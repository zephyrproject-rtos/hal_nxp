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
**         CMSIS Peripheral Access Layer for DWC_DDRPHYA_ACSM
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
 * @file PERI_DWC_DDRPHYA_ACSM.h
 * @version 1.0
 * @date 2024-11-15
 * @brief CMSIS Peripheral Access Layer for DWC_DDRPHYA_ACSM
 *
 * CMSIS Peripheral Access Layer for DWC_DDRPHYA_ACSM
 */

#if !defined(PERI_DWC_DDRPHYA_ACSM_H_)
#define PERI_DWC_DDRPHYA_ACSM_H_                 /**< Symbol preventing repeated inclusion */

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
   -- DWC_DDRPHYA_ACSM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DWC_DDRPHYA_ACSM_Peripheral_Access_Layer DWC_DDRPHYA_ACSM Peripheral Access Layer
 * @{
 */

/** DWC_DDRPHYA_ACSM - Register Layout Typedef */
typedef struct {
  __IO uint16_t ACSMSEQ0X0;                        /**< ACSM sequencer instruction [15:0]., offset: 0x0 */
  __IO uint16_t ACSMSEQ0X1;                        /**< ACSM sequencer instruction [15:0]., offset: 0x2 */
  __IO uint16_t ACSMSEQ0X2;                        /**< ACSM sequencer instruction [15:0]., offset: 0x4 */
  __IO uint16_t ACSMSEQ0X3;                        /**< ACSM sequencer instruction [15:0]., offset: 0x6 */
  __IO uint16_t ACSMSEQ0X4;                        /**< ACSM sequencer instruction [15:0]., offset: 0x8 */
  __IO uint16_t ACSMSEQ0X5;                        /**< ACSM sequencer instruction [15:0]., offset: 0xA */
  __IO uint16_t ACSMSEQ0X6;                        /**< ACSM sequencer instruction [15:0]., offset: 0xC */
  __IO uint16_t ACSMSEQ0X7;                        /**< ACSM sequencer instruction [15:0]., offset: 0xE */
  __IO uint16_t ACSMSEQ0X8;                        /**< ACSM sequencer instruction [15:0]., offset: 0x10 */
  __IO uint16_t ACSMSEQ0X9;                        /**< ACSM sequencer instruction [15:0]., offset: 0x12 */
  __IO uint16_t ACSMSEQ0X10;                       /**< ACSM sequencer instruction [15:0]., offset: 0x14 */
  __IO uint16_t ACSMSEQ0X11;                       /**< ACSM sequencer instruction [15:0]., offset: 0x16 */
  __IO uint16_t ACSMSEQ0X12;                       /**< ACSM sequencer instruction [15:0]., offset: 0x18 */
  __IO uint16_t ACSMSEQ0X13;                       /**< ACSM sequencer instruction [15:0]., offset: 0x1A */
  __IO uint16_t ACSMSEQ0X14;                       /**< ACSM sequencer instruction [15:0]., offset: 0x1C */
  __IO uint16_t ACSMSEQ0X15;                       /**< ACSM sequencer instruction [15:0]., offset: 0x1E */
  __IO uint16_t ACSMSEQ0X16;                       /**< ACSM sequencer instruction [15:0]., offset: 0x20 */
  __IO uint16_t ACSMSEQ0X17;                       /**< ACSM sequencer instruction [15:0]., offset: 0x22 */
  __IO uint16_t ACSMSEQ0X18;                       /**< ACSM sequencer instruction [15:0]., offset: 0x24 */
  __IO uint16_t ACSMSEQ0X19;                       /**< ACSM sequencer instruction [15:0]., offset: 0x26 */
  __IO uint16_t ACSMSEQ0X20;                       /**< ACSM sequencer instruction [15:0]., offset: 0x28 */
  __IO uint16_t ACSMSEQ0X21;                       /**< ACSM sequencer instruction [15:0]., offset: 0x2A */
  __IO uint16_t ACSMSEQ0X22;                       /**< ACSM sequencer instruction [15:0]., offset: 0x2C */
  __IO uint16_t ACSMSEQ0X23;                       /**< ACSM sequencer instruction [15:0]., offset: 0x2E */
  __IO uint16_t ACSMSEQ0X24;                       /**< ACSM sequencer instruction [15:0]., offset: 0x30 */
  __IO uint16_t ACSMSEQ0X25;                       /**< ACSM sequencer instruction [15:0]., offset: 0x32 */
  __IO uint16_t ACSMSEQ0X26;                       /**< ACSM sequencer instruction [15:0]., offset: 0x34 */
  __IO uint16_t ACSMSEQ0X27;                       /**< ACSM sequencer instruction [15:0]., offset: 0x36 */
  __IO uint16_t ACSMSEQ0X28;                       /**< ACSM sequencer instruction [15:0]., offset: 0x38 */
  __IO uint16_t ACSMSEQ0X29;                       /**< ACSM sequencer instruction [15:0]., offset: 0x3A */
  __IO uint16_t ACSMSEQ0X30;                       /**< ACSM sequencer instruction [15:0]., offset: 0x3C */
  __IO uint16_t ACSMSEQ0X31;                       /**< ACSM sequencer instruction [15:0]., offset: 0x3E */
  __IO uint16_t ACSMSEQ1X0;                        /**< ACSM sequencer instruction [31:16]., offset: 0x40 */
  __IO uint16_t ACSMSEQ1X1;                        /**< ACSM sequencer instruction [31:16]., offset: 0x42 */
  __IO uint16_t ACSMSEQ1X2;                        /**< ACSM sequencer instruction [31:16]., offset: 0x44 */
  __IO uint16_t ACSMSEQ1X3;                        /**< ACSM sequencer instruction [31:16]., offset: 0x46 */
  __IO uint16_t ACSMSEQ1X4;                        /**< ACSM sequencer instruction [31:16]., offset: 0x48 */
  __IO uint16_t ACSMSEQ1X5;                        /**< ACSM sequencer instruction [31:16]., offset: 0x4A */
  __IO uint16_t ACSMSEQ1X6;                        /**< ACSM sequencer instruction [31:16]., offset: 0x4C */
  __IO uint16_t ACSMSEQ1X7;                        /**< ACSM sequencer instruction [31:16]., offset: 0x4E */
  __IO uint16_t ACSMSEQ1X8;                        /**< ACSM sequencer instruction [31:16]., offset: 0x50 */
  __IO uint16_t ACSMSEQ1X9;                        /**< ACSM sequencer instruction [31:16]., offset: 0x52 */
  __IO uint16_t ACSMSEQ1X10;                       /**< ACSM sequencer instruction [31:16]., offset: 0x54 */
  __IO uint16_t ACSMSEQ1X11;                       /**< ACSM sequencer instruction [31:16]., offset: 0x56 */
  __IO uint16_t ACSMSEQ1X12;                       /**< ACSM sequencer instruction [31:16]., offset: 0x58 */
  __IO uint16_t ACSMSEQ1X13;                       /**< ACSM sequencer instruction [31:16]., offset: 0x5A */
  __IO uint16_t ACSMSEQ1X14;                       /**< ACSM sequencer instruction [31:16]., offset: 0x5C */
  __IO uint16_t ACSMSEQ1X15;                       /**< ACSM sequencer instruction [31:16]., offset: 0x5E */
  __IO uint16_t ACSMSEQ1X16;                       /**< ACSM sequencer instruction [31:16]., offset: 0x60 */
  __IO uint16_t ACSMSEQ1X17;                       /**< ACSM sequencer instruction [31:16]., offset: 0x62 */
  __IO uint16_t ACSMSEQ1X18;                       /**< ACSM sequencer instruction [31:16]., offset: 0x64 */
  __IO uint16_t ACSMSEQ1X19;                       /**< ACSM sequencer instruction [31:16]., offset: 0x66 */
  __IO uint16_t ACSMSEQ1X20;                       /**< ACSM sequencer instruction [31:16]., offset: 0x68 */
  __IO uint16_t ACSMSEQ1X21;                       /**< ACSM sequencer instruction [31:16]., offset: 0x6A */
  __IO uint16_t ACSMSEQ1X22;                       /**< ACSM sequencer instruction [31:16]., offset: 0x6C */
  __IO uint16_t ACSMSEQ1X23;                       /**< ACSM sequencer instruction [31:16]., offset: 0x6E */
  __IO uint16_t ACSMSEQ1X24;                       /**< ACSM sequencer instruction [31:16]., offset: 0x70 */
  __IO uint16_t ACSMSEQ1X25;                       /**< ACSM sequencer instruction [31:16]., offset: 0x72 */
  __IO uint16_t ACSMSEQ1X26;                       /**< ACSM sequencer instruction [31:16]., offset: 0x74 */
  __IO uint16_t ACSMSEQ1X27;                       /**< ACSM sequencer instruction [31:16]., offset: 0x76 */
  __IO uint16_t ACSMSEQ1X28;                       /**< ACSM sequencer instruction [31:16]., offset: 0x78 */
  __IO uint16_t ACSMSEQ1X29;                       /**< ACSM sequencer instruction [31:16]., offset: 0x7A */
  __IO uint16_t ACSMSEQ1X30;                       /**< ACSM sequencer instruction [31:16]., offset: 0x7C */
  __IO uint16_t ACSMSEQ1X31;                       /**< ACSM sequencer instruction [31:16]., offset: 0x7E */
  __IO uint16_t ACSMSEQ2X0;                        /**< ACSM sequencer instruction [47:32]., offset: 0x80 */
  __IO uint16_t ACSMSEQ2X1;                        /**< ACSM sequencer instruction [47:32]., offset: 0x82 */
  __IO uint16_t ACSMSEQ2X2;                        /**< ACSM sequencer instruction [47:32]., offset: 0x84 */
  __IO uint16_t ACSMSEQ2X3;                        /**< ACSM sequencer instruction [47:32]., offset: 0x86 */
  __IO uint16_t ACSMSEQ2X4;                        /**< ACSM sequencer instruction [47:32]., offset: 0x88 */
  __IO uint16_t ACSMSEQ2X5;                        /**< ACSM sequencer instruction [47:32]., offset: 0x8A */
  __IO uint16_t ACSMSEQ2X6;                        /**< ACSM sequencer instruction [47:32]., offset: 0x8C */
  __IO uint16_t ACSMSEQ2X7;                        /**< ACSM sequencer instruction [47:32]., offset: 0x8E */
  __IO uint16_t ACSMSEQ2X8;                        /**< ACSM sequencer instruction [47:32]., offset: 0x90 */
  __IO uint16_t ACSMSEQ2X9;                        /**< ACSM sequencer instruction [47:32]., offset: 0x92 */
  __IO uint16_t ACSMSEQ2X10;                       /**< ACSM sequencer instruction [47:32]., offset: 0x94 */
  __IO uint16_t ACSMSEQ2X11;                       /**< ACSM sequencer instruction [47:32]., offset: 0x96 */
  __IO uint16_t ACSMSEQ2X12;                       /**< ACSM sequencer instruction [47:32]., offset: 0x98 */
  __IO uint16_t ACSMSEQ2X13;                       /**< ACSM sequencer instruction [47:32]., offset: 0x9A */
  __IO uint16_t ACSMSEQ2X14;                       /**< ACSM sequencer instruction [47:32]., offset: 0x9C */
  __IO uint16_t ACSMSEQ2X15;                       /**< ACSM sequencer instruction [47:32]., offset: 0x9E */
  __IO uint16_t ACSMSEQ2X16;                       /**< ACSM sequencer instruction [47:32]., offset: 0xA0 */
  __IO uint16_t ACSMSEQ2X17;                       /**< ACSM sequencer instruction [47:32]., offset: 0xA2 */
  __IO uint16_t ACSMSEQ2X18;                       /**< ACSM sequencer instruction [47:32]., offset: 0xA4 */
  __IO uint16_t ACSMSEQ2X19;                       /**< ACSM sequencer instruction [47:32]., offset: 0xA6 */
  __IO uint16_t ACSMSEQ2X20;                       /**< ACSM sequencer instruction [47:32]., offset: 0xA8 */
  __IO uint16_t ACSMSEQ2X21;                       /**< ACSM sequencer instruction [47:32]., offset: 0xAA */
  __IO uint16_t ACSMSEQ2X22;                       /**< ACSM sequencer instruction [47:32]., offset: 0xAC */
  __IO uint16_t ACSMSEQ2X23;                       /**< ACSM sequencer instruction [47:32]., offset: 0xAE */
  __IO uint16_t ACSMSEQ2X24;                       /**< ACSM sequencer instruction [47:32]., offset: 0xB0 */
  __IO uint16_t ACSMSEQ2X25;                       /**< ACSM sequencer instruction [47:32]., offset: 0xB2 */
  __IO uint16_t ACSMSEQ2X26;                       /**< ACSM sequencer instruction [47:32]., offset: 0xB4 */
  __IO uint16_t ACSMSEQ2X27;                       /**< ACSM sequencer instruction [47:32]., offset: 0xB6 */
  __IO uint16_t ACSMSEQ2X28;                       /**< ACSM sequencer instruction [47:32]., offset: 0xB8 */
  __IO uint16_t ACSMSEQ2X29;                       /**< ACSM sequencer instruction [47:32]., offset: 0xBA */
  __IO uint16_t ACSMSEQ2X30;                       /**< ACSM sequencer instruction [47:32]., offset: 0xBC */
  __IO uint16_t ACSMSEQ2X31;                       /**< ACSM sequencer instruction [47:32]., offset: 0xBE */
  __IO uint16_t ACSMSEQ3X0;                        /**< ACSM sequencer instruction [63:48]., offset: 0xC0 */
  __IO uint16_t ACSMSEQ3X1;                        /**< ACSM sequencer instruction [63:48]., offset: 0xC2 */
  __IO uint16_t ACSMSEQ3X2;                        /**< ACSM sequencer instruction [63:48]., offset: 0xC4 */
  __IO uint16_t ACSMSEQ3X3;                        /**< ACSM sequencer instruction [63:48]., offset: 0xC6 */
  __IO uint16_t ACSMSEQ3X4;                        /**< ACSM sequencer instruction [63:48]., offset: 0xC8 */
  __IO uint16_t ACSMSEQ3X5;                        /**< ACSM sequencer instruction [63:48]., offset: 0xCA */
  __IO uint16_t ACSMSEQ3X6;                        /**< ACSM sequencer instruction [63:48]., offset: 0xCC */
  __IO uint16_t ACSMSEQ3X7;                        /**< ACSM sequencer instruction [63:48]., offset: 0xCE */
  __IO uint16_t ACSMSEQ3X8;                        /**< ACSM sequencer instruction [63:48]., offset: 0xD0 */
  __IO uint16_t ACSMSEQ3X9;                        /**< ACSM sequencer instruction [63:48]., offset: 0xD2 */
  __IO uint16_t ACSMSEQ3X10;                       /**< ACSM sequencer instruction [63:48]., offset: 0xD4 */
  __IO uint16_t ACSMSEQ3X11;                       /**< ACSM sequencer instruction [63:48]., offset: 0xD6 */
  __IO uint16_t ACSMSEQ3X12;                       /**< ACSM sequencer instruction [63:48]., offset: 0xD8 */
  __IO uint16_t ACSMSEQ3X13;                       /**< ACSM sequencer instruction [63:48]., offset: 0xDA */
  __IO uint16_t ACSMSEQ3X14;                       /**< ACSM sequencer instruction [63:48]., offset: 0xDC */
  __IO uint16_t ACSMSEQ3X15;                       /**< ACSM sequencer instruction [63:48]., offset: 0xDE */
  __IO uint16_t ACSMSEQ3X16;                       /**< ACSM sequencer instruction [63:48]., offset: 0xE0 */
  __IO uint16_t ACSMSEQ3X17;                       /**< ACSM sequencer instruction [63:48]., offset: 0xE2 */
  __IO uint16_t ACSMSEQ3X18;                       /**< ACSM sequencer instruction [63:48]., offset: 0xE4 */
  __IO uint16_t ACSMSEQ3X19;                       /**< ACSM sequencer instruction [63:48]., offset: 0xE6 */
  __IO uint16_t ACSMSEQ3X20;                       /**< ACSM sequencer instruction [63:48]., offset: 0xE8 */
  __IO uint16_t ACSMSEQ3X21;                       /**< ACSM sequencer instruction [63:48]., offset: 0xEA */
  __IO uint16_t ACSMSEQ3X22;                       /**< ACSM sequencer instruction [63:48]., offset: 0xEC */
  __IO uint16_t ACSMSEQ3X23;                       /**< ACSM sequencer instruction [63:48]., offset: 0xEE */
  __IO uint16_t ACSMSEQ3X24;                       /**< ACSM sequencer instruction [63:48]., offset: 0xF0 */
  __IO uint16_t ACSMSEQ3X25;                       /**< ACSM sequencer instruction [63:48]., offset: 0xF2 */
  __IO uint16_t ACSMSEQ3X26;                       /**< ACSM sequencer instruction [63:48]., offset: 0xF4 */
  __IO uint16_t ACSMSEQ3X27;                       /**< ACSM sequencer instruction [63:48]., offset: 0xF6 */
  __IO uint16_t ACSMSEQ3X28;                       /**< ACSM sequencer instruction [63:48]., offset: 0xF8 */
  __IO uint16_t ACSMSEQ3X29;                       /**< ACSM sequencer instruction [63:48]., offset: 0xFA */
  __IO uint16_t ACSMSEQ3X30;                       /**< ACSM sequencer instruction [63:48]., offset: 0xFC */
  __IO uint16_t ACSMSEQ3X31;                       /**< ACSM sequencer instruction [63:48]., offset: 0xFE */
  __IO uint16_t ACSMPLAYBACK0X0_P0;                /**< ACSM Playback Engine Register 0 for Entry 0, offset: 0x100 */
  __IO uint16_t ACSMPLAYBACK1X0_P0;                /**< ACSM Playback Engine Register 1 for Entry 0, offset: 0x102 */
  __IO uint16_t ACSMPLAYBACK0X1_P0;                /**< ACSM Playback Engine Register 0 for Entry 1, offset: 0x104 */
  __IO uint16_t ACSMPLAYBACK1X1_P0;                /**< ACSM Playback Engine Register 1 for Entry 1, offset: 0x106 */
  __IO uint16_t ACSMPLAYBACK0X2_P0;                /**< ACSM Playback Engine Register 0 for Entry 2, offset: 0x108 */
  __IO uint16_t ACSMPLAYBACK1X2_P0;                /**< ACSM Playback Engine Register 1 for Entry 2, offset: 0x10A */
  __IO uint16_t ACSMPLAYBACK0X3_P0;                /**< ACSM Playback Engine Register 0 for Entry 3, offset: 0x10C */
  __IO uint16_t ACSMPLAYBACK1X3_P0;                /**< ACSM Playback Engine Register 1 for Entry 3, offset: 0x10E */
  __IO uint16_t ACSMPLAYBACK0X4_P0;                /**< ACSM Playback Engine Register 0 for Entry 4, offset: 0x110 */
  __IO uint16_t ACSMPLAYBACK1X4_P0;                /**< ACSM Playback Engine Register 1 for Entry 4, offset: 0x112 */
  __IO uint16_t ACSMPLAYBACK0X5_P0;                /**< ACSM Playback Engine Register 0 for Entry 5, offset: 0x114 */
  __IO uint16_t ACSMPLAYBACK1X5_P0;                /**< ACSM Playback Engine Register 1 for Entry 5, offset: 0x116 */
  __IO uint16_t ACSMPLAYBACK0X6_P0;                /**< ACSM Playback Engine Register 0 for Entry 6, offset: 0x118 */
  __IO uint16_t ACSMPLAYBACK1X6_P0;                /**< ACSM Playback Engine Register 1 for Entry 6, offset: 0x11A */
  __IO uint16_t ACSMPLAYBACK0X7_P0;                /**< ACSM Playback Engine Register 0 for Entry 7, offset: 0x11C */
  __IO uint16_t ACSMPLAYBACK1X7_P0;                /**< ACSM Playback Engine Register 1 for Entry 7, offset: 0x11E */
  __IO uint16_t ACSMPSTATEOVREN;                   /**< ACSM Pstate Override Enable, offset: 0x120 */
  __IO uint16_t ACSMPSTATEOVRVAL;                  /**< ACSM Pstate Override and Control, offset: 0x122 */
       uint8_t RESERVED_0[92];
  __IO uint16_t ACSMCTRL23;                        /**< ACSM CS instruction field mask., offset: 0x180 */
       uint8_t RESERVED_1[2];
  __IO uint16_t ACSMCKEVAL;                        /**< ACSM CKE value control, offset: 0x184 */
       uint8_t RESERVED_2[10];
  __IO uint16_t LOWSPEEDCLOCKDIVIDER;              /**< ACSM low speed clock divider, offset: 0x190 */
       uint8_t RESERVED_3[14];
  __IO uint16_t ACSMCSMAPCTRL0;                    /**< ACSM CS to Dest/ODT map., offset: 0x1A0 */
  __IO uint16_t ACSMCSMAPCTRL1;                    /**< ACSM CS to Dest/ODT map., offset: 0x1A2 */
  __IO uint16_t ACSMCSMAPCTRL2;                    /**< ACSM CS to Dest/ODT map., offset: 0x1A4 */
  __IO uint16_t ACSMCSMAPCTRL3;                    /**< ACSM CS to Dest/ODT map., offset: 0x1A6 */
  __IO uint16_t ACSMCSMAPCTRL4;                    /**< ACSM CS to Dest/ODT map., offset: 0x1A8 */
  __IO uint16_t ACSMCSMAPCTRL5;                    /**< ACSM CS to Dest/ODT map., offset: 0x1AA */
  __IO uint16_t ACSMCSMAPCTRL6;                    /**< ACSM CS to Dest/ODT map., offset: 0x1AC */
  __IO uint16_t ACSMCSMAPCTRL7;                    /**< ACSM CS to Dest/ODT map., offset: 0x1AE */
  __IO uint16_t ACSMCSMAPCTRL8;                    /**< ACSM CS to Dest/ODT map., offset: 0x1B0 */
  __IO uint16_t ACSMCSMAPCTRL9;                    /**< ACSM CS to Dest/ODT map., offset: 0x1B2 */
  __IO uint16_t ACSMCSMAPCTRL10;                   /**< ACSM CS to Dest/ODT map., offset: 0x1B4 */
  __IO uint16_t ACSMCSMAPCTRL11;                   /**< ACSM CS to Dest/ODT map., offset: 0x1B6 */
  __IO uint16_t ACSMCSMAPCTRL12;                   /**< ACSM CS to Dest/ODT map., offset: 0x1B8 */
  __IO uint16_t ACSMCSMAPCTRL13;                   /**< ACSM CS to Dest/ODT map., offset: 0x1BA */
  __IO uint16_t ACSMCSMAPCTRL14;                   /**< ACSM CS to Dest/ODT map., offset: 0x1BC */
  __IO uint16_t ACSMCSMAPCTRL15;                   /**< ACSM CS to Dest/ODT map., offset: 0x1BE */
  __IO uint16_t ACSMODTCTRL0;                      /**< ACSM CS to ODT pattern map., offset: 0x1C0 */
  __IO uint16_t ACSMODTCTRL1;                      /**< ACSM CS to ODT pattern map., offset: 0x1C2 */
  __IO uint16_t ACSMODTCTRL2;                      /**< ACSM CS to ODT pattern map., offset: 0x1C4 */
  __IO uint16_t ACSMODTCTRL3;                      /**< ACSM CS to ODT pattern map., offset: 0x1C6 */
  __IO uint16_t ACSMODTCTRL4;                      /**< ACSM CS to ODT pattern map., offset: 0x1C8 */
  __IO uint16_t ACSMODTCTRL5;                      /**< ACSM CS to ODT pattern map., offset: 0x1CA */
  __IO uint16_t ACSMODTCTRL6;                      /**< ACSM CS to ODT pattern map., offset: 0x1CC */
  __IO uint16_t ACSMODTCTRL7;                      /**< ACSM CS to ODT pattern map., offset: 0x1CE */
  __IO uint16_t ACSMODTCTRL8;                      /**< ACSM ODT start/duration control., offset: 0x1D0 */
  __IO uint16_t ACSMCTRL16;                        /**< ACSM high address bits training control., offset: 0x1D2 */
  __IO uint16_t LOWSPEEDCLOCKSTOPVAL;              /**< ACSM low speed clock divider stopped value, offset: 0x1D4 */
  __I  uint16_t ACSMCTRL18;                        /**< ACSM sequence done., offset: 0x1D6 */
  __IO uint16_t ACSMCTRL19;                        /**< ACSM test observability control., offset: 0x1D8 */
  __I  uint16_t ACSMCTRL20;                        /**< ACSM test visibility port., offset: 0x1DA */
  __IO uint16_t ACSMCTRL21;                        /**< ACSM Legacy CS to DIMM mapping., offset: 0x1DC */
  __IO uint16_t ACSMCTRL22;                        /**< ACSM Legacy CS to DIMM mapping., offset: 0x1DE */
  __IO uint16_t ACSMCTRL0;                         /**< ACSM special operation modes and control., offset: 0x1E0 */
  __IO uint16_t ACSMCTRL1;                         /**< ACSM sequence repitition count., offset: 0x1E2 */
  __IO uint16_t ACSMCTRL2;                         /**< ACSM sequence start pointer., offset: 0x1E4 */
  __IO uint16_t ACSMCTRL3;                         /**< ACSM sequence loop pointer., offset: 0x1E6 */
  __IO uint16_t ACSMCTRL4;                         /**< ACSM sequence end loop pointer., offset: 0x1E8 */
  __IO uint16_t ACSMCTRL5;                         /**< ACSM read latency control., offset: 0x1EA */
  __IO uint16_t ACSMCTRL6;                         /**< ACSM write latency control., offset: 0x1EC */
  __IO uint16_t ACSMCTRL7;                         /**< ACSM algorithmic address generator control - row adr., offset: 0x1EE */
  __IO uint16_t ACSMCTRL8;                         /**< ACSM algorithmic address seed - row adr., offset: 0x1F0 */
  __IO uint16_t ACSMCTRL9;                         /**< ACSM algorithmic address generator control - col adr., offset: 0x1F2 */
  __IO uint16_t ACSMCTRL10;                        /**< ACSM algorithmic address seed - row adr., offset: 0x1F4 */
  __IO uint16_t ACSMCTRL11;                        /**< ACSM algorithmic address increment val - row/col adr., offset: 0x1F6 */
  __IO uint16_t ACSMCTRL12;                        /**< ACSM algorithmic address control and seed - bank adr., offset: 0x1F8 */
  __IO uint16_t ACSMCTRL13;                        /**< ACSM CKE enable mask., offset: 0x1FA */
  __IO uint16_t ACSMCTRL14;                        /**< ACSM algorithmic address high order config bits - row adr., offset: 0x1FC */
  __IO uint16_t ACSMCTRL15;                        /**< ACSM algorithmic address high order seed bits - row adr., offset: 0x1FE */
       uint8_t RESERVED_4[2096896];
  __IO uint16_t ACSMPLAYBACK0X0_P1;                /**< ACSM Playback Engine Register 0 for Entry 0, offset: 0x200100 */
  __IO uint16_t ACSMPLAYBACK1X0_P1;                /**< ACSM Playback Engine Register 1 for Entry 0, offset: 0x200102 */
  __IO uint16_t ACSMPLAYBACK0X1_P1;                /**< ACSM Playback Engine Register 0 for Entry 1, offset: 0x200104 */
  __IO uint16_t ACSMPLAYBACK1X1_P1;                /**< ACSM Playback Engine Register 1 for Entry 1, offset: 0x200106 */
  __IO uint16_t ACSMPLAYBACK0X2_P1;                /**< ACSM Playback Engine Register 0 for Entry 2, offset: 0x200108 */
  __IO uint16_t ACSMPLAYBACK1X2_P1;                /**< ACSM Playback Engine Register 1 for Entry 2, offset: 0x20010A */
  __IO uint16_t ACSMPLAYBACK0X3_P1;                /**< ACSM Playback Engine Register 0 for Entry 3, offset: 0x20010C */
  __IO uint16_t ACSMPLAYBACK1X3_P1;                /**< ACSM Playback Engine Register 1 for Entry 3, offset: 0x20010E */
  __IO uint16_t ACSMPLAYBACK0X4_P1;                /**< ACSM Playback Engine Register 0 for Entry 4, offset: 0x200110 */
  __IO uint16_t ACSMPLAYBACK1X4_P1;                /**< ACSM Playback Engine Register 1 for Entry 4, offset: 0x200112 */
  __IO uint16_t ACSMPLAYBACK0X5_P1;                /**< ACSM Playback Engine Register 0 for Entry 5, offset: 0x200114 */
  __IO uint16_t ACSMPLAYBACK1X5_P1;                /**< ACSM Playback Engine Register 1 for Entry 5, offset: 0x200116 */
  __IO uint16_t ACSMPLAYBACK0X6_P1;                /**< ACSM Playback Engine Register 0 for Entry 6, offset: 0x200118 */
  __IO uint16_t ACSMPLAYBACK1X6_P1;                /**< ACSM Playback Engine Register 1 for Entry 6, offset: 0x20011A */
  __IO uint16_t ACSMPLAYBACK0X7_P1;                /**< ACSM Playback Engine Register 0 for Entry 7, offset: 0x20011C */
  __IO uint16_t ACSMPLAYBACK1X7_P1;                /**< ACSM Playback Engine Register 1 for Entry 7, offset: 0x20011E */
       uint8_t RESERVED_5[2097120];
  __IO uint16_t ACSMPLAYBACK0X0_P2;                /**< ACSM Playback Engine Register 0 for Entry 0, offset: 0x400100 */
  __IO uint16_t ACSMPLAYBACK1X0_P2;                /**< ACSM Playback Engine Register 1 for Entry 0, offset: 0x400102 */
  __IO uint16_t ACSMPLAYBACK0X1_P2;                /**< ACSM Playback Engine Register 0 for Entry 1, offset: 0x400104 */
  __IO uint16_t ACSMPLAYBACK1X1_P2;                /**< ACSM Playback Engine Register 1 for Entry 1, offset: 0x400106 */
  __IO uint16_t ACSMPLAYBACK0X2_P2;                /**< ACSM Playback Engine Register 0 for Entry 2, offset: 0x400108 */
  __IO uint16_t ACSMPLAYBACK1X2_P2;                /**< ACSM Playback Engine Register 1 for Entry 2, offset: 0x40010A */
  __IO uint16_t ACSMPLAYBACK0X3_P2;                /**< ACSM Playback Engine Register 0 for Entry 3, offset: 0x40010C */
  __IO uint16_t ACSMPLAYBACK1X3_P2;                /**< ACSM Playback Engine Register 1 for Entry 3, offset: 0x40010E */
  __IO uint16_t ACSMPLAYBACK0X4_P2;                /**< ACSM Playback Engine Register 0 for Entry 4, offset: 0x400110 */
  __IO uint16_t ACSMPLAYBACK1X4_P2;                /**< ACSM Playback Engine Register 1 for Entry 4, offset: 0x400112 */
  __IO uint16_t ACSMPLAYBACK0X5_P2;                /**< ACSM Playback Engine Register 0 for Entry 5, offset: 0x400114 */
  __IO uint16_t ACSMPLAYBACK1X5_P2;                /**< ACSM Playback Engine Register 1 for Entry 5, offset: 0x400116 */
  __IO uint16_t ACSMPLAYBACK0X6_P2;                /**< ACSM Playback Engine Register 0 for Entry 6, offset: 0x400118 */
  __IO uint16_t ACSMPLAYBACK1X6_P2;                /**< ACSM Playback Engine Register 1 for Entry 6, offset: 0x40011A */
  __IO uint16_t ACSMPLAYBACK0X7_P2;                /**< ACSM Playback Engine Register 0 for Entry 7, offset: 0x40011C */
  __IO uint16_t ACSMPLAYBACK1X7_P2;                /**< ACSM Playback Engine Register 1 for Entry 7, offset: 0x40011E */
       uint8_t RESERVED_6[2097120];
  __IO uint16_t ACSMPLAYBACK0X0_P3;                /**< ACSM Playback Engine Register 0 for Entry 0, offset: 0x600100 */
  __IO uint16_t ACSMPLAYBACK1X0_P3;                /**< ACSM Playback Engine Register 1 for Entry 0, offset: 0x600102 */
  __IO uint16_t ACSMPLAYBACK0X1_P3;                /**< ACSM Playback Engine Register 0 for Entry 1, offset: 0x600104 */
  __IO uint16_t ACSMPLAYBACK1X1_P3;                /**< ACSM Playback Engine Register 1 for Entry 1, offset: 0x600106 */
  __IO uint16_t ACSMPLAYBACK0X2_P3;                /**< ACSM Playback Engine Register 0 for Entry 2, offset: 0x600108 */
  __IO uint16_t ACSMPLAYBACK1X2_P3;                /**< ACSM Playback Engine Register 1 for Entry 2, offset: 0x60010A */
  __IO uint16_t ACSMPLAYBACK0X3_P3;                /**< ACSM Playback Engine Register 0 for Entry 3, offset: 0x60010C */
  __IO uint16_t ACSMPLAYBACK1X3_P3;                /**< ACSM Playback Engine Register 1 for Entry 3, offset: 0x60010E */
  __IO uint16_t ACSMPLAYBACK0X4_P3;                /**< ACSM Playback Engine Register 0 for Entry 4, offset: 0x600110 */
  __IO uint16_t ACSMPLAYBACK1X4_P3;                /**< ACSM Playback Engine Register 1 for Entry 4, offset: 0x600112 */
  __IO uint16_t ACSMPLAYBACK0X5_P3;                /**< ACSM Playback Engine Register 0 for Entry 5, offset: 0x600114 */
  __IO uint16_t ACSMPLAYBACK1X5_P3;                /**< ACSM Playback Engine Register 1 for Entry 5, offset: 0x600116 */
  __IO uint16_t ACSMPLAYBACK0X6_P3;                /**< ACSM Playback Engine Register 0 for Entry 6, offset: 0x600118 */
  __IO uint16_t ACSMPLAYBACK1X6_P3;                /**< ACSM Playback Engine Register 1 for Entry 6, offset: 0x60011A */
  __IO uint16_t ACSMPLAYBACK0X7_P3;                /**< ACSM Playback Engine Register 0 for Entry 7, offset: 0x60011C */
  __IO uint16_t ACSMPLAYBACK1X7_P3;                /**< ACSM Playback Engine Register 1 for Entry 7, offset: 0x60011E */
} DWC_DDRPHYA_ACSM_Type;

/* ----------------------------------------------------------------------------
   -- DWC_DDRPHYA_ACSM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DWC_DDRPHYA_ACSM_Register_Masks DWC_DDRPHYA_ACSM Register Masks
 * @{
 */

/*! @name ACSMSEQ0X0 - ACSM sequencer instruction [15:0]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ0X0_RFU_AcsmSeq0x0_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ0X0_RFU_AcsmSeq0x0_SHIFT (0U)
/*! RFU_AcsmSeq0x0 - RFU_AcsmSeq0x0 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ0X0_RFU_AcsmSeq0x0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ0X0_RFU_AcsmSeq0x0_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ0X0_RFU_AcsmSeq0x0_MASK)
/*! @} */

/*! @name ACSMSEQ0X1 - ACSM sequencer instruction [15:0]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ0X1_RFU_AcsmSeq0x1_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ0X1_RFU_AcsmSeq0x1_SHIFT (0U)
/*! RFU_AcsmSeq0x1 - RFU_AcsmSeq0x1 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ0X1_RFU_AcsmSeq0x1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ0X1_RFU_AcsmSeq0x1_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ0X1_RFU_AcsmSeq0x1_MASK)
/*! @} */

/*! @name ACSMSEQ0X2 - ACSM sequencer instruction [15:0]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ0X2_RFU_AcsmSeq0x2_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ0X2_RFU_AcsmSeq0x2_SHIFT (0U)
/*! RFU_AcsmSeq0x2 - RFU_AcsmSeq0x2 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ0X2_RFU_AcsmSeq0x2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ0X2_RFU_AcsmSeq0x2_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ0X2_RFU_AcsmSeq0x2_MASK)
/*! @} */

/*! @name ACSMSEQ0X3 - ACSM sequencer instruction [15:0]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ0X3_RFU_AcsmSeq0x3_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ0X3_RFU_AcsmSeq0x3_SHIFT (0U)
/*! RFU_AcsmSeq0x3 - RFU_AcsmSeq0x3 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ0X3_RFU_AcsmSeq0x3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ0X3_RFU_AcsmSeq0x3_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ0X3_RFU_AcsmSeq0x3_MASK)
/*! @} */

/*! @name ACSMSEQ0X4 - ACSM sequencer instruction [15:0]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ0X4_RFU_AcsmSeq0x4_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ0X4_RFU_AcsmSeq0x4_SHIFT (0U)
/*! RFU_AcsmSeq0x4 - RFU_AcsmSeq0x4 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ0X4_RFU_AcsmSeq0x4(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ0X4_RFU_AcsmSeq0x4_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ0X4_RFU_AcsmSeq0x4_MASK)
/*! @} */

/*! @name ACSMSEQ0X5 - ACSM sequencer instruction [15:0]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ0X5_RFU_AcsmSeq0x5_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ0X5_RFU_AcsmSeq0x5_SHIFT (0U)
/*! RFU_AcsmSeq0x5 - RFU_AcsmSeq0x5 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ0X5_RFU_AcsmSeq0x5(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ0X5_RFU_AcsmSeq0x5_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ0X5_RFU_AcsmSeq0x5_MASK)
/*! @} */

/*! @name ACSMSEQ0X6 - ACSM sequencer instruction [15:0]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ0X6_RFU_AcsmSeq0x6_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ0X6_RFU_AcsmSeq0x6_SHIFT (0U)
/*! RFU_AcsmSeq0x6 - RFU_AcsmSeq0x6 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ0X6_RFU_AcsmSeq0x6(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ0X6_RFU_AcsmSeq0x6_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ0X6_RFU_AcsmSeq0x6_MASK)
/*! @} */

/*! @name ACSMSEQ0X7 - ACSM sequencer instruction [15:0]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ0X7_RFU_AcsmSeq0x7_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ0X7_RFU_AcsmSeq0x7_SHIFT (0U)
/*! RFU_AcsmSeq0x7 - RFU_AcsmSeq0x7 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ0X7_RFU_AcsmSeq0x7(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ0X7_RFU_AcsmSeq0x7_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ0X7_RFU_AcsmSeq0x7_MASK)
/*! @} */

/*! @name ACSMSEQ0X8 - ACSM sequencer instruction [15:0]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ0X8_RFU_AcsmSeq0x8_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ0X8_RFU_AcsmSeq0x8_SHIFT (0U)
/*! RFU_AcsmSeq0x8 - RFU_AcsmSeq0x8 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ0X8_RFU_AcsmSeq0x8(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ0X8_RFU_AcsmSeq0x8_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ0X8_RFU_AcsmSeq0x8_MASK)
/*! @} */

/*! @name ACSMSEQ0X9 - ACSM sequencer instruction [15:0]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ0X9_RFU_AcsmSeq0x9_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ0X9_RFU_AcsmSeq0x9_SHIFT (0U)
/*! RFU_AcsmSeq0x9 - RFU_AcsmSeq0x9 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ0X9_RFU_AcsmSeq0x9(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ0X9_RFU_AcsmSeq0x9_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ0X9_RFU_AcsmSeq0x9_MASK)
/*! @} */

/*! @name ACSMSEQ0X10 - ACSM sequencer instruction [15:0]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ0X10_RFU_AcsmSeq0x10_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ0X10_RFU_AcsmSeq0x10_SHIFT (0U)
/*! RFU_AcsmSeq0x10 - RFU_AcsmSeq0x10 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ0X10_RFU_AcsmSeq0x10(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ0X10_RFU_AcsmSeq0x10_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ0X10_RFU_AcsmSeq0x10_MASK)
/*! @} */

/*! @name ACSMSEQ0X11 - ACSM sequencer instruction [15:0]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ0X11_RFU_AcsmSeq0x11_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ0X11_RFU_AcsmSeq0x11_SHIFT (0U)
/*! RFU_AcsmSeq0x11 - RFU_AcsmSeq0x11 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ0X11_RFU_AcsmSeq0x11(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ0X11_RFU_AcsmSeq0x11_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ0X11_RFU_AcsmSeq0x11_MASK)
/*! @} */

/*! @name ACSMSEQ0X12 - ACSM sequencer instruction [15:0]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ0X12_RFU_AcsmSeq0x12_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ0X12_RFU_AcsmSeq0x12_SHIFT (0U)
/*! RFU_AcsmSeq0x12 - RFU_AcsmSeq0x12 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ0X12_RFU_AcsmSeq0x12(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ0X12_RFU_AcsmSeq0x12_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ0X12_RFU_AcsmSeq0x12_MASK)
/*! @} */

/*! @name ACSMSEQ0X13 - ACSM sequencer instruction [15:0]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ0X13_RFU_AcsmSeq0x13_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ0X13_RFU_AcsmSeq0x13_SHIFT (0U)
/*! RFU_AcsmSeq0x13 - RFU_AcsmSeq0x13 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ0X13_RFU_AcsmSeq0x13(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ0X13_RFU_AcsmSeq0x13_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ0X13_RFU_AcsmSeq0x13_MASK)
/*! @} */

/*! @name ACSMSEQ0X14 - ACSM sequencer instruction [15:0]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ0X14_RFU_AcsmSeq0x14_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ0X14_RFU_AcsmSeq0x14_SHIFT (0U)
/*! RFU_AcsmSeq0x14 - RFU_AcsmSeq0x14 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ0X14_RFU_AcsmSeq0x14(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ0X14_RFU_AcsmSeq0x14_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ0X14_RFU_AcsmSeq0x14_MASK)
/*! @} */

/*! @name ACSMSEQ0X15 - ACSM sequencer instruction [15:0]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ0X15_RFU_AcsmSeq0x15_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ0X15_RFU_AcsmSeq0x15_SHIFT (0U)
/*! RFU_AcsmSeq0x15 - RFU_AcsmSeq0x15 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ0X15_RFU_AcsmSeq0x15(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ0X15_RFU_AcsmSeq0x15_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ0X15_RFU_AcsmSeq0x15_MASK)
/*! @} */

/*! @name ACSMSEQ0X16 - ACSM sequencer instruction [15:0]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ0X16_RFU_AcsmSeq0x16_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ0X16_RFU_AcsmSeq0x16_SHIFT (0U)
/*! RFU_AcsmSeq0x16 - RFU_AcsmSeq0x16 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ0X16_RFU_AcsmSeq0x16(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ0X16_RFU_AcsmSeq0x16_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ0X16_RFU_AcsmSeq0x16_MASK)
/*! @} */

/*! @name ACSMSEQ0X17 - ACSM sequencer instruction [15:0]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ0X17_RFU_AcsmSeq0x17_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ0X17_RFU_AcsmSeq0x17_SHIFT (0U)
/*! RFU_AcsmSeq0x17 - RFU_AcsmSeq0x17 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ0X17_RFU_AcsmSeq0x17(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ0X17_RFU_AcsmSeq0x17_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ0X17_RFU_AcsmSeq0x17_MASK)
/*! @} */

/*! @name ACSMSEQ0X18 - ACSM sequencer instruction [15:0]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ0X18_RFU_AcsmSeq0x18_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ0X18_RFU_AcsmSeq0x18_SHIFT (0U)
/*! RFU_AcsmSeq0x18 - RFU_AcsmSeq0x18 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ0X18_RFU_AcsmSeq0x18(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ0X18_RFU_AcsmSeq0x18_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ0X18_RFU_AcsmSeq0x18_MASK)
/*! @} */

/*! @name ACSMSEQ0X19 - ACSM sequencer instruction [15:0]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ0X19_RFU_AcsmSeq0x19_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ0X19_RFU_AcsmSeq0x19_SHIFT (0U)
/*! RFU_AcsmSeq0x19 - RFU_AcsmSeq0x19 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ0X19_RFU_AcsmSeq0x19(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ0X19_RFU_AcsmSeq0x19_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ0X19_RFU_AcsmSeq0x19_MASK)
/*! @} */

/*! @name ACSMSEQ0X20 - ACSM sequencer instruction [15:0]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ0X20_RFU_AcsmSeq0x20_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ0X20_RFU_AcsmSeq0x20_SHIFT (0U)
/*! RFU_AcsmSeq0x20 - RFU_AcsmSeq0x20 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ0X20_RFU_AcsmSeq0x20(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ0X20_RFU_AcsmSeq0x20_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ0X20_RFU_AcsmSeq0x20_MASK)
/*! @} */

/*! @name ACSMSEQ0X21 - ACSM sequencer instruction [15:0]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ0X21_RFU_AcsmSeq0x21_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ0X21_RFU_AcsmSeq0x21_SHIFT (0U)
/*! RFU_AcsmSeq0x21 - RFU_AcsmSeq0x21 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ0X21_RFU_AcsmSeq0x21(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ0X21_RFU_AcsmSeq0x21_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ0X21_RFU_AcsmSeq0x21_MASK)
/*! @} */

/*! @name ACSMSEQ0X22 - ACSM sequencer instruction [15:0]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ0X22_RFU_AcsmSeq0x22_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ0X22_RFU_AcsmSeq0x22_SHIFT (0U)
/*! RFU_AcsmSeq0x22 - RFU_AcsmSeq0x22 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ0X22_RFU_AcsmSeq0x22(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ0X22_RFU_AcsmSeq0x22_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ0X22_RFU_AcsmSeq0x22_MASK)
/*! @} */

/*! @name ACSMSEQ0X23 - ACSM sequencer instruction [15:0]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ0X23_RFU_AcsmSeq0x23_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ0X23_RFU_AcsmSeq0x23_SHIFT (0U)
/*! RFU_AcsmSeq0x23 - RFU_AcsmSeq0x23 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ0X23_RFU_AcsmSeq0x23(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ0X23_RFU_AcsmSeq0x23_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ0X23_RFU_AcsmSeq0x23_MASK)
/*! @} */

/*! @name ACSMSEQ0X24 - ACSM sequencer instruction [15:0]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ0X24_RFU_AcsmSeq0x24_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ0X24_RFU_AcsmSeq0x24_SHIFT (0U)
/*! RFU_AcsmSeq0x24 - RFU_AcsmSeq0x24 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ0X24_RFU_AcsmSeq0x24(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ0X24_RFU_AcsmSeq0x24_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ0X24_RFU_AcsmSeq0x24_MASK)
/*! @} */

/*! @name ACSMSEQ0X25 - ACSM sequencer instruction [15:0]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ0X25_RFU_AcsmSeq0x25_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ0X25_RFU_AcsmSeq0x25_SHIFT (0U)
/*! RFU_AcsmSeq0x25 - RFU_AcsmSeq0x25 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ0X25_RFU_AcsmSeq0x25(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ0X25_RFU_AcsmSeq0x25_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ0X25_RFU_AcsmSeq0x25_MASK)
/*! @} */

/*! @name ACSMSEQ0X26 - ACSM sequencer instruction [15:0]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ0X26_RFU_AcsmSeq0x26_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ0X26_RFU_AcsmSeq0x26_SHIFT (0U)
/*! RFU_AcsmSeq0x26 - RFU_AcsmSeq0x26 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ0X26_RFU_AcsmSeq0x26(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ0X26_RFU_AcsmSeq0x26_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ0X26_RFU_AcsmSeq0x26_MASK)
/*! @} */

/*! @name ACSMSEQ0X27 - ACSM sequencer instruction [15:0]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ0X27_RFU_AcsmSeq0x27_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ0X27_RFU_AcsmSeq0x27_SHIFT (0U)
/*! RFU_AcsmSeq0x27 - RFU_AcsmSeq0x27 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ0X27_RFU_AcsmSeq0x27(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ0X27_RFU_AcsmSeq0x27_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ0X27_RFU_AcsmSeq0x27_MASK)
/*! @} */

/*! @name ACSMSEQ0X28 - ACSM sequencer instruction [15:0]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ0X28_RFU_AcsmSeq0x28_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ0X28_RFU_AcsmSeq0x28_SHIFT (0U)
/*! RFU_AcsmSeq0x28 - RFU_AcsmSeq0x28 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ0X28_RFU_AcsmSeq0x28(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ0X28_RFU_AcsmSeq0x28_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ0X28_RFU_AcsmSeq0x28_MASK)
/*! @} */

/*! @name ACSMSEQ0X29 - ACSM sequencer instruction [15:0]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ0X29_RFU_AcsmSeq0x29_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ0X29_RFU_AcsmSeq0x29_SHIFT (0U)
/*! RFU_AcsmSeq0x29 - RFU_AcsmSeq0x29 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ0X29_RFU_AcsmSeq0x29(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ0X29_RFU_AcsmSeq0x29_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ0X29_RFU_AcsmSeq0x29_MASK)
/*! @} */

/*! @name ACSMSEQ0X30 - ACSM sequencer instruction [15:0]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ0X30_RFU_AcsmSeq0x30_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ0X30_RFU_AcsmSeq0x30_SHIFT (0U)
/*! RFU_AcsmSeq0x30 - RFU_AcsmSeq0x30 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ0X30_RFU_AcsmSeq0x30(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ0X30_RFU_AcsmSeq0x30_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ0X30_RFU_AcsmSeq0x30_MASK)
/*! @} */

/*! @name ACSMSEQ0X31 - ACSM sequencer instruction [15:0]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ0X31_RFU_AcsmSeq0x31_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ0X31_RFU_AcsmSeq0x31_SHIFT (0U)
/*! RFU_AcsmSeq0x31 - RFU_AcsmSeq0x31 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ0X31_RFU_AcsmSeq0x31(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ0X31_RFU_AcsmSeq0x31_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ0X31_RFU_AcsmSeq0x31_MASK)
/*! @} */

/*! @name ACSMSEQ1X0 - ACSM sequencer instruction [31:16]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ1X0_RFU_AcsmSeq1x0_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ1X0_RFU_AcsmSeq1x0_SHIFT (0U)
/*! RFU_AcsmSeq1x0 - RFU_AcsmSeq1x0 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ1X0_RFU_AcsmSeq1x0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ1X0_RFU_AcsmSeq1x0_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ1X0_RFU_AcsmSeq1x0_MASK)
/*! @} */

/*! @name ACSMSEQ1X1 - ACSM sequencer instruction [31:16]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ1X1_RFU_AcsmSeq1x1_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ1X1_RFU_AcsmSeq1x1_SHIFT (0U)
/*! RFU_AcsmSeq1x1 - RFU_AcsmSeq1x1 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ1X1_RFU_AcsmSeq1x1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ1X1_RFU_AcsmSeq1x1_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ1X1_RFU_AcsmSeq1x1_MASK)
/*! @} */

/*! @name ACSMSEQ1X2 - ACSM sequencer instruction [31:16]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ1X2_RFU_AcsmSeq1x2_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ1X2_RFU_AcsmSeq1x2_SHIFT (0U)
/*! RFU_AcsmSeq1x2 - RFU_AcsmSeq1x2 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ1X2_RFU_AcsmSeq1x2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ1X2_RFU_AcsmSeq1x2_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ1X2_RFU_AcsmSeq1x2_MASK)
/*! @} */

/*! @name ACSMSEQ1X3 - ACSM sequencer instruction [31:16]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ1X3_RFU_AcsmSeq1x3_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ1X3_RFU_AcsmSeq1x3_SHIFT (0U)
/*! RFU_AcsmSeq1x3 - RFU_AcsmSeq1x3 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ1X3_RFU_AcsmSeq1x3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ1X3_RFU_AcsmSeq1x3_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ1X3_RFU_AcsmSeq1x3_MASK)
/*! @} */

/*! @name ACSMSEQ1X4 - ACSM sequencer instruction [31:16]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ1X4_RFU_AcsmSeq1x4_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ1X4_RFU_AcsmSeq1x4_SHIFT (0U)
/*! RFU_AcsmSeq1x4 - RFU_AcsmSeq1x4 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ1X4_RFU_AcsmSeq1x4(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ1X4_RFU_AcsmSeq1x4_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ1X4_RFU_AcsmSeq1x4_MASK)
/*! @} */

/*! @name ACSMSEQ1X5 - ACSM sequencer instruction [31:16]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ1X5_RFU_AcsmSeq1x5_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ1X5_RFU_AcsmSeq1x5_SHIFT (0U)
/*! RFU_AcsmSeq1x5 - RFU_AcsmSeq1x5 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ1X5_RFU_AcsmSeq1x5(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ1X5_RFU_AcsmSeq1x5_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ1X5_RFU_AcsmSeq1x5_MASK)
/*! @} */

/*! @name ACSMSEQ1X6 - ACSM sequencer instruction [31:16]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ1X6_RFU_AcsmSeq1x6_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ1X6_RFU_AcsmSeq1x6_SHIFT (0U)
/*! RFU_AcsmSeq1x6 - RFU_AcsmSeq1x6 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ1X6_RFU_AcsmSeq1x6(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ1X6_RFU_AcsmSeq1x6_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ1X6_RFU_AcsmSeq1x6_MASK)
/*! @} */

/*! @name ACSMSEQ1X7 - ACSM sequencer instruction [31:16]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ1X7_RFU_AcsmSeq1x7_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ1X7_RFU_AcsmSeq1x7_SHIFT (0U)
/*! RFU_AcsmSeq1x7 - RFU_AcsmSeq1x7 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ1X7_RFU_AcsmSeq1x7(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ1X7_RFU_AcsmSeq1x7_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ1X7_RFU_AcsmSeq1x7_MASK)
/*! @} */

/*! @name ACSMSEQ1X8 - ACSM sequencer instruction [31:16]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ1X8_RFU_AcsmSeq1x8_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ1X8_RFU_AcsmSeq1x8_SHIFT (0U)
/*! RFU_AcsmSeq1x8 - RFU_AcsmSeq1x8 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ1X8_RFU_AcsmSeq1x8(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ1X8_RFU_AcsmSeq1x8_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ1X8_RFU_AcsmSeq1x8_MASK)
/*! @} */

/*! @name ACSMSEQ1X9 - ACSM sequencer instruction [31:16]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ1X9_RFU_AcsmSeq1x9_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ1X9_RFU_AcsmSeq1x9_SHIFT (0U)
/*! RFU_AcsmSeq1x9 - RFU_AcsmSeq1x9 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ1X9_RFU_AcsmSeq1x9(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ1X9_RFU_AcsmSeq1x9_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ1X9_RFU_AcsmSeq1x9_MASK)
/*! @} */

/*! @name ACSMSEQ1X10 - ACSM sequencer instruction [31:16]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ1X10_RFU_AcsmSeq1x10_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ1X10_RFU_AcsmSeq1x10_SHIFT (0U)
/*! RFU_AcsmSeq1x10 - RFU_AcsmSeq1x10 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ1X10_RFU_AcsmSeq1x10(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ1X10_RFU_AcsmSeq1x10_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ1X10_RFU_AcsmSeq1x10_MASK)
/*! @} */

/*! @name ACSMSEQ1X11 - ACSM sequencer instruction [31:16]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ1X11_RFU_AcsmSeq1x11_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ1X11_RFU_AcsmSeq1x11_SHIFT (0U)
/*! RFU_AcsmSeq1x11 - RFU_AcsmSeq1x11 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ1X11_RFU_AcsmSeq1x11(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ1X11_RFU_AcsmSeq1x11_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ1X11_RFU_AcsmSeq1x11_MASK)
/*! @} */

/*! @name ACSMSEQ1X12 - ACSM sequencer instruction [31:16]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ1X12_RFU_AcsmSeq1x12_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ1X12_RFU_AcsmSeq1x12_SHIFT (0U)
/*! RFU_AcsmSeq1x12 - RFU_AcsmSeq1x12 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ1X12_RFU_AcsmSeq1x12(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ1X12_RFU_AcsmSeq1x12_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ1X12_RFU_AcsmSeq1x12_MASK)
/*! @} */

/*! @name ACSMSEQ1X13 - ACSM sequencer instruction [31:16]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ1X13_RFU_AcsmSeq1x13_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ1X13_RFU_AcsmSeq1x13_SHIFT (0U)
/*! RFU_AcsmSeq1x13 - RFU_AcsmSeq1x13 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ1X13_RFU_AcsmSeq1x13(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ1X13_RFU_AcsmSeq1x13_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ1X13_RFU_AcsmSeq1x13_MASK)
/*! @} */

/*! @name ACSMSEQ1X14 - ACSM sequencer instruction [31:16]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ1X14_RFU_AcsmSeq1x14_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ1X14_RFU_AcsmSeq1x14_SHIFT (0U)
/*! RFU_AcsmSeq1x14 - RFU_AcsmSeq1x14 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ1X14_RFU_AcsmSeq1x14(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ1X14_RFU_AcsmSeq1x14_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ1X14_RFU_AcsmSeq1x14_MASK)
/*! @} */

/*! @name ACSMSEQ1X15 - ACSM sequencer instruction [31:16]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ1X15_RFU_AcsmSeq1x15_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ1X15_RFU_AcsmSeq1x15_SHIFT (0U)
/*! RFU_AcsmSeq1x15 - RFU_AcsmSeq1x15 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ1X15_RFU_AcsmSeq1x15(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ1X15_RFU_AcsmSeq1x15_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ1X15_RFU_AcsmSeq1x15_MASK)
/*! @} */

/*! @name ACSMSEQ1X16 - ACSM sequencer instruction [31:16]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ1X16_RFU_AcsmSeq1x16_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ1X16_RFU_AcsmSeq1x16_SHIFT (0U)
/*! RFU_AcsmSeq1x16 - RFU_AcsmSeq1x16 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ1X16_RFU_AcsmSeq1x16(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ1X16_RFU_AcsmSeq1x16_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ1X16_RFU_AcsmSeq1x16_MASK)
/*! @} */

/*! @name ACSMSEQ1X17 - ACSM sequencer instruction [31:16]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ1X17_RFU_AcsmSeq1x17_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ1X17_RFU_AcsmSeq1x17_SHIFT (0U)
/*! RFU_AcsmSeq1x17 - RFU_AcsmSeq1x17 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ1X17_RFU_AcsmSeq1x17(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ1X17_RFU_AcsmSeq1x17_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ1X17_RFU_AcsmSeq1x17_MASK)
/*! @} */

/*! @name ACSMSEQ1X18 - ACSM sequencer instruction [31:16]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ1X18_RFU_AcsmSeq1x18_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ1X18_RFU_AcsmSeq1x18_SHIFT (0U)
/*! RFU_AcsmSeq1x18 - RFU_AcsmSeq1x18 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ1X18_RFU_AcsmSeq1x18(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ1X18_RFU_AcsmSeq1x18_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ1X18_RFU_AcsmSeq1x18_MASK)
/*! @} */

/*! @name ACSMSEQ1X19 - ACSM sequencer instruction [31:16]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ1X19_RFU_AcsmSeq1x19_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ1X19_RFU_AcsmSeq1x19_SHIFT (0U)
/*! RFU_AcsmSeq1x19 - RFU_AcsmSeq1x19 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ1X19_RFU_AcsmSeq1x19(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ1X19_RFU_AcsmSeq1x19_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ1X19_RFU_AcsmSeq1x19_MASK)
/*! @} */

/*! @name ACSMSEQ1X20 - ACSM sequencer instruction [31:16]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ1X20_RFU_AcsmSeq1x20_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ1X20_RFU_AcsmSeq1x20_SHIFT (0U)
/*! RFU_AcsmSeq1x20 - RFU_AcsmSeq1x20 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ1X20_RFU_AcsmSeq1x20(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ1X20_RFU_AcsmSeq1x20_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ1X20_RFU_AcsmSeq1x20_MASK)
/*! @} */

/*! @name ACSMSEQ1X21 - ACSM sequencer instruction [31:16]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ1X21_RFU_AcsmSeq1x21_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ1X21_RFU_AcsmSeq1x21_SHIFT (0U)
/*! RFU_AcsmSeq1x21 - RFU_AcsmSeq1x21 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ1X21_RFU_AcsmSeq1x21(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ1X21_RFU_AcsmSeq1x21_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ1X21_RFU_AcsmSeq1x21_MASK)
/*! @} */

/*! @name ACSMSEQ1X22 - ACSM sequencer instruction [31:16]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ1X22_RFU_AcsmSeq1x22_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ1X22_RFU_AcsmSeq1x22_SHIFT (0U)
/*! RFU_AcsmSeq1x22 - RFU_AcsmSeq1x22 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ1X22_RFU_AcsmSeq1x22(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ1X22_RFU_AcsmSeq1x22_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ1X22_RFU_AcsmSeq1x22_MASK)
/*! @} */

/*! @name ACSMSEQ1X23 - ACSM sequencer instruction [31:16]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ1X23_RFU_AcsmSeq1x23_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ1X23_RFU_AcsmSeq1x23_SHIFT (0U)
/*! RFU_AcsmSeq1x23 - RFU_AcsmSeq1x23 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ1X23_RFU_AcsmSeq1x23(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ1X23_RFU_AcsmSeq1x23_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ1X23_RFU_AcsmSeq1x23_MASK)
/*! @} */

/*! @name ACSMSEQ1X24 - ACSM sequencer instruction [31:16]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ1X24_RFU_AcsmSeq1x24_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ1X24_RFU_AcsmSeq1x24_SHIFT (0U)
/*! RFU_AcsmSeq1x24 - RFU_AcsmSeq1x24 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ1X24_RFU_AcsmSeq1x24(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ1X24_RFU_AcsmSeq1x24_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ1X24_RFU_AcsmSeq1x24_MASK)
/*! @} */

/*! @name ACSMSEQ1X25 - ACSM sequencer instruction [31:16]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ1X25_RFU_AcsmSeq1x25_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ1X25_RFU_AcsmSeq1x25_SHIFT (0U)
/*! RFU_AcsmSeq1x25 - RFU_AcsmSeq1x25 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ1X25_RFU_AcsmSeq1x25(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ1X25_RFU_AcsmSeq1x25_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ1X25_RFU_AcsmSeq1x25_MASK)
/*! @} */

/*! @name ACSMSEQ1X26 - ACSM sequencer instruction [31:16]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ1X26_RFU_AcsmSeq1x26_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ1X26_RFU_AcsmSeq1x26_SHIFT (0U)
/*! RFU_AcsmSeq1x26 - RFU_AcsmSeq1x26 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ1X26_RFU_AcsmSeq1x26(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ1X26_RFU_AcsmSeq1x26_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ1X26_RFU_AcsmSeq1x26_MASK)
/*! @} */

/*! @name ACSMSEQ1X27 - ACSM sequencer instruction [31:16]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ1X27_RFU_AcsmSeq1x27_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ1X27_RFU_AcsmSeq1x27_SHIFT (0U)
/*! RFU_AcsmSeq1x27 - RFU_AcsmSeq1x27 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ1X27_RFU_AcsmSeq1x27(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ1X27_RFU_AcsmSeq1x27_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ1X27_RFU_AcsmSeq1x27_MASK)
/*! @} */

/*! @name ACSMSEQ1X28 - ACSM sequencer instruction [31:16]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ1X28_RFU_AcsmSeq1x28_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ1X28_RFU_AcsmSeq1x28_SHIFT (0U)
/*! RFU_AcsmSeq1x28 - RFU_AcsmSeq1x28 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ1X28_RFU_AcsmSeq1x28(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ1X28_RFU_AcsmSeq1x28_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ1X28_RFU_AcsmSeq1x28_MASK)
/*! @} */

/*! @name ACSMSEQ1X29 - ACSM sequencer instruction [31:16]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ1X29_RFU_AcsmSeq1x29_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ1X29_RFU_AcsmSeq1x29_SHIFT (0U)
/*! RFU_AcsmSeq1x29 - RFU_AcsmSeq1x29 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ1X29_RFU_AcsmSeq1x29(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ1X29_RFU_AcsmSeq1x29_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ1X29_RFU_AcsmSeq1x29_MASK)
/*! @} */

/*! @name ACSMSEQ1X30 - ACSM sequencer instruction [31:16]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ1X30_RFU_AcsmSeq1x30_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ1X30_RFU_AcsmSeq1x30_SHIFT (0U)
/*! RFU_AcsmSeq1x30 - RFU_AcsmSeq1x30 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ1X30_RFU_AcsmSeq1x30(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ1X30_RFU_AcsmSeq1x30_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ1X30_RFU_AcsmSeq1x30_MASK)
/*! @} */

/*! @name ACSMSEQ1X31 - ACSM sequencer instruction [31:16]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ1X31_RFU_AcsmSeq1x31_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ1X31_RFU_AcsmSeq1x31_SHIFT (0U)
/*! RFU_AcsmSeq1x31 - RFU_AcsmSeq1x31 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ1X31_RFU_AcsmSeq1x31(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ1X31_RFU_AcsmSeq1x31_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ1X31_RFU_AcsmSeq1x31_MASK)
/*! @} */

/*! @name ACSMSEQ2X0 - ACSM sequencer instruction [47:32]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ2X0_RFU_AcsmSeq2x0_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ2X0_RFU_AcsmSeq2x0_SHIFT (0U)
/*! RFU_AcsmSeq2x0 - RFU_AcsmSeq2x0 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ2X0_RFU_AcsmSeq2x0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ2X0_RFU_AcsmSeq2x0_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ2X0_RFU_AcsmSeq2x0_MASK)
/*! @} */

/*! @name ACSMSEQ2X1 - ACSM sequencer instruction [47:32]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ2X1_RFU_AcsmSeq2x1_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ2X1_RFU_AcsmSeq2x1_SHIFT (0U)
/*! RFU_AcsmSeq2x1 - RFU_AcsmSeq2x1 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ2X1_RFU_AcsmSeq2x1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ2X1_RFU_AcsmSeq2x1_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ2X1_RFU_AcsmSeq2x1_MASK)
/*! @} */

/*! @name ACSMSEQ2X2 - ACSM sequencer instruction [47:32]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ2X2_RFU_AcsmSeq2x2_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ2X2_RFU_AcsmSeq2x2_SHIFT (0U)
/*! RFU_AcsmSeq2x2 - RFU_AcsmSeq2x2 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ2X2_RFU_AcsmSeq2x2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ2X2_RFU_AcsmSeq2x2_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ2X2_RFU_AcsmSeq2x2_MASK)
/*! @} */

/*! @name ACSMSEQ2X3 - ACSM sequencer instruction [47:32]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ2X3_RFU_AcsmSeq2x3_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ2X3_RFU_AcsmSeq2x3_SHIFT (0U)
/*! RFU_AcsmSeq2x3 - RFU_AcsmSeq2x3 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ2X3_RFU_AcsmSeq2x3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ2X3_RFU_AcsmSeq2x3_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ2X3_RFU_AcsmSeq2x3_MASK)
/*! @} */

/*! @name ACSMSEQ2X4 - ACSM sequencer instruction [47:32]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ2X4_RFU_AcsmSeq2x4_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ2X4_RFU_AcsmSeq2x4_SHIFT (0U)
/*! RFU_AcsmSeq2x4 - RFU_AcsmSeq2x4 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ2X4_RFU_AcsmSeq2x4(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ2X4_RFU_AcsmSeq2x4_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ2X4_RFU_AcsmSeq2x4_MASK)
/*! @} */

/*! @name ACSMSEQ2X5 - ACSM sequencer instruction [47:32]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ2X5_RFU_AcsmSeq2x5_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ2X5_RFU_AcsmSeq2x5_SHIFT (0U)
/*! RFU_AcsmSeq2x5 - RFU_AcsmSeq2x5 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ2X5_RFU_AcsmSeq2x5(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ2X5_RFU_AcsmSeq2x5_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ2X5_RFU_AcsmSeq2x5_MASK)
/*! @} */

/*! @name ACSMSEQ2X6 - ACSM sequencer instruction [47:32]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ2X6_RFU_AcsmSeq2x6_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ2X6_RFU_AcsmSeq2x6_SHIFT (0U)
/*! RFU_AcsmSeq2x6 - RFU_AcsmSeq2x6 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ2X6_RFU_AcsmSeq2x6(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ2X6_RFU_AcsmSeq2x6_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ2X6_RFU_AcsmSeq2x6_MASK)
/*! @} */

/*! @name ACSMSEQ2X7 - ACSM sequencer instruction [47:32]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ2X7_RFU_AcsmSeq2x7_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ2X7_RFU_AcsmSeq2x7_SHIFT (0U)
/*! RFU_AcsmSeq2x7 - RFU_AcsmSeq2x7 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ2X7_RFU_AcsmSeq2x7(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ2X7_RFU_AcsmSeq2x7_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ2X7_RFU_AcsmSeq2x7_MASK)
/*! @} */

/*! @name ACSMSEQ2X8 - ACSM sequencer instruction [47:32]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ2X8_RFU_AcsmSeq2x8_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ2X8_RFU_AcsmSeq2x8_SHIFT (0U)
/*! RFU_AcsmSeq2x8 - RFU_AcsmSeq2x8 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ2X8_RFU_AcsmSeq2x8(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ2X8_RFU_AcsmSeq2x8_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ2X8_RFU_AcsmSeq2x8_MASK)
/*! @} */

/*! @name ACSMSEQ2X9 - ACSM sequencer instruction [47:32]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ2X9_RFU_AcsmSeq2x9_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ2X9_RFU_AcsmSeq2x9_SHIFT (0U)
/*! RFU_AcsmSeq2x9 - RFU_AcsmSeq2x9 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ2X9_RFU_AcsmSeq2x9(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ2X9_RFU_AcsmSeq2x9_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ2X9_RFU_AcsmSeq2x9_MASK)
/*! @} */

/*! @name ACSMSEQ2X10 - ACSM sequencer instruction [47:32]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ2X10_RFU_AcsmSeq2x10_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ2X10_RFU_AcsmSeq2x10_SHIFT (0U)
/*! RFU_AcsmSeq2x10 - RFU_AcsmSeq2x10 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ2X10_RFU_AcsmSeq2x10(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ2X10_RFU_AcsmSeq2x10_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ2X10_RFU_AcsmSeq2x10_MASK)
/*! @} */

/*! @name ACSMSEQ2X11 - ACSM sequencer instruction [47:32]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ2X11_RFU_AcsmSeq2x11_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ2X11_RFU_AcsmSeq2x11_SHIFT (0U)
/*! RFU_AcsmSeq2x11 - RFU_AcsmSeq2x11 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ2X11_RFU_AcsmSeq2x11(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ2X11_RFU_AcsmSeq2x11_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ2X11_RFU_AcsmSeq2x11_MASK)
/*! @} */

/*! @name ACSMSEQ2X12 - ACSM sequencer instruction [47:32]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ2X12_RFU_AcsmSeq2x12_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ2X12_RFU_AcsmSeq2x12_SHIFT (0U)
/*! RFU_AcsmSeq2x12 - RFU_AcsmSeq2x12 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ2X12_RFU_AcsmSeq2x12(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ2X12_RFU_AcsmSeq2x12_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ2X12_RFU_AcsmSeq2x12_MASK)
/*! @} */

/*! @name ACSMSEQ2X13 - ACSM sequencer instruction [47:32]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ2X13_RFU_AcsmSeq2x13_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ2X13_RFU_AcsmSeq2x13_SHIFT (0U)
/*! RFU_AcsmSeq2x13 - RFU_AcsmSeq2x13 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ2X13_RFU_AcsmSeq2x13(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ2X13_RFU_AcsmSeq2x13_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ2X13_RFU_AcsmSeq2x13_MASK)
/*! @} */

/*! @name ACSMSEQ2X14 - ACSM sequencer instruction [47:32]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ2X14_RFU_AcsmSeq2x14_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ2X14_RFU_AcsmSeq2x14_SHIFT (0U)
/*! RFU_AcsmSeq2x14 - RFU_AcsmSeq2x14 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ2X14_RFU_AcsmSeq2x14(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ2X14_RFU_AcsmSeq2x14_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ2X14_RFU_AcsmSeq2x14_MASK)
/*! @} */

/*! @name ACSMSEQ2X15 - ACSM sequencer instruction [47:32]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ2X15_RFU_AcsmSeq2x15_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ2X15_RFU_AcsmSeq2x15_SHIFT (0U)
/*! RFU_AcsmSeq2x15 - RFU_AcsmSeq2x15 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ2X15_RFU_AcsmSeq2x15(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ2X15_RFU_AcsmSeq2x15_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ2X15_RFU_AcsmSeq2x15_MASK)
/*! @} */

/*! @name ACSMSEQ2X16 - ACSM sequencer instruction [47:32]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ2X16_RFU_AcsmSeq2x16_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ2X16_RFU_AcsmSeq2x16_SHIFT (0U)
/*! RFU_AcsmSeq2x16 - RFU_AcsmSeq2x16 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ2X16_RFU_AcsmSeq2x16(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ2X16_RFU_AcsmSeq2x16_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ2X16_RFU_AcsmSeq2x16_MASK)
/*! @} */

/*! @name ACSMSEQ2X17 - ACSM sequencer instruction [47:32]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ2X17_RFU_AcsmSeq2x17_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ2X17_RFU_AcsmSeq2x17_SHIFT (0U)
/*! RFU_AcsmSeq2x17 - RFU_AcsmSeq2x17 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ2X17_RFU_AcsmSeq2x17(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ2X17_RFU_AcsmSeq2x17_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ2X17_RFU_AcsmSeq2x17_MASK)
/*! @} */

/*! @name ACSMSEQ2X18 - ACSM sequencer instruction [47:32]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ2X18_RFU_AcsmSeq2x18_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ2X18_RFU_AcsmSeq2x18_SHIFT (0U)
/*! RFU_AcsmSeq2x18 - RFU_AcsmSeq2x18 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ2X18_RFU_AcsmSeq2x18(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ2X18_RFU_AcsmSeq2x18_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ2X18_RFU_AcsmSeq2x18_MASK)
/*! @} */

/*! @name ACSMSEQ2X19 - ACSM sequencer instruction [47:32]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ2X19_RFU_AcsmSeq2x19_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ2X19_RFU_AcsmSeq2x19_SHIFT (0U)
/*! RFU_AcsmSeq2x19 - RFU_AcsmSeq2x19 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ2X19_RFU_AcsmSeq2x19(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ2X19_RFU_AcsmSeq2x19_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ2X19_RFU_AcsmSeq2x19_MASK)
/*! @} */

/*! @name ACSMSEQ2X20 - ACSM sequencer instruction [47:32]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ2X20_RFU_AcsmSeq2x20_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ2X20_RFU_AcsmSeq2x20_SHIFT (0U)
/*! RFU_AcsmSeq2x20 - RFU_AcsmSeq2x20 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ2X20_RFU_AcsmSeq2x20(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ2X20_RFU_AcsmSeq2x20_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ2X20_RFU_AcsmSeq2x20_MASK)
/*! @} */

/*! @name ACSMSEQ2X21 - ACSM sequencer instruction [47:32]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ2X21_RFU_AcsmSeq2x21_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ2X21_RFU_AcsmSeq2x21_SHIFT (0U)
/*! RFU_AcsmSeq2x21 - RFU_AcsmSeq2x21 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ2X21_RFU_AcsmSeq2x21(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ2X21_RFU_AcsmSeq2x21_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ2X21_RFU_AcsmSeq2x21_MASK)
/*! @} */

/*! @name ACSMSEQ2X22 - ACSM sequencer instruction [47:32]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ2X22_RFU_AcsmSeq2x22_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ2X22_RFU_AcsmSeq2x22_SHIFT (0U)
/*! RFU_AcsmSeq2x22 - RFU_AcsmSeq2x22 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ2X22_RFU_AcsmSeq2x22(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ2X22_RFU_AcsmSeq2x22_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ2X22_RFU_AcsmSeq2x22_MASK)
/*! @} */

/*! @name ACSMSEQ2X23 - ACSM sequencer instruction [47:32]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ2X23_RFU_AcsmSeq2x23_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ2X23_RFU_AcsmSeq2x23_SHIFT (0U)
/*! RFU_AcsmSeq2x23 - RFU_AcsmSeq2x23 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ2X23_RFU_AcsmSeq2x23(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ2X23_RFU_AcsmSeq2x23_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ2X23_RFU_AcsmSeq2x23_MASK)
/*! @} */

/*! @name ACSMSEQ2X24 - ACSM sequencer instruction [47:32]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ2X24_RFU_AcsmSeq2x24_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ2X24_RFU_AcsmSeq2x24_SHIFT (0U)
/*! RFU_AcsmSeq2x24 - RFU_AcsmSeq2x24 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ2X24_RFU_AcsmSeq2x24(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ2X24_RFU_AcsmSeq2x24_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ2X24_RFU_AcsmSeq2x24_MASK)
/*! @} */

/*! @name ACSMSEQ2X25 - ACSM sequencer instruction [47:32]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ2X25_RFU_AcsmSeq2x25_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ2X25_RFU_AcsmSeq2x25_SHIFT (0U)
/*! RFU_AcsmSeq2x25 - RFU_AcsmSeq2x25 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ2X25_RFU_AcsmSeq2x25(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ2X25_RFU_AcsmSeq2x25_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ2X25_RFU_AcsmSeq2x25_MASK)
/*! @} */

/*! @name ACSMSEQ2X26 - ACSM sequencer instruction [47:32]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ2X26_RFU_AcsmSeq2x26_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ2X26_RFU_AcsmSeq2x26_SHIFT (0U)
/*! RFU_AcsmSeq2x26 - RFU_AcsmSeq2x26 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ2X26_RFU_AcsmSeq2x26(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ2X26_RFU_AcsmSeq2x26_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ2X26_RFU_AcsmSeq2x26_MASK)
/*! @} */

/*! @name ACSMSEQ2X27 - ACSM sequencer instruction [47:32]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ2X27_RFU_AcsmSeq2x27_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ2X27_RFU_AcsmSeq2x27_SHIFT (0U)
/*! RFU_AcsmSeq2x27 - RFU_AcsmSeq2x27 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ2X27_RFU_AcsmSeq2x27(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ2X27_RFU_AcsmSeq2x27_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ2X27_RFU_AcsmSeq2x27_MASK)
/*! @} */

/*! @name ACSMSEQ2X28 - ACSM sequencer instruction [47:32]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ2X28_RFU_AcsmSeq2x28_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ2X28_RFU_AcsmSeq2x28_SHIFT (0U)
/*! RFU_AcsmSeq2x28 - RFU_AcsmSeq2x28 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ2X28_RFU_AcsmSeq2x28(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ2X28_RFU_AcsmSeq2x28_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ2X28_RFU_AcsmSeq2x28_MASK)
/*! @} */

/*! @name ACSMSEQ2X29 - ACSM sequencer instruction [47:32]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ2X29_RFU_AcsmSeq2x29_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ2X29_RFU_AcsmSeq2x29_SHIFT (0U)
/*! RFU_AcsmSeq2x29 - RFU_AcsmSeq2x29 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ2X29_RFU_AcsmSeq2x29(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ2X29_RFU_AcsmSeq2x29_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ2X29_RFU_AcsmSeq2x29_MASK)
/*! @} */

/*! @name ACSMSEQ2X30 - ACSM sequencer instruction [47:32]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ2X30_RFU_AcsmSeq2x30_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ2X30_RFU_AcsmSeq2x30_SHIFT (0U)
/*! RFU_AcsmSeq2x30 - RFU_AcsmSeq2x30 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ2X30_RFU_AcsmSeq2x30(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ2X30_RFU_AcsmSeq2x30_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ2X30_RFU_AcsmSeq2x30_MASK)
/*! @} */

/*! @name ACSMSEQ2X31 - ACSM sequencer instruction [47:32]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ2X31_RFU_AcsmSeq2x31_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ2X31_RFU_AcsmSeq2x31_SHIFT (0U)
/*! RFU_AcsmSeq2x31 - RFU_AcsmSeq2x31 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ2X31_RFU_AcsmSeq2x31(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ2X31_RFU_AcsmSeq2x31_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ2X31_RFU_AcsmSeq2x31_MASK)
/*! @} */

/*! @name ACSMSEQ3X0 - ACSM sequencer instruction [63:48]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ3X0_RFU_AcsmSeq3x0_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ3X0_RFU_AcsmSeq3x0_SHIFT (0U)
/*! RFU_AcsmSeq3x0 - RFU_AcsmSeq3x0 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ3X0_RFU_AcsmSeq3x0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ3X0_RFU_AcsmSeq3x0_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ3X0_RFU_AcsmSeq3x0_MASK)
/*! @} */

/*! @name ACSMSEQ3X1 - ACSM sequencer instruction [63:48]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ3X1_RFU_AcsmSeq3x1_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ3X1_RFU_AcsmSeq3x1_SHIFT (0U)
/*! RFU_AcsmSeq3x1 - RFU_AcsmSeq3x1 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ3X1_RFU_AcsmSeq3x1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ3X1_RFU_AcsmSeq3x1_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ3X1_RFU_AcsmSeq3x1_MASK)
/*! @} */

/*! @name ACSMSEQ3X2 - ACSM sequencer instruction [63:48]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ3X2_RFU_AcsmSeq3x2_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ3X2_RFU_AcsmSeq3x2_SHIFT (0U)
/*! RFU_AcsmSeq3x2 - RFU_AcsmSeq3x2 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ3X2_RFU_AcsmSeq3x2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ3X2_RFU_AcsmSeq3x2_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ3X2_RFU_AcsmSeq3x2_MASK)
/*! @} */

/*! @name ACSMSEQ3X3 - ACSM sequencer instruction [63:48]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ3X3_RFU_AcsmSeq3x3_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ3X3_RFU_AcsmSeq3x3_SHIFT (0U)
/*! RFU_AcsmSeq3x3 - RFU_AcsmSeq3x3 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ3X3_RFU_AcsmSeq3x3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ3X3_RFU_AcsmSeq3x3_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ3X3_RFU_AcsmSeq3x3_MASK)
/*! @} */

/*! @name ACSMSEQ3X4 - ACSM sequencer instruction [63:48]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ3X4_RFU_AcsmSeq3x4_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ3X4_RFU_AcsmSeq3x4_SHIFT (0U)
/*! RFU_AcsmSeq3x4 - RFU_AcsmSeq3x4 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ3X4_RFU_AcsmSeq3x4(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ3X4_RFU_AcsmSeq3x4_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ3X4_RFU_AcsmSeq3x4_MASK)
/*! @} */

/*! @name ACSMSEQ3X5 - ACSM sequencer instruction [63:48]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ3X5_RFU_AcsmSeq3x5_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ3X5_RFU_AcsmSeq3x5_SHIFT (0U)
/*! RFU_AcsmSeq3x5 - RFU_AcsmSeq3x5 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ3X5_RFU_AcsmSeq3x5(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ3X5_RFU_AcsmSeq3x5_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ3X5_RFU_AcsmSeq3x5_MASK)
/*! @} */

/*! @name ACSMSEQ3X6 - ACSM sequencer instruction [63:48]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ3X6_RFU_AcsmSeq3x6_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ3X6_RFU_AcsmSeq3x6_SHIFT (0U)
/*! RFU_AcsmSeq3x6 - RFU_AcsmSeq3x6 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ3X6_RFU_AcsmSeq3x6(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ3X6_RFU_AcsmSeq3x6_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ3X6_RFU_AcsmSeq3x6_MASK)
/*! @} */

/*! @name ACSMSEQ3X7 - ACSM sequencer instruction [63:48]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ3X7_RFU_AcsmSeq3x7_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ3X7_RFU_AcsmSeq3x7_SHIFT (0U)
/*! RFU_AcsmSeq3x7 - RFU_AcsmSeq3x7 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ3X7_RFU_AcsmSeq3x7(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ3X7_RFU_AcsmSeq3x7_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ3X7_RFU_AcsmSeq3x7_MASK)
/*! @} */

/*! @name ACSMSEQ3X8 - ACSM sequencer instruction [63:48]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ3X8_RFU_AcsmSeq3x8_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ3X8_RFU_AcsmSeq3x8_SHIFT (0U)
/*! RFU_AcsmSeq3x8 - RFU_AcsmSeq3x8 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ3X8_RFU_AcsmSeq3x8(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ3X8_RFU_AcsmSeq3x8_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ3X8_RFU_AcsmSeq3x8_MASK)
/*! @} */

/*! @name ACSMSEQ3X9 - ACSM sequencer instruction [63:48]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ3X9_RFU_AcsmSeq3x9_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ3X9_RFU_AcsmSeq3x9_SHIFT (0U)
/*! RFU_AcsmSeq3x9 - RFU_AcsmSeq3x9 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ3X9_RFU_AcsmSeq3x9(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ3X9_RFU_AcsmSeq3x9_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ3X9_RFU_AcsmSeq3x9_MASK)
/*! @} */

/*! @name ACSMSEQ3X10 - ACSM sequencer instruction [63:48]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ3X10_RFU_AcsmSeq3x10_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ3X10_RFU_AcsmSeq3x10_SHIFT (0U)
/*! RFU_AcsmSeq3x10 - RFU_AcsmSeq3x10 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ3X10_RFU_AcsmSeq3x10(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ3X10_RFU_AcsmSeq3x10_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ3X10_RFU_AcsmSeq3x10_MASK)
/*! @} */

/*! @name ACSMSEQ3X11 - ACSM sequencer instruction [63:48]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ3X11_RFU_AcsmSeq3x11_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ3X11_RFU_AcsmSeq3x11_SHIFT (0U)
/*! RFU_AcsmSeq3x11 - RFU_AcsmSeq3x11 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ3X11_RFU_AcsmSeq3x11(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ3X11_RFU_AcsmSeq3x11_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ3X11_RFU_AcsmSeq3x11_MASK)
/*! @} */

/*! @name ACSMSEQ3X12 - ACSM sequencer instruction [63:48]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ3X12_RFU_AcsmSeq3x12_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ3X12_RFU_AcsmSeq3x12_SHIFT (0U)
/*! RFU_AcsmSeq3x12 - RFU_AcsmSeq3x12 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ3X12_RFU_AcsmSeq3x12(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ3X12_RFU_AcsmSeq3x12_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ3X12_RFU_AcsmSeq3x12_MASK)
/*! @} */

/*! @name ACSMSEQ3X13 - ACSM sequencer instruction [63:48]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ3X13_RFU_AcsmSeq3x13_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ3X13_RFU_AcsmSeq3x13_SHIFT (0U)
/*! RFU_AcsmSeq3x13 - RFU_AcsmSeq3x13 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ3X13_RFU_AcsmSeq3x13(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ3X13_RFU_AcsmSeq3x13_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ3X13_RFU_AcsmSeq3x13_MASK)
/*! @} */

/*! @name ACSMSEQ3X14 - ACSM sequencer instruction [63:48]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ3X14_RFU_AcsmSeq3x14_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ3X14_RFU_AcsmSeq3x14_SHIFT (0U)
/*! RFU_AcsmSeq3x14 - RFU_AcsmSeq3x14 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ3X14_RFU_AcsmSeq3x14(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ3X14_RFU_AcsmSeq3x14_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ3X14_RFU_AcsmSeq3x14_MASK)
/*! @} */

/*! @name ACSMSEQ3X15 - ACSM sequencer instruction [63:48]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ3X15_RFU_AcsmSeq3x15_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ3X15_RFU_AcsmSeq3x15_SHIFT (0U)
/*! RFU_AcsmSeq3x15 - RFU_AcsmSeq3x15 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ3X15_RFU_AcsmSeq3x15(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ3X15_RFU_AcsmSeq3x15_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ3X15_RFU_AcsmSeq3x15_MASK)
/*! @} */

/*! @name ACSMSEQ3X16 - ACSM sequencer instruction [63:48]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ3X16_RFU_AcsmSeq3x16_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ3X16_RFU_AcsmSeq3x16_SHIFT (0U)
/*! RFU_AcsmSeq3x16 - RFU_AcsmSeq3x16 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ3X16_RFU_AcsmSeq3x16(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ3X16_RFU_AcsmSeq3x16_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ3X16_RFU_AcsmSeq3x16_MASK)
/*! @} */

/*! @name ACSMSEQ3X17 - ACSM sequencer instruction [63:48]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ3X17_RFU_AcsmSeq3x17_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ3X17_RFU_AcsmSeq3x17_SHIFT (0U)
/*! RFU_AcsmSeq3x17 - RFU_AcsmSeq3x17 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ3X17_RFU_AcsmSeq3x17(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ3X17_RFU_AcsmSeq3x17_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ3X17_RFU_AcsmSeq3x17_MASK)
/*! @} */

/*! @name ACSMSEQ3X18 - ACSM sequencer instruction [63:48]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ3X18_RFU_AcsmSeq3x18_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ3X18_RFU_AcsmSeq3x18_SHIFT (0U)
/*! RFU_AcsmSeq3x18 - RFU_AcsmSeq3x18 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ3X18_RFU_AcsmSeq3x18(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ3X18_RFU_AcsmSeq3x18_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ3X18_RFU_AcsmSeq3x18_MASK)
/*! @} */

/*! @name ACSMSEQ3X19 - ACSM sequencer instruction [63:48]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ3X19_RFU_AcsmSeq3x19_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ3X19_RFU_AcsmSeq3x19_SHIFT (0U)
/*! RFU_AcsmSeq3x19 - RFU_AcsmSeq3x19 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ3X19_RFU_AcsmSeq3x19(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ3X19_RFU_AcsmSeq3x19_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ3X19_RFU_AcsmSeq3x19_MASK)
/*! @} */

/*! @name ACSMSEQ3X20 - ACSM sequencer instruction [63:48]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ3X20_RFU_AcsmSeq3x20_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ3X20_RFU_AcsmSeq3x20_SHIFT (0U)
/*! RFU_AcsmSeq3x20 - RFU_AcsmSeq3x20 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ3X20_RFU_AcsmSeq3x20(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ3X20_RFU_AcsmSeq3x20_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ3X20_RFU_AcsmSeq3x20_MASK)
/*! @} */

/*! @name ACSMSEQ3X21 - ACSM sequencer instruction [63:48]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ3X21_RFU_AcsmSeq3x21_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ3X21_RFU_AcsmSeq3x21_SHIFT (0U)
/*! RFU_AcsmSeq3x21 - RFU_AcsmSeq3x21 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ3X21_RFU_AcsmSeq3x21(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ3X21_RFU_AcsmSeq3x21_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ3X21_RFU_AcsmSeq3x21_MASK)
/*! @} */

/*! @name ACSMSEQ3X22 - ACSM sequencer instruction [63:48]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ3X22_RFU_AcsmSeq3x22_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ3X22_RFU_AcsmSeq3x22_SHIFT (0U)
/*! RFU_AcsmSeq3x22 - RFU_AcsmSeq3x22 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ3X22_RFU_AcsmSeq3x22(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ3X22_RFU_AcsmSeq3x22_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ3X22_RFU_AcsmSeq3x22_MASK)
/*! @} */

/*! @name ACSMSEQ3X23 - ACSM sequencer instruction [63:48]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ3X23_RFU_AcsmSeq3x23_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ3X23_RFU_AcsmSeq3x23_SHIFT (0U)
/*! RFU_AcsmSeq3x23 - RFU_AcsmSeq3x23 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ3X23_RFU_AcsmSeq3x23(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ3X23_RFU_AcsmSeq3x23_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ3X23_RFU_AcsmSeq3x23_MASK)
/*! @} */

/*! @name ACSMSEQ3X24 - ACSM sequencer instruction [63:48]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ3X24_RFU_AcsmSeq3x24_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ3X24_RFU_AcsmSeq3x24_SHIFT (0U)
/*! RFU_AcsmSeq3x24 - RFU_AcsmSeq3x24 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ3X24_RFU_AcsmSeq3x24(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ3X24_RFU_AcsmSeq3x24_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ3X24_RFU_AcsmSeq3x24_MASK)
/*! @} */

/*! @name ACSMSEQ3X25 - ACSM sequencer instruction [63:48]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ3X25_RFU_AcsmSeq3x25_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ3X25_RFU_AcsmSeq3x25_SHIFT (0U)
/*! RFU_AcsmSeq3x25 - RFU_AcsmSeq3x25 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ3X25_RFU_AcsmSeq3x25(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ3X25_RFU_AcsmSeq3x25_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ3X25_RFU_AcsmSeq3x25_MASK)
/*! @} */

/*! @name ACSMSEQ3X26 - ACSM sequencer instruction [63:48]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ3X26_RFU_AcsmSeq3x26_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ3X26_RFU_AcsmSeq3x26_SHIFT (0U)
/*! RFU_AcsmSeq3x26 - RFU_AcsmSeq3x26 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ3X26_RFU_AcsmSeq3x26(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ3X26_RFU_AcsmSeq3x26_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ3X26_RFU_AcsmSeq3x26_MASK)
/*! @} */

/*! @name ACSMSEQ3X27 - ACSM sequencer instruction [63:48]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ3X27_RFU_AcsmSeq3x27_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ3X27_RFU_AcsmSeq3x27_SHIFT (0U)
/*! RFU_AcsmSeq3x27 - RFU_AcsmSeq3x27 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ3X27_RFU_AcsmSeq3x27(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ3X27_RFU_AcsmSeq3x27_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ3X27_RFU_AcsmSeq3x27_MASK)
/*! @} */

/*! @name ACSMSEQ3X28 - ACSM sequencer instruction [63:48]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ3X28_RFU_AcsmSeq3x28_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ3X28_RFU_AcsmSeq3x28_SHIFT (0U)
/*! RFU_AcsmSeq3x28 - RFU_AcsmSeq3x28 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ3X28_RFU_AcsmSeq3x28(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ3X28_RFU_AcsmSeq3x28_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ3X28_RFU_AcsmSeq3x28_MASK)
/*! @} */

/*! @name ACSMSEQ3X29 - ACSM sequencer instruction [63:48]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ3X29_RFU_AcsmSeq3x29_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ3X29_RFU_AcsmSeq3x29_SHIFT (0U)
/*! RFU_AcsmSeq3x29 - RFU_AcsmSeq3x29 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ3X29_RFU_AcsmSeq3x29(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ3X29_RFU_AcsmSeq3x29_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ3X29_RFU_AcsmSeq3x29_MASK)
/*! @} */

/*! @name ACSMSEQ3X30 - ACSM sequencer instruction [63:48]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ3X30_RFU_AcsmSeq3x30_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ3X30_RFU_AcsmSeq3x30_SHIFT (0U)
/*! RFU_AcsmSeq3x30 - RFU_AcsmSeq3x30 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ3X30_RFU_AcsmSeq3x30(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ3X30_RFU_AcsmSeq3x30_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ3X30_RFU_AcsmSeq3x30_MASK)
/*! @} */

/*! @name ACSMSEQ3X31 - ACSM sequencer instruction [63:48]. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMSEQ3X31_RFU_AcsmSeq3x31_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMSEQ3X31_RFU_AcsmSeq3x31_SHIFT (0U)
/*! RFU_AcsmSeq3x31 - RFU_AcsmSeq3x31 */
#define DWC_DDRPHYA_ACSM_ACSMSEQ3X31_RFU_AcsmSeq3x31(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMSEQ3X31_RFU_AcsmSeq3x31_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMSEQ3X31_RFU_AcsmSeq3x31_MASK)
/*! @} */

/*! @name ACSMPLAYBACK0X0_P0 - ACSM Playback Engine Register 0 for Entry 0 */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X0_P0_AcsmPlayback0x0_p0_MASK (0xFFFU)
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X0_P0_AcsmPlayback0x0_p0_SHIFT (0U)
/*! AcsmPlayback0x0_p0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() for protocols that support DRAM drift compensation. */
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X0_P0_AcsmPlayback0x0_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X0_P0_AcsmPlayback0x0_p0_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X0_P0_AcsmPlayback0x0_p0_MASK)
/*! @} */

/*! @name ACSMPLAYBACK1X0_P0 - ACSM Playback Engine Register 1 for Entry 0 */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X0_P0_AcsmPlayback1x0_p0_MASK (0xFFFU)
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X0_P0_AcsmPlayback1x0_p0_SHIFT (0U)
/*! AcsmPlayback1x0_p0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() for protocols that support DRAM drift compensation. */
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X0_P0_AcsmPlayback1x0_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X0_P0_AcsmPlayback1x0_p0_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X0_P0_AcsmPlayback1x0_p0_MASK)
/*! @} */

/*! @name ACSMPLAYBACK0X1_P0 - ACSM Playback Engine Register 0 for Entry 1 */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X1_P0_AcsmPlayback0x1_p0_MASK (0xFFFU)
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X1_P0_AcsmPlayback0x1_p0_SHIFT (0U)
/*! AcsmPlayback0x1_p0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() for protocols that support DRAM drift compensation. */
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X1_P0_AcsmPlayback0x1_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X1_P0_AcsmPlayback0x1_p0_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X1_P0_AcsmPlayback0x1_p0_MASK)
/*! @} */

/*! @name ACSMPLAYBACK1X1_P0 - ACSM Playback Engine Register 1 for Entry 1 */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X1_P0_AcsmPlayback1x1_p0_MASK (0xFFFU)
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X1_P0_AcsmPlayback1x1_p0_SHIFT (0U)
/*! AcsmPlayback1x1_p0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() for protocols that support DRAM drift compensation. */
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X1_P0_AcsmPlayback1x1_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X1_P0_AcsmPlayback1x1_p0_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X1_P0_AcsmPlayback1x1_p0_MASK)
/*! @} */

/*! @name ACSMPLAYBACK0X2_P0 - ACSM Playback Engine Register 0 for Entry 2 */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X2_P0_AcsmPlayback0x2_p0_MASK (0xFFFU)
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X2_P0_AcsmPlayback0x2_p0_SHIFT (0U)
/*! AcsmPlayback0x2_p0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() for protocols that support DRAM drift compensation. */
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X2_P0_AcsmPlayback0x2_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X2_P0_AcsmPlayback0x2_p0_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X2_P0_AcsmPlayback0x2_p0_MASK)
/*! @} */

/*! @name ACSMPLAYBACK1X2_P0 - ACSM Playback Engine Register 1 for Entry 2 */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X2_P0_AcsmPlayback1x2_p0_MASK (0xFFFU)
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X2_P0_AcsmPlayback1x2_p0_SHIFT (0U)
/*! AcsmPlayback1x2_p0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() for protocols that support DRAM drift compensation. */
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X2_P0_AcsmPlayback1x2_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X2_P0_AcsmPlayback1x2_p0_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X2_P0_AcsmPlayback1x2_p0_MASK)
/*! @} */

/*! @name ACSMPLAYBACK0X3_P0 - ACSM Playback Engine Register 0 for Entry 3 */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X3_P0_AcsmPlayback0x3_p0_MASK (0xFFFU)
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X3_P0_AcsmPlayback0x3_p0_SHIFT (0U)
/*! AcsmPlayback0x3_p0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() for protocols that support DRAM drift compensation. */
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X3_P0_AcsmPlayback0x3_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X3_P0_AcsmPlayback0x3_p0_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X3_P0_AcsmPlayback0x3_p0_MASK)
/*! @} */

/*! @name ACSMPLAYBACK1X3_P0 - ACSM Playback Engine Register 1 for Entry 3 */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X3_P0_AcsmPlayback1x3_p0_MASK (0xFFFU)
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X3_P0_AcsmPlayback1x3_p0_SHIFT (0U)
/*! AcsmPlayback1x3_p0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() for protocols that support DRAM drift compensation. */
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X3_P0_AcsmPlayback1x3_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X3_P0_AcsmPlayback1x3_p0_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X3_P0_AcsmPlayback1x3_p0_MASK)
/*! @} */

/*! @name ACSMPLAYBACK0X4_P0 - ACSM Playback Engine Register 0 for Entry 4 */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X4_P0_AcsmPlayback0x4_p0_MASK (0xFFFU)
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X4_P0_AcsmPlayback0x4_p0_SHIFT (0U)
/*! AcsmPlayback0x4_p0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() for protocols that support DRAM drift compensation. */
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X4_P0_AcsmPlayback0x4_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X4_P0_AcsmPlayback0x4_p0_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X4_P0_AcsmPlayback0x4_p0_MASK)
/*! @} */

/*! @name ACSMPLAYBACK1X4_P0 - ACSM Playback Engine Register 1 for Entry 4 */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X4_P0_AcsmPlayback1x4_p0_MASK (0xFFFU)
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X4_P0_AcsmPlayback1x4_p0_SHIFT (0U)
/*! AcsmPlayback1x4_p0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() for protocols that support DRAM drift compensation. */
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X4_P0_AcsmPlayback1x4_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X4_P0_AcsmPlayback1x4_p0_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X4_P0_AcsmPlayback1x4_p0_MASK)
/*! @} */

/*! @name ACSMPLAYBACK0X5_P0 - ACSM Playback Engine Register 0 for Entry 5 */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X5_P0_AcsmPlayback0x5_p0_MASK (0xFFFU)
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X5_P0_AcsmPlayback0x5_p0_SHIFT (0U)
/*! AcsmPlayback0x5_p0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() for protocols that support DRAM drift compensation. */
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X5_P0_AcsmPlayback0x5_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X5_P0_AcsmPlayback0x5_p0_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X5_P0_AcsmPlayback0x5_p0_MASK)
/*! @} */

/*! @name ACSMPLAYBACK1X5_P0 - ACSM Playback Engine Register 1 for Entry 5 */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X5_P0_AcsmPlayback1x5_p0_MASK (0xFFFU)
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X5_P0_AcsmPlayback1x5_p0_SHIFT (0U)
/*! AcsmPlayback1x5_p0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() for protocols that support DRAM drift compensation. */
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X5_P0_AcsmPlayback1x5_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X5_P0_AcsmPlayback1x5_p0_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X5_P0_AcsmPlayback1x5_p0_MASK)
/*! @} */

/*! @name ACSMPLAYBACK0X6_P0 - ACSM Playback Engine Register 0 for Entry 6 */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X6_P0_AcsmPlayback0x6_p0_MASK (0xFFFU)
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X6_P0_AcsmPlayback0x6_p0_SHIFT (0U)
/*! AcsmPlayback0x6_p0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() for protocols that support DRAM drift compensation. */
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X6_P0_AcsmPlayback0x6_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X6_P0_AcsmPlayback0x6_p0_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X6_P0_AcsmPlayback0x6_p0_MASK)
/*! @} */

/*! @name ACSMPLAYBACK1X6_P0 - ACSM Playback Engine Register 1 for Entry 6 */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X6_P0_AcsmPlayback1x6_p0_MASK (0xFFFU)
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X6_P0_AcsmPlayback1x6_p0_SHIFT (0U)
/*! AcsmPlayback1x6_p0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() for protocols that support DRAM drift compensation. */
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X6_P0_AcsmPlayback1x6_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X6_P0_AcsmPlayback1x6_p0_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X6_P0_AcsmPlayback1x6_p0_MASK)
/*! @} */

/*! @name ACSMPLAYBACK0X7_P0 - ACSM Playback Engine Register 0 for Entry 7 */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X7_P0_AcsmPlayback0x7_p0_MASK (0xFFFU)
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X7_P0_AcsmPlayback0x7_p0_SHIFT (0U)
/*! AcsmPlayback0x7_p0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() for protocols that support DRAM drift compensation. */
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X7_P0_AcsmPlayback0x7_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X7_P0_AcsmPlayback0x7_p0_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X7_P0_AcsmPlayback0x7_p0_MASK)
/*! @} */

/*! @name ACSMPLAYBACK1X7_P0 - ACSM Playback Engine Register 1 for Entry 7 */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X7_P0_AcsmPlayback1x7_p0_MASK (0xFFFU)
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X7_P0_AcsmPlayback1x7_p0_SHIFT (0U)
/*! AcsmPlayback1x7_p0 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() for protocols that support DRAM drift compensation. */
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X7_P0_AcsmPlayback1x7_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X7_P0_AcsmPlayback1x7_p0_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X7_P0_AcsmPlayback1x7_p0_MASK)
/*! @} */

/*! @name ACSMPSTATEOVREN - ACSM Pstate Override Enable */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMPSTATEOVREN_AcsmPStateOvrEn_MASK (0x1U)
#define DWC_DDRPHYA_ACSM_ACSMPSTATEOVREN_AcsmPStateOvrEn_SHIFT (0U)
/*! AcsmPStateOvrEn - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() for Controling Playback Engine */
#define DWC_DDRPHYA_ACSM_ACSMPSTATEOVREN_AcsmPStateOvrEn(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMPSTATEOVREN_AcsmPStateOvrEn_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMPSTATEOVREN_AcsmPStateOvrEn_MASK)
/*! @} */

/*! @name ACSMPSTATEOVRVAL - ACSM Pstate Override and Control */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMPSTATEOVRVAL_AcsmPStateOvrVal_MASK (0xFU)
#define DWC_DDRPHYA_ACSM_ACSMPSTATEOVRVAL_AcsmPStateOvrVal_SHIFT (0U)
/*! AcsmPStateOvrVal - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() for Controling Playback Engine */
#define DWC_DDRPHYA_ACSM_ACSMPSTATEOVRVAL_AcsmPStateOvrVal(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMPSTATEOVRVAL_AcsmPStateOvrVal_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMPSTATEOVRVAL_AcsmPStateOvrVal_MASK)
/*! @} */

/*! @name ACSMCTRL23 - ACSM CS instruction field mask. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMCTRL23_RFU_AcsmCtrl23_MASK (0x1FFFU)
#define DWC_DDRPHYA_ACSM_ACSMCTRL23_RFU_AcsmCtrl23_SHIFT (0U)
/*! RFU_AcsmCtrl23 - RFU_AcsmCtrl23 */
#define DWC_DDRPHYA_ACSM_ACSMCTRL23_RFU_AcsmCtrl23(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMCTRL23_RFU_AcsmCtrl23_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMCTRL23_RFU_AcsmCtrl23_MASK)
/*! @} */

/*! @name ACSMCKEVAL - ACSM CKE value control */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMCKEVAL_AcsmCkeVal_MASK (0xFU)
#define DWC_DDRPHYA_ACSM_ACSMCKEVAL_AcsmCkeVal_SHIFT (0U)
/*! AcsmCkeVal - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_ACSM_ACSMCKEVAL_AcsmCkeVal(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMCKEVAL_AcsmCkeVal_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMCKEVAL_AcsmCkeVal_MASK)
/*! @} */

/*! @name LOWSPEEDCLOCKDIVIDER - ACSM low speed clock divider */
/*! @{ */

#define DWC_DDRPHYA_ACSM_LOWSPEEDCLOCKDIVIDER_LowSpeedClockDivider_MASK (0x3FU)
#define DWC_DDRPHYA_ACSM_LOWSPEEDCLOCKDIVIDER_LowSpeedClockDivider_SHIFT (0U)
/*! LowSpeedClockDivider - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_ACSM_LOWSPEEDCLOCKDIVIDER_LowSpeedClockDivider(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_LOWSPEEDCLOCKDIVIDER_LowSpeedClockDivider_SHIFT)) & DWC_DDRPHYA_ACSM_LOWSPEEDCLOCKDIVIDER_LowSpeedClockDivider_MASK)
/*! @} */

/*! @name ACSMCSMAPCTRL0 - ACSM CS to Dest/ODT map. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMCSMAPCTRL0_RFU_AcsmCsMapCtrl0_MASK (0x7FFFU)
#define DWC_DDRPHYA_ACSM_ACSMCSMAPCTRL0_RFU_AcsmCsMapCtrl0_SHIFT (0U)
/*! RFU_AcsmCsMapCtrl0 - RFU_AcsmCsMapCtrl0 */
#define DWC_DDRPHYA_ACSM_ACSMCSMAPCTRL0_RFU_AcsmCsMapCtrl0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMCSMAPCTRL0_RFU_AcsmCsMapCtrl0_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMCSMAPCTRL0_RFU_AcsmCsMapCtrl0_MASK)
/*! @} */

/*! @name ACSMCSMAPCTRL1 - ACSM CS to Dest/ODT map. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMCSMAPCTRL1_RFU_AcsmCsMapCtrl1_MASK (0x7FFFU)
#define DWC_DDRPHYA_ACSM_ACSMCSMAPCTRL1_RFU_AcsmCsMapCtrl1_SHIFT (0U)
/*! RFU_AcsmCsMapCtrl1 - RFU_AcsmCsMapCtrl1 */
#define DWC_DDRPHYA_ACSM_ACSMCSMAPCTRL1_RFU_AcsmCsMapCtrl1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMCSMAPCTRL1_RFU_AcsmCsMapCtrl1_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMCSMAPCTRL1_RFU_AcsmCsMapCtrl1_MASK)
/*! @} */

/*! @name ACSMCSMAPCTRL2 - ACSM CS to Dest/ODT map. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMCSMAPCTRL2_RFU_AcsmCsMapCtrl2_MASK (0x7FFFU)
#define DWC_DDRPHYA_ACSM_ACSMCSMAPCTRL2_RFU_AcsmCsMapCtrl2_SHIFT (0U)
/*! RFU_AcsmCsMapCtrl2 - RFU_AcsmCsMapCtrl2 */
#define DWC_DDRPHYA_ACSM_ACSMCSMAPCTRL2_RFU_AcsmCsMapCtrl2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMCSMAPCTRL2_RFU_AcsmCsMapCtrl2_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMCSMAPCTRL2_RFU_AcsmCsMapCtrl2_MASK)
/*! @} */

/*! @name ACSMCSMAPCTRL3 - ACSM CS to Dest/ODT map. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMCSMAPCTRL3_RFU_AcsmCsMapCtrl3_MASK (0x7FFFU)
#define DWC_DDRPHYA_ACSM_ACSMCSMAPCTRL3_RFU_AcsmCsMapCtrl3_SHIFT (0U)
/*! RFU_AcsmCsMapCtrl3 - RFU_AcsmCsMapCtrl3 */
#define DWC_DDRPHYA_ACSM_ACSMCSMAPCTRL3_RFU_AcsmCsMapCtrl3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMCSMAPCTRL3_RFU_AcsmCsMapCtrl3_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMCSMAPCTRL3_RFU_AcsmCsMapCtrl3_MASK)
/*! @} */

/*! @name ACSMCSMAPCTRL4 - ACSM CS to Dest/ODT map. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMCSMAPCTRL4_RFU_AcsmCsMapCtrl4_MASK (0x7FFFU)
#define DWC_DDRPHYA_ACSM_ACSMCSMAPCTRL4_RFU_AcsmCsMapCtrl4_SHIFT (0U)
/*! RFU_AcsmCsMapCtrl4 - RFU_AcsmCsMapCtrl4 */
#define DWC_DDRPHYA_ACSM_ACSMCSMAPCTRL4_RFU_AcsmCsMapCtrl4(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMCSMAPCTRL4_RFU_AcsmCsMapCtrl4_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMCSMAPCTRL4_RFU_AcsmCsMapCtrl4_MASK)
/*! @} */

/*! @name ACSMCSMAPCTRL5 - ACSM CS to Dest/ODT map. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMCSMAPCTRL5_RFU_AcsmCsMapCtrl5_MASK (0x7FFFU)
#define DWC_DDRPHYA_ACSM_ACSMCSMAPCTRL5_RFU_AcsmCsMapCtrl5_SHIFT (0U)
/*! RFU_AcsmCsMapCtrl5 - RFU_AcsmCsMapCtrl5 */
#define DWC_DDRPHYA_ACSM_ACSMCSMAPCTRL5_RFU_AcsmCsMapCtrl5(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMCSMAPCTRL5_RFU_AcsmCsMapCtrl5_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMCSMAPCTRL5_RFU_AcsmCsMapCtrl5_MASK)
/*! @} */

/*! @name ACSMCSMAPCTRL6 - ACSM CS to Dest/ODT map. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMCSMAPCTRL6_RFU_AcsmCsMapCtrl6_MASK (0x7FFFU)
#define DWC_DDRPHYA_ACSM_ACSMCSMAPCTRL6_RFU_AcsmCsMapCtrl6_SHIFT (0U)
/*! RFU_AcsmCsMapCtrl6 - RFU_AcsmCsMapCtrl6 */
#define DWC_DDRPHYA_ACSM_ACSMCSMAPCTRL6_RFU_AcsmCsMapCtrl6(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMCSMAPCTRL6_RFU_AcsmCsMapCtrl6_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMCSMAPCTRL6_RFU_AcsmCsMapCtrl6_MASK)
/*! @} */

/*! @name ACSMCSMAPCTRL7 - ACSM CS to Dest/ODT map. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMCSMAPCTRL7_RFU_AcsmCsMapCtrl7_MASK (0x7FFFU)
#define DWC_DDRPHYA_ACSM_ACSMCSMAPCTRL7_RFU_AcsmCsMapCtrl7_SHIFT (0U)
/*! RFU_AcsmCsMapCtrl7 - RFU_AcsmCsMapCtrl7 */
#define DWC_DDRPHYA_ACSM_ACSMCSMAPCTRL7_RFU_AcsmCsMapCtrl7(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMCSMAPCTRL7_RFU_AcsmCsMapCtrl7_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMCSMAPCTRL7_RFU_AcsmCsMapCtrl7_MASK)
/*! @} */

/*! @name ACSMCSMAPCTRL8 - ACSM CS to Dest/ODT map. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMCSMAPCTRL8_RFU_AcsmCsMapCtrl8_MASK (0x7FFFU)
#define DWC_DDRPHYA_ACSM_ACSMCSMAPCTRL8_RFU_AcsmCsMapCtrl8_SHIFT (0U)
/*! RFU_AcsmCsMapCtrl8 - RFU_AcsmCsMapCtrl8 */
#define DWC_DDRPHYA_ACSM_ACSMCSMAPCTRL8_RFU_AcsmCsMapCtrl8(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMCSMAPCTRL8_RFU_AcsmCsMapCtrl8_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMCSMAPCTRL8_RFU_AcsmCsMapCtrl8_MASK)
/*! @} */

/*! @name ACSMCSMAPCTRL9 - ACSM CS to Dest/ODT map. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMCSMAPCTRL9_RFU_AcsmCsMapCtrl9_MASK (0x7FFFU)
#define DWC_DDRPHYA_ACSM_ACSMCSMAPCTRL9_RFU_AcsmCsMapCtrl9_SHIFT (0U)
/*! RFU_AcsmCsMapCtrl9 - RFU_AcsmCsMapCtrl9 */
#define DWC_DDRPHYA_ACSM_ACSMCSMAPCTRL9_RFU_AcsmCsMapCtrl9(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMCSMAPCTRL9_RFU_AcsmCsMapCtrl9_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMCSMAPCTRL9_RFU_AcsmCsMapCtrl9_MASK)
/*! @} */

/*! @name ACSMCSMAPCTRL10 - ACSM CS to Dest/ODT map. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMCSMAPCTRL10_RFU_AcsmCsMapCtrl10_MASK (0x7FFFU)
#define DWC_DDRPHYA_ACSM_ACSMCSMAPCTRL10_RFU_AcsmCsMapCtrl10_SHIFT (0U)
/*! RFU_AcsmCsMapCtrl10 - RFU_AcsmCsMapCtrl10 */
#define DWC_DDRPHYA_ACSM_ACSMCSMAPCTRL10_RFU_AcsmCsMapCtrl10(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMCSMAPCTRL10_RFU_AcsmCsMapCtrl10_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMCSMAPCTRL10_RFU_AcsmCsMapCtrl10_MASK)
/*! @} */

/*! @name ACSMCSMAPCTRL11 - ACSM CS to Dest/ODT map. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMCSMAPCTRL11_RFU_AcsmCsMapCtrl11_MASK (0x7FFFU)
#define DWC_DDRPHYA_ACSM_ACSMCSMAPCTRL11_RFU_AcsmCsMapCtrl11_SHIFT (0U)
/*! RFU_AcsmCsMapCtrl11 - RFU_AcsmCsMapCtrl11 */
#define DWC_DDRPHYA_ACSM_ACSMCSMAPCTRL11_RFU_AcsmCsMapCtrl11(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMCSMAPCTRL11_RFU_AcsmCsMapCtrl11_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMCSMAPCTRL11_RFU_AcsmCsMapCtrl11_MASK)
/*! @} */

/*! @name ACSMCSMAPCTRL12 - ACSM CS to Dest/ODT map. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMCSMAPCTRL12_RFU_AcsmCsMapCtrl12_MASK (0x7FFFU)
#define DWC_DDRPHYA_ACSM_ACSMCSMAPCTRL12_RFU_AcsmCsMapCtrl12_SHIFT (0U)
/*! RFU_AcsmCsMapCtrl12 - RFU_AcsmCsMapCtrl12 */
#define DWC_DDRPHYA_ACSM_ACSMCSMAPCTRL12_RFU_AcsmCsMapCtrl12(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMCSMAPCTRL12_RFU_AcsmCsMapCtrl12_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMCSMAPCTRL12_RFU_AcsmCsMapCtrl12_MASK)
/*! @} */

/*! @name ACSMCSMAPCTRL13 - ACSM CS to Dest/ODT map. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMCSMAPCTRL13_RFU_AcsmCsMapCtrl13_MASK (0x7FFFU)
#define DWC_DDRPHYA_ACSM_ACSMCSMAPCTRL13_RFU_AcsmCsMapCtrl13_SHIFT (0U)
/*! RFU_AcsmCsMapCtrl13 - RFU_AcsmCsMapCtrl13 */
#define DWC_DDRPHYA_ACSM_ACSMCSMAPCTRL13_RFU_AcsmCsMapCtrl13(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMCSMAPCTRL13_RFU_AcsmCsMapCtrl13_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMCSMAPCTRL13_RFU_AcsmCsMapCtrl13_MASK)
/*! @} */

/*! @name ACSMCSMAPCTRL14 - ACSM CS to Dest/ODT map. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMCSMAPCTRL14_RFU_AcsmCsMapCtrl14_MASK (0x7FFFU)
#define DWC_DDRPHYA_ACSM_ACSMCSMAPCTRL14_RFU_AcsmCsMapCtrl14_SHIFT (0U)
/*! RFU_AcsmCsMapCtrl14 - RFU_AcsmCsMapCtrl14 */
#define DWC_DDRPHYA_ACSM_ACSMCSMAPCTRL14_RFU_AcsmCsMapCtrl14(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMCSMAPCTRL14_RFU_AcsmCsMapCtrl14_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMCSMAPCTRL14_RFU_AcsmCsMapCtrl14_MASK)
/*! @} */

/*! @name ACSMCSMAPCTRL15 - ACSM CS to Dest/ODT map. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMCSMAPCTRL15_RFU_AcsmCsMapCtrl15_MASK (0x7FFFU)
#define DWC_DDRPHYA_ACSM_ACSMCSMAPCTRL15_RFU_AcsmCsMapCtrl15_SHIFT (0U)
/*! RFU_AcsmCsMapCtrl15 - RFU_AcsmCsMapCtrl15 */
#define DWC_DDRPHYA_ACSM_ACSMCSMAPCTRL15_RFU_AcsmCsMapCtrl15(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMCSMAPCTRL15_RFU_AcsmCsMapCtrl15_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMCSMAPCTRL15_RFU_AcsmCsMapCtrl15_MASK)
/*! @} */

/*! @name ACSMODTCTRL0 - ACSM CS to ODT pattern map. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMODTCTRL0_RFU_AcsmOdtCtrl0_MASK (0xFFU)
#define DWC_DDRPHYA_ACSM_ACSMODTCTRL0_RFU_AcsmOdtCtrl0_SHIFT (0U)
/*! RFU_AcsmOdtCtrl0 - RFU_AcsmOdtCtrl0 */
#define DWC_DDRPHYA_ACSM_ACSMODTCTRL0_RFU_AcsmOdtCtrl0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMODTCTRL0_RFU_AcsmOdtCtrl0_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMODTCTRL0_RFU_AcsmOdtCtrl0_MASK)
/*! @} */

/*! @name ACSMODTCTRL1 - ACSM CS to ODT pattern map. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMODTCTRL1_RFU_AcsmOdtCtrl1_MASK (0xFFU)
#define DWC_DDRPHYA_ACSM_ACSMODTCTRL1_RFU_AcsmOdtCtrl1_SHIFT (0U)
/*! RFU_AcsmOdtCtrl1 - RFU_AcsmOdtCtrl1 */
#define DWC_DDRPHYA_ACSM_ACSMODTCTRL1_RFU_AcsmOdtCtrl1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMODTCTRL1_RFU_AcsmOdtCtrl1_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMODTCTRL1_RFU_AcsmOdtCtrl1_MASK)
/*! @} */

/*! @name ACSMODTCTRL2 - ACSM CS to ODT pattern map. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMODTCTRL2_RFU_AcsmOdtCtrl2_MASK (0xFFU)
#define DWC_DDRPHYA_ACSM_ACSMODTCTRL2_RFU_AcsmOdtCtrl2_SHIFT (0U)
/*! RFU_AcsmOdtCtrl2 - RFU_AcsmOdtCtrl2 */
#define DWC_DDRPHYA_ACSM_ACSMODTCTRL2_RFU_AcsmOdtCtrl2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMODTCTRL2_RFU_AcsmOdtCtrl2_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMODTCTRL2_RFU_AcsmOdtCtrl2_MASK)
/*! @} */

/*! @name ACSMODTCTRL3 - ACSM CS to ODT pattern map. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMODTCTRL3_RFU_AcsmOdtCtrl3_MASK (0xFFU)
#define DWC_DDRPHYA_ACSM_ACSMODTCTRL3_RFU_AcsmOdtCtrl3_SHIFT (0U)
/*! RFU_AcsmOdtCtrl3 - RFU_AcsmOdtCtrl3 */
#define DWC_DDRPHYA_ACSM_ACSMODTCTRL3_RFU_AcsmOdtCtrl3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMODTCTRL3_RFU_AcsmOdtCtrl3_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMODTCTRL3_RFU_AcsmOdtCtrl3_MASK)
/*! @} */

/*! @name ACSMODTCTRL4 - ACSM CS to ODT pattern map. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMODTCTRL4_RFU_AcsmOdtCtrl4_MASK (0xFFU)
#define DWC_DDRPHYA_ACSM_ACSMODTCTRL4_RFU_AcsmOdtCtrl4_SHIFT (0U)
/*! RFU_AcsmOdtCtrl4 - RFU_AcsmOdtCtrl4 */
#define DWC_DDRPHYA_ACSM_ACSMODTCTRL4_RFU_AcsmOdtCtrl4(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMODTCTRL4_RFU_AcsmOdtCtrl4_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMODTCTRL4_RFU_AcsmOdtCtrl4_MASK)
/*! @} */

/*! @name ACSMODTCTRL5 - ACSM CS to ODT pattern map. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMODTCTRL5_RFU_AcsmOdtCtrl5_MASK (0xFFU)
#define DWC_DDRPHYA_ACSM_ACSMODTCTRL5_RFU_AcsmOdtCtrl5_SHIFT (0U)
/*! RFU_AcsmOdtCtrl5 - RFU_AcsmOdtCtrl5 */
#define DWC_DDRPHYA_ACSM_ACSMODTCTRL5_RFU_AcsmOdtCtrl5(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMODTCTRL5_RFU_AcsmOdtCtrl5_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMODTCTRL5_RFU_AcsmOdtCtrl5_MASK)
/*! @} */

/*! @name ACSMODTCTRL6 - ACSM CS to ODT pattern map. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMODTCTRL6_RFU_AcsmOdtCtrl6_MASK (0xFFU)
#define DWC_DDRPHYA_ACSM_ACSMODTCTRL6_RFU_AcsmOdtCtrl6_SHIFT (0U)
/*! RFU_AcsmOdtCtrl6 - RFU_AcsmOdtCtrl6 */
#define DWC_DDRPHYA_ACSM_ACSMODTCTRL6_RFU_AcsmOdtCtrl6(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMODTCTRL6_RFU_AcsmOdtCtrl6_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMODTCTRL6_RFU_AcsmOdtCtrl6_MASK)
/*! @} */

/*! @name ACSMODTCTRL7 - ACSM CS to ODT pattern map. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMODTCTRL7_RFU_AcsmOdtCtrl7_MASK (0xFFU)
#define DWC_DDRPHYA_ACSM_ACSMODTCTRL7_RFU_AcsmOdtCtrl7_SHIFT (0U)
/*! RFU_AcsmOdtCtrl7 - RFU_AcsmOdtCtrl7 */
#define DWC_DDRPHYA_ACSM_ACSMODTCTRL7_RFU_AcsmOdtCtrl7(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMODTCTRL7_RFU_AcsmOdtCtrl7_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMODTCTRL7_RFU_AcsmOdtCtrl7_MASK)
/*! @} */

/*! @name ACSMODTCTRL8 - ACSM ODT start/duration control. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMODTCTRL8_RFU_AcsmOdtCtrl8_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMODTCTRL8_RFU_AcsmOdtCtrl8_SHIFT (0U)
/*! RFU_AcsmOdtCtrl8 - RFU_AcsmOdtCtrl8 */
#define DWC_DDRPHYA_ACSM_ACSMODTCTRL8_RFU_AcsmOdtCtrl8(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMODTCTRL8_RFU_AcsmOdtCtrl8_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMODTCTRL8_RFU_AcsmOdtCtrl8_MASK)
/*! @} */

/*! @name ACSMCTRL16 - ACSM high address bits training control. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMCTRL16_RFU_AcsmCtrl16_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMCTRL16_RFU_AcsmCtrl16_SHIFT (0U)
/*! RFU_AcsmCtrl16 - RFU_AcsmCtrl16 */
#define DWC_DDRPHYA_ACSM_ACSMCTRL16_RFU_AcsmCtrl16(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMCTRL16_RFU_AcsmCtrl16_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMCTRL16_RFU_AcsmCtrl16_MASK)
/*! @} */

/*! @name LOWSPEEDCLOCKSTOPVAL - ACSM low speed clock divider stopped value */
/*! @{ */

#define DWC_DDRPHYA_ACSM_LOWSPEEDCLOCKSTOPVAL_LowSpeedClockStopVal_MASK (0x1U)
#define DWC_DDRPHYA_ACSM_LOWSPEEDCLOCKSTOPVAL_LowSpeedClockStopVal_SHIFT (0U)
/*! LowSpeedClockStopVal - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_ACSM_LOWSPEEDCLOCKSTOPVAL_LowSpeedClockStopVal(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_LOWSPEEDCLOCKSTOPVAL_LowSpeedClockStopVal_SHIFT)) & DWC_DDRPHYA_ACSM_LOWSPEEDCLOCKSTOPVAL_LowSpeedClockStopVal_MASK)
/*! @} */

/*! @name ACSMCTRL18 - ACSM sequence done. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMCTRL18_RFU_AcsmCtrl18_MASK (0x3U)
#define DWC_DDRPHYA_ACSM_ACSMCTRL18_RFU_AcsmCtrl18_SHIFT (0U)
/*! RFU_AcsmCtrl18 - RFU_AcsmCtrl18 */
#define DWC_DDRPHYA_ACSM_ACSMCTRL18_RFU_AcsmCtrl18(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMCTRL18_RFU_AcsmCtrl18_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMCTRL18_RFU_AcsmCtrl18_MASK)
/*! @} */

/*! @name ACSMCTRL19 - ACSM test observability control. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMCTRL19_RFU_AcsmCtrl19_MASK (0x7U)
#define DWC_DDRPHYA_ACSM_ACSMCTRL19_RFU_AcsmCtrl19_SHIFT (0U)
/*! RFU_AcsmCtrl19 - RFU_AcsmCtrl19 */
#define DWC_DDRPHYA_ACSM_ACSMCTRL19_RFU_AcsmCtrl19(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMCTRL19_RFU_AcsmCtrl19_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMCTRL19_RFU_AcsmCtrl19_MASK)
/*! @} */

/*! @name ACSMCTRL20 - ACSM test visibility port. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMCTRL20_RFU_AcsmCtrl20_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMCTRL20_RFU_AcsmCtrl20_SHIFT (0U)
/*! RFU_AcsmCtrl20 - RFU_AcsmCtrl20 */
#define DWC_DDRPHYA_ACSM_ACSMCTRL20_RFU_AcsmCtrl20(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMCTRL20_RFU_AcsmCtrl20_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMCTRL20_RFU_AcsmCtrl20_MASK)
/*! @} */

/*! @name ACSMCTRL21 - ACSM Legacy CS to DIMM mapping. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMCTRL21_RFU_AcsmCtrl21_MASK (0xFFFU)
#define DWC_DDRPHYA_ACSM_ACSMCTRL21_RFU_AcsmCtrl21_SHIFT (0U)
/*! RFU_AcsmCtrl21 - RFU_AcsmCtrl21 */
#define DWC_DDRPHYA_ACSM_ACSMCTRL21_RFU_AcsmCtrl21(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMCTRL21_RFU_AcsmCtrl21_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMCTRL21_RFU_AcsmCtrl21_MASK)
/*! @} */

/*! @name ACSMCTRL22 - ACSM Legacy CS to DIMM mapping. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMCTRL22_RFU_AcsmCtrl22_MASK (0xFFFU)
#define DWC_DDRPHYA_ACSM_ACSMCTRL22_RFU_AcsmCtrl22_SHIFT (0U)
/*! RFU_AcsmCtrl22 - RFU_AcsmCtrl22 */
#define DWC_DDRPHYA_ACSM_ACSMCTRL22_RFU_AcsmCtrl22(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMCTRL22_RFU_AcsmCtrl22_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMCTRL22_RFU_AcsmCtrl22_MASK)
/*! @} */

/*! @name ACSMCTRL0 - ACSM special operation modes and control. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMCTRL0_RFU_AcsmCtrl0_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMCTRL0_RFU_AcsmCtrl0_SHIFT (0U)
/*! RFU_AcsmCtrl0 - RFU_AcsmCtrl0 */
#define DWC_DDRPHYA_ACSM_ACSMCTRL0_RFU_AcsmCtrl0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMCTRL0_RFU_AcsmCtrl0_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMCTRL0_RFU_AcsmCtrl0_MASK)
/*! @} */

/*! @name ACSMCTRL1 - ACSM sequence repitition count. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMCTRL1_RFU_AcsmCtrl1_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMCTRL1_RFU_AcsmCtrl1_SHIFT (0U)
/*! RFU_AcsmCtrl1 - RFU_AcsmCtrl1 */
#define DWC_DDRPHYA_ACSM_ACSMCTRL1_RFU_AcsmCtrl1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMCTRL1_RFU_AcsmCtrl1_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMCTRL1_RFU_AcsmCtrl1_MASK)
/*! @} */

/*! @name ACSMCTRL2 - ACSM sequence start pointer. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMCTRL2_RFU_AcsmCtrl2_MASK (0x1FU)
#define DWC_DDRPHYA_ACSM_ACSMCTRL2_RFU_AcsmCtrl2_SHIFT (0U)
/*! RFU_AcsmCtrl2 - RFU_AcsmCtrl2 */
#define DWC_DDRPHYA_ACSM_ACSMCTRL2_RFU_AcsmCtrl2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMCTRL2_RFU_AcsmCtrl2_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMCTRL2_RFU_AcsmCtrl2_MASK)
/*! @} */

/*! @name ACSMCTRL3 - ACSM sequence loop pointer. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMCTRL3_RFU_AcsmCtrl3_MASK (0x1FU)
#define DWC_DDRPHYA_ACSM_ACSMCTRL3_RFU_AcsmCtrl3_SHIFT (0U)
/*! RFU_AcsmCtrl3 - RFU_AcsmCtrl3 */
#define DWC_DDRPHYA_ACSM_ACSMCTRL3_RFU_AcsmCtrl3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMCTRL3_RFU_AcsmCtrl3_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMCTRL3_RFU_AcsmCtrl3_MASK)
/*! @} */

/*! @name ACSMCTRL4 - ACSM sequence end loop pointer. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMCTRL4_RFU_AcsmCtrl4_MASK (0x1FU)
#define DWC_DDRPHYA_ACSM_ACSMCTRL4_RFU_AcsmCtrl4_SHIFT (0U)
/*! RFU_AcsmCtrl4 - RFU_AcsmCtrl4 */
#define DWC_DDRPHYA_ACSM_ACSMCTRL4_RFU_AcsmCtrl4(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMCTRL4_RFU_AcsmCtrl4_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMCTRL4_RFU_AcsmCtrl4_MASK)
/*! @} */

/*! @name ACSMCTRL5 - ACSM read latency control. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMCTRL5_RFU_AcsmCtrl5_MASK (0x3FFFU)
#define DWC_DDRPHYA_ACSM_ACSMCTRL5_RFU_AcsmCtrl5_SHIFT (0U)
/*! RFU_AcsmCtrl5 - RFU_AcsmCtrl5 */
#define DWC_DDRPHYA_ACSM_ACSMCTRL5_RFU_AcsmCtrl5(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMCTRL5_RFU_AcsmCtrl5_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMCTRL5_RFU_AcsmCtrl5_MASK)
/*! @} */

/*! @name ACSMCTRL6 - ACSM write latency control. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMCTRL6_RFU_AcsmCtrl6_MASK (0x7FFU)
#define DWC_DDRPHYA_ACSM_ACSMCTRL6_RFU_AcsmCtrl6_SHIFT (0U)
/*! RFU_AcsmCtrl6 - RFU_AcsmCtrl6 */
#define DWC_DDRPHYA_ACSM_ACSMCTRL6_RFU_AcsmCtrl6(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMCTRL6_RFU_AcsmCtrl6_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMCTRL6_RFU_AcsmCtrl6_MASK)
/*! @} */

/*! @name ACSMCTRL7 - ACSM algorithmic address generator control - row adr. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMCTRL7_RFU_AcsmCtrl7_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMCTRL7_RFU_AcsmCtrl7_SHIFT (0U)
/*! RFU_AcsmCtrl7 - RFU_AcsmCtrl7 */
#define DWC_DDRPHYA_ACSM_ACSMCTRL7_RFU_AcsmCtrl7(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMCTRL7_RFU_AcsmCtrl7_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMCTRL7_RFU_AcsmCtrl7_MASK)
/*! @} */

/*! @name ACSMCTRL8 - ACSM algorithmic address seed - row adr. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMCTRL8_RFU_AcsmCtrl8_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMCTRL8_RFU_AcsmCtrl8_SHIFT (0U)
/*! RFU_AcsmCtrl8 - RFU_AcsmCtrl8 */
#define DWC_DDRPHYA_ACSM_ACSMCTRL8_RFU_AcsmCtrl8(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMCTRL8_RFU_AcsmCtrl8_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMCTRL8_RFU_AcsmCtrl8_MASK)
/*! @} */

/*! @name ACSMCTRL9 - ACSM algorithmic address generator control - col adr. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMCTRL9_RFU_AcsmCtrl9_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMCTRL9_RFU_AcsmCtrl9_SHIFT (0U)
/*! RFU_AcsmCtrl9 - RFU_AcsmCtrl9 */
#define DWC_DDRPHYA_ACSM_ACSMCTRL9_RFU_AcsmCtrl9(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMCTRL9_RFU_AcsmCtrl9_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMCTRL9_RFU_AcsmCtrl9_MASK)
/*! @} */

/*! @name ACSMCTRL10 - ACSM algorithmic address seed - row adr. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMCTRL10_RFU_AcsmCtrl10_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMCTRL10_RFU_AcsmCtrl10_SHIFT (0U)
/*! RFU_AcsmCtrl10 - RFU_AcsmCtrl10 */
#define DWC_DDRPHYA_ACSM_ACSMCTRL10_RFU_AcsmCtrl10(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMCTRL10_RFU_AcsmCtrl10_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMCTRL10_RFU_AcsmCtrl10_MASK)
/*! @} */

/*! @name ACSMCTRL11 - ACSM algorithmic address increment val - row/col adr. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMCTRL11_RFU_AcsmCtrl11_MASK (0xFFFFU)
#define DWC_DDRPHYA_ACSM_ACSMCTRL11_RFU_AcsmCtrl11_SHIFT (0U)
/*! RFU_AcsmCtrl11 - RFU_AcsmCtrl11 */
#define DWC_DDRPHYA_ACSM_ACSMCTRL11_RFU_AcsmCtrl11(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMCTRL11_RFU_AcsmCtrl11_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMCTRL11_RFU_AcsmCtrl11_MASK)
/*! @} */

/*! @name ACSMCTRL12 - ACSM algorithmic address control and seed - bank adr. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMCTRL12_RFU_AcsmCtrl12_MASK (0xFFFU)
#define DWC_DDRPHYA_ACSM_ACSMCTRL12_RFU_AcsmCtrl12_SHIFT (0U)
/*! RFU_AcsmCtrl12 - RFU_AcsmCtrl12 */
#define DWC_DDRPHYA_ACSM_ACSMCTRL12_RFU_AcsmCtrl12(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMCTRL12_RFU_AcsmCtrl12_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMCTRL12_RFU_AcsmCtrl12_MASK)
/*! @} */

/*! @name ACSMCTRL13 - ACSM CKE enable mask. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMCTRL13_RFU_AcsmCtrl13_MASK (0xFU)
#define DWC_DDRPHYA_ACSM_ACSMCTRL13_RFU_AcsmCtrl13_SHIFT (0U)
/*! RFU_AcsmCtrl13 - RFU_AcsmCtrl13 */
#define DWC_DDRPHYA_ACSM_ACSMCTRL13_RFU_AcsmCtrl13(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMCTRL13_RFU_AcsmCtrl13_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMCTRL13_RFU_AcsmCtrl13_MASK)
/*! @} */

/*! @name ACSMCTRL14 - ACSM algorithmic address high order config bits - row adr. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMCTRL14_RFU_AcsmCtrl14_MASK (0xFU)
#define DWC_DDRPHYA_ACSM_ACSMCTRL14_RFU_AcsmCtrl14_SHIFT (0U)
/*! RFU_AcsmCtrl14 - RFU_AcsmCtrl14 */
#define DWC_DDRPHYA_ACSM_ACSMCTRL14_RFU_AcsmCtrl14(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMCTRL14_RFU_AcsmCtrl14_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMCTRL14_RFU_AcsmCtrl14_MASK)
/*! @} */

/*! @name ACSMCTRL15 - ACSM algorithmic address high order seed bits - row adr. */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMCTRL15_RFU_AcsmCtrl15_MASK (0xFU)
#define DWC_DDRPHYA_ACSM_ACSMCTRL15_RFU_AcsmCtrl15_SHIFT (0U)
/*! RFU_AcsmCtrl15 - RFU_AcsmCtrl15 */
#define DWC_DDRPHYA_ACSM_ACSMCTRL15_RFU_AcsmCtrl15(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMCTRL15_RFU_AcsmCtrl15_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMCTRL15_RFU_AcsmCtrl15_MASK)
/*! @} */

/*! @name ACSMPLAYBACK0X0_P1 - ACSM Playback Engine Register 0 for Entry 0 */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X0_P1_AcsmPlayback0x0_p1_MASK (0xFFFU)
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X0_P1_AcsmPlayback0x0_p1_SHIFT (0U)
/*! AcsmPlayback0x0_p1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() for protocols that support DRAM drift compensation. */
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X0_P1_AcsmPlayback0x0_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X0_P1_AcsmPlayback0x0_p1_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X0_P1_AcsmPlayback0x0_p1_MASK)
/*! @} */

/*! @name ACSMPLAYBACK1X0_P1 - ACSM Playback Engine Register 1 for Entry 0 */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X0_P1_AcsmPlayback1x0_p1_MASK (0xFFFU)
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X0_P1_AcsmPlayback1x0_p1_SHIFT (0U)
/*! AcsmPlayback1x0_p1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() for protocols that support DRAM drift compensation. */
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X0_P1_AcsmPlayback1x0_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X0_P1_AcsmPlayback1x0_p1_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X0_P1_AcsmPlayback1x0_p1_MASK)
/*! @} */

/*! @name ACSMPLAYBACK0X1_P1 - ACSM Playback Engine Register 0 for Entry 1 */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X1_P1_AcsmPlayback0x1_p1_MASK (0xFFFU)
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X1_P1_AcsmPlayback0x1_p1_SHIFT (0U)
/*! AcsmPlayback0x1_p1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() for protocols that support DRAM drift compensation. */
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X1_P1_AcsmPlayback0x1_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X1_P1_AcsmPlayback0x1_p1_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X1_P1_AcsmPlayback0x1_p1_MASK)
/*! @} */

/*! @name ACSMPLAYBACK1X1_P1 - ACSM Playback Engine Register 1 for Entry 1 */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X1_P1_AcsmPlayback1x1_p1_MASK (0xFFFU)
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X1_P1_AcsmPlayback1x1_p1_SHIFT (0U)
/*! AcsmPlayback1x1_p1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() for protocols that support DRAM drift compensation. */
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X1_P1_AcsmPlayback1x1_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X1_P1_AcsmPlayback1x1_p1_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X1_P1_AcsmPlayback1x1_p1_MASK)
/*! @} */

/*! @name ACSMPLAYBACK0X2_P1 - ACSM Playback Engine Register 0 for Entry 2 */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X2_P1_AcsmPlayback0x2_p1_MASK (0xFFFU)
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X2_P1_AcsmPlayback0x2_p1_SHIFT (0U)
/*! AcsmPlayback0x2_p1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() for protocols that support DRAM drift compensation. */
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X2_P1_AcsmPlayback0x2_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X2_P1_AcsmPlayback0x2_p1_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X2_P1_AcsmPlayback0x2_p1_MASK)
/*! @} */

/*! @name ACSMPLAYBACK1X2_P1 - ACSM Playback Engine Register 1 for Entry 2 */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X2_P1_AcsmPlayback1x2_p1_MASK (0xFFFU)
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X2_P1_AcsmPlayback1x2_p1_SHIFT (0U)
/*! AcsmPlayback1x2_p1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() for protocols that support DRAM drift compensation. */
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X2_P1_AcsmPlayback1x2_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X2_P1_AcsmPlayback1x2_p1_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X2_P1_AcsmPlayback1x2_p1_MASK)
/*! @} */

/*! @name ACSMPLAYBACK0X3_P1 - ACSM Playback Engine Register 0 for Entry 3 */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X3_P1_AcsmPlayback0x3_p1_MASK (0xFFFU)
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X3_P1_AcsmPlayback0x3_p1_SHIFT (0U)
/*! AcsmPlayback0x3_p1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() for protocols that support DRAM drift compensation. */
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X3_P1_AcsmPlayback0x3_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X3_P1_AcsmPlayback0x3_p1_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X3_P1_AcsmPlayback0x3_p1_MASK)
/*! @} */

/*! @name ACSMPLAYBACK1X3_P1 - ACSM Playback Engine Register 1 for Entry 3 */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X3_P1_AcsmPlayback1x3_p1_MASK (0xFFFU)
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X3_P1_AcsmPlayback1x3_p1_SHIFT (0U)
/*! AcsmPlayback1x3_p1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() for protocols that support DRAM drift compensation. */
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X3_P1_AcsmPlayback1x3_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X3_P1_AcsmPlayback1x3_p1_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X3_P1_AcsmPlayback1x3_p1_MASK)
/*! @} */

/*! @name ACSMPLAYBACK0X4_P1 - ACSM Playback Engine Register 0 for Entry 4 */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X4_P1_AcsmPlayback0x4_p1_MASK (0xFFFU)
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X4_P1_AcsmPlayback0x4_p1_SHIFT (0U)
/*! AcsmPlayback0x4_p1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() for protocols that support DRAM drift compensation. */
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X4_P1_AcsmPlayback0x4_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X4_P1_AcsmPlayback0x4_p1_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X4_P1_AcsmPlayback0x4_p1_MASK)
/*! @} */

/*! @name ACSMPLAYBACK1X4_P1 - ACSM Playback Engine Register 1 for Entry 4 */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X4_P1_AcsmPlayback1x4_p1_MASK (0xFFFU)
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X4_P1_AcsmPlayback1x4_p1_SHIFT (0U)
/*! AcsmPlayback1x4_p1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() for protocols that support DRAM drift compensation. */
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X4_P1_AcsmPlayback1x4_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X4_P1_AcsmPlayback1x4_p1_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X4_P1_AcsmPlayback1x4_p1_MASK)
/*! @} */

/*! @name ACSMPLAYBACK0X5_P1 - ACSM Playback Engine Register 0 for Entry 5 */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X5_P1_AcsmPlayback0x5_p1_MASK (0xFFFU)
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X5_P1_AcsmPlayback0x5_p1_SHIFT (0U)
/*! AcsmPlayback0x5_p1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() for protocols that support DRAM drift compensation. */
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X5_P1_AcsmPlayback0x5_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X5_P1_AcsmPlayback0x5_p1_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X5_P1_AcsmPlayback0x5_p1_MASK)
/*! @} */

/*! @name ACSMPLAYBACK1X5_P1 - ACSM Playback Engine Register 1 for Entry 5 */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X5_P1_AcsmPlayback1x5_p1_MASK (0xFFFU)
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X5_P1_AcsmPlayback1x5_p1_SHIFT (0U)
/*! AcsmPlayback1x5_p1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() for protocols that support DRAM drift compensation. */
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X5_P1_AcsmPlayback1x5_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X5_P1_AcsmPlayback1x5_p1_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X5_P1_AcsmPlayback1x5_p1_MASK)
/*! @} */

/*! @name ACSMPLAYBACK0X6_P1 - ACSM Playback Engine Register 0 for Entry 6 */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X6_P1_AcsmPlayback0x6_p1_MASK (0xFFFU)
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X6_P1_AcsmPlayback0x6_p1_SHIFT (0U)
/*! AcsmPlayback0x6_p1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() for protocols that support DRAM drift compensation. */
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X6_P1_AcsmPlayback0x6_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X6_P1_AcsmPlayback0x6_p1_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X6_P1_AcsmPlayback0x6_p1_MASK)
/*! @} */

/*! @name ACSMPLAYBACK1X6_P1 - ACSM Playback Engine Register 1 for Entry 6 */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X6_P1_AcsmPlayback1x6_p1_MASK (0xFFFU)
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X6_P1_AcsmPlayback1x6_p1_SHIFT (0U)
/*! AcsmPlayback1x6_p1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() for protocols that support DRAM drift compensation. */
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X6_P1_AcsmPlayback1x6_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X6_P1_AcsmPlayback1x6_p1_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X6_P1_AcsmPlayback1x6_p1_MASK)
/*! @} */

/*! @name ACSMPLAYBACK0X7_P1 - ACSM Playback Engine Register 0 for Entry 7 */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X7_P1_AcsmPlayback0x7_p1_MASK (0xFFFU)
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X7_P1_AcsmPlayback0x7_p1_SHIFT (0U)
/*! AcsmPlayback0x7_p1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() for protocols that support DRAM drift compensation. */
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X7_P1_AcsmPlayback0x7_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X7_P1_AcsmPlayback0x7_p1_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X7_P1_AcsmPlayback0x7_p1_MASK)
/*! @} */

/*! @name ACSMPLAYBACK1X7_P1 - ACSM Playback Engine Register 1 for Entry 7 */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X7_P1_AcsmPlayback1x7_p1_MASK (0xFFFU)
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X7_P1_AcsmPlayback1x7_p1_SHIFT (0U)
/*! AcsmPlayback1x7_p1 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() for protocols that support DRAM drift compensation. */
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X7_P1_AcsmPlayback1x7_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X7_P1_AcsmPlayback1x7_p1_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X7_P1_AcsmPlayback1x7_p1_MASK)
/*! @} */

/*! @name ACSMPLAYBACK0X0_P2 - ACSM Playback Engine Register 0 for Entry 0 */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X0_P2_AcsmPlayback0x0_p2_MASK (0xFFFU)
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X0_P2_AcsmPlayback0x0_p2_SHIFT (0U)
/*! AcsmPlayback0x0_p2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() for protocols that support DRAM drift compensation. */
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X0_P2_AcsmPlayback0x0_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X0_P2_AcsmPlayback0x0_p2_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X0_P2_AcsmPlayback0x0_p2_MASK)
/*! @} */

/*! @name ACSMPLAYBACK1X0_P2 - ACSM Playback Engine Register 1 for Entry 0 */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X0_P2_AcsmPlayback1x0_p2_MASK (0xFFFU)
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X0_P2_AcsmPlayback1x0_p2_SHIFT (0U)
/*! AcsmPlayback1x0_p2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() for protocols that support DRAM drift compensation. */
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X0_P2_AcsmPlayback1x0_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X0_P2_AcsmPlayback1x0_p2_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X0_P2_AcsmPlayback1x0_p2_MASK)
/*! @} */

/*! @name ACSMPLAYBACK0X1_P2 - ACSM Playback Engine Register 0 for Entry 1 */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X1_P2_AcsmPlayback0x1_p2_MASK (0xFFFU)
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X1_P2_AcsmPlayback0x1_p2_SHIFT (0U)
/*! AcsmPlayback0x1_p2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() for protocols that support DRAM drift compensation. */
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X1_P2_AcsmPlayback0x1_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X1_P2_AcsmPlayback0x1_p2_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X1_P2_AcsmPlayback0x1_p2_MASK)
/*! @} */

/*! @name ACSMPLAYBACK1X1_P2 - ACSM Playback Engine Register 1 for Entry 1 */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X1_P2_AcsmPlayback1x1_p2_MASK (0xFFFU)
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X1_P2_AcsmPlayback1x1_p2_SHIFT (0U)
/*! AcsmPlayback1x1_p2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() for protocols that support DRAM drift compensation. */
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X1_P2_AcsmPlayback1x1_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X1_P2_AcsmPlayback1x1_p2_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X1_P2_AcsmPlayback1x1_p2_MASK)
/*! @} */

/*! @name ACSMPLAYBACK0X2_P2 - ACSM Playback Engine Register 0 for Entry 2 */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X2_P2_AcsmPlayback0x2_p2_MASK (0xFFFU)
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X2_P2_AcsmPlayback0x2_p2_SHIFT (0U)
/*! AcsmPlayback0x2_p2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() for protocols that support DRAM drift compensation. */
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X2_P2_AcsmPlayback0x2_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X2_P2_AcsmPlayback0x2_p2_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X2_P2_AcsmPlayback0x2_p2_MASK)
/*! @} */

/*! @name ACSMPLAYBACK1X2_P2 - ACSM Playback Engine Register 1 for Entry 2 */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X2_P2_AcsmPlayback1x2_p2_MASK (0xFFFU)
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X2_P2_AcsmPlayback1x2_p2_SHIFT (0U)
/*! AcsmPlayback1x2_p2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() for protocols that support DRAM drift compensation. */
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X2_P2_AcsmPlayback1x2_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X2_P2_AcsmPlayback1x2_p2_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X2_P2_AcsmPlayback1x2_p2_MASK)
/*! @} */

/*! @name ACSMPLAYBACK0X3_P2 - ACSM Playback Engine Register 0 for Entry 3 */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X3_P2_AcsmPlayback0x3_p2_MASK (0xFFFU)
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X3_P2_AcsmPlayback0x3_p2_SHIFT (0U)
/*! AcsmPlayback0x3_p2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() for protocols that support DRAM drift compensation. */
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X3_P2_AcsmPlayback0x3_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X3_P2_AcsmPlayback0x3_p2_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X3_P2_AcsmPlayback0x3_p2_MASK)
/*! @} */

/*! @name ACSMPLAYBACK1X3_P2 - ACSM Playback Engine Register 1 for Entry 3 */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X3_P2_AcsmPlayback1x3_p2_MASK (0xFFFU)
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X3_P2_AcsmPlayback1x3_p2_SHIFT (0U)
/*! AcsmPlayback1x3_p2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() for protocols that support DRAM drift compensation. */
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X3_P2_AcsmPlayback1x3_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X3_P2_AcsmPlayback1x3_p2_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X3_P2_AcsmPlayback1x3_p2_MASK)
/*! @} */

/*! @name ACSMPLAYBACK0X4_P2 - ACSM Playback Engine Register 0 for Entry 4 */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X4_P2_AcsmPlayback0x4_p2_MASK (0xFFFU)
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X4_P2_AcsmPlayback0x4_p2_SHIFT (0U)
/*! AcsmPlayback0x4_p2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() for protocols that support DRAM drift compensation. */
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X4_P2_AcsmPlayback0x4_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X4_P2_AcsmPlayback0x4_p2_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X4_P2_AcsmPlayback0x4_p2_MASK)
/*! @} */

/*! @name ACSMPLAYBACK1X4_P2 - ACSM Playback Engine Register 1 for Entry 4 */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X4_P2_AcsmPlayback1x4_p2_MASK (0xFFFU)
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X4_P2_AcsmPlayback1x4_p2_SHIFT (0U)
/*! AcsmPlayback1x4_p2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() for protocols that support DRAM drift compensation. */
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X4_P2_AcsmPlayback1x4_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X4_P2_AcsmPlayback1x4_p2_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X4_P2_AcsmPlayback1x4_p2_MASK)
/*! @} */

/*! @name ACSMPLAYBACK0X5_P2 - ACSM Playback Engine Register 0 for Entry 5 */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X5_P2_AcsmPlayback0x5_p2_MASK (0xFFFU)
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X5_P2_AcsmPlayback0x5_p2_SHIFT (0U)
/*! AcsmPlayback0x5_p2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() for protocols that support DRAM drift compensation. */
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X5_P2_AcsmPlayback0x5_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X5_P2_AcsmPlayback0x5_p2_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X5_P2_AcsmPlayback0x5_p2_MASK)
/*! @} */

/*! @name ACSMPLAYBACK1X5_P2 - ACSM Playback Engine Register 1 for Entry 5 */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X5_P2_AcsmPlayback1x5_p2_MASK (0xFFFU)
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X5_P2_AcsmPlayback1x5_p2_SHIFT (0U)
/*! AcsmPlayback1x5_p2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() for protocols that support DRAM drift compensation. */
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X5_P2_AcsmPlayback1x5_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X5_P2_AcsmPlayback1x5_p2_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X5_P2_AcsmPlayback1x5_p2_MASK)
/*! @} */

/*! @name ACSMPLAYBACK0X6_P2 - ACSM Playback Engine Register 0 for Entry 6 */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X6_P2_AcsmPlayback0x6_p2_MASK (0xFFFU)
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X6_P2_AcsmPlayback0x6_p2_SHIFT (0U)
/*! AcsmPlayback0x6_p2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() for protocols that support DRAM drift compensation. */
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X6_P2_AcsmPlayback0x6_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X6_P2_AcsmPlayback0x6_p2_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X6_P2_AcsmPlayback0x6_p2_MASK)
/*! @} */

/*! @name ACSMPLAYBACK1X6_P2 - ACSM Playback Engine Register 1 for Entry 6 */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X6_P2_AcsmPlayback1x6_p2_MASK (0xFFFU)
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X6_P2_AcsmPlayback1x6_p2_SHIFT (0U)
/*! AcsmPlayback1x6_p2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() for protocols that support DRAM drift compensation. */
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X6_P2_AcsmPlayback1x6_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X6_P2_AcsmPlayback1x6_p2_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X6_P2_AcsmPlayback1x6_p2_MASK)
/*! @} */

/*! @name ACSMPLAYBACK0X7_P2 - ACSM Playback Engine Register 0 for Entry 7 */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X7_P2_AcsmPlayback0x7_p2_MASK (0xFFFU)
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X7_P2_AcsmPlayback0x7_p2_SHIFT (0U)
/*! AcsmPlayback0x7_p2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() for protocols that support DRAM drift compensation. */
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X7_P2_AcsmPlayback0x7_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X7_P2_AcsmPlayback0x7_p2_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X7_P2_AcsmPlayback0x7_p2_MASK)
/*! @} */

/*! @name ACSMPLAYBACK1X7_P2 - ACSM Playback Engine Register 1 for Entry 7 */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X7_P2_AcsmPlayback1x7_p2_MASK (0xFFFU)
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X7_P2_AcsmPlayback1x7_p2_SHIFT (0U)
/*! AcsmPlayback1x7_p2 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() for protocols that support DRAM drift compensation. */
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X7_P2_AcsmPlayback1x7_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X7_P2_AcsmPlayback1x7_p2_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X7_P2_AcsmPlayback1x7_p2_MASK)
/*! @} */

/*! @name ACSMPLAYBACK0X0_P3 - ACSM Playback Engine Register 0 for Entry 0 */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X0_P3_AcsmPlayback0x0_p3_MASK (0xFFFU)
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X0_P3_AcsmPlayback0x0_p3_SHIFT (0U)
/*! AcsmPlayback0x0_p3 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() for protocols that support DRAM drift compensation. */
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X0_P3_AcsmPlayback0x0_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X0_P3_AcsmPlayback0x0_p3_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X0_P3_AcsmPlayback0x0_p3_MASK)
/*! @} */

/*! @name ACSMPLAYBACK1X0_P3 - ACSM Playback Engine Register 1 for Entry 0 */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X0_P3_AcsmPlayback1x0_p3_MASK (0xFFFU)
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X0_P3_AcsmPlayback1x0_p3_SHIFT (0U)
/*! AcsmPlayback1x0_p3 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() for protocols that support DRAM drift compensation. */
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X0_P3_AcsmPlayback1x0_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X0_P3_AcsmPlayback1x0_p3_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X0_P3_AcsmPlayback1x0_p3_MASK)
/*! @} */

/*! @name ACSMPLAYBACK0X1_P3 - ACSM Playback Engine Register 0 for Entry 1 */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X1_P3_AcsmPlayback0x1_p3_MASK (0xFFFU)
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X1_P3_AcsmPlayback0x1_p3_SHIFT (0U)
/*! AcsmPlayback0x1_p3 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() for protocols that support DRAM drift compensation. */
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X1_P3_AcsmPlayback0x1_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X1_P3_AcsmPlayback0x1_p3_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X1_P3_AcsmPlayback0x1_p3_MASK)
/*! @} */

/*! @name ACSMPLAYBACK1X1_P3 - ACSM Playback Engine Register 1 for Entry 1 */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X1_P3_AcsmPlayback1x1_p3_MASK (0xFFFU)
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X1_P3_AcsmPlayback1x1_p3_SHIFT (0U)
/*! AcsmPlayback1x1_p3 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() for protocols that support DRAM drift compensation. */
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X1_P3_AcsmPlayback1x1_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X1_P3_AcsmPlayback1x1_p3_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X1_P3_AcsmPlayback1x1_p3_MASK)
/*! @} */

/*! @name ACSMPLAYBACK0X2_P3 - ACSM Playback Engine Register 0 for Entry 2 */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X2_P3_AcsmPlayback0x2_p3_MASK (0xFFFU)
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X2_P3_AcsmPlayback0x2_p3_SHIFT (0U)
/*! AcsmPlayback0x2_p3 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() for protocols that support DRAM drift compensation. */
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X2_P3_AcsmPlayback0x2_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X2_P3_AcsmPlayback0x2_p3_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X2_P3_AcsmPlayback0x2_p3_MASK)
/*! @} */

/*! @name ACSMPLAYBACK1X2_P3 - ACSM Playback Engine Register 1 for Entry 2 */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X2_P3_AcsmPlayback1x2_p3_MASK (0xFFFU)
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X2_P3_AcsmPlayback1x2_p3_SHIFT (0U)
/*! AcsmPlayback1x2_p3 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() for protocols that support DRAM drift compensation. */
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X2_P3_AcsmPlayback1x2_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X2_P3_AcsmPlayback1x2_p3_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X2_P3_AcsmPlayback1x2_p3_MASK)
/*! @} */

/*! @name ACSMPLAYBACK0X3_P3 - ACSM Playback Engine Register 0 for Entry 3 */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X3_P3_AcsmPlayback0x3_p3_MASK (0xFFFU)
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X3_P3_AcsmPlayback0x3_p3_SHIFT (0U)
/*! AcsmPlayback0x3_p3 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() for protocols that support DRAM drift compensation. */
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X3_P3_AcsmPlayback0x3_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X3_P3_AcsmPlayback0x3_p3_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X3_P3_AcsmPlayback0x3_p3_MASK)
/*! @} */

/*! @name ACSMPLAYBACK1X3_P3 - ACSM Playback Engine Register 1 for Entry 3 */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X3_P3_AcsmPlayback1x3_p3_MASK (0xFFFU)
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X3_P3_AcsmPlayback1x3_p3_SHIFT (0U)
/*! AcsmPlayback1x3_p3 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() for protocols that support DRAM drift compensation. */
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X3_P3_AcsmPlayback1x3_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X3_P3_AcsmPlayback1x3_p3_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X3_P3_AcsmPlayback1x3_p3_MASK)
/*! @} */

/*! @name ACSMPLAYBACK0X4_P3 - ACSM Playback Engine Register 0 for Entry 4 */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X4_P3_AcsmPlayback0x4_p3_MASK (0xFFFU)
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X4_P3_AcsmPlayback0x4_p3_SHIFT (0U)
/*! AcsmPlayback0x4_p3 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() for protocols that support DRAM drift compensation. */
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X4_P3_AcsmPlayback0x4_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X4_P3_AcsmPlayback0x4_p3_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X4_P3_AcsmPlayback0x4_p3_MASK)
/*! @} */

/*! @name ACSMPLAYBACK1X4_P3 - ACSM Playback Engine Register 1 for Entry 4 */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X4_P3_AcsmPlayback1x4_p3_MASK (0xFFFU)
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X4_P3_AcsmPlayback1x4_p3_SHIFT (0U)
/*! AcsmPlayback1x4_p3 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() for protocols that support DRAM drift compensation. */
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X4_P3_AcsmPlayback1x4_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X4_P3_AcsmPlayback1x4_p3_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X4_P3_AcsmPlayback1x4_p3_MASK)
/*! @} */

/*! @name ACSMPLAYBACK0X5_P3 - ACSM Playback Engine Register 0 for Entry 5 */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X5_P3_AcsmPlayback0x5_p3_MASK (0xFFFU)
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X5_P3_AcsmPlayback0x5_p3_SHIFT (0U)
/*! AcsmPlayback0x5_p3 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() for protocols that support DRAM drift compensation. */
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X5_P3_AcsmPlayback0x5_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X5_P3_AcsmPlayback0x5_p3_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X5_P3_AcsmPlayback0x5_p3_MASK)
/*! @} */

/*! @name ACSMPLAYBACK1X5_P3 - ACSM Playback Engine Register 1 for Entry 5 */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X5_P3_AcsmPlayback1x5_p3_MASK (0xFFFU)
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X5_P3_AcsmPlayback1x5_p3_SHIFT (0U)
/*! AcsmPlayback1x5_p3 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() for protocols that support DRAM drift compensation. */
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X5_P3_AcsmPlayback1x5_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X5_P3_AcsmPlayback1x5_p3_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X5_P3_AcsmPlayback1x5_p3_MASK)
/*! @} */

/*! @name ACSMPLAYBACK0X6_P3 - ACSM Playback Engine Register 0 for Entry 6 */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X6_P3_AcsmPlayback0x6_p3_MASK (0xFFFU)
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X6_P3_AcsmPlayback0x6_p3_SHIFT (0U)
/*! AcsmPlayback0x6_p3 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() for protocols that support DRAM drift compensation. */
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X6_P3_AcsmPlayback0x6_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X6_P3_AcsmPlayback0x6_p3_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X6_P3_AcsmPlayback0x6_p3_MASK)
/*! @} */

/*! @name ACSMPLAYBACK1X6_P3 - ACSM Playback Engine Register 1 for Entry 6 */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X6_P3_AcsmPlayback1x6_p3_MASK (0xFFFU)
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X6_P3_AcsmPlayback1x6_p3_SHIFT (0U)
/*! AcsmPlayback1x6_p3 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() for protocols that support DRAM drift compensation. */
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X6_P3_AcsmPlayback1x6_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X6_P3_AcsmPlayback1x6_p3_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X6_P3_AcsmPlayback1x6_p3_MASK)
/*! @} */

/*! @name ACSMPLAYBACK0X7_P3 - ACSM Playback Engine Register 0 for Entry 7 */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X7_P3_AcsmPlayback0x7_p3_MASK (0xFFFU)
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X7_P3_AcsmPlayback0x7_p3_SHIFT (0U)
/*! AcsmPlayback0x7_p3 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() for protocols that support DRAM drift compensation. */
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X7_P3_AcsmPlayback0x7_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X7_P3_AcsmPlayback0x7_p3_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMPLAYBACK0X7_P3_AcsmPlayback0x7_p3_MASK)
/*! @} */

/*! @name ACSMPLAYBACK1X7_P3 - ACSM Playback Engine Register 1 for Entry 7 */
/*! @{ */

#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X7_P3_AcsmPlayback1x7_p3_MASK (0xFFFU)
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X7_P3_AcsmPlayback1x7_p3_SHIFT (0U)
/*! AcsmPlayback1x7_p3 - Programmed by dwc_ddrphy_phyinit_I_loadPIEImage() for protocols that support DRAM drift compensation. */
#define DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X7_P3_AcsmPlayback1x7_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X7_P3_AcsmPlayback1x7_p3_SHIFT)) & DWC_DDRPHYA_ACSM_ACSMPLAYBACK1X7_P3_AcsmPlayback1x7_p3_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group DWC_DDRPHYA_ACSM_Register_Masks */


/*!
 * @}
 */ /* end of group DWC_DDRPHYA_ACSM_Peripheral_Access_Layer */


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


#endif  /* PERI_DWC_DDRPHYA_ACSM_H_ */
