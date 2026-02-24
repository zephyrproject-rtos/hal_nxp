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
**         CMSIS Peripheral Access Layer for domainb1
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
 * @file PERI_domainb1.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for domainb1
 *
 * CMSIS Peripheral Access Layer for domainb1
 */

#if !defined(PERI_DOMAINB1_H_)
#define PERI_DOMAINB1_H_                         /**< Symbol preventing repeated inclusion */

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
   -- domainb1 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup domainb1_Peripheral_Access_Layer domainb1 Peripheral Access Layer
 * @{
 */

/** domainb1 - Register Layout Typedef */
typedef struct {
  __O  uint32_t LU;                                /**< LockUnlock, offset: 0x0 */
  __I  uint32_t LOCKS;                             /**< LockStatus, offset: 0x4 */
  __IO uint32_t STATCON;                           /**< StaticControl, offset: 0x8 */
  __O  uint32_t CONTRIG;                           /**< ControlTrigger, offset: 0xC */
  __IO uint32_t MODECONT;                          /**< ModeControl, offset: 0x10 */
  __IO uint32_t ALPHACO;                           /**< AlphaControl, offset: 0x14 */
  __IO uint32_t BLENDCON;                          /**< BlendControl, offset: 0x18 */
  __I  uint32_t TIMEOFBK;                          /**< Timeout_Feedback, offset: 0x1C */
  __O  uint32_t LC;                                /**< Lockup_Clear, offset: 0x20 */
  __IO uint32_t DELCEN;                            /**< Delay_Counter_En, offset: 0x24 */
  __I  uint32_t DELCPRIM;                          /**< Delay_Counter_Prim, offset: 0x28 */
  __I  uint32_t DELCSEC;                           /**< Delay_Counter_Sec, offset: 0x2C */
  __I  uint32_t ERCOPRIM;                          /**< Error_Counter_Prim, offset: 0x30 */
  __I  uint32_t ERCOSEC;                           /**< Error_Counter_Sec, offset: 0x34 */
  __I  uint32_t SOURS;                             /**< Source_Status, offset: 0x38 */
  __O  uint32_t SOURSC;                            /**< Source_Status_Clear, offset: 0x3C */
  __I  uint32_t PRIMCOWO;                          /**< PrimControlWord, offset: 0x40 */
  __I  uint32_t SECCONTW;                          /**< SecControlWord, offset: 0x44 */
} domainb1_Type;

/* ----------------------------------------------------------------------------
   -- domainb1 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup domainb1_Register_Masks domainb1 Register Masks
 * @{
 */

/*! @name LU - LockUnlock */
/*! @{ */

#define domainb1_LU_LkUn_MASK                    (0xFFFFFFFFU)
#define domainb1_LU_LkUn_SHIFT                   (0U)
/*! LkUn - LockUnlock
 *  0b01010110010100011111011101100011..Decrements the unlock counter. When the counter value is null, lock protection is active. Reset counter value is 1.
 *  0b01101001000111011011100100110110..Increments the unlock counter. Max allowed value is 15.
 *  0b10101110111010010101110011011100..Enables privilege protection. Disabled after reset.
 *  0b10110101111000100100011001101110..Disables privilege protection.
 *  0b11111011111010001011000111100110..Freezes current protection status. Writing keys to this register has no more effect until reset.
 */
#define domainb1_LU_LkUn(x)                      (((uint32_t)(((uint32_t)(x)) << domainb1_LU_LkUn_SHIFT)) & domainb1_LU_LkUn_MASK)
/*! @} */

/*! @name LOCKS - LockStatus */
/*! @{ */

#define domainb1_LOCKS_LkSus_MASK                (0x1U)
#define domainb1_LOCKS_LkSus_SHIFT               (0U)
/*! LkSus - LockStatus */
#define domainb1_LOCKS_LkSus(x)                  (((uint32_t)(((uint32_t)(x)) << domainb1_LOCKS_LkSus_SHIFT)) & domainb1_LOCKS_LkSus_MASK)

#define domainb1_LOCKS_PriSt_MASK                (0x10U)
#define domainb1_LOCKS_PriSt_SHIFT               (4U)
/*! PriSt - PrivilegeStatus */
#define domainb1_LOCKS_PriSt(x)                  (((uint32_t)(((uint32_t)(x)) << domainb1_LOCKS_PriSt_SHIFT)) & domainb1_LOCKS_PriSt_MASK)

#define domainb1_LOCKS_FreezeS_MASK              (0x100U)
#define domainb1_LOCKS_FreezeS_SHIFT             (8U)
/*! FreezeS - FreezeStatus */
#define domainb1_LOCKS_FreezeS(x)                (((uint32_t)(((uint32_t)(x)) << domainb1_LOCKS_FreezeS_SHIFT)) & domainb1_LOCKS_FreezeS_MASK)
/*! @} */

/*! @name STATCON - StaticControl */
/*! @{ */

#define domainb1_STATCON_ShdEn_MASK              (0x1U)
#define domainb1_STATCON_ShdEn_SHIFT             (0U)
/*! ShdEn - ShdEn */
#define domainb1_STATCON_ShdEn(x)                (((uint32_t)(((uint32_t)(x)) << domainb1_STATCON_ShdEn_SHIFT)) & domainb1_STATCON_ShdEn_MASK)

#define domainb1_STATCON_SdLdSel_MASK            (0xEU)
#define domainb1_STATCON_SdLdSel_SHIFT           (1U)
/*! SdLdSel - ShdLdSel
 *  0b000..Shadow loading not allowed
 *  0b001..Load shadows with shadow load token on primary input.
 *  0b010..Load shadows with shadow load token on secondary input.
 *  0b011..Load shadows with shadow load token on primary or secondary input.
 *  0b100..Load shadows with shadow load token from ControlTrigger register.
 *  0b101..Load shadows with shadow load token from ControlTrigger register or primary input.
 *  0b110..Load shadows with shadow load token from ControlTrigger register or secondary input.
 *  0b111..Load shadows with shadow load token from ControlTrigger register or primary or secondary input.
 */
#define domainb1_STATCON_SdLdSel(x)              (((uint32_t)(((uint32_t)(x)) << domainb1_STATCON_SdLdSel_SHIFT)) & domainb1_STATCON_SdLdSel_MASK)

#define domainb1_STATCON_SdTokSel_MASK           (0x70U)
#define domainb1_STATCON_SdTokSel_SHIFT          (4U)
/*! SdTokSel - ShdTokSel
 *  0b000..Shadow load forwarding not allowed
 *  0b001..When a token was received on the primary input.
 *  0b010..When a token was received on the secondary input.
 *  0b011..When a token was received on the primary or secondary input.
 *  0b100..When a token was received from ControlTrigger register.
 *  0b101..When a token was received from ControlTrigger register or primary input.
 *  0b110..When a token was received from ControlTrigger register or secondary input.
 *  0b111..When a token was received from ControlTrigger register or primary or secondary input.
 */
#define domainb1_STATCON_SdTokSel(x)             (((uint32_t)(((uint32_t)(x)) << domainb1_STATCON_SdTokSel_SHIFT)) & domainb1_STATCON_SdTokSel_MASK)
/*! @} */

/*! @name CONTRIG - ControlTrigger */
/*! @{ */

#define domainb1_CONTRIG_SdTokGen_MASK           (0x1U)
#define domainb1_CONTRIG_SdTokGen_SHIFT          (0U)
/*! SdTokGen - ShdTokGen */
#define domainb1_CONTRIG_SdTokGen(x)             (((uint32_t)(((uint32_t)(x)) << domainb1_CONTRIG_SdTokGen_SHIFT)) & domainb1_CONTRIG_SdTokGen_MASK)
/*! @} */

/*! @name MODECONT - ModeControl */
/*! @{ */

#define domainb1_MODECONT_MODE2_MASK             (0x3U)
#define domainb1_MODECONT_MODE2_SHIFT            (0U)
/*! MODE2 - MODE
 *  0b00..Output is same as primary input.
 *  0b01..Output is same as secondary input.
 *  0b10..Module is in blending mode.
 *  0b11..Module is in side by side mode. The primary and secondary inputs are displayed side by side.
 */
#define domainb1_MODECONT_MODE2(x)               (((uint32_t)(((uint32_t)(x)) << domainb1_MODECONT_MODE2_SHIFT)) & domainb1_MODECONT_MODE2_MASK)
/*! @} */

/*! @name ALPHACO - AlphaControl */
/*! @{ */

#define domainb1_ALPHACO_AlpMaE_MASK             (0x1U)
#define domainb1_ALPHACO_AlpMaE_SHIFT            (0U)
/*! AlpMaE - AlphaMaskEnable
 *  0b0..AlphaMask feature disabled
 *  0b1..AlphaMask feature enabled
 */
#define domainb1_ALPHACO_AlpMaE(x)               (((uint32_t)(((uint32_t)(x)) << domainb1_ALPHACO_AlpMaE_SHIFT)) & domainb1_ALPHACO_AlpMaE_MASK)

#define domainb1_ALPHACO_AlpMMode_MASK           (0xEU)
#define domainb1_ALPHACO_AlpMMode_SHIFT          (1U)
/*! AlpMMode - AlphaMaskMode
 *  0b000..Areas with primary input alpha > 128 will be mapped to 255 and the rest will have an alpha value of 0
 *  0b001..The area of the secondary input will get an alpha value of 255 and the rest will be 0
 *  0b010..Behaves as if the output of modes PRIM and SEC would be ORed together
 *  0b011..Behaves as if the output of modes PRIM and SEC would be ANDed together
 *  0b100..Behaves as if the output of mode PRIM would be inverted
 *  0b101..Behaves as if the output of mode SEC would be inverted
 *  0b110..Behaves as if the output of modes PRIM and SEC_INV would be ORed together
 *  0b111..Behaves as if the output of modes PRIM and SEC_INV would be ANDed together
 */
#define domainb1_ALPHACO_AlpMMode(x)             (((uint32_t)(((uint32_t)(x)) << domainb1_ALPHACO_AlpMMode_SHIFT)) & domainb1_ALPHACO_AlpMMode_MASK)
/*! @} */

/*! @name BLENDCON - BlendControl */
/*! @{ */

#define domainb1_BLENDCON_PRICBLDF_MASK          (0x7U)
#define domainb1_BLENDCON_PRICBLDF_SHIFT         (0U)
/*! PRICBLDF - PRIM_C_BLD_FUNC
 *  0b000..Cout = Cin * 0
 *  0b001..Cout = Cin * 1
 *  0b010..Cout = Cin * ALPHA_prim
 *  0b011..Cout = Cin * (1 - ALPHA_prim)
 *  0b100..Cout = Cin * ALPHA_sec
 *  0b101..Cout = Cin * (1 - ALPHA_sec)
 *  0b110..Cout = Cin * ALPHA_const
 *  0b111..Cout = Cin * (1 - ALPHA_const)
 */
#define domainb1_BLENDCON_PRICBLDF(x)            (((uint32_t)(((uint32_t)(x)) << domainb1_BLENDCON_PRICBLDF_SHIFT)) & domainb1_BLENDCON_PRICBLDF_MASK)

#define domainb1_BLENDCON_SECCBLDF_MASK          (0x70U)
#define domainb1_BLENDCON_SECCBLDF_SHIFT         (4U)
/*! SECCBLDF - SEC_C_BLD_FUNC
 *  0b000..Cout = Cin * 0
 *  0b001..Cout = Cin * 1
 *  0b010..Cout = Cin * ALPHA_prim
 *  0b011..Cout = Cin * (1 - ALPHA_prim)
 *  0b100..Cout = Cin * ALPHA_sec
 *  0b101..Cout = Cin * (1 - ALPHA_sec)
 *  0b110..Cout = Cin * ALPHA_const
 *  0b111..Cout = Cin * (1 - ALPHA_const)
 */
#define domainb1_BLENDCON_SECCBLDF(x)            (((uint32_t)(((uint32_t)(x)) << domainb1_BLENDCON_SECCBLDF_SHIFT)) & domainb1_BLENDCON_SECCBLDF_MASK)

#define domainb1_BLENDCON_PRIABLDF_MASK          (0x700U)
#define domainb1_BLENDCON_PRIABLDF_SHIFT         (8U)
/*! PRIABLDF - PRIM_A_BLD_FUNC
 *  0b000..Aout = Ain * 0
 *  0b001..Aout = Ain * 1
 *  0b010..Aout = Ain * ALPHA_prim
 *  0b011..Aout = Ain * (1 - ALPHA_prim)
 *  0b100..Aout = Ain * ALPHA_sec
 *  0b101..Aout = Ain * (1 - ALPHA_sec)
 *  0b110..Aout = Ain * ALPHA_const
 *  0b111..Aout = Ain * (1 - ALPHA_const)
 */
#define domainb1_BLENDCON_PRIABLDF(x)            (((uint32_t)(((uint32_t)(x)) << domainb1_BLENDCON_PRIABLDF_SHIFT)) & domainb1_BLENDCON_PRIABLDF_MASK)

#define domainb1_BLENDCON_SECABLDF_MASK          (0x7000U)
#define domainb1_BLENDCON_SECABLDF_SHIFT         (12U)
/*! SECABLDF - SEC_A_BLD_FUNC
 *  0b000..Aout = Ain * 0
 *  0b001..Aout = Ain * 1
 *  0b010..Aout = Ain * ALPHA_prim
 *  0b011..Aout = Ain * (1 - ALPHA_prim)
 *  0b100..Aout = Ain * ALPHA_sec
 *  0b101..Aout = Ain * (1 - ALPHA_sec)
 *  0b110..Aout = Ain * ALPHA_const
 *  0b111..Aout = Ain * (1 - ALPHA_const)
 */
#define domainb1_BLENDCON_SECABLDF(x)            (((uint32_t)(((uint32_t)(x)) << domainb1_BLENDCON_SECABLDF_SHIFT)) & domainb1_BLENDCON_SECABLDF_MASK)

#define domainb1_BLENDCON_BlendAlp_MASK          (0xFF0000U)
#define domainb1_BLENDCON_BlendAlp_SHIFT         (16U)
/*! BlendAlp - BlendAlpha */
#define domainb1_BLENDCON_BlendAlp(x)            (((uint32_t)(((uint32_t)(x)) << domainb1_BLENDCON_BlendAlp_SHIFT)) & domainb1_BLENDCON_BlendAlp_MASK)
/*! @} */

/*! @name TIMEOFBK - Timeout_Feedback */
/*! @{ */

#define domainb1_TIMEOFBK_PrimWait_MASK          (0x1U)
#define domainb1_TIMEOFBK_PrimWait_SHIFT         (0U)
/*! PrimWait - PrimWait */
#define domainb1_TIMEOFBK_PrimWait(x)            (((uint32_t)(((uint32_t)(x)) << domainb1_TIMEOFBK_PrimWait_SHIFT)) & domainb1_TIMEOFBK_PrimWait_MASK)

#define domainb1_TIMEOFBK_ScWait_MASK            (0x2U)
#define domainb1_TIMEOFBK_ScWait_SHIFT           (1U)
/*! ScWait - SecWait */
#define domainb1_TIMEOFBK_ScWait(x)              (((uint32_t)(((uint32_t)(x)) << domainb1_TIMEOFBK_ScWait_SHIFT)) & domainb1_TIMEOFBK_ScWait_MASK)
/*! @} */

/*! @name LC - Lockup_Clear */
/*! @{ */

#define domainb1_LC_LkupC_MASK                   (0x1U)
#define domainb1_LC_LkupC_SHIFT                  (0U)
/*! LkupC - LockupClear */
#define domainb1_LC_LkupC(x)                     (((uint32_t)(((uint32_t)(x)) << domainb1_LC_LkupC_SHIFT)) & domainb1_LC_LkupC_MASK)
/*! @} */

/*! @name DELCEN - Delay_Counter_En */
/*! @{ */

#define domainb1_DELCEN_DelCEn_MASK              (0x1U)
#define domainb1_DELCEN_DelCEn_SHIFT             (0U)
/*! DelCEn - DelayCountEn */
#define domainb1_DELCEN_DelCEn(x)                (((uint32_t)(((uint32_t)(x)) << domainb1_DELCEN_DelCEn_SHIFT)) & domainb1_DELCEN_DelCEn_MASK)
/*! @} */

/*! @name DELCPRIM - Delay_Counter_Prim */
/*! @{ */

#define domainb1_DELCPRIM_DelCPrim_MASK          (0xFFFFFFFU)
#define domainb1_DELCPRIM_DelCPrim_SHIFT         (0U)
/*! DelCPrim - DelayCountPrim */
#define domainb1_DELCPRIM_DelCPrim(x)            (((uint32_t)(((uint32_t)(x)) << domainb1_DELCPRIM_DelCPrim_SHIFT)) & domainb1_DELCPRIM_DelCPrim_MASK)
/*! @} */

/*! @name DELCSEC - Delay_Counter_Sec */
/*! @{ */

#define domainb1_DELCSEC_DelCSec_MASK            (0xFFFFFFFU)
#define domainb1_DELCSEC_DelCSec_SHIFT           (0U)
/*! DelCSec - DelayCountSec */
#define domainb1_DELCSEC_DelCSec(x)              (((uint32_t)(((uint32_t)(x)) << domainb1_DELCSEC_DelCSec_SHIFT)) & domainb1_DELCSEC_DelCSec_MASK)
/*! @} */

/*! @name ERCOPRIM - Error_Counter_Prim */
/*! @{ */

#define domainb1_ERCOPRIM_ErrCoPr_MASK           (0xFFFFFFFU)
#define domainb1_ERCOPRIM_ErrCoPr_SHIFT          (0U)
/*! ErrCoPr - ErrCountPrim */
#define domainb1_ERCOPRIM_ErrCoPr(x)             (((uint32_t)(((uint32_t)(x)) << domainb1_ERCOPRIM_ErrCoPr_SHIFT)) & domainb1_ERCOPRIM_ErrCoPr_MASK)
/*! @} */

/*! @name ERCOSEC - Error_Counter_Sec */
/*! @{ */

#define domainb1_ERCOSEC_ErrCoSe_MASK            (0xFFFFFFFU)
#define domainb1_ERCOSEC_ErrCoSe_SHIFT           (0U)
/*! ErrCoSe - ErrCountSec */
#define domainb1_ERCOSEC_ErrCoSe(x)              (((uint32_t)(((uint32_t)(x)) << domainb1_ERCOSEC_ErrCoSe_SHIFT)) & domainb1_ERCOSEC_ErrCoSe_MASK)
/*! @} */

/*! @name SOURS - Source_Status */
/*! @{ */

#define domainb1_SOURS_WrgCoWo_MASK              (0x1U)
#define domainb1_SOURS_WrgCoWo_SHIFT             (0U)
/*! WrgCoWo - WrongCommandWord */
#define domainb1_SOURS_WrgCoWo(x)                (((uint32_t)(((uint32_t)(x)) << domainb1_SOURS_WrgCoWo_SHIFT)) & domainb1_SOURS_WrgCoWo_MASK)

#define domainb1_SOURS_WrgPxlDa_MASK             (0x2U)
#define domainb1_SOURS_WrgPxlDa_SHIFT            (1U)
/*! WrgPxlDa - WrongPixelData */
#define domainb1_SOURS_WrgPxlDa(x)               (((uint32_t)(((uint32_t)(x)) << domainb1_SOURS_WrgPxlDa_SHIFT)) & domainb1_SOURS_WrgPxlDa_MASK)

#define domainb1_SOURS_WrgInput_MASK             (0x4U)
#define domainb1_SOURS_WrgInput_SHIFT            (2U)
/*! WrgInput - WrongInput */
#define domainb1_SOURS_WrgInput(x)               (((uint32_t)(((uint32_t)(x)) << domainb1_SOURS_WrgInput_SHIFT)) & domainb1_SOURS_WrgInput_MASK)
/*! @} */

/*! @name SOURSC - Source_Status_Clear */
/*! @{ */

#define domainb1_SOURSC_ClearWCW_MASK            (0x1U)
#define domainb1_SOURSC_ClearWCW_SHIFT           (0U)
/*! ClearWCW - ClearWrongCommandWord */
#define domainb1_SOURSC_ClearWCW(x)              (((uint32_t)(((uint32_t)(x)) << domainb1_SOURSC_ClearWCW_SHIFT)) & domainb1_SOURSC_ClearWCW_MASK)

#define domainb1_SOURSC_ClearWPD_MASK            (0x2U)
#define domainb1_SOURSC_ClearWPD_SHIFT           (1U)
/*! ClearWPD - ClearWrongPixelData */
#define domainb1_SOURSC_ClearWPD(x)              (((uint32_t)(((uint32_t)(x)) << domainb1_SOURSC_ClearWPD_SHIFT)) & domainb1_SOURSC_ClearWPD_MASK)

#define domainb1_SOURSC_ClearWI_MASK             (0x4U)
#define domainb1_SOURSC_ClearWI_SHIFT            (2U)
/*! ClearWI - ClearWrongInput */
#define domainb1_SOURSC_ClearWI(x)               (((uint32_t)(((uint32_t)(x)) << domainb1_SOURSC_ClearWI_SHIFT)) & domainb1_SOURSC_ClearWI_MASK)
/*! @} */

/*! @name PRIMCOWO - PrimControlWord */
/*! @{ */

#define domainb1_PRIMCOWO_PVAL_MASK              (0xFFFFFFFFU)
#define domainb1_PRIMCOWO_PVAL_SHIFT             (0U)
/*! PVAL - P_VAL */
#define domainb1_PRIMCOWO_PVAL(x)                (((uint32_t)(((uint32_t)(x)) << domainb1_PRIMCOWO_PVAL_SHIFT)) & domainb1_PRIMCOWO_PVAL_MASK)
/*! @} */

/*! @name SECCONTW - SecControlWord */
/*! @{ */

#define domainb1_SECCONTW_SVAL_MASK              (0xFFFFFFFFU)
#define domainb1_SECCONTW_SVAL_SHIFT             (0U)
/*! SVAL - S_VAL */
#define domainb1_SECCONTW_SVAL(x)                (((uint32_t)(((uint32_t)(x)) << domainb1_SECCONTW_SVAL_SHIFT)) & domainb1_SECCONTW_SVAL_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group domainb1_Register_Masks */


/*!
 * @}
 */ /* end of group domainb1_Peripheral_Access_Layer */


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


#endif  /* PERI_DOMAINB1_H_ */

