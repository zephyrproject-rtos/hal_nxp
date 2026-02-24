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
**         CMSIS Peripheral Access Layer for fetchrot
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
 * @file PERI_fetchrot.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for fetchrot
 *
 * CMSIS Peripheral Access Layer for fetchrot
 */

#if !defined(PERI_FETCHROT_H_)
#define PERI_FETCHROT_H_                         /**< Symbol preventing repeated inclusion */

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
   -- fetchrot Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup fetchrot_Peripheral_Access_Layer fetchrot Peripheral Access Layer
 * @{
 */

/** fetchrot - Register Layout Typedef */
typedef struct {
  __O  uint32_t LU;                                /**< LockUnlock, offset: 0x0 */
  __I  uint32_t LOCKS;                             /**< LockStatus, offset: 0x4 */
  __IO uint32_t STATCON;                           /**< StaticControl, offset: 0x8 */
  __IO uint32_t BURBUFMA;                          /**< BurstBufferManagement, offset: 0xC */
  __IO uint32_t RINBSA0;                           /**< RingBufStartAddr0, offset: 0x10 */
  __IO uint32_t RINBSAM0;                          /**< RingBufStartAddrMSB0, offset: 0x14 */
  __IO uint32_t RINBWA0;                           /**< RingBufWrapAddr0, offset: 0x18 */
  __IO uint32_t RINBWAM0;                          /**< RingBufWrapAddrMSB0, offset: 0x1C */
} fetchrot_Type;

/* ----------------------------------------------------------------------------
   -- fetchrot Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup fetchrot_Register_Masks fetchrot Register Masks
 * @{
 */

/*! @name LU - LockUnlock */
/*! @{ */

#define fetchrot_LU_LkUn_MASK                    (0xFFFFFFFFU)
#define fetchrot_LU_LkUn_SHIFT                   (0U)
/*! LkUn - LockUnlock
 *  0b01010110010100011111011101100011..Decrements the unlock counter. When the counter value is null, lock protection is active. Reset counter value is 1.
 *  0b01101001000111011011100100110110..Increments the unlock counter. Max allowed value is 15.
 *  0b10101110111010010101110011011100..Enables privilege protection. Disabled after reset.
 *  0b10110101111000100100011001101110..Disables privilege protection.
 *  0b11111011111010001011000111100110..Freezes current protection status. Writing keys to this register has no more effect until reset.
 */
#define fetchrot_LU_LkUn(x)                      (((uint32_t)(((uint32_t)(x)) << fetchrot_LU_LkUn_SHIFT)) & fetchrot_LU_LkUn_MASK)
/*! @} */

/*! @name LOCKS - LockStatus */
/*! @{ */

#define fetchrot_LOCKS_LkSus_MASK                (0x1U)
#define fetchrot_LOCKS_LkSus_SHIFT               (0U)
/*! LkSus - LockStatus */
#define fetchrot_LOCKS_LkSus(x)                  (((uint32_t)(((uint32_t)(x)) << fetchrot_LOCKS_LkSus_SHIFT)) & fetchrot_LOCKS_LkSus_MASK)

#define fetchrot_LOCKS_PriSt_MASK                (0x10U)
#define fetchrot_LOCKS_PriSt_SHIFT               (4U)
/*! PriSt - PrivilegeStatus */
#define fetchrot_LOCKS_PriSt(x)                  (((uint32_t)(((uint32_t)(x)) << fetchrot_LOCKS_PriSt_SHIFT)) & fetchrot_LOCKS_PriSt_MASK)

#define fetchrot_LOCKS_FreezeS_MASK              (0x100U)
#define fetchrot_LOCKS_FreezeS_SHIFT             (8U)
/*! FreezeS - FreezeStatus */
#define fetchrot_LOCKS_FreezeS(x)                (((uint32_t)(((uint32_t)(x)) << fetchrot_LOCKS_FreezeS_SHIFT)) & fetchrot_LOCKS_FreezeS_MASK)
/*! @} */

/*! @name STATCON - StaticControl */
/*! @{ */

#define fetchrot_STATCON_ShdEn_MASK              (0x1U)
#define fetchrot_STATCON_ShdEn_SHIFT             (0U)
/*! ShdEn - ShdEn */
#define fetchrot_STATCON_ShdEn(x)                (((uint32_t)(((uint32_t)(x)) << fetchrot_STATCON_ShdEn_SHIFT)) & fetchrot_STATCON_ShdEn_MASK)

#define fetchrot_STATCON_BaAdSel_MASK            (0x10U)
#define fetchrot_STATCON_BaAdSel_SHIFT           (4U)
/*! BaAdSel - BaseAddressSelect
 *  0b0..Use Baseaddress mechanism form current fetch unit.
 *  0b1..Use Baseaddress from external source (depends on system, e.g. from store unit).
 */
#define fetchrot_STATCON_BaAdSel(x)              (((uint32_t)(((uint32_t)(x)) << fetchrot_STATCON_BaAdSel_SHIFT)) & fetchrot_STATCON_BaAdSel_MASK)
/*! @} */

/*! @name BURBUFMA - BurstBufferManagement */
/*! @{ */

#define fetchrot_BURBUFMA_SetNumBu_MASK          (0xFFU)
#define fetchrot_BURBUFMA_SetNumBu_SHIFT         (0U)
/*! SetNumBu - SetNumBuffers */
#define fetchrot_BURBUFMA_SetNumBu(x)            (((uint32_t)(((uint32_t)(x)) << fetchrot_BURBUFMA_SetNumBu_SHIFT)) & fetchrot_BURBUFMA_SetNumBu_MASK)

#define fetchrot_BURBUFMA_SetBL_MASK             (0x1F00U)
#define fetchrot_BURBUFMA_SetBL_SHIFT            (8U)
/*! SetBL - SetBurstLength */
#define fetchrot_BURBUFMA_SetBL(x)               (((uint32_t)(((uint32_t)(x)) << fetchrot_BURBUFMA_SetBL_SHIFT)) & fetchrot_BURBUFMA_SetBL_MASK)

#define fetchrot_BURBUFMA_SetMaxBL_MASK          (0x1FE000U)
#define fetchrot_BURBUFMA_SetMaxBL_SHIFT         (13U)
/*! SetMaxBL - SetMaxBurstLength */
#define fetchrot_BURBUFMA_SetMaxBL(x)            (((uint32_t)(((uint32_t)(x)) << fetchrot_BURBUFMA_SetMaxBL_SHIFT)) & fetchrot_BURBUFMA_SetMaxBL_MASK)

#define fetchrot_BURBUFMA_CombTim_MASK           (0x1FE00000U)
#define fetchrot_BURBUFMA_CombTim_SHIFT          (21U)
/*! CombTim - CombinerTimeout */
#define fetchrot_BURBUFMA_CombTim(x)             (((uint32_t)(((uint32_t)(x)) << fetchrot_BURBUFMA_CombTim_SHIFT)) & fetchrot_BURBUFMA_CombTim_MASK)

#define fetchrot_BURBUFMA_CombTEn_MASK           (0x20000000U)
#define fetchrot_BURBUFMA_CombTEn_SHIFT          (29U)
/*! CombTEn - CombinerTimeout_Enable */
#define fetchrot_BURBUFMA_CombTEn(x)             (((uint32_t)(((uint32_t)(x)) << fetchrot_BURBUFMA_CombTEn_SHIFT)) & fetchrot_BURBUFMA_CombTEn_MASK)

#define fetchrot_BURBUFMA_CombLFEn_MASK          (0x40000000U)
#define fetchrot_BURBUFMA_CombLFEn_SHIFT         (30U)
/*! CombLFEn - CombinerLineFlush_Enable */
#define fetchrot_BURBUFMA_CombLFEn(x)            (((uint32_t)(((uint32_t)(x)) << fetchrot_BURBUFMA_CombLFEn_SHIFT)) & fetchrot_BURBUFMA_CombLFEn_MASK)

#define fetchrot_BURBUFMA_LineMode_MASK          (0x80000000U)
#define fetchrot_BURBUFMA_LineMode_SHIFT         (31U)
/*! LineMode - LineMode
 *  0b0..Mandatory setting for operation in the Display Controller. Works also for Blit Engine with marginal performance impact.
 *  0b1..Recommended setting for operation in the Blit Engine.
 */
#define fetchrot_BURBUFMA_LineMode(x)            (((uint32_t)(((uint32_t)(x)) << fetchrot_BURBUFMA_LineMode_SHIFT)) & fetchrot_BURBUFMA_LineMode_MASK)
/*! @} */

/*! @name RINBSA0 - RingBufStartAddr0 */
/*! @{ */

#define fetchrot_RINBSA0_RBStAd0_MASK            (0xFFFFFFFFU)
#define fetchrot_RINBSA0_RBStAd0_SHIFT           (0U)
/*! RBStAd0 - RingBufStartAddr0 */
#define fetchrot_RINBSA0_RBStAd0(x)              (((uint32_t)(((uint32_t)(x)) << fetchrot_RINBSA0_RBStAd0_SHIFT)) & fetchrot_RINBSA0_RBStAd0_MASK)
/*! @} */

/*! @name RINBSAM0 - RingBufStartAddrMSB0 */
/*! @{ */

#define fetchrot_RINBSAM0_RBStAdM0_MASK          (0xFFU)
#define fetchrot_RINBSAM0_RBStAdM0_SHIFT         (0U)
/*! RBStAdM0 - RingBufStartAddrMSB0 */
#define fetchrot_RINBSAM0_RBStAdM0(x)            (((uint32_t)(((uint32_t)(x)) << fetchrot_RINBSAM0_RBStAdM0_SHIFT)) & fetchrot_RINBSAM0_RBStAdM0_MASK)
/*! @} */

/*! @name RINBWA0 - RingBufWrapAddr0 */
/*! @{ */

#define fetchrot_RINBWA0_RBWrAd0_MASK            (0xFFFFFFFFU)
#define fetchrot_RINBWA0_RBWrAd0_SHIFT           (0U)
/*! RBWrAd0 - RingBufWrapAddr0 */
#define fetchrot_RINBWA0_RBWrAd0(x)              (((uint32_t)(((uint32_t)(x)) << fetchrot_RINBWA0_RBWrAd0_SHIFT)) & fetchrot_RINBWA0_RBWrAd0_MASK)
/*! @} */

/*! @name RINBWAM0 - RingBufWrapAddrMSB0 */
/*! @{ */

#define fetchrot_RINBWAM0_RBWrAdM0_MASK          (0xFFU)
#define fetchrot_RINBWAM0_RBWrAdM0_SHIFT         (0U)
/*! RBWrAdM0 - RingBufWrapAddrMSB0 */
#define fetchrot_RINBWAM0_RBWrAdM0(x)            (((uint32_t)(((uint32_t)(x)) << fetchrot_RINBWAM0_RBWrAdM0_SHIFT)) & fetchrot_RINBWAM0_RBWrAdM0_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group fetchrot_Register_Masks */


/*!
 * @}
 */ /* end of group fetchrot_Peripheral_Access_Layer */


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


#endif  /* PERI_FETCHROT_H_ */

