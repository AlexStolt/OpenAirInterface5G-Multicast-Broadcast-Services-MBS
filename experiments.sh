#!/bin/bash

ROOT=$(pwd)
CN=openairinterface5g-dev/ci-scripts/yaml_files/5g_rfsimulator
GNB=openairinterface5g-dev/cmake_targets/ran_build/build/nr-softmodem
UE=openairinterface5g-dev/cmake_targets/ran_build/build/nr-uesoftmodem

CONF_NO_HARQ=conf/gnb-nr.conf
CONF_HARQ=conf/gnb-nr-harq.conf


clear
cd $ROOT

TIME=20           # in Seconds 


if [ "$1" = "help" ]; then

    echo "1. Deploy CN: ./experiments.sh cn"
    echo "-------------------------------------------------------------"
    echo "2. Deploy gNB wihtout HARQ: ./experiments.sh nr"
    echo "2. Deploy gNB with HARQ: ./experiments.sh nr harq"
    echo "-------------------------------------------------------------"
    echo "3. Deploy the MBMS Baremetal UE (Tunnel): ./experiments.sh ue1"
    echo "4. Deploy N additional UE containers: ./experiments.sh ue2 <N>"
    echo "-------------------------------------------------------------"
    echo "5. Listen for Unicast UDP: ./experiments.sh ll"
    echo "5. Join MBMS and Listen for UDP: ./experiments.sh ll mbms"
    echo "-------------------------------------------------------------"
    echo "6. Send UDP from DN: ./experiments.sh dl <M>"
    echo 
    echo "[NOTE] For duplicate numbers in the list above you can only execute one of the"
    echo "commands from the duplicate pair, according to the experiment you want to perform."


elif [ "$1" = "cn" ]; then
    cd $CN
    docker container prune
    sudo service docker restart
    docker compose up -d mysql oai-amf oai-smf oai-upf oai-ext-dn


elif [ "$1" = "nr" ]; then
    rm conf/.tmp_harq_status.conf
    rm conf/.tmp_mbms_status.conf

    if [[ -z "$2" ]]; then
        CONF=$CONF_NO_HARQ
        echo "HARQ is not activated..."
        echo 0 > conf/.tmp_harq_status.conf


    elif [ "$2" = "harq" ]; then 
        CONF=$CONF_HARQ
        echo "HARQ is activated ($CONF)..."
        echo 1 > conf/.tmp_harq_status.conf
    
    else
        echo "Invalid argument..."
        exit
    fi

    sleep 1

    rm conf/.mbms.conf
    rm conf/.harq.conf

    
    # sudo gdb -ex run -q --args $GNB -O $CONF -E --sa --gNBs.[0].min_rxtxtime 6 --rfsim
    sudo $GNB -O $CONF -E --sa --gNBs.[0].min_rxtxtime 6 --rfsim


elif [ "$1" = "ue1" ]; then 
    sudo $UE --band 78 -E --sa --rfsim -r 106 --numerology 1 --ssb 516 -C 3319680000 --uicc0.imsi 208990100001100 --rfsimulator.options chanmod -O conf/nrue.uicc.conf --telnetsrv --channelmod.modellist modellist_rfsimu_1 --channelmod.modellist_rfsimu_1.[0].ploss_dB 31.6



elif [ "$1" == "ue2" ]; then

    if [[ -z "$2" ]]; then
        echo "Enter the number from 1 to 7 as the second parameter..."
        exit
    fi

    cd openairinterface5g-dev/ci-scripts/yaml_files/5g_rfsimulator
    
    # Stop all UE containers
    for UE_ID in $(seq 1 8); do
        docker compose down oai-nr-ue-$UE_ID        
    done
    
    # Clear Logs
    sudo sh -c 'truncate -s 0 /var/lib/docker/containers/*/*-json.log'
        
    # Start all UE containers
    for UE_ID in $(seq 1 $2); do
        docker compose up -d oai-nr-ue-$UE_ID
        
        while true; do
            UE_IP=$(docker exec rfsim5g-oai-nr-ue-$UE_ID sh -c "ifconfig oaitun_ue1 | grep -oE 'inet [0-9]+\.[0-9]+\.[0-9]+\.[0-9]+' | sed 's/inet //'")
            if [ -n "$UE_IP" ]; then
                break
            else
                echo "Waiting for UE rfsim5g-oai-nr-ue-$UE_ID to get its IP"
                sleep 1
            fi
        done
    done


elif [ "$1" = "ll" ]; then
    IP=$(ifconfig oaitun_ue1 | grep 'inet ' | awk '{print $2}')
    
    # Move previous results to trash instead of deleting them permanently
    trash=$(date +%Y-%m-%d_%H-%M-%S)
    sudo mkdir "results/trash/$trash"
    sudo cp -r results/iperf results/trash/$trash
    sudo rm -rf results/iperf/*   

    for UE in $(docker ps --format "{{.Names}}" | grep rfsim5g-oai-nr-ue); do
        while true; do
            UE_IP=$(docker exec $UE sh -c "ifconfig oaitun_ue1 | grep -oE 'inet [0-9]+\.[0-9]+\.[0-9]+\.[0-9]+' | sed 's/inet //'")
            if [ -n "$UE_IP" ]; then
                if [[ -z "$2" ]]; then
                    docker exec -d $UE sh -c "iperf -su -B $UE_IP -i 1 > /tmp/unicast_ue_$UE.txt 2>&1"
                    echo "UE $UE listening for Unicast UDP traffic on $UE_IP..."
                    break
              
                elif [ "$2" = "mbms" ]; then
                    docker exec -it $UE ifconfig oaitun_ue1 $IP netmask 255.255.255.0
                    docker exec -d $UE sh -c "iperf -su -B $IP -i 1 > /tmp/multicast_ue_$UE.txt 2>&1"
                    echo "UE $UE listening for Multicast UDP traffic on $IP..."
                    break
              
                else
                    echo "Invalid argument..."
                    exit
                fi
            else
                echo "UE $UE is not yet connected..."
                sleep 1
            fi
        done
    done

    if [[ -z "$2" ]]; then
        echo 0 > conf/.tmp_mbms_status.conf
    elif [ "$2" = "mbms" ]; then
        echo 1 > conf/.tmp_mbms_status.conf
    fi
    
    sudo bash -c "iperf -su -B $IP -i 1 2>&1 | tee results/iperf/iperf_0.txt"

elif [ "$1" = "dl" ]; then 
    if [[ -z "$2" ]]; then
        echo "Invalid Argument..."
    fi

    THROUGHPUT="$2"M
    # Unicast
    if [[ "$(cat conf/.tmp_mbms_status.conf)" = 0 ]]; then
        for UE in $(docker ps --format "{{.Names}}" | grep rfsim5g-oai-nr-ue); do
            while true; do
                UE_IP=$(docker exec $UE sh -c "ifconfig oaitun_ue1 | grep -oE 'inet [0-9]+\.[0-9]+\.[0-9]+\.[0-9]+' | sed 's/inet //'")
                if [ -n "$UE_IP" ]; then
                    docker exec -d rfsim5g-oai-ext-dn sh -c "iperf -u -c $UE_IP -i 1 -b $THROUGHPUT -t $TIME"
                    echo "Sending UDP to UE $UE IP $UE_IP..."
                    break
                else
                    echo "UE $UE is not yet connected..."
                    sleep 1
                fi
            done
        done
    
    # Multicast
    elif [ "$(cat conf/.tmp_mbms_status.conf)" = 1 ]; then
        echo "Multicast and Broadcast is activated..."
        echo 1 > conf/.mbms.conf
                
    else
        echo "No UE is listening for this UDP traffic..."
        exit
    fi

    # Check if HARQ is enabled 
    if [[ "$(cat conf/.tmp_harq_status.conf)" = 0 ]]; then
        CONF=$CONF_NO_HARQ
        echo "HARQ is not activated..."
   
    elif [[ "$(cat conf/.tmp_harq_status.conf)" = 1 ]]; then
        CONF=$CONF_HARQ
        echo "HARQ is activated ($CONF)..."

    else
        echo "Invalid conf/.tmp_harq_status.conf file..."
    fi 
      
    echo $(grep "disable_harq" $CONF | awk -F '=' '{print $2}' | awk -F ';' '{print $1}' | sed 's/^[[:space:]]*//') > conf/.harq.conf

    IP=$(ifconfig oaitun_ue1 | grep 'inet ' | awk '{print $2}')
    docker exec -it rfsim5g-oai-ext-dn iperf -u -c $IP -i 1 -b $THROUGHPUT -t $TIME 

elif [ "$1" = "clean" ]; then
    sudo rm -rf results/trash/*
    rm conf/.tmp_harq_status.conf
    rm conf/.tmp_mbms_status.conf
    rm conf/.mbms.conf
    rm conf/.harq.conf
fi


cd $ROOT
