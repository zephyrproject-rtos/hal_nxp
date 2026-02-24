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
**         CMSIS Peripheral Access Layer for framegen
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
 * @file PERI_framegen.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for framegen
 *
 * CMSIS Peripheral Access Layer for framegen
 */

#if !defined(PERI_FRAMEGEN_H_)
#define PERI_FRAMEGEN_H_                         /**< Symbol preventing repeated inclusion */

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
   -- framegen Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup framegen_Peripheral_Access_Layer framegen Peripheral Access Layer
 * @{
 */

/** framegen - Register Layout Typedef */
typedef struct {
  __O  uint32_t LU;                                /**< LockUnlock, offset: 0x0 */
  __I  uint32_t LOCKS;                             /**< LockStatus, offset: 0x4 */
  __IO uint32_t FGSTCTRL;                          /**< FgStCtrl, offset: 0x8 */
  __IO uint32_t HTCFG1;                            /**< HtCfg1, offset: 0xC */
  __IO uint32_t HTCFG2;                            /**< HtCfg2, offset: 0x10 */
  __IO uint32_t VTCFG1;                            /**< VtCfg1, offset: 0x14 */
  __IO uint32_t VTCFG2;                            /**< VtCfg2, offset: 0x18 */
  __IO uint32_t INT0CFG;                           /**< Int0Config, offset: 0x1C */
  __IO uint32_t INT1CFG;                           /**< Int1Config, offset: 0x20 */
  __IO uint32_t INT2CFG;                           /**< Int2Config, offset: 0x24 */
  __IO uint32_t INT3CFG;                           /**< Int3Config, offset: 0x28 */
  __IO uint32_t PKICKCO;                           /**< PKickConfig, offset: 0x2C */
  __IO uint32_t SKICKCON;                          /**< SKickConfig, offset: 0x30 */
  __IO uint32_t SECSTATC;                          /**< SecStatConfig, offset: 0x34 */
  __IO uint32_t FGSRCR1;                           /**< FgSRCR1, offset: 0x38 */
  __IO uint32_t FGSRCR2;                           /**< FgSRCR2, offset: 0x3C */
  __IO uint32_t FGSRCR3;                           /**< FgSRCR3, offset: 0x40 */
  __IO uint32_t FGSRCR4;                           /**< FgSRCR4, offset: 0x44 */
  __IO uint32_t FGSRCR5;                           /**< FgSRCR5, offset: 0x48 */
  __IO uint32_t FGSRCR6;                           /**< FgSRCR6, offset: 0x4C */
  __IO uint32_t FGSRCR7;                           /**< FgSRCR7, offset: 0x50 */
  __IO uint32_t FGSRCR8;                           /**< FgSRCR8, offset: 0x54 */
  __IO uint32_t FGSRCR9;                           /**< FgSRCR9, offset: 0x58 */
  __IO uint32_t FGSRCR10;                          /**< FgSRCR10, offset: 0x5C */
  __IO uint32_t FGSRCR11;                          /**< FgSRCR11, offset: 0x60 */
  __IO uint32_t FGSRCR12;                          /**< FgSRCR12, offset: 0x64 */
  __IO uint32_t FGSRCR13;                          /**< FgSRCR13, offset: 0x68 */
  __IO uint32_t FGSRCR14;                          /**< FgSRCR14, offset: 0x6C */
  __IO uint32_t FGSRCR15;                          /**< FgSRCR15, offset: 0x70 */
  __IO uint32_t FGKSDR;                            /**< FgKSDR, offset: 0x74 */
  __IO uint32_t PACFG;                             /**< PaCfg, offset: 0x78 */
  __IO uint32_t SACFG;                             /**< SaCfg, offset: 0x7C */
  __IO uint32_t FGINCTL;                           /**< FgInCtrl, offset: 0x80 */
  __IO uint32_t FGINCTLP;                          /**< FgInCtrlPanic, offset: 0x84 */
  __IO uint32_t FGCCR;                             /**< FgCCR, offset: 0x88 */
  __IO uint32_t FGENABLE;                          /**< FgEnable, offset: 0x8C */
  __O  uint32_t FGSLR;                             /**< FgSlr, offset: 0x90 */
  __I  uint32_t FGENSTS;                           /**< FgEnSts, offset: 0x94 */
  __I  uint32_t FGTIMEST;                          /**< FgTimeStamp, offset: 0x98 */
  __I  uint32_t FGCHSTT;                           /**< FgChStat, offset: 0x9C */
  __O  uint32_t FGCHSTTC;                          /**< FgChStatClr, offset: 0xA0 */
  __I  uint32_t FGSKEWMO;                          /**< FgSkewMon, offset: 0xA4 */
  __I  uint32_t FGPFIMIN;                          /**< FgPFifoMin, offset: 0xA8 */
  __I  uint32_t FGPFIMAX;                          /**< FgPFifoMax, offset: 0xAC */
  __O  uint32_t FGPFIFC;                           /**< FgPFifoFillClr, offset: 0xB0 */
  __IO uint32_t FGPFITRS;                          /**< FgPFifoTres, offset: 0xB4 */
  __I  uint32_t FGSFIMIN;                          /**< FgSFifoMin, offset: 0xB8 */
  __I  uint32_t FGSFIMAX;                          /**< FgSFifoMax, offset: 0xBC */
  __O  uint32_t FGSFIFC;                           /**< FgSFifoFillClr, offset: 0xC0 */
  __I  uint32_t FGSREPD;                           /**< FgSrEpD, offset: 0xC4 */
  __I  uint32_t FGSRFTD;                           /**< FgSrFtD, offset: 0xC8 */
  __I  uint32_t FGSRCSHT;                          /**< FgSrCSHTotal, offset: 0xCC */
  __I  uint32_t FGSRCKDI;                          /**< FgSrClockDiv, offset: 0xD0 */
  __I  uint32_t FGSL;                              /**< FgSl, offset: 0xD4 */
  __I  uint32_t FGSKEWDB;                          /**< FgSkewDebug, offset: 0xD8 */
} framegen_Type;

/* ----------------------------------------------------------------------------
   -- framegen Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup framegen_Register_Masks framegen Register Masks
 * @{
 */

/*! @name LU - LockUnlock */
/*! @{ */

#define framegen_LU_LkUn_MASK                    (0xFFFFFFFFU)
#define framegen_LU_LkUn_SHIFT                   (0U)
/*! LkUn - LockUnlock
 *  0b01010110010100011111011101100011..Decrements the unlock counter. When the counter value is null, lock protection is active. Reset counter value is 1.
 *  0b01101001000111011011100100110110..Increments the unlock counter. Max allowed value is 15.
 *  0b10101110111010010101110011011100..Enables privilege protection. Disabled after reset.
 *  0b10110101111000100100011001101110..Disables privilege protection.
 *  0b11111011111010001011000111100110..Freezes current protection status. Writing keys to this register has no more effect until reset.
 */
#define framegen_LU_LkUn(x)                      (((uint32_t)(((uint32_t)(x)) << framegen_LU_LkUn_SHIFT)) & framegen_LU_LkUn_MASK)
/*! @} */

/*! @name LOCKS - LockStatus */
/*! @{ */

#define framegen_LOCKS_LkSus_MASK                (0x1U)
#define framegen_LOCKS_LkSus_SHIFT               (0U)
/*! LkSus - LockStatus */
#define framegen_LOCKS_LkSus(x)                  (((uint32_t)(((uint32_t)(x)) << framegen_LOCKS_LkSus_SHIFT)) & framegen_LOCKS_LkSus_MASK)

#define framegen_LOCKS_PriSt_MASK                (0x10U)
#define framegen_LOCKS_PriSt_SHIFT               (4U)
/*! PriSt - PrivilegeStatus */
#define framegen_LOCKS_PriSt(x)                  (((uint32_t)(((uint32_t)(x)) << framegen_LOCKS_PriSt_SHIFT)) & framegen_LOCKS_PriSt_MASK)

#define framegen_LOCKS_FreezeS_MASK              (0x100U)
#define framegen_LOCKS_FreezeS_SHIFT             (8U)
/*! FreezeS - FreezeStatus */
#define framegen_LOCKS_FreezeS(x)                (((uint32_t)(((uint32_t)(x)) << framegen_LOCKS_FreezeS_SHIFT)) & framegen_LOCKS_FreezeS_MASK)
/*! @} */

/*! @name FGSTCTRL - FgStCtrl */
/*! @{ */

#define framegen_FGSTCTRL_ShdEn_MASK             (0x1U)
#define framegen_FGSTCTRL_ShdEn_SHIFT            (0U)
/*! ShdEn - ShdEn */
#define framegen_FGSTCTRL_ShdEn(x)               (((uint32_t)(((uint32_t)(x)) << framegen_FGSTCTRL_ShdEn_SHIFT)) & framegen_FGSTCTRL_ShdEn_MASK)

#define framegen_FGSTCTRL_FgSyMode_MASK          (0xEU)
#define framegen_FGSTCTRL_FgSyMode_SHIFT         (1U)
/*! FgSyMode
 *  0b000..No side-by-side synchronization.
 *  0b001..Framegen is initiator.
 *  0b010..Framegen is target. Runs in cyclic synchronization mode.
 *  0b011..Framegen is target. Runs in one time synchronization mode.
 *  0b110..Framegen is target. Runs in cyclic synchronization mode. Size is adapted.
 *  0b111..Framegen is target. Runs in one time synchronization mode. Size is adapted.
 */
#define framegen_FGSTCTRL_FgSyMode(x)            (((uint32_t)(((uint32_t)(x)) << framegen_FGSTCTRL_FgSyMode_SHIFT)) & framegen_FGSTCTRL_FgSyMode_MASK)

#define framegen_FGSTCTRL_FgSTGSM_MASK           (0x10U)
#define framegen_FGSTCTRL_FgSTGSM_SHIFT          (4U)
/*! FgSTGSM - FgShdTokGenSyncMode
 *  0b0..Shadow token is generated by local FgSlr.ShdTokGen field.
 *  0b1..Shadow token is generated by FgSlr.ShdTokGen field of second framegenerator.
 */
#define framegen_FGSTCTRL_FgSTGSM(x)             (((uint32_t)(((uint32_t)(x)) << framegen_FGSTCTRL_FgSTGSM_SHIFT)) & framegen_FGSTCTRL_FgSTGSM_MASK)

#define framegen_FGSTCTRL_ForceD_MASK            (0x40000000U)
#define framegen_FGSTCTRL_ForceD_SHIFT           (30U)
/*! ForceD - Force_Disable */
#define framegen_FGSTCTRL_ForceD(x)              (((uint32_t)(((uint32_t)(x)) << framegen_FGSTCTRL_ForceD_SHIFT)) & framegen_FGSTCTRL_ForceD_MASK)
/*! @} */

/*! @name HTCFG1 - HtCfg1 */
/*! @{ */

#define framegen_HTCFG1_Hact_MASK                (0x3FFFU)
#define framegen_HTCFG1_Hact_SHIFT               (0U)
/*! Hact - Hact */
#define framegen_HTCFG1_Hact(x)                  (((uint32_t)(((uint32_t)(x)) << framegen_HTCFG1_Hact_SHIFT)) & framegen_HTCFG1_Hact_MASK)

#define framegen_HTCFG1_Htl_MASK                 (0x3FFF0000U)
#define framegen_HTCFG1_Htl_SHIFT                (16U)
/*! Htl - Htotal */
#define framegen_HTCFG1_Htl(x)                   (((uint32_t)(((uint32_t)(x)) << framegen_HTCFG1_Htl_SHIFT)) & framegen_HTCFG1_Htl_MASK)
/*! @} */

/*! @name HTCFG2 - HtCfg2 */
/*! @{ */

#define framegen_HTCFG2_Hsync_MASK               (0x3FFFU)
#define framegen_HTCFG2_Hsync_SHIFT              (0U)
/*! Hsync - Hsync */
#define framegen_HTCFG2_Hsync(x)                 (((uint32_t)(((uint32_t)(x)) << framegen_HTCFG2_Hsync_SHIFT)) & framegen_HTCFG2_Hsync_MASK)

#define framegen_HTCFG2_Hsbp_MASK                (0x3FFF0000U)
#define framegen_HTCFG2_Hsbp_SHIFT               (16U)
/*! Hsbp - Hsbp */
#define framegen_HTCFG2_Hsbp(x)                  (((uint32_t)(((uint32_t)(x)) << framegen_HTCFG2_Hsbp_SHIFT)) & framegen_HTCFG2_Hsbp_MASK)

#define framegen_HTCFG2_HsEn_MASK                (0x80000000U)
#define framegen_HTCFG2_HsEn_SHIFT               (31U)
/*! HsEn - HsEn */
#define framegen_HTCFG2_HsEn(x)                  (((uint32_t)(((uint32_t)(x)) << framegen_HTCFG2_HsEn_SHIFT)) & framegen_HTCFG2_HsEn_MASK)
/*! @} */

/*! @name VTCFG1 - VtCfg1 */
/*! @{ */

#define framegen_VTCFG1_Vact_MASK                (0x3FFFU)
#define framegen_VTCFG1_Vact_SHIFT               (0U)
/*! Vact - Vact */
#define framegen_VTCFG1_Vact(x)                  (((uint32_t)(((uint32_t)(x)) << framegen_VTCFG1_Vact_SHIFT)) & framegen_VTCFG1_Vact_MASK)

#define framegen_VTCFG1_Vtotal_MASK              (0x3FFF0000U)
#define framegen_VTCFG1_Vtotal_SHIFT             (16U)
/*! Vtotal - Vtotal */
#define framegen_VTCFG1_Vtotal(x)                (((uint32_t)(((uint32_t)(x)) << framegen_VTCFG1_Vtotal_SHIFT)) & framegen_VTCFG1_Vtotal_MASK)
/*! @} */

/*! @name VTCFG2 - VtCfg2 */
/*! @{ */

#define framegen_VTCFG2_Vsync_MASK               (0x3FFFU)
#define framegen_VTCFG2_Vsync_SHIFT              (0U)
/*! Vsync - Vsync */
#define framegen_VTCFG2_Vsync(x)                 (((uint32_t)(((uint32_t)(x)) << framegen_VTCFG2_Vsync_SHIFT)) & framegen_VTCFG2_Vsync_MASK)

#define framegen_VTCFG2_Vsbp_MASK                (0x3FFF0000U)
#define framegen_VTCFG2_Vsbp_SHIFT               (16U)
/*! Vsbp - Vsbp */
#define framegen_VTCFG2_Vsbp(x)                  (((uint32_t)(((uint32_t)(x)) << framegen_VTCFG2_Vsbp_SHIFT)) & framegen_VTCFG2_Vsbp_MASK)

#define framegen_VTCFG2_VsAlign_MASK             (0x40000000U)
#define framegen_VTCFG2_VsAlign_SHIFT            (30U)
/*! VsAlign - VsAlign */
#define framegen_VTCFG2_VsAlign(x)               (((uint32_t)(((uint32_t)(x)) << framegen_VTCFG2_VsAlign_SHIFT)) & framegen_VTCFG2_VsAlign_MASK)

#define framegen_VTCFG2_VsEn_MASK                (0x80000000U)
#define framegen_VTCFG2_VsEn_SHIFT               (31U)
/*! VsEn - VsEn */
#define framegen_VTCFG2_VsEn(x)                  (((uint32_t)(((uint32_t)(x)) << framegen_VTCFG2_VsEn_SHIFT)) & framegen_VTCFG2_VsEn_MASK)
/*! @} */

/*! @name INT0CFG - Int0Config */
/*! @{ */

#define framegen_INT0CFG_Int0Col_MASK            (0x3FFFU)
#define framegen_INT0CFG_Int0Col_SHIFT           (0U)
/*! Int0Col - Int0Col */
#define framegen_INT0CFG_Int0Col(x)              (((uint32_t)(((uint32_t)(x)) << framegen_INT0CFG_Int0Col_SHIFT)) & framegen_INT0CFG_Int0Col_MASK)

#define framegen_INT0CFG_Int0HsEn_MASK           (0x8000U)
#define framegen_INT0CFG_Int0HsEn_SHIFT          (15U)
/*! Int0HsEn - Int0HsEn */
#define framegen_INT0CFG_Int0HsEn(x)             (((uint32_t)(((uint32_t)(x)) << framegen_INT0CFG_Int0HsEn_SHIFT)) & framegen_INT0CFG_Int0HsEn_MASK)

#define framegen_INT0CFG_Int0Row_MASK            (0x3FFF0000U)
#define framegen_INT0CFG_Int0Row_SHIFT           (16U)
/*! Int0Row - Int0Row */
#define framegen_INT0CFG_Int0Row(x)              (((uint32_t)(((uint32_t)(x)) << framegen_INT0CFG_Int0Row_SHIFT)) & framegen_INT0CFG_Int0Row_MASK)

#define framegen_INT0CFG_Int0En_MASK             (0x80000000U)
#define framegen_INT0CFG_Int0En_SHIFT            (31U)
/*! Int0En - Int0En */
#define framegen_INT0CFG_Int0En(x)               (((uint32_t)(((uint32_t)(x)) << framegen_INT0CFG_Int0En_SHIFT)) & framegen_INT0CFG_Int0En_MASK)
/*! @} */

/*! @name INT1CFG - Int1Config */
/*! @{ */

#define framegen_INT1CFG_Int1Col_MASK            (0x3FFFU)
#define framegen_INT1CFG_Int1Col_SHIFT           (0U)
/*! Int1Col - Int1Col */
#define framegen_INT1CFG_Int1Col(x)              (((uint32_t)(((uint32_t)(x)) << framegen_INT1CFG_Int1Col_SHIFT)) & framegen_INT1CFG_Int1Col_MASK)

#define framegen_INT1CFG_Int1HsEn_MASK           (0x8000U)
#define framegen_INT1CFG_Int1HsEn_SHIFT          (15U)
/*! Int1HsEn - Int1HsEn */
#define framegen_INT1CFG_Int1HsEn(x)             (((uint32_t)(((uint32_t)(x)) << framegen_INT1CFG_Int1HsEn_SHIFT)) & framegen_INT1CFG_Int1HsEn_MASK)

#define framegen_INT1CFG_Int1Row_MASK            (0x3FFF0000U)
#define framegen_INT1CFG_Int1Row_SHIFT           (16U)
/*! Int1Row - Int1Row */
#define framegen_INT1CFG_Int1Row(x)              (((uint32_t)(((uint32_t)(x)) << framegen_INT1CFG_Int1Row_SHIFT)) & framegen_INT1CFG_Int1Row_MASK)

#define framegen_INT1CFG_Int1En_MASK             (0x80000000U)
#define framegen_INT1CFG_Int1En_SHIFT            (31U)
/*! Int1En - Int1En */
#define framegen_INT1CFG_Int1En(x)               (((uint32_t)(((uint32_t)(x)) << framegen_INT1CFG_Int1En_SHIFT)) & framegen_INT1CFG_Int1En_MASK)
/*! @} */

/*! @name INT2CFG - Int2Config */
/*! @{ */

#define framegen_INT2CFG_Int2Col_MASK            (0x3FFFU)
#define framegen_INT2CFG_Int2Col_SHIFT           (0U)
/*! Int2Col - Int2Col */
#define framegen_INT2CFG_Int2Col(x)              (((uint32_t)(((uint32_t)(x)) << framegen_INT2CFG_Int2Col_SHIFT)) & framegen_INT2CFG_Int2Col_MASK)

#define framegen_INT2CFG_Int2HsEn_MASK           (0x8000U)
#define framegen_INT2CFG_Int2HsEn_SHIFT          (15U)
/*! Int2HsEn - Int2HsEn */
#define framegen_INT2CFG_Int2HsEn(x)             (((uint32_t)(((uint32_t)(x)) << framegen_INT2CFG_Int2HsEn_SHIFT)) & framegen_INT2CFG_Int2HsEn_MASK)

#define framegen_INT2CFG_Int2Row_MASK            (0x3FFF0000U)
#define framegen_INT2CFG_Int2Row_SHIFT           (16U)
/*! Int2Row - Int2Row */
#define framegen_INT2CFG_Int2Row(x)              (((uint32_t)(((uint32_t)(x)) << framegen_INT2CFG_Int2Row_SHIFT)) & framegen_INT2CFG_Int2Row_MASK)

#define framegen_INT2CFG_Int2En_MASK             (0x80000000U)
#define framegen_INT2CFG_Int2En_SHIFT            (31U)
/*! Int2En - Int2En */
#define framegen_INT2CFG_Int2En(x)               (((uint32_t)(((uint32_t)(x)) << framegen_INT2CFG_Int2En_SHIFT)) & framegen_INT2CFG_Int2En_MASK)
/*! @} */

/*! @name INT3CFG - Int3Config */
/*! @{ */

#define framegen_INT3CFG_Int3Col_MASK            (0x3FFFU)
#define framegen_INT3CFG_Int3Col_SHIFT           (0U)
/*! Int3Col - Int3Col */
#define framegen_INT3CFG_Int3Col(x)              (((uint32_t)(((uint32_t)(x)) << framegen_INT3CFG_Int3Col_SHIFT)) & framegen_INT3CFG_Int3Col_MASK)

#define framegen_INT3CFG_Int3HsEn_MASK           (0x8000U)
#define framegen_INT3CFG_Int3HsEn_SHIFT          (15U)
/*! Int3HsEn - Int3HsEn */
#define framegen_INT3CFG_Int3HsEn(x)             (((uint32_t)(((uint32_t)(x)) << framegen_INT3CFG_Int3HsEn_SHIFT)) & framegen_INT3CFG_Int3HsEn_MASK)

#define framegen_INT3CFG_Int3Row_MASK            (0x3FFF0000U)
#define framegen_INT3CFG_Int3Row_SHIFT           (16U)
/*! Int3Row - Int3Row */
#define framegen_INT3CFG_Int3Row(x)              (((uint32_t)(((uint32_t)(x)) << framegen_INT3CFG_Int3Row_SHIFT)) & framegen_INT3CFG_Int3Row_MASK)

#define framegen_INT3CFG_Int3En_MASK             (0x80000000U)
#define framegen_INT3CFG_Int3En_SHIFT            (31U)
/*! Int3En - Int3En */
#define framegen_INT3CFG_Int3En(x)               (((uint32_t)(((uint32_t)(x)) << framegen_INT3CFG_Int3En_SHIFT)) & framegen_INT3CFG_Int3En_MASK)
/*! @} */

/*! @name PKICKCO - PKickConfig */
/*! @{ */

#define framegen_PKICKCO_PKickCol_MASK           (0x3FFFU)
#define framegen_PKICKCO_PKickCol_SHIFT          (0U)
/*! PKickCol - PKickCol */
#define framegen_PKICKCO_PKickCol(x)             (((uint32_t)(((uint32_t)(x)) << framegen_PKICKCO_PKickCol_SHIFT)) & framegen_PKICKCO_PKickCol_MASK)

#define framegen_PKICKCO_PKInt0En_MASK           (0x8000U)
#define framegen_PKICKCO_PKInt0En_SHIFT          (15U)
/*! PKInt0En - PKickInt0En */
#define framegen_PKICKCO_PKInt0En(x)             (((uint32_t)(((uint32_t)(x)) << framegen_PKICKCO_PKInt0En_SHIFT)) & framegen_PKICKCO_PKInt0En_MASK)

#define framegen_PKICKCO_PKickRow_MASK           (0x3FFF0000U)
#define framegen_PKICKCO_PKickRow_SHIFT          (16U)
/*! PKickRow - PKickRow */
#define framegen_PKICKCO_PKickRow(x)             (((uint32_t)(((uint32_t)(x)) << framegen_PKICKCO_PKickRow_SHIFT)) & framegen_PKICKCO_PKickRow_MASK)

#define framegen_PKICKCO_PKickEn_MASK            (0x80000000U)
#define framegen_PKICKCO_PKickEn_SHIFT           (31U)
/*! PKickEn - PKickEn */
#define framegen_PKICKCO_PKickEn(x)              (((uint32_t)(((uint32_t)(x)) << framegen_PKICKCO_PKickEn_SHIFT)) & framegen_PKICKCO_PKickEn_MASK)
/*! @} */

/*! @name SKICKCON - SKickConfig */
/*! @{ */

#define framegen_SKICKCON_SKickCol_MASK          (0x3FFFU)
#define framegen_SKICKCON_SKickCol_SHIFT         (0U)
/*! SKickCol - SKickCol */
#define framegen_SKICKCON_SKickCol(x)            (((uint32_t)(((uint32_t)(x)) << framegen_SKICKCON_SKickCol_SHIFT)) & framegen_SKICKCON_SKickCol_MASK)

#define framegen_SKICKCON_SKickIEn_MASK          (0x8000U)
#define framegen_SKICKCON_SKickIEn_SHIFT         (15U)
/*! SKickIEn - SKickInt1En */
#define framegen_SKICKCON_SKickIEn(x)            (((uint32_t)(((uint32_t)(x)) << framegen_SKICKCON_SKickIEn_SHIFT)) & framegen_SKICKCON_SKickIEn_MASK)

#define framegen_SKICKCON_SKickRow_MASK          (0x3FFF0000U)
#define framegen_SKICKCON_SKickRow_SHIFT         (16U)
/*! SKickRow - SKickRow */
#define framegen_SKICKCON_SKickRow(x)            (((uint32_t)(((uint32_t)(x)) << framegen_SKICKCON_SKickRow_SHIFT)) & framegen_SKICKCON_SKickRow_MASK)

#define framegen_SKICKCON_SKickTr_MASK           (0x40000000U)
#define framegen_SKICKCON_SKickTr_SHIFT          (30U)
/*! SKickTr - SKickTrig
 *  0b0..Use internal skick signal, trigger point defined by SKickRow and SKickCol.
 *  0b1..Use external skick input as trigger.
 */
#define framegen_SKICKCON_SKickTr(x)             (((uint32_t)(((uint32_t)(x)) << framegen_SKICKCON_SKickTr_SHIFT)) & framegen_SKICKCON_SKickTr_MASK)

#define framegen_SKICKCON_SKickEn_MASK           (0x80000000U)
#define framegen_SKICKCON_SKickEn_SHIFT          (31U)
/*! SKickEn - SKickEn */
#define framegen_SKICKCON_SKickEn(x)             (((uint32_t)(((uint32_t)(x)) << framegen_SKICKCON_SKickEn_SHIFT)) & framegen_SKICKCON_SKickEn_MASK)
/*! @} */

/*! @name SECSTATC - SecStatConfig */
/*! @{ */

#define framegen_SECSTATC_LevGodFr_MASK          (0xFU)
#define framegen_SECSTATC_LevGodFr_SHIFT         (0U)
/*! LevGodFr - LevGoodFrames */
#define framegen_SECSTATC_LevGodFr(x)            (((uint32_t)(((uint32_t)(x)) << framegen_SECSTATC_LevGodFr_SHIFT)) & framegen_SECSTATC_LevGodFr_MASK)

#define framegen_SECSTATC_LevBadFr_MASK          (0xF0U)
#define framegen_SECSTATC_LevBadFr_SHIFT         (4U)
/*! LevBadFr - LevBadFrames */
#define framegen_SECSTATC_LevBadFr(x)            (((uint32_t)(((uint32_t)(x)) << framegen_SECSTATC_LevBadFr_SHIFT)) & framegen_SECSTATC_LevBadFr_MASK)

#define framegen_SECSTATC_LevSkInR_MASK          (0xF00U)
#define framegen_SECSTATC_LevSkInR_SHIFT         (8U)
/*! LevSkInR - LevSkewInRange */
#define framegen_SECSTATC_LevSkInR(x)            (((uint32_t)(((uint32_t)(x)) << framegen_SECSTATC_LevSkInR_SHIFT)) & framegen_SECSTATC_LevSkInR_MASK)
/*! @} */

/*! @name FGSRCR1 - FgSRCR1 */
/*! @{ */

#define framegen_FGSRCR1_SREn_MASK               (0x1U)
#define framegen_FGSRCR1_SREn_SHIFT              (0U)
/*! SREn - SREn */
#define framegen_FGSRCR1_SREn(x)                 (((uint32_t)(((uint32_t)(x)) << framegen_FGSRCR1_SREn_SHIFT)) & framegen_FGSRCR1_SREn_MASK)

#define framegen_FGSRCR1_SRMode_MASK             (0x6U)
#define framegen_FGSRCR1_SRMode_SHIFT            (1U)
/*! SRMode - SRMode
 *  0b00..Skew Regulation is off.
 *  0b01..Horizontal regulation enabled.
 *  0b10..Vertical regulation enabled.
 *  0b11..Both regulation modes are enabled.
 */
#define framegen_FGSRCR1_SRMode(x)               (((uint32_t)(((uint32_t)(x)) << framegen_FGSRCR1_SRMode_SHIFT)) & framegen_FGSRCR1_SRMode_MASK)

#define framegen_FGSRCR1_SRAdj_MASK              (0x8U)
#define framegen_FGSRCR1_SRAdj_SHIFT             (3U)
/*! SRAdj - SRAdj */
#define framegen_FGSRCR1_SRAdj(x)                (((uint32_t)(((uint32_t)(x)) << framegen_FGSRCR1_SRAdj_SHIFT)) & framegen_FGSRCR1_SRAdj_MASK)

#define framegen_FGSRCR1_SREven_MASK             (0x10U)
#define framegen_FGSRCR1_SREven_SHIFT            (4U)
/*! SREven - SREven */
#define framegen_FGSRCR1_SREven(x)               (((uint32_t)(((uint32_t)(x)) << framegen_FGSRCR1_SREven_SHIFT)) & framegen_FGSRCR1_SREven_MASK)

#define framegen_FGSRCR1_SRFaSync_MASK           (0x20U)
#define framegen_FGSRCR1_SRFaSync_SHIFT          (5U)
/*! SRFaSync - SRFastSync */
#define framegen_FGSRCR1_SRFaSync(x)             (((uint32_t)(((uint32_t)(x)) << framegen_FGSRCR1_SRFaSync_SHIFT)) & framegen_FGSRCR1_SRFaSync_MASK)

#define framegen_FGSRCR1_SRQAlign_MASK           (0x40U)
#define framegen_FGSRCR1_SRQAlign_SHIFT          (6U)
/*! SRQAlign - SRQAlign */
#define framegen_FGSRCR1_SRQAlign(x)             (((uint32_t)(((uint32_t)(x)) << framegen_FGSRCR1_SRQAlign_SHIFT)) & framegen_FGSRCR1_SRQAlign_MASK)

#define framegen_FGSRCR1_SRQVal_MASK             (0x180U)
#define framegen_FGSRCR1_SRQVal_SHIFT            (7U)
/*! SRQVal - SRQVal
 *  0b00..Fixed two LSB values of HTOTAL are 0b00.
 *  0b01..Fixed two LSB values of HTOTAL are 0b01.
 *  0b10..Fixed two LSB values of HTOTAL are 0b10.
 *  0b11..Fixed two LSB values of HTOTAL are 0b11.
 */
#define framegen_FGSRCR1_SRQVal(x)               (((uint32_t)(((uint32_t)(x)) << framegen_FGSRCR1_SRQVal_SHIFT)) & framegen_FGSRCR1_SRQVal_MASK)

#define framegen_FGSRCR1_SRDDisp_MASK            (0x200U)
#define framegen_FGSRCR1_SRDDisp_SHIFT           (9U)
/*! SRDDisp - SRDbgDisp */
#define framegen_FGSRCR1_SRDDisp(x)              (((uint32_t)(((uint32_t)(x)) << framegen_FGSRCR1_SRDDisp_SHIFT)) & framegen_FGSRCR1_SRDDisp_MASK)

#define framegen_FGSRCR1_SREpOff_MASK            (0x400U)
#define framegen_FGSRCR1_SREpOff_SHIFT           (10U)
/*! SREpOff - SREpOff */
#define framegen_FGSRCR1_SREpOff(x)              (((uint32_t)(((uint32_t)(x)) << framegen_FGSRCR1_SREpOff_SHIFT)) & framegen_FGSRCR1_SREpOff_MASK)

#define framegen_FGSRCR1_SRCMode_MASK            (0x1800U)
#define framegen_FGSRCR1_SRCMode_SHIFT           (11U)
/*! SRCMode - SRClock_Mode
 *  0b00..No clock regulation.
 *  0b01..Adapt clock frequency to input frame rate. Output alignment is done with h/vtotal regulation
 *  0b10..Start with CLKADAPT till in sync, switch to ONLY after in sync.
 *  0b11..Only clock regulation.
 */
#define framegen_FGSRCR1_SRCMode(x)              (((uint32_t)(((uint32_t)(x)) << framegen_FGSRCR1_SRCMode_SHIFT)) & framegen_FGSRCR1_SRCMode_MASK)

#define framegen_FGSRCR1_SRExt_MASK              (0x2000U)
#define framegen_FGSRCR1_SRExt_SHIFT             (13U)
/*! SRExt - SRExt */
#define framegen_FGSRCR1_SRExt(x)                (((uint32_t)(((uint32_t)(x)) << framegen_FGSRCR1_SRExt_SHIFT)) & framegen_FGSRCR1_SRExt_MASK)

#define framegen_FGSRCR1_CsSyncSl_MASK           (0xC0000000U)
#define framegen_FGSRCR1_CsSyncSl_SHIFT          (30U)
/*! CsSyncSl - CsSyncSel
 *  0b00..Use APIX control signals for external sync.
 *  0b01..Use HS VS for external sync.
 *  0b10..Use DSC control signals for external sync.
 */
#define framegen_FGSRCR1_CsSyncSl(x)             (((uint32_t)(((uint32_t)(x)) << framegen_FGSRCR1_CsSyncSl_SHIFT)) & framegen_FGSRCR1_CsSyncSl_MASK)
/*! @} */

/*! @name FGSRCR2 - FgSRCR2 */
/*! @{ */

#define framegen_FGSRCR2_HTlMin_MASK             (0x3FFFU)
#define framegen_FGSRCR2_HTlMin_SHIFT            (0U)
/*! HTlMin - HTotalMin */
#define framegen_FGSRCR2_HTlMin(x)               (((uint32_t)(((uint32_t)(x)) << framegen_FGSRCR2_HTlMin_SHIFT)) & framegen_FGSRCR2_HTlMin_MASK)

#define framegen_FGSRCR2_HTlMax_MASK             (0x3FFF0000U)
#define framegen_FGSRCR2_HTlMax_SHIFT            (16U)
/*! HTlMax - HTotalMax */
#define framegen_FGSRCR2_HTlMax(x)               (((uint32_t)(((uint32_t)(x)) << framegen_FGSRCR2_HTlMax_SHIFT)) & framegen_FGSRCR2_HTlMax_MASK)
/*! @} */

/*! @name FGSRCR3 - FgSRCR3 */
/*! @{ */

#define framegen_FGSRCR3_VTotMin_MASK            (0x3FFFU)
#define framegen_FGSRCR3_VTotMin_SHIFT           (0U)
/*! VTotMin - VTotalMin */
#define framegen_FGSRCR3_VTotMin(x)              (((uint32_t)(((uint32_t)(x)) << framegen_FGSRCR3_VTotMin_SHIFT)) & framegen_FGSRCR3_VTotMin_MASK)

#define framegen_FGSRCR3_VTotMax_MASK            (0x3FFF0000U)
#define framegen_FGSRCR3_VTotMax_SHIFT           (16U)
/*! VTotMax - VTotalMax */
#define framegen_FGSRCR3_VTotMax(x)              (((uint32_t)(((uint32_t)(x)) << framegen_FGSRCR3_VTotMax_SHIFT)) & framegen_FGSRCR3_VTotMax_MASK)
/*! @} */

/*! @name FGSRCR4 - FgSRCR4 */
/*! @{ */

#define framegen_FGSRCR4_TarSkew_MASK            (0x1FFFFFFFU)
#define framegen_FGSRCR4_TarSkew_SHIFT           (0U)
/*! TarSkew - TargetSkew */
#define framegen_FGSRCR4_TarSkew(x)              (((uint32_t)(((uint32_t)(x)) << framegen_FGSRCR4_TarSkew_SHIFT)) & framegen_FGSRCR4_TarSkew_MASK)
/*! @} */

/*! @name FGSRCR5 - FgSRCR5 */
/*! @{ */

#define framegen_FGSRCR5_SynRngLo_MASK           (0x1FFFFFFFU)
#define framegen_FGSRCR5_SynRngLo_SHIFT          (0U)
/*! SynRngLo - SyncRangeLow */
#define framegen_FGSRCR5_SynRngLo(x)             (((uint32_t)(((uint32_t)(x)) << framegen_FGSRCR5_SynRngLo_SHIFT)) & framegen_FGSRCR5_SynRngLo_MASK)
/*! @} */

/*! @name FGSRCR6 - FgSRCR6 */
/*! @{ */

#define framegen_FGSRCR6_SynRngHi_MASK           (0x1FFFFFFFU)
#define framegen_FGSRCR6_SynRngHi_SHIFT          (0U)
/*! SynRngHi - SyncRangeHigh */
#define framegen_FGSRCR6_SynRngHi(x)             (((uint32_t)(((uint32_t)(x)) << framegen_FGSRCR6_SynRngHi_SHIFT)) & framegen_FGSRCR6_SynRngHi_MASK)
/*! @} */

/*! @name FGSRCR7 - FgSRCR7 */
/*! @{ */

#define framegen_FGSRCR7_HorizIn_MASK            (0x7FFFFFFU)
#define framegen_FGSRCR7_HorizIn_SHIFT           (0U)
/*! HorizIn - HorizontalIncrement */
#define framegen_FGSRCR7_HorizIn(x)              (((uint32_t)(((uint32_t)(x)) << framegen_FGSRCR7_HorizIn_SHIFT)) & framegen_FGSRCR7_HorizIn_MASK)

#define framegen_FGSRCR7_VertInc_MASK            (0xF8000000U)
#define framegen_FGSRCR7_VertInc_SHIFT           (27U)
/*! VertInc - VerticalIncrement */
#define framegen_FGSRCR7_VertInc(x)              (((uint32_t)(((uint32_t)(x)) << framegen_FGSRCR7_VertInc_SHIFT)) & framegen_FGSRCR7_VertInc_MASK)
/*! @} */

/*! @name FGSRCR8 - FgSRCR8 */
/*! @{ */

#define framegen_FGSRCR8_StartOff_MASK           (0x3FFFFU)
#define framegen_FGSRCR8_StartOff_SHIFT          (0U)
/*! StartOff - StartOffset */
#define framegen_FGSRCR8_StartOff(x)             (((uint32_t)(((uint32_t)(x)) << framegen_FGSRCR8_StartOff_SHIFT)) & framegen_FGSRCR8_StartOff_MASK)
/*! @} */

/*! @name FGSRCR9 - FgSRCR9 */
/*! @{ */

#define framegen_FGSRCR9_clocpref_MASK           (0xFFFFFU)
#define framegen_FGSRCR9_clocpref_SHIFT          (0U)
/*! clocpref - clockperiod_ref */
#define framegen_FGSRCR9_clocpref(x)             (((uint32_t)(((uint32_t)(x)) << framegen_FGSRCR9_clocpref_SHIFT)) & framegen_FGSRCR9_clocpref_MASK)
/*! @} */

/*! @name FGSRCR10 - FgSRCR10 */
/*! @{ */

#define framegen_FGSRCR10_clocpmin_MASK          (0xFFFFFU)
#define framegen_FGSRCR10_clocpmin_SHIFT         (0U)
/*! clocpmin - clockperiod_min */
#define framegen_FGSRCR10_clocpmin(x)            (((uint32_t)(((uint32_t)(x)) << framegen_FGSRCR10_clocpmin_SHIFT)) & framegen_FGSRCR10_clocpmin_MASK)
/*! @} */

/*! @name FGSRCR11 - FgSRCR11 */
/*! @{ */

#define framegen_FGSRCR11_clocpmax_MASK          (0xFFFFFU)
#define framegen_FGSRCR11_clocpmax_SHIFT         (0U)
/*! clocpmax - clockperiod_max */
#define framegen_FGSRCR11_clocpmax(x)            (((uint32_t)(((uint32_t)(x)) << framegen_FGSRCR11_clocpmax_SHIFT)) & framegen_FGSRCR11_clocpmax_MASK)
/*! @} */

/*! @name FGSRCR12 - FgSRCR12 */
/*! @{ */

#define framegen_FGSRCR12_pxlperio_MASK          (0xFFFFFFFFU)
#define framegen_FGSRCR12_pxlperio_SHIFT         (0U)
/*! pxlperio - pixel_period */
#define framegen_FGSRCR12_pxlperio(x)            (((uint32_t)(((uint32_t)(x)) << framegen_FGSRCR12_pxlperio_SHIFT)) & framegen_FGSRCR12_pxlperio_MASK)
/*! @} */

/*! @name FGSRCR13 - FgSRCR13 */
/*! @{ */

#define framegen_FGSRCR13_CSRfirat_MASK          (0xCU)
#define framegen_FGSRCR13_CSRfirat_SHIFT         (2U)
/*! CSRfirat - CSR_filterrate
 *  0b00..Clock measurement update rate defined by CSR_updaterate, no additional filter used.
 *  0b01..Clock measurements update rate defined by CSR_updaterate filtered by 4.
 *  0b10..Clock measurements update rate defined by CSR_updaterate filtered by 16.
 *  0b11..Clock measurements update rate defined by CSR_updaterate filtered by 64.
 */
#define framegen_FGSRCR13_CSRfirat(x)            (((uint32_t)(((uint32_t)(x)) << framegen_FGSRCR13_CSRfirat_SHIFT)) & framegen_FGSRCR13_CSRfirat_MASK)

#define framegen_FGSRCR13_CSRupte_MASK           (0x70U)
#define framegen_FGSRCR13_CSRupte_SHIFT          (4U)
/*! CSRupte - CSR_updaterate
 *  0b000..Clock measurement is off, reference value is used.
 *  0b100..Measured clock is averaged over 2^16 input clock cycles.
 *  0b101..Measured clock is averaged over 2^14 input clock cycles.
 *  0b110..Measured clock is averaged over 2^12 input clock cycles.
 *  0b111..Measured clock is averaged over 2^10 input clock cycles.
 */
#define framegen_FGSRCR13_CSRupte(x)             (((uint32_t)(((uint32_t)(x)) << framegen_FGSRCR13_CSRupte_SHIFT)) & framegen_FGSRCR13_CSRupte_MASK)

#define framegen_FGSRCR13_CMSyncSe_MASK          (0x80U)
#define framegen_FGSRCR13_CMSyncSe_SHIFT         (7U)
/*! CMSyncSe - CMSyncSel
 *  0b0..Use APIX control signals for clock measurement.
 *  0b1..Use HS VS for clock measurement.
 */
#define framegen_FGSRCR13_CMSyncSe(x)            (((uint32_t)(((uint32_t)(x)) << framegen_FGSRCR13_CMSyncSe_SHIFT)) & framegen_FGSRCR13_CMSyncSe_MASK)
/*! @} */

/*! @name FGSRCR14 - FgSRCR14 */
/*! @{ */

#define framegen_FGSRCR14_clocval_MASK           (0x1U)
#define framegen_FGSRCR14_clocval_SHIFT          (0U)
/*! clocval - Clockperiod_val */
#define framegen_FGSRCR14_clocval(x)             (((uint32_t)(((uint32_t)(x)) << framegen_FGSRCR14_clocval_SHIFT)) & framegen_FGSRCR14_clocval_MASK)

#define framegen_FGSRCR14_CSRSSen_MASK           (0x8U)
#define framegen_FGSRCR14_CSRSSen_SHIFT          (3U)
/*! CSRSSen - CSR_SSCGTrack_en
 *  0b0..Phase regulation does not take SSCG into account.
 *  0b1..Phase regulation does take SSCG into account.
 */
#define framegen_FGSRCR14_CSRSSen(x)             (((uint32_t)(((uint32_t)(x)) << framegen_FGSRCR14_CSRSSen_SHIFT)) & framegen_FGSRCR14_CSRSSen_MASK)

#define framegen_FGSRCR14_CSRrate_MASK           (0x70U)
#define framegen_FGSRCR14_CSRrate_SHIFT          (4U)
/*! CSRrate - CSR_ramprate
 *  0b000..Phase regulation uses phasegain for step.
 *  0b001..Phase regulation uses 1/2 of phasegain for step.
 *  0b010..Phase regulation uses 1/4 of phasegain for step.
 *  0b011..Phase regulation uses 1/8 of phasegain for step.
 *  0b100..Phase regulation uses 1/16 of phasegain for step.
 *  0b101..Phase regulation uses 1/32 of phasegain for step.
 */
#define framegen_FGSRCR14_CSRrate(x)             (((uint32_t)(((uint32_t)(x)) << framegen_FGSRCR14_CSRrate_SHIFT)) & framegen_FGSRCR14_CSRrate_MASK)

#define framegen_FGSRCR14_CSRraen_MASK           (0x80U)
#define framegen_FGSRCR14_CSRraen_SHIFT          (7U)
/*! CSRraen - CSR_ramprate_en
 *  0b0..Phase regulation uses phasegain for step.
 *  0b1..Phase regulation uses CSR_ramprate of phasegain for step.
 */
#define framegen_FGSRCR14_CSRraen(x)             (((uint32_t)(((uint32_t)(x)) << framegen_FGSRCR14_CSRraen_SHIFT)) & framegen_FGSRCR14_CSRraen_MASK)

#define framegen_FGSRCR14_CSRphgai_MASK          (0x700U)
#define framegen_FGSRCR14_CSRphgai_SHIFT         (8U)
/*! CSRphgai - CSR_phasegain
 *  0b000..Phase regulation uses 1/1024 of clock period. Htotal has to be bigger than 1025+32.
 *  0b001..Phase regulation uses 1/512 of clock period. Htotal has to be bigger than 513+32.
 *  0b010..Phase regulation uses 1/256 of clock period. Htotal has to be bigger than 257+32.
 *  0b011..Phase regulation uses 1/128 of clock period. Htotal has to be bigger than 129+32.
 *  0b100..Phase regulation uses 1/64 of clock period. Htotal has to be bigger than 65+32.
 */
#define framegen_FGSRCR14_CSRphgai(x)            (((uint32_t)(((uint32_t)(x)) << framegen_FGSRCR14_CSRphgai_SHIFT)) & framegen_FGSRCR14_CSRphgai_MASK)

#define framegen_FGSRCR14_CSRphgsy_MASK          (0x7000U)
#define framegen_FGSRCR14_CSRphgsy_SHIFT         (12U)
/*! CSRphgsy - CSR_phasegainsync
 *  0b000..Phase regulation uses 1/1024 of clock period. Htotal has to be bigger than 1025+32.
 *  0b001..Phase regulation uses 1/512 of clock period. Htotal has to be bigger than 513+32.
 *  0b010..Phase regulation uses 1/256 of clock period. Htotal has to be bigger than 257+32.
 *  0b011..Phase regulation uses 1/128 of clock period. Htotal has to be bigger than 129+32.
 *  0b100..Phase regulation uses 1/64 of clock period. Htotal has to be bigger than 65+32.
 */
#define framegen_FGSRCR14_CSRphgsy(x)            (((uint32_t)(((uint32_t)(x)) << framegen_FGSRCR14_CSRphgsy_SHIFT)) & framegen_FGSRCR14_CSRphgsy_MASK)

#define framegen_FGSRCR14_SkwOffT_MASK           (0x3FFF0000U)
#define framegen_FGSRCR14_SkwOffT_SHIFT          (16U)
/*! SkwOffT - SkewOffset_Threshold */
#define framegen_FGSRCR14_SkwOffT(x)             (((uint32_t)(((uint32_t)(x)) << framegen_FGSRCR14_SkwOffT_SHIFT)) & framegen_FGSRCR14_SkwOffT_MASK)
/*! @} */

/*! @name FGSRCR15 - FgSRCR15 */
/*! @{ */

#define framegen_FGSRCR15_CsHsPol_MASK           (0x4000U)
#define framegen_FGSRCR15_CsHsPol_SHIFT          (14U)
/*! CsHsPol - CsHsPol
 *  0b0..HSYNC is low active.
 *  0b1..HSYNC is high active.
 */
#define framegen_FGSRCR15_CsHsPol(x)             (((uint32_t)(((uint32_t)(x)) << framegen_FGSRCR15_CsHsPol_SHIFT)) & framegen_FGSRCR15_CsHsPol_MASK)

#define framegen_FGSRCR15_CsVsPol_MASK           (0x8000U)
#define framegen_FGSRCR15_CsVsPol_SHIFT          (15U)
/*! CsVsPol - CsVsPol
 *  0b0..VSYNC is low active.
 *  0b1..VSYNC is high active.
 */
#define framegen_FGSRCR15_CsVsPol(x)             (((uint32_t)(((uint32_t)(x)) << framegen_FGSRCR15_CsVsPol_SHIFT)) & framegen_FGSRCR15_CsVsPol_MASK)

#define framegen_FGSRCR15_CsDelay_MASK           (0x3FFF0000U)
#define framegen_FGSRCR15_CsDelay_SHIFT          (16U)
/*! CsDelay - CsDelay */
#define framegen_FGSRCR15_CsDelay(x)             (((uint32_t)(((uint32_t)(x)) << framegen_FGSRCR15_CsDelay_SHIFT)) & framegen_FGSRCR15_CsDelay_MASK)
/*! @} */

/*! @name FGKSDR - FgKSDR */
/*! @{ */

#define framegen_FGKSDR_PCCplMax_MASK            (0x7U)
#define framegen_FGKSDR_PCCplMax_SHIFT           (0U)
/*! PCCplMax - PCntCplMax */
#define framegen_FGKSDR_PCCplMax(x)              (((uint32_t)(((uint32_t)(x)) << framegen_FGKSDR_PCCplMax_SHIFT)) & framegen_FGKSDR_PCCplMax_MASK)

#define framegen_FGKSDR_SCntCplM_MASK            (0x70000U)
#define framegen_FGKSDR_SCntCplM_SHIFT           (16U)
/*! SCntCplM - SCntCplMax */
#define framegen_FGKSDR_SCntCplM(x)              (((uint32_t)(((uint32_t)(x)) << framegen_FGKSDR_SCntCplM_SHIFT)) & framegen_FGKSDR_SCntCplM_MASK)
/*! @} */

/*! @name PACFG - PaCfg */
/*! @{ */

#define framegen_PACFG_Pstartx_MASK              (0x3FFFU)
#define framegen_PACFG_Pstartx_SHIFT             (0U)
/*! Pstartx - Pstartx */
#define framegen_PACFG_Pstartx(x)                (((uint32_t)(((uint32_t)(x)) << framegen_PACFG_Pstartx_SHIFT)) & framegen_PACFG_Pstartx_MASK)

#define framegen_PACFG_Pstarty_MASK              (0x3FFF0000U)
#define framegen_PACFG_Pstarty_SHIFT             (16U)
/*! Pstarty - Pstarty */
#define framegen_PACFG_Pstarty(x)                (((uint32_t)(((uint32_t)(x)) << framegen_PACFG_Pstarty_SHIFT)) & framegen_PACFG_Pstarty_MASK)
/*! @} */

/*! @name SACFG - SaCfg */
/*! @{ */

#define framegen_SACFG_Sstartx_MASK              (0x3FFFU)
#define framegen_SACFG_Sstartx_SHIFT             (0U)
/*! Sstartx - Sstartx */
#define framegen_SACFG_Sstartx(x)                (((uint32_t)(((uint32_t)(x)) << framegen_SACFG_Sstartx_SHIFT)) & framegen_SACFG_Sstartx_MASK)

#define framegen_SACFG_Sstarty_MASK              (0x3FFF0000U)
#define framegen_SACFG_Sstarty_SHIFT             (16U)
/*! Sstarty - Sstarty */
#define framegen_SACFG_Sstarty(x)                (((uint32_t)(((uint32_t)(x)) << framegen_SACFG_Sstarty_SHIFT)) & framegen_SACFG_Sstarty_MASK)
/*! @} */

/*! @name FGINCTL - FgInCtrl */
/*! @{ */

#define framegen_FGINCTL_FgDm_MASK               (0x7U)
#define framegen_FGINCTL_FgDm_SHIFT              (0U)
/*! FgDm - FgDm
 *  0b000..Black Color Background is shown.
 *  0b001..Constant Color Background is shown.
 *  0b010..Primary input only is shown.
 *  0b011..Secondary input only is shown.
 *  0b100..Both inputs overlaid with primary on top.
 *  0b101..Both inputs overlaid with secondary on top.
 *  0b110..White color background with test pattern is shown.
 */
#define framegen_FGINCTL_FgDm(x)                 (((uint32_t)(((uint32_t)(x)) << framegen_FGINCTL_FgDm_SHIFT)) & framegen_FGINCTL_FgDm_MASK)

#define framegen_FGINCTL_EnPrimAl_MASK           (0x8U)
#define framegen_FGINCTL_EnPrimAl_SHIFT          (3U)
/*! EnPrimAl - EnPrimAlpha */
#define framegen_FGINCTL_EnPrimAl(x)             (((uint32_t)(((uint32_t)(x)) << framegen_FGINCTL_EnPrimAl_SHIFT)) & framegen_FGINCTL_EnPrimAl_MASK)

#define framegen_FGINCTL_EnSecAp_MASK            (0x10U)
#define framegen_FGINCTL_EnSecAp_SHIFT           (4U)
/*! EnSecAp - EnSecAlpha */
#define framegen_FGINCTL_EnSecAp(x)              (((uint32_t)(((uint32_t)(x)) << framegen_FGINCTL_EnSecAp_SHIFT)) & framegen_FGINCTL_EnSecAp_MASK)
/*! @} */

/*! @name FGINCTLP - FgInCtrlPanic */
/*! @{ */

#define framegen_FGINCTLP_FgDmPani_MASK          (0x7U)
#define framegen_FGINCTLP_FgDmPani_SHIFT         (0U)
/*! FgDmPani - FgDmPanic
 *  0b000..Black Color Background is shown.
 *  0b001..Constant Color Background is shown.
 *  0b010..Primary input only is shown.
 *  0b011..Secondary input only is shown.
 *  0b100..Both inputs overlaid with primary on top.
 *  0b101..Both inputs overlaid with secondary on top.
 *  0b110..White color background with test pattern is shown.
 */
#define framegen_FGINCTLP_FgDmPani(x)            (((uint32_t)(((uint32_t)(x)) << framegen_FGINCTLP_FgDmPani_SHIFT)) & framegen_FGINCTLP_FgDmPani_MASK)

#define framegen_FGINCTLP_EnPrimAP_MASK          (0x8U)
#define framegen_FGINCTLP_EnPrimAP_SHIFT         (3U)
/*! EnPrimAP - EnPrimAlphaPanic */
#define framegen_FGINCTLP_EnPrimAP(x)            (((uint32_t)(((uint32_t)(x)) << framegen_FGINCTLP_EnPrimAP_SHIFT)) & framegen_FGINCTLP_EnPrimAP_MASK)

#define framegen_FGINCTLP_EnSecAPP_MASK          (0x10U)
#define framegen_FGINCTLP_EnSecAPP_SHIFT         (4U)
/*! EnSecAPP - EnSecAlphaPanic */
#define framegen_FGINCTLP_EnSecAPP(x)            (((uint32_t)(((uint32_t)(x)) << framegen_FGINCTLP_EnSecAPP_SHIFT)) & framegen_FGINCTLP_EnSecAPP_MASK)
/*! @} */

/*! @name FGCCR - FgCCR */
/*! @{ */

#define framegen_FGCCR_CcBlue_MASK               (0x3FFU)
#define framegen_FGCCR_CcBlue_SHIFT              (0U)
/*! CcBlue - CcBlue */
#define framegen_FGCCR_CcBlue(x)                 (((uint32_t)(((uint32_t)(x)) << framegen_FGCCR_CcBlue_SHIFT)) & framegen_FGCCR_CcBlue_MASK)

#define framegen_FGCCR_CcGreen_MASK              (0xFFC00U)
#define framegen_FGCCR_CcGreen_SHIFT             (10U)
/*! CcGreen - CcGreen */
#define framegen_FGCCR_CcGreen(x)                (((uint32_t)(((uint32_t)(x)) << framegen_FGCCR_CcGreen_SHIFT)) & framegen_FGCCR_CcGreen_MASK)

#define framegen_FGCCR_CcRed_MASK                (0x3FF00000U)
#define framegen_FGCCR_CcRed_SHIFT               (20U)
/*! CcRed - CcRed */
#define framegen_FGCCR_CcRed(x)                  (((uint32_t)(((uint32_t)(x)) << framegen_FGCCR_CcRed_SHIFT)) & framegen_FGCCR_CcRed_MASK)

#define framegen_FGCCR_CcAlpha_MASK              (0xC0000000U)
#define framegen_FGCCR_CcAlpha_SHIFT             (30U)
/*! CcAlpha - CcAlpha */
#define framegen_FGCCR_CcAlpha(x)                (((uint32_t)(((uint32_t)(x)) << framegen_FGCCR_CcAlpha_SHIFT)) & framegen_FGCCR_CcAlpha_MASK)
/*! @} */

/*! @name FGENABLE - FgEnable */
/*! @{ */

#define framegen_FGENABLE_FgEn_MASK              (0x1U)
#define framegen_FGENABLE_FgEn_SHIFT             (0U)
/*! FgEn - FgEn */
#define framegen_FGENABLE_FgEn(x)                (((uint32_t)(((uint32_t)(x)) << framegen_FGENABLE_FgEn_SHIFT)) & framegen_FGENABLE_FgEn_MASK)
/*! @} */

/*! @name FGSLR - FgSlr */
/*! @{ */

#define framegen_FGSLR_SdTokGen_MASK             (0x1U)
#define framegen_FGSLR_SdTokGen_SHIFT            (0U)
/*! SdTokGen - ShdTokGen */
#define framegen_FGSLR_SdTokGen(x)               (((uint32_t)(((uint32_t)(x)) << framegen_FGSLR_SdTokGen_SHIFT)) & framegen_FGSLR_SdTokGen_MASK)
/*! @} */

/*! @name FGENSTS - FgEnSts */
/*! @{ */

#define framegen_FGENSTS_EnSts_MASK              (0x1U)
#define framegen_FGENSTS_EnSts_SHIFT             (0U)
/*! EnSts - EnSts */
#define framegen_FGENSTS_EnSts(x)                (((uint32_t)(((uint32_t)(x)) << framegen_FGENSTS_EnSts_SHIFT)) & framegen_FGENSTS_EnSts_MASK)

#define framegen_FGENSTS_PanS_MASK               (0x2U)
#define framegen_FGENSTS_PanS_SHIFT              (1U)
/*! PanS - PanicStat */
#define framegen_FGENSTS_PanS(x)                 (((uint32_t)(((uint32_t)(x)) << framegen_FGENSTS_PanS_SHIFT)) & framegen_FGENSTS_PanS_MASK)
/*! @} */

/*! @name FGTIMEST - FgTimeStamp */
/*! @{ */

#define framegen_FGTIMEST_LineInde_MASK          (0x3FFFU)
#define framegen_FGTIMEST_LineInde_SHIFT         (0U)
/*! LineInde - LineIndex */
#define framegen_FGTIMEST_LineInde(x)            (((uint32_t)(((uint32_t)(x)) << framegen_FGTIMEST_LineInde_SHIFT)) & framegen_FGTIMEST_LineInde_MASK)

#define framegen_FGTIMEST_FrameIdx_MASK          (0xFFFFC000U)
#define framegen_FGTIMEST_FrameIdx_SHIFT         (14U)
/*! FrameIdx - FrameIndex */
#define framegen_FGTIMEST_FrameIdx(x)            (((uint32_t)(((uint32_t)(x)) << framegen_FGTIMEST_FrameIdx_SHIFT)) & framegen_FGTIMEST_FrameIdx_MASK)
/*! @} */

/*! @name FGCHSTT - FgChStat */
/*! @{ */

#define framegen_FGCHSTT_PFifoE_MASK             (0x1U)
#define framegen_FGCHSTT_PFifoE_SHIFT            (0U)
/*! PFifoE - PFifoEmpty */
#define framegen_FGCHSTT_PFifoE(x)               (((uint32_t)(((uint32_t)(x)) << framegen_FGCHSTT_PFifoE_SHIFT)) & framegen_FGCHSTT_PFifoE_MASK)

#define framegen_FGCHSTT_PrimSynS_MASK           (0x100U)
#define framegen_FGCHSTT_PrimSynS_SHIFT          (8U)
/*! PrimSynS - PrimSyncStat */
#define framegen_FGCHSTT_PrimSynS(x)             (((uint32_t)(((uint32_t)(x)) << framegen_FGCHSTT_PrimSynS_SHIFT)) & framegen_FGCHSTT_PrimSynS_MASK)

#define framegen_FGCHSTT_SFifoEm_MASK            (0x10000U)
#define framegen_FGCHSTT_SFifoEm_SHIFT           (16U)
/*! SFifoEm - SFifoEmpty */
#define framegen_FGCHSTT_SFifoEm(x)              (((uint32_t)(((uint32_t)(x)) << framegen_FGCHSTT_SFifoEm_SHIFT)) & framegen_FGCHSTT_SFifoEm_MASK)

#define framegen_FGCHSTT_SkwRanEr_MASK           (0x20000U)
#define framegen_FGCHSTT_SkwRanEr_SHIFT          (17U)
/*! SkwRanEr - SkewRangeErr */
#define framegen_FGCHSTT_SkwRanEr(x)             (((uint32_t)(((uint32_t)(x)) << framegen_FGCHSTT_SkwRanEr_SHIFT)) & framegen_FGCHSTT_SkwRanEr_MASK)

#define framegen_FGCHSTT_ScSyncS_MASK            (0x1000000U)
#define framegen_FGCHSTT_ScSyncS_SHIFT           (24U)
/*! ScSyncS - SecSyncStat */
#define framegen_FGCHSTT_ScSyncS(x)              (((uint32_t)(((uint32_t)(x)) << framegen_FGCHSTT_ScSyncS_SHIFT)) & framegen_FGCHSTT_ScSyncS_MASK)
/*! @} */

/*! @name FGCHSTTC - FgChStatClr */
/*! @{ */

#define framegen_FGCHSTTC_ClrPrimS_MASK          (0x1U)
#define framegen_FGCHSTTC_ClrPrimS_SHIFT         (0U)
/*! ClrPrimS - ClrPrimStat */
#define framegen_FGCHSTTC_ClrPrimS(x)            (((uint32_t)(((uint32_t)(x)) << framegen_FGCHSTTC_ClrPrimS_SHIFT)) & framegen_FGCHSTTC_ClrPrimS_MASK)

#define framegen_FGCHSTTC_ClrSecSt_MASK          (0x10000U)
#define framegen_FGCHSTTC_ClrSecSt_SHIFT         (16U)
/*! ClrSecSt - ClrSecStat */
#define framegen_FGCHSTTC_ClrSecSt(x)            (((uint32_t)(((uint32_t)(x)) << framegen_FGCHSTTC_ClrSecSt_SHIFT)) & framegen_FGCHSTTC_ClrSecSt_MASK)
/*! @} */

/*! @name FGSKEWMO - FgSkewMon */
/*! @{ */

#define framegen_FGSKEWMO_SkwMon_MASK            (0x1FFFFFFFU)
#define framegen_FGSKEWMO_SkwMon_SHIFT           (0U)
/*! SkwMon - SkewMon */
#define framegen_FGSKEWMO_SkwMon(x)              (((uint32_t)(((uint32_t)(x)) << framegen_FGSKEWMO_SkwMon_SHIFT)) & framegen_FGSKEWMO_SkwMon_MASK)
/*! @} */

/*! @name FGPFIMIN - FgPFifoMin */
/*! @{ */

#define framegen_FGPFIMIN_PFifoMin_MASK          (0xFFFFU)
#define framegen_FGPFIMIN_PFifoMin_SHIFT         (0U)
/*! PFifoMin - PFifoMin */
#define framegen_FGPFIMIN_PFifoMin(x)            (((uint32_t)(((uint32_t)(x)) << framegen_FGPFIMIN_PFifoMin_SHIFT)) & framegen_FGPFIMIN_PFifoMin_MASK)
/*! @} */

/*! @name FGPFIMAX - FgPFifoMax */
/*! @{ */

#define framegen_FGPFIMAX_PFifoMax_MASK          (0xFFFFU)
#define framegen_FGPFIMAX_PFifoMax_SHIFT         (0U)
/*! PFifoMax - PFifoMax */
#define framegen_FGPFIMAX_PFifoMax(x)            (((uint32_t)(((uint32_t)(x)) << framegen_FGPFIMAX_PFifoMax_SHIFT)) & framegen_FGPFIMAX_PFifoMax_MASK)
/*! @} */

/*! @name FGPFIFC - FgPFifoFillClr */
/*! @{ */

#define framegen_FGPFIFC_PFifoF_MASK             (0x1U)
#define framegen_FGPFIFC_PFifoF_SHIFT            (0U)
/*! PFifoF - PFifoFillClr */
#define framegen_FGPFIFC_PFifoF(x)               (((uint32_t)(((uint32_t)(x)) << framegen_FGPFIFC_PFifoF_SHIFT)) & framegen_FGPFIFC_PFifoF_MASK)
/*! @} */

/*! @name FGPFITRS - FgPFifoTres */
/*! @{ */

#define framegen_FGPFITRS_PFifoT0_MASK           (0xFFFFU)
#define framegen_FGPFITRS_PFifoT0_SHIFT          (0U)
/*! PFifoT0 - PFifoTres0 */
#define framegen_FGPFITRS_PFifoT0(x)             (((uint32_t)(((uint32_t)(x)) << framegen_FGPFITRS_PFifoT0_SHIFT)) & framegen_FGPFITRS_PFifoT0_MASK)

#define framegen_FGPFITRS_PFifoT1_MASK           (0xFFFF0000U)
#define framegen_FGPFITRS_PFifoT1_SHIFT          (16U)
/*! PFifoT1 - PFifoTres1 */
#define framegen_FGPFITRS_PFifoT1(x)             (((uint32_t)(((uint32_t)(x)) << framegen_FGPFITRS_PFifoT1_SHIFT)) & framegen_FGPFITRS_PFifoT1_MASK)
/*! @} */

/*! @name FGSFIMIN - FgSFifoMin */
/*! @{ */

#define framegen_FGSFIMIN_SFifoMin_MASK          (0xFFFFU)
#define framegen_FGSFIMIN_SFifoMin_SHIFT         (0U)
/*! SFifoMin - SFifoMin */
#define framegen_FGSFIMIN_SFifoMin(x)            (((uint32_t)(((uint32_t)(x)) << framegen_FGSFIMIN_SFifoMin_SHIFT)) & framegen_FGSFIMIN_SFifoMin_MASK)
/*! @} */

/*! @name FGSFIMAX - FgSFifoMax */
/*! @{ */

#define framegen_FGSFIMAX_SFifoMax_MASK          (0xFFFFU)
#define framegen_FGSFIMAX_SFifoMax_SHIFT         (0U)
/*! SFifoMax - SFifoMax */
#define framegen_FGSFIMAX_SFifoMax(x)            (((uint32_t)(((uint32_t)(x)) << framegen_FGSFIMAX_SFifoMax_SHIFT)) & framegen_FGSFIMAX_SFifoMax_MASK)
/*! @} */

/*! @name FGSFIFC - FgSFifoFillClr */
/*! @{ */

#define framegen_FGSFIFC_SFifoFiC_MASK           (0x1U)
#define framegen_FGSFIFC_SFifoFiC_SHIFT          (0U)
/*! SFifoFiC - SFifoFillClr */
#define framegen_FGSFIFC_SFifoFiC(x)             (((uint32_t)(((uint32_t)(x)) << framegen_FGSFIFC_SFifoFiC_SHIFT)) & framegen_FGSFIFC_SFifoFiC_MASK)
/*! @} */

/*! @name FGSREPD - FgSrEpD */
/*! @{ */

#define framegen_FGSREPD_EpVal_MASK              (0x1FFFFFFFU)
#define framegen_FGSREPD_EpVal_SHIFT             (0U)
/*! EpVal - EpVal */
#define framegen_FGSREPD_EpVal(x)                (((uint32_t)(((uint32_t)(x)) << framegen_FGSREPD_EpVal_SHIFT)) & framegen_FGSREPD_EpVal_MASK)
/*! @} */

/*! @name FGSRFTD - FgSrFtD */
/*! @{ */

#define framegen_FGSRFTD_FrTot_MASK              (0xFFFFFFFU)
#define framegen_FGSRFTD_FrTot_SHIFT             (0U)
/*! FrTot - FrTot */
#define framegen_FGSRFTD_FrTot(x)                (((uint32_t)(((uint32_t)(x)) << framegen_FGSRFTD_FrTot_SHIFT)) & framegen_FGSRFTD_FrTot_MASK)
/*! @} */

/*! @name FGSRCSHT - FgSrCSHTotal */
/*! @{ */

#define framegen_FGSRCSHT_FrCSHTot_MASK          (0xFFFFFFFFU)
#define framegen_FGSRCSHT_FrCSHTot_SHIFT         (0U)
/*! FrCSHTot - FrCSHTotal */
#define framegen_FGSRCSHT_FrCSHTot(x)            (((uint32_t)(((uint32_t)(x)) << framegen_FGSRCSHT_FrCSHTot_SHIFT)) & framegen_FGSRCSHT_FrCSHTot_MASK)
/*! @} */

/*! @name FGSRCKDI - FgSrClockDiv */
/*! @{ */

#define framegen_FGSRCKDI_FrClockD_MASK          (0xFFFFFU)
#define framegen_FGSRCKDI_FrClockD_SHIFT         (0U)
/*! FrClockD - FrClockDiv */
#define framegen_FGSRCKDI_FrClockD(x)            (((uint32_t)(((uint32_t)(x)) << framegen_FGSRCKDI_FrClockD_SHIFT)) & framegen_FGSRCKDI_FrClockD_MASK)
/*! @} */

/*! @name FGSL - FgSl */
/*! @{ */

#define framegen_FGSL_ScanLine_MASK              (0x3FFFU)
#define framegen_FGSL_ScanLine_SHIFT             (0U)
/*! ScanLine - ScanLine */
#define framegen_FGSL_ScanLine(x)                (((uint32_t)(((uint32_t)(x)) << framegen_FGSL_ScanLine_SHIFT)) & framegen_FGSL_ScanLine_MASK)

#define framegen_FGSL_VBlank_MASK                (0x80000000U)
#define framegen_FGSL_VBlank_SHIFT               (31U)
/*! VBlank - VBlank */
#define framegen_FGSL_VBlank(x)                  (((uint32_t)(((uint32_t)(x)) << framegen_FGSL_VBlank_SHIFT)) & framegen_FGSL_VBlank_MASK)
/*! @} */

/*! @name FGSKEWDB - FgSkewDebug */
/*! @{ */

#define framegen_FGSKEWDB_SState_MASK            (0x3U)
#define framegen_FGSKEWDB_SState_SHIFT           (0U)
/*! SState - SState */
#define framegen_FGSKEWDB_SState(x)              (((uint32_t)(((uint32_t)(x)) << framegen_FGSKEWDB_SState_SHIFT)) & framegen_FGSKEWDB_SState_MASK)

#define framegen_FGSKEWDB_Skwir_MASK             (0x4U)
#define framegen_FGSKEWDB_Skwir_SHIFT            (2U)
/*! Skwir - Skew_ir */
#define framegen_FGSKEWDB_Skwir(x)               (((uint32_t)(((uint32_t)(x)) << framegen_FGSKEWDB_Skwir_SHIFT)) & framegen_FGSKEWDB_Skwir_MASK)

#define framegen_FGSKEWDB_SFrircnt_MASK          (0xF0U)
#define framegen_FGSKEWDB_SFrircnt_SHIFT         (4U)
/*! SFrircnt - SFrame_ircnt */
#define framegen_FGSKEWDB_SFrircnt(x)            (((uint32_t)(((uint32_t)(x)) << framegen_FGSKEWDB_SFrircnt_SHIFT)) & framegen_FGSKEWDB_SFrircnt_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group framegen_Register_Masks */


/*!
 * @}
 */ /* end of group framegen_Peripheral_Access_Layer */


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


#endif  /* PERI_FRAMEGEN_H_ */

