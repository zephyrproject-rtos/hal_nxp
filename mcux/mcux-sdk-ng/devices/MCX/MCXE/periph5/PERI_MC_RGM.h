/*
** ###################################################################
**     Processors:          MCXE315MLF
**                          MCXE315MPA
**                          MCXE316MLF
**                          MCXE316MPA
**
**     Version:             rev. 0.1, 2024-11-19
**     Build:               b250512
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MC_RGM
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 0.1 (2024-11-19)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_MC_RGM.h
 * @version 0.1
 * @date 2024-11-19
 * @brief CMSIS Peripheral Access Layer for MC_RGM
 *
 * CMSIS Peripheral Access Layer for MC_RGM
 */

#if !defined(PERI_MC_RGM_H_)
#define PERI_MC_RGM_H_                           /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXE315MLF) || defined(CPU_MCXE315MPA))
#include "MCXE315_COMMON.h"
#elif (defined(CPU_MCXE316MLF) || defined(CPU_MCXE316MPA))
#include "MCXE316_COMMON.h"
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
   -- MC_RGM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MC_RGM_Peripheral_Access_Layer MC_RGM Peripheral Access Layer
 * @{
 */

/** MC_RGM - Register Layout Typedef */
typedef struct {
  __IO uint32_t DES;                               /**< Destructive Event Status Register, offset: 0x0 */
       uint8_t RESERVED_0[4];
  __IO uint32_t FES;                               /**< Functional /External Reset Status Register, offset: 0x8 */
  __IO uint32_t FERD;                              /**< Functional Event Reset Disable Register, offset: 0xC */
  __IO uint32_t FBRE;                              /**< Functional Bidirectional Reset Enable Register, offset: 0x10 */
  __IO uint32_t FREC;                              /**< Functional Reset Escalation Counter Register, offset: 0x14 */
  __IO uint32_t FRET;                              /**< Functional Reset Escalation Threshold Register, offset: 0x18 */
  __IO uint32_t DRET;                              /**< Destructive Reset Escalation Threshold Register, offset: 0x1C */
  __IO uint32_t ERCTRL;                            /**< External Reset Control Register, offset: 0x20 */
  __IO uint32_t RDSS;                              /**< Reset During Standby Status Register, offset: 0x24 */
  __IO uint32_t FRENTC;                            /**< Functional Reset Entry Timeout Control Register, offset: 0x28 */
} MC_RGM_Type;

/* ----------------------------------------------------------------------------
   -- MC_RGM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MC_RGM_Register_Masks MC_RGM Register Masks
 * @{
 */

/*! @name DES - Destructive Event Status Register */
/*! @{ */

#define MC_RGM_DES_F_POR_MASK                    (0x1U)
#define MC_RGM_DES_F_POR_SHIFT                   (0U)
/*! F_POR - Flag for power-on reset
 *  0b0..No power-on event has occurred since the last clear.
 *  0b1..A power-on event has occurred.
 */
#define MC_RGM_DES_F_POR(x)                      (((uint32_t)(((uint32_t)(x)) << MC_RGM_DES_F_POR_SHIFT)) & MC_RGM_DES_F_POR_MASK)

#define MC_RGM_DES_FCCU_FTR_MASK                 (0x8U)
#define MC_RGM_DES_FCCU_FTR_SHIFT                (3U)
/*! FCCU_FTR - Flag for 'Destructive' Reset FCCU_FTR
 *  0b0..'Destructive' reset event FCCU_FTR has not occurred since either the last clear or the last power-on reset assertion.
 *  0b1..'Destructive' reset event FCCU_FTR has occurred.
 */
#define MC_RGM_DES_FCCU_FTR(x)                   (((uint32_t)(((uint32_t)(x)) << MC_RGM_DES_FCCU_FTR_SHIFT)) & MC_RGM_DES_FCCU_FTR_MASK)

#define MC_RGM_DES_STCU_URF_MASK                 (0x10U)
#define MC_RGM_DES_STCU_URF_SHIFT                (4U)
/*! STCU_URF - Flag for 'Destructive' Reset STCU_URF
 *  0b0..'Destructive' reset event STCU_URF has not occurred since either the last clear or the last power-on reset assertion.
 *  0b1..'Destructive' reset event STCU_URF has occurred.
 */
#define MC_RGM_DES_STCU_URF(x)                   (((uint32_t)(((uint32_t)(x)) << MC_RGM_DES_STCU_URF_SHIFT)) & MC_RGM_DES_STCU_URF_MASK)

#define MC_RGM_DES_MC_RGM_FRE_MASK               (0x40U)
#define MC_RGM_DES_MC_RGM_FRE_SHIFT              (6U)
/*! MC_RGM_FRE - Flag for 'Destructive' Reset MC_RGM_FRE
 *  0b0..'Destructive' reset event MC_RGM_FRE has not occurred since either the last clear or the last power-on reset assertion.
 *  0b1..'Destructive' reset event MC_RGM_FRE has occurred.
 */
#define MC_RGM_DES_MC_RGM_FRE(x)                 (((uint32_t)(((uint32_t)(x)) << MC_RGM_DES_MC_RGM_FRE_SHIFT)) & MC_RGM_DES_MC_RGM_FRE_MASK)

#define MC_RGM_DES_FXOSC_FAIL_MASK               (0x100U)
#define MC_RGM_DES_FXOSC_FAIL_SHIFT              (8U)
/*! FXOSC_FAIL - Flag for 'Destructive' Reset FXOSC_FAIL
 *  0b0..'Destructive' reset event FXOSC_FAIL has not occurred since either the last clear or the last power-on reset assertion.
 *  0b1..'Destructive' reset event FXOSC_FAIL has occurred.
 */
#define MC_RGM_DES_FXOSC_FAIL(x)                 (((uint32_t)(((uint32_t)(x)) << MC_RGM_DES_FXOSC_FAIL_SHIFT)) & MC_RGM_DES_FXOSC_FAIL_MASK)

#define MC_RGM_DES_PLL_LOL_MASK                  (0x200U)
#define MC_RGM_DES_PLL_LOL_SHIFT                 (9U)
/*! PLL_LOL - Flag for 'Destructive' Reset PLL_LOL
 *  0b0..'Destructive' reset event PLL_LOL has not occurred since either the last clear or the last power-on reset assertion.
 *  0b1..'Destructive' reset event PLL_LOL has occurred.
 */
#define MC_RGM_DES_PLL_LOL(x)                    (((uint32_t)(((uint32_t)(x)) << MC_RGM_DES_PLL_LOL_SHIFT)) & MC_RGM_DES_PLL_LOL_MASK)

#define MC_RGM_DES_CORE_CLK_FAIL_MASK            (0x400U)
#define MC_RGM_DES_CORE_CLK_FAIL_SHIFT           (10U)
/*! CORE_CLK_FAIL - Flag for 'Destructive' Reset CORE_CLK_FAIL
 *  0b0..'Destructive' reset event CORE_CLK_FAIL has not occurred since either the last clear or the last power-on reset assertion.
 *  0b1..'Destructive' reset event CORE_CLK_FAIL has occurred.
 */
#define MC_RGM_DES_CORE_CLK_FAIL(x)              (((uint32_t)(((uint32_t)(x)) << MC_RGM_DES_CORE_CLK_FAIL_SHIFT)) & MC_RGM_DES_CORE_CLK_FAIL_MASK)

#define MC_RGM_DES_AIPS_PLAT_CLK_FAIL_MASK       (0x1000U)
#define MC_RGM_DES_AIPS_PLAT_CLK_FAIL_SHIFT      (12U)
/*! AIPS_PLAT_CLK_FAIL - Flag for 'Destructive' Reset AIPS_PLAT_CLK_FAIL
 *  0b0..'Destructive' reset event AIPS_PLAT_CLK_FAIL has not occurred since either the last clear or the last power-on reset assertion.
 *  0b1..'Destructive' reset event AIPS_PLAT_CLK_FAIL has occurred.
 */
#define MC_RGM_DES_AIPS_PLAT_CLK_FAIL(x)         (((uint32_t)(((uint32_t)(x)) << MC_RGM_DES_AIPS_PLAT_CLK_FAIL_SHIFT)) & MC_RGM_DES_AIPS_PLAT_CLK_FAIL_MASK)

#define MC_RGM_DES_HSE_CLK_FAIL_MASK             (0x4000U)
#define MC_RGM_DES_HSE_CLK_FAIL_SHIFT            (14U)
/*! HSE_CLK_FAIL - Flag for 'Destructive' Reset HSE_CLK_FAIL
 *  0b0..'Destructive' reset event HSE_CLK_FAIL has not occurred since either the last clear or the last power-on reset assertion.
 *  0b1..'Destructive' reset event HSE_CLK_FAIL has occurred.
 */
#define MC_RGM_DES_HSE_CLK_FAIL(x)               (((uint32_t)(((uint32_t)(x)) << MC_RGM_DES_HSE_CLK_FAIL_SHIFT)) & MC_RGM_DES_HSE_CLK_FAIL_MASK)

#define MC_RGM_DES_SYS_DIV_FAIL_MASK             (0x8000U)
#define MC_RGM_DES_SYS_DIV_FAIL_SHIFT            (15U)
/*! SYS_DIV_FAIL - Flag for 'Destructive' Reset SYS_DIV_FAIL
 *  0b0..'Destructive' reset event SYS_DIV_FAIL has not occurred since either the last clear or the last power-on reset assertion.
 *  0b1..'Destructive' reset event SYS_DIV_FAIL has occurred.
 */
#define MC_RGM_DES_SYS_DIV_FAIL(x)               (((uint32_t)(((uint32_t)(x)) << MC_RGM_DES_SYS_DIV_FAIL_SHIFT)) & MC_RGM_DES_SYS_DIV_FAIL_MASK)

#define MC_RGM_DES_HSE_TMPR_RST_MASK             (0x20000U)
#define MC_RGM_DES_HSE_TMPR_RST_SHIFT            (17U)
/*! HSE_TMPR_RST - Flag for 'Destructive' Reset HSE_TMPR_RST
 *  0b0..'Destructive' reset event HSE_TMPR_RST has not occurred since either the last clear or the last power-on reset assertion.
 *  0b1..'Destructive' reset event HSE_TMPR_RST has occurred.
 */
#define MC_RGM_DES_HSE_TMPR_RST(x)               (((uint32_t)(((uint32_t)(x)) << MC_RGM_DES_HSE_TMPR_RST_SHIFT)) & MC_RGM_DES_HSE_TMPR_RST_MASK)

#define MC_RGM_DES_HSE_SNVS_RST_MASK             (0x40000U)
#define MC_RGM_DES_HSE_SNVS_RST_SHIFT            (18U)
/*! HSE_SNVS_RST - Flag for 'Destructive' Reset HSE_SNVS_RST
 *  0b0..'Destructive' reset event HSE_SNVS_RST has not occurred since either the last clear or the last power-on reset assertion.
 *  0b1..'Destructive' reset event HSE_SNVS_RST has occurred.
 */
#define MC_RGM_DES_HSE_SNVS_RST(x)               (((uint32_t)(((uint32_t)(x)) << MC_RGM_DES_HSE_SNVS_RST_SHIFT)) & MC_RGM_DES_HSE_SNVS_RST_MASK)

#define MC_RGM_DES_SW_DEST_MASK                  (0x20000000U)
#define MC_RGM_DES_SW_DEST_SHIFT                 (29U)
/*! SW_DEST - Flag for 'Destructive' Reset SW_DEST
 *  0b0..'Destructive' reset event SW_DEST has not occurred since either the last clear or the last power-on reset assertion.
 *  0b1..'Destructive' reset event SW_DEST has occurred.
 */
#define MC_RGM_DES_SW_DEST(x)                    (((uint32_t)(((uint32_t)(x)) << MC_RGM_DES_SW_DEST_SHIFT)) & MC_RGM_DES_SW_DEST_MASK)

#define MC_RGM_DES_DEBUG_DEST_MASK               (0x40000000U)
#define MC_RGM_DES_DEBUG_DEST_SHIFT              (30U)
/*! DEBUG_DEST - Flag for 'Destructive' Reset DEBUG_DEST
 *  0b0..'Destructive' reset event DEBUG_DEST has not occurred since either the last clear or the last power-on reset assertion.
 *  0b1..'Destructive' reset event DEBUG_DEST has occurred.
 */
#define MC_RGM_DES_DEBUG_DEST(x)                 (((uint32_t)(((uint32_t)(x)) << MC_RGM_DES_DEBUG_DEST_SHIFT)) & MC_RGM_DES_DEBUG_DEST_MASK)
/*! @} */

/*! @name FES - Functional /External Reset Status Register */
/*! @{ */

#define MC_RGM_FES_F_EXR_MASK                    (0x1U)
#define MC_RGM_FES_F_EXR_SHIFT                   (0U)
/*! F_EXR - Flag for External Reset
 *  0b0..No external reset event has occurred since either the last clear or the last power-on reset assertion.
 *  0b1..An external reset event has occurred.
 */
#define MC_RGM_FES_F_EXR(x)                      (((uint32_t)(((uint32_t)(x)) << MC_RGM_FES_F_EXR_SHIFT)) & MC_RGM_FES_F_EXR_MASK)

#define MC_RGM_FES_FCCU_RST_MASK                 (0x8U)
#define MC_RGM_FES_FCCU_RST_SHIFT                (3U)
/*! FCCU_RST - Flag for 'Functional' Reset FCCU_RST
 *  0b0..'Functional' reset event FCCU_RST has not occurred since either the last clear or the last power-on reset assertion.
 *  0b1..'Functional' reset event FCCU_RST has occurred.
 */
#define MC_RGM_FES_FCCU_RST(x)                   (((uint32_t)(((uint32_t)(x)) << MC_RGM_FES_FCCU_RST_SHIFT)) & MC_RGM_FES_FCCU_RST_MASK)

#define MC_RGM_FES_ST_DONE_MASK                  (0x10U)
#define MC_RGM_FES_ST_DONE_SHIFT                 (4U)
/*! ST_DONE - Flag for 'Functional' Reset ST_DONE
 *  0b0..'Functional' reset event ST_DONE has not occurred since either the last clear or the last power-on reset assertion.
 *  0b1..'Functional' reset event ST_DONE has occurred.
 */
#define MC_RGM_FES_ST_DONE(x)                    (((uint32_t)(((uint32_t)(x)) << MC_RGM_FES_ST_DONE_SHIFT)) & MC_RGM_FES_ST_DONE_MASK)

#define MC_RGM_FES_SWT0_RST_MASK                 (0x40U)
#define MC_RGM_FES_SWT0_RST_SHIFT                (6U)
/*! SWT0_RST - Flag for 'Functional' Reset SWT0_RST
 *  0b0..'Functional' reset event SWT0_RST has not occurred since either the last clear or the last power-on reset assertion.
 *  0b1..'Functional' reset event SWT0_RST has occurred.
 */
#define MC_RGM_FES_SWT0_RST(x)                   (((uint32_t)(((uint32_t)(x)) << MC_RGM_FES_SWT0_RST_SHIFT)) & MC_RGM_FES_SWT0_RST_MASK)

#define MC_RGM_FES_JTAG_RST_MASK                 (0x200U)
#define MC_RGM_FES_JTAG_RST_SHIFT                (9U)
/*! JTAG_RST - Flag for 'Functional' Reset JTAG_RST
 *  0b0..'Functional' reset event JTAG_RST has not occurred since either the last clear or the last power-on reset assertion.
 *  0b1..'Functional' reset event JTAG_RST has occurred.
 */
#define MC_RGM_FES_JTAG_RST(x)                   (((uint32_t)(((uint32_t)(x)) << MC_RGM_FES_JTAG_RST_SHIFT)) & MC_RGM_FES_JTAG_RST_MASK)

#define MC_RGM_FES_HSE_SWT_RST_MASK              (0x10000U)
#define MC_RGM_FES_HSE_SWT_RST_SHIFT             (16U)
/*! HSE_SWT_RST - Flag for 'Functional' Reset HSE_SWT_RST
 *  0b0..'Functional' reset event HSE_SWT_RST has not occurred since either the last clear or the last power-on reset assertion.
 *  0b1..'Functional' reset event HSE_SWT_RST has occurred.
 */
#define MC_RGM_FES_HSE_SWT_RST(x)                (((uint32_t)(((uint32_t)(x)) << MC_RGM_FES_HSE_SWT_RST_SHIFT)) & MC_RGM_FES_HSE_SWT_RST_MASK)

#define MC_RGM_FES_HSE_BOOT_RST_MASK             (0x100000U)
#define MC_RGM_FES_HSE_BOOT_RST_SHIFT            (20U)
/*! HSE_BOOT_RST - Flag for 'Functional' Reset HSE_BOOT_RST
 *  0b0..'Functional' reset event HSE_BOOT_RST has not occurred since either the last clear or the last power-on reset assertion.
 *  0b1..'Functional' reset event HSE_BOOT_RST has occurred.
 */
#define MC_RGM_FES_HSE_BOOT_RST(x)               (((uint32_t)(((uint32_t)(x)) << MC_RGM_FES_HSE_BOOT_RST_SHIFT)) & MC_RGM_FES_HSE_BOOT_RST_MASK)

#define MC_RGM_FES_SW_FUNC_MASK                  (0x20000000U)
#define MC_RGM_FES_SW_FUNC_SHIFT                 (29U)
/*! SW_FUNC - Flag for 'Functional' Reset SW_FUNC
 *  0b0..'Functional' reset event SW_FUNC has not occurred since either the last clear or the last power-on reset assertion.
 *  0b1..'Functional' reset event SW_FUNC has occurred.
 */
#define MC_RGM_FES_SW_FUNC(x)                    (((uint32_t)(((uint32_t)(x)) << MC_RGM_FES_SW_FUNC_SHIFT)) & MC_RGM_FES_SW_FUNC_MASK)

#define MC_RGM_FES_DEBUG_FUNC_MASK               (0x40000000U)
#define MC_RGM_FES_DEBUG_FUNC_SHIFT              (30U)
/*! DEBUG_FUNC - Flag for 'Functional' Reset DEBUG_FUNC
 *  0b0..'Functional' reset event DEBUG_FUNC has not occurred since either the last clear or the last power-on reset assertion.
 *  0b1..'Functional' reset event DEBUG_FUNC has occurred.
 */
#define MC_RGM_FES_DEBUG_FUNC(x)                 (((uint32_t)(((uint32_t)(x)) << MC_RGM_FES_DEBUG_FUNC_SHIFT)) & MC_RGM_FES_DEBUG_FUNC_MASK)
/*! @} */

/*! @name FERD - Functional Event Reset Disable Register */
/*! @{ */

#define MC_RGM_FERD_D_FCCU_RST_MASK              (0x8U)
#define MC_RGM_FERD_D_FCCU_RST_SHIFT             (3U)
/*! D_FCCU_RST - FCCU_RST Disable Control
 *  0b0..Functional reset event FCCU_RST triggers a reset sequence.
 *  0b1..Functional reset event FCCU_RST generates an interrupt request.
 */
#define MC_RGM_FERD_D_FCCU_RST(x)                (((uint32_t)(((uint32_t)(x)) << MC_RGM_FERD_D_FCCU_RST_SHIFT)) & MC_RGM_FERD_D_FCCU_RST_MASK)

#define MC_RGM_FERD_D_SWT0_RST_MASK              (0x40U)
#define MC_RGM_FERD_D_SWT0_RST_SHIFT             (6U)
/*! D_SWT0_RST - SWT0_RST Disable Control
 *  0b0..Functional reset event SWT0_RST triggers a reset sequence.
 *  0b1..Functional reset event SWT0_RST generates an interrupt request.
 */
#define MC_RGM_FERD_D_SWT0_RST(x)                (((uint32_t)(((uint32_t)(x)) << MC_RGM_FERD_D_SWT0_RST_SHIFT)) & MC_RGM_FERD_D_SWT0_RST_MASK)

#define MC_RGM_FERD_D_JTAG_RST_MASK              (0x200U)
#define MC_RGM_FERD_D_JTAG_RST_SHIFT             (9U)
/*! D_JTAG_RST - JTAG_RST Disable Control
 *  0b0..Functional reset event JTAG_RST triggers a reset sequence.
 *  0b1..Functional reset event JTAG_RST generates an interrupt request.
 */
#define MC_RGM_FERD_D_JTAG_RST(x)                (((uint32_t)(((uint32_t)(x)) << MC_RGM_FERD_D_JTAG_RST_SHIFT)) & MC_RGM_FERD_D_JTAG_RST_MASK)

#define MC_RGM_FERD_D_DEBUG_FUNC_MASK            (0x40000000U)
#define MC_RGM_FERD_D_DEBUG_FUNC_SHIFT           (30U)
/*! D_DEBUG_FUNC - DEBUG_FUNC Disable Control
 *  0b0..Functional reset event DEBUG_FUNC triggers a reset sequence.
 *  0b1..Functional reset event DEBUG_FUNC generates an interrupt request.
 */
#define MC_RGM_FERD_D_DEBUG_FUNC(x)              (((uint32_t)(((uint32_t)(x)) << MC_RGM_FERD_D_DEBUG_FUNC_SHIFT)) & MC_RGM_FERD_D_DEBUG_FUNC_MASK)
/*! @} */

/*! @name FBRE - Functional Bidirectional Reset Enable Register */
/*! @{ */

#define MC_RGM_FBRE_BE_FCCU_RST_MASK             (0x8U)
#define MC_RGM_FBRE_BE_FCCU_RST_SHIFT            (3U)
/*! BE_FCCU_RST - Bidirectional Reset Enables for 'Functional' Reset FCCU_RST
 *  0b0..External reset pin is asserted on a 'Functional' reset FCCU_RST event if the reset is enabled.
 *  0b1..External reset pin is not asserted on a 'functional' reset FCCU_RST event.
 */
#define MC_RGM_FBRE_BE_FCCU_RST(x)               (((uint32_t)(((uint32_t)(x)) << MC_RGM_FBRE_BE_FCCU_RST_SHIFT)) & MC_RGM_FBRE_BE_FCCU_RST_MASK)

#define MC_RGM_FBRE_BE_ST_DONE_MASK              (0x10U)
#define MC_RGM_FBRE_BE_ST_DONE_SHIFT             (4U)
/*! BE_ST_DONE - Bidirectional Reset Enables for 'Functional' Reset ST_DONE
 *  0b0..External reset pin is asserted on a 'Functional' reset ST_DONE event if the reset is enabled.
 *  0b1..External reset pin is not asserted on a 'functional' reset ST_DONE event.
 */
#define MC_RGM_FBRE_BE_ST_DONE(x)                (((uint32_t)(((uint32_t)(x)) << MC_RGM_FBRE_BE_ST_DONE_SHIFT)) & MC_RGM_FBRE_BE_ST_DONE_MASK)

#define MC_RGM_FBRE_BE_SWT0_RST_MASK             (0x40U)
#define MC_RGM_FBRE_BE_SWT0_RST_SHIFT            (6U)
/*! BE_SWT0_RST - Bidirectional Reset Enables for 'Functional' Reset SWT0_RST
 *  0b0..External reset pin is asserted on a 'Functional' reset SWT0_RST event if the reset is enabled.
 *  0b1..External reset pin is not asserted on a 'functional' reset SWT0_RST event.
 */
#define MC_RGM_FBRE_BE_SWT0_RST(x)               (((uint32_t)(((uint32_t)(x)) << MC_RGM_FBRE_BE_SWT0_RST_SHIFT)) & MC_RGM_FBRE_BE_SWT0_RST_MASK)

#define MC_RGM_FBRE_BE_JTAG_RST_MASK             (0x200U)
#define MC_RGM_FBRE_BE_JTAG_RST_SHIFT            (9U)
/*! BE_JTAG_RST - Bidirectional Reset Enables for 'Functional' Reset JTAG_RST
 *  0b0..External reset pin is asserted on a 'Functional' reset JTAG_RST event if the reset is enabled.
 *  0b1..External reset pin is not asserted on a 'functional' reset JTAG_RST event.
 */
#define MC_RGM_FBRE_BE_JTAG_RST(x)               (((uint32_t)(((uint32_t)(x)) << MC_RGM_FBRE_BE_JTAG_RST_SHIFT)) & MC_RGM_FBRE_BE_JTAG_RST_MASK)

#define MC_RGM_FBRE_BE_HSE_SWT_RST_MASK          (0x10000U)
#define MC_RGM_FBRE_BE_HSE_SWT_RST_SHIFT         (16U)
/*! BE_HSE_SWT_RST - Bidirectional Reset Enables for 'Functional' Reset HSE_SWT_RST
 *  0b0..External reset pin is asserted on a 'Functional' reset HSE_SWT_RST event if the reset is enabled.
 *  0b1..External reset pin is not asserted on a 'functional' reset HSE_SWT_RST event.
 */
#define MC_RGM_FBRE_BE_HSE_SWT_RST(x)            (((uint32_t)(((uint32_t)(x)) << MC_RGM_FBRE_BE_HSE_SWT_RST_SHIFT)) & MC_RGM_FBRE_BE_HSE_SWT_RST_MASK)

#define MC_RGM_FBRE_BE_HSE_BOOT_RST_MASK         (0x100000U)
#define MC_RGM_FBRE_BE_HSE_BOOT_RST_SHIFT        (20U)
/*! BE_HSE_BOOT_RST - Bidirectional Reset Enables for 'Functional' Reset HSE_BOOT_RST
 *  0b0..External reset pin is asserted on a 'Functional' reset HSE_BOOT_RST event if the reset is enabled.
 *  0b1..External reset pin is not asserted on a 'functional' reset HSE_BOOT_RST event.
 */
#define MC_RGM_FBRE_BE_HSE_BOOT_RST(x)           (((uint32_t)(((uint32_t)(x)) << MC_RGM_FBRE_BE_HSE_BOOT_RST_SHIFT)) & MC_RGM_FBRE_BE_HSE_BOOT_RST_MASK)

#define MC_RGM_FBRE_BE_SW_FUNC_MASK              (0x20000000U)
#define MC_RGM_FBRE_BE_SW_FUNC_SHIFT             (29U)
/*! BE_SW_FUNC - Bidirectional Reset Enables for 'Functional' Reset SW_FUNC
 *  0b0..External reset pin is asserted on a 'Functional' reset SW_FUNC event if the reset is enabled.
 *  0b1..External reset pin is not asserted on a 'functional' reset SW_FUNC event.
 */
#define MC_RGM_FBRE_BE_SW_FUNC(x)                (((uint32_t)(((uint32_t)(x)) << MC_RGM_FBRE_BE_SW_FUNC_SHIFT)) & MC_RGM_FBRE_BE_SW_FUNC_MASK)

#define MC_RGM_FBRE_BE_DEBUG_FUNC_MASK           (0x40000000U)
#define MC_RGM_FBRE_BE_DEBUG_FUNC_SHIFT          (30U)
/*! BE_DEBUG_FUNC - Bidirectional Reset Enables for 'Functional' Reset DEBUG_FUNC
 *  0b0..External reset pin is asserted on a 'Functional' reset DEBUG_FUNC event if the reset is enabled.
 *  0b1..External reset pin is not asserted on a 'functional' reset DEBUG_FUNC event.
 */
#define MC_RGM_FBRE_BE_DEBUG_FUNC(x)             (((uint32_t)(((uint32_t)(x)) << MC_RGM_FBRE_BE_DEBUG_FUNC_SHIFT)) & MC_RGM_FBRE_BE_DEBUG_FUNC_MASK)
/*! @} */

/*! @name FREC - Functional Reset Escalation Counter Register */
/*! @{ */

#define MC_RGM_FREC_FREC_MASK                    (0xFU)
#define MC_RGM_FREC_FREC_SHIFT                   (0U)
/*! FREC - Functional' Reset Escalation Counter */
#define MC_RGM_FREC_FREC(x)                      (((uint32_t)(((uint32_t)(x)) << MC_RGM_FREC_FREC_SHIFT)) & MC_RGM_FREC_FREC_MASK)
/*! @} */

/*! @name FRET - Functional Reset Escalation Threshold Register */
/*! @{ */

#define MC_RGM_FRET_FRET_MASK                    (0xFU)
#define MC_RGM_FRET_FRET_SHIFT                   (0U)
/*! FRET - 'Functional' Reset Escalation Threshold */
#define MC_RGM_FRET_FRET(x)                      (((uint32_t)(((uint32_t)(x)) << MC_RGM_FRET_FRET_SHIFT)) & MC_RGM_FRET_FRET_MASK)
/*! @} */

/*! @name DRET - Destructive Reset Escalation Threshold Register */
/*! @{ */

#define MC_RGM_DRET_DRET_MASK                    (0xFU)
#define MC_RGM_DRET_DRET_SHIFT                   (0U)
/*! DRET - 'Destructive' Reset Escalation Threshold */
#define MC_RGM_DRET_DRET(x)                      (((uint32_t)(((uint32_t)(x)) << MC_RGM_DRET_DRET_SHIFT)) & MC_RGM_DRET_DRET_MASK)
/*! @} */

/*! @name ERCTRL - External Reset Control Register */
/*! @{ */

#define MC_RGM_ERCTRL_ERASSERT_MASK              (0x1U)
#define MC_RGM_ERCTRL_ERASSERT_SHIFT             (0U)
/*! ERASSERT - ERASSERT
 *  0b0..No change
 *  0b1..External reset is asserted
 */
#define MC_RGM_ERCTRL_ERASSERT(x)                (((uint32_t)(((uint32_t)(x)) << MC_RGM_ERCTRL_ERASSERT_SHIFT)) & MC_RGM_ERCTRL_ERASSERT_MASK)
/*! @} */

/*! @name RDSS - Reset During Standby Status Register */
/*! @{ */

#define MC_RGM_RDSS_DES_RES_MASK                 (0x1U)
#define MC_RGM_RDSS_DES_RES_SHIFT                (0U)
/*! DES_RES - DES_RES
 *  0b0..No destructive reset event occurred during standby mode.
 *  0b1..Destructive reset event occurred during standby mode.
 */
#define MC_RGM_RDSS_DES_RES(x)                   (((uint32_t)(((uint32_t)(x)) << MC_RGM_RDSS_DES_RES_SHIFT)) & MC_RGM_RDSS_DES_RES_MASK)

#define MC_RGM_RDSS_FES_RES_MASK                 (0x2U)
#define MC_RGM_RDSS_FES_RES_SHIFT                (1U)
/*! FES_RES - FES_RES
 *  0b0..No functional reset event occurred during standby mode.
 *  0b1..Functional reset event occurred during standby mode.
 */
#define MC_RGM_RDSS_FES_RES(x)                   (((uint32_t)(((uint32_t)(x)) << MC_RGM_RDSS_FES_RES_SHIFT)) & MC_RGM_RDSS_FES_RES_MASK)
/*! @} */

/*! @name FRENTC - Functional Reset Entry Timeout Control Register */
/*! @{ */

#define MC_RGM_FRENTC_FRET_EN_MASK               (0x1U)
#define MC_RGM_FRENTC_FRET_EN_SHIFT              (0U)
/*! FRET_EN - Functional Reset Entry Timer Enable/Disable
 *  0b0..Functional reset entry timer is disabled.
 *  0b1..Functional reset entry timer is enabled
 */
#define MC_RGM_FRENTC_FRET_EN(x)                 (((uint32_t)(((uint32_t)(x)) << MC_RGM_FRENTC_FRET_EN_SHIFT)) & MC_RGM_FRENTC_FRET_EN_MASK)

#define MC_RGM_FRENTC_FRET_TIMEOUT_MASK          (0xFFFFFFFEU)
#define MC_RGM_FRENTC_FRET_TIMEOUT_SHIFT         (1U)
/*! FRET_TIMEOUT - Functional Reset Entry Timer Value */
#define MC_RGM_FRENTC_FRET_TIMEOUT(x)            (((uint32_t)(((uint32_t)(x)) << MC_RGM_FRENTC_FRET_TIMEOUT_SHIFT)) & MC_RGM_FRENTC_FRET_TIMEOUT_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group MC_RGM_Register_Masks */


/*!
 * @}
 */ /* end of group MC_RGM_Peripheral_Access_Layer */


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


#endif  /* PERI_MC_RGM_H_ */

