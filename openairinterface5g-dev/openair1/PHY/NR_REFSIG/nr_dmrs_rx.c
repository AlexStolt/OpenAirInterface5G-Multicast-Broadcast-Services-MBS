/*
 * Licensed to the OpenAirInterface (OAI) Software Alliance under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The OpenAirInterface Software Alliance licenses this file to You under
 * the OAI Public License, Version 1.0  (the "License"); you may not use this file
 * except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.openairinterface.org/?page_id=698
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *-------------------------------------------------------------------------------
 * For more information about the OpenAirInterface (OAI) Software Alliance:
 *      contact@openairinterface.org
 */

/*! \file nr_dmrs_rx.c
 * \brief Top-level routines for generating DMRS from 38-211
 * \author
 * \date 2018
 * \version 0.1
 * \company Eurecom
 * \email:
 * \note
 * \warning
 */

//#define NR_PBCH_DMRS_LENGTH_DWORD 5
//#define NR_PBCH_DMRS_LENGTH 144
//#define DEBUG_PUSCH

#include "refsig_defs_ue.h"
#include "PHY/defs_nr_UE.h"
#include "nr_refsig.h"
#include "PHY/defs_gNB.h"
#include "nfapi/open-nFAPI/nfapi/public_inc/nfapi_nr_interface.h"

// Table 6.4.1.1.3-1/2 from TS 38.211
static const int wf1[8][2] = {{1, 1}, {1, -1}, {1, 1}, {1, -1}, {1, 1}, {1, -1}, {1, 1}, {1, -1}};
static const int wt1[8][2] = {{1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, -1}, {1, -1}, {1, -1}, {1, -1}};
static const int wf2[12][2] =
    {{1, 1}, {1, -1}, {1, 1}, {1, -1}, {1, 1}, {1, -1}, {1, 1}, {1, -1}, {1, 1}, {1, -1}, {1, 1}, {1, -1}};
static const int wt2[12][2] =
    {{1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, -1}, {1, -1}, {1, -1}, {1, -1}, {1, -1}, {1, -1}};

// complex conjugate of mod table
static const c16_t nr_rx_mod_table[7] =
    {{0, 0}, {23170, -23170}, {-23170, 23170}, {23170, -23170}, {23170, 23170}, {-23170, -23170}, {-23170, 23170}};
static const c16_t nr_rx_nmod_table[7] =
    {{0, 0}, {-23170, 23170}, {23170, -23170}, {-23170, 23170}, {-23170, -23170}, {23170, 23170}, {23170, -23170}};

int nr_pusch_dmrs_rx(PHY_VARS_gNB *gNB,
                     unsigned int Ns,
                     const uint32_t *nr_gold_pusch,
                     c16_t *output,
                     unsigned short p,
                     unsigned char lp,
                     unsigned short nb_pusch_rb,
                     uint32_t re_offset,
                     uint8_t dmrs_type)
{
  int8_t w, nb_dmrs;
  unsigned char idx=0;
  int k;
  typedef int array_of_w[2];
  const array_of_w *wf = (dmrs_type == pusch_dmrs_type1) ? wf1 : wf2;
  const array_of_w *wt = (dmrs_type == pusch_dmrs_type1) ? wt1 : wt2;

  int dmrs_offset = re_offset/((dmrs_type==pusch_dmrs_type1)?2:3);

  if (dmrs_type > 2)
    LOG_E(PHY,"PUSCH DMRS config type %d not valid\n", dmrs_type+1);

  if ((p>=1000) && (p<((dmrs_type==pusch_dmrs_type1) ? 1008 : 1012))) {
      if (gNB->frame_parms.Ncp == NORMAL) {
        nb_dmrs = ((dmrs_type==pusch_dmrs_type1) ? 6:4);
        for (int i=dmrs_offset; i<dmrs_offset+(nb_pusch_rb*nb_dmrs); i++) {
          k = i-dmrs_offset;
          w = (wf[p-1000][i&1])*(wt[p-1000][lp]);
          const c16_t *mod_table = (w == 1) ? nr_rx_mod_table : nr_rx_nmod_table;

          idx = ((((nr_gold_pusch[(i<<1)>>5])>>((i<<1)&0x1f))&1)<<1) ^ (((nr_gold_pusch[((i<<1)+1)>>5])>>(((i<<1)+1)&0x1f))&1);
          output[k] = mod_table[NR_MOD_TABLE_QPSK_OFFSET + idx];
#ifdef DEBUG_PUSCH
          printf("nr_pusch_dmrs_rx dmrs config type %d port %d nb_pusch_rb %d\n", dmrs_type, p, nb_pusch_rb);
          printf("wf[%d] = %d wt[%d]= %d\n", i&1, wf[p-1000][i&1], lp, wt[p-1000][lp]);
          printf("i %d idx %d pusch gold %u b0-b1 %d-%d mod_dmrs %d %d\n",
                 i,
                 idx,
                 nr_gold_pusch[(i << 1) >> 5],
                 (((nr_gold_pusch[(i << 1) >> 5]) >> ((i << 1) & 0x1f)) & 1),
                 (((nr_gold_pusch[((i << 1) + 1) >> 5]) >> (((i << 1) + 1) & 0x1f)) & 1),
                 output[k].r,
                 output[k].i);
#endif

        }
      } else {
        LOG_E(PHY,"extended cp not supported for PUSCH DMRS yet\n");
      }
  } else {
    LOG_E(PHY,"Illegal p %d PUSCH DMRS port\n",p);
  }

  return(0);
}

int nr_pdsch_dmrs_rx(const PHY_VARS_NR_UE *ue,
                     unsigned int Ns,
                     const unsigned int *nr_gold_pdsch,
                     c16_t *output,
                     unsigned short p,
                     unsigned char lp,
                     unsigned short nb_pdsch_rb,
                     uint8_t config_type)
{
  int8_t w;
  unsigned char idx=0;

  typedef int array_of_w[2];
  const array_of_w *wf = (config_type == NFAPI_NR_DMRS_TYPE1) ? wf1 : wf2;
  const array_of_w *wt = (config_type == NFAPI_NR_DMRS_TYPE1) ? wt1 : wt2;

  if (config_type > 1)
    LOG_E(PHY,"Bad PDSCH DMRS config type %d\n", config_type);

  if ((p >= 1000) && (p < ((config_type == NFAPI_NR_DMRS_TYPE1) ? 1008 : 1012))) {
    if (ue->frame_parms.Ncp == NORMAL) {
      for (int i = 0; i < nb_pdsch_rb * ((config_type == NFAPI_NR_DMRS_TYPE1) ? 6 : 4); i++) {
        w = (wf[p - 1000][i & 1]) * (wt[p - 1000][lp]);
        const c16_t *mod_table = (w == 1) ? nr_rx_mod_table : nr_rx_nmod_table;

        idx = ((((nr_gold_pdsch[(i << 1) >> 5]) >> ((i << 1) & 0x1f)) & 1) << 1) ^ (((nr_gold_pdsch[((i << 1) + 1) >> 5]) >> (((i << 1) + 1) & 0x1f)) & 1);
        output[i] = mod_table[NR_MOD_TABLE_QPSK_OFFSET + idx];
#ifdef DEBUG_PDSCH
        printf("nr_pdsch_dmrs_rx dmrs config type %d port %d nb_pdsch_rb %d\n", config_type, p, nb_pdsch_rb);
        printf("wf[%d] = %d wt[%d]= %d\n", i & 1, wf[p - 1000][i & 1], lp, wt[p - 1000][lp]);
        printf("i %d idx %d pdsch gold %u b0-b1 %d-%d mod_dmrs %d %d\n",
               i,
               idx,
               nr_gold_pdsch[(i << 1) >> 5],
               (((nr_gold_pdsch[(i << 1) >> 5]) >> ((i << 1) & 0x1f)) & 1),
               (((nr_gold_pdsch[((i << 1) + 1) >> 5]) >> (((i << 1) + 1) & 0x1f)) & 1),
               output[i].r,
               output[i].i);
#endif
      }
    } else {
      LOG_E(PHY, "extended cp not supported for PDSCH DMRS yet\n");
    }
  } else {
    LOG_E(PHY, "Illegal p %d PDSCH DMRS port\n", p);
  }

  return(0);
}

int nr_pdcch_dmrs_rx(const PHY_VARS_NR_UE *ue,
                     unsigned int Ns,
                     const unsigned int *nr_gold_pdcch,
                     c16_t *output,
                     unsigned short p,
                     unsigned short nb_rb_coreset)
{
  uint8_t idx=0;
  //uint8_t pdcch_rb_offset =0;
  //nr_gold_pdcch += ((int)floor(ue->frame_parms.ssb_start_subcarrier/12)+pdcch_rb_offset)*3/32;

  if (p==2000) {
    for (int i=0; i<((nb_rb_coreset*6)>>1); i++) {
      idx = ((((nr_gold_pdcch[(i<<1)>>5])>>((i<<1)&0x1f))&1)<<1) ^ (((nr_gold_pdcch[((i<<1)+1)>>5])>>(((i<<1)+1)&0x1f))&1);
      output[i] = nr_rx_mod_table[NR_MOD_TABLE_QPSK_OFFSET + idx];
#ifdef DEBUG_PDCCH
      if (i<8)
        printf("i %d idx %d pdcch gold %u b0-b1 %d-%d mod_dmrs %d %d\n",
               i,
               idx,
               nr_gold_pdcch[(i << 1) >> 5],
               (((nr_gold_pdcch[(i << 1) >> 5]) >> ((i << 1) & 0x1f)) & 1),
               (((nr_gold_pdcch[((i << 1) + 1) >> 5]) >> (((i << 1) + 1) & 0x1f)) & 1),
               output[i].r,
               output[i].i);
#endif
    }
  }

  return(0);
}

void nr_pbch_dmrs_rx(int symbol, const unsigned int *nr_gold_pbch, c16_t *output, bool sidelink)
{
  int m,m0,m1;
  uint8_t idx=0;
  if (sidelink) {
    AssertFatal(symbol == 0 || (symbol >= 5 && symbol <= 12), "illegal symbol %d\n", symbol);
    m0 = (symbol) ? (symbol - 4) * 33 : 0;
    m1 = (symbol) ? (symbol - 3) * 33 : 33;

  } else {
    AssertFatal(symbol >= 0 && symbol < 3, "illegal symbol %d\n", symbol);
    if (symbol == 0) {
      m0 = 0;
      m1 = 60;
    } else if (symbol == 1) {
      m0 = 60;
      m1 = 84;
    } else {
      m0 = 84;
      m1 = 144;
    }
  }
  //    printf("Generating pilots symbol %d, m0 %d, m1 %d\n",symbol,m0,m1);
  /// QPSK modulation
  for (m=m0; m<m1; m++) {
    idx = ((((nr_gold_pbch[(m<<1)>>5])>>((m<<1)&0x1f))&1)<<1) ^ (((nr_gold_pbch[((m<<1)+1)>>5])>>(((m<<1)+1)&0x1f))&1);
    output[m - m0] = nr_rx_mod_table[NR_MOD_TABLE_QPSK_OFFSET + idx];

#ifdef DEBUG_PBCH
    if (m<16)
      {printf("nr_gold_pbch[(m<<1)>>5] %x\n",nr_gold_pbch[(m<<1)>>5]);
      printf("m %d  output %d %d\n", m, output[m].r, output[m].i);
      }
#endif
  }
}

/*!
  \brief This function generate gold ptrs sequence for each OFDM symbol
  \param *in gold sequence for ptrs per OFDM symbol
  \param length is number of RE in a OFDM symbol
  \param *output pointer to all ptrs RE in a OFDM symbol
*/
void nr_gen_ref_conj_symbols(const uint32_t *in, uint32_t length, c16_t *output, uint16_t offset, int mod_order)
{
  uint8_t idx, b_idx;
  for (int i=0; i<length/mod_order; i++)
    {
      idx = 0;
      for (int j=0; j<mod_order; j++)
        {
          b_idx = (i*mod_order+j)&0x1f;
          if (i && (!b_idx))
            in++;
          idx ^= (((*in)>>b_idx)&1)<<(mod_order-j-1);
        }
        output[i] = nr_rx_mod_table[offset + idx];
    }
}

int nr_pusch_lowpaprtype1_dmrs_rx(PHY_VARS_gNB *gNB,
                                  unsigned int Ns,
                                  c16_t *dmrs_seq,
                                  c16_t *output,
                                  unsigned short p,
                                  unsigned char lp,
                                  unsigned short nb_pusch_rb,
                                  uint32_t re_offset,
                                  uint8_t dmrs_type)
{
  int8_t w, nb_dmrs;
  int k;

  int dmrs_offset = re_offset/((dmrs_type==pusch_dmrs_type1)?2:3);

  if (dmrs_type != pusch_dmrs_type1)
    LOG_E(PHY,"PUSCH DMRS config type %d not valid\n", dmrs_type);

  if ((p>=1000) && (p<1008)) {
      if (gNB->frame_parms.Ncp == NORMAL) {
        nb_dmrs = NR_NB_SC_PER_RB/2; // for DMRS TYPE 1 - 6 DMRS REs present per RB
        for (int i=dmrs_offset; i<dmrs_offset+(nb_pusch_rb*nb_dmrs); i++) {
          k = i-dmrs_offset;
          w = (wf1[p - 1000][i & 1]) * (wt1[p - 1000][lp]);

          output[k].r = w * dmrs_seq[i].r;
          output[k].i = -w * dmrs_seq[i].i; // conjugate

#ifdef DEBUG_PUSCH
          printf("NR_DMRS_RX: nr_pusch_dmrs_rx dmrs config type %d port %d nb_pusch_rb %d nb_dmrs %d\n",
                 dmrs_type,
                 p,
                 nb_pusch_rb,
                 nb_dmrs);
          printf("NR_DMRS_RX: wf[%d] = %d wt[%d]= %d\n", i & 1, wf1[p - 1000][i & 1], lp, wt1[p - 1000][lp]);
          printf("NR_DMRS_RX: i %d dmrs_offset %d k %d pusch dmrsseq.r %d, dmrsseq.i %d  pilots.r %d pilots.i %d\n",
                 i,
                 dmrs_offset,
                 k, 
                 dmrs_seq[i].r,
                 dmrs_seq[i].i,
                 output[k].r,
                 output[k].i);
#endif
        }
      } else {
        LOG_E(PHY,"extended cp not supported for PUSCH DMRS yet\n");
      }
  } else {
    LOG_E(PHY,"Illegal p %d PUSCH DMRS port\n",p);
  }

  return(0);
}

