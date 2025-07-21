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
**         CMSIS Peripheral Access Layer for PCIE_PHY
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
 * @file PERI_PCIE_PHY.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for PCIE_PHY
 *
 * CMSIS Peripheral Access Layer for PCIE_PHY
 */

#if !defined(PERI_PCIE_PHY_H_)
#define PERI_PCIE_PHY_H_                         /**< Symbol preventing repeated inclusion */

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
   -- PCIE_PHY Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PCIE_PHY_Peripheral_Access_Layer PCIE_PHY Peripheral Access Layer
 * @{
 */

/** PCIE_PHY - Register Layout Typedef */
typedef struct {
  __IO uint8_t CMN_REG000;                         /**< offset: 0x0 */
       uint8_t RESERVED_0[3];
  __IO uint8_t CMN_REG001;                         /**< offset: 0x4 */
       uint8_t RESERVED_1[3];
  __IO uint8_t CMN_REG002;                         /**< offset: 0x8 */
       uint8_t RESERVED_2[3];
  __IO uint8_t CMN_REG003;                         /**< offset: 0xC */
       uint8_t RESERVED_3[3];
  __IO uint8_t CMN_REG004;                         /**< offset: 0x10 */
       uint8_t RESERVED_4[3];
  __IO uint8_t CMN_REG005;                         /**< offset: 0x14 */
       uint8_t RESERVED_5[3];
  __IO uint8_t CMN_REG006;                         /**< offset: 0x18 */
       uint8_t RESERVED_6[3];
  __IO uint8_t CMN_REG007;                         /**< offset: 0x1C */
       uint8_t RESERVED_7[3];
  __IO uint8_t CMN_REG008;                         /**< offset: 0x20 */
       uint8_t RESERVED_8[3];
  __IO uint8_t CMN_REG009;                         /**< offset: 0x24 */
       uint8_t RESERVED_9[3];
  __IO uint8_t CMN_REG00A;                         /**< offset: 0x28 */
       uint8_t RESERVED_10[3];
  __IO uint8_t CMN_REG00B;                         /**< offset: 0x2C */
       uint8_t RESERVED_11[3];
  __IO uint8_t CMN_REG00C;                         /**< offset: 0x30 */
       uint8_t RESERVED_12[3];
  __IO uint8_t CMN_REG00D;                         /**< offset: 0x34 */
       uint8_t RESERVED_13[3];
  __IO uint8_t CMN_REG00E;                         /**< offset: 0x38 */
       uint8_t RESERVED_14[3];
  __IO uint8_t CMN_REG00F;                         /**< offset: 0x3C */
       uint8_t RESERVED_15[3];
  __IO uint8_t CMN_REG010;                         /**< offset: 0x40 */
       uint8_t RESERVED_16[3];
  __IO uint8_t CMN_REG011;                         /**< offset: 0x44 */
       uint8_t RESERVED_17[3];
  __IO uint8_t CMN_REG012;                         /**< offset: 0x48 */
       uint8_t RESERVED_18[3];
  __IO uint8_t CMN_REG013;                         /**< offset: 0x4C */
       uint8_t RESERVED_19[3];
  __IO uint8_t CMN_REG014;                         /**< offset: 0x50 */
       uint8_t RESERVED_20[3];
  __IO uint8_t CMN_REG015;                         /**< offset: 0x54 */
       uint8_t RESERVED_21[3];
  __IO uint8_t CMN_REG016;                         /**< offset: 0x58 */
       uint8_t RESERVED_22[3];
  __IO uint8_t CMN_REG017;                         /**< offset: 0x5C */
       uint8_t RESERVED_23[3];
  __IO uint8_t CMN_REG018;                         /**< offset: 0x60 */
       uint8_t RESERVED_24[3];
  __IO uint8_t CMN_REG019;                         /**< offset: 0x64 */
       uint8_t RESERVED_25[3];
  __IO uint8_t CMN_REG01A;                         /**< offset: 0x68 */
       uint8_t RESERVED_26[3];
  __IO uint8_t CMN_REG01B;                         /**< offset: 0x6C */
       uint8_t RESERVED_27[3];
  __IO uint8_t CMN_REG01C;                         /**< offset: 0x70 */
       uint8_t RESERVED_28[3];
  __IO uint8_t CMN_REG01D;                         /**< offset: 0x74 */
       uint8_t RESERVED_29[3];
  __IO uint8_t CMN_REG01E;                         /**< offset: 0x78 */
       uint8_t RESERVED_30[3];
  __IO uint8_t CMN_REG01F;                         /**< offset: 0x7C */
       uint8_t RESERVED_31[3];
  __IO uint8_t CMN_REG020;                         /**< offset: 0x80 */
       uint8_t RESERVED_32[3];
  __IO uint8_t CMN_REG021;                         /**< offset: 0x84 */
       uint8_t RESERVED_33[3];
  __IO uint8_t CMN_REG022;                         /**< offset: 0x88 */
       uint8_t RESERVED_34[3];
  __IO uint8_t CMN_REG023;                         /**< offset: 0x8C */
       uint8_t RESERVED_35[3];
  __IO uint8_t CMN_REG024;                         /**< offset: 0x90 */
       uint8_t RESERVED_36[3];
  __IO uint8_t CMN_REG025;                         /**< offset: 0x94 */
       uint8_t RESERVED_37[3];
  __IO uint8_t CMN_REG026;                         /**< offset: 0x98 */
       uint8_t RESERVED_38[3];
  __IO uint8_t CMN_REG027;                         /**< offset: 0x9C */
       uint8_t RESERVED_39[3];
  __IO uint8_t CMN_REG028;                         /**< offset: 0xA0 */
       uint8_t RESERVED_40[3];
  __IO uint8_t CMN_REG029;                         /**< offset: 0xA4 */
       uint8_t RESERVED_41[3];
  __IO uint8_t CMN_REG02A;                         /**< offset: 0xA8 */
       uint8_t RESERVED_42[3];
  __IO uint8_t CMN_REG02B;                         /**< offset: 0xAC */
       uint8_t RESERVED_43[3];
  __IO uint8_t CMN_REG02C;                         /**< offset: 0xB0 */
       uint8_t RESERVED_44[3];
  __IO uint8_t CMN_REG02D;                         /**< offset: 0xB4 */
       uint8_t RESERVED_45[3];
  __IO uint8_t CMN_REG02E;                         /**< offset: 0xB8 */
       uint8_t RESERVED_46[3];
  __IO uint8_t CMN_REG02F;                         /**< offset: 0xBC */
       uint8_t RESERVED_47[3];
  __IO uint8_t CMN_REG030;                         /**< offset: 0xC0 */
       uint8_t RESERVED_48[3];
  __IO uint8_t CMN_REG031;                         /**< offset: 0xC4 */
       uint8_t RESERVED_49[3];
  __IO uint8_t CMN_REG032;                         /**< offset: 0xC8 */
       uint8_t RESERVED_50[3];
  __IO uint8_t CMN_REG033;                         /**< offset: 0xCC */
       uint8_t RESERVED_51[3];
  __IO uint8_t CMN_REG034;                         /**< offset: 0xD0 */
       uint8_t RESERVED_52[3];
  __IO uint8_t CMN_REG035;                         /**< offset: 0xD4 */
       uint8_t RESERVED_53[3];
  __IO uint8_t CMN_REG036;                         /**< offset: 0xD8 */
       uint8_t RESERVED_54[3];
  __IO uint8_t CMN_REG037;                         /**< offset: 0xDC */
       uint8_t RESERVED_55[3];
  __IO uint8_t CMN_REG038;                         /**< offset: 0xE0 */
       uint8_t RESERVED_56[3];
  __IO uint8_t CMN_REG039;                         /**< offset: 0xE4 */
       uint8_t RESERVED_57[3];
  __IO uint8_t CMN_REG03A;                         /**< offset: 0xE8 */
       uint8_t RESERVED_58[3];
  __IO uint8_t CMN_REG03B;                         /**< offset: 0xEC */
       uint8_t RESERVED_59[3];
  __IO uint8_t CMN_REG03C;                         /**< offset: 0xF0 */
       uint8_t RESERVED_60[3];
  __IO uint8_t CMN_REG03D;                         /**< offset: 0xF4 */
       uint8_t RESERVED_61[3];
  __IO uint8_t CMN_REG03E;                         /**< offset: 0xF8 */
       uint8_t RESERVED_62[3];
  __IO uint8_t CMN_REG03F;                         /**< offset: 0xFC */
       uint8_t RESERVED_63[3];
  __IO uint8_t CMN_REG040;                         /**< offset: 0x100 */
       uint8_t RESERVED_64[3];
  __IO uint8_t CMN_REG041;                         /**< offset: 0x104 */
       uint8_t RESERVED_65[3];
  __IO uint8_t CMN_REG042;                         /**< offset: 0x108 */
       uint8_t RESERVED_66[3];
  __IO uint8_t CMN_REG043;                         /**< offset: 0x10C */
       uint8_t RESERVED_67[3];
  __IO uint8_t CMN_REG044;                         /**< offset: 0x110 */
       uint8_t RESERVED_68[3];
  __IO uint8_t CMN_REG045;                         /**< offset: 0x114 */
       uint8_t RESERVED_69[3];
  __IO uint8_t CMN_REG046;                         /**< offset: 0x118 */
       uint8_t RESERVED_70[3];
  __IO uint8_t CMN_REG047;                         /**< offset: 0x11C */
       uint8_t RESERVED_71[3];
  __IO uint8_t CMN_REG048;                         /**< offset: 0x120 */
       uint8_t RESERVED_72[3];
  __IO uint8_t CMN_REG049;                         /**< offset: 0x124 */
       uint8_t RESERVED_73[3];
  __IO uint8_t CMN_REG04A;                         /**< offset: 0x128 */
       uint8_t RESERVED_74[3];
  __IO uint8_t CMN_REG04B;                         /**< offset: 0x12C */
       uint8_t RESERVED_75[3];
  __IO uint8_t CMN_REG04C;                         /**< offset: 0x130 */
       uint8_t RESERVED_76[3];
  __IO uint8_t CMN_REG04D;                         /**< offset: 0x134 */
       uint8_t RESERVED_77[3];
  __IO uint8_t CMN_REG04E;                         /**< offset: 0x138 */
       uint8_t RESERVED_78[3];
  __IO uint8_t CMN_REG04F;                         /**< offset: 0x13C */
       uint8_t RESERVED_79[3];
  __IO uint8_t CMN_REG050;                         /**< offset: 0x140 */
       uint8_t RESERVED_80[3];
  __IO uint8_t CMN_REG051;                         /**< offset: 0x144 */
       uint8_t RESERVED_81[3];
  __IO uint8_t CMN_REG052;                         /**< offset: 0x148 */
       uint8_t RESERVED_82[3];
  __IO uint8_t CMN_REG053;                         /**< offset: 0x14C */
       uint8_t RESERVED_83[3];
  __IO uint8_t CMN_REG054;                         /**< offset: 0x150 */
       uint8_t RESERVED_84[3];
  __IO uint8_t CMN_REG055;                         /**< offset: 0x154 */
       uint8_t RESERVED_85[3];
  __IO uint8_t CMN_REG056;                         /**< offset: 0x158 */
       uint8_t RESERVED_86[3];
  __IO uint8_t CMN_REG057;                         /**< offset: 0x15C */
       uint8_t RESERVED_87[3];
  __IO uint8_t CMN_REG058;                         /**< offset: 0x160 */
       uint8_t RESERVED_88[3];
  __IO uint8_t CMN_REG059;                         /**< offset: 0x164 */
       uint8_t RESERVED_89[3];
  __IO uint8_t CMN_REG05A;                         /**< offset: 0x168 */
       uint8_t RESERVED_90[3];
  __IO uint8_t CMN_REG05B;                         /**< offset: 0x16C */
       uint8_t RESERVED_91[3];
  __IO uint8_t CMN_REG05C;                         /**< offset: 0x170 */
       uint8_t RESERVED_92[3];
  __IO uint8_t CMN_REG05D;                         /**< offset: 0x174 */
       uint8_t RESERVED_93[3];
  __IO uint8_t CMN_REG05E;                         /**< offset: 0x178 */
       uint8_t RESERVED_94[3];
  __IO uint8_t CMN_REG05F;                         /**< offset: 0x17C */
       uint8_t RESERVED_95[3];
  __IO uint8_t CMN_REG060;                         /**< offset: 0x180 */
       uint8_t RESERVED_96[3];
  __IO uint8_t CMN_REG061;                         /**< offset: 0x184 */
       uint8_t RESERVED_97[3];
  __IO uint8_t CMN_REG062;                         /**< offset: 0x188 */
       uint8_t RESERVED_98[3];
  __IO uint8_t CMN_REG063;                         /**< offset: 0x18C */
       uint8_t RESERVED_99[3];
  __IO uint8_t CMN_REG064;                         /**< offset: 0x190 */
       uint8_t RESERVED_100[3];
  __IO uint8_t CMN_REG065;                         /**< offset: 0x194 */
       uint8_t RESERVED_101[3];
  __IO uint8_t CMN_REG066;                         /**< offset: 0x198 */
       uint8_t RESERVED_102[3];
  __IO uint8_t CMN_REG067;                         /**< offset: 0x19C */
       uint8_t RESERVED_103[3];
  __IO uint8_t CMN_REG068;                         /**< offset: 0x1A0 */
       uint8_t RESERVED_104[3];
  __IO uint8_t CMN_REG069;                         /**< offset: 0x1A4 */
       uint8_t RESERVED_105[3];
  __IO uint8_t CMN_REG06A;                         /**< offset: 0x1A8 */
       uint8_t RESERVED_106[3];
  __IO uint8_t CMN_REG06B;                         /**< offset: 0x1AC */
       uint8_t RESERVED_107[3];
  __IO uint8_t CMN_REG06C;                         /**< offset: 0x1B0 */
       uint8_t RESERVED_108[3];
  __IO uint8_t CMN_REG06D;                         /**< offset: 0x1B4 */
       uint8_t RESERVED_109[3];
  __IO uint8_t CMN_REG06E;                         /**< offset: 0x1B8 */
       uint8_t RESERVED_110[3];
  __IO uint8_t CMN_REG06F;                         /**< offset: 0x1BC */
       uint8_t RESERVED_111[3];
  __IO uint8_t CMN_REG070;                         /**< offset: 0x1C0 */
       uint8_t RESERVED_112[3];
  __IO uint8_t CMN_REG071;                         /**< offset: 0x1C4 */
       uint8_t RESERVED_113[3];
  __IO uint8_t CMN_REG072;                         /**< offset: 0x1C8 */
       uint8_t RESERVED_114[3];
  __IO uint8_t CMN_REG073;                         /**< offset: 0x1CC */
       uint8_t RESERVED_115[3];
  __IO uint8_t CMN_REG074;                         /**< offset: 0x1D0 */
       uint8_t RESERVED_116[3];
  __IO uint8_t CMN_REG075;                         /**< offset: 0x1D4 */
       uint8_t RESERVED_117[43];
  __IO uint8_t CMN_REG076;                         /**< offset: 0x200 */
       uint8_t RESERVED_118[3];
  __IO uint8_t CMN_REG077;                         /**< offset: 0x204 */
       uint8_t RESERVED_119[3];
  __IO uint8_t CMN_REG078;                         /**< offset: 0x208 */
       uint8_t RESERVED_120[3];
  __IO uint8_t CMN_REG079;                         /**< offset: 0x20C */
       uint8_t RESERVED_121[3];
  __IO uint8_t CMN_REG080;                         /**< offset: 0x210 */
       uint8_t RESERVED_122[3];
  __IO uint8_t CMN_REG081;                         /**< offset: 0x214 */
       uint8_t RESERVED_123[3];
  __IO uint8_t CMN_REG082;                         /**< offset: 0x218 */
       uint8_t RESERVED_124[487];
  __IO uint8_t TRSV_REG000;                        /**< offset: 0x400 */
       uint8_t RESERVED_125[3];
  __IO uint8_t TRSV_REG001;                        /**< offset: 0x404 */
       uint8_t RESERVED_126[3];
  __IO uint8_t TRSV_REG002;                        /**< offset: 0x408 */
       uint8_t RESERVED_127[3];
  __IO uint8_t TRSV_REG003;                        /**< offset: 0x40C */
       uint8_t RESERVED_128[3];
  __IO uint8_t TRSV_REG004;                        /**< offset: 0x410 */
       uint8_t RESERVED_129[3];
  __IO uint8_t TRSV_REG005;                        /**< offset: 0x414 */
       uint8_t RESERVED_130[3];
  __IO uint8_t TRSV_REG006;                        /**< offset: 0x418 */
       uint8_t RESERVED_131[3];
  __IO uint8_t TRSV_REG007;                        /**< offset: 0x41C */
       uint8_t RESERVED_132[3];
  __IO uint8_t TRSV_REG008;                        /**< offset: 0x420 */
       uint8_t RESERVED_133[3];
  __IO uint8_t TRSV_REG009;                        /**< offset: 0x424 */
       uint8_t RESERVED_134[3];
  __IO uint8_t TRSV_REG00A;                        /**< offset: 0x428 */
       uint8_t RESERVED_135[3];
  __IO uint8_t TRSV_REG00B;                        /**< offset: 0x42C */
       uint8_t RESERVED_136[3];
  __IO uint8_t TRSV_REG00C;                        /**< offset: 0x430 */
       uint8_t RESERVED_137[3];
  __IO uint8_t TRSV_REG00D;                        /**< offset: 0x434 */
       uint8_t RESERVED_138[3];
  __IO uint8_t TRSV_REG00E;                        /**< offset: 0x438 */
       uint8_t RESERVED_139[3];
  __IO uint8_t TRSV_REG00F;                        /**< offset: 0x43C */
       uint8_t RESERVED_140[3];
  __IO uint8_t TRSV_REG010;                        /**< offset: 0x440 */
       uint8_t RESERVED_141[3];
  __IO uint8_t TRSV_REG011;                        /**< offset: 0x444 */
       uint8_t RESERVED_142[3];
  __IO uint8_t TRSV_REG012;                        /**< offset: 0x448 */
       uint8_t RESERVED_143[3];
  __IO uint8_t TRSV_REG013;                        /**< offset: 0x44C */
       uint8_t RESERVED_144[3];
  __IO uint8_t TRSV_REG014;                        /**< offset: 0x450 */
       uint8_t RESERVED_145[3];
  __IO uint8_t TRSV_REG015;                        /**< offset: 0x454 */
       uint8_t RESERVED_146[3];
  __IO uint8_t TRSV_REG016;                        /**< offset: 0x458 */
       uint8_t RESERVED_147[3];
  __IO uint8_t TRSV_REG017;                        /**< offset: 0x45C */
       uint8_t RESERVED_148[3];
  __IO uint8_t TRSV_REG018;                        /**< offset: 0x460 */
       uint8_t RESERVED_149[3];
  __IO uint8_t TRSV_REG019;                        /**< offset: 0x464 */
       uint8_t RESERVED_150[3];
  __IO uint8_t TRSV_REG01A;                        /**< offset: 0x468 */
       uint8_t RESERVED_151[3];
  __IO uint8_t TRSV_REG01B;                        /**< offset: 0x46C */
       uint8_t RESERVED_152[3];
  __IO uint8_t TRSV_REG01C;                        /**< offset: 0x470 */
       uint8_t RESERVED_153[3];
  __IO uint8_t TRSV_REG01D;                        /**< offset: 0x474 */
       uint8_t RESERVED_154[3];
  __IO uint8_t TRSV_REG01E;                        /**< offset: 0x478 */
       uint8_t RESERVED_155[3];
  __IO uint8_t TRSV_REG01F;                        /**< offset: 0x47C */
       uint8_t RESERVED_156[3];
  __IO uint8_t TRSV_REG020;                        /**< offset: 0x480 */
       uint8_t RESERVED_157[3];
  __IO uint8_t TRSV_REG021;                        /**< offset: 0x484 */
       uint8_t RESERVED_158[3];
  __IO uint8_t TRSV_REG022;                        /**< offset: 0x488 */
       uint8_t RESERVED_159[3];
  __IO uint8_t TRSV_REG023;                        /**< offset: 0x48C */
       uint8_t RESERVED_160[3];
  __IO uint8_t TRSV_REG024;                        /**< offset: 0x490 */
       uint8_t RESERVED_161[3];
  __IO uint8_t TRSV_REG025;                        /**< offset: 0x494 */
       uint8_t RESERVED_162[3];
  __IO uint8_t TRSV_REG026;                        /**< offset: 0x498 */
       uint8_t RESERVED_163[3];
  __IO uint8_t TRSV_REG027;                        /**< offset: 0x49C */
       uint8_t RESERVED_164[3];
  __IO uint8_t TRSV_REG028;                        /**< offset: 0x4A0 */
       uint8_t RESERVED_165[3];
  __IO uint8_t TRSV_REG029;                        /**< offset: 0x4A4 */
       uint8_t RESERVED_166[3];
  __IO uint8_t TRSV_REG02A;                        /**< offset: 0x4A8 */
       uint8_t RESERVED_167[3];
  __IO uint8_t TRSV_REG02B;                        /**< offset: 0x4AC */
       uint8_t RESERVED_168[3];
  __IO uint8_t TRSV_REG02C;                        /**< offset: 0x4B0 */
       uint8_t RESERVED_169[3];
  __IO uint8_t TRSV_REG02D;                        /**< offset: 0x4B4 */
       uint8_t RESERVED_170[3];
  __IO uint8_t TRSV_REG02E;                        /**< offset: 0x4B8 */
       uint8_t RESERVED_171[3];
  __IO uint8_t TRSV_REG02F;                        /**< offset: 0x4BC */
       uint8_t RESERVED_172[3];
  __IO uint8_t TRSV_REG030;                        /**< offset: 0x4C0 */
       uint8_t RESERVED_173[3];
  __IO uint8_t TRSV_REG031;                        /**< offset: 0x4C4 */
       uint8_t RESERVED_174[3];
  __IO uint8_t TRSV_REG032;                        /**< offset: 0x4C8 */
       uint8_t RESERVED_175[3];
  __IO uint8_t TRSV_REG033;                        /**< offset: 0x4CC */
       uint8_t RESERVED_176[3];
  __IO uint8_t TRSV_REG034;                        /**< offset: 0x4D0 */
       uint8_t RESERVED_177[3];
  __IO uint8_t TRSV_REG035;                        /**< offset: 0x4D4 */
       uint8_t RESERVED_178[3];
  __IO uint8_t TRSV_REG036;                        /**< offset: 0x4D8 */
       uint8_t RESERVED_179[3];
  __IO uint8_t TRSV_REG037;                        /**< offset: 0x4DC */
       uint8_t RESERVED_180[3];
  __IO uint8_t TRSV_REG038;                        /**< offset: 0x4E0 */
       uint8_t RESERVED_181[3];
  __IO uint8_t TRSV_REG039;                        /**< offset: 0x4E4 */
       uint8_t RESERVED_182[3];
  __IO uint8_t TRSV_REG03A;                        /**< offset: 0x4E8 */
       uint8_t RESERVED_183[3];
  __IO uint8_t TRSV_REG03B;                        /**< offset: 0x4EC */
       uint8_t RESERVED_184[3];
  __IO uint8_t TRSV_REG03C;                        /**< offset: 0x4F0 */
       uint8_t RESERVED_185[3];
  __IO uint8_t TRSV_REG03D;                        /**< offset: 0x4F4 */
       uint8_t RESERVED_186[3];
  __IO uint8_t TRSV_REG03E;                        /**< offset: 0x4F8 */
       uint8_t RESERVED_187[3];
  __IO uint8_t TRSV_REG03F;                        /**< offset: 0x4FC */
       uint8_t RESERVED_188[3];
  __IO uint8_t TRSV_REG040;                        /**< offset: 0x500 */
       uint8_t RESERVED_189[3];
  __IO uint8_t TRSV_REG041;                        /**< offset: 0x504 */
       uint8_t RESERVED_190[3];
  __IO uint8_t TRSV_REG042;                        /**< offset: 0x508 */
       uint8_t RESERVED_191[3];
  __IO uint8_t TRSV_REG043;                        /**< offset: 0x50C */
       uint8_t RESERVED_192[3];
  __IO uint8_t TRSV_REG044;                        /**< offset: 0x510 */
       uint8_t RESERVED_193[3];
  __IO uint8_t TRSV_REG045;                        /**< offset: 0x514 */
       uint8_t RESERVED_194[3];
  __IO uint8_t TRSV_REG046;                        /**< offset: 0x518 */
       uint8_t RESERVED_195[3];
  __IO uint8_t TRSV_REG047;                        /**< offset: 0x51C */
       uint8_t RESERVED_196[3];
  __IO uint8_t TRSV_REG048;                        /**< offset: 0x520 */
       uint8_t RESERVED_197[3];
  __IO uint8_t TRSV_REG049;                        /**< offset: 0x524 */
       uint8_t RESERVED_198[3];
  __IO uint8_t TRSV_REG04A;                        /**< offset: 0x528 */
       uint8_t RESERVED_199[3];
  __IO uint8_t TRSV_REG04B;                        /**< offset: 0x52C */
       uint8_t RESERVED_200[3];
  __IO uint8_t TRSV_REG04C;                        /**< offset: 0x530 */
       uint8_t RESERVED_201[3];
  __IO uint8_t TRSV_REG04D;                        /**< offset: 0x534 */
       uint8_t RESERVED_202[3];
  __IO uint8_t TRSV_REG04E;                        /**< offset: 0x538 */
       uint8_t RESERVED_203[3];
  __IO uint8_t TRSV_REG04F;                        /**< offset: 0x53C */
       uint8_t RESERVED_204[3];
  __IO uint8_t TRSV_REG050;                        /**< offset: 0x540 */
       uint8_t RESERVED_205[3];
  __IO uint8_t TRSV_REG051;                        /**< offset: 0x544 */
       uint8_t RESERVED_206[3];
  __IO uint8_t TRSV_REG052;                        /**< offset: 0x548 */
       uint8_t RESERVED_207[3];
  __IO uint8_t TRSV_REG053;                        /**< offset: 0x54C */
       uint8_t RESERVED_208[3];
  __IO uint8_t TRSV_REG054;                        /**< offset: 0x550 */
       uint8_t RESERVED_209[3];
  __IO uint8_t TRSV_REG055;                        /**< offset: 0x554 */
       uint8_t RESERVED_210[3];
  __IO uint8_t TRSV_REG056;                        /**< offset: 0x558 */
       uint8_t RESERVED_211[3];
  __IO uint8_t TRSV_REG057;                        /**< offset: 0x55C */
       uint8_t RESERVED_212[3];
  __IO uint8_t TRSV_REG058;                        /**< offset: 0x560 */
       uint8_t RESERVED_213[3];
  __IO uint8_t TRSV_REG059;                        /**< offset: 0x564 */
       uint8_t RESERVED_214[3];
  __IO uint8_t TRSV_REG05A;                        /**< offset: 0x568 */
       uint8_t RESERVED_215[3];
  __IO uint8_t TRSV_REG05B;                        /**< offset: 0x56C */
       uint8_t RESERVED_216[3];
  __IO uint8_t TRSV_REG05C;                        /**< offset: 0x570 */
       uint8_t RESERVED_217[3];
  __IO uint8_t TRSV_REG05D;                        /**< offset: 0x574 */
       uint8_t RESERVED_218[3];
  __IO uint8_t TRSV_REG05E;                        /**< offset: 0x578 */
       uint8_t RESERVED_219[3];
  __IO uint8_t TRSV_REG05F;                        /**< offset: 0x57C */
       uint8_t RESERVED_220[3];
  __IO uint8_t TRSV_REG060;                        /**< offset: 0x580 */
       uint8_t RESERVED_221[3];
  __IO uint8_t TRSV_REG061;                        /**< offset: 0x584 */
       uint8_t RESERVED_222[3];
  __IO uint8_t TRSV_REG062;                        /**< offset: 0x588 */
       uint8_t RESERVED_223[3];
  __IO uint8_t TRSV_REG063;                        /**< offset: 0x58C */
       uint8_t RESERVED_224[3];
  __IO uint8_t TRSV_REG064;                        /**< offset: 0x590 */
       uint8_t RESERVED_225[3];
  __IO uint8_t TRSV_REG065;                        /**< offset: 0x594 */
       uint8_t RESERVED_226[3];
  __IO uint8_t TRSV_REG066;                        /**< offset: 0x598 */
       uint8_t RESERVED_227[3];
  __IO uint8_t TRSV_REG067;                        /**< offset: 0x59C */
       uint8_t RESERVED_228[3];
  __IO uint8_t TRSV_REG068;                        /**< offset: 0x5A0 */
       uint8_t RESERVED_229[3];
  __IO uint8_t TRSV_REG069;                        /**< offset: 0x5A4 */
       uint8_t RESERVED_230[3];
  __IO uint8_t TRSV_REG06A;                        /**< offset: 0x5A8 */
       uint8_t RESERVED_231[3];
  __IO uint8_t TRSV_REG06B;                        /**< offset: 0x5AC */
       uint8_t RESERVED_232[3];
  __IO uint8_t TRSV_REG06C;                        /**< offset: 0x5B0 */
       uint8_t RESERVED_233[3];
  __IO uint8_t TRSV_REG06D;                        /**< offset: 0x5B4 */
       uint8_t RESERVED_234[3];
  __IO uint8_t TRSV_REG06E;                        /**< offset: 0x5B8 */
       uint8_t RESERVED_235[3];
  __IO uint8_t TRSV_REG06F;                        /**< offset: 0x5BC */
       uint8_t RESERVED_236[3];
  __IO uint8_t TRSV_REG070;                        /**< offset: 0x5C0 */
       uint8_t RESERVED_237[3];
  __IO uint8_t TRSV_REG071;                        /**< offset: 0x5C4 */
       uint8_t RESERVED_238[3];
  __IO uint8_t TRSV_REG072;                        /**< offset: 0x5C8 */
       uint8_t RESERVED_239[3];
  __IO uint8_t TRSV_REG073;                        /**< offset: 0x5CC */
       uint8_t RESERVED_240[3];
  __IO uint8_t TRSV_REG074;                        /**< offset: 0x5D0 */
       uint8_t RESERVED_241[3];
  __IO uint8_t TRSV_REG075;                        /**< offset: 0x5D4 */
       uint8_t RESERVED_242[3];
  __IO uint8_t TRSV_REG076;                        /**< offset: 0x5D8 */
       uint8_t RESERVED_243[3];
  __IO uint8_t TRSV_REG077;                        /**< offset: 0x5DC */
       uint8_t RESERVED_244[3];
  __IO uint8_t TRSV_REG078;                        /**< offset: 0x5E0 */
       uint8_t RESERVED_245[3];
  __IO uint8_t TRSV_REG079;                        /**< offset: 0x5E4 */
       uint8_t RESERVED_246[3];
  __IO uint8_t TRSV_REG07A;                        /**< offset: 0x5E8 */
       uint8_t RESERVED_247[3];
  __IO uint8_t TRSV_REG07B;                        /**< offset: 0x5EC */
       uint8_t RESERVED_248[3];
  __IO uint8_t TRSV_REG07C;                        /**< offset: 0x5F0 */
       uint8_t RESERVED_249[3];
  __IO uint8_t TRSV_REG07D;                        /**< offset: 0x5F4 */
       uint8_t RESERVED_250[3];
  __IO uint8_t TRSV_REG07E;                        /**< offset: 0x5F8 */
       uint8_t RESERVED_251[3];
  __IO uint8_t TRSV_REG07F;                        /**< offset: 0x5FC */
       uint8_t RESERVED_252[3];
  __IO uint8_t TRSV_REG080;                        /**< offset: 0x600 */
       uint8_t RESERVED_253[3];
  __IO uint8_t TRSV_REG081;                        /**< offset: 0x604 */
       uint8_t RESERVED_254[3];
  __IO uint8_t TRSV_REG082;                        /**< offset: 0x608 */
       uint8_t RESERVED_255[3];
  __IO uint8_t TRSV_REG083;                        /**< offset: 0x60C */
       uint8_t RESERVED_256[3];
  __IO uint8_t TRSV_REG084;                        /**< offset: 0x610 */
       uint8_t RESERVED_257[3];
  __IO uint8_t TRSV_REG085;                        /**< offset: 0x614 */
       uint8_t RESERVED_258[3];
  __IO uint8_t TRSV_REG086;                        /**< offset: 0x618 */
       uint8_t RESERVED_259[3];
  __IO uint8_t TRSV_REG087;                        /**< offset: 0x61C */
       uint8_t RESERVED_260[3];
  __IO uint8_t TRSV_REG088;                        /**< offset: 0x620 */
       uint8_t RESERVED_261[3];
  __IO uint8_t TRSV_REG089;                        /**< offset: 0x624 */
       uint8_t RESERVED_262[3];
  __IO uint8_t TRSV_REG08A;                        /**< offset: 0x628 */
       uint8_t RESERVED_263[3];
  __IO uint8_t TRSV_REG08B;                        /**< offset: 0x62C */
       uint8_t RESERVED_264[3];
  __IO uint8_t TRSV_REG08C;                        /**< offset: 0x630 */
       uint8_t RESERVED_265[3];
  __IO uint8_t TRSV_REG08D;                        /**< offset: 0x634 */
       uint8_t RESERVED_266[3];
  __IO uint8_t TRSV_REG08E;                        /**< offset: 0x638 */
       uint8_t RESERVED_267[3];
  __IO uint8_t TRSV_REG08F;                        /**< offset: 0x63C */
       uint8_t RESERVED_268[3];
  __IO uint8_t TRSV_REG090;                        /**< offset: 0x640 */
       uint8_t RESERVED_269[3];
  __IO uint8_t TRSV_REG091;                        /**< offset: 0x644 */
       uint8_t RESERVED_270[3];
  __IO uint8_t TRSV_REG092;                        /**< offset: 0x648 */
       uint8_t RESERVED_271[3];
  __IO uint8_t TRSV_REG093;                        /**< offset: 0x64C */
       uint8_t RESERVED_272[3];
  __IO uint8_t TRSV_REG094;                        /**< offset: 0x650 */
       uint8_t RESERVED_273[3];
  __IO uint8_t TRSV_REG095;                        /**< offset: 0x654 */
       uint8_t RESERVED_274[3];
  __IO uint8_t TRSV_REG096;                        /**< offset: 0x658 */
       uint8_t RESERVED_275[3];
  __IO uint8_t TRSV_REG097;                        /**< offset: 0x65C */
       uint8_t RESERVED_276[3];
  __IO uint8_t TRSV_REG098;                        /**< offset: 0x660 */
       uint8_t RESERVED_277[3];
  __IO uint8_t TRSV_REG099;                        /**< offset: 0x664 */
       uint8_t RESERVED_278[3];
  __IO uint8_t TRSV_REG09A;                        /**< offset: 0x668 */
       uint8_t RESERVED_279[3];
  __IO uint8_t TRSV_REG09B;                        /**< offset: 0x66C */
       uint8_t RESERVED_280[3];
  __IO uint8_t TRSV_REG09C;                        /**< offset: 0x670 */
       uint8_t RESERVED_281[3];
  __IO uint8_t TRSV_REG09D;                        /**< offset: 0x674 */
       uint8_t RESERVED_282[3];
  __IO uint8_t TRSV_REG09E;                        /**< offset: 0x678 */
       uint8_t RESERVED_283[3];
  __IO uint8_t TRSV_REG09F;                        /**< offset: 0x67C */
       uint8_t RESERVED_284[3];
  __IO uint8_t TRSV_REG0A0;                        /**< offset: 0x680 */
       uint8_t RESERVED_285[3];
  __IO uint8_t TRSV_REG0A1;                        /**< offset: 0x684 */
       uint8_t RESERVED_286[3];
  __IO uint8_t TRSV_REG0A2;                        /**< offset: 0x688 */
       uint8_t RESERVED_287[3];
  __IO uint8_t TRSV_REG0A3;                        /**< offset: 0x68C */
       uint8_t RESERVED_288[3];
  __IO uint8_t TRSV_REG0A4;                        /**< offset: 0x690 */
       uint8_t RESERVED_289[3];
  __IO uint8_t TRSV_REG0A5;                        /**< offset: 0x694 */
       uint8_t RESERVED_290[3];
  __IO uint8_t TRSV_REG0A6;                        /**< offset: 0x698 */
       uint8_t RESERVED_291[3];
  __IO uint8_t TRSV_REG0A7;                        /**< offset: 0x69C */
       uint8_t RESERVED_292[3];
  __IO uint8_t TRSV_REG0A8;                        /**< offset: 0x6A0 */
       uint8_t RESERVED_293[3];
  __IO uint8_t TRSV_REG0A9;                        /**< offset: 0x6A4 */
       uint8_t RESERVED_294[3];
  __IO uint8_t TRSV_REG0AA;                        /**< offset: 0x6A8 */
       uint8_t RESERVED_295[3];
  __IO uint8_t TRSV_REG0AB;                        /**< offset: 0x6AC */
       uint8_t RESERVED_296[3];
  __IO uint8_t TRSV_REG0AC;                        /**< offset: 0x6B0 */
       uint8_t RESERVED_297[3];
  __IO uint8_t TRSV_REG0AD;                        /**< offset: 0x6B4 */
       uint8_t RESERVED_298[3];
  __IO uint8_t TRSV_REG0AE;                        /**< offset: 0x6B8 */
       uint8_t RESERVED_299[3];
  __IO uint8_t TRSV_REG0AF;                        /**< offset: 0x6BC */
       uint8_t RESERVED_300[3];
  __IO uint8_t TRSV_REG0B0;                        /**< offset: 0x6C0 */
       uint8_t RESERVED_301[3];
  __IO uint8_t TRSV_REG0B1;                        /**< offset: 0x6C4 */
       uint8_t RESERVED_302[3];
  __IO uint8_t TRSV_REG0B2;                        /**< offset: 0x6C8 */
       uint8_t RESERVED_303[3];
  __IO uint8_t TRSV_REG0B3;                        /**< offset: 0x6CC */
       uint8_t RESERVED_304[3];
  __IO uint8_t TRSV_REG0B4;                        /**< offset: 0x6D0 */
       uint8_t RESERVED_305[3];
  __IO uint8_t TRSV_REG0B5;                        /**< offset: 0x6D4 */
       uint8_t RESERVED_306[3];
  __IO uint8_t TRSV_REG0B6;                        /**< offset: 0x6D8 */
       uint8_t RESERVED_307[3];
  __IO uint8_t TRSV_REG0B7;                        /**< offset: 0x6DC */
       uint8_t RESERVED_308[3];
  __IO uint8_t TRSV_REG0B8;                        /**< offset: 0x6E0 */
       uint8_t RESERVED_309[3];
  __IO uint8_t TRSV_REG0B9;                        /**< offset: 0x6E4 */
       uint8_t RESERVED_310[3];
  __IO uint8_t TRSV_REG0BA;                        /**< offset: 0x6E8 */
       uint8_t RESERVED_311[3];
  __IO uint8_t TRSV_REG0BB;                        /**< offset: 0x6EC */
       uint8_t RESERVED_312[3];
  __IO uint8_t TRSV_REG0BC;                        /**< offset: 0x6F0 */
       uint8_t RESERVED_313[3];
  __IO uint8_t TRSV_REG0BD;                        /**< offset: 0x6F4 */
       uint8_t RESERVED_314[3];
  __IO uint8_t TRSV_REG0BE;                        /**< offset: 0x6F8 */
       uint8_t RESERVED_315[3];
  __IO uint8_t TRSV_REG0BF;                        /**< offset: 0x6FC */
       uint8_t RESERVED_316[3];
  __IO uint8_t TRSV_REG0C0;                        /**< offset: 0x700 */
       uint8_t RESERVED_317[3];
  __IO uint8_t TRSV_REG0C1;                        /**< offset: 0x704 */
       uint8_t RESERVED_318[3];
  __IO uint8_t TRSV_REG0C2;                        /**< offset: 0x708 */
       uint8_t RESERVED_319[3];
  __IO uint8_t TRSV_REG0C3;                        /**< offset: 0x70C */
       uint8_t RESERVED_320[3];
  __IO uint8_t TRSV_REG0C4;                        /**< offset: 0x710 */
       uint8_t RESERVED_321[3];
  __IO uint8_t TRSV_REG0C5;                        /**< offset: 0x714 */
       uint8_t RESERVED_322[3];
  __IO uint8_t TRSV_REG0C6;                        /**< offset: 0x718 */
       uint8_t RESERVED_323[3];
  __IO uint8_t TRSV_REG0C7;                        /**< offset: 0x71C */
       uint8_t RESERVED_324[3];
  __IO uint8_t TRSV_REG0C8;                        /**< offset: 0x720 */
       uint8_t RESERVED_325[3];
  __IO uint8_t TRSV_REG0C9;                        /**< offset: 0x724 */
       uint8_t RESERVED_326[3];
  __IO uint8_t TRSV_REG0CA;                        /**< offset: 0x728 */
       uint8_t RESERVED_327[3];
  __IO uint8_t TRSV_REG0CB;                        /**< offset: 0x72C */
       uint8_t RESERVED_328[3];
  __IO uint8_t TRSV_REG0CC;                        /**< offset: 0x730 */
       uint8_t RESERVED_329[3];
  __IO uint8_t TRSV_REG0CD;                        /**< offset: 0x734 */
       uint8_t RESERVED_330[3];
  __IO uint8_t TRSV_REG0CE;                        /**< offset: 0x738 */
       uint8_t RESERVED_331[3];
  __IO uint8_t TRSV_REG0CF;                        /**< offset: 0x73C */
       uint8_t RESERVED_332[3];
  __IO uint8_t TRSV_REG0D0;                        /**< offset: 0x740 */
       uint8_t RESERVED_333[3];
  __IO uint8_t TRSV_REG0D1;                        /**< offset: 0x744 */
       uint8_t RESERVED_334[3];
  __IO uint8_t TRSV_REG0D2;                        /**< offset: 0x748 */
       uint8_t RESERVED_335[3];
  __IO uint8_t TRSV_REG0D3;                        /**< offset: 0x74C */
       uint8_t RESERVED_336[3];
  __IO uint8_t TRSV_REG0D4;                        /**< offset: 0x750 */
       uint8_t RESERVED_337[3];
  __IO uint8_t TRSV_REG0D5;                        /**< offset: 0x754 */
       uint8_t RESERVED_338[3];
  __IO uint8_t TRSV_REG0D6;                        /**< offset: 0x758 */
       uint8_t RESERVED_339[3];
  __IO uint8_t TRSV_REG0D7;                        /**< offset: 0x75C */
       uint8_t RESERVED_340[3];
  __IO uint8_t TRSV_REG0D8;                        /**< offset: 0x760 */
       uint8_t RESERVED_341[3];
  __IO uint8_t TRSV_REG0D9;                        /**< offset: 0x764 */
       uint8_t RESERVED_342[3];
  __IO uint8_t TRSV_REG0DA;                        /**< offset: 0x768 */
       uint8_t RESERVED_343[3];
  __IO uint8_t TRSV_REG0DB;                        /**< offset: 0x76C */
       uint8_t RESERVED_344[3];
  __IO uint8_t TRSV_REG0DC;                        /**< offset: 0x770 */
       uint8_t RESERVED_345[3];
  __IO uint8_t TRSV_REG0DD;                        /**< offset: 0x774 */
       uint8_t RESERVED_346[3];
  __IO uint8_t TRSV_REG0DE;                        /**< offset: 0x778 */
       uint8_t RESERVED_347[3];
  __IO uint8_t TRSV_REG0DF;                        /**< offset: 0x77C */
       uint8_t RESERVED_348[3];
  __IO uint8_t TRSV_REG0E0;                        /**< offset: 0x780 */
       uint8_t RESERVED_349[3];
  __IO uint8_t TRSV_REG0E1;                        /**< offset: 0x784 */
       uint8_t RESERVED_350[3];
  __IO uint8_t TRSV_REG0E2;                        /**< offset: 0x788 */
       uint8_t RESERVED_351[3];
  __IO uint8_t TRSV_REG0E3;                        /**< offset: 0x78C */
       uint8_t RESERVED_352[3];
  __IO uint8_t TRSV_REG0E4;                        /**< offset: 0x790 */
       uint8_t RESERVED_353[3];
  __IO uint8_t TRSV_REG0E5;                        /**< offset: 0x794 */
       uint8_t RESERVED_354[3];
  __IO uint8_t TRSV_REG0E6;                        /**< offset: 0x798 */
       uint8_t RESERVED_355[3];
  __IO uint8_t TRSV_REG0E7;                        /**< offset: 0x79C */
       uint8_t RESERVED_356[3];
  __IO uint8_t TRSV_REG0E8;                        /**< offset: 0x7A0 */
       uint8_t RESERVED_357[3];
  __IO uint8_t TRSV_REG0E9;                        /**< offset: 0x7A4 */
       uint8_t RESERVED_358[3];
  __IO uint8_t TRSV_REG0EA;                        /**< offset: 0x7A8 */
       uint8_t RESERVED_359[3];
  __IO uint8_t TRSV_REG0EB;                        /**< offset: 0x7AC */
       uint8_t RESERVED_360[3];
  __IO uint8_t TRSV_REG0EC;                        /**< offset: 0x7B0 */
       uint8_t RESERVED_361[3];
  __IO uint8_t TRSV_REG0ED;                        /**< offset: 0x7B4 */
       uint8_t RESERVED_362[3];
  __IO uint8_t TRSV_REG0EE;                        /**< offset: 0x7B8 */
       uint8_t RESERVED_363[3];
  __IO uint8_t TRSV_REG0EF;                        /**< offset: 0x7BC */
       uint8_t RESERVED_364[3];
  __IO uint8_t TRSV_REG0F0;                        /**< offset: 0x7C0 */
       uint8_t RESERVED_365[3];
  __IO uint8_t TRSV_REG0F1;                        /**< offset: 0x7C4 */
       uint8_t RESERVED_366[3];
  __IO uint8_t TRSV_REG0F2;                        /**< offset: 0x7C8 */
       uint8_t RESERVED_367[3];
  __IO uint8_t TRSV_REG0F3;                        /**< offset: 0x7CC */
       uint8_t RESERVED_368[3];
  __IO uint8_t TRSV_REG0F4;                        /**< offset: 0x7D0 */
       uint8_t RESERVED_369[3];
  __IO uint8_t TRSV_REG0F5;                        /**< offset: 0x7D4 */
       uint8_t RESERVED_370[3];
  __IO uint8_t TRSV_REG0F6;                        /**< offset: 0x7D8 */
       uint8_t RESERVED_371[3];
  __IO uint8_t TRSV_REG0F7;                        /**< offset: 0x7DC */
       uint8_t RESERVED_372[3];
  __IO uint8_t TRSV_REG0F8;                        /**< offset: 0x7E0 */
       uint8_t RESERVED_373[3];
  __IO uint8_t TRSV_REG0F9;                        /**< offset: 0x7E4 */
       uint8_t RESERVED_374[3];
  __IO uint8_t TRSV_REG0FA;                        /**< offset: 0x7E8 */
       uint8_t RESERVED_375[3];
  __IO uint8_t TRSV_REG0FB;                        /**< offset: 0x7EC */
       uint8_t RESERVED_376[3];
  __IO uint8_t TRSV_REG0FC;                        /**< offset: 0x7F0 */
       uint8_t RESERVED_377[3];
  __IO uint8_t TRSV_REG0FD;                        /**< offset: 0x7F4 */
       uint8_t RESERVED_378[3];
  __IO uint8_t TRSV_REG0FE;                        /**< offset: 0x7F8 */
       uint8_t RESERVED_379[3];
  __IO uint8_t TRSV_REG0FF;                        /**< offset: 0x7FC */
} PCIE_PHY_Type;

/* ----------------------------------------------------------------------------
   -- PCIE_PHY Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PCIE_PHY_Register_Masks PCIE_PHY Register Masks
 * @{
 */

/*! @name CMN_REG000 -  */
/*! @{ */

#define PCIE_PHY_CMN_REG000_BGR_LPF_BYPASS_MASK  (0x1U)
#define PCIE_PHY_CMN_REG000_BGR_LPF_BYPASS_SHIFT (0U)
/*! BGR_LPF_BYPASS - BGR LPF bypass to reduce BGR settle time */
#define PCIE_PHY_CMN_REG000_BGR_LPF_BYPASS(x)    (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG000_BGR_LPF_BYPASS_SHIFT)) & PCIE_PHY_CMN_REG000_BGR_LPF_BYPASS_MASK)

#define PCIE_PHY_CMN_REG000_OVRD_BGR_LPF_BYPASS_MASK (0x2U)
#define PCIE_PHY_CMN_REG000_OVRD_BGR_LPF_BYPASS_SHIFT (1U)
/*! OVRD_BGR_LPF_BYPASS - Override enable for bgr_lpf_bypass */
#define PCIE_PHY_CMN_REG000_OVRD_BGR_LPF_BYPASS(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG000_OVRD_BGR_LPF_BYPASS_SHIFT)) & PCIE_PHY_CMN_REG000_OVRD_BGR_LPF_BYPASS_MASK)

#define PCIE_PHY_CMN_REG000_BGR_EN_MASK          (0x4U)
#define PCIE_PHY_CMN_REG000_BGR_EN_SHIFT         (2U)
/*! BGR_EN - BGR enable */
#define PCIE_PHY_CMN_REG000_BGR_EN(x)            (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG000_BGR_EN_SHIFT)) & PCIE_PHY_CMN_REG000_BGR_EN_MASK)

#define PCIE_PHY_CMN_REG000_OVRD_BGR_EN_MASK     (0x8U)
#define PCIE_PHY_CMN_REG000_OVRD_BGR_EN_SHIFT    (3U)
/*! OVRD_BGR_EN - Override enable for bgr_en */
#define PCIE_PHY_CMN_REG000_OVRD_BGR_EN(x)       (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG000_OVRD_BGR_EN_SHIFT)) & PCIE_PHY_CMN_REG000_OVRD_BGR_EN_MASK)
/*! @} */

/*! @name CMN_REG001 -  */
/*! @{ */

#define PCIE_PHY_CMN_REG001_ANA_BGR_LADDER_EN_MASK (0x1U)
#define PCIE_PHY_CMN_REG001_ANA_BGR_LADDER_EN_SHIFT (0U)
/*! ANA_BGR_LADDER_EN - BGR output voltage selection */
#define PCIE_PHY_CMN_REG001_ANA_BGR_LADDER_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG001_ANA_BGR_LADDER_EN_SHIFT)) & PCIE_PHY_CMN_REG001_ANA_BGR_LADDER_EN_MASK)

#define PCIE_PHY_CMN_REG001_ANA_BGR_CLK_EN_MASK  (0x2U)
#define PCIE_PHY_CMN_REG001_ANA_BGR_CLK_EN_SHIFT (1U)
/*! ANA_BGR_CLK_EN - BGR chopper clock enable */
#define PCIE_PHY_CMN_REG001_ANA_BGR_CLK_EN(x)    (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG001_ANA_BGR_CLK_EN_SHIFT)) & PCIE_PHY_CMN_REG001_ANA_BGR_CLK_EN_MASK)

#define PCIE_PHY_CMN_REG001_ANA_BGR_820M_SEL_MASK (0x7CU)
#define PCIE_PHY_CMN_REG001_ANA_BGR_820M_SEL_SHIFT (2U)
/*! ANA_BGR_820M_SEL - BGR 820mV selection ( for current bias ) */
#define PCIE_PHY_CMN_REG001_ANA_BGR_820M_SEL(x)  (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG001_ANA_BGR_820M_SEL_SHIFT)) & PCIE_PHY_CMN_REG001_ANA_BGR_820M_SEL_MASK)
/*! @} */

/*! @name CMN_REG002 -  */
/*! @{ */

#define PCIE_PHY_CMN_REG002_BIAS_RCAL_EN_MASK    (0x1U)
#define PCIE_PHY_CMN_REG002_BIAS_RCAL_EN_SHIFT   (0U)
/*! BIAS_RCAL_EN - RX RCAL bias current enable */
#define PCIE_PHY_CMN_REG002_BIAS_RCAL_EN(x)      (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG002_BIAS_RCAL_EN_SHIFT)) & PCIE_PHY_CMN_REG002_BIAS_RCAL_EN_MASK)

#define PCIE_PHY_CMN_REG002_OVRD_BIAS_RCAL_EN_MASK (0x2U)
#define PCIE_PHY_CMN_REG002_OVRD_BIAS_RCAL_EN_SHIFT (1U)
/*! OVRD_BIAS_RCAL_EN - Override enable for bias_rcal_en */
#define PCIE_PHY_CMN_REG002_OVRD_BIAS_RCAL_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG002_OVRD_BIAS_RCAL_EN_SHIFT)) & PCIE_PHY_CMN_REG002_OVRD_BIAS_RCAL_EN_MASK)

#define PCIE_PHY_CMN_REG002_BIAS_EN_MASK         (0x4U)
#define PCIE_PHY_CMN_REG002_BIAS_EN_SHIFT        (2U)
/*! BIAS_EN - Bias current enable */
#define PCIE_PHY_CMN_REG002_BIAS_EN(x)           (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG002_BIAS_EN_SHIFT)) & PCIE_PHY_CMN_REG002_BIAS_EN_MASK)

#define PCIE_PHY_CMN_REG002_OVRD_BIAS_EN_MASK    (0x8U)
#define PCIE_PHY_CMN_REG002_OVRD_BIAS_EN_SHIFT   (3U)
/*! OVRD_BIAS_EN - Override enable for bias_en */
#define PCIE_PHY_CMN_REG002_OVRD_BIAS_EN(x)      (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG002_OVRD_BIAS_EN_SHIFT)) & PCIE_PHY_CMN_REG002_OVRD_BIAS_EN_MASK)

#define PCIE_PHY_CMN_REG002_ANA_BGR_ATB_SEL_MASK (0x10U)
#define PCIE_PHY_CMN_REG002_ANA_BGR_ATB_SEL_SHIFT (4U)
/*! ANA_BGR_ATB_SEL - BGR ATB select */
#define PCIE_PHY_CMN_REG002_ANA_BGR_ATB_SEL(x)   (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG002_ANA_BGR_ATB_SEL_SHIFT)) & PCIE_PHY_CMN_REG002_ANA_BGR_ATB_SEL_MASK)

#define PCIE_PHY_CMN_REG002_ANA_BGR_LADDER_SEL_MASK (0xE0U)
#define PCIE_PHY_CMN_REG002_ANA_BGR_LADDER_SEL_SHIFT (5U)
/*! ANA_BGR_LADDER_SEL - Resistor ladder voltage selection */
#define PCIE_PHY_CMN_REG002_ANA_BGR_LADDER_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG002_ANA_BGR_LADDER_SEL_SHIFT)) & PCIE_PHY_CMN_REG002_ANA_BGR_LADDER_SEL_MASK)
/*! @} */

/*! @name CMN_REG003 -  */
/*! @{ */

#define PCIE_PHY_CMN_REG003_ANA_BIAS_TX_RCAL_IREXT_CTRL_MASK (0x3U)
#define PCIE_PHY_CMN_REG003_ANA_BIAS_TX_RCAL_IREXT_CTRL_SHIFT (0U)
/*! ANA_BIAS_TX_RCAL_IREXT_CTRL - REXT-refered bias current control MSB for TX RCAL */
#define PCIE_PHY_CMN_REG003_ANA_BIAS_TX_RCAL_IREXT_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG003_ANA_BIAS_TX_RCAL_IREXT_CTRL_SHIFT)) & PCIE_PHY_CMN_REG003_ANA_BIAS_TX_RCAL_IREXT_CTRL_MASK)

#define PCIE_PHY_CMN_REG003_ANA_BIAS_RX_RCAL_IREXT_CTRL_MASK (0xCU)
#define PCIE_PHY_CMN_REG003_ANA_BIAS_RX_RCAL_IREXT_CTRL_SHIFT (2U)
/*! ANA_BIAS_RX_RCAL_IREXT_CTRL - REXT-refered bias current controlI for RX RCAL */
#define PCIE_PHY_CMN_REG003_ANA_BIAS_RX_RCAL_IREXT_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG003_ANA_BIAS_RX_RCAL_IREXT_CTRL_SHIFT)) & PCIE_PHY_CMN_REG003_ANA_BIAS_RX_RCAL_IREXT_CTRL_MASK)

#define PCIE_PHY_CMN_REG003_ANA_BIAS_IREXT_CTRL_MASK (0x30U)
#define PCIE_PHY_CMN_REG003_ANA_BIAS_IREXT_CTRL_SHIFT (4U)
/*! ANA_BIAS_IREXT_CTRL - REXT-refered bias current controlI for overall IP */
#define PCIE_PHY_CMN_REG003_ANA_BIAS_IREXT_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG003_ANA_BIAS_IREXT_CTRL_SHIFT)) & PCIE_PHY_CMN_REG003_ANA_BIAS_IREXT_CTRL_MASK)
/*! @} */

/*! @name CMN_REG004 -  */
/*! @{ */

#define PCIE_PHY_CMN_REG004_PLL_EN_MASK          (0x1U)
#define PCIE_PHY_CMN_REG004_PLL_EN_SHIFT         (0U)
/*! PLL_EN - PLL enable */
#define PCIE_PHY_CMN_REG004_PLL_EN(x)            (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG004_PLL_EN_SHIFT)) & PCIE_PHY_CMN_REG004_PLL_EN_MASK)

#define PCIE_PHY_CMN_REG004_OVRD_PLL_EN_MASK     (0x2U)
#define PCIE_PHY_CMN_REG004_OVRD_PLL_EN_SHIFT    (1U)
/*! OVRD_PLL_EN - Override enable for pll_en */
#define PCIE_PHY_CMN_REG004_OVRD_PLL_EN(x)       (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG004_OVRD_PLL_EN_SHIFT)) & PCIE_PHY_CMN_REG004_OVRD_PLL_EN_MASK)
/*! @} */

/*! @name CMN_REG005 -  */
/*! @{ */

#define PCIE_PHY_CMN_REG005_PLL_AFC_RSTN_MASK    (0x1U)
#define PCIE_PHY_CMN_REG005_PLL_AFC_RSTN_SHIFT   (0U)
/*! PLL_AFC_RSTN - PLL AFC reset. When AFC reset is asserted, the previous AFC result is held. When
 *    AFC reset is released, AFC starts from the previous AFC code stored in internal memory.
 */
#define PCIE_PHY_CMN_REG005_PLL_AFC_RSTN(x)      (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG005_PLL_AFC_RSTN_SHIFT)) & PCIE_PHY_CMN_REG005_PLL_AFC_RSTN_MASK)

#define PCIE_PHY_CMN_REG005_OVRD_PLL_AFC_RSTN_MASK (0x2U)
#define PCIE_PHY_CMN_REG005_OVRD_PLL_AFC_RSTN_SHIFT (1U)
/*! OVRD_PLL_AFC_RSTN - Override enable for pll_afc_rstn */
#define PCIE_PHY_CMN_REG005_OVRD_PLL_AFC_RSTN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG005_OVRD_PLL_AFC_RSTN_SHIFT)) & PCIE_PHY_CMN_REG005_OVRD_PLL_AFC_RSTN_MASK)

#define PCIE_PHY_CMN_REG005_PLL_AFC_INIT_RSTN_MASK (0x4U)
#define PCIE_PHY_CMN_REG005_PLL_AFC_INIT_RSTN_SHIFT (2U)
/*! PLL_AFC_INIT_RSTN - PLL AFC initial reset. When initial reset is asserted, the previous AFC
 *    result is reset. When initial reset is released, AFC starts from the initial AFC code given in
 *    i_rx_cdr_afc_sel_logic[3:0].
 */
#define PCIE_PHY_CMN_REG005_PLL_AFC_INIT_RSTN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG005_PLL_AFC_INIT_RSTN_SHIFT)) & PCIE_PHY_CMN_REG005_PLL_AFC_INIT_RSTN_MASK)

#define PCIE_PHY_CMN_REG005_OVRD_PLL_AFC_INIT_RSTN_MASK (0x8U)
#define PCIE_PHY_CMN_REG005_OVRD_PLL_AFC_INIT_RSTN_SHIFT (3U)
/*! OVRD_PLL_AFC_INIT_RSTN - Override enable for pll_afc_init_rstn */
#define PCIE_PHY_CMN_REG005_OVRD_PLL_AFC_INIT_RSTN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG005_OVRD_PLL_AFC_INIT_RSTN_SHIFT)) & PCIE_PHY_CMN_REG005_OVRD_PLL_AFC_INIT_RSTN_MASK)

#define PCIE_PHY_CMN_REG005_PLL_VCO_MODE_G4_MASK (0x10U)
#define PCIE_PHY_CMN_REG005_PLL_VCO_MODE_G4_SHIFT (4U)
/*! PLL_VCO_MODE_G4 - [GEN4] */
#define PCIE_PHY_CMN_REG005_PLL_VCO_MODE_G4(x)   (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG005_PLL_VCO_MODE_G4_SHIFT)) & PCIE_PHY_CMN_REG005_PLL_VCO_MODE_G4_MASK)

#define PCIE_PHY_CMN_REG005_PLL_VCO_MODE_G3_MASK (0x20U)
#define PCIE_PHY_CMN_REG005_PLL_VCO_MODE_G3_SHIFT (5U)
/*! PLL_VCO_MODE_G3 - [GEN3] */
#define PCIE_PHY_CMN_REG005_PLL_VCO_MODE_G3(x)   (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG005_PLL_VCO_MODE_G3_SHIFT)) & PCIE_PHY_CMN_REG005_PLL_VCO_MODE_G3_MASK)

#define PCIE_PHY_CMN_REG005_PLL_VCO_MODE_G2_MASK (0x40U)
#define PCIE_PHY_CMN_REG005_PLL_VCO_MODE_G2_SHIFT (6U)
/*! PLL_VCO_MODE_G2 - [GEN2] */
#define PCIE_PHY_CMN_REG005_PLL_VCO_MODE_G2(x)   (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG005_PLL_VCO_MODE_G2_SHIFT)) & PCIE_PHY_CMN_REG005_PLL_VCO_MODE_G2_MASK)

#define PCIE_PHY_CMN_REG005_PLL_VCO_MODE_G1_MASK (0x80U)
#define PCIE_PHY_CMN_REG005_PLL_VCO_MODE_G1_SHIFT (7U)
/*! PLL_VCO_MODE_G1 - [GEN1] PLL VCO selection */
#define PCIE_PHY_CMN_REG005_PLL_VCO_MODE_G1(x)   (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG005_PLL_VCO_MODE_G1_SHIFT)) & PCIE_PHY_CMN_REG005_PLL_VCO_MODE_G1_MASK)
/*! @} */

/*! @name CMN_REG006 -  */
/*! @{ */

#define PCIE_PHY_CMN_REG006_ANA_PLL_AFC_MAN_LC_CODE_SEL_MASK (0x3U)
#define PCIE_PHY_CMN_REG006_ANA_PLL_AFC_MAN_LC_CODE_SEL_SHIFT (0U)
/*! ANA_PLL_AFC_MAN_LC_CODE_SEL - Manual PLL AFC code selection (MSB) */
#define PCIE_PHY_CMN_REG006_ANA_PLL_AFC_MAN_LC_CODE_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG006_ANA_PLL_AFC_MAN_LC_CODE_SEL_SHIFT)) & PCIE_PHY_CMN_REG006_ANA_PLL_AFC_MAN_LC_CODE_SEL_MASK)

#define PCIE_PHY_CMN_REG006_ANA_PLL_AFC_FROM_PRE_CODE_MASK (0x4U)
#define PCIE_PHY_CMN_REG006_ANA_PLL_AFC_FROM_PRE_CODE_SHIFT (2U)
/*! ANA_PLL_AFC_FROM_PRE_CODE - PLL AFC option in restart case */
#define PCIE_PHY_CMN_REG006_ANA_PLL_AFC_FROM_PRE_CODE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG006_ANA_PLL_AFC_FROM_PRE_CODE_SHIFT)) & PCIE_PHY_CMN_REG006_ANA_PLL_AFC_FROM_PRE_CODE_MASK)

#define PCIE_PHY_CMN_REG006_ANA_PLL_AFC_EN_MASK  (0x8U)
#define PCIE_PHY_CMN_REG006_ANA_PLL_AFC_EN_SHIFT (3U)
/*! ANA_PLL_AFC_EN - PLL AFC enable; if enabled, VCO frequency is automatically calibrated. If
 *    disabled, VCO starts to oscillate with fixed AFC code of i_pll_man_bsel_m and _l.
 */
#define PCIE_PHY_CMN_REG006_ANA_PLL_AFC_EN(x)    (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG006_ANA_PLL_AFC_EN_SHIFT)) & PCIE_PHY_CMN_REG006_ANA_PLL_AFC_EN_MASK)

#define PCIE_PHY_CMN_REG006_ANA_PLL_AFC_CODE_FORCE_MASK (0x10U)
#define PCIE_PHY_CMN_REG006_ANA_PLL_AFC_CODE_FORCE_SHIFT (4U)
/*! ANA_PLL_AFC_CODE_FORCE - PLL AFC code manual selection enable */
#define PCIE_PHY_CMN_REG006_ANA_PLL_AFC_CODE_FORCE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG006_ANA_PLL_AFC_CODE_FORCE_SHIFT)) & PCIE_PHY_CMN_REG006_ANA_PLL_AFC_CODE_FORCE_MASK)

#define PCIE_PHY_CMN_REG006_ANA_PLL_AFC_CLK_DIV2_EN_MASK (0x20U)
#define PCIE_PHY_CMN_REG006_ANA_PLL_AFC_CLK_DIV2_EN_SHIFT (5U)
/*! ANA_PLL_AFC_CLK_DIV2_EN - PLL AFC clock frequency selection */
#define PCIE_PHY_CMN_REG006_ANA_PLL_AFC_CLK_DIV2_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG006_ANA_PLL_AFC_CLK_DIV2_EN_SHIFT)) & PCIE_PHY_CMN_REG006_ANA_PLL_AFC_CLK_DIV2_EN_MASK)
/*! @} */

/*! @name CMN_REG007 -  */
/*! @{ */

#define PCIE_PHY_CMN_REG007_ANA_PLL_AFC_STB_NUM_MASK (0xFU)
#define PCIE_PHY_CMN_REG007_ANA_PLL_AFC_STB_NUM_SHIFT (0U)
/*! ANA_PLL_AFC_STB_NUM - Number of reference clock cycle to check VCO stabilization during PLL AFC start */
#define PCIE_PHY_CMN_REG007_ANA_PLL_AFC_STB_NUM(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG007_ANA_PLL_AFC_STB_NUM_SHIFT)) & PCIE_PHY_CMN_REG007_ANA_PLL_AFC_STB_NUM_MASK)

#define PCIE_PHY_CMN_REG007_ANA_PLL_AFC_MAN_RING_CODE_SEL_MASK (0xF0U)
#define PCIE_PHY_CMN_REG007_ANA_PLL_AFC_MAN_RING_CODE_SEL_SHIFT (4U)
/*! ANA_PLL_AFC_MAN_RING_CODE_SEL - Manual PLL AFC code selection (LSB) */
#define PCIE_PHY_CMN_REG007_ANA_PLL_AFC_MAN_RING_CODE_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG007_ANA_PLL_AFC_MAN_RING_CODE_SEL_SHIFT)) & PCIE_PHY_CMN_REG007_ANA_PLL_AFC_MAN_RING_CODE_SEL_MASK)
/*! @} */

/*! @name CMN_REG008 -  */
/*! @{ */

#define PCIE_PHY_CMN_REG008_ANA_PLL_AFC_VCI_FORCE_MASK (0x1U)
#define PCIE_PHY_CMN_REG008_ANA_PLL_AFC_VCI_FORCE_SHIFT (0U)
/*! ANA_PLL_AFC_VCI_FORCE - PLL control voltage force for open-loop test purpose */
#define PCIE_PHY_CMN_REG008_ANA_PLL_AFC_VCI_FORCE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG008_ANA_PLL_AFC_VCI_FORCE_SHIFT)) & PCIE_PHY_CMN_REG008_ANA_PLL_AFC_VCI_FORCE_MASK)

#define PCIE_PHY_CMN_REG008_ANA_PLL_AFC_TOL_NUM_MASK (0x1EU)
#define PCIE_PHY_CMN_REG008_ANA_PLL_AFC_TOL_NUM_SHIFT (1U)
/*! ANA_PLL_AFC_TOL_NUM - PLL VCO stabilization tolerance; VCO is considered as settled-down if
 *    |counter difference|&lt;i_pll_afc_tol during i_pll_afc_stb_num
 */
#define PCIE_PHY_CMN_REG008_ANA_PLL_AFC_TOL_NUM(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG008_ANA_PLL_AFC_TOL_NUM_SHIFT)) & PCIE_PHY_CMN_REG008_ANA_PLL_AFC_TOL_NUM_MASK)
/*! @} */

/*! @name CMN_REG009 -  */
/*! @{ */

#define PCIE_PHY_CMN_REG009_ANA_PLL_AFC_VCO_CNT_WAIT_NUM_MASK (0x7U)
#define PCIE_PHY_CMN_REG009_ANA_PLL_AFC_VCO_CNT_WAIT_NUM_SHIFT (0U)
/*! ANA_PLL_AFC_VCO_CNT_WAIT_NUM - Number of reference clock cycle to count VCO clock during AFC */
#define PCIE_PHY_CMN_REG009_ANA_PLL_AFC_VCO_CNT_WAIT_NUM(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG009_ANA_PLL_AFC_VCO_CNT_WAIT_NUM_SHIFT)) & PCIE_PHY_CMN_REG009_ANA_PLL_AFC_VCO_CNT_WAIT_NUM_MASK)

#define PCIE_PHY_CMN_REG009_ANA_PLL_AFC_VCO_CNT_RUN_NUM_MASK (0xF8U)
#define PCIE_PHY_CMN_REG009_ANA_PLL_AFC_VCO_CNT_RUN_NUM_SHIFT (3U)
/*! ANA_PLL_AFC_VCO_CNT_RUN_NUM - Number of reference clock cycle to wait VCO clock during AFC */
#define PCIE_PHY_CMN_REG009_ANA_PLL_AFC_VCO_CNT_RUN_NUM(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG009_ANA_PLL_AFC_VCO_CNT_RUN_NUM_SHIFT)) & PCIE_PHY_CMN_REG009_ANA_PLL_AFC_VCO_CNT_RUN_NUM_MASK)
/*! @} */

/*! @name CMN_REG00A -  */
/*! @{ */

#define PCIE_PHY_CMN_REG00A_ANA_PLL_AGMC_MAN_GM_SEL_EN_MASK (0x1U)
#define PCIE_PHY_CMN_REG00A_ANA_PLL_AGMC_MAN_GM_SEL_EN_SHIFT (0U)
/*! ANA_PLL_AGMC_MAN_GM_SEL_EN - PLL LC VCO GM code selection */
#define PCIE_PHY_CMN_REG00A_ANA_PLL_AGMC_MAN_GM_SEL_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG00A_ANA_PLL_AGMC_MAN_GM_SEL_EN_SHIFT)) & PCIE_PHY_CMN_REG00A_ANA_PLL_AGMC_MAN_GM_SEL_EN_MASK)

#define PCIE_PHY_CMN_REG00A_ANA_PLL_AGMC_GM_ADD_MASK (0x6U)
#define PCIE_PHY_CMN_REG00A_ANA_PLL_AGMC_GM_ADD_SHIFT (1U)
/*! ANA_PLL_AGMC_GM_ADD - Offset code to be added to final gm code */
#define PCIE_PHY_CMN_REG00A_ANA_PLL_AGMC_GM_ADD(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG00A_ANA_PLL_AGMC_GM_ADD_SHIFT)) & PCIE_PHY_CMN_REG00A_ANA_PLL_AGMC_GM_ADD_MASK)

#define PCIE_PHY_CMN_REG00A_ANA_PLL_AGMC_FROM_MAX_GM_MASK (0x8U)
#define PCIE_PHY_CMN_REG00A_ANA_PLL_AGMC_FROM_MAX_GM_SHIFT (3U)
/*! ANA_PLL_AGMC_FROM_MAX_GM - PLL LC VCO automatic gm search initial condition */
#define PCIE_PHY_CMN_REG00A_ANA_PLL_AGMC_FROM_MAX_GM(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG00A_ANA_PLL_AGMC_FROM_MAX_GM_SHIFT)) & PCIE_PHY_CMN_REG00A_ANA_PLL_AGMC_FROM_MAX_GM_MASK)

#define PCIE_PHY_CMN_REG00A_ANA_PLL_AGMC_COMP_EN_MASK (0x10U)
#define PCIE_PHY_CMN_REG00A_ANA_PLL_AGMC_COMP_EN_SHIFT (4U)
/*! ANA_PLL_AGMC_COMP_EN - Comparator enable for PLL LC VCO automatic gm search */
#define PCIE_PHY_CMN_REG00A_ANA_PLL_AGMC_COMP_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG00A_ANA_PLL_AGMC_COMP_EN_SHIFT)) & PCIE_PHY_CMN_REG00A_ANA_PLL_AGMC_COMP_EN_MASK)

#define PCIE_PHY_CMN_REG00A_ANA_PLL_AFC_VCO_START_CRITERION_MASK (0xE0U)
#define PCIE_PHY_CMN_REG00A_ANA_PLL_AFC_VCO_START_CRITERION_SHIFT (5U)
/*! ANA_PLL_AFC_VCO_START_CRITERION - Minimum PLL VCO counter value to start AFC (Criterion to suppose PLL VCO successfully start to oscillate) */
#define PCIE_PHY_CMN_REG00A_ANA_PLL_AFC_VCO_START_CRITERION(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG00A_ANA_PLL_AFC_VCO_START_CRITERION_SHIFT)) & PCIE_PHY_CMN_REG00A_ANA_PLL_AFC_VCO_START_CRITERION_MASK)
/*! @} */

/*! @name CMN_REG00B -  */
/*! @{ */

#define PCIE_PHY_CMN_REG00B_ANA_PLL_AGMC_MAN_GM_SEL_MASK (0xFU)
#define PCIE_PHY_CMN_REG00B_ANA_PLL_AGMC_MAN_GM_SEL_SHIFT (0U)
/*! ANA_PLL_AGMC_MAN_GM_SEL - Manual GM code selection for LC VCO */
#define PCIE_PHY_CMN_REG00B_ANA_PLL_AGMC_MAN_GM_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG00B_ANA_PLL_AGMC_MAN_GM_SEL_SHIFT)) & PCIE_PHY_CMN_REG00B_ANA_PLL_AGMC_MAN_GM_SEL_MASK)
/*! @} */

/*! @name CMN_REG00C -  */
/*! @{ */

#define PCIE_PHY_CMN_REG00C_PLL_AGMC_TG_CODE_G1_MASK (0xFFU)
#define PCIE_PHY_CMN_REG00C_PLL_AGMC_TG_CODE_G1_SHIFT (0U)
/*! PLL_AGMC_TG_CODE_G1 - [GEN1] Target counter value for automatic GM search of LC VCO */
#define PCIE_PHY_CMN_REG00C_PLL_AGMC_TG_CODE_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG00C_PLL_AGMC_TG_CODE_G1_SHIFT)) & PCIE_PHY_CMN_REG00C_PLL_AGMC_TG_CODE_G1_MASK)
/*! @} */

/*! @name CMN_REG00D -  */
/*! @{ */

#define PCIE_PHY_CMN_REG00D_PLL_AGMC_TG_CODE_G2_MASK (0xFFU)
#define PCIE_PHY_CMN_REG00D_PLL_AGMC_TG_CODE_G2_SHIFT (0U)
/*! PLL_AGMC_TG_CODE_G2 - [GEN2] */
#define PCIE_PHY_CMN_REG00D_PLL_AGMC_TG_CODE_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG00D_PLL_AGMC_TG_CODE_G2_SHIFT)) & PCIE_PHY_CMN_REG00D_PLL_AGMC_TG_CODE_G2_MASK)
/*! @} */

/*! @name CMN_REG00E -  */
/*! @{ */

#define PCIE_PHY_CMN_REG00E_PLL_AGMC_TG_CODE_G3_MASK (0xFFU)
#define PCIE_PHY_CMN_REG00E_PLL_AGMC_TG_CODE_G3_SHIFT (0U)
/*! PLL_AGMC_TG_CODE_G3 - [GEN3] */
#define PCIE_PHY_CMN_REG00E_PLL_AGMC_TG_CODE_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG00E_PLL_AGMC_TG_CODE_G3_SHIFT)) & PCIE_PHY_CMN_REG00E_PLL_AGMC_TG_CODE_G3_MASK)
/*! @} */

/*! @name CMN_REG00F -  */
/*! @{ */

#define PCIE_PHY_CMN_REG00F_PLL_AGMC_TG_CODE_G4_MASK (0xFFU)
#define PCIE_PHY_CMN_REG00F_PLL_AGMC_TG_CODE_G4_SHIFT (0U)
/*! PLL_AGMC_TG_CODE_G4 - [GEN4] */
#define PCIE_PHY_CMN_REG00F_PLL_AGMC_TG_CODE_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG00F_PLL_AGMC_TG_CODE_G4_SHIFT)) & PCIE_PHY_CMN_REG00F_PLL_AGMC_TG_CODE_G4_MASK)
/*! @} */

/*! @name CMN_REG010 -  */
/*! @{ */

#define PCIE_PHY_CMN_REG010_PLL_ANA_CPI_CTRL_COARSE_G2_MASK (0x7U)
#define PCIE_PHY_CMN_REG010_PLL_ANA_CPI_CTRL_COARSE_G2_SHIFT (0U)
/*! PLL_ANA_CPI_CTRL_COARSE_G2 - [GEN1] PLL integral path charge-pump current contorl */
#define PCIE_PHY_CMN_REG010_PLL_ANA_CPI_CTRL_COARSE_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG010_PLL_ANA_CPI_CTRL_COARSE_G2_SHIFT)) & PCIE_PHY_CMN_REG010_PLL_ANA_CPI_CTRL_COARSE_G2_MASK)

#define PCIE_PHY_CMN_REG010_PLL_ANA_CPI_CTRL_COARSE_G1_MASK (0x38U)
#define PCIE_PHY_CMN_REG010_PLL_ANA_CPI_CTRL_COARSE_G1_SHIFT (3U)
/*! PLL_ANA_CPI_CTRL_COARSE_G1 - [GEN1] PLL integral path charge-pump current contorl */
#define PCIE_PHY_CMN_REG010_PLL_ANA_CPI_CTRL_COARSE_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG010_PLL_ANA_CPI_CTRL_COARSE_G1_SHIFT)) & PCIE_PHY_CMN_REG010_PLL_ANA_CPI_CTRL_COARSE_G1_MASK)
/*! @} */

/*! @name CMN_REG011 -  */
/*! @{ */

#define PCIE_PHY_CMN_REG011_PLL_ANA_CPI_CTRL_COARSE_G4_MASK (0x7U)
#define PCIE_PHY_CMN_REG011_PLL_ANA_CPI_CTRL_COARSE_G4_SHIFT (0U)
/*! PLL_ANA_CPI_CTRL_COARSE_G4 - [GEN1] PLL integral path charge-pump current contorl */
#define PCIE_PHY_CMN_REG011_PLL_ANA_CPI_CTRL_COARSE_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG011_PLL_ANA_CPI_CTRL_COARSE_G4_SHIFT)) & PCIE_PHY_CMN_REG011_PLL_ANA_CPI_CTRL_COARSE_G4_MASK)

#define PCIE_PHY_CMN_REG011_PLL_ANA_CPI_CTRL_COARSE_G3_MASK (0x38U)
#define PCIE_PHY_CMN_REG011_PLL_ANA_CPI_CTRL_COARSE_G3_SHIFT (3U)
/*! PLL_ANA_CPI_CTRL_COARSE_G3 - [GEN1] PLL integral path charge-pump current contorl */
#define PCIE_PHY_CMN_REG011_PLL_ANA_CPI_CTRL_COARSE_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG011_PLL_ANA_CPI_CTRL_COARSE_G3_SHIFT)) & PCIE_PHY_CMN_REG011_PLL_ANA_CPI_CTRL_COARSE_G3_MASK)
/*! @} */

/*! @name CMN_REG012 -  */
/*! @{ */

#define PCIE_PHY_CMN_REG012_PLL_ANA_CPI_CTRL_FINE_G2_MASK (0x7U)
#define PCIE_PHY_CMN_REG012_PLL_ANA_CPI_CTRL_FINE_G2_SHIFT (0U)
/*! PLL_ANA_CPI_CTRL_FINE_G2 - [GEN1] PLL integral path charge-pump current contorl */
#define PCIE_PHY_CMN_REG012_PLL_ANA_CPI_CTRL_FINE_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG012_PLL_ANA_CPI_CTRL_FINE_G2_SHIFT)) & PCIE_PHY_CMN_REG012_PLL_ANA_CPI_CTRL_FINE_G2_MASK)

#define PCIE_PHY_CMN_REG012_PLL_ANA_CPI_CTRL_FINE_G1_MASK (0x38U)
#define PCIE_PHY_CMN_REG012_PLL_ANA_CPI_CTRL_FINE_G1_SHIFT (3U)
/*! PLL_ANA_CPI_CTRL_FINE_G1 - [GEN1] PLL integral path charge-pump current contorl */
#define PCIE_PHY_CMN_REG012_PLL_ANA_CPI_CTRL_FINE_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG012_PLL_ANA_CPI_CTRL_FINE_G1_SHIFT)) & PCIE_PHY_CMN_REG012_PLL_ANA_CPI_CTRL_FINE_G1_MASK)
/*! @} */

/*! @name CMN_REG013 -  */
/*! @{ */

#define PCIE_PHY_CMN_REG013_PLL_ANA_CPI_CTRL_FINE_G4_MASK (0x7U)
#define PCIE_PHY_CMN_REG013_PLL_ANA_CPI_CTRL_FINE_G4_SHIFT (0U)
/*! PLL_ANA_CPI_CTRL_FINE_G4 - [GEN1] PLL integral path charge-pump current contorl */
#define PCIE_PHY_CMN_REG013_PLL_ANA_CPI_CTRL_FINE_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG013_PLL_ANA_CPI_CTRL_FINE_G4_SHIFT)) & PCIE_PHY_CMN_REG013_PLL_ANA_CPI_CTRL_FINE_G4_MASK)

#define PCIE_PHY_CMN_REG013_PLL_ANA_CPI_CTRL_FINE_G3_MASK (0x38U)
#define PCIE_PHY_CMN_REG013_PLL_ANA_CPI_CTRL_FINE_G3_SHIFT (3U)
/*! PLL_ANA_CPI_CTRL_FINE_G3 - [GEN1] PLL integral path charge-pump current contorl */
#define PCIE_PHY_CMN_REG013_PLL_ANA_CPI_CTRL_FINE_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG013_PLL_ANA_CPI_CTRL_FINE_G3_SHIFT)) & PCIE_PHY_CMN_REG013_PLL_ANA_CPI_CTRL_FINE_G3_MASK)
/*! @} */

/*! @name CMN_REG014 -  */
/*! @{ */

#define PCIE_PHY_CMN_REG014_PLL_ANA_CPP_CTRL_COARSE_G2_MASK (0xFU)
#define PCIE_PHY_CMN_REG014_PLL_ANA_CPP_CTRL_COARSE_G2_SHIFT (0U)
/*! PLL_ANA_CPP_CTRL_COARSE_G2 - [GEN1] PLL integral path charge-pump current contorl */
#define PCIE_PHY_CMN_REG014_PLL_ANA_CPP_CTRL_COARSE_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG014_PLL_ANA_CPP_CTRL_COARSE_G2_SHIFT)) & PCIE_PHY_CMN_REG014_PLL_ANA_CPP_CTRL_COARSE_G2_MASK)

#define PCIE_PHY_CMN_REG014_PLL_ANA_CPP_CTRL_COARSE_G1_MASK (0xF0U)
#define PCIE_PHY_CMN_REG014_PLL_ANA_CPP_CTRL_COARSE_G1_SHIFT (4U)
/*! PLL_ANA_CPP_CTRL_COARSE_G1 - [GEN1] PLL integral path charge-pump current contorl */
#define PCIE_PHY_CMN_REG014_PLL_ANA_CPP_CTRL_COARSE_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG014_PLL_ANA_CPP_CTRL_COARSE_G1_SHIFT)) & PCIE_PHY_CMN_REG014_PLL_ANA_CPP_CTRL_COARSE_G1_MASK)
/*! @} */

/*! @name CMN_REG015 -  */
/*! @{ */

#define PCIE_PHY_CMN_REG015_PLL_ANA_CPP_CTRL_COARSE_G4_MASK (0xFU)
#define PCIE_PHY_CMN_REG015_PLL_ANA_CPP_CTRL_COARSE_G4_SHIFT (0U)
/*! PLL_ANA_CPP_CTRL_COARSE_G4 - [GEN1] PLL integral path charge-pump current contorl */
#define PCIE_PHY_CMN_REG015_PLL_ANA_CPP_CTRL_COARSE_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG015_PLL_ANA_CPP_CTRL_COARSE_G4_SHIFT)) & PCIE_PHY_CMN_REG015_PLL_ANA_CPP_CTRL_COARSE_G4_MASK)

#define PCIE_PHY_CMN_REG015_PLL_ANA_CPP_CTRL_COARSE_G3_MASK (0xF0U)
#define PCIE_PHY_CMN_REG015_PLL_ANA_CPP_CTRL_COARSE_G3_SHIFT (4U)
/*! PLL_ANA_CPP_CTRL_COARSE_G3 - [GEN1] PLL integral path charge-pump current contorl */
#define PCIE_PHY_CMN_REG015_PLL_ANA_CPP_CTRL_COARSE_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG015_PLL_ANA_CPP_CTRL_COARSE_G3_SHIFT)) & PCIE_PHY_CMN_REG015_PLL_ANA_CPP_CTRL_COARSE_G3_MASK)
/*! @} */

/*! @name CMN_REG016 -  */
/*! @{ */

#define PCIE_PHY_CMN_REG016_PLL_ANA_CPP_CTRL_FINE_G2_MASK (0xFU)
#define PCIE_PHY_CMN_REG016_PLL_ANA_CPP_CTRL_FINE_G2_SHIFT (0U)
/*! PLL_ANA_CPP_CTRL_FINE_G2 - [GEN1] PLL integral path charge-pump current contorl */
#define PCIE_PHY_CMN_REG016_PLL_ANA_CPP_CTRL_FINE_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG016_PLL_ANA_CPP_CTRL_FINE_G2_SHIFT)) & PCIE_PHY_CMN_REG016_PLL_ANA_CPP_CTRL_FINE_G2_MASK)

#define PCIE_PHY_CMN_REG016_PLL_ANA_CPP_CTRL_FINE_G1_MASK (0xF0U)
#define PCIE_PHY_CMN_REG016_PLL_ANA_CPP_CTRL_FINE_G1_SHIFT (4U)
/*! PLL_ANA_CPP_CTRL_FINE_G1 - [GEN1] PLL integral path charge-pump current contorl */
#define PCIE_PHY_CMN_REG016_PLL_ANA_CPP_CTRL_FINE_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG016_PLL_ANA_CPP_CTRL_FINE_G1_SHIFT)) & PCIE_PHY_CMN_REG016_PLL_ANA_CPP_CTRL_FINE_G1_MASK)
/*! @} */

/*! @name CMN_REG017 -  */
/*! @{ */

#define PCIE_PHY_CMN_REG017_PLL_ANA_CPP_CTRL_FINE_G4_MASK (0xFU)
#define PCIE_PHY_CMN_REG017_PLL_ANA_CPP_CTRL_FINE_G4_SHIFT (0U)
/*! PLL_ANA_CPP_CTRL_FINE_G4 - [GEN1] PLL integral path charge-pump current contorl */
#define PCIE_PHY_CMN_REG017_PLL_ANA_CPP_CTRL_FINE_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG017_PLL_ANA_CPP_CTRL_FINE_G4_SHIFT)) & PCIE_PHY_CMN_REG017_PLL_ANA_CPP_CTRL_FINE_G4_MASK)

#define PCIE_PHY_CMN_REG017_PLL_ANA_CPP_CTRL_FINE_G3_MASK (0xF0U)
#define PCIE_PHY_CMN_REG017_PLL_ANA_CPP_CTRL_FINE_G3_SHIFT (4U)
/*! PLL_ANA_CPP_CTRL_FINE_G3 - [GEN1] PLL integral path charge-pump current contorl */
#define PCIE_PHY_CMN_REG017_PLL_ANA_CPP_CTRL_FINE_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG017_PLL_ANA_CPP_CTRL_FINE_G3_SHIFT)) & PCIE_PHY_CMN_REG017_PLL_ANA_CPP_CTRL_FINE_G3_MASK)
/*! @} */

/*! @name CMN_REG018 -  */
/*! @{ */

#define PCIE_PHY_CMN_REG018_ANA_PLL_ANA_LC_GM_COMP_VREF_SEL_MASK (0x7U)
#define PCIE_PHY_CMN_REG018_ANA_PLL_ANA_LC_GM_COMP_VREF_SEL_SHIFT (0U)
/*! ANA_PLL_ANA_LC_GM_COMP_VREF_SEL - PLL GM comparator reference voltage selection */
#define PCIE_PHY_CMN_REG018_ANA_PLL_ANA_LC_GM_COMP_VREF_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG018_ANA_PLL_ANA_LC_GM_COMP_VREF_SEL_SHIFT)) & PCIE_PHY_CMN_REG018_ANA_PLL_ANA_LC_GM_COMP_VREF_SEL_MASK)

#define PCIE_PHY_CMN_REG018_ANA_PLL_ANA_LC_GM_COMP_CTRL_MASK (0x8U)
#define PCIE_PHY_CMN_REG018_ANA_PLL_ANA_LC_GM_COMP_CTRL_SHIFT (3U)
#define PCIE_PHY_CMN_REG018_ANA_PLL_ANA_LC_GM_COMP_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG018_ANA_PLL_ANA_LC_GM_COMP_CTRL_SHIFT)) & PCIE_PHY_CMN_REG018_ANA_PLL_ANA_LC_GM_COMP_CTRL_MASK)

#define PCIE_PHY_CMN_REG018_ANA_PLL_ANA_LC_CAP_OFFSET_SEL_MASK (0x70U)
#define PCIE_PHY_CMN_REG018_ANA_PLL_ANA_LC_CAP_OFFSET_SEL_SHIFT (4U)
/*! ANA_PLL_ANA_LC_CAP_OFFSET_SEL - LC VCO varactor bias voltage selection */
#define PCIE_PHY_CMN_REG018_ANA_PLL_ANA_LC_CAP_OFFSET_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG018_ANA_PLL_ANA_LC_CAP_OFFSET_SEL_SHIFT)) & PCIE_PHY_CMN_REG018_ANA_PLL_ANA_LC_CAP_OFFSET_SEL_MASK)
/*! @} */

/*! @name CMN_REG019 -  */
/*! @{ */

#define PCIE_PHY_CMN_REG019_ANA_PLL_ANA_LC_VREG_R_SEL_MASK (0x7U)
#define PCIE_PHY_CMN_REG019_ANA_PLL_ANA_LC_VREG_R_SEL_SHIFT (0U)
/*! ANA_PLL_ANA_LC_VREG_R_SEL - LC VCO voltage regulator output control */
#define PCIE_PHY_CMN_REG019_ANA_PLL_ANA_LC_VREG_R_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG019_ANA_PLL_ANA_LC_VREG_R_SEL_SHIFT)) & PCIE_PHY_CMN_REG019_ANA_PLL_ANA_LC_VREG_R_SEL_MASK)

#define PCIE_PHY_CMN_REG019_ANA_PLL_ANA_LC_VREF_BYPASS_MASK (0x8U)
#define PCIE_PHY_CMN_REG019_ANA_PLL_ANA_LC_VREF_BYPASS_SHIFT (3U)
/*! ANA_PLL_ANA_LC_VREF_BYPASS - LPF on reference voltage for PLL LC VCO bypass */
#define PCIE_PHY_CMN_REG019_ANA_PLL_ANA_LC_VREF_BYPASS(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG019_ANA_PLL_ANA_LC_VREF_BYPASS_SHIFT)) & PCIE_PHY_CMN_REG019_ANA_PLL_ANA_LC_VREF_BYPASS_MASK)

#define PCIE_PHY_CMN_REG019_ANA_PLL_ANA_LC_VREG_I_CTRL_MASK (0x30U)
#define PCIE_PHY_CMN_REG019_ANA_PLL_ANA_LC_VREG_I_CTRL_SHIFT (4U)
/*! ANA_PLL_ANA_LC_VREG_I_CTRL - LC VCO Vreg current branch enable (1+1/20 or 1+ 1/33) */
#define PCIE_PHY_CMN_REG019_ANA_PLL_ANA_LC_VREG_I_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG019_ANA_PLL_ANA_LC_VREG_I_CTRL_SHIFT)) & PCIE_PHY_CMN_REG019_ANA_PLL_ANA_LC_VREG_I_CTRL_MASK)
/*! @} */

/*! @name CMN_REG01A -  */
/*! @{ */

#define PCIE_PHY_CMN_REG01A_PLL_ANA_LPF_C_SEL_COARSE_G2_MASK (0x7U)
#define PCIE_PHY_CMN_REG01A_PLL_ANA_LPF_C_SEL_COARSE_G2_SHIFT (0U)
/*! PLL_ANA_LPF_C_SEL_COARSE_G2 - [GEN2] [Coarse Mode] */
#define PCIE_PHY_CMN_REG01A_PLL_ANA_LPF_C_SEL_COARSE_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG01A_PLL_ANA_LPF_C_SEL_COARSE_G2_SHIFT)) & PCIE_PHY_CMN_REG01A_PLL_ANA_LPF_C_SEL_COARSE_G2_MASK)

#define PCIE_PHY_CMN_REG01A_PLL_ANA_LPF_C_SEL_COARSE_G1_MASK (0x38U)
#define PCIE_PHY_CMN_REG01A_PLL_ANA_LPF_C_SEL_COARSE_G1_SHIFT (3U)
/*! PLL_ANA_LPF_C_SEL_COARSE_G1 - [GEN1] [Coarse Mode] PLL loop filter capacitor control */
#define PCIE_PHY_CMN_REG01A_PLL_ANA_LPF_C_SEL_COARSE_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG01A_PLL_ANA_LPF_C_SEL_COARSE_G1_SHIFT)) & PCIE_PHY_CMN_REG01A_PLL_ANA_LPF_C_SEL_COARSE_G1_MASK)
/*! @} */

/*! @name CMN_REG01B -  */
/*! @{ */

#define PCIE_PHY_CMN_REG01B_PLL_ANA_LPF_C_SEL_COARSE_G4_MASK (0x7U)
#define PCIE_PHY_CMN_REG01B_PLL_ANA_LPF_C_SEL_COARSE_G4_SHIFT (0U)
/*! PLL_ANA_LPF_C_SEL_COARSE_G4 - [GEN4] [Coarse Mode] */
#define PCIE_PHY_CMN_REG01B_PLL_ANA_LPF_C_SEL_COARSE_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG01B_PLL_ANA_LPF_C_SEL_COARSE_G4_SHIFT)) & PCIE_PHY_CMN_REG01B_PLL_ANA_LPF_C_SEL_COARSE_G4_MASK)

#define PCIE_PHY_CMN_REG01B_PLL_ANA_LPF_C_SEL_COARSE_G3_MASK (0x38U)
#define PCIE_PHY_CMN_REG01B_PLL_ANA_LPF_C_SEL_COARSE_G3_SHIFT (3U)
/*! PLL_ANA_LPF_C_SEL_COARSE_G3 - [GEN3] [Coarse Mode] */
#define PCIE_PHY_CMN_REG01B_PLL_ANA_LPF_C_SEL_COARSE_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG01B_PLL_ANA_LPF_C_SEL_COARSE_G3_SHIFT)) & PCIE_PHY_CMN_REG01B_PLL_ANA_LPF_C_SEL_COARSE_G3_MASK)
/*! @} */

/*! @name CMN_REG01C -  */
/*! @{ */

#define PCIE_PHY_CMN_REG01C_PLL_ANA_LPF_C_SEL_FINE_G2_MASK (0x7U)
#define PCIE_PHY_CMN_REG01C_PLL_ANA_LPF_C_SEL_FINE_G2_SHIFT (0U)
/*! PLL_ANA_LPF_C_SEL_FINE_G2 - [GEN2] [Fine Mode] */
#define PCIE_PHY_CMN_REG01C_PLL_ANA_LPF_C_SEL_FINE_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG01C_PLL_ANA_LPF_C_SEL_FINE_G2_SHIFT)) & PCIE_PHY_CMN_REG01C_PLL_ANA_LPF_C_SEL_FINE_G2_MASK)

#define PCIE_PHY_CMN_REG01C_PLL_ANA_LPF_C_SEL_FINE_G1_MASK (0x38U)
#define PCIE_PHY_CMN_REG01C_PLL_ANA_LPF_C_SEL_FINE_G1_SHIFT (3U)
/*! PLL_ANA_LPF_C_SEL_FINE_G1 - [GEN1] [Fine Mode] PLL loop filter capacitor control */
#define PCIE_PHY_CMN_REG01C_PLL_ANA_LPF_C_SEL_FINE_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG01C_PLL_ANA_LPF_C_SEL_FINE_G1_SHIFT)) & PCIE_PHY_CMN_REG01C_PLL_ANA_LPF_C_SEL_FINE_G1_MASK)
/*! @} */

/*! @name CMN_REG01D -  */
/*! @{ */

#define PCIE_PHY_CMN_REG01D_PLL_ANA_LPF_C_SEL_FINE_G4_MASK (0x7U)
#define PCIE_PHY_CMN_REG01D_PLL_ANA_LPF_C_SEL_FINE_G4_SHIFT (0U)
/*! PLL_ANA_LPF_C_SEL_FINE_G4 - [GEN4] [Fine Mode] */
#define PCIE_PHY_CMN_REG01D_PLL_ANA_LPF_C_SEL_FINE_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG01D_PLL_ANA_LPF_C_SEL_FINE_G4_SHIFT)) & PCIE_PHY_CMN_REG01D_PLL_ANA_LPF_C_SEL_FINE_G4_MASK)

#define PCIE_PHY_CMN_REG01D_PLL_ANA_LPF_C_SEL_FINE_G3_MASK (0x38U)
#define PCIE_PHY_CMN_REG01D_PLL_ANA_LPF_C_SEL_FINE_G3_SHIFT (3U)
/*! PLL_ANA_LPF_C_SEL_FINE_G3 - [GEN3] [Fine Mode] */
#define PCIE_PHY_CMN_REG01D_PLL_ANA_LPF_C_SEL_FINE_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG01D_PLL_ANA_LPF_C_SEL_FINE_G3_SHIFT)) & PCIE_PHY_CMN_REG01D_PLL_ANA_LPF_C_SEL_FINE_G3_MASK)
/*! @} */

/*! @name CMN_REG01E -  */
/*! @{ */

#define PCIE_PHY_CMN_REG01E_PLL_ANA_LPF_R_SEL_COARSE_G2_MASK (0xFU)
#define PCIE_PHY_CMN_REG01E_PLL_ANA_LPF_R_SEL_COARSE_G2_SHIFT (0U)
/*! PLL_ANA_LPF_R_SEL_COARSE_G2 - [GEN2] [Coarse Mode] */
#define PCIE_PHY_CMN_REG01E_PLL_ANA_LPF_R_SEL_COARSE_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG01E_PLL_ANA_LPF_R_SEL_COARSE_G2_SHIFT)) & PCIE_PHY_CMN_REG01E_PLL_ANA_LPF_R_SEL_COARSE_G2_MASK)

#define PCIE_PHY_CMN_REG01E_PLL_ANA_LPF_R_SEL_COARSE_G1_MASK (0xF0U)
#define PCIE_PHY_CMN_REG01E_PLL_ANA_LPF_R_SEL_COARSE_G1_SHIFT (4U)
/*! PLL_ANA_LPF_R_SEL_COARSE_G1 - [GEN1] [Coarse Mode] PLL loop filter resistor control */
#define PCIE_PHY_CMN_REG01E_PLL_ANA_LPF_R_SEL_COARSE_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG01E_PLL_ANA_LPF_R_SEL_COARSE_G1_SHIFT)) & PCIE_PHY_CMN_REG01E_PLL_ANA_LPF_R_SEL_COARSE_G1_MASK)
/*! @} */

/*! @name CMN_REG01F -  */
/*! @{ */

#define PCIE_PHY_CMN_REG01F_PLL_ANA_LPF_R_SEL_COARSE_G4_MASK (0xFU)
#define PCIE_PHY_CMN_REG01F_PLL_ANA_LPF_R_SEL_COARSE_G4_SHIFT (0U)
/*! PLL_ANA_LPF_R_SEL_COARSE_G4 - [GEN4] [Coarse Mode] */
#define PCIE_PHY_CMN_REG01F_PLL_ANA_LPF_R_SEL_COARSE_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG01F_PLL_ANA_LPF_R_SEL_COARSE_G4_SHIFT)) & PCIE_PHY_CMN_REG01F_PLL_ANA_LPF_R_SEL_COARSE_G4_MASK)

#define PCIE_PHY_CMN_REG01F_PLL_ANA_LPF_R_SEL_COARSE_G3_MASK (0xF0U)
#define PCIE_PHY_CMN_REG01F_PLL_ANA_LPF_R_SEL_COARSE_G3_SHIFT (4U)
/*! PLL_ANA_LPF_R_SEL_COARSE_G3 - [GEN3] [Coarse Mode] */
#define PCIE_PHY_CMN_REG01F_PLL_ANA_LPF_R_SEL_COARSE_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG01F_PLL_ANA_LPF_R_SEL_COARSE_G3_SHIFT)) & PCIE_PHY_CMN_REG01F_PLL_ANA_LPF_R_SEL_COARSE_G3_MASK)
/*! @} */

/*! @name CMN_REG020 -  */
/*! @{ */

#define PCIE_PHY_CMN_REG020_PLL_ANA_LPF_R_SEL_FINE_G2_MASK (0xFU)
#define PCIE_PHY_CMN_REG020_PLL_ANA_LPF_R_SEL_FINE_G2_SHIFT (0U)
/*! PLL_ANA_LPF_R_SEL_FINE_G2 - [GEN2] [Fine Mode] */
#define PCIE_PHY_CMN_REG020_PLL_ANA_LPF_R_SEL_FINE_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG020_PLL_ANA_LPF_R_SEL_FINE_G2_SHIFT)) & PCIE_PHY_CMN_REG020_PLL_ANA_LPF_R_SEL_FINE_G2_MASK)

#define PCIE_PHY_CMN_REG020_PLL_ANA_LPF_R_SEL_FINE_G1_MASK (0xF0U)
#define PCIE_PHY_CMN_REG020_PLL_ANA_LPF_R_SEL_FINE_G1_SHIFT (4U)
/*! PLL_ANA_LPF_R_SEL_FINE_G1 - [GEN1] [Fine Mode] PLL loop filter resistor control */
#define PCIE_PHY_CMN_REG020_PLL_ANA_LPF_R_SEL_FINE_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG020_PLL_ANA_LPF_R_SEL_FINE_G1_SHIFT)) & PCIE_PHY_CMN_REG020_PLL_ANA_LPF_R_SEL_FINE_G1_MASK)
/*! @} */

/*! @name CMN_REG021 -  */
/*! @{ */

#define PCIE_PHY_CMN_REG021_PLL_ANA_LPF_R_SEL_FINE_G4_MASK (0xFU)
#define PCIE_PHY_CMN_REG021_PLL_ANA_LPF_R_SEL_FINE_G4_SHIFT (0U)
/*! PLL_ANA_LPF_R_SEL_FINE_G4 - [GEN4] [Fine Mode] */
#define PCIE_PHY_CMN_REG021_PLL_ANA_LPF_R_SEL_FINE_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG021_PLL_ANA_LPF_R_SEL_FINE_G4_SHIFT)) & PCIE_PHY_CMN_REG021_PLL_ANA_LPF_R_SEL_FINE_G4_MASK)

#define PCIE_PHY_CMN_REG021_PLL_ANA_LPF_R_SEL_FINE_G3_MASK (0xF0U)
#define PCIE_PHY_CMN_REG021_PLL_ANA_LPF_R_SEL_FINE_G3_SHIFT (4U)
/*! PLL_ANA_LPF_R_SEL_FINE_G3 - [GEN3] [Fine Mode] */
#define PCIE_PHY_CMN_REG021_PLL_ANA_LPF_R_SEL_FINE_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG021_PLL_ANA_LPF_R_SEL_FINE_G3_SHIFT)) & PCIE_PHY_CMN_REG021_PLL_ANA_LPF_R_SEL_FINE_G3_MASK)
/*! @} */

/*! @name CMN_REG022 -  */
/*! @{ */

#define PCIE_PHY_CMN_REG022_ANA_PLL_ANA_RING_IQ_DIV_EN_MASK (0x1U)
#define PCIE_PHY_CMN_REG022_ANA_PLL_ANA_RING_IQ_DIV_EN_SHIFT (0U)
/*! ANA_PLL_ANA_RING_IQ_DIV_EN - I/Q divider enable for PLL ring VCO clock */
#define PCIE_PHY_CMN_REG022_ANA_PLL_ANA_RING_IQ_DIV_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG022_ANA_PLL_ANA_RING_IQ_DIV_EN_SHIFT)) & PCIE_PHY_CMN_REG022_ANA_PLL_ANA_RING_IQ_DIV_EN_MASK)

#define PCIE_PHY_CMN_REG022_ANA_PLL_ANA_RING_DCC_EN_MASK (0x1EU)
#define PCIE_PHY_CMN_REG022_ANA_PLL_ANA_RING_DCC_EN_SHIFT (1U)
/*! ANA_PLL_ANA_RING_DCC_EN - PLL ring VCO DCC enable for each phase */
#define PCIE_PHY_CMN_REG022_ANA_PLL_ANA_RING_DCC_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG022_ANA_PLL_ANA_RING_DCC_EN_SHIFT)) & PCIE_PHY_CMN_REG022_ANA_PLL_ANA_RING_DCC_EN_MASK)
/*! @} */

/*! @name CMN_REG023 -  */
/*! @{ */

#define PCIE_PHY_CMN_REG023_ANA_PLL_ANA_VCI_TEST_EN_MASK (0x1U)
#define PCIE_PHY_CMN_REG023_ANA_PLL_ANA_VCI_TEST_EN_SHIFT (0U)
/*! ANA_PLL_ANA_VCI_TEST_EN - PLL VCO test mode enable */
#define PCIE_PHY_CMN_REG023_ANA_PLL_ANA_VCI_TEST_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG023_ANA_PLL_ANA_VCI_TEST_EN_SHIFT)) & PCIE_PHY_CMN_REG023_ANA_PLL_ANA_VCI_TEST_EN_MASK)

#define PCIE_PHY_CMN_REG023_ANA_PLL_ANA_VCI_SEL_MASK (0xEU)
#define PCIE_PHY_CMN_REG023_ANA_PLL_ANA_VCI_SEL_SHIFT (1U)
/*! ANA_PLL_ANA_VCI_SEL - PLL control voltage selection in AFC or open-loop test */
#define PCIE_PHY_CMN_REG023_ANA_PLL_ANA_VCI_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG023_ANA_PLL_ANA_VCI_SEL_SHIFT)) & PCIE_PHY_CMN_REG023_ANA_PLL_ANA_VCI_SEL_MASK)

#define PCIE_PHY_CMN_REG023_PLL_ANA_RING_PI_RATIO_CTRL_FINE_MASK (0x30U)
#define PCIE_PHY_CMN_REG023_PLL_ANA_RING_PI_RATIO_CTRL_FINE_SHIFT (4U)
/*! PLL_ANA_RING_PI_RATIO_CTRL_FINE - Ratio between proportional and integral path gain */
#define PCIE_PHY_CMN_REG023_PLL_ANA_RING_PI_RATIO_CTRL_FINE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG023_PLL_ANA_RING_PI_RATIO_CTRL_FINE_SHIFT)) & PCIE_PHY_CMN_REG023_PLL_ANA_RING_PI_RATIO_CTRL_FINE_MASK)

#define PCIE_PHY_CMN_REG023_PLL_ANA_RING_PI_RATIO_CTRL_COARSE_MASK (0xC0U)
#define PCIE_PHY_CMN_REG023_PLL_ANA_RING_PI_RATIO_CTRL_COARSE_SHIFT (6U)
/*! PLL_ANA_RING_PI_RATIO_CTRL_COARSE - Ratio between proportional and integral path gain */
#define PCIE_PHY_CMN_REG023_PLL_ANA_RING_PI_RATIO_CTRL_COARSE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG023_PLL_ANA_RING_PI_RATIO_CTRL_COARSE_SHIFT)) & PCIE_PHY_CMN_REG023_PLL_ANA_RING_PI_RATIO_CTRL_COARSE_MASK)
/*! @} */

/*! @name CMN_REG024 -  */
/*! @{ */

#define PCIE_PHY_CMN_REG024_ANA_PLL_EOM_PH_FINE_STEP_MASK (0x1U)
#define PCIE_PHY_CMN_REG024_ANA_PLL_EOM_PH_FINE_STEP_SHIFT (0U)
/*! ANA_PLL_EOM_PH_FINE_STEP - EOM phase resolution enhancement */
#define PCIE_PHY_CMN_REG024_ANA_PLL_EOM_PH_FINE_STEP(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG024_ANA_PLL_EOM_PH_FINE_STEP_SHIFT)) & PCIE_PHY_CMN_REG024_ANA_PLL_EOM_PH_FINE_STEP_MASK)

#define PCIE_PHY_CMN_REG024_ANA_PLL_ATB_SEL_MASK (0xFEU)
#define PCIE_PHY_CMN_REG024_ANA_PLL_ATB_SEL_SHIFT (1U)
/*! ANA_PLL_ATB_SEL - Select PLL ATB */
#define PCIE_PHY_CMN_REG024_ANA_PLL_ATB_SEL(x)   (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG024_ANA_PLL_ATB_SEL_SHIFT)) & PCIE_PHY_CMN_REG024_ANA_PLL_ATB_SEL_MASK)
/*! @} */

/*! @name CMN_REG025 -  */
/*! @{ */

#define PCIE_PHY_CMN_REG025_ANA_PLL_FLD_FAST_BYPASS_MASK (0x1U)
#define PCIE_PHY_CMN_REG025_ANA_PLL_FLD_FAST_BYPASS_SHIFT (0U)
/*! ANA_PLL_FLD_FAST_BYPASS - PLL fast frequency lock detection bypass */
#define PCIE_PHY_CMN_REG025_ANA_PLL_FLD_FAST_BYPASS(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG025_ANA_PLL_FLD_FAST_BYPASS_SHIFT)) & PCIE_PHY_CMN_REG025_ANA_PLL_FLD_FAST_BYPASS_MASK)

#define PCIE_PHY_CMN_REG025_ANA_PLL_EOM_PH_SEL_MASK (0x1EU)
#define PCIE_PHY_CMN_REG025_ANA_PLL_EOM_PH_SEL_SHIFT (1U)
/*! ANA_PLL_EOM_PH_SEL - EOM phase selection */
#define PCIE_PHY_CMN_REG025_ANA_PLL_EOM_PH_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG025_ANA_PLL_EOM_PH_SEL_SHIFT)) & PCIE_PHY_CMN_REG025_ANA_PLL_EOM_PH_SEL_MASK)

#define PCIE_PHY_CMN_REG025_ANA_PLL_EOM_PH_FIX_MASK (0x20U)
#define PCIE_PHY_CMN_REG025_ANA_PLL_EOM_PH_FIX_SHIFT (5U)
/*! ANA_PLL_EOM_PH_FIX - Phase shift enable for EOM */
#define PCIE_PHY_CMN_REG025_ANA_PLL_EOM_PH_FIX(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG025_ANA_PLL_EOM_PH_FIX_SHIFT)) & PCIE_PHY_CMN_REG025_ANA_PLL_EOM_PH_FIX_MASK)
/*! @} */

/*! @name CMN_REG026 -  */
/*! @{ */

#define PCIE_PHY_CMN_REG026_ANA_PLL_FLD_LOCK_TOL_NUM_MASK (0x1FU)
#define PCIE_PHY_CMN_REG026_ANA_PLL_FLD_LOCK_TOL_NUM_SHIFT (0U)
/*! ANA_PLL_FLD_LOCK_TOL_NUM - FLD lock tolerance setting */
#define PCIE_PHY_CMN_REG026_ANA_PLL_FLD_LOCK_TOL_NUM(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG026_ANA_PLL_FLD_LOCK_TOL_NUM_SHIFT)) & PCIE_PHY_CMN_REG026_ANA_PLL_FLD_LOCK_TOL_NUM_MASK)

#define PCIE_PHY_CMN_REG026_ANA_PLL_FLD_FAST_SETTLE_NUM_MASK (0xE0U)
#define PCIE_PHY_CMN_REG026_ANA_PLL_FLD_FAST_SETTLE_NUM_SHIFT (5U)
/*! ANA_PLL_FLD_FAST_SETTLE_NUM - Number of reference clock cycle to check VCO stabilization in fast FLD */
#define PCIE_PHY_CMN_REG026_ANA_PLL_FLD_FAST_SETTLE_NUM(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG026_ANA_PLL_FLD_FAST_SETTLE_NUM_SHIFT)) & PCIE_PHY_CMN_REG026_ANA_PLL_FLD_FAST_SETTLE_NUM_MASK)
/*! @} */

/*! @name CMN_REG027 -  */
/*! @{ */

#define PCIE_PHY_CMN_REG027_ANA_PLL_FLD_SLOW_BYPASS_MASK (0x1U)
#define PCIE_PHY_CMN_REG027_ANA_PLL_FLD_SLOW_BYPASS_SHIFT (0U)
/*! ANA_PLL_FLD_SLOW_BYPASS - PLL slow frequency lock detection bypass */
#define PCIE_PHY_CMN_REG027_ANA_PLL_FLD_SLOW_BYPASS(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG027_ANA_PLL_FLD_SLOW_BYPASS_SHIFT)) & PCIE_PHY_CMN_REG027_ANA_PLL_FLD_SLOW_BYPASS_MASK)

#define PCIE_PHY_CMN_REG027_ANA_PLL_FLD_NON_CONTINUOUS_MODE_MASK (0x2U)
#define PCIE_PHY_CMN_REG027_ANA_PLL_FLD_NON_CONTINUOUS_MODE_SHIFT (1U)
/*! ANA_PLL_FLD_NON_CONTINUOUS_MODE - Check frequency lock detection of PLL */
#define PCIE_PHY_CMN_REG027_ANA_PLL_FLD_NON_CONTINUOUS_MODE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG027_ANA_PLL_FLD_NON_CONTINUOUS_MODE_SHIFT)) & PCIE_PHY_CMN_REG027_ANA_PLL_FLD_NON_CONTINUOUS_MODE_MASK)
/*! @} */

/*! @name CMN_REG028 -  */
/*! @{ */

#define PCIE_PHY_CMN_REG028_PLL_PI_EN_G4_MASK    (0x1U)
#define PCIE_PHY_CMN_REG028_PLL_PI_EN_G4_SHIFT   (0U)
/*! PLL_PI_EN_G4 - [GEN4] */
#define PCIE_PHY_CMN_REG028_PLL_PI_EN_G4(x)      (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG028_PLL_PI_EN_G4_SHIFT)) & PCIE_PHY_CMN_REG028_PLL_PI_EN_G4_MASK)

#define PCIE_PHY_CMN_REG028_PLL_PI_EN_G3_MASK    (0x2U)
#define PCIE_PHY_CMN_REG028_PLL_PI_EN_G3_SHIFT   (1U)
/*! PLL_PI_EN_G3 - [GEN3] */
#define PCIE_PHY_CMN_REG028_PLL_PI_EN_G3(x)      (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG028_PLL_PI_EN_G3_SHIFT)) & PCIE_PHY_CMN_REG028_PLL_PI_EN_G3_MASK)

#define PCIE_PHY_CMN_REG028_PLL_PI_EN_G2_MASK    (0x4U)
#define PCIE_PHY_CMN_REG028_PLL_PI_EN_G2_SHIFT   (2U)
/*! PLL_PI_EN_G2 - [GEN2] */
#define PCIE_PHY_CMN_REG028_PLL_PI_EN_G2(x)      (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG028_PLL_PI_EN_G2_SHIFT)) & PCIE_PHY_CMN_REG028_PLL_PI_EN_G2_MASK)

#define PCIE_PHY_CMN_REG028_PLL_PI_EN_G1_MASK    (0x8U)
#define PCIE_PHY_CMN_REG028_PLL_PI_EN_G1_SHIFT   (3U)
/*! PLL_PI_EN_G1 - [GEN1] PLL phase interpolator enable */
#define PCIE_PHY_CMN_REG028_PLL_PI_EN_G1(x)      (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG028_PLL_PI_EN_G1_SHIFT)) & PCIE_PHY_CMN_REG028_PLL_PI_EN_G1_MASK)
/*! @} */

/*! @name CMN_REG029 -  */
/*! @{ */

#define PCIE_PHY_CMN_REG029_PLL_PI_STR_G2_MASK   (0xFU)
#define PCIE_PHY_CMN_REG029_PLL_PI_STR_G2_SHIFT  (0U)
/*! PLL_PI_STR_G2 - [GEN2] */
#define PCIE_PHY_CMN_REG029_PLL_PI_STR_G2(x)     (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG029_PLL_PI_STR_G2_SHIFT)) & PCIE_PHY_CMN_REG029_PLL_PI_STR_G2_MASK)

#define PCIE_PHY_CMN_REG029_PLL_PI_STR_G1_MASK   (0xF0U)
#define PCIE_PHY_CMN_REG029_PLL_PI_STR_G1_SHIFT  (4U)
/*! PLL_PI_STR_G1 - [GEN1] PLL phase interpolator input buffer strength control for Gen3 and Gen4 ( for 8GHz VCO ) */
#define PCIE_PHY_CMN_REG029_PLL_PI_STR_G1(x)     (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG029_PLL_PI_STR_G1_SHIFT)) & PCIE_PHY_CMN_REG029_PLL_PI_STR_G1_MASK)
/*! @} */

/*! @name CMN_REG02A -  */
/*! @{ */

#define PCIE_PHY_CMN_REG02A_PLL_PI_STR_G4_MASK   (0xFU)
#define PCIE_PHY_CMN_REG02A_PLL_PI_STR_G4_SHIFT  (0U)
/*! PLL_PI_STR_G4 - [GEN4] */
#define PCIE_PHY_CMN_REG02A_PLL_PI_STR_G4(x)     (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG02A_PLL_PI_STR_G4_SHIFT)) & PCIE_PHY_CMN_REG02A_PLL_PI_STR_G4_MASK)

#define PCIE_PHY_CMN_REG02A_PLL_PI_STR_G3_MASK   (0xF0U)
#define PCIE_PHY_CMN_REG02A_PLL_PI_STR_G3_SHIFT  (4U)
/*! PLL_PI_STR_G3 - [GEN3] */
#define PCIE_PHY_CMN_REG02A_PLL_PI_STR_G3(x)     (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG02A_PLL_PI_STR_G3_SHIFT)) & PCIE_PHY_CMN_REG02A_PLL_PI_STR_G3_MASK)
/*! @} */

/*! @name CMN_REG02B -  */
/*! @{ */

#define PCIE_PHY_CMN_REG02B_PLL_PMS_PDIV_RSTN_MASK (0x1U)
#define PCIE_PHY_CMN_REG02B_PLL_PMS_PDIV_RSTN_SHIFT (0U)
/*! PLL_PMS_PDIV_RSTN - PLL pre-divider reset */
#define PCIE_PHY_CMN_REG02B_PLL_PMS_PDIV_RSTN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG02B_PLL_PMS_PDIV_RSTN_SHIFT)) & PCIE_PHY_CMN_REG02B_PLL_PMS_PDIV_RSTN_MASK)

#define PCIE_PHY_CMN_REG02B_OVRD_PLL_PMS_PDIV_RSTN_MASK (0x2U)
#define PCIE_PHY_CMN_REG02B_OVRD_PLL_PMS_PDIV_RSTN_SHIFT (1U)
/*! OVRD_PLL_PMS_PDIV_RSTN - Override enable for pll_pms_pdiv_rstn */
#define PCIE_PHY_CMN_REG02B_OVRD_PLL_PMS_PDIV_RSTN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG02B_OVRD_PLL_PMS_PDIV_RSTN_SHIFT)) & PCIE_PHY_CMN_REG02B_OVRD_PLL_PMS_PDIV_RSTN_MASK)

#define PCIE_PHY_CMN_REG02B_PLL_PMS_MDIV_RSTN_MASK (0x4U)
#define PCIE_PHY_CMN_REG02B_PLL_PMS_MDIV_RSTN_SHIFT (2U)
/*! PLL_PMS_MDIV_RSTN - PLL main divider reset */
#define PCIE_PHY_CMN_REG02B_PLL_PMS_MDIV_RSTN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG02B_PLL_PMS_MDIV_RSTN_SHIFT)) & PCIE_PHY_CMN_REG02B_PLL_PMS_MDIV_RSTN_MASK)

#define PCIE_PHY_CMN_REG02B_OVRD_PLL_PMS_MDIV_RSTN_MASK (0x8U)
#define PCIE_PHY_CMN_REG02B_OVRD_PLL_PMS_MDIV_RSTN_SHIFT (3U)
/*! OVRD_PLL_PMS_MDIV_RSTN - Override enable for pll_pms_mdiv_rstn */
#define PCIE_PHY_CMN_REG02B_OVRD_PLL_PMS_MDIV_RSTN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG02B_OVRD_PLL_PMS_MDIV_RSTN_SHIFT)) & PCIE_PHY_CMN_REG02B_OVRD_PLL_PMS_MDIV_RSTN_MASK)
/*! @} */

/*! @name CMN_REG02C -  */
/*! @{ */

#define PCIE_PHY_CMN_REG02C_PLL_PMS_MDIV_AFC_G1_MASK (0xFFU)
#define PCIE_PHY_CMN_REG02C_PLL_PMS_MDIV_AFC_G1_SHIFT (0U)
/*! PLL_PMS_MDIV_AFC_G1 - [GEN1] PLL AFC target value (fVCO/fREF) setting */
#define PCIE_PHY_CMN_REG02C_PLL_PMS_MDIV_AFC_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG02C_PLL_PMS_MDIV_AFC_G1_SHIFT)) & PCIE_PHY_CMN_REG02C_PLL_PMS_MDIV_AFC_G1_MASK)
/*! @} */

/*! @name CMN_REG02D -  */
/*! @{ */

#define PCIE_PHY_CMN_REG02D_PLL_PMS_MDIV_AFC_G2_MASK (0xFFU)
#define PCIE_PHY_CMN_REG02D_PLL_PMS_MDIV_AFC_G2_SHIFT (0U)
/*! PLL_PMS_MDIV_AFC_G2 - [GEN2] */
#define PCIE_PHY_CMN_REG02D_PLL_PMS_MDIV_AFC_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG02D_PLL_PMS_MDIV_AFC_G2_SHIFT)) & PCIE_PHY_CMN_REG02D_PLL_PMS_MDIV_AFC_G2_MASK)
/*! @} */

/*! @name CMN_REG02E -  */
/*! @{ */

#define PCIE_PHY_CMN_REG02E_PLL_PMS_MDIV_AFC_G3_MASK (0xFFU)
#define PCIE_PHY_CMN_REG02E_PLL_PMS_MDIV_AFC_G3_SHIFT (0U)
/*! PLL_PMS_MDIV_AFC_G3 - [GEN3] */
#define PCIE_PHY_CMN_REG02E_PLL_PMS_MDIV_AFC_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG02E_PLL_PMS_MDIV_AFC_G3_SHIFT)) & PCIE_PHY_CMN_REG02E_PLL_PMS_MDIV_AFC_G3_MASK)
/*! @} */

/*! @name CMN_REG02F -  */
/*! @{ */

#define PCIE_PHY_CMN_REG02F_PLL_PMS_MDIV_AFC_G4_MASK (0xFFU)
#define PCIE_PHY_CMN_REG02F_PLL_PMS_MDIV_AFC_G4_SHIFT (0U)
/*! PLL_PMS_MDIV_AFC_G4 - [GEN4] */
#define PCIE_PHY_CMN_REG02F_PLL_PMS_MDIV_AFC_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG02F_PLL_PMS_MDIV_AFC_G4_SHIFT)) & PCIE_PHY_CMN_REG02F_PLL_PMS_MDIV_AFC_G4_MASK)
/*! @} */

/*! @name CMN_REG030 -  */
/*! @{ */

#define PCIE_PHY_CMN_REG030_PLL_PMS_MDIV_G1_MASK (0xFFU)
#define PCIE_PHY_CMN_REG030_PLL_PMS_MDIV_G1_SHIFT (0U)
/*! PLL_PMS_MDIV_G1 - [GEN1] PLL main divider setting */
#define PCIE_PHY_CMN_REG030_PLL_PMS_MDIV_G1(x)   (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG030_PLL_PMS_MDIV_G1_SHIFT)) & PCIE_PHY_CMN_REG030_PLL_PMS_MDIV_G1_MASK)
/*! @} */

/*! @name CMN_REG031 -  */
/*! @{ */

#define PCIE_PHY_CMN_REG031_PLL_PMS_MDIV_G2_MASK (0xFFU)
#define PCIE_PHY_CMN_REG031_PLL_PMS_MDIV_G2_SHIFT (0U)
/*! PLL_PMS_MDIV_G2 - [GEN2] */
#define PCIE_PHY_CMN_REG031_PLL_PMS_MDIV_G2(x)   (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG031_PLL_PMS_MDIV_G2_SHIFT)) & PCIE_PHY_CMN_REG031_PLL_PMS_MDIV_G2_MASK)
/*! @} */

/*! @name CMN_REG032 -  */
/*! @{ */

#define PCIE_PHY_CMN_REG032_PLL_PMS_MDIV_G3_MASK (0xFFU)
#define PCIE_PHY_CMN_REG032_PLL_PMS_MDIV_G3_SHIFT (0U)
/*! PLL_PMS_MDIV_G3 - [GEN3] */
#define PCIE_PHY_CMN_REG032_PLL_PMS_MDIV_G3(x)   (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG032_PLL_PMS_MDIV_G3_SHIFT)) & PCIE_PHY_CMN_REG032_PLL_PMS_MDIV_G3_MASK)
/*! @} */

/*! @name CMN_REG033 -  */
/*! @{ */

#define PCIE_PHY_CMN_REG033_PLL_PMS_MDIV_G4_MASK (0xFFU)
#define PCIE_PHY_CMN_REG033_PLL_PMS_MDIV_G4_SHIFT (0U)
/*! PLL_PMS_MDIV_G4 - [GEN4] */
#define PCIE_PHY_CMN_REG033_PLL_PMS_MDIV_G4(x)   (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG033_PLL_PMS_MDIV_G4_SHIFT)) & PCIE_PHY_CMN_REG033_PLL_PMS_MDIV_G4_MASK)
/*! @} */

/*! @name CMN_REG034 -  */
/*! @{ */

#define PCIE_PHY_CMN_REG034_ANA_PLL_PMS_PDIV_MASK (0xFU)
#define PCIE_PHY_CMN_REG034_ANA_PLL_PMS_PDIV_SHIFT (0U)
/*! ANA_PLL_PMS_PDIV - PLL pre-divider setting */
#define PCIE_PHY_CMN_REG034_ANA_PLL_PMS_PDIV(x)  (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG034_ANA_PLL_PMS_PDIV_SHIFT)) & PCIE_PHY_CMN_REG034_ANA_PLL_PMS_PDIV_MASK)

#define PCIE_PHY_CMN_REG034_ANA_PLL_PMS_MDIV_X2_EN_MASK (0x10U)
#define PCIE_PHY_CMN_REG034_ANA_PLL_PMS_MDIV_X2_EN_SHIFT (4U)
/*! ANA_PLL_PMS_MDIV_X2_EN - PLL main divider extra X2 enable */
#define PCIE_PHY_CMN_REG034_ANA_PLL_PMS_MDIV_X2_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG034_ANA_PLL_PMS_MDIV_X2_EN_SHIFT)) & PCIE_PHY_CMN_REG034_ANA_PLL_PMS_MDIV_X2_EN_MASK)
/*! @} */

/*! @name CMN_REG035 -  */
/*! @{ */

#define PCIE_PHY_CMN_REG035_ANA_PLL_PMS_REFDIV_MASK (0xFU)
#define PCIE_PHY_CMN_REG035_ANA_PLL_PMS_REFDIV_SHIFT (0U)
/*! ANA_PLL_PMS_REFDIV - PLL reference clock divider setting */
#define PCIE_PHY_CMN_REG035_ANA_PLL_PMS_REFDIV(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG035_ANA_PLL_PMS_REFDIV_SHIFT)) & PCIE_PHY_CMN_REG035_ANA_PLL_PMS_REFDIV_MASK)
/*! @} */

/*! @name CMN_REG036 -  */
/*! @{ */

#define PCIE_PHY_CMN_REG036_PLL_PMS_SDIV_G2_MASK (0xFU)
#define PCIE_PHY_CMN_REG036_PLL_PMS_SDIV_G2_SHIFT (0U)
/*! PLL_PMS_SDIV_G2 - [GEN2] */
#define PCIE_PHY_CMN_REG036_PLL_PMS_SDIV_G2(x)   (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG036_PLL_PMS_SDIV_G2_SHIFT)) & PCIE_PHY_CMN_REG036_PLL_PMS_SDIV_G2_MASK)

#define PCIE_PHY_CMN_REG036_PLL_PMS_SDIV_G1_MASK (0xF0U)
#define PCIE_PHY_CMN_REG036_PLL_PMS_SDIV_G1_SHIFT (4U)
/*! PLL_PMS_SDIV_G1 - [GEN1] PLL post divider setting */
#define PCIE_PHY_CMN_REG036_PLL_PMS_SDIV_G1(x)   (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG036_PLL_PMS_SDIV_G1_SHIFT)) & PCIE_PHY_CMN_REG036_PLL_PMS_SDIV_G1_MASK)
/*! @} */

/*! @name CMN_REG037 -  */
/*! @{ */

#define PCIE_PHY_CMN_REG037_PLL_PMS_SDIV_G4_MASK (0xFU)
#define PCIE_PHY_CMN_REG037_PLL_PMS_SDIV_G4_SHIFT (0U)
/*! PLL_PMS_SDIV_G4 - [GEN4] */
#define PCIE_PHY_CMN_REG037_PLL_PMS_SDIV_G4(x)   (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG037_PLL_PMS_SDIV_G4_SHIFT)) & PCIE_PHY_CMN_REG037_PLL_PMS_SDIV_G4_MASK)

#define PCIE_PHY_CMN_REG037_PLL_PMS_SDIV_G3_MASK (0xF0U)
#define PCIE_PHY_CMN_REG037_PLL_PMS_SDIV_G3_SHIFT (4U)
/*! PLL_PMS_SDIV_G3 - [GEN3] */
#define PCIE_PHY_CMN_REG037_PLL_PMS_SDIV_G3(x)   (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG037_PLL_PMS_SDIV_G3_SHIFT)) & PCIE_PHY_CMN_REG037_PLL_PMS_SDIV_G3_MASK)
/*! @} */

/*! @name CMN_REG038 -  */
/*! @{ */

#define PCIE_PHY_CMN_REG038_ANA_PLL_REF_CHOPPER_CLK_EN_MASK (0x1U)
#define PCIE_PHY_CMN_REG038_ANA_PLL_REF_CHOPPER_CLK_EN_SHIFT (0U)
/*! ANA_PLL_REF_CHOPPER_CLK_EN - Chopper clk enable */
#define PCIE_PHY_CMN_REG038_ANA_PLL_REF_CHOPPER_CLK_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG038_ANA_PLL_REF_CHOPPER_CLK_EN_SHIFT)) & PCIE_PHY_CMN_REG038_ANA_PLL_REF_CHOPPER_CLK_EN_MASK)

#define PCIE_PHY_CMN_REG038_ANA_PLL_REF_CHOPPER_CLK_DIV_SEL_MASK (0x6U)
#define PCIE_PHY_CMN_REG038_ANA_PLL_REF_CHOPPER_CLK_DIV_SEL_SHIFT (1U)
/*! ANA_PLL_REF_CHOPPER_CLK_DIV_SEL - Chopper clk divider value */
#define PCIE_PHY_CMN_REG038_ANA_PLL_REF_CHOPPER_CLK_DIV_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG038_ANA_PLL_REF_CHOPPER_CLK_DIV_SEL_SHIFT)) & PCIE_PHY_CMN_REG038_ANA_PLL_REF_CHOPPER_CLK_DIV_SEL_MASK)

#define PCIE_PHY_CMN_REG038_ANA_PLL_REF_BYPASS_CLK_SEL_MASK (0x18U)
#define PCIE_PHY_CMN_REG038_ANA_PLL_REF_BYPASS_CLK_SEL_SHIFT (3U)
/*! ANA_PLL_REF_BYPASS_CLK_SEL - PLL Bypass clock selection */
#define PCIE_PHY_CMN_REG038_ANA_PLL_REF_BYPASS_CLK_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG038_ANA_PLL_REF_BYPASS_CLK_SEL_SHIFT)) & PCIE_PHY_CMN_REG038_ANA_PLL_REF_BYPASS_CLK_SEL_MASK)

#define PCIE_PHY_CMN_REG038_PLL_REF_CHOPPER_CLK_DIV_RSTN_MASK (0x20U)
#define PCIE_PHY_CMN_REG038_PLL_REF_CHOPPER_CLK_DIV_RSTN_SHIFT (5U)
/*! PLL_REF_CHOPPER_CLK_DIV_RSTN - Chopper clk divider reset */
#define PCIE_PHY_CMN_REG038_PLL_REF_CHOPPER_CLK_DIV_RSTN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG038_PLL_REF_CHOPPER_CLK_DIV_RSTN_SHIFT)) & PCIE_PHY_CMN_REG038_PLL_REF_CHOPPER_CLK_DIV_RSTN_MASK)

#define PCIE_PHY_CMN_REG038_OVRD_PLL_REF_CHOPPER_CLK_DIV_RSTN_MASK (0x40U)
#define PCIE_PHY_CMN_REG038_OVRD_PLL_REF_CHOPPER_CLK_DIV_RSTN_SHIFT (6U)
/*! OVRD_PLL_REF_CHOPPER_CLK_DIV_RSTN - Override enable for pll_ref_chopper_clk_div_rstn */
#define PCIE_PHY_CMN_REG038_OVRD_PLL_REF_CHOPPER_CLK_DIV_RSTN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG038_OVRD_PLL_REF_CHOPPER_CLK_DIV_RSTN_SHIFT)) & PCIE_PHY_CMN_REG038_OVRD_PLL_REF_CHOPPER_CLK_DIV_RSTN_MASK)
/*! @} */

/*! @name CMN_REG039 -  */
/*! @{ */

#define PCIE_PHY_CMN_REG039_ANA_PLL_REF_DIG_CLK_SEL_MASK (0x1U)
#define PCIE_PHY_CMN_REG039_ANA_PLL_REF_DIG_CLK_SEL_SHIFT (0U)
#define PCIE_PHY_CMN_REG039_ANA_PLL_REF_DIG_CLK_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG039_ANA_PLL_REF_DIG_CLK_SEL_SHIFT)) & PCIE_PHY_CMN_REG039_ANA_PLL_REF_DIG_CLK_SEL_MASK)

#define PCIE_PHY_CMN_REG039_PLL_REF_CLK_SEL_MASK (0x6U)
#define PCIE_PHY_CMN_REG039_PLL_REF_CLK_SEL_SHIFT (1U)
/*! PLL_REF_CLK_SEL - PLL reference clock selection */
#define PCIE_PHY_CMN_REG039_PLL_REF_CLK_SEL(x)   (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG039_PLL_REF_CLK_SEL_SHIFT)) & PCIE_PHY_CMN_REG039_PLL_REF_CLK_SEL_MASK)

#define PCIE_PHY_CMN_REG039_OVRD_PLL_REF_CLK_SEL_MASK (0x8U)
#define PCIE_PHY_CMN_REG039_OVRD_PLL_REF_CLK_SEL_SHIFT (3U)
/*! OVRD_PLL_REF_CLK_SEL - Override enable for pll_ref_clk_sel */
#define PCIE_PHY_CMN_REG039_OVRD_PLL_REF_CLK_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG039_OVRD_PLL_REF_CLK_SEL_SHIFT)) & PCIE_PHY_CMN_REG039_OVRD_PLL_REF_CLK_SEL_MASK)
/*! @} */

/*! @name CMN_REG03A -  */
/*! @{ */

#define PCIE_PHY_CMN_REG03A_PLL_SDM_RSTN_MASK    (0x1U)
#define PCIE_PHY_CMN_REG03A_PLL_SDM_RSTN_SHIFT   (0U)
/*! PLL_SDM_RSTN - PLL SDM reset */
#define PCIE_PHY_CMN_REG03A_PLL_SDM_RSTN(x)      (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG03A_PLL_SDM_RSTN_SHIFT)) & PCIE_PHY_CMN_REG03A_PLL_SDM_RSTN_MASK)

#define PCIE_PHY_CMN_REG03A_OVRD_PLL_SDM_RSTN_MASK (0x2U)
#define PCIE_PHY_CMN_REG03A_OVRD_PLL_SDM_RSTN_SHIFT (1U)
/*! OVRD_PLL_SDM_RSTN - Override enable for pll_sdm_rstn */
#define PCIE_PHY_CMN_REG03A_OVRD_PLL_SDM_RSTN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG03A_OVRD_PLL_SDM_RSTN_SHIFT)) & PCIE_PHY_CMN_REG03A_OVRD_PLL_SDM_RSTN_MASK)

#define PCIE_PHY_CMN_REG03A_PLL_SDM_EN_G4_MASK   (0x4U)
#define PCIE_PHY_CMN_REG03A_PLL_SDM_EN_G4_SHIFT  (2U)
/*! PLL_SDM_EN_G4 - [GEN4] */
#define PCIE_PHY_CMN_REG03A_PLL_SDM_EN_G4(x)     (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG03A_PLL_SDM_EN_G4_SHIFT)) & PCIE_PHY_CMN_REG03A_PLL_SDM_EN_G4_MASK)

#define PCIE_PHY_CMN_REG03A_PLL_SDM_EN_G3_MASK   (0x8U)
#define PCIE_PHY_CMN_REG03A_PLL_SDM_EN_G3_SHIFT  (3U)
/*! PLL_SDM_EN_G3 - [GEN3] */
#define PCIE_PHY_CMN_REG03A_PLL_SDM_EN_G3(x)     (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG03A_PLL_SDM_EN_G3_SHIFT)) & PCIE_PHY_CMN_REG03A_PLL_SDM_EN_G3_MASK)

#define PCIE_PHY_CMN_REG03A_PLL_SDM_EN_G2_MASK   (0x10U)
#define PCIE_PHY_CMN_REG03A_PLL_SDM_EN_G2_SHIFT  (4U)
/*! PLL_SDM_EN_G2 - [GEN2] */
#define PCIE_PHY_CMN_REG03A_PLL_SDM_EN_G2(x)     (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG03A_PLL_SDM_EN_G2_SHIFT)) & PCIE_PHY_CMN_REG03A_PLL_SDM_EN_G2_MASK)

#define PCIE_PHY_CMN_REG03A_PLL_SDM_EN_G1_MASK   (0x20U)
#define PCIE_PHY_CMN_REG03A_PLL_SDM_EN_G1_SHIFT  (5U)
/*! PLL_SDM_EN_G1 - [GEN1] PLL SDM enable */
#define PCIE_PHY_CMN_REG03A_PLL_SDM_EN_G1(x)     (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG03A_PLL_SDM_EN_G1_SHIFT)) & PCIE_PHY_CMN_REG03A_PLL_SDM_EN_G1_MASK)
/*! @} */

/*! @name CMN_REG03B -  */
/*! @{ */

#define PCIE_PHY_CMN_REG03B_PLL_SDC_RSTN_MASK    (0x1U)
#define PCIE_PHY_CMN_REG03B_PLL_SDC_RSTN_SHIFT   (0U)
/*! PLL_SDC_RSTN - PLL SDM clock generation (SDC) reset */
#define PCIE_PHY_CMN_REG03B_PLL_SDC_RSTN(x)      (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG03B_PLL_SDC_RSTN_SHIFT)) & PCIE_PHY_CMN_REG03B_PLL_SDC_RSTN_MASK)

#define PCIE_PHY_CMN_REG03B_OVRD_PLL_SDC_RSTN_MASK (0x2U)
#define PCIE_PHY_CMN_REG03B_OVRD_PLL_SDC_RSTN_SHIFT (1U)
/*! OVRD_PLL_SDC_RSTN - Override enable for pll_sdc_rstn */
#define PCIE_PHY_CMN_REG03B_OVRD_PLL_SDC_RSTN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG03B_OVRD_PLL_SDC_RSTN_SHIFT)) & PCIE_PHY_CMN_REG03B_OVRD_PLL_SDC_RSTN_MASK)

#define PCIE_PHY_CMN_REG03B_PLL_SDC_FRACTIONAL_EN_G4_MASK (0x4U)
#define PCIE_PHY_CMN_REG03B_PLL_SDC_FRACTIONAL_EN_G4_SHIFT (2U)
/*! PLL_SDC_FRACTIONAL_EN_G4 - [GEN4] */
#define PCIE_PHY_CMN_REG03B_PLL_SDC_FRACTIONAL_EN_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG03B_PLL_SDC_FRACTIONAL_EN_G4_SHIFT)) & PCIE_PHY_CMN_REG03B_PLL_SDC_FRACTIONAL_EN_G4_MASK)

#define PCIE_PHY_CMN_REG03B_PLL_SDC_FRACTIONAL_EN_G3_MASK (0x8U)
#define PCIE_PHY_CMN_REG03B_PLL_SDC_FRACTIONAL_EN_G3_SHIFT (3U)
/*! PLL_SDC_FRACTIONAL_EN_G3 - [GEN3] */
#define PCIE_PHY_CMN_REG03B_PLL_SDC_FRACTIONAL_EN_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG03B_PLL_SDC_FRACTIONAL_EN_G3_SHIFT)) & PCIE_PHY_CMN_REG03B_PLL_SDC_FRACTIONAL_EN_G3_MASK)

#define PCIE_PHY_CMN_REG03B_PLL_SDC_FRACTIONAL_EN_G2_MASK (0x10U)
#define PCIE_PHY_CMN_REG03B_PLL_SDC_FRACTIONAL_EN_G2_SHIFT (4U)
/*! PLL_SDC_FRACTIONAL_EN_G2 - [GEN2] */
#define PCIE_PHY_CMN_REG03B_PLL_SDC_FRACTIONAL_EN_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG03B_PLL_SDC_FRACTIONAL_EN_G2_SHIFT)) & PCIE_PHY_CMN_REG03B_PLL_SDC_FRACTIONAL_EN_G2_MASK)

#define PCIE_PHY_CMN_REG03B_PLL_SDC_FRACTIONAL_EN_G1_MASK (0x20U)
#define PCIE_PHY_CMN_REG03B_PLL_SDC_FRACTIONAL_EN_G1_SHIFT (5U)
/*! PLL_SDC_FRACTIONAL_EN_G1 - [GEN1] Fractional clock divide in SDM clock generation */
#define PCIE_PHY_CMN_REG03B_PLL_SDC_FRACTIONAL_EN_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG03B_PLL_SDC_FRACTIONAL_EN_G1_SHIFT)) & PCIE_PHY_CMN_REG03B_PLL_SDC_FRACTIONAL_EN_G1_MASK)
/*! @} */

/*! @name CMN_REG03C -  */
/*! @{ */

#define PCIE_PHY_CMN_REG03C_PLL_SDM_DENOMINATOR_G1_MASK (0xFFU)
#define PCIE_PHY_CMN_REG03C_PLL_SDM_DENOMINATOR_G1_SHIFT (0U)
/*! PLL_SDM_DENOMINATOR_G1 - [GEN1] Denominator of SDM (Max. 255) */
#define PCIE_PHY_CMN_REG03C_PLL_SDM_DENOMINATOR_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG03C_PLL_SDM_DENOMINATOR_G1_SHIFT)) & PCIE_PHY_CMN_REG03C_PLL_SDM_DENOMINATOR_G1_MASK)
/*! @} */

/*! @name CMN_REG03D -  */
/*! @{ */

#define PCIE_PHY_CMN_REG03D_PLL_SDM_DENOMINATOR_G2_MASK (0xFFU)
#define PCIE_PHY_CMN_REG03D_PLL_SDM_DENOMINATOR_G2_SHIFT (0U)
/*! PLL_SDM_DENOMINATOR_G2 - [GEN2] */
#define PCIE_PHY_CMN_REG03D_PLL_SDM_DENOMINATOR_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG03D_PLL_SDM_DENOMINATOR_G2_SHIFT)) & PCIE_PHY_CMN_REG03D_PLL_SDM_DENOMINATOR_G2_MASK)
/*! @} */

/*! @name CMN_REG03E -  */
/*! @{ */

#define PCIE_PHY_CMN_REG03E_PLL_SDM_DENOMINATOR_G3_MASK (0xFFU)
#define PCIE_PHY_CMN_REG03E_PLL_SDM_DENOMINATOR_G3_SHIFT (0U)
/*! PLL_SDM_DENOMINATOR_G3 - [GEN3] */
#define PCIE_PHY_CMN_REG03E_PLL_SDM_DENOMINATOR_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG03E_PLL_SDM_DENOMINATOR_G3_SHIFT)) & PCIE_PHY_CMN_REG03E_PLL_SDM_DENOMINATOR_G3_MASK)
/*! @} */

/*! @name CMN_REG03F -  */
/*! @{ */

#define PCIE_PHY_CMN_REG03F_PLL_SDM_DENOMINATOR_G4_MASK (0xFFU)
#define PCIE_PHY_CMN_REG03F_PLL_SDM_DENOMINATOR_G4_SHIFT (0U)
/*! PLL_SDM_DENOMINATOR_G4 - [GEN4] */
#define PCIE_PHY_CMN_REG03F_PLL_SDM_DENOMINATOR_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG03F_PLL_SDM_DENOMINATOR_G4_SHIFT)) & PCIE_PHY_CMN_REG03F_PLL_SDM_DENOMINATOR_G4_MASK)
/*! @} */

/*! @name CMN_REG040 -  */
/*! @{ */

#define PCIE_PHY_CMN_REG040_PLL_SDM_NUMERATOR_SIGN_G4_MASK (0x1U)
#define PCIE_PHY_CMN_REG040_PLL_SDM_NUMERATOR_SIGN_G4_SHIFT (0U)
/*! PLL_SDM_NUMERATOR_SIGN_G4 - [GEN4] */
#define PCIE_PHY_CMN_REG040_PLL_SDM_NUMERATOR_SIGN_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG040_PLL_SDM_NUMERATOR_SIGN_G4_SHIFT)) & PCIE_PHY_CMN_REG040_PLL_SDM_NUMERATOR_SIGN_G4_MASK)

#define PCIE_PHY_CMN_REG040_PLL_SDM_NUMERATOR_SIGN_G3_MASK (0x2U)
#define PCIE_PHY_CMN_REG040_PLL_SDM_NUMERATOR_SIGN_G3_SHIFT (1U)
/*! PLL_SDM_NUMERATOR_SIGN_G3 - [GEN3] */
#define PCIE_PHY_CMN_REG040_PLL_SDM_NUMERATOR_SIGN_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG040_PLL_SDM_NUMERATOR_SIGN_G3_SHIFT)) & PCIE_PHY_CMN_REG040_PLL_SDM_NUMERATOR_SIGN_G3_MASK)

#define PCIE_PHY_CMN_REG040_PLL_SDM_NUMERATOR_SIGN_G2_MASK (0x4U)
#define PCIE_PHY_CMN_REG040_PLL_SDM_NUMERATOR_SIGN_G2_SHIFT (2U)
/*! PLL_SDM_NUMERATOR_SIGN_G2 - [GEN2] */
#define PCIE_PHY_CMN_REG040_PLL_SDM_NUMERATOR_SIGN_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG040_PLL_SDM_NUMERATOR_SIGN_G2_SHIFT)) & PCIE_PHY_CMN_REG040_PLL_SDM_NUMERATOR_SIGN_G2_MASK)

#define PCIE_PHY_CMN_REG040_PLL_SDM_NUMERATOR_SIGN_G1_MASK (0x8U)
#define PCIE_PHY_CMN_REG040_PLL_SDM_NUMERATOR_SIGN_G1_SHIFT (3U)
/*! PLL_SDM_NUMERATOR_SIGN_G1 - [GEN1] Sign of SDM numerator */
#define PCIE_PHY_CMN_REG040_PLL_SDM_NUMERATOR_SIGN_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG040_PLL_SDM_NUMERATOR_SIGN_G1_SHIFT)) & PCIE_PHY_CMN_REG040_PLL_SDM_NUMERATOR_SIGN_G1_MASK)
/*! @} */

/*! @name CMN_REG041 -  */
/*! @{ */

#define PCIE_PHY_CMN_REG041_PLL_SDM_NUMERATOR_G1_MASK (0xFFU)
#define PCIE_PHY_CMN_REG041_PLL_SDM_NUMERATOR_G1_SHIFT (0U)
/*! PLL_SDM_NUMERATOR_G1 - [GEN1] Numerator of SDM with i_pll_sdm_k_sign (-255~255) */
#define PCIE_PHY_CMN_REG041_PLL_SDM_NUMERATOR_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG041_PLL_SDM_NUMERATOR_G1_SHIFT)) & PCIE_PHY_CMN_REG041_PLL_SDM_NUMERATOR_G1_MASK)
/*! @} */

/*! @name CMN_REG042 -  */
/*! @{ */

#define PCIE_PHY_CMN_REG042_PLL_SDM_NUMERATOR_G2_MASK (0xFFU)
#define PCIE_PHY_CMN_REG042_PLL_SDM_NUMERATOR_G2_SHIFT (0U)
/*! PLL_SDM_NUMERATOR_G2 - [GEN2] */
#define PCIE_PHY_CMN_REG042_PLL_SDM_NUMERATOR_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG042_PLL_SDM_NUMERATOR_G2_SHIFT)) & PCIE_PHY_CMN_REG042_PLL_SDM_NUMERATOR_G2_MASK)
/*! @} */

/*! @name CMN_REG043 -  */
/*! @{ */

#define PCIE_PHY_CMN_REG043_PLL_SDM_NUMERATOR_G3_MASK (0xFFU)
#define PCIE_PHY_CMN_REG043_PLL_SDM_NUMERATOR_G3_SHIFT (0U)
/*! PLL_SDM_NUMERATOR_G3 - [GEN3] */
#define PCIE_PHY_CMN_REG043_PLL_SDM_NUMERATOR_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG043_PLL_SDM_NUMERATOR_G3_SHIFT)) & PCIE_PHY_CMN_REG043_PLL_SDM_NUMERATOR_G3_MASK)
/*! @} */

/*! @name CMN_REG044 -  */
/*! @{ */

#define PCIE_PHY_CMN_REG044_PLL_SDM_NUMERATOR_G4_MASK (0xFFU)
#define PCIE_PHY_CMN_REG044_PLL_SDM_NUMERATOR_G4_SHIFT (0U)
/*! PLL_SDM_NUMERATOR_G4 - [GEN4] */
#define PCIE_PHY_CMN_REG044_PLL_SDM_NUMERATOR_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG044_PLL_SDM_NUMERATOR_G4_SHIFT)) & PCIE_PHY_CMN_REG044_PLL_SDM_NUMERATOR_G4_MASK)
/*! @} */

/*! @name CMN_REG045 -  */
/*! @{ */

#define PCIE_PHY_CMN_REG045_PLL_SDM_PH_NUM_SEL_G4_MASK (0x1U)
#define PCIE_PHY_CMN_REG045_PLL_SDM_PH_NUM_SEL_G4_SHIFT (0U)
/*! PLL_SDM_PH_NUM_SEL_G4 - [GEN4] */
#define PCIE_PHY_CMN_REG045_PLL_SDM_PH_NUM_SEL_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG045_PLL_SDM_PH_NUM_SEL_G4_SHIFT)) & PCIE_PHY_CMN_REG045_PLL_SDM_PH_NUM_SEL_G4_MASK)

#define PCIE_PHY_CMN_REG045_PLL_SDM_PH_NUM_SEL_G3_MASK (0x2U)
#define PCIE_PHY_CMN_REG045_PLL_SDM_PH_NUM_SEL_G3_SHIFT (1U)
/*! PLL_SDM_PH_NUM_SEL_G3 - [GEN3] */
#define PCIE_PHY_CMN_REG045_PLL_SDM_PH_NUM_SEL_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG045_PLL_SDM_PH_NUM_SEL_G3_SHIFT)) & PCIE_PHY_CMN_REG045_PLL_SDM_PH_NUM_SEL_G3_MASK)

#define PCIE_PHY_CMN_REG045_PLL_SDM_PH_NUM_SEL_G2_MASK (0x4U)
#define PCIE_PHY_CMN_REG045_PLL_SDM_PH_NUM_SEL_G2_SHIFT (2U)
/*! PLL_SDM_PH_NUM_SEL_G2 - [GEN2] */
#define PCIE_PHY_CMN_REG045_PLL_SDM_PH_NUM_SEL_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG045_PLL_SDM_PH_NUM_SEL_G2_SHIFT)) & PCIE_PHY_CMN_REG045_PLL_SDM_PH_NUM_SEL_G2_MASK)

#define PCIE_PHY_CMN_REG045_PLL_SDM_PH_NUM_SEL_G1_MASK (0x8U)
#define PCIE_PHY_CMN_REG045_PLL_SDM_PH_NUM_SEL_G1_SHIFT (3U)
/*! PLL_SDM_PH_NUM_SEL_G1 - [GEN1] PLL PI input clock phase number */
#define PCIE_PHY_CMN_REG045_PLL_SDM_PH_NUM_SEL_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG045_PLL_SDM_PH_NUM_SEL_G1_SHIFT)) & PCIE_PHY_CMN_REG045_PLL_SDM_PH_NUM_SEL_G1_MASK)
/*! @} */

/*! @name CMN_REG046 -  */
/*! @{ */

#define PCIE_PHY_CMN_REG046_PLL_SDM_PI_STEP_G4_MASK (0x3U)
#define PCIE_PHY_CMN_REG046_PLL_SDM_PI_STEP_G4_SHIFT (0U)
/*! PLL_SDM_PI_STEP_G4 - [GEN4] */
#define PCIE_PHY_CMN_REG046_PLL_SDM_PI_STEP_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG046_PLL_SDM_PI_STEP_G4_SHIFT)) & PCIE_PHY_CMN_REG046_PLL_SDM_PI_STEP_G4_MASK)

#define PCIE_PHY_CMN_REG046_PLL_SDM_PI_STEP_G3_MASK (0xCU)
#define PCIE_PHY_CMN_REG046_PLL_SDM_PI_STEP_G3_SHIFT (2U)
/*! PLL_SDM_PI_STEP_G3 - [GEN3] */
#define PCIE_PHY_CMN_REG046_PLL_SDM_PI_STEP_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG046_PLL_SDM_PI_STEP_G3_SHIFT)) & PCIE_PHY_CMN_REG046_PLL_SDM_PI_STEP_G3_MASK)

#define PCIE_PHY_CMN_REG046_PLL_SDM_PI_STEP_G2_MASK (0x30U)
#define PCIE_PHY_CMN_REG046_PLL_SDM_PI_STEP_G2_SHIFT (4U)
/*! PLL_SDM_PI_STEP_G2 - [GEN2] */
#define PCIE_PHY_CMN_REG046_PLL_SDM_PI_STEP_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG046_PLL_SDM_PI_STEP_G2_SHIFT)) & PCIE_PHY_CMN_REG046_PLL_SDM_PI_STEP_G2_MASK)

#define PCIE_PHY_CMN_REG046_PLL_SDM_PI_STEP_G1_MASK (0xC0U)
#define PCIE_PHY_CMN_REG046_PLL_SDM_PI_STEP_G1_SHIFT (6U)
/*! PLL_SDM_PI_STEP_G1 - [GEN1] PLL phase interpolstor step */
#define PCIE_PHY_CMN_REG046_PLL_SDM_PI_STEP_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG046_PLL_SDM_PI_STEP_G1_SHIFT)) & PCIE_PHY_CMN_REG046_PLL_SDM_PI_STEP_G1_MASK)
/*! @} */

/*! @name CMN_REG047 -  */
/*! @{ */

#define PCIE_PHY_CMN_REG047_PLL_SDC_N_G2_MASK    (0x7U)
#define PCIE_PHY_CMN_REG047_PLL_SDC_N_G2_SHIFT   (0U)
/*! PLL_SDC_N_G2 - [GEN2] */
#define PCIE_PHY_CMN_REG047_PLL_SDC_N_G2(x)      (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG047_PLL_SDC_N_G2_SHIFT)) & PCIE_PHY_CMN_REG047_PLL_SDC_N_G2_MASK)

#define PCIE_PHY_CMN_REG047_PLL_SDC_N_G1_MASK    (0x38U)
#define PCIE_PHY_CMN_REG047_PLL_SDC_N_G1_SHIFT   (3U)
/*! PLL_SDC_N_G1 - [GEN1] PLL SDC divide-ratio selection */
#define PCIE_PHY_CMN_REG047_PLL_SDC_N_G1(x)      (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG047_PLL_SDC_N_G1_SHIFT)) & PCIE_PHY_CMN_REG047_PLL_SDC_N_G1_MASK)
/*! @} */

/*! @name CMN_REG048 -  */
/*! @{ */

#define PCIE_PHY_CMN_REG048_PLL_SDC_N_G4_MASK    (0x7U)
#define PCIE_PHY_CMN_REG048_PLL_SDC_N_G4_SHIFT   (0U)
/*! PLL_SDC_N_G4 - [GEN4] */
#define PCIE_PHY_CMN_REG048_PLL_SDC_N_G4(x)      (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG048_PLL_SDC_N_G4_SHIFT)) & PCIE_PHY_CMN_REG048_PLL_SDC_N_G4_MASK)

#define PCIE_PHY_CMN_REG048_PLL_SDC_N_G3_MASK    (0x38U)
#define PCIE_PHY_CMN_REG048_PLL_SDC_N_G3_SHIFT   (3U)
/*! PLL_SDC_N_G3 - [GEN3] */
#define PCIE_PHY_CMN_REG048_PLL_SDC_N_G3(x)      (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG048_PLL_SDC_N_G3_SHIFT)) & PCIE_PHY_CMN_REG048_PLL_SDC_N_G3_MASK)
/*! @} */

/*! @name CMN_REG049 -  */
/*! @{ */

#define PCIE_PHY_CMN_REG049_PLL_SDC_N2_G4_MASK   (0x1U)
#define PCIE_PHY_CMN_REG049_PLL_SDC_N2_G4_SHIFT  (0U)
/*! PLL_SDC_N2_G4 - [GEN4] */
#define PCIE_PHY_CMN_REG049_PLL_SDC_N2_G4(x)     (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG049_PLL_SDC_N2_G4_SHIFT)) & PCIE_PHY_CMN_REG049_PLL_SDC_N2_G4_MASK)

#define PCIE_PHY_CMN_REG049_PLL_SDC_N2_G3_MASK   (0x2U)
#define PCIE_PHY_CMN_REG049_PLL_SDC_N2_G3_SHIFT  (1U)
/*! PLL_SDC_N2_G3 - [GEN3] */
#define PCIE_PHY_CMN_REG049_PLL_SDC_N2_G3(x)     (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG049_PLL_SDC_N2_G3_SHIFT)) & PCIE_PHY_CMN_REG049_PLL_SDC_N2_G3_MASK)

#define PCIE_PHY_CMN_REG049_PLL_SDC_N2_G2_MASK   (0x4U)
#define PCIE_PHY_CMN_REG049_PLL_SDC_N2_G2_SHIFT  (2U)
/*! PLL_SDC_N2_G2 - [GEN2] */
#define PCIE_PHY_CMN_REG049_PLL_SDC_N2_G2(x)     (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG049_PLL_SDC_N2_G2_SHIFT)) & PCIE_PHY_CMN_REG049_PLL_SDC_N2_G2_MASK)

#define PCIE_PHY_CMN_REG049_PLL_SDC_N2_G1_MASK   (0x8U)
#define PCIE_PHY_CMN_REG049_PLL_SDC_N2_G1_SHIFT  (3U)
/*! PLL_SDC_N2_G1 - [GEN1] PLL SDC divide-ratio selection */
#define PCIE_PHY_CMN_REG049_PLL_SDC_N2_G1(x)     (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG049_PLL_SDC_N2_G1_SHIFT)) & PCIE_PHY_CMN_REG049_PLL_SDC_N2_G1_MASK)
/*! @} */

/*! @name CMN_REG04A -  */
/*! @{ */

#define PCIE_PHY_CMN_REG04A_PLL_SDC_NUMERATOR_G1_MASK (0x3FU)
#define PCIE_PHY_CMN_REG04A_PLL_SDC_NUMERATOR_G1_SHIFT (0U)
/*! PLL_SDC_NUMERATOR_G1 - [GEN1] Numerator of SDC (Max 65) */
#define PCIE_PHY_CMN_REG04A_PLL_SDC_NUMERATOR_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG04A_PLL_SDC_NUMERATOR_G1_SHIFT)) & PCIE_PHY_CMN_REG04A_PLL_SDC_NUMERATOR_G1_MASK)
/*! @} */

/*! @name CMN_REG04B -  */
/*! @{ */

#define PCIE_PHY_CMN_REG04B_PLL_SDC_NUMERATOR_G2_MASK (0x3FU)
#define PCIE_PHY_CMN_REG04B_PLL_SDC_NUMERATOR_G2_SHIFT (0U)
/*! PLL_SDC_NUMERATOR_G2 - [GEN2] */
#define PCIE_PHY_CMN_REG04B_PLL_SDC_NUMERATOR_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG04B_PLL_SDC_NUMERATOR_G2_SHIFT)) & PCIE_PHY_CMN_REG04B_PLL_SDC_NUMERATOR_G2_MASK)
/*! @} */

/*! @name CMN_REG04C -  */
/*! @{ */

#define PCIE_PHY_CMN_REG04C_PLL_SDC_NUMERATOR_G3_MASK (0x3FU)
#define PCIE_PHY_CMN_REG04C_PLL_SDC_NUMERATOR_G3_SHIFT (0U)
/*! PLL_SDC_NUMERATOR_G3 - [GEN3] */
#define PCIE_PHY_CMN_REG04C_PLL_SDC_NUMERATOR_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG04C_PLL_SDC_NUMERATOR_G3_SHIFT)) & PCIE_PHY_CMN_REG04C_PLL_SDC_NUMERATOR_G3_MASK)
/*! @} */

/*! @name CMN_REG04D -  */
/*! @{ */

#define PCIE_PHY_CMN_REG04D_PLL_SDC_NUMERATOR_G4_MASK (0x3FU)
#define PCIE_PHY_CMN_REG04D_PLL_SDC_NUMERATOR_G4_SHIFT (0U)
/*! PLL_SDC_NUMERATOR_G4 - [GEN4] */
#define PCIE_PHY_CMN_REG04D_PLL_SDC_NUMERATOR_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG04D_PLL_SDC_NUMERATOR_G4_SHIFT)) & PCIE_PHY_CMN_REG04D_PLL_SDC_NUMERATOR_G4_MASK)
/*! @} */

/*! @name CMN_REG04E -  */
/*! @{ */

#define PCIE_PHY_CMN_REG04E_PLL_SDC_DENOMINATOR_G1_MASK (0x3FU)
#define PCIE_PHY_CMN_REG04E_PLL_SDC_DENOMINATOR_G1_SHIFT (0U)
/*! PLL_SDC_DENOMINATOR_G1 - [GEN1] Denominator of SDC (Max 65) */
#define PCIE_PHY_CMN_REG04E_PLL_SDC_DENOMINATOR_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG04E_PLL_SDC_DENOMINATOR_G1_SHIFT)) & PCIE_PHY_CMN_REG04E_PLL_SDC_DENOMINATOR_G1_MASK)
/*! @} */

/*! @name CMN_REG04F -  */
/*! @{ */

#define PCIE_PHY_CMN_REG04F_PLL_SDC_DENOMINATOR_G2_MASK (0x3FU)
#define PCIE_PHY_CMN_REG04F_PLL_SDC_DENOMINATOR_G2_SHIFT (0U)
/*! PLL_SDC_DENOMINATOR_G2 - [GEN2] */
#define PCIE_PHY_CMN_REG04F_PLL_SDC_DENOMINATOR_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG04F_PLL_SDC_DENOMINATOR_G2_SHIFT)) & PCIE_PHY_CMN_REG04F_PLL_SDC_DENOMINATOR_G2_MASK)
/*! @} */

/*! @name CMN_REG050 -  */
/*! @{ */

#define PCIE_PHY_CMN_REG050_PLL_SDC_DENOMINATOR_G3_MASK (0x3FU)
#define PCIE_PHY_CMN_REG050_PLL_SDC_DENOMINATOR_G3_SHIFT (0U)
/*! PLL_SDC_DENOMINATOR_G3 - [GEN3] */
#define PCIE_PHY_CMN_REG050_PLL_SDC_DENOMINATOR_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG050_PLL_SDC_DENOMINATOR_G3_SHIFT)) & PCIE_PHY_CMN_REG050_PLL_SDC_DENOMINATOR_G3_MASK)
/*! @} */

/*! @name CMN_REG051 -  */
/*! @{ */

#define PCIE_PHY_CMN_REG051_ANA_PLL_SDC_MC_VALUE_SEL_MASK (0x1U)
#define PCIE_PHY_CMN_REG051_ANA_PLL_SDC_MC_VALUE_SEL_SHIFT (0U)
/*! ANA_PLL_SDC_MC_VALUE_SEL - PLL SDC value force */
#define PCIE_PHY_CMN_REG051_ANA_PLL_SDC_MC_VALUE_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG051_ANA_PLL_SDC_MC_VALUE_SEL_SHIFT)) & PCIE_PHY_CMN_REG051_ANA_PLL_SDC_MC_VALUE_SEL_MASK)

#define PCIE_PHY_CMN_REG051_PLL_SDC_DENOMINATOR_G4_MASK (0x7EU)
#define PCIE_PHY_CMN_REG051_PLL_SDC_DENOMINATOR_G4_SHIFT (1U)
/*! PLL_SDC_DENOMINATOR_G4 - [GEN4] */
#define PCIE_PHY_CMN_REG051_PLL_SDC_DENOMINATOR_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG051_PLL_SDC_DENOMINATOR_G4_SHIFT)) & PCIE_PHY_CMN_REG051_PLL_SDC_DENOMINATOR_G4_MASK)
/*! @} */

/*! @name CMN_REG052 -  */
/*! @{ */

#define PCIE_PHY_CMN_REG052_PLL_SSC_EN_MASK      (0x1U)
#define PCIE_PHY_CMN_REG052_PLL_SSC_EN_SHIFT     (0U)
/*! PLL_SSC_EN - PLL SSC enable */
#define PCIE_PHY_CMN_REG052_PLL_SSC_EN(x)        (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG052_PLL_SSC_EN_SHIFT)) & PCIE_PHY_CMN_REG052_PLL_SSC_EN_MASK)

#define PCIE_PHY_CMN_REG052_OVRD_PLL_SSC_EN_MASK (0x2U)
#define PCIE_PHY_CMN_REG052_OVRD_PLL_SSC_EN_SHIFT (1U)
/*! OVRD_PLL_SSC_EN - Override enable for pll_ssc_en */
#define PCIE_PHY_CMN_REG052_OVRD_PLL_SSC_EN(x)   (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG052_OVRD_PLL_SSC_EN_SHIFT)) & PCIE_PHY_CMN_REG052_OVRD_PLL_SSC_EN_MASK)
/*! @} */

/*! @name CMN_REG053 -  */
/*! @{ */

#define PCIE_PHY_CMN_REG053_PLL_SSC_FM_DEVIATION_G1_MASK (0x3FU)
#define PCIE_PHY_CMN_REG053_PLL_SSC_FM_DEVIATION_G1_SHIFT (0U)
/*! PLL_SSC_FM_DEVIATION_G1 - [GEN1] PLL SSC modulation deviation */
#define PCIE_PHY_CMN_REG053_PLL_SSC_FM_DEVIATION_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG053_PLL_SSC_FM_DEVIATION_G1_SHIFT)) & PCIE_PHY_CMN_REG053_PLL_SSC_FM_DEVIATION_G1_MASK)
/*! @} */

/*! @name CMN_REG054 -  */
/*! @{ */

#define PCIE_PHY_CMN_REG054_PLL_SSC_FM_DEVIATION_G2_MASK (0x3FU)
#define PCIE_PHY_CMN_REG054_PLL_SSC_FM_DEVIATION_G2_SHIFT (0U)
/*! PLL_SSC_FM_DEVIATION_G2 - [GEN2] */
#define PCIE_PHY_CMN_REG054_PLL_SSC_FM_DEVIATION_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG054_PLL_SSC_FM_DEVIATION_G2_SHIFT)) & PCIE_PHY_CMN_REG054_PLL_SSC_FM_DEVIATION_G2_MASK)
/*! @} */

/*! @name CMN_REG055 -  */
/*! @{ */

#define PCIE_PHY_CMN_REG055_PLL_SSC_FM_DEVIATION_G3_MASK (0x3FU)
#define PCIE_PHY_CMN_REG055_PLL_SSC_FM_DEVIATION_G3_SHIFT (0U)
/*! PLL_SSC_FM_DEVIATION_G3 - [GEN3] */
#define PCIE_PHY_CMN_REG055_PLL_SSC_FM_DEVIATION_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG055_PLL_SSC_FM_DEVIATION_G3_SHIFT)) & PCIE_PHY_CMN_REG055_PLL_SSC_FM_DEVIATION_G3_MASK)
/*! @} */

/*! @name CMN_REG056 -  */
/*! @{ */

#define PCIE_PHY_CMN_REG056_PLL_SSC_FM_DEVIATION_G4_MASK (0x3FU)
#define PCIE_PHY_CMN_REG056_PLL_SSC_FM_DEVIATION_G4_SHIFT (0U)
/*! PLL_SSC_FM_DEVIATION_G4 - [GEN4] */
#define PCIE_PHY_CMN_REG056_PLL_SSC_FM_DEVIATION_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG056_PLL_SSC_FM_DEVIATION_G4_SHIFT)) & PCIE_PHY_CMN_REG056_PLL_SSC_FM_DEVIATION_G4_MASK)
/*! @} */

/*! @name CMN_REG057 -  */
/*! @{ */

#define PCIE_PHY_CMN_REG057_PLL_SSC_FM_FREQ_G1_MASK (0x1FU)
#define PCIE_PHY_CMN_REG057_PLL_SSC_FM_FREQ_G1_SHIFT (0U)
/*! PLL_SSC_FM_FREQ_G1 - [GEN1] PLL SSC modulation frequency */
#define PCIE_PHY_CMN_REG057_PLL_SSC_FM_FREQ_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG057_PLL_SSC_FM_FREQ_G1_SHIFT)) & PCIE_PHY_CMN_REG057_PLL_SSC_FM_FREQ_G1_MASK)
/*! @} */

/*! @name CMN_REG058 -  */
/*! @{ */

#define PCIE_PHY_CMN_REG058_PLL_SSC_FM_FREQ_G2_MASK (0x1FU)
#define PCIE_PHY_CMN_REG058_PLL_SSC_FM_FREQ_G2_SHIFT (0U)
/*! PLL_SSC_FM_FREQ_G2 - [GEN2] */
#define PCIE_PHY_CMN_REG058_PLL_SSC_FM_FREQ_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG058_PLL_SSC_FM_FREQ_G2_SHIFT)) & PCIE_PHY_CMN_REG058_PLL_SSC_FM_FREQ_G2_MASK)
/*! @} */

/*! @name CMN_REG059 -  */
/*! @{ */

#define PCIE_PHY_CMN_REG059_PLL_SSC_FM_FREQ_G3_MASK (0x1FU)
#define PCIE_PHY_CMN_REG059_PLL_SSC_FM_FREQ_G3_SHIFT (0U)
/*! PLL_SSC_FM_FREQ_G3 - [GEN3] */
#define PCIE_PHY_CMN_REG059_PLL_SSC_FM_FREQ_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG059_PLL_SSC_FM_FREQ_G3_SHIFT)) & PCIE_PHY_CMN_REG059_PLL_SSC_FM_FREQ_G3_MASK)
/*! @} */

/*! @name CMN_REG05A -  */
/*! @{ */

#define PCIE_PHY_CMN_REG05A_PLL_SSC_FM_FREQ_G4_MASK (0x1FU)
#define PCIE_PHY_CMN_REG05A_PLL_SSC_FM_FREQ_G4_SHIFT (0U)
/*! PLL_SSC_FM_FREQ_G4 - [GEN4] */
#define PCIE_PHY_CMN_REG05A_PLL_SSC_FM_FREQ_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG05A_PLL_SSC_FM_FREQ_G4_SHIFT)) & PCIE_PHY_CMN_REG05A_PLL_SSC_FM_FREQ_G4_MASK)
/*! @} */

/*! @name CMN_REG05B -  */
/*! @{ */

#define PCIE_PHY_CMN_REG05B_PLL_SSC_PROFILE_OPT_G4_MASK (0x3U)
#define PCIE_PHY_CMN_REG05B_PLL_SSC_PROFILE_OPT_G4_SHIFT (0U)
/*! PLL_SSC_PROFILE_OPT_G4 - [GEN4] */
#define PCIE_PHY_CMN_REG05B_PLL_SSC_PROFILE_OPT_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG05B_PLL_SSC_PROFILE_OPT_G4_SHIFT)) & PCIE_PHY_CMN_REG05B_PLL_SSC_PROFILE_OPT_G4_MASK)

#define PCIE_PHY_CMN_REG05B_PLL_SSC_PROFILE_OPT_G3_MASK (0xCU)
#define PCIE_PHY_CMN_REG05B_PLL_SSC_PROFILE_OPT_G3_SHIFT (2U)
/*! PLL_SSC_PROFILE_OPT_G3 - [GEN3] */
#define PCIE_PHY_CMN_REG05B_PLL_SSC_PROFILE_OPT_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG05B_PLL_SSC_PROFILE_OPT_G3_SHIFT)) & PCIE_PHY_CMN_REG05B_PLL_SSC_PROFILE_OPT_G3_MASK)

#define PCIE_PHY_CMN_REG05B_PLL_SSC_PROFILE_OPT_G2_MASK (0x30U)
#define PCIE_PHY_CMN_REG05B_PLL_SSC_PROFILE_OPT_G2_SHIFT (4U)
/*! PLL_SSC_PROFILE_OPT_G2 - [GEN2] */
#define PCIE_PHY_CMN_REG05B_PLL_SSC_PROFILE_OPT_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG05B_PLL_SSC_PROFILE_OPT_G2_SHIFT)) & PCIE_PHY_CMN_REG05B_PLL_SSC_PROFILE_OPT_G2_MASK)

#define PCIE_PHY_CMN_REG05B_PLL_SSC_PROFILE_OPT_G1_MASK (0xC0U)
#define PCIE_PHY_CMN_REG05B_PLL_SSC_PROFILE_OPT_G1_SHIFT (6U)
/*! PLL_SSC_PROFILE_OPT_G1 - [GEN1] PLL SSC modulation profile shape control */
#define PCIE_PHY_CMN_REG05B_PLL_SSC_PROFILE_OPT_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG05B_PLL_SSC_PROFILE_OPT_G1_SHIFT)) & PCIE_PHY_CMN_REG05B_PLL_SSC_PROFILE_OPT_G1_MASK)
/*! @} */

/*! @name CMN_REG05C -  */
/*! @{ */

#define PCIE_PHY_CMN_REG05C_PLL_CD_TX_SER_RSTN_MASK (0x1U)
#define PCIE_PHY_CMN_REG05C_PLL_CD_TX_SER_RSTN_SHIFT (0U)
/*! PLL_CD_TX_SER_RSTN - TX_SER resetn */
#define PCIE_PHY_CMN_REG05C_PLL_CD_TX_SER_RSTN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG05C_PLL_CD_TX_SER_RSTN_SHIFT)) & PCIE_PHY_CMN_REG05C_PLL_CD_TX_SER_RSTN_MASK)

#define PCIE_PHY_CMN_REG05C_OVRD_PLL_CD_TX_SER_RSTN_MASK (0x2U)
#define PCIE_PHY_CMN_REG05C_OVRD_PLL_CD_TX_SER_RSTN_SHIFT (1U)
/*! OVRD_PLL_CD_TX_SER_RSTN - Override enable for pll_cd_tx_ser_rstn */
#define PCIE_PHY_CMN_REG05C_OVRD_PLL_CD_TX_SER_RSTN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG05C_OVRD_PLL_CD_TX_SER_RSTN_SHIFT)) & PCIE_PHY_CMN_REG05C_OVRD_PLL_CD_TX_SER_RSTN_MASK)

#define PCIE_PHY_CMN_REG05C_PLL_CD_CLK_EN_MASK   (0x4U)
#define PCIE_PHY_CMN_REG05C_PLL_CD_CLK_EN_SHIFT  (2U)
/*! PLL_CD_CLK_EN - CD enable */
#define PCIE_PHY_CMN_REG05C_PLL_CD_CLK_EN(x)     (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG05C_PLL_CD_CLK_EN_SHIFT)) & PCIE_PHY_CMN_REG05C_PLL_CD_CLK_EN_MASK)

#define PCIE_PHY_CMN_REG05C_OVRD_PLL_CD_CLK_EN_MASK (0x8U)
#define PCIE_PHY_CMN_REG05C_OVRD_PLL_CD_CLK_EN_SHIFT (3U)
/*! OVRD_PLL_CD_CLK_EN - Override enable for pll_cd_clk_en */
#define PCIE_PHY_CMN_REG05C_OVRD_PLL_CD_CLK_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG05C_OVRD_PLL_CD_CLK_EN_SHIFT)) & PCIE_PHY_CMN_REG05C_OVRD_PLL_CD_CLK_EN_MASK)

#define PCIE_PHY_CMN_REG05C_ANA_PLL_SSC_CLK_DIV_SEL_MASK (0xF0U)
#define PCIE_PHY_CMN_REG05C_ANA_PLL_SSC_CLK_DIV_SEL_SHIFT (4U)
/*! ANA_PLL_SSC_CLK_DIV_SEL - PLL SSC clock divide ratio */
#define PCIE_PHY_CMN_REG05C_ANA_PLL_SSC_CLK_DIV_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG05C_ANA_PLL_SSC_CLK_DIV_SEL_SHIFT)) & PCIE_PHY_CMN_REG05C_ANA_PLL_SSC_CLK_DIV_SEL_MASK)
/*! @} */

/*! @name CMN_REG05D -  */
/*! @{ */

#define PCIE_PHY_CMN_REG05D_ANA_PLL_CD_HSCLK_EAST_EN_MASK (0x1U)
#define PCIE_PHY_CMN_REG05D_ANA_PLL_CD_HSCLK_EAST_EN_SHIFT (0U)
/*! ANA_PLL_CD_HSCLK_EAST_EN - CD driver pmos strength control */
#define PCIE_PHY_CMN_REG05D_ANA_PLL_CD_HSCLK_EAST_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG05D_ANA_PLL_CD_HSCLK_EAST_EN_SHIFT)) & PCIE_PHY_CMN_REG05D_ANA_PLL_CD_HSCLK_EAST_EN_MASK)

#define PCIE_PHY_CMN_REG05D_ANA_PLL_CD_HSCLK_WEST_EN_MASK (0x2U)
#define PCIE_PHY_CMN_REG05D_ANA_PLL_CD_HSCLK_WEST_EN_SHIFT (1U)
/*! ANA_PLL_CD_HSCLK_WEST_EN - CD driver nmos strength control */
#define PCIE_PHY_CMN_REG05D_ANA_PLL_CD_HSCLK_WEST_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG05D_ANA_PLL_CD_HSCLK_WEST_EN_SHIFT)) & PCIE_PHY_CMN_REG05D_ANA_PLL_CD_HSCLK_WEST_EN_MASK)

#define PCIE_PHY_CMN_REG05D_ANA_PLL_CD_HSCLK_INV_MASK (0x4U)
#define PCIE_PHY_CMN_REG05D_ANA_PLL_CD_HSCLK_INV_SHIFT (2U)
/*! ANA_PLL_CD_HSCLK_INV - CD output clock polarity inversion */
#define PCIE_PHY_CMN_REG05D_ANA_PLL_CD_HSCLK_INV(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG05D_ANA_PLL_CD_HSCLK_INV_SHIFT)) & PCIE_PHY_CMN_REG05D_ANA_PLL_CD_HSCLK_INV_MASK)

#define PCIE_PHY_CMN_REG05D_PLL_CD_TX_SER_RATE_SEL_G4_MASK (0x8U)
#define PCIE_PHY_CMN_REG05D_PLL_CD_TX_SER_RATE_SEL_G4_SHIFT (3U)
/*! PLL_CD_TX_SER_RATE_SEL_G4 - [GEN4] */
#define PCIE_PHY_CMN_REG05D_PLL_CD_TX_SER_RATE_SEL_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG05D_PLL_CD_TX_SER_RATE_SEL_G4_SHIFT)) & PCIE_PHY_CMN_REG05D_PLL_CD_TX_SER_RATE_SEL_G4_MASK)

#define PCIE_PHY_CMN_REG05D_PLL_CD_TX_SER_RATE_SEL_G3_MASK (0x10U)
#define PCIE_PHY_CMN_REG05D_PLL_CD_TX_SER_RATE_SEL_G3_SHIFT (4U)
/*! PLL_CD_TX_SER_RATE_SEL_G3 - [GEN3] */
#define PCIE_PHY_CMN_REG05D_PLL_CD_TX_SER_RATE_SEL_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG05D_PLL_CD_TX_SER_RATE_SEL_G3_SHIFT)) & PCIE_PHY_CMN_REG05D_PLL_CD_TX_SER_RATE_SEL_G3_MASK)

#define PCIE_PHY_CMN_REG05D_PLL_CD_TX_SER_RATE_SEL_G2_MASK (0x20U)
#define PCIE_PHY_CMN_REG05D_PLL_CD_TX_SER_RATE_SEL_G2_SHIFT (5U)
/*! PLL_CD_TX_SER_RATE_SEL_G2 - [GEN2] */
#define PCIE_PHY_CMN_REG05D_PLL_CD_TX_SER_RATE_SEL_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG05D_PLL_CD_TX_SER_RATE_SEL_G2_SHIFT)) & PCIE_PHY_CMN_REG05D_PLL_CD_TX_SER_RATE_SEL_G2_MASK)

#define PCIE_PHY_CMN_REG05D_PLL_CD_TX_SER_RATE_SEL_G1_MASK (0x40U)
#define PCIE_PHY_CMN_REG05D_PLL_CD_TX_SER_RATE_SEL_G1_SHIFT (6U)
/*! PLL_CD_TX_SER_RATE_SEL_G1 - [GEN1] TX serializer data rate selection for Gen4 (Need to be controlled with i_tx_en_40bit) */
#define PCIE_PHY_CMN_REG05D_PLL_CD_TX_SER_RATE_SEL_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG05D_PLL_CD_TX_SER_RATE_SEL_G1_SHIFT)) & PCIE_PHY_CMN_REG05D_PLL_CD_TX_SER_RATE_SEL_G1_MASK)
/*! @} */

/*! @name CMN_REG05E -  */
/*! @{ */

#define PCIE_PHY_CMN_REG05E_ANA_PLL_MISC_CLK_SEL_MASK (0x3U)
#define PCIE_PHY_CMN_REG05E_ANA_PLL_MISC_CLK_SEL_SHIFT (0U)
/*! ANA_PLL_MISC_CLK_SEL - PLL low-frequency clock output source selection */
#define PCIE_PHY_CMN_REG05E_ANA_PLL_MISC_CLK_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG05E_ANA_PLL_MISC_CLK_SEL_SHIFT)) & PCIE_PHY_CMN_REG05E_ANA_PLL_MISC_CLK_SEL_MASK)

#define PCIE_PHY_CMN_REG05E_ANA_PLL_MISC_CLK_SYNC_EN_MASK (0x4U)
#define PCIE_PHY_CMN_REG05E_ANA_PLL_MISC_CLK_SYNC_EN_SHIFT (2U)
/*! ANA_PLL_MISC_CLK_SYNC_EN - PLL miscellaneous clock synchronization enable */
#define PCIE_PHY_CMN_REG05E_ANA_PLL_MISC_CLK_SYNC_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG05E_ANA_PLL_MISC_CLK_SYNC_EN_SHIFT)) & PCIE_PHY_CMN_REG05E_ANA_PLL_MISC_CLK_SYNC_EN_MASK)

#define PCIE_PHY_CMN_REG05E_PLL_BEACON_LFPS_OUT_EN_MASK (0x8U)
#define PCIE_PHY_CMN_REG05E_PLL_BEACON_LFPS_OUT_EN_SHIFT (3U)
/*! PLL_BEACON_LFPS_OUT_EN - TX beacon clock enable */
#define PCIE_PHY_CMN_REG05E_PLL_BEACON_LFPS_OUT_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG05E_PLL_BEACON_LFPS_OUT_EN_SHIFT)) & PCIE_PHY_CMN_REG05E_PLL_BEACON_LFPS_OUT_EN_MASK)

#define PCIE_PHY_CMN_REG05E_OVRD_PLL_BEACON_LFPS_OUT_EN_MASK (0x10U)
#define PCIE_PHY_CMN_REG05E_OVRD_PLL_BEACON_LFPS_OUT_EN_SHIFT (4U)
/*! OVRD_PLL_BEACON_LFPS_OUT_EN - Override enable for pll_beacon_lfps_out_en */
#define PCIE_PHY_CMN_REG05E_OVRD_PLL_BEACON_LFPS_OUT_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG05E_OVRD_PLL_BEACON_LFPS_OUT_EN_SHIFT)) & PCIE_PHY_CMN_REG05E_OVRD_PLL_BEACON_LFPS_OUT_EN_MASK)
/*! @} */

/*! @name CMN_REG05F -  */
/*! @{ */

#define PCIE_PHY_CMN_REG05F_PLL_MISC_CLK_DIV_G2_MASK (0xFU)
#define PCIE_PHY_CMN_REG05F_PLL_MISC_CLK_DIV_G2_SHIFT (0U)
/*! PLL_MISC_CLK_DIV_G2 - [GEN2] */
#define PCIE_PHY_CMN_REG05F_PLL_MISC_CLK_DIV_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG05F_PLL_MISC_CLK_DIV_G2_SHIFT)) & PCIE_PHY_CMN_REG05F_PLL_MISC_CLK_DIV_G2_MASK)

#define PCIE_PHY_CMN_REG05F_PLL_MISC_CLK_DIV_G1_MASK (0xF0U)
#define PCIE_PHY_CMN_REG05F_PLL_MISC_CLK_DIV_G1_SHIFT (4U)
/*! PLL_MISC_CLK_DIV_G1 - [GEN1] PLL miscellaneous clock divider ratio */
#define PCIE_PHY_CMN_REG05F_PLL_MISC_CLK_DIV_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG05F_PLL_MISC_CLK_DIV_G1_SHIFT)) & PCIE_PHY_CMN_REG05F_PLL_MISC_CLK_DIV_G1_MASK)
/*! @} */

/*! @name CMN_REG060 -  */
/*! @{ */

#define PCIE_PHY_CMN_REG060_PLL_MISC_CLK_DIV_G4_MASK (0xFU)
#define PCIE_PHY_CMN_REG060_PLL_MISC_CLK_DIV_G4_SHIFT (0U)
/*! PLL_MISC_CLK_DIV_G4 - [GEN4] */
#define PCIE_PHY_CMN_REG060_PLL_MISC_CLK_DIV_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG060_PLL_MISC_CLK_DIV_G4_SHIFT)) & PCIE_PHY_CMN_REG060_PLL_MISC_CLK_DIV_G4_MASK)

#define PCIE_PHY_CMN_REG060_PLL_MISC_CLK_DIV_G3_MASK (0xF0U)
#define PCIE_PHY_CMN_REG060_PLL_MISC_CLK_DIV_G3_SHIFT (4U)
/*! PLL_MISC_CLK_DIV_G3 - [GEN3] */
#define PCIE_PHY_CMN_REG060_PLL_MISC_CLK_DIV_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG060_PLL_MISC_CLK_DIV_G3_SHIFT)) & PCIE_PHY_CMN_REG060_PLL_MISC_CLK_DIV_G3_MASK)
/*! @} */

/*! @name CMN_REG061 -  */
/*! @{ */

#define PCIE_PHY_CMN_REG061_ANA_PLL_CLK_OUT_TO_EXT_IO_EN_MASK (0x1U)
#define PCIE_PHY_CMN_REG061_ANA_PLL_CLK_OUT_TO_EXT_IO_EN_SHIFT (0U)
/*! ANA_PLL_CLK_OUT_TO_EXT_IO_EN - PLL low-frequency clock output to external I/O enable */
#define PCIE_PHY_CMN_REG061_ANA_PLL_CLK_OUT_TO_EXT_IO_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG061_ANA_PLL_CLK_OUT_TO_EXT_IO_EN_SHIFT)) & PCIE_PHY_CMN_REG061_ANA_PLL_CLK_OUT_TO_EXT_IO_EN_MASK)

#define PCIE_PHY_CMN_REG061_PLL_MISC_OSC_RSTN_MASK (0x2U)
#define PCIE_PHY_CMN_REG061_PLL_MISC_OSC_RSTN_SHIFT (1U)
/*! PLL_MISC_OSC_RSTN - PLL miscellaneous clock oscillator reset */
#define PCIE_PHY_CMN_REG061_PLL_MISC_OSC_RSTN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG061_PLL_MISC_OSC_RSTN_SHIFT)) & PCIE_PHY_CMN_REG061_PLL_MISC_OSC_RSTN_MASK)

#define PCIE_PHY_CMN_REG061_OVRD_PLL_MISC_OSC_RSTN_MASK (0x4U)
#define PCIE_PHY_CMN_REG061_OVRD_PLL_MISC_OSC_RSTN_SHIFT (2U)
/*! OVRD_PLL_MISC_OSC_RSTN - Override enable for pll_misc_osc_rstn */
#define PCIE_PHY_CMN_REG061_OVRD_PLL_MISC_OSC_RSTN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG061_OVRD_PLL_MISC_OSC_RSTN_SHIFT)) & PCIE_PHY_CMN_REG061_OVRD_PLL_MISC_OSC_RSTN_MASK)

#define PCIE_PHY_CMN_REG061_PLL_MISC_OSC_FREQ_SEL_MASK (0x78U)
#define PCIE_PHY_CMN_REG061_PLL_MISC_OSC_FREQ_SEL_SHIFT (3U)
/*! PLL_MISC_OSC_FREQ_SEL - PLL miscellaneous clock frequency selection */
#define PCIE_PHY_CMN_REG061_PLL_MISC_OSC_FREQ_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG061_PLL_MISC_OSC_FREQ_SEL_SHIFT)) & PCIE_PHY_CMN_REG061_PLL_MISC_OSC_FREQ_SEL_MASK)

#define PCIE_PHY_CMN_REG061_OVRD_PLL_MISC_OSC_FREQ_SEL_MASK (0x80U)
#define PCIE_PHY_CMN_REG061_OVRD_PLL_MISC_OSC_FREQ_SEL_SHIFT (7U)
/*! OVRD_PLL_MISC_OSC_FREQ_SEL - Override enable for pll_misc_osc_freq_sel */
#define PCIE_PHY_CMN_REG061_OVRD_PLL_MISC_OSC_FREQ_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG061_OVRD_PLL_MISC_OSC_FREQ_SEL_SHIFT)) & PCIE_PHY_CMN_REG061_OVRD_PLL_MISC_OSC_FREQ_SEL_MASK)
/*! @} */

/*! @name CMN_REG062 -  */
/*! @{ */

#define PCIE_PHY_CMN_REG062_ANA_PLL_REF_CLK_MON_SEL_MASK (0x3U)
#define PCIE_PHY_CMN_REG062_ANA_PLL_REF_CLK_MON_SEL_SHIFT (0U)
/*! ANA_PLL_REF_CLK_MON_SEL - PLL reference clock selection for monitor */
#define PCIE_PHY_CMN_REG062_ANA_PLL_REF_CLK_MON_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG062_ANA_PLL_REF_CLK_MON_SEL_SHIFT)) & PCIE_PHY_CMN_REG062_ANA_PLL_REF_CLK_MON_SEL_MASK)

#define PCIE_PHY_CMN_REG062_ANA_PLL_REF_CLK_MON_EN_MASK (0x4U)
#define PCIE_PHY_CMN_REG062_ANA_PLL_REF_CLK_MON_EN_SHIFT (2U)
/*! ANA_PLL_REF_CLK_MON_EN - PLL reference clock monitor enable */
#define PCIE_PHY_CMN_REG062_ANA_PLL_REF_CLK_MON_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG062_ANA_PLL_REF_CLK_MON_EN_SHIFT)) & PCIE_PHY_CMN_REG062_ANA_PLL_REF_CLK_MON_EN_MASK)

#define PCIE_PHY_CMN_REG062_ANA_PLL_CLK_OUT_TO_EXT_IO_SEL_MASK (0x8U)
#define PCIE_PHY_CMN_REG062_ANA_PLL_CLK_OUT_TO_EXT_IO_SEL_SHIFT (3U)
/*! ANA_PLL_CLK_OUT_TO_EXT_IO_SEL - PLL low-frequency clock output to external I/O source selection */
#define PCIE_PHY_CMN_REG062_ANA_PLL_CLK_OUT_TO_EXT_IO_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG062_ANA_PLL_CLK_OUT_TO_EXT_IO_SEL_SHIFT)) & PCIE_PHY_CMN_REG062_ANA_PLL_CLK_OUT_TO_EXT_IO_SEL_MASK)
/*! @} */

/*! @name CMN_REG063 -  */
/*! @{ */

#define PCIE_PHY_CMN_REG063_ANA_PLL_RESERVED_MASK (0x3FU)
#define PCIE_PHY_CMN_REG063_ANA_PLL_RESERVED_SHIFT (0U)
/*! ANA_PLL_RESERVED - PLL Reserved pins */
#define PCIE_PHY_CMN_REG063_ANA_PLL_RESERVED(x)  (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG063_ANA_PLL_RESERVED_SHIFT)) & PCIE_PHY_CMN_REG063_ANA_PLL_RESERVED_MASK)

#define PCIE_PHY_CMN_REG063_AUX_PLL_REFCLK_SEL_MASK (0xC0U)
#define PCIE_PHY_CMN_REG063_AUX_PLL_REFCLK_SEL_SHIFT (6U)
/*! AUX_PLL_REFCLK_SEL - 0X: AUX_IN (PLL clock) */
#define PCIE_PHY_CMN_REG063_AUX_PLL_REFCLK_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG063_AUX_PLL_REFCLK_SEL_SHIFT)) & PCIE_PHY_CMN_REG063_AUX_PLL_REFCLK_SEL_MASK)
/*! @} */

/*! @name CMN_REG064 -  */
/*! @{ */

#define PCIE_PHY_CMN_REG064_ANA_AUX_TX_TERM_MASK (0x7U)
#define PCIE_PHY_CMN_REG064_ANA_AUX_TX_TERM_SHIFT (0U)
/*! ANA_AUX_TX_TERM - TX termination resistor control. Default code : 010, 50.7Ω */
#define PCIE_PHY_CMN_REG064_ANA_AUX_TX_TERM(x)   (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG064_ANA_AUX_TX_TERM_SHIFT)) & PCIE_PHY_CMN_REG064_ANA_AUX_TX_TERM_MASK)

#define PCIE_PHY_CMN_REG064_ANA_AUX_RX_TERM_GND_EN_MASK (0x8U)
#define PCIE_PHY_CMN_REG064_ANA_AUX_RX_TERM_GND_EN_SHIFT (3U)
/*! ANA_AUX_RX_TERM_GND_EN - External reference clock I/O termination to ground */
#define PCIE_PHY_CMN_REG064_ANA_AUX_RX_TERM_GND_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG064_ANA_AUX_RX_TERM_GND_EN_SHIFT)) & PCIE_PHY_CMN_REG064_ANA_AUX_RX_TERM_GND_EN_MASK)

#define PCIE_PHY_CMN_REG064_ANA_AUX_RX_CAP_BYPASS_MASK (0x10U)
#define PCIE_PHY_CMN_REG064_ANA_AUX_RX_CAP_BYPASS_SHIFT (4U)
/*! ANA_AUX_RX_CAP_BYPASS - External reference clock I/O AC-coupling capacitor bypass enable */
#define PCIE_PHY_CMN_REG064_ANA_AUX_RX_CAP_BYPASS(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG064_ANA_AUX_RX_CAP_BYPASS_SHIFT)) & PCIE_PHY_CMN_REG064_ANA_AUX_RX_CAP_BYPASS_MASK)

#define PCIE_PHY_CMN_REG064_AUX_EN_MASK          (0x20U)
#define PCIE_PHY_CMN_REG064_AUX_EN_SHIFT         (5U)
/*! AUX_EN - AUX Enable */
#define PCIE_PHY_CMN_REG064_AUX_EN(x)            (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG064_AUX_EN_SHIFT)) & PCIE_PHY_CMN_REG064_AUX_EN_MASK)

#define PCIE_PHY_CMN_REG064_OVRD_AUX_EN_MASK     (0x40U)
#define PCIE_PHY_CMN_REG064_OVRD_AUX_EN_SHIFT    (6U)
/*! OVRD_AUX_EN - Override enable for aux_en */
#define PCIE_PHY_CMN_REG064_OVRD_AUX_EN(x)       (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG064_OVRD_AUX_EN_SHIFT)) & PCIE_PHY_CMN_REG064_OVRD_AUX_EN_MASK)

#define PCIE_PHY_CMN_REG064_ANA_AUX_RX_TX_SEL_MASK (0x80U)
#define PCIE_PHY_CMN_REG064_ANA_AUX_RX_TX_SEL_SHIFT (7U)
/*! ANA_AUX_RX_TX_SEL - Select mode (TX or RX) */
#define PCIE_PHY_CMN_REG064_ANA_AUX_RX_TX_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG064_ANA_AUX_RX_TX_SEL_SHIFT)) & PCIE_PHY_CMN_REG064_ANA_AUX_RX_TX_SEL_MASK)
/*! @} */

/*! @name CMN_REG065 -  */
/*! @{ */

#define PCIE_PHY_CMN_REG065_ANA_AUX_TX_LVL_CTRL_MASK (0xFU)
#define PCIE_PHY_CMN_REG065_ANA_AUX_TX_LVL_CTRL_SHIFT (0U)
/*! ANA_AUX_TX_LVL_CTRL - TX Amplitude resistor control. Default code : 101, 375mVpp */
#define PCIE_PHY_CMN_REG065_ANA_AUX_TX_LVL_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG065_ANA_AUX_TX_LVL_CTRL_SHIFT)) & PCIE_PHY_CMN_REG065_ANA_AUX_TX_LVL_CTRL_MASK)

#define PCIE_PHY_CMN_REG065_ANA_AUX_RX_TERM_MASK (0xF0U)
#define PCIE_PHY_CMN_REG065_ANA_AUX_RX_TERM_SHIFT (4U)
/*! ANA_AUX_RX_TERM - RX termination resistor control. Default code : 1001, 99.6Ω */
#define PCIE_PHY_CMN_REG065_ANA_AUX_RX_TERM(x)   (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG065_ANA_AUX_RX_TERM_SHIFT)) & PCIE_PHY_CMN_REG065_ANA_AUX_RX_TERM_MASK)
/*! @} */

/*! @name CMN_REG066 -  */
/*! @{ */

#define PCIE_PHY_CMN_REG066_ANA_AUX_RX_HYS_CTRL_MASK (0x7U)
#define PCIE_PHY_CMN_REG066_ANA_AUX_RX_HYS_CTRL_SHIFT (0U)
/*! ANA_AUX_RX_HYS_CTRL - Hysteresis for RX noise blocking control. */
#define PCIE_PHY_CMN_REG066_ANA_AUX_RX_HYS_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG066_ANA_AUX_RX_HYS_CTRL_SHIFT)) & PCIE_PHY_CMN_REG066_ANA_AUX_RX_HYS_CTRL_MASK)

#define PCIE_PHY_CMN_REG066_ANA_AUX_RX_VCM_FINE_CTRL_MASK (0x18U)
#define PCIE_PHY_CMN_REG066_ANA_AUX_RX_VCM_FINE_CTRL_SHIFT (3U)
/*! ANA_AUX_RX_VCM_FINE_CTRL - VCM of RX control. 171mV ~ 680mV at typical condition. */
#define PCIE_PHY_CMN_REG066_ANA_AUX_RX_VCM_FINE_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG066_ANA_AUX_RX_VCM_FINE_CTRL_SHIFT)) & PCIE_PHY_CMN_REG066_ANA_AUX_RX_VCM_FINE_CTRL_MASK)

#define PCIE_PHY_CMN_REG066_ANA_AUX_RX_VCM_COARSE_CTRL_MASK (0x60U)
#define PCIE_PHY_CMN_REG066_ANA_AUX_RX_VCM_COARSE_CTRL_SHIFT (5U)
/*! ANA_AUX_RX_VCM_COARSE_CTRL - VCM of RX control. 171mV ~ 680mV at typical condition. */
#define PCIE_PHY_CMN_REG066_ANA_AUX_RX_VCM_COARSE_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG066_ANA_AUX_RX_VCM_COARSE_CTRL_SHIFT)) & PCIE_PHY_CMN_REG066_ANA_AUX_RX_VCM_COARSE_CTRL_MASK)

#define PCIE_PHY_CMN_REG066_ANA_AUX_RX_VCM_SEL_MASK (0x80U)
#define PCIE_PHY_CMN_REG066_ANA_AUX_RX_VCM_SEL_SHIFT (7U)
/*! ANA_AUX_RX_VCM_SEL - Input common mode voltage control. */
#define PCIE_PHY_CMN_REG066_ANA_AUX_RX_VCM_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG066_ANA_AUX_RX_VCM_SEL_SHIFT)) & PCIE_PHY_CMN_REG066_ANA_AUX_RX_VCM_SEL_MASK)
/*! @} */

/*! @name CMN_REG067 -  */
/*! @{ */

#define PCIE_PHY_CMN_REG067_ANA_AUX_RESERVED_MASK (0xFFU)
#define PCIE_PHY_CMN_REG067_ANA_AUX_RESERVED_SHIFT (0U)
/*! ANA_AUX_RESERVED - Reserved port */
#define PCIE_PHY_CMN_REG067_ANA_AUX_RESERVED(x)  (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG067_ANA_AUX_RESERVED_SHIFT)) & PCIE_PHY_CMN_REG067_ANA_AUX_RESERVED_MASK)
/*! @} */

/*! @name CMN_REG068 -  */
/*! @{ */

#define PCIE_PHY_CMN_REG068_PLL_LOCK_DONE_MASK   (0x1U)
#define PCIE_PHY_CMN_REG068_PLL_LOCK_DONE_SHIFT  (0U)
/*! PLL_LOCK_DONE - PLL lock done overide value */
#define PCIE_PHY_CMN_REG068_PLL_LOCK_DONE(x)     (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG068_PLL_LOCK_DONE_SHIFT)) & PCIE_PHY_CMN_REG068_PLL_LOCK_DONE_MASK)

#define PCIE_PHY_CMN_REG068_OVRD_PLL_LOCK_DONE_MASK (0x2U)
#define PCIE_PHY_CMN_REG068_OVRD_PLL_LOCK_DONE_SHIFT (1U)
/*! OVRD_PLL_LOCK_DONE - Override enable for pll_lock_done */
#define PCIE_PHY_CMN_REG068_OVRD_PLL_LOCK_DONE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG068_OVRD_PLL_LOCK_DONE_SHIFT)) & PCIE_PHY_CMN_REG068_OVRD_PLL_LOCK_DONE_MASK)

#define PCIE_PHY_CMN_REG068_PLL_AFC_DONE_MASK    (0x4U)
#define PCIE_PHY_CMN_REG068_PLL_AFC_DONE_SHIFT   (2U)
/*! PLL_AFC_DONE - PLL AFC done overide value */
#define PCIE_PHY_CMN_REG068_PLL_AFC_DONE(x)      (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG068_PLL_AFC_DONE_SHIFT)) & PCIE_PHY_CMN_REG068_PLL_AFC_DONE_MASK)

#define PCIE_PHY_CMN_REG068_OVRD_PLL_AFC_DONE_MASK (0x8U)
#define PCIE_PHY_CMN_REG068_OVRD_PLL_AFC_DONE_SHIFT (3U)
/*! OVRD_PLL_AFC_DONE - Override enable for pll_afc_done */
#define PCIE_PHY_CMN_REG068_OVRD_PLL_AFC_DONE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG068_OVRD_PLL_AFC_DONE_SHIFT)) & PCIE_PHY_CMN_REG068_OVRD_PLL_AFC_DONE_MASK)

#define PCIE_PHY_CMN_REG068_BGR_SET_DONE_MASK    (0x10U)
#define PCIE_PHY_CMN_REG068_BGR_SET_DONE_SHIFT   (4U)
/*! BGR_SET_DONE - BGR set done */
#define PCIE_PHY_CMN_REG068_BGR_SET_DONE(x)      (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG068_BGR_SET_DONE_SHIFT)) & PCIE_PHY_CMN_REG068_BGR_SET_DONE_MASK)

#define PCIE_PHY_CMN_REG068_OVRD_BGR_SET_DONE_MASK (0x20U)
#define PCIE_PHY_CMN_REG068_OVRD_BGR_SET_DONE_SHIFT (5U)
/*! OVRD_BGR_SET_DONE - Override enable for bgr_set_done */
#define PCIE_PHY_CMN_REG068_OVRD_BGR_SET_DONE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG068_OVRD_BGR_SET_DONE_SHIFT)) & PCIE_PHY_CMN_REG068_OVRD_BGR_SET_DONE_MASK)
/*! @} */

/*! @name CMN_REG069 -  */
/*! @{ */

#define PCIE_PHY_CMN_REG069_PLL_FINE_TUNE_START_MASK (0x1U)
#define PCIE_PHY_CMN_REG069_PLL_FINE_TUNE_START_SHIFT (0U)
#define PCIE_PHY_CMN_REG069_PLL_FINE_TUNE_START(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG069_PLL_FINE_TUNE_START_SHIFT)) & PCIE_PHY_CMN_REG069_PLL_FINE_TUNE_START_MASK)

#define PCIE_PHY_CMN_REG069_OVRD_PLL_FINE_TUNE_START_MASK (0x2U)
#define PCIE_PHY_CMN_REG069_OVRD_PLL_FINE_TUNE_START_SHIFT (1U)
/*! OVRD_PLL_FINE_TUNE_START - Override enable for pll_fine_tune_start */
#define PCIE_PHY_CMN_REG069_OVRD_PLL_FINE_TUNE_START(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG069_OVRD_PLL_FINE_TUNE_START_SHIFT)) & PCIE_PHY_CMN_REG069_OVRD_PLL_FINE_TUNE_START_MASK)

#define PCIE_PHY_CMN_REG069_HIGH_SPEED_MASK      (0x4U)
#define PCIE_PHY_CMN_REG069_HIGH_SPEED_SHIFT     (2U)
/*! HIGH_SPEED - HIGH SPEED indicator by operating LC VCO */
#define PCIE_PHY_CMN_REG069_HIGH_SPEED(x)        (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG069_HIGH_SPEED_SHIFT)) & PCIE_PHY_CMN_REG069_HIGH_SPEED_MASK)

#define PCIE_PHY_CMN_REG069_OVRD_HIGH_SPEED_MASK (0x8U)
#define PCIE_PHY_CMN_REG069_OVRD_HIGH_SPEED_SHIFT (3U)
/*! OVRD_HIGH_SPEED - Override enable for high_speed */
#define PCIE_PHY_CMN_REG069_OVRD_HIGH_SPEED(x)   (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG069_OVRD_HIGH_SPEED_SHIFT)) & PCIE_PHY_CMN_REG069_OVRD_HIGH_SPEED_MASK)

#define PCIE_PHY_CMN_REG069_PHY_MODE_MASK        (0x30U)
#define PCIE_PHY_CMN_REG069_PHY_MODE_SHIFT       (4U)
#define PCIE_PHY_CMN_REG069_PHY_MODE(x)          (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG069_PHY_MODE_SHIFT)) & PCIE_PHY_CMN_REG069_PHY_MODE_MASK)

#define PCIE_PHY_CMN_REG069_OVRD_PHY_MODE_MASK   (0x40U)
#define PCIE_PHY_CMN_REG069_OVRD_PHY_MODE_SHIFT  (6U)
/*! OVRD_PHY_MODE - Override enable for phy_mode */
#define PCIE_PHY_CMN_REG069_OVRD_PHY_MODE(x)     (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG069_OVRD_PHY_MODE_SHIFT)) & PCIE_PHY_CMN_REG069_OVRD_PHY_MODE_MASK)
/*! @} */

/*! @name CMN_REG06A -  */
/*! @{ */

#define PCIE_PHY_CMN_REG06A_TG_BGR_FAST_PULSE_TIME_MASK (0xFU)
#define PCIE_PHY_CMN_REG06A_TG_BGR_FAST_PULSE_TIME_SHIFT (0U)
/*! TG_BGR_FAST_PULSE_TIME - BGR LPF bypass duration after BGR_EN = 1 */
#define PCIE_PHY_CMN_REG06A_TG_BGR_FAST_PULSE_TIME(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG06A_TG_BGR_FAST_PULSE_TIME_SHIFT)) & PCIE_PHY_CMN_REG06A_TG_BGR_FAST_PULSE_TIME_MASK)

#define PCIE_PHY_CMN_REG06A_CMN_TIMER_SEL_MASK   (0x10U)
#define PCIE_PHY_CMN_REG06A_CMN_TIMER_SEL_SHIFT  (4U)
#define PCIE_PHY_CMN_REG06A_CMN_TIMER_SEL(x)     (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG06A_CMN_TIMER_SEL_SHIFT)) & PCIE_PHY_CMN_REG06A_CMN_TIMER_SEL_MASK)

#define PCIE_PHY_CMN_REG06A_CMN_RATE_MASK        (0x60U)
#define PCIE_PHY_CMN_REG06A_CMN_RATE_SHIFT       (5U)
/*! CMN_RATE - TX Data Rate manual setting */
#define PCIE_PHY_CMN_REG06A_CMN_RATE(x)          (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG06A_CMN_RATE_SHIFT)) & PCIE_PHY_CMN_REG06A_CMN_RATE_MASK)

#define PCIE_PHY_CMN_REG06A_OVRD_CMN_RATE_MASK   (0x80U)
#define PCIE_PHY_CMN_REG06A_OVRD_CMN_RATE_SHIFT  (7U)
/*! OVRD_CMN_RATE - Override enable for cmn_rate */
#define PCIE_PHY_CMN_REG06A_OVRD_CMN_RATE(x)     (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG06A_OVRD_CMN_RATE_SHIFT)) & PCIE_PHY_CMN_REG06A_OVRD_CMN_RATE_MASK)
/*! @} */

/*! @name CMN_REG06B -  */
/*! @{ */

#define PCIE_PHY_CMN_REG06B_TG_PLL_SDM_RSTN_DELAY_TIME_MASK (0x7U)
#define PCIE_PHY_CMN_REG06B_TG_PLL_SDM_RSTN_DELAY_TIME_SHIFT (0U)
/*! TG_PLL_SDM_RSTN_DELAY_TIME - PLL SDM start delay after PLL integer-mode lock(PLL lock) */
#define PCIE_PHY_CMN_REG06B_TG_PLL_SDM_RSTN_DELAY_TIME(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG06B_TG_PLL_SDM_RSTN_DELAY_TIME_SHIFT)) & PCIE_PHY_CMN_REG06B_TG_PLL_SDM_RSTN_DELAY_TIME_MASK)

#define PCIE_PHY_CMN_REG06B_TG_BGR_SET_DELAY_TIME_MASK (0x38U)
#define PCIE_PHY_CMN_REG06B_TG_BGR_SET_DELAY_TIME_SHIFT (3U)
#define PCIE_PHY_CMN_REG06B_TG_BGR_SET_DELAY_TIME(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG06B_TG_BGR_SET_DELAY_TIME_SHIFT)) & PCIE_PHY_CMN_REG06B_TG_BGR_SET_DELAY_TIME_MASK)
/*! @} */

/*! @name CMN_REG06C -  */
/*! @{ */

#define PCIE_PHY_CMN_REG06C_TG_PLL_FINE_LOCK_DELAY_TIME_MASK (0x7U)
#define PCIE_PHY_CMN_REG06C_TG_PLL_FINE_LOCK_DELAY_TIME_SHIFT (0U)
/*! TG_PLL_FINE_LOCK_DELAY_TIME - PLL Fine LOCK DLY CODE */
#define PCIE_PHY_CMN_REG06C_TG_PLL_FINE_LOCK_DELAY_TIME(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG06C_TG_PLL_FINE_LOCK_DELAY_TIME_SHIFT)) & PCIE_PHY_CMN_REG06C_TG_PLL_FINE_LOCK_DELAY_TIME_MASK)

#define PCIE_PHY_CMN_REG06C_TG_PLL_AFC_RSTN_DELAY_TIME_MASK (0x38U)
#define PCIE_PHY_CMN_REG06C_TG_PLL_AFC_RSTN_DELAY_TIME_SHIFT (3U)
/*! TG_PLL_AFC_RSTN_DELAY_TIME - PLL AFC reset delay time after bypassing BGR LPF */
#define PCIE_PHY_CMN_REG06C_TG_PLL_AFC_RSTN_DELAY_TIME(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG06C_TG_PLL_AFC_RSTN_DELAY_TIME_SHIFT)) & PCIE_PHY_CMN_REG06C_TG_PLL_AFC_RSTN_DELAY_TIME_MASK)
/*! @} */

/*! @name CMN_REG06D -  */
/*! @{ */

#define PCIE_PHY_CMN_REG06D_TG_PLL_SDC_RSTN_DELAY_TIME_MASK (0x7U)
#define PCIE_PHY_CMN_REG06D_TG_PLL_SDC_RSTN_DELAY_TIME_SHIFT (0U)
/*! TG_PLL_SDC_RSTN_DELAY_TIME - PLL SDM RESET STABLE DLY CODE */
#define PCIE_PHY_CMN_REG06D_TG_PLL_SDC_RSTN_DELAY_TIME(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG06D_TG_PLL_SDC_RSTN_DELAY_TIME_SHIFT)) & PCIE_PHY_CMN_REG06D_TG_PLL_SDC_RSTN_DELAY_TIME_MASK)

#define PCIE_PHY_CMN_REG06D_TG_PLL_SSC_EN_DELAY_TIME_MASK (0x38U)
#define PCIE_PHY_CMN_REG06D_TG_PLL_SSC_EN_DELAY_TIME_SHIFT (3U)
/*! TG_PLL_SSC_EN_DELAY_TIME - PLL SSC start delay time after */
#define PCIE_PHY_CMN_REG06D_TG_PLL_SSC_EN_DELAY_TIME(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG06D_TG_PLL_SSC_EN_DELAY_TIME_SHIFT)) & PCIE_PHY_CMN_REG06D_TG_PLL_SSC_EN_DELAY_TIME_MASK)
/*! @} */

/*! @name CMN_REG06E -  */
/*! @{ */

#define PCIE_PHY_CMN_REG06E_TG_PLL_CD_TX_SER_RSTN_DELAY_TIME_MASK (0x7U)
#define PCIE_PHY_CMN_REG06E_TG_PLL_CD_TX_SER_RSTN_DELAY_TIME_SHIFT (0U)
#define PCIE_PHY_CMN_REG06E_TG_PLL_CD_TX_SER_RSTN_DELAY_TIME(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG06E_TG_PLL_CD_TX_SER_RSTN_DELAY_TIME_SHIFT)) & PCIE_PHY_CMN_REG06E_TG_PLL_CD_TX_SER_RSTN_DELAY_TIME_MASK)
/*! @} */

/*! @name CMN_REG06F -  */
/*! @{ */

#define PCIE_PHY_CMN_REG06F_DTB_SEL_MASK         (0xFFU)
#define PCIE_PHY_CMN_REG06F_DTB_SEL_SHIFT        (0U)
/*! DTB_SEL - Digital Test Bus (DTB) selection */
#define PCIE_PHY_CMN_REG06F_DTB_SEL(x)           (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG06F_DTB_SEL_SHIFT)) & PCIE_PHY_CMN_REG06F_DTB_SEL_MASK)
/*! @} */

/*! @name CMN_REG070 -  */
/*! @{ */

#define PCIE_PHY_CMN_REG070_ANA_PLL_AFC_RING_CODE_MON_MASK (0xFU)
#define PCIE_PHY_CMN_REG070_ANA_PLL_AFC_RING_CODE_MON_SHIFT (0U)
/*! ANA_PLL_AFC_RING_CODE_MON - LC AFC code MSB monitor */
#define PCIE_PHY_CMN_REG070_ANA_PLL_AFC_RING_CODE_MON(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG070_ANA_PLL_AFC_RING_CODE_MON_SHIFT)) & PCIE_PHY_CMN_REG070_ANA_PLL_AFC_RING_CODE_MON_MASK)

#define PCIE_PHY_CMN_REG070_ANA_PLL_AFC_LC_CODE_MON_MASK (0x30U)
#define PCIE_PHY_CMN_REG070_ANA_PLL_AFC_LC_CODE_MON_SHIFT (4U)
/*! ANA_PLL_AFC_LC_CODE_MON - LC AFC code MSB monitor */
#define PCIE_PHY_CMN_REG070_ANA_PLL_AFC_LC_CODE_MON(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG070_ANA_PLL_AFC_LC_CODE_MON_SHIFT)) & PCIE_PHY_CMN_REG070_ANA_PLL_AFC_LC_CODE_MON_MASK)
/*! @} */

/*! @name CMN_REG071 -  */
/*! @{ */

#define PCIE_PHY_CMN_REG071_ANA_PLL_AGMC_CODE_MON_MASK (0xFU)
#define PCIE_PHY_CMN_REG071_ANA_PLL_AGMC_CODE_MON_SHIFT (0U)
/*! ANA_PLL_AGMC_CODE_MON - LC VCO GM code monitor */
#define PCIE_PHY_CMN_REG071_ANA_PLL_AGMC_CODE_MON(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG071_ANA_PLL_AGMC_CODE_MON_SHIFT)) & PCIE_PHY_CMN_REG071_ANA_PLL_AGMC_CODE_MON_MASK)
/*! @} */

/*! @name CMN_REG072 -  */
/*! @{ */

#define PCIE_PHY_CMN_REG072_MON_CMN_STATE_MASK   (0x1FU)
#define PCIE_PHY_CMN_REG072_MON_CMN_STATE_SHIFT  (0U)
/*! MON_CMN_STATE - CMN state monitor */
#define PCIE_PHY_CMN_REG072_MON_CMN_STATE(x)     (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG072_MON_CMN_STATE_SHIFT)) & PCIE_PHY_CMN_REG072_MON_CMN_STATE_MASK)
/*! @} */

/*! @name CMN_REG073 -  */
/*! @{ */

#define PCIE_PHY_CMN_REG073_MON_CMN_TIME__14_8_MASK (0x7FU)
#define PCIE_PHY_CMN_REG073_MON_CMN_TIME__14_8_SHIFT (0U)
/*! MON_CMN_TIME__14_8 - CMN timer monitor */
#define PCIE_PHY_CMN_REG073_MON_CMN_TIME__14_8(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG073_MON_CMN_TIME__14_8_SHIFT)) & PCIE_PHY_CMN_REG073_MON_CMN_TIME__14_8_MASK)
/*! @} */

/*! @name CMN_REG074 -  */
/*! @{ */

#define PCIE_PHY_CMN_REG074_MON_CMN_TIME__7_0_MASK (0xFFU)
#define PCIE_PHY_CMN_REG074_MON_CMN_TIME__7_0_SHIFT (0U)
/*! MON_CMN_TIME__7_0 - CMN timer monitor */
#define PCIE_PHY_CMN_REG074_MON_CMN_TIME__7_0(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG074_MON_CMN_TIME__7_0_SHIFT)) & PCIE_PHY_CMN_REG074_MON_CMN_TIME__7_0_MASK)
/*! @} */

/*! @name CMN_REG075 -  */
/*! @{ */

#define PCIE_PHY_CMN_REG075_ANA_PLL_AFC_DONE_MASK (0x1U)
#define PCIE_PHY_CMN_REG075_ANA_PLL_AFC_DONE_SHIFT (0U)
/*! ANA_PLL_AFC_DONE - PLL AFC Done */
#define PCIE_PHY_CMN_REG075_ANA_PLL_AFC_DONE(x)  (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG075_ANA_PLL_AFC_DONE_SHIFT)) & PCIE_PHY_CMN_REG075_ANA_PLL_AFC_DONE_MASK)

#define PCIE_PHY_CMN_REG075_ANA_PLL_LOCK_DONE_MASK (0x2U)
#define PCIE_PHY_CMN_REG075_ANA_PLL_LOCK_DONE_SHIFT (1U)
/*! ANA_PLL_LOCK_DONE - PLL Lock Done */
#define PCIE_PHY_CMN_REG075_ANA_PLL_LOCK_DONE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG075_ANA_PLL_LOCK_DONE_SHIFT)) & PCIE_PHY_CMN_REG075_ANA_PLL_LOCK_DONE_MASK)
/*! @} */

/*! @name CMN_REG076 -  */
/*! @{ */

#define PCIE_PHY_CMN_REG076_LANE0_RESET_MUX_SEL_MASK (0x3U)
#define PCIE_PHY_CMN_REG076_LANE0_RESET_MUX_SEL_SHIFT (0U)
/*! LANE0_RESET_MUX_SEL - 0x0 : Lane0 reset signal from Port 0 */
#define PCIE_PHY_CMN_REG076_LANE0_RESET_MUX_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG076_LANE0_RESET_MUX_SEL_SHIFT)) & PCIE_PHY_CMN_REG076_LANE0_RESET_MUX_SEL_MASK)

#define PCIE_PHY_CMN_REG076_LANE1_RESET_MUX_SEL_MASK (0xCU)
#define PCIE_PHY_CMN_REG076_LANE1_RESET_MUX_SEL_SHIFT (2U)
/*! LANE1_RESET_MUX_SEL - 0x0 : Lane1 reset signal from Port 0 */
#define PCIE_PHY_CMN_REG076_LANE1_RESET_MUX_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG076_LANE1_RESET_MUX_SEL_SHIFT)) & PCIE_PHY_CMN_REG076_LANE1_RESET_MUX_SEL_MASK)

#define PCIE_PHY_CMN_REG076_LANE2_RESET_MUX_SEL_MASK (0x30U)
#define PCIE_PHY_CMN_REG076_LANE2_RESET_MUX_SEL_SHIFT (4U)
/*! LANE2_RESET_MUX_SEL - 0x0 : Lane2 reset signal from Port 0 */
#define PCIE_PHY_CMN_REG076_LANE2_RESET_MUX_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG076_LANE2_RESET_MUX_SEL_SHIFT)) & PCIE_PHY_CMN_REG076_LANE2_RESET_MUX_SEL_MASK)

#define PCIE_PHY_CMN_REG076_LANE3_RESET_MUX_SEL_MASK (0xC0U)
#define PCIE_PHY_CMN_REG076_LANE3_RESET_MUX_SEL_SHIFT (6U)
/*! LANE3_RESET_MUX_SEL - 0x0 : Lane3 reset signal from Port 0 */
#define PCIE_PHY_CMN_REG076_LANE3_RESET_MUX_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG076_LANE3_RESET_MUX_SEL_SHIFT)) & PCIE_PHY_CMN_REG076_LANE3_RESET_MUX_SEL_MASK)
/*! @} */

/*! @name CMN_REG077 -  */
/*! @{ */

#define PCIE_PHY_CMN_REG077_LANE0_SW_RESET_MASK  (0x1U)
#define PCIE_PHY_CMN_REG077_LANE0_SW_RESET_SHIFT (0U)
/*! LANE0_SW_RESET - 0x0 : Lane0 reset */
#define PCIE_PHY_CMN_REG077_LANE0_SW_RESET(x)    (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG077_LANE0_SW_RESET_SHIFT)) & PCIE_PHY_CMN_REG077_LANE0_SW_RESET_MASK)

#define PCIE_PHY_CMN_REG077_LANE1_SW_RESET_MASK  (0x2U)
#define PCIE_PHY_CMN_REG077_LANE1_SW_RESET_SHIFT (1U)
/*! LANE1_SW_RESET - 0x0 : Lane1 reset */
#define PCIE_PHY_CMN_REG077_LANE1_SW_RESET(x)    (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG077_LANE1_SW_RESET_SHIFT)) & PCIE_PHY_CMN_REG077_LANE1_SW_RESET_MASK)

#define PCIE_PHY_CMN_REG077_LANE2_SW_RESET_MASK  (0x4U)
#define PCIE_PHY_CMN_REG077_LANE2_SW_RESET_SHIFT (2U)
/*! LANE2_SW_RESET - 0x0 : Lane2 reset */
#define PCIE_PHY_CMN_REG077_LANE2_SW_RESET(x)    (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG077_LANE2_SW_RESET_SHIFT)) & PCIE_PHY_CMN_REG077_LANE2_SW_RESET_MASK)

#define PCIE_PHY_CMN_REG077_LANE3_SW_RESET_MASK  (0x8U)
#define PCIE_PHY_CMN_REG077_LANE3_SW_RESET_SHIFT (3U)
/*! LANE3_SW_RESET - 0x0 : Lane3 reset */
#define PCIE_PHY_CMN_REG077_LANE3_SW_RESET(x)    (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG077_LANE3_SW_RESET_SHIFT)) & PCIE_PHY_CMN_REG077_LANE3_SW_RESET_MASK)

#define PCIE_PHY_CMN_REG077_CMN_SW_RESET_MASK    (0x10U)
#define PCIE_PHY_CMN_REG077_CMN_SW_RESET_SHIFT   (4U)
/*! CMN_SW_RESET - 0x0 : cmn reset */
#define PCIE_PHY_CMN_REG077_CMN_SW_RESET(x)      (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG077_CMN_SW_RESET_SHIFT)) & PCIE_PHY_CMN_REG077_CMN_SW_RESET_MASK)
/*! @} */

/*! @name CMN_REG078 -  */
/*! @{ */

#define PCIE_PHY_CMN_REG078_LANE0_TX_DATA_CLK_MUX_SEL_MASK (0x3U)
#define PCIE_PHY_CMN_REG078_LANE0_TX_DATA_CLK_MUX_SEL_SHIFT (0U)
#define PCIE_PHY_CMN_REG078_LANE0_TX_DATA_CLK_MUX_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG078_LANE0_TX_DATA_CLK_MUX_SEL_SHIFT)) & PCIE_PHY_CMN_REG078_LANE0_TX_DATA_CLK_MUX_SEL_MASK)

#define PCIE_PHY_CMN_REG078_LANE1_TX_DATA_CLK_MUX_SEL_MASK (0xCU)
#define PCIE_PHY_CMN_REG078_LANE1_TX_DATA_CLK_MUX_SEL_SHIFT (2U)
#define PCIE_PHY_CMN_REG078_LANE1_TX_DATA_CLK_MUX_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG078_LANE1_TX_DATA_CLK_MUX_SEL_SHIFT)) & PCIE_PHY_CMN_REG078_LANE1_TX_DATA_CLK_MUX_SEL_MASK)

#define PCIE_PHY_CMN_REG078_LANE2_TX_DATA_CLK_MUX_SEL_MASK (0x30U)
#define PCIE_PHY_CMN_REG078_LANE2_TX_DATA_CLK_MUX_SEL_SHIFT (4U)
#define PCIE_PHY_CMN_REG078_LANE2_TX_DATA_CLK_MUX_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG078_LANE2_TX_DATA_CLK_MUX_SEL_SHIFT)) & PCIE_PHY_CMN_REG078_LANE2_TX_DATA_CLK_MUX_SEL_MASK)

#define PCIE_PHY_CMN_REG078_LANE3_TX_DATA_CLK_MUX_SEL_MASK (0xC0U)
#define PCIE_PHY_CMN_REG078_LANE3_TX_DATA_CLK_MUX_SEL_SHIFT (6U)
/*! LANE3_TX_DATA_CLK_MUX_SEL - 0x0 : tx data clock from lane0 */
#define PCIE_PHY_CMN_REG078_LANE3_TX_DATA_CLK_MUX_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG078_LANE3_TX_DATA_CLK_MUX_SEL_SHIFT)) & PCIE_PHY_CMN_REG078_LANE3_TX_DATA_CLK_MUX_SEL_MASK)
/*! @} */

/*! @name CMN_REG079 -  */
/*! @{ */

#define PCIE_PHY_CMN_REG079_CMN_RESET_CONTROL_MASK (0x1U)
#define PCIE_PHY_CMN_REG079_CMN_RESET_CONTROL_SHIFT (0U)
#define PCIE_PHY_CMN_REG079_CMN_RESET_CONTROL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG079_CMN_RESET_CONTROL_SHIFT)) & PCIE_PHY_CMN_REG079_CMN_RESET_CONTROL_MASK)
/*! @} */

/*! @name CMN_REG080 -  */
/*! @{ */

#define PCIE_PHY_CMN_REG080_RATE_CHANGE_DELAY_MASK (0xFFU)
#define PCIE_PHY_CMN_REG080_RATE_CHANGE_DELAY_SHIFT (0U)
#define PCIE_PHY_CMN_REG080_RATE_CHANGE_DELAY(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG080_RATE_CHANGE_DELAY_SHIFT)) & PCIE_PHY_CMN_REG080_RATE_CHANGE_DELAY_MASK)
/*! @} */

/*! @name CMN_REG081 -  */
/*! @{ */

#define PCIE_PHY_CMN_REG081_RX_EFOM_ERROR_TH_7_0_MASK (0xFFU)
#define PCIE_PHY_CMN_REG081_RX_EFOM_ERROR_TH_7_0_SHIFT (0U)
#define PCIE_PHY_CMN_REG081_RX_EFOM_ERROR_TH_7_0(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG081_RX_EFOM_ERROR_TH_7_0_SHIFT)) & PCIE_PHY_CMN_REG081_RX_EFOM_ERROR_TH_7_0_MASK)
/*! @} */

/*! @name CMN_REG082 -  */
/*! @{ */

#define PCIE_PHY_CMN_REG082_RX_EFOM_ERROR_TH_9_8_MASK (0x3U)
#define PCIE_PHY_CMN_REG082_RX_EFOM_ERROR_TH_9_8_SHIFT (0U)
#define PCIE_PHY_CMN_REG082_RX_EFOM_ERROR_TH_9_8(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_CMN_REG082_RX_EFOM_ERROR_TH_9_8_SHIFT)) & PCIE_PHY_CMN_REG082_RX_EFOM_ERROR_TH_9_8_MASK)
/*! @} */

/*! @name TRSV_REG000 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG000_LN0_TX_DRV_EI_EN_MASK (0x1U)
#define PCIE_PHY_TRSV_REG000_LN0_TX_DRV_EI_EN_SHIFT (0U)
/*! LN0_TX_DRV_EI_EN - TX driver electrical-idle state enable */
#define PCIE_PHY_TRSV_REG000_LN0_TX_DRV_EI_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG000_LN0_TX_DRV_EI_EN_SHIFT)) & PCIE_PHY_TRSV_REG000_LN0_TX_DRV_EI_EN_MASK)

#define PCIE_PHY_TRSV_REG000_LN0_OVRD_TX_DRV_EI_EN_MASK (0x2U)
#define PCIE_PHY_TRSV_REG000_LN0_OVRD_TX_DRV_EI_EN_SHIFT (1U)
/*! LN0_OVRD_TX_DRV_EI_EN - Override enable for tx_drv_ei_en */
#define PCIE_PHY_TRSV_REG000_LN0_OVRD_TX_DRV_EI_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG000_LN0_OVRD_TX_DRV_EI_EN_SHIFT)) & PCIE_PHY_TRSV_REG000_LN0_OVRD_TX_DRV_EI_EN_MASK)

#define PCIE_PHY_TRSV_REG000_LN0_TX_DRV_CM_KEEPER_EN_MASK (0x4U)
#define PCIE_PHY_TRSV_REG000_LN0_TX_DRV_CM_KEEPER_EN_SHIFT (2U)
/*! LN0_TX_DRV_CM_KEEPER_EN - TX driver common-mode keep enable */
#define PCIE_PHY_TRSV_REG000_LN0_TX_DRV_CM_KEEPER_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG000_LN0_TX_DRV_CM_KEEPER_EN_SHIFT)) & PCIE_PHY_TRSV_REG000_LN0_TX_DRV_CM_KEEPER_EN_MASK)

#define PCIE_PHY_TRSV_REG000_LN0_OVRD_TX_DRV_CM_KEEPER_EN_MASK (0x8U)
#define PCIE_PHY_TRSV_REG000_LN0_OVRD_TX_DRV_CM_KEEPER_EN_SHIFT (3U)
/*! LN0_OVRD_TX_DRV_CM_KEEPER_EN - Override enable for tx_drv_cm_keeper_en */
#define PCIE_PHY_TRSV_REG000_LN0_OVRD_TX_DRV_CM_KEEPER_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG000_LN0_OVRD_TX_DRV_CM_KEEPER_EN_SHIFT)) & PCIE_PHY_TRSV_REG000_LN0_OVRD_TX_DRV_CM_KEEPER_EN_MASK)

#define PCIE_PHY_TRSV_REG000_LN0_TX_DRV_BEACON_LFPS_OUT_EN_MASK (0x10U)
#define PCIE_PHY_TRSV_REG000_LN0_TX_DRV_BEACON_LFPS_OUT_EN_SHIFT (4U)
/*! LN0_TX_DRV_BEACON_LFPS_OUT_EN - TX beacon or LFPS enable */
#define PCIE_PHY_TRSV_REG000_LN0_TX_DRV_BEACON_LFPS_OUT_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG000_LN0_TX_DRV_BEACON_LFPS_OUT_EN_SHIFT)) & PCIE_PHY_TRSV_REG000_LN0_TX_DRV_BEACON_LFPS_OUT_EN_MASK)

#define PCIE_PHY_TRSV_REG000_LN0_OVRD_TX_DRV_BEACON_LFPS_OUT_EN_MASK (0x20U)
#define PCIE_PHY_TRSV_REG000_LN0_OVRD_TX_DRV_BEACON_LFPS_OUT_EN_SHIFT (5U)
/*! LN0_OVRD_TX_DRV_BEACON_LFPS_OUT_EN - Override enable for tx_drv_beacon_lfps_out_en */
#define PCIE_PHY_TRSV_REG000_LN0_OVRD_TX_DRV_BEACON_LFPS_OUT_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG000_LN0_OVRD_TX_DRV_BEACON_LFPS_OUT_EN_SHIFT)) & PCIE_PHY_TRSV_REG000_LN0_OVRD_TX_DRV_BEACON_LFPS_OUT_EN_MASK)

#define PCIE_PHY_TRSV_REG000_LN0_TX_DRV_EN_MASK  (0x40U)
#define PCIE_PHY_TRSV_REG000_LN0_TX_DRV_EN_SHIFT (6U)
/*! LN0_TX_DRV_EN - TX driver enable */
#define PCIE_PHY_TRSV_REG000_LN0_TX_DRV_EN(x)    (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG000_LN0_TX_DRV_EN_SHIFT)) & PCIE_PHY_TRSV_REG000_LN0_TX_DRV_EN_MASK)

#define PCIE_PHY_TRSV_REG000_LN0_OVRD_TX_DRV_EN_MASK (0x80U)
#define PCIE_PHY_TRSV_REG000_LN0_OVRD_TX_DRV_EN_SHIFT (7U)
/*! LN0_OVRD_TX_DRV_EN - Override enable for tx_drv_en */
#define PCIE_PHY_TRSV_REG000_LN0_OVRD_TX_DRV_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG000_LN0_OVRD_TX_DRV_EN_SHIFT)) & PCIE_PHY_TRSV_REG000_LN0_OVRD_TX_DRV_EN_MASK)
/*! @} */

/*! @name TRSV_REG001 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG001_LN0_TX_DRV_LVL_CTRL_G1_MASK (0x1FU)
#define PCIE_PHY_TRSV_REG001_LN0_TX_DRV_LVL_CTRL_G1_SHIFT (0U)
/*! LN0_TX_DRV_LVL_CTRL_G1 - [GEN1] TX driver main-tap level */
#define PCIE_PHY_TRSV_REG001_LN0_TX_DRV_LVL_CTRL_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG001_LN0_TX_DRV_LVL_CTRL_G1_SHIFT)) & PCIE_PHY_TRSV_REG001_LN0_TX_DRV_LVL_CTRL_G1_MASK)

#define PCIE_PHY_TRSV_REG001_LN0_OVRD_TX_DRV_LVL_CTRL_MASK (0x20U)
#define PCIE_PHY_TRSV_REG001_LN0_OVRD_TX_DRV_LVL_CTRL_SHIFT (5U)
/*! LN0_OVRD_TX_DRV_LVL_CTRL - Override enable for tx_drv_lvl_ctrl_g1 */
#define PCIE_PHY_TRSV_REG001_LN0_OVRD_TX_DRV_LVL_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG001_LN0_OVRD_TX_DRV_LVL_CTRL_SHIFT)) & PCIE_PHY_TRSV_REG001_LN0_OVRD_TX_DRV_LVL_CTRL_MASK)
/*! @} */

/*! @name TRSV_REG002 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG002_LN0_TX_DRV_LVL_CTRL_G2_MASK (0x1FU)
#define PCIE_PHY_TRSV_REG002_LN0_TX_DRV_LVL_CTRL_G2_SHIFT (0U)
/*! LN0_TX_DRV_LVL_CTRL_G2 - [GEN2] */
#define PCIE_PHY_TRSV_REG002_LN0_TX_DRV_LVL_CTRL_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG002_LN0_TX_DRV_LVL_CTRL_G2_SHIFT)) & PCIE_PHY_TRSV_REG002_LN0_TX_DRV_LVL_CTRL_G2_MASK)
/*! @} */

/*! @name TRSV_REG003 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG003_LN0_TX_DRV_LVL_CTRL_G3_MASK (0x1FU)
#define PCIE_PHY_TRSV_REG003_LN0_TX_DRV_LVL_CTRL_G3_SHIFT (0U)
/*! LN0_TX_DRV_LVL_CTRL_G3 - [GEN3] */
#define PCIE_PHY_TRSV_REG003_LN0_TX_DRV_LVL_CTRL_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG003_LN0_TX_DRV_LVL_CTRL_G3_SHIFT)) & PCIE_PHY_TRSV_REG003_LN0_TX_DRV_LVL_CTRL_G3_MASK)
/*! @} */

/*! @name TRSV_REG004 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG004_LN0_TX_DRV_LVL_CTRL_G4_MASK (0x1FU)
#define PCIE_PHY_TRSV_REG004_LN0_TX_DRV_LVL_CTRL_G4_SHIFT (0U)
/*! LN0_TX_DRV_LVL_CTRL_G4 - [GEN4] */
#define PCIE_PHY_TRSV_REG004_LN0_TX_DRV_LVL_CTRL_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG004_LN0_TX_DRV_LVL_CTRL_G4_SHIFT)) & PCIE_PHY_TRSV_REG004_LN0_TX_DRV_LVL_CTRL_G4_MASK)
/*! @} */

/*! @name TRSV_REG005 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG005_LN0_TX_DRV_POST_LVL_CTRL_G1_MASK (0x1FU)
#define PCIE_PHY_TRSV_REG005_LN0_TX_DRV_POST_LVL_CTRL_G1_SHIFT (0U)
/*! LN0_TX_DRV_POST_LVL_CTRL_G1 - [GEN1] TX driver de-emphasis level */
#define PCIE_PHY_TRSV_REG005_LN0_TX_DRV_POST_LVL_CTRL_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG005_LN0_TX_DRV_POST_LVL_CTRL_G1_SHIFT)) & PCIE_PHY_TRSV_REG005_LN0_TX_DRV_POST_LVL_CTRL_G1_MASK)

#define PCIE_PHY_TRSV_REG005_LN0_OVRD_TX_DRV_POST_LVL_CTRL_MASK (0x20U)
#define PCIE_PHY_TRSV_REG005_LN0_OVRD_TX_DRV_POST_LVL_CTRL_SHIFT (5U)
/*! LN0_OVRD_TX_DRV_POST_LVL_CTRL - Override enable for tx_drv_post_lvl_ctrl_g1 */
#define PCIE_PHY_TRSV_REG005_LN0_OVRD_TX_DRV_POST_LVL_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG005_LN0_OVRD_TX_DRV_POST_LVL_CTRL_SHIFT)) & PCIE_PHY_TRSV_REG005_LN0_OVRD_TX_DRV_POST_LVL_CTRL_MASK)
/*! @} */

/*! @name TRSV_REG006 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG006_LN0_TX_DRV_POST_LVL_CTRL_G2_MASK (0x1FU)
#define PCIE_PHY_TRSV_REG006_LN0_TX_DRV_POST_LVL_CTRL_G2_SHIFT (0U)
/*! LN0_TX_DRV_POST_LVL_CTRL_G2 - [GEN2] */
#define PCIE_PHY_TRSV_REG006_LN0_TX_DRV_POST_LVL_CTRL_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG006_LN0_TX_DRV_POST_LVL_CTRL_G2_SHIFT)) & PCIE_PHY_TRSV_REG006_LN0_TX_DRV_POST_LVL_CTRL_G2_MASK)
/*! @} */

/*! @name TRSV_REG007 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG007_LN0_TX_DRV_POST_LVL_CTRL_G3_MASK (0x1FU)
#define PCIE_PHY_TRSV_REG007_LN0_TX_DRV_POST_LVL_CTRL_G3_SHIFT (0U)
/*! LN0_TX_DRV_POST_LVL_CTRL_G3 - [GEN3] */
#define PCIE_PHY_TRSV_REG007_LN0_TX_DRV_POST_LVL_CTRL_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG007_LN0_TX_DRV_POST_LVL_CTRL_G3_SHIFT)) & PCIE_PHY_TRSV_REG007_LN0_TX_DRV_POST_LVL_CTRL_G3_MASK)
/*! @} */

/*! @name TRSV_REG008 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG008_LN0_TX_DRV_POST_LVL_CTRL_G4_MASK (0x1FU)
#define PCIE_PHY_TRSV_REG008_LN0_TX_DRV_POST_LVL_CTRL_G4_SHIFT (0U)
/*! LN0_TX_DRV_POST_LVL_CTRL_G4 - [GEN4] */
#define PCIE_PHY_TRSV_REG008_LN0_TX_DRV_POST_LVL_CTRL_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG008_LN0_TX_DRV_POST_LVL_CTRL_G4_SHIFT)) & PCIE_PHY_TRSV_REG008_LN0_TX_DRV_POST_LVL_CTRL_G4_MASK)
/*! @} */

/*! @name TRSV_REG009 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG009_LN0_TX_DRV_PRE_LVL_CTRL_G1_MASK (0xFU)
#define PCIE_PHY_TRSV_REG009_LN0_TX_DRV_PRE_LVL_CTRL_G1_SHIFT (0U)
/*! LN0_TX_DRV_PRE_LVL_CTRL_G1 - [GEN1] TX driver pre-shoot level */
#define PCIE_PHY_TRSV_REG009_LN0_TX_DRV_PRE_LVL_CTRL_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG009_LN0_TX_DRV_PRE_LVL_CTRL_G1_SHIFT)) & PCIE_PHY_TRSV_REG009_LN0_TX_DRV_PRE_LVL_CTRL_G1_MASK)

#define PCIE_PHY_TRSV_REG009_LN0_OVRD_TX_DRV_PRE_LVL_CTRL_MASK (0x10U)
#define PCIE_PHY_TRSV_REG009_LN0_OVRD_TX_DRV_PRE_LVL_CTRL_SHIFT (4U)
/*! LN0_OVRD_TX_DRV_PRE_LVL_CTRL - Override enable for tx_drv_pre_lvl_ctrl_g1 */
#define PCIE_PHY_TRSV_REG009_LN0_OVRD_TX_DRV_PRE_LVL_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG009_LN0_OVRD_TX_DRV_PRE_LVL_CTRL_SHIFT)) & PCIE_PHY_TRSV_REG009_LN0_OVRD_TX_DRV_PRE_LVL_CTRL_MASK)
/*! @} */

/*! @name TRSV_REG00A -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG00A_LN0_TX_DRV_PRE_LVL_CTRL_G3_MASK (0xFU)
#define PCIE_PHY_TRSV_REG00A_LN0_TX_DRV_PRE_LVL_CTRL_G3_SHIFT (0U)
/*! LN0_TX_DRV_PRE_LVL_CTRL_G3 - [GEN3] */
#define PCIE_PHY_TRSV_REG00A_LN0_TX_DRV_PRE_LVL_CTRL_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG00A_LN0_TX_DRV_PRE_LVL_CTRL_G3_SHIFT)) & PCIE_PHY_TRSV_REG00A_LN0_TX_DRV_PRE_LVL_CTRL_G3_MASK)

#define PCIE_PHY_TRSV_REG00A_LN0_TX_DRV_PRE_LVL_CTRL_G2_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG00A_LN0_TX_DRV_PRE_LVL_CTRL_G2_SHIFT (4U)
/*! LN0_TX_DRV_PRE_LVL_CTRL_G2 - [GEN2] */
#define PCIE_PHY_TRSV_REG00A_LN0_TX_DRV_PRE_LVL_CTRL_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG00A_LN0_TX_DRV_PRE_LVL_CTRL_G2_SHIFT)) & PCIE_PHY_TRSV_REG00A_LN0_TX_DRV_PRE_LVL_CTRL_G2_MASK)
/*! @} */

/*! @name TRSV_REG00B -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG00B_LN0_TX_DRV_IDRV_EN_MASK (0x1U)
#define PCIE_PHY_TRSV_REG00B_LN0_TX_DRV_IDRV_EN_SHIFT (0U)
/*! LN0_TX_DRV_IDRV_EN - TX current-driver enable */
#define PCIE_PHY_TRSV_REG00B_LN0_TX_DRV_IDRV_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG00B_LN0_TX_DRV_IDRV_EN_SHIFT)) & PCIE_PHY_TRSV_REG00B_LN0_TX_DRV_IDRV_EN_MASK)

#define PCIE_PHY_TRSV_REG00B_LN0_OVRD_TX_DRV_IDRV_EN_MASK (0x2U)
#define PCIE_PHY_TRSV_REG00B_LN0_OVRD_TX_DRV_IDRV_EN_SHIFT (1U)
/*! LN0_OVRD_TX_DRV_IDRV_EN - Override enable for tx_drv_idrv_en */
#define PCIE_PHY_TRSV_REG00B_LN0_OVRD_TX_DRV_IDRV_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG00B_LN0_OVRD_TX_DRV_IDRV_EN_SHIFT)) & PCIE_PHY_TRSV_REG00B_LN0_OVRD_TX_DRV_IDRV_EN_MASK)

#define PCIE_PHY_TRSV_REG00B_LN0_ANA_TX_DRV_BEACON_LFPS_SYNC_EN_MASK (0x4U)
#define PCIE_PHY_TRSV_REG00B_LN0_ANA_TX_DRV_BEACON_LFPS_SYNC_EN_SHIFT (2U)
/*! LN0_ANA_TX_DRV_BEACON_LFPS_SYNC_EN - TX LFPS/BEACON synchronization enable */
#define PCIE_PHY_TRSV_REG00B_LN0_ANA_TX_DRV_BEACON_LFPS_SYNC_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG00B_LN0_ANA_TX_DRV_BEACON_LFPS_SYNC_EN_SHIFT)) & PCIE_PHY_TRSV_REG00B_LN0_ANA_TX_DRV_BEACON_LFPS_SYNC_EN_MASK)

#define PCIE_PHY_TRSV_REG00B_LN0_TX_DRV_PRE_LVL_CTRL_G4_MASK (0x78U)
#define PCIE_PHY_TRSV_REG00B_LN0_TX_DRV_PRE_LVL_CTRL_G4_SHIFT (3U)
/*! LN0_TX_DRV_PRE_LVL_CTRL_G4 - [GEN4] */
#define PCIE_PHY_TRSV_REG00B_LN0_TX_DRV_PRE_LVL_CTRL_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG00B_LN0_TX_DRV_PRE_LVL_CTRL_G4_SHIFT)) & PCIE_PHY_TRSV_REG00B_LN0_TX_DRV_PRE_LVL_CTRL_G4_MASK)
/*! @} */

/*! @name TRSV_REG00C -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG00C_LN0_ANA_TX_DRV_ACCDRV_EN_MASK (0x1U)
#define PCIE_PHY_TRSV_REG00C_LN0_ANA_TX_DRV_ACCDRV_EN_SHIFT (0U)
/*! LN0_ANA_TX_DRV_ACCDRV_EN - Enable of Cap. Peaking block. */
#define PCIE_PHY_TRSV_REG00C_LN0_ANA_TX_DRV_ACCDRV_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG00C_LN0_ANA_TX_DRV_ACCDRV_EN_SHIFT)) & PCIE_PHY_TRSV_REG00C_LN0_ANA_TX_DRV_ACCDRV_EN_MASK)

#define PCIE_PHY_TRSV_REG00C_LN0_ANA_TX_DRV_IDRV_VREF_SEL_MASK (0x2U)
#define PCIE_PHY_TRSV_REG00C_LN0_ANA_TX_DRV_IDRV_VREF_SEL_SHIFT (1U)
/*! LN0_ANA_TX_DRV_IDRV_VREF_SEL - TX current driver reference selection */
#define PCIE_PHY_TRSV_REG00C_LN0_ANA_TX_DRV_IDRV_VREF_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG00C_LN0_ANA_TX_DRV_IDRV_VREF_SEL_SHIFT)) & PCIE_PHY_TRSV_REG00C_LN0_ANA_TX_DRV_IDRV_VREF_SEL_MASK)

#define PCIE_PHY_TRSV_REG00C_LN0_ANA_TX_DRV_IDRV_IUP_CTRL_MASK (0x1CU)
#define PCIE_PHY_TRSV_REG00C_LN0_ANA_TX_DRV_IDRV_IUP_CTRL_SHIFT (2U)
/*! LN0_ANA_TX_DRV_IDRV_IUP_CTRL - TX current driver pmos current control */
#define PCIE_PHY_TRSV_REG00C_LN0_ANA_TX_DRV_IDRV_IUP_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG00C_LN0_ANA_TX_DRV_IDRV_IUP_CTRL_SHIFT)) & PCIE_PHY_TRSV_REG00C_LN0_ANA_TX_DRV_IDRV_IUP_CTRL_MASK)

#define PCIE_PHY_TRSV_REG00C_LN0_ANA_TX_DRV_IDRV_IDN_CTRL_MASK (0xE0U)
#define PCIE_PHY_TRSV_REG00C_LN0_ANA_TX_DRV_IDRV_IDN_CTRL_SHIFT (5U)
/*! LN0_ANA_TX_DRV_IDRV_IDN_CTRL - TX current driver pmos current control */
#define PCIE_PHY_TRSV_REG00C_LN0_ANA_TX_DRV_IDRV_IDN_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG00C_LN0_ANA_TX_DRV_IDRV_IDN_CTRL_SHIFT)) & PCIE_PHY_TRSV_REG00C_LN0_ANA_TX_DRV_IDRV_IDN_CTRL_MASK)
/*! @} */

/*! @name TRSV_REG00D -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG00D_LN0_RX_VALID_RSTN_DELAY_MASK (0x1FU)
#define PCIE_PHY_TRSV_REG00D_LN0_RX_VALID_RSTN_DELAY_SHIFT (0U)
#define PCIE_PHY_TRSV_REG00D_LN0_RX_VALID_RSTN_DELAY(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG00D_LN0_RX_VALID_RSTN_DELAY_SHIFT)) & PCIE_PHY_TRSV_REG00D_LN0_RX_VALID_RSTN_DELAY_MASK)
/*! @} */

/*! @name TRSV_REG00E -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG00E_LN0_TX_DRV_EI_EN_DELAY_SEL_G4_MASK (0x3U)
#define PCIE_PHY_TRSV_REG00E_LN0_TX_DRV_EI_EN_DELAY_SEL_G4_SHIFT (0U)
/*! LN0_TX_DRV_EI_EN_DELAY_SEL_G4 - [GEN4] */
#define PCIE_PHY_TRSV_REG00E_LN0_TX_DRV_EI_EN_DELAY_SEL_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG00E_LN0_TX_DRV_EI_EN_DELAY_SEL_G4_SHIFT)) & PCIE_PHY_TRSV_REG00E_LN0_TX_DRV_EI_EN_DELAY_SEL_G4_MASK)

#define PCIE_PHY_TRSV_REG00E_LN0_TX_DRV_EI_EN_DELAY_SEL_G3_MASK (0xCU)
#define PCIE_PHY_TRSV_REG00E_LN0_TX_DRV_EI_EN_DELAY_SEL_G3_SHIFT (2U)
/*! LN0_TX_DRV_EI_EN_DELAY_SEL_G3 - [GEN3] */
#define PCIE_PHY_TRSV_REG00E_LN0_TX_DRV_EI_EN_DELAY_SEL_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG00E_LN0_TX_DRV_EI_EN_DELAY_SEL_G3_SHIFT)) & PCIE_PHY_TRSV_REG00E_LN0_TX_DRV_EI_EN_DELAY_SEL_G3_MASK)

#define PCIE_PHY_TRSV_REG00E_LN0_TX_DRV_EI_EN_DELAY_SEL_G2_MASK (0x30U)
#define PCIE_PHY_TRSV_REG00E_LN0_TX_DRV_EI_EN_DELAY_SEL_G2_SHIFT (4U)
/*! LN0_TX_DRV_EI_EN_DELAY_SEL_G2 - [GEN2] */
#define PCIE_PHY_TRSV_REG00E_LN0_TX_DRV_EI_EN_DELAY_SEL_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG00E_LN0_TX_DRV_EI_EN_DELAY_SEL_G2_SHIFT)) & PCIE_PHY_TRSV_REG00E_LN0_TX_DRV_EI_EN_DELAY_SEL_G2_MASK)

#define PCIE_PHY_TRSV_REG00E_LN0_TX_DRV_EI_EN_DELAY_SEL_G1_MASK (0xC0U)
#define PCIE_PHY_TRSV_REG00E_LN0_TX_DRV_EI_EN_DELAY_SEL_G1_SHIFT (6U)
/*! LN0_TX_DRV_EI_EN_DELAY_SEL_G1 - [GEN1] TX EI enable latency control */
#define PCIE_PHY_TRSV_REG00E_LN0_TX_DRV_EI_EN_DELAY_SEL_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG00E_LN0_TX_DRV_EI_EN_DELAY_SEL_G1_SHIFT)) & PCIE_PHY_TRSV_REG00E_LN0_TX_DRV_EI_EN_DELAY_SEL_G1_MASK)
/*! @} */

/*! @name TRSV_REG00F -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG00F_LN0_ANA_TX_DRV_PLL_REF_MON_EN_MASK (0x1U)
#define PCIE_PHY_TRSV_REG00F_LN0_ANA_TX_DRV_PLL_REF_MON_EN_SHIFT (0U)
/*! LN0_ANA_TX_DRV_PLL_REF_MON_EN - Enable of PLL reference clock monitor through Tx driver */
#define PCIE_PHY_TRSV_REG00F_LN0_ANA_TX_DRV_PLL_REF_MON_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG00F_LN0_ANA_TX_DRV_PLL_REF_MON_EN_SHIFT)) & PCIE_PHY_TRSV_REG00F_LN0_ANA_TX_DRV_PLL_REF_MON_EN_MASK)

#define PCIE_PHY_TRSV_REG00F_LN0_ANA_TX_DRV_HSCLK_MON_EN_MASK (0x2U)
#define PCIE_PHY_TRSV_REG00F_LN0_ANA_TX_DRV_HSCLK_MON_EN_SHIFT (1U)
/*! LN0_ANA_TX_DRV_HSCLK_MON_EN - Enable of high-speed clock monitor through Tx driver */
#define PCIE_PHY_TRSV_REG00F_LN0_ANA_TX_DRV_HSCLK_MON_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG00F_LN0_ANA_TX_DRV_HSCLK_MON_EN_SHIFT)) & PCIE_PHY_TRSV_REG00F_LN0_ANA_TX_DRV_HSCLK_MON_EN_MASK)
/*! @} */

/*! @name TRSV_REG010 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG010_LN0_TX_JEQ_CAP_CTRL_G2_MASK (0xFU)
#define PCIE_PHY_TRSV_REG010_LN0_TX_JEQ_CAP_CTRL_G2_SHIFT (0U)
/*! LN0_TX_JEQ_CAP_CTRL_G2 - [GEN2] */
#define PCIE_PHY_TRSV_REG010_LN0_TX_JEQ_CAP_CTRL_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG010_LN0_TX_JEQ_CAP_CTRL_G2_SHIFT)) & PCIE_PHY_TRSV_REG010_LN0_TX_JEQ_CAP_CTRL_G2_MASK)

#define PCIE_PHY_TRSV_REG010_LN0_TX_JEQ_CAP_CTRL_G1_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG010_LN0_TX_JEQ_CAP_CTRL_G1_SHIFT (4U)
/*! LN0_TX_JEQ_CAP_CTRL_G1 - [GEN1] TX jitter EQ loding capacitance control in thermomether */
#define PCIE_PHY_TRSV_REG010_LN0_TX_JEQ_CAP_CTRL_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG010_LN0_TX_JEQ_CAP_CTRL_G1_SHIFT)) & PCIE_PHY_TRSV_REG010_LN0_TX_JEQ_CAP_CTRL_G1_MASK)
/*! @} */

/*! @name TRSV_REG011 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG011_LN0_TX_JEQ_CAP_CTRL_G4_MASK (0xFU)
#define PCIE_PHY_TRSV_REG011_LN0_TX_JEQ_CAP_CTRL_G4_SHIFT (0U)
/*! LN0_TX_JEQ_CAP_CTRL_G4 - [GEN4] */
#define PCIE_PHY_TRSV_REG011_LN0_TX_JEQ_CAP_CTRL_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG011_LN0_TX_JEQ_CAP_CTRL_G4_SHIFT)) & PCIE_PHY_TRSV_REG011_LN0_TX_JEQ_CAP_CTRL_G4_MASK)

#define PCIE_PHY_TRSV_REG011_LN0_TX_JEQ_CAP_CTRL_G3_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG011_LN0_TX_JEQ_CAP_CTRL_G3_SHIFT (4U)
/*! LN0_TX_JEQ_CAP_CTRL_G3 - [GEN3] */
#define PCIE_PHY_TRSV_REG011_LN0_TX_JEQ_CAP_CTRL_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG011_LN0_TX_JEQ_CAP_CTRL_G3_SHIFT)) & PCIE_PHY_TRSV_REG011_LN0_TX_JEQ_CAP_CTRL_G3_MASK)
/*! @} */

/*! @name TRSV_REG012 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG012_LN0_ANA_TX_JEQ_EN_MASK (0x1U)
#define PCIE_PHY_TRSV_REG012_LN0_ANA_TX_JEQ_EN_SHIFT (0U)
/*! LN0_ANA_TX_JEQ_EN - TX jitter EQ enable */
#define PCIE_PHY_TRSV_REG012_LN0_ANA_TX_JEQ_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG012_LN0_ANA_TX_JEQ_EN_SHIFT)) & PCIE_PHY_TRSV_REG012_LN0_ANA_TX_JEQ_EN_MASK)
/*! @} */

/*! @name TRSV_REG013 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG013_LN0_TX_JEQ_EVEN_CTRL_G2_MASK (0xFU)
#define PCIE_PHY_TRSV_REG013_LN0_TX_JEQ_EVEN_CTRL_G2_SHIFT (0U)
/*! LN0_TX_JEQ_EVEN_CTRL_G2 - [GEN2] */
#define PCIE_PHY_TRSV_REG013_LN0_TX_JEQ_EVEN_CTRL_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG013_LN0_TX_JEQ_EVEN_CTRL_G2_SHIFT)) & PCIE_PHY_TRSV_REG013_LN0_TX_JEQ_EVEN_CTRL_G2_MASK)

#define PCIE_PHY_TRSV_REG013_LN0_TX_JEQ_EVEN_CTRL_G1_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG013_LN0_TX_JEQ_EVEN_CTRL_G1_SHIFT (4U)
/*! LN0_TX_JEQ_EVEN_CTRL_G1 - [GEN1] TX jitter EQ driver (even) strength control */
#define PCIE_PHY_TRSV_REG013_LN0_TX_JEQ_EVEN_CTRL_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG013_LN0_TX_JEQ_EVEN_CTRL_G1_SHIFT)) & PCIE_PHY_TRSV_REG013_LN0_TX_JEQ_EVEN_CTRL_G1_MASK)
/*! @} */

/*! @name TRSV_REG014 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG014_LN0_TX_JEQ_EVEN_CTRL_G4_MASK (0xFU)
#define PCIE_PHY_TRSV_REG014_LN0_TX_JEQ_EVEN_CTRL_G4_SHIFT (0U)
/*! LN0_TX_JEQ_EVEN_CTRL_G4 - [GEN4] */
#define PCIE_PHY_TRSV_REG014_LN0_TX_JEQ_EVEN_CTRL_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG014_LN0_TX_JEQ_EVEN_CTRL_G4_SHIFT)) & PCIE_PHY_TRSV_REG014_LN0_TX_JEQ_EVEN_CTRL_G4_MASK)

#define PCIE_PHY_TRSV_REG014_LN0_TX_JEQ_EVEN_CTRL_G3_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG014_LN0_TX_JEQ_EVEN_CTRL_G3_SHIFT (4U)
/*! LN0_TX_JEQ_EVEN_CTRL_G3 - [GEN3] */
#define PCIE_PHY_TRSV_REG014_LN0_TX_JEQ_EVEN_CTRL_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG014_LN0_TX_JEQ_EVEN_CTRL_G3_SHIFT)) & PCIE_PHY_TRSV_REG014_LN0_TX_JEQ_EVEN_CTRL_G3_MASK)
/*! @} */

/*! @name TRSV_REG015 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG015_LN0_TX_JEQ_ODD_CTRL_G2_MASK (0xFU)
#define PCIE_PHY_TRSV_REG015_LN0_TX_JEQ_ODD_CTRL_G2_SHIFT (0U)
/*! LN0_TX_JEQ_ODD_CTRL_G2 - [GEN2] */
#define PCIE_PHY_TRSV_REG015_LN0_TX_JEQ_ODD_CTRL_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG015_LN0_TX_JEQ_ODD_CTRL_G2_SHIFT)) & PCIE_PHY_TRSV_REG015_LN0_TX_JEQ_ODD_CTRL_G2_MASK)

#define PCIE_PHY_TRSV_REG015_LN0_TX_JEQ_ODD_CTRL_G1_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG015_LN0_TX_JEQ_ODD_CTRL_G1_SHIFT (4U)
/*! LN0_TX_JEQ_ODD_CTRL_G1 - [GEN1] TX jitter EQ driver (odd) strength control */
#define PCIE_PHY_TRSV_REG015_LN0_TX_JEQ_ODD_CTRL_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG015_LN0_TX_JEQ_ODD_CTRL_G1_SHIFT)) & PCIE_PHY_TRSV_REG015_LN0_TX_JEQ_ODD_CTRL_G1_MASK)
/*! @} */

/*! @name TRSV_REG016 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG016_LN0_TX_JEQ_ODD_CTRL_G4_MASK (0xFU)
#define PCIE_PHY_TRSV_REG016_LN0_TX_JEQ_ODD_CTRL_G4_SHIFT (0U)
/*! LN0_TX_JEQ_ODD_CTRL_G4 - [GEN4] */
#define PCIE_PHY_TRSV_REG016_LN0_TX_JEQ_ODD_CTRL_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG016_LN0_TX_JEQ_ODD_CTRL_G4_SHIFT)) & PCIE_PHY_TRSV_REG016_LN0_TX_JEQ_ODD_CTRL_G4_MASK)

#define PCIE_PHY_TRSV_REG016_LN0_TX_JEQ_ODD_CTRL_G3_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG016_LN0_TX_JEQ_ODD_CTRL_G3_SHIFT (4U)
/*! LN0_TX_JEQ_ODD_CTRL_G3 - [GEN3] */
#define PCIE_PHY_TRSV_REG016_LN0_TX_JEQ_ODD_CTRL_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG016_LN0_TX_JEQ_ODD_CTRL_G3_SHIFT)) & PCIE_PHY_TRSV_REG016_LN0_TX_JEQ_ODD_CTRL_G3_MASK)
/*! @} */

/*! @name TRSV_REG017 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG017_LN0_ANA_TX_RCAL_IRMRES_CTRL_MASK (0x3U)
#define PCIE_PHY_TRSV_REG017_LN0_ANA_TX_RCAL_IRMRES_CTRL_SHIFT (0U)
/*! LN0_ANA_TX_RCAL_IRMRES_CTRL - TX RCAL rmres bias current control */
#define PCIE_PHY_TRSV_REG017_LN0_ANA_TX_RCAL_IRMRES_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG017_LN0_ANA_TX_RCAL_IRMRES_CTRL_SHIFT)) & PCIE_PHY_TRSV_REG017_LN0_ANA_TX_RCAL_IRMRES_CTRL_MASK)

#define PCIE_PHY_TRSV_REG017_LN0_TX_RCAL_EN_MASK (0x4U)
#define PCIE_PHY_TRSV_REG017_LN0_TX_RCAL_EN_SHIFT (2U)
/*! LN0_TX_RCAL_EN - TX RCAL enable */
#define PCIE_PHY_TRSV_REG017_LN0_TX_RCAL_EN(x)   (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG017_LN0_TX_RCAL_EN_SHIFT)) & PCIE_PHY_TRSV_REG017_LN0_TX_RCAL_EN_MASK)

#define PCIE_PHY_TRSV_REG017_LN0_OVRD_TX_RCAL_EN_MASK (0x8U)
#define PCIE_PHY_TRSV_REG017_LN0_OVRD_TX_RCAL_EN_SHIFT (3U)
/*! LN0_OVRD_TX_RCAL_EN - Override enable for tx_rcal_en */
#define PCIE_PHY_TRSV_REG017_LN0_OVRD_TX_RCAL_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG017_LN0_OVRD_TX_RCAL_EN_SHIFT)) & PCIE_PHY_TRSV_REG017_LN0_OVRD_TX_RCAL_EN_MASK)
/*! @} */

/*! @name TRSV_REG018 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG018_LN0_TX_RXD_EN_MASK  (0x1U)
#define PCIE_PHY_TRSV_REG018_LN0_TX_RXD_EN_SHIFT (0U)
/*! LN0_TX_RXD_EN - TX receiver detector enable. Drives a transition on the serial data and measures
 *    the charge time of the line in order to determine whether a receiver is connected.
 */
#define PCIE_PHY_TRSV_REG018_LN0_TX_RXD_EN(x)    (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG018_LN0_TX_RXD_EN_SHIFT)) & PCIE_PHY_TRSV_REG018_LN0_TX_RXD_EN_MASK)

#define PCIE_PHY_TRSV_REG018_LN0_OVRD_TX_RXD_EN_MASK (0x2U)
#define PCIE_PHY_TRSV_REG018_LN0_OVRD_TX_RXD_EN_SHIFT (1U)
/*! LN0_OVRD_TX_RXD_EN - Override enable for tx_rxd_en */
#define PCIE_PHY_TRSV_REG018_LN0_OVRD_TX_RXD_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG018_LN0_OVRD_TX_RXD_EN_SHIFT)) & PCIE_PHY_TRSV_REG018_LN0_OVRD_TX_RXD_EN_MASK)

#define PCIE_PHY_TRSV_REG018_LN0_TX_RXD_COMP_EN_MASK (0x4U)
#define PCIE_PHY_TRSV_REG018_LN0_TX_RXD_COMP_EN_SHIFT (2U)
/*! LN0_TX_RXD_COMP_EN - TX receiver detector comparator enable */
#define PCIE_PHY_TRSV_REG018_LN0_TX_RXD_COMP_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG018_LN0_TX_RXD_COMP_EN_SHIFT)) & PCIE_PHY_TRSV_REG018_LN0_TX_RXD_COMP_EN_MASK)

#define PCIE_PHY_TRSV_REG018_LN0_OVRD_TX_RXD_COMP_EN_MASK (0x8U)
#define PCIE_PHY_TRSV_REG018_LN0_OVRD_TX_RXD_COMP_EN_SHIFT (3U)
/*! LN0_OVRD_TX_RXD_COMP_EN - Override enable for tx_rxd_comp_en */
#define PCIE_PHY_TRSV_REG018_LN0_OVRD_TX_RXD_COMP_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG018_LN0_OVRD_TX_RXD_COMP_EN_SHIFT)) & PCIE_PHY_TRSV_REG018_LN0_OVRD_TX_RXD_COMP_EN_MASK)

#define PCIE_PHY_TRSV_REG018_LN0_TX_RTERM_42P5_EN_G4_MASK (0x10U)
#define PCIE_PHY_TRSV_REG018_LN0_TX_RTERM_42P5_EN_G4_SHIFT (4U)
/*! LN0_TX_RTERM_42P5_EN_G4 - [GEN4] */
#define PCIE_PHY_TRSV_REG018_LN0_TX_RTERM_42P5_EN_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG018_LN0_TX_RTERM_42P5_EN_G4_SHIFT)) & PCIE_PHY_TRSV_REG018_LN0_TX_RTERM_42P5_EN_G4_MASK)

#define PCIE_PHY_TRSV_REG018_LN0_TX_RTERM_42P5_EN_G3_MASK (0x20U)
#define PCIE_PHY_TRSV_REG018_LN0_TX_RTERM_42P5_EN_G3_SHIFT (5U)
/*! LN0_TX_RTERM_42P5_EN_G3 - [GEN3] */
#define PCIE_PHY_TRSV_REG018_LN0_TX_RTERM_42P5_EN_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG018_LN0_TX_RTERM_42P5_EN_G3_SHIFT)) & PCIE_PHY_TRSV_REG018_LN0_TX_RTERM_42P5_EN_G3_MASK)

#define PCIE_PHY_TRSV_REG018_LN0_TX_RTERM_42P5_EN_G2_MASK (0x40U)
#define PCIE_PHY_TRSV_REG018_LN0_TX_RTERM_42P5_EN_G2_SHIFT (6U)
/*! LN0_TX_RTERM_42P5_EN_G2 - [GEN2] */
#define PCIE_PHY_TRSV_REG018_LN0_TX_RTERM_42P5_EN_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG018_LN0_TX_RTERM_42P5_EN_G2_SHIFT)) & PCIE_PHY_TRSV_REG018_LN0_TX_RTERM_42P5_EN_G2_MASK)

#define PCIE_PHY_TRSV_REG018_LN0_TX_RTERM_42P5_EN_G1_MASK (0x80U)
#define PCIE_PHY_TRSV_REG018_LN0_TX_RTERM_42P5_EN_G1_SHIFT (7U)
/*! LN0_TX_RTERM_42P5_EN_G1 - [GEN1] */
#define PCIE_PHY_TRSV_REG018_LN0_TX_RTERM_42P5_EN_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG018_LN0_TX_RTERM_42P5_EN_G1_SHIFT)) & PCIE_PHY_TRSV_REG018_LN0_TX_RTERM_42P5_EN_G1_MASK)
/*! @} */

/*! @name TRSV_REG019 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG019_LN0_ANA_TX_RXD_COMP_I_CTRL_MASK (0x1U)
#define PCIE_PHY_TRSV_REG019_LN0_ANA_TX_RXD_COMP_I_CTRL_SHIFT (0U)
/*! LN0_ANA_TX_RXD_COMP_I_CTRL - TX receiver detector comparator bias control */
#define PCIE_PHY_TRSV_REG019_LN0_ANA_TX_RXD_COMP_I_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG019_LN0_ANA_TX_RXD_COMP_I_CTRL_SHIFT)) & PCIE_PHY_TRSV_REG019_LN0_ANA_TX_RXD_COMP_I_CTRL_MASK)
/*! @} */

/*! @name TRSV_REG01A -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG01A_LN0_TX_SER_DATA_RSTN_MASK (0x1U)
#define PCIE_PHY_TRSV_REG01A_LN0_TX_SER_DATA_RSTN_SHIFT (0U)
/*! LN0_TX_SER_DATA_RSTN - TX serializer data-path resetn */
#define PCIE_PHY_TRSV_REG01A_LN0_TX_SER_DATA_RSTN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG01A_LN0_TX_SER_DATA_RSTN_SHIFT)) & PCIE_PHY_TRSV_REG01A_LN0_TX_SER_DATA_RSTN_MASK)

#define PCIE_PHY_TRSV_REG01A_LN0_OVRD_TX_SER_DATA_RSTN_MASK (0x2U)
#define PCIE_PHY_TRSV_REG01A_LN0_OVRD_TX_SER_DATA_RSTN_SHIFT (1U)
/*! LN0_OVRD_TX_SER_DATA_RSTN - Override enable for tx_ser_data_rstn */
#define PCIE_PHY_TRSV_REG01A_LN0_OVRD_TX_SER_DATA_RSTN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG01A_LN0_OVRD_TX_SER_DATA_RSTN_SHIFT)) & PCIE_PHY_TRSV_REG01A_LN0_OVRD_TX_SER_DATA_RSTN_MASK)

#define PCIE_PHY_TRSV_REG01A_LN0_TX_SER_40BIT_EN_G4_MASK (0x4U)
#define PCIE_PHY_TRSV_REG01A_LN0_TX_SER_40BIT_EN_G4_SHIFT (2U)
/*! LN0_TX_SER_40BIT_EN_G4 - [GEN4] */
#define PCIE_PHY_TRSV_REG01A_LN0_TX_SER_40BIT_EN_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG01A_LN0_TX_SER_40BIT_EN_G4_SHIFT)) & PCIE_PHY_TRSV_REG01A_LN0_TX_SER_40BIT_EN_G4_MASK)

#define PCIE_PHY_TRSV_REG01A_LN0_TX_SER_40BIT_EN_G3_MASK (0x8U)
#define PCIE_PHY_TRSV_REG01A_LN0_TX_SER_40BIT_EN_G3_SHIFT (3U)
/*! LN0_TX_SER_40BIT_EN_G3 - [GEN3] */
#define PCIE_PHY_TRSV_REG01A_LN0_TX_SER_40BIT_EN_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG01A_LN0_TX_SER_40BIT_EN_G3_SHIFT)) & PCIE_PHY_TRSV_REG01A_LN0_TX_SER_40BIT_EN_G3_MASK)

#define PCIE_PHY_TRSV_REG01A_LN0_TX_SER_40BIT_EN_G2_MASK (0x10U)
#define PCIE_PHY_TRSV_REG01A_LN0_TX_SER_40BIT_EN_G2_SHIFT (4U)
/*! LN0_TX_SER_40BIT_EN_G2 - [GEN2] */
#define PCIE_PHY_TRSV_REG01A_LN0_TX_SER_40BIT_EN_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG01A_LN0_TX_SER_40BIT_EN_G2_SHIFT)) & PCIE_PHY_TRSV_REG01A_LN0_TX_SER_40BIT_EN_G2_MASK)

#define PCIE_PHY_TRSV_REG01A_LN0_TX_SER_40BIT_EN_G1_MASK (0x20U)
#define PCIE_PHY_TRSV_REG01A_LN0_TX_SER_40BIT_EN_G1_SHIFT (5U)
/*! LN0_TX_SER_40BIT_EN_G1 - [GEN1] TX serializer data width selection */
#define PCIE_PHY_TRSV_REG01A_LN0_TX_SER_40BIT_EN_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG01A_LN0_TX_SER_40BIT_EN_G1_SHIFT)) & PCIE_PHY_TRSV_REG01A_LN0_TX_SER_40BIT_EN_G1_MASK)
/*! @} */

/*! @name TRSV_REG01B -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG01B_LN0_ANA_TX_SER_TXCLK_INV_MASK (0x1U)
#define PCIE_PHY_TRSV_REG01B_LN0_ANA_TX_SER_TXCLK_INV_SHIFT (0U)
/*! LN0_ANA_TX_SER_TXCLK_INV - TX byte clock polarity inversion */
#define PCIE_PHY_TRSV_REG01B_LN0_ANA_TX_SER_TXCLK_INV(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG01B_LN0_ANA_TX_SER_TXCLK_INV_SHIFT)) & PCIE_PHY_TRSV_REG01B_LN0_ANA_TX_SER_TXCLK_INV_MASK)

#define PCIE_PHY_TRSV_REG01B_LN0_ANA_TX_CDR_CLK_MON_EN_MASK (0x2U)
#define PCIE_PHY_TRSV_REG01B_LN0_ANA_TX_CDR_CLK_MON_EN_SHIFT (1U)
/*! LN0_ANA_TX_CDR_CLK_MON_EN - TX serializer clock selection */
#define PCIE_PHY_TRSV_REG01B_LN0_ANA_TX_CDR_CLK_MON_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG01B_LN0_ANA_TX_CDR_CLK_MON_EN_SHIFT)) & PCIE_PHY_TRSV_REG01B_LN0_ANA_TX_CDR_CLK_MON_EN_MASK)

#define PCIE_PHY_TRSV_REG01B_LN0_TX_SER_CLK_RSTN_MASK (0x4U)
#define PCIE_PHY_TRSV_REG01B_LN0_TX_SER_CLK_RSTN_SHIFT (2U)
/*! LN0_TX_SER_CLK_RSTN - TX serializer clock-path resetn */
#define PCIE_PHY_TRSV_REG01B_LN0_TX_SER_CLK_RSTN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG01B_LN0_TX_SER_CLK_RSTN_SHIFT)) & PCIE_PHY_TRSV_REG01B_LN0_TX_SER_CLK_RSTN_MASK)

#define PCIE_PHY_TRSV_REG01B_LN0_OVRD_TX_SER_CLK_RSTN_MASK (0x8U)
#define PCIE_PHY_TRSV_REG01B_LN0_OVRD_TX_SER_CLK_RSTN_SHIFT (3U)
/*! LN0_OVRD_TX_SER_CLK_RSTN - Override enable for tx_ser_clk_rstn */
#define PCIE_PHY_TRSV_REG01B_LN0_OVRD_TX_SER_CLK_RSTN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG01B_LN0_OVRD_TX_SER_CLK_RSTN_SHIFT)) & PCIE_PHY_TRSV_REG01B_LN0_OVRD_TX_SER_CLK_RSTN_MASK)

#define PCIE_PHY_TRSV_REG01B_LN0_TX_SER_RATE_SEL_G4_MASK (0x10U)
#define PCIE_PHY_TRSV_REG01B_LN0_TX_SER_RATE_SEL_G4_SHIFT (4U)
/*! LN0_TX_SER_RATE_SEL_G4 - [GEN4] */
#define PCIE_PHY_TRSV_REG01B_LN0_TX_SER_RATE_SEL_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG01B_LN0_TX_SER_RATE_SEL_G4_SHIFT)) & PCIE_PHY_TRSV_REG01B_LN0_TX_SER_RATE_SEL_G4_MASK)

#define PCIE_PHY_TRSV_REG01B_LN0_TX_SER_RATE_SEL_G3_MASK (0x20U)
#define PCIE_PHY_TRSV_REG01B_LN0_TX_SER_RATE_SEL_G3_SHIFT (5U)
/*! LN0_TX_SER_RATE_SEL_G3 - [GEN3] */
#define PCIE_PHY_TRSV_REG01B_LN0_TX_SER_RATE_SEL_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG01B_LN0_TX_SER_RATE_SEL_G3_SHIFT)) & PCIE_PHY_TRSV_REG01B_LN0_TX_SER_RATE_SEL_G3_MASK)

#define PCIE_PHY_TRSV_REG01B_LN0_TX_SER_RATE_SEL_G2_MASK (0x40U)
#define PCIE_PHY_TRSV_REG01B_LN0_TX_SER_RATE_SEL_G2_SHIFT (6U)
/*! LN0_TX_SER_RATE_SEL_G2 - [GEN2] */
#define PCIE_PHY_TRSV_REG01B_LN0_TX_SER_RATE_SEL_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG01B_LN0_TX_SER_RATE_SEL_G2_SHIFT)) & PCIE_PHY_TRSV_REG01B_LN0_TX_SER_RATE_SEL_G2_MASK)

#define PCIE_PHY_TRSV_REG01B_LN0_TX_SER_RATE_SEL_G1_MASK (0x80U)
#define PCIE_PHY_TRSV_REG01B_LN0_TX_SER_RATE_SEL_G1_SHIFT (7U)
/*! LN0_TX_SER_RATE_SEL_G1 - [GEN1] TX serializer data rate selection for Gen4 (Need to be controlled with i_tx_en_40bit) */
#define PCIE_PHY_TRSV_REG01B_LN0_TX_SER_RATE_SEL_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG01B_LN0_TX_SER_RATE_SEL_G1_SHIFT)) & PCIE_PHY_TRSV_REG01B_LN0_TX_SER_RATE_SEL_G1_MASK)
/*! @} */

/*! @name TRSV_REG01C -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG01C_LN0_ANA_TX_ATB_EN_MASK (0x1U)
#define PCIE_PHY_TRSV_REG01C_LN0_ANA_TX_ATB_EN_SHIFT (0U)
/*! LN0_ANA_TX_ATB_EN - TX ATB enable */
#define PCIE_PHY_TRSV_REG01C_LN0_ANA_TX_ATB_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG01C_LN0_ANA_TX_ATB_EN_SHIFT)) & PCIE_PHY_TRSV_REG01C_LN0_ANA_TX_ATB_EN_MASK)

#define PCIE_PHY_TRSV_REG01C_LN0_ANA_TX_ATB_SEL_MASK (0x3EU)
#define PCIE_PHY_TRSV_REG01C_LN0_ANA_TX_ATB_SEL_SHIFT (1U)
/*! LN0_ANA_TX_ATB_SEL - 0000: Serailizer VDD, 0001: Pre Driver VDD, 0010: Driver VDD, 0011: Driver VDDH, */
#define PCIE_PHY_TRSV_REG01C_LN0_ANA_TX_ATB_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG01C_LN0_ANA_TX_ATB_SEL_SHIFT)) & PCIE_PHY_TRSV_REG01C_LN0_ANA_TX_ATB_SEL_MASK)
/*! @} */

/*! @name TRSV_REG01D -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG01D_LN0_ANA_TX_SRLB_EN_MASK (0x1U)
#define PCIE_PHY_TRSV_REG01D_LN0_ANA_TX_SRLB_EN_SHIFT (0U)
/*! LN0_ANA_TX_SRLB_EN - Serial retimed loopback enable */
#define PCIE_PHY_TRSV_REG01D_LN0_ANA_TX_SRLB_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG01D_LN0_ANA_TX_SRLB_EN_SHIFT)) & PCIE_PHY_TRSV_REG01D_LN0_ANA_TX_SRLB_EN_MASK)

#define PCIE_PHY_TRSV_REG01D_LN0_ANA_TX_LLB_EN_MASK (0x2U)
#define PCIE_PHY_TRSV_REG01D_LN0_ANA_TX_LLB_EN_SHIFT (1U)
/*! LN0_ANA_TX_LLB_EN - Line loopback enalble */
#define PCIE_PHY_TRSV_REG01D_LN0_ANA_TX_LLB_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG01D_LN0_ANA_TX_LLB_EN_SHIFT)) & PCIE_PHY_TRSV_REG01D_LN0_ANA_TX_LLB_EN_MASK)

#define PCIE_PHY_TRSV_REG01D_LN0_ANA_TX_SLB_EN_MASK (0x4U)
#define PCIE_PHY_TRSV_REG01D_LN0_ANA_TX_SLB_EN_SHIFT (2U)
/*! LN0_ANA_TX_SLB_EN - Serial loopback enable */
#define PCIE_PHY_TRSV_REG01D_LN0_ANA_TX_SLB_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG01D_LN0_ANA_TX_SLB_EN_SHIFT)) & PCIE_PHY_TRSV_REG01D_LN0_ANA_TX_SLB_EN_MASK)

#define PCIE_PHY_TRSV_REG01D_LN0_ANA_TX_BIAS_RMRES_CTRL_MASK (0x38U)
#define PCIE_PHY_TRSV_REG01D_LN0_ANA_TX_BIAS_RMRES_CTRL_SHIFT (3U)
/*! LN0_ANA_TX_BIAS_RMRES_CTRL - RX RMRES bias current control */
#define PCIE_PHY_TRSV_REG01D_LN0_ANA_TX_BIAS_RMRES_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG01D_LN0_ANA_TX_BIAS_RMRES_CTRL_SHIFT)) & PCIE_PHY_TRSV_REG01D_LN0_ANA_TX_BIAS_RMRES_CTRL_MASK)
/*! @} */

/*! @name TRSV_REG01E -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG01E_LN0_ANA_TX_RESERVED_MASK (0xFU)
#define PCIE_PHY_TRSV_REG01E_LN0_ANA_TX_RESERVED_SHIFT (0U)
/*! LN0_ANA_TX_RESERVED - Reserved port */
#define PCIE_PHY_TRSV_REG01E_LN0_ANA_TX_RESERVED(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG01E_LN0_ANA_TX_RESERVED_SHIFT)) & PCIE_PHY_TRSV_REG01E_LN0_ANA_TX_RESERVED_MASK)

#define PCIE_PHY_TRSV_REG01E_LN0_TX_EQ_2UI_DELAY_EN_G4_MASK (0x10U)
#define PCIE_PHY_TRSV_REG01E_LN0_TX_EQ_2UI_DELAY_EN_G4_SHIFT (4U)
/*! LN0_TX_EQ_2UI_DELAY_EN_G4 - [GEN4] */
#define PCIE_PHY_TRSV_REG01E_LN0_TX_EQ_2UI_DELAY_EN_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG01E_LN0_TX_EQ_2UI_DELAY_EN_G4_SHIFT)) & PCIE_PHY_TRSV_REG01E_LN0_TX_EQ_2UI_DELAY_EN_G4_MASK)

#define PCIE_PHY_TRSV_REG01E_LN0_TX_EQ_2UI_DELAY_EN_G3_MASK (0x20U)
#define PCIE_PHY_TRSV_REG01E_LN0_TX_EQ_2UI_DELAY_EN_G3_SHIFT (5U)
/*! LN0_TX_EQ_2UI_DELAY_EN_G3 - [GEN3] */
#define PCIE_PHY_TRSV_REG01E_LN0_TX_EQ_2UI_DELAY_EN_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG01E_LN0_TX_EQ_2UI_DELAY_EN_G3_SHIFT)) & PCIE_PHY_TRSV_REG01E_LN0_TX_EQ_2UI_DELAY_EN_G3_MASK)

#define PCIE_PHY_TRSV_REG01E_LN0_TX_EQ_2UI_DELAY_EN_G2_MASK (0x40U)
#define PCIE_PHY_TRSV_REG01E_LN0_TX_EQ_2UI_DELAY_EN_G2_SHIFT (6U)
/*! LN0_TX_EQ_2UI_DELAY_EN_G2 - [GEN2] */
#define PCIE_PHY_TRSV_REG01E_LN0_TX_EQ_2UI_DELAY_EN_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG01E_LN0_TX_EQ_2UI_DELAY_EN_G2_SHIFT)) & PCIE_PHY_TRSV_REG01E_LN0_TX_EQ_2UI_DELAY_EN_G2_MASK)

#define PCIE_PHY_TRSV_REG01E_LN0_TX_EQ_2UI_DELAY_EN_G1_MASK (0x80U)
#define PCIE_PHY_TRSV_REG01E_LN0_TX_EQ_2UI_DELAY_EN_G1_SHIFT (7U)
/*! LN0_TX_EQ_2UI_DELAY_EN_G1 - [GEN1] TX FIR filter delay control when bit-duplication */
#define PCIE_PHY_TRSV_REG01E_LN0_TX_EQ_2UI_DELAY_EN_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG01E_LN0_TX_EQ_2UI_DELAY_EN_G1_SHIFT)) & PCIE_PHY_TRSV_REG01E_LN0_TX_EQ_2UI_DELAY_EN_G1_MASK)
/*! @} */

/*! @name TRSV_REG01F -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG01F_LN0_RX_CDR_MODE_CTRL_MASK (0x3U)
#define PCIE_PHY_TRSV_REG01F_LN0_RX_CDR_MODE_CTRL_SHIFT (0U)
/*! LN0_RX_CDR_MODE_CTRL - RX CDR mode select */
#define PCIE_PHY_TRSV_REG01F_LN0_RX_CDR_MODE_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG01F_LN0_RX_CDR_MODE_CTRL_SHIFT)) & PCIE_PHY_TRSV_REG01F_LN0_RX_CDR_MODE_CTRL_MASK)

#define PCIE_PHY_TRSV_REG01F_LN0_OVRD_RX_CDR_MODE_CTRL_MASK (0x4U)
#define PCIE_PHY_TRSV_REG01F_LN0_OVRD_RX_CDR_MODE_CTRL_SHIFT (2U)
/*! LN0_OVRD_RX_CDR_MODE_CTRL - Override enable for rx_cdr_mode_ctrl */
#define PCIE_PHY_TRSV_REG01F_LN0_OVRD_RX_CDR_MODE_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG01F_LN0_OVRD_RX_CDR_MODE_CTRL_SHIFT)) & PCIE_PHY_TRSV_REG01F_LN0_OVRD_RX_CDR_MODE_CTRL_MASK)

#define PCIE_PHY_TRSV_REG01F_LN0_RX_CDR_EN_MASK  (0x8U)
#define PCIE_PHY_TRSV_REG01F_LN0_RX_CDR_EN_SHIFT (3U)
/*! LN0_RX_CDR_EN - RX CDR enable */
#define PCIE_PHY_TRSV_REG01F_LN0_RX_CDR_EN(x)    (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG01F_LN0_RX_CDR_EN_SHIFT)) & PCIE_PHY_TRSV_REG01F_LN0_RX_CDR_EN_MASK)

#define PCIE_PHY_TRSV_REG01F_LN0_OVRD_RX_CDR_EN_MASK (0x10U)
#define PCIE_PHY_TRSV_REG01F_LN0_OVRD_RX_CDR_EN_SHIFT (4U)
/*! LN0_OVRD_RX_CDR_EN - Override enable for rx_cdr_en */
#define PCIE_PHY_TRSV_REG01F_LN0_OVRD_RX_CDR_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG01F_LN0_OVRD_RX_CDR_EN_SHIFT)) & PCIE_PHY_TRSV_REG01F_LN0_OVRD_RX_CDR_EN_MASK)
/*! @} */

/*! @name TRSV_REG020 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG020_LN0_RX_CDR_REFDIV_SEL_PLL_G2_MASK (0xFU)
#define PCIE_PHY_TRSV_REG020_LN0_RX_CDR_REFDIV_SEL_PLL_G2_SHIFT (0U)
/*! LN0_RX_CDR_REFDIV_SEL_PLL_G2 - [GEN2] [PLL mode] */
#define PCIE_PHY_TRSV_REG020_LN0_RX_CDR_REFDIV_SEL_PLL_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG020_LN0_RX_CDR_REFDIV_SEL_PLL_G2_SHIFT)) & PCIE_PHY_TRSV_REG020_LN0_RX_CDR_REFDIV_SEL_PLL_G2_MASK)

#define PCIE_PHY_TRSV_REG020_LN0_RX_CDR_REFDIV_SEL_PLL_G1_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG020_LN0_RX_CDR_REFDIV_SEL_PLL_G1_SHIFT (4U)
/*! LN0_RX_CDR_REFDIV_SEL_PLL_G1 - [GEN1] [PLL mode] Decision of CDR ref. clock dividing-rate */
#define PCIE_PHY_TRSV_REG020_LN0_RX_CDR_REFDIV_SEL_PLL_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG020_LN0_RX_CDR_REFDIV_SEL_PLL_G1_SHIFT)) & PCIE_PHY_TRSV_REG020_LN0_RX_CDR_REFDIV_SEL_PLL_G1_MASK)
/*! @} */

/*! @name TRSV_REG021 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG021_LN0_RX_CDR_REFDIV_SEL_PLL_G4_MASK (0xFU)
#define PCIE_PHY_TRSV_REG021_LN0_RX_CDR_REFDIV_SEL_PLL_G4_SHIFT (0U)
/*! LN0_RX_CDR_REFDIV_SEL_PLL_G4 - [GEN4] [PLL mode] */
#define PCIE_PHY_TRSV_REG021_LN0_RX_CDR_REFDIV_SEL_PLL_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG021_LN0_RX_CDR_REFDIV_SEL_PLL_G4_SHIFT)) & PCIE_PHY_TRSV_REG021_LN0_RX_CDR_REFDIV_SEL_PLL_G4_MASK)

#define PCIE_PHY_TRSV_REG021_LN0_RX_CDR_REFDIV_SEL_PLL_G3_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG021_LN0_RX_CDR_REFDIV_SEL_PLL_G3_SHIFT (4U)
/*! LN0_RX_CDR_REFDIV_SEL_PLL_G3 - [GEN3] [PLL mode] */
#define PCIE_PHY_TRSV_REG021_LN0_RX_CDR_REFDIV_SEL_PLL_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG021_LN0_RX_CDR_REFDIV_SEL_PLL_G3_SHIFT)) & PCIE_PHY_TRSV_REG021_LN0_RX_CDR_REFDIV_SEL_PLL_G3_MASK)
/*! @} */

/*! @name TRSV_REG022 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG022_LN0_RX_CDR_REFDIV_SEL_DATA_G2_MASK (0xFU)
#define PCIE_PHY_TRSV_REG022_LN0_RX_CDR_REFDIV_SEL_DATA_G2_SHIFT (0U)
/*! LN0_RX_CDR_REFDIV_SEL_DATA_G2 - [GEN2] [Data mode] */
#define PCIE_PHY_TRSV_REG022_LN0_RX_CDR_REFDIV_SEL_DATA_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG022_LN0_RX_CDR_REFDIV_SEL_DATA_G2_SHIFT)) & PCIE_PHY_TRSV_REG022_LN0_RX_CDR_REFDIV_SEL_DATA_G2_MASK)

#define PCIE_PHY_TRSV_REG022_LN0_RX_CDR_REFDIV_SEL_DATA_G1_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG022_LN0_RX_CDR_REFDIV_SEL_DATA_G1_SHIFT (4U)
/*! LN0_RX_CDR_REFDIV_SEL_DATA_G1 - [GEN1] [Data mode] Decision of CDR ref. divider ratio */
#define PCIE_PHY_TRSV_REG022_LN0_RX_CDR_REFDIV_SEL_DATA_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG022_LN0_RX_CDR_REFDIV_SEL_DATA_G1_SHIFT)) & PCIE_PHY_TRSV_REG022_LN0_RX_CDR_REFDIV_SEL_DATA_G1_MASK)
/*! @} */

/*! @name TRSV_REG023 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG023_LN0_RX_CDR_REFDIV_SEL_DATA_G4_MASK (0xFU)
#define PCIE_PHY_TRSV_REG023_LN0_RX_CDR_REFDIV_SEL_DATA_G4_SHIFT (0U)
/*! LN0_RX_CDR_REFDIV_SEL_DATA_G4 - [GEN4] [Data mode] */
#define PCIE_PHY_TRSV_REG023_LN0_RX_CDR_REFDIV_SEL_DATA_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG023_LN0_RX_CDR_REFDIV_SEL_DATA_G4_SHIFT)) & PCIE_PHY_TRSV_REG023_LN0_RX_CDR_REFDIV_SEL_DATA_G4_MASK)

#define PCIE_PHY_TRSV_REG023_LN0_RX_CDR_REFDIV_SEL_DATA_G3_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG023_LN0_RX_CDR_REFDIV_SEL_DATA_G3_SHIFT (4U)
/*! LN0_RX_CDR_REFDIV_SEL_DATA_G3 - [GEN3] [Data mode] */
#define PCIE_PHY_TRSV_REG023_LN0_RX_CDR_REFDIV_SEL_DATA_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG023_LN0_RX_CDR_REFDIV_SEL_DATA_G3_SHIFT)) & PCIE_PHY_TRSV_REG023_LN0_RX_CDR_REFDIV_SEL_DATA_G3_MASK)
/*! @} */

/*! @name TRSV_REG024 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG024_LN0_RX_CDR_MDIV_SEL_PLL_G2_MASK (0xFU)
#define PCIE_PHY_TRSV_REG024_LN0_RX_CDR_MDIV_SEL_PLL_G2_SHIFT (0U)
/*! LN0_RX_CDR_MDIV_SEL_PLL_G2 - [GEN2] [PLL mode] */
#define PCIE_PHY_TRSV_REG024_LN0_RX_CDR_MDIV_SEL_PLL_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG024_LN0_RX_CDR_MDIV_SEL_PLL_G2_SHIFT)) & PCIE_PHY_TRSV_REG024_LN0_RX_CDR_MDIV_SEL_PLL_G2_MASK)

#define PCIE_PHY_TRSV_REG024_LN0_RX_CDR_MDIV_SEL_PLL_G1_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG024_LN0_RX_CDR_MDIV_SEL_PLL_G1_SHIFT (4U)
/*! LN0_RX_CDR_MDIV_SEL_PLL_G1 - [GEN1] [PLL mode] Decision of CDR main-divider ratio */
#define PCIE_PHY_TRSV_REG024_LN0_RX_CDR_MDIV_SEL_PLL_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG024_LN0_RX_CDR_MDIV_SEL_PLL_G1_SHIFT)) & PCIE_PHY_TRSV_REG024_LN0_RX_CDR_MDIV_SEL_PLL_G1_MASK)
/*! @} */

/*! @name TRSV_REG025 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG025_LN0_RX_CDR_MDIV_SEL_PLL_G4_MASK (0xFU)
#define PCIE_PHY_TRSV_REG025_LN0_RX_CDR_MDIV_SEL_PLL_G4_SHIFT (0U)
/*! LN0_RX_CDR_MDIV_SEL_PLL_G4 - [GEN4] [PLL mode] */
#define PCIE_PHY_TRSV_REG025_LN0_RX_CDR_MDIV_SEL_PLL_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG025_LN0_RX_CDR_MDIV_SEL_PLL_G4_SHIFT)) & PCIE_PHY_TRSV_REG025_LN0_RX_CDR_MDIV_SEL_PLL_G4_MASK)

#define PCIE_PHY_TRSV_REG025_LN0_RX_CDR_MDIV_SEL_PLL_G3_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG025_LN0_RX_CDR_MDIV_SEL_PLL_G3_SHIFT (4U)
/*! LN0_RX_CDR_MDIV_SEL_PLL_G3 - [GEN3] [PLL mode] */
#define PCIE_PHY_TRSV_REG025_LN0_RX_CDR_MDIV_SEL_PLL_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG025_LN0_RX_CDR_MDIV_SEL_PLL_G3_SHIFT)) & PCIE_PHY_TRSV_REG025_LN0_RX_CDR_MDIV_SEL_PLL_G3_MASK)
/*! @} */

/*! @name TRSV_REG026 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG026_LN0_RX_CDR_MDIV_SEL_DATA_G2_MASK (0xFU)
#define PCIE_PHY_TRSV_REG026_LN0_RX_CDR_MDIV_SEL_DATA_G2_SHIFT (0U)
/*! LN0_RX_CDR_MDIV_SEL_DATA_G2 - [GEN2] [Data mode] */
#define PCIE_PHY_TRSV_REG026_LN0_RX_CDR_MDIV_SEL_DATA_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG026_LN0_RX_CDR_MDIV_SEL_DATA_G2_SHIFT)) & PCIE_PHY_TRSV_REG026_LN0_RX_CDR_MDIV_SEL_DATA_G2_MASK)

#define PCIE_PHY_TRSV_REG026_LN0_RX_CDR_MDIV_SEL_DATA_G1_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG026_LN0_RX_CDR_MDIV_SEL_DATA_G1_SHIFT (4U)
/*! LN0_RX_CDR_MDIV_SEL_DATA_G1 - [GEN1] [Data mode] Decision of CDR main-divider ratio */
#define PCIE_PHY_TRSV_REG026_LN0_RX_CDR_MDIV_SEL_DATA_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG026_LN0_RX_CDR_MDIV_SEL_DATA_G1_SHIFT)) & PCIE_PHY_TRSV_REG026_LN0_RX_CDR_MDIV_SEL_DATA_G1_MASK)
/*! @} */

/*! @name TRSV_REG027 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG027_LN0_RX_CDR_MDIV_SEL_DATA_G4_MASK (0xFU)
#define PCIE_PHY_TRSV_REG027_LN0_RX_CDR_MDIV_SEL_DATA_G4_SHIFT (0U)
/*! LN0_RX_CDR_MDIV_SEL_DATA_G4 - [GEN4] [Data mode] */
#define PCIE_PHY_TRSV_REG027_LN0_RX_CDR_MDIV_SEL_DATA_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG027_LN0_RX_CDR_MDIV_SEL_DATA_G4_SHIFT)) & PCIE_PHY_TRSV_REG027_LN0_RX_CDR_MDIV_SEL_DATA_G4_MASK)

#define PCIE_PHY_TRSV_REG027_LN0_RX_CDR_MDIV_SEL_DATA_G3_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG027_LN0_RX_CDR_MDIV_SEL_DATA_G3_SHIFT (4U)
/*! LN0_RX_CDR_MDIV_SEL_DATA_G3 - [GEN3] [Data mode] */
#define PCIE_PHY_TRSV_REG027_LN0_RX_CDR_MDIV_SEL_DATA_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG027_LN0_RX_CDR_MDIV_SEL_DATA_G3_SHIFT)) & PCIE_PHY_TRSV_REG027_LN0_RX_CDR_MDIV_SEL_DATA_G3_MASK)
/*! @} */

/*! @name TRSV_REG028 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG028_LN0_ANA_RX_CDR_AFC_VCI_FORCE_MASK (0x1U)
#define PCIE_PHY_TRSV_REG028_LN0_ANA_RX_CDR_AFC_VCI_FORCE_SHIFT (0U)
/*! LN0_ANA_RX_CDR_AFC_VCI_FORCE - RX CDR control voltage force */
#define PCIE_PHY_TRSV_REG028_LN0_ANA_RX_CDR_AFC_VCI_FORCE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG028_LN0_ANA_RX_CDR_AFC_VCI_FORCE_SHIFT)) & PCIE_PHY_TRSV_REG028_LN0_ANA_RX_CDR_AFC_VCI_FORCE_MASK)

#define PCIE_PHY_TRSV_REG028_LN0_ANA_RX_CDR_AFC_TEST_EN_MASK (0x2U)
#define PCIE_PHY_TRSV_REG028_LN0_ANA_RX_CDR_AFC_TEST_EN_SHIFT (1U)
/*! LN0_ANA_RX_CDR_AFC_TEST_EN - RX CDR test mode enable */
#define PCIE_PHY_TRSV_REG028_LN0_ANA_RX_CDR_AFC_TEST_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG028_LN0_ANA_RX_CDR_AFC_TEST_EN_SHIFT)) & PCIE_PHY_TRSV_REG028_LN0_ANA_RX_CDR_AFC_TEST_EN_MASK)

#define PCIE_PHY_TRSV_REG028_LN0_ANA_RX_CDR_AFC_EN_MASK (0x4U)
#define PCIE_PHY_TRSV_REG028_LN0_ANA_RX_CDR_AFC_EN_SHIFT (2U)
/*! LN0_ANA_RX_CDR_AFC_EN - RX CDR AFC enable */
#define PCIE_PHY_TRSV_REG028_LN0_ANA_RX_CDR_AFC_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG028_LN0_ANA_RX_CDR_AFC_EN_SHIFT)) & PCIE_PHY_TRSV_REG028_LN0_ANA_RX_CDR_AFC_EN_MASK)

#define PCIE_PHY_TRSV_REG028_LN0_ANA_RX_CDR_DES_RXCLK_INV_MASK (0x8U)
#define PCIE_PHY_TRSV_REG028_LN0_ANA_RX_CDR_DES_RXCLK_INV_SHIFT (3U)
/*! LN0_ANA_RX_CDR_DES_RXCLK_INV - RX byte clock polarity inversion */
#define PCIE_PHY_TRSV_REG028_LN0_ANA_RX_CDR_DES_RXCLK_INV(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG028_LN0_ANA_RX_CDR_DES_RXCLK_INV_SHIFT)) & PCIE_PHY_TRSV_REG028_LN0_ANA_RX_CDR_DES_RXCLK_INV_MASK)

#define PCIE_PHY_TRSV_REG028_LN0_RX_CDR_BW_CTRL_MASK (0x10U)
#define PCIE_PHY_TRSV_REG028_LN0_RX_CDR_BW_CTRL_SHIFT (4U)
/*! LN0_RX_CDR_BW_CTRL - RX CDR bandwidth control */
#define PCIE_PHY_TRSV_REG028_LN0_RX_CDR_BW_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG028_LN0_RX_CDR_BW_CTRL_SHIFT)) & PCIE_PHY_TRSV_REG028_LN0_RX_CDR_BW_CTRL_MASK)

#define PCIE_PHY_TRSV_REG028_LN0_OVRD_RX_CDR_BW_CTRL_MASK (0x20U)
#define PCIE_PHY_TRSV_REG028_LN0_OVRD_RX_CDR_BW_CTRL_SHIFT (5U)
/*! LN0_OVRD_RX_CDR_BW_CTRL - Override enable for rx_cdr_bw_ctrl */
#define PCIE_PHY_TRSV_REG028_LN0_OVRD_RX_CDR_BW_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG028_LN0_OVRD_RX_CDR_BW_CTRL_SHIFT)) & PCIE_PHY_TRSV_REG028_LN0_OVRD_RX_CDR_BW_CTRL_MASK)
/*! @} */

/*! @name TRSV_REG029 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG029_LN0_ANA_RX_CDR_CP_E_EN_MASK (0x1U)
#define PCIE_PHY_TRSV_REG029_LN0_ANA_RX_CDR_CP_E_EN_SHIFT (0U)
/*! LN0_ANA_RX_CDR_CP_E_EN - RX CDR even charge-pump enable */
#define PCIE_PHY_TRSV_REG029_LN0_ANA_RX_CDR_CP_E_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG029_LN0_ANA_RX_CDR_CP_E_EN_SHIFT)) & PCIE_PHY_TRSV_REG029_LN0_ANA_RX_CDR_CP_E_EN_MASK)

#define PCIE_PHY_TRSV_REG029_LN0_ANA_RX_CDR_CP_CTRL_MASK (0xEU)
#define PCIE_PHY_TRSV_REG029_LN0_ANA_RX_CDR_CP_CTRL_SHIFT (1U)
/*! LN0_ANA_RX_CDR_CP_CTRL - RX CDR charge pump current control (Ieven + Iodd) */
#define PCIE_PHY_TRSV_REG029_LN0_ANA_RX_CDR_CP_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG029_LN0_ANA_RX_CDR_CP_CTRL_SHIFT)) & PCIE_PHY_TRSV_REG029_LN0_ANA_RX_CDR_CP_CTRL_MASK)

#define PCIE_PHY_TRSV_REG029_LN0_ANA_RX_CDR_AFC_VCI_SUPPLY_SEL_MASK (0x10U)
#define PCIE_PHY_TRSV_REG029_LN0_ANA_RX_CDR_AFC_VCI_SUPPLY_SEL_SHIFT (4U)
/*! LN0_ANA_RX_CDR_AFC_VCI_SUPPLY_SEL - RX CDR VCI reference voltage selection */
#define PCIE_PHY_TRSV_REG029_LN0_ANA_RX_CDR_AFC_VCI_SUPPLY_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG029_LN0_ANA_RX_CDR_AFC_VCI_SUPPLY_SEL_SHIFT)) & PCIE_PHY_TRSV_REG029_LN0_ANA_RX_CDR_AFC_VCI_SUPPLY_SEL_MASK)
/*! @} */

/*! @name TRSV_REG02A -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG02A_LN0_RX_CDR_VCO_STARTUP_MASK (0x1U)
#define PCIE_PHY_TRSV_REG02A_LN0_RX_CDR_VCO_STARTUP_SHIFT (0U)
/*! LN0_RX_CDR_VCO_STARTUP - RX CDR VCO startup signal, low to high transition */
#define PCIE_PHY_TRSV_REG02A_LN0_RX_CDR_VCO_STARTUP(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG02A_LN0_RX_CDR_VCO_STARTUP_SHIFT)) & PCIE_PHY_TRSV_REG02A_LN0_RX_CDR_VCO_STARTUP_MASK)

#define PCIE_PHY_TRSV_REG02A_LN0_OVRD_RX_CDR_VCO_STARTUP_MASK (0x2U)
#define PCIE_PHY_TRSV_REG02A_LN0_OVRD_RX_CDR_VCO_STARTUP_SHIFT (1U)
/*! LN0_OVRD_RX_CDR_VCO_STARTUP - Override enable for rx_cdr_vco_startup */
#define PCIE_PHY_TRSV_REG02A_LN0_OVRD_RX_CDR_VCO_STARTUP(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG02A_LN0_OVRD_RX_CDR_VCO_STARTUP_SHIFT)) & PCIE_PHY_TRSV_REG02A_LN0_OVRD_RX_CDR_VCO_STARTUP_MASK)

#define PCIE_PHY_TRSV_REG02A_LN0_RX_CDR_FBB_CAL_EN_MASK (0x4U)
#define PCIE_PHY_TRSV_REG02A_LN0_RX_CDR_FBB_CAL_EN_SHIFT (2U)
/*! LN0_RX_CDR_FBB_CAL_EN - RX CDR FBB calibration enable */
#define PCIE_PHY_TRSV_REG02A_LN0_RX_CDR_FBB_CAL_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG02A_LN0_RX_CDR_FBB_CAL_EN_SHIFT)) & PCIE_PHY_TRSV_REG02A_LN0_RX_CDR_FBB_CAL_EN_MASK)

#define PCIE_PHY_TRSV_REG02A_LN0_OVRD_RX_CDR_FBB_CAL_EN_MASK (0x8U)
#define PCIE_PHY_TRSV_REG02A_LN0_OVRD_RX_CDR_FBB_CAL_EN_SHIFT (3U)
/*! LN0_OVRD_RX_CDR_FBB_CAL_EN - Override enable for rx_cdr_fbb_cal_en */
#define PCIE_PHY_TRSV_REG02A_LN0_OVRD_RX_CDR_FBB_CAL_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG02A_LN0_OVRD_RX_CDR_FBB_CAL_EN_SHIFT)) & PCIE_PHY_TRSV_REG02A_LN0_OVRD_RX_CDR_FBB_CAL_EN_MASK)

#define PCIE_PHY_TRSV_REG02A_LN0_ANA_RX_CDR_CP_VREG_LPF_EN_MASK (0x10U)
#define PCIE_PHY_TRSV_REG02A_LN0_ANA_RX_CDR_CP_VREG_LPF_EN_SHIFT (4U)
/*! LN0_ANA_RX_CDR_CP_VREG_LPF_EN - LPF enable for RX CDR charge pump regualtor */
#define PCIE_PHY_TRSV_REG02A_LN0_ANA_RX_CDR_CP_VREG_LPF_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG02A_LN0_ANA_RX_CDR_CP_VREG_LPF_EN_SHIFT)) & PCIE_PHY_TRSV_REG02A_LN0_ANA_RX_CDR_CP_VREG_LPF_EN_MASK)

#define PCIE_PHY_TRSV_REG02A_LN0_ANA_RX_CDR_CP_VREG_IN_SEL_MASK (0x20U)
#define PCIE_PHY_TRSV_REG02A_LN0_ANA_RX_CDR_CP_VREG_IN_SEL_SHIFT (5U)
/*! LN0_ANA_RX_CDR_CP_VREG_IN_SEL - RX CDR charge pump regulator reference voltage selection */
#define PCIE_PHY_TRSV_REG02A_LN0_ANA_RX_CDR_CP_VREG_IN_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG02A_LN0_ANA_RX_CDR_CP_VREG_IN_SEL_SHIFT)) & PCIE_PHY_TRSV_REG02A_LN0_ANA_RX_CDR_CP_VREG_IN_SEL_MASK)

#define PCIE_PHY_TRSV_REG02A_LN0_ANA_RX_CDR_CP_O_EN_MASK (0x40U)
#define PCIE_PHY_TRSV_REG02A_LN0_ANA_RX_CDR_CP_O_EN_SHIFT (6U)
/*! LN0_ANA_RX_CDR_CP_O_EN - RX CDR odd charge-pump enable */
#define PCIE_PHY_TRSV_REG02A_LN0_ANA_RX_CDR_CP_O_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG02A_LN0_ANA_RX_CDR_CP_O_EN_SHIFT)) & PCIE_PHY_TRSV_REG02A_LN0_ANA_RX_CDR_CP_O_EN_MASK)
/*! @} */

/*! @name TRSV_REG02B -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG02B_LN0_ANA_RX_CDR_VCO_BBCAP_DN_CTRL_MASK (0xFU)
#define PCIE_PHY_TRSV_REG02B_LN0_ANA_RX_CDR_VCO_BBCAP_DN_CTRL_SHIFT (0U)
/*! LN0_ANA_RX_CDR_VCO_BBCAP_DN_CTRL - RX CDR BBVCO dummy cap control to decrease frequency */
#define PCIE_PHY_TRSV_REG02B_LN0_ANA_RX_CDR_VCO_BBCAP_DN_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG02B_LN0_ANA_RX_CDR_VCO_BBCAP_DN_CTRL_SHIFT)) & PCIE_PHY_TRSV_REG02B_LN0_ANA_RX_CDR_VCO_BBCAP_DN_CTRL_MASK)
/*! @} */

/*! @name TRSV_REG02C -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG02C_LN0_RX_CDR_VCO_FREQ_BOOST_G4_MASK (0x1U)
#define PCIE_PHY_TRSV_REG02C_LN0_RX_CDR_VCO_FREQ_BOOST_G4_SHIFT (0U)
/*! LN0_RX_CDR_VCO_FREQ_BOOST_G4 - [GEN4] */
#define PCIE_PHY_TRSV_REG02C_LN0_RX_CDR_VCO_FREQ_BOOST_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG02C_LN0_RX_CDR_VCO_FREQ_BOOST_G4_SHIFT)) & PCIE_PHY_TRSV_REG02C_LN0_RX_CDR_VCO_FREQ_BOOST_G4_MASK)

#define PCIE_PHY_TRSV_REG02C_LN0_RX_CDR_VCO_FREQ_BOOST_G3_MASK (0x2U)
#define PCIE_PHY_TRSV_REG02C_LN0_RX_CDR_VCO_FREQ_BOOST_G3_SHIFT (1U)
/*! LN0_RX_CDR_VCO_FREQ_BOOST_G3 - [GEN3] */
#define PCIE_PHY_TRSV_REG02C_LN0_RX_CDR_VCO_FREQ_BOOST_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG02C_LN0_RX_CDR_VCO_FREQ_BOOST_G3_SHIFT)) & PCIE_PHY_TRSV_REG02C_LN0_RX_CDR_VCO_FREQ_BOOST_G3_MASK)

#define PCIE_PHY_TRSV_REG02C_LN0_RX_CDR_VCO_FREQ_BOOST_G2_MASK (0x4U)
#define PCIE_PHY_TRSV_REG02C_LN0_RX_CDR_VCO_FREQ_BOOST_G2_SHIFT (2U)
/*! LN0_RX_CDR_VCO_FREQ_BOOST_G2 - [GEN2] */
#define PCIE_PHY_TRSV_REG02C_LN0_RX_CDR_VCO_FREQ_BOOST_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG02C_LN0_RX_CDR_VCO_FREQ_BOOST_G2_SHIFT)) & PCIE_PHY_TRSV_REG02C_LN0_RX_CDR_VCO_FREQ_BOOST_G2_MASK)

#define PCIE_PHY_TRSV_REG02C_LN0_RX_CDR_VCO_FREQ_BOOST_G1_MASK (0x8U)
#define PCIE_PHY_TRSV_REG02C_LN0_RX_CDR_VCO_FREQ_BOOST_G1_SHIFT (3U)
/*! LN0_RX_CDR_VCO_FREQ_BOOST_G1 - [GEN1] RX CDR VCO frequency boost enable */
#define PCIE_PHY_TRSV_REG02C_LN0_RX_CDR_VCO_FREQ_BOOST_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG02C_LN0_RX_CDR_VCO_FREQ_BOOST_G1_SHIFT)) & PCIE_PHY_TRSV_REG02C_LN0_RX_CDR_VCO_FREQ_BOOST_G1_MASK)
/*! @} */

/*! @name TRSV_REG02D -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG02D_LN0_RX_CDR_VCO_VREG_SEL_G2_MASK (0x7U)
#define PCIE_PHY_TRSV_REG02D_LN0_RX_CDR_VCO_VREG_SEL_G2_SHIFT (0U)
/*! LN0_RX_CDR_VCO_VREG_SEL_G2 - [GEN2] */
#define PCIE_PHY_TRSV_REG02D_LN0_RX_CDR_VCO_VREG_SEL_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG02D_LN0_RX_CDR_VCO_VREG_SEL_G2_SHIFT)) & PCIE_PHY_TRSV_REG02D_LN0_RX_CDR_VCO_VREG_SEL_G2_MASK)

#define PCIE_PHY_TRSV_REG02D_LN0_RX_CDR_VCO_VREG_SEL_G1_MASK (0x38U)
#define PCIE_PHY_TRSV_REG02D_LN0_RX_CDR_VCO_VREG_SEL_G1_SHIFT (3U)
/*! LN0_RX_CDR_VCO_VREG_SEL_G1 - [GEN1] RX CDR voltage regualtor selection */
#define PCIE_PHY_TRSV_REG02D_LN0_RX_CDR_VCO_VREG_SEL_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG02D_LN0_RX_CDR_VCO_VREG_SEL_G1_SHIFT)) & PCIE_PHY_TRSV_REG02D_LN0_RX_CDR_VCO_VREG_SEL_G1_MASK)
/*! @} */

/*! @name TRSV_REG02E -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG02E_LN0_RX_CTLE_EN_MASK (0x1U)
#define PCIE_PHY_TRSV_REG02E_LN0_RX_CTLE_EN_SHIFT (0U)
/*! LN0_RX_CTLE_EN - RX CTLE enable */
#define PCIE_PHY_TRSV_REG02E_LN0_RX_CTLE_EN(x)   (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG02E_LN0_RX_CTLE_EN_SHIFT)) & PCIE_PHY_TRSV_REG02E_LN0_RX_CTLE_EN_MASK)

#define PCIE_PHY_TRSV_REG02E_LN0_OVRD_RX_CTLE_EN_MASK (0x2U)
#define PCIE_PHY_TRSV_REG02E_LN0_OVRD_RX_CTLE_EN_SHIFT (1U)
/*! LN0_OVRD_RX_CTLE_EN - Override enable for rx_ctle_en */
#define PCIE_PHY_TRSV_REG02E_LN0_OVRD_RX_CTLE_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG02E_LN0_OVRD_RX_CTLE_EN_SHIFT)) & PCIE_PHY_TRSV_REG02E_LN0_OVRD_RX_CTLE_EN_MASK)

#define PCIE_PHY_TRSV_REG02E_LN0_RX_CDR_VCO_VREG_SEL_G4_MASK (0x1CU)
#define PCIE_PHY_TRSV_REG02E_LN0_RX_CDR_VCO_VREG_SEL_G4_SHIFT (2U)
/*! LN0_RX_CDR_VCO_VREG_SEL_G4 - [GEN4] */
#define PCIE_PHY_TRSV_REG02E_LN0_RX_CDR_VCO_VREG_SEL_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG02E_LN0_RX_CDR_VCO_VREG_SEL_G4_SHIFT)) & PCIE_PHY_TRSV_REG02E_LN0_RX_CDR_VCO_VREG_SEL_G4_MASK)

#define PCIE_PHY_TRSV_REG02E_LN0_RX_CDR_VCO_VREG_SEL_G3_MASK (0xE0U)
#define PCIE_PHY_TRSV_REG02E_LN0_RX_CDR_VCO_VREG_SEL_G3_SHIFT (5U)
/*! LN0_RX_CDR_VCO_VREG_SEL_G3 - [GEN3] */
#define PCIE_PHY_TRSV_REG02E_LN0_RX_CDR_VCO_VREG_SEL_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG02E_LN0_RX_CDR_VCO_VREG_SEL_G3_SHIFT)) & PCIE_PHY_TRSV_REG02E_LN0_RX_CDR_VCO_VREG_SEL_G3_MASK)
/*! @} */

/*! @name TRSV_REG02F -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG02F_LN0_RX_CTLE_HIGH_BW_EN_G4_MASK (0x1U)
#define PCIE_PHY_TRSV_REG02F_LN0_RX_CTLE_HIGH_BW_EN_G4_SHIFT (0U)
/*! LN0_RX_CTLE_HIGH_BW_EN_G4 - [GEN4] */
#define PCIE_PHY_TRSV_REG02F_LN0_RX_CTLE_HIGH_BW_EN_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG02F_LN0_RX_CTLE_HIGH_BW_EN_G4_SHIFT)) & PCIE_PHY_TRSV_REG02F_LN0_RX_CTLE_HIGH_BW_EN_G4_MASK)

#define PCIE_PHY_TRSV_REG02F_LN0_RX_CTLE_HIGH_BW_EN_G3_MASK (0x2U)
#define PCIE_PHY_TRSV_REG02F_LN0_RX_CTLE_HIGH_BW_EN_G3_SHIFT (1U)
/*! LN0_RX_CTLE_HIGH_BW_EN_G3 - [GEN3] */
#define PCIE_PHY_TRSV_REG02F_LN0_RX_CTLE_HIGH_BW_EN_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG02F_LN0_RX_CTLE_HIGH_BW_EN_G3_SHIFT)) & PCIE_PHY_TRSV_REG02F_LN0_RX_CTLE_HIGH_BW_EN_G3_MASK)

#define PCIE_PHY_TRSV_REG02F_LN0_RX_CTLE_HIGH_BW_EN_G2_MASK (0x4U)
#define PCIE_PHY_TRSV_REG02F_LN0_RX_CTLE_HIGH_BW_EN_G2_SHIFT (2U)
/*! LN0_RX_CTLE_HIGH_BW_EN_G2 - [GEN2] */
#define PCIE_PHY_TRSV_REG02F_LN0_RX_CTLE_HIGH_BW_EN_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG02F_LN0_RX_CTLE_HIGH_BW_EN_G2_SHIFT)) & PCIE_PHY_TRSV_REG02F_LN0_RX_CTLE_HIGH_BW_EN_G2_MASK)

#define PCIE_PHY_TRSV_REG02F_LN0_RX_CTLE_HIGH_BW_EN_G1_MASK (0x8U)
#define PCIE_PHY_TRSV_REG02F_LN0_RX_CTLE_HIGH_BW_EN_G1_SHIFT (3U)
/*! LN0_RX_CTLE_HIGH_BW_EN_G1 - [GEN1] RX CTLE bandwidth enhancement by boosting up current */
#define PCIE_PHY_TRSV_REG02F_LN0_RX_CTLE_HIGH_BW_EN_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG02F_LN0_RX_CTLE_HIGH_BW_EN_G1_SHIFT)) & PCIE_PHY_TRSV_REG02F_LN0_RX_CTLE_HIGH_BW_EN_G1_MASK)
/*! @} */

/*! @name TRSV_REG030 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG030_LN0_RX_CTLE_ITAIL_CTRL_G1_MASK (0x7FU)
#define PCIE_PHY_TRSV_REG030_LN0_RX_CTLE_ITAIL_CTRL_G1_SHIFT (0U)
/*! LN0_RX_CTLE_ITAIL_CTRL_G1 - [GEN1] RX CTLE main tail current */
#define PCIE_PHY_TRSV_REG030_LN0_RX_CTLE_ITAIL_CTRL_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG030_LN0_RX_CTLE_ITAIL_CTRL_G1_SHIFT)) & PCIE_PHY_TRSV_REG030_LN0_RX_CTLE_ITAIL_CTRL_G1_MASK)
/*! @} */

/*! @name TRSV_REG031 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG031_LN0_RX_CTLE_ITAIL_CTRL_G2_MASK (0x7FU)
#define PCIE_PHY_TRSV_REG031_LN0_RX_CTLE_ITAIL_CTRL_G2_SHIFT (0U)
/*! LN0_RX_CTLE_ITAIL_CTRL_G2 - [GEN2] */
#define PCIE_PHY_TRSV_REG031_LN0_RX_CTLE_ITAIL_CTRL_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG031_LN0_RX_CTLE_ITAIL_CTRL_G2_SHIFT)) & PCIE_PHY_TRSV_REG031_LN0_RX_CTLE_ITAIL_CTRL_G2_MASK)
/*! @} */

/*! @name TRSV_REG032 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG032_LN0_RX_CTLE_ITAIL_CTRL_G3_MASK (0x7FU)
#define PCIE_PHY_TRSV_REG032_LN0_RX_CTLE_ITAIL_CTRL_G3_SHIFT (0U)
/*! LN0_RX_CTLE_ITAIL_CTRL_G3 - [GEN3] */
#define PCIE_PHY_TRSV_REG032_LN0_RX_CTLE_ITAIL_CTRL_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG032_LN0_RX_CTLE_ITAIL_CTRL_G3_SHIFT)) & PCIE_PHY_TRSV_REG032_LN0_RX_CTLE_ITAIL_CTRL_G3_MASK)
/*! @} */

/*! @name TRSV_REG033 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG033_LN0_RX_CTLE_ITAIL_CTRL_G4_MASK (0x7FU)
#define PCIE_PHY_TRSV_REG033_LN0_RX_CTLE_ITAIL_CTRL_G4_SHIFT (0U)
/*! LN0_RX_CTLE_ITAIL_CTRL_G4 - [GEN4] */
#define PCIE_PHY_TRSV_REG033_LN0_RX_CTLE_ITAIL_CTRL_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG033_LN0_RX_CTLE_ITAIL_CTRL_G4_SHIFT)) & PCIE_PHY_TRSV_REG033_LN0_RX_CTLE_ITAIL_CTRL_G4_MASK)
/*! @} */

/*! @name TRSV_REG034 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG034_LN0_RX_CTLE_OC_CODE_MASK (0x7FU)
#define PCIE_PHY_TRSV_REG034_LN0_RX_CTLE_OC_CODE_SHIFT (0U)
/*! LN0_RX_CTLE_OC_CODE - RX CTLE manual offset code */
#define PCIE_PHY_TRSV_REG034_LN0_RX_CTLE_OC_CODE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG034_LN0_RX_CTLE_OC_CODE_SHIFT)) & PCIE_PHY_TRSV_REG034_LN0_RX_CTLE_OC_CODE_MASK)

#define PCIE_PHY_TRSV_REG034_LN0_OVRD_RX_CTLE_OC_CODE_MASK (0x80U)
#define PCIE_PHY_TRSV_REG034_LN0_OVRD_RX_CTLE_OC_CODE_SHIFT (7U)
/*! LN0_OVRD_RX_CTLE_OC_CODE - Override enable for rx_ctle_oc_code */
#define PCIE_PHY_TRSV_REG034_LN0_OVRD_RX_CTLE_OC_CODE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG034_LN0_OVRD_RX_CTLE_OC_CODE_SHIFT)) & PCIE_PHY_TRSV_REG034_LN0_OVRD_RX_CTLE_OC_CODE_MASK)
/*! @} */

/*! @name TRSV_REG035 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG035_LN0_RX_CTLE_OC_EN_MASK (0x1U)
#define PCIE_PHY_TRSV_REG035_LN0_RX_CTLE_OC_EN_SHIFT (0U)
/*! LN0_RX_CTLE_OC_EN - RX CTLE offset calibration enable */
#define PCIE_PHY_TRSV_REG035_LN0_RX_CTLE_OC_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG035_LN0_RX_CTLE_OC_EN_SHIFT)) & PCIE_PHY_TRSV_REG035_LN0_RX_CTLE_OC_EN_MASK)

#define PCIE_PHY_TRSV_REG035_LN0_OVRD_RX_CTLE_OC_EN_MASK (0x2U)
#define PCIE_PHY_TRSV_REG035_LN0_OVRD_RX_CTLE_OC_EN_SHIFT (1U)
/*! LN0_OVRD_RX_CTLE_OC_EN - Override enable for rx_ctle_oc_en */
#define PCIE_PHY_TRSV_REG035_LN0_OVRD_RX_CTLE_OC_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG035_LN0_OVRD_RX_CTLE_OC_EN_SHIFT)) & PCIE_PHY_TRSV_REG035_LN0_OVRD_RX_CTLE_OC_EN_MASK)
/*! @} */

/*! @name TRSV_REG036 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG036_LN0_RX_CTLE_OC_VCM_SEL_G4_MASK (0x1U)
#define PCIE_PHY_TRSV_REG036_LN0_RX_CTLE_OC_VCM_SEL_G4_SHIFT (0U)
/*! LN0_RX_CTLE_OC_VCM_SEL_G4 - [GEN4] */
#define PCIE_PHY_TRSV_REG036_LN0_RX_CTLE_OC_VCM_SEL_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG036_LN0_RX_CTLE_OC_VCM_SEL_G4_SHIFT)) & PCIE_PHY_TRSV_REG036_LN0_RX_CTLE_OC_VCM_SEL_G4_MASK)

#define PCIE_PHY_TRSV_REG036_LN0_RX_CTLE_OC_VCM_SEL_G3_MASK (0x2U)
#define PCIE_PHY_TRSV_REG036_LN0_RX_CTLE_OC_VCM_SEL_G3_SHIFT (1U)
/*! LN0_RX_CTLE_OC_VCM_SEL_G3 - [GEN3] */
#define PCIE_PHY_TRSV_REG036_LN0_RX_CTLE_OC_VCM_SEL_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG036_LN0_RX_CTLE_OC_VCM_SEL_G3_SHIFT)) & PCIE_PHY_TRSV_REG036_LN0_RX_CTLE_OC_VCM_SEL_G3_MASK)

#define PCIE_PHY_TRSV_REG036_LN0_RX_CTLE_OC_VCM_SEL_G2_MASK (0x4U)
#define PCIE_PHY_TRSV_REG036_LN0_RX_CTLE_OC_VCM_SEL_G2_SHIFT (2U)
/*! LN0_RX_CTLE_OC_VCM_SEL_G2 - [GEN2] */
#define PCIE_PHY_TRSV_REG036_LN0_RX_CTLE_OC_VCM_SEL_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG036_LN0_RX_CTLE_OC_VCM_SEL_G2_SHIFT)) & PCIE_PHY_TRSV_REG036_LN0_RX_CTLE_OC_VCM_SEL_G2_MASK)

#define PCIE_PHY_TRSV_REG036_LN0_RX_CTLE_OC_VCM_SEL_G1_MASK (0x8U)
#define PCIE_PHY_TRSV_REG036_LN0_RX_CTLE_OC_VCM_SEL_G1_SHIFT (3U)
/*! LN0_RX_CTLE_OC_VCM_SEL_G1 - [GEN1] RX CTLE input common-mode selection in offset calibration */
#define PCIE_PHY_TRSV_REG036_LN0_RX_CTLE_OC_VCM_SEL_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG036_LN0_RX_CTLE_OC_VCM_SEL_G1_SHIFT)) & PCIE_PHY_TRSV_REG036_LN0_RX_CTLE_OC_VCM_SEL_G1_MASK)
/*! @} */

/*! @name TRSV_REG037 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG037_LN0_RX_CTLE_RL_CTRL_G1_MASK (0x1FU)
#define PCIE_PHY_TRSV_REG037_LN0_RX_CTLE_RL_CTRL_G1_SHIFT (0U)
/*! LN0_RX_CTLE_RL_CTRL_G1 - [GEN1] RX CTLE load resistance control for Gen1 */
#define PCIE_PHY_TRSV_REG037_LN0_RX_CTLE_RL_CTRL_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG037_LN0_RX_CTLE_RL_CTRL_G1_SHIFT)) & PCIE_PHY_TRSV_REG037_LN0_RX_CTLE_RL_CTRL_G1_MASK)
/*! @} */

/*! @name TRSV_REG038 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG038_LN0_RX_CTLE_RL_CTRL_G2_MASK (0x1FU)
#define PCIE_PHY_TRSV_REG038_LN0_RX_CTLE_RL_CTRL_G2_SHIFT (0U)
/*! LN0_RX_CTLE_RL_CTRL_G2 - [GEN2] */
#define PCIE_PHY_TRSV_REG038_LN0_RX_CTLE_RL_CTRL_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG038_LN0_RX_CTLE_RL_CTRL_G2_SHIFT)) & PCIE_PHY_TRSV_REG038_LN0_RX_CTLE_RL_CTRL_G2_MASK)
/*! @} */

/*! @name TRSV_REG039 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG039_LN0_RX_CTLE_RL_CTRL_G3_MASK (0x1FU)
#define PCIE_PHY_TRSV_REG039_LN0_RX_CTLE_RL_CTRL_G3_SHIFT (0U)
/*! LN0_RX_CTLE_RL_CTRL_G3 - [GEN3] */
#define PCIE_PHY_TRSV_REG039_LN0_RX_CTLE_RL_CTRL_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG039_LN0_RX_CTLE_RL_CTRL_G3_SHIFT)) & PCIE_PHY_TRSV_REG039_LN0_RX_CTLE_RL_CTRL_G3_MASK)
/*! @} */

/*! @name TRSV_REG03A -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG03A_LN0_RX_CTLE_RL_CTRL_G4_MASK (0x1FU)
#define PCIE_PHY_TRSV_REG03A_LN0_RX_CTLE_RL_CTRL_G4_SHIFT (0U)
/*! LN0_RX_CTLE_RL_CTRL_G4 - [GEN4] */
#define PCIE_PHY_TRSV_REG03A_LN0_RX_CTLE_RL_CTRL_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG03A_LN0_RX_CTLE_RL_CTRL_G4_SHIFT)) & PCIE_PHY_TRSV_REG03A_LN0_RX_CTLE_RL_CTRL_G4_MASK)
/*! @} */

/*! @name TRSV_REG03B -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG03B_LN0_RX_CTLE_RS1_CTRL_G1_MASK (0xFU)
#define PCIE_PHY_TRSV_REG03B_LN0_RX_CTLE_RS1_CTRL_G1_SHIFT (0U)
/*! LN0_RX_CTLE_RS1_CTRL_G1 - [GEN1] RX CTLE 1st stage source series resistance control */
#define PCIE_PHY_TRSV_REG03B_LN0_RX_CTLE_RS1_CTRL_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG03B_LN0_RX_CTLE_RS1_CTRL_G1_SHIFT)) & PCIE_PHY_TRSV_REG03B_LN0_RX_CTLE_RS1_CTRL_G1_MASK)

#define PCIE_PHY_TRSV_REG03B_LN0_OVRD_RX_CTLE_RS1_CTRL_MASK (0x10U)
#define PCIE_PHY_TRSV_REG03B_LN0_OVRD_RX_CTLE_RS1_CTRL_SHIFT (4U)
/*! LN0_OVRD_RX_CTLE_RS1_CTRL - Override enable for rx_ctle_rs1_ctrl_g1 */
#define PCIE_PHY_TRSV_REG03B_LN0_OVRD_RX_CTLE_RS1_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG03B_LN0_OVRD_RX_CTLE_RS1_CTRL_SHIFT)) & PCIE_PHY_TRSV_REG03B_LN0_OVRD_RX_CTLE_RS1_CTRL_MASK)
/*! @} */

/*! @name TRSV_REG03C -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG03C_LN0_RX_CTLE_RS1_CTRL_G3_MASK (0xFU)
#define PCIE_PHY_TRSV_REG03C_LN0_RX_CTLE_RS1_CTRL_G3_SHIFT (0U)
/*! LN0_RX_CTLE_RS1_CTRL_G3 - [GEN3] */
#define PCIE_PHY_TRSV_REG03C_LN0_RX_CTLE_RS1_CTRL_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG03C_LN0_RX_CTLE_RS1_CTRL_G3_SHIFT)) & PCIE_PHY_TRSV_REG03C_LN0_RX_CTLE_RS1_CTRL_G3_MASK)

#define PCIE_PHY_TRSV_REG03C_LN0_RX_CTLE_RS1_CTRL_G2_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG03C_LN0_RX_CTLE_RS1_CTRL_G2_SHIFT (4U)
/*! LN0_RX_CTLE_RS1_CTRL_G2 - [GEN2] */
#define PCIE_PHY_TRSV_REG03C_LN0_RX_CTLE_RS1_CTRL_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG03C_LN0_RX_CTLE_RS1_CTRL_G2_SHIFT)) & PCIE_PHY_TRSV_REG03C_LN0_RX_CTLE_RS1_CTRL_G2_MASK)
/*! @} */

/*! @name TRSV_REG03D -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG03D_LN0_RX_CTLE_RS1_CTRL_G4_MASK (0xFU)
#define PCIE_PHY_TRSV_REG03D_LN0_RX_CTLE_RS1_CTRL_G4_SHIFT (0U)
/*! LN0_RX_CTLE_RS1_CTRL_G4 - [GEN4] */
#define PCIE_PHY_TRSV_REG03D_LN0_RX_CTLE_RS1_CTRL_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG03D_LN0_RX_CTLE_RS1_CTRL_G4_SHIFT)) & PCIE_PHY_TRSV_REG03D_LN0_RX_CTLE_RS1_CTRL_G4_MASK)
/*! @} */

/*! @name TRSV_REG03E -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG03E_LN0_RX_CTLE_RS2_CTRL_G1_MASK (0xFU)
#define PCIE_PHY_TRSV_REG03E_LN0_RX_CTLE_RS2_CTRL_G1_SHIFT (0U)
/*! LN0_RX_CTLE_RS2_CTRL_G1 - [GEN1] RX CTLE 2nd stage source series resistance control */
#define PCIE_PHY_TRSV_REG03E_LN0_RX_CTLE_RS2_CTRL_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG03E_LN0_RX_CTLE_RS2_CTRL_G1_SHIFT)) & PCIE_PHY_TRSV_REG03E_LN0_RX_CTLE_RS2_CTRL_G1_MASK)

#define PCIE_PHY_TRSV_REG03E_LN0_OVRD_RX_CTLE_RS2_CTRL_MASK (0x10U)
#define PCIE_PHY_TRSV_REG03E_LN0_OVRD_RX_CTLE_RS2_CTRL_SHIFT (4U)
/*! LN0_OVRD_RX_CTLE_RS2_CTRL - Override enable for rx_ctle_rs2_ctrl_g1 */
#define PCIE_PHY_TRSV_REG03E_LN0_OVRD_RX_CTLE_RS2_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG03E_LN0_OVRD_RX_CTLE_RS2_CTRL_SHIFT)) & PCIE_PHY_TRSV_REG03E_LN0_OVRD_RX_CTLE_RS2_CTRL_MASK)
/*! @} */

/*! @name TRSV_REG03F -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG03F_LN0_RX_CTLE_RS2_CTRL_G3_MASK (0xFU)
#define PCIE_PHY_TRSV_REG03F_LN0_RX_CTLE_RS2_CTRL_G3_SHIFT (0U)
/*! LN0_RX_CTLE_RS2_CTRL_G3 - [GEN3] */
#define PCIE_PHY_TRSV_REG03F_LN0_RX_CTLE_RS2_CTRL_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG03F_LN0_RX_CTLE_RS2_CTRL_G3_SHIFT)) & PCIE_PHY_TRSV_REG03F_LN0_RX_CTLE_RS2_CTRL_G3_MASK)

#define PCIE_PHY_TRSV_REG03F_LN0_RX_CTLE_RS2_CTRL_G2_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG03F_LN0_RX_CTLE_RS2_CTRL_G2_SHIFT (4U)
/*! LN0_RX_CTLE_RS2_CTRL_G2 - [GEN2] */
#define PCIE_PHY_TRSV_REG03F_LN0_RX_CTLE_RS2_CTRL_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG03F_LN0_RX_CTLE_RS2_CTRL_G2_SHIFT)) & PCIE_PHY_TRSV_REG03F_LN0_RX_CTLE_RS2_CTRL_G2_MASK)
/*! @} */

/*! @name TRSV_REG040 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG040_LN0_RX_CTLE_RS2_CTRL_G4_MASK (0xFU)
#define PCIE_PHY_TRSV_REG040_LN0_RX_CTLE_RS2_CTRL_G4_SHIFT (0U)
/*! LN0_RX_CTLE_RS2_CTRL_G4 - [GEN4] */
#define PCIE_PHY_TRSV_REG040_LN0_RX_CTLE_RS2_CTRL_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG040_LN0_RX_CTLE_RS2_CTRL_G4_SHIFT)) & PCIE_PHY_TRSV_REG040_LN0_RX_CTLE_RS2_CTRL_G4_MASK)
/*! @} */

/*! @name TRSV_REG041 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG041_LN0_RX_CTLE_CHFB_EN_G4_MASK (0x1U)
#define PCIE_PHY_TRSV_REG041_LN0_RX_CTLE_CHFB_EN_G4_SHIFT (0U)
/*! LN0_RX_CTLE_CHFB_EN_G4 - [GEN4] */
#define PCIE_PHY_TRSV_REG041_LN0_RX_CTLE_CHFB_EN_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG041_LN0_RX_CTLE_CHFB_EN_G4_SHIFT)) & PCIE_PHY_TRSV_REG041_LN0_RX_CTLE_CHFB_EN_G4_MASK)

#define PCIE_PHY_TRSV_REG041_LN0_RX_CTLE_CHFB_EN_G3_MASK (0x2U)
#define PCIE_PHY_TRSV_REG041_LN0_RX_CTLE_CHFB_EN_G3_SHIFT (1U)
/*! LN0_RX_CTLE_CHFB_EN_G3 - [GEN3] */
#define PCIE_PHY_TRSV_REG041_LN0_RX_CTLE_CHFB_EN_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG041_LN0_RX_CTLE_CHFB_EN_G3_SHIFT)) & PCIE_PHY_TRSV_REG041_LN0_RX_CTLE_CHFB_EN_G3_MASK)

#define PCIE_PHY_TRSV_REG041_LN0_RX_CTLE_CHFB_EN_G2_MASK (0x4U)
#define PCIE_PHY_TRSV_REG041_LN0_RX_CTLE_CHFB_EN_G2_SHIFT (2U)
/*! LN0_RX_CTLE_CHFB_EN_G2 - [GEN2] */
#define PCIE_PHY_TRSV_REG041_LN0_RX_CTLE_CHFB_EN_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG041_LN0_RX_CTLE_CHFB_EN_G2_SHIFT)) & PCIE_PHY_TRSV_REG041_LN0_RX_CTLE_CHFB_EN_G2_MASK)

#define PCIE_PHY_TRSV_REG041_LN0_RX_CTLE_CHFB_EN_G1_MASK (0x8U)
#define PCIE_PHY_TRSV_REG041_LN0_RX_CTLE_CHFB_EN_G1_SHIFT (3U)
/*! LN0_RX_CTLE_CHFB_EN_G1 - [GEN1] RX CTLE Cherry-Hooper feedback amplifier enable */
#define PCIE_PHY_TRSV_REG041_LN0_RX_CTLE_CHFB_EN_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG041_LN0_RX_CTLE_CHFB_EN_G1_SHIFT)) & PCIE_PHY_TRSV_REG041_LN0_RX_CTLE_CHFB_EN_G1_MASK)
/*! @} */

/*! @name TRSV_REG042 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG042_LN0_RX_CTLE_CS_CTRL_G2_MASK (0xFU)
#define PCIE_PHY_TRSV_REG042_LN0_RX_CTLE_CS_CTRL_G2_SHIFT (0U)
/*! LN0_RX_CTLE_CS_CTRL_G2 - [GEN2] */
#define PCIE_PHY_TRSV_REG042_LN0_RX_CTLE_CS_CTRL_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG042_LN0_RX_CTLE_CS_CTRL_G2_SHIFT)) & PCIE_PHY_TRSV_REG042_LN0_RX_CTLE_CS_CTRL_G2_MASK)

#define PCIE_PHY_TRSV_REG042_LN0_RX_CTLE_CS_CTRL_G1_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG042_LN0_RX_CTLE_CS_CTRL_G1_SHIFT (4U)
/*! LN0_RX_CTLE_CS_CTRL_G1 - [GEN1] CTLE capacitance control. 4'h0=Gen4,3 4'h3=Gen2 4'h7=Gen1 */
#define PCIE_PHY_TRSV_REG042_LN0_RX_CTLE_CS_CTRL_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG042_LN0_RX_CTLE_CS_CTRL_G1_SHIFT)) & PCIE_PHY_TRSV_REG042_LN0_RX_CTLE_CS_CTRL_G1_MASK)
/*! @} */

/*! @name TRSV_REG043 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG043_LN0_RX_CTLE_CS_CTRL_G4_MASK (0xFU)
#define PCIE_PHY_TRSV_REG043_LN0_RX_CTLE_CS_CTRL_G4_SHIFT (0U)
/*! LN0_RX_CTLE_CS_CTRL_G4 - [GEN4] */
#define PCIE_PHY_TRSV_REG043_LN0_RX_CTLE_CS_CTRL_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG043_LN0_RX_CTLE_CS_CTRL_G4_SHIFT)) & PCIE_PHY_TRSV_REG043_LN0_RX_CTLE_CS_CTRL_G4_MASK)

#define PCIE_PHY_TRSV_REG043_LN0_RX_CTLE_CS_CTRL_G3_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG043_LN0_RX_CTLE_CS_CTRL_G3_SHIFT (4U)
/*! LN0_RX_CTLE_CS_CTRL_G3 - [GEN3] */
#define PCIE_PHY_TRSV_REG043_LN0_RX_CTLE_CS_CTRL_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG043_LN0_RX_CTLE_CS_CTRL_G3_SHIFT)) & PCIE_PHY_TRSV_REG043_LN0_RX_CTLE_CS_CTRL_G3_MASK)
/*! @} */

/*! @name TRSV_REG044 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG044_LN0_RX_CTLE_PEAKING_EN_G4_MASK (0x3U)
#define PCIE_PHY_TRSV_REG044_LN0_RX_CTLE_PEAKING_EN_G4_SHIFT (0U)
/*! LN0_RX_CTLE_PEAKING_EN_G4 - [GEN4] */
#define PCIE_PHY_TRSV_REG044_LN0_RX_CTLE_PEAKING_EN_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG044_LN0_RX_CTLE_PEAKING_EN_G4_SHIFT)) & PCIE_PHY_TRSV_REG044_LN0_RX_CTLE_PEAKING_EN_G4_MASK)

#define PCIE_PHY_TRSV_REG044_LN0_RX_CTLE_PEAKING_EN_G3_MASK (0xCU)
#define PCIE_PHY_TRSV_REG044_LN0_RX_CTLE_PEAKING_EN_G3_SHIFT (2U)
/*! LN0_RX_CTLE_PEAKING_EN_G3 - [GEN3] */
#define PCIE_PHY_TRSV_REG044_LN0_RX_CTLE_PEAKING_EN_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG044_LN0_RX_CTLE_PEAKING_EN_G3_SHIFT)) & PCIE_PHY_TRSV_REG044_LN0_RX_CTLE_PEAKING_EN_G3_MASK)

#define PCIE_PHY_TRSV_REG044_LN0_RX_CTLE_PEAKING_EN_G2_MASK (0x30U)
#define PCIE_PHY_TRSV_REG044_LN0_RX_CTLE_PEAKING_EN_G2_SHIFT (4U)
/*! LN0_RX_CTLE_PEAKING_EN_G2 - [GEN2] */
#define PCIE_PHY_TRSV_REG044_LN0_RX_CTLE_PEAKING_EN_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG044_LN0_RX_CTLE_PEAKING_EN_G2_SHIFT)) & PCIE_PHY_TRSV_REG044_LN0_RX_CTLE_PEAKING_EN_G2_MASK)

#define PCIE_PHY_TRSV_REG044_LN0_RX_CTLE_PEAKING_EN_G1_MASK (0xC0U)
#define PCIE_PHY_TRSV_REG044_LN0_RX_CTLE_PEAKING_EN_G1_SHIFT (6U)
/*! LN0_RX_CTLE_PEAKING_EN_G1 - [GEN1] RX CTLE stage enable for Gen1 */
#define PCIE_PHY_TRSV_REG044_LN0_RX_CTLE_PEAKING_EN_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG044_LN0_RX_CTLE_PEAKING_EN_G1_SHIFT)) & PCIE_PHY_TRSV_REG044_LN0_RX_CTLE_PEAKING_EN_G1_MASK)
/*! @} */

/*! @name TRSV_REG045 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG045_LN0_ANA_RX_CTLE_IBLEED_CTRL_MASK (0x7U)
#define PCIE_PHY_TRSV_REG045_LN0_ANA_RX_CTLE_IBLEED_CTRL_SHIFT (0U)
/*! LN0_ANA_RX_CTLE_IBLEED_CTRL - RX CTLE bleeder current control */
#define PCIE_PHY_TRSV_REG045_LN0_ANA_RX_CTLE_IBLEED_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG045_LN0_ANA_RX_CTLE_IBLEED_CTRL_SHIFT)) & PCIE_PHY_TRSV_REG045_LN0_ANA_RX_CTLE_IBLEED_CTRL_MASK)
/*! @} */

/*! @name TRSV_REG046 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG046_LN0_RX_CTLE_NEGC_EN_G2_MASK (0xFU)
#define PCIE_PHY_TRSV_REG046_LN0_RX_CTLE_NEGC_EN_G2_SHIFT (0U)
/*! LN0_RX_CTLE_NEGC_EN_G2 - [GEN2] */
#define PCIE_PHY_TRSV_REG046_LN0_RX_CTLE_NEGC_EN_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG046_LN0_RX_CTLE_NEGC_EN_G2_SHIFT)) & PCIE_PHY_TRSV_REG046_LN0_RX_CTLE_NEGC_EN_G2_MASK)

#define PCIE_PHY_TRSV_REG046_LN0_RX_CTLE_NEGC_EN_G1_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG046_LN0_RX_CTLE_NEGC_EN_G1_SHIFT (4U)
/*! LN0_RX_CTLE_NEGC_EN_G1 - [GEN1] RX CTLE negative-C enable */
#define PCIE_PHY_TRSV_REG046_LN0_RX_CTLE_NEGC_EN_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG046_LN0_RX_CTLE_NEGC_EN_G1_SHIFT)) & PCIE_PHY_TRSV_REG046_LN0_RX_CTLE_NEGC_EN_G1_MASK)
/*! @} */

/*! @name TRSV_REG047 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG047_LN0_RX_CTLE_NEGC_EN_G4_MASK (0xFU)
#define PCIE_PHY_TRSV_REG047_LN0_RX_CTLE_NEGC_EN_G4_SHIFT (0U)
/*! LN0_RX_CTLE_NEGC_EN_G4 - [GEN4] */
#define PCIE_PHY_TRSV_REG047_LN0_RX_CTLE_NEGC_EN_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG047_LN0_RX_CTLE_NEGC_EN_G4_SHIFT)) & PCIE_PHY_TRSV_REG047_LN0_RX_CTLE_NEGC_EN_G4_MASK)

#define PCIE_PHY_TRSV_REG047_LN0_RX_CTLE_NEGC_EN_G3_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG047_LN0_RX_CTLE_NEGC_EN_G3_SHIFT (4U)
/*! LN0_RX_CTLE_NEGC_EN_G3 - [GEN3] */
#define PCIE_PHY_TRSV_REG047_LN0_RX_CTLE_NEGC_EN_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG047_LN0_RX_CTLE_NEGC_EN_G3_SHIFT)) & PCIE_PHY_TRSV_REG047_LN0_RX_CTLE_NEGC_EN_G3_MASK)
/*! @} */

/*! @name TRSV_REG048 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG048_LN0_RX_CTLE_NEGC_ITAIL_CTRL_G2_MASK (0xFU)
#define PCIE_PHY_TRSV_REG048_LN0_RX_CTLE_NEGC_ITAIL_CTRL_G2_SHIFT (0U)
/*! LN0_RX_CTLE_NEGC_ITAIL_CTRL_G2 - [GEN2] */
#define PCIE_PHY_TRSV_REG048_LN0_RX_CTLE_NEGC_ITAIL_CTRL_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG048_LN0_RX_CTLE_NEGC_ITAIL_CTRL_G2_SHIFT)) & PCIE_PHY_TRSV_REG048_LN0_RX_CTLE_NEGC_ITAIL_CTRL_G2_MASK)

#define PCIE_PHY_TRSV_REG048_LN0_RX_CTLE_NEGC_ITAIL_CTRL_G1_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG048_LN0_RX_CTLE_NEGC_ITAIL_CTRL_G1_SHIFT (4U)
/*! LN0_RX_CTLE_NEGC_ITAIL_CTRL_G1 - [GEN1] RX CTLE negative-C tail current control */
#define PCIE_PHY_TRSV_REG048_LN0_RX_CTLE_NEGC_ITAIL_CTRL_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG048_LN0_RX_CTLE_NEGC_ITAIL_CTRL_G1_SHIFT)) & PCIE_PHY_TRSV_REG048_LN0_RX_CTLE_NEGC_ITAIL_CTRL_G1_MASK)
/*! @} */

/*! @name TRSV_REG049 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG049_LN0_RX_CTLE_NEGC_ITAIL_CTRL_G4_MASK (0xFU)
#define PCIE_PHY_TRSV_REG049_LN0_RX_CTLE_NEGC_ITAIL_CTRL_G4_SHIFT (0U)
/*! LN0_RX_CTLE_NEGC_ITAIL_CTRL_G4 - [GEN4] */
#define PCIE_PHY_TRSV_REG049_LN0_RX_CTLE_NEGC_ITAIL_CTRL_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG049_LN0_RX_CTLE_NEGC_ITAIL_CTRL_G4_SHIFT)) & PCIE_PHY_TRSV_REG049_LN0_RX_CTLE_NEGC_ITAIL_CTRL_G4_MASK)

#define PCIE_PHY_TRSV_REG049_LN0_RX_CTLE_NEGC_ITAIL_CTRL_G3_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG049_LN0_RX_CTLE_NEGC_ITAIL_CTRL_G3_SHIFT (4U)
/*! LN0_RX_CTLE_NEGC_ITAIL_CTRL_G3 - [GEN3] */
#define PCIE_PHY_TRSV_REG049_LN0_RX_CTLE_NEGC_ITAIL_CTRL_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG049_LN0_RX_CTLE_NEGC_ITAIL_CTRL_G3_SHIFT)) & PCIE_PHY_TRSV_REG049_LN0_RX_CTLE_NEGC_ITAIL_CTRL_G3_MASK)
/*! @} */

/*! @name TRSV_REG04A -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG04A_LN0_ANA_RX_CTLE_VCM_SEL_MASK (0x3U)
#define PCIE_PHY_TRSV_REG04A_LN0_ANA_RX_CTLE_VCM_SEL_SHIFT (0U)
/*! LN0_ANA_RX_CTLE_VCM_SEL - RX AFE (CTLE output) common-mode voltage selection */
#define PCIE_PHY_TRSV_REG04A_LN0_ANA_RX_CTLE_VCM_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG04A_LN0_ANA_RX_CTLE_VCM_SEL_SHIFT)) & PCIE_PHY_TRSV_REG04A_LN0_ANA_RX_CTLE_VCM_SEL_MASK)
/*! @} */

/*! @name TRSV_REG04B -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG04B_LN0_RX_CTLE_CHFB_BW_CTRL_G4_MASK (0x3U)
#define PCIE_PHY_TRSV_REG04B_LN0_RX_CTLE_CHFB_BW_CTRL_G4_SHIFT (0U)
/*! LN0_RX_CTLE_CHFB_BW_CTRL_G4 - [GEN4] */
#define PCIE_PHY_TRSV_REG04B_LN0_RX_CTLE_CHFB_BW_CTRL_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG04B_LN0_RX_CTLE_CHFB_BW_CTRL_G4_SHIFT)) & PCIE_PHY_TRSV_REG04B_LN0_RX_CTLE_CHFB_BW_CTRL_G4_MASK)

#define PCIE_PHY_TRSV_REG04B_LN0_RX_CTLE_CHFB_BW_CTRL_G3_MASK (0xCU)
#define PCIE_PHY_TRSV_REG04B_LN0_RX_CTLE_CHFB_BW_CTRL_G3_SHIFT (2U)
/*! LN0_RX_CTLE_CHFB_BW_CTRL_G3 - [GEN3] */
#define PCIE_PHY_TRSV_REG04B_LN0_RX_CTLE_CHFB_BW_CTRL_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG04B_LN0_RX_CTLE_CHFB_BW_CTRL_G3_SHIFT)) & PCIE_PHY_TRSV_REG04B_LN0_RX_CTLE_CHFB_BW_CTRL_G3_MASK)

#define PCIE_PHY_TRSV_REG04B_LN0_RX_CTLE_CHFB_BW_CTRL_G2_MASK (0x30U)
#define PCIE_PHY_TRSV_REG04B_LN0_RX_CTLE_CHFB_BW_CTRL_G2_SHIFT (4U)
/*! LN0_RX_CTLE_CHFB_BW_CTRL_G2 - [GEN2] */
#define PCIE_PHY_TRSV_REG04B_LN0_RX_CTLE_CHFB_BW_CTRL_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG04B_LN0_RX_CTLE_CHFB_BW_CTRL_G2_SHIFT)) & PCIE_PHY_TRSV_REG04B_LN0_RX_CTLE_CHFB_BW_CTRL_G2_MASK)

#define PCIE_PHY_TRSV_REG04B_LN0_RX_CTLE_CHFB_BW_CTRL_G1_MASK (0xC0U)
#define PCIE_PHY_TRSV_REG04B_LN0_RX_CTLE_CHFB_BW_CTRL_G1_SHIFT (6U)
/*! LN0_RX_CTLE_CHFB_BW_CTRL_G1 - [GEN1] RX CTLE Cherry-Hooper feedback amplifier bandwidth control */
#define PCIE_PHY_TRSV_REG04B_LN0_RX_CTLE_CHFB_BW_CTRL_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG04B_LN0_RX_CTLE_CHFB_BW_CTRL_G1_SHIFT)) & PCIE_PHY_TRSV_REG04B_LN0_RX_CTLE_CHFB_BW_CTRL_G1_MASK)
/*! @} */

/*! @name TRSV_REG04C -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG04C_LN0_RX_CTLE_CHFB_GAIN_CTRL_G2_MASK (0x7U)
#define PCIE_PHY_TRSV_REG04C_LN0_RX_CTLE_CHFB_GAIN_CTRL_G2_SHIFT (0U)
/*! LN0_RX_CTLE_CHFB_GAIN_CTRL_G2 - [GEN2] */
#define PCIE_PHY_TRSV_REG04C_LN0_RX_CTLE_CHFB_GAIN_CTRL_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG04C_LN0_RX_CTLE_CHFB_GAIN_CTRL_G2_SHIFT)) & PCIE_PHY_TRSV_REG04C_LN0_RX_CTLE_CHFB_GAIN_CTRL_G2_MASK)

#define PCIE_PHY_TRSV_REG04C_LN0_RX_CTLE_CHFB_GAIN_CTRL_G1_MASK (0x38U)
#define PCIE_PHY_TRSV_REG04C_LN0_RX_CTLE_CHFB_GAIN_CTRL_G1_SHIFT (3U)
/*! LN0_RX_CTLE_CHFB_GAIN_CTRL_G1 - [GEN1] RX CTLE Cherry-Hooper feedback amplifier gain control */
#define PCIE_PHY_TRSV_REG04C_LN0_RX_CTLE_CHFB_GAIN_CTRL_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG04C_LN0_RX_CTLE_CHFB_GAIN_CTRL_G1_SHIFT)) & PCIE_PHY_TRSV_REG04C_LN0_RX_CTLE_CHFB_GAIN_CTRL_G1_MASK)
/*! @} */

/*! @name TRSV_REG04D -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG04D_LN0_RX_CTLE_CHFB_GAIN_CTRL_G4_MASK (0x7U)
#define PCIE_PHY_TRSV_REG04D_LN0_RX_CTLE_CHFB_GAIN_CTRL_G4_SHIFT (0U)
/*! LN0_RX_CTLE_CHFB_GAIN_CTRL_G4 - [GEN4] */
#define PCIE_PHY_TRSV_REG04D_LN0_RX_CTLE_CHFB_GAIN_CTRL_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG04D_LN0_RX_CTLE_CHFB_GAIN_CTRL_G4_SHIFT)) & PCIE_PHY_TRSV_REG04D_LN0_RX_CTLE_CHFB_GAIN_CTRL_G4_MASK)

#define PCIE_PHY_TRSV_REG04D_LN0_RX_CTLE_CHFB_GAIN_CTRL_G3_MASK (0x38U)
#define PCIE_PHY_TRSV_REG04D_LN0_RX_CTLE_CHFB_GAIN_CTRL_G3_SHIFT (3U)
/*! LN0_RX_CTLE_CHFB_GAIN_CTRL_G3 - [GEN3] */
#define PCIE_PHY_TRSV_REG04D_LN0_RX_CTLE_CHFB_GAIN_CTRL_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG04D_LN0_RX_CTLE_CHFB_GAIN_CTRL_G3_SHIFT)) & PCIE_PHY_TRSV_REG04D_LN0_RX_CTLE_CHFB_GAIN_CTRL_G3_MASK)
/*! @} */

/*! @name TRSV_REG04E -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG04E_LN0_RX_CTLE_ACTIVE_LOAD_CTRL_G4_MASK (0x3U)
#define PCIE_PHY_TRSV_REG04E_LN0_RX_CTLE_ACTIVE_LOAD_CTRL_G4_SHIFT (0U)
/*! LN0_RX_CTLE_ACTIVE_LOAD_CTRL_G4 - [GEN4] */
#define PCIE_PHY_TRSV_REG04E_LN0_RX_CTLE_ACTIVE_LOAD_CTRL_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG04E_LN0_RX_CTLE_ACTIVE_LOAD_CTRL_G4_SHIFT)) & PCIE_PHY_TRSV_REG04E_LN0_RX_CTLE_ACTIVE_LOAD_CTRL_G4_MASK)

#define PCIE_PHY_TRSV_REG04E_LN0_RX_CTLE_ACTIVE_LOAD_CTRL_G3_MASK (0xCU)
#define PCIE_PHY_TRSV_REG04E_LN0_RX_CTLE_ACTIVE_LOAD_CTRL_G3_SHIFT (2U)
/*! LN0_RX_CTLE_ACTIVE_LOAD_CTRL_G3 - [GEN3] */
#define PCIE_PHY_TRSV_REG04E_LN0_RX_CTLE_ACTIVE_LOAD_CTRL_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG04E_LN0_RX_CTLE_ACTIVE_LOAD_CTRL_G3_SHIFT)) & PCIE_PHY_TRSV_REG04E_LN0_RX_CTLE_ACTIVE_LOAD_CTRL_G3_MASK)

#define PCIE_PHY_TRSV_REG04E_LN0_RX_CTLE_ACTIVE_LOAD_CTRL_G2_MASK (0x30U)
#define PCIE_PHY_TRSV_REG04E_LN0_RX_CTLE_ACTIVE_LOAD_CTRL_G2_SHIFT (4U)
/*! LN0_RX_CTLE_ACTIVE_LOAD_CTRL_G2 - [GEN2] */
#define PCIE_PHY_TRSV_REG04E_LN0_RX_CTLE_ACTIVE_LOAD_CTRL_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG04E_LN0_RX_CTLE_ACTIVE_LOAD_CTRL_G2_SHIFT)) & PCIE_PHY_TRSV_REG04E_LN0_RX_CTLE_ACTIVE_LOAD_CTRL_G2_MASK)

#define PCIE_PHY_TRSV_REG04E_LN0_RX_CTLE_ACTIVE_LOAD_CTRL_G1_MASK (0xC0U)
#define PCIE_PHY_TRSV_REG04E_LN0_RX_CTLE_ACTIVE_LOAD_CTRL_G1_SHIFT (6U)
/*! LN0_RX_CTLE_ACTIVE_LOAD_CTRL_G1 - [GEN1] RX CTLE active load control */
#define PCIE_PHY_TRSV_REG04E_LN0_RX_CTLE_ACTIVE_LOAD_CTRL_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG04E_LN0_RX_CTLE_ACTIVE_LOAD_CTRL_G1_SHIFT)) & PCIE_PHY_TRSV_REG04E_LN0_RX_CTLE_ACTIVE_LOAD_CTRL_G1_MASK)
/*! @} */

/*! @name TRSV_REG04F -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG04F_LN0_ANA_RX_CTLE_PTAT_EN_MASK (0x1U)
#define PCIE_PHY_TRSV_REG04F_LN0_ANA_RX_CTLE_PTAT_EN_SHIFT (0U)
/*! LN0_ANA_RX_CTLE_PTAT_EN - RX CTLE PTAT current enable */
#define PCIE_PHY_TRSV_REG04F_LN0_ANA_RX_CTLE_PTAT_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG04F_LN0_ANA_RX_CTLE_PTAT_EN_SHIFT)) & PCIE_PHY_TRSV_REG04F_LN0_ANA_RX_CTLE_PTAT_EN_MASK)

#define PCIE_PHY_TRSV_REG04F_LN0_ANA_RX_CTLE_VREG_SEL_MASK (0x1EU)
#define PCIE_PHY_TRSV_REG04F_LN0_ANA_RX_CTLE_VREG_SEL_SHIFT (1U)
/*! LN0_ANA_RX_CTLE_VREG_SEL - RX CTLE voltage regulator output voltage */
#define PCIE_PHY_TRSV_REG04F_LN0_ANA_RX_CTLE_VREG_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG04F_LN0_ANA_RX_CTLE_VREG_SEL_SHIFT)) & PCIE_PHY_TRSV_REG04F_LN0_ANA_RX_CTLE_VREG_SEL_MASK)

#define PCIE_PHY_TRSV_REG04F_LN0_ANA_RX_CTLE_VGA_CTRL_MASK (0xE0U)
#define PCIE_PHY_TRSV_REG04F_LN0_ANA_RX_CTLE_VGA_CTRL_SHIFT (5U)
/*! LN0_ANA_RX_CTLE_VGA_CTRL - RX CTLE stage3 gain control */
#define PCIE_PHY_TRSV_REG04F_LN0_ANA_RX_CTLE_VGA_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG04F_LN0_ANA_RX_CTLE_VGA_CTRL_SHIFT)) & PCIE_PHY_TRSV_REG04F_LN0_ANA_RX_CTLE_VGA_CTRL_MASK)
/*! @} */

/*! @name TRSV_REG050 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG050_LN0_RX_DES_DATA_CLEAR_MASK (0x1U)
#define PCIE_PHY_TRSV_REG050_LN0_RX_DES_DATA_CLEAR_SHIFT (0U)
/*! LN0_RX_DES_DATA_CLEAR - RX deserializer data clear to prevent garbage data */
#define PCIE_PHY_TRSV_REG050_LN0_RX_DES_DATA_CLEAR(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG050_LN0_RX_DES_DATA_CLEAR_SHIFT)) & PCIE_PHY_TRSV_REG050_LN0_RX_DES_DATA_CLEAR_MASK)

#define PCIE_PHY_TRSV_REG050_LN0_OVRD_RX_DES_DATA_CLEAR_MASK (0x2U)
#define PCIE_PHY_TRSV_REG050_LN0_OVRD_RX_DES_DATA_CLEAR_SHIFT (1U)
/*! LN0_OVRD_RX_DES_DATA_CLEAR - Override enable for rx_des_data_clear */
#define PCIE_PHY_TRSV_REG050_LN0_OVRD_RX_DES_DATA_CLEAR(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG050_LN0_OVRD_RX_DES_DATA_CLEAR_SHIFT)) & PCIE_PHY_TRSV_REG050_LN0_OVRD_RX_DES_DATA_CLEAR_MASK)

#define PCIE_PHY_TRSV_REG050_LN0_ANA_RX_CTLE_RESERVED_MASK (0x1CU)
#define PCIE_PHY_TRSV_REG050_LN0_ANA_RX_CTLE_RESERVED_SHIFT (2U)
/*! LN0_ANA_RX_CTLE_RESERVED - Reserved port */
#define PCIE_PHY_TRSV_REG050_LN0_ANA_RX_CTLE_RESERVED(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG050_LN0_ANA_RX_CTLE_RESERVED_SHIFT)) & PCIE_PHY_TRSV_REG050_LN0_ANA_RX_CTLE_RESERVED_MASK)
/*! @} */

/*! @name TRSV_REG051 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG051_LN0_RX_DES_DATA_WIDTH_SEL_G4_MASK (0x3U)
#define PCIE_PHY_TRSV_REG051_LN0_RX_DES_DATA_WIDTH_SEL_G4_SHIFT (0U)
/*! LN0_RX_DES_DATA_WIDTH_SEL_G4 - [GEN4] */
#define PCIE_PHY_TRSV_REG051_LN0_RX_DES_DATA_WIDTH_SEL_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG051_LN0_RX_DES_DATA_WIDTH_SEL_G4_SHIFT)) & PCIE_PHY_TRSV_REG051_LN0_RX_DES_DATA_WIDTH_SEL_G4_MASK)

#define PCIE_PHY_TRSV_REG051_LN0_RX_DES_DATA_WIDTH_SEL_G3_MASK (0xCU)
#define PCIE_PHY_TRSV_REG051_LN0_RX_DES_DATA_WIDTH_SEL_G3_SHIFT (2U)
/*! LN0_RX_DES_DATA_WIDTH_SEL_G3 - [GEN3] */
#define PCIE_PHY_TRSV_REG051_LN0_RX_DES_DATA_WIDTH_SEL_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG051_LN0_RX_DES_DATA_WIDTH_SEL_G3_SHIFT)) & PCIE_PHY_TRSV_REG051_LN0_RX_DES_DATA_WIDTH_SEL_G3_MASK)

#define PCIE_PHY_TRSV_REG051_LN0_RX_DES_DATA_WIDTH_SEL_G2_MASK (0x30U)
#define PCIE_PHY_TRSV_REG051_LN0_RX_DES_DATA_WIDTH_SEL_G2_SHIFT (4U)
/*! LN0_RX_DES_DATA_WIDTH_SEL_G2 - [GEN2] */
#define PCIE_PHY_TRSV_REG051_LN0_RX_DES_DATA_WIDTH_SEL_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG051_LN0_RX_DES_DATA_WIDTH_SEL_G2_SHIFT)) & PCIE_PHY_TRSV_REG051_LN0_RX_DES_DATA_WIDTH_SEL_G2_MASK)

#define PCIE_PHY_TRSV_REG051_LN0_RX_DES_DATA_WIDTH_SEL_G1_MASK (0xC0U)
#define PCIE_PHY_TRSV_REG051_LN0_RX_DES_DATA_WIDTH_SEL_G1_SHIFT (6U)
/*! LN0_RX_DES_DATA_WIDTH_SEL_G1 - [GEN1] RX deserializer data width selection */
#define PCIE_PHY_TRSV_REG051_LN0_RX_DES_DATA_WIDTH_SEL_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG051_LN0_RX_DES_DATA_WIDTH_SEL_G1_SHIFT)) & PCIE_PHY_TRSV_REG051_LN0_RX_DES_DATA_WIDTH_SEL_G1_MASK)
/*! @} */

/*! @name TRSV_REG052 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG052_LN0_ANA_RX_DES_DATA_CLEAR_DELAY_SEL_MASK (0x3U)
#define PCIE_PHY_TRSV_REG052_LN0_ANA_RX_DES_DATA_CLEAR_DELAY_SEL_SHIFT (0U)
#define PCIE_PHY_TRSV_REG052_LN0_ANA_RX_DES_DATA_CLEAR_DELAY_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG052_LN0_ANA_RX_DES_DATA_CLEAR_DELAY_SEL_SHIFT)) & PCIE_PHY_TRSV_REG052_LN0_ANA_RX_DES_DATA_CLEAR_DELAY_SEL_MASK)

#define PCIE_PHY_TRSV_REG052_LN0_RX_DES_RSTN_MASK (0x4U)
#define PCIE_PHY_TRSV_REG052_LN0_RX_DES_RSTN_SHIFT (2U)
/*! LN0_RX_DES_RSTN - RX deserializer reset */
#define PCIE_PHY_TRSV_REG052_LN0_RX_DES_RSTN(x)  (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG052_LN0_RX_DES_RSTN_SHIFT)) & PCIE_PHY_TRSV_REG052_LN0_RX_DES_RSTN_MASK)

#define PCIE_PHY_TRSV_REG052_LN0_OVRD_RX_DES_RSTN_MASK (0x8U)
#define PCIE_PHY_TRSV_REG052_LN0_OVRD_RX_DES_RSTN_SHIFT (3U)
/*! LN0_OVRD_RX_DES_RSTN - Override enable for rx_des_rstn */
#define PCIE_PHY_TRSV_REG052_LN0_OVRD_RX_DES_RSTN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG052_LN0_OVRD_RX_DES_RSTN_SHIFT)) & PCIE_PHY_TRSV_REG052_LN0_OVRD_RX_DES_RSTN_MASK)

#define PCIE_PHY_TRSV_REG052_LN0_RX_DES_NON_DATA_SEL_MASK (0x10U)
#define PCIE_PHY_TRSV_REG052_LN0_RX_DES_NON_DATA_SEL_SHIFT (4U)
/*! LN0_RX_DES_NON_DATA_SEL - RX deserializer non-data selection for edge/error sampler calibration */
#define PCIE_PHY_TRSV_REG052_LN0_RX_DES_NON_DATA_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG052_LN0_RX_DES_NON_DATA_SEL_SHIFT)) & PCIE_PHY_TRSV_REG052_LN0_RX_DES_NON_DATA_SEL_MASK)

#define PCIE_PHY_TRSV_REG052_LN0_OVRD_RX_DES_NON_DATA_SEL_MASK (0x20U)
#define PCIE_PHY_TRSV_REG052_LN0_OVRD_RX_DES_NON_DATA_SEL_SHIFT (5U)
/*! LN0_OVRD_RX_DES_NON_DATA_SEL - Override enable for rx_des_non_data_sel */
#define PCIE_PHY_TRSV_REG052_LN0_OVRD_RX_DES_NON_DATA_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG052_LN0_OVRD_RX_DES_NON_DATA_SEL_SHIFT)) & PCIE_PHY_TRSV_REG052_LN0_OVRD_RX_DES_NON_DATA_SEL_MASK)

#define PCIE_PHY_TRSV_REG052_LN0_RX_DES_EN_MASK  (0x40U)
#define PCIE_PHY_TRSV_REG052_LN0_RX_DES_EN_SHIFT (6U)
/*! LN0_RX_DES_EN - RX deserializer enable */
#define PCIE_PHY_TRSV_REG052_LN0_RX_DES_EN(x)    (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG052_LN0_RX_DES_EN_SHIFT)) & PCIE_PHY_TRSV_REG052_LN0_RX_DES_EN_MASK)

#define PCIE_PHY_TRSV_REG052_LN0_OVRD_RX_DES_EN_MASK (0x80U)
#define PCIE_PHY_TRSV_REG052_LN0_OVRD_RX_DES_EN_SHIFT (7U)
/*! LN0_OVRD_RX_DES_EN - Override enable for rx_des_en */
#define PCIE_PHY_TRSV_REG052_LN0_OVRD_RX_DES_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG052_LN0_OVRD_RX_DES_EN_SHIFT)) & PCIE_PHY_TRSV_REG052_LN0_OVRD_RX_DES_EN_MASK)
/*! @} */

/*! @name TRSV_REG053 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG053_LN0_ANA_RX_DFE_EOM_PI_DIV_SEL_MASK (0x7U)
#define PCIE_PHY_TRSV_REG053_LN0_ANA_RX_DFE_EOM_PI_DIV_SEL_SHIFT (0U)
/*! LN0_ANA_RX_DFE_EOM_PI_DIV_SEL - Clock divider control before RX EOM phase interpolator */
#define PCIE_PHY_TRSV_REG053_LN0_ANA_RX_DFE_EOM_PI_DIV_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG053_LN0_ANA_RX_DFE_EOM_PI_DIV_SEL_SHIFT)) & PCIE_PHY_TRSV_REG053_LN0_ANA_RX_DFE_EOM_PI_DIV_SEL_MASK)

#define PCIE_PHY_TRSV_REG053_LN0_RX_DFE_EOM_EN_MASK (0x8U)
#define PCIE_PHY_TRSV_REG053_LN0_RX_DFE_EOM_EN_SHIFT (3U)
/*! LN0_RX_DFE_EOM_EN - RX EOM enable */
#define PCIE_PHY_TRSV_REG053_LN0_RX_DFE_EOM_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG053_LN0_RX_DFE_EOM_EN_SHIFT)) & PCIE_PHY_TRSV_REG053_LN0_RX_DFE_EOM_EN_MASK)

#define PCIE_PHY_TRSV_REG053_LN0_OVRD_RX_DFE_EOM_EN_MASK (0x10U)
#define PCIE_PHY_TRSV_REG053_LN0_OVRD_RX_DFE_EOM_EN_SHIFT (4U)
/*! LN0_OVRD_RX_DFE_EOM_EN - Override enable for rx_dfe_eom_en */
#define PCIE_PHY_TRSV_REG053_LN0_OVRD_RX_DFE_EOM_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG053_LN0_OVRD_RX_DFE_EOM_EN_SHIFT)) & PCIE_PHY_TRSV_REG053_LN0_OVRD_RX_DFE_EOM_EN_MASK)

#define PCIE_PHY_TRSV_REG053_LN0_RX_DFE_ADAP_EN_MASK (0x20U)
#define PCIE_PHY_TRSV_REG053_LN0_RX_DFE_ADAP_EN_SHIFT (5U)
/*! LN0_RX_DFE_ADAP_EN - RX DFE adaptation path enable. Only one of i_rx_dfe_adap_en and i_rx_eom_en should be "1". */
#define PCIE_PHY_TRSV_REG053_LN0_RX_DFE_ADAP_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG053_LN0_RX_DFE_ADAP_EN_SHIFT)) & PCIE_PHY_TRSV_REG053_LN0_RX_DFE_ADAP_EN_MASK)

#define PCIE_PHY_TRSV_REG053_LN0_OVRD_RX_DFE_ADAP_EN_MASK (0x40U)
#define PCIE_PHY_TRSV_REG053_LN0_OVRD_RX_DFE_ADAP_EN_SHIFT (6U)
/*! LN0_OVRD_RX_DFE_ADAP_EN - Override enable for rx_dfe_adap_en */
#define PCIE_PHY_TRSV_REG053_LN0_OVRD_RX_DFE_ADAP_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG053_LN0_OVRD_RX_DFE_ADAP_EN_SHIFT)) & PCIE_PHY_TRSV_REG053_LN0_OVRD_RX_DFE_ADAP_EN_MASK)
/*! @} */

/*! @name TRSV_REG054 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG054_LN0_ANA_RX_DFE_EOM_PI_STR_CTRL_MASK (0xFU)
#define PCIE_PHY_TRSV_REG054_LN0_ANA_RX_DFE_EOM_PI_STR_CTRL_SHIFT (0U)
/*! LN0_ANA_RX_DFE_EOM_PI_STR_CTRL - RX EOM PI drive strengh in pre-buffer stage */
#define PCIE_PHY_TRSV_REG054_LN0_ANA_RX_DFE_EOM_PI_STR_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG054_LN0_ANA_RX_DFE_EOM_PI_STR_CTRL_SHIFT)) & PCIE_PHY_TRSV_REG054_LN0_ANA_RX_DFE_EOM_PI_STR_CTRL_MASK)
/*! @} */

/*! @name TRSV_REG055 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG055_LN0_RX_DFE_OC_ADDER_EVEN_CODE_MASK (0x7FU)
#define PCIE_PHY_TRSV_REG055_LN0_RX_DFE_OC_ADDER_EVEN_CODE_SHIFT (0U)
/*! LN0_RX_DFE_OC_ADDER_EVEN_CODE - RX DFE even data path offset calibration code */
#define PCIE_PHY_TRSV_REG055_LN0_RX_DFE_OC_ADDER_EVEN_CODE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG055_LN0_RX_DFE_OC_ADDER_EVEN_CODE_SHIFT)) & PCIE_PHY_TRSV_REG055_LN0_RX_DFE_OC_ADDER_EVEN_CODE_MASK)

#define PCIE_PHY_TRSV_REG055_LN0_OVRD_RX_DFE_OC_ADDER_EVEN_CODE_MASK (0x80U)
#define PCIE_PHY_TRSV_REG055_LN0_OVRD_RX_DFE_OC_ADDER_EVEN_CODE_SHIFT (7U)
/*! LN0_OVRD_RX_DFE_OC_ADDER_EVEN_CODE - Override enable for rx_dfe_oc_adder_even_code */
#define PCIE_PHY_TRSV_REG055_LN0_OVRD_RX_DFE_OC_ADDER_EVEN_CODE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG055_LN0_OVRD_RX_DFE_OC_ADDER_EVEN_CODE_SHIFT)) & PCIE_PHY_TRSV_REG055_LN0_OVRD_RX_DFE_OC_ADDER_EVEN_CODE_MASK)
/*! @} */

/*! @name TRSV_REG056 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG056_LN0_RX_DFE_OC_ADDER_ODD_CODE_MASK (0x7FU)
#define PCIE_PHY_TRSV_REG056_LN0_RX_DFE_OC_ADDER_ODD_CODE_SHIFT (0U)
/*! LN0_RX_DFE_OC_ADDER_ODD_CODE - RX DFE odd data path offset calibration code */
#define PCIE_PHY_TRSV_REG056_LN0_RX_DFE_OC_ADDER_ODD_CODE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG056_LN0_RX_DFE_OC_ADDER_ODD_CODE_SHIFT)) & PCIE_PHY_TRSV_REG056_LN0_RX_DFE_OC_ADDER_ODD_CODE_MASK)

#define PCIE_PHY_TRSV_REG056_LN0_OVRD_RX_DFE_OC_ADDER_ODD_CODE_MASK (0x80U)
#define PCIE_PHY_TRSV_REG056_LN0_OVRD_RX_DFE_OC_ADDER_ODD_CODE_SHIFT (7U)
/*! LN0_OVRD_RX_DFE_OC_ADDER_ODD_CODE - Override enable for rx_dfe_oc_adder_odd_code */
#define PCIE_PHY_TRSV_REG056_LN0_OVRD_RX_DFE_OC_ADDER_ODD_CODE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG056_LN0_OVRD_RX_DFE_OC_ADDER_ODD_CODE_SHIFT)) & PCIE_PHY_TRSV_REG056_LN0_OVRD_RX_DFE_OC_ADDER_ODD_CODE_MASK)
/*! @} */

/*! @name TRSV_REG057 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG057_LN0_RX_DFE_OC_DAC_EDGE_EVEN_CODE_MASK (0x7U)
#define PCIE_PHY_TRSV_REG057_LN0_RX_DFE_OC_DAC_EDGE_EVEN_CODE_SHIFT (0U)
/*! LN0_RX_DFE_OC_DAC_EDGE_EVEN_CODE - Fine control of zero-crossing in RX DFE DAC for even edge path offset calibration */
#define PCIE_PHY_TRSV_REG057_LN0_RX_DFE_OC_DAC_EDGE_EVEN_CODE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG057_LN0_RX_DFE_OC_DAC_EDGE_EVEN_CODE_SHIFT)) & PCIE_PHY_TRSV_REG057_LN0_RX_DFE_OC_DAC_EDGE_EVEN_CODE_MASK)

#define PCIE_PHY_TRSV_REG057_LN0_OVRD_RX_DFE_OC_DAC_EDGE_EVEN_CODE_MASK (0x8U)
#define PCIE_PHY_TRSV_REG057_LN0_OVRD_RX_DFE_OC_DAC_EDGE_EVEN_CODE_SHIFT (3U)
/*! LN0_OVRD_RX_DFE_OC_DAC_EDGE_EVEN_CODE - Override enable for rx_dfe_oc_dac_edge_even_code */
#define PCIE_PHY_TRSV_REG057_LN0_OVRD_RX_DFE_OC_DAC_EDGE_EVEN_CODE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG057_LN0_OVRD_RX_DFE_OC_DAC_EDGE_EVEN_CODE_SHIFT)) & PCIE_PHY_TRSV_REG057_LN0_OVRD_RX_DFE_OC_DAC_EDGE_EVEN_CODE_MASK)

#define PCIE_PHY_TRSV_REG057_LN0_RX_DFE_OC_DAC_ADDER_ODD_CODE_MASK (0x10U)
#define PCIE_PHY_TRSV_REG057_LN0_RX_DFE_OC_DAC_ADDER_ODD_CODE_SHIFT (4U)
/*! LN0_RX_DFE_OC_DAC_ADDER_ODD_CODE - Fine control of zero-crossing in RX DFE DAC for odd adder offset calibration */
#define PCIE_PHY_TRSV_REG057_LN0_RX_DFE_OC_DAC_ADDER_ODD_CODE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG057_LN0_RX_DFE_OC_DAC_ADDER_ODD_CODE_SHIFT)) & PCIE_PHY_TRSV_REG057_LN0_RX_DFE_OC_DAC_ADDER_ODD_CODE_MASK)

#define PCIE_PHY_TRSV_REG057_LN0_OVRD_RX_DFE_OC_DAC_ADDER_ODD_CODE_MASK (0x20U)
#define PCIE_PHY_TRSV_REG057_LN0_OVRD_RX_DFE_OC_DAC_ADDER_ODD_CODE_SHIFT (5U)
/*! LN0_OVRD_RX_DFE_OC_DAC_ADDER_ODD_CODE - Override enable for rx_dfe_oc_dac_adder_odd_code */
#define PCIE_PHY_TRSV_REG057_LN0_OVRD_RX_DFE_OC_DAC_ADDER_ODD_CODE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG057_LN0_OVRD_RX_DFE_OC_DAC_ADDER_ODD_CODE_SHIFT)) & PCIE_PHY_TRSV_REG057_LN0_OVRD_RX_DFE_OC_DAC_ADDER_ODD_CODE_MASK)

#define PCIE_PHY_TRSV_REG057_LN0_RX_DFE_OC_DAC_ADDER_EVEN_CODE_MASK (0x40U)
#define PCIE_PHY_TRSV_REG057_LN0_RX_DFE_OC_DAC_ADDER_EVEN_CODE_SHIFT (6U)
/*! LN0_RX_DFE_OC_DAC_ADDER_EVEN_CODE - Fine control of zero-crossing in RX DFE DAC for even adder offset calibration */
#define PCIE_PHY_TRSV_REG057_LN0_RX_DFE_OC_DAC_ADDER_EVEN_CODE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG057_LN0_RX_DFE_OC_DAC_ADDER_EVEN_CODE_SHIFT)) & PCIE_PHY_TRSV_REG057_LN0_RX_DFE_OC_DAC_ADDER_EVEN_CODE_MASK)

#define PCIE_PHY_TRSV_REG057_LN0_OVRD_RX_DFE_OC_DAC_ADDER_EVEN_CODE_MASK (0x80U)
#define PCIE_PHY_TRSV_REG057_LN0_OVRD_RX_DFE_OC_DAC_ADDER_EVEN_CODE_SHIFT (7U)
/*! LN0_OVRD_RX_DFE_OC_DAC_ADDER_EVEN_CODE - Override enable for rx_dfe_oc_dac_adder_even_code */
#define PCIE_PHY_TRSV_REG057_LN0_OVRD_RX_DFE_OC_DAC_ADDER_EVEN_CODE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG057_LN0_OVRD_RX_DFE_OC_DAC_ADDER_EVEN_CODE_SHIFT)) & PCIE_PHY_TRSV_REG057_LN0_OVRD_RX_DFE_OC_DAC_ADDER_EVEN_CODE_MASK)
/*! @} */

/*! @name TRSV_REG058 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG058_LN0_RX_DFE_OC_DAC_ERR_EVEN_CODE_MASK (0x7U)
#define PCIE_PHY_TRSV_REG058_LN0_RX_DFE_OC_DAC_ERR_EVEN_CODE_SHIFT (0U)
/*! LN0_RX_DFE_OC_DAC_ERR_EVEN_CODE - Fine control of zero-crossing in RX DFE DAC for even error path offset calibration */
#define PCIE_PHY_TRSV_REG058_LN0_RX_DFE_OC_DAC_ERR_EVEN_CODE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG058_LN0_RX_DFE_OC_DAC_ERR_EVEN_CODE_SHIFT)) & PCIE_PHY_TRSV_REG058_LN0_RX_DFE_OC_DAC_ERR_EVEN_CODE_MASK)

#define PCIE_PHY_TRSV_REG058_LN0_OVRD_RX_DFE_OC_DAC_ERR_EVEN_CODE_MASK (0x8U)
#define PCIE_PHY_TRSV_REG058_LN0_OVRD_RX_DFE_OC_DAC_ERR_EVEN_CODE_SHIFT (3U)
/*! LN0_OVRD_RX_DFE_OC_DAC_ERR_EVEN_CODE - Override enable for rx_dfe_oc_dac_err_even_code */
#define PCIE_PHY_TRSV_REG058_LN0_OVRD_RX_DFE_OC_DAC_ERR_EVEN_CODE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG058_LN0_OVRD_RX_DFE_OC_DAC_ERR_EVEN_CODE_SHIFT)) & PCIE_PHY_TRSV_REG058_LN0_OVRD_RX_DFE_OC_DAC_ERR_EVEN_CODE_MASK)

#define PCIE_PHY_TRSV_REG058_LN0_RX_DFE_OC_DAC_EDGE_ODD_CODE_MASK (0x70U)
#define PCIE_PHY_TRSV_REG058_LN0_RX_DFE_OC_DAC_EDGE_ODD_CODE_SHIFT (4U)
/*! LN0_RX_DFE_OC_DAC_EDGE_ODD_CODE - Fine control of zero-crossing in RX DFE DAC for odd edge path offset calibration */
#define PCIE_PHY_TRSV_REG058_LN0_RX_DFE_OC_DAC_EDGE_ODD_CODE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG058_LN0_RX_DFE_OC_DAC_EDGE_ODD_CODE_SHIFT)) & PCIE_PHY_TRSV_REG058_LN0_RX_DFE_OC_DAC_EDGE_ODD_CODE_MASK)

#define PCIE_PHY_TRSV_REG058_LN0_OVRD_RX_DFE_OC_DAC_EDGE_ODD_CODE_MASK (0x80U)
#define PCIE_PHY_TRSV_REG058_LN0_OVRD_RX_DFE_OC_DAC_EDGE_ODD_CODE_SHIFT (7U)
/*! LN0_OVRD_RX_DFE_OC_DAC_EDGE_ODD_CODE - Override enable for rx_dfe_oc_dac_edge_odd_code */
#define PCIE_PHY_TRSV_REG058_LN0_OVRD_RX_DFE_OC_DAC_EDGE_ODD_CODE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG058_LN0_OVRD_RX_DFE_OC_DAC_EDGE_ODD_CODE_SHIFT)) & PCIE_PHY_TRSV_REG058_LN0_OVRD_RX_DFE_OC_DAC_EDGE_ODD_CODE_MASK)
/*! @} */

/*! @name TRSV_REG059 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG059_LN0_RX_DFE_OC_EN_MASK (0x1U)
#define PCIE_PHY_TRSV_REG059_LN0_RX_DFE_OC_EN_SHIFT (0U)
/*! LN0_RX_DFE_OC_EN - RX DFE offset calibration progress enable */
#define PCIE_PHY_TRSV_REG059_LN0_RX_DFE_OC_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG059_LN0_RX_DFE_OC_EN_SHIFT)) & PCIE_PHY_TRSV_REG059_LN0_RX_DFE_OC_EN_MASK)

#define PCIE_PHY_TRSV_REG059_LN0_OVRD_RX_DFE_OC_EN_MASK (0x2U)
#define PCIE_PHY_TRSV_REG059_LN0_OVRD_RX_DFE_OC_EN_SHIFT (1U)
/*! LN0_OVRD_RX_DFE_OC_EN - Override enable for rx_dfe_oc_en */
#define PCIE_PHY_TRSV_REG059_LN0_OVRD_RX_DFE_OC_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG059_LN0_OVRD_RX_DFE_OC_EN_SHIFT)) & PCIE_PHY_TRSV_REG059_LN0_OVRD_RX_DFE_OC_EN_MASK)

#define PCIE_PHY_TRSV_REG059_LN0_RX_DFE_OC_DAC_ERR_ODD_CODE_MASK (0x1CU)
#define PCIE_PHY_TRSV_REG059_LN0_RX_DFE_OC_DAC_ERR_ODD_CODE_SHIFT (2U)
/*! LN0_RX_DFE_OC_DAC_ERR_ODD_CODE - Fine control of zero-crossing in RX DFE DAC for odd error path offset calibration */
#define PCIE_PHY_TRSV_REG059_LN0_RX_DFE_OC_DAC_ERR_ODD_CODE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG059_LN0_RX_DFE_OC_DAC_ERR_ODD_CODE_SHIFT)) & PCIE_PHY_TRSV_REG059_LN0_RX_DFE_OC_DAC_ERR_ODD_CODE_MASK)

#define PCIE_PHY_TRSV_REG059_LN0_OVRD_RX_DFE_OC_DAC_ERR_ODD_CODE_MASK (0x20U)
#define PCIE_PHY_TRSV_REG059_LN0_OVRD_RX_DFE_OC_DAC_ERR_ODD_CODE_SHIFT (5U)
/*! LN0_OVRD_RX_DFE_OC_DAC_ERR_ODD_CODE - Override enable for rx_dfe_oc_dac_err_odd_code */
#define PCIE_PHY_TRSV_REG059_LN0_OVRD_RX_DFE_OC_DAC_ERR_ODD_CODE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG059_LN0_OVRD_RX_DFE_OC_DAC_ERR_ODD_CODE_SHIFT)) & PCIE_PHY_TRSV_REG059_LN0_OVRD_RX_DFE_OC_DAC_ERR_ODD_CODE_MASK)
/*! @} */

/*! @name TRSV_REG05A -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG05A_LN0_RX_DFE_OC_SA_EDGE_EVEN_CODE__8_MASK (0x1U)
#define PCIE_PHY_TRSV_REG05A_LN0_RX_DFE_OC_SA_EDGE_EVEN_CODE__8_SHIFT (0U)
/*! LN0_RX_DFE_OC_SA_EDGE_EVEN_CODE__8 - RX DFE even edge path offset calibration code */
#define PCIE_PHY_TRSV_REG05A_LN0_RX_DFE_OC_SA_EDGE_EVEN_CODE__8(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG05A_LN0_RX_DFE_OC_SA_EDGE_EVEN_CODE__8_SHIFT)) & PCIE_PHY_TRSV_REG05A_LN0_RX_DFE_OC_SA_EDGE_EVEN_CODE__8_MASK)

#define PCIE_PHY_TRSV_REG05A_LN0_OVRD_RX_DFE_OC_SA_EDGE_EVEN_CODE_MASK (0x2U)
#define PCIE_PHY_TRSV_REG05A_LN0_OVRD_RX_DFE_OC_SA_EDGE_EVEN_CODE_SHIFT (1U)
/*! LN0_OVRD_RX_DFE_OC_SA_EDGE_EVEN_CODE - Override enable for rx_dfe_oc_sa_edge_even_code */
#define PCIE_PHY_TRSV_REG05A_LN0_OVRD_RX_DFE_OC_SA_EDGE_EVEN_CODE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG05A_LN0_OVRD_RX_DFE_OC_SA_EDGE_EVEN_CODE_SHIFT)) & PCIE_PHY_TRSV_REG05A_LN0_OVRD_RX_DFE_OC_SA_EDGE_EVEN_CODE_MASK)
/*! @} */

/*! @name TRSV_REG05B -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG05B_LN0_RX_DFE_OC_SA_EDGE_EVEN_CODE__7_0_MASK (0xFFU)
#define PCIE_PHY_TRSV_REG05B_LN0_RX_DFE_OC_SA_EDGE_EVEN_CODE__7_0_SHIFT (0U)
/*! LN0_RX_DFE_OC_SA_EDGE_EVEN_CODE__7_0 - RX DFE even edge path offset calibration code */
#define PCIE_PHY_TRSV_REG05B_LN0_RX_DFE_OC_SA_EDGE_EVEN_CODE__7_0(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG05B_LN0_RX_DFE_OC_SA_EDGE_EVEN_CODE__7_0_SHIFT)) & PCIE_PHY_TRSV_REG05B_LN0_RX_DFE_OC_SA_EDGE_EVEN_CODE__7_0_MASK)
/*! @} */

/*! @name TRSV_REG05C -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG05C_LN0_RX_DFE_OC_SA_EDGE_ODD_CODE__8_MASK (0x1U)
#define PCIE_PHY_TRSV_REG05C_LN0_RX_DFE_OC_SA_EDGE_ODD_CODE__8_SHIFT (0U)
/*! LN0_RX_DFE_OC_SA_EDGE_ODD_CODE__8 - RX DFE odd edge path offset calibration code */
#define PCIE_PHY_TRSV_REG05C_LN0_RX_DFE_OC_SA_EDGE_ODD_CODE__8(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG05C_LN0_RX_DFE_OC_SA_EDGE_ODD_CODE__8_SHIFT)) & PCIE_PHY_TRSV_REG05C_LN0_RX_DFE_OC_SA_EDGE_ODD_CODE__8_MASK)

#define PCIE_PHY_TRSV_REG05C_LN0_OVRD_RX_DFE_OC_SA_EDGE_ODD_CODE_MASK (0x2U)
#define PCIE_PHY_TRSV_REG05C_LN0_OVRD_RX_DFE_OC_SA_EDGE_ODD_CODE_SHIFT (1U)
/*! LN0_OVRD_RX_DFE_OC_SA_EDGE_ODD_CODE - Override enable for rx_dfe_oc_sa_edge_odd_code */
#define PCIE_PHY_TRSV_REG05C_LN0_OVRD_RX_DFE_OC_SA_EDGE_ODD_CODE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG05C_LN0_OVRD_RX_DFE_OC_SA_EDGE_ODD_CODE_SHIFT)) & PCIE_PHY_TRSV_REG05C_LN0_OVRD_RX_DFE_OC_SA_EDGE_ODD_CODE_MASK)
/*! @} */

/*! @name TRSV_REG05D -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG05D_LN0_RX_DFE_OC_SA_EDGE_ODD_CODE__7_0_MASK (0xFFU)
#define PCIE_PHY_TRSV_REG05D_LN0_RX_DFE_OC_SA_EDGE_ODD_CODE__7_0_SHIFT (0U)
/*! LN0_RX_DFE_OC_SA_EDGE_ODD_CODE__7_0 - RX DFE odd edge path offset calibration code */
#define PCIE_PHY_TRSV_REG05D_LN0_RX_DFE_OC_SA_EDGE_ODD_CODE__7_0(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG05D_LN0_RX_DFE_OC_SA_EDGE_ODD_CODE__7_0_SHIFT)) & PCIE_PHY_TRSV_REG05D_LN0_RX_DFE_OC_SA_EDGE_ODD_CODE__7_0_MASK)
/*! @} */

/*! @name TRSV_REG05E -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG05E_LN0_RX_DFE_OC_SA_ERR_EVEN_CODE__8_MASK (0x1U)
#define PCIE_PHY_TRSV_REG05E_LN0_RX_DFE_OC_SA_ERR_EVEN_CODE__8_SHIFT (0U)
/*! LN0_RX_DFE_OC_SA_ERR_EVEN_CODE__8 - RX DFE even error path offset calibration code */
#define PCIE_PHY_TRSV_REG05E_LN0_RX_DFE_OC_SA_ERR_EVEN_CODE__8(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG05E_LN0_RX_DFE_OC_SA_ERR_EVEN_CODE__8_SHIFT)) & PCIE_PHY_TRSV_REG05E_LN0_RX_DFE_OC_SA_ERR_EVEN_CODE__8_MASK)

#define PCIE_PHY_TRSV_REG05E_LN0_OVRD_RX_DFE_OC_SA_ERR_EVEN_CODE_MASK (0x2U)
#define PCIE_PHY_TRSV_REG05E_LN0_OVRD_RX_DFE_OC_SA_ERR_EVEN_CODE_SHIFT (1U)
/*! LN0_OVRD_RX_DFE_OC_SA_ERR_EVEN_CODE - Override enable for rx_dfe_oc_sa_err_even_code */
#define PCIE_PHY_TRSV_REG05E_LN0_OVRD_RX_DFE_OC_SA_ERR_EVEN_CODE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG05E_LN0_OVRD_RX_DFE_OC_SA_ERR_EVEN_CODE_SHIFT)) & PCIE_PHY_TRSV_REG05E_LN0_OVRD_RX_DFE_OC_SA_ERR_EVEN_CODE_MASK)
/*! @} */

/*! @name TRSV_REG05F -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG05F_LN0_RX_DFE_OC_SA_ERR_EVEN_CODE__7_0_MASK (0xFFU)
#define PCIE_PHY_TRSV_REG05F_LN0_RX_DFE_OC_SA_ERR_EVEN_CODE__7_0_SHIFT (0U)
/*! LN0_RX_DFE_OC_SA_ERR_EVEN_CODE__7_0 - RX DFE even error path offset calibration code */
#define PCIE_PHY_TRSV_REG05F_LN0_RX_DFE_OC_SA_ERR_EVEN_CODE__7_0(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG05F_LN0_RX_DFE_OC_SA_ERR_EVEN_CODE__7_0_SHIFT)) & PCIE_PHY_TRSV_REG05F_LN0_RX_DFE_OC_SA_ERR_EVEN_CODE__7_0_MASK)
/*! @} */

/*! @name TRSV_REG060 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG060_LN0_RX_DFE_OC_SA_ERR_ODD_CODE__8_MASK (0x1U)
#define PCIE_PHY_TRSV_REG060_LN0_RX_DFE_OC_SA_ERR_ODD_CODE__8_SHIFT (0U)
/*! LN0_RX_DFE_OC_SA_ERR_ODD_CODE__8 - RX DFE odd error path offset calibration code */
#define PCIE_PHY_TRSV_REG060_LN0_RX_DFE_OC_SA_ERR_ODD_CODE__8(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG060_LN0_RX_DFE_OC_SA_ERR_ODD_CODE__8_SHIFT)) & PCIE_PHY_TRSV_REG060_LN0_RX_DFE_OC_SA_ERR_ODD_CODE__8_MASK)

#define PCIE_PHY_TRSV_REG060_LN0_OVRD_RX_DFE_OC_SA_ERR_ODD_CODE_MASK (0x2U)
#define PCIE_PHY_TRSV_REG060_LN0_OVRD_RX_DFE_OC_SA_ERR_ODD_CODE_SHIFT (1U)
/*! LN0_OVRD_RX_DFE_OC_SA_ERR_ODD_CODE - Override enable for rx_dfe_oc_sa_err_odd_code */
#define PCIE_PHY_TRSV_REG060_LN0_OVRD_RX_DFE_OC_SA_ERR_ODD_CODE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG060_LN0_OVRD_RX_DFE_OC_SA_ERR_ODD_CODE_SHIFT)) & PCIE_PHY_TRSV_REG060_LN0_OVRD_RX_DFE_OC_SA_ERR_ODD_CODE_MASK)
/*! @} */

/*! @name TRSV_REG061 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG061_LN0_RX_DFE_OC_SA_ERR_ODD_CODE__7_0_MASK (0xFFU)
#define PCIE_PHY_TRSV_REG061_LN0_RX_DFE_OC_SA_ERR_ODD_CODE__7_0_SHIFT (0U)
/*! LN0_RX_DFE_OC_SA_ERR_ODD_CODE__7_0 - RX DFE odd error path offset calibration code */
#define PCIE_PHY_TRSV_REG061_LN0_RX_DFE_OC_SA_ERR_ODD_CODE__7_0(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG061_LN0_RX_DFE_OC_SA_ERR_ODD_CODE__7_0_SHIFT)) & PCIE_PHY_TRSV_REG061_LN0_RX_DFE_OC_SA_ERR_ODD_CODE__7_0_MASK)
/*! @} */

/*! @name TRSV_REG062 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG062_LN0_RX_DFE_SA_ERR_OC_EN_MASK (0x1U)
#define PCIE_PHY_TRSV_REG062_LN0_RX_DFE_SA_ERR_OC_EN_SHIFT (0U)
/*! LN0_RX_DFE_SA_ERR_OC_EN - RX DFE error path enable in offset calibration (If all of
 *    rx_dfe_sa_*_oc_en are 0, all path are autimatically activated as normal mode)
 */
#define PCIE_PHY_TRSV_REG062_LN0_RX_DFE_SA_ERR_OC_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG062_LN0_RX_DFE_SA_ERR_OC_EN_SHIFT)) & PCIE_PHY_TRSV_REG062_LN0_RX_DFE_SA_ERR_OC_EN_MASK)

#define PCIE_PHY_TRSV_REG062_LN0_OVRD_RX_DFE_SA_ERR_OC_EN_MASK (0x2U)
#define PCIE_PHY_TRSV_REG062_LN0_OVRD_RX_DFE_SA_ERR_OC_EN_SHIFT (1U)
/*! LN0_OVRD_RX_DFE_SA_ERR_OC_EN - Override enable for rx_dfe_sa_err_oc_en */
#define PCIE_PHY_TRSV_REG062_LN0_OVRD_RX_DFE_SA_ERR_OC_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG062_LN0_OVRD_RX_DFE_SA_ERR_OC_EN_SHIFT)) & PCIE_PHY_TRSV_REG062_LN0_OVRD_RX_DFE_SA_ERR_OC_EN_MASK)

#define PCIE_PHY_TRSV_REG062_LN0_RX_DFE_SA_EDGE_OC_EN_MASK (0x4U)
#define PCIE_PHY_TRSV_REG062_LN0_RX_DFE_SA_EDGE_OC_EN_SHIFT (2U)
/*! LN0_RX_DFE_SA_EDGE_OC_EN - RX DFE edge path enable in offset calibration (If all of
 *    rx_dfe_sa_*_oc_en are 0, all path are autimatically activated as normal mode)
 */
#define PCIE_PHY_TRSV_REG062_LN0_RX_DFE_SA_EDGE_OC_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG062_LN0_RX_DFE_SA_EDGE_OC_EN_SHIFT)) & PCIE_PHY_TRSV_REG062_LN0_RX_DFE_SA_EDGE_OC_EN_MASK)

#define PCIE_PHY_TRSV_REG062_LN0_OVRD_RX_DFE_SA_EDGE_OC_EN_MASK (0x8U)
#define PCIE_PHY_TRSV_REG062_LN0_OVRD_RX_DFE_SA_EDGE_OC_EN_SHIFT (3U)
/*! LN0_OVRD_RX_DFE_SA_EDGE_OC_EN - Override enable for rx_dfe_sa_edge_oc_en */
#define PCIE_PHY_TRSV_REG062_LN0_OVRD_RX_DFE_SA_EDGE_OC_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG062_LN0_OVRD_RX_DFE_SA_EDGE_OC_EN_SHIFT)) & PCIE_PHY_TRSV_REG062_LN0_OVRD_RX_DFE_SA_EDGE_OC_EN_MASK)

#define PCIE_PHY_TRSV_REG062_LN0_RX_DFE_SA_DATA_ODD_OC_EN_MASK (0x10U)
#define PCIE_PHY_TRSV_REG062_LN0_RX_DFE_SA_DATA_ODD_OC_EN_SHIFT (4U)
/*! LN0_RX_DFE_SA_DATA_ODD_OC_EN - RX DFE data even path enable in offset calibration (If all of
 *    rx_dfe_sa_*_oc_en are 0, all path are autimatically activated as normal mode)
 */
#define PCIE_PHY_TRSV_REG062_LN0_RX_DFE_SA_DATA_ODD_OC_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG062_LN0_RX_DFE_SA_DATA_ODD_OC_EN_SHIFT)) & PCIE_PHY_TRSV_REG062_LN0_RX_DFE_SA_DATA_ODD_OC_EN_MASK)

#define PCIE_PHY_TRSV_REG062_LN0_OVRD_RX_DFE_SA_DATA_ODD_OC_EN_MASK (0x20U)
#define PCIE_PHY_TRSV_REG062_LN0_OVRD_RX_DFE_SA_DATA_ODD_OC_EN_SHIFT (5U)
/*! LN0_OVRD_RX_DFE_SA_DATA_ODD_OC_EN - Override enable for rx_dfe_sa_data_odd_oc_en */
#define PCIE_PHY_TRSV_REG062_LN0_OVRD_RX_DFE_SA_DATA_ODD_OC_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG062_LN0_OVRD_RX_DFE_SA_DATA_ODD_OC_EN_SHIFT)) & PCIE_PHY_TRSV_REG062_LN0_OVRD_RX_DFE_SA_DATA_ODD_OC_EN_MASK)

#define PCIE_PHY_TRSV_REG062_LN0_RX_DFE_SA_DATA_EVEN_OC_EN_MASK (0x40U)
#define PCIE_PHY_TRSV_REG062_LN0_RX_DFE_SA_DATA_EVEN_OC_EN_SHIFT (6U)
/*! LN0_RX_DFE_SA_DATA_EVEN_OC_EN - RX DFE data odd path enable in offset calibration (If all of
 *    rx_dfe_sa_*_oc_en are 0, all path are autimatically activated as normal mode)
 */
#define PCIE_PHY_TRSV_REG062_LN0_RX_DFE_SA_DATA_EVEN_OC_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG062_LN0_RX_DFE_SA_DATA_EVEN_OC_EN_SHIFT)) & PCIE_PHY_TRSV_REG062_LN0_RX_DFE_SA_DATA_EVEN_OC_EN_MASK)

#define PCIE_PHY_TRSV_REG062_LN0_OVRD_RX_DFE_SA_DATA_EVEN_OC_EN_MASK (0x80U)
#define PCIE_PHY_TRSV_REG062_LN0_OVRD_RX_DFE_SA_DATA_EVEN_OC_EN_SHIFT (7U)
/*! LN0_OVRD_RX_DFE_SA_DATA_EVEN_OC_EN - Override enable for rx_dfe_sa_data_even_oc_en */
#define PCIE_PHY_TRSV_REG062_LN0_OVRD_RX_DFE_SA_DATA_EVEN_OC_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG062_LN0_OVRD_RX_DFE_SA_DATA_EVEN_OC_EN_SHIFT)) & PCIE_PHY_TRSV_REG062_LN0_OVRD_RX_DFE_SA_DATA_EVEN_OC_EN_MASK)
/*! @} */

/*! @name TRSV_REG063 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG063_LN0_RX_DFE_VREF_CTRL__8_MASK (0x1U)
#define PCIE_PHY_TRSV_REG063_LN0_RX_DFE_VREF_CTRL__8_SHIFT (0U)
/*! LN0_RX_DFE_VREF_CTRL__8 - RX DFE Vref control */
#define PCIE_PHY_TRSV_REG063_LN0_RX_DFE_VREF_CTRL__8(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG063_LN0_RX_DFE_VREF_CTRL__8_SHIFT)) & PCIE_PHY_TRSV_REG063_LN0_RX_DFE_VREF_CTRL__8_MASK)

#define PCIE_PHY_TRSV_REG063_LN0_OVRD_RX_DFE_VREF_CTRL_MASK (0x2U)
#define PCIE_PHY_TRSV_REG063_LN0_OVRD_RX_DFE_VREF_CTRL_SHIFT (1U)
/*! LN0_OVRD_RX_DFE_VREF_CTRL - Override enable for rx_dfe_vref_ctrl */
#define PCIE_PHY_TRSV_REG063_LN0_OVRD_RX_DFE_VREF_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG063_LN0_OVRD_RX_DFE_VREF_CTRL_SHIFT)) & PCIE_PHY_TRSV_REG063_LN0_OVRD_RX_DFE_VREF_CTRL_MASK)
/*! @} */

/*! @name TRSV_REG064 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG064_LN0_RX_DFE_VREF_CTRL__7_0_MASK (0xFFU)
#define PCIE_PHY_TRSV_REG064_LN0_RX_DFE_VREF_CTRL__7_0_SHIFT (0U)
/*! LN0_RX_DFE_VREF_CTRL__7_0 - RX DFE Vref control */
#define PCIE_PHY_TRSV_REG064_LN0_RX_DFE_VREF_CTRL__7_0(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG064_LN0_RX_DFE_VREF_CTRL__7_0_SHIFT)) & PCIE_PHY_TRSV_REG064_LN0_RX_DFE_VREF_CTRL__7_0_MASK)
/*! @} */

/*! @name TRSV_REG065 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG065_LN0_ANA_RX_DFE_VREG_SEL_MASK (0xFU)
#define PCIE_PHY_TRSV_REG065_LN0_ANA_RX_DFE_VREG_SEL_SHIFT (0U)
/*! LN0_ANA_RX_DFE_VREG_SEL - N/A, DFE bias current control [3:2]: DFE adder bias current, [1:0]: OC DAC bias current. */
#define PCIE_PHY_TRSV_REG065_LN0_ANA_RX_DFE_VREG_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG065_LN0_ANA_RX_DFE_VREG_SEL_SHIFT)) & PCIE_PHY_TRSV_REG065_LN0_ANA_RX_DFE_VREG_SEL_MASK)

#define PCIE_PHY_TRSV_REG065_LN0_ANA_RX_DFE_ADDER_BLEED_CTRL_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG065_LN0_ANA_RX_DFE_ADDER_BLEED_CTRL_SHIFT (4U)
#define PCIE_PHY_TRSV_REG065_LN0_ANA_RX_DFE_ADDER_BLEED_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG065_LN0_ANA_RX_DFE_ADDER_BLEED_CTRL_SHIFT)) & PCIE_PHY_TRSV_REG065_LN0_ANA_RX_DFE_ADDER_BLEED_CTRL_MASK)
/*! @} */

/*! @name TRSV_REG066 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG066_LN0_RX_RCAL_EN_MASK (0x1U)
#define PCIE_PHY_TRSV_REG066_LN0_RX_RCAL_EN_SHIFT (0U)
/*! LN0_RX_RCAL_EN - RX RCAL enable */
#define PCIE_PHY_TRSV_REG066_LN0_RX_RCAL_EN(x)   (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG066_LN0_RX_RCAL_EN_SHIFT)) & PCIE_PHY_TRSV_REG066_LN0_RX_RCAL_EN_MASK)

#define PCIE_PHY_TRSV_REG066_LN0_OVRD_RX_RCAL_EN_MASK (0x2U)
#define PCIE_PHY_TRSV_REG066_LN0_OVRD_RX_RCAL_EN_SHIFT (1U)
/*! LN0_OVRD_RX_RCAL_EN - Override enable for rx_rcal_en */
#define PCIE_PHY_TRSV_REG066_LN0_OVRD_RX_RCAL_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG066_LN0_OVRD_RX_RCAL_EN_SHIFT)) & PCIE_PHY_TRSV_REG066_LN0_OVRD_RX_RCAL_EN_MASK)

#define PCIE_PHY_TRSV_REG066_LN0_ANA_RX_DFE_EOM_CLK_SEL_MASK (0x4U)
#define PCIE_PHY_TRSV_REG066_LN0_ANA_RX_DFE_EOM_CLK_SEL_SHIFT (2U)
/*! LN0_ANA_RX_DFE_EOM_CLK_SEL - RX EOM clock selection */
#define PCIE_PHY_TRSV_REG066_LN0_ANA_RX_DFE_EOM_CLK_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG066_LN0_ANA_RX_DFE_EOM_CLK_SEL_SHIFT)) & PCIE_PHY_TRSV_REG066_LN0_ANA_RX_DFE_EOM_CLK_SEL_MASK)

#define PCIE_PHY_TRSV_REG066_LN0_ANA_RX_DFE_DAC_VCM_CTRL_MASK (0x38U)
#define PCIE_PHY_TRSV_REG066_LN0_ANA_RX_DFE_DAC_VCM_CTRL_SHIFT (3U)
#define PCIE_PHY_TRSV_REG066_LN0_ANA_RX_DFE_DAC_VCM_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG066_LN0_ANA_RX_DFE_DAC_VCM_CTRL_SHIFT)) & PCIE_PHY_TRSV_REG066_LN0_ANA_RX_DFE_DAC_VCM_CTRL_MASK)

#define PCIE_PHY_TRSV_REG066_LN0_ANA_RX_DFE_DAC_OUT_PULLUP_MASK (0x40U)
#define PCIE_PHY_TRSV_REG066_LN0_ANA_RX_DFE_DAC_OUT_PULLUP_SHIFT (6U)
/*! LN0_ANA_RX_DFE_DAC_OUT_PULLUP - Pull-up all DAC output in RX DFE to disable all offset code effect */
#define PCIE_PHY_TRSV_REG066_LN0_ANA_RX_DFE_DAC_OUT_PULLUP(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG066_LN0_ANA_RX_DFE_DAC_OUT_PULLUP_SHIFT)) & PCIE_PHY_TRSV_REG066_LN0_ANA_RX_DFE_DAC_OUT_PULLUP_MASK)
/*! @} */

/*! @name TRSV_REG067 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG067_LN0_RX_RTERM_EN_MASK (0x1U)
#define PCIE_PHY_TRSV_REG067_LN0_RX_RTERM_EN_SHIFT (0U)
/*! LN0_RX_RTERM_EN - RX RTERM enable */
#define PCIE_PHY_TRSV_REG067_LN0_RX_RTERM_EN(x)  (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG067_LN0_RX_RTERM_EN_SHIFT)) & PCIE_PHY_TRSV_REG067_LN0_RX_RTERM_EN_MASK)

#define PCIE_PHY_TRSV_REG067_LN0_OVRD_RX_RTERM_EN_MASK (0x2U)
#define PCIE_PHY_TRSV_REG067_LN0_OVRD_RX_RTERM_EN_SHIFT (1U)
/*! LN0_OVRD_RX_RTERM_EN - Override enable for rx_rterm_en */
#define PCIE_PHY_TRSV_REG067_LN0_OVRD_RX_RTERM_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG067_LN0_OVRD_RX_RTERM_EN_SHIFT)) & PCIE_PHY_TRSV_REG067_LN0_OVRD_RX_RTERM_EN_MASK)

#define PCIE_PHY_TRSV_REG067_LN0_ANA_RX_RCAL_IRMRES_CTRL_MASK (0xCU)
#define PCIE_PHY_TRSV_REG067_LN0_ANA_RX_RCAL_IRMRES_CTRL_SHIFT (2U)
#define PCIE_PHY_TRSV_REG067_LN0_ANA_RX_RCAL_IRMRES_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG067_LN0_ANA_RX_RCAL_IRMRES_CTRL_SHIFT)) & PCIE_PHY_TRSV_REG067_LN0_ANA_RX_RCAL_IRMRES_CTRL_MASK)

#define PCIE_PHY_TRSV_REG067_LN0_RX_RCAL_BIAS_EN_MASK (0x10U)
#define PCIE_PHY_TRSV_REG067_LN0_RX_RCAL_BIAS_EN_SHIFT (4U)
/*! LN0_RX_RCAL_BIAS_EN - RX RCAL bias current enable */
#define PCIE_PHY_TRSV_REG067_LN0_RX_RCAL_BIAS_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG067_LN0_RX_RCAL_BIAS_EN_SHIFT)) & PCIE_PHY_TRSV_REG067_LN0_RX_RCAL_BIAS_EN_MASK)

#define PCIE_PHY_TRSV_REG067_LN0_OVRD_RX_RCAL_BIAS_EN_MASK (0x20U)
#define PCIE_PHY_TRSV_REG067_LN0_OVRD_RX_RCAL_BIAS_EN_SHIFT (5U)
/*! LN0_OVRD_RX_RCAL_BIAS_EN - Override enable for rx_rcal_bias_en */
#define PCIE_PHY_TRSV_REG067_LN0_OVRD_RX_RCAL_BIAS_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG067_LN0_OVRD_RX_RCAL_BIAS_EN_SHIFT)) & PCIE_PHY_TRSV_REG067_LN0_OVRD_RX_RCAL_BIAS_EN_MASK)
/*! @} */

/*! @name TRSV_REG068 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG068_LN0_ANA_RX_RTERM_INCM_SW_CTRL_MASK (0x3U)
#define PCIE_PHY_TRSV_REG068_LN0_ANA_RX_RTERM_INCM_SW_CTRL_SHIFT (0U)
/*! LN0_ANA_RX_RTERM_INCM_SW_CTRL - RX RTERM single-ended impedance control by switch control */
#define PCIE_PHY_TRSV_REG068_LN0_ANA_RX_RTERM_INCM_SW_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG068_LN0_ANA_RX_RTERM_INCM_SW_CTRL_SHIFT)) & PCIE_PHY_TRSV_REG068_LN0_ANA_RX_RTERM_INCM_SW_CTRL_MASK)

#define PCIE_PHY_TRSV_REG068_LN0_ANA_RX_RTERM_INCM_ITAIL_CTRL_MASK (0xCU)
#define PCIE_PHY_TRSV_REG068_LN0_ANA_RX_RTERM_INCM_ITAIL_CTRL_SHIFT (2U)
/*! LN0_ANA_RX_RTERM_INCM_ITAIL_CTRL - RX RTERM single-ended impedance control by current control */
#define PCIE_PHY_TRSV_REG068_LN0_ANA_RX_RTERM_INCM_ITAIL_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG068_LN0_ANA_RX_RTERM_INCM_ITAIL_CTRL_SHIFT)) & PCIE_PHY_TRSV_REG068_LN0_ANA_RX_RTERM_INCM_ITAIL_CTRL_MASK)

#define PCIE_PHY_TRSV_REG068_LN0_RX_RTERM_42P5_EN_G4_MASK (0x10U)
#define PCIE_PHY_TRSV_REG068_LN0_RX_RTERM_42P5_EN_G4_SHIFT (4U)
/*! LN0_RX_RTERM_42P5_EN_G4 - [GEN4] */
#define PCIE_PHY_TRSV_REG068_LN0_RX_RTERM_42P5_EN_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG068_LN0_RX_RTERM_42P5_EN_G4_SHIFT)) & PCIE_PHY_TRSV_REG068_LN0_RX_RTERM_42P5_EN_G4_MASK)

#define PCIE_PHY_TRSV_REG068_LN0_RX_RTERM_42P5_EN_G3_MASK (0x20U)
#define PCIE_PHY_TRSV_REG068_LN0_RX_RTERM_42P5_EN_G3_SHIFT (5U)
/*! LN0_RX_RTERM_42P5_EN_G3 - [GEN3] */
#define PCIE_PHY_TRSV_REG068_LN0_RX_RTERM_42P5_EN_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG068_LN0_RX_RTERM_42P5_EN_G3_SHIFT)) & PCIE_PHY_TRSV_REG068_LN0_RX_RTERM_42P5_EN_G3_MASK)

#define PCIE_PHY_TRSV_REG068_LN0_RX_RTERM_42P5_EN_G2_MASK (0x40U)
#define PCIE_PHY_TRSV_REG068_LN0_RX_RTERM_42P5_EN_G2_SHIFT (6U)
/*! LN0_RX_RTERM_42P5_EN_G2 - [GEN2] */
#define PCIE_PHY_TRSV_REG068_LN0_RX_RTERM_42P5_EN_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG068_LN0_RX_RTERM_42P5_EN_G2_SHIFT)) & PCIE_PHY_TRSV_REG068_LN0_RX_RTERM_42P5_EN_G2_MASK)

#define PCIE_PHY_TRSV_REG068_LN0_RX_RTERM_42P5_EN_G1_MASK (0x80U)
#define PCIE_PHY_TRSV_REG068_LN0_RX_RTERM_42P5_EN_G1_SHIFT (7U)
/*! LN0_RX_RTERM_42P5_EN_G1 - [GEN1] RX RTERM resistance shift */
#define PCIE_PHY_TRSV_REG068_LN0_RX_RTERM_42P5_EN_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG068_LN0_RX_RTERM_42P5_EN_G1_SHIFT)) & PCIE_PHY_TRSV_REG068_LN0_RX_RTERM_42P5_EN_G1_MASK)
/*! @} */

/*! @name TRSV_REG069 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG069_LN0_ANA_RX_RTERM_OFSP_CTRL_MASK (0x1U)
#define PCIE_PHY_TRSV_REG069_LN0_ANA_RX_RTERM_OFSP_CTRL_SHIFT (0U)
/*! LN0_ANA_RX_RTERM_OFSP_CTRL - Offset code for RX RTERM P node */
#define PCIE_PHY_TRSV_REG069_LN0_ANA_RX_RTERM_OFSP_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG069_LN0_ANA_RX_RTERM_OFSP_CTRL_SHIFT)) & PCIE_PHY_TRSV_REG069_LN0_ANA_RX_RTERM_OFSP_CTRL_MASK)

#define PCIE_PHY_TRSV_REG069_LN0_ANA_RX_RTERM_OFSN_CTRL_MASK (0x2U)
#define PCIE_PHY_TRSV_REG069_LN0_ANA_RX_RTERM_OFSN_CTRL_SHIFT (1U)
/*! LN0_ANA_RX_RTERM_OFSN_CTRL - Offset code for RX RTERM N node */
#define PCIE_PHY_TRSV_REG069_LN0_ANA_RX_RTERM_OFSN_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG069_LN0_ANA_RX_RTERM_OFSN_CTRL_SHIFT)) & PCIE_PHY_TRSV_REG069_LN0_ANA_RX_RTERM_OFSN_CTRL_MASK)

#define PCIE_PHY_TRSV_REG069_LN0_ANA_RX_RTERM_INCM_VCM_CTRL_MASK (0xCU)
#define PCIE_PHY_TRSV_REG069_LN0_ANA_RX_RTERM_INCM_VCM_CTRL_SHIFT (2U)
/*! LN0_ANA_RX_RTERM_INCM_VCM_CTRL - RX RTERM output common-mode voltage control */
#define PCIE_PHY_TRSV_REG069_LN0_ANA_RX_RTERM_INCM_VCM_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG069_LN0_ANA_RX_RTERM_INCM_VCM_CTRL_SHIFT)) & PCIE_PHY_TRSV_REG069_LN0_ANA_RX_RTERM_INCM_VCM_CTRL_MASK)
/*! @} */

/*! @name TRSV_REG06A -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG06A_LN0_RX_RTERM_CM_PULLDN_G4_MASK (0x1U)
#define PCIE_PHY_TRSV_REG06A_LN0_RX_RTERM_CM_PULLDN_G4_SHIFT (0U)
/*! LN0_RX_RTERM_CM_PULLDN_G4 - [GEN4] */
#define PCIE_PHY_TRSV_REG06A_LN0_RX_RTERM_CM_PULLDN_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG06A_LN0_RX_RTERM_CM_PULLDN_G4_SHIFT)) & PCIE_PHY_TRSV_REG06A_LN0_RX_RTERM_CM_PULLDN_G4_MASK)

#define PCIE_PHY_TRSV_REG06A_LN0_RX_RTERM_CM_PULLDN_G3_MASK (0x2U)
#define PCIE_PHY_TRSV_REG06A_LN0_RX_RTERM_CM_PULLDN_G3_SHIFT (1U)
/*! LN0_RX_RTERM_CM_PULLDN_G3 - [GEN3] */
#define PCIE_PHY_TRSV_REG06A_LN0_RX_RTERM_CM_PULLDN_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG06A_LN0_RX_RTERM_CM_PULLDN_G3_SHIFT)) & PCIE_PHY_TRSV_REG06A_LN0_RX_RTERM_CM_PULLDN_G3_MASK)

#define PCIE_PHY_TRSV_REG06A_LN0_RX_RTERM_CM_PULLDN_G2_MASK (0x4U)
#define PCIE_PHY_TRSV_REG06A_LN0_RX_RTERM_CM_PULLDN_G2_SHIFT (2U)
/*! LN0_RX_RTERM_CM_PULLDN_G2 - [GEN2] */
#define PCIE_PHY_TRSV_REG06A_LN0_RX_RTERM_CM_PULLDN_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG06A_LN0_RX_RTERM_CM_PULLDN_G2_SHIFT)) & PCIE_PHY_TRSV_REG06A_LN0_RX_RTERM_CM_PULLDN_G2_MASK)

#define PCIE_PHY_TRSV_REG06A_LN0_RX_RTERM_CM_PULLDN_G1_MASK (0x8U)
#define PCIE_PHY_TRSV_REG06A_LN0_RX_RTERM_CM_PULLDN_G1_SHIFT (3U)
/*! LN0_RX_RTERM_CM_PULLDN_G1 - [GEN1] RX RTERM termination voltage pull-down */
#define PCIE_PHY_TRSV_REG06A_LN0_RX_RTERM_CM_PULLDN_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG06A_LN0_RX_RTERM_CM_PULLDN_G1_SHIFT)) & PCIE_PHY_TRSV_REG06A_LN0_RX_RTERM_CM_PULLDN_G1_MASK)

#define PCIE_PHY_TRSV_REG06A_LN0_OVRD_RX_RTERM_CM_PULLDN_MASK (0x10U)
#define PCIE_PHY_TRSV_REG06A_LN0_OVRD_RX_RTERM_CM_PULLDN_SHIFT (4U)
/*! LN0_OVRD_RX_RTERM_CM_PULLDN - Override enable for rx_rterm_cm_pulldn_g1 */
#define PCIE_PHY_TRSV_REG06A_LN0_OVRD_RX_RTERM_CM_PULLDN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG06A_LN0_OVRD_RX_RTERM_CM_PULLDN_SHIFT)) & PCIE_PHY_TRSV_REG06A_LN0_OVRD_RX_RTERM_CM_PULLDN_MASK)
/*! @} */

/*! @name TRSV_REG06B -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG06B_LN0_ANA_RX_SQ_VREF_820M_LPF_BYPASS_MASK (0x1U)
#define PCIE_PHY_TRSV_REG06B_LN0_ANA_RX_SQ_VREF_820M_LPF_BYPASS_SHIFT (0U)
#define PCIE_PHY_TRSV_REG06B_LN0_ANA_RX_SQ_VREF_820M_LPF_BYPASS(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG06B_LN0_ANA_RX_SQ_VREF_820M_LPF_BYPASS_SHIFT)) & PCIE_PHY_TRSV_REG06B_LN0_ANA_RX_SQ_VREF_820M_LPF_BYPASS_MASK)

#define PCIE_PHY_TRSV_REG06B_LN0_RX_SQ_BMR_EN_MASK (0x2U)
#define PCIE_PHY_TRSV_REG06B_LN0_RX_SQ_BMR_EN_SHIFT (1U)
#define PCIE_PHY_TRSV_REG06B_LN0_RX_SQ_BMR_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG06B_LN0_RX_SQ_BMR_EN_SHIFT)) & PCIE_PHY_TRSV_REG06B_LN0_RX_SQ_BMR_EN_MASK)

#define PCIE_PHY_TRSV_REG06B_LN0_OVRD_RX_SQ_BMR_EN_MASK (0x4U)
#define PCIE_PHY_TRSV_REG06B_LN0_OVRD_RX_SQ_BMR_EN_SHIFT (2U)
/*! LN0_OVRD_RX_SQ_BMR_EN - Override enable for rx_sq_bmr_en */
#define PCIE_PHY_TRSV_REG06B_LN0_OVRD_RX_SQ_BMR_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG06B_LN0_OVRD_RX_SQ_BMR_EN_SHIFT)) & PCIE_PHY_TRSV_REG06B_LN0_OVRD_RX_SQ_BMR_EN_MASK)

#define PCIE_PHY_TRSV_REG06B_LN0_RX_RTERM_VCM_EN_G4_MASK (0x8U)
#define PCIE_PHY_TRSV_REG06B_LN0_RX_RTERM_VCM_EN_G4_SHIFT (3U)
/*! LN0_RX_RTERM_VCM_EN_G4 - [GEN4] */
#define PCIE_PHY_TRSV_REG06B_LN0_RX_RTERM_VCM_EN_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG06B_LN0_RX_RTERM_VCM_EN_G4_SHIFT)) & PCIE_PHY_TRSV_REG06B_LN0_RX_RTERM_VCM_EN_G4_MASK)

#define PCIE_PHY_TRSV_REG06B_LN0_RX_RTERM_VCM_EN_G3_MASK (0x10U)
#define PCIE_PHY_TRSV_REG06B_LN0_RX_RTERM_VCM_EN_G3_SHIFT (4U)
/*! LN0_RX_RTERM_VCM_EN_G3 - [GEN3] */
#define PCIE_PHY_TRSV_REG06B_LN0_RX_RTERM_VCM_EN_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG06B_LN0_RX_RTERM_VCM_EN_G3_SHIFT)) & PCIE_PHY_TRSV_REG06B_LN0_RX_RTERM_VCM_EN_G3_MASK)

#define PCIE_PHY_TRSV_REG06B_LN0_RX_RTERM_VCM_EN_G2_MASK (0x20U)
#define PCIE_PHY_TRSV_REG06B_LN0_RX_RTERM_VCM_EN_G2_SHIFT (5U)
/*! LN0_RX_RTERM_VCM_EN_G2 - [GEN2] */
#define PCIE_PHY_TRSV_REG06B_LN0_RX_RTERM_VCM_EN_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG06B_LN0_RX_RTERM_VCM_EN_G2_SHIFT)) & PCIE_PHY_TRSV_REG06B_LN0_RX_RTERM_VCM_EN_G2_MASK)

#define PCIE_PHY_TRSV_REG06B_LN0_RX_RTERM_VCM_EN_G1_MASK (0x40U)
#define PCIE_PHY_TRSV_REG06B_LN0_RX_RTERM_VCM_EN_G1_SHIFT (6U)
/*! LN0_RX_RTERM_VCM_EN_G1 - [GEN1] */
#define PCIE_PHY_TRSV_REG06B_LN0_RX_RTERM_VCM_EN_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG06B_LN0_RX_RTERM_VCM_EN_G1_SHIFT)) & PCIE_PHY_TRSV_REG06B_LN0_RX_RTERM_VCM_EN_G1_MASK)

#define PCIE_PHY_TRSV_REG06B_LN0_OVRD_RX_RTERM_VCM_EN_MASK (0x80U)
#define PCIE_PHY_TRSV_REG06B_LN0_OVRD_RX_RTERM_VCM_EN_SHIFT (7U)
/*! LN0_OVRD_RX_RTERM_VCM_EN - Override enable for rx_rterm_vcm_en_g1 */
#define PCIE_PHY_TRSV_REG06B_LN0_OVRD_RX_RTERM_VCM_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG06B_LN0_OVRD_RX_RTERM_VCM_EN_SHIFT)) & PCIE_PHY_TRSV_REG06B_LN0_OVRD_RX_RTERM_VCM_EN_MASK)
/*! @} */

/*! @name TRSV_REG06C -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG06C_LN0_ANA_RX_SQHS_DIFN_OC_CODE_SIGN_MASK (0x1U)
#define PCIE_PHY_TRSV_REG06C_LN0_ANA_RX_SQHS_DIFN_OC_CODE_SIGN_SHIFT (0U)
/*! LN0_ANA_RX_SQHS_DIFN_OC_CODE_SIGN - RX high-squelch diff-N offset sign */
#define PCIE_PHY_TRSV_REG06C_LN0_ANA_RX_SQHS_DIFN_OC_CODE_SIGN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG06C_LN0_ANA_RX_SQHS_DIFN_OC_CODE_SIGN_SHIFT)) & PCIE_PHY_TRSV_REG06C_LN0_ANA_RX_SQHS_DIFN_OC_CODE_SIGN_MASK)

#define PCIE_PHY_TRSV_REG06C_LN0_RX_SQHS_DIFN_OC_EN_MASK (0x2U)
#define PCIE_PHY_TRSV_REG06C_LN0_RX_SQHS_DIFN_OC_EN_SHIFT (1U)
/*! LN0_RX_SQHS_DIFN_OC_EN - RX high-squelch diff-N offset calibration enable */
#define PCIE_PHY_TRSV_REG06C_LN0_RX_SQHS_DIFN_OC_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG06C_LN0_RX_SQHS_DIFN_OC_EN_SHIFT)) & PCIE_PHY_TRSV_REG06C_LN0_RX_SQHS_DIFN_OC_EN_MASK)

#define PCIE_PHY_TRSV_REG06C_LN0_OVRD_RX_SQHS_DIFN_OC_EN_MASK (0x4U)
#define PCIE_PHY_TRSV_REG06C_LN0_OVRD_RX_SQHS_DIFN_OC_EN_SHIFT (2U)
/*! LN0_OVRD_RX_SQHS_DIFN_OC_EN - Override enable for rx_sqhs_difn_oc_en */
#define PCIE_PHY_TRSV_REG06C_LN0_OVRD_RX_SQHS_DIFN_OC_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG06C_LN0_OVRD_RX_SQHS_DIFN_OC_EN_SHIFT)) & PCIE_PHY_TRSV_REG06C_LN0_OVRD_RX_SQHS_DIFN_OC_EN_MASK)

#define PCIE_PHY_TRSV_REG06C_LN0_RX_SQHS_EN_MASK (0x8U)
#define PCIE_PHY_TRSV_REG06C_LN0_RX_SQHS_EN_SHIFT (3U)
/*! LN0_RX_SQHS_EN - RX high-speed squelch enable */
#define PCIE_PHY_TRSV_REG06C_LN0_RX_SQHS_EN(x)   (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG06C_LN0_RX_SQHS_EN_SHIFT)) & PCIE_PHY_TRSV_REG06C_LN0_RX_SQHS_EN_MASK)

#define PCIE_PHY_TRSV_REG06C_LN0_OVRD_RX_SQHS_EN_MASK (0x10U)
#define PCIE_PHY_TRSV_REG06C_LN0_OVRD_RX_SQHS_EN_SHIFT (4U)
/*! LN0_OVRD_RX_SQHS_EN - Override enable for rx_sqhs_en */
#define PCIE_PHY_TRSV_REG06C_LN0_OVRD_RX_SQHS_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG06C_LN0_OVRD_RX_SQHS_EN_SHIFT)) & PCIE_PHY_TRSV_REG06C_LN0_OVRD_RX_SQHS_EN_MASK)

#define PCIE_PHY_TRSV_REG06C_LN0_ANA_RX_SQ_VREF_820M_SEL_MASK (0x60U)
#define PCIE_PHY_TRSV_REG06C_LN0_ANA_RX_SQ_VREF_820M_SEL_SHIFT (5U)
#define PCIE_PHY_TRSV_REG06C_LN0_ANA_RX_SQ_VREF_820M_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG06C_LN0_ANA_RX_SQ_VREF_820M_SEL_SHIFT)) & PCIE_PHY_TRSV_REG06C_LN0_ANA_RX_SQ_VREF_820M_SEL_MASK)
/*! @} */

/*! @name TRSV_REG06D -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG06D_LN0_RX_SQHS_DIFP_OC_EN_MASK (0x1U)
#define PCIE_PHY_TRSV_REG06D_LN0_RX_SQHS_DIFP_OC_EN_SHIFT (0U)
/*! LN0_RX_SQHS_DIFP_OC_EN - RX high-squelch diff-P offset calibration enable */
#define PCIE_PHY_TRSV_REG06D_LN0_RX_SQHS_DIFP_OC_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG06D_LN0_RX_SQHS_DIFP_OC_EN_SHIFT)) & PCIE_PHY_TRSV_REG06D_LN0_RX_SQHS_DIFP_OC_EN_MASK)

#define PCIE_PHY_TRSV_REG06D_LN0_OVRD_RX_SQHS_DIFP_OC_EN_MASK (0x2U)
#define PCIE_PHY_TRSV_REG06D_LN0_OVRD_RX_SQHS_DIFP_OC_EN_SHIFT (1U)
/*! LN0_OVRD_RX_SQHS_DIFP_OC_EN - Override enable for rx_sqhs_difp_oc_en */
#define PCIE_PHY_TRSV_REG06D_LN0_OVRD_RX_SQHS_DIFP_OC_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG06D_LN0_OVRD_RX_SQHS_DIFP_OC_EN_SHIFT)) & PCIE_PHY_TRSV_REG06D_LN0_OVRD_RX_SQHS_DIFP_OC_EN_MASK)

#define PCIE_PHY_TRSV_REG06D_LN0_ANA_RX_SQHS_DIFN_SKEWBUF_EN_MASK (0x4U)
#define PCIE_PHY_TRSV_REG06D_LN0_ANA_RX_SQHS_DIFN_SKEWBUF_EN_SHIFT (2U)
#define PCIE_PHY_TRSV_REG06D_LN0_ANA_RX_SQHS_DIFN_SKEWBUF_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG06D_LN0_ANA_RX_SQHS_DIFN_SKEWBUF_EN_SHIFT)) & PCIE_PHY_TRSV_REG06D_LN0_ANA_RX_SQHS_DIFN_SKEWBUF_EN_MASK)

#define PCIE_PHY_TRSV_REG06D_LN0_RX_SQHS_DIFN_OC_CODE_MASK (0x78U)
#define PCIE_PHY_TRSV_REG06D_LN0_RX_SQHS_DIFN_OC_CODE_SHIFT (3U)
/*! LN0_RX_SQHS_DIFN_OC_CODE - RX high-squelch diff-N manual offset code */
#define PCIE_PHY_TRSV_REG06D_LN0_RX_SQHS_DIFN_OC_CODE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG06D_LN0_RX_SQHS_DIFN_OC_CODE_SHIFT)) & PCIE_PHY_TRSV_REG06D_LN0_RX_SQHS_DIFN_OC_CODE_MASK)

#define PCIE_PHY_TRSV_REG06D_LN0_OVRD_RX_SQHS_DIFN_OC_CODE_MASK (0x80U)
#define PCIE_PHY_TRSV_REG06D_LN0_OVRD_RX_SQHS_DIFN_OC_CODE_SHIFT (7U)
/*! LN0_OVRD_RX_SQHS_DIFN_OC_CODE - Override enable for rx_sqhs_difn_oc_code */
#define PCIE_PHY_TRSV_REG06D_LN0_OVRD_RX_SQHS_DIFN_OC_CODE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG06D_LN0_OVRD_RX_SQHS_DIFN_OC_CODE_SHIFT)) & PCIE_PHY_TRSV_REG06D_LN0_OVRD_RX_SQHS_DIFN_OC_CODE_MASK)
/*! @} */

/*! @name TRSV_REG06E -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG06E_LN0_ANA_RX_SQHS_SKEW_DEFAULT_EN_MASK (0x1U)
#define PCIE_PHY_TRSV_REG06E_LN0_ANA_RX_SQHS_SKEW_DEFAULT_EN_SHIFT (0U)
/*! LN0_ANA_RX_SQHS_SKEW_DEFAULT_EN - Fixed skew for PCIe/SATA Squelch */
#define PCIE_PHY_TRSV_REG06E_LN0_ANA_RX_SQHS_SKEW_DEFAULT_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG06E_LN0_ANA_RX_SQHS_SKEW_DEFAULT_EN_SHIFT)) & PCIE_PHY_TRSV_REG06E_LN0_ANA_RX_SQHS_SKEW_DEFAULT_EN_MASK)

#define PCIE_PHY_TRSV_REG06E_LN0_ANA_RX_SQHS_DIFP_SKEWBUF_EN_MASK (0x2U)
#define PCIE_PHY_TRSV_REG06E_LN0_ANA_RX_SQHS_DIFP_SKEWBUF_EN_SHIFT (1U)
/*! LN0_ANA_RX_SQHS_DIFP_SKEWBUF_EN - Enable the high speed Squelch DIFP SKEW BUFFER */
#define PCIE_PHY_TRSV_REG06E_LN0_ANA_RX_SQHS_DIFP_SKEWBUF_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG06E_LN0_ANA_RX_SQHS_DIFP_SKEWBUF_EN_SHIFT)) & PCIE_PHY_TRSV_REG06E_LN0_ANA_RX_SQHS_DIFP_SKEWBUF_EN_MASK)

#define PCIE_PHY_TRSV_REG06E_LN0_RX_SQHS_DIFP_OC_CODE_MASK (0x3CU)
#define PCIE_PHY_TRSV_REG06E_LN0_RX_SQHS_DIFP_OC_CODE_SHIFT (2U)
/*! LN0_RX_SQHS_DIFP_OC_CODE - RX squelch diff-P manual offset code */
#define PCIE_PHY_TRSV_REG06E_LN0_RX_SQHS_DIFP_OC_CODE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG06E_LN0_RX_SQHS_DIFP_OC_CODE_SHIFT)) & PCIE_PHY_TRSV_REG06E_LN0_RX_SQHS_DIFP_OC_CODE_MASK)

#define PCIE_PHY_TRSV_REG06E_LN0_OVRD_RX_SQHS_DIFP_OC_CODE_MASK (0x40U)
#define PCIE_PHY_TRSV_REG06E_LN0_OVRD_RX_SQHS_DIFP_OC_CODE_SHIFT (6U)
/*! LN0_OVRD_RX_SQHS_DIFP_OC_CODE - Override enable for rx_sqhs_difp_oc_code */
#define PCIE_PHY_TRSV_REG06E_LN0_OVRD_RX_SQHS_DIFP_OC_CODE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG06E_LN0_OVRD_RX_SQHS_DIFP_OC_CODE_SHIFT)) & PCIE_PHY_TRSV_REG06E_LN0_OVRD_RX_SQHS_DIFP_OC_CODE_MASK)

#define PCIE_PHY_TRSV_REG06E_LN0_ANA_RX_SQHS_DIFP_OC_CODE_SIGN_MASK (0x80U)
#define PCIE_PHY_TRSV_REG06E_LN0_ANA_RX_SQHS_DIFP_OC_CODE_SIGN_SHIFT (7U)
/*! LN0_ANA_RX_SQHS_DIFP_OC_CODE_SIGN - RX high-squelch diff-P offset sign */
#define PCIE_PHY_TRSV_REG06E_LN0_ANA_RX_SQHS_DIFP_OC_CODE_SIGN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG06E_LN0_ANA_RX_SQHS_DIFP_OC_CODE_SIGN_SHIFT)) & PCIE_PHY_TRSV_REG06E_LN0_ANA_RX_SQHS_DIFP_OC_CODE_SIGN_MASK)
/*! @} */

/*! @name TRSV_REG06F -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG06F_LN0_ANA_RX_SQHS_VREF_SUPPLY_SEL_MASK (0x1U)
#define PCIE_PHY_TRSV_REG06F_LN0_ANA_RX_SQHS_VREF_SUPPLY_SEL_SHIFT (0U)
/*! LN0_ANA_RX_SQHS_VREF_SUPPLY_SEL - Selection of supply voltage of reference voltage for threshold calibration of HS SQ */
#define PCIE_PHY_TRSV_REG06F_LN0_ANA_RX_SQHS_VREF_SUPPLY_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG06F_LN0_ANA_RX_SQHS_VREF_SUPPLY_SEL_SHIFT)) & PCIE_PHY_TRSV_REG06F_LN0_ANA_RX_SQHS_VREF_SUPPLY_SEL_MASK)

#define PCIE_PHY_TRSV_REG06F_LN0_ANA_RX_SQHS_BW_CTRL_MASK (0x6U)
#define PCIE_PHY_TRSV_REG06F_LN0_ANA_RX_SQHS_BW_CTRL_SHIFT (1U)
#define PCIE_PHY_TRSV_REG06F_LN0_ANA_RX_SQHS_BW_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG06F_LN0_ANA_RX_SQHS_BW_CTRL_SHIFT)) & PCIE_PHY_TRSV_REG06F_LN0_ANA_RX_SQHS_BW_CTRL_MASK)

#define PCIE_PHY_TRSV_REG06F_LN0_ANA_RX_SQHS_FILTER_EN_MASK (0x8U)
#define PCIE_PHY_TRSV_REG06F_LN0_ANA_RX_SQHS_FILTER_EN_SHIFT (3U)
/*! LN0_ANA_RX_SQHS_FILTER_EN - SQHS loss detector enable */
#define PCIE_PHY_TRSV_REG06F_LN0_ANA_RX_SQHS_FILTER_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG06F_LN0_ANA_RX_SQHS_FILTER_EN_SHIFT)) & PCIE_PHY_TRSV_REG06F_LN0_ANA_RX_SQHS_FILTER_EN_MASK)

#define PCIE_PHY_TRSV_REG06F_LN0_ANA_RX_SQHS_TH_CTRL_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG06F_LN0_ANA_RX_SQHS_TH_CTRL_SHIFT (4U)
/*! LN0_ANA_RX_SQHS_TH_CTRL - RX squelch threshold voltage selection */
#define PCIE_PHY_TRSV_REG06F_LN0_ANA_RX_SQHS_TH_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG06F_LN0_ANA_RX_SQHS_TH_CTRL_SHIFT)) & PCIE_PHY_TRSV_REG06F_LN0_ANA_RX_SQHS_TH_CTRL_MASK)
/*! @} */

/*! @name TRSV_REG070 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG070_LN0_ANA_RX_SQLS_DIFN_TH_CTRL_MASK (0x7U)
#define PCIE_PHY_TRSV_REG070_LN0_ANA_RX_SQLS_DIFN_TH_CTRL_SHIFT (0U)
/*! LN0_ANA_RX_SQLS_DIFN_TH_CTRL - DIFN in MPHY, LFPS in USB: */
#define PCIE_PHY_TRSV_REG070_LN0_ANA_RX_SQLS_DIFN_TH_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG070_LN0_ANA_RX_SQLS_DIFN_TH_CTRL_SHIFT)) & PCIE_PHY_TRSV_REG070_LN0_ANA_RX_SQLS_DIFN_TH_CTRL_MASK)

#define PCIE_PHY_TRSV_REG070_LN0_ANA_RX_SQLS_DIFP_FAST_ANA_SEL_MASK (0x8U)
#define PCIE_PHY_TRSV_REG070_LN0_ANA_RX_SQLS_DIFP_FAST_ANA_SEL_SHIFT (3U)
/*! LN0_ANA_RX_SQLS_DIFP_FAST_ANA_SEL - RX DIFP detect signal selection for PRE_DATA_VALID and DATA_VALID signal */
#define PCIE_PHY_TRSV_REG070_LN0_ANA_RX_SQLS_DIFP_FAST_ANA_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG070_LN0_ANA_RX_SQLS_DIFP_FAST_ANA_SEL_SHIFT)) & PCIE_PHY_TRSV_REG070_LN0_ANA_RX_SQLS_DIFP_FAST_ANA_SEL_MASK)

#define PCIE_PHY_TRSV_REG070_LN0_RX_SQLS_DIFP_DET_EN_MASK (0x10U)
#define PCIE_PHY_TRSV_REG070_LN0_RX_SQLS_DIFP_DET_EN_SHIFT (4U)
/*! LN0_RX_SQLS_DIFP_DET_EN - RX low-speed DIFP squelch enable */
#define PCIE_PHY_TRSV_REG070_LN0_RX_SQLS_DIFP_DET_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG070_LN0_RX_SQLS_DIFP_DET_EN_SHIFT)) & PCIE_PHY_TRSV_REG070_LN0_RX_SQLS_DIFP_DET_EN_MASK)

#define PCIE_PHY_TRSV_REG070_LN0_OVRD_RX_SQLS_DIFP_DET_EN_MASK (0x20U)
#define PCIE_PHY_TRSV_REG070_LN0_OVRD_RX_SQLS_DIFP_DET_EN_SHIFT (5U)
/*! LN0_OVRD_RX_SQLS_DIFP_DET_EN - Override enable for rx_sqls_difp_det_en */
#define PCIE_PHY_TRSV_REG070_LN0_OVRD_RX_SQLS_DIFP_DET_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG070_LN0_OVRD_RX_SQLS_DIFP_DET_EN_SHIFT)) & PCIE_PHY_TRSV_REG070_LN0_OVRD_RX_SQLS_DIFP_DET_EN_MASK)

#define PCIE_PHY_TRSV_REG070_LN0_RX_SQLS_DIFN_DET_EN_MASK (0x40U)
#define PCIE_PHY_TRSV_REG070_LN0_RX_SQLS_DIFN_DET_EN_SHIFT (6U)
/*! LN0_RX_SQLS_DIFN_DET_EN - RX low-speed DIFN squelch enable */
#define PCIE_PHY_TRSV_REG070_LN0_RX_SQLS_DIFN_DET_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG070_LN0_RX_SQLS_DIFN_DET_EN_SHIFT)) & PCIE_PHY_TRSV_REG070_LN0_RX_SQLS_DIFN_DET_EN_MASK)

#define PCIE_PHY_TRSV_REG070_LN0_OVRD_RX_SQLS_DIFN_DET_EN_MASK (0x80U)
#define PCIE_PHY_TRSV_REG070_LN0_OVRD_RX_SQLS_DIFN_DET_EN_SHIFT (7U)
/*! LN0_OVRD_RX_SQLS_DIFN_DET_EN - Override enable for rx_sqls_difn_det_en */
#define PCIE_PHY_TRSV_REG070_LN0_OVRD_RX_SQLS_DIFN_DET_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG070_LN0_OVRD_RX_SQLS_DIFN_DET_EN_SHIFT)) & PCIE_PHY_TRSV_REG070_LN0_OVRD_RX_SQLS_DIFN_DET_EN_MASK)
/*! @} */

/*! @name TRSV_REG071 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG071_LN0_ANA_RX_SQLS_SCL2CMOS_I_CTRL_MASK (0x3U)
#define PCIE_PHY_TRSV_REG071_LN0_ANA_RX_SQLS_SCL2CMOS_I_CTRL_SHIFT (0U)
/*! LN0_ANA_RX_SQLS_SCL2CMOS_I_CTRL - Current controls for low-speed Squelch comparator current source */
#define PCIE_PHY_TRSV_REG071_LN0_ANA_RX_SQLS_SCL2CMOS_I_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG071_LN0_ANA_RX_SQLS_SCL2CMOS_I_CTRL_SHIFT)) & PCIE_PHY_TRSV_REG071_LN0_ANA_RX_SQLS_SCL2CMOS_I_CTRL_MASK)

#define PCIE_PHY_TRSV_REG071_LN0_ANA_RX_SQLS_IN_LPF_CTRL_MASK (0x1CU)
#define PCIE_PHY_TRSV_REG071_LN0_ANA_RX_SQLS_IN_LPF_CTRL_SHIFT (2U)
/*! LN0_ANA_RX_SQLS_IN_LPF_CTRL - Low pass filter resistor control for Squelch input : 00:30MHz,01:60MHz,, 10:100MHz, 11: 150MHz */
#define PCIE_PHY_TRSV_REG071_LN0_ANA_RX_SQLS_IN_LPF_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG071_LN0_ANA_RX_SQLS_IN_LPF_CTRL_SHIFT)) & PCIE_PHY_TRSV_REG071_LN0_ANA_RX_SQLS_IN_LPF_CTRL_MASK)

#define PCIE_PHY_TRSV_REG071_LN0_ANA_RX_SQLS_DIFP_TH_CTRL_MASK (0xE0U)
#define PCIE_PHY_TRSV_REG071_LN0_ANA_RX_SQLS_DIFP_TH_CTRL_SHIFT (5U)
/*! LN0_ANA_RX_SQLS_DIFP_TH_CTRL - DIFP in MPHY */
#define PCIE_PHY_TRSV_REG071_LN0_ANA_RX_SQLS_DIFP_TH_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG071_LN0_ANA_RX_SQLS_DIFP_TH_CTRL_SHIFT)) & PCIE_PHY_TRSV_REG071_LN0_ANA_RX_SQLS_DIFP_TH_CTRL_MASK)
/*! @} */

/*! @name TRSV_REG072 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG072_LN0_RX_PWM_AFC_RSTN_MASK (0x1U)
#define PCIE_PHY_TRSV_REG072_LN0_RX_PWM_AFC_RSTN_SHIFT (0U)
/*! LN0_RX_PWM_AFC_RSTN - RX MPHY PWM AFC reset */
#define PCIE_PHY_TRSV_REG072_LN0_RX_PWM_AFC_RSTN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG072_LN0_RX_PWM_AFC_RSTN_SHIFT)) & PCIE_PHY_TRSV_REG072_LN0_RX_PWM_AFC_RSTN_MASK)

#define PCIE_PHY_TRSV_REG072_LN0_OVRD_RX_PWM_AFC_RSTN_MASK (0x2U)
#define PCIE_PHY_TRSV_REG072_LN0_OVRD_RX_PWM_AFC_RSTN_SHIFT (1U)
/*! LN0_OVRD_RX_PWM_AFC_RSTN - Override enable for rx_pwm_afc_rstn */
#define PCIE_PHY_TRSV_REG072_LN0_OVRD_RX_PWM_AFC_RSTN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG072_LN0_OVRD_RX_PWM_AFC_RSTN_SHIFT)) & PCIE_PHY_TRSV_REG072_LN0_OVRD_RX_PWM_AFC_RSTN_MASK)

#define PCIE_PHY_TRSV_REG072_LN0_RX_PWM_RSTN_MASK (0x4U)
#define PCIE_PHY_TRSV_REG072_LN0_RX_PWM_RSTN_SHIFT (2U)
/*! LN0_RX_PWM_RSTN - RX MPHY PWM reset */
#define PCIE_PHY_TRSV_REG072_LN0_RX_PWM_RSTN(x)  (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG072_LN0_RX_PWM_RSTN_SHIFT)) & PCIE_PHY_TRSV_REG072_LN0_RX_PWM_RSTN_MASK)

#define PCIE_PHY_TRSV_REG072_LN0_OVRD_RX_PWM_RSTN_MASK (0x8U)
#define PCIE_PHY_TRSV_REG072_LN0_OVRD_RX_PWM_RSTN_SHIFT (3U)
/*! LN0_OVRD_RX_PWM_RSTN - Override enable for rx_pwm_rstn */
#define PCIE_PHY_TRSV_REG072_LN0_OVRD_RX_PWM_RSTN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG072_LN0_OVRD_RX_PWM_RSTN_SHIFT)) & PCIE_PHY_TRSV_REG072_LN0_OVRD_RX_PWM_RSTN_MASK)

#define PCIE_PHY_TRSV_REG072_LN0_RX_PWM_CNT_EN_MASK (0x10U)
#define PCIE_PHY_TRSV_REG072_LN0_RX_PWM_CNT_EN_SHIFT (4U)
/*! LN0_RX_PWM_CNT_EN - Enalbe counter clock for PWM over sampling */
#define PCIE_PHY_TRSV_REG072_LN0_RX_PWM_CNT_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG072_LN0_RX_PWM_CNT_EN_SHIFT)) & PCIE_PHY_TRSV_REG072_LN0_RX_PWM_CNT_EN_MASK)

#define PCIE_PHY_TRSV_REG072_LN0_OVRD_RX_PWM_CNT_EN_MASK (0x20U)
#define PCIE_PHY_TRSV_REG072_LN0_OVRD_RX_PWM_CNT_EN_SHIFT (5U)
/*! LN0_OVRD_RX_PWM_CNT_EN - Override enable for rx_pwm_cnt_en */
#define PCIE_PHY_TRSV_REG072_LN0_OVRD_RX_PWM_CNT_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG072_LN0_OVRD_RX_PWM_CNT_EN_SHIFT)) & PCIE_PHY_TRSV_REG072_LN0_OVRD_RX_PWM_CNT_EN_MASK)

#define PCIE_PHY_TRSV_REG072_LN0_RX_PWM_OSC_EN_MASK (0x40U)
#define PCIE_PHY_TRSV_REG072_LN0_RX_PWM_OSC_EN_SHIFT (6U)
/*! LN0_RX_PWM_OSC_EN - RX MPHY PWM oscillator enable which is used in analog RX block in order to oversample */
#define PCIE_PHY_TRSV_REG072_LN0_RX_PWM_OSC_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG072_LN0_RX_PWM_OSC_EN_SHIFT)) & PCIE_PHY_TRSV_REG072_LN0_RX_PWM_OSC_EN_MASK)

#define PCIE_PHY_TRSV_REG072_LN0_OVRD_RX_PWM_OSC_EN_MASK (0x80U)
#define PCIE_PHY_TRSV_REG072_LN0_OVRD_RX_PWM_OSC_EN_SHIFT (7U)
/*! LN0_OVRD_RX_PWM_OSC_EN - Override enable for rx_pwm_osc_en */
#define PCIE_PHY_TRSV_REG072_LN0_OVRD_RX_PWM_OSC_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG072_LN0_OVRD_RX_PWM_OSC_EN_SHIFT)) & PCIE_PHY_TRSV_REG072_LN0_OVRD_RX_PWM_OSC_EN_MASK)
/*! @} */

/*! @name TRSV_REG073 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG073_LN0_ANA_RX_PWM_DIV_RATIO_MASK (0x7U)
#define PCIE_PHY_TRSV_REG073_LN0_ANA_RX_PWM_DIV_RATIO_SHIFT (0U)
/*! LN0_ANA_RX_PWM_DIV_RATIO - RX MPHY PWM oversampling clock divide ratio from PWM oscillator */
#define PCIE_PHY_TRSV_REG073_LN0_ANA_RX_PWM_DIV_RATIO(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG073_LN0_ANA_RX_PWM_DIV_RATIO_SHIFT)) & PCIE_PHY_TRSV_REG073_LN0_ANA_RX_PWM_DIV_RATIO_MASK)

#define PCIE_PHY_TRSV_REG073_LN0_RX_PWM_AFC_DONE_MASK (0x8U)
#define PCIE_PHY_TRSV_REG073_LN0_RX_PWM_AFC_DONE_SHIFT (3U)
/*! LN0_RX_PWM_AFC_DONE - RX MPHY PWM AFC done signal */
#define PCIE_PHY_TRSV_REG073_LN0_RX_PWM_AFC_DONE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG073_LN0_RX_PWM_AFC_DONE_SHIFT)) & PCIE_PHY_TRSV_REG073_LN0_RX_PWM_AFC_DONE_MASK)

#define PCIE_PHY_TRSV_REG073_LN0_OVRD_RX_PWM_AFC_DONE_MASK (0x10U)
#define PCIE_PHY_TRSV_REG073_LN0_OVRD_RX_PWM_AFC_DONE_SHIFT (4U)
/*! LN0_OVRD_RX_PWM_AFC_DONE - Override enable for rx_pwm_afc_done */
#define PCIE_PHY_TRSV_REG073_LN0_OVRD_RX_PWM_AFC_DONE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG073_LN0_OVRD_RX_PWM_AFC_DONE_SHIFT)) & PCIE_PHY_TRSV_REG073_LN0_OVRD_RX_PWM_AFC_DONE_MASK)
/*! @} */

/*! @name TRSV_REG074 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG074_LN0_ANA_RX_PWM_OC_EN_MASK (0x1U)
#define PCIE_PHY_TRSV_REG074_LN0_ANA_RX_PWM_OC_EN_SHIFT (0U)
#define PCIE_PHY_TRSV_REG074_LN0_ANA_RX_PWM_OC_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG074_LN0_ANA_RX_PWM_OC_EN_SHIFT)) & PCIE_PHY_TRSV_REG074_LN0_ANA_RX_PWM_OC_EN_MASK)

#define PCIE_PHY_TRSV_REG074_LN0_RX_PWM_OSC_CODE_MASK (0x1EU)
#define PCIE_PHY_TRSV_REG074_LN0_RX_PWM_OSC_CODE_SHIFT (1U)
/*! LN0_RX_PWM_OSC_CODE - RX MPHY PWM AFC code for oscillator */
#define PCIE_PHY_TRSV_REG074_LN0_RX_PWM_OSC_CODE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG074_LN0_RX_PWM_OSC_CODE_SHIFT)) & PCIE_PHY_TRSV_REG074_LN0_RX_PWM_OSC_CODE_MASK)

#define PCIE_PHY_TRSV_REG074_LN0_OVRD_RX_PWM_OSC_CODE_MASK (0x20U)
#define PCIE_PHY_TRSV_REG074_LN0_OVRD_RX_PWM_OSC_CODE_SHIFT (5U)
/*! LN0_OVRD_RX_PWM_OSC_CODE - Override enable for rx_pwm_osc_code */
#define PCIE_PHY_TRSV_REG074_LN0_OVRD_RX_PWM_OSC_CODE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG074_LN0_OVRD_RX_PWM_OSC_CODE_SHIFT)) & PCIE_PHY_TRSV_REG074_LN0_OVRD_RX_PWM_OSC_CODE_MASK)
/*! @} */

/*! @name TRSV_REG075 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG075_LN0_ANA_RX_LFPS_LOSS_DET_EN_MASK (0x1U)
#define PCIE_PHY_TRSV_REG075_LN0_ANA_RX_LFPS_LOSS_DET_EN_SHIFT (0U)
/*! LN0_ANA_RX_LFPS_LOSS_DET_EN - LFPS loss detector enable */
#define PCIE_PHY_TRSV_REG075_LN0_ANA_RX_LFPS_LOSS_DET_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG075_LN0_ANA_RX_LFPS_LOSS_DET_EN_SHIFT)) & PCIE_PHY_TRSV_REG075_LN0_ANA_RX_LFPS_LOSS_DET_EN_MASK)

#define PCIE_PHY_TRSV_REG075_LN0_RX_LFPS_DET_EN_MASK (0x2U)
#define PCIE_PHY_TRSV_REG075_LN0_RX_LFPS_DET_EN_SHIFT (1U)
/*! LN0_RX_LFPS_DET_EN - LFPS detector enable */
#define PCIE_PHY_TRSV_REG075_LN0_RX_LFPS_DET_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG075_LN0_RX_LFPS_DET_EN_SHIFT)) & PCIE_PHY_TRSV_REG075_LN0_RX_LFPS_DET_EN_MASK)

#define PCIE_PHY_TRSV_REG075_LN0_OVRD_RX_LFPS_DET_EN_MASK (0x4U)
#define PCIE_PHY_TRSV_REG075_LN0_OVRD_RX_LFPS_DET_EN_SHIFT (2U)
/*! LN0_OVRD_RX_LFPS_DET_EN - Override enable for rx_lfps_det_en */
#define PCIE_PHY_TRSV_REG075_LN0_OVRD_RX_LFPS_DET_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG075_LN0_OVRD_RX_LFPS_DET_EN_SHIFT)) & PCIE_PHY_TRSV_REG075_LN0_OVRD_RX_LFPS_DET_EN_MASK)

#define PCIE_PHY_TRSV_REG075_LN0_ANA_RX_PWM_OC_CODE_MASK (0x78U)
#define PCIE_PHY_TRSV_REG075_LN0_ANA_RX_PWM_OC_CODE_SHIFT (3U)
/*! LN0_ANA_RX_PWM_OC_CODE - min(-7 or 0_111){maximum negative offset} - max(+7 or 1_111) {maximum positive offset} */
#define PCIE_PHY_TRSV_REG075_LN0_ANA_RX_PWM_OC_CODE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG075_LN0_ANA_RX_PWM_OC_CODE_SHIFT)) & PCIE_PHY_TRSV_REG075_LN0_ANA_RX_PWM_OC_CODE_MASK)
/*! @} */

/*! @name TRSV_REG076 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG076_LN0_ANA_RX_SRLB_EN_MASK (0x1U)
#define PCIE_PHY_TRSV_REG076_LN0_ANA_RX_SRLB_EN_SHIFT (0U)
/*! LN0_ANA_RX_SRLB_EN - Serial retimed loopback enable */
#define PCIE_PHY_TRSV_REG076_LN0_ANA_RX_SRLB_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG076_LN0_ANA_RX_SRLB_EN_SHIFT)) & PCIE_PHY_TRSV_REG076_LN0_ANA_RX_SRLB_EN_MASK)

#define PCIE_PHY_TRSV_REG076_LN0_ANA_RX_LLB_EN_MASK (0x2U)
#define PCIE_PHY_TRSV_REG076_LN0_ANA_RX_LLB_EN_SHIFT (1U)
/*! LN0_ANA_RX_LLB_EN - Line loopback enalble */
#define PCIE_PHY_TRSV_REG076_LN0_ANA_RX_LLB_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG076_LN0_ANA_RX_LLB_EN_SHIFT)) & PCIE_PHY_TRSV_REG076_LN0_ANA_RX_LLB_EN_MASK)

#define PCIE_PHY_TRSV_REG076_LN0_ANA_RX_SLB_EN_MASK (0x4U)
#define PCIE_PHY_TRSV_REG076_LN0_ANA_RX_SLB_EN_SHIFT (2U)
/*! LN0_ANA_RX_SLB_EN - Serial loopback enable */
#define PCIE_PHY_TRSV_REG076_LN0_ANA_RX_SLB_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG076_LN0_ANA_RX_SLB_EN_SHIFT)) & PCIE_PHY_TRSV_REG076_LN0_ANA_RX_SLB_EN_MASK)

#define PCIE_PHY_TRSV_REG076_LN0_ANA_RX_BIAS_RMRES_CTRL_MASK (0x38U)
#define PCIE_PHY_TRSV_REG076_LN0_ANA_RX_BIAS_RMRES_CTRL_SHIFT (3U)
/*! LN0_ANA_RX_BIAS_RMRES_CTRL - RX RMRES bias current control */
#define PCIE_PHY_TRSV_REG076_LN0_ANA_RX_BIAS_RMRES_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG076_LN0_ANA_RX_BIAS_RMRES_CTRL_SHIFT)) & PCIE_PHY_TRSV_REG076_LN0_ANA_RX_BIAS_RMRES_CTRL_MASK)

#define PCIE_PHY_TRSV_REG076_LN0_RX_BIAS_EN_MASK (0x40U)
#define PCIE_PHY_TRSV_REG076_LN0_RX_BIAS_EN_SHIFT (6U)
/*! LN0_RX_BIAS_EN - RX bias current enable */
#define PCIE_PHY_TRSV_REG076_LN0_RX_BIAS_EN(x)   (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG076_LN0_RX_BIAS_EN_SHIFT)) & PCIE_PHY_TRSV_REG076_LN0_RX_BIAS_EN_MASK)

#define PCIE_PHY_TRSV_REG076_LN0_OVRD_RX_BIAS_EN_MASK (0x80U)
#define PCIE_PHY_TRSV_REG076_LN0_OVRD_RX_BIAS_EN_SHIFT (7U)
/*! LN0_OVRD_RX_BIAS_EN - Override enable for rx_bias_en */
#define PCIE_PHY_TRSV_REG076_LN0_OVRD_RX_BIAS_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG076_LN0_OVRD_RX_BIAS_EN_SHIFT)) & PCIE_PHY_TRSV_REG076_LN0_OVRD_RX_BIAS_EN_MASK)
/*! @} */

/*! @name TRSV_REG077 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG077_LN0_ANA_RX_LLB_ITAIL_CTRL_MASK (0x3U)
#define PCIE_PHY_TRSV_REG077_LN0_ANA_RX_LLB_ITAIL_CTRL_SHIFT (0U)
/*! LN0_ANA_RX_LLB_ITAIL_CTRL - Line loopback tail-current control */
#define PCIE_PHY_TRSV_REG077_LN0_ANA_RX_LLB_ITAIL_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG077_LN0_ANA_RX_LLB_ITAIL_CTRL_SHIFT)) & PCIE_PHY_TRSV_REG077_LN0_ANA_RX_LLB_ITAIL_CTRL_MASK)

#define PCIE_PHY_TRSV_REG077_LN0_ANA_RX_LLB_DUTY_CTRL_MASK (0x1CU)
#define PCIE_PHY_TRSV_REG077_LN0_ANA_RX_LLB_DUTY_CTRL_SHIFT (2U)
/*! LN0_ANA_RX_LLB_DUTY_CTRL - Line loopback duty-ratio control */
#define PCIE_PHY_TRSV_REG077_LN0_ANA_RX_LLB_DUTY_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG077_LN0_ANA_RX_LLB_DUTY_CTRL_SHIFT)) & PCIE_PHY_TRSV_REG077_LN0_ANA_RX_LLB_DUTY_CTRL_MASK)

#define PCIE_PHY_TRSV_REG077_LN0_ANA_RX_LLB_ACCAP_EN_MASK (0x20U)
#define PCIE_PHY_TRSV_REG077_LN0_ANA_RX_LLB_ACCAP_EN_SHIFT (5U)
/*! LN0_ANA_RX_LLB_ACCAP_EN - Line loopback path selection */
#define PCIE_PHY_TRSV_REG077_LN0_ANA_RX_LLB_ACCAP_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG077_LN0_ANA_RX_LLB_ACCAP_EN_SHIFT)) & PCIE_PHY_TRSV_REG077_LN0_ANA_RX_LLB_ACCAP_EN_MASK)

#define PCIE_PHY_TRSV_REG077_LN0_ANA_RX_SRLB_DATA_EDGE_SEL_MASK (0x40U)
#define PCIE_PHY_TRSV_REG077_LN0_ANA_RX_SRLB_DATA_EDGE_SEL_SHIFT (6U)
/*! LN0_ANA_RX_SRLB_DATA_EDGE_SEL - Serial retimed loopback path selection */
#define PCIE_PHY_TRSV_REG077_LN0_ANA_RX_SRLB_DATA_EDGE_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG077_LN0_ANA_RX_SRLB_DATA_EDGE_SEL_SHIFT)) & PCIE_PHY_TRSV_REG077_LN0_ANA_RX_SRLB_DATA_EDGE_SEL_MASK)

#define PCIE_PHY_TRSV_REG077_LN0_ANA_RX_SRLB_EVEN_ODD_SEL_MASK (0x80U)
#define PCIE_PHY_TRSV_REG077_LN0_ANA_RX_SRLB_EVEN_ODD_SEL_SHIFT (7U)
/*! LN0_ANA_RX_SRLB_EVEN_ODD_SEL - Serial retimed loopback path selection */
#define PCIE_PHY_TRSV_REG077_LN0_ANA_RX_SRLB_EVEN_ODD_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG077_LN0_ANA_RX_SRLB_EVEN_ODD_SEL_SHIFT)) & PCIE_PHY_TRSV_REG077_LN0_ANA_RX_SRLB_EVEN_ODD_SEL_MASK)
/*! @} */

/*! @name TRSV_REG078 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG078_LN0_ANA_RX_ATB_EN_MASK (0x1U)
#define PCIE_PHY_TRSV_REG078_LN0_ANA_RX_ATB_EN_SHIFT (0U)
/*! LN0_ANA_RX_ATB_EN - RX ATB enable */
#define PCIE_PHY_TRSV_REG078_LN0_ANA_RX_ATB_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG078_LN0_ANA_RX_ATB_EN_SHIFT)) & PCIE_PHY_TRSV_REG078_LN0_ANA_RX_ATB_EN_MASK)

#define PCIE_PHY_TRSV_REG078_LN0_ANA_RX_CDR_CLK_MON_EN_MASK (0x2U)
#define PCIE_PHY_TRSV_REG078_LN0_ANA_RX_CDR_CLK_MON_EN_SHIFT (1U)
#define PCIE_PHY_TRSV_REG078_LN0_ANA_RX_CDR_CLK_MON_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG078_LN0_ANA_RX_CDR_CLK_MON_EN_SHIFT)) & PCIE_PHY_TRSV_REG078_LN0_ANA_RX_CDR_CLK_MON_EN_MASK)

#define PCIE_PHY_TRSV_REG078_LN0_ANA_RX_LLB_RLOAD_CTRL_MASK (0x4U)
#define PCIE_PHY_TRSV_REG078_LN0_ANA_RX_LLB_RLOAD_CTRL_SHIFT (2U)
/*! LN0_ANA_RX_LLB_RLOAD_CTRL - Line loopback load resistance control */
#define PCIE_PHY_TRSV_REG078_LN0_ANA_RX_LLB_RLOAD_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG078_LN0_ANA_RX_LLB_RLOAD_CTRL_SHIFT)) & PCIE_PHY_TRSV_REG078_LN0_ANA_RX_LLB_RLOAD_CTRL_MASK)
/*! @} */

/*! @name TRSV_REG079 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG079_LN0_ANA_RX_ATB_SEL_MASK (0x3FU)
#define PCIE_PHY_TRSV_REG079_LN0_ANA_RX_ATB_SEL_SHIFT (0U)
/*! LN0_ANA_RX_ATB_SEL - When i_sfr_rx_atb_en=1 and i_sfr_rx_atb_sel&lt;5&gt;=0, RX AFE nodes are under monitoring. */
#define PCIE_PHY_TRSV_REG079_LN0_ANA_RX_ATB_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG079_LN0_ANA_RX_ATB_SEL_SHIFT)) & PCIE_PHY_TRSV_REG079_LN0_ANA_RX_ATB_SEL_MASK)
/*! @} */

/*! @name TRSV_REG07A -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG07A_LN0_ANA_RX_RESERVED_MASK (0xFFU)
#define PCIE_PHY_TRSV_REG07A_LN0_ANA_RX_RESERVED_SHIFT (0U)
/*! LN0_ANA_RX_RESERVED - Reserved port */
#define PCIE_PHY_TRSV_REG07A_LN0_ANA_RX_RESERVED(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG07A_LN0_ANA_RX_RESERVED_SHIFT)) & PCIE_PHY_TRSV_REG07A_LN0_ANA_RX_RESERVED_MASK)
/*! @} */

/*! @name TRSV_REG07B -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG07B_LN0_RX_OC_EN_MASK   (0x1U)
#define PCIE_PHY_TRSV_REG07B_LN0_RX_OC_EN_SHIFT  (0U)
/*! LN0_RX_OC_EN - RX offset calibration tolerance for average value */
#define PCIE_PHY_TRSV_REG07B_LN0_RX_OC_EN(x)     (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG07B_LN0_RX_OC_EN_SHIFT)) & PCIE_PHY_TRSV_REG07B_LN0_RX_OC_EN_MASK)

#define PCIE_PHY_TRSV_REG07B_LN0_RX_OC_TOL_MASK  (0x6U)
#define PCIE_PHY_TRSV_REG07B_LN0_RX_OC_TOL_SHIFT (1U)
/*! LN0_RX_OC_TOL - RX offset calibration enable */
#define PCIE_PHY_TRSV_REG07B_LN0_RX_OC_TOL(x)    (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG07B_LN0_RX_OC_TOL_SHIFT)) & PCIE_PHY_TRSV_REG07B_LN0_RX_OC_TOL_MASK)

#define PCIE_PHY_TRSV_REG07B_LN0_RX_OC_CNT_SEL_MASK (0x18U)
#define PCIE_PHY_TRSV_REG07B_LN0_RX_OC_CNT_SEL_SHIFT (3U)
/*! LN0_RX_OC_CNT_SEL - RX SQ offset calibraiton counter selection for waiting time */
#define PCIE_PHY_TRSV_REG07B_LN0_RX_OC_CNT_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG07B_LN0_RX_OC_CNT_SEL_SHIFT)) & PCIE_PHY_TRSV_REG07B_LN0_RX_OC_CNT_SEL_MASK)

#define PCIE_PHY_TRSV_REG07B_LN0_RX_OC_TRIAL_CNT_MASK (0xE0U)
#define PCIE_PHY_TRSV_REG07B_LN0_RX_OC_TRIAL_CNT_SHIFT (5U)
/*! LN0_RX_OC_TRIAL_CNT - RX offset calibration trial number selection */
#define PCIE_PHY_TRSV_REG07B_LN0_RX_OC_TRIAL_CNT(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG07B_LN0_RX_OC_TRIAL_CNT_SHIFT)) & PCIE_PHY_TRSV_REG07B_LN0_RX_OC_TRIAL_CNT_MASK)
/*! @} */

/*! @name TRSV_REG07C -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG07C_LN0_RX_OC_BYPASS_DFE_ADDER_EVEN_FINAL_MASK (0x1U)
#define PCIE_PHY_TRSV_REG07C_LN0_RX_OC_BYPASS_DFE_ADDER_EVEN_FINAL_SHIFT (0U)
#define PCIE_PHY_TRSV_REG07C_LN0_RX_OC_BYPASS_DFE_ADDER_EVEN_FINAL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG07C_LN0_RX_OC_BYPASS_DFE_ADDER_EVEN_FINAL_SHIFT)) & PCIE_PHY_TRSV_REG07C_LN0_RX_OC_BYPASS_DFE_ADDER_EVEN_FINAL_MASK)

#define PCIE_PHY_TRSV_REG07C_LN0_RX_OC_BYPASS_DFE_ADDER_ODD_FINAL_MASK (0x2U)
#define PCIE_PHY_TRSV_REG07C_LN0_RX_OC_BYPASS_DFE_ADDER_ODD_FINAL_SHIFT (1U)
#define PCIE_PHY_TRSV_REG07C_LN0_RX_OC_BYPASS_DFE_ADDER_ODD_FINAL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG07C_LN0_RX_OC_BYPASS_DFE_ADDER_ODD_FINAL_SHIFT)) & PCIE_PHY_TRSV_REG07C_LN0_RX_OC_BYPASS_DFE_ADDER_ODD_FINAL_MASK)

#define PCIE_PHY_TRSV_REG07C_LN0_RX_OC_BYPASS_DFE_SA_EDGE_EVEN_MASK (0x4U)
#define PCIE_PHY_TRSV_REG07C_LN0_RX_OC_BYPASS_DFE_SA_EDGE_EVEN_SHIFT (2U)
#define PCIE_PHY_TRSV_REG07C_LN0_RX_OC_BYPASS_DFE_SA_EDGE_EVEN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG07C_LN0_RX_OC_BYPASS_DFE_SA_EDGE_EVEN_SHIFT)) & PCIE_PHY_TRSV_REG07C_LN0_RX_OC_BYPASS_DFE_SA_EDGE_EVEN_MASK)

#define PCIE_PHY_TRSV_REG07C_LN0_RX_OC_BYPASS_DFE_SA_EDGE_ODD_MASK (0x8U)
#define PCIE_PHY_TRSV_REG07C_LN0_RX_OC_BYPASS_DFE_SA_EDGE_ODD_SHIFT (3U)
#define PCIE_PHY_TRSV_REG07C_LN0_RX_OC_BYPASS_DFE_SA_EDGE_ODD(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG07C_LN0_RX_OC_BYPASS_DFE_SA_EDGE_ODD_SHIFT)) & PCIE_PHY_TRSV_REG07C_LN0_RX_OC_BYPASS_DFE_SA_EDGE_ODD_MASK)

#define PCIE_PHY_TRSV_REG07C_LN0_RX_OC_BYPASS_DFE_SA_ERR_EVEN_MASK (0x10U)
#define PCIE_PHY_TRSV_REG07C_LN0_RX_OC_BYPASS_DFE_SA_ERR_EVEN_SHIFT (4U)
#define PCIE_PHY_TRSV_REG07C_LN0_RX_OC_BYPASS_DFE_SA_ERR_EVEN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG07C_LN0_RX_OC_BYPASS_DFE_SA_ERR_EVEN_SHIFT)) & PCIE_PHY_TRSV_REG07C_LN0_RX_OC_BYPASS_DFE_SA_ERR_EVEN_MASK)

#define PCIE_PHY_TRSV_REG07C_LN0_RX_OC_BYPASS_DFE_SA_ERR_ODD_MASK (0x20U)
#define PCIE_PHY_TRSV_REG07C_LN0_RX_OC_BYPASS_DFE_SA_ERR_ODD_SHIFT (5U)
/*! LN0_RX_OC_BYPASS_DFE_SA_ERR_ODD - Bypass */
#define PCIE_PHY_TRSV_REG07C_LN0_RX_OC_BYPASS_DFE_SA_ERR_ODD(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG07C_LN0_RX_OC_BYPASS_DFE_SA_ERR_ODD_SHIFT)) & PCIE_PHY_TRSV_REG07C_LN0_RX_OC_BYPASS_DFE_SA_ERR_ODD_MASK)

#define PCIE_PHY_TRSV_REG07C_LN0_RX_OC_UPD_CNT_SEL_MASK (0xC0U)
#define PCIE_PHY_TRSV_REG07C_LN0_RX_OC_UPD_CNT_SEL_SHIFT (6U)
/*! LN0_RX_OC_UPD_CNT_SEL - RX offset calibration code wating time selection for SA & CTLE only */
#define PCIE_PHY_TRSV_REG07C_LN0_RX_OC_UPD_CNT_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG07C_LN0_RX_OC_UPD_CNT_SEL_SHIFT)) & PCIE_PHY_TRSV_REG07C_LN0_RX_OC_UPD_CNT_SEL_MASK)
/*! @} */

/*! @name TRSV_REG07D -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG07D_LN0_RX_OC_DONE_MASK (0x1U)
#define PCIE_PHY_TRSV_REG07D_LN0_RX_OC_DONE_SHIFT (0U)
/*! LN0_RX_OC_DONE - RX offset calibration overide value */
#define PCIE_PHY_TRSV_REG07D_LN0_RX_OC_DONE(x)   (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG07D_LN0_RX_OC_DONE_SHIFT)) & PCIE_PHY_TRSV_REG07D_LN0_RX_OC_DONE_MASK)

#define PCIE_PHY_TRSV_REG07D_LN0_OVRD_RX_OC_DONE_MASK (0x2U)
#define PCIE_PHY_TRSV_REG07D_LN0_OVRD_RX_OC_DONE_SHIFT (1U)
/*! LN0_OVRD_RX_OC_DONE - Override enable for rx_oc_done */
#define PCIE_PHY_TRSV_REG07D_LN0_OVRD_RX_OC_DONE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG07D_LN0_OVRD_RX_OC_DONE_SHIFT)) & PCIE_PHY_TRSV_REG07D_LN0_OVRD_RX_OC_DONE_MASK)

#define PCIE_PHY_TRSV_REG07D_LN0_RX_OC_ALL_RATE_MODE_MASK (0x4U)
#define PCIE_PHY_TRSV_REG07D_LN0_RX_OC_ALL_RATE_MODE_SHIFT (2U)
#define PCIE_PHY_TRSV_REG07D_LN0_RX_OC_ALL_RATE_MODE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG07D_LN0_RX_OC_ALL_RATE_MODE_SHIFT)) & PCIE_PHY_TRSV_REG07D_LN0_RX_OC_ALL_RATE_MODE_MASK)

#define PCIE_PHY_TRSV_REG07D_LN0_RX_OC_BYPASS_CTLE_MASK (0x8U)
#define PCIE_PHY_TRSV_REG07D_LN0_RX_OC_BYPASS_CTLE_SHIFT (3U)
/*! LN0_RX_OC_BYPASS_CTLE - Bypass offset calibration for CTLE */
#define PCIE_PHY_TRSV_REG07D_LN0_RX_OC_BYPASS_CTLE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG07D_LN0_RX_OC_BYPASS_CTLE_SHIFT)) & PCIE_PHY_TRSV_REG07D_LN0_RX_OC_BYPASS_CTLE_MASK)

#define PCIE_PHY_TRSV_REG07D_LN0_RX_OC_BYPASS_RX_SQ_DIFP_MASK (0x10U)
#define PCIE_PHY_TRSV_REG07D_LN0_RX_OC_BYPASS_RX_SQ_DIFP_SHIFT (4U)
#define PCIE_PHY_TRSV_REG07D_LN0_RX_OC_BYPASS_RX_SQ_DIFP(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG07D_LN0_RX_OC_BYPASS_RX_SQ_DIFP_SHIFT)) & PCIE_PHY_TRSV_REG07D_LN0_RX_OC_BYPASS_RX_SQ_DIFP_MASK)

#define PCIE_PHY_TRSV_REG07D_LN0_RX_OC_BYPASS_RX_SQ_DIFN_MASK (0x20U)
#define PCIE_PHY_TRSV_REG07D_LN0_RX_OC_BYPASS_RX_SQ_DIFN_SHIFT (5U)
#define PCIE_PHY_TRSV_REG07D_LN0_RX_OC_BYPASS_RX_SQ_DIFN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG07D_LN0_RX_OC_BYPASS_RX_SQ_DIFN_SHIFT)) & PCIE_PHY_TRSV_REG07D_LN0_RX_OC_BYPASS_RX_SQ_DIFN_MASK)

#define PCIE_PHY_TRSV_REG07D_LN0_RX_OC_BYPASS_DFE_ADDER_EVEN_INIT_MASK (0x40U)
#define PCIE_PHY_TRSV_REG07D_LN0_RX_OC_BYPASS_DFE_ADDER_EVEN_INIT_SHIFT (6U)
#define PCIE_PHY_TRSV_REG07D_LN0_RX_OC_BYPASS_DFE_ADDER_EVEN_INIT(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG07D_LN0_RX_OC_BYPASS_DFE_ADDER_EVEN_INIT_SHIFT)) & PCIE_PHY_TRSV_REG07D_LN0_RX_OC_BYPASS_DFE_ADDER_EVEN_INIT_MASK)
/*! @} */

/*! @name TRSV_REG07E -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG07E_LN0_RX_SSLMS_C0_INIT_MASK (0xFFU)
#define PCIE_PHY_TRSV_REG07E_LN0_RX_SSLMS_C0_INIT_SHIFT (0U)
#define PCIE_PHY_TRSV_REG07E_LN0_RX_SSLMS_C0_INIT(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG07E_LN0_RX_SSLMS_C0_INIT_SHIFT)) & PCIE_PHY_TRSV_REG07E_LN0_RX_SSLMS_C0_INIT_MASK)
/*! @} */

/*! @name TRSV_REG07F -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG07F_LN0_RX_SSLMS_C2_SGN_INIT_MASK (0x1U)
#define PCIE_PHY_TRSV_REG07F_LN0_RX_SSLMS_C2_SGN_INIT_SHIFT (0U)
#define PCIE_PHY_TRSV_REG07F_LN0_RX_SSLMS_C2_SGN_INIT(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG07F_LN0_RX_SSLMS_C2_SGN_INIT_SHIFT)) & PCIE_PHY_TRSV_REG07F_LN0_RX_SSLMS_C2_SGN_INIT_MASK)

#define PCIE_PHY_TRSV_REG07F_LN0_RX_SSLMS_C1_INIT_MASK (0x7EU)
#define PCIE_PHY_TRSV_REG07F_LN0_RX_SSLMS_C1_INIT_SHIFT (1U)
#define PCIE_PHY_TRSV_REG07F_LN0_RX_SSLMS_C1_INIT(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG07F_LN0_RX_SSLMS_C1_INIT_SHIFT)) & PCIE_PHY_TRSV_REG07F_LN0_RX_SSLMS_C1_INIT_MASK)
/*! @} */

/*! @name TRSV_REG080 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG080_LN0_RX_SSLMS_C3_SGN_INIT_MASK (0x1U)
#define PCIE_PHY_TRSV_REG080_LN0_RX_SSLMS_C3_SGN_INIT_SHIFT (0U)
#define PCIE_PHY_TRSV_REG080_LN0_RX_SSLMS_C3_SGN_INIT(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG080_LN0_RX_SSLMS_C3_SGN_INIT_SHIFT)) & PCIE_PHY_TRSV_REG080_LN0_RX_SSLMS_C3_SGN_INIT_MASK)

#define PCIE_PHY_TRSV_REG080_LN0_RX_SSLMS_C2_INIT_MASK (0x3EU)
#define PCIE_PHY_TRSV_REG080_LN0_RX_SSLMS_C2_INIT_SHIFT (1U)
#define PCIE_PHY_TRSV_REG080_LN0_RX_SSLMS_C2_INIT(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG080_LN0_RX_SSLMS_C2_INIT_SHIFT)) & PCIE_PHY_TRSV_REG080_LN0_RX_SSLMS_C2_INIT_MASK)
/*! @} */

/*! @name TRSV_REG081 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG081_LN0_RX_SSLMS_C4_SGN_INIT_MASK (0x1U)
#define PCIE_PHY_TRSV_REG081_LN0_RX_SSLMS_C4_SGN_INIT_SHIFT (0U)
#define PCIE_PHY_TRSV_REG081_LN0_RX_SSLMS_C4_SGN_INIT(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG081_LN0_RX_SSLMS_C4_SGN_INIT_SHIFT)) & PCIE_PHY_TRSV_REG081_LN0_RX_SSLMS_C4_SGN_INIT_MASK)

#define PCIE_PHY_TRSV_REG081_LN0_RX_SSLMS_C3_INIT_MASK (0x3EU)
#define PCIE_PHY_TRSV_REG081_LN0_RX_SSLMS_C3_INIT_SHIFT (1U)
#define PCIE_PHY_TRSV_REG081_LN0_RX_SSLMS_C3_INIT(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG081_LN0_RX_SSLMS_C3_INIT_SHIFT)) & PCIE_PHY_TRSV_REG081_LN0_RX_SSLMS_C3_INIT_MASK)
/*! @} */

/*! @name TRSV_REG082 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG082_LN0_RX_SSLMS_C5_SGN_INIT_MASK (0x1U)
#define PCIE_PHY_TRSV_REG082_LN0_RX_SSLMS_C5_SGN_INIT_SHIFT (0U)
#define PCIE_PHY_TRSV_REG082_LN0_RX_SSLMS_C5_SGN_INIT(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG082_LN0_RX_SSLMS_C5_SGN_INIT_SHIFT)) & PCIE_PHY_TRSV_REG082_LN0_RX_SSLMS_C5_SGN_INIT_MASK)

#define PCIE_PHY_TRSV_REG082_LN0_RX_SSLMS_C4_INIT_MASK (0x1EU)
#define PCIE_PHY_TRSV_REG082_LN0_RX_SSLMS_C4_INIT_SHIFT (1U)
#define PCIE_PHY_TRSV_REG082_LN0_RX_SSLMS_C4_INIT(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG082_LN0_RX_SSLMS_C4_INIT_SHIFT)) & PCIE_PHY_TRSV_REG082_LN0_RX_SSLMS_C4_INIT_MASK)
/*! @} */

/*! @name TRSV_REG083 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG083_LN0_RX_SSLMS_C1_ADAP_SPEED_MASK (0x3U)
#define PCIE_PHY_TRSV_REG083_LN0_RX_SSLMS_C1_ADAP_SPEED_SHIFT (0U)
/*! LN0_RX_SSLMS_C1_ADAP_SPEED - RX DFE SSLMS c1 adaptation speed selection */
#define PCIE_PHY_TRSV_REG083_LN0_RX_SSLMS_C1_ADAP_SPEED(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG083_LN0_RX_SSLMS_C1_ADAP_SPEED_SHIFT)) & PCIE_PHY_TRSV_REG083_LN0_RX_SSLMS_C1_ADAP_SPEED_MASK)

#define PCIE_PHY_TRSV_REG083_LN0_RX_SSLMS_C0_ADAP_SPEED_MASK (0xCU)
#define PCIE_PHY_TRSV_REG083_LN0_RX_SSLMS_C0_ADAP_SPEED_SHIFT (2U)
/*! LN0_RX_SSLMS_C0_ADAP_SPEED - RX DFE SSLMS c0 adaptation speed selection */
#define PCIE_PHY_TRSV_REG083_LN0_RX_SSLMS_C0_ADAP_SPEED(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG083_LN0_RX_SSLMS_C0_ADAP_SPEED_SHIFT)) & PCIE_PHY_TRSV_REG083_LN0_RX_SSLMS_C0_ADAP_SPEED_MASK)

#define PCIE_PHY_TRSV_REG083_LN0_RX_SSLMS_C5_INIT_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG083_LN0_RX_SSLMS_C5_INIT_SHIFT (4U)
#define PCIE_PHY_TRSV_REG083_LN0_RX_SSLMS_C5_INIT(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG083_LN0_RX_SSLMS_C5_INIT_SHIFT)) & PCIE_PHY_TRSV_REG083_LN0_RX_SSLMS_C5_INIT_MASK)
/*! @} */

/*! @name TRSV_REG084 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG084_LN0_RX_SSLMS_C2_ADAP_GAIN_MASK (0x3U)
#define PCIE_PHY_TRSV_REG084_LN0_RX_SSLMS_C2_ADAP_GAIN_SHIFT (0U)
#define PCIE_PHY_TRSV_REG084_LN0_RX_SSLMS_C2_ADAP_GAIN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG084_LN0_RX_SSLMS_C2_ADAP_GAIN_SHIFT)) & PCIE_PHY_TRSV_REG084_LN0_RX_SSLMS_C2_ADAP_GAIN_MASK)

#define PCIE_PHY_TRSV_REG084_LN0_RX_SSLMS_C1_ADAP_GAIN_MASK (0xCU)
#define PCIE_PHY_TRSV_REG084_LN0_RX_SSLMS_C1_ADAP_GAIN_SHIFT (2U)
#define PCIE_PHY_TRSV_REG084_LN0_RX_SSLMS_C1_ADAP_GAIN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG084_LN0_RX_SSLMS_C1_ADAP_GAIN_SHIFT)) & PCIE_PHY_TRSV_REG084_LN0_RX_SSLMS_C1_ADAP_GAIN_MASK)

#define PCIE_PHY_TRSV_REG084_LN0_RX_SSLMS_C0_ADAP_GAIN_MASK (0x30U)
#define PCIE_PHY_TRSV_REG084_LN0_RX_SSLMS_C0_ADAP_GAIN_SHIFT (4U)
#define PCIE_PHY_TRSV_REG084_LN0_RX_SSLMS_C0_ADAP_GAIN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG084_LN0_RX_SSLMS_C0_ADAP_GAIN_SHIFT)) & PCIE_PHY_TRSV_REG084_LN0_RX_SSLMS_C0_ADAP_GAIN_MASK)

#define PCIE_PHY_TRSV_REG084_LN0_RX_SSLMS_C2_ADAP_SPEED_MASK (0xC0U)
#define PCIE_PHY_TRSV_REG084_LN0_RX_SSLMS_C2_ADAP_SPEED_SHIFT (6U)
/*! LN0_RX_SSLMS_C2_ADAP_SPEED - RX DFE SSLMS c2 adaptation speed selection */
#define PCIE_PHY_TRSV_REG084_LN0_RX_SSLMS_C2_ADAP_SPEED(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG084_LN0_RX_SSLMS_C2_ADAP_SPEED_SHIFT)) & PCIE_PHY_TRSV_REG084_LN0_RX_SSLMS_C2_ADAP_SPEED_MASK)
/*! @} */

/*! @name TRSV_REG085 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG085_LN0_RX_SSLMS_ADAP_TOL_MASK (0x3U)
#define PCIE_PHY_TRSV_REG085_LN0_RX_SSLMS_ADAP_TOL_SHIFT (0U)
#define PCIE_PHY_TRSV_REG085_LN0_RX_SSLMS_ADAP_TOL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG085_LN0_RX_SSLMS_ADAP_TOL_SHIFT)) & PCIE_PHY_TRSV_REG085_LN0_RX_SSLMS_ADAP_TOL_MASK)

#define PCIE_PHY_TRSV_REG085_LN0_RX_SSLMS_ADAP_STAB_MASK (0xCU)
#define PCIE_PHY_TRSV_REG085_LN0_RX_SSLMS_ADAP_STAB_SHIFT (2U)
#define PCIE_PHY_TRSV_REG085_LN0_RX_SSLMS_ADAP_STAB(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG085_LN0_RX_SSLMS_ADAP_STAB_SHIFT)) & PCIE_PHY_TRSV_REG085_LN0_RX_SSLMS_ADAP_STAB_MASK)

#define PCIE_PHY_TRSV_REG085_LN0_RX_SSLMS_STAB_CONT_MASK (0x10U)
#define PCIE_PHY_TRSV_REG085_LN0_RX_SSLMS_STAB_CONT_SHIFT (4U)
#define PCIE_PHY_TRSV_REG085_LN0_RX_SSLMS_STAB_CONT(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG085_LN0_RX_SSLMS_STAB_CONT_SHIFT)) & PCIE_PHY_TRSV_REG085_LN0_RX_SSLMS_STAB_CONT_MASK)
/*! @} */

/*! @name TRSV_REG086 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG086_LN0_RX_SSLMS_ADAP_CONT_MASK (0x1U)
#define PCIE_PHY_TRSV_REG086_LN0_RX_SSLMS_ADAP_CONT_SHIFT (0U)
#define PCIE_PHY_TRSV_REG086_LN0_RX_SSLMS_ADAP_CONT(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG086_LN0_RX_SSLMS_ADAP_CONT_SHIFT)) & PCIE_PHY_TRSV_REG086_LN0_RX_SSLMS_ADAP_CONT_MASK)

#define PCIE_PHY_TRSV_REG086_LN0_RX_SSLMS_ADAP_COEF_CHK_MASK (0x2U)
#define PCIE_PHY_TRSV_REG086_LN0_RX_SSLMS_ADAP_COEF_CHK_SHIFT (1U)
#define PCIE_PHY_TRSV_REG086_LN0_RX_SSLMS_ADAP_COEF_CHK(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG086_LN0_RX_SSLMS_ADAP_COEF_CHK_SHIFT)) & PCIE_PHY_TRSV_REG086_LN0_RX_SSLMS_ADAP_COEF_CHK_MASK)

#define PCIE_PHY_TRSV_REG086_LN0_RX_SSLMS_ADAP_COEF_SEL_MASK (0xFCU)
#define PCIE_PHY_TRSV_REG086_LN0_RX_SSLMS_ADAP_COEF_SEL_SHIFT (2U)
#define PCIE_PHY_TRSV_REG086_LN0_RX_SSLMS_ADAP_COEF_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG086_LN0_RX_SSLMS_ADAP_COEF_SEL_SHIFT)) & PCIE_PHY_TRSV_REG086_LN0_RX_SSLMS_ADAP_COEF_SEL_MASK)
/*! @} */

/*! @name TRSV_REG087 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG087_LN0_RX_SSLMS_ADAP_HOLD_MASK (0x1U)
#define PCIE_PHY_TRSV_REG087_LN0_RX_SSLMS_ADAP_HOLD_SHIFT (0U)
#define PCIE_PHY_TRSV_REG087_LN0_RX_SSLMS_ADAP_HOLD(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG087_LN0_RX_SSLMS_ADAP_HOLD_SHIFT)) & PCIE_PHY_TRSV_REG087_LN0_RX_SSLMS_ADAP_HOLD_MASK)

#define PCIE_PHY_TRSV_REG087_LN0_OVRD_RX_SSLMS_ADAP_HOLD_MASK (0x2U)
#define PCIE_PHY_TRSV_REG087_LN0_OVRD_RX_SSLMS_ADAP_HOLD_SHIFT (1U)
/*! LN0_OVRD_RX_SSLMS_ADAP_HOLD - Override enable for rx_sslms_adap_hold */
#define PCIE_PHY_TRSV_REG087_LN0_OVRD_RX_SSLMS_ADAP_HOLD(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG087_LN0_OVRD_RX_SSLMS_ADAP_HOLD_SHIFT)) & PCIE_PHY_TRSV_REG087_LN0_OVRD_RX_SSLMS_ADAP_HOLD_MASK)

#define PCIE_PHY_TRSV_REG087_LN0_RX_SSLMS_ADAP_EN_MASK (0x4U)
#define PCIE_PHY_TRSV_REG087_LN0_RX_SSLMS_ADAP_EN_SHIFT (2U)
#define PCIE_PHY_TRSV_REG087_LN0_RX_SSLMS_ADAP_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG087_LN0_RX_SSLMS_ADAP_EN_SHIFT)) & PCIE_PHY_TRSV_REG087_LN0_RX_SSLMS_ADAP_EN_MASK)

#define PCIE_PHY_TRSV_REG087_LN0_OVRD_RX_SSLMS_ADAP_EN_MASK (0x8U)
#define PCIE_PHY_TRSV_REG087_LN0_OVRD_RX_SSLMS_ADAP_EN_SHIFT (3U)
/*! LN0_OVRD_RX_SSLMS_ADAP_EN - Override enable for rx_sslms_adap_en */
#define PCIE_PHY_TRSV_REG087_LN0_OVRD_RX_SSLMS_ADAP_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG087_LN0_OVRD_RX_SSLMS_ADAP_EN_SHIFT)) & PCIE_PHY_TRSV_REG087_LN0_OVRD_RX_SSLMS_ADAP_EN_MASK)

#define PCIE_PHY_TRSV_REG087_LN0_RX_SSLMS_RSTN_MASK (0x10U)
#define PCIE_PHY_TRSV_REG087_LN0_RX_SSLMS_RSTN_SHIFT (4U)
#define PCIE_PHY_TRSV_REG087_LN0_RX_SSLMS_RSTN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG087_LN0_RX_SSLMS_RSTN_SHIFT)) & PCIE_PHY_TRSV_REG087_LN0_RX_SSLMS_RSTN_MASK)

#define PCIE_PHY_TRSV_REG087_LN0_RX_SSLMS_ADAP_TIMEOUT_EN_MASK (0x20U)
#define PCIE_PHY_TRSV_REG087_LN0_RX_SSLMS_ADAP_TIMEOUT_EN_SHIFT (5U)
#define PCIE_PHY_TRSV_REG087_LN0_RX_SSLMS_ADAP_TIMEOUT_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG087_LN0_RX_SSLMS_ADAP_TIMEOUT_EN_SHIFT)) & PCIE_PHY_TRSV_REG087_LN0_RX_SSLMS_ADAP_TIMEOUT_EN_MASK)

#define PCIE_PHY_TRSV_REG087_LN0_RX_SSLMS_ADAP_TIMEOUT_SEL_MASK (0xC0U)
#define PCIE_PHY_TRSV_REG087_LN0_RX_SSLMS_ADAP_TIMEOUT_SEL_SHIFT (6U)
#define PCIE_PHY_TRSV_REG087_LN0_RX_SSLMS_ADAP_TIMEOUT_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG087_LN0_RX_SSLMS_ADAP_TIMEOUT_SEL_SHIFT)) & PCIE_PHY_TRSV_REG087_LN0_RX_SSLMS_ADAP_TIMEOUT_SEL_MASK)
/*! @} */

/*! @name TRSV_REG088 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG088_LN0_RX_CDR_PMS_M_G1__8_MASK (0x1U)
#define PCIE_PHY_TRSV_REG088_LN0_RX_CDR_PMS_M_G1__8_SHIFT (0U)
#define PCIE_PHY_TRSV_REG088_LN0_RX_CDR_PMS_M_G1__8(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG088_LN0_RX_CDR_PMS_M_G1__8_SHIFT)) & PCIE_PHY_TRSV_REG088_LN0_RX_CDR_PMS_M_G1__8_MASK)
/*! @} */

/*! @name TRSV_REG089 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG089_LN0_RX_CDR_PMS_M_G1__7_0_MASK (0xFFU)
#define PCIE_PHY_TRSV_REG089_LN0_RX_CDR_PMS_M_G1__7_0_SHIFT (0U)
#define PCIE_PHY_TRSV_REG089_LN0_RX_CDR_PMS_M_G1__7_0(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG089_LN0_RX_CDR_PMS_M_G1__7_0_SHIFT)) & PCIE_PHY_TRSV_REG089_LN0_RX_CDR_PMS_M_G1__7_0_MASK)
/*! @} */

/*! @name TRSV_REG08A -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG08A_LN0_RX_CDR_PMS_M_G2__8_MASK (0x1U)
#define PCIE_PHY_TRSV_REG08A_LN0_RX_CDR_PMS_M_G2__8_SHIFT (0U)
#define PCIE_PHY_TRSV_REG08A_LN0_RX_CDR_PMS_M_G2__8(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG08A_LN0_RX_CDR_PMS_M_G2__8_SHIFT)) & PCIE_PHY_TRSV_REG08A_LN0_RX_CDR_PMS_M_G2__8_MASK)
/*! @} */

/*! @name TRSV_REG08B -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG08B_LN0_RX_CDR_PMS_M_G2__7_0_MASK (0xFFU)
#define PCIE_PHY_TRSV_REG08B_LN0_RX_CDR_PMS_M_G2__7_0_SHIFT (0U)
#define PCIE_PHY_TRSV_REG08B_LN0_RX_CDR_PMS_M_G2__7_0(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG08B_LN0_RX_CDR_PMS_M_G2__7_0_SHIFT)) & PCIE_PHY_TRSV_REG08B_LN0_RX_CDR_PMS_M_G2__7_0_MASK)
/*! @} */

/*! @name TRSV_REG08C -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG08C_LN0_RX_CDR_PMS_M_G3__8_MASK (0x1U)
#define PCIE_PHY_TRSV_REG08C_LN0_RX_CDR_PMS_M_G3__8_SHIFT (0U)
#define PCIE_PHY_TRSV_REG08C_LN0_RX_CDR_PMS_M_G3__8(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG08C_LN0_RX_CDR_PMS_M_G3__8_SHIFT)) & PCIE_PHY_TRSV_REG08C_LN0_RX_CDR_PMS_M_G3__8_MASK)
/*! @} */

/*! @name TRSV_REG08D -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG08D_LN0_RX_CDR_PMS_M_G3__7_0_MASK (0xFFU)
#define PCIE_PHY_TRSV_REG08D_LN0_RX_CDR_PMS_M_G3__7_0_SHIFT (0U)
#define PCIE_PHY_TRSV_REG08D_LN0_RX_CDR_PMS_M_G3__7_0(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG08D_LN0_RX_CDR_PMS_M_G3__7_0_SHIFT)) & PCIE_PHY_TRSV_REG08D_LN0_RX_CDR_PMS_M_G3__7_0_MASK)
/*! @} */

/*! @name TRSV_REG08E -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG08E_LN0_RX_CDR_PMS_M_G4__8_MASK (0x1U)
#define PCIE_PHY_TRSV_REG08E_LN0_RX_CDR_PMS_M_G4__8_SHIFT (0U)
#define PCIE_PHY_TRSV_REG08E_LN0_RX_CDR_PMS_M_G4__8(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG08E_LN0_RX_CDR_PMS_M_G4__8_SHIFT)) & PCIE_PHY_TRSV_REG08E_LN0_RX_CDR_PMS_M_G4__8_MASK)
/*! @} */

/*! @name TRSV_REG08F -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG08F_LN0_RX_CDR_PMS_M_G4__7_0_MASK (0xFFU)
#define PCIE_PHY_TRSV_REG08F_LN0_RX_CDR_PMS_M_G4__7_0_SHIFT (0U)
#define PCIE_PHY_TRSV_REG08F_LN0_RX_CDR_PMS_M_G4__7_0(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG08F_LN0_RX_CDR_PMS_M_G4__7_0_SHIFT)) & PCIE_PHY_TRSV_REG08F_LN0_RX_CDR_PMS_M_G4__7_0_MASK)
/*! @} */

/*! @name TRSV_REG090 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG090_LN0_RX_CDR_AFC_STB_NUM_MASK (0xFU)
#define PCIE_PHY_TRSV_REG090_LN0_RX_CDR_AFC_STB_NUM_SHIFT (0U)
#define PCIE_PHY_TRSV_REG090_LN0_RX_CDR_AFC_STB_NUM(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG090_LN0_RX_CDR_AFC_STB_NUM_SHIFT)) & PCIE_PHY_TRSV_REG090_LN0_RX_CDR_AFC_STB_NUM_MASK)

#define PCIE_PHY_TRSV_REG090_LN0_RX_CDR_AFC_INIT_RSTN_MASK (0x10U)
#define PCIE_PHY_TRSV_REG090_LN0_RX_CDR_AFC_INIT_RSTN_SHIFT (4U)
#define PCIE_PHY_TRSV_REG090_LN0_RX_CDR_AFC_INIT_RSTN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG090_LN0_RX_CDR_AFC_INIT_RSTN_SHIFT)) & PCIE_PHY_TRSV_REG090_LN0_RX_CDR_AFC_INIT_RSTN_MASK)

#define PCIE_PHY_TRSV_REG090_LN0_OVRD_RX_CDR_AFC_INIT_RSTN_MASK (0x20U)
#define PCIE_PHY_TRSV_REG090_LN0_OVRD_RX_CDR_AFC_INIT_RSTN_SHIFT (5U)
/*! LN0_OVRD_RX_CDR_AFC_INIT_RSTN - Override enable for rx_cdr_afc_init_rstn */
#define PCIE_PHY_TRSV_REG090_LN0_OVRD_RX_CDR_AFC_INIT_RSTN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG090_LN0_OVRD_RX_CDR_AFC_INIT_RSTN_SHIFT)) & PCIE_PHY_TRSV_REG090_LN0_OVRD_RX_CDR_AFC_INIT_RSTN_MASK)

#define PCIE_PHY_TRSV_REG090_LN0_RX_CDR_AFC_RSTN_MASK (0x40U)
#define PCIE_PHY_TRSV_REG090_LN0_RX_CDR_AFC_RSTN_SHIFT (6U)
#define PCIE_PHY_TRSV_REG090_LN0_RX_CDR_AFC_RSTN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG090_LN0_RX_CDR_AFC_RSTN_SHIFT)) & PCIE_PHY_TRSV_REG090_LN0_RX_CDR_AFC_RSTN_MASK)

#define PCIE_PHY_TRSV_REG090_LN0_OVRD_RX_CDR_AFC_RSTN_MASK (0x80U)
#define PCIE_PHY_TRSV_REG090_LN0_OVRD_RX_CDR_AFC_RSTN_SHIFT (7U)
/*! LN0_OVRD_RX_CDR_AFC_RSTN - Override enable for rx_cdr_afc_rstn */
#define PCIE_PHY_TRSV_REG090_LN0_OVRD_RX_CDR_AFC_RSTN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG090_LN0_OVRD_RX_CDR_AFC_RSTN_SHIFT)) & PCIE_PHY_TRSV_REG090_LN0_OVRD_RX_CDR_AFC_RSTN_MASK)
/*! @} */

/*! @name TRSV_REG091 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG091_LN0_RX_CDR_AFC_TOL_MASK (0xFU)
#define PCIE_PHY_TRSV_REG091_LN0_RX_CDR_AFC_TOL_SHIFT (0U)
#define PCIE_PHY_TRSV_REG091_LN0_RX_CDR_AFC_TOL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG091_LN0_RX_CDR_AFC_TOL_SHIFT)) & PCIE_PHY_TRSV_REG091_LN0_RX_CDR_AFC_TOL_MASK)
/*! @} */

/*! @name TRSV_REG092 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG092_LN0_RX_CDR_AFC_VCO_CNT_RUN_NO_MASK (0x1FU)
#define PCIE_PHY_TRSV_REG092_LN0_RX_CDR_AFC_VCO_CNT_RUN_NO_SHIFT (0U)
#define PCIE_PHY_TRSV_REG092_LN0_RX_CDR_AFC_VCO_CNT_RUN_NO(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG092_LN0_RX_CDR_AFC_VCO_CNT_RUN_NO_SHIFT)) & PCIE_PHY_TRSV_REG092_LN0_RX_CDR_AFC_VCO_CNT_RUN_NO_MASK)
/*! @} */

/*! @name TRSV_REG093 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG093_LN0_RX_CDR_AFC_FIX_CODE_MASK (0x1U)
#define PCIE_PHY_TRSV_REG093_LN0_RX_CDR_AFC_FIX_CODE_SHIFT (0U)
#define PCIE_PHY_TRSV_REG093_LN0_RX_CDR_AFC_FIX_CODE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG093_LN0_RX_CDR_AFC_FIX_CODE_SHIFT)) & PCIE_PHY_TRSV_REG093_LN0_RX_CDR_AFC_FIX_CODE_MASK)

#define PCIE_PHY_TRSV_REG093_LN0_RX_CDR_AFC_VCO_CNT_WAIT_MASK (0x1EU)
#define PCIE_PHY_TRSV_REG093_LN0_RX_CDR_AFC_VCO_CNT_WAIT_SHIFT (1U)
#define PCIE_PHY_TRSV_REG093_LN0_RX_CDR_AFC_VCO_CNT_WAIT(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG093_LN0_RX_CDR_AFC_VCO_CNT_WAIT_SHIFT)) & PCIE_PHY_TRSV_REG093_LN0_RX_CDR_AFC_VCO_CNT_WAIT_MASK)
/*! @} */

/*! @name TRSV_REG094 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG094_LN0_RX_CDR_AFC_MAN_BSEL_TIME_MASK (0x1U)
#define PCIE_PHY_TRSV_REG094_LN0_RX_CDR_AFC_MAN_BSEL_TIME_SHIFT (0U)
#define PCIE_PHY_TRSV_REG094_LN0_RX_CDR_AFC_MAN_BSEL_TIME(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG094_LN0_RX_CDR_AFC_MAN_BSEL_TIME_SHIFT)) & PCIE_PHY_TRSV_REG094_LN0_RX_CDR_AFC_MAN_BSEL_TIME_MASK)

#define PCIE_PHY_TRSV_REG094_LN0_RX_CDR_AFC_PRESET_VCO_CNT_MASK (0x1EU)
#define PCIE_PHY_TRSV_REG094_LN0_RX_CDR_AFC_PRESET_VCO_CNT_SHIFT (1U)
#define PCIE_PHY_TRSV_REG094_LN0_RX_CDR_AFC_PRESET_VCO_CNT(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG094_LN0_RX_CDR_AFC_PRESET_VCO_CNT_SHIFT)) & PCIE_PHY_TRSV_REG094_LN0_RX_CDR_AFC_PRESET_VCO_CNT_MASK)
/*! @} */

/*! @name TRSV_REG095 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG095_LN0_RX_CDR_AFC_BSEL_MASK (0x1U)
#define PCIE_PHY_TRSV_REG095_LN0_RX_CDR_AFC_BSEL_SHIFT (0U)
#define PCIE_PHY_TRSV_REG095_LN0_RX_CDR_AFC_BSEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG095_LN0_RX_CDR_AFC_BSEL_SHIFT)) & PCIE_PHY_TRSV_REG095_LN0_RX_CDR_AFC_BSEL_MASK)

#define PCIE_PHY_TRSV_REG095_LN0_RX_CDR_AFC_MAN_BSEL_MASK (0x1EU)
#define PCIE_PHY_TRSV_REG095_LN0_RX_CDR_AFC_MAN_BSEL_SHIFT (1U)
#define PCIE_PHY_TRSV_REG095_LN0_RX_CDR_AFC_MAN_BSEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG095_LN0_RX_CDR_AFC_MAN_BSEL_SHIFT)) & PCIE_PHY_TRSV_REG095_LN0_RX_CDR_AFC_MAN_BSEL_MASK)
/*! @} */

/*! @name TRSV_REG096 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG096_LN0_RX_CDR_FBB_VCO_CNT_RUN_NO_MASK (0x3FU)
#define PCIE_PHY_TRSV_REG096_LN0_RX_CDR_FBB_VCO_CNT_RUN_NO_SHIFT (0U)
#define PCIE_PHY_TRSV_REG096_LN0_RX_CDR_FBB_VCO_CNT_RUN_NO(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG096_LN0_RX_CDR_FBB_VCO_CNT_RUN_NO_SHIFT)) & PCIE_PHY_TRSV_REG096_LN0_RX_CDR_FBB_VCO_CNT_RUN_NO_MASK)
/*! @} */

/*! @name TRSV_REG097 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG097_LN0_RX_CDR_FBB_MAN_SEL_MASK (0x1U)
#define PCIE_PHY_TRSV_REG097_LN0_RX_CDR_FBB_MAN_SEL_SHIFT (0U)
#define PCIE_PHY_TRSV_REG097_LN0_RX_CDR_FBB_MAN_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG097_LN0_RX_CDR_FBB_MAN_SEL_SHIFT)) & PCIE_PHY_TRSV_REG097_LN0_RX_CDR_FBB_MAN_SEL_MASK)

#define PCIE_PHY_TRSV_REG097_LN0_RX_CDR_FBB_VCO_CNT_WAIT_NO_MASK (0x1EU)
#define PCIE_PHY_TRSV_REG097_LN0_RX_CDR_FBB_VCO_CNT_WAIT_NO_SHIFT (1U)
#define PCIE_PHY_TRSV_REG097_LN0_RX_CDR_FBB_VCO_CNT_WAIT_NO(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG097_LN0_RX_CDR_FBB_VCO_CNT_WAIT_NO_SHIFT)) & PCIE_PHY_TRSV_REG097_LN0_RX_CDR_FBB_VCO_CNT_WAIT_NO_MASK)
/*! @} */

/*! @name TRSV_REG098 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG098_LN0_RX_CDR_FBB_MAN_CODE_UPDC_MASK (0xFU)
#define PCIE_PHY_TRSV_REG098_LN0_RX_CDR_FBB_MAN_CODE_UPDC_SHIFT (0U)
#define PCIE_PHY_TRSV_REG098_LN0_RX_CDR_FBB_MAN_CODE_UPDC(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG098_LN0_RX_CDR_FBB_MAN_CODE_UPDC_SHIFT)) & PCIE_PHY_TRSV_REG098_LN0_RX_CDR_FBB_MAN_CODE_UPDC_MASK)
/*! @} */

/*! @name TRSV_REG099 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG099_LN0_RX_CDR_FBB_DELTA_CNT_MASK (0x3FU)
#define PCIE_PHY_TRSV_REG099_LN0_RX_CDR_FBB_DELTA_CNT_SHIFT (0U)
/*! LN0_RX_CDR_FBB_DELTA_CNT - Target delta number in VCO counter in CDR FBB cal mode */
#define PCIE_PHY_TRSV_REG099_LN0_RX_CDR_FBB_DELTA_CNT(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG099_LN0_RX_CDR_FBB_DELTA_CNT_SHIFT)) & PCIE_PHY_TRSV_REG099_LN0_RX_CDR_FBB_DELTA_CNT_MASK)
/*! @} */

/*! @name TRSV_REG09A -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG09A_LN0_RX_CDR_FBB_PLL_MODE_CTRL_G2_MASK (0xFU)
#define PCIE_PHY_TRSV_REG09A_LN0_RX_CDR_FBB_PLL_MODE_CTRL_G2_SHIFT (0U)
/*! LN0_RX_CDR_FBB_PLL_MODE_CTRL_G2 - [GEN2] */
#define PCIE_PHY_TRSV_REG09A_LN0_RX_CDR_FBB_PLL_MODE_CTRL_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG09A_LN0_RX_CDR_FBB_PLL_MODE_CTRL_G2_SHIFT)) & PCIE_PHY_TRSV_REG09A_LN0_RX_CDR_FBB_PLL_MODE_CTRL_G2_MASK)

#define PCIE_PHY_TRSV_REG09A_LN0_RX_CDR_FBB_PLL_MODE_CTRL_G1_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG09A_LN0_RX_CDR_FBB_PLL_MODE_CTRL_G1_SHIFT (4U)
/*! LN0_RX_CDR_FBB_PLL_MODE_CTRL_G1 - [GEN1] RX CDR BBVCO FBB gain control in PLL mode */
#define PCIE_PHY_TRSV_REG09A_LN0_RX_CDR_FBB_PLL_MODE_CTRL_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG09A_LN0_RX_CDR_FBB_PLL_MODE_CTRL_G1_SHIFT)) & PCIE_PHY_TRSV_REG09A_LN0_RX_CDR_FBB_PLL_MODE_CTRL_G1_MASK)
/*! @} */

/*! @name TRSV_REG09B -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG09B_LN0_RX_CDR_FBB_PLL_MODE_CTRL_G4_MASK (0xFU)
#define PCIE_PHY_TRSV_REG09B_LN0_RX_CDR_FBB_PLL_MODE_CTRL_G4_SHIFT (0U)
/*! LN0_RX_CDR_FBB_PLL_MODE_CTRL_G4 - [GEN4] */
#define PCIE_PHY_TRSV_REG09B_LN0_RX_CDR_FBB_PLL_MODE_CTRL_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG09B_LN0_RX_CDR_FBB_PLL_MODE_CTRL_G4_SHIFT)) & PCIE_PHY_TRSV_REG09B_LN0_RX_CDR_FBB_PLL_MODE_CTRL_G4_MASK)

#define PCIE_PHY_TRSV_REG09B_LN0_RX_CDR_FBB_PLL_MODE_CTRL_G3_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG09B_LN0_RX_CDR_FBB_PLL_MODE_CTRL_G3_SHIFT (4U)
/*! LN0_RX_CDR_FBB_PLL_MODE_CTRL_G3 - [GEN3] */
#define PCIE_PHY_TRSV_REG09B_LN0_RX_CDR_FBB_PLL_MODE_CTRL_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG09B_LN0_RX_CDR_FBB_PLL_MODE_CTRL_G3_SHIFT)) & PCIE_PHY_TRSV_REG09B_LN0_RX_CDR_FBB_PLL_MODE_CTRL_G3_MASK)
/*! @} */

/*! @name TRSV_REG09C -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG09C_LN0_RX_CDR_FBB_COARSE_CTRL_G2_MASK (0xFU)
#define PCIE_PHY_TRSV_REG09C_LN0_RX_CDR_FBB_COARSE_CTRL_G2_SHIFT (0U)
/*! LN0_RX_CDR_FBB_COARSE_CTRL_G2 - [GEN2] */
#define PCIE_PHY_TRSV_REG09C_LN0_RX_CDR_FBB_COARSE_CTRL_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG09C_LN0_RX_CDR_FBB_COARSE_CTRL_G2_SHIFT)) & PCIE_PHY_TRSV_REG09C_LN0_RX_CDR_FBB_COARSE_CTRL_G2_MASK)

#define PCIE_PHY_TRSV_REG09C_LN0_RX_CDR_FBB_COARSE_CTRL_G1_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG09C_LN0_RX_CDR_FBB_COARSE_CTRL_G1_SHIFT (4U)
/*! LN0_RX_CDR_FBB_COARSE_CTRL_G1 - [GEN1] RX CDR BBVCO FBB gain control in coarse mode (high bandwidth) */
#define PCIE_PHY_TRSV_REG09C_LN0_RX_CDR_FBB_COARSE_CTRL_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG09C_LN0_RX_CDR_FBB_COARSE_CTRL_G1_SHIFT)) & PCIE_PHY_TRSV_REG09C_LN0_RX_CDR_FBB_COARSE_CTRL_G1_MASK)
/*! @} */

/*! @name TRSV_REG09D -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG09D_LN0_RX_CDR_FBB_COARSE_CTRL_G4_MASK (0xFU)
#define PCIE_PHY_TRSV_REG09D_LN0_RX_CDR_FBB_COARSE_CTRL_G4_SHIFT (0U)
/*! LN0_RX_CDR_FBB_COARSE_CTRL_G4 - [GEN4] */
#define PCIE_PHY_TRSV_REG09D_LN0_RX_CDR_FBB_COARSE_CTRL_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG09D_LN0_RX_CDR_FBB_COARSE_CTRL_G4_SHIFT)) & PCIE_PHY_TRSV_REG09D_LN0_RX_CDR_FBB_COARSE_CTRL_G4_MASK)

#define PCIE_PHY_TRSV_REG09D_LN0_RX_CDR_FBB_COARSE_CTRL_G3_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG09D_LN0_RX_CDR_FBB_COARSE_CTRL_G3_SHIFT (4U)
/*! LN0_RX_CDR_FBB_COARSE_CTRL_G3 - [GEN3] */
#define PCIE_PHY_TRSV_REG09D_LN0_RX_CDR_FBB_COARSE_CTRL_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG09D_LN0_RX_CDR_FBB_COARSE_CTRL_G3_SHIFT)) & PCIE_PHY_TRSV_REG09D_LN0_RX_CDR_FBB_COARSE_CTRL_G3_MASK)
/*! @} */

/*! @name TRSV_REG09E -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG09E_LN0_RX_CDR_FBB_FINE_CTRL_G2_MASK (0xFU)
#define PCIE_PHY_TRSV_REG09E_LN0_RX_CDR_FBB_FINE_CTRL_G2_SHIFT (0U)
/*! LN0_RX_CDR_FBB_FINE_CTRL_G2 - [GEN2] */
#define PCIE_PHY_TRSV_REG09E_LN0_RX_CDR_FBB_FINE_CTRL_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG09E_LN0_RX_CDR_FBB_FINE_CTRL_G2_SHIFT)) & PCIE_PHY_TRSV_REG09E_LN0_RX_CDR_FBB_FINE_CTRL_G2_MASK)

#define PCIE_PHY_TRSV_REG09E_LN0_RX_CDR_FBB_FINE_CTRL_G1_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG09E_LN0_RX_CDR_FBB_FINE_CTRL_G1_SHIFT (4U)
/*! LN0_RX_CDR_FBB_FINE_CTRL_G1 - [GEN1] RX CDR BBVCO FBB gain control in fine mode (low bandwidth) */
#define PCIE_PHY_TRSV_REG09E_LN0_RX_CDR_FBB_FINE_CTRL_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG09E_LN0_RX_CDR_FBB_FINE_CTRL_G1_SHIFT)) & PCIE_PHY_TRSV_REG09E_LN0_RX_CDR_FBB_FINE_CTRL_G1_MASK)
/*! @} */

/*! @name TRSV_REG09F -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG09F_LN0_RX_CDR_FBB_FINE_CTRL_G4_MASK (0xFU)
#define PCIE_PHY_TRSV_REG09F_LN0_RX_CDR_FBB_FINE_CTRL_G4_SHIFT (0U)
/*! LN0_RX_CDR_FBB_FINE_CTRL_G4 - [GEN4] */
#define PCIE_PHY_TRSV_REG09F_LN0_RX_CDR_FBB_FINE_CTRL_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG09F_LN0_RX_CDR_FBB_FINE_CTRL_G4_SHIFT)) & PCIE_PHY_TRSV_REG09F_LN0_RX_CDR_FBB_FINE_CTRL_G4_MASK)

#define PCIE_PHY_TRSV_REG09F_LN0_RX_CDR_FBB_FINE_CTRL_G3_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG09F_LN0_RX_CDR_FBB_FINE_CTRL_G3_SHIFT (4U)
/*! LN0_RX_CDR_FBB_FINE_CTRL_G3 - [GEN3] */
#define PCIE_PHY_TRSV_REG09F_LN0_RX_CDR_FBB_FINE_CTRL_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG09F_LN0_RX_CDR_FBB_FINE_CTRL_G3_SHIFT)) & PCIE_PHY_TRSV_REG09F_LN0_RX_CDR_FBB_FINE_CTRL_G3_MASK)
/*! @} */

/*! @name TRSV_REG0A0 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0A0_LN0_RX_CDR_FBB_PLL_BW_DIFF_G2_MASK (0xFU)
#define PCIE_PHY_TRSV_REG0A0_LN0_RX_CDR_FBB_PLL_BW_DIFF_G2_SHIFT (0U)
/*! LN0_RX_CDR_FBB_PLL_BW_DIFF_G2 - [GEN4] */
#define PCIE_PHY_TRSV_REG0A0_LN0_RX_CDR_FBB_PLL_BW_DIFF_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0A0_LN0_RX_CDR_FBB_PLL_BW_DIFF_G2_SHIFT)) & PCIE_PHY_TRSV_REG0A0_LN0_RX_CDR_FBB_PLL_BW_DIFF_G2_MASK)

#define PCIE_PHY_TRSV_REG0A0_LN0_RX_CDR_FBB_PLL_BW_DIFF_G1_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG0A0_LN0_RX_CDR_FBB_PLL_BW_DIFF_G1_SHIFT (4U)
/*! LN0_RX_CDR_FBB_PLL_BW_DIFF_G1 - [GEN4] */
#define PCIE_PHY_TRSV_REG0A0_LN0_RX_CDR_FBB_PLL_BW_DIFF_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0A0_LN0_RX_CDR_FBB_PLL_BW_DIFF_G1_SHIFT)) & PCIE_PHY_TRSV_REG0A0_LN0_RX_CDR_FBB_PLL_BW_DIFF_G1_MASK)
/*! @} */

/*! @name TRSV_REG0A1 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0A1_LN0_RX_CDR_FBB_PLL_BW_DIFF_G4_MASK (0xFU)
#define PCIE_PHY_TRSV_REG0A1_LN0_RX_CDR_FBB_PLL_BW_DIFF_G4_SHIFT (0U)
/*! LN0_RX_CDR_FBB_PLL_BW_DIFF_G4 - [GEN4] */
#define PCIE_PHY_TRSV_REG0A1_LN0_RX_CDR_FBB_PLL_BW_DIFF_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0A1_LN0_RX_CDR_FBB_PLL_BW_DIFF_G4_SHIFT)) & PCIE_PHY_TRSV_REG0A1_LN0_RX_CDR_FBB_PLL_BW_DIFF_G4_MASK)

#define PCIE_PHY_TRSV_REG0A1_LN0_RX_CDR_FBB_PLL_BW_DIFF_G3_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG0A1_LN0_RX_CDR_FBB_PLL_BW_DIFF_G3_SHIFT (4U)
/*! LN0_RX_CDR_FBB_PLL_BW_DIFF_G3 - [GEN4] */
#define PCIE_PHY_TRSV_REG0A1_LN0_RX_CDR_FBB_PLL_BW_DIFF_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0A1_LN0_RX_CDR_FBB_PLL_BW_DIFF_G3_SHIFT)) & PCIE_PHY_TRSV_REG0A1_LN0_RX_CDR_FBB_PLL_BW_DIFF_G3_MASK)
/*! @} */

/*! @name TRSV_REG0A2 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0A2_LN0_RX_CDR_FBB_HI_BW_DIFF_G2_MASK (0xFU)
#define PCIE_PHY_TRSV_REG0A2_LN0_RX_CDR_FBB_HI_BW_DIFF_G2_SHIFT (0U)
/*! LN0_RX_CDR_FBB_HI_BW_DIFF_G2 - [GEN4] */
#define PCIE_PHY_TRSV_REG0A2_LN0_RX_CDR_FBB_HI_BW_DIFF_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0A2_LN0_RX_CDR_FBB_HI_BW_DIFF_G2_SHIFT)) & PCIE_PHY_TRSV_REG0A2_LN0_RX_CDR_FBB_HI_BW_DIFF_G2_MASK)

#define PCIE_PHY_TRSV_REG0A2_LN0_RX_CDR_FBB_HI_BW_DIFF_G1_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG0A2_LN0_RX_CDR_FBB_HI_BW_DIFF_G1_SHIFT (4U)
/*! LN0_RX_CDR_FBB_HI_BW_DIFF_G1 - [GEN4] */
#define PCIE_PHY_TRSV_REG0A2_LN0_RX_CDR_FBB_HI_BW_DIFF_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0A2_LN0_RX_CDR_FBB_HI_BW_DIFF_G1_SHIFT)) & PCIE_PHY_TRSV_REG0A2_LN0_RX_CDR_FBB_HI_BW_DIFF_G1_MASK)
/*! @} */

/*! @name TRSV_REG0A3 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0A3_LN0_RX_CDR_FBB_HI_BW_DIFF_G4_MASK (0xFU)
#define PCIE_PHY_TRSV_REG0A3_LN0_RX_CDR_FBB_HI_BW_DIFF_G4_SHIFT (0U)
/*! LN0_RX_CDR_FBB_HI_BW_DIFF_G4 - [GEN4] */
#define PCIE_PHY_TRSV_REG0A3_LN0_RX_CDR_FBB_HI_BW_DIFF_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0A3_LN0_RX_CDR_FBB_HI_BW_DIFF_G4_SHIFT)) & PCIE_PHY_TRSV_REG0A3_LN0_RX_CDR_FBB_HI_BW_DIFF_G4_MASK)

#define PCIE_PHY_TRSV_REG0A3_LN0_RX_CDR_FBB_HI_BW_DIFF_G3_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG0A3_LN0_RX_CDR_FBB_HI_BW_DIFF_G3_SHIFT (4U)
/*! LN0_RX_CDR_FBB_HI_BW_DIFF_G3 - [GEN4] */
#define PCIE_PHY_TRSV_REG0A3_LN0_RX_CDR_FBB_HI_BW_DIFF_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0A3_LN0_RX_CDR_FBB_HI_BW_DIFF_G3_SHIFT)) & PCIE_PHY_TRSV_REG0A3_LN0_RX_CDR_FBB_HI_BW_DIFF_G3_MASK)
/*! @} */

/*! @name TRSV_REG0A4 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0A4_LN0_RX_CDR_FBB_LO_BW_DIFF_G2_MASK (0xFU)
#define PCIE_PHY_TRSV_REG0A4_LN0_RX_CDR_FBB_LO_BW_DIFF_G2_SHIFT (0U)
/*! LN0_RX_CDR_FBB_LO_BW_DIFF_G2 - [GEN4] */
#define PCIE_PHY_TRSV_REG0A4_LN0_RX_CDR_FBB_LO_BW_DIFF_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0A4_LN0_RX_CDR_FBB_LO_BW_DIFF_G2_SHIFT)) & PCIE_PHY_TRSV_REG0A4_LN0_RX_CDR_FBB_LO_BW_DIFF_G2_MASK)

#define PCIE_PHY_TRSV_REG0A4_LN0_RX_CDR_FBB_LO_BW_DIFF_G1_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG0A4_LN0_RX_CDR_FBB_LO_BW_DIFF_G1_SHIFT (4U)
/*! LN0_RX_CDR_FBB_LO_BW_DIFF_G1 - [GEN4] */
#define PCIE_PHY_TRSV_REG0A4_LN0_RX_CDR_FBB_LO_BW_DIFF_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0A4_LN0_RX_CDR_FBB_LO_BW_DIFF_G1_SHIFT)) & PCIE_PHY_TRSV_REG0A4_LN0_RX_CDR_FBB_LO_BW_DIFF_G1_MASK)
/*! @} */

/*! @name TRSV_REG0A5 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0A5_LN0_RX_CDR_FBB_LO_BW_DIFF_G4_MASK (0xFU)
#define PCIE_PHY_TRSV_REG0A5_LN0_RX_CDR_FBB_LO_BW_DIFF_G4_SHIFT (0U)
/*! LN0_RX_CDR_FBB_LO_BW_DIFF_G4 - [GEN4] */
#define PCIE_PHY_TRSV_REG0A5_LN0_RX_CDR_FBB_LO_BW_DIFF_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0A5_LN0_RX_CDR_FBB_LO_BW_DIFF_G4_SHIFT)) & PCIE_PHY_TRSV_REG0A5_LN0_RX_CDR_FBB_LO_BW_DIFF_G4_MASK)

#define PCIE_PHY_TRSV_REG0A5_LN0_RX_CDR_FBB_LO_BW_DIFF_G3_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG0A5_LN0_RX_CDR_FBB_LO_BW_DIFF_G3_SHIFT (4U)
/*! LN0_RX_CDR_FBB_LO_BW_DIFF_G3 - [GEN4] */
#define PCIE_PHY_TRSV_REG0A5_LN0_RX_CDR_FBB_LO_BW_DIFF_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0A5_LN0_RX_CDR_FBB_LO_BW_DIFF_G3_SHIFT)) & PCIE_PHY_TRSV_REG0A5_LN0_RX_CDR_FBB_LO_BW_DIFF_G3_MASK)
/*! @} */

/*! @name TRSV_REG0A6 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0A6_LN0_RX_CDR_PLL_VCO_CNT_RUN_NO_MASK (0x1FU)
#define PCIE_PHY_TRSV_REG0A6_LN0_RX_CDR_PLL_VCO_CNT_RUN_NO_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0A6_LN0_RX_CDR_PLL_VCO_CNT_RUN_NO(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0A6_LN0_RX_CDR_PLL_VCO_CNT_RUN_NO_SHIFT)) & PCIE_PHY_TRSV_REG0A6_LN0_RX_CDR_PLL_VCO_CNT_RUN_NO_MASK)
/*! @} */

/*! @name TRSV_REG0A7 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0A7_LN0_RX_CDR_PLL_VCO_CNT_WAIT_NO_MASK (0xFU)
#define PCIE_PHY_TRSV_REG0A7_LN0_RX_CDR_PLL_VCO_CNT_WAIT_NO_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0A7_LN0_RX_CDR_PLL_VCO_CNT_WAIT_NO(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0A7_LN0_RX_CDR_PLL_VCO_CNT_WAIT_NO_SHIFT)) & PCIE_PHY_TRSV_REG0A7_LN0_RX_CDR_PLL_VCO_CNT_WAIT_NO_MASK)
/*! @} */

/*! @name TRSV_REG0A8 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0A8_LN0_RX_CDR_PLL_MODE_RESTART_MASK (0x1U)
#define PCIE_PHY_TRSV_REG0A8_LN0_RX_CDR_PLL_MODE_RESTART_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0A8_LN0_RX_CDR_PLL_MODE_RESTART(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0A8_LN0_RX_CDR_PLL_MODE_RESTART_SHIFT)) & PCIE_PHY_TRSV_REG0A8_LN0_RX_CDR_PLL_MODE_RESTART_MASK)

#define PCIE_PHY_TRSV_REG0A8_LN0_RX_CDR_PLL_MODE_ENTRY_SRC_MASK (0x2U)
#define PCIE_PHY_TRSV_REG0A8_LN0_RX_CDR_PLL_MODE_ENTRY_SRC_SHIFT (1U)
#define PCIE_PHY_TRSV_REG0A8_LN0_RX_CDR_PLL_MODE_ENTRY_SRC(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0A8_LN0_RX_CDR_PLL_MODE_ENTRY_SRC_SHIFT)) & PCIE_PHY_TRSV_REG0A8_LN0_RX_CDR_PLL_MODE_ENTRY_SRC_MASK)

#define PCIE_PHY_TRSV_REG0A8_LN0_RX_CDR_PLL_LOCK_PPM_SET_MASK (0x7CU)
#define PCIE_PHY_TRSV_REG0A8_LN0_RX_CDR_PLL_LOCK_PPM_SET_SHIFT (2U)
#define PCIE_PHY_TRSV_REG0A8_LN0_RX_CDR_PLL_LOCK_PPM_SET(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0A8_LN0_RX_CDR_PLL_LOCK_PPM_SET_SHIFT)) & PCIE_PHY_TRSV_REG0A8_LN0_RX_CDR_PLL_LOCK_PPM_SET_MASK)
/*! @} */

/*! @name TRSV_REG0A9 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0A9_LN0_RX_CDR_CK_VCO_CNT_RUN_NO_MASK (0x1FU)
#define PCIE_PHY_TRSV_REG0A9_LN0_RX_CDR_CK_VCO_CNT_RUN_NO_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0A9_LN0_RX_CDR_CK_VCO_CNT_RUN_NO(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0A9_LN0_RX_CDR_CK_VCO_CNT_RUN_NO_SHIFT)) & PCIE_PHY_TRSV_REG0A9_LN0_RX_CDR_CK_VCO_CNT_RUN_NO_MASK)
/*! @} */

/*! @name TRSV_REG0AA -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0AA_LN0_RX_CDR_LOCK_SETTLE_NO_MASK (0x7U)
#define PCIE_PHY_TRSV_REG0AA_LN0_RX_CDR_LOCK_SETTLE_NO_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0AA_LN0_RX_CDR_LOCK_SETTLE_NO(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0AA_LN0_RX_CDR_LOCK_SETTLE_NO_SHIFT)) & PCIE_PHY_TRSV_REG0AA_LN0_RX_CDR_LOCK_SETTLE_NO_MASK)

#define PCIE_PHY_TRSV_REG0AA_LN0_RX_CDR_CK_VCO_CNT_WAIT_NO_MASK (0x78U)
#define PCIE_PHY_TRSV_REG0AA_LN0_RX_CDR_CK_VCO_CNT_WAIT_NO_SHIFT (3U)
#define PCIE_PHY_TRSV_REG0AA_LN0_RX_CDR_CK_VCO_CNT_WAIT_NO(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0AA_LN0_RX_CDR_CK_VCO_CNT_WAIT_NO_SHIFT)) & PCIE_PHY_TRSV_REG0AA_LN0_RX_CDR_CK_VCO_CNT_WAIT_NO_MASK)
/*! @} */

/*! @name TRSV_REG0AB -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0AB_LN0_RX_CDR_CAL_DONE_MASK (0x1U)
#define PCIE_PHY_TRSV_REG0AB_LN0_RX_CDR_CAL_DONE_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0AB_LN0_RX_CDR_CAL_DONE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0AB_LN0_RX_CDR_CAL_DONE_SHIFT)) & PCIE_PHY_TRSV_REG0AB_LN0_RX_CDR_CAL_DONE_MASK)

#define PCIE_PHY_TRSV_REG0AB_LN0_OVRD_RX_CDR_CAL_DONE_MASK (0x2U)
#define PCIE_PHY_TRSV_REG0AB_LN0_OVRD_RX_CDR_CAL_DONE_SHIFT (1U)
/*! LN0_OVRD_RX_CDR_CAL_DONE - Override enable for rx_cdr_cal_done */
#define PCIE_PHY_TRSV_REG0AB_LN0_OVRD_RX_CDR_CAL_DONE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0AB_LN0_OVRD_RX_CDR_CAL_DONE_SHIFT)) & PCIE_PHY_TRSV_REG0AB_LN0_OVRD_RX_CDR_CAL_DONE_MASK)

#define PCIE_PHY_TRSV_REG0AB_LN0_RX_CDR_CK_LOCK_PPM_SET_MASK (0x7CU)
#define PCIE_PHY_TRSV_REG0AB_LN0_RX_CDR_CK_LOCK_PPM_SET_SHIFT (2U)
#define PCIE_PHY_TRSV_REG0AB_LN0_RX_CDR_CK_LOCK_PPM_SET(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0AB_LN0_RX_CDR_CK_LOCK_PPM_SET_SHIFT)) & PCIE_PHY_TRSV_REG0AB_LN0_RX_CDR_CK_LOCK_PPM_SET_MASK)
/*! @} */

/*! @name TRSV_REG0AC -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0AC_LN0_RX_PWM_TG_OSC_CNT_MIN_MASK (0xFFU)
#define PCIE_PHY_TRSV_REG0AC_LN0_RX_PWM_TG_OSC_CNT_MIN_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0AC_LN0_RX_PWM_TG_OSC_CNT_MIN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0AC_LN0_RX_PWM_TG_OSC_CNT_MIN_SHIFT)) & PCIE_PHY_TRSV_REG0AC_LN0_RX_PWM_TG_OSC_CNT_MIN_MASK)
/*! @} */

/*! @name TRSV_REG0AD -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0AD_LN0_RX_PWM_TG_OSC_CNT_MAX_MASK (0xFFU)
#define PCIE_PHY_TRSV_REG0AD_LN0_RX_PWM_TG_OSC_CNT_MAX_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0AD_LN0_RX_PWM_TG_OSC_CNT_MAX(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0AD_LN0_RX_PWM_TG_OSC_CNT_MAX_SHIFT)) & PCIE_PHY_TRSV_REG0AD_LN0_RX_PWM_TG_OSC_CNT_MAX_MASK)
/*! @} */

/*! @name TRSV_REG0AE -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0AE_LN0_RX_PWM_AFC_STB_NUM_MASK (0xFU)
#define PCIE_PHY_TRSV_REG0AE_LN0_RX_PWM_AFC_STB_NUM_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0AE_LN0_RX_PWM_AFC_STB_NUM(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0AE_LN0_RX_PWM_AFC_STB_NUM_SHIFT)) & PCIE_PHY_TRSV_REG0AE_LN0_RX_PWM_AFC_STB_NUM_MASK)

#define PCIE_PHY_TRSV_REG0AE_LN0_RX_PWM_AFC_TOL_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG0AE_LN0_RX_PWM_AFC_TOL_SHIFT (4U)
#define PCIE_PHY_TRSV_REG0AE_LN0_RX_PWM_AFC_TOL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0AE_LN0_RX_PWM_AFC_TOL_SHIFT)) & PCIE_PHY_TRSV_REG0AE_LN0_RX_PWM_AFC_TOL_MASK)
/*! @} */

/*! @name TRSV_REG0AF -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0AF_LN0_RX_PWM_AFC_EN_MASK (0x1U)
#define PCIE_PHY_TRSV_REG0AF_LN0_RX_PWM_AFC_EN_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0AF_LN0_RX_PWM_AFC_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0AF_LN0_RX_PWM_AFC_EN_SHIFT)) & PCIE_PHY_TRSV_REG0AF_LN0_RX_PWM_AFC_EN_MASK)
/*! @} */

/*! @name TRSV_REG0B0 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0B0_LN0_OVRD_RX_EFOM_FEEDBACK_MASK (0x1U)
#define PCIE_PHY_TRSV_REG0B0_LN0_OVRD_RX_EFOM_FEEDBACK_SHIFT (0U)
/*! LN0_OVRD_RX_EFOM_FEEDBACK - Override enable for */
#define PCIE_PHY_TRSV_REG0B0_LN0_OVRD_RX_EFOM_FEEDBACK(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0B0_LN0_OVRD_RX_EFOM_FEEDBACK_SHIFT)) & PCIE_PHY_TRSV_REG0B0_LN0_OVRD_RX_EFOM_FEEDBACK_MASK)
/*! @} */

/*! @name TRSV_REG0B1 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0B1_LN0_RX_EFOM_FEEDBACK__15_8_MASK (0xFFU)
#define PCIE_PHY_TRSV_REG0B1_LN0_RX_EFOM_FEEDBACK__15_8_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0B1_LN0_RX_EFOM_FEEDBACK__15_8(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0B1_LN0_RX_EFOM_FEEDBACK__15_8_SHIFT)) & PCIE_PHY_TRSV_REG0B1_LN0_RX_EFOM_FEEDBACK__15_8_MASK)
/*! @} */

/*! @name TRSV_REG0B2 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0B2_LN0_RX_EFOM_FEEDBACK__7_0_MASK (0xFFU)
#define PCIE_PHY_TRSV_REG0B2_LN0_RX_EFOM_FEEDBACK__7_0_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0B2_LN0_RX_EFOM_FEEDBACK__7_0(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0B2_LN0_RX_EFOM_FEEDBACK__7_0_SHIFT)) & PCIE_PHY_TRSV_REG0B2_LN0_RX_EFOM_FEEDBACK__7_0_MASK)
/*! @} */

/*! @name TRSV_REG0B3 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0B3_LN0_RX_EFOM_START_MASK (0x1U)
#define PCIE_PHY_TRSV_REG0B3_LN0_RX_EFOM_START_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0B3_LN0_RX_EFOM_START(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0B3_LN0_RX_EFOM_START_SHIFT)) & PCIE_PHY_TRSV_REG0B3_LN0_RX_EFOM_START_MASK)

#define PCIE_PHY_TRSV_REG0B3_LN0_OVRD_RX_EFOM_START_MASK (0x2U)
#define PCIE_PHY_TRSV_REG0B3_LN0_OVRD_RX_EFOM_START_SHIFT (1U)
/*! LN0_OVRD_RX_EFOM_START - Override enable for rx_efom_start */
#define PCIE_PHY_TRSV_REG0B3_LN0_OVRD_RX_EFOM_START(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0B3_LN0_OVRD_RX_EFOM_START_SHIFT)) & PCIE_PHY_TRSV_REG0B3_LN0_OVRD_RX_EFOM_START_MASK)

#define PCIE_PHY_TRSV_REG0B3_LN0_RX_EFOM_MODE_MASK (0x1CU)
#define PCIE_PHY_TRSV_REG0B3_LN0_RX_EFOM_MODE_SHIFT (2U)
#define PCIE_PHY_TRSV_REG0B3_LN0_RX_EFOM_MODE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0B3_LN0_RX_EFOM_MODE_SHIFT)) & PCIE_PHY_TRSV_REG0B3_LN0_RX_EFOM_MODE_MASK)

#define PCIE_PHY_TRSV_REG0B3_LN0_RX_EFOM_DONE_MASK (0x20U)
#define PCIE_PHY_TRSV_REG0B3_LN0_RX_EFOM_DONE_SHIFT (5U)
#define PCIE_PHY_TRSV_REG0B3_LN0_RX_EFOM_DONE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0B3_LN0_RX_EFOM_DONE_SHIFT)) & PCIE_PHY_TRSV_REG0B3_LN0_RX_EFOM_DONE_MASK)

#define PCIE_PHY_TRSV_REG0B3_LN0_OVRD_RX_EFOM_DONE_MASK (0x40U)
#define PCIE_PHY_TRSV_REG0B3_LN0_OVRD_RX_EFOM_DONE_SHIFT (6U)
/*! LN0_OVRD_RX_EFOM_DONE - Override enable for rx_efom_done */
#define PCIE_PHY_TRSV_REG0B3_LN0_OVRD_RX_EFOM_DONE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0B3_LN0_OVRD_RX_EFOM_DONE_SHIFT)) & PCIE_PHY_TRSV_REG0B3_LN0_OVRD_RX_EFOM_DONE_MASK)
/*! @} */

/*! @name TRSV_REG0B4 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0B4_LN0_RX_EFOM_V_WEIGHT_MASK (0x3U)
#define PCIE_PHY_TRSV_REG0B4_LN0_RX_EFOM_V_WEIGHT_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0B4_LN0_RX_EFOM_V_WEIGHT(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0B4_LN0_RX_EFOM_V_WEIGHT_SHIFT)) & PCIE_PHY_TRSV_REG0B4_LN0_RX_EFOM_V_WEIGHT_MASK)

#define PCIE_PHY_TRSV_REG0B4_LN0_RX_EFOM_H_WEIGHT_MASK (0xCU)
#define PCIE_PHY_TRSV_REG0B4_LN0_RX_EFOM_H_WEIGHT_SHIFT (2U)
#define PCIE_PHY_TRSV_REG0B4_LN0_RX_EFOM_H_WEIGHT(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0B4_LN0_RX_EFOM_H_WEIGHT_SHIFT)) & PCIE_PHY_TRSV_REG0B4_LN0_RX_EFOM_H_WEIGHT_MASK)

#define PCIE_PHY_TRSV_REG0B4_LN0_RX_EFOM_START_SSM_DISABLE_MASK (0x10U)
#define PCIE_PHY_TRSV_REG0B4_LN0_RX_EFOM_START_SSM_DISABLE_SHIFT (4U)
#define PCIE_PHY_TRSV_REG0B4_LN0_RX_EFOM_START_SSM_DISABLE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0B4_LN0_RX_EFOM_START_SSM_DISABLE_SHIFT)) & PCIE_PHY_TRSV_REG0B4_LN0_RX_EFOM_START_SSM_DISABLE_MASK)

#define PCIE_PHY_TRSV_REG0B4_LN0_RX_EFOM_VREF_RESOL_MASK (0xE0U)
#define PCIE_PHY_TRSV_REG0B4_LN0_RX_EFOM_VREF_RESOL_SHIFT (5U)
#define PCIE_PHY_TRSV_REG0B4_LN0_RX_EFOM_VREF_RESOL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0B4_LN0_RX_EFOM_VREF_RESOL_SHIFT)) & PCIE_PHY_TRSV_REG0B4_LN0_RX_EFOM_VREF_RESOL_MASK)
/*! @} */

/*! @name TRSV_REG0B5 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0B5_LN0_RX_EFOM_EN_MASK (0x1U)
#define PCIE_PHY_TRSV_REG0B5_LN0_RX_EFOM_EN_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0B5_LN0_RX_EFOM_EN(x)   (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0B5_LN0_RX_EFOM_EN_SHIFT)) & PCIE_PHY_TRSV_REG0B5_LN0_RX_EFOM_EN_MASK)

#define PCIE_PHY_TRSV_REG0B5_LN0_RX_EFOM_RSTN_MASK (0x2U)
#define PCIE_PHY_TRSV_REG0B5_LN0_RX_EFOM_RSTN_SHIFT (1U)
#define PCIE_PHY_TRSV_REG0B5_LN0_RX_EFOM_RSTN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0B5_LN0_RX_EFOM_RSTN_SHIFT)) & PCIE_PHY_TRSV_REG0B5_LN0_RX_EFOM_RSTN_MASK)

#define PCIE_PHY_TRSV_REG0B5_LN0_RX_EFOM_BIT_WIDTH_SEL_MASK (0xCU)
#define PCIE_PHY_TRSV_REG0B5_LN0_RX_EFOM_BIT_WIDTH_SEL_SHIFT (2U)
#define PCIE_PHY_TRSV_REG0B5_LN0_RX_EFOM_BIT_WIDTH_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0B5_LN0_RX_EFOM_BIT_WIDTH_SEL_SHIFT)) & PCIE_PHY_TRSV_REG0B5_LN0_RX_EFOM_BIT_WIDTH_SEL_MASK)

#define PCIE_PHY_TRSV_REG0B5_LN0_RX_EFOM_SETTLE_TIME_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG0B5_LN0_RX_EFOM_SETTLE_TIME_SHIFT (4U)
#define PCIE_PHY_TRSV_REG0B5_LN0_RX_EFOM_SETTLE_TIME(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0B5_LN0_RX_EFOM_SETTLE_TIME_SHIFT)) & PCIE_PHY_TRSV_REG0B5_LN0_RX_EFOM_SETTLE_TIME_MASK)
/*! @} */

/*! @name TRSV_REG0B6 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0B6_LN0_RX_EFOM_NUM_OF_SAMPLE__13_8_MASK (0x3FU)
#define PCIE_PHY_TRSV_REG0B6_LN0_RX_EFOM_NUM_OF_SAMPLE__13_8_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0B6_LN0_RX_EFOM_NUM_OF_SAMPLE__13_8(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0B6_LN0_RX_EFOM_NUM_OF_SAMPLE__13_8_SHIFT)) & PCIE_PHY_TRSV_REG0B6_LN0_RX_EFOM_NUM_OF_SAMPLE__13_8_MASK)
/*! @} */

/*! @name TRSV_REG0B7 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0B7_LN0_RX_EFOM_NUM_OF_SAMPLE__7_0_MASK (0xFFU)
#define PCIE_PHY_TRSV_REG0B7_LN0_RX_EFOM_NUM_OF_SAMPLE__7_0_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0B7_LN0_RX_EFOM_NUM_OF_SAMPLE__7_0(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0B7_LN0_RX_EFOM_NUM_OF_SAMPLE__7_0_SHIFT)) & PCIE_PHY_TRSV_REG0B7_LN0_RX_EFOM_NUM_OF_SAMPLE__7_0_MASK)
/*! @} */

/*! @name TRSV_REG0B8 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0B8_LN0_RX_EFOM_OUT_WIDTH_SEL_MASK (0x1U)
#define PCIE_PHY_TRSV_REG0B8_LN0_RX_EFOM_OUT_WIDTH_SEL_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0B8_LN0_RX_EFOM_OUT_WIDTH_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0B8_LN0_RX_EFOM_OUT_WIDTH_SEL_SHIFT)) & PCIE_PHY_TRSV_REG0B8_LN0_RX_EFOM_OUT_WIDTH_SEL_MASK)

#define PCIE_PHY_TRSV_REG0B8_LN0_RX_EFOM_TRIAL_NUM_MASK (0xEU)
#define PCIE_PHY_TRSV_REG0B8_LN0_RX_EFOM_TRIAL_NUM_SHIFT (1U)
#define PCIE_PHY_TRSV_REG0B8_LN0_RX_EFOM_TRIAL_NUM(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0B8_LN0_RX_EFOM_TRIAL_NUM_SHIFT)) & PCIE_PHY_TRSV_REG0B8_LN0_RX_EFOM_TRIAL_NUM_MASK)
/*! @} */

/*! @name TRSV_REG0B9 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0B9_LN0_RX_EFOM_DFE_VREF_CTRL_MASK (0xFFU)
#define PCIE_PHY_TRSV_REG0B9_LN0_RX_EFOM_DFE_VREF_CTRL_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0B9_LN0_RX_EFOM_DFE_VREF_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0B9_LN0_RX_EFOM_DFE_VREF_CTRL_SHIFT)) & PCIE_PHY_TRSV_REG0B9_LN0_RX_EFOM_DFE_VREF_CTRL_MASK)
/*! @} */

/*! @name TRSV_REG0BA -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0BA_LN0_RX_EFOM_EOM_PH_SEL_MASK (0x7FU)
#define PCIE_PHY_TRSV_REG0BA_LN0_RX_EFOM_EOM_PH_SEL_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0BA_LN0_RX_EFOM_EOM_PH_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0BA_LN0_RX_EFOM_EOM_PH_SEL_SHIFT)) & PCIE_PHY_TRSV_REG0BA_LN0_RX_EFOM_EOM_PH_SEL_MASK)
/*! @} */

/*! @name TRSV_REG0BB -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0BB_LN0_RETIMEDLB_EN_MASK (0x1U)
#define PCIE_PHY_TRSV_REG0BB_LN0_RETIMEDLB_EN_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0BB_LN0_RETIMEDLB_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0BB_LN0_RETIMEDLB_EN_SHIFT)) & PCIE_PHY_TRSV_REG0BB_LN0_RETIMEDLB_EN_MASK)

#define PCIE_PHY_TRSV_REG0BB_LN0_NEARLB_EN_MASK  (0x2U)
#define PCIE_PHY_TRSV_REG0BB_LN0_NEARLB_EN_SHIFT (1U)
#define PCIE_PHY_TRSV_REG0BB_LN0_NEARLB_EN(x)    (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0BB_LN0_NEARLB_EN_SHIFT)) & PCIE_PHY_TRSV_REG0BB_LN0_NEARLB_EN_MASK)

#define PCIE_PHY_TRSV_REG0BB_LN0_TXD_DESKEW_BYPASS_MASK (0x4U)
#define PCIE_PHY_TRSV_REG0BB_LN0_TXD_DESKEW_BYPASS_SHIFT (2U)
#define PCIE_PHY_TRSV_REG0BB_LN0_TXD_DESKEW_BYPASS(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0BB_LN0_TXD_DESKEW_BYPASS_SHIFT)) & PCIE_PHY_TRSV_REG0BB_LN0_TXD_DESKEW_BYPASS_MASK)

#define PCIE_PHY_TRSV_REG0BB_LN0_TXD_DESKEW_FIX_DB_MASK (0x8U)
#define PCIE_PHY_TRSV_REG0BB_LN0_TXD_DESKEW_FIX_DB_SHIFT (3U)
#define PCIE_PHY_TRSV_REG0BB_LN0_TXD_DESKEW_FIX_DB(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0BB_LN0_TXD_DESKEW_FIX_DB_SHIFT)) & PCIE_PHY_TRSV_REG0BB_LN0_TXD_DESKEW_FIX_DB_MASK)

#define PCIE_PHY_TRSV_REG0BB_LN0_TXD_DESKEW_FIX_DA_MASK (0x10U)
#define PCIE_PHY_TRSV_REG0BB_LN0_TXD_DESKEW_FIX_DA_SHIFT (4U)
#define PCIE_PHY_TRSV_REG0BB_LN0_TXD_DESKEW_FIX_DA(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0BB_LN0_TXD_DESKEW_FIX_DA_SHIFT)) & PCIE_PHY_TRSV_REG0BB_LN0_TXD_DESKEW_FIX_DA_MASK)

#define PCIE_PHY_TRSV_REG0BB_LN0_TXD_DESKEW_BYPASS_ERR_CHK_MASK (0x20U)
#define PCIE_PHY_TRSV_REG0BB_LN0_TXD_DESKEW_BYPASS_ERR_CHK_SHIFT (5U)
#define PCIE_PHY_TRSV_REG0BB_LN0_TXD_DESKEW_BYPASS_ERR_CHK(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0BB_LN0_TXD_DESKEW_BYPASS_ERR_CHK_SHIFT)) & PCIE_PHY_TRSV_REG0BB_LN0_TXD_DESKEW_BYPASS_ERR_CHK_MASK)

#define PCIE_PHY_TRSV_REG0BB_LN0_TXD_DESKEW_RSTN_MASK (0x40U)
#define PCIE_PHY_TRSV_REG0BB_LN0_TXD_DESKEW_RSTN_SHIFT (6U)
#define PCIE_PHY_TRSV_REG0BB_LN0_TXD_DESKEW_RSTN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0BB_LN0_TXD_DESKEW_RSTN_SHIFT)) & PCIE_PHY_TRSV_REG0BB_LN0_TXD_DESKEW_RSTN_MASK)

#define PCIE_PHY_TRSV_REG0BB_LN0_OVRD_TXD_DESKEW_RSTN_MASK (0x80U)
#define PCIE_PHY_TRSV_REG0BB_LN0_OVRD_TXD_DESKEW_RSTN_SHIFT (7U)
/*! LN0_OVRD_TXD_DESKEW_RSTN - Override enable for txd_deskew_rstn */
#define PCIE_PHY_TRSV_REG0BB_LN0_OVRD_TXD_DESKEW_RSTN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0BB_LN0_OVRD_TXD_DESKEW_RSTN_SHIFT)) & PCIE_PHY_TRSV_REG0BB_LN0_OVRD_TXD_DESKEW_RSTN_MASK)
/*! @} */

/*! @name TRSV_REG0BC -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0BC_LN0_RXD_FLIP_BYTE_MASK (0x1U)
#define PCIE_PHY_TRSV_REG0BC_LN0_RXD_FLIP_BYTE_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0BC_LN0_RXD_FLIP_BYTE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0BC_LN0_RXD_FLIP_BYTE_SHIFT)) & PCIE_PHY_TRSV_REG0BC_LN0_RXD_FLIP_BYTE_MASK)

#define PCIE_PHY_TRSV_REG0BC_LN0_RXD_LOCK_NUM_MASK (0x1EU)
#define PCIE_PHY_TRSV_REG0BC_LN0_RXD_LOCK_NUM_SHIFT (1U)
#define PCIE_PHY_TRSV_REG0BC_LN0_RXD_LOCK_NUM(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0BC_LN0_RXD_LOCK_NUM_SHIFT)) & PCIE_PHY_TRSV_REG0BC_LN0_RXD_LOCK_NUM_MASK)

#define PCIE_PHY_TRSV_REG0BC_LN0_RXD_ALIGN_WORD_MASK (0x20U)
#define PCIE_PHY_TRSV_REG0BC_LN0_RXD_ALIGN_WORD_SHIFT (5U)
#define PCIE_PHY_TRSV_REG0BC_LN0_RXD_ALIGN_WORD(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0BC_LN0_RXD_ALIGN_WORD_SHIFT)) & PCIE_PHY_TRSV_REG0BC_LN0_RXD_ALIGN_WORD_MASK)

#define PCIE_PHY_TRSV_REG0BC_LN0_RXD_ALIGN_HOLD_MASK (0x40U)
#define PCIE_PHY_TRSV_REG0BC_LN0_RXD_ALIGN_HOLD_SHIFT (6U)
#define PCIE_PHY_TRSV_REG0BC_LN0_RXD_ALIGN_HOLD(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0BC_LN0_RXD_ALIGN_HOLD_SHIFT)) & PCIE_PHY_TRSV_REG0BC_LN0_RXD_ALIGN_HOLD_MASK)

#define PCIE_PHY_TRSV_REG0BC_LN0_RXD_ALIGN_EN_MASK (0x80U)
#define PCIE_PHY_TRSV_REG0BC_LN0_RXD_ALIGN_EN_SHIFT (7U)
#define PCIE_PHY_TRSV_REG0BC_LN0_RXD_ALIGN_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0BC_LN0_RXD_ALIGN_EN_SHIFT)) & PCIE_PHY_TRSV_REG0BC_LN0_RXD_ALIGN_EN_MASK)
/*! @} */

/*! @name TRSV_REG0BD -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0BD_LN0_TX_RCAL_DN_OPT_CODE_MASK (0x3U)
#define PCIE_PHY_TRSV_REG0BD_LN0_TX_RCAL_DN_OPT_CODE_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0BD_LN0_TX_RCAL_DN_OPT_CODE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0BD_LN0_TX_RCAL_DN_OPT_CODE_SHIFT)) & PCIE_PHY_TRSV_REG0BD_LN0_TX_RCAL_DN_OPT_CODE_MASK)

#define PCIE_PHY_TRSV_REG0BD_LN0_TX_RCAL_UP_OPT_CODE_MASK (0xCU)
#define PCIE_PHY_TRSV_REG0BD_LN0_TX_RCAL_UP_OPT_CODE_SHIFT (2U)
#define PCIE_PHY_TRSV_REG0BD_LN0_TX_RCAL_UP_OPT_CODE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0BD_LN0_TX_RCAL_UP_OPT_CODE_SHIFT)) & PCIE_PHY_TRSV_REG0BD_LN0_TX_RCAL_UP_OPT_CODE_MASK)

#define PCIE_PHY_TRSV_REG0BD_LN0_TX_RCAL_RSTN_MASK (0x10U)
#define PCIE_PHY_TRSV_REG0BD_LN0_TX_RCAL_RSTN_SHIFT (4U)
#define PCIE_PHY_TRSV_REG0BD_LN0_TX_RCAL_RSTN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0BD_LN0_TX_RCAL_RSTN_SHIFT)) & PCIE_PHY_TRSV_REG0BD_LN0_TX_RCAL_RSTN_MASK)

#define PCIE_PHY_TRSV_REG0BD_LN0_OVRD_TX_RCAL_RSTN_MASK (0x20U)
#define PCIE_PHY_TRSV_REG0BD_LN0_OVRD_TX_RCAL_RSTN_SHIFT (5U)
/*! LN0_OVRD_TX_RCAL_RSTN - Override enable for tx_rcal_rstn */
#define PCIE_PHY_TRSV_REG0BD_LN0_OVRD_TX_RCAL_RSTN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0BD_LN0_OVRD_TX_RCAL_RSTN_SHIFT)) & PCIE_PHY_TRSV_REG0BD_LN0_OVRD_TX_RCAL_RSTN_MASK)

#define PCIE_PHY_TRSV_REG0BD_LN0_RXD_POLARITY_MASK (0x40U)
#define PCIE_PHY_TRSV_REG0BD_LN0_RXD_POLARITY_SHIFT (6U)
#define PCIE_PHY_TRSV_REG0BD_LN0_RXD_POLARITY(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0BD_LN0_RXD_POLARITY_SHIFT)) & PCIE_PHY_TRSV_REG0BD_LN0_RXD_POLARITY_MASK)

#define PCIE_PHY_TRSV_REG0BD_LN0_RXD_FLIP_BIT_MASK (0x80U)
#define PCIE_PHY_TRSV_REG0BD_LN0_RXD_FLIP_BIT_SHIFT (7U)
#define PCIE_PHY_TRSV_REG0BD_LN0_RXD_FLIP_BIT(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0BD_LN0_RXD_FLIP_BIT_SHIFT)) & PCIE_PHY_TRSV_REG0BD_LN0_RXD_FLIP_BIT_MASK)
/*! @} */

/*! @name TRSV_REG0BE -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0BE_LN0_TX_RCAL_DN_CODE_MASK (0xFU)
#define PCIE_PHY_TRSV_REG0BE_LN0_TX_RCAL_DN_CODE_SHIFT (0U)
/*! LN0_TX_RCAL_DN_CODE - Termination down control bits. &lt;3&gt;bit is reserved bit., Default code= 011,Min code =000 and Max code is 111 */
#define PCIE_PHY_TRSV_REG0BE_LN0_TX_RCAL_DN_CODE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0BE_LN0_TX_RCAL_DN_CODE_SHIFT)) & PCIE_PHY_TRSV_REG0BE_LN0_TX_RCAL_DN_CODE_MASK)

#define PCIE_PHY_TRSV_REG0BE_LN0_TX_RCAL_UP_CODE_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG0BE_LN0_TX_RCAL_UP_CODE_SHIFT (4U)
/*! LN0_TX_RCAL_UP_CODE - Termination up control bits. &lt;3&gt; bit is reserved bit., Default code = 011,Min code =000 and Max code is 111 */
#define PCIE_PHY_TRSV_REG0BE_LN0_TX_RCAL_UP_CODE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0BE_LN0_TX_RCAL_UP_CODE_SHIFT)) & PCIE_PHY_TRSV_REG0BE_LN0_TX_RCAL_UP_CODE_MASK)
/*! @} */

/*! @name TRSV_REG0BF -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0BF_LN0_RX_RCAL_OPT_CODE_MASK (0x3U)
#define PCIE_PHY_TRSV_REG0BF_LN0_RX_RCAL_OPT_CODE_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0BF_LN0_RX_RCAL_OPT_CODE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0BF_LN0_RX_RCAL_OPT_CODE_SHIFT)) & PCIE_PHY_TRSV_REG0BF_LN0_RX_RCAL_OPT_CODE_MASK)

#define PCIE_PHY_TRSV_REG0BF_LN0_RX_RCAL_RSTN_MASK (0x4U)
#define PCIE_PHY_TRSV_REG0BF_LN0_RX_RCAL_RSTN_SHIFT (2U)
#define PCIE_PHY_TRSV_REG0BF_LN0_RX_RCAL_RSTN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0BF_LN0_RX_RCAL_RSTN_SHIFT)) & PCIE_PHY_TRSV_REG0BF_LN0_RX_RCAL_RSTN_MASK)

#define PCIE_PHY_TRSV_REG0BF_LN0_OVRD_RX_RCAL_RSTN_MASK (0x8U)
#define PCIE_PHY_TRSV_REG0BF_LN0_OVRD_RX_RCAL_RSTN_SHIFT (3U)
/*! LN0_OVRD_RX_RCAL_RSTN - Override enable for rx_rcal_rstn */
#define PCIE_PHY_TRSV_REG0BF_LN0_OVRD_RX_RCAL_RSTN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0BF_LN0_OVRD_RX_RCAL_RSTN_SHIFT)) & PCIE_PHY_TRSV_REG0BF_LN0_OVRD_RX_RCAL_RSTN_MASK)

#define PCIE_PHY_TRSV_REG0BF_LN0_TX_RCAL_DONE_MASK (0x10U)
#define PCIE_PHY_TRSV_REG0BF_LN0_TX_RCAL_DONE_SHIFT (4U)
/*! LN0_TX_RCAL_DONE - Monitoring for TX RCAL done */
#define PCIE_PHY_TRSV_REG0BF_LN0_TX_RCAL_DONE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0BF_LN0_TX_RCAL_DONE_SHIFT)) & PCIE_PHY_TRSV_REG0BF_LN0_TX_RCAL_DONE_MASK)

#define PCIE_PHY_TRSV_REG0BF_LN0_OVRD_TX_RCAL_DONE_MASK (0x20U)
#define PCIE_PHY_TRSV_REG0BF_LN0_OVRD_TX_RCAL_DONE_SHIFT (5U)
/*! LN0_OVRD_TX_RCAL_DONE - Override enable for tx_rcal_done */
#define PCIE_PHY_TRSV_REG0BF_LN0_OVRD_TX_RCAL_DONE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0BF_LN0_OVRD_TX_RCAL_DONE_SHIFT)) & PCIE_PHY_TRSV_REG0BF_LN0_OVRD_TX_RCAL_DONE_MASK)

#define PCIE_PHY_TRSV_REG0BF_LN0_TX_RCAL_COMP_OUT_MASK (0x40U)
#define PCIE_PHY_TRSV_REG0BF_LN0_TX_RCAL_COMP_OUT_SHIFT (6U)
#define PCIE_PHY_TRSV_REG0BF_LN0_TX_RCAL_COMP_OUT(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0BF_LN0_TX_RCAL_COMP_OUT_SHIFT)) & PCIE_PHY_TRSV_REG0BF_LN0_TX_RCAL_COMP_OUT_MASK)

#define PCIE_PHY_TRSV_REG0BF_LN0_OVRD_TX_RCAL_COMP_OUT_MASK (0x80U)
#define PCIE_PHY_TRSV_REG0BF_LN0_OVRD_TX_RCAL_COMP_OUT_SHIFT (7U)
/*! LN0_OVRD_TX_RCAL_COMP_OUT - Override enable for tx_rcal_comp_out */
#define PCIE_PHY_TRSV_REG0BF_LN0_OVRD_TX_RCAL_COMP_OUT(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0BF_LN0_OVRD_TX_RCAL_COMP_OUT_SHIFT)) & PCIE_PHY_TRSV_REG0BF_LN0_OVRD_TX_RCAL_COMP_OUT_MASK)
/*! @} */

/*! @name TRSV_REG0C0 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0C0_LN0_RX_RCAL_DONE_MASK (0x1U)
#define PCIE_PHY_TRSV_REG0C0_LN0_RX_RCAL_DONE_SHIFT (0U)
/*! LN0_RX_RCAL_DONE - RX RCAL done */
#define PCIE_PHY_TRSV_REG0C0_LN0_RX_RCAL_DONE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0C0_LN0_RX_RCAL_DONE_SHIFT)) & PCIE_PHY_TRSV_REG0C0_LN0_RX_RCAL_DONE_MASK)

#define PCIE_PHY_TRSV_REG0C0_LN0_OVRD_RX_RCAL_DONE_MASK (0x2U)
#define PCIE_PHY_TRSV_REG0C0_LN0_OVRD_RX_RCAL_DONE_SHIFT (1U)
/*! LN0_OVRD_RX_RCAL_DONE - Override enable for rx_rcal_done */
#define PCIE_PHY_TRSV_REG0C0_LN0_OVRD_RX_RCAL_DONE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0C0_LN0_OVRD_RX_RCAL_DONE_SHIFT)) & PCIE_PHY_TRSV_REG0C0_LN0_OVRD_RX_RCAL_DONE_MASK)

#define PCIE_PHY_TRSV_REG0C0_LN0_RX_RCAL_COMP_OUT_MASK (0x4U)
#define PCIE_PHY_TRSV_REG0C0_LN0_RX_RCAL_COMP_OUT_SHIFT (2U)
#define PCIE_PHY_TRSV_REG0C0_LN0_RX_RCAL_COMP_OUT(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0C0_LN0_RX_RCAL_COMP_OUT_SHIFT)) & PCIE_PHY_TRSV_REG0C0_LN0_RX_RCAL_COMP_OUT_MASK)

#define PCIE_PHY_TRSV_REG0C0_LN0_OVRD_RX_RCAL_COMP_OUT_MASK (0x8U)
#define PCIE_PHY_TRSV_REG0C0_LN0_OVRD_RX_RCAL_COMP_OUT_SHIFT (3U)
/*! LN0_OVRD_RX_RCAL_COMP_OUT - Override enable for rx_rcal_comp_out */
#define PCIE_PHY_TRSV_REG0C0_LN0_OVRD_RX_RCAL_COMP_OUT(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0C0_LN0_OVRD_RX_RCAL_COMP_OUT_SHIFT)) & PCIE_PHY_TRSV_REG0C0_LN0_OVRD_RX_RCAL_COMP_OUT_MASK)

#define PCIE_PHY_TRSV_REG0C0_LN0_RX_RTERM_CTRL_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG0C0_LN0_RX_RTERM_CTRL_SHIFT (4U)
/*! LN0_RX_RTERM_CTRL - Termination Calibration will send control signals to make 42.5 ohms. MSB&lt;4&gt;=&gt;1'b0=50,1'b1=42.5(default). */
#define PCIE_PHY_TRSV_REG0C0_LN0_RX_RTERM_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0C0_LN0_RX_RTERM_CTRL_SHIFT)) & PCIE_PHY_TRSV_REG0C0_LN0_RX_RTERM_CTRL_MASK)
/*! @} */

/*! @name TRSV_REG0C1 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0C1_LN0_BIST_PRBS_MODE_MASK (0x3U)
#define PCIE_PHY_TRSV_REG0C1_LN0_BIST_PRBS_MODE_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0C1_LN0_BIST_PRBS_MODE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0C1_LN0_BIST_PRBS_MODE_SHIFT)) & PCIE_PHY_TRSV_REG0C1_LN0_BIST_PRBS_MODE_MASK)

#define PCIE_PHY_TRSV_REG0C1_LN0_BIST_SEED_SEL_MASK (0x1CU)
#define PCIE_PHY_TRSV_REG0C1_LN0_BIST_SEED_SEL_SHIFT (2U)
#define PCIE_PHY_TRSV_REG0C1_LN0_BIST_SEED_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0C1_LN0_BIST_SEED_SEL_SHIFT)) & PCIE_PHY_TRSV_REG0C1_LN0_BIST_SEED_SEL_MASK)

#define PCIE_PHY_TRSV_REG0C1_LN0_BIST_COMDET_NUM_MASK (0x60U)
#define PCIE_PHY_TRSV_REG0C1_LN0_BIST_COMDET_NUM_SHIFT (5U)
#define PCIE_PHY_TRSV_REG0C1_LN0_BIST_COMDET_NUM(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0C1_LN0_BIST_COMDET_NUM_SHIFT)) & PCIE_PHY_TRSV_REG0C1_LN0_BIST_COMDET_NUM_MASK)

#define PCIE_PHY_TRSV_REG0C1_LN0_BIST_AUTO_RUN_MASK (0x80U)
#define PCIE_PHY_TRSV_REG0C1_LN0_BIST_AUTO_RUN_SHIFT (7U)
#define PCIE_PHY_TRSV_REG0C1_LN0_BIST_AUTO_RUN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0C1_LN0_BIST_AUTO_RUN_SHIFT)) & PCIE_PHY_TRSV_REG0C1_LN0_BIST_AUTO_RUN_MASK)
/*! @} */

/*! @name TRSV_REG0C2 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0C2_LN0_BIST_TX_START_MASK (0x1U)
#define PCIE_PHY_TRSV_REG0C2_LN0_BIST_TX_START_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0C2_LN0_BIST_TX_START(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0C2_LN0_BIST_TX_START_SHIFT)) & PCIE_PHY_TRSV_REG0C2_LN0_BIST_TX_START_MASK)

#define PCIE_PHY_TRSV_REG0C2_LN0_BIST_TX_ERRINJ_MASK (0x2U)
#define PCIE_PHY_TRSV_REG0C2_LN0_BIST_TX_ERRINJ_SHIFT (1U)
#define PCIE_PHY_TRSV_REG0C2_LN0_BIST_TX_ERRINJ(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0C2_LN0_BIST_TX_ERRINJ_SHIFT)) & PCIE_PHY_TRSV_REG0C2_LN0_BIST_TX_ERRINJ_MASK)

#define PCIE_PHY_TRSV_REG0C2_LN0_BIST_TX_EN_MASK (0x4U)
#define PCIE_PHY_TRSV_REG0C2_LN0_BIST_TX_EN_SHIFT (2U)
#define PCIE_PHY_TRSV_REG0C2_LN0_BIST_TX_EN(x)   (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0C2_LN0_BIST_TX_EN_SHIFT)) & PCIE_PHY_TRSV_REG0C2_LN0_BIST_TX_EN_MASK)

#define PCIE_PHY_TRSV_REG0C2_LN0_BIST_RX_START_MASK (0x8U)
#define PCIE_PHY_TRSV_REG0C2_LN0_BIST_RX_START_SHIFT (3U)
#define PCIE_PHY_TRSV_REG0C2_LN0_BIST_RX_START(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0C2_LN0_BIST_RX_START_SHIFT)) & PCIE_PHY_TRSV_REG0C2_LN0_BIST_RX_START_MASK)

#define PCIE_PHY_TRSV_REG0C2_LN0_BIST_RX_HOLD_MASK (0x10U)
#define PCIE_PHY_TRSV_REG0C2_LN0_BIST_RX_HOLD_SHIFT (4U)
#define PCIE_PHY_TRSV_REG0C2_LN0_BIST_RX_HOLD(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0C2_LN0_BIST_RX_HOLD_SHIFT)) & PCIE_PHY_TRSV_REG0C2_LN0_BIST_RX_HOLD_MASK)

#define PCIE_PHY_TRSV_REG0C2_LN0_BIST_RX_EN_MASK (0x20U)
#define PCIE_PHY_TRSV_REG0C2_LN0_BIST_RX_EN_SHIFT (5U)
#define PCIE_PHY_TRSV_REG0C2_LN0_BIST_RX_EN(x)   (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0C2_LN0_BIST_RX_EN_SHIFT)) & PCIE_PHY_TRSV_REG0C2_LN0_BIST_RX_EN_MASK)

#define PCIE_PHY_TRSV_REG0C2_LN0_BIST_DATA_EN_MASK (0x40U)
#define PCIE_PHY_TRSV_REG0C2_LN0_BIST_DATA_EN_SHIFT (6U)
#define PCIE_PHY_TRSV_REG0C2_LN0_BIST_DATA_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0C2_LN0_BIST_DATA_EN_SHIFT)) & PCIE_PHY_TRSV_REG0C2_LN0_BIST_DATA_EN_MASK)

#define PCIE_PHY_TRSV_REG0C2_LN0_BIST_EN_MASK    (0x80U)
#define PCIE_PHY_TRSV_REG0C2_LN0_BIST_EN_SHIFT   (7U)
#define PCIE_PHY_TRSV_REG0C2_LN0_BIST_EN(x)      (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0C2_LN0_BIST_EN_SHIFT)) & PCIE_PHY_TRSV_REG0C2_LN0_BIST_EN_MASK)
/*! @} */

/*! @name TRSV_REG0C3 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0C3_LN0_BIST_USER_PAT_EN_MASK (0x1U)
#define PCIE_PHY_TRSV_REG0C3_LN0_BIST_USER_PAT_EN_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0C3_LN0_BIST_USER_PAT_EN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0C3_LN0_BIST_USER_PAT_EN_SHIFT)) & PCIE_PHY_TRSV_REG0C3_LN0_BIST_USER_PAT_EN_MASK)
/*! @} */

/*! @name TRSV_REG0C4 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0C4_LN0_BIST_USER_PAT__79_72_MASK (0xFFU)
#define PCIE_PHY_TRSV_REG0C4_LN0_BIST_USER_PAT__79_72_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0C4_LN0_BIST_USER_PAT__79_72(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0C4_LN0_BIST_USER_PAT__79_72_SHIFT)) & PCIE_PHY_TRSV_REG0C4_LN0_BIST_USER_PAT__79_72_MASK)
/*! @} */

/*! @name TRSV_REG0C5 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0C5_LN0_BIST_USER_PAT__71_64_MASK (0xFFU)
#define PCIE_PHY_TRSV_REG0C5_LN0_BIST_USER_PAT__71_64_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0C5_LN0_BIST_USER_PAT__71_64(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0C5_LN0_BIST_USER_PAT__71_64_SHIFT)) & PCIE_PHY_TRSV_REG0C5_LN0_BIST_USER_PAT__71_64_MASK)
/*! @} */

/*! @name TRSV_REG0C6 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0C6_LN0_BIST_USER_PAT__63_56_MASK (0xFFU)
#define PCIE_PHY_TRSV_REG0C6_LN0_BIST_USER_PAT__63_56_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0C6_LN0_BIST_USER_PAT__63_56(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0C6_LN0_BIST_USER_PAT__63_56_SHIFT)) & PCIE_PHY_TRSV_REG0C6_LN0_BIST_USER_PAT__63_56_MASK)
/*! @} */

/*! @name TRSV_REG0C7 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0C7_LN0_BIST_USER_PAT__55_48_MASK (0xFFU)
#define PCIE_PHY_TRSV_REG0C7_LN0_BIST_USER_PAT__55_48_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0C7_LN0_BIST_USER_PAT__55_48(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0C7_LN0_BIST_USER_PAT__55_48_SHIFT)) & PCIE_PHY_TRSV_REG0C7_LN0_BIST_USER_PAT__55_48_MASK)
/*! @} */

/*! @name TRSV_REG0C8 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0C8_LN0_BIST_USER_PAT__47_40_MASK (0xFFU)
#define PCIE_PHY_TRSV_REG0C8_LN0_BIST_USER_PAT__47_40_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0C8_LN0_BIST_USER_PAT__47_40(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0C8_LN0_BIST_USER_PAT__47_40_SHIFT)) & PCIE_PHY_TRSV_REG0C8_LN0_BIST_USER_PAT__47_40_MASK)
/*! @} */

/*! @name TRSV_REG0C9 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0C9_LN0_BIST_USER_PAT__39_32_MASK (0xFFU)
#define PCIE_PHY_TRSV_REG0C9_LN0_BIST_USER_PAT__39_32_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0C9_LN0_BIST_USER_PAT__39_32(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0C9_LN0_BIST_USER_PAT__39_32_SHIFT)) & PCIE_PHY_TRSV_REG0C9_LN0_BIST_USER_PAT__39_32_MASK)
/*! @} */

/*! @name TRSV_REG0CA -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0CA_LN0_BIST_USER_PAT__31_24_MASK (0xFFU)
#define PCIE_PHY_TRSV_REG0CA_LN0_BIST_USER_PAT__31_24_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0CA_LN0_BIST_USER_PAT__31_24(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0CA_LN0_BIST_USER_PAT__31_24_SHIFT)) & PCIE_PHY_TRSV_REG0CA_LN0_BIST_USER_PAT__31_24_MASK)
/*! @} */

/*! @name TRSV_REG0CB -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0CB_LN0_BIST_USER_PAT__23_16_MASK (0xFFU)
#define PCIE_PHY_TRSV_REG0CB_LN0_BIST_USER_PAT__23_16_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0CB_LN0_BIST_USER_PAT__23_16(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0CB_LN0_BIST_USER_PAT__23_16_SHIFT)) & PCIE_PHY_TRSV_REG0CB_LN0_BIST_USER_PAT__23_16_MASK)
/*! @} */

/*! @name TRSV_REG0CC -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0CC_LN0_BIST_USER_PAT__15_8_MASK (0xFFU)
#define PCIE_PHY_TRSV_REG0CC_LN0_BIST_USER_PAT__15_8_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0CC_LN0_BIST_USER_PAT__15_8(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0CC_LN0_BIST_USER_PAT__15_8_SHIFT)) & PCIE_PHY_TRSV_REG0CC_LN0_BIST_USER_PAT__15_8_MASK)
/*! @} */

/*! @name TRSV_REG0CD -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0CD_LN0_BIST_USER_PAT__7_0_MASK (0xFFU)
#define PCIE_PHY_TRSV_REG0CD_LN0_BIST_USER_PAT__7_0_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0CD_LN0_BIST_USER_PAT__7_0(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0CD_LN0_BIST_USER_PAT__7_0_SHIFT)) & PCIE_PHY_TRSV_REG0CD_LN0_BIST_USER_PAT__7_0_MASK)
/*! @} */

/*! @name TRSV_REG0CE -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0CE_LN0_LANE_MODE_MASK  (0x1U)
#define PCIE_PHY_TRSV_REG0CE_LN0_LANE_MODE_SHIFT (0U)
/*! LN0_LANE_MODE - Lane operation mode */
#define PCIE_PHY_TRSV_REG0CE_LN0_LANE_MODE(x)    (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0CE_LN0_LANE_MODE_SHIFT)) & PCIE_PHY_TRSV_REG0CE_LN0_LANE_MODE_MASK)

#define PCIE_PHY_TRSV_REG0CE_LN0_TG_RX_SIGVAL_LPF_DELAY_TIME_MASK (0xEU)
#define PCIE_PHY_TRSV_REG0CE_LN0_TG_RX_SIGVAL_LPF_DELAY_TIME_SHIFT (1U)
#define PCIE_PHY_TRSV_REG0CE_LN0_TG_RX_SIGVAL_LPF_DELAY_TIME(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0CE_LN0_TG_RX_SIGVAL_LPF_DELAY_TIME_SHIFT)) & PCIE_PHY_TRSV_REG0CE_LN0_TG_RX_SIGVAL_LPF_DELAY_TIME_MASK)

#define PCIE_PHY_TRSV_REG0CE_LN0_RX_SIGVAL_LPF_BYPASS_MASK (0x30U)
#define PCIE_PHY_TRSV_REG0CE_LN0_RX_SIGVAL_LPF_BYPASS_SHIFT (4U)
#define PCIE_PHY_TRSV_REG0CE_LN0_RX_SIGVAL_LPF_BYPASS(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0CE_LN0_RX_SIGVAL_LPF_BYPASS_SHIFT)) & PCIE_PHY_TRSV_REG0CE_LN0_RX_SIGVAL_LPF_BYPASS_MASK)
/*! @} */

/*! @name TRSV_REG0CF -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0CF_LN0_MISC_RX_CLK_INV_MASK (0x1U)
#define PCIE_PHY_TRSV_REG0CF_LN0_MISC_RX_CLK_INV_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0CF_LN0_MISC_RX_CLK_INV(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0CF_LN0_MISC_RX_CLK_INV_SHIFT)) & PCIE_PHY_TRSV_REG0CF_LN0_MISC_RX_CLK_INV_MASK)

#define PCIE_PHY_TRSV_REG0CF_LN0_MISC_RX_CLK_SRC_MASK (0x2U)
#define PCIE_PHY_TRSV_REG0CF_LN0_MISC_RX_CLK_SRC_SHIFT (1U)
#define PCIE_PHY_TRSV_REG0CF_LN0_MISC_RX_CLK_SRC(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0CF_LN0_MISC_RX_CLK_SRC_SHIFT)) & PCIE_PHY_TRSV_REG0CF_LN0_MISC_RX_CLK_SRC_MASK)

#define PCIE_PHY_TRSV_REG0CF_LN0_MISC_TX_CLK_SRC_MASK (0x4U)
#define PCIE_PHY_TRSV_REG0CF_LN0_MISC_TX_CLK_SRC_SHIFT (2U)
#define PCIE_PHY_TRSV_REG0CF_LN0_MISC_TX_CLK_SRC(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0CF_LN0_MISC_TX_CLK_SRC_SHIFT)) & PCIE_PHY_TRSV_REG0CF_LN0_MISC_TX_CLK_SRC_MASK)

#define PCIE_PHY_TRSV_REG0CF_LN0_LANE_TIMER_SEL_MASK (0x8U)
#define PCIE_PHY_TRSV_REG0CF_LN0_LANE_TIMER_SEL_SHIFT (3U)
#define PCIE_PHY_TRSV_REG0CF_LN0_LANE_TIMER_SEL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0CF_LN0_LANE_TIMER_SEL_SHIFT)) & PCIE_PHY_TRSV_REG0CF_LN0_LANE_TIMER_SEL_MASK)

#define PCIE_PHY_TRSV_REG0CF_LN0_LANE_RATE_MASK  (0x30U)
#define PCIE_PHY_TRSV_REG0CF_LN0_LANE_RATE_SHIFT (4U)
#define PCIE_PHY_TRSV_REG0CF_LN0_LANE_RATE(x)    (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0CF_LN0_LANE_RATE_SHIFT)) & PCIE_PHY_TRSV_REG0CF_LN0_LANE_RATE_MASK)

#define PCIE_PHY_TRSV_REG0CF_LN0_OVRD_LANE_RATE_MASK (0x40U)
#define PCIE_PHY_TRSV_REG0CF_LN0_OVRD_LANE_RATE_SHIFT (6U)
/*! LN0_OVRD_LANE_RATE - Override enable for lane_rate */
#define PCIE_PHY_TRSV_REG0CF_LN0_OVRD_LANE_RATE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0CF_LN0_OVRD_LANE_RATE_SHIFT)) & PCIE_PHY_TRSV_REG0CF_LN0_OVRD_LANE_RATE_MASK)
/*! @} */

/*! @name TRSV_REG0D0 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0D0_LN0_MISC_TX_RXD_DETECTED_MASK (0x1U)
#define PCIE_PHY_TRSV_REG0D0_LN0_MISC_TX_RXD_DETECTED_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0D0_LN0_MISC_TX_RXD_DETECTED(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0D0_LN0_MISC_TX_RXD_DETECTED_SHIFT)) & PCIE_PHY_TRSV_REG0D0_LN0_MISC_TX_RXD_DETECTED_MASK)

#define PCIE_PHY_TRSV_REG0D0_LN0_OVRD_MISC_TX_RXD_DETECTED_MASK (0x2U)
#define PCIE_PHY_TRSV_REG0D0_LN0_OVRD_MISC_TX_RXD_DETECTED_SHIFT (1U)
/*! LN0_OVRD_MISC_TX_RXD_DETECTED - Override enable for misc_tx_rxd_detected */
#define PCIE_PHY_TRSV_REG0D0_LN0_OVRD_MISC_TX_RXD_DETECTED(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0D0_LN0_OVRD_MISC_TX_RXD_DETECTED_SHIFT)) & PCIE_PHY_TRSV_REG0D0_LN0_OVRD_MISC_TX_RXD_DETECTED_MASK)

#define PCIE_PHY_TRSV_REG0D0_LN0_MISC_RX_LFPS_DET_MASK (0x4U)
#define PCIE_PHY_TRSV_REG0D0_LN0_MISC_RX_LFPS_DET_SHIFT (2U)
#define PCIE_PHY_TRSV_REG0D0_LN0_MISC_RX_LFPS_DET(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0D0_LN0_MISC_RX_LFPS_DET_SHIFT)) & PCIE_PHY_TRSV_REG0D0_LN0_MISC_RX_LFPS_DET_MASK)

#define PCIE_PHY_TRSV_REG0D0_LN0_OVRD_MISC_RX_LFPS_DET_MASK (0x8U)
#define PCIE_PHY_TRSV_REG0D0_LN0_OVRD_MISC_RX_LFPS_DET_SHIFT (3U)
/*! LN0_OVRD_MISC_RX_LFPS_DET - Override enable for misc_rx_lfps_det */
#define PCIE_PHY_TRSV_REG0D0_LN0_OVRD_MISC_RX_LFPS_DET(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0D0_LN0_OVRD_MISC_RX_LFPS_DET_SHIFT)) & PCIE_PHY_TRSV_REG0D0_LN0_OVRD_MISC_RX_LFPS_DET_MASK)

#define PCIE_PHY_TRSV_REG0D0_LN0_MISC_RX_DATA_CLEAR_SRC_MASK (0x10U)
#define PCIE_PHY_TRSV_REG0D0_LN0_MISC_RX_DATA_CLEAR_SRC_SHIFT (4U)
#define PCIE_PHY_TRSV_REG0D0_LN0_MISC_RX_DATA_CLEAR_SRC(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0D0_LN0_MISC_RX_DATA_CLEAR_SRC_SHIFT)) & PCIE_PHY_TRSV_REG0D0_LN0_MISC_RX_DATA_CLEAR_SRC_MASK)

#define PCIE_PHY_TRSV_REG0D0_LN0_MISC_RX_SQHS_SIGVAL_MASK (0x20U)
#define PCIE_PHY_TRSV_REG0D0_LN0_MISC_RX_SQHS_SIGVAL_SHIFT (5U)
#define PCIE_PHY_TRSV_REG0D0_LN0_MISC_RX_SQHS_SIGVAL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0D0_LN0_MISC_RX_SQHS_SIGVAL_SHIFT)) & PCIE_PHY_TRSV_REG0D0_LN0_MISC_RX_SQHS_SIGVAL_MASK)

#define PCIE_PHY_TRSV_REG0D0_LN0_OVRD_MISC_RX_SQHS_SIGVAL_MASK (0x40U)
#define PCIE_PHY_TRSV_REG0D0_LN0_OVRD_MISC_RX_SQHS_SIGVAL_SHIFT (6U)
/*! LN0_OVRD_MISC_RX_SQHS_SIGVAL - Override enable for misc_rx_sqhs_sigval */
#define PCIE_PHY_TRSV_REG0D0_LN0_OVRD_MISC_RX_SQHS_SIGVAL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0D0_LN0_OVRD_MISC_RX_SQHS_SIGVAL_SHIFT)) & PCIE_PHY_TRSV_REG0D0_LN0_OVRD_MISC_RX_SQHS_SIGVAL_MASK)
/*! @} */

/*! @name TRSV_REG0D1 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0D1_LN0_TG_RCAL_RSTN_DELAY_TIME_MASK (0x7U)
#define PCIE_PHY_TRSV_REG0D1_LN0_TG_RCAL_RSTN_DELAY_TIME_SHIFT (0U)
/*! LN0_TG_RCAL_RSTN_DELAY_TIME - Rx Rcal reset delay time after PLL AFC done */
#define PCIE_PHY_TRSV_REG0D1_LN0_TG_RCAL_RSTN_DELAY_TIME(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0D1_LN0_TG_RCAL_RSTN_DELAY_TIME_SHIFT)) & PCIE_PHY_TRSV_REG0D1_LN0_TG_RCAL_RSTN_DELAY_TIME_MASK)

#define PCIE_PHY_TRSV_REG0D1_LN0_TG_CDR_BW_CTRL_DELAY_TIME_MASK (0x38U)
#define PCIE_PHY_TRSV_REG0D1_LN0_TG_CDR_BW_CTRL_DELAY_TIME_SHIFT (3U)
/*! LN0_TG_CDR_BW_CTRL_DELAY_TIME - RX CDR bandwidth change time control */
#define PCIE_PHY_TRSV_REG0D1_LN0_TG_CDR_BW_CTRL_DELAY_TIME(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0D1_LN0_TG_CDR_BW_CTRL_DELAY_TIME_SHIFT)) & PCIE_PHY_TRSV_REG0D1_LN0_TG_CDR_BW_CTRL_DELAY_TIME_MASK)

#define PCIE_PHY_TRSV_REG0D1_LN0_MISC_RX_VALID_RSTN_MASK (0x40U)
#define PCIE_PHY_TRSV_REG0D1_LN0_MISC_RX_VALID_RSTN_SHIFT (6U)
#define PCIE_PHY_TRSV_REG0D1_LN0_MISC_RX_VALID_RSTN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0D1_LN0_MISC_RX_VALID_RSTN_SHIFT)) & PCIE_PHY_TRSV_REG0D1_LN0_MISC_RX_VALID_RSTN_MASK)

#define PCIE_PHY_TRSV_REG0D1_LN0_OVRD_MISC_RX_VALID_RSTN_MASK (0x80U)
#define PCIE_PHY_TRSV_REG0D1_LN0_OVRD_MISC_RX_VALID_RSTN_SHIFT (7U)
/*! LN0_OVRD_MISC_RX_VALID_RSTN - Override enable for misc_rx_valid_rstn */
#define PCIE_PHY_TRSV_REG0D1_LN0_OVRD_MISC_RX_VALID_RSTN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0D1_LN0_OVRD_MISC_RX_VALID_RSTN_SHIFT)) & PCIE_PHY_TRSV_REG0D1_LN0_OVRD_MISC_RX_VALID_RSTN_MASK)
/*! @} */

/*! @name TRSV_REG0D2 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0D2_LN0_TG_RXD_COMP_DELAY_TIME_MASK (0x3U)
#define PCIE_PHY_TRSV_REG0D2_LN0_TG_RXD_COMP_DELAY_TIME_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0D2_LN0_TG_RXD_COMP_DELAY_TIME(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0D2_LN0_TG_RXD_COMP_DELAY_TIME_SHIFT)) & PCIE_PHY_TRSV_REG0D2_LN0_TG_RXD_COMP_DELAY_TIME_MASK)
/*! @} */

/*! @name TRSV_REG0D3 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0D3_LN0_MON_LANE_STATE_MASK (0xFU)
#define PCIE_PHY_TRSV_REG0D3_LN0_MON_LANE_STATE_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0D3_LN0_MON_LANE_STATE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0D3_LN0_MON_LANE_STATE_SHIFT)) & PCIE_PHY_TRSV_REG0D3_LN0_MON_LANE_STATE_MASK)

#define PCIE_PHY_TRSV_REG0D3_LN0_ANA_RX_SQLS_DIFP_DET_MASK (0x10U)
#define PCIE_PHY_TRSV_REG0D3_LN0_ANA_RX_SQLS_DIFP_DET_SHIFT (4U)
/*! LN0_ANA_RX_SQLS_DIFP_DET - DIFP Detection signal */
#define PCIE_PHY_TRSV_REG0D3_LN0_ANA_RX_SQLS_DIFP_DET(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0D3_LN0_ANA_RX_SQLS_DIFP_DET_SHIFT)) & PCIE_PHY_TRSV_REG0D3_LN0_ANA_RX_SQLS_DIFP_DET_MASK)

#define PCIE_PHY_TRSV_REG0D3_LN0_ANA_RX_SQLS_DIFN_DET_MASK (0x20U)
#define PCIE_PHY_TRSV_REG0D3_LN0_ANA_RX_SQLS_DIFN_DET_SHIFT (5U)
/*! LN0_ANA_RX_SQLS_DIFN_DET - DIFN Detection signal */
#define PCIE_PHY_TRSV_REG0D3_LN0_ANA_RX_SQLS_DIFN_DET(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0D3_LN0_ANA_RX_SQLS_DIFN_DET_SHIFT)) & PCIE_PHY_TRSV_REG0D3_LN0_ANA_RX_SQLS_DIFN_DET_MASK)
/*! @} */

/*! @name TRSV_REG0D4 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0D4_LN0_MON_CDR_STATE_MASK (0xFU)
#define PCIE_PHY_TRSV_REG0D4_LN0_MON_CDR_STATE_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0D4_LN0_MON_CDR_STATE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0D4_LN0_MON_CDR_STATE_SHIFT)) & PCIE_PHY_TRSV_REG0D4_LN0_MON_CDR_STATE_MASK)
/*! @} */

/*! @name TRSV_REG0D5 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0D5_LN0_MON_LANE_TIME__14_8_MASK (0x7FU)
#define PCIE_PHY_TRSV_REG0D5_LN0_MON_LANE_TIME__14_8_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0D5_LN0_MON_LANE_TIME__14_8(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0D5_LN0_MON_LANE_TIME__14_8_SHIFT)) & PCIE_PHY_TRSV_REG0D5_LN0_MON_LANE_TIME__14_8_MASK)
/*! @} */

/*! @name TRSV_REG0D6 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0D6_LN0_MON_LANE_TIME__7_0_MASK (0xFFU)
#define PCIE_PHY_TRSV_REG0D6_LN0_MON_LANE_TIME__7_0_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0D6_LN0_MON_LANE_TIME__7_0(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0D6_LN0_MON_LANE_TIME__7_0_SHIFT)) & PCIE_PHY_TRSV_REG0D6_LN0_MON_LANE_TIME__7_0_MASK)
/*! @} */

/*! @name TRSV_REG0D7 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0D7_LN0_MON_RX_CDR_FBB_FINE_CTRL_MASK (0xFU)
#define PCIE_PHY_TRSV_REG0D7_LN0_MON_RX_CDR_FBB_FINE_CTRL_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0D7_LN0_MON_RX_CDR_FBB_FINE_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0D7_LN0_MON_RX_CDR_FBB_FINE_CTRL_SHIFT)) & PCIE_PHY_TRSV_REG0D7_LN0_MON_RX_CDR_FBB_FINE_CTRL_MASK)

#define PCIE_PHY_TRSV_REG0D7_LN0_MON_RX_CDR_AFC_SEL_LOGIC_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG0D7_LN0_MON_RX_CDR_AFC_SEL_LOGIC_SHIFT (4U)
#define PCIE_PHY_TRSV_REG0D7_LN0_MON_RX_CDR_AFC_SEL_LOGIC(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0D7_LN0_MON_RX_CDR_AFC_SEL_LOGIC_SHIFT)) & PCIE_PHY_TRSV_REG0D7_LN0_MON_RX_CDR_AFC_SEL_LOGIC_MASK)
/*! @} */

/*! @name TRSV_REG0D8 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0D8_LN0_MON_RX_CDR_FBB_PLL_MODE_CTRL_MASK (0xFU)
#define PCIE_PHY_TRSV_REG0D8_LN0_MON_RX_CDR_FBB_PLL_MODE_CTRL_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0D8_LN0_MON_RX_CDR_FBB_PLL_MODE_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0D8_LN0_MON_RX_CDR_FBB_PLL_MODE_CTRL_SHIFT)) & PCIE_PHY_TRSV_REG0D8_LN0_MON_RX_CDR_FBB_PLL_MODE_CTRL_MASK)

#define PCIE_PHY_TRSV_REG0D8_LN0_MON_RX_CDR_FBB_COARSE_CTRL_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG0D8_LN0_MON_RX_CDR_FBB_COARSE_CTRL_SHIFT (4U)
#define PCIE_PHY_TRSV_REG0D8_LN0_MON_RX_CDR_FBB_COARSE_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0D8_LN0_MON_RX_CDR_FBB_COARSE_CTRL_SHIFT)) & PCIE_PHY_TRSV_REG0D8_LN0_MON_RX_CDR_FBB_COARSE_CTRL_MASK)
/*! @} */

/*! @name TRSV_REG0D9 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0D9_LN0_MON_RX_CDR_MODE_CTRL_MASK (0x3U)
#define PCIE_PHY_TRSV_REG0D9_LN0_MON_RX_CDR_MODE_CTRL_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0D9_LN0_MON_RX_CDR_MODE_CTRL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0D9_LN0_MON_RX_CDR_MODE_CTRL_SHIFT)) & PCIE_PHY_TRSV_REG0D9_LN0_MON_RX_CDR_MODE_CTRL_MASK)
/*! @} */

/*! @name TRSV_REG0DA -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0DA_LN0_MON_RX_OC_DFE_ADDER_EVEN_MASK (0x7FU)
#define PCIE_PHY_TRSV_REG0DA_LN0_MON_RX_OC_DFE_ADDER_EVEN_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0DA_LN0_MON_RX_OC_DFE_ADDER_EVEN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0DA_LN0_MON_RX_OC_DFE_ADDER_EVEN_SHIFT)) & PCIE_PHY_TRSV_REG0DA_LN0_MON_RX_OC_DFE_ADDER_EVEN_MASK)
/*! @} */

/*! @name TRSV_REG0DB -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0DB_LN0_MON_RX_OC_DFE_DAC_ADDER_EVEN_MASK (0x1U)
#define PCIE_PHY_TRSV_REG0DB_LN0_MON_RX_OC_DFE_DAC_ADDER_EVEN_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0DB_LN0_MON_RX_OC_DFE_DAC_ADDER_EVEN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0DB_LN0_MON_RX_OC_DFE_DAC_ADDER_EVEN_SHIFT)) & PCIE_PHY_TRSV_REG0DB_LN0_MON_RX_OC_DFE_DAC_ADDER_EVEN_MASK)

#define PCIE_PHY_TRSV_REG0DB_LN0_MON_RX_OC_DFE_ADDER_ODD_MASK (0xFEU)
#define PCIE_PHY_TRSV_REG0DB_LN0_MON_RX_OC_DFE_ADDER_ODD_SHIFT (1U)
#define PCIE_PHY_TRSV_REG0DB_LN0_MON_RX_OC_DFE_ADDER_ODD(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0DB_LN0_MON_RX_OC_DFE_ADDER_ODD_SHIFT)) & PCIE_PHY_TRSV_REG0DB_LN0_MON_RX_OC_DFE_ADDER_ODD_MASK)
/*! @} */

/*! @name TRSV_REG0DC -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0DC_LN0_MON_RX_OC_DFE_DAC_ADDER_ODD_MASK (0x1U)
#define PCIE_PHY_TRSV_REG0DC_LN0_MON_RX_OC_DFE_DAC_ADDER_ODD_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0DC_LN0_MON_RX_OC_DFE_DAC_ADDER_ODD(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0DC_LN0_MON_RX_OC_DFE_DAC_ADDER_ODD_SHIFT)) & PCIE_PHY_TRSV_REG0DC_LN0_MON_RX_OC_DFE_DAC_ADDER_ODD_MASK)
/*! @} */

/*! @name TRSV_REG0DD -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0DD_LN0_MON_RX_OC_DFE_SA_EDGE_EVEN__8_MASK (0x1U)
#define PCIE_PHY_TRSV_REG0DD_LN0_MON_RX_OC_DFE_SA_EDGE_EVEN__8_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0DD_LN0_MON_RX_OC_DFE_SA_EDGE_EVEN__8(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0DD_LN0_MON_RX_OC_DFE_SA_EDGE_EVEN__8_SHIFT)) & PCIE_PHY_TRSV_REG0DD_LN0_MON_RX_OC_DFE_SA_EDGE_EVEN__8_MASK)
/*! @} */

/*! @name TRSV_REG0DE -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0DE_LN0_MON_RX_OC_DFE_SA_EDGE_EVEN__7_0_MASK (0xFFU)
#define PCIE_PHY_TRSV_REG0DE_LN0_MON_RX_OC_DFE_SA_EDGE_EVEN__7_0_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0DE_LN0_MON_RX_OC_DFE_SA_EDGE_EVEN__7_0(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0DE_LN0_MON_RX_OC_DFE_SA_EDGE_EVEN__7_0_SHIFT)) & PCIE_PHY_TRSV_REG0DE_LN0_MON_RX_OC_DFE_SA_EDGE_EVEN__7_0_MASK)
/*! @} */

/*! @name TRSV_REG0DF -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0DF_LN0_MON_RX_OC_DFE_SA_EDGE_ODD__8_MASK (0x1U)
#define PCIE_PHY_TRSV_REG0DF_LN0_MON_RX_OC_DFE_SA_EDGE_ODD__8_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0DF_LN0_MON_RX_OC_DFE_SA_EDGE_ODD__8(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0DF_LN0_MON_RX_OC_DFE_SA_EDGE_ODD__8_SHIFT)) & PCIE_PHY_TRSV_REG0DF_LN0_MON_RX_OC_DFE_SA_EDGE_ODD__8_MASK)
/*! @} */

/*! @name TRSV_REG0E0 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0E0_LN0_MON_RX_OC_DFE_SA_EDGE_ODD__7_0_MASK (0xFFU)
#define PCIE_PHY_TRSV_REG0E0_LN0_MON_RX_OC_DFE_SA_EDGE_ODD__7_0_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0E0_LN0_MON_RX_OC_DFE_SA_EDGE_ODD__7_0(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0E0_LN0_MON_RX_OC_DFE_SA_EDGE_ODD__7_0_SHIFT)) & PCIE_PHY_TRSV_REG0E0_LN0_MON_RX_OC_DFE_SA_EDGE_ODD__7_0_MASK)
/*! @} */

/*! @name TRSV_REG0E1 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0E1_LN0_MON_RX_OC_DFE_DAC_EDGE_EVEN_MASK (0x7U)
#define PCIE_PHY_TRSV_REG0E1_LN0_MON_RX_OC_DFE_DAC_EDGE_EVEN_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0E1_LN0_MON_RX_OC_DFE_DAC_EDGE_EVEN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0E1_LN0_MON_RX_OC_DFE_DAC_EDGE_EVEN_SHIFT)) & PCIE_PHY_TRSV_REG0E1_LN0_MON_RX_OC_DFE_DAC_EDGE_EVEN_MASK)

#define PCIE_PHY_TRSV_REG0E1_LN0_MON_RX_OC_DFE_DAC_EDGE_ODD_MASK (0x38U)
#define PCIE_PHY_TRSV_REG0E1_LN0_MON_RX_OC_DFE_DAC_EDGE_ODD_SHIFT (3U)
#define PCIE_PHY_TRSV_REG0E1_LN0_MON_RX_OC_DFE_DAC_EDGE_ODD(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0E1_LN0_MON_RX_OC_DFE_DAC_EDGE_ODD_SHIFT)) & PCIE_PHY_TRSV_REG0E1_LN0_MON_RX_OC_DFE_DAC_EDGE_ODD_MASK)
/*! @} */

/*! @name TRSV_REG0E2 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0E2_LN0_MON_RX_OC_DFE_SA_ERR_EVEN__8_MASK (0x1U)
#define PCIE_PHY_TRSV_REG0E2_LN0_MON_RX_OC_DFE_SA_ERR_EVEN__8_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0E2_LN0_MON_RX_OC_DFE_SA_ERR_EVEN__8(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0E2_LN0_MON_RX_OC_DFE_SA_ERR_EVEN__8_SHIFT)) & PCIE_PHY_TRSV_REG0E2_LN0_MON_RX_OC_DFE_SA_ERR_EVEN__8_MASK)
/*! @} */

/*! @name TRSV_REG0E3 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0E3_LN0_MON_RX_OC_DFE_SA_ERR_EVEN__7_0_MASK (0xFFU)
#define PCIE_PHY_TRSV_REG0E3_LN0_MON_RX_OC_DFE_SA_ERR_EVEN__7_0_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0E3_LN0_MON_RX_OC_DFE_SA_ERR_EVEN__7_0(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0E3_LN0_MON_RX_OC_DFE_SA_ERR_EVEN__7_0_SHIFT)) & PCIE_PHY_TRSV_REG0E3_LN0_MON_RX_OC_DFE_SA_ERR_EVEN__7_0_MASK)
/*! @} */

/*! @name TRSV_REG0E4 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0E4_LN0_MON_RX_OC_DFE_SA_ERR_ODD__8_MASK (0x1U)
#define PCIE_PHY_TRSV_REG0E4_LN0_MON_RX_OC_DFE_SA_ERR_ODD__8_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0E4_LN0_MON_RX_OC_DFE_SA_ERR_ODD__8(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0E4_LN0_MON_RX_OC_DFE_SA_ERR_ODD__8_SHIFT)) & PCIE_PHY_TRSV_REG0E4_LN0_MON_RX_OC_DFE_SA_ERR_ODD__8_MASK)
/*! @} */

/*! @name TRSV_REG0E5 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0E5_LN0_MON_RX_OC_DFE_SA_ERR_ODD__7_0_MASK (0xFFU)
#define PCIE_PHY_TRSV_REG0E5_LN0_MON_RX_OC_DFE_SA_ERR_ODD__7_0_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0E5_LN0_MON_RX_OC_DFE_SA_ERR_ODD__7_0(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0E5_LN0_MON_RX_OC_DFE_SA_ERR_ODD__7_0_SHIFT)) & PCIE_PHY_TRSV_REG0E5_LN0_MON_RX_OC_DFE_SA_ERR_ODD__7_0_MASK)
/*! @} */

/*! @name TRSV_REG0E6 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0E6_LN0_MON_RX_OC_DFE_DAC_ERR_ODD_MASK (0x7U)
#define PCIE_PHY_TRSV_REG0E6_LN0_MON_RX_OC_DFE_DAC_ERR_ODD_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0E6_LN0_MON_RX_OC_DFE_DAC_ERR_ODD(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0E6_LN0_MON_RX_OC_DFE_DAC_ERR_ODD_SHIFT)) & PCIE_PHY_TRSV_REG0E6_LN0_MON_RX_OC_DFE_DAC_ERR_ODD_MASK)

#define PCIE_PHY_TRSV_REG0E6_LN0_MON_RX_OC_DFE_DAC_ERR_EVEN_MASK (0x38U)
#define PCIE_PHY_TRSV_REG0E6_LN0_MON_RX_OC_DFE_DAC_ERR_EVEN_SHIFT (3U)
#define PCIE_PHY_TRSV_REG0E6_LN0_MON_RX_OC_DFE_DAC_ERR_EVEN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0E6_LN0_MON_RX_OC_DFE_DAC_ERR_EVEN_SHIFT)) & PCIE_PHY_TRSV_REG0E6_LN0_MON_RX_OC_DFE_DAC_ERR_EVEN_MASK)
/*! @} */

/*! @name TRSV_REG0E7 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0E7_LN0_MON_RX_OC_CTLE_MASK (0x7FU)
#define PCIE_PHY_TRSV_REG0E7_LN0_MON_RX_OC_CTLE_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0E7_LN0_MON_RX_OC_CTLE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0E7_LN0_MON_RX_OC_CTLE_SHIFT)) & PCIE_PHY_TRSV_REG0E7_LN0_MON_RX_OC_CTLE_MASK)
/*! @} */

/*! @name TRSV_REG0E8 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0E8_LN0_MON_RX_OC_SQ_DIFP_MASK (0xFU)
#define PCIE_PHY_TRSV_REG0E8_LN0_MON_RX_OC_SQ_DIFP_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0E8_LN0_MON_RX_OC_SQ_DIFP(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0E8_LN0_MON_RX_OC_SQ_DIFP_SHIFT)) & PCIE_PHY_TRSV_REG0E8_LN0_MON_RX_OC_SQ_DIFP_MASK)

#define PCIE_PHY_TRSV_REG0E8_LN0_MON_RX_OC_SQ_DIFN_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG0E8_LN0_MON_RX_OC_SQ_DIFN_SHIFT (4U)
#define PCIE_PHY_TRSV_REG0E8_LN0_MON_RX_OC_SQ_DIFN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0E8_LN0_MON_RX_OC_SQ_DIFN_SHIFT)) & PCIE_PHY_TRSV_REG0E8_LN0_MON_RX_OC_SQ_DIFN_MASK)
/*! @} */

/*! @name TRSV_REG0E9 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0E9_LN0_MON_RX_OC_CAL_DONE_MASK (0x1U)
#define PCIE_PHY_TRSV_REG0E9_LN0_MON_RX_OC_CAL_DONE_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0E9_LN0_MON_RX_OC_CAL_DONE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0E9_LN0_MON_RX_OC_CAL_DONE_SHIFT)) & PCIE_PHY_TRSV_REG0E9_LN0_MON_RX_OC_CAL_DONE_MASK)
/*! @} */

/*! @name TRSV_REG0EA -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0EA_LN0_MON_RX_OC_FAIL__9_8_MASK (0x3U)
#define PCIE_PHY_TRSV_REG0EA_LN0_MON_RX_OC_FAIL__9_8_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0EA_LN0_MON_RX_OC_FAIL__9_8(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0EA_LN0_MON_RX_OC_FAIL__9_8_SHIFT)) & PCIE_PHY_TRSV_REG0EA_LN0_MON_RX_OC_FAIL__9_8_MASK)
/*! @} */

/*! @name TRSV_REG0EB -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0EB_LN0_MON_RX_OC_FAIL__7_0_MASK (0xFFU)
#define PCIE_PHY_TRSV_REG0EB_LN0_MON_RX_OC_FAIL__7_0_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0EB_LN0_MON_RX_OC_FAIL__7_0(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0EB_LN0_MON_RX_OC_FAIL__7_0_SHIFT)) & PCIE_PHY_TRSV_REG0EB_LN0_MON_RX_OC_FAIL__7_0_MASK)
/*! @} */

/*! @name TRSV_REG0EC -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0EC_LN0_MON_RX_SSLMS_C0__8_MASK (0x1U)
#define PCIE_PHY_TRSV_REG0EC_LN0_MON_RX_SSLMS_C0__8_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0EC_LN0_MON_RX_SSLMS_C0__8(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0EC_LN0_MON_RX_SSLMS_C0__8_SHIFT)) & PCIE_PHY_TRSV_REG0EC_LN0_MON_RX_SSLMS_C0__8_MASK)
/*! @} */

/*! @name TRSV_REG0ED -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0ED_LN0_MON_RX_SSLMS_C0__7_0_MASK (0xFFU)
#define PCIE_PHY_TRSV_REG0ED_LN0_MON_RX_SSLMS_C0__7_0_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0ED_LN0_MON_RX_SSLMS_C0__7_0(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0ED_LN0_MON_RX_SSLMS_C0__7_0_SHIFT)) & PCIE_PHY_TRSV_REG0ED_LN0_MON_RX_SSLMS_C0__7_0_MASK)
/*! @} */

/*! @name TRSV_REG0EE -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0EE_LN0_MON_RX_SSLMS_C2_SGN_MASK (0x1U)
#define PCIE_PHY_TRSV_REG0EE_LN0_MON_RX_SSLMS_C2_SGN_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0EE_LN0_MON_RX_SSLMS_C2_SGN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0EE_LN0_MON_RX_SSLMS_C2_SGN_SHIFT)) & PCIE_PHY_TRSV_REG0EE_LN0_MON_RX_SSLMS_C2_SGN_MASK)

#define PCIE_PHY_TRSV_REG0EE_LN0_MON_RX_SSLMS_C1_MASK (0xFEU)
#define PCIE_PHY_TRSV_REG0EE_LN0_MON_RX_SSLMS_C1_SHIFT (1U)
#define PCIE_PHY_TRSV_REG0EE_LN0_MON_RX_SSLMS_C1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0EE_LN0_MON_RX_SSLMS_C1_SHIFT)) & PCIE_PHY_TRSV_REG0EE_LN0_MON_RX_SSLMS_C1_MASK)
/*! @} */

/*! @name TRSV_REG0EF -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0EF_LN0_MON_RX_SSLMS_C3_SGN_MASK (0x1U)
#define PCIE_PHY_TRSV_REG0EF_LN0_MON_RX_SSLMS_C3_SGN_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0EF_LN0_MON_RX_SSLMS_C3_SGN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0EF_LN0_MON_RX_SSLMS_C3_SGN_SHIFT)) & PCIE_PHY_TRSV_REG0EF_LN0_MON_RX_SSLMS_C3_SGN_MASK)

#define PCIE_PHY_TRSV_REG0EF_LN0_MON_RX_SSLMS_C2_MASK (0x3EU)
#define PCIE_PHY_TRSV_REG0EF_LN0_MON_RX_SSLMS_C2_SHIFT (1U)
#define PCIE_PHY_TRSV_REG0EF_LN0_MON_RX_SSLMS_C2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0EF_LN0_MON_RX_SSLMS_C2_SHIFT)) & PCIE_PHY_TRSV_REG0EF_LN0_MON_RX_SSLMS_C2_MASK)
/*! @} */

/*! @name TRSV_REG0F0 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0F0_LN0_MON_RX_SSLMS_C4_SGN_MASK (0x1U)
#define PCIE_PHY_TRSV_REG0F0_LN0_MON_RX_SSLMS_C4_SGN_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0F0_LN0_MON_RX_SSLMS_C4_SGN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0F0_LN0_MON_RX_SSLMS_C4_SGN_SHIFT)) & PCIE_PHY_TRSV_REG0F0_LN0_MON_RX_SSLMS_C4_SGN_MASK)

#define PCIE_PHY_TRSV_REG0F0_LN0_MON_RX_SSLMS_C3_MASK (0x3EU)
#define PCIE_PHY_TRSV_REG0F0_LN0_MON_RX_SSLMS_C3_SHIFT (1U)
#define PCIE_PHY_TRSV_REG0F0_LN0_MON_RX_SSLMS_C3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0F0_LN0_MON_RX_SSLMS_C3_SHIFT)) & PCIE_PHY_TRSV_REG0F0_LN0_MON_RX_SSLMS_C3_MASK)
/*! @} */

/*! @name TRSV_REG0F1 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0F1_LN0_MON_RX_SSLMS_C5_SGN_MASK (0x1U)
#define PCIE_PHY_TRSV_REG0F1_LN0_MON_RX_SSLMS_C5_SGN_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0F1_LN0_MON_RX_SSLMS_C5_SGN(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0F1_LN0_MON_RX_SSLMS_C5_SGN_SHIFT)) & PCIE_PHY_TRSV_REG0F1_LN0_MON_RX_SSLMS_C5_SGN_MASK)

#define PCIE_PHY_TRSV_REG0F1_LN0_MON_RX_SSLMS_C4_MASK (0x1EU)
#define PCIE_PHY_TRSV_REG0F1_LN0_MON_RX_SSLMS_C4_SHIFT (1U)
#define PCIE_PHY_TRSV_REG0F1_LN0_MON_RX_SSLMS_C4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0F1_LN0_MON_RX_SSLMS_C4_SHIFT)) & PCIE_PHY_TRSV_REG0F1_LN0_MON_RX_SSLMS_C4_MASK)
/*! @} */

/*! @name TRSV_REG0F2 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0F2_LN0_MON_RX_EFOM_DONE_MASK (0x1U)
#define PCIE_PHY_TRSV_REG0F2_LN0_MON_RX_EFOM_DONE_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0F2_LN0_MON_RX_EFOM_DONE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0F2_LN0_MON_RX_EFOM_DONE_SHIFT)) & PCIE_PHY_TRSV_REG0F2_LN0_MON_RX_EFOM_DONE_MASK)

#define PCIE_PHY_TRSV_REG0F2_LN0_MON_RX_SSLMS_ADAP_DONE_MASK (0x2U)
#define PCIE_PHY_TRSV_REG0F2_LN0_MON_RX_SSLMS_ADAP_DONE_SHIFT (1U)
#define PCIE_PHY_TRSV_REG0F2_LN0_MON_RX_SSLMS_ADAP_DONE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0F2_LN0_MON_RX_SSLMS_ADAP_DONE_SHIFT)) & PCIE_PHY_TRSV_REG0F2_LN0_MON_RX_SSLMS_ADAP_DONE_MASK)

#define PCIE_PHY_TRSV_REG0F2_LN0_MON_RX_SSLMS_C5_MASK (0x3CU)
#define PCIE_PHY_TRSV_REG0F2_LN0_MON_RX_SSLMS_C5_SHIFT (2U)
#define PCIE_PHY_TRSV_REG0F2_LN0_MON_RX_SSLMS_C5(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0F2_LN0_MON_RX_SSLMS_C5_SHIFT)) & PCIE_PHY_TRSV_REG0F2_LN0_MON_RX_SSLMS_C5_MASK)
/*! @} */

/*! @name TRSV_REG0F3 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0F3_LN0_MON_RX_EFOM_ERR_CNT__13_8_MASK (0x3FU)
#define PCIE_PHY_TRSV_REG0F3_LN0_MON_RX_EFOM_ERR_CNT__13_8_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0F3_LN0_MON_RX_EFOM_ERR_CNT__13_8(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0F3_LN0_MON_RX_EFOM_ERR_CNT__13_8_SHIFT)) & PCIE_PHY_TRSV_REG0F3_LN0_MON_RX_EFOM_ERR_CNT__13_8_MASK)
/*! @} */

/*! @name TRSV_REG0F4 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0F4_LN0_MON_RX_EFOM_ERR_CNT__7_0_MASK (0xFFU)
#define PCIE_PHY_TRSV_REG0F4_LN0_MON_RX_EFOM_ERR_CNT__7_0_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0F4_LN0_MON_RX_EFOM_ERR_CNT__7_0(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0F4_LN0_MON_RX_EFOM_ERR_CNT__7_0_SHIFT)) & PCIE_PHY_TRSV_REG0F4_LN0_MON_RX_EFOM_ERR_CNT__7_0_MASK)
/*! @} */

/*! @name TRSV_REG0F5 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0F5_LN0_MON_RX_EFOM_FEEDBACK__15_8_MASK (0xFFU)
#define PCIE_PHY_TRSV_REG0F5_LN0_MON_RX_EFOM_FEEDBACK__15_8_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0F5_LN0_MON_RX_EFOM_FEEDBACK__15_8(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0F5_LN0_MON_RX_EFOM_FEEDBACK__15_8_SHIFT)) & PCIE_PHY_TRSV_REG0F5_LN0_MON_RX_EFOM_FEEDBACK__15_8_MASK)
/*! @} */

/*! @name TRSV_REG0F6 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0F6_LN0_MON_RX_EFOM_FEEDBACK__7_0_MASK (0xFFU)
#define PCIE_PHY_TRSV_REG0F6_LN0_MON_RX_EFOM_FEEDBACK__7_0_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0F6_LN0_MON_RX_EFOM_FEEDBACK__7_0(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0F6_LN0_MON_RX_EFOM_FEEDBACK__7_0_SHIFT)) & PCIE_PHY_TRSV_REG0F6_LN0_MON_RX_EFOM_FEEDBACK__7_0_MASK)
/*! @} */

/*! @name TRSV_REG0F7 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0F7_LN0_MON_TX_RCAL_DONE_MASK (0x1U)
#define PCIE_PHY_TRSV_REG0F7_LN0_MON_TX_RCAL_DONE_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0F7_LN0_MON_TX_RCAL_DONE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0F7_LN0_MON_TX_RCAL_DONE_SHIFT)) & PCIE_PHY_TRSV_REG0F7_LN0_MON_TX_RCAL_DONE_MASK)

#define PCIE_PHY_TRSV_REG0F7_LN0_MON_TX_RCAL_TUNE_CODE_MASK (0x1EU)
#define PCIE_PHY_TRSV_REG0F7_LN0_MON_TX_RCAL_TUNE_CODE_SHIFT (1U)
#define PCIE_PHY_TRSV_REG0F7_LN0_MON_TX_RCAL_TUNE_CODE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0F7_LN0_MON_TX_RCAL_TUNE_CODE_SHIFT)) & PCIE_PHY_TRSV_REG0F7_LN0_MON_TX_RCAL_TUNE_CODE_MASK)
/*! @} */

/*! @name TRSV_REG0F8 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0F8_LN0_MON_RX_PWM_AFC_REPEAT_MASK (0x1U)
#define PCIE_PHY_TRSV_REG0F8_LN0_MON_RX_PWM_AFC_REPEAT_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0F8_LN0_MON_RX_PWM_AFC_REPEAT(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0F8_LN0_MON_RX_PWM_AFC_REPEAT_SHIFT)) & PCIE_PHY_TRSV_REG0F8_LN0_MON_RX_PWM_AFC_REPEAT_MASK)

#define PCIE_PHY_TRSV_REG0F8_LN0_MON_RX_PWM_AFC_FAIL_MASK (0x2U)
#define PCIE_PHY_TRSV_REG0F8_LN0_MON_RX_PWM_AFC_FAIL_SHIFT (1U)
#define PCIE_PHY_TRSV_REG0F8_LN0_MON_RX_PWM_AFC_FAIL(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0F8_LN0_MON_RX_PWM_AFC_FAIL_SHIFT)) & PCIE_PHY_TRSV_REG0F8_LN0_MON_RX_PWM_AFC_FAIL_MASK)

#define PCIE_PHY_TRSV_REG0F8_LN0_MON_RX_PWM_AFC_DONE_MASK (0x4U)
#define PCIE_PHY_TRSV_REG0F8_LN0_MON_RX_PWM_AFC_DONE_SHIFT (2U)
#define PCIE_PHY_TRSV_REG0F8_LN0_MON_RX_PWM_AFC_DONE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0F8_LN0_MON_RX_PWM_AFC_DONE_SHIFT)) & PCIE_PHY_TRSV_REG0F8_LN0_MON_RX_PWM_AFC_DONE_MASK)

#define PCIE_PHY_TRSV_REG0F8_LN0_MON_RX_RCAL_DONE_MASK (0x8U)
#define PCIE_PHY_TRSV_REG0F8_LN0_MON_RX_RCAL_DONE_SHIFT (3U)
#define PCIE_PHY_TRSV_REG0F8_LN0_MON_RX_RCAL_DONE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0F8_LN0_MON_RX_RCAL_DONE_SHIFT)) & PCIE_PHY_TRSV_REG0F8_LN0_MON_RX_RCAL_DONE_MASK)

#define PCIE_PHY_TRSV_REG0F8_LN0_MON_RX_RCAL_TUNE_CODE_MASK (0xF0U)
#define PCIE_PHY_TRSV_REG0F8_LN0_MON_RX_RCAL_TUNE_CODE_SHIFT (4U)
#define PCIE_PHY_TRSV_REG0F8_LN0_MON_RX_RCAL_TUNE_CODE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0F8_LN0_MON_RX_RCAL_TUNE_CODE_SHIFT)) & PCIE_PHY_TRSV_REG0F8_LN0_MON_RX_RCAL_TUNE_CODE_MASK)
/*! @} */

/*! @name TRSV_REG0F9 -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0F9_LN0_MON_RX_PWM_AFC_CODE_MASK (0xFU)
#define PCIE_PHY_TRSV_REG0F9_LN0_MON_RX_PWM_AFC_CODE_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0F9_LN0_MON_RX_PWM_AFC_CODE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0F9_LN0_MON_RX_PWM_AFC_CODE_SHIFT)) & PCIE_PHY_TRSV_REG0F9_LN0_MON_RX_PWM_AFC_CODE_MASK)
/*! @} */

/*! @name TRSV_REG0FA -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0FA_LN0_MON_BIST_COMP_START_MASK (0x1U)
#define PCIE_PHY_TRSV_REG0FA_LN0_MON_BIST_COMP_START_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0FA_LN0_MON_BIST_COMP_START(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0FA_LN0_MON_BIST_COMP_START_SHIFT)) & PCIE_PHY_TRSV_REG0FA_LN0_MON_BIST_COMP_START_MASK)

#define PCIE_PHY_TRSV_REG0FA_LN0_MON_BIST_ERRINJ_TEST_MASK (0x2U)
#define PCIE_PHY_TRSV_REG0FA_LN0_MON_BIST_ERRINJ_TEST_SHIFT (1U)
#define PCIE_PHY_TRSV_REG0FA_LN0_MON_BIST_ERRINJ_TEST(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0FA_LN0_MON_BIST_ERRINJ_TEST_SHIFT)) & PCIE_PHY_TRSV_REG0FA_LN0_MON_BIST_ERRINJ_TEST_MASK)

#define PCIE_PHY_TRSV_REG0FA_LN0_MON_BIST_COMP_TEST_MASK (0x4U)
#define PCIE_PHY_TRSV_REG0FA_LN0_MON_BIST_COMP_TEST_SHIFT (2U)
#define PCIE_PHY_TRSV_REG0FA_LN0_MON_BIST_COMP_TEST(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0FA_LN0_MON_BIST_COMP_TEST_SHIFT)) & PCIE_PHY_TRSV_REG0FA_LN0_MON_BIST_COMP_TEST_MASK)

#define PCIE_PHY_TRSV_REG0FA_LN0_MON_RX_CDR_LOCK_DONE_MASK (0x8U)
#define PCIE_PHY_TRSV_REG0FA_LN0_MON_RX_CDR_LOCK_DONE_SHIFT (3U)
#define PCIE_PHY_TRSV_REG0FA_LN0_MON_RX_CDR_LOCK_DONE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0FA_LN0_MON_RX_CDR_LOCK_DONE_SHIFT)) & PCIE_PHY_TRSV_REG0FA_LN0_MON_RX_CDR_LOCK_DONE_MASK)

#define PCIE_PHY_TRSV_REG0FA_LN0_MON_RX_CDR_FLD_PLL_MODE_DONE_MASK (0x10U)
#define PCIE_PHY_TRSV_REG0FA_LN0_MON_RX_CDR_FLD_PLL_MODE_DONE_SHIFT (4U)
#define PCIE_PHY_TRSV_REG0FA_LN0_MON_RX_CDR_FLD_PLL_MODE_DONE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0FA_LN0_MON_RX_CDR_FLD_PLL_MODE_DONE_SHIFT)) & PCIE_PHY_TRSV_REG0FA_LN0_MON_RX_CDR_FLD_PLL_MODE_DONE_MASK)

#define PCIE_PHY_TRSV_REG0FA_LN0_MON_RX_CDR_CAL_DONE_MASK (0x20U)
#define PCIE_PHY_TRSV_REG0FA_LN0_MON_RX_CDR_CAL_DONE_SHIFT (5U)
#define PCIE_PHY_TRSV_REG0FA_LN0_MON_RX_CDR_CAL_DONE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0FA_LN0_MON_RX_CDR_CAL_DONE_SHIFT)) & PCIE_PHY_TRSV_REG0FA_LN0_MON_RX_CDR_CAL_DONE_MASK)

#define PCIE_PHY_TRSV_REG0FA_LN0_MON_RX_CDR_AFC_DONE_MASK (0x40U)
#define PCIE_PHY_TRSV_REG0FA_LN0_MON_RX_CDR_AFC_DONE_SHIFT (6U)
#define PCIE_PHY_TRSV_REG0FA_LN0_MON_RX_CDR_AFC_DONE(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0FA_LN0_MON_RX_CDR_AFC_DONE_SHIFT)) & PCIE_PHY_TRSV_REG0FA_LN0_MON_RX_CDR_AFC_DONE_MASK)
/*! @} */

/*! @name TRSV_REG0FB -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0FB_LN0_MON_BIST_EOUT_MASK (0xFFU)
#define PCIE_PHY_TRSV_REG0FB_LN0_MON_BIST_EOUT_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0FB_LN0_MON_BIST_EOUT(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0FB_LN0_MON_BIST_EOUT_SHIFT)) & PCIE_PHY_TRSV_REG0FB_LN0_MON_BIST_EOUT_MASK)
/*! @} */

/*! @name TRSV_REG0FC -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0FC_LN0_ANA_TX_DRV_ACCDRV_CTRL_G2_MASK (0x7U)
#define PCIE_PHY_TRSV_REG0FC_LN0_ANA_TX_DRV_ACCDRV_CTRL_G2_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0FC_LN0_ANA_TX_DRV_ACCDRV_CTRL_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0FC_LN0_ANA_TX_DRV_ACCDRV_CTRL_G2_SHIFT)) & PCIE_PHY_TRSV_REG0FC_LN0_ANA_TX_DRV_ACCDRV_CTRL_G2_MASK)

#define PCIE_PHY_TRSV_REG0FC_LN0_ANA_TX_DRV_ACCDRV_POL_SEL_G2_MASK (0x8U)
#define PCIE_PHY_TRSV_REG0FC_LN0_ANA_TX_DRV_ACCDRV_POL_SEL_G2_SHIFT (3U)
#define PCIE_PHY_TRSV_REG0FC_LN0_ANA_TX_DRV_ACCDRV_POL_SEL_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0FC_LN0_ANA_TX_DRV_ACCDRV_POL_SEL_G2_SHIFT)) & PCIE_PHY_TRSV_REG0FC_LN0_ANA_TX_DRV_ACCDRV_POL_SEL_G2_MASK)

#define PCIE_PHY_TRSV_REG0FC_LN0_ANA_TX_DRV_ACCDRV_CTRL_G1_MASK (0x70U)
#define PCIE_PHY_TRSV_REG0FC_LN0_ANA_TX_DRV_ACCDRV_CTRL_G1_SHIFT (4U)
#define PCIE_PHY_TRSV_REG0FC_LN0_ANA_TX_DRV_ACCDRV_CTRL_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0FC_LN0_ANA_TX_DRV_ACCDRV_CTRL_G1_SHIFT)) & PCIE_PHY_TRSV_REG0FC_LN0_ANA_TX_DRV_ACCDRV_CTRL_G1_MASK)

#define PCIE_PHY_TRSV_REG0FC_LN0_ANA_TX_DRV_ACCDRV_POL_SEL_G1_MASK (0x80U)
#define PCIE_PHY_TRSV_REG0FC_LN0_ANA_TX_DRV_ACCDRV_POL_SEL_G1_SHIFT (7U)
#define PCIE_PHY_TRSV_REG0FC_LN0_ANA_TX_DRV_ACCDRV_POL_SEL_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0FC_LN0_ANA_TX_DRV_ACCDRV_POL_SEL_G1_SHIFT)) & PCIE_PHY_TRSV_REG0FC_LN0_ANA_TX_DRV_ACCDRV_POL_SEL_G1_MASK)
/*! @} */

/*! @name TRSV_REG0FD -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0FD_LN0_ANA_TX_DRV_ACCDRV_CTRL_G4_MASK (0x7U)
#define PCIE_PHY_TRSV_REG0FD_LN0_ANA_TX_DRV_ACCDRV_CTRL_G4_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0FD_LN0_ANA_TX_DRV_ACCDRV_CTRL_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0FD_LN0_ANA_TX_DRV_ACCDRV_CTRL_G4_SHIFT)) & PCIE_PHY_TRSV_REG0FD_LN0_ANA_TX_DRV_ACCDRV_CTRL_G4_MASK)

#define PCIE_PHY_TRSV_REG0FD_LN0_ANA_TX_DRV_ACCDRV_POL_SEL_G4_MASK (0x8U)
#define PCIE_PHY_TRSV_REG0FD_LN0_ANA_TX_DRV_ACCDRV_POL_SEL_G4_SHIFT (3U)
#define PCIE_PHY_TRSV_REG0FD_LN0_ANA_TX_DRV_ACCDRV_POL_SEL_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0FD_LN0_ANA_TX_DRV_ACCDRV_POL_SEL_G4_SHIFT)) & PCIE_PHY_TRSV_REG0FD_LN0_ANA_TX_DRV_ACCDRV_POL_SEL_G4_MASK)

#define PCIE_PHY_TRSV_REG0FD_LN0_ANA_TX_DRV_ACCDRV_CTRL_G3_MASK (0x70U)
#define PCIE_PHY_TRSV_REG0FD_LN0_ANA_TX_DRV_ACCDRV_CTRL_G3_SHIFT (4U)
#define PCIE_PHY_TRSV_REG0FD_LN0_ANA_TX_DRV_ACCDRV_CTRL_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0FD_LN0_ANA_TX_DRV_ACCDRV_CTRL_G3_SHIFT)) & PCIE_PHY_TRSV_REG0FD_LN0_ANA_TX_DRV_ACCDRV_CTRL_G3_MASK)

#define PCIE_PHY_TRSV_REG0FD_LN0_ANA_TX_DRV_ACCDRV_POL_SEL_G3_MASK (0x80U)
#define PCIE_PHY_TRSV_REG0FD_LN0_ANA_TX_DRV_ACCDRV_POL_SEL_G3_SHIFT (7U)
#define PCIE_PHY_TRSV_REG0FD_LN0_ANA_TX_DRV_ACCDRV_POL_SEL_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0FD_LN0_ANA_TX_DRV_ACCDRV_POL_SEL_G3_SHIFT)) & PCIE_PHY_TRSV_REG0FD_LN0_ANA_TX_DRV_ACCDRV_POL_SEL_G3_MASK)
/*! @} */

/*! @name TRSV_REG0FE -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0FE_LN0_ANA_RX_CDR_AFC_VCI_SEL_G2_MASK (0x7U)
#define PCIE_PHY_TRSV_REG0FE_LN0_ANA_RX_CDR_AFC_VCI_SEL_G2_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0FE_LN0_ANA_RX_CDR_AFC_VCI_SEL_G2(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0FE_LN0_ANA_RX_CDR_AFC_VCI_SEL_G2_SHIFT)) & PCIE_PHY_TRSV_REG0FE_LN0_ANA_RX_CDR_AFC_VCI_SEL_G2_MASK)

#define PCIE_PHY_TRSV_REG0FE_LN0_ANA_RX_CDR_AFC_VCI_SEL_G1_MASK (0x70U)
#define PCIE_PHY_TRSV_REG0FE_LN0_ANA_RX_CDR_AFC_VCI_SEL_G1_SHIFT (4U)
#define PCIE_PHY_TRSV_REG0FE_LN0_ANA_RX_CDR_AFC_VCI_SEL_G1(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0FE_LN0_ANA_RX_CDR_AFC_VCI_SEL_G1_SHIFT)) & PCIE_PHY_TRSV_REG0FE_LN0_ANA_RX_CDR_AFC_VCI_SEL_G1_MASK)
/*! @} */

/*! @name TRSV_REG0FF -  */
/*! @{ */

#define PCIE_PHY_TRSV_REG0FF_LN0_ANA_RX_CDR_AFC_VCI_SEL_G4_MASK (0x7U)
#define PCIE_PHY_TRSV_REG0FF_LN0_ANA_RX_CDR_AFC_VCI_SEL_G4_SHIFT (0U)
#define PCIE_PHY_TRSV_REG0FF_LN0_ANA_RX_CDR_AFC_VCI_SEL_G4(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0FF_LN0_ANA_RX_CDR_AFC_VCI_SEL_G4_SHIFT)) & PCIE_PHY_TRSV_REG0FF_LN0_ANA_RX_CDR_AFC_VCI_SEL_G4_MASK)

#define PCIE_PHY_TRSV_REG0FF_LN0_ANA_RX_CDR_AFC_VCI_SEL_G3_MASK (0x70U)
#define PCIE_PHY_TRSV_REG0FF_LN0_ANA_RX_CDR_AFC_VCI_SEL_G3_SHIFT (4U)
#define PCIE_PHY_TRSV_REG0FF_LN0_ANA_RX_CDR_AFC_VCI_SEL_G3(x) (((uint8_t)(((uint8_t)(x)) << PCIE_PHY_TRSV_REG0FF_LN0_ANA_RX_CDR_AFC_VCI_SEL_G3_SHIFT)) & PCIE_PHY_TRSV_REG0FF_LN0_ANA_RX_CDR_AFC_VCI_SEL_G3_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group PCIE_PHY_Register_Masks */


/*!
 * @}
 */ /* end of group PCIE_PHY_Peripheral_Access_Layer */


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


#endif  /* PERI_PCIE_PHY_H_ */

