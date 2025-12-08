/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K566_VFCCU_0.h
 * @version 2.2
 * @date 2025-10-16
 * @brief Peripheral Access Layer for S32K566_VFCCU_0
 *
 * This file contains register definitions and macros for easy access to their
 * bit fields.
 *
 * This file assumes LITTLE endian system.
 */

/**
* @page misra_violations MISRA-C:2012 violations
*
* @section [global]
* Violates MISRA 2012 Advisory Rule 2.3, local typedef not referenced
* The SoC header defines typedef for all modules.
*
* @section [global]
* Violates MISRA 2012 Advisory Rule 2.5, local macro not referenced
* The SoC header defines macros for all modules and registers.
*
* @section [global]
* Violates MISRA 2012 Advisory Directive 4.9, Function-like macro
* These are generated macros used for accessing the bit-fields from registers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.1, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.2, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.4, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.5, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 21.1, defined macro '__I' is reserved to the compiler
* This type qualifier is needed to ensure correct I/O access and addressing.
*/

/* Prevention from multiple including the same memory map */
#if !defined(S32K566_VFCCU_0_H_)  /* Check if memory map has not been already included */
#define S32K566_VFCCU_0_H_

#include "S32K566_COMMON.h"

/* ----------------------------------------------------------------------------
   -- VFCCU_0 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VFCCU_0_Peripheral_Access_Layer VFCCU_0 Peripheral Access Layer
 * @{
 */

/** VFCCU_0 - Size of Registers Arrays */
#define VFCCU_0_GRKNTIMC_COUNT                    1u
#define VFCCU_0_GLB_EOUT_COUNT                    2u

/** VFCCU_0 - Register Layout Typedef */
typedef struct VFCCU_0_Struct {
  uint8_t RESERVED_0[768];
  __IO uint32_t GRKNTIMC[VFCCU_0_GRKNTIMC_COUNT];  /**< Global Reaction Timer Period, array offset: 0x300, array step: 0x4 */
  uint8_t RESERVED_1[316];
  __IO uint32_t GFLTRC_C0;                         /**< Global Fault Recovery, offset: 0x440 */
  __IO uint32_t GFLTRC_C1;                         /**< Global Fault Recovery, offset: 0x444 */
  uint8_t RESERVED_2[2232];
  __I  uint32_t GRKNTIMS;                          /**< Global Reaction Timer Status, offset: 0xD00 */
  uint8_t RESERVED_3[4];
  __I  uint32_t GINTOVFS;                          /**< Global DID FSM Status, offset: 0xD08 */
  uint8_t RESERVED_4[20];
  __IO uint32_t GMEOUTDC;                          /**< Global Minimum EOUT Duration, offset: 0xD20 */
  __IO uint32_t GEOUTTCT;                          /**< Global EOUT Timer Disable, offset: 0xD24 */
  uint8_t RESERVED_5[8];
  struct VFCCU_0_GLB_EOUT {                        /* offset: 0xD30, array step: 0x14 */
    __IO uint32_t GEOUTPNC;                          /**< Global EOUT Pin, array offset: 0xD30, array step: 0x14 */
    __IO uint32_t GEOUTPMC;                          /**< Global EOUT Pin Map, array offset: 0xD34, array step: 0x14 */
    __IO uint32_t GEOUTMC;                           /**< Global EOUT Mode, array offset: 0xD38, array step: 0x14 */
    __I  uint32_t GEOUTTMS;                          /**< Global EOUT Timer Status, array offset: 0xD3C, array step: 0x14 */
    __IO uint32_t GEOUTDIC;                          /**< Global EOUT DID, array offset: 0xD40, array step: 0x14 */
  } GLB_EOUT[VFCCU_0_GLB_EOUT_COUNT];
  uint8_t RESERVED_6[600];
  __IO uint32_t GDBGCFG;                           /**< Global Debug, offset: 0xFB0 */
  __I  uint32_t GDBGSTAT;                          /**< Global Debug Status, offset: 0xFB4 */
  __I  uint32_t GDPFSTAT;                          /**< Global Debug Pending Fault Status, offset: 0xFB8 */
  __I  uint32_t GDALTRLD;                          /**< Global Debug Alternate Reload Status, offset: 0xFBC */
  uint8_t RESERVED_7[64];
  __IO uint32_t FHCFG0;                            /**< Fault Handler, offset: 0x1000 */
  __I  uint32_t FHSRVDS0;                          /**< Fault Handler Status, offset: 0x1004 */
  uint8_t RESERVED_8[8];
  __IO uint32_t FHFLTENC0_0;                       /**< Fault Enable, offset: 0x1010 */
  __IO uint32_t FHFLTENC0_1;                       /**< Fault Enable, offset: 0x1014 */
  uint8_t RESERVED_9[56];
  __IO uint32_t FHFLTS0_0;                         /**< Fault Status, offset: 0x1050 */
  __IO uint32_t FHFLTS0_1;                         /**< Fault Status, offset: 0x1054 */
  uint8_t RESERVED_10[56];
  __IO uint32_t FHFLTRKC0_0;                       /**< Fault Reaction Set Configuration, offset: 0x1090 */
  __IO uint32_t FHFLTRKC0_1;                       /**< Fault Reaction Set Configuration, offset: 0x1094 */
  __IO uint32_t FHFLTRKC0_2;                       /**< Fault Reaction Set Configuration, offset: 0x1098 */
  __IO uint32_t FHFLTRKC0_3;                       /**< Fault Reaction Set Configuration, offset: 0x109C */
  __IO uint32_t FHFLTRKC0_4;                       /**< Fault Reaction Set Configuration, offset: 0x10A0 */
  __IO uint32_t FHFLTRKC0_5;                       /**< Fault Reaction Set Configuration, offset: 0x10A4 */
  __IO uint32_t FHFLTRKC0_6;                       /**< Fault Reaction Set Configuration, offset: 0x10A8 */
  __IO uint32_t FHFLTRKC0_7;                       /**< Fault Reaction Set Configuration, offset: 0x10AC */
  __IO uint32_t FHFLTRKC0_8;                       /**< Fault Reaction Set Configuration, offset: 0x10B0 */
  __IO uint32_t FHFLTRKC0_9;                       /**< Fault Reaction Set Configuration, offset: 0x10B4 */
  __IO uint32_t FHFLTRKC0_10;                      /**< Fault Reaction Set Configuration, offset: 0x10B8 */
  __IO uint32_t FHFLTRKC0_11;                      /**< Fault Reaction Set Configuration, offset: 0x10BC */
  __IO uint32_t FHFLTRKC0_12;                      /**< Fault Reaction Set Configuration, offset: 0x10C0 */
  __IO uint32_t FHFLTRKC0_13;                      /**< Fault Reaction Set Configuration, offset: 0x10C4 */
  __IO uint32_t FHFLTRKC0_14;                      /**< Fault Reaction Set Configuration, offset: 0x10C8 */
  __IO uint32_t FHFLTRKC0_15;                      /**< Fault Reaction Set Configuration, offset: 0x10CC */
  uint8_t RESERVED_11[448];
  __IO uint32_t FHIMRKC0_00;                       /**< Immediate Reaction Configuration, offset: 0x1290 */
  uint8_t RESERVED_12[12];
  __IO uint32_t FHDLRKC0_00;                       /**< Delayed Reaction Configuration, offset: 0x12A0 */
  uint8_t RESERVED_13[12];
  __IO uint32_t FHIMRKC0_10;                       /**< Immediate Reaction Configuration, offset: 0x12B0 */
  uint8_t RESERVED_14[12];
  __IO uint32_t FHDLRKC0_10;                       /**< Delayed Reaction Configuration, offset: 0x12C0 */
  uint8_t RESERVED_15[12];
  __IO uint32_t FHIMRKC0_20;                       /**< Immediate Reaction Configuration, offset: 0x12D0 */
  uint8_t RESERVED_16[12];
  __IO uint32_t FHDLRKC0_20;                       /**< Delayed Reaction Configuration, offset: 0x12E0 */
  uint8_t RESERVED_17[12];
  __IO uint32_t FHIMRKC0_30;                       /**< Immediate Reaction Configuration, offset: 0x12F0 */
  uint8_t RESERVED_18[12];
  __IO uint32_t FHDLRKC0_30;                       /**< Delayed Reaction Configuration, offset: 0x1300 */
  uint8_t RESERVED_19[12];
  __IO uint32_t FHIMRKC0_40;                       /**< Immediate Reaction Configuration, offset: 0x1310 */
  uint8_t RESERVED_20[12];
  __IO uint32_t FHDLRKC0_40;                       /**< Delayed Reaction Configuration, offset: 0x1320 */
  uint8_t RESERVED_21[12];
  __IO uint32_t FHIMRKC0_50;                       /**< Immediate Reaction Configuration, offset: 0x1330 */
  uint8_t RESERVED_22[12];
  __IO uint32_t FHDLRKC0_50;                       /**< Delayed Reaction Configuration, offset: 0x1340 */
  uint8_t RESERVED_23[12];
  __IO uint32_t FHIMRKC0_60;                       /**< Immediate Reaction Configuration, offset: 0x1350 */
  uint8_t RESERVED_24[12];
  __IO uint32_t FHDLRKC0_60;                       /**< Delayed Reaction Configuration, offset: 0x1360 */
  uint8_t RESERVED_25[12];
  __IO uint32_t FHIMRKC0_70;                       /**< Immediate Reaction Configuration, offset: 0x1370 */
  uint8_t RESERVED_26[12];
  __IO uint32_t FHDLRKC0_70;                       /**< Delayed Reaction Configuration, offset: 0x1380 */
  uint8_t RESERVED_27[12];
  __IO uint32_t FHIMRKC0_80;                       /**< Immediate Reaction Configuration, offset: 0x1390 */
  uint8_t RESERVED_28[12];
  __IO uint32_t FHDLRKC0_80;                       /**< Delayed Reaction Configuration, offset: 0x13A0 */
  uint8_t RESERVED_29[12];
  __IO uint32_t FHIMRKC0_90;                       /**< Immediate Reaction Configuration, offset: 0x13B0 */
  uint8_t RESERVED_30[12];
  __IO uint32_t FHDLRKC0_90;                       /**< Delayed Reaction Configuration, offset: 0x13C0 */
  uint8_t RESERVED_31[12];
  __IO uint32_t FHIMRKC0_100;                      /**< Immediate Reaction Configuration, offset: 0x13D0 */
  uint8_t RESERVED_32[12];
  __IO uint32_t FHDLRKC0_100;                      /**< Delayed Reaction Configuration, offset: 0x13E0 */
  uint8_t RESERVED_33[12];
  __IO uint32_t FHIMRKC0_110;                      /**< Immediate Reaction Configuration, offset: 0x13F0 */
  uint8_t RESERVED_34[12];
  __IO uint32_t FHDLRKC0_110;                      /**< Delayed Reaction Configuration, offset: 0x1400 */
  uint8_t RESERVED_35[12];
  __IO uint32_t FHIMRKC0_120;                      /**< Immediate Reaction Configuration, offset: 0x1410 */
  uint8_t RESERVED_36[12];
  __IO uint32_t FHDLRKC0_120;                      /**< Delayed Reaction Configuration, offset: 0x1420 */
  uint8_t RESERVED_37[12];
  __IO uint32_t FHIMRKC0_130;                      /**< Immediate Reaction Configuration, offset: 0x1430 */
  uint8_t RESERVED_38[12];
  __IO uint32_t FHDLRKC0_130;                      /**< Delayed Reaction Configuration, offset: 0x1440 */
  uint8_t RESERVED_39[12];
  __IO uint32_t FHIMRKC0_140;                      /**< Immediate Reaction Configuration, offset: 0x1450 */
  uint8_t RESERVED_40[12];
  __IO uint32_t FHDLRKC0_140;                      /**< Delayed Reaction Configuration, offset: 0x1460 */
  uint8_t RESERVED_41[12];
  __IO uint32_t FHIMRKC0_150;                      /**< Immediate Reaction Configuration, offset: 0x1470 */
  uint8_t RESERVED_42[12];
  __IO uint32_t FHDLRKC0_150;                      /**< Delayed Reaction Configuration, offset: 0x1480 */
} VFCCU_0_Type, *VFCCU_0_MemMapPtr;

/** Number of instances of the VFCCU_0 module. */
#define VFCCU_0_INSTANCE_COUNT                   (1u)

/* VFCCU_0 - Peripheral instance base addresses */
/** Peripheral VFCCU_0 base address */
#define IP_VFCCU_0_BASE                          (0x40B44000u)
/** Peripheral VFCCU_0 base pointer */
#define IP_VFCCU_0                               ((VFCCU_0_Type *)IP_VFCCU_0_BASE)
/** Array initializer of VFCCU_0 peripheral base addresses */
#define IP_VFCCU_0_BASE_ADDRS                    { IP_VFCCU_0_BASE }
/** Array initializer of VFCCU_0 peripheral base pointers */
#define IP_VFCCU_0_BASE_PTRS                     { IP_VFCCU_0 }

/* ----------------------------------------------------------------------------
   -- VFCCU_0 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VFCCU_0_Register_Masks VFCCU_0 Register Masks
 * @{
 */

/*! @name GRKNTIMC - Global Reaction Timer Period */
/*! @{ */

#define VFCCU_0_GRKNTIMC_RKTIMCFG_MASK           (0xFFFFFFFFU)
#define VFCCU_0_GRKNTIMC_RKTIMCFG_SHIFT          (0U)
#define VFCCU_0_GRKNTIMC_RKTIMCFG_WIDTH          (32U)
#define VFCCU_0_GRKNTIMC_RKTIMCFG(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GRKNTIMC_RKTIMCFG_SHIFT)) & VFCCU_0_GRKNTIMC_RKTIMCFG_MASK)
/*! @} */

/*! @name GFLTRC_C0 - Global Fault Recovery */
/*! @{ */

#define VFCCU_0_GFLTRC_C0_RHWSW0_MASK            (0x1U)
#define VFCCU_0_GFLTRC_C0_RHWSW0_SHIFT           (0U)
#define VFCCU_0_GFLTRC_C0_RHWSW0_WIDTH           (1U)
#define VFCCU_0_GFLTRC_C0_RHWSW0(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GFLTRC_C0_RHWSW0_SHIFT)) & VFCCU_0_GFLTRC_C0_RHWSW0_MASK)

#define VFCCU_0_GFLTRC_C0_RHWSW1_MASK            (0x2U)
#define VFCCU_0_GFLTRC_C0_RHWSW1_SHIFT           (1U)
#define VFCCU_0_GFLTRC_C0_RHWSW1_WIDTH           (1U)
#define VFCCU_0_GFLTRC_C0_RHWSW1(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GFLTRC_C0_RHWSW1_SHIFT)) & VFCCU_0_GFLTRC_C0_RHWSW1_MASK)

#define VFCCU_0_GFLTRC_C0_RHWSW2_MASK            (0x4U)
#define VFCCU_0_GFLTRC_C0_RHWSW2_SHIFT           (2U)
#define VFCCU_0_GFLTRC_C0_RHWSW2_WIDTH           (1U)
#define VFCCU_0_GFLTRC_C0_RHWSW2(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GFLTRC_C0_RHWSW2_SHIFT)) & VFCCU_0_GFLTRC_C0_RHWSW2_MASK)

#define VFCCU_0_GFLTRC_C0_RHWSW3_MASK            (0x8U)
#define VFCCU_0_GFLTRC_C0_RHWSW3_SHIFT           (3U)
#define VFCCU_0_GFLTRC_C0_RHWSW3_WIDTH           (1U)
#define VFCCU_0_GFLTRC_C0_RHWSW3(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GFLTRC_C0_RHWSW3_SHIFT)) & VFCCU_0_GFLTRC_C0_RHWSW3_MASK)

#define VFCCU_0_GFLTRC_C0_RHWSW4_MASK            (0x10U)
#define VFCCU_0_GFLTRC_C0_RHWSW4_SHIFT           (4U)
#define VFCCU_0_GFLTRC_C0_RHWSW4_WIDTH           (1U)
#define VFCCU_0_GFLTRC_C0_RHWSW4(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GFLTRC_C0_RHWSW4_SHIFT)) & VFCCU_0_GFLTRC_C0_RHWSW4_MASK)

#define VFCCU_0_GFLTRC_C0_RHWSW5_MASK            (0x20U)
#define VFCCU_0_GFLTRC_C0_RHWSW5_SHIFT           (5U)
#define VFCCU_0_GFLTRC_C0_RHWSW5_WIDTH           (1U)
#define VFCCU_0_GFLTRC_C0_RHWSW5(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GFLTRC_C0_RHWSW5_SHIFT)) & VFCCU_0_GFLTRC_C0_RHWSW5_MASK)

#define VFCCU_0_GFLTRC_C0_RHWSW6_MASK            (0x40U)
#define VFCCU_0_GFLTRC_C0_RHWSW6_SHIFT           (6U)
#define VFCCU_0_GFLTRC_C0_RHWSW6_WIDTH           (1U)
#define VFCCU_0_GFLTRC_C0_RHWSW6(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GFLTRC_C0_RHWSW6_SHIFT)) & VFCCU_0_GFLTRC_C0_RHWSW6_MASK)

#define VFCCU_0_GFLTRC_C0_RHWSW7_MASK            (0x80U)
#define VFCCU_0_GFLTRC_C0_RHWSW7_SHIFT           (7U)
#define VFCCU_0_GFLTRC_C0_RHWSW7_WIDTH           (1U)
#define VFCCU_0_GFLTRC_C0_RHWSW7(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GFLTRC_C0_RHWSW7_SHIFT)) & VFCCU_0_GFLTRC_C0_RHWSW7_MASK)

#define VFCCU_0_GFLTRC_C0_RHWSW8_MASK            (0x100U)
#define VFCCU_0_GFLTRC_C0_RHWSW8_SHIFT           (8U)
#define VFCCU_0_GFLTRC_C0_RHWSW8_WIDTH           (1U)
#define VFCCU_0_GFLTRC_C0_RHWSW8(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GFLTRC_C0_RHWSW8_SHIFT)) & VFCCU_0_GFLTRC_C0_RHWSW8_MASK)

#define VFCCU_0_GFLTRC_C0_RHWSW9_MASK            (0x200U)
#define VFCCU_0_GFLTRC_C0_RHWSW9_SHIFT           (9U)
#define VFCCU_0_GFLTRC_C0_RHWSW9_WIDTH           (1U)
#define VFCCU_0_GFLTRC_C0_RHWSW9(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GFLTRC_C0_RHWSW9_SHIFT)) & VFCCU_0_GFLTRC_C0_RHWSW9_MASK)

#define VFCCU_0_GFLTRC_C0_RHWSW10_MASK           (0x400U)
#define VFCCU_0_GFLTRC_C0_RHWSW10_SHIFT          (10U)
#define VFCCU_0_GFLTRC_C0_RHWSW10_WIDTH          (1U)
#define VFCCU_0_GFLTRC_C0_RHWSW10(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GFLTRC_C0_RHWSW10_SHIFT)) & VFCCU_0_GFLTRC_C0_RHWSW10_MASK)

#define VFCCU_0_GFLTRC_C0_RHWSW11_MASK           (0x800U)
#define VFCCU_0_GFLTRC_C0_RHWSW11_SHIFT          (11U)
#define VFCCU_0_GFLTRC_C0_RHWSW11_WIDTH          (1U)
#define VFCCU_0_GFLTRC_C0_RHWSW11(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GFLTRC_C0_RHWSW11_SHIFT)) & VFCCU_0_GFLTRC_C0_RHWSW11_MASK)

#define VFCCU_0_GFLTRC_C0_RHWSW12_MASK           (0x1000U)
#define VFCCU_0_GFLTRC_C0_RHWSW12_SHIFT          (12U)
#define VFCCU_0_GFLTRC_C0_RHWSW12_WIDTH          (1U)
#define VFCCU_0_GFLTRC_C0_RHWSW12(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GFLTRC_C0_RHWSW12_SHIFT)) & VFCCU_0_GFLTRC_C0_RHWSW12_MASK)

#define VFCCU_0_GFLTRC_C0_RHWSW13_MASK           (0x2000U)
#define VFCCU_0_GFLTRC_C0_RHWSW13_SHIFT          (13U)
#define VFCCU_0_GFLTRC_C0_RHWSW13_WIDTH          (1U)
#define VFCCU_0_GFLTRC_C0_RHWSW13(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GFLTRC_C0_RHWSW13_SHIFT)) & VFCCU_0_GFLTRC_C0_RHWSW13_MASK)

#define VFCCU_0_GFLTRC_C0_RHWSW14_MASK           (0x4000U)
#define VFCCU_0_GFLTRC_C0_RHWSW14_SHIFT          (14U)
#define VFCCU_0_GFLTRC_C0_RHWSW14_WIDTH          (1U)
#define VFCCU_0_GFLTRC_C0_RHWSW14(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GFLTRC_C0_RHWSW14_SHIFT)) & VFCCU_0_GFLTRC_C0_RHWSW14_MASK)

#define VFCCU_0_GFLTRC_C0_RHWSW15_MASK           (0x8000U)
#define VFCCU_0_GFLTRC_C0_RHWSW15_SHIFT          (15U)
#define VFCCU_0_GFLTRC_C0_RHWSW15_WIDTH          (1U)
#define VFCCU_0_GFLTRC_C0_RHWSW15(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GFLTRC_C0_RHWSW15_SHIFT)) & VFCCU_0_GFLTRC_C0_RHWSW15_MASK)

#define VFCCU_0_GFLTRC_C0_RHWSW16_MASK           (0x10000U)
#define VFCCU_0_GFLTRC_C0_RHWSW16_SHIFT          (16U)
#define VFCCU_0_GFLTRC_C0_RHWSW16_WIDTH          (1U)
#define VFCCU_0_GFLTRC_C0_RHWSW16(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GFLTRC_C0_RHWSW16_SHIFT)) & VFCCU_0_GFLTRC_C0_RHWSW16_MASK)

#define VFCCU_0_GFLTRC_C0_RHWSW17_MASK           (0x20000U)
#define VFCCU_0_GFLTRC_C0_RHWSW17_SHIFT          (17U)
#define VFCCU_0_GFLTRC_C0_RHWSW17_WIDTH          (1U)
#define VFCCU_0_GFLTRC_C0_RHWSW17(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GFLTRC_C0_RHWSW17_SHIFT)) & VFCCU_0_GFLTRC_C0_RHWSW17_MASK)

#define VFCCU_0_GFLTRC_C0_RHWSW18_MASK           (0x40000U)
#define VFCCU_0_GFLTRC_C0_RHWSW18_SHIFT          (18U)
#define VFCCU_0_GFLTRC_C0_RHWSW18_WIDTH          (1U)
#define VFCCU_0_GFLTRC_C0_RHWSW18(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GFLTRC_C0_RHWSW18_SHIFT)) & VFCCU_0_GFLTRC_C0_RHWSW18_MASK)

#define VFCCU_0_GFLTRC_C0_RHWSW19_MASK           (0x80000U)
#define VFCCU_0_GFLTRC_C0_RHWSW19_SHIFT          (19U)
#define VFCCU_0_GFLTRC_C0_RHWSW19_WIDTH          (1U)
#define VFCCU_0_GFLTRC_C0_RHWSW19(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GFLTRC_C0_RHWSW19_SHIFT)) & VFCCU_0_GFLTRC_C0_RHWSW19_MASK)

#define VFCCU_0_GFLTRC_C0_RHWSW20_MASK           (0x100000U)
#define VFCCU_0_GFLTRC_C0_RHWSW20_SHIFT          (20U)
#define VFCCU_0_GFLTRC_C0_RHWSW20_WIDTH          (1U)
#define VFCCU_0_GFLTRC_C0_RHWSW20(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GFLTRC_C0_RHWSW20_SHIFT)) & VFCCU_0_GFLTRC_C0_RHWSW20_MASK)

#define VFCCU_0_GFLTRC_C0_RHWSW21_MASK           (0x200000U)
#define VFCCU_0_GFLTRC_C0_RHWSW21_SHIFT          (21U)
#define VFCCU_0_GFLTRC_C0_RHWSW21_WIDTH          (1U)
#define VFCCU_0_GFLTRC_C0_RHWSW21(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GFLTRC_C0_RHWSW21_SHIFT)) & VFCCU_0_GFLTRC_C0_RHWSW21_MASK)

#define VFCCU_0_GFLTRC_C0_RHWSW22_MASK           (0x400000U)
#define VFCCU_0_GFLTRC_C0_RHWSW22_SHIFT          (22U)
#define VFCCU_0_GFLTRC_C0_RHWSW22_WIDTH          (1U)
#define VFCCU_0_GFLTRC_C0_RHWSW22(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GFLTRC_C0_RHWSW22_SHIFT)) & VFCCU_0_GFLTRC_C0_RHWSW22_MASK)

#define VFCCU_0_GFLTRC_C0_RHWSW23_MASK           (0x800000U)
#define VFCCU_0_GFLTRC_C0_RHWSW23_SHIFT          (23U)
#define VFCCU_0_GFLTRC_C0_RHWSW23_WIDTH          (1U)
#define VFCCU_0_GFLTRC_C0_RHWSW23(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GFLTRC_C0_RHWSW23_SHIFT)) & VFCCU_0_GFLTRC_C0_RHWSW23_MASK)

#define VFCCU_0_GFLTRC_C0_RHWSW24_MASK           (0x1000000U)
#define VFCCU_0_GFLTRC_C0_RHWSW24_SHIFT          (24U)
#define VFCCU_0_GFLTRC_C0_RHWSW24_WIDTH          (1U)
#define VFCCU_0_GFLTRC_C0_RHWSW24(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GFLTRC_C0_RHWSW24_SHIFT)) & VFCCU_0_GFLTRC_C0_RHWSW24_MASK)

#define VFCCU_0_GFLTRC_C0_RHWSW25_MASK           (0x2000000U)
#define VFCCU_0_GFLTRC_C0_RHWSW25_SHIFT          (25U)
#define VFCCU_0_GFLTRC_C0_RHWSW25_WIDTH          (1U)
#define VFCCU_0_GFLTRC_C0_RHWSW25(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GFLTRC_C0_RHWSW25_SHIFT)) & VFCCU_0_GFLTRC_C0_RHWSW25_MASK)

#define VFCCU_0_GFLTRC_C0_RHWSW26_MASK           (0x4000000U)
#define VFCCU_0_GFLTRC_C0_RHWSW26_SHIFT          (26U)
#define VFCCU_0_GFLTRC_C0_RHWSW26_WIDTH          (1U)
#define VFCCU_0_GFLTRC_C0_RHWSW26(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GFLTRC_C0_RHWSW26_SHIFT)) & VFCCU_0_GFLTRC_C0_RHWSW26_MASK)

#define VFCCU_0_GFLTRC_C0_RHWSW27_MASK           (0x8000000U)
#define VFCCU_0_GFLTRC_C0_RHWSW27_SHIFT          (27U)
#define VFCCU_0_GFLTRC_C0_RHWSW27_WIDTH          (1U)
#define VFCCU_0_GFLTRC_C0_RHWSW27(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GFLTRC_C0_RHWSW27_SHIFT)) & VFCCU_0_GFLTRC_C0_RHWSW27_MASK)

#define VFCCU_0_GFLTRC_C0_RHWSW28_MASK           (0x10000000U)
#define VFCCU_0_GFLTRC_C0_RHWSW28_SHIFT          (28U)
#define VFCCU_0_GFLTRC_C0_RHWSW28_WIDTH          (1U)
#define VFCCU_0_GFLTRC_C0_RHWSW28(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GFLTRC_C0_RHWSW28_SHIFT)) & VFCCU_0_GFLTRC_C0_RHWSW28_MASK)

#define VFCCU_0_GFLTRC_C0_RHWSW29_MASK           (0x20000000U)
#define VFCCU_0_GFLTRC_C0_RHWSW29_SHIFT          (29U)
#define VFCCU_0_GFLTRC_C0_RHWSW29_WIDTH          (1U)
#define VFCCU_0_GFLTRC_C0_RHWSW29(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GFLTRC_C0_RHWSW29_SHIFT)) & VFCCU_0_GFLTRC_C0_RHWSW29_MASK)

#define VFCCU_0_GFLTRC_C0_RHWSW30_MASK           (0x40000000U)
#define VFCCU_0_GFLTRC_C0_RHWSW30_SHIFT          (30U)
#define VFCCU_0_GFLTRC_C0_RHWSW30_WIDTH          (1U)
#define VFCCU_0_GFLTRC_C0_RHWSW30(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GFLTRC_C0_RHWSW30_SHIFT)) & VFCCU_0_GFLTRC_C0_RHWSW30_MASK)

#define VFCCU_0_GFLTRC_C0_RHWSW31_MASK           (0x80000000U)
#define VFCCU_0_GFLTRC_C0_RHWSW31_SHIFT          (31U)
#define VFCCU_0_GFLTRC_C0_RHWSW31_WIDTH          (1U)
#define VFCCU_0_GFLTRC_C0_RHWSW31(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GFLTRC_C0_RHWSW31_SHIFT)) & VFCCU_0_GFLTRC_C0_RHWSW31_MASK)
/*! @} */

/*! @name GFLTRC_C1 - Global Fault Recovery */
/*! @{ */

#define VFCCU_0_GFLTRC_C1_RHWSW32_MASK           (0x1U)
#define VFCCU_0_GFLTRC_C1_RHWSW32_SHIFT          (0U)
#define VFCCU_0_GFLTRC_C1_RHWSW32_WIDTH          (1U)
#define VFCCU_0_GFLTRC_C1_RHWSW32(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GFLTRC_C1_RHWSW32_SHIFT)) & VFCCU_0_GFLTRC_C1_RHWSW32_MASK)

#define VFCCU_0_GFLTRC_C1_RHWSW33_MASK           (0x2U)
#define VFCCU_0_GFLTRC_C1_RHWSW33_SHIFT          (1U)
#define VFCCU_0_GFLTRC_C1_RHWSW33_WIDTH          (1U)
#define VFCCU_0_GFLTRC_C1_RHWSW33(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GFLTRC_C1_RHWSW33_SHIFT)) & VFCCU_0_GFLTRC_C1_RHWSW33_MASK)

#define VFCCU_0_GFLTRC_C1_RHWSW34_MASK           (0x4U)
#define VFCCU_0_GFLTRC_C1_RHWSW34_SHIFT          (2U)
#define VFCCU_0_GFLTRC_C1_RHWSW34_WIDTH          (1U)
#define VFCCU_0_GFLTRC_C1_RHWSW34(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GFLTRC_C1_RHWSW34_SHIFT)) & VFCCU_0_GFLTRC_C1_RHWSW34_MASK)

#define VFCCU_0_GFLTRC_C1_RHWSW35_MASK           (0x8U)
#define VFCCU_0_GFLTRC_C1_RHWSW35_SHIFT          (3U)
#define VFCCU_0_GFLTRC_C1_RHWSW35_WIDTH          (1U)
#define VFCCU_0_GFLTRC_C1_RHWSW35(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GFLTRC_C1_RHWSW35_SHIFT)) & VFCCU_0_GFLTRC_C1_RHWSW35_MASK)

#define VFCCU_0_GFLTRC_C1_RHWSW36_MASK           (0x10U)
#define VFCCU_0_GFLTRC_C1_RHWSW36_SHIFT          (4U)
#define VFCCU_0_GFLTRC_C1_RHWSW36_WIDTH          (1U)
#define VFCCU_0_GFLTRC_C1_RHWSW36(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GFLTRC_C1_RHWSW36_SHIFT)) & VFCCU_0_GFLTRC_C1_RHWSW36_MASK)

#define VFCCU_0_GFLTRC_C1_RHWSW37_MASK           (0x20U)
#define VFCCU_0_GFLTRC_C1_RHWSW37_SHIFT          (5U)
#define VFCCU_0_GFLTRC_C1_RHWSW37_WIDTH          (1U)
#define VFCCU_0_GFLTRC_C1_RHWSW37(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GFLTRC_C1_RHWSW37_SHIFT)) & VFCCU_0_GFLTRC_C1_RHWSW37_MASK)

#define VFCCU_0_GFLTRC_C1_RHWSW38_MASK           (0x40U)
#define VFCCU_0_GFLTRC_C1_RHWSW38_SHIFT          (6U)
#define VFCCU_0_GFLTRC_C1_RHWSW38_WIDTH          (1U)
#define VFCCU_0_GFLTRC_C1_RHWSW38(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GFLTRC_C1_RHWSW38_SHIFT)) & VFCCU_0_GFLTRC_C1_RHWSW38_MASK)

#define VFCCU_0_GFLTRC_C1_RHWSW39_MASK           (0x80U)
#define VFCCU_0_GFLTRC_C1_RHWSW39_SHIFT          (7U)
#define VFCCU_0_GFLTRC_C1_RHWSW39_WIDTH          (1U)
#define VFCCU_0_GFLTRC_C1_RHWSW39(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GFLTRC_C1_RHWSW39_SHIFT)) & VFCCU_0_GFLTRC_C1_RHWSW39_MASK)

#define VFCCU_0_GFLTRC_C1_RHWSW40_MASK           (0x100U)
#define VFCCU_0_GFLTRC_C1_RHWSW40_SHIFT          (8U)
#define VFCCU_0_GFLTRC_C1_RHWSW40_WIDTH          (1U)
#define VFCCU_0_GFLTRC_C1_RHWSW40(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GFLTRC_C1_RHWSW40_SHIFT)) & VFCCU_0_GFLTRC_C1_RHWSW40_MASK)

#define VFCCU_0_GFLTRC_C1_RHWSW41_MASK           (0x200U)
#define VFCCU_0_GFLTRC_C1_RHWSW41_SHIFT          (9U)
#define VFCCU_0_GFLTRC_C1_RHWSW41_WIDTH          (1U)
#define VFCCU_0_GFLTRC_C1_RHWSW41(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GFLTRC_C1_RHWSW41_SHIFT)) & VFCCU_0_GFLTRC_C1_RHWSW41_MASK)

#define VFCCU_0_GFLTRC_C1_RHWSW42_MASK           (0x400U)
#define VFCCU_0_GFLTRC_C1_RHWSW42_SHIFT          (10U)
#define VFCCU_0_GFLTRC_C1_RHWSW42_WIDTH          (1U)
#define VFCCU_0_GFLTRC_C1_RHWSW42(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GFLTRC_C1_RHWSW42_SHIFT)) & VFCCU_0_GFLTRC_C1_RHWSW42_MASK)

#define VFCCU_0_GFLTRC_C1_RHWSW43_MASK           (0x800U)
#define VFCCU_0_GFLTRC_C1_RHWSW43_SHIFT          (11U)
#define VFCCU_0_GFLTRC_C1_RHWSW43_WIDTH          (1U)
#define VFCCU_0_GFLTRC_C1_RHWSW43(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GFLTRC_C1_RHWSW43_SHIFT)) & VFCCU_0_GFLTRC_C1_RHWSW43_MASK)

#define VFCCU_0_GFLTRC_C1_RHWSW44_MASK           (0x1000U)
#define VFCCU_0_GFLTRC_C1_RHWSW44_SHIFT          (12U)
#define VFCCU_0_GFLTRC_C1_RHWSW44_WIDTH          (1U)
#define VFCCU_0_GFLTRC_C1_RHWSW44(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GFLTRC_C1_RHWSW44_SHIFT)) & VFCCU_0_GFLTRC_C1_RHWSW44_MASK)

#define VFCCU_0_GFLTRC_C1_RHWSW45_MASK           (0x2000U)
#define VFCCU_0_GFLTRC_C1_RHWSW45_SHIFT          (13U)
#define VFCCU_0_GFLTRC_C1_RHWSW45_WIDTH          (1U)
#define VFCCU_0_GFLTRC_C1_RHWSW45(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GFLTRC_C1_RHWSW45_SHIFT)) & VFCCU_0_GFLTRC_C1_RHWSW45_MASK)

#define VFCCU_0_GFLTRC_C1_RHWSW46_MASK           (0x4000U)
#define VFCCU_0_GFLTRC_C1_RHWSW46_SHIFT          (14U)
#define VFCCU_0_GFLTRC_C1_RHWSW46_WIDTH          (1U)
#define VFCCU_0_GFLTRC_C1_RHWSW46(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GFLTRC_C1_RHWSW46_SHIFT)) & VFCCU_0_GFLTRC_C1_RHWSW46_MASK)

#define VFCCU_0_GFLTRC_C1_RHWSW47_MASK           (0x8000U)
#define VFCCU_0_GFLTRC_C1_RHWSW47_SHIFT          (15U)
#define VFCCU_0_GFLTRC_C1_RHWSW47_WIDTH          (1U)
#define VFCCU_0_GFLTRC_C1_RHWSW47(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GFLTRC_C1_RHWSW47_SHIFT)) & VFCCU_0_GFLTRC_C1_RHWSW47_MASK)

#define VFCCU_0_GFLTRC_C1_RHWSW48_MASK           (0x10000U)
#define VFCCU_0_GFLTRC_C1_RHWSW48_SHIFT          (16U)
#define VFCCU_0_GFLTRC_C1_RHWSW48_WIDTH          (1U)
#define VFCCU_0_GFLTRC_C1_RHWSW48(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GFLTRC_C1_RHWSW48_SHIFT)) & VFCCU_0_GFLTRC_C1_RHWSW48_MASK)

#define VFCCU_0_GFLTRC_C1_RHWSW49_MASK           (0x20000U)
#define VFCCU_0_GFLTRC_C1_RHWSW49_SHIFT          (17U)
#define VFCCU_0_GFLTRC_C1_RHWSW49_WIDTH          (1U)
#define VFCCU_0_GFLTRC_C1_RHWSW49(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GFLTRC_C1_RHWSW49_SHIFT)) & VFCCU_0_GFLTRC_C1_RHWSW49_MASK)

#define VFCCU_0_GFLTRC_C1_RHWSW50_MASK           (0x40000U)
#define VFCCU_0_GFLTRC_C1_RHWSW50_SHIFT          (18U)
#define VFCCU_0_GFLTRC_C1_RHWSW50_WIDTH          (1U)
#define VFCCU_0_GFLTRC_C1_RHWSW50(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GFLTRC_C1_RHWSW50_SHIFT)) & VFCCU_0_GFLTRC_C1_RHWSW50_MASK)

#define VFCCU_0_GFLTRC_C1_RHWSW51_MASK           (0x80000U)
#define VFCCU_0_GFLTRC_C1_RHWSW51_SHIFT          (19U)
#define VFCCU_0_GFLTRC_C1_RHWSW51_WIDTH          (1U)
#define VFCCU_0_GFLTRC_C1_RHWSW51(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GFLTRC_C1_RHWSW51_SHIFT)) & VFCCU_0_GFLTRC_C1_RHWSW51_MASK)

#define VFCCU_0_GFLTRC_C1_RHWSW52_MASK           (0x100000U)
#define VFCCU_0_GFLTRC_C1_RHWSW52_SHIFT          (20U)
#define VFCCU_0_GFLTRC_C1_RHWSW52_WIDTH          (1U)
#define VFCCU_0_GFLTRC_C1_RHWSW52(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GFLTRC_C1_RHWSW52_SHIFT)) & VFCCU_0_GFLTRC_C1_RHWSW52_MASK)

#define VFCCU_0_GFLTRC_C1_RHWSW53_MASK           (0x200000U)
#define VFCCU_0_GFLTRC_C1_RHWSW53_SHIFT          (21U)
#define VFCCU_0_GFLTRC_C1_RHWSW53_WIDTH          (1U)
#define VFCCU_0_GFLTRC_C1_RHWSW53(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GFLTRC_C1_RHWSW53_SHIFT)) & VFCCU_0_GFLTRC_C1_RHWSW53_MASK)

#define VFCCU_0_GFLTRC_C1_RHWSW54_MASK           (0x400000U)
#define VFCCU_0_GFLTRC_C1_RHWSW54_SHIFT          (22U)
#define VFCCU_0_GFLTRC_C1_RHWSW54_WIDTH          (1U)
#define VFCCU_0_GFLTRC_C1_RHWSW54(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GFLTRC_C1_RHWSW54_SHIFT)) & VFCCU_0_GFLTRC_C1_RHWSW54_MASK)

#define VFCCU_0_GFLTRC_C1_RHWSW55_MASK           (0x800000U)
#define VFCCU_0_GFLTRC_C1_RHWSW55_SHIFT          (23U)
#define VFCCU_0_GFLTRC_C1_RHWSW55_WIDTH          (1U)
#define VFCCU_0_GFLTRC_C1_RHWSW55(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GFLTRC_C1_RHWSW55_SHIFT)) & VFCCU_0_GFLTRC_C1_RHWSW55_MASK)

#define VFCCU_0_GFLTRC_C1_RHWSW56_MASK           (0x1000000U)
#define VFCCU_0_GFLTRC_C1_RHWSW56_SHIFT          (24U)
#define VFCCU_0_GFLTRC_C1_RHWSW56_WIDTH          (1U)
#define VFCCU_0_GFLTRC_C1_RHWSW56(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GFLTRC_C1_RHWSW56_SHIFT)) & VFCCU_0_GFLTRC_C1_RHWSW56_MASK)

#define VFCCU_0_GFLTRC_C1_RHWSW57_MASK           (0x2000000U)
#define VFCCU_0_GFLTRC_C1_RHWSW57_SHIFT          (25U)
#define VFCCU_0_GFLTRC_C1_RHWSW57_WIDTH          (1U)
#define VFCCU_0_GFLTRC_C1_RHWSW57(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GFLTRC_C1_RHWSW57_SHIFT)) & VFCCU_0_GFLTRC_C1_RHWSW57_MASK)

#define VFCCU_0_GFLTRC_C1_RHWSW58_MASK           (0x4000000U)
#define VFCCU_0_GFLTRC_C1_RHWSW58_SHIFT          (26U)
#define VFCCU_0_GFLTRC_C1_RHWSW58_WIDTH          (1U)
#define VFCCU_0_GFLTRC_C1_RHWSW58(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GFLTRC_C1_RHWSW58_SHIFT)) & VFCCU_0_GFLTRC_C1_RHWSW58_MASK)

#define VFCCU_0_GFLTRC_C1_RHWSW59_MASK           (0x8000000U)
#define VFCCU_0_GFLTRC_C1_RHWSW59_SHIFT          (27U)
#define VFCCU_0_GFLTRC_C1_RHWSW59_WIDTH          (1U)
#define VFCCU_0_GFLTRC_C1_RHWSW59(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GFLTRC_C1_RHWSW59_SHIFT)) & VFCCU_0_GFLTRC_C1_RHWSW59_MASK)

#define VFCCU_0_GFLTRC_C1_RHWSW60_MASK           (0x10000000U)
#define VFCCU_0_GFLTRC_C1_RHWSW60_SHIFT          (28U)
#define VFCCU_0_GFLTRC_C1_RHWSW60_WIDTH          (1U)
#define VFCCU_0_GFLTRC_C1_RHWSW60(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GFLTRC_C1_RHWSW60_SHIFT)) & VFCCU_0_GFLTRC_C1_RHWSW60_MASK)

#define VFCCU_0_GFLTRC_C1_RHWSW61_MASK           (0x20000000U)
#define VFCCU_0_GFLTRC_C1_RHWSW61_SHIFT          (29U)
#define VFCCU_0_GFLTRC_C1_RHWSW61_WIDTH          (1U)
#define VFCCU_0_GFLTRC_C1_RHWSW61(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GFLTRC_C1_RHWSW61_SHIFT)) & VFCCU_0_GFLTRC_C1_RHWSW61_MASK)

#define VFCCU_0_GFLTRC_C1_RHWSW62_MASK           (0x40000000U)
#define VFCCU_0_GFLTRC_C1_RHWSW62_SHIFT          (30U)
#define VFCCU_0_GFLTRC_C1_RHWSW62_WIDTH          (1U)
#define VFCCU_0_GFLTRC_C1_RHWSW62(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GFLTRC_C1_RHWSW62_SHIFT)) & VFCCU_0_GFLTRC_C1_RHWSW62_MASK)

#define VFCCU_0_GFLTRC_C1_RHWSW63_MASK           (0x80000000U)
#define VFCCU_0_GFLTRC_C1_RHWSW63_SHIFT          (31U)
#define VFCCU_0_GFLTRC_C1_RHWSW63_WIDTH          (1U)
#define VFCCU_0_GFLTRC_C1_RHWSW63(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GFLTRC_C1_RHWSW63_SHIFT)) & VFCCU_0_GFLTRC_C1_RHWSW63_MASK)
/*! @} */

/*! @name GRKNTIMS - Global Reaction Timer Status */
/*! @{ */

#define VFCCU_0_GRKNTIMS_RKTIMVAL_MASK           (0xFFFFFFFFU)
#define VFCCU_0_GRKNTIMS_RKTIMVAL_SHIFT          (0U)
#define VFCCU_0_GRKNTIMS_RKTIMVAL_WIDTH          (32U)
#define VFCCU_0_GRKNTIMS_RKTIMVAL(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GRKNTIMS_RKTIMVAL_SHIFT)) & VFCCU_0_GRKNTIMS_RKTIMVAL_MASK)
/*! @} */

/*! @name GINTOVFS - Global DID FSM Status */
/*! @{ */

#define VFCCU_0_GINTOVFS_FSMSTATE_MASK           (0x3U)
#define VFCCU_0_GINTOVFS_FSMSTATE_SHIFT          (0U)
#define VFCCU_0_GINTOVFS_FSMSTATE_WIDTH          (2U)
#define VFCCU_0_GINTOVFS_FSMSTATE(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GINTOVFS_FSMSTATE_SHIFT)) & VFCCU_0_GINTOVFS_FSMSTATE_MASK)

#define VFCCU_0_GINTOVFS_FLTSERV_MASK            (0x80U)
#define VFCCU_0_GINTOVFS_FLTSERV_SHIFT           (7U)
#define VFCCU_0_GINTOVFS_FLTSERV_WIDTH           (1U)
#define VFCCU_0_GINTOVFS_FLTSERV(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GINTOVFS_FLTSERV_SHIFT)) & VFCCU_0_GINTOVFS_FLTSERV_MASK)

#define VFCCU_0_GINTOVFS_SERV_DID_MASK           (0xF0000U)
#define VFCCU_0_GINTOVFS_SERV_DID_SHIFT          (16U)
#define VFCCU_0_GINTOVFS_SERV_DID_WIDTH          (4U)
#define VFCCU_0_GINTOVFS_SERV_DID(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GINTOVFS_SERV_DID_SHIFT)) & VFCCU_0_GINTOVFS_SERV_DID_MASK)
/*! @} */

/*! @name GMEOUTDC - Global Minimum EOUT Duration */
/*! @{ */

#define VFCCU_0_GMEOUTDC_EOUTMIND_MASK           (0xFFFFFFFFU)
#define VFCCU_0_GMEOUTDC_EOUTMIND_SHIFT          (0U)
#define VFCCU_0_GMEOUTDC_EOUTMIND_WIDTH          (32U)
#define VFCCU_0_GMEOUTDC_EOUTMIND(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GMEOUTDC_EOUTMIND_SHIFT)) & VFCCU_0_GMEOUTDC_EOUTMIND_MASK)
/*! @} */

/*! @name GEOUTTCT - Global EOUT Timer Disable */
/*! @{ */

#define VFCCU_0_GEOUTTCT_TMRDIS0_MASK            (0x1U)
#define VFCCU_0_GEOUTTCT_TMRDIS0_SHIFT           (0U)
#define VFCCU_0_GEOUTTCT_TMRDIS0_WIDTH           (1U)
#define VFCCU_0_GEOUTTCT_TMRDIS0(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GEOUTTCT_TMRDIS0_SHIFT)) & VFCCU_0_GEOUTTCT_TMRDIS0_MASK)

#define VFCCU_0_GEOUTTCT_TMRDIS1_MASK            (0x2U)
#define VFCCU_0_GEOUTTCT_TMRDIS1_SHIFT           (1U)
#define VFCCU_0_GEOUTTCT_TMRDIS1_WIDTH           (1U)
#define VFCCU_0_GEOUTTCT_TMRDIS1(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GEOUTTCT_TMRDIS1_SHIFT)) & VFCCU_0_GEOUTTCT_TMRDIS1_MASK)
/*! @} */

/*! @name GEOUTPNC - Global EOUT Pin */
/*! @{ */

#define VFCCU_0_GEOUTPNC_OBE_VALID_MASK          (0x1U)
#define VFCCU_0_GEOUTPNC_OBE_VALID_SHIFT         (0U)
#define VFCCU_0_GEOUTPNC_OBE_VALID_WIDTH         (1U)
#define VFCCU_0_GEOUTPNC_OBE_VALID(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GEOUTPNC_OBE_VALID_SHIFT)) & VFCCU_0_GEOUTPNC_OBE_VALID_MASK)

#define VFCCU_0_GEOUTPNC_OBE_STAT_MASK           (0x2U)
#define VFCCU_0_GEOUTPNC_OBE_STAT_SHIFT          (1U)
#define VFCCU_0_GEOUTPNC_OBE_STAT_WIDTH          (1U)
#define VFCCU_0_GEOUTPNC_OBE_STAT(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GEOUTPNC_OBE_STAT_SHIFT)) & VFCCU_0_GEOUTPNC_OBE_STAT_MASK)

#define VFCCU_0_GEOUTPNC_DO_STAT_MASK            (0x8U)
#define VFCCU_0_GEOUTPNC_DO_STAT_SHIFT           (3U)
#define VFCCU_0_GEOUTPNC_DO_STAT_WIDTH           (1U)
#define VFCCU_0_GEOUTPNC_DO_STAT(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GEOUTPNC_DO_STAT_SHIFT)) & VFCCU_0_GEOUTPNC_DO_STAT_MASK)

#define VFCCU_0_GEOUTPNC_VAL_CTRL_MASK           (0x30U)
#define VFCCU_0_GEOUTPNC_VAL_CTRL_SHIFT          (4U)
#define VFCCU_0_GEOUTPNC_VAL_CTRL_WIDTH          (2U)
#define VFCCU_0_GEOUTPNC_VAL_CTRL(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GEOUTPNC_VAL_CTRL_SHIFT)) & VFCCU_0_GEOUTPNC_VAL_CTRL_MASK)

#define VFCCU_0_GEOUTPNC_IBE_MASK                (0x100U)
#define VFCCU_0_GEOUTPNC_IBE_SHIFT               (8U)
#define VFCCU_0_GEOUTPNC_IBE_WIDTH               (1U)
#define VFCCU_0_GEOUTPNC_IBE(x)                  (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GEOUTPNC_IBE_SHIFT)) & VFCCU_0_GEOUTPNC_IBE_MASK)

#define VFCCU_0_GEOUTPNC_IND_STAT_MASK           (0x200U)
#define VFCCU_0_GEOUTPNC_IND_STAT_SHIFT          (9U)
#define VFCCU_0_GEOUTPNC_IND_STAT_WIDTH          (1U)
#define VFCCU_0_GEOUTPNC_IND_STAT(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GEOUTPNC_IND_STAT_SHIFT)) & VFCCU_0_GEOUTPNC_IND_STAT_MASK)

#define VFCCU_0_GEOUTPNC_INV_IP_MASK             (0x400U)
#define VFCCU_0_GEOUTPNC_INV_IP_SHIFT            (10U)
#define VFCCU_0_GEOUTPNC_INV_IP_WIDTH            (1U)
#define VFCCU_0_GEOUTPNC_INV_IP(x)               (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GEOUTPNC_INV_IP_SHIFT)) & VFCCU_0_GEOUTPNC_INV_IP_MASK)
/*! @} */

/*! @name GEOUTPMC - Global EOUT Pin Map */
/*! @{ */

#define VFCCU_0_GEOUTPMC_SPLENB0_MASK            (0x1U)
#define VFCCU_0_GEOUTPMC_SPLENB0_SHIFT           (0U)
#define VFCCU_0_GEOUTPMC_SPLENB0_WIDTH           (1U)
#define VFCCU_0_GEOUTPMC_SPLENB0(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GEOUTPMC_SPLENB0_SHIFT)) & VFCCU_0_GEOUTPMC_SPLENB0_MASK)
/*! @} */

/*! @name GEOUTMC - Global EOUT Mode */
/*! @{ */

#define VFCCU_0_GEOUTMC_EOUTM_MASK               (0x7U)
#define VFCCU_0_GEOUTMC_EOUTM_SHIFT              (0U)
#define VFCCU_0_GEOUTMC_EOUTM_WIDTH              (3U)
#define VFCCU_0_GEOUTMC_EOUTM(x)                 (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GEOUTMC_EOUTM_SHIFT)) & VFCCU_0_GEOUTMC_EOUTM_MASK)

#define VFCCU_0_GEOUTMC_INV_MASK                 (0x8U)
#define VFCCU_0_GEOUTMC_INV_SHIFT                (3U)
#define VFCCU_0_GEOUTMC_INV_WIDTH                (1U)
#define VFCCU_0_GEOUTMC_INV(x)                   (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GEOUTMC_INV_SHIFT)) & VFCCU_0_GEOUTMC_INV_MASK)

#define VFCCU_0_GEOUTMC_TSM_CNT_MASK             (0xFFFFF00U)
#define VFCCU_0_GEOUTMC_TSM_CNT_SHIFT            (8U)
#define VFCCU_0_GEOUTMC_TSM_CNT_WIDTH            (20U)
#define VFCCU_0_GEOUTMC_TSM_CNT(x)               (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GEOUTMC_TSM_CNT_SHIFT)) & VFCCU_0_GEOUTMC_TSM_CNT_MASK)
/*! @} */

/*! @name GEOUTTMS - Global EOUT Timer Status */
/*! @{ */

#define VFCCU_0_GEOUTTMS_EOUTDVAL_MASK           (0xFFFFFFFFU)
#define VFCCU_0_GEOUTTMS_EOUTDVAL_SHIFT          (0U)
#define VFCCU_0_GEOUTTMS_EOUTDVAL_WIDTH          (32U)
#define VFCCU_0_GEOUTTMS_EOUTDVAL(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GEOUTTMS_EOUTDVAL_SHIFT)) & VFCCU_0_GEOUTTMS_EOUTDVAL_MASK)
/*! @} */

/*! @name GEOUTDIC - Global EOUT DID */
/*! @{ */

#define VFCCU_0_GEOUTDIC_DID_EOUT_MASK           (0xFU)
#define VFCCU_0_GEOUTDIC_DID_EOUT_SHIFT          (0U)
#define VFCCU_0_GEOUTDIC_DID_EOUT_WIDTH          (4U)
#define VFCCU_0_GEOUTDIC_DID_EOUT(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GEOUTDIC_DID_EOUT_SHIFT)) & VFCCU_0_GEOUTDIC_DID_EOUT_MASK)
/*! @} */

/*! @name GDBGCFG - Global Debug */
/*! @{ */

#define VFCCU_0_GDBGCFG_FRZ_MASK                 (0x10000U)
#define VFCCU_0_GDBGCFG_FRZ_SHIFT                (16U)
#define VFCCU_0_GDBGCFG_FRZ_WIDTH                (1U)
#define VFCCU_0_GDBGCFG_FRZ(x)                   (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GDBGCFG_FRZ_SHIFT)) & VFCCU_0_GDBGCFG_FRZ_MASK)
/*! @} */

/*! @name GDBGSTAT - Global Debug Status */
/*! @{ */

#define VFCCU_0_GDBGSTAT_FLTIND_MASK             (0xFFU)
#define VFCCU_0_GDBGSTAT_FLTIND_SHIFT            (0U)
#define VFCCU_0_GDBGSTAT_FLTIND_WIDTH            (8U)
#define VFCCU_0_GDBGSTAT_FLTIND(x)               (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GDBGSTAT_FLTIND_SHIFT)) & VFCCU_0_GDBGSTAT_FLTIND_MASK)
/*! @} */

/*! @name GDPFSTAT - Global Debug Pending Fault Status */
/*! @{ */

#define VFCCU_0_GDPFSTAT_PENDFLT0_MASK           (0x1U)
#define VFCCU_0_GDPFSTAT_PENDFLT0_SHIFT          (0U)
#define VFCCU_0_GDPFSTAT_PENDFLT0_WIDTH          (1U)
#define VFCCU_0_GDPFSTAT_PENDFLT0(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GDPFSTAT_PENDFLT0_SHIFT)) & VFCCU_0_GDPFSTAT_PENDFLT0_MASK)

#define VFCCU_0_GDPFSTAT_PENDFLT1_MASK           (0x2U)
#define VFCCU_0_GDPFSTAT_PENDFLT1_SHIFT          (1U)
#define VFCCU_0_GDPFSTAT_PENDFLT1_WIDTH          (1U)
#define VFCCU_0_GDPFSTAT_PENDFLT1(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GDPFSTAT_PENDFLT1_SHIFT)) & VFCCU_0_GDPFSTAT_PENDFLT1_MASK)
/*! @} */

/*! @name GDALTRLD - Global Debug Alternate Reload Status */
/*! @{ */

#define VFCCU_0_GDALTRLD_ALTRLD0_MASK            (0x1U)
#define VFCCU_0_GDALTRLD_ALTRLD0_SHIFT           (0U)
#define VFCCU_0_GDALTRLD_ALTRLD0_WIDTH           (1U)
#define VFCCU_0_GDALTRLD_ALTRLD0(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GDALTRLD_ALTRLD0_SHIFT)) & VFCCU_0_GDALTRLD_ALTRLD0_MASK)

#define VFCCU_0_GDALTRLD_ALTRLD1_MASK            (0x2U)
#define VFCCU_0_GDALTRLD_ALTRLD1_SHIFT           (1U)
#define VFCCU_0_GDALTRLD_ALTRLD1_WIDTH           (1U)
#define VFCCU_0_GDALTRLD_ALTRLD1(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_GDALTRLD_ALTRLD1_SHIFT)) & VFCCU_0_GDALTRLD_ALTRLD1_MASK)
/*! @} */

/*! @name FHCFG0 - Fault Handler */
/*! @{ */

#define VFCCU_0_FHCFG0_FHIDEN_MASK               (0x1U)
#define VFCCU_0_FHCFG0_FHIDEN_SHIFT              (0U)
#define VFCCU_0_FHCFG0_FHIDEN_WIDTH              (1U)
#define VFCCU_0_FHCFG0_FHIDEN(x)                 (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHCFG0_FHIDEN_SHIFT)) & VFCCU_0_FHCFG0_FHIDEN_MASK)
/*! @} */

/*! @name FHSRVDS0 - Fault Handler Status */
/*! @{ */

#define VFCCU_0_FHSRVDS0_SERV_DID_MASK           (0xFU)
#define VFCCU_0_FHSRVDS0_SERV_DID_SHIFT          (0U)
#define VFCCU_0_FHSRVDS0_SERV_DID_WIDTH          (4U)
#define VFCCU_0_FHSRVDS0_SERV_DID(x)             (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHSRVDS0_SERV_DID_SHIFT)) & VFCCU_0_FHSRVDS0_SERV_DID_MASK)

#define VFCCU_0_FHSRVDS0_AGGFLTS_MASK            (0x100U)
#define VFCCU_0_FHSRVDS0_AGGFLTS_SHIFT           (8U)
#define VFCCU_0_FHSRVDS0_AGGFLTS_WIDTH           (1U)
#define VFCCU_0_FHSRVDS0_AGGFLTS(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHSRVDS0_AGGFLTS_SHIFT)) & VFCCU_0_FHSRVDS0_AGGFLTS_MASK)
/*! @} */

/*! @name FHFLTENC0_0 - Fault Enable */
/*! @{ */

#define VFCCU_0_FHFLTENC0_0_EN0_MASK             (0x1U)
#define VFCCU_0_FHFLTENC0_0_EN0_SHIFT            (0U)
#define VFCCU_0_FHFLTENC0_0_EN0_WIDTH            (1U)
#define VFCCU_0_FHFLTENC0_0_EN0(x)               (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTENC0_0_EN0_SHIFT)) & VFCCU_0_FHFLTENC0_0_EN0_MASK)

#define VFCCU_0_FHFLTENC0_0_EN1_MASK             (0x2U)
#define VFCCU_0_FHFLTENC0_0_EN1_SHIFT            (1U)
#define VFCCU_0_FHFLTENC0_0_EN1_WIDTH            (1U)
#define VFCCU_0_FHFLTENC0_0_EN1(x)               (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTENC0_0_EN1_SHIFT)) & VFCCU_0_FHFLTENC0_0_EN1_MASK)

#define VFCCU_0_FHFLTENC0_0_EN2_MASK             (0x4U)
#define VFCCU_0_FHFLTENC0_0_EN2_SHIFT            (2U)
#define VFCCU_0_FHFLTENC0_0_EN2_WIDTH            (1U)
#define VFCCU_0_FHFLTENC0_0_EN2(x)               (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTENC0_0_EN2_SHIFT)) & VFCCU_0_FHFLTENC0_0_EN2_MASK)

#define VFCCU_0_FHFLTENC0_0_EN3_MASK             (0x8U)
#define VFCCU_0_FHFLTENC0_0_EN3_SHIFT            (3U)
#define VFCCU_0_FHFLTENC0_0_EN3_WIDTH            (1U)
#define VFCCU_0_FHFLTENC0_0_EN3(x)               (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTENC0_0_EN3_SHIFT)) & VFCCU_0_FHFLTENC0_0_EN3_MASK)

#define VFCCU_0_FHFLTENC0_0_EN4_MASK             (0x10U)
#define VFCCU_0_FHFLTENC0_0_EN4_SHIFT            (4U)
#define VFCCU_0_FHFLTENC0_0_EN4_WIDTH            (1U)
#define VFCCU_0_FHFLTENC0_0_EN4(x)               (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTENC0_0_EN4_SHIFT)) & VFCCU_0_FHFLTENC0_0_EN4_MASK)

#define VFCCU_0_FHFLTENC0_0_EN5_MASK             (0x20U)
#define VFCCU_0_FHFLTENC0_0_EN5_SHIFT            (5U)
#define VFCCU_0_FHFLTENC0_0_EN5_WIDTH            (1U)
#define VFCCU_0_FHFLTENC0_0_EN5(x)               (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTENC0_0_EN5_SHIFT)) & VFCCU_0_FHFLTENC0_0_EN5_MASK)

#define VFCCU_0_FHFLTENC0_0_EN6_MASK             (0x40U)
#define VFCCU_0_FHFLTENC0_0_EN6_SHIFT            (6U)
#define VFCCU_0_FHFLTENC0_0_EN6_WIDTH            (1U)
#define VFCCU_0_FHFLTENC0_0_EN6(x)               (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTENC0_0_EN6_SHIFT)) & VFCCU_0_FHFLTENC0_0_EN6_MASK)

#define VFCCU_0_FHFLTENC0_0_EN7_MASK             (0x80U)
#define VFCCU_0_FHFLTENC0_0_EN7_SHIFT            (7U)
#define VFCCU_0_FHFLTENC0_0_EN7_WIDTH            (1U)
#define VFCCU_0_FHFLTENC0_0_EN7(x)               (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTENC0_0_EN7_SHIFT)) & VFCCU_0_FHFLTENC0_0_EN7_MASK)

#define VFCCU_0_FHFLTENC0_0_EN8_MASK             (0x100U)
#define VFCCU_0_FHFLTENC0_0_EN8_SHIFT            (8U)
#define VFCCU_0_FHFLTENC0_0_EN8_WIDTH            (1U)
#define VFCCU_0_FHFLTENC0_0_EN8(x)               (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTENC0_0_EN8_SHIFT)) & VFCCU_0_FHFLTENC0_0_EN8_MASK)

#define VFCCU_0_FHFLTENC0_0_EN9_MASK             (0x200U)
#define VFCCU_0_FHFLTENC0_0_EN9_SHIFT            (9U)
#define VFCCU_0_FHFLTENC0_0_EN9_WIDTH            (1U)
#define VFCCU_0_FHFLTENC0_0_EN9(x)               (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTENC0_0_EN9_SHIFT)) & VFCCU_0_FHFLTENC0_0_EN9_MASK)

#define VFCCU_0_FHFLTENC0_0_EN10_MASK            (0x400U)
#define VFCCU_0_FHFLTENC0_0_EN10_SHIFT           (10U)
#define VFCCU_0_FHFLTENC0_0_EN10_WIDTH           (1U)
#define VFCCU_0_FHFLTENC0_0_EN10(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTENC0_0_EN10_SHIFT)) & VFCCU_0_FHFLTENC0_0_EN10_MASK)

#define VFCCU_0_FHFLTENC0_0_EN11_MASK            (0x800U)
#define VFCCU_0_FHFLTENC0_0_EN11_SHIFT           (11U)
#define VFCCU_0_FHFLTENC0_0_EN11_WIDTH           (1U)
#define VFCCU_0_FHFLTENC0_0_EN11(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTENC0_0_EN11_SHIFT)) & VFCCU_0_FHFLTENC0_0_EN11_MASK)

#define VFCCU_0_FHFLTENC0_0_EN12_MASK            (0x1000U)
#define VFCCU_0_FHFLTENC0_0_EN12_SHIFT           (12U)
#define VFCCU_0_FHFLTENC0_0_EN12_WIDTH           (1U)
#define VFCCU_0_FHFLTENC0_0_EN12(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTENC0_0_EN12_SHIFT)) & VFCCU_0_FHFLTENC0_0_EN12_MASK)

#define VFCCU_0_FHFLTENC0_0_EN13_MASK            (0x2000U)
#define VFCCU_0_FHFLTENC0_0_EN13_SHIFT           (13U)
#define VFCCU_0_FHFLTENC0_0_EN13_WIDTH           (1U)
#define VFCCU_0_FHFLTENC0_0_EN13(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTENC0_0_EN13_SHIFT)) & VFCCU_0_FHFLTENC0_0_EN13_MASK)

#define VFCCU_0_FHFLTENC0_0_EN14_MASK            (0x4000U)
#define VFCCU_0_FHFLTENC0_0_EN14_SHIFT           (14U)
#define VFCCU_0_FHFLTENC0_0_EN14_WIDTH           (1U)
#define VFCCU_0_FHFLTENC0_0_EN14(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTENC0_0_EN14_SHIFT)) & VFCCU_0_FHFLTENC0_0_EN14_MASK)

#define VFCCU_0_FHFLTENC0_0_EN15_MASK            (0x8000U)
#define VFCCU_0_FHFLTENC0_0_EN15_SHIFT           (15U)
#define VFCCU_0_FHFLTENC0_0_EN15_WIDTH           (1U)
#define VFCCU_0_FHFLTENC0_0_EN15(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTENC0_0_EN15_SHIFT)) & VFCCU_0_FHFLTENC0_0_EN15_MASK)

#define VFCCU_0_FHFLTENC0_0_EN16_MASK            (0x10000U)
#define VFCCU_0_FHFLTENC0_0_EN16_SHIFT           (16U)
#define VFCCU_0_FHFLTENC0_0_EN16_WIDTH           (1U)
#define VFCCU_0_FHFLTENC0_0_EN16(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTENC0_0_EN16_SHIFT)) & VFCCU_0_FHFLTENC0_0_EN16_MASK)

#define VFCCU_0_FHFLTENC0_0_EN17_MASK            (0x20000U)
#define VFCCU_0_FHFLTENC0_0_EN17_SHIFT           (17U)
#define VFCCU_0_FHFLTENC0_0_EN17_WIDTH           (1U)
#define VFCCU_0_FHFLTENC0_0_EN17(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTENC0_0_EN17_SHIFT)) & VFCCU_0_FHFLTENC0_0_EN17_MASK)

#define VFCCU_0_FHFLTENC0_0_EN18_MASK            (0x40000U)
#define VFCCU_0_FHFLTENC0_0_EN18_SHIFT           (18U)
#define VFCCU_0_FHFLTENC0_0_EN18_WIDTH           (1U)
#define VFCCU_0_FHFLTENC0_0_EN18(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTENC0_0_EN18_SHIFT)) & VFCCU_0_FHFLTENC0_0_EN18_MASK)

#define VFCCU_0_FHFLTENC0_0_EN19_MASK            (0x80000U)
#define VFCCU_0_FHFLTENC0_0_EN19_SHIFT           (19U)
#define VFCCU_0_FHFLTENC0_0_EN19_WIDTH           (1U)
#define VFCCU_0_FHFLTENC0_0_EN19(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTENC0_0_EN19_SHIFT)) & VFCCU_0_FHFLTENC0_0_EN19_MASK)

#define VFCCU_0_FHFLTENC0_0_EN20_MASK            (0x100000U)
#define VFCCU_0_FHFLTENC0_0_EN20_SHIFT           (20U)
#define VFCCU_0_FHFLTENC0_0_EN20_WIDTH           (1U)
#define VFCCU_0_FHFLTENC0_0_EN20(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTENC0_0_EN20_SHIFT)) & VFCCU_0_FHFLTENC0_0_EN20_MASK)

#define VFCCU_0_FHFLTENC0_0_EN21_MASK            (0x200000U)
#define VFCCU_0_FHFLTENC0_0_EN21_SHIFT           (21U)
#define VFCCU_0_FHFLTENC0_0_EN21_WIDTH           (1U)
#define VFCCU_0_FHFLTENC0_0_EN21(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTENC0_0_EN21_SHIFT)) & VFCCU_0_FHFLTENC0_0_EN21_MASK)

#define VFCCU_0_FHFLTENC0_0_EN22_MASK            (0x400000U)
#define VFCCU_0_FHFLTENC0_0_EN22_SHIFT           (22U)
#define VFCCU_0_FHFLTENC0_0_EN22_WIDTH           (1U)
#define VFCCU_0_FHFLTENC0_0_EN22(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTENC0_0_EN22_SHIFT)) & VFCCU_0_FHFLTENC0_0_EN22_MASK)

#define VFCCU_0_FHFLTENC0_0_EN23_MASK            (0x800000U)
#define VFCCU_0_FHFLTENC0_0_EN23_SHIFT           (23U)
#define VFCCU_0_FHFLTENC0_0_EN23_WIDTH           (1U)
#define VFCCU_0_FHFLTENC0_0_EN23(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTENC0_0_EN23_SHIFT)) & VFCCU_0_FHFLTENC0_0_EN23_MASK)

#define VFCCU_0_FHFLTENC0_0_EN24_MASK            (0x1000000U)
#define VFCCU_0_FHFLTENC0_0_EN24_SHIFT           (24U)
#define VFCCU_0_FHFLTENC0_0_EN24_WIDTH           (1U)
#define VFCCU_0_FHFLTENC0_0_EN24(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTENC0_0_EN24_SHIFT)) & VFCCU_0_FHFLTENC0_0_EN24_MASK)

#define VFCCU_0_FHFLTENC0_0_EN25_MASK            (0x2000000U)
#define VFCCU_0_FHFLTENC0_0_EN25_SHIFT           (25U)
#define VFCCU_0_FHFLTENC0_0_EN25_WIDTH           (1U)
#define VFCCU_0_FHFLTENC0_0_EN25(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTENC0_0_EN25_SHIFT)) & VFCCU_0_FHFLTENC0_0_EN25_MASK)

#define VFCCU_0_FHFLTENC0_0_EN26_MASK            (0x4000000U)
#define VFCCU_0_FHFLTENC0_0_EN26_SHIFT           (26U)
#define VFCCU_0_FHFLTENC0_0_EN26_WIDTH           (1U)
#define VFCCU_0_FHFLTENC0_0_EN26(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTENC0_0_EN26_SHIFT)) & VFCCU_0_FHFLTENC0_0_EN26_MASK)

#define VFCCU_0_FHFLTENC0_0_EN27_MASK            (0x8000000U)
#define VFCCU_0_FHFLTENC0_0_EN27_SHIFT           (27U)
#define VFCCU_0_FHFLTENC0_0_EN27_WIDTH           (1U)
#define VFCCU_0_FHFLTENC0_0_EN27(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTENC0_0_EN27_SHIFT)) & VFCCU_0_FHFLTENC0_0_EN27_MASK)

#define VFCCU_0_FHFLTENC0_0_EN28_MASK            (0x10000000U)
#define VFCCU_0_FHFLTENC0_0_EN28_SHIFT           (28U)
#define VFCCU_0_FHFLTENC0_0_EN28_WIDTH           (1U)
#define VFCCU_0_FHFLTENC0_0_EN28(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTENC0_0_EN28_SHIFT)) & VFCCU_0_FHFLTENC0_0_EN28_MASK)

#define VFCCU_0_FHFLTENC0_0_EN29_MASK            (0x20000000U)
#define VFCCU_0_FHFLTENC0_0_EN29_SHIFT           (29U)
#define VFCCU_0_FHFLTENC0_0_EN29_WIDTH           (1U)
#define VFCCU_0_FHFLTENC0_0_EN29(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTENC0_0_EN29_SHIFT)) & VFCCU_0_FHFLTENC0_0_EN29_MASK)

#define VFCCU_0_FHFLTENC0_0_EN30_MASK            (0x40000000U)
#define VFCCU_0_FHFLTENC0_0_EN30_SHIFT           (30U)
#define VFCCU_0_FHFLTENC0_0_EN30_WIDTH           (1U)
#define VFCCU_0_FHFLTENC0_0_EN30(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTENC0_0_EN30_SHIFT)) & VFCCU_0_FHFLTENC0_0_EN30_MASK)

#define VFCCU_0_FHFLTENC0_0_EN31_MASK            (0x80000000U)
#define VFCCU_0_FHFLTENC0_0_EN31_SHIFT           (31U)
#define VFCCU_0_FHFLTENC0_0_EN31_WIDTH           (1U)
#define VFCCU_0_FHFLTENC0_0_EN31(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTENC0_0_EN31_SHIFT)) & VFCCU_0_FHFLTENC0_0_EN31_MASK)
/*! @} */

/*! @name FHFLTENC0_1 - Fault Enable */
/*! @{ */

#define VFCCU_0_FHFLTENC0_1_EN32_MASK            (0x1U)
#define VFCCU_0_FHFLTENC0_1_EN32_SHIFT           (0U)
#define VFCCU_0_FHFLTENC0_1_EN32_WIDTH           (1U)
#define VFCCU_0_FHFLTENC0_1_EN32(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTENC0_1_EN32_SHIFT)) & VFCCU_0_FHFLTENC0_1_EN32_MASK)

#define VFCCU_0_FHFLTENC0_1_EN33_MASK            (0x2U)
#define VFCCU_0_FHFLTENC0_1_EN33_SHIFT           (1U)
#define VFCCU_0_FHFLTENC0_1_EN33_WIDTH           (1U)
#define VFCCU_0_FHFLTENC0_1_EN33(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTENC0_1_EN33_SHIFT)) & VFCCU_0_FHFLTENC0_1_EN33_MASK)

#define VFCCU_0_FHFLTENC0_1_EN34_MASK            (0x4U)
#define VFCCU_0_FHFLTENC0_1_EN34_SHIFT           (2U)
#define VFCCU_0_FHFLTENC0_1_EN34_WIDTH           (1U)
#define VFCCU_0_FHFLTENC0_1_EN34(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTENC0_1_EN34_SHIFT)) & VFCCU_0_FHFLTENC0_1_EN34_MASK)

#define VFCCU_0_FHFLTENC0_1_EN35_MASK            (0x8U)
#define VFCCU_0_FHFLTENC0_1_EN35_SHIFT           (3U)
#define VFCCU_0_FHFLTENC0_1_EN35_WIDTH           (1U)
#define VFCCU_0_FHFLTENC0_1_EN35(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTENC0_1_EN35_SHIFT)) & VFCCU_0_FHFLTENC0_1_EN35_MASK)

#define VFCCU_0_FHFLTENC0_1_EN36_MASK            (0x10U)
#define VFCCU_0_FHFLTENC0_1_EN36_SHIFT           (4U)
#define VFCCU_0_FHFLTENC0_1_EN36_WIDTH           (1U)
#define VFCCU_0_FHFLTENC0_1_EN36(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTENC0_1_EN36_SHIFT)) & VFCCU_0_FHFLTENC0_1_EN36_MASK)

#define VFCCU_0_FHFLTENC0_1_EN37_MASK            (0x20U)
#define VFCCU_0_FHFLTENC0_1_EN37_SHIFT           (5U)
#define VFCCU_0_FHFLTENC0_1_EN37_WIDTH           (1U)
#define VFCCU_0_FHFLTENC0_1_EN37(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTENC0_1_EN37_SHIFT)) & VFCCU_0_FHFLTENC0_1_EN37_MASK)

#define VFCCU_0_FHFLTENC0_1_EN38_MASK            (0x40U)
#define VFCCU_0_FHFLTENC0_1_EN38_SHIFT           (6U)
#define VFCCU_0_FHFLTENC0_1_EN38_WIDTH           (1U)
#define VFCCU_0_FHFLTENC0_1_EN38(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTENC0_1_EN38_SHIFT)) & VFCCU_0_FHFLTENC0_1_EN38_MASK)

#define VFCCU_0_FHFLTENC0_1_EN39_MASK            (0x80U)
#define VFCCU_0_FHFLTENC0_1_EN39_SHIFT           (7U)
#define VFCCU_0_FHFLTENC0_1_EN39_WIDTH           (1U)
#define VFCCU_0_FHFLTENC0_1_EN39(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTENC0_1_EN39_SHIFT)) & VFCCU_0_FHFLTENC0_1_EN39_MASK)

#define VFCCU_0_FHFLTENC0_1_EN40_MASK            (0x100U)
#define VFCCU_0_FHFLTENC0_1_EN40_SHIFT           (8U)
#define VFCCU_0_FHFLTENC0_1_EN40_WIDTH           (1U)
#define VFCCU_0_FHFLTENC0_1_EN40(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTENC0_1_EN40_SHIFT)) & VFCCU_0_FHFLTENC0_1_EN40_MASK)

#define VFCCU_0_FHFLTENC0_1_EN41_MASK            (0x200U)
#define VFCCU_0_FHFLTENC0_1_EN41_SHIFT           (9U)
#define VFCCU_0_FHFLTENC0_1_EN41_WIDTH           (1U)
#define VFCCU_0_FHFLTENC0_1_EN41(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTENC0_1_EN41_SHIFT)) & VFCCU_0_FHFLTENC0_1_EN41_MASK)

#define VFCCU_0_FHFLTENC0_1_EN42_MASK            (0x400U)
#define VFCCU_0_FHFLTENC0_1_EN42_SHIFT           (10U)
#define VFCCU_0_FHFLTENC0_1_EN42_WIDTH           (1U)
#define VFCCU_0_FHFLTENC0_1_EN42(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTENC0_1_EN42_SHIFT)) & VFCCU_0_FHFLTENC0_1_EN42_MASK)

#define VFCCU_0_FHFLTENC0_1_EN43_MASK            (0x800U)
#define VFCCU_0_FHFLTENC0_1_EN43_SHIFT           (11U)
#define VFCCU_0_FHFLTENC0_1_EN43_WIDTH           (1U)
#define VFCCU_0_FHFLTENC0_1_EN43(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTENC0_1_EN43_SHIFT)) & VFCCU_0_FHFLTENC0_1_EN43_MASK)

#define VFCCU_0_FHFLTENC0_1_EN44_MASK            (0x1000U)
#define VFCCU_0_FHFLTENC0_1_EN44_SHIFT           (12U)
#define VFCCU_0_FHFLTENC0_1_EN44_WIDTH           (1U)
#define VFCCU_0_FHFLTENC0_1_EN44(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTENC0_1_EN44_SHIFT)) & VFCCU_0_FHFLTENC0_1_EN44_MASK)

#define VFCCU_0_FHFLTENC0_1_EN45_MASK            (0x2000U)
#define VFCCU_0_FHFLTENC0_1_EN45_SHIFT           (13U)
#define VFCCU_0_FHFLTENC0_1_EN45_WIDTH           (1U)
#define VFCCU_0_FHFLTENC0_1_EN45(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTENC0_1_EN45_SHIFT)) & VFCCU_0_FHFLTENC0_1_EN45_MASK)

#define VFCCU_0_FHFLTENC0_1_EN46_MASK            (0x4000U)
#define VFCCU_0_FHFLTENC0_1_EN46_SHIFT           (14U)
#define VFCCU_0_FHFLTENC0_1_EN46_WIDTH           (1U)
#define VFCCU_0_FHFLTENC0_1_EN46(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTENC0_1_EN46_SHIFT)) & VFCCU_0_FHFLTENC0_1_EN46_MASK)

#define VFCCU_0_FHFLTENC0_1_EN47_MASK            (0x8000U)
#define VFCCU_0_FHFLTENC0_1_EN47_SHIFT           (15U)
#define VFCCU_0_FHFLTENC0_1_EN47_WIDTH           (1U)
#define VFCCU_0_FHFLTENC0_1_EN47(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTENC0_1_EN47_SHIFT)) & VFCCU_0_FHFLTENC0_1_EN47_MASK)

#define VFCCU_0_FHFLTENC0_1_EN48_MASK            (0x10000U)
#define VFCCU_0_FHFLTENC0_1_EN48_SHIFT           (16U)
#define VFCCU_0_FHFLTENC0_1_EN48_WIDTH           (1U)
#define VFCCU_0_FHFLTENC0_1_EN48(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTENC0_1_EN48_SHIFT)) & VFCCU_0_FHFLTENC0_1_EN48_MASK)

#define VFCCU_0_FHFLTENC0_1_EN49_MASK            (0x20000U)
#define VFCCU_0_FHFLTENC0_1_EN49_SHIFT           (17U)
#define VFCCU_0_FHFLTENC0_1_EN49_WIDTH           (1U)
#define VFCCU_0_FHFLTENC0_1_EN49(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTENC0_1_EN49_SHIFT)) & VFCCU_0_FHFLTENC0_1_EN49_MASK)

#define VFCCU_0_FHFLTENC0_1_EN50_MASK            (0x40000U)
#define VFCCU_0_FHFLTENC0_1_EN50_SHIFT           (18U)
#define VFCCU_0_FHFLTENC0_1_EN50_WIDTH           (1U)
#define VFCCU_0_FHFLTENC0_1_EN50(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTENC0_1_EN50_SHIFT)) & VFCCU_0_FHFLTENC0_1_EN50_MASK)

#define VFCCU_0_FHFLTENC0_1_EN51_MASK            (0x80000U)
#define VFCCU_0_FHFLTENC0_1_EN51_SHIFT           (19U)
#define VFCCU_0_FHFLTENC0_1_EN51_WIDTH           (1U)
#define VFCCU_0_FHFLTENC0_1_EN51(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTENC0_1_EN51_SHIFT)) & VFCCU_0_FHFLTENC0_1_EN51_MASK)

#define VFCCU_0_FHFLTENC0_1_EN52_MASK            (0x100000U)
#define VFCCU_0_FHFLTENC0_1_EN52_SHIFT           (20U)
#define VFCCU_0_FHFLTENC0_1_EN52_WIDTH           (1U)
#define VFCCU_0_FHFLTENC0_1_EN52(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTENC0_1_EN52_SHIFT)) & VFCCU_0_FHFLTENC0_1_EN52_MASK)

#define VFCCU_0_FHFLTENC0_1_EN53_MASK            (0x200000U)
#define VFCCU_0_FHFLTENC0_1_EN53_SHIFT           (21U)
#define VFCCU_0_FHFLTENC0_1_EN53_WIDTH           (1U)
#define VFCCU_0_FHFLTENC0_1_EN53(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTENC0_1_EN53_SHIFT)) & VFCCU_0_FHFLTENC0_1_EN53_MASK)

#define VFCCU_0_FHFLTENC0_1_EN54_MASK            (0x400000U)
#define VFCCU_0_FHFLTENC0_1_EN54_SHIFT           (22U)
#define VFCCU_0_FHFLTENC0_1_EN54_WIDTH           (1U)
#define VFCCU_0_FHFLTENC0_1_EN54(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTENC0_1_EN54_SHIFT)) & VFCCU_0_FHFLTENC0_1_EN54_MASK)

#define VFCCU_0_FHFLTENC0_1_EN55_MASK            (0x800000U)
#define VFCCU_0_FHFLTENC0_1_EN55_SHIFT           (23U)
#define VFCCU_0_FHFLTENC0_1_EN55_WIDTH           (1U)
#define VFCCU_0_FHFLTENC0_1_EN55(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTENC0_1_EN55_SHIFT)) & VFCCU_0_FHFLTENC0_1_EN55_MASK)

#define VFCCU_0_FHFLTENC0_1_EN56_MASK            (0x1000000U)
#define VFCCU_0_FHFLTENC0_1_EN56_SHIFT           (24U)
#define VFCCU_0_FHFLTENC0_1_EN56_WIDTH           (1U)
#define VFCCU_0_FHFLTENC0_1_EN56(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTENC0_1_EN56_SHIFT)) & VFCCU_0_FHFLTENC0_1_EN56_MASK)

#define VFCCU_0_FHFLTENC0_1_EN57_MASK            (0x2000000U)
#define VFCCU_0_FHFLTENC0_1_EN57_SHIFT           (25U)
#define VFCCU_0_FHFLTENC0_1_EN57_WIDTH           (1U)
#define VFCCU_0_FHFLTENC0_1_EN57(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTENC0_1_EN57_SHIFT)) & VFCCU_0_FHFLTENC0_1_EN57_MASK)

#define VFCCU_0_FHFLTENC0_1_EN58_MASK            (0x4000000U)
#define VFCCU_0_FHFLTENC0_1_EN58_SHIFT           (26U)
#define VFCCU_0_FHFLTENC0_1_EN58_WIDTH           (1U)
#define VFCCU_0_FHFLTENC0_1_EN58(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTENC0_1_EN58_SHIFT)) & VFCCU_0_FHFLTENC0_1_EN58_MASK)

#define VFCCU_0_FHFLTENC0_1_EN59_MASK            (0x8000000U)
#define VFCCU_0_FHFLTENC0_1_EN59_SHIFT           (27U)
#define VFCCU_0_FHFLTENC0_1_EN59_WIDTH           (1U)
#define VFCCU_0_FHFLTENC0_1_EN59(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTENC0_1_EN59_SHIFT)) & VFCCU_0_FHFLTENC0_1_EN59_MASK)

#define VFCCU_0_FHFLTENC0_1_EN60_MASK            (0x10000000U)
#define VFCCU_0_FHFLTENC0_1_EN60_SHIFT           (28U)
#define VFCCU_0_FHFLTENC0_1_EN60_WIDTH           (1U)
#define VFCCU_0_FHFLTENC0_1_EN60(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTENC0_1_EN60_SHIFT)) & VFCCU_0_FHFLTENC0_1_EN60_MASK)

#define VFCCU_0_FHFLTENC0_1_EN61_MASK            (0x20000000U)
#define VFCCU_0_FHFLTENC0_1_EN61_SHIFT           (29U)
#define VFCCU_0_FHFLTENC0_1_EN61_WIDTH           (1U)
#define VFCCU_0_FHFLTENC0_1_EN61(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTENC0_1_EN61_SHIFT)) & VFCCU_0_FHFLTENC0_1_EN61_MASK)

#define VFCCU_0_FHFLTENC0_1_EN62_MASK            (0x40000000U)
#define VFCCU_0_FHFLTENC0_1_EN62_SHIFT           (30U)
#define VFCCU_0_FHFLTENC0_1_EN62_WIDTH           (1U)
#define VFCCU_0_FHFLTENC0_1_EN62(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTENC0_1_EN62_SHIFT)) & VFCCU_0_FHFLTENC0_1_EN62_MASK)

#define VFCCU_0_FHFLTENC0_1_EN63_MASK            (0x80000000U)
#define VFCCU_0_FHFLTENC0_1_EN63_SHIFT           (31U)
#define VFCCU_0_FHFLTENC0_1_EN63_WIDTH           (1U)
#define VFCCU_0_FHFLTENC0_1_EN63(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTENC0_1_EN63_SHIFT)) & VFCCU_0_FHFLTENC0_1_EN63_MASK)
/*! @} */

/*! @name FHFLTS0_0 - Fault Status */
/*! @{ */

#define VFCCU_0_FHFLTS0_0_STAT0_MASK             (0x1U)
#define VFCCU_0_FHFLTS0_0_STAT0_SHIFT            (0U)
#define VFCCU_0_FHFLTS0_0_STAT0_WIDTH            (1U)
#define VFCCU_0_FHFLTS0_0_STAT0(x)               (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTS0_0_STAT0_SHIFT)) & VFCCU_0_FHFLTS0_0_STAT0_MASK)

#define VFCCU_0_FHFLTS0_0_STAT1_MASK             (0x2U)
#define VFCCU_0_FHFLTS0_0_STAT1_SHIFT            (1U)
#define VFCCU_0_FHFLTS0_0_STAT1_WIDTH            (1U)
#define VFCCU_0_FHFLTS0_0_STAT1(x)               (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTS0_0_STAT1_SHIFT)) & VFCCU_0_FHFLTS0_0_STAT1_MASK)

#define VFCCU_0_FHFLTS0_0_STAT2_MASK             (0x4U)
#define VFCCU_0_FHFLTS0_0_STAT2_SHIFT            (2U)
#define VFCCU_0_FHFLTS0_0_STAT2_WIDTH            (1U)
#define VFCCU_0_FHFLTS0_0_STAT2(x)               (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTS0_0_STAT2_SHIFT)) & VFCCU_0_FHFLTS0_0_STAT2_MASK)

#define VFCCU_0_FHFLTS0_0_STAT3_MASK             (0x8U)
#define VFCCU_0_FHFLTS0_0_STAT3_SHIFT            (3U)
#define VFCCU_0_FHFLTS0_0_STAT3_WIDTH            (1U)
#define VFCCU_0_FHFLTS0_0_STAT3(x)               (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTS0_0_STAT3_SHIFT)) & VFCCU_0_FHFLTS0_0_STAT3_MASK)

#define VFCCU_0_FHFLTS0_0_STAT4_MASK             (0x10U)
#define VFCCU_0_FHFLTS0_0_STAT4_SHIFT            (4U)
#define VFCCU_0_FHFLTS0_0_STAT4_WIDTH            (1U)
#define VFCCU_0_FHFLTS0_0_STAT4(x)               (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTS0_0_STAT4_SHIFT)) & VFCCU_0_FHFLTS0_0_STAT4_MASK)

#define VFCCU_0_FHFLTS0_0_STAT5_MASK             (0x20U)
#define VFCCU_0_FHFLTS0_0_STAT5_SHIFT            (5U)
#define VFCCU_0_FHFLTS0_0_STAT5_WIDTH            (1U)
#define VFCCU_0_FHFLTS0_0_STAT5(x)               (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTS0_0_STAT5_SHIFT)) & VFCCU_0_FHFLTS0_0_STAT5_MASK)

#define VFCCU_0_FHFLTS0_0_STAT6_MASK             (0x40U)
#define VFCCU_0_FHFLTS0_0_STAT6_SHIFT            (6U)
#define VFCCU_0_FHFLTS0_0_STAT6_WIDTH            (1U)
#define VFCCU_0_FHFLTS0_0_STAT6(x)               (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTS0_0_STAT6_SHIFT)) & VFCCU_0_FHFLTS0_0_STAT6_MASK)

#define VFCCU_0_FHFLTS0_0_STAT7_MASK             (0x80U)
#define VFCCU_0_FHFLTS0_0_STAT7_SHIFT            (7U)
#define VFCCU_0_FHFLTS0_0_STAT7_WIDTH            (1U)
#define VFCCU_0_FHFLTS0_0_STAT7(x)               (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTS0_0_STAT7_SHIFT)) & VFCCU_0_FHFLTS0_0_STAT7_MASK)

#define VFCCU_0_FHFLTS0_0_STAT8_MASK             (0x100U)
#define VFCCU_0_FHFLTS0_0_STAT8_SHIFT            (8U)
#define VFCCU_0_FHFLTS0_0_STAT8_WIDTH            (1U)
#define VFCCU_0_FHFLTS0_0_STAT8(x)               (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTS0_0_STAT8_SHIFT)) & VFCCU_0_FHFLTS0_0_STAT8_MASK)

#define VFCCU_0_FHFLTS0_0_STAT9_MASK             (0x200U)
#define VFCCU_0_FHFLTS0_0_STAT9_SHIFT            (9U)
#define VFCCU_0_FHFLTS0_0_STAT9_WIDTH            (1U)
#define VFCCU_0_FHFLTS0_0_STAT9(x)               (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTS0_0_STAT9_SHIFT)) & VFCCU_0_FHFLTS0_0_STAT9_MASK)

#define VFCCU_0_FHFLTS0_0_STAT10_MASK            (0x400U)
#define VFCCU_0_FHFLTS0_0_STAT10_SHIFT           (10U)
#define VFCCU_0_FHFLTS0_0_STAT10_WIDTH           (1U)
#define VFCCU_0_FHFLTS0_0_STAT10(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTS0_0_STAT10_SHIFT)) & VFCCU_0_FHFLTS0_0_STAT10_MASK)

#define VFCCU_0_FHFLTS0_0_STAT11_MASK            (0x800U)
#define VFCCU_0_FHFLTS0_0_STAT11_SHIFT           (11U)
#define VFCCU_0_FHFLTS0_0_STAT11_WIDTH           (1U)
#define VFCCU_0_FHFLTS0_0_STAT11(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTS0_0_STAT11_SHIFT)) & VFCCU_0_FHFLTS0_0_STAT11_MASK)

#define VFCCU_0_FHFLTS0_0_STAT12_MASK            (0x1000U)
#define VFCCU_0_FHFLTS0_0_STAT12_SHIFT           (12U)
#define VFCCU_0_FHFLTS0_0_STAT12_WIDTH           (1U)
#define VFCCU_0_FHFLTS0_0_STAT12(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTS0_0_STAT12_SHIFT)) & VFCCU_0_FHFLTS0_0_STAT12_MASK)

#define VFCCU_0_FHFLTS0_0_STAT13_MASK            (0x2000U)
#define VFCCU_0_FHFLTS0_0_STAT13_SHIFT           (13U)
#define VFCCU_0_FHFLTS0_0_STAT13_WIDTH           (1U)
#define VFCCU_0_FHFLTS0_0_STAT13(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTS0_0_STAT13_SHIFT)) & VFCCU_0_FHFLTS0_0_STAT13_MASK)

#define VFCCU_0_FHFLTS0_0_STAT14_MASK            (0x4000U)
#define VFCCU_0_FHFLTS0_0_STAT14_SHIFT           (14U)
#define VFCCU_0_FHFLTS0_0_STAT14_WIDTH           (1U)
#define VFCCU_0_FHFLTS0_0_STAT14(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTS0_0_STAT14_SHIFT)) & VFCCU_0_FHFLTS0_0_STAT14_MASK)

#define VFCCU_0_FHFLTS0_0_STAT15_MASK            (0x8000U)
#define VFCCU_0_FHFLTS0_0_STAT15_SHIFT           (15U)
#define VFCCU_0_FHFLTS0_0_STAT15_WIDTH           (1U)
#define VFCCU_0_FHFLTS0_0_STAT15(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTS0_0_STAT15_SHIFT)) & VFCCU_0_FHFLTS0_0_STAT15_MASK)

#define VFCCU_0_FHFLTS0_0_STAT16_MASK            (0x10000U)
#define VFCCU_0_FHFLTS0_0_STAT16_SHIFT           (16U)
#define VFCCU_0_FHFLTS0_0_STAT16_WIDTH           (1U)
#define VFCCU_0_FHFLTS0_0_STAT16(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTS0_0_STAT16_SHIFT)) & VFCCU_0_FHFLTS0_0_STAT16_MASK)

#define VFCCU_0_FHFLTS0_0_STAT17_MASK            (0x20000U)
#define VFCCU_0_FHFLTS0_0_STAT17_SHIFT           (17U)
#define VFCCU_0_FHFLTS0_0_STAT17_WIDTH           (1U)
#define VFCCU_0_FHFLTS0_0_STAT17(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTS0_0_STAT17_SHIFT)) & VFCCU_0_FHFLTS0_0_STAT17_MASK)

#define VFCCU_0_FHFLTS0_0_STAT18_MASK            (0x40000U)
#define VFCCU_0_FHFLTS0_0_STAT18_SHIFT           (18U)
#define VFCCU_0_FHFLTS0_0_STAT18_WIDTH           (1U)
#define VFCCU_0_FHFLTS0_0_STAT18(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTS0_0_STAT18_SHIFT)) & VFCCU_0_FHFLTS0_0_STAT18_MASK)

#define VFCCU_0_FHFLTS0_0_STAT19_MASK            (0x80000U)
#define VFCCU_0_FHFLTS0_0_STAT19_SHIFT           (19U)
#define VFCCU_0_FHFLTS0_0_STAT19_WIDTH           (1U)
#define VFCCU_0_FHFLTS0_0_STAT19(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTS0_0_STAT19_SHIFT)) & VFCCU_0_FHFLTS0_0_STAT19_MASK)

#define VFCCU_0_FHFLTS0_0_STAT20_MASK            (0x100000U)
#define VFCCU_0_FHFLTS0_0_STAT20_SHIFT           (20U)
#define VFCCU_0_FHFLTS0_0_STAT20_WIDTH           (1U)
#define VFCCU_0_FHFLTS0_0_STAT20(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTS0_0_STAT20_SHIFT)) & VFCCU_0_FHFLTS0_0_STAT20_MASK)

#define VFCCU_0_FHFLTS0_0_STAT21_MASK            (0x200000U)
#define VFCCU_0_FHFLTS0_0_STAT21_SHIFT           (21U)
#define VFCCU_0_FHFLTS0_0_STAT21_WIDTH           (1U)
#define VFCCU_0_FHFLTS0_0_STAT21(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTS0_0_STAT21_SHIFT)) & VFCCU_0_FHFLTS0_0_STAT21_MASK)

#define VFCCU_0_FHFLTS0_0_STAT22_MASK            (0x400000U)
#define VFCCU_0_FHFLTS0_0_STAT22_SHIFT           (22U)
#define VFCCU_0_FHFLTS0_0_STAT22_WIDTH           (1U)
#define VFCCU_0_FHFLTS0_0_STAT22(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTS0_0_STAT22_SHIFT)) & VFCCU_0_FHFLTS0_0_STAT22_MASK)

#define VFCCU_0_FHFLTS0_0_STAT23_MASK            (0x800000U)
#define VFCCU_0_FHFLTS0_0_STAT23_SHIFT           (23U)
#define VFCCU_0_FHFLTS0_0_STAT23_WIDTH           (1U)
#define VFCCU_0_FHFLTS0_0_STAT23(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTS0_0_STAT23_SHIFT)) & VFCCU_0_FHFLTS0_0_STAT23_MASK)

#define VFCCU_0_FHFLTS0_0_STAT24_MASK            (0x1000000U)
#define VFCCU_0_FHFLTS0_0_STAT24_SHIFT           (24U)
#define VFCCU_0_FHFLTS0_0_STAT24_WIDTH           (1U)
#define VFCCU_0_FHFLTS0_0_STAT24(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTS0_0_STAT24_SHIFT)) & VFCCU_0_FHFLTS0_0_STAT24_MASK)

#define VFCCU_0_FHFLTS0_0_STAT25_MASK            (0x2000000U)
#define VFCCU_0_FHFLTS0_0_STAT25_SHIFT           (25U)
#define VFCCU_0_FHFLTS0_0_STAT25_WIDTH           (1U)
#define VFCCU_0_FHFLTS0_0_STAT25(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTS0_0_STAT25_SHIFT)) & VFCCU_0_FHFLTS0_0_STAT25_MASK)

#define VFCCU_0_FHFLTS0_0_STAT26_MASK            (0x4000000U)
#define VFCCU_0_FHFLTS0_0_STAT26_SHIFT           (26U)
#define VFCCU_0_FHFLTS0_0_STAT26_WIDTH           (1U)
#define VFCCU_0_FHFLTS0_0_STAT26(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTS0_0_STAT26_SHIFT)) & VFCCU_0_FHFLTS0_0_STAT26_MASK)

#define VFCCU_0_FHFLTS0_0_STAT27_MASK            (0x8000000U)
#define VFCCU_0_FHFLTS0_0_STAT27_SHIFT           (27U)
#define VFCCU_0_FHFLTS0_0_STAT27_WIDTH           (1U)
#define VFCCU_0_FHFLTS0_0_STAT27(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTS0_0_STAT27_SHIFT)) & VFCCU_0_FHFLTS0_0_STAT27_MASK)

#define VFCCU_0_FHFLTS0_0_STAT28_MASK            (0x10000000U)
#define VFCCU_0_FHFLTS0_0_STAT28_SHIFT           (28U)
#define VFCCU_0_FHFLTS0_0_STAT28_WIDTH           (1U)
#define VFCCU_0_FHFLTS0_0_STAT28(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTS0_0_STAT28_SHIFT)) & VFCCU_0_FHFLTS0_0_STAT28_MASK)

#define VFCCU_0_FHFLTS0_0_STAT29_MASK            (0x20000000U)
#define VFCCU_0_FHFLTS0_0_STAT29_SHIFT           (29U)
#define VFCCU_0_FHFLTS0_0_STAT29_WIDTH           (1U)
#define VFCCU_0_FHFLTS0_0_STAT29(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTS0_0_STAT29_SHIFT)) & VFCCU_0_FHFLTS0_0_STAT29_MASK)

#define VFCCU_0_FHFLTS0_0_STAT30_MASK            (0x40000000U)
#define VFCCU_0_FHFLTS0_0_STAT30_SHIFT           (30U)
#define VFCCU_0_FHFLTS0_0_STAT30_WIDTH           (1U)
#define VFCCU_0_FHFLTS0_0_STAT30(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTS0_0_STAT30_SHIFT)) & VFCCU_0_FHFLTS0_0_STAT30_MASK)

#define VFCCU_0_FHFLTS0_0_STAT31_MASK            (0x80000000U)
#define VFCCU_0_FHFLTS0_0_STAT31_SHIFT           (31U)
#define VFCCU_0_FHFLTS0_0_STAT31_WIDTH           (1U)
#define VFCCU_0_FHFLTS0_0_STAT31(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTS0_0_STAT31_SHIFT)) & VFCCU_0_FHFLTS0_0_STAT31_MASK)
/*! @} */

/*! @name FHFLTS0_1 - Fault Status */
/*! @{ */

#define VFCCU_0_FHFLTS0_1_STAT32_MASK            (0x1U)
#define VFCCU_0_FHFLTS0_1_STAT32_SHIFT           (0U)
#define VFCCU_0_FHFLTS0_1_STAT32_WIDTH           (1U)
#define VFCCU_0_FHFLTS0_1_STAT32(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTS0_1_STAT32_SHIFT)) & VFCCU_0_FHFLTS0_1_STAT32_MASK)

#define VFCCU_0_FHFLTS0_1_STAT33_MASK            (0x2U)
#define VFCCU_0_FHFLTS0_1_STAT33_SHIFT           (1U)
#define VFCCU_0_FHFLTS0_1_STAT33_WIDTH           (1U)
#define VFCCU_0_FHFLTS0_1_STAT33(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTS0_1_STAT33_SHIFT)) & VFCCU_0_FHFLTS0_1_STAT33_MASK)

#define VFCCU_0_FHFLTS0_1_STAT34_MASK            (0x4U)
#define VFCCU_0_FHFLTS0_1_STAT34_SHIFT           (2U)
#define VFCCU_0_FHFLTS0_1_STAT34_WIDTH           (1U)
#define VFCCU_0_FHFLTS0_1_STAT34(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTS0_1_STAT34_SHIFT)) & VFCCU_0_FHFLTS0_1_STAT34_MASK)

#define VFCCU_0_FHFLTS0_1_STAT35_MASK            (0x8U)
#define VFCCU_0_FHFLTS0_1_STAT35_SHIFT           (3U)
#define VFCCU_0_FHFLTS0_1_STAT35_WIDTH           (1U)
#define VFCCU_0_FHFLTS0_1_STAT35(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTS0_1_STAT35_SHIFT)) & VFCCU_0_FHFLTS0_1_STAT35_MASK)

#define VFCCU_0_FHFLTS0_1_STAT36_MASK            (0x10U)
#define VFCCU_0_FHFLTS0_1_STAT36_SHIFT           (4U)
#define VFCCU_0_FHFLTS0_1_STAT36_WIDTH           (1U)
#define VFCCU_0_FHFLTS0_1_STAT36(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTS0_1_STAT36_SHIFT)) & VFCCU_0_FHFLTS0_1_STAT36_MASK)

#define VFCCU_0_FHFLTS0_1_STAT37_MASK            (0x20U)
#define VFCCU_0_FHFLTS0_1_STAT37_SHIFT           (5U)
#define VFCCU_0_FHFLTS0_1_STAT37_WIDTH           (1U)
#define VFCCU_0_FHFLTS0_1_STAT37(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTS0_1_STAT37_SHIFT)) & VFCCU_0_FHFLTS0_1_STAT37_MASK)

#define VFCCU_0_FHFLTS0_1_STAT38_MASK            (0x40U)
#define VFCCU_0_FHFLTS0_1_STAT38_SHIFT           (6U)
#define VFCCU_0_FHFLTS0_1_STAT38_WIDTH           (1U)
#define VFCCU_0_FHFLTS0_1_STAT38(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTS0_1_STAT38_SHIFT)) & VFCCU_0_FHFLTS0_1_STAT38_MASK)

#define VFCCU_0_FHFLTS0_1_STAT39_MASK            (0x80U)
#define VFCCU_0_FHFLTS0_1_STAT39_SHIFT           (7U)
#define VFCCU_0_FHFLTS0_1_STAT39_WIDTH           (1U)
#define VFCCU_0_FHFLTS0_1_STAT39(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTS0_1_STAT39_SHIFT)) & VFCCU_0_FHFLTS0_1_STAT39_MASK)

#define VFCCU_0_FHFLTS0_1_STAT40_MASK            (0x100U)
#define VFCCU_0_FHFLTS0_1_STAT40_SHIFT           (8U)
#define VFCCU_0_FHFLTS0_1_STAT40_WIDTH           (1U)
#define VFCCU_0_FHFLTS0_1_STAT40(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTS0_1_STAT40_SHIFT)) & VFCCU_0_FHFLTS0_1_STAT40_MASK)

#define VFCCU_0_FHFLTS0_1_STAT41_MASK            (0x200U)
#define VFCCU_0_FHFLTS0_1_STAT41_SHIFT           (9U)
#define VFCCU_0_FHFLTS0_1_STAT41_WIDTH           (1U)
#define VFCCU_0_FHFLTS0_1_STAT41(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTS0_1_STAT41_SHIFT)) & VFCCU_0_FHFLTS0_1_STAT41_MASK)

#define VFCCU_0_FHFLTS0_1_STAT42_MASK            (0x400U)
#define VFCCU_0_FHFLTS0_1_STAT42_SHIFT           (10U)
#define VFCCU_0_FHFLTS0_1_STAT42_WIDTH           (1U)
#define VFCCU_0_FHFLTS0_1_STAT42(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTS0_1_STAT42_SHIFT)) & VFCCU_0_FHFLTS0_1_STAT42_MASK)

#define VFCCU_0_FHFLTS0_1_STAT43_MASK            (0x800U)
#define VFCCU_0_FHFLTS0_1_STAT43_SHIFT           (11U)
#define VFCCU_0_FHFLTS0_1_STAT43_WIDTH           (1U)
#define VFCCU_0_FHFLTS0_1_STAT43(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTS0_1_STAT43_SHIFT)) & VFCCU_0_FHFLTS0_1_STAT43_MASK)

#define VFCCU_0_FHFLTS0_1_STAT44_MASK            (0x1000U)
#define VFCCU_0_FHFLTS0_1_STAT44_SHIFT           (12U)
#define VFCCU_0_FHFLTS0_1_STAT44_WIDTH           (1U)
#define VFCCU_0_FHFLTS0_1_STAT44(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTS0_1_STAT44_SHIFT)) & VFCCU_0_FHFLTS0_1_STAT44_MASK)

#define VFCCU_0_FHFLTS0_1_STAT45_MASK            (0x2000U)
#define VFCCU_0_FHFLTS0_1_STAT45_SHIFT           (13U)
#define VFCCU_0_FHFLTS0_1_STAT45_WIDTH           (1U)
#define VFCCU_0_FHFLTS0_1_STAT45(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTS0_1_STAT45_SHIFT)) & VFCCU_0_FHFLTS0_1_STAT45_MASK)

#define VFCCU_0_FHFLTS0_1_STAT46_MASK            (0x4000U)
#define VFCCU_0_FHFLTS0_1_STAT46_SHIFT           (14U)
#define VFCCU_0_FHFLTS0_1_STAT46_WIDTH           (1U)
#define VFCCU_0_FHFLTS0_1_STAT46(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTS0_1_STAT46_SHIFT)) & VFCCU_0_FHFLTS0_1_STAT46_MASK)

#define VFCCU_0_FHFLTS0_1_STAT47_MASK            (0x8000U)
#define VFCCU_0_FHFLTS0_1_STAT47_SHIFT           (15U)
#define VFCCU_0_FHFLTS0_1_STAT47_WIDTH           (1U)
#define VFCCU_0_FHFLTS0_1_STAT47(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTS0_1_STAT47_SHIFT)) & VFCCU_0_FHFLTS0_1_STAT47_MASK)

#define VFCCU_0_FHFLTS0_1_STAT48_MASK            (0x10000U)
#define VFCCU_0_FHFLTS0_1_STAT48_SHIFT           (16U)
#define VFCCU_0_FHFLTS0_1_STAT48_WIDTH           (1U)
#define VFCCU_0_FHFLTS0_1_STAT48(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTS0_1_STAT48_SHIFT)) & VFCCU_0_FHFLTS0_1_STAT48_MASK)

#define VFCCU_0_FHFLTS0_1_STAT49_MASK            (0x20000U)
#define VFCCU_0_FHFLTS0_1_STAT49_SHIFT           (17U)
#define VFCCU_0_FHFLTS0_1_STAT49_WIDTH           (1U)
#define VFCCU_0_FHFLTS0_1_STAT49(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTS0_1_STAT49_SHIFT)) & VFCCU_0_FHFLTS0_1_STAT49_MASK)

#define VFCCU_0_FHFLTS0_1_STAT50_MASK            (0x40000U)
#define VFCCU_0_FHFLTS0_1_STAT50_SHIFT           (18U)
#define VFCCU_0_FHFLTS0_1_STAT50_WIDTH           (1U)
#define VFCCU_0_FHFLTS0_1_STAT50(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTS0_1_STAT50_SHIFT)) & VFCCU_0_FHFLTS0_1_STAT50_MASK)

#define VFCCU_0_FHFLTS0_1_STAT51_MASK            (0x80000U)
#define VFCCU_0_FHFLTS0_1_STAT51_SHIFT           (19U)
#define VFCCU_0_FHFLTS0_1_STAT51_WIDTH           (1U)
#define VFCCU_0_FHFLTS0_1_STAT51(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTS0_1_STAT51_SHIFT)) & VFCCU_0_FHFLTS0_1_STAT51_MASK)

#define VFCCU_0_FHFLTS0_1_STAT52_MASK            (0x100000U)
#define VFCCU_0_FHFLTS0_1_STAT52_SHIFT           (20U)
#define VFCCU_0_FHFLTS0_1_STAT52_WIDTH           (1U)
#define VFCCU_0_FHFLTS0_1_STAT52(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTS0_1_STAT52_SHIFT)) & VFCCU_0_FHFLTS0_1_STAT52_MASK)

#define VFCCU_0_FHFLTS0_1_STAT53_MASK            (0x200000U)
#define VFCCU_0_FHFLTS0_1_STAT53_SHIFT           (21U)
#define VFCCU_0_FHFLTS0_1_STAT53_WIDTH           (1U)
#define VFCCU_0_FHFLTS0_1_STAT53(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTS0_1_STAT53_SHIFT)) & VFCCU_0_FHFLTS0_1_STAT53_MASK)

#define VFCCU_0_FHFLTS0_1_STAT54_MASK            (0x400000U)
#define VFCCU_0_FHFLTS0_1_STAT54_SHIFT           (22U)
#define VFCCU_0_FHFLTS0_1_STAT54_WIDTH           (1U)
#define VFCCU_0_FHFLTS0_1_STAT54(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTS0_1_STAT54_SHIFT)) & VFCCU_0_FHFLTS0_1_STAT54_MASK)

#define VFCCU_0_FHFLTS0_1_STAT55_MASK            (0x800000U)
#define VFCCU_0_FHFLTS0_1_STAT55_SHIFT           (23U)
#define VFCCU_0_FHFLTS0_1_STAT55_WIDTH           (1U)
#define VFCCU_0_FHFLTS0_1_STAT55(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTS0_1_STAT55_SHIFT)) & VFCCU_0_FHFLTS0_1_STAT55_MASK)

#define VFCCU_0_FHFLTS0_1_STAT56_MASK            (0x1000000U)
#define VFCCU_0_FHFLTS0_1_STAT56_SHIFT           (24U)
#define VFCCU_0_FHFLTS0_1_STAT56_WIDTH           (1U)
#define VFCCU_0_FHFLTS0_1_STAT56(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTS0_1_STAT56_SHIFT)) & VFCCU_0_FHFLTS0_1_STAT56_MASK)

#define VFCCU_0_FHFLTS0_1_STAT57_MASK            (0x2000000U)
#define VFCCU_0_FHFLTS0_1_STAT57_SHIFT           (25U)
#define VFCCU_0_FHFLTS0_1_STAT57_WIDTH           (1U)
#define VFCCU_0_FHFLTS0_1_STAT57(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTS0_1_STAT57_SHIFT)) & VFCCU_0_FHFLTS0_1_STAT57_MASK)

#define VFCCU_0_FHFLTS0_1_STAT58_MASK            (0x4000000U)
#define VFCCU_0_FHFLTS0_1_STAT58_SHIFT           (26U)
#define VFCCU_0_FHFLTS0_1_STAT58_WIDTH           (1U)
#define VFCCU_0_FHFLTS0_1_STAT58(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTS0_1_STAT58_SHIFT)) & VFCCU_0_FHFLTS0_1_STAT58_MASK)

#define VFCCU_0_FHFLTS0_1_STAT59_MASK            (0x8000000U)
#define VFCCU_0_FHFLTS0_1_STAT59_SHIFT           (27U)
#define VFCCU_0_FHFLTS0_1_STAT59_WIDTH           (1U)
#define VFCCU_0_FHFLTS0_1_STAT59(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTS0_1_STAT59_SHIFT)) & VFCCU_0_FHFLTS0_1_STAT59_MASK)

#define VFCCU_0_FHFLTS0_1_STAT60_MASK            (0x10000000U)
#define VFCCU_0_FHFLTS0_1_STAT60_SHIFT           (28U)
#define VFCCU_0_FHFLTS0_1_STAT60_WIDTH           (1U)
#define VFCCU_0_FHFLTS0_1_STAT60(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTS0_1_STAT60_SHIFT)) & VFCCU_0_FHFLTS0_1_STAT60_MASK)

#define VFCCU_0_FHFLTS0_1_STAT61_MASK            (0x20000000U)
#define VFCCU_0_FHFLTS0_1_STAT61_SHIFT           (29U)
#define VFCCU_0_FHFLTS0_1_STAT61_WIDTH           (1U)
#define VFCCU_0_FHFLTS0_1_STAT61(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTS0_1_STAT61_SHIFT)) & VFCCU_0_FHFLTS0_1_STAT61_MASK)

#define VFCCU_0_FHFLTS0_1_STAT62_MASK            (0x40000000U)
#define VFCCU_0_FHFLTS0_1_STAT62_SHIFT           (30U)
#define VFCCU_0_FHFLTS0_1_STAT62_WIDTH           (1U)
#define VFCCU_0_FHFLTS0_1_STAT62(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTS0_1_STAT62_SHIFT)) & VFCCU_0_FHFLTS0_1_STAT62_MASK)

#define VFCCU_0_FHFLTS0_1_STAT63_MASK            (0x80000000U)
#define VFCCU_0_FHFLTS0_1_STAT63_SHIFT           (31U)
#define VFCCU_0_FHFLTS0_1_STAT63_WIDTH           (1U)
#define VFCCU_0_FHFLTS0_1_STAT63(x)              (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTS0_1_STAT63_SHIFT)) & VFCCU_0_FHFLTS0_1_STAT63_MASK)
/*! @} */

/*! @name FHFLTRKC0_0 - Fault Reaction Set Configuration */
/*! @{ */

#define VFCCU_0_FHFLTRKC0_0_RKNSEL0_MASK         (0xFU)
#define VFCCU_0_FHFLTRKC0_0_RKNSEL0_SHIFT        (0U)
#define VFCCU_0_FHFLTRKC0_0_RKNSEL0_WIDTH        (4U)
#define VFCCU_0_FHFLTRKC0_0_RKNSEL0(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTRKC0_0_RKNSEL0_SHIFT)) & VFCCU_0_FHFLTRKC0_0_RKNSEL0_MASK)

#define VFCCU_0_FHFLTRKC0_0_RKNSEL1_MASK         (0xF00U)
#define VFCCU_0_FHFLTRKC0_0_RKNSEL1_SHIFT        (8U)
#define VFCCU_0_FHFLTRKC0_0_RKNSEL1_WIDTH        (4U)
#define VFCCU_0_FHFLTRKC0_0_RKNSEL1(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTRKC0_0_RKNSEL1_SHIFT)) & VFCCU_0_FHFLTRKC0_0_RKNSEL1_MASK)

#define VFCCU_0_FHFLTRKC0_0_RKNSEL2_MASK         (0xF0000U)
#define VFCCU_0_FHFLTRKC0_0_RKNSEL2_SHIFT        (16U)
#define VFCCU_0_FHFLTRKC0_0_RKNSEL2_WIDTH        (4U)
#define VFCCU_0_FHFLTRKC0_0_RKNSEL2(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTRKC0_0_RKNSEL2_SHIFT)) & VFCCU_0_FHFLTRKC0_0_RKNSEL2_MASK)

#define VFCCU_0_FHFLTRKC0_0_RKNSEL3_MASK         (0xF000000U)
#define VFCCU_0_FHFLTRKC0_0_RKNSEL3_SHIFT        (24U)
#define VFCCU_0_FHFLTRKC0_0_RKNSEL3_WIDTH        (4U)
#define VFCCU_0_FHFLTRKC0_0_RKNSEL3(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTRKC0_0_RKNSEL3_SHIFT)) & VFCCU_0_FHFLTRKC0_0_RKNSEL3_MASK)
/*! @} */

/*! @name FHFLTRKC0_1 - Fault Reaction Set Configuration */
/*! @{ */

#define VFCCU_0_FHFLTRKC0_1_RKNSEL4_MASK         (0xFU)
#define VFCCU_0_FHFLTRKC0_1_RKNSEL4_SHIFT        (0U)
#define VFCCU_0_FHFLTRKC0_1_RKNSEL4_WIDTH        (4U)
#define VFCCU_0_FHFLTRKC0_1_RKNSEL4(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTRKC0_1_RKNSEL4_SHIFT)) & VFCCU_0_FHFLTRKC0_1_RKNSEL4_MASK)

#define VFCCU_0_FHFLTRKC0_1_RKNSEL5_MASK         (0xF00U)
#define VFCCU_0_FHFLTRKC0_1_RKNSEL5_SHIFT        (8U)
#define VFCCU_0_FHFLTRKC0_1_RKNSEL5_WIDTH        (4U)
#define VFCCU_0_FHFLTRKC0_1_RKNSEL5(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTRKC0_1_RKNSEL5_SHIFT)) & VFCCU_0_FHFLTRKC0_1_RKNSEL5_MASK)

#define VFCCU_0_FHFLTRKC0_1_RKNSEL6_MASK         (0xF0000U)
#define VFCCU_0_FHFLTRKC0_1_RKNSEL6_SHIFT        (16U)
#define VFCCU_0_FHFLTRKC0_1_RKNSEL6_WIDTH        (4U)
#define VFCCU_0_FHFLTRKC0_1_RKNSEL6(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTRKC0_1_RKNSEL6_SHIFT)) & VFCCU_0_FHFLTRKC0_1_RKNSEL6_MASK)

#define VFCCU_0_FHFLTRKC0_1_RKNSEL7_MASK         (0xF000000U)
#define VFCCU_0_FHFLTRKC0_1_RKNSEL7_SHIFT        (24U)
#define VFCCU_0_FHFLTRKC0_1_RKNSEL7_WIDTH        (4U)
#define VFCCU_0_FHFLTRKC0_1_RKNSEL7(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTRKC0_1_RKNSEL7_SHIFT)) & VFCCU_0_FHFLTRKC0_1_RKNSEL7_MASK)
/*! @} */

/*! @name FHFLTRKC0_2 - Fault Reaction Set Configuration */
/*! @{ */

#define VFCCU_0_FHFLTRKC0_2_RKNSEL8_MASK         (0xFU)
#define VFCCU_0_FHFLTRKC0_2_RKNSEL8_SHIFT        (0U)
#define VFCCU_0_FHFLTRKC0_2_RKNSEL8_WIDTH        (4U)
#define VFCCU_0_FHFLTRKC0_2_RKNSEL8(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTRKC0_2_RKNSEL8_SHIFT)) & VFCCU_0_FHFLTRKC0_2_RKNSEL8_MASK)

#define VFCCU_0_FHFLTRKC0_2_RKNSEL9_MASK         (0xF00U)
#define VFCCU_0_FHFLTRKC0_2_RKNSEL9_SHIFT        (8U)
#define VFCCU_0_FHFLTRKC0_2_RKNSEL9_WIDTH        (4U)
#define VFCCU_0_FHFLTRKC0_2_RKNSEL9(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTRKC0_2_RKNSEL9_SHIFT)) & VFCCU_0_FHFLTRKC0_2_RKNSEL9_MASK)

#define VFCCU_0_FHFLTRKC0_2_RKNSEL10_MASK        (0xF0000U)
#define VFCCU_0_FHFLTRKC0_2_RKNSEL10_SHIFT       (16U)
#define VFCCU_0_FHFLTRKC0_2_RKNSEL10_WIDTH       (4U)
#define VFCCU_0_FHFLTRKC0_2_RKNSEL10(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTRKC0_2_RKNSEL10_SHIFT)) & VFCCU_0_FHFLTRKC0_2_RKNSEL10_MASK)

#define VFCCU_0_FHFLTRKC0_2_RKNSEL11_MASK        (0xF000000U)
#define VFCCU_0_FHFLTRKC0_2_RKNSEL11_SHIFT       (24U)
#define VFCCU_0_FHFLTRKC0_2_RKNSEL11_WIDTH       (4U)
#define VFCCU_0_FHFLTRKC0_2_RKNSEL11(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTRKC0_2_RKNSEL11_SHIFT)) & VFCCU_0_FHFLTRKC0_2_RKNSEL11_MASK)
/*! @} */

/*! @name FHFLTRKC0_3 - Fault Reaction Set Configuration */
/*! @{ */

#define VFCCU_0_FHFLTRKC0_3_RKNSEL12_MASK        (0xFU)
#define VFCCU_0_FHFLTRKC0_3_RKNSEL12_SHIFT       (0U)
#define VFCCU_0_FHFLTRKC0_3_RKNSEL12_WIDTH       (4U)
#define VFCCU_0_FHFLTRKC0_3_RKNSEL12(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTRKC0_3_RKNSEL12_SHIFT)) & VFCCU_0_FHFLTRKC0_3_RKNSEL12_MASK)

#define VFCCU_0_FHFLTRKC0_3_RKNSEL13_MASK        (0xF00U)
#define VFCCU_0_FHFLTRKC0_3_RKNSEL13_SHIFT       (8U)
#define VFCCU_0_FHFLTRKC0_3_RKNSEL13_WIDTH       (4U)
#define VFCCU_0_FHFLTRKC0_3_RKNSEL13(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTRKC0_3_RKNSEL13_SHIFT)) & VFCCU_0_FHFLTRKC0_3_RKNSEL13_MASK)

#define VFCCU_0_FHFLTRKC0_3_RKNSEL14_MASK        (0xF0000U)
#define VFCCU_0_FHFLTRKC0_3_RKNSEL14_SHIFT       (16U)
#define VFCCU_0_FHFLTRKC0_3_RKNSEL14_WIDTH       (4U)
#define VFCCU_0_FHFLTRKC0_3_RKNSEL14(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTRKC0_3_RKNSEL14_SHIFT)) & VFCCU_0_FHFLTRKC0_3_RKNSEL14_MASK)

#define VFCCU_0_FHFLTRKC0_3_RKNSEL15_MASK        (0xF000000U)
#define VFCCU_0_FHFLTRKC0_3_RKNSEL15_SHIFT       (24U)
#define VFCCU_0_FHFLTRKC0_3_RKNSEL15_WIDTH       (4U)
#define VFCCU_0_FHFLTRKC0_3_RKNSEL15(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTRKC0_3_RKNSEL15_SHIFT)) & VFCCU_0_FHFLTRKC0_3_RKNSEL15_MASK)
/*! @} */

/*! @name FHFLTRKC0_4 - Fault Reaction Set Configuration */
/*! @{ */

#define VFCCU_0_FHFLTRKC0_4_RKNSEL16_MASK        (0xFU)
#define VFCCU_0_FHFLTRKC0_4_RKNSEL16_SHIFT       (0U)
#define VFCCU_0_FHFLTRKC0_4_RKNSEL16_WIDTH       (4U)
#define VFCCU_0_FHFLTRKC0_4_RKNSEL16(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTRKC0_4_RKNSEL16_SHIFT)) & VFCCU_0_FHFLTRKC0_4_RKNSEL16_MASK)

#define VFCCU_0_FHFLTRKC0_4_RKNSEL17_MASK        (0xF00U)
#define VFCCU_0_FHFLTRKC0_4_RKNSEL17_SHIFT       (8U)
#define VFCCU_0_FHFLTRKC0_4_RKNSEL17_WIDTH       (4U)
#define VFCCU_0_FHFLTRKC0_4_RKNSEL17(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTRKC0_4_RKNSEL17_SHIFT)) & VFCCU_0_FHFLTRKC0_4_RKNSEL17_MASK)

#define VFCCU_0_FHFLTRKC0_4_RKNSEL18_MASK        (0xF0000U)
#define VFCCU_0_FHFLTRKC0_4_RKNSEL18_SHIFT       (16U)
#define VFCCU_0_FHFLTRKC0_4_RKNSEL18_WIDTH       (4U)
#define VFCCU_0_FHFLTRKC0_4_RKNSEL18(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTRKC0_4_RKNSEL18_SHIFT)) & VFCCU_0_FHFLTRKC0_4_RKNSEL18_MASK)

#define VFCCU_0_FHFLTRKC0_4_RKNSEL19_MASK        (0xF000000U)
#define VFCCU_0_FHFLTRKC0_4_RKNSEL19_SHIFT       (24U)
#define VFCCU_0_FHFLTRKC0_4_RKNSEL19_WIDTH       (4U)
#define VFCCU_0_FHFLTRKC0_4_RKNSEL19(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTRKC0_4_RKNSEL19_SHIFT)) & VFCCU_0_FHFLTRKC0_4_RKNSEL19_MASK)
/*! @} */

/*! @name FHFLTRKC0_5 - Fault Reaction Set Configuration */
/*! @{ */

#define VFCCU_0_FHFLTRKC0_5_RKNSEL20_MASK        (0xFU)
#define VFCCU_0_FHFLTRKC0_5_RKNSEL20_SHIFT       (0U)
#define VFCCU_0_FHFLTRKC0_5_RKNSEL20_WIDTH       (4U)
#define VFCCU_0_FHFLTRKC0_5_RKNSEL20(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTRKC0_5_RKNSEL20_SHIFT)) & VFCCU_0_FHFLTRKC0_5_RKNSEL20_MASK)

#define VFCCU_0_FHFLTRKC0_5_RKNSEL21_MASK        (0xF00U)
#define VFCCU_0_FHFLTRKC0_5_RKNSEL21_SHIFT       (8U)
#define VFCCU_0_FHFLTRKC0_5_RKNSEL21_WIDTH       (4U)
#define VFCCU_0_FHFLTRKC0_5_RKNSEL21(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTRKC0_5_RKNSEL21_SHIFT)) & VFCCU_0_FHFLTRKC0_5_RKNSEL21_MASK)

#define VFCCU_0_FHFLTRKC0_5_RKNSEL22_MASK        (0xF0000U)
#define VFCCU_0_FHFLTRKC0_5_RKNSEL22_SHIFT       (16U)
#define VFCCU_0_FHFLTRKC0_5_RKNSEL22_WIDTH       (4U)
#define VFCCU_0_FHFLTRKC0_5_RKNSEL22(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTRKC0_5_RKNSEL22_SHIFT)) & VFCCU_0_FHFLTRKC0_5_RKNSEL22_MASK)

#define VFCCU_0_FHFLTRKC0_5_RKNSEL23_MASK        (0xF000000U)
#define VFCCU_0_FHFLTRKC0_5_RKNSEL23_SHIFT       (24U)
#define VFCCU_0_FHFLTRKC0_5_RKNSEL23_WIDTH       (4U)
#define VFCCU_0_FHFLTRKC0_5_RKNSEL23(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTRKC0_5_RKNSEL23_SHIFT)) & VFCCU_0_FHFLTRKC0_5_RKNSEL23_MASK)
/*! @} */

/*! @name FHFLTRKC0_6 - Fault Reaction Set Configuration */
/*! @{ */

#define VFCCU_0_FHFLTRKC0_6_RKNSEL24_MASK        (0xFU)
#define VFCCU_0_FHFLTRKC0_6_RKNSEL24_SHIFT       (0U)
#define VFCCU_0_FHFLTRKC0_6_RKNSEL24_WIDTH       (4U)
#define VFCCU_0_FHFLTRKC0_6_RKNSEL24(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTRKC0_6_RKNSEL24_SHIFT)) & VFCCU_0_FHFLTRKC0_6_RKNSEL24_MASK)

#define VFCCU_0_FHFLTRKC0_6_RKNSEL25_MASK        (0xF00U)
#define VFCCU_0_FHFLTRKC0_6_RKNSEL25_SHIFT       (8U)
#define VFCCU_0_FHFLTRKC0_6_RKNSEL25_WIDTH       (4U)
#define VFCCU_0_FHFLTRKC0_6_RKNSEL25(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTRKC0_6_RKNSEL25_SHIFT)) & VFCCU_0_FHFLTRKC0_6_RKNSEL25_MASK)

#define VFCCU_0_FHFLTRKC0_6_RKNSEL26_MASK        (0xF0000U)
#define VFCCU_0_FHFLTRKC0_6_RKNSEL26_SHIFT       (16U)
#define VFCCU_0_FHFLTRKC0_6_RKNSEL26_WIDTH       (4U)
#define VFCCU_0_FHFLTRKC0_6_RKNSEL26(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTRKC0_6_RKNSEL26_SHIFT)) & VFCCU_0_FHFLTRKC0_6_RKNSEL26_MASK)

#define VFCCU_0_FHFLTRKC0_6_RKNSEL27_MASK        (0xF000000U)
#define VFCCU_0_FHFLTRKC0_6_RKNSEL27_SHIFT       (24U)
#define VFCCU_0_FHFLTRKC0_6_RKNSEL27_WIDTH       (4U)
#define VFCCU_0_FHFLTRKC0_6_RKNSEL27(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTRKC0_6_RKNSEL27_SHIFT)) & VFCCU_0_FHFLTRKC0_6_RKNSEL27_MASK)
/*! @} */

/*! @name FHFLTRKC0_7 - Fault Reaction Set Configuration */
/*! @{ */

#define VFCCU_0_FHFLTRKC0_7_RKNSEL28_MASK        (0xFU)
#define VFCCU_0_FHFLTRKC0_7_RKNSEL28_SHIFT       (0U)
#define VFCCU_0_FHFLTRKC0_7_RKNSEL28_WIDTH       (4U)
#define VFCCU_0_FHFLTRKC0_7_RKNSEL28(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTRKC0_7_RKNSEL28_SHIFT)) & VFCCU_0_FHFLTRKC0_7_RKNSEL28_MASK)

#define VFCCU_0_FHFLTRKC0_7_RKNSEL29_MASK        (0xF00U)
#define VFCCU_0_FHFLTRKC0_7_RKNSEL29_SHIFT       (8U)
#define VFCCU_0_FHFLTRKC0_7_RKNSEL29_WIDTH       (4U)
#define VFCCU_0_FHFLTRKC0_7_RKNSEL29(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTRKC0_7_RKNSEL29_SHIFT)) & VFCCU_0_FHFLTRKC0_7_RKNSEL29_MASK)

#define VFCCU_0_FHFLTRKC0_7_RKNSEL30_MASK        (0xF0000U)
#define VFCCU_0_FHFLTRKC0_7_RKNSEL30_SHIFT       (16U)
#define VFCCU_0_FHFLTRKC0_7_RKNSEL30_WIDTH       (4U)
#define VFCCU_0_FHFLTRKC0_7_RKNSEL30(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTRKC0_7_RKNSEL30_SHIFT)) & VFCCU_0_FHFLTRKC0_7_RKNSEL30_MASK)

#define VFCCU_0_FHFLTRKC0_7_RKNSEL31_MASK        (0xF000000U)
#define VFCCU_0_FHFLTRKC0_7_RKNSEL31_SHIFT       (24U)
#define VFCCU_0_FHFLTRKC0_7_RKNSEL31_WIDTH       (4U)
#define VFCCU_0_FHFLTRKC0_7_RKNSEL31(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTRKC0_7_RKNSEL31_SHIFT)) & VFCCU_0_FHFLTRKC0_7_RKNSEL31_MASK)
/*! @} */

/*! @name FHFLTRKC0_8 - Fault Reaction Set Configuration */
/*! @{ */

#define VFCCU_0_FHFLTRKC0_8_RKNSEL32_MASK        (0xFU)
#define VFCCU_0_FHFLTRKC0_8_RKNSEL32_SHIFT       (0U)
#define VFCCU_0_FHFLTRKC0_8_RKNSEL32_WIDTH       (4U)
#define VFCCU_0_FHFLTRKC0_8_RKNSEL32(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTRKC0_8_RKNSEL32_SHIFT)) & VFCCU_0_FHFLTRKC0_8_RKNSEL32_MASK)

#define VFCCU_0_FHFLTRKC0_8_RKNSEL33_MASK        (0xF00U)
#define VFCCU_0_FHFLTRKC0_8_RKNSEL33_SHIFT       (8U)
#define VFCCU_0_FHFLTRKC0_8_RKNSEL33_WIDTH       (4U)
#define VFCCU_0_FHFLTRKC0_8_RKNSEL33(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTRKC0_8_RKNSEL33_SHIFT)) & VFCCU_0_FHFLTRKC0_8_RKNSEL33_MASK)

#define VFCCU_0_FHFLTRKC0_8_RKNSEL34_MASK        (0xF0000U)
#define VFCCU_0_FHFLTRKC0_8_RKNSEL34_SHIFT       (16U)
#define VFCCU_0_FHFLTRKC0_8_RKNSEL34_WIDTH       (4U)
#define VFCCU_0_FHFLTRKC0_8_RKNSEL34(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTRKC0_8_RKNSEL34_SHIFT)) & VFCCU_0_FHFLTRKC0_8_RKNSEL34_MASK)

#define VFCCU_0_FHFLTRKC0_8_RKNSEL35_MASK        (0xF000000U)
#define VFCCU_0_FHFLTRKC0_8_RKNSEL35_SHIFT       (24U)
#define VFCCU_0_FHFLTRKC0_8_RKNSEL35_WIDTH       (4U)
#define VFCCU_0_FHFLTRKC0_8_RKNSEL35(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTRKC0_8_RKNSEL35_SHIFT)) & VFCCU_0_FHFLTRKC0_8_RKNSEL35_MASK)
/*! @} */

/*! @name FHFLTRKC0_9 - Fault Reaction Set Configuration */
/*! @{ */

#define VFCCU_0_FHFLTRKC0_9_RKNSEL36_MASK        (0xFU)
#define VFCCU_0_FHFLTRKC0_9_RKNSEL36_SHIFT       (0U)
#define VFCCU_0_FHFLTRKC0_9_RKNSEL36_WIDTH       (4U)
#define VFCCU_0_FHFLTRKC0_9_RKNSEL36(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTRKC0_9_RKNSEL36_SHIFT)) & VFCCU_0_FHFLTRKC0_9_RKNSEL36_MASK)

#define VFCCU_0_FHFLTRKC0_9_RKNSEL37_MASK        (0xF00U)
#define VFCCU_0_FHFLTRKC0_9_RKNSEL37_SHIFT       (8U)
#define VFCCU_0_FHFLTRKC0_9_RKNSEL37_WIDTH       (4U)
#define VFCCU_0_FHFLTRKC0_9_RKNSEL37(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTRKC0_9_RKNSEL37_SHIFT)) & VFCCU_0_FHFLTRKC0_9_RKNSEL37_MASK)

#define VFCCU_0_FHFLTRKC0_9_RKNSEL38_MASK        (0xF0000U)
#define VFCCU_0_FHFLTRKC0_9_RKNSEL38_SHIFT       (16U)
#define VFCCU_0_FHFLTRKC0_9_RKNSEL38_WIDTH       (4U)
#define VFCCU_0_FHFLTRKC0_9_RKNSEL38(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTRKC0_9_RKNSEL38_SHIFT)) & VFCCU_0_FHFLTRKC0_9_RKNSEL38_MASK)

#define VFCCU_0_FHFLTRKC0_9_RKNSEL39_MASK        (0xF000000U)
#define VFCCU_0_FHFLTRKC0_9_RKNSEL39_SHIFT       (24U)
#define VFCCU_0_FHFLTRKC0_9_RKNSEL39_WIDTH       (4U)
#define VFCCU_0_FHFLTRKC0_9_RKNSEL39(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTRKC0_9_RKNSEL39_SHIFT)) & VFCCU_0_FHFLTRKC0_9_RKNSEL39_MASK)
/*! @} */

/*! @name FHFLTRKC0_10 - Fault Reaction Set Configuration */
/*! @{ */

#define VFCCU_0_FHFLTRKC0_10_RKNSEL40_MASK       (0xFU)
#define VFCCU_0_FHFLTRKC0_10_RKNSEL40_SHIFT      (0U)
#define VFCCU_0_FHFLTRKC0_10_RKNSEL40_WIDTH      (4U)
#define VFCCU_0_FHFLTRKC0_10_RKNSEL40(x)         (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTRKC0_10_RKNSEL40_SHIFT)) & VFCCU_0_FHFLTRKC0_10_RKNSEL40_MASK)

#define VFCCU_0_FHFLTRKC0_10_RKNSEL41_MASK       (0xF00U)
#define VFCCU_0_FHFLTRKC0_10_RKNSEL41_SHIFT      (8U)
#define VFCCU_0_FHFLTRKC0_10_RKNSEL41_WIDTH      (4U)
#define VFCCU_0_FHFLTRKC0_10_RKNSEL41(x)         (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTRKC0_10_RKNSEL41_SHIFT)) & VFCCU_0_FHFLTRKC0_10_RKNSEL41_MASK)

#define VFCCU_0_FHFLTRKC0_10_RKNSEL42_MASK       (0xF0000U)
#define VFCCU_0_FHFLTRKC0_10_RKNSEL42_SHIFT      (16U)
#define VFCCU_0_FHFLTRKC0_10_RKNSEL42_WIDTH      (4U)
#define VFCCU_0_FHFLTRKC0_10_RKNSEL42(x)         (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTRKC0_10_RKNSEL42_SHIFT)) & VFCCU_0_FHFLTRKC0_10_RKNSEL42_MASK)

#define VFCCU_0_FHFLTRKC0_10_RKNSEL43_MASK       (0xF000000U)
#define VFCCU_0_FHFLTRKC0_10_RKNSEL43_SHIFT      (24U)
#define VFCCU_0_FHFLTRKC0_10_RKNSEL43_WIDTH      (4U)
#define VFCCU_0_FHFLTRKC0_10_RKNSEL43(x)         (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTRKC0_10_RKNSEL43_SHIFT)) & VFCCU_0_FHFLTRKC0_10_RKNSEL43_MASK)
/*! @} */

/*! @name FHFLTRKC0_11 - Fault Reaction Set Configuration */
/*! @{ */

#define VFCCU_0_FHFLTRKC0_11_RKNSEL44_MASK       (0xFU)
#define VFCCU_0_FHFLTRKC0_11_RKNSEL44_SHIFT      (0U)
#define VFCCU_0_FHFLTRKC0_11_RKNSEL44_WIDTH      (4U)
#define VFCCU_0_FHFLTRKC0_11_RKNSEL44(x)         (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTRKC0_11_RKNSEL44_SHIFT)) & VFCCU_0_FHFLTRKC0_11_RKNSEL44_MASK)

#define VFCCU_0_FHFLTRKC0_11_RKNSEL45_MASK       (0xF00U)
#define VFCCU_0_FHFLTRKC0_11_RKNSEL45_SHIFT      (8U)
#define VFCCU_0_FHFLTRKC0_11_RKNSEL45_WIDTH      (4U)
#define VFCCU_0_FHFLTRKC0_11_RKNSEL45(x)         (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTRKC0_11_RKNSEL45_SHIFT)) & VFCCU_0_FHFLTRKC0_11_RKNSEL45_MASK)

#define VFCCU_0_FHFLTRKC0_11_RKNSEL46_MASK       (0xF0000U)
#define VFCCU_0_FHFLTRKC0_11_RKNSEL46_SHIFT      (16U)
#define VFCCU_0_FHFLTRKC0_11_RKNSEL46_WIDTH      (4U)
#define VFCCU_0_FHFLTRKC0_11_RKNSEL46(x)         (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTRKC0_11_RKNSEL46_SHIFT)) & VFCCU_0_FHFLTRKC0_11_RKNSEL46_MASK)

#define VFCCU_0_FHFLTRKC0_11_RKNSEL47_MASK       (0xF000000U)
#define VFCCU_0_FHFLTRKC0_11_RKNSEL47_SHIFT      (24U)
#define VFCCU_0_FHFLTRKC0_11_RKNSEL47_WIDTH      (4U)
#define VFCCU_0_FHFLTRKC0_11_RKNSEL47(x)         (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTRKC0_11_RKNSEL47_SHIFT)) & VFCCU_0_FHFLTRKC0_11_RKNSEL47_MASK)
/*! @} */

/*! @name FHFLTRKC0_12 - Fault Reaction Set Configuration */
/*! @{ */

#define VFCCU_0_FHFLTRKC0_12_RKNSEL48_MASK       (0xFU)
#define VFCCU_0_FHFLTRKC0_12_RKNSEL48_SHIFT      (0U)
#define VFCCU_0_FHFLTRKC0_12_RKNSEL48_WIDTH      (4U)
#define VFCCU_0_FHFLTRKC0_12_RKNSEL48(x)         (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTRKC0_12_RKNSEL48_SHIFT)) & VFCCU_0_FHFLTRKC0_12_RKNSEL48_MASK)

#define VFCCU_0_FHFLTRKC0_12_RKNSEL49_MASK       (0xF00U)
#define VFCCU_0_FHFLTRKC0_12_RKNSEL49_SHIFT      (8U)
#define VFCCU_0_FHFLTRKC0_12_RKNSEL49_WIDTH      (4U)
#define VFCCU_0_FHFLTRKC0_12_RKNSEL49(x)         (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTRKC0_12_RKNSEL49_SHIFT)) & VFCCU_0_FHFLTRKC0_12_RKNSEL49_MASK)

#define VFCCU_0_FHFLTRKC0_12_RKNSEL50_MASK       (0xF0000U)
#define VFCCU_0_FHFLTRKC0_12_RKNSEL50_SHIFT      (16U)
#define VFCCU_0_FHFLTRKC0_12_RKNSEL50_WIDTH      (4U)
#define VFCCU_0_FHFLTRKC0_12_RKNSEL50(x)         (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTRKC0_12_RKNSEL50_SHIFT)) & VFCCU_0_FHFLTRKC0_12_RKNSEL50_MASK)

#define VFCCU_0_FHFLTRKC0_12_RKNSEL51_MASK       (0xF000000U)
#define VFCCU_0_FHFLTRKC0_12_RKNSEL51_SHIFT      (24U)
#define VFCCU_0_FHFLTRKC0_12_RKNSEL51_WIDTH      (4U)
#define VFCCU_0_FHFLTRKC0_12_RKNSEL51(x)         (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTRKC0_12_RKNSEL51_SHIFT)) & VFCCU_0_FHFLTRKC0_12_RKNSEL51_MASK)
/*! @} */

/*! @name FHFLTRKC0_13 - Fault Reaction Set Configuration */
/*! @{ */

#define VFCCU_0_FHFLTRKC0_13_RKNSEL52_MASK       (0xFU)
#define VFCCU_0_FHFLTRKC0_13_RKNSEL52_SHIFT      (0U)
#define VFCCU_0_FHFLTRKC0_13_RKNSEL52_WIDTH      (4U)
#define VFCCU_0_FHFLTRKC0_13_RKNSEL52(x)         (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTRKC0_13_RKNSEL52_SHIFT)) & VFCCU_0_FHFLTRKC0_13_RKNSEL52_MASK)

#define VFCCU_0_FHFLTRKC0_13_RKNSEL53_MASK       (0xF00U)
#define VFCCU_0_FHFLTRKC0_13_RKNSEL53_SHIFT      (8U)
#define VFCCU_0_FHFLTRKC0_13_RKNSEL53_WIDTH      (4U)
#define VFCCU_0_FHFLTRKC0_13_RKNSEL53(x)         (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTRKC0_13_RKNSEL53_SHIFT)) & VFCCU_0_FHFLTRKC0_13_RKNSEL53_MASK)

#define VFCCU_0_FHFLTRKC0_13_RKNSEL54_MASK       (0xF0000U)
#define VFCCU_0_FHFLTRKC0_13_RKNSEL54_SHIFT      (16U)
#define VFCCU_0_FHFLTRKC0_13_RKNSEL54_WIDTH      (4U)
#define VFCCU_0_FHFLTRKC0_13_RKNSEL54(x)         (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTRKC0_13_RKNSEL54_SHIFT)) & VFCCU_0_FHFLTRKC0_13_RKNSEL54_MASK)

#define VFCCU_0_FHFLTRKC0_13_RKNSEL55_MASK       (0xF000000U)
#define VFCCU_0_FHFLTRKC0_13_RKNSEL55_SHIFT      (24U)
#define VFCCU_0_FHFLTRKC0_13_RKNSEL55_WIDTH      (4U)
#define VFCCU_0_FHFLTRKC0_13_RKNSEL55(x)         (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTRKC0_13_RKNSEL55_SHIFT)) & VFCCU_0_FHFLTRKC0_13_RKNSEL55_MASK)
/*! @} */

/*! @name FHFLTRKC0_14 - Fault Reaction Set Configuration */
/*! @{ */

#define VFCCU_0_FHFLTRKC0_14_RKNSEL56_MASK       (0xFU)
#define VFCCU_0_FHFLTRKC0_14_RKNSEL56_SHIFT      (0U)
#define VFCCU_0_FHFLTRKC0_14_RKNSEL56_WIDTH      (4U)
#define VFCCU_0_FHFLTRKC0_14_RKNSEL56(x)         (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTRKC0_14_RKNSEL56_SHIFT)) & VFCCU_0_FHFLTRKC0_14_RKNSEL56_MASK)

#define VFCCU_0_FHFLTRKC0_14_RKNSEL57_MASK       (0xF00U)
#define VFCCU_0_FHFLTRKC0_14_RKNSEL57_SHIFT      (8U)
#define VFCCU_0_FHFLTRKC0_14_RKNSEL57_WIDTH      (4U)
#define VFCCU_0_FHFLTRKC0_14_RKNSEL57(x)         (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTRKC0_14_RKNSEL57_SHIFT)) & VFCCU_0_FHFLTRKC0_14_RKNSEL57_MASK)

#define VFCCU_0_FHFLTRKC0_14_RKNSEL58_MASK       (0xF0000U)
#define VFCCU_0_FHFLTRKC0_14_RKNSEL58_SHIFT      (16U)
#define VFCCU_0_FHFLTRKC0_14_RKNSEL58_WIDTH      (4U)
#define VFCCU_0_FHFLTRKC0_14_RKNSEL58(x)         (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTRKC0_14_RKNSEL58_SHIFT)) & VFCCU_0_FHFLTRKC0_14_RKNSEL58_MASK)

#define VFCCU_0_FHFLTRKC0_14_RKNSEL59_MASK       (0xF000000U)
#define VFCCU_0_FHFLTRKC0_14_RKNSEL59_SHIFT      (24U)
#define VFCCU_0_FHFLTRKC0_14_RKNSEL59_WIDTH      (4U)
#define VFCCU_0_FHFLTRKC0_14_RKNSEL59(x)         (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTRKC0_14_RKNSEL59_SHIFT)) & VFCCU_0_FHFLTRKC0_14_RKNSEL59_MASK)
/*! @} */

/*! @name FHFLTRKC0_15 - Fault Reaction Set Configuration */
/*! @{ */

#define VFCCU_0_FHFLTRKC0_15_RKNSEL60_MASK       (0xFU)
#define VFCCU_0_FHFLTRKC0_15_RKNSEL60_SHIFT      (0U)
#define VFCCU_0_FHFLTRKC0_15_RKNSEL60_WIDTH      (4U)
#define VFCCU_0_FHFLTRKC0_15_RKNSEL60(x)         (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTRKC0_15_RKNSEL60_SHIFT)) & VFCCU_0_FHFLTRKC0_15_RKNSEL60_MASK)

#define VFCCU_0_FHFLTRKC0_15_RKNSEL61_MASK       (0xF00U)
#define VFCCU_0_FHFLTRKC0_15_RKNSEL61_SHIFT      (8U)
#define VFCCU_0_FHFLTRKC0_15_RKNSEL61_WIDTH      (4U)
#define VFCCU_0_FHFLTRKC0_15_RKNSEL61(x)         (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTRKC0_15_RKNSEL61_SHIFT)) & VFCCU_0_FHFLTRKC0_15_RKNSEL61_MASK)

#define VFCCU_0_FHFLTRKC0_15_RKNSEL62_MASK       (0xF0000U)
#define VFCCU_0_FHFLTRKC0_15_RKNSEL62_SHIFT      (16U)
#define VFCCU_0_FHFLTRKC0_15_RKNSEL62_WIDTH      (4U)
#define VFCCU_0_FHFLTRKC0_15_RKNSEL62(x)         (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTRKC0_15_RKNSEL62_SHIFT)) & VFCCU_0_FHFLTRKC0_15_RKNSEL62_MASK)

#define VFCCU_0_FHFLTRKC0_15_RKNSEL63_MASK       (0xF000000U)
#define VFCCU_0_FHFLTRKC0_15_RKNSEL63_SHIFT      (24U)
#define VFCCU_0_FHFLTRKC0_15_RKNSEL63_WIDTH      (4U)
#define VFCCU_0_FHFLTRKC0_15_RKNSEL63(x)         (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHFLTRKC0_15_RKNSEL63_SHIFT)) & VFCCU_0_FHFLTRKC0_15_RKNSEL63_MASK)
/*! @} */

/*! @name FHIMRKC0_00 - Immediate Reaction Configuration */
/*! @{ */

#define VFCCU_0_FHIMRKC0_00_EOUTEN0_MASK         (0x1U)
#define VFCCU_0_FHIMRKC0_00_EOUTEN0_SHIFT        (0U)
#define VFCCU_0_FHIMRKC0_00_EOUTEN0_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_00_EOUTEN0(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_00_EOUTEN0_SHIFT)) & VFCCU_0_FHIMRKC0_00_EOUTEN0_MASK)

#define VFCCU_0_FHIMRKC0_00_EOUTEN1_MASK         (0x2U)
#define VFCCU_0_FHIMRKC0_00_EOUTEN1_SHIFT        (1U)
#define VFCCU_0_FHIMRKC0_00_EOUTEN1_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_00_EOUTEN1(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_00_EOUTEN1_SHIFT)) & VFCCU_0_FHIMRKC0_00_EOUTEN1_MASK)

#define VFCCU_0_FHIMRKC0_00_RKNEN0_MASK          (0x4U)
#define VFCCU_0_FHIMRKC0_00_RKNEN0_SHIFT         (2U)
#define VFCCU_0_FHIMRKC0_00_RKNEN0_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_00_RKNEN0(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_00_RKNEN0_SHIFT)) & VFCCU_0_FHIMRKC0_00_RKNEN0_MASK)

#define VFCCU_0_FHIMRKC0_00_RKNEN1_MASK          (0x8U)
#define VFCCU_0_FHIMRKC0_00_RKNEN1_SHIFT         (3U)
#define VFCCU_0_FHIMRKC0_00_RKNEN1_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_00_RKNEN1(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_00_RKNEN1_SHIFT)) & VFCCU_0_FHIMRKC0_00_RKNEN1_MASK)

#define VFCCU_0_FHIMRKC0_00_RKNEN2_MASK          (0x10U)
#define VFCCU_0_FHIMRKC0_00_RKNEN2_SHIFT         (4U)
#define VFCCU_0_FHIMRKC0_00_RKNEN2_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_00_RKNEN2(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_00_RKNEN2_SHIFT)) & VFCCU_0_FHIMRKC0_00_RKNEN2_MASK)

#define VFCCU_0_FHIMRKC0_00_RKNEN3_MASK          (0x20U)
#define VFCCU_0_FHIMRKC0_00_RKNEN3_SHIFT         (5U)
#define VFCCU_0_FHIMRKC0_00_RKNEN3_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_00_RKNEN3(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_00_RKNEN3_SHIFT)) & VFCCU_0_FHIMRKC0_00_RKNEN3_MASK)

#define VFCCU_0_FHIMRKC0_00_RKNEN4_MASK          (0x40U)
#define VFCCU_0_FHIMRKC0_00_RKNEN4_SHIFT         (6U)
#define VFCCU_0_FHIMRKC0_00_RKNEN4_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_00_RKNEN4(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_00_RKNEN4_SHIFT)) & VFCCU_0_FHIMRKC0_00_RKNEN4_MASK)

#define VFCCU_0_FHIMRKC0_00_RKNEN5_MASK          (0x80U)
#define VFCCU_0_FHIMRKC0_00_RKNEN5_SHIFT         (7U)
#define VFCCU_0_FHIMRKC0_00_RKNEN5_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_00_RKNEN5(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_00_RKNEN5_SHIFT)) & VFCCU_0_FHIMRKC0_00_RKNEN5_MASK)

#define VFCCU_0_FHIMRKC0_00_RKNEN6_MASK          (0x100U)
#define VFCCU_0_FHIMRKC0_00_RKNEN6_SHIFT         (8U)
#define VFCCU_0_FHIMRKC0_00_RKNEN6_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_00_RKNEN6(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_00_RKNEN6_SHIFT)) & VFCCU_0_FHIMRKC0_00_RKNEN6_MASK)

#define VFCCU_0_FHIMRKC0_00_RKNEN7_MASK          (0x200U)
#define VFCCU_0_FHIMRKC0_00_RKNEN7_SHIFT         (9U)
#define VFCCU_0_FHIMRKC0_00_RKNEN7_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_00_RKNEN7(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_00_RKNEN7_SHIFT)) & VFCCU_0_FHIMRKC0_00_RKNEN7_MASK)

#define VFCCU_0_FHIMRKC0_00_RKNEN8_MASK          (0x400U)
#define VFCCU_0_FHIMRKC0_00_RKNEN8_SHIFT         (10U)
#define VFCCU_0_FHIMRKC0_00_RKNEN8_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_00_RKNEN8(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_00_RKNEN8_SHIFT)) & VFCCU_0_FHIMRKC0_00_RKNEN8_MASK)

#define VFCCU_0_FHIMRKC0_00_RKNEN9_MASK          (0x800U)
#define VFCCU_0_FHIMRKC0_00_RKNEN9_SHIFT         (11U)
#define VFCCU_0_FHIMRKC0_00_RKNEN9_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_00_RKNEN9(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_00_RKNEN9_SHIFT)) & VFCCU_0_FHIMRKC0_00_RKNEN9_MASK)

#define VFCCU_0_FHIMRKC0_00_RKNEN10_MASK         (0x1000U)
#define VFCCU_0_FHIMRKC0_00_RKNEN10_SHIFT        (12U)
#define VFCCU_0_FHIMRKC0_00_RKNEN10_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_00_RKNEN10(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_00_RKNEN10_SHIFT)) & VFCCU_0_FHIMRKC0_00_RKNEN10_MASK)

#define VFCCU_0_FHIMRKC0_00_RKNEN11_MASK         (0x2000U)
#define VFCCU_0_FHIMRKC0_00_RKNEN11_SHIFT        (13U)
#define VFCCU_0_FHIMRKC0_00_RKNEN11_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_00_RKNEN11(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_00_RKNEN11_SHIFT)) & VFCCU_0_FHIMRKC0_00_RKNEN11_MASK)

#define VFCCU_0_FHIMRKC0_00_RKNEN12_MASK         (0x4000U)
#define VFCCU_0_FHIMRKC0_00_RKNEN12_SHIFT        (14U)
#define VFCCU_0_FHIMRKC0_00_RKNEN12_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_00_RKNEN12(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_00_RKNEN12_SHIFT)) & VFCCU_0_FHIMRKC0_00_RKNEN12_MASK)

#define VFCCU_0_FHIMRKC0_00_RKNEN13_MASK         (0x8000U)
#define VFCCU_0_FHIMRKC0_00_RKNEN13_SHIFT        (15U)
#define VFCCU_0_FHIMRKC0_00_RKNEN13_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_00_RKNEN13(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_00_RKNEN13_SHIFT)) & VFCCU_0_FHIMRKC0_00_RKNEN13_MASK)

#define VFCCU_0_FHIMRKC0_00_RKNEN14_MASK         (0x10000U)
#define VFCCU_0_FHIMRKC0_00_RKNEN14_SHIFT        (16U)
#define VFCCU_0_FHIMRKC0_00_RKNEN14_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_00_RKNEN14(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_00_RKNEN14_SHIFT)) & VFCCU_0_FHIMRKC0_00_RKNEN14_MASK)

#define VFCCU_0_FHIMRKC0_00_RKNEN15_MASK         (0x20000U)
#define VFCCU_0_FHIMRKC0_00_RKNEN15_SHIFT        (17U)
#define VFCCU_0_FHIMRKC0_00_RKNEN15_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_00_RKNEN15(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_00_RKNEN15_SHIFT)) & VFCCU_0_FHIMRKC0_00_RKNEN15_MASK)

#define VFCCU_0_FHIMRKC0_00_RKNEN16_MASK         (0x40000U)
#define VFCCU_0_FHIMRKC0_00_RKNEN16_SHIFT        (18U)
#define VFCCU_0_FHIMRKC0_00_RKNEN16_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_00_RKNEN16(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_00_RKNEN16_SHIFT)) & VFCCU_0_FHIMRKC0_00_RKNEN16_MASK)

#define VFCCU_0_FHIMRKC0_00_RKNEN17_MASK         (0x80000U)
#define VFCCU_0_FHIMRKC0_00_RKNEN17_SHIFT        (19U)
#define VFCCU_0_FHIMRKC0_00_RKNEN17_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_00_RKNEN17(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_00_RKNEN17_SHIFT)) & VFCCU_0_FHIMRKC0_00_RKNEN17_MASK)

#define VFCCU_0_FHIMRKC0_00_RKNEN18_MASK         (0x100000U)
#define VFCCU_0_FHIMRKC0_00_RKNEN18_SHIFT        (20U)
#define VFCCU_0_FHIMRKC0_00_RKNEN18_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_00_RKNEN18(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_00_RKNEN18_SHIFT)) & VFCCU_0_FHIMRKC0_00_RKNEN18_MASK)

#define VFCCU_0_FHIMRKC0_00_RKNEN19_MASK         (0x200000U)
#define VFCCU_0_FHIMRKC0_00_RKNEN19_SHIFT        (21U)
#define VFCCU_0_FHIMRKC0_00_RKNEN19_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_00_RKNEN19(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_00_RKNEN19_SHIFT)) & VFCCU_0_FHIMRKC0_00_RKNEN19_MASK)

#define VFCCU_0_FHIMRKC0_00_RKNEN20_MASK         (0x400000U)
#define VFCCU_0_FHIMRKC0_00_RKNEN20_SHIFT        (22U)
#define VFCCU_0_FHIMRKC0_00_RKNEN20_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_00_RKNEN20(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_00_RKNEN20_SHIFT)) & VFCCU_0_FHIMRKC0_00_RKNEN20_MASK)

#define VFCCU_0_FHIMRKC0_00_RKNEN21_MASK         (0x800000U)
#define VFCCU_0_FHIMRKC0_00_RKNEN21_SHIFT        (23U)
#define VFCCU_0_FHIMRKC0_00_RKNEN21_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_00_RKNEN21(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_00_RKNEN21_SHIFT)) & VFCCU_0_FHIMRKC0_00_RKNEN21_MASK)

#define VFCCU_0_FHIMRKC0_00_RKNEN22_MASK         (0x1000000U)
#define VFCCU_0_FHIMRKC0_00_RKNEN22_SHIFT        (24U)
#define VFCCU_0_FHIMRKC0_00_RKNEN22_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_00_RKNEN22(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_00_RKNEN22_SHIFT)) & VFCCU_0_FHIMRKC0_00_RKNEN22_MASK)

#define VFCCU_0_FHIMRKC0_00_RKNEN23_MASK         (0x2000000U)
#define VFCCU_0_FHIMRKC0_00_RKNEN23_SHIFT        (25U)
#define VFCCU_0_FHIMRKC0_00_RKNEN23_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_00_RKNEN23(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_00_RKNEN23_SHIFT)) & VFCCU_0_FHIMRKC0_00_RKNEN23_MASK)

#define VFCCU_0_FHIMRKC0_00_RKNEN24_MASK         (0x4000000U)
#define VFCCU_0_FHIMRKC0_00_RKNEN24_SHIFT        (26U)
#define VFCCU_0_FHIMRKC0_00_RKNEN24_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_00_RKNEN24(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_00_RKNEN24_SHIFT)) & VFCCU_0_FHIMRKC0_00_RKNEN24_MASK)

#define VFCCU_0_FHIMRKC0_00_RKNEN25_MASK         (0x8000000U)
#define VFCCU_0_FHIMRKC0_00_RKNEN25_SHIFT        (27U)
#define VFCCU_0_FHIMRKC0_00_RKNEN25_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_00_RKNEN25(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_00_RKNEN25_SHIFT)) & VFCCU_0_FHIMRKC0_00_RKNEN25_MASK)

#define VFCCU_0_FHIMRKC0_00_RKNEN26_MASK         (0x10000000U)
#define VFCCU_0_FHIMRKC0_00_RKNEN26_SHIFT        (28U)
#define VFCCU_0_FHIMRKC0_00_RKNEN26_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_00_RKNEN26(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_00_RKNEN26_SHIFT)) & VFCCU_0_FHIMRKC0_00_RKNEN26_MASK)

#define VFCCU_0_FHIMRKC0_00_RKNEN27_MASK         (0x20000000U)
#define VFCCU_0_FHIMRKC0_00_RKNEN27_SHIFT        (29U)
#define VFCCU_0_FHIMRKC0_00_RKNEN27_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_00_RKNEN27(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_00_RKNEN27_SHIFT)) & VFCCU_0_FHIMRKC0_00_RKNEN27_MASK)

#define VFCCU_0_FHIMRKC0_00_RKNEN28_MASK         (0x40000000U)
#define VFCCU_0_FHIMRKC0_00_RKNEN28_SHIFT        (30U)
#define VFCCU_0_FHIMRKC0_00_RKNEN28_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_00_RKNEN28(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_00_RKNEN28_SHIFT)) & VFCCU_0_FHIMRKC0_00_RKNEN28_MASK)

#define VFCCU_0_FHIMRKC0_00_RKNEN29_MASK         (0x80000000U)
#define VFCCU_0_FHIMRKC0_00_RKNEN29_SHIFT        (31U)
#define VFCCU_0_FHIMRKC0_00_RKNEN29_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_00_RKNEN29(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_00_RKNEN29_SHIFT)) & VFCCU_0_FHIMRKC0_00_RKNEN29_MASK)
/*! @} */

/*! @name FHDLRKC0_00 - Delayed Reaction Configuration */
/*! @{ */

#define VFCCU_0_FHDLRKC0_00_EOUTEN0_MASK         (0x1U)
#define VFCCU_0_FHDLRKC0_00_EOUTEN0_SHIFT        (0U)
#define VFCCU_0_FHDLRKC0_00_EOUTEN0_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_00_EOUTEN0(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_00_EOUTEN0_SHIFT)) & VFCCU_0_FHDLRKC0_00_EOUTEN0_MASK)

#define VFCCU_0_FHDLRKC0_00_EOUTEN1_MASK         (0x2U)
#define VFCCU_0_FHDLRKC0_00_EOUTEN1_SHIFT        (1U)
#define VFCCU_0_FHDLRKC0_00_EOUTEN1_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_00_EOUTEN1(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_00_EOUTEN1_SHIFT)) & VFCCU_0_FHDLRKC0_00_EOUTEN1_MASK)

#define VFCCU_0_FHDLRKC0_00_RKNEN0_MASK          (0x4U)
#define VFCCU_0_FHDLRKC0_00_RKNEN0_SHIFT         (2U)
#define VFCCU_0_FHDLRKC0_00_RKNEN0_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_00_RKNEN0(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_00_RKNEN0_SHIFT)) & VFCCU_0_FHDLRKC0_00_RKNEN0_MASK)

#define VFCCU_0_FHDLRKC0_00_RKNEN1_MASK          (0x8U)
#define VFCCU_0_FHDLRKC0_00_RKNEN1_SHIFT         (3U)
#define VFCCU_0_FHDLRKC0_00_RKNEN1_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_00_RKNEN1(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_00_RKNEN1_SHIFT)) & VFCCU_0_FHDLRKC0_00_RKNEN1_MASK)

#define VFCCU_0_FHDLRKC0_00_RKNEN2_MASK          (0x10U)
#define VFCCU_0_FHDLRKC0_00_RKNEN2_SHIFT         (4U)
#define VFCCU_0_FHDLRKC0_00_RKNEN2_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_00_RKNEN2(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_00_RKNEN2_SHIFT)) & VFCCU_0_FHDLRKC0_00_RKNEN2_MASK)

#define VFCCU_0_FHDLRKC0_00_RKNEN3_MASK          (0x20U)
#define VFCCU_0_FHDLRKC0_00_RKNEN3_SHIFT         (5U)
#define VFCCU_0_FHDLRKC0_00_RKNEN3_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_00_RKNEN3(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_00_RKNEN3_SHIFT)) & VFCCU_0_FHDLRKC0_00_RKNEN3_MASK)

#define VFCCU_0_FHDLRKC0_00_RKNEN4_MASK          (0x40U)
#define VFCCU_0_FHDLRKC0_00_RKNEN4_SHIFT         (6U)
#define VFCCU_0_FHDLRKC0_00_RKNEN4_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_00_RKNEN4(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_00_RKNEN4_SHIFT)) & VFCCU_0_FHDLRKC0_00_RKNEN4_MASK)

#define VFCCU_0_FHDLRKC0_00_RKNEN5_MASK          (0x80U)
#define VFCCU_0_FHDLRKC0_00_RKNEN5_SHIFT         (7U)
#define VFCCU_0_FHDLRKC0_00_RKNEN5_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_00_RKNEN5(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_00_RKNEN5_SHIFT)) & VFCCU_0_FHDLRKC0_00_RKNEN5_MASK)

#define VFCCU_0_FHDLRKC0_00_RKNEN6_MASK          (0x100U)
#define VFCCU_0_FHDLRKC0_00_RKNEN6_SHIFT         (8U)
#define VFCCU_0_FHDLRKC0_00_RKNEN6_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_00_RKNEN6(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_00_RKNEN6_SHIFT)) & VFCCU_0_FHDLRKC0_00_RKNEN6_MASK)

#define VFCCU_0_FHDLRKC0_00_RKNEN7_MASK          (0x200U)
#define VFCCU_0_FHDLRKC0_00_RKNEN7_SHIFT         (9U)
#define VFCCU_0_FHDLRKC0_00_RKNEN7_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_00_RKNEN7(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_00_RKNEN7_SHIFT)) & VFCCU_0_FHDLRKC0_00_RKNEN7_MASK)

#define VFCCU_0_FHDLRKC0_00_RKNEN8_MASK          (0x400U)
#define VFCCU_0_FHDLRKC0_00_RKNEN8_SHIFT         (10U)
#define VFCCU_0_FHDLRKC0_00_RKNEN8_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_00_RKNEN8(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_00_RKNEN8_SHIFT)) & VFCCU_0_FHDLRKC0_00_RKNEN8_MASK)

#define VFCCU_0_FHDLRKC0_00_RKNEN9_MASK          (0x800U)
#define VFCCU_0_FHDLRKC0_00_RKNEN9_SHIFT         (11U)
#define VFCCU_0_FHDLRKC0_00_RKNEN9_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_00_RKNEN9(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_00_RKNEN9_SHIFT)) & VFCCU_0_FHDLRKC0_00_RKNEN9_MASK)

#define VFCCU_0_FHDLRKC0_00_RKNEN10_MASK         (0x1000U)
#define VFCCU_0_FHDLRKC0_00_RKNEN10_SHIFT        (12U)
#define VFCCU_0_FHDLRKC0_00_RKNEN10_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_00_RKNEN10(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_00_RKNEN10_SHIFT)) & VFCCU_0_FHDLRKC0_00_RKNEN10_MASK)

#define VFCCU_0_FHDLRKC0_00_RKNEN11_MASK         (0x2000U)
#define VFCCU_0_FHDLRKC0_00_RKNEN11_SHIFT        (13U)
#define VFCCU_0_FHDLRKC0_00_RKNEN11_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_00_RKNEN11(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_00_RKNEN11_SHIFT)) & VFCCU_0_FHDLRKC0_00_RKNEN11_MASK)

#define VFCCU_0_FHDLRKC0_00_RKNEN12_MASK         (0x4000U)
#define VFCCU_0_FHDLRKC0_00_RKNEN12_SHIFT        (14U)
#define VFCCU_0_FHDLRKC0_00_RKNEN12_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_00_RKNEN12(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_00_RKNEN12_SHIFT)) & VFCCU_0_FHDLRKC0_00_RKNEN12_MASK)

#define VFCCU_0_FHDLRKC0_00_RKNEN13_MASK         (0x8000U)
#define VFCCU_0_FHDLRKC0_00_RKNEN13_SHIFT        (15U)
#define VFCCU_0_FHDLRKC0_00_RKNEN13_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_00_RKNEN13(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_00_RKNEN13_SHIFT)) & VFCCU_0_FHDLRKC0_00_RKNEN13_MASK)

#define VFCCU_0_FHDLRKC0_00_RKNEN14_MASK         (0x10000U)
#define VFCCU_0_FHDLRKC0_00_RKNEN14_SHIFT        (16U)
#define VFCCU_0_FHDLRKC0_00_RKNEN14_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_00_RKNEN14(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_00_RKNEN14_SHIFT)) & VFCCU_0_FHDLRKC0_00_RKNEN14_MASK)

#define VFCCU_0_FHDLRKC0_00_RKNEN15_MASK         (0x20000U)
#define VFCCU_0_FHDLRKC0_00_RKNEN15_SHIFT        (17U)
#define VFCCU_0_FHDLRKC0_00_RKNEN15_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_00_RKNEN15(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_00_RKNEN15_SHIFT)) & VFCCU_0_FHDLRKC0_00_RKNEN15_MASK)

#define VFCCU_0_FHDLRKC0_00_RKNEN16_MASK         (0x40000U)
#define VFCCU_0_FHDLRKC0_00_RKNEN16_SHIFT        (18U)
#define VFCCU_0_FHDLRKC0_00_RKNEN16_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_00_RKNEN16(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_00_RKNEN16_SHIFT)) & VFCCU_0_FHDLRKC0_00_RKNEN16_MASK)

#define VFCCU_0_FHDLRKC0_00_RKNEN17_MASK         (0x80000U)
#define VFCCU_0_FHDLRKC0_00_RKNEN17_SHIFT        (19U)
#define VFCCU_0_FHDLRKC0_00_RKNEN17_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_00_RKNEN17(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_00_RKNEN17_SHIFT)) & VFCCU_0_FHDLRKC0_00_RKNEN17_MASK)

#define VFCCU_0_FHDLRKC0_00_RKNEN18_MASK         (0x100000U)
#define VFCCU_0_FHDLRKC0_00_RKNEN18_SHIFT        (20U)
#define VFCCU_0_FHDLRKC0_00_RKNEN18_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_00_RKNEN18(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_00_RKNEN18_SHIFT)) & VFCCU_0_FHDLRKC0_00_RKNEN18_MASK)

#define VFCCU_0_FHDLRKC0_00_RKNEN19_MASK         (0x200000U)
#define VFCCU_0_FHDLRKC0_00_RKNEN19_SHIFT        (21U)
#define VFCCU_0_FHDLRKC0_00_RKNEN19_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_00_RKNEN19(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_00_RKNEN19_SHIFT)) & VFCCU_0_FHDLRKC0_00_RKNEN19_MASK)

#define VFCCU_0_FHDLRKC0_00_RKNEN20_MASK         (0x400000U)
#define VFCCU_0_FHDLRKC0_00_RKNEN20_SHIFT        (22U)
#define VFCCU_0_FHDLRKC0_00_RKNEN20_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_00_RKNEN20(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_00_RKNEN20_SHIFT)) & VFCCU_0_FHDLRKC0_00_RKNEN20_MASK)

#define VFCCU_0_FHDLRKC0_00_RKNEN21_MASK         (0x800000U)
#define VFCCU_0_FHDLRKC0_00_RKNEN21_SHIFT        (23U)
#define VFCCU_0_FHDLRKC0_00_RKNEN21_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_00_RKNEN21(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_00_RKNEN21_SHIFT)) & VFCCU_0_FHDLRKC0_00_RKNEN21_MASK)

#define VFCCU_0_FHDLRKC0_00_RKNEN22_MASK         (0x1000000U)
#define VFCCU_0_FHDLRKC0_00_RKNEN22_SHIFT        (24U)
#define VFCCU_0_FHDLRKC0_00_RKNEN22_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_00_RKNEN22(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_00_RKNEN22_SHIFT)) & VFCCU_0_FHDLRKC0_00_RKNEN22_MASK)

#define VFCCU_0_FHDLRKC0_00_RKNEN23_MASK         (0x2000000U)
#define VFCCU_0_FHDLRKC0_00_RKNEN23_SHIFT        (25U)
#define VFCCU_0_FHDLRKC0_00_RKNEN23_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_00_RKNEN23(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_00_RKNEN23_SHIFT)) & VFCCU_0_FHDLRKC0_00_RKNEN23_MASK)

#define VFCCU_0_FHDLRKC0_00_RKNEN24_MASK         (0x4000000U)
#define VFCCU_0_FHDLRKC0_00_RKNEN24_SHIFT        (26U)
#define VFCCU_0_FHDLRKC0_00_RKNEN24_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_00_RKNEN24(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_00_RKNEN24_SHIFT)) & VFCCU_0_FHDLRKC0_00_RKNEN24_MASK)

#define VFCCU_0_FHDLRKC0_00_RKNEN25_MASK         (0x8000000U)
#define VFCCU_0_FHDLRKC0_00_RKNEN25_SHIFT        (27U)
#define VFCCU_0_FHDLRKC0_00_RKNEN25_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_00_RKNEN25(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_00_RKNEN25_SHIFT)) & VFCCU_0_FHDLRKC0_00_RKNEN25_MASK)

#define VFCCU_0_FHDLRKC0_00_RKNEN26_MASK         (0x10000000U)
#define VFCCU_0_FHDLRKC0_00_RKNEN26_SHIFT        (28U)
#define VFCCU_0_FHDLRKC0_00_RKNEN26_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_00_RKNEN26(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_00_RKNEN26_SHIFT)) & VFCCU_0_FHDLRKC0_00_RKNEN26_MASK)

#define VFCCU_0_FHDLRKC0_00_RKNEN27_MASK         (0x20000000U)
#define VFCCU_0_FHDLRKC0_00_RKNEN27_SHIFT        (29U)
#define VFCCU_0_FHDLRKC0_00_RKNEN27_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_00_RKNEN27(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_00_RKNEN27_SHIFT)) & VFCCU_0_FHDLRKC0_00_RKNEN27_MASK)

#define VFCCU_0_FHDLRKC0_00_RKNEN28_MASK         (0x40000000U)
#define VFCCU_0_FHDLRKC0_00_RKNEN28_SHIFT        (30U)
#define VFCCU_0_FHDLRKC0_00_RKNEN28_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_00_RKNEN28(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_00_RKNEN28_SHIFT)) & VFCCU_0_FHDLRKC0_00_RKNEN28_MASK)

#define VFCCU_0_FHDLRKC0_00_RKNEN29_MASK         (0x80000000U)
#define VFCCU_0_FHDLRKC0_00_RKNEN29_SHIFT        (31U)
#define VFCCU_0_FHDLRKC0_00_RKNEN29_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_00_RKNEN29(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_00_RKNEN29_SHIFT)) & VFCCU_0_FHDLRKC0_00_RKNEN29_MASK)
/*! @} */

/*! @name FHIMRKC0_10 - Immediate Reaction Configuration */
/*! @{ */

#define VFCCU_0_FHIMRKC0_10_EOUTEN0_MASK         (0x1U)
#define VFCCU_0_FHIMRKC0_10_EOUTEN0_SHIFT        (0U)
#define VFCCU_0_FHIMRKC0_10_EOUTEN0_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_10_EOUTEN0(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_10_EOUTEN0_SHIFT)) & VFCCU_0_FHIMRKC0_10_EOUTEN0_MASK)

#define VFCCU_0_FHIMRKC0_10_EOUTEN1_MASK         (0x2U)
#define VFCCU_0_FHIMRKC0_10_EOUTEN1_SHIFT        (1U)
#define VFCCU_0_FHIMRKC0_10_EOUTEN1_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_10_EOUTEN1(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_10_EOUTEN1_SHIFT)) & VFCCU_0_FHIMRKC0_10_EOUTEN1_MASK)

#define VFCCU_0_FHIMRKC0_10_RKNEN0_MASK          (0x4U)
#define VFCCU_0_FHIMRKC0_10_RKNEN0_SHIFT         (2U)
#define VFCCU_0_FHIMRKC0_10_RKNEN0_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_10_RKNEN0(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_10_RKNEN0_SHIFT)) & VFCCU_0_FHIMRKC0_10_RKNEN0_MASK)

#define VFCCU_0_FHIMRKC0_10_RKNEN1_MASK          (0x8U)
#define VFCCU_0_FHIMRKC0_10_RKNEN1_SHIFT         (3U)
#define VFCCU_0_FHIMRKC0_10_RKNEN1_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_10_RKNEN1(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_10_RKNEN1_SHIFT)) & VFCCU_0_FHIMRKC0_10_RKNEN1_MASK)

#define VFCCU_0_FHIMRKC0_10_RKNEN2_MASK          (0x10U)
#define VFCCU_0_FHIMRKC0_10_RKNEN2_SHIFT         (4U)
#define VFCCU_0_FHIMRKC0_10_RKNEN2_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_10_RKNEN2(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_10_RKNEN2_SHIFT)) & VFCCU_0_FHIMRKC0_10_RKNEN2_MASK)

#define VFCCU_0_FHIMRKC0_10_RKNEN3_MASK          (0x20U)
#define VFCCU_0_FHIMRKC0_10_RKNEN3_SHIFT         (5U)
#define VFCCU_0_FHIMRKC0_10_RKNEN3_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_10_RKNEN3(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_10_RKNEN3_SHIFT)) & VFCCU_0_FHIMRKC0_10_RKNEN3_MASK)

#define VFCCU_0_FHIMRKC0_10_RKNEN4_MASK          (0x40U)
#define VFCCU_0_FHIMRKC0_10_RKNEN4_SHIFT         (6U)
#define VFCCU_0_FHIMRKC0_10_RKNEN4_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_10_RKNEN4(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_10_RKNEN4_SHIFT)) & VFCCU_0_FHIMRKC0_10_RKNEN4_MASK)

#define VFCCU_0_FHIMRKC0_10_RKNEN5_MASK          (0x80U)
#define VFCCU_0_FHIMRKC0_10_RKNEN5_SHIFT         (7U)
#define VFCCU_0_FHIMRKC0_10_RKNEN5_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_10_RKNEN5(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_10_RKNEN5_SHIFT)) & VFCCU_0_FHIMRKC0_10_RKNEN5_MASK)

#define VFCCU_0_FHIMRKC0_10_RKNEN6_MASK          (0x100U)
#define VFCCU_0_FHIMRKC0_10_RKNEN6_SHIFT         (8U)
#define VFCCU_0_FHIMRKC0_10_RKNEN6_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_10_RKNEN6(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_10_RKNEN6_SHIFT)) & VFCCU_0_FHIMRKC0_10_RKNEN6_MASK)

#define VFCCU_0_FHIMRKC0_10_RKNEN7_MASK          (0x200U)
#define VFCCU_0_FHIMRKC0_10_RKNEN7_SHIFT         (9U)
#define VFCCU_0_FHIMRKC0_10_RKNEN7_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_10_RKNEN7(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_10_RKNEN7_SHIFT)) & VFCCU_0_FHIMRKC0_10_RKNEN7_MASK)

#define VFCCU_0_FHIMRKC0_10_RKNEN8_MASK          (0x400U)
#define VFCCU_0_FHIMRKC0_10_RKNEN8_SHIFT         (10U)
#define VFCCU_0_FHIMRKC0_10_RKNEN8_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_10_RKNEN8(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_10_RKNEN8_SHIFT)) & VFCCU_0_FHIMRKC0_10_RKNEN8_MASK)

#define VFCCU_0_FHIMRKC0_10_RKNEN9_MASK          (0x800U)
#define VFCCU_0_FHIMRKC0_10_RKNEN9_SHIFT         (11U)
#define VFCCU_0_FHIMRKC0_10_RKNEN9_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_10_RKNEN9(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_10_RKNEN9_SHIFT)) & VFCCU_0_FHIMRKC0_10_RKNEN9_MASK)

#define VFCCU_0_FHIMRKC0_10_RKNEN10_MASK         (0x1000U)
#define VFCCU_0_FHIMRKC0_10_RKNEN10_SHIFT        (12U)
#define VFCCU_0_FHIMRKC0_10_RKNEN10_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_10_RKNEN10(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_10_RKNEN10_SHIFT)) & VFCCU_0_FHIMRKC0_10_RKNEN10_MASK)

#define VFCCU_0_FHIMRKC0_10_RKNEN11_MASK         (0x2000U)
#define VFCCU_0_FHIMRKC0_10_RKNEN11_SHIFT        (13U)
#define VFCCU_0_FHIMRKC0_10_RKNEN11_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_10_RKNEN11(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_10_RKNEN11_SHIFT)) & VFCCU_0_FHIMRKC0_10_RKNEN11_MASK)

#define VFCCU_0_FHIMRKC0_10_RKNEN12_MASK         (0x4000U)
#define VFCCU_0_FHIMRKC0_10_RKNEN12_SHIFT        (14U)
#define VFCCU_0_FHIMRKC0_10_RKNEN12_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_10_RKNEN12(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_10_RKNEN12_SHIFT)) & VFCCU_0_FHIMRKC0_10_RKNEN12_MASK)

#define VFCCU_0_FHIMRKC0_10_RKNEN13_MASK         (0x8000U)
#define VFCCU_0_FHIMRKC0_10_RKNEN13_SHIFT        (15U)
#define VFCCU_0_FHIMRKC0_10_RKNEN13_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_10_RKNEN13(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_10_RKNEN13_SHIFT)) & VFCCU_0_FHIMRKC0_10_RKNEN13_MASK)

#define VFCCU_0_FHIMRKC0_10_RKNEN14_MASK         (0x10000U)
#define VFCCU_0_FHIMRKC0_10_RKNEN14_SHIFT        (16U)
#define VFCCU_0_FHIMRKC0_10_RKNEN14_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_10_RKNEN14(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_10_RKNEN14_SHIFT)) & VFCCU_0_FHIMRKC0_10_RKNEN14_MASK)

#define VFCCU_0_FHIMRKC0_10_RKNEN15_MASK         (0x20000U)
#define VFCCU_0_FHIMRKC0_10_RKNEN15_SHIFT        (17U)
#define VFCCU_0_FHIMRKC0_10_RKNEN15_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_10_RKNEN15(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_10_RKNEN15_SHIFT)) & VFCCU_0_FHIMRKC0_10_RKNEN15_MASK)

#define VFCCU_0_FHIMRKC0_10_RKNEN16_MASK         (0x40000U)
#define VFCCU_0_FHIMRKC0_10_RKNEN16_SHIFT        (18U)
#define VFCCU_0_FHIMRKC0_10_RKNEN16_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_10_RKNEN16(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_10_RKNEN16_SHIFT)) & VFCCU_0_FHIMRKC0_10_RKNEN16_MASK)

#define VFCCU_0_FHIMRKC0_10_RKNEN17_MASK         (0x80000U)
#define VFCCU_0_FHIMRKC0_10_RKNEN17_SHIFT        (19U)
#define VFCCU_0_FHIMRKC0_10_RKNEN17_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_10_RKNEN17(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_10_RKNEN17_SHIFT)) & VFCCU_0_FHIMRKC0_10_RKNEN17_MASK)

#define VFCCU_0_FHIMRKC0_10_RKNEN18_MASK         (0x100000U)
#define VFCCU_0_FHIMRKC0_10_RKNEN18_SHIFT        (20U)
#define VFCCU_0_FHIMRKC0_10_RKNEN18_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_10_RKNEN18(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_10_RKNEN18_SHIFT)) & VFCCU_0_FHIMRKC0_10_RKNEN18_MASK)

#define VFCCU_0_FHIMRKC0_10_RKNEN19_MASK         (0x200000U)
#define VFCCU_0_FHIMRKC0_10_RKNEN19_SHIFT        (21U)
#define VFCCU_0_FHIMRKC0_10_RKNEN19_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_10_RKNEN19(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_10_RKNEN19_SHIFT)) & VFCCU_0_FHIMRKC0_10_RKNEN19_MASK)

#define VFCCU_0_FHIMRKC0_10_RKNEN20_MASK         (0x400000U)
#define VFCCU_0_FHIMRKC0_10_RKNEN20_SHIFT        (22U)
#define VFCCU_0_FHIMRKC0_10_RKNEN20_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_10_RKNEN20(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_10_RKNEN20_SHIFT)) & VFCCU_0_FHIMRKC0_10_RKNEN20_MASK)

#define VFCCU_0_FHIMRKC0_10_RKNEN21_MASK         (0x800000U)
#define VFCCU_0_FHIMRKC0_10_RKNEN21_SHIFT        (23U)
#define VFCCU_0_FHIMRKC0_10_RKNEN21_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_10_RKNEN21(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_10_RKNEN21_SHIFT)) & VFCCU_0_FHIMRKC0_10_RKNEN21_MASK)

#define VFCCU_0_FHIMRKC0_10_RKNEN22_MASK         (0x1000000U)
#define VFCCU_0_FHIMRKC0_10_RKNEN22_SHIFT        (24U)
#define VFCCU_0_FHIMRKC0_10_RKNEN22_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_10_RKNEN22(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_10_RKNEN22_SHIFT)) & VFCCU_0_FHIMRKC0_10_RKNEN22_MASK)

#define VFCCU_0_FHIMRKC0_10_RKNEN23_MASK         (0x2000000U)
#define VFCCU_0_FHIMRKC0_10_RKNEN23_SHIFT        (25U)
#define VFCCU_0_FHIMRKC0_10_RKNEN23_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_10_RKNEN23(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_10_RKNEN23_SHIFT)) & VFCCU_0_FHIMRKC0_10_RKNEN23_MASK)

#define VFCCU_0_FHIMRKC0_10_RKNEN24_MASK         (0x4000000U)
#define VFCCU_0_FHIMRKC0_10_RKNEN24_SHIFT        (26U)
#define VFCCU_0_FHIMRKC0_10_RKNEN24_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_10_RKNEN24(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_10_RKNEN24_SHIFT)) & VFCCU_0_FHIMRKC0_10_RKNEN24_MASK)

#define VFCCU_0_FHIMRKC0_10_RKNEN25_MASK         (0x8000000U)
#define VFCCU_0_FHIMRKC0_10_RKNEN25_SHIFT        (27U)
#define VFCCU_0_FHIMRKC0_10_RKNEN25_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_10_RKNEN25(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_10_RKNEN25_SHIFT)) & VFCCU_0_FHIMRKC0_10_RKNEN25_MASK)

#define VFCCU_0_FHIMRKC0_10_RKNEN26_MASK         (0x10000000U)
#define VFCCU_0_FHIMRKC0_10_RKNEN26_SHIFT        (28U)
#define VFCCU_0_FHIMRKC0_10_RKNEN26_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_10_RKNEN26(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_10_RKNEN26_SHIFT)) & VFCCU_0_FHIMRKC0_10_RKNEN26_MASK)

#define VFCCU_0_FHIMRKC0_10_RKNEN27_MASK         (0x20000000U)
#define VFCCU_0_FHIMRKC0_10_RKNEN27_SHIFT        (29U)
#define VFCCU_0_FHIMRKC0_10_RKNEN27_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_10_RKNEN27(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_10_RKNEN27_SHIFT)) & VFCCU_0_FHIMRKC0_10_RKNEN27_MASK)

#define VFCCU_0_FHIMRKC0_10_RKNEN28_MASK         (0x40000000U)
#define VFCCU_0_FHIMRKC0_10_RKNEN28_SHIFT        (30U)
#define VFCCU_0_FHIMRKC0_10_RKNEN28_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_10_RKNEN28(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_10_RKNEN28_SHIFT)) & VFCCU_0_FHIMRKC0_10_RKNEN28_MASK)

#define VFCCU_0_FHIMRKC0_10_RKNEN29_MASK         (0x80000000U)
#define VFCCU_0_FHIMRKC0_10_RKNEN29_SHIFT        (31U)
#define VFCCU_0_FHIMRKC0_10_RKNEN29_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_10_RKNEN29(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_10_RKNEN29_SHIFT)) & VFCCU_0_FHIMRKC0_10_RKNEN29_MASK)
/*! @} */

/*! @name FHDLRKC0_10 - Delayed Reaction Configuration */
/*! @{ */

#define VFCCU_0_FHDLRKC0_10_EOUTEN0_MASK         (0x1U)
#define VFCCU_0_FHDLRKC0_10_EOUTEN0_SHIFT        (0U)
#define VFCCU_0_FHDLRKC0_10_EOUTEN0_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_10_EOUTEN0(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_10_EOUTEN0_SHIFT)) & VFCCU_0_FHDLRKC0_10_EOUTEN0_MASK)

#define VFCCU_0_FHDLRKC0_10_EOUTEN1_MASK         (0x2U)
#define VFCCU_0_FHDLRKC0_10_EOUTEN1_SHIFT        (1U)
#define VFCCU_0_FHDLRKC0_10_EOUTEN1_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_10_EOUTEN1(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_10_EOUTEN1_SHIFT)) & VFCCU_0_FHDLRKC0_10_EOUTEN1_MASK)

#define VFCCU_0_FHDLRKC0_10_RKNEN0_MASK          (0x4U)
#define VFCCU_0_FHDLRKC0_10_RKNEN0_SHIFT         (2U)
#define VFCCU_0_FHDLRKC0_10_RKNEN0_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_10_RKNEN0(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_10_RKNEN0_SHIFT)) & VFCCU_0_FHDLRKC0_10_RKNEN0_MASK)

#define VFCCU_0_FHDLRKC0_10_RKNEN1_MASK          (0x8U)
#define VFCCU_0_FHDLRKC0_10_RKNEN1_SHIFT         (3U)
#define VFCCU_0_FHDLRKC0_10_RKNEN1_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_10_RKNEN1(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_10_RKNEN1_SHIFT)) & VFCCU_0_FHDLRKC0_10_RKNEN1_MASK)

#define VFCCU_0_FHDLRKC0_10_RKNEN2_MASK          (0x10U)
#define VFCCU_0_FHDLRKC0_10_RKNEN2_SHIFT         (4U)
#define VFCCU_0_FHDLRKC0_10_RKNEN2_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_10_RKNEN2(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_10_RKNEN2_SHIFT)) & VFCCU_0_FHDLRKC0_10_RKNEN2_MASK)

#define VFCCU_0_FHDLRKC0_10_RKNEN3_MASK          (0x20U)
#define VFCCU_0_FHDLRKC0_10_RKNEN3_SHIFT         (5U)
#define VFCCU_0_FHDLRKC0_10_RKNEN3_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_10_RKNEN3(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_10_RKNEN3_SHIFT)) & VFCCU_0_FHDLRKC0_10_RKNEN3_MASK)

#define VFCCU_0_FHDLRKC0_10_RKNEN4_MASK          (0x40U)
#define VFCCU_0_FHDLRKC0_10_RKNEN4_SHIFT         (6U)
#define VFCCU_0_FHDLRKC0_10_RKNEN4_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_10_RKNEN4(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_10_RKNEN4_SHIFT)) & VFCCU_0_FHDLRKC0_10_RKNEN4_MASK)

#define VFCCU_0_FHDLRKC0_10_RKNEN5_MASK          (0x80U)
#define VFCCU_0_FHDLRKC0_10_RKNEN5_SHIFT         (7U)
#define VFCCU_0_FHDLRKC0_10_RKNEN5_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_10_RKNEN5(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_10_RKNEN5_SHIFT)) & VFCCU_0_FHDLRKC0_10_RKNEN5_MASK)

#define VFCCU_0_FHDLRKC0_10_RKNEN6_MASK          (0x100U)
#define VFCCU_0_FHDLRKC0_10_RKNEN6_SHIFT         (8U)
#define VFCCU_0_FHDLRKC0_10_RKNEN6_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_10_RKNEN6(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_10_RKNEN6_SHIFT)) & VFCCU_0_FHDLRKC0_10_RKNEN6_MASK)

#define VFCCU_0_FHDLRKC0_10_RKNEN7_MASK          (0x200U)
#define VFCCU_0_FHDLRKC0_10_RKNEN7_SHIFT         (9U)
#define VFCCU_0_FHDLRKC0_10_RKNEN7_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_10_RKNEN7(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_10_RKNEN7_SHIFT)) & VFCCU_0_FHDLRKC0_10_RKNEN7_MASK)

#define VFCCU_0_FHDLRKC0_10_RKNEN8_MASK          (0x400U)
#define VFCCU_0_FHDLRKC0_10_RKNEN8_SHIFT         (10U)
#define VFCCU_0_FHDLRKC0_10_RKNEN8_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_10_RKNEN8(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_10_RKNEN8_SHIFT)) & VFCCU_0_FHDLRKC0_10_RKNEN8_MASK)

#define VFCCU_0_FHDLRKC0_10_RKNEN9_MASK          (0x800U)
#define VFCCU_0_FHDLRKC0_10_RKNEN9_SHIFT         (11U)
#define VFCCU_0_FHDLRKC0_10_RKNEN9_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_10_RKNEN9(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_10_RKNEN9_SHIFT)) & VFCCU_0_FHDLRKC0_10_RKNEN9_MASK)

#define VFCCU_0_FHDLRKC0_10_RKNEN10_MASK         (0x1000U)
#define VFCCU_0_FHDLRKC0_10_RKNEN10_SHIFT        (12U)
#define VFCCU_0_FHDLRKC0_10_RKNEN10_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_10_RKNEN10(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_10_RKNEN10_SHIFT)) & VFCCU_0_FHDLRKC0_10_RKNEN10_MASK)

#define VFCCU_0_FHDLRKC0_10_RKNEN11_MASK         (0x2000U)
#define VFCCU_0_FHDLRKC0_10_RKNEN11_SHIFT        (13U)
#define VFCCU_0_FHDLRKC0_10_RKNEN11_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_10_RKNEN11(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_10_RKNEN11_SHIFT)) & VFCCU_0_FHDLRKC0_10_RKNEN11_MASK)

#define VFCCU_0_FHDLRKC0_10_RKNEN12_MASK         (0x4000U)
#define VFCCU_0_FHDLRKC0_10_RKNEN12_SHIFT        (14U)
#define VFCCU_0_FHDLRKC0_10_RKNEN12_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_10_RKNEN12(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_10_RKNEN12_SHIFT)) & VFCCU_0_FHDLRKC0_10_RKNEN12_MASK)

#define VFCCU_0_FHDLRKC0_10_RKNEN13_MASK         (0x8000U)
#define VFCCU_0_FHDLRKC0_10_RKNEN13_SHIFT        (15U)
#define VFCCU_0_FHDLRKC0_10_RKNEN13_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_10_RKNEN13(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_10_RKNEN13_SHIFT)) & VFCCU_0_FHDLRKC0_10_RKNEN13_MASK)

#define VFCCU_0_FHDLRKC0_10_RKNEN14_MASK         (0x10000U)
#define VFCCU_0_FHDLRKC0_10_RKNEN14_SHIFT        (16U)
#define VFCCU_0_FHDLRKC0_10_RKNEN14_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_10_RKNEN14(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_10_RKNEN14_SHIFT)) & VFCCU_0_FHDLRKC0_10_RKNEN14_MASK)

#define VFCCU_0_FHDLRKC0_10_RKNEN15_MASK         (0x20000U)
#define VFCCU_0_FHDLRKC0_10_RKNEN15_SHIFT        (17U)
#define VFCCU_0_FHDLRKC0_10_RKNEN15_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_10_RKNEN15(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_10_RKNEN15_SHIFT)) & VFCCU_0_FHDLRKC0_10_RKNEN15_MASK)

#define VFCCU_0_FHDLRKC0_10_RKNEN16_MASK         (0x40000U)
#define VFCCU_0_FHDLRKC0_10_RKNEN16_SHIFT        (18U)
#define VFCCU_0_FHDLRKC0_10_RKNEN16_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_10_RKNEN16(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_10_RKNEN16_SHIFT)) & VFCCU_0_FHDLRKC0_10_RKNEN16_MASK)

#define VFCCU_0_FHDLRKC0_10_RKNEN17_MASK         (0x80000U)
#define VFCCU_0_FHDLRKC0_10_RKNEN17_SHIFT        (19U)
#define VFCCU_0_FHDLRKC0_10_RKNEN17_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_10_RKNEN17(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_10_RKNEN17_SHIFT)) & VFCCU_0_FHDLRKC0_10_RKNEN17_MASK)

#define VFCCU_0_FHDLRKC0_10_RKNEN18_MASK         (0x100000U)
#define VFCCU_0_FHDLRKC0_10_RKNEN18_SHIFT        (20U)
#define VFCCU_0_FHDLRKC0_10_RKNEN18_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_10_RKNEN18(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_10_RKNEN18_SHIFT)) & VFCCU_0_FHDLRKC0_10_RKNEN18_MASK)

#define VFCCU_0_FHDLRKC0_10_RKNEN19_MASK         (0x200000U)
#define VFCCU_0_FHDLRKC0_10_RKNEN19_SHIFT        (21U)
#define VFCCU_0_FHDLRKC0_10_RKNEN19_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_10_RKNEN19(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_10_RKNEN19_SHIFT)) & VFCCU_0_FHDLRKC0_10_RKNEN19_MASK)

#define VFCCU_0_FHDLRKC0_10_RKNEN20_MASK         (0x400000U)
#define VFCCU_0_FHDLRKC0_10_RKNEN20_SHIFT        (22U)
#define VFCCU_0_FHDLRKC0_10_RKNEN20_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_10_RKNEN20(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_10_RKNEN20_SHIFT)) & VFCCU_0_FHDLRKC0_10_RKNEN20_MASK)

#define VFCCU_0_FHDLRKC0_10_RKNEN21_MASK         (0x800000U)
#define VFCCU_0_FHDLRKC0_10_RKNEN21_SHIFT        (23U)
#define VFCCU_0_FHDLRKC0_10_RKNEN21_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_10_RKNEN21(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_10_RKNEN21_SHIFT)) & VFCCU_0_FHDLRKC0_10_RKNEN21_MASK)

#define VFCCU_0_FHDLRKC0_10_RKNEN22_MASK         (0x1000000U)
#define VFCCU_0_FHDLRKC0_10_RKNEN22_SHIFT        (24U)
#define VFCCU_0_FHDLRKC0_10_RKNEN22_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_10_RKNEN22(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_10_RKNEN22_SHIFT)) & VFCCU_0_FHDLRKC0_10_RKNEN22_MASK)

#define VFCCU_0_FHDLRKC0_10_RKNEN23_MASK         (0x2000000U)
#define VFCCU_0_FHDLRKC0_10_RKNEN23_SHIFT        (25U)
#define VFCCU_0_FHDLRKC0_10_RKNEN23_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_10_RKNEN23(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_10_RKNEN23_SHIFT)) & VFCCU_0_FHDLRKC0_10_RKNEN23_MASK)

#define VFCCU_0_FHDLRKC0_10_RKNEN24_MASK         (0x4000000U)
#define VFCCU_0_FHDLRKC0_10_RKNEN24_SHIFT        (26U)
#define VFCCU_0_FHDLRKC0_10_RKNEN24_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_10_RKNEN24(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_10_RKNEN24_SHIFT)) & VFCCU_0_FHDLRKC0_10_RKNEN24_MASK)

#define VFCCU_0_FHDLRKC0_10_RKNEN25_MASK         (0x8000000U)
#define VFCCU_0_FHDLRKC0_10_RKNEN25_SHIFT        (27U)
#define VFCCU_0_FHDLRKC0_10_RKNEN25_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_10_RKNEN25(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_10_RKNEN25_SHIFT)) & VFCCU_0_FHDLRKC0_10_RKNEN25_MASK)

#define VFCCU_0_FHDLRKC0_10_RKNEN26_MASK         (0x10000000U)
#define VFCCU_0_FHDLRKC0_10_RKNEN26_SHIFT        (28U)
#define VFCCU_0_FHDLRKC0_10_RKNEN26_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_10_RKNEN26(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_10_RKNEN26_SHIFT)) & VFCCU_0_FHDLRKC0_10_RKNEN26_MASK)

#define VFCCU_0_FHDLRKC0_10_RKNEN27_MASK         (0x20000000U)
#define VFCCU_0_FHDLRKC0_10_RKNEN27_SHIFT        (29U)
#define VFCCU_0_FHDLRKC0_10_RKNEN27_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_10_RKNEN27(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_10_RKNEN27_SHIFT)) & VFCCU_0_FHDLRKC0_10_RKNEN27_MASK)

#define VFCCU_0_FHDLRKC0_10_RKNEN28_MASK         (0x40000000U)
#define VFCCU_0_FHDLRKC0_10_RKNEN28_SHIFT        (30U)
#define VFCCU_0_FHDLRKC0_10_RKNEN28_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_10_RKNEN28(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_10_RKNEN28_SHIFT)) & VFCCU_0_FHDLRKC0_10_RKNEN28_MASK)

#define VFCCU_0_FHDLRKC0_10_RKNEN29_MASK         (0x80000000U)
#define VFCCU_0_FHDLRKC0_10_RKNEN29_SHIFT        (31U)
#define VFCCU_0_FHDLRKC0_10_RKNEN29_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_10_RKNEN29(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_10_RKNEN29_SHIFT)) & VFCCU_0_FHDLRKC0_10_RKNEN29_MASK)
/*! @} */

/*! @name FHIMRKC0_20 - Immediate Reaction Configuration */
/*! @{ */

#define VFCCU_0_FHIMRKC0_20_EOUTEN0_MASK         (0x1U)
#define VFCCU_0_FHIMRKC0_20_EOUTEN0_SHIFT        (0U)
#define VFCCU_0_FHIMRKC0_20_EOUTEN0_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_20_EOUTEN0(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_20_EOUTEN0_SHIFT)) & VFCCU_0_FHIMRKC0_20_EOUTEN0_MASK)

#define VFCCU_0_FHIMRKC0_20_EOUTEN1_MASK         (0x2U)
#define VFCCU_0_FHIMRKC0_20_EOUTEN1_SHIFT        (1U)
#define VFCCU_0_FHIMRKC0_20_EOUTEN1_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_20_EOUTEN1(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_20_EOUTEN1_SHIFT)) & VFCCU_0_FHIMRKC0_20_EOUTEN1_MASK)

#define VFCCU_0_FHIMRKC0_20_RKNEN0_MASK          (0x4U)
#define VFCCU_0_FHIMRKC0_20_RKNEN0_SHIFT         (2U)
#define VFCCU_0_FHIMRKC0_20_RKNEN0_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_20_RKNEN0(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_20_RKNEN0_SHIFT)) & VFCCU_0_FHIMRKC0_20_RKNEN0_MASK)

#define VFCCU_0_FHIMRKC0_20_RKNEN1_MASK          (0x8U)
#define VFCCU_0_FHIMRKC0_20_RKNEN1_SHIFT         (3U)
#define VFCCU_0_FHIMRKC0_20_RKNEN1_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_20_RKNEN1(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_20_RKNEN1_SHIFT)) & VFCCU_0_FHIMRKC0_20_RKNEN1_MASK)

#define VFCCU_0_FHIMRKC0_20_RKNEN2_MASK          (0x10U)
#define VFCCU_0_FHIMRKC0_20_RKNEN2_SHIFT         (4U)
#define VFCCU_0_FHIMRKC0_20_RKNEN2_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_20_RKNEN2(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_20_RKNEN2_SHIFT)) & VFCCU_0_FHIMRKC0_20_RKNEN2_MASK)

#define VFCCU_0_FHIMRKC0_20_RKNEN3_MASK          (0x20U)
#define VFCCU_0_FHIMRKC0_20_RKNEN3_SHIFT         (5U)
#define VFCCU_0_FHIMRKC0_20_RKNEN3_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_20_RKNEN3(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_20_RKNEN3_SHIFT)) & VFCCU_0_FHIMRKC0_20_RKNEN3_MASK)

#define VFCCU_0_FHIMRKC0_20_RKNEN4_MASK          (0x40U)
#define VFCCU_0_FHIMRKC0_20_RKNEN4_SHIFT         (6U)
#define VFCCU_0_FHIMRKC0_20_RKNEN4_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_20_RKNEN4(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_20_RKNEN4_SHIFT)) & VFCCU_0_FHIMRKC0_20_RKNEN4_MASK)

#define VFCCU_0_FHIMRKC0_20_RKNEN5_MASK          (0x80U)
#define VFCCU_0_FHIMRKC0_20_RKNEN5_SHIFT         (7U)
#define VFCCU_0_FHIMRKC0_20_RKNEN5_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_20_RKNEN5(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_20_RKNEN5_SHIFT)) & VFCCU_0_FHIMRKC0_20_RKNEN5_MASK)

#define VFCCU_0_FHIMRKC0_20_RKNEN6_MASK          (0x100U)
#define VFCCU_0_FHIMRKC0_20_RKNEN6_SHIFT         (8U)
#define VFCCU_0_FHIMRKC0_20_RKNEN6_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_20_RKNEN6(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_20_RKNEN6_SHIFT)) & VFCCU_0_FHIMRKC0_20_RKNEN6_MASK)

#define VFCCU_0_FHIMRKC0_20_RKNEN7_MASK          (0x200U)
#define VFCCU_0_FHIMRKC0_20_RKNEN7_SHIFT         (9U)
#define VFCCU_0_FHIMRKC0_20_RKNEN7_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_20_RKNEN7(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_20_RKNEN7_SHIFT)) & VFCCU_0_FHIMRKC0_20_RKNEN7_MASK)

#define VFCCU_0_FHIMRKC0_20_RKNEN8_MASK          (0x400U)
#define VFCCU_0_FHIMRKC0_20_RKNEN8_SHIFT         (10U)
#define VFCCU_0_FHIMRKC0_20_RKNEN8_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_20_RKNEN8(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_20_RKNEN8_SHIFT)) & VFCCU_0_FHIMRKC0_20_RKNEN8_MASK)

#define VFCCU_0_FHIMRKC0_20_RKNEN9_MASK          (0x800U)
#define VFCCU_0_FHIMRKC0_20_RKNEN9_SHIFT         (11U)
#define VFCCU_0_FHIMRKC0_20_RKNEN9_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_20_RKNEN9(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_20_RKNEN9_SHIFT)) & VFCCU_0_FHIMRKC0_20_RKNEN9_MASK)

#define VFCCU_0_FHIMRKC0_20_RKNEN10_MASK         (0x1000U)
#define VFCCU_0_FHIMRKC0_20_RKNEN10_SHIFT        (12U)
#define VFCCU_0_FHIMRKC0_20_RKNEN10_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_20_RKNEN10(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_20_RKNEN10_SHIFT)) & VFCCU_0_FHIMRKC0_20_RKNEN10_MASK)

#define VFCCU_0_FHIMRKC0_20_RKNEN11_MASK         (0x2000U)
#define VFCCU_0_FHIMRKC0_20_RKNEN11_SHIFT        (13U)
#define VFCCU_0_FHIMRKC0_20_RKNEN11_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_20_RKNEN11(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_20_RKNEN11_SHIFT)) & VFCCU_0_FHIMRKC0_20_RKNEN11_MASK)

#define VFCCU_0_FHIMRKC0_20_RKNEN12_MASK         (0x4000U)
#define VFCCU_0_FHIMRKC0_20_RKNEN12_SHIFT        (14U)
#define VFCCU_0_FHIMRKC0_20_RKNEN12_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_20_RKNEN12(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_20_RKNEN12_SHIFT)) & VFCCU_0_FHIMRKC0_20_RKNEN12_MASK)

#define VFCCU_0_FHIMRKC0_20_RKNEN13_MASK         (0x8000U)
#define VFCCU_0_FHIMRKC0_20_RKNEN13_SHIFT        (15U)
#define VFCCU_0_FHIMRKC0_20_RKNEN13_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_20_RKNEN13(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_20_RKNEN13_SHIFT)) & VFCCU_0_FHIMRKC0_20_RKNEN13_MASK)

#define VFCCU_0_FHIMRKC0_20_RKNEN14_MASK         (0x10000U)
#define VFCCU_0_FHIMRKC0_20_RKNEN14_SHIFT        (16U)
#define VFCCU_0_FHIMRKC0_20_RKNEN14_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_20_RKNEN14(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_20_RKNEN14_SHIFT)) & VFCCU_0_FHIMRKC0_20_RKNEN14_MASK)

#define VFCCU_0_FHIMRKC0_20_RKNEN15_MASK         (0x20000U)
#define VFCCU_0_FHIMRKC0_20_RKNEN15_SHIFT        (17U)
#define VFCCU_0_FHIMRKC0_20_RKNEN15_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_20_RKNEN15(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_20_RKNEN15_SHIFT)) & VFCCU_0_FHIMRKC0_20_RKNEN15_MASK)

#define VFCCU_0_FHIMRKC0_20_RKNEN16_MASK         (0x40000U)
#define VFCCU_0_FHIMRKC0_20_RKNEN16_SHIFT        (18U)
#define VFCCU_0_FHIMRKC0_20_RKNEN16_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_20_RKNEN16(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_20_RKNEN16_SHIFT)) & VFCCU_0_FHIMRKC0_20_RKNEN16_MASK)

#define VFCCU_0_FHIMRKC0_20_RKNEN17_MASK         (0x80000U)
#define VFCCU_0_FHIMRKC0_20_RKNEN17_SHIFT        (19U)
#define VFCCU_0_FHIMRKC0_20_RKNEN17_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_20_RKNEN17(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_20_RKNEN17_SHIFT)) & VFCCU_0_FHIMRKC0_20_RKNEN17_MASK)

#define VFCCU_0_FHIMRKC0_20_RKNEN18_MASK         (0x100000U)
#define VFCCU_0_FHIMRKC0_20_RKNEN18_SHIFT        (20U)
#define VFCCU_0_FHIMRKC0_20_RKNEN18_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_20_RKNEN18(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_20_RKNEN18_SHIFT)) & VFCCU_0_FHIMRKC0_20_RKNEN18_MASK)

#define VFCCU_0_FHIMRKC0_20_RKNEN19_MASK         (0x200000U)
#define VFCCU_0_FHIMRKC0_20_RKNEN19_SHIFT        (21U)
#define VFCCU_0_FHIMRKC0_20_RKNEN19_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_20_RKNEN19(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_20_RKNEN19_SHIFT)) & VFCCU_0_FHIMRKC0_20_RKNEN19_MASK)

#define VFCCU_0_FHIMRKC0_20_RKNEN20_MASK         (0x400000U)
#define VFCCU_0_FHIMRKC0_20_RKNEN20_SHIFT        (22U)
#define VFCCU_0_FHIMRKC0_20_RKNEN20_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_20_RKNEN20(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_20_RKNEN20_SHIFT)) & VFCCU_0_FHIMRKC0_20_RKNEN20_MASK)

#define VFCCU_0_FHIMRKC0_20_RKNEN21_MASK         (0x800000U)
#define VFCCU_0_FHIMRKC0_20_RKNEN21_SHIFT        (23U)
#define VFCCU_0_FHIMRKC0_20_RKNEN21_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_20_RKNEN21(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_20_RKNEN21_SHIFT)) & VFCCU_0_FHIMRKC0_20_RKNEN21_MASK)

#define VFCCU_0_FHIMRKC0_20_RKNEN22_MASK         (0x1000000U)
#define VFCCU_0_FHIMRKC0_20_RKNEN22_SHIFT        (24U)
#define VFCCU_0_FHIMRKC0_20_RKNEN22_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_20_RKNEN22(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_20_RKNEN22_SHIFT)) & VFCCU_0_FHIMRKC0_20_RKNEN22_MASK)

#define VFCCU_0_FHIMRKC0_20_RKNEN23_MASK         (0x2000000U)
#define VFCCU_0_FHIMRKC0_20_RKNEN23_SHIFT        (25U)
#define VFCCU_0_FHIMRKC0_20_RKNEN23_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_20_RKNEN23(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_20_RKNEN23_SHIFT)) & VFCCU_0_FHIMRKC0_20_RKNEN23_MASK)

#define VFCCU_0_FHIMRKC0_20_RKNEN24_MASK         (0x4000000U)
#define VFCCU_0_FHIMRKC0_20_RKNEN24_SHIFT        (26U)
#define VFCCU_0_FHIMRKC0_20_RKNEN24_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_20_RKNEN24(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_20_RKNEN24_SHIFT)) & VFCCU_0_FHIMRKC0_20_RKNEN24_MASK)

#define VFCCU_0_FHIMRKC0_20_RKNEN25_MASK         (0x8000000U)
#define VFCCU_0_FHIMRKC0_20_RKNEN25_SHIFT        (27U)
#define VFCCU_0_FHIMRKC0_20_RKNEN25_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_20_RKNEN25(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_20_RKNEN25_SHIFT)) & VFCCU_0_FHIMRKC0_20_RKNEN25_MASK)

#define VFCCU_0_FHIMRKC0_20_RKNEN26_MASK         (0x10000000U)
#define VFCCU_0_FHIMRKC0_20_RKNEN26_SHIFT        (28U)
#define VFCCU_0_FHIMRKC0_20_RKNEN26_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_20_RKNEN26(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_20_RKNEN26_SHIFT)) & VFCCU_0_FHIMRKC0_20_RKNEN26_MASK)

#define VFCCU_0_FHIMRKC0_20_RKNEN27_MASK         (0x20000000U)
#define VFCCU_0_FHIMRKC0_20_RKNEN27_SHIFT        (29U)
#define VFCCU_0_FHIMRKC0_20_RKNEN27_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_20_RKNEN27(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_20_RKNEN27_SHIFT)) & VFCCU_0_FHIMRKC0_20_RKNEN27_MASK)

#define VFCCU_0_FHIMRKC0_20_RKNEN28_MASK         (0x40000000U)
#define VFCCU_0_FHIMRKC0_20_RKNEN28_SHIFT        (30U)
#define VFCCU_0_FHIMRKC0_20_RKNEN28_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_20_RKNEN28(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_20_RKNEN28_SHIFT)) & VFCCU_0_FHIMRKC0_20_RKNEN28_MASK)

#define VFCCU_0_FHIMRKC0_20_RKNEN29_MASK         (0x80000000U)
#define VFCCU_0_FHIMRKC0_20_RKNEN29_SHIFT        (31U)
#define VFCCU_0_FHIMRKC0_20_RKNEN29_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_20_RKNEN29(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_20_RKNEN29_SHIFT)) & VFCCU_0_FHIMRKC0_20_RKNEN29_MASK)
/*! @} */

/*! @name FHDLRKC0_20 - Delayed Reaction Configuration */
/*! @{ */

#define VFCCU_0_FHDLRKC0_20_EOUTEN0_MASK         (0x1U)
#define VFCCU_0_FHDLRKC0_20_EOUTEN0_SHIFT        (0U)
#define VFCCU_0_FHDLRKC0_20_EOUTEN0_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_20_EOUTEN0(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_20_EOUTEN0_SHIFT)) & VFCCU_0_FHDLRKC0_20_EOUTEN0_MASK)

#define VFCCU_0_FHDLRKC0_20_EOUTEN1_MASK         (0x2U)
#define VFCCU_0_FHDLRKC0_20_EOUTEN1_SHIFT        (1U)
#define VFCCU_0_FHDLRKC0_20_EOUTEN1_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_20_EOUTEN1(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_20_EOUTEN1_SHIFT)) & VFCCU_0_FHDLRKC0_20_EOUTEN1_MASK)

#define VFCCU_0_FHDLRKC0_20_RKNEN0_MASK          (0x4U)
#define VFCCU_0_FHDLRKC0_20_RKNEN0_SHIFT         (2U)
#define VFCCU_0_FHDLRKC0_20_RKNEN0_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_20_RKNEN0(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_20_RKNEN0_SHIFT)) & VFCCU_0_FHDLRKC0_20_RKNEN0_MASK)

#define VFCCU_0_FHDLRKC0_20_RKNEN1_MASK          (0x8U)
#define VFCCU_0_FHDLRKC0_20_RKNEN1_SHIFT         (3U)
#define VFCCU_0_FHDLRKC0_20_RKNEN1_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_20_RKNEN1(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_20_RKNEN1_SHIFT)) & VFCCU_0_FHDLRKC0_20_RKNEN1_MASK)

#define VFCCU_0_FHDLRKC0_20_RKNEN2_MASK          (0x10U)
#define VFCCU_0_FHDLRKC0_20_RKNEN2_SHIFT         (4U)
#define VFCCU_0_FHDLRKC0_20_RKNEN2_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_20_RKNEN2(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_20_RKNEN2_SHIFT)) & VFCCU_0_FHDLRKC0_20_RKNEN2_MASK)

#define VFCCU_0_FHDLRKC0_20_RKNEN3_MASK          (0x20U)
#define VFCCU_0_FHDLRKC0_20_RKNEN3_SHIFT         (5U)
#define VFCCU_0_FHDLRKC0_20_RKNEN3_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_20_RKNEN3(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_20_RKNEN3_SHIFT)) & VFCCU_0_FHDLRKC0_20_RKNEN3_MASK)

#define VFCCU_0_FHDLRKC0_20_RKNEN4_MASK          (0x40U)
#define VFCCU_0_FHDLRKC0_20_RKNEN4_SHIFT         (6U)
#define VFCCU_0_FHDLRKC0_20_RKNEN4_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_20_RKNEN4(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_20_RKNEN4_SHIFT)) & VFCCU_0_FHDLRKC0_20_RKNEN4_MASK)

#define VFCCU_0_FHDLRKC0_20_RKNEN5_MASK          (0x80U)
#define VFCCU_0_FHDLRKC0_20_RKNEN5_SHIFT         (7U)
#define VFCCU_0_FHDLRKC0_20_RKNEN5_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_20_RKNEN5(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_20_RKNEN5_SHIFT)) & VFCCU_0_FHDLRKC0_20_RKNEN5_MASK)

#define VFCCU_0_FHDLRKC0_20_RKNEN6_MASK          (0x100U)
#define VFCCU_0_FHDLRKC0_20_RKNEN6_SHIFT         (8U)
#define VFCCU_0_FHDLRKC0_20_RKNEN6_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_20_RKNEN6(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_20_RKNEN6_SHIFT)) & VFCCU_0_FHDLRKC0_20_RKNEN6_MASK)

#define VFCCU_0_FHDLRKC0_20_RKNEN7_MASK          (0x200U)
#define VFCCU_0_FHDLRKC0_20_RKNEN7_SHIFT         (9U)
#define VFCCU_0_FHDLRKC0_20_RKNEN7_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_20_RKNEN7(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_20_RKNEN7_SHIFT)) & VFCCU_0_FHDLRKC0_20_RKNEN7_MASK)

#define VFCCU_0_FHDLRKC0_20_RKNEN8_MASK          (0x400U)
#define VFCCU_0_FHDLRKC0_20_RKNEN8_SHIFT         (10U)
#define VFCCU_0_FHDLRKC0_20_RKNEN8_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_20_RKNEN8(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_20_RKNEN8_SHIFT)) & VFCCU_0_FHDLRKC0_20_RKNEN8_MASK)

#define VFCCU_0_FHDLRKC0_20_RKNEN9_MASK          (0x800U)
#define VFCCU_0_FHDLRKC0_20_RKNEN9_SHIFT         (11U)
#define VFCCU_0_FHDLRKC0_20_RKNEN9_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_20_RKNEN9(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_20_RKNEN9_SHIFT)) & VFCCU_0_FHDLRKC0_20_RKNEN9_MASK)

#define VFCCU_0_FHDLRKC0_20_RKNEN10_MASK         (0x1000U)
#define VFCCU_0_FHDLRKC0_20_RKNEN10_SHIFT        (12U)
#define VFCCU_0_FHDLRKC0_20_RKNEN10_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_20_RKNEN10(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_20_RKNEN10_SHIFT)) & VFCCU_0_FHDLRKC0_20_RKNEN10_MASK)

#define VFCCU_0_FHDLRKC0_20_RKNEN11_MASK         (0x2000U)
#define VFCCU_0_FHDLRKC0_20_RKNEN11_SHIFT        (13U)
#define VFCCU_0_FHDLRKC0_20_RKNEN11_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_20_RKNEN11(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_20_RKNEN11_SHIFT)) & VFCCU_0_FHDLRKC0_20_RKNEN11_MASK)

#define VFCCU_0_FHDLRKC0_20_RKNEN12_MASK         (0x4000U)
#define VFCCU_0_FHDLRKC0_20_RKNEN12_SHIFT        (14U)
#define VFCCU_0_FHDLRKC0_20_RKNEN12_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_20_RKNEN12(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_20_RKNEN12_SHIFT)) & VFCCU_0_FHDLRKC0_20_RKNEN12_MASK)

#define VFCCU_0_FHDLRKC0_20_RKNEN13_MASK         (0x8000U)
#define VFCCU_0_FHDLRKC0_20_RKNEN13_SHIFT        (15U)
#define VFCCU_0_FHDLRKC0_20_RKNEN13_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_20_RKNEN13(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_20_RKNEN13_SHIFT)) & VFCCU_0_FHDLRKC0_20_RKNEN13_MASK)

#define VFCCU_0_FHDLRKC0_20_RKNEN14_MASK         (0x10000U)
#define VFCCU_0_FHDLRKC0_20_RKNEN14_SHIFT        (16U)
#define VFCCU_0_FHDLRKC0_20_RKNEN14_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_20_RKNEN14(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_20_RKNEN14_SHIFT)) & VFCCU_0_FHDLRKC0_20_RKNEN14_MASK)

#define VFCCU_0_FHDLRKC0_20_RKNEN15_MASK         (0x20000U)
#define VFCCU_0_FHDLRKC0_20_RKNEN15_SHIFT        (17U)
#define VFCCU_0_FHDLRKC0_20_RKNEN15_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_20_RKNEN15(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_20_RKNEN15_SHIFT)) & VFCCU_0_FHDLRKC0_20_RKNEN15_MASK)

#define VFCCU_0_FHDLRKC0_20_RKNEN16_MASK         (0x40000U)
#define VFCCU_0_FHDLRKC0_20_RKNEN16_SHIFT        (18U)
#define VFCCU_0_FHDLRKC0_20_RKNEN16_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_20_RKNEN16(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_20_RKNEN16_SHIFT)) & VFCCU_0_FHDLRKC0_20_RKNEN16_MASK)

#define VFCCU_0_FHDLRKC0_20_RKNEN17_MASK         (0x80000U)
#define VFCCU_0_FHDLRKC0_20_RKNEN17_SHIFT        (19U)
#define VFCCU_0_FHDLRKC0_20_RKNEN17_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_20_RKNEN17(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_20_RKNEN17_SHIFT)) & VFCCU_0_FHDLRKC0_20_RKNEN17_MASK)

#define VFCCU_0_FHDLRKC0_20_RKNEN18_MASK         (0x100000U)
#define VFCCU_0_FHDLRKC0_20_RKNEN18_SHIFT        (20U)
#define VFCCU_0_FHDLRKC0_20_RKNEN18_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_20_RKNEN18(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_20_RKNEN18_SHIFT)) & VFCCU_0_FHDLRKC0_20_RKNEN18_MASK)

#define VFCCU_0_FHDLRKC0_20_RKNEN19_MASK         (0x200000U)
#define VFCCU_0_FHDLRKC0_20_RKNEN19_SHIFT        (21U)
#define VFCCU_0_FHDLRKC0_20_RKNEN19_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_20_RKNEN19(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_20_RKNEN19_SHIFT)) & VFCCU_0_FHDLRKC0_20_RKNEN19_MASK)

#define VFCCU_0_FHDLRKC0_20_RKNEN20_MASK         (0x400000U)
#define VFCCU_0_FHDLRKC0_20_RKNEN20_SHIFT        (22U)
#define VFCCU_0_FHDLRKC0_20_RKNEN20_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_20_RKNEN20(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_20_RKNEN20_SHIFT)) & VFCCU_0_FHDLRKC0_20_RKNEN20_MASK)

#define VFCCU_0_FHDLRKC0_20_RKNEN21_MASK         (0x800000U)
#define VFCCU_0_FHDLRKC0_20_RKNEN21_SHIFT        (23U)
#define VFCCU_0_FHDLRKC0_20_RKNEN21_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_20_RKNEN21(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_20_RKNEN21_SHIFT)) & VFCCU_0_FHDLRKC0_20_RKNEN21_MASK)

#define VFCCU_0_FHDLRKC0_20_RKNEN22_MASK         (0x1000000U)
#define VFCCU_0_FHDLRKC0_20_RKNEN22_SHIFT        (24U)
#define VFCCU_0_FHDLRKC0_20_RKNEN22_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_20_RKNEN22(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_20_RKNEN22_SHIFT)) & VFCCU_0_FHDLRKC0_20_RKNEN22_MASK)

#define VFCCU_0_FHDLRKC0_20_RKNEN23_MASK         (0x2000000U)
#define VFCCU_0_FHDLRKC0_20_RKNEN23_SHIFT        (25U)
#define VFCCU_0_FHDLRKC0_20_RKNEN23_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_20_RKNEN23(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_20_RKNEN23_SHIFT)) & VFCCU_0_FHDLRKC0_20_RKNEN23_MASK)

#define VFCCU_0_FHDLRKC0_20_RKNEN24_MASK         (0x4000000U)
#define VFCCU_0_FHDLRKC0_20_RKNEN24_SHIFT        (26U)
#define VFCCU_0_FHDLRKC0_20_RKNEN24_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_20_RKNEN24(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_20_RKNEN24_SHIFT)) & VFCCU_0_FHDLRKC0_20_RKNEN24_MASK)

#define VFCCU_0_FHDLRKC0_20_RKNEN25_MASK         (0x8000000U)
#define VFCCU_0_FHDLRKC0_20_RKNEN25_SHIFT        (27U)
#define VFCCU_0_FHDLRKC0_20_RKNEN25_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_20_RKNEN25(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_20_RKNEN25_SHIFT)) & VFCCU_0_FHDLRKC0_20_RKNEN25_MASK)

#define VFCCU_0_FHDLRKC0_20_RKNEN26_MASK         (0x10000000U)
#define VFCCU_0_FHDLRKC0_20_RKNEN26_SHIFT        (28U)
#define VFCCU_0_FHDLRKC0_20_RKNEN26_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_20_RKNEN26(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_20_RKNEN26_SHIFT)) & VFCCU_0_FHDLRKC0_20_RKNEN26_MASK)

#define VFCCU_0_FHDLRKC0_20_RKNEN27_MASK         (0x20000000U)
#define VFCCU_0_FHDLRKC0_20_RKNEN27_SHIFT        (29U)
#define VFCCU_0_FHDLRKC0_20_RKNEN27_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_20_RKNEN27(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_20_RKNEN27_SHIFT)) & VFCCU_0_FHDLRKC0_20_RKNEN27_MASK)

#define VFCCU_0_FHDLRKC0_20_RKNEN28_MASK         (0x40000000U)
#define VFCCU_0_FHDLRKC0_20_RKNEN28_SHIFT        (30U)
#define VFCCU_0_FHDLRKC0_20_RKNEN28_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_20_RKNEN28(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_20_RKNEN28_SHIFT)) & VFCCU_0_FHDLRKC0_20_RKNEN28_MASK)

#define VFCCU_0_FHDLRKC0_20_RKNEN29_MASK         (0x80000000U)
#define VFCCU_0_FHDLRKC0_20_RKNEN29_SHIFT        (31U)
#define VFCCU_0_FHDLRKC0_20_RKNEN29_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_20_RKNEN29(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_20_RKNEN29_SHIFT)) & VFCCU_0_FHDLRKC0_20_RKNEN29_MASK)
/*! @} */

/*! @name FHIMRKC0_30 - Immediate Reaction Configuration */
/*! @{ */

#define VFCCU_0_FHIMRKC0_30_EOUTEN0_MASK         (0x1U)
#define VFCCU_0_FHIMRKC0_30_EOUTEN0_SHIFT        (0U)
#define VFCCU_0_FHIMRKC0_30_EOUTEN0_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_30_EOUTEN0(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_30_EOUTEN0_SHIFT)) & VFCCU_0_FHIMRKC0_30_EOUTEN0_MASK)

#define VFCCU_0_FHIMRKC0_30_EOUTEN1_MASK         (0x2U)
#define VFCCU_0_FHIMRKC0_30_EOUTEN1_SHIFT        (1U)
#define VFCCU_0_FHIMRKC0_30_EOUTEN1_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_30_EOUTEN1(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_30_EOUTEN1_SHIFT)) & VFCCU_0_FHIMRKC0_30_EOUTEN1_MASK)

#define VFCCU_0_FHIMRKC0_30_RKNEN0_MASK          (0x4U)
#define VFCCU_0_FHIMRKC0_30_RKNEN0_SHIFT         (2U)
#define VFCCU_0_FHIMRKC0_30_RKNEN0_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_30_RKNEN0(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_30_RKNEN0_SHIFT)) & VFCCU_0_FHIMRKC0_30_RKNEN0_MASK)

#define VFCCU_0_FHIMRKC0_30_RKNEN1_MASK          (0x8U)
#define VFCCU_0_FHIMRKC0_30_RKNEN1_SHIFT         (3U)
#define VFCCU_0_FHIMRKC0_30_RKNEN1_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_30_RKNEN1(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_30_RKNEN1_SHIFT)) & VFCCU_0_FHIMRKC0_30_RKNEN1_MASK)

#define VFCCU_0_FHIMRKC0_30_RKNEN2_MASK          (0x10U)
#define VFCCU_0_FHIMRKC0_30_RKNEN2_SHIFT         (4U)
#define VFCCU_0_FHIMRKC0_30_RKNEN2_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_30_RKNEN2(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_30_RKNEN2_SHIFT)) & VFCCU_0_FHIMRKC0_30_RKNEN2_MASK)

#define VFCCU_0_FHIMRKC0_30_RKNEN3_MASK          (0x20U)
#define VFCCU_0_FHIMRKC0_30_RKNEN3_SHIFT         (5U)
#define VFCCU_0_FHIMRKC0_30_RKNEN3_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_30_RKNEN3(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_30_RKNEN3_SHIFT)) & VFCCU_0_FHIMRKC0_30_RKNEN3_MASK)

#define VFCCU_0_FHIMRKC0_30_RKNEN4_MASK          (0x40U)
#define VFCCU_0_FHIMRKC0_30_RKNEN4_SHIFT         (6U)
#define VFCCU_0_FHIMRKC0_30_RKNEN4_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_30_RKNEN4(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_30_RKNEN4_SHIFT)) & VFCCU_0_FHIMRKC0_30_RKNEN4_MASK)

#define VFCCU_0_FHIMRKC0_30_RKNEN5_MASK          (0x80U)
#define VFCCU_0_FHIMRKC0_30_RKNEN5_SHIFT         (7U)
#define VFCCU_0_FHIMRKC0_30_RKNEN5_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_30_RKNEN5(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_30_RKNEN5_SHIFT)) & VFCCU_0_FHIMRKC0_30_RKNEN5_MASK)

#define VFCCU_0_FHIMRKC0_30_RKNEN6_MASK          (0x100U)
#define VFCCU_0_FHIMRKC0_30_RKNEN6_SHIFT         (8U)
#define VFCCU_0_FHIMRKC0_30_RKNEN6_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_30_RKNEN6(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_30_RKNEN6_SHIFT)) & VFCCU_0_FHIMRKC0_30_RKNEN6_MASK)

#define VFCCU_0_FHIMRKC0_30_RKNEN7_MASK          (0x200U)
#define VFCCU_0_FHIMRKC0_30_RKNEN7_SHIFT         (9U)
#define VFCCU_0_FHIMRKC0_30_RKNEN7_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_30_RKNEN7(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_30_RKNEN7_SHIFT)) & VFCCU_0_FHIMRKC0_30_RKNEN7_MASK)

#define VFCCU_0_FHIMRKC0_30_RKNEN8_MASK          (0x400U)
#define VFCCU_0_FHIMRKC0_30_RKNEN8_SHIFT         (10U)
#define VFCCU_0_FHIMRKC0_30_RKNEN8_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_30_RKNEN8(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_30_RKNEN8_SHIFT)) & VFCCU_0_FHIMRKC0_30_RKNEN8_MASK)

#define VFCCU_0_FHIMRKC0_30_RKNEN9_MASK          (0x800U)
#define VFCCU_0_FHIMRKC0_30_RKNEN9_SHIFT         (11U)
#define VFCCU_0_FHIMRKC0_30_RKNEN9_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_30_RKNEN9(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_30_RKNEN9_SHIFT)) & VFCCU_0_FHIMRKC0_30_RKNEN9_MASK)

#define VFCCU_0_FHIMRKC0_30_RKNEN10_MASK         (0x1000U)
#define VFCCU_0_FHIMRKC0_30_RKNEN10_SHIFT        (12U)
#define VFCCU_0_FHIMRKC0_30_RKNEN10_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_30_RKNEN10(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_30_RKNEN10_SHIFT)) & VFCCU_0_FHIMRKC0_30_RKNEN10_MASK)

#define VFCCU_0_FHIMRKC0_30_RKNEN11_MASK         (0x2000U)
#define VFCCU_0_FHIMRKC0_30_RKNEN11_SHIFT        (13U)
#define VFCCU_0_FHIMRKC0_30_RKNEN11_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_30_RKNEN11(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_30_RKNEN11_SHIFT)) & VFCCU_0_FHIMRKC0_30_RKNEN11_MASK)

#define VFCCU_0_FHIMRKC0_30_RKNEN12_MASK         (0x4000U)
#define VFCCU_0_FHIMRKC0_30_RKNEN12_SHIFT        (14U)
#define VFCCU_0_FHIMRKC0_30_RKNEN12_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_30_RKNEN12(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_30_RKNEN12_SHIFT)) & VFCCU_0_FHIMRKC0_30_RKNEN12_MASK)

#define VFCCU_0_FHIMRKC0_30_RKNEN13_MASK         (0x8000U)
#define VFCCU_0_FHIMRKC0_30_RKNEN13_SHIFT        (15U)
#define VFCCU_0_FHIMRKC0_30_RKNEN13_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_30_RKNEN13(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_30_RKNEN13_SHIFT)) & VFCCU_0_FHIMRKC0_30_RKNEN13_MASK)

#define VFCCU_0_FHIMRKC0_30_RKNEN14_MASK         (0x10000U)
#define VFCCU_0_FHIMRKC0_30_RKNEN14_SHIFT        (16U)
#define VFCCU_0_FHIMRKC0_30_RKNEN14_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_30_RKNEN14(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_30_RKNEN14_SHIFT)) & VFCCU_0_FHIMRKC0_30_RKNEN14_MASK)

#define VFCCU_0_FHIMRKC0_30_RKNEN15_MASK         (0x20000U)
#define VFCCU_0_FHIMRKC0_30_RKNEN15_SHIFT        (17U)
#define VFCCU_0_FHIMRKC0_30_RKNEN15_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_30_RKNEN15(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_30_RKNEN15_SHIFT)) & VFCCU_0_FHIMRKC0_30_RKNEN15_MASK)

#define VFCCU_0_FHIMRKC0_30_RKNEN16_MASK         (0x40000U)
#define VFCCU_0_FHIMRKC0_30_RKNEN16_SHIFT        (18U)
#define VFCCU_0_FHIMRKC0_30_RKNEN16_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_30_RKNEN16(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_30_RKNEN16_SHIFT)) & VFCCU_0_FHIMRKC0_30_RKNEN16_MASK)

#define VFCCU_0_FHIMRKC0_30_RKNEN17_MASK         (0x80000U)
#define VFCCU_0_FHIMRKC0_30_RKNEN17_SHIFT        (19U)
#define VFCCU_0_FHIMRKC0_30_RKNEN17_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_30_RKNEN17(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_30_RKNEN17_SHIFT)) & VFCCU_0_FHIMRKC0_30_RKNEN17_MASK)

#define VFCCU_0_FHIMRKC0_30_RKNEN18_MASK         (0x100000U)
#define VFCCU_0_FHIMRKC0_30_RKNEN18_SHIFT        (20U)
#define VFCCU_0_FHIMRKC0_30_RKNEN18_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_30_RKNEN18(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_30_RKNEN18_SHIFT)) & VFCCU_0_FHIMRKC0_30_RKNEN18_MASK)

#define VFCCU_0_FHIMRKC0_30_RKNEN19_MASK         (0x200000U)
#define VFCCU_0_FHIMRKC0_30_RKNEN19_SHIFT        (21U)
#define VFCCU_0_FHIMRKC0_30_RKNEN19_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_30_RKNEN19(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_30_RKNEN19_SHIFT)) & VFCCU_0_FHIMRKC0_30_RKNEN19_MASK)

#define VFCCU_0_FHIMRKC0_30_RKNEN20_MASK         (0x400000U)
#define VFCCU_0_FHIMRKC0_30_RKNEN20_SHIFT        (22U)
#define VFCCU_0_FHIMRKC0_30_RKNEN20_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_30_RKNEN20(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_30_RKNEN20_SHIFT)) & VFCCU_0_FHIMRKC0_30_RKNEN20_MASK)

#define VFCCU_0_FHIMRKC0_30_RKNEN21_MASK         (0x800000U)
#define VFCCU_0_FHIMRKC0_30_RKNEN21_SHIFT        (23U)
#define VFCCU_0_FHIMRKC0_30_RKNEN21_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_30_RKNEN21(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_30_RKNEN21_SHIFT)) & VFCCU_0_FHIMRKC0_30_RKNEN21_MASK)

#define VFCCU_0_FHIMRKC0_30_RKNEN22_MASK         (0x1000000U)
#define VFCCU_0_FHIMRKC0_30_RKNEN22_SHIFT        (24U)
#define VFCCU_0_FHIMRKC0_30_RKNEN22_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_30_RKNEN22(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_30_RKNEN22_SHIFT)) & VFCCU_0_FHIMRKC0_30_RKNEN22_MASK)

#define VFCCU_0_FHIMRKC0_30_RKNEN23_MASK         (0x2000000U)
#define VFCCU_0_FHIMRKC0_30_RKNEN23_SHIFT        (25U)
#define VFCCU_0_FHIMRKC0_30_RKNEN23_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_30_RKNEN23(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_30_RKNEN23_SHIFT)) & VFCCU_0_FHIMRKC0_30_RKNEN23_MASK)

#define VFCCU_0_FHIMRKC0_30_RKNEN24_MASK         (0x4000000U)
#define VFCCU_0_FHIMRKC0_30_RKNEN24_SHIFT        (26U)
#define VFCCU_0_FHIMRKC0_30_RKNEN24_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_30_RKNEN24(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_30_RKNEN24_SHIFT)) & VFCCU_0_FHIMRKC0_30_RKNEN24_MASK)

#define VFCCU_0_FHIMRKC0_30_RKNEN25_MASK         (0x8000000U)
#define VFCCU_0_FHIMRKC0_30_RKNEN25_SHIFT        (27U)
#define VFCCU_0_FHIMRKC0_30_RKNEN25_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_30_RKNEN25(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_30_RKNEN25_SHIFT)) & VFCCU_0_FHIMRKC0_30_RKNEN25_MASK)

#define VFCCU_0_FHIMRKC0_30_RKNEN26_MASK         (0x10000000U)
#define VFCCU_0_FHIMRKC0_30_RKNEN26_SHIFT        (28U)
#define VFCCU_0_FHIMRKC0_30_RKNEN26_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_30_RKNEN26(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_30_RKNEN26_SHIFT)) & VFCCU_0_FHIMRKC0_30_RKNEN26_MASK)

#define VFCCU_0_FHIMRKC0_30_RKNEN27_MASK         (0x20000000U)
#define VFCCU_0_FHIMRKC0_30_RKNEN27_SHIFT        (29U)
#define VFCCU_0_FHIMRKC0_30_RKNEN27_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_30_RKNEN27(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_30_RKNEN27_SHIFT)) & VFCCU_0_FHIMRKC0_30_RKNEN27_MASK)

#define VFCCU_0_FHIMRKC0_30_RKNEN28_MASK         (0x40000000U)
#define VFCCU_0_FHIMRKC0_30_RKNEN28_SHIFT        (30U)
#define VFCCU_0_FHIMRKC0_30_RKNEN28_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_30_RKNEN28(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_30_RKNEN28_SHIFT)) & VFCCU_0_FHIMRKC0_30_RKNEN28_MASK)

#define VFCCU_0_FHIMRKC0_30_RKNEN29_MASK         (0x80000000U)
#define VFCCU_0_FHIMRKC0_30_RKNEN29_SHIFT        (31U)
#define VFCCU_0_FHIMRKC0_30_RKNEN29_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_30_RKNEN29(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_30_RKNEN29_SHIFT)) & VFCCU_0_FHIMRKC0_30_RKNEN29_MASK)
/*! @} */

/*! @name FHDLRKC0_30 - Delayed Reaction Configuration */
/*! @{ */

#define VFCCU_0_FHDLRKC0_30_EOUTEN0_MASK         (0x1U)
#define VFCCU_0_FHDLRKC0_30_EOUTEN0_SHIFT        (0U)
#define VFCCU_0_FHDLRKC0_30_EOUTEN0_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_30_EOUTEN0(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_30_EOUTEN0_SHIFT)) & VFCCU_0_FHDLRKC0_30_EOUTEN0_MASK)

#define VFCCU_0_FHDLRKC0_30_EOUTEN1_MASK         (0x2U)
#define VFCCU_0_FHDLRKC0_30_EOUTEN1_SHIFT        (1U)
#define VFCCU_0_FHDLRKC0_30_EOUTEN1_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_30_EOUTEN1(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_30_EOUTEN1_SHIFT)) & VFCCU_0_FHDLRKC0_30_EOUTEN1_MASK)

#define VFCCU_0_FHDLRKC0_30_RKNEN0_MASK          (0x4U)
#define VFCCU_0_FHDLRKC0_30_RKNEN0_SHIFT         (2U)
#define VFCCU_0_FHDLRKC0_30_RKNEN0_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_30_RKNEN0(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_30_RKNEN0_SHIFT)) & VFCCU_0_FHDLRKC0_30_RKNEN0_MASK)

#define VFCCU_0_FHDLRKC0_30_RKNEN1_MASK          (0x8U)
#define VFCCU_0_FHDLRKC0_30_RKNEN1_SHIFT         (3U)
#define VFCCU_0_FHDLRKC0_30_RKNEN1_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_30_RKNEN1(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_30_RKNEN1_SHIFT)) & VFCCU_0_FHDLRKC0_30_RKNEN1_MASK)

#define VFCCU_0_FHDLRKC0_30_RKNEN2_MASK          (0x10U)
#define VFCCU_0_FHDLRKC0_30_RKNEN2_SHIFT         (4U)
#define VFCCU_0_FHDLRKC0_30_RKNEN2_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_30_RKNEN2(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_30_RKNEN2_SHIFT)) & VFCCU_0_FHDLRKC0_30_RKNEN2_MASK)

#define VFCCU_0_FHDLRKC0_30_RKNEN3_MASK          (0x20U)
#define VFCCU_0_FHDLRKC0_30_RKNEN3_SHIFT         (5U)
#define VFCCU_0_FHDLRKC0_30_RKNEN3_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_30_RKNEN3(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_30_RKNEN3_SHIFT)) & VFCCU_0_FHDLRKC0_30_RKNEN3_MASK)

#define VFCCU_0_FHDLRKC0_30_RKNEN4_MASK          (0x40U)
#define VFCCU_0_FHDLRKC0_30_RKNEN4_SHIFT         (6U)
#define VFCCU_0_FHDLRKC0_30_RKNEN4_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_30_RKNEN4(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_30_RKNEN4_SHIFT)) & VFCCU_0_FHDLRKC0_30_RKNEN4_MASK)

#define VFCCU_0_FHDLRKC0_30_RKNEN5_MASK          (0x80U)
#define VFCCU_0_FHDLRKC0_30_RKNEN5_SHIFT         (7U)
#define VFCCU_0_FHDLRKC0_30_RKNEN5_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_30_RKNEN5(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_30_RKNEN5_SHIFT)) & VFCCU_0_FHDLRKC0_30_RKNEN5_MASK)

#define VFCCU_0_FHDLRKC0_30_RKNEN6_MASK          (0x100U)
#define VFCCU_0_FHDLRKC0_30_RKNEN6_SHIFT         (8U)
#define VFCCU_0_FHDLRKC0_30_RKNEN6_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_30_RKNEN6(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_30_RKNEN6_SHIFT)) & VFCCU_0_FHDLRKC0_30_RKNEN6_MASK)

#define VFCCU_0_FHDLRKC0_30_RKNEN7_MASK          (0x200U)
#define VFCCU_0_FHDLRKC0_30_RKNEN7_SHIFT         (9U)
#define VFCCU_0_FHDLRKC0_30_RKNEN7_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_30_RKNEN7(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_30_RKNEN7_SHIFT)) & VFCCU_0_FHDLRKC0_30_RKNEN7_MASK)

#define VFCCU_0_FHDLRKC0_30_RKNEN8_MASK          (0x400U)
#define VFCCU_0_FHDLRKC0_30_RKNEN8_SHIFT         (10U)
#define VFCCU_0_FHDLRKC0_30_RKNEN8_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_30_RKNEN8(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_30_RKNEN8_SHIFT)) & VFCCU_0_FHDLRKC0_30_RKNEN8_MASK)

#define VFCCU_0_FHDLRKC0_30_RKNEN9_MASK          (0x800U)
#define VFCCU_0_FHDLRKC0_30_RKNEN9_SHIFT         (11U)
#define VFCCU_0_FHDLRKC0_30_RKNEN9_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_30_RKNEN9(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_30_RKNEN9_SHIFT)) & VFCCU_0_FHDLRKC0_30_RKNEN9_MASK)

#define VFCCU_0_FHDLRKC0_30_RKNEN10_MASK         (0x1000U)
#define VFCCU_0_FHDLRKC0_30_RKNEN10_SHIFT        (12U)
#define VFCCU_0_FHDLRKC0_30_RKNEN10_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_30_RKNEN10(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_30_RKNEN10_SHIFT)) & VFCCU_0_FHDLRKC0_30_RKNEN10_MASK)

#define VFCCU_0_FHDLRKC0_30_RKNEN11_MASK         (0x2000U)
#define VFCCU_0_FHDLRKC0_30_RKNEN11_SHIFT        (13U)
#define VFCCU_0_FHDLRKC0_30_RKNEN11_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_30_RKNEN11(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_30_RKNEN11_SHIFT)) & VFCCU_0_FHDLRKC0_30_RKNEN11_MASK)

#define VFCCU_0_FHDLRKC0_30_RKNEN12_MASK         (0x4000U)
#define VFCCU_0_FHDLRKC0_30_RKNEN12_SHIFT        (14U)
#define VFCCU_0_FHDLRKC0_30_RKNEN12_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_30_RKNEN12(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_30_RKNEN12_SHIFT)) & VFCCU_0_FHDLRKC0_30_RKNEN12_MASK)

#define VFCCU_0_FHDLRKC0_30_RKNEN13_MASK         (0x8000U)
#define VFCCU_0_FHDLRKC0_30_RKNEN13_SHIFT        (15U)
#define VFCCU_0_FHDLRKC0_30_RKNEN13_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_30_RKNEN13(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_30_RKNEN13_SHIFT)) & VFCCU_0_FHDLRKC0_30_RKNEN13_MASK)

#define VFCCU_0_FHDLRKC0_30_RKNEN14_MASK         (0x10000U)
#define VFCCU_0_FHDLRKC0_30_RKNEN14_SHIFT        (16U)
#define VFCCU_0_FHDLRKC0_30_RKNEN14_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_30_RKNEN14(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_30_RKNEN14_SHIFT)) & VFCCU_0_FHDLRKC0_30_RKNEN14_MASK)

#define VFCCU_0_FHDLRKC0_30_RKNEN15_MASK         (0x20000U)
#define VFCCU_0_FHDLRKC0_30_RKNEN15_SHIFT        (17U)
#define VFCCU_0_FHDLRKC0_30_RKNEN15_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_30_RKNEN15(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_30_RKNEN15_SHIFT)) & VFCCU_0_FHDLRKC0_30_RKNEN15_MASK)

#define VFCCU_0_FHDLRKC0_30_RKNEN16_MASK         (0x40000U)
#define VFCCU_0_FHDLRKC0_30_RKNEN16_SHIFT        (18U)
#define VFCCU_0_FHDLRKC0_30_RKNEN16_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_30_RKNEN16(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_30_RKNEN16_SHIFT)) & VFCCU_0_FHDLRKC0_30_RKNEN16_MASK)

#define VFCCU_0_FHDLRKC0_30_RKNEN17_MASK         (0x80000U)
#define VFCCU_0_FHDLRKC0_30_RKNEN17_SHIFT        (19U)
#define VFCCU_0_FHDLRKC0_30_RKNEN17_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_30_RKNEN17(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_30_RKNEN17_SHIFT)) & VFCCU_0_FHDLRKC0_30_RKNEN17_MASK)

#define VFCCU_0_FHDLRKC0_30_RKNEN18_MASK         (0x100000U)
#define VFCCU_0_FHDLRKC0_30_RKNEN18_SHIFT        (20U)
#define VFCCU_0_FHDLRKC0_30_RKNEN18_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_30_RKNEN18(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_30_RKNEN18_SHIFT)) & VFCCU_0_FHDLRKC0_30_RKNEN18_MASK)

#define VFCCU_0_FHDLRKC0_30_RKNEN19_MASK         (0x200000U)
#define VFCCU_0_FHDLRKC0_30_RKNEN19_SHIFT        (21U)
#define VFCCU_0_FHDLRKC0_30_RKNEN19_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_30_RKNEN19(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_30_RKNEN19_SHIFT)) & VFCCU_0_FHDLRKC0_30_RKNEN19_MASK)

#define VFCCU_0_FHDLRKC0_30_RKNEN20_MASK         (0x400000U)
#define VFCCU_0_FHDLRKC0_30_RKNEN20_SHIFT        (22U)
#define VFCCU_0_FHDLRKC0_30_RKNEN20_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_30_RKNEN20(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_30_RKNEN20_SHIFT)) & VFCCU_0_FHDLRKC0_30_RKNEN20_MASK)

#define VFCCU_0_FHDLRKC0_30_RKNEN21_MASK         (0x800000U)
#define VFCCU_0_FHDLRKC0_30_RKNEN21_SHIFT        (23U)
#define VFCCU_0_FHDLRKC0_30_RKNEN21_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_30_RKNEN21(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_30_RKNEN21_SHIFT)) & VFCCU_0_FHDLRKC0_30_RKNEN21_MASK)

#define VFCCU_0_FHDLRKC0_30_RKNEN22_MASK         (0x1000000U)
#define VFCCU_0_FHDLRKC0_30_RKNEN22_SHIFT        (24U)
#define VFCCU_0_FHDLRKC0_30_RKNEN22_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_30_RKNEN22(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_30_RKNEN22_SHIFT)) & VFCCU_0_FHDLRKC0_30_RKNEN22_MASK)

#define VFCCU_0_FHDLRKC0_30_RKNEN23_MASK         (0x2000000U)
#define VFCCU_0_FHDLRKC0_30_RKNEN23_SHIFT        (25U)
#define VFCCU_0_FHDLRKC0_30_RKNEN23_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_30_RKNEN23(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_30_RKNEN23_SHIFT)) & VFCCU_0_FHDLRKC0_30_RKNEN23_MASK)

#define VFCCU_0_FHDLRKC0_30_RKNEN24_MASK         (0x4000000U)
#define VFCCU_0_FHDLRKC0_30_RKNEN24_SHIFT        (26U)
#define VFCCU_0_FHDLRKC0_30_RKNEN24_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_30_RKNEN24(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_30_RKNEN24_SHIFT)) & VFCCU_0_FHDLRKC0_30_RKNEN24_MASK)

#define VFCCU_0_FHDLRKC0_30_RKNEN25_MASK         (0x8000000U)
#define VFCCU_0_FHDLRKC0_30_RKNEN25_SHIFT        (27U)
#define VFCCU_0_FHDLRKC0_30_RKNEN25_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_30_RKNEN25(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_30_RKNEN25_SHIFT)) & VFCCU_0_FHDLRKC0_30_RKNEN25_MASK)

#define VFCCU_0_FHDLRKC0_30_RKNEN26_MASK         (0x10000000U)
#define VFCCU_0_FHDLRKC0_30_RKNEN26_SHIFT        (28U)
#define VFCCU_0_FHDLRKC0_30_RKNEN26_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_30_RKNEN26(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_30_RKNEN26_SHIFT)) & VFCCU_0_FHDLRKC0_30_RKNEN26_MASK)

#define VFCCU_0_FHDLRKC0_30_RKNEN27_MASK         (0x20000000U)
#define VFCCU_0_FHDLRKC0_30_RKNEN27_SHIFT        (29U)
#define VFCCU_0_FHDLRKC0_30_RKNEN27_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_30_RKNEN27(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_30_RKNEN27_SHIFT)) & VFCCU_0_FHDLRKC0_30_RKNEN27_MASK)

#define VFCCU_0_FHDLRKC0_30_RKNEN28_MASK         (0x40000000U)
#define VFCCU_0_FHDLRKC0_30_RKNEN28_SHIFT        (30U)
#define VFCCU_0_FHDLRKC0_30_RKNEN28_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_30_RKNEN28(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_30_RKNEN28_SHIFT)) & VFCCU_0_FHDLRKC0_30_RKNEN28_MASK)

#define VFCCU_0_FHDLRKC0_30_RKNEN29_MASK         (0x80000000U)
#define VFCCU_0_FHDLRKC0_30_RKNEN29_SHIFT        (31U)
#define VFCCU_0_FHDLRKC0_30_RKNEN29_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_30_RKNEN29(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_30_RKNEN29_SHIFT)) & VFCCU_0_FHDLRKC0_30_RKNEN29_MASK)
/*! @} */

/*! @name FHIMRKC0_40 - Immediate Reaction Configuration */
/*! @{ */

#define VFCCU_0_FHIMRKC0_40_EOUTEN0_MASK         (0x1U)
#define VFCCU_0_FHIMRKC0_40_EOUTEN0_SHIFT        (0U)
#define VFCCU_0_FHIMRKC0_40_EOUTEN0_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_40_EOUTEN0(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_40_EOUTEN0_SHIFT)) & VFCCU_0_FHIMRKC0_40_EOUTEN0_MASK)

#define VFCCU_0_FHIMRKC0_40_EOUTEN1_MASK         (0x2U)
#define VFCCU_0_FHIMRKC0_40_EOUTEN1_SHIFT        (1U)
#define VFCCU_0_FHIMRKC0_40_EOUTEN1_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_40_EOUTEN1(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_40_EOUTEN1_SHIFT)) & VFCCU_0_FHIMRKC0_40_EOUTEN1_MASK)

#define VFCCU_0_FHIMRKC0_40_RKNEN0_MASK          (0x4U)
#define VFCCU_0_FHIMRKC0_40_RKNEN0_SHIFT         (2U)
#define VFCCU_0_FHIMRKC0_40_RKNEN0_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_40_RKNEN0(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_40_RKNEN0_SHIFT)) & VFCCU_0_FHIMRKC0_40_RKNEN0_MASK)

#define VFCCU_0_FHIMRKC0_40_RKNEN1_MASK          (0x8U)
#define VFCCU_0_FHIMRKC0_40_RKNEN1_SHIFT         (3U)
#define VFCCU_0_FHIMRKC0_40_RKNEN1_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_40_RKNEN1(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_40_RKNEN1_SHIFT)) & VFCCU_0_FHIMRKC0_40_RKNEN1_MASK)

#define VFCCU_0_FHIMRKC0_40_RKNEN2_MASK          (0x10U)
#define VFCCU_0_FHIMRKC0_40_RKNEN2_SHIFT         (4U)
#define VFCCU_0_FHIMRKC0_40_RKNEN2_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_40_RKNEN2(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_40_RKNEN2_SHIFT)) & VFCCU_0_FHIMRKC0_40_RKNEN2_MASK)

#define VFCCU_0_FHIMRKC0_40_RKNEN3_MASK          (0x20U)
#define VFCCU_0_FHIMRKC0_40_RKNEN3_SHIFT         (5U)
#define VFCCU_0_FHIMRKC0_40_RKNEN3_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_40_RKNEN3(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_40_RKNEN3_SHIFT)) & VFCCU_0_FHIMRKC0_40_RKNEN3_MASK)

#define VFCCU_0_FHIMRKC0_40_RKNEN4_MASK          (0x40U)
#define VFCCU_0_FHIMRKC0_40_RKNEN4_SHIFT         (6U)
#define VFCCU_0_FHIMRKC0_40_RKNEN4_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_40_RKNEN4(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_40_RKNEN4_SHIFT)) & VFCCU_0_FHIMRKC0_40_RKNEN4_MASK)

#define VFCCU_0_FHIMRKC0_40_RKNEN5_MASK          (0x80U)
#define VFCCU_0_FHIMRKC0_40_RKNEN5_SHIFT         (7U)
#define VFCCU_0_FHIMRKC0_40_RKNEN5_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_40_RKNEN5(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_40_RKNEN5_SHIFT)) & VFCCU_0_FHIMRKC0_40_RKNEN5_MASK)

#define VFCCU_0_FHIMRKC0_40_RKNEN6_MASK          (0x100U)
#define VFCCU_0_FHIMRKC0_40_RKNEN6_SHIFT         (8U)
#define VFCCU_0_FHIMRKC0_40_RKNEN6_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_40_RKNEN6(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_40_RKNEN6_SHIFT)) & VFCCU_0_FHIMRKC0_40_RKNEN6_MASK)

#define VFCCU_0_FHIMRKC0_40_RKNEN7_MASK          (0x200U)
#define VFCCU_0_FHIMRKC0_40_RKNEN7_SHIFT         (9U)
#define VFCCU_0_FHIMRKC0_40_RKNEN7_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_40_RKNEN7(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_40_RKNEN7_SHIFT)) & VFCCU_0_FHIMRKC0_40_RKNEN7_MASK)

#define VFCCU_0_FHIMRKC0_40_RKNEN8_MASK          (0x400U)
#define VFCCU_0_FHIMRKC0_40_RKNEN8_SHIFT         (10U)
#define VFCCU_0_FHIMRKC0_40_RKNEN8_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_40_RKNEN8(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_40_RKNEN8_SHIFT)) & VFCCU_0_FHIMRKC0_40_RKNEN8_MASK)

#define VFCCU_0_FHIMRKC0_40_RKNEN9_MASK          (0x800U)
#define VFCCU_0_FHIMRKC0_40_RKNEN9_SHIFT         (11U)
#define VFCCU_0_FHIMRKC0_40_RKNEN9_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_40_RKNEN9(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_40_RKNEN9_SHIFT)) & VFCCU_0_FHIMRKC0_40_RKNEN9_MASK)

#define VFCCU_0_FHIMRKC0_40_RKNEN10_MASK         (0x1000U)
#define VFCCU_0_FHIMRKC0_40_RKNEN10_SHIFT        (12U)
#define VFCCU_0_FHIMRKC0_40_RKNEN10_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_40_RKNEN10(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_40_RKNEN10_SHIFT)) & VFCCU_0_FHIMRKC0_40_RKNEN10_MASK)

#define VFCCU_0_FHIMRKC0_40_RKNEN11_MASK         (0x2000U)
#define VFCCU_0_FHIMRKC0_40_RKNEN11_SHIFT        (13U)
#define VFCCU_0_FHIMRKC0_40_RKNEN11_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_40_RKNEN11(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_40_RKNEN11_SHIFT)) & VFCCU_0_FHIMRKC0_40_RKNEN11_MASK)

#define VFCCU_0_FHIMRKC0_40_RKNEN12_MASK         (0x4000U)
#define VFCCU_0_FHIMRKC0_40_RKNEN12_SHIFT        (14U)
#define VFCCU_0_FHIMRKC0_40_RKNEN12_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_40_RKNEN12(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_40_RKNEN12_SHIFT)) & VFCCU_0_FHIMRKC0_40_RKNEN12_MASK)

#define VFCCU_0_FHIMRKC0_40_RKNEN13_MASK         (0x8000U)
#define VFCCU_0_FHIMRKC0_40_RKNEN13_SHIFT        (15U)
#define VFCCU_0_FHIMRKC0_40_RKNEN13_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_40_RKNEN13(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_40_RKNEN13_SHIFT)) & VFCCU_0_FHIMRKC0_40_RKNEN13_MASK)

#define VFCCU_0_FHIMRKC0_40_RKNEN14_MASK         (0x10000U)
#define VFCCU_0_FHIMRKC0_40_RKNEN14_SHIFT        (16U)
#define VFCCU_0_FHIMRKC0_40_RKNEN14_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_40_RKNEN14(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_40_RKNEN14_SHIFT)) & VFCCU_0_FHIMRKC0_40_RKNEN14_MASK)

#define VFCCU_0_FHIMRKC0_40_RKNEN15_MASK         (0x20000U)
#define VFCCU_0_FHIMRKC0_40_RKNEN15_SHIFT        (17U)
#define VFCCU_0_FHIMRKC0_40_RKNEN15_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_40_RKNEN15(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_40_RKNEN15_SHIFT)) & VFCCU_0_FHIMRKC0_40_RKNEN15_MASK)

#define VFCCU_0_FHIMRKC0_40_RKNEN16_MASK         (0x40000U)
#define VFCCU_0_FHIMRKC0_40_RKNEN16_SHIFT        (18U)
#define VFCCU_0_FHIMRKC0_40_RKNEN16_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_40_RKNEN16(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_40_RKNEN16_SHIFT)) & VFCCU_0_FHIMRKC0_40_RKNEN16_MASK)

#define VFCCU_0_FHIMRKC0_40_RKNEN17_MASK         (0x80000U)
#define VFCCU_0_FHIMRKC0_40_RKNEN17_SHIFT        (19U)
#define VFCCU_0_FHIMRKC0_40_RKNEN17_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_40_RKNEN17(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_40_RKNEN17_SHIFT)) & VFCCU_0_FHIMRKC0_40_RKNEN17_MASK)

#define VFCCU_0_FHIMRKC0_40_RKNEN18_MASK         (0x100000U)
#define VFCCU_0_FHIMRKC0_40_RKNEN18_SHIFT        (20U)
#define VFCCU_0_FHIMRKC0_40_RKNEN18_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_40_RKNEN18(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_40_RKNEN18_SHIFT)) & VFCCU_0_FHIMRKC0_40_RKNEN18_MASK)

#define VFCCU_0_FHIMRKC0_40_RKNEN19_MASK         (0x200000U)
#define VFCCU_0_FHIMRKC0_40_RKNEN19_SHIFT        (21U)
#define VFCCU_0_FHIMRKC0_40_RKNEN19_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_40_RKNEN19(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_40_RKNEN19_SHIFT)) & VFCCU_0_FHIMRKC0_40_RKNEN19_MASK)

#define VFCCU_0_FHIMRKC0_40_RKNEN20_MASK         (0x400000U)
#define VFCCU_0_FHIMRKC0_40_RKNEN20_SHIFT        (22U)
#define VFCCU_0_FHIMRKC0_40_RKNEN20_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_40_RKNEN20(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_40_RKNEN20_SHIFT)) & VFCCU_0_FHIMRKC0_40_RKNEN20_MASK)

#define VFCCU_0_FHIMRKC0_40_RKNEN21_MASK         (0x800000U)
#define VFCCU_0_FHIMRKC0_40_RKNEN21_SHIFT        (23U)
#define VFCCU_0_FHIMRKC0_40_RKNEN21_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_40_RKNEN21(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_40_RKNEN21_SHIFT)) & VFCCU_0_FHIMRKC0_40_RKNEN21_MASK)

#define VFCCU_0_FHIMRKC0_40_RKNEN22_MASK         (0x1000000U)
#define VFCCU_0_FHIMRKC0_40_RKNEN22_SHIFT        (24U)
#define VFCCU_0_FHIMRKC0_40_RKNEN22_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_40_RKNEN22(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_40_RKNEN22_SHIFT)) & VFCCU_0_FHIMRKC0_40_RKNEN22_MASK)

#define VFCCU_0_FHIMRKC0_40_RKNEN23_MASK         (0x2000000U)
#define VFCCU_0_FHIMRKC0_40_RKNEN23_SHIFT        (25U)
#define VFCCU_0_FHIMRKC0_40_RKNEN23_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_40_RKNEN23(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_40_RKNEN23_SHIFT)) & VFCCU_0_FHIMRKC0_40_RKNEN23_MASK)

#define VFCCU_0_FHIMRKC0_40_RKNEN24_MASK         (0x4000000U)
#define VFCCU_0_FHIMRKC0_40_RKNEN24_SHIFT        (26U)
#define VFCCU_0_FHIMRKC0_40_RKNEN24_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_40_RKNEN24(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_40_RKNEN24_SHIFT)) & VFCCU_0_FHIMRKC0_40_RKNEN24_MASK)

#define VFCCU_0_FHIMRKC0_40_RKNEN25_MASK         (0x8000000U)
#define VFCCU_0_FHIMRKC0_40_RKNEN25_SHIFT        (27U)
#define VFCCU_0_FHIMRKC0_40_RKNEN25_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_40_RKNEN25(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_40_RKNEN25_SHIFT)) & VFCCU_0_FHIMRKC0_40_RKNEN25_MASK)

#define VFCCU_0_FHIMRKC0_40_RKNEN26_MASK         (0x10000000U)
#define VFCCU_0_FHIMRKC0_40_RKNEN26_SHIFT        (28U)
#define VFCCU_0_FHIMRKC0_40_RKNEN26_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_40_RKNEN26(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_40_RKNEN26_SHIFT)) & VFCCU_0_FHIMRKC0_40_RKNEN26_MASK)

#define VFCCU_0_FHIMRKC0_40_RKNEN27_MASK         (0x20000000U)
#define VFCCU_0_FHIMRKC0_40_RKNEN27_SHIFT        (29U)
#define VFCCU_0_FHIMRKC0_40_RKNEN27_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_40_RKNEN27(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_40_RKNEN27_SHIFT)) & VFCCU_0_FHIMRKC0_40_RKNEN27_MASK)

#define VFCCU_0_FHIMRKC0_40_RKNEN28_MASK         (0x40000000U)
#define VFCCU_0_FHIMRKC0_40_RKNEN28_SHIFT        (30U)
#define VFCCU_0_FHIMRKC0_40_RKNEN28_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_40_RKNEN28(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_40_RKNEN28_SHIFT)) & VFCCU_0_FHIMRKC0_40_RKNEN28_MASK)

#define VFCCU_0_FHIMRKC0_40_RKNEN29_MASK         (0x80000000U)
#define VFCCU_0_FHIMRKC0_40_RKNEN29_SHIFT        (31U)
#define VFCCU_0_FHIMRKC0_40_RKNEN29_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_40_RKNEN29(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_40_RKNEN29_SHIFT)) & VFCCU_0_FHIMRKC0_40_RKNEN29_MASK)
/*! @} */

/*! @name FHDLRKC0_40 - Delayed Reaction Configuration */
/*! @{ */

#define VFCCU_0_FHDLRKC0_40_EOUTEN0_MASK         (0x1U)
#define VFCCU_0_FHDLRKC0_40_EOUTEN0_SHIFT        (0U)
#define VFCCU_0_FHDLRKC0_40_EOUTEN0_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_40_EOUTEN0(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_40_EOUTEN0_SHIFT)) & VFCCU_0_FHDLRKC0_40_EOUTEN0_MASK)

#define VFCCU_0_FHDLRKC0_40_EOUTEN1_MASK         (0x2U)
#define VFCCU_0_FHDLRKC0_40_EOUTEN1_SHIFT        (1U)
#define VFCCU_0_FHDLRKC0_40_EOUTEN1_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_40_EOUTEN1(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_40_EOUTEN1_SHIFT)) & VFCCU_0_FHDLRKC0_40_EOUTEN1_MASK)

#define VFCCU_0_FHDLRKC0_40_RKNEN0_MASK          (0x4U)
#define VFCCU_0_FHDLRKC0_40_RKNEN0_SHIFT         (2U)
#define VFCCU_0_FHDLRKC0_40_RKNEN0_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_40_RKNEN0(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_40_RKNEN0_SHIFT)) & VFCCU_0_FHDLRKC0_40_RKNEN0_MASK)

#define VFCCU_0_FHDLRKC0_40_RKNEN1_MASK          (0x8U)
#define VFCCU_0_FHDLRKC0_40_RKNEN1_SHIFT         (3U)
#define VFCCU_0_FHDLRKC0_40_RKNEN1_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_40_RKNEN1(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_40_RKNEN1_SHIFT)) & VFCCU_0_FHDLRKC0_40_RKNEN1_MASK)

#define VFCCU_0_FHDLRKC0_40_RKNEN2_MASK          (0x10U)
#define VFCCU_0_FHDLRKC0_40_RKNEN2_SHIFT         (4U)
#define VFCCU_0_FHDLRKC0_40_RKNEN2_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_40_RKNEN2(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_40_RKNEN2_SHIFT)) & VFCCU_0_FHDLRKC0_40_RKNEN2_MASK)

#define VFCCU_0_FHDLRKC0_40_RKNEN3_MASK          (0x20U)
#define VFCCU_0_FHDLRKC0_40_RKNEN3_SHIFT         (5U)
#define VFCCU_0_FHDLRKC0_40_RKNEN3_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_40_RKNEN3(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_40_RKNEN3_SHIFT)) & VFCCU_0_FHDLRKC0_40_RKNEN3_MASK)

#define VFCCU_0_FHDLRKC0_40_RKNEN4_MASK          (0x40U)
#define VFCCU_0_FHDLRKC0_40_RKNEN4_SHIFT         (6U)
#define VFCCU_0_FHDLRKC0_40_RKNEN4_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_40_RKNEN4(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_40_RKNEN4_SHIFT)) & VFCCU_0_FHDLRKC0_40_RKNEN4_MASK)

#define VFCCU_0_FHDLRKC0_40_RKNEN5_MASK          (0x80U)
#define VFCCU_0_FHDLRKC0_40_RKNEN5_SHIFT         (7U)
#define VFCCU_0_FHDLRKC0_40_RKNEN5_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_40_RKNEN5(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_40_RKNEN5_SHIFT)) & VFCCU_0_FHDLRKC0_40_RKNEN5_MASK)

#define VFCCU_0_FHDLRKC0_40_RKNEN6_MASK          (0x100U)
#define VFCCU_0_FHDLRKC0_40_RKNEN6_SHIFT         (8U)
#define VFCCU_0_FHDLRKC0_40_RKNEN6_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_40_RKNEN6(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_40_RKNEN6_SHIFT)) & VFCCU_0_FHDLRKC0_40_RKNEN6_MASK)

#define VFCCU_0_FHDLRKC0_40_RKNEN7_MASK          (0x200U)
#define VFCCU_0_FHDLRKC0_40_RKNEN7_SHIFT         (9U)
#define VFCCU_0_FHDLRKC0_40_RKNEN7_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_40_RKNEN7(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_40_RKNEN7_SHIFT)) & VFCCU_0_FHDLRKC0_40_RKNEN7_MASK)

#define VFCCU_0_FHDLRKC0_40_RKNEN8_MASK          (0x400U)
#define VFCCU_0_FHDLRKC0_40_RKNEN8_SHIFT         (10U)
#define VFCCU_0_FHDLRKC0_40_RKNEN8_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_40_RKNEN8(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_40_RKNEN8_SHIFT)) & VFCCU_0_FHDLRKC0_40_RKNEN8_MASK)

#define VFCCU_0_FHDLRKC0_40_RKNEN9_MASK          (0x800U)
#define VFCCU_0_FHDLRKC0_40_RKNEN9_SHIFT         (11U)
#define VFCCU_0_FHDLRKC0_40_RKNEN9_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_40_RKNEN9(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_40_RKNEN9_SHIFT)) & VFCCU_0_FHDLRKC0_40_RKNEN9_MASK)

#define VFCCU_0_FHDLRKC0_40_RKNEN10_MASK         (0x1000U)
#define VFCCU_0_FHDLRKC0_40_RKNEN10_SHIFT        (12U)
#define VFCCU_0_FHDLRKC0_40_RKNEN10_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_40_RKNEN10(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_40_RKNEN10_SHIFT)) & VFCCU_0_FHDLRKC0_40_RKNEN10_MASK)

#define VFCCU_0_FHDLRKC0_40_RKNEN11_MASK         (0x2000U)
#define VFCCU_0_FHDLRKC0_40_RKNEN11_SHIFT        (13U)
#define VFCCU_0_FHDLRKC0_40_RKNEN11_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_40_RKNEN11(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_40_RKNEN11_SHIFT)) & VFCCU_0_FHDLRKC0_40_RKNEN11_MASK)

#define VFCCU_0_FHDLRKC0_40_RKNEN12_MASK         (0x4000U)
#define VFCCU_0_FHDLRKC0_40_RKNEN12_SHIFT        (14U)
#define VFCCU_0_FHDLRKC0_40_RKNEN12_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_40_RKNEN12(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_40_RKNEN12_SHIFT)) & VFCCU_0_FHDLRKC0_40_RKNEN12_MASK)

#define VFCCU_0_FHDLRKC0_40_RKNEN13_MASK         (0x8000U)
#define VFCCU_0_FHDLRKC0_40_RKNEN13_SHIFT        (15U)
#define VFCCU_0_FHDLRKC0_40_RKNEN13_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_40_RKNEN13(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_40_RKNEN13_SHIFT)) & VFCCU_0_FHDLRKC0_40_RKNEN13_MASK)

#define VFCCU_0_FHDLRKC0_40_RKNEN14_MASK         (0x10000U)
#define VFCCU_0_FHDLRKC0_40_RKNEN14_SHIFT        (16U)
#define VFCCU_0_FHDLRKC0_40_RKNEN14_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_40_RKNEN14(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_40_RKNEN14_SHIFT)) & VFCCU_0_FHDLRKC0_40_RKNEN14_MASK)

#define VFCCU_0_FHDLRKC0_40_RKNEN15_MASK         (0x20000U)
#define VFCCU_0_FHDLRKC0_40_RKNEN15_SHIFT        (17U)
#define VFCCU_0_FHDLRKC0_40_RKNEN15_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_40_RKNEN15(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_40_RKNEN15_SHIFT)) & VFCCU_0_FHDLRKC0_40_RKNEN15_MASK)

#define VFCCU_0_FHDLRKC0_40_RKNEN16_MASK         (0x40000U)
#define VFCCU_0_FHDLRKC0_40_RKNEN16_SHIFT        (18U)
#define VFCCU_0_FHDLRKC0_40_RKNEN16_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_40_RKNEN16(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_40_RKNEN16_SHIFT)) & VFCCU_0_FHDLRKC0_40_RKNEN16_MASK)

#define VFCCU_0_FHDLRKC0_40_RKNEN17_MASK         (0x80000U)
#define VFCCU_0_FHDLRKC0_40_RKNEN17_SHIFT        (19U)
#define VFCCU_0_FHDLRKC0_40_RKNEN17_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_40_RKNEN17(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_40_RKNEN17_SHIFT)) & VFCCU_0_FHDLRKC0_40_RKNEN17_MASK)

#define VFCCU_0_FHDLRKC0_40_RKNEN18_MASK         (0x100000U)
#define VFCCU_0_FHDLRKC0_40_RKNEN18_SHIFT        (20U)
#define VFCCU_0_FHDLRKC0_40_RKNEN18_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_40_RKNEN18(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_40_RKNEN18_SHIFT)) & VFCCU_0_FHDLRKC0_40_RKNEN18_MASK)

#define VFCCU_0_FHDLRKC0_40_RKNEN19_MASK         (0x200000U)
#define VFCCU_0_FHDLRKC0_40_RKNEN19_SHIFT        (21U)
#define VFCCU_0_FHDLRKC0_40_RKNEN19_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_40_RKNEN19(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_40_RKNEN19_SHIFT)) & VFCCU_0_FHDLRKC0_40_RKNEN19_MASK)

#define VFCCU_0_FHDLRKC0_40_RKNEN20_MASK         (0x400000U)
#define VFCCU_0_FHDLRKC0_40_RKNEN20_SHIFT        (22U)
#define VFCCU_0_FHDLRKC0_40_RKNEN20_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_40_RKNEN20(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_40_RKNEN20_SHIFT)) & VFCCU_0_FHDLRKC0_40_RKNEN20_MASK)

#define VFCCU_0_FHDLRKC0_40_RKNEN21_MASK         (0x800000U)
#define VFCCU_0_FHDLRKC0_40_RKNEN21_SHIFT        (23U)
#define VFCCU_0_FHDLRKC0_40_RKNEN21_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_40_RKNEN21(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_40_RKNEN21_SHIFT)) & VFCCU_0_FHDLRKC0_40_RKNEN21_MASK)

#define VFCCU_0_FHDLRKC0_40_RKNEN22_MASK         (0x1000000U)
#define VFCCU_0_FHDLRKC0_40_RKNEN22_SHIFT        (24U)
#define VFCCU_0_FHDLRKC0_40_RKNEN22_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_40_RKNEN22(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_40_RKNEN22_SHIFT)) & VFCCU_0_FHDLRKC0_40_RKNEN22_MASK)

#define VFCCU_0_FHDLRKC0_40_RKNEN23_MASK         (0x2000000U)
#define VFCCU_0_FHDLRKC0_40_RKNEN23_SHIFT        (25U)
#define VFCCU_0_FHDLRKC0_40_RKNEN23_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_40_RKNEN23(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_40_RKNEN23_SHIFT)) & VFCCU_0_FHDLRKC0_40_RKNEN23_MASK)

#define VFCCU_0_FHDLRKC0_40_RKNEN24_MASK         (0x4000000U)
#define VFCCU_0_FHDLRKC0_40_RKNEN24_SHIFT        (26U)
#define VFCCU_0_FHDLRKC0_40_RKNEN24_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_40_RKNEN24(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_40_RKNEN24_SHIFT)) & VFCCU_0_FHDLRKC0_40_RKNEN24_MASK)

#define VFCCU_0_FHDLRKC0_40_RKNEN25_MASK         (0x8000000U)
#define VFCCU_0_FHDLRKC0_40_RKNEN25_SHIFT        (27U)
#define VFCCU_0_FHDLRKC0_40_RKNEN25_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_40_RKNEN25(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_40_RKNEN25_SHIFT)) & VFCCU_0_FHDLRKC0_40_RKNEN25_MASK)

#define VFCCU_0_FHDLRKC0_40_RKNEN26_MASK         (0x10000000U)
#define VFCCU_0_FHDLRKC0_40_RKNEN26_SHIFT        (28U)
#define VFCCU_0_FHDLRKC0_40_RKNEN26_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_40_RKNEN26(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_40_RKNEN26_SHIFT)) & VFCCU_0_FHDLRKC0_40_RKNEN26_MASK)

#define VFCCU_0_FHDLRKC0_40_RKNEN27_MASK         (0x20000000U)
#define VFCCU_0_FHDLRKC0_40_RKNEN27_SHIFT        (29U)
#define VFCCU_0_FHDLRKC0_40_RKNEN27_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_40_RKNEN27(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_40_RKNEN27_SHIFT)) & VFCCU_0_FHDLRKC0_40_RKNEN27_MASK)

#define VFCCU_0_FHDLRKC0_40_RKNEN28_MASK         (0x40000000U)
#define VFCCU_0_FHDLRKC0_40_RKNEN28_SHIFT        (30U)
#define VFCCU_0_FHDLRKC0_40_RKNEN28_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_40_RKNEN28(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_40_RKNEN28_SHIFT)) & VFCCU_0_FHDLRKC0_40_RKNEN28_MASK)

#define VFCCU_0_FHDLRKC0_40_RKNEN29_MASK         (0x80000000U)
#define VFCCU_0_FHDLRKC0_40_RKNEN29_SHIFT        (31U)
#define VFCCU_0_FHDLRKC0_40_RKNEN29_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_40_RKNEN29(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_40_RKNEN29_SHIFT)) & VFCCU_0_FHDLRKC0_40_RKNEN29_MASK)
/*! @} */

/*! @name FHIMRKC0_50 - Immediate Reaction Configuration */
/*! @{ */

#define VFCCU_0_FHIMRKC0_50_EOUTEN0_MASK         (0x1U)
#define VFCCU_0_FHIMRKC0_50_EOUTEN0_SHIFT        (0U)
#define VFCCU_0_FHIMRKC0_50_EOUTEN0_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_50_EOUTEN0(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_50_EOUTEN0_SHIFT)) & VFCCU_0_FHIMRKC0_50_EOUTEN0_MASK)

#define VFCCU_0_FHIMRKC0_50_EOUTEN1_MASK         (0x2U)
#define VFCCU_0_FHIMRKC0_50_EOUTEN1_SHIFT        (1U)
#define VFCCU_0_FHIMRKC0_50_EOUTEN1_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_50_EOUTEN1(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_50_EOUTEN1_SHIFT)) & VFCCU_0_FHIMRKC0_50_EOUTEN1_MASK)

#define VFCCU_0_FHIMRKC0_50_RKNEN0_MASK          (0x4U)
#define VFCCU_0_FHIMRKC0_50_RKNEN0_SHIFT         (2U)
#define VFCCU_0_FHIMRKC0_50_RKNEN0_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_50_RKNEN0(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_50_RKNEN0_SHIFT)) & VFCCU_0_FHIMRKC0_50_RKNEN0_MASK)

#define VFCCU_0_FHIMRKC0_50_RKNEN1_MASK          (0x8U)
#define VFCCU_0_FHIMRKC0_50_RKNEN1_SHIFT         (3U)
#define VFCCU_0_FHIMRKC0_50_RKNEN1_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_50_RKNEN1(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_50_RKNEN1_SHIFT)) & VFCCU_0_FHIMRKC0_50_RKNEN1_MASK)

#define VFCCU_0_FHIMRKC0_50_RKNEN2_MASK          (0x10U)
#define VFCCU_0_FHIMRKC0_50_RKNEN2_SHIFT         (4U)
#define VFCCU_0_FHIMRKC0_50_RKNEN2_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_50_RKNEN2(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_50_RKNEN2_SHIFT)) & VFCCU_0_FHIMRKC0_50_RKNEN2_MASK)

#define VFCCU_0_FHIMRKC0_50_RKNEN3_MASK          (0x20U)
#define VFCCU_0_FHIMRKC0_50_RKNEN3_SHIFT         (5U)
#define VFCCU_0_FHIMRKC0_50_RKNEN3_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_50_RKNEN3(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_50_RKNEN3_SHIFT)) & VFCCU_0_FHIMRKC0_50_RKNEN3_MASK)

#define VFCCU_0_FHIMRKC0_50_RKNEN4_MASK          (0x40U)
#define VFCCU_0_FHIMRKC0_50_RKNEN4_SHIFT         (6U)
#define VFCCU_0_FHIMRKC0_50_RKNEN4_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_50_RKNEN4(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_50_RKNEN4_SHIFT)) & VFCCU_0_FHIMRKC0_50_RKNEN4_MASK)

#define VFCCU_0_FHIMRKC0_50_RKNEN5_MASK          (0x80U)
#define VFCCU_0_FHIMRKC0_50_RKNEN5_SHIFT         (7U)
#define VFCCU_0_FHIMRKC0_50_RKNEN5_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_50_RKNEN5(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_50_RKNEN5_SHIFT)) & VFCCU_0_FHIMRKC0_50_RKNEN5_MASK)

#define VFCCU_0_FHIMRKC0_50_RKNEN6_MASK          (0x100U)
#define VFCCU_0_FHIMRKC0_50_RKNEN6_SHIFT         (8U)
#define VFCCU_0_FHIMRKC0_50_RKNEN6_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_50_RKNEN6(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_50_RKNEN6_SHIFT)) & VFCCU_0_FHIMRKC0_50_RKNEN6_MASK)

#define VFCCU_0_FHIMRKC0_50_RKNEN7_MASK          (0x200U)
#define VFCCU_0_FHIMRKC0_50_RKNEN7_SHIFT         (9U)
#define VFCCU_0_FHIMRKC0_50_RKNEN7_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_50_RKNEN7(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_50_RKNEN7_SHIFT)) & VFCCU_0_FHIMRKC0_50_RKNEN7_MASK)

#define VFCCU_0_FHIMRKC0_50_RKNEN8_MASK          (0x400U)
#define VFCCU_0_FHIMRKC0_50_RKNEN8_SHIFT         (10U)
#define VFCCU_0_FHIMRKC0_50_RKNEN8_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_50_RKNEN8(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_50_RKNEN8_SHIFT)) & VFCCU_0_FHIMRKC0_50_RKNEN8_MASK)

#define VFCCU_0_FHIMRKC0_50_RKNEN9_MASK          (0x800U)
#define VFCCU_0_FHIMRKC0_50_RKNEN9_SHIFT         (11U)
#define VFCCU_0_FHIMRKC0_50_RKNEN9_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_50_RKNEN9(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_50_RKNEN9_SHIFT)) & VFCCU_0_FHIMRKC0_50_RKNEN9_MASK)

#define VFCCU_0_FHIMRKC0_50_RKNEN10_MASK         (0x1000U)
#define VFCCU_0_FHIMRKC0_50_RKNEN10_SHIFT        (12U)
#define VFCCU_0_FHIMRKC0_50_RKNEN10_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_50_RKNEN10(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_50_RKNEN10_SHIFT)) & VFCCU_0_FHIMRKC0_50_RKNEN10_MASK)

#define VFCCU_0_FHIMRKC0_50_RKNEN11_MASK         (0x2000U)
#define VFCCU_0_FHIMRKC0_50_RKNEN11_SHIFT        (13U)
#define VFCCU_0_FHIMRKC0_50_RKNEN11_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_50_RKNEN11(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_50_RKNEN11_SHIFT)) & VFCCU_0_FHIMRKC0_50_RKNEN11_MASK)

#define VFCCU_0_FHIMRKC0_50_RKNEN12_MASK         (0x4000U)
#define VFCCU_0_FHIMRKC0_50_RKNEN12_SHIFT        (14U)
#define VFCCU_0_FHIMRKC0_50_RKNEN12_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_50_RKNEN12(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_50_RKNEN12_SHIFT)) & VFCCU_0_FHIMRKC0_50_RKNEN12_MASK)

#define VFCCU_0_FHIMRKC0_50_RKNEN13_MASK         (0x8000U)
#define VFCCU_0_FHIMRKC0_50_RKNEN13_SHIFT        (15U)
#define VFCCU_0_FHIMRKC0_50_RKNEN13_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_50_RKNEN13(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_50_RKNEN13_SHIFT)) & VFCCU_0_FHIMRKC0_50_RKNEN13_MASK)

#define VFCCU_0_FHIMRKC0_50_RKNEN14_MASK         (0x10000U)
#define VFCCU_0_FHIMRKC0_50_RKNEN14_SHIFT        (16U)
#define VFCCU_0_FHIMRKC0_50_RKNEN14_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_50_RKNEN14(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_50_RKNEN14_SHIFT)) & VFCCU_0_FHIMRKC0_50_RKNEN14_MASK)

#define VFCCU_0_FHIMRKC0_50_RKNEN15_MASK         (0x20000U)
#define VFCCU_0_FHIMRKC0_50_RKNEN15_SHIFT        (17U)
#define VFCCU_0_FHIMRKC0_50_RKNEN15_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_50_RKNEN15(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_50_RKNEN15_SHIFT)) & VFCCU_0_FHIMRKC0_50_RKNEN15_MASK)

#define VFCCU_0_FHIMRKC0_50_RKNEN16_MASK         (0x40000U)
#define VFCCU_0_FHIMRKC0_50_RKNEN16_SHIFT        (18U)
#define VFCCU_0_FHIMRKC0_50_RKNEN16_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_50_RKNEN16(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_50_RKNEN16_SHIFT)) & VFCCU_0_FHIMRKC0_50_RKNEN16_MASK)

#define VFCCU_0_FHIMRKC0_50_RKNEN17_MASK         (0x80000U)
#define VFCCU_0_FHIMRKC0_50_RKNEN17_SHIFT        (19U)
#define VFCCU_0_FHIMRKC0_50_RKNEN17_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_50_RKNEN17(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_50_RKNEN17_SHIFT)) & VFCCU_0_FHIMRKC0_50_RKNEN17_MASK)

#define VFCCU_0_FHIMRKC0_50_RKNEN18_MASK         (0x100000U)
#define VFCCU_0_FHIMRKC0_50_RKNEN18_SHIFT        (20U)
#define VFCCU_0_FHIMRKC0_50_RKNEN18_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_50_RKNEN18(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_50_RKNEN18_SHIFT)) & VFCCU_0_FHIMRKC0_50_RKNEN18_MASK)

#define VFCCU_0_FHIMRKC0_50_RKNEN19_MASK         (0x200000U)
#define VFCCU_0_FHIMRKC0_50_RKNEN19_SHIFT        (21U)
#define VFCCU_0_FHIMRKC0_50_RKNEN19_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_50_RKNEN19(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_50_RKNEN19_SHIFT)) & VFCCU_0_FHIMRKC0_50_RKNEN19_MASK)

#define VFCCU_0_FHIMRKC0_50_RKNEN20_MASK         (0x400000U)
#define VFCCU_0_FHIMRKC0_50_RKNEN20_SHIFT        (22U)
#define VFCCU_0_FHIMRKC0_50_RKNEN20_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_50_RKNEN20(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_50_RKNEN20_SHIFT)) & VFCCU_0_FHIMRKC0_50_RKNEN20_MASK)

#define VFCCU_0_FHIMRKC0_50_RKNEN21_MASK         (0x800000U)
#define VFCCU_0_FHIMRKC0_50_RKNEN21_SHIFT        (23U)
#define VFCCU_0_FHIMRKC0_50_RKNEN21_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_50_RKNEN21(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_50_RKNEN21_SHIFT)) & VFCCU_0_FHIMRKC0_50_RKNEN21_MASK)

#define VFCCU_0_FHIMRKC0_50_RKNEN22_MASK         (0x1000000U)
#define VFCCU_0_FHIMRKC0_50_RKNEN22_SHIFT        (24U)
#define VFCCU_0_FHIMRKC0_50_RKNEN22_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_50_RKNEN22(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_50_RKNEN22_SHIFT)) & VFCCU_0_FHIMRKC0_50_RKNEN22_MASK)

#define VFCCU_0_FHIMRKC0_50_RKNEN23_MASK         (0x2000000U)
#define VFCCU_0_FHIMRKC0_50_RKNEN23_SHIFT        (25U)
#define VFCCU_0_FHIMRKC0_50_RKNEN23_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_50_RKNEN23(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_50_RKNEN23_SHIFT)) & VFCCU_0_FHIMRKC0_50_RKNEN23_MASK)

#define VFCCU_0_FHIMRKC0_50_RKNEN24_MASK         (0x4000000U)
#define VFCCU_0_FHIMRKC0_50_RKNEN24_SHIFT        (26U)
#define VFCCU_0_FHIMRKC0_50_RKNEN24_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_50_RKNEN24(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_50_RKNEN24_SHIFT)) & VFCCU_0_FHIMRKC0_50_RKNEN24_MASK)

#define VFCCU_0_FHIMRKC0_50_RKNEN25_MASK         (0x8000000U)
#define VFCCU_0_FHIMRKC0_50_RKNEN25_SHIFT        (27U)
#define VFCCU_0_FHIMRKC0_50_RKNEN25_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_50_RKNEN25(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_50_RKNEN25_SHIFT)) & VFCCU_0_FHIMRKC0_50_RKNEN25_MASK)

#define VFCCU_0_FHIMRKC0_50_RKNEN26_MASK         (0x10000000U)
#define VFCCU_0_FHIMRKC0_50_RKNEN26_SHIFT        (28U)
#define VFCCU_0_FHIMRKC0_50_RKNEN26_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_50_RKNEN26(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_50_RKNEN26_SHIFT)) & VFCCU_0_FHIMRKC0_50_RKNEN26_MASK)

#define VFCCU_0_FHIMRKC0_50_RKNEN27_MASK         (0x20000000U)
#define VFCCU_0_FHIMRKC0_50_RKNEN27_SHIFT        (29U)
#define VFCCU_0_FHIMRKC0_50_RKNEN27_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_50_RKNEN27(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_50_RKNEN27_SHIFT)) & VFCCU_0_FHIMRKC0_50_RKNEN27_MASK)

#define VFCCU_0_FHIMRKC0_50_RKNEN28_MASK         (0x40000000U)
#define VFCCU_0_FHIMRKC0_50_RKNEN28_SHIFT        (30U)
#define VFCCU_0_FHIMRKC0_50_RKNEN28_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_50_RKNEN28(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_50_RKNEN28_SHIFT)) & VFCCU_0_FHIMRKC0_50_RKNEN28_MASK)

#define VFCCU_0_FHIMRKC0_50_RKNEN29_MASK         (0x80000000U)
#define VFCCU_0_FHIMRKC0_50_RKNEN29_SHIFT        (31U)
#define VFCCU_0_FHIMRKC0_50_RKNEN29_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_50_RKNEN29(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_50_RKNEN29_SHIFT)) & VFCCU_0_FHIMRKC0_50_RKNEN29_MASK)
/*! @} */

/*! @name FHDLRKC0_50 - Delayed Reaction Configuration */
/*! @{ */

#define VFCCU_0_FHDLRKC0_50_EOUTEN0_MASK         (0x1U)
#define VFCCU_0_FHDLRKC0_50_EOUTEN0_SHIFT        (0U)
#define VFCCU_0_FHDLRKC0_50_EOUTEN0_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_50_EOUTEN0(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_50_EOUTEN0_SHIFT)) & VFCCU_0_FHDLRKC0_50_EOUTEN0_MASK)

#define VFCCU_0_FHDLRKC0_50_EOUTEN1_MASK         (0x2U)
#define VFCCU_0_FHDLRKC0_50_EOUTEN1_SHIFT        (1U)
#define VFCCU_0_FHDLRKC0_50_EOUTEN1_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_50_EOUTEN1(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_50_EOUTEN1_SHIFT)) & VFCCU_0_FHDLRKC0_50_EOUTEN1_MASK)

#define VFCCU_0_FHDLRKC0_50_RKNEN0_MASK          (0x4U)
#define VFCCU_0_FHDLRKC0_50_RKNEN0_SHIFT         (2U)
#define VFCCU_0_FHDLRKC0_50_RKNEN0_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_50_RKNEN0(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_50_RKNEN0_SHIFT)) & VFCCU_0_FHDLRKC0_50_RKNEN0_MASK)

#define VFCCU_0_FHDLRKC0_50_RKNEN1_MASK          (0x8U)
#define VFCCU_0_FHDLRKC0_50_RKNEN1_SHIFT         (3U)
#define VFCCU_0_FHDLRKC0_50_RKNEN1_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_50_RKNEN1(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_50_RKNEN1_SHIFT)) & VFCCU_0_FHDLRKC0_50_RKNEN1_MASK)

#define VFCCU_0_FHDLRKC0_50_RKNEN2_MASK          (0x10U)
#define VFCCU_0_FHDLRKC0_50_RKNEN2_SHIFT         (4U)
#define VFCCU_0_FHDLRKC0_50_RKNEN2_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_50_RKNEN2(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_50_RKNEN2_SHIFT)) & VFCCU_0_FHDLRKC0_50_RKNEN2_MASK)

#define VFCCU_0_FHDLRKC0_50_RKNEN3_MASK          (0x20U)
#define VFCCU_0_FHDLRKC0_50_RKNEN3_SHIFT         (5U)
#define VFCCU_0_FHDLRKC0_50_RKNEN3_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_50_RKNEN3(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_50_RKNEN3_SHIFT)) & VFCCU_0_FHDLRKC0_50_RKNEN3_MASK)

#define VFCCU_0_FHDLRKC0_50_RKNEN4_MASK          (0x40U)
#define VFCCU_0_FHDLRKC0_50_RKNEN4_SHIFT         (6U)
#define VFCCU_0_FHDLRKC0_50_RKNEN4_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_50_RKNEN4(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_50_RKNEN4_SHIFT)) & VFCCU_0_FHDLRKC0_50_RKNEN4_MASK)

#define VFCCU_0_FHDLRKC0_50_RKNEN5_MASK          (0x80U)
#define VFCCU_0_FHDLRKC0_50_RKNEN5_SHIFT         (7U)
#define VFCCU_0_FHDLRKC0_50_RKNEN5_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_50_RKNEN5(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_50_RKNEN5_SHIFT)) & VFCCU_0_FHDLRKC0_50_RKNEN5_MASK)

#define VFCCU_0_FHDLRKC0_50_RKNEN6_MASK          (0x100U)
#define VFCCU_0_FHDLRKC0_50_RKNEN6_SHIFT         (8U)
#define VFCCU_0_FHDLRKC0_50_RKNEN6_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_50_RKNEN6(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_50_RKNEN6_SHIFT)) & VFCCU_0_FHDLRKC0_50_RKNEN6_MASK)

#define VFCCU_0_FHDLRKC0_50_RKNEN7_MASK          (0x200U)
#define VFCCU_0_FHDLRKC0_50_RKNEN7_SHIFT         (9U)
#define VFCCU_0_FHDLRKC0_50_RKNEN7_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_50_RKNEN7(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_50_RKNEN7_SHIFT)) & VFCCU_0_FHDLRKC0_50_RKNEN7_MASK)

#define VFCCU_0_FHDLRKC0_50_RKNEN8_MASK          (0x400U)
#define VFCCU_0_FHDLRKC0_50_RKNEN8_SHIFT         (10U)
#define VFCCU_0_FHDLRKC0_50_RKNEN8_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_50_RKNEN8(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_50_RKNEN8_SHIFT)) & VFCCU_0_FHDLRKC0_50_RKNEN8_MASK)

#define VFCCU_0_FHDLRKC0_50_RKNEN9_MASK          (0x800U)
#define VFCCU_0_FHDLRKC0_50_RKNEN9_SHIFT         (11U)
#define VFCCU_0_FHDLRKC0_50_RKNEN9_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_50_RKNEN9(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_50_RKNEN9_SHIFT)) & VFCCU_0_FHDLRKC0_50_RKNEN9_MASK)

#define VFCCU_0_FHDLRKC0_50_RKNEN10_MASK         (0x1000U)
#define VFCCU_0_FHDLRKC0_50_RKNEN10_SHIFT        (12U)
#define VFCCU_0_FHDLRKC0_50_RKNEN10_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_50_RKNEN10(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_50_RKNEN10_SHIFT)) & VFCCU_0_FHDLRKC0_50_RKNEN10_MASK)

#define VFCCU_0_FHDLRKC0_50_RKNEN11_MASK         (0x2000U)
#define VFCCU_0_FHDLRKC0_50_RKNEN11_SHIFT        (13U)
#define VFCCU_0_FHDLRKC0_50_RKNEN11_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_50_RKNEN11(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_50_RKNEN11_SHIFT)) & VFCCU_0_FHDLRKC0_50_RKNEN11_MASK)

#define VFCCU_0_FHDLRKC0_50_RKNEN12_MASK         (0x4000U)
#define VFCCU_0_FHDLRKC0_50_RKNEN12_SHIFT        (14U)
#define VFCCU_0_FHDLRKC0_50_RKNEN12_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_50_RKNEN12(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_50_RKNEN12_SHIFT)) & VFCCU_0_FHDLRKC0_50_RKNEN12_MASK)

#define VFCCU_0_FHDLRKC0_50_RKNEN13_MASK         (0x8000U)
#define VFCCU_0_FHDLRKC0_50_RKNEN13_SHIFT        (15U)
#define VFCCU_0_FHDLRKC0_50_RKNEN13_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_50_RKNEN13(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_50_RKNEN13_SHIFT)) & VFCCU_0_FHDLRKC0_50_RKNEN13_MASK)

#define VFCCU_0_FHDLRKC0_50_RKNEN14_MASK         (0x10000U)
#define VFCCU_0_FHDLRKC0_50_RKNEN14_SHIFT        (16U)
#define VFCCU_0_FHDLRKC0_50_RKNEN14_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_50_RKNEN14(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_50_RKNEN14_SHIFT)) & VFCCU_0_FHDLRKC0_50_RKNEN14_MASK)

#define VFCCU_0_FHDLRKC0_50_RKNEN15_MASK         (0x20000U)
#define VFCCU_0_FHDLRKC0_50_RKNEN15_SHIFT        (17U)
#define VFCCU_0_FHDLRKC0_50_RKNEN15_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_50_RKNEN15(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_50_RKNEN15_SHIFT)) & VFCCU_0_FHDLRKC0_50_RKNEN15_MASK)

#define VFCCU_0_FHDLRKC0_50_RKNEN16_MASK         (0x40000U)
#define VFCCU_0_FHDLRKC0_50_RKNEN16_SHIFT        (18U)
#define VFCCU_0_FHDLRKC0_50_RKNEN16_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_50_RKNEN16(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_50_RKNEN16_SHIFT)) & VFCCU_0_FHDLRKC0_50_RKNEN16_MASK)

#define VFCCU_0_FHDLRKC0_50_RKNEN17_MASK         (0x80000U)
#define VFCCU_0_FHDLRKC0_50_RKNEN17_SHIFT        (19U)
#define VFCCU_0_FHDLRKC0_50_RKNEN17_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_50_RKNEN17(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_50_RKNEN17_SHIFT)) & VFCCU_0_FHDLRKC0_50_RKNEN17_MASK)

#define VFCCU_0_FHDLRKC0_50_RKNEN18_MASK         (0x100000U)
#define VFCCU_0_FHDLRKC0_50_RKNEN18_SHIFT        (20U)
#define VFCCU_0_FHDLRKC0_50_RKNEN18_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_50_RKNEN18(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_50_RKNEN18_SHIFT)) & VFCCU_0_FHDLRKC0_50_RKNEN18_MASK)

#define VFCCU_0_FHDLRKC0_50_RKNEN19_MASK         (0x200000U)
#define VFCCU_0_FHDLRKC0_50_RKNEN19_SHIFT        (21U)
#define VFCCU_0_FHDLRKC0_50_RKNEN19_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_50_RKNEN19(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_50_RKNEN19_SHIFT)) & VFCCU_0_FHDLRKC0_50_RKNEN19_MASK)

#define VFCCU_0_FHDLRKC0_50_RKNEN20_MASK         (0x400000U)
#define VFCCU_0_FHDLRKC0_50_RKNEN20_SHIFT        (22U)
#define VFCCU_0_FHDLRKC0_50_RKNEN20_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_50_RKNEN20(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_50_RKNEN20_SHIFT)) & VFCCU_0_FHDLRKC0_50_RKNEN20_MASK)

#define VFCCU_0_FHDLRKC0_50_RKNEN21_MASK         (0x800000U)
#define VFCCU_0_FHDLRKC0_50_RKNEN21_SHIFT        (23U)
#define VFCCU_0_FHDLRKC0_50_RKNEN21_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_50_RKNEN21(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_50_RKNEN21_SHIFT)) & VFCCU_0_FHDLRKC0_50_RKNEN21_MASK)

#define VFCCU_0_FHDLRKC0_50_RKNEN22_MASK         (0x1000000U)
#define VFCCU_0_FHDLRKC0_50_RKNEN22_SHIFT        (24U)
#define VFCCU_0_FHDLRKC0_50_RKNEN22_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_50_RKNEN22(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_50_RKNEN22_SHIFT)) & VFCCU_0_FHDLRKC0_50_RKNEN22_MASK)

#define VFCCU_0_FHDLRKC0_50_RKNEN23_MASK         (0x2000000U)
#define VFCCU_0_FHDLRKC0_50_RKNEN23_SHIFT        (25U)
#define VFCCU_0_FHDLRKC0_50_RKNEN23_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_50_RKNEN23(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_50_RKNEN23_SHIFT)) & VFCCU_0_FHDLRKC0_50_RKNEN23_MASK)

#define VFCCU_0_FHDLRKC0_50_RKNEN24_MASK         (0x4000000U)
#define VFCCU_0_FHDLRKC0_50_RKNEN24_SHIFT        (26U)
#define VFCCU_0_FHDLRKC0_50_RKNEN24_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_50_RKNEN24(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_50_RKNEN24_SHIFT)) & VFCCU_0_FHDLRKC0_50_RKNEN24_MASK)

#define VFCCU_0_FHDLRKC0_50_RKNEN25_MASK         (0x8000000U)
#define VFCCU_0_FHDLRKC0_50_RKNEN25_SHIFT        (27U)
#define VFCCU_0_FHDLRKC0_50_RKNEN25_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_50_RKNEN25(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_50_RKNEN25_SHIFT)) & VFCCU_0_FHDLRKC0_50_RKNEN25_MASK)

#define VFCCU_0_FHDLRKC0_50_RKNEN26_MASK         (0x10000000U)
#define VFCCU_0_FHDLRKC0_50_RKNEN26_SHIFT        (28U)
#define VFCCU_0_FHDLRKC0_50_RKNEN26_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_50_RKNEN26(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_50_RKNEN26_SHIFT)) & VFCCU_0_FHDLRKC0_50_RKNEN26_MASK)

#define VFCCU_0_FHDLRKC0_50_RKNEN27_MASK         (0x20000000U)
#define VFCCU_0_FHDLRKC0_50_RKNEN27_SHIFT        (29U)
#define VFCCU_0_FHDLRKC0_50_RKNEN27_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_50_RKNEN27(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_50_RKNEN27_SHIFT)) & VFCCU_0_FHDLRKC0_50_RKNEN27_MASK)

#define VFCCU_0_FHDLRKC0_50_RKNEN28_MASK         (0x40000000U)
#define VFCCU_0_FHDLRKC0_50_RKNEN28_SHIFT        (30U)
#define VFCCU_0_FHDLRKC0_50_RKNEN28_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_50_RKNEN28(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_50_RKNEN28_SHIFT)) & VFCCU_0_FHDLRKC0_50_RKNEN28_MASK)

#define VFCCU_0_FHDLRKC0_50_RKNEN29_MASK         (0x80000000U)
#define VFCCU_0_FHDLRKC0_50_RKNEN29_SHIFT        (31U)
#define VFCCU_0_FHDLRKC0_50_RKNEN29_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_50_RKNEN29(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_50_RKNEN29_SHIFT)) & VFCCU_0_FHDLRKC0_50_RKNEN29_MASK)
/*! @} */

/*! @name FHIMRKC0_60 - Immediate Reaction Configuration */
/*! @{ */

#define VFCCU_0_FHIMRKC0_60_EOUTEN0_MASK         (0x1U)
#define VFCCU_0_FHIMRKC0_60_EOUTEN0_SHIFT        (0U)
#define VFCCU_0_FHIMRKC0_60_EOUTEN0_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_60_EOUTEN0(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_60_EOUTEN0_SHIFT)) & VFCCU_0_FHIMRKC0_60_EOUTEN0_MASK)

#define VFCCU_0_FHIMRKC0_60_EOUTEN1_MASK         (0x2U)
#define VFCCU_0_FHIMRKC0_60_EOUTEN1_SHIFT        (1U)
#define VFCCU_0_FHIMRKC0_60_EOUTEN1_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_60_EOUTEN1(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_60_EOUTEN1_SHIFT)) & VFCCU_0_FHIMRKC0_60_EOUTEN1_MASK)

#define VFCCU_0_FHIMRKC0_60_RKNEN0_MASK          (0x4U)
#define VFCCU_0_FHIMRKC0_60_RKNEN0_SHIFT         (2U)
#define VFCCU_0_FHIMRKC0_60_RKNEN0_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_60_RKNEN0(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_60_RKNEN0_SHIFT)) & VFCCU_0_FHIMRKC0_60_RKNEN0_MASK)

#define VFCCU_0_FHIMRKC0_60_RKNEN1_MASK          (0x8U)
#define VFCCU_0_FHIMRKC0_60_RKNEN1_SHIFT         (3U)
#define VFCCU_0_FHIMRKC0_60_RKNEN1_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_60_RKNEN1(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_60_RKNEN1_SHIFT)) & VFCCU_0_FHIMRKC0_60_RKNEN1_MASK)

#define VFCCU_0_FHIMRKC0_60_RKNEN2_MASK          (0x10U)
#define VFCCU_0_FHIMRKC0_60_RKNEN2_SHIFT         (4U)
#define VFCCU_0_FHIMRKC0_60_RKNEN2_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_60_RKNEN2(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_60_RKNEN2_SHIFT)) & VFCCU_0_FHIMRKC0_60_RKNEN2_MASK)

#define VFCCU_0_FHIMRKC0_60_RKNEN3_MASK          (0x20U)
#define VFCCU_0_FHIMRKC0_60_RKNEN3_SHIFT         (5U)
#define VFCCU_0_FHIMRKC0_60_RKNEN3_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_60_RKNEN3(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_60_RKNEN3_SHIFT)) & VFCCU_0_FHIMRKC0_60_RKNEN3_MASK)

#define VFCCU_0_FHIMRKC0_60_RKNEN4_MASK          (0x40U)
#define VFCCU_0_FHIMRKC0_60_RKNEN4_SHIFT         (6U)
#define VFCCU_0_FHIMRKC0_60_RKNEN4_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_60_RKNEN4(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_60_RKNEN4_SHIFT)) & VFCCU_0_FHIMRKC0_60_RKNEN4_MASK)

#define VFCCU_0_FHIMRKC0_60_RKNEN5_MASK          (0x80U)
#define VFCCU_0_FHIMRKC0_60_RKNEN5_SHIFT         (7U)
#define VFCCU_0_FHIMRKC0_60_RKNEN5_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_60_RKNEN5(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_60_RKNEN5_SHIFT)) & VFCCU_0_FHIMRKC0_60_RKNEN5_MASK)

#define VFCCU_0_FHIMRKC0_60_RKNEN6_MASK          (0x100U)
#define VFCCU_0_FHIMRKC0_60_RKNEN6_SHIFT         (8U)
#define VFCCU_0_FHIMRKC0_60_RKNEN6_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_60_RKNEN6(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_60_RKNEN6_SHIFT)) & VFCCU_0_FHIMRKC0_60_RKNEN6_MASK)

#define VFCCU_0_FHIMRKC0_60_RKNEN7_MASK          (0x200U)
#define VFCCU_0_FHIMRKC0_60_RKNEN7_SHIFT         (9U)
#define VFCCU_0_FHIMRKC0_60_RKNEN7_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_60_RKNEN7(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_60_RKNEN7_SHIFT)) & VFCCU_0_FHIMRKC0_60_RKNEN7_MASK)

#define VFCCU_0_FHIMRKC0_60_RKNEN8_MASK          (0x400U)
#define VFCCU_0_FHIMRKC0_60_RKNEN8_SHIFT         (10U)
#define VFCCU_0_FHIMRKC0_60_RKNEN8_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_60_RKNEN8(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_60_RKNEN8_SHIFT)) & VFCCU_0_FHIMRKC0_60_RKNEN8_MASK)

#define VFCCU_0_FHIMRKC0_60_RKNEN9_MASK          (0x800U)
#define VFCCU_0_FHIMRKC0_60_RKNEN9_SHIFT         (11U)
#define VFCCU_0_FHIMRKC0_60_RKNEN9_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_60_RKNEN9(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_60_RKNEN9_SHIFT)) & VFCCU_0_FHIMRKC0_60_RKNEN9_MASK)

#define VFCCU_0_FHIMRKC0_60_RKNEN10_MASK         (0x1000U)
#define VFCCU_0_FHIMRKC0_60_RKNEN10_SHIFT        (12U)
#define VFCCU_0_FHIMRKC0_60_RKNEN10_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_60_RKNEN10(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_60_RKNEN10_SHIFT)) & VFCCU_0_FHIMRKC0_60_RKNEN10_MASK)

#define VFCCU_0_FHIMRKC0_60_RKNEN11_MASK         (0x2000U)
#define VFCCU_0_FHIMRKC0_60_RKNEN11_SHIFT        (13U)
#define VFCCU_0_FHIMRKC0_60_RKNEN11_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_60_RKNEN11(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_60_RKNEN11_SHIFT)) & VFCCU_0_FHIMRKC0_60_RKNEN11_MASK)

#define VFCCU_0_FHIMRKC0_60_RKNEN12_MASK         (0x4000U)
#define VFCCU_0_FHIMRKC0_60_RKNEN12_SHIFT        (14U)
#define VFCCU_0_FHIMRKC0_60_RKNEN12_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_60_RKNEN12(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_60_RKNEN12_SHIFT)) & VFCCU_0_FHIMRKC0_60_RKNEN12_MASK)

#define VFCCU_0_FHIMRKC0_60_RKNEN13_MASK         (0x8000U)
#define VFCCU_0_FHIMRKC0_60_RKNEN13_SHIFT        (15U)
#define VFCCU_0_FHIMRKC0_60_RKNEN13_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_60_RKNEN13(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_60_RKNEN13_SHIFT)) & VFCCU_0_FHIMRKC0_60_RKNEN13_MASK)

#define VFCCU_0_FHIMRKC0_60_RKNEN14_MASK         (0x10000U)
#define VFCCU_0_FHIMRKC0_60_RKNEN14_SHIFT        (16U)
#define VFCCU_0_FHIMRKC0_60_RKNEN14_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_60_RKNEN14(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_60_RKNEN14_SHIFT)) & VFCCU_0_FHIMRKC0_60_RKNEN14_MASK)

#define VFCCU_0_FHIMRKC0_60_RKNEN15_MASK         (0x20000U)
#define VFCCU_0_FHIMRKC0_60_RKNEN15_SHIFT        (17U)
#define VFCCU_0_FHIMRKC0_60_RKNEN15_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_60_RKNEN15(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_60_RKNEN15_SHIFT)) & VFCCU_0_FHIMRKC0_60_RKNEN15_MASK)

#define VFCCU_0_FHIMRKC0_60_RKNEN16_MASK         (0x40000U)
#define VFCCU_0_FHIMRKC0_60_RKNEN16_SHIFT        (18U)
#define VFCCU_0_FHIMRKC0_60_RKNEN16_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_60_RKNEN16(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_60_RKNEN16_SHIFT)) & VFCCU_0_FHIMRKC0_60_RKNEN16_MASK)

#define VFCCU_0_FHIMRKC0_60_RKNEN17_MASK         (0x80000U)
#define VFCCU_0_FHIMRKC0_60_RKNEN17_SHIFT        (19U)
#define VFCCU_0_FHIMRKC0_60_RKNEN17_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_60_RKNEN17(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_60_RKNEN17_SHIFT)) & VFCCU_0_FHIMRKC0_60_RKNEN17_MASK)

#define VFCCU_0_FHIMRKC0_60_RKNEN18_MASK         (0x100000U)
#define VFCCU_0_FHIMRKC0_60_RKNEN18_SHIFT        (20U)
#define VFCCU_0_FHIMRKC0_60_RKNEN18_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_60_RKNEN18(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_60_RKNEN18_SHIFT)) & VFCCU_0_FHIMRKC0_60_RKNEN18_MASK)

#define VFCCU_0_FHIMRKC0_60_RKNEN19_MASK         (0x200000U)
#define VFCCU_0_FHIMRKC0_60_RKNEN19_SHIFT        (21U)
#define VFCCU_0_FHIMRKC0_60_RKNEN19_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_60_RKNEN19(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_60_RKNEN19_SHIFT)) & VFCCU_0_FHIMRKC0_60_RKNEN19_MASK)

#define VFCCU_0_FHIMRKC0_60_RKNEN20_MASK         (0x400000U)
#define VFCCU_0_FHIMRKC0_60_RKNEN20_SHIFT        (22U)
#define VFCCU_0_FHIMRKC0_60_RKNEN20_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_60_RKNEN20(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_60_RKNEN20_SHIFT)) & VFCCU_0_FHIMRKC0_60_RKNEN20_MASK)

#define VFCCU_0_FHIMRKC0_60_RKNEN21_MASK         (0x800000U)
#define VFCCU_0_FHIMRKC0_60_RKNEN21_SHIFT        (23U)
#define VFCCU_0_FHIMRKC0_60_RKNEN21_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_60_RKNEN21(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_60_RKNEN21_SHIFT)) & VFCCU_0_FHIMRKC0_60_RKNEN21_MASK)

#define VFCCU_0_FHIMRKC0_60_RKNEN22_MASK         (0x1000000U)
#define VFCCU_0_FHIMRKC0_60_RKNEN22_SHIFT        (24U)
#define VFCCU_0_FHIMRKC0_60_RKNEN22_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_60_RKNEN22(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_60_RKNEN22_SHIFT)) & VFCCU_0_FHIMRKC0_60_RKNEN22_MASK)

#define VFCCU_0_FHIMRKC0_60_RKNEN23_MASK         (0x2000000U)
#define VFCCU_0_FHIMRKC0_60_RKNEN23_SHIFT        (25U)
#define VFCCU_0_FHIMRKC0_60_RKNEN23_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_60_RKNEN23(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_60_RKNEN23_SHIFT)) & VFCCU_0_FHIMRKC0_60_RKNEN23_MASK)

#define VFCCU_0_FHIMRKC0_60_RKNEN24_MASK         (0x4000000U)
#define VFCCU_0_FHIMRKC0_60_RKNEN24_SHIFT        (26U)
#define VFCCU_0_FHIMRKC0_60_RKNEN24_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_60_RKNEN24(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_60_RKNEN24_SHIFT)) & VFCCU_0_FHIMRKC0_60_RKNEN24_MASK)

#define VFCCU_0_FHIMRKC0_60_RKNEN25_MASK         (0x8000000U)
#define VFCCU_0_FHIMRKC0_60_RKNEN25_SHIFT        (27U)
#define VFCCU_0_FHIMRKC0_60_RKNEN25_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_60_RKNEN25(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_60_RKNEN25_SHIFT)) & VFCCU_0_FHIMRKC0_60_RKNEN25_MASK)

#define VFCCU_0_FHIMRKC0_60_RKNEN26_MASK         (0x10000000U)
#define VFCCU_0_FHIMRKC0_60_RKNEN26_SHIFT        (28U)
#define VFCCU_0_FHIMRKC0_60_RKNEN26_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_60_RKNEN26(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_60_RKNEN26_SHIFT)) & VFCCU_0_FHIMRKC0_60_RKNEN26_MASK)

#define VFCCU_0_FHIMRKC0_60_RKNEN27_MASK         (0x20000000U)
#define VFCCU_0_FHIMRKC0_60_RKNEN27_SHIFT        (29U)
#define VFCCU_0_FHIMRKC0_60_RKNEN27_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_60_RKNEN27(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_60_RKNEN27_SHIFT)) & VFCCU_0_FHIMRKC0_60_RKNEN27_MASK)

#define VFCCU_0_FHIMRKC0_60_RKNEN28_MASK         (0x40000000U)
#define VFCCU_0_FHIMRKC0_60_RKNEN28_SHIFT        (30U)
#define VFCCU_0_FHIMRKC0_60_RKNEN28_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_60_RKNEN28(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_60_RKNEN28_SHIFT)) & VFCCU_0_FHIMRKC0_60_RKNEN28_MASK)

#define VFCCU_0_FHIMRKC0_60_RKNEN29_MASK         (0x80000000U)
#define VFCCU_0_FHIMRKC0_60_RKNEN29_SHIFT        (31U)
#define VFCCU_0_FHIMRKC0_60_RKNEN29_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_60_RKNEN29(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_60_RKNEN29_SHIFT)) & VFCCU_0_FHIMRKC0_60_RKNEN29_MASK)
/*! @} */

/*! @name FHDLRKC0_60 - Delayed Reaction Configuration */
/*! @{ */

#define VFCCU_0_FHDLRKC0_60_EOUTEN0_MASK         (0x1U)
#define VFCCU_0_FHDLRKC0_60_EOUTEN0_SHIFT        (0U)
#define VFCCU_0_FHDLRKC0_60_EOUTEN0_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_60_EOUTEN0(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_60_EOUTEN0_SHIFT)) & VFCCU_0_FHDLRKC0_60_EOUTEN0_MASK)

#define VFCCU_0_FHDLRKC0_60_EOUTEN1_MASK         (0x2U)
#define VFCCU_0_FHDLRKC0_60_EOUTEN1_SHIFT        (1U)
#define VFCCU_0_FHDLRKC0_60_EOUTEN1_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_60_EOUTEN1(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_60_EOUTEN1_SHIFT)) & VFCCU_0_FHDLRKC0_60_EOUTEN1_MASK)

#define VFCCU_0_FHDLRKC0_60_RKNEN0_MASK          (0x4U)
#define VFCCU_0_FHDLRKC0_60_RKNEN0_SHIFT         (2U)
#define VFCCU_0_FHDLRKC0_60_RKNEN0_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_60_RKNEN0(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_60_RKNEN0_SHIFT)) & VFCCU_0_FHDLRKC0_60_RKNEN0_MASK)

#define VFCCU_0_FHDLRKC0_60_RKNEN1_MASK          (0x8U)
#define VFCCU_0_FHDLRKC0_60_RKNEN1_SHIFT         (3U)
#define VFCCU_0_FHDLRKC0_60_RKNEN1_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_60_RKNEN1(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_60_RKNEN1_SHIFT)) & VFCCU_0_FHDLRKC0_60_RKNEN1_MASK)

#define VFCCU_0_FHDLRKC0_60_RKNEN2_MASK          (0x10U)
#define VFCCU_0_FHDLRKC0_60_RKNEN2_SHIFT         (4U)
#define VFCCU_0_FHDLRKC0_60_RKNEN2_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_60_RKNEN2(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_60_RKNEN2_SHIFT)) & VFCCU_0_FHDLRKC0_60_RKNEN2_MASK)

#define VFCCU_0_FHDLRKC0_60_RKNEN3_MASK          (0x20U)
#define VFCCU_0_FHDLRKC0_60_RKNEN3_SHIFT         (5U)
#define VFCCU_0_FHDLRKC0_60_RKNEN3_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_60_RKNEN3(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_60_RKNEN3_SHIFT)) & VFCCU_0_FHDLRKC0_60_RKNEN3_MASK)

#define VFCCU_0_FHDLRKC0_60_RKNEN4_MASK          (0x40U)
#define VFCCU_0_FHDLRKC0_60_RKNEN4_SHIFT         (6U)
#define VFCCU_0_FHDLRKC0_60_RKNEN4_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_60_RKNEN4(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_60_RKNEN4_SHIFT)) & VFCCU_0_FHDLRKC0_60_RKNEN4_MASK)

#define VFCCU_0_FHDLRKC0_60_RKNEN5_MASK          (0x80U)
#define VFCCU_0_FHDLRKC0_60_RKNEN5_SHIFT         (7U)
#define VFCCU_0_FHDLRKC0_60_RKNEN5_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_60_RKNEN5(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_60_RKNEN5_SHIFT)) & VFCCU_0_FHDLRKC0_60_RKNEN5_MASK)

#define VFCCU_0_FHDLRKC0_60_RKNEN6_MASK          (0x100U)
#define VFCCU_0_FHDLRKC0_60_RKNEN6_SHIFT         (8U)
#define VFCCU_0_FHDLRKC0_60_RKNEN6_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_60_RKNEN6(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_60_RKNEN6_SHIFT)) & VFCCU_0_FHDLRKC0_60_RKNEN6_MASK)

#define VFCCU_0_FHDLRKC0_60_RKNEN7_MASK          (0x200U)
#define VFCCU_0_FHDLRKC0_60_RKNEN7_SHIFT         (9U)
#define VFCCU_0_FHDLRKC0_60_RKNEN7_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_60_RKNEN7(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_60_RKNEN7_SHIFT)) & VFCCU_0_FHDLRKC0_60_RKNEN7_MASK)

#define VFCCU_0_FHDLRKC0_60_RKNEN8_MASK          (0x400U)
#define VFCCU_0_FHDLRKC0_60_RKNEN8_SHIFT         (10U)
#define VFCCU_0_FHDLRKC0_60_RKNEN8_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_60_RKNEN8(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_60_RKNEN8_SHIFT)) & VFCCU_0_FHDLRKC0_60_RKNEN8_MASK)

#define VFCCU_0_FHDLRKC0_60_RKNEN9_MASK          (0x800U)
#define VFCCU_0_FHDLRKC0_60_RKNEN9_SHIFT         (11U)
#define VFCCU_0_FHDLRKC0_60_RKNEN9_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_60_RKNEN9(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_60_RKNEN9_SHIFT)) & VFCCU_0_FHDLRKC0_60_RKNEN9_MASK)

#define VFCCU_0_FHDLRKC0_60_RKNEN10_MASK         (0x1000U)
#define VFCCU_0_FHDLRKC0_60_RKNEN10_SHIFT        (12U)
#define VFCCU_0_FHDLRKC0_60_RKNEN10_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_60_RKNEN10(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_60_RKNEN10_SHIFT)) & VFCCU_0_FHDLRKC0_60_RKNEN10_MASK)

#define VFCCU_0_FHDLRKC0_60_RKNEN11_MASK         (0x2000U)
#define VFCCU_0_FHDLRKC0_60_RKNEN11_SHIFT        (13U)
#define VFCCU_0_FHDLRKC0_60_RKNEN11_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_60_RKNEN11(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_60_RKNEN11_SHIFT)) & VFCCU_0_FHDLRKC0_60_RKNEN11_MASK)

#define VFCCU_0_FHDLRKC0_60_RKNEN12_MASK         (0x4000U)
#define VFCCU_0_FHDLRKC0_60_RKNEN12_SHIFT        (14U)
#define VFCCU_0_FHDLRKC0_60_RKNEN12_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_60_RKNEN12(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_60_RKNEN12_SHIFT)) & VFCCU_0_FHDLRKC0_60_RKNEN12_MASK)

#define VFCCU_0_FHDLRKC0_60_RKNEN13_MASK         (0x8000U)
#define VFCCU_0_FHDLRKC0_60_RKNEN13_SHIFT        (15U)
#define VFCCU_0_FHDLRKC0_60_RKNEN13_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_60_RKNEN13(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_60_RKNEN13_SHIFT)) & VFCCU_0_FHDLRKC0_60_RKNEN13_MASK)

#define VFCCU_0_FHDLRKC0_60_RKNEN14_MASK         (0x10000U)
#define VFCCU_0_FHDLRKC0_60_RKNEN14_SHIFT        (16U)
#define VFCCU_0_FHDLRKC0_60_RKNEN14_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_60_RKNEN14(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_60_RKNEN14_SHIFT)) & VFCCU_0_FHDLRKC0_60_RKNEN14_MASK)

#define VFCCU_0_FHDLRKC0_60_RKNEN15_MASK         (0x20000U)
#define VFCCU_0_FHDLRKC0_60_RKNEN15_SHIFT        (17U)
#define VFCCU_0_FHDLRKC0_60_RKNEN15_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_60_RKNEN15(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_60_RKNEN15_SHIFT)) & VFCCU_0_FHDLRKC0_60_RKNEN15_MASK)

#define VFCCU_0_FHDLRKC0_60_RKNEN16_MASK         (0x40000U)
#define VFCCU_0_FHDLRKC0_60_RKNEN16_SHIFT        (18U)
#define VFCCU_0_FHDLRKC0_60_RKNEN16_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_60_RKNEN16(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_60_RKNEN16_SHIFT)) & VFCCU_0_FHDLRKC0_60_RKNEN16_MASK)

#define VFCCU_0_FHDLRKC0_60_RKNEN17_MASK         (0x80000U)
#define VFCCU_0_FHDLRKC0_60_RKNEN17_SHIFT        (19U)
#define VFCCU_0_FHDLRKC0_60_RKNEN17_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_60_RKNEN17(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_60_RKNEN17_SHIFT)) & VFCCU_0_FHDLRKC0_60_RKNEN17_MASK)

#define VFCCU_0_FHDLRKC0_60_RKNEN18_MASK         (0x100000U)
#define VFCCU_0_FHDLRKC0_60_RKNEN18_SHIFT        (20U)
#define VFCCU_0_FHDLRKC0_60_RKNEN18_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_60_RKNEN18(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_60_RKNEN18_SHIFT)) & VFCCU_0_FHDLRKC0_60_RKNEN18_MASK)

#define VFCCU_0_FHDLRKC0_60_RKNEN19_MASK         (0x200000U)
#define VFCCU_0_FHDLRKC0_60_RKNEN19_SHIFT        (21U)
#define VFCCU_0_FHDLRKC0_60_RKNEN19_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_60_RKNEN19(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_60_RKNEN19_SHIFT)) & VFCCU_0_FHDLRKC0_60_RKNEN19_MASK)

#define VFCCU_0_FHDLRKC0_60_RKNEN20_MASK         (0x400000U)
#define VFCCU_0_FHDLRKC0_60_RKNEN20_SHIFT        (22U)
#define VFCCU_0_FHDLRKC0_60_RKNEN20_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_60_RKNEN20(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_60_RKNEN20_SHIFT)) & VFCCU_0_FHDLRKC0_60_RKNEN20_MASK)

#define VFCCU_0_FHDLRKC0_60_RKNEN21_MASK         (0x800000U)
#define VFCCU_0_FHDLRKC0_60_RKNEN21_SHIFT        (23U)
#define VFCCU_0_FHDLRKC0_60_RKNEN21_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_60_RKNEN21(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_60_RKNEN21_SHIFT)) & VFCCU_0_FHDLRKC0_60_RKNEN21_MASK)

#define VFCCU_0_FHDLRKC0_60_RKNEN22_MASK         (0x1000000U)
#define VFCCU_0_FHDLRKC0_60_RKNEN22_SHIFT        (24U)
#define VFCCU_0_FHDLRKC0_60_RKNEN22_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_60_RKNEN22(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_60_RKNEN22_SHIFT)) & VFCCU_0_FHDLRKC0_60_RKNEN22_MASK)

#define VFCCU_0_FHDLRKC0_60_RKNEN23_MASK         (0x2000000U)
#define VFCCU_0_FHDLRKC0_60_RKNEN23_SHIFT        (25U)
#define VFCCU_0_FHDLRKC0_60_RKNEN23_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_60_RKNEN23(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_60_RKNEN23_SHIFT)) & VFCCU_0_FHDLRKC0_60_RKNEN23_MASK)

#define VFCCU_0_FHDLRKC0_60_RKNEN24_MASK         (0x4000000U)
#define VFCCU_0_FHDLRKC0_60_RKNEN24_SHIFT        (26U)
#define VFCCU_0_FHDLRKC0_60_RKNEN24_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_60_RKNEN24(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_60_RKNEN24_SHIFT)) & VFCCU_0_FHDLRKC0_60_RKNEN24_MASK)

#define VFCCU_0_FHDLRKC0_60_RKNEN25_MASK         (0x8000000U)
#define VFCCU_0_FHDLRKC0_60_RKNEN25_SHIFT        (27U)
#define VFCCU_0_FHDLRKC0_60_RKNEN25_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_60_RKNEN25(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_60_RKNEN25_SHIFT)) & VFCCU_0_FHDLRKC0_60_RKNEN25_MASK)

#define VFCCU_0_FHDLRKC0_60_RKNEN26_MASK         (0x10000000U)
#define VFCCU_0_FHDLRKC0_60_RKNEN26_SHIFT        (28U)
#define VFCCU_0_FHDLRKC0_60_RKNEN26_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_60_RKNEN26(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_60_RKNEN26_SHIFT)) & VFCCU_0_FHDLRKC0_60_RKNEN26_MASK)

#define VFCCU_0_FHDLRKC0_60_RKNEN27_MASK         (0x20000000U)
#define VFCCU_0_FHDLRKC0_60_RKNEN27_SHIFT        (29U)
#define VFCCU_0_FHDLRKC0_60_RKNEN27_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_60_RKNEN27(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_60_RKNEN27_SHIFT)) & VFCCU_0_FHDLRKC0_60_RKNEN27_MASK)

#define VFCCU_0_FHDLRKC0_60_RKNEN28_MASK         (0x40000000U)
#define VFCCU_0_FHDLRKC0_60_RKNEN28_SHIFT        (30U)
#define VFCCU_0_FHDLRKC0_60_RKNEN28_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_60_RKNEN28(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_60_RKNEN28_SHIFT)) & VFCCU_0_FHDLRKC0_60_RKNEN28_MASK)

#define VFCCU_0_FHDLRKC0_60_RKNEN29_MASK         (0x80000000U)
#define VFCCU_0_FHDLRKC0_60_RKNEN29_SHIFT        (31U)
#define VFCCU_0_FHDLRKC0_60_RKNEN29_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_60_RKNEN29(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_60_RKNEN29_SHIFT)) & VFCCU_0_FHDLRKC0_60_RKNEN29_MASK)
/*! @} */

/*! @name FHIMRKC0_70 - Immediate Reaction Configuration */
/*! @{ */

#define VFCCU_0_FHIMRKC0_70_EOUTEN0_MASK         (0x1U)
#define VFCCU_0_FHIMRKC0_70_EOUTEN0_SHIFT        (0U)
#define VFCCU_0_FHIMRKC0_70_EOUTEN0_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_70_EOUTEN0(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_70_EOUTEN0_SHIFT)) & VFCCU_0_FHIMRKC0_70_EOUTEN0_MASK)

#define VFCCU_0_FHIMRKC0_70_EOUTEN1_MASK         (0x2U)
#define VFCCU_0_FHIMRKC0_70_EOUTEN1_SHIFT        (1U)
#define VFCCU_0_FHIMRKC0_70_EOUTEN1_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_70_EOUTEN1(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_70_EOUTEN1_SHIFT)) & VFCCU_0_FHIMRKC0_70_EOUTEN1_MASK)

#define VFCCU_0_FHIMRKC0_70_RKNEN0_MASK          (0x4U)
#define VFCCU_0_FHIMRKC0_70_RKNEN0_SHIFT         (2U)
#define VFCCU_0_FHIMRKC0_70_RKNEN0_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_70_RKNEN0(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_70_RKNEN0_SHIFT)) & VFCCU_0_FHIMRKC0_70_RKNEN0_MASK)

#define VFCCU_0_FHIMRKC0_70_RKNEN1_MASK          (0x8U)
#define VFCCU_0_FHIMRKC0_70_RKNEN1_SHIFT         (3U)
#define VFCCU_0_FHIMRKC0_70_RKNEN1_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_70_RKNEN1(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_70_RKNEN1_SHIFT)) & VFCCU_0_FHIMRKC0_70_RKNEN1_MASK)

#define VFCCU_0_FHIMRKC0_70_RKNEN2_MASK          (0x10U)
#define VFCCU_0_FHIMRKC0_70_RKNEN2_SHIFT         (4U)
#define VFCCU_0_FHIMRKC0_70_RKNEN2_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_70_RKNEN2(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_70_RKNEN2_SHIFT)) & VFCCU_0_FHIMRKC0_70_RKNEN2_MASK)

#define VFCCU_0_FHIMRKC0_70_RKNEN3_MASK          (0x20U)
#define VFCCU_0_FHIMRKC0_70_RKNEN3_SHIFT         (5U)
#define VFCCU_0_FHIMRKC0_70_RKNEN3_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_70_RKNEN3(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_70_RKNEN3_SHIFT)) & VFCCU_0_FHIMRKC0_70_RKNEN3_MASK)

#define VFCCU_0_FHIMRKC0_70_RKNEN4_MASK          (0x40U)
#define VFCCU_0_FHIMRKC0_70_RKNEN4_SHIFT         (6U)
#define VFCCU_0_FHIMRKC0_70_RKNEN4_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_70_RKNEN4(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_70_RKNEN4_SHIFT)) & VFCCU_0_FHIMRKC0_70_RKNEN4_MASK)

#define VFCCU_0_FHIMRKC0_70_RKNEN5_MASK          (0x80U)
#define VFCCU_0_FHIMRKC0_70_RKNEN5_SHIFT         (7U)
#define VFCCU_0_FHIMRKC0_70_RKNEN5_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_70_RKNEN5(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_70_RKNEN5_SHIFT)) & VFCCU_0_FHIMRKC0_70_RKNEN5_MASK)

#define VFCCU_0_FHIMRKC0_70_RKNEN6_MASK          (0x100U)
#define VFCCU_0_FHIMRKC0_70_RKNEN6_SHIFT         (8U)
#define VFCCU_0_FHIMRKC0_70_RKNEN6_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_70_RKNEN6(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_70_RKNEN6_SHIFT)) & VFCCU_0_FHIMRKC0_70_RKNEN6_MASK)

#define VFCCU_0_FHIMRKC0_70_RKNEN7_MASK          (0x200U)
#define VFCCU_0_FHIMRKC0_70_RKNEN7_SHIFT         (9U)
#define VFCCU_0_FHIMRKC0_70_RKNEN7_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_70_RKNEN7(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_70_RKNEN7_SHIFT)) & VFCCU_0_FHIMRKC0_70_RKNEN7_MASK)

#define VFCCU_0_FHIMRKC0_70_RKNEN8_MASK          (0x400U)
#define VFCCU_0_FHIMRKC0_70_RKNEN8_SHIFT         (10U)
#define VFCCU_0_FHIMRKC0_70_RKNEN8_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_70_RKNEN8(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_70_RKNEN8_SHIFT)) & VFCCU_0_FHIMRKC0_70_RKNEN8_MASK)

#define VFCCU_0_FHIMRKC0_70_RKNEN9_MASK          (0x800U)
#define VFCCU_0_FHIMRKC0_70_RKNEN9_SHIFT         (11U)
#define VFCCU_0_FHIMRKC0_70_RKNEN9_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_70_RKNEN9(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_70_RKNEN9_SHIFT)) & VFCCU_0_FHIMRKC0_70_RKNEN9_MASK)

#define VFCCU_0_FHIMRKC0_70_RKNEN10_MASK         (0x1000U)
#define VFCCU_0_FHIMRKC0_70_RKNEN10_SHIFT        (12U)
#define VFCCU_0_FHIMRKC0_70_RKNEN10_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_70_RKNEN10(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_70_RKNEN10_SHIFT)) & VFCCU_0_FHIMRKC0_70_RKNEN10_MASK)

#define VFCCU_0_FHIMRKC0_70_RKNEN11_MASK         (0x2000U)
#define VFCCU_0_FHIMRKC0_70_RKNEN11_SHIFT        (13U)
#define VFCCU_0_FHIMRKC0_70_RKNEN11_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_70_RKNEN11(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_70_RKNEN11_SHIFT)) & VFCCU_0_FHIMRKC0_70_RKNEN11_MASK)

#define VFCCU_0_FHIMRKC0_70_RKNEN12_MASK         (0x4000U)
#define VFCCU_0_FHIMRKC0_70_RKNEN12_SHIFT        (14U)
#define VFCCU_0_FHIMRKC0_70_RKNEN12_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_70_RKNEN12(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_70_RKNEN12_SHIFT)) & VFCCU_0_FHIMRKC0_70_RKNEN12_MASK)

#define VFCCU_0_FHIMRKC0_70_RKNEN13_MASK         (0x8000U)
#define VFCCU_0_FHIMRKC0_70_RKNEN13_SHIFT        (15U)
#define VFCCU_0_FHIMRKC0_70_RKNEN13_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_70_RKNEN13(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_70_RKNEN13_SHIFT)) & VFCCU_0_FHIMRKC0_70_RKNEN13_MASK)

#define VFCCU_0_FHIMRKC0_70_RKNEN14_MASK         (0x10000U)
#define VFCCU_0_FHIMRKC0_70_RKNEN14_SHIFT        (16U)
#define VFCCU_0_FHIMRKC0_70_RKNEN14_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_70_RKNEN14(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_70_RKNEN14_SHIFT)) & VFCCU_0_FHIMRKC0_70_RKNEN14_MASK)

#define VFCCU_0_FHIMRKC0_70_RKNEN15_MASK         (0x20000U)
#define VFCCU_0_FHIMRKC0_70_RKNEN15_SHIFT        (17U)
#define VFCCU_0_FHIMRKC0_70_RKNEN15_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_70_RKNEN15(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_70_RKNEN15_SHIFT)) & VFCCU_0_FHIMRKC0_70_RKNEN15_MASK)

#define VFCCU_0_FHIMRKC0_70_RKNEN16_MASK         (0x40000U)
#define VFCCU_0_FHIMRKC0_70_RKNEN16_SHIFT        (18U)
#define VFCCU_0_FHIMRKC0_70_RKNEN16_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_70_RKNEN16(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_70_RKNEN16_SHIFT)) & VFCCU_0_FHIMRKC0_70_RKNEN16_MASK)

#define VFCCU_0_FHIMRKC0_70_RKNEN17_MASK         (0x80000U)
#define VFCCU_0_FHIMRKC0_70_RKNEN17_SHIFT        (19U)
#define VFCCU_0_FHIMRKC0_70_RKNEN17_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_70_RKNEN17(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_70_RKNEN17_SHIFT)) & VFCCU_0_FHIMRKC0_70_RKNEN17_MASK)

#define VFCCU_0_FHIMRKC0_70_RKNEN18_MASK         (0x100000U)
#define VFCCU_0_FHIMRKC0_70_RKNEN18_SHIFT        (20U)
#define VFCCU_0_FHIMRKC0_70_RKNEN18_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_70_RKNEN18(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_70_RKNEN18_SHIFT)) & VFCCU_0_FHIMRKC0_70_RKNEN18_MASK)

#define VFCCU_0_FHIMRKC0_70_RKNEN19_MASK         (0x200000U)
#define VFCCU_0_FHIMRKC0_70_RKNEN19_SHIFT        (21U)
#define VFCCU_0_FHIMRKC0_70_RKNEN19_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_70_RKNEN19(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_70_RKNEN19_SHIFT)) & VFCCU_0_FHIMRKC0_70_RKNEN19_MASK)

#define VFCCU_0_FHIMRKC0_70_RKNEN20_MASK         (0x400000U)
#define VFCCU_0_FHIMRKC0_70_RKNEN20_SHIFT        (22U)
#define VFCCU_0_FHIMRKC0_70_RKNEN20_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_70_RKNEN20(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_70_RKNEN20_SHIFT)) & VFCCU_0_FHIMRKC0_70_RKNEN20_MASK)

#define VFCCU_0_FHIMRKC0_70_RKNEN21_MASK         (0x800000U)
#define VFCCU_0_FHIMRKC0_70_RKNEN21_SHIFT        (23U)
#define VFCCU_0_FHIMRKC0_70_RKNEN21_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_70_RKNEN21(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_70_RKNEN21_SHIFT)) & VFCCU_0_FHIMRKC0_70_RKNEN21_MASK)

#define VFCCU_0_FHIMRKC0_70_RKNEN22_MASK         (0x1000000U)
#define VFCCU_0_FHIMRKC0_70_RKNEN22_SHIFT        (24U)
#define VFCCU_0_FHIMRKC0_70_RKNEN22_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_70_RKNEN22(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_70_RKNEN22_SHIFT)) & VFCCU_0_FHIMRKC0_70_RKNEN22_MASK)

#define VFCCU_0_FHIMRKC0_70_RKNEN23_MASK         (0x2000000U)
#define VFCCU_0_FHIMRKC0_70_RKNEN23_SHIFT        (25U)
#define VFCCU_0_FHIMRKC0_70_RKNEN23_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_70_RKNEN23(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_70_RKNEN23_SHIFT)) & VFCCU_0_FHIMRKC0_70_RKNEN23_MASK)

#define VFCCU_0_FHIMRKC0_70_RKNEN24_MASK         (0x4000000U)
#define VFCCU_0_FHIMRKC0_70_RKNEN24_SHIFT        (26U)
#define VFCCU_0_FHIMRKC0_70_RKNEN24_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_70_RKNEN24(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_70_RKNEN24_SHIFT)) & VFCCU_0_FHIMRKC0_70_RKNEN24_MASK)

#define VFCCU_0_FHIMRKC0_70_RKNEN25_MASK         (0x8000000U)
#define VFCCU_0_FHIMRKC0_70_RKNEN25_SHIFT        (27U)
#define VFCCU_0_FHIMRKC0_70_RKNEN25_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_70_RKNEN25(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_70_RKNEN25_SHIFT)) & VFCCU_0_FHIMRKC0_70_RKNEN25_MASK)

#define VFCCU_0_FHIMRKC0_70_RKNEN26_MASK         (0x10000000U)
#define VFCCU_0_FHIMRKC0_70_RKNEN26_SHIFT        (28U)
#define VFCCU_0_FHIMRKC0_70_RKNEN26_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_70_RKNEN26(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_70_RKNEN26_SHIFT)) & VFCCU_0_FHIMRKC0_70_RKNEN26_MASK)

#define VFCCU_0_FHIMRKC0_70_RKNEN27_MASK         (0x20000000U)
#define VFCCU_0_FHIMRKC0_70_RKNEN27_SHIFT        (29U)
#define VFCCU_0_FHIMRKC0_70_RKNEN27_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_70_RKNEN27(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_70_RKNEN27_SHIFT)) & VFCCU_0_FHIMRKC0_70_RKNEN27_MASK)

#define VFCCU_0_FHIMRKC0_70_RKNEN28_MASK         (0x40000000U)
#define VFCCU_0_FHIMRKC0_70_RKNEN28_SHIFT        (30U)
#define VFCCU_0_FHIMRKC0_70_RKNEN28_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_70_RKNEN28(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_70_RKNEN28_SHIFT)) & VFCCU_0_FHIMRKC0_70_RKNEN28_MASK)

#define VFCCU_0_FHIMRKC0_70_RKNEN29_MASK         (0x80000000U)
#define VFCCU_0_FHIMRKC0_70_RKNEN29_SHIFT        (31U)
#define VFCCU_0_FHIMRKC0_70_RKNEN29_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_70_RKNEN29(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_70_RKNEN29_SHIFT)) & VFCCU_0_FHIMRKC0_70_RKNEN29_MASK)
/*! @} */

/*! @name FHDLRKC0_70 - Delayed Reaction Configuration */
/*! @{ */

#define VFCCU_0_FHDLRKC0_70_EOUTEN0_MASK         (0x1U)
#define VFCCU_0_FHDLRKC0_70_EOUTEN0_SHIFT        (0U)
#define VFCCU_0_FHDLRKC0_70_EOUTEN0_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_70_EOUTEN0(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_70_EOUTEN0_SHIFT)) & VFCCU_0_FHDLRKC0_70_EOUTEN0_MASK)

#define VFCCU_0_FHDLRKC0_70_EOUTEN1_MASK         (0x2U)
#define VFCCU_0_FHDLRKC0_70_EOUTEN1_SHIFT        (1U)
#define VFCCU_0_FHDLRKC0_70_EOUTEN1_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_70_EOUTEN1(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_70_EOUTEN1_SHIFT)) & VFCCU_0_FHDLRKC0_70_EOUTEN1_MASK)

#define VFCCU_0_FHDLRKC0_70_RKNEN0_MASK          (0x4U)
#define VFCCU_0_FHDLRKC0_70_RKNEN0_SHIFT         (2U)
#define VFCCU_0_FHDLRKC0_70_RKNEN0_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_70_RKNEN0(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_70_RKNEN0_SHIFT)) & VFCCU_0_FHDLRKC0_70_RKNEN0_MASK)

#define VFCCU_0_FHDLRKC0_70_RKNEN1_MASK          (0x8U)
#define VFCCU_0_FHDLRKC0_70_RKNEN1_SHIFT         (3U)
#define VFCCU_0_FHDLRKC0_70_RKNEN1_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_70_RKNEN1(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_70_RKNEN1_SHIFT)) & VFCCU_0_FHDLRKC0_70_RKNEN1_MASK)

#define VFCCU_0_FHDLRKC0_70_RKNEN2_MASK          (0x10U)
#define VFCCU_0_FHDLRKC0_70_RKNEN2_SHIFT         (4U)
#define VFCCU_0_FHDLRKC0_70_RKNEN2_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_70_RKNEN2(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_70_RKNEN2_SHIFT)) & VFCCU_0_FHDLRKC0_70_RKNEN2_MASK)

#define VFCCU_0_FHDLRKC0_70_RKNEN3_MASK          (0x20U)
#define VFCCU_0_FHDLRKC0_70_RKNEN3_SHIFT         (5U)
#define VFCCU_0_FHDLRKC0_70_RKNEN3_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_70_RKNEN3(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_70_RKNEN3_SHIFT)) & VFCCU_0_FHDLRKC0_70_RKNEN3_MASK)

#define VFCCU_0_FHDLRKC0_70_RKNEN4_MASK          (0x40U)
#define VFCCU_0_FHDLRKC0_70_RKNEN4_SHIFT         (6U)
#define VFCCU_0_FHDLRKC0_70_RKNEN4_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_70_RKNEN4(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_70_RKNEN4_SHIFT)) & VFCCU_0_FHDLRKC0_70_RKNEN4_MASK)

#define VFCCU_0_FHDLRKC0_70_RKNEN5_MASK          (0x80U)
#define VFCCU_0_FHDLRKC0_70_RKNEN5_SHIFT         (7U)
#define VFCCU_0_FHDLRKC0_70_RKNEN5_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_70_RKNEN5(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_70_RKNEN5_SHIFT)) & VFCCU_0_FHDLRKC0_70_RKNEN5_MASK)

#define VFCCU_0_FHDLRKC0_70_RKNEN6_MASK          (0x100U)
#define VFCCU_0_FHDLRKC0_70_RKNEN6_SHIFT         (8U)
#define VFCCU_0_FHDLRKC0_70_RKNEN6_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_70_RKNEN6(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_70_RKNEN6_SHIFT)) & VFCCU_0_FHDLRKC0_70_RKNEN6_MASK)

#define VFCCU_0_FHDLRKC0_70_RKNEN7_MASK          (0x200U)
#define VFCCU_0_FHDLRKC0_70_RKNEN7_SHIFT         (9U)
#define VFCCU_0_FHDLRKC0_70_RKNEN7_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_70_RKNEN7(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_70_RKNEN7_SHIFT)) & VFCCU_0_FHDLRKC0_70_RKNEN7_MASK)

#define VFCCU_0_FHDLRKC0_70_RKNEN8_MASK          (0x400U)
#define VFCCU_0_FHDLRKC0_70_RKNEN8_SHIFT         (10U)
#define VFCCU_0_FHDLRKC0_70_RKNEN8_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_70_RKNEN8(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_70_RKNEN8_SHIFT)) & VFCCU_0_FHDLRKC0_70_RKNEN8_MASK)

#define VFCCU_0_FHDLRKC0_70_RKNEN9_MASK          (0x800U)
#define VFCCU_0_FHDLRKC0_70_RKNEN9_SHIFT         (11U)
#define VFCCU_0_FHDLRKC0_70_RKNEN9_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_70_RKNEN9(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_70_RKNEN9_SHIFT)) & VFCCU_0_FHDLRKC0_70_RKNEN9_MASK)

#define VFCCU_0_FHDLRKC0_70_RKNEN10_MASK         (0x1000U)
#define VFCCU_0_FHDLRKC0_70_RKNEN10_SHIFT        (12U)
#define VFCCU_0_FHDLRKC0_70_RKNEN10_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_70_RKNEN10(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_70_RKNEN10_SHIFT)) & VFCCU_0_FHDLRKC0_70_RKNEN10_MASK)

#define VFCCU_0_FHDLRKC0_70_RKNEN11_MASK         (0x2000U)
#define VFCCU_0_FHDLRKC0_70_RKNEN11_SHIFT        (13U)
#define VFCCU_0_FHDLRKC0_70_RKNEN11_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_70_RKNEN11(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_70_RKNEN11_SHIFT)) & VFCCU_0_FHDLRKC0_70_RKNEN11_MASK)

#define VFCCU_0_FHDLRKC0_70_RKNEN12_MASK         (0x4000U)
#define VFCCU_0_FHDLRKC0_70_RKNEN12_SHIFT        (14U)
#define VFCCU_0_FHDLRKC0_70_RKNEN12_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_70_RKNEN12(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_70_RKNEN12_SHIFT)) & VFCCU_0_FHDLRKC0_70_RKNEN12_MASK)

#define VFCCU_0_FHDLRKC0_70_RKNEN13_MASK         (0x8000U)
#define VFCCU_0_FHDLRKC0_70_RKNEN13_SHIFT        (15U)
#define VFCCU_0_FHDLRKC0_70_RKNEN13_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_70_RKNEN13(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_70_RKNEN13_SHIFT)) & VFCCU_0_FHDLRKC0_70_RKNEN13_MASK)

#define VFCCU_0_FHDLRKC0_70_RKNEN14_MASK         (0x10000U)
#define VFCCU_0_FHDLRKC0_70_RKNEN14_SHIFT        (16U)
#define VFCCU_0_FHDLRKC0_70_RKNEN14_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_70_RKNEN14(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_70_RKNEN14_SHIFT)) & VFCCU_0_FHDLRKC0_70_RKNEN14_MASK)

#define VFCCU_0_FHDLRKC0_70_RKNEN15_MASK         (0x20000U)
#define VFCCU_0_FHDLRKC0_70_RKNEN15_SHIFT        (17U)
#define VFCCU_0_FHDLRKC0_70_RKNEN15_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_70_RKNEN15(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_70_RKNEN15_SHIFT)) & VFCCU_0_FHDLRKC0_70_RKNEN15_MASK)

#define VFCCU_0_FHDLRKC0_70_RKNEN16_MASK         (0x40000U)
#define VFCCU_0_FHDLRKC0_70_RKNEN16_SHIFT        (18U)
#define VFCCU_0_FHDLRKC0_70_RKNEN16_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_70_RKNEN16(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_70_RKNEN16_SHIFT)) & VFCCU_0_FHDLRKC0_70_RKNEN16_MASK)

#define VFCCU_0_FHDLRKC0_70_RKNEN17_MASK         (0x80000U)
#define VFCCU_0_FHDLRKC0_70_RKNEN17_SHIFT        (19U)
#define VFCCU_0_FHDLRKC0_70_RKNEN17_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_70_RKNEN17(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_70_RKNEN17_SHIFT)) & VFCCU_0_FHDLRKC0_70_RKNEN17_MASK)

#define VFCCU_0_FHDLRKC0_70_RKNEN18_MASK         (0x100000U)
#define VFCCU_0_FHDLRKC0_70_RKNEN18_SHIFT        (20U)
#define VFCCU_0_FHDLRKC0_70_RKNEN18_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_70_RKNEN18(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_70_RKNEN18_SHIFT)) & VFCCU_0_FHDLRKC0_70_RKNEN18_MASK)

#define VFCCU_0_FHDLRKC0_70_RKNEN19_MASK         (0x200000U)
#define VFCCU_0_FHDLRKC0_70_RKNEN19_SHIFT        (21U)
#define VFCCU_0_FHDLRKC0_70_RKNEN19_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_70_RKNEN19(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_70_RKNEN19_SHIFT)) & VFCCU_0_FHDLRKC0_70_RKNEN19_MASK)

#define VFCCU_0_FHDLRKC0_70_RKNEN20_MASK         (0x400000U)
#define VFCCU_0_FHDLRKC0_70_RKNEN20_SHIFT        (22U)
#define VFCCU_0_FHDLRKC0_70_RKNEN20_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_70_RKNEN20(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_70_RKNEN20_SHIFT)) & VFCCU_0_FHDLRKC0_70_RKNEN20_MASK)

#define VFCCU_0_FHDLRKC0_70_RKNEN21_MASK         (0x800000U)
#define VFCCU_0_FHDLRKC0_70_RKNEN21_SHIFT        (23U)
#define VFCCU_0_FHDLRKC0_70_RKNEN21_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_70_RKNEN21(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_70_RKNEN21_SHIFT)) & VFCCU_0_FHDLRKC0_70_RKNEN21_MASK)

#define VFCCU_0_FHDLRKC0_70_RKNEN22_MASK         (0x1000000U)
#define VFCCU_0_FHDLRKC0_70_RKNEN22_SHIFT        (24U)
#define VFCCU_0_FHDLRKC0_70_RKNEN22_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_70_RKNEN22(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_70_RKNEN22_SHIFT)) & VFCCU_0_FHDLRKC0_70_RKNEN22_MASK)

#define VFCCU_0_FHDLRKC0_70_RKNEN23_MASK         (0x2000000U)
#define VFCCU_0_FHDLRKC0_70_RKNEN23_SHIFT        (25U)
#define VFCCU_0_FHDLRKC0_70_RKNEN23_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_70_RKNEN23(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_70_RKNEN23_SHIFT)) & VFCCU_0_FHDLRKC0_70_RKNEN23_MASK)

#define VFCCU_0_FHDLRKC0_70_RKNEN24_MASK         (0x4000000U)
#define VFCCU_0_FHDLRKC0_70_RKNEN24_SHIFT        (26U)
#define VFCCU_0_FHDLRKC0_70_RKNEN24_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_70_RKNEN24(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_70_RKNEN24_SHIFT)) & VFCCU_0_FHDLRKC0_70_RKNEN24_MASK)

#define VFCCU_0_FHDLRKC0_70_RKNEN25_MASK         (0x8000000U)
#define VFCCU_0_FHDLRKC0_70_RKNEN25_SHIFT        (27U)
#define VFCCU_0_FHDLRKC0_70_RKNEN25_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_70_RKNEN25(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_70_RKNEN25_SHIFT)) & VFCCU_0_FHDLRKC0_70_RKNEN25_MASK)

#define VFCCU_0_FHDLRKC0_70_RKNEN26_MASK         (0x10000000U)
#define VFCCU_0_FHDLRKC0_70_RKNEN26_SHIFT        (28U)
#define VFCCU_0_FHDLRKC0_70_RKNEN26_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_70_RKNEN26(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_70_RKNEN26_SHIFT)) & VFCCU_0_FHDLRKC0_70_RKNEN26_MASK)

#define VFCCU_0_FHDLRKC0_70_RKNEN27_MASK         (0x20000000U)
#define VFCCU_0_FHDLRKC0_70_RKNEN27_SHIFT        (29U)
#define VFCCU_0_FHDLRKC0_70_RKNEN27_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_70_RKNEN27(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_70_RKNEN27_SHIFT)) & VFCCU_0_FHDLRKC0_70_RKNEN27_MASK)

#define VFCCU_0_FHDLRKC0_70_RKNEN28_MASK         (0x40000000U)
#define VFCCU_0_FHDLRKC0_70_RKNEN28_SHIFT        (30U)
#define VFCCU_0_FHDLRKC0_70_RKNEN28_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_70_RKNEN28(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_70_RKNEN28_SHIFT)) & VFCCU_0_FHDLRKC0_70_RKNEN28_MASK)

#define VFCCU_0_FHDLRKC0_70_RKNEN29_MASK         (0x80000000U)
#define VFCCU_0_FHDLRKC0_70_RKNEN29_SHIFT        (31U)
#define VFCCU_0_FHDLRKC0_70_RKNEN29_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_70_RKNEN29(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_70_RKNEN29_SHIFT)) & VFCCU_0_FHDLRKC0_70_RKNEN29_MASK)
/*! @} */

/*! @name FHIMRKC0_80 - Immediate Reaction Configuration */
/*! @{ */

#define VFCCU_0_FHIMRKC0_80_EOUTEN0_MASK         (0x1U)
#define VFCCU_0_FHIMRKC0_80_EOUTEN0_SHIFT        (0U)
#define VFCCU_0_FHIMRKC0_80_EOUTEN0_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_80_EOUTEN0(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_80_EOUTEN0_SHIFT)) & VFCCU_0_FHIMRKC0_80_EOUTEN0_MASK)

#define VFCCU_0_FHIMRKC0_80_EOUTEN1_MASK         (0x2U)
#define VFCCU_0_FHIMRKC0_80_EOUTEN1_SHIFT        (1U)
#define VFCCU_0_FHIMRKC0_80_EOUTEN1_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_80_EOUTEN1(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_80_EOUTEN1_SHIFT)) & VFCCU_0_FHIMRKC0_80_EOUTEN1_MASK)

#define VFCCU_0_FHIMRKC0_80_RKNEN0_MASK          (0x4U)
#define VFCCU_0_FHIMRKC0_80_RKNEN0_SHIFT         (2U)
#define VFCCU_0_FHIMRKC0_80_RKNEN0_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_80_RKNEN0(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_80_RKNEN0_SHIFT)) & VFCCU_0_FHIMRKC0_80_RKNEN0_MASK)

#define VFCCU_0_FHIMRKC0_80_RKNEN1_MASK          (0x8U)
#define VFCCU_0_FHIMRKC0_80_RKNEN1_SHIFT         (3U)
#define VFCCU_0_FHIMRKC0_80_RKNEN1_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_80_RKNEN1(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_80_RKNEN1_SHIFT)) & VFCCU_0_FHIMRKC0_80_RKNEN1_MASK)

#define VFCCU_0_FHIMRKC0_80_RKNEN2_MASK          (0x10U)
#define VFCCU_0_FHIMRKC0_80_RKNEN2_SHIFT         (4U)
#define VFCCU_0_FHIMRKC0_80_RKNEN2_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_80_RKNEN2(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_80_RKNEN2_SHIFT)) & VFCCU_0_FHIMRKC0_80_RKNEN2_MASK)

#define VFCCU_0_FHIMRKC0_80_RKNEN3_MASK          (0x20U)
#define VFCCU_0_FHIMRKC0_80_RKNEN3_SHIFT         (5U)
#define VFCCU_0_FHIMRKC0_80_RKNEN3_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_80_RKNEN3(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_80_RKNEN3_SHIFT)) & VFCCU_0_FHIMRKC0_80_RKNEN3_MASK)

#define VFCCU_0_FHIMRKC0_80_RKNEN4_MASK          (0x40U)
#define VFCCU_0_FHIMRKC0_80_RKNEN4_SHIFT         (6U)
#define VFCCU_0_FHIMRKC0_80_RKNEN4_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_80_RKNEN4(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_80_RKNEN4_SHIFT)) & VFCCU_0_FHIMRKC0_80_RKNEN4_MASK)

#define VFCCU_0_FHIMRKC0_80_RKNEN5_MASK          (0x80U)
#define VFCCU_0_FHIMRKC0_80_RKNEN5_SHIFT         (7U)
#define VFCCU_0_FHIMRKC0_80_RKNEN5_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_80_RKNEN5(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_80_RKNEN5_SHIFT)) & VFCCU_0_FHIMRKC0_80_RKNEN5_MASK)

#define VFCCU_0_FHIMRKC0_80_RKNEN6_MASK          (0x100U)
#define VFCCU_0_FHIMRKC0_80_RKNEN6_SHIFT         (8U)
#define VFCCU_0_FHIMRKC0_80_RKNEN6_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_80_RKNEN6(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_80_RKNEN6_SHIFT)) & VFCCU_0_FHIMRKC0_80_RKNEN6_MASK)

#define VFCCU_0_FHIMRKC0_80_RKNEN7_MASK          (0x200U)
#define VFCCU_0_FHIMRKC0_80_RKNEN7_SHIFT         (9U)
#define VFCCU_0_FHIMRKC0_80_RKNEN7_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_80_RKNEN7(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_80_RKNEN7_SHIFT)) & VFCCU_0_FHIMRKC0_80_RKNEN7_MASK)

#define VFCCU_0_FHIMRKC0_80_RKNEN8_MASK          (0x400U)
#define VFCCU_0_FHIMRKC0_80_RKNEN8_SHIFT         (10U)
#define VFCCU_0_FHIMRKC0_80_RKNEN8_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_80_RKNEN8(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_80_RKNEN8_SHIFT)) & VFCCU_0_FHIMRKC0_80_RKNEN8_MASK)

#define VFCCU_0_FHIMRKC0_80_RKNEN9_MASK          (0x800U)
#define VFCCU_0_FHIMRKC0_80_RKNEN9_SHIFT         (11U)
#define VFCCU_0_FHIMRKC0_80_RKNEN9_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_80_RKNEN9(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_80_RKNEN9_SHIFT)) & VFCCU_0_FHIMRKC0_80_RKNEN9_MASK)

#define VFCCU_0_FHIMRKC0_80_RKNEN10_MASK         (0x1000U)
#define VFCCU_0_FHIMRKC0_80_RKNEN10_SHIFT        (12U)
#define VFCCU_0_FHIMRKC0_80_RKNEN10_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_80_RKNEN10(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_80_RKNEN10_SHIFT)) & VFCCU_0_FHIMRKC0_80_RKNEN10_MASK)

#define VFCCU_0_FHIMRKC0_80_RKNEN11_MASK         (0x2000U)
#define VFCCU_0_FHIMRKC0_80_RKNEN11_SHIFT        (13U)
#define VFCCU_0_FHIMRKC0_80_RKNEN11_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_80_RKNEN11(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_80_RKNEN11_SHIFT)) & VFCCU_0_FHIMRKC0_80_RKNEN11_MASK)

#define VFCCU_0_FHIMRKC0_80_RKNEN12_MASK         (0x4000U)
#define VFCCU_0_FHIMRKC0_80_RKNEN12_SHIFT        (14U)
#define VFCCU_0_FHIMRKC0_80_RKNEN12_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_80_RKNEN12(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_80_RKNEN12_SHIFT)) & VFCCU_0_FHIMRKC0_80_RKNEN12_MASK)

#define VFCCU_0_FHIMRKC0_80_RKNEN13_MASK         (0x8000U)
#define VFCCU_0_FHIMRKC0_80_RKNEN13_SHIFT        (15U)
#define VFCCU_0_FHIMRKC0_80_RKNEN13_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_80_RKNEN13(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_80_RKNEN13_SHIFT)) & VFCCU_0_FHIMRKC0_80_RKNEN13_MASK)

#define VFCCU_0_FHIMRKC0_80_RKNEN14_MASK         (0x10000U)
#define VFCCU_0_FHIMRKC0_80_RKNEN14_SHIFT        (16U)
#define VFCCU_0_FHIMRKC0_80_RKNEN14_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_80_RKNEN14(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_80_RKNEN14_SHIFT)) & VFCCU_0_FHIMRKC0_80_RKNEN14_MASK)

#define VFCCU_0_FHIMRKC0_80_RKNEN15_MASK         (0x20000U)
#define VFCCU_0_FHIMRKC0_80_RKNEN15_SHIFT        (17U)
#define VFCCU_0_FHIMRKC0_80_RKNEN15_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_80_RKNEN15(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_80_RKNEN15_SHIFT)) & VFCCU_0_FHIMRKC0_80_RKNEN15_MASK)

#define VFCCU_0_FHIMRKC0_80_RKNEN16_MASK         (0x40000U)
#define VFCCU_0_FHIMRKC0_80_RKNEN16_SHIFT        (18U)
#define VFCCU_0_FHIMRKC0_80_RKNEN16_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_80_RKNEN16(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_80_RKNEN16_SHIFT)) & VFCCU_0_FHIMRKC0_80_RKNEN16_MASK)

#define VFCCU_0_FHIMRKC0_80_RKNEN17_MASK         (0x80000U)
#define VFCCU_0_FHIMRKC0_80_RKNEN17_SHIFT        (19U)
#define VFCCU_0_FHIMRKC0_80_RKNEN17_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_80_RKNEN17(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_80_RKNEN17_SHIFT)) & VFCCU_0_FHIMRKC0_80_RKNEN17_MASK)

#define VFCCU_0_FHIMRKC0_80_RKNEN18_MASK         (0x100000U)
#define VFCCU_0_FHIMRKC0_80_RKNEN18_SHIFT        (20U)
#define VFCCU_0_FHIMRKC0_80_RKNEN18_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_80_RKNEN18(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_80_RKNEN18_SHIFT)) & VFCCU_0_FHIMRKC0_80_RKNEN18_MASK)

#define VFCCU_0_FHIMRKC0_80_RKNEN19_MASK         (0x200000U)
#define VFCCU_0_FHIMRKC0_80_RKNEN19_SHIFT        (21U)
#define VFCCU_0_FHIMRKC0_80_RKNEN19_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_80_RKNEN19(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_80_RKNEN19_SHIFT)) & VFCCU_0_FHIMRKC0_80_RKNEN19_MASK)

#define VFCCU_0_FHIMRKC0_80_RKNEN20_MASK         (0x400000U)
#define VFCCU_0_FHIMRKC0_80_RKNEN20_SHIFT        (22U)
#define VFCCU_0_FHIMRKC0_80_RKNEN20_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_80_RKNEN20(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_80_RKNEN20_SHIFT)) & VFCCU_0_FHIMRKC0_80_RKNEN20_MASK)

#define VFCCU_0_FHIMRKC0_80_RKNEN21_MASK         (0x800000U)
#define VFCCU_0_FHIMRKC0_80_RKNEN21_SHIFT        (23U)
#define VFCCU_0_FHIMRKC0_80_RKNEN21_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_80_RKNEN21(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_80_RKNEN21_SHIFT)) & VFCCU_0_FHIMRKC0_80_RKNEN21_MASK)

#define VFCCU_0_FHIMRKC0_80_RKNEN22_MASK         (0x1000000U)
#define VFCCU_0_FHIMRKC0_80_RKNEN22_SHIFT        (24U)
#define VFCCU_0_FHIMRKC0_80_RKNEN22_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_80_RKNEN22(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_80_RKNEN22_SHIFT)) & VFCCU_0_FHIMRKC0_80_RKNEN22_MASK)

#define VFCCU_0_FHIMRKC0_80_RKNEN23_MASK         (0x2000000U)
#define VFCCU_0_FHIMRKC0_80_RKNEN23_SHIFT        (25U)
#define VFCCU_0_FHIMRKC0_80_RKNEN23_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_80_RKNEN23(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_80_RKNEN23_SHIFT)) & VFCCU_0_FHIMRKC0_80_RKNEN23_MASK)

#define VFCCU_0_FHIMRKC0_80_RKNEN24_MASK         (0x4000000U)
#define VFCCU_0_FHIMRKC0_80_RKNEN24_SHIFT        (26U)
#define VFCCU_0_FHIMRKC0_80_RKNEN24_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_80_RKNEN24(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_80_RKNEN24_SHIFT)) & VFCCU_0_FHIMRKC0_80_RKNEN24_MASK)

#define VFCCU_0_FHIMRKC0_80_RKNEN25_MASK         (0x8000000U)
#define VFCCU_0_FHIMRKC0_80_RKNEN25_SHIFT        (27U)
#define VFCCU_0_FHIMRKC0_80_RKNEN25_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_80_RKNEN25(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_80_RKNEN25_SHIFT)) & VFCCU_0_FHIMRKC0_80_RKNEN25_MASK)

#define VFCCU_0_FHIMRKC0_80_RKNEN26_MASK         (0x10000000U)
#define VFCCU_0_FHIMRKC0_80_RKNEN26_SHIFT        (28U)
#define VFCCU_0_FHIMRKC0_80_RKNEN26_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_80_RKNEN26(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_80_RKNEN26_SHIFT)) & VFCCU_0_FHIMRKC0_80_RKNEN26_MASK)

#define VFCCU_0_FHIMRKC0_80_RKNEN27_MASK         (0x20000000U)
#define VFCCU_0_FHIMRKC0_80_RKNEN27_SHIFT        (29U)
#define VFCCU_0_FHIMRKC0_80_RKNEN27_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_80_RKNEN27(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_80_RKNEN27_SHIFT)) & VFCCU_0_FHIMRKC0_80_RKNEN27_MASK)

#define VFCCU_0_FHIMRKC0_80_RKNEN28_MASK         (0x40000000U)
#define VFCCU_0_FHIMRKC0_80_RKNEN28_SHIFT        (30U)
#define VFCCU_0_FHIMRKC0_80_RKNEN28_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_80_RKNEN28(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_80_RKNEN28_SHIFT)) & VFCCU_0_FHIMRKC0_80_RKNEN28_MASK)

#define VFCCU_0_FHIMRKC0_80_RKNEN29_MASK         (0x80000000U)
#define VFCCU_0_FHIMRKC0_80_RKNEN29_SHIFT        (31U)
#define VFCCU_0_FHIMRKC0_80_RKNEN29_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_80_RKNEN29(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_80_RKNEN29_SHIFT)) & VFCCU_0_FHIMRKC0_80_RKNEN29_MASK)
/*! @} */

/*! @name FHDLRKC0_80 - Delayed Reaction Configuration */
/*! @{ */

#define VFCCU_0_FHDLRKC0_80_EOUTEN0_MASK         (0x1U)
#define VFCCU_0_FHDLRKC0_80_EOUTEN0_SHIFT        (0U)
#define VFCCU_0_FHDLRKC0_80_EOUTEN0_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_80_EOUTEN0(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_80_EOUTEN0_SHIFT)) & VFCCU_0_FHDLRKC0_80_EOUTEN0_MASK)

#define VFCCU_0_FHDLRKC0_80_EOUTEN1_MASK         (0x2U)
#define VFCCU_0_FHDLRKC0_80_EOUTEN1_SHIFT        (1U)
#define VFCCU_0_FHDLRKC0_80_EOUTEN1_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_80_EOUTEN1(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_80_EOUTEN1_SHIFT)) & VFCCU_0_FHDLRKC0_80_EOUTEN1_MASK)

#define VFCCU_0_FHDLRKC0_80_RKNEN0_MASK          (0x4U)
#define VFCCU_0_FHDLRKC0_80_RKNEN0_SHIFT         (2U)
#define VFCCU_0_FHDLRKC0_80_RKNEN0_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_80_RKNEN0(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_80_RKNEN0_SHIFT)) & VFCCU_0_FHDLRKC0_80_RKNEN0_MASK)

#define VFCCU_0_FHDLRKC0_80_RKNEN1_MASK          (0x8U)
#define VFCCU_0_FHDLRKC0_80_RKNEN1_SHIFT         (3U)
#define VFCCU_0_FHDLRKC0_80_RKNEN1_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_80_RKNEN1(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_80_RKNEN1_SHIFT)) & VFCCU_0_FHDLRKC0_80_RKNEN1_MASK)

#define VFCCU_0_FHDLRKC0_80_RKNEN2_MASK          (0x10U)
#define VFCCU_0_FHDLRKC0_80_RKNEN2_SHIFT         (4U)
#define VFCCU_0_FHDLRKC0_80_RKNEN2_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_80_RKNEN2(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_80_RKNEN2_SHIFT)) & VFCCU_0_FHDLRKC0_80_RKNEN2_MASK)

#define VFCCU_0_FHDLRKC0_80_RKNEN3_MASK          (0x20U)
#define VFCCU_0_FHDLRKC0_80_RKNEN3_SHIFT         (5U)
#define VFCCU_0_FHDLRKC0_80_RKNEN3_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_80_RKNEN3(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_80_RKNEN3_SHIFT)) & VFCCU_0_FHDLRKC0_80_RKNEN3_MASK)

#define VFCCU_0_FHDLRKC0_80_RKNEN4_MASK          (0x40U)
#define VFCCU_0_FHDLRKC0_80_RKNEN4_SHIFT         (6U)
#define VFCCU_0_FHDLRKC0_80_RKNEN4_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_80_RKNEN4(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_80_RKNEN4_SHIFT)) & VFCCU_0_FHDLRKC0_80_RKNEN4_MASK)

#define VFCCU_0_FHDLRKC0_80_RKNEN5_MASK          (0x80U)
#define VFCCU_0_FHDLRKC0_80_RKNEN5_SHIFT         (7U)
#define VFCCU_0_FHDLRKC0_80_RKNEN5_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_80_RKNEN5(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_80_RKNEN5_SHIFT)) & VFCCU_0_FHDLRKC0_80_RKNEN5_MASK)

#define VFCCU_0_FHDLRKC0_80_RKNEN6_MASK          (0x100U)
#define VFCCU_0_FHDLRKC0_80_RKNEN6_SHIFT         (8U)
#define VFCCU_0_FHDLRKC0_80_RKNEN6_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_80_RKNEN6(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_80_RKNEN6_SHIFT)) & VFCCU_0_FHDLRKC0_80_RKNEN6_MASK)

#define VFCCU_0_FHDLRKC0_80_RKNEN7_MASK          (0x200U)
#define VFCCU_0_FHDLRKC0_80_RKNEN7_SHIFT         (9U)
#define VFCCU_0_FHDLRKC0_80_RKNEN7_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_80_RKNEN7(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_80_RKNEN7_SHIFT)) & VFCCU_0_FHDLRKC0_80_RKNEN7_MASK)

#define VFCCU_0_FHDLRKC0_80_RKNEN8_MASK          (0x400U)
#define VFCCU_0_FHDLRKC0_80_RKNEN8_SHIFT         (10U)
#define VFCCU_0_FHDLRKC0_80_RKNEN8_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_80_RKNEN8(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_80_RKNEN8_SHIFT)) & VFCCU_0_FHDLRKC0_80_RKNEN8_MASK)

#define VFCCU_0_FHDLRKC0_80_RKNEN9_MASK          (0x800U)
#define VFCCU_0_FHDLRKC0_80_RKNEN9_SHIFT         (11U)
#define VFCCU_0_FHDLRKC0_80_RKNEN9_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_80_RKNEN9(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_80_RKNEN9_SHIFT)) & VFCCU_0_FHDLRKC0_80_RKNEN9_MASK)

#define VFCCU_0_FHDLRKC0_80_RKNEN10_MASK         (0x1000U)
#define VFCCU_0_FHDLRKC0_80_RKNEN10_SHIFT        (12U)
#define VFCCU_0_FHDLRKC0_80_RKNEN10_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_80_RKNEN10(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_80_RKNEN10_SHIFT)) & VFCCU_0_FHDLRKC0_80_RKNEN10_MASK)

#define VFCCU_0_FHDLRKC0_80_RKNEN11_MASK         (0x2000U)
#define VFCCU_0_FHDLRKC0_80_RKNEN11_SHIFT        (13U)
#define VFCCU_0_FHDLRKC0_80_RKNEN11_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_80_RKNEN11(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_80_RKNEN11_SHIFT)) & VFCCU_0_FHDLRKC0_80_RKNEN11_MASK)

#define VFCCU_0_FHDLRKC0_80_RKNEN12_MASK         (0x4000U)
#define VFCCU_0_FHDLRKC0_80_RKNEN12_SHIFT        (14U)
#define VFCCU_0_FHDLRKC0_80_RKNEN12_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_80_RKNEN12(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_80_RKNEN12_SHIFT)) & VFCCU_0_FHDLRKC0_80_RKNEN12_MASK)

#define VFCCU_0_FHDLRKC0_80_RKNEN13_MASK         (0x8000U)
#define VFCCU_0_FHDLRKC0_80_RKNEN13_SHIFT        (15U)
#define VFCCU_0_FHDLRKC0_80_RKNEN13_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_80_RKNEN13(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_80_RKNEN13_SHIFT)) & VFCCU_0_FHDLRKC0_80_RKNEN13_MASK)

#define VFCCU_0_FHDLRKC0_80_RKNEN14_MASK         (0x10000U)
#define VFCCU_0_FHDLRKC0_80_RKNEN14_SHIFT        (16U)
#define VFCCU_0_FHDLRKC0_80_RKNEN14_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_80_RKNEN14(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_80_RKNEN14_SHIFT)) & VFCCU_0_FHDLRKC0_80_RKNEN14_MASK)

#define VFCCU_0_FHDLRKC0_80_RKNEN15_MASK         (0x20000U)
#define VFCCU_0_FHDLRKC0_80_RKNEN15_SHIFT        (17U)
#define VFCCU_0_FHDLRKC0_80_RKNEN15_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_80_RKNEN15(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_80_RKNEN15_SHIFT)) & VFCCU_0_FHDLRKC0_80_RKNEN15_MASK)

#define VFCCU_0_FHDLRKC0_80_RKNEN16_MASK         (0x40000U)
#define VFCCU_0_FHDLRKC0_80_RKNEN16_SHIFT        (18U)
#define VFCCU_0_FHDLRKC0_80_RKNEN16_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_80_RKNEN16(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_80_RKNEN16_SHIFT)) & VFCCU_0_FHDLRKC0_80_RKNEN16_MASK)

#define VFCCU_0_FHDLRKC0_80_RKNEN17_MASK         (0x80000U)
#define VFCCU_0_FHDLRKC0_80_RKNEN17_SHIFT        (19U)
#define VFCCU_0_FHDLRKC0_80_RKNEN17_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_80_RKNEN17(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_80_RKNEN17_SHIFT)) & VFCCU_0_FHDLRKC0_80_RKNEN17_MASK)

#define VFCCU_0_FHDLRKC0_80_RKNEN18_MASK         (0x100000U)
#define VFCCU_0_FHDLRKC0_80_RKNEN18_SHIFT        (20U)
#define VFCCU_0_FHDLRKC0_80_RKNEN18_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_80_RKNEN18(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_80_RKNEN18_SHIFT)) & VFCCU_0_FHDLRKC0_80_RKNEN18_MASK)

#define VFCCU_0_FHDLRKC0_80_RKNEN19_MASK         (0x200000U)
#define VFCCU_0_FHDLRKC0_80_RKNEN19_SHIFT        (21U)
#define VFCCU_0_FHDLRKC0_80_RKNEN19_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_80_RKNEN19(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_80_RKNEN19_SHIFT)) & VFCCU_0_FHDLRKC0_80_RKNEN19_MASK)

#define VFCCU_0_FHDLRKC0_80_RKNEN20_MASK         (0x400000U)
#define VFCCU_0_FHDLRKC0_80_RKNEN20_SHIFT        (22U)
#define VFCCU_0_FHDLRKC0_80_RKNEN20_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_80_RKNEN20(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_80_RKNEN20_SHIFT)) & VFCCU_0_FHDLRKC0_80_RKNEN20_MASK)

#define VFCCU_0_FHDLRKC0_80_RKNEN21_MASK         (0x800000U)
#define VFCCU_0_FHDLRKC0_80_RKNEN21_SHIFT        (23U)
#define VFCCU_0_FHDLRKC0_80_RKNEN21_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_80_RKNEN21(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_80_RKNEN21_SHIFT)) & VFCCU_0_FHDLRKC0_80_RKNEN21_MASK)

#define VFCCU_0_FHDLRKC0_80_RKNEN22_MASK         (0x1000000U)
#define VFCCU_0_FHDLRKC0_80_RKNEN22_SHIFT        (24U)
#define VFCCU_0_FHDLRKC0_80_RKNEN22_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_80_RKNEN22(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_80_RKNEN22_SHIFT)) & VFCCU_0_FHDLRKC0_80_RKNEN22_MASK)

#define VFCCU_0_FHDLRKC0_80_RKNEN23_MASK         (0x2000000U)
#define VFCCU_0_FHDLRKC0_80_RKNEN23_SHIFT        (25U)
#define VFCCU_0_FHDLRKC0_80_RKNEN23_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_80_RKNEN23(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_80_RKNEN23_SHIFT)) & VFCCU_0_FHDLRKC0_80_RKNEN23_MASK)

#define VFCCU_0_FHDLRKC0_80_RKNEN24_MASK         (0x4000000U)
#define VFCCU_0_FHDLRKC0_80_RKNEN24_SHIFT        (26U)
#define VFCCU_0_FHDLRKC0_80_RKNEN24_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_80_RKNEN24(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_80_RKNEN24_SHIFT)) & VFCCU_0_FHDLRKC0_80_RKNEN24_MASK)

#define VFCCU_0_FHDLRKC0_80_RKNEN25_MASK         (0x8000000U)
#define VFCCU_0_FHDLRKC0_80_RKNEN25_SHIFT        (27U)
#define VFCCU_0_FHDLRKC0_80_RKNEN25_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_80_RKNEN25(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_80_RKNEN25_SHIFT)) & VFCCU_0_FHDLRKC0_80_RKNEN25_MASK)

#define VFCCU_0_FHDLRKC0_80_RKNEN26_MASK         (0x10000000U)
#define VFCCU_0_FHDLRKC0_80_RKNEN26_SHIFT        (28U)
#define VFCCU_0_FHDLRKC0_80_RKNEN26_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_80_RKNEN26(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_80_RKNEN26_SHIFT)) & VFCCU_0_FHDLRKC0_80_RKNEN26_MASK)

#define VFCCU_0_FHDLRKC0_80_RKNEN27_MASK         (0x20000000U)
#define VFCCU_0_FHDLRKC0_80_RKNEN27_SHIFT        (29U)
#define VFCCU_0_FHDLRKC0_80_RKNEN27_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_80_RKNEN27(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_80_RKNEN27_SHIFT)) & VFCCU_0_FHDLRKC0_80_RKNEN27_MASK)

#define VFCCU_0_FHDLRKC0_80_RKNEN28_MASK         (0x40000000U)
#define VFCCU_0_FHDLRKC0_80_RKNEN28_SHIFT        (30U)
#define VFCCU_0_FHDLRKC0_80_RKNEN28_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_80_RKNEN28(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_80_RKNEN28_SHIFT)) & VFCCU_0_FHDLRKC0_80_RKNEN28_MASK)

#define VFCCU_0_FHDLRKC0_80_RKNEN29_MASK         (0x80000000U)
#define VFCCU_0_FHDLRKC0_80_RKNEN29_SHIFT        (31U)
#define VFCCU_0_FHDLRKC0_80_RKNEN29_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_80_RKNEN29(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_80_RKNEN29_SHIFT)) & VFCCU_0_FHDLRKC0_80_RKNEN29_MASK)
/*! @} */

/*! @name FHIMRKC0_90 - Immediate Reaction Configuration */
/*! @{ */

#define VFCCU_0_FHIMRKC0_90_EOUTEN0_MASK         (0x1U)
#define VFCCU_0_FHIMRKC0_90_EOUTEN0_SHIFT        (0U)
#define VFCCU_0_FHIMRKC0_90_EOUTEN0_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_90_EOUTEN0(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_90_EOUTEN0_SHIFT)) & VFCCU_0_FHIMRKC0_90_EOUTEN0_MASK)

#define VFCCU_0_FHIMRKC0_90_EOUTEN1_MASK         (0x2U)
#define VFCCU_0_FHIMRKC0_90_EOUTEN1_SHIFT        (1U)
#define VFCCU_0_FHIMRKC0_90_EOUTEN1_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_90_EOUTEN1(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_90_EOUTEN1_SHIFT)) & VFCCU_0_FHIMRKC0_90_EOUTEN1_MASK)

#define VFCCU_0_FHIMRKC0_90_RKNEN0_MASK          (0x4U)
#define VFCCU_0_FHIMRKC0_90_RKNEN0_SHIFT         (2U)
#define VFCCU_0_FHIMRKC0_90_RKNEN0_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_90_RKNEN0(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_90_RKNEN0_SHIFT)) & VFCCU_0_FHIMRKC0_90_RKNEN0_MASK)

#define VFCCU_0_FHIMRKC0_90_RKNEN1_MASK          (0x8U)
#define VFCCU_0_FHIMRKC0_90_RKNEN1_SHIFT         (3U)
#define VFCCU_0_FHIMRKC0_90_RKNEN1_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_90_RKNEN1(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_90_RKNEN1_SHIFT)) & VFCCU_0_FHIMRKC0_90_RKNEN1_MASK)

#define VFCCU_0_FHIMRKC0_90_RKNEN2_MASK          (0x10U)
#define VFCCU_0_FHIMRKC0_90_RKNEN2_SHIFT         (4U)
#define VFCCU_0_FHIMRKC0_90_RKNEN2_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_90_RKNEN2(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_90_RKNEN2_SHIFT)) & VFCCU_0_FHIMRKC0_90_RKNEN2_MASK)

#define VFCCU_0_FHIMRKC0_90_RKNEN3_MASK          (0x20U)
#define VFCCU_0_FHIMRKC0_90_RKNEN3_SHIFT         (5U)
#define VFCCU_0_FHIMRKC0_90_RKNEN3_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_90_RKNEN3(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_90_RKNEN3_SHIFT)) & VFCCU_0_FHIMRKC0_90_RKNEN3_MASK)

#define VFCCU_0_FHIMRKC0_90_RKNEN4_MASK          (0x40U)
#define VFCCU_0_FHIMRKC0_90_RKNEN4_SHIFT         (6U)
#define VFCCU_0_FHIMRKC0_90_RKNEN4_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_90_RKNEN4(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_90_RKNEN4_SHIFT)) & VFCCU_0_FHIMRKC0_90_RKNEN4_MASK)

#define VFCCU_0_FHIMRKC0_90_RKNEN5_MASK          (0x80U)
#define VFCCU_0_FHIMRKC0_90_RKNEN5_SHIFT         (7U)
#define VFCCU_0_FHIMRKC0_90_RKNEN5_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_90_RKNEN5(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_90_RKNEN5_SHIFT)) & VFCCU_0_FHIMRKC0_90_RKNEN5_MASK)

#define VFCCU_0_FHIMRKC0_90_RKNEN6_MASK          (0x100U)
#define VFCCU_0_FHIMRKC0_90_RKNEN6_SHIFT         (8U)
#define VFCCU_0_FHIMRKC0_90_RKNEN6_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_90_RKNEN6(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_90_RKNEN6_SHIFT)) & VFCCU_0_FHIMRKC0_90_RKNEN6_MASK)

#define VFCCU_0_FHIMRKC0_90_RKNEN7_MASK          (0x200U)
#define VFCCU_0_FHIMRKC0_90_RKNEN7_SHIFT         (9U)
#define VFCCU_0_FHIMRKC0_90_RKNEN7_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_90_RKNEN7(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_90_RKNEN7_SHIFT)) & VFCCU_0_FHIMRKC0_90_RKNEN7_MASK)

#define VFCCU_0_FHIMRKC0_90_RKNEN8_MASK          (0x400U)
#define VFCCU_0_FHIMRKC0_90_RKNEN8_SHIFT         (10U)
#define VFCCU_0_FHIMRKC0_90_RKNEN8_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_90_RKNEN8(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_90_RKNEN8_SHIFT)) & VFCCU_0_FHIMRKC0_90_RKNEN8_MASK)

#define VFCCU_0_FHIMRKC0_90_RKNEN9_MASK          (0x800U)
#define VFCCU_0_FHIMRKC0_90_RKNEN9_SHIFT         (11U)
#define VFCCU_0_FHIMRKC0_90_RKNEN9_WIDTH         (1U)
#define VFCCU_0_FHIMRKC0_90_RKNEN9(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_90_RKNEN9_SHIFT)) & VFCCU_0_FHIMRKC0_90_RKNEN9_MASK)

#define VFCCU_0_FHIMRKC0_90_RKNEN10_MASK         (0x1000U)
#define VFCCU_0_FHIMRKC0_90_RKNEN10_SHIFT        (12U)
#define VFCCU_0_FHIMRKC0_90_RKNEN10_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_90_RKNEN10(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_90_RKNEN10_SHIFT)) & VFCCU_0_FHIMRKC0_90_RKNEN10_MASK)

#define VFCCU_0_FHIMRKC0_90_RKNEN11_MASK         (0x2000U)
#define VFCCU_0_FHIMRKC0_90_RKNEN11_SHIFT        (13U)
#define VFCCU_0_FHIMRKC0_90_RKNEN11_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_90_RKNEN11(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_90_RKNEN11_SHIFT)) & VFCCU_0_FHIMRKC0_90_RKNEN11_MASK)

#define VFCCU_0_FHIMRKC0_90_RKNEN12_MASK         (0x4000U)
#define VFCCU_0_FHIMRKC0_90_RKNEN12_SHIFT        (14U)
#define VFCCU_0_FHIMRKC0_90_RKNEN12_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_90_RKNEN12(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_90_RKNEN12_SHIFT)) & VFCCU_0_FHIMRKC0_90_RKNEN12_MASK)

#define VFCCU_0_FHIMRKC0_90_RKNEN13_MASK         (0x8000U)
#define VFCCU_0_FHIMRKC0_90_RKNEN13_SHIFT        (15U)
#define VFCCU_0_FHIMRKC0_90_RKNEN13_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_90_RKNEN13(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_90_RKNEN13_SHIFT)) & VFCCU_0_FHIMRKC0_90_RKNEN13_MASK)

#define VFCCU_0_FHIMRKC0_90_RKNEN14_MASK         (0x10000U)
#define VFCCU_0_FHIMRKC0_90_RKNEN14_SHIFT        (16U)
#define VFCCU_0_FHIMRKC0_90_RKNEN14_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_90_RKNEN14(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_90_RKNEN14_SHIFT)) & VFCCU_0_FHIMRKC0_90_RKNEN14_MASK)

#define VFCCU_0_FHIMRKC0_90_RKNEN15_MASK         (0x20000U)
#define VFCCU_0_FHIMRKC0_90_RKNEN15_SHIFT        (17U)
#define VFCCU_0_FHIMRKC0_90_RKNEN15_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_90_RKNEN15(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_90_RKNEN15_SHIFT)) & VFCCU_0_FHIMRKC0_90_RKNEN15_MASK)

#define VFCCU_0_FHIMRKC0_90_RKNEN16_MASK         (0x40000U)
#define VFCCU_0_FHIMRKC0_90_RKNEN16_SHIFT        (18U)
#define VFCCU_0_FHIMRKC0_90_RKNEN16_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_90_RKNEN16(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_90_RKNEN16_SHIFT)) & VFCCU_0_FHIMRKC0_90_RKNEN16_MASK)

#define VFCCU_0_FHIMRKC0_90_RKNEN17_MASK         (0x80000U)
#define VFCCU_0_FHIMRKC0_90_RKNEN17_SHIFT        (19U)
#define VFCCU_0_FHIMRKC0_90_RKNEN17_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_90_RKNEN17(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_90_RKNEN17_SHIFT)) & VFCCU_0_FHIMRKC0_90_RKNEN17_MASK)

#define VFCCU_0_FHIMRKC0_90_RKNEN18_MASK         (0x100000U)
#define VFCCU_0_FHIMRKC0_90_RKNEN18_SHIFT        (20U)
#define VFCCU_0_FHIMRKC0_90_RKNEN18_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_90_RKNEN18(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_90_RKNEN18_SHIFT)) & VFCCU_0_FHIMRKC0_90_RKNEN18_MASK)

#define VFCCU_0_FHIMRKC0_90_RKNEN19_MASK         (0x200000U)
#define VFCCU_0_FHIMRKC0_90_RKNEN19_SHIFT        (21U)
#define VFCCU_0_FHIMRKC0_90_RKNEN19_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_90_RKNEN19(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_90_RKNEN19_SHIFT)) & VFCCU_0_FHIMRKC0_90_RKNEN19_MASK)

#define VFCCU_0_FHIMRKC0_90_RKNEN20_MASK         (0x400000U)
#define VFCCU_0_FHIMRKC0_90_RKNEN20_SHIFT        (22U)
#define VFCCU_0_FHIMRKC0_90_RKNEN20_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_90_RKNEN20(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_90_RKNEN20_SHIFT)) & VFCCU_0_FHIMRKC0_90_RKNEN20_MASK)

#define VFCCU_0_FHIMRKC0_90_RKNEN21_MASK         (0x800000U)
#define VFCCU_0_FHIMRKC0_90_RKNEN21_SHIFT        (23U)
#define VFCCU_0_FHIMRKC0_90_RKNEN21_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_90_RKNEN21(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_90_RKNEN21_SHIFT)) & VFCCU_0_FHIMRKC0_90_RKNEN21_MASK)

#define VFCCU_0_FHIMRKC0_90_RKNEN22_MASK         (0x1000000U)
#define VFCCU_0_FHIMRKC0_90_RKNEN22_SHIFT        (24U)
#define VFCCU_0_FHIMRKC0_90_RKNEN22_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_90_RKNEN22(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_90_RKNEN22_SHIFT)) & VFCCU_0_FHIMRKC0_90_RKNEN22_MASK)

#define VFCCU_0_FHIMRKC0_90_RKNEN23_MASK         (0x2000000U)
#define VFCCU_0_FHIMRKC0_90_RKNEN23_SHIFT        (25U)
#define VFCCU_0_FHIMRKC0_90_RKNEN23_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_90_RKNEN23(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_90_RKNEN23_SHIFT)) & VFCCU_0_FHIMRKC0_90_RKNEN23_MASK)

#define VFCCU_0_FHIMRKC0_90_RKNEN24_MASK         (0x4000000U)
#define VFCCU_0_FHIMRKC0_90_RKNEN24_SHIFT        (26U)
#define VFCCU_0_FHIMRKC0_90_RKNEN24_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_90_RKNEN24(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_90_RKNEN24_SHIFT)) & VFCCU_0_FHIMRKC0_90_RKNEN24_MASK)

#define VFCCU_0_FHIMRKC0_90_RKNEN25_MASK         (0x8000000U)
#define VFCCU_0_FHIMRKC0_90_RKNEN25_SHIFT        (27U)
#define VFCCU_0_FHIMRKC0_90_RKNEN25_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_90_RKNEN25(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_90_RKNEN25_SHIFT)) & VFCCU_0_FHIMRKC0_90_RKNEN25_MASK)

#define VFCCU_0_FHIMRKC0_90_RKNEN26_MASK         (0x10000000U)
#define VFCCU_0_FHIMRKC0_90_RKNEN26_SHIFT        (28U)
#define VFCCU_0_FHIMRKC0_90_RKNEN26_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_90_RKNEN26(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_90_RKNEN26_SHIFT)) & VFCCU_0_FHIMRKC0_90_RKNEN26_MASK)

#define VFCCU_0_FHIMRKC0_90_RKNEN27_MASK         (0x20000000U)
#define VFCCU_0_FHIMRKC0_90_RKNEN27_SHIFT        (29U)
#define VFCCU_0_FHIMRKC0_90_RKNEN27_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_90_RKNEN27(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_90_RKNEN27_SHIFT)) & VFCCU_0_FHIMRKC0_90_RKNEN27_MASK)

#define VFCCU_0_FHIMRKC0_90_RKNEN28_MASK         (0x40000000U)
#define VFCCU_0_FHIMRKC0_90_RKNEN28_SHIFT        (30U)
#define VFCCU_0_FHIMRKC0_90_RKNEN28_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_90_RKNEN28(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_90_RKNEN28_SHIFT)) & VFCCU_0_FHIMRKC0_90_RKNEN28_MASK)

#define VFCCU_0_FHIMRKC0_90_RKNEN29_MASK         (0x80000000U)
#define VFCCU_0_FHIMRKC0_90_RKNEN29_SHIFT        (31U)
#define VFCCU_0_FHIMRKC0_90_RKNEN29_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_90_RKNEN29(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_90_RKNEN29_SHIFT)) & VFCCU_0_FHIMRKC0_90_RKNEN29_MASK)
/*! @} */

/*! @name FHDLRKC0_90 - Delayed Reaction Configuration */
/*! @{ */

#define VFCCU_0_FHDLRKC0_90_EOUTEN0_MASK         (0x1U)
#define VFCCU_0_FHDLRKC0_90_EOUTEN0_SHIFT        (0U)
#define VFCCU_0_FHDLRKC0_90_EOUTEN0_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_90_EOUTEN0(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_90_EOUTEN0_SHIFT)) & VFCCU_0_FHDLRKC0_90_EOUTEN0_MASK)

#define VFCCU_0_FHDLRKC0_90_EOUTEN1_MASK         (0x2U)
#define VFCCU_0_FHDLRKC0_90_EOUTEN1_SHIFT        (1U)
#define VFCCU_0_FHDLRKC0_90_EOUTEN1_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_90_EOUTEN1(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_90_EOUTEN1_SHIFT)) & VFCCU_0_FHDLRKC0_90_EOUTEN1_MASK)

#define VFCCU_0_FHDLRKC0_90_RKNEN0_MASK          (0x4U)
#define VFCCU_0_FHDLRKC0_90_RKNEN0_SHIFT         (2U)
#define VFCCU_0_FHDLRKC0_90_RKNEN0_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_90_RKNEN0(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_90_RKNEN0_SHIFT)) & VFCCU_0_FHDLRKC0_90_RKNEN0_MASK)

#define VFCCU_0_FHDLRKC0_90_RKNEN1_MASK          (0x8U)
#define VFCCU_0_FHDLRKC0_90_RKNEN1_SHIFT         (3U)
#define VFCCU_0_FHDLRKC0_90_RKNEN1_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_90_RKNEN1(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_90_RKNEN1_SHIFT)) & VFCCU_0_FHDLRKC0_90_RKNEN1_MASK)

#define VFCCU_0_FHDLRKC0_90_RKNEN2_MASK          (0x10U)
#define VFCCU_0_FHDLRKC0_90_RKNEN2_SHIFT         (4U)
#define VFCCU_0_FHDLRKC0_90_RKNEN2_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_90_RKNEN2(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_90_RKNEN2_SHIFT)) & VFCCU_0_FHDLRKC0_90_RKNEN2_MASK)

#define VFCCU_0_FHDLRKC0_90_RKNEN3_MASK          (0x20U)
#define VFCCU_0_FHDLRKC0_90_RKNEN3_SHIFT         (5U)
#define VFCCU_0_FHDLRKC0_90_RKNEN3_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_90_RKNEN3(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_90_RKNEN3_SHIFT)) & VFCCU_0_FHDLRKC0_90_RKNEN3_MASK)

#define VFCCU_0_FHDLRKC0_90_RKNEN4_MASK          (0x40U)
#define VFCCU_0_FHDLRKC0_90_RKNEN4_SHIFT         (6U)
#define VFCCU_0_FHDLRKC0_90_RKNEN4_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_90_RKNEN4(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_90_RKNEN4_SHIFT)) & VFCCU_0_FHDLRKC0_90_RKNEN4_MASK)

#define VFCCU_0_FHDLRKC0_90_RKNEN5_MASK          (0x80U)
#define VFCCU_0_FHDLRKC0_90_RKNEN5_SHIFT         (7U)
#define VFCCU_0_FHDLRKC0_90_RKNEN5_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_90_RKNEN5(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_90_RKNEN5_SHIFT)) & VFCCU_0_FHDLRKC0_90_RKNEN5_MASK)

#define VFCCU_0_FHDLRKC0_90_RKNEN6_MASK          (0x100U)
#define VFCCU_0_FHDLRKC0_90_RKNEN6_SHIFT         (8U)
#define VFCCU_0_FHDLRKC0_90_RKNEN6_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_90_RKNEN6(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_90_RKNEN6_SHIFT)) & VFCCU_0_FHDLRKC0_90_RKNEN6_MASK)

#define VFCCU_0_FHDLRKC0_90_RKNEN7_MASK          (0x200U)
#define VFCCU_0_FHDLRKC0_90_RKNEN7_SHIFT         (9U)
#define VFCCU_0_FHDLRKC0_90_RKNEN7_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_90_RKNEN7(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_90_RKNEN7_SHIFT)) & VFCCU_0_FHDLRKC0_90_RKNEN7_MASK)

#define VFCCU_0_FHDLRKC0_90_RKNEN8_MASK          (0x400U)
#define VFCCU_0_FHDLRKC0_90_RKNEN8_SHIFT         (10U)
#define VFCCU_0_FHDLRKC0_90_RKNEN8_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_90_RKNEN8(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_90_RKNEN8_SHIFT)) & VFCCU_0_FHDLRKC0_90_RKNEN8_MASK)

#define VFCCU_0_FHDLRKC0_90_RKNEN9_MASK          (0x800U)
#define VFCCU_0_FHDLRKC0_90_RKNEN9_SHIFT         (11U)
#define VFCCU_0_FHDLRKC0_90_RKNEN9_WIDTH         (1U)
#define VFCCU_0_FHDLRKC0_90_RKNEN9(x)            (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_90_RKNEN9_SHIFT)) & VFCCU_0_FHDLRKC0_90_RKNEN9_MASK)

#define VFCCU_0_FHDLRKC0_90_RKNEN10_MASK         (0x1000U)
#define VFCCU_0_FHDLRKC0_90_RKNEN10_SHIFT        (12U)
#define VFCCU_0_FHDLRKC0_90_RKNEN10_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_90_RKNEN10(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_90_RKNEN10_SHIFT)) & VFCCU_0_FHDLRKC0_90_RKNEN10_MASK)

#define VFCCU_0_FHDLRKC0_90_RKNEN11_MASK         (0x2000U)
#define VFCCU_0_FHDLRKC0_90_RKNEN11_SHIFT        (13U)
#define VFCCU_0_FHDLRKC0_90_RKNEN11_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_90_RKNEN11(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_90_RKNEN11_SHIFT)) & VFCCU_0_FHDLRKC0_90_RKNEN11_MASK)

#define VFCCU_0_FHDLRKC0_90_RKNEN12_MASK         (0x4000U)
#define VFCCU_0_FHDLRKC0_90_RKNEN12_SHIFT        (14U)
#define VFCCU_0_FHDLRKC0_90_RKNEN12_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_90_RKNEN12(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_90_RKNEN12_SHIFT)) & VFCCU_0_FHDLRKC0_90_RKNEN12_MASK)

#define VFCCU_0_FHDLRKC0_90_RKNEN13_MASK         (0x8000U)
#define VFCCU_0_FHDLRKC0_90_RKNEN13_SHIFT        (15U)
#define VFCCU_0_FHDLRKC0_90_RKNEN13_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_90_RKNEN13(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_90_RKNEN13_SHIFT)) & VFCCU_0_FHDLRKC0_90_RKNEN13_MASK)

#define VFCCU_0_FHDLRKC0_90_RKNEN14_MASK         (0x10000U)
#define VFCCU_0_FHDLRKC0_90_RKNEN14_SHIFT        (16U)
#define VFCCU_0_FHDLRKC0_90_RKNEN14_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_90_RKNEN14(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_90_RKNEN14_SHIFT)) & VFCCU_0_FHDLRKC0_90_RKNEN14_MASK)

#define VFCCU_0_FHDLRKC0_90_RKNEN15_MASK         (0x20000U)
#define VFCCU_0_FHDLRKC0_90_RKNEN15_SHIFT        (17U)
#define VFCCU_0_FHDLRKC0_90_RKNEN15_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_90_RKNEN15(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_90_RKNEN15_SHIFT)) & VFCCU_0_FHDLRKC0_90_RKNEN15_MASK)

#define VFCCU_0_FHDLRKC0_90_RKNEN16_MASK         (0x40000U)
#define VFCCU_0_FHDLRKC0_90_RKNEN16_SHIFT        (18U)
#define VFCCU_0_FHDLRKC0_90_RKNEN16_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_90_RKNEN16(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_90_RKNEN16_SHIFT)) & VFCCU_0_FHDLRKC0_90_RKNEN16_MASK)

#define VFCCU_0_FHDLRKC0_90_RKNEN17_MASK         (0x80000U)
#define VFCCU_0_FHDLRKC0_90_RKNEN17_SHIFT        (19U)
#define VFCCU_0_FHDLRKC0_90_RKNEN17_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_90_RKNEN17(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_90_RKNEN17_SHIFT)) & VFCCU_0_FHDLRKC0_90_RKNEN17_MASK)

#define VFCCU_0_FHDLRKC0_90_RKNEN18_MASK         (0x100000U)
#define VFCCU_0_FHDLRKC0_90_RKNEN18_SHIFT        (20U)
#define VFCCU_0_FHDLRKC0_90_RKNEN18_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_90_RKNEN18(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_90_RKNEN18_SHIFT)) & VFCCU_0_FHDLRKC0_90_RKNEN18_MASK)

#define VFCCU_0_FHDLRKC0_90_RKNEN19_MASK         (0x200000U)
#define VFCCU_0_FHDLRKC0_90_RKNEN19_SHIFT        (21U)
#define VFCCU_0_FHDLRKC0_90_RKNEN19_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_90_RKNEN19(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_90_RKNEN19_SHIFT)) & VFCCU_0_FHDLRKC0_90_RKNEN19_MASK)

#define VFCCU_0_FHDLRKC0_90_RKNEN20_MASK         (0x400000U)
#define VFCCU_0_FHDLRKC0_90_RKNEN20_SHIFT        (22U)
#define VFCCU_0_FHDLRKC0_90_RKNEN20_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_90_RKNEN20(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_90_RKNEN20_SHIFT)) & VFCCU_0_FHDLRKC0_90_RKNEN20_MASK)

#define VFCCU_0_FHDLRKC0_90_RKNEN21_MASK         (0x800000U)
#define VFCCU_0_FHDLRKC0_90_RKNEN21_SHIFT        (23U)
#define VFCCU_0_FHDLRKC0_90_RKNEN21_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_90_RKNEN21(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_90_RKNEN21_SHIFT)) & VFCCU_0_FHDLRKC0_90_RKNEN21_MASK)

#define VFCCU_0_FHDLRKC0_90_RKNEN22_MASK         (0x1000000U)
#define VFCCU_0_FHDLRKC0_90_RKNEN22_SHIFT        (24U)
#define VFCCU_0_FHDLRKC0_90_RKNEN22_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_90_RKNEN22(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_90_RKNEN22_SHIFT)) & VFCCU_0_FHDLRKC0_90_RKNEN22_MASK)

#define VFCCU_0_FHDLRKC0_90_RKNEN23_MASK         (0x2000000U)
#define VFCCU_0_FHDLRKC0_90_RKNEN23_SHIFT        (25U)
#define VFCCU_0_FHDLRKC0_90_RKNEN23_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_90_RKNEN23(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_90_RKNEN23_SHIFT)) & VFCCU_0_FHDLRKC0_90_RKNEN23_MASK)

#define VFCCU_0_FHDLRKC0_90_RKNEN24_MASK         (0x4000000U)
#define VFCCU_0_FHDLRKC0_90_RKNEN24_SHIFT        (26U)
#define VFCCU_0_FHDLRKC0_90_RKNEN24_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_90_RKNEN24(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_90_RKNEN24_SHIFT)) & VFCCU_0_FHDLRKC0_90_RKNEN24_MASK)

#define VFCCU_0_FHDLRKC0_90_RKNEN25_MASK         (0x8000000U)
#define VFCCU_0_FHDLRKC0_90_RKNEN25_SHIFT        (27U)
#define VFCCU_0_FHDLRKC0_90_RKNEN25_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_90_RKNEN25(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_90_RKNEN25_SHIFT)) & VFCCU_0_FHDLRKC0_90_RKNEN25_MASK)

#define VFCCU_0_FHDLRKC0_90_RKNEN26_MASK         (0x10000000U)
#define VFCCU_0_FHDLRKC0_90_RKNEN26_SHIFT        (28U)
#define VFCCU_0_FHDLRKC0_90_RKNEN26_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_90_RKNEN26(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_90_RKNEN26_SHIFT)) & VFCCU_0_FHDLRKC0_90_RKNEN26_MASK)

#define VFCCU_0_FHDLRKC0_90_RKNEN27_MASK         (0x20000000U)
#define VFCCU_0_FHDLRKC0_90_RKNEN27_SHIFT        (29U)
#define VFCCU_0_FHDLRKC0_90_RKNEN27_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_90_RKNEN27(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_90_RKNEN27_SHIFT)) & VFCCU_0_FHDLRKC0_90_RKNEN27_MASK)

#define VFCCU_0_FHDLRKC0_90_RKNEN28_MASK         (0x40000000U)
#define VFCCU_0_FHDLRKC0_90_RKNEN28_SHIFT        (30U)
#define VFCCU_0_FHDLRKC0_90_RKNEN28_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_90_RKNEN28(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_90_RKNEN28_SHIFT)) & VFCCU_0_FHDLRKC0_90_RKNEN28_MASK)

#define VFCCU_0_FHDLRKC0_90_RKNEN29_MASK         (0x80000000U)
#define VFCCU_0_FHDLRKC0_90_RKNEN29_SHIFT        (31U)
#define VFCCU_0_FHDLRKC0_90_RKNEN29_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_90_RKNEN29(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_90_RKNEN29_SHIFT)) & VFCCU_0_FHDLRKC0_90_RKNEN29_MASK)
/*! @} */

/*! @name FHIMRKC0_100 - Immediate Reaction Configuration */
/*! @{ */

#define VFCCU_0_FHIMRKC0_100_EOUTEN0_MASK        (0x1U)
#define VFCCU_0_FHIMRKC0_100_EOUTEN0_SHIFT       (0U)
#define VFCCU_0_FHIMRKC0_100_EOUTEN0_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_100_EOUTEN0(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_100_EOUTEN0_SHIFT)) & VFCCU_0_FHIMRKC0_100_EOUTEN0_MASK)

#define VFCCU_0_FHIMRKC0_100_EOUTEN1_MASK        (0x2U)
#define VFCCU_0_FHIMRKC0_100_EOUTEN1_SHIFT       (1U)
#define VFCCU_0_FHIMRKC0_100_EOUTEN1_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_100_EOUTEN1(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_100_EOUTEN1_SHIFT)) & VFCCU_0_FHIMRKC0_100_EOUTEN1_MASK)

#define VFCCU_0_FHIMRKC0_100_RKNEN0_MASK         (0x4U)
#define VFCCU_0_FHIMRKC0_100_RKNEN0_SHIFT        (2U)
#define VFCCU_0_FHIMRKC0_100_RKNEN0_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_100_RKNEN0(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_100_RKNEN0_SHIFT)) & VFCCU_0_FHIMRKC0_100_RKNEN0_MASK)

#define VFCCU_0_FHIMRKC0_100_RKNEN1_MASK         (0x8U)
#define VFCCU_0_FHIMRKC0_100_RKNEN1_SHIFT        (3U)
#define VFCCU_0_FHIMRKC0_100_RKNEN1_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_100_RKNEN1(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_100_RKNEN1_SHIFT)) & VFCCU_0_FHIMRKC0_100_RKNEN1_MASK)

#define VFCCU_0_FHIMRKC0_100_RKNEN2_MASK         (0x10U)
#define VFCCU_0_FHIMRKC0_100_RKNEN2_SHIFT        (4U)
#define VFCCU_0_FHIMRKC0_100_RKNEN2_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_100_RKNEN2(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_100_RKNEN2_SHIFT)) & VFCCU_0_FHIMRKC0_100_RKNEN2_MASK)

#define VFCCU_0_FHIMRKC0_100_RKNEN3_MASK         (0x20U)
#define VFCCU_0_FHIMRKC0_100_RKNEN3_SHIFT        (5U)
#define VFCCU_0_FHIMRKC0_100_RKNEN3_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_100_RKNEN3(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_100_RKNEN3_SHIFT)) & VFCCU_0_FHIMRKC0_100_RKNEN3_MASK)

#define VFCCU_0_FHIMRKC0_100_RKNEN4_MASK         (0x40U)
#define VFCCU_0_FHIMRKC0_100_RKNEN4_SHIFT        (6U)
#define VFCCU_0_FHIMRKC0_100_RKNEN4_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_100_RKNEN4(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_100_RKNEN4_SHIFT)) & VFCCU_0_FHIMRKC0_100_RKNEN4_MASK)

#define VFCCU_0_FHIMRKC0_100_RKNEN5_MASK         (0x80U)
#define VFCCU_0_FHIMRKC0_100_RKNEN5_SHIFT        (7U)
#define VFCCU_0_FHIMRKC0_100_RKNEN5_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_100_RKNEN5(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_100_RKNEN5_SHIFT)) & VFCCU_0_FHIMRKC0_100_RKNEN5_MASK)

#define VFCCU_0_FHIMRKC0_100_RKNEN6_MASK         (0x100U)
#define VFCCU_0_FHIMRKC0_100_RKNEN6_SHIFT        (8U)
#define VFCCU_0_FHIMRKC0_100_RKNEN6_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_100_RKNEN6(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_100_RKNEN6_SHIFT)) & VFCCU_0_FHIMRKC0_100_RKNEN6_MASK)

#define VFCCU_0_FHIMRKC0_100_RKNEN7_MASK         (0x200U)
#define VFCCU_0_FHIMRKC0_100_RKNEN7_SHIFT        (9U)
#define VFCCU_0_FHIMRKC0_100_RKNEN7_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_100_RKNEN7(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_100_RKNEN7_SHIFT)) & VFCCU_0_FHIMRKC0_100_RKNEN7_MASK)

#define VFCCU_0_FHIMRKC0_100_RKNEN8_MASK         (0x400U)
#define VFCCU_0_FHIMRKC0_100_RKNEN8_SHIFT        (10U)
#define VFCCU_0_FHIMRKC0_100_RKNEN8_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_100_RKNEN8(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_100_RKNEN8_SHIFT)) & VFCCU_0_FHIMRKC0_100_RKNEN8_MASK)

#define VFCCU_0_FHIMRKC0_100_RKNEN9_MASK         (0x800U)
#define VFCCU_0_FHIMRKC0_100_RKNEN9_SHIFT        (11U)
#define VFCCU_0_FHIMRKC0_100_RKNEN9_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_100_RKNEN9(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_100_RKNEN9_SHIFT)) & VFCCU_0_FHIMRKC0_100_RKNEN9_MASK)

#define VFCCU_0_FHIMRKC0_100_RKNEN10_MASK        (0x1000U)
#define VFCCU_0_FHIMRKC0_100_RKNEN10_SHIFT       (12U)
#define VFCCU_0_FHIMRKC0_100_RKNEN10_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_100_RKNEN10(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_100_RKNEN10_SHIFT)) & VFCCU_0_FHIMRKC0_100_RKNEN10_MASK)

#define VFCCU_0_FHIMRKC0_100_RKNEN11_MASK        (0x2000U)
#define VFCCU_0_FHIMRKC0_100_RKNEN11_SHIFT       (13U)
#define VFCCU_0_FHIMRKC0_100_RKNEN11_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_100_RKNEN11(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_100_RKNEN11_SHIFT)) & VFCCU_0_FHIMRKC0_100_RKNEN11_MASK)

#define VFCCU_0_FHIMRKC0_100_RKNEN12_MASK        (0x4000U)
#define VFCCU_0_FHIMRKC0_100_RKNEN12_SHIFT       (14U)
#define VFCCU_0_FHIMRKC0_100_RKNEN12_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_100_RKNEN12(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_100_RKNEN12_SHIFT)) & VFCCU_0_FHIMRKC0_100_RKNEN12_MASK)

#define VFCCU_0_FHIMRKC0_100_RKNEN13_MASK        (0x8000U)
#define VFCCU_0_FHIMRKC0_100_RKNEN13_SHIFT       (15U)
#define VFCCU_0_FHIMRKC0_100_RKNEN13_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_100_RKNEN13(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_100_RKNEN13_SHIFT)) & VFCCU_0_FHIMRKC0_100_RKNEN13_MASK)

#define VFCCU_0_FHIMRKC0_100_RKNEN14_MASK        (0x10000U)
#define VFCCU_0_FHIMRKC0_100_RKNEN14_SHIFT       (16U)
#define VFCCU_0_FHIMRKC0_100_RKNEN14_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_100_RKNEN14(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_100_RKNEN14_SHIFT)) & VFCCU_0_FHIMRKC0_100_RKNEN14_MASK)

#define VFCCU_0_FHIMRKC0_100_RKNEN15_MASK        (0x20000U)
#define VFCCU_0_FHIMRKC0_100_RKNEN15_SHIFT       (17U)
#define VFCCU_0_FHIMRKC0_100_RKNEN15_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_100_RKNEN15(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_100_RKNEN15_SHIFT)) & VFCCU_0_FHIMRKC0_100_RKNEN15_MASK)

#define VFCCU_0_FHIMRKC0_100_RKNEN16_MASK        (0x40000U)
#define VFCCU_0_FHIMRKC0_100_RKNEN16_SHIFT       (18U)
#define VFCCU_0_FHIMRKC0_100_RKNEN16_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_100_RKNEN16(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_100_RKNEN16_SHIFT)) & VFCCU_0_FHIMRKC0_100_RKNEN16_MASK)

#define VFCCU_0_FHIMRKC0_100_RKNEN17_MASK        (0x80000U)
#define VFCCU_0_FHIMRKC0_100_RKNEN17_SHIFT       (19U)
#define VFCCU_0_FHIMRKC0_100_RKNEN17_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_100_RKNEN17(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_100_RKNEN17_SHIFT)) & VFCCU_0_FHIMRKC0_100_RKNEN17_MASK)

#define VFCCU_0_FHIMRKC0_100_RKNEN18_MASK        (0x100000U)
#define VFCCU_0_FHIMRKC0_100_RKNEN18_SHIFT       (20U)
#define VFCCU_0_FHIMRKC0_100_RKNEN18_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_100_RKNEN18(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_100_RKNEN18_SHIFT)) & VFCCU_0_FHIMRKC0_100_RKNEN18_MASK)

#define VFCCU_0_FHIMRKC0_100_RKNEN19_MASK        (0x200000U)
#define VFCCU_0_FHIMRKC0_100_RKNEN19_SHIFT       (21U)
#define VFCCU_0_FHIMRKC0_100_RKNEN19_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_100_RKNEN19(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_100_RKNEN19_SHIFT)) & VFCCU_0_FHIMRKC0_100_RKNEN19_MASK)

#define VFCCU_0_FHIMRKC0_100_RKNEN20_MASK        (0x400000U)
#define VFCCU_0_FHIMRKC0_100_RKNEN20_SHIFT       (22U)
#define VFCCU_0_FHIMRKC0_100_RKNEN20_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_100_RKNEN20(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_100_RKNEN20_SHIFT)) & VFCCU_0_FHIMRKC0_100_RKNEN20_MASK)

#define VFCCU_0_FHIMRKC0_100_RKNEN21_MASK        (0x800000U)
#define VFCCU_0_FHIMRKC0_100_RKNEN21_SHIFT       (23U)
#define VFCCU_0_FHIMRKC0_100_RKNEN21_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_100_RKNEN21(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_100_RKNEN21_SHIFT)) & VFCCU_0_FHIMRKC0_100_RKNEN21_MASK)

#define VFCCU_0_FHIMRKC0_100_RKNEN22_MASK        (0x1000000U)
#define VFCCU_0_FHIMRKC0_100_RKNEN22_SHIFT       (24U)
#define VFCCU_0_FHIMRKC0_100_RKNEN22_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_100_RKNEN22(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_100_RKNEN22_SHIFT)) & VFCCU_0_FHIMRKC0_100_RKNEN22_MASK)

#define VFCCU_0_FHIMRKC0_100_RKNEN23_MASK        (0x2000000U)
#define VFCCU_0_FHIMRKC0_100_RKNEN23_SHIFT       (25U)
#define VFCCU_0_FHIMRKC0_100_RKNEN23_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_100_RKNEN23(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_100_RKNEN23_SHIFT)) & VFCCU_0_FHIMRKC0_100_RKNEN23_MASK)

#define VFCCU_0_FHIMRKC0_100_RKNEN24_MASK        (0x4000000U)
#define VFCCU_0_FHIMRKC0_100_RKNEN24_SHIFT       (26U)
#define VFCCU_0_FHIMRKC0_100_RKNEN24_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_100_RKNEN24(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_100_RKNEN24_SHIFT)) & VFCCU_0_FHIMRKC0_100_RKNEN24_MASK)

#define VFCCU_0_FHIMRKC0_100_RKNEN25_MASK        (0x8000000U)
#define VFCCU_0_FHIMRKC0_100_RKNEN25_SHIFT       (27U)
#define VFCCU_0_FHIMRKC0_100_RKNEN25_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_100_RKNEN25(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_100_RKNEN25_SHIFT)) & VFCCU_0_FHIMRKC0_100_RKNEN25_MASK)

#define VFCCU_0_FHIMRKC0_100_RKNEN26_MASK        (0x10000000U)
#define VFCCU_0_FHIMRKC0_100_RKNEN26_SHIFT       (28U)
#define VFCCU_0_FHIMRKC0_100_RKNEN26_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_100_RKNEN26(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_100_RKNEN26_SHIFT)) & VFCCU_0_FHIMRKC0_100_RKNEN26_MASK)

#define VFCCU_0_FHIMRKC0_100_RKNEN27_MASK        (0x20000000U)
#define VFCCU_0_FHIMRKC0_100_RKNEN27_SHIFT       (29U)
#define VFCCU_0_FHIMRKC0_100_RKNEN27_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_100_RKNEN27(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_100_RKNEN27_SHIFT)) & VFCCU_0_FHIMRKC0_100_RKNEN27_MASK)

#define VFCCU_0_FHIMRKC0_100_RKNEN28_MASK        (0x40000000U)
#define VFCCU_0_FHIMRKC0_100_RKNEN28_SHIFT       (30U)
#define VFCCU_0_FHIMRKC0_100_RKNEN28_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_100_RKNEN28(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_100_RKNEN28_SHIFT)) & VFCCU_0_FHIMRKC0_100_RKNEN28_MASK)

#define VFCCU_0_FHIMRKC0_100_RKNEN29_MASK        (0x80000000U)
#define VFCCU_0_FHIMRKC0_100_RKNEN29_SHIFT       (31U)
#define VFCCU_0_FHIMRKC0_100_RKNEN29_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_100_RKNEN29(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_100_RKNEN29_SHIFT)) & VFCCU_0_FHIMRKC0_100_RKNEN29_MASK)
/*! @} */

/*! @name FHDLRKC0_100 - Delayed Reaction Configuration */
/*! @{ */

#define VFCCU_0_FHDLRKC0_100_EOUTEN0_MASK        (0x1U)
#define VFCCU_0_FHDLRKC0_100_EOUTEN0_SHIFT       (0U)
#define VFCCU_0_FHDLRKC0_100_EOUTEN0_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_100_EOUTEN0(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_100_EOUTEN0_SHIFT)) & VFCCU_0_FHDLRKC0_100_EOUTEN0_MASK)

#define VFCCU_0_FHDLRKC0_100_EOUTEN1_MASK        (0x2U)
#define VFCCU_0_FHDLRKC0_100_EOUTEN1_SHIFT       (1U)
#define VFCCU_0_FHDLRKC0_100_EOUTEN1_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_100_EOUTEN1(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_100_EOUTEN1_SHIFT)) & VFCCU_0_FHDLRKC0_100_EOUTEN1_MASK)

#define VFCCU_0_FHDLRKC0_100_RKNEN0_MASK         (0x4U)
#define VFCCU_0_FHDLRKC0_100_RKNEN0_SHIFT        (2U)
#define VFCCU_0_FHDLRKC0_100_RKNEN0_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_100_RKNEN0(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_100_RKNEN0_SHIFT)) & VFCCU_0_FHDLRKC0_100_RKNEN0_MASK)

#define VFCCU_0_FHDLRKC0_100_RKNEN1_MASK         (0x8U)
#define VFCCU_0_FHDLRKC0_100_RKNEN1_SHIFT        (3U)
#define VFCCU_0_FHDLRKC0_100_RKNEN1_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_100_RKNEN1(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_100_RKNEN1_SHIFT)) & VFCCU_0_FHDLRKC0_100_RKNEN1_MASK)

#define VFCCU_0_FHDLRKC0_100_RKNEN2_MASK         (0x10U)
#define VFCCU_0_FHDLRKC0_100_RKNEN2_SHIFT        (4U)
#define VFCCU_0_FHDLRKC0_100_RKNEN2_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_100_RKNEN2(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_100_RKNEN2_SHIFT)) & VFCCU_0_FHDLRKC0_100_RKNEN2_MASK)

#define VFCCU_0_FHDLRKC0_100_RKNEN3_MASK         (0x20U)
#define VFCCU_0_FHDLRKC0_100_RKNEN3_SHIFT        (5U)
#define VFCCU_0_FHDLRKC0_100_RKNEN3_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_100_RKNEN3(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_100_RKNEN3_SHIFT)) & VFCCU_0_FHDLRKC0_100_RKNEN3_MASK)

#define VFCCU_0_FHDLRKC0_100_RKNEN4_MASK         (0x40U)
#define VFCCU_0_FHDLRKC0_100_RKNEN4_SHIFT        (6U)
#define VFCCU_0_FHDLRKC0_100_RKNEN4_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_100_RKNEN4(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_100_RKNEN4_SHIFT)) & VFCCU_0_FHDLRKC0_100_RKNEN4_MASK)

#define VFCCU_0_FHDLRKC0_100_RKNEN5_MASK         (0x80U)
#define VFCCU_0_FHDLRKC0_100_RKNEN5_SHIFT        (7U)
#define VFCCU_0_FHDLRKC0_100_RKNEN5_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_100_RKNEN5(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_100_RKNEN5_SHIFT)) & VFCCU_0_FHDLRKC0_100_RKNEN5_MASK)

#define VFCCU_0_FHDLRKC0_100_RKNEN6_MASK         (0x100U)
#define VFCCU_0_FHDLRKC0_100_RKNEN6_SHIFT        (8U)
#define VFCCU_0_FHDLRKC0_100_RKNEN6_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_100_RKNEN6(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_100_RKNEN6_SHIFT)) & VFCCU_0_FHDLRKC0_100_RKNEN6_MASK)

#define VFCCU_0_FHDLRKC0_100_RKNEN7_MASK         (0x200U)
#define VFCCU_0_FHDLRKC0_100_RKNEN7_SHIFT        (9U)
#define VFCCU_0_FHDLRKC0_100_RKNEN7_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_100_RKNEN7(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_100_RKNEN7_SHIFT)) & VFCCU_0_FHDLRKC0_100_RKNEN7_MASK)

#define VFCCU_0_FHDLRKC0_100_RKNEN8_MASK         (0x400U)
#define VFCCU_0_FHDLRKC0_100_RKNEN8_SHIFT        (10U)
#define VFCCU_0_FHDLRKC0_100_RKNEN8_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_100_RKNEN8(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_100_RKNEN8_SHIFT)) & VFCCU_0_FHDLRKC0_100_RKNEN8_MASK)

#define VFCCU_0_FHDLRKC0_100_RKNEN9_MASK         (0x800U)
#define VFCCU_0_FHDLRKC0_100_RKNEN9_SHIFT        (11U)
#define VFCCU_0_FHDLRKC0_100_RKNEN9_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_100_RKNEN9(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_100_RKNEN9_SHIFT)) & VFCCU_0_FHDLRKC0_100_RKNEN9_MASK)

#define VFCCU_0_FHDLRKC0_100_RKNEN10_MASK        (0x1000U)
#define VFCCU_0_FHDLRKC0_100_RKNEN10_SHIFT       (12U)
#define VFCCU_0_FHDLRKC0_100_RKNEN10_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_100_RKNEN10(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_100_RKNEN10_SHIFT)) & VFCCU_0_FHDLRKC0_100_RKNEN10_MASK)

#define VFCCU_0_FHDLRKC0_100_RKNEN11_MASK        (0x2000U)
#define VFCCU_0_FHDLRKC0_100_RKNEN11_SHIFT       (13U)
#define VFCCU_0_FHDLRKC0_100_RKNEN11_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_100_RKNEN11(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_100_RKNEN11_SHIFT)) & VFCCU_0_FHDLRKC0_100_RKNEN11_MASK)

#define VFCCU_0_FHDLRKC0_100_RKNEN12_MASK        (0x4000U)
#define VFCCU_0_FHDLRKC0_100_RKNEN12_SHIFT       (14U)
#define VFCCU_0_FHDLRKC0_100_RKNEN12_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_100_RKNEN12(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_100_RKNEN12_SHIFT)) & VFCCU_0_FHDLRKC0_100_RKNEN12_MASK)

#define VFCCU_0_FHDLRKC0_100_RKNEN13_MASK        (0x8000U)
#define VFCCU_0_FHDLRKC0_100_RKNEN13_SHIFT       (15U)
#define VFCCU_0_FHDLRKC0_100_RKNEN13_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_100_RKNEN13(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_100_RKNEN13_SHIFT)) & VFCCU_0_FHDLRKC0_100_RKNEN13_MASK)

#define VFCCU_0_FHDLRKC0_100_RKNEN14_MASK        (0x10000U)
#define VFCCU_0_FHDLRKC0_100_RKNEN14_SHIFT       (16U)
#define VFCCU_0_FHDLRKC0_100_RKNEN14_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_100_RKNEN14(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_100_RKNEN14_SHIFT)) & VFCCU_0_FHDLRKC0_100_RKNEN14_MASK)

#define VFCCU_0_FHDLRKC0_100_RKNEN15_MASK        (0x20000U)
#define VFCCU_0_FHDLRKC0_100_RKNEN15_SHIFT       (17U)
#define VFCCU_0_FHDLRKC0_100_RKNEN15_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_100_RKNEN15(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_100_RKNEN15_SHIFT)) & VFCCU_0_FHDLRKC0_100_RKNEN15_MASK)

#define VFCCU_0_FHDLRKC0_100_RKNEN16_MASK        (0x40000U)
#define VFCCU_0_FHDLRKC0_100_RKNEN16_SHIFT       (18U)
#define VFCCU_0_FHDLRKC0_100_RKNEN16_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_100_RKNEN16(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_100_RKNEN16_SHIFT)) & VFCCU_0_FHDLRKC0_100_RKNEN16_MASK)

#define VFCCU_0_FHDLRKC0_100_RKNEN17_MASK        (0x80000U)
#define VFCCU_0_FHDLRKC0_100_RKNEN17_SHIFT       (19U)
#define VFCCU_0_FHDLRKC0_100_RKNEN17_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_100_RKNEN17(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_100_RKNEN17_SHIFT)) & VFCCU_0_FHDLRKC0_100_RKNEN17_MASK)

#define VFCCU_0_FHDLRKC0_100_RKNEN18_MASK        (0x100000U)
#define VFCCU_0_FHDLRKC0_100_RKNEN18_SHIFT       (20U)
#define VFCCU_0_FHDLRKC0_100_RKNEN18_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_100_RKNEN18(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_100_RKNEN18_SHIFT)) & VFCCU_0_FHDLRKC0_100_RKNEN18_MASK)

#define VFCCU_0_FHDLRKC0_100_RKNEN19_MASK        (0x200000U)
#define VFCCU_0_FHDLRKC0_100_RKNEN19_SHIFT       (21U)
#define VFCCU_0_FHDLRKC0_100_RKNEN19_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_100_RKNEN19(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_100_RKNEN19_SHIFT)) & VFCCU_0_FHDLRKC0_100_RKNEN19_MASK)

#define VFCCU_0_FHDLRKC0_100_RKNEN20_MASK        (0x400000U)
#define VFCCU_0_FHDLRKC0_100_RKNEN20_SHIFT       (22U)
#define VFCCU_0_FHDLRKC0_100_RKNEN20_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_100_RKNEN20(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_100_RKNEN20_SHIFT)) & VFCCU_0_FHDLRKC0_100_RKNEN20_MASK)

#define VFCCU_0_FHDLRKC0_100_RKNEN21_MASK        (0x800000U)
#define VFCCU_0_FHDLRKC0_100_RKNEN21_SHIFT       (23U)
#define VFCCU_0_FHDLRKC0_100_RKNEN21_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_100_RKNEN21(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_100_RKNEN21_SHIFT)) & VFCCU_0_FHDLRKC0_100_RKNEN21_MASK)

#define VFCCU_0_FHDLRKC0_100_RKNEN22_MASK        (0x1000000U)
#define VFCCU_0_FHDLRKC0_100_RKNEN22_SHIFT       (24U)
#define VFCCU_0_FHDLRKC0_100_RKNEN22_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_100_RKNEN22(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_100_RKNEN22_SHIFT)) & VFCCU_0_FHDLRKC0_100_RKNEN22_MASK)

#define VFCCU_0_FHDLRKC0_100_RKNEN23_MASK        (0x2000000U)
#define VFCCU_0_FHDLRKC0_100_RKNEN23_SHIFT       (25U)
#define VFCCU_0_FHDLRKC0_100_RKNEN23_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_100_RKNEN23(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_100_RKNEN23_SHIFT)) & VFCCU_0_FHDLRKC0_100_RKNEN23_MASK)

#define VFCCU_0_FHDLRKC0_100_RKNEN24_MASK        (0x4000000U)
#define VFCCU_0_FHDLRKC0_100_RKNEN24_SHIFT       (26U)
#define VFCCU_0_FHDLRKC0_100_RKNEN24_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_100_RKNEN24(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_100_RKNEN24_SHIFT)) & VFCCU_0_FHDLRKC0_100_RKNEN24_MASK)

#define VFCCU_0_FHDLRKC0_100_RKNEN25_MASK        (0x8000000U)
#define VFCCU_0_FHDLRKC0_100_RKNEN25_SHIFT       (27U)
#define VFCCU_0_FHDLRKC0_100_RKNEN25_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_100_RKNEN25(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_100_RKNEN25_SHIFT)) & VFCCU_0_FHDLRKC0_100_RKNEN25_MASK)

#define VFCCU_0_FHDLRKC0_100_RKNEN26_MASK        (0x10000000U)
#define VFCCU_0_FHDLRKC0_100_RKNEN26_SHIFT       (28U)
#define VFCCU_0_FHDLRKC0_100_RKNEN26_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_100_RKNEN26(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_100_RKNEN26_SHIFT)) & VFCCU_0_FHDLRKC0_100_RKNEN26_MASK)

#define VFCCU_0_FHDLRKC0_100_RKNEN27_MASK        (0x20000000U)
#define VFCCU_0_FHDLRKC0_100_RKNEN27_SHIFT       (29U)
#define VFCCU_0_FHDLRKC0_100_RKNEN27_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_100_RKNEN27(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_100_RKNEN27_SHIFT)) & VFCCU_0_FHDLRKC0_100_RKNEN27_MASK)

#define VFCCU_0_FHDLRKC0_100_RKNEN28_MASK        (0x40000000U)
#define VFCCU_0_FHDLRKC0_100_RKNEN28_SHIFT       (30U)
#define VFCCU_0_FHDLRKC0_100_RKNEN28_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_100_RKNEN28(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_100_RKNEN28_SHIFT)) & VFCCU_0_FHDLRKC0_100_RKNEN28_MASK)

#define VFCCU_0_FHDLRKC0_100_RKNEN29_MASK        (0x80000000U)
#define VFCCU_0_FHDLRKC0_100_RKNEN29_SHIFT       (31U)
#define VFCCU_0_FHDLRKC0_100_RKNEN29_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_100_RKNEN29(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_100_RKNEN29_SHIFT)) & VFCCU_0_FHDLRKC0_100_RKNEN29_MASK)
/*! @} */

/*! @name FHIMRKC0_110 - Immediate Reaction Configuration */
/*! @{ */

#define VFCCU_0_FHIMRKC0_110_EOUTEN0_MASK        (0x1U)
#define VFCCU_0_FHIMRKC0_110_EOUTEN0_SHIFT       (0U)
#define VFCCU_0_FHIMRKC0_110_EOUTEN0_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_110_EOUTEN0(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_110_EOUTEN0_SHIFT)) & VFCCU_0_FHIMRKC0_110_EOUTEN0_MASK)

#define VFCCU_0_FHIMRKC0_110_EOUTEN1_MASK        (0x2U)
#define VFCCU_0_FHIMRKC0_110_EOUTEN1_SHIFT       (1U)
#define VFCCU_0_FHIMRKC0_110_EOUTEN1_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_110_EOUTEN1(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_110_EOUTEN1_SHIFT)) & VFCCU_0_FHIMRKC0_110_EOUTEN1_MASK)

#define VFCCU_0_FHIMRKC0_110_RKNEN0_MASK         (0x4U)
#define VFCCU_0_FHIMRKC0_110_RKNEN0_SHIFT        (2U)
#define VFCCU_0_FHIMRKC0_110_RKNEN0_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_110_RKNEN0(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_110_RKNEN0_SHIFT)) & VFCCU_0_FHIMRKC0_110_RKNEN0_MASK)

#define VFCCU_0_FHIMRKC0_110_RKNEN1_MASK         (0x8U)
#define VFCCU_0_FHIMRKC0_110_RKNEN1_SHIFT        (3U)
#define VFCCU_0_FHIMRKC0_110_RKNEN1_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_110_RKNEN1(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_110_RKNEN1_SHIFT)) & VFCCU_0_FHIMRKC0_110_RKNEN1_MASK)

#define VFCCU_0_FHIMRKC0_110_RKNEN2_MASK         (0x10U)
#define VFCCU_0_FHIMRKC0_110_RKNEN2_SHIFT        (4U)
#define VFCCU_0_FHIMRKC0_110_RKNEN2_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_110_RKNEN2(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_110_RKNEN2_SHIFT)) & VFCCU_0_FHIMRKC0_110_RKNEN2_MASK)

#define VFCCU_0_FHIMRKC0_110_RKNEN3_MASK         (0x20U)
#define VFCCU_0_FHIMRKC0_110_RKNEN3_SHIFT        (5U)
#define VFCCU_0_FHIMRKC0_110_RKNEN3_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_110_RKNEN3(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_110_RKNEN3_SHIFT)) & VFCCU_0_FHIMRKC0_110_RKNEN3_MASK)

#define VFCCU_0_FHIMRKC0_110_RKNEN4_MASK         (0x40U)
#define VFCCU_0_FHIMRKC0_110_RKNEN4_SHIFT        (6U)
#define VFCCU_0_FHIMRKC0_110_RKNEN4_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_110_RKNEN4(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_110_RKNEN4_SHIFT)) & VFCCU_0_FHIMRKC0_110_RKNEN4_MASK)

#define VFCCU_0_FHIMRKC0_110_RKNEN5_MASK         (0x80U)
#define VFCCU_0_FHIMRKC0_110_RKNEN5_SHIFT        (7U)
#define VFCCU_0_FHIMRKC0_110_RKNEN5_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_110_RKNEN5(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_110_RKNEN5_SHIFT)) & VFCCU_0_FHIMRKC0_110_RKNEN5_MASK)

#define VFCCU_0_FHIMRKC0_110_RKNEN6_MASK         (0x100U)
#define VFCCU_0_FHIMRKC0_110_RKNEN6_SHIFT        (8U)
#define VFCCU_0_FHIMRKC0_110_RKNEN6_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_110_RKNEN6(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_110_RKNEN6_SHIFT)) & VFCCU_0_FHIMRKC0_110_RKNEN6_MASK)

#define VFCCU_0_FHIMRKC0_110_RKNEN7_MASK         (0x200U)
#define VFCCU_0_FHIMRKC0_110_RKNEN7_SHIFT        (9U)
#define VFCCU_0_FHIMRKC0_110_RKNEN7_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_110_RKNEN7(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_110_RKNEN7_SHIFT)) & VFCCU_0_FHIMRKC0_110_RKNEN7_MASK)

#define VFCCU_0_FHIMRKC0_110_RKNEN8_MASK         (0x400U)
#define VFCCU_0_FHIMRKC0_110_RKNEN8_SHIFT        (10U)
#define VFCCU_0_FHIMRKC0_110_RKNEN8_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_110_RKNEN8(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_110_RKNEN8_SHIFT)) & VFCCU_0_FHIMRKC0_110_RKNEN8_MASK)

#define VFCCU_0_FHIMRKC0_110_RKNEN9_MASK         (0x800U)
#define VFCCU_0_FHIMRKC0_110_RKNEN9_SHIFT        (11U)
#define VFCCU_0_FHIMRKC0_110_RKNEN9_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_110_RKNEN9(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_110_RKNEN9_SHIFT)) & VFCCU_0_FHIMRKC0_110_RKNEN9_MASK)

#define VFCCU_0_FHIMRKC0_110_RKNEN10_MASK        (0x1000U)
#define VFCCU_0_FHIMRKC0_110_RKNEN10_SHIFT       (12U)
#define VFCCU_0_FHIMRKC0_110_RKNEN10_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_110_RKNEN10(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_110_RKNEN10_SHIFT)) & VFCCU_0_FHIMRKC0_110_RKNEN10_MASK)

#define VFCCU_0_FHIMRKC0_110_RKNEN11_MASK        (0x2000U)
#define VFCCU_0_FHIMRKC0_110_RKNEN11_SHIFT       (13U)
#define VFCCU_0_FHIMRKC0_110_RKNEN11_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_110_RKNEN11(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_110_RKNEN11_SHIFT)) & VFCCU_0_FHIMRKC0_110_RKNEN11_MASK)

#define VFCCU_0_FHIMRKC0_110_RKNEN12_MASK        (0x4000U)
#define VFCCU_0_FHIMRKC0_110_RKNEN12_SHIFT       (14U)
#define VFCCU_0_FHIMRKC0_110_RKNEN12_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_110_RKNEN12(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_110_RKNEN12_SHIFT)) & VFCCU_0_FHIMRKC0_110_RKNEN12_MASK)

#define VFCCU_0_FHIMRKC0_110_RKNEN13_MASK        (0x8000U)
#define VFCCU_0_FHIMRKC0_110_RKNEN13_SHIFT       (15U)
#define VFCCU_0_FHIMRKC0_110_RKNEN13_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_110_RKNEN13(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_110_RKNEN13_SHIFT)) & VFCCU_0_FHIMRKC0_110_RKNEN13_MASK)

#define VFCCU_0_FHIMRKC0_110_RKNEN14_MASK        (0x10000U)
#define VFCCU_0_FHIMRKC0_110_RKNEN14_SHIFT       (16U)
#define VFCCU_0_FHIMRKC0_110_RKNEN14_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_110_RKNEN14(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_110_RKNEN14_SHIFT)) & VFCCU_0_FHIMRKC0_110_RKNEN14_MASK)

#define VFCCU_0_FHIMRKC0_110_RKNEN15_MASK        (0x20000U)
#define VFCCU_0_FHIMRKC0_110_RKNEN15_SHIFT       (17U)
#define VFCCU_0_FHIMRKC0_110_RKNEN15_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_110_RKNEN15(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_110_RKNEN15_SHIFT)) & VFCCU_0_FHIMRKC0_110_RKNEN15_MASK)

#define VFCCU_0_FHIMRKC0_110_RKNEN16_MASK        (0x40000U)
#define VFCCU_0_FHIMRKC0_110_RKNEN16_SHIFT       (18U)
#define VFCCU_0_FHIMRKC0_110_RKNEN16_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_110_RKNEN16(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_110_RKNEN16_SHIFT)) & VFCCU_0_FHIMRKC0_110_RKNEN16_MASK)

#define VFCCU_0_FHIMRKC0_110_RKNEN17_MASK        (0x80000U)
#define VFCCU_0_FHIMRKC0_110_RKNEN17_SHIFT       (19U)
#define VFCCU_0_FHIMRKC0_110_RKNEN17_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_110_RKNEN17(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_110_RKNEN17_SHIFT)) & VFCCU_0_FHIMRKC0_110_RKNEN17_MASK)

#define VFCCU_0_FHIMRKC0_110_RKNEN18_MASK        (0x100000U)
#define VFCCU_0_FHIMRKC0_110_RKNEN18_SHIFT       (20U)
#define VFCCU_0_FHIMRKC0_110_RKNEN18_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_110_RKNEN18(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_110_RKNEN18_SHIFT)) & VFCCU_0_FHIMRKC0_110_RKNEN18_MASK)

#define VFCCU_0_FHIMRKC0_110_RKNEN19_MASK        (0x200000U)
#define VFCCU_0_FHIMRKC0_110_RKNEN19_SHIFT       (21U)
#define VFCCU_0_FHIMRKC0_110_RKNEN19_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_110_RKNEN19(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_110_RKNEN19_SHIFT)) & VFCCU_0_FHIMRKC0_110_RKNEN19_MASK)

#define VFCCU_0_FHIMRKC0_110_RKNEN20_MASK        (0x400000U)
#define VFCCU_0_FHIMRKC0_110_RKNEN20_SHIFT       (22U)
#define VFCCU_0_FHIMRKC0_110_RKNEN20_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_110_RKNEN20(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_110_RKNEN20_SHIFT)) & VFCCU_0_FHIMRKC0_110_RKNEN20_MASK)

#define VFCCU_0_FHIMRKC0_110_RKNEN21_MASK        (0x800000U)
#define VFCCU_0_FHIMRKC0_110_RKNEN21_SHIFT       (23U)
#define VFCCU_0_FHIMRKC0_110_RKNEN21_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_110_RKNEN21(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_110_RKNEN21_SHIFT)) & VFCCU_0_FHIMRKC0_110_RKNEN21_MASK)

#define VFCCU_0_FHIMRKC0_110_RKNEN22_MASK        (0x1000000U)
#define VFCCU_0_FHIMRKC0_110_RKNEN22_SHIFT       (24U)
#define VFCCU_0_FHIMRKC0_110_RKNEN22_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_110_RKNEN22(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_110_RKNEN22_SHIFT)) & VFCCU_0_FHIMRKC0_110_RKNEN22_MASK)

#define VFCCU_0_FHIMRKC0_110_RKNEN23_MASK        (0x2000000U)
#define VFCCU_0_FHIMRKC0_110_RKNEN23_SHIFT       (25U)
#define VFCCU_0_FHIMRKC0_110_RKNEN23_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_110_RKNEN23(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_110_RKNEN23_SHIFT)) & VFCCU_0_FHIMRKC0_110_RKNEN23_MASK)

#define VFCCU_0_FHIMRKC0_110_RKNEN24_MASK        (0x4000000U)
#define VFCCU_0_FHIMRKC0_110_RKNEN24_SHIFT       (26U)
#define VFCCU_0_FHIMRKC0_110_RKNEN24_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_110_RKNEN24(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_110_RKNEN24_SHIFT)) & VFCCU_0_FHIMRKC0_110_RKNEN24_MASK)

#define VFCCU_0_FHIMRKC0_110_RKNEN25_MASK        (0x8000000U)
#define VFCCU_0_FHIMRKC0_110_RKNEN25_SHIFT       (27U)
#define VFCCU_0_FHIMRKC0_110_RKNEN25_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_110_RKNEN25(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_110_RKNEN25_SHIFT)) & VFCCU_0_FHIMRKC0_110_RKNEN25_MASK)

#define VFCCU_0_FHIMRKC0_110_RKNEN26_MASK        (0x10000000U)
#define VFCCU_0_FHIMRKC0_110_RKNEN26_SHIFT       (28U)
#define VFCCU_0_FHIMRKC0_110_RKNEN26_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_110_RKNEN26(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_110_RKNEN26_SHIFT)) & VFCCU_0_FHIMRKC0_110_RKNEN26_MASK)

#define VFCCU_0_FHIMRKC0_110_RKNEN27_MASK        (0x20000000U)
#define VFCCU_0_FHIMRKC0_110_RKNEN27_SHIFT       (29U)
#define VFCCU_0_FHIMRKC0_110_RKNEN27_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_110_RKNEN27(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_110_RKNEN27_SHIFT)) & VFCCU_0_FHIMRKC0_110_RKNEN27_MASK)

#define VFCCU_0_FHIMRKC0_110_RKNEN28_MASK        (0x40000000U)
#define VFCCU_0_FHIMRKC0_110_RKNEN28_SHIFT       (30U)
#define VFCCU_0_FHIMRKC0_110_RKNEN28_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_110_RKNEN28(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_110_RKNEN28_SHIFT)) & VFCCU_0_FHIMRKC0_110_RKNEN28_MASK)

#define VFCCU_0_FHIMRKC0_110_RKNEN29_MASK        (0x80000000U)
#define VFCCU_0_FHIMRKC0_110_RKNEN29_SHIFT       (31U)
#define VFCCU_0_FHIMRKC0_110_RKNEN29_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_110_RKNEN29(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_110_RKNEN29_SHIFT)) & VFCCU_0_FHIMRKC0_110_RKNEN29_MASK)
/*! @} */

/*! @name FHDLRKC0_110 - Delayed Reaction Configuration */
/*! @{ */

#define VFCCU_0_FHDLRKC0_110_EOUTEN0_MASK        (0x1U)
#define VFCCU_0_FHDLRKC0_110_EOUTEN0_SHIFT       (0U)
#define VFCCU_0_FHDLRKC0_110_EOUTEN0_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_110_EOUTEN0(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_110_EOUTEN0_SHIFT)) & VFCCU_0_FHDLRKC0_110_EOUTEN0_MASK)

#define VFCCU_0_FHDLRKC0_110_EOUTEN1_MASK        (0x2U)
#define VFCCU_0_FHDLRKC0_110_EOUTEN1_SHIFT       (1U)
#define VFCCU_0_FHDLRKC0_110_EOUTEN1_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_110_EOUTEN1(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_110_EOUTEN1_SHIFT)) & VFCCU_0_FHDLRKC0_110_EOUTEN1_MASK)

#define VFCCU_0_FHDLRKC0_110_RKNEN0_MASK         (0x4U)
#define VFCCU_0_FHDLRKC0_110_RKNEN0_SHIFT        (2U)
#define VFCCU_0_FHDLRKC0_110_RKNEN0_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_110_RKNEN0(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_110_RKNEN0_SHIFT)) & VFCCU_0_FHDLRKC0_110_RKNEN0_MASK)

#define VFCCU_0_FHDLRKC0_110_RKNEN1_MASK         (0x8U)
#define VFCCU_0_FHDLRKC0_110_RKNEN1_SHIFT        (3U)
#define VFCCU_0_FHDLRKC0_110_RKNEN1_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_110_RKNEN1(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_110_RKNEN1_SHIFT)) & VFCCU_0_FHDLRKC0_110_RKNEN1_MASK)

#define VFCCU_0_FHDLRKC0_110_RKNEN2_MASK         (0x10U)
#define VFCCU_0_FHDLRKC0_110_RKNEN2_SHIFT        (4U)
#define VFCCU_0_FHDLRKC0_110_RKNEN2_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_110_RKNEN2(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_110_RKNEN2_SHIFT)) & VFCCU_0_FHDLRKC0_110_RKNEN2_MASK)

#define VFCCU_0_FHDLRKC0_110_RKNEN3_MASK         (0x20U)
#define VFCCU_0_FHDLRKC0_110_RKNEN3_SHIFT        (5U)
#define VFCCU_0_FHDLRKC0_110_RKNEN3_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_110_RKNEN3(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_110_RKNEN3_SHIFT)) & VFCCU_0_FHDLRKC0_110_RKNEN3_MASK)

#define VFCCU_0_FHDLRKC0_110_RKNEN4_MASK         (0x40U)
#define VFCCU_0_FHDLRKC0_110_RKNEN4_SHIFT        (6U)
#define VFCCU_0_FHDLRKC0_110_RKNEN4_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_110_RKNEN4(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_110_RKNEN4_SHIFT)) & VFCCU_0_FHDLRKC0_110_RKNEN4_MASK)

#define VFCCU_0_FHDLRKC0_110_RKNEN5_MASK         (0x80U)
#define VFCCU_0_FHDLRKC0_110_RKNEN5_SHIFT        (7U)
#define VFCCU_0_FHDLRKC0_110_RKNEN5_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_110_RKNEN5(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_110_RKNEN5_SHIFT)) & VFCCU_0_FHDLRKC0_110_RKNEN5_MASK)

#define VFCCU_0_FHDLRKC0_110_RKNEN6_MASK         (0x100U)
#define VFCCU_0_FHDLRKC0_110_RKNEN6_SHIFT        (8U)
#define VFCCU_0_FHDLRKC0_110_RKNEN6_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_110_RKNEN6(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_110_RKNEN6_SHIFT)) & VFCCU_0_FHDLRKC0_110_RKNEN6_MASK)

#define VFCCU_0_FHDLRKC0_110_RKNEN7_MASK         (0x200U)
#define VFCCU_0_FHDLRKC0_110_RKNEN7_SHIFT        (9U)
#define VFCCU_0_FHDLRKC0_110_RKNEN7_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_110_RKNEN7(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_110_RKNEN7_SHIFT)) & VFCCU_0_FHDLRKC0_110_RKNEN7_MASK)

#define VFCCU_0_FHDLRKC0_110_RKNEN8_MASK         (0x400U)
#define VFCCU_0_FHDLRKC0_110_RKNEN8_SHIFT        (10U)
#define VFCCU_0_FHDLRKC0_110_RKNEN8_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_110_RKNEN8(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_110_RKNEN8_SHIFT)) & VFCCU_0_FHDLRKC0_110_RKNEN8_MASK)

#define VFCCU_0_FHDLRKC0_110_RKNEN9_MASK         (0x800U)
#define VFCCU_0_FHDLRKC0_110_RKNEN9_SHIFT        (11U)
#define VFCCU_0_FHDLRKC0_110_RKNEN9_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_110_RKNEN9(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_110_RKNEN9_SHIFT)) & VFCCU_0_FHDLRKC0_110_RKNEN9_MASK)

#define VFCCU_0_FHDLRKC0_110_RKNEN10_MASK        (0x1000U)
#define VFCCU_0_FHDLRKC0_110_RKNEN10_SHIFT       (12U)
#define VFCCU_0_FHDLRKC0_110_RKNEN10_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_110_RKNEN10(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_110_RKNEN10_SHIFT)) & VFCCU_0_FHDLRKC0_110_RKNEN10_MASK)

#define VFCCU_0_FHDLRKC0_110_RKNEN11_MASK        (0x2000U)
#define VFCCU_0_FHDLRKC0_110_RKNEN11_SHIFT       (13U)
#define VFCCU_0_FHDLRKC0_110_RKNEN11_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_110_RKNEN11(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_110_RKNEN11_SHIFT)) & VFCCU_0_FHDLRKC0_110_RKNEN11_MASK)

#define VFCCU_0_FHDLRKC0_110_RKNEN12_MASK        (0x4000U)
#define VFCCU_0_FHDLRKC0_110_RKNEN12_SHIFT       (14U)
#define VFCCU_0_FHDLRKC0_110_RKNEN12_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_110_RKNEN12(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_110_RKNEN12_SHIFT)) & VFCCU_0_FHDLRKC0_110_RKNEN12_MASK)

#define VFCCU_0_FHDLRKC0_110_RKNEN13_MASK        (0x8000U)
#define VFCCU_0_FHDLRKC0_110_RKNEN13_SHIFT       (15U)
#define VFCCU_0_FHDLRKC0_110_RKNEN13_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_110_RKNEN13(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_110_RKNEN13_SHIFT)) & VFCCU_0_FHDLRKC0_110_RKNEN13_MASK)

#define VFCCU_0_FHDLRKC0_110_RKNEN14_MASK        (0x10000U)
#define VFCCU_0_FHDLRKC0_110_RKNEN14_SHIFT       (16U)
#define VFCCU_0_FHDLRKC0_110_RKNEN14_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_110_RKNEN14(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_110_RKNEN14_SHIFT)) & VFCCU_0_FHDLRKC0_110_RKNEN14_MASK)

#define VFCCU_0_FHDLRKC0_110_RKNEN15_MASK        (0x20000U)
#define VFCCU_0_FHDLRKC0_110_RKNEN15_SHIFT       (17U)
#define VFCCU_0_FHDLRKC0_110_RKNEN15_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_110_RKNEN15(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_110_RKNEN15_SHIFT)) & VFCCU_0_FHDLRKC0_110_RKNEN15_MASK)

#define VFCCU_0_FHDLRKC0_110_RKNEN16_MASK        (0x40000U)
#define VFCCU_0_FHDLRKC0_110_RKNEN16_SHIFT       (18U)
#define VFCCU_0_FHDLRKC0_110_RKNEN16_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_110_RKNEN16(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_110_RKNEN16_SHIFT)) & VFCCU_0_FHDLRKC0_110_RKNEN16_MASK)

#define VFCCU_0_FHDLRKC0_110_RKNEN17_MASK        (0x80000U)
#define VFCCU_0_FHDLRKC0_110_RKNEN17_SHIFT       (19U)
#define VFCCU_0_FHDLRKC0_110_RKNEN17_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_110_RKNEN17(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_110_RKNEN17_SHIFT)) & VFCCU_0_FHDLRKC0_110_RKNEN17_MASK)

#define VFCCU_0_FHDLRKC0_110_RKNEN18_MASK        (0x100000U)
#define VFCCU_0_FHDLRKC0_110_RKNEN18_SHIFT       (20U)
#define VFCCU_0_FHDLRKC0_110_RKNEN18_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_110_RKNEN18(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_110_RKNEN18_SHIFT)) & VFCCU_0_FHDLRKC0_110_RKNEN18_MASK)

#define VFCCU_0_FHDLRKC0_110_RKNEN19_MASK        (0x200000U)
#define VFCCU_0_FHDLRKC0_110_RKNEN19_SHIFT       (21U)
#define VFCCU_0_FHDLRKC0_110_RKNEN19_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_110_RKNEN19(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_110_RKNEN19_SHIFT)) & VFCCU_0_FHDLRKC0_110_RKNEN19_MASK)

#define VFCCU_0_FHDLRKC0_110_RKNEN20_MASK        (0x400000U)
#define VFCCU_0_FHDLRKC0_110_RKNEN20_SHIFT       (22U)
#define VFCCU_0_FHDLRKC0_110_RKNEN20_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_110_RKNEN20(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_110_RKNEN20_SHIFT)) & VFCCU_0_FHDLRKC0_110_RKNEN20_MASK)

#define VFCCU_0_FHDLRKC0_110_RKNEN21_MASK        (0x800000U)
#define VFCCU_0_FHDLRKC0_110_RKNEN21_SHIFT       (23U)
#define VFCCU_0_FHDLRKC0_110_RKNEN21_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_110_RKNEN21(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_110_RKNEN21_SHIFT)) & VFCCU_0_FHDLRKC0_110_RKNEN21_MASK)

#define VFCCU_0_FHDLRKC0_110_RKNEN22_MASK        (0x1000000U)
#define VFCCU_0_FHDLRKC0_110_RKNEN22_SHIFT       (24U)
#define VFCCU_0_FHDLRKC0_110_RKNEN22_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_110_RKNEN22(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_110_RKNEN22_SHIFT)) & VFCCU_0_FHDLRKC0_110_RKNEN22_MASK)

#define VFCCU_0_FHDLRKC0_110_RKNEN23_MASK        (0x2000000U)
#define VFCCU_0_FHDLRKC0_110_RKNEN23_SHIFT       (25U)
#define VFCCU_0_FHDLRKC0_110_RKNEN23_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_110_RKNEN23(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_110_RKNEN23_SHIFT)) & VFCCU_0_FHDLRKC0_110_RKNEN23_MASK)

#define VFCCU_0_FHDLRKC0_110_RKNEN24_MASK        (0x4000000U)
#define VFCCU_0_FHDLRKC0_110_RKNEN24_SHIFT       (26U)
#define VFCCU_0_FHDLRKC0_110_RKNEN24_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_110_RKNEN24(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_110_RKNEN24_SHIFT)) & VFCCU_0_FHDLRKC0_110_RKNEN24_MASK)

#define VFCCU_0_FHDLRKC0_110_RKNEN25_MASK        (0x8000000U)
#define VFCCU_0_FHDLRKC0_110_RKNEN25_SHIFT       (27U)
#define VFCCU_0_FHDLRKC0_110_RKNEN25_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_110_RKNEN25(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_110_RKNEN25_SHIFT)) & VFCCU_0_FHDLRKC0_110_RKNEN25_MASK)

#define VFCCU_0_FHDLRKC0_110_RKNEN26_MASK        (0x10000000U)
#define VFCCU_0_FHDLRKC0_110_RKNEN26_SHIFT       (28U)
#define VFCCU_0_FHDLRKC0_110_RKNEN26_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_110_RKNEN26(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_110_RKNEN26_SHIFT)) & VFCCU_0_FHDLRKC0_110_RKNEN26_MASK)

#define VFCCU_0_FHDLRKC0_110_RKNEN27_MASK        (0x20000000U)
#define VFCCU_0_FHDLRKC0_110_RKNEN27_SHIFT       (29U)
#define VFCCU_0_FHDLRKC0_110_RKNEN27_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_110_RKNEN27(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_110_RKNEN27_SHIFT)) & VFCCU_0_FHDLRKC0_110_RKNEN27_MASK)

#define VFCCU_0_FHDLRKC0_110_RKNEN28_MASK        (0x40000000U)
#define VFCCU_0_FHDLRKC0_110_RKNEN28_SHIFT       (30U)
#define VFCCU_0_FHDLRKC0_110_RKNEN28_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_110_RKNEN28(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_110_RKNEN28_SHIFT)) & VFCCU_0_FHDLRKC0_110_RKNEN28_MASK)

#define VFCCU_0_FHDLRKC0_110_RKNEN29_MASK        (0x80000000U)
#define VFCCU_0_FHDLRKC0_110_RKNEN29_SHIFT       (31U)
#define VFCCU_0_FHDLRKC0_110_RKNEN29_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_110_RKNEN29(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_110_RKNEN29_SHIFT)) & VFCCU_0_FHDLRKC0_110_RKNEN29_MASK)
/*! @} */

/*! @name FHIMRKC0_120 - Immediate Reaction Configuration */
/*! @{ */

#define VFCCU_0_FHIMRKC0_120_EOUTEN0_MASK        (0x1U)
#define VFCCU_0_FHIMRKC0_120_EOUTEN0_SHIFT       (0U)
#define VFCCU_0_FHIMRKC0_120_EOUTEN0_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_120_EOUTEN0(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_120_EOUTEN0_SHIFT)) & VFCCU_0_FHIMRKC0_120_EOUTEN0_MASK)

#define VFCCU_0_FHIMRKC0_120_EOUTEN1_MASK        (0x2U)
#define VFCCU_0_FHIMRKC0_120_EOUTEN1_SHIFT       (1U)
#define VFCCU_0_FHIMRKC0_120_EOUTEN1_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_120_EOUTEN1(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_120_EOUTEN1_SHIFT)) & VFCCU_0_FHIMRKC0_120_EOUTEN1_MASK)

#define VFCCU_0_FHIMRKC0_120_RKNEN0_MASK         (0x4U)
#define VFCCU_0_FHIMRKC0_120_RKNEN0_SHIFT        (2U)
#define VFCCU_0_FHIMRKC0_120_RKNEN0_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_120_RKNEN0(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_120_RKNEN0_SHIFT)) & VFCCU_0_FHIMRKC0_120_RKNEN0_MASK)

#define VFCCU_0_FHIMRKC0_120_RKNEN1_MASK         (0x8U)
#define VFCCU_0_FHIMRKC0_120_RKNEN1_SHIFT        (3U)
#define VFCCU_0_FHIMRKC0_120_RKNEN1_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_120_RKNEN1(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_120_RKNEN1_SHIFT)) & VFCCU_0_FHIMRKC0_120_RKNEN1_MASK)

#define VFCCU_0_FHIMRKC0_120_RKNEN2_MASK         (0x10U)
#define VFCCU_0_FHIMRKC0_120_RKNEN2_SHIFT        (4U)
#define VFCCU_0_FHIMRKC0_120_RKNEN2_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_120_RKNEN2(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_120_RKNEN2_SHIFT)) & VFCCU_0_FHIMRKC0_120_RKNEN2_MASK)

#define VFCCU_0_FHIMRKC0_120_RKNEN3_MASK         (0x20U)
#define VFCCU_0_FHIMRKC0_120_RKNEN3_SHIFT        (5U)
#define VFCCU_0_FHIMRKC0_120_RKNEN3_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_120_RKNEN3(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_120_RKNEN3_SHIFT)) & VFCCU_0_FHIMRKC0_120_RKNEN3_MASK)

#define VFCCU_0_FHIMRKC0_120_RKNEN4_MASK         (0x40U)
#define VFCCU_0_FHIMRKC0_120_RKNEN4_SHIFT        (6U)
#define VFCCU_0_FHIMRKC0_120_RKNEN4_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_120_RKNEN4(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_120_RKNEN4_SHIFT)) & VFCCU_0_FHIMRKC0_120_RKNEN4_MASK)

#define VFCCU_0_FHIMRKC0_120_RKNEN5_MASK         (0x80U)
#define VFCCU_0_FHIMRKC0_120_RKNEN5_SHIFT        (7U)
#define VFCCU_0_FHIMRKC0_120_RKNEN5_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_120_RKNEN5(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_120_RKNEN5_SHIFT)) & VFCCU_0_FHIMRKC0_120_RKNEN5_MASK)

#define VFCCU_0_FHIMRKC0_120_RKNEN6_MASK         (0x100U)
#define VFCCU_0_FHIMRKC0_120_RKNEN6_SHIFT        (8U)
#define VFCCU_0_FHIMRKC0_120_RKNEN6_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_120_RKNEN6(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_120_RKNEN6_SHIFT)) & VFCCU_0_FHIMRKC0_120_RKNEN6_MASK)

#define VFCCU_0_FHIMRKC0_120_RKNEN7_MASK         (0x200U)
#define VFCCU_0_FHIMRKC0_120_RKNEN7_SHIFT        (9U)
#define VFCCU_0_FHIMRKC0_120_RKNEN7_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_120_RKNEN7(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_120_RKNEN7_SHIFT)) & VFCCU_0_FHIMRKC0_120_RKNEN7_MASK)

#define VFCCU_0_FHIMRKC0_120_RKNEN8_MASK         (0x400U)
#define VFCCU_0_FHIMRKC0_120_RKNEN8_SHIFT        (10U)
#define VFCCU_0_FHIMRKC0_120_RKNEN8_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_120_RKNEN8(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_120_RKNEN8_SHIFT)) & VFCCU_0_FHIMRKC0_120_RKNEN8_MASK)

#define VFCCU_0_FHIMRKC0_120_RKNEN9_MASK         (0x800U)
#define VFCCU_0_FHIMRKC0_120_RKNEN9_SHIFT        (11U)
#define VFCCU_0_FHIMRKC0_120_RKNEN9_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_120_RKNEN9(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_120_RKNEN9_SHIFT)) & VFCCU_0_FHIMRKC0_120_RKNEN9_MASK)

#define VFCCU_0_FHIMRKC0_120_RKNEN10_MASK        (0x1000U)
#define VFCCU_0_FHIMRKC0_120_RKNEN10_SHIFT       (12U)
#define VFCCU_0_FHIMRKC0_120_RKNEN10_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_120_RKNEN10(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_120_RKNEN10_SHIFT)) & VFCCU_0_FHIMRKC0_120_RKNEN10_MASK)

#define VFCCU_0_FHIMRKC0_120_RKNEN11_MASK        (0x2000U)
#define VFCCU_0_FHIMRKC0_120_RKNEN11_SHIFT       (13U)
#define VFCCU_0_FHIMRKC0_120_RKNEN11_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_120_RKNEN11(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_120_RKNEN11_SHIFT)) & VFCCU_0_FHIMRKC0_120_RKNEN11_MASK)

#define VFCCU_0_FHIMRKC0_120_RKNEN12_MASK        (0x4000U)
#define VFCCU_0_FHIMRKC0_120_RKNEN12_SHIFT       (14U)
#define VFCCU_0_FHIMRKC0_120_RKNEN12_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_120_RKNEN12(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_120_RKNEN12_SHIFT)) & VFCCU_0_FHIMRKC0_120_RKNEN12_MASK)

#define VFCCU_0_FHIMRKC0_120_RKNEN13_MASK        (0x8000U)
#define VFCCU_0_FHIMRKC0_120_RKNEN13_SHIFT       (15U)
#define VFCCU_0_FHIMRKC0_120_RKNEN13_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_120_RKNEN13(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_120_RKNEN13_SHIFT)) & VFCCU_0_FHIMRKC0_120_RKNEN13_MASK)

#define VFCCU_0_FHIMRKC0_120_RKNEN14_MASK        (0x10000U)
#define VFCCU_0_FHIMRKC0_120_RKNEN14_SHIFT       (16U)
#define VFCCU_0_FHIMRKC0_120_RKNEN14_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_120_RKNEN14(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_120_RKNEN14_SHIFT)) & VFCCU_0_FHIMRKC0_120_RKNEN14_MASK)

#define VFCCU_0_FHIMRKC0_120_RKNEN15_MASK        (0x20000U)
#define VFCCU_0_FHIMRKC0_120_RKNEN15_SHIFT       (17U)
#define VFCCU_0_FHIMRKC0_120_RKNEN15_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_120_RKNEN15(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_120_RKNEN15_SHIFT)) & VFCCU_0_FHIMRKC0_120_RKNEN15_MASK)

#define VFCCU_0_FHIMRKC0_120_RKNEN16_MASK        (0x40000U)
#define VFCCU_0_FHIMRKC0_120_RKNEN16_SHIFT       (18U)
#define VFCCU_0_FHIMRKC0_120_RKNEN16_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_120_RKNEN16(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_120_RKNEN16_SHIFT)) & VFCCU_0_FHIMRKC0_120_RKNEN16_MASK)

#define VFCCU_0_FHIMRKC0_120_RKNEN17_MASK        (0x80000U)
#define VFCCU_0_FHIMRKC0_120_RKNEN17_SHIFT       (19U)
#define VFCCU_0_FHIMRKC0_120_RKNEN17_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_120_RKNEN17(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_120_RKNEN17_SHIFT)) & VFCCU_0_FHIMRKC0_120_RKNEN17_MASK)

#define VFCCU_0_FHIMRKC0_120_RKNEN18_MASK        (0x100000U)
#define VFCCU_0_FHIMRKC0_120_RKNEN18_SHIFT       (20U)
#define VFCCU_0_FHIMRKC0_120_RKNEN18_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_120_RKNEN18(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_120_RKNEN18_SHIFT)) & VFCCU_0_FHIMRKC0_120_RKNEN18_MASK)

#define VFCCU_0_FHIMRKC0_120_RKNEN19_MASK        (0x200000U)
#define VFCCU_0_FHIMRKC0_120_RKNEN19_SHIFT       (21U)
#define VFCCU_0_FHIMRKC0_120_RKNEN19_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_120_RKNEN19(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_120_RKNEN19_SHIFT)) & VFCCU_0_FHIMRKC0_120_RKNEN19_MASK)

#define VFCCU_0_FHIMRKC0_120_RKNEN20_MASK        (0x400000U)
#define VFCCU_0_FHIMRKC0_120_RKNEN20_SHIFT       (22U)
#define VFCCU_0_FHIMRKC0_120_RKNEN20_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_120_RKNEN20(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_120_RKNEN20_SHIFT)) & VFCCU_0_FHIMRKC0_120_RKNEN20_MASK)

#define VFCCU_0_FHIMRKC0_120_RKNEN21_MASK        (0x800000U)
#define VFCCU_0_FHIMRKC0_120_RKNEN21_SHIFT       (23U)
#define VFCCU_0_FHIMRKC0_120_RKNEN21_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_120_RKNEN21(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_120_RKNEN21_SHIFT)) & VFCCU_0_FHIMRKC0_120_RKNEN21_MASK)

#define VFCCU_0_FHIMRKC0_120_RKNEN22_MASK        (0x1000000U)
#define VFCCU_0_FHIMRKC0_120_RKNEN22_SHIFT       (24U)
#define VFCCU_0_FHIMRKC0_120_RKNEN22_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_120_RKNEN22(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_120_RKNEN22_SHIFT)) & VFCCU_0_FHIMRKC0_120_RKNEN22_MASK)

#define VFCCU_0_FHIMRKC0_120_RKNEN23_MASK        (0x2000000U)
#define VFCCU_0_FHIMRKC0_120_RKNEN23_SHIFT       (25U)
#define VFCCU_0_FHIMRKC0_120_RKNEN23_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_120_RKNEN23(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_120_RKNEN23_SHIFT)) & VFCCU_0_FHIMRKC0_120_RKNEN23_MASK)

#define VFCCU_0_FHIMRKC0_120_RKNEN24_MASK        (0x4000000U)
#define VFCCU_0_FHIMRKC0_120_RKNEN24_SHIFT       (26U)
#define VFCCU_0_FHIMRKC0_120_RKNEN24_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_120_RKNEN24(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_120_RKNEN24_SHIFT)) & VFCCU_0_FHIMRKC0_120_RKNEN24_MASK)

#define VFCCU_0_FHIMRKC0_120_RKNEN25_MASK        (0x8000000U)
#define VFCCU_0_FHIMRKC0_120_RKNEN25_SHIFT       (27U)
#define VFCCU_0_FHIMRKC0_120_RKNEN25_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_120_RKNEN25(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_120_RKNEN25_SHIFT)) & VFCCU_0_FHIMRKC0_120_RKNEN25_MASK)

#define VFCCU_0_FHIMRKC0_120_RKNEN26_MASK        (0x10000000U)
#define VFCCU_0_FHIMRKC0_120_RKNEN26_SHIFT       (28U)
#define VFCCU_0_FHIMRKC0_120_RKNEN26_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_120_RKNEN26(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_120_RKNEN26_SHIFT)) & VFCCU_0_FHIMRKC0_120_RKNEN26_MASK)

#define VFCCU_0_FHIMRKC0_120_RKNEN27_MASK        (0x20000000U)
#define VFCCU_0_FHIMRKC0_120_RKNEN27_SHIFT       (29U)
#define VFCCU_0_FHIMRKC0_120_RKNEN27_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_120_RKNEN27(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_120_RKNEN27_SHIFT)) & VFCCU_0_FHIMRKC0_120_RKNEN27_MASK)

#define VFCCU_0_FHIMRKC0_120_RKNEN28_MASK        (0x40000000U)
#define VFCCU_0_FHIMRKC0_120_RKNEN28_SHIFT       (30U)
#define VFCCU_0_FHIMRKC0_120_RKNEN28_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_120_RKNEN28(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_120_RKNEN28_SHIFT)) & VFCCU_0_FHIMRKC0_120_RKNEN28_MASK)

#define VFCCU_0_FHIMRKC0_120_RKNEN29_MASK        (0x80000000U)
#define VFCCU_0_FHIMRKC0_120_RKNEN29_SHIFT       (31U)
#define VFCCU_0_FHIMRKC0_120_RKNEN29_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_120_RKNEN29(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_120_RKNEN29_SHIFT)) & VFCCU_0_FHIMRKC0_120_RKNEN29_MASK)
/*! @} */

/*! @name FHDLRKC0_120 - Delayed Reaction Configuration */
/*! @{ */

#define VFCCU_0_FHDLRKC0_120_EOUTEN0_MASK        (0x1U)
#define VFCCU_0_FHDLRKC0_120_EOUTEN0_SHIFT       (0U)
#define VFCCU_0_FHDLRKC0_120_EOUTEN0_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_120_EOUTEN0(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_120_EOUTEN0_SHIFT)) & VFCCU_0_FHDLRKC0_120_EOUTEN0_MASK)

#define VFCCU_0_FHDLRKC0_120_EOUTEN1_MASK        (0x2U)
#define VFCCU_0_FHDLRKC0_120_EOUTEN1_SHIFT       (1U)
#define VFCCU_0_FHDLRKC0_120_EOUTEN1_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_120_EOUTEN1(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_120_EOUTEN1_SHIFT)) & VFCCU_0_FHDLRKC0_120_EOUTEN1_MASK)

#define VFCCU_0_FHDLRKC0_120_RKNEN0_MASK         (0x4U)
#define VFCCU_0_FHDLRKC0_120_RKNEN0_SHIFT        (2U)
#define VFCCU_0_FHDLRKC0_120_RKNEN0_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_120_RKNEN0(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_120_RKNEN0_SHIFT)) & VFCCU_0_FHDLRKC0_120_RKNEN0_MASK)

#define VFCCU_0_FHDLRKC0_120_RKNEN1_MASK         (0x8U)
#define VFCCU_0_FHDLRKC0_120_RKNEN1_SHIFT        (3U)
#define VFCCU_0_FHDLRKC0_120_RKNEN1_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_120_RKNEN1(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_120_RKNEN1_SHIFT)) & VFCCU_0_FHDLRKC0_120_RKNEN1_MASK)

#define VFCCU_0_FHDLRKC0_120_RKNEN2_MASK         (0x10U)
#define VFCCU_0_FHDLRKC0_120_RKNEN2_SHIFT        (4U)
#define VFCCU_0_FHDLRKC0_120_RKNEN2_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_120_RKNEN2(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_120_RKNEN2_SHIFT)) & VFCCU_0_FHDLRKC0_120_RKNEN2_MASK)

#define VFCCU_0_FHDLRKC0_120_RKNEN3_MASK         (0x20U)
#define VFCCU_0_FHDLRKC0_120_RKNEN3_SHIFT        (5U)
#define VFCCU_0_FHDLRKC0_120_RKNEN3_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_120_RKNEN3(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_120_RKNEN3_SHIFT)) & VFCCU_0_FHDLRKC0_120_RKNEN3_MASK)

#define VFCCU_0_FHDLRKC0_120_RKNEN4_MASK         (0x40U)
#define VFCCU_0_FHDLRKC0_120_RKNEN4_SHIFT        (6U)
#define VFCCU_0_FHDLRKC0_120_RKNEN4_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_120_RKNEN4(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_120_RKNEN4_SHIFT)) & VFCCU_0_FHDLRKC0_120_RKNEN4_MASK)

#define VFCCU_0_FHDLRKC0_120_RKNEN5_MASK         (0x80U)
#define VFCCU_0_FHDLRKC0_120_RKNEN5_SHIFT        (7U)
#define VFCCU_0_FHDLRKC0_120_RKNEN5_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_120_RKNEN5(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_120_RKNEN5_SHIFT)) & VFCCU_0_FHDLRKC0_120_RKNEN5_MASK)

#define VFCCU_0_FHDLRKC0_120_RKNEN6_MASK         (0x100U)
#define VFCCU_0_FHDLRKC0_120_RKNEN6_SHIFT        (8U)
#define VFCCU_0_FHDLRKC0_120_RKNEN6_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_120_RKNEN6(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_120_RKNEN6_SHIFT)) & VFCCU_0_FHDLRKC0_120_RKNEN6_MASK)

#define VFCCU_0_FHDLRKC0_120_RKNEN7_MASK         (0x200U)
#define VFCCU_0_FHDLRKC0_120_RKNEN7_SHIFT        (9U)
#define VFCCU_0_FHDLRKC0_120_RKNEN7_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_120_RKNEN7(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_120_RKNEN7_SHIFT)) & VFCCU_0_FHDLRKC0_120_RKNEN7_MASK)

#define VFCCU_0_FHDLRKC0_120_RKNEN8_MASK         (0x400U)
#define VFCCU_0_FHDLRKC0_120_RKNEN8_SHIFT        (10U)
#define VFCCU_0_FHDLRKC0_120_RKNEN8_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_120_RKNEN8(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_120_RKNEN8_SHIFT)) & VFCCU_0_FHDLRKC0_120_RKNEN8_MASK)

#define VFCCU_0_FHDLRKC0_120_RKNEN9_MASK         (0x800U)
#define VFCCU_0_FHDLRKC0_120_RKNEN9_SHIFT        (11U)
#define VFCCU_0_FHDLRKC0_120_RKNEN9_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_120_RKNEN9(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_120_RKNEN9_SHIFT)) & VFCCU_0_FHDLRKC0_120_RKNEN9_MASK)

#define VFCCU_0_FHDLRKC0_120_RKNEN10_MASK        (0x1000U)
#define VFCCU_0_FHDLRKC0_120_RKNEN10_SHIFT       (12U)
#define VFCCU_0_FHDLRKC0_120_RKNEN10_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_120_RKNEN10(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_120_RKNEN10_SHIFT)) & VFCCU_0_FHDLRKC0_120_RKNEN10_MASK)

#define VFCCU_0_FHDLRKC0_120_RKNEN11_MASK        (0x2000U)
#define VFCCU_0_FHDLRKC0_120_RKNEN11_SHIFT       (13U)
#define VFCCU_0_FHDLRKC0_120_RKNEN11_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_120_RKNEN11(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_120_RKNEN11_SHIFT)) & VFCCU_0_FHDLRKC0_120_RKNEN11_MASK)

#define VFCCU_0_FHDLRKC0_120_RKNEN12_MASK        (0x4000U)
#define VFCCU_0_FHDLRKC0_120_RKNEN12_SHIFT       (14U)
#define VFCCU_0_FHDLRKC0_120_RKNEN12_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_120_RKNEN12(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_120_RKNEN12_SHIFT)) & VFCCU_0_FHDLRKC0_120_RKNEN12_MASK)

#define VFCCU_0_FHDLRKC0_120_RKNEN13_MASK        (0x8000U)
#define VFCCU_0_FHDLRKC0_120_RKNEN13_SHIFT       (15U)
#define VFCCU_0_FHDLRKC0_120_RKNEN13_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_120_RKNEN13(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_120_RKNEN13_SHIFT)) & VFCCU_0_FHDLRKC0_120_RKNEN13_MASK)

#define VFCCU_0_FHDLRKC0_120_RKNEN14_MASK        (0x10000U)
#define VFCCU_0_FHDLRKC0_120_RKNEN14_SHIFT       (16U)
#define VFCCU_0_FHDLRKC0_120_RKNEN14_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_120_RKNEN14(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_120_RKNEN14_SHIFT)) & VFCCU_0_FHDLRKC0_120_RKNEN14_MASK)

#define VFCCU_0_FHDLRKC0_120_RKNEN15_MASK        (0x20000U)
#define VFCCU_0_FHDLRKC0_120_RKNEN15_SHIFT       (17U)
#define VFCCU_0_FHDLRKC0_120_RKNEN15_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_120_RKNEN15(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_120_RKNEN15_SHIFT)) & VFCCU_0_FHDLRKC0_120_RKNEN15_MASK)

#define VFCCU_0_FHDLRKC0_120_RKNEN16_MASK        (0x40000U)
#define VFCCU_0_FHDLRKC0_120_RKNEN16_SHIFT       (18U)
#define VFCCU_0_FHDLRKC0_120_RKNEN16_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_120_RKNEN16(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_120_RKNEN16_SHIFT)) & VFCCU_0_FHDLRKC0_120_RKNEN16_MASK)

#define VFCCU_0_FHDLRKC0_120_RKNEN17_MASK        (0x80000U)
#define VFCCU_0_FHDLRKC0_120_RKNEN17_SHIFT       (19U)
#define VFCCU_0_FHDLRKC0_120_RKNEN17_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_120_RKNEN17(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_120_RKNEN17_SHIFT)) & VFCCU_0_FHDLRKC0_120_RKNEN17_MASK)

#define VFCCU_0_FHDLRKC0_120_RKNEN18_MASK        (0x100000U)
#define VFCCU_0_FHDLRKC0_120_RKNEN18_SHIFT       (20U)
#define VFCCU_0_FHDLRKC0_120_RKNEN18_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_120_RKNEN18(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_120_RKNEN18_SHIFT)) & VFCCU_0_FHDLRKC0_120_RKNEN18_MASK)

#define VFCCU_0_FHDLRKC0_120_RKNEN19_MASK        (0x200000U)
#define VFCCU_0_FHDLRKC0_120_RKNEN19_SHIFT       (21U)
#define VFCCU_0_FHDLRKC0_120_RKNEN19_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_120_RKNEN19(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_120_RKNEN19_SHIFT)) & VFCCU_0_FHDLRKC0_120_RKNEN19_MASK)

#define VFCCU_0_FHDLRKC0_120_RKNEN20_MASK        (0x400000U)
#define VFCCU_0_FHDLRKC0_120_RKNEN20_SHIFT       (22U)
#define VFCCU_0_FHDLRKC0_120_RKNEN20_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_120_RKNEN20(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_120_RKNEN20_SHIFT)) & VFCCU_0_FHDLRKC0_120_RKNEN20_MASK)

#define VFCCU_0_FHDLRKC0_120_RKNEN21_MASK        (0x800000U)
#define VFCCU_0_FHDLRKC0_120_RKNEN21_SHIFT       (23U)
#define VFCCU_0_FHDLRKC0_120_RKNEN21_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_120_RKNEN21(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_120_RKNEN21_SHIFT)) & VFCCU_0_FHDLRKC0_120_RKNEN21_MASK)

#define VFCCU_0_FHDLRKC0_120_RKNEN22_MASK        (0x1000000U)
#define VFCCU_0_FHDLRKC0_120_RKNEN22_SHIFT       (24U)
#define VFCCU_0_FHDLRKC0_120_RKNEN22_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_120_RKNEN22(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_120_RKNEN22_SHIFT)) & VFCCU_0_FHDLRKC0_120_RKNEN22_MASK)

#define VFCCU_0_FHDLRKC0_120_RKNEN23_MASK        (0x2000000U)
#define VFCCU_0_FHDLRKC0_120_RKNEN23_SHIFT       (25U)
#define VFCCU_0_FHDLRKC0_120_RKNEN23_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_120_RKNEN23(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_120_RKNEN23_SHIFT)) & VFCCU_0_FHDLRKC0_120_RKNEN23_MASK)

#define VFCCU_0_FHDLRKC0_120_RKNEN24_MASK        (0x4000000U)
#define VFCCU_0_FHDLRKC0_120_RKNEN24_SHIFT       (26U)
#define VFCCU_0_FHDLRKC0_120_RKNEN24_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_120_RKNEN24(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_120_RKNEN24_SHIFT)) & VFCCU_0_FHDLRKC0_120_RKNEN24_MASK)

#define VFCCU_0_FHDLRKC0_120_RKNEN25_MASK        (0x8000000U)
#define VFCCU_0_FHDLRKC0_120_RKNEN25_SHIFT       (27U)
#define VFCCU_0_FHDLRKC0_120_RKNEN25_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_120_RKNEN25(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_120_RKNEN25_SHIFT)) & VFCCU_0_FHDLRKC0_120_RKNEN25_MASK)

#define VFCCU_0_FHDLRKC0_120_RKNEN26_MASK        (0x10000000U)
#define VFCCU_0_FHDLRKC0_120_RKNEN26_SHIFT       (28U)
#define VFCCU_0_FHDLRKC0_120_RKNEN26_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_120_RKNEN26(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_120_RKNEN26_SHIFT)) & VFCCU_0_FHDLRKC0_120_RKNEN26_MASK)

#define VFCCU_0_FHDLRKC0_120_RKNEN27_MASK        (0x20000000U)
#define VFCCU_0_FHDLRKC0_120_RKNEN27_SHIFT       (29U)
#define VFCCU_0_FHDLRKC0_120_RKNEN27_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_120_RKNEN27(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_120_RKNEN27_SHIFT)) & VFCCU_0_FHDLRKC0_120_RKNEN27_MASK)

#define VFCCU_0_FHDLRKC0_120_RKNEN28_MASK        (0x40000000U)
#define VFCCU_0_FHDLRKC0_120_RKNEN28_SHIFT       (30U)
#define VFCCU_0_FHDLRKC0_120_RKNEN28_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_120_RKNEN28(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_120_RKNEN28_SHIFT)) & VFCCU_0_FHDLRKC0_120_RKNEN28_MASK)

#define VFCCU_0_FHDLRKC0_120_RKNEN29_MASK        (0x80000000U)
#define VFCCU_0_FHDLRKC0_120_RKNEN29_SHIFT       (31U)
#define VFCCU_0_FHDLRKC0_120_RKNEN29_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_120_RKNEN29(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_120_RKNEN29_SHIFT)) & VFCCU_0_FHDLRKC0_120_RKNEN29_MASK)
/*! @} */

/*! @name FHIMRKC0_130 - Immediate Reaction Configuration */
/*! @{ */

#define VFCCU_0_FHIMRKC0_130_EOUTEN0_MASK        (0x1U)
#define VFCCU_0_FHIMRKC0_130_EOUTEN0_SHIFT       (0U)
#define VFCCU_0_FHIMRKC0_130_EOUTEN0_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_130_EOUTEN0(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_130_EOUTEN0_SHIFT)) & VFCCU_0_FHIMRKC0_130_EOUTEN0_MASK)

#define VFCCU_0_FHIMRKC0_130_EOUTEN1_MASK        (0x2U)
#define VFCCU_0_FHIMRKC0_130_EOUTEN1_SHIFT       (1U)
#define VFCCU_0_FHIMRKC0_130_EOUTEN1_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_130_EOUTEN1(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_130_EOUTEN1_SHIFT)) & VFCCU_0_FHIMRKC0_130_EOUTEN1_MASK)

#define VFCCU_0_FHIMRKC0_130_RKNEN0_MASK         (0x4U)
#define VFCCU_0_FHIMRKC0_130_RKNEN0_SHIFT        (2U)
#define VFCCU_0_FHIMRKC0_130_RKNEN0_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_130_RKNEN0(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_130_RKNEN0_SHIFT)) & VFCCU_0_FHIMRKC0_130_RKNEN0_MASK)

#define VFCCU_0_FHIMRKC0_130_RKNEN1_MASK         (0x8U)
#define VFCCU_0_FHIMRKC0_130_RKNEN1_SHIFT        (3U)
#define VFCCU_0_FHIMRKC0_130_RKNEN1_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_130_RKNEN1(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_130_RKNEN1_SHIFT)) & VFCCU_0_FHIMRKC0_130_RKNEN1_MASK)

#define VFCCU_0_FHIMRKC0_130_RKNEN2_MASK         (0x10U)
#define VFCCU_0_FHIMRKC0_130_RKNEN2_SHIFT        (4U)
#define VFCCU_0_FHIMRKC0_130_RKNEN2_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_130_RKNEN2(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_130_RKNEN2_SHIFT)) & VFCCU_0_FHIMRKC0_130_RKNEN2_MASK)

#define VFCCU_0_FHIMRKC0_130_RKNEN3_MASK         (0x20U)
#define VFCCU_0_FHIMRKC0_130_RKNEN3_SHIFT        (5U)
#define VFCCU_0_FHIMRKC0_130_RKNEN3_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_130_RKNEN3(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_130_RKNEN3_SHIFT)) & VFCCU_0_FHIMRKC0_130_RKNEN3_MASK)

#define VFCCU_0_FHIMRKC0_130_RKNEN4_MASK         (0x40U)
#define VFCCU_0_FHIMRKC0_130_RKNEN4_SHIFT        (6U)
#define VFCCU_0_FHIMRKC0_130_RKNEN4_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_130_RKNEN4(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_130_RKNEN4_SHIFT)) & VFCCU_0_FHIMRKC0_130_RKNEN4_MASK)

#define VFCCU_0_FHIMRKC0_130_RKNEN5_MASK         (0x80U)
#define VFCCU_0_FHIMRKC0_130_RKNEN5_SHIFT        (7U)
#define VFCCU_0_FHIMRKC0_130_RKNEN5_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_130_RKNEN5(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_130_RKNEN5_SHIFT)) & VFCCU_0_FHIMRKC0_130_RKNEN5_MASK)

#define VFCCU_0_FHIMRKC0_130_RKNEN6_MASK         (0x100U)
#define VFCCU_0_FHIMRKC0_130_RKNEN6_SHIFT        (8U)
#define VFCCU_0_FHIMRKC0_130_RKNEN6_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_130_RKNEN6(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_130_RKNEN6_SHIFT)) & VFCCU_0_FHIMRKC0_130_RKNEN6_MASK)

#define VFCCU_0_FHIMRKC0_130_RKNEN7_MASK         (0x200U)
#define VFCCU_0_FHIMRKC0_130_RKNEN7_SHIFT        (9U)
#define VFCCU_0_FHIMRKC0_130_RKNEN7_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_130_RKNEN7(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_130_RKNEN7_SHIFT)) & VFCCU_0_FHIMRKC0_130_RKNEN7_MASK)

#define VFCCU_0_FHIMRKC0_130_RKNEN8_MASK         (0x400U)
#define VFCCU_0_FHIMRKC0_130_RKNEN8_SHIFT        (10U)
#define VFCCU_0_FHIMRKC0_130_RKNEN8_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_130_RKNEN8(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_130_RKNEN8_SHIFT)) & VFCCU_0_FHIMRKC0_130_RKNEN8_MASK)

#define VFCCU_0_FHIMRKC0_130_RKNEN9_MASK         (0x800U)
#define VFCCU_0_FHIMRKC0_130_RKNEN9_SHIFT        (11U)
#define VFCCU_0_FHIMRKC0_130_RKNEN9_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_130_RKNEN9(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_130_RKNEN9_SHIFT)) & VFCCU_0_FHIMRKC0_130_RKNEN9_MASK)

#define VFCCU_0_FHIMRKC0_130_RKNEN10_MASK        (0x1000U)
#define VFCCU_0_FHIMRKC0_130_RKNEN10_SHIFT       (12U)
#define VFCCU_0_FHIMRKC0_130_RKNEN10_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_130_RKNEN10(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_130_RKNEN10_SHIFT)) & VFCCU_0_FHIMRKC0_130_RKNEN10_MASK)

#define VFCCU_0_FHIMRKC0_130_RKNEN11_MASK        (0x2000U)
#define VFCCU_0_FHIMRKC0_130_RKNEN11_SHIFT       (13U)
#define VFCCU_0_FHIMRKC0_130_RKNEN11_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_130_RKNEN11(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_130_RKNEN11_SHIFT)) & VFCCU_0_FHIMRKC0_130_RKNEN11_MASK)

#define VFCCU_0_FHIMRKC0_130_RKNEN12_MASK        (0x4000U)
#define VFCCU_0_FHIMRKC0_130_RKNEN12_SHIFT       (14U)
#define VFCCU_0_FHIMRKC0_130_RKNEN12_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_130_RKNEN12(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_130_RKNEN12_SHIFT)) & VFCCU_0_FHIMRKC0_130_RKNEN12_MASK)

#define VFCCU_0_FHIMRKC0_130_RKNEN13_MASK        (0x8000U)
#define VFCCU_0_FHIMRKC0_130_RKNEN13_SHIFT       (15U)
#define VFCCU_0_FHIMRKC0_130_RKNEN13_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_130_RKNEN13(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_130_RKNEN13_SHIFT)) & VFCCU_0_FHIMRKC0_130_RKNEN13_MASK)

#define VFCCU_0_FHIMRKC0_130_RKNEN14_MASK        (0x10000U)
#define VFCCU_0_FHIMRKC0_130_RKNEN14_SHIFT       (16U)
#define VFCCU_0_FHIMRKC0_130_RKNEN14_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_130_RKNEN14(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_130_RKNEN14_SHIFT)) & VFCCU_0_FHIMRKC0_130_RKNEN14_MASK)

#define VFCCU_0_FHIMRKC0_130_RKNEN15_MASK        (0x20000U)
#define VFCCU_0_FHIMRKC0_130_RKNEN15_SHIFT       (17U)
#define VFCCU_0_FHIMRKC0_130_RKNEN15_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_130_RKNEN15(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_130_RKNEN15_SHIFT)) & VFCCU_0_FHIMRKC0_130_RKNEN15_MASK)

#define VFCCU_0_FHIMRKC0_130_RKNEN16_MASK        (0x40000U)
#define VFCCU_0_FHIMRKC0_130_RKNEN16_SHIFT       (18U)
#define VFCCU_0_FHIMRKC0_130_RKNEN16_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_130_RKNEN16(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_130_RKNEN16_SHIFT)) & VFCCU_0_FHIMRKC0_130_RKNEN16_MASK)

#define VFCCU_0_FHIMRKC0_130_RKNEN17_MASK        (0x80000U)
#define VFCCU_0_FHIMRKC0_130_RKNEN17_SHIFT       (19U)
#define VFCCU_0_FHIMRKC0_130_RKNEN17_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_130_RKNEN17(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_130_RKNEN17_SHIFT)) & VFCCU_0_FHIMRKC0_130_RKNEN17_MASK)

#define VFCCU_0_FHIMRKC0_130_RKNEN18_MASK        (0x100000U)
#define VFCCU_0_FHIMRKC0_130_RKNEN18_SHIFT       (20U)
#define VFCCU_0_FHIMRKC0_130_RKNEN18_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_130_RKNEN18(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_130_RKNEN18_SHIFT)) & VFCCU_0_FHIMRKC0_130_RKNEN18_MASK)

#define VFCCU_0_FHIMRKC0_130_RKNEN19_MASK        (0x200000U)
#define VFCCU_0_FHIMRKC0_130_RKNEN19_SHIFT       (21U)
#define VFCCU_0_FHIMRKC0_130_RKNEN19_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_130_RKNEN19(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_130_RKNEN19_SHIFT)) & VFCCU_0_FHIMRKC0_130_RKNEN19_MASK)

#define VFCCU_0_FHIMRKC0_130_RKNEN20_MASK        (0x400000U)
#define VFCCU_0_FHIMRKC0_130_RKNEN20_SHIFT       (22U)
#define VFCCU_0_FHIMRKC0_130_RKNEN20_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_130_RKNEN20(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_130_RKNEN20_SHIFT)) & VFCCU_0_FHIMRKC0_130_RKNEN20_MASK)

#define VFCCU_0_FHIMRKC0_130_RKNEN21_MASK        (0x800000U)
#define VFCCU_0_FHIMRKC0_130_RKNEN21_SHIFT       (23U)
#define VFCCU_0_FHIMRKC0_130_RKNEN21_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_130_RKNEN21(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_130_RKNEN21_SHIFT)) & VFCCU_0_FHIMRKC0_130_RKNEN21_MASK)

#define VFCCU_0_FHIMRKC0_130_RKNEN22_MASK        (0x1000000U)
#define VFCCU_0_FHIMRKC0_130_RKNEN22_SHIFT       (24U)
#define VFCCU_0_FHIMRKC0_130_RKNEN22_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_130_RKNEN22(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_130_RKNEN22_SHIFT)) & VFCCU_0_FHIMRKC0_130_RKNEN22_MASK)

#define VFCCU_0_FHIMRKC0_130_RKNEN23_MASK        (0x2000000U)
#define VFCCU_0_FHIMRKC0_130_RKNEN23_SHIFT       (25U)
#define VFCCU_0_FHIMRKC0_130_RKNEN23_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_130_RKNEN23(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_130_RKNEN23_SHIFT)) & VFCCU_0_FHIMRKC0_130_RKNEN23_MASK)

#define VFCCU_0_FHIMRKC0_130_RKNEN24_MASK        (0x4000000U)
#define VFCCU_0_FHIMRKC0_130_RKNEN24_SHIFT       (26U)
#define VFCCU_0_FHIMRKC0_130_RKNEN24_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_130_RKNEN24(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_130_RKNEN24_SHIFT)) & VFCCU_0_FHIMRKC0_130_RKNEN24_MASK)

#define VFCCU_0_FHIMRKC0_130_RKNEN25_MASK        (0x8000000U)
#define VFCCU_0_FHIMRKC0_130_RKNEN25_SHIFT       (27U)
#define VFCCU_0_FHIMRKC0_130_RKNEN25_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_130_RKNEN25(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_130_RKNEN25_SHIFT)) & VFCCU_0_FHIMRKC0_130_RKNEN25_MASK)

#define VFCCU_0_FHIMRKC0_130_RKNEN26_MASK        (0x10000000U)
#define VFCCU_0_FHIMRKC0_130_RKNEN26_SHIFT       (28U)
#define VFCCU_0_FHIMRKC0_130_RKNEN26_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_130_RKNEN26(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_130_RKNEN26_SHIFT)) & VFCCU_0_FHIMRKC0_130_RKNEN26_MASK)

#define VFCCU_0_FHIMRKC0_130_RKNEN27_MASK        (0x20000000U)
#define VFCCU_0_FHIMRKC0_130_RKNEN27_SHIFT       (29U)
#define VFCCU_0_FHIMRKC0_130_RKNEN27_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_130_RKNEN27(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_130_RKNEN27_SHIFT)) & VFCCU_0_FHIMRKC0_130_RKNEN27_MASK)

#define VFCCU_0_FHIMRKC0_130_RKNEN28_MASK        (0x40000000U)
#define VFCCU_0_FHIMRKC0_130_RKNEN28_SHIFT       (30U)
#define VFCCU_0_FHIMRKC0_130_RKNEN28_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_130_RKNEN28(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_130_RKNEN28_SHIFT)) & VFCCU_0_FHIMRKC0_130_RKNEN28_MASK)

#define VFCCU_0_FHIMRKC0_130_RKNEN29_MASK        (0x80000000U)
#define VFCCU_0_FHIMRKC0_130_RKNEN29_SHIFT       (31U)
#define VFCCU_0_FHIMRKC0_130_RKNEN29_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_130_RKNEN29(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_130_RKNEN29_SHIFT)) & VFCCU_0_FHIMRKC0_130_RKNEN29_MASK)
/*! @} */

/*! @name FHDLRKC0_130 - Delayed Reaction Configuration */
/*! @{ */

#define VFCCU_0_FHDLRKC0_130_EOUTEN0_MASK        (0x1U)
#define VFCCU_0_FHDLRKC0_130_EOUTEN0_SHIFT       (0U)
#define VFCCU_0_FHDLRKC0_130_EOUTEN0_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_130_EOUTEN0(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_130_EOUTEN0_SHIFT)) & VFCCU_0_FHDLRKC0_130_EOUTEN0_MASK)

#define VFCCU_0_FHDLRKC0_130_EOUTEN1_MASK        (0x2U)
#define VFCCU_0_FHDLRKC0_130_EOUTEN1_SHIFT       (1U)
#define VFCCU_0_FHDLRKC0_130_EOUTEN1_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_130_EOUTEN1(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_130_EOUTEN1_SHIFT)) & VFCCU_0_FHDLRKC0_130_EOUTEN1_MASK)

#define VFCCU_0_FHDLRKC0_130_RKNEN0_MASK         (0x4U)
#define VFCCU_0_FHDLRKC0_130_RKNEN0_SHIFT        (2U)
#define VFCCU_0_FHDLRKC0_130_RKNEN0_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_130_RKNEN0(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_130_RKNEN0_SHIFT)) & VFCCU_0_FHDLRKC0_130_RKNEN0_MASK)

#define VFCCU_0_FHDLRKC0_130_RKNEN1_MASK         (0x8U)
#define VFCCU_0_FHDLRKC0_130_RKNEN1_SHIFT        (3U)
#define VFCCU_0_FHDLRKC0_130_RKNEN1_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_130_RKNEN1(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_130_RKNEN1_SHIFT)) & VFCCU_0_FHDLRKC0_130_RKNEN1_MASK)

#define VFCCU_0_FHDLRKC0_130_RKNEN2_MASK         (0x10U)
#define VFCCU_0_FHDLRKC0_130_RKNEN2_SHIFT        (4U)
#define VFCCU_0_FHDLRKC0_130_RKNEN2_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_130_RKNEN2(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_130_RKNEN2_SHIFT)) & VFCCU_0_FHDLRKC0_130_RKNEN2_MASK)

#define VFCCU_0_FHDLRKC0_130_RKNEN3_MASK         (0x20U)
#define VFCCU_0_FHDLRKC0_130_RKNEN3_SHIFT        (5U)
#define VFCCU_0_FHDLRKC0_130_RKNEN3_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_130_RKNEN3(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_130_RKNEN3_SHIFT)) & VFCCU_0_FHDLRKC0_130_RKNEN3_MASK)

#define VFCCU_0_FHDLRKC0_130_RKNEN4_MASK         (0x40U)
#define VFCCU_0_FHDLRKC0_130_RKNEN4_SHIFT        (6U)
#define VFCCU_0_FHDLRKC0_130_RKNEN4_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_130_RKNEN4(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_130_RKNEN4_SHIFT)) & VFCCU_0_FHDLRKC0_130_RKNEN4_MASK)

#define VFCCU_0_FHDLRKC0_130_RKNEN5_MASK         (0x80U)
#define VFCCU_0_FHDLRKC0_130_RKNEN5_SHIFT        (7U)
#define VFCCU_0_FHDLRKC0_130_RKNEN5_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_130_RKNEN5(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_130_RKNEN5_SHIFT)) & VFCCU_0_FHDLRKC0_130_RKNEN5_MASK)

#define VFCCU_0_FHDLRKC0_130_RKNEN6_MASK         (0x100U)
#define VFCCU_0_FHDLRKC0_130_RKNEN6_SHIFT        (8U)
#define VFCCU_0_FHDLRKC0_130_RKNEN6_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_130_RKNEN6(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_130_RKNEN6_SHIFT)) & VFCCU_0_FHDLRKC0_130_RKNEN6_MASK)

#define VFCCU_0_FHDLRKC0_130_RKNEN7_MASK         (0x200U)
#define VFCCU_0_FHDLRKC0_130_RKNEN7_SHIFT        (9U)
#define VFCCU_0_FHDLRKC0_130_RKNEN7_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_130_RKNEN7(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_130_RKNEN7_SHIFT)) & VFCCU_0_FHDLRKC0_130_RKNEN7_MASK)

#define VFCCU_0_FHDLRKC0_130_RKNEN8_MASK         (0x400U)
#define VFCCU_0_FHDLRKC0_130_RKNEN8_SHIFT        (10U)
#define VFCCU_0_FHDLRKC0_130_RKNEN8_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_130_RKNEN8(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_130_RKNEN8_SHIFT)) & VFCCU_0_FHDLRKC0_130_RKNEN8_MASK)

#define VFCCU_0_FHDLRKC0_130_RKNEN9_MASK         (0x800U)
#define VFCCU_0_FHDLRKC0_130_RKNEN9_SHIFT        (11U)
#define VFCCU_0_FHDLRKC0_130_RKNEN9_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_130_RKNEN9(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_130_RKNEN9_SHIFT)) & VFCCU_0_FHDLRKC0_130_RKNEN9_MASK)

#define VFCCU_0_FHDLRKC0_130_RKNEN10_MASK        (0x1000U)
#define VFCCU_0_FHDLRKC0_130_RKNEN10_SHIFT       (12U)
#define VFCCU_0_FHDLRKC0_130_RKNEN10_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_130_RKNEN10(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_130_RKNEN10_SHIFT)) & VFCCU_0_FHDLRKC0_130_RKNEN10_MASK)

#define VFCCU_0_FHDLRKC0_130_RKNEN11_MASK        (0x2000U)
#define VFCCU_0_FHDLRKC0_130_RKNEN11_SHIFT       (13U)
#define VFCCU_0_FHDLRKC0_130_RKNEN11_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_130_RKNEN11(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_130_RKNEN11_SHIFT)) & VFCCU_0_FHDLRKC0_130_RKNEN11_MASK)

#define VFCCU_0_FHDLRKC0_130_RKNEN12_MASK        (0x4000U)
#define VFCCU_0_FHDLRKC0_130_RKNEN12_SHIFT       (14U)
#define VFCCU_0_FHDLRKC0_130_RKNEN12_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_130_RKNEN12(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_130_RKNEN12_SHIFT)) & VFCCU_0_FHDLRKC0_130_RKNEN12_MASK)

#define VFCCU_0_FHDLRKC0_130_RKNEN13_MASK        (0x8000U)
#define VFCCU_0_FHDLRKC0_130_RKNEN13_SHIFT       (15U)
#define VFCCU_0_FHDLRKC0_130_RKNEN13_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_130_RKNEN13(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_130_RKNEN13_SHIFT)) & VFCCU_0_FHDLRKC0_130_RKNEN13_MASK)

#define VFCCU_0_FHDLRKC0_130_RKNEN14_MASK        (0x10000U)
#define VFCCU_0_FHDLRKC0_130_RKNEN14_SHIFT       (16U)
#define VFCCU_0_FHDLRKC0_130_RKNEN14_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_130_RKNEN14(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_130_RKNEN14_SHIFT)) & VFCCU_0_FHDLRKC0_130_RKNEN14_MASK)

#define VFCCU_0_FHDLRKC0_130_RKNEN15_MASK        (0x20000U)
#define VFCCU_0_FHDLRKC0_130_RKNEN15_SHIFT       (17U)
#define VFCCU_0_FHDLRKC0_130_RKNEN15_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_130_RKNEN15(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_130_RKNEN15_SHIFT)) & VFCCU_0_FHDLRKC0_130_RKNEN15_MASK)

#define VFCCU_0_FHDLRKC0_130_RKNEN16_MASK        (0x40000U)
#define VFCCU_0_FHDLRKC0_130_RKNEN16_SHIFT       (18U)
#define VFCCU_0_FHDLRKC0_130_RKNEN16_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_130_RKNEN16(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_130_RKNEN16_SHIFT)) & VFCCU_0_FHDLRKC0_130_RKNEN16_MASK)

#define VFCCU_0_FHDLRKC0_130_RKNEN17_MASK        (0x80000U)
#define VFCCU_0_FHDLRKC0_130_RKNEN17_SHIFT       (19U)
#define VFCCU_0_FHDLRKC0_130_RKNEN17_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_130_RKNEN17(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_130_RKNEN17_SHIFT)) & VFCCU_0_FHDLRKC0_130_RKNEN17_MASK)

#define VFCCU_0_FHDLRKC0_130_RKNEN18_MASK        (0x100000U)
#define VFCCU_0_FHDLRKC0_130_RKNEN18_SHIFT       (20U)
#define VFCCU_0_FHDLRKC0_130_RKNEN18_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_130_RKNEN18(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_130_RKNEN18_SHIFT)) & VFCCU_0_FHDLRKC0_130_RKNEN18_MASK)

#define VFCCU_0_FHDLRKC0_130_RKNEN19_MASK        (0x200000U)
#define VFCCU_0_FHDLRKC0_130_RKNEN19_SHIFT       (21U)
#define VFCCU_0_FHDLRKC0_130_RKNEN19_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_130_RKNEN19(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_130_RKNEN19_SHIFT)) & VFCCU_0_FHDLRKC0_130_RKNEN19_MASK)

#define VFCCU_0_FHDLRKC0_130_RKNEN20_MASK        (0x400000U)
#define VFCCU_0_FHDLRKC0_130_RKNEN20_SHIFT       (22U)
#define VFCCU_0_FHDLRKC0_130_RKNEN20_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_130_RKNEN20(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_130_RKNEN20_SHIFT)) & VFCCU_0_FHDLRKC0_130_RKNEN20_MASK)

#define VFCCU_0_FHDLRKC0_130_RKNEN21_MASK        (0x800000U)
#define VFCCU_0_FHDLRKC0_130_RKNEN21_SHIFT       (23U)
#define VFCCU_0_FHDLRKC0_130_RKNEN21_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_130_RKNEN21(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_130_RKNEN21_SHIFT)) & VFCCU_0_FHDLRKC0_130_RKNEN21_MASK)

#define VFCCU_0_FHDLRKC0_130_RKNEN22_MASK        (0x1000000U)
#define VFCCU_0_FHDLRKC0_130_RKNEN22_SHIFT       (24U)
#define VFCCU_0_FHDLRKC0_130_RKNEN22_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_130_RKNEN22(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_130_RKNEN22_SHIFT)) & VFCCU_0_FHDLRKC0_130_RKNEN22_MASK)

#define VFCCU_0_FHDLRKC0_130_RKNEN23_MASK        (0x2000000U)
#define VFCCU_0_FHDLRKC0_130_RKNEN23_SHIFT       (25U)
#define VFCCU_0_FHDLRKC0_130_RKNEN23_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_130_RKNEN23(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_130_RKNEN23_SHIFT)) & VFCCU_0_FHDLRKC0_130_RKNEN23_MASK)

#define VFCCU_0_FHDLRKC0_130_RKNEN24_MASK        (0x4000000U)
#define VFCCU_0_FHDLRKC0_130_RKNEN24_SHIFT       (26U)
#define VFCCU_0_FHDLRKC0_130_RKNEN24_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_130_RKNEN24(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_130_RKNEN24_SHIFT)) & VFCCU_0_FHDLRKC0_130_RKNEN24_MASK)

#define VFCCU_0_FHDLRKC0_130_RKNEN25_MASK        (0x8000000U)
#define VFCCU_0_FHDLRKC0_130_RKNEN25_SHIFT       (27U)
#define VFCCU_0_FHDLRKC0_130_RKNEN25_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_130_RKNEN25(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_130_RKNEN25_SHIFT)) & VFCCU_0_FHDLRKC0_130_RKNEN25_MASK)

#define VFCCU_0_FHDLRKC0_130_RKNEN26_MASK        (0x10000000U)
#define VFCCU_0_FHDLRKC0_130_RKNEN26_SHIFT       (28U)
#define VFCCU_0_FHDLRKC0_130_RKNEN26_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_130_RKNEN26(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_130_RKNEN26_SHIFT)) & VFCCU_0_FHDLRKC0_130_RKNEN26_MASK)

#define VFCCU_0_FHDLRKC0_130_RKNEN27_MASK        (0x20000000U)
#define VFCCU_0_FHDLRKC0_130_RKNEN27_SHIFT       (29U)
#define VFCCU_0_FHDLRKC0_130_RKNEN27_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_130_RKNEN27(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_130_RKNEN27_SHIFT)) & VFCCU_0_FHDLRKC0_130_RKNEN27_MASK)

#define VFCCU_0_FHDLRKC0_130_RKNEN28_MASK        (0x40000000U)
#define VFCCU_0_FHDLRKC0_130_RKNEN28_SHIFT       (30U)
#define VFCCU_0_FHDLRKC0_130_RKNEN28_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_130_RKNEN28(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_130_RKNEN28_SHIFT)) & VFCCU_0_FHDLRKC0_130_RKNEN28_MASK)

#define VFCCU_0_FHDLRKC0_130_RKNEN29_MASK        (0x80000000U)
#define VFCCU_0_FHDLRKC0_130_RKNEN29_SHIFT       (31U)
#define VFCCU_0_FHDLRKC0_130_RKNEN29_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_130_RKNEN29(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_130_RKNEN29_SHIFT)) & VFCCU_0_FHDLRKC0_130_RKNEN29_MASK)
/*! @} */

/*! @name FHIMRKC0_140 - Immediate Reaction Configuration */
/*! @{ */

#define VFCCU_0_FHIMRKC0_140_EOUTEN0_MASK        (0x1U)
#define VFCCU_0_FHIMRKC0_140_EOUTEN0_SHIFT       (0U)
#define VFCCU_0_FHIMRKC0_140_EOUTEN0_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_140_EOUTEN0(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_140_EOUTEN0_SHIFT)) & VFCCU_0_FHIMRKC0_140_EOUTEN0_MASK)

#define VFCCU_0_FHIMRKC0_140_EOUTEN1_MASK        (0x2U)
#define VFCCU_0_FHIMRKC0_140_EOUTEN1_SHIFT       (1U)
#define VFCCU_0_FHIMRKC0_140_EOUTEN1_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_140_EOUTEN1(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_140_EOUTEN1_SHIFT)) & VFCCU_0_FHIMRKC0_140_EOUTEN1_MASK)

#define VFCCU_0_FHIMRKC0_140_RKNEN0_MASK         (0x4U)
#define VFCCU_0_FHIMRKC0_140_RKNEN0_SHIFT        (2U)
#define VFCCU_0_FHIMRKC0_140_RKNEN0_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_140_RKNEN0(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_140_RKNEN0_SHIFT)) & VFCCU_0_FHIMRKC0_140_RKNEN0_MASK)

#define VFCCU_0_FHIMRKC0_140_RKNEN1_MASK         (0x8U)
#define VFCCU_0_FHIMRKC0_140_RKNEN1_SHIFT        (3U)
#define VFCCU_0_FHIMRKC0_140_RKNEN1_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_140_RKNEN1(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_140_RKNEN1_SHIFT)) & VFCCU_0_FHIMRKC0_140_RKNEN1_MASK)

#define VFCCU_0_FHIMRKC0_140_RKNEN2_MASK         (0x10U)
#define VFCCU_0_FHIMRKC0_140_RKNEN2_SHIFT        (4U)
#define VFCCU_0_FHIMRKC0_140_RKNEN2_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_140_RKNEN2(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_140_RKNEN2_SHIFT)) & VFCCU_0_FHIMRKC0_140_RKNEN2_MASK)

#define VFCCU_0_FHIMRKC0_140_RKNEN3_MASK         (0x20U)
#define VFCCU_0_FHIMRKC0_140_RKNEN3_SHIFT        (5U)
#define VFCCU_0_FHIMRKC0_140_RKNEN3_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_140_RKNEN3(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_140_RKNEN3_SHIFT)) & VFCCU_0_FHIMRKC0_140_RKNEN3_MASK)

#define VFCCU_0_FHIMRKC0_140_RKNEN4_MASK         (0x40U)
#define VFCCU_0_FHIMRKC0_140_RKNEN4_SHIFT        (6U)
#define VFCCU_0_FHIMRKC0_140_RKNEN4_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_140_RKNEN4(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_140_RKNEN4_SHIFT)) & VFCCU_0_FHIMRKC0_140_RKNEN4_MASK)

#define VFCCU_0_FHIMRKC0_140_RKNEN5_MASK         (0x80U)
#define VFCCU_0_FHIMRKC0_140_RKNEN5_SHIFT        (7U)
#define VFCCU_0_FHIMRKC0_140_RKNEN5_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_140_RKNEN5(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_140_RKNEN5_SHIFT)) & VFCCU_0_FHIMRKC0_140_RKNEN5_MASK)

#define VFCCU_0_FHIMRKC0_140_RKNEN6_MASK         (0x100U)
#define VFCCU_0_FHIMRKC0_140_RKNEN6_SHIFT        (8U)
#define VFCCU_0_FHIMRKC0_140_RKNEN6_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_140_RKNEN6(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_140_RKNEN6_SHIFT)) & VFCCU_0_FHIMRKC0_140_RKNEN6_MASK)

#define VFCCU_0_FHIMRKC0_140_RKNEN7_MASK         (0x200U)
#define VFCCU_0_FHIMRKC0_140_RKNEN7_SHIFT        (9U)
#define VFCCU_0_FHIMRKC0_140_RKNEN7_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_140_RKNEN7(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_140_RKNEN7_SHIFT)) & VFCCU_0_FHIMRKC0_140_RKNEN7_MASK)

#define VFCCU_0_FHIMRKC0_140_RKNEN8_MASK         (0x400U)
#define VFCCU_0_FHIMRKC0_140_RKNEN8_SHIFT        (10U)
#define VFCCU_0_FHIMRKC0_140_RKNEN8_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_140_RKNEN8(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_140_RKNEN8_SHIFT)) & VFCCU_0_FHIMRKC0_140_RKNEN8_MASK)

#define VFCCU_0_FHIMRKC0_140_RKNEN9_MASK         (0x800U)
#define VFCCU_0_FHIMRKC0_140_RKNEN9_SHIFT        (11U)
#define VFCCU_0_FHIMRKC0_140_RKNEN9_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_140_RKNEN9(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_140_RKNEN9_SHIFT)) & VFCCU_0_FHIMRKC0_140_RKNEN9_MASK)

#define VFCCU_0_FHIMRKC0_140_RKNEN10_MASK        (0x1000U)
#define VFCCU_0_FHIMRKC0_140_RKNEN10_SHIFT       (12U)
#define VFCCU_0_FHIMRKC0_140_RKNEN10_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_140_RKNEN10(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_140_RKNEN10_SHIFT)) & VFCCU_0_FHIMRKC0_140_RKNEN10_MASK)

#define VFCCU_0_FHIMRKC0_140_RKNEN11_MASK        (0x2000U)
#define VFCCU_0_FHIMRKC0_140_RKNEN11_SHIFT       (13U)
#define VFCCU_0_FHIMRKC0_140_RKNEN11_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_140_RKNEN11(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_140_RKNEN11_SHIFT)) & VFCCU_0_FHIMRKC0_140_RKNEN11_MASK)

#define VFCCU_0_FHIMRKC0_140_RKNEN12_MASK        (0x4000U)
#define VFCCU_0_FHIMRKC0_140_RKNEN12_SHIFT       (14U)
#define VFCCU_0_FHIMRKC0_140_RKNEN12_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_140_RKNEN12(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_140_RKNEN12_SHIFT)) & VFCCU_0_FHIMRKC0_140_RKNEN12_MASK)

#define VFCCU_0_FHIMRKC0_140_RKNEN13_MASK        (0x8000U)
#define VFCCU_0_FHIMRKC0_140_RKNEN13_SHIFT       (15U)
#define VFCCU_0_FHIMRKC0_140_RKNEN13_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_140_RKNEN13(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_140_RKNEN13_SHIFT)) & VFCCU_0_FHIMRKC0_140_RKNEN13_MASK)

#define VFCCU_0_FHIMRKC0_140_RKNEN14_MASK        (0x10000U)
#define VFCCU_0_FHIMRKC0_140_RKNEN14_SHIFT       (16U)
#define VFCCU_0_FHIMRKC0_140_RKNEN14_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_140_RKNEN14(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_140_RKNEN14_SHIFT)) & VFCCU_0_FHIMRKC0_140_RKNEN14_MASK)

#define VFCCU_0_FHIMRKC0_140_RKNEN15_MASK        (0x20000U)
#define VFCCU_0_FHIMRKC0_140_RKNEN15_SHIFT       (17U)
#define VFCCU_0_FHIMRKC0_140_RKNEN15_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_140_RKNEN15(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_140_RKNEN15_SHIFT)) & VFCCU_0_FHIMRKC0_140_RKNEN15_MASK)

#define VFCCU_0_FHIMRKC0_140_RKNEN16_MASK        (0x40000U)
#define VFCCU_0_FHIMRKC0_140_RKNEN16_SHIFT       (18U)
#define VFCCU_0_FHIMRKC0_140_RKNEN16_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_140_RKNEN16(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_140_RKNEN16_SHIFT)) & VFCCU_0_FHIMRKC0_140_RKNEN16_MASK)

#define VFCCU_0_FHIMRKC0_140_RKNEN17_MASK        (0x80000U)
#define VFCCU_0_FHIMRKC0_140_RKNEN17_SHIFT       (19U)
#define VFCCU_0_FHIMRKC0_140_RKNEN17_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_140_RKNEN17(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_140_RKNEN17_SHIFT)) & VFCCU_0_FHIMRKC0_140_RKNEN17_MASK)

#define VFCCU_0_FHIMRKC0_140_RKNEN18_MASK        (0x100000U)
#define VFCCU_0_FHIMRKC0_140_RKNEN18_SHIFT       (20U)
#define VFCCU_0_FHIMRKC0_140_RKNEN18_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_140_RKNEN18(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_140_RKNEN18_SHIFT)) & VFCCU_0_FHIMRKC0_140_RKNEN18_MASK)

#define VFCCU_0_FHIMRKC0_140_RKNEN19_MASK        (0x200000U)
#define VFCCU_0_FHIMRKC0_140_RKNEN19_SHIFT       (21U)
#define VFCCU_0_FHIMRKC0_140_RKNEN19_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_140_RKNEN19(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_140_RKNEN19_SHIFT)) & VFCCU_0_FHIMRKC0_140_RKNEN19_MASK)

#define VFCCU_0_FHIMRKC0_140_RKNEN20_MASK        (0x400000U)
#define VFCCU_0_FHIMRKC0_140_RKNEN20_SHIFT       (22U)
#define VFCCU_0_FHIMRKC0_140_RKNEN20_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_140_RKNEN20(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_140_RKNEN20_SHIFT)) & VFCCU_0_FHIMRKC0_140_RKNEN20_MASK)

#define VFCCU_0_FHIMRKC0_140_RKNEN21_MASK        (0x800000U)
#define VFCCU_0_FHIMRKC0_140_RKNEN21_SHIFT       (23U)
#define VFCCU_0_FHIMRKC0_140_RKNEN21_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_140_RKNEN21(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_140_RKNEN21_SHIFT)) & VFCCU_0_FHIMRKC0_140_RKNEN21_MASK)

#define VFCCU_0_FHIMRKC0_140_RKNEN22_MASK        (0x1000000U)
#define VFCCU_0_FHIMRKC0_140_RKNEN22_SHIFT       (24U)
#define VFCCU_0_FHIMRKC0_140_RKNEN22_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_140_RKNEN22(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_140_RKNEN22_SHIFT)) & VFCCU_0_FHIMRKC0_140_RKNEN22_MASK)

#define VFCCU_0_FHIMRKC0_140_RKNEN23_MASK        (0x2000000U)
#define VFCCU_0_FHIMRKC0_140_RKNEN23_SHIFT       (25U)
#define VFCCU_0_FHIMRKC0_140_RKNEN23_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_140_RKNEN23(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_140_RKNEN23_SHIFT)) & VFCCU_0_FHIMRKC0_140_RKNEN23_MASK)

#define VFCCU_0_FHIMRKC0_140_RKNEN24_MASK        (0x4000000U)
#define VFCCU_0_FHIMRKC0_140_RKNEN24_SHIFT       (26U)
#define VFCCU_0_FHIMRKC0_140_RKNEN24_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_140_RKNEN24(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_140_RKNEN24_SHIFT)) & VFCCU_0_FHIMRKC0_140_RKNEN24_MASK)

#define VFCCU_0_FHIMRKC0_140_RKNEN25_MASK        (0x8000000U)
#define VFCCU_0_FHIMRKC0_140_RKNEN25_SHIFT       (27U)
#define VFCCU_0_FHIMRKC0_140_RKNEN25_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_140_RKNEN25(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_140_RKNEN25_SHIFT)) & VFCCU_0_FHIMRKC0_140_RKNEN25_MASK)

#define VFCCU_0_FHIMRKC0_140_RKNEN26_MASK        (0x10000000U)
#define VFCCU_0_FHIMRKC0_140_RKNEN26_SHIFT       (28U)
#define VFCCU_0_FHIMRKC0_140_RKNEN26_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_140_RKNEN26(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_140_RKNEN26_SHIFT)) & VFCCU_0_FHIMRKC0_140_RKNEN26_MASK)

#define VFCCU_0_FHIMRKC0_140_RKNEN27_MASK        (0x20000000U)
#define VFCCU_0_FHIMRKC0_140_RKNEN27_SHIFT       (29U)
#define VFCCU_0_FHIMRKC0_140_RKNEN27_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_140_RKNEN27(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_140_RKNEN27_SHIFT)) & VFCCU_0_FHIMRKC0_140_RKNEN27_MASK)

#define VFCCU_0_FHIMRKC0_140_RKNEN28_MASK        (0x40000000U)
#define VFCCU_0_FHIMRKC0_140_RKNEN28_SHIFT       (30U)
#define VFCCU_0_FHIMRKC0_140_RKNEN28_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_140_RKNEN28(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_140_RKNEN28_SHIFT)) & VFCCU_0_FHIMRKC0_140_RKNEN28_MASK)

#define VFCCU_0_FHIMRKC0_140_RKNEN29_MASK        (0x80000000U)
#define VFCCU_0_FHIMRKC0_140_RKNEN29_SHIFT       (31U)
#define VFCCU_0_FHIMRKC0_140_RKNEN29_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_140_RKNEN29(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_140_RKNEN29_SHIFT)) & VFCCU_0_FHIMRKC0_140_RKNEN29_MASK)
/*! @} */

/*! @name FHDLRKC0_140 - Delayed Reaction Configuration */
/*! @{ */

#define VFCCU_0_FHDLRKC0_140_EOUTEN0_MASK        (0x1U)
#define VFCCU_0_FHDLRKC0_140_EOUTEN0_SHIFT       (0U)
#define VFCCU_0_FHDLRKC0_140_EOUTEN0_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_140_EOUTEN0(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_140_EOUTEN0_SHIFT)) & VFCCU_0_FHDLRKC0_140_EOUTEN0_MASK)

#define VFCCU_0_FHDLRKC0_140_EOUTEN1_MASK        (0x2U)
#define VFCCU_0_FHDLRKC0_140_EOUTEN1_SHIFT       (1U)
#define VFCCU_0_FHDLRKC0_140_EOUTEN1_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_140_EOUTEN1(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_140_EOUTEN1_SHIFT)) & VFCCU_0_FHDLRKC0_140_EOUTEN1_MASK)

#define VFCCU_0_FHDLRKC0_140_RKNEN0_MASK         (0x4U)
#define VFCCU_0_FHDLRKC0_140_RKNEN0_SHIFT        (2U)
#define VFCCU_0_FHDLRKC0_140_RKNEN0_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_140_RKNEN0(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_140_RKNEN0_SHIFT)) & VFCCU_0_FHDLRKC0_140_RKNEN0_MASK)

#define VFCCU_0_FHDLRKC0_140_RKNEN1_MASK         (0x8U)
#define VFCCU_0_FHDLRKC0_140_RKNEN1_SHIFT        (3U)
#define VFCCU_0_FHDLRKC0_140_RKNEN1_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_140_RKNEN1(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_140_RKNEN1_SHIFT)) & VFCCU_0_FHDLRKC0_140_RKNEN1_MASK)

#define VFCCU_0_FHDLRKC0_140_RKNEN2_MASK         (0x10U)
#define VFCCU_0_FHDLRKC0_140_RKNEN2_SHIFT        (4U)
#define VFCCU_0_FHDLRKC0_140_RKNEN2_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_140_RKNEN2(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_140_RKNEN2_SHIFT)) & VFCCU_0_FHDLRKC0_140_RKNEN2_MASK)

#define VFCCU_0_FHDLRKC0_140_RKNEN3_MASK         (0x20U)
#define VFCCU_0_FHDLRKC0_140_RKNEN3_SHIFT        (5U)
#define VFCCU_0_FHDLRKC0_140_RKNEN3_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_140_RKNEN3(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_140_RKNEN3_SHIFT)) & VFCCU_0_FHDLRKC0_140_RKNEN3_MASK)

#define VFCCU_0_FHDLRKC0_140_RKNEN4_MASK         (0x40U)
#define VFCCU_0_FHDLRKC0_140_RKNEN4_SHIFT        (6U)
#define VFCCU_0_FHDLRKC0_140_RKNEN4_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_140_RKNEN4(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_140_RKNEN4_SHIFT)) & VFCCU_0_FHDLRKC0_140_RKNEN4_MASK)

#define VFCCU_0_FHDLRKC0_140_RKNEN5_MASK         (0x80U)
#define VFCCU_0_FHDLRKC0_140_RKNEN5_SHIFT        (7U)
#define VFCCU_0_FHDLRKC0_140_RKNEN5_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_140_RKNEN5(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_140_RKNEN5_SHIFT)) & VFCCU_0_FHDLRKC0_140_RKNEN5_MASK)

#define VFCCU_0_FHDLRKC0_140_RKNEN6_MASK         (0x100U)
#define VFCCU_0_FHDLRKC0_140_RKNEN6_SHIFT        (8U)
#define VFCCU_0_FHDLRKC0_140_RKNEN6_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_140_RKNEN6(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_140_RKNEN6_SHIFT)) & VFCCU_0_FHDLRKC0_140_RKNEN6_MASK)

#define VFCCU_0_FHDLRKC0_140_RKNEN7_MASK         (0x200U)
#define VFCCU_0_FHDLRKC0_140_RKNEN7_SHIFT        (9U)
#define VFCCU_0_FHDLRKC0_140_RKNEN7_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_140_RKNEN7(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_140_RKNEN7_SHIFT)) & VFCCU_0_FHDLRKC0_140_RKNEN7_MASK)

#define VFCCU_0_FHDLRKC0_140_RKNEN8_MASK         (0x400U)
#define VFCCU_0_FHDLRKC0_140_RKNEN8_SHIFT        (10U)
#define VFCCU_0_FHDLRKC0_140_RKNEN8_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_140_RKNEN8(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_140_RKNEN8_SHIFT)) & VFCCU_0_FHDLRKC0_140_RKNEN8_MASK)

#define VFCCU_0_FHDLRKC0_140_RKNEN9_MASK         (0x800U)
#define VFCCU_0_FHDLRKC0_140_RKNEN9_SHIFT        (11U)
#define VFCCU_0_FHDLRKC0_140_RKNEN9_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_140_RKNEN9(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_140_RKNEN9_SHIFT)) & VFCCU_0_FHDLRKC0_140_RKNEN9_MASK)

#define VFCCU_0_FHDLRKC0_140_RKNEN10_MASK        (0x1000U)
#define VFCCU_0_FHDLRKC0_140_RKNEN10_SHIFT       (12U)
#define VFCCU_0_FHDLRKC0_140_RKNEN10_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_140_RKNEN10(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_140_RKNEN10_SHIFT)) & VFCCU_0_FHDLRKC0_140_RKNEN10_MASK)

#define VFCCU_0_FHDLRKC0_140_RKNEN11_MASK        (0x2000U)
#define VFCCU_0_FHDLRKC0_140_RKNEN11_SHIFT       (13U)
#define VFCCU_0_FHDLRKC0_140_RKNEN11_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_140_RKNEN11(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_140_RKNEN11_SHIFT)) & VFCCU_0_FHDLRKC0_140_RKNEN11_MASK)

#define VFCCU_0_FHDLRKC0_140_RKNEN12_MASK        (0x4000U)
#define VFCCU_0_FHDLRKC0_140_RKNEN12_SHIFT       (14U)
#define VFCCU_0_FHDLRKC0_140_RKNEN12_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_140_RKNEN12(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_140_RKNEN12_SHIFT)) & VFCCU_0_FHDLRKC0_140_RKNEN12_MASK)

#define VFCCU_0_FHDLRKC0_140_RKNEN13_MASK        (0x8000U)
#define VFCCU_0_FHDLRKC0_140_RKNEN13_SHIFT       (15U)
#define VFCCU_0_FHDLRKC0_140_RKNEN13_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_140_RKNEN13(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_140_RKNEN13_SHIFT)) & VFCCU_0_FHDLRKC0_140_RKNEN13_MASK)

#define VFCCU_0_FHDLRKC0_140_RKNEN14_MASK        (0x10000U)
#define VFCCU_0_FHDLRKC0_140_RKNEN14_SHIFT       (16U)
#define VFCCU_0_FHDLRKC0_140_RKNEN14_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_140_RKNEN14(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_140_RKNEN14_SHIFT)) & VFCCU_0_FHDLRKC0_140_RKNEN14_MASK)

#define VFCCU_0_FHDLRKC0_140_RKNEN15_MASK        (0x20000U)
#define VFCCU_0_FHDLRKC0_140_RKNEN15_SHIFT       (17U)
#define VFCCU_0_FHDLRKC0_140_RKNEN15_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_140_RKNEN15(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_140_RKNEN15_SHIFT)) & VFCCU_0_FHDLRKC0_140_RKNEN15_MASK)

#define VFCCU_0_FHDLRKC0_140_RKNEN16_MASK        (0x40000U)
#define VFCCU_0_FHDLRKC0_140_RKNEN16_SHIFT       (18U)
#define VFCCU_0_FHDLRKC0_140_RKNEN16_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_140_RKNEN16(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_140_RKNEN16_SHIFT)) & VFCCU_0_FHDLRKC0_140_RKNEN16_MASK)

#define VFCCU_0_FHDLRKC0_140_RKNEN17_MASK        (0x80000U)
#define VFCCU_0_FHDLRKC0_140_RKNEN17_SHIFT       (19U)
#define VFCCU_0_FHDLRKC0_140_RKNEN17_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_140_RKNEN17(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_140_RKNEN17_SHIFT)) & VFCCU_0_FHDLRKC0_140_RKNEN17_MASK)

#define VFCCU_0_FHDLRKC0_140_RKNEN18_MASK        (0x100000U)
#define VFCCU_0_FHDLRKC0_140_RKNEN18_SHIFT       (20U)
#define VFCCU_0_FHDLRKC0_140_RKNEN18_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_140_RKNEN18(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_140_RKNEN18_SHIFT)) & VFCCU_0_FHDLRKC0_140_RKNEN18_MASK)

#define VFCCU_0_FHDLRKC0_140_RKNEN19_MASK        (0x200000U)
#define VFCCU_0_FHDLRKC0_140_RKNEN19_SHIFT       (21U)
#define VFCCU_0_FHDLRKC0_140_RKNEN19_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_140_RKNEN19(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_140_RKNEN19_SHIFT)) & VFCCU_0_FHDLRKC0_140_RKNEN19_MASK)

#define VFCCU_0_FHDLRKC0_140_RKNEN20_MASK        (0x400000U)
#define VFCCU_0_FHDLRKC0_140_RKNEN20_SHIFT       (22U)
#define VFCCU_0_FHDLRKC0_140_RKNEN20_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_140_RKNEN20(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_140_RKNEN20_SHIFT)) & VFCCU_0_FHDLRKC0_140_RKNEN20_MASK)

#define VFCCU_0_FHDLRKC0_140_RKNEN21_MASK        (0x800000U)
#define VFCCU_0_FHDLRKC0_140_RKNEN21_SHIFT       (23U)
#define VFCCU_0_FHDLRKC0_140_RKNEN21_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_140_RKNEN21(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_140_RKNEN21_SHIFT)) & VFCCU_0_FHDLRKC0_140_RKNEN21_MASK)

#define VFCCU_0_FHDLRKC0_140_RKNEN22_MASK        (0x1000000U)
#define VFCCU_0_FHDLRKC0_140_RKNEN22_SHIFT       (24U)
#define VFCCU_0_FHDLRKC0_140_RKNEN22_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_140_RKNEN22(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_140_RKNEN22_SHIFT)) & VFCCU_0_FHDLRKC0_140_RKNEN22_MASK)

#define VFCCU_0_FHDLRKC0_140_RKNEN23_MASK        (0x2000000U)
#define VFCCU_0_FHDLRKC0_140_RKNEN23_SHIFT       (25U)
#define VFCCU_0_FHDLRKC0_140_RKNEN23_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_140_RKNEN23(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_140_RKNEN23_SHIFT)) & VFCCU_0_FHDLRKC0_140_RKNEN23_MASK)

#define VFCCU_0_FHDLRKC0_140_RKNEN24_MASK        (0x4000000U)
#define VFCCU_0_FHDLRKC0_140_RKNEN24_SHIFT       (26U)
#define VFCCU_0_FHDLRKC0_140_RKNEN24_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_140_RKNEN24(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_140_RKNEN24_SHIFT)) & VFCCU_0_FHDLRKC0_140_RKNEN24_MASK)

#define VFCCU_0_FHDLRKC0_140_RKNEN25_MASK        (0x8000000U)
#define VFCCU_0_FHDLRKC0_140_RKNEN25_SHIFT       (27U)
#define VFCCU_0_FHDLRKC0_140_RKNEN25_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_140_RKNEN25(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_140_RKNEN25_SHIFT)) & VFCCU_0_FHDLRKC0_140_RKNEN25_MASK)

#define VFCCU_0_FHDLRKC0_140_RKNEN26_MASK        (0x10000000U)
#define VFCCU_0_FHDLRKC0_140_RKNEN26_SHIFT       (28U)
#define VFCCU_0_FHDLRKC0_140_RKNEN26_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_140_RKNEN26(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_140_RKNEN26_SHIFT)) & VFCCU_0_FHDLRKC0_140_RKNEN26_MASK)

#define VFCCU_0_FHDLRKC0_140_RKNEN27_MASK        (0x20000000U)
#define VFCCU_0_FHDLRKC0_140_RKNEN27_SHIFT       (29U)
#define VFCCU_0_FHDLRKC0_140_RKNEN27_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_140_RKNEN27(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_140_RKNEN27_SHIFT)) & VFCCU_0_FHDLRKC0_140_RKNEN27_MASK)

#define VFCCU_0_FHDLRKC0_140_RKNEN28_MASK        (0x40000000U)
#define VFCCU_0_FHDLRKC0_140_RKNEN28_SHIFT       (30U)
#define VFCCU_0_FHDLRKC0_140_RKNEN28_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_140_RKNEN28(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_140_RKNEN28_SHIFT)) & VFCCU_0_FHDLRKC0_140_RKNEN28_MASK)

#define VFCCU_0_FHDLRKC0_140_RKNEN29_MASK        (0x80000000U)
#define VFCCU_0_FHDLRKC0_140_RKNEN29_SHIFT       (31U)
#define VFCCU_0_FHDLRKC0_140_RKNEN29_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_140_RKNEN29(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_140_RKNEN29_SHIFT)) & VFCCU_0_FHDLRKC0_140_RKNEN29_MASK)
/*! @} */

/*! @name FHIMRKC0_150 - Immediate Reaction Configuration */
/*! @{ */

#define VFCCU_0_FHIMRKC0_150_EOUTEN0_MASK        (0x1U)
#define VFCCU_0_FHIMRKC0_150_EOUTEN0_SHIFT       (0U)
#define VFCCU_0_FHIMRKC0_150_EOUTEN0_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_150_EOUTEN0(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_150_EOUTEN0_SHIFT)) & VFCCU_0_FHIMRKC0_150_EOUTEN0_MASK)

#define VFCCU_0_FHIMRKC0_150_EOUTEN1_MASK        (0x2U)
#define VFCCU_0_FHIMRKC0_150_EOUTEN1_SHIFT       (1U)
#define VFCCU_0_FHIMRKC0_150_EOUTEN1_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_150_EOUTEN1(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_150_EOUTEN1_SHIFT)) & VFCCU_0_FHIMRKC0_150_EOUTEN1_MASK)

#define VFCCU_0_FHIMRKC0_150_RKNEN0_MASK         (0x4U)
#define VFCCU_0_FHIMRKC0_150_RKNEN0_SHIFT        (2U)
#define VFCCU_0_FHIMRKC0_150_RKNEN0_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_150_RKNEN0(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_150_RKNEN0_SHIFT)) & VFCCU_0_FHIMRKC0_150_RKNEN0_MASK)

#define VFCCU_0_FHIMRKC0_150_RKNEN1_MASK         (0x8U)
#define VFCCU_0_FHIMRKC0_150_RKNEN1_SHIFT        (3U)
#define VFCCU_0_FHIMRKC0_150_RKNEN1_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_150_RKNEN1(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_150_RKNEN1_SHIFT)) & VFCCU_0_FHIMRKC0_150_RKNEN1_MASK)

#define VFCCU_0_FHIMRKC0_150_RKNEN2_MASK         (0x10U)
#define VFCCU_0_FHIMRKC0_150_RKNEN2_SHIFT        (4U)
#define VFCCU_0_FHIMRKC0_150_RKNEN2_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_150_RKNEN2(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_150_RKNEN2_SHIFT)) & VFCCU_0_FHIMRKC0_150_RKNEN2_MASK)

#define VFCCU_0_FHIMRKC0_150_RKNEN3_MASK         (0x20U)
#define VFCCU_0_FHIMRKC0_150_RKNEN3_SHIFT        (5U)
#define VFCCU_0_FHIMRKC0_150_RKNEN3_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_150_RKNEN3(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_150_RKNEN3_SHIFT)) & VFCCU_0_FHIMRKC0_150_RKNEN3_MASK)

#define VFCCU_0_FHIMRKC0_150_RKNEN4_MASK         (0x40U)
#define VFCCU_0_FHIMRKC0_150_RKNEN4_SHIFT        (6U)
#define VFCCU_0_FHIMRKC0_150_RKNEN4_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_150_RKNEN4(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_150_RKNEN4_SHIFT)) & VFCCU_0_FHIMRKC0_150_RKNEN4_MASK)

#define VFCCU_0_FHIMRKC0_150_RKNEN5_MASK         (0x80U)
#define VFCCU_0_FHIMRKC0_150_RKNEN5_SHIFT        (7U)
#define VFCCU_0_FHIMRKC0_150_RKNEN5_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_150_RKNEN5(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_150_RKNEN5_SHIFT)) & VFCCU_0_FHIMRKC0_150_RKNEN5_MASK)

#define VFCCU_0_FHIMRKC0_150_RKNEN6_MASK         (0x100U)
#define VFCCU_0_FHIMRKC0_150_RKNEN6_SHIFT        (8U)
#define VFCCU_0_FHIMRKC0_150_RKNEN6_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_150_RKNEN6(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_150_RKNEN6_SHIFT)) & VFCCU_0_FHIMRKC0_150_RKNEN6_MASK)

#define VFCCU_0_FHIMRKC0_150_RKNEN7_MASK         (0x200U)
#define VFCCU_0_FHIMRKC0_150_RKNEN7_SHIFT        (9U)
#define VFCCU_0_FHIMRKC0_150_RKNEN7_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_150_RKNEN7(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_150_RKNEN7_SHIFT)) & VFCCU_0_FHIMRKC0_150_RKNEN7_MASK)

#define VFCCU_0_FHIMRKC0_150_RKNEN8_MASK         (0x400U)
#define VFCCU_0_FHIMRKC0_150_RKNEN8_SHIFT        (10U)
#define VFCCU_0_FHIMRKC0_150_RKNEN8_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_150_RKNEN8(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_150_RKNEN8_SHIFT)) & VFCCU_0_FHIMRKC0_150_RKNEN8_MASK)

#define VFCCU_0_FHIMRKC0_150_RKNEN9_MASK         (0x800U)
#define VFCCU_0_FHIMRKC0_150_RKNEN9_SHIFT        (11U)
#define VFCCU_0_FHIMRKC0_150_RKNEN9_WIDTH        (1U)
#define VFCCU_0_FHIMRKC0_150_RKNEN9(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_150_RKNEN9_SHIFT)) & VFCCU_0_FHIMRKC0_150_RKNEN9_MASK)

#define VFCCU_0_FHIMRKC0_150_RKNEN10_MASK        (0x1000U)
#define VFCCU_0_FHIMRKC0_150_RKNEN10_SHIFT       (12U)
#define VFCCU_0_FHIMRKC0_150_RKNEN10_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_150_RKNEN10(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_150_RKNEN10_SHIFT)) & VFCCU_0_FHIMRKC0_150_RKNEN10_MASK)

#define VFCCU_0_FHIMRKC0_150_RKNEN11_MASK        (0x2000U)
#define VFCCU_0_FHIMRKC0_150_RKNEN11_SHIFT       (13U)
#define VFCCU_0_FHIMRKC0_150_RKNEN11_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_150_RKNEN11(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_150_RKNEN11_SHIFT)) & VFCCU_0_FHIMRKC0_150_RKNEN11_MASK)

#define VFCCU_0_FHIMRKC0_150_RKNEN12_MASK        (0x4000U)
#define VFCCU_0_FHIMRKC0_150_RKNEN12_SHIFT       (14U)
#define VFCCU_0_FHIMRKC0_150_RKNEN12_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_150_RKNEN12(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_150_RKNEN12_SHIFT)) & VFCCU_0_FHIMRKC0_150_RKNEN12_MASK)

#define VFCCU_0_FHIMRKC0_150_RKNEN13_MASK        (0x8000U)
#define VFCCU_0_FHIMRKC0_150_RKNEN13_SHIFT       (15U)
#define VFCCU_0_FHIMRKC0_150_RKNEN13_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_150_RKNEN13(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_150_RKNEN13_SHIFT)) & VFCCU_0_FHIMRKC0_150_RKNEN13_MASK)

#define VFCCU_0_FHIMRKC0_150_RKNEN14_MASK        (0x10000U)
#define VFCCU_0_FHIMRKC0_150_RKNEN14_SHIFT       (16U)
#define VFCCU_0_FHIMRKC0_150_RKNEN14_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_150_RKNEN14(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_150_RKNEN14_SHIFT)) & VFCCU_0_FHIMRKC0_150_RKNEN14_MASK)

#define VFCCU_0_FHIMRKC0_150_RKNEN15_MASK        (0x20000U)
#define VFCCU_0_FHIMRKC0_150_RKNEN15_SHIFT       (17U)
#define VFCCU_0_FHIMRKC0_150_RKNEN15_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_150_RKNEN15(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_150_RKNEN15_SHIFT)) & VFCCU_0_FHIMRKC0_150_RKNEN15_MASK)

#define VFCCU_0_FHIMRKC0_150_RKNEN16_MASK        (0x40000U)
#define VFCCU_0_FHIMRKC0_150_RKNEN16_SHIFT       (18U)
#define VFCCU_0_FHIMRKC0_150_RKNEN16_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_150_RKNEN16(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_150_RKNEN16_SHIFT)) & VFCCU_0_FHIMRKC0_150_RKNEN16_MASK)

#define VFCCU_0_FHIMRKC0_150_RKNEN17_MASK        (0x80000U)
#define VFCCU_0_FHIMRKC0_150_RKNEN17_SHIFT       (19U)
#define VFCCU_0_FHIMRKC0_150_RKNEN17_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_150_RKNEN17(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_150_RKNEN17_SHIFT)) & VFCCU_0_FHIMRKC0_150_RKNEN17_MASK)

#define VFCCU_0_FHIMRKC0_150_RKNEN18_MASK        (0x100000U)
#define VFCCU_0_FHIMRKC0_150_RKNEN18_SHIFT       (20U)
#define VFCCU_0_FHIMRKC0_150_RKNEN18_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_150_RKNEN18(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_150_RKNEN18_SHIFT)) & VFCCU_0_FHIMRKC0_150_RKNEN18_MASK)

#define VFCCU_0_FHIMRKC0_150_RKNEN19_MASK        (0x200000U)
#define VFCCU_0_FHIMRKC0_150_RKNEN19_SHIFT       (21U)
#define VFCCU_0_FHIMRKC0_150_RKNEN19_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_150_RKNEN19(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_150_RKNEN19_SHIFT)) & VFCCU_0_FHIMRKC0_150_RKNEN19_MASK)

#define VFCCU_0_FHIMRKC0_150_RKNEN20_MASK        (0x400000U)
#define VFCCU_0_FHIMRKC0_150_RKNEN20_SHIFT       (22U)
#define VFCCU_0_FHIMRKC0_150_RKNEN20_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_150_RKNEN20(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_150_RKNEN20_SHIFT)) & VFCCU_0_FHIMRKC0_150_RKNEN20_MASK)

#define VFCCU_0_FHIMRKC0_150_RKNEN21_MASK        (0x800000U)
#define VFCCU_0_FHIMRKC0_150_RKNEN21_SHIFT       (23U)
#define VFCCU_0_FHIMRKC0_150_RKNEN21_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_150_RKNEN21(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_150_RKNEN21_SHIFT)) & VFCCU_0_FHIMRKC0_150_RKNEN21_MASK)

#define VFCCU_0_FHIMRKC0_150_RKNEN22_MASK        (0x1000000U)
#define VFCCU_0_FHIMRKC0_150_RKNEN22_SHIFT       (24U)
#define VFCCU_0_FHIMRKC0_150_RKNEN22_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_150_RKNEN22(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_150_RKNEN22_SHIFT)) & VFCCU_0_FHIMRKC0_150_RKNEN22_MASK)

#define VFCCU_0_FHIMRKC0_150_RKNEN23_MASK        (0x2000000U)
#define VFCCU_0_FHIMRKC0_150_RKNEN23_SHIFT       (25U)
#define VFCCU_0_FHIMRKC0_150_RKNEN23_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_150_RKNEN23(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_150_RKNEN23_SHIFT)) & VFCCU_0_FHIMRKC0_150_RKNEN23_MASK)

#define VFCCU_0_FHIMRKC0_150_RKNEN24_MASK        (0x4000000U)
#define VFCCU_0_FHIMRKC0_150_RKNEN24_SHIFT       (26U)
#define VFCCU_0_FHIMRKC0_150_RKNEN24_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_150_RKNEN24(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_150_RKNEN24_SHIFT)) & VFCCU_0_FHIMRKC0_150_RKNEN24_MASK)

#define VFCCU_0_FHIMRKC0_150_RKNEN25_MASK        (0x8000000U)
#define VFCCU_0_FHIMRKC0_150_RKNEN25_SHIFT       (27U)
#define VFCCU_0_FHIMRKC0_150_RKNEN25_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_150_RKNEN25(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_150_RKNEN25_SHIFT)) & VFCCU_0_FHIMRKC0_150_RKNEN25_MASK)

#define VFCCU_0_FHIMRKC0_150_RKNEN26_MASK        (0x10000000U)
#define VFCCU_0_FHIMRKC0_150_RKNEN26_SHIFT       (28U)
#define VFCCU_0_FHIMRKC0_150_RKNEN26_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_150_RKNEN26(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_150_RKNEN26_SHIFT)) & VFCCU_0_FHIMRKC0_150_RKNEN26_MASK)

#define VFCCU_0_FHIMRKC0_150_RKNEN27_MASK        (0x20000000U)
#define VFCCU_0_FHIMRKC0_150_RKNEN27_SHIFT       (29U)
#define VFCCU_0_FHIMRKC0_150_RKNEN27_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_150_RKNEN27(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_150_RKNEN27_SHIFT)) & VFCCU_0_FHIMRKC0_150_RKNEN27_MASK)

#define VFCCU_0_FHIMRKC0_150_RKNEN28_MASK        (0x40000000U)
#define VFCCU_0_FHIMRKC0_150_RKNEN28_SHIFT       (30U)
#define VFCCU_0_FHIMRKC0_150_RKNEN28_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_150_RKNEN28(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_150_RKNEN28_SHIFT)) & VFCCU_0_FHIMRKC0_150_RKNEN28_MASK)

#define VFCCU_0_FHIMRKC0_150_RKNEN29_MASK        (0x80000000U)
#define VFCCU_0_FHIMRKC0_150_RKNEN29_SHIFT       (31U)
#define VFCCU_0_FHIMRKC0_150_RKNEN29_WIDTH       (1U)
#define VFCCU_0_FHIMRKC0_150_RKNEN29(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHIMRKC0_150_RKNEN29_SHIFT)) & VFCCU_0_FHIMRKC0_150_RKNEN29_MASK)
/*! @} */

/*! @name FHDLRKC0_150 - Delayed Reaction Configuration */
/*! @{ */

#define VFCCU_0_FHDLRKC0_150_EOUTEN0_MASK        (0x1U)
#define VFCCU_0_FHDLRKC0_150_EOUTEN0_SHIFT       (0U)
#define VFCCU_0_FHDLRKC0_150_EOUTEN0_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_150_EOUTEN0(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_150_EOUTEN0_SHIFT)) & VFCCU_0_FHDLRKC0_150_EOUTEN0_MASK)

#define VFCCU_0_FHDLRKC0_150_EOUTEN1_MASK        (0x2U)
#define VFCCU_0_FHDLRKC0_150_EOUTEN1_SHIFT       (1U)
#define VFCCU_0_FHDLRKC0_150_EOUTEN1_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_150_EOUTEN1(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_150_EOUTEN1_SHIFT)) & VFCCU_0_FHDLRKC0_150_EOUTEN1_MASK)

#define VFCCU_0_FHDLRKC0_150_RKNEN0_MASK         (0x4U)
#define VFCCU_0_FHDLRKC0_150_RKNEN0_SHIFT        (2U)
#define VFCCU_0_FHDLRKC0_150_RKNEN0_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_150_RKNEN0(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_150_RKNEN0_SHIFT)) & VFCCU_0_FHDLRKC0_150_RKNEN0_MASK)

#define VFCCU_0_FHDLRKC0_150_RKNEN1_MASK         (0x8U)
#define VFCCU_0_FHDLRKC0_150_RKNEN1_SHIFT        (3U)
#define VFCCU_0_FHDLRKC0_150_RKNEN1_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_150_RKNEN1(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_150_RKNEN1_SHIFT)) & VFCCU_0_FHDLRKC0_150_RKNEN1_MASK)

#define VFCCU_0_FHDLRKC0_150_RKNEN2_MASK         (0x10U)
#define VFCCU_0_FHDLRKC0_150_RKNEN2_SHIFT        (4U)
#define VFCCU_0_FHDLRKC0_150_RKNEN2_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_150_RKNEN2(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_150_RKNEN2_SHIFT)) & VFCCU_0_FHDLRKC0_150_RKNEN2_MASK)

#define VFCCU_0_FHDLRKC0_150_RKNEN3_MASK         (0x20U)
#define VFCCU_0_FHDLRKC0_150_RKNEN3_SHIFT        (5U)
#define VFCCU_0_FHDLRKC0_150_RKNEN3_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_150_RKNEN3(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_150_RKNEN3_SHIFT)) & VFCCU_0_FHDLRKC0_150_RKNEN3_MASK)

#define VFCCU_0_FHDLRKC0_150_RKNEN4_MASK         (0x40U)
#define VFCCU_0_FHDLRKC0_150_RKNEN4_SHIFT        (6U)
#define VFCCU_0_FHDLRKC0_150_RKNEN4_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_150_RKNEN4(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_150_RKNEN4_SHIFT)) & VFCCU_0_FHDLRKC0_150_RKNEN4_MASK)

#define VFCCU_0_FHDLRKC0_150_RKNEN5_MASK         (0x80U)
#define VFCCU_0_FHDLRKC0_150_RKNEN5_SHIFT        (7U)
#define VFCCU_0_FHDLRKC0_150_RKNEN5_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_150_RKNEN5(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_150_RKNEN5_SHIFT)) & VFCCU_0_FHDLRKC0_150_RKNEN5_MASK)

#define VFCCU_0_FHDLRKC0_150_RKNEN6_MASK         (0x100U)
#define VFCCU_0_FHDLRKC0_150_RKNEN6_SHIFT        (8U)
#define VFCCU_0_FHDLRKC0_150_RKNEN6_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_150_RKNEN6(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_150_RKNEN6_SHIFT)) & VFCCU_0_FHDLRKC0_150_RKNEN6_MASK)

#define VFCCU_0_FHDLRKC0_150_RKNEN7_MASK         (0x200U)
#define VFCCU_0_FHDLRKC0_150_RKNEN7_SHIFT        (9U)
#define VFCCU_0_FHDLRKC0_150_RKNEN7_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_150_RKNEN7(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_150_RKNEN7_SHIFT)) & VFCCU_0_FHDLRKC0_150_RKNEN7_MASK)

#define VFCCU_0_FHDLRKC0_150_RKNEN8_MASK         (0x400U)
#define VFCCU_0_FHDLRKC0_150_RKNEN8_SHIFT        (10U)
#define VFCCU_0_FHDLRKC0_150_RKNEN8_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_150_RKNEN8(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_150_RKNEN8_SHIFT)) & VFCCU_0_FHDLRKC0_150_RKNEN8_MASK)

#define VFCCU_0_FHDLRKC0_150_RKNEN9_MASK         (0x800U)
#define VFCCU_0_FHDLRKC0_150_RKNEN9_SHIFT        (11U)
#define VFCCU_0_FHDLRKC0_150_RKNEN9_WIDTH        (1U)
#define VFCCU_0_FHDLRKC0_150_RKNEN9(x)           (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_150_RKNEN9_SHIFT)) & VFCCU_0_FHDLRKC0_150_RKNEN9_MASK)

#define VFCCU_0_FHDLRKC0_150_RKNEN10_MASK        (0x1000U)
#define VFCCU_0_FHDLRKC0_150_RKNEN10_SHIFT       (12U)
#define VFCCU_0_FHDLRKC0_150_RKNEN10_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_150_RKNEN10(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_150_RKNEN10_SHIFT)) & VFCCU_0_FHDLRKC0_150_RKNEN10_MASK)

#define VFCCU_0_FHDLRKC0_150_RKNEN11_MASK        (0x2000U)
#define VFCCU_0_FHDLRKC0_150_RKNEN11_SHIFT       (13U)
#define VFCCU_0_FHDLRKC0_150_RKNEN11_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_150_RKNEN11(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_150_RKNEN11_SHIFT)) & VFCCU_0_FHDLRKC0_150_RKNEN11_MASK)

#define VFCCU_0_FHDLRKC0_150_RKNEN12_MASK        (0x4000U)
#define VFCCU_0_FHDLRKC0_150_RKNEN12_SHIFT       (14U)
#define VFCCU_0_FHDLRKC0_150_RKNEN12_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_150_RKNEN12(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_150_RKNEN12_SHIFT)) & VFCCU_0_FHDLRKC0_150_RKNEN12_MASK)

#define VFCCU_0_FHDLRKC0_150_RKNEN13_MASK        (0x8000U)
#define VFCCU_0_FHDLRKC0_150_RKNEN13_SHIFT       (15U)
#define VFCCU_0_FHDLRKC0_150_RKNEN13_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_150_RKNEN13(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_150_RKNEN13_SHIFT)) & VFCCU_0_FHDLRKC0_150_RKNEN13_MASK)

#define VFCCU_0_FHDLRKC0_150_RKNEN14_MASK        (0x10000U)
#define VFCCU_0_FHDLRKC0_150_RKNEN14_SHIFT       (16U)
#define VFCCU_0_FHDLRKC0_150_RKNEN14_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_150_RKNEN14(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_150_RKNEN14_SHIFT)) & VFCCU_0_FHDLRKC0_150_RKNEN14_MASK)

#define VFCCU_0_FHDLRKC0_150_RKNEN15_MASK        (0x20000U)
#define VFCCU_0_FHDLRKC0_150_RKNEN15_SHIFT       (17U)
#define VFCCU_0_FHDLRKC0_150_RKNEN15_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_150_RKNEN15(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_150_RKNEN15_SHIFT)) & VFCCU_0_FHDLRKC0_150_RKNEN15_MASK)

#define VFCCU_0_FHDLRKC0_150_RKNEN16_MASK        (0x40000U)
#define VFCCU_0_FHDLRKC0_150_RKNEN16_SHIFT       (18U)
#define VFCCU_0_FHDLRKC0_150_RKNEN16_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_150_RKNEN16(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_150_RKNEN16_SHIFT)) & VFCCU_0_FHDLRKC0_150_RKNEN16_MASK)

#define VFCCU_0_FHDLRKC0_150_RKNEN17_MASK        (0x80000U)
#define VFCCU_0_FHDLRKC0_150_RKNEN17_SHIFT       (19U)
#define VFCCU_0_FHDLRKC0_150_RKNEN17_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_150_RKNEN17(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_150_RKNEN17_SHIFT)) & VFCCU_0_FHDLRKC0_150_RKNEN17_MASK)

#define VFCCU_0_FHDLRKC0_150_RKNEN18_MASK        (0x100000U)
#define VFCCU_0_FHDLRKC0_150_RKNEN18_SHIFT       (20U)
#define VFCCU_0_FHDLRKC0_150_RKNEN18_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_150_RKNEN18(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_150_RKNEN18_SHIFT)) & VFCCU_0_FHDLRKC0_150_RKNEN18_MASK)

#define VFCCU_0_FHDLRKC0_150_RKNEN19_MASK        (0x200000U)
#define VFCCU_0_FHDLRKC0_150_RKNEN19_SHIFT       (21U)
#define VFCCU_0_FHDLRKC0_150_RKNEN19_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_150_RKNEN19(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_150_RKNEN19_SHIFT)) & VFCCU_0_FHDLRKC0_150_RKNEN19_MASK)

#define VFCCU_0_FHDLRKC0_150_RKNEN20_MASK        (0x400000U)
#define VFCCU_0_FHDLRKC0_150_RKNEN20_SHIFT       (22U)
#define VFCCU_0_FHDLRKC0_150_RKNEN20_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_150_RKNEN20(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_150_RKNEN20_SHIFT)) & VFCCU_0_FHDLRKC0_150_RKNEN20_MASK)

#define VFCCU_0_FHDLRKC0_150_RKNEN21_MASK        (0x800000U)
#define VFCCU_0_FHDLRKC0_150_RKNEN21_SHIFT       (23U)
#define VFCCU_0_FHDLRKC0_150_RKNEN21_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_150_RKNEN21(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_150_RKNEN21_SHIFT)) & VFCCU_0_FHDLRKC0_150_RKNEN21_MASK)

#define VFCCU_0_FHDLRKC0_150_RKNEN22_MASK        (0x1000000U)
#define VFCCU_0_FHDLRKC0_150_RKNEN22_SHIFT       (24U)
#define VFCCU_0_FHDLRKC0_150_RKNEN22_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_150_RKNEN22(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_150_RKNEN22_SHIFT)) & VFCCU_0_FHDLRKC0_150_RKNEN22_MASK)

#define VFCCU_0_FHDLRKC0_150_RKNEN23_MASK        (0x2000000U)
#define VFCCU_0_FHDLRKC0_150_RKNEN23_SHIFT       (25U)
#define VFCCU_0_FHDLRKC0_150_RKNEN23_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_150_RKNEN23(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_150_RKNEN23_SHIFT)) & VFCCU_0_FHDLRKC0_150_RKNEN23_MASK)

#define VFCCU_0_FHDLRKC0_150_RKNEN24_MASK        (0x4000000U)
#define VFCCU_0_FHDLRKC0_150_RKNEN24_SHIFT       (26U)
#define VFCCU_0_FHDLRKC0_150_RKNEN24_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_150_RKNEN24(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_150_RKNEN24_SHIFT)) & VFCCU_0_FHDLRKC0_150_RKNEN24_MASK)

#define VFCCU_0_FHDLRKC0_150_RKNEN25_MASK        (0x8000000U)
#define VFCCU_0_FHDLRKC0_150_RKNEN25_SHIFT       (27U)
#define VFCCU_0_FHDLRKC0_150_RKNEN25_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_150_RKNEN25(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_150_RKNEN25_SHIFT)) & VFCCU_0_FHDLRKC0_150_RKNEN25_MASK)

#define VFCCU_0_FHDLRKC0_150_RKNEN26_MASK        (0x10000000U)
#define VFCCU_0_FHDLRKC0_150_RKNEN26_SHIFT       (28U)
#define VFCCU_0_FHDLRKC0_150_RKNEN26_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_150_RKNEN26(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_150_RKNEN26_SHIFT)) & VFCCU_0_FHDLRKC0_150_RKNEN26_MASK)

#define VFCCU_0_FHDLRKC0_150_RKNEN27_MASK        (0x20000000U)
#define VFCCU_0_FHDLRKC0_150_RKNEN27_SHIFT       (29U)
#define VFCCU_0_FHDLRKC0_150_RKNEN27_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_150_RKNEN27(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_150_RKNEN27_SHIFT)) & VFCCU_0_FHDLRKC0_150_RKNEN27_MASK)

#define VFCCU_0_FHDLRKC0_150_RKNEN28_MASK        (0x40000000U)
#define VFCCU_0_FHDLRKC0_150_RKNEN28_SHIFT       (30U)
#define VFCCU_0_FHDLRKC0_150_RKNEN28_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_150_RKNEN28(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_150_RKNEN28_SHIFT)) & VFCCU_0_FHDLRKC0_150_RKNEN28_MASK)

#define VFCCU_0_FHDLRKC0_150_RKNEN29_MASK        (0x80000000U)
#define VFCCU_0_FHDLRKC0_150_RKNEN29_SHIFT       (31U)
#define VFCCU_0_FHDLRKC0_150_RKNEN29_WIDTH       (1U)
#define VFCCU_0_FHDLRKC0_150_RKNEN29(x)          (((uint32_t)(((uint32_t)(x)) << VFCCU_0_FHDLRKC0_150_RKNEN29_SHIFT)) & VFCCU_0_FHDLRKC0_150_RKNEN29_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group VFCCU_0_Register_Masks */

/*!
 * @}
 */ /* end of group VFCCU_0_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K566_VFCCU_0_H_) */
