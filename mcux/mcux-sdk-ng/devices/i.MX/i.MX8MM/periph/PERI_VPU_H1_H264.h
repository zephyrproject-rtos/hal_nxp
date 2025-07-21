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
**         CMSIS Peripheral Access Layer for VPU_H1_H264
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
 * @file PERI_VPU_H1_H264.h
 * @version 5.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for VPU_H1_H264
 *
 * CMSIS Peripheral Access Layer for VPU_H1_H264
 */

#if !defined(PERI_VPU_H1_H264_H_)
#define PERI_VPU_H1_H264_H_                      /**< Symbol preventing repeated inclusion */

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
   -- VPU_H1_H264 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VPU_H1_H264_Peripheral_Access_Layer VPU_H1_H264 Peripheral Access Layer
 * @{
 */

/** VPU_H1_H264 - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[64];
  __IO uint32_t SWREG16_H264;                      /**< VPU H1 Register 16 - for H.264, offset: 0x40 */
  __IO uint32_t SWREG17_H264;                      /**< VPU H1 Register 17 - for H.264, offset: 0x44 */
       uint8_t RESERVED_1[32];
  __IO uint32_t SWREG26_H264;                      /**< VPU H1 Register 26 - for H.264, offset: 0x68 */
  __IO uint32_t SWREG27_H264;                      /**< VPU H1 Register 27 - for H.264, offset: 0x6C */
  __IO uint32_t SWREG28_H264;                      /**< VPU H1 Register 28 - for H.264, offset: 0x70 */
  __IO uint32_t SWREG29_H264;                      /**< VPU H1 Register 29 - for H.264, offset: 0x74 */
  __IO uint32_t SWREG30_H264;                      /**< VPU H1 Register 30 - for H.264, offset: 0x78 */
  __IO uint32_t SWREG31_H264;                      /**< VPU H1 Register 31 - for H.264, offset: 0x7C */
  __IO uint32_t SWREG32_H264;                      /**< VPU H1 Register 32 - for H.264, offset: 0x80 */
  __IO uint32_t SWREG33_H264;                      /**< VPU H1 Register 33 - for H.264, offset: 0x84 */
  __IO uint32_t SWREG34_H264;                      /**< VPU H1 Register 34 - for H.264, offset: 0x88 */
  __IO uint32_t SWREG35_H264;                      /**< VPU H1 Register 35 - for H.264, offset: 0x8C */
  __IO uint32_t SWREG36_H264;                      /**< VPU H1 Register 36 - for H.264, offset: 0x90 */
       uint8_t RESERVED_2[84];
  __IO uint32_t SWREG58_H264;                      /**< VPU H1 Register 58 - for H.264, offset: 0xE8 */
  __IO uint32_t SWREG59_H264;                      /**< VPU H1 Register 59 - for H.264, offset: 0xEC */
} VPU_H1_H264_Type;

/* ----------------------------------------------------------------------------
   -- VPU_H1_H264 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VPU_H1_H264_Register_Masks VPU_H1_H264 Register Masks
 * @{
 */

/*! @name SWREG16_H264 - VPU H1 Register 16 - for H.264 */
/*! @{ */

#define VPU_H1_H264_SWREG16_H264_BF_0_MASK       (0x1U)
#define VPU_H1_H264_SWREG16_H264_BF_0_SHIFT      (0U)
/*! BF_0 - H.264 Constrained intra prediction enable. constIntraPred */
#define VPU_H1_H264_SWREG16_H264_BF_0(x)         (((uint32_t)(((uint32_t)(x)) << VPU_H1_H264_SWREG16_H264_BF_0_SHIFT)) & VPU_H1_H264_SWREG16_H264_BF_0_MASK)

#define VPU_H1_H264_SWREG16_H264_BF_1_MASK       (0x1EU)
#define VPU_H1_H264_SWREG16_H264_BF_1_SHIFT      (1U)
/*! BF_1 - H.264 IDR picture ID */
#define VPU_H1_H264_SWREG16_H264_BF_1(x)         (((uint32_t)(((uint32_t)(x)) << VPU_H1_H264_SWREG16_H264_BF_1_SHIFT)) & VPU_H1_H264_SWREG16_H264_BF_1_MASK)

#define VPU_H1_H264_SWREG16_H264_BF_13_MASK      (0x3E000U)
#define VPU_H1_H264_SWREG16_H264_BF_13_SHIFT     (13U)
/*! BF_13 - H.264 Chroma qp index offset [-12..12] */
#define VPU_H1_H264_SWREG16_H264_BF_13(x)        (((uint32_t)(((uint32_t)(x)) << VPU_H1_H264_SWREG16_H264_BF_13_SHIFT)) & VPU_H1_H264_SWREG16_H264_BF_13_MASK)

#define VPU_H1_H264_SWREG16_H264_BF_18_MASK      (0x3C0000U)
#define VPU_H1_H264_SWREG16_H264_BF_18_SHIFT     (18U)
/*! BF_18 - H.264 Slice filter beta offset div2 [-6..6] */
#define VPU_H1_H264_SWREG16_H264_BF_18(x)        (((uint32_t)(((uint32_t)(x)) << VPU_H1_H264_SWREG16_H264_BF_18_SHIFT)) & VPU_H1_H264_SWREG16_H264_BF_18_MASK)

#define VPU_H1_H264_SWREG16_H264_BF_22_MASK      (0x3C00000U)
#define VPU_H1_H264_SWREG16_H264_BF_22_SHIFT     (22U)
/*! BF_22 - H.264 Slice filter alpha c0 offset div2 [-6..6] */
#define VPU_H1_H264_SWREG16_H264_BF_22(x)        (((uint32_t)(((uint32_t)(x)) << VPU_H1_H264_SWREG16_H264_BF_22_SHIFT)) & VPU_H1_H264_SWREG16_H264_BF_22_MASK)

#define VPU_H1_H264_SWREG16_H264_BF_26_MASK      (0xFC000000U)
#define VPU_H1_H264_SWREG16_H264_BF_26_SHIFT     (26U)
/*! BF_26 - H.264 Pic init qp in PPS [0..51] */
#define VPU_H1_H264_SWREG16_H264_BF_26(x)        (((uint32_t)(((uint32_t)(x)) << VPU_H1_H264_SWREG16_H264_BF_26_SHIFT)) & VPU_H1_H264_SWREG16_H264_BF_26_MASK)
/*! @} */

/*! @name SWREG17_H264 - VPU H1 Register 17 - for H.264 */
/*! @{ */

#define VPU_H1_H264_SWREG17_H264_BF_0_MASK       (0xFFFFU)
#define VPU_H1_H264_SWREG17_H264_BF_0_SHIFT      (0U)
/*! BF_0 - H.264 Frame num */
#define VPU_H1_H264_SWREG17_H264_BF_0(x)         (((uint32_t)(((uint32_t)(x)) << VPU_H1_H264_SWREG17_H264_BF_0_SHIFT)) & VPU_H1_H264_SWREG17_H264_BF_0_MASK)

#define VPU_H1_H264_SWREG17_H264_BF_16_MASK      (0xFF0000U)
#define VPU_H1_H264_SWREG17_H264_BF_16_SHIFT     (16U)
/*! BF_16 - H.264 Intra prediction previous 4x4 mode favor */
#define VPU_H1_H264_SWREG17_H264_BF_16(x)        (((uint32_t)(((uint32_t)(x)) << VPU_H1_H264_SWREG17_H264_BF_16_SHIFT)) & VPU_H1_H264_SWREG17_H264_BF_16_MASK)

#define VPU_H1_H264_SWREG17_H264_BF_24_MASK      (0xFF000000U)
#define VPU_H1_H264_SWREG17_H264_BF_24_SHIFT     (24U)
/*! BF_24 - H.264 pic_parameter_set_id */
#define VPU_H1_H264_SWREG17_H264_BF_24(x)        (((uint32_t)(((uint32_t)(x)) << VPU_H1_H264_SWREG17_H264_BF_24_SHIFT)) & VPU_H1_H264_SWREG17_H264_BF_24_MASK)
/*! @} */

/*! @name SWREG26_H264 - VPU H1 Register 26 - for H.264 */
/*! @{ */

#define VPU_H1_H264_SWREG26_H264_BF_0_MASK       (0xFFFFFFFFU)
#define VPU_H1_H264_SWREG26_H264_BF_0_SHIFT      (0U)
/*! BF_0 - Intra slice bitmap for slices 64..95. LSB=slice64. MSB=slice95. 1=intra. */
#define VPU_H1_H264_SWREG26_H264_BF_0(x)         (((uint32_t)(((uint32_t)(x)) << VPU_H1_H264_SWREG26_H264_BF_0_SHIFT)) & VPU_H1_H264_SWREG26_H264_BF_0_MASK)
/*! @} */

/*! @name SWREG27_H264 - VPU H1 Register 27 - for H.264 */
/*! @{ */

#define VPU_H1_H264_SWREG27_H264_BF_0_MASK       (0x1FFFU)
#define VPU_H1_H264_SWREG27_H264_BF_0_SHIFT      (0U)
/*! BF_0 - H.264 Checkpoint distance (mb). 0=disabled [0..8191] */
#define VPU_H1_H264_SWREG27_H264_BF_0(x)         (((uint32_t)(((uint32_t)(x)) << VPU_H1_H264_SWREG27_H264_BF_0_SHIFT)) & VPU_H1_H264_SWREG27_H264_BF_0_MASK)

#define VPU_H1_H264_SWREG27_H264_BF_14_MASK      (0xFC000U)
#define VPU_H1_H264_SWREG27_H264_BF_14_SHIFT     (14U)
/*! BF_14 - H.264 Minimum QP. qpMin [0..51] */
#define VPU_H1_H264_SWREG27_H264_BF_14(x)        (((uint32_t)(((uint32_t)(x)) << VPU_H1_H264_SWREG27_H264_BF_14_SHIFT)) & VPU_H1_H264_SWREG27_H264_BF_14_MASK)

#define VPU_H1_H264_SWREG27_H264_BF_20_MASK      (0x3F00000U)
#define VPU_H1_H264_SWREG27_H264_BF_20_SHIFT     (20U)
/*! BF_20 - H.264 Maximum QP. qpMax [0..51] */
#define VPU_H1_H264_SWREG27_H264_BF_20(x)        (((uint32_t)(((uint32_t)(x)) << VPU_H1_H264_SWREG27_H264_BF_20_SHIFT)) & VPU_H1_H264_SWREG27_H264_BF_20_MASK)

#define VPU_H1_H264_SWREG27_H264_BF_26_MASK      (0xFC000000U)
#define VPU_H1_H264_SWREG27_H264_BF_26_SHIFT     (26U)
/*! BF_26 - H.264 Initial QP. qpLum [0..51] */
#define VPU_H1_H264_SWREG27_H264_BF_26(x)        (((uint32_t)(((uint32_t)(x)) << VPU_H1_H264_SWREG27_H264_BF_26_SHIFT)) & VPU_H1_H264_SWREG27_H264_BF_26_MASK)
/*! @} */

/*! @name SWREG28_H264 - VPU H1 Register 28 - for H.264 */
/*! @{ */

#define VPU_H1_H264_SWREG28_H264_BF_0_MASK       (0xFFFFU)
#define VPU_H1_H264_SWREG28_H264_BF_0_SHIFT      (0U)
/*! BF_0 - H.264 Checkpoint 2 word target/usage div32 [0..65535] */
#define VPU_H1_H264_SWREG28_H264_BF_0(x)         (((uint32_t)(((uint32_t)(x)) << VPU_H1_H264_SWREG28_H264_BF_0_SHIFT)) & VPU_H1_H264_SWREG28_H264_BF_0_MASK)

#define VPU_H1_H264_SWREG28_H264_BF_16_MASK      (0xFFFF0000U)
#define VPU_H1_H264_SWREG28_H264_BF_16_SHIFT     (16U)
/*! BF_16 - H.264 Checkpoint 1 word target/usage div32 [0..65535] */
#define VPU_H1_H264_SWREG28_H264_BF_16(x)        (((uint32_t)(((uint32_t)(x)) << VPU_H1_H264_SWREG28_H264_BF_16_SHIFT)) & VPU_H1_H264_SWREG28_H264_BF_16_MASK)
/*! @} */

/*! @name SWREG29_H264 - VPU H1 Register 29 - for H.264 */
/*! @{ */

#define VPU_H1_H264_SWREG29_H264_BF_0_MASK       (0xFFFFU)
#define VPU_H1_H264_SWREG29_H264_BF_0_SHIFT      (0U)
/*! BF_0 - H.264 Checkpoint 4 word target/usage div32 [0..65535] */
#define VPU_H1_H264_SWREG29_H264_BF_0(x)         (((uint32_t)(((uint32_t)(x)) << VPU_H1_H264_SWREG29_H264_BF_0_SHIFT)) & VPU_H1_H264_SWREG29_H264_BF_0_MASK)

#define VPU_H1_H264_SWREG29_H264_BF_16_MASK      (0xFFFF0000U)
#define VPU_H1_H264_SWREG29_H264_BF_16_SHIFT     (16U)
/*! BF_16 - H.264 Checkpoint 3 word target/usage div32 [0..65535] */
#define VPU_H1_H264_SWREG29_H264_BF_16(x)        (((uint32_t)(((uint32_t)(x)) << VPU_H1_H264_SWREG29_H264_BF_16_SHIFT)) & VPU_H1_H264_SWREG29_H264_BF_16_MASK)
/*! @} */

/*! @name SWREG30_H264 - VPU H1 Register 30 - for H.264 */
/*! @{ */

#define VPU_H1_H264_SWREG30_H264_BF_0_MASK       (0xFFFFU)
#define VPU_H1_H264_SWREG30_H264_BF_0_SHIFT      (0U)
/*! BF_0 - H.264 Checkpoint 6 word target/usage div32 [0..65535] */
#define VPU_H1_H264_SWREG30_H264_BF_0(x)         (((uint32_t)(((uint32_t)(x)) << VPU_H1_H264_SWREG30_H264_BF_0_SHIFT)) & VPU_H1_H264_SWREG30_H264_BF_0_MASK)

#define VPU_H1_H264_SWREG30_H264_BF_16_MASK      (0xFFFF0000U)
#define VPU_H1_H264_SWREG30_H264_BF_16_SHIFT     (16U)
/*! BF_16 - H.264 Checkpoint 5 word target/usage div32 [0..65535] */
#define VPU_H1_H264_SWREG30_H264_BF_16(x)        (((uint32_t)(((uint32_t)(x)) << VPU_H1_H264_SWREG30_H264_BF_16_SHIFT)) & VPU_H1_H264_SWREG30_H264_BF_16_MASK)
/*! @} */

/*! @name SWREG31_H264 - VPU H1 Register 31 - for H.264 */
/*! @{ */

#define VPU_H1_H264_SWREG31_H264_BF_0_MASK       (0xFFFFU)
#define VPU_H1_H264_SWREG31_H264_BF_0_SHIFT      (0U)
/*! BF_0 - H.264 Checkpoint 8 word target/usage div32 [0..65535] */
#define VPU_H1_H264_SWREG31_H264_BF_0(x)         (((uint32_t)(((uint32_t)(x)) << VPU_H1_H264_SWREG31_H264_BF_0_SHIFT)) & VPU_H1_H264_SWREG31_H264_BF_0_MASK)

#define VPU_H1_H264_SWREG31_H264_BF_16_MASK      (0xFFFF0000U)
#define VPU_H1_H264_SWREG31_H264_BF_16_SHIFT     (16U)
/*! BF_16 - H.264 Checkpoint 7 word target/usage div32 [0..65535] */
#define VPU_H1_H264_SWREG31_H264_BF_16(x)        (((uint32_t)(((uint32_t)(x)) << VPU_H1_H264_SWREG31_H264_BF_16_SHIFT)) & VPU_H1_H264_SWREG31_H264_BF_16_MASK)
/*! @} */

/*! @name SWREG32_H264 - VPU H1 Register 32 - for H.264 */
/*! @{ */

#define VPU_H1_H264_SWREG32_H264_BF_0_MASK       (0xFFFFU)
#define VPU_H1_H264_SWREG32_H264_BF_0_SHIFT      (0U)
/*! BF_0 - H.264 Checkpoint 10 word target/usage div32 [0..65535] */
#define VPU_H1_H264_SWREG32_H264_BF_0(x)         (((uint32_t)(((uint32_t)(x)) << VPU_H1_H264_SWREG32_H264_BF_0_SHIFT)) & VPU_H1_H264_SWREG32_H264_BF_0_MASK)

#define VPU_H1_H264_SWREG32_H264_BF_16_MASK      (0xFFFF0000U)
#define VPU_H1_H264_SWREG32_H264_BF_16_SHIFT     (16U)
/*! BF_16 - H.264 Checkpoint 9 word target/usage div32 [0..65535] */
#define VPU_H1_H264_SWREG32_H264_BF_16(x)        (((uint32_t)(((uint32_t)(x)) << VPU_H1_H264_SWREG32_H264_BF_16_SHIFT)) & VPU_H1_H264_SWREG32_H264_BF_16_MASK)
/*! @} */

/*! @name SWREG33_H264 - VPU H1 Register 33 - for H.264 */
/*! @{ */

#define VPU_H1_H264_SWREG33_H264_BF_0_MASK       (0xFFFFU)
#define VPU_H1_H264_SWREG33_H264_BF_0_SHIFT      (0U)
/*! BF_0 - H.264 Checkpoint word error 2 div4 [-32768..32767] */
#define VPU_H1_H264_SWREG33_H264_BF_0(x)         (((uint32_t)(((uint32_t)(x)) << VPU_H1_H264_SWREG33_H264_BF_0_SHIFT)) & VPU_H1_H264_SWREG33_H264_BF_0_MASK)

#define VPU_H1_H264_SWREG33_H264_BF_16_MASK      (0xFFFF0000U)
#define VPU_H1_H264_SWREG33_H264_BF_16_SHIFT     (16U)
/*! BF_16 - H.264 Checkpoint word error 1 div4 [-32768..32767] */
#define VPU_H1_H264_SWREG33_H264_BF_16(x)        (((uint32_t)(((uint32_t)(x)) << VPU_H1_H264_SWREG33_H264_BF_16_SHIFT)) & VPU_H1_H264_SWREG33_H264_BF_16_MASK)
/*! @} */

/*! @name SWREG34_H264 - VPU H1 Register 34 - for H.264 */
/*! @{ */

#define VPU_H1_H264_SWREG34_H264_BF_0_MASK       (0xFFFFU)
#define VPU_H1_H264_SWREG34_H264_BF_0_SHIFT      (0U)
/*! BF_0 - H.264 Checkpoint word error 4 div4 [-32768..32767] */
#define VPU_H1_H264_SWREG34_H264_BF_0(x)         (((uint32_t)(((uint32_t)(x)) << VPU_H1_H264_SWREG34_H264_BF_0_SHIFT)) & VPU_H1_H264_SWREG34_H264_BF_0_MASK)

#define VPU_H1_H264_SWREG34_H264_BF_16_MASK      (0xFFFF0000U)
#define VPU_H1_H264_SWREG34_H264_BF_16_SHIFT     (16U)
/*! BF_16 - H.264 Checkpoint word error 3 div4 [-32768..32767] */
#define VPU_H1_H264_SWREG34_H264_BF_16(x)        (((uint32_t)(((uint32_t)(x)) << VPU_H1_H264_SWREG34_H264_BF_16_SHIFT)) & VPU_H1_H264_SWREG34_H264_BF_16_MASK)
/*! @} */

/*! @name SWREG35_H264 - VPU H1 Register 35 - for H.264 */
/*! @{ */

#define VPU_H1_H264_SWREG35_H264_BF_0_MASK       (0xFFFFU)
#define VPU_H1_H264_SWREG35_H264_BF_0_SHIFT      (0U)
/*! BF_0 - H.264 Checkpoint word error 6 div4 [-32768..32767] */
#define VPU_H1_H264_SWREG35_H264_BF_0(x)         (((uint32_t)(((uint32_t)(x)) << VPU_H1_H264_SWREG35_H264_BF_0_SHIFT)) & VPU_H1_H264_SWREG35_H264_BF_0_MASK)

#define VPU_H1_H264_SWREG35_H264_BF_16_MASK      (0xFFFF0000U)
#define VPU_H1_H264_SWREG35_H264_BF_16_SHIFT     (16U)
/*! BF_16 - H.264 Checkpoint word error 5 div4 [-32768..32767] */
#define VPU_H1_H264_SWREG35_H264_BF_16(x)        (((uint32_t)(((uint32_t)(x)) << VPU_H1_H264_SWREG35_H264_BF_16_SHIFT)) & VPU_H1_H264_SWREG35_H264_BF_16_MASK)
/*! @} */

/*! @name SWREG36_H264 - VPU H1 Register 36 - for H.264 */
/*! @{ */

#define VPU_H1_H264_SWREG36_H264_BF_0_MASK       (0xFU)
#define VPU_H1_H264_SWREG36_H264_BF_0_SHIFT      (0U)
/*! BF_0 - H.264 Checkpoint delta QP 7 [-8..7] */
#define VPU_H1_H264_SWREG36_H264_BF_0(x)         (((uint32_t)(((uint32_t)(x)) << VPU_H1_H264_SWREG36_H264_BF_0_SHIFT)) & VPU_H1_H264_SWREG36_H264_BF_0_MASK)

#define VPU_H1_H264_SWREG36_H264_BF_4_MASK       (0xF0U)
#define VPU_H1_H264_SWREG36_H264_BF_4_SHIFT      (4U)
/*! BF_4 - H.264 Checkpoint delta QP 6 [-8..7] */
#define VPU_H1_H264_SWREG36_H264_BF_4(x)         (((uint32_t)(((uint32_t)(x)) << VPU_H1_H264_SWREG36_H264_BF_4_SHIFT)) & VPU_H1_H264_SWREG36_H264_BF_4_MASK)

#define VPU_H1_H264_SWREG36_H264_BF_8_MASK       (0xF00U)
#define VPU_H1_H264_SWREG36_H264_BF_8_SHIFT      (8U)
/*! BF_8 - H.264 Checkpoint delta QP 5 [-8..7] */
#define VPU_H1_H264_SWREG36_H264_BF_8(x)         (((uint32_t)(((uint32_t)(x)) << VPU_H1_H264_SWREG36_H264_BF_8_SHIFT)) & VPU_H1_H264_SWREG36_H264_BF_8_MASK)

#define VPU_H1_H264_SWREG36_H264_BF_12_MASK      (0xF000U)
#define VPU_H1_H264_SWREG36_H264_BF_12_SHIFT     (12U)
/*! BF_12 - H.264 Checkpoint delta QP 4 [-8..7] */
#define VPU_H1_H264_SWREG36_H264_BF_12(x)        (((uint32_t)(((uint32_t)(x)) << VPU_H1_H264_SWREG36_H264_BF_12_SHIFT)) & VPU_H1_H264_SWREG36_H264_BF_12_MASK)

#define VPU_H1_H264_SWREG36_H264_BF_16_MASK      (0xF0000U)
#define VPU_H1_H264_SWREG36_H264_BF_16_SHIFT     (16U)
/*! BF_16 - H.264 Checkpoint delta QP 3 [-8..7] */
#define VPU_H1_H264_SWREG36_H264_BF_16(x)        (((uint32_t)(((uint32_t)(x)) << VPU_H1_H264_SWREG36_H264_BF_16_SHIFT)) & VPU_H1_H264_SWREG36_H264_BF_16_MASK)

#define VPU_H1_H264_SWREG36_H264_BF_20_MASK      (0xF00000U)
#define VPU_H1_H264_SWREG36_H264_BF_20_SHIFT     (20U)
/*! BF_20 - H.264 Checkpoint delta QP 2 [-8..7] */
#define VPU_H1_H264_SWREG36_H264_BF_20(x)        (((uint32_t)(((uint32_t)(x)) << VPU_H1_H264_SWREG36_H264_BF_20_SHIFT)) & VPU_H1_H264_SWREG36_H264_BF_20_MASK)

#define VPU_H1_H264_SWREG36_H264_BF_24_MASK      (0xF000000U)
#define VPU_H1_H264_SWREG36_H264_BF_24_SHIFT     (24U)
/*! BF_24 - H.264 Checkpoint delta QP 1 [-8..7] */
#define VPU_H1_H264_SWREG36_H264_BF_24(x)        (((uint32_t)(((uint32_t)(x)) << VPU_H1_H264_SWREG36_H264_BF_24_SHIFT)) & VPU_H1_H264_SWREG36_H264_BF_24_MASK)
/*! @} */

/*! @name SWREG58_H264 - VPU H1 Register 58 - for H.264 */
/*! @{ */

#define VPU_H1_H264_SWREG58_H264_BF_0_MASK       (0xFFFFFFFFU)
#define VPU_H1_H264_SWREG58_H264_BF_0_SHIFT      (0U)
/*! BF_0 - Intra slice bitmap for slices 0..31. LSB=slice0. MSB=slice31. 1=intra. */
#define VPU_H1_H264_SWREG58_H264_BF_0(x)         (((uint32_t)(((uint32_t)(x)) << VPU_H1_H264_SWREG58_H264_BF_0_SHIFT)) & VPU_H1_H264_SWREG58_H264_BF_0_MASK)
/*! @} */

/*! @name SWREG59_H264 - VPU H1 Register 59 - for H.264 */
/*! @{ */

#define VPU_H1_H264_SWREG59_H264_BF_0_MASK       (0xFFFFFFFFU)
#define VPU_H1_H264_SWREG59_H264_BF_0_SHIFT      (0U)
/*! BF_0 - Intra slice bitmap for slices 32..63. LSB=slice32. MSB=slice63. 1=intra. */
#define VPU_H1_H264_SWREG59_H264_BF_0(x)         (((uint32_t)(((uint32_t)(x)) << VPU_H1_H264_SWREG59_H264_BF_0_SHIFT)) & VPU_H1_H264_SWREG59_H264_BF_0_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group VPU_H1_H264_Register_Masks */


/*!
 * @}
 */ /* end of group VPU_H1_H264_Peripheral_Access_Layer */


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


#endif  /* PERI_VPU_H1_H264_H_ */

