

# OpenAirInterface5G MBS
This project is based on the official OpenAirInterface5G tag: ba2d7aad18788c2572cb0b96488dc96ef4089c83

## Build
1. [RAN](https://gitlab.eurecom.fr/oai/openairinterface5g/-/blob/develop/openair2/E2AP/README.md)
   * ```sudo source openairinterface5g-dev/cmake_targets/build_oai -I --phy_simulators -w SIMU --nrUE --gNB```

## Deploy
1. Deploy the [Core Network](https://gitlab.eurecom.fr/oai/openairinterface5g/-/tree/develop/ci-scripts/yaml_files/5g_rfsimulator?ref_type=heads) with: ```source experiments.sh cn```
2. Deploy RAN
   * Without HARQ (No-ACK HARQ-ACK): ```source experiments.sh nr``` 
   * With HARQ (ACK-NACK or NACK-Only HARQ-ACK): ```source experiments.sh nr harq``` 
3. Deploy the Baremetal UE: ```source experiments.sh ue1```
4. Deploy another N UE devices: ```source experiments.sh ue2 <N>```
5. Make the UE devices to listen for downlink MBS traffic
   * The traffic is PTP: ```source experiments.sh ll```
   * The traffic is PTM: ```source experiments.sh ll mbms```
6. Send <M> Mbps MBS traffic to the UE devices: ```source experiments.sh dl <M>```

