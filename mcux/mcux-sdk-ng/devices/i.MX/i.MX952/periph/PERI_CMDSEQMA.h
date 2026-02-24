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
**         CMSIS Peripheral Access Layer for cmdseqma
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
 * @file PERI_cmdseqma.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for cmdseqma
 *
 * CMSIS Peripheral Access Layer for cmdseqma
 */

#if !defined(PERI_CMDSEQMA_H_)
#define PERI_CMDSEQMA_H_                         /**< Symbol preventing repeated inclusion */

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
   -- cmdseqma Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup cmdseqma_Peripheral_Access_Layer cmdseqma Peripheral Access Layer
 * @{
 */

/** cmdseqma - Register Layout Typedef */
typedef struct {
  __O  uint32_t MAKLKUNL;                          /**< MaskLockUnlock, offset: 0x0 */
  __I  uint32_t MASKLS;                            /**< MaskLockStatus, offset: 0x4 */
  __IO uint32_t CMDACMS0;                          /**< cmdseq_access_mask0, offset: 0x8 */
  __IO uint32_t CMDACMS1;                          /**< cmdseq_access_mask1, offset: 0xC */
} cmdseqma_Type;

/* ----------------------------------------------------------------------------
   -- cmdseqma Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup cmdseqma_Register_Masks cmdseqma Register Masks
 * @{
 */

/*! @name MAKLKUNL - MaskLockUnlock */
/*! @{ */

#define cmdseqma_MAKLKUNL_MakLkUnl_MASK          (0xFFFFFFFFU)
#define cmdseqma_MAKLKUNL_MakLkUnl_SHIFT         (0U)
/*! MakLkUnl - MaskLockUnlock
 *  0b01010110010100011111011101100011..Decrements the unlock counter. When the counter value is null, lock protection is active. Reset counter value is 1.
 *  0b01101001000111011011100100110110..Increments the unlock counter. Max allowed value is 15.
 *  0b10101110111010010101110011011100..Enables privilege protection. Disabled after reset.
 *  0b10110101111000100100011001101110..Disables privilege protection.
 *  0b11111011111010001011000111100110..Freezes current protection status. Writing keys to this register has no more effect until reset.
 */
#define cmdseqma_MAKLKUNL_MakLkUnl(x)            (((uint32_t)(((uint32_t)(x)) << cmdseqma_MAKLKUNL_MakLkUnl_SHIFT)) & cmdseqma_MAKLKUNL_MakLkUnl_MASK)
/*! @} */

/*! @name MASKLS - MaskLockStatus */
/*! @{ */

#define cmdseqma_MASKLS_MakLkS_MASK              (0x1U)
#define cmdseqma_MASKLS_MakLkS_SHIFT             (0U)
/*! MakLkS - MaskLockStatus */
#define cmdseqma_MASKLS_MakLkS(x)                (((uint32_t)(((uint32_t)(x)) << cmdseqma_MASKLS_MakLkS_SHIFT)) & cmdseqma_MASKLS_MakLkS_MASK)

#define cmdseqma_MASKLS_MakPS_MASK               (0x10U)
#define cmdseqma_MASKLS_MakPS_SHIFT              (4U)
/*! MakPS - MaskPrivilegeStatus */
#define cmdseqma_MASKLS_MakPS(x)                 (((uint32_t)(((uint32_t)(x)) << cmdseqma_MASKLS_MakPS_SHIFT)) & cmdseqma_MASKLS_MakPS_MASK)

#define cmdseqma_MASKLS_MakFreS_MASK             (0x100U)
#define cmdseqma_MASKLS_MakFreS_SHIFT            (8U)
/*! MakFreS - MaskFreezeStatus */
#define cmdseqma_MASKLS_MakFreS(x)               (((uint32_t)(((uint32_t)(x)) << cmdseqma_MASKLS_MakFreS_SHIFT)) & cmdseqma_MASKLS_MakFreS_MASK)
/*! @} */

/*! @name CMDACMS0 - cmdseq_access_mask0 */
/*! @{ */

#define cmdseqma_CMDACMS0_csacmas0_MASK          (0xFFFFFFFFU)
#define cmdseqma_CMDACMS0_csacmas0_SHIFT         (0U)
/*! csacmas0 - cs_access_mask0 */
#define cmdseqma_CMDACMS0_csacmas0(x)            (((uint32_t)(((uint32_t)(x)) << cmdseqma_CMDACMS0_csacmas0_SHIFT)) & cmdseqma_CMDACMS0_csacmas0_MASK)
/*! @} */

/*! @name CMDACMS1 - cmdseq_access_mask1 */
/*! @{ */

#define cmdseqma_CMDACMS1_csacmas1_MASK          (0xFFFFFFFFU)
#define cmdseqma_CMDACMS1_csacmas1_SHIFT         (0U)
/*! csacmas1 - cs_access_mask1 */
#define cmdseqma_CMDACMS1_csacmas1(x)            (((uint32_t)(((uint32_t)(x)) << cmdseqma_CMDACMS1_csacmas1_SHIFT)) & cmdseqma_CMDACMS1_csacmas1_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group cmdseqma_Register_Masks */


/*!
 * @}
 */ /* end of group cmdseqma_Peripheral_Access_Layer */


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


#endif  /* PERI_CMDSEQMA_H_ */

