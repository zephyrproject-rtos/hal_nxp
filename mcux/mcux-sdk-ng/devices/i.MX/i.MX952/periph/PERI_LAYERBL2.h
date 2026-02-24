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
**         CMSIS Peripheral Access Layer for layerbl2
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
 * @file PERI_layerbl2.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for layerbl2
 *
 * CMSIS Peripheral Access Layer for layerbl2
 */

#if !defined(PERI_LAYERBL2_H_)
#define PERI_LAYERBL2_H_                         /**< Symbol preventing repeated inclusion */

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
   -- layerbl2 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup layerbl2_Peripheral_Access_Layer layerbl2 Peripheral Access Layer
 * @{
 */

/** layerbl2 - Register Layout Typedef */
typedef struct {
  __O  uint32_t LU;                                /**< LockUnlock, offset: 0x0 */
  __I  uint32_t LOCKS;                             /**< LockStatus, offset: 0x4 */
  __IO uint32_t STATCON;                           /**< StaticControl, offset: 0x8 */
  __IO uint32_t CONTR;                             /**< Control, offset: 0xC */
  __IO uint32_t BLENDCON;                          /**< BlendControl, offset: 0x10 */
  __IO uint32_t POSITION;                          /**< Position, offset: 0x14 */
  __I  uint32_t PRIMCOWO;                          /**< PrimControlWord, offset: 0x18 */
  __I  uint32_t SECCONTW;                          /**< SecControlWord, offset: 0x1C */
} layerbl2_Type;

/* ----------------------------------------------------------------------------
   -- layerbl2 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup layerbl2_Register_Masks layerbl2 Register Masks
 * @{
 */

/*! @name LU - LockUnlock */
/*! @{ */

#define layerbl2_LU_LkUn_MASK                    (0xFFFFFFFFU)
#define layerbl2_LU_LkUn_SHIFT                   (0U)
/*! LkUn - LockUnlock
 *  0b01010110010100011111011101100011..Decrements the unlock counter. When the counter value is null, lock protection is active. Reset counter value is 1.
 *  0b01101001000111011011100100110110..Increments the unlock counter. Max allowed value is 15.
 *  0b10101110111010010101110011011100..Enables privilege protection. Disabled after reset.
 *  0b10110101111000100100011001101110..Disables privilege protection.
 *  0b11111011111010001011000111100110..Freezes current protection status. Writing keys to this register has no more effect until reset.
 */
#define layerbl2_LU_LkUn(x)                      (((uint32_t)(((uint32_t)(x)) << layerbl2_LU_LkUn_SHIFT)) & layerbl2_LU_LkUn_MASK)
/*! @} */

/*! @name LOCKS - LockStatus */
/*! @{ */

#define layerbl2_LOCKS_LkSus_MASK                (0x1U)
#define layerbl2_LOCKS_LkSus_SHIFT               (0U)
/*! LkSus - LockStatus */
#define layerbl2_LOCKS_LkSus(x)                  (((uint32_t)(((uint32_t)(x)) << layerbl2_LOCKS_LkSus_SHIFT)) & layerbl2_LOCKS_LkSus_MASK)

#define layerbl2_LOCKS_PriSt_MASK                (0x10U)
#define layerbl2_LOCKS_PriSt_SHIFT               (4U)
/*! PriSt - PrivilegeStatus */
#define layerbl2_LOCKS_PriSt(x)                  (((uint32_t)(((uint32_t)(x)) << layerbl2_LOCKS_PriSt_SHIFT)) & layerbl2_LOCKS_PriSt_MASK)

#define layerbl2_LOCKS_FreezeS_MASK              (0x100U)
#define layerbl2_LOCKS_FreezeS_SHIFT             (8U)
/*! FreezeS - FreezeStatus */
#define layerbl2_LOCKS_FreezeS(x)                (((uint32_t)(((uint32_t)(x)) << layerbl2_LOCKS_FreezeS_SHIFT)) & layerbl2_LOCKS_FreezeS_MASK)
/*! @} */

/*! @name STATCON - StaticControl */
/*! @{ */

#define layerbl2_STATCON_ShdEn_MASK              (0x1U)
#define layerbl2_STATCON_ShdEn_SHIFT             (0U)
/*! ShdEn - ShdEn */
#define layerbl2_STATCON_ShdEn(x)                (((uint32_t)(((uint32_t)(x)) << layerbl2_STATCON_ShdEn_SHIFT)) & layerbl2_STATCON_ShdEn_MASK)

#define layerbl2_STATCON_SdLdSel_MASK            (0x6U)
#define layerbl2_STATCON_SdLdSel_SHIFT           (1U)
/*! SdLdSel - ShdLdSel
 *  0b00..Load shadows with shadow load token on primary input (background plane).
 *  0b01..Load shadows with shadow load token on secondary input (foreground plane).
 *  0b10..Load shadows with shadow load token on any input.
 */
#define layerbl2_STATCON_SdLdSel(x)              (((uint32_t)(((uint32_t)(x)) << layerbl2_STATCON_SdLdSel_SHIFT)) & layerbl2_STATCON_SdLdSel_MASK)

#define layerbl2_STATCON_SdTokSel_MASK           (0x18U)
#define layerbl2_STATCON_SdTokSel_SHIFT          (3U)
/*! SdTokSel - ShdTokSel
 *  0b00..When a token was received on the primary input (background plane).
 *  0b01..When a token was received on the secondary input (foreground plane).
 *  0b10..When a token was received on any input.
 */
#define layerbl2_STATCON_SdTokSel(x)             (((uint32_t)(((uint32_t)(x)) << layerbl2_STATCON_SdTokSel_SHIFT)) & layerbl2_STATCON_SdTokSel_MASK)
/*! @} */

/*! @name CONTR - Control */
/*! @{ */

#define layerbl2_CONTR_MODE2_MASK                (0x1U)
#define layerbl2_CONTR_MODE2_SHIFT               (0U)
/*! MODE2 - MODE
 *  0b0..Module is in neutral mode. Output is same as primary input.
 *  0b1..Module is in blending mode.
 */
#define layerbl2_CONTR_MODE2(x)                  (((uint32_t)(((uint32_t)(x)) << layerbl2_CONTR_MODE2_SHIFT)) & layerbl2_CONTR_MODE2_MASK)

#define layerbl2_CONTR_AlpMaE_MASK               (0x4U)
#define layerbl2_CONTR_AlpMaE_SHIFT              (2U)
/*! AlpMaE - AlphaMaskEnable
 *  0b0..AlphaMask feature disabled
 *  0b1..AlphaMask feature enabled
 */
#define layerbl2_CONTR_AlpMaE(x)                 (((uint32_t)(((uint32_t)(x)) << layerbl2_CONTR_AlpMaE_SHIFT)) & layerbl2_CONTR_AlpMaE_MASK)

#define layerbl2_CONTR_AlpMMode_MASK             (0x70U)
#define layerbl2_CONTR_AlpMMode_SHIFT            (4U)
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
#define layerbl2_CONTR_AlpMMode(x)               (((uint32_t)(((uint32_t)(x)) << layerbl2_CONTR_AlpMMode_SHIFT)) & layerbl2_CONTR_AlpMMode_MASK)

#define layerbl2_CONTR_ScLwPaEn_MASK             (0x100U)
#define layerbl2_CONTR_ScLwPaEn_SHIFT            (8U)
/*! ScLwPaEn - SecLowPassEn */
#define layerbl2_CONTR_ScLwPaEn(x)               (((uint32_t)(((uint32_t)(x)) << layerbl2_CONTR_ScLwPaEn_SHIFT)) & layerbl2_CONTR_ScLwPaEn_MASK)

#define layerbl2_CONTR_ScReplEn_MASK             (0x200U)
#define layerbl2_CONTR_ScReplEn_SHIFT            (9U)
/*! ScReplEn - SecReplicateEn */
#define layerbl2_CONTR_ScReplEn(x)               (((uint32_t)(((uint32_t)(x)) << layerbl2_CONTR_ScReplEn_SHIFT)) & layerbl2_CONTR_ScReplEn_MASK)

#define layerbl2_CONTR_ScEREvCD_MASK             (0x3C00U)
#define layerbl2_CONTR_ScEREvCD_SHIFT            (10U)
/*! ScEREvCD - SecEvenRowEvenColDis */
#define layerbl2_CONTR_ScEREvCD(x)               (((uint32_t)(((uint32_t)(x)) << layerbl2_CONTR_ScEREvCD_SHIFT)) & layerbl2_CONTR_ScEREvCD_MASK)

#define layerbl2_CONTR_ScEROdCD_MASK             (0x3C000U)
#define layerbl2_CONTR_ScEROdCD_SHIFT            (14U)
/*! ScEROdCD - SecEvenRowOddColDis */
#define layerbl2_CONTR_ScEROdCD(x)               (((uint32_t)(((uint32_t)(x)) << layerbl2_CONTR_ScEROdCD_SHIFT)) & layerbl2_CONTR_ScEROdCD_MASK)

#define layerbl2_CONTR_ScORECD_MASK              (0x3C0000U)
#define layerbl2_CONTR_ScORECD_SHIFT             (18U)
/*! ScORECD - SecOddRowEvenColDis */
#define layerbl2_CONTR_ScORECD(x)                (((uint32_t)(((uint32_t)(x)) << layerbl2_CONTR_ScORECD_SHIFT)) & layerbl2_CONTR_ScORECD_MASK)

#define layerbl2_CONTR_ScOROCD_MASK              (0x3C00000U)
#define layerbl2_CONTR_ScOROCD_SHIFT             (22U)
/*! ScOROCD - SecOddRowOddColDis */
#define layerbl2_CONTR_ScOROCD(x)                (((uint32_t)(((uint32_t)(x)) << layerbl2_CONTR_ScOROCD_SHIFT)) & layerbl2_CONTR_ScOROCD_MASK)
/*! @} */

/*! @name BLENDCON - BlendControl */
/*! @{ */

#define layerbl2_BLENDCON_PRICBLDF_MASK          (0x7U)
#define layerbl2_BLENDCON_PRICBLDF_SHIFT         (0U)
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
#define layerbl2_BLENDCON_PRICBLDF(x)            (((uint32_t)(((uint32_t)(x)) << layerbl2_BLENDCON_PRICBLDF_SHIFT)) & layerbl2_BLENDCON_PRICBLDF_MASK)

#define layerbl2_BLENDCON_SECCBLDF_MASK          (0x70U)
#define layerbl2_BLENDCON_SECCBLDF_SHIFT         (4U)
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
#define layerbl2_BLENDCON_SECCBLDF(x)            (((uint32_t)(((uint32_t)(x)) << layerbl2_BLENDCON_SECCBLDF_SHIFT)) & layerbl2_BLENDCON_SECCBLDF_MASK)

#define layerbl2_BLENDCON_PRIABLDF_MASK          (0x700U)
#define layerbl2_BLENDCON_PRIABLDF_SHIFT         (8U)
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
#define layerbl2_BLENDCON_PRIABLDF(x)            (((uint32_t)(((uint32_t)(x)) << layerbl2_BLENDCON_PRIABLDF_SHIFT)) & layerbl2_BLENDCON_PRIABLDF_MASK)

#define layerbl2_BLENDCON_SECABLDF_MASK          (0x7000U)
#define layerbl2_BLENDCON_SECABLDF_SHIFT         (12U)
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
#define layerbl2_BLENDCON_SECABLDF(x)            (((uint32_t)(((uint32_t)(x)) << layerbl2_BLENDCON_SECABLDF_SHIFT)) & layerbl2_BLENDCON_SECABLDF_MASK)

#define layerbl2_BLENDCON_BlendAlp_MASK          (0xFF0000U)
#define layerbl2_BLENDCON_BlendAlp_SHIFT         (16U)
/*! BlendAlp - BlendAlpha */
#define layerbl2_BLENDCON_BlendAlp(x)            (((uint32_t)(((uint32_t)(x)) << layerbl2_BLENDCON_BlendAlp_SHIFT)) & layerbl2_BLENDCON_BlendAlp_MASK)
/*! @} */

/*! @name POSITION - Position */
/*! @{ */

#define layerbl2_POSITION_XPOS_MASK              (0xFFFFU)
#define layerbl2_POSITION_XPOS_SHIFT             (0U)
/*! XPOS - XPOS */
#define layerbl2_POSITION_XPOS(x)                (((uint32_t)(((uint32_t)(x)) << layerbl2_POSITION_XPOS_SHIFT)) & layerbl2_POSITION_XPOS_MASK)

#define layerbl2_POSITION_YPOS_MASK              (0xFFFF0000U)
#define layerbl2_POSITION_YPOS_SHIFT             (16U)
/*! YPOS - YPOS */
#define layerbl2_POSITION_YPOS(x)                (((uint32_t)(((uint32_t)(x)) << layerbl2_POSITION_YPOS_SHIFT)) & layerbl2_POSITION_YPOS_MASK)
/*! @} */

/*! @name PRIMCOWO - PrimControlWord */
/*! @{ */

#define layerbl2_PRIMCOWO_PVAL_MASK              (0xFFFFFFFFU)
#define layerbl2_PRIMCOWO_PVAL_SHIFT             (0U)
/*! PVAL - P_VAL */
#define layerbl2_PRIMCOWO_PVAL(x)                (((uint32_t)(((uint32_t)(x)) << layerbl2_PRIMCOWO_PVAL_SHIFT)) & layerbl2_PRIMCOWO_PVAL_MASK)
/*! @} */

/*! @name SECCONTW - SecControlWord */
/*! @{ */

#define layerbl2_SECCONTW_SVAL_MASK              (0xFFFFFFFFU)
#define layerbl2_SECCONTW_SVAL_SHIFT             (0U)
/*! SVAL - S_VAL */
#define layerbl2_SECCONTW_SVAL(x)                (((uint32_t)(((uint32_t)(x)) << layerbl2_SECCONTW_SVAL_SHIFT)) & layerbl2_SECCONTW_SVAL_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group layerbl2_Register_Masks */


/*!
 * @}
 */ /* end of group layerbl2_Peripheral_Access_Layer */


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


#endif  /* PERI_LAYERBL2_H_ */

