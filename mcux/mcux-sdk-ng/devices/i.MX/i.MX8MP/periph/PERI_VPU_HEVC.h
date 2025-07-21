/*
** ###################################################################
**     Processors:          MIMX8ML2CVNKZ_ca53
**                          MIMX8ML2CVNKZ_cm7
**                          MIMX8ML2CVNKZ_dsp
**                          MIMX8ML2DVNLZ_ca53
**                          MIMX8ML2DVNLZ_cm7
**                          MIMX8ML2DVNLZ_dsp
**                          MIMX8ML3CVNKZ_ca53
**                          MIMX8ML3CVNKZ_cm7
**                          MIMX8ML3CVNKZ_dsp
**                          MIMX8ML3DVNLZ_ca53
**                          MIMX8ML3DVNLZ_cm7
**                          MIMX8ML3DVNLZ_dsp
**                          MIMX8ML4CVNKZ_ca53
**                          MIMX8ML4CVNKZ_cm7
**                          MIMX8ML4DVNLZ_ca53
**                          MIMX8ML4DVNLZ_cm7
**                          MIMX8ML5CVNKZ_ca53
**                          MIMX8ML5CVNKZ_cm7
**                          MIMX8ML5CVNKZ_dsp
**                          MIMX8ML5DVNLZ_ca53
**                          MIMX8ML5DVNLZ_cm7
**                          MIMX8ML5DVNLZ_dsp
**                          MIMX8ML6CVNKZ_ca53
**                          MIMX8ML6CVNKZ_cm7
**                          MIMX8ML6DVNLZ_ca53
**                          MIMX8ML6DVNLZ_cm7
**                          MIMX8ML8CVNKZ_ca53
**                          MIMX8ML8CVNKZ_cm7
**                          MIMX8ML8CVNKZ_dsp
**                          MIMX8ML8DVNLZ_ca53
**                          MIMX8ML8DVNLZ_cm7
**                          MIMX8ML8DVNLZ_dsp
**
**     Version:             rev. 6.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for VPU_HEVC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2019-10-11)
**         Initial version.
**     - rev. 2.0 (2020-02-21)
**         Rev.B Header.
**     - rev. 3.0 (2020-06-22)
**         Rev.C Header.
**     - rev. 4.0 (2020-11-16)
**         Rev.D Header.
**     - rev. 5.0 (2021-03-01)
**         Rev.D Header Final.
**     - rev. 6.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_VPU_HEVC.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for VPU_HEVC
 *
 * CMSIS Peripheral Access Layer for VPU_HEVC
 */

#if !defined(PERI_VPU_HEVC_H_)
#define PERI_VPU_HEVC_H_                         /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8ML2CVNKZ_ca53) || defined(CPU_MIMX8ML2DVNLZ_ca53))
#include "MIMX8ML2_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML2CVNKZ_cm7) || defined(CPU_MIMX8ML2DVNLZ_cm7))
#include "MIMX8ML2_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML2CVNKZ_dsp) || defined(CPU_MIMX8ML2DVNLZ_dsp))
#include "MIMX8ML2_dsp_COMMON.h"
#elif (defined(CPU_MIMX8ML3CVNKZ_ca53) || defined(CPU_MIMX8ML3DVNLZ_ca53))
#include "MIMX8ML3_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML3CVNKZ_cm7) || defined(CPU_MIMX8ML3DVNLZ_cm7))
#include "MIMX8ML3_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML3CVNKZ_dsp) || defined(CPU_MIMX8ML3DVNLZ_dsp))
#include "MIMX8ML3_dsp_COMMON.h"
#elif (defined(CPU_MIMX8ML4CVNKZ_ca53) || defined(CPU_MIMX8ML4DVNLZ_ca53))
#include "MIMX8ML4_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML4CVNKZ_cm7) || defined(CPU_MIMX8ML4DVNLZ_cm7))
#include "MIMX8ML4_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML5CVNKZ_ca53) || defined(CPU_MIMX8ML5DVNLZ_ca53))
#include "MIMX8ML5_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML5CVNKZ_cm7) || defined(CPU_MIMX8ML5DVNLZ_cm7))
#include "MIMX8ML5_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML5CVNKZ_dsp) || defined(CPU_MIMX8ML5DVNLZ_dsp))
#include "MIMX8ML5_dsp_COMMON.h"
#elif (defined(CPU_MIMX8ML6CVNKZ_ca53) || defined(CPU_MIMX8ML6DVNLZ_ca53))
#include "MIMX8ML6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML6CVNKZ_cm7) || defined(CPU_MIMX8ML6DVNLZ_cm7))
#include "MIMX8ML6_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML8CVNKZ_ca53) || defined(CPU_MIMX8ML8DVNLZ_ca53))
#include "MIMX8ML8_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML8CVNKZ_cm7) || defined(CPU_MIMX8ML8DVNLZ_cm7))
#include "MIMX8ML8_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML8CVNKZ_dsp) || defined(CPU_MIMX8ML8DVNLZ_dsp))
#include "MIMX8ML8_dsp_COMMON.h"
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
#elif defined(__XTENSA__)
  /* anonymous unions are enabled by default */
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- VPU_HEVC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VPU_HEVC_Peripheral_Access_Layer VPU_HEVC Peripheral Access Layer
 * @{
 */

/** VPU_HEVC - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[4];
  __IO uint32_t SWREG1;                            /**< Interrupt register encoder, offset: 0x4 */
  __IO uint32_t SWREG2;                            /**< Data configuration register0, offset: 0x8 */
  __IO uint32_t SWREG3;                            /**< Data configuration register1, offset: 0xC */
  __IO uint32_t SWREG4;                            /**< control register 0, offset: 0x10 */
  __IO uint32_t SWREG5;                            /**< control register 1, offset: 0x14 */
       uint8_t RESERVED_1[4];
  __IO uint32_t SWREG7;                            /**< control register 3, offset: 0x1C */
  __IO uint32_t SWREG8;                            /**< stream output buffer0 address, offset: 0x20 */
  __IO uint32_t SWREG9;                            /**< stream output buffer0 limit size, offset: 0x24 */
  __IO uint32_t SWREG10;                           /**< sizeTblBase, offset: 0x28 */
  __IO uint32_t SWREG11;                           /**< encoded Picture order count, offset: 0x2C */
  __IO uint32_t SWREG12;                           /**< input lum base address, offset: 0x30 */
  __IO uint32_t SWREG13;                           /**< input cb base address, offset: 0x34 */
  __IO uint32_t SWREG14;                           /**< input cr base address, offset: 0x38 */
  __IO uint32_t SWREG15;                           /**< recon image luma base address, offset: 0x3C */
  __IO uint32_t SWREG16;                           /**< recon image chroma base address, offset: 0x40 */
       uint8_t RESERVED_2[4];
  __IO uint32_t SWREG18;                           /**< reference picture reconstructed list0 luma0, offset: 0x48 */
  __IO uint32_t SWREG19;                           /**< reference picture reconstructed list0 chroma0, offset: 0x4C */
       uint8_t RESERVED_3[8];
  __IO uint32_t SWREG22;                           /**< Cyclic Intra, offset: 0x58 */
  __IO uint32_t SWREG23;                           /**< intra Area, offset: 0x5C */
  __IO uint32_t SWREG24;                           /**< ROI1 Area, offset: 0x60 */
  __IO uint32_t SWREG25;                           /**< ROI2 Area, offset: 0x64 */
  __IO uint32_t SWREG26_H2V2;                      /**< intra size factors. For H2V2 or later version., offset: 0x68 */
  __IO uint32_t SWREG27_H2V2;                      /**< intra mode factors . For H2V2 or later version., offset: 0x6C */
  __IO uint32_t SWREG28_H2V5;                      /**< inter me SATD lambda config 0. For H2V5 or later version., offset: 0x70 */
  __IO uint32_t SWREG29_H2V5;                      /**< inter me SATD lambda config 1.For H2V5 or later version., offset: 0x74 */
  __IO uint32_t SWREG30_H2V5;                      /**< inter me SATD lambda config 2. For H2V5 or later version., offset: 0x78 */
  __IO uint32_t SWREG31_H2V5;                      /**< inter me SATD lambda config 3. For H2V5 or later version., offset: 0x7C */
  __IO uint32_t SWREG32_H2V5;                      /**< inter me SATD lambda config 4. For H2V5 or later version., offset: 0x80 */
  __IO uint32_t SWREG33_H2V5;                      /**< inter me SATD lambda config 5. For H2V5 or later version., offset: 0x84 */
  __IO uint32_t SWREG34_H2V5;                      /**< inter me SATD lambda config 6. For H2V5 or later version., offset: 0x88 */
  __IO uint32_t SWREG35;                           /**< inter prediction parameters1, offset: 0x8C */
  __IO uint32_t SWREG36;                           /**< inter prediction parameters2, offset: 0x90 */
  __IO uint32_t SWREG37;                           /**< SAO lambda parameter, offset: 0x94 */
  __IO uint32_t SWREG38;                           /**< Pre-processor configuration, offset: 0x98 */
  __IO uint32_t SWREG39;                           /**< Pre-processor color conversion parameters0, offset: 0x9C */
  __IO uint32_t SWREG40;                           /**< Pre-processor color conversion parameters1, offset: 0xA0 */
  __IO uint32_t SWREG41;                           /**< Pre-processor color conversion parameters2, offset: 0xA4 */
  __IO uint32_t SWREG42;                           /**< Pre-processor Base address for down-scaled output, offset: 0xA8 */
  __IO uint32_t SWREG43;                           /**< Pre-processor down-scaled configuration0, offset: 0xAC */
  __IO uint32_t SWREG44;                           /**< Pre-processor down-scaled configuration1, offset: 0xB0 */
  __IO uint32_t SWREG45;                           /**< Pre-processor down-scaled configuration2, offset: 0xB4 */
  __IO uint32_t SWREG46;                           /**< compressed coefficients base address for SAN module., offset: 0xB8 */
       uint8_t RESERVED_4[52];
  __IO uint32_t SWREG60;                           /**< Base address for recon luma compress table LSB., offset: 0xF0 */
       uint8_t RESERVED_5[4];
  __IO uint32_t SWREG62;                           /**< Base address for recon Chroma compress table LSB, offset: 0xF8 */
       uint8_t RESERVED_6[4];
  __IO uint32_t SWREG64;                           /**< Base address for list 0 ref 0 luma compress table LSB., offset: 0x100 */
       uint8_t RESERVED_7[4];
  __IO uint32_t SWREG66;                           /**< Base address for list 0 ref 0 Chroma compress table LSB., offset: 0x108 */
       uint8_t RESERVED_8[20];
  __IO uint32_t SWREG72;                           /**< Base address for recon luma 4n base LSB., offset: 0x120 */
       uint8_t RESERVED_9[4];
  __IO uint32_t SWREG74;                           /**< reference picture reconstructed list0 4n 0, offset: 0x128 */
       uint8_t RESERVED_10[12];
  __IO uint32_t SWREG78_H2V5;                      /**< inter me SATD lambda config 7. For H2V5 or later version., offset: 0x138 */
  __IO uint32_t SWREG79_H2V5;                      /**< inter me SSE lambda config 0. For H2V5 or later version., offset: 0x13C */
       uint8_t RESERVED_11[4];
  __IO uint32_t SWREG81;                           /**< hardware configuation 0, offset: 0x144 */
  __I  uint32_t SWREG82;                           /**< record hardware performance, offset: 0x148 */
  __IO uint32_t SWREG83;                           /**< reference picture reconstructed list1 luma0, offset: 0x14C */
  __IO uint32_t SWREG84;                           /**< reference picture reconstructed list1 chroma0, offset: 0x150 */
       uint8_t RESERVED_12[24];
  __IO uint32_t SWREG91;                           /**< reference pictures list1 config, offset: 0x16C */
  __IO uint32_t SWREG92;                           /**< reference picture reconstructed list1 4n 0, offset: 0x170 */
       uint8_t RESERVED_13[12];
  __IO uint32_t SWREG96;                           /**< Base address for list 1 ref 0 luma compress table LSB., offset: 0x180 */
       uint8_t RESERVED_14[4];
  __IO uint32_t SWREG98;                           /**< Base address for list 1 ref 0 Chroma compress table LSB., offset: 0x188 */
       uint8_t RESERVED_15[20];
  __IO uint32_t SWREG104;                          /**< reference picture lists modification, offset: 0x1A0 */
       uint8_t RESERVED_16[4];
  __IO uint32_t SWREG106;                          /**< Min picture size, offset: 0x1A8 */
  __IO uint32_t SWREG107;                          /**< Max picture size, offset: 0x1AC */
       uint8_t RESERVED_17[4];
  __IO uint32_t SWREG109;                          /**< Qp delta map, offset: 0x1B4 */
       uint8_t RESERVED_18[4];
  __I  uint32_t SWREG111;                          /**< adaptive GOP configuration1, offset: 0x1BC */
  __I  uint32_t SWREG112;                          /**< adaptive GOP configuration2, offset: 0x1C0 */
  __IO uint32_t SWREG113;                          /**< adaptive GOP configuration3, offset: 0x1C4 */
       uint8_t RESERVED_19[20];
  __IO uint32_t SWREG119;                          /**< min/max lcu bits number of last picture, offset: 0x1DC */
  __IO uint32_t SWREG120;                          /**< total bits number of all lcus of last picture not including slice header bits, offset: 0x1E0 */
       uint8_t RESERVED_20[4];
  __IO uint32_t SWREG122_H2V5;                     /**< inter me SSE lambda config 1. For H2V5 or later version., offset: 0x1E8 */
  __IO uint32_t SWREG123_H2V5;                     /**< inter me SSE lambda config 2. For H2V5 or later version., offset: 0x1EC */
  __IO uint32_t SWREG124_H2V5;                     /**< inter me SSE lambda config 3. For H2V5 or later version., offset: 0x1F0 */
  __IO uint32_t SWREG125;                          /**< intra SATD lambda config 0, offset: 0x1F4 */
  __IO uint32_t SWREG126;                          /**< intra SATD lambda config 1, offset: 0x1F8 */
  __IO uint32_t SWREG127;                          /**< intra SATD lambda config 2, offset: 0x1FC */
  __IO uint32_t SWREG128;                          /**< intra SATD lambda config 3, offset: 0x200 */
  __IO uint32_t SWREG129;                          /**< intra SATD lambda config 4, offset: 0x204 */
  __IO uint32_t SWREG130;                          /**< intra SATD lambda config 5, offset: 0x208 */
  __IO uint32_t SWREG131;                          /**< intra SATD lambda config 6, offset: 0x20C */
  __IO uint32_t SWREG132;                          /**< intra SATD lambda config 7, offset: 0x210 */
  __IO uint32_t SWREG133;                          /**< SSE devide 256, offset: 0x214 */
  __IO uint32_t SWREG134;                          /**< noise reduction, offset: 0x218 */
  __IO uint32_t SWREG135;                          /**< noise reduction 1, offset: 0x21C */
  __IO uint32_t SWREG136;                          /**< noise reduction 2, offset: 0x220 */
  __IO uint32_t SWREG137;                          /**< noise reduction 3, offset: 0x224 */
  __IO uint32_t SWREG138_H2V5;                     /**< inter me SSE lambda config 4. For H2V5 or later version., offset: 0x228 */
  __IO uint32_t SWREG139_H2V5;                     /**< inter me SSE lambda config 5. For H2V5 or later version., offset: 0x22C */
  __IO uint32_t SWREG140_H2V5;                     /**< inter me SSE lambda config 6. For H2V5 or later version., offset: 0x230 */
  __IO uint32_t SWREG141_H2V5;                     /**< inter me SSE lambda config 7. For H2V5 or later version., offset: 0x234 */
  __IO uint32_t SWREG142_H2V5;                     /**< inter me SSE lambda config 8. For H2V5 or later version., offset: 0x238 */
  __IO uint32_t SWREG143_H2V5;                     /**< inter me SSE lambda config 9. For H2V5 or later version., offset: 0x23C */
  __IO uint32_t SWREG144_H2V5;                     /**< inter me SSE lambda config 10. For H2V5 or later version., offset: 0x240 */
  __IO uint32_t SWREG145_H2V5;                     /**< inter me SSE lambda config 11. For H2V5 or later version., offset: 0x244 */
  __IO uint32_t SWREG146_H2V5;                     /**< inter me SSE lambda config 12. For H2V5 or later version., offset: 0x248 */
  __IO uint32_t SWREG147_H2V5;                     /**< inter me SSE lambda config 13. For H2V5 or later version., offset: 0x24C */
  __IO uint32_t SWREG148_H2V5;                     /**< inter me SSE lambda config 14. For H2V5 or later version., offset: 0x250 */
  __IO uint32_t SWREG149_H2V5;                     /**< inter me SSE lambda config 15. For H2V5 or later version., offset: 0x254 */
  __IO uint32_t SWREG150;                          /**< inter me SATD lambda config 8, offset: 0x258 */
  __IO uint32_t SWREG151;                          /**< inter me SATD lambda config 9, offset: 0x25C */
  __IO uint32_t SWREG152;                          /**< inter me SATD lambda config 10, offset: 0x260 */
  __IO uint32_t SWREG153;                          /**< inter me SATD lambda config 11, offset: 0x264 */
  __IO uint32_t SWREG154;                          /**< inter me SATD lambda config 12, offset: 0x268 */
  __IO uint32_t SWREG155;                          /**< inter me SATD lambda config 13, offset: 0x26C */
  __IO uint32_t SWREG156;                          /**< inter me SATD lambda config 14, offset: 0x270 */
  __IO uint32_t SWREG157;                          /**< inter me SATD lambda config 15, offset: 0x274 */
  __IO uint32_t SWREG158;                          /**< inter me SSE lambda config 16, offset: 0x278 */
  __IO uint32_t SWREG159;                          /**< inter me SSE lambda config 17, offset: 0x27C */
  __IO uint32_t SWREG160;                          /**< inter me SSE lambda config 18, offset: 0x280 */
  __IO uint32_t SWREG161;                          /**< inter me SSE lambda config 19, offset: 0x284 */
  __IO uint32_t SWREG162;                          /**< inter me SSE lambda config 20, offset: 0x288 */
  __IO uint32_t SWREG163;                          /**< inter me SSE lambda config 21, offset: 0x28C */
  __IO uint32_t SWREG164;                          /**< inter me SSE lambda config 22, offset: 0x290 */
  __IO uint32_t SWREG165;                          /**< inter me SSE lambda config 23, offset: 0x294 */
  __IO uint32_t SWREG166;                          /**< inter me SSE lambda config 24, offset: 0x298 */
  __IO uint32_t SWREG167;                          /**< inter me SSE lambda config 25, offset: 0x29C */
  __IO uint32_t SWREG168;                          /**< inter me SSE lambda config 26, offset: 0x2A0 */
  __IO uint32_t SWREG169;                          /**< inter me SSE lambda config 27, offset: 0x2A4 */
       uint8_t RESERVED_21[8];
  __IO uint32_t SWREG172;                          /**< inter me SSE lambda config 30, offset: 0x2B0 */
  __IO uint32_t SWREG173;                          /**< inter me SSE lambda config 31, offset: 0x2B4 */
  __IO uint32_t SWREG174;                          /**< intra SATD lambda config 8, offset: 0x2B8 */
  __IO uint32_t SWREG175;                          /**< intra SATD lambda config 9, offset: 0x2BC */
  __IO uint32_t SWREG176;                          /**< intra SATD lambda config 10, offset: 0x2C0 */
  __IO uint32_t SWREG177;                          /**< intra SATD lambda config 11, offset: 0x2C4 */
  __IO uint32_t SWREG178;                          /**< intra SATD lambda config 12, offset: 0x2C8 */
  __IO uint32_t SWREG179;                          /**< intra SATD lambda config 13, offset: 0x2CC */
  __IO uint32_t SWREG180;                          /**< intra SATD lambda config 14, offset: 0x2D0 */
  __IO uint32_t SWREG181;                          /**< intra SATD lambda config 15, offset: 0x2D4 */
  __IO uint32_t SWREG182;                          /**< qp fractional part, offset: 0x2D8 */
  __I  uint32_t SWREG183;                          /**< qp sum, offset: 0x2DC */
  __I  uint32_t SWREG184;                          /**< qp num, offset: 0x2E0 */
  __IO uint32_t SWREG185;                          /**< picture complexity. Timeout cycles MSB., offset: 0x2E4 */
  __IO uint32_t SWREG186;                          /**< Base address for CU information table LSB, offset: 0x2E8 */
       uint8_t RESERVED_22[4];
  __IO uint32_t SWREG188;                          /**< Base address for CU information LSB, offset: 0x2F0 */
       uint8_t RESERVED_23[4];
  __IO uint32_t SWREG190;                          /**< Long-term reference pictures config, offset: 0x2F8 */
  __IO uint32_t SWREG191;                          /**< Temporal scalable config, offset: 0x2FC */
       uint8_t RESERVED_24[12];
  __IO uint32_t SWREG195;                          /**< register extension for ctu_size=16, offset: 0x30C */
  __IO uint32_t SWREG196;                          /**< Low Latency Controls, offset: 0x310 */
  __IO uint32_t SWREG197;                          /**< Delta POC extension, offset: 0x314 */
  __IO uint32_t SWREG198;                          /**< Long Term Reference Control, offset: 0x318 */
  __IO uint32_t SWREG199;                          /**< Hash Code Control, offset: 0x31C */
  __IO uint32_t SWREG200;                          /**< Hash Code Value, offset: 0x320 */
  __IO uint32_t SWREG201;                          /**< Background SKIP Control 0, offset: 0x324 */
  __IO uint32_t SWREG202;                          /**< Background SKIP Control 1, offset: 0x328 */
  __IO uint32_t SWREG203;                          /**< Background SKIP Control 2, offset: 0x32C */
  __IO uint32_t SWREG204;                          /**< Background SKIP Control 3, offset: 0x330 */
  __IO uint32_t SWREG205;                          /**< Background SKIP Control 4, offset: 0x334 */
  __IO uint32_t SWREG206;                          /**< Background SKIP Control 5, offset: 0x338 */
  __IO uint32_t SWREG207;                          /**< Background SKIP Control 6, offset: 0x33C */
  __IO uint32_t SWREG208;                          /**< Background SKIP Control 7, offset: 0x340 */
  __IO uint32_t SWREG209;                          /**< IPCM Control 0, offset: 0x344 */
  __IO uint32_t SWREG210;                          /**< IPCM Control 1, offset: 0x348 */
  __IO uint32_t SWREG211;                          /**< IPCM Control 2, offset: 0x34C */
  __IO uint32_t SWREG212;                          /**< IPCM Control 3, offset: 0x350 */
  __IO uint32_t SWREG213;                          /**< IPCM Control 4, offset: 0x354 */
  __I  uint32_t SWREG214;                          /**< HW synthesis config register 2, read-only, offset: 0x358 */
  __I  uint32_t SWREG215;                          /**< AXI Information 0, offset: 0x35C */
  __I  uint32_t SWREG216;                          /**< AXI Information 1, offset: 0x360 */
  __I  uint32_t SWREG217;                          /**< AXI Information 2, offset: 0x364 */
  __I  uint32_t SWREG218;                          /**< AXI Information 3, offset: 0x368 */
  __I  uint32_t SWREG219;                          /**< AXI Information 4, offset: 0x36C */
  __I  uint32_t SWREG220;                          /**< AXI Information 5, offset: 0x370 */
  __I  uint32_t SWREG221;                          /**< AXI Information 6, offset: 0x374 */
  __I  uint32_t SWREG222;                          /**< AXI Information 7, offset: 0x378 */
  __I  uint32_t SWREG223;                          /**< AXI Information 8, offset: 0x37C */
  __IO uint32_t SWREG224;                          /**< control register 4, offset: 0x380 */
  __IO uint32_t SWREG225;                          /**< Tile Control, offset: 0x384 */
  __I  uint32_t SWREG226;                          /**< HW synthesis config register 3, read-only, offset: 0x388 */
       uint8_t RESERVED_25[32];
  __IO uint32_t SWREG235;                          /**< RPS encoding control 0, offset: 0x3AC */
  __IO uint32_t SWREG236;                          /**< RPS encoding control 1, offset: 0x3B0 */
  __IO uint32_t SWREG237;                          /**< Stride Control, offset: 0x3B4 */
  __IO uint32_t SWREG238;                          /**< Dummy Read, offset: 0x3B8 */
  __IO uint32_t SWREG239;                          /**< Base Address LSB of CTB MADs of current frame., offset: 0x3BC */
       uint8_t RESERVED_26[4];
  __IO uint32_t SWREG241;                          /**< Base Address LSB of CTB MADs of previous frame., offset: 0x3C4 */
       uint8_t RESERVED_27[4];
  __IO uint32_t SWREG243;                          /**< CTB RC Control 0, offset: 0x3CC */
  __IO uint32_t SWREG244;                          /**< CTB RC Control 1, offset: 0x3D0 */
  __IO uint32_t SWREG245;                          /**< CTB RC Control 2, offset: 0x3D4 */
  __IO uint32_t SWREG246;                          /**< CTB RC Control 3, offset: 0x3D8 */
  __IO uint32_t SWREG247;                          /**< CTB RC Control 4, offset: 0x3DC */
  __IO uint32_t SWREG248;                          /**< CTB RC Control 5, offset: 0x3E0 */
  __IO uint32_t SWREG249;                          /**< register extension for 8K width, offset: 0x3E4 */
  __IO uint32_t SWREG250;                          /**< Global MV Control 0, offset: 0x3E8 */
  __IO uint32_t SWREG251;                          /**< Global MV Control 1, offset: 0x3EC */
  __IO uint32_t SWREG252;                          /**< ROI3 Area, offset: 0x3F0 */
  __IO uint32_t SWREG253;                          /**< ROI3&4 Area, offset: 0x3F4 */
  __IO uint32_t SWREG254;                          /**< ROI4&5 Area, offset: 0x3F8 */
  __IO uint32_t SWREG255;                          /**< ROI5 Area, offset: 0x3FC */
  __IO uint32_t SWREG256;                          /**< ROI6 Area, offset: 0x400 */
  __IO uint32_t SWREG257;                          /**< ROI6&7 Area, offset: 0x404 */
  __IO uint32_t SWREG258;                          /**< ROI7&8 Area, offset: 0x408 */
  __IO uint32_t SWREG259;                          /**< ROI8 Area, offset: 0x40C */
  __IO uint32_t SWREG260;                          /**< ROI qp, offset: 0x410 */
  __IO uint32_t SWREG261;                          /**< Stride Control, offset: 0x414 */
       uint8_t RESERVED_28[12];
  __IO uint32_t SWREG265;                          /**< Multicore sync ctrl, offset: 0x424 */
  __IO uint32_t SWREG266;                          /**< Multicore sync address L0 LSB, offset: 0x428 */
  __IO uint32_t SWREG267;                          /**< Multicore sync address L0 MSB, offset: 0x42C */
  __IO uint32_t SWREG268;                          /**< Multicore sync address L1 LSB, offset: 0x430 */
  __IO uint32_t SWREG269;                          /**< Multicore sync address L1 MSB, offset: 0x434 */
  __IO uint32_t SWREG270;                          /**< Multicore sync address recon LSB, offset: 0x438 */
  __IO uint32_t SWREG271;                          /**< Multicore sync address recon MSB, offset: 0x43C */
  __IO uint32_t SWREG272;                          /**< Programmable AXI urgent sideband signals, offset: 0x440 */
  __IO uint32_t SWREG273;                          /**< roimap cu ctrl index address LSB, offset: 0x444 */
  __IO uint32_t SWREG274;                          /**< roimap cu ctrl index address MSB, offset: 0x448 */
  __IO uint32_t SWREG275;                          /**< roimap cu ctrl address LSB, offset: 0x44C */
  __IO uint32_t SWREG276;                          /**< roimap cu ctrl address MSB, offset: 0x450 */
  __IO uint32_t SWREG277;                          /**< poc type/bits setting, offset: 0x454 */
  __IO uint32_t SWREG278;                          /**< stream output buffer1 address, offset: 0x458 */
       uint8_t RESERVED_29[4];
  __IO uint32_t SWREG280;                          /**< stream output buffer1 limit size, offset: 0x460 */
  __IO uint32_t SWREG281;                          /**< poc type/bits setting, offset: 0x464 */
       uint8_t RESERVED_30[20];
  __I  uint32_t SWREG287;                          /**< HW synthesis config register 4, read-only, offset: 0x47C */
       uint8_t RESERVED_31[4];
  __IO uint32_t SWREG289;                          /**< Pre-processor color conversion parameters1, offset: 0x484 */
} VPU_HEVC_Type;

/* ----------------------------------------------------------------------------
   -- VPU_HEVC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VPU_HEVC_Register_Masks VPU_HEVC Register Masks
 * @{
 */

/*! @name SWREG1 - Interrupt register encoder */
/*! @{ */

#define VPU_HEVC_SWREG1_SW_ENC_IRQ_MASK          (0x1U)
#define VPU_HEVC_SWREG1_SW_ENC_IRQ_SHIFT         (0U)
#define VPU_HEVC_SWREG1_SW_ENC_IRQ(x)            (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG1_SW_ENC_IRQ_SHIFT)) & VPU_HEVC_SWREG1_SW_ENC_IRQ_MASK)

#define VPU_HEVC_SWREG1_SW_ENC_IRQ_DIS_MASK      (0x2U)
#define VPU_HEVC_SWREG1_SW_ENC_IRQ_DIS_SHIFT     (1U)
#define VPU_HEVC_SWREG1_SW_ENC_IRQ_DIS(x)        (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG1_SW_ENC_IRQ_DIS_SHIFT)) & VPU_HEVC_SWREG1_SW_ENC_IRQ_DIS_MASK)

#define VPU_HEVC_SWREG1_SW_ENC_FRAME_RDY_STATUS_MASK (0x4U)
#define VPU_HEVC_SWREG1_SW_ENC_FRAME_RDY_STATUS_SHIFT (2U)
#define VPU_HEVC_SWREG1_SW_ENC_FRAME_RDY_STATUS(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG1_SW_ENC_FRAME_RDY_STATUS_SHIFT)) & VPU_HEVC_SWREG1_SW_ENC_FRAME_RDY_STATUS_MASK)

#define VPU_HEVC_SWREG1_SW_ENC_BUS_ERROR_STATUS_MASK (0x8U)
#define VPU_HEVC_SWREG1_SW_ENC_BUS_ERROR_STATUS_SHIFT (3U)
#define VPU_HEVC_SWREG1_SW_ENC_BUS_ERROR_STATUS(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG1_SW_ENC_BUS_ERROR_STATUS_SHIFT)) & VPU_HEVC_SWREG1_SW_ENC_BUS_ERROR_STATUS_MASK)

#define VPU_HEVC_SWREG1_SW_ENC_SW_RESET_MASK     (0x10U)
#define VPU_HEVC_SWREG1_SW_ENC_SW_RESET_SHIFT    (4U)
#define VPU_HEVC_SWREG1_SW_ENC_SW_RESET(x)       (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG1_SW_ENC_SW_RESET_SHIFT)) & VPU_HEVC_SWREG1_SW_ENC_SW_RESET_MASK)

#define VPU_HEVC_SWREG1_SW_ENC_BUFFER_FULL_MASK  (0x20U)
#define VPU_HEVC_SWREG1_SW_ENC_BUFFER_FULL_SHIFT (5U)
#define VPU_HEVC_SWREG1_SW_ENC_BUFFER_FULL(x)    (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG1_SW_ENC_BUFFER_FULL_SHIFT)) & VPU_HEVC_SWREG1_SW_ENC_BUFFER_FULL_MASK)

#define VPU_HEVC_SWREG1_SW_ENC_TIMEOUT_MASK      (0x40U)
#define VPU_HEVC_SWREG1_SW_ENC_TIMEOUT_SHIFT     (6U)
#define VPU_HEVC_SWREG1_SW_ENC_TIMEOUT(x)        (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG1_SW_ENC_TIMEOUT_SHIFT)) & VPU_HEVC_SWREG1_SW_ENC_TIMEOUT_MASK)

#define VPU_HEVC_SWREG1_SW_ENC_IRQ_LINE_BUFFER_MASK (0x80U)
#define VPU_HEVC_SWREG1_SW_ENC_IRQ_LINE_BUFFER_SHIFT (7U)
#define VPU_HEVC_SWREG1_SW_ENC_IRQ_LINE_BUFFER(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG1_SW_ENC_IRQ_LINE_BUFFER_SHIFT)) & VPU_HEVC_SWREG1_SW_ENC_IRQ_LINE_BUFFER_MASK)

#define VPU_HEVC_SWREG1_SW_ENC_SLICE_RDY_STATUS_MASK (0x100U)
#define VPU_HEVC_SWREG1_SW_ENC_SLICE_RDY_STATUS_SHIFT (8U)
#define VPU_HEVC_SWREG1_SW_ENC_SLICE_RDY_STATUS(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG1_SW_ENC_SLICE_RDY_STATUS_SHIFT)) & VPU_HEVC_SWREG1_SW_ENC_SLICE_RDY_STATUS_MASK)

#define VPU_HEVC_SWREG1_SW_ENC_IRQ_FUSE_ERROR_MASK (0x200U)
#define VPU_HEVC_SWREG1_SW_ENC_IRQ_FUSE_ERROR_SHIFT (9U)
#define VPU_HEVC_SWREG1_SW_ENC_IRQ_FUSE_ERROR(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG1_SW_ENC_IRQ_FUSE_ERROR_SHIFT)) & VPU_HEVC_SWREG1_SW_ENC_IRQ_FUSE_ERROR_MASK)

#define VPU_HEVC_SWREG1_SW_ENC_TIMEOUT_INT_MASK  (0x800U)
#define VPU_HEVC_SWREG1_SW_ENC_TIMEOUT_INT_SHIFT (11U)
#define VPU_HEVC_SWREG1_SW_ENC_TIMEOUT_INT(x)    (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG1_SW_ENC_TIMEOUT_INT_SHIFT)) & VPU_HEVC_SWREG1_SW_ENC_TIMEOUT_INT_MASK)

#define VPU_HEVC_SWREG1_SW_ENC_STRM_SEGMENT_RDY_INT_MASK (0x1000U)
#define VPU_HEVC_SWREG1_SW_ENC_STRM_SEGMENT_RDY_INT_SHIFT (12U)
#define VPU_HEVC_SWREG1_SW_ENC_STRM_SEGMENT_RDY_INT(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG1_SW_ENC_STRM_SEGMENT_RDY_INT_SHIFT)) & VPU_HEVC_SWREG1_SW_ENC_STRM_SEGMENT_RDY_INT_MASK)
/*! @} */

/*! @name SWREG2 - Data configuration register0 */
/*! @{ */

#define VPU_HEVC_SWREG2_SW_ENC_CTB_RC_MEM_OUT_SWAP_MASK (0xFU)
#define VPU_HEVC_SWREG2_SW_ENC_CTB_RC_MEM_OUT_SWAP_SHIFT (0U)
#define VPU_HEVC_SWREG2_SW_ENC_CTB_RC_MEM_OUT_SWAP(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG2_SW_ENC_CTB_RC_MEM_OUT_SWAP_SHIFT)) & VPU_HEVC_SWREG2_SW_ENC_CTB_RC_MEM_OUT_SWAP_MASK)

#define VPU_HEVC_SWREG2_SW_ENC_ROI_MAP_QP_DELTA_MAP_SWAP_MASK (0xF0U)
#define VPU_HEVC_SWREG2_SW_ENC_ROI_MAP_QP_DELTA_MAP_SWAP_SHIFT (4U)
#define VPU_HEVC_SWREG2_SW_ENC_ROI_MAP_QP_DELTA_MAP_SWAP(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG2_SW_ENC_ROI_MAP_QP_DELTA_MAP_SWAP_SHIFT)) & VPU_HEVC_SWREG2_SW_ENC_ROI_MAP_QP_DELTA_MAP_SWAP_MASK)

#define VPU_HEVC_SWREG2_SW_ENC_PIC_SWAP_MASK     (0xF00U)
#define VPU_HEVC_SWREG2_SW_ENC_PIC_SWAP_SHIFT    (8U)
#define VPU_HEVC_SWREG2_SW_ENC_PIC_SWAP(x)       (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG2_SW_ENC_PIC_SWAP_SHIFT)) & VPU_HEVC_SWREG2_SW_ENC_PIC_SWAP_MASK)

#define VPU_HEVC_SWREG2_SW_ENC_STRM_SWAP_MASK    (0xF000U)
#define VPU_HEVC_SWREG2_SW_ENC_STRM_SWAP_SHIFT   (12U)
#define VPU_HEVC_SWREG2_SW_ENC_STRM_SWAP(x)      (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG2_SW_ENC_STRM_SWAP_SHIFT)) & VPU_HEVC_SWREG2_SW_ENC_STRM_SWAP_MASK)

#define VPU_HEVC_SWREG2_SW_ENC_AXI_READ_ID_MASK  (0xFF0000U)
#define VPU_HEVC_SWREG2_SW_ENC_AXI_READ_ID_SHIFT (16U)
#define VPU_HEVC_SWREG2_SW_ENC_AXI_READ_ID(x)    (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG2_SW_ENC_AXI_READ_ID_SHIFT)) & VPU_HEVC_SWREG2_SW_ENC_AXI_READ_ID_MASK)

#define VPU_HEVC_SWREG2_SW_ENC_AXI_WRITE_ID_MASK (0xFF000000U)
#define VPU_HEVC_SWREG2_SW_ENC_AXI_WRITE_ID_SHIFT (24U)
#define VPU_HEVC_SWREG2_SW_ENC_AXI_WRITE_ID(x)   (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG2_SW_ENC_AXI_WRITE_ID_SHIFT)) & VPU_HEVC_SWREG2_SW_ENC_AXI_WRITE_ID_MASK)
/*! @} */

/*! @name SWREG3 - Data configuration register1 */
/*! @{ */

#define VPU_HEVC_SWREG3_SW_ENC_STRM_SEGMENT_INT_MASK (0x2U)
#define VPU_HEVC_SWREG3_SW_ENC_STRM_SEGMENT_INT_SHIFT (1U)
#define VPU_HEVC_SWREG3_SW_ENC_STRM_SEGMENT_INT(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG3_SW_ENC_STRM_SEGMENT_INT_SHIFT)) & VPU_HEVC_SWREG3_SW_ENC_STRM_SEGMENT_INT_MASK)

#define VPU_HEVC_SWREG3_SW_ENC_LINE_BUFFER_INT_MASK (0x4U)
#define VPU_HEVC_SWREG3_SW_ENC_LINE_BUFFER_INT_SHIFT (2U)
#define VPU_HEVC_SWREG3_SW_ENC_LINE_BUFFER_INT(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG3_SW_ENC_LINE_BUFFER_INT_SHIFT)) & VPU_HEVC_SWREG3_SW_ENC_LINE_BUFFER_INT_MASK)

#define VPU_HEVC_SWREG3_SW_ENC_SLICE_INT_MASK    (0x8U)
#define VPU_HEVC_SWREG3_SW_ENC_SLICE_INT_SHIFT   (3U)
#define VPU_HEVC_SWREG3_SW_ENC_SLICE_INT(x)      (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG3_SW_ENC_SLICE_INT_SHIFT)) & VPU_HEVC_SWREG3_SW_ENC_SLICE_INT_MASK)

#define VPU_HEVC_SWREG3_SW_ENC_CU_INFO_MEM_OUT_SWAP_MASK (0xF00000U)
#define VPU_HEVC_SWREG3_SW_ENC_CU_INFO_MEM_OUT_SWAP_SHIFT (20U)
#define VPU_HEVC_SWREG3_SW_ENC_CU_INFO_MEM_OUT_SWAP(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG3_SW_ENC_CU_INFO_MEM_OUT_SWAP_SHIFT)) & VPU_HEVC_SWREG3_SW_ENC_CU_INFO_MEM_OUT_SWAP_MASK)

#define VPU_HEVC_SWREG3_SW_ENC_AXI_RD_ID_E_MASK  (0x1000000U)
#define VPU_HEVC_SWREG3_SW_ENC_AXI_RD_ID_E_SHIFT (24U)
/*! SW_ENC_AXI_RD_ID_E
 *  0b0..disable.
 *  0b1..enable.
 */
#define VPU_HEVC_SWREG3_SW_ENC_AXI_RD_ID_E(x)    (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG3_SW_ENC_AXI_RD_ID_E_SHIFT)) & VPU_HEVC_SWREG3_SW_ENC_AXI_RD_ID_E_MASK)

#define VPU_HEVC_SWREG3_SW_ENC_AXI_WR_ID_E_MASK  (0x2000000U)
#define VPU_HEVC_SWREG3_SW_ENC_AXI_WR_ID_E_SHIFT (25U)
/*! SW_ENC_AXI_WR_ID_E
 *  0b0..disable.
 *  0b1..enable.
 */
#define VPU_HEVC_SWREG3_SW_ENC_AXI_WR_ID_E(x)    (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG3_SW_ENC_AXI_WR_ID_E_SHIFT)) & VPU_HEVC_SWREG3_SW_ENC_AXI_WR_ID_E_MASK)

#define VPU_HEVC_SWREG3_SW_ENC_CLOCK_GATE_INTER_H264_E_MASK (0x4000000U)
#define VPU_HEVC_SWREG3_SW_ENC_CLOCK_GATE_INTER_H264_E_SHIFT (26U)
/*! SW_ENC_CLOCK_GATE_INTER_H264_E
 *  0b0..clock always on.
 *  0b1..hardware clock gating control
 */
#define VPU_HEVC_SWREG3_SW_ENC_CLOCK_GATE_INTER_H264_E(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG3_SW_ENC_CLOCK_GATE_INTER_H264_E_SHIFT)) & VPU_HEVC_SWREG3_SW_ENC_CLOCK_GATE_INTER_H264_E_MASK)

#define VPU_HEVC_SWREG3_SW_ENC_CLOCK_GATE_INTER_H265_E_MASK (0x8000000U)
#define VPU_HEVC_SWREG3_SW_ENC_CLOCK_GATE_INTER_H265_E_SHIFT (27U)
/*! SW_ENC_CLOCK_GATE_INTER_H265_E
 *  0b0..clock always on.
 *  0b1..hardware clock gating control
 */
#define VPU_HEVC_SWREG3_SW_ENC_CLOCK_GATE_INTER_H265_E(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG3_SW_ENC_CLOCK_GATE_INTER_H265_E_SHIFT)) & VPU_HEVC_SWREG3_SW_ENC_CLOCK_GATE_INTER_H265_E_MASK)

#define VPU_HEVC_SWREG3_SW_ENC_CLOCK_GATE_INTER_E_MASK (0x10000000U)
#define VPU_HEVC_SWREG3_SW_ENC_CLOCK_GATE_INTER_E_SHIFT (28U)
/*! SW_ENC_CLOCK_GATE_INTER_E
 *  0b0..clock always on.
 *  0b1..hardware clock gating control
 */
#define VPU_HEVC_SWREG3_SW_ENC_CLOCK_GATE_INTER_E(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG3_SW_ENC_CLOCK_GATE_INTER_E_SHIFT)) & VPU_HEVC_SWREG3_SW_ENC_CLOCK_GATE_INTER_E_MASK)

#define VPU_HEVC_SWREG3_SW_ENC_CLOCK_GATE_ENCODER_H264_E_MASK (0x20000000U)
#define VPU_HEVC_SWREG3_SW_ENC_CLOCK_GATE_ENCODER_H264_E_SHIFT (29U)
/*! SW_ENC_CLOCK_GATE_ENCODER_H264_E
 *  0b0..clock always on.
 *  0b1..hardware clock gating control
 */
#define VPU_HEVC_SWREG3_SW_ENC_CLOCK_GATE_ENCODER_H264_E(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG3_SW_ENC_CLOCK_GATE_ENCODER_H264_E_SHIFT)) & VPU_HEVC_SWREG3_SW_ENC_CLOCK_GATE_ENCODER_H264_E_MASK)

#define VPU_HEVC_SWREG3_SW_ENC_CLOCK_GATE_ENCODER_H265_E_MASK (0x40000000U)
#define VPU_HEVC_SWREG3_SW_ENC_CLOCK_GATE_ENCODER_H265_E_SHIFT (30U)
/*! SW_ENC_CLOCK_GATE_ENCODER_H265_E
 *  0b0..clock always on.
 *  0b1..hardware clock gating control
 */
#define VPU_HEVC_SWREG3_SW_ENC_CLOCK_GATE_ENCODER_H265_E(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG3_SW_ENC_CLOCK_GATE_ENCODER_H265_E_SHIFT)) & VPU_HEVC_SWREG3_SW_ENC_CLOCK_GATE_ENCODER_H265_E_MASK)

#define VPU_HEVC_SWREG3_SW_ENC_CLOCK_GATE_ENCODER_E_MASK (0x80000000U)
#define VPU_HEVC_SWREG3_SW_ENC_CLOCK_GATE_ENCODER_E_SHIFT (31U)
/*! SW_ENC_CLOCK_GATE_ENCODER_E
 *  0b0..clock always on.
 *  0b1..hardware clock gating control
 */
#define VPU_HEVC_SWREG3_SW_ENC_CLOCK_GATE_ENCODER_E(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG3_SW_ENC_CLOCK_GATE_ENCODER_E_SHIFT)) & VPU_HEVC_SWREG3_SW_ENC_CLOCK_GATE_ENCODER_E_MASK)
/*! @} */

/*! @name SWREG4 - control register 0 */
/*! @{ */

#define VPU_HEVC_SWREG4_SW_ENC_MAX_TRANS_HIERARCHY_DEPTH_INTER_MASK (0x7U)
#define VPU_HEVC_SWREG4_SW_ENC_MAX_TRANS_HIERARCHY_DEPTH_INTER_SHIFT (0U)
#define VPU_HEVC_SWREG4_SW_ENC_MAX_TRANS_HIERARCHY_DEPTH_INTER(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG4_SW_ENC_MAX_TRANS_HIERARCHY_DEPTH_INTER_SHIFT)) & VPU_HEVC_SWREG4_SW_ENC_MAX_TRANS_HIERARCHY_DEPTH_INTER_MASK)

#define VPU_HEVC_SWREG4_SW_ENC_MAX_TRANS_HIERARCHY_DEPTH_INTRA_MASK (0x38U)
#define VPU_HEVC_SWREG4_SW_ENC_MAX_TRANS_HIERARCHY_DEPTH_INTRA_SHIFT (3U)
#define VPU_HEVC_SWREG4_SW_ENC_MAX_TRANS_HIERARCHY_DEPTH_INTRA(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG4_SW_ENC_MAX_TRANS_HIERARCHY_DEPTH_INTRA_SHIFT)) & VPU_HEVC_SWREG4_SW_ENC_MAX_TRANS_HIERARCHY_DEPTH_INTRA_MASK)

#define VPU_HEVC_SWREG4_SW_ENC_SAO_ENABLE_MASK   (0x40U)
#define VPU_HEVC_SWREG4_SW_ENC_SAO_ENABLE_SHIFT  (6U)
#define VPU_HEVC_SWREG4_SW_ENC_SAO_ENABLE(x)     (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG4_SW_ENC_SAO_ENABLE_SHIFT)) & VPU_HEVC_SWREG4_SW_ENC_SAO_ENABLE_MASK)

#define VPU_HEVC_SWREG4_SW_ENC_ACTIVE_OVERRIDE_FLAG_MASK (0x80U)
#define VPU_HEVC_SWREG4_SW_ENC_ACTIVE_OVERRIDE_FLAG_SHIFT (7U)
#define VPU_HEVC_SWREG4_SW_ENC_ACTIVE_OVERRIDE_FLAG(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG4_SW_ENC_ACTIVE_OVERRIDE_FLAG_SHIFT)) & VPU_HEVC_SWREG4_SW_ENC_ACTIVE_OVERRIDE_FLAG_MASK)

#define VPU_HEVC_SWREG4_SW_ENC_SCALING_LIST_ENABLED_FLAG_MASK (0x100U)
#define VPU_HEVC_SWREG4_SW_ENC_SCALING_LIST_ENABLED_FLAG_SHIFT (8U)
#define VPU_HEVC_SWREG4_SW_ENC_SCALING_LIST_ENABLED_FLAG(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG4_SW_ENC_SCALING_LIST_ENABLED_FLAG_SHIFT)) & VPU_HEVC_SWREG4_SW_ENC_SCALING_LIST_ENABLED_FLAG_MASK)

#define VPU_HEVC_SWREG4_SW_BW_LINEBUF_DISABLE_MASK (0x800U)
#define VPU_HEVC_SWREG4_SW_BW_LINEBUF_DISABLE_SHIFT (11U)
#define VPU_HEVC_SWREG4_SW_BW_LINEBUF_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG4_SW_BW_LINEBUF_DISABLE_SHIFT)) & VPU_HEVC_SWREG4_SW_BW_LINEBUF_DISABLE_MASK)

#define VPU_HEVC_SWREG4_SW_ENC_STRONG_INTRA_SMOOTHING_ENABLED_FLAG_MASK (0x1000U)
#define VPU_HEVC_SWREG4_SW_ENC_STRONG_INTRA_SMOOTHING_ENABLED_FLAG_SHIFT (12U)
#define VPU_HEVC_SWREG4_SW_ENC_STRONG_INTRA_SMOOTHING_ENABLED_FLAG(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG4_SW_ENC_STRONG_INTRA_SMOOTHING_ENABLED_FLAG_SHIFT)) & VPU_HEVC_SWREG4_SW_ENC_STRONG_INTRA_SMOOTHING_ENABLED_FLAG_MASK)

#define VPU_HEVC_SWREG4_SW_ENC_CHROMA_QP_OFFSET_MASK (0x3E000U)
#define VPU_HEVC_SWREG4_SW_ENC_CHROMA_QP_OFFSET_SHIFT (13U)
#define VPU_HEVC_SWREG4_SW_ENC_CHROMA_QP_OFFSET(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG4_SW_ENC_CHROMA_QP_OFFSET_SHIFT)) & VPU_HEVC_SWREG4_SW_ENC_CHROMA_QP_OFFSET_MASK)

#define VPU_HEVC_SWREG4_SW_ENC_OUTPUT_STRM_MODE_MASK (0x40000U)
#define VPU_HEVC_SWREG4_SW_ENC_OUTPUT_STRM_MODE_SHIFT (18U)
/*! SW_ENC_OUTPUT_STRM_MODE
 *  0b0..byte stream
 *  0b1..Nal stream
 */
#define VPU_HEVC_SWREG4_SW_ENC_OUTPUT_STRM_MODE(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG4_SW_ENC_OUTPUT_STRM_MODE_SHIFT)) & VPU_HEVC_SWREG4_SW_ENC_OUTPUT_STRM_MODE_MASK)

#define VPU_HEVC_SWREG4_SW_ENC_MAX_TRB_SIZE_MASK (0x180000U)
#define VPU_HEVC_SWREG4_SW_ENC_MAX_TRB_SIZE_SHIFT (19U)
/*! SW_ENC_MAX_TRB_SIZE
 *  0b00..4x4
 *  0b01..8x8
 *  0b10..16x16
 *  0b11..32x32
 */
#define VPU_HEVC_SWREG4_SW_ENC_MAX_TRB_SIZE(x)   (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG4_SW_ENC_MAX_TRB_SIZE_SHIFT)) & VPU_HEVC_SWREG4_SW_ENC_MAX_TRB_SIZE_MASK)

#define VPU_HEVC_SWREG4_SW_ENC_MIN_TRB_SIZE_MASK (0x600000U)
#define VPU_HEVC_SWREG4_SW_ENC_MIN_TRB_SIZE_SHIFT (21U)
/*! SW_ENC_MIN_TRB_SIZE
 *  0b00..4x4
 *  0b01..8x8
 *  0b10..16x16
 *  0b11..32x32
 */
#define VPU_HEVC_SWREG4_SW_ENC_MIN_TRB_SIZE(x)   (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG4_SW_ENC_MIN_TRB_SIZE_SHIFT)) & VPU_HEVC_SWREG4_SW_ENC_MIN_TRB_SIZE_MASK)

#define VPU_HEVC_SWREG4_SW_ENC_MAX_CB_SIZE_MASK  (0x1800000U)
#define VPU_HEVC_SWREG4_SW_ENC_MAX_CB_SIZE_SHIFT (23U)
/*! SW_ENC_MAX_CB_SIZE
 *  0b00..8x8
 *  0b01..16x16
 *  0b10..32x32
 *  0b11..64x64
 */
#define VPU_HEVC_SWREG4_SW_ENC_MAX_CB_SIZE(x)    (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG4_SW_ENC_MAX_CB_SIZE_SHIFT)) & VPU_HEVC_SWREG4_SW_ENC_MAX_CB_SIZE_MASK)

#define VPU_HEVC_SWREG4_SW_ENC_MIN_CB_SIZE_MASK  (0x6000000U)
#define VPU_HEVC_SWREG4_SW_ENC_MIN_CB_SIZE_SHIFT (25U)
/*! SW_ENC_MIN_CB_SIZE
 *  0b00..8x8
 *  0b01..16x16
 *  0b10..32x32
 *  0b11..64x64
 */
#define VPU_HEVC_SWREG4_SW_ENC_MIN_CB_SIZE(x)    (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG4_SW_ENC_MIN_CB_SIZE_SHIFT)) & VPU_HEVC_SWREG4_SW_ENC_MIN_CB_SIZE_MASK)

#define VPU_HEVC_SWREG4_SW_ENC_MODE_MASK         (0xE0000000U)
#define VPU_HEVC_SWREG4_SW_ENC_MODE_SHIFT        (29U)
/*! SW_ENC_MODE
 *  0b001..hevc.
 *  0b010..h264.
 *  0b100..jpeg
 */
#define VPU_HEVC_SWREG4_SW_ENC_MODE(x)           (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG4_SW_ENC_MODE_SHIFT)) & VPU_HEVC_SWREG4_SW_ENC_MODE_MASK)
/*! @} */

/*! @name SWREG5 - control register 1 */
/*! @{ */

#define VPU_HEVC_SWREG5_SW_ENC_E_MASK            (0x1U)
#define VPU_HEVC_SWREG5_SW_ENC_E_SHIFT           (0U)
#define VPU_HEVC_SWREG5_SW_ENC_E(x)              (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG5_SW_ENC_E_SHIFT)) & VPU_HEVC_SWREG5_SW_ENC_E_MASK)

#define VPU_HEVC_SWREG5_SW_ENC_FRAME_CODING_TYPE_MASK (0x6U)
#define VPU_HEVC_SWREG5_SW_ENC_FRAME_CODING_TYPE_SHIFT (1U)
#define VPU_HEVC_SWREG5_SW_ENC_FRAME_CODING_TYPE(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG5_SW_ENC_FRAME_CODING_TYPE_SHIFT)) & VPU_HEVC_SWREG5_SW_ENC_FRAME_CODING_TYPE_MASK)

#define VPU_HEVC_SWREG5_SW_ENC_OUTPUT_CU_INFO_ENABLED_MASK (0x40U)
#define VPU_HEVC_SWREG5_SW_ENC_OUTPUT_CU_INFO_ENABLED_SHIFT (6U)
/*! SW_ENC_OUTPUT_CU_INFO_ENABLED
 *  0b0..disable
 *  0b1..enable
 */
#define VPU_HEVC_SWREG5_SW_ENC_OUTPUT_CU_INFO_ENABLED(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG5_SW_ENC_OUTPUT_CU_INFO_ENABLED_SHIFT)) & VPU_HEVC_SWREG5_SW_ENC_OUTPUT_CU_INFO_ENABLED_MASK)

#define VPU_HEVC_SWREG5_SW_ENC_SLICE_DEBLOCKING_FILTER_OVERRIDE_FLAG_MASK (0x100U)
#define VPU_HEVC_SWREG5_SW_ENC_SLICE_DEBLOCKING_FILTER_OVERRIDE_FLAG_SHIFT (8U)
/*! SW_ENC_SLICE_DEBLOCKING_FILTER_OVERRIDE_FLAG
 *  0b0..no
 *  0b1..yes
 */
#define VPU_HEVC_SWREG5_SW_ENC_SLICE_DEBLOCKING_FILTER_OVERRIDE_FLAG(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG5_SW_ENC_SLICE_DEBLOCKING_FILTER_OVERRIDE_FLAG_SHIFT)) & VPU_HEVC_SWREG5_SW_ENC_SLICE_DEBLOCKING_FILTER_OVERRIDE_FLAG_MASK)

#define VPU_HEVC_SWREG5_SW_ENC_PPS_DEBLOCKING_FILTER_OVERRIDE_ENABLED_FLAG_MASK (0x200U)
#define VPU_HEVC_SWREG5_SW_ENC_PPS_DEBLOCKING_FILTER_OVERRIDE_ENABLED_FLAG_SHIFT (9U)
/*! SW_ENC_PPS_DEBLOCKING_FILTER_OVERRIDE_ENABLED_FLAG
 *  0b0..disable
 *  0b1..enable
 */
#define VPU_HEVC_SWREG5_SW_ENC_PPS_DEBLOCKING_FILTER_OVERRIDE_ENABLED_FLAG(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG5_SW_ENC_PPS_DEBLOCKING_FILTER_OVERRIDE_ENABLED_FLAG_SHIFT)) & VPU_HEVC_SWREG5_SW_ENC_PPS_DEBLOCKING_FILTER_OVERRIDE_ENABLED_FLAG_MASK)

#define VPU_HEVC_SWREG5_SW_ENC_PIC_HEIGHT_MASK   (0x3FF800U)
#define VPU_HEVC_SWREG5_SW_ENC_PIC_HEIGHT_SHIFT  (11U)
#define VPU_HEVC_SWREG5_SW_ENC_PIC_HEIGHT(x)     (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG5_SW_ENC_PIC_HEIGHT_SHIFT)) & VPU_HEVC_SWREG5_SW_ENC_PIC_HEIGHT_MASK)

#define VPU_HEVC_SWREG5_SW_ENC_PIC_WIDTH_MASK    (0xFFC00000U)
#define VPU_HEVC_SWREG5_SW_ENC_PIC_WIDTH_SHIFT   (22U)
#define VPU_HEVC_SWREG5_SW_ENC_PIC_WIDTH(x)      (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG5_SW_ENC_PIC_WIDTH_SHIFT)) & VPU_HEVC_SWREG5_SW_ENC_PIC_WIDTH_MASK)
/*! @} */

/*! @name SWREG7 - control register 3 */
/*! @{ */

#define VPU_HEVC_SWREG7_SW_ENC_ROI2_DELTA_QP_MASK (0xFU)
#define VPU_HEVC_SWREG7_SW_ENC_ROI2_DELTA_QP_SHIFT (0U)
#define VPU_HEVC_SWREG7_SW_ENC_ROI2_DELTA_QP(x)  (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG7_SW_ENC_ROI2_DELTA_QP_SHIFT)) & VPU_HEVC_SWREG7_SW_ENC_ROI2_DELTA_QP_MASK)

#define VPU_HEVC_SWREG7_SW_ENC_ROI1_DELTA_QP_MASK (0xF0U)
#define VPU_HEVC_SWREG7_SW_ENC_ROI1_DELTA_QP_SHIFT (4U)
#define VPU_HEVC_SWREG7_SW_ENC_ROI1_DELTA_QP(x)  (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG7_SW_ENC_ROI1_DELTA_QP_SHIFT)) & VPU_HEVC_SWREG7_SW_ENC_ROI1_DELTA_QP_MASK)

#define VPU_HEVC_SWREG7_SW_ENC_PIC_QP_MASK       (0x3F00U)
#define VPU_HEVC_SWREG7_SW_ENC_PIC_QP_SHIFT      (8U)
#define VPU_HEVC_SWREG7_SW_ENC_PIC_QP(x)         (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG7_SW_ENC_PIC_QP_SHIFT)) & VPU_HEVC_SWREG7_SW_ENC_PIC_QP_MASK)

#define VPU_HEVC_SWREG7_SW_ENC_DIFF_CU_QP_DELTA_DEPTH_MASK (0xC000U)
#define VPU_HEVC_SWREG7_SW_ENC_DIFF_CU_QP_DELTA_DEPTH_SHIFT (14U)
#define VPU_HEVC_SWREG7_SW_ENC_DIFF_CU_QP_DELTA_DEPTH(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG7_SW_ENC_DIFF_CU_QP_DELTA_DEPTH_SHIFT)) & VPU_HEVC_SWREG7_SW_ENC_DIFF_CU_QP_DELTA_DEPTH_MASK)

#define VPU_HEVC_SWREG7_SW_ENC_NUM_SLICES_READY_MASK (0x1FE0000U)
#define VPU_HEVC_SWREG7_SW_ENC_NUM_SLICES_READY_SHIFT (17U)
#define VPU_HEVC_SWREG7_SW_ENC_NUM_SLICES_READY(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG7_SW_ENC_NUM_SLICES_READY_SHIFT)) & VPU_HEVC_SWREG7_SW_ENC_NUM_SLICES_READY_MASK)

#define VPU_HEVC_SWREG7_SW_ENC_CABAC_INIT_FLAG_MASK (0x2000000U)
#define VPU_HEVC_SWREG7_SW_ENC_CABAC_INIT_FLAG_SHIFT (25U)
#define VPU_HEVC_SWREG7_SW_ENC_CABAC_INIT_FLAG(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG7_SW_ENC_CABAC_INIT_FLAG_SHIFT)) & VPU_HEVC_SWREG7_SW_ENC_CABAC_INIT_FLAG_MASK)

#define VPU_HEVC_SWREG7_SW_ENC_PIC_INIT_QP_MASK  (0xFC000000U)
#define VPU_HEVC_SWREG7_SW_ENC_PIC_INIT_QP_SHIFT (26U)
#define VPU_HEVC_SWREG7_SW_ENC_PIC_INIT_QP(x)    (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG7_SW_ENC_PIC_INIT_QP_SHIFT)) & VPU_HEVC_SWREG7_SW_ENC_PIC_INIT_QP_MASK)
/*! @} */

/*! @name SWREG8 - stream output buffer0 address */
/*! @{ */

#define VPU_HEVC_SWREG8_SW_ENC_OUTPUT_STRM_BASE_MASK (0xFFFFFFFFU)
#define VPU_HEVC_SWREG8_SW_ENC_OUTPUT_STRM_BASE_SHIFT (0U)
#define VPU_HEVC_SWREG8_SW_ENC_OUTPUT_STRM_BASE(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG8_SW_ENC_OUTPUT_STRM_BASE_SHIFT)) & VPU_HEVC_SWREG8_SW_ENC_OUTPUT_STRM_BASE_MASK)
/*! @} */

/*! @name SWREG9 - stream output buffer0 limit size */
/*! @{ */

#define VPU_HEVC_SWREG9_SW_ENC_OUTPUT_STRM_BUFFER_LIMIT_MASK (0xFFFFFFFFU)
#define VPU_HEVC_SWREG9_SW_ENC_OUTPUT_STRM_BUFFER_LIMIT_SHIFT (0U)
#define VPU_HEVC_SWREG9_SW_ENC_OUTPUT_STRM_BUFFER_LIMIT(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG9_SW_ENC_OUTPUT_STRM_BUFFER_LIMIT_SHIFT)) & VPU_HEVC_SWREG9_SW_ENC_OUTPUT_STRM_BUFFER_LIMIT_MASK)
/*! @} */

/*! @name SWREG10 - sizeTblBase */
/*! @{ */

#define VPU_HEVC_SWREG10_SW_ENC_SIZE_TBL_BASE_MASK (0xFFFFFFFFU)
#define VPU_HEVC_SWREG10_SW_ENC_SIZE_TBL_BASE_SHIFT (0U)
#define VPU_HEVC_SWREG10_SW_ENC_SIZE_TBL_BASE(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG10_SW_ENC_SIZE_TBL_BASE_SHIFT)) & VPU_HEVC_SWREG10_SW_ENC_SIZE_TBL_BASE_MASK)
/*! @} */

/*! @name SWREG11 - encoded Picture order count */
/*! @{ */

#define VPU_HEVC_SWREG11_SW_ENC_POC_MASK         (0xFFFFFFFFU)
#define VPU_HEVC_SWREG11_SW_ENC_POC_SHIFT        (0U)
#define VPU_HEVC_SWREG11_SW_ENC_POC(x)           (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG11_SW_ENC_POC_SHIFT)) & VPU_HEVC_SWREG11_SW_ENC_POC_MASK)
/*! @} */

/*! @name SWREG12 - input lum base address */
/*! @{ */

#define VPU_HEVC_SWREG12_SW_ENC_INPUT_Y_BASE_MASK (0xFFFFFFFFU)
#define VPU_HEVC_SWREG12_SW_ENC_INPUT_Y_BASE_SHIFT (0U)
#define VPU_HEVC_SWREG12_SW_ENC_INPUT_Y_BASE(x)  (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG12_SW_ENC_INPUT_Y_BASE_SHIFT)) & VPU_HEVC_SWREG12_SW_ENC_INPUT_Y_BASE_MASK)
/*! @} */

/*! @name SWREG13 - input cb base address */
/*! @{ */

#define VPU_HEVC_SWREG13_SW_ENC_INPUT_CB_BASE_MASK (0xFFFFFFFFU)
#define VPU_HEVC_SWREG13_SW_ENC_INPUT_CB_BASE_SHIFT (0U)
#define VPU_HEVC_SWREG13_SW_ENC_INPUT_CB_BASE(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG13_SW_ENC_INPUT_CB_BASE_SHIFT)) & VPU_HEVC_SWREG13_SW_ENC_INPUT_CB_BASE_MASK)
/*! @} */

/*! @name SWREG14 - input cr base address */
/*! @{ */

#define VPU_HEVC_SWREG14_SW_ENC_INPUT_CR_BASE_MASK (0xFFFFFFFFU)
#define VPU_HEVC_SWREG14_SW_ENC_INPUT_CR_BASE_SHIFT (0U)
#define VPU_HEVC_SWREG14_SW_ENC_INPUT_CR_BASE(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG14_SW_ENC_INPUT_CR_BASE_SHIFT)) & VPU_HEVC_SWREG14_SW_ENC_INPUT_CR_BASE_MASK)
/*! @} */

/*! @name SWREG15 - recon image luma base address */
/*! @{ */

#define VPU_HEVC_SWREG15_SW_ENC_RECON_Y_BASE_MASK (0xFFFFFFFFU)
#define VPU_HEVC_SWREG15_SW_ENC_RECON_Y_BASE_SHIFT (0U)
#define VPU_HEVC_SWREG15_SW_ENC_RECON_Y_BASE(x)  (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG15_SW_ENC_RECON_Y_BASE_SHIFT)) & VPU_HEVC_SWREG15_SW_ENC_RECON_Y_BASE_MASK)
/*! @} */

/*! @name SWREG16 - recon image chroma base address */
/*! @{ */

#define VPU_HEVC_SWREG16_SW_ENC_RECON_CHROMA_BASE_MASK (0xFFFFFFFFU)
#define VPU_HEVC_SWREG16_SW_ENC_RECON_CHROMA_BASE_SHIFT (0U)
#define VPU_HEVC_SWREG16_SW_ENC_RECON_CHROMA_BASE(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG16_SW_ENC_RECON_CHROMA_BASE_SHIFT)) & VPU_HEVC_SWREG16_SW_ENC_RECON_CHROMA_BASE_MASK)
/*! @} */

/*! @name SWREG18 - reference picture reconstructed list0 luma0 */
/*! @{ */

#define VPU_HEVC_SWREG18_SW_ENC_REFPIC_RECON_L0_Y0_MASK (0xFFFFFFFFU)
#define VPU_HEVC_SWREG18_SW_ENC_REFPIC_RECON_L0_Y0_SHIFT (0U)
#define VPU_HEVC_SWREG18_SW_ENC_REFPIC_RECON_L0_Y0(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG18_SW_ENC_REFPIC_RECON_L0_Y0_SHIFT)) & VPU_HEVC_SWREG18_SW_ENC_REFPIC_RECON_L0_Y0_MASK)
/*! @} */

/*! @name SWREG19 - reference picture reconstructed list0 chroma0 */
/*! @{ */

#define VPU_HEVC_SWREG19_SW_ENC_REFPIC_RECON_L0_CHROMA0_MASK (0xFFFFFFFFU)
#define VPU_HEVC_SWREG19_SW_ENC_REFPIC_RECON_L0_CHROMA0_SHIFT (0U)
#define VPU_HEVC_SWREG19_SW_ENC_REFPIC_RECON_L0_CHROMA0(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG19_SW_ENC_REFPIC_RECON_L0_CHROMA0_SHIFT)) & VPU_HEVC_SWREG19_SW_ENC_REFPIC_RECON_L0_CHROMA0_MASK)
/*! @} */

/*! @name SWREG22 - Cyclic Intra */
/*! @{ */

#define VPU_HEVC_SWREG22_SW_ENC_RCROI_ENABLE_MASK (0xFU)
#define VPU_HEVC_SWREG22_SW_ENC_RCROI_ENABLE_SHIFT (0U)
#define VPU_HEVC_SWREG22_SW_ENC_RCROI_ENABLE(x)  (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG22_SW_ENC_RCROI_ENABLE_SHIFT)) & VPU_HEVC_SWREG22_SW_ENC_RCROI_ENABLE_MASK)

#define VPU_HEVC_SWREG22_SW_ENC_CIR_INTERVAL_MASK (0x3FFF0U)
#define VPU_HEVC_SWREG22_SW_ENC_CIR_INTERVAL_SHIFT (4U)
#define VPU_HEVC_SWREG22_SW_ENC_CIR_INTERVAL(x)  (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG22_SW_ENC_CIR_INTERVAL_SHIFT)) & VPU_HEVC_SWREG22_SW_ENC_CIR_INTERVAL_MASK)

#define VPU_HEVC_SWREG22_SW_ENC_CIR_START_MASK   (0xFFFC0000U)
#define VPU_HEVC_SWREG22_SW_ENC_CIR_START_SHIFT  (18U)
#define VPU_HEVC_SWREG22_SW_ENC_CIR_START(x)     (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG22_SW_ENC_CIR_START_SHIFT)) & VPU_HEVC_SWREG22_SW_ENC_CIR_START_MASK)
/*! @} */

/*! @name SWREG23 - intra Area */
/*! @{ */

#define VPU_HEVC_SWREG23_SW_ENC_INTRA_AREA_BOTTOM_MASK (0xFFU)
#define VPU_HEVC_SWREG23_SW_ENC_INTRA_AREA_BOTTOM_SHIFT (0U)
#define VPU_HEVC_SWREG23_SW_ENC_INTRA_AREA_BOTTOM(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG23_SW_ENC_INTRA_AREA_BOTTOM_SHIFT)) & VPU_HEVC_SWREG23_SW_ENC_INTRA_AREA_BOTTOM_MASK)

#define VPU_HEVC_SWREG23_SW_ENC_INTRA_AREA_TOP_MASK (0xFF00U)
#define VPU_HEVC_SWREG23_SW_ENC_INTRA_AREA_TOP_SHIFT (8U)
#define VPU_HEVC_SWREG23_SW_ENC_INTRA_AREA_TOP(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG23_SW_ENC_INTRA_AREA_TOP_SHIFT)) & VPU_HEVC_SWREG23_SW_ENC_INTRA_AREA_TOP_MASK)

#define VPU_HEVC_SWREG23_SW_ENC_INTRA_AREA_RIGHT_MASK (0xFF0000U)
#define VPU_HEVC_SWREG23_SW_ENC_INTRA_AREA_RIGHT_SHIFT (16U)
#define VPU_HEVC_SWREG23_SW_ENC_INTRA_AREA_RIGHT(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG23_SW_ENC_INTRA_AREA_RIGHT_SHIFT)) & VPU_HEVC_SWREG23_SW_ENC_INTRA_AREA_RIGHT_MASK)

#define VPU_HEVC_SWREG23_SW_ENC_INTRA_AREA_LEFT_MASK (0xFF000000U)
#define VPU_HEVC_SWREG23_SW_ENC_INTRA_AREA_LEFT_SHIFT (24U)
#define VPU_HEVC_SWREG23_SW_ENC_INTRA_AREA_LEFT(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG23_SW_ENC_INTRA_AREA_LEFT_SHIFT)) & VPU_HEVC_SWREG23_SW_ENC_INTRA_AREA_LEFT_MASK)
/*! @} */

/*! @name SWREG24 - ROI1 Area */
/*! @{ */

#define VPU_HEVC_SWREG24_SW_ENC_ROI1_BOTTOM_MASK (0xFFU)
#define VPU_HEVC_SWREG24_SW_ENC_ROI1_BOTTOM_SHIFT (0U)
#define VPU_HEVC_SWREG24_SW_ENC_ROI1_BOTTOM(x)   (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG24_SW_ENC_ROI1_BOTTOM_SHIFT)) & VPU_HEVC_SWREG24_SW_ENC_ROI1_BOTTOM_MASK)

#define VPU_HEVC_SWREG24_SW_ENC_ROI1_TOP_MASK    (0xFF00U)
#define VPU_HEVC_SWREG24_SW_ENC_ROI1_TOP_SHIFT   (8U)
#define VPU_HEVC_SWREG24_SW_ENC_ROI1_TOP(x)      (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG24_SW_ENC_ROI1_TOP_SHIFT)) & VPU_HEVC_SWREG24_SW_ENC_ROI1_TOP_MASK)

#define VPU_HEVC_SWREG24_SW_ENC_ROI1_RIGHT_MASK  (0xFF0000U)
#define VPU_HEVC_SWREG24_SW_ENC_ROI1_RIGHT_SHIFT (16U)
#define VPU_HEVC_SWREG24_SW_ENC_ROI1_RIGHT(x)    (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG24_SW_ENC_ROI1_RIGHT_SHIFT)) & VPU_HEVC_SWREG24_SW_ENC_ROI1_RIGHT_MASK)

#define VPU_HEVC_SWREG24_SW_ENC_ROI1_LEFT_MASK   (0xFF000000U)
#define VPU_HEVC_SWREG24_SW_ENC_ROI1_LEFT_SHIFT  (24U)
#define VPU_HEVC_SWREG24_SW_ENC_ROI1_LEFT(x)     (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG24_SW_ENC_ROI1_LEFT_SHIFT)) & VPU_HEVC_SWREG24_SW_ENC_ROI1_LEFT_MASK)
/*! @} */

/*! @name SWREG25 - ROI2 Area */
/*! @{ */

#define VPU_HEVC_SWREG25_SW_ENC_ROI2_BOTTOM_MASK (0xFFU)
#define VPU_HEVC_SWREG25_SW_ENC_ROI2_BOTTOM_SHIFT (0U)
#define VPU_HEVC_SWREG25_SW_ENC_ROI2_BOTTOM(x)   (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG25_SW_ENC_ROI2_BOTTOM_SHIFT)) & VPU_HEVC_SWREG25_SW_ENC_ROI2_BOTTOM_MASK)

#define VPU_HEVC_SWREG25_SW_ENC_ROI2_TOP_MASK    (0xFF00U)
#define VPU_HEVC_SWREG25_SW_ENC_ROI2_TOP_SHIFT   (8U)
#define VPU_HEVC_SWREG25_SW_ENC_ROI2_TOP(x)      (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG25_SW_ENC_ROI2_TOP_SHIFT)) & VPU_HEVC_SWREG25_SW_ENC_ROI2_TOP_MASK)

#define VPU_HEVC_SWREG25_SW_ENC_ROI2_RIGHT_MASK  (0xFF0000U)
#define VPU_HEVC_SWREG25_SW_ENC_ROI2_RIGHT_SHIFT (16U)
#define VPU_HEVC_SWREG25_SW_ENC_ROI2_RIGHT(x)    (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG25_SW_ENC_ROI2_RIGHT_SHIFT)) & VPU_HEVC_SWREG25_SW_ENC_ROI2_RIGHT_MASK)

#define VPU_HEVC_SWREG25_SW_ENC_ROI2_LEFT_MASK   (0xFF000000U)
#define VPU_HEVC_SWREG25_SW_ENC_ROI2_LEFT_SHIFT  (24U)
#define VPU_HEVC_SWREG25_SW_ENC_ROI2_LEFT(x)     (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG25_SW_ENC_ROI2_LEFT_SHIFT)) & VPU_HEVC_SWREG25_SW_ENC_ROI2_LEFT_MASK)
/*! @} */

/*! @name SWREG26_H2V2 - intra size factors. For H2V2 or later version. */
/*! @{ */

#define VPU_HEVC_SWREG26_H2V2_SW_ENC_INTRA_SIZE_FACTOR_2_MASK (0xFFCU)
#define VPU_HEVC_SWREG26_H2V2_SW_ENC_INTRA_SIZE_FACTOR_2_SHIFT (2U)
#define VPU_HEVC_SWREG26_H2V2_SW_ENC_INTRA_SIZE_FACTOR_2(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG26_H2V2_SW_ENC_INTRA_SIZE_FACTOR_2_SHIFT)) & VPU_HEVC_SWREG26_H2V2_SW_ENC_INTRA_SIZE_FACTOR_2_MASK)

#define VPU_HEVC_SWREG26_H2V2_SW_ENC_INTRA_SIZE_FACTOR_1_MASK (0x3FF000U)
#define VPU_HEVC_SWREG26_H2V2_SW_ENC_INTRA_SIZE_FACTOR_1_SHIFT (12U)
#define VPU_HEVC_SWREG26_H2V2_SW_ENC_INTRA_SIZE_FACTOR_1(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG26_H2V2_SW_ENC_INTRA_SIZE_FACTOR_1_SHIFT)) & VPU_HEVC_SWREG26_H2V2_SW_ENC_INTRA_SIZE_FACTOR_1_MASK)

#define VPU_HEVC_SWREG26_H2V2_SW_ENC_INTRA_SIZE_FACTOR_0_MASK (0xFFC00000U)
#define VPU_HEVC_SWREG26_H2V2_SW_ENC_INTRA_SIZE_FACTOR_0_SHIFT (22U)
#define VPU_HEVC_SWREG26_H2V2_SW_ENC_INTRA_SIZE_FACTOR_0(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG26_H2V2_SW_ENC_INTRA_SIZE_FACTOR_0_SHIFT)) & VPU_HEVC_SWREG26_H2V2_SW_ENC_INTRA_SIZE_FACTOR_0_MASK)
/*! @} */

/*! @name SWREG27_H2V2 - intra mode factors . For H2V2 or later version. */
/*! @{ */

#define VPU_HEVC_SWREG27_H2V2_SW_ENC_INTRA_MODE_FACTOR_2_MASK (0x7F0U)
#define VPU_HEVC_SWREG27_H2V2_SW_ENC_INTRA_MODE_FACTOR_2_SHIFT (4U)
#define VPU_HEVC_SWREG27_H2V2_SW_ENC_INTRA_MODE_FACTOR_2(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG27_H2V2_SW_ENC_INTRA_MODE_FACTOR_2_SHIFT)) & VPU_HEVC_SWREG27_H2V2_SW_ENC_INTRA_MODE_FACTOR_2_MASK)

#define VPU_HEVC_SWREG27_H2V2_SW_ENC_INTRA_MODE_FACTOR_1_MASK (0x1F800U)
#define VPU_HEVC_SWREG27_H2V2_SW_ENC_INTRA_MODE_FACTOR_1_SHIFT (11U)
#define VPU_HEVC_SWREG27_H2V2_SW_ENC_INTRA_MODE_FACTOR_1(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG27_H2V2_SW_ENC_INTRA_MODE_FACTOR_1_SHIFT)) & VPU_HEVC_SWREG27_H2V2_SW_ENC_INTRA_MODE_FACTOR_1_MASK)

#define VPU_HEVC_SWREG27_H2V2_SW_ENC_INTRA_MODE_FACTOR_0_MASK (0x3E0000U)
#define VPU_HEVC_SWREG27_H2V2_SW_ENC_INTRA_MODE_FACTOR_0_SHIFT (17U)
#define VPU_HEVC_SWREG27_H2V2_SW_ENC_INTRA_MODE_FACTOR_0(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG27_H2V2_SW_ENC_INTRA_MODE_FACTOR_0_SHIFT)) & VPU_HEVC_SWREG27_H2V2_SW_ENC_INTRA_MODE_FACTOR_0_MASK)

#define VPU_HEVC_SWREG27_H2V2_SW_ENC_INTRA_SIZE_FACTOR_3_MASK (0xFFC00000U)
#define VPU_HEVC_SWREG27_H2V2_SW_ENC_INTRA_SIZE_FACTOR_3_SHIFT (22U)
#define VPU_HEVC_SWREG27_H2V2_SW_ENC_INTRA_SIZE_FACTOR_3(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG27_H2V2_SW_ENC_INTRA_SIZE_FACTOR_3_SHIFT)) & VPU_HEVC_SWREG27_H2V2_SW_ENC_INTRA_SIZE_FACTOR_3_MASK)
/*! @} */

/*! @name SWREG28_H2V5 - inter me SATD lambda config 0. For H2V5 or later version. */
/*! @{ */

#define VPU_HEVC_SWREG28_H2V5_SW_ENC_LAMDA_SATD_ME_1_EXPAND5BIT_MASK (0x7FFC0U)
#define VPU_HEVC_SWREG28_H2V5_SW_ENC_LAMDA_SATD_ME_1_EXPAND5BIT_SHIFT (6U)
#define VPU_HEVC_SWREG28_H2V5_SW_ENC_LAMDA_SATD_ME_1_EXPAND5BIT(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG28_H2V5_SW_ENC_LAMDA_SATD_ME_1_EXPAND5BIT_SHIFT)) & VPU_HEVC_SWREG28_H2V5_SW_ENC_LAMDA_SATD_ME_1_EXPAND5BIT_MASK)

#define VPU_HEVC_SWREG28_H2V5_SW_ENC_LAMDA_SATD_ME_0_EXPAND5BIT_MASK (0xFFF80000U)
#define VPU_HEVC_SWREG28_H2V5_SW_ENC_LAMDA_SATD_ME_0_EXPAND5BIT_SHIFT (19U)
#define VPU_HEVC_SWREG28_H2V5_SW_ENC_LAMDA_SATD_ME_0_EXPAND5BIT(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG28_H2V5_SW_ENC_LAMDA_SATD_ME_0_EXPAND5BIT_SHIFT)) & VPU_HEVC_SWREG28_H2V5_SW_ENC_LAMDA_SATD_ME_0_EXPAND5BIT_MASK)
/*! @} */

/*! @name SWREG29_H2V5 - inter me SATD lambda config 1.For H2V5 or later version. */
/*! @{ */

#define VPU_HEVC_SWREG29_H2V5_SW_ENC_LAMDA_SATD_ME_3_EXPAND5BIT_MASK (0x7FFC0U)
#define VPU_HEVC_SWREG29_H2V5_SW_ENC_LAMDA_SATD_ME_3_EXPAND5BIT_SHIFT (6U)
#define VPU_HEVC_SWREG29_H2V5_SW_ENC_LAMDA_SATD_ME_3_EXPAND5BIT(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG29_H2V5_SW_ENC_LAMDA_SATD_ME_3_EXPAND5BIT_SHIFT)) & VPU_HEVC_SWREG29_H2V5_SW_ENC_LAMDA_SATD_ME_3_EXPAND5BIT_MASK)

#define VPU_HEVC_SWREG29_H2V5_SW_ENC_LAMDA_SATD_ME_2_EXPAND5BIT_MASK (0xFFF80000U)
#define VPU_HEVC_SWREG29_H2V5_SW_ENC_LAMDA_SATD_ME_2_EXPAND5BIT_SHIFT (19U)
#define VPU_HEVC_SWREG29_H2V5_SW_ENC_LAMDA_SATD_ME_2_EXPAND5BIT(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG29_H2V5_SW_ENC_LAMDA_SATD_ME_2_EXPAND5BIT_SHIFT)) & VPU_HEVC_SWREG29_H2V5_SW_ENC_LAMDA_SATD_ME_2_EXPAND5BIT_MASK)
/*! @} */

/*! @name SWREG30_H2V5 - inter me SATD lambda config 2. For H2V5 or later version. */
/*! @{ */

#define VPU_HEVC_SWREG30_H2V5_SW_ENC_LAMDA_SATD_ME_5_EXPAND5BIT_MASK (0x7FFC0U)
#define VPU_HEVC_SWREG30_H2V5_SW_ENC_LAMDA_SATD_ME_5_EXPAND5BIT_SHIFT (6U)
#define VPU_HEVC_SWREG30_H2V5_SW_ENC_LAMDA_SATD_ME_5_EXPAND5BIT(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG30_H2V5_SW_ENC_LAMDA_SATD_ME_5_EXPAND5BIT_SHIFT)) & VPU_HEVC_SWREG30_H2V5_SW_ENC_LAMDA_SATD_ME_5_EXPAND5BIT_MASK)

#define VPU_HEVC_SWREG30_H2V5_SW_ENC_LAMDA_SATD_ME_4_EXPAND5BIT_MASK (0xFFF80000U)
#define VPU_HEVC_SWREG30_H2V5_SW_ENC_LAMDA_SATD_ME_4_EXPAND5BIT_SHIFT (19U)
#define VPU_HEVC_SWREG30_H2V5_SW_ENC_LAMDA_SATD_ME_4_EXPAND5BIT(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG30_H2V5_SW_ENC_LAMDA_SATD_ME_4_EXPAND5BIT_SHIFT)) & VPU_HEVC_SWREG30_H2V5_SW_ENC_LAMDA_SATD_ME_4_EXPAND5BIT_MASK)
/*! @} */

/*! @name SWREG31_H2V5 - inter me SATD lambda config 3. For H2V5 or later version. */
/*! @{ */

#define VPU_HEVC_SWREG31_H2V5_SW_ENC_LAMDA_SATD_ME_7_EXPAND5BIT_MASK (0x7FFC0U)
#define VPU_HEVC_SWREG31_H2V5_SW_ENC_LAMDA_SATD_ME_7_EXPAND5BIT_SHIFT (6U)
#define VPU_HEVC_SWREG31_H2V5_SW_ENC_LAMDA_SATD_ME_7_EXPAND5BIT(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG31_H2V5_SW_ENC_LAMDA_SATD_ME_7_EXPAND5BIT_SHIFT)) & VPU_HEVC_SWREG31_H2V5_SW_ENC_LAMDA_SATD_ME_7_EXPAND5BIT_MASK)

#define VPU_HEVC_SWREG31_H2V5_SW_ENC_LAMDA_SATD_ME_6_EXPAND5BIT_MASK (0xFFF80000U)
#define VPU_HEVC_SWREG31_H2V5_SW_ENC_LAMDA_SATD_ME_6_EXPAND5BIT_SHIFT (19U)
#define VPU_HEVC_SWREG31_H2V5_SW_ENC_LAMDA_SATD_ME_6_EXPAND5BIT(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG31_H2V5_SW_ENC_LAMDA_SATD_ME_6_EXPAND5BIT_SHIFT)) & VPU_HEVC_SWREG31_H2V5_SW_ENC_LAMDA_SATD_ME_6_EXPAND5BIT_MASK)
/*! @} */

/*! @name SWREG32_H2V5 - inter me SATD lambda config 4. For H2V5 or later version. */
/*! @{ */

#define VPU_HEVC_SWREG32_H2V5_SW_ENC_LAMDA_SATD_ME_9_EXPAND5BIT_MASK (0x7FFC0U)
#define VPU_HEVC_SWREG32_H2V5_SW_ENC_LAMDA_SATD_ME_9_EXPAND5BIT_SHIFT (6U)
#define VPU_HEVC_SWREG32_H2V5_SW_ENC_LAMDA_SATD_ME_9_EXPAND5BIT(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG32_H2V5_SW_ENC_LAMDA_SATD_ME_9_EXPAND5BIT_SHIFT)) & VPU_HEVC_SWREG32_H2V5_SW_ENC_LAMDA_SATD_ME_9_EXPAND5BIT_MASK)

#define VPU_HEVC_SWREG32_H2V5_SW_ENC_LAMDA_SATD_ME_8_EXPAND5BIT_MASK (0xFFF80000U)
#define VPU_HEVC_SWREG32_H2V5_SW_ENC_LAMDA_SATD_ME_8_EXPAND5BIT_SHIFT (19U)
#define VPU_HEVC_SWREG32_H2V5_SW_ENC_LAMDA_SATD_ME_8_EXPAND5BIT(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG32_H2V5_SW_ENC_LAMDA_SATD_ME_8_EXPAND5BIT_SHIFT)) & VPU_HEVC_SWREG32_H2V5_SW_ENC_LAMDA_SATD_ME_8_EXPAND5BIT_MASK)
/*! @} */

/*! @name SWREG33_H2V5 - inter me SATD lambda config 5. For H2V5 or later version. */
/*! @{ */

#define VPU_HEVC_SWREG33_H2V5_SW_ENC_LAMDA_SATD_ME_11_EXPAND5BIT_MASK (0x7FFC0U)
#define VPU_HEVC_SWREG33_H2V5_SW_ENC_LAMDA_SATD_ME_11_EXPAND5BIT_SHIFT (6U)
#define VPU_HEVC_SWREG33_H2V5_SW_ENC_LAMDA_SATD_ME_11_EXPAND5BIT(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG33_H2V5_SW_ENC_LAMDA_SATD_ME_11_EXPAND5BIT_SHIFT)) & VPU_HEVC_SWREG33_H2V5_SW_ENC_LAMDA_SATD_ME_11_EXPAND5BIT_MASK)

#define VPU_HEVC_SWREG33_H2V5_SW_ENC_LAMDA_SATD_ME_10_EXPAND5BIT_MASK (0xFFF80000U)
#define VPU_HEVC_SWREG33_H2V5_SW_ENC_LAMDA_SATD_ME_10_EXPAND5BIT_SHIFT (19U)
#define VPU_HEVC_SWREG33_H2V5_SW_ENC_LAMDA_SATD_ME_10_EXPAND5BIT(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG33_H2V5_SW_ENC_LAMDA_SATD_ME_10_EXPAND5BIT_SHIFT)) & VPU_HEVC_SWREG33_H2V5_SW_ENC_LAMDA_SATD_ME_10_EXPAND5BIT_MASK)
/*! @} */

/*! @name SWREG34_H2V5 - inter me SATD lambda config 6. For H2V5 or later version. */
/*! @{ */

#define VPU_HEVC_SWREG34_H2V5_SW_ENC_LAMDA_SATD_ME_13_EXPAND5BIT_MASK (0x7FFC0U)
#define VPU_HEVC_SWREG34_H2V5_SW_ENC_LAMDA_SATD_ME_13_EXPAND5BIT_SHIFT (6U)
#define VPU_HEVC_SWREG34_H2V5_SW_ENC_LAMDA_SATD_ME_13_EXPAND5BIT(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG34_H2V5_SW_ENC_LAMDA_SATD_ME_13_EXPAND5BIT_SHIFT)) & VPU_HEVC_SWREG34_H2V5_SW_ENC_LAMDA_SATD_ME_13_EXPAND5BIT_MASK)

#define VPU_HEVC_SWREG34_H2V5_SW_ENC_LAMDA_SATD_ME_12_EXPAND5BIT_MASK (0xFFF80000U)
#define VPU_HEVC_SWREG34_H2V5_SW_ENC_LAMDA_SATD_ME_12_EXPAND5BIT_SHIFT (19U)
#define VPU_HEVC_SWREG34_H2V5_SW_ENC_LAMDA_SATD_ME_12_EXPAND5BIT(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG34_H2V5_SW_ENC_LAMDA_SATD_ME_12_EXPAND5BIT_SHIFT)) & VPU_HEVC_SWREG34_H2V5_SW_ENC_LAMDA_SATD_ME_12_EXPAND5BIT_MASK)
/*! @} */

/*! @name SWREG35 - inter prediction parameters1 */
/*! @{ */

#define VPU_HEVC_SWREG35_SW_ENC_BITS_EST_BIAS_INTRA_CU_16_MASK (0xFFU)
#define VPU_HEVC_SWREG35_SW_ENC_BITS_EST_BIAS_INTRA_CU_16_SHIFT (0U)
#define VPU_HEVC_SWREG35_SW_ENC_BITS_EST_BIAS_INTRA_CU_16(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG35_SW_ENC_BITS_EST_BIAS_INTRA_CU_16_SHIFT)) & VPU_HEVC_SWREG35_SW_ENC_BITS_EST_BIAS_INTRA_CU_16_MASK)

#define VPU_HEVC_SWREG35_SW_ENC_BITS_EST_BIAS_INTRA_CU_8_MASK (0x7F00U)
#define VPU_HEVC_SWREG35_SW_ENC_BITS_EST_BIAS_INTRA_CU_8_SHIFT (8U)
#define VPU_HEVC_SWREG35_SW_ENC_BITS_EST_BIAS_INTRA_CU_8(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG35_SW_ENC_BITS_EST_BIAS_INTRA_CU_8_SHIFT)) & VPU_HEVC_SWREG35_SW_ENC_BITS_EST_BIAS_INTRA_CU_8_MASK)

#define VPU_HEVC_SWREG35_SW_ENC_BITS_EST_TU_SPLIT_PENALTY_MASK (0x38000U)
#define VPU_HEVC_SWREG35_SW_ENC_BITS_EST_TU_SPLIT_PENALTY_SHIFT (15U)
#define VPU_HEVC_SWREG35_SW_ENC_BITS_EST_TU_SPLIT_PENALTY(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG35_SW_ENC_BITS_EST_TU_SPLIT_PENALTY_SHIFT)) & VPU_HEVC_SWREG35_SW_ENC_BITS_EST_TU_SPLIT_PENALTY_MASK)

#define VPU_HEVC_SWREG35_SW_ENC_LAMDA_MOTION_SSE_MASK (0xFFFC0000U)
#define VPU_HEVC_SWREG35_SW_ENC_LAMDA_MOTION_SSE_SHIFT (18U)
#define VPU_HEVC_SWREG35_SW_ENC_LAMDA_MOTION_SSE(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG35_SW_ENC_LAMDA_MOTION_SSE_SHIFT)) & VPU_HEVC_SWREG35_SW_ENC_LAMDA_MOTION_SSE_MASK)
/*! @} */

/*! @name SWREG36 - inter prediction parameters2 */
/*! @{ */

#define VPU_HEVC_SWREG36_SW_ENC_OUTPUT_BITWIDTH_CHROMA_MASK (0x3U)
#define VPU_HEVC_SWREG36_SW_ENC_OUTPUT_BITWIDTH_CHROMA_SHIFT (0U)
/*! SW_ENC_OUTPUT_BITWIDTH_CHROMA
 *  0b00..8 bit.
 *  0b01..9 bit.
 *  0b10..10 bit.
 */
#define VPU_HEVC_SWREG36_SW_ENC_OUTPUT_BITWIDTH_CHROMA(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG36_SW_ENC_OUTPUT_BITWIDTH_CHROMA_SHIFT)) & VPU_HEVC_SWREG36_SW_ENC_OUTPUT_BITWIDTH_CHROMA_MASK)

#define VPU_HEVC_SWREG36_SW_ENC_BITS_EST_1N_CU_PENALTY_MASK (0x3CU)
#define VPU_HEVC_SWREG36_SW_ENC_BITS_EST_1N_CU_PENALTY_SHIFT (2U)
#define VPU_HEVC_SWREG36_SW_ENC_BITS_EST_1N_CU_PENALTY(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG36_SW_ENC_BITS_EST_1N_CU_PENALTY_SHIFT)) & VPU_HEVC_SWREG36_SW_ENC_BITS_EST_1N_CU_PENALTY_MASK)

#define VPU_HEVC_SWREG36_SW_ENC_INTER_SKIP_BIAS_MASK (0x1FC0U)
#define VPU_HEVC_SWREG36_SW_ENC_INTER_SKIP_BIAS_SHIFT (6U)
#define VPU_HEVC_SWREG36_SW_ENC_INTER_SKIP_BIAS(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG36_SW_ENC_INTER_SKIP_BIAS_SHIFT)) & VPU_HEVC_SWREG36_SW_ENC_INTER_SKIP_BIAS_MASK)

#define VPU_HEVC_SWREG36_SW_ENC_BITS_EST_BIAS_INTRA_CU_64_MASK (0x7FE000U)
#define VPU_HEVC_SWREG36_SW_ENC_BITS_EST_BIAS_INTRA_CU_64_SHIFT (13U)
#define VPU_HEVC_SWREG36_SW_ENC_BITS_EST_BIAS_INTRA_CU_64(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG36_SW_ENC_BITS_EST_BIAS_INTRA_CU_64_SHIFT)) & VPU_HEVC_SWREG36_SW_ENC_BITS_EST_BIAS_INTRA_CU_64_MASK)

#define VPU_HEVC_SWREG36_SW_ENC_BITS_EST_BIAS_INTRA_CU_32_MASK (0xFF800000U)
#define VPU_HEVC_SWREG36_SW_ENC_BITS_EST_BIAS_INTRA_CU_32_SHIFT (23U)
#define VPU_HEVC_SWREG36_SW_ENC_BITS_EST_BIAS_INTRA_CU_32(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG36_SW_ENC_BITS_EST_BIAS_INTRA_CU_32_SHIFT)) & VPU_HEVC_SWREG36_SW_ENC_BITS_EST_BIAS_INTRA_CU_32_MASK)
/*! @} */

/*! @name SWREG37 - SAO lambda parameter */
/*! @{ */

#define VPU_HEVC_SWREG37_SW_ENC_CHROFFSET_MASK   (0xFU)
#define VPU_HEVC_SWREG37_SW_ENC_CHROFFSET_SHIFT  (0U)
#define VPU_HEVC_SWREG37_SW_ENC_CHROFFSET(x)     (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG37_SW_ENC_CHROFFSET_SHIFT)) & VPU_HEVC_SWREG37_SW_ENC_CHROFFSET_MASK)

#define VPU_HEVC_SWREG37_SW_ENC_LAMDA_SAO_LUMA_MASK (0x3FFF0U)
#define VPU_HEVC_SWREG37_SW_ENC_LAMDA_SAO_LUMA_SHIFT (4U)
#define VPU_HEVC_SWREG37_SW_ENC_LAMDA_SAO_LUMA(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG37_SW_ENC_LAMDA_SAO_LUMA_SHIFT)) & VPU_HEVC_SWREG37_SW_ENC_LAMDA_SAO_LUMA_MASK)

#define VPU_HEVC_SWREG37_SW_ENC_LAMDA_SAO_CHROMA_MASK (0xFFFC0000U)
#define VPU_HEVC_SWREG37_SW_ENC_LAMDA_SAO_CHROMA_SHIFT (18U)
#define VPU_HEVC_SWREG37_SW_ENC_LAMDA_SAO_CHROMA(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG37_SW_ENC_LAMDA_SAO_CHROMA_SHIFT)) & VPU_HEVC_SWREG37_SW_ENC_LAMDA_SAO_CHROMA_MASK)
/*! @} */

/*! @name SWREG38 - Pre-processor configuration */
/*! @{ */

#define VPU_HEVC_SWREG38_SW_ENC_MIRROR_MASK      (0x1U)
#define VPU_HEVC_SWREG38_SW_ENC_MIRROR_SHIFT     (0U)
#define VPU_HEVC_SWREG38_SW_ENC_MIRROR(x)        (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG38_SW_ENC_MIRROR_SHIFT)) & VPU_HEVC_SWREG38_SW_ENC_MIRROR_MASK)

#define VPU_HEVC_SWREG38_SW_ENC_YFILL_MASK       (0xEU)
#define VPU_HEVC_SWREG38_SW_ENC_YFILL_SHIFT      (1U)
#define VPU_HEVC_SWREG38_SW_ENC_YFILL(x)         (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG38_SW_ENC_YFILL_SHIFT)) & VPU_HEVC_SWREG38_SW_ENC_YFILL_MASK)

#define VPU_HEVC_SWREG38_SW_ENC_XFILL_MASK       (0x30U)
#define VPU_HEVC_SWREG38_SW_ENC_XFILL_SHIFT      (4U)
#define VPU_HEVC_SWREG38_SW_ENC_XFILL(x)         (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG38_SW_ENC_XFILL_SHIFT)) & VPU_HEVC_SWREG38_SW_ENC_XFILL_MASK)

#define VPU_HEVC_SWREG38_SW_ENC_ROWLENGTH_MASK   (0xFFFC0U)
#define VPU_HEVC_SWREG38_SW_ENC_ROWLENGTH_SHIFT  (6U)
#define VPU_HEVC_SWREG38_SW_ENC_ROWLENGTH(x)     (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG38_SW_ENC_ROWLENGTH_SHIFT)) & VPU_HEVC_SWREG38_SW_ENC_ROWLENGTH_MASK)

#define VPU_HEVC_SWREG38_SW_ENC_LUMOFFSET_MASK   (0xF00000U)
#define VPU_HEVC_SWREG38_SW_ENC_LUMOFFSET_SHIFT  (20U)
#define VPU_HEVC_SWREG38_SW_ENC_LUMOFFSET(x)     (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG38_SW_ENC_LUMOFFSET_SHIFT)) & VPU_HEVC_SWREG38_SW_ENC_LUMOFFSET_MASK)

#define VPU_HEVC_SWREG38_SW_ENC_OUTPUT_BITWIDTH_LUM_MASK (0x3000000U)
#define VPU_HEVC_SWREG38_SW_ENC_OUTPUT_BITWIDTH_LUM_SHIFT (24U)
/*! SW_ENC_OUTPUT_BITWIDTH_LUM
 *  0b00..8 bit.
 *  0b01..9 bit.
 *  0b10..10 bit.
 */
#define VPU_HEVC_SWREG38_SW_ENC_OUTPUT_BITWIDTH_LUM(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG38_SW_ENC_OUTPUT_BITWIDTH_LUM_SHIFT)) & VPU_HEVC_SWREG38_SW_ENC_OUTPUT_BITWIDTH_LUM_MASK)

#define VPU_HEVC_SWREG38_SW_ENC_INPUT_ROTATION_MASK (0xC000000U)
#define VPU_HEVC_SWREG38_SW_ENC_INPUT_ROTATION_SHIFT (26U)
/*! SW_ENC_INPUT_ROTATION
 *  0b00..disabled.
 *  0b01..90 degrees right.
 *  0b10..90 degrees left.
 *  0b11..180 degree right.
 */
#define VPU_HEVC_SWREG38_SW_ENC_INPUT_ROTATION(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG38_SW_ENC_INPUT_ROTATION_SHIFT)) & VPU_HEVC_SWREG38_SW_ENC_INPUT_ROTATION_MASK)

#define VPU_HEVC_SWREG38_SW_ENC_INPUT_FORMAT_MASK (0xF0000000U)
#define VPU_HEVC_SWREG38_SW_ENC_INPUT_FORMAT_SHIFT (28U)
/*! SW_ENC_INPUT_FORMAT
 *  0b0001..YUV420SP
 *  0b0010..YUYV422
 *  0b0011..UYVY422
 *  0b0100..RGB565
 *  0b0101..RGB555
 *  0b0110..RGB444
 *  0b0111..RGB888
 *  0b1000..RGB101010
 *  0b1001..I010
 *  0b1010..P010
 *  0b1011..PACKED10BITPLANAR
 *  0b1100..Y0L2
 *  0b1101..DAHUAHEVC
 *  0b1110..DAHUAH264
 */
#define VPU_HEVC_SWREG38_SW_ENC_INPUT_FORMAT(x)  (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG38_SW_ENC_INPUT_FORMAT_SHIFT)) & VPU_HEVC_SWREG38_SW_ENC_INPUT_FORMAT_MASK)
/*! @} */

/*! @name SWREG39 - Pre-processor color conversion parameters0 */
/*! @{ */

#define VPU_HEVC_SWREG39_SW_ENC_RGBCOEFFB_MASK   (0xFFFFU)
#define VPU_HEVC_SWREG39_SW_ENC_RGBCOEFFB_SHIFT  (0U)
#define VPU_HEVC_SWREG39_SW_ENC_RGBCOEFFB(x)     (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG39_SW_ENC_RGBCOEFFB_SHIFT)) & VPU_HEVC_SWREG39_SW_ENC_RGBCOEFFB_MASK)

#define VPU_HEVC_SWREG39_SW_ENC_RGBCOEFFA_MASK   (0xFFFF0000U)
#define VPU_HEVC_SWREG39_SW_ENC_RGBCOEFFA_SHIFT  (16U)
#define VPU_HEVC_SWREG39_SW_ENC_RGBCOEFFA(x)     (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG39_SW_ENC_RGBCOEFFA_SHIFT)) & VPU_HEVC_SWREG39_SW_ENC_RGBCOEFFA_MASK)
/*! @} */

/*! @name SWREG40 - Pre-processor color conversion parameters1 */
/*! @{ */

#define VPU_HEVC_SWREG40_SW_ENC_RGBCOEFFE_MASK   (0xFFFFU)
#define VPU_HEVC_SWREG40_SW_ENC_RGBCOEFFE_SHIFT  (0U)
#define VPU_HEVC_SWREG40_SW_ENC_RGBCOEFFE(x)     (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG40_SW_ENC_RGBCOEFFE_SHIFT)) & VPU_HEVC_SWREG40_SW_ENC_RGBCOEFFE_MASK)

#define VPU_HEVC_SWREG40_SW_ENC_RGBCOEFFC_MASK   (0xFFFF0000U)
#define VPU_HEVC_SWREG40_SW_ENC_RGBCOEFFC_SHIFT  (16U)
#define VPU_HEVC_SWREG40_SW_ENC_RGBCOEFFC(x)     (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG40_SW_ENC_RGBCOEFFC_SHIFT)) & VPU_HEVC_SWREG40_SW_ENC_RGBCOEFFC_MASK)
/*! @} */

/*! @name SWREG41 - Pre-processor color conversion parameters2 */
/*! @{ */

#define VPU_HEVC_SWREG41_SW_ENC_BMASKMSB_MASK    (0x3EU)
#define VPU_HEVC_SWREG41_SW_ENC_BMASKMSB_SHIFT   (1U)
#define VPU_HEVC_SWREG41_SW_ENC_BMASKMSB(x)      (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG41_SW_ENC_BMASKMSB_SHIFT)) & VPU_HEVC_SWREG41_SW_ENC_BMASKMSB_MASK)

#define VPU_HEVC_SWREG41_SW_ENC_GMASKMSB_MASK    (0x7C0U)
#define VPU_HEVC_SWREG41_SW_ENC_GMASKMSB_SHIFT   (6U)
#define VPU_HEVC_SWREG41_SW_ENC_GMASKMSB(x)      (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG41_SW_ENC_GMASKMSB_SHIFT)) & VPU_HEVC_SWREG41_SW_ENC_GMASKMSB_MASK)

#define VPU_HEVC_SWREG41_SW_ENC_RMASKMSB_MASK    (0xF800U)
#define VPU_HEVC_SWREG41_SW_ENC_RMASKMSB_SHIFT   (11U)
#define VPU_HEVC_SWREG41_SW_ENC_RMASKMSB(x)      (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG41_SW_ENC_RMASKMSB_SHIFT)) & VPU_HEVC_SWREG41_SW_ENC_RMASKMSB_MASK)

#define VPU_HEVC_SWREG41_SW_ENC_RGBCOEFFF_MASK   (0xFFFF0000U)
#define VPU_HEVC_SWREG41_SW_ENC_RGBCOEFFF_SHIFT  (16U)
#define VPU_HEVC_SWREG41_SW_ENC_RGBCOEFFF(x)     (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG41_SW_ENC_RGBCOEFFF_SHIFT)) & VPU_HEVC_SWREG41_SW_ENC_RGBCOEFFF_MASK)
/*! @} */

/*! @name SWREG42 - Pre-processor Base address for down-scaled output */
/*! @{ */

#define VPU_HEVC_SWREG42_SW_ENC_BASESCALEDOUTLUM_MASK (0xFFFFFFFFU)
#define VPU_HEVC_SWREG42_SW_ENC_BASESCALEDOUTLUM_SHIFT (0U)
#define VPU_HEVC_SWREG42_SW_ENC_BASESCALEDOUTLUM(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG42_SW_ENC_BASESCALEDOUTLUM_SHIFT)) & VPU_HEVC_SWREG42_SW_ENC_BASESCALEDOUTLUM_MASK)
/*! @} */

/*! @name SWREG43 - Pre-processor down-scaled configuration0 */
/*! @{ */

#define VPU_HEVC_SWREG43_SW_ENC_SCALE_MODE_MASK  (0x3U)
#define VPU_HEVC_SWREG43_SW_ENC_SCALE_MODE_SHIFT (0U)
/*! SW_ENC_SCALE_MODE
 *  0b00..disabled.
 *  0b01..scaling only.
 *  0b10..scale+encode
 */
#define VPU_HEVC_SWREG43_SW_ENC_SCALE_MODE(x)    (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG43_SW_ENC_SCALE_MODE_SHIFT)) & VPU_HEVC_SWREG43_SW_ENC_SCALE_MODE_MASK)

#define VPU_HEVC_SWREG43_SW_ENC_SCALEDOUTWIDTHMSB_MASK (0x4U)
#define VPU_HEVC_SWREG43_SW_ENC_SCALEDOUTWIDTHMSB_SHIFT (2U)
#define VPU_HEVC_SWREG43_SW_ENC_SCALEDOUTWIDTHMSB(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG43_SW_ENC_SCALEDOUTWIDTHMSB_SHIFT)) & VPU_HEVC_SWREG43_SW_ENC_SCALEDOUTWIDTHMSB_MASK)

#define VPU_HEVC_SWREG43_SW_ENC_SCALEDOUTWIDTHRATIO_MASK (0x7FFF8U)
#define VPU_HEVC_SWREG43_SW_ENC_SCALEDOUTWIDTHRATIO_SHIFT (3U)
#define VPU_HEVC_SWREG43_SW_ENC_SCALEDOUTWIDTHRATIO(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG43_SW_ENC_SCALEDOUTWIDTHRATIO_SHIFT)) & VPU_HEVC_SWREG43_SW_ENC_SCALEDOUTWIDTHRATIO_MASK)

#define VPU_HEVC_SWREG43_SW_ENC_SCALEDOUTWIDTH_MASK (0xFFF80000U)
#define VPU_HEVC_SWREG43_SW_ENC_SCALEDOUTWIDTH_SHIFT (19U)
#define VPU_HEVC_SWREG43_SW_ENC_SCALEDOUTWIDTH(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG43_SW_ENC_SCALEDOUTWIDTH_SHIFT)) & VPU_HEVC_SWREG43_SW_ENC_SCALEDOUTWIDTH_MASK)
/*! @} */

/*! @name SWREG44 - Pre-processor down-scaled configuration1 */
/*! @{ */

#define VPU_HEVC_SWREG44_SW_ENC_INPUT_FORMAT_MSB_MASK (0x3U)
#define VPU_HEVC_SWREG44_SW_ENC_INPUT_FORMAT_MSB_SHIFT (0U)
#define VPU_HEVC_SWREG44_SW_ENC_INPUT_FORMAT_MSB(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG44_SW_ENC_INPUT_FORMAT_MSB_SHIFT)) & VPU_HEVC_SWREG44_SW_ENC_INPUT_FORMAT_MSB_MASK)

#define VPU_HEVC_SWREG44_SW_ENC_SCALEDOUTHEIGHTRATIO_MASK (0x3FFFCU)
#define VPU_HEVC_SWREG44_SW_ENC_SCALEDOUTHEIGHTRATIO_SHIFT (2U)
#define VPU_HEVC_SWREG44_SW_ENC_SCALEDOUTHEIGHTRATIO(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG44_SW_ENC_SCALEDOUTHEIGHTRATIO_SHIFT)) & VPU_HEVC_SWREG44_SW_ENC_SCALEDOUTHEIGHTRATIO_MASK)

#define VPU_HEVC_SWREG44_SW_ENC_SCALEDOUTHEIGHT_MASK (0xFFFC0000U)
#define VPU_HEVC_SWREG44_SW_ENC_SCALEDOUTHEIGHT_SHIFT (18U)
#define VPU_HEVC_SWREG44_SW_ENC_SCALEDOUTHEIGHT(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG44_SW_ENC_SCALEDOUTHEIGHT_SHIFT)) & VPU_HEVC_SWREG44_SW_ENC_SCALEDOUTHEIGHT_MASK)
/*! @} */

/*! @name SWREG45 - Pre-processor down-scaled configuration2 */
/*! @{ */

#define VPU_HEVC_SWREG45_SW_ENC_SCALEDOUT_FORMAT_MASK (0x4U)
#define VPU_HEVC_SWREG45_SW_ENC_SCALEDOUT_FORMAT_SHIFT (2U)
#define VPU_HEVC_SWREG45_SW_ENC_SCALEDOUT_FORMAT(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG45_SW_ENC_SCALEDOUT_FORMAT_SHIFT)) & VPU_HEVC_SWREG45_SW_ENC_SCALEDOUT_FORMAT_MASK)

#define VPU_HEVC_SWREG45_SW_ENC_NALUNITSIZE_SWAP_MASK (0x78U)
#define VPU_HEVC_SWREG45_SW_ENC_NALUNITSIZE_SWAP_SHIFT (3U)
#define VPU_HEVC_SWREG45_SW_ENC_NALUNITSIZE_SWAP(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG45_SW_ENC_NALUNITSIZE_SWAP_SHIFT)) & VPU_HEVC_SWREG45_SW_ENC_NALUNITSIZE_SWAP_MASK)

#define VPU_HEVC_SWREG45_SW_ENC_SCALEDVERTICALCOPY_MASK (0x80U)
#define VPU_HEVC_SWREG45_SW_ENC_SCALEDVERTICALCOPY_SHIFT (7U)
#define VPU_HEVC_SWREG45_SW_ENC_SCALEDVERTICALCOPY(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG45_SW_ENC_SCALEDVERTICALCOPY_SHIFT)) & VPU_HEVC_SWREG45_SW_ENC_SCALEDVERTICALCOPY_MASK)

#define VPU_HEVC_SWREG45_SW_ENC_SCALEDHORIZONTALCOPY_MASK (0x100U)
#define VPU_HEVC_SWREG45_SW_ENC_SCALEDHORIZONTALCOPY_SHIFT (8U)
#define VPU_HEVC_SWREG45_SW_ENC_SCALEDHORIZONTALCOPY(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG45_SW_ENC_SCALEDHORIZONTALCOPY_SHIFT)) & VPU_HEVC_SWREG45_SW_ENC_SCALEDHORIZONTALCOPY_MASK)

#define VPU_HEVC_SWREG45_SW_ENC_VSCALE_WEIGHT_EN_MASK (0x200U)
#define VPU_HEVC_SWREG45_SW_ENC_VSCALE_WEIGHT_EN_SHIFT (9U)
#define VPU_HEVC_SWREG45_SW_ENC_VSCALE_WEIGHT_EN(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG45_SW_ENC_VSCALE_WEIGHT_EN_SHIFT)) & VPU_HEVC_SWREG45_SW_ENC_VSCALE_WEIGHT_EN_MASK)

#define VPU_HEVC_SWREG45_SW_ENC_SCALEDSKIPTOPPIXELROW_MASK (0xC00U)
#define VPU_HEVC_SWREG45_SW_ENC_SCALEDSKIPTOPPIXELROW_SHIFT (10U)
#define VPU_HEVC_SWREG45_SW_ENC_SCALEDSKIPTOPPIXELROW(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG45_SW_ENC_SCALEDSKIPTOPPIXELROW_SHIFT)) & VPU_HEVC_SWREG45_SW_ENC_SCALEDSKIPTOPPIXELROW_MASK)

#define VPU_HEVC_SWREG45_SW_ENC_SCALEDSKIPLEFTPIXELCOLUMN_MASK (0x3000U)
#define VPU_HEVC_SWREG45_SW_ENC_SCALEDSKIPLEFTPIXELCOLUMN_SHIFT (12U)
#define VPU_HEVC_SWREG45_SW_ENC_SCALEDSKIPLEFTPIXELCOLUMN(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG45_SW_ENC_SCALEDSKIPLEFTPIXELCOLUMN_SHIFT)) & VPU_HEVC_SWREG45_SW_ENC_SCALEDSKIPLEFTPIXELCOLUMN_MASK)

#define VPU_HEVC_SWREG45_SW_ENC_ENCODED_CTB_NUMBER_MASK (0x7FFC000U)
#define VPU_HEVC_SWREG45_SW_ENC_ENCODED_CTB_NUMBER_SHIFT (14U)
#define VPU_HEVC_SWREG45_SW_ENC_ENCODED_CTB_NUMBER(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG45_SW_ENC_ENCODED_CTB_NUMBER_SHIFT)) & VPU_HEVC_SWREG45_SW_ENC_ENCODED_CTB_NUMBER_MASK)

#define VPU_HEVC_SWREG45_SW_ENC_CHROMA_SWAP_MASK (0x8000000U)
#define VPU_HEVC_SWREG45_SW_ENC_CHROMA_SWAP_SHIFT (27U)
#define VPU_HEVC_SWREG45_SW_ENC_CHROMA_SWAP(x)   (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG45_SW_ENC_CHROMA_SWAP_SHIFT)) & VPU_HEVC_SWREG45_SW_ENC_CHROMA_SWAP_MASK)

#define VPU_HEVC_SWREG45_SW_ENC_SCALEDOUT_SWAP_MASK (0xF0000000U)
#define VPU_HEVC_SWREG45_SW_ENC_SCALEDOUT_SWAP_SHIFT (28U)
#define VPU_HEVC_SWREG45_SW_ENC_SCALEDOUT_SWAP(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG45_SW_ENC_SCALEDOUT_SWAP_SHIFT)) & VPU_HEVC_SWREG45_SW_ENC_SCALEDOUT_SWAP_MASK)
/*! @} */

/*! @name SWREG46 - compressed coefficients base address for SAN module. */
/*! @{ */

#define VPU_HEVC_SWREG46_SW_ENC_COMPRESSEDCOEFF_BASE_MASK (0xFFFFFFFFU)
#define VPU_HEVC_SWREG46_SW_ENC_COMPRESSEDCOEFF_BASE_SHIFT (0U)
#define VPU_HEVC_SWREG46_SW_ENC_COMPRESSEDCOEFF_BASE(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG46_SW_ENC_COMPRESSEDCOEFF_BASE_SHIFT)) & VPU_HEVC_SWREG46_SW_ENC_COMPRESSEDCOEFF_BASE_MASK)
/*! @} */

/*! @name SWREG60 - Base address for recon luma compress table LSB. */
/*! @{ */

#define VPU_HEVC_SWREG60_SW_ENC_RECON_LUMA_COMPRESS_TABLE_BASE_MASK (0xFFFFFFFFU)
#define VPU_HEVC_SWREG60_SW_ENC_RECON_LUMA_COMPRESS_TABLE_BASE_SHIFT (0U)
#define VPU_HEVC_SWREG60_SW_ENC_RECON_LUMA_COMPRESS_TABLE_BASE(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG60_SW_ENC_RECON_LUMA_COMPRESS_TABLE_BASE_SHIFT)) & VPU_HEVC_SWREG60_SW_ENC_RECON_LUMA_COMPRESS_TABLE_BASE_MASK)
/*! @} */

/*! @name SWREG62 - Base address for recon Chroma compress table LSB */
/*! @{ */

#define VPU_HEVC_SWREG62_SW_ENC_RECON_CHROMA_COMPRESS_TABLE_BASE_MASK (0xFFFFFFFFU)
#define VPU_HEVC_SWREG62_SW_ENC_RECON_CHROMA_COMPRESS_TABLE_BASE_SHIFT (0U)
#define VPU_HEVC_SWREG62_SW_ENC_RECON_CHROMA_COMPRESS_TABLE_BASE(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG62_SW_ENC_RECON_CHROMA_COMPRESS_TABLE_BASE_SHIFT)) & VPU_HEVC_SWREG62_SW_ENC_RECON_CHROMA_COMPRESS_TABLE_BASE_MASK)
/*! @} */

/*! @name SWREG64 - Base address for list 0 ref 0 luma compress table LSB. */
/*! @{ */

#define VPU_HEVC_SWREG64_SW_ENC_L0_REF0_LUMA_COMPRESS_TABLE_BASE_MASK (0xFFFFFFFFU)
#define VPU_HEVC_SWREG64_SW_ENC_L0_REF0_LUMA_COMPRESS_TABLE_BASE_SHIFT (0U)
#define VPU_HEVC_SWREG64_SW_ENC_L0_REF0_LUMA_COMPRESS_TABLE_BASE(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG64_SW_ENC_L0_REF0_LUMA_COMPRESS_TABLE_BASE_SHIFT)) & VPU_HEVC_SWREG64_SW_ENC_L0_REF0_LUMA_COMPRESS_TABLE_BASE_MASK)
/*! @} */

/*! @name SWREG66 - Base address for list 0 ref 0 Chroma compress table LSB. */
/*! @{ */

#define VPU_HEVC_SWREG66_SW_ENC_L0_REF0_CHROMA_COMPRESS_TABLE_BASE_MASK (0xFFFFFFFFU)
#define VPU_HEVC_SWREG66_SW_ENC_L0_REF0_CHROMA_COMPRESS_TABLE_BASE_SHIFT (0U)
#define VPU_HEVC_SWREG66_SW_ENC_L0_REF0_CHROMA_COMPRESS_TABLE_BASE(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG66_SW_ENC_L0_REF0_CHROMA_COMPRESS_TABLE_BASE_SHIFT)) & VPU_HEVC_SWREG66_SW_ENC_L0_REF0_CHROMA_COMPRESS_TABLE_BASE_MASK)
/*! @} */

/*! @name SWREG72 - Base address for recon luma 4n base LSB. */
/*! @{ */

#define VPU_HEVC_SWREG72_SW_ENC_RECON_LUMA_4N_BASE_MASK (0xFFFFFFFFU)
#define VPU_HEVC_SWREG72_SW_ENC_RECON_LUMA_4N_BASE_SHIFT (0U)
#define VPU_HEVC_SWREG72_SW_ENC_RECON_LUMA_4N_BASE(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG72_SW_ENC_RECON_LUMA_4N_BASE_SHIFT)) & VPU_HEVC_SWREG72_SW_ENC_RECON_LUMA_4N_BASE_MASK)
/*! @} */

/*! @name SWREG74 - reference picture reconstructed list0 4n 0 */
/*! @{ */

#define VPU_HEVC_SWREG74_SW_ENC_REFPIC_RECON_L0_4N0_BASE_MASK (0xFFFFFFFFU)
#define VPU_HEVC_SWREG74_SW_ENC_REFPIC_RECON_L0_4N0_BASE_SHIFT (0U)
#define VPU_HEVC_SWREG74_SW_ENC_REFPIC_RECON_L0_4N0_BASE(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG74_SW_ENC_REFPIC_RECON_L0_4N0_BASE_SHIFT)) & VPU_HEVC_SWREG74_SW_ENC_REFPIC_RECON_L0_4N0_BASE_MASK)
/*! @} */

/*! @name SWREG78_H2V5 - inter me SATD lambda config 7. For H2V5 or later version. */
/*! @{ */

#define VPU_HEVC_SWREG78_H2V5_SW_ENC_LAMDA_SATD_ME_15_EXPAND5BIT_MASK (0x7FFC0U)
#define VPU_HEVC_SWREG78_H2V5_SW_ENC_LAMDA_SATD_ME_15_EXPAND5BIT_SHIFT (6U)
#define VPU_HEVC_SWREG78_H2V5_SW_ENC_LAMDA_SATD_ME_15_EXPAND5BIT(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG78_H2V5_SW_ENC_LAMDA_SATD_ME_15_EXPAND5BIT_SHIFT)) & VPU_HEVC_SWREG78_H2V5_SW_ENC_LAMDA_SATD_ME_15_EXPAND5BIT_MASK)

#define VPU_HEVC_SWREG78_H2V5_SW_ENC_LAMDA_SATD_ME_14_EXPAND5BIT_MASK (0xFFF80000U)
#define VPU_HEVC_SWREG78_H2V5_SW_ENC_LAMDA_SATD_ME_14_EXPAND5BIT_SHIFT (19U)
#define VPU_HEVC_SWREG78_H2V5_SW_ENC_LAMDA_SATD_ME_14_EXPAND5BIT(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG78_H2V5_SW_ENC_LAMDA_SATD_ME_14_EXPAND5BIT_SHIFT)) & VPU_HEVC_SWREG78_H2V5_SW_ENC_LAMDA_SATD_ME_14_EXPAND5BIT_MASK)
/*! @} */

/*! @name SWREG79_H2V5 - inter me SSE lambda config 0. For H2V5 or later version. */
/*! @{ */

#define VPU_HEVC_SWREG79_H2V5_SW_ENC_LAMDA_SSE_ME_0_EXPAND6BIT_MASK (0xFFFFF800U)
#define VPU_HEVC_SWREG79_H2V5_SW_ENC_LAMDA_SSE_ME_0_EXPAND6BIT_SHIFT (11U)
#define VPU_HEVC_SWREG79_H2V5_SW_ENC_LAMDA_SSE_ME_0_EXPAND6BIT(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG79_H2V5_SW_ENC_LAMDA_SSE_ME_0_EXPAND6BIT_SHIFT)) & VPU_HEVC_SWREG79_H2V5_SW_ENC_LAMDA_SSE_ME_0_EXPAND6BIT_MASK)
/*! @} */

/*! @name SWREG81 - hardware configuation 0 */
/*! @{ */

#define VPU_HEVC_SWREG81_SW_TIMEOUT_CYCLES_MASK  (0x7FFFFFU)
#define VPU_HEVC_SWREG81_SW_TIMEOUT_CYCLES_SHIFT (0U)
#define VPU_HEVC_SWREG81_SW_TIMEOUT_CYCLES(x)    (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG81_SW_TIMEOUT_CYCLES_SHIFT)) & VPU_HEVC_SWREG81_SW_TIMEOUT_CYCLES_MASK)

#define VPU_HEVC_SWREG81_SW_TIMEOUT_OVERRIDE_E_MASK (0x800000U)
#define VPU_HEVC_SWREG81_SW_TIMEOUT_OVERRIDE_E_SHIFT (23U)
#define VPU_HEVC_SWREG81_SW_TIMEOUT_OVERRIDE_E(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG81_SW_TIMEOUT_OVERRIDE_E_SHIFT)) & VPU_HEVC_SWREG81_SW_TIMEOUT_OVERRIDE_E_MASK)

#define VPU_HEVC_SWREG81_SW_ENC_MAX_BURST_MASK   (0xFF000000U)
#define VPU_HEVC_SWREG81_SW_ENC_MAX_BURST_SHIFT  (24U)
#define VPU_HEVC_SWREG81_SW_ENC_MAX_BURST(x)     (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG81_SW_ENC_MAX_BURST_SHIFT)) & VPU_HEVC_SWREG81_SW_ENC_MAX_BURST_MASK)
/*! @} */

/*! @name SWREG82 - record hardware performance */
/*! @{ */

#define VPU_HEVC_SWREG82_SW_ENC_HW_PERFORMANCE_MASK (0xFFFFFFFFU)
#define VPU_HEVC_SWREG82_SW_ENC_HW_PERFORMANCE_SHIFT (0U)
#define VPU_HEVC_SWREG82_SW_ENC_HW_PERFORMANCE(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG82_SW_ENC_HW_PERFORMANCE_SHIFT)) & VPU_HEVC_SWREG82_SW_ENC_HW_PERFORMANCE_MASK)
/*! @} */

/*! @name SWREG83 - reference picture reconstructed list1 luma0 */
/*! @{ */

#define VPU_HEVC_SWREG83_SW_ENC_REFPIC_RECON_L1_Y0_MASK (0xFFFFFFFFU)
#define VPU_HEVC_SWREG83_SW_ENC_REFPIC_RECON_L1_Y0_SHIFT (0U)
#define VPU_HEVC_SWREG83_SW_ENC_REFPIC_RECON_L1_Y0(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG83_SW_ENC_REFPIC_RECON_L1_Y0_SHIFT)) & VPU_HEVC_SWREG83_SW_ENC_REFPIC_RECON_L1_Y0_MASK)
/*! @} */

/*! @name SWREG84 - reference picture reconstructed list1 chroma0 */
/*! @{ */

#define VPU_HEVC_SWREG84_SW_ENC_REFPIC_RECON_L1_CHROMA0_MASK (0xFFFFFFFFU)
#define VPU_HEVC_SWREG84_SW_ENC_REFPIC_RECON_L1_CHROMA0_SHIFT (0U)
#define VPU_HEVC_SWREG84_SW_ENC_REFPIC_RECON_L1_CHROMA0(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG84_SW_ENC_REFPIC_RECON_L1_CHROMA0_SHIFT)) & VPU_HEVC_SWREG84_SW_ENC_REFPIC_RECON_L1_CHROMA0_MASK)
/*! @} */

/*! @name SWREG91 - reference pictures list1 config */
/*! @{ */

#define VPU_HEVC_SWREG91_SW_ENC_L1_REF0_CHROMA_COMPRESSOR_ENABLE_MASK (0x4U)
#define VPU_HEVC_SWREG91_SW_ENC_L1_REF0_CHROMA_COMPRESSOR_ENABLE_SHIFT (2U)
/*! SW_ENC_L1_REF0_CHROMA_COMPRESSOR_ENABLE
 *  0b0..disable
 *  0b1..enable.
 */
#define VPU_HEVC_SWREG91_SW_ENC_L1_REF0_CHROMA_COMPRESSOR_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG91_SW_ENC_L1_REF0_CHROMA_COMPRESSOR_ENABLE_SHIFT)) & VPU_HEVC_SWREG91_SW_ENC_L1_REF0_CHROMA_COMPRESSOR_ENABLE_MASK)

#define VPU_HEVC_SWREG91_SW_ENC_L1_REF0_LUMA_COMPRESSOR_ENABLE_MASK (0x8U)
#define VPU_HEVC_SWREG91_SW_ENC_L1_REF0_LUMA_COMPRESSOR_ENABLE_SHIFT (3U)
/*! SW_ENC_L1_REF0_LUMA_COMPRESSOR_ENABLE
 *  0b0..disable
 *  0b1..enable.
 */
#define VPU_HEVC_SWREG91_SW_ENC_L1_REF0_LUMA_COMPRESSOR_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG91_SW_ENC_L1_REF0_LUMA_COMPRESSOR_ENABLE_SHIFT)) & VPU_HEVC_SWREG91_SW_ENC_L1_REF0_LUMA_COMPRESSOR_ENABLE_MASK)

#define VPU_HEVC_SWREG91_SW_ENC_LONG_TERM_REF_PICS_PRESENT_FLAG_MASK (0x10U)
#define VPU_HEVC_SWREG91_SW_ENC_LONG_TERM_REF_PICS_PRESENT_FLAG_SHIFT (4U)
#define VPU_HEVC_SWREG91_SW_ENC_LONG_TERM_REF_PICS_PRESENT_FLAG(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG91_SW_ENC_LONG_TERM_REF_PICS_PRESENT_FLAG_SHIFT)) & VPU_HEVC_SWREG91_SW_ENC_LONG_TERM_REF_PICS_PRESENT_FLAG_MASK)

#define VPU_HEVC_SWREG91_SW_ENC_ACTIVE_L1_CNT_MASK (0xC0U)
#define VPU_HEVC_SWREG91_SW_ENC_ACTIVE_L1_CNT_SHIFT (6U)
#define VPU_HEVC_SWREG91_SW_ENC_ACTIVE_L1_CNT(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG91_SW_ENC_ACTIVE_L1_CNT_SHIFT)) & VPU_HEVC_SWREG91_SW_ENC_ACTIVE_L1_CNT_MASK)

#define VPU_HEVC_SWREG91_SW_ENC_L1_USED_BY_CURR_PIC1_MASK (0x100U)
#define VPU_HEVC_SWREG91_SW_ENC_L1_USED_BY_CURR_PIC1_SHIFT (8U)
#define VPU_HEVC_SWREG91_SW_ENC_L1_USED_BY_CURR_PIC1(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG91_SW_ENC_L1_USED_BY_CURR_PIC1_SHIFT)) & VPU_HEVC_SWREG91_SW_ENC_L1_USED_BY_CURR_PIC1_MASK)

#define VPU_HEVC_SWREG91_SW_ENC_L1_LONG_TERM_FLAG1_MASK (0x200U)
#define VPU_HEVC_SWREG91_SW_ENC_L1_LONG_TERM_FLAG1_SHIFT (9U)
#define VPU_HEVC_SWREG91_SW_ENC_L1_LONG_TERM_FLAG1(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG91_SW_ENC_L1_LONG_TERM_FLAG1_SHIFT)) & VPU_HEVC_SWREG91_SW_ENC_L1_LONG_TERM_FLAG1_MASK)

#define VPU_HEVC_SWREG91_SW_ENC_L1_DELTA_POC1_MASK (0xFFC00U)
#define VPU_HEVC_SWREG91_SW_ENC_L1_DELTA_POC1_SHIFT (10U)
#define VPU_HEVC_SWREG91_SW_ENC_L1_DELTA_POC1(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG91_SW_ENC_L1_DELTA_POC1_SHIFT)) & VPU_HEVC_SWREG91_SW_ENC_L1_DELTA_POC1_MASK)

#define VPU_HEVC_SWREG91_SW_ENC_L1_USED_BY_CURR_PIC0_MASK (0x100000U)
#define VPU_HEVC_SWREG91_SW_ENC_L1_USED_BY_CURR_PIC0_SHIFT (20U)
#define VPU_HEVC_SWREG91_SW_ENC_L1_USED_BY_CURR_PIC0(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG91_SW_ENC_L1_USED_BY_CURR_PIC0_SHIFT)) & VPU_HEVC_SWREG91_SW_ENC_L1_USED_BY_CURR_PIC0_MASK)

#define VPU_HEVC_SWREG91_SW_ENC_L1_LONG_TERM_FLAG0_MASK (0x200000U)
#define VPU_HEVC_SWREG91_SW_ENC_L1_LONG_TERM_FLAG0_SHIFT (21U)
#define VPU_HEVC_SWREG91_SW_ENC_L1_LONG_TERM_FLAG0(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG91_SW_ENC_L1_LONG_TERM_FLAG0_SHIFT)) & VPU_HEVC_SWREG91_SW_ENC_L1_LONG_TERM_FLAG0_MASK)

#define VPU_HEVC_SWREG91_SW_ENC_L1_DELTA_POC0_MASK (0xFFC00000U)
#define VPU_HEVC_SWREG91_SW_ENC_L1_DELTA_POC0_SHIFT (22U)
#define VPU_HEVC_SWREG91_SW_ENC_L1_DELTA_POC0(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG91_SW_ENC_L1_DELTA_POC0_SHIFT)) & VPU_HEVC_SWREG91_SW_ENC_L1_DELTA_POC0_MASK)
/*! @} */

/*! @name SWREG92 - reference picture reconstructed list1 4n 0 */
/*! @{ */

#define VPU_HEVC_SWREG92_SW_ENC_REFPIC_RECON_L1_4N0_BASE_MASK (0xFFFFFFFFU)
#define VPU_HEVC_SWREG92_SW_ENC_REFPIC_RECON_L1_4N0_BASE_SHIFT (0U)
#define VPU_HEVC_SWREG92_SW_ENC_REFPIC_RECON_L1_4N0_BASE(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG92_SW_ENC_REFPIC_RECON_L1_4N0_BASE_SHIFT)) & VPU_HEVC_SWREG92_SW_ENC_REFPIC_RECON_L1_4N0_BASE_MASK)
/*! @} */

/*! @name SWREG96 - Base address for list 1 ref 0 luma compress table LSB. */
/*! @{ */

#define VPU_HEVC_SWREG96_SW_ENC_L1_REF0_LUMA_COMPRESS_TABLE_BASE_MASK (0xFFFFFFFFU)
#define VPU_HEVC_SWREG96_SW_ENC_L1_REF0_LUMA_COMPRESS_TABLE_BASE_SHIFT (0U)
#define VPU_HEVC_SWREG96_SW_ENC_L1_REF0_LUMA_COMPRESS_TABLE_BASE(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG96_SW_ENC_L1_REF0_LUMA_COMPRESS_TABLE_BASE_SHIFT)) & VPU_HEVC_SWREG96_SW_ENC_L1_REF0_LUMA_COMPRESS_TABLE_BASE_MASK)
/*! @} */

/*! @name SWREG98 - Base address for list 1 ref 0 Chroma compress table LSB. */
/*! @{ */

#define VPU_HEVC_SWREG98_SW_ENC_L1_REF0_CHROMA_COMPRESS_TABLE_BASE_MASK (0xFFFFFFFFU)
#define VPU_HEVC_SWREG98_SW_ENC_L1_REF0_CHROMA_COMPRESS_TABLE_BASE_SHIFT (0U)
#define VPU_HEVC_SWREG98_SW_ENC_L1_REF0_CHROMA_COMPRESS_TABLE_BASE(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG98_SW_ENC_L1_REF0_CHROMA_COMPRESS_TABLE_BASE_SHIFT)) & VPU_HEVC_SWREG98_SW_ENC_L1_REF0_CHROMA_COMPRESS_TABLE_BASE_MASK)
/*! @} */

/*! @name SWREG104 - reference picture lists modification */
/*! @{ */

#define VPU_HEVC_SWREG104_SW_ENC_REF_PIC_LIST_MODI_FLAG_L0_MASK (0x1U)
#define VPU_HEVC_SWREG104_SW_ENC_REF_PIC_LIST_MODI_FLAG_L0_SHIFT (0U)
#define VPU_HEVC_SWREG104_SW_ENC_REF_PIC_LIST_MODI_FLAG_L0(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG104_SW_ENC_REF_PIC_LIST_MODI_FLAG_L0_SHIFT)) & VPU_HEVC_SWREG104_SW_ENC_REF_PIC_LIST_MODI_FLAG_L0_MASK)

#define VPU_HEVC_SWREG104_SW_ENC_LIST_ENTRY_L0_PIC0_MASK (0x1EU)
#define VPU_HEVC_SWREG104_SW_ENC_LIST_ENTRY_L0_PIC0_SHIFT (1U)
#define VPU_HEVC_SWREG104_SW_ENC_LIST_ENTRY_L0_PIC0(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG104_SW_ENC_LIST_ENTRY_L0_PIC0_SHIFT)) & VPU_HEVC_SWREG104_SW_ENC_LIST_ENTRY_L0_PIC0_MASK)

#define VPU_HEVC_SWREG104_SW_ENC_REF_PIC_LIST_MODI_FLAG_L1_MASK (0x10000U)
#define VPU_HEVC_SWREG104_SW_ENC_REF_PIC_LIST_MODI_FLAG_L1_SHIFT (16U)
#define VPU_HEVC_SWREG104_SW_ENC_REF_PIC_LIST_MODI_FLAG_L1(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG104_SW_ENC_REF_PIC_LIST_MODI_FLAG_L1_SHIFT)) & VPU_HEVC_SWREG104_SW_ENC_REF_PIC_LIST_MODI_FLAG_L1_MASK)

#define VPU_HEVC_SWREG104_SW_ENC_LIST_ENTRY_L1_PIC0_MASK (0x1E0000U)
#define VPU_HEVC_SWREG104_SW_ENC_LIST_ENTRY_L1_PIC0_SHIFT (17U)
#define VPU_HEVC_SWREG104_SW_ENC_LIST_ENTRY_L1_PIC0(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG104_SW_ENC_LIST_ENTRY_L1_PIC0_SHIFT)) & VPU_HEVC_SWREG104_SW_ENC_LIST_ENTRY_L1_PIC0_MASK)

#define VPU_HEVC_SWREG104_SW_ENC_RDO_LEVEL_MASK  (0x60000000U)
#define VPU_HEVC_SWREG104_SW_ENC_RDO_LEVEL_SHIFT (29U)
#define VPU_HEVC_SWREG104_SW_ENC_RDO_LEVEL(x)    (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG104_SW_ENC_RDO_LEVEL_SHIFT)) & VPU_HEVC_SWREG104_SW_ENC_RDO_LEVEL_MASK)

#define VPU_HEVC_SWREG104_SW_ENC_LISTS_MODI_PRESENT_FLAG_MASK (0x80000000U)
#define VPU_HEVC_SWREG104_SW_ENC_LISTS_MODI_PRESENT_FLAG_SHIFT (31U)
#define VPU_HEVC_SWREG104_SW_ENC_LISTS_MODI_PRESENT_FLAG(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG104_SW_ENC_LISTS_MODI_PRESENT_FLAG_SHIFT)) & VPU_HEVC_SWREG104_SW_ENC_LISTS_MODI_PRESENT_FLAG_MASK)
/*! @} */

/*! @name SWREG106 - Min picture size */
/*! @{ */

#define VPU_HEVC_SWREG106_SW_ENC_MINPICSIZE_MASK (0xFFFFFFFFU)
#define VPU_HEVC_SWREG106_SW_ENC_MINPICSIZE_SHIFT (0U)
#define VPU_HEVC_SWREG106_SW_ENC_MINPICSIZE(x)   (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG106_SW_ENC_MINPICSIZE_SHIFT)) & VPU_HEVC_SWREG106_SW_ENC_MINPICSIZE_MASK)
/*! @} */

/*! @name SWREG107 - Max picture size */
/*! @{ */

#define VPU_HEVC_SWREG107_SW_ENC_MAXPICSIZE_MASK (0xFFFFFFFFU)
#define VPU_HEVC_SWREG107_SW_ENC_MAXPICSIZE_SHIFT (0U)
#define VPU_HEVC_SWREG107_SW_ENC_MAXPICSIZE(x)   (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG107_SW_ENC_MAXPICSIZE_SHIFT)) & VPU_HEVC_SWREG107_SW_ENC_MAXPICSIZE_MASK)
/*! @} */

/*! @name SWREG109 - Qp delta map */
/*! @{ */

#define VPU_HEVC_SWREG109_SW_ENC_ROIMAPDELTAQPADDR_MASK (0xFFFFFFFFU)
#define VPU_HEVC_SWREG109_SW_ENC_ROIMAPDELTAQPADDR_SHIFT (0U)
#define VPU_HEVC_SWREG109_SW_ENC_ROIMAPDELTAQPADDR(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG109_SW_ENC_ROIMAPDELTAQPADDR_SHIFT)) & VPU_HEVC_SWREG109_SW_ENC_ROIMAPDELTAQPADDR_MASK)
/*! @} */

/*! @name SWREG111 - adaptive GOP configuration1 */
/*! @{ */

#define VPU_HEVC_SWREG111_SW_ENC_INTRACU8NUM_MASK (0xFFFFF000U)
#define VPU_HEVC_SWREG111_SW_ENC_INTRACU8NUM_SHIFT (12U)
#define VPU_HEVC_SWREG111_SW_ENC_INTRACU8NUM(x)  (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG111_SW_ENC_INTRACU8NUM_SHIFT)) & VPU_HEVC_SWREG111_SW_ENC_INTRACU8NUM_MASK)
/*! @} */

/*! @name SWREG112 - adaptive GOP configuration2 */
/*! @{ */

#define VPU_HEVC_SWREG112_SW_ENC_SKIPCU8NUM_MASK (0xFFFFF000U)
#define VPU_HEVC_SWREG112_SW_ENC_SKIPCU8NUM_SHIFT (12U)
#define VPU_HEVC_SWREG112_SW_ENC_SKIPCU8NUM(x)   (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG112_SW_ENC_SKIPCU8NUM_SHIFT)) & VPU_HEVC_SWREG112_SW_ENC_SKIPCU8NUM_MASK)
/*! @} */

/*! @name SWREG113 - adaptive GOP configuration3 */
/*! @{ */

#define VPU_HEVC_SWREG113_SW_ENC_PBFRAME4NRDCOST_MASK (0xFFFFFFFFU)
#define VPU_HEVC_SWREG113_SW_ENC_PBFRAME4NRDCOST_SHIFT (0U)
#define VPU_HEVC_SWREG113_SW_ENC_PBFRAME4NRDCOST(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG113_SW_ENC_PBFRAME4NRDCOST_SHIFT)) & VPU_HEVC_SWREG113_SW_ENC_PBFRAME4NRDCOST_MASK)
/*! @} */

/*! @name SWREG119 - min/max lcu bits number of last picture */
/*! @{ */

#define VPU_HEVC_SWREG119_SW_ENC_CTBBITSMAX_MASK (0xFFFFU)
#define VPU_HEVC_SWREG119_SW_ENC_CTBBITSMAX_SHIFT (0U)
#define VPU_HEVC_SWREG119_SW_ENC_CTBBITSMAX(x)   (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG119_SW_ENC_CTBBITSMAX_SHIFT)) & VPU_HEVC_SWREG119_SW_ENC_CTBBITSMAX_MASK)

#define VPU_HEVC_SWREG119_SW_ENC_CTBBITSMIN_MASK (0xFFFF0000U)
#define VPU_HEVC_SWREG119_SW_ENC_CTBBITSMIN_SHIFT (16U)
#define VPU_HEVC_SWREG119_SW_ENC_CTBBITSMIN(x)   (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG119_SW_ENC_CTBBITSMIN_SHIFT)) & VPU_HEVC_SWREG119_SW_ENC_CTBBITSMIN_MASK)
/*! @} */

/*! @name SWREG120 - total bits number of all lcus of last picture not including slice header bits */
/*! @{ */

#define VPU_HEVC_SWREG120_SW_ENC_TOTALLCUBITS_MASK (0xFFFFFFFFU)
#define VPU_HEVC_SWREG120_SW_ENC_TOTALLCUBITS_SHIFT (0U)
#define VPU_HEVC_SWREG120_SW_ENC_TOTALLCUBITS(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG120_SW_ENC_TOTALLCUBITS_SHIFT)) & VPU_HEVC_SWREG120_SW_ENC_TOTALLCUBITS_MASK)
/*! @} */

/*! @name SWREG122_H2V5 - inter me SSE lambda config 1. For H2V5 or later version. */
/*! @{ */

#define VPU_HEVC_SWREG122_H2V5_SW_ENC_LAMDA_SSE_ME_1_EXPAND6BIT_MASK (0xFFFFF800U)
#define VPU_HEVC_SWREG122_H2V5_SW_ENC_LAMDA_SSE_ME_1_EXPAND6BIT_SHIFT (11U)
#define VPU_HEVC_SWREG122_H2V5_SW_ENC_LAMDA_SSE_ME_1_EXPAND6BIT(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG122_H2V5_SW_ENC_LAMDA_SSE_ME_1_EXPAND6BIT_SHIFT)) & VPU_HEVC_SWREG122_H2V5_SW_ENC_LAMDA_SSE_ME_1_EXPAND6BIT_MASK)
/*! @} */

/*! @name SWREG123_H2V5 - inter me SSE lambda config 2. For H2V5 or later version. */
/*! @{ */

#define VPU_HEVC_SWREG123_H2V5_SW_ENC_LAMDA_SSE_ME_2_EXPAND6BIT_MASK (0xFFFFF800U)
#define VPU_HEVC_SWREG123_H2V5_SW_ENC_LAMDA_SSE_ME_2_EXPAND6BIT_SHIFT (11U)
#define VPU_HEVC_SWREG123_H2V5_SW_ENC_LAMDA_SSE_ME_2_EXPAND6BIT(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG123_H2V5_SW_ENC_LAMDA_SSE_ME_2_EXPAND6BIT_SHIFT)) & VPU_HEVC_SWREG123_H2V5_SW_ENC_LAMDA_SSE_ME_2_EXPAND6BIT_MASK)
/*! @} */

/*! @name SWREG124_H2V5 - inter me SSE lambda config 3. For H2V5 or later version. */
/*! @{ */

#define VPU_HEVC_SWREG124_H2V5_SW_ENC_LAMDA_SSE_ME_3_EXPAND6BIT_MASK (0xFFFFF800U)
#define VPU_HEVC_SWREG124_H2V5_SW_ENC_LAMDA_SSE_ME_3_EXPAND6BIT_SHIFT (11U)
#define VPU_HEVC_SWREG124_H2V5_SW_ENC_LAMDA_SSE_ME_3_EXPAND6BIT(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG124_H2V5_SW_ENC_LAMDA_SSE_ME_3_EXPAND6BIT_SHIFT)) & VPU_HEVC_SWREG124_H2V5_SW_ENC_LAMDA_SSE_ME_3_EXPAND6BIT_MASK)
/*! @} */

/*! @name SWREG125 - intra SATD lambda config 0 */
/*! @{ */

#define VPU_HEVC_SWREG125_SW_ENC_INTRA_SATD_LAMDA_1_MASK (0x3FFF0U)
#define VPU_HEVC_SWREG125_SW_ENC_INTRA_SATD_LAMDA_1_SHIFT (4U)
#define VPU_HEVC_SWREG125_SW_ENC_INTRA_SATD_LAMDA_1(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG125_SW_ENC_INTRA_SATD_LAMDA_1_SHIFT)) & VPU_HEVC_SWREG125_SW_ENC_INTRA_SATD_LAMDA_1_MASK)

#define VPU_HEVC_SWREG125_SW_ENC_INTRA_SATD_LAMDA_0_MASK (0xFFFC0000U)
#define VPU_HEVC_SWREG125_SW_ENC_INTRA_SATD_LAMDA_0_SHIFT (18U)
#define VPU_HEVC_SWREG125_SW_ENC_INTRA_SATD_LAMDA_0(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG125_SW_ENC_INTRA_SATD_LAMDA_0_SHIFT)) & VPU_HEVC_SWREG125_SW_ENC_INTRA_SATD_LAMDA_0_MASK)
/*! @} */

/*! @name SWREG126 - intra SATD lambda config 1 */
/*! @{ */

#define VPU_HEVC_SWREG126_SW_ENC_INTRA_SATD_LAMDA_3_MASK (0x3FFF0U)
#define VPU_HEVC_SWREG126_SW_ENC_INTRA_SATD_LAMDA_3_SHIFT (4U)
#define VPU_HEVC_SWREG126_SW_ENC_INTRA_SATD_LAMDA_3(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG126_SW_ENC_INTRA_SATD_LAMDA_3_SHIFT)) & VPU_HEVC_SWREG126_SW_ENC_INTRA_SATD_LAMDA_3_MASK)

#define VPU_HEVC_SWREG126_SW_ENC_INTRA_SATD_LAMDA_2_MASK (0xFFFC0000U)
#define VPU_HEVC_SWREG126_SW_ENC_INTRA_SATD_LAMDA_2_SHIFT (18U)
#define VPU_HEVC_SWREG126_SW_ENC_INTRA_SATD_LAMDA_2(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG126_SW_ENC_INTRA_SATD_LAMDA_2_SHIFT)) & VPU_HEVC_SWREG126_SW_ENC_INTRA_SATD_LAMDA_2_MASK)
/*! @} */

/*! @name SWREG127 - intra SATD lambda config 2 */
/*! @{ */

#define VPU_HEVC_SWREG127_SW_ENC_INTRA_SATD_LAMDA_5_MASK (0x3FFF0U)
#define VPU_HEVC_SWREG127_SW_ENC_INTRA_SATD_LAMDA_5_SHIFT (4U)
#define VPU_HEVC_SWREG127_SW_ENC_INTRA_SATD_LAMDA_5(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG127_SW_ENC_INTRA_SATD_LAMDA_5_SHIFT)) & VPU_HEVC_SWREG127_SW_ENC_INTRA_SATD_LAMDA_5_MASK)

#define VPU_HEVC_SWREG127_SW_ENC_INTRA_SATD_LAMDA_4_MASK (0xFFFC0000U)
#define VPU_HEVC_SWREG127_SW_ENC_INTRA_SATD_LAMDA_4_SHIFT (18U)
#define VPU_HEVC_SWREG127_SW_ENC_INTRA_SATD_LAMDA_4(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG127_SW_ENC_INTRA_SATD_LAMDA_4_SHIFT)) & VPU_HEVC_SWREG127_SW_ENC_INTRA_SATD_LAMDA_4_MASK)
/*! @} */

/*! @name SWREG128 - intra SATD lambda config 3 */
/*! @{ */

#define VPU_HEVC_SWREG128_SW_ENC_INTRA_SATD_LAMDA_7_MASK (0x3FFF0U)
#define VPU_HEVC_SWREG128_SW_ENC_INTRA_SATD_LAMDA_7_SHIFT (4U)
#define VPU_HEVC_SWREG128_SW_ENC_INTRA_SATD_LAMDA_7(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG128_SW_ENC_INTRA_SATD_LAMDA_7_SHIFT)) & VPU_HEVC_SWREG128_SW_ENC_INTRA_SATD_LAMDA_7_MASK)

#define VPU_HEVC_SWREG128_SW_ENC_INTRA_SATD_LAMDA_6_MASK (0xFFFC0000U)
#define VPU_HEVC_SWREG128_SW_ENC_INTRA_SATD_LAMDA_6_SHIFT (18U)
#define VPU_HEVC_SWREG128_SW_ENC_INTRA_SATD_LAMDA_6(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG128_SW_ENC_INTRA_SATD_LAMDA_6_SHIFT)) & VPU_HEVC_SWREG128_SW_ENC_INTRA_SATD_LAMDA_6_MASK)
/*! @} */

/*! @name SWREG129 - intra SATD lambda config 4 */
/*! @{ */

#define VPU_HEVC_SWREG129_SW_ENC_INTRA_SATD_LAMDA_9_MASK (0x3FFF0U)
#define VPU_HEVC_SWREG129_SW_ENC_INTRA_SATD_LAMDA_9_SHIFT (4U)
#define VPU_HEVC_SWREG129_SW_ENC_INTRA_SATD_LAMDA_9(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG129_SW_ENC_INTRA_SATD_LAMDA_9_SHIFT)) & VPU_HEVC_SWREG129_SW_ENC_INTRA_SATD_LAMDA_9_MASK)

#define VPU_HEVC_SWREG129_SW_ENC_INTRA_SATD_LAMDA_8_MASK (0xFFFC0000U)
#define VPU_HEVC_SWREG129_SW_ENC_INTRA_SATD_LAMDA_8_SHIFT (18U)
#define VPU_HEVC_SWREG129_SW_ENC_INTRA_SATD_LAMDA_8(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG129_SW_ENC_INTRA_SATD_LAMDA_8_SHIFT)) & VPU_HEVC_SWREG129_SW_ENC_INTRA_SATD_LAMDA_8_MASK)
/*! @} */

/*! @name SWREG130 - intra SATD lambda config 5 */
/*! @{ */

#define VPU_HEVC_SWREG130_SW_ENC_INTRA_SATD_LAMDA_11_MASK (0x3FFF0U)
#define VPU_HEVC_SWREG130_SW_ENC_INTRA_SATD_LAMDA_11_SHIFT (4U)
#define VPU_HEVC_SWREG130_SW_ENC_INTRA_SATD_LAMDA_11(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG130_SW_ENC_INTRA_SATD_LAMDA_11_SHIFT)) & VPU_HEVC_SWREG130_SW_ENC_INTRA_SATD_LAMDA_11_MASK)

#define VPU_HEVC_SWREG130_SW_ENC_INTRA_SATD_LAMDA_10_MASK (0xFFFC0000U)
#define VPU_HEVC_SWREG130_SW_ENC_INTRA_SATD_LAMDA_10_SHIFT (18U)
#define VPU_HEVC_SWREG130_SW_ENC_INTRA_SATD_LAMDA_10(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG130_SW_ENC_INTRA_SATD_LAMDA_10_SHIFT)) & VPU_HEVC_SWREG130_SW_ENC_INTRA_SATD_LAMDA_10_MASK)
/*! @} */

/*! @name SWREG131 - intra SATD lambda config 6 */
/*! @{ */

#define VPU_HEVC_SWREG131_SW_ENC_INTRA_SATD_LAMDA_13_MASK (0x3FFF0U)
#define VPU_HEVC_SWREG131_SW_ENC_INTRA_SATD_LAMDA_13_SHIFT (4U)
#define VPU_HEVC_SWREG131_SW_ENC_INTRA_SATD_LAMDA_13(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG131_SW_ENC_INTRA_SATD_LAMDA_13_SHIFT)) & VPU_HEVC_SWREG131_SW_ENC_INTRA_SATD_LAMDA_13_MASK)

#define VPU_HEVC_SWREG131_SW_ENC_INTRA_SATD_LAMDA_12_MASK (0xFFFC0000U)
#define VPU_HEVC_SWREG131_SW_ENC_INTRA_SATD_LAMDA_12_SHIFT (18U)
#define VPU_HEVC_SWREG131_SW_ENC_INTRA_SATD_LAMDA_12(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG131_SW_ENC_INTRA_SATD_LAMDA_12_SHIFT)) & VPU_HEVC_SWREG131_SW_ENC_INTRA_SATD_LAMDA_12_MASK)
/*! @} */

/*! @name SWREG132 - intra SATD lambda config 7 */
/*! @{ */

#define VPU_HEVC_SWREG132_SW_ENC_INTRA_SATD_LAMDA_15_MASK (0x3FFF0U)
#define VPU_HEVC_SWREG132_SW_ENC_INTRA_SATD_LAMDA_15_SHIFT (4U)
#define VPU_HEVC_SWREG132_SW_ENC_INTRA_SATD_LAMDA_15(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG132_SW_ENC_INTRA_SATD_LAMDA_15_SHIFT)) & VPU_HEVC_SWREG132_SW_ENC_INTRA_SATD_LAMDA_15_MASK)

#define VPU_HEVC_SWREG132_SW_ENC_INTRA_SATD_LAMDA_14_MASK (0xFFFC0000U)
#define VPU_HEVC_SWREG132_SW_ENC_INTRA_SATD_LAMDA_14_SHIFT (18U)
#define VPU_HEVC_SWREG132_SW_ENC_INTRA_SATD_LAMDA_14(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG132_SW_ENC_INTRA_SATD_LAMDA_14_SHIFT)) & VPU_HEVC_SWREG132_SW_ENC_INTRA_SATD_LAMDA_14_MASK)
/*! @} */

/*! @name SWREG133 - SSE devide 256 */
/*! @{ */

#define VPU_HEVC_SWREG133_SW_ENC_SSE_DIV_256_MASK (0xFFFFFFFFU)
#define VPU_HEVC_SWREG133_SW_ENC_SSE_DIV_256_SHIFT (0U)
#define VPU_HEVC_SWREG133_SW_ENC_SSE_DIV_256(x)  (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG133_SW_ENC_SSE_DIV_256_SHIFT)) & VPU_HEVC_SWREG133_SW_ENC_SSE_DIV_256_MASK)
/*! @} */

/*! @name SWREG134 - noise reduction */
/*! @{ */

#define VPU_HEVC_SWREG134_SW_ENC_NR_MBNUM_INVERT_REG_MASK (0xFFFFU)
#define VPU_HEVC_SWREG134_SW_ENC_NR_MBNUM_INVERT_REG_SHIFT (0U)
#define VPU_HEVC_SWREG134_SW_ENC_NR_MBNUM_INVERT_REG(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG134_SW_ENC_NR_MBNUM_INVERT_REG_SHIFT)) & VPU_HEVC_SWREG134_SW_ENC_NR_MBNUM_INVERT_REG_MASK)

#define VPU_HEVC_SWREG134_SW_ENC_NOISE_LOW_MASK  (0x3F000000U)
#define VPU_HEVC_SWREG134_SW_ENC_NOISE_LOW_SHIFT (24U)
#define VPU_HEVC_SWREG134_SW_ENC_NOISE_LOW(x)    (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG134_SW_ENC_NOISE_LOW_SHIFT)) & VPU_HEVC_SWREG134_SW_ENC_NOISE_LOW_MASK)

#define VPU_HEVC_SWREG134_SW_ENC_NOISE_REDUCTION_ENABLE_MASK (0xC0000000U)
#define VPU_HEVC_SWREG134_SW_ENC_NOISE_REDUCTION_ENABLE_SHIFT (30U)
#define VPU_HEVC_SWREG134_SW_ENC_NOISE_REDUCTION_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG134_SW_ENC_NOISE_REDUCTION_ENABLE_SHIFT)) & VPU_HEVC_SWREG134_SW_ENC_NOISE_REDUCTION_ENABLE_MASK)
/*! @} */

/*! @name SWREG135 - noise reduction 1 */
/*! @{ */

#define VPU_HEVC_SWREG135_SW_ENC_THRESH_SIGMA_CUR_MASK (0x3FFFFE0U)
#define VPU_HEVC_SWREG135_SW_ENC_THRESH_SIGMA_CUR_SHIFT (5U)
#define VPU_HEVC_SWREG135_SW_ENC_THRESH_SIGMA_CUR(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG135_SW_ENC_THRESH_SIGMA_CUR_SHIFT)) & VPU_HEVC_SWREG135_SW_ENC_THRESH_SIGMA_CUR_MASK)

#define VPU_HEVC_SWREG135_SW_ENC_SLICEQP_PREV_MASK (0xFC000000U)
#define VPU_HEVC_SWREG135_SW_ENC_SLICEQP_PREV_SHIFT (26U)
#define VPU_HEVC_SWREG135_SW_ENC_SLICEQP_PREV(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG135_SW_ENC_SLICEQP_PREV_SHIFT)) & VPU_HEVC_SWREG135_SW_ENC_SLICEQP_PREV_MASK)
/*! @} */

/*! @name SWREG136 - noise reduction 2 */
/*! @{ */

#define VPU_HEVC_SWREG136_SW_ENC_FRAME_SIGMA_CALCED_MASK (0xFFFFU)
#define VPU_HEVC_SWREG136_SW_ENC_FRAME_SIGMA_CALCED_SHIFT (0U)
#define VPU_HEVC_SWREG136_SW_ENC_FRAME_SIGMA_CALCED(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG136_SW_ENC_FRAME_SIGMA_CALCED_SHIFT)) & VPU_HEVC_SWREG136_SW_ENC_FRAME_SIGMA_CALCED_MASK)

#define VPU_HEVC_SWREG136_SW_ENC_SIGMA_CUR_MASK  (0xFFFF0000U)
#define VPU_HEVC_SWREG136_SW_ENC_SIGMA_CUR_SHIFT (16U)
#define VPU_HEVC_SWREG136_SW_ENC_SIGMA_CUR(x)    (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG136_SW_ENC_SIGMA_CUR_SHIFT)) & VPU_HEVC_SWREG136_SW_ENC_SIGMA_CUR_MASK)
/*! @} */

/*! @name SWREG137 - noise reduction 3 */
/*! @{ */

#define VPU_HEVC_SWREG137_SW_ENC_THRESH_SIGMA_CALCED_MASK (0xFFFFF800U)
#define VPU_HEVC_SWREG137_SW_ENC_THRESH_SIGMA_CALCED_SHIFT (11U)
#define VPU_HEVC_SWREG137_SW_ENC_THRESH_SIGMA_CALCED(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG137_SW_ENC_THRESH_SIGMA_CALCED_SHIFT)) & VPU_HEVC_SWREG137_SW_ENC_THRESH_SIGMA_CALCED_MASK)
/*! @} */

/*! @name SWREG138_H2V5 - inter me SSE lambda config 4. For H2V5 or later version. */
/*! @{ */

#define VPU_HEVC_SWREG138_H2V5_SW_ENC_LAMDA_SSE_ME_4_EXPAND6BIT_MASK (0xFFFFF800U)
#define VPU_HEVC_SWREG138_H2V5_SW_ENC_LAMDA_SSE_ME_4_EXPAND6BIT_SHIFT (11U)
#define VPU_HEVC_SWREG138_H2V5_SW_ENC_LAMDA_SSE_ME_4_EXPAND6BIT(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG138_H2V5_SW_ENC_LAMDA_SSE_ME_4_EXPAND6BIT_SHIFT)) & VPU_HEVC_SWREG138_H2V5_SW_ENC_LAMDA_SSE_ME_4_EXPAND6BIT_MASK)
/*! @} */

/*! @name SWREG139_H2V5 - inter me SSE lambda config 5. For H2V5 or later version. */
/*! @{ */

#define VPU_HEVC_SWREG139_H2V5_SW_ENC_LAMDA_SSE_ME_5_EXPAND6BIT_MASK (0xFFFFF800U)
#define VPU_HEVC_SWREG139_H2V5_SW_ENC_LAMDA_SSE_ME_5_EXPAND6BIT_SHIFT (11U)
#define VPU_HEVC_SWREG139_H2V5_SW_ENC_LAMDA_SSE_ME_5_EXPAND6BIT(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG139_H2V5_SW_ENC_LAMDA_SSE_ME_5_EXPAND6BIT_SHIFT)) & VPU_HEVC_SWREG139_H2V5_SW_ENC_LAMDA_SSE_ME_5_EXPAND6BIT_MASK)
/*! @} */

/*! @name SWREG140_H2V5 - inter me SSE lambda config 6. For H2V5 or later version. */
/*! @{ */

#define VPU_HEVC_SWREG140_H2V5_SW_ENC_LAMDA_SSE_ME_6_EXPAND6BIT_MASK (0xFFFFF800U)
#define VPU_HEVC_SWREG140_H2V5_SW_ENC_LAMDA_SSE_ME_6_EXPAND6BIT_SHIFT (11U)
#define VPU_HEVC_SWREG140_H2V5_SW_ENC_LAMDA_SSE_ME_6_EXPAND6BIT(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG140_H2V5_SW_ENC_LAMDA_SSE_ME_6_EXPAND6BIT_SHIFT)) & VPU_HEVC_SWREG140_H2V5_SW_ENC_LAMDA_SSE_ME_6_EXPAND6BIT_MASK)
/*! @} */

/*! @name SWREG141_H2V5 - inter me SSE lambda config 7. For H2V5 or later version. */
/*! @{ */

#define VPU_HEVC_SWREG141_H2V5_SW_ENC_LAMDA_SSE_ME_7_EXPAND6BIT_MASK (0xFFFFF800U)
#define VPU_HEVC_SWREG141_H2V5_SW_ENC_LAMDA_SSE_ME_7_EXPAND6BIT_SHIFT (11U)
#define VPU_HEVC_SWREG141_H2V5_SW_ENC_LAMDA_SSE_ME_7_EXPAND6BIT(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG141_H2V5_SW_ENC_LAMDA_SSE_ME_7_EXPAND6BIT_SHIFT)) & VPU_HEVC_SWREG141_H2V5_SW_ENC_LAMDA_SSE_ME_7_EXPAND6BIT_MASK)
/*! @} */

/*! @name SWREG142_H2V5 - inter me SSE lambda config 8. For H2V5 or later version. */
/*! @{ */

#define VPU_HEVC_SWREG142_H2V5_SW_ENC_LAMDA_SSE_ME_8_EXPAND6BIT_MASK (0xFFFFF800U)
#define VPU_HEVC_SWREG142_H2V5_SW_ENC_LAMDA_SSE_ME_8_EXPAND6BIT_SHIFT (11U)
#define VPU_HEVC_SWREG142_H2V5_SW_ENC_LAMDA_SSE_ME_8_EXPAND6BIT(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG142_H2V5_SW_ENC_LAMDA_SSE_ME_8_EXPAND6BIT_SHIFT)) & VPU_HEVC_SWREG142_H2V5_SW_ENC_LAMDA_SSE_ME_8_EXPAND6BIT_MASK)
/*! @} */

/*! @name SWREG143_H2V5 - inter me SSE lambda config 9. For H2V5 or later version. */
/*! @{ */

#define VPU_HEVC_SWREG143_H2V5_SW_ENC_LAMDA_SSE_ME_9_EXPAND6BIT_MASK (0xFFFFF800U)
#define VPU_HEVC_SWREG143_H2V5_SW_ENC_LAMDA_SSE_ME_9_EXPAND6BIT_SHIFT (11U)
#define VPU_HEVC_SWREG143_H2V5_SW_ENC_LAMDA_SSE_ME_9_EXPAND6BIT(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG143_H2V5_SW_ENC_LAMDA_SSE_ME_9_EXPAND6BIT_SHIFT)) & VPU_HEVC_SWREG143_H2V5_SW_ENC_LAMDA_SSE_ME_9_EXPAND6BIT_MASK)
/*! @} */

/*! @name SWREG144_H2V5 - inter me SSE lambda config 10. For H2V5 or later version. */
/*! @{ */

#define VPU_HEVC_SWREG144_H2V5_SW_ENC_LAMDA_SSE_ME_10_EXPAND6BIT_MASK (0xFFFFF800U)
#define VPU_HEVC_SWREG144_H2V5_SW_ENC_LAMDA_SSE_ME_10_EXPAND6BIT_SHIFT (11U)
#define VPU_HEVC_SWREG144_H2V5_SW_ENC_LAMDA_SSE_ME_10_EXPAND6BIT(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG144_H2V5_SW_ENC_LAMDA_SSE_ME_10_EXPAND6BIT_SHIFT)) & VPU_HEVC_SWREG144_H2V5_SW_ENC_LAMDA_SSE_ME_10_EXPAND6BIT_MASK)
/*! @} */

/*! @name SWREG145_H2V5 - inter me SSE lambda config 11. For H2V5 or later version. */
/*! @{ */

#define VPU_HEVC_SWREG145_H2V5_SW_ENC_LAMDA_SSE_ME_11_EXPAND6BIT_MASK (0xFFFFF800U)
#define VPU_HEVC_SWREG145_H2V5_SW_ENC_LAMDA_SSE_ME_11_EXPAND6BIT_SHIFT (11U)
#define VPU_HEVC_SWREG145_H2V5_SW_ENC_LAMDA_SSE_ME_11_EXPAND6BIT(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG145_H2V5_SW_ENC_LAMDA_SSE_ME_11_EXPAND6BIT_SHIFT)) & VPU_HEVC_SWREG145_H2V5_SW_ENC_LAMDA_SSE_ME_11_EXPAND6BIT_MASK)
/*! @} */

/*! @name SWREG146_H2V5 - inter me SSE lambda config 12. For H2V5 or later version. */
/*! @{ */

#define VPU_HEVC_SWREG146_H2V5_SW_ENC_LAMDA_SSE_ME_12_EXPAND6BIT_MASK (0xFFFFF800U)
#define VPU_HEVC_SWREG146_H2V5_SW_ENC_LAMDA_SSE_ME_12_EXPAND6BIT_SHIFT (11U)
#define VPU_HEVC_SWREG146_H2V5_SW_ENC_LAMDA_SSE_ME_12_EXPAND6BIT(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG146_H2V5_SW_ENC_LAMDA_SSE_ME_12_EXPAND6BIT_SHIFT)) & VPU_HEVC_SWREG146_H2V5_SW_ENC_LAMDA_SSE_ME_12_EXPAND6BIT_MASK)
/*! @} */

/*! @name SWREG147_H2V5 - inter me SSE lambda config 13. For H2V5 or later version. */
/*! @{ */

#define VPU_HEVC_SWREG147_H2V5_SW_ENC_LAMDA_SSE_ME_13_EXPAND6BIT_MASK (0xFFFFF800U)
#define VPU_HEVC_SWREG147_H2V5_SW_ENC_LAMDA_SSE_ME_13_EXPAND6BIT_SHIFT (11U)
#define VPU_HEVC_SWREG147_H2V5_SW_ENC_LAMDA_SSE_ME_13_EXPAND6BIT(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG147_H2V5_SW_ENC_LAMDA_SSE_ME_13_EXPAND6BIT_SHIFT)) & VPU_HEVC_SWREG147_H2V5_SW_ENC_LAMDA_SSE_ME_13_EXPAND6BIT_MASK)
/*! @} */

/*! @name SWREG148_H2V5 - inter me SSE lambda config 14. For H2V5 or later version. */
/*! @{ */

#define VPU_HEVC_SWREG148_H2V5_SW_ENC_LAMDA_SSE_ME_14_EXPAND6BIT_MASK (0xFFFFF800U)
#define VPU_HEVC_SWREG148_H2V5_SW_ENC_LAMDA_SSE_ME_14_EXPAND6BIT_SHIFT (11U)
#define VPU_HEVC_SWREG148_H2V5_SW_ENC_LAMDA_SSE_ME_14_EXPAND6BIT(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG148_H2V5_SW_ENC_LAMDA_SSE_ME_14_EXPAND6BIT_SHIFT)) & VPU_HEVC_SWREG148_H2V5_SW_ENC_LAMDA_SSE_ME_14_EXPAND6BIT_MASK)
/*! @} */

/*! @name SWREG149_H2V5 - inter me SSE lambda config 15. For H2V5 or later version. */
/*! @{ */

#define VPU_HEVC_SWREG149_H2V5_SW_ENC_LAMDA_SSE_ME_15_EXPAND6BIT_MASK (0xFFFFF800U)
#define VPU_HEVC_SWREG149_H2V5_SW_ENC_LAMDA_SSE_ME_15_EXPAND6BIT_SHIFT (11U)
#define VPU_HEVC_SWREG149_H2V5_SW_ENC_LAMDA_SSE_ME_15_EXPAND6BIT(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG149_H2V5_SW_ENC_LAMDA_SSE_ME_15_EXPAND6BIT_SHIFT)) & VPU_HEVC_SWREG149_H2V5_SW_ENC_LAMDA_SSE_ME_15_EXPAND6BIT_MASK)
/*! @} */

/*! @name SWREG150 - inter me SATD lambda config 8 */
/*! @{ */

#define VPU_HEVC_SWREG150_SW_ENC_LAMDA_SATD_ME_17_MASK (0x7FFC0U)
#define VPU_HEVC_SWREG150_SW_ENC_LAMDA_SATD_ME_17_SHIFT (6U)
#define VPU_HEVC_SWREG150_SW_ENC_LAMDA_SATD_ME_17(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG150_SW_ENC_LAMDA_SATD_ME_17_SHIFT)) & VPU_HEVC_SWREG150_SW_ENC_LAMDA_SATD_ME_17_MASK)

#define VPU_HEVC_SWREG150_SW_ENC_LAMDA_SATD_ME_16_MASK (0xFFF80000U)
#define VPU_HEVC_SWREG150_SW_ENC_LAMDA_SATD_ME_16_SHIFT (19U)
#define VPU_HEVC_SWREG150_SW_ENC_LAMDA_SATD_ME_16(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG150_SW_ENC_LAMDA_SATD_ME_16_SHIFT)) & VPU_HEVC_SWREG150_SW_ENC_LAMDA_SATD_ME_16_MASK)
/*! @} */

/*! @name SWREG151 - inter me SATD lambda config 9 */
/*! @{ */

#define VPU_HEVC_SWREG151_SW_ENC_LAMDA_SATD_ME_19_MASK (0x7FFC0U)
#define VPU_HEVC_SWREG151_SW_ENC_LAMDA_SATD_ME_19_SHIFT (6U)
#define VPU_HEVC_SWREG151_SW_ENC_LAMDA_SATD_ME_19(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG151_SW_ENC_LAMDA_SATD_ME_19_SHIFT)) & VPU_HEVC_SWREG151_SW_ENC_LAMDA_SATD_ME_19_MASK)

#define VPU_HEVC_SWREG151_SW_ENC_LAMDA_SATD_ME_18_MASK (0xFFF80000U)
#define VPU_HEVC_SWREG151_SW_ENC_LAMDA_SATD_ME_18_SHIFT (19U)
#define VPU_HEVC_SWREG151_SW_ENC_LAMDA_SATD_ME_18(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG151_SW_ENC_LAMDA_SATD_ME_18_SHIFT)) & VPU_HEVC_SWREG151_SW_ENC_LAMDA_SATD_ME_18_MASK)
/*! @} */

/*! @name SWREG152 - inter me SATD lambda config 10 */
/*! @{ */

#define VPU_HEVC_SWREG152_SW_ENC_LAMDA_SATD_ME_21_MASK (0x7FFC0U)
#define VPU_HEVC_SWREG152_SW_ENC_LAMDA_SATD_ME_21_SHIFT (6U)
#define VPU_HEVC_SWREG152_SW_ENC_LAMDA_SATD_ME_21(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG152_SW_ENC_LAMDA_SATD_ME_21_SHIFT)) & VPU_HEVC_SWREG152_SW_ENC_LAMDA_SATD_ME_21_MASK)

#define VPU_HEVC_SWREG152_SW_ENC_LAMDA_SATD_ME_20_MASK (0xFFF80000U)
#define VPU_HEVC_SWREG152_SW_ENC_LAMDA_SATD_ME_20_SHIFT (19U)
#define VPU_HEVC_SWREG152_SW_ENC_LAMDA_SATD_ME_20(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG152_SW_ENC_LAMDA_SATD_ME_20_SHIFT)) & VPU_HEVC_SWREG152_SW_ENC_LAMDA_SATD_ME_20_MASK)
/*! @} */

/*! @name SWREG153 - inter me SATD lambda config 11 */
/*! @{ */

#define VPU_HEVC_SWREG153_SW_ENC_LAMDA_SATD_ME_23_MASK (0x7FFC0U)
#define VPU_HEVC_SWREG153_SW_ENC_LAMDA_SATD_ME_23_SHIFT (6U)
#define VPU_HEVC_SWREG153_SW_ENC_LAMDA_SATD_ME_23(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG153_SW_ENC_LAMDA_SATD_ME_23_SHIFT)) & VPU_HEVC_SWREG153_SW_ENC_LAMDA_SATD_ME_23_MASK)

#define VPU_HEVC_SWREG153_SW_ENC_LAMDA_SATD_ME_22_MASK (0xFFF80000U)
#define VPU_HEVC_SWREG153_SW_ENC_LAMDA_SATD_ME_22_SHIFT (19U)
#define VPU_HEVC_SWREG153_SW_ENC_LAMDA_SATD_ME_22(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG153_SW_ENC_LAMDA_SATD_ME_22_SHIFT)) & VPU_HEVC_SWREG153_SW_ENC_LAMDA_SATD_ME_22_MASK)
/*! @} */

/*! @name SWREG154 - inter me SATD lambda config 12 */
/*! @{ */

#define VPU_HEVC_SWREG154_SW_ENC_LAMDA_SATD_ME_25_MASK (0x7FFC0U)
#define VPU_HEVC_SWREG154_SW_ENC_LAMDA_SATD_ME_25_SHIFT (6U)
#define VPU_HEVC_SWREG154_SW_ENC_LAMDA_SATD_ME_25(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG154_SW_ENC_LAMDA_SATD_ME_25_SHIFT)) & VPU_HEVC_SWREG154_SW_ENC_LAMDA_SATD_ME_25_MASK)

#define VPU_HEVC_SWREG154_SW_ENC_LAMDA_SATD_ME_24_MASK (0xFFF80000U)
#define VPU_HEVC_SWREG154_SW_ENC_LAMDA_SATD_ME_24_SHIFT (19U)
#define VPU_HEVC_SWREG154_SW_ENC_LAMDA_SATD_ME_24(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG154_SW_ENC_LAMDA_SATD_ME_24_SHIFT)) & VPU_HEVC_SWREG154_SW_ENC_LAMDA_SATD_ME_24_MASK)
/*! @} */

/*! @name SWREG155 - inter me SATD lambda config 13 */
/*! @{ */

#define VPU_HEVC_SWREG155_SW_ENC_LAMDA_SATD_ME_27_MASK (0x7FFC0U)
#define VPU_HEVC_SWREG155_SW_ENC_LAMDA_SATD_ME_27_SHIFT (6U)
#define VPU_HEVC_SWREG155_SW_ENC_LAMDA_SATD_ME_27(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG155_SW_ENC_LAMDA_SATD_ME_27_SHIFT)) & VPU_HEVC_SWREG155_SW_ENC_LAMDA_SATD_ME_27_MASK)

#define VPU_HEVC_SWREG155_SW_ENC_LAMDA_SATD_ME_26_MASK (0xFFF80000U)
#define VPU_HEVC_SWREG155_SW_ENC_LAMDA_SATD_ME_26_SHIFT (19U)
#define VPU_HEVC_SWREG155_SW_ENC_LAMDA_SATD_ME_26(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG155_SW_ENC_LAMDA_SATD_ME_26_SHIFT)) & VPU_HEVC_SWREG155_SW_ENC_LAMDA_SATD_ME_26_MASK)
/*! @} */

/*! @name SWREG156 - inter me SATD lambda config 14 */
/*! @{ */

#define VPU_HEVC_SWREG156_SW_ENC_LAMDA_SATD_ME_29_MASK (0x7FFC0U)
#define VPU_HEVC_SWREG156_SW_ENC_LAMDA_SATD_ME_29_SHIFT (6U)
#define VPU_HEVC_SWREG156_SW_ENC_LAMDA_SATD_ME_29(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG156_SW_ENC_LAMDA_SATD_ME_29_SHIFT)) & VPU_HEVC_SWREG156_SW_ENC_LAMDA_SATD_ME_29_MASK)

#define VPU_HEVC_SWREG156_SW_ENC_LAMDA_SATD_ME_28_MASK (0xFFF80000U)
#define VPU_HEVC_SWREG156_SW_ENC_LAMDA_SATD_ME_28_SHIFT (19U)
#define VPU_HEVC_SWREG156_SW_ENC_LAMDA_SATD_ME_28(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG156_SW_ENC_LAMDA_SATD_ME_28_SHIFT)) & VPU_HEVC_SWREG156_SW_ENC_LAMDA_SATD_ME_28_MASK)
/*! @} */

/*! @name SWREG157 - inter me SATD lambda config 15 */
/*! @{ */

#define VPU_HEVC_SWREG157_SW_ENC_LAMDA_SATD_ME_31_MASK (0x7FFC0U)
#define VPU_HEVC_SWREG157_SW_ENC_LAMDA_SATD_ME_31_SHIFT (6U)
#define VPU_HEVC_SWREG157_SW_ENC_LAMDA_SATD_ME_31(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG157_SW_ENC_LAMDA_SATD_ME_31_SHIFT)) & VPU_HEVC_SWREG157_SW_ENC_LAMDA_SATD_ME_31_MASK)

#define VPU_HEVC_SWREG157_SW_ENC_LAMDA_SATD_ME_30_MASK (0xFFF80000U)
#define VPU_HEVC_SWREG157_SW_ENC_LAMDA_SATD_ME_30_SHIFT (19U)
#define VPU_HEVC_SWREG157_SW_ENC_LAMDA_SATD_ME_30(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG157_SW_ENC_LAMDA_SATD_ME_30_SHIFT)) & VPU_HEVC_SWREG157_SW_ENC_LAMDA_SATD_ME_30_MASK)
/*! @} */

/*! @name SWREG158 - inter me SSE lambda config 16 */
/*! @{ */

#define VPU_HEVC_SWREG158_SW_ENC_LAMDA_SSE_ME_16_MASK (0xFFFFF800U)
#define VPU_HEVC_SWREG158_SW_ENC_LAMDA_SSE_ME_16_SHIFT (11U)
#define VPU_HEVC_SWREG158_SW_ENC_LAMDA_SSE_ME_16(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG158_SW_ENC_LAMDA_SSE_ME_16_SHIFT)) & VPU_HEVC_SWREG158_SW_ENC_LAMDA_SSE_ME_16_MASK)
/*! @} */

/*! @name SWREG159 - inter me SSE lambda config 17 */
/*! @{ */

#define VPU_HEVC_SWREG159_SW_ENC_LAMDA_SSE_ME_17_MASK (0xFFFFF800U)
#define VPU_HEVC_SWREG159_SW_ENC_LAMDA_SSE_ME_17_SHIFT (11U)
#define VPU_HEVC_SWREG159_SW_ENC_LAMDA_SSE_ME_17(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG159_SW_ENC_LAMDA_SSE_ME_17_SHIFT)) & VPU_HEVC_SWREG159_SW_ENC_LAMDA_SSE_ME_17_MASK)
/*! @} */

/*! @name SWREG160 - inter me SSE lambda config 18 */
/*! @{ */

#define VPU_HEVC_SWREG160_SW_ENC_LAMDA_SSE_ME_18_MASK (0xFFFFF800U)
#define VPU_HEVC_SWREG160_SW_ENC_LAMDA_SSE_ME_18_SHIFT (11U)
#define VPU_HEVC_SWREG160_SW_ENC_LAMDA_SSE_ME_18(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG160_SW_ENC_LAMDA_SSE_ME_18_SHIFT)) & VPU_HEVC_SWREG160_SW_ENC_LAMDA_SSE_ME_18_MASK)
/*! @} */

/*! @name SWREG161 - inter me SSE lambda config 19 */
/*! @{ */

#define VPU_HEVC_SWREG161_SW_ENC_LAMDA_SSE_ME_19_MASK (0xFFFFF800U)
#define VPU_HEVC_SWREG161_SW_ENC_LAMDA_SSE_ME_19_SHIFT (11U)
#define VPU_HEVC_SWREG161_SW_ENC_LAMDA_SSE_ME_19(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG161_SW_ENC_LAMDA_SSE_ME_19_SHIFT)) & VPU_HEVC_SWREG161_SW_ENC_LAMDA_SSE_ME_19_MASK)
/*! @} */

/*! @name SWREG162 - inter me SSE lambda config 20 */
/*! @{ */

#define VPU_HEVC_SWREG162_SW_ENC_LAMDA_SSE_ME_20_MASK (0xFFFFF800U)
#define VPU_HEVC_SWREG162_SW_ENC_LAMDA_SSE_ME_20_SHIFT (11U)
#define VPU_HEVC_SWREG162_SW_ENC_LAMDA_SSE_ME_20(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG162_SW_ENC_LAMDA_SSE_ME_20_SHIFT)) & VPU_HEVC_SWREG162_SW_ENC_LAMDA_SSE_ME_20_MASK)
/*! @} */

/*! @name SWREG163 - inter me SSE lambda config 21 */
/*! @{ */

#define VPU_HEVC_SWREG163_SW_ENC_LAMDA_SSE_ME_21_MASK (0xFFFFF800U)
#define VPU_HEVC_SWREG163_SW_ENC_LAMDA_SSE_ME_21_SHIFT (11U)
#define VPU_HEVC_SWREG163_SW_ENC_LAMDA_SSE_ME_21(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG163_SW_ENC_LAMDA_SSE_ME_21_SHIFT)) & VPU_HEVC_SWREG163_SW_ENC_LAMDA_SSE_ME_21_MASK)
/*! @} */

/*! @name SWREG164 - inter me SSE lambda config 22 */
/*! @{ */

#define VPU_HEVC_SWREG164_SW_ENC_LAMDA_SSE_ME_22_MASK (0xFFFFF800U)
#define VPU_HEVC_SWREG164_SW_ENC_LAMDA_SSE_ME_22_SHIFT (11U)
#define VPU_HEVC_SWREG164_SW_ENC_LAMDA_SSE_ME_22(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG164_SW_ENC_LAMDA_SSE_ME_22_SHIFT)) & VPU_HEVC_SWREG164_SW_ENC_LAMDA_SSE_ME_22_MASK)
/*! @} */

/*! @name SWREG165 - inter me SSE lambda config 23 */
/*! @{ */

#define VPU_HEVC_SWREG165_SW_ENC_LAMDA_SSE_ME_23_MASK (0xFFFFF800U)
#define VPU_HEVC_SWREG165_SW_ENC_LAMDA_SSE_ME_23_SHIFT (11U)
#define VPU_HEVC_SWREG165_SW_ENC_LAMDA_SSE_ME_23(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG165_SW_ENC_LAMDA_SSE_ME_23_SHIFT)) & VPU_HEVC_SWREG165_SW_ENC_LAMDA_SSE_ME_23_MASK)
/*! @} */

/*! @name SWREG166 - inter me SSE lambda config 24 */
/*! @{ */

#define VPU_HEVC_SWREG166_SW_ENC_LAMDA_SSE_ME_24_MASK (0xFFFFF800U)
#define VPU_HEVC_SWREG166_SW_ENC_LAMDA_SSE_ME_24_SHIFT (11U)
#define VPU_HEVC_SWREG166_SW_ENC_LAMDA_SSE_ME_24(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG166_SW_ENC_LAMDA_SSE_ME_24_SHIFT)) & VPU_HEVC_SWREG166_SW_ENC_LAMDA_SSE_ME_24_MASK)
/*! @} */

/*! @name SWREG167 - inter me SSE lambda config 25 */
/*! @{ */

#define VPU_HEVC_SWREG167_SW_ENC_LAMDA_SSE_ME_25_MASK (0xFFFFF800U)
#define VPU_HEVC_SWREG167_SW_ENC_LAMDA_SSE_ME_25_SHIFT (11U)
#define VPU_HEVC_SWREG167_SW_ENC_LAMDA_SSE_ME_25(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG167_SW_ENC_LAMDA_SSE_ME_25_SHIFT)) & VPU_HEVC_SWREG167_SW_ENC_LAMDA_SSE_ME_25_MASK)
/*! @} */

/*! @name SWREG168 - inter me SSE lambda config 26 */
/*! @{ */

#define VPU_HEVC_SWREG168_SW_ENC_LAMDA_SSE_ME_26_MASK (0xFFFFF800U)
#define VPU_HEVC_SWREG168_SW_ENC_LAMDA_SSE_ME_26_SHIFT (11U)
#define VPU_HEVC_SWREG168_SW_ENC_LAMDA_SSE_ME_26(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG168_SW_ENC_LAMDA_SSE_ME_26_SHIFT)) & VPU_HEVC_SWREG168_SW_ENC_LAMDA_SSE_ME_26_MASK)
/*! @} */

/*! @name SWREG169 - inter me SSE lambda config 27 */
/*! @{ */

#define VPU_HEVC_SWREG169_SW_ENC_LAMDA_SSE_ME_27_MASK (0xFFFFF800U)
#define VPU_HEVC_SWREG169_SW_ENC_LAMDA_SSE_ME_27_SHIFT (11U)
#define VPU_HEVC_SWREG169_SW_ENC_LAMDA_SSE_ME_27(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG169_SW_ENC_LAMDA_SSE_ME_27_SHIFT)) & VPU_HEVC_SWREG169_SW_ENC_LAMDA_SSE_ME_27_MASK)
/*! @} */

/*! @name SWREG172 - inter me SSE lambda config 30 */
/*! @{ */

#define VPU_HEVC_SWREG172_SW_ENC_COMPLEXITY_OFFSET_MASK (0x1FU)
#define VPU_HEVC_SWREG172_SW_ENC_COMPLEXITY_OFFSET_SHIFT (0U)
#define VPU_HEVC_SWREG172_SW_ENC_COMPLEXITY_OFFSET(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG172_SW_ENC_COMPLEXITY_OFFSET_SHIFT)) & VPU_HEVC_SWREG172_SW_ENC_COMPLEXITY_OFFSET_MASK)

#define VPU_HEVC_SWREG172_SW_ENC_QP_MIN_MASK     (0x7E0U)
#define VPU_HEVC_SWREG172_SW_ENC_QP_MIN_SHIFT    (5U)
#define VPU_HEVC_SWREG172_SW_ENC_QP_MIN(x)       (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG172_SW_ENC_QP_MIN_SHIFT)) & VPU_HEVC_SWREG172_SW_ENC_QP_MIN_MASK)

#define VPU_HEVC_SWREG172_SW_ENC_LAMDA_SSE_ME_30_MASK (0xFFFFF800U)
#define VPU_HEVC_SWREG172_SW_ENC_LAMDA_SSE_ME_30_SHIFT (11U)
#define VPU_HEVC_SWREG172_SW_ENC_LAMDA_SSE_ME_30(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG172_SW_ENC_LAMDA_SSE_ME_30_SHIFT)) & VPU_HEVC_SWREG172_SW_ENC_LAMDA_SSE_ME_30_MASK)
/*! @} */

/*! @name SWREG173 - inter me SSE lambda config 31 */
/*! @{ */

#define VPU_HEVC_SWREG173_SW_ENC_RC_QPDELTA_RANGE_MASK (0xFU)
#define VPU_HEVC_SWREG173_SW_ENC_RC_QPDELTA_RANGE_SHIFT (0U)
#define VPU_HEVC_SWREG173_SW_ENC_RC_QPDELTA_RANGE(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG173_SW_ENC_RC_QPDELTA_RANGE_SHIFT)) & VPU_HEVC_SWREG173_SW_ENC_RC_QPDELTA_RANGE_MASK)

#define VPU_HEVC_SWREG173_SW_ENC_QP_MAX_MASK     (0x7E0U)
#define VPU_HEVC_SWREG173_SW_ENC_QP_MAX_SHIFT    (5U)
#define VPU_HEVC_SWREG173_SW_ENC_QP_MAX(x)       (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG173_SW_ENC_QP_MAX_SHIFT)) & VPU_HEVC_SWREG173_SW_ENC_QP_MAX_MASK)

#define VPU_HEVC_SWREG173_SW_ENC_LAMDA_SSE_ME_31_MASK (0xFFFFF800U)
#define VPU_HEVC_SWREG173_SW_ENC_LAMDA_SSE_ME_31_SHIFT (11U)
#define VPU_HEVC_SWREG173_SW_ENC_LAMDA_SSE_ME_31(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG173_SW_ENC_LAMDA_SSE_ME_31_SHIFT)) & VPU_HEVC_SWREG173_SW_ENC_LAMDA_SSE_ME_31_MASK)
/*! @} */

/*! @name SWREG174 - intra SATD lambda config 8 */
/*! @{ */

#define VPU_HEVC_SWREG174_SW_ENC_INTRA_SATD_LAMDA_17_MASK (0x3FFF0U)
#define VPU_HEVC_SWREG174_SW_ENC_INTRA_SATD_LAMDA_17_SHIFT (4U)
#define VPU_HEVC_SWREG174_SW_ENC_INTRA_SATD_LAMDA_17(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG174_SW_ENC_INTRA_SATD_LAMDA_17_SHIFT)) & VPU_HEVC_SWREG174_SW_ENC_INTRA_SATD_LAMDA_17_MASK)

#define VPU_HEVC_SWREG174_SW_ENC_INTRA_SATD_LAMDA_16_MASK (0xFFFC0000U)
#define VPU_HEVC_SWREG174_SW_ENC_INTRA_SATD_LAMDA_16_SHIFT (18U)
#define VPU_HEVC_SWREG174_SW_ENC_INTRA_SATD_LAMDA_16(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG174_SW_ENC_INTRA_SATD_LAMDA_16_SHIFT)) & VPU_HEVC_SWREG174_SW_ENC_INTRA_SATD_LAMDA_16_MASK)
/*! @} */

/*! @name SWREG175 - intra SATD lambda config 9 */
/*! @{ */

#define VPU_HEVC_SWREG175_SW_ENC_INTRA_SATD_LAMDA_19_MASK (0x3FFF0U)
#define VPU_HEVC_SWREG175_SW_ENC_INTRA_SATD_LAMDA_19_SHIFT (4U)
#define VPU_HEVC_SWREG175_SW_ENC_INTRA_SATD_LAMDA_19(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG175_SW_ENC_INTRA_SATD_LAMDA_19_SHIFT)) & VPU_HEVC_SWREG175_SW_ENC_INTRA_SATD_LAMDA_19_MASK)

#define VPU_HEVC_SWREG175_SW_ENC_INTRA_SATD_LAMDA_18_MASK (0xFFFC0000U)
#define VPU_HEVC_SWREG175_SW_ENC_INTRA_SATD_LAMDA_18_SHIFT (18U)
#define VPU_HEVC_SWREG175_SW_ENC_INTRA_SATD_LAMDA_18(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG175_SW_ENC_INTRA_SATD_LAMDA_18_SHIFT)) & VPU_HEVC_SWREG175_SW_ENC_INTRA_SATD_LAMDA_18_MASK)
/*! @} */

/*! @name SWREG176 - intra SATD lambda config 10 */
/*! @{ */

#define VPU_HEVC_SWREG176_SW_ENC_INTRA_SATD_LAMDA_21_MASK (0x3FFF0U)
#define VPU_HEVC_SWREG176_SW_ENC_INTRA_SATD_LAMDA_21_SHIFT (4U)
#define VPU_HEVC_SWREG176_SW_ENC_INTRA_SATD_LAMDA_21(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG176_SW_ENC_INTRA_SATD_LAMDA_21_SHIFT)) & VPU_HEVC_SWREG176_SW_ENC_INTRA_SATD_LAMDA_21_MASK)

#define VPU_HEVC_SWREG176_SW_ENC_INTRA_SATD_LAMDA_20_MASK (0xFFFC0000U)
#define VPU_HEVC_SWREG176_SW_ENC_INTRA_SATD_LAMDA_20_SHIFT (18U)
#define VPU_HEVC_SWREG176_SW_ENC_INTRA_SATD_LAMDA_20(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG176_SW_ENC_INTRA_SATD_LAMDA_20_SHIFT)) & VPU_HEVC_SWREG176_SW_ENC_INTRA_SATD_LAMDA_20_MASK)
/*! @} */

/*! @name SWREG177 - intra SATD lambda config 11 */
/*! @{ */

#define VPU_HEVC_SWREG177_SW_ENC_INTRA_SATD_LAMDA_23_MASK (0x3FFF0U)
#define VPU_HEVC_SWREG177_SW_ENC_INTRA_SATD_LAMDA_23_SHIFT (4U)
#define VPU_HEVC_SWREG177_SW_ENC_INTRA_SATD_LAMDA_23(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG177_SW_ENC_INTRA_SATD_LAMDA_23_SHIFT)) & VPU_HEVC_SWREG177_SW_ENC_INTRA_SATD_LAMDA_23_MASK)

#define VPU_HEVC_SWREG177_SW_ENC_INTRA_SATD_LAMDA_22_MASK (0xFFFC0000U)
#define VPU_HEVC_SWREG177_SW_ENC_INTRA_SATD_LAMDA_22_SHIFT (18U)
#define VPU_HEVC_SWREG177_SW_ENC_INTRA_SATD_LAMDA_22(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG177_SW_ENC_INTRA_SATD_LAMDA_22_SHIFT)) & VPU_HEVC_SWREG177_SW_ENC_INTRA_SATD_LAMDA_22_MASK)
/*! @} */

/*! @name SWREG178 - intra SATD lambda config 12 */
/*! @{ */

#define VPU_HEVC_SWREG178_SW_ENC_INTRA_SATD_LAMDA_25_MASK (0x3FFF0U)
#define VPU_HEVC_SWREG178_SW_ENC_INTRA_SATD_LAMDA_25_SHIFT (4U)
#define VPU_HEVC_SWREG178_SW_ENC_INTRA_SATD_LAMDA_25(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG178_SW_ENC_INTRA_SATD_LAMDA_25_SHIFT)) & VPU_HEVC_SWREG178_SW_ENC_INTRA_SATD_LAMDA_25_MASK)

#define VPU_HEVC_SWREG178_SW_ENC_INTRA_SATD_LAMDA_24_MASK (0xFFFC0000U)
#define VPU_HEVC_SWREG178_SW_ENC_INTRA_SATD_LAMDA_24_SHIFT (18U)
#define VPU_HEVC_SWREG178_SW_ENC_INTRA_SATD_LAMDA_24(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG178_SW_ENC_INTRA_SATD_LAMDA_24_SHIFT)) & VPU_HEVC_SWREG178_SW_ENC_INTRA_SATD_LAMDA_24_MASK)
/*! @} */

/*! @name SWREG179 - intra SATD lambda config 13 */
/*! @{ */

#define VPU_HEVC_SWREG179_SW_ENC_INTRA_SATD_LAMDA_27_MASK (0x3FFF0U)
#define VPU_HEVC_SWREG179_SW_ENC_INTRA_SATD_LAMDA_27_SHIFT (4U)
#define VPU_HEVC_SWREG179_SW_ENC_INTRA_SATD_LAMDA_27(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG179_SW_ENC_INTRA_SATD_LAMDA_27_SHIFT)) & VPU_HEVC_SWREG179_SW_ENC_INTRA_SATD_LAMDA_27_MASK)

#define VPU_HEVC_SWREG179_SW_ENC_INTRA_SATD_LAMDA_26_MASK (0xFFFC0000U)
#define VPU_HEVC_SWREG179_SW_ENC_INTRA_SATD_LAMDA_26_SHIFT (18U)
#define VPU_HEVC_SWREG179_SW_ENC_INTRA_SATD_LAMDA_26(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG179_SW_ENC_INTRA_SATD_LAMDA_26_SHIFT)) & VPU_HEVC_SWREG179_SW_ENC_INTRA_SATD_LAMDA_26_MASK)
/*! @} */

/*! @name SWREG180 - intra SATD lambda config 14 */
/*! @{ */

#define VPU_HEVC_SWREG180_SW_ENC_INTRA_SATD_LAMDA_29_MASK (0x3FFF0U)
#define VPU_HEVC_SWREG180_SW_ENC_INTRA_SATD_LAMDA_29_SHIFT (4U)
#define VPU_HEVC_SWREG180_SW_ENC_INTRA_SATD_LAMDA_29(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG180_SW_ENC_INTRA_SATD_LAMDA_29_SHIFT)) & VPU_HEVC_SWREG180_SW_ENC_INTRA_SATD_LAMDA_29_MASK)

#define VPU_HEVC_SWREG180_SW_ENC_INTRA_SATD_LAMDA_28_MASK (0xFFFC0000U)
#define VPU_HEVC_SWREG180_SW_ENC_INTRA_SATD_LAMDA_28_SHIFT (18U)
#define VPU_HEVC_SWREG180_SW_ENC_INTRA_SATD_LAMDA_28(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG180_SW_ENC_INTRA_SATD_LAMDA_28_SHIFT)) & VPU_HEVC_SWREG180_SW_ENC_INTRA_SATD_LAMDA_28_MASK)
/*! @} */

/*! @name SWREG181 - intra SATD lambda config 15 */
/*! @{ */

#define VPU_HEVC_SWREG181_SW_ENC_RC_BLOCK_SIZE_MASK (0xCU)
#define VPU_HEVC_SWREG181_SW_ENC_RC_BLOCK_SIZE_SHIFT (2U)
/*! SW_ENC_RC_BLOCK_SIZE
 *  0b00..64x64.
 *  0b01..32x32.
 *  0b10..16x16
 */
#define VPU_HEVC_SWREG181_SW_ENC_RC_BLOCK_SIZE(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG181_SW_ENC_RC_BLOCK_SIZE_SHIFT)) & VPU_HEVC_SWREG181_SW_ENC_RC_BLOCK_SIZE_MASK)

#define VPU_HEVC_SWREG181_SW_ENC_INTRA_SATD_LAMDA_31_MASK (0x3FFF0U)
#define VPU_HEVC_SWREG181_SW_ENC_INTRA_SATD_LAMDA_31_SHIFT (4U)
#define VPU_HEVC_SWREG181_SW_ENC_INTRA_SATD_LAMDA_31(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG181_SW_ENC_INTRA_SATD_LAMDA_31_SHIFT)) & VPU_HEVC_SWREG181_SW_ENC_INTRA_SATD_LAMDA_31_MASK)

#define VPU_HEVC_SWREG181_SW_ENC_INTRA_SATD_LAMDA_30_MASK (0xFFFC0000U)
#define VPU_HEVC_SWREG181_SW_ENC_INTRA_SATD_LAMDA_30_SHIFT (18U)
#define VPU_HEVC_SWREG181_SW_ENC_INTRA_SATD_LAMDA_30(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG181_SW_ENC_INTRA_SATD_LAMDA_30_SHIFT)) & VPU_HEVC_SWREG181_SW_ENC_INTRA_SATD_LAMDA_30_MASK)
/*! @} */

/*! @name SWREG182 - qp fractional part */
/*! @{ */

#define VPU_HEVC_SWREG182_SW_ENC_QP_DELTA_GAIN_MASK (0xFFFFU)
#define VPU_HEVC_SWREG182_SW_ENC_QP_DELTA_GAIN_SHIFT (0U)
#define VPU_HEVC_SWREG182_SW_ENC_QP_DELTA_GAIN(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG182_SW_ENC_QP_DELTA_GAIN_SHIFT)) & VPU_HEVC_SWREG182_SW_ENC_QP_DELTA_GAIN_MASK)

#define VPU_HEVC_SWREG182_SW_ENC_QP_FRACTIONAL_MASK (0xFFFF0000U)
#define VPU_HEVC_SWREG182_SW_ENC_QP_FRACTIONAL_SHIFT (16U)
#define VPU_HEVC_SWREG182_SW_ENC_QP_FRACTIONAL(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG182_SW_ENC_QP_FRACTIONAL_SHIFT)) & VPU_HEVC_SWREG182_SW_ENC_QP_FRACTIONAL_MASK)
/*! @} */

/*! @name SWREG183 - qp sum */
/*! @{ */

#define VPU_HEVC_SWREG183_SW_ENC_QP_SUM_MASK     (0xFFFFFFC0U)
#define VPU_HEVC_SWREG183_SW_ENC_QP_SUM_SHIFT    (6U)
#define VPU_HEVC_SWREG183_SW_ENC_QP_SUM(x)       (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG183_SW_ENC_QP_SUM_SHIFT)) & VPU_HEVC_SWREG183_SW_ENC_QP_SUM_MASK)
/*! @} */

/*! @name SWREG184 - qp num */
/*! @{ */

#define VPU_HEVC_SWREG184_SW_ENC_QP_NUM_MASK     (0xFFFFF000U)
#define VPU_HEVC_SWREG184_SW_ENC_QP_NUM_SHIFT    (12U)
#define VPU_HEVC_SWREG184_SW_ENC_QP_NUM(x)       (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG184_SW_ENC_QP_NUM_SHIFT)) & VPU_HEVC_SWREG184_SW_ENC_QP_NUM_MASK)
/*! @} */

/*! @name SWREG185 - picture complexity. Timeout cycles MSB. */
/*! @{ */

#define VPU_HEVC_SWREG185_SW_TIMEOUT_CYCLES_MSB_MASK (0x1FFU)
#define VPU_HEVC_SWREG185_SW_TIMEOUT_CYCLES_MSB_SHIFT (0U)
#define VPU_HEVC_SWREG185_SW_TIMEOUT_CYCLES_MSB(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG185_SW_TIMEOUT_CYCLES_MSB_SHIFT)) & VPU_HEVC_SWREG185_SW_TIMEOUT_CYCLES_MSB_MASK)

#define VPU_HEVC_SWREG185_SW_ENC_PIC_COMPLEXITY_MASK (0xFFFFFE00U)
#define VPU_HEVC_SWREG185_SW_ENC_PIC_COMPLEXITY_SHIFT (9U)
#define VPU_HEVC_SWREG185_SW_ENC_PIC_COMPLEXITY(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG185_SW_ENC_PIC_COMPLEXITY_SHIFT)) & VPU_HEVC_SWREG185_SW_ENC_PIC_COMPLEXITY_MASK)
/*! @} */

/*! @name SWREG186 - Base address for CU information table LSB */
/*! @{ */

#define VPU_HEVC_SWREG186_SW_ENC_CU_INFORMATION_TABLE_BASE_MASK (0xFFFFFFFFU)
#define VPU_HEVC_SWREG186_SW_ENC_CU_INFORMATION_TABLE_BASE_SHIFT (0U)
#define VPU_HEVC_SWREG186_SW_ENC_CU_INFORMATION_TABLE_BASE(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG186_SW_ENC_CU_INFORMATION_TABLE_BASE_SHIFT)) & VPU_HEVC_SWREG186_SW_ENC_CU_INFORMATION_TABLE_BASE_MASK)
/*! @} */

/*! @name SWREG188 - Base address for CU information LSB */
/*! @{ */

#define VPU_HEVC_SWREG188_SW_ENC_CU_INFORMATION_BASE_MASK (0xFFFFFFFFU)
#define VPU_HEVC_SWREG188_SW_ENC_CU_INFORMATION_BASE_SHIFT (0U)
#define VPU_HEVC_SWREG188_SW_ENC_CU_INFORMATION_BASE(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG188_SW_ENC_CU_INFORMATION_BASE_SHIFT)) & VPU_HEVC_SWREG188_SW_ENC_CU_INFORMATION_BASE_MASK)
/*! @} */

/*! @name SWREG190 - Long-term reference pictures config */
/*! @{ */

#define VPU_HEVC_SWREG190_SW_ENC_NUM_LONG_TERM_PICS_MASK (0xC0000000U)
#define VPU_HEVC_SWREG190_SW_ENC_NUM_LONG_TERM_PICS_SHIFT (30U)
#define VPU_HEVC_SWREG190_SW_ENC_NUM_LONG_TERM_PICS(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG190_SW_ENC_NUM_LONG_TERM_PICS_SHIFT)) & VPU_HEVC_SWREG190_SW_ENC_NUM_LONG_TERM_PICS_MASK)
/*! @} */

/*! @name SWREG191 - Temporal scalable config */
/*! @{ */

#define VPU_HEVC_SWREG191_SW_ENC_SLICE_HEADER_SIZE_MASK (0xFFFFU)
#define VPU_HEVC_SWREG191_SW_ENC_SLICE_HEADER_SIZE_SHIFT (0U)
#define VPU_HEVC_SWREG191_SW_ENC_SLICE_HEADER_SIZE(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG191_SW_ENC_SLICE_HEADER_SIZE_SHIFT)) & VPU_HEVC_SWREG191_SW_ENC_SLICE_HEADER_SIZE_MASK)

#define VPU_HEVC_SWREG191_SW_ENC_PPS_ID_MASK     (0x7E0000U)
#define VPU_HEVC_SWREG191_SW_ENC_PPS_ID_SHIFT    (17U)
#define VPU_HEVC_SWREG191_SW_ENC_PPS_ID(x)       (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG191_SW_ENC_PPS_ID_SHIFT)) & VPU_HEVC_SWREG191_SW_ENC_PPS_ID_MASK)

#define VPU_HEVC_SWREG191_SW_ENC_NUH_TEMPORAL_ID_MASK (0x3800000U)
#define VPU_HEVC_SWREG191_SW_ENC_NUH_TEMPORAL_ID_SHIFT (23U)
#define VPU_HEVC_SWREG191_SW_ENC_NUH_TEMPORAL_ID(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG191_SW_ENC_NUH_TEMPORAL_ID_SHIFT)) & VPU_HEVC_SWREG191_SW_ENC_NUH_TEMPORAL_ID_MASK)

#define VPU_HEVC_SWREG191_SW_ENC_NAL_UNIT_TYPE_MASK (0xFC000000U)
#define VPU_HEVC_SWREG191_SW_ENC_NAL_UNIT_TYPE_SHIFT (26U)
#define VPU_HEVC_SWREG191_SW_ENC_NAL_UNIT_TYPE(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG191_SW_ENC_NAL_UNIT_TYPE_SHIFT)) & VPU_HEVC_SWREG191_SW_ENC_NAL_UNIT_TYPE_MASK)
/*! @} */

/*! @name SWREG195 - register extension for ctu_size=16 */
/*! @{ */

#define VPU_HEVC_SWREG195_SW_ENC_PIC_WIDTH_MSB_MASK (0xCU)
#define VPU_HEVC_SWREG195_SW_ENC_PIC_WIDTH_MSB_SHIFT (2U)
#define VPU_HEVC_SWREG195_SW_ENC_PIC_WIDTH_MSB(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG195_SW_ENC_PIC_WIDTH_MSB_SHIFT)) & VPU_HEVC_SWREG195_SW_ENC_PIC_WIDTH_MSB_MASK)

#define VPU_HEVC_SWREG195_SW_ENC_ROI2_BOTTOM_MSB_MASK (0x10U)
#define VPU_HEVC_SWREG195_SW_ENC_ROI2_BOTTOM_MSB_SHIFT (4U)
#define VPU_HEVC_SWREG195_SW_ENC_ROI2_BOTTOM_MSB(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG195_SW_ENC_ROI2_BOTTOM_MSB_SHIFT)) & VPU_HEVC_SWREG195_SW_ENC_ROI2_BOTTOM_MSB_MASK)

#define VPU_HEVC_SWREG195_SW_ENC_ROI2_TOP_MSB_MASK (0x20U)
#define VPU_HEVC_SWREG195_SW_ENC_ROI2_TOP_MSB_SHIFT (5U)
#define VPU_HEVC_SWREG195_SW_ENC_ROI2_TOP_MSB(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG195_SW_ENC_ROI2_TOP_MSB_SHIFT)) & VPU_HEVC_SWREG195_SW_ENC_ROI2_TOP_MSB_MASK)

#define VPU_HEVC_SWREG195_SW_ENC_ROI2_RIGHT_MSB_MASK (0x40U)
#define VPU_HEVC_SWREG195_SW_ENC_ROI2_RIGHT_MSB_SHIFT (6U)
#define VPU_HEVC_SWREG195_SW_ENC_ROI2_RIGHT_MSB(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG195_SW_ENC_ROI2_RIGHT_MSB_SHIFT)) & VPU_HEVC_SWREG195_SW_ENC_ROI2_RIGHT_MSB_MASK)

#define VPU_HEVC_SWREG195_SW_ENC_ROI2_LEFT_MSB_MASK (0x80U)
#define VPU_HEVC_SWREG195_SW_ENC_ROI2_LEFT_MSB_SHIFT (7U)
#define VPU_HEVC_SWREG195_SW_ENC_ROI2_LEFT_MSB(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG195_SW_ENC_ROI2_LEFT_MSB_SHIFT)) & VPU_HEVC_SWREG195_SW_ENC_ROI2_LEFT_MSB_MASK)

#define VPU_HEVC_SWREG195_SW_ENC_ROI1_BOTTOM_MSB_MASK (0x100U)
#define VPU_HEVC_SWREG195_SW_ENC_ROI1_BOTTOM_MSB_SHIFT (8U)
#define VPU_HEVC_SWREG195_SW_ENC_ROI1_BOTTOM_MSB(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG195_SW_ENC_ROI1_BOTTOM_MSB_SHIFT)) & VPU_HEVC_SWREG195_SW_ENC_ROI1_BOTTOM_MSB_MASK)

#define VPU_HEVC_SWREG195_SW_ENC_ROI1_TOP_MSB_MASK (0x200U)
#define VPU_HEVC_SWREG195_SW_ENC_ROI1_TOP_MSB_SHIFT (9U)
#define VPU_HEVC_SWREG195_SW_ENC_ROI1_TOP_MSB(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG195_SW_ENC_ROI1_TOP_MSB_SHIFT)) & VPU_HEVC_SWREG195_SW_ENC_ROI1_TOP_MSB_MASK)

#define VPU_HEVC_SWREG195_SW_ENC_ROI1_RIGHT_MSB_MASK (0x400U)
#define VPU_HEVC_SWREG195_SW_ENC_ROI1_RIGHT_MSB_SHIFT (10U)
#define VPU_HEVC_SWREG195_SW_ENC_ROI1_RIGHT_MSB(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG195_SW_ENC_ROI1_RIGHT_MSB_SHIFT)) & VPU_HEVC_SWREG195_SW_ENC_ROI1_RIGHT_MSB_MASK)

#define VPU_HEVC_SWREG195_SW_ENC_ROI1_LEFT_MSB_MASK (0x800U)
#define VPU_HEVC_SWREG195_SW_ENC_ROI1_LEFT_MSB_SHIFT (11U)
#define VPU_HEVC_SWREG195_SW_ENC_ROI1_LEFT_MSB(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG195_SW_ENC_ROI1_LEFT_MSB_SHIFT)) & VPU_HEVC_SWREG195_SW_ENC_ROI1_LEFT_MSB_MASK)

#define VPU_HEVC_SWREG195_SW_ENC_INTRA_AREA_BOTTOM_MSB_MASK (0x1000U)
#define VPU_HEVC_SWREG195_SW_ENC_INTRA_AREA_BOTTOM_MSB_SHIFT (12U)
#define VPU_HEVC_SWREG195_SW_ENC_INTRA_AREA_BOTTOM_MSB(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG195_SW_ENC_INTRA_AREA_BOTTOM_MSB_SHIFT)) & VPU_HEVC_SWREG195_SW_ENC_INTRA_AREA_BOTTOM_MSB_MASK)

#define VPU_HEVC_SWREG195_SW_ENC_INTRA_AREA_TOP_MSB_MASK (0x2000U)
#define VPU_HEVC_SWREG195_SW_ENC_INTRA_AREA_TOP_MSB_SHIFT (13U)
#define VPU_HEVC_SWREG195_SW_ENC_INTRA_AREA_TOP_MSB(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG195_SW_ENC_INTRA_AREA_TOP_MSB_SHIFT)) & VPU_HEVC_SWREG195_SW_ENC_INTRA_AREA_TOP_MSB_MASK)

#define VPU_HEVC_SWREG195_SW_ENC_INTRA_AREA_RIGHT_MSB_MASK (0x4000U)
#define VPU_HEVC_SWREG195_SW_ENC_INTRA_AREA_RIGHT_MSB_SHIFT (14U)
#define VPU_HEVC_SWREG195_SW_ENC_INTRA_AREA_RIGHT_MSB(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG195_SW_ENC_INTRA_AREA_RIGHT_MSB_SHIFT)) & VPU_HEVC_SWREG195_SW_ENC_INTRA_AREA_RIGHT_MSB_MASK)

#define VPU_HEVC_SWREG195_SW_ENC_INTRA_AREA_LEFT_MSB_MASK (0x8000U)
#define VPU_HEVC_SWREG195_SW_ENC_INTRA_AREA_LEFT_MSB_SHIFT (15U)
#define VPU_HEVC_SWREG195_SW_ENC_INTRA_AREA_LEFT_MSB(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG195_SW_ENC_INTRA_AREA_LEFT_MSB_SHIFT)) & VPU_HEVC_SWREG195_SW_ENC_INTRA_AREA_LEFT_MSB_MASK)

#define VPU_HEVC_SWREG195_SW_ENC_CIR_INTERVAL_MSB_MASK (0xF0000U)
#define VPU_HEVC_SWREG195_SW_ENC_CIR_INTERVAL_MSB_SHIFT (16U)
#define VPU_HEVC_SWREG195_SW_ENC_CIR_INTERVAL_MSB(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG195_SW_ENC_CIR_INTERVAL_MSB_SHIFT)) & VPU_HEVC_SWREG195_SW_ENC_CIR_INTERVAL_MSB_MASK)

#define VPU_HEVC_SWREG195_SW_ENC_CIR_START_MSB_MASK (0xF00000U)
#define VPU_HEVC_SWREG195_SW_ENC_CIR_START_MSB_SHIFT (20U)
#define VPU_HEVC_SWREG195_SW_ENC_CIR_START_MSB(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG195_SW_ENC_CIR_START_MSB_SHIFT)) & VPU_HEVC_SWREG195_SW_ENC_CIR_START_MSB_MASK)

#define VPU_HEVC_SWREG195_SW_ENC_SLICE_SIZE_MSB_MASK (0x3000000U)
#define VPU_HEVC_SWREG195_SW_ENC_SLICE_SIZE_MSB_SHIFT (24U)
#define VPU_HEVC_SWREG195_SW_ENC_SLICE_SIZE_MSB(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG195_SW_ENC_SLICE_SIZE_MSB_SHIFT)) & VPU_HEVC_SWREG195_SW_ENC_SLICE_SIZE_MSB_MASK)

#define VPU_HEVC_SWREG195_SW_ENC_NUM_SLICES_READY_MSB_MASK (0xC000000U)
#define VPU_HEVC_SWREG195_SW_ENC_NUM_SLICES_READY_MSB_SHIFT (26U)
#define VPU_HEVC_SWREG195_SW_ENC_NUM_SLICES_READY_MSB(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG195_SW_ENC_NUM_SLICES_READY_MSB_SHIFT)) & VPU_HEVC_SWREG195_SW_ENC_NUM_SLICES_READY_MSB_MASK)

#define VPU_HEVC_SWREG195_SW_ENC_ENCODED_CTB_NUMBER_MSB_MASK (0xF0000000U)
#define VPU_HEVC_SWREG195_SW_ENC_ENCODED_CTB_NUMBER_MSB_SHIFT (28U)
#define VPU_HEVC_SWREG195_SW_ENC_ENCODED_CTB_NUMBER_MSB(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG195_SW_ENC_ENCODED_CTB_NUMBER_MSB_SHIFT)) & VPU_HEVC_SWREG195_SW_ENC_ENCODED_CTB_NUMBER_MSB_MASK)
/*! @} */

/*! @name SWREG196 - Low Latency Controls */
/*! @{ */

#define VPU_HEVC_SWREG196_SW_CTB_ROW_WR_PTR_MASK (0x3FFU)
#define VPU_HEVC_SWREG196_SW_CTB_ROW_WR_PTR_SHIFT (0U)
#define VPU_HEVC_SWREG196_SW_CTB_ROW_WR_PTR(x)   (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG196_SW_CTB_ROW_WR_PTR_SHIFT)) & VPU_HEVC_SWREG196_SW_CTB_ROW_WR_PTR_MASK)

#define VPU_HEVC_SWREG196_SW_CTB_ROW_RD_PTR_MASK (0xFFC00U)
#define VPU_HEVC_SWREG196_SW_CTB_ROW_RD_PTR_SHIFT (10U)
#define VPU_HEVC_SWREG196_SW_CTB_ROW_RD_PTR(x)   (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG196_SW_CTB_ROW_RD_PTR_SHIFT)) & VPU_HEVC_SWREG196_SW_CTB_ROW_RD_PTR_MASK)

#define VPU_HEVC_SWREG196_SW_NUM_CTB_ROWS_PER_SYNC_MASK (0x1FF00000U)
#define VPU_HEVC_SWREG196_SW_NUM_CTB_ROWS_PER_SYNC_SHIFT (20U)
#define VPU_HEVC_SWREG196_SW_NUM_CTB_ROWS_PER_SYNC(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG196_SW_NUM_CTB_ROWS_PER_SYNC_SHIFT)) & VPU_HEVC_SWREG196_SW_NUM_CTB_ROWS_PER_SYNC_MASK)

#define VPU_HEVC_SWREG196_SW_INPUT_BUF_LOOPBACK_EN_MASK (0x20000000U)
#define VPU_HEVC_SWREG196_SW_INPUT_BUF_LOOPBACK_EN_SHIFT (29U)
#define VPU_HEVC_SWREG196_SW_INPUT_BUF_LOOPBACK_EN(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG196_SW_INPUT_BUF_LOOPBACK_EN_SHIFT)) & VPU_HEVC_SWREG196_SW_INPUT_BUF_LOOPBACK_EN_MASK)

#define VPU_HEVC_SWREG196_SW_LOW_LATENCY_EN_MASK (0x40000000U)
#define VPU_HEVC_SWREG196_SW_LOW_LATENCY_EN_SHIFT (30U)
#define VPU_HEVC_SWREG196_SW_LOW_LATENCY_EN(x)   (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG196_SW_LOW_LATENCY_EN_SHIFT)) & VPU_HEVC_SWREG196_SW_LOW_LATENCY_EN_MASK)

#define VPU_HEVC_SWREG196_SW_LOW_LATENCY_HW_SYNC_EN_MASK (0x80000000U)
#define VPU_HEVC_SWREG196_SW_LOW_LATENCY_HW_SYNC_EN_SHIFT (31U)
#define VPU_HEVC_SWREG196_SW_LOW_LATENCY_HW_SYNC_EN(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG196_SW_LOW_LATENCY_HW_SYNC_EN_SHIFT)) & VPU_HEVC_SWREG196_SW_LOW_LATENCY_HW_SYNC_EN_MASK)
/*! @} */

/*! @name SWREG197 - Delta POC extension */
/*! @{ */

#define VPU_HEVC_SWREG197_SW_ENC_L1_DELTA_POC0_MSB_MASK (0xFFCU)
#define VPU_HEVC_SWREG197_SW_ENC_L1_DELTA_POC0_MSB_SHIFT (2U)
#define VPU_HEVC_SWREG197_SW_ENC_L1_DELTA_POC0_MSB(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG197_SW_ENC_L1_DELTA_POC0_MSB_SHIFT)) & VPU_HEVC_SWREG197_SW_ENC_L1_DELTA_POC0_MSB_MASK)

#define VPU_HEVC_SWREG197_SW_ENC_L0_DELTA_POC1_MSB_MASK (0x3FF000U)
#define VPU_HEVC_SWREG197_SW_ENC_L0_DELTA_POC1_MSB_SHIFT (12U)
#define VPU_HEVC_SWREG197_SW_ENC_L0_DELTA_POC1_MSB(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG197_SW_ENC_L0_DELTA_POC1_MSB_SHIFT)) & VPU_HEVC_SWREG197_SW_ENC_L0_DELTA_POC1_MSB_MASK)

#define VPU_HEVC_SWREG197_SW_ENC_L0_DELTA_POC0_MSB_MASK (0xFFC00000U)
#define VPU_HEVC_SWREG197_SW_ENC_L0_DELTA_POC0_MSB_SHIFT (22U)
#define VPU_HEVC_SWREG197_SW_ENC_L0_DELTA_POC0_MSB(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG197_SW_ENC_L0_DELTA_POC0_MSB_SHIFT)) & VPU_HEVC_SWREG197_SW_ENC_L0_DELTA_POC0_MSB_MASK)
/*! @} */

/*! @name SWREG198 - Long Term Reference Control */
/*! @{ */

#define VPU_HEVC_SWREG198_SW_ENC_L1_DELTA_POC1_MSB_MASK (0xFFC00000U)
#define VPU_HEVC_SWREG198_SW_ENC_L1_DELTA_POC1_MSB_SHIFT (22U)
#define VPU_HEVC_SWREG198_SW_ENC_L1_DELTA_POC1_MSB(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG198_SW_ENC_L1_DELTA_POC1_MSB_SHIFT)) & VPU_HEVC_SWREG198_SW_ENC_L1_DELTA_POC1_MSB_MASK)
/*! @} */

/*! @name SWREG199 - Hash Code Control */
/*! @{ */

#define VPU_HEVC_SWREG199_SW_ENC_OSD_ALPHABLEND_ENABLE_MASK (0x1U)
#define VPU_HEVC_SWREG199_SW_ENC_OSD_ALPHABLEND_ENABLE_SHIFT (0U)
/*! SW_ENC_OSD_ALPHABLEND_ENABLE
 *  0b0..disable.
 *  0b1..enable.
 */
#define VPU_HEVC_SWREG199_SW_ENC_OSD_ALPHABLEND_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG199_SW_ENC_OSD_ALPHABLEND_ENABLE_SHIFT)) & VPU_HEVC_SWREG199_SW_ENC_OSD_ALPHABLEND_ENABLE_MASK)

#define VPU_HEVC_SWREG199_SW_ENC_HASH_OFFSET_MASK (0x6U)
#define VPU_HEVC_SWREG199_SW_ENC_HASH_OFFSET_SHIFT (1U)
#define VPU_HEVC_SWREG199_SW_ENC_HASH_OFFSET(x)  (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG199_SW_ENC_HASH_OFFSET_SHIFT)) & VPU_HEVC_SWREG199_SW_ENC_HASH_OFFSET_MASK)

#define VPU_HEVC_SWREG199_SW_ENC_HASH_TYPE_MASK  (0x18U)
#define VPU_HEVC_SWREG199_SW_ENC_HASH_TYPE_SHIFT (3U)
/*! SW_ENC_HASH_TYPE
 *  0b00..none.
 *  0b01..crc32.
 *  0b10..checksum32
 */
#define VPU_HEVC_SWREG199_SW_ENC_HASH_TYPE(x)    (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG199_SW_ENC_HASH_TYPE_SHIFT)) & VPU_HEVC_SWREG199_SW_ENC_HASH_TYPE_MASK)
/*! @} */

/*! @name SWREG200 - Hash Code Value */
/*! @{ */

#define VPU_HEVC_SWREG200_SW_ENC_HASH_VAL_MASK   (0xFFFFFFFFU)
#define VPU_HEVC_SWREG200_SW_ENC_HASH_VAL_SHIFT  (0U)
#define VPU_HEVC_SWREG200_SW_ENC_HASH_VAL(x)     (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG200_SW_ENC_HASH_VAL_SHIFT)) & VPU_HEVC_SWREG200_SW_ENC_HASH_VAL_MASK)
/*! @} */

/*! @name SWREG201 - Background SKIP Control 0 */
/*! @{ */

#define VPU_HEVC_SWREG201_SW_ENC_MEAN_THR3_MASK  (0xFFU)
#define VPU_HEVC_SWREG201_SW_ENC_MEAN_THR3_SHIFT (0U)
#define VPU_HEVC_SWREG201_SW_ENC_MEAN_THR3(x)    (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG201_SW_ENC_MEAN_THR3_SHIFT)) & VPU_HEVC_SWREG201_SW_ENC_MEAN_THR3_MASK)

#define VPU_HEVC_SWREG201_SW_ENC_MEAN_THR2_MASK  (0xFF00U)
#define VPU_HEVC_SWREG201_SW_ENC_MEAN_THR2_SHIFT (8U)
#define VPU_HEVC_SWREG201_SW_ENC_MEAN_THR2(x)    (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG201_SW_ENC_MEAN_THR2_SHIFT)) & VPU_HEVC_SWREG201_SW_ENC_MEAN_THR2_MASK)

#define VPU_HEVC_SWREG201_SW_ENC_MEAN_THR1_MASK  (0xFF0000U)
#define VPU_HEVC_SWREG201_SW_ENC_MEAN_THR1_SHIFT (16U)
#define VPU_HEVC_SWREG201_SW_ENC_MEAN_THR1(x)    (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG201_SW_ENC_MEAN_THR1_SHIFT)) & VPU_HEVC_SWREG201_SW_ENC_MEAN_THR1_MASK)

#define VPU_HEVC_SWREG201_SW_ENC_MEAN_THR0_MASK  (0xFF000000U)
#define VPU_HEVC_SWREG201_SW_ENC_MEAN_THR0_SHIFT (24U)
#define VPU_HEVC_SWREG201_SW_ENC_MEAN_THR0(x)    (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG201_SW_ENC_MEAN_THR0_SHIFT)) & VPU_HEVC_SWREG201_SW_ENC_MEAN_THR0_MASK)
/*! @} */

/*! @name SWREG202 - Background SKIP Control 1 */
/*! @{ */

#define VPU_HEVC_SWREG202_SW_ENC_THR_DC_CHROMA_8X8_MASK (0xFFFFU)
#define VPU_HEVC_SWREG202_SW_ENC_THR_DC_CHROMA_8X8_SHIFT (0U)
#define VPU_HEVC_SWREG202_SW_ENC_THR_DC_CHROMA_8X8(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG202_SW_ENC_THR_DC_CHROMA_8X8_SHIFT)) & VPU_HEVC_SWREG202_SW_ENC_THR_DC_CHROMA_8X8_MASK)

#define VPU_HEVC_SWREG202_SW_ENC_THR_DC_LUM_8X8_MASK (0xFFFF0000U)
#define VPU_HEVC_SWREG202_SW_ENC_THR_DC_LUM_8X8_SHIFT (16U)
#define VPU_HEVC_SWREG202_SW_ENC_THR_DC_LUM_8X8(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG202_SW_ENC_THR_DC_LUM_8X8_SHIFT)) & VPU_HEVC_SWREG202_SW_ENC_THR_DC_LUM_8X8_MASK)
/*! @} */

/*! @name SWREG203 - Background SKIP Control 2 */
/*! @{ */

#define VPU_HEVC_SWREG203_SW_ENC_THR_DC_CHROMA_16X16_MASK (0xFFFFU)
#define VPU_HEVC_SWREG203_SW_ENC_THR_DC_CHROMA_16X16_SHIFT (0U)
#define VPU_HEVC_SWREG203_SW_ENC_THR_DC_CHROMA_16X16(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG203_SW_ENC_THR_DC_CHROMA_16X16_SHIFT)) & VPU_HEVC_SWREG203_SW_ENC_THR_DC_CHROMA_16X16_MASK)

#define VPU_HEVC_SWREG203_SW_ENC_THR_DC_LUM_16X16_MASK (0xFFFF0000U)
#define VPU_HEVC_SWREG203_SW_ENC_THR_DC_LUM_16X16_SHIFT (16U)
#define VPU_HEVC_SWREG203_SW_ENC_THR_DC_LUM_16X16(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG203_SW_ENC_THR_DC_LUM_16X16_SHIFT)) & VPU_HEVC_SWREG203_SW_ENC_THR_DC_LUM_16X16_MASK)
/*! @} */

/*! @name SWREG204 - Background SKIP Control 3 */
/*! @{ */

#define VPU_HEVC_SWREG204_SW_ENC_THR_DC_CHROMA_32X32_MASK (0xFFFFU)
#define VPU_HEVC_SWREG204_SW_ENC_THR_DC_CHROMA_32X32_SHIFT (0U)
#define VPU_HEVC_SWREG204_SW_ENC_THR_DC_CHROMA_32X32(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG204_SW_ENC_THR_DC_CHROMA_32X32_SHIFT)) & VPU_HEVC_SWREG204_SW_ENC_THR_DC_CHROMA_32X32_MASK)

#define VPU_HEVC_SWREG204_SW_ENC_THR_DC_LUM_32X32_MASK (0xFFFF0000U)
#define VPU_HEVC_SWREG204_SW_ENC_THR_DC_LUM_32X32_SHIFT (16U)
#define VPU_HEVC_SWREG204_SW_ENC_THR_DC_LUM_32X32(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG204_SW_ENC_THR_DC_LUM_32X32_SHIFT)) & VPU_HEVC_SWREG204_SW_ENC_THR_DC_LUM_32X32_MASK)
/*! @} */

/*! @name SWREG205 - Background SKIP Control 4 */
/*! @{ */

#define VPU_HEVC_SWREG205_SW_ENC_THR_AC_NUM_CHROMA_8X8_MASK (0xFFFFU)
#define VPU_HEVC_SWREG205_SW_ENC_THR_AC_NUM_CHROMA_8X8_SHIFT (0U)
#define VPU_HEVC_SWREG205_SW_ENC_THR_AC_NUM_CHROMA_8X8(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG205_SW_ENC_THR_AC_NUM_CHROMA_8X8_SHIFT)) & VPU_HEVC_SWREG205_SW_ENC_THR_AC_NUM_CHROMA_8X8_MASK)

#define VPU_HEVC_SWREG205_SW_ENC_THR_AC_NUM_LUM_8X8_MASK (0xFFFF0000U)
#define VPU_HEVC_SWREG205_SW_ENC_THR_AC_NUM_LUM_8X8_SHIFT (16U)
#define VPU_HEVC_SWREG205_SW_ENC_THR_AC_NUM_LUM_8X8(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG205_SW_ENC_THR_AC_NUM_LUM_8X8_SHIFT)) & VPU_HEVC_SWREG205_SW_ENC_THR_AC_NUM_LUM_8X8_MASK)
/*! @} */

/*! @name SWREG206 - Background SKIP Control 5 */
/*! @{ */

#define VPU_HEVC_SWREG206_SW_ENC_THR_AC_NUM_CHROMA_16X16_MASK (0xFFFFU)
#define VPU_HEVC_SWREG206_SW_ENC_THR_AC_NUM_CHROMA_16X16_SHIFT (0U)
#define VPU_HEVC_SWREG206_SW_ENC_THR_AC_NUM_CHROMA_16X16(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG206_SW_ENC_THR_AC_NUM_CHROMA_16X16_SHIFT)) & VPU_HEVC_SWREG206_SW_ENC_THR_AC_NUM_CHROMA_16X16_MASK)

#define VPU_HEVC_SWREG206_SW_ENC_THR_AC_NUM_LUM_16X16_MASK (0xFFFF0000U)
#define VPU_HEVC_SWREG206_SW_ENC_THR_AC_NUM_LUM_16X16_SHIFT (16U)
#define VPU_HEVC_SWREG206_SW_ENC_THR_AC_NUM_LUM_16X16(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG206_SW_ENC_THR_AC_NUM_LUM_16X16_SHIFT)) & VPU_HEVC_SWREG206_SW_ENC_THR_AC_NUM_LUM_16X16_MASK)
/*! @} */

/*! @name SWREG207 - Background SKIP Control 6 */
/*! @{ */

#define VPU_HEVC_SWREG207_SW_ENC_THR_AC_NUM_CHROMA_32X32_MASK (0xFFFFU)
#define VPU_HEVC_SWREG207_SW_ENC_THR_AC_NUM_CHROMA_32X32_SHIFT (0U)
#define VPU_HEVC_SWREG207_SW_ENC_THR_AC_NUM_CHROMA_32X32(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG207_SW_ENC_THR_AC_NUM_CHROMA_32X32_SHIFT)) & VPU_HEVC_SWREG207_SW_ENC_THR_AC_NUM_CHROMA_32X32_MASK)

#define VPU_HEVC_SWREG207_SW_ENC_THR_AC_NUM_LUM_32X32_MASK (0xFFFF0000U)
#define VPU_HEVC_SWREG207_SW_ENC_THR_AC_NUM_LUM_32X32_SHIFT (16U)
#define VPU_HEVC_SWREG207_SW_ENC_THR_AC_NUM_LUM_32X32(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG207_SW_ENC_THR_AC_NUM_LUM_32X32_SHIFT)) & VPU_HEVC_SWREG207_SW_ENC_THR_AC_NUM_LUM_32X32_MASK)
/*! @} */

/*! @name SWREG208 - Background SKIP Control 7 */
/*! @{ */

#define VPU_HEVC_SWREG208_SW_ENC_SKIP_MAP_ENABLE_MASK (0x8U)
#define VPU_HEVC_SWREG208_SW_ENC_SKIP_MAP_ENABLE_SHIFT (3U)
#define VPU_HEVC_SWREG208_SW_ENC_SKIP_MAP_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG208_SW_ENC_SKIP_MAP_ENABLE_SHIFT)) & VPU_HEVC_SWREG208_SW_ENC_SKIP_MAP_ENABLE_MASK)

#define VPU_HEVC_SWREG208_SW_ENC_IPCM1_LEFT_MASK (0x1FF0U)
#define VPU_HEVC_SWREG208_SW_ENC_IPCM1_LEFT_SHIFT (4U)
#define VPU_HEVC_SWREG208_SW_ENC_IPCM1_LEFT(x)   (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG208_SW_ENC_IPCM1_LEFT_SHIFT)) & VPU_HEVC_SWREG208_SW_ENC_IPCM1_LEFT_MASK)

#define VPU_HEVC_SWREG208_SW_ENC_ENABLE_SMART_MASK (0x2000U)
#define VPU_HEVC_SWREG208_SW_ENC_ENABLE_SMART_SHIFT (13U)
#define VPU_HEVC_SWREG208_SW_ENC_ENABLE_SMART(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG208_SW_ENC_ENABLE_SMART_SHIFT)) & VPU_HEVC_SWREG208_SW_ENC_ENABLE_SMART_MASK)

#define VPU_HEVC_SWREG208_SW_ENC_FOREGROUND_PIXEL_THX_MASK (0xFC000U)
#define VPU_HEVC_SWREG208_SW_ENC_FOREGROUND_PIXEL_THX_SHIFT (14U)
#define VPU_HEVC_SWREG208_SW_ENC_FOREGROUND_PIXEL_THX(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG208_SW_ENC_FOREGROUND_PIXEL_THX_SHIFT)) & VPU_HEVC_SWREG208_SW_ENC_FOREGROUND_PIXEL_THX_MASK)

#define VPU_HEVC_SWREG208_SW_ENC_MDQPC_MASK      (0x3F00000U)
#define VPU_HEVC_SWREG208_SW_ENC_MDQPC_SHIFT     (20U)
#define VPU_HEVC_SWREG208_SW_ENC_MDQPC(x)        (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG208_SW_ENC_MDQPC_SHIFT)) & VPU_HEVC_SWREG208_SW_ENC_MDQPC_MASK)

#define VPU_HEVC_SWREG208_SW_ENC_MDQPY_MASK      (0xFC000000U)
#define VPU_HEVC_SWREG208_SW_ENC_MDQPY_SHIFT     (26U)
#define VPU_HEVC_SWREG208_SW_ENC_MDQPY(x)        (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG208_SW_ENC_MDQPY_SHIFT)) & VPU_HEVC_SWREG208_SW_ENC_MDQPY_MASK)
/*! @} */

/*! @name SWREG209 - IPCM Control 0 */
/*! @{ */

#define VPU_HEVC_SWREG209_SW_ENC_IPCM_MAP_ENABLE_MASK (0x8U)
#define VPU_HEVC_SWREG209_SW_ENC_IPCM_MAP_ENABLE_SHIFT (3U)
#define VPU_HEVC_SWREG209_SW_ENC_IPCM_MAP_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG209_SW_ENC_IPCM_MAP_ENABLE_SHIFT)) & VPU_HEVC_SWREG209_SW_ENC_IPCM_MAP_ENABLE_MASK)

#define VPU_HEVC_SWREG209_SW_ENC_PCM_FILTER_DISABLE_MASK (0x10U)
#define VPU_HEVC_SWREG209_SW_ENC_PCM_FILTER_DISABLE_SHIFT (4U)
#define VPU_HEVC_SWREG209_SW_ENC_PCM_FILTER_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG209_SW_ENC_PCM_FILTER_DISABLE_SHIFT)) & VPU_HEVC_SWREG209_SW_ENC_PCM_FILTER_DISABLE_MASK)

#define VPU_HEVC_SWREG209_SW_ENC_IPCM1_BOTTOM_MASK (0x3FE0U)
#define VPU_HEVC_SWREG209_SW_ENC_IPCM1_BOTTOM_SHIFT (5U)
#define VPU_HEVC_SWREG209_SW_ENC_IPCM1_BOTTOM(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG209_SW_ENC_IPCM1_BOTTOM_SHIFT)) & VPU_HEVC_SWREG209_SW_ENC_IPCM1_BOTTOM_MASK)

#define VPU_HEVC_SWREG209_SW_ENC_IPCM1_TOP_MASK  (0x7FC000U)
#define VPU_HEVC_SWREG209_SW_ENC_IPCM1_TOP_SHIFT (14U)
#define VPU_HEVC_SWREG209_SW_ENC_IPCM1_TOP(x)    (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG209_SW_ENC_IPCM1_TOP_SHIFT)) & VPU_HEVC_SWREG209_SW_ENC_IPCM1_TOP_MASK)

#define VPU_HEVC_SWREG209_SW_ENC_IPCM1_RIGHT_MASK (0xFF800000U)
#define VPU_HEVC_SWREG209_SW_ENC_IPCM1_RIGHT_SHIFT (23U)
#define VPU_HEVC_SWREG209_SW_ENC_IPCM1_RIGHT(x)  (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG209_SW_ENC_IPCM1_RIGHT_SHIFT)) & VPU_HEVC_SWREG209_SW_ENC_IPCM1_RIGHT_MASK)
/*! @} */

/*! @name SWREG210 - IPCM Control 1 */
/*! @{ */

#define VPU_HEVC_SWREG210_SW_ENC_IPCM2_LEFT_MASK (0xFF8U)
#define VPU_HEVC_SWREG210_SW_ENC_IPCM2_LEFT_SHIFT (3U)
#define VPU_HEVC_SWREG210_SW_ENC_IPCM2_LEFT(x)   (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG210_SW_ENC_IPCM2_LEFT_SHIFT)) & VPU_HEVC_SWREG210_SW_ENC_IPCM2_LEFT_MASK)
/*! @} */

/*! @name SWREG211 - IPCM Control 2 */
/*! @{ */

#define VPU_HEVC_SWREG211_SW_ENC_IPCM2_RIGHT_MASK (0xFF8U)
#define VPU_HEVC_SWREG211_SW_ENC_IPCM2_RIGHT_SHIFT (3U)
#define VPU_HEVC_SWREG211_SW_ENC_IPCM2_RIGHT(x)  (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG211_SW_ENC_IPCM2_RIGHT_SHIFT)) & VPU_HEVC_SWREG211_SW_ENC_IPCM2_RIGHT_MASK)
/*! @} */

/*! @name SWREG212 - IPCM Control 3 */
/*! @{ */

#define VPU_HEVC_SWREG212_SW_ENC_IPCM2_TOP_MASK  (0xFF8U)
#define VPU_HEVC_SWREG212_SW_ENC_IPCM2_TOP_SHIFT (3U)
#define VPU_HEVC_SWREG212_SW_ENC_IPCM2_TOP(x)    (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG212_SW_ENC_IPCM2_TOP_SHIFT)) & VPU_HEVC_SWREG212_SW_ENC_IPCM2_TOP_MASK)
/*! @} */

/*! @name SWREG213 - IPCM Control 4 */
/*! @{ */

#define VPU_HEVC_SWREG213_SW_ENC_IPCM2_BOTTOM_MASK (0x3FE0U)
#define VPU_HEVC_SWREG213_SW_ENC_IPCM2_BOTTOM_SHIFT (5U)
#define VPU_HEVC_SWREG213_SW_ENC_IPCM2_BOTTOM(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG213_SW_ENC_IPCM2_BOTTOM_SHIFT)) & VPU_HEVC_SWREG213_SW_ENC_IPCM2_BOTTOM_MASK)
/*! @} */

/*! @name SWREG214 - HW synthesis config register 2, read-only */
/*! @{ */

#define VPU_HEVC_SWREG214_SW_ENC_HWROIMAPVERSION_MASK (0x1C000000U)
#define VPU_HEVC_SWREG214_SW_ENC_HWROIMAPVERSION_SHIFT (26U)
/*! SW_ENC_HWROIMAPVERSION
 *  0b000..4 bit per pixel.
 *  0b001..8 bit per pixel
 */
#define VPU_HEVC_SWREG214_SW_ENC_HWROIMAPVERSION(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG214_SW_ENC_HWROIMAPVERSION_SHIFT)) & VPU_HEVC_SWREG214_SW_ENC_HWROIMAPVERSION_MASK)

#define VPU_HEVC_SWREG214_SW_ENC_HWINTRATU32SUPPORT_MASK (0x20000000U)
#define VPU_HEVC_SWREG214_SW_ENC_HWINTRATU32SUPPORT_SHIFT (29U)
/*! SW_ENC_HWINTRATU32SUPPORT
 *  0b0..not supported.
 *  0b1..supported
 */
#define VPU_HEVC_SWREG214_SW_ENC_HWINTRATU32SUPPORT(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG214_SW_ENC_HWINTRATU32SUPPORT_SHIFT)) & VPU_HEVC_SWREG214_SW_ENC_HWINTRATU32SUPPORT_MASK)

#define VPU_HEVC_SWREG214_SW_ENC_HWABSQPSUPPORT_MASK (0x40000000U)
#define VPU_HEVC_SWREG214_SW_ENC_HWABSQPSUPPORT_SHIFT (30U)
/*! SW_ENC_HWABSQPSUPPORT
 *  0b0..not supported.
 *  0b1..supported
 */
#define VPU_HEVC_SWREG214_SW_ENC_HWABSQPSUPPORT(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG214_SW_ENC_HWABSQPSUPPORT_SHIFT)) & VPU_HEVC_SWREG214_SW_ENC_HWABSQPSUPPORT_MASK)

#define VPU_HEVC_SWREG214_SW_ENC_HWLJPEGSUPPORT_MASK (0x80000000U)
#define VPU_HEVC_SWREG214_SW_ENC_HWLJPEGSUPPORT_SHIFT (31U)
/*! SW_ENC_HWLJPEGSUPPORT
 *  0b0..not supported.
 *  0b1..supported
 */
#define VPU_HEVC_SWREG214_SW_ENC_HWLJPEGSUPPORT(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG214_SW_ENC_HWLJPEGSUPPORT_SHIFT)) & VPU_HEVC_SWREG214_SW_ENC_HWLJPEGSUPPORT_MASK)
/*! @} */

/*! @name SWREG215 - AXI Information 0 */
/*! @{ */

#define VPU_HEVC_SWREG215_SW_ENC_TOTALARLEN_MASK (0xFFFFFFFFU)
#define VPU_HEVC_SWREG215_SW_ENC_TOTALARLEN_SHIFT (0U)
#define VPU_HEVC_SWREG215_SW_ENC_TOTALARLEN(x)   (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG215_SW_ENC_TOTALARLEN_SHIFT)) & VPU_HEVC_SWREG215_SW_ENC_TOTALARLEN_MASK)
/*! @} */

/*! @name SWREG216 - AXI Information 1 */
/*! @{ */

#define VPU_HEVC_SWREG216_SW_ENC_TOTALR_MASK     (0xFFFFFFFFU)
#define VPU_HEVC_SWREG216_SW_ENC_TOTALR_SHIFT    (0U)
#define VPU_HEVC_SWREG216_SW_ENC_TOTALR(x)       (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG216_SW_ENC_TOTALR_SHIFT)) & VPU_HEVC_SWREG216_SW_ENC_TOTALR_MASK)
/*! @} */

/*! @name SWREG217 - AXI Information 2 */
/*! @{ */

#define VPU_HEVC_SWREG217_SW_ENC_TOTALAR_MASK    (0xFFFFFFFFU)
#define VPU_HEVC_SWREG217_SW_ENC_TOTALAR_SHIFT   (0U)
#define VPU_HEVC_SWREG217_SW_ENC_TOTALAR(x)      (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG217_SW_ENC_TOTALAR_SHIFT)) & VPU_HEVC_SWREG217_SW_ENC_TOTALAR_MASK)
/*! @} */

/*! @name SWREG218 - AXI Information 3 */
/*! @{ */

#define VPU_HEVC_SWREG218_SW_ENC_TOTALRLAST_MASK (0xFFFFFFFFU)
#define VPU_HEVC_SWREG218_SW_ENC_TOTALRLAST_SHIFT (0U)
#define VPU_HEVC_SWREG218_SW_ENC_TOTALRLAST(x)   (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG218_SW_ENC_TOTALRLAST_SHIFT)) & VPU_HEVC_SWREG218_SW_ENC_TOTALRLAST_MASK)
/*! @} */

/*! @name SWREG219 - AXI Information 4 */
/*! @{ */

#define VPU_HEVC_SWREG219_SW_ENC_TOTALAWLEN_MASK (0xFFFFFFFFU)
#define VPU_HEVC_SWREG219_SW_ENC_TOTALAWLEN_SHIFT (0U)
#define VPU_HEVC_SWREG219_SW_ENC_TOTALAWLEN(x)   (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG219_SW_ENC_TOTALAWLEN_SHIFT)) & VPU_HEVC_SWREG219_SW_ENC_TOTALAWLEN_MASK)
/*! @} */

/*! @name SWREG220 - AXI Information 5 */
/*! @{ */

#define VPU_HEVC_SWREG220_SW_ENC_TOTALW_MASK     (0xFFFFFFFFU)
#define VPU_HEVC_SWREG220_SW_ENC_TOTALW_SHIFT    (0U)
#define VPU_HEVC_SWREG220_SW_ENC_TOTALW(x)       (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG220_SW_ENC_TOTALW_SHIFT)) & VPU_HEVC_SWREG220_SW_ENC_TOTALW_MASK)
/*! @} */

/*! @name SWREG221 - AXI Information 6 */
/*! @{ */

#define VPU_HEVC_SWREG221_SW_ENC_TOTALAW_MASK    (0xFFFFFFFFU)
#define VPU_HEVC_SWREG221_SW_ENC_TOTALAW_SHIFT   (0U)
#define VPU_HEVC_SWREG221_SW_ENC_TOTALAW(x)      (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG221_SW_ENC_TOTALAW_SHIFT)) & VPU_HEVC_SWREG221_SW_ENC_TOTALAW_MASK)
/*! @} */

/*! @name SWREG222 - AXI Information 7 */
/*! @{ */

#define VPU_HEVC_SWREG222_SW_ENC_TOTALWLAST_MASK (0xFFFFFFFFU)
#define VPU_HEVC_SWREG222_SW_ENC_TOTALWLAST_SHIFT (0U)
#define VPU_HEVC_SWREG222_SW_ENC_TOTALWLAST(x)   (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG222_SW_ENC_TOTALWLAST_SHIFT)) & VPU_HEVC_SWREG222_SW_ENC_TOTALWLAST_MASK)
/*! @} */

/*! @name SWREG223 - AXI Information 8 */
/*! @{ */

#define VPU_HEVC_SWREG223_SW_ENC_TOTALB_MASK     (0xFFFFFFFFU)
#define VPU_HEVC_SWREG223_SW_ENC_TOTALB_SHIFT    (0U)
#define VPU_HEVC_SWREG223_SW_ENC_TOTALB(x)       (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG223_SW_ENC_TOTALB_SHIFT)) & VPU_HEVC_SWREG223_SW_ENC_TOTALB_MASK)
/*! @} */

/*! @name SWREG224 - control register 4 */
/*! @{ */

#define VPU_HEVC_SWREG224_SW_ENC_CB_CONST_PIXEL_MASK (0x3FFU)
#define VPU_HEVC_SWREG224_SW_ENC_CB_CONST_PIXEL_SHIFT (0U)
#define VPU_HEVC_SWREG224_SW_ENC_CB_CONST_PIXEL(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG224_SW_ENC_CB_CONST_PIXEL_SHIFT)) & VPU_HEVC_SWREG224_SW_ENC_CB_CONST_PIXEL_MASK)

#define VPU_HEVC_SWREG224_SW_ENC_CR_CONST_PIXEL_MASK (0xFFC00U)
#define VPU_HEVC_SWREG224_SW_ENC_CR_CONST_PIXEL_SHIFT (10U)
#define VPU_HEVC_SWREG224_SW_ENC_CR_CONST_PIXEL(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG224_SW_ENC_CR_CONST_PIXEL_SHIFT)) & VPU_HEVC_SWREG224_SW_ENC_CR_CONST_PIXEL_MASK)

#define VPU_HEVC_SWREG224_SW_ENC_SKIPFRAME_EN_MASK (0x100000U)
#define VPU_HEVC_SWREG224_SW_ENC_SKIPFRAME_EN_SHIFT (20U)
/*! SW_ENC_SKIPFRAME_EN
 *  0b0..no.
 *  0b1..yes
 */
#define VPU_HEVC_SWREG224_SW_ENC_SKIPFRAME_EN(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG224_SW_ENC_SKIPFRAME_EN_SHIFT)) & VPU_HEVC_SWREG224_SW_ENC_SKIPFRAME_EN_MASK)

#define VPU_HEVC_SWREG224_SW_ENC_SSIM_EN_MASK    (0x200000U)
#define VPU_HEVC_SWREG224_SW_ENC_SSIM_EN_SHIFT   (21U)
/*! SW_ENC_SSIM_EN
 *  0b0..Disable.
 *  0b1..Enable
 */
#define VPU_HEVC_SWREG224_SW_ENC_SSIM_EN(x)      (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG224_SW_ENC_SSIM_EN_SHIFT)) & VPU_HEVC_SWREG224_SW_ENC_SSIM_EN_MASK)

#define VPU_HEVC_SWREG224_SW_ENC_CHROMA_CONST_EN_MASK (0x80000000U)
#define VPU_HEVC_SWREG224_SW_ENC_CHROMA_CONST_EN_SHIFT (31U)
/*! SW_ENC_CHROMA_CONST_EN
 *  0b0..no.
 *  0b1..yes.
 */
#define VPU_HEVC_SWREG224_SW_ENC_CHROMA_CONST_EN(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG224_SW_ENC_CHROMA_CONST_EN_SHIFT)) & VPU_HEVC_SWREG224_SW_ENC_CHROMA_CONST_EN_MASK)
/*! @} */

/*! @name SWREG225 - Tile Control */
/*! @{ */

#define VPU_HEVC_SWREG225_SW_ENC_ROIMAP_QPDELTA_VER_MASK (0x1C0U)
#define VPU_HEVC_SWREG225_SW_ENC_ROIMAP_QPDELTA_VER_SHIFT (6U)
#define VPU_HEVC_SWREG225_SW_ENC_ROIMAP_QPDELTA_VER(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG225_SW_ENC_ROIMAP_QPDELTA_VER_SHIFT)) & VPU_HEVC_SWREG225_SW_ENC_ROIMAP_QPDELTA_VER_MASK)

#define VPU_HEVC_SWREG225_SW_ENC_ROIMAP_CUCTRL_VER_MASK (0xE00U)
#define VPU_HEVC_SWREG225_SW_ENC_ROIMAP_CUCTRL_VER_SHIFT (9U)
#define VPU_HEVC_SWREG225_SW_ENC_ROIMAP_CUCTRL_VER(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG225_SW_ENC_ROIMAP_CUCTRL_VER_SHIFT)) & VPU_HEVC_SWREG225_SW_ENC_ROIMAP_CUCTRL_VER_MASK)

#define VPU_HEVC_SWREG225_SW_ENC_ROIMAP_CUCTRL_ENABLE_MASK (0x1000U)
#define VPU_HEVC_SWREG225_SW_ENC_ROIMAP_CUCTRL_ENABLE_SHIFT (12U)
/*! SW_ENC_ROIMAP_CUCTRL_ENABLE
 *  0b0..Disable.
 *  0b1..Enable
 */
#define VPU_HEVC_SWREG225_SW_ENC_ROIMAP_CUCTRL_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG225_SW_ENC_ROIMAP_CUCTRL_ENABLE_SHIFT)) & VPU_HEVC_SWREG225_SW_ENC_ROIMAP_CUCTRL_ENABLE_MASK)

#define VPU_HEVC_SWREG225_SW_ENC_ROIMAP_CUCTRL_INDEX_ENABLE_MASK (0x2000U)
#define VPU_HEVC_SWREG225_SW_ENC_ROIMAP_CUCTRL_INDEX_ENABLE_SHIFT (13U)
/*! SW_ENC_ROIMAP_CUCTRL_INDEX_ENABLE
 *  0b0..Disable.
 *  0b1..Enable
 */
#define VPU_HEVC_SWREG225_SW_ENC_ROIMAP_CUCTRL_INDEX_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG225_SW_ENC_ROIMAP_CUCTRL_INDEX_ENABLE_SHIFT)) & VPU_HEVC_SWREG225_SW_ENC_ROIMAP_CUCTRL_INDEX_ENABLE_MASK)

#define VPU_HEVC_SWREG225_SW_ENC_LOOP_FILTER_ACROSS_TILES_ENABLED_FLAG_MASK (0x4000U)
#define VPU_HEVC_SWREG225_SW_ENC_LOOP_FILTER_ACROSS_TILES_ENABLED_FLAG_SHIFT (14U)
/*! SW_ENC_LOOP_FILTER_ACROSS_TILES_ENABLED_FLAG
 *  0b0..disabled.
 *  0b1..enabled.
 */
#define VPU_HEVC_SWREG225_SW_ENC_LOOP_FILTER_ACROSS_TILES_ENABLED_FLAG(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG225_SW_ENC_LOOP_FILTER_ACROSS_TILES_ENABLED_FLAG_SHIFT)) & VPU_HEVC_SWREG225_SW_ENC_LOOP_FILTER_ACROSS_TILES_ENABLED_FLAG_MASK)

#define VPU_HEVC_SWREG225_SW_ENC_TILES_ENABLED_FLAG_MASK (0x8000U)
#define VPU_HEVC_SWREG225_SW_ENC_TILES_ENABLED_FLAG_SHIFT (15U)
/*! SW_ENC_TILES_ENABLED_FLAG
 *  0b0..disabled.
 *  0b1..enabled.
 */
#define VPU_HEVC_SWREG225_SW_ENC_TILES_ENABLED_FLAG(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG225_SW_ENC_TILES_ENABLED_FLAG_SHIFT)) & VPU_HEVC_SWREG225_SW_ENC_TILES_ENABLED_FLAG_MASK)

#define VPU_HEVC_SWREG225_SW_ENC_NUM_TILE_ROWS_MASK (0xFF0000U)
#define VPU_HEVC_SWREG225_SW_ENC_NUM_TILE_ROWS_SHIFT (16U)
#define VPU_HEVC_SWREG225_SW_ENC_NUM_TILE_ROWS(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG225_SW_ENC_NUM_TILE_ROWS_SHIFT)) & VPU_HEVC_SWREG225_SW_ENC_NUM_TILE_ROWS_MASK)

#define VPU_HEVC_SWREG225_SW_ENC_NUM_TILE_COLUMNS_MASK (0xFF000000U)
#define VPU_HEVC_SWREG225_SW_ENC_NUM_TILE_COLUMNS_SHIFT (24U)
#define VPU_HEVC_SWREG225_SW_ENC_NUM_TILE_COLUMNS(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG225_SW_ENC_NUM_TILE_COLUMNS_SHIFT)) & VPU_HEVC_SWREG225_SW_ENC_NUM_TILE_COLUMNS_MASK)
/*! @} */

/*! @name SWREG226 - HW synthesis config register 3, read-only */
/*! @{ */

#define VPU_HEVC_SWREG226_SW_ENC_HWDYNAMICMAXTUSIZE_MASK (0x1U)
#define VPU_HEVC_SWREG226_SW_ENC_HWDYNAMICMAXTUSIZE_SHIFT (0U)
/*! SW_ENC_HWDYNAMICMAXTUSIZE
 *  0b0..not supported.
 *  0b1..supported
 */
#define VPU_HEVC_SWREG226_SW_ENC_HWDYNAMICMAXTUSIZE(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG226_SW_ENC_HWDYNAMICMAXTUSIZE_SHIFT)) & VPU_HEVC_SWREG226_SW_ENC_HWDYNAMICMAXTUSIZE_MASK)

#define VPU_HEVC_SWREG226_SW_ENC_HWIFRAMEONLY_MASK (0x2U)
#define VPU_HEVC_SWREG226_SW_ENC_HWIFRAMEONLY_SHIFT (1U)
/*! SW_ENC_HWIFRAMEONLY
 *  0b0..support I/P/B frame.
 *  0b1..only support I frame
 */
#define VPU_HEVC_SWREG226_SW_ENC_HWIFRAMEONLY(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG226_SW_ENC_HWIFRAMEONLY_SHIFT)) & VPU_HEVC_SWREG226_SW_ENC_HWIFRAMEONLY_MASK)

#define VPU_HEVC_SWREG226_SW_ENC_HWSTREAMSEGMENTSUPPORT_MASK (0x4U)
#define VPU_HEVC_SWREG226_SW_ENC_HWSTREAMSEGMENTSUPPORT_SHIFT (2U)
/*! SW_ENC_HWSTREAMSEGMENTSUPPORT
 *  0b0..not supported.
 *  0b1..supported
 */
#define VPU_HEVC_SWREG226_SW_ENC_HWSTREAMSEGMENTSUPPORT(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG226_SW_ENC_HWSTREAMSEGMENTSUPPORT_SHIFT)) & VPU_HEVC_SWREG226_SW_ENC_HWSTREAMSEGMENTSUPPORT_MASK)

#define VPU_HEVC_SWREG226_SW_ENC_HWSTREAMBUFCHAIN_MASK (0x8U)
#define VPU_HEVC_SWREG226_SW_ENC_HWSTREAMBUFCHAIN_SHIFT (3U)
/*! SW_ENC_HWSTREAMBUFCHAIN
 *  0b0..not supported.
 *  0b1..supported
 */
#define VPU_HEVC_SWREG226_SW_ENC_HWSTREAMBUFCHAIN(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG226_SW_ENC_HWSTREAMBUFCHAIN_SHIFT)) & VPU_HEVC_SWREG226_SW_ENC_HWSTREAMBUFCHAIN_MASK)

#define VPU_HEVC_SWREG226_SW_ENC_HWINLOOPDSRATIO_MASK (0x10U)
#define VPU_HEVC_SWREG226_SW_ENC_HWINLOOPDSRATIO_SHIFT (4U)
/*! SW_ENC_HWINLOOPDSRATIO
 *  0b0..1:1
 *  0b1..1:2
 */
#define VPU_HEVC_SWREG226_SW_ENC_HWINLOOPDSRATIO(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG226_SW_ENC_HWINLOOPDSRATIO_SHIFT)) & VPU_HEVC_SWREG226_SW_ENC_HWINLOOPDSRATIO_MASK)

#define VPU_HEVC_SWREG226_SW_ENC_HWMULTIPASSSUPPORT_MASK (0x20U)
#define VPU_HEVC_SWREG226_SW_ENC_HWMULTIPASSSUPPORT_SHIFT (5U)
/*! SW_ENC_HWMULTIPASSSUPPORT
 *  0b0..not supported.
 *  0b1..supported
 */
#define VPU_HEVC_SWREG226_SW_ENC_HWMULTIPASSSUPPORT(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG226_SW_ENC_HWMULTIPASSSUPPORT_SHIFT)) & VPU_HEVC_SWREG226_SW_ENC_HWMULTIPASSSUPPORT_MASK)

#define VPU_HEVC_SWREG226_SW_ENC_HWRDOQSUPPORT_MASK (0x40U)
#define VPU_HEVC_SWREG226_SW_ENC_HWRDOQSUPPORT_SHIFT (6U)
/*! SW_ENC_HWRDOQSUPPORT
 *  0b0..not supported.
 *  0b1..supported
 */
#define VPU_HEVC_SWREG226_SW_ENC_HWRDOQSUPPORT(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG226_SW_ENC_HWRDOQSUPPORT_SHIFT)) & VPU_HEVC_SWREG226_SW_ENC_HWRDOQSUPPORT_MASK)

#define VPU_HEVC_SWREG226_SW_ENC_BFRAME_ME4N_HOR_SEARCHRANGE_MASK (0x180U)
#define VPU_HEVC_SWREG226_SW_ENC_BFRAME_ME4N_HOR_SEARCHRANGE_SHIFT (7U)
/*! SW_ENC_BFRAME_ME4N_HOR_SEARCHRANGE
 *  0b00..64.
 *  0b01..128.
 *  0b10..192.
 *  0b11..256
 */
#define VPU_HEVC_SWREG226_SW_ENC_BFRAME_ME4N_HOR_SEARCHRANGE(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG226_SW_ENC_BFRAME_ME4N_HOR_SEARCHRANGE_SHIFT)) & VPU_HEVC_SWREG226_SW_ENC_BFRAME_ME4N_HOR_SEARCHRANGE_MASK)

#define VPU_HEVC_SWREG226_SW_ENC_HWROI8SUPPORT_MASK (0x200U)
#define VPU_HEVC_SWREG226_SW_ENC_HWROI8SUPPORT_SHIFT (9U)
#define VPU_HEVC_SWREG226_SW_ENC_HWROI8SUPPORT(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG226_SW_ENC_HWROI8SUPPORT_SHIFT)) & VPU_HEVC_SWREG226_SW_ENC_HWROI8SUPPORT_MASK)

#define VPU_HEVC_SWREG226_SW_ENC_HWGMVSUPPORT_MASK (0x400U)
#define VPU_HEVC_SWREG226_SW_ENC_HWGMVSUPPORT_SHIFT (10U)
/*! SW_ENC_HWGMVSUPPORT
 *  0b0..not supported.
 *  0b1..supported
 */
#define VPU_HEVC_SWREG226_SW_ENC_HWGMVSUPPORT(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG226_SW_ENC_HWGMVSUPPORT_SHIFT)) & VPU_HEVC_SWREG226_SW_ENC_HWGMVSUPPORT_MASK)

#define VPU_HEVC_SWREG226_SW_ENC_HWJPEG422SUPPORT_MASK (0x800U)
#define VPU_HEVC_SWREG226_SW_ENC_HWJPEG422SUPPORT_SHIFT (11U)
/*! SW_ENC_HWJPEG422SUPPORT
 *  0b0..not supported.
 *  0b1..supported
 */
#define VPU_HEVC_SWREG226_SW_ENC_HWJPEG422SUPPORT(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG226_SW_ENC_HWJPEG422SUPPORT_SHIFT)) & VPU_HEVC_SWREG226_SW_ENC_HWJPEG422SUPPORT_MASK)

#define VPU_HEVC_SWREG226_SW_ENC_HWCTBRCVERSION_MASK (0x7000U)
#define VPU_HEVC_SWREG226_SW_ENC_HWCTBRCVERSION_SHIFT (12U)
#define VPU_HEVC_SWREG226_SW_ENC_HWCTBRCVERSION(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG226_SW_ENC_HWCTBRCVERSION_SHIFT)) & VPU_HEVC_SWREG226_SW_ENC_HWCTBRCVERSION_MASK)

#define VPU_HEVC_SWREG226_SW_ENC_ME_VERT_SEARCHRANGE_H264_MASK (0x1F8000U)
#define VPU_HEVC_SWREG226_SW_ENC_ME_VERT_SEARCHRANGE_H264_SHIFT (15U)
#define VPU_HEVC_SWREG226_SW_ENC_ME_VERT_SEARCHRANGE_H264(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG226_SW_ENC_ME_VERT_SEARCHRANGE_H264_SHIFT)) & VPU_HEVC_SWREG226_SW_ENC_ME_VERT_SEARCHRANGE_H264_MASK)

#define VPU_HEVC_SWREG226_SW_ENC_ME_VERT_SEARCHRANGE_HEVC_MASK (0x7E00000U)
#define VPU_HEVC_SWREG226_SW_ENC_ME_VERT_SEARCHRANGE_HEVC_SHIFT (21U)
#define VPU_HEVC_SWREG226_SW_ENC_ME_VERT_SEARCHRANGE_HEVC(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG226_SW_ENC_ME_VERT_SEARCHRANGE_HEVC_SHIFT)) & VPU_HEVC_SWREG226_SW_ENC_ME_VERT_SEARCHRANGE_HEVC_MASK)

#define VPU_HEVC_SWREG226_SW_ENC_HWCUINFORVERSION_MASK (0x38000000U)
#define VPU_HEVC_SWREG226_SW_ENC_HWCUINFORVERSION_SHIFT (27U)
#define VPU_HEVC_SWREG226_SW_ENC_HWCUINFORVERSION(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG226_SW_ENC_HWCUINFORVERSION_SHIFT)) & VPU_HEVC_SWREG226_SW_ENC_HWCUINFORVERSION_MASK)

#define VPU_HEVC_SWREG226_SW_ENC_HWP010REFSUPPORT_MASK (0x40000000U)
#define VPU_HEVC_SWREG226_SW_ENC_HWP010REFSUPPORT_SHIFT (30U)
/*! SW_ENC_HWP010REFSUPPORT
 *  0b0..normal format
 *  0b1..P010 tile raster format.
 */
#define VPU_HEVC_SWREG226_SW_ENC_HWP010REFSUPPORT(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG226_SW_ENC_HWP010REFSUPPORT_SHIFT)) & VPU_HEVC_SWREG226_SW_ENC_HWP010REFSUPPORT_MASK)

#define VPU_HEVC_SWREG226_SW_ENC_HWSSIMSUPPORT_MASK (0x80000000U)
#define VPU_HEVC_SWREG226_SW_ENC_HWSSIMSUPPORT_SHIFT (31U)
/*! SW_ENC_HWSSIMSUPPORT
 *  0b0..not supported.
 *  0b1..supported
 */
#define VPU_HEVC_SWREG226_SW_ENC_HWSSIMSUPPORT(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG226_SW_ENC_HWSSIMSUPPORT_SHIFT)) & VPU_HEVC_SWREG226_SW_ENC_HWSSIMSUPPORT_MASK)
/*! @} */

/*! @name SWREG235 - RPS encoding control 0 */
/*! @{ */

#define VPU_HEVC_SWREG235_SW_ENC_RPS_USED_BY_CUR_1_MASK (0x1U)
#define VPU_HEVC_SWREG235_SW_ENC_RPS_USED_BY_CUR_1_SHIFT (0U)
#define VPU_HEVC_SWREG235_SW_ENC_RPS_USED_BY_CUR_1(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG235_SW_ENC_RPS_USED_BY_CUR_1_SHIFT)) & VPU_HEVC_SWREG235_SW_ENC_RPS_USED_BY_CUR_1_MASK)

#define VPU_HEVC_SWREG235_SW_ENC_RPS_USED_BY_CUR_0_MASK (0x2U)
#define VPU_HEVC_SWREG235_SW_ENC_RPS_USED_BY_CUR_0_SHIFT (1U)
#define VPU_HEVC_SWREG235_SW_ENC_RPS_USED_BY_CUR_0(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG235_SW_ENC_RPS_USED_BY_CUR_0_SHIFT)) & VPU_HEVC_SWREG235_SW_ENC_RPS_USED_BY_CUR_0_MASK)

#define VPU_HEVC_SWREG235_SW_ENC_RPS_DELTA_POC_2_MASK (0xFFCU)
#define VPU_HEVC_SWREG235_SW_ENC_RPS_DELTA_POC_2_SHIFT (2U)
#define VPU_HEVC_SWREG235_SW_ENC_RPS_DELTA_POC_2(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG235_SW_ENC_RPS_DELTA_POC_2_SHIFT)) & VPU_HEVC_SWREG235_SW_ENC_RPS_DELTA_POC_2_MASK)

#define VPU_HEVC_SWREG235_SW_ENC_RPS_DELTA_POC_1_MASK (0x3FF000U)
#define VPU_HEVC_SWREG235_SW_ENC_RPS_DELTA_POC_1_SHIFT (12U)
#define VPU_HEVC_SWREG235_SW_ENC_RPS_DELTA_POC_1(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG235_SW_ENC_RPS_DELTA_POC_1_SHIFT)) & VPU_HEVC_SWREG235_SW_ENC_RPS_DELTA_POC_1_MASK)

#define VPU_HEVC_SWREG235_SW_ENC_RPS_DELTA_POC_0_MASK (0xFFC00000U)
#define VPU_HEVC_SWREG235_SW_ENC_RPS_DELTA_POC_0_SHIFT (22U)
#define VPU_HEVC_SWREG235_SW_ENC_RPS_DELTA_POC_0(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG235_SW_ENC_RPS_DELTA_POC_0_SHIFT)) & VPU_HEVC_SWREG235_SW_ENC_RPS_DELTA_POC_0_MASK)
/*! @} */

/*! @name SWREG236 - RPS encoding control 1 */
/*! @{ */

#define VPU_HEVC_SWREG236_SW_ENC_P010_REF_ENABLE_MASK (0x1000U)
#define VPU_HEVC_SWREG236_SW_ENC_P010_REF_ENABLE_SHIFT (12U)
/*! SW_ENC_P010_REF_ENABLE
 *  0b0..not supported.
 *  0b1..supported.
 */
#define VPU_HEVC_SWREG236_SW_ENC_P010_REF_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG236_SW_ENC_P010_REF_ENABLE_SHIFT)) & VPU_HEVC_SWREG236_SW_ENC_P010_REF_ENABLE_MASK)

#define VPU_HEVC_SWREG236_SW_ENC_SHORT_TERM_REF_PIC_SET_SPS_FLAG_MASK (0x2000U)
#define VPU_HEVC_SWREG236_SW_ENC_SHORT_TERM_REF_PIC_SET_SPS_FLAG_SHIFT (13U)
#define VPU_HEVC_SWREG236_SW_ENC_SHORT_TERM_REF_PIC_SET_SPS_FLAG(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG236_SW_ENC_SHORT_TERM_REF_PIC_SET_SPS_FLAG_SHIFT)) & VPU_HEVC_SWREG236_SW_ENC_SHORT_TERM_REF_PIC_SET_SPS_FLAG_MASK)

#define VPU_HEVC_SWREG236_SW_ENC_RPS_POS_PIC_NUM_MASK (0x1C000U)
#define VPU_HEVC_SWREG236_SW_ENC_RPS_POS_PIC_NUM_SHIFT (14U)
#define VPU_HEVC_SWREG236_SW_ENC_RPS_POS_PIC_NUM(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG236_SW_ENC_RPS_POS_PIC_NUM_SHIFT)) & VPU_HEVC_SWREG236_SW_ENC_RPS_POS_PIC_NUM_MASK)

#define VPU_HEVC_SWREG236_SW_ENC_RPS_NEG_PIC_NUM_MASK (0xE0000U)
#define VPU_HEVC_SWREG236_SW_ENC_RPS_NEG_PIC_NUM_SHIFT (17U)
#define VPU_HEVC_SWREG236_SW_ENC_RPS_NEG_PIC_NUM(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG236_SW_ENC_RPS_NEG_PIC_NUM_SHIFT)) & VPU_HEVC_SWREG236_SW_ENC_RPS_NEG_PIC_NUM_MASK)

#define VPU_HEVC_SWREG236_SW_ENC_RPS_USED_BY_CUR_3_MASK (0x100000U)
#define VPU_HEVC_SWREG236_SW_ENC_RPS_USED_BY_CUR_3_SHIFT (20U)
#define VPU_HEVC_SWREG236_SW_ENC_RPS_USED_BY_CUR_3(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG236_SW_ENC_RPS_USED_BY_CUR_3_SHIFT)) & VPU_HEVC_SWREG236_SW_ENC_RPS_USED_BY_CUR_3_MASK)

#define VPU_HEVC_SWREG236_SW_ENC_RPS_USED_BY_CUR_2_MASK (0x200000U)
#define VPU_HEVC_SWREG236_SW_ENC_RPS_USED_BY_CUR_2_SHIFT (21U)
#define VPU_HEVC_SWREG236_SW_ENC_RPS_USED_BY_CUR_2(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG236_SW_ENC_RPS_USED_BY_CUR_2_SHIFT)) & VPU_HEVC_SWREG236_SW_ENC_RPS_USED_BY_CUR_2_MASK)

#define VPU_HEVC_SWREG236_SW_ENC_RPS_DELTA_POC_3_MASK (0xFFC00000U)
#define VPU_HEVC_SWREG236_SW_ENC_RPS_DELTA_POC_3_SHIFT (22U)
#define VPU_HEVC_SWREG236_SW_ENC_RPS_DELTA_POC_3(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG236_SW_ENC_RPS_DELTA_POC_3_SHIFT)) & VPU_HEVC_SWREG236_SW_ENC_RPS_DELTA_POC_3_MASK)
/*! @} */

/*! @name SWREG237 - Stride Control */
/*! @{ */

#define VPU_HEVC_SWREG237_SW_ENC_DUMMYREADEN_MASK (0x800U)
#define VPU_HEVC_SWREG237_SW_ENC_DUMMYREADEN_SHIFT (11U)
#define VPU_HEVC_SWREG237_SW_ENC_DUMMYREADEN(x)  (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG237_SW_ENC_DUMMYREADEN_SHIFT)) & VPU_HEVC_SWREG237_SW_ENC_DUMMYREADEN_MASK)

#define VPU_HEVC_SWREG237_SW_ENC_REF_CH_STRIDE_MASK (0xFFFFF000U)
#define VPU_HEVC_SWREG237_SW_ENC_REF_CH_STRIDE_SHIFT (12U)
#define VPU_HEVC_SWREG237_SW_ENC_REF_CH_STRIDE(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG237_SW_ENC_REF_CH_STRIDE_SHIFT)) & VPU_HEVC_SWREG237_SW_ENC_REF_CH_STRIDE_MASK)
/*! @} */

/*! @name SWREG238 - Dummy Read */
/*! @{ */

#define VPU_HEVC_SWREG238_SW_ENC_DUMMYREADADDR_MASK (0xFFFFFFFFU)
#define VPU_HEVC_SWREG238_SW_ENC_DUMMYREADADDR_SHIFT (0U)
#define VPU_HEVC_SWREG238_SW_ENC_DUMMYREADADDR(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG238_SW_ENC_DUMMYREADADDR_SHIFT)) & VPU_HEVC_SWREG238_SW_ENC_DUMMYREADADDR_MASK)
/*! @} */

/*! @name SWREG239 - Base Address LSB of CTB MADs of current frame. */
/*! @{ */

#define VPU_HEVC_SWREG239_SW_ENC_CURRENT_CTB_MAD_BASE_MASK (0xFFFFFFFFU)
#define VPU_HEVC_SWREG239_SW_ENC_CURRENT_CTB_MAD_BASE_SHIFT (0U)
#define VPU_HEVC_SWREG239_SW_ENC_CURRENT_CTB_MAD_BASE(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG239_SW_ENC_CURRENT_CTB_MAD_BASE_SHIFT)) & VPU_HEVC_SWREG239_SW_ENC_CURRENT_CTB_MAD_BASE_MASK)
/*! @} */

/*! @name SWREG241 - Base Address LSB of CTB MADs of previous frame. */
/*! @{ */

#define VPU_HEVC_SWREG241_SW_ENC_PREVIOUS_CTB_MAD_BASE_MASK (0xFFFFFFFFU)
#define VPU_HEVC_SWREG241_SW_ENC_PREVIOUS_CTB_MAD_BASE_SHIFT (0U)
#define VPU_HEVC_SWREG241_SW_ENC_PREVIOUS_CTB_MAD_BASE(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG241_SW_ENC_PREVIOUS_CTB_MAD_BASE_SHIFT)) & VPU_HEVC_SWREG241_SW_ENC_PREVIOUS_CTB_MAD_BASE_MASK)
/*! @} */

/*! @name SWREG243 - CTB RC Control 0 */
/*! @{ */

#define VPU_HEVC_SWREG243_SW_ENC_CTB_RC_MODEL_PARAM0_MASK (0xFFFFF800U)
#define VPU_HEVC_SWREG243_SW_ENC_CTB_RC_MODEL_PARAM0_SHIFT (11U)
#define VPU_HEVC_SWREG243_SW_ENC_CTB_RC_MODEL_PARAM0(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG243_SW_ENC_CTB_RC_MODEL_PARAM0_SHIFT)) & VPU_HEVC_SWREG243_SW_ENC_CTB_RC_MODEL_PARAM0_MASK)
/*! @} */

/*! @name SWREG244 - CTB RC Control 1 */
/*! @{ */

#define VPU_HEVC_SWREG244_SW_ENC_ROI3_QP_TYPE_MASK (0x4U)
#define VPU_HEVC_SWREG244_SW_ENC_ROI3_QP_TYPE_SHIFT (2U)
/*! SW_ENC_ROI3_QP_TYPE
 *  0b0..delta
 *  0b1..Absolute value
 */
#define VPU_HEVC_SWREG244_SW_ENC_ROI3_QP_TYPE(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG244_SW_ENC_ROI3_QP_TYPE_SHIFT)) & VPU_HEVC_SWREG244_SW_ENC_ROI3_QP_TYPE_MASK)

#define VPU_HEVC_SWREG244_SW_ENC_ROI3_QP_VALUE_MASK (0x3F8U)
#define VPU_HEVC_SWREG244_SW_ENC_ROI3_QP_VALUE_SHIFT (3U)
#define VPU_HEVC_SWREG244_SW_ENC_ROI3_QP_VALUE(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG244_SW_ENC_ROI3_QP_VALUE_SHIFT)) & VPU_HEVC_SWREG244_SW_ENC_ROI3_QP_VALUE_MASK)

#define VPU_HEVC_SWREG244_SW_ENC_CTB_RC_MODEL_PARAM1_MASK (0xFFFFFC00U)
#define VPU_HEVC_SWREG244_SW_ENC_CTB_RC_MODEL_PARAM1_SHIFT (10U)
#define VPU_HEVC_SWREG244_SW_ENC_CTB_RC_MODEL_PARAM1(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG244_SW_ENC_CTB_RC_MODEL_PARAM1_SHIFT)) & VPU_HEVC_SWREG244_SW_ENC_CTB_RC_MODEL_PARAM1_MASK)
/*! @} */

/*! @name SWREG245 - CTB RC Control 2 */
/*! @{ */

#define VPU_HEVC_SWREG245_SW_ENC_CTB_RC_ROW_FACTOR_MASK (0x3FFFCU)
#define VPU_HEVC_SWREG245_SW_ENC_CTB_RC_ROW_FACTOR_SHIFT (2U)
#define VPU_HEVC_SWREG245_SW_ENC_CTB_RC_ROW_FACTOR(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG245_SW_ENC_CTB_RC_ROW_FACTOR_SHIFT)) & VPU_HEVC_SWREG245_SW_ENC_CTB_RC_ROW_FACTOR_MASK)

#define VPU_HEVC_SWREG245_SW_ENC_CTB_RC_MODEL_PARAM_MIN_MASK (0xFFFC0000U)
#define VPU_HEVC_SWREG245_SW_ENC_CTB_RC_MODEL_PARAM_MIN_SHIFT (18U)
#define VPU_HEVC_SWREG245_SW_ENC_CTB_RC_MODEL_PARAM_MIN(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG245_SW_ENC_CTB_RC_MODEL_PARAM_MIN_SHIFT)) & VPU_HEVC_SWREG245_SW_ENC_CTB_RC_MODEL_PARAM_MIN_MASK)
/*! @} */

/*! @name SWREG246 - CTB RC Control 3 */
/*! @{ */

#define VPU_HEVC_SWREG246_SW_ENC_CTB_RC_DELAY_MASK (0x38U)
#define VPU_HEVC_SWREG246_SW_ENC_CTB_RC_DELAY_SHIFT (3U)
#define VPU_HEVC_SWREG246_SW_ENC_CTB_RC_DELAY(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG246_SW_ENC_CTB_RC_DELAY_SHIFT)) & VPU_HEVC_SWREG246_SW_ENC_CTB_RC_DELAY_MASK)

#define VPU_HEVC_SWREG246_SW_ENC_AXI_WRITE_OUTSTANDING_NUM_MASK (0x3FC0U)
#define VPU_HEVC_SWREG246_SW_ENC_AXI_WRITE_OUTSTANDING_NUM_SHIFT (6U)
#define VPU_HEVC_SWREG246_SW_ENC_AXI_WRITE_OUTSTANDING_NUM(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG246_SW_ENC_AXI_WRITE_OUTSTANDING_NUM_SHIFT)) & VPU_HEVC_SWREG246_SW_ENC_AXI_WRITE_OUTSTANDING_NUM_MASK)

#define VPU_HEVC_SWREG246_SW_ENC_CTB_RC_QP_STEP_MASK (0xFFFFC000U)
#define VPU_HEVC_SWREG246_SW_ENC_CTB_RC_QP_STEP_SHIFT (14U)
#define VPU_HEVC_SWREG246_SW_ENC_CTB_RC_QP_STEP(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG246_SW_ENC_CTB_RC_QP_STEP_SHIFT)) & VPU_HEVC_SWREG246_SW_ENC_CTB_RC_QP_STEP_MASK)
/*! @} */

/*! @name SWREG247 - CTB RC Control 4 */
/*! @{ */

#define VPU_HEVC_SWREG247_SW_ENC_CTB_RC_PREV_MAD_VALID_MASK (0x2U)
#define VPU_HEVC_SWREG247_SW_ENC_CTB_RC_PREV_MAD_VALID_SHIFT (1U)
/*! SW_ENC_CTB_RC_PREV_MAD_VALID
 *  0b0..no
 *  0b1..yes.
 */
#define VPU_HEVC_SWREG247_SW_ENC_CTB_RC_PREV_MAD_VALID(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG247_SW_ENC_CTB_RC_PREV_MAD_VALID_SHIFT)) & VPU_HEVC_SWREG247_SW_ENC_CTB_RC_PREV_MAD_VALID_MASK)

#define VPU_HEVC_SWREG247_SW_ENC_PREV_PIC_LUM_MAD_MASK (0xFFFFFFC0U)
#define VPU_HEVC_SWREG247_SW_ENC_PREV_PIC_LUM_MAD_SHIFT (6U)
#define VPU_HEVC_SWREG247_SW_ENC_PREV_PIC_LUM_MAD(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG247_SW_ENC_PREV_PIC_LUM_MAD_SHIFT)) & VPU_HEVC_SWREG247_SW_ENC_PREV_PIC_LUM_MAD_MASK)
/*! @} */

/*! @name SWREG248 - CTB RC Control 5 */
/*! @{ */

#define VPU_HEVC_SWREG248_SW_ENC_ROI4_QP_TYPE_MASK (0x1U)
#define VPU_HEVC_SWREG248_SW_ENC_ROI4_QP_TYPE_SHIFT (0U)
/*! SW_ENC_ROI4_QP_TYPE
 *  0b0..delta
 *  0b1..Absolute value
 */
#define VPU_HEVC_SWREG248_SW_ENC_ROI4_QP_TYPE(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG248_SW_ENC_ROI4_QP_TYPE_SHIFT)) & VPU_HEVC_SWREG248_SW_ENC_ROI4_QP_TYPE_MASK)

#define VPU_HEVC_SWREG248_SW_ENC_ROI4_QP_VALUE_MASK (0xFEU)
#define VPU_HEVC_SWREG248_SW_ENC_ROI4_QP_VALUE_SHIFT (1U)
#define VPU_HEVC_SWREG248_SW_ENC_ROI4_QP_VALUE(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG248_SW_ENC_ROI4_QP_VALUE_SHIFT)) & VPU_HEVC_SWREG248_SW_ENC_ROI4_QP_VALUE_MASK)

#define VPU_HEVC_SWREG248_SW_ENC_CTB_QP_SUM_FOR_RC_MASK (0xFFFFFF00U)
#define VPU_HEVC_SWREG248_SW_ENC_CTB_QP_SUM_FOR_RC_SHIFT (8U)
#define VPU_HEVC_SWREG248_SW_ENC_CTB_QP_SUM_FOR_RC(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG248_SW_ENC_CTB_QP_SUM_FOR_RC_SHIFT)) & VPU_HEVC_SWREG248_SW_ENC_CTB_QP_SUM_FOR_RC_MASK)
/*! @} */

/*! @name SWREG249 - register extension for 8K width */
/*! @{ */

#define VPU_HEVC_SWREG249_SW_ENC_IPCM2_BOTTOM_MSB_MASK (0x8U)
#define VPU_HEVC_SWREG249_SW_ENC_IPCM2_BOTTOM_MSB_SHIFT (3U)
#define VPU_HEVC_SWREG249_SW_ENC_IPCM2_BOTTOM_MSB(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG249_SW_ENC_IPCM2_BOTTOM_MSB_SHIFT)) & VPU_HEVC_SWREG249_SW_ENC_IPCM2_BOTTOM_MSB_MASK)

#define VPU_HEVC_SWREG249_SW_ENC_IPCM2_TOP_MSB_MASK (0x10U)
#define VPU_HEVC_SWREG249_SW_ENC_IPCM2_TOP_MSB_SHIFT (4U)
#define VPU_HEVC_SWREG249_SW_ENC_IPCM2_TOP_MSB(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG249_SW_ENC_IPCM2_TOP_MSB_SHIFT)) & VPU_HEVC_SWREG249_SW_ENC_IPCM2_TOP_MSB_MASK)

#define VPU_HEVC_SWREG249_SW_ENC_IPCM2_RIGHT_MSB_MASK (0x20U)
#define VPU_HEVC_SWREG249_SW_ENC_IPCM2_RIGHT_MSB_SHIFT (5U)
#define VPU_HEVC_SWREG249_SW_ENC_IPCM2_RIGHT_MSB(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG249_SW_ENC_IPCM2_RIGHT_MSB_SHIFT)) & VPU_HEVC_SWREG249_SW_ENC_IPCM2_RIGHT_MSB_MASK)

#define VPU_HEVC_SWREG249_SW_ENC_IPCM2_LEFT_MSB_MASK (0x40U)
#define VPU_HEVC_SWREG249_SW_ENC_IPCM2_LEFT_MSB_SHIFT (6U)
#define VPU_HEVC_SWREG249_SW_ENC_IPCM2_LEFT_MSB(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG249_SW_ENC_IPCM2_LEFT_MSB_SHIFT)) & VPU_HEVC_SWREG249_SW_ENC_IPCM2_LEFT_MSB_MASK)

#define VPU_HEVC_SWREG249_SW_ENC_IPCM1_BOTTOM_MSB_MASK (0x80U)
#define VPU_HEVC_SWREG249_SW_ENC_IPCM1_BOTTOM_MSB_SHIFT (7U)
#define VPU_HEVC_SWREG249_SW_ENC_IPCM1_BOTTOM_MSB(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG249_SW_ENC_IPCM1_BOTTOM_MSB_SHIFT)) & VPU_HEVC_SWREG249_SW_ENC_IPCM1_BOTTOM_MSB_MASK)

#define VPU_HEVC_SWREG249_SW_ENC_IPCM1_TOP_MSB_MASK (0x100U)
#define VPU_HEVC_SWREG249_SW_ENC_IPCM1_TOP_MSB_SHIFT (8U)
#define VPU_HEVC_SWREG249_SW_ENC_IPCM1_TOP_MSB(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG249_SW_ENC_IPCM1_TOP_MSB_SHIFT)) & VPU_HEVC_SWREG249_SW_ENC_IPCM1_TOP_MSB_MASK)

#define VPU_HEVC_SWREG249_SW_ENC_IPCM1_RIGHT_MSB_MASK (0x200U)
#define VPU_HEVC_SWREG249_SW_ENC_IPCM1_RIGHT_MSB_SHIFT (9U)
#define VPU_HEVC_SWREG249_SW_ENC_IPCM1_RIGHT_MSB(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG249_SW_ENC_IPCM1_RIGHT_MSB_SHIFT)) & VPU_HEVC_SWREG249_SW_ENC_IPCM1_RIGHT_MSB_MASK)

#define VPU_HEVC_SWREG249_SW_ENC_IPCM1_LEFT_MSB_MASK (0x400U)
#define VPU_HEVC_SWREG249_SW_ENC_IPCM1_LEFT_MSB_SHIFT (10U)
#define VPU_HEVC_SWREG249_SW_ENC_IPCM1_LEFT_MSB(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG249_SW_ENC_IPCM1_LEFT_MSB_SHIFT)) & VPU_HEVC_SWREG249_SW_ENC_IPCM1_LEFT_MSB_MASK)

#define VPU_HEVC_SWREG249_SW_ENC_PIC_WIDTH_MSB2_MASK (0x800U)
#define VPU_HEVC_SWREG249_SW_ENC_PIC_WIDTH_MSB2_SHIFT (11U)
#define VPU_HEVC_SWREG249_SW_ENC_PIC_WIDTH_MSB2(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG249_SW_ENC_PIC_WIDTH_MSB2_SHIFT)) & VPU_HEVC_SWREG249_SW_ENC_PIC_WIDTH_MSB2_MASK)

#define VPU_HEVC_SWREG249_SW_ENC_ROI2_BOTTOM_MSB2_MASK (0x1000U)
#define VPU_HEVC_SWREG249_SW_ENC_ROI2_BOTTOM_MSB2_SHIFT (12U)
#define VPU_HEVC_SWREG249_SW_ENC_ROI2_BOTTOM_MSB2(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG249_SW_ENC_ROI2_BOTTOM_MSB2_SHIFT)) & VPU_HEVC_SWREG249_SW_ENC_ROI2_BOTTOM_MSB2_MASK)

#define VPU_HEVC_SWREG249_SW_ENC_ROI2_TOP_MSB2_MASK (0x2000U)
#define VPU_HEVC_SWREG249_SW_ENC_ROI2_TOP_MSB2_SHIFT (13U)
#define VPU_HEVC_SWREG249_SW_ENC_ROI2_TOP_MSB2(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG249_SW_ENC_ROI2_TOP_MSB2_SHIFT)) & VPU_HEVC_SWREG249_SW_ENC_ROI2_TOP_MSB2_MASK)

#define VPU_HEVC_SWREG249_SW_ENC_ROI2_RIGHT_MSB2_MASK (0x4000U)
#define VPU_HEVC_SWREG249_SW_ENC_ROI2_RIGHT_MSB2_SHIFT (14U)
#define VPU_HEVC_SWREG249_SW_ENC_ROI2_RIGHT_MSB2(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG249_SW_ENC_ROI2_RIGHT_MSB2_SHIFT)) & VPU_HEVC_SWREG249_SW_ENC_ROI2_RIGHT_MSB2_MASK)

#define VPU_HEVC_SWREG249_SW_ENC_ROI2_LEFT_MSB2_MASK (0x8000U)
#define VPU_HEVC_SWREG249_SW_ENC_ROI2_LEFT_MSB2_SHIFT (15U)
#define VPU_HEVC_SWREG249_SW_ENC_ROI2_LEFT_MSB2(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG249_SW_ENC_ROI2_LEFT_MSB2_SHIFT)) & VPU_HEVC_SWREG249_SW_ENC_ROI2_LEFT_MSB2_MASK)

#define VPU_HEVC_SWREG249_SW_ENC_ROI1_BOTTOM_MSB2_MASK (0x10000U)
#define VPU_HEVC_SWREG249_SW_ENC_ROI1_BOTTOM_MSB2_SHIFT (16U)
#define VPU_HEVC_SWREG249_SW_ENC_ROI1_BOTTOM_MSB2(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG249_SW_ENC_ROI1_BOTTOM_MSB2_SHIFT)) & VPU_HEVC_SWREG249_SW_ENC_ROI1_BOTTOM_MSB2_MASK)

#define VPU_HEVC_SWREG249_SW_ENC_ROI1_TOP_MSB2_MASK (0x20000U)
#define VPU_HEVC_SWREG249_SW_ENC_ROI1_TOP_MSB2_SHIFT (17U)
#define VPU_HEVC_SWREG249_SW_ENC_ROI1_TOP_MSB2(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG249_SW_ENC_ROI1_TOP_MSB2_SHIFT)) & VPU_HEVC_SWREG249_SW_ENC_ROI1_TOP_MSB2_MASK)

#define VPU_HEVC_SWREG249_SW_ENC_ROI1_RIGHT_MSB2_MASK (0x40000U)
#define VPU_HEVC_SWREG249_SW_ENC_ROI1_RIGHT_MSB2_SHIFT (18U)
#define VPU_HEVC_SWREG249_SW_ENC_ROI1_RIGHT_MSB2(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG249_SW_ENC_ROI1_RIGHT_MSB2_SHIFT)) & VPU_HEVC_SWREG249_SW_ENC_ROI1_RIGHT_MSB2_MASK)

#define VPU_HEVC_SWREG249_SW_ENC_ROI1_LEFT_MSB2_MASK (0x80000U)
#define VPU_HEVC_SWREG249_SW_ENC_ROI1_LEFT_MSB2_SHIFT (19U)
#define VPU_HEVC_SWREG249_SW_ENC_ROI1_LEFT_MSB2(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG249_SW_ENC_ROI1_LEFT_MSB2_SHIFT)) & VPU_HEVC_SWREG249_SW_ENC_ROI1_LEFT_MSB2_MASK)

#define VPU_HEVC_SWREG249_SW_ENC_INTRA_AREA_BOTTOM_MSB2_MASK (0x100000U)
#define VPU_HEVC_SWREG249_SW_ENC_INTRA_AREA_BOTTOM_MSB2_SHIFT (20U)
#define VPU_HEVC_SWREG249_SW_ENC_INTRA_AREA_BOTTOM_MSB2(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG249_SW_ENC_INTRA_AREA_BOTTOM_MSB2_SHIFT)) & VPU_HEVC_SWREG249_SW_ENC_INTRA_AREA_BOTTOM_MSB2_MASK)

#define VPU_HEVC_SWREG249_SW_ENC_INTRA_AREA_TOP_MSB2_MASK (0x200000U)
#define VPU_HEVC_SWREG249_SW_ENC_INTRA_AREA_TOP_MSB2_SHIFT (21U)
#define VPU_HEVC_SWREG249_SW_ENC_INTRA_AREA_TOP_MSB2(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG249_SW_ENC_INTRA_AREA_TOP_MSB2_SHIFT)) & VPU_HEVC_SWREG249_SW_ENC_INTRA_AREA_TOP_MSB2_MASK)

#define VPU_HEVC_SWREG249_SW_ENC_INTRA_AREA_RIGHT_MSB2_MASK (0x400000U)
#define VPU_HEVC_SWREG249_SW_ENC_INTRA_AREA_RIGHT_MSB2_SHIFT (22U)
#define VPU_HEVC_SWREG249_SW_ENC_INTRA_AREA_RIGHT_MSB2(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG249_SW_ENC_INTRA_AREA_RIGHT_MSB2_SHIFT)) & VPU_HEVC_SWREG249_SW_ENC_INTRA_AREA_RIGHT_MSB2_MASK)

#define VPU_HEVC_SWREG249_SW_ENC_INTRA_AREA_LEFT_MSB2_MASK (0x800000U)
#define VPU_HEVC_SWREG249_SW_ENC_INTRA_AREA_LEFT_MSB2_SHIFT (23U)
#define VPU_HEVC_SWREG249_SW_ENC_INTRA_AREA_LEFT_MSB2(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG249_SW_ENC_INTRA_AREA_LEFT_MSB2_SHIFT)) & VPU_HEVC_SWREG249_SW_ENC_INTRA_AREA_LEFT_MSB2_MASK)

#define VPU_HEVC_SWREG249_SW_ENC_CIR_INTERVAL_MSB2_MASK (0x3000000U)
#define VPU_HEVC_SWREG249_SW_ENC_CIR_INTERVAL_MSB2_SHIFT (24U)
#define VPU_HEVC_SWREG249_SW_ENC_CIR_INTERVAL_MSB2(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG249_SW_ENC_CIR_INTERVAL_MSB2_SHIFT)) & VPU_HEVC_SWREG249_SW_ENC_CIR_INTERVAL_MSB2_MASK)

#define VPU_HEVC_SWREG249_SW_ENC_CIR_START_MSB2_MASK (0xC000000U)
#define VPU_HEVC_SWREG249_SW_ENC_CIR_START_MSB2_SHIFT (26U)
#define VPU_HEVC_SWREG249_SW_ENC_CIR_START_MSB2(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG249_SW_ENC_CIR_START_MSB2_SHIFT)) & VPU_HEVC_SWREG249_SW_ENC_CIR_START_MSB2_MASK)

#define VPU_HEVC_SWREG249_SW_ENC_SLICE_SIZE_MSB2_MASK (0x10000000U)
#define VPU_HEVC_SWREG249_SW_ENC_SLICE_SIZE_MSB2_SHIFT (28U)
#define VPU_HEVC_SWREG249_SW_ENC_SLICE_SIZE_MSB2(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG249_SW_ENC_SLICE_SIZE_MSB2_SHIFT)) & VPU_HEVC_SWREG249_SW_ENC_SLICE_SIZE_MSB2_MASK)

#define VPU_HEVC_SWREG249_SW_ENC_NUM_SLICES_READY_MSB2_MASK (0x20000000U)
#define VPU_HEVC_SWREG249_SW_ENC_NUM_SLICES_READY_MSB2_SHIFT (29U)
#define VPU_HEVC_SWREG249_SW_ENC_NUM_SLICES_READY_MSB2(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG249_SW_ENC_NUM_SLICES_READY_MSB2_SHIFT)) & VPU_HEVC_SWREG249_SW_ENC_NUM_SLICES_READY_MSB2_MASK)

#define VPU_HEVC_SWREG249_SW_ENC_ENCODED_CTB_NUMBER_MSB2_MASK (0xC0000000U)
#define VPU_HEVC_SWREG249_SW_ENC_ENCODED_CTB_NUMBER_MSB2_SHIFT (30U)
#define VPU_HEVC_SWREG249_SW_ENC_ENCODED_CTB_NUMBER_MSB2(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG249_SW_ENC_ENCODED_CTB_NUMBER_MSB2_SHIFT)) & VPU_HEVC_SWREG249_SW_ENC_ENCODED_CTB_NUMBER_MSB2_MASK)
/*! @} */

/*! @name SWREG250 - Global MV Control 0 */
/*! @{ */

#define VPU_HEVC_SWREG250_SW_ENC_GLOBAL_VERTICAL_MV_L0_MASK (0x3FFF0U)
#define VPU_HEVC_SWREG250_SW_ENC_GLOBAL_VERTICAL_MV_L0_SHIFT (4U)
#define VPU_HEVC_SWREG250_SW_ENC_GLOBAL_VERTICAL_MV_L0(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG250_SW_ENC_GLOBAL_VERTICAL_MV_L0_SHIFT)) & VPU_HEVC_SWREG250_SW_ENC_GLOBAL_VERTICAL_MV_L0_MASK)

#define VPU_HEVC_SWREG250_SW_ENC_GLOBAL_HORIZONTAL_MV_L0_MASK (0xFFFC0000U)
#define VPU_HEVC_SWREG250_SW_ENC_GLOBAL_HORIZONTAL_MV_L0_SHIFT (18U)
#define VPU_HEVC_SWREG250_SW_ENC_GLOBAL_HORIZONTAL_MV_L0(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG250_SW_ENC_GLOBAL_HORIZONTAL_MV_L0_SHIFT)) & VPU_HEVC_SWREG250_SW_ENC_GLOBAL_HORIZONTAL_MV_L0_MASK)
/*! @} */

/*! @name SWREG251 - Global MV Control 1 */
/*! @{ */

#define VPU_HEVC_SWREG251_SW_ENC_GLOBAL_VERTICAL_MV_L1_MASK (0x3FFF0U)
#define VPU_HEVC_SWREG251_SW_ENC_GLOBAL_VERTICAL_MV_L1_SHIFT (4U)
#define VPU_HEVC_SWREG251_SW_ENC_GLOBAL_VERTICAL_MV_L1(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG251_SW_ENC_GLOBAL_VERTICAL_MV_L1_SHIFT)) & VPU_HEVC_SWREG251_SW_ENC_GLOBAL_VERTICAL_MV_L1_MASK)

#define VPU_HEVC_SWREG251_SW_ENC_GLOBAL_HORIZONTAL_MV_L1_MASK (0xFFFC0000U)
#define VPU_HEVC_SWREG251_SW_ENC_GLOBAL_HORIZONTAL_MV_L1_SHIFT (18U)
#define VPU_HEVC_SWREG251_SW_ENC_GLOBAL_HORIZONTAL_MV_L1(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG251_SW_ENC_GLOBAL_HORIZONTAL_MV_L1_SHIFT)) & VPU_HEVC_SWREG251_SW_ENC_GLOBAL_HORIZONTAL_MV_L1_MASK)
/*! @} */

/*! @name SWREG252 - ROI3 Area */
/*! @{ */

#define VPU_HEVC_SWREG252_SW_ENC_ROI3_RIGHT_MASK (0xFFCU)
#define VPU_HEVC_SWREG252_SW_ENC_ROI3_RIGHT_SHIFT (2U)
#define VPU_HEVC_SWREG252_SW_ENC_ROI3_RIGHT(x)   (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG252_SW_ENC_ROI3_RIGHT_SHIFT)) & VPU_HEVC_SWREG252_SW_ENC_ROI3_RIGHT_MASK)

#define VPU_HEVC_SWREG252_SW_ENC_ROI3_TOP_MASK   (0x3FF000U)
#define VPU_HEVC_SWREG252_SW_ENC_ROI3_TOP_SHIFT  (12U)
#define VPU_HEVC_SWREG252_SW_ENC_ROI3_TOP(x)     (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG252_SW_ENC_ROI3_TOP_SHIFT)) & VPU_HEVC_SWREG252_SW_ENC_ROI3_TOP_MASK)

#define VPU_HEVC_SWREG252_SW_ENC_ROI3_LEFT_MASK  (0xFFC00000U)
#define VPU_HEVC_SWREG252_SW_ENC_ROI3_LEFT_SHIFT (22U)
#define VPU_HEVC_SWREG252_SW_ENC_ROI3_LEFT(x)    (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG252_SW_ENC_ROI3_LEFT_SHIFT)) & VPU_HEVC_SWREG252_SW_ENC_ROI3_LEFT_MASK)
/*! @} */

/*! @name SWREG253 - ROI3&4 Area */
/*! @{ */

#define VPU_HEVC_SWREG253_SW_ENC_ROI4_TOP_MASK   (0xFFCU)
#define VPU_HEVC_SWREG253_SW_ENC_ROI4_TOP_SHIFT  (2U)
#define VPU_HEVC_SWREG253_SW_ENC_ROI4_TOP(x)     (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG253_SW_ENC_ROI4_TOP_SHIFT)) & VPU_HEVC_SWREG253_SW_ENC_ROI4_TOP_MASK)

#define VPU_HEVC_SWREG253_SW_ENC_ROI4_LEFT_MASK  (0x3FF000U)
#define VPU_HEVC_SWREG253_SW_ENC_ROI4_LEFT_SHIFT (12U)
#define VPU_HEVC_SWREG253_SW_ENC_ROI4_LEFT(x)    (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG253_SW_ENC_ROI4_LEFT_SHIFT)) & VPU_HEVC_SWREG253_SW_ENC_ROI4_LEFT_MASK)

#define VPU_HEVC_SWREG253_SW_ENC_ROI3_BOTTOM_MASK (0xFFC00000U)
#define VPU_HEVC_SWREG253_SW_ENC_ROI3_BOTTOM_SHIFT (22U)
#define VPU_HEVC_SWREG253_SW_ENC_ROI3_BOTTOM(x)  (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG253_SW_ENC_ROI3_BOTTOM_SHIFT)) & VPU_HEVC_SWREG253_SW_ENC_ROI3_BOTTOM_MASK)
/*! @} */

/*! @name SWREG254 - ROI4&5 Area */
/*! @{ */

#define VPU_HEVC_SWREG254_SW_ENC_ROI5_LEFT_MASK  (0xFFCU)
#define VPU_HEVC_SWREG254_SW_ENC_ROI5_LEFT_SHIFT (2U)
#define VPU_HEVC_SWREG254_SW_ENC_ROI5_LEFT(x)    (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG254_SW_ENC_ROI5_LEFT_SHIFT)) & VPU_HEVC_SWREG254_SW_ENC_ROI5_LEFT_MASK)

#define VPU_HEVC_SWREG254_SW_ENC_ROI4_BOTTOM_MASK (0x3FF000U)
#define VPU_HEVC_SWREG254_SW_ENC_ROI4_BOTTOM_SHIFT (12U)
#define VPU_HEVC_SWREG254_SW_ENC_ROI4_BOTTOM(x)  (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG254_SW_ENC_ROI4_BOTTOM_SHIFT)) & VPU_HEVC_SWREG254_SW_ENC_ROI4_BOTTOM_MASK)

#define VPU_HEVC_SWREG254_SW_ENC_ROI4_RIGHT_MASK (0xFFC00000U)
#define VPU_HEVC_SWREG254_SW_ENC_ROI4_RIGHT_SHIFT (22U)
#define VPU_HEVC_SWREG254_SW_ENC_ROI4_RIGHT(x)   (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG254_SW_ENC_ROI4_RIGHT_SHIFT)) & VPU_HEVC_SWREG254_SW_ENC_ROI4_RIGHT_MASK)
/*! @} */

/*! @name SWREG255 - ROI5 Area */
/*! @{ */

#define VPU_HEVC_SWREG255_SW_ENC_ROI5_BOTTOM_MASK (0xFFCU)
#define VPU_HEVC_SWREG255_SW_ENC_ROI5_BOTTOM_SHIFT (2U)
#define VPU_HEVC_SWREG255_SW_ENC_ROI5_BOTTOM(x)  (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG255_SW_ENC_ROI5_BOTTOM_SHIFT)) & VPU_HEVC_SWREG255_SW_ENC_ROI5_BOTTOM_MASK)

#define VPU_HEVC_SWREG255_SW_ENC_ROI5_RIGHT_MASK (0x3FF000U)
#define VPU_HEVC_SWREG255_SW_ENC_ROI5_RIGHT_SHIFT (12U)
#define VPU_HEVC_SWREG255_SW_ENC_ROI5_RIGHT(x)   (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG255_SW_ENC_ROI5_RIGHT_SHIFT)) & VPU_HEVC_SWREG255_SW_ENC_ROI5_RIGHT_MASK)

#define VPU_HEVC_SWREG255_SW_ENC_ROI5_TOP_MASK   (0xFFC00000U)
#define VPU_HEVC_SWREG255_SW_ENC_ROI5_TOP_SHIFT  (22U)
#define VPU_HEVC_SWREG255_SW_ENC_ROI5_TOP(x)     (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG255_SW_ENC_ROI5_TOP_SHIFT)) & VPU_HEVC_SWREG255_SW_ENC_ROI5_TOP_MASK)
/*! @} */

/*! @name SWREG256 - ROI6 Area */
/*! @{ */

#define VPU_HEVC_SWREG256_SW_ENC_ROI6_RIGHT_MASK (0xFFCU)
#define VPU_HEVC_SWREG256_SW_ENC_ROI6_RIGHT_SHIFT (2U)
#define VPU_HEVC_SWREG256_SW_ENC_ROI6_RIGHT(x)   (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG256_SW_ENC_ROI6_RIGHT_SHIFT)) & VPU_HEVC_SWREG256_SW_ENC_ROI6_RIGHT_MASK)

#define VPU_HEVC_SWREG256_SW_ENC_ROI6_TOP_MASK   (0x3FF000U)
#define VPU_HEVC_SWREG256_SW_ENC_ROI6_TOP_SHIFT  (12U)
#define VPU_HEVC_SWREG256_SW_ENC_ROI6_TOP(x)     (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG256_SW_ENC_ROI6_TOP_SHIFT)) & VPU_HEVC_SWREG256_SW_ENC_ROI6_TOP_MASK)

#define VPU_HEVC_SWREG256_SW_ENC_ROI6_LEFT_MASK  (0xFFC00000U)
#define VPU_HEVC_SWREG256_SW_ENC_ROI6_LEFT_SHIFT (22U)
#define VPU_HEVC_SWREG256_SW_ENC_ROI6_LEFT(x)    (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG256_SW_ENC_ROI6_LEFT_SHIFT)) & VPU_HEVC_SWREG256_SW_ENC_ROI6_LEFT_MASK)
/*! @} */

/*! @name SWREG257 - ROI6&7 Area */
/*! @{ */

#define VPU_HEVC_SWREG257_SW_ENC_ROI7_TOP_MASK   (0xFFCU)
#define VPU_HEVC_SWREG257_SW_ENC_ROI7_TOP_SHIFT  (2U)
#define VPU_HEVC_SWREG257_SW_ENC_ROI7_TOP(x)     (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG257_SW_ENC_ROI7_TOP_SHIFT)) & VPU_HEVC_SWREG257_SW_ENC_ROI7_TOP_MASK)

#define VPU_HEVC_SWREG257_SW_ENC_ROI7_LEFT_MASK  (0x3FF000U)
#define VPU_HEVC_SWREG257_SW_ENC_ROI7_LEFT_SHIFT (12U)
#define VPU_HEVC_SWREG257_SW_ENC_ROI7_LEFT(x)    (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG257_SW_ENC_ROI7_LEFT_SHIFT)) & VPU_HEVC_SWREG257_SW_ENC_ROI7_LEFT_MASK)

#define VPU_HEVC_SWREG257_SW_ENC_ROI6_BOTTOM_MASK (0xFFC00000U)
#define VPU_HEVC_SWREG257_SW_ENC_ROI6_BOTTOM_SHIFT (22U)
#define VPU_HEVC_SWREG257_SW_ENC_ROI6_BOTTOM(x)  (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG257_SW_ENC_ROI6_BOTTOM_SHIFT)) & VPU_HEVC_SWREG257_SW_ENC_ROI6_BOTTOM_MASK)
/*! @} */

/*! @name SWREG258 - ROI7&8 Area */
/*! @{ */

#define VPU_HEVC_SWREG258_SW_ENC_ROI8_LEFT_MASK  (0xFFCU)
#define VPU_HEVC_SWREG258_SW_ENC_ROI8_LEFT_SHIFT (2U)
#define VPU_HEVC_SWREG258_SW_ENC_ROI8_LEFT(x)    (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG258_SW_ENC_ROI8_LEFT_SHIFT)) & VPU_HEVC_SWREG258_SW_ENC_ROI8_LEFT_MASK)

#define VPU_HEVC_SWREG258_SW_ENC_ROI7_BOTTOM_MASK (0x3FF000U)
#define VPU_HEVC_SWREG258_SW_ENC_ROI7_BOTTOM_SHIFT (12U)
#define VPU_HEVC_SWREG258_SW_ENC_ROI7_BOTTOM(x)  (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG258_SW_ENC_ROI7_BOTTOM_SHIFT)) & VPU_HEVC_SWREG258_SW_ENC_ROI7_BOTTOM_MASK)

#define VPU_HEVC_SWREG258_SW_ENC_ROI7_RIGHT_MASK (0xFFC00000U)
#define VPU_HEVC_SWREG258_SW_ENC_ROI7_RIGHT_SHIFT (22U)
#define VPU_HEVC_SWREG258_SW_ENC_ROI7_RIGHT(x)   (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG258_SW_ENC_ROI7_RIGHT_SHIFT)) & VPU_HEVC_SWREG258_SW_ENC_ROI7_RIGHT_MASK)
/*! @} */

/*! @name SWREG259 - ROI8 Area */
/*! @{ */

#define VPU_HEVC_SWREG259_SW_ENC_CURRENT_MAX_TU_SIZE_DECREASE_MASK (0x2U)
#define VPU_HEVC_SWREG259_SW_ENC_CURRENT_MAX_TU_SIZE_DECREASE_SHIFT (1U)
/*! SW_ENC_CURRENT_MAX_TU_SIZE_DECREASE
 *  0b0..max tu size 32.
 *  0b1..max tu size 16.
 */
#define VPU_HEVC_SWREG259_SW_ENC_CURRENT_MAX_TU_SIZE_DECREASE(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG259_SW_ENC_CURRENT_MAX_TU_SIZE_DECREASE_SHIFT)) & VPU_HEVC_SWREG259_SW_ENC_CURRENT_MAX_TU_SIZE_DECREASE_MASK)

#define VPU_HEVC_SWREG259_SW_ENC_ROI8_BOTTOM_MASK (0xFFCU)
#define VPU_HEVC_SWREG259_SW_ENC_ROI8_BOTTOM_SHIFT (2U)
#define VPU_HEVC_SWREG259_SW_ENC_ROI8_BOTTOM(x)  (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG259_SW_ENC_ROI8_BOTTOM_SHIFT)) & VPU_HEVC_SWREG259_SW_ENC_ROI8_BOTTOM_MASK)

#define VPU_HEVC_SWREG259_SW_ENC_ROI8_RIGHT_MASK (0x3FF000U)
#define VPU_HEVC_SWREG259_SW_ENC_ROI8_RIGHT_SHIFT (12U)
#define VPU_HEVC_SWREG259_SW_ENC_ROI8_RIGHT(x)   (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG259_SW_ENC_ROI8_RIGHT_SHIFT)) & VPU_HEVC_SWREG259_SW_ENC_ROI8_RIGHT_MASK)

#define VPU_HEVC_SWREG259_SW_ENC_ROI8_TOP_MASK   (0xFFC00000U)
#define VPU_HEVC_SWREG259_SW_ENC_ROI8_TOP_SHIFT  (22U)
#define VPU_HEVC_SWREG259_SW_ENC_ROI8_TOP(x)     (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG259_SW_ENC_ROI8_TOP_SHIFT)) & VPU_HEVC_SWREG259_SW_ENC_ROI8_TOP_MASK)
/*! @} */

/*! @name SWREG260 - ROI qp */
/*! @{ */

#define VPU_HEVC_SWREG260_SW_ENC_ROI5_QP_TYPE_MASK (0x1U)
#define VPU_HEVC_SWREG260_SW_ENC_ROI5_QP_TYPE_SHIFT (0U)
/*! SW_ENC_ROI5_QP_TYPE
 *  0b0..delta
 *  0b1..Absolute value
 */
#define VPU_HEVC_SWREG260_SW_ENC_ROI5_QP_TYPE(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG260_SW_ENC_ROI5_QP_TYPE_SHIFT)) & VPU_HEVC_SWREG260_SW_ENC_ROI5_QP_TYPE_MASK)

#define VPU_HEVC_SWREG260_SW_ENC_ROI5_QP_VALUE_MASK (0xFEU)
#define VPU_HEVC_SWREG260_SW_ENC_ROI5_QP_VALUE_SHIFT (1U)
#define VPU_HEVC_SWREG260_SW_ENC_ROI5_QP_VALUE(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG260_SW_ENC_ROI5_QP_VALUE_SHIFT)) & VPU_HEVC_SWREG260_SW_ENC_ROI5_QP_VALUE_MASK)

#define VPU_HEVC_SWREG260_SW_ENC_ROI6_QP_TYPE_MASK (0x100U)
#define VPU_HEVC_SWREG260_SW_ENC_ROI6_QP_TYPE_SHIFT (8U)
/*! SW_ENC_ROI6_QP_TYPE
 *  0b0..delta
 *  0b1..Absolute value
 */
#define VPU_HEVC_SWREG260_SW_ENC_ROI6_QP_TYPE(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG260_SW_ENC_ROI6_QP_TYPE_SHIFT)) & VPU_HEVC_SWREG260_SW_ENC_ROI6_QP_TYPE_MASK)

#define VPU_HEVC_SWREG260_SW_ENC_ROI6_QP_VALUE_MASK (0xFE00U)
#define VPU_HEVC_SWREG260_SW_ENC_ROI6_QP_VALUE_SHIFT (9U)
#define VPU_HEVC_SWREG260_SW_ENC_ROI6_QP_VALUE(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG260_SW_ENC_ROI6_QP_VALUE_SHIFT)) & VPU_HEVC_SWREG260_SW_ENC_ROI6_QP_VALUE_MASK)

#define VPU_HEVC_SWREG260_SW_ENC_ROI7_QP_TYPE_MASK (0x10000U)
#define VPU_HEVC_SWREG260_SW_ENC_ROI7_QP_TYPE_SHIFT (16U)
/*! SW_ENC_ROI7_QP_TYPE
 *  0b0..delta
 *  0b1..Absolute value
 */
#define VPU_HEVC_SWREG260_SW_ENC_ROI7_QP_TYPE(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG260_SW_ENC_ROI7_QP_TYPE_SHIFT)) & VPU_HEVC_SWREG260_SW_ENC_ROI7_QP_TYPE_MASK)

#define VPU_HEVC_SWREG260_SW_ENC_ROI7_QP_VALUE_MASK (0xFE0000U)
#define VPU_HEVC_SWREG260_SW_ENC_ROI7_QP_VALUE_SHIFT (17U)
#define VPU_HEVC_SWREG260_SW_ENC_ROI7_QP_VALUE(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG260_SW_ENC_ROI7_QP_VALUE_SHIFT)) & VPU_HEVC_SWREG260_SW_ENC_ROI7_QP_VALUE_MASK)

#define VPU_HEVC_SWREG260_SW_ENC_ROI8_QP_TYPE_MASK (0x1000000U)
#define VPU_HEVC_SWREG260_SW_ENC_ROI8_QP_TYPE_SHIFT (24U)
/*! SW_ENC_ROI8_QP_TYPE
 *  0b0..delta
 *  0b1..Absolute value
 */
#define VPU_HEVC_SWREG260_SW_ENC_ROI8_QP_TYPE(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG260_SW_ENC_ROI8_QP_TYPE_SHIFT)) & VPU_HEVC_SWREG260_SW_ENC_ROI8_QP_TYPE_MASK)

#define VPU_HEVC_SWREG260_SW_ENC_ROI8_QP_VALUE_MASK (0xFE000000U)
#define VPU_HEVC_SWREG260_SW_ENC_ROI8_QP_VALUE_SHIFT (25U)
#define VPU_HEVC_SWREG260_SW_ENC_ROI8_QP_VALUE(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG260_SW_ENC_ROI8_QP_VALUE_SHIFT)) & VPU_HEVC_SWREG260_SW_ENC_ROI8_QP_VALUE_MASK)
/*! @} */

/*! @name SWREG261 - Stride Control */
/*! @{ */

#define VPU_HEVC_SWREG261_SW_ENC_MOTION_SCORE_ENABLE_MASK (0x1U)
#define VPU_HEVC_SWREG261_SW_ENC_MOTION_SCORE_ENABLE_SHIFT (0U)
#define VPU_HEVC_SWREG261_SW_ENC_MOTION_SCORE_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG261_SW_ENC_MOTION_SCORE_ENABLE_SHIFT)) & VPU_HEVC_SWREG261_SW_ENC_MOTION_SCORE_ENABLE_MASK)

#define VPU_HEVC_SWREG261_SW_ENC_PASS1_SKIP_CABAC_MASK (0x2U)
#define VPU_HEVC_SWREG261_SW_ENC_PASS1_SKIP_CABAC_SHIFT (1U)
#define VPU_HEVC_SWREG261_SW_ENC_PASS1_SKIP_CABAC(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG261_SW_ENC_PASS1_SKIP_CABAC_SHIFT)) & VPU_HEVC_SWREG261_SW_ENC_PASS1_SKIP_CABAC_MASK)

#define VPU_HEVC_SWREG261_SW_ENC_RDOQ_ENABLE_MASK (0x4U)
#define VPU_HEVC_SWREG261_SW_ENC_RDOQ_ENABLE_SHIFT (2U)
#define VPU_HEVC_SWREG261_SW_ENC_RDOQ_ENABLE(x)  (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG261_SW_ENC_RDOQ_ENABLE_SHIFT)) & VPU_HEVC_SWREG261_SW_ENC_RDOQ_ENABLE_MASK)

#define VPU_HEVC_SWREG261_SW_ENC_MULTI_CORE_EN_MASK (0x8U)
#define VPU_HEVC_SWREG261_SW_ENC_MULTI_CORE_EN_SHIFT (3U)
#define VPU_HEVC_SWREG261_SW_ENC_MULTI_CORE_EN(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG261_SW_ENC_MULTI_CORE_EN_SHIFT)) & VPU_HEVC_SWREG261_SW_ENC_MULTI_CORE_EN_MASK)

#define VPU_HEVC_SWREG261_SW_ENC_AXI_READ_OUTSTANDING_NUM_MASK (0xFF0U)
#define VPU_HEVC_SWREG261_SW_ENC_AXI_READ_OUTSTANDING_NUM_SHIFT (4U)
#define VPU_HEVC_SWREG261_SW_ENC_AXI_READ_OUTSTANDING_NUM(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG261_SW_ENC_AXI_READ_OUTSTANDING_NUM_SHIFT)) & VPU_HEVC_SWREG261_SW_ENC_AXI_READ_OUTSTANDING_NUM_MASK)

#define VPU_HEVC_SWREG261_SW_ENC_PRP_IN_LOOP_DS_RATIO_MASK (0x1000U)
#define VPU_HEVC_SWREG261_SW_ENC_PRP_IN_LOOP_DS_RATIO_SHIFT (12U)
#define VPU_HEVC_SWREG261_SW_ENC_PRP_IN_LOOP_DS_RATIO(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG261_SW_ENC_PRP_IN_LOOP_DS_RATIO_SHIFT)) & VPU_HEVC_SWREG261_SW_ENC_PRP_IN_LOOP_DS_RATIO_MASK)

#define VPU_HEVC_SWREG261_SW_ENC_RGBLUMAOFFSET_MASK (0x3E000U)
#define VPU_HEVC_SWREG261_SW_ENC_RGBLUMAOFFSET_SHIFT (13U)
#define VPU_HEVC_SWREG261_SW_ENC_RGBLUMAOFFSET(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG261_SW_ENC_RGBLUMAOFFSET_SHIFT)) & VPU_HEVC_SWREG261_SW_ENC_RGBLUMAOFFSET_MASK)
/*! @} */

/*! @name SWREG265 - Multicore sync ctrl */
/*! @{ */

#define VPU_HEVC_SWREG265_SW_ENC_DDR_POLLING_INTERVAL_MASK (0xFFFFU)
#define VPU_HEVC_SWREG265_SW_ENC_DDR_POLLING_INTERVAL_SHIFT (0U)
#define VPU_HEVC_SWREG265_SW_ENC_DDR_POLLING_INTERVAL(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG265_SW_ENC_DDR_POLLING_INTERVAL_SHIFT)) & VPU_HEVC_SWREG265_SW_ENC_DDR_POLLING_INTERVAL_MASK)

#define VPU_HEVC_SWREG265_SW_ENC_REF_READY_THRESHOLD_MASK (0xFFFF0000U)
#define VPU_HEVC_SWREG265_SW_ENC_REF_READY_THRESHOLD_SHIFT (16U)
#define VPU_HEVC_SWREG265_SW_ENC_REF_READY_THRESHOLD(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG265_SW_ENC_REF_READY_THRESHOLD_SHIFT)) & VPU_HEVC_SWREG265_SW_ENC_REF_READY_THRESHOLD_MASK)
/*! @} */

/*! @name SWREG266 - Multicore sync address L0 LSB */
/*! @{ */

#define VPU_HEVC_SWREG266_SW_ENC_MULTICORE_SYNC_L0_ADDR_MASK (0xFFFFFFFFU)
#define VPU_HEVC_SWREG266_SW_ENC_MULTICORE_SYNC_L0_ADDR_SHIFT (0U)
#define VPU_HEVC_SWREG266_SW_ENC_MULTICORE_SYNC_L0_ADDR(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG266_SW_ENC_MULTICORE_SYNC_L0_ADDR_SHIFT)) & VPU_HEVC_SWREG266_SW_ENC_MULTICORE_SYNC_L0_ADDR_MASK)
/*! @} */

/*! @name SWREG267 - Multicore sync address L0 MSB */
/*! @{ */

#define VPU_HEVC_SWREG267_SW_ENC_MULTICORE_SYNC_L0_ADDR_MSB_MASK (0xFFFFFFFFU)
#define VPU_HEVC_SWREG267_SW_ENC_MULTICORE_SYNC_L0_ADDR_MSB_SHIFT (0U)
#define VPU_HEVC_SWREG267_SW_ENC_MULTICORE_SYNC_L0_ADDR_MSB(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG267_SW_ENC_MULTICORE_SYNC_L0_ADDR_MSB_SHIFT)) & VPU_HEVC_SWREG267_SW_ENC_MULTICORE_SYNC_L0_ADDR_MSB_MASK)
/*! @} */

/*! @name SWREG268 - Multicore sync address L1 LSB */
/*! @{ */

#define VPU_HEVC_SWREG268_SW_ENC_MULTICORE_SYNC_L1_ADDR_MASK (0xFFFFFFFFU)
#define VPU_HEVC_SWREG268_SW_ENC_MULTICORE_SYNC_L1_ADDR_SHIFT (0U)
#define VPU_HEVC_SWREG268_SW_ENC_MULTICORE_SYNC_L1_ADDR(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG268_SW_ENC_MULTICORE_SYNC_L1_ADDR_SHIFT)) & VPU_HEVC_SWREG268_SW_ENC_MULTICORE_SYNC_L1_ADDR_MASK)
/*! @} */

/*! @name SWREG269 - Multicore sync address L1 MSB */
/*! @{ */

#define VPU_HEVC_SWREG269_SW_ENC_MULTICORE_SYNC_L1_ADDR_MSB_MASK (0xFFFFFFFFU)
#define VPU_HEVC_SWREG269_SW_ENC_MULTICORE_SYNC_L1_ADDR_MSB_SHIFT (0U)
#define VPU_HEVC_SWREG269_SW_ENC_MULTICORE_SYNC_L1_ADDR_MSB(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG269_SW_ENC_MULTICORE_SYNC_L1_ADDR_MSB_SHIFT)) & VPU_HEVC_SWREG269_SW_ENC_MULTICORE_SYNC_L1_ADDR_MSB_MASK)
/*! @} */

/*! @name SWREG270 - Multicore sync address recon LSB */
/*! @{ */

#define VPU_HEVC_SWREG270_SW_ENC_MULTICORE_SYNC_REC_ADDR_MASK (0xFFFFFFFFU)
#define VPU_HEVC_SWREG270_SW_ENC_MULTICORE_SYNC_REC_ADDR_SHIFT (0U)
#define VPU_HEVC_SWREG270_SW_ENC_MULTICORE_SYNC_REC_ADDR(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG270_SW_ENC_MULTICORE_SYNC_REC_ADDR_SHIFT)) & VPU_HEVC_SWREG270_SW_ENC_MULTICORE_SYNC_REC_ADDR_MASK)
/*! @} */

/*! @name SWREG271 - Multicore sync address recon MSB */
/*! @{ */

#define VPU_HEVC_SWREG271_SW_ENC_MULTICORE_SYNC_REC_ADDR_MSB_MASK (0xFFFFFFFFU)
#define VPU_HEVC_SWREG271_SW_ENC_MULTICORE_SYNC_REC_ADDR_MSB_SHIFT (0U)
#define VPU_HEVC_SWREG271_SW_ENC_MULTICORE_SYNC_REC_ADDR_MSB(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG271_SW_ENC_MULTICORE_SYNC_REC_ADDR_MSB_SHIFT)) & VPU_HEVC_SWREG271_SW_ENC_MULTICORE_SYNC_REC_ADDR_MSB_MASK)
/*! @} */

/*! @name SWREG272 - Programmable AXI urgent sideband signals */
/*! @{ */

#define VPU_HEVC_SWREG272_SW_ENC_WR_URGENT_DISABLE_THRESHOLD_MASK (0xFFU)
#define VPU_HEVC_SWREG272_SW_ENC_WR_URGENT_DISABLE_THRESHOLD_SHIFT (0U)
#define VPU_HEVC_SWREG272_SW_ENC_WR_URGENT_DISABLE_THRESHOLD(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG272_SW_ENC_WR_URGENT_DISABLE_THRESHOLD_SHIFT)) & VPU_HEVC_SWREG272_SW_ENC_WR_URGENT_DISABLE_THRESHOLD_MASK)

#define VPU_HEVC_SWREG272_SW_ENC_WR_URGENT_ENABLE_THRESHOLD_MASK (0xFF00U)
#define VPU_HEVC_SWREG272_SW_ENC_WR_URGENT_ENABLE_THRESHOLD_SHIFT (8U)
#define VPU_HEVC_SWREG272_SW_ENC_WR_URGENT_ENABLE_THRESHOLD(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG272_SW_ENC_WR_URGENT_ENABLE_THRESHOLD_SHIFT)) & VPU_HEVC_SWREG272_SW_ENC_WR_URGENT_ENABLE_THRESHOLD_MASK)

#define VPU_HEVC_SWREG272_SW_ENC_RD_URGENT_DISABLE_THRESHOLD_MASK (0xFF0000U)
#define VPU_HEVC_SWREG272_SW_ENC_RD_URGENT_DISABLE_THRESHOLD_SHIFT (16U)
#define VPU_HEVC_SWREG272_SW_ENC_RD_URGENT_DISABLE_THRESHOLD(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG272_SW_ENC_RD_URGENT_DISABLE_THRESHOLD_SHIFT)) & VPU_HEVC_SWREG272_SW_ENC_RD_URGENT_DISABLE_THRESHOLD_MASK)

#define VPU_HEVC_SWREG272_SW_ENC_RD_URGENT_ENABLE_THRESHOLD_MASK (0xFF000000U)
#define VPU_HEVC_SWREG272_SW_ENC_RD_URGENT_ENABLE_THRESHOLD_SHIFT (24U)
#define VPU_HEVC_SWREG272_SW_ENC_RD_URGENT_ENABLE_THRESHOLD(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG272_SW_ENC_RD_URGENT_ENABLE_THRESHOLD_SHIFT)) & VPU_HEVC_SWREG272_SW_ENC_RD_URGENT_ENABLE_THRESHOLD_MASK)
/*! @} */

/*! @name SWREG273 - roimap cu ctrl index address LSB */
/*! @{ */

#define VPU_HEVC_SWREG273_SW_ENC_ROIMAP_CUCTRL_INDEX_ADDR_MASK (0xFFFFFFFFU)
#define VPU_HEVC_SWREG273_SW_ENC_ROIMAP_CUCTRL_INDEX_ADDR_SHIFT (0U)
#define VPU_HEVC_SWREG273_SW_ENC_ROIMAP_CUCTRL_INDEX_ADDR(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG273_SW_ENC_ROIMAP_CUCTRL_INDEX_ADDR_SHIFT)) & VPU_HEVC_SWREG273_SW_ENC_ROIMAP_CUCTRL_INDEX_ADDR_MASK)
/*! @} */

/*! @name SWREG274 - roimap cu ctrl index address MSB */
/*! @{ */

#define VPU_HEVC_SWREG274_SW_ENC_ROIMAP_CUCTRL_INDEX_ADDR_MSB_MASK (0xFFFFFFFFU)
#define VPU_HEVC_SWREG274_SW_ENC_ROIMAP_CUCTRL_INDEX_ADDR_MSB_SHIFT (0U)
#define VPU_HEVC_SWREG274_SW_ENC_ROIMAP_CUCTRL_INDEX_ADDR_MSB(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG274_SW_ENC_ROIMAP_CUCTRL_INDEX_ADDR_MSB_SHIFT)) & VPU_HEVC_SWREG274_SW_ENC_ROIMAP_CUCTRL_INDEX_ADDR_MSB_MASK)
/*! @} */

/*! @name SWREG275 - roimap cu ctrl address LSB */
/*! @{ */

#define VPU_HEVC_SWREG275_SW_ENC_ROIMAP_CUCTRL_ADDR_MASK (0xFFFFFFFFU)
#define VPU_HEVC_SWREG275_SW_ENC_ROIMAP_CUCTRL_ADDR_SHIFT (0U)
#define VPU_HEVC_SWREG275_SW_ENC_ROIMAP_CUCTRL_ADDR(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG275_SW_ENC_ROIMAP_CUCTRL_ADDR_SHIFT)) & VPU_HEVC_SWREG275_SW_ENC_ROIMAP_CUCTRL_ADDR_MASK)
/*! @} */

/*! @name SWREG276 - roimap cu ctrl address MSB */
/*! @{ */

#define VPU_HEVC_SWREG276_SW_ENC_ROIMAP_CUCTRL_ADDR_MSB_MASK (0xFFFFFFFFU)
#define VPU_HEVC_SWREG276_SW_ENC_ROIMAP_CUCTRL_ADDR_MSB_SHIFT (0U)
#define VPU_HEVC_SWREG276_SW_ENC_ROIMAP_CUCTRL_ADDR_MSB(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG276_SW_ENC_ROIMAP_CUCTRL_ADDR_MSB_SHIFT)) & VPU_HEVC_SWREG276_SW_ENC_ROIMAP_CUCTRL_ADDR_MSB_MASK)
/*! @} */

/*! @name SWREG277 - poc type/bits setting */
/*! @{ */

#define VPU_HEVC_SWREG277_SW_ENC_SYN_AMOUNT_PER_LOOPBACK_MASK (0xFFFE0U)
#define VPU_HEVC_SWREG277_SW_ENC_SYN_AMOUNT_PER_LOOPBACK_SHIFT (5U)
#define VPU_HEVC_SWREG277_SW_ENC_SYN_AMOUNT_PER_LOOPBACK(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG277_SW_ENC_SYN_AMOUNT_PER_LOOPBACK_SHIFT)) & VPU_HEVC_SWREG277_SW_ENC_SYN_AMOUNT_PER_LOOPBACK_MASK)

#define VPU_HEVC_SWREG277_SW_ENC_LOG2_MAX_PIC_ORDER_CNT_LSB_MASK (0xF8000000U)
#define VPU_HEVC_SWREG277_SW_ENC_LOG2_MAX_PIC_ORDER_CNT_LSB_SHIFT (27U)
#define VPU_HEVC_SWREG277_SW_ENC_LOG2_MAX_PIC_ORDER_CNT_LSB(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG277_SW_ENC_LOG2_MAX_PIC_ORDER_CNT_LSB_SHIFT)) & VPU_HEVC_SWREG277_SW_ENC_LOG2_MAX_PIC_ORDER_CNT_LSB_MASK)
/*! @} */

/*! @name SWREG278 - stream output buffer1 address */
/*! @{ */

#define VPU_HEVC_SWREG278_SW_ENC_OUTPUT_STRM_BUF1_BASE_MASK (0xFFFFFFFFU)
#define VPU_HEVC_SWREG278_SW_ENC_OUTPUT_STRM_BUF1_BASE_SHIFT (0U)
#define VPU_HEVC_SWREG278_SW_ENC_OUTPUT_STRM_BUF1_BASE(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG278_SW_ENC_OUTPUT_STRM_BUF1_BASE_SHIFT)) & VPU_HEVC_SWREG278_SW_ENC_OUTPUT_STRM_BUF1_BASE_MASK)
/*! @} */

/*! @name SWREG280 - stream output buffer1 limit size */
/*! @{ */

#define VPU_HEVC_SWREG280_SW_ENC_OUTPUT_STRM_BUFFER1_LIMIT_MASK (0xFFFFFFFFU)
#define VPU_HEVC_SWREG280_SW_ENC_OUTPUT_STRM_BUFFER1_LIMIT_SHIFT (0U)
#define VPU_HEVC_SWREG280_SW_ENC_OUTPUT_STRM_BUFFER1_LIMIT(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG280_SW_ENC_OUTPUT_STRM_BUFFER1_LIMIT_SHIFT)) & VPU_HEVC_SWREG280_SW_ENC_OUTPUT_STRM_BUFFER1_LIMIT_MASK)
/*! @} */

/*! @name SWREG281 - poc type/bits setting */
/*! @{ */

#define VPU_HEVC_SWREG281_SW_NUM_CTB_ROWS_PER_SYNC_MSB_MASK (0x3F0U)
#define VPU_HEVC_SWREG281_SW_NUM_CTB_ROWS_PER_SYNC_MSB_SHIFT (4U)
#define VPU_HEVC_SWREG281_SW_NUM_CTB_ROWS_PER_SYNC_MSB(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG281_SW_NUM_CTB_ROWS_PER_SYNC_MSB_SHIFT)) & VPU_HEVC_SWREG281_SW_NUM_CTB_ROWS_PER_SYNC_MSB_MASK)

#define VPU_HEVC_SWREG281_SW_ENC_STRM_SEGMENT_WR_PTR_MASK (0xFFC00U)
#define VPU_HEVC_SWREG281_SW_ENC_STRM_SEGMENT_WR_PTR_SHIFT (10U)
#define VPU_HEVC_SWREG281_SW_ENC_STRM_SEGMENT_WR_PTR(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG281_SW_ENC_STRM_SEGMENT_WR_PTR_SHIFT)) & VPU_HEVC_SWREG281_SW_ENC_STRM_SEGMENT_WR_PTR_MASK)

#define VPU_HEVC_SWREG281_SW_ENC_STRM_SEGMENT_RD_PTR_MASK (0x3FF00000U)
#define VPU_HEVC_SWREG281_SW_ENC_STRM_SEGMENT_RD_PTR_SHIFT (20U)
#define VPU_HEVC_SWREG281_SW_ENC_STRM_SEGMENT_RD_PTR(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG281_SW_ENC_STRM_SEGMENT_RD_PTR_SHIFT)) & VPU_HEVC_SWREG281_SW_ENC_STRM_SEGMENT_RD_PTR_MASK)

#define VPU_HEVC_SWREG281_SW_ENC_STRM_SEGMENT_EN_MASK (0x40000000U)
#define VPU_HEVC_SWREG281_SW_ENC_STRM_SEGMENT_EN_SHIFT (30U)
#define VPU_HEVC_SWREG281_SW_ENC_STRM_SEGMENT_EN(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG281_SW_ENC_STRM_SEGMENT_EN_SHIFT)) & VPU_HEVC_SWREG281_SW_ENC_STRM_SEGMENT_EN_MASK)

#define VPU_HEVC_SWREG281_SW_ENC_STRM_SEGMENT_SW_SYNC_EN_MASK (0x80000000U)
#define VPU_HEVC_SWREG281_SW_ENC_STRM_SEGMENT_SW_SYNC_EN_SHIFT (31U)
#define VPU_HEVC_SWREG281_SW_ENC_STRM_SEGMENT_SW_SYNC_EN(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG281_SW_ENC_STRM_SEGMENT_SW_SYNC_EN_SHIFT)) & VPU_HEVC_SWREG281_SW_ENC_STRM_SEGMENT_SW_SYNC_EN_MASK)
/*! @} */

/*! @name SWREG287 - HW synthesis config register 4, read-only */
/*! @{ */

#define VPU_HEVC_SWREG287_SW_ENC_HWSCALER420SUPPORT_MASK (0x20000000U)
#define VPU_HEVC_SWREG287_SW_ENC_HWSCALER420SUPPORT_SHIFT (29U)
/*! SW_ENC_HWSCALER420SUPPORT
 *  0b0..not supported.
 *  0b1..supported
 */
#define VPU_HEVC_SWREG287_SW_ENC_HWSCALER420SUPPORT(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG287_SW_ENC_HWSCALER420SUPPORT_SHIFT)) & VPU_HEVC_SWREG287_SW_ENC_HWSCALER420SUPPORT_MASK)

#define VPU_HEVC_SWREG287_SW_ENC_HWCSCEXTENSIONSUPPORT_MASK (0x40000000U)
#define VPU_HEVC_SWREG287_SW_ENC_HWCSCEXTENSIONSUPPORT_SHIFT (30U)
/*! SW_ENC_HWCSCEXTENSIONSUPPORT
 *  0b0..not supported.
 *  0b1..supported
 */
#define VPU_HEVC_SWREG287_SW_ENC_HWCSCEXTENSIONSUPPORT(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG287_SW_ENC_HWCSCEXTENSIONSUPPORT_SHIFT)) & VPU_HEVC_SWREG287_SW_ENC_HWCSCEXTENSIONSUPPORT_MASK)

#define VPU_HEVC_SWREG287_SW_ENC_HWVIDEOHEIGHTEXT_MASK (0x80000000U)
#define VPU_HEVC_SWREG287_SW_ENC_HWVIDEOHEIGHTEXT_SHIFT (31U)
/*! SW_ENC_HWVIDEOHEIGHTEXT
 *  0b0..Not.
 *  0b1..Yes.
 */
#define VPU_HEVC_SWREG287_SW_ENC_HWVIDEOHEIGHTEXT(x) (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG287_SW_ENC_HWVIDEOHEIGHTEXT_SHIFT)) & VPU_HEVC_SWREG287_SW_ENC_HWVIDEOHEIGHTEXT_MASK)
/*! @} */

/*! @name SWREG289 - Pre-processor color conversion parameters1 */
/*! @{ */

#define VPU_HEVC_SWREG289_SW_ENC_RGBCOEFFH_MASK  (0xFFFFU)
#define VPU_HEVC_SWREG289_SW_ENC_RGBCOEFFH_SHIFT (0U)
#define VPU_HEVC_SWREG289_SW_ENC_RGBCOEFFH(x)    (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG289_SW_ENC_RGBCOEFFH_SHIFT)) & VPU_HEVC_SWREG289_SW_ENC_RGBCOEFFH_MASK)

#define VPU_HEVC_SWREG289_SW_ENC_RGBCOEFFG_MASK  (0xFFFF0000U)
#define VPU_HEVC_SWREG289_SW_ENC_RGBCOEFFG_SHIFT (16U)
#define VPU_HEVC_SWREG289_SW_ENC_RGBCOEFFG(x)    (((uint32_t)(((uint32_t)(x)) << VPU_HEVC_SWREG289_SW_ENC_RGBCOEFFG_SHIFT)) & VPU_HEVC_SWREG289_SW_ENC_RGBCOEFFG_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group VPU_HEVC_Register_Masks */


/*!
 * @}
 */ /* end of group VPU_HEVC_Peripheral_Access_Layer */


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
#elif defined(__XTENSA__)
  /* leave anonymous unions enabled */
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_VPU_HEVC_H_ */

