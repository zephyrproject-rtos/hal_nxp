/*
** ###################################################################
**     Processors:          MIMX8MM1CVTKZ_ca53
**                          MIMX8MM1CVTKZ_cm4
**                          MIMX8MM1DVTLZ_ca53
**                          MIMX8MM1DVTLZ_cm4
**                          MIMX8MM2CVTKZ_ca53
**                          MIMX8MM2CVTKZ_cm4
**                          MIMX8MM2DVTLZ_ca53
**                          MIMX8MM2DVTLZ_cm4
**                          MIMX8MM3CVTKZ_ca53
**                          MIMX8MM3CVTKZ_cm4
**                          MIMX8MM3DVTLZ_ca53
**                          MIMX8MM3DVTLZ_cm4
**                          MIMX8MM4CVTKZ_ca53
**                          MIMX8MM4CVTKZ_cm4
**                          MIMX8MM4DVTLZ_ca53
**                          MIMX8MM4DVTLZ_cm4
**                          MIMX8MM5CVTKZ_ca53
**                          MIMX8MM5CVTKZ_cm4
**                          MIMX8MM5DVTLZ_ca53
**                          MIMX8MM5DVTLZ_cm4
**                          MIMX8MM6CVTKZ_ca53
**                          MIMX8MM6CVTKZ_cm4
**                          MIMX8MM6DVTLZ_ca53
**                          MIMX8MM6DVTLZ_cm4
**
**     Version:             rev. 5.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for VPU_H1
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2018-03-26)
**         Initial version.
**     - rev. 2.0 (2018-07-20)
**         Rev.A Header EAR
**     - rev. 3.0 (2018-10-24)
**         Rev.B Header PRC
**     - rev. 4.0 (2019-02-18)
**         Rev.0 Header RFP
**     - rev. 5.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_VPU_H1.h
 * @version 5.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for VPU_H1
 *
 * CMSIS Peripheral Access Layer for VPU_H1
 */

#if !defined(PERI_VPU_H1_H_)
#define PERI_VPU_H1_H_                           /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8MM1CVTKZ_ca53) || defined(CPU_MIMX8MM1DVTLZ_ca53))
#include "MIMX8MM1_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM1CVTKZ_cm4) || defined(CPU_MIMX8MM1DVTLZ_cm4))
#include "MIMX8MM1_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MM2CVTKZ_ca53) || defined(CPU_MIMX8MM2DVTLZ_ca53))
#include "MIMX8MM2_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM2CVTKZ_cm4) || defined(CPU_MIMX8MM2DVTLZ_cm4))
#include "MIMX8MM2_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MM3CVTKZ_ca53) || defined(CPU_MIMX8MM3DVTLZ_ca53))
#include "MIMX8MM3_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM3CVTKZ_cm4) || defined(CPU_MIMX8MM3DVTLZ_cm4))
#include "MIMX8MM3_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MM4CVTKZ_ca53) || defined(CPU_MIMX8MM4DVTLZ_ca53))
#include "MIMX8MM4_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM4CVTKZ_cm4) || defined(CPU_MIMX8MM4DVTLZ_cm4))
#include "MIMX8MM4_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MM5CVTKZ_ca53) || defined(CPU_MIMX8MM5DVTLZ_ca53))
#include "MIMX8MM5_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM5CVTKZ_cm4) || defined(CPU_MIMX8MM5DVTLZ_cm4))
#include "MIMX8MM5_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MM6CVTKZ_ca53) || defined(CPU_MIMX8MM6DVTLZ_ca53))
#include "MIMX8MM6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM6CVTKZ_cm4) || defined(CPU_MIMX8MM6DVTLZ_cm4))
#include "MIMX8MM6_cm4_COMMON.h"
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
   -- VPU_H1 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VPU_H1_Peripheral_Access_Layer VPU_H1 Peripheral Access Layer
 * @{
 */

/** VPU_H1 - Register Layout Typedef */
typedef struct {
  __I  uint32_t SWREG0;                            /**< VPU H1 Register 0, offset: 0x0 */
  __IO uint32_t SWREG1;                            /**< VPU H1 Register 1, offset: 0x4 */
  __IO uint32_t SWREG2;                            /**< VPU H1 Register 2, offset: 0x8 */
  __IO uint32_t SWREG3;                            /**< VPU H1 Register 3, offset: 0xC */
       uint8_t RESERVED_0[4];
  __IO uint32_t SWREG5;                            /**< VPU H1 Register 5, offset: 0x14 */
  __IO uint32_t SWREG6;                            /**< VPU H1 Register 6, offset: 0x18 */
  __IO uint32_t SWREG7;                            /**< VPU H1 Register 7, offset: 0x1C */
  __IO uint32_t SWREG8;                            /**< VPU H1 Register 8, offset: 0x20 */
  __IO uint32_t SWREG9;                            /**< VPU H1 Register 9, offset: 0x24 */
  __IO uint32_t SWREG10;                           /**< VPU H1 Register 10, offset: 0x28 */
  __IO uint32_t SWREG11;                           /**< VPU H1 Register 11, offset: 0x2C */
  __IO uint32_t SWREG12;                           /**< VPU H1 Register 12, offset: 0x30 */
  __IO uint32_t SWREG13;                           /**< VPU H1 Register 13, offset: 0x34 */
  __IO uint32_t SWREG14;                           /**< VPU H1 Register 14, offset: 0x38 */
  __IO uint32_t SWREG15;                           /**< VPU H1 Register 15, offset: 0x3C */
       uint8_t RESERVED_1[8];
  __IO uint32_t SWREG18;                           /**< VPU H1 Register 18, offset: 0x48 */
  __IO uint32_t SWREG19;                           /**< VPU H1 Register 19, offset: 0x4C */
  __IO uint32_t SWREG20;                           /**< VPU H1 Register 20, offset: 0x50 */
  __IO uint32_t SWREG21;                           /**< VPU H1 Register 21, offset: 0x54 */
  __IO uint32_t SWREG22;                           /**< VPU H1 Register 22, offset: 0x58 */
  __IO uint32_t SWREG23;                           /**< VPU H1 Register 23, offset: 0x5C */
  __IO uint32_t SWREG24;                           /**< VPU H1 Register 24, offset: 0x60 */
  __IO uint32_t SWREG25;                           /**< VPU H1 Register 25, offset: 0x64 */
       uint8_t RESERVED_2[44];
  __IO uint32_t SWREG37;                           /**< VPU H1 Register 37, offset: 0x94 */
  __IO uint32_t SWREG38;                           /**< VPU H1 Register 38, offset: 0x98 */
  __IO uint32_t SWREG39;                           /**< VPU H1 Register 39, offset: 0x9C */
  __IO uint32_t SWREG40;                           /**< VPU H1 Register 40, offset: 0xA0 */
  __IO uint32_t SWREG41;                           /**< VPU H1 Register 41, offset: 0xA4 */
  __IO uint32_t SWREG42;                           /**< VPU H1 Register 42, offset: 0xA8 */
  __IO uint32_t SWREG43;                           /**< VPU H1 Register 43, offset: 0xAC */
  __IO uint32_t SWREG44;                           /**< VPU H1 Register 44, offset: 0xB0 */
  __IO uint32_t SWREG45;                           /**< VPU H1 Register 45, offset: 0xB4 */
  __IO uint32_t SWREG46;                           /**< VPU H1 Register 46, offset: 0xB8 */
  __IO uint32_t SWREG47;                           /**< VPU H1 Register 47, offset: 0xBC */
  __IO uint32_t SWREG48;                           /**< VPU H1 Register 48, offset: 0xC0 */
  __IO uint32_t SWREG49;                           /**< VPU H1 Register 49, offset: 0xC4 */
  __IO uint32_t SWREG50;                           /**< VPU H1 Register 50, offset: 0xC8 */
  __IO uint32_t SWREG51;                           /**< VPU H1 Register 51, offset: 0xCC */
  __IO uint32_t SWREG52;                           /**< VPU H1 Register 52, offset: 0xD0 */
  __IO uint32_t SWREG53;                           /**< VPU H1 Register 53, offset: 0xD4 */
  __IO uint32_t SWREG54;                           /**< VPU H1 Register 54, offset: 0xD8 */
  __IO uint32_t SWREG55;                           /**< VPU H1 Register 55, offset: 0xDC */
  __IO uint32_t SWREG56;                           /**< VPU H1 Register 56, offset: 0xE0 */
  __IO uint32_t SWREG57;                           /**< VPU H1 Register 57, offset: 0xE4 */
       uint8_t RESERVED_3[8];
  __IO uint32_t SWREG60;                           /**< VPU H1 Register 60, offset: 0xF0 */
  __IO uint32_t SWREG61;                           /**< VPU H1 Register 61, offset: 0xF4 */
  __IO uint32_t SWREG62;                           /**< VPU H1 Register 62, offset: 0xF8 */
  __I  uint32_t SWREG63;                           /**< VPU H1 Register 63, offset: 0xFC */
       uint8_t RESERVED_4[128];
  __O  uint32_t SWREG96;                           /**< VPU H1 Register 96, offset: 0x180 */
  __O  uint32_t SWREG97;                           /**< VPU H1 Register 97, offset: 0x184 */
  __O  uint32_t SWREG98;                           /**< VPU H1 Register 98, offset: 0x188 */
  __O  uint32_t SWREG99;                           /**< VPU H1 Register 99, offset: 0x18C */
  __O  uint32_t SWREG100;                          /**< VPU H1 Register 100, offset: 0x190 */
  __O  uint32_t SWREG101;                          /**< VPU H1 Register 101, offset: 0x194 */
  __O  uint32_t SWREG102;                          /**< VPU H1 Register 102, offset: 0x198 */
  __O  uint32_t SWREG103;                          /**< VPU H1 Register 103, offset: 0x19C */
  __O  uint32_t SWREG104;                          /**< VPU H1 Register 104, offset: 0x1A0 */
  __O  uint32_t SWREG105;                          /**< VPU H1 Register 105, offset: 0x1A4 */
  __O  uint32_t SWREG106;                          /**< VPU H1 Register 106, offset: 0x1A8 */
  __O  uint32_t SWREG107;                          /**< VPU H1 Register 107, offset: 0x1AC */
  __O  uint32_t SWREG108;                          /**< VPU H1 Register 108, offset: 0x1B0 */
  __O  uint32_t SWREG109;                          /**< VPU H1 Register 109, offset: 0x1B4 */
  __O  uint32_t SWREG110;                          /**< VPU H1 Register 110, offset: 0x1B8 */
  __O  uint32_t SWREG111;                          /**< VPU H1 Register 111, offset: 0x1BC */
  __O  uint32_t SWREG112;                          /**< VPU H1 Register 112, offset: 0x1C0 */
  __O  uint32_t SWREG113;                          /**< VPU H1 Register 113, offset: 0x1C4 */
  __O  uint32_t SWREG114;                          /**< VPU H1 Register 114, offset: 0x1C8 */
  __O  uint32_t SWREG115;                          /**< VPU H1 Register 115, offset: 0x1CC */
  __O  uint32_t SWREG116;                          /**< VPU H1 Register 116, offset: 0x1D0 */
  __O  uint32_t SWREG117;                          /**< VPU H1 Register 117, offset: 0x1D4 */
  __O  uint32_t SWREG118;                          /**< VPU H1 Register 118, offset: 0x1D8 */
  __O  uint32_t SWREG119;                          /**< VPU H1 Register 119, offset: 0x1DC */
  __O  uint32_t SWREG120;                          /**< VPU H1 Register 120, offset: 0x1E0 */
  __O  uint32_t SWREG121;                          /**< VPU H1 Register 121, offset: 0x1E4 */
  __O  uint32_t SWREG122;                          /**< VPU H1 Register 122, offset: 0x1E8 */
  __O  uint32_t SWREG123;                          /**< VPU H1 Register 123, offset: 0x1EC */
  __O  uint32_t SWREG124;                          /**< VPU H1 Register 124, offset: 0x1F0 */
  __O  uint32_t SWREG125;                          /**< VPU H1 Register 125, offset: 0x1F4 */
  __O  uint32_t SWREG126;                          /**< VPU H1 Register 126, offset: 0x1F8 */
  __O  uint32_t SWREG127;                          /**< VPU H1 Register 127, offset: 0x1FC */
  __O  uint32_t SWREG128;                          /**< VPU H1 Register 128, offset: 0x200 */
  __O  uint32_t SWREG129;                          /**< VPU H1 Register 129, offset: 0x204 */
  __O  uint32_t SWREG130;                          /**< VPU H1 Register 130, offset: 0x208 */
  __O  uint32_t SWREG131;                          /**< VPU H1 Register 131, offset: 0x20C */
  __O  uint32_t SWREG132;                          /**< VPU H1 Register 132, offset: 0x210 */
  __O  uint32_t SWREG133;                          /**< VPU H1 Register 133, offset: 0x214 */
  __O  uint32_t SWREG134;                          /**< VPU H1 Register 134, offset: 0x218 */
  __O  uint32_t SWREG135;                          /**< VPU H1 Register 135, offset: 0x21C */
  __O  uint32_t SWREG136;                          /**< VPU H1 Register 136, offset: 0x220 */
  __O  uint32_t SWREG137;                          /**< VPU H1 Register 137, offset: 0x224 */
  __O  uint32_t SWREG138;                          /**< VPU H1 Register 138, offset: 0x228 */
  __O  uint32_t SWREG139;                          /**< VPU H1 Register 139, offset: 0x22C */
  __O  uint32_t SWREG140;                          /**< VPU H1 Register 140, offset: 0x230 */
  __O  uint32_t SWREG141;                          /**< VPU H1 Register 141, offset: 0x234 */
  __O  uint32_t SWREG142;                          /**< VPU H1 Register 142, offset: 0x238 */
  __O  uint32_t SWREG143;                          /**< VPU H1 Register 143, offset: 0x23C */
  __O  uint32_t SWREG144;                          /**< VPU H1 Register 144, offset: 0x240 */
  __O  uint32_t SWREG145;                          /**< VPU H1 Register 145, offset: 0x244 */
  __O  uint32_t SWREG146;                          /**< VPU H1 Register 146, offset: 0x248 */
  __O  uint32_t SWREG147;                          /**< VPU H1 Register 147, offset: 0x24C */
  __O  uint32_t SWREG148;                          /**< VPU H1 Register 148, offset: 0x250 */
  __O  uint32_t SWREG149;                          /**< VPU H1 Register 149, offset: 0x254 */
  __O  uint32_t SWREG150;                          /**< VPU H1 Register 150, offset: 0x258 */
  __O  uint32_t SWREG151;                          /**< VPU H1 Register 151, offset: 0x25C */
  __O  uint32_t SWREG152;                          /**< VPU H1 Register 152, offset: 0x260 */
  __O  uint32_t SWREG153;                          /**< VPU H1 Register 153, offset: 0x264 */
  __O  uint32_t SWREG154;                          /**< VPU H1 Register 154, offset: 0x268 */
  __O  uint32_t SWREG155;                          /**< VPU H1 Register 155, offset: 0x26C */
  __O  uint32_t SWREG156;                          /**< VPU H1 Register 156, offset: 0x270 */
  __O  uint32_t SWREG157;                          /**< VPU H1 Register 157, offset: 0x274 */
  __O  uint32_t SWREG158;                          /**< VPU H1 Register 158, offset: 0x278 */
  __O  uint32_t SWREG159;                          /**< VPU H1 Register 159, offset: 0x27C */
  __IO uint32_t SWREG160;                          /**< VPU H1 Register 160, offset: 0x280 */
  __IO uint32_t SWREG161;                          /**< VPU H1 Register 161, offset: 0x284 */
  __IO uint32_t SWREG162;                          /**< VPU H1 Register 162, offset: 0x288 */
  __IO uint32_t SWREG163;                          /**< VPU H1 Register 163, offset: 0x28C */
  __IO uint32_t SWREG164;                          /**< VPU H1 Register 164, offset: 0x290 */
  __IO uint32_t SWREG165;                          /**< VPU H1 Register 165, offset: 0x294 */
  __IO uint32_t SWREG166;                          /**< VPU H1 Register 166, offset: 0x298 */
  __IO uint32_t SWREG167;                          /**< VPU H1 Register 167, offset: 0x29C */
  __IO uint32_t SWREG168;                          /**< VPU H1 Register 168, offset: 0x2A0 */
  __IO uint32_t SWREG169;                          /**< VPU H1 Register 169, offset: 0x2A4 */
  __IO uint32_t SWREG170;                          /**< VPU H1 Register 170, offset: 0x2A8 */
  __IO uint32_t SWREG171;                          /**< VPU H1 Register 171, offset: 0x2AC */
  __IO uint32_t SWREG172;                          /**< VPU H1 Register 172, offset: 0x2B0 */
  __IO uint32_t SWREG173;                          /**< VPU H1 Register 173, offset: 0x2B4 */
  __IO uint32_t SWREG174;                          /**< VPU H1 Register 174, offset: 0x2B8 */
  __IO uint32_t SWREG175;                          /**< VPU H1 Register 175, offset: 0x2BC */
  __IO uint32_t SWREG176;                          /**< VPU H1 Register 176, offset: 0x2C0 */
  __IO uint32_t SWREG177;                          /**< VPU H1 Register 177, offset: 0x2C4 */
  __IO uint32_t SWREG178;                          /**< VPU H1 Register 178, offset: 0x2C8 */
  __IO uint32_t SWREG179;                          /**< VPU H1 Register 179, offset: 0x2CC */
  __IO uint32_t SWREG180;                          /**< VPU H1 Register 180, offset: 0x2D0 */
  __IO uint32_t SWREG181;                          /**< VPU H1 Register 181, offset: 0x2D4 */
  __IO uint32_t SWREG182;                          /**< VPU H1 Register 182, offset: 0x2D8 */
  __IO uint32_t SWREG183;                          /**< VPU H1 Register 183, offset: 0x2DC */
  __IO uint32_t SWREG184;                          /**< VPU H1 Register 184, offset: 0x2E0 */
  __IO uint32_t SWREG185;                          /**< VPU H1 Register 185, offset: 0x2E4 */
  __IO uint32_t SWREG186;                          /**< VPU H1 Register 186, offset: 0x2E8 */
  __IO uint32_t SWREG187;                          /**< VPU H1 Register 187, offset: 0x2EC */
  __IO uint32_t SWREG188;                          /**< VPU H1 Register 188, offset: 0x2F0 */
  __IO uint32_t SWREG189;                          /**< VPU H1 Register 189, offset: 0x2F4 */
  __IO uint32_t SWREG190;                          /**< VPU H1 Register 190, offset: 0x2F8 */
  __IO uint32_t SWREG191;                          /**< VPU H1 Register 191, offset: 0x2FC */
  __IO uint32_t SWREG192;                          /**< VPU H1 Register 192, offset: 0x300 */
  __IO uint32_t SWREG193;                          /**< VPU H1 Register 193, offset: 0x304 */
  __IO uint32_t SWREG194;                          /**< VPU H1 Register 194, offset: 0x308 */
  __IO uint32_t SWREG195;                          /**< VPU H1 Register 195, offset: 0x30C */
  __IO uint32_t SWREG196;                          /**< VPU H1 Register 196, offset: 0x310 */
  __IO uint32_t SWREG197;                          /**< VPU H1 Register 197, offset: 0x314 */
  __IO uint32_t SWREG198;                          /**< VPU H1 Register 198, offset: 0x318 */
  __IO uint32_t SWREG199;                          /**< VPU H1 Register 199, offset: 0x31C */
  __IO uint32_t SWREG200;                          /**< VPU H1 Register 200, offset: 0x320 */
  __IO uint32_t SWREG201;                          /**< VPU H1 Register 201, offset: 0x324 */
  __IO uint32_t SWREG202;                          /**< VPU H1 Register 202, offset: 0x328 */
  __IO uint32_t SWREG203;                          /**< VPU H1 Register 203, offset: 0x32C */
  __IO uint32_t SWREG204;                          /**< VPU H1 Register 204, offset: 0x330 */
  __IO uint32_t SWREG205;                          /**< VPU H1 Register 205, offset: 0x334 */
  __IO uint32_t SWREG206;                          /**< VPU H1 Register 206, offset: 0x338 */
  __IO uint32_t SWREG207;                          /**< VPU H1 Register 207, offset: 0x33C */
  __IO uint32_t SWREG208;                          /**< VPU H1 Register 208, offset: 0x340 */
  __IO uint32_t SWREG209;                          /**< VPU H1 Register 209, offset: 0x344 */
  __IO uint32_t SWREG210;                          /**< VPU H1 Register 210, offset: 0x348 */
  __IO uint32_t SWREG211;                          /**< VPU H1 Register 211, offset: 0x34C */
  __IO uint32_t SWREG212;                          /**< VPU H1 Register 212, offset: 0x350 */
  __IO uint32_t SWREG213;                          /**< VPU H1 Register 213, offset: 0x354 */
  __IO uint32_t SWREG214;                          /**< VPU H1 Register 214, offset: 0x358 */
  __IO uint32_t SWREG215;                          /**< VPU H1 Register 215, offset: 0x35C */
  __IO uint32_t SWREG216;                          /**< VPU H1 Register 216, offset: 0x360 */
  __IO uint32_t SWREG217;                          /**< VPU H1 Register 217, offset: 0x364 */
  __IO uint32_t SWREG218;                          /**< VPU H1 Register 218, offset: 0x368 */
  __IO uint32_t SWREG219;                          /**< VPU H1 Register 219, offset: 0x36C */
  __IO uint32_t SWREG220;                          /**< VPU H1 Register 220, offset: 0x370 */
  __IO uint32_t SWREG221;                          /**< VPU H1 Register 221, offset: 0x374 */
  __IO uint32_t SWREG222;                          /**< VPU H1 Register 222, offset: 0x378 */
  __IO uint32_t SWREG223;                          /**< VPU H1 Register 223, offset: 0x37C */
  __IO uint32_t SWREG224;                          /**< VPU H1 Register 224, offset: 0x380 */
  __IO uint32_t SWREG225;                          /**< VPU H1 Register 225, offset: 0x384 */
  __IO uint32_t SWREG226;                          /**< VPU H1 Register 226, offset: 0x388 */
  __IO uint32_t SWREG227;                          /**< VPU H1 Register 227, offset: 0x38C */
  __IO uint32_t SWREG228;                          /**< VPU H1 Register 228, offset: 0x390 */
  __IO uint32_t SWREG229;                          /**< VPU H1 Register 229, offset: 0x394 */
  __IO uint32_t SWREG230;                          /**< VPU H1 Register 230, offset: 0x398 */
  __IO uint32_t SWREG231;                          /**< VPU H1 Register 231, offset: 0x39C */
  __IO uint32_t SWREG232;                          /**< VPU H1 Register 232, offset: 0x3A0 */
  __IO uint32_t SWREG233;                          /**< VPU H1 Register 233, offset: 0x3A4 */
       uint8_t RESERVED_5[8];
  __IO uint32_t SWREG236;                          /**< VPU H1 Register 236, offset: 0x3B0 */
  __IO uint32_t SWREG237;                          /**< VPU H1 Register 237, offset: 0x3B4 */
  __IO uint32_t SWREG238;                          /**< VPU H1 Register 238, offset: 0x3B8 */
  __IO uint32_t SWREG239;                          /**< VPU H1 Register 239, offset: 0x3BC */
  __IO uint32_t SWREG240;                          /**< VPU H1 Register 240, offset: 0x3C0 */
  __IO uint32_t SWREG241;                          /**< VPU H1 Register 241, offset: 0x3C4 */
  __IO uint32_t SWREG242;                          /**< VPU H1 Register 242, offset: 0x3C8 */
  __IO uint32_t SWREG243;                          /**< VPU H1 Register 243, offset: 0x3CC */
  __IO uint32_t SWREG244;                          /**< VPU H1 Register 244, offset: 0x3D0 */
  __IO uint32_t SWREG245;                          /**< VPU H1 Register 245, offset: 0x3D4 */
       uint8_t RESERVED_6[40];
  __IO uint32_t SWREG256;                          /**< VPU H1 Register 256, offset: 0x400 */
  __IO uint32_t SWREG257;                          /**< VPU H1 Register 257, offset: 0x404 */
  __IO uint32_t SWREG258;                          /**< VPU H1 Register 258, offset: 0x408 */
  __IO uint32_t SWREG259;                          /**< VPU H1 Register 259, offset: 0x40C */
  __IO uint32_t SWREG260;                          /**< VPU H1 Register 260, offset: 0x410 */
  __IO uint32_t SWREG261;                          /**< VPU H1 Register 261, offset: 0x414 */
  __IO uint32_t SWREG262;                          /**< VPU H1 Register 262, offset: 0x418 */
  __IO uint32_t SWREG263;                          /**< VPU H1 Register 263, offset: 0x41C */
  __IO uint32_t SWREG264;                          /**< VPU H1 Register 264, offset: 0x420 */
  __IO uint32_t SWREG265;                          /**< VPU H1 Register 265, offset: 0x424 */
  __IO uint32_t SWREG266;                          /**< VPU H1 Register 266, offset: 0x428 */
  __IO uint32_t SWREG267;                          /**< VPU H1 Register 267, offset: 0x42C */
  __IO uint32_t SWREG268;                          /**< VPU H1 Register 268, offset: 0x430 */
  __IO uint32_t SWREG269;                          /**< VPU H1 Register 269, offset: 0x434 */
  __IO uint32_t SWREG270;                          /**< VPU H1 Register 270, offset: 0x438 */
  __IO uint32_t SWREG271;                          /**< VPU H1 Register 271, offset: 0x43C */
  __IO uint32_t SWREG272;                          /**< VPU H1 Register 272, offset: 0x440 */
  __IO uint32_t SWREG273;                          /**< VPU H1 Register 273, offset: 0x444 */
  __IO uint32_t SWREG274;                          /**< VPU H1 Register 274, offset: 0x448 */
  __IO uint32_t SWREG275;                          /**< VPU H1 Register 275, offset: 0x44C */
  __IO uint32_t SWREG276;                          /**< VPU H1 Register 276, offset: 0x450 */
  __IO uint32_t SWREG277;                          /**< VPU H1 Register 277, offset: 0x454 */
  __IO uint32_t SWREG278;                          /**< VPU H1 Register 278, offset: 0x458 */
  __IO uint32_t SWREG279;                          /**< VPU H1 Register 279, offset: 0x45C */
  __IO uint32_t SWREG280;                          /**< VPU H1 Register 280, offset: 0x460 */
  __IO uint32_t SWREG281;                          /**< VPU H1 Register 281, offset: 0x464 */
  __IO uint32_t SWREG282;                          /**< VPU H1 Register 282, offset: 0x468 */
  __IO uint32_t SWREG283;                          /**< VPU H1 Register 283, offset: 0x46C */
  __IO uint32_t SWREG284;                          /**< VPU H1 Register 284, offset: 0x470 */
  __IO uint32_t SWREG285;                          /**< VPU H1 Register 285, offset: 0x474 */
  __IO uint32_t SWREG286;                          /**< VPU H1 Register 286, offset: 0x478 */
  __IO uint32_t SWREG287;                          /**< VPU H1 Register 287, offset: 0x47C */
  __IO uint32_t SWREG288;                          /**< VPU H1 Register 288, offset: 0x480 */
  __IO uint32_t SWREG289;                          /**< VPU H1 Register 289, offset: 0x484 */
  __IO uint32_t SWREG290;                          /**< VPU H1 Register 290, offset: 0x488 */
  __IO uint32_t SWREG291;                          /**< VPU H1 Register 291, offset: 0x48C */
  __IO uint32_t SWREG292;                          /**< VPU H1 Register 292, offset: 0x490 */
  __IO uint32_t SWREG293;                          /**< VPU H1 Register 293, offset: 0x494 */
  __IO uint32_t SWREG294;                          /**< VPU H1 Register 294, offset: 0x498 */
  __IO uint32_t SWREG295;                          /**< VPU H1 Register 295, offset: 0x49C */
  __I  uint32_t SWREG296;                          /**< VPU H1 Register 296, offset: 0x4A0 */
  __IO uint32_t SWREG297;                          /**< VPU H1 Register 297, offset: 0x4A4 */
  __IO uint32_t SWREG298;                          /**< VPU H1 Register 298, offset: 0x4A8 */
  __IO uint32_t SWREG299;                          /**< VPU H1 Register 299, offset: 0x4AC */
  __IO uint32_t SWREG300;                          /**< VPU H1 Register 300, offset: 0x4B0 */
  __IO uint32_t SWREG301;                          /**< VPU H1 Register 301, offset: 0x4B4 */
  __IO uint32_t SWREG302;                          /**< VPU H1 Register 302, offset: 0x4B8 */
  __IO uint32_t SWREG303;                          /**< VPU H1 Register 303, offset: 0x4BC */
  __IO uint32_t SWREG304;                          /**< VPU H1 Register 304, offset: 0x4C0 */
  __IO uint32_t SWREG305;                          /**< VPU H1 Register 305, offset: 0x4C4 */
  __IO uint32_t SWREG306;                          /**< VPU H1 Register 306, offset: 0x4C8 */
  __IO uint32_t SWREG307;                          /**< VPU H1 Register 307, offset: 0x4CC */
  __IO uint32_t SWREG308;                          /**< VPU H1 Register 308, offset: 0x4D0 */
  __IO uint32_t SWREG309;                          /**< VPU H1 Register 309, offset: 0x4D4 */
  __IO uint32_t SWREG310;                          /**< VPU H1 Register 310, offset: 0x4D8 */
  __IO uint32_t SWREG311;                          /**< VPU H1 Register 311, offset: 0x4DC */
  __IO uint32_t SWREG312;                          /**< VPU H1 Register 312, offset: 0x4E0 */
  __IO uint32_t SWREG313;                          /**< VPU H1 Register 313, offset: 0x4E4 */
  __IO uint32_t SWREG314;                          /**< VPU H1 Register 314, offset: 0x4E8 */
  __IO uint32_t SWREG315;                          /**< VPU H1 Register 315, offset: 0x4EC */
  __IO uint32_t SWREG316;                          /**< VPU H1 Register 316, offset: 0x4F0 */
  __IO uint32_t SWREG317;                          /**< VPU H1 Register 317, offset: 0x4F4 */
  __IO uint32_t SWREG318;                          /**< VPU H1 Register 318, offset: 0x4F8 */
  __IO uint32_t SWREG319;                          /**< VPU H1 Register 319, offset: 0x4FC */
  __IO uint32_t SWREG320;                          /**< VPU H1 Register 320, offset: 0x500 */
  __IO uint32_t SWREG321;                          /**< VPU H1 Register 321, offset: 0x504 */
  __IO uint32_t SWREG322;                          /**< VPU H1 Register 322, offset: 0x508 */
  __IO uint32_t SWREG323;                          /**< VPU H1 Register 323, offset: 0x50C */
  __IO uint32_t SWREG324;                          /**< VPU H1 Register 324, offset: 0x510 */
  __IO uint32_t SWREG325;                          /**< VPU H1 Register 325, offset: 0x514 */
  __IO uint32_t SWREG326;                          /**< VPU H1 Register 326, offset: 0x518 */
  __IO uint32_t SWREG327;                          /**< VPU H1 Register 327, offset: 0x51C */
  __IO uint32_t SWREG328;                          /**< VPU H1 Register 328, offset: 0x520 */
  __IO uint32_t SWREG329;                          /**< VPU H1 Register 329, offset: 0x524 */
  __IO uint32_t SWREG330;                          /**< VPU H1 Register 330, offset: 0x528 */
  __IO uint32_t SWREG331;                          /**< VPU H1 Register 331, offset: 0x52C */
  __IO uint32_t SWREG332;                          /**< VPU H1 Register 332, offset: 0x530 */
  __IO uint32_t SWREG333;                          /**< VPU H1 Register 333, offset: 0x534 */
  __IO uint32_t SWREG334;                          /**< VPU H1 Register 334, offset: 0x538 */
  __IO uint32_t SWREG335;                          /**< VPU H1 Register 335, offset: 0x53C */
  __IO uint32_t SWREG336;                          /**< VPU H1 Register 336, offset: 0x540 */
  __IO uint32_t SWREG337;                          /**< VPU H1 Register 337, offset: 0x544 */
  __IO uint32_t SWREG338;                          /**< VPU H1 Register 338, offset: 0x548 */
  __IO uint32_t SWREG339;                          /**< VPU H1 Register 339, offset: 0x54C */
  __IO uint32_t SWREG340;                          /**< VPU H1 Register 340, offset: 0x550 */
  __IO uint32_t SWREG341;                          /**< VPU H1 Register 341, offset: 0x554 */
  __IO uint32_t SWREG342;                          /**< VPU H1 Register 342, offset: 0x558 */
  __IO uint32_t SWREG343;                          /**< VPU H1 Register 343, offset: 0x55C */
  __IO uint32_t SWREG344;                          /**< VPU H1 Register 344, offset: 0x560 */
  __IO uint32_t SWREG345;                          /**< VPU H1 Register 345, offset: 0x564 */
  __IO uint32_t SWREG346;                          /**< VPU H1 Register 346, offset: 0x568 */
  __IO uint32_t SWREG347;                          /**< VPU H1 Register 347, offset: 0x56C */
  __IO uint32_t SWREG348;                          /**< VPU H1 Register 348, offset: 0x570 */
  __IO uint32_t SWREG349;                          /**< VPU H1 Register 349, offset: 0x574 */
  __IO uint32_t SWREG350;                          /**< VPU H1 Register 350, offset: 0x578 */
  __IO uint32_t SWREG351;                          /**< VPU H1 Register 351, offset: 0x57C */
  __IO uint32_t SWREG352;                          /**< VPU H1 Register 352, offset: 0x580 */
  __IO uint32_t SWREG353;                          /**< VPU H1 Register 353, offset: 0x584 */
  __IO uint32_t SWREG354;                          /**< VPU H1 Register 354, offset: 0x588 */
  __IO uint32_t SWREG355;                          /**< VPU H1 Register 355, offset: 0x58C */
  __IO uint32_t SWREG356;                          /**< VPU H1 Register 356, offset: 0x590 */
  __IO uint32_t SWREG357;                          /**< VPU H1 Register 357, offset: 0x594 */
  __IO uint32_t SWREG358;                          /**< VPU H1 Register 358, offset: 0x598 */
  __IO uint32_t SWREG359;                          /**< VPU H1 Register 359, offset: 0x59C */
  __IO uint32_t SWREG360;                          /**< VPU H1 Register 360, offset: 0x5A0 */
  __IO uint32_t SWREG361;                          /**< VPU H1 Register 361, offset: 0x5A4 */
  __IO uint32_t SWREG362;                          /**< VPU H1 Register 362, offset: 0x5A8 */
  __IO uint32_t SWREG363;                          /**< VPU H1 Register 363, offset: 0x5AC */
  __IO uint32_t SWREG364;                          /**< VPU H1 Register 364, offset: 0x5B0 */
  __IO uint32_t SWREG365;                          /**< VPU H1 Register 365, offset: 0x5B4 */
  __IO uint32_t SWREG366;                          /**< VPU H1 Register 366, offset: 0x5B8 */
  __IO uint32_t SWREG367;                          /**< VPU H1 Register 367, offset: 0x5BC */
  __IO uint32_t SWREG368;                          /**< VPU H1 Register 368, offset: 0x5C0 */
  __IO uint32_t SWREG369;                          /**< VPU H1 Register 369, offset: 0x5C4 */
  __IO uint32_t SWREG370;                          /**< VPU H1 Register 370, offset: 0x5C8 */
  __IO uint32_t SWREG371;                          /**< VPU H1 Register 371, offset: 0x5CC */
  __IO uint32_t SWREG372;                          /**< VPU H1 Register 372, offset: 0x5D0 */
  __IO uint32_t SWREG373;                          /**< VPU H1 Register 373, offset: 0x5D4 */
  __IO uint32_t SWREG374;                          /**< VPU H1 Register 374, offset: 0x5D8 */
  __IO uint32_t SWREG375;                          /**< VPU H1 Register 375, offset: 0x5DC */
  __IO uint32_t SWREG376;                          /**< VPU H1 Register 376, offset: 0x5E0 */
  __IO uint32_t SWREG377;                          /**< VPU H1 Register 377, offset: 0x5E4 */
  __IO uint32_t SWREG378;                          /**< VPU H1 Register 378, offset: 0x5E8 */
  __IO uint32_t SWREG379;                          /**< VPU H1 Register 379, offset: 0x5EC */
  __IO uint32_t SWREG380;                          /**< VPU H1 Register 380, offset: 0x5F0 */
  __IO uint32_t SWREG381;                          /**< VPU H1 Register 381, offset: 0x5F4 */
  __IO uint32_t SWREG382;                          /**< VPU H1 Register 382, offset: 0x5F8 */
  __IO uint32_t SWREG383;                          /**< VPU H1 Register 383, offset: 0x5FC */
  __IO uint32_t SWREG384;                          /**< VPU H1 Register 384, offset: 0x600 */
  __IO uint32_t SWREG385;                          /**< VPU H1 Register 385, offset: 0x604 */
  __IO uint32_t SWREG386;                          /**< VPU H1 Register 386, offset: 0x608 */
  __IO uint32_t SWREG387;                          /**< VPU H1 Register 387, offset: 0x60C */
  __IO uint32_t SWREG388;                          /**< VPU H1 Register 388, offset: 0x610 */
  __IO uint32_t SWREG389;                          /**< VPU H1 Register 389, offset: 0x614 */
  __IO uint32_t SWREG390;                          /**< VPU H1 Register 390, offset: 0x618 */
  __IO uint32_t SWREG391;                          /**< VPU H1 Register 391, offset: 0x61C */
  __IO uint32_t SWREG392;                          /**< VPU H1 Register 392, offset: 0x620 */
  __IO uint32_t SWREG393;                          /**< VPU H1 Register 393, offset: 0x624 */
  __IO uint32_t SWREG394;                          /**< VPU H1 Register 394, offset: 0x628 */
  __IO uint32_t SWREG395;                          /**< VPU H1 Register 395, offset: 0x62C */
  __IO uint32_t SWREG396;                          /**< VPU H1 Register 396, offset: 0x630 */
  __IO uint32_t SWREG397;                          /**< VPU H1 Register 397, offset: 0x634 */
  __IO uint32_t SWREG398;                          /**< VPU H1 Register 398, offset: 0x638 */
  __IO uint32_t SWREG399;                          /**< VPU H1 Register 399, offset: 0x63C */
  __IO uint32_t SWREG400;                          /**< VPU H1 Register 400, offset: 0x640 */
  __IO uint32_t SWREG401;                          /**< VPU H1 Register 401, offset: 0x644 */
  __IO uint32_t SWREG402;                          /**< VPU H1 Register 402, offset: 0x648 */
  __IO uint32_t SWREG403;                          /**< VPU H1 Register 403, offset: 0x64C */
  __IO uint32_t SWREG404;                          /**< VPU H1 Register 404, offset: 0x650 */
  __IO uint32_t SWREG405;                          /**< VPU H1 Register 405, offset: 0x654 */
  __IO uint32_t SWREG406;                          /**< VPU H1 Register 406, offset: 0x658 */
  __IO uint32_t SWREG407;                          /**< VPU H1 Register 407, offset: 0x65C */
  __IO uint32_t SWREG408;                          /**< VPU H1 Register 408, offset: 0x660 */
  __IO uint32_t SWREG409;                          /**< VPU H1 Register 409, offset: 0x664 */
  __IO uint32_t SWREG410;                          /**< VPU H1 Register 410, offset: 0x668 */
  __IO uint32_t SWREG411;                          /**< VPU H1 Register 411, offset: 0x66C */
  __IO uint32_t SWREG412;                          /**< VPU H1 Register 412, offset: 0x670 */
  __IO uint32_t SWREG413;                          /**< VPU H1 Register 413, offset: 0x674 */
  __IO uint32_t SWREG414;                          /**< VPU H1 Register 414, offset: 0x678 */
  __IO uint32_t SWREG415;                          /**< VPU H1 Register 415, offset: 0x67C */
  __IO uint32_t SWREG416;                          /**< VPU H1 Register 416, offset: 0x680 */
  __IO uint32_t SWREG417;                          /**< VPU H1 Register 417, offset: 0x684 */
  __IO uint32_t SWREG418;                          /**< VPU H1 Register 418, offset: 0x688 */
  __IO uint32_t SWREG419;                          /**< VPU H1 Register 419, offset: 0x68C */
  __IO uint32_t SWREG420;                          /**< VPU H1 Register 420, offset: 0x690 */
  __IO uint32_t SWREG421;                          /**< VPU H1 Register 421, offset: 0x694 */
  __IO uint32_t SWREG422;                          /**< VPU H1 Register 422, offset: 0x698 */
  __IO uint32_t SWREG423;                          /**< VPU H1 Register 423, offset: 0x69C */
  __IO uint32_t SWREG424;                          /**< VPU H1 Register 424, offset: 0x6A0 */
  __IO uint32_t SWREG425;                          /**< VPU H1 Register 425, offset: 0x6A4 */
  __IO uint32_t SWREG426;                          /**< VPU H1 Register 426, offset: 0x6A8 */
  __IO uint32_t SWREG427;                          /**< VPU H1 Register 427, offset: 0x6AC */
  __IO uint32_t SWREG428;                          /**< VPU H1 Register 428, offset: 0x6B0 */
  __IO uint32_t SWREG429;                          /**< VPU H1 Register 429, offset: 0x6B4 */
  __IO uint32_t SWREG430;                          /**< VPU H1 Register 430, offset: 0x6B8 */
  __IO uint32_t SWREG431;                          /**< VPU H1 Register 431, offset: 0x6BC */
  __IO uint32_t SWREG432;                          /**< VPU H1 Register 432, offset: 0x6C0 */
  __IO uint32_t SWREG433;                          /**< VPU H1 Register 433, offset: 0x6C4 */
  __IO uint32_t SWREG434;                          /**< VPU H1 Register 434, offset: 0x6C8 */
  __IO uint32_t SWREG435;                          /**< VPU H1 Register 435, offset: 0x6CC */
  __IO uint32_t SWREG436;                          /**< VPU H1 Register 436, offset: 0x6D0 */
  __IO uint32_t SWREG437;                          /**< VPU H1 Register 437, offset: 0x6D4 */
  __IO uint32_t SWREG438;                          /**< VPU H1 Register 438, offset: 0x6D8 */
  __IO uint32_t SWREG439;                          /**< VPU H1 Register 439, offset: 0x6DC */
  __IO uint32_t SWREG440;                          /**< VPU H1 Register 440, offset: 0x6E0 */
  __IO uint32_t SWREG441;                          /**< VPU H1 Register 441, offset: 0x6E4 */
  __IO uint32_t SWREG442;                          /**< VPU H1 Register 442, offset: 0x6E8 */
  __IO uint32_t SWREG443;                          /**< VPU H1 Register 443, offset: 0x6EC */
  __IO uint32_t SWREG444;                          /**< VPU H1 Register 444, offset: 0x6F0 */
  __IO uint32_t SWREG445;                          /**< VPU H1 Register 445, offset: 0x6F4 */
  __IO uint32_t SWREG446;                          /**< VPU H1 Register 446, offset: 0x6F8 */
  __IO uint32_t SWREG447;                          /**< VPU H1 Register 447, offset: 0x6FC */
  __IO uint32_t SWREG448;                          /**< VPU H1 Register 448, offset: 0x700 */
  __IO uint32_t SWREG449;                          /**< VPU H1 Register 449, offset: 0x704 */
  __IO uint32_t SWREG450;                          /**< VPU H1 Register 450, offset: 0x708 */
  __IO uint32_t SWREG451;                          /**< VPU H1 Register 451, offset: 0x70C */
  __IO uint32_t SWREG452;                          /**< VPU H1 Register 452, offset: 0x710 */
  __IO uint32_t SWREG453;                          /**< VPU H1 Register 453, offset: 0x714 */
  __IO uint32_t SWREG454;                          /**< VPU H1 Register 454, offset: 0x718 */
  __IO uint32_t SWREG455;                          /**< VPU H1 Register 455, offset: 0x71C */
  __IO uint32_t SWREG456;                          /**< VPU H1 Register 456, offset: 0x720 */
  __O  uint32_t SWREG457;                          /**< VPU H1 Register 457, offset: 0x724 */
  __O  uint32_t SWREG458;                          /**< VPU H1 Register 458, offset: 0x728 */
  __O  uint32_t SWREG459;                          /**< VPU H1 Register 459, offset: 0x72C */
  __O  uint32_t SWREG460;                          /**< VPU H1 Register 460, offset: 0x730 */
  __O  uint32_t SWREG461;                          /**< VPU H1 Register 461, offset: 0x734 */
  __O  uint32_t SWREG462;                          /**< VPU H1 Register 462, offset: 0x738 */
  __O  uint32_t SWREG463;                          /**< VPU H1 Register 463, offset: 0x73C */
  __O  uint32_t SWREG464;                          /**< VPU H1 Register 464, offset: 0x740 */
  __O  uint32_t SWREG465;                          /**< VPU H1 Register 465, offset: 0x744 */
  __O  uint32_t SWREG466;                          /**< VPU H1 Register 466, offset: 0x748 */
  __O  uint32_t SWREG467;                          /**< VPU H1 Register 467, offset: 0x74C */
  __O  uint32_t SWREG468;                          /**< VPU H1 Register 468, offset: 0x750 */
  __O  uint32_t SWREG469;                          /**< VPU H1 Register 469, offset: 0x754 */
  __O  uint32_t SWREG470;                          /**< VPU H1 Register 470, offset: 0x758 */
  __O  uint32_t SWREG471;                          /**< VPU H1 Register 471, offset: 0x75C */
  __O  uint32_t SWREG472;                          /**< VPU H1 Register 472, offset: 0x760 */
  __O  uint32_t SWREG473;                          /**< VPU H1 Register 473, offset: 0x764 */
  __O  uint32_t SWREG474;                          /**< VPU H1 Register 474, offset: 0x768 */
  __O  uint32_t SWREG475;                          /**< VPU H1 Register 475, offset: 0x76C */
  __O  uint32_t SWREG476;                          /**< VPU H1 Register 476, offset: 0x770 */
  __O  uint32_t SWREG477;                          /**< VPU H1 Register 477, offset: 0x774 */
  __O  uint32_t SWREG478;                          /**< VPU H1 Register 478, offset: 0x778 */
  __O  uint32_t SWREG479;                          /**< VPU H1 Register 479, offset: 0x77C */
  __O  uint32_t SWREG480;                          /**< VPU H1 Register 480, offset: 0x780 */
  __O  uint32_t SWREG481;                          /**< VPU H1 Register 481, offset: 0x784 */
  __O  uint32_t SWREG482;                          /**< VPU H1 Register 482, offset: 0x788 */
  __O  uint32_t SWREG483;                          /**< VPU H1 Register 483, offset: 0x78C */
  __O  uint32_t SWREG484;                          /**< VPU H1 Register 484, offset: 0x790 */
  __O  uint32_t SWREG485;                          /**< VPU H1 Register 485, offset: 0x794 */
  __O  uint32_t SWREG486;                          /**< VPU H1 Register 486, offset: 0x798 */
  __O  uint32_t SWREG487;                          /**< VPU H1 Register 487, offset: 0x79C */
  __O  uint32_t SWREG488;                          /**< VPU H1 Register 488, offset: 0x7A0 */
  __O  uint32_t SWREG489;                          /**< VPU H1 Register 489, offset: 0x7A4 */
  __O  uint32_t SWREG490;                          /**< VPU H1 Register 490, offset: 0x7A8 */
  __O  uint32_t SWREG491;                          /**< VPU H1 Register 491, offset: 0x7AC */
  __O  uint32_t SWREG492;                          /**< VPU H1 Register 492, offset: 0x7B0 */
  __O  uint32_t SWREG493;                          /**< VPU H1 Register 493, offset: 0x7B4 */
  __O  uint32_t SWREG494;                          /**< VPU H1 Register 494, offset: 0x7B8 */
  __O  uint32_t SWREG495;                          /**< VPU H1 Register 495, offset: 0x7BC */
  __O  uint32_t SWREG496;                          /**< VPU H1 Register 496, offset: 0x7C0 */
  __IO uint32_t SWREG497;                          /**< VPU H1 Register 497, offset: 0x7C4 */
} VPU_H1_Type;

/* ----------------------------------------------------------------------------
   -- VPU_H1 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VPU_H1_Register_Masks VPU_H1 Register Masks
 * @{
 */

/*! @name SWREG0 - VPU H1 Register 0 */
/*! @{ */

#define VPU_H1_SWREG0_BF_0_MASK                  (0xFU)
#define VPU_H1_SWREG0_BF_0_SHIFT                 (0U)
/*! BF_0 - Build number defined in synthesis. */
#define VPU_H1_SWREG0_BF_0(x)                    (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG0_BF_0_SHIFT)) & VPU_H1_SWREG0_BF_0_MASK)

#define VPU_H1_SWREG0_BF_4_MASK                  (0xFF0U)
#define VPU_H1_SWREG0_BF_4_SHIFT                 (4U)
/*! BF_4 - Minor number */
#define VPU_H1_SWREG0_BF_4(x)                    (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG0_BF_4_SHIFT)) & VPU_H1_SWREG0_BF_4_MASK)

#define VPU_H1_SWREG0_BF_12_MASK                 (0xF000U)
#define VPU_H1_SWREG0_BF_12_SHIFT                (12U)
/*! BF_12 - Major number */
#define VPU_H1_SWREG0_BF_12(x)                   (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG0_BF_12_SHIFT)) & VPU_H1_SWREG0_BF_12_MASK)

#define VPU_H1_SWREG0_BF_16_MASK                 (0xFFFF0000U)
#define VPU_H1_SWREG0_BF_16_SHIFT                (16U)
/*! BF_16 - Product ID */
#define VPU_H1_SWREG0_BF_16(x)                   (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG0_BF_16_SHIFT)) & VPU_H1_SWREG0_BF_16_MASK)
/*! @} */

/*! @name SWREG1 - VPU H1 Register 1 */
/*! @{ */

#define VPU_H1_SWREG1_BF_0_MASK                  (0x1U)
#define VPU_H1_SWREG1_BF_0_SHIFT                 (0U)
/*! BF_0 - HINTenc Interrupt from HW. SW resets at IRQ handler. */
#define VPU_H1_SWREG1_BF_0(x)                    (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG1_BF_0_SHIFT)) & VPU_H1_SWREG1_BF_0_MASK)

#define VPU_H1_SWREG1_BF_1_MASK                  (0x2U)
#define VPU_H1_SWREG1_BF_1_SHIFT                 (1U)
/*! BF_1 - IRQ disable. No interrupts from HW. SW must use polling. */
#define VPU_H1_SWREG1_BF_1(x)                    (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG1_BF_1_SHIFT)) & VPU_H1_SWREG1_BF_1_MASK)

#define VPU_H1_SWREG1_BF_2_MASK                  (0x4U)
#define VPU_H1_SWREG1_BF_2_SHIFT                 (2U)
/*! BF_2 - IRQ frame ready status bit. Encoder has finished a frame. */
#define VPU_H1_SWREG1_BF_2(x)                    (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG1_BF_2_SHIFT)) & VPU_H1_SWREG1_BF_2_MASK)

#define VPU_H1_SWREG1_BF_3_MASK                  (0x8U)
#define VPU_H1_SWREG1_BF_3_SHIFT                 (3U)
/*! BF_3 - IRQ bus error status bit. */
#define VPU_H1_SWREG1_BF_3(x)                    (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG1_BF_3_SHIFT)) & VPU_H1_SWREG1_BF_3_MASK)

#define VPU_H1_SWREG1_BF_4_MASK                  (0x10U)
#define VPU_H1_SWREG1_BF_4_SHIFT                 (4U)
/*! BF_4 - IRQ SW reset status bit. */
#define VPU_H1_SWREG1_BF_4(x)                    (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG1_BF_4_SHIFT)) & VPU_H1_SWREG1_BF_4_MASK)

#define VPU_H1_SWREG1_BF_5_MASK                  (0x20U)
#define VPU_H1_SWREG1_BF_5_SHIFT                 (5U)
/*! BF_5 - IRQ buffer full status bit. bufferFullInterrupt */
#define VPU_H1_SWREG1_BF_5(x)                    (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG1_BF_5_SHIFT)) & VPU_H1_SWREG1_BF_5_MASK)

#define VPU_H1_SWREG1_BF_6_MASK                  (0x40U)
#define VPU_H1_SWREG1_BF_6_SHIFT                 (6U)
/*! BF_6 - IRQ HW timeout status bit. HW encoding failed. */
#define VPU_H1_SWREG1_BF_6(x)                    (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG1_BF_6_SHIFT)) & VPU_H1_SWREG1_BF_6_MASK)

#define VPU_H1_SWREG1_BF_8_MASK                  (0x100U)
#define VPU_H1_SWREG1_BF_8_SHIFT                 (8U)
/*! BF_8 - IRQ slice ready status bit. Slice is ready but frame encoding continues. */
#define VPU_H1_SWREG1_BF_8(x)                    (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG1_BF_8_SHIFT)) & VPU_H1_SWREG1_BF_8_MASK)

#define VPU_H1_SWREG1_BF_9_MASK                  (0x200U)
#define VPU_H1_SWREG1_BF_9_SHIFT                 (9U)
/*! BF_9 - IRQ stream format fuse status bit. Format disabled by fuse. */
#define VPU_H1_SWREG1_BF_9(x)                    (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG1_BF_9_SHIFT)) & VPU_H1_SWREG1_BF_9_MASK)

#define VPU_H1_SWREG1_BF_10_MASK                 (0x400U)
#define VPU_H1_SWREG1_BF_10_SHIFT                (10U)
/*! BF_10 - IRQ line buffer status bit. One line buffer reading has been done. */
#define VPU_H1_SWREG1_BF_10(x)                   (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG1_BF_10_SHIFT)) & VPU_H1_SWREG1_BF_10_MASK)

#define VPU_H1_SWREG1_BF_11_MASK                 (0x800U)
#define VPU_H1_SWREG1_BF_11_SHIFT                (11U)
/*! BF_11 - IRQ Compressed reference buffer overflow status bit. */
#define VPU_H1_SWREG1_BF_11(x)                   (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG1_BF_11_SHIFT)) & VPU_H1_SWREG1_BF_11_MASK)
/*! @} */

/*! @name SWREG2 - VPU H1 Register 2 */
/*! @{ */

#define VPU_H1_SWREG2_BF_0_MASK                  (0x1U)
#define VPU_H1_SWREG2_BF_0_SHIFT                 (0U)
/*! BF_0 - Enable input swap 8-bits */
#define VPU_H1_SWREG2_BF_0(x)                    (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG2_BF_0_SHIFT)) & VPU_H1_SWREG2_BF_0_MASK)

#define VPU_H1_SWREG2_BF_1_MASK                  (0x2U)
#define VPU_H1_SWREG2_BF_1_SHIFT                 (1U)
/*! BF_1 - Enable output stream swap 8-bits */
#define VPU_H1_SWREG2_BF_1(x)                    (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG2_BF_1_SHIFT)) & VPU_H1_SWREG2_BF_1_MASK)

#define VPU_H1_SWREG2_BF_2_MASK                  (0x4U)
#define VPU_H1_SWREG2_BF_2_SHIFT                 (2U)
/*! BF_2 - Enable input swap 32-bits */
#define VPU_H1_SWREG2_BF_2(x)                    (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG2_BF_2_SHIFT)) & VPU_H1_SWREG2_BF_2_MASK)

#define VPU_H1_SWREG2_BF_3_MASK                  (0x8U)
#define VPU_H1_SWREG2_BF_3_SHIFT                 (3U)
/*! BF_3 - Enable output stream swap 32-bits */
#define VPU_H1_SWREG2_BF_3(x)                    (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG2_BF_3_SHIFT)) & VPU_H1_SWREG2_BF_3_MASK)

#define VPU_H1_SWREG2_BF_4_MASK                  (0x10U)
#define VPU_H1_SWREG2_BF_4_SHIFT                 (4U)
/*! BF_4 - Enable clock gating */
#define VPU_H1_SWREG2_BF_4(x)                    (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG2_BF_4_SHIFT)) & VPU_H1_SWREG2_BF_4_MASK)

#define VPU_H1_SWREG2_BF_5_MASK                  (0x20U)
#define VPU_H1_SWREG2_BF_5_SHIFT                 (5U)
/*! BF_5 - Enable burst data discard. 2 or 3 long reads are using BURST4 */
#define VPU_H1_SWREG2_BF_5(x)                    (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG2_BF_5_SHIFT)) & VPU_H1_SWREG2_BF_5_MASK)

#define VPU_H1_SWREG2_BF_6_MASK                  (0x40U)
#define VPU_H1_SWREG2_BF_6_SHIFT                 (6U)
/*! BF_6 - Burst incremental. */
#define VPU_H1_SWREG2_BF_6(x)                    (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG2_BF_6_SHIFT)) & VPU_H1_SWREG2_BF_6_MASK)

#define VPU_H1_SWREG2_BF_7_MASK                  (0x80U)
#define VPU_H1_SWREG2_BF_7_SHIFT                 (7U)
/*! BF_7 - Disable burst mode for AXI */
#define VPU_H1_SWREG2_BF_7(x)                    (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG2_BF_7_SHIFT)) & VPU_H1_SWREG2_BF_7_MASK)

#define VPU_H1_SWREG2_BF_8_MASK                  (0x3F00U)
#define VPU_H1_SWREG2_BF_8_SHIFT                 (8U)
/*! BF_8 - Burst length. */
#define VPU_H1_SWREG2_BF_8(x)                    (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG2_BF_8_SHIFT)) & VPU_H1_SWREG2_BF_8_MASK)

#define VPU_H1_SWREG2_BF_14_MASK                 (0x4000U)
#define VPU_H1_SWREG2_BF_14_SHIFT                (14U)
/*! BF_14 - Enable input swap 16-bits */
#define VPU_H1_SWREG2_BF_14(x)                   (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG2_BF_14_SHIFT)) & VPU_H1_SWREG2_BF_14_MASK)

#define VPU_H1_SWREG2_BF_15_MASK                 (0x8000U)
#define VPU_H1_SWREG2_BF_15_SHIFT                (15U)
/*! BF_15 - Enable output stream swap 16-bits */
#define VPU_H1_SWREG2_BF_15(x)                   (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG2_BF_15_SHIFT)) & VPU_H1_SWREG2_BF_15_MASK)

#define VPU_H1_SWREG2_BF_16_MASK                 (0xFF0000U)
#define VPU_H1_SWREG2_BF_16_SHIFT                (16U)
/*! BF_16 - AXI Read ID */
#define VPU_H1_SWREG2_BF_16(x)                   (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG2_BF_16_SHIFT)) & VPU_H1_SWREG2_BF_16_MASK)

#define VPU_H1_SWREG2_BF_24_MASK                 (0xFF000000U)
#define VPU_H1_SWREG2_BF_24_SHIFT                (24U)
/*! BF_24 - AXI Write ID */
#define VPU_H1_SWREG2_BF_24(x)                   (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG2_BF_24_SHIFT)) & VPU_H1_SWREG2_BF_24_MASK)
/*! @} */

/*! @name SWREG3 - VPU H1 Register 3 */
/*! @{ */

#define VPU_H1_SWREG3_BF_0_MASK                  (0x1U)
#define VPU_H1_SWREG3_BF_0_SHIFT                 (0U)
/*! BF_0 - Enable MB bus timing info output. */
#define VPU_H1_SWREG3_BF_0(x)                    (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG3_BF_0_SHIFT)) & VPU_H1_SWREG3_BF_0_MASK)

#define VPU_H1_SWREG3_BF_20_MASK                 (0x100000U)
#define VPU_H1_SWREG3_BF_20_SHIFT                (20U)
/*! BF_20 - Disable dual channel AXI. */
#define VPU_H1_SWREG3_BF_20(x)                   (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG3_BF_20_SHIFT)) & VPU_H1_SWREG3_BF_20_MASK)

#define VPU_H1_SWREG3_BF_21_MASK                 (0x200000U)
#define VPU_H1_SWREG3_BF_21_SHIFT                (21U)
/*! BF_21 - Chunk size for input picture read. */
#define VPU_H1_SWREG3_BF_21(x)                   (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG3_BF_21_SHIFT)) & VPU_H1_SWREG3_BF_21_MASK)

#define VPU_H1_SWREG3_BF_22_MASK                 (0x400000U)
#define VPU_H1_SWREG3_BF_22_SHIFT                (22U)
/*! BF_22 - Enable output MV (MB info) swap for 32-bits */
#define VPU_H1_SWREG3_BF_22(x)                   (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG3_BF_22_SHIFT)) & VPU_H1_SWREG3_BF_22_MASK)

#define VPU_H1_SWREG3_BF_23_MASK                 (0x800000U)
#define VPU_H1_SWREG3_BF_23_SHIFT                (23U)
/*! BF_23 - Enable output MV (MB info) swap for 16-bits */
#define VPU_H1_SWREG3_BF_23(x)                   (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG3_BF_23_SHIFT)) & VPU_H1_SWREG3_BF_23_MASK)

#define VPU_H1_SWREG3_BF_24_MASK                 (0x1000000U)
#define VPU_H1_SWREG3_BF_24_SHIFT                (24U)
/*! BF_24 - Enable output MV (MB info) swap for 8-bits */
#define VPU_H1_SWREG3_BF_24(x)                   (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG3_BF_24_SHIFT)) & VPU_H1_SWREG3_BF_24_MASK)

#define VPU_H1_SWREG3_BF_25_MASK                 (0x2000000U)
#define VPU_H1_SWREG3_BF_25_SHIFT                (25U)
/*! BF_25 - Enable output scaled image swap for 32-bits */
#define VPU_H1_SWREG3_BF_25(x)                   (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG3_BF_25_SHIFT)) & VPU_H1_SWREG3_BF_25_MASK)

#define VPU_H1_SWREG3_BF_26_MASK                 (0x4000000U)
#define VPU_H1_SWREG3_BF_26_SHIFT                (26U)
/*! BF_26 - Enable output scaled image swap for 16-bits */
#define VPU_H1_SWREG3_BF_26(x)                   (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG3_BF_26_SHIFT)) & VPU_H1_SWREG3_BF_26_MASK)

#define VPU_H1_SWREG3_BF_27_MASK                 (0x8000000U)
#define VPU_H1_SWREG3_BF_27_SHIFT                (27U)
/*! BF_27 - Enable output scaled image swap for 8-bits */
#define VPU_H1_SWREG3_BF_27(x)                   (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG3_BF_27_SHIFT)) & VPU_H1_SWREG3_BF_27_MASK)
/*! @} */

/*! @name SWREG5 - VPU H1 Register 5 */
/*! @{ */

#define VPU_H1_SWREG5_BF_0_MASK                  (0xFFFFFFFFU)
#define VPU_H1_SWREG5_BF_0_SHIFT                 (0U)
/*! BF_0 - Base address for output stream data */
#define VPU_H1_SWREG5_BF_0(x)                    (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG5_BF_0_SHIFT)) & VPU_H1_SWREG5_BF_0_MASK)
/*! @} */

/*! @name SWREG6 - VPU H1 Register 6 */
/*! @{ */

#define VPU_H1_SWREG6_BF_0_MASK                  (0xFFFFFFFFU)
#define VPU_H1_SWREG6_BF_0_SHIFT                 (0U)
/*! BF_0 - Base address for output control data */
#define VPU_H1_SWREG6_BF_0(x)                    (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG6_BF_0_SHIFT)) & VPU_H1_SWREG6_BF_0_MASK)
/*! @} */

/*! @name SWREG7 - VPU H1 Register 7 */
/*! @{ */

#define VPU_H1_SWREG7_BF_0_MASK                  (0xFFFFFFFFU)
#define VPU_H1_SWREG7_BF_0_SHIFT                 (0U)
/*! BF_0 - Base address for reference luma */
#define VPU_H1_SWREG7_BF_0(x)                    (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG7_BF_0_SHIFT)) & VPU_H1_SWREG7_BF_0_MASK)
/*! @} */

/*! @name SWREG8 - VPU H1 Register 8 */
/*! @{ */

#define VPU_H1_SWREG8_BF_0_MASK                  (0xFFFFFFFFU)
#define VPU_H1_SWREG8_BF_0_SHIFT                 (0U)
/*! BF_0 - Base address for reference chroma */
#define VPU_H1_SWREG8_BF_0(x)                    (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG8_BF_0_SHIFT)) & VPU_H1_SWREG8_BF_0_MASK)
/*! @} */

/*! @name SWREG9 - VPU H1 Register 9 */
/*! @{ */

#define VPU_H1_SWREG9_BF_0_MASK                  (0xFFFFFFFFU)
#define VPU_H1_SWREG9_BF_0_SHIFT                 (0U)
/*! BF_0 - Base address for reconstructed luma */
#define VPU_H1_SWREG9_BF_0(x)                    (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG9_BF_0_SHIFT)) & VPU_H1_SWREG9_BF_0_MASK)
/*! @} */

/*! @name SWREG10 - VPU H1 Register 10 */
/*! @{ */

#define VPU_H1_SWREG10_BF_0_MASK                 (0xFFFFFFFFU)
#define VPU_H1_SWREG10_BF_0_SHIFT                (0U)
/*! BF_0 - Base address for reconstructed chroma */
#define VPU_H1_SWREG10_BF_0(x)                   (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG10_BF_0_SHIFT)) & VPU_H1_SWREG10_BF_0_MASK)
/*! @} */

/*! @name SWREG11 - VPU H1 Register 11 */
/*! @{ */

#define VPU_H1_SWREG11_BF_0_MASK                 (0xFFFFFFFFU)
#define VPU_H1_SWREG11_BF_0_SHIFT                (0U)
/*! BF_0 - Base address for input picture luma */
#define VPU_H1_SWREG11_BF_0(x)                   (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG11_BF_0_SHIFT)) & VPU_H1_SWREG11_BF_0_MASK)
/*! @} */

/*! @name SWREG12 - VPU H1 Register 12 */
/*! @{ */

#define VPU_H1_SWREG12_BF_0_MASK                 (0xFFFFFFFFU)
#define VPU_H1_SWREG12_BF_0_SHIFT                (0U)
/*! BF_0 - Base address for input picture cb */
#define VPU_H1_SWREG12_BF_0(x)                   (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG12_BF_0_SHIFT)) & VPU_H1_SWREG12_BF_0_MASK)
/*! @} */

/*! @name SWREG13 - VPU H1 Register 13 */
/*! @{ */

#define VPU_H1_SWREG13_BF_0_MASK                 (0xFFFFFFFFU)
#define VPU_H1_SWREG13_BF_0_SHIFT                (0U)
/*! BF_0 - Base address for input picture cr */
#define VPU_H1_SWREG13_BF_0(x)                   (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG13_BF_0_SHIFT)) & VPU_H1_SWREG13_BF_0_MASK)
/*! @} */

/*! @name SWREG14 - VPU H1 Register 14 */
/*! @{ */

#define VPU_H1_SWREG14_BF_0_MASK                 (0x1U)
#define VPU_H1_SWREG14_BF_0_SHIFT                (0U)
/*! BF_0 - Encoder enable */
#define VPU_H1_SWREG14_BF_0(x)                   (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG14_BF_0_SHIFT)) & VPU_H1_SWREG14_BF_0_MASK)

#define VPU_H1_SWREG14_BF_1_MASK                 (0x6U)
#define VPU_H1_SWREG14_BF_1_SHIFT                (1U)
/*! BF_1 - Encoding mode. streamType. */
#define VPU_H1_SWREG14_BF_1(x)                   (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG14_BF_1_SHIFT)) & VPU_H1_SWREG14_BF_1_MASK)

#define VPU_H1_SWREG14_BF_3_MASK                 (0x18U)
#define VPU_H1_SWREG14_BF_3_SHIFT                (3U)
/*! BF_3 - Encoded picture type. frameType. */
#define VPU_H1_SWREG14_BF_3(x)                   (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG14_BF_3_SHIFT)) & VPU_H1_SWREG14_BF_3_MASK)

#define VPU_H1_SWREG14_BF_6_MASK                 (0x40U)
#define VPU_H1_SWREG14_BF_6_SHIFT                (6U)
/*! BF_6 - Disable writing of reconstructed image. recWriteDisable */
#define VPU_H1_SWREG14_BF_6(x)                   (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG14_BF_6_SHIFT)) & VPU_H1_SWREG14_BF_6_MASK)

#define VPU_H1_SWREG14_BF_7_MASK                 (0x80U)
#define VPU_H1_SWREG14_BF_7_SHIFT                (7U)
/*! BF_7 - Size of buffer used when writing reconstructed image. */
#define VPU_H1_SWREG14_BF_7(x)                   (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG14_BF_7_SHIFT)) & VPU_H1_SWREG14_BF_7_MASK)

#define VPU_H1_SWREG14_BF_10_MASK                (0x7FC00U)
#define VPU_H1_SWREG14_BF_10_SHIFT               (10U)
/*! BF_10 - Encoded height. lumHeight (macroblocks) H264:[6..255] JPEG:[2..511] */
#define VPU_H1_SWREG14_BF_10(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG14_BF_10_SHIFT)) & VPU_H1_SWREG14_BF_10_MASK)

#define VPU_H1_SWREG14_BF_19_MASK                (0xFF80000U)
#define VPU_H1_SWREG14_BF_19_SHIFT               (19U)
/*! BF_19 - Encoded width. lumWidth (macroblocks) H264:[9..255] JPEG:[6..511] */
#define VPU_H1_SWREG14_BF_19(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG14_BF_19_SHIFT)) & VPU_H1_SWREG14_BF_19_MASK)

#define VPU_H1_SWREG14_BF_28_MASK                (0x10000000U)
#define VPU_H1_SWREG14_BF_28_SHIFT               (28U)
/*! BF_28 - Enable interrupt for slice ready */
#define VPU_H1_SWREG14_BF_28(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG14_BF_28_SHIFT)) & VPU_H1_SWREG14_BF_28_MASK)

#define VPU_H1_SWREG14_BF_29_MASK                (0x20000000U)
#define VPU_H1_SWREG14_BF_29_SHIFT               (29U)
/*! BF_29 - Enable writing size of each NAL unit to BaseControl, nalSizeWriteOut */
#define VPU_H1_SWREG14_BF_29(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG14_BF_29_SHIFT)) & VPU_H1_SWREG14_BF_29_MASK)

#define VPU_H1_SWREG14_BF_30_MASK                (0x40000000U)
#define VPU_H1_SWREG14_BF_30_SHIFT               (30U)
/*! BF_30 - Enable writing MV and SAD of each MB to BaseMvWrite */
#define VPU_H1_SWREG14_BF_30(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG14_BF_30_SHIFT)) & VPU_H1_SWREG14_BF_30_MASK)

#define VPU_H1_SWREG14_BF_31_MASK                (0x80000000U)
#define VPU_H1_SWREG14_BF_31_SHIFT               (31U)
/*! BF_31 - Enable interrupt for timeout */
#define VPU_H1_SWREG14_BF_31(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG14_BF_31_SHIFT)) & VPU_H1_SWREG14_BF_31_MASK)
/*! @} */

/*! @name SWREG15 - VPU H1 Register 15 */
/*! @{ */

#define VPU_H1_SWREG15_BF_0_MASK                 (0x3U)
#define VPU_H1_SWREG15_BF_0_SHIFT                (0U)
/*! BF_0 - Input image rotation. */
#define VPU_H1_SWREG15_BF_0(x)                   (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG15_BF_0_SHIFT)) & VPU_H1_SWREG15_BF_0_MASK)

#define VPU_H1_SWREG15_BF_2_MASK                 (0x3CU)
#define VPU_H1_SWREG15_BF_2_SHIFT                (2U)
/*! BF_2 - Input image format. inputFormat. YUV420P/YUV420SP/YUYV422/UYVY422/RGB565/RGB555/RGB444/RGB888/RGB101010 */
#define VPU_H1_SWREG15_BF_2(x)                   (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG15_BF_2_SHIFT)) & VPU_H1_SWREG15_BF_2_MASK)

#define VPU_H1_SWREG15_BF_6_MASK                 (0x3C0U)
#define VPU_H1_SWREG15_BF_6_SHIFT                (6U)
/*! BF_6 - Overfill pixels on bottom edge of image. YFill. [0..15] */
#define VPU_H1_SWREG15_BF_6(x)                   (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG15_BF_6_SHIFT)) & VPU_H1_SWREG15_BF_6_MASK)

#define VPU_H1_SWREG15_BF_10_MASK                (0xC00U)
#define VPU_H1_SWREG15_BF_10_SHIFT               (10U)
/*! BF_10 - Overfill pixels on right edge of image div4 [0..3] */
#define VPU_H1_SWREG15_BF_10(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG15_BF_10_SHIFT)) & VPU_H1_SWREG15_BF_10_MASK)

#define VPU_H1_SWREG15_BF_12_MASK                (0x3FFF000U)
#define VPU_H1_SWREG15_BF_12_SHIFT               (12U)
/*! BF_12 - Input luminance row length. lumWidthSrc (bytes) [96..8192] */
#define VPU_H1_SWREG15_BF_12(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG15_BF_12_SHIFT)) & VPU_H1_SWREG15_BF_12_MASK)

#define VPU_H1_SWREG15_BF_26_MASK                (0x1C000000U)
#define VPU_H1_SWREG15_BF_26_SHIFT               (26U)
/*! BF_26 - Input luminance offset (bytes) [0..7] */
#define VPU_H1_SWREG15_BF_26(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG15_BF_26_SHIFT)) & VPU_H1_SWREG15_BF_26_MASK)

#define VPU_H1_SWREG15_BF_29_MASK                (0xE0000000U)
#define VPU_H1_SWREG15_BF_29_SHIFT               (29U)
/*! BF_29 - Input chrominance offset (bytes) [0..7] */
#define VPU_H1_SWREG15_BF_29(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG15_BF_29_SHIFT)) & VPU_H1_SWREG15_BF_29_MASK)
/*! @} */

/*! @name SWREG18 - VPU H1 Register 18 */
/*! @{ */

#define VPU_H1_SWREG18_BF_0_MASK                 (0xFFFFU)
#define VPU_H1_SWREG18_BF_0_SHIFT                (0U)
/*! BF_0 - Intra prediction intra 16x16 mode favor */
#define VPU_H1_SWREG18_BF_0(x)                   (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG18_BF_0_SHIFT)) & VPU_H1_SWREG18_BF_0_MASK)

#define VPU_H1_SWREG18_BF_16_MASK                (0x10000U)
#define VPU_H1_SWREG18_BF_16_SHIFT               (16U)
/*! BF_16 - H.264 Stream mode. byteStream. */
#define VPU_H1_SWREG18_BF_16(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG18_BF_16_SHIFT)) & VPU_H1_SWREG18_BF_16_MASK)

#define VPU_H1_SWREG18_BF_17_MASK                (0x20000U)
#define VPU_H1_SWREG18_BF_17_SHIFT               (17U)
/*! BF_17 - H.264 Inter 4x4 mode restriction. restricted4x4Mode */
#define VPU_H1_SWREG18_BF_17(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG18_BF_17_SHIFT)) & VPU_H1_SWREG18_BF_17_MASK)

#define VPU_H1_SWREG18_BF_18_MASK                (0x40000U)
#define VPU_H1_SWREG18_BF_18_SHIFT               (18U)
/*! BF_18 - H.264 CABAC / VP8 boolenc enable. entropyCodingMode. */
#define VPU_H1_SWREG18_BF_18(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG18_BF_18_SHIFT)) & VPU_H1_SWREG18_BF_18_MASK)

#define VPU_H1_SWREG18_BF_19_MASK                (0x180000U)
#define VPU_H1_SWREG18_BF_19_SHIFT               (19U)
/*! BF_19 - H.264 CABAC initial IDC. [0..2] */
#define VPU_H1_SWREG18_BF_19(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG18_BF_19_SHIFT)) & VPU_H1_SWREG18_BF_19_MASK)

#define VPU_H1_SWREG18_BF_21_MASK                (0x200000U)
#define VPU_H1_SWREG18_BF_21_SHIFT               (21U)
/*! BF_21 - H.264 Transform 8x8 enable. High Profile H.264. transform8x8Mode */
#define VPU_H1_SWREG18_BF_21(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG18_BF_21_SHIFT)) & VPU_H1_SWREG18_BF_21_MASK)

#define VPU_H1_SWREG18_BF_22_MASK                (0x400000U)
#define VPU_H1_SWREG18_BF_22_SHIFT               (22U)
/*! BF_22 - H.264 Disable quarter pixel MVs. disableQuarterPixelMv */
#define VPU_H1_SWREG18_BF_22(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG18_BF_22_SHIFT)) & VPU_H1_SWREG18_BF_22_MASK)

#define VPU_H1_SWREG18_BF_23_MASK                (0x3F800000U)
#define VPU_H1_SWREG18_BF_23_SHIFT               (23U)
/*! BF_23 - H.264 Slice size. mbRowPerSlice (mb rows) [0..127] 0=one slice per picture */
#define VPU_H1_SWREG18_BF_23(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG18_BF_23_SHIFT)) & VPU_H1_SWREG18_BF_23_MASK)

#define VPU_H1_SWREG18_BF_30_MASK                (0xC0000000U)
#define VPU_H1_SWREG18_BF_30_SHIFT               (30U)
/*! BF_30 - Deblocking filter mode. */
#define VPU_H1_SWREG18_BF_30(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG18_BF_30_SHIFT)) & VPU_H1_SWREG18_BF_30_MASK)
/*! @} */

/*! @name SWREG19 - VPU H1 Register 19 */
/*! @{ */

#define VPU_H1_SWREG19_BF_0_MASK                 (0x3FFU)
#define VPU_H1_SWREG19_BF_0_SHIFT                (0U)
/*! BF_0 - Differential MV penalty for 1p ME. DMVPenalty1p */
#define VPU_H1_SWREG19_BF_0(x)                   (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG19_BF_0_SHIFT)) & VPU_H1_SWREG19_BF_0_MASK)

#define VPU_H1_SWREG19_BF_10_MASK                (0xFFC00U)
#define VPU_H1_SWREG19_BF_10_SHIFT               (10U)
/*! BF_10 - Differential MV penalty for 4p ME. DMVPenalty4p */
#define VPU_H1_SWREG19_BF_10(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG19_BF_10_SHIFT)) & VPU_H1_SWREG19_BF_10_MASK)

#define VPU_H1_SWREG19_BF_20_MASK                (0x3FF00000U)
#define VPU_H1_SWREG19_BF_20_SHIFT               (20U)
/*! BF_20 - Differential MV penalty for 1/4p ME. DMVPenaltyQp */
#define VPU_H1_SWREG19_BF_20(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG19_BF_20_SHIFT)) & VPU_H1_SWREG19_BF_20_MASK)

#define VPU_H1_SWREG19_BF_30_MASK                (0x40000000U)
#define VPU_H1_SWREG19_BF_30_SHIFT               (30U)
/*! BF_30 - Enable using more than 1 MV per macroblock. */
#define VPU_H1_SWREG19_BF_30(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG19_BF_30_SHIFT)) & VPU_H1_SWREG19_BF_30_MASK)

#define VPU_H1_SWREG19_BF_31_MASK                (0x80000000U)
#define VPU_H1_SWREG19_BF_31_SHIFT               (31U)
/*! BF_31 - Swap order of chroma bytes in semiplanar input format. */
#define VPU_H1_SWREG19_BF_31(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG19_BF_31_SHIFT)) & VPU_H1_SWREG19_BF_31_MASK)
/*! @} */

/*! @name SWREG20 - VPU H1 Register 20 */
/*! @{ */

#define VPU_H1_SWREG20_BF_0_MASK                 (0x3FFU)
#define VPU_H1_SWREG20_BF_0_SHIFT                (0U)
/*! BF_0 - Penalty for using 8x4 or 4x8 MV. */
#define VPU_H1_SWREG20_BF_0(x)                   (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG20_BF_0_SHIFT)) & VPU_H1_SWREG20_BF_0_MASK)

#define VPU_H1_SWREG20_BF_10_MASK                (0xFFC00U)
#define VPU_H1_SWREG20_BF_10_SHIFT               (10U)
/*! BF_10 - Penalty for using 8x8 MV. */
#define VPU_H1_SWREG20_BF_10(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG20_BF_10_SHIFT)) & VPU_H1_SWREG20_BF_10_MASK)

#define VPU_H1_SWREG20_BF_20_MASK                (0x3FF00000U)
#define VPU_H1_SWREG20_BF_20_SHIFT               (20U)
/*! BF_20 - Penalty for using 16x8 or 8x16 MV. */
#define VPU_H1_SWREG20_BF_20(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG20_BF_20_SHIFT)) & VPU_H1_SWREG20_BF_20_MASK)
/*! @} */

/*! @name SWREG21 - VPU H1 Register 21 */
/*! @{ */

#define VPU_H1_SWREG21_BF_0_MASK                 (0xFFFFU)
#define VPU_H1_SWREG21_BF_0_SHIFT                (0U)
/*! BF_0 - Inter MB mode favor in intra/inter selection */
#define VPU_H1_SWREG21_BF_0(x)                   (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG21_BF_0_SHIFT)) & VPU_H1_SWREG21_BF_0_MASK)

#define VPU_H1_SWREG21_BF_16_MASK                (0xFF0000U)
#define VPU_H1_SWREG21_BF_16_SHIFT               (16U)
/*! BF_16 - H.264 amount of completed slices. */
#define VPU_H1_SWREG21_BF_16(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG21_BF_16_SHIFT)) & VPU_H1_SWREG21_BF_16_MASK)

#define VPU_H1_SWREG21_BF_24_MASK                (0xFF000000U)
#define VPU_H1_SWREG21_BF_24_SHIFT               (24U)
/*! BF_24 - H.264 SKIP macroblock mode / VP8 zero/nearest/near mode penalty */
#define VPU_H1_SWREG21_BF_24(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG21_BF_24_SHIFT)) & VPU_H1_SWREG21_BF_24_MASK)
/*! @} */

/*! @name SWREG22 - VPU H1 Register 22 */
/*! @{ */

#define VPU_H1_SWREG22_BF_0_MASK                 (0xFFFFFFFFU)
#define VPU_H1_SWREG22_BF_0_SHIFT                (0U)
/*! BF_0 - Stream header remainder bits MSB (MSB aligned) */
#define VPU_H1_SWREG22_BF_0(x)                   (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG22_BF_0_SHIFT)) & VPU_H1_SWREG22_BF_0_MASK)
/*! @} */

/*! @name SWREG23 - VPU H1 Register 23 */
/*! @{ */

#define VPU_H1_SWREG23_BF_0_MASK                 (0xFFFFFFFFU)
#define VPU_H1_SWREG23_BF_0_SHIFT                (0U)
/*! BF_0 - Stream header remainder bits LSB (MSB aligned) */
#define VPU_H1_SWREG23_BF_0(x)                   (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG23_BF_0_SHIFT)) & VPU_H1_SWREG23_BF_0_MASK)
/*! @} */

/*! @name SWREG24 - VPU H1 Register 24 */
/*! @{ */

#define VPU_H1_SWREG24_BF_0_MASK                 (0xFFFFFFFFU)
#define VPU_H1_SWREG24_BF_0_SHIFT                (0U)
/*! BF_0 - Stream buffer limit (64bit addresses) / output stream size (bits). HWStreamDataCount. If
 *    limit is reached buffer full IRQ is given.
 */
#define VPU_H1_SWREG24_BF_0(x)                   (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG24_BF_0_SHIFT)) & VPU_H1_SWREG24_BF_0_MASK)
/*! @} */

/*! @name SWREG25 - VPU H1 Register 25 */
/*! @{ */

#define VPU_H1_SWREG25_BF_0_MASK                 (0x3FFFFFU)
#define VPU_H1_SWREG25_BF_0_SHIFT                (0U)
/*! BF_0 - QP Sum div2 output */
#define VPU_H1_SWREG25_BF_0(x)                   (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG25_BF_0_SHIFT)) & VPU_H1_SWREG25_BF_0_MASK)

#define VPU_H1_SWREG25_BF_22_MASK                (0xFC00000U)
#define VPU_H1_SWREG25_BF_22_SHIFT               (22U)
/*! BF_22 - MAD threshold div256 */
#define VPU_H1_SWREG25_BF_22(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG25_BF_22_SHIFT)) & VPU_H1_SWREG25_BF_22_MASK)

#define VPU_H1_SWREG25_BF_28_MASK                (0xF0000000U)
#define VPU_H1_SWREG25_BF_28_SHIFT               (28U)
/*! BF_28 - MAD based QP adjustment. madQpChange [-8..7] */
#define VPU_H1_SWREG25_BF_28(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG25_BF_28_SHIFT)) & VPU_H1_SWREG25_BF_28_MASK)
/*! @} */

/*! @name SWREG37 - VPU H1 Register 37 */
/*! @{ */

#define VPU_H1_SWREG37_BF_0_MASK                 (0x7FFFFFU)
#define VPU_H1_SWREG37_BF_0_SHIFT                (0U)
/*! BF_0 - RLC codeword count div4 output. max 255*255*384/4 */
#define VPU_H1_SWREG37_BF_0(x)                   (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG37_BF_0_SHIFT)) & VPU_H1_SWREG37_BF_0_MASK)

#define VPU_H1_SWREG37_BF_23_MASK                (0x1F800000U)
#define VPU_H1_SWREG37_BF_23_SHIFT               (23U)
/*! BF_23 - Stream start offset = amount of StrmHdrRem (bits) [0..63] */
#define VPU_H1_SWREG37_BF_23(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG37_BF_23_SHIFT)) & VPU_H1_SWREG37_BF_23_MASK)

#define VPU_H1_SWREG37_BF_31_MASK                (0x80000000U)
#define VPU_H1_SWREG37_BF_31_SHIFT               (31U)
/*! BF_31 - Mode for VP8 interpolation filter. */
#define VPU_H1_SWREG37_BF_31(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG37_BF_31_SHIFT)) & VPU_H1_SWREG37_BF_31_MASK)
/*! @} */

/*! @name SWREG38 - VPU H1 Register 38 */
/*! @{ */

#define VPU_H1_SWREG38_BF_0_MASK                 (0xFFFFU)
#define VPU_H1_SWREG38_BF_0_SHIFT                (0U)
/*! BF_0 - MB count output. max 255*255 */
#define VPU_H1_SWREG38_BF_0(x)                   (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG38_BF_0_SHIFT)) & VPU_H1_SWREG38_BF_0_MASK)

#define VPU_H1_SWREG38_BF_16_MASK                (0xFFFF0000U)
#define VPU_H1_SWREG38_BF_16_SHIFT               (16U)
/*! BF_16 - Macroblock count with MAD value under threshold output */
#define VPU_H1_SWREG38_BF_16(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG38_BF_16_SHIFT)) & VPU_H1_SWREG38_BF_16_MASK)
/*! @} */

/*! @name SWREG39 - VPU H1 Register 39 */
/*! @{ */

#define VPU_H1_SWREG39_BF_0_MASK                 (0xFFFFFFFFU)
#define VPU_H1_SWREG39_BF_0_SHIFT                (0U)
/*! BF_0 - Base address for next pic luminance */
#define VPU_H1_SWREG39_BF_0(x)                   (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG39_BF_0_SHIFT)) & VPU_H1_SWREG39_BF_0_MASK)
/*! @} */

/*! @name SWREG40 - VPU H1 Register 40 */
/*! @{ */

#define VPU_H1_SWREG40_BF_0_MASK                 (0xFFFFFFU)
#define VPU_H1_SWREG40_BF_0_SHIFT                (0U)
/*! BF_0 - Stabilization minimum value output. max 253*253*255 */
#define VPU_H1_SWREG40_BF_0(x)                   (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG40_BF_0_SHIFT)) & VPU_H1_SWREG40_BF_0_MASK)

#define VPU_H1_SWREG40_BF_30_MASK                (0xC0000000U)
#define VPU_H1_SWREG40_BF_30_SHIFT               (30U)
/*! BF_30 - Stabilization mode. */
#define VPU_H1_SWREG40_BF_30(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG40_BF_30_SHIFT)) & VPU_H1_SWREG40_BF_30_MASK)
/*! @} */

/*! @name SWREG41 - VPU H1 Register 41 */
/*! @{ */

#define VPU_H1_SWREG41_BF_0_MASK                 (0xFFFFFFFFU)
#define VPU_H1_SWREG41_BF_0_SHIFT                (0U)
/*! BF_0 - Stabilization motion sum div8 output. max 253*253*255*1089/8 */
#define VPU_H1_SWREG41_BF_0(x)                   (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG41_BF_0_SHIFT)) & VPU_H1_SWREG41_BF_0_MASK)
/*! @} */

/*! @name SWREG42 - VPU H1 Register 42 */
/*! @{ */

#define VPU_H1_SWREG42_BF_0_MASK                 (0xFFFFFFU)
#define VPU_H1_SWREG42_BF_0_SHIFT                (0U)
/*! BF_0 - Stabilization matrix 1 (up-left position) output */
#define VPU_H1_SWREG42_BF_0(x)                   (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG42_BF_0_SHIFT)) & VPU_H1_SWREG42_BF_0_MASK)

#define VPU_H1_SWREG42_BF_26_MASK                (0xFC000000U)
#define VPU_H1_SWREG42_BF_26_SHIFT               (26U)
/*! BF_26 - Stabilization GMV horizontal output [-16..16] */
#define VPU_H1_SWREG42_BF_26(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG42_BF_26_SHIFT)) & VPU_H1_SWREG42_BF_26_MASK)
/*! @} */

/*! @name SWREG43 - VPU H1 Register 43 */
/*! @{ */

#define VPU_H1_SWREG43_BF_0_MASK                 (0xFFFFFFU)
#define VPU_H1_SWREG43_BF_0_SHIFT                (0U)
/*! BF_0 - Stabilization matrix 2 (up position) output */
#define VPU_H1_SWREG43_BF_0(x)                   (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG43_BF_0_SHIFT)) & VPU_H1_SWREG43_BF_0_MASK)

#define VPU_H1_SWREG43_BF_26_MASK                (0xFC000000U)
#define VPU_H1_SWREG43_BF_26_SHIFT               (26U)
/*! BF_26 - Stabilization GMV vertical output [-16..16] */
#define VPU_H1_SWREG43_BF_26(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG43_BF_26_SHIFT)) & VPU_H1_SWREG43_BF_26_MASK)
/*! @} */

/*! @name SWREG44 - VPU H1 Register 44 */
/*! @{ */

#define VPU_H1_SWREG44_BF_0_MASK                 (0xFFFFFFU)
#define VPU_H1_SWREG44_BF_0_SHIFT                (0U)
/*! BF_0 - Stabilization matrix 3 (up-right position) output */
#define VPU_H1_SWREG44_BF_0(x)                   (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG44_BF_0_SHIFT)) & VPU_H1_SWREG44_BF_0_MASK)
/*! @} */

/*! @name SWREG45 - VPU H1 Register 45 */
/*! @{ */

#define VPU_H1_SWREG45_BF_0_MASK                 (0xFFFFFFU)
#define VPU_H1_SWREG45_BF_0_SHIFT                (0U)
/*! BF_0 - Stabilization matrix 4 (left position) output */
#define VPU_H1_SWREG45_BF_0(x)                   (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG45_BF_0_SHIFT)) & VPU_H1_SWREG45_BF_0_MASK)
/*! @} */

/*! @name SWREG46 - VPU H1 Register 46 */
/*! @{ */

#define VPU_H1_SWREG46_BF_0_MASK                 (0xFFFFFFU)
#define VPU_H1_SWREG46_BF_0_SHIFT                (0U)
/*! BF_0 - Stabilization matrix 5 (GMV position) output */
#define VPU_H1_SWREG46_BF_0(x)                   (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG46_BF_0_SHIFT)) & VPU_H1_SWREG46_BF_0_MASK)
/*! @} */

/*! @name SWREG47 - VPU H1 Register 47 */
/*! @{ */

#define VPU_H1_SWREG47_BF_0_MASK                 (0xFFFFFFU)
#define VPU_H1_SWREG47_BF_0_SHIFT                (0U)
/*! BF_0 - Stabilization matrix 6 (right position) output */
#define VPU_H1_SWREG47_BF_0(x)                   (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG47_BF_0_SHIFT)) & VPU_H1_SWREG47_BF_0_MASK)
/*! @} */

/*! @name SWREG48 - VPU H1 Register 48 */
/*! @{ */

#define VPU_H1_SWREG48_BF_0_MASK                 (0xFFFFFFU)
#define VPU_H1_SWREG48_BF_0_SHIFT                (0U)
/*! BF_0 - Stabilization matrix 7 (down-left position) output */
#define VPU_H1_SWREG48_BF_0(x)                   (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG48_BF_0_SHIFT)) & VPU_H1_SWREG48_BF_0_MASK)
/*! @} */

/*! @name SWREG49 - VPU H1 Register 49 */
/*! @{ */

#define VPU_H1_SWREG49_BF_0_MASK                 (0xFFFFFFU)
#define VPU_H1_SWREG49_BF_0_SHIFT                (0U)
/*! BF_0 - Stabilization matrix 8 (down position) output */
#define VPU_H1_SWREG49_BF_0(x)                   (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG49_BF_0_SHIFT)) & VPU_H1_SWREG49_BF_0_MASK)
/*! @} */

/*! @name SWREG50 - VPU H1 Register 50 */
/*! @{ */

#define VPU_H1_SWREG50_BF_0_MASK                 (0xFFFFFFU)
#define VPU_H1_SWREG50_BF_0_SHIFT                (0U)
/*! BF_0 - Stabilization matrix 9 (down-right position) output */
#define VPU_H1_SWREG50_BF_0(x)                   (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG50_BF_0_SHIFT)) & VPU_H1_SWREG50_BF_0_MASK)
/*! @} */

/*! @name SWREG51 - VPU H1 Register 51 */
/*! @{ */

#define VPU_H1_SWREG51_BF_0_MASK                 (0xFFFFFFFFU)
#define VPU_H1_SWREG51_BF_0_SHIFT                (0U)
/*! BF_0 - Base address for cabac context tables (H264) or probability tables (VP8) */
#define VPU_H1_SWREG51_BF_0(x)                   (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG51_BF_0_SHIFT)) & VPU_H1_SWREG51_BF_0_MASK)
/*! @} */

/*! @name SWREG52 - VPU H1 Register 52 */
/*! @{ */

#define VPU_H1_SWREG52_BF_0_MASK                 (0xFFFFFFFFU)
#define VPU_H1_SWREG52_BF_0_SHIFT                (0U)
/*! BF_0 - Base address for MV output writing */
#define VPU_H1_SWREG52_BF_0(x)                   (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG52_BF_0_SHIFT)) & VPU_H1_SWREG52_BF_0_MASK)
/*! @} */

/*! @name SWREG53 - VPU H1 Register 53 */
/*! @{ */

#define VPU_H1_SWREG53_BF_0_MASK                 (0xFFFFU)
#define VPU_H1_SWREG53_BF_0_SHIFT                (0U)
/*! BF_0 - RGB to YUV conversion coefficient A */
#define VPU_H1_SWREG53_BF_0(x)                   (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG53_BF_0_SHIFT)) & VPU_H1_SWREG53_BF_0_MASK)

#define VPU_H1_SWREG53_BF_16_MASK                (0xFFFF0000U)
#define VPU_H1_SWREG53_BF_16_SHIFT               (16U)
/*! BF_16 - RGB to YUV conversion coefficient B */
#define VPU_H1_SWREG53_BF_16(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG53_BF_16_SHIFT)) & VPU_H1_SWREG53_BF_16_MASK)
/*! @} */

/*! @name SWREG54 - VPU H1 Register 54 */
/*! @{ */

#define VPU_H1_SWREG54_BF_0_MASK                 (0xFFFFU)
#define VPU_H1_SWREG54_BF_0_SHIFT                (0U)
/*! BF_0 - RGB to YUV conversion coefficient C */
#define VPU_H1_SWREG54_BF_0(x)                   (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG54_BF_0_SHIFT)) & VPU_H1_SWREG54_BF_0_MASK)

#define VPU_H1_SWREG54_BF_16_MASK                (0xFFFF0000U)
#define VPU_H1_SWREG54_BF_16_SHIFT               (16U)
/*! BF_16 - RGB to YUV conversion coefficient E */
#define VPU_H1_SWREG54_BF_16(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG54_BF_16_SHIFT)) & VPU_H1_SWREG54_BF_16_MASK)
/*! @} */

/*! @name SWREG55 - VPU H1 Register 55 */
/*! @{ */

#define VPU_H1_SWREG55_BF_0_MASK                 (0xFFFFU)
#define VPU_H1_SWREG55_BF_0_SHIFT                (0U)
/*! BF_0 - RGB to YUV conversion coefficient F */
#define VPU_H1_SWREG55_BF_0(x)                   (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG55_BF_0_SHIFT)) & VPU_H1_SWREG55_BF_0_MASK)

#define VPU_H1_SWREG55_BF_16_MASK                (0x1F0000U)
#define VPU_H1_SWREG55_BF_16_SHIFT               (16U)
/*! BF_16 - RGB R-component mask MSB bit position [0..31] */
#define VPU_H1_SWREG55_BF_16(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG55_BF_16_SHIFT)) & VPU_H1_SWREG55_BF_16_MASK)

#define VPU_H1_SWREG55_BF_21_MASK                (0x3E00000U)
#define VPU_H1_SWREG55_BF_21_SHIFT               (21U)
/*! BF_21 - RGB G-component mask MSB bit position [0..31] */
#define VPU_H1_SWREG55_BF_21(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG55_BF_21_SHIFT)) & VPU_H1_SWREG55_BF_21_MASK)

#define VPU_H1_SWREG55_BF_26_MASK                (0x7C000000U)
#define VPU_H1_SWREG55_BF_26_SHIFT               (26U)
/*! BF_26 - RGB B-component mask MSB bit position [0..31] */
#define VPU_H1_SWREG55_BF_26(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG55_BF_26_SHIFT)) & VPU_H1_SWREG55_BF_26_MASK)
/*! @} */

/*! @name SWREG56 - VPU H1 Register 56 */
/*! @{ */

#define VPU_H1_SWREG56_BF_0_MASK                 (0xFFU)
#define VPU_H1_SWREG56_BF_0_SHIFT                (0U)
/*! BF_0 - Intra area bottom mb row (outside area) [0..255] */
#define VPU_H1_SWREG56_BF_0(x)                   (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG56_BF_0_SHIFT)) & VPU_H1_SWREG56_BF_0_MASK)

#define VPU_H1_SWREG56_BF_8_MASK                 (0xFF00U)
#define VPU_H1_SWREG56_BF_8_SHIFT                (8U)
/*! BF_8 - Intra area top mb row (inside area) [0..255] */
#define VPU_H1_SWREG56_BF_8(x)                   (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG56_BF_8_SHIFT)) & VPU_H1_SWREG56_BF_8_MASK)

#define VPU_H1_SWREG56_BF_16_MASK                (0xFF0000U)
#define VPU_H1_SWREG56_BF_16_SHIFT               (16U)
/*! BF_16 - Intra area right mb column (outside area) [0..255] */
#define VPU_H1_SWREG56_BF_16(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG56_BF_16_SHIFT)) & VPU_H1_SWREG56_BF_16_MASK)

#define VPU_H1_SWREG56_BF_24_MASK                (0xFF000000U)
#define VPU_H1_SWREG56_BF_24_SHIFT               (24U)
/*! BF_24 - Intra area left mb column (inside area) [0..255] */
#define VPU_H1_SWREG56_BF_24(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG56_BF_24_SHIFT)) & VPU_H1_SWREG56_BF_24_MASK)
/*! @} */

/*! @name SWREG57 - VPU H1 Register 57 */
/*! @{ */

#define VPU_H1_SWREG57_BF_0_MASK                 (0xFFFFU)
#define VPU_H1_SWREG57_BF_0_SHIFT                (0U)
/*! BF_0 - CIR intra mb interval. 0=disabled [0..65535] */
#define VPU_H1_SWREG57_BF_0(x)                   (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG57_BF_0_SHIFT)) & VPU_H1_SWREG57_BF_0_MASK)

#define VPU_H1_SWREG57_BF_16_MASK                (0xFFFF0000U)
#define VPU_H1_SWREG57_BF_16_SHIFT               (16U)
/*! BF_16 - CIR first intra mb. 0=disabled [0..65535] */
#define VPU_H1_SWREG57_BF_16(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG57_BF_16_SHIFT)) & VPU_H1_SWREG57_BF_16_MASK)
/*! @} */

/*! @name SWREG60 - VPU H1 Register 60 */
/*! @{ */

#define VPU_H1_SWREG60_BF_0_MASK                 (0xFFU)
#define VPU_H1_SWREG60_BF_0_SHIFT                (0U)
/*! BF_0 - 1st ROI area bottom mb row (outside area) */
#define VPU_H1_SWREG60_BF_0(x)                   (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG60_BF_0_SHIFT)) & VPU_H1_SWREG60_BF_0_MASK)

#define VPU_H1_SWREG60_BF_8_MASK                 (0xFF00U)
#define VPU_H1_SWREG60_BF_8_SHIFT                (8U)
/*! BF_8 - 1st ROI area top mb row (inside area) */
#define VPU_H1_SWREG60_BF_8(x)                   (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG60_BF_8_SHIFT)) & VPU_H1_SWREG60_BF_8_MASK)

#define VPU_H1_SWREG60_BF_16_MASK                (0xFF0000U)
#define VPU_H1_SWREG60_BF_16_SHIFT               (16U)
/*! BF_16 - 1st ROI area right mb column (outside area) qp-=Roi1DeltaQp */
#define VPU_H1_SWREG60_BF_16(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG60_BF_16_SHIFT)) & VPU_H1_SWREG60_BF_16_MASK)

#define VPU_H1_SWREG60_BF_24_MASK                (0xFF000000U)
#define VPU_H1_SWREG60_BF_24_SHIFT               (24U)
/*! BF_24 - 1st ROI area left mb column (inside area) qp+=Roi1DeltaQp */
#define VPU_H1_SWREG60_BF_24(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG60_BF_24_SHIFT)) & VPU_H1_SWREG60_BF_24_MASK)
/*! @} */

/*! @name SWREG61 - VPU H1 Register 61 */
/*! @{ */

#define VPU_H1_SWREG61_BF_0_MASK                 (0xFFU)
#define VPU_H1_SWREG61_BF_0_SHIFT                (0U)
/*! BF_0 - 2nd ROI area bottom mb row (outside area) */
#define VPU_H1_SWREG61_BF_0(x)                   (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG61_BF_0_SHIFT)) & VPU_H1_SWREG61_BF_0_MASK)

#define VPU_H1_SWREG61_BF_8_MASK                 (0xFF00U)
#define VPU_H1_SWREG61_BF_8_SHIFT                (8U)
/*! BF_8 - 2nd ROI area top mb row (inside area) */
#define VPU_H1_SWREG61_BF_8(x)                   (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG61_BF_8_SHIFT)) & VPU_H1_SWREG61_BF_8_MASK)

#define VPU_H1_SWREG61_BF_16_MASK                (0xFF0000U)
#define VPU_H1_SWREG61_BF_16_SHIFT               (16U)
/*! BF_16 - 2nd ROI area right mb column (outside area) qp-=Roi2DeltaQp */
#define VPU_H1_SWREG61_BF_16(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG61_BF_16_SHIFT)) & VPU_H1_SWREG61_BF_16_MASK)

#define VPU_H1_SWREG61_BF_24_MASK                (0xFF000000U)
#define VPU_H1_SWREG61_BF_24_SHIFT               (24U)
/*! BF_24 - 2nd ROI area left mb column (inside area) qp+=Roi2DeltaQp */
#define VPU_H1_SWREG61_BF_24(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG61_BF_24_SHIFT)) & VPU_H1_SWREG61_BF_24_MASK)
/*! @} */

/*! @name SWREG62 - VPU H1 Register 62 */
/*! @{ */

#define VPU_H1_SWREG62_BF_0_MASK                 (0xFU)
#define VPU_H1_SWREG62_BF_0_SHIFT                (0U)
/*! BF_0 - 2nd ROI area delta QP. qp = Qp - Roi2DeltaQp [0..15] */
#define VPU_H1_SWREG62_BF_0(x)                   (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG62_BF_0_SHIFT)) & VPU_H1_SWREG62_BF_0_MASK)

#define VPU_H1_SWREG62_BF_4_MASK                 (0xF0U)
#define VPU_H1_SWREG62_BF_4_SHIFT                (4U)
/*! BF_4 - 1st ROI area delta QP. qp = Qp - Roi1DeltaQp [0..15] */
#define VPU_H1_SWREG62_BF_4(x)                   (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG62_BF_4_SHIFT)) & VPU_H1_SWREG62_BF_4_MASK)

#define VPU_H1_SWREG62_BF_8_MASK                 (0x100U)
#define VPU_H1_SWREG62_BF_8_SHIFT                (8U)
/*! BF_8 - MVC inter_view_flag. Specifies that the picture is used for inter-view prediction. */
#define VPU_H1_SWREG62_BF_8(x)                   (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG62_BF_8_SHIFT)) & VPU_H1_SWREG62_BF_8_MASK)

#define VPU_H1_SWREG62_BF_9_MASK                 (0x200U)
#define VPU_H1_SWREG62_BF_9_SHIFT                (9U)
/*! BF_9 - MVC anchor_pic_flag. Specifies that the picture is part of an anchor access unit. */
#define VPU_H1_SWREG62_BF_9(x)                   (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG62_BF_9_SHIFT)) & VPU_H1_SWREG62_BF_9_MASK)

#define VPU_H1_SWREG62_BF_10_MASK                (0x1C00U)
#define VPU_H1_SWREG62_BF_10_SHIFT               (10U)
/*! BF_10 - MVC temporal_id [0..7] */
#define VPU_H1_SWREG62_BF_10(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG62_BF_10_SHIFT)) & VPU_H1_SWREG62_BF_10_MASK)

#define VPU_H1_SWREG62_BF_13_MASK                (0xE000U)
#define VPU_H1_SWREG62_BF_13_SHIFT               (13U)
/*! BF_13 - MVC view_id [0..7] */
#define VPU_H1_SWREG62_BF_13(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG62_BF_13_SHIFT)) & VPU_H1_SWREG62_BF_13_MASK)

#define VPU_H1_SWREG62_BF_16_MASK                (0x70000U)
#define VPU_H1_SWREG62_BF_16_SHIFT               (16U)
/*! BF_16 - MVC priority_id [0..7] */
#define VPU_H1_SWREG62_BF_16(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG62_BF_16_SHIFT)) & VPU_H1_SWREG62_BF_16_MASK)

#define VPU_H1_SWREG62_BF_19_MASK                (0xFF80000U)
#define VPU_H1_SWREG62_BF_19_SHIFT               (19U)
/*! BF_19 - Penalty for using 4x4 MV. */
#define VPU_H1_SWREG62_BF_19(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG62_BF_19_SHIFT)) & VPU_H1_SWREG62_BF_19_MASK)

#define VPU_H1_SWREG62_BF_28_MASK                (0xF0000000U)
#define VPU_H1_SWREG62_BF_28_SHIFT               (28U)
/*! BF_28 - Zero 16x16 MV favor div2. */
#define VPU_H1_SWREG62_BF_28(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG62_BF_28_SHIFT)) & VPU_H1_SWREG62_BF_28_MASK)
/*! @} */

/*! @name SWREG63 - VPU H1 Register 63 */
/*! @{ */

#define VPU_H1_SWREG63_BF_0_MASK                 (0xFFFU)
#define VPU_H1_SWREG63_BF_0_SHIFT                (0U)
/*! BF_0 - Maximum video width supported by HW (pixels) */
#define VPU_H1_SWREG63_BF_0(x)                   (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG63_BF_0_SHIFT)) & VPU_H1_SWREG63_BF_0_MASK)

#define VPU_H1_SWREG63_BF_12_MASK                (0xF000U)
#define VPU_H1_SWREG63_BF_12_SHIFT               (12U)
/*! BF_12 - Bus width of HW. */
#define VPU_H1_SWREG63_BF_12(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG63_BF_12_SHIFT)) & VPU_H1_SWREG63_BF_12_MASK)

#define VPU_H1_SWREG63_BF_16_MASK                (0xF0000U)
#define VPU_H1_SWREG63_BF_16_SHIFT               (16U)
/*! BF_16 - Synthesis language. */
#define VPU_H1_SWREG63_BF_16(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG63_BF_16_SHIFT)) & VPU_H1_SWREG63_BF_16_MASK)

#define VPU_H1_SWREG63_BF_20_MASK                (0xF00000U)
#define VPU_H1_SWREG63_BF_20_SHIFT               (20U)
/*! BF_20 - Bus connection of HW. */
#define VPU_H1_SWREG63_BF_20(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG63_BF_20_SHIFT)) & VPU_H1_SWREG63_BF_20_MASK)

#define VPU_H1_SWREG63_BF_24_MASK                (0x1000000U)
#define VPU_H1_SWREG63_BF_24_SHIFT               (24U)
/*! BF_24 - Stabilization supported by HW. */
#define VPU_H1_SWREG63_BF_24(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG63_BF_24_SHIFT)) & VPU_H1_SWREG63_BF_24_MASK)

#define VPU_H1_SWREG63_BF_25_MASK                (0x2000000U)
#define VPU_H1_SWREG63_BF_25_SHIFT               (25U)
/*! BF_25 - JPEG encoding supported by HW. */
#define VPU_H1_SWREG63_BF_25(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG63_BF_25_SHIFT)) & VPU_H1_SWREG63_BF_25_MASK)

#define VPU_H1_SWREG63_BF_26_MASK                (0x4000000U)
#define VPU_H1_SWREG63_BF_26_SHIFT               (26U)
/*! BF_26 - VP8 encoding supported by HW. */
#define VPU_H1_SWREG63_BF_26(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG63_BF_26_SHIFT)) & VPU_H1_SWREG63_BF_26_MASK)

#define VPU_H1_SWREG63_BF_27_MASK                (0x8000000U)
#define VPU_H1_SWREG63_BF_27_SHIFT               (27U)
/*! BF_27 - H.264 encoding supported by HW. */
#define VPU_H1_SWREG63_BF_27(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG63_BF_27_SHIFT)) & VPU_H1_SWREG63_BF_27_MASK)

#define VPU_H1_SWREG63_BF_28_MASK                (0x10000000U)
#define VPU_H1_SWREG63_BF_28_SHIFT               (28U)
/*! BF_28 - RGB to YUV conversion supported by HW. */
#define VPU_H1_SWREG63_BF_28(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG63_BF_28_SHIFT)) & VPU_H1_SWREG63_BF_28_MASK)

#define VPU_H1_SWREG63_BF_29_MASK                (0x20000000U)
#define VPU_H1_SWREG63_BF_29_SHIFT               (29U)
/*! BF_29 - HW search area height. */
#define VPU_H1_SWREG63_BF_29(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG63_BF_29_SHIFT)) & VPU_H1_SWREG63_BF_29_MASK)

#define VPU_H1_SWREG63_BF_30_MASK                (0x40000000U)
#define VPU_H1_SWREG63_BF_30_SHIFT               (30U)
/*! BF_30 - Down-scaling supported by HW. */
#define VPU_H1_SWREG63_BF_30(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG63_BF_30_SHIFT)) & VPU_H1_SWREG63_BF_30_MASK)

#define VPU_H1_SWREG63_BF_31_MASK                (0x80000000U)
#define VPU_H1_SWREG63_BF_31_SHIFT               (31U)
/*! BF_31 - HW Chrominance search area internal buffer. */
#define VPU_H1_SWREG63_BF_31(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG63_BF_31_SHIFT)) & VPU_H1_SWREG63_BF_31_MASK)
/*! @} */

/*! @name SWREG96 - VPU H1 Register 96 */
/*! @{ */

#define VPU_H1_SWREG96_BF_0_MASK                 (0xFFFFFFFFU)
#define VPU_H1_SWREG96_BF_0_SHIFT                (0U)
/*! BF_0 - DMV 4p/1p penalty values 0-3 */
#define VPU_H1_SWREG96_BF_0(x)                   (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG96_BF_0_SHIFT)) & VPU_H1_SWREG96_BF_0_MASK)
/*! @} */

/*! @name SWREG97 - VPU H1 Register 97 */
/*! @{ */

#define VPU_H1_SWREG97_BF_0_MASK                 (0xFFFFFFFFU)
#define VPU_H1_SWREG97_BF_0_SHIFT                (0U)
/*! BF_0 - DMV 4p/1p penalty values 4-7 */
#define VPU_H1_SWREG97_BF_0(x)                   (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG97_BF_0_SHIFT)) & VPU_H1_SWREG97_BF_0_MASK)
/*! @} */

/*! @name SWREG98 - VPU H1 Register 98 */
/*! @{ */

#define VPU_H1_SWREG98_BF_0_MASK                 (0xFFFFFFFFU)
#define VPU_H1_SWREG98_BF_0_SHIFT                (0U)
/*! BF_0 - DMV 4p/1p penalty values */
#define VPU_H1_SWREG98_BF_0(x)                   (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG98_BF_0_SHIFT)) & VPU_H1_SWREG98_BF_0_MASK)
/*! @} */

/*! @name SWREG99 - VPU H1 Register 99 */
/*! @{ */

#define VPU_H1_SWREG99_BF_0_MASK                 (0xFFFFFFFFU)
#define VPU_H1_SWREG99_BF_0_SHIFT                (0U)
/*! BF_0 - DMV 4p/1p penalty values */
#define VPU_H1_SWREG99_BF_0(x)                   (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG99_BF_0_SHIFT)) & VPU_H1_SWREG99_BF_0_MASK)
/*! @} */

/*! @name SWREG100 - VPU H1 Register 100 */
/*! @{ */

#define VPU_H1_SWREG100_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG100_BF_0_SHIFT               (0U)
/*! BF_0 - DMV 4p/1p penalty values */
#define VPU_H1_SWREG100_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG100_BF_0_SHIFT)) & VPU_H1_SWREG100_BF_0_MASK)
/*! @} */

/*! @name SWREG101 - VPU H1 Register 101 */
/*! @{ */

#define VPU_H1_SWREG101_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG101_BF_0_SHIFT               (0U)
/*! BF_0 - DMV 4p/1p penalty values */
#define VPU_H1_SWREG101_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG101_BF_0_SHIFT)) & VPU_H1_SWREG101_BF_0_MASK)
/*! @} */

/*! @name SWREG102 - VPU H1 Register 102 */
/*! @{ */

#define VPU_H1_SWREG102_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG102_BF_0_SHIFT               (0U)
/*! BF_0 - DMV 4p/1p penalty values */
#define VPU_H1_SWREG102_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG102_BF_0_SHIFT)) & VPU_H1_SWREG102_BF_0_MASK)
/*! @} */

/*! @name SWREG103 - VPU H1 Register 103 */
/*! @{ */

#define VPU_H1_SWREG103_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG103_BF_0_SHIFT               (0U)
/*! BF_0 - DMV 4p/1p penalty values */
#define VPU_H1_SWREG103_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG103_BF_0_SHIFT)) & VPU_H1_SWREG103_BF_0_MASK)
/*! @} */

/*! @name SWREG104 - VPU H1 Register 104 */
/*! @{ */

#define VPU_H1_SWREG104_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG104_BF_0_SHIFT               (0U)
/*! BF_0 - DMV 4p/1p penalty values */
#define VPU_H1_SWREG104_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG104_BF_0_SHIFT)) & VPU_H1_SWREG104_BF_0_MASK)
/*! @} */

/*! @name SWREG105 - VPU H1 Register 105 */
/*! @{ */

#define VPU_H1_SWREG105_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG105_BF_0_SHIFT               (0U)
/*! BF_0 - DMV 4p/1p penalty values */
#define VPU_H1_SWREG105_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG105_BF_0_SHIFT)) & VPU_H1_SWREG105_BF_0_MASK)
/*! @} */

/*! @name SWREG106 - VPU H1 Register 106 */
/*! @{ */

#define VPU_H1_SWREG106_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG106_BF_0_SHIFT               (0U)
/*! BF_0 - DMV 4p/1p penalty values */
#define VPU_H1_SWREG106_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG106_BF_0_SHIFT)) & VPU_H1_SWREG106_BF_0_MASK)
/*! @} */

/*! @name SWREG107 - VPU H1 Register 107 */
/*! @{ */

#define VPU_H1_SWREG107_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG107_BF_0_SHIFT               (0U)
/*! BF_0 - DMV 4p/1p penalty values */
#define VPU_H1_SWREG107_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG107_BF_0_SHIFT)) & VPU_H1_SWREG107_BF_0_MASK)
/*! @} */

/*! @name SWREG108 - VPU H1 Register 108 */
/*! @{ */

#define VPU_H1_SWREG108_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG108_BF_0_SHIFT               (0U)
/*! BF_0 - DMV 4p/1p penalty values */
#define VPU_H1_SWREG108_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG108_BF_0_SHIFT)) & VPU_H1_SWREG108_BF_0_MASK)
/*! @} */

/*! @name SWREG109 - VPU H1 Register 109 */
/*! @{ */

#define VPU_H1_SWREG109_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG109_BF_0_SHIFT               (0U)
/*! BF_0 - DMV 4p/1p penalty values */
#define VPU_H1_SWREG109_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG109_BF_0_SHIFT)) & VPU_H1_SWREG109_BF_0_MASK)
/*! @} */

/*! @name SWREG110 - VPU H1 Register 110 */
/*! @{ */

#define VPU_H1_SWREG110_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG110_BF_0_SHIFT               (0U)
/*! BF_0 - DMV 4p/1p penalty values */
#define VPU_H1_SWREG110_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG110_BF_0_SHIFT)) & VPU_H1_SWREG110_BF_0_MASK)
/*! @} */

/*! @name SWREG111 - VPU H1 Register 111 */
/*! @{ */

#define VPU_H1_SWREG111_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG111_BF_0_SHIFT               (0U)
/*! BF_0 - DMV 4p/1p penalty values */
#define VPU_H1_SWREG111_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG111_BF_0_SHIFT)) & VPU_H1_SWREG111_BF_0_MASK)
/*! @} */

/*! @name SWREG112 - VPU H1 Register 112 */
/*! @{ */

#define VPU_H1_SWREG112_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG112_BF_0_SHIFT               (0U)
/*! BF_0 - DMV 4p/1p penalty values */
#define VPU_H1_SWREG112_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG112_BF_0_SHIFT)) & VPU_H1_SWREG112_BF_0_MASK)
/*! @} */

/*! @name SWREG113 - VPU H1 Register 113 */
/*! @{ */

#define VPU_H1_SWREG113_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG113_BF_0_SHIFT               (0U)
/*! BF_0 - DMV 4p/1p penalty values */
#define VPU_H1_SWREG113_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG113_BF_0_SHIFT)) & VPU_H1_SWREG113_BF_0_MASK)
/*! @} */

/*! @name SWREG114 - VPU H1 Register 114 */
/*! @{ */

#define VPU_H1_SWREG114_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG114_BF_0_SHIFT               (0U)
/*! BF_0 - DMV 4p/1p penalty values */
#define VPU_H1_SWREG114_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG114_BF_0_SHIFT)) & VPU_H1_SWREG114_BF_0_MASK)
/*! @} */

/*! @name SWREG115 - VPU H1 Register 115 */
/*! @{ */

#define VPU_H1_SWREG115_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG115_BF_0_SHIFT               (0U)
/*! BF_0 - DMV 4p/1p penalty values */
#define VPU_H1_SWREG115_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG115_BF_0_SHIFT)) & VPU_H1_SWREG115_BF_0_MASK)
/*! @} */

/*! @name SWREG116 - VPU H1 Register 116 */
/*! @{ */

#define VPU_H1_SWREG116_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG116_BF_0_SHIFT               (0U)
/*! BF_0 - DMV 4p/1p penalty values */
#define VPU_H1_SWREG116_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG116_BF_0_SHIFT)) & VPU_H1_SWREG116_BF_0_MASK)
/*! @} */

/*! @name SWREG117 - VPU H1 Register 117 */
/*! @{ */

#define VPU_H1_SWREG117_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG117_BF_0_SHIFT               (0U)
/*! BF_0 - DMV 4p/1p penalty values */
#define VPU_H1_SWREG117_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG117_BF_0_SHIFT)) & VPU_H1_SWREG117_BF_0_MASK)
/*! @} */

/*! @name SWREG118 - VPU H1 Register 118 */
/*! @{ */

#define VPU_H1_SWREG118_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG118_BF_0_SHIFT               (0U)
/*! BF_0 - DMV 4p/1p penalty values */
#define VPU_H1_SWREG118_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG118_BF_0_SHIFT)) & VPU_H1_SWREG118_BF_0_MASK)
/*! @} */

/*! @name SWREG119 - VPU H1 Register 119 */
/*! @{ */

#define VPU_H1_SWREG119_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG119_BF_0_SHIFT               (0U)
/*! BF_0 - DMV 4p/1p penalty values */
#define VPU_H1_SWREG119_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG119_BF_0_SHIFT)) & VPU_H1_SWREG119_BF_0_MASK)
/*! @} */

/*! @name SWREG120 - VPU H1 Register 120 */
/*! @{ */

#define VPU_H1_SWREG120_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG120_BF_0_SHIFT               (0U)
/*! BF_0 - DMV 4p/1p penalty values */
#define VPU_H1_SWREG120_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG120_BF_0_SHIFT)) & VPU_H1_SWREG120_BF_0_MASK)
/*! @} */

/*! @name SWREG121 - VPU H1 Register 121 */
/*! @{ */

#define VPU_H1_SWREG121_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG121_BF_0_SHIFT               (0U)
/*! BF_0 - DMV 4p/1p penalty values */
#define VPU_H1_SWREG121_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG121_BF_0_SHIFT)) & VPU_H1_SWREG121_BF_0_MASK)
/*! @} */

/*! @name SWREG122 - VPU H1 Register 122 */
/*! @{ */

#define VPU_H1_SWREG122_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG122_BF_0_SHIFT               (0U)
/*! BF_0 - DMV 4p/1p penalty values */
#define VPU_H1_SWREG122_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG122_BF_0_SHIFT)) & VPU_H1_SWREG122_BF_0_MASK)
/*! @} */

/*! @name SWREG123 - VPU H1 Register 123 */
/*! @{ */

#define VPU_H1_SWREG123_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG123_BF_0_SHIFT               (0U)
/*! BF_0 - DMV 4p/1p penalty values */
#define VPU_H1_SWREG123_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG123_BF_0_SHIFT)) & VPU_H1_SWREG123_BF_0_MASK)
/*! @} */

/*! @name SWREG124 - VPU H1 Register 124 */
/*! @{ */

#define VPU_H1_SWREG124_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG124_BF_0_SHIFT               (0U)
/*! BF_0 - DMV 4p/1p penalty values */
#define VPU_H1_SWREG124_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG124_BF_0_SHIFT)) & VPU_H1_SWREG124_BF_0_MASK)
/*! @} */

/*! @name SWREG125 - VPU H1 Register 125 */
/*! @{ */

#define VPU_H1_SWREG125_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG125_BF_0_SHIFT               (0U)
/*! BF_0 - DMV 4p/1p penalty values */
#define VPU_H1_SWREG125_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG125_BF_0_SHIFT)) & VPU_H1_SWREG125_BF_0_MASK)
/*! @} */

/*! @name SWREG126 - VPU H1 Register 126 */
/*! @{ */

#define VPU_H1_SWREG126_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG126_BF_0_SHIFT               (0U)
/*! BF_0 - DMV 4p/1p penalty values */
#define VPU_H1_SWREG126_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG126_BF_0_SHIFT)) & VPU_H1_SWREG126_BF_0_MASK)
/*! @} */

/*! @name SWREG127 - VPU H1 Register 127 */
/*! @{ */

#define VPU_H1_SWREG127_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG127_BF_0_SHIFT               (0U)
/*! BF_0 - DMV 4p/1p penalty values 124-127 */
#define VPU_H1_SWREG127_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG127_BF_0_SHIFT)) & VPU_H1_SWREG127_BF_0_MASK)
/*! @} */

/*! @name SWREG128 - VPU H1 Register 128 */
/*! @{ */

#define VPU_H1_SWREG128_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG128_BF_0_SHIFT               (0U)
/*! BF_0 - DMV qpel penalty values 0-3 */
#define VPU_H1_SWREG128_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG128_BF_0_SHIFT)) & VPU_H1_SWREG128_BF_0_MASK)
/*! @} */

/*! @name SWREG129 - VPU H1 Register 129 */
/*! @{ */

#define VPU_H1_SWREG129_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG129_BF_0_SHIFT               (0U)
/*! BF_0 - DMV qpel penalty values 4-7 */
#define VPU_H1_SWREG129_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG129_BF_0_SHIFT)) & VPU_H1_SWREG129_BF_0_MASK)
/*! @} */

/*! @name SWREG130 - VPU H1 Register 130 */
/*! @{ */

#define VPU_H1_SWREG130_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG130_BF_0_SHIFT               (0U)
/*! BF_0 - DMV qpel penalty values */
#define VPU_H1_SWREG130_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG130_BF_0_SHIFT)) & VPU_H1_SWREG130_BF_0_MASK)
/*! @} */

/*! @name SWREG131 - VPU H1 Register 131 */
/*! @{ */

#define VPU_H1_SWREG131_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG131_BF_0_SHIFT               (0U)
/*! BF_0 - DMV qpel penalty values */
#define VPU_H1_SWREG131_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG131_BF_0_SHIFT)) & VPU_H1_SWREG131_BF_0_MASK)
/*! @} */

/*! @name SWREG132 - VPU H1 Register 132 */
/*! @{ */

#define VPU_H1_SWREG132_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG132_BF_0_SHIFT               (0U)
/*! BF_0 - DMV qpel penalty values */
#define VPU_H1_SWREG132_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG132_BF_0_SHIFT)) & VPU_H1_SWREG132_BF_0_MASK)
/*! @} */

/*! @name SWREG133 - VPU H1 Register 133 */
/*! @{ */

#define VPU_H1_SWREG133_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG133_BF_0_SHIFT               (0U)
/*! BF_0 - DMV qpel penalty values */
#define VPU_H1_SWREG133_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG133_BF_0_SHIFT)) & VPU_H1_SWREG133_BF_0_MASK)
/*! @} */

/*! @name SWREG134 - VPU H1 Register 134 */
/*! @{ */

#define VPU_H1_SWREG134_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG134_BF_0_SHIFT               (0U)
/*! BF_0 - DMV qpel penalty values */
#define VPU_H1_SWREG134_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG134_BF_0_SHIFT)) & VPU_H1_SWREG134_BF_0_MASK)
/*! @} */

/*! @name SWREG135 - VPU H1 Register 135 */
/*! @{ */

#define VPU_H1_SWREG135_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG135_BF_0_SHIFT               (0U)
/*! BF_0 - DMV qpel penalty values */
#define VPU_H1_SWREG135_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG135_BF_0_SHIFT)) & VPU_H1_SWREG135_BF_0_MASK)
/*! @} */

/*! @name SWREG136 - VPU H1 Register 136 */
/*! @{ */

#define VPU_H1_SWREG136_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG136_BF_0_SHIFT               (0U)
/*! BF_0 - DMV qpel penalty values */
#define VPU_H1_SWREG136_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG136_BF_0_SHIFT)) & VPU_H1_SWREG136_BF_0_MASK)
/*! @} */

/*! @name SWREG137 - VPU H1 Register 137 */
/*! @{ */

#define VPU_H1_SWREG137_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG137_BF_0_SHIFT               (0U)
/*! BF_0 - DMV qpel penalty values */
#define VPU_H1_SWREG137_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG137_BF_0_SHIFT)) & VPU_H1_SWREG137_BF_0_MASK)
/*! @} */

/*! @name SWREG138 - VPU H1 Register 138 */
/*! @{ */

#define VPU_H1_SWREG138_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG138_BF_0_SHIFT               (0U)
/*! BF_0 - DMV qpel penalty values */
#define VPU_H1_SWREG138_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG138_BF_0_SHIFT)) & VPU_H1_SWREG138_BF_0_MASK)
/*! @} */

/*! @name SWREG139 - VPU H1 Register 139 */
/*! @{ */

#define VPU_H1_SWREG139_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG139_BF_0_SHIFT               (0U)
/*! BF_0 - DMV qpel penalty values */
#define VPU_H1_SWREG139_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG139_BF_0_SHIFT)) & VPU_H1_SWREG139_BF_0_MASK)
/*! @} */

/*! @name SWREG140 - VPU H1 Register 140 */
/*! @{ */

#define VPU_H1_SWREG140_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG140_BF_0_SHIFT               (0U)
/*! BF_0 - DMV qpel penalty values */
#define VPU_H1_SWREG140_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG140_BF_0_SHIFT)) & VPU_H1_SWREG140_BF_0_MASK)
/*! @} */

/*! @name SWREG141 - VPU H1 Register 141 */
/*! @{ */

#define VPU_H1_SWREG141_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG141_BF_0_SHIFT               (0U)
/*! BF_0 - DMV qpel penalty values */
#define VPU_H1_SWREG141_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG141_BF_0_SHIFT)) & VPU_H1_SWREG141_BF_0_MASK)
/*! @} */

/*! @name SWREG142 - VPU H1 Register 142 */
/*! @{ */

#define VPU_H1_SWREG142_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG142_BF_0_SHIFT               (0U)
/*! BF_0 - DMV qpel penalty values */
#define VPU_H1_SWREG142_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG142_BF_0_SHIFT)) & VPU_H1_SWREG142_BF_0_MASK)
/*! @} */

/*! @name SWREG143 - VPU H1 Register 143 */
/*! @{ */

#define VPU_H1_SWREG143_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG143_BF_0_SHIFT               (0U)
/*! BF_0 - DMV qpel penalty values */
#define VPU_H1_SWREG143_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG143_BF_0_SHIFT)) & VPU_H1_SWREG143_BF_0_MASK)
/*! @} */

/*! @name SWREG144 - VPU H1 Register 144 */
/*! @{ */

#define VPU_H1_SWREG144_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG144_BF_0_SHIFT               (0U)
/*! BF_0 - DMV qpel penalty values */
#define VPU_H1_SWREG144_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG144_BF_0_SHIFT)) & VPU_H1_SWREG144_BF_0_MASK)
/*! @} */

/*! @name SWREG145 - VPU H1 Register 145 */
/*! @{ */

#define VPU_H1_SWREG145_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG145_BF_0_SHIFT               (0U)
/*! BF_0 - DMV qpel penalty values */
#define VPU_H1_SWREG145_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG145_BF_0_SHIFT)) & VPU_H1_SWREG145_BF_0_MASK)
/*! @} */

/*! @name SWREG146 - VPU H1 Register 146 */
/*! @{ */

#define VPU_H1_SWREG146_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG146_BF_0_SHIFT               (0U)
/*! BF_0 - DMV qpel penalty values */
#define VPU_H1_SWREG146_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG146_BF_0_SHIFT)) & VPU_H1_SWREG146_BF_0_MASK)
/*! @} */

/*! @name SWREG147 - VPU H1 Register 147 */
/*! @{ */

#define VPU_H1_SWREG147_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG147_BF_0_SHIFT               (0U)
/*! BF_0 - DMV qpel penalty values */
#define VPU_H1_SWREG147_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG147_BF_0_SHIFT)) & VPU_H1_SWREG147_BF_0_MASK)
/*! @} */

/*! @name SWREG148 - VPU H1 Register 148 */
/*! @{ */

#define VPU_H1_SWREG148_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG148_BF_0_SHIFT               (0U)
/*! BF_0 - DMV qpel penalty values */
#define VPU_H1_SWREG148_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG148_BF_0_SHIFT)) & VPU_H1_SWREG148_BF_0_MASK)
/*! @} */

/*! @name SWREG149 - VPU H1 Register 149 */
/*! @{ */

#define VPU_H1_SWREG149_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG149_BF_0_SHIFT               (0U)
/*! BF_0 - DMV qpel penalty values */
#define VPU_H1_SWREG149_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG149_BF_0_SHIFT)) & VPU_H1_SWREG149_BF_0_MASK)
/*! @} */

/*! @name SWREG150 - VPU H1 Register 150 */
/*! @{ */

#define VPU_H1_SWREG150_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG150_BF_0_SHIFT               (0U)
/*! BF_0 - DMV qpel penalty values */
#define VPU_H1_SWREG150_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG150_BF_0_SHIFT)) & VPU_H1_SWREG150_BF_0_MASK)
/*! @} */

/*! @name SWREG151 - VPU H1 Register 151 */
/*! @{ */

#define VPU_H1_SWREG151_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG151_BF_0_SHIFT               (0U)
/*! BF_0 - DMV qpel penalty values */
#define VPU_H1_SWREG151_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG151_BF_0_SHIFT)) & VPU_H1_SWREG151_BF_0_MASK)
/*! @} */

/*! @name SWREG152 - VPU H1 Register 152 */
/*! @{ */

#define VPU_H1_SWREG152_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG152_BF_0_SHIFT               (0U)
/*! BF_0 - DMV qpel penalty values */
#define VPU_H1_SWREG152_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG152_BF_0_SHIFT)) & VPU_H1_SWREG152_BF_0_MASK)
/*! @} */

/*! @name SWREG153 - VPU H1 Register 153 */
/*! @{ */

#define VPU_H1_SWREG153_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG153_BF_0_SHIFT               (0U)
/*! BF_0 - DMV qpel penalty values */
#define VPU_H1_SWREG153_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG153_BF_0_SHIFT)) & VPU_H1_SWREG153_BF_0_MASK)
/*! @} */

/*! @name SWREG154 - VPU H1 Register 154 */
/*! @{ */

#define VPU_H1_SWREG154_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG154_BF_0_SHIFT               (0U)
/*! BF_0 - DMV qpel penalty values */
#define VPU_H1_SWREG154_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG154_BF_0_SHIFT)) & VPU_H1_SWREG154_BF_0_MASK)
/*! @} */

/*! @name SWREG155 - VPU H1 Register 155 */
/*! @{ */

#define VPU_H1_SWREG155_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG155_BF_0_SHIFT               (0U)
/*! BF_0 - DMV qpel penalty values */
#define VPU_H1_SWREG155_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG155_BF_0_SHIFT)) & VPU_H1_SWREG155_BF_0_MASK)
/*! @} */

/*! @name SWREG156 - VPU H1 Register 156 */
/*! @{ */

#define VPU_H1_SWREG156_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG156_BF_0_SHIFT               (0U)
/*! BF_0 - DMV qpel penalty values */
#define VPU_H1_SWREG156_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG156_BF_0_SHIFT)) & VPU_H1_SWREG156_BF_0_MASK)
/*! @} */

/*! @name SWREG157 - VPU H1 Register 157 */
/*! @{ */

#define VPU_H1_SWREG157_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG157_BF_0_SHIFT               (0U)
/*! BF_0 - DMV qpel penalty values */
#define VPU_H1_SWREG157_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG157_BF_0_SHIFT)) & VPU_H1_SWREG157_BF_0_MASK)
/*! @} */

/*! @name SWREG158 - VPU H1 Register 158 */
/*! @{ */

#define VPU_H1_SWREG158_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG158_BF_0_SHIFT               (0U)
/*! BF_0 - DMV qpel penalty values */
#define VPU_H1_SWREG158_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG158_BF_0_SHIFT)) & VPU_H1_SWREG158_BF_0_MASK)
/*! @} */

/*! @name SWREG159 - VPU H1 Register 159 */
/*! @{ */

#define VPU_H1_SWREG159_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG159_BF_0_SHIFT               (0U)
/*! BF_0 - DMV qpel penalty values 124-127 */
#define VPU_H1_SWREG159_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG159_BF_0_SHIFT)) & VPU_H1_SWREG159_BF_0_MASK)
/*! @} */

/*! @name SWREG160 - VPU H1 Register 160 */
/*! @{ */

#define VPU_H1_SWREG160_BF_0_MASK                (0xFFFU)
#define VPU_H1_SWREG160_BF_0_SHIFT               (0U)
/*! BF_0 - VP8 bit cost of inter type */
#define VPU_H1_SWREG160_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG160_BF_0_SHIFT)) & VPU_H1_SWREG160_BF_0_MASK)

#define VPU_H1_SWREG160_BF_12_MASK               (0xFFF000U)
#define VPU_H1_SWREG160_BF_12_SHIFT              (12U)
/*! BF_12 - VP8 coeff for dmv penalty for intra/inter selection */
#define VPU_H1_SWREG160_BF_12(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG160_BF_12_SHIFT)) & VPU_H1_SWREG160_BF_12_MASK)

#define VPU_H1_SWREG160_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG160_BF_24_SHIFT              (24U)
/*! BF_24 - Penalty for using zero-MV in 16x8/8x16/8x8 split */
#define VPU_H1_SWREG160_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG160_BF_24_SHIFT)) & VPU_H1_SWREG160_BF_24_MASK)
/*! @} */

/*! @name SWREG161 - VPU H1 Register 161 */
/*! @{ */

#define VPU_H1_SWREG161_BF_0_MASK                (0xFFFU)
#define VPU_H1_SWREG161_BF_0_SHIFT               (0U)
/*! BF_0 - VP8 bit cost of golden ref frame (not used) */
#define VPU_H1_SWREG161_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG161_BF_0_SHIFT)) & VPU_H1_SWREG161_BF_0_MASK)
/*! @} */

/*! @name SWREG162 - VPU H1 Register 162 */
/*! @{ */

#define VPU_H1_SWREG162_BF_0_MASK                (0x7FU)
#define VPU_H1_SWREG162_BF_0_SHIFT               (0U)
/*! BF_0 - VP8 loop filter delta for intra mb */
#define VPU_H1_SWREG162_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG162_BF_0_SHIFT)) & VPU_H1_SWREG162_BF_0_MASK)

#define VPU_H1_SWREG162_BF_7_MASK                (0x3F80U)
#define VPU_H1_SWREG162_BF_7_SHIFT               (7U)
/*! BF_7 - VP8 loop filter delta for last ref */
#define VPU_H1_SWREG162_BF_7(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG162_BF_7_SHIFT)) & VPU_H1_SWREG162_BF_7_MASK)

#define VPU_H1_SWREG162_BF_14_MASK               (0x1FC000U)
#define VPU_H1_SWREG162_BF_14_SHIFT              (14U)
/*! BF_14 - VP8 loop filter delta for golden ref */
#define VPU_H1_SWREG162_BF_14(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG162_BF_14_SHIFT)) & VPU_H1_SWREG162_BF_14_MASK)

#define VPU_H1_SWREG162_BF_21_MASK               (0xFE00000U)
#define VPU_H1_SWREG162_BF_21_SHIFT              (21U)
/*! BF_21 - VP8 loop filter delta for alt ref */
#define VPU_H1_SWREG162_BF_21(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG162_BF_21_SHIFT)) & VPU_H1_SWREG162_BF_21_MASK)
/*! @} */

/*! @name SWREG163 - VPU H1 Register 163 */
/*! @{ */

#define VPU_H1_SWREG163_BF_0_MASK                (0x7FU)
#define VPU_H1_SWREG163_BF_0_SHIFT               (0U)
/*! BF_0 - VP8 loop filter delta for BPRED */
#define VPU_H1_SWREG163_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG163_BF_0_SHIFT)) & VPU_H1_SWREG163_BF_0_MASK)

#define VPU_H1_SWREG163_BF_7_MASK                (0x3F80U)
#define VPU_H1_SWREG163_BF_7_SHIFT               (7U)
/*! BF_7 - VP8 loop filter delta for ZEROMV */
#define VPU_H1_SWREG163_BF_7(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG163_BF_7_SHIFT)) & VPU_H1_SWREG163_BF_7_MASK)

#define VPU_H1_SWREG163_BF_14_MASK               (0x1FC000U)
#define VPU_H1_SWREG163_BF_14_SHIFT              (14U)
/*! BF_14 - VP8 loop filter delta for NEWMV */
#define VPU_H1_SWREG163_BF_14(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG163_BF_14_SHIFT)) & VPU_H1_SWREG163_BF_14_MASK)

#define VPU_H1_SWREG163_BF_21_MASK               (0xFE00000U)
#define VPU_H1_SWREG163_BF_21_SHIFT              (21U)
/*! BF_21 - VP8 loop filter delta for SPLITMV */
#define VPU_H1_SWREG163_BF_21(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG163_BF_21_SHIFT)) & VPU_H1_SWREG163_BF_21_MASK)
/*! @} */

/*! @name SWREG164 - VPU H1 Register 164 */
/*! @{ */

#define VPU_H1_SWREG164_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG164_BF_0_SHIFT               (0U)
/*! BF_0 - VP8 deadzone lookup table */
#define VPU_H1_SWREG164_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG164_BF_0_SHIFT)) & VPU_H1_SWREG164_BF_0_MASK)
/*! @} */

/*! @name SWREG165 - VPU H1 Register 165 */
/*! @{ */

#define VPU_H1_SWREG165_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG165_BF_0_SHIFT               (0U)
/*! BF_0 - VP8 deadzone lookup table */
#define VPU_H1_SWREG165_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG165_BF_0_SHIFT)) & VPU_H1_SWREG165_BF_0_MASK)
/*! @} */

/*! @name SWREG166 - VPU H1 Register 166 */
/*! @{ */

#define VPU_H1_SWREG166_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG166_BF_0_SHIFT               (0U)
/*! BF_0 - VP8 deadzone lookup table */
#define VPU_H1_SWREG166_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG166_BF_0_SHIFT)) & VPU_H1_SWREG166_BF_0_MASK)
/*! @} */

/*! @name SWREG167 - VPU H1 Register 167 */
/*! @{ */

#define VPU_H1_SWREG167_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG167_BF_0_SHIFT               (0U)
/*! BF_0 - VP8 deadzone lookup table */
#define VPU_H1_SWREG167_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG167_BF_0_SHIFT)) & VPU_H1_SWREG167_BF_0_MASK)
/*! @} */

/*! @name SWREG168 - VPU H1 Register 168 */
/*! @{ */

#define VPU_H1_SWREG168_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG168_BF_0_SHIFT               (0U)
/*! BF_0 - VP8 deadzone lookup table */
#define VPU_H1_SWREG168_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG168_BF_0_SHIFT)) & VPU_H1_SWREG168_BF_0_MASK)
/*! @} */

/*! @name SWREG169 - VPU H1 Register 169 */
/*! @{ */

#define VPU_H1_SWREG169_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG169_BF_0_SHIFT               (0U)
/*! BF_0 - VP8 deadzone lookup table */
#define VPU_H1_SWREG169_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG169_BF_0_SHIFT)) & VPU_H1_SWREG169_BF_0_MASK)
/*! @} */

/*! @name SWREG170 - VPU H1 Register 170 */
/*! @{ */

#define VPU_H1_SWREG170_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG170_BF_0_SHIFT               (0U)
/*! BF_0 - VP8 deadzone lookup table */
#define VPU_H1_SWREG170_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG170_BF_0_SHIFT)) & VPU_H1_SWREG170_BF_0_MASK)
/*! @} */

/*! @name SWREG171 - VPU H1 Register 171 */
/*! @{ */

#define VPU_H1_SWREG171_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG171_BF_0_SHIFT               (0U)
/*! BF_0 - VP8 deadzone lookup table */
#define VPU_H1_SWREG171_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG171_BF_0_SHIFT)) & VPU_H1_SWREG171_BF_0_MASK)
/*! @} */

/*! @name SWREG172 - VPU H1 Register 172 */
/*! @{ */

#define VPU_H1_SWREG172_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG172_BF_0_SHIFT               (0U)
/*! BF_0 - VP8 deadzone lookup table */
#define VPU_H1_SWREG172_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG172_BF_0_SHIFT)) & VPU_H1_SWREG172_BF_0_MASK)
/*! @} */

/*! @name SWREG173 - VPU H1 Register 173 */
/*! @{ */

#define VPU_H1_SWREG173_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG173_BF_0_SHIFT               (0U)
/*! BF_0 - VP8 deadzone lookup table */
#define VPU_H1_SWREG173_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG173_BF_0_SHIFT)) & VPU_H1_SWREG173_BF_0_MASK)
/*! @} */

/*! @name SWREG174 - VPU H1 Register 174 */
/*! @{ */

#define VPU_H1_SWREG174_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG174_BF_0_SHIFT               (0U)
/*! BF_0 - VP8 deadzone lookup table */
#define VPU_H1_SWREG174_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG174_BF_0_SHIFT)) & VPU_H1_SWREG174_BF_0_MASK)
/*! @} */

/*! @name SWREG175 - VPU H1 Register 175 */
/*! @{ */

#define VPU_H1_SWREG175_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG175_BF_0_SHIFT               (0U)
/*! BF_0 - VP8 deadzone lookup table */
#define VPU_H1_SWREG175_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG175_BF_0_SHIFT)) & VPU_H1_SWREG175_BF_0_MASK)
/*! @} */

/*! @name SWREG176 - VPU H1 Register 176 */
/*! @{ */

#define VPU_H1_SWREG176_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG176_BF_0_SHIFT               (0U)
/*! BF_0 - VP8 deadzone lookup table */
#define VPU_H1_SWREG176_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG176_BF_0_SHIFT)) & VPU_H1_SWREG176_BF_0_MASK)
/*! @} */

/*! @name SWREG177 - VPU H1 Register 177 */
/*! @{ */

#define VPU_H1_SWREG177_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG177_BF_0_SHIFT               (0U)
/*! BF_0 - VP8 deadzone lookup table */
#define VPU_H1_SWREG177_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG177_BF_0_SHIFT)) & VPU_H1_SWREG177_BF_0_MASK)
/*! @} */

/*! @name SWREG178 - VPU H1 Register 178 */
/*! @{ */

#define VPU_H1_SWREG178_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG178_BF_0_SHIFT               (0U)
/*! BF_0 - VP8 deadzone lookup table */
#define VPU_H1_SWREG178_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG178_BF_0_SHIFT)) & VPU_H1_SWREG178_BF_0_MASK)
/*! @} */

/*! @name SWREG179 - VPU H1 Register 179 */
/*! @{ */

#define VPU_H1_SWREG179_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG179_BF_0_SHIFT               (0U)
/*! BF_0 - VP8 deadzone lookup table */
#define VPU_H1_SWREG179_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG179_BF_0_SHIFT)) & VPU_H1_SWREG179_BF_0_MASK)
/*! @} */

/*! @name SWREG180 - VPU H1 Register 180 */
/*! @{ */

#define VPU_H1_SWREG180_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG180_BF_0_SHIFT               (0U)
/*! BF_0 - VP8 deadzone lookup table */
#define VPU_H1_SWREG180_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG180_BF_0_SHIFT)) & VPU_H1_SWREG180_BF_0_MASK)
/*! @} */

/*! @name SWREG181 - VPU H1 Register 181 */
/*! @{ */

#define VPU_H1_SWREG181_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG181_BF_0_SHIFT               (0U)
/*! BF_0 - VP8 deadzone lookup table */
#define VPU_H1_SWREG181_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG181_BF_0_SHIFT)) & VPU_H1_SWREG181_BF_0_MASK)
/*! @} */

/*! @name SWREG182 - VPU H1 Register 182 */
/*! @{ */

#define VPU_H1_SWREG182_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG182_BF_0_SHIFT               (0U)
/*! BF_0 - VP8 deadzone lookup table */
#define VPU_H1_SWREG182_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG182_BF_0_SHIFT)) & VPU_H1_SWREG182_BF_0_MASK)
/*! @} */

/*! @name SWREG183 - VPU H1 Register 183 */
/*! @{ */

#define VPU_H1_SWREG183_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG183_BF_0_SHIFT               (0U)
/*! BF_0 - VP8 deadzone lookup table */
#define VPU_H1_SWREG183_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG183_BF_0_SHIFT)) & VPU_H1_SWREG183_BF_0_MASK)
/*! @} */

/*! @name SWREG184 - VPU H1 Register 184 */
/*! @{ */

#define VPU_H1_SWREG184_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG184_BF_0_SHIFT               (0U)
/*! BF_0 - VP8 deadzone lookup table */
#define VPU_H1_SWREG184_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG184_BF_0_SHIFT)) & VPU_H1_SWREG184_BF_0_MASK)
/*! @} */

/*! @name SWREG185 - VPU H1 Register 185 */
/*! @{ */

#define VPU_H1_SWREG185_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG185_BF_0_SHIFT               (0U)
/*! BF_0 - VP8 deadzone lookup table */
#define VPU_H1_SWREG185_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG185_BF_0_SHIFT)) & VPU_H1_SWREG185_BF_0_MASK)
/*! @} */

/*! @name SWREG186 - VPU H1 Register 186 */
/*! @{ */

#define VPU_H1_SWREG186_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG186_BF_0_SHIFT               (0U)
/*! BF_0 - VP8 deadzone lookup table */
#define VPU_H1_SWREG186_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG186_BF_0_SHIFT)) & VPU_H1_SWREG186_BF_0_MASK)
/*! @} */

/*! @name SWREG187 - VPU H1 Register 187 */
/*! @{ */

#define VPU_H1_SWREG187_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG187_BF_0_SHIFT               (0U)
/*! BF_0 - VP8 deadzone lookup table */
#define VPU_H1_SWREG187_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG187_BF_0_SHIFT)) & VPU_H1_SWREG187_BF_0_MASK)
/*! @} */

/*! @name SWREG188 - VPU H1 Register 188 */
/*! @{ */

#define VPU_H1_SWREG188_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG188_BF_0_SHIFT               (0U)
/*! BF_0 - VP8 deadzone lookup table */
#define VPU_H1_SWREG188_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG188_BF_0_SHIFT)) & VPU_H1_SWREG188_BF_0_MASK)
/*! @} */

/*! @name SWREG189 - VPU H1 Register 189 */
/*! @{ */

#define VPU_H1_SWREG189_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG189_BF_0_SHIFT               (0U)
/*! BF_0 - VP8 deadzone lookup table */
#define VPU_H1_SWREG189_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG189_BF_0_SHIFT)) & VPU_H1_SWREG189_BF_0_MASK)
/*! @} */

/*! @name SWREG190 - VPU H1 Register 190 */
/*! @{ */

#define VPU_H1_SWREG190_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG190_BF_0_SHIFT               (0U)
/*! BF_0 - VP8 deadzone lookup table */
#define VPU_H1_SWREG190_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG190_BF_0_SHIFT)) & VPU_H1_SWREG190_BF_0_MASK)
/*! @} */

/*! @name SWREG191 - VPU H1 Register 191 */
/*! @{ */

#define VPU_H1_SWREG191_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG191_BF_0_SHIFT               (0U)
/*! BF_0 - VP8 deadzone lookup table */
#define VPU_H1_SWREG191_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG191_BF_0_SHIFT)) & VPU_H1_SWREG191_BF_0_MASK)
/*! @} */

/*! @name SWREG192 - VPU H1 Register 192 */
/*! @{ */

#define VPU_H1_SWREG192_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG192_BF_0_SHIFT               (0U)
/*! BF_0 - VP8 deadzone lookup table */
#define VPU_H1_SWREG192_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG192_BF_0_SHIFT)) & VPU_H1_SWREG192_BF_0_MASK)
/*! @} */

/*! @name SWREG193 - VPU H1 Register 193 */
/*! @{ */

#define VPU_H1_SWREG193_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG193_BF_0_SHIFT               (0U)
/*! BF_0 - VP8 deadzone lookup table */
#define VPU_H1_SWREG193_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG193_BF_0_SHIFT)) & VPU_H1_SWREG193_BF_0_MASK)
/*! @} */

/*! @name SWREG194 - VPU H1 Register 194 */
/*! @{ */

#define VPU_H1_SWREG194_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG194_BF_0_SHIFT               (0U)
/*! BF_0 - VP8 deadzone lookup table */
#define VPU_H1_SWREG194_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG194_BF_0_SHIFT)) & VPU_H1_SWREG194_BF_0_MASK)
/*! @} */

/*! @name SWREG195 - VPU H1 Register 195 */
/*! @{ */

#define VPU_H1_SWREG195_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG195_BF_0_SHIFT               (0U)
/*! BF_0 - VP8 deadzone lookup table */
#define VPU_H1_SWREG195_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG195_BF_0_SHIFT)) & VPU_H1_SWREG195_BF_0_MASK)
/*! @} */

/*! @name SWREG196 - VPU H1 Register 196 */
/*! @{ */

#define VPU_H1_SWREG196_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG196_BF_0_SHIFT               (0U)
/*! BF_0 - VP8 deadzone lookup table */
#define VPU_H1_SWREG196_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG196_BF_0_SHIFT)) & VPU_H1_SWREG196_BF_0_MASK)
/*! @} */

/*! @name SWREG197 - VPU H1 Register 197 */
/*! @{ */

#define VPU_H1_SWREG197_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG197_BF_0_SHIFT               (0U)
/*! BF_0 - VP8 deadzone lookup table */
#define VPU_H1_SWREG197_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG197_BF_0_SHIFT)) & VPU_H1_SWREG197_BF_0_MASK)
/*! @} */

/*! @name SWREG198 - VPU H1 Register 198 */
/*! @{ */

#define VPU_H1_SWREG198_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG198_BF_0_SHIFT               (0U)
/*! BF_0 - VP8 deadzone lookup table */
#define VPU_H1_SWREG198_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG198_BF_0_SHIFT)) & VPU_H1_SWREG198_BF_0_MASK)
/*! @} */

/*! @name SWREG199 - VPU H1 Register 199 */
/*! @{ */

#define VPU_H1_SWREG199_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG199_BF_0_SHIFT               (0U)
/*! BF_0 - VP8 deadzone lookup table */
#define VPU_H1_SWREG199_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG199_BF_0_SHIFT)) & VPU_H1_SWREG199_BF_0_MASK)
/*! @} */

/*! @name SWREG200 - VPU H1 Register 200 */
/*! @{ */

#define VPU_H1_SWREG200_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG200_BF_0_SHIFT               (0U)
/*! BF_0 - VP8 deadzone lookup table */
#define VPU_H1_SWREG200_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG200_BF_0_SHIFT)) & VPU_H1_SWREG200_BF_0_MASK)
/*! @} */

/*! @name SWREG201 - VPU H1 Register 201 */
/*! @{ */

#define VPU_H1_SWREG201_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG201_BF_0_SHIFT               (0U)
/*! BF_0 - VP8 deadzone lookup table */
#define VPU_H1_SWREG201_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG201_BF_0_SHIFT)) & VPU_H1_SWREG201_BF_0_MASK)
/*! @} */

/*! @name SWREG202 - VPU H1 Register 202 */
/*! @{ */

#define VPU_H1_SWREG202_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG202_BF_0_SHIFT               (0U)
/*! BF_0 - VP8 deadzone lookup table */
#define VPU_H1_SWREG202_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG202_BF_0_SHIFT)) & VPU_H1_SWREG202_BF_0_MASK)
/*! @} */

/*! @name SWREG203 - VPU H1 Register 203 */
/*! @{ */

#define VPU_H1_SWREG203_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG203_BF_0_SHIFT               (0U)
/*! BF_0 - VP8 deadzone lookup table */
#define VPU_H1_SWREG203_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG203_BF_0_SHIFT)) & VPU_H1_SWREG203_BF_0_MASK)
/*! @} */

/*! @name SWREG204 - VPU H1 Register 204 */
/*! @{ */

#define VPU_H1_SWREG204_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG204_BF_0_SHIFT               (0U)
/*! BF_0 - VP8 deadzone lookup table */
#define VPU_H1_SWREG204_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG204_BF_0_SHIFT)) & VPU_H1_SWREG204_BF_0_MASK)
/*! @} */

/*! @name SWREG205 - VPU H1 Register 205 */
/*! @{ */

#define VPU_H1_SWREG205_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG205_BF_0_SHIFT               (0U)
/*! BF_0 - VP8 deadzone lookup table */
#define VPU_H1_SWREG205_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG205_BF_0_SHIFT)) & VPU_H1_SWREG205_BF_0_MASK)
/*! @} */

/*! @name SWREG206 - VPU H1 Register 206 */
/*! @{ */

#define VPU_H1_SWREG206_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG206_BF_0_SHIFT               (0U)
/*! BF_0 - VP8 deadzone lookup table */
#define VPU_H1_SWREG206_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG206_BF_0_SHIFT)) & VPU_H1_SWREG206_BF_0_MASK)
/*! @} */

/*! @name SWREG207 - VPU H1 Register 207 */
/*! @{ */

#define VPU_H1_SWREG207_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG207_BF_0_SHIFT               (0U)
/*! BF_0 - VP8 deadzone lookup table */
#define VPU_H1_SWREG207_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG207_BF_0_SHIFT)) & VPU_H1_SWREG207_BF_0_MASK)
/*! @} */

/*! @name SWREG208 - VPU H1 Register 208 */
/*! @{ */

#define VPU_H1_SWREG208_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG208_BF_0_SHIFT               (0U)
/*! BF_0 - VP8 deadzone lookup table */
#define VPU_H1_SWREG208_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG208_BF_0_SHIFT)) & VPU_H1_SWREG208_BF_0_MASK)
/*! @} */

/*! @name SWREG209 - VPU H1 Register 209 */
/*! @{ */

#define VPU_H1_SWREG209_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG209_BF_0_SHIFT               (0U)
/*! BF_0 - VP8 deadzone lookup table */
#define VPU_H1_SWREG209_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG209_BF_0_SHIFT)) & VPU_H1_SWREG209_BF_0_MASK)
/*! @} */

/*! @name SWREG210 - VPU H1 Register 210 */
/*! @{ */

#define VPU_H1_SWREG210_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG210_BF_0_SHIFT               (0U)
/*! BF_0 - VP8 deadzone lookup table */
#define VPU_H1_SWREG210_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG210_BF_0_SHIFT)) & VPU_H1_SWREG210_BF_0_MASK)
/*! @} */

/*! @name SWREG211 - VPU H1 Register 211 */
/*! @{ */

#define VPU_H1_SWREG211_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG211_BF_0_SHIFT               (0U)
/*! BF_0 - VP8 deadzone lookup table */
#define VPU_H1_SWREG211_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG211_BF_0_SHIFT)) & VPU_H1_SWREG211_BF_0_MASK)
/*! @} */

/*! @name SWREG212 - VPU H1 Register 212 */
/*! @{ */

#define VPU_H1_SWREG212_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG212_BF_0_SHIFT               (0U)
/*! BF_0 - VP8 deadzone lookup table */
#define VPU_H1_SWREG212_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG212_BF_0_SHIFT)) & VPU_H1_SWREG212_BF_0_MASK)
/*! @} */

/*! @name SWREG213 - VPU H1 Register 213 */
/*! @{ */

#define VPU_H1_SWREG213_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG213_BF_0_SHIFT               (0U)
/*! BF_0 - VP8 deadzone lookup table */
#define VPU_H1_SWREG213_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG213_BF_0_SHIFT)) & VPU_H1_SWREG213_BF_0_MASK)
/*! @} */

/*! @name SWREG214 - VPU H1 Register 214 */
/*! @{ */

#define VPU_H1_SWREG214_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG214_BF_0_SHIFT               (0U)
/*! BF_0 - VP8 deadzone lookup table */
#define VPU_H1_SWREG214_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG214_BF_0_SHIFT)) & VPU_H1_SWREG214_BF_0_MASK)
/*! @} */

/*! @name SWREG215 - VPU H1 Register 215 */
/*! @{ */

#define VPU_H1_SWREG215_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG215_BF_0_SHIFT               (0U)
/*! BF_0 - VP8 deadzone lookup table */
#define VPU_H1_SWREG215_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG215_BF_0_SHIFT)) & VPU_H1_SWREG215_BF_0_MASK)
/*! @} */

/*! @name SWREG216 - VPU H1 Register 216 */
/*! @{ */

#define VPU_H1_SWREG216_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG216_BF_0_SHIFT               (0U)
/*! BF_0 - VP8 deadzone lookup table */
#define VPU_H1_SWREG216_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG216_BF_0_SHIFT)) & VPU_H1_SWREG216_BF_0_MASK)
/*! @} */

/*! @name SWREG217 - VPU H1 Register 217 */
/*! @{ */

#define VPU_H1_SWREG217_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG217_BF_0_SHIFT               (0U)
/*! BF_0 - VP8 deadzone lookup table */
#define VPU_H1_SWREG217_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG217_BF_0_SHIFT)) & VPU_H1_SWREG217_BF_0_MASK)
/*! @} */

/*! @name SWREG218 - VPU H1 Register 218 */
/*! @{ */

#define VPU_H1_SWREG218_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG218_BF_0_SHIFT               (0U)
/*! BF_0 - VP8 deadzone lookup table */
#define VPU_H1_SWREG218_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG218_BF_0_SHIFT)) & VPU_H1_SWREG218_BF_0_MASK)
/*! @} */

/*! @name SWREG219 - VPU H1 Register 219 */
/*! @{ */

#define VPU_H1_SWREG219_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG219_BF_0_SHIFT               (0U)
/*! BF_0 - VP8 deadzone lookup table */
#define VPU_H1_SWREG219_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG219_BF_0_SHIFT)) & VPU_H1_SWREG219_BF_0_MASK)
/*! @} */

/*! @name SWREG220 - VPU H1 Register 220 */
/*! @{ */

#define VPU_H1_SWREG220_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG220_BF_0_SHIFT               (0U)
/*! BF_0 - VP8 deadzone lookup table */
#define VPU_H1_SWREG220_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG220_BF_0_SHIFT)) & VPU_H1_SWREG220_BF_0_MASK)
/*! @} */

/*! @name SWREG221 - VPU H1 Register 221 */
/*! @{ */

#define VPU_H1_SWREG221_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG221_BF_0_SHIFT               (0U)
/*! BF_0 - VP8 deadzone lookup table */
#define VPU_H1_SWREG221_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG221_BF_0_SHIFT)) & VPU_H1_SWREG221_BF_0_MASK)
/*! @} */

/*! @name SWREG222 - VPU H1 Register 222 */
/*! @{ */

#define VPU_H1_SWREG222_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG222_BF_0_SHIFT               (0U)
/*! BF_0 - VP8 deadzone lookup table */
#define VPU_H1_SWREG222_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG222_BF_0_SHIFT)) & VPU_H1_SWREG222_BF_0_MASK)
/*! @} */

/*! @name SWREG223 - VPU H1 Register 223 */
/*! @{ */

#define VPU_H1_SWREG223_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG223_BF_0_SHIFT               (0U)
/*! BF_0 - VP8 deadzone lookup table */
#define VPU_H1_SWREG223_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG223_BF_0_SHIFT)) & VPU_H1_SWREG223_BF_0_MASK)
/*! @} */

/*! @name SWREG224 - VPU H1 Register 224 */
/*! @{ */

#define VPU_H1_SWREG224_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG224_BF_0_SHIFT               (0U)
/*! BF_0 - VP8 deadzone lookup table */
#define VPU_H1_SWREG224_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG224_BF_0_SHIFT)) & VPU_H1_SWREG224_BF_0_MASK)
/*! @} */

/*! @name SWREG225 - VPU H1 Register 225 */
/*! @{ */

#define VPU_H1_SWREG225_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG225_BF_0_SHIFT               (0U)
/*! BF_0 - VP8 deadzone lookup table */
#define VPU_H1_SWREG225_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG225_BF_0_SHIFT)) & VPU_H1_SWREG225_BF_0_MASK)
/*! @} */

/*! @name SWREG226 - VPU H1 Register 226 */
/*! @{ */

#define VPU_H1_SWREG226_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG226_BF_0_SHIFT               (0U)
/*! BF_0 - VP8 deadzone lookup table */
#define VPU_H1_SWREG226_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG226_BF_0_SHIFT)) & VPU_H1_SWREG226_BF_0_MASK)
/*! @} */

/*! @name SWREG227 - VPU H1 Register 227 */
/*! @{ */

#define VPU_H1_SWREG227_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG227_BF_0_SHIFT               (0U)
/*! BF_0 - VP8 deadzone lookup table */
#define VPU_H1_SWREG227_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG227_BF_0_SHIFT)) & VPU_H1_SWREG227_BF_0_MASK)
/*! @} */

/*! @name SWREG228 - VPU H1 Register 228 */
/*! @{ */

#define VPU_H1_SWREG228_BF_0_MASK                (0x3FFFU)
#define VPU_H1_SWREG228_BF_0_SHIFT               (0U)
/*! BF_0 - VP8 deadzone rate multiplier for plane 1 */
#define VPU_H1_SWREG228_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG228_BF_0_SHIFT)) & VPU_H1_SWREG228_BF_0_MASK)

#define VPU_H1_SWREG228_BF_16_MASK               (0x3FFF0000U)
#define VPU_H1_SWREG228_BF_16_SHIFT              (16U)
/*! BF_16 - VP8 deadzone rate multiplier for plane 0 */
#define VPU_H1_SWREG228_BF_16(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG228_BF_16_SHIFT)) & VPU_H1_SWREG228_BF_16_MASK)
/*! @} */

/*! @name SWREG229 - VPU H1 Register 229 */
/*! @{ */

#define VPU_H1_SWREG229_BF_0_MASK                (0x3FFFU)
#define VPU_H1_SWREG229_BF_0_SHIFT               (0U)
/*! BF_0 - VP8 deadzone rate multiplier for plane 3 */
#define VPU_H1_SWREG229_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG229_BF_0_SHIFT)) & VPU_H1_SWREG229_BF_0_MASK)

#define VPU_H1_SWREG229_BF_16_MASK               (0x3FFF0000U)
#define VPU_H1_SWREG229_BF_16_SHIFT              (16U)
/*! BF_16 - VP8 deadzone rate multiplier for plane 2 */
#define VPU_H1_SWREG229_BF_16(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG229_BF_16_SHIFT)) & VPU_H1_SWREG229_BF_16_MASK)
/*! @} */

/*! @name SWREG230 - VPU H1 Register 230 */
/*! @{ */

#define VPU_H1_SWREG230_BF_0_MASK                (0x3FFU)
#define VPU_H1_SWREG230_BF_0_SHIFT               (0U)
/*! BF_0 - VP8 deadzone rate for macroblock skip token 1 */
#define VPU_H1_SWREG230_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG230_BF_0_SHIFT)) & VPU_H1_SWREG230_BF_0_MASK)

#define VPU_H1_SWREG230_BF_12_MASK               (0x3FF000U)
#define VPU_H1_SWREG230_BF_12_SHIFT              (12U)
/*! BF_12 - VP8 deadzone rate for macroblock skip token 0 */
#define VPU_H1_SWREG230_BF_12(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG230_BF_12_SHIFT)) & VPU_H1_SWREG230_BF_12_MASK)
/*! @} */

/*! @name SWREG231 - VPU H1 Register 231 */
/*! @{ */

#define VPU_H1_SWREG231_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG231_BF_0_SHIFT               (0U)
/*! BF_0 - Base address for output of down-scaled encoder image in YUYV 4:2:2 format */
#define VPU_H1_SWREG231_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG231_BF_0_SHIFT)) & VPU_H1_SWREG231_BF_0_MASK)
/*! @} */

/*! @name SWREG232 - VPU H1 Register 232 */
/*! @{ */

#define VPU_H1_SWREG232_BF_0_MASK                (0x1FFFFU)
#define VPU_H1_SWREG232_BF_0_SHIFT               (0U)
/*! BF_0 - Scaling ratio for width of down-scaled image. Fixed point integer 1.16. */
#define VPU_H1_SWREG232_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG232_BF_0_SHIFT)) & VPU_H1_SWREG232_BF_0_MASK)

#define VPU_H1_SWREG232_BF_17_MASK               (0x1FFE0000U)
#define VPU_H1_SWREG232_BF_17_SHIFT              (17U)
/*! BF_17 - Scaling width of down-scaled image. ScaledWidth. [96..4076] */
#define VPU_H1_SWREG232_BF_17(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG232_BF_17_SHIFT)) & VPU_H1_SWREG232_BF_17_MASK)

#define VPU_H1_SWREG232_BF_30_MASK               (0xC0000000U)
#define VPU_H1_SWREG232_BF_30_SHIFT              (30U)
/*! BF_30 - Scaling mode. ScalingMode. */
#define VPU_H1_SWREG232_BF_30(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG232_BF_30_SHIFT)) & VPU_H1_SWREG232_BF_30_MASK)
/*! @} */

/*! @name SWREG233 - VPU H1 Register 233 */
/*! @{ */

#define VPU_H1_SWREG233_BF_0_MASK                (0x1FFFFU)
#define VPU_H1_SWREG233_BF_0_SHIFT               (0U)
/*! BF_0 - Scaling ratio for height of down-scaled image. Fixed point integer 1.16. */
#define VPU_H1_SWREG233_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG233_BF_0_SHIFT)) & VPU_H1_SWREG233_BF_0_MASK)

#define VPU_H1_SWREG233_BF_17_MASK               (0x1FFE0000U)
#define VPU_H1_SWREG233_BF_17_SHIFT              (17U)
/*! BF_17 - Scaling width of down-scaled image. ScaledHeight. [2..4078] */
#define VPU_H1_SWREG233_BF_17(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG233_BF_17_SHIFT)) & VPU_H1_SWREG233_BF_17_MASK)
/*! @} */

/*! @name SWREG236 - VPU H1 Register 236 */
/*! @{ */

#define VPU_H1_SWREG236_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG236_BF_0_SHIFT               (0U)
/*! BF_0 - Squared error output calculated for 13x13 pixels per macroblock. 32-bit max */
#define VPU_H1_SWREG236_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG236_BF_0_SHIFT)) & VPU_H1_SWREG236_BF_0_MASK)
/*! @} */

/*! @name SWREG237 - VPU H1 Register 237 */
/*! @{ */

#define VPU_H1_SWREG237_BF_0_MASK                (0xFFFFU)
#define VPU_H1_SWREG237_BF_0_SHIFT               (0U)
/*! BF_0 - Macroblock count with MAD value under threshold output */
#define VPU_H1_SWREG237_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG237_BF_0_SHIFT)) & VPU_H1_SWREG237_BF_0_MASK)

#define VPU_H1_SWREG237_BF_16_MASK               (0xFF0000U)
#define VPU_H1_SWREG237_BF_16_SHIFT              (16U)
/*! BF_16 - MAD based QP adjustment. madQpChange [-127..127] */
#define VPU_H1_SWREG237_BF_16(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG237_BF_16_SHIFT)) & VPU_H1_SWREG237_BF_16_MASK)

#define VPU_H1_SWREG237_BF_24_MASK               (0x3F000000U)
#define VPU_H1_SWREG237_BF_24_SHIFT              (24U)
/*! BF_24 - MAD threshold div256. MadThreshold2 < MadThreshold */
#define VPU_H1_SWREG237_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG237_BF_24_SHIFT)) & VPU_H1_SWREG237_BF_24_MASK)
/*! @} */

/*! @name SWREG238 - VPU H1 Register 238 */
/*! @{ */

#define VPU_H1_SWREG238_BF_0_MASK                (0xFFFFU)
#define VPU_H1_SWREG238_BF_0_SHIFT               (0U)
/*! BF_0 - Macroblock count with MAD value under threshold output */
#define VPU_H1_SWREG238_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG238_BF_0_SHIFT)) & VPU_H1_SWREG238_BF_0_MASK)

#define VPU_H1_SWREG238_BF_16_MASK               (0xFF0000U)
#define VPU_H1_SWREG238_BF_16_SHIFT              (16U)
/*! BF_16 - MAD based QP adjustment. madQpChange [-127..127] */
#define VPU_H1_SWREG238_BF_16(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG238_BF_16_SHIFT)) & VPU_H1_SWREG238_BF_16_MASK)

#define VPU_H1_SWREG238_BF_24_MASK               (0x3F000000U)
#define VPU_H1_SWREG238_BF_24_SHIFT              (24U)
/*! BF_24 - MAD threshold div256. MadThreshold3 < MadThreshold2 */
#define VPU_H1_SWREG238_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG238_BF_24_SHIFT)) & VPU_H1_SWREG238_BF_24_MASK)
/*! @} */

/*! @name SWREG239 - VPU H1 Register 239 */
/*! @{ */

#define VPU_H1_SWREG239_BF_0_MASK                (0x7U)
#define VPU_H1_SWREG239_BF_0_SHIFT               (0U)
/*! BF_0 - VP8 predictor interpolation coefficient for full pixel position tap=6 */
#define VPU_H1_SWREG239_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG239_BF_0_SHIFT)) & VPU_H1_SWREG239_BF_0_MASK)

#define VPU_H1_SWREG239_BF_3_MASK                (0xF8U)
#define VPU_H1_SWREG239_BF_3_SHIFT               (3U)
/*! BF_3 - VP8 predictor interpolation coefficient for full pixel position tap=5 */
#define VPU_H1_SWREG239_BF_3(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG239_BF_3_SHIFT)) & VPU_H1_SWREG239_BF_3_MASK)

#define VPU_H1_SWREG239_BF_8_MASK                (0xFF00U)
#define VPU_H1_SWREG239_BF_8_SHIFT               (8U)
/*! BF_8 - VP8 predictor interpolation coefficient for full pixel position tap=4 */
#define VPU_H1_SWREG239_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG239_BF_8_SHIFT)) & VPU_H1_SWREG239_BF_8_MASK)

#define VPU_H1_SWREG239_BF_16_MASK               (0xFF0000U)
#define VPU_H1_SWREG239_BF_16_SHIFT              (16U)
/*! BF_16 - VP8 predictor interpolation coefficient for full pixel position tap=3 */
#define VPU_H1_SWREG239_BF_16(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG239_BF_16_SHIFT)) & VPU_H1_SWREG239_BF_16_MASK)

#define VPU_H1_SWREG239_BF_24_MASK               (0x1F000000U)
#define VPU_H1_SWREG239_BF_24_SHIFT              (24U)
/*! BF_24 - VP8 predictor interpolation coefficient for full pixel position tap=2 */
#define VPU_H1_SWREG239_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG239_BF_24_SHIFT)) & VPU_H1_SWREG239_BF_24_MASK)

#define VPU_H1_SWREG239_BF_29_MASK               (0xE0000000U)
#define VPU_H1_SWREG239_BF_29_SHIFT              (29U)
/*! BF_29 - VP8 predictor interpolation coefficient for full pixel position tap=1 */
#define VPU_H1_SWREG239_BF_29(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG239_BF_29_SHIFT)) & VPU_H1_SWREG239_BF_29_MASK)
/*! @} */

/*! @name SWREG240 - VPU H1 Register 240 */
/*! @{ */

#define VPU_H1_SWREG240_BF_0_MASK                (0x7U)
#define VPU_H1_SWREG240_BF_0_SHIFT               (0U)
/*! BF_0 - VP8 predictor interpolation coefficient for 1/8 pixel position tap=6 */
#define VPU_H1_SWREG240_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG240_BF_0_SHIFT)) & VPU_H1_SWREG240_BF_0_MASK)

#define VPU_H1_SWREG240_BF_3_MASK                (0xF8U)
#define VPU_H1_SWREG240_BF_3_SHIFT               (3U)
/*! BF_3 - VP8 predictor interpolation coefficient for 1/8 pixel position tap=5 */
#define VPU_H1_SWREG240_BF_3(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG240_BF_3_SHIFT)) & VPU_H1_SWREG240_BF_3_MASK)

#define VPU_H1_SWREG240_BF_8_MASK                (0xFF00U)
#define VPU_H1_SWREG240_BF_8_SHIFT               (8U)
/*! BF_8 - VP8 predictor interpolation coefficient for 1/8 pixel position tap=4 */
#define VPU_H1_SWREG240_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG240_BF_8_SHIFT)) & VPU_H1_SWREG240_BF_8_MASK)

#define VPU_H1_SWREG240_BF_16_MASK               (0xFF0000U)
#define VPU_H1_SWREG240_BF_16_SHIFT              (16U)
/*! BF_16 - VP8 predictor interpolation coefficient for 1/8 pixel position tap=3 */
#define VPU_H1_SWREG240_BF_16(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG240_BF_16_SHIFT)) & VPU_H1_SWREG240_BF_16_MASK)

#define VPU_H1_SWREG240_BF_24_MASK               (0x1F000000U)
#define VPU_H1_SWREG240_BF_24_SHIFT              (24U)
/*! BF_24 - VP8 predictor interpolation coefficient for 1/8 pixel position tap=2 */
#define VPU_H1_SWREG240_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG240_BF_24_SHIFT)) & VPU_H1_SWREG240_BF_24_MASK)

#define VPU_H1_SWREG240_BF_29_MASK               (0xE0000000U)
#define VPU_H1_SWREG240_BF_29_SHIFT              (29U)
/*! BF_29 - VP8 predictor interpolation coefficient for 1/8 pixel position tap=1 */
#define VPU_H1_SWREG240_BF_29(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG240_BF_29_SHIFT)) & VPU_H1_SWREG240_BF_29_MASK)
/*! @} */

/*! @name SWREG241 - VPU H1 Register 241 */
/*! @{ */

#define VPU_H1_SWREG241_BF_0_MASK                (0x7U)
#define VPU_H1_SWREG241_BF_0_SHIFT               (0U)
/*! BF_0 - VP8 predictor interpolation coefficient for 2/8 pixel position tap=6 */
#define VPU_H1_SWREG241_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG241_BF_0_SHIFT)) & VPU_H1_SWREG241_BF_0_MASK)

#define VPU_H1_SWREG241_BF_3_MASK                (0xF8U)
#define VPU_H1_SWREG241_BF_3_SHIFT               (3U)
/*! BF_3 - VP8 predictor interpolation coefficient for 2/8 pixel position tap=5 */
#define VPU_H1_SWREG241_BF_3(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG241_BF_3_SHIFT)) & VPU_H1_SWREG241_BF_3_MASK)

#define VPU_H1_SWREG241_BF_8_MASK                (0xFF00U)
#define VPU_H1_SWREG241_BF_8_SHIFT               (8U)
/*! BF_8 - VP8 predictor interpolation coefficient for 2/8 pixel position tap=4 */
#define VPU_H1_SWREG241_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG241_BF_8_SHIFT)) & VPU_H1_SWREG241_BF_8_MASK)

#define VPU_H1_SWREG241_BF_16_MASK               (0xFF0000U)
#define VPU_H1_SWREG241_BF_16_SHIFT              (16U)
/*! BF_16 - VP8 predictor interpolation coefficient for 2/8 pixel position tap=3 */
#define VPU_H1_SWREG241_BF_16(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG241_BF_16_SHIFT)) & VPU_H1_SWREG241_BF_16_MASK)

#define VPU_H1_SWREG241_BF_24_MASK               (0x1F000000U)
#define VPU_H1_SWREG241_BF_24_SHIFT              (24U)
/*! BF_24 - VP8 predictor interpolation coefficient for 2/8 pixel position tap=2 */
#define VPU_H1_SWREG241_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG241_BF_24_SHIFT)) & VPU_H1_SWREG241_BF_24_MASK)

#define VPU_H1_SWREG241_BF_29_MASK               (0xE0000000U)
#define VPU_H1_SWREG241_BF_29_SHIFT              (29U)
/*! BF_29 - VP8 predictor interpolation coefficient for 2/8 pixel position tap=1 */
#define VPU_H1_SWREG241_BF_29(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG241_BF_29_SHIFT)) & VPU_H1_SWREG241_BF_29_MASK)
/*! @} */

/*! @name SWREG242 - VPU H1 Register 242 */
/*! @{ */

#define VPU_H1_SWREG242_BF_0_MASK                (0x7U)
#define VPU_H1_SWREG242_BF_0_SHIFT               (0U)
/*! BF_0 - VP8 predictor interpolation coefficient for 3/8 pixel position tap=6 */
#define VPU_H1_SWREG242_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG242_BF_0_SHIFT)) & VPU_H1_SWREG242_BF_0_MASK)

#define VPU_H1_SWREG242_BF_3_MASK                (0xF8U)
#define VPU_H1_SWREG242_BF_3_SHIFT               (3U)
/*! BF_3 - VP8 predictor interpolation coefficient for 3/8 pixel position tap=5 */
#define VPU_H1_SWREG242_BF_3(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG242_BF_3_SHIFT)) & VPU_H1_SWREG242_BF_3_MASK)

#define VPU_H1_SWREG242_BF_8_MASK                (0xFF00U)
#define VPU_H1_SWREG242_BF_8_SHIFT               (8U)
/*! BF_8 - VP8 predictor interpolation coefficient for 3/8 pixel position tap=4 */
#define VPU_H1_SWREG242_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG242_BF_8_SHIFT)) & VPU_H1_SWREG242_BF_8_MASK)

#define VPU_H1_SWREG242_BF_16_MASK               (0xFF0000U)
#define VPU_H1_SWREG242_BF_16_SHIFT              (16U)
/*! BF_16 - VP8 predictor interpolation coefficient for 3/8 pixel position tap=3 */
#define VPU_H1_SWREG242_BF_16(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG242_BF_16_SHIFT)) & VPU_H1_SWREG242_BF_16_MASK)

#define VPU_H1_SWREG242_BF_24_MASK               (0x1F000000U)
#define VPU_H1_SWREG242_BF_24_SHIFT              (24U)
/*! BF_24 - VP8 predictor interpolation coefficient for 3/8 pixel position tap=2 */
#define VPU_H1_SWREG242_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG242_BF_24_SHIFT)) & VPU_H1_SWREG242_BF_24_MASK)

#define VPU_H1_SWREG242_BF_29_MASK               (0xE0000000U)
#define VPU_H1_SWREG242_BF_29_SHIFT              (29U)
/*! BF_29 - VP8 predictor interpolation coefficient for 3/8 pixel position tap=1 */
#define VPU_H1_SWREG242_BF_29(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG242_BF_29_SHIFT)) & VPU_H1_SWREG242_BF_29_MASK)
/*! @} */

/*! @name SWREG243 - VPU H1 Register 243 */
/*! @{ */

#define VPU_H1_SWREG243_BF_0_MASK                (0x7U)
#define VPU_H1_SWREG243_BF_0_SHIFT               (0U)
/*! BF_0 - VP8 predictor interpolation coefficient for 4/8 pixel position tap=6 */
#define VPU_H1_SWREG243_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG243_BF_0_SHIFT)) & VPU_H1_SWREG243_BF_0_MASK)

#define VPU_H1_SWREG243_BF_3_MASK                (0xF8U)
#define VPU_H1_SWREG243_BF_3_SHIFT               (3U)
/*! BF_3 - VP8 predictor interpolation coefficient for 4/8 pixel position tap=5 */
#define VPU_H1_SWREG243_BF_3(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG243_BF_3_SHIFT)) & VPU_H1_SWREG243_BF_3_MASK)

#define VPU_H1_SWREG243_BF_8_MASK                (0xFF00U)
#define VPU_H1_SWREG243_BF_8_SHIFT               (8U)
/*! BF_8 - VP8 predictor interpolation coefficient for 4/8 pixel position tap=4 */
#define VPU_H1_SWREG243_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG243_BF_8_SHIFT)) & VPU_H1_SWREG243_BF_8_MASK)

#define VPU_H1_SWREG243_BF_16_MASK               (0xFF0000U)
#define VPU_H1_SWREG243_BF_16_SHIFT              (16U)
/*! BF_16 - VP8 predictor interpolation coefficient for 4/8 pixel position tap=3 */
#define VPU_H1_SWREG243_BF_16(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG243_BF_16_SHIFT)) & VPU_H1_SWREG243_BF_16_MASK)

#define VPU_H1_SWREG243_BF_24_MASK               (0x1F000000U)
#define VPU_H1_SWREG243_BF_24_SHIFT              (24U)
/*! BF_24 - VP8 predictor interpolation coefficient for 4/8 pixel position tap=2 */
#define VPU_H1_SWREG243_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG243_BF_24_SHIFT)) & VPU_H1_SWREG243_BF_24_MASK)

#define VPU_H1_SWREG243_BF_29_MASK               (0xE0000000U)
#define VPU_H1_SWREG243_BF_29_SHIFT              (29U)
/*! BF_29 - VP8 predictor interpolation coefficient for 4/8 pixel position tap=1 */
#define VPU_H1_SWREG243_BF_29(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG243_BF_29_SHIFT)) & VPU_H1_SWREG243_BF_29_MASK)
/*! @} */

/*! @name SWREG244 - VPU H1 Register 244 */
/*! @{ */

#define VPU_H1_SWREG244_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG244_BF_0_SHIFT               (0U)
/*! BF_0 - Base address for VP8 3rd DCT partition */
#define VPU_H1_SWREG244_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG244_BF_0_SHIFT)) & VPU_H1_SWREG244_BF_0_MASK)
/*! @} */

/*! @name SWREG245 - VPU H1 Register 245 */
/*! @{ */

#define VPU_H1_SWREG245_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG245_BF_0_SHIFT               (0U)
/*! BF_0 - Base address for VP8 4th DCT partition */
#define VPU_H1_SWREG245_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG245_BF_0_SHIFT)) & VPU_H1_SWREG245_BF_0_MASK)
/*! @} */

/*! @name SWREG256 - VPU H1 Register 256 */
/*! @{ */

#define VPU_H1_SWREG256_BF_0_MASK                (0x3FFU)
#define VPU_H1_SWREG256_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 1: Intra 16x16 mode 0 penalty */
#define VPU_H1_SWREG256_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG256_BF_0_SHIFT)) & VPU_H1_SWREG256_BF_0_MASK)

#define VPU_H1_SWREG256_BF_10_MASK               (0xFFC00U)
#define VPU_H1_SWREG256_BF_10_SHIFT              (10U)
/*! BF_10 - Segment 1: Intra 16x16 mode 1 penalty */
#define VPU_H1_SWREG256_BF_10(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG256_BF_10_SHIFT)) & VPU_H1_SWREG256_BF_10_MASK)

#define VPU_H1_SWREG256_BF_20_MASK               (0x3FF00000U)
#define VPU_H1_SWREG256_BF_20_SHIFT              (20U)
/*! BF_20 - Segment 1: Intra 16x16 mode 2 penalty */
#define VPU_H1_SWREG256_BF_20(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG256_BF_20_SHIFT)) & VPU_H1_SWREG256_BF_20_MASK)
/*! @} */

/*! @name SWREG257 - VPU H1 Register 257 */
/*! @{ */

#define VPU_H1_SWREG257_BF_0_MASK                (0x3FFU)
#define VPU_H1_SWREG257_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 1: Intra 16x16 mode 3 penalty */
#define VPU_H1_SWREG257_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG257_BF_0_SHIFT)) & VPU_H1_SWREG257_BF_0_MASK)

#define VPU_H1_SWREG257_BF_10_MASK               (0xFFC00U)
#define VPU_H1_SWREG257_BF_10_SHIFT              (10U)
/*! BF_10 - Segment 1: Intra 4x4 mode 0 penalty */
#define VPU_H1_SWREG257_BF_10(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG257_BF_10_SHIFT)) & VPU_H1_SWREG257_BF_10_MASK)

#define VPU_H1_SWREG257_BF_20_MASK               (0x3FF00000U)
#define VPU_H1_SWREG257_BF_20_SHIFT              (20U)
/*! BF_20 - Segment 1: Intra 4x4 mode 1 penalty */
#define VPU_H1_SWREG257_BF_20(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG257_BF_20_SHIFT)) & VPU_H1_SWREG257_BF_20_MASK)
/*! @} */

/*! @name SWREG258 - VPU H1 Register 258 */
/*! @{ */

#define VPU_H1_SWREG258_BF_0_MASK                (0x3FFU)
#define VPU_H1_SWREG258_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 1: Intra 4x4 mode 2 penalty */
#define VPU_H1_SWREG258_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG258_BF_0_SHIFT)) & VPU_H1_SWREG258_BF_0_MASK)

#define VPU_H1_SWREG258_BF_10_MASK               (0xFFC00U)
#define VPU_H1_SWREG258_BF_10_SHIFT              (10U)
/*! BF_10 - Segment 1: Intra 4x4 mode 3 penalty */
#define VPU_H1_SWREG258_BF_10(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG258_BF_10_SHIFT)) & VPU_H1_SWREG258_BF_10_MASK)

#define VPU_H1_SWREG258_BF_20_MASK               (0x3FF00000U)
#define VPU_H1_SWREG258_BF_20_SHIFT              (20U)
/*! BF_20 - Segment 1: Intra 4x4 mode 4 penalty */
#define VPU_H1_SWREG258_BF_20(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG258_BF_20_SHIFT)) & VPU_H1_SWREG258_BF_20_MASK)
/*! @} */

/*! @name SWREG259 - VPU H1 Register 259 */
/*! @{ */

#define VPU_H1_SWREG259_BF_0_MASK                (0x3FFU)
#define VPU_H1_SWREG259_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 1: Intra 4x4 mode 5 penalty */
#define VPU_H1_SWREG259_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG259_BF_0_SHIFT)) & VPU_H1_SWREG259_BF_0_MASK)

#define VPU_H1_SWREG259_BF_10_MASK               (0xFFC00U)
#define VPU_H1_SWREG259_BF_10_SHIFT              (10U)
/*! BF_10 - Segment 1: Intra 4x4 mode 6 penalty */
#define VPU_H1_SWREG259_BF_10(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG259_BF_10_SHIFT)) & VPU_H1_SWREG259_BF_10_MASK)

#define VPU_H1_SWREG259_BF_20_MASK               (0x3FF00000U)
#define VPU_H1_SWREG259_BF_20_SHIFT              (20U)
/*! BF_20 - Segment 1: Intra 4x4 mode 7 penalty */
#define VPU_H1_SWREG259_BF_20(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG259_BF_20_SHIFT)) & VPU_H1_SWREG259_BF_20_MASK)
/*! @} */

/*! @name SWREG260 - VPU H1 Register 260 */
/*! @{ */

#define VPU_H1_SWREG260_BF_0_MASK                (0x3FFU)
#define VPU_H1_SWREG260_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 1: Intra 4x4 mode 8 penalty */
#define VPU_H1_SWREG260_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG260_BF_0_SHIFT)) & VPU_H1_SWREG260_BF_0_MASK)

#define VPU_H1_SWREG260_BF_10_MASK               (0xFFC00U)
#define VPU_H1_SWREG260_BF_10_SHIFT              (10U)
/*! BF_10 - Segment 1: Intra 4x4 mode 9 penalty */
#define VPU_H1_SWREG260_BF_10(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG260_BF_10_SHIFT)) & VPU_H1_SWREG260_BF_10_MASK)

#define VPU_H1_SWREG260_BF_20_MASK               (0xFF00000U)
#define VPU_H1_SWREG260_BF_20_SHIFT              (20U)
/*! BF_20 - Segment 1: Intra 4x4 previous mode favor for H.264 */
#define VPU_H1_SWREG260_BF_20(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG260_BF_20_SHIFT)) & VPU_H1_SWREG260_BF_20_MASK)
/*! @} */

/*! @name SWREG261 - VPU H1 Register 261 */
/*! @{ */

#define VPU_H1_SWREG261_BF_0_MASK                (0xFFFU)
#define VPU_H1_SWREG261_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 1: Bit cost of inter type */
#define VPU_H1_SWREG261_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG261_BF_0_SHIFT)) & VPU_H1_SWREG261_BF_0_MASK)

#define VPU_H1_SWREG261_BF_12_MASK               (0xFFFF000U)
#define VPU_H1_SWREG261_BF_12_SHIFT              (12U)
/*! BF_12 - Segment 1: Intra 16x16 mode favor in intra 16x16/4x4 selection */
#define VPU_H1_SWREG261_BF_12(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG261_BF_12_SHIFT)) & VPU_H1_SWREG261_BF_12_MASK)
/*! @} */

/*! @name SWREG262 - VPU H1 Register 262 */
/*! @{ */

#define VPU_H1_SWREG262_BF_0_MASK                (0xFFFFU)
#define VPU_H1_SWREG262_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 1: Inter MB mode favor in intra/inter selection */
#define VPU_H1_SWREG262_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG262_BF_0_SHIFT)) & VPU_H1_SWREG262_BF_0_MASK)

#define VPU_H1_SWREG262_BF_16_MASK               (0xFF0000U)
#define VPU_H1_SWREG262_BF_16_SHIFT              (16U)
/*! BF_16 - Segment 1: Skip mode (zero/nearest/near) penalty */
#define VPU_H1_SWREG262_BF_16(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG262_BF_16_SHIFT)) & VPU_H1_SWREG262_BF_16_MASK)

#define VPU_H1_SWREG262_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG262_BF_24_SHIFT              (24U)
/*! BF_24 - Segment 1: Penalty value for second reference frame zero-mv. VP8 golden / H.264 LTR. [0..255] */
#define VPU_H1_SWREG262_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG262_BF_24_SHIFT)) & VPU_H1_SWREG262_BF_24_MASK)
/*! @} */

/*! @name SWREG263 - VPU H1 Register 263 */
/*! @{ */

#define VPU_H1_SWREG263_BF_0_MASK                (0x3FFU)
#define VPU_H1_SWREG263_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 1: Penalty for using 8x4 or 4x8 MV. */
#define VPU_H1_SWREG263_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG263_BF_0_SHIFT)) & VPU_H1_SWREG263_BF_0_MASK)

#define VPU_H1_SWREG263_BF_10_MASK               (0xFFC00U)
#define VPU_H1_SWREG263_BF_10_SHIFT              (10U)
/*! BF_10 - Segment 1: Penalty for using 8x8 MV. */
#define VPU_H1_SWREG263_BF_10(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG263_BF_10_SHIFT)) & VPU_H1_SWREG263_BF_10_MASK)

#define VPU_H1_SWREG263_BF_20_MASK               (0x3FF00000U)
#define VPU_H1_SWREG263_BF_20_SHIFT              (20U)
/*! BF_20 - Segment 1: Penalty for using 16x8 or 8x16 MV. */
#define VPU_H1_SWREG263_BF_20(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG263_BF_20_SHIFT)) & VPU_H1_SWREG263_BF_20_MASK)
/*! @} */

/*! @name SWREG264 - VPU H1 Register 264 */
/*! @{ */

#define VPU_H1_SWREG264_BF_0_MASK                (0x1FFU)
#define VPU_H1_SWREG264_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 1: Penalty for using 4x4 MV. */
#define VPU_H1_SWREG264_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG264_BF_0_SHIFT)) & VPU_H1_SWREG264_BF_0_MASK)

#define VPU_H1_SWREG264_BF_10_MASK               (0xFFC00U)
#define VPU_H1_SWREG264_BF_10_SHIFT              (10U)
/*! BF_10 - Segment 1: Penalty for using zero-MV in 16x8/8x16/8x8 split */
#define VPU_H1_SWREG264_BF_10(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG264_BF_10_SHIFT)) & VPU_H1_SWREG264_BF_10_MASK)

#define VPU_H1_SWREG264_BF_20_MASK               (0x3FF00000U)
#define VPU_H1_SWREG264_BF_20_SHIFT              (20U)
/*! BF_20 - Segment 1: Differential MV penalty for 1/4p ME. DMVPenaltyQp */
#define VPU_H1_SWREG264_BF_20(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG264_BF_20_SHIFT)) & VPU_H1_SWREG264_BF_20_MASK)
/*! @} */

/*! @name SWREG265 - VPU H1 Register 265 */
/*! @{ */

#define VPU_H1_SWREG265_BF_0_MASK                (0x3FFFU)
#define VPU_H1_SWREG265_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 1: Deadzone rate multiplier for plane 0 */
#define VPU_H1_SWREG265_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG265_BF_0_SHIFT)) & VPU_H1_SWREG265_BF_0_MASK)

#define VPU_H1_SWREG265_BF_14_MASK               (0xFFFC000U)
#define VPU_H1_SWREG265_BF_14_SHIFT              (14U)
/*! BF_14 - Segment 1: Deadzone rate multiplier for plane 1 */
#define VPU_H1_SWREG265_BF_14(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG265_BF_14_SHIFT)) & VPU_H1_SWREG265_BF_14_MASK)
/*! @} */

/*! @name SWREG266 - VPU H1 Register 266 */
/*! @{ */

#define VPU_H1_SWREG266_BF_0_MASK                (0x3FFFU)
#define VPU_H1_SWREG266_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 1: Deadzone rate multiplier for plane 2 */
#define VPU_H1_SWREG266_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG266_BF_0_SHIFT)) & VPU_H1_SWREG266_BF_0_MASK)

#define VPU_H1_SWREG266_BF_14_MASK               (0xFFFC000U)
#define VPU_H1_SWREG266_BF_14_SHIFT              (14U)
/*! BF_14 - Segment 1: Deadzone rate multiplier for plane 3 */
#define VPU_H1_SWREG266_BF_14(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG266_BF_14_SHIFT)) & VPU_H1_SWREG266_BF_14_MASK)
/*! @} */

/*! @name SWREG267 - VPU H1 Register 267 */
/*! @{ */

#define VPU_H1_SWREG267_BF_0_MASK                (0x3FFU)
#define VPU_H1_SWREG267_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 1: Deadzone rate for macroblock skip token 0 */
#define VPU_H1_SWREG267_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG267_BF_0_SHIFT)) & VPU_H1_SWREG267_BF_0_MASK)

#define VPU_H1_SWREG267_BF_10_MASK               (0xFFC00U)
#define VPU_H1_SWREG267_BF_10_SHIFT              (10U)
/*! BF_10 - Segment 1: Deadzone rate for macroblock skip token 1 */
#define VPU_H1_SWREG267_BF_10(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG267_BF_10_SHIFT)) & VPU_H1_SWREG267_BF_10_MASK)

#define VPU_H1_SWREG267_BF_20_MASK               (0xFFF00000U)
#define VPU_H1_SWREG267_BF_20_SHIFT              (20U)
/*! BF_20 - Segment 1: Coeff for dmv penalty for intra/inter selection */
#define VPU_H1_SWREG267_BF_20(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG267_BF_20_SHIFT)) & VPU_H1_SWREG267_BF_20_MASK)
/*! @} */

/*! @name SWREG268 - VPU H1 Register 268 */
/*! @{ */

#define VPU_H1_SWREG268_BF_0_MASK                (0x3FFU)
#define VPU_H1_SWREG268_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 2: Intra 16x16 mode 0 penalty */
#define VPU_H1_SWREG268_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG268_BF_0_SHIFT)) & VPU_H1_SWREG268_BF_0_MASK)

#define VPU_H1_SWREG268_BF_10_MASK               (0xFFC00U)
#define VPU_H1_SWREG268_BF_10_SHIFT              (10U)
/*! BF_10 - Segment 2: Intra 16x16 mode 1 penalty */
#define VPU_H1_SWREG268_BF_10(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG268_BF_10_SHIFT)) & VPU_H1_SWREG268_BF_10_MASK)

#define VPU_H1_SWREG268_BF_20_MASK               (0x3FF00000U)
#define VPU_H1_SWREG268_BF_20_SHIFT              (20U)
/*! BF_20 - Segment 2: Intra 16x16 mode 2 penalty */
#define VPU_H1_SWREG268_BF_20(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG268_BF_20_SHIFT)) & VPU_H1_SWREG268_BF_20_MASK)
/*! @} */

/*! @name SWREG269 - VPU H1 Register 269 */
/*! @{ */

#define VPU_H1_SWREG269_BF_0_MASK                (0x3FFU)
#define VPU_H1_SWREG269_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 2: Intra 16x16 mode 3 penalty */
#define VPU_H1_SWREG269_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG269_BF_0_SHIFT)) & VPU_H1_SWREG269_BF_0_MASK)

#define VPU_H1_SWREG269_BF_10_MASK               (0xFFC00U)
#define VPU_H1_SWREG269_BF_10_SHIFT              (10U)
/*! BF_10 - Segment 2: Intra 4x4 mode 0 penalty */
#define VPU_H1_SWREG269_BF_10(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG269_BF_10_SHIFT)) & VPU_H1_SWREG269_BF_10_MASK)

#define VPU_H1_SWREG269_BF_20_MASK               (0x3FF00000U)
#define VPU_H1_SWREG269_BF_20_SHIFT              (20U)
/*! BF_20 - Segment 2: Intra 4x4 mode 1 penalty */
#define VPU_H1_SWREG269_BF_20(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG269_BF_20_SHIFT)) & VPU_H1_SWREG269_BF_20_MASK)
/*! @} */

/*! @name SWREG270 - VPU H1 Register 270 */
/*! @{ */

#define VPU_H1_SWREG270_BF_0_MASK                (0x3FFU)
#define VPU_H1_SWREG270_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 2: Intra 4x4 mode 2 penalty */
#define VPU_H1_SWREG270_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG270_BF_0_SHIFT)) & VPU_H1_SWREG270_BF_0_MASK)

#define VPU_H1_SWREG270_BF_10_MASK               (0xFFC00U)
#define VPU_H1_SWREG270_BF_10_SHIFT              (10U)
/*! BF_10 - Segment 2: Intra 4x4 mode 3 penalty */
#define VPU_H1_SWREG270_BF_10(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG270_BF_10_SHIFT)) & VPU_H1_SWREG270_BF_10_MASK)

#define VPU_H1_SWREG270_BF_20_MASK               (0x3FF00000U)
#define VPU_H1_SWREG270_BF_20_SHIFT              (20U)
/*! BF_20 - Segment 2: Intra 4x4 mode 4 penalty */
#define VPU_H1_SWREG270_BF_20(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG270_BF_20_SHIFT)) & VPU_H1_SWREG270_BF_20_MASK)
/*! @} */

/*! @name SWREG271 - VPU H1 Register 271 */
/*! @{ */

#define VPU_H1_SWREG271_BF_0_MASK                (0x3FFU)
#define VPU_H1_SWREG271_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 2: Intra 4x4 mode 5 penalty */
#define VPU_H1_SWREG271_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG271_BF_0_SHIFT)) & VPU_H1_SWREG271_BF_0_MASK)

#define VPU_H1_SWREG271_BF_10_MASK               (0xFFC00U)
#define VPU_H1_SWREG271_BF_10_SHIFT              (10U)
/*! BF_10 - Segment 2: Intra 4x4 mode 6 penalty */
#define VPU_H1_SWREG271_BF_10(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG271_BF_10_SHIFT)) & VPU_H1_SWREG271_BF_10_MASK)

#define VPU_H1_SWREG271_BF_20_MASK               (0x3FF00000U)
#define VPU_H1_SWREG271_BF_20_SHIFT              (20U)
/*! BF_20 - Segment 2: Intra 4x4 mode 7 penalty */
#define VPU_H1_SWREG271_BF_20(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG271_BF_20_SHIFT)) & VPU_H1_SWREG271_BF_20_MASK)
/*! @} */

/*! @name SWREG272 - VPU H1 Register 272 */
/*! @{ */

#define VPU_H1_SWREG272_BF_0_MASK                (0x3FFU)
#define VPU_H1_SWREG272_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 2: Intra 4x4 mode 8 penalty */
#define VPU_H1_SWREG272_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG272_BF_0_SHIFT)) & VPU_H1_SWREG272_BF_0_MASK)

#define VPU_H1_SWREG272_BF_10_MASK               (0xFFC00U)
#define VPU_H1_SWREG272_BF_10_SHIFT              (10U)
/*! BF_10 - Segment 2: Intra 4x4 mode 9 penalty */
#define VPU_H1_SWREG272_BF_10(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG272_BF_10_SHIFT)) & VPU_H1_SWREG272_BF_10_MASK)

#define VPU_H1_SWREG272_BF_20_MASK               (0xFF00000U)
#define VPU_H1_SWREG272_BF_20_SHIFT              (20U)
/*! BF_20 - Segment 2: Intra 4x4 previous mode favor for H.264 */
#define VPU_H1_SWREG272_BF_20(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG272_BF_20_SHIFT)) & VPU_H1_SWREG272_BF_20_MASK)
/*! @} */

/*! @name SWREG273 - VPU H1 Register 273 */
/*! @{ */

#define VPU_H1_SWREG273_BF_0_MASK                (0xFFFU)
#define VPU_H1_SWREG273_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 2: Bit cost of inter type */
#define VPU_H1_SWREG273_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG273_BF_0_SHIFT)) & VPU_H1_SWREG273_BF_0_MASK)

#define VPU_H1_SWREG273_BF_12_MASK               (0xFFFF000U)
#define VPU_H1_SWREG273_BF_12_SHIFT              (12U)
/*! BF_12 - Segment 2: Intra 16x16 mode favor in intra 16x16/4x4 selection */
#define VPU_H1_SWREG273_BF_12(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG273_BF_12_SHIFT)) & VPU_H1_SWREG273_BF_12_MASK)
/*! @} */

/*! @name SWREG274 - VPU H1 Register 274 */
/*! @{ */

#define VPU_H1_SWREG274_BF_0_MASK                (0xFFFFU)
#define VPU_H1_SWREG274_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 2: Inter MB mode favor in intra/inter selection */
#define VPU_H1_SWREG274_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG274_BF_0_SHIFT)) & VPU_H1_SWREG274_BF_0_MASK)

#define VPU_H1_SWREG274_BF_16_MASK               (0xFF0000U)
#define VPU_H1_SWREG274_BF_16_SHIFT              (16U)
/*! BF_16 - Segment 2: Skip mode (zero/nearest/near) penalty */
#define VPU_H1_SWREG274_BF_16(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG274_BF_16_SHIFT)) & VPU_H1_SWREG274_BF_16_MASK)

#define VPU_H1_SWREG274_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG274_BF_24_SHIFT              (24U)
/*! BF_24 - Segment 2: Penalty value for second reference frame zero-mv. VP8 golden / H.264 LTR. [0..255] */
#define VPU_H1_SWREG274_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG274_BF_24_SHIFT)) & VPU_H1_SWREG274_BF_24_MASK)
/*! @} */

/*! @name SWREG275 - VPU H1 Register 275 */
/*! @{ */

#define VPU_H1_SWREG275_BF_0_MASK                (0x3FFU)
#define VPU_H1_SWREG275_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 2: Penalty for using 8x4 or 4x8 MV. */
#define VPU_H1_SWREG275_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG275_BF_0_SHIFT)) & VPU_H1_SWREG275_BF_0_MASK)

#define VPU_H1_SWREG275_BF_10_MASK               (0xFFC00U)
#define VPU_H1_SWREG275_BF_10_SHIFT              (10U)
/*! BF_10 - Segment 2: Penalty for using 8x8 MV. */
#define VPU_H1_SWREG275_BF_10(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG275_BF_10_SHIFT)) & VPU_H1_SWREG275_BF_10_MASK)

#define VPU_H1_SWREG275_BF_20_MASK               (0x3FF00000U)
#define VPU_H1_SWREG275_BF_20_SHIFT              (20U)
/*! BF_20 - Segment 2: Penalty for using 16x8 or 8x16 MV. */
#define VPU_H1_SWREG275_BF_20(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG275_BF_20_SHIFT)) & VPU_H1_SWREG275_BF_20_MASK)
/*! @} */

/*! @name SWREG276 - VPU H1 Register 276 */
/*! @{ */

#define VPU_H1_SWREG276_BF_0_MASK                (0x1FFU)
#define VPU_H1_SWREG276_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 2: Penalty for using 4x4 MV. */
#define VPU_H1_SWREG276_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG276_BF_0_SHIFT)) & VPU_H1_SWREG276_BF_0_MASK)

#define VPU_H1_SWREG276_BF_10_MASK               (0xFFC00U)
#define VPU_H1_SWREG276_BF_10_SHIFT              (10U)
/*! BF_10 - Segment 2: Penalty for using zero-MV in 16x8/8x16/8x8 split */
#define VPU_H1_SWREG276_BF_10(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG276_BF_10_SHIFT)) & VPU_H1_SWREG276_BF_10_MASK)

#define VPU_H1_SWREG276_BF_20_MASK               (0x3FF00000U)
#define VPU_H1_SWREG276_BF_20_SHIFT              (20U)
/*! BF_20 - Segment 2: Differential MV penalty for 1/4p ME. DMVPenaltyQp */
#define VPU_H1_SWREG276_BF_20(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG276_BF_20_SHIFT)) & VPU_H1_SWREG276_BF_20_MASK)
/*! @} */

/*! @name SWREG277 - VPU H1 Register 277 */
/*! @{ */

#define VPU_H1_SWREG277_BF_0_MASK                (0x3FFFU)
#define VPU_H1_SWREG277_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 2: Deadzone rate multiplier for plane 0 */
#define VPU_H1_SWREG277_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG277_BF_0_SHIFT)) & VPU_H1_SWREG277_BF_0_MASK)

#define VPU_H1_SWREG277_BF_14_MASK               (0xFFFC000U)
#define VPU_H1_SWREG277_BF_14_SHIFT              (14U)
/*! BF_14 - Segment 2: Deadzone rate multiplier for plane 1 */
#define VPU_H1_SWREG277_BF_14(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG277_BF_14_SHIFT)) & VPU_H1_SWREG277_BF_14_MASK)
/*! @} */

/*! @name SWREG278 - VPU H1 Register 278 */
/*! @{ */

#define VPU_H1_SWREG278_BF_0_MASK                (0x3FFFU)
#define VPU_H1_SWREG278_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 2: Deadzone rate multiplier for plane 2 */
#define VPU_H1_SWREG278_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG278_BF_0_SHIFT)) & VPU_H1_SWREG278_BF_0_MASK)

#define VPU_H1_SWREG278_BF_14_MASK               (0xFFFC000U)
#define VPU_H1_SWREG278_BF_14_SHIFT              (14U)
/*! BF_14 - Segment 2: Deadzone rate multiplier for plane 3 */
#define VPU_H1_SWREG278_BF_14(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG278_BF_14_SHIFT)) & VPU_H1_SWREG278_BF_14_MASK)
/*! @} */

/*! @name SWREG279 - VPU H1 Register 279 */
/*! @{ */

#define VPU_H1_SWREG279_BF_0_MASK                (0x3FFU)
#define VPU_H1_SWREG279_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 2: Deadzone rate for macroblock skip token 0 */
#define VPU_H1_SWREG279_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG279_BF_0_SHIFT)) & VPU_H1_SWREG279_BF_0_MASK)

#define VPU_H1_SWREG279_BF_10_MASK               (0xFFC00U)
#define VPU_H1_SWREG279_BF_10_SHIFT              (10U)
/*! BF_10 - Segment 2: Deadzone rate for macroblock skip token 1 */
#define VPU_H1_SWREG279_BF_10(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG279_BF_10_SHIFT)) & VPU_H1_SWREG279_BF_10_MASK)

#define VPU_H1_SWREG279_BF_20_MASK               (0xFFF00000U)
#define VPU_H1_SWREG279_BF_20_SHIFT              (20U)
/*! BF_20 - Segment 2: Coeff for dmv penalty for intra/inter selection */
#define VPU_H1_SWREG279_BF_20(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG279_BF_20_SHIFT)) & VPU_H1_SWREG279_BF_20_MASK)
/*! @} */

/*! @name SWREG280 - VPU H1 Register 280 */
/*! @{ */

#define VPU_H1_SWREG280_BF_0_MASK                (0x3FFU)
#define VPU_H1_SWREG280_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 3: Intra 16x16 mode 0 penalty */
#define VPU_H1_SWREG280_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG280_BF_0_SHIFT)) & VPU_H1_SWREG280_BF_0_MASK)

#define VPU_H1_SWREG280_BF_10_MASK               (0xFFC00U)
#define VPU_H1_SWREG280_BF_10_SHIFT              (10U)
/*! BF_10 - Segment 3: Intra 16x16 mode 1 penalty */
#define VPU_H1_SWREG280_BF_10(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG280_BF_10_SHIFT)) & VPU_H1_SWREG280_BF_10_MASK)

#define VPU_H1_SWREG280_BF_20_MASK               (0x3FF00000U)
#define VPU_H1_SWREG280_BF_20_SHIFT              (20U)
/*! BF_20 - Segment 3: Intra 16x16 mode 2 penalty */
#define VPU_H1_SWREG280_BF_20(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG280_BF_20_SHIFT)) & VPU_H1_SWREG280_BF_20_MASK)
/*! @} */

/*! @name SWREG281 - VPU H1 Register 281 */
/*! @{ */

#define VPU_H1_SWREG281_BF_0_MASK                (0x3FFU)
#define VPU_H1_SWREG281_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 3: Intra 16x16 mode 3 penalty */
#define VPU_H1_SWREG281_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG281_BF_0_SHIFT)) & VPU_H1_SWREG281_BF_0_MASK)

#define VPU_H1_SWREG281_BF_10_MASK               (0xFFC00U)
#define VPU_H1_SWREG281_BF_10_SHIFT              (10U)
/*! BF_10 - Segment 3: Intra 4x4 mode 0 penalty */
#define VPU_H1_SWREG281_BF_10(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG281_BF_10_SHIFT)) & VPU_H1_SWREG281_BF_10_MASK)

#define VPU_H1_SWREG281_BF_20_MASK               (0x3FF00000U)
#define VPU_H1_SWREG281_BF_20_SHIFT              (20U)
/*! BF_20 - Segment 3: Intra 4x4 mode 1 penalty */
#define VPU_H1_SWREG281_BF_20(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG281_BF_20_SHIFT)) & VPU_H1_SWREG281_BF_20_MASK)
/*! @} */

/*! @name SWREG282 - VPU H1 Register 282 */
/*! @{ */

#define VPU_H1_SWREG282_BF_0_MASK                (0x3FFU)
#define VPU_H1_SWREG282_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 3: Intra 4x4 mode 2 penalty */
#define VPU_H1_SWREG282_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG282_BF_0_SHIFT)) & VPU_H1_SWREG282_BF_0_MASK)

#define VPU_H1_SWREG282_BF_10_MASK               (0xFFC00U)
#define VPU_H1_SWREG282_BF_10_SHIFT              (10U)
/*! BF_10 - Segment 3: Intra 4x4 mode 3 penalty */
#define VPU_H1_SWREG282_BF_10(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG282_BF_10_SHIFT)) & VPU_H1_SWREG282_BF_10_MASK)

#define VPU_H1_SWREG282_BF_20_MASK               (0x3FF00000U)
#define VPU_H1_SWREG282_BF_20_SHIFT              (20U)
/*! BF_20 - Segment 3: Intra 4x4 mode 4 penalty */
#define VPU_H1_SWREG282_BF_20(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG282_BF_20_SHIFT)) & VPU_H1_SWREG282_BF_20_MASK)
/*! @} */

/*! @name SWREG283 - VPU H1 Register 283 */
/*! @{ */

#define VPU_H1_SWREG283_BF_0_MASK                (0x3FFU)
#define VPU_H1_SWREG283_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 3: Intra 4x4 mode 5 penalty */
#define VPU_H1_SWREG283_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG283_BF_0_SHIFT)) & VPU_H1_SWREG283_BF_0_MASK)

#define VPU_H1_SWREG283_BF_10_MASK               (0xFFC00U)
#define VPU_H1_SWREG283_BF_10_SHIFT              (10U)
/*! BF_10 - Segment 3: Intra 4x4 mode 6 penalty */
#define VPU_H1_SWREG283_BF_10(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG283_BF_10_SHIFT)) & VPU_H1_SWREG283_BF_10_MASK)

#define VPU_H1_SWREG283_BF_20_MASK               (0x3FF00000U)
#define VPU_H1_SWREG283_BF_20_SHIFT              (20U)
/*! BF_20 - Segment 3: Intra 4x4 mode 7 penalty */
#define VPU_H1_SWREG283_BF_20(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG283_BF_20_SHIFT)) & VPU_H1_SWREG283_BF_20_MASK)
/*! @} */

/*! @name SWREG284 - VPU H1 Register 284 */
/*! @{ */

#define VPU_H1_SWREG284_BF_0_MASK                (0x3FFU)
#define VPU_H1_SWREG284_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 3: Intra 4x4 mode 8 penalty */
#define VPU_H1_SWREG284_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG284_BF_0_SHIFT)) & VPU_H1_SWREG284_BF_0_MASK)

#define VPU_H1_SWREG284_BF_10_MASK               (0xFFC00U)
#define VPU_H1_SWREG284_BF_10_SHIFT              (10U)
/*! BF_10 - Segment 3: Intra 4x4 mode 9 penalty */
#define VPU_H1_SWREG284_BF_10(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG284_BF_10_SHIFT)) & VPU_H1_SWREG284_BF_10_MASK)

#define VPU_H1_SWREG284_BF_20_MASK               (0xFF00000U)
#define VPU_H1_SWREG284_BF_20_SHIFT              (20U)
/*! BF_20 - Segment 3: Intra 4x4 previous mode favor for H.264 */
#define VPU_H1_SWREG284_BF_20(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG284_BF_20_SHIFT)) & VPU_H1_SWREG284_BF_20_MASK)
/*! @} */

/*! @name SWREG285 - VPU H1 Register 285 */
/*! @{ */

#define VPU_H1_SWREG285_BF_0_MASK                (0xFFFU)
#define VPU_H1_SWREG285_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 3: Bit cost of inter type */
#define VPU_H1_SWREG285_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG285_BF_0_SHIFT)) & VPU_H1_SWREG285_BF_0_MASK)

#define VPU_H1_SWREG285_BF_12_MASK               (0xFFFF000U)
#define VPU_H1_SWREG285_BF_12_SHIFT              (12U)
/*! BF_12 - Segment 3: Intra 16x16 mode favor in intra 16x16/4x4 selection */
#define VPU_H1_SWREG285_BF_12(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG285_BF_12_SHIFT)) & VPU_H1_SWREG285_BF_12_MASK)
/*! @} */

/*! @name SWREG286 - VPU H1 Register 286 */
/*! @{ */

#define VPU_H1_SWREG286_BF_0_MASK                (0xFFFFU)
#define VPU_H1_SWREG286_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 3: Inter MB mode favor in intra/inter selection */
#define VPU_H1_SWREG286_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG286_BF_0_SHIFT)) & VPU_H1_SWREG286_BF_0_MASK)

#define VPU_H1_SWREG286_BF_16_MASK               (0xFF0000U)
#define VPU_H1_SWREG286_BF_16_SHIFT              (16U)
/*! BF_16 - Segment 3: Skip mode (zero/nearest/near) penalty */
#define VPU_H1_SWREG286_BF_16(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG286_BF_16_SHIFT)) & VPU_H1_SWREG286_BF_16_MASK)

#define VPU_H1_SWREG286_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG286_BF_24_SHIFT              (24U)
/*! BF_24 - Segment 3: Penalty value for second reference frame zero-mv. VP8 golden / H.264 LTR. [0..255] */
#define VPU_H1_SWREG286_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG286_BF_24_SHIFT)) & VPU_H1_SWREG286_BF_24_MASK)
/*! @} */

/*! @name SWREG287 - VPU H1 Register 287 */
/*! @{ */

#define VPU_H1_SWREG287_BF_0_MASK                (0x3FFU)
#define VPU_H1_SWREG287_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 3: Penalty for using 8x4 or 4x8 MV. */
#define VPU_H1_SWREG287_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG287_BF_0_SHIFT)) & VPU_H1_SWREG287_BF_0_MASK)

#define VPU_H1_SWREG287_BF_10_MASK               (0xFFC00U)
#define VPU_H1_SWREG287_BF_10_SHIFT              (10U)
/*! BF_10 - Segment 3: Penalty for using 8x8 MV. */
#define VPU_H1_SWREG287_BF_10(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG287_BF_10_SHIFT)) & VPU_H1_SWREG287_BF_10_MASK)

#define VPU_H1_SWREG287_BF_20_MASK               (0x3FF00000U)
#define VPU_H1_SWREG287_BF_20_SHIFT              (20U)
/*! BF_20 - Segment 3: Penalty for using 16x8 or 8x16 MV. */
#define VPU_H1_SWREG287_BF_20(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG287_BF_20_SHIFT)) & VPU_H1_SWREG287_BF_20_MASK)
/*! @} */

/*! @name SWREG288 - VPU H1 Register 288 */
/*! @{ */

#define VPU_H1_SWREG288_BF_0_MASK                (0x1FFU)
#define VPU_H1_SWREG288_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 3: Penalty for using 4x4 MV. */
#define VPU_H1_SWREG288_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG288_BF_0_SHIFT)) & VPU_H1_SWREG288_BF_0_MASK)

#define VPU_H1_SWREG288_BF_10_MASK               (0xFFC00U)
#define VPU_H1_SWREG288_BF_10_SHIFT              (10U)
/*! BF_10 - Segment 3: Penalty for using zero-MV in 16x8/8x16/8x8 split */
#define VPU_H1_SWREG288_BF_10(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG288_BF_10_SHIFT)) & VPU_H1_SWREG288_BF_10_MASK)

#define VPU_H1_SWREG288_BF_20_MASK               (0x3FF00000U)
#define VPU_H1_SWREG288_BF_20_SHIFT              (20U)
/*! BF_20 - Segment 3: Differential MV penalty for 1/4p ME. DMVPenaltyQp */
#define VPU_H1_SWREG288_BF_20(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG288_BF_20_SHIFT)) & VPU_H1_SWREG288_BF_20_MASK)
/*! @} */

/*! @name SWREG289 - VPU H1 Register 289 */
/*! @{ */

#define VPU_H1_SWREG289_BF_0_MASK                (0x3FFFU)
#define VPU_H1_SWREG289_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 3: Deadzone rate multiplier for plane 0 */
#define VPU_H1_SWREG289_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG289_BF_0_SHIFT)) & VPU_H1_SWREG289_BF_0_MASK)

#define VPU_H1_SWREG289_BF_14_MASK               (0xFFFC000U)
#define VPU_H1_SWREG289_BF_14_SHIFT              (14U)
/*! BF_14 - Segment 3: Deadzone rate multiplier for plane 1 */
#define VPU_H1_SWREG289_BF_14(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG289_BF_14_SHIFT)) & VPU_H1_SWREG289_BF_14_MASK)
/*! @} */

/*! @name SWREG290 - VPU H1 Register 290 */
/*! @{ */

#define VPU_H1_SWREG290_BF_0_MASK                (0x3FFFU)
#define VPU_H1_SWREG290_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 3: Deadzone rate multiplier for plane 2 */
#define VPU_H1_SWREG290_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG290_BF_0_SHIFT)) & VPU_H1_SWREG290_BF_0_MASK)

#define VPU_H1_SWREG290_BF_14_MASK               (0xFFFC000U)
#define VPU_H1_SWREG290_BF_14_SHIFT              (14U)
/*! BF_14 - Segment 3: Deadzone rate multiplier for plane 3 */
#define VPU_H1_SWREG290_BF_14(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG290_BF_14_SHIFT)) & VPU_H1_SWREG290_BF_14_MASK)
/*! @} */

/*! @name SWREG291 - VPU H1 Register 291 */
/*! @{ */

#define VPU_H1_SWREG291_BF_0_MASK                (0x3FFU)
#define VPU_H1_SWREG291_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 3: Deadzone rate for macroblock skip token 0 */
#define VPU_H1_SWREG291_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG291_BF_0_SHIFT)) & VPU_H1_SWREG291_BF_0_MASK)

#define VPU_H1_SWREG291_BF_10_MASK               (0xFFC00U)
#define VPU_H1_SWREG291_BF_10_SHIFT              (10U)
/*! BF_10 - Segment 3: Deadzone rate for macroblock skip token 1 */
#define VPU_H1_SWREG291_BF_10(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG291_BF_10_SHIFT)) & VPU_H1_SWREG291_BF_10_MASK)

#define VPU_H1_SWREG291_BF_20_MASK               (0xFFF00000U)
#define VPU_H1_SWREG291_BF_20_SHIFT              (20U)
/*! BF_20 - Segment 3: Coeff for dmv penalty for intra/inter selection */
#define VPU_H1_SWREG291_BF_20(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG291_BF_20_SHIFT)) & VPU_H1_SWREG291_BF_20_MASK)
/*! @} */

/*! @name SWREG292 - VPU H1 Register 292 */
/*! @{ */

#define VPU_H1_SWREG292_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG292_BF_0_SHIFT               (0U)
/*! BF_0 - VP8 average variance in prev frame */
#define VPU_H1_SWREG292_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG292_BF_0_SHIFT)) & VPU_H1_SWREG292_BF_0_MASK)
/*! @} */

/*! @name SWREG293 - VPU H1 Register 293 */
/*! @{ */

#define VPU_H1_SWREG293_BF_0_MASK                (0xFFFFU)
#define VPU_H1_SWREG293_BF_0_SHIFT               (0U)
/*! BF_0 - VP8 16384/avgVar in prev frame */
#define VPU_H1_SWREG293_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG293_BF_0_SHIFT)) & VPU_H1_SWREG293_BF_0_MASK)

#define VPU_H1_SWREG293_BF_16_MASK               (0x10000U)
#define VPU_H1_SWREG293_BF_16_SHIFT              (16U)
/*! BF_16 - H.264 FieldPicFlag. */
#define VPU_H1_SWREG293_BF_16(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG293_BF_16_SHIFT)) & VPU_H1_SWREG293_BF_16_MASK)

#define VPU_H1_SWREG293_BF_17_MASK               (0x20000U)
#define VPU_H1_SWREG293_BF_17_SHIFT              (17U)
/*! BF_17 - H.264 BottomFieldFlag. */
#define VPU_H1_SWREG293_BF_17(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG293_BF_17_SHIFT)) & VPU_H1_SWREG293_BF_17_MASK)

#define VPU_H1_SWREG293_BF_18_MASK               (0xC0000U)
#define VPU_H1_SWREG293_BF_18_SHIFT              (18U)
/*! BF_18 - H.264 Field parity conditions for chroma MV. */
#define VPU_H1_SWREG293_BF_18(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG293_BF_18_SHIFT)) & VPU_H1_SWREG293_BF_18_MASK)
/*! @} */

/*! @name SWREG294 - VPU H1 Register 294 */
/*! @{ */

#define VPU_H1_SWREG294_BF_0_MASK                (0x3FU)
#define VPU_H1_SWREG294_BF_0_SHIFT               (0U)
/*! BF_0 - Mb boost qp */
#define VPU_H1_SWREG294_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG294_BF_0_SHIFT)) & VPU_H1_SWREG294_BF_0_MASK)

#define VPU_H1_SWREG294_BF_6_MASK                (0x7FFC0U)
#define VPU_H1_SWREG294_BF_6_SHIFT               (6U)
/*! BF_6 - Mb boost variance1 */
#define VPU_H1_SWREG294_BF_6(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG294_BF_6_SHIFT)) & VPU_H1_SWREG294_BF_6_MASK)

#define VPU_H1_SWREG294_BF_19_MASK               (0xFFF80000U)
#define VPU_H1_SWREG294_BF_19_SHIFT              (19U)
/*! BF_19 - Mb boost variance2 */
#define VPU_H1_SWREG294_BF_19(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG294_BF_19_SHIFT)) & VPU_H1_SWREG294_BF_19_MASK)
/*! @} */

/*! @name SWREG295 - VPU H1 Register 295 */
/*! @{ */

#define VPU_H1_SWREG295_BF_0_MASK                (0xFU)
#define VPU_H1_SWREG295_BF_0_SHIFT               (0U)
/*! BF_0 - Variance limit */
#define VPU_H1_SWREG295_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG295_BF_0_SHIFT)) & VPU_H1_SWREG295_BF_0_MASK)

#define VPU_H1_SWREG295_BF_4_MASK                (0xF0U)
#define VPU_H1_SWREG295_BF_4_SHIFT               (4U)
/*! BF_4 - Variance interFavor */
#define VPU_H1_SWREG295_BF_4(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG295_BF_4_SHIFT)) & VPU_H1_SWREG295_BF_4_MASK)

#define VPU_H1_SWREG295_BF_8_MASK                (0x1F00U)
#define VPU_H1_SWREG295_BF_8_SHIFT               (8U)
/*! BF_8 - Variance multiplier */
#define VPU_H1_SWREG295_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG295_BF_8_SHIFT)) & VPU_H1_SWREG295_BF_8_MASK)

#define VPU_H1_SWREG295_BF_13_MASK               (0xE000U)
#define VPU_H1_SWREG295_BF_13_SHIFT              (13U)
/*! BF_13 - Variance add */
#define VPU_H1_SWREG295_BF_13(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG295_BF_13_SHIFT)) & VPU_H1_SWREG295_BF_13_MASK)

#define VPU_H1_SWREG295_BF_16_MASK               (0x10000U)
#define VPU_H1_SWREG295_BF_16_SHIFT              (16U)
/*! BF_16 - Pskip coding mode */
#define VPU_H1_SWREG295_BF_16(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG295_BF_16_SHIFT)) & VPU_H1_SWREG295_BF_16_MASK)
/*! @} */

/*! @name SWREG296 - VPU H1 Register 296 */
/*! @{ */

#define VPU_H1_SWREG296_BF_22_MASK               (0x400000U)
#define VPU_H1_SWREG296_BF_22_SHIFT              (22U)
/*! BF_22 - HW Input Loopback Support. not support now */
#define VPU_H1_SWREG296_BF_22(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG296_BF_22_SHIFT)) & VPU_H1_SWREG296_BF_22_MASK)

#define VPU_H1_SWREG296_BF_23_MASK               (0x800000U)
#define VPU_H1_SWREG296_BF_23_SHIFT              (23U)
/*! BF_23 - HW IRQ is clear in write-one way. */
#define VPU_H1_SWREG296_BF_23(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG296_BF_23_SHIFT)) & VPU_H1_SWREG296_BF_23_MASK)

#define VPU_H1_SWREG296_BF_24_MASK               (0x1000000U)
#define VPU_H1_SWREG296_BF_24_SHIFT              (24U)
/*! BF_24 - HW AXI Read ID for Input Support. */
#define VPU_H1_SWREG296_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG296_BF_24_SHIFT)) & VPU_H1_SWREG296_BF_24_MASK)

#define VPU_H1_SWREG296_BF_25_MASK               (0x2000000U)
#define VPU_H1_SWREG296_BF_25_SHIFT              (25U)
/*! BF_25 - HW SVCT Support. */
#define VPU_H1_SWREG296_BF_25(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG296_BF_25_SHIFT)) & VPU_H1_SWREG296_BF_25_MASK)

#define VPU_H1_SWREG296_BF_26_MASK               (0x4000000U)
#define VPU_H1_SWREG296_BF_26_SHIFT              (26U)
/*! BF_26 - HW Low Latency Control. */
#define VPU_H1_SWREG296_BF_26(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG296_BF_26_SHIFT)) & VPU_H1_SWREG296_BF_26_MASK)

#define VPU_H1_SWREG296_BF_27_MASK               (0x8000000U)
#define VPU_H1_SWREG296_BF_27_SHIFT              (27U)
/*! BF_27 - HW Enhancement for Quality. */
#define VPU_H1_SWREG296_BF_27(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG296_BF_27_SHIFT)) & VPU_H1_SWREG296_BF_27_MASK)

#define VPU_H1_SWREG296_BF_28_MASK               (0x30000000U)
#define VPU_H1_SWREG296_BF_28_SHIFT              (28U)
/*! BF_28 - HW Reference Compression Support for Luma and Chroma. */
#define VPU_H1_SWREG296_BF_28(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG296_BF_28_SHIFT)) & VPU_H1_SWREG296_BF_28_MASK)

#define VPU_H1_SWREG296_BF_30_MASK               (0x40000000U)
#define VPU_H1_SWREG296_BF_30_SHIFT              (30U)
/*! BF_30 - HW Denoise Support. */
#define VPU_H1_SWREG296_BF_30(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG296_BF_30_SHIFT)) & VPU_H1_SWREG296_BF_30_MASK)

#define VPU_H1_SWREG296_BF_31_MASK               (0x80000000U)
#define VPU_H1_SWREG296_BF_31_SHIFT              (31U)
/*! BF_31 - HW Address bit width. */
#define VPU_H1_SWREG296_BF_31(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG296_BF_31_SHIFT)) & VPU_H1_SWREG296_BF_31_MASK)
/*! @} */

/*! @name SWREG297 - VPU H1 Register 297 */
/*! @{ */

#define VPU_H1_SWREG297_BF_17_MASK               (0x7E0000U)
#define VPU_H1_SWREG297_BF_17_SHIFT              (17U)
/*! BF_17 - Segment 4: Intra 16x16 mode 1 penalty */
#define VPU_H1_SWREG297_BF_17(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG297_BF_17_SHIFT)) & VPU_H1_SWREG297_BF_17_MASK)

#define VPU_H1_SWREG297_BF_23_MASK               (0x7800000U)
#define VPU_H1_SWREG297_BF_23_SHIFT              (23U)
/*! BF_23 - Segment 4: Intra 16x16 mode 2 penalty */
#define VPU_H1_SWREG297_BF_23(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG297_BF_23_SHIFT)) & VPU_H1_SWREG297_BF_23_MASK)
/*! @} */

/*! @name SWREG298 - VPU H1 Register 298 */
/*! @{ */

#define VPU_H1_SWREG298_BF_0_MASK                (0xFFU)
#define VPU_H1_SWREG298_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 4: Penalty value for second reference frame zero-mv. VP8 golden / H.264 LTR. [0..255] */
#define VPU_H1_SWREG298_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG298_BF_0_SHIFT)) & VPU_H1_SWREG298_BF_0_MASK)

#define VPU_H1_SWREG298_BF_8_MASK                (0xFFFF00U)
#define VPU_H1_SWREG298_BF_8_SHIFT               (8U)
/*! BF_8 - Segment 4: Intra 16x16 mode favor in intra 16x16/4x4 selection */
#define VPU_H1_SWREG298_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG298_BF_8_SHIFT)) & VPU_H1_SWREG298_BF_8_MASK)

#define VPU_H1_SWREG298_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG298_BF_24_SHIFT              (24U)
/*! BF_24 - Segment 4: Intra 4x4 previous mode favor for H.264 */
#define VPU_H1_SWREG298_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG298_BF_24_SHIFT)) & VPU_H1_SWREG298_BF_24_MASK)
/*! @} */

/*! @name SWREG299 - VPU H1 Register 299 */
/*! @{ */

#define VPU_H1_SWREG299_BF_8_MASK                (0xFFFF00U)
#define VPU_H1_SWREG299_BF_8_SHIFT               (8U)
/*! BF_8 - Segment 4: Inter MB mode favor in intra/inter selection */
#define VPU_H1_SWREG299_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG299_BF_8_SHIFT)) & VPU_H1_SWREG299_BF_8_MASK)

#define VPU_H1_SWREG299_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG299_BF_24_SHIFT              (24U)
/*! BF_24 - Segment 4: Skip mode (zero/nearest/near) penalty */
#define VPU_H1_SWREG299_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG299_BF_24_SHIFT)) & VPU_H1_SWREG299_BF_24_MASK)
/*! @} */

/*! @name SWREG300 - VPU H1 Register 300 */
/*! @{ */

#define VPU_H1_SWREG300_BF_0_MASK                (0x3FFU)
#define VPU_H1_SWREG300_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 4: Penalty for using 8x4 or 4x8 MV. */
#define VPU_H1_SWREG300_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG300_BF_0_SHIFT)) & VPU_H1_SWREG300_BF_0_MASK)

#define VPU_H1_SWREG300_BF_10_MASK               (0xFFC00U)
#define VPU_H1_SWREG300_BF_10_SHIFT              (10U)
/*! BF_10 - Segment 4: Penalty for using 8x8 MV. */
#define VPU_H1_SWREG300_BF_10(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG300_BF_10_SHIFT)) & VPU_H1_SWREG300_BF_10_MASK)

#define VPU_H1_SWREG300_BF_20_MASK               (0x3FF00000U)
#define VPU_H1_SWREG300_BF_20_SHIFT              (20U)
/*! BF_20 - Segment 4: Penalty for using 16x8 or 8x16 MV. */
#define VPU_H1_SWREG300_BF_20(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG300_BF_20_SHIFT)) & VPU_H1_SWREG300_BF_20_MASK)
/*! @} */

/*! @name SWREG301 - VPU H1 Register 301 */
/*! @{ */

#define VPU_H1_SWREG301_BF_0_MASK                (0x1FFU)
#define VPU_H1_SWREG301_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 4: Penalty for using 4x4 MV. */
#define VPU_H1_SWREG301_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG301_BF_0_SHIFT)) & VPU_H1_SWREG301_BF_0_MASK)

#define VPU_H1_SWREG301_BF_20_MASK               (0x3FF00000U)
#define VPU_H1_SWREG301_BF_20_SHIFT              (20U)
/*! BF_20 - Segment 4: Differential MV penalty for 1/4p ME. DMVPenaltyQp */
#define VPU_H1_SWREG301_BF_20(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG301_BF_20_SHIFT)) & VPU_H1_SWREG301_BF_20_MASK)
/*! @} */

/*! @name SWREG302 - VPU H1 Register 302 */
/*! @{ */

#define VPU_H1_SWREG302_BF_0_MASK                (0xFFU)
#define VPU_H1_SWREG302_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 5: Penalty value for second reference frame zero-mv. VP8 golden / H.264 LTR. [0..255] */
#define VPU_H1_SWREG302_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG302_BF_0_SHIFT)) & VPU_H1_SWREG302_BF_0_MASK)

#define VPU_H1_SWREG302_BF_8_MASK                (0xFFFF00U)
#define VPU_H1_SWREG302_BF_8_SHIFT               (8U)
/*! BF_8 - Segment 5: Intra 16x16 mode favor in intra 16x16/4x4 selection */
#define VPU_H1_SWREG302_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG302_BF_8_SHIFT)) & VPU_H1_SWREG302_BF_8_MASK)

#define VPU_H1_SWREG302_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG302_BF_24_SHIFT              (24U)
/*! BF_24 - Segment 5: Intra 4x4 previous mode favor for H.264 */
#define VPU_H1_SWREG302_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG302_BF_24_SHIFT)) & VPU_H1_SWREG302_BF_24_MASK)
/*! @} */

/*! @name SWREG303 - VPU H1 Register 303 */
/*! @{ */

#define VPU_H1_SWREG303_BF_8_MASK                (0xFFFF00U)
#define VPU_H1_SWREG303_BF_8_SHIFT               (8U)
/*! BF_8 - Segment 5: Inter MB mode favor in intra/inter selection */
#define VPU_H1_SWREG303_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG303_BF_8_SHIFT)) & VPU_H1_SWREG303_BF_8_MASK)

#define VPU_H1_SWREG303_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG303_BF_24_SHIFT              (24U)
/*! BF_24 - Segment 5: Skip mode (zero/nearest/near) penalty */
#define VPU_H1_SWREG303_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG303_BF_24_SHIFT)) & VPU_H1_SWREG303_BF_24_MASK)
/*! @} */

/*! @name SWREG304 - VPU H1 Register 304 */
/*! @{ */

#define VPU_H1_SWREG304_BF_0_MASK                (0x3FFU)
#define VPU_H1_SWREG304_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 5: Penalty for using 8x4 or 4x8 MV. */
#define VPU_H1_SWREG304_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG304_BF_0_SHIFT)) & VPU_H1_SWREG304_BF_0_MASK)

#define VPU_H1_SWREG304_BF_10_MASK               (0xFFC00U)
#define VPU_H1_SWREG304_BF_10_SHIFT              (10U)
/*! BF_10 - Segment 5: Penalty for using 8x8 MV. */
#define VPU_H1_SWREG304_BF_10(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG304_BF_10_SHIFT)) & VPU_H1_SWREG304_BF_10_MASK)

#define VPU_H1_SWREG304_BF_20_MASK               (0x3FF00000U)
#define VPU_H1_SWREG304_BF_20_SHIFT              (20U)
/*! BF_20 - Segment 5: Penalty for using 16x8 or 8x16 MV. */
#define VPU_H1_SWREG304_BF_20(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG304_BF_20_SHIFT)) & VPU_H1_SWREG304_BF_20_MASK)
/*! @} */

/*! @name SWREG305 - VPU H1 Register 305 */
/*! @{ */

#define VPU_H1_SWREG305_BF_0_MASK                (0x1FFU)
#define VPU_H1_SWREG305_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 5: Penalty for using 4x4 MV. */
#define VPU_H1_SWREG305_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG305_BF_0_SHIFT)) & VPU_H1_SWREG305_BF_0_MASK)

#define VPU_H1_SWREG305_BF_20_MASK               (0x3FF00000U)
#define VPU_H1_SWREG305_BF_20_SHIFT              (20U)
/*! BF_20 - Segment 5: Differential MV penalty for 1/4p ME. DMVPenaltyQp */
#define VPU_H1_SWREG305_BF_20(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG305_BF_20_SHIFT)) & VPU_H1_SWREG305_BF_20_MASK)
/*! @} */

/*! @name SWREG306 - VPU H1 Register 306 */
/*! @{ */

#define VPU_H1_SWREG306_BF_0_MASK                (0xFFU)
#define VPU_H1_SWREG306_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 6: Penalty value for second reference frame zero-mv. VP8 golden / H.264 LTR. [0..255] */
#define VPU_H1_SWREG306_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG306_BF_0_SHIFT)) & VPU_H1_SWREG306_BF_0_MASK)

#define VPU_H1_SWREG306_BF_8_MASK                (0xFFFF00U)
#define VPU_H1_SWREG306_BF_8_SHIFT               (8U)
/*! BF_8 - Segment 6: Intra 16x16 mode favor in intra 16x16/4x4 selection */
#define VPU_H1_SWREG306_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG306_BF_8_SHIFT)) & VPU_H1_SWREG306_BF_8_MASK)

#define VPU_H1_SWREG306_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG306_BF_24_SHIFT              (24U)
/*! BF_24 - Segment 6: Intra 4x4 previous mode favor for H.264 */
#define VPU_H1_SWREG306_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG306_BF_24_SHIFT)) & VPU_H1_SWREG306_BF_24_MASK)
/*! @} */

/*! @name SWREG307 - VPU H1 Register 307 */
/*! @{ */

#define VPU_H1_SWREG307_BF_8_MASK                (0xFFFF00U)
#define VPU_H1_SWREG307_BF_8_SHIFT               (8U)
/*! BF_8 - Segment 6: Inter MB mode favor in intra/inter selection */
#define VPU_H1_SWREG307_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG307_BF_8_SHIFT)) & VPU_H1_SWREG307_BF_8_MASK)

#define VPU_H1_SWREG307_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG307_BF_24_SHIFT              (24U)
/*! BF_24 - Segment 6: Skip mode (zero/nearest/near) penalty */
#define VPU_H1_SWREG307_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG307_BF_24_SHIFT)) & VPU_H1_SWREG307_BF_24_MASK)
/*! @} */

/*! @name SWREG308 - VPU H1 Register 308 */
/*! @{ */

#define VPU_H1_SWREG308_BF_0_MASK                (0x3FFU)
#define VPU_H1_SWREG308_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 6: Penalty for using 8x4 or 4x8 MV. */
#define VPU_H1_SWREG308_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG308_BF_0_SHIFT)) & VPU_H1_SWREG308_BF_0_MASK)

#define VPU_H1_SWREG308_BF_10_MASK               (0xFFC00U)
#define VPU_H1_SWREG308_BF_10_SHIFT              (10U)
/*! BF_10 - Segment 6: Penalty for using 8x8 MV. */
#define VPU_H1_SWREG308_BF_10(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG308_BF_10_SHIFT)) & VPU_H1_SWREG308_BF_10_MASK)

#define VPU_H1_SWREG308_BF_20_MASK               (0x3FF00000U)
#define VPU_H1_SWREG308_BF_20_SHIFT              (20U)
/*! BF_20 - Segment 6: Penalty for using 16x8 or 8x16 MV. */
#define VPU_H1_SWREG308_BF_20(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG308_BF_20_SHIFT)) & VPU_H1_SWREG308_BF_20_MASK)
/*! @} */

/*! @name SWREG309 - VPU H1 Register 309 */
/*! @{ */

#define VPU_H1_SWREG309_BF_0_MASK                (0x1FFU)
#define VPU_H1_SWREG309_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 6: Penalty for using 4x4 MV. */
#define VPU_H1_SWREG309_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG309_BF_0_SHIFT)) & VPU_H1_SWREG309_BF_0_MASK)

#define VPU_H1_SWREG309_BF_20_MASK               (0x3FF00000U)
#define VPU_H1_SWREG309_BF_20_SHIFT              (20U)
/*! BF_20 - Segment 6: Differential MV penalty for 1/4p ME. DMVPenaltyQp */
#define VPU_H1_SWREG309_BF_20(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG309_BF_20_SHIFT)) & VPU_H1_SWREG309_BF_20_MASK)
/*! @} */

/*! @name SWREG310 - VPU H1 Register 310 */
/*! @{ */

#define VPU_H1_SWREG310_BF_0_MASK                (0xFFU)
#define VPU_H1_SWREG310_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 7: Penalty value for second reference frame zero-mv. VP8 golden / H.264 LTR. [0..255] */
#define VPU_H1_SWREG310_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG310_BF_0_SHIFT)) & VPU_H1_SWREG310_BF_0_MASK)

#define VPU_H1_SWREG310_BF_8_MASK                (0xFFFF00U)
#define VPU_H1_SWREG310_BF_8_SHIFT               (8U)
/*! BF_8 - Segment 7: Intra 16x16 mode favor in intra 16x16/4x4 selection */
#define VPU_H1_SWREG310_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG310_BF_8_SHIFT)) & VPU_H1_SWREG310_BF_8_MASK)

#define VPU_H1_SWREG310_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG310_BF_24_SHIFT              (24U)
/*! BF_24 - Segment 7: Intra 4x4 previous mode favor for H.264 */
#define VPU_H1_SWREG310_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG310_BF_24_SHIFT)) & VPU_H1_SWREG310_BF_24_MASK)
/*! @} */

/*! @name SWREG311 - VPU H1 Register 311 */
/*! @{ */

#define VPU_H1_SWREG311_BF_8_MASK                (0xFFFF00U)
#define VPU_H1_SWREG311_BF_8_SHIFT               (8U)
/*! BF_8 - Segment 7: Inter MB mode favor in intra/inter selection */
#define VPU_H1_SWREG311_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG311_BF_8_SHIFT)) & VPU_H1_SWREG311_BF_8_MASK)

#define VPU_H1_SWREG311_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG311_BF_24_SHIFT              (24U)
/*! BF_24 - Segment 7: Skip mode (zero/nearest/near) penalty */
#define VPU_H1_SWREG311_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG311_BF_24_SHIFT)) & VPU_H1_SWREG311_BF_24_MASK)
/*! @} */

/*! @name SWREG312 - VPU H1 Register 312 */
/*! @{ */

#define VPU_H1_SWREG312_BF_0_MASK                (0x3FFU)
#define VPU_H1_SWREG312_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 7: Penalty for using 8x4 or 4x8 MV. */
#define VPU_H1_SWREG312_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG312_BF_0_SHIFT)) & VPU_H1_SWREG312_BF_0_MASK)

#define VPU_H1_SWREG312_BF_10_MASK               (0xFFC00U)
#define VPU_H1_SWREG312_BF_10_SHIFT              (10U)
/*! BF_10 - Segment 7: Penalty for using 8x8 MV. */
#define VPU_H1_SWREG312_BF_10(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG312_BF_10_SHIFT)) & VPU_H1_SWREG312_BF_10_MASK)

#define VPU_H1_SWREG312_BF_20_MASK               (0x3FF00000U)
#define VPU_H1_SWREG312_BF_20_SHIFT              (20U)
/*! BF_20 - Segment 7: Penalty for using 16x8 or 8x16 MV. */
#define VPU_H1_SWREG312_BF_20(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG312_BF_20_SHIFT)) & VPU_H1_SWREG312_BF_20_MASK)
/*! @} */

/*! @name SWREG313 - VPU H1 Register 313 */
/*! @{ */

#define VPU_H1_SWREG313_BF_0_MASK                (0x1FFU)
#define VPU_H1_SWREG313_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 7: Penalty for using 4x4 MV. */
#define VPU_H1_SWREG313_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG313_BF_0_SHIFT)) & VPU_H1_SWREG313_BF_0_MASK)

#define VPU_H1_SWREG313_BF_20_MASK               (0x3FF00000U)
#define VPU_H1_SWREG313_BF_20_SHIFT              (20U)
/*! BF_20 - Segment 7: Differential MV penalty for 1/4p ME. DMVPenaltyQp */
#define VPU_H1_SWREG313_BF_20(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG313_BF_20_SHIFT)) & VPU_H1_SWREG313_BF_20_MASK)
/*! @} */

/*! @name SWREG314 - VPU H1 Register 314 */
/*! @{ */

#define VPU_H1_SWREG314_BF_0_MASK                (0xFFU)
#define VPU_H1_SWREG314_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 8: Penalty value for second reference frame zero-mv. VP8 golden / H.264 LTR. [0..255] */
#define VPU_H1_SWREG314_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG314_BF_0_SHIFT)) & VPU_H1_SWREG314_BF_0_MASK)

#define VPU_H1_SWREG314_BF_8_MASK                (0xFFFF00U)
#define VPU_H1_SWREG314_BF_8_SHIFT               (8U)
/*! BF_8 - Segment 8: Intra 16x16 mode favor in intra 16x16/4x4 selection */
#define VPU_H1_SWREG314_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG314_BF_8_SHIFT)) & VPU_H1_SWREG314_BF_8_MASK)

#define VPU_H1_SWREG314_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG314_BF_24_SHIFT              (24U)
/*! BF_24 - Segment 8: Intra 4x4 previous mode favor for H.264 */
#define VPU_H1_SWREG314_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG314_BF_24_SHIFT)) & VPU_H1_SWREG314_BF_24_MASK)
/*! @} */

/*! @name SWREG315 - VPU H1 Register 315 */
/*! @{ */

#define VPU_H1_SWREG315_BF_8_MASK                (0xFFFF00U)
#define VPU_H1_SWREG315_BF_8_SHIFT               (8U)
/*! BF_8 - Segment 8: Inter MB mode favor in intra/inter selection */
#define VPU_H1_SWREG315_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG315_BF_8_SHIFT)) & VPU_H1_SWREG315_BF_8_MASK)

#define VPU_H1_SWREG315_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG315_BF_24_SHIFT              (24U)
/*! BF_24 - Segment 8: Skip mode (zero/nearest/near) penalty */
#define VPU_H1_SWREG315_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG315_BF_24_SHIFT)) & VPU_H1_SWREG315_BF_24_MASK)
/*! @} */

/*! @name SWREG316 - VPU H1 Register 316 */
/*! @{ */

#define VPU_H1_SWREG316_BF_0_MASK                (0x3FFU)
#define VPU_H1_SWREG316_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 8: Penalty for using 8x4 or 4x8 MV. */
#define VPU_H1_SWREG316_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG316_BF_0_SHIFT)) & VPU_H1_SWREG316_BF_0_MASK)

#define VPU_H1_SWREG316_BF_10_MASK               (0xFFC00U)
#define VPU_H1_SWREG316_BF_10_SHIFT              (10U)
/*! BF_10 - Segment 8: Penalty for using 8x8 MV. */
#define VPU_H1_SWREG316_BF_10(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG316_BF_10_SHIFT)) & VPU_H1_SWREG316_BF_10_MASK)

#define VPU_H1_SWREG316_BF_20_MASK               (0x3FF00000U)
#define VPU_H1_SWREG316_BF_20_SHIFT              (20U)
/*! BF_20 - Segment 8: Penalty for using 16x8 or 8x16 MV. */
#define VPU_H1_SWREG316_BF_20(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG316_BF_20_SHIFT)) & VPU_H1_SWREG316_BF_20_MASK)
/*! @} */

/*! @name SWREG317 - VPU H1 Register 317 */
/*! @{ */

#define VPU_H1_SWREG317_BF_0_MASK                (0x1FFU)
#define VPU_H1_SWREG317_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 8: Penalty for using 4x4 MV. */
#define VPU_H1_SWREG317_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG317_BF_0_SHIFT)) & VPU_H1_SWREG317_BF_0_MASK)

#define VPU_H1_SWREG317_BF_20_MASK               (0x3FF00000U)
#define VPU_H1_SWREG317_BF_20_SHIFT              (20U)
/*! BF_20 - Segment 8: Differential MV penalty for 1/4p ME. DMVPenaltyQp */
#define VPU_H1_SWREG317_BF_20(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG317_BF_20_SHIFT)) & VPU_H1_SWREG317_BF_20_MASK)
/*! @} */

/*! @name SWREG318 - VPU H1 Register 318 */
/*! @{ */

#define VPU_H1_SWREG318_BF_0_MASK                (0xFFU)
#define VPU_H1_SWREG318_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 9: Penalty value for second reference frame zero-mv. VP8 golden / H.264 LTR. [0..255] */
#define VPU_H1_SWREG318_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG318_BF_0_SHIFT)) & VPU_H1_SWREG318_BF_0_MASK)

#define VPU_H1_SWREG318_BF_8_MASK                (0xFFFF00U)
#define VPU_H1_SWREG318_BF_8_SHIFT               (8U)
/*! BF_8 - Segment 9: Intra 16x16 mode favor in intra 16x16/4x4 selection */
#define VPU_H1_SWREG318_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG318_BF_8_SHIFT)) & VPU_H1_SWREG318_BF_8_MASK)

#define VPU_H1_SWREG318_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG318_BF_24_SHIFT              (24U)
/*! BF_24 - Segment 9: Intra 4x4 previous mode favor for H.264 */
#define VPU_H1_SWREG318_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG318_BF_24_SHIFT)) & VPU_H1_SWREG318_BF_24_MASK)
/*! @} */

/*! @name SWREG319 - VPU H1 Register 319 */
/*! @{ */

#define VPU_H1_SWREG319_BF_8_MASK                (0xFFFF00U)
#define VPU_H1_SWREG319_BF_8_SHIFT               (8U)
/*! BF_8 - Segment 9: Inter MB mode favor in intra/inter selection */
#define VPU_H1_SWREG319_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG319_BF_8_SHIFT)) & VPU_H1_SWREG319_BF_8_MASK)

#define VPU_H1_SWREG319_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG319_BF_24_SHIFT              (24U)
/*! BF_24 - Segment 9: Skip mode (zero/nearest/near) penalty */
#define VPU_H1_SWREG319_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG319_BF_24_SHIFT)) & VPU_H1_SWREG319_BF_24_MASK)
/*! @} */

/*! @name SWREG320 - VPU H1 Register 320 */
/*! @{ */

#define VPU_H1_SWREG320_BF_0_MASK                (0x3FFU)
#define VPU_H1_SWREG320_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 9: Penalty for using 8x4 or 4x8 MV. */
#define VPU_H1_SWREG320_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG320_BF_0_SHIFT)) & VPU_H1_SWREG320_BF_0_MASK)

#define VPU_H1_SWREG320_BF_10_MASK               (0xFFC00U)
#define VPU_H1_SWREG320_BF_10_SHIFT              (10U)
/*! BF_10 - Segment 9: Penalty for using 8x8 MV. */
#define VPU_H1_SWREG320_BF_10(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG320_BF_10_SHIFT)) & VPU_H1_SWREG320_BF_10_MASK)

#define VPU_H1_SWREG320_BF_20_MASK               (0x3FF00000U)
#define VPU_H1_SWREG320_BF_20_SHIFT              (20U)
/*! BF_20 - Segment 9: Penalty for using 16x8 or 8x16 MV. */
#define VPU_H1_SWREG320_BF_20(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG320_BF_20_SHIFT)) & VPU_H1_SWREG320_BF_20_MASK)
/*! @} */

/*! @name SWREG321 - VPU H1 Register 321 */
/*! @{ */

#define VPU_H1_SWREG321_BF_0_MASK                (0x1FFU)
#define VPU_H1_SWREG321_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 9: Penalty for using 4x4 MV. */
#define VPU_H1_SWREG321_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG321_BF_0_SHIFT)) & VPU_H1_SWREG321_BF_0_MASK)

#define VPU_H1_SWREG321_BF_20_MASK               (0x3FF00000U)
#define VPU_H1_SWREG321_BF_20_SHIFT              (20U)
/*! BF_20 - Segment 9: Differential MV penalty for 1/4p ME. DMVPenaltyQp */
#define VPU_H1_SWREG321_BF_20(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG321_BF_20_SHIFT)) & VPU_H1_SWREG321_BF_20_MASK)
/*! @} */

/*! @name SWREG322 - VPU H1 Register 322 */
/*! @{ */

#define VPU_H1_SWREG322_BF_0_MASK                (0xFFU)
#define VPU_H1_SWREG322_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 10: Penalty value for second reference frame zero-mv. VP8 golden / H.264 LTR. [0..255] */
#define VPU_H1_SWREG322_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG322_BF_0_SHIFT)) & VPU_H1_SWREG322_BF_0_MASK)

#define VPU_H1_SWREG322_BF_8_MASK                (0xFFFF00U)
#define VPU_H1_SWREG322_BF_8_SHIFT               (8U)
/*! BF_8 - Segment 10: Intra 16x16 mode favor in intra 16x16/4x4 selection */
#define VPU_H1_SWREG322_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG322_BF_8_SHIFT)) & VPU_H1_SWREG322_BF_8_MASK)

#define VPU_H1_SWREG322_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG322_BF_24_SHIFT              (24U)
/*! BF_24 - Segment 10: Intra 4x4 previous mode favor for H.264 */
#define VPU_H1_SWREG322_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG322_BF_24_SHIFT)) & VPU_H1_SWREG322_BF_24_MASK)
/*! @} */

/*! @name SWREG323 - VPU H1 Register 323 */
/*! @{ */

#define VPU_H1_SWREG323_BF_8_MASK                (0xFFFF00U)
#define VPU_H1_SWREG323_BF_8_SHIFT               (8U)
/*! BF_8 - Segment 10: Inter MB mode favor in intra/inter selection */
#define VPU_H1_SWREG323_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG323_BF_8_SHIFT)) & VPU_H1_SWREG323_BF_8_MASK)

#define VPU_H1_SWREG323_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG323_BF_24_SHIFT              (24U)
/*! BF_24 - Segment 10: Skip mode (zero/nearest/near) penalty */
#define VPU_H1_SWREG323_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG323_BF_24_SHIFT)) & VPU_H1_SWREG323_BF_24_MASK)
/*! @} */

/*! @name SWREG324 - VPU H1 Register 324 */
/*! @{ */

#define VPU_H1_SWREG324_BF_0_MASK                (0x3FFU)
#define VPU_H1_SWREG324_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 10: Penalty for using 8x4 or 4x8 MV. */
#define VPU_H1_SWREG324_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG324_BF_0_SHIFT)) & VPU_H1_SWREG324_BF_0_MASK)

#define VPU_H1_SWREG324_BF_10_MASK               (0xFFC00U)
#define VPU_H1_SWREG324_BF_10_SHIFT              (10U)
/*! BF_10 - Segment 10: Penalty for using 8x8 MV. */
#define VPU_H1_SWREG324_BF_10(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG324_BF_10_SHIFT)) & VPU_H1_SWREG324_BF_10_MASK)

#define VPU_H1_SWREG324_BF_20_MASK               (0x3FF00000U)
#define VPU_H1_SWREG324_BF_20_SHIFT              (20U)
/*! BF_20 - Segment 10: Penalty for using 16x8 or 8x16 MV. */
#define VPU_H1_SWREG324_BF_20(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG324_BF_20_SHIFT)) & VPU_H1_SWREG324_BF_20_MASK)
/*! @} */

/*! @name SWREG325 - VPU H1 Register 325 */
/*! @{ */

#define VPU_H1_SWREG325_BF_0_MASK                (0x1FFU)
#define VPU_H1_SWREG325_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 10: Penalty for using 4x4 MV. */
#define VPU_H1_SWREG325_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG325_BF_0_SHIFT)) & VPU_H1_SWREG325_BF_0_MASK)

#define VPU_H1_SWREG325_BF_20_MASK               (0x3FF00000U)
#define VPU_H1_SWREG325_BF_20_SHIFT              (20U)
/*! BF_20 - Segment 10: Differential MV penalty for 1/4p ME. DMVPenaltyQp */
#define VPU_H1_SWREG325_BF_20(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG325_BF_20_SHIFT)) & VPU_H1_SWREG325_BF_20_MASK)
/*! @} */

/*! @name SWREG326 - VPU H1 Register 326 */
/*! @{ */

#define VPU_H1_SWREG326_BF_0_MASK                (0xFFU)
#define VPU_H1_SWREG326_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 11: Penalty value for second reference frame zero-mv. VP8 golden / H.264 LTR. [0..255] */
#define VPU_H1_SWREG326_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG326_BF_0_SHIFT)) & VPU_H1_SWREG326_BF_0_MASK)

#define VPU_H1_SWREG326_BF_8_MASK                (0xFFFF00U)
#define VPU_H1_SWREG326_BF_8_SHIFT               (8U)
/*! BF_8 - Segment 11: Intra 16x16 mode favor in intra 16x16/4x4 selection */
#define VPU_H1_SWREG326_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG326_BF_8_SHIFT)) & VPU_H1_SWREG326_BF_8_MASK)

#define VPU_H1_SWREG326_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG326_BF_24_SHIFT              (24U)
/*! BF_24 - Segment 11: Intra 4x4 previous mode favor for H.264 */
#define VPU_H1_SWREG326_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG326_BF_24_SHIFT)) & VPU_H1_SWREG326_BF_24_MASK)
/*! @} */

/*! @name SWREG327 - VPU H1 Register 327 */
/*! @{ */

#define VPU_H1_SWREG327_BF_8_MASK                (0xFFFF00U)
#define VPU_H1_SWREG327_BF_8_SHIFT               (8U)
/*! BF_8 - Segment 11: Inter MB mode favor in intra/inter selection */
#define VPU_H1_SWREG327_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG327_BF_8_SHIFT)) & VPU_H1_SWREG327_BF_8_MASK)

#define VPU_H1_SWREG327_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG327_BF_24_SHIFT              (24U)
/*! BF_24 - Segment 11: Skip mode (zero/nearest/near) penalty */
#define VPU_H1_SWREG327_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG327_BF_24_SHIFT)) & VPU_H1_SWREG327_BF_24_MASK)
/*! @} */

/*! @name SWREG328 - VPU H1 Register 328 */
/*! @{ */

#define VPU_H1_SWREG328_BF_0_MASK                (0x3FFU)
#define VPU_H1_SWREG328_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 11: Penalty for using 8x4 or 4x8 MV. */
#define VPU_H1_SWREG328_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG328_BF_0_SHIFT)) & VPU_H1_SWREG328_BF_0_MASK)

#define VPU_H1_SWREG328_BF_10_MASK               (0xFFC00U)
#define VPU_H1_SWREG328_BF_10_SHIFT              (10U)
/*! BF_10 - Segment 11: Penalty for using 8x8 MV. */
#define VPU_H1_SWREG328_BF_10(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG328_BF_10_SHIFT)) & VPU_H1_SWREG328_BF_10_MASK)

#define VPU_H1_SWREG328_BF_20_MASK               (0x3FF00000U)
#define VPU_H1_SWREG328_BF_20_SHIFT              (20U)
/*! BF_20 - Segment 11: Penalty for using 16x8 or 8x16 MV. */
#define VPU_H1_SWREG328_BF_20(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG328_BF_20_SHIFT)) & VPU_H1_SWREG328_BF_20_MASK)
/*! @} */

/*! @name SWREG329 - VPU H1 Register 329 */
/*! @{ */

#define VPU_H1_SWREG329_BF_0_MASK                (0x1FFU)
#define VPU_H1_SWREG329_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 11: Penalty for using 4x4 MV. */
#define VPU_H1_SWREG329_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG329_BF_0_SHIFT)) & VPU_H1_SWREG329_BF_0_MASK)

#define VPU_H1_SWREG329_BF_20_MASK               (0x3FF00000U)
#define VPU_H1_SWREG329_BF_20_SHIFT              (20U)
/*! BF_20 - Segment 11: Differential MV penalty for 1/4p ME. DMVPenaltyQp */
#define VPU_H1_SWREG329_BF_20(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG329_BF_20_SHIFT)) & VPU_H1_SWREG329_BF_20_MASK)
/*! @} */

/*! @name SWREG330 - VPU H1 Register 330 */
/*! @{ */

#define VPU_H1_SWREG330_BF_0_MASK                (0xFFU)
#define VPU_H1_SWREG330_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 12: Penalty value for second reference frame zero-mv. VP8 golden / H.264 LTR. [0..255] */
#define VPU_H1_SWREG330_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG330_BF_0_SHIFT)) & VPU_H1_SWREG330_BF_0_MASK)

#define VPU_H1_SWREG330_BF_8_MASK                (0xFFFF00U)
#define VPU_H1_SWREG330_BF_8_SHIFT               (8U)
/*! BF_8 - Segment 12: Intra 16x16 mode favor in intra 16x16/4x4 selection */
#define VPU_H1_SWREG330_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG330_BF_8_SHIFT)) & VPU_H1_SWREG330_BF_8_MASK)

#define VPU_H1_SWREG330_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG330_BF_24_SHIFT              (24U)
/*! BF_24 - Segment 12: Intra 4x4 previous mode favor for H.264 */
#define VPU_H1_SWREG330_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG330_BF_24_SHIFT)) & VPU_H1_SWREG330_BF_24_MASK)
/*! @} */

/*! @name SWREG331 - VPU H1 Register 331 */
/*! @{ */

#define VPU_H1_SWREG331_BF_8_MASK                (0xFFFF00U)
#define VPU_H1_SWREG331_BF_8_SHIFT               (8U)
/*! BF_8 - Segment 12: Inter MB mode favor in intra/inter selection */
#define VPU_H1_SWREG331_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG331_BF_8_SHIFT)) & VPU_H1_SWREG331_BF_8_MASK)

#define VPU_H1_SWREG331_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG331_BF_24_SHIFT              (24U)
/*! BF_24 - Segment 12: Skip mode (zero/nearest/near) penalty */
#define VPU_H1_SWREG331_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG331_BF_24_SHIFT)) & VPU_H1_SWREG331_BF_24_MASK)
/*! @} */

/*! @name SWREG332 - VPU H1 Register 332 */
/*! @{ */

#define VPU_H1_SWREG332_BF_0_MASK                (0x3FFU)
#define VPU_H1_SWREG332_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 12: Penalty for using 8x4 or 4x8 MV. */
#define VPU_H1_SWREG332_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG332_BF_0_SHIFT)) & VPU_H1_SWREG332_BF_0_MASK)

#define VPU_H1_SWREG332_BF_10_MASK               (0xFFC00U)
#define VPU_H1_SWREG332_BF_10_SHIFT              (10U)
/*! BF_10 - Segment 12: Penalty for using 8x8 MV. */
#define VPU_H1_SWREG332_BF_10(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG332_BF_10_SHIFT)) & VPU_H1_SWREG332_BF_10_MASK)

#define VPU_H1_SWREG332_BF_20_MASK               (0x3FF00000U)
#define VPU_H1_SWREG332_BF_20_SHIFT              (20U)
/*! BF_20 - Segment 12: Penalty for using 16x8 or 8x16 MV. */
#define VPU_H1_SWREG332_BF_20(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG332_BF_20_SHIFT)) & VPU_H1_SWREG332_BF_20_MASK)
/*! @} */

/*! @name SWREG333 - VPU H1 Register 333 */
/*! @{ */

#define VPU_H1_SWREG333_BF_0_MASK                (0x1FFU)
#define VPU_H1_SWREG333_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 12: Penalty for using 4x4 MV. */
#define VPU_H1_SWREG333_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG333_BF_0_SHIFT)) & VPU_H1_SWREG333_BF_0_MASK)

#define VPU_H1_SWREG333_BF_20_MASK               (0x3FF00000U)
#define VPU_H1_SWREG333_BF_20_SHIFT              (20U)
/*! BF_20 - Segment 12: Differential MV penalty for 1/4p ME. DMVPenaltyQp */
#define VPU_H1_SWREG333_BF_20(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG333_BF_20_SHIFT)) & VPU_H1_SWREG333_BF_20_MASK)
/*! @} */

/*! @name SWREG334 - VPU H1 Register 334 */
/*! @{ */

#define VPU_H1_SWREG334_BF_0_MASK                (0xFFU)
#define VPU_H1_SWREG334_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 13: Penalty value for second reference frame zero-mv. VP8 golden / H.264 LTR. [0..255] */
#define VPU_H1_SWREG334_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG334_BF_0_SHIFT)) & VPU_H1_SWREG334_BF_0_MASK)

#define VPU_H1_SWREG334_BF_8_MASK                (0xFFFF00U)
#define VPU_H1_SWREG334_BF_8_SHIFT               (8U)
/*! BF_8 - Segment 13: Intra 16x16 mode favor in intra 16x16/4x4 selection */
#define VPU_H1_SWREG334_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG334_BF_8_SHIFT)) & VPU_H1_SWREG334_BF_8_MASK)

#define VPU_H1_SWREG334_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG334_BF_24_SHIFT              (24U)
/*! BF_24 - Segment 13: Intra 4x4 previous mode favor for H.264 */
#define VPU_H1_SWREG334_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG334_BF_24_SHIFT)) & VPU_H1_SWREG334_BF_24_MASK)
/*! @} */

/*! @name SWREG335 - VPU H1 Register 335 */
/*! @{ */

#define VPU_H1_SWREG335_BF_8_MASK                (0xFFFF00U)
#define VPU_H1_SWREG335_BF_8_SHIFT               (8U)
/*! BF_8 - Segment 13: Inter MB mode favor in intra/inter selection */
#define VPU_H1_SWREG335_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG335_BF_8_SHIFT)) & VPU_H1_SWREG335_BF_8_MASK)

#define VPU_H1_SWREG335_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG335_BF_24_SHIFT              (24U)
/*! BF_24 - Segment 13: Skip mode (zero/nearest/near) penalty */
#define VPU_H1_SWREG335_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG335_BF_24_SHIFT)) & VPU_H1_SWREG335_BF_24_MASK)
/*! @} */

/*! @name SWREG336 - VPU H1 Register 336 */
/*! @{ */

#define VPU_H1_SWREG336_BF_0_MASK                (0x3FFU)
#define VPU_H1_SWREG336_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 13: Penalty for using 8x4 or 4x8 MV. */
#define VPU_H1_SWREG336_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG336_BF_0_SHIFT)) & VPU_H1_SWREG336_BF_0_MASK)

#define VPU_H1_SWREG336_BF_10_MASK               (0xFFC00U)
#define VPU_H1_SWREG336_BF_10_SHIFT              (10U)
/*! BF_10 - Segment 13: Penalty for using 8x8 MV. */
#define VPU_H1_SWREG336_BF_10(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG336_BF_10_SHIFT)) & VPU_H1_SWREG336_BF_10_MASK)

#define VPU_H1_SWREG336_BF_20_MASK               (0x3FF00000U)
#define VPU_H1_SWREG336_BF_20_SHIFT              (20U)
/*! BF_20 - Segment 13: Penalty for using 16x8 or 8x16 MV. */
#define VPU_H1_SWREG336_BF_20(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG336_BF_20_SHIFT)) & VPU_H1_SWREG336_BF_20_MASK)
/*! @} */

/*! @name SWREG337 - VPU H1 Register 337 */
/*! @{ */

#define VPU_H1_SWREG337_BF_0_MASK                (0x1FFU)
#define VPU_H1_SWREG337_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 13: Penalty for using 4x4 MV. */
#define VPU_H1_SWREG337_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG337_BF_0_SHIFT)) & VPU_H1_SWREG337_BF_0_MASK)

#define VPU_H1_SWREG337_BF_20_MASK               (0x3FF00000U)
#define VPU_H1_SWREG337_BF_20_SHIFT              (20U)
/*! BF_20 - Segment 13: Differential MV penalty for 1/4p ME. DMVPenaltyQp */
#define VPU_H1_SWREG337_BF_20(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG337_BF_20_SHIFT)) & VPU_H1_SWREG337_BF_20_MASK)
/*! @} */

/*! @name SWREG338 - VPU H1 Register 338 */
/*! @{ */

#define VPU_H1_SWREG338_BF_0_MASK                (0xFFU)
#define VPU_H1_SWREG338_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 14: Penalty value for second reference frame zero-mv. VP8 golden / H.264 LTR. [0..255] */
#define VPU_H1_SWREG338_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG338_BF_0_SHIFT)) & VPU_H1_SWREG338_BF_0_MASK)

#define VPU_H1_SWREG338_BF_8_MASK                (0xFFFF00U)
#define VPU_H1_SWREG338_BF_8_SHIFT               (8U)
/*! BF_8 - Segment 14: Intra 16x16 mode favor in intra 16x16/4x4 selection */
#define VPU_H1_SWREG338_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG338_BF_8_SHIFT)) & VPU_H1_SWREG338_BF_8_MASK)

#define VPU_H1_SWREG338_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG338_BF_24_SHIFT              (24U)
/*! BF_24 - Segment 14: Intra 4x4 previous mode favor for H.264 */
#define VPU_H1_SWREG338_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG338_BF_24_SHIFT)) & VPU_H1_SWREG338_BF_24_MASK)
/*! @} */

/*! @name SWREG339 - VPU H1 Register 339 */
/*! @{ */

#define VPU_H1_SWREG339_BF_8_MASK                (0xFFFF00U)
#define VPU_H1_SWREG339_BF_8_SHIFT               (8U)
/*! BF_8 - Segment 14: Inter MB mode favor in intra/inter selection */
#define VPU_H1_SWREG339_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG339_BF_8_SHIFT)) & VPU_H1_SWREG339_BF_8_MASK)

#define VPU_H1_SWREG339_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG339_BF_24_SHIFT              (24U)
/*! BF_24 - Segment 14: Skip mode (zero/nearest/near) penalty */
#define VPU_H1_SWREG339_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG339_BF_24_SHIFT)) & VPU_H1_SWREG339_BF_24_MASK)
/*! @} */

/*! @name SWREG340 - VPU H1 Register 340 */
/*! @{ */

#define VPU_H1_SWREG340_BF_0_MASK                (0x3FFU)
#define VPU_H1_SWREG340_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 14: Penalty for using 8x4 or 4x8 MV. */
#define VPU_H1_SWREG340_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG340_BF_0_SHIFT)) & VPU_H1_SWREG340_BF_0_MASK)

#define VPU_H1_SWREG340_BF_10_MASK               (0xFFC00U)
#define VPU_H1_SWREG340_BF_10_SHIFT              (10U)
/*! BF_10 - Segment 14: Penalty for using 8x8 MV. */
#define VPU_H1_SWREG340_BF_10(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG340_BF_10_SHIFT)) & VPU_H1_SWREG340_BF_10_MASK)

#define VPU_H1_SWREG340_BF_20_MASK               (0x3FF00000U)
#define VPU_H1_SWREG340_BF_20_SHIFT              (20U)
/*! BF_20 - Segment 14: Penalty for using 16x8 or 8x16 MV. */
#define VPU_H1_SWREG340_BF_20(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG340_BF_20_SHIFT)) & VPU_H1_SWREG340_BF_20_MASK)
/*! @} */

/*! @name SWREG341 - VPU H1 Register 341 */
/*! @{ */

#define VPU_H1_SWREG341_BF_0_MASK                (0x1FFU)
#define VPU_H1_SWREG341_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 14: Penalty for using 4x4 MV. */
#define VPU_H1_SWREG341_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG341_BF_0_SHIFT)) & VPU_H1_SWREG341_BF_0_MASK)

#define VPU_H1_SWREG341_BF_20_MASK               (0x3FF00000U)
#define VPU_H1_SWREG341_BF_20_SHIFT              (20U)
/*! BF_20 - Segment 14: Differential MV penalty for 1/4p ME. DMVPenaltyQp */
#define VPU_H1_SWREG341_BF_20(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG341_BF_20_SHIFT)) & VPU_H1_SWREG341_BF_20_MASK)
/*! @} */

/*! @name SWREG342 - VPU H1 Register 342 */
/*! @{ */

#define VPU_H1_SWREG342_BF_0_MASK                (0xFFU)
#define VPU_H1_SWREG342_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 15: Penalty value for second reference frame zero-mv. VP8 golden / H.264 LTR. [0..255] */
#define VPU_H1_SWREG342_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG342_BF_0_SHIFT)) & VPU_H1_SWREG342_BF_0_MASK)

#define VPU_H1_SWREG342_BF_8_MASK                (0xFFFF00U)
#define VPU_H1_SWREG342_BF_8_SHIFT               (8U)
/*! BF_8 - Segment 15: Intra 16x16 mode favor in intra 16x16/4x4 selection */
#define VPU_H1_SWREG342_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG342_BF_8_SHIFT)) & VPU_H1_SWREG342_BF_8_MASK)

#define VPU_H1_SWREG342_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG342_BF_24_SHIFT              (24U)
/*! BF_24 - Segment 15: Intra 4x4 previous mode favor for H.264 */
#define VPU_H1_SWREG342_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG342_BF_24_SHIFT)) & VPU_H1_SWREG342_BF_24_MASK)
/*! @} */

/*! @name SWREG343 - VPU H1 Register 343 */
/*! @{ */

#define VPU_H1_SWREG343_BF_8_MASK                (0xFFFF00U)
#define VPU_H1_SWREG343_BF_8_SHIFT               (8U)
/*! BF_8 - Segment 15: Inter MB mode favor in intra/inter selection */
#define VPU_H1_SWREG343_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG343_BF_8_SHIFT)) & VPU_H1_SWREG343_BF_8_MASK)

#define VPU_H1_SWREG343_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG343_BF_24_SHIFT              (24U)
/*! BF_24 - Segment 15: Skip mode (zero/nearest/near) penalty */
#define VPU_H1_SWREG343_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG343_BF_24_SHIFT)) & VPU_H1_SWREG343_BF_24_MASK)
/*! @} */

/*! @name SWREG344 - VPU H1 Register 344 */
/*! @{ */

#define VPU_H1_SWREG344_BF_0_MASK                (0x3FFU)
#define VPU_H1_SWREG344_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 15: Penalty for using 8x4 or 4x8 MV. */
#define VPU_H1_SWREG344_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG344_BF_0_SHIFT)) & VPU_H1_SWREG344_BF_0_MASK)

#define VPU_H1_SWREG344_BF_10_MASK               (0xFFC00U)
#define VPU_H1_SWREG344_BF_10_SHIFT              (10U)
/*! BF_10 - Segment 15: Penalty for using 8x8 MV. */
#define VPU_H1_SWREG344_BF_10(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG344_BF_10_SHIFT)) & VPU_H1_SWREG344_BF_10_MASK)

#define VPU_H1_SWREG344_BF_20_MASK               (0x3FF00000U)
#define VPU_H1_SWREG344_BF_20_SHIFT              (20U)
/*! BF_20 - Segment 15: Penalty for using 16x8 or 8x16 MV. */
#define VPU_H1_SWREG344_BF_20(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG344_BF_20_SHIFT)) & VPU_H1_SWREG344_BF_20_MASK)
/*! @} */

/*! @name SWREG345 - VPU H1 Register 345 */
/*! @{ */

#define VPU_H1_SWREG345_BF_0_MASK                (0x1FFU)
#define VPU_H1_SWREG345_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 15: Penalty for using 4x4 MV. */
#define VPU_H1_SWREG345_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG345_BF_0_SHIFT)) & VPU_H1_SWREG345_BF_0_MASK)

#define VPU_H1_SWREG345_BF_20_MASK               (0x3FF00000U)
#define VPU_H1_SWREG345_BF_20_SHIFT              (20U)
/*! BF_20 - Segment 15: Differential MV penalty for 1/4p ME. DMVPenaltyQp */
#define VPU_H1_SWREG345_BF_20(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG345_BF_20_SHIFT)) & VPU_H1_SWREG345_BF_20_MASK)
/*! @} */

/*! @name SWREG346 - VPU H1 Register 346 */
/*! @{ */

#define VPU_H1_SWREG346_BF_0_MASK                (0xFFU)
#define VPU_H1_SWREG346_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 16: Penalty value for second reference frame zero-mv. VP8 golden / H.264 LTR. [0..255] */
#define VPU_H1_SWREG346_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG346_BF_0_SHIFT)) & VPU_H1_SWREG346_BF_0_MASK)

#define VPU_H1_SWREG346_BF_8_MASK                (0xFFFF00U)
#define VPU_H1_SWREG346_BF_8_SHIFT               (8U)
/*! BF_8 - Segment 16: Intra 16x16 mode favor in intra 16x16/4x4 selection */
#define VPU_H1_SWREG346_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG346_BF_8_SHIFT)) & VPU_H1_SWREG346_BF_8_MASK)

#define VPU_H1_SWREG346_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG346_BF_24_SHIFT              (24U)
/*! BF_24 - Segment 16: Intra 4x4 previous mode favor for H.264 */
#define VPU_H1_SWREG346_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG346_BF_24_SHIFT)) & VPU_H1_SWREG346_BF_24_MASK)
/*! @} */

/*! @name SWREG347 - VPU H1 Register 347 */
/*! @{ */

#define VPU_H1_SWREG347_BF_8_MASK                (0xFFFF00U)
#define VPU_H1_SWREG347_BF_8_SHIFT               (8U)
/*! BF_8 - Segment 16: Inter MB mode favor in intra/inter selection */
#define VPU_H1_SWREG347_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG347_BF_8_SHIFT)) & VPU_H1_SWREG347_BF_8_MASK)

#define VPU_H1_SWREG347_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG347_BF_24_SHIFT              (24U)
/*! BF_24 - Segment 16: Skip mode (zero/nearest/near) penalty */
#define VPU_H1_SWREG347_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG347_BF_24_SHIFT)) & VPU_H1_SWREG347_BF_24_MASK)
/*! @} */

/*! @name SWREG348 - VPU H1 Register 348 */
/*! @{ */

#define VPU_H1_SWREG348_BF_0_MASK                (0x3FFU)
#define VPU_H1_SWREG348_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 16: Penalty for using 8x4 or 4x8 MV. */
#define VPU_H1_SWREG348_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG348_BF_0_SHIFT)) & VPU_H1_SWREG348_BF_0_MASK)

#define VPU_H1_SWREG348_BF_10_MASK               (0xFFC00U)
#define VPU_H1_SWREG348_BF_10_SHIFT              (10U)
/*! BF_10 - Segment 16: Penalty for using 8x8 MV. */
#define VPU_H1_SWREG348_BF_10(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG348_BF_10_SHIFT)) & VPU_H1_SWREG348_BF_10_MASK)

#define VPU_H1_SWREG348_BF_20_MASK               (0x3FF00000U)
#define VPU_H1_SWREG348_BF_20_SHIFT              (20U)
/*! BF_20 - Segment 16: Penalty for using 16x8 or 8x16 MV. */
#define VPU_H1_SWREG348_BF_20(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG348_BF_20_SHIFT)) & VPU_H1_SWREG348_BF_20_MASK)
/*! @} */

/*! @name SWREG349 - VPU H1 Register 349 */
/*! @{ */

#define VPU_H1_SWREG349_BF_0_MASK                (0x1FFU)
#define VPU_H1_SWREG349_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 16: Penalty for using 4x4 MV. */
#define VPU_H1_SWREG349_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG349_BF_0_SHIFT)) & VPU_H1_SWREG349_BF_0_MASK)

#define VPU_H1_SWREG349_BF_20_MASK               (0x3FF00000U)
#define VPU_H1_SWREG349_BF_20_SHIFT              (20U)
/*! BF_20 - Segment 16: Differential MV penalty for 1/4p ME. DMVPenaltyQp */
#define VPU_H1_SWREG349_BF_20(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG349_BF_20_SHIFT)) & VPU_H1_SWREG349_BF_20_MASK)
/*! @} */

/*! @name SWREG350 - VPU H1 Register 350 */
/*! @{ */

#define VPU_H1_SWREG350_BF_0_MASK                (0xFFU)
#define VPU_H1_SWREG350_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 17: Penalty value for second reference frame zero-mv. VP8 golden / H.264 LTR. [0..255] */
#define VPU_H1_SWREG350_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG350_BF_0_SHIFT)) & VPU_H1_SWREG350_BF_0_MASK)

#define VPU_H1_SWREG350_BF_8_MASK                (0xFFFF00U)
#define VPU_H1_SWREG350_BF_8_SHIFT               (8U)
/*! BF_8 - Segment 17: Intra 16x16 mode favor in intra 16x16/4x4 selection */
#define VPU_H1_SWREG350_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG350_BF_8_SHIFT)) & VPU_H1_SWREG350_BF_8_MASK)

#define VPU_H1_SWREG350_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG350_BF_24_SHIFT              (24U)
/*! BF_24 - Segment 17: Intra 4x4 previous mode favor for H.264 */
#define VPU_H1_SWREG350_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG350_BF_24_SHIFT)) & VPU_H1_SWREG350_BF_24_MASK)
/*! @} */

/*! @name SWREG351 - VPU H1 Register 351 */
/*! @{ */

#define VPU_H1_SWREG351_BF_8_MASK                (0xFFFF00U)
#define VPU_H1_SWREG351_BF_8_SHIFT               (8U)
/*! BF_8 - Segment 17: Inter MB mode favor in intra/inter selection */
#define VPU_H1_SWREG351_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG351_BF_8_SHIFT)) & VPU_H1_SWREG351_BF_8_MASK)

#define VPU_H1_SWREG351_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG351_BF_24_SHIFT              (24U)
/*! BF_24 - Segment 17: Skip mode (zero/nearest/near) penalty */
#define VPU_H1_SWREG351_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG351_BF_24_SHIFT)) & VPU_H1_SWREG351_BF_24_MASK)
/*! @} */

/*! @name SWREG352 - VPU H1 Register 352 */
/*! @{ */

#define VPU_H1_SWREG352_BF_0_MASK                (0x3FFU)
#define VPU_H1_SWREG352_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 17: Penalty for using 8x4 or 4x8 MV. */
#define VPU_H1_SWREG352_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG352_BF_0_SHIFT)) & VPU_H1_SWREG352_BF_0_MASK)

#define VPU_H1_SWREG352_BF_10_MASK               (0xFFC00U)
#define VPU_H1_SWREG352_BF_10_SHIFT              (10U)
/*! BF_10 - Segment 17: Penalty for using 8x8 MV. */
#define VPU_H1_SWREG352_BF_10(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG352_BF_10_SHIFT)) & VPU_H1_SWREG352_BF_10_MASK)

#define VPU_H1_SWREG352_BF_20_MASK               (0x3FF00000U)
#define VPU_H1_SWREG352_BF_20_SHIFT              (20U)
/*! BF_20 - Segment 17: Penalty for using 16x8 or 8x16 MV. */
#define VPU_H1_SWREG352_BF_20(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG352_BF_20_SHIFT)) & VPU_H1_SWREG352_BF_20_MASK)
/*! @} */

/*! @name SWREG353 - VPU H1 Register 353 */
/*! @{ */

#define VPU_H1_SWREG353_BF_0_MASK                (0x1FFU)
#define VPU_H1_SWREG353_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 17: Penalty for using 4x4 MV. */
#define VPU_H1_SWREG353_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG353_BF_0_SHIFT)) & VPU_H1_SWREG353_BF_0_MASK)

#define VPU_H1_SWREG353_BF_20_MASK               (0x3FF00000U)
#define VPU_H1_SWREG353_BF_20_SHIFT              (20U)
/*! BF_20 - Segment 17: Differential MV penalty for 1/4p ME. DMVPenaltyQp */
#define VPU_H1_SWREG353_BF_20(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG353_BF_20_SHIFT)) & VPU_H1_SWREG353_BF_20_MASK)
/*! @} */

/*! @name SWREG354 - VPU H1 Register 354 */
/*! @{ */

#define VPU_H1_SWREG354_BF_0_MASK                (0xFFU)
#define VPU_H1_SWREG354_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 18: Penalty value for second reference frame zero-mv. VP8 golden / H.264 LTR. [0..255] */
#define VPU_H1_SWREG354_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG354_BF_0_SHIFT)) & VPU_H1_SWREG354_BF_0_MASK)

#define VPU_H1_SWREG354_BF_8_MASK                (0xFFFF00U)
#define VPU_H1_SWREG354_BF_8_SHIFT               (8U)
/*! BF_8 - Segment 18: Intra 16x16 mode favor in intra 16x16/4x4 selection */
#define VPU_H1_SWREG354_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG354_BF_8_SHIFT)) & VPU_H1_SWREG354_BF_8_MASK)

#define VPU_H1_SWREG354_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG354_BF_24_SHIFT              (24U)
/*! BF_24 - Segment 18: Intra 4x4 previous mode favor for H.264 */
#define VPU_H1_SWREG354_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG354_BF_24_SHIFT)) & VPU_H1_SWREG354_BF_24_MASK)
/*! @} */

/*! @name SWREG355 - VPU H1 Register 355 */
/*! @{ */

#define VPU_H1_SWREG355_BF_8_MASK                (0xFFFF00U)
#define VPU_H1_SWREG355_BF_8_SHIFT               (8U)
/*! BF_8 - Segment 18: Inter MB mode favor in intra/inter selection */
#define VPU_H1_SWREG355_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG355_BF_8_SHIFT)) & VPU_H1_SWREG355_BF_8_MASK)

#define VPU_H1_SWREG355_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG355_BF_24_SHIFT              (24U)
/*! BF_24 - Segment 18: Skip mode (zero/nearest/near) penalty */
#define VPU_H1_SWREG355_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG355_BF_24_SHIFT)) & VPU_H1_SWREG355_BF_24_MASK)
/*! @} */

/*! @name SWREG356 - VPU H1 Register 356 */
/*! @{ */

#define VPU_H1_SWREG356_BF_0_MASK                (0x3FFU)
#define VPU_H1_SWREG356_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 18: Penalty for using 8x4 or 4x8 MV. */
#define VPU_H1_SWREG356_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG356_BF_0_SHIFT)) & VPU_H1_SWREG356_BF_0_MASK)

#define VPU_H1_SWREG356_BF_10_MASK               (0xFFC00U)
#define VPU_H1_SWREG356_BF_10_SHIFT              (10U)
/*! BF_10 - Segment 18: Penalty for using 8x8 MV. */
#define VPU_H1_SWREG356_BF_10(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG356_BF_10_SHIFT)) & VPU_H1_SWREG356_BF_10_MASK)

#define VPU_H1_SWREG356_BF_20_MASK               (0x3FF00000U)
#define VPU_H1_SWREG356_BF_20_SHIFT              (20U)
/*! BF_20 - Segment 18: Penalty for using 16x8 or 8x16 MV. */
#define VPU_H1_SWREG356_BF_20(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG356_BF_20_SHIFT)) & VPU_H1_SWREG356_BF_20_MASK)
/*! @} */

/*! @name SWREG357 - VPU H1 Register 357 */
/*! @{ */

#define VPU_H1_SWREG357_BF_0_MASK                (0x1FFU)
#define VPU_H1_SWREG357_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 18: Penalty for using 4x4 MV. */
#define VPU_H1_SWREG357_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG357_BF_0_SHIFT)) & VPU_H1_SWREG357_BF_0_MASK)

#define VPU_H1_SWREG357_BF_20_MASK               (0x3FF00000U)
#define VPU_H1_SWREG357_BF_20_SHIFT              (20U)
/*! BF_20 - Segment 18: Differential MV penalty for 1/4p ME. DMVPenaltyQp */
#define VPU_H1_SWREG357_BF_20(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG357_BF_20_SHIFT)) & VPU_H1_SWREG357_BF_20_MASK)
/*! @} */

/*! @name SWREG358 - VPU H1 Register 358 */
/*! @{ */

#define VPU_H1_SWREG358_BF_0_MASK                (0xFFU)
#define VPU_H1_SWREG358_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 19: Penalty value for second reference frame zero-mv. VP8 golden / H.264 LTR. [0..255] */
#define VPU_H1_SWREG358_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG358_BF_0_SHIFT)) & VPU_H1_SWREG358_BF_0_MASK)

#define VPU_H1_SWREG358_BF_8_MASK                (0xFFFF00U)
#define VPU_H1_SWREG358_BF_8_SHIFT               (8U)
/*! BF_8 - Segment 19: Intra 16x16 mode favor in intra 16x16/4x4 selection */
#define VPU_H1_SWREG358_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG358_BF_8_SHIFT)) & VPU_H1_SWREG358_BF_8_MASK)

#define VPU_H1_SWREG358_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG358_BF_24_SHIFT              (24U)
/*! BF_24 - Segment 19: Intra 4x4 previous mode favor for H.264 */
#define VPU_H1_SWREG358_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG358_BF_24_SHIFT)) & VPU_H1_SWREG358_BF_24_MASK)
/*! @} */

/*! @name SWREG359 - VPU H1 Register 359 */
/*! @{ */

#define VPU_H1_SWREG359_BF_8_MASK                (0xFFFF00U)
#define VPU_H1_SWREG359_BF_8_SHIFT               (8U)
/*! BF_8 - Segment 19: Inter MB mode favor in intra/inter selection */
#define VPU_H1_SWREG359_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG359_BF_8_SHIFT)) & VPU_H1_SWREG359_BF_8_MASK)

#define VPU_H1_SWREG359_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG359_BF_24_SHIFT              (24U)
/*! BF_24 - Segment 19: Skip mode (zero/nearest/near) penalty */
#define VPU_H1_SWREG359_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG359_BF_24_SHIFT)) & VPU_H1_SWREG359_BF_24_MASK)
/*! @} */

/*! @name SWREG360 - VPU H1 Register 360 */
/*! @{ */

#define VPU_H1_SWREG360_BF_0_MASK                (0x3FFU)
#define VPU_H1_SWREG360_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 19: Penalty for using 8x4 or 4x8 MV. */
#define VPU_H1_SWREG360_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG360_BF_0_SHIFT)) & VPU_H1_SWREG360_BF_0_MASK)

#define VPU_H1_SWREG360_BF_10_MASK               (0xFFC00U)
#define VPU_H1_SWREG360_BF_10_SHIFT              (10U)
/*! BF_10 - Segment 19: Penalty for using 8x8 MV. */
#define VPU_H1_SWREG360_BF_10(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG360_BF_10_SHIFT)) & VPU_H1_SWREG360_BF_10_MASK)

#define VPU_H1_SWREG360_BF_20_MASK               (0x3FF00000U)
#define VPU_H1_SWREG360_BF_20_SHIFT              (20U)
/*! BF_20 - Segment 19: Penalty for using 16x8 or 8x16 MV. */
#define VPU_H1_SWREG360_BF_20(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG360_BF_20_SHIFT)) & VPU_H1_SWREG360_BF_20_MASK)
/*! @} */

/*! @name SWREG361 - VPU H1 Register 361 */
/*! @{ */

#define VPU_H1_SWREG361_BF_0_MASK                (0x1FFU)
#define VPU_H1_SWREG361_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 19: Penalty for using 4x4 MV. */
#define VPU_H1_SWREG361_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG361_BF_0_SHIFT)) & VPU_H1_SWREG361_BF_0_MASK)

#define VPU_H1_SWREG361_BF_20_MASK               (0x3FF00000U)
#define VPU_H1_SWREG361_BF_20_SHIFT              (20U)
/*! BF_20 - Segment 19: Differential MV penalty for 1/4p ME. DMVPenaltyQp */
#define VPU_H1_SWREG361_BF_20(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG361_BF_20_SHIFT)) & VPU_H1_SWREG361_BF_20_MASK)
/*! @} */

/*! @name SWREG362 - VPU H1 Register 362 */
/*! @{ */

#define VPU_H1_SWREG362_BF_0_MASK                (0xFFU)
#define VPU_H1_SWREG362_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 20: Penalty value for second reference frame zero-mv. VP8 golden / H.264 LTR. [0..255] */
#define VPU_H1_SWREG362_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG362_BF_0_SHIFT)) & VPU_H1_SWREG362_BF_0_MASK)

#define VPU_H1_SWREG362_BF_8_MASK                (0xFFFF00U)
#define VPU_H1_SWREG362_BF_8_SHIFT               (8U)
/*! BF_8 - Segment 20: Intra 16x16 mode favor in intra 16x16/4x4 selection */
#define VPU_H1_SWREG362_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG362_BF_8_SHIFT)) & VPU_H1_SWREG362_BF_8_MASK)

#define VPU_H1_SWREG362_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG362_BF_24_SHIFT              (24U)
/*! BF_24 - Segment 20: Intra 4x4 previous mode favor for H.264 */
#define VPU_H1_SWREG362_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG362_BF_24_SHIFT)) & VPU_H1_SWREG362_BF_24_MASK)
/*! @} */

/*! @name SWREG363 - VPU H1 Register 363 */
/*! @{ */

#define VPU_H1_SWREG363_BF_8_MASK                (0xFFFF00U)
#define VPU_H1_SWREG363_BF_8_SHIFT               (8U)
/*! BF_8 - Segment 20: Inter MB mode favor in intra/inter selection */
#define VPU_H1_SWREG363_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG363_BF_8_SHIFT)) & VPU_H1_SWREG363_BF_8_MASK)

#define VPU_H1_SWREG363_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG363_BF_24_SHIFT              (24U)
/*! BF_24 - Segment 20: Skip mode (zero/nearest/near) penalty */
#define VPU_H1_SWREG363_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG363_BF_24_SHIFT)) & VPU_H1_SWREG363_BF_24_MASK)
/*! @} */

/*! @name SWREG364 - VPU H1 Register 364 */
/*! @{ */

#define VPU_H1_SWREG364_BF_0_MASK                (0x3FFU)
#define VPU_H1_SWREG364_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 20: Penalty for using 8x4 or 4x8 MV. */
#define VPU_H1_SWREG364_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG364_BF_0_SHIFT)) & VPU_H1_SWREG364_BF_0_MASK)

#define VPU_H1_SWREG364_BF_10_MASK               (0xFFC00U)
#define VPU_H1_SWREG364_BF_10_SHIFT              (10U)
/*! BF_10 - Segment 20: Penalty for using 8x8 MV. */
#define VPU_H1_SWREG364_BF_10(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG364_BF_10_SHIFT)) & VPU_H1_SWREG364_BF_10_MASK)

#define VPU_H1_SWREG364_BF_20_MASK               (0x3FF00000U)
#define VPU_H1_SWREG364_BF_20_SHIFT              (20U)
/*! BF_20 - Segment 20: Penalty for using 16x8 or 8x16 MV. */
#define VPU_H1_SWREG364_BF_20(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG364_BF_20_SHIFT)) & VPU_H1_SWREG364_BF_20_MASK)
/*! @} */

/*! @name SWREG365 - VPU H1 Register 365 */
/*! @{ */

#define VPU_H1_SWREG365_BF_0_MASK                (0x1FFU)
#define VPU_H1_SWREG365_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 20: Penalty for using 4x4 MV. */
#define VPU_H1_SWREG365_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG365_BF_0_SHIFT)) & VPU_H1_SWREG365_BF_0_MASK)

#define VPU_H1_SWREG365_BF_20_MASK               (0x3FF00000U)
#define VPU_H1_SWREG365_BF_20_SHIFT              (20U)
/*! BF_20 - Segment 20: Differential MV penalty for 1/4p ME. DMVPenaltyQp */
#define VPU_H1_SWREG365_BF_20(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG365_BF_20_SHIFT)) & VPU_H1_SWREG365_BF_20_MASK)
/*! @} */

/*! @name SWREG366 - VPU H1 Register 366 */
/*! @{ */

#define VPU_H1_SWREG366_BF_0_MASK                (0xFFU)
#define VPU_H1_SWREG366_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 21: Penalty value for second reference frame zero-mv. VP8 golden / H.264 LTR. [0..255] */
#define VPU_H1_SWREG366_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG366_BF_0_SHIFT)) & VPU_H1_SWREG366_BF_0_MASK)

#define VPU_H1_SWREG366_BF_8_MASK                (0xFFFF00U)
#define VPU_H1_SWREG366_BF_8_SHIFT               (8U)
/*! BF_8 - Segment 21: Intra 16x16 mode favor in intra 16x16/4x4 selection */
#define VPU_H1_SWREG366_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG366_BF_8_SHIFT)) & VPU_H1_SWREG366_BF_8_MASK)

#define VPU_H1_SWREG366_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG366_BF_24_SHIFT              (24U)
/*! BF_24 - Segment 21: Intra 4x4 previous mode favor for H.264 */
#define VPU_H1_SWREG366_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG366_BF_24_SHIFT)) & VPU_H1_SWREG366_BF_24_MASK)
/*! @} */

/*! @name SWREG367 - VPU H1 Register 367 */
/*! @{ */

#define VPU_H1_SWREG367_BF_8_MASK                (0xFFFF00U)
#define VPU_H1_SWREG367_BF_8_SHIFT               (8U)
/*! BF_8 - Segment 21: Inter MB mode favor in intra/inter selection */
#define VPU_H1_SWREG367_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG367_BF_8_SHIFT)) & VPU_H1_SWREG367_BF_8_MASK)

#define VPU_H1_SWREG367_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG367_BF_24_SHIFT              (24U)
/*! BF_24 - Segment 21: Skip mode (zero/nearest/near) penalty */
#define VPU_H1_SWREG367_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG367_BF_24_SHIFT)) & VPU_H1_SWREG367_BF_24_MASK)
/*! @} */

/*! @name SWREG368 - VPU H1 Register 368 */
/*! @{ */

#define VPU_H1_SWREG368_BF_0_MASK                (0x3FFU)
#define VPU_H1_SWREG368_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 21: Penalty for using 8x4 or 4x8 MV. */
#define VPU_H1_SWREG368_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG368_BF_0_SHIFT)) & VPU_H1_SWREG368_BF_0_MASK)

#define VPU_H1_SWREG368_BF_10_MASK               (0xFFC00U)
#define VPU_H1_SWREG368_BF_10_SHIFT              (10U)
/*! BF_10 - Segment 21: Penalty for using 8x8 MV. */
#define VPU_H1_SWREG368_BF_10(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG368_BF_10_SHIFT)) & VPU_H1_SWREG368_BF_10_MASK)

#define VPU_H1_SWREG368_BF_20_MASK               (0x3FF00000U)
#define VPU_H1_SWREG368_BF_20_SHIFT              (20U)
/*! BF_20 - Segment 21: Penalty for using 16x8 or 8x16 MV. */
#define VPU_H1_SWREG368_BF_20(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG368_BF_20_SHIFT)) & VPU_H1_SWREG368_BF_20_MASK)
/*! @} */

/*! @name SWREG369 - VPU H1 Register 369 */
/*! @{ */

#define VPU_H1_SWREG369_BF_0_MASK                (0x1FFU)
#define VPU_H1_SWREG369_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 21: Penalty for using 4x4 MV. */
#define VPU_H1_SWREG369_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG369_BF_0_SHIFT)) & VPU_H1_SWREG369_BF_0_MASK)

#define VPU_H1_SWREG369_BF_20_MASK               (0x3FF00000U)
#define VPU_H1_SWREG369_BF_20_SHIFT              (20U)
/*! BF_20 - Segment 21: Differential MV penalty for 1/4p ME. DMVPenaltyQp */
#define VPU_H1_SWREG369_BF_20(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG369_BF_20_SHIFT)) & VPU_H1_SWREG369_BF_20_MASK)
/*! @} */

/*! @name SWREG370 - VPU H1 Register 370 */
/*! @{ */

#define VPU_H1_SWREG370_BF_0_MASK                (0xFFU)
#define VPU_H1_SWREG370_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 22: Penalty value for second reference frame zero-mv. VP8 golden / H.264 LTR. [0..255] */
#define VPU_H1_SWREG370_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG370_BF_0_SHIFT)) & VPU_H1_SWREG370_BF_0_MASK)

#define VPU_H1_SWREG370_BF_8_MASK                (0xFFFF00U)
#define VPU_H1_SWREG370_BF_8_SHIFT               (8U)
/*! BF_8 - Segment 22: Intra 16x16 mode favor in intra 16x16/4x4 selection */
#define VPU_H1_SWREG370_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG370_BF_8_SHIFT)) & VPU_H1_SWREG370_BF_8_MASK)

#define VPU_H1_SWREG370_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG370_BF_24_SHIFT              (24U)
/*! BF_24 - Segment 22: Intra 4x4 previous mode favor for H.264 */
#define VPU_H1_SWREG370_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG370_BF_24_SHIFT)) & VPU_H1_SWREG370_BF_24_MASK)
/*! @} */

/*! @name SWREG371 - VPU H1 Register 371 */
/*! @{ */

#define VPU_H1_SWREG371_BF_8_MASK                (0xFFFF00U)
#define VPU_H1_SWREG371_BF_8_SHIFT               (8U)
/*! BF_8 - Segment 22: Inter MB mode favor in intra/inter selection */
#define VPU_H1_SWREG371_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG371_BF_8_SHIFT)) & VPU_H1_SWREG371_BF_8_MASK)

#define VPU_H1_SWREG371_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG371_BF_24_SHIFT              (24U)
/*! BF_24 - Segment 22: Skip mode (zero/nearest/near) penalty */
#define VPU_H1_SWREG371_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG371_BF_24_SHIFT)) & VPU_H1_SWREG371_BF_24_MASK)
/*! @} */

/*! @name SWREG372 - VPU H1 Register 372 */
/*! @{ */

#define VPU_H1_SWREG372_BF_0_MASK                (0x3FFU)
#define VPU_H1_SWREG372_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 22: Penalty for using 8x4 or 4x8 MV. */
#define VPU_H1_SWREG372_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG372_BF_0_SHIFT)) & VPU_H1_SWREG372_BF_0_MASK)

#define VPU_H1_SWREG372_BF_10_MASK               (0xFFC00U)
#define VPU_H1_SWREG372_BF_10_SHIFT              (10U)
/*! BF_10 - Segment 22: Penalty for using 8x8 MV. */
#define VPU_H1_SWREG372_BF_10(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG372_BF_10_SHIFT)) & VPU_H1_SWREG372_BF_10_MASK)

#define VPU_H1_SWREG372_BF_20_MASK               (0x3FF00000U)
#define VPU_H1_SWREG372_BF_20_SHIFT              (20U)
/*! BF_20 - Segment 22: Penalty for using 16x8 or 8x16 MV. */
#define VPU_H1_SWREG372_BF_20(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG372_BF_20_SHIFT)) & VPU_H1_SWREG372_BF_20_MASK)
/*! @} */

/*! @name SWREG373 - VPU H1 Register 373 */
/*! @{ */

#define VPU_H1_SWREG373_BF_0_MASK                (0x1FFU)
#define VPU_H1_SWREG373_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 22: Penalty for using 4x4 MV. */
#define VPU_H1_SWREG373_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG373_BF_0_SHIFT)) & VPU_H1_SWREG373_BF_0_MASK)

#define VPU_H1_SWREG373_BF_20_MASK               (0x3FF00000U)
#define VPU_H1_SWREG373_BF_20_SHIFT              (20U)
/*! BF_20 - Segment 22: Differential MV penalty for 1/4p ME. DMVPenaltyQp */
#define VPU_H1_SWREG373_BF_20(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG373_BF_20_SHIFT)) & VPU_H1_SWREG373_BF_20_MASK)
/*! @} */

/*! @name SWREG374 - VPU H1 Register 374 */
/*! @{ */

#define VPU_H1_SWREG374_BF_0_MASK                (0xFFU)
#define VPU_H1_SWREG374_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 23: Penalty value for second reference frame zero-mv. VP8 golden / H.264 LTR. [0..255] */
#define VPU_H1_SWREG374_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG374_BF_0_SHIFT)) & VPU_H1_SWREG374_BF_0_MASK)

#define VPU_H1_SWREG374_BF_8_MASK                (0xFFFF00U)
#define VPU_H1_SWREG374_BF_8_SHIFT               (8U)
/*! BF_8 - Segment 23: Intra 16x16 mode favor in intra 16x16/4x4 selection */
#define VPU_H1_SWREG374_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG374_BF_8_SHIFT)) & VPU_H1_SWREG374_BF_8_MASK)

#define VPU_H1_SWREG374_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG374_BF_24_SHIFT              (24U)
/*! BF_24 - Segment 23: Intra 4x4 previous mode favor for H.264 */
#define VPU_H1_SWREG374_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG374_BF_24_SHIFT)) & VPU_H1_SWREG374_BF_24_MASK)
/*! @} */

/*! @name SWREG375 - VPU H1 Register 375 */
/*! @{ */

#define VPU_H1_SWREG375_BF_8_MASK                (0xFFFF00U)
#define VPU_H1_SWREG375_BF_8_SHIFT               (8U)
/*! BF_8 - Segment 23: Inter MB mode favor in intra/inter selection */
#define VPU_H1_SWREG375_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG375_BF_8_SHIFT)) & VPU_H1_SWREG375_BF_8_MASK)

#define VPU_H1_SWREG375_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG375_BF_24_SHIFT              (24U)
/*! BF_24 - Segment 23: Skip mode (zero/nearest/near) penalty */
#define VPU_H1_SWREG375_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG375_BF_24_SHIFT)) & VPU_H1_SWREG375_BF_24_MASK)
/*! @} */

/*! @name SWREG376 - VPU H1 Register 376 */
/*! @{ */

#define VPU_H1_SWREG376_BF_0_MASK                (0x3FFU)
#define VPU_H1_SWREG376_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 23: Penalty for using 8x4 or 4x8 MV. */
#define VPU_H1_SWREG376_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG376_BF_0_SHIFT)) & VPU_H1_SWREG376_BF_0_MASK)

#define VPU_H1_SWREG376_BF_10_MASK               (0xFFC00U)
#define VPU_H1_SWREG376_BF_10_SHIFT              (10U)
/*! BF_10 - Segment 23: Penalty for using 8x8 MV. */
#define VPU_H1_SWREG376_BF_10(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG376_BF_10_SHIFT)) & VPU_H1_SWREG376_BF_10_MASK)

#define VPU_H1_SWREG376_BF_20_MASK               (0x3FF00000U)
#define VPU_H1_SWREG376_BF_20_SHIFT              (20U)
/*! BF_20 - Segment 23: Penalty for using 16x8 or 8x16 MV. */
#define VPU_H1_SWREG376_BF_20(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG376_BF_20_SHIFT)) & VPU_H1_SWREG376_BF_20_MASK)
/*! @} */

/*! @name SWREG377 - VPU H1 Register 377 */
/*! @{ */

#define VPU_H1_SWREG377_BF_0_MASK                (0x1FFU)
#define VPU_H1_SWREG377_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 23: Penalty for using 4x4 MV. */
#define VPU_H1_SWREG377_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG377_BF_0_SHIFT)) & VPU_H1_SWREG377_BF_0_MASK)

#define VPU_H1_SWREG377_BF_20_MASK               (0x3FF00000U)
#define VPU_H1_SWREG377_BF_20_SHIFT              (20U)
/*! BF_20 - Segment 23: Differential MV penalty for 1/4p ME. DMVPenaltyQp */
#define VPU_H1_SWREG377_BF_20(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG377_BF_20_SHIFT)) & VPU_H1_SWREG377_BF_20_MASK)
/*! @} */

/*! @name SWREG378 - VPU H1 Register 378 */
/*! @{ */

#define VPU_H1_SWREG378_BF_0_MASK                (0xFFU)
#define VPU_H1_SWREG378_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 24: Penalty value for second reference frame zero-mv. VP8 golden / H.264 LTR. [0..255] */
#define VPU_H1_SWREG378_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG378_BF_0_SHIFT)) & VPU_H1_SWREG378_BF_0_MASK)

#define VPU_H1_SWREG378_BF_8_MASK                (0xFFFF00U)
#define VPU_H1_SWREG378_BF_8_SHIFT               (8U)
/*! BF_8 - Segment 24: Intra 16x16 mode favor in intra 16x16/4x4 selection */
#define VPU_H1_SWREG378_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG378_BF_8_SHIFT)) & VPU_H1_SWREG378_BF_8_MASK)

#define VPU_H1_SWREG378_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG378_BF_24_SHIFT              (24U)
/*! BF_24 - Segment 24: Intra 4x4 previous mode favor for H.264 */
#define VPU_H1_SWREG378_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG378_BF_24_SHIFT)) & VPU_H1_SWREG378_BF_24_MASK)
/*! @} */

/*! @name SWREG379 - VPU H1 Register 379 */
/*! @{ */

#define VPU_H1_SWREG379_BF_8_MASK                (0xFFFF00U)
#define VPU_H1_SWREG379_BF_8_SHIFT               (8U)
/*! BF_8 - Segment 24: Inter MB mode favor in intra/inter selection */
#define VPU_H1_SWREG379_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG379_BF_8_SHIFT)) & VPU_H1_SWREG379_BF_8_MASK)

#define VPU_H1_SWREG379_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG379_BF_24_SHIFT              (24U)
/*! BF_24 - Segment 24: Skip mode (zero/nearest/near) penalty */
#define VPU_H1_SWREG379_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG379_BF_24_SHIFT)) & VPU_H1_SWREG379_BF_24_MASK)
/*! @} */

/*! @name SWREG380 - VPU H1 Register 380 */
/*! @{ */

#define VPU_H1_SWREG380_BF_0_MASK                (0x3FFU)
#define VPU_H1_SWREG380_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 24: Penalty for using 8x4 or 4x8 MV. */
#define VPU_H1_SWREG380_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG380_BF_0_SHIFT)) & VPU_H1_SWREG380_BF_0_MASK)

#define VPU_H1_SWREG380_BF_10_MASK               (0xFFC00U)
#define VPU_H1_SWREG380_BF_10_SHIFT              (10U)
/*! BF_10 - Segment 24: Penalty for using 8x8 MV. */
#define VPU_H1_SWREG380_BF_10(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG380_BF_10_SHIFT)) & VPU_H1_SWREG380_BF_10_MASK)

#define VPU_H1_SWREG380_BF_20_MASK               (0x3FF00000U)
#define VPU_H1_SWREG380_BF_20_SHIFT              (20U)
/*! BF_20 - Segment 24: Penalty for using 16x8 or 8x16 MV. */
#define VPU_H1_SWREG380_BF_20(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG380_BF_20_SHIFT)) & VPU_H1_SWREG380_BF_20_MASK)
/*! @} */

/*! @name SWREG381 - VPU H1 Register 381 */
/*! @{ */

#define VPU_H1_SWREG381_BF_0_MASK                (0x1FFU)
#define VPU_H1_SWREG381_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 24: Penalty for using 4x4 MV. */
#define VPU_H1_SWREG381_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG381_BF_0_SHIFT)) & VPU_H1_SWREG381_BF_0_MASK)

#define VPU_H1_SWREG381_BF_20_MASK               (0x3FF00000U)
#define VPU_H1_SWREG381_BF_20_SHIFT              (20U)
/*! BF_20 - Segment 24: Differential MV penalty for 1/4p ME. DMVPenaltyQp */
#define VPU_H1_SWREG381_BF_20(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG381_BF_20_SHIFT)) & VPU_H1_SWREG381_BF_20_MASK)
/*! @} */

/*! @name SWREG382 - VPU H1 Register 382 */
/*! @{ */

#define VPU_H1_SWREG382_BF_0_MASK                (0xFFU)
#define VPU_H1_SWREG382_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 25: Penalty value for second reference frame zero-mv. VP8 golden / H.264 LTR. [0..255] */
#define VPU_H1_SWREG382_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG382_BF_0_SHIFT)) & VPU_H1_SWREG382_BF_0_MASK)

#define VPU_H1_SWREG382_BF_8_MASK                (0xFFFF00U)
#define VPU_H1_SWREG382_BF_8_SHIFT               (8U)
/*! BF_8 - Segment 25: Intra 16x16 mode favor in intra 16x16/4x4 selection */
#define VPU_H1_SWREG382_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG382_BF_8_SHIFT)) & VPU_H1_SWREG382_BF_8_MASK)

#define VPU_H1_SWREG382_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG382_BF_24_SHIFT              (24U)
/*! BF_24 - Segment 25: Intra 4x4 previous mode favor for H.264 */
#define VPU_H1_SWREG382_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG382_BF_24_SHIFT)) & VPU_H1_SWREG382_BF_24_MASK)
/*! @} */

/*! @name SWREG383 - VPU H1 Register 383 */
/*! @{ */

#define VPU_H1_SWREG383_BF_8_MASK                (0xFFFF00U)
#define VPU_H1_SWREG383_BF_8_SHIFT               (8U)
/*! BF_8 - Segment 25: Inter MB mode favor in intra/inter selection */
#define VPU_H1_SWREG383_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG383_BF_8_SHIFT)) & VPU_H1_SWREG383_BF_8_MASK)

#define VPU_H1_SWREG383_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG383_BF_24_SHIFT              (24U)
/*! BF_24 - Segment 25: Skip mode (zero/nearest/near) penalty */
#define VPU_H1_SWREG383_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG383_BF_24_SHIFT)) & VPU_H1_SWREG383_BF_24_MASK)
/*! @} */

/*! @name SWREG384 - VPU H1 Register 384 */
/*! @{ */

#define VPU_H1_SWREG384_BF_0_MASK                (0x3FFU)
#define VPU_H1_SWREG384_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 25: Penalty for using 8x4 or 4x8 MV. */
#define VPU_H1_SWREG384_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG384_BF_0_SHIFT)) & VPU_H1_SWREG384_BF_0_MASK)

#define VPU_H1_SWREG384_BF_10_MASK               (0xFFC00U)
#define VPU_H1_SWREG384_BF_10_SHIFT              (10U)
/*! BF_10 - Segment 25: Penalty for using 8x8 MV. */
#define VPU_H1_SWREG384_BF_10(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG384_BF_10_SHIFT)) & VPU_H1_SWREG384_BF_10_MASK)

#define VPU_H1_SWREG384_BF_20_MASK               (0x3FF00000U)
#define VPU_H1_SWREG384_BF_20_SHIFT              (20U)
/*! BF_20 - Segment 25: Penalty for using 16x8 or 8x16 MV. */
#define VPU_H1_SWREG384_BF_20(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG384_BF_20_SHIFT)) & VPU_H1_SWREG384_BF_20_MASK)
/*! @} */

/*! @name SWREG385 - VPU H1 Register 385 */
/*! @{ */

#define VPU_H1_SWREG385_BF_0_MASK                (0x1FFU)
#define VPU_H1_SWREG385_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 25: Penalty for using 4x4 MV. */
#define VPU_H1_SWREG385_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG385_BF_0_SHIFT)) & VPU_H1_SWREG385_BF_0_MASK)

#define VPU_H1_SWREG385_BF_20_MASK               (0x3FF00000U)
#define VPU_H1_SWREG385_BF_20_SHIFT              (20U)
/*! BF_20 - Segment 25: Differential MV penalty for 1/4p ME. DMVPenaltyQp */
#define VPU_H1_SWREG385_BF_20(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG385_BF_20_SHIFT)) & VPU_H1_SWREG385_BF_20_MASK)
/*! @} */

/*! @name SWREG386 - VPU H1 Register 386 */
/*! @{ */

#define VPU_H1_SWREG386_BF_0_MASK                (0xFFU)
#define VPU_H1_SWREG386_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 26: Penalty value for second reference frame zero-mv. VP8 golden / H.264 LTR. [0..255] */
#define VPU_H1_SWREG386_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG386_BF_0_SHIFT)) & VPU_H1_SWREG386_BF_0_MASK)

#define VPU_H1_SWREG386_BF_8_MASK                (0xFFFF00U)
#define VPU_H1_SWREG386_BF_8_SHIFT               (8U)
/*! BF_8 - Segment 26: Intra 16x16 mode favor in intra 16x16/4x4 selection */
#define VPU_H1_SWREG386_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG386_BF_8_SHIFT)) & VPU_H1_SWREG386_BF_8_MASK)

#define VPU_H1_SWREG386_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG386_BF_24_SHIFT              (24U)
/*! BF_24 - Segment 26: Intra 4x4 previous mode favor for H.264 */
#define VPU_H1_SWREG386_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG386_BF_24_SHIFT)) & VPU_H1_SWREG386_BF_24_MASK)
/*! @} */

/*! @name SWREG387 - VPU H1 Register 387 */
/*! @{ */

#define VPU_H1_SWREG387_BF_8_MASK                (0xFFFF00U)
#define VPU_H1_SWREG387_BF_8_SHIFT               (8U)
/*! BF_8 - Segment 26: Inter MB mode favor in intra/inter selection */
#define VPU_H1_SWREG387_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG387_BF_8_SHIFT)) & VPU_H1_SWREG387_BF_8_MASK)

#define VPU_H1_SWREG387_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG387_BF_24_SHIFT              (24U)
/*! BF_24 - Segment 26: Skip mode (zero/nearest/near) penalty */
#define VPU_H1_SWREG387_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG387_BF_24_SHIFT)) & VPU_H1_SWREG387_BF_24_MASK)
/*! @} */

/*! @name SWREG388 - VPU H1 Register 388 */
/*! @{ */

#define VPU_H1_SWREG388_BF_0_MASK                (0x3FFU)
#define VPU_H1_SWREG388_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 26: Penalty for using 8x4 or 4x8 MV. */
#define VPU_H1_SWREG388_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG388_BF_0_SHIFT)) & VPU_H1_SWREG388_BF_0_MASK)

#define VPU_H1_SWREG388_BF_10_MASK               (0xFFC00U)
#define VPU_H1_SWREG388_BF_10_SHIFT              (10U)
/*! BF_10 - Segment 26: Penalty for using 8x8 MV. */
#define VPU_H1_SWREG388_BF_10(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG388_BF_10_SHIFT)) & VPU_H1_SWREG388_BF_10_MASK)

#define VPU_H1_SWREG388_BF_20_MASK               (0x3FF00000U)
#define VPU_H1_SWREG388_BF_20_SHIFT              (20U)
/*! BF_20 - Segment 26: Penalty for using 16x8 or 8x16 MV. */
#define VPU_H1_SWREG388_BF_20(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG388_BF_20_SHIFT)) & VPU_H1_SWREG388_BF_20_MASK)
/*! @} */

/*! @name SWREG389 - VPU H1 Register 389 */
/*! @{ */

#define VPU_H1_SWREG389_BF_0_MASK                (0x1FFU)
#define VPU_H1_SWREG389_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 26: Penalty for using 4x4 MV. */
#define VPU_H1_SWREG389_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG389_BF_0_SHIFT)) & VPU_H1_SWREG389_BF_0_MASK)

#define VPU_H1_SWREG389_BF_20_MASK               (0x3FF00000U)
#define VPU_H1_SWREG389_BF_20_SHIFT              (20U)
/*! BF_20 - Segment 26: Differential MV penalty for 1/4p ME. DMVPenaltyQp */
#define VPU_H1_SWREG389_BF_20(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG389_BF_20_SHIFT)) & VPU_H1_SWREG389_BF_20_MASK)
/*! @} */

/*! @name SWREG390 - VPU H1 Register 390 */
/*! @{ */

#define VPU_H1_SWREG390_BF_0_MASK                (0xFFU)
#define VPU_H1_SWREG390_BF_0_SHIFT               (0U)
/*! BF_0 - Segm */
#define VPU_H1_SWREG390_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG390_BF_0_SHIFT)) & VPU_H1_SWREG390_BF_0_MASK)

#define VPU_H1_SWREG390_BF_8_MASK                (0xFFFF00U)
#define VPU_H1_SWREG390_BF_8_SHIFT               (8U)
/*! BF_8 - Segment 27: Intra 16x16 mode favor in intra 16x16/4x4 selection */
#define VPU_H1_SWREG390_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG390_BF_8_SHIFT)) & VPU_H1_SWREG390_BF_8_MASK)

#define VPU_H1_SWREG390_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG390_BF_24_SHIFT              (24U)
/*! BF_24 - Segment 27: Intra 4x4 previous mode favor for H.264 */
#define VPU_H1_SWREG390_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG390_BF_24_SHIFT)) & VPU_H1_SWREG390_BF_24_MASK)
/*! @} */

/*! @name SWREG391 - VPU H1 Register 391 */
/*! @{ */

#define VPU_H1_SWREG391_BF_8_MASK                (0xFFFF00U)
#define VPU_H1_SWREG391_BF_8_SHIFT               (8U)
/*! BF_8 - Segment 27: Inter MB mode favor in intra/inter selection */
#define VPU_H1_SWREG391_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG391_BF_8_SHIFT)) & VPU_H1_SWREG391_BF_8_MASK)

#define VPU_H1_SWREG391_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG391_BF_24_SHIFT              (24U)
/*! BF_24 - Segment 27: Skip mode (zero/nearest/near) penalty */
#define VPU_H1_SWREG391_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG391_BF_24_SHIFT)) & VPU_H1_SWREG391_BF_24_MASK)
/*! @} */

/*! @name SWREG392 - VPU H1 Register 392 */
/*! @{ */

#define VPU_H1_SWREG392_BF_0_MASK                (0x3FFU)
#define VPU_H1_SWREG392_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 27: Penalty for using 8x4 or 4x8 MV. */
#define VPU_H1_SWREG392_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG392_BF_0_SHIFT)) & VPU_H1_SWREG392_BF_0_MASK)

#define VPU_H1_SWREG392_BF_10_MASK               (0xFFC00U)
#define VPU_H1_SWREG392_BF_10_SHIFT              (10U)
/*! BF_10 - Segment 27: Penalty for using 8x8 MV. */
#define VPU_H1_SWREG392_BF_10(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG392_BF_10_SHIFT)) & VPU_H1_SWREG392_BF_10_MASK)

#define VPU_H1_SWREG392_BF_20_MASK               (0x3FF00000U)
#define VPU_H1_SWREG392_BF_20_SHIFT              (20U)
/*! BF_20 - Segment 27: Penalty for using 16x8 or 8x16 MV. */
#define VPU_H1_SWREG392_BF_20(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG392_BF_20_SHIFT)) & VPU_H1_SWREG392_BF_20_MASK)
/*! @} */

/*! @name SWREG393 - VPU H1 Register 393 */
/*! @{ */

#define VPU_H1_SWREG393_BF_0_MASK                (0x1FFU)
#define VPU_H1_SWREG393_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 27: Penalty for using 4x4 MV. */
#define VPU_H1_SWREG393_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG393_BF_0_SHIFT)) & VPU_H1_SWREG393_BF_0_MASK)

#define VPU_H1_SWREG393_BF_20_MASK               (0x3FF00000U)
#define VPU_H1_SWREG393_BF_20_SHIFT              (20U)
/*! BF_20 - Segment 27: Differential MV penalty for 1/4p ME. DMVPenaltyQp */
#define VPU_H1_SWREG393_BF_20(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG393_BF_20_SHIFT)) & VPU_H1_SWREG393_BF_20_MASK)
/*! @} */

/*! @name SWREG394 - VPU H1 Register 394 */
/*! @{ */

#define VPU_H1_SWREG394_BF_0_MASK                (0xFFU)
#define VPU_H1_SWREG394_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 28: Penalty value for second reference frame zero-mv. VP8 golden / H.264 LTR. [0..255] */
#define VPU_H1_SWREG394_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG394_BF_0_SHIFT)) & VPU_H1_SWREG394_BF_0_MASK)

#define VPU_H1_SWREG394_BF_8_MASK                (0xFFFF00U)
#define VPU_H1_SWREG394_BF_8_SHIFT               (8U)
/*! BF_8 - Segment 28: Intra 16x16 mode favor in intra 16x16/4x4 selection */
#define VPU_H1_SWREG394_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG394_BF_8_SHIFT)) & VPU_H1_SWREG394_BF_8_MASK)

#define VPU_H1_SWREG394_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG394_BF_24_SHIFT              (24U)
/*! BF_24 - Segment 28: Intra 4x4 previous mode favor for H.264 */
#define VPU_H1_SWREG394_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG394_BF_24_SHIFT)) & VPU_H1_SWREG394_BF_24_MASK)
/*! @} */

/*! @name SWREG395 - VPU H1 Register 395 */
/*! @{ */

#define VPU_H1_SWREG395_BF_8_MASK                (0xFFFF00U)
#define VPU_H1_SWREG395_BF_8_SHIFT               (8U)
/*! BF_8 - Segment 28: Inter MB mode favor in intra/inter selection */
#define VPU_H1_SWREG395_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG395_BF_8_SHIFT)) & VPU_H1_SWREG395_BF_8_MASK)

#define VPU_H1_SWREG395_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG395_BF_24_SHIFT              (24U)
/*! BF_24 - Segment 28: Skip mode (zero/nearest/near) penalty */
#define VPU_H1_SWREG395_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG395_BF_24_SHIFT)) & VPU_H1_SWREG395_BF_24_MASK)
/*! @} */

/*! @name SWREG396 - VPU H1 Register 396 */
/*! @{ */

#define VPU_H1_SWREG396_BF_0_MASK                (0x3FFU)
#define VPU_H1_SWREG396_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 28: Penalty for using 8x4 or 4x8 MV. */
#define VPU_H1_SWREG396_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG396_BF_0_SHIFT)) & VPU_H1_SWREG396_BF_0_MASK)

#define VPU_H1_SWREG396_BF_10_MASK               (0xFFC00U)
#define VPU_H1_SWREG396_BF_10_SHIFT              (10U)
/*! BF_10 - Segment 28: Penalty for using 8x8 MV. */
#define VPU_H1_SWREG396_BF_10(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG396_BF_10_SHIFT)) & VPU_H1_SWREG396_BF_10_MASK)

#define VPU_H1_SWREG396_BF_20_MASK               (0x3FF00000U)
#define VPU_H1_SWREG396_BF_20_SHIFT              (20U)
/*! BF_20 - Segment 28: Penalty for using 16x8 or 8x16 MV. */
#define VPU_H1_SWREG396_BF_20(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG396_BF_20_SHIFT)) & VPU_H1_SWREG396_BF_20_MASK)
/*! @} */

/*! @name SWREG397 - VPU H1 Register 397 */
/*! @{ */

#define VPU_H1_SWREG397_BF_0_MASK                (0x1FFU)
#define VPU_H1_SWREG397_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 28: Penalty for using 4x4 MV. */
#define VPU_H1_SWREG397_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG397_BF_0_SHIFT)) & VPU_H1_SWREG397_BF_0_MASK)

#define VPU_H1_SWREG397_BF_20_MASK               (0x3FF00000U)
#define VPU_H1_SWREG397_BF_20_SHIFT              (20U)
/*! BF_20 - Segment 28: Differential MV penalty for 1/4p ME. DMVPenaltyQp */
#define VPU_H1_SWREG397_BF_20(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG397_BF_20_SHIFT)) & VPU_H1_SWREG397_BF_20_MASK)
/*! @} */

/*! @name SWREG398 - VPU H1 Register 398 */
/*! @{ */

#define VPU_H1_SWREG398_BF_0_MASK                (0xFFU)
#define VPU_H1_SWREG398_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 29: Penalty value for second reference frame zero-mv. VP8 golden / H.264 LTR. [0..255] */
#define VPU_H1_SWREG398_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG398_BF_0_SHIFT)) & VPU_H1_SWREG398_BF_0_MASK)

#define VPU_H1_SWREG398_BF_8_MASK                (0xFFFF00U)
#define VPU_H1_SWREG398_BF_8_SHIFT               (8U)
/*! BF_8 - Segment 29: Intra 16x16 mode favor in intra 16x16/4x4 selection */
#define VPU_H1_SWREG398_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG398_BF_8_SHIFT)) & VPU_H1_SWREG398_BF_8_MASK)

#define VPU_H1_SWREG398_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG398_BF_24_SHIFT              (24U)
/*! BF_24 - Segment 29: Intra 4x4 previous mode favor for H.264 */
#define VPU_H1_SWREG398_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG398_BF_24_SHIFT)) & VPU_H1_SWREG398_BF_24_MASK)
/*! @} */

/*! @name SWREG399 - VPU H1 Register 399 */
/*! @{ */

#define VPU_H1_SWREG399_BF_8_MASK                (0xFFFF00U)
#define VPU_H1_SWREG399_BF_8_SHIFT               (8U)
/*! BF_8 - Segment 29: Inter MB mode favor in intra/inter selection */
#define VPU_H1_SWREG399_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG399_BF_8_SHIFT)) & VPU_H1_SWREG399_BF_8_MASK)

#define VPU_H1_SWREG399_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG399_BF_24_SHIFT              (24U)
/*! BF_24 - Segment 29: Skip mode (zero/nearest/near) penalty */
#define VPU_H1_SWREG399_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG399_BF_24_SHIFT)) & VPU_H1_SWREG399_BF_24_MASK)
/*! @} */

/*! @name SWREG400 - VPU H1 Register 400 */
/*! @{ */

#define VPU_H1_SWREG400_BF_0_MASK                (0x3FFU)
#define VPU_H1_SWREG400_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 29: Penalty for using 8x4 or 4x8 MV. */
#define VPU_H1_SWREG400_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG400_BF_0_SHIFT)) & VPU_H1_SWREG400_BF_0_MASK)

#define VPU_H1_SWREG400_BF_10_MASK               (0xFFC00U)
#define VPU_H1_SWREG400_BF_10_SHIFT              (10U)
/*! BF_10 - Segment 29: Penalty for using 8x8 MV. */
#define VPU_H1_SWREG400_BF_10(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG400_BF_10_SHIFT)) & VPU_H1_SWREG400_BF_10_MASK)

#define VPU_H1_SWREG400_BF_20_MASK               (0x3FF00000U)
#define VPU_H1_SWREG400_BF_20_SHIFT              (20U)
/*! BF_20 - Segment 29: Penalty for using 16x8 or 8x16 MV. */
#define VPU_H1_SWREG400_BF_20(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG400_BF_20_SHIFT)) & VPU_H1_SWREG400_BF_20_MASK)
/*! @} */

/*! @name SWREG401 - VPU H1 Register 401 */
/*! @{ */

#define VPU_H1_SWREG401_BF_0_MASK                (0x1FFU)
#define VPU_H1_SWREG401_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 29: Penalty for using 4x4 MV. */
#define VPU_H1_SWREG401_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG401_BF_0_SHIFT)) & VPU_H1_SWREG401_BF_0_MASK)

#define VPU_H1_SWREG401_BF_20_MASK               (0x3FF00000U)
#define VPU_H1_SWREG401_BF_20_SHIFT              (20U)
/*! BF_20 - Segment 29: Differential MV penalty for 1/4p ME. DMVPenaltyQp */
#define VPU_H1_SWREG401_BF_20(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG401_BF_20_SHIFT)) & VPU_H1_SWREG401_BF_20_MASK)
/*! @} */

/*! @name SWREG402 - VPU H1 Register 402 */
/*! @{ */

#define VPU_H1_SWREG402_BF_0_MASK                (0xFFU)
#define VPU_H1_SWREG402_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 30: Penalty value for second reference frame zero-mv. VP8 golden / H.264 LTR. [0..255] */
#define VPU_H1_SWREG402_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG402_BF_0_SHIFT)) & VPU_H1_SWREG402_BF_0_MASK)

#define VPU_H1_SWREG402_BF_8_MASK                (0xFFFF00U)
#define VPU_H1_SWREG402_BF_8_SHIFT               (8U)
/*! BF_8 - Segment 30: Intra 16x16 mode favor in intra 16x16/4x4 selection */
#define VPU_H1_SWREG402_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG402_BF_8_SHIFT)) & VPU_H1_SWREG402_BF_8_MASK)

#define VPU_H1_SWREG402_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG402_BF_24_SHIFT              (24U)
/*! BF_24 - Segment 30: Intra 4x4 previous mode favor for H.264 */
#define VPU_H1_SWREG402_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG402_BF_24_SHIFT)) & VPU_H1_SWREG402_BF_24_MASK)
/*! @} */

/*! @name SWREG403 - VPU H1 Register 403 */
/*! @{ */

#define VPU_H1_SWREG403_BF_8_MASK                (0xFFFF00U)
#define VPU_H1_SWREG403_BF_8_SHIFT               (8U)
/*! BF_8 - Segment 30: Inter MB mode favor in intra/inter selection */
#define VPU_H1_SWREG403_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG403_BF_8_SHIFT)) & VPU_H1_SWREG403_BF_8_MASK)

#define VPU_H1_SWREG403_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG403_BF_24_SHIFT              (24U)
/*! BF_24 - Segment 30: Skip mode (zero/nearest/near) penalty */
#define VPU_H1_SWREG403_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG403_BF_24_SHIFT)) & VPU_H1_SWREG403_BF_24_MASK)
/*! @} */

/*! @name SWREG404 - VPU H1 Register 404 */
/*! @{ */

#define VPU_H1_SWREG404_BF_0_MASK                (0x3FFU)
#define VPU_H1_SWREG404_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 30: Penalty for using 8x4 or 4x8 MV. */
#define VPU_H1_SWREG404_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG404_BF_0_SHIFT)) & VPU_H1_SWREG404_BF_0_MASK)

#define VPU_H1_SWREG404_BF_10_MASK               (0xFFC00U)
#define VPU_H1_SWREG404_BF_10_SHIFT              (10U)
/*! BF_10 - Segment 30: Penalty for using 8x8 MV. */
#define VPU_H1_SWREG404_BF_10(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG404_BF_10_SHIFT)) & VPU_H1_SWREG404_BF_10_MASK)

#define VPU_H1_SWREG404_BF_20_MASK               (0x3FF00000U)
#define VPU_H1_SWREG404_BF_20_SHIFT              (20U)
/*! BF_20 - Segment 30: Penalty for using 16x8 or 8x16 MV. */
#define VPU_H1_SWREG404_BF_20(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG404_BF_20_SHIFT)) & VPU_H1_SWREG404_BF_20_MASK)
/*! @} */

/*! @name SWREG405 - VPU H1 Register 405 */
/*! @{ */

#define VPU_H1_SWREG405_BF_0_MASK                (0x1FFU)
#define VPU_H1_SWREG405_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 30: Penalty for using 4x4 MV. */
#define VPU_H1_SWREG405_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG405_BF_0_SHIFT)) & VPU_H1_SWREG405_BF_0_MASK)

#define VPU_H1_SWREG405_BF_20_MASK               (0x3FF00000U)
#define VPU_H1_SWREG405_BF_20_SHIFT              (20U)
/*! BF_20 - Segment 30: Differential MV penalty for 1/4p ME. DMVPenaltyQp */
#define VPU_H1_SWREG405_BF_20(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG405_BF_20_SHIFT)) & VPU_H1_SWREG405_BF_20_MASK)
/*! @} */

/*! @name SWREG406 - VPU H1 Register 406 */
/*! @{ */

#define VPU_H1_SWREG406_BF_0_MASK                (0xFFU)
#define VPU_H1_SWREG406_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 31: Penalty value for second reference frame zero-mv. VP8 golden / H.264 LTR. [0..255] */
#define VPU_H1_SWREG406_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG406_BF_0_SHIFT)) & VPU_H1_SWREG406_BF_0_MASK)

#define VPU_H1_SWREG406_BF_8_MASK                (0xFFFF00U)
#define VPU_H1_SWREG406_BF_8_SHIFT               (8U)
/*! BF_8 - Segment 31: Intra 16x16 mode favor in intra 16x16/4x4 selection */
#define VPU_H1_SWREG406_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG406_BF_8_SHIFT)) & VPU_H1_SWREG406_BF_8_MASK)

#define VPU_H1_SWREG406_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG406_BF_24_SHIFT              (24U)
/*! BF_24 - Segment 31: Intra 4x4 previous mode favor for H.264 */
#define VPU_H1_SWREG406_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG406_BF_24_SHIFT)) & VPU_H1_SWREG406_BF_24_MASK)
/*! @} */

/*! @name SWREG407 - VPU H1 Register 407 */
/*! @{ */

#define VPU_H1_SWREG407_BF_8_MASK                (0xFFFF00U)
#define VPU_H1_SWREG407_BF_8_SHIFT               (8U)
/*! BF_8 - Segment 31: Inter MB mode favor in intra/inter selection */
#define VPU_H1_SWREG407_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG407_BF_8_SHIFT)) & VPU_H1_SWREG407_BF_8_MASK)

#define VPU_H1_SWREG407_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG407_BF_24_SHIFT              (24U)
/*! BF_24 - Segment 31: Skip mode (zero/nearest/near) penalty */
#define VPU_H1_SWREG407_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG407_BF_24_SHIFT)) & VPU_H1_SWREG407_BF_24_MASK)
/*! @} */

/*! @name SWREG408 - VPU H1 Register 408 */
/*! @{ */

#define VPU_H1_SWREG408_BF_0_MASK                (0x3FFU)
#define VPU_H1_SWREG408_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 31: Penalty for using 8x4 or 4x8 MV. */
#define VPU_H1_SWREG408_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG408_BF_0_SHIFT)) & VPU_H1_SWREG408_BF_0_MASK)

#define VPU_H1_SWREG408_BF_10_MASK               (0xFFC00U)
#define VPU_H1_SWREG408_BF_10_SHIFT              (10U)
/*! BF_10 - Segment 31: Penalty for using 8x8 MV. */
#define VPU_H1_SWREG408_BF_10(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG408_BF_10_SHIFT)) & VPU_H1_SWREG408_BF_10_MASK)

#define VPU_H1_SWREG408_BF_20_MASK               (0x3FF00000U)
#define VPU_H1_SWREG408_BF_20_SHIFT              (20U)
/*! BF_20 - Segment 31: Penalty for using 16x8 or 8x16 MV. */
#define VPU_H1_SWREG408_BF_20(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG408_BF_20_SHIFT)) & VPU_H1_SWREG408_BF_20_MASK)
/*! @} */

/*! @name SWREG409 - VPU H1 Register 409 */
/*! @{ */

#define VPU_H1_SWREG409_BF_0_MASK                (0x1FFU)
#define VPU_H1_SWREG409_BF_0_SHIFT               (0U)
/*! BF_0 - Segment 31: Penalty for using 4x4 MV. */
#define VPU_H1_SWREG409_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG409_BF_0_SHIFT)) & VPU_H1_SWREG409_BF_0_MASK)

#define VPU_H1_SWREG409_BF_20_MASK               (0x3FF00000U)
#define VPU_H1_SWREG409_BF_20_SHIFT              (20U)
/*! BF_20 - Segment 31: Differential MV penalty for 1/4p ME. DMVPenaltyQp */
#define VPU_H1_SWREG409_BF_20(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG409_BF_20_SHIFT)) & VPU_H1_SWREG409_BF_20_MASK)
/*! @} */

/*! @name SWREG410 - VPU H1 Register 410 */
/*! @{ */

#define VPU_H1_SWREG410_BF_0_MASK                (0x3U)
#define VPU_H1_SWREG410_BF_0_SHIFT               (0U)
/*! BF_0 - MB RC Enable. */
#define VPU_H1_SWREG410_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG410_BF_0_SHIFT)) & VPU_H1_SWREG410_BF_0_MASK)

#define VPU_H1_SWREG410_BF_7_MASK                (0xF80U)
#define VPU_H1_SWREG410_BF_7_SHIFT               (7U)
/*! BF_7 - offset of MB complexity */
#define VPU_H1_SWREG410_BF_7(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG410_BF_7_SHIFT)) & VPU_H1_SWREG410_BF_7_MASK)

#define VPU_H1_SWREG410_BF_16_MASK               (0xFFFF0000U)
#define VPU_H1_SWREG410_BF_16_SHIFT              (16U)
/*! BF_16 - fractional part of frame qp. .16 format */
#define VPU_H1_SWREG410_BF_16(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG410_BF_16_SHIFT)) & VPU_H1_SWREG410_BF_16_MASK)
/*! @} */

/*! @name SWREG411 - VPU H1 Register 411 */
/*! @{ */

#define VPU_H1_SWREG411_BF_0_MASK                (0xFFFFU)
#define VPU_H1_SWREG411_BF_0_SHIFT               (0U)
/*! BF_0 - gain of MB qp delta. 8.8 format */
#define VPU_H1_SWREG411_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG411_BF_0_SHIFT)) & VPU_H1_SWREG411_BF_0_MASK)
/*! @} */

/*! @name SWREG412 - VPU H1 Register 412 */
/*! @{ */

#define VPU_H1_SWREG412_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG412_BF_0_SHIFT               (0U)
/*! BF_0 - average of MB complexity */
#define VPU_H1_SWREG412_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG412_BF_0_SHIFT)) & VPU_H1_SWREG412_BF_0_MASK)
/*! @} */

/*! @name SWREG413 - VPU H1 Register 413 */
/*! @{ */

#define VPU_H1_SWREG413_BF_0_MASK                (0x1U)
#define VPU_H1_SWREG413_BF_0_SHIFT               (0U)
/*! BF_0 - Reference Frame Luma Compression. */
#define VPU_H1_SWREG413_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG413_BF_0_SHIFT)) & VPU_H1_SWREG413_BF_0_MASK)

#define VPU_H1_SWREG413_BF_1_MASK                (0x2U)
#define VPU_H1_SWREG413_BF_1_SHIFT               (1U)
/*! BF_1 - Reference Frame Chroma Compression. */
#define VPU_H1_SWREG413_BF_1(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG413_BF_1_SHIFT)) & VPU_H1_SWREG413_BF_1_MASK)

#define VPU_H1_SWREG413_BF_2_MASK                (0x4U)
#define VPU_H1_SWREG413_BF_2_SHIFT               (2U)
/*! BF_2 - Reference Compression in discrete storage mode. */
#define VPU_H1_SWREG413_BF_2(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG413_BF_2_SHIFT)) & VPU_H1_SWREG413_BF_2_MASK)

#define VPU_H1_SWREG413_BF_3_MASK                (0x8U)
#define VPU_H1_SWREG413_BF_3_SHIFT               (3U)
/*! BF_3 - RFC overflow IRQ Enable. */
#define VPU_H1_SWREG413_BF_3(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG413_BF_3_SHIFT)) & VPU_H1_SWREG413_BF_3_MASK)

#define VPU_H1_SWREG413_BF_11_MASK               (0xFFFFF800U)
#define VPU_H1_SWREG413_BF_11_SHIFT              (11U)
/*! BF_11 - Limit of luma RFC buffer in unit of 64-bit. 0 indicating no limit. Send an IRQ if overflow. */
#define VPU_H1_SWREG413_BF_11(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG413_BF_11_SHIFT)) & VPU_H1_SWREG413_BF_11_MASK)
/*! @} */

/*! @name SWREG414 - VPU H1 Register 414 */
/*! @{ */

#define VPU_H1_SWREG414_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG414_BF_0_SHIFT               (0U)
/*! BF_0 - Base address for reference luma compression table */
#define VPU_H1_SWREG414_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG414_BF_0_SHIFT)) & VPU_H1_SWREG414_BF_0_MASK)
/*! @} */

/*! @name SWREG415 - VPU H1 Register 415 */
/*! @{ */

#define VPU_H1_SWREG415_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG415_BF_0_SHIFT               (0U)
/*! BF_0 - Base address for reference chroma compression table */
#define VPU_H1_SWREG415_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG415_BF_0_SHIFT)) & VPU_H1_SWREG415_BF_0_MASK)
/*! @} */

/*! @name SWREG416 - VPU H1 Register 416 */
/*! @{ */

#define VPU_H1_SWREG416_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG416_BF_0_SHIFT               (0U)
/*! BF_0 - Base address for reconstructed luma compression table */
#define VPU_H1_SWREG416_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG416_BF_0_SHIFT)) & VPU_H1_SWREG416_BF_0_MASK)
/*! @} */

/*! @name SWREG417 - VPU H1 Register 417 */
/*! @{ */

#define VPU_H1_SWREG417_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG417_BF_0_SHIFT               (0U)
/*! BF_0 - Base address for reconstructed chroma compression table */
#define VPU_H1_SWREG417_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG417_BF_0_SHIFT)) & VPU_H1_SWREG417_BF_0_MASK)
/*! @} */

/*! @name SWREG418 - VPU H1 Register 418 */
/*! @{ */

#define VPU_H1_SWREG418_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG418_BF_0_SHIFT               (0U)
/*! BF_0 - Base address for second reference luma compression table */
#define VPU_H1_SWREG418_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG418_BF_0_SHIFT)) & VPU_H1_SWREG418_BF_0_MASK)
/*! @} */

/*! @name SWREG419 - VPU H1 Register 419 */
/*! @{ */

#define VPU_H1_SWREG419_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG419_BF_0_SHIFT               (0U)
/*! BF_0 - Base address for second reference chroma compression table */
#define VPU_H1_SWREG419_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG419_BF_0_SHIFT)) & VPU_H1_SWREG419_BF_0_MASK)
/*! @} */

/*! @name SWREG420 - VPU H1 Register 420 */
/*! @{ */

#define VPU_H1_SWREG420_BF_12_MASK               (0xFFFFF000U)
#define VPU_H1_SWREG420_BF_12_SHIFT              (12U)
/*! BF_12 - Limit of chroma RFC buffer in unit of 64-bit. 0 indicating no limit. Send an IRQ if overflow. */
#define VPU_H1_SWREG420_BF_12(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG420_BF_12_SHIFT)) & VPU_H1_SWREG420_BF_12_MASK)
/*! @} */

/*! @name SWREG421 - VPU H1 Register 421 */
/*! @{ */

#define VPU_H1_SWREG421_BF_26_MASK               (0x7C000000U)
#define VPU_H1_SWREG421_BF_26_SHIFT              (26U)
/*! BF_26 - Modification Absolute Diff Pic Nums. */
#define VPU_H1_SWREG421_BF_26(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG421_BF_26_SHIFT)) & VPU_H1_SWREG421_BF_26_MASK)

#define VPU_H1_SWREG421_BF_31_MASK               (0x80000000U)
#define VPU_H1_SWREG421_BF_31_SHIFT              (31U)
/*! BF_31 - Modification Flag of Pic Nums. */
#define VPU_H1_SWREG421_BF_31(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG421_BF_31_SHIFT)) & VPU_H1_SWREG421_BF_31_MASK)
/*! @} */

/*! @name SWREG422 - VPU H1 Register 422 */
/*! @{ */

#define VPU_H1_SWREG422_BF_0_MASK                (0x1U)
#define VPU_H1_SWREG422_BF_0_SHIFT               (0U)
/*! BF_0 - Enable AXI Read ID and different burst. */
#define VPU_H1_SWREG422_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG422_BF_0_SHIFT)) & VPU_H1_SWREG422_BF_0_MASK)

#define VPU_H1_SWREG422_BF_8_MASK                (0xFF00U)
#define VPU_H1_SWREG422_BF_8_SHIFT               (8U)
/*! BF_8 - AXI Read ID for Input Channel 2. */
#define VPU_H1_SWREG422_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG422_BF_8_SHIFT)) & VPU_H1_SWREG422_BF_8_MASK)

#define VPU_H1_SWREG422_BF_16_MASK               (0xFF0000U)
#define VPU_H1_SWREG422_BF_16_SHIFT              (16U)
/*! BF_16 - AXI Read ID for Input Channel 1. */
#define VPU_H1_SWREG422_BF_16(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG422_BF_16_SHIFT)) & VPU_H1_SWREG422_BF_16_MASK)

#define VPU_H1_SWREG422_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG422_BF_24_SHIFT              (24U)
/*! BF_24 - AXI Read ID for Input Channel 0. */
#define VPU_H1_SWREG422_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG422_BF_24_SHIFT)) & VPU_H1_SWREG422_BF_24_MASK)
/*! @} */

/*! @name SWREG423 - VPU H1 Register 423 */
/*! @{ */

#define VPU_H1_SWREG423_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG423_BF_0_SHIFT               (0U)
/*! BF_0 - Base address MSB for reference luma compression table. */
#define VPU_H1_SWREG423_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG423_BF_0_SHIFT)) & VPU_H1_SWREG423_BF_0_MASK)
/*! @} */

/*! @name SWREG424 - VPU H1 Register 424 */
/*! @{ */

#define VPU_H1_SWREG424_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG424_BF_0_SHIFT               (0U)
/*! BF_0 - Base address MSB for reference chroma compression table */
#define VPU_H1_SWREG424_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG424_BF_0_SHIFT)) & VPU_H1_SWREG424_BF_0_MASK)
/*! @} */

/*! @name SWREG425 - VPU H1 Register 425 */
/*! @{ */

#define VPU_H1_SWREG425_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG425_BF_0_SHIFT               (0U)
/*! BF_0 - Base address MSB for reconstructed luma compression table */
#define VPU_H1_SWREG425_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG425_BF_0_SHIFT)) & VPU_H1_SWREG425_BF_0_MASK)
/*! @} */

/*! @name SWREG426 - VPU H1 Register 426 */
/*! @{ */

#define VPU_H1_SWREG426_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG426_BF_0_SHIFT               (0U)
/*! BF_0 - Base address for reconstructed chroma compression table */
#define VPU_H1_SWREG426_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG426_BF_0_SHIFT)) & VPU_H1_SWREG426_BF_0_MASK)
/*! @} */

/*! @name SWREG427 - VPU H1 Register 427 */
/*! @{ */

#define VPU_H1_SWREG427_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG427_BF_0_SHIFT               (0U)
/*! BF_0 - Base address MSB for second reference luma compression table */
#define VPU_H1_SWREG427_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG427_BF_0_SHIFT)) & VPU_H1_SWREG427_BF_0_MASK)
/*! @} */

/*! @name SWREG428 - VPU H1 Register 428 */
/*! @{ */

#define VPU_H1_SWREG428_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG428_BF_0_SHIFT               (0U)
/*! BF_0 - Base address MSB for second reference chroma compression table */
#define VPU_H1_SWREG428_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG428_BF_0_SHIFT)) & VPU_H1_SWREG428_BF_0_MASK)
/*! @} */

/*! @name SWREG429 - VPU H1 Register 429 */
/*! @{ */

#define VPU_H1_SWREG429_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG429_BF_0_SHIFT               (0U)
/*! BF_0 - high 32 bits of Base address for output stream data */
#define VPU_H1_SWREG429_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG429_BF_0_SHIFT)) & VPU_H1_SWREG429_BF_0_MASK)
/*! @} */

/*! @name SWREG430 - VPU H1 Register 430 */
/*! @{ */

#define VPU_H1_SWREG430_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG430_BF_0_SHIFT               (0U)
/*! BF_0 - high 32 bits of Base address for output control data */
#define VPU_H1_SWREG430_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG430_BF_0_SHIFT)) & VPU_H1_SWREG430_BF_0_MASK)
/*! @} */

/*! @name SWREG431 - VPU H1 Register 431 */
/*! @{ */

#define VPU_H1_SWREG431_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG431_BF_0_SHIFT               (0U)
/*! BF_0 - high 32 bits of Base address for reference luma */
#define VPU_H1_SWREG431_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG431_BF_0_SHIFT)) & VPU_H1_SWREG431_BF_0_MASK)
/*! @} */

/*! @name SWREG432 - VPU H1 Register 432 */
/*! @{ */

#define VPU_H1_SWREG432_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG432_BF_0_SHIFT               (0U)
/*! BF_0 - high 32 bits of Base address for reference chroma */
#define VPU_H1_SWREG432_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG432_BF_0_SHIFT)) & VPU_H1_SWREG432_BF_0_MASK)
/*! @} */

/*! @name SWREG433 - VPU H1 Register 433 */
/*! @{ */

#define VPU_H1_SWREG433_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG433_BF_0_SHIFT               (0U)
/*! BF_0 - high 32 bits of Base address for reconstructed luma */
#define VPU_H1_SWREG433_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG433_BF_0_SHIFT)) & VPU_H1_SWREG433_BF_0_MASK)
/*! @} */

/*! @name SWREG434 - VPU H1 Register 434 */
/*! @{ */

#define VPU_H1_SWREG434_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG434_BF_0_SHIFT               (0U)
/*! BF_0 - high 32 bits of Base address for reconstructed chroma */
#define VPU_H1_SWREG434_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG434_BF_0_SHIFT)) & VPU_H1_SWREG434_BF_0_MASK)
/*! @} */

/*! @name SWREG435 - VPU H1 Register 435 */
/*! @{ */

#define VPU_H1_SWREG435_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG435_BF_0_SHIFT               (0U)
/*! BF_0 - high 32 bits of Base address for input picture luma */
#define VPU_H1_SWREG435_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG435_BF_0_SHIFT)) & VPU_H1_SWREG435_BF_0_MASK)
/*! @} */

/*! @name SWREG436 - VPU H1 Register 436 */
/*! @{ */

#define VPU_H1_SWREG436_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG436_BF_0_SHIFT               (0U)
/*! BF_0 - high 32 bits of Base address for input picture cb */
#define VPU_H1_SWREG436_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG436_BF_0_SHIFT)) & VPU_H1_SWREG436_BF_0_MASK)
/*! @} */

/*! @name SWREG437 - VPU H1 Register 437 */
/*! @{ */

#define VPU_H1_SWREG437_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG437_BF_0_SHIFT               (0U)
/*! BF_0 - high 32 bits of Base address for input picture cr */
#define VPU_H1_SWREG437_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG437_BF_0_SHIFT)) & VPU_H1_SWREG437_BF_0_MASK)
/*! @} */

/*! @name SWREG438 - VPU H1 Register 438 */
/*! @{ */

#define VPU_H1_SWREG438_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG438_BF_0_SHIFT               (0U)
/*! BF_0 - high 32 bits of Base address for second reference luma */
#define VPU_H1_SWREG438_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG438_BF_0_SHIFT)) & VPU_H1_SWREG438_BF_0_MASK)
/*! @} */

/*! @name SWREG439 - VPU H1 Register 439 */
/*! @{ */

#define VPU_H1_SWREG439_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG439_BF_0_SHIFT               (0U)
/*! BF_0 - high 32 bits of Base address for second reference chroma */
#define VPU_H1_SWREG439_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG439_BF_0_SHIFT)) & VPU_H1_SWREG439_BF_0_MASK)
/*! @} */

/*! @name SWREG440 - VPU H1 Register 440 */
/*! @{ */

#define VPU_H1_SWREG440_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG440_BF_0_SHIFT               (0U)
/*! BF_0 - high 32 bits of H264 secondary ref pic base */
#define VPU_H1_SWREG440_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG440_BF_0_SHIFT)) & VPU_H1_SWREG440_BF_0_MASK)
/*! @} */

/*! @name SWREG441 - VPU H1 Register 441 */
/*! @{ */

#define VPU_H1_SWREG441_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG441_BF_0_SHIFT               (0U)
/*! BF_0 - high 32 bits of H264 secondary ref pic base */
#define VPU_H1_SWREG441_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG441_BF_0_SHIFT)) & VPU_H1_SWREG441_BF_0_MASK)
/*! @} */

/*! @name SWREG442 - VPU H1 Register 442 */
/*! @{ */

#define VPU_H1_SWREG442_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG442_BF_0_SHIFT               (0U)
/*! BF_0 - high 32 bits of Base address for next pic luminance */
#define VPU_H1_SWREG442_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG442_BF_0_SHIFT)) & VPU_H1_SWREG442_BF_0_MASK)
/*! @} */

/*! @name SWREG443 - VPU H1 Register 443 */
/*! @{ */

#define VPU_H1_SWREG443_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG443_BF_0_SHIFT               (0U)
/*! BF_0 - high 32 bits of Base address for cabac context tables (H264) or probability tables (VP8) */
#define VPU_H1_SWREG443_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG443_BF_0_SHIFT)) & VPU_H1_SWREG443_BF_0_MASK)
/*! @} */

/*! @name SWREG444 - VPU H1 Register 444 */
/*! @{ */

#define VPU_H1_SWREG444_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG444_BF_0_SHIFT               (0U)
/*! BF_0 - high 32 bits of Base address for MV output writing */
#define VPU_H1_SWREG444_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG444_BF_0_SHIFT)) & VPU_H1_SWREG444_BF_0_MASK)
/*! @} */

/*! @name SWREG445 - VPU H1 Register 445 */
/*! @{ */

#define VPU_H1_SWREG445_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG445_BF_0_SHIFT               (0U)
/*! BF_0 - high 32 bits of Base address for VP8 1st DCT partition */
#define VPU_H1_SWREG445_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG445_BF_0_SHIFT)) & VPU_H1_SWREG445_BF_0_MASK)
/*! @} */

/*! @name SWREG446 - VPU H1 Register 446 */
/*! @{ */

#define VPU_H1_SWREG446_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG446_BF_0_SHIFT               (0U)
/*! BF_0 - high 32 bits of Base address for VP8 2nd DCT partition */
#define VPU_H1_SWREG446_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG446_BF_0_SHIFT)) & VPU_H1_SWREG446_BF_0_MASK)
/*! @} */

/*! @name SWREG447 - VPU H1 Register 447 */
/*! @{ */

#define VPU_H1_SWREG447_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG447_BF_0_SHIFT               (0U)
/*! BF_0 - high 32 bits of Base address for VP8 counters for probability updates */
#define VPU_H1_SWREG447_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG447_BF_0_SHIFT)) & VPU_H1_SWREG447_BF_0_MASK)
/*! @} */

/*! @name SWREG448 - VPU H1 Register 448 */
/*! @{ */

#define VPU_H1_SWREG448_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG448_BF_0_SHIFT               (0U)
/*! BF_0 - high 32 bits of Base address for VP8 segmentation map. segmentId 2-bits/macroblock */
#define VPU_H1_SWREG448_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG448_BF_0_SHIFT)) & VPU_H1_SWREG448_BF_0_MASK)
/*! @} */

/*! @name SWREG449 - VPU H1 Register 449 */
/*! @{ */

#define VPU_H1_SWREG449_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG449_BF_0_SHIFT               (0U)
/*! BF_0 - high 32 bits of Base address for output of down-scaled encoder image in YUYV 4:2:2 format */
#define VPU_H1_SWREG449_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG449_BF_0_SHIFT)) & VPU_H1_SWREG449_BF_0_MASK)
/*! @} */

/*! @name SWREG450 - VPU H1 Register 450 */
/*! @{ */

#define VPU_H1_SWREG450_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG450_BF_0_SHIFT               (0U)
/*! BF_0 - high 32 bits of Base address for VP8 3rd DCT partition */
#define VPU_H1_SWREG450_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG450_BF_0_SHIFT)) & VPU_H1_SWREG450_BF_0_MASK)
/*! @} */

/*! @name SWREG451 - VPU H1 Register 451 */
/*! @{ */

#define VPU_H1_SWREG451_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG451_BF_0_SHIFT               (0U)
/*! BF_0 - high 32 bits of Base address for VP8 4th DCT partition */
#define VPU_H1_SWREG451_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG451_BF_0_SHIFT)) & VPU_H1_SWREG451_BF_0_MASK)
/*! @} */

/*! @name SWREG452 - VPU H1 Register 452 */
/*! @{ */

#define VPU_H1_SWREG452_BF_0_MASK                (0xFFFFU)
#define VPU_H1_SWREG452_BF_0_SHIFT               (0U)
/*! BF_0 - Number of Noisy MB */
#define VPU_H1_SWREG452_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG452_BF_0_SHIFT)) & VPU_H1_SWREG452_BF_0_MASK)

#define VPU_H1_SWREG452_BF_16_MASK               (0x7FF0000U)
#define VPU_H1_SWREG452_BF_16_SHIFT              (16U)
/*! BF_16 - Denoise filter strength */
#define VPU_H1_SWREG452_BF_16(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG452_BF_16_SHIFT)) & VPU_H1_SWREG452_BF_16_MASK)

#define VPU_H1_SWREG452_BF_31_MASK               (0x80000000U)
#define VPU_H1_SWREG452_BF_31_SHIFT              (31U)
/*! BF_31 - Enable/disable the de-noise function */
#define VPU_H1_SWREG452_BF_31(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG452_BF_31_SHIFT)) & VPU_H1_SWREG452_BF_31_MASK)
/*! @} */

/*! @name SWREG453 - VPU H1 Register 453 */
/*! @{ */

#define VPU_H1_SWREG453_BF_0_MASK                (0xFFFFU)
#define VPU_H1_SWREG453_BF_0_SHIFT               (0U)
/*! BF_0 - Max noise level */
#define VPU_H1_SWREG453_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG453_BF_0_SHIFT)) & VPU_H1_SWREG453_BF_0_MASK)
/*! @} */

/*! @name SWREG454 - VPU H1 Register 454 */
/*! @{ */

#define VPU_H1_SWREG454_BF_0_MASK                (0xFFFU)
#define VPU_H1_SWREG454_BF_0_SHIFT               (0U)
/*! BF_0 - Noise level inverted for luma */
#define VPU_H1_SWREG454_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG454_BF_0_SHIFT)) & VPU_H1_SWREG454_BF_0_MASK)

#define VPU_H1_SWREG454_BF_16_MASK               (0xFFF0000U)
#define VPU_H1_SWREG454_BF_16_SHIFT              (16U)
/*! BF_16 - Noise level inverted for chroma */
#define VPU_H1_SWREG454_BF_16(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG454_BF_16_SHIFT)) & VPU_H1_SWREG454_BF_16_MASK)
/*! @} */

/*! @name SWREG455 - VPU H1 Register 455 */
/*! @{ */

#define VPU_H1_SWREG455_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG455_BF_0_SHIFT               (0U)
/*! BF_0 - calculated sigma of coding frame */
#define VPU_H1_SWREG455_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG455_BF_0_SHIFT)) & VPU_H1_SWREG455_BF_0_MASK)
/*! @} */

/*! @name SWREG456 - VPU H1 Register 456 */
/*! @{ */

#define VPU_H1_SWREG456_BF_0_MASK                (0xFFFFFFFFU)
#define VPU_H1_SWREG456_BF_0_SHIFT               (0U)
/*! BF_0 - noise sigma for current frame */
#define VPU_H1_SWREG456_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG456_BF_0_SHIFT)) & VPU_H1_SWREG456_BF_0_MASK)
/*! @} */

/*! @name SWREG457 - VPU H1 Register 457 */
/*! @{ */

#define VPU_H1_SWREG457_BF_0_MASK                (0xFFU)
#define VPU_H1_SWREG457_BF_0_SHIFT               (0U)
/*! BF_0 - Denoise Filter Parameters Set 1, No.0. */
#define VPU_H1_SWREG457_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG457_BF_0_SHIFT)) & VPU_H1_SWREG457_BF_0_MASK)

#define VPU_H1_SWREG457_BF_8_MASK                (0xFF00U)
#define VPU_H1_SWREG457_BF_8_SHIFT               (8U)
/*! BF_8 - Denoise Filter Parameters Set 1, No.1. */
#define VPU_H1_SWREG457_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG457_BF_8_SHIFT)) & VPU_H1_SWREG457_BF_8_MASK)

#define VPU_H1_SWREG457_BF_16_MASK               (0xFF0000U)
#define VPU_H1_SWREG457_BF_16_SHIFT              (16U)
/*! BF_16 - Denoise Filter Parameters Set 1, No.2. */
#define VPU_H1_SWREG457_BF_16(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG457_BF_16_SHIFT)) & VPU_H1_SWREG457_BF_16_MASK)

#define VPU_H1_SWREG457_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG457_BF_24_SHIFT              (24U)
/*! BF_24 - Denoise Filter Parameters Set 1, No.3. */
#define VPU_H1_SWREG457_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG457_BF_24_SHIFT)) & VPU_H1_SWREG457_BF_24_MASK)
/*! @} */

/*! @name SWREG458 - VPU H1 Register 458 */
/*! @{ */

#define VPU_H1_SWREG458_BF_0_MASK                (0xFFU)
#define VPU_H1_SWREG458_BF_0_SHIFT               (0U)
/*! BF_0 - Denoise Filter Parameters Set 1, No.4. */
#define VPU_H1_SWREG458_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG458_BF_0_SHIFT)) & VPU_H1_SWREG458_BF_0_MASK)

#define VPU_H1_SWREG458_BF_8_MASK                (0xFF00U)
#define VPU_H1_SWREG458_BF_8_SHIFT               (8U)
/*! BF_8 - Denoise Filter Parameters Set 1, No.5. */
#define VPU_H1_SWREG458_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG458_BF_8_SHIFT)) & VPU_H1_SWREG458_BF_8_MASK)

#define VPU_H1_SWREG458_BF_16_MASK               (0xFF0000U)
#define VPU_H1_SWREG458_BF_16_SHIFT              (16U)
/*! BF_16 - Denoise Filter Parameters Set 1, No.6. */
#define VPU_H1_SWREG458_BF_16(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG458_BF_16_SHIFT)) & VPU_H1_SWREG458_BF_16_MASK)

#define VPU_H1_SWREG458_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG458_BF_24_SHIFT              (24U)
/*! BF_24 - Denoise Filter Parameters Set 1, No.7. */
#define VPU_H1_SWREG458_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG458_BF_24_SHIFT)) & VPU_H1_SWREG458_BF_24_MASK)
/*! @} */

/*! @name SWREG459 - VPU H1 Register 459 */
/*! @{ */

#define VPU_H1_SWREG459_BF_0_MASK                (0xFFU)
#define VPU_H1_SWREG459_BF_0_SHIFT               (0U)
/*! BF_0 - Denoise Filter Parameters Set 1, No.8. */
#define VPU_H1_SWREG459_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG459_BF_0_SHIFT)) & VPU_H1_SWREG459_BF_0_MASK)

#define VPU_H1_SWREG459_BF_8_MASK                (0xFF00U)
#define VPU_H1_SWREG459_BF_8_SHIFT               (8U)
/*! BF_8 - Denoise Filter Parameters Set 1, No.9. */
#define VPU_H1_SWREG459_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG459_BF_8_SHIFT)) & VPU_H1_SWREG459_BF_8_MASK)

#define VPU_H1_SWREG459_BF_16_MASK               (0xFF0000U)
#define VPU_H1_SWREG459_BF_16_SHIFT              (16U)
/*! BF_16 - Denoise Filter Parameters Set 1, No.10. */
#define VPU_H1_SWREG459_BF_16(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG459_BF_16_SHIFT)) & VPU_H1_SWREG459_BF_16_MASK)

#define VPU_H1_SWREG459_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG459_BF_24_SHIFT              (24U)
/*! BF_24 - Denoise Filter Parameters Set 1, No.11. */
#define VPU_H1_SWREG459_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG459_BF_24_SHIFT)) & VPU_H1_SWREG459_BF_24_MASK)
/*! @} */

/*! @name SWREG460 - VPU H1 Register 460 */
/*! @{ */

#define VPU_H1_SWREG460_BF_0_MASK                (0xFFU)
#define VPU_H1_SWREG460_BF_0_SHIFT               (0U)
/*! BF_0 - Denoise Filter Parameters Set 1, No.12. */
#define VPU_H1_SWREG460_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG460_BF_0_SHIFT)) & VPU_H1_SWREG460_BF_0_MASK)

#define VPU_H1_SWREG460_BF_8_MASK                (0xFF00U)
#define VPU_H1_SWREG460_BF_8_SHIFT               (8U)
/*! BF_8 - Denoise Filter Parameters Set 1, No.13. */
#define VPU_H1_SWREG460_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG460_BF_8_SHIFT)) & VPU_H1_SWREG460_BF_8_MASK)

#define VPU_H1_SWREG460_BF_16_MASK               (0xFF0000U)
#define VPU_H1_SWREG460_BF_16_SHIFT              (16U)
/*! BF_16 - Denoise Filter Parameters Set 1, No.14. */
#define VPU_H1_SWREG460_BF_16(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG460_BF_16_SHIFT)) & VPU_H1_SWREG460_BF_16_MASK)

#define VPU_H1_SWREG460_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG460_BF_24_SHIFT              (24U)
/*! BF_24 - Denoise Filter Parameters Set 1, No.15. */
#define VPU_H1_SWREG460_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG460_BF_24_SHIFT)) & VPU_H1_SWREG460_BF_24_MASK)
/*! @} */

/*! @name SWREG461 - VPU H1 Register 461 */
/*! @{ */

#define VPU_H1_SWREG461_BF_0_MASK                (0xFFU)
#define VPU_H1_SWREG461_BF_0_SHIFT               (0U)
/*! BF_0 - Denoise Filter Parameters Set 2, No.0. */
#define VPU_H1_SWREG461_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG461_BF_0_SHIFT)) & VPU_H1_SWREG461_BF_0_MASK)

#define VPU_H1_SWREG461_BF_8_MASK                (0xFF00U)
#define VPU_H1_SWREG461_BF_8_SHIFT               (8U)
/*! BF_8 - Denoise Filter Parameters Set 2, No.1. */
#define VPU_H1_SWREG461_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG461_BF_8_SHIFT)) & VPU_H1_SWREG461_BF_8_MASK)

#define VPU_H1_SWREG461_BF_16_MASK               (0xFF0000U)
#define VPU_H1_SWREG461_BF_16_SHIFT              (16U)
/*! BF_16 - Denoise Filter Parameters Set 2, No.2. */
#define VPU_H1_SWREG461_BF_16(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG461_BF_16_SHIFT)) & VPU_H1_SWREG461_BF_16_MASK)

#define VPU_H1_SWREG461_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG461_BF_24_SHIFT              (24U)
/*! BF_24 - Denoise Filter Parameters Set 2, No.3. */
#define VPU_H1_SWREG461_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG461_BF_24_SHIFT)) & VPU_H1_SWREG461_BF_24_MASK)
/*! @} */

/*! @name SWREG462 - VPU H1 Register 462 */
/*! @{ */

#define VPU_H1_SWREG462_BF_0_MASK                (0xFFU)
#define VPU_H1_SWREG462_BF_0_SHIFT               (0U)
/*! BF_0 - Denoise Filter Parameters Set 2, No.4. */
#define VPU_H1_SWREG462_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG462_BF_0_SHIFT)) & VPU_H1_SWREG462_BF_0_MASK)

#define VPU_H1_SWREG462_BF_8_MASK                (0xFF00U)
#define VPU_H1_SWREG462_BF_8_SHIFT               (8U)
/*! BF_8 - Denoise Filter Parameters Set 2, No.5. */
#define VPU_H1_SWREG462_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG462_BF_8_SHIFT)) & VPU_H1_SWREG462_BF_8_MASK)

#define VPU_H1_SWREG462_BF_16_MASK               (0xFF0000U)
#define VPU_H1_SWREG462_BF_16_SHIFT              (16U)
/*! BF_16 - Denoise Filter Parameters Set 2, No.6. */
#define VPU_H1_SWREG462_BF_16(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG462_BF_16_SHIFT)) & VPU_H1_SWREG462_BF_16_MASK)

#define VPU_H1_SWREG462_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG462_BF_24_SHIFT              (24U)
/*! BF_24 - Denoise Filter Parameters Set 2, No.7. */
#define VPU_H1_SWREG462_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG462_BF_24_SHIFT)) & VPU_H1_SWREG462_BF_24_MASK)
/*! @} */

/*! @name SWREG463 - VPU H1 Register 463 */
/*! @{ */

#define VPU_H1_SWREG463_BF_0_MASK                (0xFFU)
#define VPU_H1_SWREG463_BF_0_SHIFT               (0U)
/*! BF_0 - Denoise Filter Parameters Set 2, No.8. */
#define VPU_H1_SWREG463_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG463_BF_0_SHIFT)) & VPU_H1_SWREG463_BF_0_MASK)

#define VPU_H1_SWREG463_BF_8_MASK                (0xFF00U)
#define VPU_H1_SWREG463_BF_8_SHIFT               (8U)
/*! BF_8 - Denoise Filter Parameters Set 2, No.9. */
#define VPU_H1_SWREG463_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG463_BF_8_SHIFT)) & VPU_H1_SWREG463_BF_8_MASK)

#define VPU_H1_SWREG463_BF_16_MASK               (0xFF0000U)
#define VPU_H1_SWREG463_BF_16_SHIFT              (16U)
/*! BF_16 - Denoise Filter Parameters Set 2, No.10. */
#define VPU_H1_SWREG463_BF_16(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG463_BF_16_SHIFT)) & VPU_H1_SWREG463_BF_16_MASK)

#define VPU_H1_SWREG463_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG463_BF_24_SHIFT              (24U)
/*! BF_24 - Denoise Filter Parameters Set 2, No.11. */
#define VPU_H1_SWREG463_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG463_BF_24_SHIFT)) & VPU_H1_SWREG463_BF_24_MASK)
/*! @} */

/*! @name SWREG464 - VPU H1 Register 464 */
/*! @{ */

#define VPU_H1_SWREG464_BF_0_MASK                (0xFFU)
#define VPU_H1_SWREG464_BF_0_SHIFT               (0U)
/*! BF_0 - Denoise Filter Parameters Set 2, No.12. */
#define VPU_H1_SWREG464_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG464_BF_0_SHIFT)) & VPU_H1_SWREG464_BF_0_MASK)

#define VPU_H1_SWREG464_BF_8_MASK                (0xFF00U)
#define VPU_H1_SWREG464_BF_8_SHIFT               (8U)
/*! BF_8 - Denoise Filter Parameters Set 2, No.13. */
#define VPU_H1_SWREG464_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG464_BF_8_SHIFT)) & VPU_H1_SWREG464_BF_8_MASK)

#define VPU_H1_SWREG464_BF_16_MASK               (0xFF0000U)
#define VPU_H1_SWREG464_BF_16_SHIFT              (16U)
/*! BF_16 - Denoise Filter Parameters Set 2, No.14. */
#define VPU_H1_SWREG464_BF_16(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG464_BF_16_SHIFT)) & VPU_H1_SWREG464_BF_16_MASK)

#define VPU_H1_SWREG464_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG464_BF_24_SHIFT              (24U)
/*! BF_24 - Denoise Filter Parameters Set 2, No.15. */
#define VPU_H1_SWREG464_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG464_BF_24_SHIFT)) & VPU_H1_SWREG464_BF_24_MASK)
/*! @} */

/*! @name SWREG465 - VPU H1 Register 465 */
/*! @{ */

#define VPU_H1_SWREG465_BF_0_MASK                (0xFFU)
#define VPU_H1_SWREG465_BF_0_SHIFT               (0U)
/*! BF_0 - Denoise Filter Parameters Set 3, No.0. */
#define VPU_H1_SWREG465_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG465_BF_0_SHIFT)) & VPU_H1_SWREG465_BF_0_MASK)

#define VPU_H1_SWREG465_BF_8_MASK                (0xFF00U)
#define VPU_H1_SWREG465_BF_8_SHIFT               (8U)
/*! BF_8 - Denoise Filter Parameters Set 3, No.1. */
#define VPU_H1_SWREG465_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG465_BF_8_SHIFT)) & VPU_H1_SWREG465_BF_8_MASK)

#define VPU_H1_SWREG465_BF_16_MASK               (0xFF0000U)
#define VPU_H1_SWREG465_BF_16_SHIFT              (16U)
/*! BF_16 - Denoise Filter Parameters Set 3, No.2. */
#define VPU_H1_SWREG465_BF_16(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG465_BF_16_SHIFT)) & VPU_H1_SWREG465_BF_16_MASK)

#define VPU_H1_SWREG465_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG465_BF_24_SHIFT              (24U)
/*! BF_24 - Denoise Filter Parameters Set 3, No.3. */
#define VPU_H1_SWREG465_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG465_BF_24_SHIFT)) & VPU_H1_SWREG465_BF_24_MASK)
/*! @} */

/*! @name SWREG466 - VPU H1 Register 466 */
/*! @{ */

#define VPU_H1_SWREG466_BF_0_MASK                (0xFFU)
#define VPU_H1_SWREG466_BF_0_SHIFT               (0U)
/*! BF_0 - Denoise Filter Parameters Set 3, No.4. */
#define VPU_H1_SWREG466_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG466_BF_0_SHIFT)) & VPU_H1_SWREG466_BF_0_MASK)

#define VPU_H1_SWREG466_BF_8_MASK                (0xFF00U)
#define VPU_H1_SWREG466_BF_8_SHIFT               (8U)
/*! BF_8 - Denoise Filter Parameters Set 3, No.5. */
#define VPU_H1_SWREG466_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG466_BF_8_SHIFT)) & VPU_H1_SWREG466_BF_8_MASK)

#define VPU_H1_SWREG466_BF_16_MASK               (0xFF0000U)
#define VPU_H1_SWREG466_BF_16_SHIFT              (16U)
/*! BF_16 - Denoise Filter Parameters Set 3, No.6. */
#define VPU_H1_SWREG466_BF_16(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG466_BF_16_SHIFT)) & VPU_H1_SWREG466_BF_16_MASK)

#define VPU_H1_SWREG466_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG466_BF_24_SHIFT              (24U)
/*! BF_24 - Denoise Filter Parameters Set 3, No.7. */
#define VPU_H1_SWREG466_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG466_BF_24_SHIFT)) & VPU_H1_SWREG466_BF_24_MASK)
/*! @} */

/*! @name SWREG467 - VPU H1 Register 467 */
/*! @{ */

#define VPU_H1_SWREG467_BF_0_MASK                (0xFFU)
#define VPU_H1_SWREG467_BF_0_SHIFT               (0U)
/*! BF_0 - Denoise Filter Parameters Set 3, No.8. */
#define VPU_H1_SWREG467_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG467_BF_0_SHIFT)) & VPU_H1_SWREG467_BF_0_MASK)

#define VPU_H1_SWREG467_BF_8_MASK                (0xFF00U)
#define VPU_H1_SWREG467_BF_8_SHIFT               (8U)
/*! BF_8 - Denoise Filter Parameters Set 3, No.9. */
#define VPU_H1_SWREG467_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG467_BF_8_SHIFT)) & VPU_H1_SWREG467_BF_8_MASK)

#define VPU_H1_SWREG467_BF_16_MASK               (0xFF0000U)
#define VPU_H1_SWREG467_BF_16_SHIFT              (16U)
/*! BF_16 - Denoise Filter Parameters Set 3, No.10. */
#define VPU_H1_SWREG467_BF_16(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG467_BF_16_SHIFT)) & VPU_H1_SWREG467_BF_16_MASK)

#define VPU_H1_SWREG467_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG467_BF_24_SHIFT              (24U)
/*! BF_24 - Denoise Filter Parameters Set 3, No.11. */
#define VPU_H1_SWREG467_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG467_BF_24_SHIFT)) & VPU_H1_SWREG467_BF_24_MASK)
/*! @} */

/*! @name SWREG468 - VPU H1 Register 468 */
/*! @{ */

#define VPU_H1_SWREG468_BF_0_MASK                (0xFFU)
#define VPU_H1_SWREG468_BF_0_SHIFT               (0U)
/*! BF_0 - Denoise Filter Parameters Set 3, No.12. */
#define VPU_H1_SWREG468_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG468_BF_0_SHIFT)) & VPU_H1_SWREG468_BF_0_MASK)

#define VPU_H1_SWREG468_BF_8_MASK                (0xFF00U)
#define VPU_H1_SWREG468_BF_8_SHIFT               (8U)
/*! BF_8 - Denoise Filter Parameters Set 3, No.13. */
#define VPU_H1_SWREG468_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG468_BF_8_SHIFT)) & VPU_H1_SWREG468_BF_8_MASK)

#define VPU_H1_SWREG468_BF_16_MASK               (0xFF0000U)
#define VPU_H1_SWREG468_BF_16_SHIFT              (16U)
/*! BF_16 - Denoise Filter Parameters Set 3, No.14. */
#define VPU_H1_SWREG468_BF_16(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG468_BF_16_SHIFT)) & VPU_H1_SWREG468_BF_16_MASK)

#define VPU_H1_SWREG468_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG468_BF_24_SHIFT              (24U)
/*! BF_24 - Denoise Filter Parameters Set 3, No.15. */
#define VPU_H1_SWREG468_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG468_BF_24_SHIFT)) & VPU_H1_SWREG468_BF_24_MASK)
/*! @} */

/*! @name SWREG469 - VPU H1 Register 469 */
/*! @{ */

#define VPU_H1_SWREG469_BF_0_MASK                (0xFFU)
#define VPU_H1_SWREG469_BF_0_SHIFT               (0U)
/*! BF_0 - Denoise Filter Parameters Set 3, No.16. */
#define VPU_H1_SWREG469_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG469_BF_0_SHIFT)) & VPU_H1_SWREG469_BF_0_MASK)

#define VPU_H1_SWREG469_BF_8_MASK                (0xFF00U)
#define VPU_H1_SWREG469_BF_8_SHIFT               (8U)
/*! BF_8 - Denoise Filter Parameters Set 3, No.17. */
#define VPU_H1_SWREG469_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG469_BF_8_SHIFT)) & VPU_H1_SWREG469_BF_8_MASK)

#define VPU_H1_SWREG469_BF_16_MASK               (0xFF0000U)
#define VPU_H1_SWREG469_BF_16_SHIFT              (16U)
/*! BF_16 - Denoise Filter Parameters Set 3, No.18. */
#define VPU_H1_SWREG469_BF_16(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG469_BF_16_SHIFT)) & VPU_H1_SWREG469_BF_16_MASK)

#define VPU_H1_SWREG469_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG469_BF_24_SHIFT              (24U)
/*! BF_24 - Denoise Filter Parameters Set 3, No.19. */
#define VPU_H1_SWREG469_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG469_BF_24_SHIFT)) & VPU_H1_SWREG469_BF_24_MASK)
/*! @} */

/*! @name SWREG470 - VPU H1 Register 470 */
/*! @{ */

#define VPU_H1_SWREG470_BF_0_MASK                (0xFFU)
#define VPU_H1_SWREG470_BF_0_SHIFT               (0U)
/*! BF_0 - Denoise Filter Parameters Set 3, No.20. */
#define VPU_H1_SWREG470_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG470_BF_0_SHIFT)) & VPU_H1_SWREG470_BF_0_MASK)

#define VPU_H1_SWREG470_BF_8_MASK                (0xFF00U)
#define VPU_H1_SWREG470_BF_8_SHIFT               (8U)
/*! BF_8 - Denoise Filter Parameters Set 3, No.21. */
#define VPU_H1_SWREG470_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG470_BF_8_SHIFT)) & VPU_H1_SWREG470_BF_8_MASK)

#define VPU_H1_SWREG470_BF_16_MASK               (0xFF0000U)
#define VPU_H1_SWREG470_BF_16_SHIFT              (16U)
/*! BF_16 - Denoise Filter Parameters Set 3, No.22. */
#define VPU_H1_SWREG470_BF_16(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG470_BF_16_SHIFT)) & VPU_H1_SWREG470_BF_16_MASK)

#define VPU_H1_SWREG470_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG470_BF_24_SHIFT              (24U)
/*! BF_24 - Denoise Filter Parameters Set 3, No.23. */
#define VPU_H1_SWREG470_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG470_BF_24_SHIFT)) & VPU_H1_SWREG470_BF_24_MASK)
/*! @} */

/*! @name SWREG471 - VPU H1 Register 471 */
/*! @{ */

#define VPU_H1_SWREG471_BF_0_MASK                (0xFFU)
#define VPU_H1_SWREG471_BF_0_SHIFT               (0U)
/*! BF_0 - Denoise Filter Parameters Set 3, No.24. */
#define VPU_H1_SWREG471_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG471_BF_0_SHIFT)) & VPU_H1_SWREG471_BF_0_MASK)

#define VPU_H1_SWREG471_BF_8_MASK                (0xFF00U)
#define VPU_H1_SWREG471_BF_8_SHIFT               (8U)
/*! BF_8 - Denoise Filter Parameters Set 3, No.25. */
#define VPU_H1_SWREG471_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG471_BF_8_SHIFT)) & VPU_H1_SWREG471_BF_8_MASK)

#define VPU_H1_SWREG471_BF_16_MASK               (0xFF0000U)
#define VPU_H1_SWREG471_BF_16_SHIFT              (16U)
/*! BF_16 - Denoise Filter Parameters Set 3, No.26. */
#define VPU_H1_SWREG471_BF_16(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG471_BF_16_SHIFT)) & VPU_H1_SWREG471_BF_16_MASK)

#define VPU_H1_SWREG471_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG471_BF_24_SHIFT              (24U)
/*! BF_24 - Denoise Filter Parameters Set 3, No.27. */
#define VPU_H1_SWREG471_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG471_BF_24_SHIFT)) & VPU_H1_SWREG471_BF_24_MASK)
/*! @} */

/*! @name SWREG472 - VPU H1 Register 472 */
/*! @{ */

#define VPU_H1_SWREG472_BF_0_MASK                (0xFFU)
#define VPU_H1_SWREG472_BF_0_SHIFT               (0U)
/*! BF_0 - Denoise Filter Parameters Set 3, No.28. */
#define VPU_H1_SWREG472_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG472_BF_0_SHIFT)) & VPU_H1_SWREG472_BF_0_MASK)

#define VPU_H1_SWREG472_BF_8_MASK                (0xFF00U)
#define VPU_H1_SWREG472_BF_8_SHIFT               (8U)
/*! BF_8 - Denoise Filter Parameters Set 3, No.29. */
#define VPU_H1_SWREG472_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG472_BF_8_SHIFT)) & VPU_H1_SWREG472_BF_8_MASK)

#define VPU_H1_SWREG472_BF_16_MASK               (0xFF0000U)
#define VPU_H1_SWREG472_BF_16_SHIFT              (16U)
/*! BF_16 - Denoise Filter Parameters Set 3, No.30. */
#define VPU_H1_SWREG472_BF_16(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG472_BF_16_SHIFT)) & VPU_H1_SWREG472_BF_16_MASK)

#define VPU_H1_SWREG472_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG472_BF_24_SHIFT              (24U)
/*! BF_24 - Denoise Filter Parameters Set 3, No.31. */
#define VPU_H1_SWREG472_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG472_BF_24_SHIFT)) & VPU_H1_SWREG472_BF_24_MASK)
/*! @} */

/*! @name SWREG473 - VPU H1 Register 473 */
/*! @{ */

#define VPU_H1_SWREG473_BF_0_MASK                (0xFFU)
#define VPU_H1_SWREG473_BF_0_SHIFT               (0U)
/*! BF_0 - Denoise Filter Parameters Set 3, No.32. */
#define VPU_H1_SWREG473_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG473_BF_0_SHIFT)) & VPU_H1_SWREG473_BF_0_MASK)

#define VPU_H1_SWREG473_BF_8_MASK                (0xFF00U)
#define VPU_H1_SWREG473_BF_8_SHIFT               (8U)
/*! BF_8 - Denoise Filter Parameters Set 3, No.33. */
#define VPU_H1_SWREG473_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG473_BF_8_SHIFT)) & VPU_H1_SWREG473_BF_8_MASK)

#define VPU_H1_SWREG473_BF_16_MASK               (0xFF0000U)
#define VPU_H1_SWREG473_BF_16_SHIFT              (16U)
/*! BF_16 - Denoise Filter Parameters Set 3, No.34. */
#define VPU_H1_SWREG473_BF_16(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG473_BF_16_SHIFT)) & VPU_H1_SWREG473_BF_16_MASK)

#define VPU_H1_SWREG473_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG473_BF_24_SHIFT              (24U)
/*! BF_24 - Denoise Filter Parameters Set 3, No.35. */
#define VPU_H1_SWREG473_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG473_BF_24_SHIFT)) & VPU_H1_SWREG473_BF_24_MASK)
/*! @} */

/*! @name SWREG474 - VPU H1 Register 474 */
/*! @{ */

#define VPU_H1_SWREG474_BF_0_MASK                (0xFFU)
#define VPU_H1_SWREG474_BF_0_SHIFT               (0U)
/*! BF_0 - Denoise Filter Parameters Set 3, No.36. */
#define VPU_H1_SWREG474_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG474_BF_0_SHIFT)) & VPU_H1_SWREG474_BF_0_MASK)

#define VPU_H1_SWREG474_BF_8_MASK                (0xFF00U)
#define VPU_H1_SWREG474_BF_8_SHIFT               (8U)
/*! BF_8 - Denoise Filter Parameters Set 3, No.37. */
#define VPU_H1_SWREG474_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG474_BF_8_SHIFT)) & VPU_H1_SWREG474_BF_8_MASK)

#define VPU_H1_SWREG474_BF_16_MASK               (0xFF0000U)
#define VPU_H1_SWREG474_BF_16_SHIFT              (16U)
/*! BF_16 - Denoise Filter Parameters Set 3, No.38. */
#define VPU_H1_SWREG474_BF_16(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG474_BF_16_SHIFT)) & VPU_H1_SWREG474_BF_16_MASK)

#define VPU_H1_SWREG474_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG474_BF_24_SHIFT              (24U)
/*! BF_24 - Denoise Filter Parameters Set 3, No.39. */
#define VPU_H1_SWREG474_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG474_BF_24_SHIFT)) & VPU_H1_SWREG474_BF_24_MASK)
/*! @} */

/*! @name SWREG475 - VPU H1 Register 475 */
/*! @{ */

#define VPU_H1_SWREG475_BF_0_MASK                (0xFFU)
#define VPU_H1_SWREG475_BF_0_SHIFT               (0U)
/*! BF_0 - Denoise Filter Parameters Set 3, No.40. */
#define VPU_H1_SWREG475_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG475_BF_0_SHIFT)) & VPU_H1_SWREG475_BF_0_MASK)

#define VPU_H1_SWREG475_BF_8_MASK                (0xFF00U)
#define VPU_H1_SWREG475_BF_8_SHIFT               (8U)
/*! BF_8 - Denoise Filter Parameters Set 3, No.41. */
#define VPU_H1_SWREG475_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG475_BF_8_SHIFT)) & VPU_H1_SWREG475_BF_8_MASK)

#define VPU_H1_SWREG475_BF_16_MASK               (0xFF0000U)
#define VPU_H1_SWREG475_BF_16_SHIFT              (16U)
/*! BF_16 - Denoise Filter Parameters Set 3, No.42. */
#define VPU_H1_SWREG475_BF_16(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG475_BF_16_SHIFT)) & VPU_H1_SWREG475_BF_16_MASK)

#define VPU_H1_SWREG475_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG475_BF_24_SHIFT              (24U)
/*! BF_24 - Denoise Filter Parameters Set 3, No.43. */
#define VPU_H1_SWREG475_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG475_BF_24_SHIFT)) & VPU_H1_SWREG475_BF_24_MASK)
/*! @} */

/*! @name SWREG476 - VPU H1 Register 476 */
/*! @{ */

#define VPU_H1_SWREG476_BF_0_MASK                (0xFFU)
#define VPU_H1_SWREG476_BF_0_SHIFT               (0U)
/*! BF_0 - Denoise Filter Parameters Set 3, No.44. */
#define VPU_H1_SWREG476_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG476_BF_0_SHIFT)) & VPU_H1_SWREG476_BF_0_MASK)

#define VPU_H1_SWREG476_BF_8_MASK                (0xFF00U)
#define VPU_H1_SWREG476_BF_8_SHIFT               (8U)
/*! BF_8 - Denoise Filter Parameters Set 3, No.45. */
#define VPU_H1_SWREG476_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG476_BF_8_SHIFT)) & VPU_H1_SWREG476_BF_8_MASK)

#define VPU_H1_SWREG476_BF_16_MASK               (0xFF0000U)
#define VPU_H1_SWREG476_BF_16_SHIFT              (16U)
/*! BF_16 - Denoise Filter Parameters Set 3, No.46. */
#define VPU_H1_SWREG476_BF_16(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG476_BF_16_SHIFT)) & VPU_H1_SWREG476_BF_16_MASK)

#define VPU_H1_SWREG476_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG476_BF_24_SHIFT              (24U)
/*! BF_24 - Denoise Filter Parameters Set 3, No.47. */
#define VPU_H1_SWREG476_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG476_BF_24_SHIFT)) & VPU_H1_SWREG476_BF_24_MASK)
/*! @} */

/*! @name SWREG477 - VPU H1 Register 477 */
/*! @{ */

#define VPU_H1_SWREG477_BF_0_MASK                (0xFFU)
#define VPU_H1_SWREG477_BF_0_SHIFT               (0U)
/*! BF_0 - Denoise Filter Parameters Set 3, No.48. */
#define VPU_H1_SWREG477_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG477_BF_0_SHIFT)) & VPU_H1_SWREG477_BF_0_MASK)

#define VPU_H1_SWREG477_BF_8_MASK                (0xFF00U)
#define VPU_H1_SWREG477_BF_8_SHIFT               (8U)
/*! BF_8 - Denoise Filter Parameters Set 3, No.49. */
#define VPU_H1_SWREG477_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG477_BF_8_SHIFT)) & VPU_H1_SWREG477_BF_8_MASK)

#define VPU_H1_SWREG477_BF_16_MASK               (0xFF0000U)
#define VPU_H1_SWREG477_BF_16_SHIFT              (16U)
/*! BF_16 - Denoise Filter Parameters Set 3, No.50. */
#define VPU_H1_SWREG477_BF_16(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG477_BF_16_SHIFT)) & VPU_H1_SWREG477_BF_16_MASK)

#define VPU_H1_SWREG477_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG477_BF_24_SHIFT              (24U)
/*! BF_24 - Denoise Filter Parameters Set 3, No.51. */
#define VPU_H1_SWREG477_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG477_BF_24_SHIFT)) & VPU_H1_SWREG477_BF_24_MASK)
/*! @} */

/*! @name SWREG478 - VPU H1 Register 478 */
/*! @{ */

#define VPU_H1_SWREG478_BF_0_MASK                (0xFFU)
#define VPU_H1_SWREG478_BF_0_SHIFT               (0U)
/*! BF_0 - Denoise Filter Parameters Set 3, No.52. */
#define VPU_H1_SWREG478_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG478_BF_0_SHIFT)) & VPU_H1_SWREG478_BF_0_MASK)

#define VPU_H1_SWREG478_BF_8_MASK                (0xFF00U)
#define VPU_H1_SWREG478_BF_8_SHIFT               (8U)
/*! BF_8 - Denoise Filter Parameters Set 3, No.53. */
#define VPU_H1_SWREG478_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG478_BF_8_SHIFT)) & VPU_H1_SWREG478_BF_8_MASK)

#define VPU_H1_SWREG478_BF_16_MASK               (0xFF0000U)
#define VPU_H1_SWREG478_BF_16_SHIFT              (16U)
/*! BF_16 - Denoise Filter Parameters Set 3, No.54. */
#define VPU_H1_SWREG478_BF_16(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG478_BF_16_SHIFT)) & VPU_H1_SWREG478_BF_16_MASK)

#define VPU_H1_SWREG478_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG478_BF_24_SHIFT              (24U)
/*! BF_24 - Denoise Filter Parameters Set 3, No.55. */
#define VPU_H1_SWREG478_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG478_BF_24_SHIFT)) & VPU_H1_SWREG478_BF_24_MASK)
/*! @} */

/*! @name SWREG479 - VPU H1 Register 479 */
/*! @{ */

#define VPU_H1_SWREG479_BF_0_MASK                (0xFFU)
#define VPU_H1_SWREG479_BF_0_SHIFT               (0U)
/*! BF_0 - Denoise Filter Parameters Set 3, No.56. */
#define VPU_H1_SWREG479_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG479_BF_0_SHIFT)) & VPU_H1_SWREG479_BF_0_MASK)

#define VPU_H1_SWREG479_BF_8_MASK                (0xFF00U)
#define VPU_H1_SWREG479_BF_8_SHIFT               (8U)
/*! BF_8 - Denoise Filter Parameters Set 3, No.57. */
#define VPU_H1_SWREG479_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG479_BF_8_SHIFT)) & VPU_H1_SWREG479_BF_8_MASK)

#define VPU_H1_SWREG479_BF_16_MASK               (0xFF0000U)
#define VPU_H1_SWREG479_BF_16_SHIFT              (16U)
/*! BF_16 - Denoise Filter Parameters Set 3, No.58. */
#define VPU_H1_SWREG479_BF_16(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG479_BF_16_SHIFT)) & VPU_H1_SWREG479_BF_16_MASK)

#define VPU_H1_SWREG479_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG479_BF_24_SHIFT              (24U)
/*! BF_24 - Denoise Filter Parameters Set 3, No.59. */
#define VPU_H1_SWREG479_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG479_BF_24_SHIFT)) & VPU_H1_SWREG479_BF_24_MASK)
/*! @} */

/*! @name SWREG480 - VPU H1 Register 480 */
/*! @{ */

#define VPU_H1_SWREG480_BF_0_MASK                (0xFFU)
#define VPU_H1_SWREG480_BF_0_SHIFT               (0U)
/*! BF_0 - Denoise Filter Parameters Set 3, No.60. */
#define VPU_H1_SWREG480_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG480_BF_0_SHIFT)) & VPU_H1_SWREG480_BF_0_MASK)

#define VPU_H1_SWREG480_BF_8_MASK                (0xFF00U)
#define VPU_H1_SWREG480_BF_8_SHIFT               (8U)
/*! BF_8 - Denoise Filter Parameters Set 3, No.61. */
#define VPU_H1_SWREG480_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG480_BF_8_SHIFT)) & VPU_H1_SWREG480_BF_8_MASK)

#define VPU_H1_SWREG480_BF_16_MASK               (0xFF0000U)
#define VPU_H1_SWREG480_BF_16_SHIFT              (16U)
/*! BF_16 - Denoise Filter Parameters Set 3, No.62. */
#define VPU_H1_SWREG480_BF_16(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG480_BF_16_SHIFT)) & VPU_H1_SWREG480_BF_16_MASK)

#define VPU_H1_SWREG480_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG480_BF_24_SHIFT              (24U)
/*! BF_24 - Denoise Filter Parameters Set 3, No.63. */
#define VPU_H1_SWREG480_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG480_BF_24_SHIFT)) & VPU_H1_SWREG480_BF_24_MASK)
/*! @} */

/*! @name SWREG481 - VPU H1 Register 481 */
/*! @{ */

#define VPU_H1_SWREG481_BF_0_MASK                (0xFFU)
#define VPU_H1_SWREG481_BF_0_SHIFT               (0U)
/*! BF_0 - Denoise Filter Parameters Set 4, No.0. */
#define VPU_H1_SWREG481_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG481_BF_0_SHIFT)) & VPU_H1_SWREG481_BF_0_MASK)

#define VPU_H1_SWREG481_BF_8_MASK                (0xFF00U)
#define VPU_H1_SWREG481_BF_8_SHIFT               (8U)
/*! BF_8 - Denoise Filter Parameters Set 4, No.1. */
#define VPU_H1_SWREG481_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG481_BF_8_SHIFT)) & VPU_H1_SWREG481_BF_8_MASK)

#define VPU_H1_SWREG481_BF_16_MASK               (0xFF0000U)
#define VPU_H1_SWREG481_BF_16_SHIFT              (16U)
/*! BF_16 - Denoise Filter Parameters Set 4, No.2. */
#define VPU_H1_SWREG481_BF_16(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG481_BF_16_SHIFT)) & VPU_H1_SWREG481_BF_16_MASK)

#define VPU_H1_SWREG481_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG481_BF_24_SHIFT              (24U)
/*! BF_24 - Denoise Filter Parameters Set 4, No.3. */
#define VPU_H1_SWREG481_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG481_BF_24_SHIFT)) & VPU_H1_SWREG481_BF_24_MASK)
/*! @} */

/*! @name SWREG482 - VPU H1 Register 482 */
/*! @{ */

#define VPU_H1_SWREG482_BF_0_MASK                (0xFFU)
#define VPU_H1_SWREG482_BF_0_SHIFT               (0U)
/*! BF_0 - Denoise Filter Parameters Set 4, No.4. */
#define VPU_H1_SWREG482_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG482_BF_0_SHIFT)) & VPU_H1_SWREG482_BF_0_MASK)

#define VPU_H1_SWREG482_BF_8_MASK                (0xFF00U)
#define VPU_H1_SWREG482_BF_8_SHIFT               (8U)
/*! BF_8 - Denoise Filter Parameters Set 4, No.5. */
#define VPU_H1_SWREG482_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG482_BF_8_SHIFT)) & VPU_H1_SWREG482_BF_8_MASK)

#define VPU_H1_SWREG482_BF_16_MASK               (0xFF0000U)
#define VPU_H1_SWREG482_BF_16_SHIFT              (16U)
/*! BF_16 - Denoise Filter Parameters Set 4, No.6. */
#define VPU_H1_SWREG482_BF_16(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG482_BF_16_SHIFT)) & VPU_H1_SWREG482_BF_16_MASK)

#define VPU_H1_SWREG482_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG482_BF_24_SHIFT              (24U)
/*! BF_24 - Denoise Filter Parameters Set 4, No.7. */
#define VPU_H1_SWREG482_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG482_BF_24_SHIFT)) & VPU_H1_SWREG482_BF_24_MASK)
/*! @} */

/*! @name SWREG483 - VPU H1 Register 483 */
/*! @{ */

#define VPU_H1_SWREG483_BF_0_MASK                (0xFFU)
#define VPU_H1_SWREG483_BF_0_SHIFT               (0U)
/*! BF_0 - Denoise Filter Parameters Set 4, No.8. */
#define VPU_H1_SWREG483_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG483_BF_0_SHIFT)) & VPU_H1_SWREG483_BF_0_MASK)

#define VPU_H1_SWREG483_BF_8_MASK                (0xFF00U)
#define VPU_H1_SWREG483_BF_8_SHIFT               (8U)
/*! BF_8 - Denoise Filter Parameters Set 4, No.9. */
#define VPU_H1_SWREG483_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG483_BF_8_SHIFT)) & VPU_H1_SWREG483_BF_8_MASK)

#define VPU_H1_SWREG483_BF_16_MASK               (0xFF0000U)
#define VPU_H1_SWREG483_BF_16_SHIFT              (16U)
/*! BF_16 - Denoise Filter Parameters Set 4, No.10. */
#define VPU_H1_SWREG483_BF_16(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG483_BF_16_SHIFT)) & VPU_H1_SWREG483_BF_16_MASK)

#define VPU_H1_SWREG483_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG483_BF_24_SHIFT              (24U)
/*! BF_24 - Denoise Filter Parameters Set 4, No.11. */
#define VPU_H1_SWREG483_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG483_BF_24_SHIFT)) & VPU_H1_SWREG483_BF_24_MASK)
/*! @} */

/*! @name SWREG484 - VPU H1 Register 484 */
/*! @{ */

#define VPU_H1_SWREG484_BF_0_MASK                (0xFFU)
#define VPU_H1_SWREG484_BF_0_SHIFT               (0U)
/*! BF_0 - Denoise Filter Parameters Set 4, No.12. */
#define VPU_H1_SWREG484_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG484_BF_0_SHIFT)) & VPU_H1_SWREG484_BF_0_MASK)

#define VPU_H1_SWREG484_BF_8_MASK                (0xFF00U)
#define VPU_H1_SWREG484_BF_8_SHIFT               (8U)
/*! BF_8 - Denoise Filter Parameters Set 4, No.13. */
#define VPU_H1_SWREG484_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG484_BF_8_SHIFT)) & VPU_H1_SWREG484_BF_8_MASK)

#define VPU_H1_SWREG484_BF_16_MASK               (0xFF0000U)
#define VPU_H1_SWREG484_BF_16_SHIFT              (16U)
/*! BF_16 - Denoise Filter Parameters Set 4, No.14. */
#define VPU_H1_SWREG484_BF_16(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG484_BF_16_SHIFT)) & VPU_H1_SWREG484_BF_16_MASK)

#define VPU_H1_SWREG484_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG484_BF_24_SHIFT              (24U)
/*! BF_24 - Denoise Filter Parameters Set 4, No.15. */
#define VPU_H1_SWREG484_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG484_BF_24_SHIFT)) & VPU_H1_SWREG484_BF_24_MASK)
/*! @} */

/*! @name SWREG485 - VPU H1 Register 485 */
/*! @{ */

#define VPU_H1_SWREG485_BF_0_MASK                (0xFFU)
#define VPU_H1_SWREG485_BF_0_SHIFT               (0U)
/*! BF_0 - Denoise Filter Parameters Set 4, No.16. */
#define VPU_H1_SWREG485_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG485_BF_0_SHIFT)) & VPU_H1_SWREG485_BF_0_MASK)

#define VPU_H1_SWREG485_BF_8_MASK                (0xFF00U)
#define VPU_H1_SWREG485_BF_8_SHIFT               (8U)
/*! BF_8 - Denoise Filter Parameters Set 4, No.17. */
#define VPU_H1_SWREG485_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG485_BF_8_SHIFT)) & VPU_H1_SWREG485_BF_8_MASK)

#define VPU_H1_SWREG485_BF_16_MASK               (0xFF0000U)
#define VPU_H1_SWREG485_BF_16_SHIFT              (16U)
/*! BF_16 - Denoise Filter Parameters Set 4, No.18. */
#define VPU_H1_SWREG485_BF_16(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG485_BF_16_SHIFT)) & VPU_H1_SWREG485_BF_16_MASK)

#define VPU_H1_SWREG485_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG485_BF_24_SHIFT              (24U)
/*! BF_24 - Denoise Filter Parameters Set 4, No.19. */
#define VPU_H1_SWREG485_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG485_BF_24_SHIFT)) & VPU_H1_SWREG485_BF_24_MASK)
/*! @} */

/*! @name SWREG486 - VPU H1 Register 486 */
/*! @{ */

#define VPU_H1_SWREG486_BF_0_MASK                (0xFFU)
#define VPU_H1_SWREG486_BF_0_SHIFT               (0U)
/*! BF_0 - Denoise Filter Parameters Set 4, No.20. */
#define VPU_H1_SWREG486_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG486_BF_0_SHIFT)) & VPU_H1_SWREG486_BF_0_MASK)

#define VPU_H1_SWREG486_BF_8_MASK                (0xFF00U)
#define VPU_H1_SWREG486_BF_8_SHIFT               (8U)
/*! BF_8 - Denoise Filter Parameters Set 4, No.21. */
#define VPU_H1_SWREG486_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG486_BF_8_SHIFT)) & VPU_H1_SWREG486_BF_8_MASK)

#define VPU_H1_SWREG486_BF_16_MASK               (0xFF0000U)
#define VPU_H1_SWREG486_BF_16_SHIFT              (16U)
/*! BF_16 - Denoise Filter Parameters Set 4, No.22. */
#define VPU_H1_SWREG486_BF_16(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG486_BF_16_SHIFT)) & VPU_H1_SWREG486_BF_16_MASK)

#define VPU_H1_SWREG486_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG486_BF_24_SHIFT              (24U)
/*! BF_24 - Denoise Filter Parameters Set 4, No.23. */
#define VPU_H1_SWREG486_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG486_BF_24_SHIFT)) & VPU_H1_SWREG486_BF_24_MASK)
/*! @} */

/*! @name SWREG487 - VPU H1 Register 487 */
/*! @{ */

#define VPU_H1_SWREG487_BF_0_MASK                (0xFFU)
#define VPU_H1_SWREG487_BF_0_SHIFT               (0U)
/*! BF_0 - Denoise Filter Parameters Set 4, No.24. */
#define VPU_H1_SWREG487_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG487_BF_0_SHIFT)) & VPU_H1_SWREG487_BF_0_MASK)

#define VPU_H1_SWREG487_BF_8_MASK                (0xFF00U)
#define VPU_H1_SWREG487_BF_8_SHIFT               (8U)
/*! BF_8 - Denoise Filter Parameters Set 4, No.25. */
#define VPU_H1_SWREG487_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG487_BF_8_SHIFT)) & VPU_H1_SWREG487_BF_8_MASK)

#define VPU_H1_SWREG487_BF_16_MASK               (0xFF0000U)
#define VPU_H1_SWREG487_BF_16_SHIFT              (16U)
/*! BF_16 - Denoise Filter Parameters Set 4, No.26. */
#define VPU_H1_SWREG487_BF_16(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG487_BF_16_SHIFT)) & VPU_H1_SWREG487_BF_16_MASK)

#define VPU_H1_SWREG487_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG487_BF_24_SHIFT              (24U)
/*! BF_24 - Denoise Filter Parameters Set 4, No.27. */
#define VPU_H1_SWREG487_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG487_BF_24_SHIFT)) & VPU_H1_SWREG487_BF_24_MASK)
/*! @} */

/*! @name SWREG488 - VPU H1 Register 488 */
/*! @{ */

#define VPU_H1_SWREG488_BF_0_MASK                (0xFFU)
#define VPU_H1_SWREG488_BF_0_SHIFT               (0U)
/*! BF_0 - Denoise Filter Parameters Set 4, No.28. */
#define VPU_H1_SWREG488_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG488_BF_0_SHIFT)) & VPU_H1_SWREG488_BF_0_MASK)

#define VPU_H1_SWREG488_BF_8_MASK                (0xFF00U)
#define VPU_H1_SWREG488_BF_8_SHIFT               (8U)
/*! BF_8 - Denoise Filter Parameters Set 4, No.29. */
#define VPU_H1_SWREG488_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG488_BF_8_SHIFT)) & VPU_H1_SWREG488_BF_8_MASK)

#define VPU_H1_SWREG488_BF_16_MASK               (0xFF0000U)
#define VPU_H1_SWREG488_BF_16_SHIFT              (16U)
/*! BF_16 - Denoise Filter Parameters Set 4, No.30. */
#define VPU_H1_SWREG488_BF_16(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG488_BF_16_SHIFT)) & VPU_H1_SWREG488_BF_16_MASK)

#define VPU_H1_SWREG488_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG488_BF_24_SHIFT              (24U)
/*! BF_24 - Denoise Filter Parameters Set 4, No.31. */
#define VPU_H1_SWREG488_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG488_BF_24_SHIFT)) & VPU_H1_SWREG488_BF_24_MASK)
/*! @} */

/*! @name SWREG489 - VPU H1 Register 489 */
/*! @{ */

#define VPU_H1_SWREG489_BF_0_MASK                (0xFFU)
#define VPU_H1_SWREG489_BF_0_SHIFT               (0U)
/*! BF_0 - Denoise Filter Parameters Set 4, No.32. */
#define VPU_H1_SWREG489_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG489_BF_0_SHIFT)) & VPU_H1_SWREG489_BF_0_MASK)

#define VPU_H1_SWREG489_BF_8_MASK                (0xFF00U)
#define VPU_H1_SWREG489_BF_8_SHIFT               (8U)
/*! BF_8 - Denoise Filter Parameters Set 4, No.33. */
#define VPU_H1_SWREG489_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG489_BF_8_SHIFT)) & VPU_H1_SWREG489_BF_8_MASK)

#define VPU_H1_SWREG489_BF_16_MASK               (0xFF0000U)
#define VPU_H1_SWREG489_BF_16_SHIFT              (16U)
/*! BF_16 - Denoise Filter Parameters Set 4, No.34. */
#define VPU_H1_SWREG489_BF_16(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG489_BF_16_SHIFT)) & VPU_H1_SWREG489_BF_16_MASK)

#define VPU_H1_SWREG489_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG489_BF_24_SHIFT              (24U)
/*! BF_24 - Denoise Filter Parameters Set 4, No.35. */
#define VPU_H1_SWREG489_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG489_BF_24_SHIFT)) & VPU_H1_SWREG489_BF_24_MASK)
/*! @} */

/*! @name SWREG490 - VPU H1 Register 490 */
/*! @{ */

#define VPU_H1_SWREG490_BF_0_MASK                (0xFFU)
#define VPU_H1_SWREG490_BF_0_SHIFT               (0U)
/*! BF_0 - Denoise Filter Parameters Set 4, No.36. */
#define VPU_H1_SWREG490_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG490_BF_0_SHIFT)) & VPU_H1_SWREG490_BF_0_MASK)

#define VPU_H1_SWREG490_BF_8_MASK                (0xFF00U)
#define VPU_H1_SWREG490_BF_8_SHIFT               (8U)
/*! BF_8 - Denoise Filter Parameters Set 4, No.37. */
#define VPU_H1_SWREG490_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG490_BF_8_SHIFT)) & VPU_H1_SWREG490_BF_8_MASK)

#define VPU_H1_SWREG490_BF_16_MASK               (0xFF0000U)
#define VPU_H1_SWREG490_BF_16_SHIFT              (16U)
/*! BF_16 - Denoise Filter Parameters Set 4, No.38. */
#define VPU_H1_SWREG490_BF_16(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG490_BF_16_SHIFT)) & VPU_H1_SWREG490_BF_16_MASK)

#define VPU_H1_SWREG490_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG490_BF_24_SHIFT              (24U)
/*! BF_24 - Denoise Filter Parameters Set 4, No.39. */
#define VPU_H1_SWREG490_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG490_BF_24_SHIFT)) & VPU_H1_SWREG490_BF_24_MASK)
/*! @} */

/*! @name SWREG491 - VPU H1 Register 491 */
/*! @{ */

#define VPU_H1_SWREG491_BF_0_MASK                (0xFFU)
#define VPU_H1_SWREG491_BF_0_SHIFT               (0U)
/*! BF_0 - Denoise Filter Parameters Set 4, No.40. */
#define VPU_H1_SWREG491_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG491_BF_0_SHIFT)) & VPU_H1_SWREG491_BF_0_MASK)

#define VPU_H1_SWREG491_BF_8_MASK                (0xFF00U)
#define VPU_H1_SWREG491_BF_8_SHIFT               (8U)
/*! BF_8 - Denoise Filter Parameters Set 4, No.41. */
#define VPU_H1_SWREG491_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG491_BF_8_SHIFT)) & VPU_H1_SWREG491_BF_8_MASK)

#define VPU_H1_SWREG491_BF_16_MASK               (0xFF0000U)
#define VPU_H1_SWREG491_BF_16_SHIFT              (16U)
/*! BF_16 - Denoise Filter Parameters Set 4, No.42. */
#define VPU_H1_SWREG491_BF_16(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG491_BF_16_SHIFT)) & VPU_H1_SWREG491_BF_16_MASK)

#define VPU_H1_SWREG491_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG491_BF_24_SHIFT              (24U)
/*! BF_24 - Denoise Filter Parameters Set 4, No.43. */
#define VPU_H1_SWREG491_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG491_BF_24_SHIFT)) & VPU_H1_SWREG491_BF_24_MASK)
/*! @} */

/*! @name SWREG492 - VPU H1 Register 492 */
/*! @{ */

#define VPU_H1_SWREG492_BF_0_MASK                (0xFFU)
#define VPU_H1_SWREG492_BF_0_SHIFT               (0U)
/*! BF_0 - Denoise Filter Parameters Set 4, No.44. */
#define VPU_H1_SWREG492_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG492_BF_0_SHIFT)) & VPU_H1_SWREG492_BF_0_MASK)

#define VPU_H1_SWREG492_BF_8_MASK                (0xFF00U)
#define VPU_H1_SWREG492_BF_8_SHIFT               (8U)
/*! BF_8 - Denoise Filter Parameters Set 4, No.45. */
#define VPU_H1_SWREG492_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG492_BF_8_SHIFT)) & VPU_H1_SWREG492_BF_8_MASK)

#define VPU_H1_SWREG492_BF_16_MASK               (0xFF0000U)
#define VPU_H1_SWREG492_BF_16_SHIFT              (16U)
/*! BF_16 - Denoise Filter Parameters Set 4, No.46. */
#define VPU_H1_SWREG492_BF_16(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG492_BF_16_SHIFT)) & VPU_H1_SWREG492_BF_16_MASK)

#define VPU_H1_SWREG492_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG492_BF_24_SHIFT              (24U)
/*! BF_24 - Denoise Filter Parameters Set 4, No.47. */
#define VPU_H1_SWREG492_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG492_BF_24_SHIFT)) & VPU_H1_SWREG492_BF_24_MASK)
/*! @} */

/*! @name SWREG493 - VPU H1 Register 493 */
/*! @{ */

#define VPU_H1_SWREG493_BF_0_MASK                (0xFFU)
#define VPU_H1_SWREG493_BF_0_SHIFT               (0U)
/*! BF_0 - Denoise Filter Parameters Set 4, No.48. */
#define VPU_H1_SWREG493_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG493_BF_0_SHIFT)) & VPU_H1_SWREG493_BF_0_MASK)

#define VPU_H1_SWREG493_BF_8_MASK                (0xFF00U)
#define VPU_H1_SWREG493_BF_8_SHIFT               (8U)
/*! BF_8 - Denoise Filter Parameters Set 4, No.49. */
#define VPU_H1_SWREG493_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG493_BF_8_SHIFT)) & VPU_H1_SWREG493_BF_8_MASK)

#define VPU_H1_SWREG493_BF_16_MASK               (0xFF0000U)
#define VPU_H1_SWREG493_BF_16_SHIFT              (16U)
/*! BF_16 - Denoise Filter Parameters Set 4, No.50. */
#define VPU_H1_SWREG493_BF_16(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG493_BF_16_SHIFT)) & VPU_H1_SWREG493_BF_16_MASK)

#define VPU_H1_SWREG493_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG493_BF_24_SHIFT              (24U)
/*! BF_24 - Denoise Filter Parameters Set 4, No.51. */
#define VPU_H1_SWREG493_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG493_BF_24_SHIFT)) & VPU_H1_SWREG493_BF_24_MASK)
/*! @} */

/*! @name SWREG494 - VPU H1 Register 494 */
/*! @{ */

#define VPU_H1_SWREG494_BF_0_MASK                (0xFFU)
#define VPU_H1_SWREG494_BF_0_SHIFT               (0U)
/*! BF_0 - Denoise Filter Parameters Set 4, No.52. */
#define VPU_H1_SWREG494_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG494_BF_0_SHIFT)) & VPU_H1_SWREG494_BF_0_MASK)

#define VPU_H1_SWREG494_BF_8_MASK                (0xFF00U)
#define VPU_H1_SWREG494_BF_8_SHIFT               (8U)
/*! BF_8 - Denoise Filter Parameters Set 4, No.53. */
#define VPU_H1_SWREG494_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG494_BF_8_SHIFT)) & VPU_H1_SWREG494_BF_8_MASK)

#define VPU_H1_SWREG494_BF_16_MASK               (0xFF0000U)
#define VPU_H1_SWREG494_BF_16_SHIFT              (16U)
/*! BF_16 - Denoise Filter Parameters Set 4, No.54. */
#define VPU_H1_SWREG494_BF_16(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG494_BF_16_SHIFT)) & VPU_H1_SWREG494_BF_16_MASK)

#define VPU_H1_SWREG494_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG494_BF_24_SHIFT              (24U)
/*! BF_24 - Denoise Filter Parameters Set 4, No.55. */
#define VPU_H1_SWREG494_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG494_BF_24_SHIFT)) & VPU_H1_SWREG494_BF_24_MASK)
/*! @} */

/*! @name SWREG495 - VPU H1 Register 495 */
/*! @{ */

#define VPU_H1_SWREG495_BF_0_MASK                (0xFFU)
#define VPU_H1_SWREG495_BF_0_SHIFT               (0U)
/*! BF_0 - Denoise Filter Parameters Set 4, No.56. */
#define VPU_H1_SWREG495_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG495_BF_0_SHIFT)) & VPU_H1_SWREG495_BF_0_MASK)

#define VPU_H1_SWREG495_BF_8_MASK                (0xFF00U)
#define VPU_H1_SWREG495_BF_8_SHIFT               (8U)
/*! BF_8 - Denoise Filter Parameters Set 4, No.57. */
#define VPU_H1_SWREG495_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG495_BF_8_SHIFT)) & VPU_H1_SWREG495_BF_8_MASK)

#define VPU_H1_SWREG495_BF_16_MASK               (0xFF0000U)
#define VPU_H1_SWREG495_BF_16_SHIFT              (16U)
/*! BF_16 - Denoise Filter Parameters Set 4, No.58. */
#define VPU_H1_SWREG495_BF_16(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG495_BF_16_SHIFT)) & VPU_H1_SWREG495_BF_16_MASK)

#define VPU_H1_SWREG495_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG495_BF_24_SHIFT              (24U)
/*! BF_24 - Denoise Filter Parameters Set 4, No.59. */
#define VPU_H1_SWREG495_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG495_BF_24_SHIFT)) & VPU_H1_SWREG495_BF_24_MASK)
/*! @} */

/*! @name SWREG496 - VPU H1 Register 496 */
/*! @{ */

#define VPU_H1_SWREG496_BF_0_MASK                (0xFFU)
#define VPU_H1_SWREG496_BF_0_SHIFT               (0U)
/*! BF_0 - Denoise Filter Parameters Set 4, No.60. */
#define VPU_H1_SWREG496_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG496_BF_0_SHIFT)) & VPU_H1_SWREG496_BF_0_MASK)

#define VPU_H1_SWREG496_BF_8_MASK                (0xFF00U)
#define VPU_H1_SWREG496_BF_8_SHIFT               (8U)
/*! BF_8 - Denoise Filter Parameters Set 4, No.61. */
#define VPU_H1_SWREG496_BF_8(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG496_BF_8_SHIFT)) & VPU_H1_SWREG496_BF_8_MASK)

#define VPU_H1_SWREG496_BF_16_MASK               (0xFF0000U)
#define VPU_H1_SWREG496_BF_16_SHIFT              (16U)
/*! BF_16 - Denoise Filter Parameters Set 4, No.62. */
#define VPU_H1_SWREG496_BF_16(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG496_BF_16_SHIFT)) & VPU_H1_SWREG496_BF_16_MASK)

#define VPU_H1_SWREG496_BF_24_MASK               (0xFF000000U)
#define VPU_H1_SWREG496_BF_24_SHIFT              (24U)
/*! BF_24 - Denoise Filter Parameters Set 4, No.63. */
#define VPU_H1_SWREG496_BF_24(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG496_BF_24_SHIFT)) & VPU_H1_SWREG496_BF_24_MASK)
/*! @} */

/*! @name SWREG497 - VPU H1 Register 497 */
/*! @{ */

#define VPU_H1_SWREG497_BF_0_MASK                (0x1FFU)
#define VPU_H1_SWREG497_BF_0_SHIFT               (0U)
/*! BF_0 - The number of MB rows that is already filled in the input buffer */
#define VPU_H1_SWREG497_BF_0(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG497_BF_0_SHIFT)) & VPU_H1_SWREG497_BF_0_MASK)

#define VPU_H1_SWREG497_BF_9_MASK                (0x3FE00U)
#define VPU_H1_SWREG497_BF_9_SHIFT               (9U)
/*! BF_9 - The number of MB rows that is already read out from the input buffer */
#define VPU_H1_SWREG497_BF_9(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG497_BF_9_SHIFT)) & VPU_H1_SWREG497_BF_9_MASK)

#define VPU_H1_SWREG497_BF_18_MASK               (0x7FC0000U)
#define VPU_H1_SWREG497_BF_18_SHIFT              (18U)
/*! BF_18 - The number of MB rows featched by encoder which will introduce HW shakehand happens. */
#define VPU_H1_SWREG497_BF_18(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG497_BF_18_SHIFT)) & VPU_H1_SWREG497_BF_18_MASK)

#define VPU_H1_SWREG497_BF_27_MASK               (0x8000000U)
#define VPU_H1_SWREG497_BF_27_SHIFT              (27U)
/*! BF_27 - Line Buffer Enable */
#define VPU_H1_SWREG497_BF_27(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG497_BF_27_SHIFT)) & VPU_H1_SWREG497_BF_27_MASK)

#define VPU_H1_SWREG497_BF_28_MASK               (0x10000000U)
#define VPU_H1_SWREG497_BF_28_SHIFT              (28U)
/*! BF_28 - Input Buffer Loop Back Enable. valid only when sw_num_mb_rows_per_sync is smaller than frame size. */
#define VPU_H1_SWREG497_BF_28(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG497_BF_28_SHIFT)) & VPU_H1_SWREG497_BF_28_MASK)

#define VPU_H1_SWREG497_BF_29_MASK               (0x20000000U)
#define VPU_H1_SWREG497_BF_29_SHIFT              (29U)
/*! BF_29 - Low Latency Hardware Interface Enable. Use hardware handshaking. */
#define VPU_H1_SWREG497_BF_29(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG497_BF_29_SHIFT)) & VPU_H1_SWREG497_BF_29_MASK)

#define VPU_H1_SWREG497_BF_30_MASK               (0x40000000U)
#define VPU_H1_SWREG497_BF_30_SHIFT              (30U)
/*! BF_30 - Enable input Buffer underflow interrupt. */
#define VPU_H1_SWREG497_BF_30(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_H1_SWREG497_BF_30_SHIFT)) & VPU_H1_SWREG497_BF_30_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group VPU_H1_Register_Masks */


/*!
 * @}
 */ /* end of group VPU_H1_Peripheral_Access_Layer */


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


#endif  /* PERI_VPU_H1_H_ */

