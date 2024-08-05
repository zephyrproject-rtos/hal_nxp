#if CONFIG_WLS_CSI_PROC
/** @file wls_param_defines.h
 *
 * @brief This file contains global header file for configuring fft processing of CSI.
 *
 * Copyright 2023-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/************************************************************************
 * DFW Global header file for configuring fft processing of CSI.
 ************************************************************************/

#ifndef WLS_PARAM_DEFINES_H
#define WLS_PARAM_DEFINES_H

#define _BIN 0
#define _TXT 1
#define _TTL 2

#define INPUT_FILE _TXT
// #define SMAC_BFINFO

#ifdef SMAC_BFINFO
#define CSI_SIGNATURE      0x0
#define HEADER_LEN         0x15
#define CSI_BUFFER_SIZE_DW (1024 * 2 + 64)
#define CSI_NUM_BUFFER     32
#else
#define CSI_SIGNATURE      0xabcd0000
#define HEADER_LEN         28
#define CSI_BUFFER_SIZE_DW (512 + 64) // 1536 // 512 //
#define CSI_NUM_BUFFER     32         // 16 //
#endif

#define ENABLE_SUBSPACE_FTIMING
// #define ENABLE_AOA
// #define FFT_PARALLEL
// #define FFT_INPLACE
// #define TDDE_FIRSTPATH
#define STA_20_ONLY

#define MAX_RX 1
#define MAX_TX 4

#if defined(FFT_PARALLEL)
#define NUM_PARALLEL 4
#else
#define NUM_PARALLEL 1
#endif

#if defined(ENABLE_SUBSPACE_FTIMING) && defined(STA_20_ONLY)
#define NUM_PROC_BUF (11 + NUM_PARALLEL)
#elif defined(ENABLE_SUBSPACE_FTIMING)
#define NUM_PROC_BUF (2 + NUM_PARALLEL)
#else
#define NUM_PROC_BUF (NUM_PARALLEL)
#endif

#define DUMP_MULTP_PEAKS 3

#define _SC4B0_1760_20MHz 0
#define _SC4B0_0026_20MHz 1
#define _SC4B0_F69C_20MHz 2
#define _SC4B0_F798_20MHz 3
#define _SC4B0_0354_20MHz 4
#define _SC4B0_12C7_20MHz 5
#define _SC4B0_127D_20MHz 6
#define _SC4B0_0929_20MHz 7
#define _SC4B0_0F0B_20MHz 8

#define _USE_DEFAULT_CAL 0xFF

#define RX_A 0
#define RX_B 1
#define RX_C 2
#define RX_D 3

#define BAND_2P4GHZ 0
#define BAND_5GHZ   1

#define REF_ANTENNA RX_D

#define ANTENNA_SPACING_MM 27
#define DEFAULT_CHANNEL    36
#define DEFAULT_FREQ_BAND  BAND_5GHZ // needs to match DEFAULT_CHANNEL
#define DEFAULT_TSF        0
#define DEFAULT_FTM_INIT   0
#define DEFAULT_FTM_FORMAT 0xD // vht80
#define ENABLE_DELAY_PEAKS 1

#define DEFAULT_CAL_LOW_A 0x3de  // 0x3d1
#define DEFAULT_CAL_LOW_B 0x23d  // 0x222
#define DEFAULT_CAL_LOW_C 0x37f  // 0x399

#define DEFAULT_CAL_HIGH_A 0x386 // 0x37f
#define DEFAULT_CAL_HIGH_B 0x1ff // 0x1e6
#define DEFAULT_CAL_HIGH_C 0x362 // 0x37c

#define SCREEN_OUT
#ifdef SCREEN_OUT
// #define SMAC_LOG printf("\n");printf
#define HAL_LOG(...) printf(__VA_ARGS__); // printf("\n")
#else
#define HAL_LOG(...)
#endif

#define TOA_MIN_DEFAULT  0
#define SUBSPACE_DEFAULT 1
#define AOA_DEFAULT      0

#ifndef ARM
// #define FLOATING_POINT
#endif

// #define DEBUG_OUT_FD

#define MAX_TSF_DIFF_POS 10
#define MAX_TSF_DIFF_NEG -120

#define CAL_DATA _USE_DEFAULT_CAL

#define IFFT_OSF_SHIFT 2
// #define IFFT_OSF (1<<IFFT_OSF_SHIFT)
#define SPATIAL_RES          64 // number of angular bins
#define NUM_MAX_PEAKS        32 // max number of angle/delay peaks to keep
#define DELAY_DELTA_SHIFT    4
#define FFT_ADV_FRAC         16
#define TD_FRAC_OF_FFT       4     // as fraction of 3.2 microseconds
#define TD_FRAC_OF_FFT_HE    2     // to account for 2x/4x CP lengths
#define PEAK_THRESH_SHIFT    2     // consider peaks up to 6 dB below peak
#define PEAK_THRESH_MIN_ABS  0xA00 // (0.1976)^2=0.0391 0xC00 // 3/64=0.0469 0x1400 // 5/64=0.0781 in p16
#define SUBBAND_DET_THRESH   4     // 18 dB
#define REMOVE_IIR           2
#define COMPUTE_80P80_AS_160       // or true 160 in SC4+Citril
#define TOA_FPATH_BIPT       12

#ifdef STA_20_ONLY
#define MAX_IFFT_SIZE_SHIFT 2
#else // up to 80 MHz
#define MAX_IFFT_SIZE_SHIFT 5
#endif
#define MIN_IFFT_SIZE_SHIFT 1
#define MAX_IFFT_SIZE_CSI   (64 << MAX_IFFT_SIZE_SHIFT)
#define MIN_IFFT_SIZE_CSI   (64 << MIN_IFFT_SIZE_SHIFT)

#define MPY_BIPT     12
#define MY_SQRT_BIPT 8

#define IIR_FORMAT_NP 12
#define IIR_FORMAT_NB 16

// #define CAL_FORMAT_NP 12
#define CAL_FORMAT_NP 10
#define CAL_FORMAT_NB 16

#define VAC_LIGHTSPEED_MM_MICROSEC   300000
#define CABLE_LIGHTSPEED_MM_MICROSEC 200000

#define PI                 3.141592653589795f
#define ONE_OVER_PIE_16P15 0x28BE

#define SC5_VHT80_PILOTS 8
#define SC5_VHT40_PILOTS 6
#define SC5_VHT20_PILOTS 4
#define SC5_HE80_PILOTS  8
#define SC5_HE40_PILOTS  8
#define SC5_HE20_PILOTS  4
#define SC5_HT20_PILOTS  27

#endif

#endif /* CONFIG_WLS_CSI_PROC */
