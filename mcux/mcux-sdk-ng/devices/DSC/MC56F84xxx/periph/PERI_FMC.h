/*
** ###################################################################
**     Processors:          MC56F84441VLF
**                          MC56F84442VLH
**                          MC56F84451VLF
**                          MC56F84452VLH
**                          MC56F84462VLH
**                          MC56F84540VLF
**                          MC56F84543VLH
**                          MC56F84550VLF
**                          MC56F84553VLH
**                          MC56F84565VLK
**                          MC56F84567VLL
**                          MC56F84587VLL
**                          MC56F84763VLH
**                          MC56F84766VLK
**                          MC56F84769VLL
**                          MC56F84786VLK
**                          MC56F84789VLL
**
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for FMC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 2.0 (2021-02-06)
**         Initial version.
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_FMC.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for FMC
 *
 * CMSIS Peripheral Access Layer for FMC
 */

#if !defined(PERI_FMC_H_)
#define PERI_FMC_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MC56F84441VLF))
#include "MC56F84441_COMMON.h"
#elif (defined(CPU_MC56F84442VLH))
#include "MC56F84442_COMMON.h"
#elif (defined(CPU_MC56F84451VLF))
#include "MC56F84451_COMMON.h"
#elif (defined(CPU_MC56F84452VLH))
#include "MC56F84452_COMMON.h"
#elif (defined(CPU_MC56F84462VLH))
#include "MC56F84462_COMMON.h"
#elif (defined(CPU_MC56F84540VLF))
#include "MC56F84540_COMMON.h"
#elif (defined(CPU_MC56F84543VLH))
#include "MC56F84543_COMMON.h"
#elif (defined(CPU_MC56F84550VLF))
#include "MC56F84550_COMMON.h"
#elif (defined(CPU_MC56F84553VLH))
#include "MC56F84553_COMMON.h"
#elif (defined(CPU_MC56F84565VLK))
#include "MC56F84565_COMMON.h"
#elif (defined(CPU_MC56F84567VLL))
#include "MC56F84567_COMMON.h"
#elif (defined(CPU_MC56F84587VLL))
#include "MC56F84587_COMMON.h"
#elif (defined(CPU_MC56F84763VLH))
#include "MC56F84763_COMMON.h"
#elif (defined(CPU_MC56F84766VLK))
#include "MC56F84766_COMMON.h"
#elif (defined(CPU_MC56F84769VLL))
#include "MC56F84769_COMMON.h"
#elif (defined(CPU_MC56F84786VLK))
#include "MC56F84786_COMMON.h"
#elif (defined(CPU_MC56F84789VLL))
#include "MC56F84789_COMMON.h"
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

#if defined(__CWCC__)
  #pragma push
  #pragma cpp_extensions on
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- FMC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FMC_Peripheral_Access_Layer FMC Peripheral Access Layer
 * @{
 */

/** FMC - Register Layout Typedef */
typedef struct {
  __IO uint32_t PFAPR;                             /**< Flash Access Protection Register, offset: 0x0 */
  __IO uint32_t PFB0CR;                            /**< Flash Bank 0 Control Register, offset: 0x2 */
  __I  uint32_t PFB1CR;                            /**< Flash Bank 1 Control Register, offset: 0x4 */
       uint16_t RESERVED_0[122];
  __IO uint32_t TAGVDW0S0;                         /**< Cache Tag Storage, offset: 0x80 */
  __IO uint32_t TAGVDW0S1;                         /**< Cache Tag Storage, offset: 0x82 */
  __IO uint32_t TAGVDW0S2;                         /**< Cache Tag Storage, offset: 0x84 */
  __IO uint32_t TAGVDW0S3;                         /**< Cache Tag Storage, offset: 0x86 */
  __IO uint32_t TAGVDW0S4;                         /**< Cache Tag Storage, offset: 0x88 */
  __IO uint32_t TAGVDW0S5;                         /**< Cache Tag Storage, offset: 0x8A */
  __IO uint32_t TAGVDW0S6;                         /**< Cache Tag Storage, offset: 0x8C */
  __IO uint32_t TAGVDW0S7;                         /**< Cache Tag Storage, offset: 0x8E */
  __IO uint32_t TAGVDW1S0;                         /**< Cache Tag Storage, offset: 0x90 */
  __IO uint32_t TAGVDW1S1;                         /**< Cache Tag Storage, offset: 0x92 */
  __IO uint32_t TAGVDW1S2;                         /**< Cache Tag Storage, offset: 0x94 */
  __IO uint32_t TAGVDW1S3;                         /**< Cache Tag Storage, offset: 0x96 */
  __IO uint32_t TAGVDW1S4;                         /**< Cache Tag Storage, offset: 0x98 */
  __IO uint32_t TAGVDW1S5;                         /**< Cache Tag Storage, offset: 0x9A */
  __IO uint32_t TAGVDW1S6;                         /**< Cache Tag Storage, offset: 0x9C */
  __IO uint32_t TAGVDW1S7;                         /**< Cache Tag Storage, offset: 0x9E */
  __IO uint32_t TAGVDW2S0;                         /**< Cache Tag Storage, offset: 0xA0 */
  __IO uint32_t TAGVDW2S1;                         /**< Cache Tag Storage, offset: 0xA2 */
  __IO uint32_t TAGVDW2S2;                         /**< Cache Tag Storage, offset: 0xA4 */
  __IO uint32_t TAGVDW2S3;                         /**< Cache Tag Storage, offset: 0xA6 */
  __IO uint32_t TAGVDW2S4;                         /**< Cache Tag Storage, offset: 0xA8 */
  __IO uint32_t TAGVDW2S5;                         /**< Cache Tag Storage, offset: 0xAA */
  __IO uint32_t TAGVDW2S6;                         /**< Cache Tag Storage, offset: 0xAC */
  __IO uint32_t TAGVDW2S7;                         /**< Cache Tag Storage, offset: 0xAE */
  __IO uint32_t TAGVDW3S0;                         /**< Cache Tag Storage, offset: 0xB0 */
  __IO uint32_t TAGVDW3S1;                         /**< Cache Tag Storage, offset: 0xB2 */
  __IO uint32_t TAGVDW3S2;                         /**< Cache Tag Storage, offset: 0xB4 */
  __IO uint32_t TAGVDW3S3;                         /**< Cache Tag Storage, offset: 0xB6 */
  __IO uint32_t TAGVDW3S4;                         /**< Cache Tag Storage, offset: 0xB8 */
  __IO uint32_t TAGVDW3S5;                         /**< Cache Tag Storage, offset: 0xBA */
  __IO uint32_t TAGVDW3S6;                         /**< Cache Tag Storage, offset: 0xBC */
  __IO uint32_t TAGVDW3S7;                         /**< Cache Tag Storage, offset: 0xBE */
       uint16_t RESERVED_1[64];
  __IO uint32_t DATAW0S0U;                         /**< Cache Data Storage (upper word), offset: 0x100 */
  __IO uint32_t DATAW0S0L;                         /**< Cache Data Storage (lower word), offset: 0x102 */
  __IO uint32_t DATAW0S1U;                         /**< Cache Data Storage (upper word), offset: 0x104 */
  __IO uint32_t DATAW0S1L;                         /**< Cache Data Storage (lower word), offset: 0x106 */
  __IO uint32_t DATAW0S2U;                         /**< Cache Data Storage (upper word), offset: 0x108 */
  __IO uint32_t DATAW0S2L;                         /**< Cache Data Storage (lower word), offset: 0x10A */
  __IO uint32_t DATAW0S3U;                         /**< Cache Data Storage (upper word), offset: 0x10C */
  __IO uint32_t DATAW0S3L;                         /**< Cache Data Storage (lower word), offset: 0x10E */
  __IO uint32_t DATAW0S4U;                         /**< Cache Data Storage (upper word), offset: 0x110 */
  __IO uint32_t DATAW0S4L;                         /**< Cache Data Storage (lower word), offset: 0x112 */
  __IO uint32_t DATAW0S5U;                         /**< Cache Data Storage (upper word), offset: 0x114 */
  __IO uint32_t DATAW0S5L;                         /**< Cache Data Storage (lower word), offset: 0x116 */
  __IO uint32_t DATAW0S6U;                         /**< Cache Data Storage (upper word), offset: 0x118 */
  __IO uint32_t DATAW0S6L;                         /**< Cache Data Storage (lower word), offset: 0x11A */
  __IO uint32_t DATAW0S7U;                         /**< Cache Data Storage (upper word), offset: 0x11C */
  __IO uint32_t DATAW0S7L;                         /**< Cache Data Storage (lower word), offset: 0x11E */
  __IO uint32_t DATAW1S0U;                         /**< Cache Data Storage (upper word), offset: 0x120 */
  __IO uint32_t DATAW1S0L;                         /**< Cache Data Storage (lower word), offset: 0x122 */
  __IO uint32_t DATAW1S1U;                         /**< Cache Data Storage (upper word), offset: 0x124 */
  __IO uint32_t DATAW1S1L;                         /**< Cache Data Storage (lower word), offset: 0x126 */
  __IO uint32_t DATAW1S2U;                         /**< Cache Data Storage (upper word), offset: 0x128 */
  __IO uint32_t DATAW1S2L;                         /**< Cache Data Storage (lower word), offset: 0x12A */
  __IO uint32_t DATAW1S3U;                         /**< Cache Data Storage (upper word), offset: 0x12C */
  __IO uint32_t DATAW1S3L;                         /**< Cache Data Storage (lower word), offset: 0x12E */
  __IO uint32_t DATAW1S4U;                         /**< Cache Data Storage (upper word), offset: 0x130 */
  __IO uint32_t DATAW1S4L;                         /**< Cache Data Storage (lower word), offset: 0x132 */
  __IO uint32_t DATAW1S5U;                         /**< Cache Data Storage (upper word), offset: 0x134 */
  __IO uint32_t DATAW1S5L;                         /**< Cache Data Storage (lower word), offset: 0x136 */
  __IO uint32_t DATAW1S6U;                         /**< Cache Data Storage (upper word), offset: 0x138 */
  __IO uint32_t DATAW1S6L;                         /**< Cache Data Storage (lower word), offset: 0x13A */
  __IO uint32_t DATAW1S7U;                         /**< Cache Data Storage (upper word), offset: 0x13C */
  __IO uint32_t DATAW1S7L;                         /**< Cache Data Storage (lower word), offset: 0x13E */
  __IO uint32_t DATAW2S0U;                         /**< Cache Data Storage (upper word), offset: 0x140 */
  __IO uint32_t DATAW2S0L;                         /**< Cache Data Storage (lower word), offset: 0x142 */
  __IO uint32_t DATAW2S1U;                         /**< Cache Data Storage (upper word), offset: 0x144 */
  __IO uint32_t DATAW2S1L;                         /**< Cache Data Storage (lower word), offset: 0x146 */
  __IO uint32_t DATAW2S2U;                         /**< Cache Data Storage (upper word), offset: 0x148 */
  __IO uint32_t DATAW2S2L;                         /**< Cache Data Storage (lower word), offset: 0x14A */
  __IO uint32_t DATAW2S3U;                         /**< Cache Data Storage (upper word), offset: 0x14C */
  __IO uint32_t DATAW2S3L;                         /**< Cache Data Storage (lower word), offset: 0x14E */
  __IO uint32_t DATAW2S4U;                         /**< Cache Data Storage (upper word), offset: 0x150 */
  __IO uint32_t DATAW2S4L;                         /**< Cache Data Storage (lower word), offset: 0x152 */
  __IO uint32_t DATAW2S5U;                         /**< Cache Data Storage (upper word), offset: 0x154 */
  __IO uint32_t DATAW2S5L;                         /**< Cache Data Storage (lower word), offset: 0x156 */
  __IO uint32_t DATAW2S6U;                         /**< Cache Data Storage (upper word), offset: 0x158 */
  __IO uint32_t DATAW2S6L;                         /**< Cache Data Storage (lower word), offset: 0x15A */
  __IO uint32_t DATAW2S7U;                         /**< Cache Data Storage (upper word), offset: 0x15C */
  __IO uint32_t DATAW2S7L;                         /**< Cache Data Storage (lower word), offset: 0x15E */
  __IO uint32_t DATAW3S0U;                         /**< Cache Data Storage (upper word), offset: 0x160 */
  __IO uint32_t DATAW3S0L;                         /**< Cache Data Storage (lower word), offset: 0x162 */
  __IO uint32_t DATAW3S1U;                         /**< Cache Data Storage (upper word), offset: 0x164 */
  __IO uint32_t DATAW3S1L;                         /**< Cache Data Storage (lower word), offset: 0x166 */
  __IO uint32_t DATAW3S2U;                         /**< Cache Data Storage (upper word), offset: 0x168 */
  __IO uint32_t DATAW3S2L;                         /**< Cache Data Storage (lower word), offset: 0x16A */
  __IO uint32_t DATAW3S3U;                         /**< Cache Data Storage (upper word), offset: 0x16C */
  __IO uint32_t DATAW3S3L;                         /**< Cache Data Storage (lower word), offset: 0x16E */
  __IO uint32_t DATAW3S4U;                         /**< Cache Data Storage (upper word), offset: 0x170 */
  __IO uint32_t DATAW3S4L;                         /**< Cache Data Storage (lower word), offset: 0x172 */
  __IO uint32_t DATAW3S5U;                         /**< Cache Data Storage (upper word), offset: 0x174 */
  __IO uint32_t DATAW3S5L;                         /**< Cache Data Storage (lower word), offset: 0x176 */
  __IO uint32_t DATAW3S6U;                         /**< Cache Data Storage (upper word), offset: 0x178 */
  __IO uint32_t DATAW3S6L;                         /**< Cache Data Storage (lower word), offset: 0x17A */
  __IO uint32_t DATAW3S7U;                         /**< Cache Data Storage (upper word), offset: 0x17C */
  __IO uint32_t DATAW3S7L;                         /**< Cache Data Storage (lower word), offset: 0x17E */
} FMC_Type;

/* ----------------------------------------------------------------------------
   -- FMC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FMC_Register_Masks FMC Register Masks
 * @{
 */

/*! @name PFAPR - Flash Access Protection Register */
/*! @{ */

#define FMC_PFAPR_M0AP_MASK                      (0x3UL)
#define FMC_PFAPR_M0AP_SHIFT                     (0UL)
/*! M0AP - Master 0 Access Protection
 *  0b00..No access may be performed by this master
 *  0b01..Only read accesses may be performed by this master
 *  0b10..Only write accesses may be performed by this master
 *  0b11..Both read and write accesses may be performed by this master
 */
#define FMC_PFAPR_M0AP(x)                        (((uint32_t)(((uint32_t)(x)) << FMC_PFAPR_M0AP_SHIFT)) & FMC_PFAPR_M0AP_MASK)

#define FMC_PFAPR_M1AP_MASK                      (0xCUL)
#define FMC_PFAPR_M1AP_SHIFT                     (2UL)
/*! M1AP - Master 1 Access Protection
 *  0b00..No access may be performed by this master
 *  0b01..Only read accesses may be performed by this master
 *  0b10..Only write accesses may be performed by this master
 *  0b11..Both read and write accesses may be performed by this master
 */
#define FMC_PFAPR_M1AP(x)                        (((uint32_t)(((uint32_t)(x)) << FMC_PFAPR_M1AP_SHIFT)) & FMC_PFAPR_M1AP_MASK)

#define FMC_PFAPR_M2AP_MASK                      (0x30UL)
#define FMC_PFAPR_M2AP_SHIFT                     (4UL)
/*! M2AP - Master 2 Access Protection
 *  0b00..No access may be performed by this master
 *  0b01..Only read accesses may be performed by this master
 *  0b10..Only write accesses may be performed by this master
 *  0b11..Both read and write accesses may be performed by this master
 */
#define FMC_PFAPR_M2AP(x)                        (((uint32_t)(((uint32_t)(x)) << FMC_PFAPR_M2AP_SHIFT)) & FMC_PFAPR_M2AP_MASK)

#define FMC_PFAPR_M3AP_MASK                      (0xC0UL)
#define FMC_PFAPR_M3AP_SHIFT                     (6UL)
/*! M3AP - Master 3 Access Protection
 *  0b00..No access may be performed by this master
 *  0b01..Only read accesses may be performed by this master
 *  0b10..Only write accesses may be performed by this master
 *  0b11..Both read and write accesses may be performed by this master
 */
#define FMC_PFAPR_M3AP(x)                        (((uint32_t)(((uint32_t)(x)) << FMC_PFAPR_M3AP_SHIFT)) & FMC_PFAPR_M3AP_MASK)

#define FMC_PFAPR_M0PFD_MASK                     (0x10000UL)
#define FMC_PFAPR_M0PFD_SHIFT                    (16UL)
/*! M0PFD - Master 0 Prefetch Disable
 *  0b0..Prefetching for this master is enabled.
 *  0b1..Prefetching for this master is disabled.
 */
#define FMC_PFAPR_M0PFD(x)                       (((uint32_t)(((uint32_t)(x)) << FMC_PFAPR_M0PFD_SHIFT)) & FMC_PFAPR_M0PFD_MASK)

#define FMC_PFAPR_M1PFD_MASK                     (0x20000UL)
#define FMC_PFAPR_M1PFD_SHIFT                    (17UL)
/*! M1PFD - Master 1 Prefetch Disable
 *  0b0..Prefetching for this master is enabled.
 *  0b1..Prefetching for this master is disabled.
 */
#define FMC_PFAPR_M1PFD(x)                       (((uint32_t)(((uint32_t)(x)) << FMC_PFAPR_M1PFD_SHIFT)) & FMC_PFAPR_M1PFD_MASK)

#define FMC_PFAPR_M2PFD_MASK                     (0x40000UL)
#define FMC_PFAPR_M2PFD_SHIFT                    (18UL)
/*! M2PFD - Master 2 Prefetch Disable
 *  0b0..Prefetching for this master is enabled.
 *  0b1..Prefetching for this master is disabled.
 */
#define FMC_PFAPR_M2PFD(x)                       (((uint32_t)(((uint32_t)(x)) << FMC_PFAPR_M2PFD_SHIFT)) & FMC_PFAPR_M2PFD_MASK)

#define FMC_PFAPR_M3PFD_MASK                     (0x80000UL)
#define FMC_PFAPR_M3PFD_SHIFT                    (19UL)
/*! M3PFD - Master 3 Prefetch Disable
 *  0b0..Prefetching for this master is enabled.
 *  0b1..Prefetching for this master is disabled.
 */
#define FMC_PFAPR_M3PFD(x)                       (((uint32_t)(((uint32_t)(x)) << FMC_PFAPR_M3PFD_SHIFT)) & FMC_PFAPR_M3PFD_MASK)
/*! @} */

/*! @name PFB0CR - Flash Bank 0 Control Register */
/*! @{ */

#define FMC_PFB0CR_B0SEBE_MASK                   (0x1UL)
#define FMC_PFB0CR_B0SEBE_SHIFT                  (0UL)
/*! B0SEBE - Bank 0 Single Entry Buffer Enable
 *  0b0..Single entry buffer is disabled.
 *  0b1..Single entry buffer is enabled.
 */
#define FMC_PFB0CR_B0SEBE(x)                     (((uint32_t)(((uint32_t)(x)) << FMC_PFB0CR_B0SEBE_SHIFT)) & FMC_PFB0CR_B0SEBE_MASK)

#define FMC_PFB0CR_B0IPE_MASK                    (0x2UL)
#define FMC_PFB0CR_B0IPE_SHIFT                   (1UL)
/*! B0IPE - Bank 0 Instruction Prefetch Enable
 *  0b0..Do not prefetch in response to instruction fetches.
 *  0b1..Enable prefetches in response to instruction fetches.
 */
#define FMC_PFB0CR_B0IPE(x)                      (((uint32_t)(((uint32_t)(x)) << FMC_PFB0CR_B0IPE_SHIFT)) & FMC_PFB0CR_B0IPE_MASK)

#define FMC_PFB0CR_B0DPE_MASK                    (0x4UL)
#define FMC_PFB0CR_B0DPE_SHIFT                   (2UL)
/*! B0DPE - Bank 0 Data Prefetch Enable
 *  0b0..Do not prefetch in response to data references.
 *  0b1..Enable prefetches in response to data references.
 */
#define FMC_PFB0CR_B0DPE(x)                      (((uint32_t)(((uint32_t)(x)) << FMC_PFB0CR_B0DPE_SHIFT)) & FMC_PFB0CR_B0DPE_MASK)

#define FMC_PFB0CR_B0ICE_MASK                    (0x8UL)
#define FMC_PFB0CR_B0ICE_SHIFT                   (3UL)
/*! B0ICE - Bank 0 Instruction Cache Enable
 *  0b0..Do not cache instruction fetches.
 *  0b1..Cache instruction fetches.
 */
#define FMC_PFB0CR_B0ICE(x)                      (((uint32_t)(((uint32_t)(x)) << FMC_PFB0CR_B0ICE_SHIFT)) & FMC_PFB0CR_B0ICE_MASK)

#define FMC_PFB0CR_B0DCE_MASK                    (0x10UL)
#define FMC_PFB0CR_B0DCE_SHIFT                   (4UL)
/*! B0DCE - Bank 0 Data Cache Enable
 *  0b0..Do not cache data references.
 *  0b1..Cache data references.
 */
#define FMC_PFB0CR_B0DCE(x)                      (((uint32_t)(((uint32_t)(x)) << FMC_PFB0CR_B0DCE_SHIFT)) & FMC_PFB0CR_B0DCE_MASK)

#define FMC_PFB0CR_CRC_MASK                      (0xE0UL)
#define FMC_PFB0CR_CRC_SHIFT                     (5UL)
/*! CRC - Cache Replacement Control
 *  0b000..LRU replacement algorithm per set across all four ways
 *  0b001..Reserved
 *  0b010..Independent LRU with ways [0-1] for ifetches, [2-3] for data
 *  0b011..Independent LRU with ways [0-2] for ifetches, [3] for data
 *  0b1xx..Reserved
 */
#define FMC_PFB0CR_CRC(x)                        (((uint32_t)(((uint32_t)(x)) << FMC_PFB0CR_CRC_SHIFT)) & FMC_PFB0CR_CRC_MASK)

#define FMC_PFB0CR_B0MW_MASK                     (0x60000UL)
#define FMC_PFB0CR_B0MW_SHIFT                    (17UL)
/*! B0MW - Bank 0 Memory Width
 *  0b00..32 bits
 *  0b01..64 bits
 *  0b1x..Reserved
 */
#define FMC_PFB0CR_B0MW(x)                       (((uint32_t)(((uint32_t)(x)) << FMC_PFB0CR_B0MW_SHIFT)) & FMC_PFB0CR_B0MW_MASK)

#define FMC_PFB0CR_S_B_INV_MASK                  (0x80000UL)
#define FMC_PFB0CR_S_B_INV_SHIFT                 (19UL)
/*! S_B_INV - Invalidate Prefetch Speculation Buffer
 *  0b0..Speculation buffer and single entry buffer are not affected.
 *  0b1..Invalidate (clear) speculation buffer and single entry buffer.
 */
#define FMC_PFB0CR_S_B_INV(x)                    (((uint32_t)(((uint32_t)(x)) << FMC_PFB0CR_S_B_INV_SHIFT)) & FMC_PFB0CR_S_B_INV_MASK)

#define FMC_PFB0CR_CINV_WAY_MASK                 (0xF00000UL)
#define FMC_PFB0CR_CINV_WAY_SHIFT                (20UL)
/*! CINV_WAY - Cache Invalidate Way x
 *  0b0000..No cache way invalidation for the corresponding cache
 *  0b0001..Invalidate cache way for the corresponding cache: clear the tag, data, and vld bits of ways selected
 */
#define FMC_PFB0CR_CINV_WAY(x)                   (((uint32_t)(((uint32_t)(x)) << FMC_PFB0CR_CINV_WAY_SHIFT)) & FMC_PFB0CR_CINV_WAY_MASK)

#define FMC_PFB0CR_CLCK_WAY_MASK                 (0xF000000UL)
#define FMC_PFB0CR_CLCK_WAY_SHIFT                (24UL)
/*! CLCK_WAY - Cache Lock Way x
 *  0b0000..Cache way is unlocked and may be displaced
 *  0b0001..Cache way is locked and its contents are not displaced
 */
#define FMC_PFB0CR_CLCK_WAY(x)                   (((uint32_t)(((uint32_t)(x)) << FMC_PFB0CR_CLCK_WAY_SHIFT)) & FMC_PFB0CR_CLCK_WAY_MASK)

#define FMC_PFB0CR_B0RWSC_MASK                   (0xF0000000UL)
#define FMC_PFB0CR_B0RWSC_SHIFT                  (28UL)
/*! B0RWSC - Bank 0 Read Wait State Control */
#define FMC_PFB0CR_B0RWSC(x)                     (((uint32_t)(((uint32_t)(x)) << FMC_PFB0CR_B0RWSC_SHIFT)) & FMC_PFB0CR_B0RWSC_MASK)
/*! @} */

/*! @name PFB1CR - Flash Bank 1 Control Register */
/*! @{ */

#define FMC_PFB1CR_B1MW_MASK                     (0x60000UL)
#define FMC_PFB1CR_B1MW_SHIFT                    (17UL)
/*! B1MW - Bank 1 Memory Width
 *  0b00..32 bits
 *  0b01..64 bits
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define FMC_PFB1CR_B1MW(x)                       (((uint32_t)(((uint32_t)(x)) << FMC_PFB1CR_B1MW_SHIFT)) & FMC_PFB1CR_B1MW_MASK)

#define FMC_PFB1CR_B1RWSC_MASK                   (0xF0000000UL)
#define FMC_PFB1CR_B1RWSC_SHIFT                  (28UL)
/*! B1RWSC - Bank 1 Read Wait State Control */
#define FMC_PFB1CR_B1RWSC(x)                     (((uint32_t)(((uint32_t)(x)) << FMC_PFB1CR_B1RWSC_SHIFT)) & FMC_PFB1CR_B1RWSC_MASK)
/*! @} */

/*! @name TAGVDW0S0 - Cache Tag Storage */
/*! @{ */

#define FMC_TAGVDW0S0_valid_MASK                 (0x1UL)
#define FMC_TAGVDW0S0_valid_SHIFT                (0UL)
/*! valid - 1-bit valid for cache entry */
#define FMC_TAGVDW0S0_valid(x)                   (((uint32_t)(((uint32_t)(x)) << FMC_TAGVDW0S0_valid_SHIFT)) & FMC_TAGVDW0S0_valid_MASK)

#define FMC_TAGVDW0S0_tag_MASK                   (0x7FFC0UL)
#define FMC_TAGVDW0S0_tag_SHIFT                  (6UL)
/*! tag - 13-bit tag for cache entry */
#define FMC_TAGVDW0S0_tag(x)                     (((uint32_t)(((uint32_t)(x)) << FMC_TAGVDW0S0_tag_SHIFT)) & FMC_TAGVDW0S0_tag_MASK)
/*! @} */

/*! @name TAGVDW0S1 - Cache Tag Storage */
/*! @{ */

#define FMC_TAGVDW0S1_valid_MASK                 (0x1UL)
#define FMC_TAGVDW0S1_valid_SHIFT                (0UL)
/*! valid - 1-bit valid for cache entry */
#define FMC_TAGVDW0S1_valid(x)                   (((uint32_t)(((uint32_t)(x)) << FMC_TAGVDW0S1_valid_SHIFT)) & FMC_TAGVDW0S1_valid_MASK)

#define FMC_TAGVDW0S1_tag_MASK                   (0x7FFC0UL)
#define FMC_TAGVDW0S1_tag_SHIFT                  (6UL)
/*! tag - 13-bit tag for cache entry */
#define FMC_TAGVDW0S1_tag(x)                     (((uint32_t)(((uint32_t)(x)) << FMC_TAGVDW0S1_tag_SHIFT)) & FMC_TAGVDW0S1_tag_MASK)
/*! @} */

/*! @name TAGVDW0S2 - Cache Tag Storage */
/*! @{ */

#define FMC_TAGVDW0S2_valid_MASK                 (0x1UL)
#define FMC_TAGVDW0S2_valid_SHIFT                (0UL)
/*! valid - 1-bit valid for cache entry */
#define FMC_TAGVDW0S2_valid(x)                   (((uint32_t)(((uint32_t)(x)) << FMC_TAGVDW0S2_valid_SHIFT)) & FMC_TAGVDW0S2_valid_MASK)

#define FMC_TAGVDW0S2_tag_MASK                   (0x7FFC0UL)
#define FMC_TAGVDW0S2_tag_SHIFT                  (6UL)
/*! tag - 13-bit tag for cache entry */
#define FMC_TAGVDW0S2_tag(x)                     (((uint32_t)(((uint32_t)(x)) << FMC_TAGVDW0S2_tag_SHIFT)) & FMC_TAGVDW0S2_tag_MASK)
/*! @} */

/*! @name TAGVDW0S3 - Cache Tag Storage */
/*! @{ */

#define FMC_TAGVDW0S3_valid_MASK                 (0x1UL)
#define FMC_TAGVDW0S3_valid_SHIFT                (0UL)
/*! valid - 1-bit valid for cache entry */
#define FMC_TAGVDW0S3_valid(x)                   (((uint32_t)(((uint32_t)(x)) << FMC_TAGVDW0S3_valid_SHIFT)) & FMC_TAGVDW0S3_valid_MASK)

#define FMC_TAGVDW0S3_tag_MASK                   (0x7FFC0UL)
#define FMC_TAGVDW0S3_tag_SHIFT                  (6UL)
/*! tag - 13-bit tag for cache entry */
#define FMC_TAGVDW0S3_tag(x)                     (((uint32_t)(((uint32_t)(x)) << FMC_TAGVDW0S3_tag_SHIFT)) & FMC_TAGVDW0S3_tag_MASK)
/*! @} */

/*! @name TAGVDW0S4 - Cache Tag Storage */
/*! @{ */

#define FMC_TAGVDW0S4_valid_MASK                 (0x1UL)
#define FMC_TAGVDW0S4_valid_SHIFT                (0UL)
/*! valid - 1-bit valid for cache entry */
#define FMC_TAGVDW0S4_valid(x)                   (((uint32_t)(((uint32_t)(x)) << FMC_TAGVDW0S4_valid_SHIFT)) & FMC_TAGVDW0S4_valid_MASK)

#define FMC_TAGVDW0S4_tag_MASK                   (0x7FFC0UL)
#define FMC_TAGVDW0S4_tag_SHIFT                  (6UL)
/*! tag - 13-bit tag for cache entry */
#define FMC_TAGVDW0S4_tag(x)                     (((uint32_t)(((uint32_t)(x)) << FMC_TAGVDW0S4_tag_SHIFT)) & FMC_TAGVDW0S4_tag_MASK)
/*! @} */

/*! @name TAGVDW0S5 - Cache Tag Storage */
/*! @{ */

#define FMC_TAGVDW0S5_valid_MASK                 (0x1UL)
#define FMC_TAGVDW0S5_valid_SHIFT                (0UL)
/*! valid - 1-bit valid for cache entry */
#define FMC_TAGVDW0S5_valid(x)                   (((uint32_t)(((uint32_t)(x)) << FMC_TAGVDW0S5_valid_SHIFT)) & FMC_TAGVDW0S5_valid_MASK)

#define FMC_TAGVDW0S5_tag_MASK                   (0x7FFC0UL)
#define FMC_TAGVDW0S5_tag_SHIFT                  (6UL)
/*! tag - 13-bit tag for cache entry */
#define FMC_TAGVDW0S5_tag(x)                     (((uint32_t)(((uint32_t)(x)) << FMC_TAGVDW0S5_tag_SHIFT)) & FMC_TAGVDW0S5_tag_MASK)
/*! @} */

/*! @name TAGVDW0S6 - Cache Tag Storage */
/*! @{ */

#define FMC_TAGVDW0S6_valid_MASK                 (0x1UL)
#define FMC_TAGVDW0S6_valid_SHIFT                (0UL)
/*! valid - 1-bit valid for cache entry */
#define FMC_TAGVDW0S6_valid(x)                   (((uint32_t)(((uint32_t)(x)) << FMC_TAGVDW0S6_valid_SHIFT)) & FMC_TAGVDW0S6_valid_MASK)

#define FMC_TAGVDW0S6_tag_MASK                   (0x7FFC0UL)
#define FMC_TAGVDW0S6_tag_SHIFT                  (6UL)
/*! tag - 13-bit tag for cache entry */
#define FMC_TAGVDW0S6_tag(x)                     (((uint32_t)(((uint32_t)(x)) << FMC_TAGVDW0S6_tag_SHIFT)) & FMC_TAGVDW0S6_tag_MASK)
/*! @} */

/*! @name TAGVDW0S7 - Cache Tag Storage */
/*! @{ */

#define FMC_TAGVDW0S7_valid_MASK                 (0x1UL)
#define FMC_TAGVDW0S7_valid_SHIFT                (0UL)
/*! valid - 1-bit valid for cache entry */
#define FMC_TAGVDW0S7_valid(x)                   (((uint32_t)(((uint32_t)(x)) << FMC_TAGVDW0S7_valid_SHIFT)) & FMC_TAGVDW0S7_valid_MASK)

#define FMC_TAGVDW0S7_tag_MASK                   (0x7FFC0UL)
#define FMC_TAGVDW0S7_tag_SHIFT                  (6UL)
/*! tag - 13-bit tag for cache entry */
#define FMC_TAGVDW0S7_tag(x)                     (((uint32_t)(((uint32_t)(x)) << FMC_TAGVDW0S7_tag_SHIFT)) & FMC_TAGVDW0S7_tag_MASK)
/*! @} */

/*! @name TAGVDW1S0 - Cache Tag Storage */
/*! @{ */

#define FMC_TAGVDW1S0_valid_MASK                 (0x1UL)
#define FMC_TAGVDW1S0_valid_SHIFT                (0UL)
/*! valid - 1-bit valid for cache entry */
#define FMC_TAGVDW1S0_valid(x)                   (((uint32_t)(((uint32_t)(x)) << FMC_TAGVDW1S0_valid_SHIFT)) & FMC_TAGVDW1S0_valid_MASK)

#define FMC_TAGVDW1S0_tag_MASK                   (0x7FFC0UL)
#define FMC_TAGVDW1S0_tag_SHIFT                  (6UL)
/*! tag - 13-bit tag for cache entry */
#define FMC_TAGVDW1S0_tag(x)                     (((uint32_t)(((uint32_t)(x)) << FMC_TAGVDW1S0_tag_SHIFT)) & FMC_TAGVDW1S0_tag_MASK)
/*! @} */

/*! @name TAGVDW1S1 - Cache Tag Storage */
/*! @{ */

#define FMC_TAGVDW1S1_valid_MASK                 (0x1UL)
#define FMC_TAGVDW1S1_valid_SHIFT                (0UL)
/*! valid - 1-bit valid for cache entry */
#define FMC_TAGVDW1S1_valid(x)                   (((uint32_t)(((uint32_t)(x)) << FMC_TAGVDW1S1_valid_SHIFT)) & FMC_TAGVDW1S1_valid_MASK)

#define FMC_TAGVDW1S1_tag_MASK                   (0x7FFC0UL)
#define FMC_TAGVDW1S1_tag_SHIFT                  (6UL)
/*! tag - 13-bit tag for cache entry */
#define FMC_TAGVDW1S1_tag(x)                     (((uint32_t)(((uint32_t)(x)) << FMC_TAGVDW1S1_tag_SHIFT)) & FMC_TAGVDW1S1_tag_MASK)
/*! @} */

/*! @name TAGVDW1S2 - Cache Tag Storage */
/*! @{ */

#define FMC_TAGVDW1S2_valid_MASK                 (0x1UL)
#define FMC_TAGVDW1S2_valid_SHIFT                (0UL)
/*! valid - 1-bit valid for cache entry */
#define FMC_TAGVDW1S2_valid(x)                   (((uint32_t)(((uint32_t)(x)) << FMC_TAGVDW1S2_valid_SHIFT)) & FMC_TAGVDW1S2_valid_MASK)

#define FMC_TAGVDW1S2_tag_MASK                   (0x7FFC0UL)
#define FMC_TAGVDW1S2_tag_SHIFT                  (6UL)
/*! tag - 13-bit tag for cache entry */
#define FMC_TAGVDW1S2_tag(x)                     (((uint32_t)(((uint32_t)(x)) << FMC_TAGVDW1S2_tag_SHIFT)) & FMC_TAGVDW1S2_tag_MASK)
/*! @} */

/*! @name TAGVDW1S3 - Cache Tag Storage */
/*! @{ */

#define FMC_TAGVDW1S3_valid_MASK                 (0x1UL)
#define FMC_TAGVDW1S3_valid_SHIFT                (0UL)
/*! valid - 1-bit valid for cache entry */
#define FMC_TAGVDW1S3_valid(x)                   (((uint32_t)(((uint32_t)(x)) << FMC_TAGVDW1S3_valid_SHIFT)) & FMC_TAGVDW1S3_valid_MASK)

#define FMC_TAGVDW1S3_tag_MASK                   (0x7FFC0UL)
#define FMC_TAGVDW1S3_tag_SHIFT                  (6UL)
/*! tag - 13-bit tag for cache entry */
#define FMC_TAGVDW1S3_tag(x)                     (((uint32_t)(((uint32_t)(x)) << FMC_TAGVDW1S3_tag_SHIFT)) & FMC_TAGVDW1S3_tag_MASK)
/*! @} */

/*! @name TAGVDW1S4 - Cache Tag Storage */
/*! @{ */

#define FMC_TAGVDW1S4_valid_MASK                 (0x1UL)
#define FMC_TAGVDW1S4_valid_SHIFT                (0UL)
/*! valid - 1-bit valid for cache entry */
#define FMC_TAGVDW1S4_valid(x)                   (((uint32_t)(((uint32_t)(x)) << FMC_TAGVDW1S4_valid_SHIFT)) & FMC_TAGVDW1S4_valid_MASK)

#define FMC_TAGVDW1S4_tag_MASK                   (0x7FFC0UL)
#define FMC_TAGVDW1S4_tag_SHIFT                  (6UL)
/*! tag - 13-bit tag for cache entry */
#define FMC_TAGVDW1S4_tag(x)                     (((uint32_t)(((uint32_t)(x)) << FMC_TAGVDW1S4_tag_SHIFT)) & FMC_TAGVDW1S4_tag_MASK)
/*! @} */

/*! @name TAGVDW1S5 - Cache Tag Storage */
/*! @{ */

#define FMC_TAGVDW1S5_valid_MASK                 (0x1UL)
#define FMC_TAGVDW1S5_valid_SHIFT                (0UL)
/*! valid - 1-bit valid for cache entry */
#define FMC_TAGVDW1S5_valid(x)                   (((uint32_t)(((uint32_t)(x)) << FMC_TAGVDW1S5_valid_SHIFT)) & FMC_TAGVDW1S5_valid_MASK)

#define FMC_TAGVDW1S5_tag_MASK                   (0x7FFC0UL)
#define FMC_TAGVDW1S5_tag_SHIFT                  (6UL)
/*! tag - 13-bit tag for cache entry */
#define FMC_TAGVDW1S5_tag(x)                     (((uint32_t)(((uint32_t)(x)) << FMC_TAGVDW1S5_tag_SHIFT)) & FMC_TAGVDW1S5_tag_MASK)
/*! @} */

/*! @name TAGVDW1S6 - Cache Tag Storage */
/*! @{ */

#define FMC_TAGVDW1S6_valid_MASK                 (0x1UL)
#define FMC_TAGVDW1S6_valid_SHIFT                (0UL)
/*! valid - 1-bit valid for cache entry */
#define FMC_TAGVDW1S6_valid(x)                   (((uint32_t)(((uint32_t)(x)) << FMC_TAGVDW1S6_valid_SHIFT)) & FMC_TAGVDW1S6_valid_MASK)

#define FMC_TAGVDW1S6_tag_MASK                   (0x7FFC0UL)
#define FMC_TAGVDW1S6_tag_SHIFT                  (6UL)
/*! tag - 13-bit tag for cache entry */
#define FMC_TAGVDW1S6_tag(x)                     (((uint32_t)(((uint32_t)(x)) << FMC_TAGVDW1S6_tag_SHIFT)) & FMC_TAGVDW1S6_tag_MASK)
/*! @} */

/*! @name TAGVDW1S7 - Cache Tag Storage */
/*! @{ */

#define FMC_TAGVDW1S7_valid_MASK                 (0x1UL)
#define FMC_TAGVDW1S7_valid_SHIFT                (0UL)
/*! valid - 1-bit valid for cache entry */
#define FMC_TAGVDW1S7_valid(x)                   (((uint32_t)(((uint32_t)(x)) << FMC_TAGVDW1S7_valid_SHIFT)) & FMC_TAGVDW1S7_valid_MASK)

#define FMC_TAGVDW1S7_tag_MASK                   (0x7FFC0UL)
#define FMC_TAGVDW1S7_tag_SHIFT                  (6UL)
/*! tag - 13-bit tag for cache entry */
#define FMC_TAGVDW1S7_tag(x)                     (((uint32_t)(((uint32_t)(x)) << FMC_TAGVDW1S7_tag_SHIFT)) & FMC_TAGVDW1S7_tag_MASK)
/*! @} */

/*! @name TAGVDW2S0 - Cache Tag Storage */
/*! @{ */

#define FMC_TAGVDW2S0_valid_MASK                 (0x1UL)
#define FMC_TAGVDW2S0_valid_SHIFT                (0UL)
/*! valid - 1-bit valid for cache entry */
#define FMC_TAGVDW2S0_valid(x)                   (((uint32_t)(((uint32_t)(x)) << FMC_TAGVDW2S0_valid_SHIFT)) & FMC_TAGVDW2S0_valid_MASK)

#define FMC_TAGVDW2S0_tag_MASK                   (0x7FFC0UL)
#define FMC_TAGVDW2S0_tag_SHIFT                  (6UL)
/*! tag - 13-bit tag for cache entry */
#define FMC_TAGVDW2S0_tag(x)                     (((uint32_t)(((uint32_t)(x)) << FMC_TAGVDW2S0_tag_SHIFT)) & FMC_TAGVDW2S0_tag_MASK)
/*! @} */

/*! @name TAGVDW2S1 - Cache Tag Storage */
/*! @{ */

#define FMC_TAGVDW2S1_valid_MASK                 (0x1UL)
#define FMC_TAGVDW2S1_valid_SHIFT                (0UL)
/*! valid - 1-bit valid for cache entry */
#define FMC_TAGVDW2S1_valid(x)                   (((uint32_t)(((uint32_t)(x)) << FMC_TAGVDW2S1_valid_SHIFT)) & FMC_TAGVDW2S1_valid_MASK)

#define FMC_TAGVDW2S1_tag_MASK                   (0x7FFC0UL)
#define FMC_TAGVDW2S1_tag_SHIFT                  (6UL)
/*! tag - 13-bit tag for cache entry */
#define FMC_TAGVDW2S1_tag(x)                     (((uint32_t)(((uint32_t)(x)) << FMC_TAGVDW2S1_tag_SHIFT)) & FMC_TAGVDW2S1_tag_MASK)
/*! @} */

/*! @name TAGVDW2S2 - Cache Tag Storage */
/*! @{ */

#define FMC_TAGVDW2S2_valid_MASK                 (0x1UL)
#define FMC_TAGVDW2S2_valid_SHIFT                (0UL)
/*! valid - 1-bit valid for cache entry */
#define FMC_TAGVDW2S2_valid(x)                   (((uint32_t)(((uint32_t)(x)) << FMC_TAGVDW2S2_valid_SHIFT)) & FMC_TAGVDW2S2_valid_MASK)

#define FMC_TAGVDW2S2_tag_MASK                   (0x7FFC0UL)
#define FMC_TAGVDW2S2_tag_SHIFT                  (6UL)
/*! tag - 13-bit tag for cache entry */
#define FMC_TAGVDW2S2_tag(x)                     (((uint32_t)(((uint32_t)(x)) << FMC_TAGVDW2S2_tag_SHIFT)) & FMC_TAGVDW2S2_tag_MASK)
/*! @} */

/*! @name TAGVDW2S3 - Cache Tag Storage */
/*! @{ */

#define FMC_TAGVDW2S3_valid_MASK                 (0x1UL)
#define FMC_TAGVDW2S3_valid_SHIFT                (0UL)
/*! valid - 1-bit valid for cache entry */
#define FMC_TAGVDW2S3_valid(x)                   (((uint32_t)(((uint32_t)(x)) << FMC_TAGVDW2S3_valid_SHIFT)) & FMC_TAGVDW2S3_valid_MASK)

#define FMC_TAGVDW2S3_tag_MASK                   (0x7FFC0UL)
#define FMC_TAGVDW2S3_tag_SHIFT                  (6UL)
/*! tag - 13-bit tag for cache entry */
#define FMC_TAGVDW2S3_tag(x)                     (((uint32_t)(((uint32_t)(x)) << FMC_TAGVDW2S3_tag_SHIFT)) & FMC_TAGVDW2S3_tag_MASK)
/*! @} */

/*! @name TAGVDW2S4 - Cache Tag Storage */
/*! @{ */

#define FMC_TAGVDW2S4_valid_MASK                 (0x1UL)
#define FMC_TAGVDW2S4_valid_SHIFT                (0UL)
/*! valid - 1-bit valid for cache entry */
#define FMC_TAGVDW2S4_valid(x)                   (((uint32_t)(((uint32_t)(x)) << FMC_TAGVDW2S4_valid_SHIFT)) & FMC_TAGVDW2S4_valid_MASK)

#define FMC_TAGVDW2S4_tag_MASK                   (0x7FFC0UL)
#define FMC_TAGVDW2S4_tag_SHIFT                  (6UL)
/*! tag - 13-bit tag for cache entry */
#define FMC_TAGVDW2S4_tag(x)                     (((uint32_t)(((uint32_t)(x)) << FMC_TAGVDW2S4_tag_SHIFT)) & FMC_TAGVDW2S4_tag_MASK)
/*! @} */

/*! @name TAGVDW2S5 - Cache Tag Storage */
/*! @{ */

#define FMC_TAGVDW2S5_valid_MASK                 (0x1UL)
#define FMC_TAGVDW2S5_valid_SHIFT                (0UL)
/*! valid - 1-bit valid for cache entry */
#define FMC_TAGVDW2S5_valid(x)                   (((uint32_t)(((uint32_t)(x)) << FMC_TAGVDW2S5_valid_SHIFT)) & FMC_TAGVDW2S5_valid_MASK)

#define FMC_TAGVDW2S5_tag_MASK                   (0x7FFC0UL)
#define FMC_TAGVDW2S5_tag_SHIFT                  (6UL)
/*! tag - 13-bit tag for cache entry */
#define FMC_TAGVDW2S5_tag(x)                     (((uint32_t)(((uint32_t)(x)) << FMC_TAGVDW2S5_tag_SHIFT)) & FMC_TAGVDW2S5_tag_MASK)
/*! @} */

/*! @name TAGVDW2S6 - Cache Tag Storage */
/*! @{ */

#define FMC_TAGVDW2S6_valid_MASK                 (0x1UL)
#define FMC_TAGVDW2S6_valid_SHIFT                (0UL)
/*! valid - 1-bit valid for cache entry */
#define FMC_TAGVDW2S6_valid(x)                   (((uint32_t)(((uint32_t)(x)) << FMC_TAGVDW2S6_valid_SHIFT)) & FMC_TAGVDW2S6_valid_MASK)

#define FMC_TAGVDW2S6_tag_MASK                   (0x7FFC0UL)
#define FMC_TAGVDW2S6_tag_SHIFT                  (6UL)
/*! tag - 13-bit tag for cache entry */
#define FMC_TAGVDW2S6_tag(x)                     (((uint32_t)(((uint32_t)(x)) << FMC_TAGVDW2S6_tag_SHIFT)) & FMC_TAGVDW2S6_tag_MASK)
/*! @} */

/*! @name TAGVDW2S7 - Cache Tag Storage */
/*! @{ */

#define FMC_TAGVDW2S7_valid_MASK                 (0x1UL)
#define FMC_TAGVDW2S7_valid_SHIFT                (0UL)
/*! valid - 1-bit valid for cache entry */
#define FMC_TAGVDW2S7_valid(x)                   (((uint32_t)(((uint32_t)(x)) << FMC_TAGVDW2S7_valid_SHIFT)) & FMC_TAGVDW2S7_valid_MASK)

#define FMC_TAGVDW2S7_tag_MASK                   (0x7FFC0UL)
#define FMC_TAGVDW2S7_tag_SHIFT                  (6UL)
/*! tag - 13-bit tag for cache entry */
#define FMC_TAGVDW2S7_tag(x)                     (((uint32_t)(((uint32_t)(x)) << FMC_TAGVDW2S7_tag_SHIFT)) & FMC_TAGVDW2S7_tag_MASK)
/*! @} */

/*! @name TAGVDW3S0 - Cache Tag Storage */
/*! @{ */

#define FMC_TAGVDW3S0_valid_MASK                 (0x1UL)
#define FMC_TAGVDW3S0_valid_SHIFT                (0UL)
/*! valid - 1-bit valid for cache entry */
#define FMC_TAGVDW3S0_valid(x)                   (((uint32_t)(((uint32_t)(x)) << FMC_TAGVDW3S0_valid_SHIFT)) & FMC_TAGVDW3S0_valid_MASK)

#define FMC_TAGVDW3S0_tag_MASK                   (0x7FFC0UL)
#define FMC_TAGVDW3S0_tag_SHIFT                  (6UL)
/*! tag - 13-bit tag for cache entry */
#define FMC_TAGVDW3S0_tag(x)                     (((uint32_t)(((uint32_t)(x)) << FMC_TAGVDW3S0_tag_SHIFT)) & FMC_TAGVDW3S0_tag_MASK)
/*! @} */

/*! @name TAGVDW3S1 - Cache Tag Storage */
/*! @{ */

#define FMC_TAGVDW3S1_valid_MASK                 (0x1UL)
#define FMC_TAGVDW3S1_valid_SHIFT                (0UL)
/*! valid - 1-bit valid for cache entry */
#define FMC_TAGVDW3S1_valid(x)                   (((uint32_t)(((uint32_t)(x)) << FMC_TAGVDW3S1_valid_SHIFT)) & FMC_TAGVDW3S1_valid_MASK)

#define FMC_TAGVDW3S1_tag_MASK                   (0x7FFC0UL)
#define FMC_TAGVDW3S1_tag_SHIFT                  (6UL)
/*! tag - 13-bit tag for cache entry */
#define FMC_TAGVDW3S1_tag(x)                     (((uint32_t)(((uint32_t)(x)) << FMC_TAGVDW3S1_tag_SHIFT)) & FMC_TAGVDW3S1_tag_MASK)
/*! @} */

/*! @name TAGVDW3S2 - Cache Tag Storage */
/*! @{ */

#define FMC_TAGVDW3S2_valid_MASK                 (0x1UL)
#define FMC_TAGVDW3S2_valid_SHIFT                (0UL)
/*! valid - 1-bit valid for cache entry */
#define FMC_TAGVDW3S2_valid(x)                   (((uint32_t)(((uint32_t)(x)) << FMC_TAGVDW3S2_valid_SHIFT)) & FMC_TAGVDW3S2_valid_MASK)

#define FMC_TAGVDW3S2_tag_MASK                   (0x7FFC0UL)
#define FMC_TAGVDW3S2_tag_SHIFT                  (6UL)
/*! tag - 13-bit tag for cache entry */
#define FMC_TAGVDW3S2_tag(x)                     (((uint32_t)(((uint32_t)(x)) << FMC_TAGVDW3S2_tag_SHIFT)) & FMC_TAGVDW3S2_tag_MASK)
/*! @} */

/*! @name TAGVDW3S3 - Cache Tag Storage */
/*! @{ */

#define FMC_TAGVDW3S3_valid_MASK                 (0x1UL)
#define FMC_TAGVDW3S3_valid_SHIFT                (0UL)
/*! valid - 1-bit valid for cache entry */
#define FMC_TAGVDW3S3_valid(x)                   (((uint32_t)(((uint32_t)(x)) << FMC_TAGVDW3S3_valid_SHIFT)) & FMC_TAGVDW3S3_valid_MASK)

#define FMC_TAGVDW3S3_tag_MASK                   (0x7FFC0UL)
#define FMC_TAGVDW3S3_tag_SHIFT                  (6UL)
/*! tag - 13-bit tag for cache entry */
#define FMC_TAGVDW3S3_tag(x)                     (((uint32_t)(((uint32_t)(x)) << FMC_TAGVDW3S3_tag_SHIFT)) & FMC_TAGVDW3S3_tag_MASK)
/*! @} */

/*! @name TAGVDW3S4 - Cache Tag Storage */
/*! @{ */

#define FMC_TAGVDW3S4_valid_MASK                 (0x1UL)
#define FMC_TAGVDW3S4_valid_SHIFT                (0UL)
/*! valid - 1-bit valid for cache entry */
#define FMC_TAGVDW3S4_valid(x)                   (((uint32_t)(((uint32_t)(x)) << FMC_TAGVDW3S4_valid_SHIFT)) & FMC_TAGVDW3S4_valid_MASK)

#define FMC_TAGVDW3S4_tag_MASK                   (0x7FFC0UL)
#define FMC_TAGVDW3S4_tag_SHIFT                  (6UL)
/*! tag - 13-bit tag for cache entry */
#define FMC_TAGVDW3S4_tag(x)                     (((uint32_t)(((uint32_t)(x)) << FMC_TAGVDW3S4_tag_SHIFT)) & FMC_TAGVDW3S4_tag_MASK)
/*! @} */

/*! @name TAGVDW3S5 - Cache Tag Storage */
/*! @{ */

#define FMC_TAGVDW3S5_valid_MASK                 (0x1UL)
#define FMC_TAGVDW3S5_valid_SHIFT                (0UL)
/*! valid - 1-bit valid for cache entry */
#define FMC_TAGVDW3S5_valid(x)                   (((uint32_t)(((uint32_t)(x)) << FMC_TAGVDW3S5_valid_SHIFT)) & FMC_TAGVDW3S5_valid_MASK)

#define FMC_TAGVDW3S5_tag_MASK                   (0x7FFC0UL)
#define FMC_TAGVDW3S5_tag_SHIFT                  (6UL)
/*! tag - 13-bit tag for cache entry */
#define FMC_TAGVDW3S5_tag(x)                     (((uint32_t)(((uint32_t)(x)) << FMC_TAGVDW3S5_tag_SHIFT)) & FMC_TAGVDW3S5_tag_MASK)
/*! @} */

/*! @name TAGVDW3S6 - Cache Tag Storage */
/*! @{ */

#define FMC_TAGVDW3S6_valid_MASK                 (0x1UL)
#define FMC_TAGVDW3S6_valid_SHIFT                (0UL)
/*! valid - 1-bit valid for cache entry */
#define FMC_TAGVDW3S6_valid(x)                   (((uint32_t)(((uint32_t)(x)) << FMC_TAGVDW3S6_valid_SHIFT)) & FMC_TAGVDW3S6_valid_MASK)

#define FMC_TAGVDW3S6_tag_MASK                   (0x7FFC0UL)
#define FMC_TAGVDW3S6_tag_SHIFT                  (6UL)
/*! tag - 13-bit tag for cache entry */
#define FMC_TAGVDW3S6_tag(x)                     (((uint32_t)(((uint32_t)(x)) << FMC_TAGVDW3S6_tag_SHIFT)) & FMC_TAGVDW3S6_tag_MASK)
/*! @} */

/*! @name TAGVDW3S7 - Cache Tag Storage */
/*! @{ */

#define FMC_TAGVDW3S7_valid_MASK                 (0x1UL)
#define FMC_TAGVDW3S7_valid_SHIFT                (0UL)
/*! valid - 1-bit valid for cache entry */
#define FMC_TAGVDW3S7_valid(x)                   (((uint32_t)(((uint32_t)(x)) << FMC_TAGVDW3S7_valid_SHIFT)) & FMC_TAGVDW3S7_valid_MASK)

#define FMC_TAGVDW3S7_tag_MASK                   (0x7FFC0UL)
#define FMC_TAGVDW3S7_tag_SHIFT                  (6UL)
/*! tag - 13-bit tag for cache entry */
#define FMC_TAGVDW3S7_tag(x)                     (((uint32_t)(((uint32_t)(x)) << FMC_TAGVDW3S7_tag_SHIFT)) & FMC_TAGVDW3S7_tag_MASK)
/*! @} */

/*! @name DATAW0S0U - Cache Data Storage (upper word) */
/*! @{ */

#define FMC_DATAW0S0U_data_MASK                  (0xFFFFFFFFUL)
#define FMC_DATAW0S0U_data_SHIFT                 (0UL)
/*! data - Bits [63:32] of data entry */
#define FMC_DATAW0S0U_data(x)                    (((uint32_t)(((uint32_t)(x)) << FMC_DATAW0S0U_data_SHIFT)) & FMC_DATAW0S0U_data_MASK)
/*! @} */

/*! @name DATAW0S0L - Cache Data Storage (lower word) */
/*! @{ */

#define FMC_DATAW0S0L_data_MASK                  (0xFFFFFFFFUL)
#define FMC_DATAW0S0L_data_SHIFT                 (0UL)
/*! data - Bits [31:0] of data entry */
#define FMC_DATAW0S0L_data(x)                    (((uint32_t)(((uint32_t)(x)) << FMC_DATAW0S0L_data_SHIFT)) & FMC_DATAW0S0L_data_MASK)
/*! @} */

/*! @name DATAW0S1U - Cache Data Storage (upper word) */
/*! @{ */

#define FMC_DATAW0S1U_data_MASK                  (0xFFFFFFFFUL)
#define FMC_DATAW0S1U_data_SHIFT                 (0UL)
/*! data - Bits [63:32] of data entry */
#define FMC_DATAW0S1U_data(x)                    (((uint32_t)(((uint32_t)(x)) << FMC_DATAW0S1U_data_SHIFT)) & FMC_DATAW0S1U_data_MASK)
/*! @} */

/*! @name DATAW0S1L - Cache Data Storage (lower word) */
/*! @{ */

#define FMC_DATAW0S1L_data_MASK                  (0xFFFFFFFFUL)
#define FMC_DATAW0S1L_data_SHIFT                 (0UL)
/*! data - Bits [31:0] of data entry */
#define FMC_DATAW0S1L_data(x)                    (((uint32_t)(((uint32_t)(x)) << FMC_DATAW0S1L_data_SHIFT)) & FMC_DATAW0S1L_data_MASK)
/*! @} */

/*! @name DATAW0S2U - Cache Data Storage (upper word) */
/*! @{ */

#define FMC_DATAW0S2U_data_MASK                  (0xFFFFFFFFUL)
#define FMC_DATAW0S2U_data_SHIFT                 (0UL)
/*! data - Bits [63:32] of data entry */
#define FMC_DATAW0S2U_data(x)                    (((uint32_t)(((uint32_t)(x)) << FMC_DATAW0S2U_data_SHIFT)) & FMC_DATAW0S2U_data_MASK)
/*! @} */

/*! @name DATAW0S2L - Cache Data Storage (lower word) */
/*! @{ */

#define FMC_DATAW0S2L_data_MASK                  (0xFFFFFFFFUL)
#define FMC_DATAW0S2L_data_SHIFT                 (0UL)
/*! data - Bits [31:0] of data entry */
#define FMC_DATAW0S2L_data(x)                    (((uint32_t)(((uint32_t)(x)) << FMC_DATAW0S2L_data_SHIFT)) & FMC_DATAW0S2L_data_MASK)
/*! @} */

/*! @name DATAW0S3U - Cache Data Storage (upper word) */
/*! @{ */

#define FMC_DATAW0S3U_data_MASK                  (0xFFFFFFFFUL)
#define FMC_DATAW0S3U_data_SHIFT                 (0UL)
/*! data - Bits [63:32] of data entry */
#define FMC_DATAW0S3U_data(x)                    (((uint32_t)(((uint32_t)(x)) << FMC_DATAW0S3U_data_SHIFT)) & FMC_DATAW0S3U_data_MASK)
/*! @} */

/*! @name DATAW0S3L - Cache Data Storage (lower word) */
/*! @{ */

#define FMC_DATAW0S3L_data_MASK                  (0xFFFFFFFFUL)
#define FMC_DATAW0S3L_data_SHIFT                 (0UL)
/*! data - Bits [31:0] of data entry */
#define FMC_DATAW0S3L_data(x)                    (((uint32_t)(((uint32_t)(x)) << FMC_DATAW0S3L_data_SHIFT)) & FMC_DATAW0S3L_data_MASK)
/*! @} */

/*! @name DATAW0S4U - Cache Data Storage (upper word) */
/*! @{ */

#define FMC_DATAW0S4U_data_MASK                  (0xFFFFFFFFUL)
#define FMC_DATAW0S4U_data_SHIFT                 (0UL)
/*! data - Bits [63:32] of data entry */
#define FMC_DATAW0S4U_data(x)                    (((uint32_t)(((uint32_t)(x)) << FMC_DATAW0S4U_data_SHIFT)) & FMC_DATAW0S4U_data_MASK)
/*! @} */

/*! @name DATAW0S4L - Cache Data Storage (lower word) */
/*! @{ */

#define FMC_DATAW0S4L_data_MASK                  (0xFFFFFFFFUL)
#define FMC_DATAW0S4L_data_SHIFT                 (0UL)
/*! data - Bits [31:0] of data entry */
#define FMC_DATAW0S4L_data(x)                    (((uint32_t)(((uint32_t)(x)) << FMC_DATAW0S4L_data_SHIFT)) & FMC_DATAW0S4L_data_MASK)
/*! @} */

/*! @name DATAW0S5U - Cache Data Storage (upper word) */
/*! @{ */

#define FMC_DATAW0S5U_data_MASK                  (0xFFFFFFFFUL)
#define FMC_DATAW0S5U_data_SHIFT                 (0UL)
/*! data - Bits [63:32] of data entry */
#define FMC_DATAW0S5U_data(x)                    (((uint32_t)(((uint32_t)(x)) << FMC_DATAW0S5U_data_SHIFT)) & FMC_DATAW0S5U_data_MASK)
/*! @} */

/*! @name DATAW0S5L - Cache Data Storage (lower word) */
/*! @{ */

#define FMC_DATAW0S5L_data_MASK                  (0xFFFFFFFFUL)
#define FMC_DATAW0S5L_data_SHIFT                 (0UL)
/*! data - Bits [31:0] of data entry */
#define FMC_DATAW0S5L_data(x)                    (((uint32_t)(((uint32_t)(x)) << FMC_DATAW0S5L_data_SHIFT)) & FMC_DATAW0S5L_data_MASK)
/*! @} */

/*! @name DATAW0S6U - Cache Data Storage (upper word) */
/*! @{ */

#define FMC_DATAW0S6U_data_MASK                  (0xFFFFFFFFUL)
#define FMC_DATAW0S6U_data_SHIFT                 (0UL)
/*! data - Bits [63:32] of data entry */
#define FMC_DATAW0S6U_data(x)                    (((uint32_t)(((uint32_t)(x)) << FMC_DATAW0S6U_data_SHIFT)) & FMC_DATAW0S6U_data_MASK)
/*! @} */

/*! @name DATAW0S6L - Cache Data Storage (lower word) */
/*! @{ */

#define FMC_DATAW0S6L_data_MASK                  (0xFFFFFFFFUL)
#define FMC_DATAW0S6L_data_SHIFT                 (0UL)
/*! data - Bits [31:0] of data entry */
#define FMC_DATAW0S6L_data(x)                    (((uint32_t)(((uint32_t)(x)) << FMC_DATAW0S6L_data_SHIFT)) & FMC_DATAW0S6L_data_MASK)
/*! @} */

/*! @name DATAW0S7U - Cache Data Storage (upper word) */
/*! @{ */

#define FMC_DATAW0S7U_data_MASK                  (0xFFFFFFFFUL)
#define FMC_DATAW0S7U_data_SHIFT                 (0UL)
/*! data - Bits [63:32] of data entry */
#define FMC_DATAW0S7U_data(x)                    (((uint32_t)(((uint32_t)(x)) << FMC_DATAW0S7U_data_SHIFT)) & FMC_DATAW0S7U_data_MASK)
/*! @} */

/*! @name DATAW0S7L - Cache Data Storage (lower word) */
/*! @{ */

#define FMC_DATAW0S7L_data_MASK                  (0xFFFFFFFFUL)
#define FMC_DATAW0S7L_data_SHIFT                 (0UL)
/*! data - Bits [31:0] of data entry */
#define FMC_DATAW0S7L_data(x)                    (((uint32_t)(((uint32_t)(x)) << FMC_DATAW0S7L_data_SHIFT)) & FMC_DATAW0S7L_data_MASK)
/*! @} */

/*! @name DATAW1S0U - Cache Data Storage (upper word) */
/*! @{ */

#define FMC_DATAW1S0U_data_MASK                  (0xFFFFFFFFUL)
#define FMC_DATAW1S0U_data_SHIFT                 (0UL)
/*! data - Bits [63:32] of data entry */
#define FMC_DATAW1S0U_data(x)                    (((uint32_t)(((uint32_t)(x)) << FMC_DATAW1S0U_data_SHIFT)) & FMC_DATAW1S0U_data_MASK)
/*! @} */

/*! @name DATAW1S0L - Cache Data Storage (lower word) */
/*! @{ */

#define FMC_DATAW1S0L_data_MASK                  (0xFFFFFFFFUL)
#define FMC_DATAW1S0L_data_SHIFT                 (0UL)
/*! data - Bits [31:0] of data entry */
#define FMC_DATAW1S0L_data(x)                    (((uint32_t)(((uint32_t)(x)) << FMC_DATAW1S0L_data_SHIFT)) & FMC_DATAW1S0L_data_MASK)
/*! @} */

/*! @name DATAW1S1U - Cache Data Storage (upper word) */
/*! @{ */

#define FMC_DATAW1S1U_data_MASK                  (0xFFFFFFFFUL)
#define FMC_DATAW1S1U_data_SHIFT                 (0UL)
/*! data - Bits [63:32] of data entry */
#define FMC_DATAW1S1U_data(x)                    (((uint32_t)(((uint32_t)(x)) << FMC_DATAW1S1U_data_SHIFT)) & FMC_DATAW1S1U_data_MASK)
/*! @} */

/*! @name DATAW1S1L - Cache Data Storage (lower word) */
/*! @{ */

#define FMC_DATAW1S1L_data_MASK                  (0xFFFFFFFFUL)
#define FMC_DATAW1S1L_data_SHIFT                 (0UL)
/*! data - Bits [31:0] of data entry */
#define FMC_DATAW1S1L_data(x)                    (((uint32_t)(((uint32_t)(x)) << FMC_DATAW1S1L_data_SHIFT)) & FMC_DATAW1S1L_data_MASK)
/*! @} */

/*! @name DATAW1S2U - Cache Data Storage (upper word) */
/*! @{ */

#define FMC_DATAW1S2U_data_MASK                  (0xFFFFFFFFUL)
#define FMC_DATAW1S2U_data_SHIFT                 (0UL)
/*! data - Bits [63:32] of data entry */
#define FMC_DATAW1S2U_data(x)                    (((uint32_t)(((uint32_t)(x)) << FMC_DATAW1S2U_data_SHIFT)) & FMC_DATAW1S2U_data_MASK)
/*! @} */

/*! @name DATAW1S2L - Cache Data Storage (lower word) */
/*! @{ */

#define FMC_DATAW1S2L_data_MASK                  (0xFFFFFFFFUL)
#define FMC_DATAW1S2L_data_SHIFT                 (0UL)
/*! data - Bits [31:0] of data entry */
#define FMC_DATAW1S2L_data(x)                    (((uint32_t)(((uint32_t)(x)) << FMC_DATAW1S2L_data_SHIFT)) & FMC_DATAW1S2L_data_MASK)
/*! @} */

/*! @name DATAW1S3U - Cache Data Storage (upper word) */
/*! @{ */

#define FMC_DATAW1S3U_data_MASK                  (0xFFFFFFFFUL)
#define FMC_DATAW1S3U_data_SHIFT                 (0UL)
/*! data - Bits [63:32] of data entry */
#define FMC_DATAW1S3U_data(x)                    (((uint32_t)(((uint32_t)(x)) << FMC_DATAW1S3U_data_SHIFT)) & FMC_DATAW1S3U_data_MASK)
/*! @} */

/*! @name DATAW1S3L - Cache Data Storage (lower word) */
/*! @{ */

#define FMC_DATAW1S3L_data_MASK                  (0xFFFFFFFFUL)
#define FMC_DATAW1S3L_data_SHIFT                 (0UL)
/*! data - Bits [31:0] of data entry */
#define FMC_DATAW1S3L_data(x)                    (((uint32_t)(((uint32_t)(x)) << FMC_DATAW1S3L_data_SHIFT)) & FMC_DATAW1S3L_data_MASK)
/*! @} */

/*! @name DATAW1S4U - Cache Data Storage (upper word) */
/*! @{ */

#define FMC_DATAW1S4U_data_MASK                  (0xFFFFFFFFUL)
#define FMC_DATAW1S4U_data_SHIFT                 (0UL)
/*! data - Bits [63:32] of data entry */
#define FMC_DATAW1S4U_data(x)                    (((uint32_t)(((uint32_t)(x)) << FMC_DATAW1S4U_data_SHIFT)) & FMC_DATAW1S4U_data_MASK)
/*! @} */

/*! @name DATAW1S4L - Cache Data Storage (lower word) */
/*! @{ */

#define FMC_DATAW1S4L_data_MASK                  (0xFFFFFFFFUL)
#define FMC_DATAW1S4L_data_SHIFT                 (0UL)
/*! data - Bits [31:0] of data entry */
#define FMC_DATAW1S4L_data(x)                    (((uint32_t)(((uint32_t)(x)) << FMC_DATAW1S4L_data_SHIFT)) & FMC_DATAW1S4L_data_MASK)
/*! @} */

/*! @name DATAW1S5U - Cache Data Storage (upper word) */
/*! @{ */

#define FMC_DATAW1S5U_data_MASK                  (0xFFFFFFFFUL)
#define FMC_DATAW1S5U_data_SHIFT                 (0UL)
/*! data - Bits [63:32] of data entry */
#define FMC_DATAW1S5U_data(x)                    (((uint32_t)(((uint32_t)(x)) << FMC_DATAW1S5U_data_SHIFT)) & FMC_DATAW1S5U_data_MASK)
/*! @} */

/*! @name DATAW1S5L - Cache Data Storage (lower word) */
/*! @{ */

#define FMC_DATAW1S5L_data_MASK                  (0xFFFFFFFFUL)
#define FMC_DATAW1S5L_data_SHIFT                 (0UL)
/*! data - Bits [31:0] of data entry */
#define FMC_DATAW1S5L_data(x)                    (((uint32_t)(((uint32_t)(x)) << FMC_DATAW1S5L_data_SHIFT)) & FMC_DATAW1S5L_data_MASK)
/*! @} */

/*! @name DATAW1S6U - Cache Data Storage (upper word) */
/*! @{ */

#define FMC_DATAW1S6U_data_MASK                  (0xFFFFFFFFUL)
#define FMC_DATAW1S6U_data_SHIFT                 (0UL)
/*! data - Bits [63:32] of data entry */
#define FMC_DATAW1S6U_data(x)                    (((uint32_t)(((uint32_t)(x)) << FMC_DATAW1S6U_data_SHIFT)) & FMC_DATAW1S6U_data_MASK)
/*! @} */

/*! @name DATAW1S6L - Cache Data Storage (lower word) */
/*! @{ */

#define FMC_DATAW1S6L_data_MASK                  (0xFFFFFFFFUL)
#define FMC_DATAW1S6L_data_SHIFT                 (0UL)
/*! data - Bits [31:0] of data entry */
#define FMC_DATAW1S6L_data(x)                    (((uint32_t)(((uint32_t)(x)) << FMC_DATAW1S6L_data_SHIFT)) & FMC_DATAW1S6L_data_MASK)
/*! @} */

/*! @name DATAW1S7U - Cache Data Storage (upper word) */
/*! @{ */

#define FMC_DATAW1S7U_data_MASK                  (0xFFFFFFFFUL)
#define FMC_DATAW1S7U_data_SHIFT                 (0UL)
/*! data - Bits [63:32] of data entry */
#define FMC_DATAW1S7U_data(x)                    (((uint32_t)(((uint32_t)(x)) << FMC_DATAW1S7U_data_SHIFT)) & FMC_DATAW1S7U_data_MASK)
/*! @} */

/*! @name DATAW1S7L - Cache Data Storage (lower word) */
/*! @{ */

#define FMC_DATAW1S7L_data_MASK                  (0xFFFFFFFFUL)
#define FMC_DATAW1S7L_data_SHIFT                 (0UL)
/*! data - Bits [31:0] of data entry */
#define FMC_DATAW1S7L_data(x)                    (((uint32_t)(((uint32_t)(x)) << FMC_DATAW1S7L_data_SHIFT)) & FMC_DATAW1S7L_data_MASK)
/*! @} */

/*! @name DATAW2S0U - Cache Data Storage (upper word) */
/*! @{ */

#define FMC_DATAW2S0U_data_MASK                  (0xFFFFFFFFUL)
#define FMC_DATAW2S0U_data_SHIFT                 (0UL)
/*! data - Bits [63:32] of data entry */
#define FMC_DATAW2S0U_data(x)                    (((uint32_t)(((uint32_t)(x)) << FMC_DATAW2S0U_data_SHIFT)) & FMC_DATAW2S0U_data_MASK)
/*! @} */

/*! @name DATAW2S0L - Cache Data Storage (lower word) */
/*! @{ */

#define FMC_DATAW2S0L_data_MASK                  (0xFFFFFFFFUL)
#define FMC_DATAW2S0L_data_SHIFT                 (0UL)
/*! data - Bits [31:0] of data entry */
#define FMC_DATAW2S0L_data(x)                    (((uint32_t)(((uint32_t)(x)) << FMC_DATAW2S0L_data_SHIFT)) & FMC_DATAW2S0L_data_MASK)
/*! @} */

/*! @name DATAW2S1U - Cache Data Storage (upper word) */
/*! @{ */

#define FMC_DATAW2S1U_data_MASK                  (0xFFFFFFFFUL)
#define FMC_DATAW2S1U_data_SHIFT                 (0UL)
/*! data - Bits [63:32] of data entry */
#define FMC_DATAW2S1U_data(x)                    (((uint32_t)(((uint32_t)(x)) << FMC_DATAW2S1U_data_SHIFT)) & FMC_DATAW2S1U_data_MASK)
/*! @} */

/*! @name DATAW2S1L - Cache Data Storage (lower word) */
/*! @{ */

#define FMC_DATAW2S1L_data_MASK                  (0xFFFFFFFFUL)
#define FMC_DATAW2S1L_data_SHIFT                 (0UL)
/*! data - Bits [31:0] of data entry */
#define FMC_DATAW2S1L_data(x)                    (((uint32_t)(((uint32_t)(x)) << FMC_DATAW2S1L_data_SHIFT)) & FMC_DATAW2S1L_data_MASK)
/*! @} */

/*! @name DATAW2S2U - Cache Data Storage (upper word) */
/*! @{ */

#define FMC_DATAW2S2U_data_MASK                  (0xFFFFFFFFUL)
#define FMC_DATAW2S2U_data_SHIFT                 (0UL)
/*! data - Bits [63:32] of data entry */
#define FMC_DATAW2S2U_data(x)                    (((uint32_t)(((uint32_t)(x)) << FMC_DATAW2S2U_data_SHIFT)) & FMC_DATAW2S2U_data_MASK)
/*! @} */

/*! @name DATAW2S2L - Cache Data Storage (lower word) */
/*! @{ */

#define FMC_DATAW2S2L_data_MASK                  (0xFFFFFFFFUL)
#define FMC_DATAW2S2L_data_SHIFT                 (0UL)
/*! data - Bits [31:0] of data entry */
#define FMC_DATAW2S2L_data(x)                    (((uint32_t)(((uint32_t)(x)) << FMC_DATAW2S2L_data_SHIFT)) & FMC_DATAW2S2L_data_MASK)
/*! @} */

/*! @name DATAW2S3U - Cache Data Storage (upper word) */
/*! @{ */

#define FMC_DATAW2S3U_data_MASK                  (0xFFFFFFFFUL)
#define FMC_DATAW2S3U_data_SHIFT                 (0UL)
/*! data - Bits [63:32] of data entry */
#define FMC_DATAW2S3U_data(x)                    (((uint32_t)(((uint32_t)(x)) << FMC_DATAW2S3U_data_SHIFT)) & FMC_DATAW2S3U_data_MASK)
/*! @} */

/*! @name DATAW2S3L - Cache Data Storage (lower word) */
/*! @{ */

#define FMC_DATAW2S3L_data_MASK                  (0xFFFFFFFFUL)
#define FMC_DATAW2S3L_data_SHIFT                 (0UL)
/*! data - Bits [31:0] of data entry */
#define FMC_DATAW2S3L_data(x)                    (((uint32_t)(((uint32_t)(x)) << FMC_DATAW2S3L_data_SHIFT)) & FMC_DATAW2S3L_data_MASK)
/*! @} */

/*! @name DATAW2S4U - Cache Data Storage (upper word) */
/*! @{ */

#define FMC_DATAW2S4U_data_MASK                  (0xFFFFFFFFUL)
#define FMC_DATAW2S4U_data_SHIFT                 (0UL)
/*! data - Bits [63:32] of data entry */
#define FMC_DATAW2S4U_data(x)                    (((uint32_t)(((uint32_t)(x)) << FMC_DATAW2S4U_data_SHIFT)) & FMC_DATAW2S4U_data_MASK)
/*! @} */

/*! @name DATAW2S4L - Cache Data Storage (lower word) */
/*! @{ */

#define FMC_DATAW2S4L_data_MASK                  (0xFFFFFFFFUL)
#define FMC_DATAW2S4L_data_SHIFT                 (0UL)
/*! data - Bits [31:0] of data entry */
#define FMC_DATAW2S4L_data(x)                    (((uint32_t)(((uint32_t)(x)) << FMC_DATAW2S4L_data_SHIFT)) & FMC_DATAW2S4L_data_MASK)
/*! @} */

/*! @name DATAW2S5U - Cache Data Storage (upper word) */
/*! @{ */

#define FMC_DATAW2S5U_data_MASK                  (0xFFFFFFFFUL)
#define FMC_DATAW2S5U_data_SHIFT                 (0UL)
/*! data - Bits [63:32] of data entry */
#define FMC_DATAW2S5U_data(x)                    (((uint32_t)(((uint32_t)(x)) << FMC_DATAW2S5U_data_SHIFT)) & FMC_DATAW2S5U_data_MASK)
/*! @} */

/*! @name DATAW2S5L - Cache Data Storage (lower word) */
/*! @{ */

#define FMC_DATAW2S5L_data_MASK                  (0xFFFFFFFFUL)
#define FMC_DATAW2S5L_data_SHIFT                 (0UL)
/*! data - Bits [31:0] of data entry */
#define FMC_DATAW2S5L_data(x)                    (((uint32_t)(((uint32_t)(x)) << FMC_DATAW2S5L_data_SHIFT)) & FMC_DATAW2S5L_data_MASK)
/*! @} */

/*! @name DATAW2S6U - Cache Data Storage (upper word) */
/*! @{ */

#define FMC_DATAW2S6U_data_MASK                  (0xFFFFFFFFUL)
#define FMC_DATAW2S6U_data_SHIFT                 (0UL)
/*! data - Bits [63:32] of data entry */
#define FMC_DATAW2S6U_data(x)                    (((uint32_t)(((uint32_t)(x)) << FMC_DATAW2S6U_data_SHIFT)) & FMC_DATAW2S6U_data_MASK)
/*! @} */

/*! @name DATAW2S6L - Cache Data Storage (lower word) */
/*! @{ */

#define FMC_DATAW2S6L_data_MASK                  (0xFFFFFFFFUL)
#define FMC_DATAW2S6L_data_SHIFT                 (0UL)
/*! data - Bits [31:0] of data entry */
#define FMC_DATAW2S6L_data(x)                    (((uint32_t)(((uint32_t)(x)) << FMC_DATAW2S6L_data_SHIFT)) & FMC_DATAW2S6L_data_MASK)
/*! @} */

/*! @name DATAW2S7U - Cache Data Storage (upper word) */
/*! @{ */

#define FMC_DATAW2S7U_data_MASK                  (0xFFFFFFFFUL)
#define FMC_DATAW2S7U_data_SHIFT                 (0UL)
/*! data - Bits [63:32] of data entry */
#define FMC_DATAW2S7U_data(x)                    (((uint32_t)(((uint32_t)(x)) << FMC_DATAW2S7U_data_SHIFT)) & FMC_DATAW2S7U_data_MASK)
/*! @} */

/*! @name DATAW2S7L - Cache Data Storage (lower word) */
/*! @{ */

#define FMC_DATAW2S7L_data_MASK                  (0xFFFFFFFFUL)
#define FMC_DATAW2S7L_data_SHIFT                 (0UL)
/*! data - Bits [31:0] of data entry */
#define FMC_DATAW2S7L_data(x)                    (((uint32_t)(((uint32_t)(x)) << FMC_DATAW2S7L_data_SHIFT)) & FMC_DATAW2S7L_data_MASK)
/*! @} */

/*! @name DATAW3S0U - Cache Data Storage (upper word) */
/*! @{ */

#define FMC_DATAW3S0U_data_MASK                  (0xFFFFFFFFUL)
#define FMC_DATAW3S0U_data_SHIFT                 (0UL)
/*! data - Bits [63:32] of data entry */
#define FMC_DATAW3S0U_data(x)                    (((uint32_t)(((uint32_t)(x)) << FMC_DATAW3S0U_data_SHIFT)) & FMC_DATAW3S0U_data_MASK)
/*! @} */

/*! @name DATAW3S0L - Cache Data Storage (lower word) */
/*! @{ */

#define FMC_DATAW3S0L_data_MASK                  (0xFFFFFFFFUL)
#define FMC_DATAW3S0L_data_SHIFT                 (0UL)
/*! data - Bits [31:0] of data entry */
#define FMC_DATAW3S0L_data(x)                    (((uint32_t)(((uint32_t)(x)) << FMC_DATAW3S0L_data_SHIFT)) & FMC_DATAW3S0L_data_MASK)
/*! @} */

/*! @name DATAW3S1U - Cache Data Storage (upper word) */
/*! @{ */

#define FMC_DATAW3S1U_data_MASK                  (0xFFFFFFFFUL)
#define FMC_DATAW3S1U_data_SHIFT                 (0UL)
/*! data - Bits [63:32] of data entry */
#define FMC_DATAW3S1U_data(x)                    (((uint32_t)(((uint32_t)(x)) << FMC_DATAW3S1U_data_SHIFT)) & FMC_DATAW3S1U_data_MASK)
/*! @} */

/*! @name DATAW3S1L - Cache Data Storage (lower word) */
/*! @{ */

#define FMC_DATAW3S1L_data_MASK                  (0xFFFFFFFFUL)
#define FMC_DATAW3S1L_data_SHIFT                 (0UL)
/*! data - Bits [31:0] of data entry */
#define FMC_DATAW3S1L_data(x)                    (((uint32_t)(((uint32_t)(x)) << FMC_DATAW3S1L_data_SHIFT)) & FMC_DATAW3S1L_data_MASK)
/*! @} */

/*! @name DATAW3S2U - Cache Data Storage (upper word) */
/*! @{ */

#define FMC_DATAW3S2U_data_MASK                  (0xFFFFFFFFUL)
#define FMC_DATAW3S2U_data_SHIFT                 (0UL)
/*! data - Bits [63:32] of data entry */
#define FMC_DATAW3S2U_data(x)                    (((uint32_t)(((uint32_t)(x)) << FMC_DATAW3S2U_data_SHIFT)) & FMC_DATAW3S2U_data_MASK)
/*! @} */

/*! @name DATAW3S2L - Cache Data Storage (lower word) */
/*! @{ */

#define FMC_DATAW3S2L_data_MASK                  (0xFFFFFFFFUL)
#define FMC_DATAW3S2L_data_SHIFT                 (0UL)
/*! data - Bits [31:0] of data entry */
#define FMC_DATAW3S2L_data(x)                    (((uint32_t)(((uint32_t)(x)) << FMC_DATAW3S2L_data_SHIFT)) & FMC_DATAW3S2L_data_MASK)
/*! @} */

/*! @name DATAW3S3U - Cache Data Storage (upper word) */
/*! @{ */

#define FMC_DATAW3S3U_data_MASK                  (0xFFFFFFFFUL)
#define FMC_DATAW3S3U_data_SHIFT                 (0UL)
/*! data - Bits [63:32] of data entry */
#define FMC_DATAW3S3U_data(x)                    (((uint32_t)(((uint32_t)(x)) << FMC_DATAW3S3U_data_SHIFT)) & FMC_DATAW3S3U_data_MASK)
/*! @} */

/*! @name DATAW3S3L - Cache Data Storage (lower word) */
/*! @{ */

#define FMC_DATAW3S3L_data_MASK                  (0xFFFFFFFFUL)
#define FMC_DATAW3S3L_data_SHIFT                 (0UL)
/*! data - Bits [31:0] of data entry */
#define FMC_DATAW3S3L_data(x)                    (((uint32_t)(((uint32_t)(x)) << FMC_DATAW3S3L_data_SHIFT)) & FMC_DATAW3S3L_data_MASK)
/*! @} */

/*! @name DATAW3S4U - Cache Data Storage (upper word) */
/*! @{ */

#define FMC_DATAW3S4U_data_MASK                  (0xFFFFFFFFUL)
#define FMC_DATAW3S4U_data_SHIFT                 (0UL)
/*! data - Bits [63:32] of data entry */
#define FMC_DATAW3S4U_data(x)                    (((uint32_t)(((uint32_t)(x)) << FMC_DATAW3S4U_data_SHIFT)) & FMC_DATAW3S4U_data_MASK)
/*! @} */

/*! @name DATAW3S4L - Cache Data Storage (lower word) */
/*! @{ */

#define FMC_DATAW3S4L_data_MASK                  (0xFFFFFFFFUL)
#define FMC_DATAW3S4L_data_SHIFT                 (0UL)
/*! data - Bits [31:0] of data entry */
#define FMC_DATAW3S4L_data(x)                    (((uint32_t)(((uint32_t)(x)) << FMC_DATAW3S4L_data_SHIFT)) & FMC_DATAW3S4L_data_MASK)
/*! @} */

/*! @name DATAW3S5U - Cache Data Storage (upper word) */
/*! @{ */

#define FMC_DATAW3S5U_data_MASK                  (0xFFFFFFFFUL)
#define FMC_DATAW3S5U_data_SHIFT                 (0UL)
/*! data - Bits [63:32] of data entry */
#define FMC_DATAW3S5U_data(x)                    (((uint32_t)(((uint32_t)(x)) << FMC_DATAW3S5U_data_SHIFT)) & FMC_DATAW3S5U_data_MASK)
/*! @} */

/*! @name DATAW3S5L - Cache Data Storage (lower word) */
/*! @{ */

#define FMC_DATAW3S5L_data_MASK                  (0xFFFFFFFFUL)
#define FMC_DATAW3S5L_data_SHIFT                 (0UL)
/*! data - Bits [31:0] of data entry */
#define FMC_DATAW3S5L_data(x)                    (((uint32_t)(((uint32_t)(x)) << FMC_DATAW3S5L_data_SHIFT)) & FMC_DATAW3S5L_data_MASK)
/*! @} */

/*! @name DATAW3S6U - Cache Data Storage (upper word) */
/*! @{ */

#define FMC_DATAW3S6U_data_MASK                  (0xFFFFFFFFUL)
#define FMC_DATAW3S6U_data_SHIFT                 (0UL)
/*! data - Bits [63:32] of data entry */
#define FMC_DATAW3S6U_data(x)                    (((uint32_t)(((uint32_t)(x)) << FMC_DATAW3S6U_data_SHIFT)) & FMC_DATAW3S6U_data_MASK)
/*! @} */

/*! @name DATAW3S6L - Cache Data Storage (lower word) */
/*! @{ */

#define FMC_DATAW3S6L_data_MASK                  (0xFFFFFFFFUL)
#define FMC_DATAW3S6L_data_SHIFT                 (0UL)
/*! data - Bits [31:0] of data entry */
#define FMC_DATAW3S6L_data(x)                    (((uint32_t)(((uint32_t)(x)) << FMC_DATAW3S6L_data_SHIFT)) & FMC_DATAW3S6L_data_MASK)
/*! @} */

/*! @name DATAW3S7U - Cache Data Storage (upper word) */
/*! @{ */

#define FMC_DATAW3S7U_data_MASK                  (0xFFFFFFFFUL)
#define FMC_DATAW3S7U_data_SHIFT                 (0UL)
/*! data - Bits [63:32] of data entry */
#define FMC_DATAW3S7U_data(x)                    (((uint32_t)(((uint32_t)(x)) << FMC_DATAW3S7U_data_SHIFT)) & FMC_DATAW3S7U_data_MASK)
/*! @} */

/*! @name DATAW3S7L - Cache Data Storage (lower word) */
/*! @{ */

#define FMC_DATAW3S7L_data_MASK                  (0xFFFFFFFFUL)
#define FMC_DATAW3S7L_data_SHIFT                 (0UL)
/*! data - Bits [31:0] of data entry */
#define FMC_DATAW3S7L_data(x)                    (((uint32_t)(((uint32_t)(x)) << FMC_DATAW3S7L_data_SHIFT)) & FMC_DATAW3S7L_data_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group FMC_Register_Masks */


/*!
 * @}
 */ /* end of group FMC_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

#if defined(__CWCC__)
  #pragma pop
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_FMC_H_ */

