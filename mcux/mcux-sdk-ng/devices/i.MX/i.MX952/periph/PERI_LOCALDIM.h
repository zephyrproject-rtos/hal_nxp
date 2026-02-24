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
**         CMSIS Peripheral Access Layer for localdim
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
 * @file PERI_localdim.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for localdim
 *
 * CMSIS Peripheral Access Layer for localdim
 */

#if !defined(PERI_LOCALDIM_H_)
#define PERI_LOCALDIM_H_                         /**< Symbol preventing repeated inclusion */

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
   -- localdim Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup localdim_Peripheral_Access_Layer localdim Peripheral Access Layer
 * @{
 */

/** localdim - Register Layout Typedef */
typedef struct {
  __O  uint32_t LU;                                /**< LockUnlock, offset: 0x0 */
  __I  uint32_t LOCKS;                             /**< LockStatus, offset: 0x4 */
  __IO uint32_t CLKCTRL0;                          /**< ClkCtrl0, offset: 0x8 */
  __IO uint32_t CLKCTRL1;                          /**< ClkCtrl1, offset: 0xC */
  __I  uint32_t CLKCTRL2;                          /**< ClkCtrl2, offset: 0x10 */
  __I  uint32_t INTS;                              /**< IntStatus, offset: 0x14 */
  __O  uint32_t INTCTRL;                           /**< IntCtrl, offset: 0x18 */
  __IO uint32_t STATCON;                           /**< StaticControl, offset: 0x1C */
  __IO uint32_t HSYNCTI;                           /**< HSyncTiming, offset: 0x20 */
  __IO uint32_t VSYNCT;                            /**< VSyncTiming, offset: 0x24 */
} localdim_Type;

/* ----------------------------------------------------------------------------
   -- localdim Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup localdim_Register_Masks localdim Register Masks
 * @{
 */

/*! @name LU - LockUnlock */
/*! @{ */

#define localdim_LU_LkUn_MASK                    (0xFFFFFFFFU)
#define localdim_LU_LkUn_SHIFT                   (0U)
/*! LkUn - LockUnlock
 *  0b01010110010100011111011101100011..Decrements the unlock counter. When the counter value is null, lock protection is active. Reset counter value is 1.
 *  0b01101001000111011011100100110110..Increments the unlock counter. Max allowed value is 15.
 *  0b10101110111010010101110011011100..Enables privilege protection. Disabled after reset.
 *  0b10110101111000100100011001101110..Disables privilege protection.
 *  0b11111011111010001011000111100110..Freezes current protection status. Writing keys to this register has no more effect until reset.
 */
#define localdim_LU_LkUn(x)                      (((uint32_t)(((uint32_t)(x)) << localdim_LU_LkUn_SHIFT)) & localdim_LU_LkUn_MASK)
/*! @} */

/*! @name LOCKS - LockStatus */
/*! @{ */

#define localdim_LOCKS_LkSus_MASK                (0x1U)
#define localdim_LOCKS_LkSus_SHIFT               (0U)
/*! LkSus - LockStatus */
#define localdim_LOCKS_LkSus(x)                  (((uint32_t)(((uint32_t)(x)) << localdim_LOCKS_LkSus_SHIFT)) & localdim_LOCKS_LkSus_MASK)

#define localdim_LOCKS_PriSt_MASK                (0x10U)
#define localdim_LOCKS_PriSt_SHIFT               (4U)
/*! PriSt - PrivilegeStatus */
#define localdim_LOCKS_PriSt(x)                  (((uint32_t)(((uint32_t)(x)) << localdim_LOCKS_PriSt_SHIFT)) & localdim_LOCKS_PriSt_MASK)

#define localdim_LOCKS_FreezeS_MASK              (0x100U)
#define localdim_LOCKS_FreezeS_SHIFT             (8U)
/*! FreezeS - FreezeStatus */
#define localdim_LOCKS_FreezeS(x)                (((uint32_t)(((uint32_t)(x)) << localdim_LOCKS_FreezeS_SHIFT)) & localdim_LOCKS_FreezeS_MASK)
/*! @} */

/*! @name CLKCTRL0 - ClkCtrl0 */
/*! @{ */

#define localdim_CLKCTRL0_GlobClkE_MASK          (0x1U)
#define localdim_CLKCTRL0_GlobClkE_SHIFT         (0U)
/*! GlobClkE - GlobClkEn */
#define localdim_CLKCTRL0_GlobClkE(x)            (((uint32_t)(((uint32_t)(x)) << localdim_CLKCTRL0_GlobClkE_SHIFT)) & localdim_CLKCTRL0_GlobClkE_MASK)
/*! @} */

/*! @name CLKCTRL1 - ClkCtrl1 */
/*! @{ */

#define localdim_CLKCTRL1_ClkLdEn_MASK           (0x1U)
#define localdim_CLKCTRL1_ClkLdEn_SHIFT          (0U)
/*! ClkLdEn - ClkLdEn */
#define localdim_CLKCTRL1_ClkLdEn(x)             (((uint32_t)(((uint32_t)(x)) << localdim_CLKCTRL1_ClkLdEn_SHIFT)) & localdim_CLKCTRL1_ClkLdEn_MASK)

#define localdim_CLKCTRL1_ClkLdSEn_MASK          (0x2U)
#define localdim_CLKCTRL1_ClkLdSEn_SHIFT         (1U)
/*! ClkLdSEn - ClkLdSysEn */
#define localdim_CLKCTRL1_ClkLdSEn(x)            (((uint32_t)(((uint32_t)(x)) << localdim_CLKCTRL1_ClkLdSEn_SHIFT)) & localdim_CLKCTRL1_ClkLdSEn_MASK)
/*! @} */

/*! @name CLKCTRL2 - ClkCtrl2 */
/*! @{ */

#define localdim_CLKCTRL2_LdPass0_MASK           (0x1U)
#define localdim_CLKCTRL2_LdPass0_SHIFT          (0U)
/*! LdPass0 - LdPass */
#define localdim_CLKCTRL2_LdPass0(x)             (((uint32_t)(((uint32_t)(x)) << localdim_CLKCTRL2_LdPass0_SHIFT)) & localdim_CLKCTRL2_LdPass0_MASK)
/*! @} */

/*! @name INTS - IntStatus */
/*! @{ */

#define localdim_INTS_IntSts_MASK                (0x7U)
#define localdim_INTS_IntSts_SHIFT               (0U)
/*! IntSts - IntSts */
#define localdim_INTS_IntSts(x)                  (((uint32_t)(((uint32_t)(x)) << localdim_INTS_IntSts_SHIFT)) & localdim_INTS_IntSts_MASK)
/*! @} */

/*! @name INTCTRL - IntCtrl */
/*! @{ */

#define localdim_INTCTRL_ClrInt_MASK             (0x7U)
#define localdim_INTCTRL_ClrInt_SHIFT            (0U)
/*! ClrInt - ClrInt */
#define localdim_INTCTRL_ClrInt(x)               (((uint32_t)(((uint32_t)(x)) << localdim_INTCTRL_ClrInt_SHIFT)) & localdim_INTCTRL_ClrInt_MASK)
/*! @} */

/*! @name STATCON - StaticControl */
/*! @{ */

#define localdim_STATCON_Bypass_MASK             (0x1U)
#define localdim_STATCON_Bypass_SHIFT            (0U)
/*! Bypass - Bypass */
#define localdim_STATCON_Bypass(x)               (((uint32_t)(((uint32_t)(x)) << localdim_STATCON_Bypass_SHIFT)) & localdim_STATCON_Bypass_MASK)

#define localdim_STATCON_Dlycmp_MASK             (0xFEU)
#define localdim_STATCON_Dlycmp_SHIFT            (1U)
/*! Dlycmp - Dlycmp */
#define localdim_STATCON_Dlycmp(x)               (((uint32_t)(((uint32_t)(x)) << localdim_STATCON_Dlycmp_SHIFT)) & localdim_STATCON_Dlycmp_MASK)

#define localdim_STATCON_Hppol_MASK              (0x100U)
#define localdim_STATCON_Hppol_SHIFT             (8U)
/*! Hppol - Hppol */
#define localdim_STATCON_Hppol(x)                (((uint32_t)(((uint32_t)(x)) << localdim_STATCON_Hppol_SHIFT)) & localdim_STATCON_Hppol_MASK)

#define localdim_STATCON_Vppol_MASK              (0x200U)
#define localdim_STATCON_Vppol_SHIFT             (9U)
/*! Vppol - Vppol */
#define localdim_STATCON_Vppol(x)                (((uint32_t)(((uint32_t)(x)) << localdim_STATCON_Vppol_SHIFT)) & localdim_STATCON_Vppol_MASK)

#define localdim_STATCON_Depol_MASK              (0x400U)
#define localdim_STATCON_Depol_SHIFT             (10U)
/*! Depol - Depol */
#define localdim_STATCON_Depol(x)                (((uint32_t)(((uint32_t)(x)) << localdim_STATCON_Depol_SHIFT)) & localdim_STATCON_Depol_MASK)

#define localdim_STATCON_Mode1_MASK              (0x3000U)
#define localdim_STATCON_Mode1_SHIFT             (12U)
/*! Mode1 - Mode
 *  0b00..LD sync signals are generated from hlast, vlast sync signals (default). Hsync_Srt, Vsync_Srt, Vsync_End counters must be programmed.
 *  0b01..hsync, vsync are used for LD sync. Input timing used.
 *  0b10..LD sync signals are generated from hsync, vsync signals. Adapted input timing used.
 *  0b11..LD sync signals are generated from hsync, vsync signals. Hsync_Srt, Vsync_Srt, Vsync_End counters must be programmed.
 */
#define localdim_STATCON_Mode1(x)                (((uint32_t)(((uint32_t)(x)) << localdim_STATCON_Mode1_SHIFT)) & localdim_STATCON_Mode1_MASK)
/*! @} */

/*! @name HSYNCTI - HSyncTiming */
/*! @{ */

#define localdim_HSYNCTI_HsyncS_MASK             (0x3FFFU)
#define localdim_HSYNCTI_HsyncS_SHIFT            (0U)
/*! HsyncS - Hsync_Srt */
#define localdim_HSYNCTI_HsyncS(x)               (((uint32_t)(((uint32_t)(x)) << localdim_HSYNCTI_HsyncS_SHIFT)) & localdim_HSYNCTI_HsyncS_MASK)
/*! @} */

/*! @name VSYNCT - VSyncTiming */
/*! @{ */

#define localdim_VSYNCT_VsynSrt_MASK             (0x3FFFU)
#define localdim_VSYNCT_VsynSrt_SHIFT            (0U)
/*! VsynSrt - Vsync_Srt */
#define localdim_VSYNCT_VsynSrt(x)               (((uint32_t)(((uint32_t)(x)) << localdim_VSYNCT_VsynSrt_SHIFT)) & localdim_VSYNCT_VsynSrt_MASK)

#define localdim_VSYNCT_VsyncEnd_MASK            (0x3FFF0000U)
#define localdim_VSYNCT_VsyncEnd_SHIFT           (16U)
/*! VsyncEnd - Vsync_End */
#define localdim_VSYNCT_VsyncEnd(x)              (((uint32_t)(((uint32_t)(x)) << localdim_VSYNCT_VsyncEnd_SHIFT)) & localdim_VSYNCT_VsyncEnd_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group localdim_Register_Masks */


/*!
 * @}
 */ /* end of group localdim_Peripheral_Access_Layer */


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


#endif  /* PERI_LOCALDIM_H_ */

