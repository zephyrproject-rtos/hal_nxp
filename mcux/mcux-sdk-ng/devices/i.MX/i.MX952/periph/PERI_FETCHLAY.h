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
**         CMSIS Peripheral Access Layer for fetchlay
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
 * @file PERI_fetchlay.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for fetchlay
 *
 * CMSIS Peripheral Access Layer for fetchlay
 */

#if !defined(PERI_FETCHLAY_H_)
#define PERI_FETCHLAY_H_                         /**< Symbol preventing repeated inclusion */

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
   -- fetchlay Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup fetchlay_Peripheral_Access_Layer fetchlay Peripheral Access Layer
 * @{
 */

/** fetchlay - Register Layout Typedef */
typedef struct {
  __O  uint32_t LU;                                /**< LockUnlock, offset: 0x0 */
  __I  uint32_t LOCKS;                             /**< LockStatus, offset: 0x4 */
  __IO uint32_t STATCON;                           /**< StaticControl, offset: 0x8 */
  __IO uint32_t SHDLRCON;                          /**< ShdLdReqControl, offset: 0xC */
  __IO uint32_t BURBUFMA;                          /**< BurstBufferManagement, offset: 0x10 */
} fetchlay_Type;

/* ----------------------------------------------------------------------------
   -- fetchlay Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup fetchlay_Register_Masks fetchlay Register Masks
 * @{
 */

/*! @name LU - LockUnlock */
/*! @{ */

#define fetchlay_LU_LkUn_MASK                    (0xFFFFFFFFU)
#define fetchlay_LU_LkUn_SHIFT                   (0U)
/*! LkUn - LockUnlock
 *  0b01010110010100011111011101100011..Decrements the unlock counter. When the counter value is null, lock protection is active. Reset counter value is 1.
 *  0b01101001000111011011100100110110..Increments the unlock counter. Max allowed value is 15.
 *  0b10101110111010010101110011011100..Enables privilege protection. Disabled after reset.
 *  0b10110101111000100100011001101110..Disables privilege protection.
 *  0b11111011111010001011000111100110..Freezes current protection status. Writing keys to this register has no more effect until reset.
 */
#define fetchlay_LU_LkUn(x)                      (((uint32_t)(((uint32_t)(x)) << fetchlay_LU_LkUn_SHIFT)) & fetchlay_LU_LkUn_MASK)
/*! @} */

/*! @name LOCKS - LockStatus */
/*! @{ */

#define fetchlay_LOCKS_LkSus_MASK                (0x1U)
#define fetchlay_LOCKS_LkSus_SHIFT               (0U)
/*! LkSus - LockStatus */
#define fetchlay_LOCKS_LkSus(x)                  (((uint32_t)(((uint32_t)(x)) << fetchlay_LOCKS_LkSus_SHIFT)) & fetchlay_LOCKS_LkSus_MASK)

#define fetchlay_LOCKS_PriSt_MASK                (0x10U)
#define fetchlay_LOCKS_PriSt_SHIFT               (4U)
/*! PriSt - PrivilegeStatus */
#define fetchlay_LOCKS_PriSt(x)                  (((uint32_t)(((uint32_t)(x)) << fetchlay_LOCKS_PriSt_SHIFT)) & fetchlay_LOCKS_PriSt_MASK)

#define fetchlay_LOCKS_FreezeS_MASK              (0x100U)
#define fetchlay_LOCKS_FreezeS_SHIFT             (8U)
/*! FreezeS - FreezeStatus */
#define fetchlay_LOCKS_FreezeS(x)                (((uint32_t)(((uint32_t)(x)) << fetchlay_LOCKS_FreezeS_SHIFT)) & fetchlay_LOCKS_FreezeS_MASK)
/*! @} */

/*! @name STATCON - StaticControl */
/*! @{ */

#define fetchlay_STATCON_ShdEn_MASK              (0x1U)
#define fetchlay_STATCON_ShdEn_SHIFT             (0U)
/*! ShdEn - ShdEn */
#define fetchlay_STATCON_ShdEn(x)                (((uint32_t)(((uint32_t)(x)) << fetchlay_STATCON_ShdEn_SHIFT)) & fetchlay_STATCON_ShdEn_MASK)
/*! @} */

/*! @name SHDLRCON - ShdLdReqControl */
/*! @{ */

#define fetchlay_SHDLRCON_SdLdRqS0_MASK          (0x1U)
#define fetchlay_SHDLRCON_SdLdRqS0_SHIFT         (0U)
/*! SdLdRqS0 - ShdLdReqSticky0 */
#define fetchlay_SHDLRCON_SdLdRqS0(x)            (((uint32_t)(((uint32_t)(x)) << fetchlay_SHDLRCON_SdLdRqS0_SHIFT)) & fetchlay_SHDLRCON_SdLdRqS0_MASK)

#define fetchlay_SHDLRCON_SdLdRqS1_MASK          (0x2U)
#define fetchlay_SHDLRCON_SdLdRqS1_SHIFT         (1U)
/*! SdLdRqS1 - ShdLdReqSticky1 */
#define fetchlay_SHDLRCON_SdLdRqS1(x)            (((uint32_t)(((uint32_t)(x)) << fetchlay_SHDLRCON_SdLdRqS1_SHIFT)) & fetchlay_SHDLRCON_SdLdRqS1_MASK)

#define fetchlay_SHDLRCON_SdLdRqS2_MASK          (0x4U)
#define fetchlay_SHDLRCON_SdLdRqS2_SHIFT         (2U)
/*! SdLdRqS2 - ShdLdReqSticky2 */
#define fetchlay_SHDLRCON_SdLdRqS2(x)            (((uint32_t)(((uint32_t)(x)) << fetchlay_SHDLRCON_SdLdRqS2_SHIFT)) & fetchlay_SHDLRCON_SdLdRqS2_MASK)

#define fetchlay_SHDLRCON_SdLdRqS3_MASK          (0x8U)
#define fetchlay_SHDLRCON_SdLdRqS3_SHIFT         (3U)
/*! SdLdRqS3 - ShdLdReqSticky3 */
#define fetchlay_SHDLRCON_SdLdRqS3(x)            (((uint32_t)(((uint32_t)(x)) << fetchlay_SHDLRCON_SdLdRqS3_SHIFT)) & fetchlay_SHDLRCON_SdLdRqS3_MASK)

#define fetchlay_SHDLRCON_SdLdRqS4_MASK          (0x10U)
#define fetchlay_SHDLRCON_SdLdRqS4_SHIFT         (4U)
/*! SdLdRqS4 - ShdLdReqSticky4 */
#define fetchlay_SHDLRCON_SdLdRqS4(x)            (((uint32_t)(((uint32_t)(x)) << fetchlay_SHDLRCON_SdLdRqS4_SHIFT)) & fetchlay_SHDLRCON_SdLdRqS4_MASK)

#define fetchlay_SHDLRCON_SdLdRqS5_MASK          (0x20U)
#define fetchlay_SHDLRCON_SdLdRqS5_SHIFT         (5U)
/*! SdLdRqS5 - ShdLdReqSticky5 */
#define fetchlay_SHDLRCON_SdLdRqS5(x)            (((uint32_t)(((uint32_t)(x)) << fetchlay_SHDLRCON_SdLdRqS5_SHIFT)) & fetchlay_SHDLRCON_SdLdRqS5_MASK)

#define fetchlay_SHDLRCON_SdLdRqS6_MASK          (0x40U)
#define fetchlay_SHDLRCON_SdLdRqS6_SHIFT         (6U)
/*! SdLdRqS6 - ShdLdReqSticky6 */
#define fetchlay_SHDLRCON_SdLdRqS6(x)            (((uint32_t)(((uint32_t)(x)) << fetchlay_SHDLRCON_SdLdRqS6_SHIFT)) & fetchlay_SHDLRCON_SdLdRqS6_MASK)

#define fetchlay_SHDLRCON_SdLdRqS7_MASK          (0x80U)
#define fetchlay_SHDLRCON_SdLdRqS7_SHIFT         (7U)
/*! SdLdRqS7 - ShdLdReqSticky7 */
#define fetchlay_SHDLRCON_SdLdRqS7(x)            (((uint32_t)(((uint32_t)(x)) << fetchlay_SHDLRCON_SdLdRqS7_SHIFT)) & fetchlay_SHDLRCON_SdLdRqS7_MASK)
/*! @} */

/*! @name BURBUFMA - BurstBufferManagement */
/*! @{ */

#define fetchlay_BURBUFMA_SetNumBu_MASK          (0xFFU)
#define fetchlay_BURBUFMA_SetNumBu_SHIFT         (0U)
/*! SetNumBu - SetNumBuffers */
#define fetchlay_BURBUFMA_SetNumBu(x)            (((uint32_t)(((uint32_t)(x)) << fetchlay_BURBUFMA_SetNumBu_SHIFT)) & fetchlay_BURBUFMA_SetNumBu_MASK)

#define fetchlay_BURBUFMA_SetBL_MASK             (0x1F00U)
#define fetchlay_BURBUFMA_SetBL_SHIFT            (8U)
/*! SetBL - SetBurstLength */
#define fetchlay_BURBUFMA_SetBL(x)               (((uint32_t)(((uint32_t)(x)) << fetchlay_BURBUFMA_SetBL_SHIFT)) & fetchlay_BURBUFMA_SetBL_MASK)

#define fetchlay_BURBUFMA_SetMaxBL_MASK          (0x1FE000U)
#define fetchlay_BURBUFMA_SetMaxBL_SHIFT         (13U)
/*! SetMaxBL - SetMaxBurstLength */
#define fetchlay_BURBUFMA_SetMaxBL(x)            (((uint32_t)(((uint32_t)(x)) << fetchlay_BURBUFMA_SetMaxBL_SHIFT)) & fetchlay_BURBUFMA_SetMaxBL_MASK)

#define fetchlay_BURBUFMA_CombTim_MASK           (0x1FE00000U)
#define fetchlay_BURBUFMA_CombTim_SHIFT          (21U)
/*! CombTim - CombinerTimeout */
#define fetchlay_BURBUFMA_CombTim(x)             (((uint32_t)(((uint32_t)(x)) << fetchlay_BURBUFMA_CombTim_SHIFT)) & fetchlay_BURBUFMA_CombTim_MASK)

#define fetchlay_BURBUFMA_CombTEn_MASK           (0x20000000U)
#define fetchlay_BURBUFMA_CombTEn_SHIFT          (29U)
/*! CombTEn - CombinerTimeout_Enable */
#define fetchlay_BURBUFMA_CombTEn(x)             (((uint32_t)(((uint32_t)(x)) << fetchlay_BURBUFMA_CombTEn_SHIFT)) & fetchlay_BURBUFMA_CombTEn_MASK)

#define fetchlay_BURBUFMA_CombLFEn_MASK          (0x40000000U)
#define fetchlay_BURBUFMA_CombLFEn_SHIFT         (30U)
/*! CombLFEn - CombinerLineFlush_Enable */
#define fetchlay_BURBUFMA_CombLFEn(x)            (((uint32_t)(((uint32_t)(x)) << fetchlay_BURBUFMA_CombLFEn_SHIFT)) & fetchlay_BURBUFMA_CombLFEn_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group fetchlay_Register_Masks */


/*!
 * @}
 */ /* end of group fetchlay_Peripheral_Access_Layer */


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


#endif  /* PERI_FETCHLAY_H_ */

