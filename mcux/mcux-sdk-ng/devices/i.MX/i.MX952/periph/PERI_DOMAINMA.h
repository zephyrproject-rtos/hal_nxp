/*
** ###################################################################
**     Processors:          MIMX95294AVTN_ca55
**                          MIMX95294AVTN_cm33
**                          MIMX95294AVTN_cm7
**                          MIMX95294AVYN_ca55
**                          MIMX95294AVYN_cm33
**                          MIMX95294AVYN_cm7
**                          MIMX95294AVZN_ca55
**                          MIMX95294AVZN_cm33
**                          MIMX95294AVZN_cm7
**                          MIMX95294CVTN_ca55
**                          MIMX95294CVTN_cm33
**                          MIMX95294CVTN_cm7
**                          MIMX95294CVYN_ca55
**                          MIMX95294CVYN_cm33
**                          MIMX95294CVYN_cm7
**                          MIMX95294CVZN_ca55
**                          MIMX95294CVZN_cm33
**                          MIMX95294CVZN_cm7
**                          MIMX95294DVTN_ca55
**                          MIMX95294DVTN_cm33
**                          MIMX95294DVTN_cm7
**                          MIMX95294DVYN_ca55
**                          MIMX95294DVYN_cm33
**                          MIMX95294DVYN_cm7
**                          MIMX95294DVZN_ca55
**                          MIMX95294DVZN_cm33
**                          MIMX95294DVZN_cm7
**                          MIMX95294XVTN_ca55
**                          MIMX95294XVTN_cm33
**                          MIMX95294XVTN_cm7
**                          MIMX95294XVYN_ca55
**                          MIMX95294XVYN_cm33
**                          MIMX95294XVYN_cm7
**                          MIMX95294XVZN_ca55
**                          MIMX95294XVZN_cm33
**                          MIMX95294XVZN_cm7
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250903
**
**     Abstract:
**         CMSIS Peripheral Access Layer for domainma
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2023-01-10)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_domainma.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for domainma
 *
 * CMSIS Peripheral Access Layer for domainma
 */

#if !defined(PERI_DOMAINMA_H_)
#define PERI_DOMAINMA_H_                         /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX95294AVTN_ca55) || defined(CPU_MIMX95294AVYN_ca55) || defined(CPU_MIMX95294AVZN_ca55) || defined(CPU_MIMX95294CVTN_ca55) || defined(CPU_MIMX95294CVYN_ca55) || defined(CPU_MIMX95294CVZN_ca55) || defined(CPU_MIMX95294DVTN_ca55) || defined(CPU_MIMX95294DVYN_ca55) || defined(CPU_MIMX95294DVZN_ca55) || defined(CPU_MIMX95294XVTN_ca55) || defined(CPU_MIMX95294XVYN_ca55) || defined(CPU_MIMX95294XVZN_ca55))
#include "MIMX95294_ca55_COMMON.h"
#elif (defined(CPU_MIMX95294AVTN_cm33) || defined(CPU_MIMX95294AVYN_cm33) || defined(CPU_MIMX95294AVZN_cm33) || defined(CPU_MIMX95294CVTN_cm33) || defined(CPU_MIMX95294CVYN_cm33) || defined(CPU_MIMX95294CVZN_cm33) || defined(CPU_MIMX95294DVTN_cm33) || defined(CPU_MIMX95294DVYN_cm33) || defined(CPU_MIMX95294DVZN_cm33) || defined(CPU_MIMX95294XVTN_cm33) || defined(CPU_MIMX95294XVYN_cm33) || defined(CPU_MIMX95294XVZN_cm33))
#include "MIMX95294_cm33_COMMON.h"
#elif (defined(CPU_MIMX95294AVTN_cm7) || defined(CPU_MIMX95294AVYN_cm7) || defined(CPU_MIMX95294AVZN_cm7) || defined(CPU_MIMX95294CVTN_cm7) || defined(CPU_MIMX95294CVYN_cm7) || defined(CPU_MIMX95294CVZN_cm7) || defined(CPU_MIMX95294DVTN_cm7) || defined(CPU_MIMX95294DVYN_cm7) || defined(CPU_MIMX95294DVZN_cm7) || defined(CPU_MIMX95294XVTN_cm7) || defined(CPU_MIMX95294XVYN_cm7) || defined(CPU_MIMX95294XVZN_cm7))
#include "MIMX95294_cm7_COMMON.h"
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
   -- domainma Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup domainma_Peripheral_Access_Layer domainma Peripheral Access Layer
 * @{
 */

/** domainma - Register Layout Typedef */
typedef struct {
  __O  uint32_t MAKLKUNL;                          /**< MaskLockUnlock, offset: 0x0 */
  __I  uint32_t MASKLS;                            /**< MaskLockStatus, offset: 0x4 */
  __IO uint32_t STOR9DM;                           /**< store9_domain_mask0, offset: 0x8 */
  __IO uint32_t EXTD0DK0;                          /**< extdst0_domain_mask0, offset: 0xC */
  __IO uint32_t EXTD4DK0;                          /**< extdst4_domain_mask0, offset: 0x10 */
  __IO uint32_t EXTD1DK0;                          /**< extdst1_domain_mask0, offset: 0x14 */
  __IO uint32_t EXTD5DK0;                          /**< extdst5_domain_mask0, offset: 0x18 */
  __IO uint32_t SEERISDS;                          /**< SEERIS_Display_Static, offset: 0x1C */
  __IO uint32_t EXTD0S;                            /**< extdst0_Static, offset: 0x20 */
  __IO uint32_t EXTD4S;                            /**< extdst4_Static, offset: 0x24 */
  __IO uint32_t EXTD1S;                            /**< extdst1_Static, offset: 0x28 */
  __IO uint32_t EXTD5S;                            /**< extdst5_Static, offset: 0x2C */
} domainma_Type;

/* ----------------------------------------------------------------------------
   -- domainma Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup domainma_Register_Masks domainma Register Masks
 * @{
 */

/*! @name MAKLKUNL - MaskLockUnlock */
/*! @{ */

#define domainma_MAKLKUNL_MakLkUnl_MASK          (0xFFFFFFFFU)
#define domainma_MAKLKUNL_MakLkUnl_SHIFT         (0U)
/*! MakLkUnl - MaskLockUnlock
 *  0b01010110010100011111011101100011..Decrements the unlock counter. When the counter value is null, lock protection is active. Reset counter value is 1.
 *  0b01101001000111011011100100110110..Increments the unlock counter. Max allowed value is 15.
 *  0b10101110111010010101110011011100..Enables privilege protection. Disabled after reset.
 *  0b10110101111000100100011001101110..Disables privilege protection.
 *  0b11111011111010001011000111100110..Freezes current protection status. Writing keys to this register has no more effect until reset.
 */
#define domainma_MAKLKUNL_MakLkUnl(x)            (((uint32_t)(((uint32_t)(x)) << domainma_MAKLKUNL_MakLkUnl_SHIFT)) & domainma_MAKLKUNL_MakLkUnl_MASK)
/*! @} */

/*! @name MASKLS - MaskLockStatus */
/*! @{ */

#define domainma_MASKLS_MakLkS_MASK              (0x1U)
#define domainma_MASKLS_MakLkS_SHIFT             (0U)
/*! MakLkS - MaskLockStatus */
#define domainma_MASKLS_MakLkS(x)                (((uint32_t)(((uint32_t)(x)) << domainma_MASKLS_MakLkS_SHIFT)) & domainma_MASKLS_MakLkS_MASK)

#define domainma_MASKLS_MakPS_MASK               (0x10U)
#define domainma_MASKLS_MakPS_SHIFT              (4U)
/*! MakPS - MaskPrivilegeStatus */
#define domainma_MASKLS_MakPS(x)                 (((uint32_t)(((uint32_t)(x)) << domainma_MASKLS_MakPS_SHIFT)) & domainma_MASKLS_MakPS_MASK)

#define domainma_MASKLS_MakFreS_MASK             (0x100U)
#define domainma_MASKLS_MakFreS_SHIFT            (8U)
/*! MakFreS - MaskFreezeStatus */
#define domainma_MASKLS_MakFreS(x)               (((uint32_t)(((uint32_t)(x)) << domainma_MASKLS_MakFreS_SHIFT)) & domainma_MASKLS_MakFreS_MASK)
/*! @} */

/*! @name STOR9DM - store9_domain_mask0 */
/*! @{ */

#define domainma_STOR9DM_sto9dro9_MASK           (0x1U)
#define domainma_STOR9DM_sto9dro9_SHIFT          (0U)
/*! sto9dro9 - store9_dm_rop9
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_STOR9DM_sto9dro9(x)             (((uint32_t)(((uint32_t)(x)) << domainma_STOR9DM_sto9dro9_SHIFT)) & domainma_STOR9DM_sto9dro9_MASK)

#define domainma_STOR9DM_sto9dcl9_MASK           (0x2U)
#define domainma_STOR9DM_sto9dcl9_SHIFT          (1U)
/*! sto9dcl9 - store9_dm_clut9
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_STOR9DM_sto9dcl9(x)             (((uint32_t)(((uint32_t)(x)) << domainma_STOR9DM_sto9dcl9_SHIFT)) & domainma_STOR9DM_sto9dcl9_MASK)

#define domainma_STOR9DM_sto9dma9_MASK           (0x4U)
#define domainma_STOR9DM_sto9dma9_SHIFT          (2U)
/*! sto9dma9 - store9_dm_matrix9
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_STOR9DM_sto9dma9(x)             (((uint32_t)(((uint32_t)(x)) << domainma_STOR9DM_sto9dma9_SHIFT)) & domainma_STOR9DM_sto9dma9_MASK)

#define domainma_STOR9DM_sto9dbb9_MASK           (0x8U)
#define domainma_STOR9DM_sto9dbb9_SHIFT          (3U)
/*! sto9dbb9 - store9_dm_blitblend9
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_STOR9DM_sto9dbb9(x)             (((uint32_t)(((uint32_t)(x)) << domainma_STOR9DM_sto9dbb9_SHIFT)) & domainma_STOR9DM_sto9dbb9_MASK)

#define domainma_STOR9DM_sto9dfr9_MASK           (0x10U)
#define domainma_STOR9DM_sto9dfr9_SHIFT          (4U)
/*! sto9dfr9 - store9_dm_fetchrot9
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_STOR9DM_sto9dfr9(x)             (((uint32_t)(((uint32_t)(x)) << domainma_STOR9DM_sto9dfr9_SHIFT)) & domainma_STOR9DM_sto9dfr9_MASK)

#define domainma_STOR9DM_sto9dfd9_MASK           (0x20U)
#define domainma_STOR9DM_sto9dfd9_SHIFT          (5U)
/*! sto9dfd9 - store9_dm_fetchdecode9
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_STOR9DM_sto9dfd9(x)             (((uint32_t)(((uint32_t)(x)) << domainma_STOR9DM_sto9dfd9_SHIFT)) & domainma_STOR9DM_sto9dfd9_MASK)

#define domainma_STOR9DM_sto9dfe9_MASK           (0x40U)
#define domainma_STOR9DM_sto9dfe9_SHIFT          (6U)
/*! sto9dfe9 - store9_dm_fetcheco9
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_STOR9DM_sto9dfe9(x)             (((uint32_t)(((uint32_t)(x)) << domainma_STOR9DM_sto9dfe9_SHIFT)) & domainma_STOR9DM_sto9dfe9_MASK)

#define domainma_STOR9DM_sto9dhs9_MASK           (0x80U)
#define domainma_STOR9DM_sto9dhs9_SHIFT          (7U)
/*! sto9dhs9 - store9_dm_hscaler9
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_STOR9DM_sto9dhs9(x)             (((uint32_t)(((uint32_t)(x)) << domainma_STOR9DM_sto9dhs9_SHIFT)) & domainma_STOR9DM_sto9dhs9_MASK)

#define domainma_STOR9DM_sto9dvs9_MASK           (0x100U)
#define domainma_STOR9DM_sto9dvs9_SHIFT          (8U)
/*! sto9dvs9 - store9_dm_vscaler9
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_STOR9DM_sto9dvs9(x)             (((uint32_t)(((uint32_t)(x)) << domainma_STOR9DM_sto9dvs9_SHIFT)) & domainma_STOR9DM_sto9dvs9_MASK)

#define domainma_STOR9DM_sto9dfi9_MASK           (0x200U)
#define domainma_STOR9DM_sto9dfi9_SHIFT          (9U)
/*! sto9dfi9 - store9_dm_filter9
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_STOR9DM_sto9dfi9(x)             (((uint32_t)(((uint32_t)(x)) << domainma_STOR9DM_sto9dfi9_SHIFT)) & domainma_STOR9DM_sto9dfi9_MASK)

#define domainma_STOR9DM_sto9dcf0_MASK           (0x400U)
#define domainma_STOR9DM_sto9dcf0_SHIFT          (10U)
/*! sto9dcf0 - store9_dm_constframe0
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_STOR9DM_sto9dcf0(x)             (((uint32_t)(((uint32_t)(x)) << domainma_STOR9DM_sto9dcf0_SHIFT)) & domainma_STOR9DM_sto9dcf0_MASK)

#define domainma_STOR9DM_sto9dcf4_MASK           (0x800U)
#define domainma_STOR9DM_sto9dcf4_SHIFT          (11U)
/*! sto9dcf4 - store9_dm_constframe4
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_STOR9DM_sto9dcf4(x)             (((uint32_t)(((uint32_t)(x)) << domainma_STOR9DM_sto9dcf4_SHIFT)) & domainma_STOR9DM_sto9dcf4_MASK)

#define domainma_STOR9DM_sto9dcf1_MASK           (0x1000U)
#define domainma_STOR9DM_sto9dcf1_SHIFT          (12U)
/*! sto9dcf1 - store9_dm_constframe1
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_STOR9DM_sto9dcf1(x)             (((uint32_t)(((uint32_t)(x)) << domainma_STOR9DM_sto9dcf1_SHIFT)) & domainma_STOR9DM_sto9dcf1_MASK)

#define domainma_STOR9DM_sto9dcf5_MASK           (0x2000U)
#define domainma_STOR9DM_sto9dcf5_SHIFT          (13U)
/*! sto9dcf5 - store9_dm_constframe5
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_STOR9DM_sto9dcf5(x)             (((uint32_t)(((uint32_t)(x)) << domainma_STOR9DM_sto9dcf5_SHIFT)) & domainma_STOR9DM_sto9dcf5_MASK)

#define domainma_STOR9DM_sto9dlb1_MASK           (0x4000U)
#define domainma_STOR9DM_sto9dlb1_SHIFT          (14U)
/*! sto9dlb1 - store9_dm_layerblend1
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_STOR9DM_sto9dlb1(x)             (((uint32_t)(((uint32_t)(x)) << domainma_STOR9DM_sto9dlb1_SHIFT)) & domainma_STOR9DM_sto9dlb1_MASK)

#define domainma_STOR9DM_sto9dlb2_MASK           (0x8000U)
#define domainma_STOR9DM_sto9dlb2_SHIFT          (15U)
/*! sto9dlb2 - store9_dm_layerblend2
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_STOR9DM_sto9dlb2(x)             (((uint32_t)(((uint32_t)(x)) << domainma_STOR9DM_sto9dlb2_SHIFT)) & domainma_STOR9DM_sto9dlb2_MASK)

#define domainma_STOR9DM_sto9dlb3_MASK           (0x10000U)
#define domainma_STOR9DM_sto9dlb3_SHIFT          (16U)
/*! sto9dlb3 - store9_dm_layerblend3
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_STOR9DM_sto9dlb3(x)             (((uint32_t)(((uint32_t)(x)) << domainma_STOR9DM_sto9dlb3_SHIFT)) & domainma_STOR9DM_sto9dlb3_MASK)

#define domainma_STOR9DM_sto9dlb4_MASK           (0x20000U)
#define domainma_STOR9DM_sto9dlb4_SHIFT          (17U)
/*! sto9dlb4 - store9_dm_layerblend4
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_STOR9DM_sto9dlb4(x)             (((uint32_t)(((uint32_t)(x)) << domainma_STOR9DM_sto9dlb4_SHIFT)) & domainma_STOR9DM_sto9dlb4_MASK)

#define domainma_STOR9DM_sto9dlb5_MASK           (0x40000U)
#define domainma_STOR9DM_sto9dlb5_SHIFT          (18U)
/*! sto9dlb5 - store9_dm_layerblend5
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_STOR9DM_sto9dlb5(x)             (((uint32_t)(((uint32_t)(x)) << domainma_STOR9DM_sto9dlb5_SHIFT)) & domainma_STOR9DM_sto9dlb5_MASK)

#define domainma_STOR9DM_sto9dfl0_MASK           (0x80000U)
#define domainma_STOR9DM_sto9dfl0_SHIFT          (19U)
/*! sto9dfl0 - store9_dm_fetchlayer0
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_STOR9DM_sto9dfl0(x)             (((uint32_t)(((uint32_t)(x)) << domainma_STOR9DM_sto9dfl0_SHIFT)) & domainma_STOR9DM_sto9dfl0_MASK)

#define domainma_STOR9DM_sto9dfl1_MASK           (0x100000U)
#define domainma_STOR9DM_sto9dfl1_SHIFT          (20U)
/*! sto9dfl1 - store9_dm_fetchlayer1
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_STOR9DM_sto9dfl1(x)             (((uint32_t)(((uint32_t)(x)) << domainma_STOR9DM_sto9dfl1_SHIFT)) & domainma_STOR9DM_sto9dfl1_MASK)

#define domainma_STOR9DM_sto9dfy3_MASK           (0x200000U)
#define domainma_STOR9DM_sto9dfy3_SHIFT          (21U)
/*! sto9dfy3 - store9_dm_fetchyuv3
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_STOR9DM_sto9dfy3(x)             (((uint32_t)(((uint32_t)(x)) << domainma_STOR9DM_sto9dfy3_SHIFT)) & domainma_STOR9DM_sto9dfy3_MASK)

#define domainma_STOR9DM_sto9dfy0_MASK           (0x400000U)
#define domainma_STOR9DM_sto9dfy0_SHIFT          (22U)
/*! sto9dfy0 - store9_dm_fetchyuv0
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_STOR9DM_sto9dfy0(x)             (((uint32_t)(((uint32_t)(x)) << domainma_STOR9DM_sto9dfy0_SHIFT)) & domainma_STOR9DM_sto9dfy0_MASK)

#define domainma_STOR9DM_sto9dfe0_MASK           (0x800000U)
#define domainma_STOR9DM_sto9dfe0_SHIFT          (23U)
/*! sto9dfe0 - store9_dm_fetcheco0
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_STOR9DM_sto9dfe0(x)             (((uint32_t)(((uint32_t)(x)) << domainma_STOR9DM_sto9dfe0_SHIFT)) & domainma_STOR9DM_sto9dfe0_MASK)

#define domainma_STOR9DM_sto9dfy1_MASK           (0x1000000U)
#define domainma_STOR9DM_sto9dfy1_SHIFT          (24U)
/*! sto9dfy1 - store9_dm_fetchyuv1
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_STOR9DM_sto9dfy1(x)             (((uint32_t)(((uint32_t)(x)) << domainma_STOR9DM_sto9dfy1_SHIFT)) & domainma_STOR9DM_sto9dfy1_MASK)

#define domainma_STOR9DM_sto9dfe1_MASK           (0x2000000U)
#define domainma_STOR9DM_sto9dfe1_SHIFT          (25U)
/*! sto9dfe1 - store9_dm_fetcheco1
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_STOR9DM_sto9dfe1(x)             (((uint32_t)(((uint32_t)(x)) << domainma_STOR9DM_sto9dfe1_SHIFT)) & domainma_STOR9DM_sto9dfe1_MASK)

#define domainma_STOR9DM_sto9dma4_MASK           (0x4000000U)
#define domainma_STOR9DM_sto9dma4_SHIFT          (26U)
/*! sto9dma4 - store9_dm_matrix4
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_STOR9DM_sto9dma4(x)             (((uint32_t)(((uint32_t)(x)) << domainma_STOR9DM_sto9dma4_SHIFT)) & domainma_STOR9DM_sto9dma4_MASK)

#define domainma_STOR9DM_sto9dhs4_MASK           (0x8000000U)
#define domainma_STOR9DM_sto9dhs4_SHIFT          (27U)
/*! sto9dhs4 - store9_dm_hscaler4
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_STOR9DM_sto9dhs4(x)             (((uint32_t)(((uint32_t)(x)) << domainma_STOR9DM_sto9dhs4_SHIFT)) & domainma_STOR9DM_sto9dhs4_MASK)

#define domainma_STOR9DM_sto9dvs4_MASK           (0x10000000U)
#define domainma_STOR9DM_sto9dvs4_SHIFT          (28U)
/*! sto9dvs4 - store9_dm_vscaler4
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_STOR9DM_sto9dvs4(x)             (((uint32_t)(((uint32_t)(x)) << domainma_STOR9DM_sto9dvs4_SHIFT)) & domainma_STOR9DM_sto9dvs4_MASK)
/*! @} */

/*! @name EXTD0DK0 - extdst0_domain_mask0 */
/*! @{ */

#define domainma_EXTD0DK0_exd0dmr9_MASK          (0x1U)
#define domainma_EXTD0DK0_exd0dmr9_SHIFT         (0U)
/*! exd0dmr9 - extdst0_dm_rop9
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD0DK0_exd0dmr9(x)            (((uint32_t)(((uint32_t)(x)) << domainma_EXTD0DK0_exd0dmr9_SHIFT)) & domainma_EXTD0DK0_exd0dmr9_MASK)

#define domainma_EXTD0DK0_exd0dc9_MASK           (0x2U)
#define domainma_EXTD0DK0_exd0dc9_SHIFT          (1U)
/*! exd0dc9 - extdst0_dm_clut9
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD0DK0_exd0dc9(x)             (((uint32_t)(((uint32_t)(x)) << domainma_EXTD0DK0_exd0dc9_SHIFT)) & domainma_EXTD0DK0_exd0dc9_MASK)

#define domainma_EXTD0DK0_exd0dm9_MASK           (0x4U)
#define domainma_EXTD0DK0_exd0dm9_SHIFT          (2U)
/*! exd0dm9 - extdst0_dm_matrix9
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD0DK0_exd0dm9(x)             (((uint32_t)(((uint32_t)(x)) << domainma_EXTD0DK0_exd0dm9_SHIFT)) & domainma_EXTD0DK0_exd0dm9_MASK)

#define domainma_EXTD0DK0_exd0db9_MASK           (0x8U)
#define domainma_EXTD0DK0_exd0db9_SHIFT          (3U)
/*! exd0db9 - extdst0_dm_blitblend9
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD0DK0_exd0db9(x)             (((uint32_t)(((uint32_t)(x)) << domainma_EXTD0DK0_exd0db9_SHIFT)) & domainma_EXTD0DK0_exd0db9_MASK)

#define domainma_EXTD0DK0_exd0dfr9_MASK          (0x10U)
#define domainma_EXTD0DK0_exd0dfr9_SHIFT         (4U)
/*! exd0dfr9 - extdst0_dm_fetchrot9
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD0DK0_exd0dfr9(x)            (((uint32_t)(((uint32_t)(x)) << domainma_EXTD0DK0_exd0dfr9_SHIFT)) & domainma_EXTD0DK0_exd0dfr9_MASK)

#define domainma_EXTD0DK0_exd0dfd9_MASK          (0x20U)
#define domainma_EXTD0DK0_exd0dfd9_SHIFT         (5U)
/*! exd0dfd9 - extdst0_dm_fetchdecode9
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD0DK0_exd0dfd9(x)            (((uint32_t)(((uint32_t)(x)) << domainma_EXTD0DK0_exd0dfd9_SHIFT)) & domainma_EXTD0DK0_exd0dfd9_MASK)

#define domainma_EXTD0DK0_exd0dfe9_MASK          (0x40U)
#define domainma_EXTD0DK0_exd0dfe9_SHIFT         (6U)
/*! exd0dfe9 - extdst0_dm_fetcheco9
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD0DK0_exd0dfe9(x)            (((uint32_t)(((uint32_t)(x)) << domainma_EXTD0DK0_exd0dfe9_SHIFT)) & domainma_EXTD0DK0_exd0dfe9_MASK)

#define domainma_EXTD0DK0_exd0dhs9_MASK          (0x80U)
#define domainma_EXTD0DK0_exd0dhs9_SHIFT         (7U)
/*! exd0dhs9 - extdst0_dm_hscaler9
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD0DK0_exd0dhs9(x)            (((uint32_t)(((uint32_t)(x)) << domainma_EXTD0DK0_exd0dhs9_SHIFT)) & domainma_EXTD0DK0_exd0dhs9_MASK)

#define domainma_EXTD0DK0_exd0dmv9_MASK          (0x100U)
#define domainma_EXTD0DK0_exd0dmv9_SHIFT         (8U)
/*! exd0dmv9 - extdst0_dm_vscaler9
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD0DK0_exd0dmv9(x)            (((uint32_t)(((uint32_t)(x)) << domainma_EXTD0DK0_exd0dmv9_SHIFT)) & domainma_EXTD0DK0_exd0dmv9_MASK)

#define domainma_EXTD0DK0_exd0dfi9_MASK          (0x200U)
#define domainma_EXTD0DK0_exd0dfi9_SHIFT         (9U)
/*! exd0dfi9 - extdst0_dm_filter9
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD0DK0_exd0dfi9(x)            (((uint32_t)(((uint32_t)(x)) << domainma_EXTD0DK0_exd0dfi9_SHIFT)) & domainma_EXTD0DK0_exd0dfi9_MASK)

#define domainma_EXTD0DK0_exd0dc0_MASK           (0x400U)
#define domainma_EXTD0DK0_exd0dc0_SHIFT          (10U)
/*! exd0dc0 - extdst0_dm_constframe0
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD0DK0_exd0dc0(x)             (((uint32_t)(((uint32_t)(x)) << domainma_EXTD0DK0_exd0dc0_SHIFT)) & domainma_EXTD0DK0_exd0dc0_MASK)

#define domainma_EXTD0DK0_exd0dc4_MASK           (0x800U)
#define domainma_EXTD0DK0_exd0dc4_SHIFT          (11U)
/*! exd0dc4 - extdst0_dm_constframe4
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD0DK0_exd0dc4(x)             (((uint32_t)(((uint32_t)(x)) << domainma_EXTD0DK0_exd0dc4_SHIFT)) & domainma_EXTD0DK0_exd0dc4_MASK)

#define domainma_EXTD0DK0_exd0dc1_MASK           (0x1000U)
#define domainma_EXTD0DK0_exd0dc1_SHIFT          (12U)
/*! exd0dc1 - extdst0_dm_constframe1
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD0DK0_exd0dc1(x)             (((uint32_t)(((uint32_t)(x)) << domainma_EXTD0DK0_exd0dc1_SHIFT)) & domainma_EXTD0DK0_exd0dc1_MASK)

#define domainma_EXTD0DK0_exd0dc5_MASK           (0x2000U)
#define domainma_EXTD0DK0_exd0dc5_SHIFT          (13U)
/*! exd0dc5 - extdst0_dm_constframe5
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD0DK0_exd0dc5(x)             (((uint32_t)(((uint32_t)(x)) << domainma_EXTD0DK0_exd0dc5_SHIFT)) & domainma_EXTD0DK0_exd0dc5_MASK)

#define domainma_EXTD0DK0_exd0dlb1_MASK          (0x4000U)
#define domainma_EXTD0DK0_exd0dlb1_SHIFT         (14U)
/*! exd0dlb1 - extdst0_dm_layerblend1
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD0DK0_exd0dlb1(x)            (((uint32_t)(((uint32_t)(x)) << domainma_EXTD0DK0_exd0dlb1_SHIFT)) & domainma_EXTD0DK0_exd0dlb1_MASK)

#define domainma_EXTD0DK0_exd0dlb2_MASK          (0x8000U)
#define domainma_EXTD0DK0_exd0dlb2_SHIFT         (15U)
/*! exd0dlb2 - extdst0_dm_layerblend2
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD0DK0_exd0dlb2(x)            (((uint32_t)(((uint32_t)(x)) << domainma_EXTD0DK0_exd0dlb2_SHIFT)) & domainma_EXTD0DK0_exd0dlb2_MASK)

#define domainma_EXTD0DK0_exd0dlb3_MASK          (0x10000U)
#define domainma_EXTD0DK0_exd0dlb3_SHIFT         (16U)
/*! exd0dlb3 - extdst0_dm_layerblend3
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD0DK0_exd0dlb3(x)            (((uint32_t)(((uint32_t)(x)) << domainma_EXTD0DK0_exd0dlb3_SHIFT)) & domainma_EXTD0DK0_exd0dlb3_MASK)

#define domainma_EXTD0DK0_exd0dlb4_MASK          (0x20000U)
#define domainma_EXTD0DK0_exd0dlb4_SHIFT         (17U)
/*! exd0dlb4 - extdst0_dm_layerblend4
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD0DK0_exd0dlb4(x)            (((uint32_t)(((uint32_t)(x)) << domainma_EXTD0DK0_exd0dlb4_SHIFT)) & domainma_EXTD0DK0_exd0dlb4_MASK)

#define domainma_EXTD0DK0_exd0dlb5_MASK          (0x40000U)
#define domainma_EXTD0DK0_exd0dlb5_SHIFT         (18U)
/*! exd0dlb5 - extdst0_dm_layerblend5
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD0DK0_exd0dlb5(x)            (((uint32_t)(((uint32_t)(x)) << domainma_EXTD0DK0_exd0dlb5_SHIFT)) & domainma_EXTD0DK0_exd0dlb5_MASK)

#define domainma_EXTD0DK0_exd0dfl0_MASK          (0x80000U)
#define domainma_EXTD0DK0_exd0dfl0_SHIFT         (19U)
/*! exd0dfl0 - extdst0_dm_fetchlayer0
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD0DK0_exd0dfl0(x)            (((uint32_t)(((uint32_t)(x)) << domainma_EXTD0DK0_exd0dfl0_SHIFT)) & domainma_EXTD0DK0_exd0dfl0_MASK)

#define domainma_EXTD0DK0_exd0dfl1_MASK          (0x100000U)
#define domainma_EXTD0DK0_exd0dfl1_SHIFT         (20U)
/*! exd0dfl1 - extdst0_dm_fetchlayer1
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD0DK0_exd0dfl1(x)            (((uint32_t)(((uint32_t)(x)) << domainma_EXTD0DK0_exd0dfl1_SHIFT)) & domainma_EXTD0DK0_exd0dfl1_MASK)

#define domainma_EXTD0DK0_exd0dfy3_MASK          (0x200000U)
#define domainma_EXTD0DK0_exd0dfy3_SHIFT         (21U)
/*! exd0dfy3 - extdst0_dm_fetchyuv3
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD0DK0_exd0dfy3(x)            (((uint32_t)(((uint32_t)(x)) << domainma_EXTD0DK0_exd0dfy3_SHIFT)) & domainma_EXTD0DK0_exd0dfy3_MASK)

#define domainma_EXTD0DK0_exd0dfy0_MASK          (0x400000U)
#define domainma_EXTD0DK0_exd0dfy0_SHIFT         (22U)
/*! exd0dfy0 - extdst0_dm_fetchyuv0
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD0DK0_exd0dfy0(x)            (((uint32_t)(((uint32_t)(x)) << domainma_EXTD0DK0_exd0dfy0_SHIFT)) & domainma_EXTD0DK0_exd0dfy0_MASK)

#define domainma_EXTD0DK0_exd0dfe0_MASK          (0x800000U)
#define domainma_EXTD0DK0_exd0dfe0_SHIFT         (23U)
/*! exd0dfe0 - extdst0_dm_fetcheco0
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD0DK0_exd0dfe0(x)            (((uint32_t)(((uint32_t)(x)) << domainma_EXTD0DK0_exd0dfe0_SHIFT)) & domainma_EXTD0DK0_exd0dfe0_MASK)

#define domainma_EXTD0DK0_exd0dfy1_MASK          (0x1000000U)
#define domainma_EXTD0DK0_exd0dfy1_SHIFT         (24U)
/*! exd0dfy1 - extdst0_dm_fetchyuv1
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD0DK0_exd0dfy1(x)            (((uint32_t)(((uint32_t)(x)) << domainma_EXTD0DK0_exd0dfy1_SHIFT)) & domainma_EXTD0DK0_exd0dfy1_MASK)

#define domainma_EXTD0DK0_exd0dfe1_MASK          (0x2000000U)
#define domainma_EXTD0DK0_exd0dfe1_SHIFT         (25U)
/*! exd0dfe1 - extdst0_dm_fetcheco1
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD0DK0_exd0dfe1(x)            (((uint32_t)(((uint32_t)(x)) << domainma_EXTD0DK0_exd0dfe1_SHIFT)) & domainma_EXTD0DK0_exd0dfe1_MASK)

#define domainma_EXTD0DK0_exd0dm4_MASK           (0x4000000U)
#define domainma_EXTD0DK0_exd0dm4_SHIFT          (26U)
/*! exd0dm4 - extdst0_dm_matrix4
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD0DK0_exd0dm4(x)             (((uint32_t)(((uint32_t)(x)) << domainma_EXTD0DK0_exd0dm4_SHIFT)) & domainma_EXTD0DK0_exd0dm4_MASK)

#define domainma_EXTD0DK0_exd0dhs4_MASK          (0x8000000U)
#define domainma_EXTD0DK0_exd0dhs4_SHIFT         (27U)
/*! exd0dhs4 - extdst0_dm_hscaler4
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD0DK0_exd0dhs4(x)            (((uint32_t)(((uint32_t)(x)) << domainma_EXTD0DK0_exd0dhs4_SHIFT)) & domainma_EXTD0DK0_exd0dhs4_MASK)

#define domainma_EXTD0DK0_exd0dmv4_MASK          (0x10000000U)
#define domainma_EXTD0DK0_exd0dmv4_SHIFT         (28U)
/*! exd0dmv4 - extdst0_dm_vscaler4
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD0DK0_exd0dmv4(x)            (((uint32_t)(((uint32_t)(x)) << domainma_EXTD0DK0_exd0dmv4_SHIFT)) & domainma_EXTD0DK0_exd0dmv4_MASK)
/*! @} */

/*! @name EXTD4DK0 - extdst4_domain_mask0 */
/*! @{ */

#define domainma_EXTD4DK0_exd4dmr9_MASK          (0x1U)
#define domainma_EXTD4DK0_exd4dmr9_SHIFT         (0U)
/*! exd4dmr9 - extdst4_dm_rop9
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD4DK0_exd4dmr9(x)            (((uint32_t)(((uint32_t)(x)) << domainma_EXTD4DK0_exd4dmr9_SHIFT)) & domainma_EXTD4DK0_exd4dmr9_MASK)

#define domainma_EXTD4DK0_exd4dc9_MASK           (0x2U)
#define domainma_EXTD4DK0_exd4dc9_SHIFT          (1U)
/*! exd4dc9 - extdst4_dm_clut9
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD4DK0_exd4dc9(x)             (((uint32_t)(((uint32_t)(x)) << domainma_EXTD4DK0_exd4dc9_SHIFT)) & domainma_EXTD4DK0_exd4dc9_MASK)

#define domainma_EXTD4DK0_exd4dm9_MASK           (0x4U)
#define domainma_EXTD4DK0_exd4dm9_SHIFT          (2U)
/*! exd4dm9 - extdst4_dm_matrix9
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD4DK0_exd4dm9(x)             (((uint32_t)(((uint32_t)(x)) << domainma_EXTD4DK0_exd4dm9_SHIFT)) & domainma_EXTD4DK0_exd4dm9_MASK)

#define domainma_EXTD4DK0_exd4db9_MASK           (0x8U)
#define domainma_EXTD4DK0_exd4db9_SHIFT          (3U)
/*! exd4db9 - extdst4_dm_blitblend9
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD4DK0_exd4db9(x)             (((uint32_t)(((uint32_t)(x)) << domainma_EXTD4DK0_exd4db9_SHIFT)) & domainma_EXTD4DK0_exd4db9_MASK)

#define domainma_EXTD4DK0_exd4dfr9_MASK          (0x10U)
#define domainma_EXTD4DK0_exd4dfr9_SHIFT         (4U)
/*! exd4dfr9 - extdst4_dm_fetchrot9
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD4DK0_exd4dfr9(x)            (((uint32_t)(((uint32_t)(x)) << domainma_EXTD4DK0_exd4dfr9_SHIFT)) & domainma_EXTD4DK0_exd4dfr9_MASK)

#define domainma_EXTD4DK0_exd4dfd9_MASK          (0x20U)
#define domainma_EXTD4DK0_exd4dfd9_SHIFT         (5U)
/*! exd4dfd9 - extdst4_dm_fetchdecode9
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD4DK0_exd4dfd9(x)            (((uint32_t)(((uint32_t)(x)) << domainma_EXTD4DK0_exd4dfd9_SHIFT)) & domainma_EXTD4DK0_exd4dfd9_MASK)

#define domainma_EXTD4DK0_exd4dfe9_MASK          (0x40U)
#define domainma_EXTD4DK0_exd4dfe9_SHIFT         (6U)
/*! exd4dfe9 - extdst4_dm_fetcheco9
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD4DK0_exd4dfe9(x)            (((uint32_t)(((uint32_t)(x)) << domainma_EXTD4DK0_exd4dfe9_SHIFT)) & domainma_EXTD4DK0_exd4dfe9_MASK)

#define domainma_EXTD4DK0_exd4dhs9_MASK          (0x80U)
#define domainma_EXTD4DK0_exd4dhs9_SHIFT         (7U)
/*! exd4dhs9 - extdst4_dm_hscaler9
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD4DK0_exd4dhs9(x)            (((uint32_t)(((uint32_t)(x)) << domainma_EXTD4DK0_exd4dhs9_SHIFT)) & domainma_EXTD4DK0_exd4dhs9_MASK)

#define domainma_EXTD4DK0_exd4dms9_MASK          (0x100U)
#define domainma_EXTD4DK0_exd4dms9_SHIFT         (8U)
/*! exd4dms9 - extdst4_dm_vscaler9
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD4DK0_exd4dms9(x)            (((uint32_t)(((uint32_t)(x)) << domainma_EXTD4DK0_exd4dms9_SHIFT)) & domainma_EXTD4DK0_exd4dms9_MASK)

#define domainma_EXTD4DK0_exd4dfi9_MASK          (0x200U)
#define domainma_EXTD4DK0_exd4dfi9_SHIFT         (9U)
/*! exd4dfi9 - extdst4_dm_filter9
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD4DK0_exd4dfi9(x)            (((uint32_t)(((uint32_t)(x)) << domainma_EXTD4DK0_exd4dfi9_SHIFT)) & domainma_EXTD4DK0_exd4dfi9_MASK)

#define domainma_EXTD4DK0_exd4dc0_MASK           (0x400U)
#define domainma_EXTD4DK0_exd4dc0_SHIFT          (10U)
/*! exd4dc0 - extdst4_dm_constframe0
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD4DK0_exd4dc0(x)             (((uint32_t)(((uint32_t)(x)) << domainma_EXTD4DK0_exd4dc0_SHIFT)) & domainma_EXTD4DK0_exd4dc0_MASK)

#define domainma_EXTD4DK0_exd4dc4_MASK           (0x800U)
#define domainma_EXTD4DK0_exd4dc4_SHIFT          (11U)
/*! exd4dc4 - extdst4_dm_constframe4
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD4DK0_exd4dc4(x)             (((uint32_t)(((uint32_t)(x)) << domainma_EXTD4DK0_exd4dc4_SHIFT)) & domainma_EXTD4DK0_exd4dc4_MASK)

#define domainma_EXTD4DK0_exd4dc1_MASK           (0x1000U)
#define domainma_EXTD4DK0_exd4dc1_SHIFT          (12U)
/*! exd4dc1 - extdst4_dm_constframe1
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD4DK0_exd4dc1(x)             (((uint32_t)(((uint32_t)(x)) << domainma_EXTD4DK0_exd4dc1_SHIFT)) & domainma_EXTD4DK0_exd4dc1_MASK)

#define domainma_EXTD4DK0_exd4dc5_MASK           (0x2000U)
#define domainma_EXTD4DK0_exd4dc5_SHIFT          (13U)
/*! exd4dc5 - extdst4_dm_constframe5
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD4DK0_exd4dc5(x)             (((uint32_t)(((uint32_t)(x)) << domainma_EXTD4DK0_exd4dc5_SHIFT)) & domainma_EXTD4DK0_exd4dc5_MASK)

#define domainma_EXTD4DK0_exd4dlb1_MASK          (0x4000U)
#define domainma_EXTD4DK0_exd4dlb1_SHIFT         (14U)
/*! exd4dlb1 - extdst4_dm_layerblend1
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD4DK0_exd4dlb1(x)            (((uint32_t)(((uint32_t)(x)) << domainma_EXTD4DK0_exd4dlb1_SHIFT)) & domainma_EXTD4DK0_exd4dlb1_MASK)

#define domainma_EXTD4DK0_exd4dlb2_MASK          (0x8000U)
#define domainma_EXTD4DK0_exd4dlb2_SHIFT         (15U)
/*! exd4dlb2 - extdst4_dm_layerblend2
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD4DK0_exd4dlb2(x)            (((uint32_t)(((uint32_t)(x)) << domainma_EXTD4DK0_exd4dlb2_SHIFT)) & domainma_EXTD4DK0_exd4dlb2_MASK)

#define domainma_EXTD4DK0_exd4dlb3_MASK          (0x10000U)
#define domainma_EXTD4DK0_exd4dlb3_SHIFT         (16U)
/*! exd4dlb3 - extdst4_dm_layerblend3
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD4DK0_exd4dlb3(x)            (((uint32_t)(((uint32_t)(x)) << domainma_EXTD4DK0_exd4dlb3_SHIFT)) & domainma_EXTD4DK0_exd4dlb3_MASK)

#define domainma_EXTD4DK0_exd4dlb4_MASK          (0x20000U)
#define domainma_EXTD4DK0_exd4dlb4_SHIFT         (17U)
/*! exd4dlb4 - extdst4_dm_layerblend4
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD4DK0_exd4dlb4(x)            (((uint32_t)(((uint32_t)(x)) << domainma_EXTD4DK0_exd4dlb4_SHIFT)) & domainma_EXTD4DK0_exd4dlb4_MASK)

#define domainma_EXTD4DK0_exd4dlb5_MASK          (0x40000U)
#define domainma_EXTD4DK0_exd4dlb5_SHIFT         (18U)
/*! exd4dlb5 - extdst4_dm_layerblend5
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD4DK0_exd4dlb5(x)            (((uint32_t)(((uint32_t)(x)) << domainma_EXTD4DK0_exd4dlb5_SHIFT)) & domainma_EXTD4DK0_exd4dlb5_MASK)

#define domainma_EXTD4DK0_exd4dfl0_MASK          (0x80000U)
#define domainma_EXTD4DK0_exd4dfl0_SHIFT         (19U)
/*! exd4dfl0 - extdst4_dm_fetchlayer0
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD4DK0_exd4dfl0(x)            (((uint32_t)(((uint32_t)(x)) << domainma_EXTD4DK0_exd4dfl0_SHIFT)) & domainma_EXTD4DK0_exd4dfl0_MASK)

#define domainma_EXTD4DK0_exd4dfl1_MASK          (0x100000U)
#define domainma_EXTD4DK0_exd4dfl1_SHIFT         (20U)
/*! exd4dfl1 - extdst4_dm_fetchlayer1
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD4DK0_exd4dfl1(x)            (((uint32_t)(((uint32_t)(x)) << domainma_EXTD4DK0_exd4dfl1_SHIFT)) & domainma_EXTD4DK0_exd4dfl1_MASK)

#define domainma_EXTD4DK0_exd4dfy3_MASK          (0x200000U)
#define domainma_EXTD4DK0_exd4dfy3_SHIFT         (21U)
/*! exd4dfy3 - extdst4_dm_fetchyuv3
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD4DK0_exd4dfy3(x)            (((uint32_t)(((uint32_t)(x)) << domainma_EXTD4DK0_exd4dfy3_SHIFT)) & domainma_EXTD4DK0_exd4dfy3_MASK)

#define domainma_EXTD4DK0_exd4dfy0_MASK          (0x400000U)
#define domainma_EXTD4DK0_exd4dfy0_SHIFT         (22U)
/*! exd4dfy0 - extdst4_dm_fetchyuv0
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD4DK0_exd4dfy0(x)            (((uint32_t)(((uint32_t)(x)) << domainma_EXTD4DK0_exd4dfy0_SHIFT)) & domainma_EXTD4DK0_exd4dfy0_MASK)

#define domainma_EXTD4DK0_exd4dfe0_MASK          (0x800000U)
#define domainma_EXTD4DK0_exd4dfe0_SHIFT         (23U)
/*! exd4dfe0 - extdst4_dm_fetcheco0
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD4DK0_exd4dfe0(x)            (((uint32_t)(((uint32_t)(x)) << domainma_EXTD4DK0_exd4dfe0_SHIFT)) & domainma_EXTD4DK0_exd4dfe0_MASK)

#define domainma_EXTD4DK0_exd4dfy1_MASK          (0x1000000U)
#define domainma_EXTD4DK0_exd4dfy1_SHIFT         (24U)
/*! exd4dfy1 - extdst4_dm_fetchyuv1
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD4DK0_exd4dfy1(x)            (((uint32_t)(((uint32_t)(x)) << domainma_EXTD4DK0_exd4dfy1_SHIFT)) & domainma_EXTD4DK0_exd4dfy1_MASK)

#define domainma_EXTD4DK0_exd4dfe1_MASK          (0x2000000U)
#define domainma_EXTD4DK0_exd4dfe1_SHIFT         (25U)
/*! exd4dfe1 - extdst4_dm_fetcheco1
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD4DK0_exd4dfe1(x)            (((uint32_t)(((uint32_t)(x)) << domainma_EXTD4DK0_exd4dfe1_SHIFT)) & domainma_EXTD4DK0_exd4dfe1_MASK)

#define domainma_EXTD4DK0_exd4dm4_MASK           (0x4000000U)
#define domainma_EXTD4DK0_exd4dm4_SHIFT          (26U)
/*! exd4dm4 - extdst4_dm_matrix4
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD4DK0_exd4dm4(x)             (((uint32_t)(((uint32_t)(x)) << domainma_EXTD4DK0_exd4dm4_SHIFT)) & domainma_EXTD4DK0_exd4dm4_MASK)

#define domainma_EXTD4DK0_exd4dhs4_MASK          (0x8000000U)
#define domainma_EXTD4DK0_exd4dhs4_SHIFT         (27U)
/*! exd4dhs4 - extdst4_dm_hscaler4
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD4DK0_exd4dhs4(x)            (((uint32_t)(((uint32_t)(x)) << domainma_EXTD4DK0_exd4dhs4_SHIFT)) & domainma_EXTD4DK0_exd4dhs4_MASK)

#define domainma_EXTD4DK0_exd4dms4_MASK          (0x10000000U)
#define domainma_EXTD4DK0_exd4dms4_SHIFT         (28U)
/*! exd4dms4 - extdst4_dm_vscaler4
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD4DK0_exd4dms4(x)            (((uint32_t)(((uint32_t)(x)) << domainma_EXTD4DK0_exd4dms4_SHIFT)) & domainma_EXTD4DK0_exd4dms4_MASK)
/*! @} */

/*! @name EXTD1DK0 - extdst1_domain_mask0 */
/*! @{ */

#define domainma_EXTD1DK0_exd1dmr9_MASK          (0x1U)
#define domainma_EXTD1DK0_exd1dmr9_SHIFT         (0U)
/*! exd1dmr9 - extdst1_dm_rop9
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD1DK0_exd1dmr9(x)            (((uint32_t)(((uint32_t)(x)) << domainma_EXTD1DK0_exd1dmr9_SHIFT)) & domainma_EXTD1DK0_exd1dmr9_MASK)

#define domainma_EXTD1DK0_exd1dc9_MASK           (0x2U)
#define domainma_EXTD1DK0_exd1dc9_SHIFT          (1U)
/*! exd1dc9 - extdst1_dm_clut9
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD1DK0_exd1dc9(x)             (((uint32_t)(((uint32_t)(x)) << domainma_EXTD1DK0_exd1dc9_SHIFT)) & domainma_EXTD1DK0_exd1dc9_MASK)

#define domainma_EXTD1DK0_exd1dm9_MASK           (0x4U)
#define domainma_EXTD1DK0_exd1dm9_SHIFT          (2U)
/*! exd1dm9 - extdst1_dm_matrix9
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD1DK0_exd1dm9(x)             (((uint32_t)(((uint32_t)(x)) << domainma_EXTD1DK0_exd1dm9_SHIFT)) & domainma_EXTD1DK0_exd1dm9_MASK)

#define domainma_EXTD1DK0_exd1db9_MASK           (0x8U)
#define domainma_EXTD1DK0_exd1db9_SHIFT          (3U)
/*! exd1db9 - extdst1_dm_blitblend9
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD1DK0_exd1db9(x)             (((uint32_t)(((uint32_t)(x)) << domainma_EXTD1DK0_exd1db9_SHIFT)) & domainma_EXTD1DK0_exd1db9_MASK)

#define domainma_EXTD1DK0_exddfr9_MASK           (0x10U)
#define domainma_EXTD1DK0_exddfr9_SHIFT          (4U)
/*! exddfr9 - extdst1_dm_fetchrot9
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD1DK0_exddfr9(x)             (((uint32_t)(((uint32_t)(x)) << domainma_EXTD1DK0_exddfr9_SHIFT)) & domainma_EXTD1DK0_exddfr9_MASK)

#define domainma_EXTD1DK0_exd1dfd9_MASK          (0x20U)
#define domainma_EXTD1DK0_exd1dfd9_SHIFT         (5U)
/*! exd1dfd9 - extdst1_dm_fetchdecode9
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD1DK0_exd1dfd9(x)            (((uint32_t)(((uint32_t)(x)) << domainma_EXTD1DK0_exd1dfd9_SHIFT)) & domainma_EXTD1DK0_exd1dfd9_MASK)

#define domainma_EXTD1DK0_exd1dfe9_MASK          (0x40U)
#define domainma_EXTD1DK0_exd1dfe9_SHIFT         (6U)
/*! exd1dfe9 - extdst1_dm_fetcheco9
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD1DK0_exd1dfe9(x)            (((uint32_t)(((uint32_t)(x)) << domainma_EXTD1DK0_exd1dfe9_SHIFT)) & domainma_EXTD1DK0_exd1dfe9_MASK)

#define domainma_EXTD1DK0_exddhs9_MASK           (0x80U)
#define domainma_EXTD1DK0_exddhs9_SHIFT          (7U)
/*! exddhs9 - extdst1_dm_hscaler9
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD1DK0_exddhs9(x)             (((uint32_t)(((uint32_t)(x)) << domainma_EXTD1DK0_exddhs9_SHIFT)) & domainma_EXTD1DK0_exddhs9_MASK)

#define domainma_EXTD1DK0_exd1dmv9_MASK          (0x100U)
#define domainma_EXTD1DK0_exd1dmv9_SHIFT         (8U)
/*! exd1dmv9 - extdst1_dm_vscaler9
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD1DK0_exd1dmv9(x)            (((uint32_t)(((uint32_t)(x)) << domainma_EXTD1DK0_exd1dmv9_SHIFT)) & domainma_EXTD1DK0_exd1dmv9_MASK)

#define domainma_EXTD1DK0_exddfi9_MASK           (0x200U)
#define domainma_EXTD1DK0_exddfi9_SHIFT          (9U)
/*! exddfi9 - extdst1_dm_filter9
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD1DK0_exddfi9(x)             (((uint32_t)(((uint32_t)(x)) << domainma_EXTD1DK0_exddfi9_SHIFT)) & domainma_EXTD1DK0_exddfi9_MASK)

#define domainma_EXTD1DK0_exd1dc0_MASK           (0x400U)
#define domainma_EXTD1DK0_exd1dc0_SHIFT          (10U)
/*! exd1dc0 - extdst1_dm_constframe0
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD1DK0_exd1dc0(x)             (((uint32_t)(((uint32_t)(x)) << domainma_EXTD1DK0_exd1dc0_SHIFT)) & domainma_EXTD1DK0_exd1dc0_MASK)

#define domainma_EXTD1DK0_exd1dc4_MASK           (0x800U)
#define domainma_EXTD1DK0_exd1dc4_SHIFT          (11U)
/*! exd1dc4 - extdst1_dm_constframe4
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD1DK0_exd1dc4(x)             (((uint32_t)(((uint32_t)(x)) << domainma_EXTD1DK0_exd1dc4_SHIFT)) & domainma_EXTD1DK0_exd1dc4_MASK)

#define domainma_EXTD1DK0_exd1dc1_MASK           (0x1000U)
#define domainma_EXTD1DK0_exd1dc1_SHIFT          (12U)
/*! exd1dc1 - extdst1_dm_constframe1
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD1DK0_exd1dc1(x)             (((uint32_t)(((uint32_t)(x)) << domainma_EXTD1DK0_exd1dc1_SHIFT)) & domainma_EXTD1DK0_exd1dc1_MASK)

#define domainma_EXTD1DK0_exd1dc5_MASK           (0x2000U)
#define domainma_EXTD1DK0_exd1dc5_SHIFT          (13U)
/*! exd1dc5 - extdst1_dm_constframe5
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD1DK0_exd1dc5(x)             (((uint32_t)(((uint32_t)(x)) << domainma_EXTD1DK0_exd1dc5_SHIFT)) & domainma_EXTD1DK0_exd1dc5_MASK)

#define domainma_EXTD1DK0_exd1dlb1_MASK          (0x4000U)
#define domainma_EXTD1DK0_exd1dlb1_SHIFT         (14U)
/*! exd1dlb1 - extdst1_dm_layerblend1
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD1DK0_exd1dlb1(x)            (((uint32_t)(((uint32_t)(x)) << domainma_EXTD1DK0_exd1dlb1_SHIFT)) & domainma_EXTD1DK0_exd1dlb1_MASK)

#define domainma_EXTD1DK0_exd1dlb2_MASK          (0x8000U)
#define domainma_EXTD1DK0_exd1dlb2_SHIFT         (15U)
/*! exd1dlb2 - extdst1_dm_layerblend2
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD1DK0_exd1dlb2(x)            (((uint32_t)(((uint32_t)(x)) << domainma_EXTD1DK0_exd1dlb2_SHIFT)) & domainma_EXTD1DK0_exd1dlb2_MASK)

#define domainma_EXTD1DK0_exd1dlb3_MASK          (0x10000U)
#define domainma_EXTD1DK0_exd1dlb3_SHIFT         (16U)
/*! exd1dlb3 - extdst1_dm_layerblend3
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD1DK0_exd1dlb3(x)            (((uint32_t)(((uint32_t)(x)) << domainma_EXTD1DK0_exd1dlb3_SHIFT)) & domainma_EXTD1DK0_exd1dlb3_MASK)

#define domainma_EXTD1DK0_exdldlb4_MASK          (0x20000U)
#define domainma_EXTD1DK0_exdldlb4_SHIFT         (17U)
/*! exdldlb4 - extdst1_dm_layerblend4
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD1DK0_exdldlb4(x)            (((uint32_t)(((uint32_t)(x)) << domainma_EXTD1DK0_exdldlb4_SHIFT)) & domainma_EXTD1DK0_exdldlb4_MASK)

#define domainma_EXTD1DK0_exd1dlb5_MASK          (0x40000U)
#define domainma_EXTD1DK0_exd1dlb5_SHIFT         (18U)
/*! exd1dlb5 - extdst1_dm_layerblend5
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD1DK0_exd1dlb5(x)            (((uint32_t)(((uint32_t)(x)) << domainma_EXTD1DK0_exd1dlb5_SHIFT)) & domainma_EXTD1DK0_exd1dlb5_MASK)

#define domainma_EXTD1DK0_exd1dfl0_MASK          (0x80000U)
#define domainma_EXTD1DK0_exd1dfl0_SHIFT         (19U)
/*! exd1dfl0 - extdst1_dm_fetchlayer0
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD1DK0_exd1dfl0(x)            (((uint32_t)(((uint32_t)(x)) << domainma_EXTD1DK0_exd1dfl0_SHIFT)) & domainma_EXTD1DK0_exd1dfl0_MASK)

#define domainma_EXTD1DK0_exd1dfl1_MASK          (0x100000U)
#define domainma_EXTD1DK0_exd1dfl1_SHIFT         (20U)
/*! exd1dfl1 - extdst1_dm_fetchlayer1
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD1DK0_exd1dfl1(x)            (((uint32_t)(((uint32_t)(x)) << domainma_EXTD1DK0_exd1dfl1_SHIFT)) & domainma_EXTD1DK0_exd1dfl1_MASK)

#define domainma_EXTD1DK0_exddfy3_MASK           (0x200000U)
#define domainma_EXTD1DK0_exddfy3_SHIFT          (21U)
/*! exddfy3 - extdst1_dm_fetchyuv3
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD1DK0_exddfy3(x)             (((uint32_t)(((uint32_t)(x)) << domainma_EXTD1DK0_exddfy3_SHIFT)) & domainma_EXTD1DK0_exddfy3_MASK)

#define domainma_EXTD1DK0_exddfy0_MASK           (0x400000U)
#define domainma_EXTD1DK0_exddfy0_SHIFT          (22U)
/*! exddfy0 - extdst1_dm_fetchyuv0
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD1DK0_exddfy0(x)             (((uint32_t)(((uint32_t)(x)) << domainma_EXTD1DK0_exddfy0_SHIFT)) & domainma_EXTD1DK0_exddfy0_MASK)

#define domainma_EXTD1DK0_exd1dfe0_MASK          (0x800000U)
#define domainma_EXTD1DK0_exd1dfe0_SHIFT         (23U)
/*! exd1dfe0 - extdst1_dm_fetcheco0
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD1DK0_exd1dfe0(x)            (((uint32_t)(((uint32_t)(x)) << domainma_EXTD1DK0_exd1dfe0_SHIFT)) & domainma_EXTD1DK0_exd1dfe0_MASK)

#define domainma_EXTD1DK0_exddfy1_MASK           (0x1000000U)
#define domainma_EXTD1DK0_exddfy1_SHIFT          (24U)
/*! exddfy1 - extdst1_dm_fetchyuv1
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD1DK0_exddfy1(x)             (((uint32_t)(((uint32_t)(x)) << domainma_EXTD1DK0_exddfy1_SHIFT)) & domainma_EXTD1DK0_exddfy1_MASK)

#define domainma_EXTD1DK0_exd1dfe1_MASK          (0x2000000U)
#define domainma_EXTD1DK0_exd1dfe1_SHIFT         (25U)
/*! exd1dfe1 - extdst1_dm_fetcheco1
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD1DK0_exd1dfe1(x)            (((uint32_t)(((uint32_t)(x)) << domainma_EXTD1DK0_exd1dfe1_SHIFT)) & domainma_EXTD1DK0_exd1dfe1_MASK)

#define domainma_EXTD1DK0_exd1dm4_MASK           (0x4000000U)
#define domainma_EXTD1DK0_exd1dm4_SHIFT          (26U)
/*! exd1dm4 - extdst1_dm_matrix4
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD1DK0_exd1dm4(x)             (((uint32_t)(((uint32_t)(x)) << domainma_EXTD1DK0_exd1dm4_SHIFT)) & domainma_EXTD1DK0_exd1dm4_MASK)

#define domainma_EXTD1DK0_exddhs4_MASK           (0x8000000U)
#define domainma_EXTD1DK0_exddhs4_SHIFT          (27U)
/*! exddhs4 - extdst1_dm_hscaler4
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD1DK0_exddhs4(x)             (((uint32_t)(((uint32_t)(x)) << domainma_EXTD1DK0_exddhs4_SHIFT)) & domainma_EXTD1DK0_exddhs4_MASK)

#define domainma_EXTD1DK0_exd1dmv4_MASK          (0x10000000U)
#define domainma_EXTD1DK0_exd1dmv4_SHIFT         (28U)
/*! exd1dmv4 - extdst1_dm_vscaler4
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD1DK0_exd1dmv4(x)            (((uint32_t)(((uint32_t)(x)) << domainma_EXTD1DK0_exd1dmv4_SHIFT)) & domainma_EXTD1DK0_exd1dmv4_MASK)
/*! @} */

/*! @name EXTD5DK0 - extdst5_domain_mask0 */
/*! @{ */

#define domainma_EXTD5DK0_exd5dmr9_MASK          (0x1U)
#define domainma_EXTD5DK0_exd5dmr9_SHIFT         (0U)
/*! exd5dmr9 - extdst5_dm_rop9
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD5DK0_exd5dmr9(x)            (((uint32_t)(((uint32_t)(x)) << domainma_EXTD5DK0_exd5dmr9_SHIFT)) & domainma_EXTD5DK0_exd5dmr9_MASK)

#define domainma_EXTD5DK0_exd5dc9_MASK           (0x2U)
#define domainma_EXTD5DK0_exd5dc9_SHIFT          (1U)
/*! exd5dc9 - extdst5_dm_clut9
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD5DK0_exd5dc9(x)             (((uint32_t)(((uint32_t)(x)) << domainma_EXTD5DK0_exd5dc9_SHIFT)) & domainma_EXTD5DK0_exd5dc9_MASK)

#define domainma_EXTD5DK0_exd5dm9_MASK           (0x4U)
#define domainma_EXTD5DK0_exd5dm9_SHIFT          (2U)
/*! exd5dm9 - extdst5_dm_matrix9
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD5DK0_exd5dm9(x)             (((uint32_t)(((uint32_t)(x)) << domainma_EXTD5DK0_exd5dm9_SHIFT)) & domainma_EXTD5DK0_exd5dm9_MASK)

#define domainma_EXTD5DK0_exd5db9_MASK           (0x8U)
#define domainma_EXTD5DK0_exd5db9_SHIFT          (3U)
/*! exd5db9 - extdst5_dm_blitblend9
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD5DK0_exd5db9(x)             (((uint32_t)(((uint32_t)(x)) << domainma_EXTD5DK0_exd5db9_SHIFT)) & domainma_EXTD5DK0_exd5db9_MASK)

#define domainma_EXTD5DK0_exd5dfr9_MASK          (0x10U)
#define domainma_EXTD5DK0_exd5dfr9_SHIFT         (4U)
/*! exd5dfr9 - extdst5_dm_fetchrot9
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD5DK0_exd5dfr9(x)            (((uint32_t)(((uint32_t)(x)) << domainma_EXTD5DK0_exd5dfr9_SHIFT)) & domainma_EXTD5DK0_exd5dfr9_MASK)

#define domainma_EXTD5DK0_exd5dfd9_MASK          (0x20U)
#define domainma_EXTD5DK0_exd5dfd9_SHIFT         (5U)
/*! exd5dfd9 - extdst5_dm_fetchdecode9
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD5DK0_exd5dfd9(x)            (((uint32_t)(((uint32_t)(x)) << domainma_EXTD5DK0_exd5dfd9_SHIFT)) & domainma_EXTD5DK0_exd5dfd9_MASK)

#define domainma_EXTD5DK0_exd5dfe9_MASK          (0x40U)
#define domainma_EXTD5DK0_exd5dfe9_SHIFT         (6U)
/*! exd5dfe9 - extdst5_dm_fetcheco9
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD5DK0_exd5dfe9(x)            (((uint32_t)(((uint32_t)(x)) << domainma_EXTD5DK0_exd5dfe9_SHIFT)) & domainma_EXTD5DK0_exd5dfe9_MASK)

#define domainma_EXTD5DK0_exd5dhs9_MASK          (0x80U)
#define domainma_EXTD5DK0_exd5dhs9_SHIFT         (7U)
/*! exd5dhs9 - extdst5_dm_hscaler9
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD5DK0_exd5dhs9(x)            (((uint32_t)(((uint32_t)(x)) << domainma_EXTD5DK0_exd5dhs9_SHIFT)) & domainma_EXTD5DK0_exd5dhs9_MASK)

#define domainma_EXTD5DK0_exd5dms9_MASK          (0x100U)
#define domainma_EXTD5DK0_exd5dms9_SHIFT         (8U)
/*! exd5dms9 - extdst5_dm_vscaler9
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD5DK0_exd5dms9(x)            (((uint32_t)(((uint32_t)(x)) << domainma_EXTD5DK0_exd5dms9_SHIFT)) & domainma_EXTD5DK0_exd5dms9_MASK)

#define domainma_EXTD5DK0_exd5dfi9_MASK          (0x200U)
#define domainma_EXTD5DK0_exd5dfi9_SHIFT         (9U)
/*! exd5dfi9 - extdst5_dm_filter9
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD5DK0_exd5dfi9(x)            (((uint32_t)(((uint32_t)(x)) << domainma_EXTD5DK0_exd5dfi9_SHIFT)) & domainma_EXTD5DK0_exd5dfi9_MASK)

#define domainma_EXTD5DK0_exd5dc0_MASK           (0x400U)
#define domainma_EXTD5DK0_exd5dc0_SHIFT          (10U)
/*! exd5dc0 - extdst5_dm_constframe0
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD5DK0_exd5dc0(x)             (((uint32_t)(((uint32_t)(x)) << domainma_EXTD5DK0_exd5dc0_SHIFT)) & domainma_EXTD5DK0_exd5dc0_MASK)

#define domainma_EXTD5DK0_exd5dc4_MASK           (0x800U)
#define domainma_EXTD5DK0_exd5dc4_SHIFT          (11U)
/*! exd5dc4 - extdst5_dm_constframe4
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD5DK0_exd5dc4(x)             (((uint32_t)(((uint32_t)(x)) << domainma_EXTD5DK0_exd5dc4_SHIFT)) & domainma_EXTD5DK0_exd5dc4_MASK)

#define domainma_EXTD5DK0_exd5dc1_MASK           (0x1000U)
#define domainma_EXTD5DK0_exd5dc1_SHIFT          (12U)
/*! exd5dc1 - extdst5_dm_constframe1
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD5DK0_exd5dc1(x)             (((uint32_t)(((uint32_t)(x)) << domainma_EXTD5DK0_exd5dc1_SHIFT)) & domainma_EXTD5DK0_exd5dc1_MASK)

#define domainma_EXTD5DK0_exd5dc5_MASK           (0x2000U)
#define domainma_EXTD5DK0_exd5dc5_SHIFT          (13U)
/*! exd5dc5 - extdst5_dm_constframe5
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD5DK0_exd5dc5(x)             (((uint32_t)(((uint32_t)(x)) << domainma_EXTD5DK0_exd5dc5_SHIFT)) & domainma_EXTD5DK0_exd5dc5_MASK)

#define domainma_EXTD5DK0_exd5dlb1_MASK          (0x4000U)
#define domainma_EXTD5DK0_exd5dlb1_SHIFT         (14U)
/*! exd5dlb1 - extdst5_dm_layerblend1
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD5DK0_exd5dlb1(x)            (((uint32_t)(((uint32_t)(x)) << domainma_EXTD5DK0_exd5dlb1_SHIFT)) & domainma_EXTD5DK0_exd5dlb1_MASK)

#define domainma_EXTD5DK0_exd5dlb2_MASK          (0x8000U)
#define domainma_EXTD5DK0_exd5dlb2_SHIFT         (15U)
/*! exd5dlb2 - extdst5_dm_layerblend2
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD5DK0_exd5dlb2(x)            (((uint32_t)(((uint32_t)(x)) << domainma_EXTD5DK0_exd5dlb2_SHIFT)) & domainma_EXTD5DK0_exd5dlb2_MASK)

#define domainma_EXTD5DK0_exd5dlb3_MASK          (0x10000U)
#define domainma_EXTD5DK0_exd5dlb3_SHIFT         (16U)
/*! exd5dlb3 - extdst5_dm_layerblend3
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD5DK0_exd5dlb3(x)            (((uint32_t)(((uint32_t)(x)) << domainma_EXTD5DK0_exd5dlb3_SHIFT)) & domainma_EXTD5DK0_exd5dlb3_MASK)

#define domainma_EXTD5DK0_exd5dlb4_MASK          (0x20000U)
#define domainma_EXTD5DK0_exd5dlb4_SHIFT         (17U)
/*! exd5dlb4 - extdst5_dm_layerblend4
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD5DK0_exd5dlb4(x)            (((uint32_t)(((uint32_t)(x)) << domainma_EXTD5DK0_exd5dlb4_SHIFT)) & domainma_EXTD5DK0_exd5dlb4_MASK)

#define domainma_EXTD5DK0_exd5dlb5_MASK          (0x40000U)
#define domainma_EXTD5DK0_exd5dlb5_SHIFT         (18U)
/*! exd5dlb5 - extdst5_dm_layerblend5
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD5DK0_exd5dlb5(x)            (((uint32_t)(((uint32_t)(x)) << domainma_EXTD5DK0_exd5dlb5_SHIFT)) & domainma_EXTD5DK0_exd5dlb5_MASK)

#define domainma_EXTD5DK0_exd5dfl0_MASK          (0x80000U)
#define domainma_EXTD5DK0_exd5dfl0_SHIFT         (19U)
/*! exd5dfl0 - extdst5_dm_fetchlayer0
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD5DK0_exd5dfl0(x)            (((uint32_t)(((uint32_t)(x)) << domainma_EXTD5DK0_exd5dfl0_SHIFT)) & domainma_EXTD5DK0_exd5dfl0_MASK)

#define domainma_EXTD5DK0_exd5dfl1_MASK          (0x100000U)
#define domainma_EXTD5DK0_exd5dfl1_SHIFT         (20U)
/*! exd5dfl1 - extdst5_dm_fetchlayer1
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD5DK0_exd5dfl1(x)            (((uint32_t)(((uint32_t)(x)) << domainma_EXTD5DK0_exd5dfl1_SHIFT)) & domainma_EXTD5DK0_exd5dfl1_MASK)

#define domainma_EXTD5DK0_exd5dfy3_MASK          (0x200000U)
#define domainma_EXTD5DK0_exd5dfy3_SHIFT         (21U)
/*! exd5dfy3 - extdst5_dm_fetchyuv3
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD5DK0_exd5dfy3(x)            (((uint32_t)(((uint32_t)(x)) << domainma_EXTD5DK0_exd5dfy3_SHIFT)) & domainma_EXTD5DK0_exd5dfy3_MASK)

#define domainma_EXTD5DK0_exd5dfy0_MASK          (0x400000U)
#define domainma_EXTD5DK0_exd5dfy0_SHIFT         (22U)
/*! exd5dfy0 - extdst5_dm_fetchyuv0
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD5DK0_exd5dfy0(x)            (((uint32_t)(((uint32_t)(x)) << domainma_EXTD5DK0_exd5dfy0_SHIFT)) & domainma_EXTD5DK0_exd5dfy0_MASK)

#define domainma_EXTD5DK0_exd5dfe0_MASK          (0x800000U)
#define domainma_EXTD5DK0_exd5dfe0_SHIFT         (23U)
/*! exd5dfe0 - extdst5_dm_fetcheco0
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD5DK0_exd5dfe0(x)            (((uint32_t)(((uint32_t)(x)) << domainma_EXTD5DK0_exd5dfe0_SHIFT)) & domainma_EXTD5DK0_exd5dfe0_MASK)

#define domainma_EXTD5DK0_exd5dfy1_MASK          (0x1000000U)
#define domainma_EXTD5DK0_exd5dfy1_SHIFT         (24U)
/*! exd5dfy1 - extdst5_dm_fetchyuv1
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD5DK0_exd5dfy1(x)            (((uint32_t)(((uint32_t)(x)) << domainma_EXTD5DK0_exd5dfy1_SHIFT)) & domainma_EXTD5DK0_exd5dfy1_MASK)

#define domainma_EXTD5DK0_exd5dfe1_MASK          (0x2000000U)
#define domainma_EXTD5DK0_exd5dfe1_SHIFT         (25U)
/*! exd5dfe1 - extdst5_dm_fetcheco1
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD5DK0_exd5dfe1(x)            (((uint32_t)(((uint32_t)(x)) << domainma_EXTD5DK0_exd5dfe1_SHIFT)) & domainma_EXTD5DK0_exd5dfe1_MASK)

#define domainma_EXTD5DK0_exd5dm4_MASK           (0x4000000U)
#define domainma_EXTD5DK0_exd5dm4_SHIFT          (26U)
/*! exd5dm4 - extdst5_dm_matrix4
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD5DK0_exd5dm4(x)             (((uint32_t)(((uint32_t)(x)) << domainma_EXTD5DK0_exd5dm4_SHIFT)) & domainma_EXTD5DK0_exd5dm4_MASK)

#define domainma_EXTD5DK0_exd5dhs4_MASK          (0x8000000U)
#define domainma_EXTD5DK0_exd5dhs4_SHIFT         (27U)
/*! exd5dhs4 - extdst5_dm_hscaler4
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD5DK0_exd5dhs4(x)            (((uint32_t)(((uint32_t)(x)) << domainma_EXTD5DK0_exd5dhs4_SHIFT)) & domainma_EXTD5DK0_exd5dhs4_MASK)

#define domainma_EXTD5DK0_exd5dms4_MASK          (0x10000000U)
#define domainma_EXTD5DK0_exd5dms4_SHIFT         (28U)
/*! exd5dms4 - extdst5_dm_vscaler4
 *  0b0..Module is prohibited.
 *  0b1..Module is allowed.
 */
#define domainma_EXTD5DK0_exd5dms4(x)            (((uint32_t)(((uint32_t)(x)) << domainma_EXTD5DK0_exd5dms4_SHIFT)) & domainma_EXTD5DK0_exd5dms4_MASK)
/*! @} */

/*! @name SEERISDS - SEERIS_Display_Static */
/*! @{ */

#define domainma_SEERISDS_displps_MASK           (0x1U)
#define domainma_SEERISDS_displps_SHIFT          (0U)
/*! displps - display_pipeline_synchronization
 *  0b0..Display pipeline synchronization is disabled
 *  0b1..Display pipeline synchronization is enabled
 */
#define domainma_SEERISDS_displps(x)             (((uint32_t)(((uint32_t)(x)) << domainma_SEERISDS_displps_SHIFT)) & domainma_SEERISDS_displps_MASK)
/*! @} */

/*! @name EXTD0S - extdst0_Static */
/*! @{ */

#define domainma_EXTD0S_exd0isdm_MASK            (0x8000U)
#define domainma_EXTD0S_exd0isdm_SHIFT           (15U)
/*! exd0isdm
 *  0b0..Target Synchronizer
 *  0b1..Initiator Synchronizer
 */
#define domainma_EXTD0S_exd0isdm(x)              (((uint32_t)(((uint32_t)(x)) << domainma_EXTD0S_exd0isdm_SHIFT)) & domainma_EXTD0S_exd0isdm_MASK)
/*! @} */

/*! @name EXTD4S - extdst4_Static */
/*! @{ */

#define domainma_EXTD4S_exd4isdm_MASK            (0x8000U)
#define domainma_EXTD4S_exd4isdm_SHIFT           (15U)
/*! exd4isdm
 *  0b0..Target Synchronizer
 *  0b1..Initiator Synchronizer
 */
#define domainma_EXTD4S_exd4isdm(x)              (((uint32_t)(((uint32_t)(x)) << domainma_EXTD4S_exd4isdm_SHIFT)) & domainma_EXTD4S_exd4isdm_MASK)
/*! @} */

/*! @name EXTD1S - extdst1_Static */
/*! @{ */

#define domainma_EXTD1S_exd1isdm_MASK            (0x8000U)
#define domainma_EXTD1S_exd1isdm_SHIFT           (15U)
/*! exd1isdm
 *  0b0..Target Synchronizer
 *  0b1..Initiator Synchronizer
 */
#define domainma_EXTD1S_exd1isdm(x)              (((uint32_t)(((uint32_t)(x)) << domainma_EXTD1S_exd1isdm_SHIFT)) & domainma_EXTD1S_exd1isdm_MASK)
/*! @} */

/*! @name EXTD5S - extdst5_Static */
/*! @{ */

#define domainma_EXTD5S_exd5isdm_MASK            (0x8000U)
#define domainma_EXTD5S_exd5isdm_SHIFT           (15U)
/*! exd5isdm
 *  0b0..Target Synchronizer
 *  0b1..Initiator Synchronizer
 */
#define domainma_EXTD5S_exd5isdm(x)              (((uint32_t)(((uint32_t)(x)) << domainma_EXTD5S_exd5isdm_SHIFT)) & domainma_EXTD5S_exd5isdm_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group domainma_Register_Masks */


/*!
 * @}
 */ /* end of group domainma_Peripheral_Access_Layer */


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


#endif  /* PERI_DOMAINMA_H_ */

