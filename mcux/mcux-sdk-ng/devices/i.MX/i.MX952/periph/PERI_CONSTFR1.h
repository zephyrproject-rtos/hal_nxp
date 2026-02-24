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
**         CMSIS Peripheral Access Layer for constfr1
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
 * @file PERI_constfr1.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for constfr1
 *
 * CMSIS Peripheral Access Layer for constfr1
 */

#if !defined(PERI_CONSTFR1_H_)
#define PERI_CONSTFR1_H_                         /**< Symbol preventing repeated inclusion */

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
   -- constfr1 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup constfr1_Peripheral_Access_Layer constfr1 Peripheral Access Layer
 * @{
 */

/** constfr1 - Register Layout Typedef */
typedef struct {
  __O  uint32_t LU;                                /**< LockUnlock, offset: 0x0 */
  __I  uint32_t LOCKS;                             /**< LockStatus, offset: 0x4 */
  __IO uint32_t STATCON;                           /**< StaticControl, offset: 0x8 */
  __IO uint32_t FRADIM;                            /**< FrameDimensions, offset: 0xC */
  __IO uint32_t CONSTC;                            /**< ConstantColor, offset: 0x10 */
  __O  uint32_t CONTRIG;                           /**< ControlTrigger, offset: 0x14 */
  __O  uint32_t START;                             /**< Start, offset: 0x18 */
  __I  uint32_t STATUS;                            /**< Status, offset: 0x1C */
} constfr1_Type;

/* ----------------------------------------------------------------------------
   -- constfr1 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup constfr1_Register_Masks constfr1 Register Masks
 * @{
 */

/*! @name LU - LockUnlock */
/*! @{ */

#define constfr1_LU_LkUn_MASK                    (0xFFFFFFFFU)
#define constfr1_LU_LkUn_SHIFT                   (0U)
/*! LkUn - LockUnlock
 *  0b01010110010100011111011101100011..Decrements the unlock counter. When the counter value is null, lock protection is active. Reset counter value is 1.
 *  0b01101001000111011011100100110110..Increments the unlock counter. Max allowed value is 15.
 *  0b10101110111010010101110011011100..Enables privilege protection. Disabled after reset.
 *  0b10110101111000100100011001101110..Disables privilege protection.
 *  0b11111011111010001011000111100110..Freezes current protection status. Writing keys to this register has no more effect until reset.
 */
#define constfr1_LU_LkUn(x)                      (((uint32_t)(((uint32_t)(x)) << constfr1_LU_LkUn_SHIFT)) & constfr1_LU_LkUn_MASK)
/*! @} */

/*! @name LOCKS - LockStatus */
/*! @{ */

#define constfr1_LOCKS_LkSus_MASK                (0x1U)
#define constfr1_LOCKS_LkSus_SHIFT               (0U)
/*! LkSus - LockStatus */
#define constfr1_LOCKS_LkSus(x)                  (((uint32_t)(((uint32_t)(x)) << constfr1_LOCKS_LkSus_SHIFT)) & constfr1_LOCKS_LkSus_MASK)

#define constfr1_LOCKS_PriSt_MASK                (0x10U)
#define constfr1_LOCKS_PriSt_SHIFT               (4U)
/*! PriSt - PrivilegeStatus */
#define constfr1_LOCKS_PriSt(x)                  (((uint32_t)(((uint32_t)(x)) << constfr1_LOCKS_PriSt_SHIFT)) & constfr1_LOCKS_PriSt_MASK)

#define constfr1_LOCKS_FreezeS_MASK              (0x100U)
#define constfr1_LOCKS_FreezeS_SHIFT             (8U)
/*! FreezeS - FreezeStatus */
#define constfr1_LOCKS_FreezeS(x)                (((uint32_t)(((uint32_t)(x)) << constfr1_LOCKS_FreezeS_SHIFT)) & constfr1_LOCKS_FreezeS_MASK)
/*! @} */

/*! @name STATCON - StaticControl */
/*! @{ */

#define constfr1_STATCON_ShdEn_MASK              (0x1U)
#define constfr1_STATCON_ShdEn_SHIFT             (0U)
/*! ShdEn - ShdEn */
#define constfr1_STATCON_ShdEn(x)                (((uint32_t)(((uint32_t)(x)) << constfr1_STATCON_ShdEn_SHIFT)) & constfr1_STATCON_ShdEn_MASK)
/*! @} */

/*! @name FRADIM - FrameDimensions */
/*! @{ */

#define constfr1_FRADIM_FrameWid_MASK            (0x3FFFU)
#define constfr1_FRADIM_FrameWid_SHIFT           (0U)
/*! FrameWid - FrameWidth */
#define constfr1_FRADIM_FrameWid(x)              (((uint32_t)(((uint32_t)(x)) << constfr1_FRADIM_FrameWid_SHIFT)) & constfr1_FRADIM_FrameWid_MASK)

#define constfr1_FRADIM_FrameHei_MASK            (0x3FFF0000U)
#define constfr1_FRADIM_FrameHei_SHIFT           (16U)
/*! FrameHei - FrameHeight */
#define constfr1_FRADIM_FrameHei(x)              (((uint32_t)(((uint32_t)(x)) << constfr1_FRADIM_FrameHei_SHIFT)) & constfr1_FRADIM_FrameHei_MASK)

#define constfr1_FRADIM_EmptFram_MASK            (0x80000000U)
#define constfr1_FRADIM_EmptFram_SHIFT           (31U)
/*! EmptFram - EmptyFrame */
#define constfr1_FRADIM_EmptFram(x)              (((uint32_t)(((uint32_t)(x)) << constfr1_FRADIM_EmptFram_SHIFT)) & constfr1_FRADIM_EmptFram_MASK)
/*! @} */

/*! @name CONSTC - ConstantColor */
/*! @{ */

#define constfr1_CONSTC_ConstA_MASK              (0xFFU)
#define constfr1_CONSTC_ConstA_SHIFT             (0U)
/*! ConstA - ConstantAlpha */
#define constfr1_CONSTC_ConstA(x)                (((uint32_t)(((uint32_t)(x)) << constfr1_CONSTC_ConstA_SHIFT)) & constfr1_CONSTC_ConstA_MASK)

#define constfr1_CONSTC_ConstB_MASK              (0xFF00U)
#define constfr1_CONSTC_ConstB_SHIFT             (8U)
/*! ConstB - ConstantBlue */
#define constfr1_CONSTC_ConstB(x)                (((uint32_t)(((uint32_t)(x)) << constfr1_CONSTC_ConstB_SHIFT)) & constfr1_CONSTC_ConstB_MASK)

#define constfr1_CONSTC_ConstG_MASK              (0xFF0000U)
#define constfr1_CONSTC_ConstG_SHIFT             (16U)
/*! ConstG - ConstantGreen */
#define constfr1_CONSTC_ConstG(x)                (((uint32_t)(((uint32_t)(x)) << constfr1_CONSTC_ConstG_SHIFT)) & constfr1_CONSTC_ConstG_MASK)

#define constfr1_CONSTC_ConstR_MASK              (0xFF000000U)
#define constfr1_CONSTC_ConstR_SHIFT             (24U)
/*! ConstR - ConstantRed */
#define constfr1_CONSTC_ConstR(x)                (((uint32_t)(((uint32_t)(x)) << constfr1_CONSTC_ConstR_SHIFT)) & constfr1_CONSTC_ConstR_MASK)
/*! @} */

/*! @name CONTRIG - ControlTrigger */
/*! @{ */

#define constfr1_CONTRIG_SdTokGen_MASK           (0x1U)
#define constfr1_CONTRIG_SdTokGen_SHIFT          (0U)
/*! SdTokGen - ShdTokGen */
#define constfr1_CONTRIG_SdTokGen(x)             (((uint32_t)(((uint32_t)(x)) << constfr1_CONTRIG_SdTokGen_SHIFT)) & constfr1_CONTRIG_SdTokGen_MASK)
/*! @} */

/*! @name START - Start */
/*! @{ */

#define constfr1_START_Start1_MASK               (0x1U)
#define constfr1_START_Start1_SHIFT              (0U)
/*! Start1 - Start */
#define constfr1_START_Start1(x)                 (((uint32_t)(((uint32_t)(x)) << constfr1_START_Start1_SHIFT)) & constfr1_START_Start1_MASK)
/*! @} */

/*! @name STATUS - Status */
/*! @{ */

#define constfr1_STATUS_StBusy_MASK              (0x1U)
#define constfr1_STATUS_StBusy_SHIFT             (0U)
/*! StBusy - StatusBusy */
#define constfr1_STATUS_StBusy(x)                (((uint32_t)(((uint32_t)(x)) << constfr1_STATUS_StBusy_SHIFT)) & constfr1_STATUS_StBusy_MASK)

#define constfr1_STATUS_ShadowS_MASK             (0x2U)
#define constfr1_STATUS_ShadowS_SHIFT            (1U)
/*! ShadowS - ShadowStatus */
#define constfr1_STATUS_ShadowS(x)               (((uint32_t)(((uint32_t)(x)) << constfr1_STATUS_ShadowS_SHIFT)) & constfr1_STATUS_ShadowS_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group constfr1_Register_Masks */


/*!
 * @}
 */ /* end of group constfr1_Peripheral_Access_Layer */


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


#endif  /* PERI_CONSTFR1_H_ */

