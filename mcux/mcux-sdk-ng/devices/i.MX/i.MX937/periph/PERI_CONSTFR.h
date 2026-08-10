/*
** ###################################################################
**     Processors:          MIMX9371xxVTx_ca55
**                          MIMX9371xxVTx_cm33
**                          MIMX9371xxVTx_cm7
**                          MIMX9373xxVTx_ca55
**                          MIMX9373xxVTx_cm33
**                          MIMX9373xxVTx_cm7
**                          MIMX9373xxVZx_ca55
**                          MIMX9373xxVZx_cm33
**                          MIMX9373xxVZx_cm7
**                          MIMX9375xxVTx_ca55
**                          MIMX9375xxVTx_cm33
**                          MIMX9375xxVTx_cm7
**                          MIMX9375xxVZx_ca55
**                          MIMX9375xxVZx_cm33
**                          MIMX9375xxVZx_cm7
**
**     Version:             rev. 1.0, 2026-04-09
**     Build:               b260624
**
**     Abstract:
**         CMSIS Peripheral Access Layer for CONSTFR
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2026 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2026-04-09)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_CONSTFR.h
 * @version 1.0
 * @date 2026-04-09
 * @brief CMSIS Peripheral Access Layer for CONSTFR
 *
 * CMSIS Peripheral Access Layer for CONSTFR
 */

#if !defined(PERI_CONSTFR_H_)
#define PERI_CONSTFR_H_                          /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX9371xxVTx_ca55))
#include "MIMX9371_ca55_COMMON.h"
#elif (defined(CPU_MIMX9371xxVTx_cm33))
#include "MIMX9371_cm33_COMMON.h"
#elif (defined(CPU_MIMX9371xxVTx_cm7))
#include "MIMX9371_cm7_COMMON.h"
#elif (defined(CPU_MIMX9373xxVTx_ca55) || defined(CPU_MIMX9373xxVZx_ca55))
#include "MIMX9373_ca55_COMMON.h"
#elif (defined(CPU_MIMX9373xxVTx_cm33) || defined(CPU_MIMX9373xxVZx_cm33))
#include "MIMX9373_cm33_COMMON.h"
#elif (defined(CPU_MIMX9373xxVTx_cm7) || defined(CPU_MIMX9373xxVZx_cm7))
#include "MIMX9373_cm7_COMMON.h"
#elif (defined(CPU_MIMX9375xxVTx_ca55) || defined(CPU_MIMX9375xxVZx_ca55))
#include "MIMX9375_ca55_COMMON.h"
#elif (defined(CPU_MIMX9375xxVTx_cm33) || defined(CPU_MIMX9375xxVZx_cm33))
#include "MIMX9375_cm33_COMMON.h"
#elif (defined(CPU_MIMX9375xxVTx_cm7) || defined(CPU_MIMX9375xxVZx_cm7))
#include "MIMX9375_cm7_COMMON.h"
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
   -- CONSTFR Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CONSTFR_Peripheral_Access_Layer CONSTFR Peripheral Access Layer
 * @{
 */

/** CONSTFR - Register Layout Typedef */
typedef struct {
  __O  uint32_t LU;                                /**< LockUnlock, offset: 0x0 */
  __I  uint32_t LOCKS;                             /**< LockStatus, offset: 0x4 */
  __IO uint32_t STATCON;                           /**< StaticControl, offset: 0x8 */
  __IO uint32_t FRADIM;                            /**< FrameDimensions, offset: 0xC */
  __IO uint32_t CONSTC;                            /**< ConstantColor, offset: 0x10 */
  __O  uint32_t CONTRIG;                           /**< ControlTrigger, offset: 0x14 */
  __O  uint32_t START;                             /**< Start, offset: 0x18 */
  __I  uint32_t STATUS;                            /**< Status, offset: 0x1C */
} CONSTFR_Type;

/* ----------------------------------------------------------------------------
   -- CONSTFR Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CONSTFR_Register_Masks CONSTFR Register Masks
 * @{
 */

/*! @name LU - LockUnlock */
/*! @{ */

#define CONSTFR_LU_LkUn_MASK                     (0xFFFFFFFFU)
#define CONSTFR_LU_LkUn_SHIFT                    (0U)
/*! LkUn - LockUnlock
 *  0b01010110010100011111011101100011..Decrements the unlock counter. When the counter value is null, lock protection is active. Reset counter value is 1.
 *  0b01101001000111011011100100110110..Increments the unlock counter. Max allowed value is 15.
 *  0b10101110111010010101110011011100..Enables privilege protection. Disabled after reset.
 *  0b10110101111000100100011001101110..Disables privilege protection.
 *  0b11111011111010001011000111100110..Freezes current protection status. Writing keys to this register has no more effect until reset.
 */
#define CONSTFR_LU_LkUn(x)                       (((uint32_t)(((uint32_t)(x)) << CONSTFR_LU_LkUn_SHIFT)) & CONSTFR_LU_LkUn_MASK)
/*! @} */

/*! @name LOCKS - LockStatus */
/*! @{ */

#define CONSTFR_LOCKS_LkSus_MASK                 (0x1U)
#define CONSTFR_LOCKS_LkSus_SHIFT                (0U)
/*! LkSus - LockStatus */
#define CONSTFR_LOCKS_LkSus(x)                   (((uint32_t)(((uint32_t)(x)) << CONSTFR_LOCKS_LkSus_SHIFT)) & CONSTFR_LOCKS_LkSus_MASK)

#define CONSTFR_LOCKS_PriSt_MASK                 (0x10U)
#define CONSTFR_LOCKS_PriSt_SHIFT                (4U)
/*! PriSt - PrivilegeStatus */
#define CONSTFR_LOCKS_PriSt(x)                   (((uint32_t)(((uint32_t)(x)) << CONSTFR_LOCKS_PriSt_SHIFT)) & CONSTFR_LOCKS_PriSt_MASK)

#define CONSTFR_LOCKS_FreezeS_MASK               (0x100U)
#define CONSTFR_LOCKS_FreezeS_SHIFT              (8U)
/*! FreezeS - FreezeStatus */
#define CONSTFR_LOCKS_FreezeS(x)                 (((uint32_t)(((uint32_t)(x)) << CONSTFR_LOCKS_FreezeS_SHIFT)) & CONSTFR_LOCKS_FreezeS_MASK)
/*! @} */

/*! @name STATCON - StaticControl */
/*! @{ */

#define CONSTFR_STATCON_ShdEn_MASK               (0x1U)
#define CONSTFR_STATCON_ShdEn_SHIFT              (0U)
/*! ShdEn - ShdEn */
#define CONSTFR_STATCON_ShdEn(x)                 (((uint32_t)(((uint32_t)(x)) << CONSTFR_STATCON_ShdEn_SHIFT)) & CONSTFR_STATCON_ShdEn_MASK)
/*! @} */

/*! @name FRADIM - FrameDimensions */
/*! @{ */

#define CONSTFR_FRADIM_FrameWid_MASK             (0x3FFFU)
#define CONSTFR_FRADIM_FrameWid_SHIFT            (0U)
/*! FrameWid - FrameWidth */
#define CONSTFR_FRADIM_FrameWid(x)               (((uint32_t)(((uint32_t)(x)) << CONSTFR_FRADIM_FrameWid_SHIFT)) & CONSTFR_FRADIM_FrameWid_MASK)

#define CONSTFR_FRADIM_FrameHei_MASK             (0x3FFF0000U)
#define CONSTFR_FRADIM_FrameHei_SHIFT            (16U)
/*! FrameHei - FrameHeight */
#define CONSTFR_FRADIM_FrameHei(x)               (((uint32_t)(((uint32_t)(x)) << CONSTFR_FRADIM_FrameHei_SHIFT)) & CONSTFR_FRADIM_FrameHei_MASK)

#define CONSTFR_FRADIM_EmptFram_MASK             (0x80000000U)
#define CONSTFR_FRADIM_EmptFram_SHIFT            (31U)
/*! EmptFram - EmptyFrame */
#define CONSTFR_FRADIM_EmptFram(x)               (((uint32_t)(((uint32_t)(x)) << CONSTFR_FRADIM_EmptFram_SHIFT)) & CONSTFR_FRADIM_EmptFram_MASK)
/*! @} */

/*! @name CONSTC - ConstantColor */
/*! @{ */

#define CONSTFR_CONSTC_ConstA_MASK               (0xFFU)
#define CONSTFR_CONSTC_ConstA_SHIFT              (0U)
/*! ConstA - ConstantAlpha */
#define CONSTFR_CONSTC_ConstA(x)                 (((uint32_t)(((uint32_t)(x)) << CONSTFR_CONSTC_ConstA_SHIFT)) & CONSTFR_CONSTC_ConstA_MASK)

#define CONSTFR_CONSTC_ConstB_MASK               (0xFF00U)
#define CONSTFR_CONSTC_ConstB_SHIFT              (8U)
/*! ConstB - ConstantBlue */
#define CONSTFR_CONSTC_ConstB(x)                 (((uint32_t)(((uint32_t)(x)) << CONSTFR_CONSTC_ConstB_SHIFT)) & CONSTFR_CONSTC_ConstB_MASK)

#define CONSTFR_CONSTC_ConstG_MASK               (0xFF0000U)
#define CONSTFR_CONSTC_ConstG_SHIFT              (16U)
/*! ConstG - ConstantGreen */
#define CONSTFR_CONSTC_ConstG(x)                 (((uint32_t)(((uint32_t)(x)) << CONSTFR_CONSTC_ConstG_SHIFT)) & CONSTFR_CONSTC_ConstG_MASK)

#define CONSTFR_CONSTC_ConstR_MASK               (0xFF000000U)
#define CONSTFR_CONSTC_ConstR_SHIFT              (24U)
/*! ConstR - ConstantRed */
#define CONSTFR_CONSTC_ConstR(x)                 (((uint32_t)(((uint32_t)(x)) << CONSTFR_CONSTC_ConstR_SHIFT)) & CONSTFR_CONSTC_ConstR_MASK)
/*! @} */

/*! @name CONTRIG - ControlTrigger */
/*! @{ */

#define CONSTFR_CONTRIG_SdTokGen_MASK            (0x1U)
#define CONSTFR_CONTRIG_SdTokGen_SHIFT           (0U)
/*! SdTokGen - ShdTokGen */
#define CONSTFR_CONTRIG_SdTokGen(x)              (((uint32_t)(((uint32_t)(x)) << CONSTFR_CONTRIG_SdTokGen_SHIFT)) & CONSTFR_CONTRIG_SdTokGen_MASK)
/*! @} */

/*! @name START - Start */
/*! @{ */

#define CONSTFR_START_Start1_MASK                (0x1U)
#define CONSTFR_START_Start1_SHIFT               (0U)
/*! Start1 - Start */
#define CONSTFR_START_Start1(x)                  (((uint32_t)(((uint32_t)(x)) << CONSTFR_START_Start1_SHIFT)) & CONSTFR_START_Start1_MASK)
/*! @} */

/*! @name STATUS - Status */
/*! @{ */

#define CONSTFR_STATUS_StBusy_MASK               (0x1U)
#define CONSTFR_STATUS_StBusy_SHIFT              (0U)
/*! StBusy - StatusBusy */
#define CONSTFR_STATUS_StBusy(x)                 (((uint32_t)(((uint32_t)(x)) << CONSTFR_STATUS_StBusy_SHIFT)) & CONSTFR_STATUS_StBusy_MASK)

#define CONSTFR_STATUS_ShadowS_MASK              (0x2U)
#define CONSTFR_STATUS_ShadowS_SHIFT             (1U)
/*! ShadowS - ShadowStatus */
#define CONSTFR_STATUS_ShadowS(x)                (((uint32_t)(((uint32_t)(x)) << CONSTFR_STATUS_ShadowS_SHIFT)) & CONSTFR_STATUS_ShadowS_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group CONSTFR_Register_Masks */


/*!
 * @}
 */ /* end of group CONSTFR_Peripheral_Access_Layer */


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


#endif  /* PERI_CONSTFR_H_ */

