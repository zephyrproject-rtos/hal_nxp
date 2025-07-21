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
**         CMSIS Peripheral Access Layer for VPU_G2
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
 * @file PERI_VPU_G2.h
 * @version 5.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for VPU_G2
 *
 * CMSIS Peripheral Access Layer for VPU_G2
 */

#if !defined(PERI_VPU_G2_H_)
#define PERI_VPU_G2_H_                           /**< Symbol preventing repeated inclusion */

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
   -- VPU_G2 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VPU_G2_Peripheral_Access_Layer VPU_G2 Peripheral Access Layer
 * @{
 */

/** VPU_G2 - Register Layout Typedef */
typedef struct {
  __I  uint32_t SWREG0;                            /**< ID register (read only), offset: 0x0 */
  __IO uint32_t SWREG1;                            /**< Interrupt register decoder, offset: 0x4 */
  __IO uint32_t SWREG2;                            /**< Data configuration register decoder, offset: 0x8 */
  __IO uint32_t SWREG3;                            /**< Decoder control register 0, offset: 0xC */
  __IO uint32_t SWREG4;                            /**< Decoder control register 1, offset: 0x10 */
  __IO uint32_t SWREG5;                            /**< Decoder control register 2, offset: 0x14 */
  __IO uint32_t SWREG6;                            /**< Decoder control register 3, offset: 0x18 */
  __IO uint32_t SWREG7;                            /**< Decoder control register 4, offset: 0x1C */
  __IO uint32_t SWREG8;                            /**< Decoder control register 5, offset: 0x20 */
  __IO uint32_t SWREG9;                            /**< Decoder control register 6, offset: 0x24 */
  __IO uint32_t SWREG10;                           /**< Decoder control register 7, offset: 0x28 */
  __IO uint32_t SWREG11;                           /**< Decoder control register 8, offset: 0x2C */
  __IO uint32_t SWREG12;                           /**< Decoder control register 9, offset: 0x30 */
  __IO uint32_t SWREG13;                           /**< Decoder control register 10, offset: 0x34 */
  __IO uint32_t SWREG14;                           /**< Initial ref pic list register (0-2), offset: 0x38 */
  __IO uint32_t SWREG15;                           /**< Initial ref pic list register (3-5), offset: 0x3C */
  __IO uint32_t SWREG16;                           /**< Initial ref pic list register (6-8), offset: 0x40 */
  __IO uint32_t SWREG17;                           /**< Initial ref pic list register (9-11), offset: 0x44 */
  __IO uint32_t SWREG18;                           /**< Initial ref pic list register (12-14), offset: 0x48 */
  __IO uint32_t SWREG19;                           /**< Initial ref pic list register (15 and P 0-3), offset: 0x4C */
  __IO uint32_t SWREG20;                           /**< Decoder control register 11, offset: 0x50 */
       uint32_t SWREG21;                           /**< Not used, offset: 0x54 */
       uint32_t SWREG22;                           /**< Not used, offset: 0x58 */
  __I  uint32_t SWREG23;                           /**< Decoder configure status register, offset: 0x5C */
       uint32_t SWREG24;                           /**< Not used, offset: 0x60 */
       uint32_t SWREG25;                           /**< Not used, offset: 0x64 */
       uint32_t SWREG26;                           /**< Not used, offset: 0x68 */
       uint32_t SWREG27;                           /**< Not used, offset: 0x6C */
       uint32_t SWREG28;                           /**< Not used, offset: 0x70 */
       uint32_t SWREG29;                           /**< Not used, offset: 0x74 */
       uint32_t SWREG30;                           /**< Not used, offset: 0x78 */
  __IO uint32_t SWREG31;                           /**< VP9 segmentation values, offset: 0x7C */
  __IO uint32_t SWREG32;                           /**< VP9 segmentation values, offset: 0x80 */
  __IO uint32_t SWREG33;                           /**< VP9 reference picture scaling register 0, offset: 0x84 */
  __IO uint32_t SWREG34;                           /**< VP9 reference picture scaling register 1, offset: 0x88 */
  __IO uint32_t SWREG35;                           /**< VP9 reference picture scaling register 2, offset: 0x8C */
  __IO uint32_t SWREG36;                           /**< VP9 reference picture scaling register 3, offset: 0x90 */
  __IO uint32_t SWREG37;                           /**< VP9 reference picture scaling register 4, offset: 0x94 */
  __IO uint32_t SWREG38;                           /**< VP9 reference picture scaling register 5, offset: 0x98 */
       uint32_t SWREG39;                           /**< Not used, offset: 0x9C */
       uint32_t SWREG40;                           /**< Not used, offset: 0xA0 */
       uint32_t SWREG41;                           /**< Not used, offset: 0xA4 */
       uint32_t SWREG42;                           /**< Not used, offset: 0xA8 */
       uint32_t SWREG43;                           /**< Not used, offset: 0xAC */
       uint32_t SWREG44;                           /**< Not used, offset: 0xB0 */
  __IO uint32_t SWREG45;                           /**< Timeout control register, offset: 0xB4 */
  __IO uint32_t SWREG46;                           /**< Picture order count from current pictures for index 0-3, offset: 0xB8 */
  __IO uint32_t SWREG47;                           /**< Picture order count from current pictures for index 4-7, offset: 0xBC */
  __IO uint32_t SWREG48;                           /**< Picture order count from current pictures for index 8-11, offset: 0xC0 */
  __IO uint32_t SWREG49;                           /**< Picture order count from current pictures for index 12-15, offset: 0xC4 */
  __I  uint32_t SWREG50;                           /**< Synthesis configuration register decoder 0 (read only), offset: 0xC8 */
       uint32_t SWREG51;                           /**< Reference picture buffer control register, offset: 0xCC */
       uint32_t SWREG52;                           /**< Reference picture buffer information register 1 (read only), offset: 0xD0 */
       uint32_t SWREG53;                           /**< Reference picture buffer information register 2 (read only), offset: 0xD4 */
  __I  uint32_t SWREG54;                           /**< Synthesis configuration register decoder 1 (read only), offset: 0xD8 */
  __IO uint32_t SWREG55;                           /**< Advanced prefetch control register, offset: 0xDC */
  __I  uint32_t SWREG56;                           /**< Synthesis configuration register decoder 2 (read only), offset: 0xE0 */
       uint32_t SWREG57;                           /**< Decoder fuse register (read only), offset: 0xE4 */
  __IO uint32_t SWREG58;                           /**< Device configuration register decoder 2 + Multi core control register, offset: 0xE8 */
  __IO uint32_t SWREG59;                           /**< Device configuration register AXI ID, offset: 0xEC */
  __I  uint32_t SWREG60;                           /**< Synthesis configuration register decoder 3 for PP (read only), offset: 0xF0 */
       uint32_t SWREG61;                           /**< Not used, offset: 0xF4 */
  __IO uint32_t SWREG62;                           /**< HW proceed register (CU location), offset: 0xF8 */
  __I  uint32_t SWREG63;                           /**< HW performance register (cycles running), offset: 0xFC */
  __IO uint32_t SWREG64;                           /**< Base address MSB (bits 63:32) for decoded luminance picture, offset: 0x100 */
  __IO uint32_t SWREG65;                           /**< Base address LSB (bits 31:0) for decoded luminance picture, offset: 0x104 */
  __IO uint32_t SWREG66;                           /**< Base address MSB (bits 63:32) for reference luminance picture index 0, offset: 0x108 */
  __IO uint32_t SWREG67;                           /**< Base address LSB (bits 31:0) for reference luminance picture index 0, offset: 0x10C */
  __IO uint32_t SWREG68;                           /**< Base address MSB (bits 63:32) for reference luminance picture index 1, offset: 0x110 */
  __IO uint32_t SWREG69;                           /**< Base address LSB (bits 31:0) for reference luminance picture index 1, offset: 0x114 */
  __IO uint32_t SWREG70;                           /**< Base address MSB (bits 63:32) for reference luminance picture index 2, offset: 0x118 */
  __IO uint32_t SWREG71;                           /**< Base address LSB (bits 31:0) for reference luminance picture index 2, offset: 0x11C */
  __IO uint32_t SWREG72;                           /**< Base address MSB (bits 63:32) for reference luminance picture index 3, offset: 0x120 */
  __IO uint32_t SWREG73;                           /**< Base address LSB (bits 31:0) for reference luminance picture index 3, offset: 0x124 */
  __IO uint32_t SWREG74;                           /**< Base address MSB (bits 63:32) for reference luminance picture index 4, offset: 0x128 */
  __IO uint32_t SWREG75;                           /**< Base address LSB (bits 31:0) for reference luminance picture index 4, offset: 0x12C */
  __IO uint32_t SWREG76;                           /**< Base address MSB (bits 63:32) for reference luminance picture index 5, offset: 0x130 */
  __IO uint32_t SWREG77;                           /**< Base address LSB (bits 31:0) for reference luminance picture index 5, offset: 0x134 */
  __IO uint32_t SWREG78;                           /**< Base address MSB (bits 63:32) for reference luminance picture index 6 /VP9 segment write base MSB, offset: 0x138 */
  __IO uint32_t SWREG79;                           /**< Base address LSB (bits 31:0) for reference luminance picture index 6 /VP9 segment write base LSB, offset: 0x13C */
  __IO uint32_t SWREG80;                           /**< Base address MSB (bits 63:32) for reference luminance picture index 7 /VP9 segment read base MSB, offset: 0x140 */
  __IO uint32_t SWREG81;                           /**< Base address LSB (bits 31:0) for reference luminance picture index 7 /VP9 segment read base LSB, offset: 0x144 */
  __IO uint32_t SWREG82;                           /**< Base address MSB (bits 63:32) for reference luminance picture index 8, offset: 0x148 */
  __IO uint32_t SWREG83;                           /**< Base address LSB (bits 31:0) for reference luminance picture index 8, offset: 0x14C */
  __IO uint32_t SWREG84;                           /**< Base address MSB (bits 63:32) for reference luminance picture index 9, offset: 0x150 */
  __IO uint32_t SWREG85;                           /**< Base address LSB (bits 31:0) for reference luminance picture index 9, offset: 0x154 */
  __IO uint32_t SWREG86;                           /**< Base address MSB (bits 63:32) for reference luminance picture index 10, offset: 0x158 */
  __IO uint32_t SWREG87;                           /**< Base address LSB (bits 31:0) for reference luminance picture index 10, offset: 0x15C */
  __IO uint32_t SWREG88;                           /**< Base address MSB (bits 63:32) for reference luminance picture index 11, offset: 0x160 */
  __IO uint32_t SWREG89;                           /**< Base address LSB (bits 31:0) for reference luminance picture index 11, offset: 0x164 */
  __IO uint32_t SWREG90;                           /**< Base address MSB (bits 63:32) for reference luminance picture index 12, offset: 0x168 */
  __IO uint32_t SWREG91;                           /**< Base address LSB (bits 31:0) for reference luminance picture index 12, offset: 0x16C */
  __IO uint32_t SWREG92;                           /**< Base address MSB (bits 63:32) for reference luminance picture index 13, offset: 0x170 */
  __IO uint32_t SWREG93;                           /**< Base address LSB (bits 31:0) for reference luminance picture index 13, offset: 0x174 */
  __IO uint32_t SWREG94;                           /**< Base address MSB (bits 63:32) for reference luminance picture index 14, offset: 0x178 */
  __IO uint32_t SWREG95;                           /**< Base address LSB (bits 31:0) for reference luminance picture index 14, offset: 0x17C */
  __IO uint32_t SWREG96;                           /**< Base address MSB (bits 63:32) for reference luminance picture index 15, offset: 0x180 */
  __IO uint32_t SWREG97;                           /**< Base address LSB (bits 31:0) for reference luminance picture index 15, offset: 0x184 */
  __IO uint32_t SWREG98;                           /**< Base address MSB (bits 63:32) for decoded chrominance picture, offset: 0x188 */
  __IO uint32_t SWREG99;                           /**< Base address LSB (bits 31:0) for decoded chrominance picture, offset: 0x18C */
  __IO uint32_t SWREG100;                          /**< Base address MSB (bits 63:32) for reference chrominance picture index 0, offset: 0x190 */
  __IO uint32_t SWREG101;                          /**< Base address LSB (bits 31:0) for reference chrominance picture index 0, offset: 0x194 */
  __IO uint32_t SWREG102;                          /**< Base address MSB (bits 63:32) for reference chrominance picture index 1, offset: 0x198 */
  __IO uint32_t SWREG103;                          /**< Base address LSB (bits 31:0) for reference chrominance picture index 1, offset: 0x19C */
  __IO uint32_t SWREG104;                          /**< Base address MSB (bits 63:32) for reference chrominance picture index 2, offset: 0x1A0 */
  __IO uint32_t SWREG105;                          /**< Base address LSB (bits 31:0) for reference chrominance picture index 2, offset: 0x1A4 */
  __IO uint32_t SWREG106;                          /**< Base address MSB (bits 63:32) for reference chrominance picture index 3, offset: 0x1A8 */
  __IO uint32_t SWREG107;                          /**< Base address LSB (bits 31:0) for reference chrominance picture index 3, offset: 0x1AC */
  __IO uint32_t SWREG108;                          /**< Base address MSB (bits 63:32) for reference chrominance picture index 4, offset: 0x1B0 */
  __IO uint32_t SWREG109;                          /**< Base address LSB (bits 31:0) for reference chrominance picture index 4, offset: 0x1B4 */
  __IO uint32_t SWREG110;                          /**< Base address MSB (bits 63:32) for reference chrominance picture index 5, offset: 0x1B8 */
  __IO uint32_t SWREG111;                          /**< Base address LSB (bits 31:0) for reference chrominance picture index 5, offset: 0x1BC */
  __IO uint32_t SWREG112;                          /**< Base address MSB (bits 63:32) for reference chrominance picture index 6, offset: 0x1C0 */
  __IO uint32_t SWREG113;                          /**< Base address LSB (bits 31:0) for reference chrominance picture index 6, offset: 0x1C4 */
  __IO uint32_t SWREG114;                          /**< Base address MSB (bits 63:32) for reference chrominance picture index 7, offset: 0x1C8 */
  __IO uint32_t SWREG115;                          /**< Base address LSB (bits 31:0) for reference chrominance picture index 7, offset: 0x1CC */
  __IO uint32_t SWREG116;                          /**< Base address MSB (bits 63:32) for reference chrominance picture index 8, offset: 0x1D0 */
  __IO uint32_t SWREG117;                          /**< Base address LSB (bits 31:0) for reference chrominance picture index 8, offset: 0x1D4 */
  __IO uint32_t SWREG118;                          /**< Base address MSB (bits 63:32) for reference chrominance picture index 9, offset: 0x1D8 */
  __IO uint32_t SWREG119;                          /**< Base address LSB (bits 31:0) for reference chrominance picture index 9, offset: 0x1DC */
  __IO uint32_t SWREG120;                          /**< Base address MSB (bits 63:32) for reference chrominance picture index 10, offset: 0x1E0 */
  __IO uint32_t SWREG121;                          /**< Base address LSB (bits 31:0) for reference chrominance picture index 10, offset: 0x1E4 */
  __IO uint32_t SWREG122;                          /**< Base address MSB (bits 63:32) for reference chrominance picture index 11, offset: 0x1E8 */
  __IO uint32_t SWREG123;                          /**< Base address LSB (bits 31:0) for reference chrominance picture index 11, offset: 0x1EC */
  __IO uint32_t SWREG124;                          /**< Base address MSB (bits 63:32) for reference chrominance picture index 12, offset: 0x1F0 */
  __IO uint32_t SWREG125;                          /**< Base address LSB (bits 31:0) for reference chrominance picture index 12, offset: 0x1F4 */
  __IO uint32_t SWREG126;                          /**< Base address MSB (bits 63:32) for reference chrominance picture index 13, offset: 0x1F8 */
  __IO uint32_t SWREG127;                          /**< Base address LSB (bits 31:0) for reference chrominance picture index 13, offset: 0x1FC */
  __IO uint32_t SWREG128;                          /**< Base address MSB (bits 63:32) for reference chrominance picture index 14, offset: 0x200 */
  __IO uint32_t SWREG129;                          /**< Base address LSB (bits 31:0) for reference chrominance picture index 14, offset: 0x204 */
  __IO uint32_t SWREG130;                          /**< Base address MSB (bits 63:32) for reference chrominance picture index 15, offset: 0x208 */
  __IO uint32_t SWREG131;                          /**< Base address LSB (bits 31:0) for reference chrominance picture index 15, offset: 0x20C */
  __IO uint32_t SWREG132;                          /**< Base address MSB (bits 63:32) for decoded direct mode MVS, offset: 0x210 */
  __IO uint32_t SWREG133;                          /**< Base address LSB (bits 31:0) for decoded direct mode MVS, offset: 0x214 */
  __IO uint32_t SWREG134;                          /**< Base address MSB (bits 63:32) for reference direct mode MVS index 0, offset: 0x218 */
  __IO uint32_t SWREG135;                          /**< Base address LSB (bits 31:0) for reference direct mode MVS index 0, offset: 0x21C */
  __IO uint32_t SWREG136;                          /**< Base address MSB (bits 63:32) for reference direct mode MVS index 1, offset: 0x220 */
  __IO uint32_t SWREG137;                          /**< Base address LSB (bits 31:0) for reference direct mode MVS index 1, offset: 0x224 */
  __IO uint32_t SWREG138;                          /**< Base address MSB (bits 63:32) for reference direct mode MVS index 2, offset: 0x228 */
  __IO uint32_t SWREG139;                          /**< Base address LSB (bits 31:0) for reference direct mode MVS index 2, offset: 0x22C */
  __IO uint32_t SWREG140;                          /**< Base address MSB (bits 63:32) for reference direct mode MVS index 3, offset: 0x230 */
  __IO uint32_t SWREG141;                          /**< Base address LSB (bits 31:0) for reference direct mode MVS index 3, offset: 0x234 */
  __IO uint32_t SWREG142;                          /**< Base address MSB (bits 63:32) for reference direct mode MVS index 4, offset: 0x238 */
  __IO uint32_t SWREG143;                          /**< Base address LSB (bits 31:0) for reference direct mode MVS index 4, offset: 0x23C */
  __IO uint32_t SWREG144;                          /**< Base address MSB (bits 63:32) for reference direct mode MVS index 5, offset: 0x240 */
  __IO uint32_t SWREG145;                          /**< Base address LSB (bits 31:0) for reference direct mode MVS index 5, offset: 0x244 */
  __IO uint32_t SWREG146;                          /**< Base address MSB (bits 63:32) for reference direct mode MVS index 6, offset: 0x248 */
  __IO uint32_t SWREG147;                          /**< Base address LSB (bits 31:0) for reference direct mode MVS index 6, offset: 0x24C */
  __IO uint32_t SWREG148;                          /**< Base address MSB (bits 63:32) for reference direct mode MVS index 7, offset: 0x250 */
  __IO uint32_t SWREG149;                          /**< Base address LSB (bits 31:0) for reference direct mode MVS index 7, offset: 0x254 */
  __IO uint32_t SWREG150;                          /**< Base address MSB (bits 63:32) for reference direct mode MVS index 8, offset: 0x258 */
  __IO uint32_t SWREG151;                          /**< Base address LSB (bits 31:0) for reference direct mode MVS index 8, offset: 0x25C */
  __IO uint32_t SWREG152;                          /**< Base address MSB (bits 63:32) for reference direct mode mode MVS index 9, offset: 0x260 */
  __IO uint32_t SWREG153;                          /**< Base address LSB (bits 31:0) for reference direct mode mode MVS index 9, offset: 0x264 */
  __IO uint32_t SWREG154;                          /**< Base address MSB (bits 63:32) for reference direct mode MVS index 10, offset: 0x268 */
  __IO uint32_t SWREG155;                          /**< Base address LSB (bits 31:0) for reference direct mode MVS index 10, offset: 0x26C */
  __IO uint32_t SWREG156;                          /**< Base address MSB (bits 63:32) for reference direct mode MVS index 11, offset: 0x270 */
  __IO uint32_t SWREG157;                          /**< Base address LSB (bits 31:0) for reference direct mode MVS index 11, offset: 0x274 */
  __IO uint32_t SWREG158;                          /**< Base address MSB (bits 63:32) for reference direct mode MVS index 12, offset: 0x278 */
  __IO uint32_t SWREG159;                          /**< Base address LSB (bits 31:0) for reference direct mode MVS index 12, offset: 0x27C */
  __IO uint32_t SWREG160;                          /**< Base address MSB (bits 63:32) for reference direct mode MVS index 13, offset: 0x280 */
  __IO uint32_t SWREG161;                          /**< Base address LSB (bits 31:0) for reference direct mode MVS index 13, offset: 0x284 */
  __IO uint32_t SWREG162;                          /**< Base address MSB (bits 63:32) for reference direct mode MVS index 14, offset: 0x288 */
  __IO uint32_t SWREG163;                          /**< Base address LSB (bits 31:0) for reference direct mode MVS index 14, offset: 0x28C */
  __IO uint32_t SWREG164;                          /**< Base address MSB (bits 63:32) for reference direct mode MVS index 15, offset: 0x290 */
  __IO uint32_t SWREG165;                          /**< Base address LSB (bits 31:0) for reference direct mode MVS index 15, offset: 0x294 */
  __IO uint32_t SWREG166;                          /**< Base address MSB (bits 63:32) for tile sizes, offset: 0x298 */
  __IO uint32_t SWREG167;                          /**< Base address LSB (bits 31:0) for tile sizes, offset: 0x29C */
  __IO uint32_t SWREG168;                          /**< Base address MSB (bits 63:32) for / stream start address/decoded end addr register, offset: 0x2A0 */
  __IO uint32_t SWREG169;                          /**< Base address LSB (bits 31:0) for / stream start address/decoded end addr register, offset: 0x2A4 */
  __IO uint32_t SWREG170;                          /**< Base address MSB (bits 63:32) for scaling lists / VP9 CTX counter values, offset: 0x2A8 */
  __IO uint32_t SWREG171;                          /**< Base address LSB (bits 31:0) for scaling lists / VP9 CTX counter values, offset: 0x2AC */
  __IO uint32_t SWREG172;                          /**< Base address MSB (bits 63:32) for stream propability tables, offset: 0x2B0 */
  __IO uint32_t SWREG173;                          /**< Base address LSB (bits 31:0) for stream propability tables, offset: 0x2B4 */
  __IO uint32_t SWREG174;                          /**< Base address MSB (bits 63:32) for decoder output raster scan Y picture, offset: 0x2B8 */
  __IO uint32_t SWREG175;                          /**< Base address LSB (bits 31:0) for decoder output raster scan Y picture, offset: 0x2BC */
  __IO uint32_t SWREG176;                          /**< Base address MSB (bits 63:32) for decoder output raster scan C picture, offset: 0x2C0 */
  __IO uint32_t SWREG177;                          /**< Base address LSB (bits 31:0) for decoder output raster scan C picture, offset: 0x2C4 */
  __IO uint32_t SWREG178;                          /**< Base address MSB (bits 63:32) for tile border coeffients of filter, offset: 0x2C8 */
  __IO uint32_t SWREG179;                          /**< Base address LSB (bits 31:0) for tile border coeffients of filter, offset: 0x2CC */
  __IO uint32_t SWREG180;                          /**< Base address MSB (bits 63:32) for tile border coeffients of sao, offset: 0x2D0 */
  __IO uint32_t SWREG181;                          /**< Base address LSB (bits 31:0) for tile border coeffients of sao, offset: 0x2D4 */
  __IO uint32_t SWREG182;                          /**< Base address MSB (bits 63:32) for tile border bsd control data, offset: 0x2D8 */
  __IO uint32_t SWREG183;                          /**< Base address LSB (bits 31:0) for tile border bsd control data, offset: 0x2DC */
  __IO uint32_t SWREG184;                          /**< Raster scan down scale control register MSM, offset: 0x2E0 */
  __IO uint32_t SWREG185;                          /**< Base address MSB (bits 63:32) for decoder output raster scan down scale Y picture, offset: 0x2E4 */
  __IO uint32_t SWREG186;                          /**< Base address LSB (bits 31:0) for decoder output raster scan down scale Y picture, offset: 0x2E8 */
  __IO uint32_t SWREG187;                          /**< Base address MSB (bits 63:32) for decoder output raster scan down scale C picture, offset: 0x2EC */
  __IO uint32_t SWREG188;                          /**< Base address LSB (bits 31:0) for decoder output raster scan down scale C picture, offset: 0x2F0 */
  __IO uint32_t SWREG189;                          /**< Base address MSB (bits 63:32) for decoder output compress luminance table, offset: 0x2F4 */
  __IO uint32_t SWREG190;                          /**< Base address LSB (bits 31:0) for decoder output compress luminance table, offset: 0x2F8 */
  __IO uint32_t SWREG191;                          /**< Base address MSB (bits 63:32) for reference compress luminance table index 0, offset: 0x2FC */
  __IO uint32_t SWREG192;                          /**< Base address LSB (bits 31:0) for reference compress luminance table index 0, offset: 0x300 */
  __IO uint32_t SWREG193;                          /**< Base address MSB (bits 63:32) for reference compress luminance table index 1, offset: 0x304 */
  __IO uint32_t SWREG194;                          /**< Base address LSB (bits 31:0) for reference compress luminance table index 1, offset: 0x308 */
  __IO uint32_t SWREG195;                          /**< Base address MSB (bits 63:32) for reference compress luminance table index 2, offset: 0x30C */
  __IO uint32_t SWREG196;                          /**< Base address LSB (bits 31:0) for reference compress luminance table index 2, offset: 0x310 */
  __IO uint32_t SWREG197;                          /**< Base address MSB (bits 63:32) for reference compress luminance table index 3, offset: 0x314 */
  __IO uint32_t SWREG198;                          /**< Base address LSB (bits 31:0) for reference compress luminance table index 3, offset: 0x318 */
  __IO uint32_t SWREG199;                          /**< Base address MSB (bits 63:32) for reference compress luminance table index 4, offset: 0x31C */
  __IO uint32_t SWREG200;                          /**< Base address LSB (bits 31:0) for reference compress luminance table index 4, offset: 0x320 */
  __IO uint32_t SWREG201;                          /**< Base address MSB (bits 63:32) for reference compress luminance table index 5, offset: 0x324 */
  __IO uint32_t SWREG202;                          /**< Base address LSB (bits 31:0) for reference compress luminance table index 5, offset: 0x328 */
  __IO uint32_t SWREG203;                          /**< Base address MSB (bits 63:32) for reference compress luminance table index 6, offset: 0x32C */
  __IO uint32_t SWREG204;                          /**< Base address LSB (bits 31:0) for reference compress luminance table index 6, offset: 0x330 */
  __IO uint32_t SWREG205;                          /**< Base address MSB (bits 63:32) for reference compress luminance table index 7, offset: 0x334 */
  __IO uint32_t SWREG206;                          /**< Base address LSB (bits 31:0) for reference compress luminance table index 7, offset: 0x338 */
  __IO uint32_t SWREG207;                          /**< Base address MSB (bits 63:32) for reference compress luminance table index 8, offset: 0x33C */
  __IO uint32_t SWREG208;                          /**< Base address LSB (bits 31:0) for reference compress luminance table index 8, offset: 0x340 */
  __IO uint32_t SWREG209;                          /**< Base address MSB (bits 63:32) for reference compress luminance table index 9, offset: 0x344 */
  __IO uint32_t SWREG210;                          /**< Base address LSB (bits 31:0) for reference compress luminance table index 9, offset: 0x348 */
  __IO uint32_t SWREG211;                          /**< Base address MSB (bits 63:32) for reference compress luminance table index 10, offset: 0x34C */
  __IO uint32_t SWREG212;                          /**< Base address LSB (bits 31:0) for reference compress luminance table index 10, offset: 0x350 */
  __IO uint32_t SWREG213;                          /**< Base address MSB (bits 63:32) for reference compress luminance table index 11, offset: 0x354 */
  __IO uint32_t SWREG214;                          /**< Base address LSB (bits 31:0) for reference compress luminance table index 11, offset: 0x358 */
  __IO uint32_t SWREG215;                          /**< Base address MSB (bits 63:32) for reference compress luminance table index 12, offset: 0x35C */
  __IO uint32_t SWREG216;                          /**< Base address LSB (bits 31:0) for reference compress luminance table index 12, offset: 0x360 */
  __IO uint32_t SWREG217;                          /**< Base address MSB (bits 63:32) for reference compress luminance table index 13, offset: 0x364 */
  __IO uint32_t SWREG218;                          /**< Base address LSB (bits 31:0) for reference compress luminance table index 13, offset: 0x368 */
  __IO uint32_t SWREG219;                          /**< Base address MSB (bits 63:32) for reference compress luminance table index 14, offset: 0x36C */
  __IO uint32_t SWREG220;                          /**< Base address LSB (bits 31:0) for reference compress luminance table index 14, offset: 0x370 */
  __IO uint32_t SWREG221;                          /**< Base address MSB (bits 63:32) for reference compress luminance table index 15, offset: 0x374 */
  __IO uint32_t SWREG222;                          /**< Base address LSB (bits 31:0) for reference compress luminance table index 15, offset: 0x378 */
  __IO uint32_t SWREG223;                          /**< Base address MSB (bits 63:32) for decoder output compress chrominance table, offset: 0x37C */
  __IO uint32_t SWREG224;                          /**< Base address LSB (bits 31:0) for decoder output compress chrominance table, offset: 0x380 */
  __IO uint32_t SWREG225;                          /**< Base address MSB (bits 63:32) for reference compress chrominance table index 0, offset: 0x384 */
  __IO uint32_t SWREG226;                          /**< Base address LSB (bits 31:0) for reference compress chrominance table index 0, offset: 0x388 */
  __IO uint32_t SWREG227;                          /**< Base address MSB (bits 63:32) for reference compress chrominance table index 1, offset: 0x38C */
  __IO uint32_t SWREG228;                          /**< Base address LSB (bits 31:0) for reference compress chrominance table index 1, offset: 0x390 */
  __IO uint32_t SWREG229;                          /**< Base address MSB (bits 63:32) for reference compress chrominance table index 2, offset: 0x394 */
  __IO uint32_t SWREG230;                          /**< Base address LSB (bits 31:0) for reference compress chrominance table index 2, offset: 0x398 */
  __IO uint32_t SWREG231;                          /**< Base address MSB (bits 63:32) for reference compress chrominance table index 3, offset: 0x39C */
  __IO uint32_t SWREG232;                          /**< Base address LSB (bits 31:0) for reference compress chrominance table index 3, offset: 0x3A0 */
  __IO uint32_t SWREG233;                          /**< Base address MSB (bits 63:32) for reference compress chrominance table index 4, offset: 0x3A4 */
  __IO uint32_t SWREG234;                          /**< Base address LSB (bits 31:0) for reference compress chrominance table index 4, offset: 0x3A8 */
  __IO uint32_t SWREG235;                          /**< Base address MSB (bits 63:32) for reference compress chrominance table index 5, offset: 0x3AC */
  __IO uint32_t SWREG236;                          /**< Base address LSB (bits 31:0) for reference compress chrominance table index 5, offset: 0x3B0 */
  __IO uint32_t SWREG237;                          /**< Base address MSB (bits 63:32) for reference compress chrominance table index 6, offset: 0x3B4 */
  __IO uint32_t SWREG238;                          /**< Base address LSB (bits 31:0) for reference compress chrominance table index 6, offset: 0x3B8 */
  __IO uint32_t SWREG239;                          /**< Base address MSB (bits 63:32) for reference compress chrominance table index 7, offset: 0x3BC */
  __IO uint32_t SWREG240;                          /**< Base address LSB (bits 31:0) for reference compress chrominance table index 7, offset: 0x3C0 */
  __IO uint32_t SWREG241;                          /**< Base address MSB (bits 63:32) for reference compress chrominance table index 8, offset: 0x3C4 */
  __IO uint32_t SWREG242;                          /**< Base address LSB (bits 31:0) for reference compress chrominance table index 8, offset: 0x3C8 */
  __IO uint32_t SWREG243;                          /**< Base address MSB (bits 63:32) for reference compress chrominance table index 9, offset: 0x3CC */
  __IO uint32_t SWREG244;                          /**< Base address LSB (bits 31:0) for reference compress chrominance table index 9, offset: 0x3D0 */
  __IO uint32_t SWREG245;                          /**< Base address MSB (bits 63:32) for reference compress chrominance table index 10, offset: 0x3D4 */
  __IO uint32_t SWREG246;                          /**< Base address LSB (bits 31:0) for reference compress chrominance table index 10, offset: 0x3D8 */
  __IO uint32_t SWREG247;                          /**< Base address MSB (bits 63:32) for reference compress chrominance table index 11, offset: 0x3DC */
  __IO uint32_t SWREG248;                          /**< Base address LSB (bits 31:0) for reference compress chrominance table index 11, offset: 0x3E0 */
  __IO uint32_t SWREG249;                          /**< Base address MSB (bits 63:32) for reference compress chrominance table index 12, offset: 0x3E4 */
  __IO uint32_t SWREG250;                          /**< Base address LSB (bits 31:0) for reference compress chrominance table index 12, offset: 0x3E8 */
  __IO uint32_t SWREG251;                          /**< Base address MSB (bits 63:32) for reference compress chrominance table index 13, offset: 0x3EC */
  __IO uint32_t SWREG252;                          /**< Base address LSB (bits 31:0) for reference compress chrominance table index 13, offset: 0x3F0 */
  __IO uint32_t SWREG253;                          /**< Base address MSB (bits 63:32) for reference compress chrominance table index 14, offset: 0x3F4 */
  __IO uint32_t SWREG254;                          /**< Base address LSB (bits 31:0) for reference compress chrominance table index 14, offset: 0x3F8 */
  __IO uint32_t SWREG255;                          /**< Base address MSB (bits 63:32) for reference compress chrominance table index 15, offset: 0x3FC */
  __IO uint32_t SWREG256;                          /**< Base address LSB (bits 31:0) for reference compress chrominance table index 15, offset: 0x400 */
       uint32_t SWREG257;                          /**< Not used, offset: 0x404 */
  __IO uint32_t SWREG258;                          /**< input stream buffer length, offset: 0x408 */
  __IO uint32_t SWREG259;                          /**< input stream buffer start offset, offset: 0x40C */
} VPU_G2_Type;

/* ----------------------------------------------------------------------------
   -- VPU_G2 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VPU_G2_Register_Masks VPU_G2 Register Masks
 * @{
 */

/*! @name SWREG0 - ID register (read only) */
/*! @{ */

#define VPU_G2_SWREG0_SW_BUILD_VERSION_MASK      (0x7U)
#define VPU_G2_SWREG0_SW_BUILD_VERSION_SHIFT     (0U)
/*! SW_BUILD_VERSION - Build version (core number) */
#define VPU_G2_SWREG0_SW_BUILD_VERSION(x)        (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG0_SW_BUILD_VERSION_SHIFT)) & VPU_G2_SWREG0_SW_BUILD_VERSION_MASK)

#define VPU_G2_SWREG0_SW_PRODUCT_ID_EN_MASK      (0x8U)
#define VPU_G2_SWREG0_SW_PRODUCT_ID_EN_SHIFT     (3U)
/*! SW_PRODUCT_ID_EN - ASCII type product ID enable */
#define VPU_G2_SWREG0_SW_PRODUCT_ID_EN(x)        (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG0_SW_PRODUCT_ID_EN_SHIFT)) & VPU_G2_SWREG0_SW_PRODUCT_ID_EN_MASK)

#define VPU_G2_SWREG0_SW_MINOR_VERSION_MASK      (0xFF0U)
#define VPU_G2_SWREG0_SW_MINOR_VERSION_SHIFT     (4U)
/*! SW_MINOR_VERSION - Minor version */
#define VPU_G2_SWREG0_SW_MINOR_VERSION(x)        (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG0_SW_MINOR_VERSION_SHIFT)) & VPU_G2_SWREG0_SW_MINOR_VERSION_MASK)

#define VPU_G2_SWREG0_SW_MAJOR_VERSION_MASK      (0xF000U)
#define VPU_G2_SWREG0_SW_MAJOR_VERSION_SHIFT     (12U)
/*! SW_MAJOR_VERSION - Major version */
#define VPU_G2_SWREG0_SW_MAJOR_VERSION(x)        (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG0_SW_MAJOR_VERSION_SHIFT)) & VPU_G2_SWREG0_SW_MAJOR_VERSION_MASK)

#define VPU_G2_SWREG0_SW_PRODUCT_NUMBER_MASK     (0xFFFF0000U)
#define VPU_G2_SWREG0_SW_PRODUCT_NUMBER_SHIFT    (16U)
/*! SW_PRODUCT_NUMBER - Product number (g2) */
#define VPU_G2_SWREG0_SW_PRODUCT_NUMBER(x)       (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG0_SW_PRODUCT_NUMBER_SHIFT)) & VPU_G2_SWREG0_SW_PRODUCT_NUMBER_MASK)
/*! @} */

/*! @name SWREG1 - Interrupt register decoder */
/*! @{ */

#define VPU_G2_SWREG1_SW_DEC_E_MASK              (0x1U)
#define VPU_G2_SWREG1_SW_DEC_E_SHIFT             (0U)
/*! SW_DEC_E - Decoder enable. Setting this bit high will start the decoding operation. HW will
 *    reset this when picture is processed or ASO or stream error is detected or bus error or timeout
 *    interrupt is given.
 */
#define VPU_G2_SWREG1_SW_DEC_E(x)                (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG1_SW_DEC_E_SHIFT)) & VPU_G2_SWREG1_SW_DEC_E_MASK)

#define VPU_G2_SWREG1_SW_DEC_IRQ_DIS_MASK        (0x10U)
#define VPU_G2_SWREG1_SW_DEC_IRQ_DIS_SHIFT       (4U)
/*! SW_DEC_IRQ_DIS - Decoder IRQ disable. When high there are no interrupts concerning decoder from
 *    HW. Polling must be used to see the interrupt statuses.
 */
#define VPU_G2_SWREG1_SW_DEC_IRQ_DIS(x)          (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG1_SW_DEC_IRQ_DIS_SHIFT)) & VPU_G2_SWREG1_SW_DEC_IRQ_DIS_MASK)

#define VPU_G2_SWREG1_SW_DEC_ABORT_E_MASK        (0x20U)
#define VPU_G2_SWREG1_SW_DEC_ABORT_E_SHIFT       (5U)
/*! SW_DEC_ABORT_E - Abort decoding enable. Setting this bit high will cause HW to abort decoding
 *    and safely to reset itself down. After abort is complete the corresponding interrupt status is
 *    set and this bit is set low as well as the decoder enable.
 */
#define VPU_G2_SWREG1_SW_DEC_ABORT_E(x)          (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG1_SW_DEC_ABORT_E_SHIFT)) & VPU_G2_SWREG1_SW_DEC_ABORT_E_MASK)

#define VPU_G2_SWREG1_SW_DEC_IRQ_MASK            (0x100U)
#define VPU_G2_SWREG1_SW_DEC_IRQ_SHIFT           (8U)
/*! SW_DEC_IRQ - Decoder IRQ. When high decoder requests an interrupt. SW will reset this after interrupt is handled. */
#define VPU_G2_SWREG1_SW_DEC_IRQ(x)              (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG1_SW_DEC_IRQ_SHIFT)) & VPU_G2_SWREG1_SW_DEC_IRQ_MASK)

#define VPU_G2_SWREG1_SW_DEC_ABORT_INT_MASK      (0x800U)
#define VPU_G2_SWREG1_SW_DEC_ABORT_INT_SHIFT     (11U)
/*! SW_DEC_ABORT_INT - Interrupt status bit decoding aborted. When this bit is high decoder has
 *    aborted the current picture decoding as SW requested (sw_dec_abort_e). Decoder self reset and
 *    sw_dec_abort_e written low
 */
#define VPU_G2_SWREG1_SW_DEC_ABORT_INT(x)        (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG1_SW_DEC_ABORT_INT_SHIFT)) & VPU_G2_SWREG1_SW_DEC_ABORT_INT_MASK)

#define VPU_G2_SWREG1_SW_DEC_RDY_INT_MASK        (0x1000U)
#define VPU_G2_SWREG1_SW_DEC_RDY_INT_SHIFT       (12U)
/*! SW_DEC_RDY_INT - Interrupt status bit decoder. When this bit is high decoder has decoded a picture. HW will self reset. */
#define VPU_G2_SWREG1_SW_DEC_RDY_INT(x)          (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG1_SW_DEC_RDY_INT_SHIFT)) & VPU_G2_SWREG1_SW_DEC_RDY_INT_MASK)

#define VPU_G2_SWREG1_SW_DEC_BUS_INT_MASK        (0x2000U)
#define VPU_G2_SWREG1_SW_DEC_BUS_INT_SHIFT       (13U)
/*! SW_DEC_BUS_INT - Interrupt status bit bus. Error response from bus. HW will self reset. */
#define VPU_G2_SWREG1_SW_DEC_BUS_INT(x)          (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG1_SW_DEC_BUS_INT_SHIFT)) & VPU_G2_SWREG1_SW_DEC_BUS_INT_MASK)

#define VPU_G2_SWREG1_SW_DEC_BUFFER_INT_MASK     (0x4000U)
#define VPU_G2_SWREG1_SW_DEC_BUFFER_INT_SHIFT    (14U)
/*! SW_DEC_BUFFER_INT - Interrupt status bit input buffer empty. When high input stream buffer is
 *    empty but picture is not ready. HW will not self reset.
 */
#define VPU_G2_SWREG1_SW_DEC_BUFFER_INT(x)       (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG1_SW_DEC_BUFFER_INT_SHIFT)) & VPU_G2_SWREG1_SW_DEC_BUFFER_INT_MASK)

#define VPU_G2_SWREG1_SW_DEC_ERROR_INT_MASK      (0x10000U)
#define VPU_G2_SWREG1_SW_DEC_ERROR_INT_SHIFT     (16U)
/*! SW_DEC_ERROR_INT - Interrupt status bit input stream error. When high an error is found in input data stream decoding. HW will self reset. */
#define VPU_G2_SWREG1_SW_DEC_ERROR_INT(x)        (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG1_SW_DEC_ERROR_INT_SHIFT)) & VPU_G2_SWREG1_SW_DEC_ERROR_INT_MASK)

#define VPU_G2_SWREG1_SW_DEC_TIMEOUT_MASK        (0x40000U)
#define VPU_G2_SWREG1_SW_DEC_TIMEOUT_SHIFT       (18U)
/*! SW_DEC_TIMEOUT - Interrupt status bit decoder timeout. When high the decoder has been idling for
 *    too long. HW will self reset. Possible only if timeout interrupt is enabled
 */
#define VPU_G2_SWREG1_SW_DEC_TIMEOUT(x)          (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG1_SW_DEC_TIMEOUT_SHIFT)) & VPU_G2_SWREG1_SW_DEC_TIMEOUT_MASK)
/*! @} */

/*! @name SWREG2 - Data configuration register decoder */
/*! @{ */

#define VPU_G2_SWREG2_SW_DEC_RSCAN_SWAP_MASK     (0xFU)
#define VPU_G2_SWREG2_SW_DEC_RSCAN_SWAP_SHIFT    (0U)
/*! SW_DEC_RSCAN_SWAP - Byte swap for raster scan output picture data */
#define VPU_G2_SWREG2_SW_DEC_RSCAN_SWAP(x)       (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG2_SW_DEC_RSCAN_SWAP_SHIFT)) & VPU_G2_SWREG2_SW_DEC_RSCAN_SWAP_MASK)

#define VPU_G2_SWREG2_SW_DEC_TAB3_SWAP_MASK      (0xF0U)
#define VPU_G2_SWREG2_SW_DEC_TAB3_SWAP_SHIFT     (4U)
/*! SW_DEC_TAB3_SWAP - Byte swap configuration for tile sizes */
#define VPU_G2_SWREG2_SW_DEC_TAB3_SWAP(x)        (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG2_SW_DEC_TAB3_SWAP_SHIFT)) & VPU_G2_SWREG2_SW_DEC_TAB3_SWAP_MASK)

#define VPU_G2_SWREG2_SW_DEC_TAB2_SWAP_MASK      (0xF00U)
#define VPU_G2_SWREG2_SW_DEC_TAB2_SWAP_SHIFT     (8U)
/*! SW_DEC_TAB2_SWAP - Byte swap configuration for VP9 CTX counter values */
#define VPU_G2_SWREG2_SW_DEC_TAB2_SWAP(x)        (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG2_SW_DEC_TAB2_SWAP_SHIFT)) & VPU_G2_SWREG2_SW_DEC_TAB2_SWAP_MASK)

#define VPU_G2_SWREG2_SW_DEC_TAB1_SWAP_MASK      (0xF000U)
#define VPU_G2_SWREG2_SW_DEC_TAB1_SWAP_SHIFT     (12U)
/*! SW_DEC_TAB1_SWAP - Byte swap configuration for HEVC scaling lists / VP9 segmentation map read/write */
#define VPU_G2_SWREG2_SW_DEC_TAB1_SWAP(x)        (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG2_SW_DEC_TAB1_SWAP_SHIFT)) & VPU_G2_SWREG2_SW_DEC_TAB1_SWAP_MASK)

#define VPU_G2_SWREG2_SW_DEC_TAB0_SWAP_MASK      (0xF0000U)
#define VPU_G2_SWREG2_SW_DEC_TAB0_SWAP_SHIFT     (16U)
/*! SW_DEC_TAB0_SWAP - Byte swap configuration for VP9 stream propability tables */
#define VPU_G2_SWREG2_SW_DEC_TAB0_SWAP(x)        (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG2_SW_DEC_TAB0_SWAP_SHIFT)) & VPU_G2_SWREG2_SW_DEC_TAB0_SWAP_MASK)

#define VPU_G2_SWREG2_SW_DEC_DIRMV_SWAP_MASK     (0xF00000U)
#define VPU_G2_SWREG2_SW_DEC_DIRMV_SWAP_SHIFT    (20U)
/*! SW_DEC_DIRMV_SWAP - Byte swap configuration for direct mode MV data (read/write) */
#define VPU_G2_SWREG2_SW_DEC_DIRMV_SWAP(x)       (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG2_SW_DEC_DIRMV_SWAP_SHIFT)) & VPU_G2_SWREG2_SW_DEC_DIRMV_SWAP_MASK)

#define VPU_G2_SWREG2_SW_DEC_PIC_SWAP_MASK       (0xF000000U)
#define VPU_G2_SWREG2_SW_DEC_PIC_SWAP_SHIFT      (24U)
/*! SW_DEC_PIC_SWAP - Byte swap configuration for decoder reference output picture data */
#define VPU_G2_SWREG2_SW_DEC_PIC_SWAP(x)         (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG2_SW_DEC_PIC_SWAP_SHIFT)) & VPU_G2_SWREG2_SW_DEC_PIC_SWAP_MASK)

#define VPU_G2_SWREG2_SW_DEC_STRM_SWAP_MASK      (0xF0000000U)
#define VPU_G2_SWREG2_SW_DEC_STRM_SWAP_SHIFT     (28U)
/*! SW_DEC_STRM_SWAP - Byte swap configuration for stream data 4 Bit byte order vector to control
 *    byte locations inside HW internal 128 bit data vector. For 64 and 32 bit external bus widths,
 *    the data is first gathered to 128 bit width and then bytes swapped accordingly:
 */
#define VPU_G2_SWREG2_SW_DEC_STRM_SWAP(x)        (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG2_SW_DEC_STRM_SWAP_SHIFT)) & VPU_G2_SWREG2_SW_DEC_STRM_SWAP_MASK)
/*! @} */

/*! @name SWREG3 - Decoder control register 0 */
/*! @{ */

#define VPU_G2_SWREG3_SW_APF_ONE_PID_MASK        (0x800U)
#define VPU_G2_SWREG3_SW_APF_ONE_PID_SHIFT       (11U)
/*! SW_APF_ONE_PID - Prefetch partitions that have the same pic_id together */
#define VPU_G2_SWREG3_SW_APF_ONE_PID(x)          (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG3_SW_APF_ONE_PID_SHIFT)) & VPU_G2_SWREG3_SW_APF_ONE_PID_MASK)

#define VPU_G2_SWREG3_SW_WRITE_MVS_E_MASK        (0x1000U)
#define VPU_G2_SWREG3_SW_WRITE_MVS_E_SHIFT       (12U)
/*! SW_WRITE_MVS_E - Direct mode motion vector write enable for current picture
 *  0b0..Writing disabled for current picture.
 *  0b1..The direct mode motion vectors are written to external memory. HEVC/VP9 direct mode motion vectors are
 *       written to DPB aside with the corresponding reference picture. Other decoding mode dir mode mvs are written
 *       to external memory starting from sw_dir_mv_base.
 */
#define VPU_G2_SWREG3_SW_WRITE_MVS_E(x)          (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG3_SW_WRITE_MVS_E_SHIFT)) & VPU_G2_SWREG3_SW_WRITE_MVS_E_MASK)

#define VPU_G2_SWREG3_SW_FILTERING_DIS_MASK      (0x4000U)
#define VPU_G2_SWREG3_SW_FILTERING_DIS_SHIFT     (14U)
/*! SW_FILTERING_DIS - De-block filtering disable
 *  0b0..Filtering is enabled for current picture
 *  0b1..Filtering is disabled for current picture
 */
#define VPU_G2_SWREG3_SW_FILTERING_DIS(x)        (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG3_SW_FILTERING_DIS_SHIFT)) & VPU_G2_SWREG3_SW_FILTERING_DIS_MASK)

#define VPU_G2_SWREG3_SW_DEC_OUT_DIS_MASK        (0x8000U)
#define VPU_G2_SWREG3_SW_DEC_OUT_DIS_SHIFT       (15U)
/*! SW_DEC_OUT_DIS - Disable decoder output picture writing
 *  0b0..Decoder output picture is written to external memory
 *  0b1..Decoder output picture is not written to external memory
 */
#define VPU_G2_SWREG3_SW_DEC_OUT_DIS(x)          (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG3_SW_DEC_OUT_DIS_SHIFT)) & VPU_G2_SWREG3_SW_DEC_OUT_DIS_MASK)

#define VPU_G2_SWREG3_SW_DEC_OUT_RS_E_MASK       (0x10000U)
#define VPU_G2_SWREG3_SW_DEC_OUT_RS_E_SHIFT      (16U)
/*! SW_DEC_OUT_RS_E - Raster scan output enable. If high decoder writes the raster scan output if
 *    the configuration of Decoder includes PP raster scan output
 */
#define VPU_G2_SWREG3_SW_DEC_OUT_RS_E(x)         (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG3_SW_DEC_OUT_RS_E_SHIFT)) & VPU_G2_SWREG3_SW_DEC_OUT_RS_E_MASK)

#define VPU_G2_SWREG3_SW_DEC_OUT_EC_BYPASS_MASK  (0x20000U)
#define VPU_G2_SWREG3_SW_DEC_OUT_EC_BYPASS_SHIFT (17U)
/*! SW_DEC_OUT_EC_BYPASS - Compress bypass */
#define VPU_G2_SWREG3_SW_DEC_OUT_EC_BYPASS(x)    (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG3_SW_DEC_OUT_EC_BYPASS_SHIFT)) & VPU_G2_SWREG3_SW_DEC_OUT_EC_BYPASS_MASK)

#define VPU_G2_SWREG3_SW_DEC_COMP_TABLE_SWAP_MASK (0xF00000U)
#define VPU_G2_SWREG3_SW_DEC_COMP_TABLE_SWAP_SHIFT (20U)
/*! SW_DEC_COMP_TABLE_SWAP - Byte swap configuration for compress table data */
#define VPU_G2_SWREG3_SW_DEC_COMP_TABLE_SWAP(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG3_SW_DEC_COMP_TABLE_SWAP_SHIFT)) & VPU_G2_SWREG3_SW_DEC_COMP_TABLE_SWAP_MASK)

#define VPU_G2_SWREG3_SW_DEC_MODE_MASK           (0xF8000000U)
#define VPU_G2_SWREG3_SW_DEC_MODE_SHIFT          (27U)
/*! SW_DEC_MODE - Decoding mode:
 *  0b00000-0b01011..Reserved
 *  0b01100..HEVC
 *  0b01101..VP9
 *  0b01110-0b11111..Reserved
 */
#define VPU_G2_SWREG3_SW_DEC_MODE(x)             (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG3_SW_DEC_MODE_SHIFT)) & VPU_G2_SWREG3_SW_DEC_MODE_MASK)
/*! @} */

/*! @name SWREG4 - Decoder control register 1 */
/*! @{ */

#define VPU_G2_SWREG4_SW_REF_FRAMES_MASK         (0x1FU)
#define VPU_G2_SWREG4_SW_REF_FRAMES_SHIFT        (0U)
/*! SW_REF_FRAMES - HEVC: num_ref_frames maximum number of short and long term reference frames in decoded picture buffer */
#define VPU_G2_SWREG4_SW_REF_FRAMES(x)           (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG4_SW_REF_FRAMES_SHIFT)) & VPU_G2_SWREG4_SW_REF_FRAMES_MASK)

#define VPU_G2_SWREG4_SW_PIC_HEIGHT_IN_CBS_MASK  (0x7FFC0U)
#define VPU_G2_SWREG4_SW_PIC_HEIGHT_IN_CBS_SHIFT (6U)
/*! SW_PIC_HEIGHT_IN_CBS - Picture height in min coded blocks (min = 8pix) */
#define VPU_G2_SWREG4_SW_PIC_HEIGHT_IN_CBS(x)    (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG4_SW_PIC_HEIGHT_IN_CBS_SHIFT)) & VPU_G2_SWREG4_SW_PIC_HEIGHT_IN_CBS_MASK)

#define VPU_G2_SWREG4_SW_PIC_WIDTH_IN_CBS_MASK   (0xFFF80000U)
#define VPU_G2_SWREG4_SW_PIC_WIDTH_IN_CBS_SHIFT  (19U)
/*! SW_PIC_WIDTH_IN_CBS - Picture width in min coded blocks (min = 8pix) */
#define VPU_G2_SWREG4_SW_PIC_WIDTH_IN_CBS(x)     (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG4_SW_PIC_WIDTH_IN_CBS_SHIFT)) & VPU_G2_SWREG4_SW_PIC_WIDTH_IN_CBS_MASK)
/*! @} */

/*! @name SWREG5 - Decoder control register 2 */
/*! @{ */

#define VPU_G2_SWREG5_SW_CU_QPD_E_MASK           (0x10U)
#define VPU_G2_SWREG5_SW_CU_QPD_E_SHIFT          (4U)
/*! SW_CU_QPD_E - CU qp delta enable */
#define VPU_G2_SWREG5_SW_CU_QPD_E(x)             (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG5_SW_CU_QPD_E_SHIFT)) & VPU_G2_SWREG5_SW_CU_QPD_E_MASK)

#define VPU_G2_SWREG5_SW_MAX_CU_QPD_DEPTH_MASK   (0x7E0U)
#define VPU_G2_SWREG5_SW_MAX_CU_QPD_DEPTH_SHIFT  (5U)
/*! SW_MAX_CU_QPD_DEPTH - Max CU qp delta depth */
#define VPU_G2_SWREG5_SW_MAX_CU_QPD_DEPTH(x)     (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG5_SW_MAX_CU_QPD_DEPTH_SHIFT)) & VPU_G2_SWREG5_SW_MAX_CU_QPD_DEPTH_MASK)

#define VPU_G2_SWREG5_SW_TEMPOR_MVP_E_MASK       (0x800U)
#define VPU_G2_SWREG5_SW_TEMPOR_MVP_E_SHIFT      (11U)
/*! SW_TEMPOR_MVP_E - Temporal mvp enable */
#define VPU_G2_SWREG5_SW_TEMPOR_MVP_E(x)         (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG5_SW_TEMPOR_MVP_E_SHIFT)) & VPU_G2_SWREG5_SW_TEMPOR_MVP_E_MASK)

#define VPU_G2_SWREG5_SW_SIGN_DATA_HIDE_MASK     (0x1000U)
#define VPU_G2_SWREG5_SW_SIGN_DATA_HIDE_SHIFT    (12U)
/*! SW_SIGN_DATA_HIDE - Flag for stream decoding */
#define VPU_G2_SWREG5_SW_SIGN_DATA_HIDE(x)       (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG5_SW_SIGN_DATA_HIDE_SHIFT)) & VPU_G2_SWREG5_SW_SIGN_DATA_HIDE_MASK)

#define VPU_G2_SWREG5_SW_CH_QP_OFFSET2_MASK      (0x7C000U)
#define VPU_G2_SWREG5_SW_CH_QP_OFFSET2_SHIFT     (14U)
/*! SW_CH_QP_OFFSET2 - Chroma Qp filter offset for cr type */
#define VPU_G2_SWREG5_SW_CH_QP_OFFSET2(x)        (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG5_SW_CH_QP_OFFSET2_SHIFT)) & VPU_G2_SWREG5_SW_CH_QP_OFFSET2_MASK)

#define VPU_G2_SWREG5_SW_CH_QP_OFFSET_MASK       (0xF80000U)
#define VPU_G2_SWREG5_SW_CH_QP_OFFSET_SHIFT      (19U)
/*! SW_CH_QP_OFFSET - Chroma Qp filter offset. (For HEVC this offset concerns Cb only) */
#define VPU_G2_SWREG5_SW_CH_QP_OFFSET(x)         (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG5_SW_CH_QP_OFFSET_SHIFT)) & VPU_G2_SWREG5_SW_CH_QP_OFFSET_MASK)

#define VPU_G2_SWREG5_SW_SCALING_LIST_E_MASK     (0x1000000U)
#define VPU_G2_SWREG5_SW_SCALING_LIST_E_SHIFT    (24U)
/*! SW_SCALING_LIST_E - Scaling matrix enable
 *  0b0..Normal transform
 *  0b1..Use scaling matrix for transform (read from external memory)
 */
#define VPU_G2_SWREG5_SW_SCALING_LIST_E(x)       (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG5_SW_SCALING_LIST_E_SHIFT)) & VPU_G2_SWREG5_SW_SCALING_LIST_E_MASK)

#define VPU_G2_SWREG5_SW_STRM_START_BIT_MASK     (0xFE000000U)
#define VPU_G2_SWREG5_SW_STRM_START_BIT_SHIFT    (25U)
/*! SW_STRM_START_BIT - Exact bit of stream start word where decoding can be started (assosiates with sw_rlc_vlc_base) */
#define VPU_G2_SWREG5_SW_STRM_START_BIT(x)       (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG5_SW_STRM_START_BIT_SHIFT)) & VPU_G2_SWREG5_SW_STRM_START_BIT_MASK)
/*! @} */

/*! @name SWREG6 - Decoder control register 3 */
/*! @{ */

#define VPU_G2_SWREG6_SW_STREAM_LEN_MASK         (0xFFFFFFFFU)
#define VPU_G2_SWREG6_SW_STREAM_LEN_SHIFT        (0U)
/*! SW_STREAM_LEN - Amount of stream data bytes in input buffer. If the given buffer size is not
 *    enough for finishing the picture the corresponding interrupt is given and new stream buffer base
 *    address and stream buffer size information should be given (assosiates with sw_rlc_vlc_base).
 *    For HEVC the buffer must include at least data for one slice/VP of the picture
 */
#define VPU_G2_SWREG6_SW_STREAM_LEN(x)           (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG6_SW_STREAM_LEN_SHIFT)) & VPU_G2_SWREG6_SW_STREAM_LEN_MASK)
/*! @} */

/*! @name SWREG7 - Decoder control register 4 */
/*! @{ */

#define VPU_G2_SWREG7_SW_SLICE_HDR_EBITS_MASK    (0x38U)
#define VPU_G2_SWREG7_SW_SLICE_HDR_EBITS_SHIFT   (3U)
/*! SW_SLICE_HDR_EBITS - Number of extra slice header bits (if enabled slice header extension) */
#define VPU_G2_SWREG7_SW_SLICE_HDR_EBITS(x)      (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG7_SW_SLICE_HDR_EBITS_SHIFT)) & VPU_G2_SWREG7_SW_SLICE_HDR_EBITS_MASK)

#define VPU_G2_SWREG7_SW_SLICE_HDR_EXT_E_MASK    (0x40U)
#define VPU_G2_SWREG7_SW_SLICE_HDR_EXT_E_SHIFT   (6U)
/*! SW_SLICE_HDR_EXT_E - Slice header extension enable. Reserved for future use */
#define VPU_G2_SWREG7_SW_SLICE_HDR_EXT_E(x)      (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG7_SW_SLICE_HDR_EXT_E_SHIFT)) & VPU_G2_SWREG7_SW_SLICE_HDR_EXT_E_MASK)

#define VPU_G2_SWREG7_SW_FILT_OFFSET_TC_MASK     (0xF80U)
#define VPU_G2_SWREG7_SW_FILT_OFFSET_TC_SHIFT    (7U)
/*! SW_FILT_OFFSET_TC - Filter tc offset (declared as div2) */
#define VPU_G2_SWREG7_SW_FILT_OFFSET_TC(x)       (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG7_SW_FILT_OFFSET_TC_SHIFT)) & VPU_G2_SWREG7_SW_FILT_OFFSET_TC_MASK)

#define VPU_G2_SWREG7_SW_FILT_OFFSET_BETA_MASK   (0x1F000U)
#define VPU_G2_SWREG7_SW_FILT_OFFSET_BETA_SHIFT  (12U)
/*! SW_FILT_OFFSET_BETA - Filter beta offset (declared as div2) */
#define VPU_G2_SWREG7_SW_FILT_OFFSET_BETA(x)     (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG7_SW_FILT_OFFSET_BETA_SHIFT)) & VPU_G2_SWREG7_SW_FILT_OFFSET_BETA_MASK)

#define VPU_G2_SWREG7_SW_STRONG_SMOOTH_E_MASK    (0x20000U)
#define VPU_G2_SWREG7_SW_STRONG_SMOOTH_E_SHIFT   (17U)
/*! SW_STRONG_SMOOTH_E - Strong smoothing enable */
#define VPU_G2_SWREG7_SW_STRONG_SMOOTH_E(x)      (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG7_SW_STRONG_SMOOTH_E_SHIFT)) & VPU_G2_SWREG7_SW_STRONG_SMOOTH_E_MASK)

#define VPU_G2_SWREG7_SW_FILT_OVERRIDE_E_MASK    (0x40000U)
#define VPU_G2_SWREG7_SW_FILT_OVERRIDE_E_SHIFT   (18U)
/*! SW_FILT_OVERRIDE_E - Filter override enable */
#define VPU_G2_SWREG7_SW_FILT_OVERRIDE_E(x)      (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG7_SW_FILT_OVERRIDE_E_SHIFT)) & VPU_G2_SWREG7_SW_FILT_OVERRIDE_E_MASK)

#define VPU_G2_SWREG7_SW_DEPEND_SLICE_E_MASK     (0x80000U)
#define VPU_G2_SWREG7_SW_DEPEND_SLICE_E_SHIFT    (19U)
/*! SW_DEPEND_SLICE_E - Dependent slice enable */
#define VPU_G2_SWREG7_SW_DEPEND_SLICE_E(x)       (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG7_SW_DEPEND_SLICE_E_SHIFT)) & VPU_G2_SWREG7_SW_DEPEND_SLICE_E_MASK)

#define VPU_G2_SWREG7_SW_SLICE_CHQP_FLAG_MASK    (0x100000U)
#define VPU_G2_SWREG7_SW_SLICE_CHQP_FLAG_SHIFT   (20U)
/*! SW_SLICE_CHQP_FLAG - Slice header flag for chroma QP present (if it is included in slice header) */
#define VPU_G2_SWREG7_SW_SLICE_CHQP_FLAG(x)      (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG7_SW_SLICE_CHQP_FLAG_SHIFT)) & VPU_G2_SWREG7_SW_SLICE_CHQP_FLAG_MASK)

#define VPU_G2_SWREG7_SW_PCM_FILT_DISABLE_MASK   (0x200000U)
#define VPU_G2_SWREG7_SW_PCM_FILT_DISABLE_SHIFT  (21U)
/*! SW_PCM_FILT_DISABLE - Disable for PCM loop filtering */
#define VPU_G2_SWREG7_SW_PCM_FILT_DISABLE(x)     (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG7_SW_PCM_FILT_DISABLE_SHIFT)) & VPU_G2_SWREG7_SW_PCM_FILT_DISABLE_MASK)

#define VPU_G2_SWREG7_SW_SAO_E_MASK              (0x400000U)
#define VPU_G2_SWREG7_SW_SAO_E_SHIFT             (22U)
/*! SW_SAO_E - Sample Adaptive Offset enable for stream decoding */
#define VPU_G2_SWREG7_SW_SAO_E(x)                (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG7_SW_SAO_E_SHIFT)) & VPU_G2_SWREG7_SW_SAO_E_MASK)

#define VPU_G2_SWREG7_SW_ASYM_PRED_E_MASK        (0x800000U)
#define VPU_G2_SWREG7_SW_ASYM_PRED_E_SHIFT       (23U)
/*! SW_ASYM_PRED_E - Asymmetric prediction flag for stream decoding */
#define VPU_G2_SWREG7_SW_ASYM_PRED_E(x)          (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG7_SW_ASYM_PRED_E_SHIFT)) & VPU_G2_SWREG7_SW_ASYM_PRED_E_MASK)

#define VPU_G2_SWREG7_SW_FILT_TILE_BORDER_MASK   (0x1000000U)
#define VPU_G2_SWREG7_SW_FILT_TILE_BORDER_SHIFT  (24U)
/*! SW_FILT_TILE_BORDER - Filter enable over tile border */
#define VPU_G2_SWREG7_SW_FILT_TILE_BORDER(x)     (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG7_SW_FILT_TILE_BORDER_SHIFT)) & VPU_G2_SWREG7_SW_FILT_TILE_BORDER_MASK)

#define VPU_G2_SWREG7_SW_FILT_SLICE_BORDER_MASK  (0x2000000U)
#define VPU_G2_SWREG7_SW_FILT_SLICE_BORDER_SHIFT (25U)
/*! SW_FILT_SLICE_BORDER - Filter enable over slice border */
#define VPU_G2_SWREG7_SW_FILT_SLICE_BORDER(x)    (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG7_SW_FILT_SLICE_BORDER_SHIFT)) & VPU_G2_SWREG7_SW_FILT_SLICE_BORDER_MASK)

#define VPU_G2_SWREG7_SW_WEIGHT_BIPR_IDC_MASK    (0xC000000U)
#define VPU_G2_SWREG7_SW_WEIGHT_BIPR_IDC_SHIFT   (26U)
/*! SW_WEIGHT_BIPR_IDC - Weighted prediction specification
 *  0b00..Default weighted prediction is applied to B slices
 *  0b01..Explicit weighted prediction shall be applied to B slices
 *  0b10..NA
 *  0b11..NA
 */
#define VPU_G2_SWREG7_SW_WEIGHT_BIPR_IDC(x)      (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG7_SW_WEIGHT_BIPR_IDC_SHIFT)) & VPU_G2_SWREG7_SW_WEIGHT_BIPR_IDC_MASK)

#define VPU_G2_SWREG7_SW_WEIGHT_PRED_E_MASK      (0x10000000U)
#define VPU_G2_SWREG7_SW_WEIGHT_PRED_E_SHIFT     (28U)
/*! SW_WEIGHT_PRED_E - Weighted prediction enable for P slices */
#define VPU_G2_SWREG7_SW_WEIGHT_PRED_E(x)        (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG7_SW_WEIGHT_PRED_E_SHIFT)) & VPU_G2_SWREG7_SW_WEIGHT_PRED_E_MASK)

#define VPU_G2_SWREG7_SW_BLACKWHITE_E_MASK       (0x40000000U)
#define VPU_G2_SWREG7_SW_BLACKWHITE_E_SHIFT      (30U)
/*! SW_BLACKWHITE_E - Sampling
 *  0b0..4:2:0 sampling format
 *  0b1..4:0:0 sampling format (H264 monochroma)
 */
#define VPU_G2_SWREG7_SW_BLACKWHITE_E(x)         (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG7_SW_BLACKWHITE_E_SHIFT)) & VPU_G2_SWREG7_SW_BLACKWHITE_E_MASK)

#define VPU_G2_SWREG7_SW_CABAC_INIT_PRESENT_MASK (0x80000000U)
#define VPU_G2_SWREG7_SW_CABAC_INIT_PRESENT_SHIFT (31U)
/*! SW_CABAC_INIT_PRESENT - CABAC init present enable for stream decoding */
#define VPU_G2_SWREG7_SW_CABAC_INIT_PRESENT(x)   (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG7_SW_CABAC_INIT_PRESENT_SHIFT)) & VPU_G2_SWREG7_SW_CABAC_INIT_PRESENT_MASK)
/*! @} */

/*! @name SWREG8 - Decoder control register 5 */
/*! @{ */

#define VPU_G2_SWREG8_SW_OUTPUT_FORMAT_MASK      (0x7U)
#define VPU_G2_SWREG8_SW_OUTPUT_FORMAT_SHIFT     (0U)
/*! SW_OUTPUT_FORMAT - Raster scan and down scale output data format
 *  0b000..Each pixel in 10 bits when luma or chroma pixel bit depth is larger than 8; or 8 bits when both luma
 *         and chroma pixel bit depth are 8 bits. (default)
 *  0b001..Store in P010 format when luma or chroma pixel bit depth is larger than 8.
 *  0b010..A customized format: please refer to register SWREG23[6].
 */
#define VPU_G2_SWREG8_SW_OUTPUT_FORMAT(x)        (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG8_SW_OUTPUT_FORMAT_SHIFT)) & VPU_G2_SWREG8_SW_OUTPUT_FORMAT_MASK)

#define VPU_G2_SWREG8_SW_OUTPUT_8_BITS_MASK      (0x8U)
#define VPU_G2_SWREG8_SW_OUTPUT_8_BITS_SHIFT     (3U)
/*! SW_OUTPUT_8_BITS - enable rasterscan output force to 8 bit(only for hevc main10 and vp9 10bit) */
#define VPU_G2_SWREG8_SW_OUTPUT_8_BITS(x)        (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG8_SW_OUTPUT_8_BITS_SHIFT)) & VPU_G2_SWREG8_SW_OUTPUT_8_BITS_MASK)

#define VPU_G2_SWREG8_SW_BIT_DEPTH_C_MINUS8_MASK (0x30U)
#define VPU_G2_SWREG8_SW_BIT_DEPTH_C_MINUS8_SHIFT (4U)
/*! SW_BIT_DEPTH_C_MINUS8 - Bit depth of chroma samples minus 8 */
#define VPU_G2_SWREG8_SW_BIT_DEPTH_C_MINUS8(x)   (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG8_SW_BIT_DEPTH_C_MINUS8_SHIFT)) & VPU_G2_SWREG8_SW_BIT_DEPTH_C_MINUS8_MASK)

#define VPU_G2_SWREG8_SW_BIT_DEPTH_Y_MINUS8_MASK (0xC0U)
#define VPU_G2_SWREG8_SW_BIT_DEPTH_Y_MINUS8_SHIFT (6U)
/*! SW_BIT_DEPTH_Y_MINUS8 - Bit depth of luma samples minus 8 */
#define VPU_G2_SWREG8_SW_BIT_DEPTH_Y_MINUS8(x)   (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG8_SW_BIT_DEPTH_Y_MINUS8_SHIFT)) & VPU_G2_SWREG8_SW_BIT_DEPTH_Y_MINUS8_MASK)

#define VPU_G2_SWREG8_SW_PCM_BITDEPTH_C_MASK     (0xF00U)
#define VPU_G2_SWREG8_SW_PCM_BITDEPTH_C_SHIFT    (8U)
/*! SW_PCM_BITDEPTH_C - Bit depth for PCM C data */
#define VPU_G2_SWREG8_SW_PCM_BITDEPTH_C(x)       (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG8_SW_PCM_BITDEPTH_C_SHIFT)) & VPU_G2_SWREG8_SW_PCM_BITDEPTH_C_MASK)

#define VPU_G2_SWREG8_SW_PCM_BITDEPTH_Y_MASK     (0xF000U)
#define VPU_G2_SWREG8_SW_PCM_BITDEPTH_Y_SHIFT    (12U)
/*! SW_PCM_BITDEPTH_Y - Bit depth for PCM Y data */
#define VPU_G2_SWREG8_SW_PCM_BITDEPTH_Y(x)       (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG8_SW_PCM_BITDEPTH_Y_SHIFT)) & VPU_G2_SWREG8_SW_PCM_BITDEPTH_Y_MASK)

#define VPU_G2_SWREG8_SW_IDR_PIC_E_MASK          (0x10000U)
#define VPU_G2_SWREG8_SW_IDR_PIC_E_SHIFT         (16U)
/*! SW_IDR_PIC_E - IDR (instantaneous decoding refresh) picture flag. */
#define VPU_G2_SWREG8_SW_IDR_PIC_E(x)            (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG8_SW_IDR_PIC_E_SHIFT)) & VPU_G2_SWREG8_SW_IDR_PIC_E_MASK)

#define VPU_G2_SWREG8_SW_FILT_CTRL_PRES_MASK     (0x40000000U)
#define VPU_G2_SWREG8_SW_FILT_CTRL_PRES_SHIFT    (30U)
/*! SW_FILT_CTRL_PRES - deblocking_filter_control_present_flag indicates whether extra variables
 *    controlling characteristics of the deblocking filter are present in the slice header.
 */
#define VPU_G2_SWREG8_SW_FILT_CTRL_PRES(x)       (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG8_SW_FILT_CTRL_PRES_SHIFT)) & VPU_G2_SWREG8_SW_FILT_CTRL_PRES_MASK)

#define VPU_G2_SWREG8_SW_CONST_INTRA_E_MASK      (0x80000000U)
#define VPU_G2_SWREG8_SW_CONST_INTRA_E_SHIFT     (31U)
/*! SW_CONST_INTRA_E - constrained_intra_pred_flag equal to 1 specifies that intra prediction uses
 *    only neighbouring intra macroblocks in prediction. When equal to 0 also neighbouring inter
 *    macroblocks are used in intra prediction process.
 */
#define VPU_G2_SWREG8_SW_CONST_INTRA_E(x)        (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG8_SW_CONST_INTRA_E_SHIFT)) & VPU_G2_SWREG8_SW_CONST_INTRA_E_MASK)
/*! @} */

/*! @name SWREG9 - Decoder control register 6 */
/*! @{ */

#define VPU_G2_SWREG9_SW_HDR_SKIP_LENGTH_MASK    (0x3FFFU)
#define VPU_G2_SWREG9_SW_HDR_SKIP_LENGTH_SHIFT   (0U)
/*! SW_HDR_SKIP_LENGTH - Length of slice header skip length (bytes used by sw) */
#define VPU_G2_SWREG9_SW_HDR_SKIP_LENGTH(x)      (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG9_SW_HDR_SKIP_LENGTH_SHIFT)) & VPU_G2_SWREG9_SW_HDR_SKIP_LENGTH_MASK)

#define VPU_G2_SWREG9_SW_REFIDX0_ACTIVE_MASK     (0x7C000U)
#define VPU_G2_SWREG9_SW_REFIDX0_ACTIVE_SHIFT    (14U)
/*! SW_REFIDX0_ACTIVE - Specifies the maximum reference index that can be used while decoding inter
 *    predicted macro blocks. This is same as in previous decoders (width increased with q bit)
 */
#define VPU_G2_SWREG9_SW_REFIDX0_ACTIVE(x)       (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG9_SW_REFIDX0_ACTIVE_SHIFT)) & VPU_G2_SWREG9_SW_REFIDX0_ACTIVE_MASK)

#define VPU_G2_SWREG9_SW_REFIDX1_ACTIVE_MASK     (0xF80000U)
#define VPU_G2_SWREG9_SW_REFIDX1_ACTIVE_SHIFT    (19U)
/*! SW_REFIDX1_ACTIVE - Specifies the maximum reference index that can be used while decoding inter predicted macro blocks. */
#define VPU_G2_SWREG9_SW_REFIDX1_ACTIVE(x)       (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG9_SW_REFIDX1_ACTIVE_SHIFT)) & VPU_G2_SWREG9_SW_REFIDX1_ACTIVE_MASK)
/*! @} */

/*! @name SWREG10 - Decoder control register 7 */
/*! @{ */

#define VPU_G2_SWREG10_SW_ENTR_CODE_SYNCH_E_MASK (0x1U)
#define VPU_G2_SWREG10_SW_ENTR_CODE_SYNCH_E_SHIFT (0U)
/*! SW_ENTR_CODE_SYNCH_E - Entropy coding synchronization enable (Possible parallel cabac decoding) */
#define VPU_G2_SWREG10_SW_ENTR_CODE_SYNCH_E(x)   (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG10_SW_ENTR_CODE_SYNCH_E_SHIFT)) & VPU_G2_SWREG10_SW_ENTR_CODE_SYNCH_E_MASK)

#define VPU_G2_SWREG10_SW_TILE_ENABLE_MASK       (0x2U)
#define VPU_G2_SWREG10_SW_TILE_ENABLE_SHIFT      (1U)
/*! SW_TILE_ENABLE - Tile enable */
#define VPU_G2_SWREG10_SW_TILE_ENABLE(x)         (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG10_SW_TILE_ENABLE_SHIFT)) & VPU_G2_SWREG10_SW_TILE_ENABLE_MASK)

#define VPU_G2_SWREG10_SW_NUM_TILE_ROWS_MASK     (0x7C000U)
#define VPU_G2_SWREG10_SW_NUM_TILE_ROWS_SHIFT    (14U)
/*! SW_NUM_TILE_ROWS - Number of tile rows in picture */
#define VPU_G2_SWREG10_SW_NUM_TILE_ROWS(x)       (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG10_SW_NUM_TILE_ROWS_SHIFT)) & VPU_G2_SWREG10_SW_NUM_TILE_ROWS_MASK)

#define VPU_G2_SWREG10_SW_NUM_TILE_COLS_MASK     (0xF80000U)
#define VPU_G2_SWREG10_SW_NUM_TILE_COLS_SHIFT    (19U)
/*! SW_NUM_TILE_COLS - Number of tile columns in picture */
#define VPU_G2_SWREG10_SW_NUM_TILE_COLS(x)       (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG10_SW_NUM_TILE_COLS_SHIFT)) & VPU_G2_SWREG10_SW_NUM_TILE_COLS_MASK)

#define VPU_G2_SWREG10_SW_INIT_QP_MASK           (0x7F000000U)
#define VPU_G2_SWREG10_SW_INIT_QP_SHIFT          (24U)
/*! SW_INIT_QP - Initial value for quantization parameter (picture quantizer). */
#define VPU_G2_SWREG10_SW_INIT_QP(x)             (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG10_SW_INIT_QP_SHIFT)) & VPU_G2_SWREG10_SW_INIT_QP_MASK)

#define VPU_G2_SWREG10_SW_START_CODE_E_MASK      (0x80000000U)
#define VPU_G2_SWREG10_SW_START_CODE_E_SHIFT     (31U)
/*! SW_START_CODE_E - Bit for indicating stream start code existence
 *  0b0..Stream does not contain start codes
 *  0b1..Stream contains start codes
 */
#define VPU_G2_SWREG10_SW_START_CODE_E(x)        (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG10_SW_START_CODE_E_SHIFT)) & VPU_G2_SWREG10_SW_START_CODE_E_MASK)
/*! @} */

/*! @name SWREG11 - Decoder control register 8 */
/*! @{ */

#define VPU_G2_SWREG11_SW_AREF_SIGN_BIAS_MASK    (0x1U)
#define VPU_G2_SWREG11_SW_AREF_SIGN_BIAS_SHIFT   (0U)
/*! SW_AREF_SIGN_BIAS - Alternate reference picture sign bias used for motion vector decoding */
#define VPU_G2_SWREG11_SW_AREF_SIGN_BIAS(x)      (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG11_SW_AREF_SIGN_BIAS_SHIFT)) & VPU_G2_SWREG11_SW_AREF_SIGN_BIAS_MASK)

#define VPU_G2_SWREG11_SW_GREF_SIGN_BIAS_MASK    (0x4U)
#define VPU_G2_SWREG11_SW_GREF_SIGN_BIAS_SHIFT   (2U)
/*! SW_GREF_SIGN_BIAS - Golden reference picture sign bias used for motion vector decoding */
#define VPU_G2_SWREG11_SW_GREF_SIGN_BIAS(x)      (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG11_SW_GREF_SIGN_BIAS_SHIFT)) & VPU_G2_SWREG11_SW_GREF_SIGN_BIAS_MASK)

#define VPU_G2_SWREG11_SW_COMP_PRED_MODE_MASK    (0x30U)
#define VPU_G2_SWREG11_SW_COMP_PRED_MODE_SHIFT   (4U)
/*! SW_COMP_PRED_MODE - Prediction Comp Type
 *  0b00..Single prediction only
 *  0b01..COMP prediction only
 *  0b10..Hybrid prediction
 */
#define VPU_G2_SWREG11_SW_COMP_PRED_MODE(x)      (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG11_SW_COMP_PRED_MODE_SHIFT)) & VPU_G2_SWREG11_SW_COMP_PRED_MODE_MASK)

#define VPU_G2_SWREG11_SW_HIGH_PREC_MV_E_MASK    (0x80U)
#define VPU_G2_SWREG11_SW_HIGH_PREC_MV_E_SHIFT   (7U)
/*! SW_HIGH_PREC_MV_E - High precision MV prediction enable */
#define VPU_G2_SWREG11_SW_HIGH_PREC_MV_E(x)      (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG11_SW_HIGH_PREC_MV_E_SHIFT)) & VPU_G2_SWREG11_SW_HIGH_PREC_MV_E_MASK)

#define VPU_G2_SWREG11_SW_MCOMP_FILT_TYPE_MASK   (0x700U)
#define VPU_G2_SWREG11_SW_MCOMP_FILT_TYPE_SHIFT  (8U)
/*! SW_MCOMP_FILT_TYPE - Inter prediction filter type to stream decoder
 *  0b000..Eight tap smooth
 *  0b001..Eight tap
 *  0b010..Eight tap sharp
 *  0b011..Bilinear
 *  0b100..Switchable
 */
#define VPU_G2_SWREG11_SW_MCOMP_FILT_TYPE(x)     (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG11_SW_MCOMP_FILT_TYPE_SHIFT)) & VPU_G2_SWREG11_SW_MCOMP_FILT_TYPE_MASK)

#define VPU_G2_SWREG11_SW_FILT_TYPE_MASK         (0x80000U)
#define VPU_G2_SWREG11_SW_FILT_TYPE_SHIFT        (19U)
/*! SW_FILT_TYPE - Filter Type */
#define VPU_G2_SWREG11_SW_FILT_TYPE(x)           (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG11_SW_FILT_TYPE_SHIFT)) & VPU_G2_SWREG11_SW_FILT_TYPE_MASK)

#define VPU_G2_SWREG11_SW_FILT_SHARPNESS_MASK    (0xE00000U)
#define VPU_G2_SWREG11_SW_FILT_SHARPNESS_SHIFT   (21U)
/*! SW_FILT_SHARPNESS - Filter sharpness value */
#define VPU_G2_SWREG11_SW_FILT_SHARPNESS(x)      (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG11_SW_FILT_SHARPNESS_SHIFT)) & VPU_G2_SWREG11_SW_FILT_SHARPNESS_MASK)

#define VPU_G2_SWREG11_SW_TRANSFORM_MODE_MASK    (0x38000000U)
#define VPU_G2_SWREG11_SW_TRANSFORM_MODE_SHIFT   (27U)
/*! SW_TRANSFORM_MODE - Transform modes
 *  0b000..4x4 only
 *  0b001..Allow 8x8
 *  0b010..Allow 16x16
 *  0b011..Allow 32x32
 *  0b100..TX mode select
 */
#define VPU_G2_SWREG11_SW_TRANSFORM_MODE(x)      (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG11_SW_TRANSFORM_MODE_SHIFT)) & VPU_G2_SWREG11_SW_TRANSFORM_MODE_MASK)
/*! @} */

/*! @name SWREG12 - Decoder control register 9 */
/*! @{ */

#define VPU_G2_SWREG12_SW_REFPICLIST_MOD_E_MASK  (0x1U)
#define VPU_G2_SWREG12_SW_REFPICLIST_MOD_E_SHIFT (0U)
/*! SW_REFPICLIST_MOD_E - Refpic list reordering flag */
#define VPU_G2_SWREG12_SW_REFPICLIST_MOD_E(x)    (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG12_SW_REFPICLIST_MOD_E_SHIFT)) & VPU_G2_SWREG12_SW_REFPICLIST_MOD_E_MASK)

#define VPU_G2_SWREG12_SW_TRANSQ_BYPASS_E_MASK   (0x2U)
#define VPU_G2_SWREG12_SW_TRANSQ_BYPASS_E_SHIFT  (1U)
/*! SW_TRANSQ_BYPASS_E - Transform bypass flag (lossless mode) */
#define VPU_G2_SWREG12_SW_TRANSQ_BYPASS_E(x)     (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG12_SW_TRANSQ_BYPASS_E_SHIFT)) & VPU_G2_SWREG12_SW_TRANSQ_BYPASS_E_MASK)

#define VPU_G2_SWREG12_SW_TRANSFORM_SKIP_E_MASK  (0x4U)
#define VPU_G2_SWREG12_SW_TRANSFORM_SKIP_E_SHIFT (2U)
/*! SW_TRANSFORM_SKIP_E - Transform skipping flag */
#define VPU_G2_SWREG12_SW_TRANSFORM_SKIP_E(x)    (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG12_SW_TRANSFORM_SKIP_E_SHIFT)) & VPU_G2_SWREG12_SW_TRANSFORM_SKIP_E_MASK)

#define VPU_G2_SWREG12_SW_PCM_E_MASK             (0x8U)
#define VPU_G2_SWREG12_SW_PCM_E_SHIFT            (3U)
/*! SW_PCM_E - IPCM MBs flag */
#define VPU_G2_SWREG12_SW_PCM_E(x)               (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG12_SW_PCM_E_SHIFT)) & VPU_G2_SWREG12_SW_PCM_E_MASK)

#define VPU_G2_SWREG12_SW_MAX_PCM_SIZE_MASK      (0x70U)
#define VPU_G2_SWREG12_SW_MAX_PCM_SIZE_SHIFT     (4U)
/*! SW_MAX_PCM_SIZE - PCM max size (2^N):
 *  0b011..8 pix
 *  0b100..16 pix
 *  0b101..32 pix
 *  0b110..64 pix
 */
#define VPU_G2_SWREG12_SW_MAX_PCM_SIZE(x)        (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG12_SW_MAX_PCM_SIZE_SHIFT)) & VPU_G2_SWREG12_SW_MAX_PCM_SIZE_MASK)

#define VPU_G2_SWREG12_SW_MIN_PCM_SIZE_MASK      (0x380U)
#define VPU_G2_SWREG12_SW_MIN_PCM_SIZE_SHIFT     (7U)
/*! SW_MIN_PCM_SIZE - PCM min size (2^N):
 *  0b011..8 pix
 *  0b100..16 pix
 *  0b101..32 pix
 *  0b110..64 pix
 */
#define VPU_G2_SWREG12_SW_MIN_PCM_SIZE(x)        (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG12_SW_MIN_PCM_SIZE_SHIFT)) & VPU_G2_SWREG12_SW_MIN_PCM_SIZE_MASK)

#define VPU_G2_SWREG12_SW_MAX_CB_SIZE_MASK       (0x1C00U)
#define VPU_G2_SWREG12_SW_MAX_CB_SIZE_SHIFT      (10U)
/*! SW_MAX_CB_SIZE - CodedBlock max size (2^N):
 *  0b011..8 pix
 *  0b100..16 pix
 *  0b101..32 pix
 *  0b110..64 pix
 */
#define VPU_G2_SWREG12_SW_MAX_CB_SIZE(x)         (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG12_SW_MAX_CB_SIZE_SHIFT)) & VPU_G2_SWREG12_SW_MAX_CB_SIZE_MASK)

#define VPU_G2_SWREG12_SW_MIN_CB_SIZE_MASK       (0xE000U)
#define VPU_G2_SWREG12_SW_MIN_CB_SIZE_SHIFT      (13U)
/*! SW_MIN_CB_SIZE - CodedBlock min size (2^N):
 *  0b011..8 pix
 *  0b100..16 pix
 *  0b101..32 pix
 *  0b110..64 pix
 */
#define VPU_G2_SWREG12_SW_MIN_CB_SIZE(x)         (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG12_SW_MIN_CB_SIZE_SHIFT)) & VPU_G2_SWREG12_SW_MIN_CB_SIZE_MASK)

#define VPU_G2_SWREG12_SW_REFER_LTERM_E_MASK     (0xFFFF0000U)
#define VPU_G2_SWREG12_SW_REFER_LTERM_E_SHIFT    (16U)
/*! SW_REFER_LTERM_E - Long term flag for reference picture index Definition: Bit 31 for picture index 0 Bit 30 for picture index 1 etc. */
#define VPU_G2_SWREG12_SW_REFER_LTERM_E(x)       (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG12_SW_REFER_LTERM_E_SHIFT)) & VPU_G2_SWREG12_SW_REFER_LTERM_E_MASK)
/*! @} */

/*! @name SWREG13 - Decoder control register 10 */
/*! @{ */

#define VPU_G2_SWREG13_DEC_CTRL_REG10_BF_MASK    (0x1FFFFFFFU)
#define VPU_G2_SWREG13_DEC_CTRL_REG10_BF_SHIFT   (0U)
#define VPU_G2_SWREG13_DEC_CTRL_REG10_BF(x)      (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG13_DEC_CTRL_REG10_BF_SHIFT)) & VPU_G2_SWREG13_DEC_CTRL_REG10_BF_MASK)
/*! @} */

/*! @name SWREG14 - Initial ref pic list register (0-2) */
/*! @{ */

#define VPU_G2_SWREG14_INIT_REF_PIC_0_2_BF_MASK  (0xFFFFFFFFU)
#define VPU_G2_SWREG14_INIT_REF_PIC_0_2_BF_SHIFT (0U)
#define VPU_G2_SWREG14_INIT_REF_PIC_0_2_BF(x)    (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG14_INIT_REF_PIC_0_2_BF_SHIFT)) & VPU_G2_SWREG14_INIT_REF_PIC_0_2_BF_MASK)
/*! @} */

/*! @name SWREG15 - Initial ref pic list register (3-5) */
/*! @{ */

#define VPU_G2_SWREG15_INIT_REF_PIC_3_5_BF_MASK  (0xFFFFFFFFU)
#define VPU_G2_SWREG15_INIT_REF_PIC_3_5_BF_SHIFT (0U)
#define VPU_G2_SWREG15_INIT_REF_PIC_3_5_BF(x)    (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG15_INIT_REF_PIC_3_5_BF_SHIFT)) & VPU_G2_SWREG15_INIT_REF_PIC_3_5_BF_MASK)
/*! @} */

/*! @name SWREG16 - Initial ref pic list register (6-8) */
/*! @{ */

#define VPU_G2_SWREG16_INIT_REF_PIC_6_8_BF_MASK  (0xFFFFFFFFU)
#define VPU_G2_SWREG16_INIT_REF_PIC_6_8_BF_SHIFT (0U)
#define VPU_G2_SWREG16_INIT_REF_PIC_6_8_BF(x)    (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG16_INIT_REF_PIC_6_8_BF_SHIFT)) & VPU_G2_SWREG16_INIT_REF_PIC_6_8_BF_MASK)
/*! @} */

/*! @name SWREG17 - Initial ref pic list register (9-11) */
/*! @{ */

#define VPU_G2_SWREG17_INIT_REF_PIC_9_11_BF_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG17_INIT_REF_PIC_9_11_BF_SHIFT (0U)
#define VPU_G2_SWREG17_INIT_REF_PIC_9_11_BF(x)   (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG17_INIT_REF_PIC_9_11_BF_SHIFT)) & VPU_G2_SWREG17_INIT_REF_PIC_9_11_BF_MASK)
/*! @} */

/*! @name SWREG18 - Initial ref pic list register (12-14) */
/*! @{ */

#define VPU_G2_SWREG18_INIT_REF_PIC_12_14_BF_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG18_INIT_REF_PIC_12_14_BF_SHIFT (0U)
#define VPU_G2_SWREG18_INIT_REF_PIC_12_14_BF(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG18_INIT_REF_PIC_12_14_BF_SHIFT)) & VPU_G2_SWREG18_INIT_REF_PIC_12_14_BF_MASK)
/*! @} */

/*! @name SWREG19 - Initial ref pic list register (15 and P 0-3) */
/*! @{ */

#define VPU_G2_SWREG19_INIT_REF_PIC_15_BF_MASK   (0xFFFFFFFFU)
#define VPU_G2_SWREG19_INIT_REF_PIC_15_BF_SHIFT  (0U)
#define VPU_G2_SWREG19_INIT_REF_PIC_15_BF(x)     (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG19_INIT_REF_PIC_15_BF_SHIFT)) & VPU_G2_SWREG19_INIT_REF_PIC_15_BF_MASK)
/*! @} */

/*! @name SWREG20 - Decoder control register 11 */
/*! @{ */

#define VPU_G2_SWREG20_SW_PIC_HEIGHT_4X4_MASK    (0xFFFU)
#define VPU_G2_SWREG20_SW_PIC_HEIGHT_4X4_SHIFT   (0U)
/*! SW_PIC_HEIGHT_4X4 - Current picture height in 4x4 blocks (Needed to reduce overlapping HW conditions in various blocks) */
#define VPU_G2_SWREG20_SW_PIC_HEIGHT_4X4(x)      (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG20_SW_PIC_HEIGHT_4X4_SHIFT)) & VPU_G2_SWREG20_SW_PIC_HEIGHT_4X4_MASK)

#define VPU_G2_SWREG20_SW_PIC_WIDTH_4X4_MASK     (0xFFF0000U)
#define VPU_G2_SWREG20_SW_PIC_WIDTH_4X4_SHIFT    (16U)
/*! SW_PIC_WIDTH_4X4 - Current picture width in 4x4 blocks (Needed to reduce overlapping HW conditions in various blocks) */
#define VPU_G2_SWREG20_SW_PIC_WIDTH_4X4(x)       (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG20_SW_PIC_WIDTH_4X4_SHIFT)) & VPU_G2_SWREG20_SW_PIC_WIDTH_4X4_MASK)

#define VPU_G2_SWREG20_SW_PARTIAL_CTB_Y_MASK     (0x40000000U)
#define VPU_G2_SWREG20_SW_PARTIAL_CTB_Y_SHIFT    (30U)
/*! SW_PARTIAL_CTB_Y - Picture height not multiple of CTB size */
#define VPU_G2_SWREG20_SW_PARTIAL_CTB_Y(x)       (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG20_SW_PARTIAL_CTB_Y_SHIFT)) & VPU_G2_SWREG20_SW_PARTIAL_CTB_Y_MASK)

#define VPU_G2_SWREG20_SW_PARTIAL_CTB_X_MASK     (0x80000000U)
#define VPU_G2_SWREG20_SW_PARTIAL_CTB_X_SHIFT    (31U)
/*! SW_PARTIAL_CTB_X - Picture width not multiple of CTB size */
#define VPU_G2_SWREG20_SW_PARTIAL_CTB_X(x)       (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG20_SW_PARTIAL_CTB_X_SHIFT)) & VPU_G2_SWREG20_SW_PARTIAL_CTB_X_MASK)
/*! @} */

/*! @name SWREG23 - Decoder configure status register */
/*! @{ */

#define VPU_G2_SWREG23_SW_HEVC_SUPPORT_MASK      (0x1U)
#define VPU_G2_SWREG23_SW_HEVC_SUPPORT_SHIFT     (0U)
/*! SW_HEVC_SUPPORT - HEVC support
 *  0b0..Do not support HEVC
 *  0b1..Support HEVC
 */
#define VPU_G2_SWREG23_SW_HEVC_SUPPORT(x)        (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG23_SW_HEVC_SUPPORT_SHIFT)) & VPU_G2_SWREG23_SW_HEVC_SUPPORT_MASK)

#define VPU_G2_SWREG23_SW_VP9_SUPPORT_MASK       (0x2U)
#define VPU_G2_SWREG23_SW_VP9_SUPPORT_SHIFT      (1U)
/*! SW_VP9_SUPPORT - VP9 support
 *  0b0..Do not support VP9
 *  0b1..Support VP9
 */
#define VPU_G2_SWREG23_SW_VP9_SUPPORT(x)         (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG23_SW_VP9_SUPPORT_SHIFT)) & VPU_G2_SWREG23_SW_VP9_SUPPORT_MASK)

#define VPU_G2_SWREG23_SW_RFC_SUPPORT_MASK       (0x4U)
#define VPU_G2_SWREG23_SW_RFC_SUPPORT_SHIFT      (2U)
/*! SW_RFC_SUPPORT - RFC support
 *  0b0..Do not support RFC
 *  0b1..Support RFC
 */
#define VPU_G2_SWREG23_SW_RFC_SUPPORT(x)         (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG23_SW_RFC_SUPPORT_SHIFT)) & VPU_G2_SWREG23_SW_RFC_SUPPORT_MASK)

#define VPU_G2_SWREG23_SW_DOWN_SUPPORT_MASK      (0x8U)
#define VPU_G2_SWREG23_SW_DOWN_SUPPORT_SHIFT     (3U)
/*! SW_DOWN_SUPPORT - Downscale support
 *  0b0..Do not support downscale
 *  0b1..Support downscale
 */
#define VPU_G2_SWREG23_SW_DOWN_SUPPORT(x)        (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG23_SW_DOWN_SUPPORT_SHIFT)) & VPU_G2_SWREG23_SW_DOWN_SUPPORT_MASK)

#define VPU_G2_SWREG23_SW_DEC_64BIT_AD_E_MASK    (0x10U)
#define VPU_G2_SWREG23_SW_DEC_64BIT_AD_E_SHIFT   (4U)
/*! SW_DEC_64BIT_AD_E - 64 bit addressing of master interface support
 *  0b0..Not supported (32 bit addressing)
 *  0b1..Supported
 */
#define VPU_G2_SWREG23_SW_DEC_64BIT_AD_E(x)      (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG23_SW_DEC_64BIT_AD_E_SHIFT)) & VPU_G2_SWREG23_SW_DEC_64BIT_AD_E_MASK)

#define VPU_G2_SWREG23_SW_DEC_FORMAT_P010_E_MASK (0x20U)
#define VPU_G2_SWREG23_SW_DEC_FORMAT_P010_E_SHIFT (5U)
/*! SW_DEC_FORMAT_P010_E - P010 output format support
 *  0b0..Not supported
 *  0b1..Supported
 */
#define VPU_G2_SWREG23_SW_DEC_FORMAT_P010_E(x)   (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG23_SW_DEC_FORMAT_P010_E_SHIFT)) & VPU_G2_SWREG23_SW_DEC_FORMAT_P010_E_MASK)

#define VPU_G2_SWREG23_SW_DEC_FORMAT_CUSTOMER1_E_MASK (0x40U)
#define VPU_G2_SWREG23_SW_DEC_FORMAT_CUSTOMER1_E_SHIFT (6U)
/*! SW_DEC_FORMAT_CUSTOMER1_E - Customized output format support
 *  0b0..Not supported
 *  0b1..Supported
 */
#define VPU_G2_SWREG23_SW_DEC_FORMAT_CUSTOMER1_E(x) (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG23_SW_DEC_FORMAT_CUSTOMER1_E_SHIFT)) & VPU_G2_SWREG23_SW_DEC_FORMAT_CUSTOMER1_E_MASK)

#define VPU_G2_SWREG23_SW_MULTI_PREFETCH_MASK    (0x80U)
#define VPU_G2_SWREG23_SW_MULTI_PREFETCH_SHIFT   (7U)
/*! SW_MULTI_PREFETCH - Multi-Reference Blocks Prefetch
 *  0b0..Not supported
 *  0b1..Supported
 */
#define VPU_G2_SWREG23_SW_MULTI_PREFETCH(x)      (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG23_SW_MULTI_PREFETCH_SHIFT)) & VPU_G2_SWREG23_SW_MULTI_PREFETCH_MASK)

#define VPU_G2_SWREG23_SW_HEVC_VERSION_MASK      (0xF00U)
#define VPU_G2_SWREG23_SW_HEVC_VERSION_SHIFT     (8U)
/*! SW_HEVC_VERSION - HEVC version
 *  0b0000..main8
 *  0b0001..main10
 */
#define VPU_G2_SWREG23_SW_HEVC_VERSION(x)        (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG23_SW_HEVC_VERSION_SHIFT)) & VPU_G2_SWREG23_SW_HEVC_VERSION_MASK)

#define VPU_G2_SWREG23_SW_VP9_PROFILE_MASK       (0xF000U)
#define VPU_G2_SWREG23_SW_VP9_PROFILE_SHIFT      (12U)
/*! SW_VP9_PROFILE - VP9 version
 *  0b0000..vp9 profile 0
 *  0b0001..vp9 profile 2 - 10bits
 */
#define VPU_G2_SWREG23_SW_VP9_PROFILE(x)         (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG23_SW_VP9_PROFILE_SHIFT)) & VPU_G2_SWREG23_SW_VP9_PROFILE_MASK)
/*! @} */

/*! @name SWREG31 - VP9 segmentation values */
/*! @{ */

#define VPU_G2_SWREG31_SW_QUANT_SEG6_MASK        (0xFFU)
#define VPU_G2_SWREG31_SW_QUANT_SEG6_SHIFT       (0U)
/*! SW_QUANT_SEG6 - Segment quantization parameter */
#define VPU_G2_SWREG31_SW_QUANT_SEG6(x)          (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG31_SW_QUANT_SEG6_SHIFT)) & VPU_G2_SWREG31_SW_QUANT_SEG6_MASK)

#define VPU_G2_SWREG31_SW_FILT_LEVEL_SEG6_MASK   (0x3F00U)
#define VPU_G2_SWREG31_SW_FILT_LEVEL_SEG6_SHIFT  (8U)
/*! SW_FILT_LEVEL_SEG6 - Segment filter level */
#define VPU_G2_SWREG31_SW_FILT_LEVEL_SEG6(x)     (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG31_SW_FILT_LEVEL_SEG6_SHIFT)) & VPU_G2_SWREG31_SW_FILT_LEVEL_SEG6_MASK)

#define VPU_G2_SWREG31_SW_SKIP_SEG6_MASK         (0x4000U)
#define VPU_G2_SWREG31_SW_SKIP_SEG6_SHIFT        (14U)
/*! SW_SKIP_SEG6 - Segment skip enable */
#define VPU_G2_SWREG31_SW_SKIP_SEG6(x)           (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG31_SW_SKIP_SEG6_SHIFT)) & VPU_G2_SWREG31_SW_SKIP_SEG6_MASK)

#define VPU_G2_SWREG31_SW_REFPIC_SEG6_MASK       (0x38000U)
#define VPU_G2_SWREG31_SW_REFPIC_SEG6_SHIFT      (15U)
/*! SW_REFPIC_SEG6 - Segment refer picture */
#define VPU_G2_SWREG31_SW_REFPIC_SEG6(x)         (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG31_SW_REFPIC_SEG6_SHIFT)) & VPU_G2_SWREG31_SW_REFPIC_SEG6_MASK)
/*! @} */

/*! @name SWREG32 - VP9 segmentation values */
/*! @{ */

#define VPU_G2_SWREG32_SW_QUANT_SEG7_MASK        (0xFFU)
#define VPU_G2_SWREG32_SW_QUANT_SEG7_SHIFT       (0U)
/*! SW_QUANT_SEG7 - Segment quantization parameter */
#define VPU_G2_SWREG32_SW_QUANT_SEG7(x)          (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG32_SW_QUANT_SEG7_SHIFT)) & VPU_G2_SWREG32_SW_QUANT_SEG7_MASK)

#define VPU_G2_SWREG32_SW_FILT_LEVEL_SEG7_MASK   (0x3F00U)
#define VPU_G2_SWREG32_SW_FILT_LEVEL_SEG7_SHIFT  (8U)
/*! SW_FILT_LEVEL_SEG7 - Segment filter level */
#define VPU_G2_SWREG32_SW_FILT_LEVEL_SEG7(x)     (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG32_SW_FILT_LEVEL_SEG7_SHIFT)) & VPU_G2_SWREG32_SW_FILT_LEVEL_SEG7_MASK)

#define VPU_G2_SWREG32_SW_SKIP_SEG7_MASK         (0x4000U)
#define VPU_G2_SWREG32_SW_SKIP_SEG7_SHIFT        (14U)
/*! SW_SKIP_SEG7 - Segment skip enable */
#define VPU_G2_SWREG32_SW_SKIP_SEG7(x)           (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG32_SW_SKIP_SEG7_SHIFT)) & VPU_G2_SWREG32_SW_SKIP_SEG7_MASK)

#define VPU_G2_SWREG32_SW_REFPIC_SEG7_MASK       (0x38000U)
#define VPU_G2_SWREG32_SW_REFPIC_SEG7_SHIFT      (15U)
/*! SW_REFPIC_SEG7 - Segment refer picture */
#define VPU_G2_SWREG32_SW_REFPIC_SEG7(x)         (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG32_SW_REFPIC_SEG7_SHIFT)) & VPU_G2_SWREG32_SW_REFPIC_SEG7_MASK)
/*! @} */

/*! @name SWREG33 - VP9 reference picture scaling register 0 */
/*! @{ */

#define VPU_G2_SWREG33_SW_LREF_HEIGHT_MASK       (0xFFFFU)
#define VPU_G2_SWREG33_SW_LREF_HEIGHT_SHIFT      (0U)
/*! SW_LREF_HEIGHT - Accurate height of last (previous) reference picture in pixels */
#define VPU_G2_SWREG33_SW_LREF_HEIGHT(x)         (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG33_SW_LREF_HEIGHT_SHIFT)) & VPU_G2_SWREG33_SW_LREF_HEIGHT_MASK)

#define VPU_G2_SWREG33_SW_LREF_WIDTH_MASK        (0xFFFF0000U)
#define VPU_G2_SWREG33_SW_LREF_WIDTH_SHIFT       (16U)
/*! SW_LREF_WIDTH - Accurate width of last (previous) reference picture in pixels */
#define VPU_G2_SWREG33_SW_LREF_WIDTH(x)          (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG33_SW_LREF_WIDTH_SHIFT)) & VPU_G2_SWREG33_SW_LREF_WIDTH_MASK)
/*! @} */

/*! @name SWREG34 - VP9 reference picture scaling register 1 */
/*! @{ */

#define VPU_G2_SWREG34_SW_GREF_HEIGHT_MASK       (0xFFFFU)
#define VPU_G2_SWREG34_SW_GREF_HEIGHT_SHIFT      (0U)
/*! SW_GREF_HEIGHT - Accurate height of golden reference picture in pixels */
#define VPU_G2_SWREG34_SW_GREF_HEIGHT(x)         (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG34_SW_GREF_HEIGHT_SHIFT)) & VPU_G2_SWREG34_SW_GREF_HEIGHT_MASK)

#define VPU_G2_SWREG34_SW_GREF_WIDTH_MASK        (0xFFFF0000U)
#define VPU_G2_SWREG34_SW_GREF_WIDTH_SHIFT       (16U)
/*! SW_GREF_WIDTH - Accurate width of golden reference picture in pixels */
#define VPU_G2_SWREG34_SW_GREF_WIDTH(x)          (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG34_SW_GREF_WIDTH_SHIFT)) & VPU_G2_SWREG34_SW_GREF_WIDTH_MASK)
/*! @} */

/*! @name SWREG35 - VP9 reference picture scaling register 2 */
/*! @{ */

#define VPU_G2_SWREG35_SW_AREF_HEIGHT_MASK       (0xFFFFU)
#define VPU_G2_SWREG35_SW_AREF_HEIGHT_SHIFT      (0U)
/*! SW_AREF_HEIGHT - Accurate height of alternate reference picture in pixels */
#define VPU_G2_SWREG35_SW_AREF_HEIGHT(x)         (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG35_SW_AREF_HEIGHT_SHIFT)) & VPU_G2_SWREG35_SW_AREF_HEIGHT_MASK)

#define VPU_G2_SWREG35_SW_AREF_WIDTH_MASK        (0xFFFF0000U)
#define VPU_G2_SWREG35_SW_AREF_WIDTH_SHIFT       (16U)
/*! SW_AREF_WIDTH - Accurate width of alternate reference picture in pixels */
#define VPU_G2_SWREG35_SW_AREF_WIDTH(x)          (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG35_SW_AREF_WIDTH_SHIFT)) & VPU_G2_SWREG35_SW_AREF_WIDTH_MASK)
/*! @} */

/*! @name SWREG36 - VP9 reference picture scaling register 3 */
/*! @{ */

#define VPU_G2_SWREG36_SW_LREF_VER_SCALE_MASK    (0xFFFFU)
#define VPU_G2_SWREG36_SW_LREF_VER_SCALE_SHIFT   (0U)
/*! SW_LREF_VER_SCALE - Vertical scaling factor for last (previous) reference picture */
#define VPU_G2_SWREG36_SW_LREF_VER_SCALE(x)      (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG36_SW_LREF_VER_SCALE_SHIFT)) & VPU_G2_SWREG36_SW_LREF_VER_SCALE_MASK)

#define VPU_G2_SWREG36_SW_LREF_HOR_SCALE_MASK    (0xFFFF0000U)
#define VPU_G2_SWREG36_SW_LREF_HOR_SCALE_SHIFT   (16U)
/*! SW_LREF_HOR_SCALE - Horizontal scaling factor for last (previous) reference picture */
#define VPU_G2_SWREG36_SW_LREF_HOR_SCALE(x)      (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG36_SW_LREF_HOR_SCALE_SHIFT)) & VPU_G2_SWREG36_SW_LREF_HOR_SCALE_MASK)
/*! @} */

/*! @name SWREG37 - VP9 reference picture scaling register 4 */
/*! @{ */

#define VPU_G2_SWREG37_SW_GREF_VER_SCALE_MASK    (0xFFFFU)
#define VPU_G2_SWREG37_SW_GREF_VER_SCALE_SHIFT   (0U)
/*! SW_GREF_VER_SCALE - Vertical scaling factor for golden reference picture */
#define VPU_G2_SWREG37_SW_GREF_VER_SCALE(x)      (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG37_SW_GREF_VER_SCALE_SHIFT)) & VPU_G2_SWREG37_SW_GREF_VER_SCALE_MASK)

#define VPU_G2_SWREG37_SW_GREF_HOR_SCALE_MASK    (0xFFFF0000U)
#define VPU_G2_SWREG37_SW_GREF_HOR_SCALE_SHIFT   (16U)
/*! SW_GREF_HOR_SCALE - Horizontal scaling factor for golden reference picture */
#define VPU_G2_SWREG37_SW_GREF_HOR_SCALE(x)      (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG37_SW_GREF_HOR_SCALE_SHIFT)) & VPU_G2_SWREG37_SW_GREF_HOR_SCALE_MASK)
/*! @} */

/*! @name SWREG38 - VP9 reference picture scaling register 5 */
/*! @{ */

#define VPU_G2_SWREG38_SW_AREF_VER_SCALE_MASK    (0xFFFFU)
#define VPU_G2_SWREG38_SW_AREF_VER_SCALE_SHIFT   (0U)
/*! SW_AREF_VER_SCALE - Vertical scaling factor for alternate reference picture */
#define VPU_G2_SWREG38_SW_AREF_VER_SCALE(x)      (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG38_SW_AREF_VER_SCALE_SHIFT)) & VPU_G2_SWREG38_SW_AREF_VER_SCALE_MASK)

#define VPU_G2_SWREG38_SW_AREF_HOR_SCALE_MASK    (0xFFFF0000U)
#define VPU_G2_SWREG38_SW_AREF_HOR_SCALE_SHIFT   (16U)
/*! SW_AREF_HOR_SCALE - Horizontal scaling factor for alternate reference picture */
#define VPU_G2_SWREG38_SW_AREF_HOR_SCALE(x)      (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG38_SW_AREF_HOR_SCALE_SHIFT)) & VPU_G2_SWREG38_SW_AREF_HOR_SCALE_MASK)
/*! @} */

/*! @name SWREG45 - Timeout control register */
/*! @{ */

#define VPU_G2_SWREG45_SW_TIMEOUT_CYCLES_MASK    (0x7FFFFFFFU)
#define VPU_G2_SWREG45_SW_TIMEOUT_CYCLES_SHIFT   (0U)
/*! SW_TIMEOUT_CYCLES - Amount of clock cycles to trigger timeout interrupt if no external master
 *    activity acknowledged. Used if sw_timeout_override_e is set
 */
#define VPU_G2_SWREG45_SW_TIMEOUT_CYCLES(x)      (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG45_SW_TIMEOUT_CYCLES_SHIFT)) & VPU_G2_SWREG45_SW_TIMEOUT_CYCLES_MASK)

#define VPU_G2_SWREG45_SW_TIMEOUT_OVERRIDE_E_MASK (0x80000000U)
#define VPU_G2_SWREG45_SW_TIMEOUT_OVERRIDE_E_SHIFT (31U)
/*! SW_TIMEOUT_OVERRIDE_E - Enable for SW controlled timeout. If enabled the sw_timeout_cycles is
 *    used to detect HW timeout instead of hard coded HW value
 */
#define VPU_G2_SWREG45_SW_TIMEOUT_OVERRIDE_E(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG45_SW_TIMEOUT_OVERRIDE_E_SHIFT)) & VPU_G2_SWREG45_SW_TIMEOUT_OVERRIDE_E_MASK)
/*! @} */

/*! @name SWREG46 - Picture order count from current pictures for index 0-3 */
/*! @{ */

#define VPU_G2_SWREG46_PIC_ORD_0_3_BF_MASK       (0xFFFFFFFFU)
#define VPU_G2_SWREG46_PIC_ORD_0_3_BF_SHIFT      (0U)
#define VPU_G2_SWREG46_PIC_ORD_0_3_BF(x)         (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG46_PIC_ORD_0_3_BF_SHIFT)) & VPU_G2_SWREG46_PIC_ORD_0_3_BF_MASK)
/*! @} */

/*! @name SWREG47 - Picture order count from current pictures for index 4-7 */
/*! @{ */

#define VPU_G2_SWREG47_PIC_ORD_4_7_BF_MASK       (0xFFFFFFFFU)
#define VPU_G2_SWREG47_PIC_ORD_4_7_BF_SHIFT      (0U)
#define VPU_G2_SWREG47_PIC_ORD_4_7_BF(x)         (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG47_PIC_ORD_4_7_BF_SHIFT)) & VPU_G2_SWREG47_PIC_ORD_4_7_BF_MASK)
/*! @} */

/*! @name SWREG48 - Picture order count from current pictures for index 8-11 */
/*! @{ */

#define VPU_G2_SWREG48_SW_CUR_POC_11_MASK        (0xFFU)
#define VPU_G2_SWREG48_SW_CUR_POC_11_SHIFT       (0U)
/*! SW_CUR_POC_11 - Picture order count from current picture 11 */
#define VPU_G2_SWREG48_SW_CUR_POC_11(x)          (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG48_SW_CUR_POC_11_SHIFT)) & VPU_G2_SWREG48_SW_CUR_POC_11_MASK)

#define VPU_G2_SWREG48_SW_CUR_POC_10_MASK        (0xFF00U)
#define VPU_G2_SWREG48_SW_CUR_POC_10_SHIFT       (8U)
/*! SW_CUR_POC_10 - Picture order count from current picture 10 */
#define VPU_G2_SWREG48_SW_CUR_POC_10(x)          (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG48_SW_CUR_POC_10_SHIFT)) & VPU_G2_SWREG48_SW_CUR_POC_10_MASK)

#define VPU_G2_SWREG48_SW_CUR_POC_09_MASK        (0xFF0000U)
#define VPU_G2_SWREG48_SW_CUR_POC_09_SHIFT       (16U)
/*! SW_CUR_POC_09 - Picture order count from current picture 9 */
#define VPU_G2_SWREG48_SW_CUR_POC_09(x)          (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG48_SW_CUR_POC_09_SHIFT)) & VPU_G2_SWREG48_SW_CUR_POC_09_MASK)

#define VPU_G2_SWREG48_SW_CUR_POC_08_MASK        (0xFF000000U)
#define VPU_G2_SWREG48_SW_CUR_POC_08_SHIFT       (24U)
/*! SW_CUR_POC_08 - Picture order count from current picture 8 */
#define VPU_G2_SWREG48_SW_CUR_POC_08(x)          (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG48_SW_CUR_POC_08_SHIFT)) & VPU_G2_SWREG48_SW_CUR_POC_08_MASK)
/*! @} */

/*! @name SWREG49 - Picture order count from current pictures for index 12-15 */
/*! @{ */

#define VPU_G2_SWREG49_SW_CUR_POC_15_MASK        (0xFFU)
#define VPU_G2_SWREG49_SW_CUR_POC_15_SHIFT       (0U)
/*! SW_CUR_POC_15 - Picture order count from current picture 15 */
#define VPU_G2_SWREG49_SW_CUR_POC_15(x)          (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG49_SW_CUR_POC_15_SHIFT)) & VPU_G2_SWREG49_SW_CUR_POC_15_MASK)

#define VPU_G2_SWREG49_SW_CUR_POC_14_MASK        (0xFF00U)
#define VPU_G2_SWREG49_SW_CUR_POC_14_SHIFT       (8U)
/*! SW_CUR_POC_14 - Picture order count from current picture 14 */
#define VPU_G2_SWREG49_SW_CUR_POC_14(x)          (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG49_SW_CUR_POC_14_SHIFT)) & VPU_G2_SWREG49_SW_CUR_POC_14_MASK)

#define VPU_G2_SWREG49_SW_CUR_POC_13_MASK        (0xFF0000U)
#define VPU_G2_SWREG49_SW_CUR_POC_13_SHIFT       (16U)
/*! SW_CUR_POC_13 - Picture order count from current picture 13 */
#define VPU_G2_SWREG49_SW_CUR_POC_13(x)          (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG49_SW_CUR_POC_13_SHIFT)) & VPU_G2_SWREG49_SW_CUR_POC_13_MASK)

#define VPU_G2_SWREG49_SW_CUR_POC_12_MASK        (0xFF000000U)
#define VPU_G2_SWREG49_SW_CUR_POC_12_SHIFT       (24U)
/*! SW_CUR_POC_12 - Picture order count from current picture 12 */
#define VPU_G2_SWREG49_SW_CUR_POC_12(x)          (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG49_SW_CUR_POC_12_SHIFT)) & VPU_G2_SWREG49_SW_CUR_POC_12_MASK)
/*! @} */

/*! @name SWREG50 - Synthesis configuration register decoder 0 (read only) */
/*! @{ */

#define VPU_G2_SWREG50_SW_DEC_MAX_OWIDTH_MASK    (0x7FFU)
#define VPU_G2_SWREG50_SW_DEC_MAX_OWIDTH_SHIFT   (0U)
/*! SW_DEC_MAX_OWIDTH - Max configured decoder video resolution that can be decoded. Informed as width of the picture in pixels */
#define VPU_G2_SWREG50_SW_DEC_MAX_OWIDTH(x)      (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG50_SW_DEC_MAX_OWIDTH_SHIFT)) & VPU_G2_SWREG50_SW_DEC_MAX_OWIDTH_MASK)
/*! @} */

/*! @name SWREG54 - Synthesis configuration register decoder 1 (read only) */
/*! @{ */

#define VPU_G2_SWREG54_SW_DEC_MAX_OW_EXT_MASK    (0xC000U)
#define VPU_G2_SWREG54_SW_DEC_MAX_OW_EXT_SHIFT   (14U)
/*! SW_DEC_MAX_OW_EXT - Max configured decoder video resolution that can be decoded. This is the MSB part of the configuration signal */
#define VPU_G2_SWREG54_SW_DEC_MAX_OW_EXT(x)      (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG54_SW_DEC_MAX_OW_EXT_SHIFT)) & VPU_G2_SWREG54_SW_DEC_MAX_OW_EXT_MASK)
/*! @} */

/*! @name SWREG55 - Advanced prefetch control register */
/*! @{ */

#define VPU_G2_SWREG55_SW_APF_THRESHOLD_MASK     (0xFFFFU)
#define VPU_G2_SWREG55_SW_APF_THRESHOLD_SHIFT    (0U)
/*! SW_APF_THRESHOLD - Advanced prefetch threshold. If current buffered unit exceeds the threshold
 *    the advanced mode is not used. Value 0 disables threshold usage and advanced prefetch usage is
 *    restricted by internal memory limitation only
 */
#define VPU_G2_SWREG55_SW_APF_THRESHOLD(x)       (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG55_SW_APF_THRESHOLD_SHIFT)) & VPU_G2_SWREG55_SW_APF_THRESHOLD_MASK)

#define VPU_G2_SWREG55_SW_APF_SINGLE_PU_MODE_MASK (0x40000000U)
#define VPU_G2_SWREG55_SW_APF_SINGLE_PU_MODE_SHIFT (30U)
/*! SW_APF_SINGLE_PU_MODE - APF amount of buffered Pus: can be restricted to buffer one PU at a time */
#define VPU_G2_SWREG55_SW_APF_SINGLE_PU_MODE(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG55_SW_APF_SINGLE_PU_MODE_SHIFT)) & VPU_G2_SWREG55_SW_APF_SINGLE_PU_MODE_MASK)

#define VPU_G2_SWREG55_SW_APF_DISABLE_MASK       (0x80000000U)
#define VPU_G2_SWREG55_SW_APF_DISABLE_SHIFT      (31U)
/*! SW_APF_DISABLE - Advanced prefetch disable. If hight each partition is read separately */
#define VPU_G2_SWREG55_SW_APF_DISABLE(x)         (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG55_SW_APF_DISABLE_SHIFT)) & VPU_G2_SWREG55_SW_APF_DISABLE_MASK)
/*! @} */

/*! @name SWREG56 - Synthesis configuration register decoder 2 (read only) */
/*! @{ */

#define VPU_G2_SWREG56_SW_DEC_MAX_OHEIGHT_MASK   (0x1FFFU)
#define VPU_G2_SWREG56_SW_DEC_MAX_OHEIGHT_SHIFT  (0U)
/*! SW_DEC_MAX_OHEIGHT - Max supported picture height in pixels */
#define VPU_G2_SWREG56_SW_DEC_MAX_OHEIGHT(x)     (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG56_SW_DEC_MAX_OHEIGHT_SHIFT)) & VPU_G2_SWREG56_SW_DEC_MAX_OHEIGHT_MASK)
/*! @} */

/*! @name SWREG58 - Device configuration register decoder 2 + Multi core control register */
/*! @{ */

#define VPU_G2_SWREG58_SW_DEC_MAX_BURST_MASK     (0xFFU)
#define VPU_G2_SWREG58_SW_DEC_MAX_BURST_SHIFT    (0U)
/*! SW_DEC_MAX_BURST - Maximum burst length for decoder bus transactions. Valid values: AXI: 1-256 */
#define VPU_G2_SWREG58_SW_DEC_MAX_BURST(x)       (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG58_SW_DEC_MAX_BURST_SHIFT)) & VPU_G2_SWREG58_SW_DEC_MAX_BURST_MASK)

#define VPU_G2_SWREG58_SW_DEC_BUSWIDTH_MASK      (0x700U)
#define VPU_G2_SWREG58_SW_DEC_BUSWIDTH_SHIFT     (8U)
/*! SW_DEC_BUSWIDTH - Decoder master interface buswidth
 *  0b000..32 bit bus
 *  0b001..64 bit bus
 *  0b010..128 bit bus
 */
#define VPU_G2_SWREG58_SW_DEC_BUSWIDTH(x)        (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG58_SW_DEC_BUSWIDTH_SHIFT)) & VPU_G2_SWREG58_SW_DEC_BUSWIDTH_MASK)

#define VPU_G2_SWREG58_SW_DEC_AXI_WD_ID_E_MASK   (0x2000U)
#define VPU_G2_SWREG58_SW_DEC_AXI_WD_ID_E_SHIFT  (13U)
/*! SW_DEC_AXI_WD_ID_E - SW axi ID enable. When enabled the given sw_dec_axi_wd_id is used as ID base and each sub-block will use offsets 0...max */
#define VPU_G2_SWREG58_SW_DEC_AXI_WD_ID_E(x)     (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG58_SW_DEC_AXI_WD_ID_E_SHIFT)) & VPU_G2_SWREG58_SW_DEC_AXI_WD_ID_E_MASK)

#define VPU_G2_SWREG58_SW_DEC_AXI_RD_ID_E_MASK   (0x4000U)
#define VPU_G2_SWREG58_SW_DEC_AXI_RD_ID_E_SHIFT  (14U)
/*! SW_DEC_AXI_RD_ID_E - SW axi ID enable. When enabled the given sw_dec_axi_rd_id is used as ID base and each sub-block will use offsets 0...max */
#define VPU_G2_SWREG58_SW_DEC_AXI_RD_ID_E(x)     (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG58_SW_DEC_AXI_RD_ID_E_SHIFT)) & VPU_G2_SWREG58_SW_DEC_AXI_RD_ID_E_MASK)

#define VPU_G2_SWREG58_SW_DEC_REFER_DOUBLEBUFFER_E_MASK (0x8000U)
#define VPU_G2_SWREG58_SW_DEC_REFER_DOUBLEBUFFER_E_SHIFT (15U)
/*! SW_DEC_REFER_DOUBLEBUFFER_E - HW internal double buffering enable for reference data. This
 *    enable requires that there are two buffers available at the configured decoder (see configuration
 *    register values)
 */
#define VPU_G2_SWREG58_SW_DEC_REFER_DOUBLEBUFFER_E(x) (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG58_SW_DEC_REFER_DOUBLEBUFFER_E_SHIFT)) & VPU_G2_SWREG58_SW_DEC_REFER_DOUBLEBUFFER_E_MASK)

#define VPU_G2_SWREG58_SW_DEC_CLK_GATE_E_MASK    (0x10000U)
#define VPU_G2_SWREG58_SW_DEC_CLK_GATE_E_SHIFT   (16U)
/*! SW_DEC_CLK_GATE_E - Clock gating enable for picture-wise/decoding format clock gating. Between
 *    each picture the clock is gated from HW if this bit is high
 */
#define VPU_G2_SWREG58_SW_DEC_CLK_GATE_E(x)      (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG58_SW_DEC_CLK_GATE_E_SHIFT)) & VPU_G2_SWREG58_SW_DEC_CLK_GATE_E_MASK)

#define VPU_G2_SWREG58_SW_DEC_CLK_GATE_IDLE_E_MASK (0x20000U)
#define VPU_G2_SWREG58_SW_DEC_CLK_GATE_IDLE_E_SHIFT (17U)
/*! SW_DEC_CLK_GATE_IDLE_E - Clock gating enable for decoder run-time. Generated separate clocks for each block by its own IDLE signal. */
#define VPU_G2_SWREG58_SW_DEC_CLK_GATE_IDLE_E(x) (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG58_SW_DEC_CLK_GATE_IDLE_E_SHIFT)) & VPU_G2_SWREG58_SW_DEC_CLK_GATE_IDLE_E_MASK)
/*! @} */

/*! @name SWREG59 - Device configuration register AXI ID */
/*! @{ */

#define VPU_G2_SWREG59_SW_DEC_AXI_RD_ID_MASK     (0xFFFFU)
#define VPU_G2_SWREG59_SW_DEC_AXI_RD_ID_SHIFT    (0U)
/*! SW_DEC_AXI_RD_ID - Write ID base for HW write accesses. Each writing device use AXI ID of
 *    base+deviceoffset (where device offset is 0 1 2 3...Number of writing sub-blocks)
 */
#define VPU_G2_SWREG59_SW_DEC_AXI_RD_ID(x)       (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG59_SW_DEC_AXI_RD_ID_SHIFT)) & VPU_G2_SWREG59_SW_DEC_AXI_RD_ID_MASK)

#define VPU_G2_SWREG59_SW_DEC_AXI_WR_ID_MASK     (0xFFFF0000U)
#define VPU_G2_SWREG59_SW_DEC_AXI_WR_ID_SHIFT    (16U)
/*! SW_DEC_AXI_WR_ID - Read ID base for HW write accesses. Each writing device use AXI ID of
 *    base+deviceoffset (where device offset is 0 1 2 3...Number of reading sub-blocks)
 */
#define VPU_G2_SWREG59_SW_DEC_AXI_WR_ID(x)       (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG59_SW_DEC_AXI_WR_ID_SHIFT)) & VPU_G2_SWREG59_SW_DEC_AXI_WR_ID_MASK)
/*! @} */

/*! @name SWREG60 - Synthesis configuration register decoder 3 for PP (read only) */
/*! @{ */

#define VPU_G2_SWREG60_SW_DEC_PP_RS_E_MASK       (0x40000000U)
#define VPU_G2_SWREG60_SW_DEC_PP_RS_E_SHIFT      (30U)
/*! SW_DEC_PP_RS_E - Decoder PP raster scan output support
 *  0b0..Raster scan output not supported
 *  0b1..Raster scan output supported
 */
#define VPU_G2_SWREG60_SW_DEC_PP_RS_E(x)         (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG60_SW_DEC_PP_RS_E_SHIFT)) & VPU_G2_SWREG60_SW_DEC_PP_RS_E_MASK)

#define VPU_G2_SWREG60_SW_DEC_PP_E_MASK          (0x80000000U)
#define VPU_G2_SWREG60_SW_DEC_PP_E_SHIFT         (31U)
/*! SW_DEC_PP_E - Decoder include PP
 *  0b0..PP does not exist. None of the PP features can be enabled.
 *  0b1..PP exists
 */
#define VPU_G2_SWREG60_SW_DEC_PP_E(x)            (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG60_SW_DEC_PP_E_SHIFT)) & VPU_G2_SWREG60_SW_DEC_PP_E_MASK)
/*! @} */

/*! @name SWREG62 - HW proceed register (CU location) */
/*! @{ */

#define VPU_G2_SWREG62_SW_CU_LOCATION_Y_MASK     (0xFFFFU)
#define VPU_G2_SWREG62_SW_CU_LOCATION_Y_SHIFT    (0U)
/*! SW_CU_LOCATION_Y - Cu vertical start location Y in pixels (returned HW internal position during interrupt) */
#define VPU_G2_SWREG62_SW_CU_LOCATION_Y(x)       (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG62_SW_CU_LOCATION_Y_SHIFT)) & VPU_G2_SWREG62_SW_CU_LOCATION_Y_MASK)

#define VPU_G2_SWREG62_SW_CU_LOCATION_X_MASK     (0xFFFF0000U)
#define VPU_G2_SWREG62_SW_CU_LOCATION_X_SHIFT    (16U)
/*! SW_CU_LOCATION_X - Cu horizontal start location X in pixels (returned HW internal position during interrupt) */
#define VPU_G2_SWREG62_SW_CU_LOCATION_X(x)       (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG62_SW_CU_LOCATION_X_SHIFT)) & VPU_G2_SWREG62_SW_CU_LOCATION_X_MASK)
/*! @} */

/*! @name SWREG63 - HW performance register (cycles running) */
/*! @{ */

#define VPU_G2_SWREG63_SW_PERF_CYCLE_COUNT_MASK  (0xFFFFFFFFU)
#define VPU_G2_SWREG63_SW_PERF_CYCLE_COUNT_SHIFT (0U)
/*! SW_PERF_CYCLE_COUNT - HW clock cycle counter return value. Amount of consumed clock cycles
 *    returned to this register when interrupt is being made (any kind of interrupt)
 */
#define VPU_G2_SWREG63_SW_PERF_CYCLE_COUNT(x)    (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG63_SW_PERF_CYCLE_COUNT_SHIFT)) & VPU_G2_SWREG63_SW_PERF_CYCLE_COUNT_MASK)
/*! @} */

/*! @name SWREG64 - Base address MSB (bits 63:32) for decoded luminance picture */
/*! @{ */

#define VPU_G2_SWREG64_SW_DEC_OUT_YBASE_MSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG64_SW_DEC_OUT_YBASE_MSB_SHIFT (0U)
/*! SW_DEC_OUT_YBASE_MSB - Base address MSB (bits 63:32) for decoded luminance picture */
#define VPU_G2_SWREG64_SW_DEC_OUT_YBASE_MSB(x)   (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG64_SW_DEC_OUT_YBASE_MSB_SHIFT)) & VPU_G2_SWREG64_SW_DEC_OUT_YBASE_MSB_MASK)
/*! @} */

/*! @name SWREG65 - Base address LSB (bits 31:0) for decoded luminance picture */
/*! @{ */

#define VPU_G2_SWREG65_SW_DEC_OUT_YBASE_LSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG65_SW_DEC_OUT_YBASE_LSB_SHIFT (0U)
/*! SW_DEC_OUT_YBASE_LSB - Base address LSB (bits 31:0) for decoded luminance picture */
#define VPU_G2_SWREG65_SW_DEC_OUT_YBASE_LSB(x)   (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG65_SW_DEC_OUT_YBASE_LSB_SHIFT)) & VPU_G2_SWREG65_SW_DEC_OUT_YBASE_LSB_MASK)
/*! @} */

/*! @name SWREG66 - Base address MSB (bits 63:32) for reference luminance picture index 0 */
/*! @{ */

#define VPU_G2_SWREG66_SW_REFER0_YBASE_MSB_MASK  (0xFFFFFFFFU)
#define VPU_G2_SWREG66_SW_REFER0_YBASE_MSB_SHIFT (0U)
/*! SW_REFER0_YBASE_MSB - Base address MSB (bits 63:32) for reference luminance picture index 0 */
#define VPU_G2_SWREG66_SW_REFER0_YBASE_MSB(x)    (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG66_SW_REFER0_YBASE_MSB_SHIFT)) & VPU_G2_SWREG66_SW_REFER0_YBASE_MSB_MASK)
/*! @} */

/*! @name SWREG67 - Base address LSB (bits 31:0) for reference luminance picture index 0 */
/*! @{ */

#define VPU_G2_SWREG67_SW_REFER0_YBASE_LSB_MASK  (0xFFFFFFFFU)
#define VPU_G2_SWREG67_SW_REFER0_YBASE_LSB_SHIFT (0U)
/*! SW_REFER0_YBASE_LSB - Base address LSB (bits 31:0) for reference luminance picture index 0 */
#define VPU_G2_SWREG67_SW_REFER0_YBASE_LSB(x)    (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG67_SW_REFER0_YBASE_LSB_SHIFT)) & VPU_G2_SWREG67_SW_REFER0_YBASE_LSB_MASK)
/*! @} */

/*! @name SWREG68 - Base address MSB (bits 63:32) for reference luminance picture index 1 */
/*! @{ */

#define VPU_G2_SWREG68_SW_REFER1_YBASE_MSB_MASK  (0xFFFFFFFFU)
#define VPU_G2_SWREG68_SW_REFER1_YBASE_MSB_SHIFT (0U)
/*! SW_REFER1_YBASE_MSB - Base address MSB (bits 63:32) for reference luminance picture index 1 */
#define VPU_G2_SWREG68_SW_REFER1_YBASE_MSB(x)    (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG68_SW_REFER1_YBASE_MSB_SHIFT)) & VPU_G2_SWREG68_SW_REFER1_YBASE_MSB_MASK)
/*! @} */

/*! @name SWREG69 - Base address LSB (bits 31:0) for reference luminance picture index 1 */
/*! @{ */

#define VPU_G2_SWREG69_SW_REFER1_YBASE_LSB_MASK  (0xFFFFFFFFU)
#define VPU_G2_SWREG69_SW_REFER1_YBASE_LSB_SHIFT (0U)
/*! SW_REFER1_YBASE_LSB - Base address LSB (bits 31:0) for reference luminance picture index 1 */
#define VPU_G2_SWREG69_SW_REFER1_YBASE_LSB(x)    (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG69_SW_REFER1_YBASE_LSB_SHIFT)) & VPU_G2_SWREG69_SW_REFER1_YBASE_LSB_MASK)
/*! @} */

/*! @name SWREG70 - Base address MSB (bits 63:32) for reference luminance picture index 2 */
/*! @{ */

#define VPU_G2_SWREG70_SW_REFER2_YBASE_MSB_MASK  (0xFFFFFFFFU)
#define VPU_G2_SWREG70_SW_REFER2_YBASE_MSB_SHIFT (0U)
/*! SW_REFER2_YBASE_MSB - Base address MSB (bits 63:32) for reference luminance picture index 2 */
#define VPU_G2_SWREG70_SW_REFER2_YBASE_MSB(x)    (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG70_SW_REFER2_YBASE_MSB_SHIFT)) & VPU_G2_SWREG70_SW_REFER2_YBASE_MSB_MASK)
/*! @} */

/*! @name SWREG71 - Base address LSB (bits 31:0) for reference luminance picture index 2 */
/*! @{ */

#define VPU_G2_SWREG71_SW_REFER2_YBASE_LSB_MASK  (0xFFFFFFFFU)
#define VPU_G2_SWREG71_SW_REFER2_YBASE_LSB_SHIFT (0U)
/*! SW_REFER2_YBASE_LSB - Base address LSB (bits 31:0) for reference luminance picture index 2 */
#define VPU_G2_SWREG71_SW_REFER2_YBASE_LSB(x)    (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG71_SW_REFER2_YBASE_LSB_SHIFT)) & VPU_G2_SWREG71_SW_REFER2_YBASE_LSB_MASK)
/*! @} */

/*! @name SWREG72 - Base address MSB (bits 63:32) for reference luminance picture index 3 */
/*! @{ */

#define VPU_G2_SWREG72_SW_REFER3_YBASE_MSB_MASK  (0xFFFFFFFFU)
#define VPU_G2_SWREG72_SW_REFER3_YBASE_MSB_SHIFT (0U)
/*! SW_REFER3_YBASE_MSB - Base address MSB (bits 63:32) for reference luminance picture index 3 */
#define VPU_G2_SWREG72_SW_REFER3_YBASE_MSB(x)    (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG72_SW_REFER3_YBASE_MSB_SHIFT)) & VPU_G2_SWREG72_SW_REFER3_YBASE_MSB_MASK)
/*! @} */

/*! @name SWREG73 - Base address LSB (bits 31:0) for reference luminance picture index 3 */
/*! @{ */

#define VPU_G2_SWREG73_SW_REFER3_YBASE_LSB_MASK  (0xFFFFFFFFU)
#define VPU_G2_SWREG73_SW_REFER3_YBASE_LSB_SHIFT (0U)
/*! SW_REFER3_YBASE_LSB - Base address LSB (bits 31:0) for reference luminance picture index 3 */
#define VPU_G2_SWREG73_SW_REFER3_YBASE_LSB(x)    (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG73_SW_REFER3_YBASE_LSB_SHIFT)) & VPU_G2_SWREG73_SW_REFER3_YBASE_LSB_MASK)
/*! @} */

/*! @name SWREG74 - Base address MSB (bits 63:32) for reference luminance picture index 4 */
/*! @{ */

#define VPU_G2_SWREG74_SW_REFER4_YBASE_MSB_MASK  (0xFFFFFFFFU)
#define VPU_G2_SWREG74_SW_REFER4_YBASE_MSB_SHIFT (0U)
/*! SW_REFER4_YBASE_MSB - Base address MSB (bits 63:32) for reference luminance picture index 4 */
#define VPU_G2_SWREG74_SW_REFER4_YBASE_MSB(x)    (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG74_SW_REFER4_YBASE_MSB_SHIFT)) & VPU_G2_SWREG74_SW_REFER4_YBASE_MSB_MASK)
/*! @} */

/*! @name SWREG75 - Base address LSB (bits 31:0) for reference luminance picture index 4 */
/*! @{ */

#define VPU_G2_SWREG75_SW_REFER4_YBASE_LSB_MASK  (0xFFFFFFFFU)
#define VPU_G2_SWREG75_SW_REFER4_YBASE_LSB_SHIFT (0U)
/*! SW_REFER4_YBASE_LSB - Base address LSB (bits 31:0) for reference luminance picture index 4 */
#define VPU_G2_SWREG75_SW_REFER4_YBASE_LSB(x)    (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG75_SW_REFER4_YBASE_LSB_SHIFT)) & VPU_G2_SWREG75_SW_REFER4_YBASE_LSB_MASK)
/*! @} */

/*! @name SWREG76 - Base address MSB (bits 63:32) for reference luminance picture index 5 */
/*! @{ */

#define VPU_G2_SWREG76_SW_REFER5_YBASE_MSB_MASK  (0xFFFFFFFFU)
#define VPU_G2_SWREG76_SW_REFER5_YBASE_MSB_SHIFT (0U)
/*! SW_REFER5_YBASE_MSB - Base address MSB (bits 63:32) for reference luminance picture index 5 */
#define VPU_G2_SWREG76_SW_REFER5_YBASE_MSB(x)    (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG76_SW_REFER5_YBASE_MSB_SHIFT)) & VPU_G2_SWREG76_SW_REFER5_YBASE_MSB_MASK)
/*! @} */

/*! @name SWREG77 - Base address LSB (bits 31:0) for reference luminance picture index 5 */
/*! @{ */

#define VPU_G2_SWREG77_SW_REFER5_YBASE_LSB_MASK  (0xFFFFFFFFU)
#define VPU_G2_SWREG77_SW_REFER5_YBASE_LSB_SHIFT (0U)
/*! SW_REFER5_YBASE_LSB - Base address LSB (bits 31:0) for reference luminance picture index 5 */
#define VPU_G2_SWREG77_SW_REFER5_YBASE_LSB(x)    (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG77_SW_REFER5_YBASE_LSB_SHIFT)) & VPU_G2_SWREG77_SW_REFER5_YBASE_LSB_MASK)
/*! @} */

/*! @name SWREG78 - Base address MSB (bits 63:32) for reference luminance picture index 6 /VP9 segment write base MSB */
/*! @{ */

#define VPU_G2_SWREG78_BASE_ADDR_6_MSB_BF_MASK   (0xFFFFFFFFU)
#define VPU_G2_SWREG78_BASE_ADDR_6_MSB_BF_SHIFT  (0U)
#define VPU_G2_SWREG78_BASE_ADDR_6_MSB_BF(x)     (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG78_BASE_ADDR_6_MSB_BF_SHIFT)) & VPU_G2_SWREG78_BASE_ADDR_6_MSB_BF_MASK)
/*! @} */

/*! @name SWREG79 - Base address LSB (bits 31:0) for reference luminance picture index 6 /VP9 segment write base LSB */
/*! @{ */

#define VPU_G2_SWREG79_BASE_ADDR_6_LSB_BF_MASK   (0xFFFFFFFFU)
#define VPU_G2_SWREG79_BASE_ADDR_6_LSB_BF_SHIFT  (0U)
#define VPU_G2_SWREG79_BASE_ADDR_6_LSB_BF(x)     (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG79_BASE_ADDR_6_LSB_BF_SHIFT)) & VPU_G2_SWREG79_BASE_ADDR_6_LSB_BF_MASK)
/*! @} */

/*! @name SWREG80 - Base address MSB (bits 63:32) for reference luminance picture index 7 /VP9 segment read base MSB */
/*! @{ */

#define VPU_G2_SWREG80_BASE_ADDR_7_MSB_BF_MASK   (0xFFFFFFFFU)
#define VPU_G2_SWREG80_BASE_ADDR_7_MSB_BF_SHIFT  (0U)
#define VPU_G2_SWREG80_BASE_ADDR_7_MSB_BF(x)     (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG80_BASE_ADDR_7_MSB_BF_SHIFT)) & VPU_G2_SWREG80_BASE_ADDR_7_MSB_BF_MASK)
/*! @} */

/*! @name SWREG81 - Base address LSB (bits 31:0) for reference luminance picture index 7 /VP9 segment read base LSB */
/*! @{ */

#define VPU_G2_SWREG81_BASE_ADDR_7_LSB_BF_MASK   (0xFFFFFFFFU)
#define VPU_G2_SWREG81_BASE_ADDR_7_LSB_BF_SHIFT  (0U)
#define VPU_G2_SWREG81_BASE_ADDR_7_LSB_BF(x)     (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG81_BASE_ADDR_7_LSB_BF_SHIFT)) & VPU_G2_SWREG81_BASE_ADDR_7_LSB_BF_MASK)
/*! @} */

/*! @name SWREG82 - Base address MSB (bits 63:32) for reference luminance picture index 8 */
/*! @{ */

#define VPU_G2_SWREG82_SW_REFER8_YBASE_MSB_MASK  (0xFFFFFFFFU)
#define VPU_G2_SWREG82_SW_REFER8_YBASE_MSB_SHIFT (0U)
/*! SW_REFER8_YBASE_MSB - Base address MSB (bits 63:32) for reference luminance picture index 8 */
#define VPU_G2_SWREG82_SW_REFER8_YBASE_MSB(x)    (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG82_SW_REFER8_YBASE_MSB_SHIFT)) & VPU_G2_SWREG82_SW_REFER8_YBASE_MSB_MASK)
/*! @} */

/*! @name SWREG83 - Base address LSB (bits 31:0) for reference luminance picture index 8 */
/*! @{ */

#define VPU_G2_SWREG83_SW_REFER8_YBASE_LSB_MASK  (0xFFFFFFFFU)
#define VPU_G2_SWREG83_SW_REFER8_YBASE_LSB_SHIFT (0U)
/*! SW_REFER8_YBASE_LSB - Base address LSB (bits 31:0) for reference luminance picture index 8 */
#define VPU_G2_SWREG83_SW_REFER8_YBASE_LSB(x)    (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG83_SW_REFER8_YBASE_LSB_SHIFT)) & VPU_G2_SWREG83_SW_REFER8_YBASE_LSB_MASK)
/*! @} */

/*! @name SWREG84 - Base address MSB (bits 63:32) for reference luminance picture index 9 */
/*! @{ */

#define VPU_G2_SWREG84_SW_REFER9_YBASE_MSB_MASK  (0xFFFFFFFFU)
#define VPU_G2_SWREG84_SW_REFER9_YBASE_MSB_SHIFT (0U)
/*! SW_REFER9_YBASE_MSB - Base address MSB (bits 63:32) for reference luminance picture index 9 */
#define VPU_G2_SWREG84_SW_REFER9_YBASE_MSB(x)    (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG84_SW_REFER9_YBASE_MSB_SHIFT)) & VPU_G2_SWREG84_SW_REFER9_YBASE_MSB_MASK)
/*! @} */

/*! @name SWREG85 - Base address LSB (bits 31:0) for reference luminance picture index 9 */
/*! @{ */

#define VPU_G2_SWREG85_SW_REFER9_YBASE_LSB_MASK  (0xFFFFFFFFU)
#define VPU_G2_SWREG85_SW_REFER9_YBASE_LSB_SHIFT (0U)
/*! SW_REFER9_YBASE_LSB - Base address LSB (bits 31:0) for reference luminance picture index 9 */
#define VPU_G2_SWREG85_SW_REFER9_YBASE_LSB(x)    (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG85_SW_REFER9_YBASE_LSB_SHIFT)) & VPU_G2_SWREG85_SW_REFER9_YBASE_LSB_MASK)
/*! @} */

/*! @name SWREG86 - Base address MSB (bits 63:32) for reference luminance picture index 10 */
/*! @{ */

#define VPU_G2_SWREG86_SW_REFER10_YBASE_MSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG86_SW_REFER10_YBASE_MSB_SHIFT (0U)
/*! SW_REFER10_YBASE_MSB - Base address MSB (bits 63:32) for reference luminance picture index 10 */
#define VPU_G2_SWREG86_SW_REFER10_YBASE_MSB(x)   (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG86_SW_REFER10_YBASE_MSB_SHIFT)) & VPU_G2_SWREG86_SW_REFER10_YBASE_MSB_MASK)
/*! @} */

/*! @name SWREG87 - Base address LSB (bits 31:0) for reference luminance picture index 10 */
/*! @{ */

#define VPU_G2_SWREG87_SW_REFER10_YBASE_LSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG87_SW_REFER10_YBASE_LSB_SHIFT (0U)
/*! SW_REFER10_YBASE_LSB - Base address LSB (bits 31:0) for reference luminance picture index 10 */
#define VPU_G2_SWREG87_SW_REFER10_YBASE_LSB(x)   (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG87_SW_REFER10_YBASE_LSB_SHIFT)) & VPU_G2_SWREG87_SW_REFER10_YBASE_LSB_MASK)
/*! @} */

/*! @name SWREG88 - Base address MSB (bits 63:32) for reference luminance picture index 11 */
/*! @{ */

#define VPU_G2_SWREG88_SW_REFER11_YBASE_MSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG88_SW_REFER11_YBASE_MSB_SHIFT (0U)
/*! SW_REFER11_YBASE_MSB - Base address MSB (bits 63:32) for reference luminance picture index 11 */
#define VPU_G2_SWREG88_SW_REFER11_YBASE_MSB(x)   (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG88_SW_REFER11_YBASE_MSB_SHIFT)) & VPU_G2_SWREG88_SW_REFER11_YBASE_MSB_MASK)
/*! @} */

/*! @name SWREG89 - Base address LSB (bits 31:0) for reference luminance picture index 11 */
/*! @{ */

#define VPU_G2_SWREG89_SW_REFER11_YBASE_LSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG89_SW_REFER11_YBASE_LSB_SHIFT (0U)
/*! SW_REFER11_YBASE_LSB - Base address LSB (bits 31:0) for reference luminance picture index 11 */
#define VPU_G2_SWREG89_SW_REFER11_YBASE_LSB(x)   (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG89_SW_REFER11_YBASE_LSB_SHIFT)) & VPU_G2_SWREG89_SW_REFER11_YBASE_LSB_MASK)
/*! @} */

/*! @name SWREG90 - Base address MSB (bits 63:32) for reference luminance picture index 12 */
/*! @{ */

#define VPU_G2_SWREG90_SW_REFER12_YBASE_MSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG90_SW_REFER12_YBASE_MSB_SHIFT (0U)
/*! SW_REFER12_YBASE_MSB - Base address MSB (bits 63:32) for reference luminance picture index 12 */
#define VPU_G2_SWREG90_SW_REFER12_YBASE_MSB(x)   (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG90_SW_REFER12_YBASE_MSB_SHIFT)) & VPU_G2_SWREG90_SW_REFER12_YBASE_MSB_MASK)
/*! @} */

/*! @name SWREG91 - Base address LSB (bits 31:0) for reference luminance picture index 12 */
/*! @{ */

#define VPU_G2_SWREG91_SW_REFER12_YBASE_LSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG91_SW_REFER12_YBASE_LSB_SHIFT (0U)
/*! SW_REFER12_YBASE_LSB - Base address LSB (bits 31:0) for reference luminance picture index 12 */
#define VPU_G2_SWREG91_SW_REFER12_YBASE_LSB(x)   (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG91_SW_REFER12_YBASE_LSB_SHIFT)) & VPU_G2_SWREG91_SW_REFER12_YBASE_LSB_MASK)
/*! @} */

/*! @name SWREG92 - Base address MSB (bits 63:32) for reference luminance picture index 13 */
/*! @{ */

#define VPU_G2_SWREG92_SW_REFER13_YBASE_MSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG92_SW_REFER13_YBASE_MSB_SHIFT (0U)
/*! SW_REFER13_YBASE_MSB - Base address MSB (bits 63:32) for reference luminance picture index 13 */
#define VPU_G2_SWREG92_SW_REFER13_YBASE_MSB(x)   (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG92_SW_REFER13_YBASE_MSB_SHIFT)) & VPU_G2_SWREG92_SW_REFER13_YBASE_MSB_MASK)
/*! @} */

/*! @name SWREG93 - Base address LSB (bits 31:0) for reference luminance picture index 13 */
/*! @{ */

#define VPU_G2_SWREG93_SW_REFER13_YBASE_LSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG93_SW_REFER13_YBASE_LSB_SHIFT (0U)
/*! SW_REFER13_YBASE_LSB - Base address LSB (bits 31:0) for reference luminance picture index 13 */
#define VPU_G2_SWREG93_SW_REFER13_YBASE_LSB(x)   (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG93_SW_REFER13_YBASE_LSB_SHIFT)) & VPU_G2_SWREG93_SW_REFER13_YBASE_LSB_MASK)
/*! @} */

/*! @name SWREG94 - Base address MSB (bits 63:32) for reference luminance picture index 14 */
/*! @{ */

#define VPU_G2_SWREG94_SW_REFER14_YBASE_MSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG94_SW_REFER14_YBASE_MSB_SHIFT (0U)
/*! SW_REFER14_YBASE_MSB - Base address MSB (bits 63:32) for reference luminance picture index 14 */
#define VPU_G2_SWREG94_SW_REFER14_YBASE_MSB(x)   (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG94_SW_REFER14_YBASE_MSB_SHIFT)) & VPU_G2_SWREG94_SW_REFER14_YBASE_MSB_MASK)
/*! @} */

/*! @name SWREG95 - Base address LSB (bits 31:0) for reference luminance picture index 14 */
/*! @{ */

#define VPU_G2_SWREG95_SW_REFER14_YBASE_LSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG95_SW_REFER14_YBASE_LSB_SHIFT (0U)
/*! SW_REFER14_YBASE_LSB - Base address LSB (bits 31:0) for reference luminance picture index 14 */
#define VPU_G2_SWREG95_SW_REFER14_YBASE_LSB(x)   (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG95_SW_REFER14_YBASE_LSB_SHIFT)) & VPU_G2_SWREG95_SW_REFER14_YBASE_LSB_MASK)
/*! @} */

/*! @name SWREG96 - Base address MSB (bits 63:32) for reference luminance picture index 15 */
/*! @{ */

#define VPU_G2_SWREG96_SW_REFER15_YBASE_MSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG96_SW_REFER15_YBASE_MSB_SHIFT (0U)
/*! SW_REFER15_YBASE_MSB - Base address MSB (bits 63:32) for reference luminance picture index 15 */
#define VPU_G2_SWREG96_SW_REFER15_YBASE_MSB(x)   (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG96_SW_REFER15_YBASE_MSB_SHIFT)) & VPU_G2_SWREG96_SW_REFER15_YBASE_MSB_MASK)
/*! @} */

/*! @name SWREG97 - Base address LSB (bits 31:0) for reference luminance picture index 15 */
/*! @{ */

#define VPU_G2_SWREG97_SW_REFER15_YBASE_LSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG97_SW_REFER15_YBASE_LSB_SHIFT (0U)
/*! SW_REFER15_YBASE_LSB - Base address LSB (bits 31:0) for reference luminance picture index 15 */
#define VPU_G2_SWREG97_SW_REFER15_YBASE_LSB(x)   (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG97_SW_REFER15_YBASE_LSB_SHIFT)) & VPU_G2_SWREG97_SW_REFER15_YBASE_LSB_MASK)
/*! @} */

/*! @name SWREG98 - Base address MSB (bits 63:32) for decoded chrominance picture */
/*! @{ */

#define VPU_G2_SWREG98_SW_DEC_OUT_CBASE_MSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG98_SW_DEC_OUT_CBASE_MSB_SHIFT (0U)
/*! SW_DEC_OUT_CBASE_MSB - Base address MSB (bits 64:32) for decoded chrominance picture */
#define VPU_G2_SWREG98_SW_DEC_OUT_CBASE_MSB(x)   (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG98_SW_DEC_OUT_CBASE_MSB_SHIFT)) & VPU_G2_SWREG98_SW_DEC_OUT_CBASE_MSB_MASK)
/*! @} */

/*! @name SWREG99 - Base address LSB (bits 31:0) for decoded chrominance picture */
/*! @{ */

#define VPU_G2_SWREG99_SW_DEC_OUT_CBASE_LSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG99_SW_DEC_OUT_CBASE_LSB_SHIFT (0U)
/*! SW_DEC_OUT_CBASE_LSB - Base address LSB (bits 31:0) for decoded chrominance picture */
#define VPU_G2_SWREG99_SW_DEC_OUT_CBASE_LSB(x)   (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG99_SW_DEC_OUT_CBASE_LSB_SHIFT)) & VPU_G2_SWREG99_SW_DEC_OUT_CBASE_LSB_MASK)
/*! @} */

/*! @name SWREG100 - Base address MSB (bits 63:32) for reference chrominance picture index 0 */
/*! @{ */

#define VPU_G2_SWREG100_SW_REFER0_CBASE_MSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG100_SW_REFER0_CBASE_MSB_SHIFT (0U)
/*! SW_REFER0_CBASE_MSB - Base address MSB (bits 63:32) for reference chrominance picture index 0 */
#define VPU_G2_SWREG100_SW_REFER0_CBASE_MSB(x)   (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG100_SW_REFER0_CBASE_MSB_SHIFT)) & VPU_G2_SWREG100_SW_REFER0_CBASE_MSB_MASK)
/*! @} */

/*! @name SWREG101 - Base address LSB (bits 31:0) for reference chrominance picture index 0 */
/*! @{ */

#define VPU_G2_SWREG101_SW_REFER0_CBASE_LSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG101_SW_REFER0_CBASE_LSB_SHIFT (0U)
/*! SW_REFER0_CBASE_LSB - Base address LSB (bits 31:0) for reference chrominance picture index 0 */
#define VPU_G2_SWREG101_SW_REFER0_CBASE_LSB(x)   (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG101_SW_REFER0_CBASE_LSB_SHIFT)) & VPU_G2_SWREG101_SW_REFER0_CBASE_LSB_MASK)
/*! @} */

/*! @name SWREG102 - Base address MSB (bits 63:32) for reference chrominance picture index 1 */
/*! @{ */

#define VPU_G2_SWREG102_SW_REFER1_CBASE_MSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG102_SW_REFER1_CBASE_MSB_SHIFT (0U)
/*! SW_REFER1_CBASE_MSB - Base address MSB (bits 63:32) for reference chrominance picture index 1 */
#define VPU_G2_SWREG102_SW_REFER1_CBASE_MSB(x)   (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG102_SW_REFER1_CBASE_MSB_SHIFT)) & VPU_G2_SWREG102_SW_REFER1_CBASE_MSB_MASK)
/*! @} */

/*! @name SWREG103 - Base address LSB (bits 31:0) for reference chrominance picture index 1 */
/*! @{ */

#define VPU_G2_SWREG103_SW_REFER1_CBASE_LSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG103_SW_REFER1_CBASE_LSB_SHIFT (0U)
/*! SW_REFER1_CBASE_LSB - Base address LSB (bits 31:0) for reference chrominance picture index 1 */
#define VPU_G2_SWREG103_SW_REFER1_CBASE_LSB(x)   (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG103_SW_REFER1_CBASE_LSB_SHIFT)) & VPU_G2_SWREG103_SW_REFER1_CBASE_LSB_MASK)
/*! @} */

/*! @name SWREG104 - Base address MSB (bits 63:32) for reference chrominance picture index 2 */
/*! @{ */

#define VPU_G2_SWREG104_SW_REFER2_CBASE_MSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG104_SW_REFER2_CBASE_MSB_SHIFT (0U)
/*! SW_REFER2_CBASE_MSB - Base address MSB (bits 63:32) for reference chrominance picture index 2 */
#define VPU_G2_SWREG104_SW_REFER2_CBASE_MSB(x)   (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG104_SW_REFER2_CBASE_MSB_SHIFT)) & VPU_G2_SWREG104_SW_REFER2_CBASE_MSB_MASK)
/*! @} */

/*! @name SWREG105 - Base address LSB (bits 31:0) for reference chrominance picture index 2 */
/*! @{ */

#define VPU_G2_SWREG105_SW_REFER2_CBASE_LSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG105_SW_REFER2_CBASE_LSB_SHIFT (0U)
/*! SW_REFER2_CBASE_LSB - Base address LSB (bits 31:0) for reference chrominance picture index 2 */
#define VPU_G2_SWREG105_SW_REFER2_CBASE_LSB(x)   (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG105_SW_REFER2_CBASE_LSB_SHIFT)) & VPU_G2_SWREG105_SW_REFER2_CBASE_LSB_MASK)
/*! @} */

/*! @name SWREG106 - Base address MSB (bits 63:32) for reference chrominance picture index 3 */
/*! @{ */

#define VPU_G2_SWREG106_SW_REFER3_CBASE_MSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG106_SW_REFER3_CBASE_MSB_SHIFT (0U)
/*! SW_REFER3_CBASE_MSB - Base address MSB (bits 63:32) for reference chrominance picture index 3 */
#define VPU_G2_SWREG106_SW_REFER3_CBASE_MSB(x)   (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG106_SW_REFER3_CBASE_MSB_SHIFT)) & VPU_G2_SWREG106_SW_REFER3_CBASE_MSB_MASK)
/*! @} */

/*! @name SWREG107 - Base address LSB (bits 31:0) for reference chrominance picture index 3 */
/*! @{ */

#define VPU_G2_SWREG107_SW_REFER3_CBASE_LSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG107_SW_REFER3_CBASE_LSB_SHIFT (0U)
/*! SW_REFER3_CBASE_LSB - Base address LSB (bits 31:0) for reference chrominance picture index 3 */
#define VPU_G2_SWREG107_SW_REFER3_CBASE_LSB(x)   (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG107_SW_REFER3_CBASE_LSB_SHIFT)) & VPU_G2_SWREG107_SW_REFER3_CBASE_LSB_MASK)
/*! @} */

/*! @name SWREG108 - Base address MSB (bits 63:32) for reference chrominance picture index 4 */
/*! @{ */

#define VPU_G2_SWREG108_SW_REFER4_CBASE_MSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG108_SW_REFER4_CBASE_MSB_SHIFT (0U)
/*! SW_REFER4_CBASE_MSB - Base address MSB (bits 63:32) for reference chrominance picture index 4 */
#define VPU_G2_SWREG108_SW_REFER4_CBASE_MSB(x)   (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG108_SW_REFER4_CBASE_MSB_SHIFT)) & VPU_G2_SWREG108_SW_REFER4_CBASE_MSB_MASK)
/*! @} */

/*! @name SWREG109 - Base address LSB (bits 31:0) for reference chrominance picture index 4 */
/*! @{ */

#define VPU_G2_SWREG109_SW_REFER4_CBASE_LSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG109_SW_REFER4_CBASE_LSB_SHIFT (0U)
/*! SW_REFER4_CBASE_LSB - Base address LSB (bits 31:0) for reference chrominance picture index 4 */
#define VPU_G2_SWREG109_SW_REFER4_CBASE_LSB(x)   (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG109_SW_REFER4_CBASE_LSB_SHIFT)) & VPU_G2_SWREG109_SW_REFER4_CBASE_LSB_MASK)
/*! @} */

/*! @name SWREG110 - Base address MSB (bits 63:32) for reference chrominance picture index 5 */
/*! @{ */

#define VPU_G2_SWREG110_SW_REFER5_CBASE_MSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG110_SW_REFER5_CBASE_MSB_SHIFT (0U)
/*! SW_REFER5_CBASE_MSB - Base address MSB (bits 63:32) for reference chrominance picture index 5 */
#define VPU_G2_SWREG110_SW_REFER5_CBASE_MSB(x)   (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG110_SW_REFER5_CBASE_MSB_SHIFT)) & VPU_G2_SWREG110_SW_REFER5_CBASE_MSB_MASK)
/*! @} */

/*! @name SWREG111 - Base address LSB (bits 31:0) for reference chrominance picture index 5 */
/*! @{ */

#define VPU_G2_SWREG111_SW_REFER5_CBASE_LSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG111_SW_REFER5_CBASE_LSB_SHIFT (0U)
/*! SW_REFER5_CBASE_LSB - Base address LSB (bits 31:0) for reference chrominance picture index 5 */
#define VPU_G2_SWREG111_SW_REFER5_CBASE_LSB(x)   (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG111_SW_REFER5_CBASE_LSB_SHIFT)) & VPU_G2_SWREG111_SW_REFER5_CBASE_LSB_MASK)
/*! @} */

/*! @name SWREG112 - Base address MSB (bits 63:32) for reference chrominance picture index 6 */
/*! @{ */

#define VPU_G2_SWREG112_SW_REFER6_CBASE_MSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG112_SW_REFER6_CBASE_MSB_SHIFT (0U)
/*! SW_REFER6_CBASE_MSB - Base address MSB (bits 63:32) for reference chrominance picture index 6 */
#define VPU_G2_SWREG112_SW_REFER6_CBASE_MSB(x)   (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG112_SW_REFER6_CBASE_MSB_SHIFT)) & VPU_G2_SWREG112_SW_REFER6_CBASE_MSB_MASK)
/*! @} */

/*! @name SWREG113 - Base address LSB (bits 31:0) for reference chrominance picture index 6 */
/*! @{ */

#define VPU_G2_SWREG113_SW_REFER6_CBASE_LSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG113_SW_REFER6_CBASE_LSB_SHIFT (0U)
/*! SW_REFER6_CBASE_LSB - Base address LSB (bits 31:0) for reference chrominance picture index 6 */
#define VPU_G2_SWREG113_SW_REFER6_CBASE_LSB(x)   (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG113_SW_REFER6_CBASE_LSB_SHIFT)) & VPU_G2_SWREG113_SW_REFER6_CBASE_LSB_MASK)
/*! @} */

/*! @name SWREG114 - Base address MSB (bits 63:32) for reference chrominance picture index 7 */
/*! @{ */

#define VPU_G2_SWREG114_SW_REFER7_CBASE_MSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG114_SW_REFER7_CBASE_MSB_SHIFT (0U)
/*! SW_REFER7_CBASE_MSB - Base address MSB (bits 63:32) for reference chrominance picture index 7 */
#define VPU_G2_SWREG114_SW_REFER7_CBASE_MSB(x)   (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG114_SW_REFER7_CBASE_MSB_SHIFT)) & VPU_G2_SWREG114_SW_REFER7_CBASE_MSB_MASK)
/*! @} */

/*! @name SWREG115 - Base address LSB (bits 31:0) for reference chrominance picture index 7 */
/*! @{ */

#define VPU_G2_SWREG115_SW_REFER7_CBASE_LSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG115_SW_REFER7_CBASE_LSB_SHIFT (0U)
/*! SW_REFER7_CBASE_LSB - Base address LSB (bits 31:0) for reference chrominance picture index 7 */
#define VPU_G2_SWREG115_SW_REFER7_CBASE_LSB(x)   (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG115_SW_REFER7_CBASE_LSB_SHIFT)) & VPU_G2_SWREG115_SW_REFER7_CBASE_LSB_MASK)
/*! @} */

/*! @name SWREG116 - Base address MSB (bits 63:32) for reference chrominance picture index 8 */
/*! @{ */

#define VPU_G2_SWREG116_SW_REFER8_CBASE_MSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG116_SW_REFER8_CBASE_MSB_SHIFT (0U)
/*! SW_REFER8_CBASE_MSB - Base address MSB (bits 63:32) for reference chrominance picture index 8 */
#define VPU_G2_SWREG116_SW_REFER8_CBASE_MSB(x)   (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG116_SW_REFER8_CBASE_MSB_SHIFT)) & VPU_G2_SWREG116_SW_REFER8_CBASE_MSB_MASK)
/*! @} */

/*! @name SWREG117 - Base address LSB (bits 31:0) for reference chrominance picture index 8 */
/*! @{ */

#define VPU_G2_SWREG117_SW_REFER8_CBASE_LSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG117_SW_REFER8_CBASE_LSB_SHIFT (0U)
/*! SW_REFER8_CBASE_LSB - Base address LSB (bits 31:0) for reference chrominance picture index 8 */
#define VPU_G2_SWREG117_SW_REFER8_CBASE_LSB(x)   (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG117_SW_REFER8_CBASE_LSB_SHIFT)) & VPU_G2_SWREG117_SW_REFER8_CBASE_LSB_MASK)
/*! @} */

/*! @name SWREG118 - Base address MSB (bits 63:32) for reference chrominance picture index 9 */
/*! @{ */

#define VPU_G2_SWREG118_SW_REFER9_CBASE_MSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG118_SW_REFER9_CBASE_MSB_SHIFT (0U)
/*! SW_REFER9_CBASE_MSB - Base address MSB (bits 63:32) for reference chrominance picture index 9 */
#define VPU_G2_SWREG118_SW_REFER9_CBASE_MSB(x)   (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG118_SW_REFER9_CBASE_MSB_SHIFT)) & VPU_G2_SWREG118_SW_REFER9_CBASE_MSB_MASK)
/*! @} */

/*! @name SWREG119 - Base address LSB (bits 31:0) for reference chrominance picture index 9 */
/*! @{ */

#define VPU_G2_SWREG119_SW_REFER9_CBASE_LSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG119_SW_REFER9_CBASE_LSB_SHIFT (0U)
/*! SW_REFER9_CBASE_LSB - Base address LSB (bits 31:0) for reference chrominance picture index 9 */
#define VPU_G2_SWREG119_SW_REFER9_CBASE_LSB(x)   (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG119_SW_REFER9_CBASE_LSB_SHIFT)) & VPU_G2_SWREG119_SW_REFER9_CBASE_LSB_MASK)
/*! @} */

/*! @name SWREG120 - Base address MSB (bits 63:32) for reference chrominance picture index 10 */
/*! @{ */

#define VPU_G2_SWREG120_SW_REFER10_CBASE_MSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG120_SW_REFER10_CBASE_MSB_SHIFT (0U)
/*! SW_REFER10_CBASE_MSB - Base address MSB (bits 63:32) for reference chrominance picture index 10 */
#define VPU_G2_SWREG120_SW_REFER10_CBASE_MSB(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG120_SW_REFER10_CBASE_MSB_SHIFT)) & VPU_G2_SWREG120_SW_REFER10_CBASE_MSB_MASK)
/*! @} */

/*! @name SWREG121 - Base address LSB (bits 31:0) for reference chrominance picture index 10 */
/*! @{ */

#define VPU_G2_SWREG121_SW_REFER10_CBASE_LSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG121_SW_REFER10_CBASE_LSB_SHIFT (0U)
/*! SW_REFER10_CBASE_LSB - Base address LSB (bits 31:0) for reference chrominance picture index 10 */
#define VPU_G2_SWREG121_SW_REFER10_CBASE_LSB(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG121_SW_REFER10_CBASE_LSB_SHIFT)) & VPU_G2_SWREG121_SW_REFER10_CBASE_LSB_MASK)
/*! @} */

/*! @name SWREG122 - Base address MSB (bits 63:32) for reference chrominance picture index 11 */
/*! @{ */

#define VPU_G2_SWREG122_SW_REFER11_CBASE_MSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG122_SW_REFER11_CBASE_MSB_SHIFT (0U)
/*! SW_REFER11_CBASE_MSB - Base address MSB (bits 63:32) for reference chrominance picture index 11 */
#define VPU_G2_SWREG122_SW_REFER11_CBASE_MSB(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG122_SW_REFER11_CBASE_MSB_SHIFT)) & VPU_G2_SWREG122_SW_REFER11_CBASE_MSB_MASK)
/*! @} */

/*! @name SWREG123 - Base address LSB (bits 31:0) for reference chrominance picture index 11 */
/*! @{ */

#define VPU_G2_SWREG123_SW_REFER11_CBASE_LSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG123_SW_REFER11_CBASE_LSB_SHIFT (0U)
/*! SW_REFER11_CBASE_LSB - Base address LSB (bits 31:0) for reference chrominance picture index 11 */
#define VPU_G2_SWREG123_SW_REFER11_CBASE_LSB(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG123_SW_REFER11_CBASE_LSB_SHIFT)) & VPU_G2_SWREG123_SW_REFER11_CBASE_LSB_MASK)
/*! @} */

/*! @name SWREG124 - Base address MSB (bits 63:32) for reference chrominance picture index 12 */
/*! @{ */

#define VPU_G2_SWREG124_SW_REFER12_CBASE_MSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG124_SW_REFER12_CBASE_MSB_SHIFT (0U)
/*! SW_REFER12_CBASE_MSB - Base address MSB (bits 63:32) for reference chrominance picture index 12 */
#define VPU_G2_SWREG124_SW_REFER12_CBASE_MSB(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG124_SW_REFER12_CBASE_MSB_SHIFT)) & VPU_G2_SWREG124_SW_REFER12_CBASE_MSB_MASK)
/*! @} */

/*! @name SWREG125 - Base address LSB (bits 31:0) for reference chrominance picture index 12 */
/*! @{ */

#define VPU_G2_SWREG125_SW_REFER12_CBASE_LSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG125_SW_REFER12_CBASE_LSB_SHIFT (0U)
/*! SW_REFER12_CBASE_LSB - Base address LSB (bits 31:0) for reference chrominance picture index 12 */
#define VPU_G2_SWREG125_SW_REFER12_CBASE_LSB(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG125_SW_REFER12_CBASE_LSB_SHIFT)) & VPU_G2_SWREG125_SW_REFER12_CBASE_LSB_MASK)
/*! @} */

/*! @name SWREG126 - Base address MSB (bits 63:32) for reference chrominance picture index 13 */
/*! @{ */

#define VPU_G2_SWREG126_SW_REFER13_CBASE_MSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG126_SW_REFER13_CBASE_MSB_SHIFT (0U)
/*! SW_REFER13_CBASE_MSB - Base address MSB (bits 63:32) for reference chrominance picture index 13 */
#define VPU_G2_SWREG126_SW_REFER13_CBASE_MSB(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG126_SW_REFER13_CBASE_MSB_SHIFT)) & VPU_G2_SWREG126_SW_REFER13_CBASE_MSB_MASK)
/*! @} */

/*! @name SWREG127 - Base address LSB (bits 31:0) for reference chrominance picture index 13 */
/*! @{ */

#define VPU_G2_SWREG127_SW_REFER13_CBASE_LSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG127_SW_REFER13_CBASE_LSB_SHIFT (0U)
/*! SW_REFER13_CBASE_LSB - Base address LSB (bits 31:0) for reference chrominance picture index 13 */
#define VPU_G2_SWREG127_SW_REFER13_CBASE_LSB(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG127_SW_REFER13_CBASE_LSB_SHIFT)) & VPU_G2_SWREG127_SW_REFER13_CBASE_LSB_MASK)
/*! @} */

/*! @name SWREG128 - Base address MSB (bits 63:32) for reference chrominance picture index 14 */
/*! @{ */

#define VPU_G2_SWREG128_SW_REFER14_CBASE_MSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG128_SW_REFER14_CBASE_MSB_SHIFT (0U)
/*! SW_REFER14_CBASE_MSB - Base address MSB (bits 63:32) for reference chrominance picture index 14 */
#define VPU_G2_SWREG128_SW_REFER14_CBASE_MSB(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG128_SW_REFER14_CBASE_MSB_SHIFT)) & VPU_G2_SWREG128_SW_REFER14_CBASE_MSB_MASK)
/*! @} */

/*! @name SWREG129 - Base address LSB (bits 31:0) for reference chrominance picture index 14 */
/*! @{ */

#define VPU_G2_SWREG129_SW_REFER14_CBASE_LSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG129_SW_REFER14_CBASE_LSB_SHIFT (0U)
/*! SW_REFER14_CBASE_LSB - Base address LSB (bits 31:0) for reference chrominance picture index 14 */
#define VPU_G2_SWREG129_SW_REFER14_CBASE_LSB(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG129_SW_REFER14_CBASE_LSB_SHIFT)) & VPU_G2_SWREG129_SW_REFER14_CBASE_LSB_MASK)
/*! @} */

/*! @name SWREG130 - Base address MSB (bits 63:32) for reference chrominance picture index 15 */
/*! @{ */

#define VPU_G2_SWREG130_SW_REFER15_CBASE_MSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG130_SW_REFER15_CBASE_MSB_SHIFT (0U)
/*! SW_REFER15_CBASE_MSB - Base address MSB (bits 63:32) for reference chrominance picture index 15 */
#define VPU_G2_SWREG130_SW_REFER15_CBASE_MSB(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG130_SW_REFER15_CBASE_MSB_SHIFT)) & VPU_G2_SWREG130_SW_REFER15_CBASE_MSB_MASK)
/*! @} */

/*! @name SWREG131 - Base address LSB (bits 31:0) for reference chrominance picture index 15 */
/*! @{ */

#define VPU_G2_SWREG131_SW_REFER15_CBASE_LSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG131_SW_REFER15_CBASE_LSB_SHIFT (0U)
/*! SW_REFER15_CBASE_LSB - Base address LSB (bits 31:0) for reference chrominance picture index 15 */
#define VPU_G2_SWREG131_SW_REFER15_CBASE_LSB(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG131_SW_REFER15_CBASE_LSB_SHIFT)) & VPU_G2_SWREG131_SW_REFER15_CBASE_LSB_MASK)
/*! @} */

/*! @name SWREG132 - Base address MSB (bits 63:32) for decoded direct mode MVS */
/*! @{ */

#define VPU_G2_SWREG132_SW_DEC_OUT_DBASE_MSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG132_SW_DEC_OUT_DBASE_MSB_SHIFT (0U)
/*! SW_DEC_OUT_DBASE_MSB - Base address MSB (bits 63:32) for decoded direct mode MVS */
#define VPU_G2_SWREG132_SW_DEC_OUT_DBASE_MSB(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG132_SW_DEC_OUT_DBASE_MSB_SHIFT)) & VPU_G2_SWREG132_SW_DEC_OUT_DBASE_MSB_MASK)
/*! @} */

/*! @name SWREG133 - Base address LSB (bits 31:0) for decoded direct mode MVS */
/*! @{ */

#define VPU_G2_SWREG133_SW_DEC_OUT_DBASE_LSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG133_SW_DEC_OUT_DBASE_LSB_SHIFT (0U)
/*! SW_DEC_OUT_DBASE_LSB - Base address LSB (bits 31:0) for decoded direct mode MVS */
#define VPU_G2_SWREG133_SW_DEC_OUT_DBASE_LSB(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG133_SW_DEC_OUT_DBASE_LSB_SHIFT)) & VPU_G2_SWREG133_SW_DEC_OUT_DBASE_LSB_MASK)
/*! @} */

/*! @name SWREG134 - Base address MSB (bits 63:32) for reference direct mode MVS index 0 */
/*! @{ */

#define VPU_G2_SWREG134_SW_REFER0_DBASE_MSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG134_SW_REFER0_DBASE_MSB_SHIFT (0U)
/*! SW_REFER0_DBASE_MSB - Base address MSB (bits 63:32) for reference direct mode MVS index 0 */
#define VPU_G2_SWREG134_SW_REFER0_DBASE_MSB(x)   (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG134_SW_REFER0_DBASE_MSB_SHIFT)) & VPU_G2_SWREG134_SW_REFER0_DBASE_MSB_MASK)
/*! @} */

/*! @name SWREG135 - Base address LSB (bits 31:0) for reference direct mode MVS index 0 */
/*! @{ */

#define VPU_G2_SWREG135_SW_REFER0_DBASE_LSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG135_SW_REFER0_DBASE_LSB_SHIFT (0U)
/*! SW_REFER0_DBASE_LSB - Base address LSB (bits 31:0) for reference direct mode MVS index 0 */
#define VPU_G2_SWREG135_SW_REFER0_DBASE_LSB(x)   (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG135_SW_REFER0_DBASE_LSB_SHIFT)) & VPU_G2_SWREG135_SW_REFER0_DBASE_LSB_MASK)
/*! @} */

/*! @name SWREG136 - Base address MSB (bits 63:32) for reference direct mode MVS index 1 */
/*! @{ */

#define VPU_G2_SWREG136_SW_REFER1_DBASE_MSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG136_SW_REFER1_DBASE_MSB_SHIFT (0U)
/*! SW_REFER1_DBASE_MSB - Base address MSB (bits 63:32) for reference direct mode MVS index 1 */
#define VPU_G2_SWREG136_SW_REFER1_DBASE_MSB(x)   (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG136_SW_REFER1_DBASE_MSB_SHIFT)) & VPU_G2_SWREG136_SW_REFER1_DBASE_MSB_MASK)
/*! @} */

/*! @name SWREG137 - Base address LSB (bits 31:0) for reference direct mode MVS index 1 */
/*! @{ */

#define VPU_G2_SWREG137_SW_REFER1_DBASE_LSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG137_SW_REFER1_DBASE_LSB_SHIFT (0U)
/*! SW_REFER1_DBASE_LSB - Base address LSB (bits 31:0) for reference direct mode MVS index 1 */
#define VPU_G2_SWREG137_SW_REFER1_DBASE_LSB(x)   (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG137_SW_REFER1_DBASE_LSB_SHIFT)) & VPU_G2_SWREG137_SW_REFER1_DBASE_LSB_MASK)
/*! @} */

/*! @name SWREG138 - Base address MSB (bits 63:32) for reference direct mode MVS index 2 */
/*! @{ */

#define VPU_G2_SWREG138_SW_REFER2_DBASE_MSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG138_SW_REFER2_DBASE_MSB_SHIFT (0U)
/*! SW_REFER2_DBASE_MSB - Base address MSB (bits 63:32) for reference direct mode MVS index 2 */
#define VPU_G2_SWREG138_SW_REFER2_DBASE_MSB(x)   (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG138_SW_REFER2_DBASE_MSB_SHIFT)) & VPU_G2_SWREG138_SW_REFER2_DBASE_MSB_MASK)
/*! @} */

/*! @name SWREG139 - Base address LSB (bits 31:0) for reference direct mode MVS index 2 */
/*! @{ */

#define VPU_G2_SWREG139_SW_REFER2_DBASE_LSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG139_SW_REFER2_DBASE_LSB_SHIFT (0U)
/*! SW_REFER2_DBASE_LSB - Base address LSB (bits 31:0) for reference direct mode MVS index 2 */
#define VPU_G2_SWREG139_SW_REFER2_DBASE_LSB(x)   (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG139_SW_REFER2_DBASE_LSB_SHIFT)) & VPU_G2_SWREG139_SW_REFER2_DBASE_LSB_MASK)
/*! @} */

/*! @name SWREG140 - Base address MSB (bits 63:32) for reference direct mode MVS index 3 */
/*! @{ */

#define VPU_G2_SWREG140_SW_REFER3_DBASE_MSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG140_SW_REFER3_DBASE_MSB_SHIFT (0U)
/*! SW_REFER3_DBASE_MSB - Base address MSB (bits 63:32) for reference direct mode MVS index 3 */
#define VPU_G2_SWREG140_SW_REFER3_DBASE_MSB(x)   (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG140_SW_REFER3_DBASE_MSB_SHIFT)) & VPU_G2_SWREG140_SW_REFER3_DBASE_MSB_MASK)
/*! @} */

/*! @name SWREG141 - Base address LSB (bits 31:0) for reference direct mode MVS index 3 */
/*! @{ */

#define VPU_G2_SWREG141_SW_REFER3_DBASE_LSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG141_SW_REFER3_DBASE_LSB_SHIFT (0U)
/*! SW_REFER3_DBASE_LSB - Base address LSB (bits 31:0) for reference direct mode MVS index 3 */
#define VPU_G2_SWREG141_SW_REFER3_DBASE_LSB(x)   (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG141_SW_REFER3_DBASE_LSB_SHIFT)) & VPU_G2_SWREG141_SW_REFER3_DBASE_LSB_MASK)
/*! @} */

/*! @name SWREG142 - Base address MSB (bits 63:32) for reference direct mode MVS index 4 */
/*! @{ */

#define VPU_G2_SWREG142_SW_REFER4_DBASE_MSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG142_SW_REFER4_DBASE_MSB_SHIFT (0U)
/*! SW_REFER4_DBASE_MSB - Base address MSB (bits 63:32) for reference direct mode MVS index 4 */
#define VPU_G2_SWREG142_SW_REFER4_DBASE_MSB(x)   (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG142_SW_REFER4_DBASE_MSB_SHIFT)) & VPU_G2_SWREG142_SW_REFER4_DBASE_MSB_MASK)
/*! @} */

/*! @name SWREG143 - Base address LSB (bits 31:0) for reference direct mode MVS index 4 */
/*! @{ */

#define VPU_G2_SWREG143_SW_REFER4_DBASE_LSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG143_SW_REFER4_DBASE_LSB_SHIFT (0U)
/*! SW_REFER4_DBASE_LSB - Base address LSB (bits 31:0) for reference direct mode MVS index 4 */
#define VPU_G2_SWREG143_SW_REFER4_DBASE_LSB(x)   (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG143_SW_REFER4_DBASE_LSB_SHIFT)) & VPU_G2_SWREG143_SW_REFER4_DBASE_LSB_MASK)
/*! @} */

/*! @name SWREG144 - Base address MSB (bits 63:32) for reference direct mode MVS index 5 */
/*! @{ */

#define VPU_G2_SWREG144_SW_REFER5_DBASE_MSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG144_SW_REFER5_DBASE_MSB_SHIFT (0U)
/*! SW_REFER5_DBASE_MSB - Base address MSB (bits 63:32) for reference direct mode MVS index 5 */
#define VPU_G2_SWREG144_SW_REFER5_DBASE_MSB(x)   (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG144_SW_REFER5_DBASE_MSB_SHIFT)) & VPU_G2_SWREG144_SW_REFER5_DBASE_MSB_MASK)
/*! @} */

/*! @name SWREG145 - Base address LSB (bits 31:0) for reference direct mode MVS index 5 */
/*! @{ */

#define VPU_G2_SWREG145_SW_REFER5_DBASE_LSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG145_SW_REFER5_DBASE_LSB_SHIFT (0U)
/*! SW_REFER5_DBASE_LSB - Base address LSB (bits 31:0) for reference direct mode MVS index 5 */
#define VPU_G2_SWREG145_SW_REFER5_DBASE_LSB(x)   (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG145_SW_REFER5_DBASE_LSB_SHIFT)) & VPU_G2_SWREG145_SW_REFER5_DBASE_LSB_MASK)
/*! @} */

/*! @name SWREG146 - Base address MSB (bits 63:32) for reference direct mode MVS index 6 */
/*! @{ */

#define VPU_G2_SWREG146_SW_REFER6_DBASE_MSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG146_SW_REFER6_DBASE_MSB_SHIFT (0U)
/*! SW_REFER6_DBASE_MSB - Base address MSB (bits 63:32) for reference direct mode MVS index 6 */
#define VPU_G2_SWREG146_SW_REFER6_DBASE_MSB(x)   (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG146_SW_REFER6_DBASE_MSB_SHIFT)) & VPU_G2_SWREG146_SW_REFER6_DBASE_MSB_MASK)
/*! @} */

/*! @name SWREG147 - Base address LSB (bits 31:0) for reference direct mode MVS index 6 */
/*! @{ */

#define VPU_G2_SWREG147_SW_REFER6_DBASE_LSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG147_SW_REFER6_DBASE_LSB_SHIFT (0U)
/*! SW_REFER6_DBASE_LSB - Base address LSB (bits 31:0) for reference direct mode MVS index 6 */
#define VPU_G2_SWREG147_SW_REFER6_DBASE_LSB(x)   (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG147_SW_REFER6_DBASE_LSB_SHIFT)) & VPU_G2_SWREG147_SW_REFER6_DBASE_LSB_MASK)
/*! @} */

/*! @name SWREG148 - Base address MSB (bits 63:32) for reference direct mode MVS index 7 */
/*! @{ */

#define VPU_G2_SWREG148_SW_REFER7_DBASE_MSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG148_SW_REFER7_DBASE_MSB_SHIFT (0U)
/*! SW_REFER7_DBASE_MSB - Base address MSB (bits 63:32) for reference direct mode MVS index 7 */
#define VPU_G2_SWREG148_SW_REFER7_DBASE_MSB(x)   (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG148_SW_REFER7_DBASE_MSB_SHIFT)) & VPU_G2_SWREG148_SW_REFER7_DBASE_MSB_MASK)
/*! @} */

/*! @name SWREG149 - Base address LSB (bits 31:0) for reference direct mode MVS index 7 */
/*! @{ */

#define VPU_G2_SWREG149_SW_REFER7_DBASE_LSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG149_SW_REFER7_DBASE_LSB_SHIFT (0U)
/*! SW_REFER7_DBASE_LSB - Base address LSB (bits 31:0) for reference direct mode MVS index 7 */
#define VPU_G2_SWREG149_SW_REFER7_DBASE_LSB(x)   (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG149_SW_REFER7_DBASE_LSB_SHIFT)) & VPU_G2_SWREG149_SW_REFER7_DBASE_LSB_MASK)
/*! @} */

/*! @name SWREG150 - Base address MSB (bits 63:32) for reference direct mode MVS index 8 */
/*! @{ */

#define VPU_G2_SWREG150_SW_REFER8_DBASE_MSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG150_SW_REFER8_DBASE_MSB_SHIFT (0U)
/*! SW_REFER8_DBASE_MSB - Base address MSB (bits 63:32) for reference direct mode MVS index 8 */
#define VPU_G2_SWREG150_SW_REFER8_DBASE_MSB(x)   (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG150_SW_REFER8_DBASE_MSB_SHIFT)) & VPU_G2_SWREG150_SW_REFER8_DBASE_MSB_MASK)
/*! @} */

/*! @name SWREG151 - Base address LSB (bits 31:0) for reference direct mode MVS index 8 */
/*! @{ */

#define VPU_G2_SWREG151_SW_REFER8_DBASE_LSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG151_SW_REFER8_DBASE_LSB_SHIFT (0U)
/*! SW_REFER8_DBASE_LSB - Base address LSB (bits 31:0) for reference direct mode mode MVS index 8 */
#define VPU_G2_SWREG151_SW_REFER8_DBASE_LSB(x)   (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG151_SW_REFER8_DBASE_LSB_SHIFT)) & VPU_G2_SWREG151_SW_REFER8_DBASE_LSB_MASK)
/*! @} */

/*! @name SWREG152 - Base address MSB (bits 63:32) for reference direct mode mode MVS index 9 */
/*! @{ */

#define VPU_G2_SWREG152_SW_REFER9_DBASE_MSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG152_SW_REFER9_DBASE_MSB_SHIFT (0U)
/*! SW_REFER9_DBASE_MSB - Base address MSB (bits 63:32) for reference direct mode MVS index 9 */
#define VPU_G2_SWREG152_SW_REFER9_DBASE_MSB(x)   (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG152_SW_REFER9_DBASE_MSB_SHIFT)) & VPU_G2_SWREG152_SW_REFER9_DBASE_MSB_MASK)
/*! @} */

/*! @name SWREG153 - Base address LSB (bits 31:0) for reference direct mode mode MVS index 9 */
/*! @{ */

#define VPU_G2_SWREG153_SW_REFER9_DBASE_LSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG153_SW_REFER9_DBASE_LSB_SHIFT (0U)
/*! SW_REFER9_DBASE_LSB - Base address LSB (bits 31:0) for reference direct mode mode MVS index 9 */
#define VPU_G2_SWREG153_SW_REFER9_DBASE_LSB(x)   (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG153_SW_REFER9_DBASE_LSB_SHIFT)) & VPU_G2_SWREG153_SW_REFER9_DBASE_LSB_MASK)
/*! @} */

/*! @name SWREG154 - Base address MSB (bits 63:32) for reference direct mode MVS index 10 */
/*! @{ */

#define VPU_G2_SWREG154_SW_REFER10_DBASE_MSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG154_SW_REFER10_DBASE_MSB_SHIFT (0U)
/*! SW_REFER10_DBASE_MSB - Base address MSB (bits 63:32) for reference direct mode MVS index 10 */
#define VPU_G2_SWREG154_SW_REFER10_DBASE_MSB(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG154_SW_REFER10_DBASE_MSB_SHIFT)) & VPU_G2_SWREG154_SW_REFER10_DBASE_MSB_MASK)
/*! @} */

/*! @name SWREG155 - Base address LSB (bits 31:0) for reference direct mode MVS index 10 */
/*! @{ */

#define VPU_G2_SWREG155_SW_REFER10_DBASE_LSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG155_SW_REFER10_DBASE_LSB_SHIFT (0U)
/*! SW_REFER10_DBASE_LSB - Base address LSB (bits 31:0) for reference direct mode MVS index 10 */
#define VPU_G2_SWREG155_SW_REFER10_DBASE_LSB(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG155_SW_REFER10_DBASE_LSB_SHIFT)) & VPU_G2_SWREG155_SW_REFER10_DBASE_LSB_MASK)
/*! @} */

/*! @name SWREG156 - Base address MSB (bits 63:32) for reference direct mode MVS index 11 */
/*! @{ */

#define VPU_G2_SWREG156_SW_REFER11_DBASE_MSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG156_SW_REFER11_DBASE_MSB_SHIFT (0U)
/*! SW_REFER11_DBASE_MSB - Base address MSB (bits 63:32) for reference direct mode MVS index 11 */
#define VPU_G2_SWREG156_SW_REFER11_DBASE_MSB(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG156_SW_REFER11_DBASE_MSB_SHIFT)) & VPU_G2_SWREG156_SW_REFER11_DBASE_MSB_MASK)
/*! @} */

/*! @name SWREG157 - Base address LSB (bits 31:0) for reference direct mode MVS index 11 */
/*! @{ */

#define VPU_G2_SWREG157_SW_REFER11_DBASE_LSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG157_SW_REFER11_DBASE_LSB_SHIFT (0U)
/*! SW_REFER11_DBASE_LSB - Base address LSB (bits 31:0) for reference direct mode MVS index 11 */
#define VPU_G2_SWREG157_SW_REFER11_DBASE_LSB(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG157_SW_REFER11_DBASE_LSB_SHIFT)) & VPU_G2_SWREG157_SW_REFER11_DBASE_LSB_MASK)
/*! @} */

/*! @name SWREG158 - Base address MSB (bits 63:32) for reference direct mode MVS index 12 */
/*! @{ */

#define VPU_G2_SWREG158_SW_REFER12_DBASE_MSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG158_SW_REFER12_DBASE_MSB_SHIFT (0U)
/*! SW_REFER12_DBASE_MSB - Base address MSB (bits 63:32) for reference direct mode MVS index 12 */
#define VPU_G2_SWREG158_SW_REFER12_DBASE_MSB(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG158_SW_REFER12_DBASE_MSB_SHIFT)) & VPU_G2_SWREG158_SW_REFER12_DBASE_MSB_MASK)
/*! @} */

/*! @name SWREG159 - Base address LSB (bits 31:0) for reference direct mode MVS index 12 */
/*! @{ */

#define VPU_G2_SWREG159_SW_REFER12_DBASE_LSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG159_SW_REFER12_DBASE_LSB_SHIFT (0U)
/*! SW_REFER12_DBASE_LSB - Base address LSB (bits 31:0) for reference direct mode MVS index 12 */
#define VPU_G2_SWREG159_SW_REFER12_DBASE_LSB(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG159_SW_REFER12_DBASE_LSB_SHIFT)) & VPU_G2_SWREG159_SW_REFER12_DBASE_LSB_MASK)
/*! @} */

/*! @name SWREG160 - Base address MSB (bits 63:32) for reference direct mode MVS index 13 */
/*! @{ */

#define VPU_G2_SWREG160_SW_REFER13_DBASE_MSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG160_SW_REFER13_DBASE_MSB_SHIFT (0U)
/*! SW_REFER13_DBASE_MSB - Base address MSB (bits 63:32) for reference direct mode MVS index 13 */
#define VPU_G2_SWREG160_SW_REFER13_DBASE_MSB(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG160_SW_REFER13_DBASE_MSB_SHIFT)) & VPU_G2_SWREG160_SW_REFER13_DBASE_MSB_MASK)
/*! @} */

/*! @name SWREG161 - Base address LSB (bits 31:0) for reference direct mode MVS index 13 */
/*! @{ */

#define VPU_G2_SWREG161_SW_REFER13_DBASE_LSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG161_SW_REFER13_DBASE_LSB_SHIFT (0U)
/*! SW_REFER13_DBASE_LSB - Base address LSB (bits 31:0) for reference direct mode MVS index 13 */
#define VPU_G2_SWREG161_SW_REFER13_DBASE_LSB(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG161_SW_REFER13_DBASE_LSB_SHIFT)) & VPU_G2_SWREG161_SW_REFER13_DBASE_LSB_MASK)
/*! @} */

/*! @name SWREG162 - Base address MSB (bits 63:32) for reference direct mode MVS index 14 */
/*! @{ */

#define VPU_G2_SWREG162_SW_REFER14_DBASE_MSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG162_SW_REFER14_DBASE_MSB_SHIFT (0U)
/*! SW_REFER14_DBASE_MSB - Base address MSB (bits 63:32) for reference direct mode MVS index 14 */
#define VPU_G2_SWREG162_SW_REFER14_DBASE_MSB(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG162_SW_REFER14_DBASE_MSB_SHIFT)) & VPU_G2_SWREG162_SW_REFER14_DBASE_MSB_MASK)
/*! @} */

/*! @name SWREG163 - Base address LSB (bits 31:0) for reference direct mode MVS index 14 */
/*! @{ */

#define VPU_G2_SWREG163_SW_REFER14_DBASE_LSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG163_SW_REFER14_DBASE_LSB_SHIFT (0U)
/*! SW_REFER14_DBASE_LSB - Base address LSB (bits 31:0) for reference direct mode MVS index 14 */
#define VPU_G2_SWREG163_SW_REFER14_DBASE_LSB(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG163_SW_REFER14_DBASE_LSB_SHIFT)) & VPU_G2_SWREG163_SW_REFER14_DBASE_LSB_MASK)
/*! @} */

/*! @name SWREG164 - Base address MSB (bits 63:32) for reference direct mode MVS index 15 */
/*! @{ */

#define VPU_G2_SWREG164_SW_REFER15_DBASE_MSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG164_SW_REFER15_DBASE_MSB_SHIFT (0U)
/*! SW_REFER15_DBASE_MSB - Base address MSB (bits 63:32) for reference direct mode MVS index 15 */
#define VPU_G2_SWREG164_SW_REFER15_DBASE_MSB(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG164_SW_REFER15_DBASE_MSB_SHIFT)) & VPU_G2_SWREG164_SW_REFER15_DBASE_MSB_MASK)
/*! @} */

/*! @name SWREG165 - Base address LSB (bits 31:0) for reference direct mode MVS index 15 */
/*! @{ */

#define VPU_G2_SWREG165_SW_REFER15_DBASE_LSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG165_SW_REFER15_DBASE_LSB_SHIFT (0U)
/*! SW_REFER15_DBASE_LSB - Base address LSB (bits 31:0) for reference direct mode MVS index 15 */
#define VPU_G2_SWREG165_SW_REFER15_DBASE_LSB(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG165_SW_REFER15_DBASE_LSB_SHIFT)) & VPU_G2_SWREG165_SW_REFER15_DBASE_LSB_MASK)
/*! @} */

/*! @name SWREG166 - Base address MSB (bits 63:32) for tile sizes */
/*! @{ */

#define VPU_G2_SWREG166_SW_TILE_BASE_MSB_MASK    (0xFFFFFFFFU)
#define VPU_G2_SWREG166_SW_TILE_BASE_MSB_SHIFT   (0U)
/*! SW_TILE_BASE_MSB - Base address MSB (bits 63:32) for tile sizes */
#define VPU_G2_SWREG166_SW_TILE_BASE_MSB(x)      (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG166_SW_TILE_BASE_MSB_SHIFT)) & VPU_G2_SWREG166_SW_TILE_BASE_MSB_MASK)
/*! @} */

/*! @name SWREG167 - Base address LSB (bits 31:0) for tile sizes */
/*! @{ */

#define VPU_G2_SWREG167_SW_TILE_BASE_LSB_MASK    (0xFFFFFFFFU)
#define VPU_G2_SWREG167_SW_TILE_BASE_LSB_SHIFT   (0U)
/*! SW_TILE_BASE_LSB - Base address LSB (bits 31:0) for tile sizes */
#define VPU_G2_SWREG167_SW_TILE_BASE_LSB(x)      (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG167_SW_TILE_BASE_LSB_SHIFT)) & VPU_G2_SWREG167_SW_TILE_BASE_LSB_MASK)
/*! @} */

/*! @name SWREG168 - Base address MSB (bits 63:32) for / stream start address/decoded end addr register */
/*! @{ */

#define VPU_G2_SWREG168_SW_STREAM_BASE_MSB_MASK  (0xFFFFFFFFU)
#define VPU_G2_SWREG168_SW_STREAM_BASE_MSB_SHIFT (0U)
/*! SW_STREAM_BASE_MSB - Base address MSB (bits 63:32) for / stream start address/decoded end addr register */
#define VPU_G2_SWREG168_SW_STREAM_BASE_MSB(x)    (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG168_SW_STREAM_BASE_MSB_SHIFT)) & VPU_G2_SWREG168_SW_STREAM_BASE_MSB_MASK)
/*! @} */

/*! @name SWREG169 - Base address LSB (bits 31:0) for / stream start address/decoded end addr register */
/*! @{ */

#define VPU_G2_SWREG169_SW_STREAM_BASE_LSB_MASK  (0xFFFFFFFFU)
#define VPU_G2_SWREG169_SW_STREAM_BASE_LSB_SHIFT (0U)
/*! SW_STREAM_BASE_LSB - Base address LSB (bits 31:0) for / stream start address/decoded end addr register */
#define VPU_G2_SWREG169_SW_STREAM_BASE_LSB(x)    (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG169_SW_STREAM_BASE_LSB_SHIFT)) & VPU_G2_SWREG169_SW_STREAM_BASE_LSB_MASK)
/*! @} */

/*! @name SWREG170 - Base address MSB (bits 63:32) for scaling lists / VP9 CTX counter values */
/*! @{ */

#define VPU_G2_SWREG170_SW_SCALE_LIST_CTX_COUNTER_BASE_MSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG170_SW_SCALE_LIST_CTX_COUNTER_BASE_MSB_SHIFT (0U)
/*! SW_SCALE_LIST_CTX_COUNTER_BASE_MSB - HEVC: Base address MSB (bits 63:32) for scaling lists VP9: CTX counter values */
#define VPU_G2_SWREG170_SW_SCALE_LIST_CTX_COUNTER_BASE_MSB(x) (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG170_SW_SCALE_LIST_CTX_COUNTER_BASE_MSB_SHIFT)) & VPU_G2_SWREG170_SW_SCALE_LIST_CTX_COUNTER_BASE_MSB_MASK)
/*! @} */

/*! @name SWREG171 - Base address LSB (bits 31:0) for scaling lists / VP9 CTX counter values */
/*! @{ */

#define VPU_G2_SWREG171_SW_SCALE_LISTT_CTX_COUNTER_BASE_LSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG171_SW_SCALE_LISTT_CTX_COUNTER_BASE_LSB_SHIFT (0U)
/*! SW_SCALE_LISTT_CTX_COUNTER_BASE_LSB - HEVC: Base address LSB (bits 31:0) for scaling lists VP9: CTX counter values */
#define VPU_G2_SWREG171_SW_SCALE_LISTT_CTX_COUNTER_BASE_LSB(x) (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG171_SW_SCALE_LISTT_CTX_COUNTER_BASE_LSB_SHIFT)) & VPU_G2_SWREG171_SW_SCALE_LISTT_CTX_COUNTER_BASE_LSB_MASK)
/*! @} */

/*! @name SWREG172 - Base address MSB (bits 63:32) for stream propability tables */
/*! @{ */

#define VPU_G2_SWREG172_SW_PROB_TAB_BASE_MSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG172_SW_PROB_TAB_BASE_MSB_SHIFT (0U)
/*! SW_PROB_TAB_BASE_MSB - Base address MSB (bits 63:32) for stream propability tables */
#define VPU_G2_SWREG172_SW_PROB_TAB_BASE_MSB(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG172_SW_PROB_TAB_BASE_MSB_SHIFT)) & VPU_G2_SWREG172_SW_PROB_TAB_BASE_MSB_MASK)
/*! @} */

/*! @name SWREG173 - Base address LSB (bits 31:0) for stream propability tables */
/*! @{ */

#define VPU_G2_SWREG173_SW_PROB_TAB_BASE_LSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG173_SW_PROB_TAB_BASE_LSB_SHIFT (0U)
/*! SW_PROB_TAB_BASE_LSB - Base address LSB (bits 31:0) for stream propability tables */
#define VPU_G2_SWREG173_SW_PROB_TAB_BASE_LSB(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG173_SW_PROB_TAB_BASE_LSB_SHIFT)) & VPU_G2_SWREG173_SW_PROB_TAB_BASE_LSB_MASK)
/*! @} */

/*! @name SWREG174 - Base address MSB (bits 63:32) for decoder output raster scan Y picture */
/*! @{ */

#define VPU_G2_SWREG174_SW_DEC_RSY_BASE_MSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG174_SW_DEC_RSY_BASE_MSB_SHIFT (0U)
/*! SW_DEC_RSY_BASE_MSB - Base address MSB (bits 63:32) for decoder output raster scan Y picture */
#define VPU_G2_SWREG174_SW_DEC_RSY_BASE_MSB(x)   (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG174_SW_DEC_RSY_BASE_MSB_SHIFT)) & VPU_G2_SWREG174_SW_DEC_RSY_BASE_MSB_MASK)
/*! @} */

/*! @name SWREG175 - Base address LSB (bits 31:0) for decoder output raster scan Y picture */
/*! @{ */

#define VPU_G2_SWREG175_SW_DEC_RSY_BASE_LSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG175_SW_DEC_RSY_BASE_LSB_SHIFT (0U)
/*! SW_DEC_RSY_BASE_LSB - Base address LSB (bits 31:0) for decoder output raster scan Y picture */
#define VPU_G2_SWREG175_SW_DEC_RSY_BASE_LSB(x)   (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG175_SW_DEC_RSY_BASE_LSB_SHIFT)) & VPU_G2_SWREG175_SW_DEC_RSY_BASE_LSB_MASK)
/*! @} */

/*! @name SWREG176 - Base address MSB (bits 63:32) for decoder output raster scan C picture */
/*! @{ */

#define VPU_G2_SWREG176_SW_DEC_RSC_BASE_MSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG176_SW_DEC_RSC_BASE_MSB_SHIFT (0U)
/*! SW_DEC_RSC_BASE_MSB - Base address MSB (bits 63:32) for decoder output raster scan C picture */
#define VPU_G2_SWREG176_SW_DEC_RSC_BASE_MSB(x)   (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG176_SW_DEC_RSC_BASE_MSB_SHIFT)) & VPU_G2_SWREG176_SW_DEC_RSC_BASE_MSB_MASK)
/*! @} */

/*! @name SWREG177 - Base address LSB (bits 31:0) for decoder output raster scan C picture */
/*! @{ */

#define VPU_G2_SWREG177_SW_DEC_RSC_BASE_LSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG177_SW_DEC_RSC_BASE_LSB_SHIFT (0U)
/*! SW_DEC_RSC_BASE_LSB - Base address LSB (bits 31:0) for decoder output raster scan C picture */
#define VPU_G2_SWREG177_SW_DEC_RSC_BASE_LSB(x)   (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG177_SW_DEC_RSC_BASE_LSB_SHIFT)) & VPU_G2_SWREG177_SW_DEC_RSC_BASE_LSB_MASK)
/*! @} */

/*! @name SWREG178 - Base address MSB (bits 63:32) for tile border coeffients of filter */
/*! @{ */

#define VPU_G2_SWREG178_SW_DEC_VERT_FILT_BASE_MSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG178_SW_DEC_VERT_FILT_BASE_MSB_SHIFT (0U)
/*! SW_DEC_VERT_FILT_BASE_MSB - Base address MSB to store/read filtering coeffients of current picture at tile border. */
#define VPU_G2_SWREG178_SW_DEC_VERT_FILT_BASE_MSB(x) (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG178_SW_DEC_VERT_FILT_BASE_MSB_SHIFT)) & VPU_G2_SWREG178_SW_DEC_VERT_FILT_BASE_MSB_MASK)
/*! @} */

/*! @name SWREG179 - Base address LSB (bits 31:0) for tile border coeffients of filter */
/*! @{ */

#define VPU_G2_SWREG179_SW_DEC_VERT_FILT_BASE_LSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG179_SW_DEC_VERT_FILT_BASE_LSB_SHIFT (0U)
/*! SW_DEC_VERT_FILT_BASE_LSB - Base address LSB to store/read filtering coeffients of current picture at tile border. */
#define VPU_G2_SWREG179_SW_DEC_VERT_FILT_BASE_LSB(x) (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG179_SW_DEC_VERT_FILT_BASE_LSB_SHIFT)) & VPU_G2_SWREG179_SW_DEC_VERT_FILT_BASE_LSB_MASK)
/*! @} */

/*! @name SWREG180 - Base address MSB (bits 63:32) for tile border coeffients of sao */
/*! @{ */

#define VPU_G2_SWREG180_SW_DEC_VERT_SAO_BASE_MSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG180_SW_DEC_VERT_SAO_BASE_MSB_SHIFT (0U)
/*! SW_DEC_VERT_SAO_BASE_MSB - Base address MSB to store/read sao coeffients of current picture at tile border. */
#define VPU_G2_SWREG180_SW_DEC_VERT_SAO_BASE_MSB(x) (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG180_SW_DEC_VERT_SAO_BASE_MSB_SHIFT)) & VPU_G2_SWREG180_SW_DEC_VERT_SAO_BASE_MSB_MASK)
/*! @} */

/*! @name SWREG181 - Base address LSB (bits 31:0) for tile border coeffients of sao */
/*! @{ */

#define VPU_G2_SWREG181_SW_DEC_VERT_SAO_BASE_LSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG181_SW_DEC_VERT_SAO_BASE_LSB_SHIFT (0U)
/*! SW_DEC_VERT_SAO_BASE_LSB - Base address LSB to store/read sao coeffients of current picture at tile border. */
#define VPU_G2_SWREG181_SW_DEC_VERT_SAO_BASE_LSB(x) (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG181_SW_DEC_VERT_SAO_BASE_LSB_SHIFT)) & VPU_G2_SWREG181_SW_DEC_VERT_SAO_BASE_LSB_MASK)
/*! @} */

/*! @name SWREG182 - Base address MSB (bits 63:32) for tile border bsd control data */
/*! @{ */

#define VPU_G2_SWREG182_SW_DEC_BSD_CTRL_BASE_MSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG182_SW_DEC_BSD_CTRL_BASE_MSB_SHIFT (0U)
/*! SW_DEC_BSD_CTRL_BASE_MSB - Base address MSB to store/read BSD control data of current picture at tile border. */
#define VPU_G2_SWREG182_SW_DEC_BSD_CTRL_BASE_MSB(x) (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG182_SW_DEC_BSD_CTRL_BASE_MSB_SHIFT)) & VPU_G2_SWREG182_SW_DEC_BSD_CTRL_BASE_MSB_MASK)
/*! @} */

/*! @name SWREG183 - Base address LSB (bits 31:0) for tile border bsd control data */
/*! @{ */

#define VPU_G2_SWREG183_SW_DEC_BSD_CTRL_BASE_LSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG183_SW_DEC_BSD_CTRL_BASE_LSB_SHIFT (0U)
/*! SW_DEC_BSD_CTRL_BASE_LSB - Base address LSB to store/read BSD control data of current picture at tile border. */
#define VPU_G2_SWREG183_SW_DEC_BSD_CTRL_BASE_LSB(x) (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG183_SW_DEC_BSD_CTRL_BASE_LSB_SHIFT)) & VPU_G2_SWREG183_SW_DEC_BSD_CTRL_BASE_LSB_MASK)
/*! @} */

/*! @name SWREG184 - Raster scan down scale control register MSM */
/*! @{ */

#define VPU_G2_SWREG184_SW_DEC_DS_X_MASK         (0x3U)
#define VPU_G2_SWREG184_SW_DEC_DS_X_SHIFT        (0U)
/*! SW_DEC_DS_X - X coordinate down scale times for raster scan output picture data
 *  0b00..1/2
 *  0b01..1/4
 *  0b10..1/8
 */
#define VPU_G2_SWREG184_SW_DEC_DS_X(x)           (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG184_SW_DEC_DS_X_SHIFT)) & VPU_G2_SWREG184_SW_DEC_DS_X_MASK)

#define VPU_G2_SWREG184_SW_DEC_DS_Y_MASK         (0xCU)
#define VPU_G2_SWREG184_SW_DEC_DS_Y_SHIFT        (2U)
/*! SW_DEC_DS_Y - Y coordinate down scale times for raster scan output picture data
 *  0b00..1/2
 *  0b01..1/4
 *  0b10..1/8
 */
#define VPU_G2_SWREG184_SW_DEC_DS_Y(x)           (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG184_SW_DEC_DS_Y_SHIFT)) & VPU_G2_SWREG184_SW_DEC_DS_Y_MASK)

#define VPU_G2_SWREG184_SW_DEC_DS_E_MASK         (0x80U)
#define VPU_G2_SWREG184_SW_DEC_DS_E_SHIFT        (7U)
/*! SW_DEC_DS_E - Raster scan down scale enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define VPU_G2_SWREG184_SW_DEC_DS_E(x)           (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG184_SW_DEC_DS_E_SHIFT)) & VPU_G2_SWREG184_SW_DEC_DS_E_MASK)
/*! @} */

/*! @name SWREG185 - Base address MSB (bits 63:32) for decoder output raster scan down scale Y picture */
/*! @{ */

#define VPU_G2_SWREG185_SW_DEC_DSY_BASE_MSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG185_SW_DEC_DSY_BASE_MSB_SHIFT (0U)
/*! SW_DEC_DSY_BASE_MSB - Base address MSB (bits 63:32) for decoder output raster scan down scale Y picture */
#define VPU_G2_SWREG185_SW_DEC_DSY_BASE_MSB(x)   (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG185_SW_DEC_DSY_BASE_MSB_SHIFT)) & VPU_G2_SWREG185_SW_DEC_DSY_BASE_MSB_MASK)
/*! @} */

/*! @name SWREG186 - Base address LSB (bits 31:0) for decoder output raster scan down scale Y picture */
/*! @{ */

#define VPU_G2_SWREG186_SW_DEC_DSY_BASE_LSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG186_SW_DEC_DSY_BASE_LSB_SHIFT (0U)
/*! SW_DEC_DSY_BASE_LSB - Base address LSB (bits 31:0) for decoder output raster scan down scale Y picture */
#define VPU_G2_SWREG186_SW_DEC_DSY_BASE_LSB(x)   (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG186_SW_DEC_DSY_BASE_LSB_SHIFT)) & VPU_G2_SWREG186_SW_DEC_DSY_BASE_LSB_MASK)
/*! @} */

/*! @name SWREG187 - Base address MSB (bits 63:32) for decoder output raster scan down scale C picture */
/*! @{ */

#define VPU_G2_SWREG187_SW_DEC_DSC_BASE_MSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG187_SW_DEC_DSC_BASE_MSB_SHIFT (0U)
/*! SW_DEC_DSC_BASE_MSB - Base address MSB (bits 63:32) for decoder output raster scan down scale C picture */
#define VPU_G2_SWREG187_SW_DEC_DSC_BASE_MSB(x)   (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG187_SW_DEC_DSC_BASE_MSB_SHIFT)) & VPU_G2_SWREG187_SW_DEC_DSC_BASE_MSB_MASK)
/*! @} */

/*! @name SWREG188 - Base address LSB (bits 31:0) for decoder output raster scan down scale C picture */
/*! @{ */

#define VPU_G2_SWREG188_SW_DEC_DSC_BASE_LSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG188_SW_DEC_DSC_BASE_LSB_SHIFT (0U)
/*! SW_DEC_DSC_BASE_LSB - Base address LSB (bits 31:0) for decoder output raster scan down scale C picture */
#define VPU_G2_SWREG188_SW_DEC_DSC_BASE_LSB(x)   (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG188_SW_DEC_DSC_BASE_LSB_SHIFT)) & VPU_G2_SWREG188_SW_DEC_DSC_BASE_LSB_MASK)
/*! @} */

/*! @name SWREG189 - Base address MSB (bits 63:32) for decoder output compress luminance table */
/*! @{ */

#define VPU_G2_SWREG189_SW_DEC_OUT_TYBASE_MSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG189_SW_DEC_OUT_TYBASE_MSB_SHIFT (0U)
/*! SW_DEC_OUT_TYBASE_MSB - Base address MSB (bits 63:32) for decoder output compress luminance table */
#define VPU_G2_SWREG189_SW_DEC_OUT_TYBASE_MSB(x) (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG189_SW_DEC_OUT_TYBASE_MSB_SHIFT)) & VPU_G2_SWREG189_SW_DEC_OUT_TYBASE_MSB_MASK)
/*! @} */

/*! @name SWREG190 - Base address LSB (bits 31:0) for decoder output compress luminance table */
/*! @{ */

#define VPU_G2_SWREG190_SW_DEC_OUT_TYBASE_LSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG190_SW_DEC_OUT_TYBASE_LSB_SHIFT (0U)
/*! SW_DEC_OUT_TYBASE_LSB - Base address LSB (bits 31:0) for decoder output compress luminance table */
#define VPU_G2_SWREG190_SW_DEC_OUT_TYBASE_LSB(x) (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG190_SW_DEC_OUT_TYBASE_LSB_SHIFT)) & VPU_G2_SWREG190_SW_DEC_OUT_TYBASE_LSB_MASK)
/*! @} */

/*! @name SWREG191 - Base address MSB (bits 63:32) for reference compress luminance table index 0 */
/*! @{ */

#define VPU_G2_SWREG191_SW_REFER0_TYBASE_MSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG191_SW_REFER0_TYBASE_MSB_SHIFT (0U)
/*! SW_REFER0_TYBASE_MSB - Base address MSB (bits 63:32) for reference compress luminance table index 0 */
#define VPU_G2_SWREG191_SW_REFER0_TYBASE_MSB(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG191_SW_REFER0_TYBASE_MSB_SHIFT)) & VPU_G2_SWREG191_SW_REFER0_TYBASE_MSB_MASK)
/*! @} */

/*! @name SWREG192 - Base address LSB (bits 31:0) for reference compress luminance table index 0 */
/*! @{ */

#define VPU_G2_SWREG192_SW_REFER0_TYBASE_LSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG192_SW_REFER0_TYBASE_LSB_SHIFT (0U)
/*! SW_REFER0_TYBASE_LSB - Base address LSB (bits 31:0) for reference compress luminance table index 0 */
#define VPU_G2_SWREG192_SW_REFER0_TYBASE_LSB(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG192_SW_REFER0_TYBASE_LSB_SHIFT)) & VPU_G2_SWREG192_SW_REFER0_TYBASE_LSB_MASK)
/*! @} */

/*! @name SWREG193 - Base address MSB (bits 63:32) for reference compress luminance table index 1 */
/*! @{ */

#define VPU_G2_SWREG193_SW_REFER1_TYBASE_MSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG193_SW_REFER1_TYBASE_MSB_SHIFT (0U)
/*! SW_REFER1_TYBASE_MSB - Base address MSB (bits 63:32) for reference compress luminance table index 1 */
#define VPU_G2_SWREG193_SW_REFER1_TYBASE_MSB(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG193_SW_REFER1_TYBASE_MSB_SHIFT)) & VPU_G2_SWREG193_SW_REFER1_TYBASE_MSB_MASK)
/*! @} */

/*! @name SWREG194 - Base address LSB (bits 31:0) for reference compress luminance table index 1 */
/*! @{ */

#define VPU_G2_SWREG194_SW_REFER1_TYBASE_LSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG194_SW_REFER1_TYBASE_LSB_SHIFT (0U)
/*! SW_REFER1_TYBASE_LSB - Base address LSB (bits 31:0) for reference compress luminance table index 1 */
#define VPU_G2_SWREG194_SW_REFER1_TYBASE_LSB(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG194_SW_REFER1_TYBASE_LSB_SHIFT)) & VPU_G2_SWREG194_SW_REFER1_TYBASE_LSB_MASK)
/*! @} */

/*! @name SWREG195 - Base address MSB (bits 63:32) for reference compress luminance table index 2 */
/*! @{ */

#define VPU_G2_SWREG195_SW_REFER2_TYBASE_MSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG195_SW_REFER2_TYBASE_MSB_SHIFT (0U)
/*! SW_REFER2_TYBASE_MSB - Base address MSB (bits 63:32) for reference compress luminance table index 2 */
#define VPU_G2_SWREG195_SW_REFER2_TYBASE_MSB(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG195_SW_REFER2_TYBASE_MSB_SHIFT)) & VPU_G2_SWREG195_SW_REFER2_TYBASE_MSB_MASK)
/*! @} */

/*! @name SWREG196 - Base address LSB (bits 31:0) for reference compress luminance table index 2 */
/*! @{ */

#define VPU_G2_SWREG196_SW_REFER2_TYBASE_LSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG196_SW_REFER2_TYBASE_LSB_SHIFT (0U)
/*! SW_REFER2_TYBASE_LSB - Base address LSB (bits 31:0) for reference compress luminance table index 2 */
#define VPU_G2_SWREG196_SW_REFER2_TYBASE_LSB(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG196_SW_REFER2_TYBASE_LSB_SHIFT)) & VPU_G2_SWREG196_SW_REFER2_TYBASE_LSB_MASK)
/*! @} */

/*! @name SWREG197 - Base address MSB (bits 63:32) for reference compress luminance table index 3 */
/*! @{ */

#define VPU_G2_SWREG197_SW_REFER3_TYBASE_MSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG197_SW_REFER3_TYBASE_MSB_SHIFT (0U)
/*! SW_REFER3_TYBASE_MSB - Base address MSB (bits 63:32) for reference compress luminance table index 3 */
#define VPU_G2_SWREG197_SW_REFER3_TYBASE_MSB(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG197_SW_REFER3_TYBASE_MSB_SHIFT)) & VPU_G2_SWREG197_SW_REFER3_TYBASE_MSB_MASK)
/*! @} */

/*! @name SWREG198 - Base address LSB (bits 31:0) for reference compress luminance table index 3 */
/*! @{ */

#define VPU_G2_SWREG198_SW_REFER3_TYBASE_LSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG198_SW_REFER3_TYBASE_LSB_SHIFT (0U)
/*! SW_REFER3_TYBASE_LSB - Base address LSB (bits 31:0) for reference compress luminance table index 3 */
#define VPU_G2_SWREG198_SW_REFER3_TYBASE_LSB(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG198_SW_REFER3_TYBASE_LSB_SHIFT)) & VPU_G2_SWREG198_SW_REFER3_TYBASE_LSB_MASK)
/*! @} */

/*! @name SWREG199 - Base address MSB (bits 63:32) for reference compress luminance table index 4 */
/*! @{ */

#define VPU_G2_SWREG199_SW_REFER4_TYBASE_MSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG199_SW_REFER4_TYBASE_MSB_SHIFT (0U)
/*! SW_REFER4_TYBASE_MSB - Base address MSB (bits 63:32) for reference compress luminance table index 4 */
#define VPU_G2_SWREG199_SW_REFER4_TYBASE_MSB(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG199_SW_REFER4_TYBASE_MSB_SHIFT)) & VPU_G2_SWREG199_SW_REFER4_TYBASE_MSB_MASK)
/*! @} */

/*! @name SWREG200 - Base address LSB (bits 31:0) for reference compress luminance table index 4 */
/*! @{ */

#define VPU_G2_SWREG200_SW_REFER4_TYBASE_LSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG200_SW_REFER4_TYBASE_LSB_SHIFT (0U)
/*! SW_REFER4_TYBASE_LSB - Base address LSB (bits 31:0) for reference compress luminance table index 4 */
#define VPU_G2_SWREG200_SW_REFER4_TYBASE_LSB(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG200_SW_REFER4_TYBASE_LSB_SHIFT)) & VPU_G2_SWREG200_SW_REFER4_TYBASE_LSB_MASK)
/*! @} */

/*! @name SWREG201 - Base address MSB (bits 63:32) for reference compress luminance table index 5 */
/*! @{ */

#define VPU_G2_SWREG201_SW_REFER5_TYBASE_MSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG201_SW_REFER5_TYBASE_MSB_SHIFT (0U)
/*! SW_REFER5_TYBASE_MSB - Base address MSB (bits 63:32) for reference compress luminance table index 5 */
#define VPU_G2_SWREG201_SW_REFER5_TYBASE_MSB(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG201_SW_REFER5_TYBASE_MSB_SHIFT)) & VPU_G2_SWREG201_SW_REFER5_TYBASE_MSB_MASK)
/*! @} */

/*! @name SWREG202 - Base address LSB (bits 31:0) for reference compress luminance table index 5 */
/*! @{ */

#define VPU_G2_SWREG202_SW_REFER5_TYBASE_LSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG202_SW_REFER5_TYBASE_LSB_SHIFT (0U)
/*! SW_REFER5_TYBASE_LSB - Base address LSB (bits 31:0) for reference compress luminance table index 5 */
#define VPU_G2_SWREG202_SW_REFER5_TYBASE_LSB(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG202_SW_REFER5_TYBASE_LSB_SHIFT)) & VPU_G2_SWREG202_SW_REFER5_TYBASE_LSB_MASK)
/*! @} */

/*! @name SWREG203 - Base address MSB (bits 63:32) for reference compress luminance table index 6 */
/*! @{ */

#define VPU_G2_SWREG203_SW_REFER6_TYBASE_MSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG203_SW_REFER6_TYBASE_MSB_SHIFT (0U)
/*! SW_REFER6_TYBASE_MSB - Base address MSB (bits 63:32) for reference compress luminance table index 6 */
#define VPU_G2_SWREG203_SW_REFER6_TYBASE_MSB(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG203_SW_REFER6_TYBASE_MSB_SHIFT)) & VPU_G2_SWREG203_SW_REFER6_TYBASE_MSB_MASK)
/*! @} */

/*! @name SWREG204 - Base address LSB (bits 31:0) for reference compress luminance table index 6 */
/*! @{ */

#define VPU_G2_SWREG204_SW_REFER6_TYBASE_LSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG204_SW_REFER6_TYBASE_LSB_SHIFT (0U)
/*! SW_REFER6_TYBASE_LSB - Base address LSB (bits 31:0) for reference compress luminance table index 6 */
#define VPU_G2_SWREG204_SW_REFER6_TYBASE_LSB(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG204_SW_REFER6_TYBASE_LSB_SHIFT)) & VPU_G2_SWREG204_SW_REFER6_TYBASE_LSB_MASK)
/*! @} */

/*! @name SWREG205 - Base address MSB (bits 63:32) for reference compress luminance table index 7 */
/*! @{ */

#define VPU_G2_SWREG205_SW_REFER7_TYBASE_MSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG205_SW_REFER7_TYBASE_MSB_SHIFT (0U)
/*! SW_REFER7_TYBASE_MSB - Base address MSB (bits 63:32) for reference compress luminance table index 7 */
#define VPU_G2_SWREG205_SW_REFER7_TYBASE_MSB(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG205_SW_REFER7_TYBASE_MSB_SHIFT)) & VPU_G2_SWREG205_SW_REFER7_TYBASE_MSB_MASK)
/*! @} */

/*! @name SWREG206 - Base address LSB (bits 31:0) for reference compress luminance table index 7 */
/*! @{ */

#define VPU_G2_SWREG206_SW_REFER7_TYBASE_LSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG206_SW_REFER7_TYBASE_LSB_SHIFT (0U)
/*! SW_REFER7_TYBASE_LSB - Base address LSB (bits 31:0) for reference compress luminance table index 7 */
#define VPU_G2_SWREG206_SW_REFER7_TYBASE_LSB(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG206_SW_REFER7_TYBASE_LSB_SHIFT)) & VPU_G2_SWREG206_SW_REFER7_TYBASE_LSB_MASK)
/*! @} */

/*! @name SWREG207 - Base address MSB (bits 63:32) for reference compress luminance table index 8 */
/*! @{ */

#define VPU_G2_SWREG207_SW_REFER8_TYBASE_MSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG207_SW_REFER8_TYBASE_MSB_SHIFT (0U)
/*! SW_REFER8_TYBASE_MSB - Base address MSB (bits 63:32) for reference compress luminance table index 8 */
#define VPU_G2_SWREG207_SW_REFER8_TYBASE_MSB(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG207_SW_REFER8_TYBASE_MSB_SHIFT)) & VPU_G2_SWREG207_SW_REFER8_TYBASE_MSB_MASK)
/*! @} */

/*! @name SWREG208 - Base address LSB (bits 31:0) for reference compress luminance table index 8 */
/*! @{ */

#define VPU_G2_SWREG208_SW_REFER8_TYBASE_LSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG208_SW_REFER8_TYBASE_LSB_SHIFT (0U)
/*! SW_REFER8_TYBASE_LSB - Base address LSB (bits 31:0) for reference compress luminance table index 8 */
#define VPU_G2_SWREG208_SW_REFER8_TYBASE_LSB(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG208_SW_REFER8_TYBASE_LSB_SHIFT)) & VPU_G2_SWREG208_SW_REFER8_TYBASE_LSB_MASK)
/*! @} */

/*! @name SWREG209 - Base address MSB (bits 63:32) for reference compress luminance table index 9 */
/*! @{ */

#define VPU_G2_SWREG209_SW_REFER9_TYBASE_MSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG209_SW_REFER9_TYBASE_MSB_SHIFT (0U)
/*! SW_REFER9_TYBASE_MSB - Base address MSB (bits 63:32) for reference compress luminance table index 9 */
#define VPU_G2_SWREG209_SW_REFER9_TYBASE_MSB(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG209_SW_REFER9_TYBASE_MSB_SHIFT)) & VPU_G2_SWREG209_SW_REFER9_TYBASE_MSB_MASK)
/*! @} */

/*! @name SWREG210 - Base address LSB (bits 31:0) for reference compress luminance table index 9 */
/*! @{ */

#define VPU_G2_SWREG210_SW_REFER9_TYBASE_LSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG210_SW_REFER9_TYBASE_LSB_SHIFT (0U)
/*! SW_REFER9_TYBASE_LSB - Base address LSB (bits 31:0) for reference compress luminance table index 9 */
#define VPU_G2_SWREG210_SW_REFER9_TYBASE_LSB(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG210_SW_REFER9_TYBASE_LSB_SHIFT)) & VPU_G2_SWREG210_SW_REFER9_TYBASE_LSB_MASK)
/*! @} */

/*! @name SWREG211 - Base address MSB (bits 63:32) for reference compress luminance table index 10 */
/*! @{ */

#define VPU_G2_SWREG211_SW_REFER10_TYBASE_MSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG211_SW_REFER10_TYBASE_MSB_SHIFT (0U)
/*! SW_REFER10_TYBASE_MSB - Base address MSB (bits 63:32) for reference compress luminance table index 10 */
#define VPU_G2_SWREG211_SW_REFER10_TYBASE_MSB(x) (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG211_SW_REFER10_TYBASE_MSB_SHIFT)) & VPU_G2_SWREG211_SW_REFER10_TYBASE_MSB_MASK)
/*! @} */

/*! @name SWREG212 - Base address LSB (bits 31:0) for reference compress luminance table index 10 */
/*! @{ */

#define VPU_G2_SWREG212_SW_REFER10_TYBASE_LSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG212_SW_REFER10_TYBASE_LSB_SHIFT (0U)
/*! SW_REFER10_TYBASE_LSB - Base address LSB (bits 31:0) for reference compress luminance table index 10 */
#define VPU_G2_SWREG212_SW_REFER10_TYBASE_LSB(x) (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG212_SW_REFER10_TYBASE_LSB_SHIFT)) & VPU_G2_SWREG212_SW_REFER10_TYBASE_LSB_MASK)
/*! @} */

/*! @name SWREG213 - Base address MSB (bits 63:32) for reference compress luminance table index 11 */
/*! @{ */

#define VPU_G2_SWREG213_SW_REFER11_TYBASE_MSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG213_SW_REFER11_TYBASE_MSB_SHIFT (0U)
/*! SW_REFER11_TYBASE_MSB - Base address MSB (bits 63:32) for reference compress luminance table index 11 */
#define VPU_G2_SWREG213_SW_REFER11_TYBASE_MSB(x) (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG213_SW_REFER11_TYBASE_MSB_SHIFT)) & VPU_G2_SWREG213_SW_REFER11_TYBASE_MSB_MASK)
/*! @} */

/*! @name SWREG214 - Base address LSB (bits 31:0) for reference compress luminance table index 11 */
/*! @{ */

#define VPU_G2_SWREG214_SW_REFER11_TYBASE_LSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG214_SW_REFER11_TYBASE_LSB_SHIFT (0U)
/*! SW_REFER11_TYBASE_LSB - Base address LSB (bits 31:0) for reference compress luminance table index 11 */
#define VPU_G2_SWREG214_SW_REFER11_TYBASE_LSB(x) (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG214_SW_REFER11_TYBASE_LSB_SHIFT)) & VPU_G2_SWREG214_SW_REFER11_TYBASE_LSB_MASK)
/*! @} */

/*! @name SWREG215 - Base address MSB (bits 63:32) for reference compress luminance table index 12 */
/*! @{ */

#define VPU_G2_SWREG215_SW_REFER12_TYBASE_MSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG215_SW_REFER12_TYBASE_MSB_SHIFT (0U)
/*! SW_REFER12_TYBASE_MSB - Base address MSB (bits 63:32) for reference compress luminance table index 12 */
#define VPU_G2_SWREG215_SW_REFER12_TYBASE_MSB(x) (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG215_SW_REFER12_TYBASE_MSB_SHIFT)) & VPU_G2_SWREG215_SW_REFER12_TYBASE_MSB_MASK)
/*! @} */

/*! @name SWREG216 - Base address LSB (bits 31:0) for reference compress luminance table index 12 */
/*! @{ */

#define VPU_G2_SWREG216_SW_REFER12_TYBASE_LSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG216_SW_REFER12_TYBASE_LSB_SHIFT (0U)
/*! SW_REFER12_TYBASE_LSB - Base address LSB (bits 31:0) for reference compress luminance table index 12 */
#define VPU_G2_SWREG216_SW_REFER12_TYBASE_LSB(x) (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG216_SW_REFER12_TYBASE_LSB_SHIFT)) & VPU_G2_SWREG216_SW_REFER12_TYBASE_LSB_MASK)
/*! @} */

/*! @name SWREG217 - Base address MSB (bits 63:32) for reference compress luminance table index 13 */
/*! @{ */

#define VPU_G2_SWREG217_SW_REFER13_TYBASE_MSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG217_SW_REFER13_TYBASE_MSB_SHIFT (0U)
/*! SW_REFER13_TYBASE_MSB - Base address MSB (bits 63:32) for reference compress luminance table index 13 */
#define VPU_G2_SWREG217_SW_REFER13_TYBASE_MSB(x) (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG217_SW_REFER13_TYBASE_MSB_SHIFT)) & VPU_G2_SWREG217_SW_REFER13_TYBASE_MSB_MASK)
/*! @} */

/*! @name SWREG218 - Base address LSB (bits 31:0) for reference compress luminance table index 13 */
/*! @{ */

#define VPU_G2_SWREG218_SW_REFER13_TYBASE_LSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG218_SW_REFER13_TYBASE_LSB_SHIFT (0U)
/*! SW_REFER13_TYBASE_LSB - Base address LSB (bits 31:0) for reference compress luminance table index 13 */
#define VPU_G2_SWREG218_SW_REFER13_TYBASE_LSB(x) (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG218_SW_REFER13_TYBASE_LSB_SHIFT)) & VPU_G2_SWREG218_SW_REFER13_TYBASE_LSB_MASK)
/*! @} */

/*! @name SWREG219 - Base address MSB (bits 63:32) for reference compress luminance table index 14 */
/*! @{ */

#define VPU_G2_SWREG219_SW_REFER14_TYBASE_MSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG219_SW_REFER14_TYBASE_MSB_SHIFT (0U)
/*! SW_REFER14_TYBASE_MSB - Base address MSB (bits 63:32) for reference compress luminance table index 14 */
#define VPU_G2_SWREG219_SW_REFER14_TYBASE_MSB(x) (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG219_SW_REFER14_TYBASE_MSB_SHIFT)) & VPU_G2_SWREG219_SW_REFER14_TYBASE_MSB_MASK)
/*! @} */

/*! @name SWREG220 - Base address LSB (bits 31:0) for reference compress luminance table index 14 */
/*! @{ */

#define VPU_G2_SWREG220_SW_REFER14_TYBASE_LSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG220_SW_REFER14_TYBASE_LSB_SHIFT (0U)
/*! SW_REFER14_TYBASE_LSB - Base address LSB (bits 31:0) for reference compress luminance table index 14 */
#define VPU_G2_SWREG220_SW_REFER14_TYBASE_LSB(x) (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG220_SW_REFER14_TYBASE_LSB_SHIFT)) & VPU_G2_SWREG220_SW_REFER14_TYBASE_LSB_MASK)
/*! @} */

/*! @name SWREG221 - Base address MSB (bits 63:32) for reference compress luminance table index 15 */
/*! @{ */

#define VPU_G2_SWREG221_SW_REFER15_TYBASE_MSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG221_SW_REFER15_TYBASE_MSB_SHIFT (0U)
/*! SW_REFER15_TYBASE_MSB - Base address MSB (bits 63:32) for reference compress luminance table index 15 */
#define VPU_G2_SWREG221_SW_REFER15_TYBASE_MSB(x) (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG221_SW_REFER15_TYBASE_MSB_SHIFT)) & VPU_G2_SWREG221_SW_REFER15_TYBASE_MSB_MASK)
/*! @} */

/*! @name SWREG222 - Base address LSB (bits 31:0) for reference compress luminance table index 15 */
/*! @{ */

#define VPU_G2_SWREG222_SW_REFER15_TYBASE_LSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG222_SW_REFER15_TYBASE_LSB_SHIFT (0U)
/*! SW_REFER15_TYBASE_LSB - Base address LSB (bits 31:0) for reference compress luminance table index 15 */
#define VPU_G2_SWREG222_SW_REFER15_TYBASE_LSB(x) (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG222_SW_REFER15_TYBASE_LSB_SHIFT)) & VPU_G2_SWREG222_SW_REFER15_TYBASE_LSB_MASK)
/*! @} */

/*! @name SWREG223 - Base address MSB (bits 63:32) for decoder output compress chrominance table */
/*! @{ */

#define VPU_G2_SWREG223_SW_DEC_OUT_TCBASE_MSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG223_SW_DEC_OUT_TCBASE_MSB_SHIFT (0U)
/*! SW_DEC_OUT_TCBASE_MSB - Base address MSB (bits 63:32) for decoder output compress chrominance table */
#define VPU_G2_SWREG223_SW_DEC_OUT_TCBASE_MSB(x) (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG223_SW_DEC_OUT_TCBASE_MSB_SHIFT)) & VPU_G2_SWREG223_SW_DEC_OUT_TCBASE_MSB_MASK)
/*! @} */

/*! @name SWREG224 - Base address LSB (bits 31:0) for decoder output compress chrominance table */
/*! @{ */

#define VPU_G2_SWREG224_SW_DEC_OUT_TCBASE_LSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG224_SW_DEC_OUT_TCBASE_LSB_SHIFT (0U)
/*! SW_DEC_OUT_TCBASE_LSB - Base address LSB (bits 31:0) for decoder output compress chrominance table */
#define VPU_G2_SWREG224_SW_DEC_OUT_TCBASE_LSB(x) (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG224_SW_DEC_OUT_TCBASE_LSB_SHIFT)) & VPU_G2_SWREG224_SW_DEC_OUT_TCBASE_LSB_MASK)
/*! @} */

/*! @name SWREG225 - Base address MSB (bits 63:32) for reference compress chrominance table index 0 */
/*! @{ */

#define VPU_G2_SWREG225_SW_REFER0_TCBASE_MSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG225_SW_REFER0_TCBASE_MSB_SHIFT (0U)
/*! SW_REFER0_TCBASE_MSB - Base address MSB (bits 63:32) for reference compress chrominance table index 0 */
#define VPU_G2_SWREG225_SW_REFER0_TCBASE_MSB(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG225_SW_REFER0_TCBASE_MSB_SHIFT)) & VPU_G2_SWREG225_SW_REFER0_TCBASE_MSB_MASK)
/*! @} */

/*! @name SWREG226 - Base address LSB (bits 31:0) for reference compress chrominance table index 0 */
/*! @{ */

#define VPU_G2_SWREG226_SW_REFER0_TCBASE_LSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG226_SW_REFER0_TCBASE_LSB_SHIFT (0U)
/*! SW_REFER0_TCBASE_LSB - Base address LSB (bits 31:0) for reference compress chrominance table index 0 */
#define VPU_G2_SWREG226_SW_REFER0_TCBASE_LSB(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG226_SW_REFER0_TCBASE_LSB_SHIFT)) & VPU_G2_SWREG226_SW_REFER0_TCBASE_LSB_MASK)
/*! @} */

/*! @name SWREG227 - Base address MSB (bits 63:32) for reference compress chrominance table index 1 */
/*! @{ */

#define VPU_G2_SWREG227_SW_REFER1_TCBASE_MSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG227_SW_REFER1_TCBASE_MSB_SHIFT (0U)
/*! SW_REFER1_TCBASE_MSB - Base address MSB (bits 63:32) for reference compress chrominance table index 1 */
#define VPU_G2_SWREG227_SW_REFER1_TCBASE_MSB(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG227_SW_REFER1_TCBASE_MSB_SHIFT)) & VPU_G2_SWREG227_SW_REFER1_TCBASE_MSB_MASK)
/*! @} */

/*! @name SWREG228 - Base address LSB (bits 31:0) for reference compress chrominance table index 1 */
/*! @{ */

#define VPU_G2_SWREG228_SW_REFER1_TCBASE_LSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG228_SW_REFER1_TCBASE_LSB_SHIFT (0U)
/*! SW_REFER1_TCBASE_LSB - Base address LSB (bits 31:0) for reference compress chrominance table index 1 */
#define VPU_G2_SWREG228_SW_REFER1_TCBASE_LSB(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG228_SW_REFER1_TCBASE_LSB_SHIFT)) & VPU_G2_SWREG228_SW_REFER1_TCBASE_LSB_MASK)
/*! @} */

/*! @name SWREG229 - Base address MSB (bits 63:32) for reference compress chrominance table index 2 */
/*! @{ */

#define VPU_G2_SWREG229_SW_REFER2_TCBASE_MSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG229_SW_REFER2_TCBASE_MSB_SHIFT (0U)
/*! SW_REFER2_TCBASE_MSB - Base address MSB (bits 63:32) for reference compress chrominance table index 2 */
#define VPU_G2_SWREG229_SW_REFER2_TCBASE_MSB(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG229_SW_REFER2_TCBASE_MSB_SHIFT)) & VPU_G2_SWREG229_SW_REFER2_TCBASE_MSB_MASK)
/*! @} */

/*! @name SWREG230 - Base address LSB (bits 31:0) for reference compress chrominance table index 2 */
/*! @{ */

#define VPU_G2_SWREG230_SW_REFER2_TCBASE_LSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG230_SW_REFER2_TCBASE_LSB_SHIFT (0U)
/*! SW_REFER2_TCBASE_LSB - Base address LSB (bits 31:0) for reference compress chrominance table index 2 */
#define VPU_G2_SWREG230_SW_REFER2_TCBASE_LSB(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG230_SW_REFER2_TCBASE_LSB_SHIFT)) & VPU_G2_SWREG230_SW_REFER2_TCBASE_LSB_MASK)
/*! @} */

/*! @name SWREG231 - Base address MSB (bits 63:32) for reference compress chrominance table index 3 */
/*! @{ */

#define VPU_G2_SWREG231_SW_REFER3_TCBASE_MSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG231_SW_REFER3_TCBASE_MSB_SHIFT (0U)
/*! SW_REFER3_TCBASE_MSB - Base address MSB (bits 63:32) for reference compress chrominance table index 3 */
#define VPU_G2_SWREG231_SW_REFER3_TCBASE_MSB(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG231_SW_REFER3_TCBASE_MSB_SHIFT)) & VPU_G2_SWREG231_SW_REFER3_TCBASE_MSB_MASK)
/*! @} */

/*! @name SWREG232 - Base address LSB (bits 31:0) for reference compress chrominance table index 3 */
/*! @{ */

#define VPU_G2_SWREG232_SW_REFER3_TCBASE_LSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG232_SW_REFER3_TCBASE_LSB_SHIFT (0U)
/*! SW_REFER3_TCBASE_LSB - Base address LSB (bits 31:0) for reference compress chrominance table index 3 */
#define VPU_G2_SWREG232_SW_REFER3_TCBASE_LSB(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG232_SW_REFER3_TCBASE_LSB_SHIFT)) & VPU_G2_SWREG232_SW_REFER3_TCBASE_LSB_MASK)
/*! @} */

/*! @name SWREG233 - Base address MSB (bits 63:32) for reference compress chrominance table index 4 */
/*! @{ */

#define VPU_G2_SWREG233_SW_REFER4_TCBASE_MSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG233_SW_REFER4_TCBASE_MSB_SHIFT (0U)
/*! SW_REFER4_TCBASE_MSB - Base address MSB (bits 63:32) for reference compress chrominance table index 4 */
#define VPU_G2_SWREG233_SW_REFER4_TCBASE_MSB(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG233_SW_REFER4_TCBASE_MSB_SHIFT)) & VPU_G2_SWREG233_SW_REFER4_TCBASE_MSB_MASK)
/*! @} */

/*! @name SWREG234 - Base address LSB (bits 31:0) for reference compress chrominance table index 4 */
/*! @{ */

#define VPU_G2_SWREG234_SW_REFER4_TCBASE_LSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG234_SW_REFER4_TCBASE_LSB_SHIFT (0U)
/*! SW_REFER4_TCBASE_LSB - Base address LSB (bits 31:0) for reference compress chrominance table index 4 */
#define VPU_G2_SWREG234_SW_REFER4_TCBASE_LSB(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG234_SW_REFER4_TCBASE_LSB_SHIFT)) & VPU_G2_SWREG234_SW_REFER4_TCBASE_LSB_MASK)
/*! @} */

/*! @name SWREG235 - Base address MSB (bits 63:32) for reference compress chrominance table index 5 */
/*! @{ */

#define VPU_G2_SWREG235_SW_REFER5_TCBASE_MSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG235_SW_REFER5_TCBASE_MSB_SHIFT (0U)
/*! SW_REFER5_TCBASE_MSB - Base address MSB (bits 63:32) for reference compress chrominance table index 5 */
#define VPU_G2_SWREG235_SW_REFER5_TCBASE_MSB(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG235_SW_REFER5_TCBASE_MSB_SHIFT)) & VPU_G2_SWREG235_SW_REFER5_TCBASE_MSB_MASK)
/*! @} */

/*! @name SWREG236 - Base address LSB (bits 31:0) for reference compress chrominance table index 5 */
/*! @{ */

#define VPU_G2_SWREG236_SW_REFER5_TCBASE_LSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG236_SW_REFER5_TCBASE_LSB_SHIFT (0U)
/*! SW_REFER5_TCBASE_LSB - Base address LSB (bits 31:0) for reference compress chrominance table index 5 */
#define VPU_G2_SWREG236_SW_REFER5_TCBASE_LSB(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG236_SW_REFER5_TCBASE_LSB_SHIFT)) & VPU_G2_SWREG236_SW_REFER5_TCBASE_LSB_MASK)
/*! @} */

/*! @name SWREG237 - Base address MSB (bits 63:32) for reference compress chrominance table index 6 */
/*! @{ */

#define VPU_G2_SWREG237_SW_REFER6_TCBASE_MSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG237_SW_REFER6_TCBASE_MSB_SHIFT (0U)
/*! SW_REFER6_TCBASE_MSB - Base address MSB (bits 63:32) for reference compress chrominance table index 6 */
#define VPU_G2_SWREG237_SW_REFER6_TCBASE_MSB(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG237_SW_REFER6_TCBASE_MSB_SHIFT)) & VPU_G2_SWREG237_SW_REFER6_TCBASE_MSB_MASK)
/*! @} */

/*! @name SWREG238 - Base address LSB (bits 31:0) for reference compress chrominance table index 6 */
/*! @{ */

#define VPU_G2_SWREG238_SW_REFER6_TCBASE_LSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG238_SW_REFER6_TCBASE_LSB_SHIFT (0U)
/*! SW_REFER6_TCBASE_LSB - Base address LSB (bits 31:0) for reference compress chrominance table index 6 */
#define VPU_G2_SWREG238_SW_REFER6_TCBASE_LSB(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG238_SW_REFER6_TCBASE_LSB_SHIFT)) & VPU_G2_SWREG238_SW_REFER6_TCBASE_LSB_MASK)
/*! @} */

/*! @name SWREG239 - Base address MSB (bits 63:32) for reference compress chrominance table index 7 */
/*! @{ */

#define VPU_G2_SWREG239_SW_REFER7_TCBASE_MSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG239_SW_REFER7_TCBASE_MSB_SHIFT (0U)
/*! SW_REFER7_TCBASE_MSB - Base address MSB (bits 63:32) for reference compress chrominance table index 7 */
#define VPU_G2_SWREG239_SW_REFER7_TCBASE_MSB(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG239_SW_REFER7_TCBASE_MSB_SHIFT)) & VPU_G2_SWREG239_SW_REFER7_TCBASE_MSB_MASK)
/*! @} */

/*! @name SWREG240 - Base address LSB (bits 31:0) for reference compress chrominance table index 7 */
/*! @{ */

#define VPU_G2_SWREG240_SW_REFER7_TCBASE_LSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG240_SW_REFER7_TCBASE_LSB_SHIFT (0U)
/*! SW_REFER7_TCBASE_LSB - Base address LSB (bits 31:0) for reference compress chrominance table index 7 */
#define VPU_G2_SWREG240_SW_REFER7_TCBASE_LSB(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG240_SW_REFER7_TCBASE_LSB_SHIFT)) & VPU_G2_SWREG240_SW_REFER7_TCBASE_LSB_MASK)
/*! @} */

/*! @name SWREG241 - Base address MSB (bits 63:32) for reference compress chrominance table index 8 */
/*! @{ */

#define VPU_G2_SWREG241_SW_REFER8_TCBASE_MSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG241_SW_REFER8_TCBASE_MSB_SHIFT (0U)
/*! SW_REFER8_TCBASE_MSB - Base address MSB (bits 63:32) for reference compress chrominance table index 8 */
#define VPU_G2_SWREG241_SW_REFER8_TCBASE_MSB(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG241_SW_REFER8_TCBASE_MSB_SHIFT)) & VPU_G2_SWREG241_SW_REFER8_TCBASE_MSB_MASK)
/*! @} */

/*! @name SWREG242 - Base address LSB (bits 31:0) for reference compress chrominance table index 8 */
/*! @{ */

#define VPU_G2_SWREG242_SW_REFER8_TCBASE_LSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG242_SW_REFER8_TCBASE_LSB_SHIFT (0U)
/*! SW_REFER8_TCBASE_LSB - Base address LSB (bits 31:0) for reference compress chrominance table index 8 */
#define VPU_G2_SWREG242_SW_REFER8_TCBASE_LSB(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG242_SW_REFER8_TCBASE_LSB_SHIFT)) & VPU_G2_SWREG242_SW_REFER8_TCBASE_LSB_MASK)
/*! @} */

/*! @name SWREG243 - Base address MSB (bits 63:32) for reference compress chrominance table index 9 */
/*! @{ */

#define VPU_G2_SWREG243_SW_REFER9_TCBASE_MSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG243_SW_REFER9_TCBASE_MSB_SHIFT (0U)
/*! SW_REFER9_TCBASE_MSB - Base address MSB (bits 63:32) for reference compress chrominance table index 9 */
#define VPU_G2_SWREG243_SW_REFER9_TCBASE_MSB(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG243_SW_REFER9_TCBASE_MSB_SHIFT)) & VPU_G2_SWREG243_SW_REFER9_TCBASE_MSB_MASK)
/*! @} */

/*! @name SWREG244 - Base address LSB (bits 31:0) for reference compress chrominance table index 9 */
/*! @{ */

#define VPU_G2_SWREG244_SW_REFER9_TCBASE_LSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG244_SW_REFER9_TCBASE_LSB_SHIFT (0U)
/*! SW_REFER9_TCBASE_LSB - Base address LSB (bits 31:0) for reference compress chrominance table index 9 */
#define VPU_G2_SWREG244_SW_REFER9_TCBASE_LSB(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG244_SW_REFER9_TCBASE_LSB_SHIFT)) & VPU_G2_SWREG244_SW_REFER9_TCBASE_LSB_MASK)
/*! @} */

/*! @name SWREG245 - Base address MSB (bits 63:32) for reference compress chrominance table index 10 */
/*! @{ */

#define VPU_G2_SWREG245_SW_REFER10_TCBASE_MSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG245_SW_REFER10_TCBASE_MSB_SHIFT (0U)
/*! SW_REFER10_TCBASE_MSB - Base address MSB (bits 63:32) for reference compress chrominance table index 10 */
#define VPU_G2_SWREG245_SW_REFER10_TCBASE_MSB(x) (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG245_SW_REFER10_TCBASE_MSB_SHIFT)) & VPU_G2_SWREG245_SW_REFER10_TCBASE_MSB_MASK)
/*! @} */

/*! @name SWREG246 - Base address LSB (bits 31:0) for reference compress chrominance table index 10 */
/*! @{ */

#define VPU_G2_SWREG246_SW_REFER10_TCBASE_LSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG246_SW_REFER10_TCBASE_LSB_SHIFT (0U)
/*! SW_REFER10_TCBASE_LSB - Base address LSB (bits 31:0) for reference compress chrominance table index 10 */
#define VPU_G2_SWREG246_SW_REFER10_TCBASE_LSB(x) (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG246_SW_REFER10_TCBASE_LSB_SHIFT)) & VPU_G2_SWREG246_SW_REFER10_TCBASE_LSB_MASK)
/*! @} */

/*! @name SWREG247 - Base address MSB (bits 63:32) for reference compress chrominance table index 11 */
/*! @{ */

#define VPU_G2_SWREG247_SW_REFER11_TCBASE_MSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG247_SW_REFER11_TCBASE_MSB_SHIFT (0U)
/*! SW_REFER11_TCBASE_MSB - Base address MSB (bits 63:32) for reference compress chrominance table index 11 */
#define VPU_G2_SWREG247_SW_REFER11_TCBASE_MSB(x) (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG247_SW_REFER11_TCBASE_MSB_SHIFT)) & VPU_G2_SWREG247_SW_REFER11_TCBASE_MSB_MASK)
/*! @} */

/*! @name SWREG248 - Base address LSB (bits 31:0) for reference compress chrominance table index 11 */
/*! @{ */

#define VPU_G2_SWREG248_SW_REFER11_TCBASE_LSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG248_SW_REFER11_TCBASE_LSB_SHIFT (0U)
/*! SW_REFER11_TCBASE_LSB - Base address LSB (bits 31:0) for reference compress chrominance table index 11 */
#define VPU_G2_SWREG248_SW_REFER11_TCBASE_LSB(x) (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG248_SW_REFER11_TCBASE_LSB_SHIFT)) & VPU_G2_SWREG248_SW_REFER11_TCBASE_LSB_MASK)
/*! @} */

/*! @name SWREG249 - Base address MSB (bits 63:32) for reference compress chrominance table index 12 */
/*! @{ */

#define VPU_G2_SWREG249_SW_REFER12_TCBASE_MSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG249_SW_REFER12_TCBASE_MSB_SHIFT (0U)
/*! SW_REFER12_TCBASE_MSB - Base address MSB (bits 63:32) for reference compress chrominance table index 12 */
#define VPU_G2_SWREG249_SW_REFER12_TCBASE_MSB(x) (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG249_SW_REFER12_TCBASE_MSB_SHIFT)) & VPU_G2_SWREG249_SW_REFER12_TCBASE_MSB_MASK)
/*! @} */

/*! @name SWREG250 - Base address LSB (bits 31:0) for reference compress chrominance table index 12 */
/*! @{ */

#define VPU_G2_SWREG250_SW_REFER12_TCBASE_LSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG250_SW_REFER12_TCBASE_LSB_SHIFT (0U)
/*! SW_REFER12_TCBASE_LSB - Base address LSB (bits 31:0) for reference compress chrominance table index 12 */
#define VPU_G2_SWREG250_SW_REFER12_TCBASE_LSB(x) (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG250_SW_REFER12_TCBASE_LSB_SHIFT)) & VPU_G2_SWREG250_SW_REFER12_TCBASE_LSB_MASK)
/*! @} */

/*! @name SWREG251 - Base address MSB (bits 63:32) for reference compress chrominance table index 13 */
/*! @{ */

#define VPU_G2_SWREG251_SW_REFER13_TCBASE_MSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG251_SW_REFER13_TCBASE_MSB_SHIFT (0U)
/*! SW_REFER13_TCBASE_MSB - Base address MSB (bits 63:32) for reference compress chrominance table index 13 */
#define VPU_G2_SWREG251_SW_REFER13_TCBASE_MSB(x) (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG251_SW_REFER13_TCBASE_MSB_SHIFT)) & VPU_G2_SWREG251_SW_REFER13_TCBASE_MSB_MASK)
/*! @} */

/*! @name SWREG252 - Base address LSB (bits 31:0) for reference compress chrominance table index 13 */
/*! @{ */

#define VPU_G2_SWREG252_SW_REFER13_TCBASE_LSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG252_SW_REFER13_TCBASE_LSB_SHIFT (0U)
/*! SW_REFER13_TCBASE_LSB - Base address LSB (bits 31:0) for reference compress chrominance table index 13 */
#define VPU_G2_SWREG252_SW_REFER13_TCBASE_LSB(x) (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG252_SW_REFER13_TCBASE_LSB_SHIFT)) & VPU_G2_SWREG252_SW_REFER13_TCBASE_LSB_MASK)
/*! @} */

/*! @name SWREG253 - Base address MSB (bits 63:32) for reference compress chrominance table index 14 */
/*! @{ */

#define VPU_G2_SWREG253_SW_REFER14_TCBASE_MSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG253_SW_REFER14_TCBASE_MSB_SHIFT (0U)
/*! SW_REFER14_TCBASE_MSB - Base address MSB (bits 63:32) for reference compress chrominance table index 14 */
#define VPU_G2_SWREG253_SW_REFER14_TCBASE_MSB(x) (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG253_SW_REFER14_TCBASE_MSB_SHIFT)) & VPU_G2_SWREG253_SW_REFER14_TCBASE_MSB_MASK)
/*! @} */

/*! @name SWREG254 - Base address LSB (bits 31:0) for reference compress chrominance table index 14 */
/*! @{ */

#define VPU_G2_SWREG254_SW_REFER14_TCBASE_LSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG254_SW_REFER14_TCBASE_LSB_SHIFT (0U)
/*! SW_REFER14_TCBASE_LSB - Base address LSB (bits 31:0) for reference compress chrominance table index 14 */
#define VPU_G2_SWREG254_SW_REFER14_TCBASE_LSB(x) (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG254_SW_REFER14_TCBASE_LSB_SHIFT)) & VPU_G2_SWREG254_SW_REFER14_TCBASE_LSB_MASK)
/*! @} */

/*! @name SWREG255 - Base address MSB (bits 63:32) for reference compress chrominance table index 15 */
/*! @{ */

#define VPU_G2_SWREG255_SW_REFER15_TCBASE_MSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG255_SW_REFER15_TCBASE_MSB_SHIFT (0U)
/*! SW_REFER15_TCBASE_MSB - Base address MSB (bits 63:32) for reference compress chrominance table index 15 */
#define VPU_G2_SWREG255_SW_REFER15_TCBASE_MSB(x) (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG255_SW_REFER15_TCBASE_MSB_SHIFT)) & VPU_G2_SWREG255_SW_REFER15_TCBASE_MSB_MASK)
/*! @} */

/*! @name SWREG256 - Base address LSB (bits 31:0) for reference compress chrominance table index 15 */
/*! @{ */

#define VPU_G2_SWREG256_SW_REFER15_TCBASE_LSB_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG256_SW_REFER15_TCBASE_LSB_SHIFT (0U)
/*! SW_REFER15_TCBASE_LSB - Base address LSB (bits 31:0) for reference compress chrominance table index 15 */
#define VPU_G2_SWREG256_SW_REFER15_TCBASE_LSB(x) (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG256_SW_REFER15_TCBASE_LSB_SHIFT)) & VPU_G2_SWREG256_SW_REFER15_TCBASE_LSB_MASK)
/*! @} */

/*! @name SWREG258 - input stream buffer length */
/*! @{ */

#define VPU_G2_SWREG258_SW_STRM_BUFFER_LEN_MASK  (0xFFFFFFFFU)
#define VPU_G2_SWREG258_SW_STRM_BUFFER_LEN_SHIFT (0U)
/*! SW_STRM_BUFFER_LEN - input stream buffer length */
#define VPU_G2_SWREG258_SW_STRM_BUFFER_LEN(x)    (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG258_SW_STRM_BUFFER_LEN_SHIFT)) & VPU_G2_SWREG258_SW_STRM_BUFFER_LEN_MASK)
/*! @} */

/*! @name SWREG259 - input stream buffer start offset */
/*! @{ */

#define VPU_G2_SWREG259_SW_STRM_START_OFFSET_MASK (0xFFFFFFFFU)
#define VPU_G2_SWREG259_SW_STRM_START_OFFSET_SHIFT (0U)
/*! SW_STRM_START_OFFSET - input stream buffer start offset */
#define VPU_G2_SWREG259_SW_STRM_START_OFFSET(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G2_SWREG259_SW_STRM_START_OFFSET_SHIFT)) & VPU_G2_SWREG259_SW_STRM_START_OFFSET_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group VPU_G2_Register_Masks */


/*!
 * @}
 */ /* end of group VPU_G2_Peripheral_Access_Layer */


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


#endif  /* PERI_VPU_G2_H_ */

