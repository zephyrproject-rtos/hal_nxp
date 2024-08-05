#if CONFIG_WLS_CSI_PROC
/** @file wls_structure_defs.h
 *
 * @brief This file contains header file for CSI structure definitions
 *
 * Copyright 2023-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/************************************************************************
 * DFW Header file for CSI structure definitions
 ************************************************************************/

#ifndef WLS_STRUCTURE_DEFS_H
#define WLS_STRUCTURE_DEFS_H

#include "wls_param_defines.h"

#ifndef DEF_TYPES
#define DEF_TYPES
#define SINT8  signed char
#define SINT16 signed short
#define SINT32 signed int
#define SINT64 signed long long
#define UINT8  unsigned char
#define UINT16 unsigned short
#define UINT32 unsigned int
#define UINT64 unsigned long long
#endif

typedef struct csiHeaderInfoStruct
{
    unsigned char csi;
    unsigned char LTF;
    unsigned short dataLength;
    unsigned short FCF;
    unsigned short dataParameter;
    unsigned int HTCF;
    unsigned int TSF;
    unsigned char ADDR1[6];
    unsigned char ADDR2[6];
    unsigned char SBFnIndex;
    // unsigned short PKTinfo;
    unsigned char rxDevBw;
    unsigned char nRx;
    unsigned char nTx;
    unsigned char Ng;
    unsigned char sigBw;
    unsigned char psb;
    unsigned char packetType;

    unsigned char cfoCourseEst;
    // unsigned int LSig;
    unsigned char LSigRate;
    unsigned char LSigRateMbps;
    unsigned short LSigLength;
    unsigned char LSigParity;
    unsigned char LSigTail;

    unsigned char cfoFineEst;

    unsigned char HtSigMcs;
    unsigned char HtSigCbw20_40;
    unsigned short HtSigLength;

    unsigned char HtSigSmoothing;
    unsigned char HtSigNotSounding;
    unsigned char HtSigAggregation;
    unsigned char HtSigStbc;
    unsigned char HtSigFecCoding;
    unsigned char HtSigShortGi;
    unsigned char HtSigNoExtSpatStreams;
    unsigned char HtSigCrc;
    unsigned char HtSigTailBits;

    unsigned char VhtSigBw;
    unsigned char VhtSigStbc;
    unsigned char VhtSigGroupId;
    unsigned char VhtSigSuNoSts;
    unsigned short VhtSigPartialAid;
    unsigned char VhtSigTxOpPsNotAllwd;

    unsigned char VhtSigShortGi;
    unsigned char VhtSigShortGiDisAmb;
    unsigned char VhtSigSuCoding;
    unsigned char VhtSigLdpcExtraSymb;
    unsigned char VhtSigMcs;
    unsigned char VhtSigBeamformed;
    unsigned char VhtSigCrc;
    unsigned char VhtSigTail;

    unsigned char rxNoiseFloor, rxNfA, rxNfB, rxNfC, rxNfD;
    unsigned char rxRssi, rxRssiA, rxRssiB, rxRssiC, rxRssiD;

    unsigned char LltfDvgaCtrMax;
    unsigned char LltfBbCtrMax;
    unsigned char LltfIfCtrMax;
    unsigned char LltfLnaCtrMax;
    unsigned char LltfSlnaMax;

    unsigned char HtDvgaCtrMax;
    unsigned char HtBbCtrMax;
    unsigned char HtIfCtrMax;
    unsigned char HtLnaCtrMax;
    unsigned char HtSlnaMax;

    unsigned char isLtf;
    unsigned char NgDsfShift;
    unsigned char scOffset;

    int totalGainLltf;
    int totalGainCsi;

} CsiHeaderInfo;

#define SOC_W8X64
#define SOC_W8864
#define SOC_W8964

typedef struct hal_rxinfo
{
    // DWORD-0
#ifdef SOC_W8X64
    UINT32 reserved0 : 16;
    UINT32 sign : 16; // 0xBEEF: tagged by MAC HW
    // DWORD-1
#ifdef SOC_W8964
    UINT32 cfo : 17;
    UINT32 reservedcfo : 7;
    UINT32 nf : 8;
#else
    UINT8 nf_c;
    UINT8 nf_b;
    UINT8 nf_a;
    UINT8 nf;
#endif
    // DWORD-2
#ifdef SOC_W8964
    UINT16 dta : 12;
    UINT16 reserveddta : 4;
    UINT8 t2;
#else
    UINT8 rssi_c;
    UINT8 rssi_b;
    UINT8 rssi_a;
#endif
    UINT8 rssi; // RSSI
    // DWORD-3
    UINT16 Rxlength;
    UINT16 rx_svc;
    // DWORD-4
    UINT32 rx_cq : 24;
#ifdef SOC_W8964
    UINT32 reservedrxcq : 8;
#else
    UINT32 rssi_d : 8;
#endif
    // DWORD-5
    UINT32 ht_sig1 : 24;
#ifdef SOC_W8964
    UINT32 reservedhtsig : 8;
#else
    UINT32 nf_d : 8;
#endif
    // DWORD-6
    UINT32 ht_sig2 : 18;
    UINT32 Rx_LSig_Rsvd : 1;
    UINT32 Rx_LSig_parity : 1;
    UINT32 Rx_LSig_bad_parity : 1;
    UINT32 Rx_HTSig_bad_crc : 3;
    UINT32 rate : 8;
#ifdef SOC_W8864
    // DWORD-7
    UINT32 Rx_Gain_code_a : 22;
    UINT32 BBU_Reserved_9_0 : 10;
    // DWORD-8
    UINT32 Rx_Gain_code_b : 22;
    UINT32 BBU_Reserved_19_10 : 10;
    // DWORD-9
    UINT32 Rx_Gain_code_c : 22;
    UINT32 BBU_Reserved_29_20 : 10;
    // DWORD-10
    UINT32 Rx_Gain_code_d : 22;
#ifdef SOC_W8964
    UINT32 BBU_Reserved_35_30 : 6;
    UINT32 mu_cq_valid : 4;
#else
    UINT32 BBU_Reserved_39_30 : 10;
#endif
    // DWORD-11
    UINT32 pm_rssi_dbm_b : 12;
    UINT32 pm_rssi_dbm_a : 12;
#ifdef SOC_W8964
    UINT32 mu_cq0 : 8;
#else
    UINT32 BBU_Reserved_47_40 : 8;
#endif
    // DWORD-12
    UINT32 pm_rssi_dbm_d : 12;
    UINT32 pm_rssi_dbm_c : 12;
#ifdef SOC_W8964
    UINT32 mu_cq1 : 8;
#else
    UINT32 BBU_Reserved_55_48 : 8;
#endif
    // DWORD-13
    UINT32 pm_nf_dbm_b : 12;
    UINT32 pm_nf_dbm_a : 12;
#ifdef SOC_W8964
    UINT32 mu_cq2 : 8;
#else
    UINT32 BBU_Reserved_63_56 : 8;
#endif
    // DWORD-14
    UINT32 pm_nf_dbm_d : 12;
    UINT32 pm_nf_dbm_c : 12;
#ifdef SOC_W8964
    UINT32 mu_cq3 : 8;
#else
    UINT32 BBU_Reserved_71_64 : 8;
#endif
    // DWORD-15
    UINT32 rx_pkt_secondary : 1;
    UINT32 rx_dyn_bw : 1;
    UINT32 rx_ind_bw : 2;
    UINT32 rx_dup_likely_bw : 2;
    UINT32 rx_pkt_info : 3;
#ifdef SOC_W8964
    UINT32 rx_vhtsigb : 23;
    // DWORD-16
    UINT16 lltf_phroll;
    UINT16 htlf_phroll;
#else
    UINT32 ReservedDword15 : 23;
    // DWORD-16
    UINT32 ReservedDword16;
#endif
    // DWORD-17
    UINT32 T2;
    // DWORD-18
    UINT32 T3;
    // DWORD-19
    UINT32 Rx_timestamp;
    // DWORD-20
    UINT32 TSF;
    // DWORD-21
    UINT32 param : 24;
    UINT32 Rx_AMPDU_Num : 8;
    // DWORD-22
    UINT16 qc;  //
    UINT16 sq2; // temp tookout foo fb_mcs_param;
    // DWORD - 23
    UINT32 ht_ctrl; //
#else
    // DWORD-7
    UINT32 Rx_Gain_code_a : 21;
    UINT32 BBU_Reserved_10_0 : 11;
    // DWORD-8
    UINT32 Rx_Gain_code_b : 21;
    UINT32 BBU_Reserved_22_11 : 11;
    // DWORD-9
    UINT32 Rx_Gain_code_c : 21;
    UINT32 BBU_Reserved_32_22 : 11;
    // DWORD-10
    UINT32 Rx_Gain_code_d : 21;
    UINT32 BBU_Reserved_43_33 : 11;
    // DWORD-11
    UINT32 Rx_timestamp;
    // DWORD-12
    UINT32 TSF;
    // DWORD-13
    UINT32 param : 24;
    UINT32 Rx_AMPDU_Num : 8;
    // DWORD-14
    UINT16 qc;
    UINT16 sq2; // temp tookout foo fb_mcs_param;
    // DWORD-15
    UINT32 ht_ctrl;
#endif

#else
    UINT32 ht_sig2 : 10;
    UINT32 params_hi : 6;
    UINT32 sign : 16; /* Signature = 0xBEEF */

    // 1
    UINT8 param;
    UINT8 sq1;
    UINT8 rate;
    UINT8 rssi;
    // 2
    UINT8 ts_low; /* timestamp [7:0] */
    UINT8 nf;     /* Noise floor */
    UINT16 ts_hi; /* timestamp [23:8] */
    // 3
    UINT16 qc; /* QoS control */
    UINT16 sq2;

    // 4
    UINT32 ht_sig1;

    // 5
    UINT8 rssi_c;
    UINT8 rssi_b;
    UINT8 rssi_a;
    UINT8 svc_low;

    // 6
    UINT8 nf_c;
    UINT8 nf_b;
    UINT8 nf_a;
    UINT8 svc_hi;

    // 7
    UINT32 ht_ctrl;
#endif
} hal_rxinfo_t;

typedef struct hal_csirxinfo
{
#ifdef SMAC_BFINFO
    // DWORD-0
    UINT32 header_length : 13;
    UINT32 rsvd0 : 3;
    UINT32 signature : 16; // 0x0000
    // DWORD-1
    UINT32 pktinfo : 20;
    UINT32 rsvd1 : 12;
    // DWORD-2
    UINT32 lsig : 24;
    UINT32 cfo_coarse : 8;
    // DWORD-3
    UINT32 htsig1 : 24;
    UINT32 cfo_fine : 8;
    // DWORD-4
    UINT32 htsig2 : 24;
    UINT32 rsvd2 : 8;
    // DWORD-5
    UINT32 rx_rssi : 8;
    UINT32 rx_noise_floor : 8;
    UINT32 rsvd3 : 16;
    // DWORD-6
    UINT32 rx_rssi_a : 8;
    UINT32 rx_rssi_b : 8;
    UINT32 rx_rssi_c : 8;
    UINT32 rx_rssi_d : 8;
    // DWORD-7
    UINT32 rx_rssi_e : 8;
    UINT32 rx_rssi_f : 8;
    UINT32 rx_rssi_g : 8;
    UINT32 rx_rssi_h : 8;
    // DWORD-8
    UINT32 rx_nf_a : 8;
    UINT32 rx_nf_b : 8;
    UINT32 rx_nf_c : 8;
    UINT32 rx_nf_d : 8;
    // DWORD-9
    UINT32 rx_nf_e : 8;
    UINT32 rx_nf_f : 8;
    UINT32 rx_nf_g : 8;
    UINT32 rx_nf_h : 8;
    // DWORD-10
    UINT32 gain_code_11ft : 24;
    UINT32 rsvd4 : 8;
    // DWORD-11
    UINT32 gain_code_ht : 24;
    UINT32 rsvd5 : 8;
    // DWORD-12
    UINT32 timestamp_0;
    // DWORD-13
    UINT32 timestamp_1;
    // DWORD-14
    UINT32 timestamp_2;
    // DWORD-15
    UINT32 timestamp_3;
    // DWORD-16
    UINT32 timestamp_4;
    // DWORD-17
    UINT32 timestamp_5;
    // DWORD-18
    UINT32 timestamp_6;
    // DWORD-19
    UINT32 timestamp_7;
    // DWORD-20
    UINT32 timestamp_8;
#else
    // DWORD-0
    UINT32 data_length : 13; // Includes BF_INFO, LTF Data, and CSI Data. Length in dwords
    UINT32 ltf : 1;
    UINT32 csi : 1;
    UINT32 tbd : 1;
    UINT32 signature : 16; // 0xABCD: tagged by MAC HW
    // DWORD-1
    UINT32 dataparam : 16;
    UINT32 fcf : 16;
    // DWORD-2
    UINT32 htcf;
    // DWORD-3
    UINT32 tsf;
    // DWORD-4
    UINT32 addr1_lo;
    // DWORD-5
    UINT32 addr1_hi : 16;
    UINT32 addr2_lo : 16;
    // DWORD-6
    UINT32 addr2_hi;
    // DWORD-7
    UINT32 sbfnindex : 7;
    UINT32 rsvd0 : 17;
    UINT32 rx_ppdu_seq : 8;
    // DWORD-8 -- start of BBUD portion, same as SC5/SCBT
    // DWORD-1
    UINT32 pktinfo : 20;
    UINT32 rsvd1 : 12;
    // DWORD-2
    UINT32 lsig : 24;
    UINT32 cfo_coarse : 8;
    // DWORD-3
    UINT32 htsig1 : 24;
    UINT32 cfo_fine : 8;
    // DWORD-4
    UINT32 htsig2 : 24;
    UINT32 rsvd2 : 8;
    // DWORD-5
    UINT32 rx_rssi : 8;
    UINT32 rx_noise_floor : 8;
    UINT32 rsvd3 : 16;
    // DWORD-6
    UINT32 rx_rssi_a : 8;
    UINT32 rx_rssi_b : 8;
    UINT32 rx_rssi_c : 8;
    UINT32 rx_rssi_d : 8;
    // DWORD-7
    UINT32 rx_rssi_e : 8;
    UINT32 rx_rssi_f : 8;
    UINT32 rx_rssi_g : 8;
    UINT32 rx_rssi_h : 8;
    // DWORD-8
    UINT32 rx_nf_a : 8;
    UINT32 rx_nf_b : 8;
    UINT32 rx_nf_c : 8;
    UINT32 rx_nf_d : 8;
    // DWORD-9
    UINT32 rx_nf_e : 8;
    UINT32 rx_nf_f : 8;
    UINT32 rx_nf_g : 8;
    UINT32 rx_nf_h : 8;
    // DWORD-10
    UINT32 gain_code_11ft : 24;
    UINT32 rsvd4 : 8;
    // DWORD-11
    UINT32 gain_code_ht : 24;
    UINT32 rsvd5 : 8;
    // DWORD-12
    UINT32 timestamp_0;
    // DWORD-13
    UINT32 timestamp_1;
    // DWORD-14
    UINT32 timestamp_2;
    // DWORD-15
    UINT32 timestamp_3;
    // DWORD-16
    UINT32 timestamp_4;
    // DWORD-17
    UINT32 timestamp_5;
    // DWORD-18
    UINT32 timestamp_6;
    // DWORD-19
    UINT32 timestamp_7;
    // DWORD-20
    UINT32 timestamp_8;
#endif
} hal_csirxinfo_t;

typedef struct hal_pktinfo
{
    UINT32 packetType : 3;
    UINT32 psb : 3;
    UINT32 sigBw : 2;
    UINT32 Ng : 1;
    UINT32 nTx : 3;
    UINT32 nRx : 3;
    UINT32 rxDevBw : 2;
    UINT32 MU : 1;
    UINT32 HELTF : 2;
    UINT32 NgDsfShift : 2; // added to pass parameters
    UINT32 fftSize : 4;
    UINT32 rsvd1 : 4;
    UINT32 scOffset : 12;
    UINT32 dcPhase : 2;
    UINT32 rsvd2 : 18;
} hal_pktinfo_t;

#ifndef DFW_CSI_PROC
typedef struct hal_wls_processing_input_params
{
    UINT32 enableCsi : 1;              // turn on CSI processing
    UINT32 enableAoA : 1;              // turn on AoA (req. enableCsi==1)
    UINT32 nTx : 3;                    // limit # tx streams to process
    UINT32 nRx : 3;                    // limit # rx to process
    UINT32 selCal : 8;                 // choose cal values
    UINT32 dumpMul : 2;                // dump extra peaks in AoA
    UINT32 enableAntCycling : 1;       // enable antenna cycling
    UINT32 dumpRawAngle : 1;           // Dump Raw Angle
    UINT32 useToaMin : 1;              // 1: use min combining, 0: power combining;
    UINT32 useSubspace : 1;            // 1: use subspace algo; 0: no;
    UINT32 useFindAngleDelayPeaks : 1; // use this algorithm for AoA
    UINT32 rsvd1 : 9;
} hal_wls_processing_input_params_t;

typedef struct hal_wls_packet_params
{
    UINT32 chNum : 8;              // ch_index 1-4, 36:4:140, 149:4:165
    UINT32 isFtmInit : 1;          // indicate if this is FTM exchange initiator or responder
    UINT32 ftmSignalBW : 3;        // Channel bandwidth 0: 20 MHz, 1: 40 MHz, 2: 80 MHz, 3: 160 Mhz, 4-7 reserved
    UINT32 ftmPacketType : 3;      // Format of FTM exchange 0: legacy, 1:HT, 3:VHT, 4:HE
    UINT32 freqBand : 1;           // Declare freq. band, 0: 2.4 GHz, 1: 5 GHz
    UINT32 peerMacAddress_lo : 16; // first 16 bit of FTM peer MAC address
    UINT32 peerMacAddress_hi;      // rest of FTM peer MAC address
    UINT32 info_tsf;               // TSF counter from tx/rx-info
    UINT32 cal_data_low_A : 10;
    UINT32 cal_data_low_B : 10;
    UINT32 cal_data_low_C : 10;
    UINT32 rsvd2 : 2;
    UINT32 cal_data_high_A : 10;
    UINT32 cal_data_high_B : 10;
    UINT32 cal_data_high_C : 10;
    UINT32 rsvd3 : 2;
    UINT32 cable_len_A : 8;
    UINT32 cable_len_B : 8;
    UINT32 cable_len_C : 8;
    UINT32 antenna_spacing : 8;
} hal_wls_packet_params_t;
#else
#include "dsp_cmd.h"
#endif

typedef struct hal_cal_struc
{
    short calData[4];
    short centerFreq;
} hal_cal_struc_t;

typedef struct reg_buf_config
{
    // DWORD-0
    UINT16 buf_size : 13;
    UINT16 rsvd1 : 3;
    UINT16 buf_num : 12;
    UINT16 rsvd0 : 4;
} reg_buf_config_t;

typedef struct reg_buf_ptr
{
    // DWORD-0
    UINT16 wr_ptr : 13;
    UINT16 rsvd1 : 3;
    UINT16 rd_ptr : 13;
    UINT16 rsvd0 : 3;
} reg_buf_ptr_t;

#endif

#endif /* CONFIG_WLS_CSI_PROC */
