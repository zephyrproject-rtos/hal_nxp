/*
** ###################################################################
**     Processors:          MIMX9101CVXXC
**                          MIMX9101DVXXC
**                          MIMX9111CVXXJ
**                          MIMX9111DVXXJ
**                          MIMX9121CVVXC
**                          MIMX9121DVVXC
**                          MIMX9131CVVXJ
**                          MIMX9131DVVXJ
**
**     Version:             rev. 1.0, 2024-11-15
**     Build:               b250814
**
**     Abstract:
**         CMSIS Peripheral Access Layer for DWC_DDRPHYA_INITENG
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2024-11-15)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_DWC_DDRPHYA_INITENG.h
 * @version 1.0
 * @date 2024-11-15
 * @brief CMSIS Peripheral Access Layer for DWC_DDRPHYA_INITENG
 *
 * CMSIS Peripheral Access Layer for DWC_DDRPHYA_INITENG
 */

#if !defined(PERI_DWC_DDRPHYA_INITENG_H_)
#define PERI_DWC_DDRPHYA_INITENG_H_              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX9101CVXXC) || defined(CPU_MIMX9101DVXXC))
#include "MIMX9101_COMMON.h"
#elif (defined(CPU_MIMX9111CVXXJ) || defined(CPU_MIMX9111DVXXJ))
#include "MIMX9111_COMMON.h"
#elif (defined(CPU_MIMX9121CVVXC) || defined(CPU_MIMX9121DVVXC))
#include "MIMX9121_COMMON.h"
#elif (defined(CPU_MIMX9131CVVXJ) || defined(CPU_MIMX9131DVVXJ))
#include "MIMX9131_COMMON.h"
#else
  #error "No valid CPU defined!"
#endif

/* ----------------------------------------------------------------------------
   -- Device Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Peripheral_access_layer Device Peripheral Access Layer
 * @{
 */


/*
** Start of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic push
  #else
    #pragma push
    #pragma anon_unions
  #endif
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=extended
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- DWC_DDRPHYA_INITENG Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DWC_DDRPHYA_INITENG_Peripheral_Access_Layer DWC_DDRPHYA_INITENG Peripheral Access Layer
 * @{
 */

/** DWC_DDRPHYA_INITENG - Register Layout Typedef */
typedef struct {
  __IO uint16_t PRESEQUENCEREG0B0S0;               /**< PHY Initialization Engine (PIE) Pre-Instruction 0_0, offset: 0x0 */
  __IO uint16_t PRESEQUENCEREG0B0S1;               /**< PHY Initialization Engine (PIE) Pre-Instruction 0_1, offset: 0x2 */
  __IO uint16_t PRESEQUENCEREG0B0S2;               /**< PHY Initialization Engine (PIE) Pre-Instruction 0_2, offset: 0x4 */
  __IO uint16_t PRESEQUENCEREG0B1S0;               /**< PHY Initialization Engine (PIE) Pre-Instruction 1_0, offset: 0x6 */
  __IO uint16_t PRESEQUENCEREG0B1S1;               /**< PHY Initialization Engine (PIE) Pre-Instruction 1_1, offset: 0x8 */
  __IO uint16_t PRESEQUENCEREG0B1S2;               /**< PHY Initialization Engine (PIE) Pre-Instruction 1_2, offset: 0xA */
  __IO uint16_t POSTSEQUENCEREG0B0S0;              /**< PHY Initialization Engine (PIE) Post-Instruction 0_0, offset: 0xC */
  __IO uint16_t POSTSEQUENCEREG0B0S1;              /**< PHY Initialization Engine (PIE) Post-Instruction 0_1, offset: 0xE */
  __IO uint16_t POSTSEQUENCEREG0B0S2;              /**< PHY Initialization Engine (PIE) Post-Instruction 0_2, offset: 0x10 */
  __IO uint16_t POSTSEQUENCEREG0B1S0;              /**< PHY Initialization Engine (PIE) Post-Instruction 1_0, offset: 0x12 */
  __IO uint16_t POSTSEQUENCEREG0B1S1;              /**< PHY Initialization Engine (PIE) Post-Instruction 1_1, offset: 0x14 */
  __IO uint16_t POSTSEQUENCEREG0B1S2;              /**< PHY Initialization Engine (PIE) Post-Instruction 1_2, offset: 0x16 */
  __IO uint16_t SEQ0BDISABLEFLAG0;                 /**< PHY Initialization Engine (PIE) Disable Instruction Group 0 Disable Bits, offset: 0x18 */
  __IO uint16_t SEQ0BDISABLEFLAG1;                 /**< PHY Initialization Engine (PIE) Disable Instruction Group 1 Disable Bits, offset: 0x1A */
  __IO uint16_t SEQ0BDISABLEFLAG2;                 /**< PHY Initialization Engine (PIE) Disable Instruction Group 2 Disable Bits, offset: 0x1C */
  __IO uint16_t SEQ0BDISABLEFLAG3;                 /**< PHY Initialization Engine (PIE) Disable Instruction Group 3 Disable Bits, offset: 0x1E */
  __IO uint16_t SEQ0BDISABLEFLAG4;                 /**< PHY Initialization Engine (PIE) Disable Instruction Group 4 Disable Bits, offset: 0x20 */
  __IO uint16_t SEQ0BDISABLEFLAG5;                 /**< PHY Initialization Engine (PIE) Disable Instruction Group 5 Disable Bits, offset: 0x22 */
  __IO uint16_t SEQ0BDISABLEFLAG6;                 /**< PHY Initialization Engine (PIE) Disable Instruction Group 6 Disable Bits, offset: 0x24 */
  __IO uint16_t SEQ0BDISABLEFLAG7;                 /**< PHY Initialization Engine (PIE) Disable Instruction Group 7 Disable Bits, offset: 0x26 */
       uint8_t RESERVED_0[6];
  __IO uint16_t STARTVECTOR0B0;                    /**< PHY Initialization Engine (PIE) start vector 0, offset: 0x2E */
  __IO uint16_t STARTVECTOR0B1;                    /**< PHY Initialization Engine (PIE) start vector 1, offset: 0x30 */
  __IO uint16_t STARTVECTOR0B2;                    /**< PHY Initialization Engine (PIE) start vector 2, offset: 0x32 */
  __IO uint16_t STARTVECTOR0B3;                    /**< PHY Initialization Engine (PIE) start vector 3, offset: 0x34 */
  __IO uint16_t STARTVECTOR0B4;                    /**< PHY Initialization Engine (PIE) start vector 4, offset: 0x36 */
  __IO uint16_t STARTVECTOR0B5;                    /**< PHY Initialization Engine (PIE) start vector 5, offset: 0x38 */
  __IO uint16_t STARTVECTOR0B6;                    /**< PHY Initialization Engine (PIE) start vector 6, offset: 0x3A */
  __IO uint16_t STARTVECTOR0B7;                    /**< PHY Initialization Engine (PIE) start vector 7, offset: 0x3C */
  __IO uint16_t STARTVECTOR0B8;                    /**< PHY Initialization Engine (PIE) start vector 8, offset: 0x3E */
  __IO uint16_t STARTVECTOR0B9;                    /**< PHY Initialization Engine (PIE) start vector 9, offset: 0x40 */
  __IO uint16_t STARTVECTOR0B10;                   /**< PHY Initialization Engine (PIE) start vector 10, offset: 0x42 */
  __IO uint16_t STARTVECTOR0B11;                   /**< PHY Initialization Engine (PIE) start vector 11, offset: 0x44 */
  __IO uint16_t STARTVECTOR0B12;                   /**< PHY Initialization Engine (PIE) start vector 12, offset: 0x46 */
  __IO uint16_t STARTVECTOR0B13;                   /**< PHY Initialization Engine (PIE) start vector 13, offset: 0x48 */
  __IO uint16_t STARTVECTOR0B14;                   /**< PHY Initialization Engine (PIE) start vector 14, offset: 0x4A */
  __IO uint16_t STARTVECTOR0B15;                   /**< PHY Initialization Engine (PIE) start vector 15, offset: 0x4C */
  __IO uint16_t SEQ0BWAITCONDSEL;                  /**< PHY Initialization Engine (PIE) wait condition selection, offset: 0x4E */
  __IO uint16_t PHYINLP3;                          /**< Indicator for PIE Lower Power 3 (LP3) Status, offset: 0x50 */
  __IO uint16_t SEQUENCEREG0B0S0;                  /**< PHY Initialization Engine (PIE) Instruction 0_0, offset: 0x52 */
  __IO uint16_t SEQUENCEREG0B0S1;                  /**< PHY Initialization Engine (PIE) Instruction 0_1, offset: 0x54 */
  __IO uint16_t SEQUENCEREG0B0S2;                  /**< PHY Initialization Engine (PIE) Instruction 0_2, offset: 0x56 */
  __IO uint16_t SEQUENCEREG0B1S0;                  /**< PHY Initialization Engine (PIE) Instruction 1_0, offset: 0x58 */
  __IO uint16_t SEQUENCEREG0B1S1;                  /**< PHY Initialization Engine (PIE) Instruction 1_1, offset: 0x5A */
  __IO uint16_t SEQUENCEREG0B1S2;                  /**< PHY Initialization Engine (PIE) Instruction 1_2, offset: 0x5C */
  __IO uint16_t SEQUENCEREG0B2S0;                  /**< PHY Initialization Engine (PIE) Instruction 2_0, offset: 0x5E */
  __IO uint16_t SEQUENCEREG0B2S1;                  /**< PHY Initialization Engine (PIE) Instruction 2_1, offset: 0x60 */
  __IO uint16_t SEQUENCEREG0B2S2;                  /**< PHY Initialization Engine (PIE) Instruction 2_2, offset: 0x62 */
  __IO uint16_t SEQUENCEREG0B3S0;                  /**< PHY Initialization Engine (PIE) Instruction 3_0, offset: 0x64 */
  __IO uint16_t SEQUENCEREG0B3S1;                  /**< PHY Initialization Engine (PIE) Instruction 3_1, offset: 0x66 */
  __IO uint16_t SEQUENCEREG0B3S2;                  /**< PHY Initialization Engine (PIE) Instruction 3_2, offset: 0x68 */
  __IO uint16_t SEQUENCEREG0B4S0;                  /**< PHY Initialization Engine (PIE) Instruction 4_0, offset: 0x6A */
  __IO uint16_t SEQUENCEREG0B4S1;                  /**< PHY Initialization Engine (PIE) Instruction 4_1, offset: 0x6C */
  __IO uint16_t SEQUENCEREG0B4S2;                  /**< PHY Initialization Engine (PIE) Instruction 4_2, offset: 0x6E */
  __IO uint16_t SEQUENCEREG0B5S0;                  /**< PHY Initialization Engine (PIE) Instruction 5_0, offset: 0x70 */
  __IO uint16_t SEQUENCEREG0B5S1;                  /**< PHY Initialization Engine (PIE) Instruction 5_1, offset: 0x72 */
  __IO uint16_t SEQUENCEREG0B5S2;                  /**< PHY Initialization Engine (PIE) Instruction 5_2, offset: 0x74 */
  __IO uint16_t SEQUENCEREG0B6S0;                  /**< PHY Initialization Engine (PIE) Instruction 6_0, offset: 0x76 */
  __IO uint16_t SEQUENCEREG0B6S1;                  /**< PHY Initialization Engine (PIE) Instruction 6_1, offset: 0x78 */
  __IO uint16_t SEQUENCEREG0B6S2;                  /**< PHY Initialization Engine (PIE) Instruction 6_2, offset: 0x7A */
  __IO uint16_t SEQUENCEREG0B7S0;                  /**< PHY Initialization Engine (PIE) Instruction 7_0, offset: 0x7C */
  __IO uint16_t SEQUENCEREG0B7S1;                  /**< PHY Initialization Engine (PIE) Instruction 7_1, offset: 0x7E */
  __IO uint16_t SEQUENCEREG0B7S2;                  /**< PHY Initialization Engine (PIE) Instruction 7_2, offset: 0x80 */
  __IO uint16_t SEQUENCEREG0B8S0;                  /**< PHY Initialization Engine (PIE) Instruction 8_0, offset: 0x82 */
  __IO uint16_t SEQUENCEREG0B8S1;                  /**< PHY Initialization Engine (PIE) Instruction 8_1, offset: 0x84 */
  __IO uint16_t SEQUENCEREG0B8S2;                  /**< PHY Initialization Engine (PIE) Instruction 8_2, offset: 0x86 */
  __IO uint16_t SEQUENCEREG0B9S0;                  /**< PHY Initialization Engine (PIE) Instruction 9_0, offset: 0x88 */
  __IO uint16_t SEQUENCEREG0B9S1;                  /**< PHY Initialization Engine (PIE) Instruction 9_1, offset: 0x8A */
  __IO uint16_t SEQUENCEREG0B9S2;                  /**< PHY Initialization Engine (PIE) Instruction 9_2, offset: 0x8C */
  __IO uint16_t SEQUENCEREG0B10S0;                 /**< PHY Initialization Engine (PIE) Instruction 10_0, offset: 0x8E */
  __IO uint16_t SEQUENCEREG0B10S1;                 /**< PHY Initialization Engine (PIE) Instruction 10_1, offset: 0x90 */
  __IO uint16_t SEQUENCEREG0B10S2;                 /**< PHY Initialization Engine (PIE) Instruction 10_2, offset: 0x92 */
  __IO uint16_t SEQUENCEREG0B11S0;                 /**< PHY Initialization Engine (PIE) Instruction 11_0, offset: 0x94 */
  __IO uint16_t SEQUENCEREG0B11S1;                 /**< PHY Initialization Engine (PIE) Instruction 11_1, offset: 0x96 */
  __IO uint16_t SEQUENCEREG0B11S2;                 /**< PHY Initialization Engine (PIE) Instruction 11_2, offset: 0x98 */
  __IO uint16_t SEQUENCEREG0B12S0;                 /**< PHY Initialization Engine (PIE) Instruction 12_0, offset: 0x9A */
  __IO uint16_t SEQUENCEREG0B12S1;                 /**< PHY Initialization Engine (PIE) Instruction 12_1, offset: 0x9C */
  __IO uint16_t SEQUENCEREG0B12S2;                 /**< PHY Initialization Engine (PIE) Instruction 12_2, offset: 0x9E */
  __IO uint16_t SEQUENCEREG0B13S0;                 /**< PHY Initialization Engine (PIE) Instruction 13_0, offset: 0xA0 */
  __IO uint16_t SEQUENCEREG0B13S1;                 /**< PHY Initialization Engine (PIE) Instruction 13_1, offset: 0xA2 */
  __IO uint16_t SEQUENCEREG0B13S2;                 /**< PHY Initialization Engine (PIE) Instruction 13_2, offset: 0xA4 */
  __IO uint16_t SEQUENCEREG0B14S0;                 /**< PHY Initialization Engine (PIE) Instruction 14_0, offset: 0xA6 */
  __IO uint16_t SEQUENCEREG0B14S1;                 /**< PHY Initialization Engine (PIE) Instruction 14_1, offset: 0xA8 */
  __IO uint16_t SEQUENCEREG0B14S2;                 /**< PHY Initialization Engine (PIE) Instruction 14_2, offset: 0xAA */
  __IO uint16_t SEQUENCEREG0B15S0;                 /**< PHY Initialization Engine (PIE) Instruction 15_0, offset: 0xAC */
  __IO uint16_t SEQUENCEREG0B15S1;                 /**< PHY Initialization Engine (PIE) Instruction 15_1, offset: 0xAE */
  __IO uint16_t SEQUENCEREG0B15S2;                 /**< PHY Initialization Engine (PIE) Instruction 15_2, offset: 0xB0 */
  __IO uint16_t SEQUENCEREG0B16S0;                 /**< PHY Initialization Engine (PIE) Instruction 16_0, offset: 0xB2 */
  __IO uint16_t SEQUENCEREG0B16S1;                 /**< PHY Initialization Engine (PIE) Instruction 16_1, offset: 0xB4 */
  __IO uint16_t SEQUENCEREG0B16S2;                 /**< PHY Initialization Engine (PIE) Instruction 16_2, offset: 0xB6 */
  __IO uint16_t SEQUENCEREG0B17S0;                 /**< PHY Initialization Engine (PIE) Instruction 17_0, offset: 0xB8 */
  __IO uint16_t SEQUENCEREG0B17S1;                 /**< PHY Initialization Engine (PIE) Instruction 17_1, offset: 0xBA */
  __IO uint16_t SEQUENCEREG0B17S2;                 /**< PHY Initialization Engine (PIE) Instruction 17_2, offset: 0xBC */
  __IO uint16_t SEQUENCEREG0B18S0;                 /**< PHY Initialization Engine (PIE) Instruction 18_0, offset: 0xBE */
  __IO uint16_t SEQUENCEREG0B18S1;                 /**< PHY Initialization Engine (PIE) Instruction 18_1, offset: 0xC0 */
  __IO uint16_t SEQUENCEREG0B18S2;                 /**< PHY Initialization Engine (PIE) Instruction 18_2, offset: 0xC2 */
  __IO uint16_t SEQUENCEREG0B19S0;                 /**< PHY Initialization Engine (PIE) Instruction 19_0, offset: 0xC4 */
  __IO uint16_t SEQUENCEREG0B19S1;                 /**< PHY Initialization Engine (PIE) Instruction 19_1, offset: 0xC6 */
  __IO uint16_t SEQUENCEREG0B19S2;                 /**< PHY Initialization Engine (PIE) Instruction 19_2, offset: 0xC8 */
  __IO uint16_t SEQUENCEREG0B20S0;                 /**< PHY Initialization Engine (PIE) Instruction 20_0, offset: 0xCA */
  __IO uint16_t SEQUENCEREG0B20S1;                 /**< PHY Initialization Engine (PIE) Instruction 20_1, offset: 0xCC */
  __IO uint16_t SEQUENCEREG0B20S2;                 /**< PHY Initialization Engine (PIE) Instruction 20_2, offset: 0xCE */
  __IO uint16_t SEQUENCEREG0B21S0;                 /**< PHY Initialization Engine (PIE) Instruction 21_0, offset: 0xD0 */
  __IO uint16_t SEQUENCEREG0B21S1;                 /**< PHY Initialization Engine (PIE) Instruction 21_1, offset: 0xD2 */
  __IO uint16_t SEQUENCEREG0B21S2;                 /**< PHY Initialization Engine (PIE) Instruction 21_2, offset: 0xD4 */
  __IO uint16_t SEQUENCEREG0B22S0;                 /**< PHY Initialization Engine (PIE) Instruction 22_0, offset: 0xD6 */
  __IO uint16_t SEQUENCEREG0B22S1;                 /**< PHY Initialization Engine (PIE) Instruction 22_1, offset: 0xD8 */
  __IO uint16_t SEQUENCEREG0B22S2;                 /**< PHY Initialization Engine (PIE) Instruction 22_2, offset: 0xDA */
  __IO uint16_t SEQUENCEREG0B23S0;                 /**< PHY Initialization Engine (PIE) Instruction 23_0, offset: 0xDC */
  __IO uint16_t SEQUENCEREG0B23S1;                 /**< PHY Initialization Engine (PIE) Instruction 23_1, offset: 0xDE */
  __IO uint16_t SEQUENCEREG0B23S2;                 /**< PHY Initialization Engine (PIE) Instruction 23_2, offset: 0xE0 */
  __IO uint16_t SEQUENCEREG0B24S0;                 /**< PHY Initialization Engine (PIE) Instruction 24_0, offset: 0xE2 */
  __IO uint16_t SEQUENCEREG0B24S1;                 /**< PHY Initialization Engine (PIE) Instruction 24_1, offset: 0xE4 */
  __IO uint16_t SEQUENCEREG0B24S2;                 /**< PHY Initialization Engine (PIE) Instruction 24_2, offset: 0xE6 */
  __IO uint16_t SEQUENCEREG0B25S0;                 /**< PHY Initialization Engine (PIE) Instruction 25_0, offset: 0xE8 */
  __IO uint16_t SEQUENCEREG0B25S1;                 /**< PHY Initialization Engine (PIE) Instruction 25_1, offset: 0xEA */
  __IO uint16_t SEQUENCEREG0B25S2;                 /**< PHY Initialization Engine (PIE) Instruction 25_2, offset: 0xEC */
  __IO uint16_t SEQUENCEREG0B26S0;                 /**< PHY Initialization Engine (PIE) Instruction 26_0, offset: 0xEE */
  __IO uint16_t SEQUENCEREG0B26S1;                 /**< PHY Initialization Engine (PIE) Instruction 26_1, offset: 0xF0 */
  __IO uint16_t SEQUENCEREG0B26S2;                 /**< PHY Initialization Engine (PIE) Instruction 26_2, offset: 0xF2 */
  __IO uint16_t SEQUENCEREG0B27S0;                 /**< PHY Initialization Engine (PIE) Instruction 27_0, offset: 0xF4 */
  __IO uint16_t SEQUENCEREG0B27S1;                 /**< PHY Initialization Engine (PIE) Instruction 27_1, offset: 0xF6 */
  __IO uint16_t SEQUENCEREG0B27S2;                 /**< PHY Initialization Engine (PIE) Instruction 27_2, offset: 0xF8 */
  __IO uint16_t SEQUENCEREG0B28S0;                 /**< PHY Initialization Engine (PIE) Instruction 28_0, offset: 0xFA */
  __IO uint16_t SEQUENCEREG0B28S1;                 /**< PHY Initialization Engine (PIE) Instruction 28_1, offset: 0xFC */
  __IO uint16_t SEQUENCEREG0B28S2;                 /**< PHY Initialization Engine (PIE) Instruction 28_2, offset: 0xFE */
  __IO uint16_t SEQUENCEREG0B29S0;                 /**< PHY Initialization Engine (PIE) Instruction 29_0, offset: 0x100 */
  __IO uint16_t SEQUENCEREG0B29S1;                 /**< PHY Initialization Engine (PIE) Instruction 29_1, offset: 0x102 */
  __IO uint16_t SEQUENCEREG0B29S2;                 /**< PHY Initialization Engine (PIE) Instruction 29_2, offset: 0x104 */
  __IO uint16_t SEQUENCEREG0B30S0;                 /**< PHY Initialization Engine (PIE) Instruction 30_0, offset: 0x106 */
  __IO uint16_t SEQUENCEREG0B30S1;                 /**< PHY Initialization Engine (PIE) Instruction 30_1, offset: 0x108 */
  __IO uint16_t SEQUENCEREG0B30S2;                 /**< PHY Initialization Engine (PIE) Instruction 30_2, offset: 0x10A */
  __IO uint16_t SEQUENCEREG0B31S0;                 /**< PHY Initialization Engine (PIE) Instruction 31_0, offset: 0x10C */
  __IO uint16_t SEQUENCEREG0B31S1;                 /**< PHY Initialization Engine (PIE) Instruction 31_1, offset: 0x10E */
  __IO uint16_t SEQUENCEREG0B31S2;                 /**< PHY Initialization Engine (PIE) Instruction 31_2, offset: 0x110 */
  __IO uint16_t SEQUENCEREG0B32S0;                 /**< PHY Initialization Engine (PIE) Instruction 32_0, offset: 0x112 */
  __IO uint16_t SEQUENCEREG0B32S1;                 /**< PHY Initialization Engine (PIE) Instruction 32_1, offset: 0x114 */
  __IO uint16_t SEQUENCEREG0B32S2;                 /**< PHY Initialization Engine (PIE) Instruction 32_2, offset: 0x116 */
  __IO uint16_t SEQUENCEREG0B33S0;                 /**< PHY Initialization Engine (PIE) Instruction 33_0, offset: 0x118 */
  __IO uint16_t SEQUENCEREG0B33S1;                 /**< PHY Initialization Engine (PIE) Instruction 33_1, offset: 0x11A */
  __IO uint16_t SEQUENCEREG0B33S2;                 /**< PHY Initialization Engine (PIE) Instruction 33_2, offset: 0x11C */
  __IO uint16_t SEQUENCEREG0B34S0;                 /**< PHY Initialization Engine (PIE) Instruction 34_0, offset: 0x11E */
  __IO uint16_t SEQUENCEREG0B34S1;                 /**< PHY Initialization Engine (PIE) Instruction 34_1, offset: 0x120 */
  __IO uint16_t SEQUENCEREG0B34S2;                 /**< PHY Initialization Engine (PIE) Instruction 34_2, offset: 0x122 */
  __IO uint16_t SEQUENCEREG0B35S0;                 /**< PHY Initialization Engine (PIE) Instruction 35_0, offset: 0x124 */
  __IO uint16_t SEQUENCEREG0B35S1;                 /**< PHY Initialization Engine (PIE) Instruction 35_1, offset: 0x126 */
  __IO uint16_t SEQUENCEREG0B35S2;                 /**< PHY Initialization Engine (PIE) Instruction 35_2, offset: 0x128 */
  __IO uint16_t SEQUENCEREG0B36S0;                 /**< PHY Initialization Engine (PIE) Instruction 36_0, offset: 0x12A */
  __IO uint16_t SEQUENCEREG0B36S1;                 /**< PHY Initialization Engine (PIE) Instruction 36_1, offset: 0x12C */
  __IO uint16_t SEQUENCEREG0B36S2;                 /**< PHY Initialization Engine (PIE) Instruction 36_2, offset: 0x12E */
  __IO uint16_t SEQUENCEREG0B37S0;                 /**< PHY Initialization Engine (PIE) Instruction 37_0, offset: 0x130 */
  __IO uint16_t SEQUENCEREG0B37S1;                 /**< PHY Initialization Engine (PIE) Instruction 37_1, offset: 0x132 */
  __IO uint16_t SEQUENCEREG0B37S2;                 /**< PHY Initialization Engine (PIE) Instruction 37_2, offset: 0x134 */
  __IO uint16_t SEQUENCEREG0B38S0;                 /**< PHY Initialization Engine (PIE) Instruction 38_0, offset: 0x136 */
  __IO uint16_t SEQUENCEREG0B38S1;                 /**< PHY Initialization Engine (PIE) Instruction 38_1, offset: 0x138 */
  __IO uint16_t SEQUENCEREG0B38S2;                 /**< PHY Initialization Engine (PIE) Instruction 38_2, offset: 0x13A */
  __IO uint16_t SEQUENCEREG0B39S0;                 /**< PHY Initialization Engine (PIE) Instruction 39_0, offset: 0x13C */
  __IO uint16_t SEQUENCEREG0B39S1;                 /**< PHY Initialization Engine (PIE) Instruction 39_1, offset: 0x13E */
  __IO uint16_t SEQUENCEREG0B39S2;                 /**< PHY Initialization Engine (PIE) Instruction 39_2, offset: 0x140 */
  __IO uint16_t SEQUENCEREG0B40S0;                 /**< PHY Initialization Engine (PIE) Instruction 40_0, offset: 0x142 */
  __IO uint16_t SEQUENCEREG0B40S1;                 /**< PHY Initialization Engine (PIE) Instruction 40_1, offset: 0x144 */
  __IO uint16_t SEQUENCEREG0B40S2;                 /**< PHY Initialization Engine (PIE) Instruction 40_2, offset: 0x146 */
  __IO uint16_t SEQUENCEREG0B41S0;                 /**< PHY Initialization Engine (PIE) Instruction 41_0, offset: 0x148 */
  __IO uint16_t SEQUENCEREG0B41S1;                 /**< PHY Initialization Engine (PIE) Instruction 41_1, offset: 0x14A */
  __IO uint16_t SEQUENCEREG0B41S2;                 /**< PHY Initialization Engine (PIE) Instruction 41_2, offset: 0x14C */
  __IO uint16_t SEQUENCEREG0B42S0;                 /**< PHY Initialization Engine (PIE) Instruction 42_0, offset: 0x14E */
  __IO uint16_t SEQUENCEREG0B42S1;                 /**< PHY Initialization Engine (PIE) Instruction 42_1, offset: 0x150 */
  __IO uint16_t SEQUENCEREG0B42S2;                 /**< PHY Initialization Engine (PIE) Instruction 42_2, offset: 0x152 */
  __IO uint16_t SEQUENCEREG0B43S0;                 /**< PHY Initialization Engine (PIE) Instruction 43_0, offset: 0x154 */
  __IO uint16_t SEQUENCEREG0B43S1;                 /**< PHY Initialization Engine (PIE) Instruction 43_1, offset: 0x156 */
  __IO uint16_t SEQUENCEREG0B43S2;                 /**< PHY Initialization Engine (PIE) Instruction 43_2, offset: 0x158 */
  __IO uint16_t SEQUENCEREG0B44S0;                 /**< PHY Initialization Engine (PIE) Instruction 44_0, offset: 0x15A */
  __IO uint16_t SEQUENCEREG0B44S1;                 /**< PHY Initialization Engine (PIE) Instruction 44_1, offset: 0x15C */
  __IO uint16_t SEQUENCEREG0B44S2;                 /**< PHY Initialization Engine (PIE) Instruction 44_2, offset: 0x15E */
  __IO uint16_t SEQUENCEREG0B45S0;                 /**< PHY Initialization Engine (PIE) Instruction 45_0, offset: 0x160 */
  __IO uint16_t SEQUENCEREG0B45S1;                 /**< PHY Initialization Engine (PIE) Instruction 45_1, offset: 0x162 */
  __IO uint16_t SEQUENCEREG0B45S2;                 /**< PHY Initialization Engine (PIE) Instruction 45_2, offset: 0x164 */
  __IO uint16_t SEQUENCEREG0B46S0;                 /**< PHY Initialization Engine (PIE) Instruction 46_0, offset: 0x166 */
  __IO uint16_t SEQUENCEREG0B46S1;                 /**< PHY Initialization Engine (PIE) Instruction 46_1, offset: 0x168 */
  __IO uint16_t SEQUENCEREG0B46S2;                 /**< PHY Initialization Engine (PIE) Instruction 46_2, offset: 0x16A */
  __IO uint16_t SEQUENCEREG0B47S0;                 /**< PHY Initialization Engine (PIE) Instruction 47_0, offset: 0x16C */
  __IO uint16_t SEQUENCEREG0B47S1;                 /**< PHY Initialization Engine (PIE) Instruction 47_1, offset: 0x16E */
  __IO uint16_t SEQUENCEREG0B47S2;                 /**< PHY Initialization Engine (PIE) Instruction 47_2, offset: 0x170 */
  __IO uint16_t SEQUENCEREG0B48S0;                 /**< PHY Initialization Engine (PIE) Instruction 48_0, offset: 0x172 */
  __IO uint16_t SEQUENCEREG0B48S1;                 /**< PHY Initialization Engine (PIE) Instruction 48_1, offset: 0x174 */
  __IO uint16_t SEQUENCEREG0B48S2;                 /**< PHY Initialization Engine (PIE) Instruction 48_2, offset: 0x176 */
  __IO uint16_t SEQUENCEREG0B49S0;                 /**< PHY Initialization Engine (PIE) Instruction 49_0, offset: 0x178 */
  __IO uint16_t SEQUENCEREG0B49S1;                 /**< PHY Initialization Engine (PIE) Instruction 49_1, offset: 0x17A */
  __IO uint16_t SEQUENCEREG0B49S2;                 /**< PHY Initialization Engine (PIE) Instruction 49_2, offset: 0x17C */
  __IO uint16_t SEQUENCEREG0B50S0;                 /**< PHY Initialization Engine (PIE) Instruction 50_0, offset: 0x17E */
  __IO uint16_t SEQUENCEREG0B50S1;                 /**< PHY Initialization Engine (PIE) Instruction 50_1, offset: 0x180 */
  __IO uint16_t SEQUENCEREG0B50S2;                 /**< PHY Initialization Engine (PIE) Instruction 50_2, offset: 0x182 */
  __IO uint16_t SEQUENCEREG0B51S0;                 /**< PHY Initialization Engine (PIE) Instruction 51_0, offset: 0x184 */
  __IO uint16_t SEQUENCEREG0B51S1;                 /**< PHY Initialization Engine (PIE) Instruction 51_1, offset: 0x186 */
  __IO uint16_t SEQUENCEREG0B51S2;                 /**< PHY Initialization Engine (PIE) Instruction 51_2, offset: 0x188 */
  __IO uint16_t SEQUENCEREG0B52S0;                 /**< PHY Initialization Engine (PIE) Instruction 52_0, offset: 0x18A */
  __IO uint16_t SEQUENCEREG0B52S1;                 /**< PHY Initialization Engine (PIE) Instruction 52_1, offset: 0x18C */
  __IO uint16_t SEQUENCEREG0B52S2;                 /**< PHY Initialization Engine (PIE) Instruction 52_2, offset: 0x18E */
  __IO uint16_t SEQUENCEREG0B53S0;                 /**< PHY Initialization Engine (PIE) Instruction 53_0, offset: 0x190 */
  __IO uint16_t SEQUENCEREG0B53S1;                 /**< PHY Initialization Engine (PIE) Instruction 53_1, offset: 0x192 */
  __IO uint16_t SEQUENCEREG0B53S2;                 /**< PHY Initialization Engine (PIE) Instruction 53_2, offset: 0x194 */
  __IO uint16_t SEQUENCEREG0B54S0;                 /**< PHY Initialization Engine (PIE) Instruction 54_0, offset: 0x196 */
  __IO uint16_t SEQUENCEREG0B54S1;                 /**< PHY Initialization Engine (PIE) Instruction 54_1, offset: 0x198 */
  __IO uint16_t SEQUENCEREG0B54S2;                 /**< PHY Initialization Engine (PIE) Instruction 54_2, offset: 0x19A */
  __IO uint16_t SEQUENCEREG0B55S0;                 /**< PHY Initialization Engine (PIE) Instruction 55_0, offset: 0x19C */
  __IO uint16_t SEQUENCEREG0B55S1;                 /**< PHY Initialization Engine (PIE) Instruction 55_1, offset: 0x19E */
  __IO uint16_t SEQUENCEREG0B55S2;                 /**< PHY Initialization Engine (PIE) Instruction 55_2, offset: 0x1A0 */
  __IO uint16_t SEQUENCEREG0B56S0;                 /**< PHY Initialization Engine (PIE) Instruction 56_0, offset: 0x1A2 */
  __IO uint16_t SEQUENCEREG0B56S1;                 /**< PHY Initialization Engine (PIE) Instruction 56_1, offset: 0x1A4 */
  __IO uint16_t SEQUENCEREG0B56S2;                 /**< PHY Initialization Engine (PIE) Instruction 56_2, offset: 0x1A6 */
  __IO uint16_t SEQUENCEREG0B57S0;                 /**< PHY Initialization Engine (PIE) Instruction 57_0, offset: 0x1A8 */
  __IO uint16_t SEQUENCEREG0B57S1;                 /**< PHY Initialization Engine (PIE) Instruction 57_1, offset: 0x1AA */
  __IO uint16_t SEQUENCEREG0B57S2;                 /**< PHY Initialization Engine (PIE) Instruction 57_2, offset: 0x1AC */
  __IO uint16_t SEQUENCEREG0B58S0;                 /**< PHY Initialization Engine (PIE) Instruction 58_0, offset: 0x1AE */
  __IO uint16_t SEQUENCEREG0B58S1;                 /**< PHY Initialization Engine (PIE) Instruction 58_1, offset: 0x1B0 */
  __IO uint16_t SEQUENCEREG0B58S2;                 /**< PHY Initialization Engine (PIE) Instruction 58_2, offset: 0x1B2 */
  __IO uint16_t SEQUENCEREG0B59S0;                 /**< PHY Initialization Engine (PIE) Instruction 59_0, offset: 0x1B4 */
  __IO uint16_t SEQUENCEREG0B59S1;                 /**< PHY Initialization Engine (PIE) Instruction 59_1, offset: 0x1B6 */
  __IO uint16_t SEQUENCEREG0B59S2;                 /**< PHY Initialization Engine (PIE) Instruction 59_2, offset: 0x1B8 */
  __IO uint16_t SEQUENCEREG0B60S0;                 /**< PHY Initialization Engine (PIE) Instruction 60_0, offset: 0x1BA */
  __IO uint16_t SEQUENCEREG0B60S1;                 /**< PHY Initialization Engine (PIE) Instruction 60_1, offset: 0x1BC */
  __IO uint16_t SEQUENCEREG0B60S2;                 /**< PHY Initialization Engine (PIE) Instruction 60_2, offset: 0x1BE */
  __IO uint16_t SEQUENCEREG0B61S0;                 /**< PHY Initialization Engine (PIE) Instruction 61_0, offset: 0x1C0 */
  __IO uint16_t SEQUENCEREG0B61S1;                 /**< PHY Initialization Engine (PIE) Instruction 61_1, offset: 0x1C2 */
  __IO uint16_t SEQUENCEREG0B61S2;                 /**< PHY Initialization Engine (PIE) Instruction 61_2, offset: 0x1C4 */
  __IO uint16_t SEQUENCEREG0B62S0;                 /**< PHY Initialization Engine (PIE) Instruction 62_0, offset: 0x1C6 */
  __IO uint16_t SEQUENCEREG0B62S1;                 /**< PHY Initialization Engine (PIE) Instruction 62_1, offset: 0x1C8 */
  __IO uint16_t SEQUENCEREG0B62S2;                 /**< PHY Initialization Engine (PIE) Instruction 62_2, offset: 0x1CA */
  __IO uint16_t SEQUENCEREG0B63S0;                 /**< PHY Initialization Engine (PIE) Instruction 63_0, offset: 0x1CC */
  __IO uint16_t SEQUENCEREG0B63S1;                 /**< PHY Initialization Engine (PIE) Instruction 63_1, offset: 0x1CE */
  __IO uint16_t SEQUENCEREG0B63S2;                 /**< PHY Initialization Engine (PIE) Instruction 63_2, offset: 0x1D0 */
  __IO uint16_t SEQUENCEREG0B64S0;                 /**< PHY Initialization Engine (PIE) Instruction 64_0, offset: 0x1D2 */
  __IO uint16_t SEQUENCEREG0B64S1;                 /**< PHY Initialization Engine (PIE) Instruction 64_1, offset: 0x1D4 */
  __IO uint16_t SEQUENCEREG0B64S2;                 /**< PHY Initialization Engine (PIE) Instruction 64_2, offset: 0x1D6 */
  __IO uint16_t SEQUENCEREG0B65S0;                 /**< PHY Initialization Engine (PIE) Instruction 65_0, offset: 0x1D8 */
  __IO uint16_t SEQUENCEREG0B65S1;                 /**< PHY Initialization Engine (PIE) Instruction 65_1, offset: 0x1DA */
  __IO uint16_t SEQUENCEREG0B65S2;                 /**< PHY Initialization Engine (PIE) Instruction 65_2, offset: 0x1DC */
  __IO uint16_t SEQUENCEREG0B66S0;                 /**< PHY Initialization Engine (PIE) Instruction 66_0, offset: 0x1DE */
  __IO uint16_t SEQUENCEREG0B66S1;                 /**< PHY Initialization Engine (PIE) Instruction 66_1, offset: 0x1E0 */
  __IO uint16_t SEQUENCEREG0B66S2;                 /**< PHY Initialization Engine (PIE) Instruction 66_2, offset: 0x1E2 */
  __IO uint16_t SEQUENCEREG0B67S0;                 /**< PHY Initialization Engine (PIE) Instruction 67_0, offset: 0x1E4 */
  __IO uint16_t SEQUENCEREG0B67S1;                 /**< PHY Initialization Engine (PIE) Instruction 67_1, offset: 0x1E6 */
  __IO uint16_t SEQUENCEREG0B67S2;                 /**< PHY Initialization Engine (PIE) Instruction 67_2, offset: 0x1E8 */
  __IO uint16_t SEQUENCEREG0B68S0;                 /**< PHY Initialization Engine (PIE) Instruction 68_0, offset: 0x1EA */
  __IO uint16_t SEQUENCEREG0B68S1;                 /**< PHY Initialization Engine (PIE) Instruction 68_1, offset: 0x1EC */
  __IO uint16_t SEQUENCEREG0B68S2;                 /**< PHY Initialization Engine (PIE) Instruction 68_2, offset: 0x1EE */
  __IO uint16_t SEQUENCEREG0B69S0;                 /**< PHY Initialization Engine (PIE) Instruction 69_0, offset: 0x1F0 */
  __IO uint16_t SEQUENCEREG0B69S1;                 /**< PHY Initialization Engine (PIE) Instruction 69_1, offset: 0x1F2 */
  __IO uint16_t SEQUENCEREG0B69S2;                 /**< PHY Initialization Engine (PIE) Instruction 69_2, offset: 0x1F4 */
  __IO uint16_t SEQUENCEREG0B70S0;                 /**< PHY Initialization Engine (PIE) Instruction 70_0, offset: 0x1F6 */
  __IO uint16_t SEQUENCEREG0B70S1;                 /**< PHY Initialization Engine (PIE) Instruction 70_1, offset: 0x1F8 */
  __IO uint16_t SEQUENCEREG0B70S2;                 /**< PHY Initialization Engine (PIE) Instruction 70_2, offset: 0x1FA */
  __IO uint16_t SEQUENCEREG0B71S0;                 /**< PHY Initialization Engine (PIE) Instruction 71_0, offset: 0x1FC */
  __IO uint16_t SEQUENCEREG0B71S1;                 /**< PHY Initialization Engine (PIE) Instruction 71_1, offset: 0x1FE */
  __IO uint16_t SEQUENCEREG0B71S2;                 /**< PHY Initialization Engine (PIE) Instruction 71_2, offset: 0x200 */
  __IO uint16_t SEQUENCEREG0B72S0;                 /**< PHY Initialization Engine (PIE) Instruction 72_0, offset: 0x202 */
  __IO uint16_t SEQUENCEREG0B72S1;                 /**< PHY Initialization Engine (PIE) Instruction 72_1, offset: 0x204 */
  __IO uint16_t SEQUENCEREG0B72S2;                 /**< PHY Initialization Engine (PIE) Instruction 72_2, offset: 0x206 */
  __IO uint16_t SEQUENCEREG0B73S0;                 /**< PHY Initialization Engine (PIE) Instruction 73_0, offset: 0x208 */
  __IO uint16_t SEQUENCEREG0B73S1;                 /**< PHY Initialization Engine (PIE) Instruction 73_1, offset: 0x20A */
  __IO uint16_t SEQUENCEREG0B73S2;                 /**< PHY Initialization Engine (PIE) Instruction 73_2, offset: 0x20C */
  __IO uint16_t SEQUENCEREG0B74S0;                 /**< PHY Initialization Engine (PIE) Instruction 74_0, offset: 0x20E */
  __IO uint16_t SEQUENCEREG0B74S1;                 /**< PHY Initialization Engine (PIE) Instruction 74_1, offset: 0x210 */
  __IO uint16_t SEQUENCEREG0B74S2;                 /**< PHY Initialization Engine (PIE) Instruction 74_2, offset: 0x212 */
  __IO uint16_t SEQUENCEREG0B75S0;                 /**< PHY Initialization Engine (PIE) Instruction 75_0, offset: 0x214 */
  __IO uint16_t SEQUENCEREG0B75S1;                 /**< PHY Initialization Engine (PIE) Instruction 75_1, offset: 0x216 */
  __IO uint16_t SEQUENCEREG0B75S2;                 /**< PHY Initialization Engine (PIE) Instruction 75_2, offset: 0x218 */
  __IO uint16_t SEQUENCEREG0B76S0;                 /**< PHY Initialization Engine (PIE) Instruction 76_0, offset: 0x21A */
  __IO uint16_t SEQUENCEREG0B76S1;                 /**< PHY Initialization Engine (PIE) Instruction 76_1, offset: 0x21C */
  __IO uint16_t SEQUENCEREG0B76S2;                 /**< PHY Initialization Engine (PIE) Instruction 76_2, offset: 0x21E */
  __IO uint16_t SEQUENCEREG0B77S0;                 /**< PHY Initialization Engine (PIE) Instruction 77_0, offset: 0x220 */
  __IO uint16_t SEQUENCEREG0B77S1;                 /**< PHY Initialization Engine (PIE) Instruction 77_1, offset: 0x222 */
  __IO uint16_t SEQUENCEREG0B77S2;                 /**< PHY Initialization Engine (PIE) Instruction 77_2, offset: 0x224 */
  __IO uint16_t SEQUENCEREG0B78S0;                 /**< PHY Initialization Engine (PIE) Instruction 78_0, offset: 0x226 */
  __IO uint16_t SEQUENCEREG0B78S1;                 /**< PHY Initialization Engine (PIE) Instruction 78_1, offset: 0x228 */
  __IO uint16_t SEQUENCEREG0B78S2;                 /**< PHY Initialization Engine (PIE) Instruction 78_2, offset: 0x22A */
  __IO uint16_t SEQUENCEREG0B79S0;                 /**< PHY Initialization Engine (PIE) Instruction 79_0, offset: 0x22C */
  __IO uint16_t SEQUENCEREG0B79S1;                 /**< PHY Initialization Engine (PIE) Instruction 79_1, offset: 0x22E */
  __IO uint16_t SEQUENCEREG0B79S2;                 /**< PHY Initialization Engine (PIE) Instruction 79_2, offset: 0x230 */
  __IO uint16_t SEQUENCEREG0B80S0;                 /**< PHY Initialization Engine (PIE) Instruction 80_0, offset: 0x232 */
  __IO uint16_t SEQUENCEREG0B80S1;                 /**< PHY Initialization Engine (PIE) Instruction 80_1, offset: 0x234 */
  __IO uint16_t SEQUENCEREG0B80S2;                 /**< PHY Initialization Engine (PIE) Instruction 80_2, offset: 0x236 */
  __IO uint16_t SEQUENCEREG0B81S0;                 /**< PHY Initialization Engine (PIE) Instruction 81_0, offset: 0x238 */
  __IO uint16_t SEQUENCEREG0B81S1;                 /**< PHY Initialization Engine (PIE) Instruction 81_1, offset: 0x23A */
  __IO uint16_t SEQUENCEREG0B81S2;                 /**< PHY Initialization Engine (PIE) Instruction 81_2, offset: 0x23C */
  __IO uint16_t SEQUENCEREG0B82S0;                 /**< PHY Initialization Engine (PIE) Instruction 82_0, offset: 0x23E */
  __IO uint16_t SEQUENCEREG0B82S1;                 /**< PHY Initialization Engine (PIE) Instruction 82_1, offset: 0x240 */
  __IO uint16_t SEQUENCEREG0B82S2;                 /**< PHY Initialization Engine (PIE) Instruction 82_2, offset: 0x242 */
  __IO uint16_t SEQUENCEREG0B83S0;                 /**< PHY Initialization Engine (PIE) Instruction 83_0, offset: 0x244 */
  __IO uint16_t SEQUENCEREG0B83S1;                 /**< PHY Initialization Engine (PIE) Instruction 83_1, offset: 0x246 */
  __IO uint16_t SEQUENCEREG0B83S2;                 /**< PHY Initialization Engine (PIE) Instruction 83_2, offset: 0x248 */
  __IO uint16_t SEQUENCEREG0B84S0;                 /**< PHY Initialization Engine (PIE) Instruction 84_0, offset: 0x24A */
  __IO uint16_t SEQUENCEREG0B84S1;                 /**< PHY Initialization Engine (PIE) Instruction 84_1, offset: 0x24C */
  __IO uint16_t SEQUENCEREG0B84S2;                 /**< PHY Initialization Engine (PIE) Instruction 84_2, offset: 0x24E */
  __IO uint16_t SEQUENCEREG0B85S0;                 /**< PHY Initialization Engine (PIE) Instruction 85_0, offset: 0x250 */
  __IO uint16_t SEQUENCEREG0B85S1;                 /**< PHY Initialization Engine (PIE) Instruction 85_1, offset: 0x252 */
  __IO uint16_t SEQUENCEREG0B85S2;                 /**< PHY Initialization Engine (PIE) Instruction 85_2, offset: 0x254 */
  __IO uint16_t SEQUENCEREG0B86S0;                 /**< PHY Initialization Engine (PIE) Instruction 86_0, offset: 0x256 */
  __IO uint16_t SEQUENCEREG0B86S1;                 /**< PHY Initialization Engine (PIE) Instruction 86_1, offset: 0x258 */
  __IO uint16_t SEQUENCEREG0B86S2;                 /**< PHY Initialization Engine (PIE) Instruction 86_2, offset: 0x25A */
  __IO uint16_t SEQUENCEREG0B87S0;                 /**< PHY Initialization Engine (PIE) Instruction 87_0, offset: 0x25C */
  __IO uint16_t SEQUENCEREG0B87S1;                 /**< PHY Initialization Engine (PIE) Instruction 87_1, offset: 0x25E */
  __IO uint16_t SEQUENCEREG0B87S2;                 /**< PHY Initialization Engine (PIE) Instruction 87_2, offset: 0x260 */
  __IO uint16_t SEQUENCEREG0B88S0;                 /**< PHY Initialization Engine (PIE) Instruction 88_0, offset: 0x262 */
  __IO uint16_t SEQUENCEREG0B88S1;                 /**< PHY Initialization Engine (PIE) Instruction 88_1, offset: 0x264 */
  __IO uint16_t SEQUENCEREG0B88S2;                 /**< PHY Initialization Engine (PIE) Instruction 88_2, offset: 0x266 */
  __IO uint16_t SEQUENCEREG0B89S0;                 /**< PHY Initialization Engine (PIE) Instruction 89_0, offset: 0x268 */
  __IO uint16_t SEQUENCEREG0B89S1;                 /**< PHY Initialization Engine (PIE) Instruction 89_1, offset: 0x26A */
  __IO uint16_t SEQUENCEREG0B89S2;                 /**< PHY Initialization Engine (PIE) Instruction 89_2, offset: 0x26C */
  __IO uint16_t SEQUENCEREG0B90S0;                 /**< PHY Initialization Engine (PIE) Instruction 90_0, offset: 0x26E */
  __IO uint16_t SEQUENCEREG0B90S1;                 /**< PHY Initialization Engine (PIE) Instruction 90_1, offset: 0x270 */
  __IO uint16_t SEQUENCEREG0B90S2;                 /**< PHY Initialization Engine (PIE) Instruction 90_2, offset: 0x272 */
  __IO uint16_t SEQUENCEREG0B91S0;                 /**< PHY Initialization Engine (PIE) Instruction 91_0, offset: 0x274 */
  __IO uint16_t SEQUENCEREG0B91S1;                 /**< PHY Initialization Engine (PIE) Instruction 91_1, offset: 0x276 */
  __IO uint16_t SEQUENCEREG0B91S2;                 /**< PHY Initialization Engine (PIE) Instruction 91_2, offset: 0x278 */
  __IO uint16_t SEQUENCEREG0B92S0;                 /**< PHY Initialization Engine (PIE) Instruction 92_0, offset: 0x27A */
  __IO uint16_t SEQUENCEREG0B92S1;                 /**< PHY Initialization Engine (PIE) Instruction 92_1, offset: 0x27C */
  __IO uint16_t SEQUENCEREG0B92S2;                 /**< PHY Initialization Engine (PIE) Instruction 92_2, offset: 0x27E */
  __IO uint16_t SEQUENCEREG0B93S0;                 /**< PHY Initialization Engine (PIE) Instruction 93_0, offset: 0x280 */
  __IO uint16_t SEQUENCEREG0B93S1;                 /**< PHY Initialization Engine (PIE) Instruction 93_1, offset: 0x282 */
  __IO uint16_t SEQUENCEREG0B93S2;                 /**< PHY Initialization Engine (PIE) Instruction 93_2, offset: 0x284 */
  __IO uint16_t SEQUENCEREG0B94S0;                 /**< PHY Initialization Engine (PIE) Instruction 94_0, offset: 0x286 */
  __IO uint16_t SEQUENCEREG0B94S1;                 /**< PHY Initialization Engine (PIE) Instruction 94_1, offset: 0x288 */
  __IO uint16_t SEQUENCEREG0B94S2;                 /**< PHY Initialization Engine (PIE) Instruction 94_2, offset: 0x28A */
  __IO uint16_t SEQUENCEREG0B95S0;                 /**< PHY Initialization Engine (PIE) Instruction 95_0, offset: 0x28C */
  __IO uint16_t SEQUENCEREG0B95S1;                 /**< PHY Initialization Engine (PIE) Instruction 95_1, offset: 0x28E */
  __IO uint16_t SEQUENCEREG0B95S2;                 /**< PHY Initialization Engine (PIE) Instruction 95_2, offset: 0x290 */
  __IO uint16_t SEQUENCEREG0B96S0;                 /**< PHY Initialization Engine (PIE) Instruction 96_0, offset: 0x292 */
  __IO uint16_t SEQUENCEREG0B96S1;                 /**< PHY Initialization Engine (PIE) Instruction 96_1, offset: 0x294 */
  __IO uint16_t SEQUENCEREG0B96S2;                 /**< PHY Initialization Engine (PIE) Instruction 96_2, offset: 0x296 */
  __IO uint16_t SEQUENCEREG0B97S0;                 /**< PHY Initialization Engine (PIE) Instruction 97_0, offset: 0x298 */
  __IO uint16_t SEQUENCEREG0B97S1;                 /**< PHY Initialization Engine (PIE) Instruction 97_1, offset: 0x29A */
  __IO uint16_t SEQUENCEREG0B97S2;                 /**< PHY Initialization Engine (PIE) Instruction 97_2, offset: 0x29C */
  __IO uint16_t SEQUENCEREG0B98S0;                 /**< PHY Initialization Engine (PIE) Instruction 98_0, offset: 0x29E */
  __IO uint16_t SEQUENCEREG0B98S1;                 /**< PHY Initialization Engine (PIE) Instruction 98_1, offset: 0x2A0 */
  __IO uint16_t SEQUENCEREG0B98S2;                 /**< PHY Initialization Engine (PIE) Instruction 98_2, offset: 0x2A2 */
  __IO uint16_t SEQUENCEREG0B99S0;                 /**< PHY Initialization Engine (PIE) Instruction 99_0, offset: 0x2A4 */
  __IO uint16_t SEQUENCEREG0B99S1;                 /**< PHY Initialization Engine (PIE) Instruction 99_1, offset: 0x2A6 */
  __IO uint16_t SEQUENCEREG0B99S2;                 /**< PHY Initialization Engine (PIE) Instruction 99_2, offset: 0x2A8 */
  __IO uint16_t SEQUENCEREG0B100S0;                /**< PHY Initialization Engine (PIE) Instruction 100_0, offset: 0x2AA */
  __IO uint16_t SEQUENCEREG0B100S1;                /**< PHY Initialization Engine (PIE) Instruction 100_1, offset: 0x2AC */
  __IO uint16_t SEQUENCEREG0B100S2;                /**< PHY Initialization Engine (PIE) Instruction 100_2, offset: 0x2AE */
  __IO uint16_t SEQUENCEREG0B101S0;                /**< PHY Initialization Engine (PIE) Instruction 101_0, offset: 0x2B0 */
  __IO uint16_t SEQUENCEREG0B101S1;                /**< PHY Initialization Engine (PIE) Instruction 101_1, offset: 0x2B2 */
  __IO uint16_t SEQUENCEREG0B101S2;                /**< PHY Initialization Engine (PIE) Instruction 101_2, offset: 0x2B4 */
  __IO uint16_t SEQUENCEREG0B102S0;                /**< PHY Initialization Engine (PIE) Instruction 102_0, offset: 0x2B6 */
  __IO uint16_t SEQUENCEREG0B102S1;                /**< PHY Initialization Engine (PIE) Instruction 102_1, offset: 0x2B8 */
  __IO uint16_t SEQUENCEREG0B102S2;                /**< PHY Initialization Engine (PIE) Instruction 102_2, offset: 0x2BA */
  __IO uint16_t SEQUENCEREG0B103S0;                /**< PHY Initialization Engine (PIE) Instruction 103_0, offset: 0x2BC */
  __IO uint16_t SEQUENCEREG0B103S1;                /**< PHY Initialization Engine (PIE) Instruction 103_1, offset: 0x2BE */
  __IO uint16_t SEQUENCEREG0B103S2;                /**< PHY Initialization Engine (PIE) Instruction 103_2, offset: 0x2C0 */
  __IO uint16_t SEQUENCEREG0B104S0;                /**< PHY Initialization Engine (PIE) Instruction 104_0, offset: 0x2C2 */
  __IO uint16_t SEQUENCEREG0B104S1;                /**< PHY Initialization Engine (PIE) Instruction 104_1, offset: 0x2C4 */
  __IO uint16_t SEQUENCEREG0B104S2;                /**< PHY Initialization Engine (PIE) Instruction 104_2, offset: 0x2C6 */
  __IO uint16_t SEQUENCEREG0B105S0;                /**< PHY Initialization Engine (PIE) Instruction 105_0, offset: 0x2C8 */
  __IO uint16_t SEQUENCEREG0B105S1;                /**< PHY Initialization Engine (PIE) Instruction 105_1, offset: 0x2CA */
  __IO uint16_t SEQUENCEREG0B105S2;                /**< PHY Initialization Engine (PIE) Instruction 105_2, offset: 0x2CC */
  __IO uint16_t SEQUENCEREG0B106S0;                /**< PHY Initialization Engine (PIE) Instruction 106_0, offset: 0x2CE */
  __IO uint16_t SEQUENCEREG0B106S1;                /**< PHY Initialization Engine (PIE) Instruction 106_1, offset: 0x2D0 */
  __IO uint16_t SEQUENCEREG0B106S2;                /**< PHY Initialization Engine (PIE) Instruction 106_2, offset: 0x2D2 */
  __IO uint16_t SEQUENCEREG0B107S0;                /**< PHY Initialization Engine (PIE) Instruction 107_0, offset: 0x2D4 */
  __IO uint16_t SEQUENCEREG0B107S1;                /**< PHY Initialization Engine (PIE) Instruction 107_1, offset: 0x2D6 */
  __IO uint16_t SEQUENCEREG0B107S2;                /**< PHY Initialization Engine (PIE) Instruction 107_2, offset: 0x2D8 */
  __IO uint16_t SEQUENCEREG0B108S0;                /**< PHY Initialization Engine (PIE) Instruction 108_0, offset: 0x2DA */
  __IO uint16_t SEQUENCEREG0B108S1;                /**< PHY Initialization Engine (PIE) Instruction 108_1, offset: 0x2DC */
  __IO uint16_t SEQUENCEREG0B108S2;                /**< PHY Initialization Engine (PIE) Instruction 108_2, offset: 0x2DE */
  __IO uint16_t SEQUENCEREG0B109S0;                /**< PHY Initialization Engine (PIE) Instruction 109_0, offset: 0x2E0 */
  __IO uint16_t SEQUENCEREG0B109S1;                /**< PHY Initialization Engine (PIE) Instruction 109_1, offset: 0x2E2 */
  __IO uint16_t SEQUENCEREG0B109S2;                /**< PHY Initialization Engine (PIE) Instruction 109_2, offset: 0x2E4 */
  __IO uint16_t SEQUENCEREG0B110S0;                /**< PHY Initialization Engine (PIE) Instruction 110_0, offset: 0x2E6 */
  __IO uint16_t SEQUENCEREG0B110S1;                /**< PHY Initialization Engine (PIE) Instruction 110_1, offset: 0x2E8 */
  __IO uint16_t SEQUENCEREG0B110S2;                /**< PHY Initialization Engine (PIE) Instruction 110_2, offset: 0x2EA */
  __IO uint16_t SEQUENCEREG0B111S0;                /**< PHY Initialization Engine (PIE) Instruction 111_0, offset: 0x2EC */
  __IO uint16_t SEQUENCEREG0B111S1;                /**< PHY Initialization Engine (PIE) Instruction 111_1, offset: 0x2EE */
  __IO uint16_t SEQUENCEREG0B111S2;                /**< PHY Initialization Engine (PIE) Instruction 111_2, offset: 0x2F0 */
  __IO uint16_t SEQUENCEREG0B112S0;                /**< PHY Initialization Engine (PIE) Instruction 112_0, offset: 0x2F2 */
  __IO uint16_t SEQUENCEREG0B112S1;                /**< PHY Initialization Engine (PIE) Instruction 112_1, offset: 0x2F4 */
  __IO uint16_t SEQUENCEREG0B112S2;                /**< PHY Initialization Engine (PIE) Instruction 112_2, offset: 0x2F6 */
  __IO uint16_t SEQUENCEREG0B113S0;                /**< PHY Initialization Engine (PIE) Instruction 113_0, offset: 0x2F8 */
  __IO uint16_t SEQUENCEREG0B113S1;                /**< PHY Initialization Engine (PIE) Instruction 113_1, offset: 0x2FA */
  __IO uint16_t SEQUENCEREG0B113S2;                /**< PHY Initialization Engine (PIE) Instruction 113_2, offset: 0x2FC */
  __IO uint16_t SEQUENCEREG0B114S0;                /**< PHY Initialization Engine (PIE) Instruction 114_0, offset: 0x2FE */
  __IO uint16_t SEQUENCEREG0B114S1;                /**< PHY Initialization Engine (PIE) Instruction 114_1, offset: 0x300 */
  __IO uint16_t SEQUENCEREG0B114S2;                /**< PHY Initialization Engine (PIE) Instruction 114_2, offset: 0x302 */
  __IO uint16_t SEQUENCEREG0B115S0;                /**< PHY Initialization Engine (PIE) Instruction 115_0, offset: 0x304 */
  __IO uint16_t SEQUENCEREG0B115S1;                /**< PHY Initialization Engine (PIE) Instruction 115_1, offset: 0x306 */
  __IO uint16_t SEQUENCEREG0B115S2;                /**< PHY Initialization Engine (PIE) Instruction 115_2, offset: 0x308 */
  __IO uint16_t SEQUENCEREG0B116S0;                /**< PHY Initialization Engine (PIE) Instruction 116_0, offset: 0x30A */
  __IO uint16_t SEQUENCEREG0B116S1;                /**< PHY Initialization Engine (PIE) Instruction 116_1, offset: 0x30C */
  __IO uint16_t SEQUENCEREG0B116S2;                /**< PHY Initialization Engine (PIE) Instruction 116_2, offset: 0x30E */
  __IO uint16_t SEQUENCEREG0B117S0;                /**< PHY Initialization Engine (PIE) Instruction 117_0, offset: 0x310 */
  __IO uint16_t SEQUENCEREG0B117S1;                /**< PHY Initialization Engine (PIE) Instruction 117_1, offset: 0x312 */
  __IO uint16_t SEQUENCEREG0B117S2;                /**< PHY Initialization Engine (PIE) Instruction 117_2, offset: 0x314 */
  __IO uint16_t SEQUENCEREG0B118S0;                /**< PHY Initialization Engine (PIE) Instruction 118_0, offset: 0x316 */
  __IO uint16_t SEQUENCEREG0B118S1;                /**< PHY Initialization Engine (PIE) Instruction 118_1, offset: 0x318 */
  __IO uint16_t SEQUENCEREG0B118S2;                /**< PHY Initialization Engine (PIE) Instruction 118_2, offset: 0x31A */
  __IO uint16_t SEQUENCEREG0B119S0;                /**< PHY Initialization Engine (PIE) Instruction 119_0, offset: 0x31C */
  __IO uint16_t SEQUENCEREG0B119S1;                /**< PHY Initialization Engine (PIE) Instruction 119_1, offset: 0x31E */
  __IO uint16_t SEQUENCEREG0B119S2;                /**< PHY Initialization Engine (PIE) Instruction 119_2, offset: 0x320 */
  __IO uint16_t SEQUENCEREG0B120S0;                /**< PHY Initialization Engine (PIE) Instruction 120_0, offset: 0x322 */
  __IO uint16_t SEQUENCEREG0B120S1;                /**< PHY Initialization Engine (PIE) Instruction 120_1, offset: 0x324 */
  __IO uint16_t SEQUENCEREG0B120S2;                /**< PHY Initialization Engine (PIE) Instruction 120_2, offset: 0x326 */
  __IO uint16_t SEQUENCEREG0B121S0;                /**< PHY Initialization Engine (PIE) Instruction 121_0, offset: 0x328 */
  __IO uint16_t SEQUENCEREG0B121S1;                /**< PHY Initialization Engine (PIE) Instruction 121_1, offset: 0x32A */
  __IO uint16_t SEQUENCEREG0B121S2;                /**< PHY Initialization Engine (PIE) Instruction 121_2, offset: 0x32C */
       uint8_t RESERVED_1[212];
  __IO uint16_t SEQ0BGPR1_P0;                      /**< PHY Initialization Engine (PIE) General Purpose Register 1, offset: 0x402 */
  __IO uint16_t SEQ0BGPR2_P0;                      /**< PHY Initialization Engine (PIE) General Purpose Register 2, offset: 0x404 */
  __IO uint16_t SEQ0BGPR3_P0;                      /**< PHY Initialization Engine (PIE) General Purpose Register 3, offset: 0x406 */
  __IO uint16_t SEQ0BGPR4_P0;                      /**< PHY Initialization Engine (PIE) General Purpose Register 4, offset: 0x408 */
  __IO uint16_t SEQ0BGPR5_P0;                      /**< PHY Initialization Engine (PIE) General Purpose Register 5, offset: 0x40A */
  __IO uint16_t SEQ0BGPR6_P0;                      /**< PHY Initialization Engine (PIE) General Purpose Register 6, offset: 0x40C */
  __IO uint16_t SEQ0BGPR7_P0;                      /**< PHY Initialization Engine (PIE) General Purpose Register 7, offset: 0x40E */
  __IO uint16_t SEQ0BGPR8_P0;                      /**< PHY Initialization Engine (PIE) General Purpose Register 8, offset: 0x410 */
       uint8_t RESERVED_2[492];
  __IO uint16_t SEQ0BFIXEDADDRBITS;                /**< Address fill-ins for PIE CSR writes, offset: 0x5FE */
       uint8_t RESERVED_3[2096642];
  __IO uint16_t SEQ0BGPR1_P1;                      /**< PHY Initialization Engine (PIE) General Purpose Register 1, offset: 0x200402 */
  __IO uint16_t SEQ0BGPR2_P1;                      /**< PHY Initialization Engine (PIE) General Purpose Register 2, offset: 0x200404 */
  __IO uint16_t SEQ0BGPR3_P1;                      /**< PHY Initialization Engine (PIE) General Purpose Register 3, offset: 0x200406 */
  __IO uint16_t SEQ0BGPR4_P1;                      /**< PHY Initialization Engine (PIE) General Purpose Register 4, offset: 0x200408 */
  __IO uint16_t SEQ0BGPR5_P1;                      /**< PHY Initialization Engine (PIE) General Purpose Register 5, offset: 0x20040A */
  __IO uint16_t SEQ0BGPR6_P1;                      /**< PHY Initialization Engine (PIE) General Purpose Register 6, offset: 0x20040C */
  __IO uint16_t SEQ0BGPR7_P1;                      /**< PHY Initialization Engine (PIE) General Purpose Register 7, offset: 0x20040E */
  __IO uint16_t SEQ0BGPR8_P1;                      /**< PHY Initialization Engine (PIE) General Purpose Register 8, offset: 0x200410 */
       uint8_t RESERVED_4[2097136];
  __IO uint16_t SEQ0BGPR1_P2;                      /**< PHY Initialization Engine (PIE) General Purpose Register 1, offset: 0x400402 */
  __IO uint16_t SEQ0BGPR2_P2;                      /**< PHY Initialization Engine (PIE) General Purpose Register 2, offset: 0x400404 */
  __IO uint16_t SEQ0BGPR3_P2;                      /**< PHY Initialization Engine (PIE) General Purpose Register 3, offset: 0x400406 */
  __IO uint16_t SEQ0BGPR4_P2;                      /**< PHY Initialization Engine (PIE) General Purpose Register 4, offset: 0x400408 */
  __IO uint16_t SEQ0BGPR5_P2;                      /**< PHY Initialization Engine (PIE) General Purpose Register 5, offset: 0x40040A */
  __IO uint16_t SEQ0BGPR6_P2;                      /**< PHY Initialization Engine (PIE) General Purpose Register 6, offset: 0x40040C */
  __IO uint16_t SEQ0BGPR7_P2;                      /**< PHY Initialization Engine (PIE) General Purpose Register 7, offset: 0x40040E */
  __IO uint16_t SEQ0BGPR8_P2;                      /**< PHY Initialization Engine (PIE) General Purpose Register 8, offset: 0x400410 */
       uint8_t RESERVED_5[2097136];
  __IO uint16_t SEQ0BGPR1_P3;                      /**< PHY Initialization Engine (PIE) General Purpose Register 1, offset: 0x600402 */
  __IO uint16_t SEQ0BGPR2_P3;                      /**< PHY Initialization Engine (PIE) General Purpose Register 2, offset: 0x600404 */
  __IO uint16_t SEQ0BGPR3_P3;                      /**< PHY Initialization Engine (PIE) General Purpose Register 3, offset: 0x600406 */
  __IO uint16_t SEQ0BGPR4_P3;                      /**< PHY Initialization Engine (PIE) General Purpose Register 4, offset: 0x600408 */
  __IO uint16_t SEQ0BGPR5_P3;                      /**< PHY Initialization Engine (PIE) General Purpose Register 5, offset: 0x60040A */
  __IO uint16_t SEQ0BGPR6_P3;                      /**< PHY Initialization Engine (PIE) General Purpose Register 6, offset: 0x60040C */
  __IO uint16_t SEQ0BGPR7_P3;                      /**< PHY Initialization Engine (PIE) General Purpose Register 7, offset: 0x60040E */
  __IO uint16_t SEQ0BGPR8_P3;                      /**< PHY Initialization Engine (PIE) General Purpose Register 8, offset: 0x600410 */
} DWC_DDRPHYA_INITENG_Type;

/* ----------------------------------------------------------------------------
   -- DWC_DDRPHYA_INITENG Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DWC_DDRPHYA_INITENG_Register_Masks DWC_DDRPHYA_INITENG Register Masks
 * @{
 */

/*! @name PRESEQUENCEREG0B0S0 - PHY Initialization Engine (PIE) Pre-Instruction 0_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_PRESEQUENCEREG0B0S0_PreSequenceReg0b0s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_PRESEQUENCEREG0B0S0_PreSequenceReg0b0s0_SHIFT (0U)
/*! PreSequenceReg0b0s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_PRESEQUENCEREG0B0S0_PreSequenceReg0b0s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_PRESEQUENCEREG0B0S0_PreSequenceReg0b0s0_SHIFT)) & DWC_DDRPHYA_INITENG_PRESEQUENCEREG0B0S0_PreSequenceReg0b0s0_MASK)
/*! @} */

/*! @name PRESEQUENCEREG0B0S1 - PHY Initialization Engine (PIE) Pre-Instruction 0_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_PRESEQUENCEREG0B0S1_PreSequenceReg0b0s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_PRESEQUENCEREG0B0S1_PreSequenceReg0b0s1_SHIFT (0U)
/*! PreSequenceReg0b0s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_PRESEQUENCEREG0B0S1_PreSequenceReg0b0s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_PRESEQUENCEREG0B0S1_PreSequenceReg0b0s1_SHIFT)) & DWC_DDRPHYA_INITENG_PRESEQUENCEREG0B0S1_PreSequenceReg0b0s1_MASK)
/*! @} */

/*! @name PRESEQUENCEREG0B0S2 - PHY Initialization Engine (PIE) Pre-Instruction 0_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_PRESEQUENCEREG0B0S2_PreSequenceReg0b0s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_PRESEQUENCEREG0B0S2_PreSequenceReg0b0s2_SHIFT (0U)
/*! PreSequenceReg0b0s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_PRESEQUENCEREG0B0S2_PreSequenceReg0b0s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_PRESEQUENCEREG0B0S2_PreSequenceReg0b0s2_SHIFT)) & DWC_DDRPHYA_INITENG_PRESEQUENCEREG0B0S2_PreSequenceReg0b0s2_MASK)
/*! @} */

/*! @name PRESEQUENCEREG0B1S0 - PHY Initialization Engine (PIE) Pre-Instruction 1_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_PRESEQUENCEREG0B1S0_PreSequenceReg0b1s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_PRESEQUENCEREG0B1S0_PreSequenceReg0b1s0_SHIFT (0U)
/*! PreSequenceReg0b1s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_PRESEQUENCEREG0B1S0_PreSequenceReg0b1s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_PRESEQUENCEREG0B1S0_PreSequenceReg0b1s0_SHIFT)) & DWC_DDRPHYA_INITENG_PRESEQUENCEREG0B1S0_PreSequenceReg0b1s0_MASK)
/*! @} */

/*! @name PRESEQUENCEREG0B1S1 - PHY Initialization Engine (PIE) Pre-Instruction 1_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_PRESEQUENCEREG0B1S1_PreSequenceReg0b1s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_PRESEQUENCEREG0B1S1_PreSequenceReg0b1s1_SHIFT (0U)
/*! PreSequenceReg0b1s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_PRESEQUENCEREG0B1S1_PreSequenceReg0b1s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_PRESEQUENCEREG0B1S1_PreSequenceReg0b1s1_SHIFT)) & DWC_DDRPHYA_INITENG_PRESEQUENCEREG0B1S1_PreSequenceReg0b1s1_MASK)
/*! @} */

/*! @name PRESEQUENCEREG0B1S2 - PHY Initialization Engine (PIE) Pre-Instruction 1_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_PRESEQUENCEREG0B1S2_PreSequenceReg0b1s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_PRESEQUENCEREG0B1S2_PreSequenceReg0b1s2_SHIFT (0U)
/*! PreSequenceReg0b1s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_PRESEQUENCEREG0B1S2_PreSequenceReg0b1s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_PRESEQUENCEREG0B1S2_PreSequenceReg0b1s2_SHIFT)) & DWC_DDRPHYA_INITENG_PRESEQUENCEREG0B1S2_PreSequenceReg0b1s2_MASK)
/*! @} */

/*! @name POSTSEQUENCEREG0B0S0 - PHY Initialization Engine (PIE) Post-Instruction 0_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_POSTSEQUENCEREG0B0S0_PostSequenceReg0b0s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_POSTSEQUENCEREG0B0S0_PostSequenceReg0b0s0_SHIFT (0U)
/*! PostSequenceReg0b0s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_POSTSEQUENCEREG0B0S0_PostSequenceReg0b0s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_POSTSEQUENCEREG0B0S0_PostSequenceReg0b0s0_SHIFT)) & DWC_DDRPHYA_INITENG_POSTSEQUENCEREG0B0S0_PostSequenceReg0b0s0_MASK)
/*! @} */

/*! @name POSTSEQUENCEREG0B0S1 - PHY Initialization Engine (PIE) Post-Instruction 0_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_POSTSEQUENCEREG0B0S1_PostSequenceReg0b0s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_POSTSEQUENCEREG0B0S1_PostSequenceReg0b0s1_SHIFT (0U)
/*! PostSequenceReg0b0s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_POSTSEQUENCEREG0B0S1_PostSequenceReg0b0s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_POSTSEQUENCEREG0B0S1_PostSequenceReg0b0s1_SHIFT)) & DWC_DDRPHYA_INITENG_POSTSEQUENCEREG0B0S1_PostSequenceReg0b0s1_MASK)
/*! @} */

/*! @name POSTSEQUENCEREG0B0S2 - PHY Initialization Engine (PIE) Post-Instruction 0_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_POSTSEQUENCEREG0B0S2_PostSequenceReg0b0s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_POSTSEQUENCEREG0B0S2_PostSequenceReg0b0s2_SHIFT (0U)
/*! PostSequenceReg0b0s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_POSTSEQUENCEREG0B0S2_PostSequenceReg0b0s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_POSTSEQUENCEREG0B0S2_PostSequenceReg0b0s2_SHIFT)) & DWC_DDRPHYA_INITENG_POSTSEQUENCEREG0B0S2_PostSequenceReg0b0s2_MASK)
/*! @} */

/*! @name POSTSEQUENCEREG0B1S0 - PHY Initialization Engine (PIE) Post-Instruction 1_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_POSTSEQUENCEREG0B1S0_PostSequenceReg0b1s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_POSTSEQUENCEREG0B1S0_PostSequenceReg0b1s0_SHIFT (0U)
/*! PostSequenceReg0b1s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_POSTSEQUENCEREG0B1S0_PostSequenceReg0b1s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_POSTSEQUENCEREG0B1S0_PostSequenceReg0b1s0_SHIFT)) & DWC_DDRPHYA_INITENG_POSTSEQUENCEREG0B1S0_PostSequenceReg0b1s0_MASK)
/*! @} */

/*! @name POSTSEQUENCEREG0B1S1 - PHY Initialization Engine (PIE) Post-Instruction 1_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_POSTSEQUENCEREG0B1S1_PostSequenceReg0b1s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_POSTSEQUENCEREG0B1S1_PostSequenceReg0b1s1_SHIFT (0U)
/*! PostSequenceReg0b1s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_POSTSEQUENCEREG0B1S1_PostSequenceReg0b1s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_POSTSEQUENCEREG0B1S1_PostSequenceReg0b1s1_SHIFT)) & DWC_DDRPHYA_INITENG_POSTSEQUENCEREG0B1S1_PostSequenceReg0b1s1_MASK)
/*! @} */

/*! @name POSTSEQUENCEREG0B1S2 - PHY Initialization Engine (PIE) Post-Instruction 1_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_POSTSEQUENCEREG0B1S2_PostSequenceReg0b1s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_POSTSEQUENCEREG0B1S2_PostSequenceReg0b1s2_SHIFT (0U)
/*! PostSequenceReg0b1s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_POSTSEQUENCEREG0B1S2_PostSequenceReg0b1s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_POSTSEQUENCEREG0B1S2_PostSequenceReg0b1s2_SHIFT)) & DWC_DDRPHYA_INITENG_POSTSEQUENCEREG0B1S2_PostSequenceReg0b1s2_MASK)
/*! @} */

/*! @name SEQ0BDISABLEFLAG0 - PHY Initialization Engine (PIE) Disable Instruction Group 0 Disable Bits */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQ0BDISABLEFLAG0_Seq0BDisableFlag0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQ0BDISABLEFLAG0_Seq0BDisableFlag0_SHIFT (0U)
/*! Seq0BDisableFlag0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQ0BDISABLEFLAG0_Seq0BDisableFlag0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQ0BDISABLEFLAG0_Seq0BDisableFlag0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQ0BDISABLEFLAG0_Seq0BDisableFlag0_MASK)
/*! @} */

/*! @name SEQ0BDISABLEFLAG1 - PHY Initialization Engine (PIE) Disable Instruction Group 1 Disable Bits */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQ0BDISABLEFLAG1_Seq0BDisableFlag1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQ0BDISABLEFLAG1_Seq0BDisableFlag1_SHIFT (0U)
/*! Seq0BDisableFlag1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQ0BDISABLEFLAG1_Seq0BDisableFlag1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQ0BDISABLEFLAG1_Seq0BDisableFlag1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQ0BDISABLEFLAG1_Seq0BDisableFlag1_MASK)
/*! @} */

/*! @name SEQ0BDISABLEFLAG2 - PHY Initialization Engine (PIE) Disable Instruction Group 2 Disable Bits */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQ0BDISABLEFLAG2_Seq0BDisableFlag2_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQ0BDISABLEFLAG2_Seq0BDisableFlag2_SHIFT (0U)
/*! Seq0BDisableFlag2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQ0BDISABLEFLAG2_Seq0BDisableFlag2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQ0BDISABLEFLAG2_Seq0BDisableFlag2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQ0BDISABLEFLAG2_Seq0BDisableFlag2_MASK)
/*! @} */

/*! @name SEQ0BDISABLEFLAG3 - PHY Initialization Engine (PIE) Disable Instruction Group 3 Disable Bits */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQ0BDISABLEFLAG3_Seq0BDisableFlag3_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQ0BDISABLEFLAG3_Seq0BDisableFlag3_SHIFT (0U)
/*! Seq0BDisableFlag3 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQ0BDISABLEFLAG3_Seq0BDisableFlag3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQ0BDISABLEFLAG3_Seq0BDisableFlag3_SHIFT)) & DWC_DDRPHYA_INITENG_SEQ0BDISABLEFLAG3_Seq0BDisableFlag3_MASK)
/*! @} */

/*! @name SEQ0BDISABLEFLAG4 - PHY Initialization Engine (PIE) Disable Instruction Group 4 Disable Bits */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQ0BDISABLEFLAG4_Seq0BDisableFlag4_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQ0BDISABLEFLAG4_Seq0BDisableFlag4_SHIFT (0U)
/*! Seq0BDisableFlag4 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQ0BDISABLEFLAG4_Seq0BDisableFlag4(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQ0BDISABLEFLAG4_Seq0BDisableFlag4_SHIFT)) & DWC_DDRPHYA_INITENG_SEQ0BDISABLEFLAG4_Seq0BDisableFlag4_MASK)
/*! @} */

/*! @name SEQ0BDISABLEFLAG5 - PHY Initialization Engine (PIE) Disable Instruction Group 5 Disable Bits */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQ0BDISABLEFLAG5_Seq0BDisableFlag5_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQ0BDISABLEFLAG5_Seq0BDisableFlag5_SHIFT (0U)
/*! Seq0BDisableFlag5 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQ0BDISABLEFLAG5_Seq0BDisableFlag5(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQ0BDISABLEFLAG5_Seq0BDisableFlag5_SHIFT)) & DWC_DDRPHYA_INITENG_SEQ0BDISABLEFLAG5_Seq0BDisableFlag5_MASK)
/*! @} */

/*! @name SEQ0BDISABLEFLAG6 - PHY Initialization Engine (PIE) Disable Instruction Group 6 Disable Bits */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQ0BDISABLEFLAG6_Seq0BDisableFlag6_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQ0BDISABLEFLAG6_Seq0BDisableFlag6_SHIFT (0U)
/*! Seq0BDisableFlag6 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQ0BDISABLEFLAG6_Seq0BDisableFlag6(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQ0BDISABLEFLAG6_Seq0BDisableFlag6_SHIFT)) & DWC_DDRPHYA_INITENG_SEQ0BDISABLEFLAG6_Seq0BDisableFlag6_MASK)
/*! @} */

/*! @name SEQ0BDISABLEFLAG7 - PHY Initialization Engine (PIE) Disable Instruction Group 7 Disable Bits */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQ0BDISABLEFLAG7_Seq0BDisableFlag7_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQ0BDISABLEFLAG7_Seq0BDisableFlag7_SHIFT (0U)
/*! Seq0BDisableFlag7 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQ0BDISABLEFLAG7_Seq0BDisableFlag7(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQ0BDISABLEFLAG7_Seq0BDisableFlag7_SHIFT)) & DWC_DDRPHYA_INITENG_SEQ0BDISABLEFLAG7_Seq0BDisableFlag7_MASK)
/*! @} */

/*! @name STARTVECTOR0B0 - PHY Initialization Engine (PIE) start vector 0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_STARTVECTOR0B0_RFU_StartVector0b0_MASK (0x7FU)
#define DWC_DDRPHYA_INITENG_STARTVECTOR0B0_RFU_StartVector0b0_SHIFT (0U)
/*! RFU_StartVector0b0 - RFU_StartVector0b0 */
#define DWC_DDRPHYA_INITENG_STARTVECTOR0B0_RFU_StartVector0b0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_STARTVECTOR0B0_RFU_StartVector0b0_SHIFT)) & DWC_DDRPHYA_INITENG_STARTVECTOR0B0_RFU_StartVector0b0_MASK)
/*! @} */

/*! @name STARTVECTOR0B1 - PHY Initialization Engine (PIE) start vector 1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_STARTVECTOR0B1_RFU_StartVector0b1_MASK (0x7FU)
#define DWC_DDRPHYA_INITENG_STARTVECTOR0B1_RFU_StartVector0b1_SHIFT (0U)
/*! RFU_StartVector0b1 - RFU_StartVector0b1 */
#define DWC_DDRPHYA_INITENG_STARTVECTOR0B1_RFU_StartVector0b1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_STARTVECTOR0B1_RFU_StartVector0b1_SHIFT)) & DWC_DDRPHYA_INITENG_STARTVECTOR0B1_RFU_StartVector0b1_MASK)
/*! @} */

/*! @name STARTVECTOR0B2 - PHY Initialization Engine (PIE) start vector 2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_STARTVECTOR0B2_RFU_StartVector0b2_MASK (0x7FU)
#define DWC_DDRPHYA_INITENG_STARTVECTOR0B2_RFU_StartVector0b2_SHIFT (0U)
/*! RFU_StartVector0b2 - RFU_StartVector0b2 */
#define DWC_DDRPHYA_INITENG_STARTVECTOR0B2_RFU_StartVector0b2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_STARTVECTOR0B2_RFU_StartVector0b2_SHIFT)) & DWC_DDRPHYA_INITENG_STARTVECTOR0B2_RFU_StartVector0b2_MASK)
/*! @} */

/*! @name STARTVECTOR0B3 - PHY Initialization Engine (PIE) start vector 3 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_STARTVECTOR0B3_RFU_StartVector0b3_MASK (0x7FU)
#define DWC_DDRPHYA_INITENG_STARTVECTOR0B3_RFU_StartVector0b3_SHIFT (0U)
/*! RFU_StartVector0b3 - RFU_StartVector0b3 */
#define DWC_DDRPHYA_INITENG_STARTVECTOR0B3_RFU_StartVector0b3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_STARTVECTOR0B3_RFU_StartVector0b3_SHIFT)) & DWC_DDRPHYA_INITENG_STARTVECTOR0B3_RFU_StartVector0b3_MASK)
/*! @} */

/*! @name STARTVECTOR0B4 - PHY Initialization Engine (PIE) start vector 4 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_STARTVECTOR0B4_RFU_StartVector0b4_MASK (0x7FU)
#define DWC_DDRPHYA_INITENG_STARTVECTOR0B4_RFU_StartVector0b4_SHIFT (0U)
/*! RFU_StartVector0b4 - RFU_StartVector0b4 */
#define DWC_DDRPHYA_INITENG_STARTVECTOR0B4_RFU_StartVector0b4(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_STARTVECTOR0B4_RFU_StartVector0b4_SHIFT)) & DWC_DDRPHYA_INITENG_STARTVECTOR0B4_RFU_StartVector0b4_MASK)
/*! @} */

/*! @name STARTVECTOR0B5 - PHY Initialization Engine (PIE) start vector 5 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_STARTVECTOR0B5_RFU_StartVector0b5_MASK (0x7FU)
#define DWC_DDRPHYA_INITENG_STARTVECTOR0B5_RFU_StartVector0b5_SHIFT (0U)
/*! RFU_StartVector0b5 - RFU_StartVector0b5 */
#define DWC_DDRPHYA_INITENG_STARTVECTOR0B5_RFU_StartVector0b5(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_STARTVECTOR0B5_RFU_StartVector0b5_SHIFT)) & DWC_DDRPHYA_INITENG_STARTVECTOR0B5_RFU_StartVector0b5_MASK)
/*! @} */

/*! @name STARTVECTOR0B6 - PHY Initialization Engine (PIE) start vector 6 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_STARTVECTOR0B6_RFU_StartVector0b6_MASK (0x7FU)
#define DWC_DDRPHYA_INITENG_STARTVECTOR0B6_RFU_StartVector0b6_SHIFT (0U)
/*! RFU_StartVector0b6 - RFU_StartVector0b6 */
#define DWC_DDRPHYA_INITENG_STARTVECTOR0B6_RFU_StartVector0b6(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_STARTVECTOR0B6_RFU_StartVector0b6_SHIFT)) & DWC_DDRPHYA_INITENG_STARTVECTOR0B6_RFU_StartVector0b6_MASK)
/*! @} */

/*! @name STARTVECTOR0B7 - PHY Initialization Engine (PIE) start vector 7 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_STARTVECTOR0B7_RFU_StartVector0b7_MASK (0x7FU)
#define DWC_DDRPHYA_INITENG_STARTVECTOR0B7_RFU_StartVector0b7_SHIFT (0U)
/*! RFU_StartVector0b7 - RFU_StartVector0b7 */
#define DWC_DDRPHYA_INITENG_STARTVECTOR0B7_RFU_StartVector0b7(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_STARTVECTOR0B7_RFU_StartVector0b7_SHIFT)) & DWC_DDRPHYA_INITENG_STARTVECTOR0B7_RFU_StartVector0b7_MASK)
/*! @} */

/*! @name STARTVECTOR0B8 - PHY Initialization Engine (PIE) start vector 8 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_STARTVECTOR0B8_RFU_StartVector0b8_MASK (0x7FU)
#define DWC_DDRPHYA_INITENG_STARTVECTOR0B8_RFU_StartVector0b8_SHIFT (0U)
/*! RFU_StartVector0b8 - RFU_StartVector0b8 */
#define DWC_DDRPHYA_INITENG_STARTVECTOR0B8_RFU_StartVector0b8(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_STARTVECTOR0B8_RFU_StartVector0b8_SHIFT)) & DWC_DDRPHYA_INITENG_STARTVECTOR0B8_RFU_StartVector0b8_MASK)
/*! @} */

/*! @name STARTVECTOR0B9 - PHY Initialization Engine (PIE) start vector 9 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_STARTVECTOR0B9_RFU_StartVector0b9_MASK (0x7FU)
#define DWC_DDRPHYA_INITENG_STARTVECTOR0B9_RFU_StartVector0b9_SHIFT (0U)
/*! RFU_StartVector0b9 - RFU_StartVector0b9 */
#define DWC_DDRPHYA_INITENG_STARTVECTOR0B9_RFU_StartVector0b9(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_STARTVECTOR0B9_RFU_StartVector0b9_SHIFT)) & DWC_DDRPHYA_INITENG_STARTVECTOR0B9_RFU_StartVector0b9_MASK)
/*! @} */

/*! @name STARTVECTOR0B10 - PHY Initialization Engine (PIE) start vector 10 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_STARTVECTOR0B10_RFU_StartVector0b10_MASK (0x7FU)
#define DWC_DDRPHYA_INITENG_STARTVECTOR0B10_RFU_StartVector0b10_SHIFT (0U)
/*! RFU_StartVector0b10 - RFU_StartVector0b10 */
#define DWC_DDRPHYA_INITENG_STARTVECTOR0B10_RFU_StartVector0b10(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_STARTVECTOR0B10_RFU_StartVector0b10_SHIFT)) & DWC_DDRPHYA_INITENG_STARTVECTOR0B10_RFU_StartVector0b10_MASK)
/*! @} */

/*! @name STARTVECTOR0B11 - PHY Initialization Engine (PIE) start vector 11 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_STARTVECTOR0B11_RFU_StartVector0b11_MASK (0x7FU)
#define DWC_DDRPHYA_INITENG_STARTVECTOR0B11_RFU_StartVector0b11_SHIFT (0U)
/*! RFU_StartVector0b11 - RFU_StartVector0b11 */
#define DWC_DDRPHYA_INITENG_STARTVECTOR0B11_RFU_StartVector0b11(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_STARTVECTOR0B11_RFU_StartVector0b11_SHIFT)) & DWC_DDRPHYA_INITENG_STARTVECTOR0B11_RFU_StartVector0b11_MASK)
/*! @} */

/*! @name STARTVECTOR0B12 - PHY Initialization Engine (PIE) start vector 12 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_STARTVECTOR0B12_RFU_StartVector0b12_MASK (0x7FU)
#define DWC_DDRPHYA_INITENG_STARTVECTOR0B12_RFU_StartVector0b12_SHIFT (0U)
/*! RFU_StartVector0b12 - RFU_StartVector0b12 */
#define DWC_DDRPHYA_INITENG_STARTVECTOR0B12_RFU_StartVector0b12(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_STARTVECTOR0B12_RFU_StartVector0b12_SHIFT)) & DWC_DDRPHYA_INITENG_STARTVECTOR0B12_RFU_StartVector0b12_MASK)
/*! @} */

/*! @name STARTVECTOR0B13 - PHY Initialization Engine (PIE) start vector 13 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_STARTVECTOR0B13_RFU_StartVector0b13_MASK (0x7FU)
#define DWC_DDRPHYA_INITENG_STARTVECTOR0B13_RFU_StartVector0b13_SHIFT (0U)
/*! RFU_StartVector0b13 - RFU_StartVector0b13 */
#define DWC_DDRPHYA_INITENG_STARTVECTOR0B13_RFU_StartVector0b13(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_STARTVECTOR0B13_RFU_StartVector0b13_SHIFT)) & DWC_DDRPHYA_INITENG_STARTVECTOR0B13_RFU_StartVector0b13_MASK)
/*! @} */

/*! @name STARTVECTOR0B14 - PHY Initialization Engine (PIE) start vector 14 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_STARTVECTOR0B14_RFU_StartVector0b14_MASK (0x7FU)
#define DWC_DDRPHYA_INITENG_STARTVECTOR0B14_RFU_StartVector0b14_SHIFT (0U)
/*! RFU_StartVector0b14 - RFU_StartVector0b14 */
#define DWC_DDRPHYA_INITENG_STARTVECTOR0B14_RFU_StartVector0b14(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_STARTVECTOR0B14_RFU_StartVector0b14_SHIFT)) & DWC_DDRPHYA_INITENG_STARTVECTOR0B14_RFU_StartVector0b14_MASK)
/*! @} */

/*! @name STARTVECTOR0B15 - PHY Initialization Engine (PIE) start vector 15 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_STARTVECTOR0B15_RFU_StartVector0b15_MASK (0x7FU)
#define DWC_DDRPHYA_INITENG_STARTVECTOR0B15_RFU_StartVector0b15_SHIFT (0U)
/*! RFU_StartVector0b15 - RFU_StartVector0b15 */
#define DWC_DDRPHYA_INITENG_STARTVECTOR0B15_RFU_StartVector0b15(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_STARTVECTOR0B15_RFU_StartVector0b15_SHIFT)) & DWC_DDRPHYA_INITENG_STARTVECTOR0B15_RFU_StartVector0b15_MASK)
/*! @} */

/*! @name SEQ0BWAITCONDSEL - PHY Initialization Engine (PIE) wait condition selection */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQ0BWAITCONDSEL_Seq0bWaitCondSel_MASK (0x7U)
#define DWC_DDRPHYA_INITENG_SEQ0BWAITCONDSEL_Seq0bWaitCondSel_SHIFT (0U)
/*! Seq0bWaitCondSel - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQ0BWAITCONDSEL_Seq0bWaitCondSel(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQ0BWAITCONDSEL_Seq0bWaitCondSel_SHIFT)) & DWC_DDRPHYA_INITENG_SEQ0BWAITCONDSEL_Seq0bWaitCondSel_MASK)
/*! @} */

/*! @name PHYINLP3 - Indicator for PIE Lower Power 3 (LP3) Status */
/*! @{ */

#define DWC_DDRPHYA_INITENG_PHYINLP3_PhyInLP3_MASK (0x1U)
#define DWC_DDRPHYA_INITENG_PHYINLP3_PhyInLP3_SHIFT (0U)
/*! PhyInLP3 - Read Only. */
#define DWC_DDRPHYA_INITENG_PHYINLP3_PhyInLP3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_PHYINLP3_PhyInLP3_SHIFT)) & DWC_DDRPHYA_INITENG_PHYINLP3_PhyInLP3_MASK)
/*! @} */

/*! @name SEQUENCEREG0B0S0 - PHY Initialization Engine (PIE) Instruction 0_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B0S0_SequenceReg0b0s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B0S0_SequenceReg0b0s0_SHIFT (0U)
/*! SequenceReg0b0s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B0S0_SequenceReg0b0s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B0S0_SequenceReg0b0s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B0S0_SequenceReg0b0s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B0S1 - PHY Initialization Engine (PIE) Instruction 0_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B0S1_SequenceReg0b0s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B0S1_SequenceReg0b0s1_SHIFT (0U)
/*! SequenceReg0b0s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B0S1_SequenceReg0b0s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B0S1_SequenceReg0b0s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B0S1_SequenceReg0b0s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B0S2 - PHY Initialization Engine (PIE) Instruction 0_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B0S2_SequenceReg0b0s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B0S2_SequenceReg0b0s2_SHIFT (0U)
/*! SequenceReg0b0s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B0S2_SequenceReg0b0s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B0S2_SequenceReg0b0s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B0S2_SequenceReg0b0s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B1S0 - PHY Initialization Engine (PIE) Instruction 1_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B1S0_SequenceReg0b1s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B1S0_SequenceReg0b1s0_SHIFT (0U)
/*! SequenceReg0b1s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B1S0_SequenceReg0b1s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B1S0_SequenceReg0b1s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B1S0_SequenceReg0b1s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B1S1 - PHY Initialization Engine (PIE) Instruction 1_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B1S1_SequenceReg0b1s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B1S1_SequenceReg0b1s1_SHIFT (0U)
/*! SequenceReg0b1s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B1S1_SequenceReg0b1s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B1S1_SequenceReg0b1s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B1S1_SequenceReg0b1s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B1S2 - PHY Initialization Engine (PIE) Instruction 1_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B1S2_SequenceReg0b1s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B1S2_SequenceReg0b1s2_SHIFT (0U)
/*! SequenceReg0b1s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B1S2_SequenceReg0b1s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B1S2_SequenceReg0b1s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B1S2_SequenceReg0b1s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B2S0 - PHY Initialization Engine (PIE) Instruction 2_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B2S0_SequenceReg0b2s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B2S0_SequenceReg0b2s0_SHIFT (0U)
/*! SequenceReg0b2s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B2S0_SequenceReg0b2s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B2S0_SequenceReg0b2s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B2S0_SequenceReg0b2s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B2S1 - PHY Initialization Engine (PIE) Instruction 2_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B2S1_SequenceReg0b2s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B2S1_SequenceReg0b2s1_SHIFT (0U)
/*! SequenceReg0b2s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B2S1_SequenceReg0b2s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B2S1_SequenceReg0b2s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B2S1_SequenceReg0b2s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B2S2 - PHY Initialization Engine (PIE) Instruction 2_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B2S2_SequenceReg0b2s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B2S2_SequenceReg0b2s2_SHIFT (0U)
/*! SequenceReg0b2s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B2S2_SequenceReg0b2s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B2S2_SequenceReg0b2s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B2S2_SequenceReg0b2s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B3S0 - PHY Initialization Engine (PIE) Instruction 3_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B3S0_SequenceReg0b3s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B3S0_SequenceReg0b3s0_SHIFT (0U)
/*! SequenceReg0b3s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B3S0_SequenceReg0b3s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B3S0_SequenceReg0b3s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B3S0_SequenceReg0b3s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B3S1 - PHY Initialization Engine (PIE) Instruction 3_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B3S1_SequenceReg0b3s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B3S1_SequenceReg0b3s1_SHIFT (0U)
/*! SequenceReg0b3s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B3S1_SequenceReg0b3s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B3S1_SequenceReg0b3s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B3S1_SequenceReg0b3s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B3S2 - PHY Initialization Engine (PIE) Instruction 3_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B3S2_SequenceReg0b3s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B3S2_SequenceReg0b3s2_SHIFT (0U)
/*! SequenceReg0b3s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B3S2_SequenceReg0b3s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B3S2_SequenceReg0b3s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B3S2_SequenceReg0b3s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B4S0 - PHY Initialization Engine (PIE) Instruction 4_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B4S0_SequenceReg0b4s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B4S0_SequenceReg0b4s0_SHIFT (0U)
/*! SequenceReg0b4s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B4S0_SequenceReg0b4s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B4S0_SequenceReg0b4s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B4S0_SequenceReg0b4s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B4S1 - PHY Initialization Engine (PIE) Instruction 4_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B4S1_SequenceReg0b4s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B4S1_SequenceReg0b4s1_SHIFT (0U)
/*! SequenceReg0b4s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B4S1_SequenceReg0b4s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B4S1_SequenceReg0b4s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B4S1_SequenceReg0b4s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B4S2 - PHY Initialization Engine (PIE) Instruction 4_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B4S2_SequenceReg0b4s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B4S2_SequenceReg0b4s2_SHIFT (0U)
/*! SequenceReg0b4s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B4S2_SequenceReg0b4s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B4S2_SequenceReg0b4s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B4S2_SequenceReg0b4s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B5S0 - PHY Initialization Engine (PIE) Instruction 5_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B5S0_SequenceReg0b5s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B5S0_SequenceReg0b5s0_SHIFT (0U)
/*! SequenceReg0b5s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B5S0_SequenceReg0b5s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B5S0_SequenceReg0b5s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B5S0_SequenceReg0b5s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B5S1 - PHY Initialization Engine (PIE) Instruction 5_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B5S1_SequenceReg0b5s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B5S1_SequenceReg0b5s1_SHIFT (0U)
/*! SequenceReg0b5s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B5S1_SequenceReg0b5s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B5S1_SequenceReg0b5s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B5S1_SequenceReg0b5s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B5S2 - PHY Initialization Engine (PIE) Instruction 5_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B5S2_SequenceReg0b5s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B5S2_SequenceReg0b5s2_SHIFT (0U)
/*! SequenceReg0b5s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B5S2_SequenceReg0b5s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B5S2_SequenceReg0b5s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B5S2_SequenceReg0b5s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B6S0 - PHY Initialization Engine (PIE) Instruction 6_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B6S0_SequenceReg0b6s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B6S0_SequenceReg0b6s0_SHIFT (0U)
/*! SequenceReg0b6s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B6S0_SequenceReg0b6s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B6S0_SequenceReg0b6s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B6S0_SequenceReg0b6s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B6S1 - PHY Initialization Engine (PIE) Instruction 6_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B6S1_SequenceReg0b6s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B6S1_SequenceReg0b6s1_SHIFT (0U)
/*! SequenceReg0b6s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B6S1_SequenceReg0b6s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B6S1_SequenceReg0b6s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B6S1_SequenceReg0b6s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B6S2 - PHY Initialization Engine (PIE) Instruction 6_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B6S2_SequenceReg0b6s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B6S2_SequenceReg0b6s2_SHIFT (0U)
/*! SequenceReg0b6s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B6S2_SequenceReg0b6s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B6S2_SequenceReg0b6s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B6S2_SequenceReg0b6s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B7S0 - PHY Initialization Engine (PIE) Instruction 7_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B7S0_SequenceReg0b7s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B7S0_SequenceReg0b7s0_SHIFT (0U)
/*! SequenceReg0b7s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B7S0_SequenceReg0b7s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B7S0_SequenceReg0b7s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B7S0_SequenceReg0b7s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B7S1 - PHY Initialization Engine (PIE) Instruction 7_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B7S1_SequenceReg0b7s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B7S1_SequenceReg0b7s1_SHIFT (0U)
/*! SequenceReg0b7s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B7S1_SequenceReg0b7s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B7S1_SequenceReg0b7s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B7S1_SequenceReg0b7s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B7S2 - PHY Initialization Engine (PIE) Instruction 7_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B7S2_SequenceReg0b7s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B7S2_SequenceReg0b7s2_SHIFT (0U)
/*! SequenceReg0b7s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B7S2_SequenceReg0b7s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B7S2_SequenceReg0b7s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B7S2_SequenceReg0b7s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B8S0 - PHY Initialization Engine (PIE) Instruction 8_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B8S0_SequenceReg0b8s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B8S0_SequenceReg0b8s0_SHIFT (0U)
/*! SequenceReg0b8s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B8S0_SequenceReg0b8s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B8S0_SequenceReg0b8s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B8S0_SequenceReg0b8s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B8S1 - PHY Initialization Engine (PIE) Instruction 8_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B8S1_SequenceReg0b8s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B8S1_SequenceReg0b8s1_SHIFT (0U)
/*! SequenceReg0b8s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B8S1_SequenceReg0b8s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B8S1_SequenceReg0b8s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B8S1_SequenceReg0b8s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B8S2 - PHY Initialization Engine (PIE) Instruction 8_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B8S2_SequenceReg0b8s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B8S2_SequenceReg0b8s2_SHIFT (0U)
/*! SequenceReg0b8s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B8S2_SequenceReg0b8s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B8S2_SequenceReg0b8s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B8S2_SequenceReg0b8s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B9S0 - PHY Initialization Engine (PIE) Instruction 9_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B9S0_SequenceReg0b9s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B9S0_SequenceReg0b9s0_SHIFT (0U)
/*! SequenceReg0b9s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B9S0_SequenceReg0b9s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B9S0_SequenceReg0b9s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B9S0_SequenceReg0b9s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B9S1 - PHY Initialization Engine (PIE) Instruction 9_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B9S1_SequenceReg0b9s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B9S1_SequenceReg0b9s1_SHIFT (0U)
/*! SequenceReg0b9s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B9S1_SequenceReg0b9s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B9S1_SequenceReg0b9s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B9S1_SequenceReg0b9s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B9S2 - PHY Initialization Engine (PIE) Instruction 9_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B9S2_SequenceReg0b9s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B9S2_SequenceReg0b9s2_SHIFT (0U)
/*! SequenceReg0b9s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B9S2_SequenceReg0b9s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B9S2_SequenceReg0b9s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B9S2_SequenceReg0b9s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B10S0 - PHY Initialization Engine (PIE) Instruction 10_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B10S0_SequenceReg0b10s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B10S0_SequenceReg0b10s0_SHIFT (0U)
/*! SequenceReg0b10s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B10S0_SequenceReg0b10s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B10S0_SequenceReg0b10s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B10S0_SequenceReg0b10s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B10S1 - PHY Initialization Engine (PIE) Instruction 10_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B10S1_SequenceReg0b10s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B10S1_SequenceReg0b10s1_SHIFT (0U)
/*! SequenceReg0b10s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B10S1_SequenceReg0b10s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B10S1_SequenceReg0b10s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B10S1_SequenceReg0b10s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B10S2 - PHY Initialization Engine (PIE) Instruction 10_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B10S2_SequenceReg0b10s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B10S2_SequenceReg0b10s2_SHIFT (0U)
/*! SequenceReg0b10s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B10S2_SequenceReg0b10s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B10S2_SequenceReg0b10s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B10S2_SequenceReg0b10s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B11S0 - PHY Initialization Engine (PIE) Instruction 11_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B11S0_SequenceReg0b11s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B11S0_SequenceReg0b11s0_SHIFT (0U)
/*! SequenceReg0b11s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B11S0_SequenceReg0b11s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B11S0_SequenceReg0b11s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B11S0_SequenceReg0b11s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B11S1 - PHY Initialization Engine (PIE) Instruction 11_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B11S1_SequenceReg0b11s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B11S1_SequenceReg0b11s1_SHIFT (0U)
/*! SequenceReg0b11s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B11S1_SequenceReg0b11s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B11S1_SequenceReg0b11s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B11S1_SequenceReg0b11s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B11S2 - PHY Initialization Engine (PIE) Instruction 11_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B11S2_SequenceReg0b11s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B11S2_SequenceReg0b11s2_SHIFT (0U)
/*! SequenceReg0b11s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B11S2_SequenceReg0b11s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B11S2_SequenceReg0b11s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B11S2_SequenceReg0b11s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B12S0 - PHY Initialization Engine (PIE) Instruction 12_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B12S0_SequenceReg0b12s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B12S0_SequenceReg0b12s0_SHIFT (0U)
/*! SequenceReg0b12s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B12S0_SequenceReg0b12s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B12S0_SequenceReg0b12s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B12S0_SequenceReg0b12s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B12S1 - PHY Initialization Engine (PIE) Instruction 12_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B12S1_SequenceReg0b12s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B12S1_SequenceReg0b12s1_SHIFT (0U)
/*! SequenceReg0b12s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B12S1_SequenceReg0b12s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B12S1_SequenceReg0b12s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B12S1_SequenceReg0b12s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B12S2 - PHY Initialization Engine (PIE) Instruction 12_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B12S2_SequenceReg0b12s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B12S2_SequenceReg0b12s2_SHIFT (0U)
/*! SequenceReg0b12s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B12S2_SequenceReg0b12s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B12S2_SequenceReg0b12s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B12S2_SequenceReg0b12s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B13S0 - PHY Initialization Engine (PIE) Instruction 13_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B13S0_SequenceReg0b13s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B13S0_SequenceReg0b13s0_SHIFT (0U)
/*! SequenceReg0b13s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B13S0_SequenceReg0b13s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B13S0_SequenceReg0b13s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B13S0_SequenceReg0b13s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B13S1 - PHY Initialization Engine (PIE) Instruction 13_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B13S1_SequenceReg0b13s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B13S1_SequenceReg0b13s1_SHIFT (0U)
/*! SequenceReg0b13s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B13S1_SequenceReg0b13s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B13S1_SequenceReg0b13s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B13S1_SequenceReg0b13s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B13S2 - PHY Initialization Engine (PIE) Instruction 13_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B13S2_SequenceReg0b13s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B13S2_SequenceReg0b13s2_SHIFT (0U)
/*! SequenceReg0b13s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B13S2_SequenceReg0b13s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B13S2_SequenceReg0b13s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B13S2_SequenceReg0b13s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B14S0 - PHY Initialization Engine (PIE) Instruction 14_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B14S0_SequenceReg0b14s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B14S0_SequenceReg0b14s0_SHIFT (0U)
/*! SequenceReg0b14s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B14S0_SequenceReg0b14s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B14S0_SequenceReg0b14s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B14S0_SequenceReg0b14s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B14S1 - PHY Initialization Engine (PIE) Instruction 14_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B14S1_SequenceReg0b14s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B14S1_SequenceReg0b14s1_SHIFT (0U)
/*! SequenceReg0b14s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B14S1_SequenceReg0b14s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B14S1_SequenceReg0b14s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B14S1_SequenceReg0b14s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B14S2 - PHY Initialization Engine (PIE) Instruction 14_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B14S2_SequenceReg0b14s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B14S2_SequenceReg0b14s2_SHIFT (0U)
/*! SequenceReg0b14s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B14S2_SequenceReg0b14s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B14S2_SequenceReg0b14s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B14S2_SequenceReg0b14s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B15S0 - PHY Initialization Engine (PIE) Instruction 15_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B15S0_SequenceReg0b15s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B15S0_SequenceReg0b15s0_SHIFT (0U)
/*! SequenceReg0b15s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B15S0_SequenceReg0b15s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B15S0_SequenceReg0b15s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B15S0_SequenceReg0b15s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B15S1 - PHY Initialization Engine (PIE) Instruction 15_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B15S1_SequenceReg0b15s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B15S1_SequenceReg0b15s1_SHIFT (0U)
/*! SequenceReg0b15s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B15S1_SequenceReg0b15s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B15S1_SequenceReg0b15s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B15S1_SequenceReg0b15s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B15S2 - PHY Initialization Engine (PIE) Instruction 15_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B15S2_SequenceReg0b15s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B15S2_SequenceReg0b15s2_SHIFT (0U)
/*! SequenceReg0b15s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B15S2_SequenceReg0b15s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B15S2_SequenceReg0b15s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B15S2_SequenceReg0b15s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B16S0 - PHY Initialization Engine (PIE) Instruction 16_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B16S0_SequenceReg0b16s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B16S0_SequenceReg0b16s0_SHIFT (0U)
/*! SequenceReg0b16s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B16S0_SequenceReg0b16s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B16S0_SequenceReg0b16s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B16S0_SequenceReg0b16s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B16S1 - PHY Initialization Engine (PIE) Instruction 16_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B16S1_SequenceReg0b16s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B16S1_SequenceReg0b16s1_SHIFT (0U)
/*! SequenceReg0b16s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B16S1_SequenceReg0b16s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B16S1_SequenceReg0b16s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B16S1_SequenceReg0b16s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B16S2 - PHY Initialization Engine (PIE) Instruction 16_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B16S2_SequenceReg0b16s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B16S2_SequenceReg0b16s2_SHIFT (0U)
/*! SequenceReg0b16s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B16S2_SequenceReg0b16s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B16S2_SequenceReg0b16s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B16S2_SequenceReg0b16s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B17S0 - PHY Initialization Engine (PIE) Instruction 17_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B17S0_SequenceReg0b17s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B17S0_SequenceReg0b17s0_SHIFT (0U)
/*! SequenceReg0b17s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B17S0_SequenceReg0b17s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B17S0_SequenceReg0b17s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B17S0_SequenceReg0b17s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B17S1 - PHY Initialization Engine (PIE) Instruction 17_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B17S1_SequenceReg0b17s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B17S1_SequenceReg0b17s1_SHIFT (0U)
/*! SequenceReg0b17s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B17S1_SequenceReg0b17s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B17S1_SequenceReg0b17s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B17S1_SequenceReg0b17s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B17S2 - PHY Initialization Engine (PIE) Instruction 17_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B17S2_SequenceReg0b17s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B17S2_SequenceReg0b17s2_SHIFT (0U)
/*! SequenceReg0b17s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B17S2_SequenceReg0b17s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B17S2_SequenceReg0b17s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B17S2_SequenceReg0b17s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B18S0 - PHY Initialization Engine (PIE) Instruction 18_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B18S0_SequenceReg0b18s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B18S0_SequenceReg0b18s0_SHIFT (0U)
/*! SequenceReg0b18s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B18S0_SequenceReg0b18s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B18S0_SequenceReg0b18s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B18S0_SequenceReg0b18s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B18S1 - PHY Initialization Engine (PIE) Instruction 18_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B18S1_SequenceReg0b18s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B18S1_SequenceReg0b18s1_SHIFT (0U)
/*! SequenceReg0b18s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B18S1_SequenceReg0b18s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B18S1_SequenceReg0b18s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B18S1_SequenceReg0b18s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B18S2 - PHY Initialization Engine (PIE) Instruction 18_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B18S2_SequenceReg0b18s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B18S2_SequenceReg0b18s2_SHIFT (0U)
/*! SequenceReg0b18s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B18S2_SequenceReg0b18s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B18S2_SequenceReg0b18s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B18S2_SequenceReg0b18s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B19S0 - PHY Initialization Engine (PIE) Instruction 19_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B19S0_SequenceReg0b19s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B19S0_SequenceReg0b19s0_SHIFT (0U)
/*! SequenceReg0b19s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B19S0_SequenceReg0b19s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B19S0_SequenceReg0b19s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B19S0_SequenceReg0b19s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B19S1 - PHY Initialization Engine (PIE) Instruction 19_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B19S1_SequenceReg0b19s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B19S1_SequenceReg0b19s1_SHIFT (0U)
/*! SequenceReg0b19s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B19S1_SequenceReg0b19s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B19S1_SequenceReg0b19s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B19S1_SequenceReg0b19s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B19S2 - PHY Initialization Engine (PIE) Instruction 19_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B19S2_SequenceReg0b19s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B19S2_SequenceReg0b19s2_SHIFT (0U)
/*! SequenceReg0b19s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B19S2_SequenceReg0b19s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B19S2_SequenceReg0b19s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B19S2_SequenceReg0b19s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B20S0 - PHY Initialization Engine (PIE) Instruction 20_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B20S0_SequenceReg0b20s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B20S0_SequenceReg0b20s0_SHIFT (0U)
/*! SequenceReg0b20s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B20S0_SequenceReg0b20s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B20S0_SequenceReg0b20s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B20S0_SequenceReg0b20s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B20S1 - PHY Initialization Engine (PIE) Instruction 20_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B20S1_SequenceReg0b20s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B20S1_SequenceReg0b20s1_SHIFT (0U)
/*! SequenceReg0b20s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B20S1_SequenceReg0b20s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B20S1_SequenceReg0b20s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B20S1_SequenceReg0b20s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B20S2 - PHY Initialization Engine (PIE) Instruction 20_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B20S2_SequenceReg0b20s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B20S2_SequenceReg0b20s2_SHIFT (0U)
/*! SequenceReg0b20s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B20S2_SequenceReg0b20s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B20S2_SequenceReg0b20s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B20S2_SequenceReg0b20s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B21S0 - PHY Initialization Engine (PIE) Instruction 21_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B21S0_SequenceReg0b21s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B21S0_SequenceReg0b21s0_SHIFT (0U)
/*! SequenceReg0b21s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B21S0_SequenceReg0b21s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B21S0_SequenceReg0b21s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B21S0_SequenceReg0b21s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B21S1 - PHY Initialization Engine (PIE) Instruction 21_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B21S1_SequenceReg0b21s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B21S1_SequenceReg0b21s1_SHIFT (0U)
/*! SequenceReg0b21s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B21S1_SequenceReg0b21s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B21S1_SequenceReg0b21s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B21S1_SequenceReg0b21s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B21S2 - PHY Initialization Engine (PIE) Instruction 21_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B21S2_SequenceReg0b21s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B21S2_SequenceReg0b21s2_SHIFT (0U)
/*! SequenceReg0b21s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B21S2_SequenceReg0b21s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B21S2_SequenceReg0b21s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B21S2_SequenceReg0b21s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B22S0 - PHY Initialization Engine (PIE) Instruction 22_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B22S0_SequenceReg0b22s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B22S0_SequenceReg0b22s0_SHIFT (0U)
/*! SequenceReg0b22s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B22S0_SequenceReg0b22s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B22S0_SequenceReg0b22s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B22S0_SequenceReg0b22s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B22S1 - PHY Initialization Engine (PIE) Instruction 22_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B22S1_SequenceReg0b22s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B22S1_SequenceReg0b22s1_SHIFT (0U)
/*! SequenceReg0b22s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B22S1_SequenceReg0b22s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B22S1_SequenceReg0b22s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B22S1_SequenceReg0b22s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B22S2 - PHY Initialization Engine (PIE) Instruction 22_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B22S2_SequenceReg0b22s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B22S2_SequenceReg0b22s2_SHIFT (0U)
/*! SequenceReg0b22s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B22S2_SequenceReg0b22s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B22S2_SequenceReg0b22s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B22S2_SequenceReg0b22s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B23S0 - PHY Initialization Engine (PIE) Instruction 23_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B23S0_SequenceReg0b23s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B23S0_SequenceReg0b23s0_SHIFT (0U)
/*! SequenceReg0b23s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B23S0_SequenceReg0b23s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B23S0_SequenceReg0b23s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B23S0_SequenceReg0b23s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B23S1 - PHY Initialization Engine (PIE) Instruction 23_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B23S1_SequenceReg0b23s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B23S1_SequenceReg0b23s1_SHIFT (0U)
/*! SequenceReg0b23s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B23S1_SequenceReg0b23s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B23S1_SequenceReg0b23s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B23S1_SequenceReg0b23s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B23S2 - PHY Initialization Engine (PIE) Instruction 23_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B23S2_SequenceReg0b23s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B23S2_SequenceReg0b23s2_SHIFT (0U)
/*! SequenceReg0b23s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B23S2_SequenceReg0b23s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B23S2_SequenceReg0b23s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B23S2_SequenceReg0b23s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B24S0 - PHY Initialization Engine (PIE) Instruction 24_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B24S0_SequenceReg0b24s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B24S0_SequenceReg0b24s0_SHIFT (0U)
/*! SequenceReg0b24s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B24S0_SequenceReg0b24s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B24S0_SequenceReg0b24s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B24S0_SequenceReg0b24s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B24S1 - PHY Initialization Engine (PIE) Instruction 24_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B24S1_SequenceReg0b24s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B24S1_SequenceReg0b24s1_SHIFT (0U)
/*! SequenceReg0b24s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B24S1_SequenceReg0b24s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B24S1_SequenceReg0b24s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B24S1_SequenceReg0b24s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B24S2 - PHY Initialization Engine (PIE) Instruction 24_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B24S2_SequenceReg0b24s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B24S2_SequenceReg0b24s2_SHIFT (0U)
/*! SequenceReg0b24s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B24S2_SequenceReg0b24s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B24S2_SequenceReg0b24s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B24S2_SequenceReg0b24s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B25S0 - PHY Initialization Engine (PIE) Instruction 25_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B25S0_SequenceReg0b25s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B25S0_SequenceReg0b25s0_SHIFT (0U)
/*! SequenceReg0b25s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B25S0_SequenceReg0b25s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B25S0_SequenceReg0b25s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B25S0_SequenceReg0b25s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B25S1 - PHY Initialization Engine (PIE) Instruction 25_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B25S1_SequenceReg0b25s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B25S1_SequenceReg0b25s1_SHIFT (0U)
/*! SequenceReg0b25s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B25S1_SequenceReg0b25s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B25S1_SequenceReg0b25s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B25S1_SequenceReg0b25s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B25S2 - PHY Initialization Engine (PIE) Instruction 25_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B25S2_SequenceReg0b25s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B25S2_SequenceReg0b25s2_SHIFT (0U)
/*! SequenceReg0b25s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B25S2_SequenceReg0b25s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B25S2_SequenceReg0b25s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B25S2_SequenceReg0b25s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B26S0 - PHY Initialization Engine (PIE) Instruction 26_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B26S0_SequenceReg0b26s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B26S0_SequenceReg0b26s0_SHIFT (0U)
/*! SequenceReg0b26s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B26S0_SequenceReg0b26s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B26S0_SequenceReg0b26s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B26S0_SequenceReg0b26s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B26S1 - PHY Initialization Engine (PIE) Instruction 26_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B26S1_SequenceReg0b26s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B26S1_SequenceReg0b26s1_SHIFT (0U)
/*! SequenceReg0b26s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B26S1_SequenceReg0b26s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B26S1_SequenceReg0b26s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B26S1_SequenceReg0b26s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B26S2 - PHY Initialization Engine (PIE) Instruction 26_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B26S2_SequenceReg0b26s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B26S2_SequenceReg0b26s2_SHIFT (0U)
/*! SequenceReg0b26s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B26S2_SequenceReg0b26s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B26S2_SequenceReg0b26s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B26S2_SequenceReg0b26s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B27S0 - PHY Initialization Engine (PIE) Instruction 27_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B27S0_SequenceReg0b27s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B27S0_SequenceReg0b27s0_SHIFT (0U)
/*! SequenceReg0b27s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B27S0_SequenceReg0b27s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B27S0_SequenceReg0b27s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B27S0_SequenceReg0b27s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B27S1 - PHY Initialization Engine (PIE) Instruction 27_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B27S1_SequenceReg0b27s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B27S1_SequenceReg0b27s1_SHIFT (0U)
/*! SequenceReg0b27s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B27S1_SequenceReg0b27s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B27S1_SequenceReg0b27s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B27S1_SequenceReg0b27s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B27S2 - PHY Initialization Engine (PIE) Instruction 27_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B27S2_SequenceReg0b27s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B27S2_SequenceReg0b27s2_SHIFT (0U)
/*! SequenceReg0b27s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B27S2_SequenceReg0b27s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B27S2_SequenceReg0b27s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B27S2_SequenceReg0b27s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B28S0 - PHY Initialization Engine (PIE) Instruction 28_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B28S0_SequenceReg0b28s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B28S0_SequenceReg0b28s0_SHIFT (0U)
/*! SequenceReg0b28s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B28S0_SequenceReg0b28s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B28S0_SequenceReg0b28s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B28S0_SequenceReg0b28s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B28S1 - PHY Initialization Engine (PIE) Instruction 28_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B28S1_SequenceReg0b28s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B28S1_SequenceReg0b28s1_SHIFT (0U)
/*! SequenceReg0b28s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B28S1_SequenceReg0b28s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B28S1_SequenceReg0b28s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B28S1_SequenceReg0b28s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B28S2 - PHY Initialization Engine (PIE) Instruction 28_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B28S2_SequenceReg0b28s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B28S2_SequenceReg0b28s2_SHIFT (0U)
/*! SequenceReg0b28s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B28S2_SequenceReg0b28s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B28S2_SequenceReg0b28s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B28S2_SequenceReg0b28s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B29S0 - PHY Initialization Engine (PIE) Instruction 29_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B29S0_SequenceReg0b29s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B29S0_SequenceReg0b29s0_SHIFT (0U)
/*! SequenceReg0b29s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B29S0_SequenceReg0b29s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B29S0_SequenceReg0b29s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B29S0_SequenceReg0b29s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B29S1 - PHY Initialization Engine (PIE) Instruction 29_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B29S1_SequenceReg0b29s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B29S1_SequenceReg0b29s1_SHIFT (0U)
/*! SequenceReg0b29s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B29S1_SequenceReg0b29s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B29S1_SequenceReg0b29s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B29S1_SequenceReg0b29s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B29S2 - PHY Initialization Engine (PIE) Instruction 29_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B29S2_SequenceReg0b29s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B29S2_SequenceReg0b29s2_SHIFT (0U)
/*! SequenceReg0b29s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B29S2_SequenceReg0b29s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B29S2_SequenceReg0b29s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B29S2_SequenceReg0b29s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B30S0 - PHY Initialization Engine (PIE) Instruction 30_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B30S0_SequenceReg0b30s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B30S0_SequenceReg0b30s0_SHIFT (0U)
/*! SequenceReg0b30s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B30S0_SequenceReg0b30s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B30S0_SequenceReg0b30s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B30S0_SequenceReg0b30s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B30S1 - PHY Initialization Engine (PIE) Instruction 30_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B30S1_SequenceReg0b30s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B30S1_SequenceReg0b30s1_SHIFT (0U)
/*! SequenceReg0b30s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B30S1_SequenceReg0b30s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B30S1_SequenceReg0b30s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B30S1_SequenceReg0b30s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B30S2 - PHY Initialization Engine (PIE) Instruction 30_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B30S2_SequenceReg0b30s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B30S2_SequenceReg0b30s2_SHIFT (0U)
/*! SequenceReg0b30s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B30S2_SequenceReg0b30s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B30S2_SequenceReg0b30s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B30S2_SequenceReg0b30s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B31S0 - PHY Initialization Engine (PIE) Instruction 31_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B31S0_SequenceReg0b31s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B31S0_SequenceReg0b31s0_SHIFT (0U)
/*! SequenceReg0b31s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B31S0_SequenceReg0b31s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B31S0_SequenceReg0b31s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B31S0_SequenceReg0b31s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B31S1 - PHY Initialization Engine (PIE) Instruction 31_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B31S1_SequenceReg0b31s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B31S1_SequenceReg0b31s1_SHIFT (0U)
/*! SequenceReg0b31s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B31S1_SequenceReg0b31s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B31S1_SequenceReg0b31s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B31S1_SequenceReg0b31s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B31S2 - PHY Initialization Engine (PIE) Instruction 31_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B31S2_SequenceReg0b31s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B31S2_SequenceReg0b31s2_SHIFT (0U)
/*! SequenceReg0b31s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B31S2_SequenceReg0b31s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B31S2_SequenceReg0b31s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B31S2_SequenceReg0b31s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B32S0 - PHY Initialization Engine (PIE) Instruction 32_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B32S0_SequenceReg0b32s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B32S0_SequenceReg0b32s0_SHIFT (0U)
/*! SequenceReg0b32s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B32S0_SequenceReg0b32s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B32S0_SequenceReg0b32s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B32S0_SequenceReg0b32s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B32S1 - PHY Initialization Engine (PIE) Instruction 32_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B32S1_SequenceReg0b32s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B32S1_SequenceReg0b32s1_SHIFT (0U)
/*! SequenceReg0b32s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B32S1_SequenceReg0b32s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B32S1_SequenceReg0b32s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B32S1_SequenceReg0b32s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B32S2 - PHY Initialization Engine (PIE) Instruction 32_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B32S2_SequenceReg0b32s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B32S2_SequenceReg0b32s2_SHIFT (0U)
/*! SequenceReg0b32s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B32S2_SequenceReg0b32s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B32S2_SequenceReg0b32s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B32S2_SequenceReg0b32s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B33S0 - PHY Initialization Engine (PIE) Instruction 33_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B33S0_SequenceReg0b33s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B33S0_SequenceReg0b33s0_SHIFT (0U)
/*! SequenceReg0b33s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B33S0_SequenceReg0b33s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B33S0_SequenceReg0b33s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B33S0_SequenceReg0b33s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B33S1 - PHY Initialization Engine (PIE) Instruction 33_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B33S1_SequenceReg0b33s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B33S1_SequenceReg0b33s1_SHIFT (0U)
/*! SequenceReg0b33s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B33S1_SequenceReg0b33s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B33S1_SequenceReg0b33s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B33S1_SequenceReg0b33s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B33S2 - PHY Initialization Engine (PIE) Instruction 33_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B33S2_SequenceReg0b33s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B33S2_SequenceReg0b33s2_SHIFT (0U)
/*! SequenceReg0b33s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B33S2_SequenceReg0b33s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B33S2_SequenceReg0b33s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B33S2_SequenceReg0b33s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B34S0 - PHY Initialization Engine (PIE) Instruction 34_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B34S0_SequenceReg0b34s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B34S0_SequenceReg0b34s0_SHIFT (0U)
/*! SequenceReg0b34s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B34S0_SequenceReg0b34s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B34S0_SequenceReg0b34s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B34S0_SequenceReg0b34s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B34S1 - PHY Initialization Engine (PIE) Instruction 34_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B34S1_SequenceReg0b34s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B34S1_SequenceReg0b34s1_SHIFT (0U)
/*! SequenceReg0b34s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B34S1_SequenceReg0b34s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B34S1_SequenceReg0b34s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B34S1_SequenceReg0b34s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B34S2 - PHY Initialization Engine (PIE) Instruction 34_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B34S2_SequenceReg0b34s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B34S2_SequenceReg0b34s2_SHIFT (0U)
/*! SequenceReg0b34s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B34S2_SequenceReg0b34s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B34S2_SequenceReg0b34s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B34S2_SequenceReg0b34s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B35S0 - PHY Initialization Engine (PIE) Instruction 35_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B35S0_SequenceReg0b35s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B35S0_SequenceReg0b35s0_SHIFT (0U)
/*! SequenceReg0b35s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B35S0_SequenceReg0b35s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B35S0_SequenceReg0b35s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B35S0_SequenceReg0b35s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B35S1 - PHY Initialization Engine (PIE) Instruction 35_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B35S1_SequenceReg0b35s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B35S1_SequenceReg0b35s1_SHIFT (0U)
/*! SequenceReg0b35s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B35S1_SequenceReg0b35s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B35S1_SequenceReg0b35s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B35S1_SequenceReg0b35s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B35S2 - PHY Initialization Engine (PIE) Instruction 35_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B35S2_SequenceReg0b35s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B35S2_SequenceReg0b35s2_SHIFT (0U)
/*! SequenceReg0b35s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B35S2_SequenceReg0b35s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B35S2_SequenceReg0b35s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B35S2_SequenceReg0b35s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B36S0 - PHY Initialization Engine (PIE) Instruction 36_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B36S0_SequenceReg0b36s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B36S0_SequenceReg0b36s0_SHIFT (0U)
/*! SequenceReg0b36s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B36S0_SequenceReg0b36s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B36S0_SequenceReg0b36s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B36S0_SequenceReg0b36s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B36S1 - PHY Initialization Engine (PIE) Instruction 36_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B36S1_SequenceReg0b36s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B36S1_SequenceReg0b36s1_SHIFT (0U)
/*! SequenceReg0b36s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B36S1_SequenceReg0b36s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B36S1_SequenceReg0b36s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B36S1_SequenceReg0b36s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B36S2 - PHY Initialization Engine (PIE) Instruction 36_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B36S2_SequenceReg0b36s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B36S2_SequenceReg0b36s2_SHIFT (0U)
/*! SequenceReg0b36s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B36S2_SequenceReg0b36s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B36S2_SequenceReg0b36s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B36S2_SequenceReg0b36s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B37S0 - PHY Initialization Engine (PIE) Instruction 37_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B37S0_SequenceReg0b37s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B37S0_SequenceReg0b37s0_SHIFT (0U)
/*! SequenceReg0b37s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B37S0_SequenceReg0b37s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B37S0_SequenceReg0b37s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B37S0_SequenceReg0b37s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B37S1 - PHY Initialization Engine (PIE) Instruction 37_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B37S1_SequenceReg0b37s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B37S1_SequenceReg0b37s1_SHIFT (0U)
/*! SequenceReg0b37s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B37S1_SequenceReg0b37s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B37S1_SequenceReg0b37s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B37S1_SequenceReg0b37s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B37S2 - PHY Initialization Engine (PIE) Instruction 37_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B37S2_SequenceReg0b37s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B37S2_SequenceReg0b37s2_SHIFT (0U)
/*! SequenceReg0b37s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B37S2_SequenceReg0b37s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B37S2_SequenceReg0b37s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B37S2_SequenceReg0b37s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B38S0 - PHY Initialization Engine (PIE) Instruction 38_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B38S0_SequenceReg0b38s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B38S0_SequenceReg0b38s0_SHIFT (0U)
/*! SequenceReg0b38s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B38S0_SequenceReg0b38s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B38S0_SequenceReg0b38s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B38S0_SequenceReg0b38s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B38S1 - PHY Initialization Engine (PIE) Instruction 38_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B38S1_SequenceReg0b38s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B38S1_SequenceReg0b38s1_SHIFT (0U)
/*! SequenceReg0b38s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B38S1_SequenceReg0b38s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B38S1_SequenceReg0b38s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B38S1_SequenceReg0b38s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B38S2 - PHY Initialization Engine (PIE) Instruction 38_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B38S2_SequenceReg0b38s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B38S2_SequenceReg0b38s2_SHIFT (0U)
/*! SequenceReg0b38s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B38S2_SequenceReg0b38s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B38S2_SequenceReg0b38s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B38S2_SequenceReg0b38s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B39S0 - PHY Initialization Engine (PIE) Instruction 39_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B39S0_SequenceReg0b39s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B39S0_SequenceReg0b39s0_SHIFT (0U)
/*! SequenceReg0b39s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B39S0_SequenceReg0b39s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B39S0_SequenceReg0b39s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B39S0_SequenceReg0b39s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B39S1 - PHY Initialization Engine (PIE) Instruction 39_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B39S1_SequenceReg0b39s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B39S1_SequenceReg0b39s1_SHIFT (0U)
/*! SequenceReg0b39s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B39S1_SequenceReg0b39s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B39S1_SequenceReg0b39s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B39S1_SequenceReg0b39s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B39S2 - PHY Initialization Engine (PIE) Instruction 39_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B39S2_SequenceReg0b39s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B39S2_SequenceReg0b39s2_SHIFT (0U)
/*! SequenceReg0b39s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B39S2_SequenceReg0b39s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B39S2_SequenceReg0b39s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B39S2_SequenceReg0b39s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B40S0 - PHY Initialization Engine (PIE) Instruction 40_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B40S0_SequenceReg0b40s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B40S0_SequenceReg0b40s0_SHIFT (0U)
/*! SequenceReg0b40s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B40S0_SequenceReg0b40s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B40S0_SequenceReg0b40s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B40S0_SequenceReg0b40s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B40S1 - PHY Initialization Engine (PIE) Instruction 40_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B40S1_SequenceReg0b40s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B40S1_SequenceReg0b40s1_SHIFT (0U)
/*! SequenceReg0b40s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B40S1_SequenceReg0b40s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B40S1_SequenceReg0b40s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B40S1_SequenceReg0b40s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B40S2 - PHY Initialization Engine (PIE) Instruction 40_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B40S2_SequenceReg0b40s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B40S2_SequenceReg0b40s2_SHIFT (0U)
/*! SequenceReg0b40s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B40S2_SequenceReg0b40s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B40S2_SequenceReg0b40s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B40S2_SequenceReg0b40s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B41S0 - PHY Initialization Engine (PIE) Instruction 41_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B41S0_SequenceReg0b41s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B41S0_SequenceReg0b41s0_SHIFT (0U)
/*! SequenceReg0b41s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B41S0_SequenceReg0b41s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B41S0_SequenceReg0b41s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B41S0_SequenceReg0b41s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B41S1 - PHY Initialization Engine (PIE) Instruction 41_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B41S1_SequenceReg0b41s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B41S1_SequenceReg0b41s1_SHIFT (0U)
/*! SequenceReg0b41s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B41S1_SequenceReg0b41s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B41S1_SequenceReg0b41s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B41S1_SequenceReg0b41s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B41S2 - PHY Initialization Engine (PIE) Instruction 41_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B41S2_SequenceReg0b41s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B41S2_SequenceReg0b41s2_SHIFT (0U)
/*! SequenceReg0b41s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B41S2_SequenceReg0b41s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B41S2_SequenceReg0b41s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B41S2_SequenceReg0b41s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B42S0 - PHY Initialization Engine (PIE) Instruction 42_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B42S0_SequenceReg0b42s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B42S0_SequenceReg0b42s0_SHIFT (0U)
/*! SequenceReg0b42s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B42S0_SequenceReg0b42s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B42S0_SequenceReg0b42s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B42S0_SequenceReg0b42s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B42S1 - PHY Initialization Engine (PIE) Instruction 42_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B42S1_SequenceReg0b42s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B42S1_SequenceReg0b42s1_SHIFT (0U)
/*! SequenceReg0b42s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B42S1_SequenceReg0b42s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B42S1_SequenceReg0b42s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B42S1_SequenceReg0b42s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B42S2 - PHY Initialization Engine (PIE) Instruction 42_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B42S2_SequenceReg0b42s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B42S2_SequenceReg0b42s2_SHIFT (0U)
/*! SequenceReg0b42s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B42S2_SequenceReg0b42s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B42S2_SequenceReg0b42s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B42S2_SequenceReg0b42s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B43S0 - PHY Initialization Engine (PIE) Instruction 43_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B43S0_SequenceReg0b43s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B43S0_SequenceReg0b43s0_SHIFT (0U)
/*! SequenceReg0b43s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B43S0_SequenceReg0b43s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B43S0_SequenceReg0b43s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B43S0_SequenceReg0b43s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B43S1 - PHY Initialization Engine (PIE) Instruction 43_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B43S1_SequenceReg0b43s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B43S1_SequenceReg0b43s1_SHIFT (0U)
/*! SequenceReg0b43s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B43S1_SequenceReg0b43s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B43S1_SequenceReg0b43s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B43S1_SequenceReg0b43s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B43S2 - PHY Initialization Engine (PIE) Instruction 43_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B43S2_SequenceReg0b43s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B43S2_SequenceReg0b43s2_SHIFT (0U)
/*! SequenceReg0b43s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B43S2_SequenceReg0b43s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B43S2_SequenceReg0b43s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B43S2_SequenceReg0b43s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B44S0 - PHY Initialization Engine (PIE) Instruction 44_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B44S0_SequenceReg0b44s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B44S0_SequenceReg0b44s0_SHIFT (0U)
/*! SequenceReg0b44s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B44S0_SequenceReg0b44s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B44S0_SequenceReg0b44s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B44S0_SequenceReg0b44s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B44S1 - PHY Initialization Engine (PIE) Instruction 44_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B44S1_SequenceReg0b44s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B44S1_SequenceReg0b44s1_SHIFT (0U)
/*! SequenceReg0b44s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B44S1_SequenceReg0b44s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B44S1_SequenceReg0b44s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B44S1_SequenceReg0b44s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B44S2 - PHY Initialization Engine (PIE) Instruction 44_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B44S2_SequenceReg0b44s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B44S2_SequenceReg0b44s2_SHIFT (0U)
/*! SequenceReg0b44s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B44S2_SequenceReg0b44s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B44S2_SequenceReg0b44s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B44S2_SequenceReg0b44s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B45S0 - PHY Initialization Engine (PIE) Instruction 45_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B45S0_SequenceReg0b45s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B45S0_SequenceReg0b45s0_SHIFT (0U)
/*! SequenceReg0b45s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B45S0_SequenceReg0b45s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B45S0_SequenceReg0b45s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B45S0_SequenceReg0b45s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B45S1 - PHY Initialization Engine (PIE) Instruction 45_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B45S1_SequenceReg0b45s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B45S1_SequenceReg0b45s1_SHIFT (0U)
/*! SequenceReg0b45s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B45S1_SequenceReg0b45s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B45S1_SequenceReg0b45s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B45S1_SequenceReg0b45s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B45S2 - PHY Initialization Engine (PIE) Instruction 45_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B45S2_SequenceReg0b45s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B45S2_SequenceReg0b45s2_SHIFT (0U)
/*! SequenceReg0b45s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B45S2_SequenceReg0b45s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B45S2_SequenceReg0b45s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B45S2_SequenceReg0b45s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B46S0 - PHY Initialization Engine (PIE) Instruction 46_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B46S0_SequenceReg0b46s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B46S0_SequenceReg0b46s0_SHIFT (0U)
/*! SequenceReg0b46s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B46S0_SequenceReg0b46s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B46S0_SequenceReg0b46s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B46S0_SequenceReg0b46s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B46S1 - PHY Initialization Engine (PIE) Instruction 46_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B46S1_SequenceReg0b46s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B46S1_SequenceReg0b46s1_SHIFT (0U)
/*! SequenceReg0b46s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B46S1_SequenceReg0b46s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B46S1_SequenceReg0b46s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B46S1_SequenceReg0b46s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B46S2 - PHY Initialization Engine (PIE) Instruction 46_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B46S2_SequenceReg0b46s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B46S2_SequenceReg0b46s2_SHIFT (0U)
/*! SequenceReg0b46s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B46S2_SequenceReg0b46s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B46S2_SequenceReg0b46s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B46S2_SequenceReg0b46s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B47S0 - PHY Initialization Engine (PIE) Instruction 47_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B47S0_SequenceReg0b47s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B47S0_SequenceReg0b47s0_SHIFT (0U)
/*! SequenceReg0b47s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B47S0_SequenceReg0b47s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B47S0_SequenceReg0b47s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B47S0_SequenceReg0b47s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B47S1 - PHY Initialization Engine (PIE) Instruction 47_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B47S1_SequenceReg0b47s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B47S1_SequenceReg0b47s1_SHIFT (0U)
/*! SequenceReg0b47s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B47S1_SequenceReg0b47s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B47S1_SequenceReg0b47s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B47S1_SequenceReg0b47s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B47S2 - PHY Initialization Engine (PIE) Instruction 47_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B47S2_SequenceReg0b47s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B47S2_SequenceReg0b47s2_SHIFT (0U)
/*! SequenceReg0b47s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B47S2_SequenceReg0b47s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B47S2_SequenceReg0b47s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B47S2_SequenceReg0b47s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B48S0 - PHY Initialization Engine (PIE) Instruction 48_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B48S0_SequenceReg0b48s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B48S0_SequenceReg0b48s0_SHIFT (0U)
/*! SequenceReg0b48s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B48S0_SequenceReg0b48s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B48S0_SequenceReg0b48s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B48S0_SequenceReg0b48s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B48S1 - PHY Initialization Engine (PIE) Instruction 48_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B48S1_SequenceReg0b48s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B48S1_SequenceReg0b48s1_SHIFT (0U)
/*! SequenceReg0b48s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B48S1_SequenceReg0b48s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B48S1_SequenceReg0b48s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B48S1_SequenceReg0b48s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B48S2 - PHY Initialization Engine (PIE) Instruction 48_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B48S2_SequenceReg0b48s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B48S2_SequenceReg0b48s2_SHIFT (0U)
/*! SequenceReg0b48s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B48S2_SequenceReg0b48s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B48S2_SequenceReg0b48s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B48S2_SequenceReg0b48s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B49S0 - PHY Initialization Engine (PIE) Instruction 49_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B49S0_SequenceReg0b49s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B49S0_SequenceReg0b49s0_SHIFT (0U)
/*! SequenceReg0b49s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B49S0_SequenceReg0b49s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B49S0_SequenceReg0b49s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B49S0_SequenceReg0b49s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B49S1 - PHY Initialization Engine (PIE) Instruction 49_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B49S1_SequenceReg0b49s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B49S1_SequenceReg0b49s1_SHIFT (0U)
/*! SequenceReg0b49s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B49S1_SequenceReg0b49s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B49S1_SequenceReg0b49s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B49S1_SequenceReg0b49s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B49S2 - PHY Initialization Engine (PIE) Instruction 49_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B49S2_SequenceReg0b49s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B49S2_SequenceReg0b49s2_SHIFT (0U)
/*! SequenceReg0b49s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B49S2_SequenceReg0b49s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B49S2_SequenceReg0b49s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B49S2_SequenceReg0b49s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B50S0 - PHY Initialization Engine (PIE) Instruction 50_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B50S0_SequenceReg0b50s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B50S0_SequenceReg0b50s0_SHIFT (0U)
/*! SequenceReg0b50s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B50S0_SequenceReg0b50s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B50S0_SequenceReg0b50s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B50S0_SequenceReg0b50s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B50S1 - PHY Initialization Engine (PIE) Instruction 50_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B50S1_SequenceReg0b50s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B50S1_SequenceReg0b50s1_SHIFT (0U)
/*! SequenceReg0b50s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B50S1_SequenceReg0b50s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B50S1_SequenceReg0b50s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B50S1_SequenceReg0b50s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B50S2 - PHY Initialization Engine (PIE) Instruction 50_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B50S2_SequenceReg0b50s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B50S2_SequenceReg0b50s2_SHIFT (0U)
/*! SequenceReg0b50s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B50S2_SequenceReg0b50s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B50S2_SequenceReg0b50s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B50S2_SequenceReg0b50s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B51S0 - PHY Initialization Engine (PIE) Instruction 51_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B51S0_SequenceReg0b51s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B51S0_SequenceReg0b51s0_SHIFT (0U)
/*! SequenceReg0b51s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B51S0_SequenceReg0b51s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B51S0_SequenceReg0b51s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B51S0_SequenceReg0b51s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B51S1 - PHY Initialization Engine (PIE) Instruction 51_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B51S1_SequenceReg0b51s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B51S1_SequenceReg0b51s1_SHIFT (0U)
/*! SequenceReg0b51s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B51S1_SequenceReg0b51s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B51S1_SequenceReg0b51s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B51S1_SequenceReg0b51s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B51S2 - PHY Initialization Engine (PIE) Instruction 51_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B51S2_SequenceReg0b51s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B51S2_SequenceReg0b51s2_SHIFT (0U)
/*! SequenceReg0b51s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B51S2_SequenceReg0b51s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B51S2_SequenceReg0b51s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B51S2_SequenceReg0b51s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B52S0 - PHY Initialization Engine (PIE) Instruction 52_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B52S0_SequenceReg0b52s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B52S0_SequenceReg0b52s0_SHIFT (0U)
/*! SequenceReg0b52s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B52S0_SequenceReg0b52s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B52S0_SequenceReg0b52s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B52S0_SequenceReg0b52s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B52S1 - PHY Initialization Engine (PIE) Instruction 52_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B52S1_SequenceReg0b52s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B52S1_SequenceReg0b52s1_SHIFT (0U)
/*! SequenceReg0b52s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B52S1_SequenceReg0b52s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B52S1_SequenceReg0b52s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B52S1_SequenceReg0b52s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B52S2 - PHY Initialization Engine (PIE) Instruction 52_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B52S2_SequenceReg0b52s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B52S2_SequenceReg0b52s2_SHIFT (0U)
/*! SequenceReg0b52s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B52S2_SequenceReg0b52s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B52S2_SequenceReg0b52s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B52S2_SequenceReg0b52s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B53S0 - PHY Initialization Engine (PIE) Instruction 53_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B53S0_SequenceReg0b53s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B53S0_SequenceReg0b53s0_SHIFT (0U)
/*! SequenceReg0b53s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B53S0_SequenceReg0b53s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B53S0_SequenceReg0b53s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B53S0_SequenceReg0b53s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B53S1 - PHY Initialization Engine (PIE) Instruction 53_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B53S1_SequenceReg0b53s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B53S1_SequenceReg0b53s1_SHIFT (0U)
/*! SequenceReg0b53s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B53S1_SequenceReg0b53s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B53S1_SequenceReg0b53s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B53S1_SequenceReg0b53s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B53S2 - PHY Initialization Engine (PIE) Instruction 53_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B53S2_SequenceReg0b53s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B53S2_SequenceReg0b53s2_SHIFT (0U)
/*! SequenceReg0b53s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B53S2_SequenceReg0b53s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B53S2_SequenceReg0b53s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B53S2_SequenceReg0b53s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B54S0 - PHY Initialization Engine (PIE) Instruction 54_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B54S0_SequenceReg0b54s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B54S0_SequenceReg0b54s0_SHIFT (0U)
/*! SequenceReg0b54s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B54S0_SequenceReg0b54s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B54S0_SequenceReg0b54s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B54S0_SequenceReg0b54s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B54S1 - PHY Initialization Engine (PIE) Instruction 54_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B54S1_SequenceReg0b54s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B54S1_SequenceReg0b54s1_SHIFT (0U)
/*! SequenceReg0b54s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B54S1_SequenceReg0b54s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B54S1_SequenceReg0b54s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B54S1_SequenceReg0b54s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B54S2 - PHY Initialization Engine (PIE) Instruction 54_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B54S2_SequenceReg0b54s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B54S2_SequenceReg0b54s2_SHIFT (0U)
/*! SequenceReg0b54s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B54S2_SequenceReg0b54s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B54S2_SequenceReg0b54s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B54S2_SequenceReg0b54s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B55S0 - PHY Initialization Engine (PIE) Instruction 55_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B55S0_SequenceReg0b55s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B55S0_SequenceReg0b55s0_SHIFT (0U)
/*! SequenceReg0b55s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B55S0_SequenceReg0b55s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B55S0_SequenceReg0b55s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B55S0_SequenceReg0b55s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B55S1 - PHY Initialization Engine (PIE) Instruction 55_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B55S1_SequenceReg0b55s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B55S1_SequenceReg0b55s1_SHIFT (0U)
/*! SequenceReg0b55s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B55S1_SequenceReg0b55s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B55S1_SequenceReg0b55s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B55S1_SequenceReg0b55s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B55S2 - PHY Initialization Engine (PIE) Instruction 55_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B55S2_SequenceReg0b55s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B55S2_SequenceReg0b55s2_SHIFT (0U)
/*! SequenceReg0b55s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B55S2_SequenceReg0b55s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B55S2_SequenceReg0b55s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B55S2_SequenceReg0b55s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B56S0 - PHY Initialization Engine (PIE) Instruction 56_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B56S0_SequenceReg0b56s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B56S0_SequenceReg0b56s0_SHIFT (0U)
/*! SequenceReg0b56s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B56S0_SequenceReg0b56s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B56S0_SequenceReg0b56s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B56S0_SequenceReg0b56s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B56S1 - PHY Initialization Engine (PIE) Instruction 56_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B56S1_SequenceReg0b56s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B56S1_SequenceReg0b56s1_SHIFT (0U)
/*! SequenceReg0b56s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B56S1_SequenceReg0b56s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B56S1_SequenceReg0b56s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B56S1_SequenceReg0b56s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B56S2 - PHY Initialization Engine (PIE) Instruction 56_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B56S2_SequenceReg0b56s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B56S2_SequenceReg0b56s2_SHIFT (0U)
/*! SequenceReg0b56s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B56S2_SequenceReg0b56s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B56S2_SequenceReg0b56s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B56S2_SequenceReg0b56s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B57S0 - PHY Initialization Engine (PIE) Instruction 57_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B57S0_SequenceReg0b57s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B57S0_SequenceReg0b57s0_SHIFT (0U)
/*! SequenceReg0b57s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B57S0_SequenceReg0b57s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B57S0_SequenceReg0b57s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B57S0_SequenceReg0b57s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B57S1 - PHY Initialization Engine (PIE) Instruction 57_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B57S1_SequenceReg0b57s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B57S1_SequenceReg0b57s1_SHIFT (0U)
/*! SequenceReg0b57s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B57S1_SequenceReg0b57s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B57S1_SequenceReg0b57s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B57S1_SequenceReg0b57s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B57S2 - PHY Initialization Engine (PIE) Instruction 57_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B57S2_SequenceReg0b57s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B57S2_SequenceReg0b57s2_SHIFT (0U)
/*! SequenceReg0b57s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B57S2_SequenceReg0b57s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B57S2_SequenceReg0b57s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B57S2_SequenceReg0b57s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B58S0 - PHY Initialization Engine (PIE) Instruction 58_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B58S0_SequenceReg0b58s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B58S0_SequenceReg0b58s0_SHIFT (0U)
/*! SequenceReg0b58s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B58S0_SequenceReg0b58s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B58S0_SequenceReg0b58s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B58S0_SequenceReg0b58s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B58S1 - PHY Initialization Engine (PIE) Instruction 58_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B58S1_SequenceReg0b58s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B58S1_SequenceReg0b58s1_SHIFT (0U)
/*! SequenceReg0b58s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B58S1_SequenceReg0b58s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B58S1_SequenceReg0b58s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B58S1_SequenceReg0b58s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B58S2 - PHY Initialization Engine (PIE) Instruction 58_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B58S2_SequenceReg0b58s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B58S2_SequenceReg0b58s2_SHIFT (0U)
/*! SequenceReg0b58s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B58S2_SequenceReg0b58s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B58S2_SequenceReg0b58s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B58S2_SequenceReg0b58s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B59S0 - PHY Initialization Engine (PIE) Instruction 59_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B59S0_SequenceReg0b59s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B59S0_SequenceReg0b59s0_SHIFT (0U)
/*! SequenceReg0b59s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B59S0_SequenceReg0b59s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B59S0_SequenceReg0b59s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B59S0_SequenceReg0b59s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B59S1 - PHY Initialization Engine (PIE) Instruction 59_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B59S1_SequenceReg0b59s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B59S1_SequenceReg0b59s1_SHIFT (0U)
/*! SequenceReg0b59s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B59S1_SequenceReg0b59s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B59S1_SequenceReg0b59s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B59S1_SequenceReg0b59s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B59S2 - PHY Initialization Engine (PIE) Instruction 59_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B59S2_SequenceReg0b59s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B59S2_SequenceReg0b59s2_SHIFT (0U)
/*! SequenceReg0b59s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B59S2_SequenceReg0b59s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B59S2_SequenceReg0b59s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B59S2_SequenceReg0b59s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B60S0 - PHY Initialization Engine (PIE) Instruction 60_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B60S0_SequenceReg0b60s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B60S0_SequenceReg0b60s0_SHIFT (0U)
/*! SequenceReg0b60s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B60S0_SequenceReg0b60s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B60S0_SequenceReg0b60s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B60S0_SequenceReg0b60s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B60S1 - PHY Initialization Engine (PIE) Instruction 60_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B60S1_SequenceReg0b60s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B60S1_SequenceReg0b60s1_SHIFT (0U)
/*! SequenceReg0b60s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B60S1_SequenceReg0b60s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B60S1_SequenceReg0b60s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B60S1_SequenceReg0b60s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B60S2 - PHY Initialization Engine (PIE) Instruction 60_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B60S2_SequenceReg0b60s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B60S2_SequenceReg0b60s2_SHIFT (0U)
/*! SequenceReg0b60s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B60S2_SequenceReg0b60s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B60S2_SequenceReg0b60s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B60S2_SequenceReg0b60s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B61S0 - PHY Initialization Engine (PIE) Instruction 61_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B61S0_SequenceReg0b61s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B61S0_SequenceReg0b61s0_SHIFT (0U)
/*! SequenceReg0b61s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B61S0_SequenceReg0b61s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B61S0_SequenceReg0b61s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B61S0_SequenceReg0b61s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B61S1 - PHY Initialization Engine (PIE) Instruction 61_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B61S1_SequenceReg0b61s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B61S1_SequenceReg0b61s1_SHIFT (0U)
/*! SequenceReg0b61s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B61S1_SequenceReg0b61s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B61S1_SequenceReg0b61s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B61S1_SequenceReg0b61s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B61S2 - PHY Initialization Engine (PIE) Instruction 61_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B61S2_SequenceReg0b61s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B61S2_SequenceReg0b61s2_SHIFT (0U)
/*! SequenceReg0b61s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B61S2_SequenceReg0b61s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B61S2_SequenceReg0b61s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B61S2_SequenceReg0b61s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B62S0 - PHY Initialization Engine (PIE) Instruction 62_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B62S0_SequenceReg0b62s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B62S0_SequenceReg0b62s0_SHIFT (0U)
/*! SequenceReg0b62s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B62S0_SequenceReg0b62s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B62S0_SequenceReg0b62s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B62S0_SequenceReg0b62s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B62S1 - PHY Initialization Engine (PIE) Instruction 62_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B62S1_SequenceReg0b62s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B62S1_SequenceReg0b62s1_SHIFT (0U)
/*! SequenceReg0b62s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B62S1_SequenceReg0b62s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B62S1_SequenceReg0b62s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B62S1_SequenceReg0b62s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B62S2 - PHY Initialization Engine (PIE) Instruction 62_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B62S2_SequenceReg0b62s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B62S2_SequenceReg0b62s2_SHIFT (0U)
/*! SequenceReg0b62s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B62S2_SequenceReg0b62s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B62S2_SequenceReg0b62s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B62S2_SequenceReg0b62s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B63S0 - PHY Initialization Engine (PIE) Instruction 63_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B63S0_SequenceReg0b63s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B63S0_SequenceReg0b63s0_SHIFT (0U)
/*! SequenceReg0b63s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B63S0_SequenceReg0b63s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B63S0_SequenceReg0b63s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B63S0_SequenceReg0b63s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B63S1 - PHY Initialization Engine (PIE) Instruction 63_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B63S1_SequenceReg0b63s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B63S1_SequenceReg0b63s1_SHIFT (0U)
/*! SequenceReg0b63s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B63S1_SequenceReg0b63s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B63S1_SequenceReg0b63s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B63S1_SequenceReg0b63s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B63S2 - PHY Initialization Engine (PIE) Instruction 63_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B63S2_SequenceReg0b63s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B63S2_SequenceReg0b63s2_SHIFT (0U)
/*! SequenceReg0b63s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B63S2_SequenceReg0b63s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B63S2_SequenceReg0b63s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B63S2_SequenceReg0b63s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B64S0 - PHY Initialization Engine (PIE) Instruction 64_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B64S0_SequenceReg0b64s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B64S0_SequenceReg0b64s0_SHIFT (0U)
/*! SequenceReg0b64s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B64S0_SequenceReg0b64s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B64S0_SequenceReg0b64s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B64S0_SequenceReg0b64s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B64S1 - PHY Initialization Engine (PIE) Instruction 64_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B64S1_SequenceReg0b64s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B64S1_SequenceReg0b64s1_SHIFT (0U)
/*! SequenceReg0b64s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B64S1_SequenceReg0b64s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B64S1_SequenceReg0b64s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B64S1_SequenceReg0b64s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B64S2 - PHY Initialization Engine (PIE) Instruction 64_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B64S2_SequenceReg0b64s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B64S2_SequenceReg0b64s2_SHIFT (0U)
/*! SequenceReg0b64s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B64S2_SequenceReg0b64s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B64S2_SequenceReg0b64s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B64S2_SequenceReg0b64s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B65S0 - PHY Initialization Engine (PIE) Instruction 65_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B65S0_SequenceReg0b65s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B65S0_SequenceReg0b65s0_SHIFT (0U)
/*! SequenceReg0b65s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B65S0_SequenceReg0b65s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B65S0_SequenceReg0b65s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B65S0_SequenceReg0b65s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B65S1 - PHY Initialization Engine (PIE) Instruction 65_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B65S1_SequenceReg0b65s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B65S1_SequenceReg0b65s1_SHIFT (0U)
/*! SequenceReg0b65s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B65S1_SequenceReg0b65s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B65S1_SequenceReg0b65s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B65S1_SequenceReg0b65s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B65S2 - PHY Initialization Engine (PIE) Instruction 65_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B65S2_SequenceReg0b65s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B65S2_SequenceReg0b65s2_SHIFT (0U)
/*! SequenceReg0b65s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B65S2_SequenceReg0b65s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B65S2_SequenceReg0b65s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B65S2_SequenceReg0b65s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B66S0 - PHY Initialization Engine (PIE) Instruction 66_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B66S0_SequenceReg0b66s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B66S0_SequenceReg0b66s0_SHIFT (0U)
/*! SequenceReg0b66s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B66S0_SequenceReg0b66s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B66S0_SequenceReg0b66s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B66S0_SequenceReg0b66s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B66S1 - PHY Initialization Engine (PIE) Instruction 66_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B66S1_SequenceReg0b66s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B66S1_SequenceReg0b66s1_SHIFT (0U)
/*! SequenceReg0b66s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B66S1_SequenceReg0b66s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B66S1_SequenceReg0b66s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B66S1_SequenceReg0b66s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B66S2 - PHY Initialization Engine (PIE) Instruction 66_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B66S2_SequenceReg0b66s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B66S2_SequenceReg0b66s2_SHIFT (0U)
/*! SequenceReg0b66s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B66S2_SequenceReg0b66s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B66S2_SequenceReg0b66s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B66S2_SequenceReg0b66s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B67S0 - PHY Initialization Engine (PIE) Instruction 67_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B67S0_SequenceReg0b67s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B67S0_SequenceReg0b67s0_SHIFT (0U)
/*! SequenceReg0b67s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B67S0_SequenceReg0b67s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B67S0_SequenceReg0b67s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B67S0_SequenceReg0b67s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B67S1 - PHY Initialization Engine (PIE) Instruction 67_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B67S1_SequenceReg0b67s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B67S1_SequenceReg0b67s1_SHIFT (0U)
/*! SequenceReg0b67s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B67S1_SequenceReg0b67s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B67S1_SequenceReg0b67s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B67S1_SequenceReg0b67s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B67S2 - PHY Initialization Engine (PIE) Instruction 67_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B67S2_SequenceReg0b67s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B67S2_SequenceReg0b67s2_SHIFT (0U)
/*! SequenceReg0b67s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B67S2_SequenceReg0b67s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B67S2_SequenceReg0b67s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B67S2_SequenceReg0b67s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B68S0 - PHY Initialization Engine (PIE) Instruction 68_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B68S0_SequenceReg0b68s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B68S0_SequenceReg0b68s0_SHIFT (0U)
/*! SequenceReg0b68s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B68S0_SequenceReg0b68s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B68S0_SequenceReg0b68s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B68S0_SequenceReg0b68s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B68S1 - PHY Initialization Engine (PIE) Instruction 68_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B68S1_SequenceReg0b68s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B68S1_SequenceReg0b68s1_SHIFT (0U)
/*! SequenceReg0b68s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B68S1_SequenceReg0b68s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B68S1_SequenceReg0b68s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B68S1_SequenceReg0b68s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B68S2 - PHY Initialization Engine (PIE) Instruction 68_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B68S2_SequenceReg0b68s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B68S2_SequenceReg0b68s2_SHIFT (0U)
/*! SequenceReg0b68s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B68S2_SequenceReg0b68s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B68S2_SequenceReg0b68s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B68S2_SequenceReg0b68s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B69S0 - PHY Initialization Engine (PIE) Instruction 69_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B69S0_SequenceReg0b69s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B69S0_SequenceReg0b69s0_SHIFT (0U)
/*! SequenceReg0b69s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B69S0_SequenceReg0b69s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B69S0_SequenceReg0b69s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B69S0_SequenceReg0b69s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B69S1 - PHY Initialization Engine (PIE) Instruction 69_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B69S1_SequenceReg0b69s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B69S1_SequenceReg0b69s1_SHIFT (0U)
/*! SequenceReg0b69s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B69S1_SequenceReg0b69s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B69S1_SequenceReg0b69s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B69S1_SequenceReg0b69s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B69S2 - PHY Initialization Engine (PIE) Instruction 69_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B69S2_SequenceReg0b69s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B69S2_SequenceReg0b69s2_SHIFT (0U)
/*! SequenceReg0b69s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B69S2_SequenceReg0b69s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B69S2_SequenceReg0b69s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B69S2_SequenceReg0b69s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B70S0 - PHY Initialization Engine (PIE) Instruction 70_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B70S0_SequenceReg0b70s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B70S0_SequenceReg0b70s0_SHIFT (0U)
/*! SequenceReg0b70s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B70S0_SequenceReg0b70s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B70S0_SequenceReg0b70s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B70S0_SequenceReg0b70s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B70S1 - PHY Initialization Engine (PIE) Instruction 70_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B70S1_SequenceReg0b70s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B70S1_SequenceReg0b70s1_SHIFT (0U)
/*! SequenceReg0b70s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B70S1_SequenceReg0b70s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B70S1_SequenceReg0b70s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B70S1_SequenceReg0b70s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B70S2 - PHY Initialization Engine (PIE) Instruction 70_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B70S2_SequenceReg0b70s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B70S2_SequenceReg0b70s2_SHIFT (0U)
/*! SequenceReg0b70s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B70S2_SequenceReg0b70s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B70S2_SequenceReg0b70s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B70S2_SequenceReg0b70s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B71S0 - PHY Initialization Engine (PIE) Instruction 71_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B71S0_SequenceReg0b71s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B71S0_SequenceReg0b71s0_SHIFT (0U)
/*! SequenceReg0b71s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B71S0_SequenceReg0b71s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B71S0_SequenceReg0b71s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B71S0_SequenceReg0b71s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B71S1 - PHY Initialization Engine (PIE) Instruction 71_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B71S1_SequenceReg0b71s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B71S1_SequenceReg0b71s1_SHIFT (0U)
/*! SequenceReg0b71s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B71S1_SequenceReg0b71s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B71S1_SequenceReg0b71s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B71S1_SequenceReg0b71s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B71S2 - PHY Initialization Engine (PIE) Instruction 71_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B71S2_SequenceReg0b71s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B71S2_SequenceReg0b71s2_SHIFT (0U)
/*! SequenceReg0b71s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B71S2_SequenceReg0b71s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B71S2_SequenceReg0b71s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B71S2_SequenceReg0b71s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B72S0 - PHY Initialization Engine (PIE) Instruction 72_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B72S0_SequenceReg0b72s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B72S0_SequenceReg0b72s0_SHIFT (0U)
/*! SequenceReg0b72s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B72S0_SequenceReg0b72s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B72S0_SequenceReg0b72s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B72S0_SequenceReg0b72s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B72S1 - PHY Initialization Engine (PIE) Instruction 72_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B72S1_SequenceReg0b72s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B72S1_SequenceReg0b72s1_SHIFT (0U)
/*! SequenceReg0b72s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B72S1_SequenceReg0b72s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B72S1_SequenceReg0b72s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B72S1_SequenceReg0b72s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B72S2 - PHY Initialization Engine (PIE) Instruction 72_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B72S2_SequenceReg0b72s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B72S2_SequenceReg0b72s2_SHIFT (0U)
/*! SequenceReg0b72s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B72S2_SequenceReg0b72s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B72S2_SequenceReg0b72s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B72S2_SequenceReg0b72s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B73S0 - PHY Initialization Engine (PIE) Instruction 73_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B73S0_SequenceReg0b73s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B73S0_SequenceReg0b73s0_SHIFT (0U)
/*! SequenceReg0b73s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B73S0_SequenceReg0b73s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B73S0_SequenceReg0b73s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B73S0_SequenceReg0b73s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B73S1 - PHY Initialization Engine (PIE) Instruction 73_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B73S1_SequenceReg0b73s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B73S1_SequenceReg0b73s1_SHIFT (0U)
/*! SequenceReg0b73s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B73S1_SequenceReg0b73s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B73S1_SequenceReg0b73s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B73S1_SequenceReg0b73s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B73S2 - PHY Initialization Engine (PIE) Instruction 73_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B73S2_SequenceReg0b73s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B73S2_SequenceReg0b73s2_SHIFT (0U)
/*! SequenceReg0b73s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B73S2_SequenceReg0b73s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B73S2_SequenceReg0b73s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B73S2_SequenceReg0b73s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B74S0 - PHY Initialization Engine (PIE) Instruction 74_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B74S0_SequenceReg0b74s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B74S0_SequenceReg0b74s0_SHIFT (0U)
/*! SequenceReg0b74s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B74S0_SequenceReg0b74s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B74S0_SequenceReg0b74s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B74S0_SequenceReg0b74s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B74S1 - PHY Initialization Engine (PIE) Instruction 74_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B74S1_SequenceReg0b74s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B74S1_SequenceReg0b74s1_SHIFT (0U)
/*! SequenceReg0b74s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B74S1_SequenceReg0b74s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B74S1_SequenceReg0b74s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B74S1_SequenceReg0b74s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B74S2 - PHY Initialization Engine (PIE) Instruction 74_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B74S2_SequenceReg0b74s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B74S2_SequenceReg0b74s2_SHIFT (0U)
/*! SequenceReg0b74s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B74S2_SequenceReg0b74s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B74S2_SequenceReg0b74s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B74S2_SequenceReg0b74s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B75S0 - PHY Initialization Engine (PIE) Instruction 75_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B75S0_SequenceReg0b75s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B75S0_SequenceReg0b75s0_SHIFT (0U)
/*! SequenceReg0b75s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B75S0_SequenceReg0b75s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B75S0_SequenceReg0b75s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B75S0_SequenceReg0b75s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B75S1 - PHY Initialization Engine (PIE) Instruction 75_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B75S1_SequenceReg0b75s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B75S1_SequenceReg0b75s1_SHIFT (0U)
/*! SequenceReg0b75s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B75S1_SequenceReg0b75s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B75S1_SequenceReg0b75s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B75S1_SequenceReg0b75s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B75S2 - PHY Initialization Engine (PIE) Instruction 75_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B75S2_SequenceReg0b75s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B75S2_SequenceReg0b75s2_SHIFT (0U)
/*! SequenceReg0b75s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B75S2_SequenceReg0b75s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B75S2_SequenceReg0b75s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B75S2_SequenceReg0b75s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B76S0 - PHY Initialization Engine (PIE) Instruction 76_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B76S0_SequenceReg0b76s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B76S0_SequenceReg0b76s0_SHIFT (0U)
/*! SequenceReg0b76s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B76S0_SequenceReg0b76s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B76S0_SequenceReg0b76s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B76S0_SequenceReg0b76s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B76S1 - PHY Initialization Engine (PIE) Instruction 76_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B76S1_SequenceReg0b76s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B76S1_SequenceReg0b76s1_SHIFT (0U)
/*! SequenceReg0b76s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B76S1_SequenceReg0b76s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B76S1_SequenceReg0b76s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B76S1_SequenceReg0b76s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B76S2 - PHY Initialization Engine (PIE) Instruction 76_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B76S2_SequenceReg0b76s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B76S2_SequenceReg0b76s2_SHIFT (0U)
/*! SequenceReg0b76s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B76S2_SequenceReg0b76s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B76S2_SequenceReg0b76s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B76S2_SequenceReg0b76s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B77S0 - PHY Initialization Engine (PIE) Instruction 77_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B77S0_SequenceReg0b77s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B77S0_SequenceReg0b77s0_SHIFT (0U)
/*! SequenceReg0b77s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B77S0_SequenceReg0b77s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B77S0_SequenceReg0b77s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B77S0_SequenceReg0b77s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B77S1 - PHY Initialization Engine (PIE) Instruction 77_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B77S1_SequenceReg0b77s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B77S1_SequenceReg0b77s1_SHIFT (0U)
/*! SequenceReg0b77s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B77S1_SequenceReg0b77s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B77S1_SequenceReg0b77s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B77S1_SequenceReg0b77s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B77S2 - PHY Initialization Engine (PIE) Instruction 77_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B77S2_SequenceReg0b77s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B77S2_SequenceReg0b77s2_SHIFT (0U)
/*! SequenceReg0b77s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B77S2_SequenceReg0b77s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B77S2_SequenceReg0b77s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B77S2_SequenceReg0b77s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B78S0 - PHY Initialization Engine (PIE) Instruction 78_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B78S0_SequenceReg0b78s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B78S0_SequenceReg0b78s0_SHIFT (0U)
/*! SequenceReg0b78s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B78S0_SequenceReg0b78s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B78S0_SequenceReg0b78s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B78S0_SequenceReg0b78s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B78S1 - PHY Initialization Engine (PIE) Instruction 78_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B78S1_SequenceReg0b78s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B78S1_SequenceReg0b78s1_SHIFT (0U)
/*! SequenceReg0b78s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B78S1_SequenceReg0b78s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B78S1_SequenceReg0b78s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B78S1_SequenceReg0b78s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B78S2 - PHY Initialization Engine (PIE) Instruction 78_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B78S2_SequenceReg0b78s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B78S2_SequenceReg0b78s2_SHIFT (0U)
/*! SequenceReg0b78s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B78S2_SequenceReg0b78s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B78S2_SequenceReg0b78s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B78S2_SequenceReg0b78s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B79S0 - PHY Initialization Engine (PIE) Instruction 79_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B79S0_SequenceReg0b79s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B79S0_SequenceReg0b79s0_SHIFT (0U)
/*! SequenceReg0b79s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B79S0_SequenceReg0b79s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B79S0_SequenceReg0b79s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B79S0_SequenceReg0b79s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B79S1 - PHY Initialization Engine (PIE) Instruction 79_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B79S1_SequenceReg0b79s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B79S1_SequenceReg0b79s1_SHIFT (0U)
/*! SequenceReg0b79s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B79S1_SequenceReg0b79s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B79S1_SequenceReg0b79s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B79S1_SequenceReg0b79s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B79S2 - PHY Initialization Engine (PIE) Instruction 79_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B79S2_SequenceReg0b79s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B79S2_SequenceReg0b79s2_SHIFT (0U)
/*! SequenceReg0b79s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B79S2_SequenceReg0b79s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B79S2_SequenceReg0b79s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B79S2_SequenceReg0b79s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B80S0 - PHY Initialization Engine (PIE) Instruction 80_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B80S0_SequenceReg0b80s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B80S0_SequenceReg0b80s0_SHIFT (0U)
/*! SequenceReg0b80s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B80S0_SequenceReg0b80s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B80S0_SequenceReg0b80s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B80S0_SequenceReg0b80s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B80S1 - PHY Initialization Engine (PIE) Instruction 80_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B80S1_SequenceReg0b80s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B80S1_SequenceReg0b80s1_SHIFT (0U)
/*! SequenceReg0b80s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B80S1_SequenceReg0b80s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B80S1_SequenceReg0b80s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B80S1_SequenceReg0b80s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B80S2 - PHY Initialization Engine (PIE) Instruction 80_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B80S2_SequenceReg0b80s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B80S2_SequenceReg0b80s2_SHIFT (0U)
/*! SequenceReg0b80s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B80S2_SequenceReg0b80s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B80S2_SequenceReg0b80s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B80S2_SequenceReg0b80s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B81S0 - PHY Initialization Engine (PIE) Instruction 81_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B81S0_SequenceReg0b81s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B81S0_SequenceReg0b81s0_SHIFT (0U)
/*! SequenceReg0b81s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B81S0_SequenceReg0b81s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B81S0_SequenceReg0b81s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B81S0_SequenceReg0b81s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B81S1 - PHY Initialization Engine (PIE) Instruction 81_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B81S1_SequenceReg0b81s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B81S1_SequenceReg0b81s1_SHIFT (0U)
/*! SequenceReg0b81s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B81S1_SequenceReg0b81s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B81S1_SequenceReg0b81s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B81S1_SequenceReg0b81s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B81S2 - PHY Initialization Engine (PIE) Instruction 81_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B81S2_SequenceReg0b81s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B81S2_SequenceReg0b81s2_SHIFT (0U)
/*! SequenceReg0b81s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B81S2_SequenceReg0b81s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B81S2_SequenceReg0b81s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B81S2_SequenceReg0b81s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B82S0 - PHY Initialization Engine (PIE) Instruction 82_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B82S0_SequenceReg0b82s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B82S0_SequenceReg0b82s0_SHIFT (0U)
/*! SequenceReg0b82s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B82S0_SequenceReg0b82s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B82S0_SequenceReg0b82s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B82S0_SequenceReg0b82s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B82S1 - PHY Initialization Engine (PIE) Instruction 82_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B82S1_SequenceReg0b82s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B82S1_SequenceReg0b82s1_SHIFT (0U)
/*! SequenceReg0b82s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B82S1_SequenceReg0b82s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B82S1_SequenceReg0b82s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B82S1_SequenceReg0b82s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B82S2 - PHY Initialization Engine (PIE) Instruction 82_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B82S2_SequenceReg0b82s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B82S2_SequenceReg0b82s2_SHIFT (0U)
/*! SequenceReg0b82s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B82S2_SequenceReg0b82s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B82S2_SequenceReg0b82s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B82S2_SequenceReg0b82s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B83S0 - PHY Initialization Engine (PIE) Instruction 83_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B83S0_SequenceReg0b83s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B83S0_SequenceReg0b83s0_SHIFT (0U)
/*! SequenceReg0b83s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B83S0_SequenceReg0b83s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B83S0_SequenceReg0b83s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B83S0_SequenceReg0b83s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B83S1 - PHY Initialization Engine (PIE) Instruction 83_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B83S1_SequenceReg0b83s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B83S1_SequenceReg0b83s1_SHIFT (0U)
/*! SequenceReg0b83s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B83S1_SequenceReg0b83s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B83S1_SequenceReg0b83s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B83S1_SequenceReg0b83s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B83S2 - PHY Initialization Engine (PIE) Instruction 83_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B83S2_SequenceReg0b83s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B83S2_SequenceReg0b83s2_SHIFT (0U)
/*! SequenceReg0b83s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B83S2_SequenceReg0b83s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B83S2_SequenceReg0b83s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B83S2_SequenceReg0b83s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B84S0 - PHY Initialization Engine (PIE) Instruction 84_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B84S0_SequenceReg0b84s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B84S0_SequenceReg0b84s0_SHIFT (0U)
/*! SequenceReg0b84s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B84S0_SequenceReg0b84s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B84S0_SequenceReg0b84s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B84S0_SequenceReg0b84s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B84S1 - PHY Initialization Engine (PIE) Instruction 84_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B84S1_SequenceReg0b84s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B84S1_SequenceReg0b84s1_SHIFT (0U)
/*! SequenceReg0b84s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B84S1_SequenceReg0b84s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B84S1_SequenceReg0b84s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B84S1_SequenceReg0b84s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B84S2 - PHY Initialization Engine (PIE) Instruction 84_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B84S2_SequenceReg0b84s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B84S2_SequenceReg0b84s2_SHIFT (0U)
/*! SequenceReg0b84s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B84S2_SequenceReg0b84s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B84S2_SequenceReg0b84s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B84S2_SequenceReg0b84s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B85S0 - PHY Initialization Engine (PIE) Instruction 85_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B85S0_SequenceReg0b85s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B85S0_SequenceReg0b85s0_SHIFT (0U)
/*! SequenceReg0b85s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B85S0_SequenceReg0b85s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B85S0_SequenceReg0b85s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B85S0_SequenceReg0b85s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B85S1 - PHY Initialization Engine (PIE) Instruction 85_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B85S1_SequenceReg0b85s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B85S1_SequenceReg0b85s1_SHIFT (0U)
/*! SequenceReg0b85s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B85S1_SequenceReg0b85s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B85S1_SequenceReg0b85s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B85S1_SequenceReg0b85s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B85S2 - PHY Initialization Engine (PIE) Instruction 85_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B85S2_SequenceReg0b85s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B85S2_SequenceReg0b85s2_SHIFT (0U)
/*! SequenceReg0b85s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B85S2_SequenceReg0b85s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B85S2_SequenceReg0b85s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B85S2_SequenceReg0b85s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B86S0 - PHY Initialization Engine (PIE) Instruction 86_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B86S0_SequenceReg0b86s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B86S0_SequenceReg0b86s0_SHIFT (0U)
/*! SequenceReg0b86s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B86S0_SequenceReg0b86s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B86S0_SequenceReg0b86s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B86S0_SequenceReg0b86s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B86S1 - PHY Initialization Engine (PIE) Instruction 86_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B86S1_SequenceReg0b86s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B86S1_SequenceReg0b86s1_SHIFT (0U)
/*! SequenceReg0b86s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B86S1_SequenceReg0b86s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B86S1_SequenceReg0b86s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B86S1_SequenceReg0b86s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B86S2 - PHY Initialization Engine (PIE) Instruction 86_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B86S2_SequenceReg0b86s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B86S2_SequenceReg0b86s2_SHIFT (0U)
/*! SequenceReg0b86s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B86S2_SequenceReg0b86s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B86S2_SequenceReg0b86s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B86S2_SequenceReg0b86s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B87S0 - PHY Initialization Engine (PIE) Instruction 87_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B87S0_SequenceReg0b87s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B87S0_SequenceReg0b87s0_SHIFT (0U)
/*! SequenceReg0b87s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B87S0_SequenceReg0b87s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B87S0_SequenceReg0b87s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B87S0_SequenceReg0b87s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B87S1 - PHY Initialization Engine (PIE) Instruction 87_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B87S1_SequenceReg0b87s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B87S1_SequenceReg0b87s1_SHIFT (0U)
/*! SequenceReg0b87s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B87S1_SequenceReg0b87s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B87S1_SequenceReg0b87s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B87S1_SequenceReg0b87s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B87S2 - PHY Initialization Engine (PIE) Instruction 87_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B87S2_SequenceReg0b87s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B87S2_SequenceReg0b87s2_SHIFT (0U)
/*! SequenceReg0b87s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B87S2_SequenceReg0b87s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B87S2_SequenceReg0b87s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B87S2_SequenceReg0b87s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B88S0 - PHY Initialization Engine (PIE) Instruction 88_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B88S0_SequenceReg0b88s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B88S0_SequenceReg0b88s0_SHIFT (0U)
/*! SequenceReg0b88s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B88S0_SequenceReg0b88s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B88S0_SequenceReg0b88s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B88S0_SequenceReg0b88s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B88S1 - PHY Initialization Engine (PIE) Instruction 88_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B88S1_SequenceReg0b88s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B88S1_SequenceReg0b88s1_SHIFT (0U)
/*! SequenceReg0b88s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B88S1_SequenceReg0b88s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B88S1_SequenceReg0b88s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B88S1_SequenceReg0b88s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B88S2 - PHY Initialization Engine (PIE) Instruction 88_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B88S2_SequenceReg0b88s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B88S2_SequenceReg0b88s2_SHIFT (0U)
/*! SequenceReg0b88s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B88S2_SequenceReg0b88s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B88S2_SequenceReg0b88s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B88S2_SequenceReg0b88s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B89S0 - PHY Initialization Engine (PIE) Instruction 89_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B89S0_SequenceReg0b89s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B89S0_SequenceReg0b89s0_SHIFT (0U)
/*! SequenceReg0b89s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B89S0_SequenceReg0b89s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B89S0_SequenceReg0b89s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B89S0_SequenceReg0b89s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B89S1 - PHY Initialization Engine (PIE) Instruction 89_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B89S1_SequenceReg0b89s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B89S1_SequenceReg0b89s1_SHIFT (0U)
/*! SequenceReg0b89s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B89S1_SequenceReg0b89s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B89S1_SequenceReg0b89s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B89S1_SequenceReg0b89s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B89S2 - PHY Initialization Engine (PIE) Instruction 89_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B89S2_SequenceReg0b89s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B89S2_SequenceReg0b89s2_SHIFT (0U)
/*! SequenceReg0b89s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B89S2_SequenceReg0b89s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B89S2_SequenceReg0b89s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B89S2_SequenceReg0b89s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B90S0 - PHY Initialization Engine (PIE) Instruction 90_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B90S0_SequenceReg0b90s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B90S0_SequenceReg0b90s0_SHIFT (0U)
/*! SequenceReg0b90s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B90S0_SequenceReg0b90s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B90S0_SequenceReg0b90s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B90S0_SequenceReg0b90s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B90S1 - PHY Initialization Engine (PIE) Instruction 90_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B90S1_SequenceReg0b90s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B90S1_SequenceReg0b90s1_SHIFT (0U)
/*! SequenceReg0b90s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B90S1_SequenceReg0b90s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B90S1_SequenceReg0b90s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B90S1_SequenceReg0b90s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B90S2 - PHY Initialization Engine (PIE) Instruction 90_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B90S2_SequenceReg0b90s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B90S2_SequenceReg0b90s2_SHIFT (0U)
/*! SequenceReg0b90s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B90S2_SequenceReg0b90s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B90S2_SequenceReg0b90s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B90S2_SequenceReg0b90s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B91S0 - PHY Initialization Engine (PIE) Instruction 91_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B91S0_SequenceReg0b91s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B91S0_SequenceReg0b91s0_SHIFT (0U)
/*! SequenceReg0b91s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B91S0_SequenceReg0b91s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B91S0_SequenceReg0b91s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B91S0_SequenceReg0b91s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B91S1 - PHY Initialization Engine (PIE) Instruction 91_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B91S1_SequenceReg0b91s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B91S1_SequenceReg0b91s1_SHIFT (0U)
/*! SequenceReg0b91s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B91S1_SequenceReg0b91s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B91S1_SequenceReg0b91s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B91S1_SequenceReg0b91s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B91S2 - PHY Initialization Engine (PIE) Instruction 91_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B91S2_SequenceReg0b91s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B91S2_SequenceReg0b91s2_SHIFT (0U)
/*! SequenceReg0b91s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B91S2_SequenceReg0b91s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B91S2_SequenceReg0b91s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B91S2_SequenceReg0b91s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B92S0 - PHY Initialization Engine (PIE) Instruction 92_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B92S0_SequenceReg0b92s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B92S0_SequenceReg0b92s0_SHIFT (0U)
/*! SequenceReg0b92s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B92S0_SequenceReg0b92s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B92S0_SequenceReg0b92s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B92S0_SequenceReg0b92s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B92S1 - PHY Initialization Engine (PIE) Instruction 92_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B92S1_SequenceReg0b92s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B92S1_SequenceReg0b92s1_SHIFT (0U)
/*! SequenceReg0b92s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B92S1_SequenceReg0b92s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B92S1_SequenceReg0b92s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B92S1_SequenceReg0b92s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B92S2 - PHY Initialization Engine (PIE) Instruction 92_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B92S2_SequenceReg0b92s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B92S2_SequenceReg0b92s2_SHIFT (0U)
/*! SequenceReg0b92s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B92S2_SequenceReg0b92s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B92S2_SequenceReg0b92s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B92S2_SequenceReg0b92s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B93S0 - PHY Initialization Engine (PIE) Instruction 93_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B93S0_SequenceReg0b93s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B93S0_SequenceReg0b93s0_SHIFT (0U)
/*! SequenceReg0b93s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B93S0_SequenceReg0b93s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B93S0_SequenceReg0b93s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B93S0_SequenceReg0b93s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B93S1 - PHY Initialization Engine (PIE) Instruction 93_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B93S1_SequenceReg0b93s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B93S1_SequenceReg0b93s1_SHIFT (0U)
/*! SequenceReg0b93s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B93S1_SequenceReg0b93s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B93S1_SequenceReg0b93s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B93S1_SequenceReg0b93s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B93S2 - PHY Initialization Engine (PIE) Instruction 93_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B93S2_SequenceReg0b93s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B93S2_SequenceReg0b93s2_SHIFT (0U)
/*! SequenceReg0b93s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B93S2_SequenceReg0b93s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B93S2_SequenceReg0b93s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B93S2_SequenceReg0b93s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B94S0 - PHY Initialization Engine (PIE) Instruction 94_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B94S0_SequenceReg0b94s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B94S0_SequenceReg0b94s0_SHIFT (0U)
/*! SequenceReg0b94s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B94S0_SequenceReg0b94s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B94S0_SequenceReg0b94s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B94S0_SequenceReg0b94s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B94S1 - PHY Initialization Engine (PIE) Instruction 94_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B94S1_SequenceReg0b94s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B94S1_SequenceReg0b94s1_SHIFT (0U)
/*! SequenceReg0b94s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B94S1_SequenceReg0b94s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B94S1_SequenceReg0b94s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B94S1_SequenceReg0b94s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B94S2 - PHY Initialization Engine (PIE) Instruction 94_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B94S2_SequenceReg0b94s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B94S2_SequenceReg0b94s2_SHIFT (0U)
/*! SequenceReg0b94s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B94S2_SequenceReg0b94s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B94S2_SequenceReg0b94s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B94S2_SequenceReg0b94s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B95S0 - PHY Initialization Engine (PIE) Instruction 95_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B95S0_SequenceReg0b95s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B95S0_SequenceReg0b95s0_SHIFT (0U)
/*! SequenceReg0b95s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B95S0_SequenceReg0b95s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B95S0_SequenceReg0b95s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B95S0_SequenceReg0b95s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B95S1 - PHY Initialization Engine (PIE) Instruction 95_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B95S1_SequenceReg0b95s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B95S1_SequenceReg0b95s1_SHIFT (0U)
/*! SequenceReg0b95s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B95S1_SequenceReg0b95s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B95S1_SequenceReg0b95s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B95S1_SequenceReg0b95s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B95S2 - PHY Initialization Engine (PIE) Instruction 95_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B95S2_SequenceReg0b95s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B95S2_SequenceReg0b95s2_SHIFT (0U)
/*! SequenceReg0b95s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B95S2_SequenceReg0b95s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B95S2_SequenceReg0b95s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B95S2_SequenceReg0b95s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B96S0 - PHY Initialization Engine (PIE) Instruction 96_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B96S0_SequenceReg0b96s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B96S0_SequenceReg0b96s0_SHIFT (0U)
/*! SequenceReg0b96s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B96S0_SequenceReg0b96s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B96S0_SequenceReg0b96s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B96S0_SequenceReg0b96s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B96S1 - PHY Initialization Engine (PIE) Instruction 96_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B96S1_SequenceReg0b96s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B96S1_SequenceReg0b96s1_SHIFT (0U)
/*! SequenceReg0b96s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B96S1_SequenceReg0b96s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B96S1_SequenceReg0b96s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B96S1_SequenceReg0b96s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B96S2 - PHY Initialization Engine (PIE) Instruction 96_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B96S2_SequenceReg0b96s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B96S2_SequenceReg0b96s2_SHIFT (0U)
/*! SequenceReg0b96s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B96S2_SequenceReg0b96s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B96S2_SequenceReg0b96s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B96S2_SequenceReg0b96s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B97S0 - PHY Initialization Engine (PIE) Instruction 97_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B97S0_SequenceReg0b97s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B97S0_SequenceReg0b97s0_SHIFT (0U)
/*! SequenceReg0b97s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B97S0_SequenceReg0b97s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B97S0_SequenceReg0b97s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B97S0_SequenceReg0b97s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B97S1 - PHY Initialization Engine (PIE) Instruction 97_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B97S1_SequenceReg0b97s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B97S1_SequenceReg0b97s1_SHIFT (0U)
/*! SequenceReg0b97s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B97S1_SequenceReg0b97s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B97S1_SequenceReg0b97s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B97S1_SequenceReg0b97s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B97S2 - PHY Initialization Engine (PIE) Instruction 97_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B97S2_SequenceReg0b97s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B97S2_SequenceReg0b97s2_SHIFT (0U)
/*! SequenceReg0b97s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B97S2_SequenceReg0b97s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B97S2_SequenceReg0b97s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B97S2_SequenceReg0b97s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B98S0 - PHY Initialization Engine (PIE) Instruction 98_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B98S0_SequenceReg0b98s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B98S0_SequenceReg0b98s0_SHIFT (0U)
/*! SequenceReg0b98s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B98S0_SequenceReg0b98s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B98S0_SequenceReg0b98s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B98S0_SequenceReg0b98s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B98S1 - PHY Initialization Engine (PIE) Instruction 98_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B98S1_SequenceReg0b98s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B98S1_SequenceReg0b98s1_SHIFT (0U)
/*! SequenceReg0b98s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B98S1_SequenceReg0b98s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B98S1_SequenceReg0b98s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B98S1_SequenceReg0b98s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B98S2 - PHY Initialization Engine (PIE) Instruction 98_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B98S2_SequenceReg0b98s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B98S2_SequenceReg0b98s2_SHIFT (0U)
/*! SequenceReg0b98s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B98S2_SequenceReg0b98s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B98S2_SequenceReg0b98s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B98S2_SequenceReg0b98s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B99S0 - PHY Initialization Engine (PIE) Instruction 99_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B99S0_SequenceReg0b99s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B99S0_SequenceReg0b99s0_SHIFT (0U)
/*! SequenceReg0b99s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B99S0_SequenceReg0b99s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B99S0_SequenceReg0b99s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B99S0_SequenceReg0b99s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B99S1 - PHY Initialization Engine (PIE) Instruction 99_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B99S1_SequenceReg0b99s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B99S1_SequenceReg0b99s1_SHIFT (0U)
/*! SequenceReg0b99s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B99S1_SequenceReg0b99s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B99S1_SequenceReg0b99s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B99S1_SequenceReg0b99s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B99S2 - PHY Initialization Engine (PIE) Instruction 99_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B99S2_SequenceReg0b99s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B99S2_SequenceReg0b99s2_SHIFT (0U)
/*! SequenceReg0b99s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B99S2_SequenceReg0b99s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B99S2_SequenceReg0b99s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B99S2_SequenceReg0b99s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B100S0 - PHY Initialization Engine (PIE) Instruction 100_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B100S0_SequenceReg0b100s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B100S0_SequenceReg0b100s0_SHIFT (0U)
/*! SequenceReg0b100s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B100S0_SequenceReg0b100s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B100S0_SequenceReg0b100s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B100S0_SequenceReg0b100s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B100S1 - PHY Initialization Engine (PIE) Instruction 100_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B100S1_SequenceReg0b100s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B100S1_SequenceReg0b100s1_SHIFT (0U)
/*! SequenceReg0b100s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B100S1_SequenceReg0b100s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B100S1_SequenceReg0b100s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B100S1_SequenceReg0b100s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B100S2 - PHY Initialization Engine (PIE) Instruction 100_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B100S2_SequenceReg0b100s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B100S2_SequenceReg0b100s2_SHIFT (0U)
/*! SequenceReg0b100s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B100S2_SequenceReg0b100s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B100S2_SequenceReg0b100s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B100S2_SequenceReg0b100s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B101S0 - PHY Initialization Engine (PIE) Instruction 101_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B101S0_SequenceReg0b101s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B101S0_SequenceReg0b101s0_SHIFT (0U)
/*! SequenceReg0b101s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B101S0_SequenceReg0b101s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B101S0_SequenceReg0b101s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B101S0_SequenceReg0b101s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B101S1 - PHY Initialization Engine (PIE) Instruction 101_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B101S1_SequenceReg0b101s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B101S1_SequenceReg0b101s1_SHIFT (0U)
/*! SequenceReg0b101s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B101S1_SequenceReg0b101s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B101S1_SequenceReg0b101s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B101S1_SequenceReg0b101s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B101S2 - PHY Initialization Engine (PIE) Instruction 101_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B101S2_SequenceReg0b101s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B101S2_SequenceReg0b101s2_SHIFT (0U)
/*! SequenceReg0b101s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B101S2_SequenceReg0b101s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B101S2_SequenceReg0b101s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B101S2_SequenceReg0b101s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B102S0 - PHY Initialization Engine (PIE) Instruction 102_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B102S0_SequenceReg0b102s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B102S0_SequenceReg0b102s0_SHIFT (0U)
/*! SequenceReg0b102s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B102S0_SequenceReg0b102s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B102S0_SequenceReg0b102s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B102S0_SequenceReg0b102s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B102S1 - PHY Initialization Engine (PIE) Instruction 102_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B102S1_SequenceReg0b102s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B102S1_SequenceReg0b102s1_SHIFT (0U)
/*! SequenceReg0b102s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B102S1_SequenceReg0b102s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B102S1_SequenceReg0b102s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B102S1_SequenceReg0b102s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B102S2 - PHY Initialization Engine (PIE) Instruction 102_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B102S2_SequenceReg0b102s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B102S2_SequenceReg0b102s2_SHIFT (0U)
/*! SequenceReg0b102s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B102S2_SequenceReg0b102s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B102S2_SequenceReg0b102s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B102S2_SequenceReg0b102s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B103S0 - PHY Initialization Engine (PIE) Instruction 103_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B103S0_SequenceReg0b103s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B103S0_SequenceReg0b103s0_SHIFT (0U)
/*! SequenceReg0b103s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B103S0_SequenceReg0b103s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B103S0_SequenceReg0b103s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B103S0_SequenceReg0b103s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B103S1 - PHY Initialization Engine (PIE) Instruction 103_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B103S1_SequenceReg0b103s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B103S1_SequenceReg0b103s1_SHIFT (0U)
/*! SequenceReg0b103s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B103S1_SequenceReg0b103s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B103S1_SequenceReg0b103s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B103S1_SequenceReg0b103s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B103S2 - PHY Initialization Engine (PIE) Instruction 103_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B103S2_SequenceReg0b103s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B103S2_SequenceReg0b103s2_SHIFT (0U)
/*! SequenceReg0b103s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B103S2_SequenceReg0b103s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B103S2_SequenceReg0b103s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B103S2_SequenceReg0b103s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B104S0 - PHY Initialization Engine (PIE) Instruction 104_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B104S0_SequenceReg0b104s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B104S0_SequenceReg0b104s0_SHIFT (0U)
/*! SequenceReg0b104s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B104S0_SequenceReg0b104s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B104S0_SequenceReg0b104s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B104S0_SequenceReg0b104s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B104S1 - PHY Initialization Engine (PIE) Instruction 104_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B104S1_SequenceReg0b104s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B104S1_SequenceReg0b104s1_SHIFT (0U)
/*! SequenceReg0b104s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B104S1_SequenceReg0b104s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B104S1_SequenceReg0b104s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B104S1_SequenceReg0b104s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B104S2 - PHY Initialization Engine (PIE) Instruction 104_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B104S2_SequenceReg0b104s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B104S2_SequenceReg0b104s2_SHIFT (0U)
/*! SequenceReg0b104s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B104S2_SequenceReg0b104s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B104S2_SequenceReg0b104s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B104S2_SequenceReg0b104s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B105S0 - PHY Initialization Engine (PIE) Instruction 105_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B105S0_SequenceReg0b105s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B105S0_SequenceReg0b105s0_SHIFT (0U)
/*! SequenceReg0b105s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B105S0_SequenceReg0b105s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B105S0_SequenceReg0b105s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B105S0_SequenceReg0b105s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B105S1 - PHY Initialization Engine (PIE) Instruction 105_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B105S1_SequenceReg0b105s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B105S1_SequenceReg0b105s1_SHIFT (0U)
/*! SequenceReg0b105s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B105S1_SequenceReg0b105s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B105S1_SequenceReg0b105s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B105S1_SequenceReg0b105s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B105S2 - PHY Initialization Engine (PIE) Instruction 105_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B105S2_SequenceReg0b105s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B105S2_SequenceReg0b105s2_SHIFT (0U)
/*! SequenceReg0b105s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B105S2_SequenceReg0b105s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B105S2_SequenceReg0b105s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B105S2_SequenceReg0b105s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B106S0 - PHY Initialization Engine (PIE) Instruction 106_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B106S0_SequenceReg0b106s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B106S0_SequenceReg0b106s0_SHIFT (0U)
/*! SequenceReg0b106s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B106S0_SequenceReg0b106s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B106S0_SequenceReg0b106s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B106S0_SequenceReg0b106s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B106S1 - PHY Initialization Engine (PIE) Instruction 106_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B106S1_SequenceReg0b106s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B106S1_SequenceReg0b106s1_SHIFT (0U)
/*! SequenceReg0b106s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B106S1_SequenceReg0b106s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B106S1_SequenceReg0b106s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B106S1_SequenceReg0b106s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B106S2 - PHY Initialization Engine (PIE) Instruction 106_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B106S2_SequenceReg0b106s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B106S2_SequenceReg0b106s2_SHIFT (0U)
/*! SequenceReg0b106s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B106S2_SequenceReg0b106s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B106S2_SequenceReg0b106s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B106S2_SequenceReg0b106s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B107S0 - PHY Initialization Engine (PIE) Instruction 107_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B107S0_SequenceReg0b107s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B107S0_SequenceReg0b107s0_SHIFT (0U)
/*! SequenceReg0b107s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B107S0_SequenceReg0b107s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B107S0_SequenceReg0b107s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B107S0_SequenceReg0b107s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B107S1 - PHY Initialization Engine (PIE) Instruction 107_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B107S1_SequenceReg0b107s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B107S1_SequenceReg0b107s1_SHIFT (0U)
/*! SequenceReg0b107s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B107S1_SequenceReg0b107s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B107S1_SequenceReg0b107s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B107S1_SequenceReg0b107s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B107S2 - PHY Initialization Engine (PIE) Instruction 107_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B107S2_SequenceReg0b107s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B107S2_SequenceReg0b107s2_SHIFT (0U)
/*! SequenceReg0b107s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B107S2_SequenceReg0b107s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B107S2_SequenceReg0b107s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B107S2_SequenceReg0b107s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B108S0 - PHY Initialization Engine (PIE) Instruction 108_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B108S0_SequenceReg0b108s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B108S0_SequenceReg0b108s0_SHIFT (0U)
/*! SequenceReg0b108s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B108S0_SequenceReg0b108s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B108S0_SequenceReg0b108s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B108S0_SequenceReg0b108s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B108S1 - PHY Initialization Engine (PIE) Instruction 108_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B108S1_SequenceReg0b108s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B108S1_SequenceReg0b108s1_SHIFT (0U)
/*! SequenceReg0b108s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B108S1_SequenceReg0b108s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B108S1_SequenceReg0b108s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B108S1_SequenceReg0b108s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B108S2 - PHY Initialization Engine (PIE) Instruction 108_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B108S2_SequenceReg0b108s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B108S2_SequenceReg0b108s2_SHIFT (0U)
/*! SequenceReg0b108s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B108S2_SequenceReg0b108s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B108S2_SequenceReg0b108s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B108S2_SequenceReg0b108s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B109S0 - PHY Initialization Engine (PIE) Instruction 109_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B109S0_SequenceReg0b109s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B109S0_SequenceReg0b109s0_SHIFT (0U)
/*! SequenceReg0b109s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B109S0_SequenceReg0b109s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B109S0_SequenceReg0b109s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B109S0_SequenceReg0b109s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B109S1 - PHY Initialization Engine (PIE) Instruction 109_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B109S1_SequenceReg0b109s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B109S1_SequenceReg0b109s1_SHIFT (0U)
/*! SequenceReg0b109s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B109S1_SequenceReg0b109s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B109S1_SequenceReg0b109s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B109S1_SequenceReg0b109s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B109S2 - PHY Initialization Engine (PIE) Instruction 109_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B109S2_SequenceReg0b109s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B109S2_SequenceReg0b109s2_SHIFT (0U)
/*! SequenceReg0b109s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B109S2_SequenceReg0b109s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B109S2_SequenceReg0b109s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B109S2_SequenceReg0b109s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B110S0 - PHY Initialization Engine (PIE) Instruction 110_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B110S0_SequenceReg0b110s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B110S0_SequenceReg0b110s0_SHIFT (0U)
/*! SequenceReg0b110s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B110S0_SequenceReg0b110s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B110S0_SequenceReg0b110s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B110S0_SequenceReg0b110s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B110S1 - PHY Initialization Engine (PIE) Instruction 110_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B110S1_SequenceReg0b110s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B110S1_SequenceReg0b110s1_SHIFT (0U)
/*! SequenceReg0b110s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B110S1_SequenceReg0b110s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B110S1_SequenceReg0b110s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B110S1_SequenceReg0b110s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B110S2 - PHY Initialization Engine (PIE) Instruction 110_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B110S2_SequenceReg0b110s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B110S2_SequenceReg0b110s2_SHIFT (0U)
/*! SequenceReg0b110s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B110S2_SequenceReg0b110s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B110S2_SequenceReg0b110s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B110S2_SequenceReg0b110s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B111S0 - PHY Initialization Engine (PIE) Instruction 111_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B111S0_SequenceReg0b111s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B111S0_SequenceReg0b111s0_SHIFT (0U)
/*! SequenceReg0b111s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B111S0_SequenceReg0b111s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B111S0_SequenceReg0b111s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B111S0_SequenceReg0b111s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B111S1 - PHY Initialization Engine (PIE) Instruction 111_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B111S1_SequenceReg0b111s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B111S1_SequenceReg0b111s1_SHIFT (0U)
/*! SequenceReg0b111s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B111S1_SequenceReg0b111s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B111S1_SequenceReg0b111s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B111S1_SequenceReg0b111s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B111S2 - PHY Initialization Engine (PIE) Instruction 111_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B111S2_SequenceReg0b111s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B111S2_SequenceReg0b111s2_SHIFT (0U)
/*! SequenceReg0b111s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B111S2_SequenceReg0b111s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B111S2_SequenceReg0b111s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B111S2_SequenceReg0b111s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B112S0 - PHY Initialization Engine (PIE) Instruction 112_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B112S0_SequenceReg0b112s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B112S0_SequenceReg0b112s0_SHIFT (0U)
/*! SequenceReg0b112s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B112S0_SequenceReg0b112s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B112S0_SequenceReg0b112s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B112S0_SequenceReg0b112s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B112S1 - PHY Initialization Engine (PIE) Instruction 112_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B112S1_SequenceReg0b112s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B112S1_SequenceReg0b112s1_SHIFT (0U)
/*! SequenceReg0b112s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B112S1_SequenceReg0b112s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B112S1_SequenceReg0b112s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B112S1_SequenceReg0b112s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B112S2 - PHY Initialization Engine (PIE) Instruction 112_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B112S2_SequenceReg0b112s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B112S2_SequenceReg0b112s2_SHIFT (0U)
/*! SequenceReg0b112s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B112S2_SequenceReg0b112s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B112S2_SequenceReg0b112s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B112S2_SequenceReg0b112s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B113S0 - PHY Initialization Engine (PIE) Instruction 113_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B113S0_SequenceReg0b113s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B113S0_SequenceReg0b113s0_SHIFT (0U)
/*! SequenceReg0b113s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B113S0_SequenceReg0b113s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B113S0_SequenceReg0b113s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B113S0_SequenceReg0b113s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B113S1 - PHY Initialization Engine (PIE) Instruction 113_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B113S1_SequenceReg0b113s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B113S1_SequenceReg0b113s1_SHIFT (0U)
/*! SequenceReg0b113s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B113S1_SequenceReg0b113s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B113S1_SequenceReg0b113s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B113S1_SequenceReg0b113s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B113S2 - PHY Initialization Engine (PIE) Instruction 113_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B113S2_SequenceReg0b113s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B113S2_SequenceReg0b113s2_SHIFT (0U)
/*! SequenceReg0b113s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B113S2_SequenceReg0b113s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B113S2_SequenceReg0b113s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B113S2_SequenceReg0b113s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B114S0 - PHY Initialization Engine (PIE) Instruction 114_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B114S0_SequenceReg0b114s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B114S0_SequenceReg0b114s0_SHIFT (0U)
/*! SequenceReg0b114s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B114S0_SequenceReg0b114s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B114S0_SequenceReg0b114s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B114S0_SequenceReg0b114s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B114S1 - PHY Initialization Engine (PIE) Instruction 114_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B114S1_SequenceReg0b114s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B114S1_SequenceReg0b114s1_SHIFT (0U)
/*! SequenceReg0b114s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B114S1_SequenceReg0b114s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B114S1_SequenceReg0b114s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B114S1_SequenceReg0b114s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B114S2 - PHY Initialization Engine (PIE) Instruction 114_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B114S2_SequenceReg0b114s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B114S2_SequenceReg0b114s2_SHIFT (0U)
/*! SequenceReg0b114s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B114S2_SequenceReg0b114s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B114S2_SequenceReg0b114s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B114S2_SequenceReg0b114s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B115S0 - PHY Initialization Engine (PIE) Instruction 115_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B115S0_SequenceReg0b115s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B115S0_SequenceReg0b115s0_SHIFT (0U)
/*! SequenceReg0b115s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B115S0_SequenceReg0b115s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B115S0_SequenceReg0b115s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B115S0_SequenceReg0b115s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B115S1 - PHY Initialization Engine (PIE) Instruction 115_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B115S1_SequenceReg0b115s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B115S1_SequenceReg0b115s1_SHIFT (0U)
/*! SequenceReg0b115s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B115S1_SequenceReg0b115s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B115S1_SequenceReg0b115s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B115S1_SequenceReg0b115s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B115S2 - PHY Initialization Engine (PIE) Instruction 115_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B115S2_SequenceReg0b115s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B115S2_SequenceReg0b115s2_SHIFT (0U)
/*! SequenceReg0b115s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B115S2_SequenceReg0b115s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B115S2_SequenceReg0b115s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B115S2_SequenceReg0b115s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B116S0 - PHY Initialization Engine (PIE) Instruction 116_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B116S0_SequenceReg0b116s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B116S0_SequenceReg0b116s0_SHIFT (0U)
/*! SequenceReg0b116s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B116S0_SequenceReg0b116s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B116S0_SequenceReg0b116s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B116S0_SequenceReg0b116s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B116S1 - PHY Initialization Engine (PIE) Instruction 116_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B116S1_SequenceReg0b116s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B116S1_SequenceReg0b116s1_SHIFT (0U)
/*! SequenceReg0b116s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B116S1_SequenceReg0b116s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B116S1_SequenceReg0b116s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B116S1_SequenceReg0b116s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B116S2 - PHY Initialization Engine (PIE) Instruction 116_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B116S2_SequenceReg0b116s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B116S2_SequenceReg0b116s2_SHIFT (0U)
/*! SequenceReg0b116s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B116S2_SequenceReg0b116s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B116S2_SequenceReg0b116s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B116S2_SequenceReg0b116s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B117S0 - PHY Initialization Engine (PIE) Instruction 117_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B117S0_SequenceReg0b117s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B117S0_SequenceReg0b117s0_SHIFT (0U)
/*! SequenceReg0b117s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B117S0_SequenceReg0b117s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B117S0_SequenceReg0b117s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B117S0_SequenceReg0b117s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B117S1 - PHY Initialization Engine (PIE) Instruction 117_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B117S1_SequenceReg0b117s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B117S1_SequenceReg0b117s1_SHIFT (0U)
/*! SequenceReg0b117s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B117S1_SequenceReg0b117s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B117S1_SequenceReg0b117s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B117S1_SequenceReg0b117s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B117S2 - PHY Initialization Engine (PIE) Instruction 117_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B117S2_SequenceReg0b117s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B117S2_SequenceReg0b117s2_SHIFT (0U)
/*! SequenceReg0b117s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B117S2_SequenceReg0b117s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B117S2_SequenceReg0b117s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B117S2_SequenceReg0b117s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B118S0 - PHY Initialization Engine (PIE) Instruction 118_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B118S0_SequenceReg0b118s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B118S0_SequenceReg0b118s0_SHIFT (0U)
/*! SequenceReg0b118s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B118S0_SequenceReg0b118s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B118S0_SequenceReg0b118s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B118S0_SequenceReg0b118s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B118S1 - PHY Initialization Engine (PIE) Instruction 118_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B118S1_SequenceReg0b118s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B118S1_SequenceReg0b118s1_SHIFT (0U)
/*! SequenceReg0b118s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B118S1_SequenceReg0b118s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B118S1_SequenceReg0b118s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B118S1_SequenceReg0b118s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B118S2 - PHY Initialization Engine (PIE) Instruction 118_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B118S2_SequenceReg0b118s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B118S2_SequenceReg0b118s2_SHIFT (0U)
/*! SequenceReg0b118s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B118S2_SequenceReg0b118s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B118S2_SequenceReg0b118s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B118S2_SequenceReg0b118s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B119S0 - PHY Initialization Engine (PIE) Instruction 119_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B119S0_SequenceReg0b119s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B119S0_SequenceReg0b119s0_SHIFT (0U)
/*! SequenceReg0b119s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B119S0_SequenceReg0b119s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B119S0_SequenceReg0b119s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B119S0_SequenceReg0b119s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B119S1 - PHY Initialization Engine (PIE) Instruction 119_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B119S1_SequenceReg0b119s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B119S1_SequenceReg0b119s1_SHIFT (0U)
/*! SequenceReg0b119s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B119S1_SequenceReg0b119s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B119S1_SequenceReg0b119s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B119S1_SequenceReg0b119s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B119S2 - PHY Initialization Engine (PIE) Instruction 119_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B119S2_SequenceReg0b119s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B119S2_SequenceReg0b119s2_SHIFT (0U)
/*! SequenceReg0b119s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B119S2_SequenceReg0b119s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B119S2_SequenceReg0b119s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B119S2_SequenceReg0b119s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B120S0 - PHY Initialization Engine (PIE) Instruction 120_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B120S0_SequenceReg0b120s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B120S0_SequenceReg0b120s0_SHIFT (0U)
/*! SequenceReg0b120s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B120S0_SequenceReg0b120s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B120S0_SequenceReg0b120s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B120S0_SequenceReg0b120s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B120S1 - PHY Initialization Engine (PIE) Instruction 120_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B120S1_SequenceReg0b120s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B120S1_SequenceReg0b120s1_SHIFT (0U)
/*! SequenceReg0b120s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B120S1_SequenceReg0b120s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B120S1_SequenceReg0b120s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B120S1_SequenceReg0b120s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B120S2 - PHY Initialization Engine (PIE) Instruction 120_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B120S2_SequenceReg0b120s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B120S2_SequenceReg0b120s2_SHIFT (0U)
/*! SequenceReg0b120s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B120S2_SequenceReg0b120s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B120S2_SequenceReg0b120s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B120S2_SequenceReg0b120s2_MASK)
/*! @} */

/*! @name SEQUENCEREG0B121S0 - PHY Initialization Engine (PIE) Instruction 121_0 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B121S0_SequenceReg0b121s0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B121S0_SequenceReg0b121s0_SHIFT (0U)
/*! SequenceReg0b121s0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B121S0_SequenceReg0b121s0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B121S0_SequenceReg0b121s0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B121S0_SequenceReg0b121s0_MASK)
/*! @} */

/*! @name SEQUENCEREG0B121S1 - PHY Initialization Engine (PIE) Instruction 121_1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B121S1_SequenceReg0b121s1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B121S1_SequenceReg0b121s1_SHIFT (0U)
/*! SequenceReg0b121s1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B121S1_SequenceReg0b121s1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B121S1_SequenceReg0b121s1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B121S1_SequenceReg0b121s1_MASK)
/*! @} */

/*! @name SEQUENCEREG0B121S2 - PHY Initialization Engine (PIE) Instruction 121_2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B121S2_SequenceReg0b121s2_MASK (0x1FFU)
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B121S2_SequenceReg0b121s2_SHIFT (0U)
/*! SequenceReg0b121s2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQUENCEREG0B121S2_SequenceReg0b121s2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQUENCEREG0B121S2_SequenceReg0b121s2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQUENCEREG0B121S2_SequenceReg0b121s2_MASK)
/*! @} */

/*! @name SEQ0BGPR1_P0 - PHY Initialization Engine (PIE) General Purpose Register 1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQ0BGPR1_P0_Seq0BGPR1_p0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQ0BGPR1_P0_Seq0BGPR1_p0_SHIFT (0U)
/*! Seq0BGPR1_p0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQ0BGPR1_P0_Seq0BGPR1_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQ0BGPR1_P0_Seq0BGPR1_p0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQ0BGPR1_P0_Seq0BGPR1_p0_MASK)
/*! @} */

/*! @name SEQ0BGPR2_P0 - PHY Initialization Engine (PIE) General Purpose Register 2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQ0BGPR2_P0_Seq0BGPR2_p0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQ0BGPR2_P0_Seq0BGPR2_p0_SHIFT (0U)
/*! Seq0BGPR2_p0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQ0BGPR2_P0_Seq0BGPR2_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQ0BGPR2_P0_Seq0BGPR2_p0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQ0BGPR2_P0_Seq0BGPR2_p0_MASK)
/*! @} */

/*! @name SEQ0BGPR3_P0 - PHY Initialization Engine (PIE) General Purpose Register 3 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQ0BGPR3_P0_Seq0BGPR3_p0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQ0BGPR3_P0_Seq0BGPR3_p0_SHIFT (0U)
/*! Seq0BGPR3_p0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQ0BGPR3_P0_Seq0BGPR3_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQ0BGPR3_P0_Seq0BGPR3_p0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQ0BGPR3_P0_Seq0BGPR3_p0_MASK)
/*! @} */

/*! @name SEQ0BGPR4_P0 - PHY Initialization Engine (PIE) General Purpose Register 4 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQ0BGPR4_P0_Seq0BGPR4_p0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQ0BGPR4_P0_Seq0BGPR4_p0_SHIFT (0U)
/*! Seq0BGPR4_p0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQ0BGPR4_P0_Seq0BGPR4_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQ0BGPR4_P0_Seq0BGPR4_p0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQ0BGPR4_P0_Seq0BGPR4_p0_MASK)
/*! @} */

/*! @name SEQ0BGPR5_P0 - PHY Initialization Engine (PIE) General Purpose Register 5 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQ0BGPR5_P0_Seq0BGPR5_p0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQ0BGPR5_P0_Seq0BGPR5_p0_SHIFT (0U)
/*! Seq0BGPR5_p0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQ0BGPR5_P0_Seq0BGPR5_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQ0BGPR5_P0_Seq0BGPR5_p0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQ0BGPR5_P0_Seq0BGPR5_p0_MASK)
/*! @} */

/*! @name SEQ0BGPR6_P0 - PHY Initialization Engine (PIE) General Purpose Register 6 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQ0BGPR6_P0_Seq0BGPR6_p0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQ0BGPR6_P0_Seq0BGPR6_p0_SHIFT (0U)
/*! Seq0BGPR6_p0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQ0BGPR6_P0_Seq0BGPR6_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQ0BGPR6_P0_Seq0BGPR6_p0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQ0BGPR6_P0_Seq0BGPR6_p0_MASK)
/*! @} */

/*! @name SEQ0BGPR7_P0 - PHY Initialization Engine (PIE) General Purpose Register 7 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQ0BGPR7_P0_Seq0BGPR7_p0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQ0BGPR7_P0_Seq0BGPR7_p0_SHIFT (0U)
/*! Seq0BGPR7_p0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQ0BGPR7_P0_Seq0BGPR7_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQ0BGPR7_P0_Seq0BGPR7_p0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQ0BGPR7_P0_Seq0BGPR7_p0_MASK)
/*! @} */

/*! @name SEQ0BGPR8_P0 - PHY Initialization Engine (PIE) General Purpose Register 8 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQ0BGPR8_P0_Seq0BGPR8_p0_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQ0BGPR8_P0_Seq0BGPR8_p0_SHIFT (0U)
/*! Seq0BGPR8_p0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQ0BGPR8_P0_Seq0BGPR8_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQ0BGPR8_P0_Seq0BGPR8_p0_SHIFT)) & DWC_DDRPHYA_INITENG_SEQ0BGPR8_P0_Seq0BGPR8_p0_MASK)
/*! @} */

/*! @name SEQ0BFIXEDADDRBITS - Address fill-ins for PIE CSR writes */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQ0BFIXEDADDRBITS_RFU_Seq0BFixedAddrBits_MASK (0x7FU)
#define DWC_DDRPHYA_INITENG_SEQ0BFIXEDADDRBITS_RFU_Seq0BFixedAddrBits_SHIFT (0U)
/*! RFU_Seq0BFixedAddrBits - RFU_Seq0BFixedAddrBits */
#define DWC_DDRPHYA_INITENG_SEQ0BFIXEDADDRBITS_RFU_Seq0BFixedAddrBits(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQ0BFIXEDADDRBITS_RFU_Seq0BFixedAddrBits_SHIFT)) & DWC_DDRPHYA_INITENG_SEQ0BFIXEDADDRBITS_RFU_Seq0BFixedAddrBits_MASK)
/*! @} */

/*! @name SEQ0BGPR1_P1 - PHY Initialization Engine (PIE) General Purpose Register 1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQ0BGPR1_P1_Seq0BGPR1_p1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQ0BGPR1_P1_Seq0BGPR1_p1_SHIFT (0U)
/*! Seq0BGPR1_p1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQ0BGPR1_P1_Seq0BGPR1_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQ0BGPR1_P1_Seq0BGPR1_p1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQ0BGPR1_P1_Seq0BGPR1_p1_MASK)
/*! @} */

/*! @name SEQ0BGPR2_P1 - PHY Initialization Engine (PIE) General Purpose Register 2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQ0BGPR2_P1_Seq0BGPR2_p1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQ0BGPR2_P1_Seq0BGPR2_p1_SHIFT (0U)
/*! Seq0BGPR2_p1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQ0BGPR2_P1_Seq0BGPR2_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQ0BGPR2_P1_Seq0BGPR2_p1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQ0BGPR2_P1_Seq0BGPR2_p1_MASK)
/*! @} */

/*! @name SEQ0BGPR3_P1 - PHY Initialization Engine (PIE) General Purpose Register 3 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQ0BGPR3_P1_Seq0BGPR3_p1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQ0BGPR3_P1_Seq0BGPR3_p1_SHIFT (0U)
/*! Seq0BGPR3_p1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQ0BGPR3_P1_Seq0BGPR3_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQ0BGPR3_P1_Seq0BGPR3_p1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQ0BGPR3_P1_Seq0BGPR3_p1_MASK)
/*! @} */

/*! @name SEQ0BGPR4_P1 - PHY Initialization Engine (PIE) General Purpose Register 4 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQ0BGPR4_P1_Seq0BGPR4_p1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQ0BGPR4_P1_Seq0BGPR4_p1_SHIFT (0U)
/*! Seq0BGPR4_p1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQ0BGPR4_P1_Seq0BGPR4_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQ0BGPR4_P1_Seq0BGPR4_p1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQ0BGPR4_P1_Seq0BGPR4_p1_MASK)
/*! @} */

/*! @name SEQ0BGPR5_P1 - PHY Initialization Engine (PIE) General Purpose Register 5 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQ0BGPR5_P1_Seq0BGPR5_p1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQ0BGPR5_P1_Seq0BGPR5_p1_SHIFT (0U)
/*! Seq0BGPR5_p1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQ0BGPR5_P1_Seq0BGPR5_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQ0BGPR5_P1_Seq0BGPR5_p1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQ0BGPR5_P1_Seq0BGPR5_p1_MASK)
/*! @} */

/*! @name SEQ0BGPR6_P1 - PHY Initialization Engine (PIE) General Purpose Register 6 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQ0BGPR6_P1_Seq0BGPR6_p1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQ0BGPR6_P1_Seq0BGPR6_p1_SHIFT (0U)
/*! Seq0BGPR6_p1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQ0BGPR6_P1_Seq0BGPR6_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQ0BGPR6_P1_Seq0BGPR6_p1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQ0BGPR6_P1_Seq0BGPR6_p1_MASK)
/*! @} */

/*! @name SEQ0BGPR7_P1 - PHY Initialization Engine (PIE) General Purpose Register 7 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQ0BGPR7_P1_Seq0BGPR7_p1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQ0BGPR7_P1_Seq0BGPR7_p1_SHIFT (0U)
/*! Seq0BGPR7_p1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQ0BGPR7_P1_Seq0BGPR7_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQ0BGPR7_P1_Seq0BGPR7_p1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQ0BGPR7_P1_Seq0BGPR7_p1_MASK)
/*! @} */

/*! @name SEQ0BGPR8_P1 - PHY Initialization Engine (PIE) General Purpose Register 8 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQ0BGPR8_P1_Seq0BGPR8_p1_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQ0BGPR8_P1_Seq0BGPR8_p1_SHIFT (0U)
/*! Seq0BGPR8_p1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQ0BGPR8_P1_Seq0BGPR8_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQ0BGPR8_P1_Seq0BGPR8_p1_SHIFT)) & DWC_DDRPHYA_INITENG_SEQ0BGPR8_P1_Seq0BGPR8_p1_MASK)
/*! @} */

/*! @name SEQ0BGPR1_P2 - PHY Initialization Engine (PIE) General Purpose Register 1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQ0BGPR1_P2_Seq0BGPR1_p2_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQ0BGPR1_P2_Seq0BGPR1_p2_SHIFT (0U)
/*! Seq0BGPR1_p2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQ0BGPR1_P2_Seq0BGPR1_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQ0BGPR1_P2_Seq0BGPR1_p2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQ0BGPR1_P2_Seq0BGPR1_p2_MASK)
/*! @} */

/*! @name SEQ0BGPR2_P2 - PHY Initialization Engine (PIE) General Purpose Register 2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQ0BGPR2_P2_Seq0BGPR2_p2_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQ0BGPR2_P2_Seq0BGPR2_p2_SHIFT (0U)
/*! Seq0BGPR2_p2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQ0BGPR2_P2_Seq0BGPR2_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQ0BGPR2_P2_Seq0BGPR2_p2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQ0BGPR2_P2_Seq0BGPR2_p2_MASK)
/*! @} */

/*! @name SEQ0BGPR3_P2 - PHY Initialization Engine (PIE) General Purpose Register 3 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQ0BGPR3_P2_Seq0BGPR3_p2_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQ0BGPR3_P2_Seq0BGPR3_p2_SHIFT (0U)
/*! Seq0BGPR3_p2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQ0BGPR3_P2_Seq0BGPR3_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQ0BGPR3_P2_Seq0BGPR3_p2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQ0BGPR3_P2_Seq0BGPR3_p2_MASK)
/*! @} */

/*! @name SEQ0BGPR4_P2 - PHY Initialization Engine (PIE) General Purpose Register 4 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQ0BGPR4_P2_Seq0BGPR4_p2_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQ0BGPR4_P2_Seq0BGPR4_p2_SHIFT (0U)
/*! Seq0BGPR4_p2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQ0BGPR4_P2_Seq0BGPR4_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQ0BGPR4_P2_Seq0BGPR4_p2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQ0BGPR4_P2_Seq0BGPR4_p2_MASK)
/*! @} */

/*! @name SEQ0BGPR5_P2 - PHY Initialization Engine (PIE) General Purpose Register 5 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQ0BGPR5_P2_Seq0BGPR5_p2_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQ0BGPR5_P2_Seq0BGPR5_p2_SHIFT (0U)
/*! Seq0BGPR5_p2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQ0BGPR5_P2_Seq0BGPR5_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQ0BGPR5_P2_Seq0BGPR5_p2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQ0BGPR5_P2_Seq0BGPR5_p2_MASK)
/*! @} */

/*! @name SEQ0BGPR6_P2 - PHY Initialization Engine (PIE) General Purpose Register 6 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQ0BGPR6_P2_Seq0BGPR6_p2_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQ0BGPR6_P2_Seq0BGPR6_p2_SHIFT (0U)
/*! Seq0BGPR6_p2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQ0BGPR6_P2_Seq0BGPR6_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQ0BGPR6_P2_Seq0BGPR6_p2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQ0BGPR6_P2_Seq0BGPR6_p2_MASK)
/*! @} */

/*! @name SEQ0BGPR7_P2 - PHY Initialization Engine (PIE) General Purpose Register 7 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQ0BGPR7_P2_Seq0BGPR7_p2_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQ0BGPR7_P2_Seq0BGPR7_p2_SHIFT (0U)
/*! Seq0BGPR7_p2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQ0BGPR7_P2_Seq0BGPR7_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQ0BGPR7_P2_Seq0BGPR7_p2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQ0BGPR7_P2_Seq0BGPR7_p2_MASK)
/*! @} */

/*! @name SEQ0BGPR8_P2 - PHY Initialization Engine (PIE) General Purpose Register 8 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQ0BGPR8_P2_Seq0BGPR8_p2_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQ0BGPR8_P2_Seq0BGPR8_p2_SHIFT (0U)
/*! Seq0BGPR8_p2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQ0BGPR8_P2_Seq0BGPR8_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQ0BGPR8_P2_Seq0BGPR8_p2_SHIFT)) & DWC_DDRPHYA_INITENG_SEQ0BGPR8_P2_Seq0BGPR8_p2_MASK)
/*! @} */

/*! @name SEQ0BGPR1_P3 - PHY Initialization Engine (PIE) General Purpose Register 1 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQ0BGPR1_P3_Seq0BGPR1_p3_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQ0BGPR1_P3_Seq0BGPR1_p3_SHIFT (0U)
/*! Seq0BGPR1_p3 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQ0BGPR1_P3_Seq0BGPR1_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQ0BGPR1_P3_Seq0BGPR1_p3_SHIFT)) & DWC_DDRPHYA_INITENG_SEQ0BGPR1_P3_Seq0BGPR1_p3_MASK)
/*! @} */

/*! @name SEQ0BGPR2_P3 - PHY Initialization Engine (PIE) General Purpose Register 2 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQ0BGPR2_P3_Seq0BGPR2_p3_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQ0BGPR2_P3_Seq0BGPR2_p3_SHIFT (0U)
/*! Seq0BGPR2_p3 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQ0BGPR2_P3_Seq0BGPR2_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQ0BGPR2_P3_Seq0BGPR2_p3_SHIFT)) & DWC_DDRPHYA_INITENG_SEQ0BGPR2_P3_Seq0BGPR2_p3_MASK)
/*! @} */

/*! @name SEQ0BGPR3_P3 - PHY Initialization Engine (PIE) General Purpose Register 3 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQ0BGPR3_P3_Seq0BGPR3_p3_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQ0BGPR3_P3_Seq0BGPR3_p3_SHIFT (0U)
/*! Seq0BGPR3_p3 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQ0BGPR3_P3_Seq0BGPR3_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQ0BGPR3_P3_Seq0BGPR3_p3_SHIFT)) & DWC_DDRPHYA_INITENG_SEQ0BGPR3_P3_Seq0BGPR3_p3_MASK)
/*! @} */

/*! @name SEQ0BGPR4_P3 - PHY Initialization Engine (PIE) General Purpose Register 4 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQ0BGPR4_P3_Seq0BGPR4_p3_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQ0BGPR4_P3_Seq0BGPR4_p3_SHIFT (0U)
/*! Seq0BGPR4_p3 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQ0BGPR4_P3_Seq0BGPR4_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQ0BGPR4_P3_Seq0BGPR4_p3_SHIFT)) & DWC_DDRPHYA_INITENG_SEQ0BGPR4_P3_Seq0BGPR4_p3_MASK)
/*! @} */

/*! @name SEQ0BGPR5_P3 - PHY Initialization Engine (PIE) General Purpose Register 5 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQ0BGPR5_P3_Seq0BGPR5_p3_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQ0BGPR5_P3_Seq0BGPR5_p3_SHIFT (0U)
/*! Seq0BGPR5_p3 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQ0BGPR5_P3_Seq0BGPR5_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQ0BGPR5_P3_Seq0BGPR5_p3_SHIFT)) & DWC_DDRPHYA_INITENG_SEQ0BGPR5_P3_Seq0BGPR5_p3_MASK)
/*! @} */

/*! @name SEQ0BGPR6_P3 - PHY Initialization Engine (PIE) General Purpose Register 6 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQ0BGPR6_P3_Seq0BGPR6_p3_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQ0BGPR6_P3_Seq0BGPR6_p3_SHIFT (0U)
/*! Seq0BGPR6_p3 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQ0BGPR6_P3_Seq0BGPR6_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQ0BGPR6_P3_Seq0BGPR6_p3_SHIFT)) & DWC_DDRPHYA_INITENG_SEQ0BGPR6_P3_Seq0BGPR6_p3_MASK)
/*! @} */

/*! @name SEQ0BGPR7_P3 - PHY Initialization Engine (PIE) General Purpose Register 7 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQ0BGPR7_P3_Seq0BGPR7_p3_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQ0BGPR7_P3_Seq0BGPR7_p3_SHIFT (0U)
/*! Seq0BGPR7_p3 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQ0BGPR7_P3_Seq0BGPR7_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQ0BGPR7_P3_Seq0BGPR7_p3_SHIFT)) & DWC_DDRPHYA_INITENG_SEQ0BGPR7_P3_Seq0BGPR7_p3_MASK)
/*! @} */

/*! @name SEQ0BGPR8_P3 - PHY Initialization Engine (PIE) General Purpose Register 8 */
/*! @{ */

#define DWC_DDRPHYA_INITENG_SEQ0BGPR8_P3_Seq0BGPR8_p3_MASK (0xFFFFU)
#define DWC_DDRPHYA_INITENG_SEQ0BGPR8_P3_Seq0BGPR8_p3_SHIFT (0U)
/*! Seq0BGPR8_p3 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() to support frequency changes. */
#define DWC_DDRPHYA_INITENG_SEQ0BGPR8_P3_Seq0BGPR8_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_INITENG_SEQ0BGPR8_P3_Seq0BGPR8_p3_SHIFT)) & DWC_DDRPHYA_INITENG_SEQ0BGPR8_P3_Seq0BGPR8_p3_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group DWC_DDRPHYA_INITENG_Register_Masks */


/*!
 * @}
 */ /* end of group DWC_DDRPHYA_INITENG_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic pop
  #else
    #pragma pop
  #endif
#elif defined(__GNUC__)
  /* leave anonymous unions enabled */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=default
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_DWC_DDRPHYA_INITENG_H_ */
