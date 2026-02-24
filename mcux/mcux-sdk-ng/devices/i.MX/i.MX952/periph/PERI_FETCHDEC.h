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
**         CMSIS Peripheral Access Layer for fetchdec
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
 * @file PERI_fetchdec.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for fetchdec
 *
 * CMSIS Peripheral Access Layer for fetchdec
 */

#if !defined(PERI_FETCHDEC_H_)
#define PERI_FETCHDEC_H_                         /**< Symbol preventing repeated inclusion */

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
   -- fetchdec Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup fetchdec_Peripheral_Access_Layer fetchdec Peripheral Access Layer
 * @{
 */

/** fetchdec - Register Layout Typedef */
typedef struct {
  __O  uint32_t LU;                                /**< LockUnlock, offset: 0x0 */
  __I  uint32_t LOCKS;                             /**< LockStatus, offset: 0x4 */
  __IO uint32_t STATCON;                           /**< StaticControl, offset: 0x8 */
  __IO uint32_t BURBUFMA;                          /**< BurstBufferManagement, offset: 0xC */
  __IO uint32_t RINBSA0;                           /**< RingBufStartAddr0, offset: 0x10 */
  __IO uint32_t RINBSAM0;                          /**< RingBufStartAddrMSB0, offset: 0x14 */
  __IO uint32_t RINBWA0;                           /**< RingBufWrapAddr0, offset: 0x18 */
  __IO uint32_t RINBWAM0;                          /**< RingBufWrapAddrMSB0, offset: 0x1C */
  __IO uint32_t FRAP0;                             /**< FrameProperties0, offset: 0x20 */
} fetchdec_Type;

/* ----------------------------------------------------------------------------
   -- fetchdec Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup fetchdec_Register_Masks fetchdec Register Masks
 * @{
 */

/*! @name LU - LockUnlock */
/*! @{ */

#define fetchdec_LU_LkUn_MASK                    (0xFFFFFFFFU)
#define fetchdec_LU_LkUn_SHIFT                   (0U)
/*! LkUn - LockUnlock
 *  0b01010110010100011111011101100011..Decrements the unlock counter. When the counter value is null, lock protection is active. Reset counter value is 1.
 *  0b01101001000111011011100100110110..Increments the unlock counter. Max allowed value is 15.
 *  0b10101110111010010101110011011100..Enables privilege protection. Disabled after reset.
 *  0b10110101111000100100011001101110..Disables privilege protection.
 *  0b11111011111010001011000111100110..Freezes current protection status. Writing keys to this register has no more effect until reset.
 */
#define fetchdec_LU_LkUn(x)                      (((uint32_t)(((uint32_t)(x)) << fetchdec_LU_LkUn_SHIFT)) & fetchdec_LU_LkUn_MASK)
/*! @} */

/*! @name LOCKS - LockStatus */
/*! @{ */

#define fetchdec_LOCKS_LkSus_MASK                (0x1U)
#define fetchdec_LOCKS_LkSus_SHIFT               (0U)
/*! LkSus - LockStatus */
#define fetchdec_LOCKS_LkSus(x)                  (((uint32_t)(((uint32_t)(x)) << fetchdec_LOCKS_LkSus_SHIFT)) & fetchdec_LOCKS_LkSus_MASK)

#define fetchdec_LOCKS_PriSt_MASK                (0x10U)
#define fetchdec_LOCKS_PriSt_SHIFT               (4U)
/*! PriSt - PrivilegeStatus */
#define fetchdec_LOCKS_PriSt(x)                  (((uint32_t)(((uint32_t)(x)) << fetchdec_LOCKS_PriSt_SHIFT)) & fetchdec_LOCKS_PriSt_MASK)

#define fetchdec_LOCKS_FreezeS_MASK              (0x100U)
#define fetchdec_LOCKS_FreezeS_SHIFT             (8U)
/*! FreezeS - FreezeStatus */
#define fetchdec_LOCKS_FreezeS(x)                (((uint32_t)(((uint32_t)(x)) << fetchdec_LOCKS_FreezeS_SHIFT)) & fetchdec_LOCKS_FreezeS_MASK)
/*! @} */

/*! @name STATCON - StaticControl */
/*! @{ */

#define fetchdec_STATCON_ShdEn_MASK              (0x1U)
#define fetchdec_STATCON_ShdEn_SHIFT             (0U)
/*! ShdEn - ShdEn */
#define fetchdec_STATCON_ShdEn(x)                (((uint32_t)(((uint32_t)(x)) << fetchdec_STATCON_ShdEn_SHIFT)) & fetchdec_STATCON_ShdEn_MASK)
/*! @} */

/*! @name BURBUFMA - BurstBufferManagement */
/*! @{ */

#define fetchdec_BURBUFMA_SetNumBu_MASK          (0xFFU)
#define fetchdec_BURBUFMA_SetNumBu_SHIFT         (0U)
/*! SetNumBu - SetNumBuffers */
#define fetchdec_BURBUFMA_SetNumBu(x)            (((uint32_t)(((uint32_t)(x)) << fetchdec_BURBUFMA_SetNumBu_SHIFT)) & fetchdec_BURBUFMA_SetNumBu_MASK)

#define fetchdec_BURBUFMA_SetBL_MASK             (0x1F00U)
#define fetchdec_BURBUFMA_SetBL_SHIFT            (8U)
/*! SetBL - SetBurstLength */
#define fetchdec_BURBUFMA_SetBL(x)               (((uint32_t)(((uint32_t)(x)) << fetchdec_BURBUFMA_SetBL_SHIFT)) & fetchdec_BURBUFMA_SetBL_MASK)

#define fetchdec_BURBUFMA_SetMaxBL_MASK          (0x1FE000U)
#define fetchdec_BURBUFMA_SetMaxBL_SHIFT         (13U)
/*! SetMaxBL - SetMaxBurstLength */
#define fetchdec_BURBUFMA_SetMaxBL(x)            (((uint32_t)(((uint32_t)(x)) << fetchdec_BURBUFMA_SetMaxBL_SHIFT)) & fetchdec_BURBUFMA_SetMaxBL_MASK)

#define fetchdec_BURBUFMA_CombTim_MASK           (0x1FE00000U)
#define fetchdec_BURBUFMA_CombTim_SHIFT          (21U)
/*! CombTim - CombinerTimeout */
#define fetchdec_BURBUFMA_CombTim(x)             (((uint32_t)(((uint32_t)(x)) << fetchdec_BURBUFMA_CombTim_SHIFT)) & fetchdec_BURBUFMA_CombTim_MASK)

#define fetchdec_BURBUFMA_CombTEn_MASK           (0x20000000U)
#define fetchdec_BURBUFMA_CombTEn_SHIFT          (29U)
/*! CombTEn - CombinerTimeout_Enable */
#define fetchdec_BURBUFMA_CombTEn(x)             (((uint32_t)(((uint32_t)(x)) << fetchdec_BURBUFMA_CombTEn_SHIFT)) & fetchdec_BURBUFMA_CombTEn_MASK)

#define fetchdec_BURBUFMA_CombLFEn_MASK          (0x40000000U)
#define fetchdec_BURBUFMA_CombLFEn_SHIFT         (30U)
/*! CombLFEn - CombinerLineFlush_Enable */
#define fetchdec_BURBUFMA_CombLFEn(x)            (((uint32_t)(((uint32_t)(x)) << fetchdec_BURBUFMA_CombLFEn_SHIFT)) & fetchdec_BURBUFMA_CombLFEn_MASK)
/*! @} */

/*! @name RINBSA0 - RingBufStartAddr0 */
/*! @{ */

#define fetchdec_RINBSA0_RBStAd0_MASK            (0xFFFFFFFFU)
#define fetchdec_RINBSA0_RBStAd0_SHIFT           (0U)
/*! RBStAd0 - RingBufStartAddr0 */
#define fetchdec_RINBSA0_RBStAd0(x)              (((uint32_t)(((uint32_t)(x)) << fetchdec_RINBSA0_RBStAd0_SHIFT)) & fetchdec_RINBSA0_RBStAd0_MASK)
/*! @} */

/*! @name RINBSAM0 - RingBufStartAddrMSB0 */
/*! @{ */

#define fetchdec_RINBSAM0_RBStAdM0_MASK          (0xFFU)
#define fetchdec_RINBSAM0_RBStAdM0_SHIFT         (0U)
/*! RBStAdM0 - RingBufStartAddrMSB0 */
#define fetchdec_RINBSAM0_RBStAdM0(x)            (((uint32_t)(((uint32_t)(x)) << fetchdec_RINBSAM0_RBStAdM0_SHIFT)) & fetchdec_RINBSAM0_RBStAdM0_MASK)
/*! @} */

/*! @name RINBWA0 - RingBufWrapAddr0 */
/*! @{ */

#define fetchdec_RINBWA0_RBWrAd0_MASK            (0xFFFFFFFFU)
#define fetchdec_RINBWA0_RBWrAd0_SHIFT           (0U)
/*! RBWrAd0 - RingBufWrapAddr0 */
#define fetchdec_RINBWA0_RBWrAd0(x)              (((uint32_t)(((uint32_t)(x)) << fetchdec_RINBWA0_RBWrAd0_SHIFT)) & fetchdec_RINBWA0_RBWrAd0_MASK)
/*! @} */

/*! @name RINBWAM0 - RingBufWrapAddrMSB0 */
/*! @{ */

#define fetchdec_RINBWAM0_RBWrAdM0_MASK          (0xFFU)
#define fetchdec_RINBWAM0_RBWrAdM0_SHIFT         (0U)
/*! RBWrAdM0 - RingBufWrapAddrMSB0 */
#define fetchdec_RINBWAM0_RBWrAdM0(x)            (((uint32_t)(((uint32_t)(x)) << fetchdec_RINBWAM0_RBWrAdM0_SHIFT)) & fetchdec_RINBWAM0_RBWrAdM0_MASK)
/*! @} */

/*! @name FRAP0 - FrameProperties0 */
/*! @{ */

#define fetchdec_FRAP0_FieldId0_MASK             (0x1U)
#define fetchdec_FRAP0_FieldId0_SHIFT            (0U)
/*! FieldId0 - FieldId0 */
#define fetchdec_FRAP0_FieldId0(x)               (((uint32_t)(((uint32_t)(x)) << fetchdec_FRAP0_FieldId0_SHIFT)) & fetchdec_FRAP0_FieldId0_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group fetchdec_Register_Masks */


/*!
 * @}
 */ /* end of group fetchdec_Peripheral_Access_Layer */


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


#endif  /* PERI_FETCHDEC_H_ */

