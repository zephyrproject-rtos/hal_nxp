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
**         CMSIS Peripheral Access Layer for VPU_H1_VP8
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
 * @file PERI_VPU_H1_VP8.h
 * @version 5.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for VPU_H1_VP8
 *
 * CMSIS Peripheral Access Layer for VPU_H1_VP8
 */

#if !defined(PERI_VPU_H1_VP8_H_)
#define PERI_VPU_H1_VP8_H_                       /**< Symbol preventing repeated inclusion */

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
   -- VPU_H1_VP8 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VPU_H1_VP8_Peripheral_Access_Layer VPU_H1_VP8 Peripheral Access Layer
 * @{
 */

/** VPU_H1_VP8 - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[104];
  __IO uint32_t SWREG26_VP8;                       /**< VPU H1 Register 26 - for VP8, offset: 0x68 */
  __IO uint32_t SWREG27_VP8;                       /**< VPU H1 Register 27 - for VP8, offset: 0x6C */
  __IO uint32_t SWREG28_VP8;                       /**< VPU H1 Register 28 - for VP8, offset: 0x70 */
  __IO uint32_t SWREG29_VP8;                       /**< VPU H1 Register 29 - for VP8, offset: 0x74 */
  __IO uint32_t SWREG30_VP8;                       /**< VPU H1 Register 30 - for VP8, offset: 0x78 */
  __IO uint32_t SWREG31_VP8;                       /**< VPU H1 Register 31 - for VP8, offset: 0x7C */
  __IO uint32_t SWREG32_VP8;                       /**< VPU H1 Register 32 - for VP8, offset: 0x80 */
  __IO uint32_t SWREG33_VP8;                       /**< VPU H1 Register 33 - for VP8, offset: 0x84 */
  __IO uint32_t SWREG34_VP8;                       /**< VPU H1 Register 34 - for VP8, offset: 0x88 */
  __IO uint32_t SWREG35_VP8;                       /**< VPU H1 Register 35 - for VP8, offset: 0x8C */
  __IO uint32_t SWREG36_VP8;                       /**< VPU H1 Register 36 - for VP8, offset: 0x90 */
       uint8_t RESERVED_1[84];
  __IO uint32_t SWREG58_VP8;                       /**< VPU H1 Register 58 - for VP8, offset: 0xE8 */
  __IO uint32_t SWREG59_VP8;                       /**< VPU H1 Register 59 - for VP8, offset: 0xEC */
       uint8_t RESERVED_2[16];
  __IO uint32_t SWREG64_VP8;                       /**< VPU H1 Register 64 - for VP8, offset: 0x100 */
  __IO uint32_t SWREG65_VP8;                       /**< VPU H1 Register 65 - for VP8, offset: 0x104 */
  __IO uint32_t SWREG66_VP8;                       /**< VPU H1 Register 66 - for VP8, offset: 0x108 */
  __IO uint32_t SWREG67_VP8;                       /**< VPU H1 Register 67 - for VP8, offset: 0x10C */
  __IO uint32_t SWREG68_VP8;                       /**< VPU H1 Register 68 - for VP8, offset: 0x110 */
  __IO uint32_t SWREG69_VP8;                       /**< VPU H1 Register 69 - for VP8, offset: 0x114 */
  __IO uint32_t SWREG70_VP8;                       /**< VPU H1 Register 70 - for VP8, offset: 0x118 */
  __IO uint32_t SWREG71_VP8;                       /**< VPU H1 Register 71 - for VP8, offset: 0x11C */
  __IO uint32_t SWREG72_VP8;                       /**< VPU H1 Register 72 - for VP8, offset: 0x120 */
  __IO uint32_t SWREG73_VP8;                       /**< VPU H1 Register 73 - for VP8, offset: 0x124 */
  __IO uint32_t SWREG74_VP8;                       /**< VPU H1 Register 74 - for VP8, offset: 0x128 */
  __IO uint32_t SWREG75_VP8;                       /**< VPU H1 Register 75 - for VP8, offset: 0x12C */
  __IO uint32_t SWREG76_VP8;                       /**< VPU H1 Register 76 - for VP8, offset: 0x130 */
  __IO uint32_t SWREG77_VP8;                       /**< VPU H1 Register 77 - for VP8, offset: 0x134 */
  __IO uint32_t SWREG78_VP8;                       /**< VPU H1 Register 78 - for VP8, offset: 0x138 */
  __IO uint32_t SWREG79_VP8;                       /**< VPU H1 Register 79 - for VP8, offset: 0x13C */
  __IO uint32_t SWREG80_VP8;                       /**< VPU H1 Register 80 - for VP8, offset: 0x140 */
  __IO uint32_t SWREG81_VP8;                       /**< VPU H1 Register 81 - for VP8, offset: 0x144 */
  __IO uint32_t SWREG82_VP8;                       /**< VPU H1 Register 82 - for VP8, offset: 0x148 */
  __IO uint32_t SWREG83_VP8;                       /**< VPU H1 Register 83 - for VP8, offset: 0x14C */
  __IO uint32_t SWREG84_VP8;                       /**< VPU H1 Register 84 - for VP8, offset: 0x150 */
  __IO uint32_t SWREG85_VP8;                       /**< VPU H1 Register 85 - for VP8, offset: 0x154 */
  __IO uint32_t SWREG86_VP8;                       /**< VPU H1 Register 86 - for VP8, offset: 0x158 */
  __IO uint32_t SWREG87_VP8;                       /**< VPU H1 Register 87 - for VP8, offset: 0x15C */
  __IO uint32_t SWREG88_VP8;                       /**< VPU H1 Register 88 - for VP8, offset: 0x160 */
  __IO uint32_t SWREG89_VP8;                       /**< VPU H1 Register 89 - for VP8, offset: 0x164 */
  __IO uint32_t SWREG90_VP8;                       /**< VPU H1 Register 90 - for VP8, offset: 0x168 */
  __IO uint32_t SWREG91_VP8;                       /**< VPU H1 Register 91 - for VP8, offset: 0x16C */
  __IO uint32_t SWREG92_VP8;                       /**< VPU H1 Register 92 - for VP8, offset: 0x170 */
  __IO uint32_t SWREG93_VP8;                       /**< VPU H1 Register 93 - for VP8, offset: 0x174 */
  __IO uint32_t SWREG94_VP8;                       /**< VPU H1 Register 94 - for VP8, offset: 0x178 */
  __IO uint32_t SWREG95_VP8;                       /**< VPU H1 Register 95 - for VP8, offset: 0x17C */
} VPU_H1_VP8_Type;

/* ----------------------------------------------------------------------------
   -- VPU_H1_VP8 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VPU_H1_VP8_Register_Masks VPU_H1_VP8 Register Masks
 * @{
 */

/*! @name SWREG26_VP8 - VPU H1 Register 26 - for VP8 */
/*! @{ */

#define VPU_H1_VP8_SWREG26_VP8_BF_0_MASK         (0xFFFFFFFFU)
#define VPU_H1_VP8_SWREG26_VP8_BF_0_SHIFT        (0U)
/*! BF_0 - Base address for VP8 counters for probability updates */
#define VPU_H1_VP8_SWREG26_VP8_BF_0(x)           (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG26_VP8_BF_0_SHIFT)) & VPU_H1_VP8_SWREG26_VP8_BF_0_MASK)
/*! @} */

/*! @name SWREG27_VP8 - VPU H1 Register 27 - for VP8 */
/*! @{ */

#define VPU_H1_VP8_SWREG27_VP8_BF_0_MASK         (0x3FFFU)
#define VPU_H1_VP8_SWREG27_VP8_BF_0_SHIFT        (0U)
/*! BF_0 - VP8 qpY1QuantDc 14b */
#define VPU_H1_VP8_SWREG27_VP8_BF_0(x)           (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG27_VP8_BF_0_SHIFT)) & VPU_H1_VP8_SWREG27_VP8_BF_0_MASK)

#define VPU_H1_VP8_SWREG27_VP8_BF_14_MASK        (0x7FC000U)
#define VPU_H1_VP8_SWREG27_VP8_BF_14_SHIFT       (14U)
/*! BF_14 - VP8 qpY1ZbinDc 9b */
#define VPU_H1_VP8_SWREG27_VP8_BF_14(x)          (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG27_VP8_BF_14_SHIFT)) & VPU_H1_VP8_SWREG27_VP8_BF_14_MASK)

#define VPU_H1_VP8_SWREG27_VP8_BF_23_MASK        (0x7F800000U)
#define VPU_H1_VP8_SWREG27_VP8_BF_23_SHIFT       (23U)
/*! BF_23 - VP8 qpY1RoundDc 8b */
#define VPU_H1_VP8_SWREG27_VP8_BF_23(x)          (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG27_VP8_BF_23_SHIFT)) & VPU_H1_VP8_SWREG27_VP8_BF_23_MASK)
/*! @} */

/*! @name SWREG28_VP8 - VPU H1 Register 28 - for VP8 */
/*! @{ */

#define VPU_H1_VP8_SWREG28_VP8_BF_0_MASK         (0x3FFFU)
#define VPU_H1_VP8_SWREG28_VP8_BF_0_SHIFT        (0U)
/*! BF_0 - VP8 qpY1QuantAc 14b */
#define VPU_H1_VP8_SWREG28_VP8_BF_0(x)           (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG28_VP8_BF_0_SHIFT)) & VPU_H1_VP8_SWREG28_VP8_BF_0_MASK)

#define VPU_H1_VP8_SWREG28_VP8_BF_14_MASK        (0x7FC000U)
#define VPU_H1_VP8_SWREG28_VP8_BF_14_SHIFT       (14U)
/*! BF_14 - VP8 qpY1ZbinAc 9b */
#define VPU_H1_VP8_SWREG28_VP8_BF_14(x)          (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG28_VP8_BF_14_SHIFT)) & VPU_H1_VP8_SWREG28_VP8_BF_14_MASK)

#define VPU_H1_VP8_SWREG28_VP8_BF_23_MASK        (0x7F800000U)
#define VPU_H1_VP8_SWREG28_VP8_BF_23_SHIFT       (23U)
/*! BF_23 - VP8 qpY1RoundAc 8b */
#define VPU_H1_VP8_SWREG28_VP8_BF_23(x)          (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG28_VP8_BF_23_SHIFT)) & VPU_H1_VP8_SWREG28_VP8_BF_23_MASK)
/*! @} */

/*! @name SWREG29_VP8 - VPU H1 Register 29 - for VP8 */
/*! @{ */

#define VPU_H1_VP8_SWREG29_VP8_BF_0_MASK         (0x3FFFU)
#define VPU_H1_VP8_SWREG29_VP8_BF_0_SHIFT        (0U)
/*! BF_0 - VP8 qpY2QuantDc 14b */
#define VPU_H1_VP8_SWREG29_VP8_BF_0(x)           (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG29_VP8_BF_0_SHIFT)) & VPU_H1_VP8_SWREG29_VP8_BF_0_MASK)

#define VPU_H1_VP8_SWREG29_VP8_BF_14_MASK        (0x7FC000U)
#define VPU_H1_VP8_SWREG29_VP8_BF_14_SHIFT       (14U)
/*! BF_14 - VP8 qpY2ZbinDc 9b */
#define VPU_H1_VP8_SWREG29_VP8_BF_14(x)          (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG29_VP8_BF_14_SHIFT)) & VPU_H1_VP8_SWREG29_VP8_BF_14_MASK)

#define VPU_H1_VP8_SWREG29_VP8_BF_23_MASK        (0x7F800000U)
#define VPU_H1_VP8_SWREG29_VP8_BF_23_SHIFT       (23U)
/*! BF_23 - VP8 qpY2RoundDc 8b */
#define VPU_H1_VP8_SWREG29_VP8_BF_23(x)          (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG29_VP8_BF_23_SHIFT)) & VPU_H1_VP8_SWREG29_VP8_BF_23_MASK)
/*! @} */

/*! @name SWREG30_VP8 - VPU H1 Register 30 - for VP8 */
/*! @{ */

#define VPU_H1_VP8_SWREG30_VP8_BF_0_MASK         (0x3FFFU)
#define VPU_H1_VP8_SWREG30_VP8_BF_0_SHIFT        (0U)
/*! BF_0 - VP8 qpY2QuantAc 14b */
#define VPU_H1_VP8_SWREG30_VP8_BF_0(x)           (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG30_VP8_BF_0_SHIFT)) & VPU_H1_VP8_SWREG30_VP8_BF_0_MASK)

#define VPU_H1_VP8_SWREG30_VP8_BF_14_MASK        (0x7FC000U)
#define VPU_H1_VP8_SWREG30_VP8_BF_14_SHIFT       (14U)
/*! BF_14 - VP8 qpY2ZbinAc 9b */
#define VPU_H1_VP8_SWREG30_VP8_BF_14(x)          (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG30_VP8_BF_14_SHIFT)) & VPU_H1_VP8_SWREG30_VP8_BF_14_MASK)

#define VPU_H1_VP8_SWREG30_VP8_BF_23_MASK        (0x7F800000U)
#define VPU_H1_VP8_SWREG30_VP8_BF_23_SHIFT       (23U)
/*! BF_23 - VP8 qpY2RoundAc 8b */
#define VPU_H1_VP8_SWREG30_VP8_BF_23(x)          (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG30_VP8_BF_23_SHIFT)) & VPU_H1_VP8_SWREG30_VP8_BF_23_MASK)
/*! @} */

/*! @name SWREG31_VP8 - VPU H1 Register 31 - for VP8 */
/*! @{ */

#define VPU_H1_VP8_SWREG31_VP8_BF_0_MASK         (0x3FFFU)
#define VPU_H1_VP8_SWREG31_VP8_BF_0_SHIFT        (0U)
/*! BF_0 - VP8 qpChQuantDc 14b */
#define VPU_H1_VP8_SWREG31_VP8_BF_0(x)           (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG31_VP8_BF_0_SHIFT)) & VPU_H1_VP8_SWREG31_VP8_BF_0_MASK)

#define VPU_H1_VP8_SWREG31_VP8_BF_14_MASK        (0x7FC000U)
#define VPU_H1_VP8_SWREG31_VP8_BF_14_SHIFT       (14U)
/*! BF_14 - VP8 qpChZbinDc 9b */
#define VPU_H1_VP8_SWREG31_VP8_BF_14(x)          (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG31_VP8_BF_14_SHIFT)) & VPU_H1_VP8_SWREG31_VP8_BF_14_MASK)

#define VPU_H1_VP8_SWREG31_VP8_BF_23_MASK        (0x7F800000U)
#define VPU_H1_VP8_SWREG31_VP8_BF_23_SHIFT       (23U)
/*! BF_23 - VP8 qpChRoundDc 8b */
#define VPU_H1_VP8_SWREG31_VP8_BF_23(x)          (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG31_VP8_BF_23_SHIFT)) & VPU_H1_VP8_SWREG31_VP8_BF_23_MASK)
/*! @} */

/*! @name SWREG32_VP8 - VPU H1 Register 32 - for VP8 */
/*! @{ */

#define VPU_H1_VP8_SWREG32_VP8_BF_0_MASK         (0x3FFFU)
#define VPU_H1_VP8_SWREG32_VP8_BF_0_SHIFT        (0U)
/*! BF_0 - VP8 qpChQuantAc 14b */
#define VPU_H1_VP8_SWREG32_VP8_BF_0(x)           (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG32_VP8_BF_0_SHIFT)) & VPU_H1_VP8_SWREG32_VP8_BF_0_MASK)

#define VPU_H1_VP8_SWREG32_VP8_BF_14_MASK        (0x7FC000U)
#define VPU_H1_VP8_SWREG32_VP8_BF_14_SHIFT       (14U)
/*! BF_14 - VP8 qpChZbinAc 9b */
#define VPU_H1_VP8_SWREG32_VP8_BF_14(x)          (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG32_VP8_BF_14_SHIFT)) & VPU_H1_VP8_SWREG32_VP8_BF_14_MASK)

#define VPU_H1_VP8_SWREG32_VP8_BF_23_MASK        (0x7F800000U)
#define VPU_H1_VP8_SWREG32_VP8_BF_23_SHIFT       (23U)
/*! BF_23 - VP8 qpChRoundAc 8b */
#define VPU_H1_VP8_SWREG32_VP8_BF_23(x)          (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG32_VP8_BF_23_SHIFT)) & VPU_H1_VP8_SWREG32_VP8_BF_23_MASK)
/*! @} */

/*! @name SWREG33_VP8 - VPU H1 Register 33 - for VP8 */
/*! @{ */

#define VPU_H1_VP8_SWREG33_VP8_BF_0_MASK         (0xFFU)
#define VPU_H1_VP8_SWREG33_VP8_BF_0_SHIFT        (0U)
/*! BF_0 - VP8 qpY1DequantDc 8b */
#define VPU_H1_VP8_SWREG33_VP8_BF_0(x)           (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG33_VP8_BF_0_SHIFT)) & VPU_H1_VP8_SWREG33_VP8_BF_0_MASK)

#define VPU_H1_VP8_SWREG33_VP8_BF_8_MASK         (0x1FF00U)
#define VPU_H1_VP8_SWREG33_VP8_BF_8_SHIFT        (8U)
/*! BF_8 - VP8 qpY1DequantAc 9b */
#define VPU_H1_VP8_SWREG33_VP8_BF_8(x)           (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG33_VP8_BF_8_SHIFT)) & VPU_H1_VP8_SWREG33_VP8_BF_8_MASK)

#define VPU_H1_VP8_SWREG33_VP8_BF_17_MASK        (0x3FE0000U)
#define VPU_H1_VP8_SWREG33_VP8_BF_17_SHIFT       (17U)
/*! BF_17 - VP8 qpY2DequantDc 9b */
#define VPU_H1_VP8_SWREG33_VP8_BF_17(x)          (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG33_VP8_BF_17_SHIFT)) & VPU_H1_VP8_SWREG33_VP8_BF_17_MASK)

#define VPU_H1_VP8_SWREG33_VP8_BF_26_MASK        (0xC000000U)
#define VPU_H1_VP8_SWREG33_VP8_BF_26_SHIFT       (26U)
/*! BF_26 - VP8 mvRefIdx for first reference frame. */
#define VPU_H1_VP8_SWREG33_VP8_BF_26(x)          (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG33_VP8_BF_26_SHIFT)) & VPU_H1_VP8_SWREG33_VP8_BF_26_MASK)
/*! @} */

/*! @name SWREG34_VP8 - VPU H1 Register 34 - for VP8 */
/*! @{ */

#define VPU_H1_VP8_SWREG34_VP8_BF_0_MASK         (0x1FFU)
#define VPU_H1_VP8_SWREG34_VP8_BF_0_SHIFT        (0U)
/*! BF_0 - VP8 qpY2DequantAc 9b */
#define VPU_H1_VP8_SWREG34_VP8_BF_0(x)           (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG34_VP8_BF_0_SHIFT)) & VPU_H1_VP8_SWREG34_VP8_BF_0_MASK)

#define VPU_H1_VP8_SWREG34_VP8_BF_9_MASK         (0x1FE00U)
#define VPU_H1_VP8_SWREG34_VP8_BF_9_SHIFT        (9U)
/*! BF_9 - VP8 qpChDequantDc 8b */
#define VPU_H1_VP8_SWREG34_VP8_BF_9(x)           (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG34_VP8_BF_9_SHIFT)) & VPU_H1_VP8_SWREG34_VP8_BF_9_MASK)

#define VPU_H1_VP8_SWREG34_VP8_BF_17_MASK        (0x3FE0000U)
#define VPU_H1_VP8_SWREG34_VP8_BF_17_SHIFT       (17U)
/*! BF_17 - VP8 qpChDequantAc 9b */
#define VPU_H1_VP8_SWREG34_VP8_BF_17(x)          (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG34_VP8_BF_17_SHIFT)) & VPU_H1_VP8_SWREG34_VP8_BF_17_MASK)

#define VPU_H1_VP8_SWREG34_VP8_BF_26_MASK        (0xC000000U)
#define VPU_H1_VP8_SWREG34_VP8_BF_26_SHIFT       (26U)
/*! BF_26 - VP8 mvRefIdx for second reference frame. */
#define VPU_H1_VP8_SWREG34_VP8_BF_26(x)          (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG34_VP8_BF_26_SHIFT)) & VPU_H1_VP8_SWREG34_VP8_BF_26_MASK)

#define VPU_H1_VP8_SWREG34_VP8_BF_28_MASK        (0x10000000U)
#define VPU_H1_VP8_SWREG34_VP8_BF_28_SHIFT       (28U)
/*! BF_28 - VP8 enable for second reference frame. */
#define VPU_H1_VP8_SWREG34_VP8_BF_28(x)          (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG34_VP8_BF_28_SHIFT)) & VPU_H1_VP8_SWREG34_VP8_BF_28_MASK)

#define VPU_H1_VP8_SWREG34_VP8_BF_29_MASK        (0x20000000U)
#define VPU_H1_VP8_SWREG34_VP8_BF_29_SHIFT       (29U)
/*! BF_29 - VP8 enable for segmentation. Segmentation map is stored in BaseSegmentMap. */
#define VPU_H1_VP8_SWREG34_VP8_BF_29(x)          (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG34_VP8_BF_29_SHIFT)) & VPU_H1_VP8_SWREG34_VP8_BF_29_MASK)

#define VPU_H1_VP8_SWREG34_VP8_BF_30_MASK        (0x40000000U)
#define VPU_H1_VP8_SWREG34_VP8_BF_30_SHIFT       (30U)
/*! BF_30 - VP8 enable for segmentation map update. Map is different from previous frame and is written in stream. */
#define VPU_H1_VP8_SWREG34_VP8_BF_30(x)          (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG34_VP8_BF_30_SHIFT)) & VPU_H1_VP8_SWREG34_VP8_BF_30_MASK)

#define VPU_H1_VP8_SWREG34_VP8_BF_31_MASK        (0x80000000U)
#define VPU_H1_VP8_SWREG34_VP8_BF_31_SHIFT       (31U)
/*! BF_31 - VP8 enable for deadzone. */
#define VPU_H1_VP8_SWREG34_VP8_BF_31(x)          (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG34_VP8_BF_31_SHIFT)) & VPU_H1_VP8_SWREG34_VP8_BF_31_MASK)
/*! @} */

/*! @name SWREG35_VP8 - VPU H1 Register 35 - for VP8 */
/*! @{ */

#define VPU_H1_VP8_SWREG35_VP8_BF_0_MASK         (0xFFFFFFFFU)
#define VPU_H1_VP8_SWREG35_VP8_BF_0_SHIFT        (0U)
/*! BF_0 - VP8 boolEncValue */
#define VPU_H1_VP8_SWREG35_VP8_BF_0(x)           (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG35_VP8_BF_0_SHIFT)) & VPU_H1_VP8_SWREG35_VP8_BF_0_MASK)
/*! @} */

/*! @name SWREG36_VP8 - VPU H1 Register 36 - for VP8 */
/*! @{ */

#define VPU_H1_VP8_SWREG36_VP8_BF_0_MASK         (0xFFU)
#define VPU_H1_VP8_SWREG36_VP8_BF_0_SHIFT        (0U)
/*! BF_0 - VP8 boolEncRange [0..255] */
#define VPU_H1_VP8_SWREG36_VP8_BF_0(x)           (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG36_VP8_BF_0_SHIFT)) & VPU_H1_VP8_SWREG36_VP8_BF_0_MASK)

#define VPU_H1_VP8_SWREG36_VP8_BF_8_MASK         (0x1F00U)
#define VPU_H1_VP8_SWREG36_VP8_BF_8_SHIFT        (8U)
/*! BF_8 - VP8 boolEncValueBitsMinus8 [0..23] */
#define VPU_H1_VP8_SWREG36_VP8_BF_8(x)           (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG36_VP8_BF_8_SHIFT)) & VPU_H1_VP8_SWREG36_VP8_BF_8_MASK)

#define VPU_H1_VP8_SWREG36_VP8_BF_13_MASK        (0x6000U)
#define VPU_H1_VP8_SWREG36_VP8_BF_13_SHIFT       (13U)
/*! BF_13 - VP8 DCT partition count. */
#define VPU_H1_VP8_SWREG36_VP8_BF_13(x)          (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG36_VP8_BF_13_SHIFT)) & VPU_H1_VP8_SWREG36_VP8_BF_13_MASK)

#define VPU_H1_VP8_SWREG36_VP8_BF_15_MASK        (0x1F8000U)
#define VPU_H1_VP8_SWREG36_VP8_BF_15_SHIFT       (15U)
/*! BF_15 - VP8 Deblocking filter level [0..63] */
#define VPU_H1_VP8_SWREG36_VP8_BF_15(x)          (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG36_VP8_BF_15_SHIFT)) & VPU_H1_VP8_SWREG36_VP8_BF_15_MASK)

#define VPU_H1_VP8_SWREG36_VP8_BF_21_MASK        (0xE00000U)
#define VPU_H1_VP8_SWREG36_VP8_BF_21_SHIFT       (21U)
/*! BF_21 - VP8 Deblocking filter sharpness [0..7] */
#define VPU_H1_VP8_SWREG36_VP8_BF_21(x)          (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG36_VP8_BF_21_SHIFT)) & VPU_H1_VP8_SWREG36_VP8_BF_21_MASK)

#define VPU_H1_VP8_SWREG36_VP8_BF_24_MASK        (0xFF000000U)
#define VPU_H1_VP8_SWREG36_VP8_BF_24_SHIFT       (24U)
/*! BF_24 - VP8 Penalty value for second reference frame zero-mv [0..255] */
#define VPU_H1_VP8_SWREG36_VP8_BF_24(x)          (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG36_VP8_BF_24_SHIFT)) & VPU_H1_VP8_SWREG36_VP8_BF_24_MASK)
/*! @} */

/*! @name SWREG58_VP8 - VPU H1 Register 58 - for VP8 */
/*! @{ */

#define VPU_H1_VP8_SWREG58_VP8_BF_0_MASK         (0xFFFFFFFFU)
#define VPU_H1_VP8_SWREG58_VP8_BF_0_SHIFT        (0U)
/*! BF_0 - Base address for VP8 1st DCT partition */
#define VPU_H1_VP8_SWREG58_VP8_BF_0(x)           (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG58_VP8_BF_0_SHIFT)) & VPU_H1_VP8_SWREG58_VP8_BF_0_MASK)
/*! @} */

/*! @name SWREG59_VP8 - VPU H1 Register 59 - for VP8 */
/*! @{ */

#define VPU_H1_VP8_SWREG59_VP8_BF_0_MASK         (0xFFFFFFFFU)
#define VPU_H1_VP8_SWREG59_VP8_BF_0_SHIFT        (0U)
/*! BF_0 - Base address for VP8 2nd DCT partition */
#define VPU_H1_VP8_SWREG59_VP8_BF_0(x)           (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG59_VP8_BF_0_SHIFT)) & VPU_H1_VP8_SWREG59_VP8_BF_0_MASK)
/*! @} */

/*! @name SWREG64_VP8 - VPU H1 Register 64 - for VP8 */
/*! @{ */

#define VPU_H1_VP8_SWREG64_VP8_BF_0_MASK         (0x3FFU)
#define VPU_H1_VP8_SWREG64_VP8_BF_0_SHIFT        (0U)
/*! BF_0 - VP8 intra 16x16 mode 0 penalty */
#define VPU_H1_VP8_SWREG64_VP8_BF_0(x)           (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG64_VP8_BF_0_SHIFT)) & VPU_H1_VP8_SWREG64_VP8_BF_0_MASK)

#define VPU_H1_VP8_SWREG64_VP8_BF_12_MASK        (0x3FF000U)
#define VPU_H1_VP8_SWREG64_VP8_BF_12_SHIFT       (12U)
/*! BF_12 - VP8 intra 16x16 mode 1 penalty */
#define VPU_H1_VP8_SWREG64_VP8_BF_12(x)          (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG64_VP8_BF_12_SHIFT)) & VPU_H1_VP8_SWREG64_VP8_BF_12_MASK)
/*! @} */

/*! @name SWREG65_VP8 - VPU H1 Register 65 - for VP8 */
/*! @{ */

#define VPU_H1_VP8_SWREG65_VP8_BF_0_MASK         (0x3FFU)
#define VPU_H1_VP8_SWREG65_VP8_BF_0_SHIFT        (0U)
/*! BF_0 - VP8 intra 16x16 mode 2 penalty */
#define VPU_H1_VP8_SWREG65_VP8_BF_0(x)           (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG65_VP8_BF_0_SHIFT)) & VPU_H1_VP8_SWREG65_VP8_BF_0_MASK)

#define VPU_H1_VP8_SWREG65_VP8_BF_12_MASK        (0x3FF000U)
#define VPU_H1_VP8_SWREG65_VP8_BF_12_SHIFT       (12U)
/*! BF_12 - VP8 intra 16x16 mode 3 penalty */
#define VPU_H1_VP8_SWREG65_VP8_BF_12(x)          (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG65_VP8_BF_12_SHIFT)) & VPU_H1_VP8_SWREG65_VP8_BF_12_MASK)
/*! @} */

/*! @name SWREG66_VP8 - VPU H1 Register 66 - for VP8 */
/*! @{ */

#define VPU_H1_VP8_SWREG66_VP8_BF_0_MASK         (0x3FFU)
#define VPU_H1_VP8_SWREG66_VP8_BF_0_SHIFT        (0U)
/*! BF_0 - VP8 intra 4x4 mode 0 penalty */
#define VPU_H1_VP8_SWREG66_VP8_BF_0(x)           (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG66_VP8_BF_0_SHIFT)) & VPU_H1_VP8_SWREG66_VP8_BF_0_MASK)

#define VPU_H1_VP8_SWREG66_VP8_BF_12_MASK        (0x3FF000U)
#define VPU_H1_VP8_SWREG66_VP8_BF_12_SHIFT       (12U)
/*! BF_12 - VP8 intra 4x4 mode 1 penalty */
#define VPU_H1_VP8_SWREG66_VP8_BF_12(x)          (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG66_VP8_BF_12_SHIFT)) & VPU_H1_VP8_SWREG66_VP8_BF_12_MASK)
/*! @} */

/*! @name SWREG67_VP8 - VPU H1 Register 67 - for VP8 */
/*! @{ */

#define VPU_H1_VP8_SWREG67_VP8_BF_0_MASK         (0x3FFU)
#define VPU_H1_VP8_SWREG67_VP8_BF_0_SHIFT        (0U)
/*! BF_0 - VP8 intra 4x4 mode 2 penalty */
#define VPU_H1_VP8_SWREG67_VP8_BF_0(x)           (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG67_VP8_BF_0_SHIFT)) & VPU_H1_VP8_SWREG67_VP8_BF_0_MASK)

#define VPU_H1_VP8_SWREG67_VP8_BF_12_MASK        (0x3FF000U)
#define VPU_H1_VP8_SWREG67_VP8_BF_12_SHIFT       (12U)
/*! BF_12 - VP8 intra 4x4 mode 3 penalty */
#define VPU_H1_VP8_SWREG67_VP8_BF_12(x)          (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG67_VP8_BF_12_SHIFT)) & VPU_H1_VP8_SWREG67_VP8_BF_12_MASK)
/*! @} */

/*! @name SWREG68_VP8 - VPU H1 Register 68 - for VP8 */
/*! @{ */

#define VPU_H1_VP8_SWREG68_VP8_BF_0_MASK         (0x3FFU)
#define VPU_H1_VP8_SWREG68_VP8_BF_0_SHIFT        (0U)
/*! BF_0 - VP8 intra 4x4 mode 4 penalty */
#define VPU_H1_VP8_SWREG68_VP8_BF_0(x)           (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG68_VP8_BF_0_SHIFT)) & VPU_H1_VP8_SWREG68_VP8_BF_0_MASK)

#define VPU_H1_VP8_SWREG68_VP8_BF_12_MASK        (0x3FF000U)
#define VPU_H1_VP8_SWREG68_VP8_BF_12_SHIFT       (12U)
/*! BF_12 - VP8 intra 4x4 mode 5 penalty */
#define VPU_H1_VP8_SWREG68_VP8_BF_12(x)          (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG68_VP8_BF_12_SHIFT)) & VPU_H1_VP8_SWREG68_VP8_BF_12_MASK)
/*! @} */

/*! @name SWREG69_VP8 - VPU H1 Register 69 - for VP8 */
/*! @{ */

#define VPU_H1_VP8_SWREG69_VP8_BF_0_MASK         (0x3FFU)
#define VPU_H1_VP8_SWREG69_VP8_BF_0_SHIFT        (0U)
/*! BF_0 - VP8 intra 4x4 mode 6 penalty */
#define VPU_H1_VP8_SWREG69_VP8_BF_0(x)           (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG69_VP8_BF_0_SHIFT)) & VPU_H1_VP8_SWREG69_VP8_BF_0_MASK)

#define VPU_H1_VP8_SWREG69_VP8_BF_12_MASK        (0x3FF000U)
#define VPU_H1_VP8_SWREG69_VP8_BF_12_SHIFT       (12U)
/*! BF_12 - VP8 intra 4x4 mode 7 penalty */
#define VPU_H1_VP8_SWREG69_VP8_BF_12(x)          (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG69_VP8_BF_12_SHIFT)) & VPU_H1_VP8_SWREG69_VP8_BF_12_MASK)
/*! @} */

/*! @name SWREG70_VP8 - VPU H1 Register 70 - for VP8 */
/*! @{ */

#define VPU_H1_VP8_SWREG70_VP8_BF_0_MASK         (0x3FFU)
#define VPU_H1_VP8_SWREG70_VP8_BF_0_SHIFT        (0U)
/*! BF_0 - VP8 intra 4x4 mode 8 penalty */
#define VPU_H1_VP8_SWREG70_VP8_BF_0(x)           (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG70_VP8_BF_0_SHIFT)) & VPU_H1_VP8_SWREG70_VP8_BF_0_MASK)

#define VPU_H1_VP8_SWREG70_VP8_BF_12_MASK        (0x3FF000U)
#define VPU_H1_VP8_SWREG70_VP8_BF_12_SHIFT       (12U)
/*! BF_12 - VP8 intra 4x4 mode 9 penalty */
#define VPU_H1_VP8_SWREG70_VP8_BF_12(x)          (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG70_VP8_BF_12_SHIFT)) & VPU_H1_VP8_SWREG70_VP8_BF_12_MASK)
/*! @} */

/*! @name SWREG71_VP8 - VPU H1 Register 71 - for VP8 */
/*! @{ */

#define VPU_H1_VP8_SWREG71_VP8_BF_0_MASK         (0xFFFFFFFFU)
#define VPU_H1_VP8_SWREG71_VP8_BF_0_SHIFT        (0U)
/*! BF_0 - Base address for VP8 segmentation map, segmentId 2-bits/macroblock */
#define VPU_H1_VP8_SWREG71_VP8_BF_0(x)           (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG71_VP8_BF_0_SHIFT)) & VPU_H1_VP8_SWREG71_VP8_BF_0_MASK)
/*! @} */

/*! @name SWREG72_VP8 - VPU H1 Register 72 - for VP8 */
/*! @{ */

#define VPU_H1_VP8_SWREG72_VP8_BF_0_MASK         (0x3FFFU)
#define VPU_H1_VP8_SWREG72_VP8_BF_0_SHIFT        (0U)
/*! BF_0 - VP8 segment1 qpY1QuantDc 14b */
#define VPU_H1_VP8_SWREG72_VP8_BF_0(x)           (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG72_VP8_BF_0_SHIFT)) & VPU_H1_VP8_SWREG72_VP8_BF_0_MASK)

#define VPU_H1_VP8_SWREG72_VP8_BF_14_MASK        (0x7FC000U)
#define VPU_H1_VP8_SWREG72_VP8_BF_14_SHIFT       (14U)
/*! BF_14 - VP8 segment1 qpY1ZbinDc 9b */
#define VPU_H1_VP8_SWREG72_VP8_BF_14(x)          (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG72_VP8_BF_14_SHIFT)) & VPU_H1_VP8_SWREG72_VP8_BF_14_MASK)

#define VPU_H1_VP8_SWREG72_VP8_BF_23_MASK        (0x7F800000U)
#define VPU_H1_VP8_SWREG72_VP8_BF_23_SHIFT       (23U)
/*! BF_23 - VP8 segment1 qpY1RoundDc 8b */
#define VPU_H1_VP8_SWREG72_VP8_BF_23(x)          (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG72_VP8_BF_23_SHIFT)) & VPU_H1_VP8_SWREG72_VP8_BF_23_MASK)
/*! @} */

/*! @name SWREG73_VP8 - VPU H1 Register 73 - for VP8 */
/*! @{ */

#define VPU_H1_VP8_SWREG73_VP8_BF_0_MASK         (0x3FFFU)
#define VPU_H1_VP8_SWREG73_VP8_BF_0_SHIFT        (0U)
/*! BF_0 - VP8 segment1 qpY1QuantAc 14b */
#define VPU_H1_VP8_SWREG73_VP8_BF_0(x)           (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG73_VP8_BF_0_SHIFT)) & VPU_H1_VP8_SWREG73_VP8_BF_0_MASK)

#define VPU_H1_VP8_SWREG73_VP8_BF_14_MASK        (0x7FC000U)
#define VPU_H1_VP8_SWREG73_VP8_BF_14_SHIFT       (14U)
/*! BF_14 - VP8 segment1 qpY1ZbinAc 9b */
#define VPU_H1_VP8_SWREG73_VP8_BF_14(x)          (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG73_VP8_BF_14_SHIFT)) & VPU_H1_VP8_SWREG73_VP8_BF_14_MASK)

#define VPU_H1_VP8_SWREG73_VP8_BF_23_MASK        (0x7F800000U)
#define VPU_H1_VP8_SWREG73_VP8_BF_23_SHIFT       (23U)
/*! BF_23 - VP8 segment1 qpY1RoundAc 8b */
#define VPU_H1_VP8_SWREG73_VP8_BF_23(x)          (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG73_VP8_BF_23_SHIFT)) & VPU_H1_VP8_SWREG73_VP8_BF_23_MASK)
/*! @} */

/*! @name SWREG74_VP8 - VPU H1 Register 74 - for VP8 */
/*! @{ */

#define VPU_H1_VP8_SWREG74_VP8_BF_0_MASK         (0x3FFFU)
#define VPU_H1_VP8_SWREG74_VP8_BF_0_SHIFT        (0U)
/*! BF_0 - VP8 segment1 qpY2QuantDc 14b */
#define VPU_H1_VP8_SWREG74_VP8_BF_0(x)           (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG74_VP8_BF_0_SHIFT)) & VPU_H1_VP8_SWREG74_VP8_BF_0_MASK)

#define VPU_H1_VP8_SWREG74_VP8_BF_14_MASK        (0x7FC000U)
#define VPU_H1_VP8_SWREG74_VP8_BF_14_SHIFT       (14U)
/*! BF_14 - VP8 segment1 qpY2ZbinDc 9b */
#define VPU_H1_VP8_SWREG74_VP8_BF_14(x)          (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG74_VP8_BF_14_SHIFT)) & VPU_H1_VP8_SWREG74_VP8_BF_14_MASK)

#define VPU_H1_VP8_SWREG74_VP8_BF_23_MASK        (0x7F800000U)
#define VPU_H1_VP8_SWREG74_VP8_BF_23_SHIFT       (23U)
/*! BF_23 - VP8 segment1 qpY2RoundDc 8b */
#define VPU_H1_VP8_SWREG74_VP8_BF_23(x)          (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG74_VP8_BF_23_SHIFT)) & VPU_H1_VP8_SWREG74_VP8_BF_23_MASK)
/*! @} */

/*! @name SWREG75_VP8 - VPU H1 Register 75 - for VP8 */
/*! @{ */

#define VPU_H1_VP8_SWREG75_VP8_BF_0_MASK         (0x3FFFU)
#define VPU_H1_VP8_SWREG75_VP8_BF_0_SHIFT        (0U)
/*! BF_0 - VP8 segment1 qpY2QuantAc 14b */
#define VPU_H1_VP8_SWREG75_VP8_BF_0(x)           (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG75_VP8_BF_0_SHIFT)) & VPU_H1_VP8_SWREG75_VP8_BF_0_MASK)

#define VPU_H1_VP8_SWREG75_VP8_BF_14_MASK        (0x7FC000U)
#define VPU_H1_VP8_SWREG75_VP8_BF_14_SHIFT       (14U)
/*! BF_14 - VP8 segment1 qpY2ZbinAc 9b */
#define VPU_H1_VP8_SWREG75_VP8_BF_14(x)          (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG75_VP8_BF_14_SHIFT)) & VPU_H1_VP8_SWREG75_VP8_BF_14_MASK)

#define VPU_H1_VP8_SWREG75_VP8_BF_23_MASK        (0x7F800000U)
#define VPU_H1_VP8_SWREG75_VP8_BF_23_SHIFT       (23U)
/*! BF_23 - VP8 segment1 qpY2RoundAc 8b */
#define VPU_H1_VP8_SWREG75_VP8_BF_23(x)          (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG75_VP8_BF_23_SHIFT)) & VPU_H1_VP8_SWREG75_VP8_BF_23_MASK)
/*! @} */

/*! @name SWREG76_VP8 - VPU H1 Register 76 - for VP8 */
/*! @{ */

#define VPU_H1_VP8_SWREG76_VP8_BF_0_MASK         (0x3FFFU)
#define VPU_H1_VP8_SWREG76_VP8_BF_0_SHIFT        (0U)
/*! BF_0 - VP8 segment1 qpChQuantDc 14b */
#define VPU_H1_VP8_SWREG76_VP8_BF_0(x)           (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG76_VP8_BF_0_SHIFT)) & VPU_H1_VP8_SWREG76_VP8_BF_0_MASK)

#define VPU_H1_VP8_SWREG76_VP8_BF_14_MASK        (0x7FC000U)
#define VPU_H1_VP8_SWREG76_VP8_BF_14_SHIFT       (14U)
/*! BF_14 - VP8 segment1 qpChZbinDc 9b */
#define VPU_H1_VP8_SWREG76_VP8_BF_14(x)          (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG76_VP8_BF_14_SHIFT)) & VPU_H1_VP8_SWREG76_VP8_BF_14_MASK)

#define VPU_H1_VP8_SWREG76_VP8_BF_23_MASK        (0x7F800000U)
#define VPU_H1_VP8_SWREG76_VP8_BF_23_SHIFT       (23U)
/*! BF_23 - VP8 segment1 qpChRoundDc 8b */
#define VPU_H1_VP8_SWREG76_VP8_BF_23(x)          (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG76_VP8_BF_23_SHIFT)) & VPU_H1_VP8_SWREG76_VP8_BF_23_MASK)
/*! @} */

/*! @name SWREG77_VP8 - VPU H1 Register 77 - for VP8 */
/*! @{ */

#define VPU_H1_VP8_SWREG77_VP8_BF_0_MASK         (0x3FFFU)
#define VPU_H1_VP8_SWREG77_VP8_BF_0_SHIFT        (0U)
/*! BF_0 - VP8 segment1 qpChQuantAc 14b */
#define VPU_H1_VP8_SWREG77_VP8_BF_0(x)           (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG77_VP8_BF_0_SHIFT)) & VPU_H1_VP8_SWREG77_VP8_BF_0_MASK)

#define VPU_H1_VP8_SWREG77_VP8_BF_14_MASK        (0x7FC000U)
#define VPU_H1_VP8_SWREG77_VP8_BF_14_SHIFT       (14U)
/*! BF_14 - VP8 segment1 qpChZbinAc 9b */
#define VPU_H1_VP8_SWREG77_VP8_BF_14(x)          (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG77_VP8_BF_14_SHIFT)) & VPU_H1_VP8_SWREG77_VP8_BF_14_MASK)

#define VPU_H1_VP8_SWREG77_VP8_BF_23_MASK        (0x7F800000U)
#define VPU_H1_VP8_SWREG77_VP8_BF_23_SHIFT       (23U)
/*! BF_23 - VP8 segment1 qpChRoundAc 8b */
#define VPU_H1_VP8_SWREG77_VP8_BF_23(x)          (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG77_VP8_BF_23_SHIFT)) & VPU_H1_VP8_SWREG77_VP8_BF_23_MASK)
/*! @} */

/*! @name SWREG78_VP8 - VPU H1 Register 78 - for VP8 */
/*! @{ */

#define VPU_H1_VP8_SWREG78_VP8_BF_0_MASK         (0xFFU)
#define VPU_H1_VP8_SWREG78_VP8_BF_0_SHIFT        (0U)
/*! BF_0 - VP8 segment1 qpY1DequantDc 8b */
#define VPU_H1_VP8_SWREG78_VP8_BF_0(x)           (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG78_VP8_BF_0_SHIFT)) & VPU_H1_VP8_SWREG78_VP8_BF_0_MASK)

#define VPU_H1_VP8_SWREG78_VP8_BF_8_MASK         (0x1FF00U)
#define VPU_H1_VP8_SWREG78_VP8_BF_8_SHIFT        (8U)
/*! BF_8 - VP8 segment1 qpY1DequantAc 9b */
#define VPU_H1_VP8_SWREG78_VP8_BF_8(x)           (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG78_VP8_BF_8_SHIFT)) & VPU_H1_VP8_SWREG78_VP8_BF_8_MASK)

#define VPU_H1_VP8_SWREG78_VP8_BF_17_MASK        (0x3FE0000U)
#define VPU_H1_VP8_SWREG78_VP8_BF_17_SHIFT       (17U)
/*! BF_17 - VP8 segment1 qpY2DequantDc 9b */
#define VPU_H1_VP8_SWREG78_VP8_BF_17(x)          (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG78_VP8_BF_17_SHIFT)) & VPU_H1_VP8_SWREG78_VP8_BF_17_MASK)
/*! @} */

/*! @name SWREG79_VP8 - VPU H1 Register 79 - for VP8 */
/*! @{ */

#define VPU_H1_VP8_SWREG79_VP8_BF_0_MASK         (0x1FFU)
#define VPU_H1_VP8_SWREG79_VP8_BF_0_SHIFT        (0U)
/*! BF_0 - VP8 segment1 qpY2DequantAc 9b */
#define VPU_H1_VP8_SWREG79_VP8_BF_0(x)           (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG79_VP8_BF_0_SHIFT)) & VPU_H1_VP8_SWREG79_VP8_BF_0_MASK)

#define VPU_H1_VP8_SWREG79_VP8_BF_9_MASK         (0x1FE00U)
#define VPU_H1_VP8_SWREG79_VP8_BF_9_SHIFT        (9U)
/*! BF_9 - VP8 segment1 qpChDequantDc 8b */
#define VPU_H1_VP8_SWREG79_VP8_BF_9(x)           (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG79_VP8_BF_9_SHIFT)) & VPU_H1_VP8_SWREG79_VP8_BF_9_MASK)

#define VPU_H1_VP8_SWREG79_VP8_BF_17_MASK        (0x3FE0000U)
#define VPU_H1_VP8_SWREG79_VP8_BF_17_SHIFT       (17U)
/*! BF_17 - VP8 segment1 qpChDequantAc 9b */
#define VPU_H1_VP8_SWREG79_VP8_BF_17(x)          (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG79_VP8_BF_17_SHIFT)) & VPU_H1_VP8_SWREG79_VP8_BF_17_MASK)

#define VPU_H1_VP8_SWREG79_VP8_BF_26_MASK        (0xFC000000U)
#define VPU_H1_VP8_SWREG79_VP8_BF_26_SHIFT       (26U)
/*! BF_26 - VP8 segment1 filter level 6b */
#define VPU_H1_VP8_SWREG79_VP8_BF_26(x)          (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG79_VP8_BF_26_SHIFT)) & VPU_H1_VP8_SWREG79_VP8_BF_26_MASK)
/*! @} */

/*! @name SWREG80_VP8 - VPU H1 Register 80 - for VP8 */
/*! @{ */

#define VPU_H1_VP8_SWREG80_VP8_BF_0_MASK         (0x3FFFU)
#define VPU_H1_VP8_SWREG80_VP8_BF_0_SHIFT        (0U)
/*! BF_0 - VP8 segment2 qpY1QuantDc 14b */
#define VPU_H1_VP8_SWREG80_VP8_BF_0(x)           (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG80_VP8_BF_0_SHIFT)) & VPU_H1_VP8_SWREG80_VP8_BF_0_MASK)

#define VPU_H1_VP8_SWREG80_VP8_BF_14_MASK        (0x7FC000U)
#define VPU_H1_VP8_SWREG80_VP8_BF_14_SHIFT       (14U)
/*! BF_14 - VP8 segment2 qpY1ZbinDc 9b */
#define VPU_H1_VP8_SWREG80_VP8_BF_14(x)          (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG80_VP8_BF_14_SHIFT)) & VPU_H1_VP8_SWREG80_VP8_BF_14_MASK)

#define VPU_H1_VP8_SWREG80_VP8_BF_23_MASK        (0x7F800000U)
#define VPU_H1_VP8_SWREG80_VP8_BF_23_SHIFT       (23U)
/*! BF_23 - VP8 segment2 qpY1RoundDc 8b */
#define VPU_H1_VP8_SWREG80_VP8_BF_23(x)          (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG80_VP8_BF_23_SHIFT)) & VPU_H1_VP8_SWREG80_VP8_BF_23_MASK)
/*! @} */

/*! @name SWREG81_VP8 - VPU H1 Register 81 - for VP8 */
/*! @{ */

#define VPU_H1_VP8_SWREG81_VP8_BF_0_MASK         (0x3FFFU)
#define VPU_H1_VP8_SWREG81_VP8_BF_0_SHIFT        (0U)
/*! BF_0 - VP8 segment2 qpY1QuantAc 14b */
#define VPU_H1_VP8_SWREG81_VP8_BF_0(x)           (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG81_VP8_BF_0_SHIFT)) & VPU_H1_VP8_SWREG81_VP8_BF_0_MASK)

#define VPU_H1_VP8_SWREG81_VP8_BF_14_MASK        (0x7FC000U)
#define VPU_H1_VP8_SWREG81_VP8_BF_14_SHIFT       (14U)
/*! BF_14 - VP8 segment2 qpY1ZbinAc 9b */
#define VPU_H1_VP8_SWREG81_VP8_BF_14(x)          (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG81_VP8_BF_14_SHIFT)) & VPU_H1_VP8_SWREG81_VP8_BF_14_MASK)

#define VPU_H1_VP8_SWREG81_VP8_BF_23_MASK        (0x7F800000U)
#define VPU_H1_VP8_SWREG81_VP8_BF_23_SHIFT       (23U)
/*! BF_23 - VP8 segment2 qpY1RoundAc 8b */
#define VPU_H1_VP8_SWREG81_VP8_BF_23(x)          (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG81_VP8_BF_23_SHIFT)) & VPU_H1_VP8_SWREG81_VP8_BF_23_MASK)
/*! @} */

/*! @name SWREG82_VP8 - VPU H1 Register 82 - for VP8 */
/*! @{ */

#define VPU_H1_VP8_SWREG82_VP8_BF_0_MASK         (0x3FFFU)
#define VPU_H1_VP8_SWREG82_VP8_BF_0_SHIFT        (0U)
/*! BF_0 - VP8 segment2 qpY2QuantDc 14b */
#define VPU_H1_VP8_SWREG82_VP8_BF_0(x)           (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG82_VP8_BF_0_SHIFT)) & VPU_H1_VP8_SWREG82_VP8_BF_0_MASK)

#define VPU_H1_VP8_SWREG82_VP8_BF_14_MASK        (0x7FC000U)
#define VPU_H1_VP8_SWREG82_VP8_BF_14_SHIFT       (14U)
/*! BF_14 - VP8 segment2 qpY2ZbinDc 9b */
#define VPU_H1_VP8_SWREG82_VP8_BF_14(x)          (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG82_VP8_BF_14_SHIFT)) & VPU_H1_VP8_SWREG82_VP8_BF_14_MASK)

#define VPU_H1_VP8_SWREG82_VP8_BF_23_MASK        (0x7F800000U)
#define VPU_H1_VP8_SWREG82_VP8_BF_23_SHIFT       (23U)
/*! BF_23 - VP8 segment2 qpY2RoundDc 8b */
#define VPU_H1_VP8_SWREG82_VP8_BF_23(x)          (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG82_VP8_BF_23_SHIFT)) & VPU_H1_VP8_SWREG82_VP8_BF_23_MASK)
/*! @} */

/*! @name SWREG83_VP8 - VPU H1 Register 83 - for VP8 */
/*! @{ */

#define VPU_H1_VP8_SWREG83_VP8_BF_0_MASK         (0x3FFFU)
#define VPU_H1_VP8_SWREG83_VP8_BF_0_SHIFT        (0U)
/*! BF_0 - VP8 segment2 qpY2QuantAc 14b */
#define VPU_H1_VP8_SWREG83_VP8_BF_0(x)           (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG83_VP8_BF_0_SHIFT)) & VPU_H1_VP8_SWREG83_VP8_BF_0_MASK)

#define VPU_H1_VP8_SWREG83_VP8_BF_14_MASK        (0x7FC000U)
#define VPU_H1_VP8_SWREG83_VP8_BF_14_SHIFT       (14U)
/*! BF_14 - VP8 segment2 qpY2ZbinAc 9b */
#define VPU_H1_VP8_SWREG83_VP8_BF_14(x)          (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG83_VP8_BF_14_SHIFT)) & VPU_H1_VP8_SWREG83_VP8_BF_14_MASK)

#define VPU_H1_VP8_SWREG83_VP8_BF_23_MASK        (0x7F800000U)
#define VPU_H1_VP8_SWREG83_VP8_BF_23_SHIFT       (23U)
/*! BF_23 - VP8 segment2 qpY2RoundAc 8b */
#define VPU_H1_VP8_SWREG83_VP8_BF_23(x)          (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG83_VP8_BF_23_SHIFT)) & VPU_H1_VP8_SWREG83_VP8_BF_23_MASK)
/*! @} */

/*! @name SWREG84_VP8 - VPU H1 Register 84 - for VP8 */
/*! @{ */

#define VPU_H1_VP8_SWREG84_VP8_BF_0_MASK         (0x3FFFU)
#define VPU_H1_VP8_SWREG84_VP8_BF_0_SHIFT        (0U)
/*! BF_0 - VP8 segment2 qpChQuantDc 14b */
#define VPU_H1_VP8_SWREG84_VP8_BF_0(x)           (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG84_VP8_BF_0_SHIFT)) & VPU_H1_VP8_SWREG84_VP8_BF_0_MASK)

#define VPU_H1_VP8_SWREG84_VP8_BF_14_MASK        (0x7FC000U)
#define VPU_H1_VP8_SWREG84_VP8_BF_14_SHIFT       (14U)
/*! BF_14 - VP8 segment2 qpChZbinDc 9b */
#define VPU_H1_VP8_SWREG84_VP8_BF_14(x)          (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG84_VP8_BF_14_SHIFT)) & VPU_H1_VP8_SWREG84_VP8_BF_14_MASK)

#define VPU_H1_VP8_SWREG84_VP8_BF_23_MASK        (0x7F800000U)
#define VPU_H1_VP8_SWREG84_VP8_BF_23_SHIFT       (23U)
/*! BF_23 - VP8 segment2 qpChRoundDc 8b */
#define VPU_H1_VP8_SWREG84_VP8_BF_23(x)          (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG84_VP8_BF_23_SHIFT)) & VPU_H1_VP8_SWREG84_VP8_BF_23_MASK)
/*! @} */

/*! @name SWREG85_VP8 - VPU H1 Register 85 - for VP8 */
/*! @{ */

#define VPU_H1_VP8_SWREG85_VP8_BF_0_MASK         (0x3FFFU)
#define VPU_H1_VP8_SWREG85_VP8_BF_0_SHIFT        (0U)
/*! BF_0 - VP8 segment2 qpChQuantAc 14b */
#define VPU_H1_VP8_SWREG85_VP8_BF_0(x)           (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG85_VP8_BF_0_SHIFT)) & VPU_H1_VP8_SWREG85_VP8_BF_0_MASK)

#define VPU_H1_VP8_SWREG85_VP8_BF_14_MASK        (0x7FC000U)
#define VPU_H1_VP8_SWREG85_VP8_BF_14_SHIFT       (14U)
/*! BF_14 - VP8 segment2 qpChZbinAc 9b */
#define VPU_H1_VP8_SWREG85_VP8_BF_14(x)          (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG85_VP8_BF_14_SHIFT)) & VPU_H1_VP8_SWREG85_VP8_BF_14_MASK)

#define VPU_H1_VP8_SWREG85_VP8_BF_23_MASK        (0x7F800000U)
#define VPU_H1_VP8_SWREG85_VP8_BF_23_SHIFT       (23U)
/*! BF_23 - VP8 segment2 qpChRoundAc 8b */
#define VPU_H1_VP8_SWREG85_VP8_BF_23(x)          (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG85_VP8_BF_23_SHIFT)) & VPU_H1_VP8_SWREG85_VP8_BF_23_MASK)
/*! @} */

/*! @name SWREG86_VP8 - VPU H1 Register 86 - for VP8 */
/*! @{ */

#define VPU_H1_VP8_SWREG86_VP8_BF_0_MASK         (0xFFU)
#define VPU_H1_VP8_SWREG86_VP8_BF_0_SHIFT        (0U)
/*! BF_0 - VP8 segment2 qpY1DequantDc 8b */
#define VPU_H1_VP8_SWREG86_VP8_BF_0(x)           (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG86_VP8_BF_0_SHIFT)) & VPU_H1_VP8_SWREG86_VP8_BF_0_MASK)

#define VPU_H1_VP8_SWREG86_VP8_BF_8_MASK         (0x1FF00U)
#define VPU_H1_VP8_SWREG86_VP8_BF_8_SHIFT        (8U)
/*! BF_8 - VP8 segment2 qpY1DequantAc 9b */
#define VPU_H1_VP8_SWREG86_VP8_BF_8(x)           (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG86_VP8_BF_8_SHIFT)) & VPU_H1_VP8_SWREG86_VP8_BF_8_MASK)

#define VPU_H1_VP8_SWREG86_VP8_BF_17_MASK        (0x3FE0000U)
#define VPU_H1_VP8_SWREG86_VP8_BF_17_SHIFT       (17U)
/*! BF_17 - VP8 segment2 qpY2DequantDc 9b */
#define VPU_H1_VP8_SWREG86_VP8_BF_17(x)          (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG86_VP8_BF_17_SHIFT)) & VPU_H1_VP8_SWREG86_VP8_BF_17_MASK)
/*! @} */

/*! @name SWREG87_VP8 - VPU H1 Register 87 - for VP8 */
/*! @{ */

#define VPU_H1_VP8_SWREG87_VP8_BF_0_MASK         (0x1FFU)
#define VPU_H1_VP8_SWREG87_VP8_BF_0_SHIFT        (0U)
/*! BF_0 - VP8 segment2 qpY2DequantAc 9b */
#define VPU_H1_VP8_SWREG87_VP8_BF_0(x)           (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG87_VP8_BF_0_SHIFT)) & VPU_H1_VP8_SWREG87_VP8_BF_0_MASK)

#define VPU_H1_VP8_SWREG87_VP8_BF_9_MASK         (0x1FE00U)
#define VPU_H1_VP8_SWREG87_VP8_BF_9_SHIFT        (9U)
/*! BF_9 - VP8 segment2 qpChDequantDc 8b */
#define VPU_H1_VP8_SWREG87_VP8_BF_9(x)           (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG87_VP8_BF_9_SHIFT)) & VPU_H1_VP8_SWREG87_VP8_BF_9_MASK)

#define VPU_H1_VP8_SWREG87_VP8_BF_17_MASK        (0x3FE0000U)
#define VPU_H1_VP8_SWREG87_VP8_BF_17_SHIFT       (17U)
/*! BF_17 - VP8 segment2 qpChDequantAc 9b */
#define VPU_H1_VP8_SWREG87_VP8_BF_17(x)          (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG87_VP8_BF_17_SHIFT)) & VPU_H1_VP8_SWREG87_VP8_BF_17_MASK)

#define VPU_H1_VP8_SWREG87_VP8_BF_26_MASK        (0xFC000000U)
#define VPU_H1_VP8_SWREG87_VP8_BF_26_SHIFT       (26U)
/*! BF_26 - VP8 segment2 filter level 6b */
#define VPU_H1_VP8_SWREG87_VP8_BF_26(x)          (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG87_VP8_BF_26_SHIFT)) & VPU_H1_VP8_SWREG87_VP8_BF_26_MASK)
/*! @} */

/*! @name SWREG88_VP8 - VPU H1 Register 88 - for VP8 */
/*! @{ */

#define VPU_H1_VP8_SWREG88_VP8_BF_0_MASK         (0x3FFFU)
#define VPU_H1_VP8_SWREG88_VP8_BF_0_SHIFT        (0U)
/*! BF_0 - VP8 segment3 qpY1QuantDc 14b */
#define VPU_H1_VP8_SWREG88_VP8_BF_0(x)           (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG88_VP8_BF_0_SHIFT)) & VPU_H1_VP8_SWREG88_VP8_BF_0_MASK)

#define VPU_H1_VP8_SWREG88_VP8_BF_14_MASK        (0x7FC000U)
#define VPU_H1_VP8_SWREG88_VP8_BF_14_SHIFT       (14U)
/*! BF_14 - VP8 segment3 qpY1ZbinDc 9b */
#define VPU_H1_VP8_SWREG88_VP8_BF_14(x)          (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG88_VP8_BF_14_SHIFT)) & VPU_H1_VP8_SWREG88_VP8_BF_14_MASK)

#define VPU_H1_VP8_SWREG88_VP8_BF_23_MASK        (0x7F800000U)
#define VPU_H1_VP8_SWREG88_VP8_BF_23_SHIFT       (23U)
/*! BF_23 - VP8 segment3 qpY1RoundDc 8b */
#define VPU_H1_VP8_SWREG88_VP8_BF_23(x)          (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG88_VP8_BF_23_SHIFT)) & VPU_H1_VP8_SWREG88_VP8_BF_23_MASK)
/*! @} */

/*! @name SWREG89_VP8 - VPU H1 Register 89 - for VP8 */
/*! @{ */

#define VPU_H1_VP8_SWREG89_VP8_BF_0_MASK         (0x3FFFU)
#define VPU_H1_VP8_SWREG89_VP8_BF_0_SHIFT        (0U)
/*! BF_0 - VP8 segment3 qpY1QuantAc 14b */
#define VPU_H1_VP8_SWREG89_VP8_BF_0(x)           (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG89_VP8_BF_0_SHIFT)) & VPU_H1_VP8_SWREG89_VP8_BF_0_MASK)

#define VPU_H1_VP8_SWREG89_VP8_BF_14_MASK        (0x7FC000U)
#define VPU_H1_VP8_SWREG89_VP8_BF_14_SHIFT       (14U)
/*! BF_14 - VP8 segment3 qpY1ZbinAc 9b */
#define VPU_H1_VP8_SWREG89_VP8_BF_14(x)          (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG89_VP8_BF_14_SHIFT)) & VPU_H1_VP8_SWREG89_VP8_BF_14_MASK)

#define VPU_H1_VP8_SWREG89_VP8_BF_23_MASK        (0x7F800000U)
#define VPU_H1_VP8_SWREG89_VP8_BF_23_SHIFT       (23U)
/*! BF_23 - VP8 segment3 qpY1RoundAc 8b */
#define VPU_H1_VP8_SWREG89_VP8_BF_23(x)          (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG89_VP8_BF_23_SHIFT)) & VPU_H1_VP8_SWREG89_VP8_BF_23_MASK)
/*! @} */

/*! @name SWREG90_VP8 - VPU H1 Register 90 - for VP8 */
/*! @{ */

#define VPU_H1_VP8_SWREG90_VP8_BF_0_MASK         (0x3FFFU)
#define VPU_H1_VP8_SWREG90_VP8_BF_0_SHIFT        (0U)
/*! BF_0 - VP8 segment3 qpY2QuantDc 14b */
#define VPU_H1_VP8_SWREG90_VP8_BF_0(x)           (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG90_VP8_BF_0_SHIFT)) & VPU_H1_VP8_SWREG90_VP8_BF_0_MASK)

#define VPU_H1_VP8_SWREG90_VP8_BF_14_MASK        (0x7FC000U)
#define VPU_H1_VP8_SWREG90_VP8_BF_14_SHIFT       (14U)
/*! BF_14 - VP8 segment3 qpY2ZbinDc 9b */
#define VPU_H1_VP8_SWREG90_VP8_BF_14(x)          (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG90_VP8_BF_14_SHIFT)) & VPU_H1_VP8_SWREG90_VP8_BF_14_MASK)

#define VPU_H1_VP8_SWREG90_VP8_BF_23_MASK        (0x7F800000U)
#define VPU_H1_VP8_SWREG90_VP8_BF_23_SHIFT       (23U)
/*! BF_23 - VP8 segment3 qpY2RoundDc 8b */
#define VPU_H1_VP8_SWREG90_VP8_BF_23(x)          (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG90_VP8_BF_23_SHIFT)) & VPU_H1_VP8_SWREG90_VP8_BF_23_MASK)
/*! @} */

/*! @name SWREG91_VP8 - VPU H1 Register 91 - for VP8 */
/*! @{ */

#define VPU_H1_VP8_SWREG91_VP8_BF_0_MASK         (0x3FFFU)
#define VPU_H1_VP8_SWREG91_VP8_BF_0_SHIFT        (0U)
/*! BF_0 - VP8 segment3 qpY2QuantAc 14b */
#define VPU_H1_VP8_SWREG91_VP8_BF_0(x)           (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG91_VP8_BF_0_SHIFT)) & VPU_H1_VP8_SWREG91_VP8_BF_0_MASK)

#define VPU_H1_VP8_SWREG91_VP8_BF_14_MASK        (0x7FC000U)
#define VPU_H1_VP8_SWREG91_VP8_BF_14_SHIFT       (14U)
/*! BF_14 - VP8 segment3 qpY2ZbinAc 9b */
#define VPU_H1_VP8_SWREG91_VP8_BF_14(x)          (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG91_VP8_BF_14_SHIFT)) & VPU_H1_VP8_SWREG91_VP8_BF_14_MASK)

#define VPU_H1_VP8_SWREG91_VP8_BF_23_MASK        (0x7F800000U)
#define VPU_H1_VP8_SWREG91_VP8_BF_23_SHIFT       (23U)
/*! BF_23 - VP8 segment3 qpY2RoundAc 8b */
#define VPU_H1_VP8_SWREG91_VP8_BF_23(x)          (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG91_VP8_BF_23_SHIFT)) & VPU_H1_VP8_SWREG91_VP8_BF_23_MASK)
/*! @} */

/*! @name SWREG92_VP8 - VPU H1 Register 92 - for VP8 */
/*! @{ */

#define VPU_H1_VP8_SWREG92_VP8_BF_0_MASK         (0x3FFFU)
#define VPU_H1_VP8_SWREG92_VP8_BF_0_SHIFT        (0U)
/*! BF_0 - VP8 segment3 qpChQuantDc 14b */
#define VPU_H1_VP8_SWREG92_VP8_BF_0(x)           (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG92_VP8_BF_0_SHIFT)) & VPU_H1_VP8_SWREG92_VP8_BF_0_MASK)

#define VPU_H1_VP8_SWREG92_VP8_BF_14_MASK        (0x7FC000U)
#define VPU_H1_VP8_SWREG92_VP8_BF_14_SHIFT       (14U)
/*! BF_14 - VP8 segment3 qpChZbinDc 9b */
#define VPU_H1_VP8_SWREG92_VP8_BF_14(x)          (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG92_VP8_BF_14_SHIFT)) & VPU_H1_VP8_SWREG92_VP8_BF_14_MASK)

#define VPU_H1_VP8_SWREG92_VP8_BF_23_MASK        (0x7F800000U)
#define VPU_H1_VP8_SWREG92_VP8_BF_23_SHIFT       (23U)
/*! BF_23 - VP8 segment3 qpChRoundDc 8b */
#define VPU_H1_VP8_SWREG92_VP8_BF_23(x)          (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG92_VP8_BF_23_SHIFT)) & VPU_H1_VP8_SWREG92_VP8_BF_23_MASK)
/*! @} */

/*! @name SWREG93_VP8 - VPU H1 Register 93 - for VP8 */
/*! @{ */

#define VPU_H1_VP8_SWREG93_VP8_BF_0_MASK         (0x3FFFU)
#define VPU_H1_VP8_SWREG93_VP8_BF_0_SHIFT        (0U)
/*! BF_0 - VP8 segment3 qpChQuantAc 14b */
#define VPU_H1_VP8_SWREG93_VP8_BF_0(x)           (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG93_VP8_BF_0_SHIFT)) & VPU_H1_VP8_SWREG93_VP8_BF_0_MASK)

#define VPU_H1_VP8_SWREG93_VP8_BF_14_MASK        (0x7FC000U)
#define VPU_H1_VP8_SWREG93_VP8_BF_14_SHIFT       (14U)
/*! BF_14 - VP8 segment3 qpChZbinAc 9b */
#define VPU_H1_VP8_SWREG93_VP8_BF_14(x)          (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG93_VP8_BF_14_SHIFT)) & VPU_H1_VP8_SWREG93_VP8_BF_14_MASK)

#define VPU_H1_VP8_SWREG93_VP8_BF_23_MASK        (0x7F800000U)
#define VPU_H1_VP8_SWREG93_VP8_BF_23_SHIFT       (23U)
/*! BF_23 - VP8 segment3 qpChRoundAc 8b */
#define VPU_H1_VP8_SWREG93_VP8_BF_23(x)          (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG93_VP8_BF_23_SHIFT)) & VPU_H1_VP8_SWREG93_VP8_BF_23_MASK)
/*! @} */

/*! @name SWREG94_VP8 - VPU H1 Register 94 - for VP8 */
/*! @{ */

#define VPU_H1_VP8_SWREG94_VP8_BF_0_MASK         (0xFFU)
#define VPU_H1_VP8_SWREG94_VP8_BF_0_SHIFT        (0U)
/*! BF_0 - VP8 segment3 qpY1DequantDc 8b */
#define VPU_H1_VP8_SWREG94_VP8_BF_0(x)           (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG94_VP8_BF_0_SHIFT)) & VPU_H1_VP8_SWREG94_VP8_BF_0_MASK)

#define VPU_H1_VP8_SWREG94_VP8_BF_8_MASK         (0x1FF00U)
#define VPU_H1_VP8_SWREG94_VP8_BF_8_SHIFT        (8U)
/*! BF_8 - VP8 segment3 qpY1DequantAc 9b */
#define VPU_H1_VP8_SWREG94_VP8_BF_8(x)           (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG94_VP8_BF_8_SHIFT)) & VPU_H1_VP8_SWREG94_VP8_BF_8_MASK)

#define VPU_H1_VP8_SWREG94_VP8_BF_17_MASK        (0x3FE0000U)
#define VPU_H1_VP8_SWREG94_VP8_BF_17_SHIFT       (17U)
/*! BF_17 - VP8 segment3 qpY2DequantDc 9b */
#define VPU_H1_VP8_SWREG94_VP8_BF_17(x)          (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG94_VP8_BF_17_SHIFT)) & VPU_H1_VP8_SWREG94_VP8_BF_17_MASK)
/*! @} */

/*! @name SWREG95_VP8 - VPU H1 Register 95 - for VP8 */
/*! @{ */

#define VPU_H1_VP8_SWREG95_VP8_BF_0_MASK         (0x1FFU)
#define VPU_H1_VP8_SWREG95_VP8_BF_0_SHIFT        (0U)
/*! BF_0 - VP8 segment3 qpY2DequantAc 9b */
#define VPU_H1_VP8_SWREG95_VP8_BF_0(x)           (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG95_VP8_BF_0_SHIFT)) & VPU_H1_VP8_SWREG95_VP8_BF_0_MASK)

#define VPU_H1_VP8_SWREG95_VP8_BF_9_MASK         (0x1FE00U)
#define VPU_H1_VP8_SWREG95_VP8_BF_9_SHIFT        (9U)
/*! BF_9 - VP8 segment3 qpChDequantDc 8b */
#define VPU_H1_VP8_SWREG95_VP8_BF_9(x)           (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG95_VP8_BF_9_SHIFT)) & VPU_H1_VP8_SWREG95_VP8_BF_9_MASK)

#define VPU_H1_VP8_SWREG95_VP8_BF_17_MASK        (0x3FE0000U)
#define VPU_H1_VP8_SWREG95_VP8_BF_17_SHIFT       (17U)
/*! BF_17 - VP8 segment3 qpChDequantAc 9b */
#define VPU_H1_VP8_SWREG95_VP8_BF_17(x)          (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG95_VP8_BF_17_SHIFT)) & VPU_H1_VP8_SWREG95_VP8_BF_17_MASK)

#define VPU_H1_VP8_SWREG95_VP8_BF_26_MASK        (0xFC000000U)
#define VPU_H1_VP8_SWREG95_VP8_BF_26_SHIFT       (26U)
/*! BF_26 - VP8 segment3 filter level 6b */
#define VPU_H1_VP8_SWREG95_VP8_BF_26(x)          (((uint32_t)(((uint32_t)(x)) << VPU_H1_VP8_SWREG95_VP8_BF_26_SHIFT)) & VPU_H1_VP8_SWREG95_VP8_BF_26_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group VPU_H1_VP8_Register_Masks */


/*!
 * @}
 */ /* end of group VPU_H1_VP8_Peripheral_Access_Layer */


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


#endif  /* PERI_VPU_H1_VP8_H_ */

