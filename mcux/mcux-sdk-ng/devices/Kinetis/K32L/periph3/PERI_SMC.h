/*
** ###################################################################
**     Processors:          K32L3A60VPJ1A_cm0plus
**                          K32L3A60VPJ1A_cm4
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for SMC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2019-04-22)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_SMC.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for SMC
 *
 * CMSIS Peripheral Access Layer for SMC
 */

#if !defined(PERI_SMC_H_)
#define PERI_SMC_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_K32L3A60VPJ1A_cm0plus))
#include "K32L3A60_cm0plus_COMMON.h"
#elif (defined(CPU_K32L3A60VPJ1A_cm4))
#include "K32L3A60_cm4_COMMON.h"
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
   -- SMC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SMC_Peripheral_Access_Layer SMC Peripheral Access Layer
 * @{
 */

/** SMC - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< Version ID Register, offset: 0x0 */
  __I  uint32_t PARAM;                             /**< Parameter Register, offset: 0x4 */
  __IO uint32_t PMPROT;                            /**< Power Mode Protection register, offset: 0x8 */
       uint8_t RESERVED_0[4];
  __IO uint32_t PMCTRL;                            /**< Power Mode Control register, offset: 0x10 */
       uint8_t RESERVED_1[4];
  __IO uint32_t PMSTAT;                            /**< Power Mode Status register, offset: 0x18 */
       uint8_t RESERVED_2[4];
  __I  uint32_t SRS;                               /**< System Reset Status, offset: 0x20 */
  __IO uint32_t RPC;                               /**< Reset Pin Control, offset: 0x24, available only on: SMC0 (missing on SMC1) */
  __IO uint32_t SSRS;                              /**< Sticky System Reset Status, offset: 0x28 */
  __IO uint32_t SRIE;                              /**< System Reset Interrupt Enable, offset: 0x2C */
  __IO uint32_t SRIF;                              /**< System Reset Interrupt Flag, offset: 0x30 */
       uint8_t RESERVED_3[12];
  __IO uint32_t MR;                                /**< Mode Register, offset: 0x40 */
       uint8_t RESERVED_4[12];
  __IO uint32_t FM;                                /**< Force Mode Register, offset: 0x50 */
       uint8_t RESERVED_5[12];
  __IO uint32_t SRAMLPR;                           /**< SRAM Low Power Register, offset: 0x60 */
  __IO uint32_t SRAMDSR;                           /**< SRAM Deep Sleep Register, offset: 0x64 */
} SMC_Type;

/* ----------------------------------------------------------------------------
   -- SMC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SMC_Register_Masks SMC Register Masks
 * @{
 */

/*! @name VERID - Version ID Register */
/*! @{ */

#define SMC_VERID_FEATURE_MASK                   (0xFFFFU)
#define SMC_VERID_FEATURE_SHIFT                  (0U)
/*! FEATURE - Feature Specification Number
 *  0b0000000010101011..Default features supported
 */
#define SMC_VERID_FEATURE(x)                     (((uint32_t)(((uint32_t)(x)) << SMC_VERID_FEATURE_SHIFT)) & SMC_VERID_FEATURE_MASK)

#define SMC_VERID_MINOR_MASK                     (0xFF0000U)
#define SMC_VERID_MINOR_SHIFT                    (16U)
/*! MINOR - Minor Version Number */
#define SMC_VERID_MINOR(x)                       (((uint32_t)(((uint32_t)(x)) << SMC_VERID_MINOR_SHIFT)) & SMC_VERID_MINOR_MASK)

#define SMC_VERID_MAJOR_MASK                     (0xFF000000U)
#define SMC_VERID_MAJOR_SHIFT                    (24U)
/*! MAJOR - Major Version Number */
#define SMC_VERID_MAJOR(x)                       (((uint32_t)(((uint32_t)(x)) << SMC_VERID_MAJOR_SHIFT)) & SMC_VERID_MAJOR_MASK)
/*! @} */

/*! @name PARAM - Parameter Register */
/*! @{ */

#define SMC_PARAM_PWRD_INDPT_MASK                (0x1U)
#define SMC_PARAM_PWRD_INDPT_SHIFT               (0U)
/*! PWRD_INDPT - Power Domains Independent */
#define SMC_PARAM_PWRD_INDPT(x)                  (((uint32_t)(((uint32_t)(x)) << SMC_PARAM_PWRD_INDPT_SHIFT)) & SMC_PARAM_PWRD_INDPT_MASK)
/*! @} */

/*! @name PMPROT - Power Mode Protection register */
/*! @{ */

#define SMC_PMPROT_AVLLS_MASK                    (0x3U)
#define SMC_PMPROT_AVLLS_SHIFT                   (0U)
/*! AVLLS - Allow Very-Low-Leakage Stop Mode
 *  0b00..VLLS mode is not allowed
 *  0b01..VLLS0/1 mode is allowed
 *  0b10..VLLS2/3 mode is allowed
 *  0b11..VLLS0/1/2/3 mode is allowed
 */
#define SMC_PMPROT_AVLLS(x)                      (((uint32_t)(((uint32_t)(x)) << SMC_PMPROT_AVLLS_SHIFT)) & SMC_PMPROT_AVLLS_MASK)

#define SMC_PMPROT_ALLS_MASK                     (0x8U)
#define SMC_PMPROT_ALLS_SHIFT                    (3U)
/*! ALLS - Allow Low-Leakage Stop Mode
 *  0b0..LLS is not allowed
 *  0b1..LLS is allowed
 */
#define SMC_PMPROT_ALLS(x)                       (((uint32_t)(((uint32_t)(x)) << SMC_PMPROT_ALLS_SHIFT)) & SMC_PMPROT_ALLS_MASK)

#define SMC_PMPROT_AVLP_MASK                     (0x20U)
#define SMC_PMPROT_AVLP_SHIFT                    (5U)
/*! AVLP - Allow Very-Low-Power Modes
 *  0b0..VLPR, VLPW, and VLPS are not allowed.
 *  0b1..VLPR, VLPW, and VLPS are allowed.
 */
#define SMC_PMPROT_AVLP(x)                       (((uint32_t)(((uint32_t)(x)) << SMC_PMPROT_AVLP_SHIFT)) & SMC_PMPROT_AVLP_MASK)

#define SMC_PMPROT_AHSRUN_MASK                   (0x80U)
#define SMC_PMPROT_AHSRUN_SHIFT                  (7U)
/*! AHSRUN - Allow High Speed Run mode
 *  0b0..HSRUN is not allowed
 *  0b1..HSRUN is allowed
 */
#define SMC_PMPROT_AHSRUN(x)                     (((uint32_t)(((uint32_t)(x)) << SMC_PMPROT_AHSRUN_SHIFT)) & SMC_PMPROT_AHSRUN_MASK)
/*! @} */

/*! @name PMCTRL - Power Mode Control register */
/*! @{ */

#define SMC_PMCTRL_STOPM_MASK                    (0x7U)
#define SMC_PMCTRL_STOPM_SHIFT                   (0U)
/*! STOPM - Stop Mode Control
 *  0b000..Normal Stop (STOP)
 *  0b001..Reserved
 *  0b010..Very-Low-Power Stop (VLPS)
 *  0b011..Low-Leakage Stop (LLS)
 *  0b100..Very-Low-Leakage Stop with SRAM retention(VLLS2/3)
 *  0b101..Reserved
 *  0b110..Very-Low-Leakage Stop without SRAM retention (VLLS0/1)
 *  0b111..Reserved
 */
#define SMC_PMCTRL_STOPM(x)                      (((uint32_t)(((uint32_t)(x)) << SMC_PMCTRL_STOPM_SHIFT)) & SMC_PMCTRL_STOPM_MASK)

#define SMC_PMCTRL_RUNM_MASK                     (0x300U)
#define SMC_PMCTRL_RUNM_SHIFT                    (8U)
/*! RUNM - Run Mode Control
 *  0b00..Normal Run mode (RUN)
 *  0b01..Reserved
 *  0b10..Very-Low-Power Run mode (VLPR)
 *  0b11..High Speed Run mode (HSRUN)
 */
#define SMC_PMCTRL_RUNM(x)                       (((uint32_t)(((uint32_t)(x)) << SMC_PMCTRL_RUNM_SHIFT)) & SMC_PMCTRL_RUNM_MASK)

#define SMC_PMCTRL_PSTOPO_MASK                   (0x30000U)
#define SMC_PMCTRL_PSTOPO_SHIFT                  (16U)
/*! PSTOPO - Partial Stop Option
 *  0b00..STOP - Normal Stop mode
 *  0b01..PSTOP1 - Partial Stop with system and bus clock disabled
 *  0b10..PSTOP2 - Partial Stop with system clock disabled and bus clock enabled
 *  0b11..PSTOP3 - Partial Stop with system clock enabled and bus clock enabled
 */
#define SMC_PMCTRL_PSTOPO(x)                     (((uint32_t)(((uint32_t)(x)) << SMC_PMCTRL_PSTOPO_SHIFT)) & SMC_PMCTRL_PSTOPO_MASK)
/*! @} */

/*! @name PMSTAT - Power Mode Status register */
/*! @{ */

#define SMC_PMSTAT_PMSTAT_MASK                   (0xFFU)
#define SMC_PMSTAT_PMSTAT_SHIFT                  (0U)
/*! PMSTAT - Power Mode Status
 *  0b00000001..Current power mode is RUN.
 *  0b00000010..Current power mode is any STOP mode.
 *  0b00000100..Current power mode is VLPR.
 *  0b10000000..Current power mode is HSRUN
 */
#define SMC_PMSTAT_PMSTAT(x)                     (((uint32_t)(((uint32_t)(x)) << SMC_PMSTAT_PMSTAT_SHIFT)) & SMC_PMSTAT_PMSTAT_MASK)

#define SMC_PMSTAT_STOPSTAT_MASK                 (0xFF000000U)
#define SMC_PMSTAT_STOPSTAT_SHIFT                (24U)
/*! STOPSTAT - Stop Entry Status */
#define SMC_PMSTAT_STOPSTAT(x)                   (((uint32_t)(((uint32_t)(x)) << SMC_PMSTAT_STOPSTAT_SHIFT)) & SMC_PMSTAT_STOPSTAT_MASK)
/*! @} */

/*! @name SRS - System Reset Status */
/*! @{ */

#define SMC_SRS_WAKEUP_MASK                      (0x1U)
#define SMC_SRS_WAKEUP_SHIFT                     (0U)
/*! WAKEUP - Wakeup Reset
 *  0b0..Reset not generated by wakeup from VLLS mode.
 *  0b1..Reset generated by wakeup from VLLS mode.
 */
#define SMC_SRS_WAKEUP(x)                        (((uint32_t)(((uint32_t)(x)) << SMC_SRS_WAKEUP_SHIFT)) & SMC_SRS_WAKEUP_MASK)

#define SMC_SRS_POR_MASK                         (0x2U)
#define SMC_SRS_POR_SHIFT                        (1U)
/*! POR - POR Reset
 *  0b0..Reset not generated by POR.
 *  0b1..Reset generated by POR.
 */
#define SMC_SRS_POR(x)                           (((uint32_t)(((uint32_t)(x)) << SMC_SRS_POR_SHIFT)) & SMC_SRS_POR_MASK)

#define SMC_SRS_LVD_MASK                         (0x4U)
#define SMC_SRS_LVD_SHIFT                        (2U)
/*! LVD - LVD Reset
 *  0b0..Reset not generated by LVD.
 *  0b1..Reset generated by LVD.
 */
#define SMC_SRS_LVD(x)                           (((uint32_t)(((uint32_t)(x)) << SMC_SRS_LVD_SHIFT)) & SMC_SRS_LVD_MASK)

#define SMC_SRS_HVD_MASK                         (0x8U)
#define SMC_SRS_HVD_SHIFT                        (3U)
/*! HVD - HVD Reset
 *  0b0..Reset not generated by HVD.
 *  0b1..Reset generated by HVD.
 */
#define SMC_SRS_HVD(x)                           (((uint32_t)(((uint32_t)(x)) << SMC_SRS_HVD_SHIFT)) & SMC_SRS_HVD_MASK)

#define SMC_SRS_WARM_MASK                        (0x10U)
#define SMC_SRS_WARM_SHIFT                       (4U)
/*! WARM - Warm Reset
 *  0b0..Reset not generated by Warm Reset source.
 *  0b1..Reset generated by Warm Reset source.
 */
#define SMC_SRS_WARM(x)                          (((uint32_t)(((uint32_t)(x)) << SMC_SRS_WARM_SHIFT)) & SMC_SRS_WARM_MASK)

#define SMC_SRS_FATAL_MASK                       (0x20U)
#define SMC_SRS_FATAL_SHIFT                      (5U)
/*! FATAL - Fatal Reset
 *  0b0..Reset was not generated by a fatal reset source.
 *  0b1..Reset was generated by a fatal reset source.
 */
#define SMC_SRS_FATAL(x)                         (((uint32_t)(((uint32_t)(x)) << SMC_SRS_FATAL_SHIFT)) & SMC_SRS_FATAL_MASK)

#define SMC_SRS_CORE_MASK                        (0x80U)
#define SMC_SRS_CORE_SHIFT                       (7U)
/*! CORE - Core Reset
 *  0b0..Reset source was not core only reset.
 *  0b1..Reset source was core reset and reset the core only.
 */
#define SMC_SRS_CORE(x)                          (((uint32_t)(((uint32_t)(x)) << SMC_SRS_CORE_SHIFT)) & SMC_SRS_CORE_MASK)

#define SMC_SRS_PIN_MASK                         (0x100U)
#define SMC_SRS_PIN_SHIFT                        (8U)
/*! PIN - Pin Reset
 *  0b0..Reset was not generated from the assertion of RESET_B pin.
 *  0b1..Reset was generated from the assertion of RESET_B pin.
 */
#define SMC_SRS_PIN(x)                           (((uint32_t)(((uint32_t)(x)) << SMC_SRS_PIN_SHIFT)) & SMC_SRS_PIN_MASK)

#define SMC_SRS_MDM_MASK                         (0x200U)
#define SMC_SRS_MDM_SHIFT                        (9U)
/*! MDM - MDM Reset
 *  0b0..Reset was not generated from the MDM reset request.
 *  0b1..Reset was generated from the MDM reset request.
 */
#define SMC_SRS_MDM(x)                           (((uint32_t)(((uint32_t)(x)) << SMC_SRS_MDM_SHIFT)) & SMC_SRS_MDM_MASK)

#define SMC_SRS_RSTACK_MASK                      (0x400U)
#define SMC_SRS_RSTACK_SHIFT                     (10U)
/*! RSTACK - Reset Timeout
 *  0b0..Reset not generated from Reset Controller Timeout.
 *  0b1..Reset generated from Reset Controller Timeout.
 */
#define SMC_SRS_RSTACK(x)                        (((uint32_t)(((uint32_t)(x)) << SMC_SRS_RSTACK_SHIFT)) & SMC_SRS_RSTACK_MASK)

#define SMC_SRS_STOPACK_MASK                     (0x800U)
#define SMC_SRS_STOPACK_SHIFT                    (11U)
/*! STOPACK - Stop Timeout Reset
 *  0b0..Reset not generated by Stop Controller Timeout.
 *  0b1..Reset generated by Stop Controller Timeout.
 */
#define SMC_SRS_STOPACK(x)                       (((uint32_t)(((uint32_t)(x)) << SMC_SRS_STOPACK_SHIFT)) & SMC_SRS_STOPACK_MASK)

#define SMC_SRS_SCG_MASK                         (0x1000U)
#define SMC_SRS_SCG_SHIFT                        (12U)
/*! SCG - SCG Reset
 *  0b0..Reset is not generated from an SCG loss of lock or loss of clock.
 *  0b1..Reset is generated from an SCG loss of lock or loss of clock.
 */
#define SMC_SRS_SCG(x)                           (((uint32_t)(((uint32_t)(x)) << SMC_SRS_SCG_SHIFT)) & SMC_SRS_SCG_MASK)

#define SMC_SRS_WDOG_MASK                        (0x2000U)
#define SMC_SRS_WDOG_SHIFT                       (13U)
/*! WDOG - Watchdog Reset
 *  0b0..Reset is not generated from the WatchDog timeout.
 *  0b1..Reset is generated from the WatchDog timeout.
 */
#define SMC_SRS_WDOG(x)                          (((uint32_t)(((uint32_t)(x)) << SMC_SRS_WDOG_SHIFT)) & SMC_SRS_WDOG_MASK)

#define SMC_SRS_SW_MASK                          (0x4000U)
#define SMC_SRS_SW_SHIFT                         (14U)
/*! SW - Software Reset
 *  0b0..Reset not generated by software request from core.
 *  0b1..Reset generated by software request from core.
 */
#define SMC_SRS_SW(x)                            (((uint32_t)(((uint32_t)(x)) << SMC_SRS_SW_SHIFT)) & SMC_SRS_SW_MASK)

#define SMC_SRS_LOCKUP_MASK                      (0x8000U)
#define SMC_SRS_LOCKUP_SHIFT                     (15U)
/*! LOCKUP - Lockup Reset
 *  0b0..Reset not generated by core lockup or exception.
 *  0b1..Reset generated by core lockup or exception.
 */
#define SMC_SRS_LOCKUP(x)                        (((uint32_t)(((uint32_t)(x)) << SMC_SRS_LOCKUP_SHIFT)) & SMC_SRS_LOCKUP_MASK)

#define SMC_SRS_CORE0_MASK                       (0x10000U)
#define SMC_SRS_CORE0_SHIFT                      (16U)
/*! CORE0 - Core0 System Reset
 *  0b0..Reset not generated from Core0 system reset source.
 *  0b1..Reset generated from Core0 system reset source.
 */
#define SMC_SRS_CORE0(x)                         (((uint32_t)(((uint32_t)(x)) << SMC_SRS_CORE0_SHIFT)) & SMC_SRS_CORE0_MASK)

#define SMC_SRS_CORE1_MASK                       (0x20000U)
#define SMC_SRS_CORE1_SHIFT                      (17U)
/*! CORE1 - Core1 System Reset
 *  0b0..Reset not generated from Core1 system reset source.
 *  0b1..Reset generated from Core1 system reset source.
 */
#define SMC_SRS_CORE1(x)                         (((uint32_t)(((uint32_t)(x)) << SMC_SRS_CORE1_SHIFT)) & SMC_SRS_CORE1_MASK)

#define SMC_SRS_JTAG_MASK                        (0x10000000U)
#define SMC_SRS_JTAG_SHIFT                       (28U)
/*! JTAG - JTAG System Reset
 *  0b0..Reset not generated by JTAG system reset.
 *  0b1..Reset generated by JTAG system reset.
 */
#define SMC_SRS_JTAG(x)                          (((uint32_t)(((uint32_t)(x)) << SMC_SRS_JTAG_SHIFT)) & SMC_SRS_JTAG_MASK)
/*! @} */

/*! @name RPC - Reset Pin Control */
/*! @{ */

#define SMC_RPC_FILTCFG_MASK                     (0x1FU)
#define SMC_RPC_FILTCFG_SHIFT                    (0U)
/*! FILTCFG - Reset Filter Configuration */
#define SMC_RPC_FILTCFG(x)                       (((uint32_t)(((uint32_t)(x)) << SMC_RPC_FILTCFG_SHIFT)) & SMC_RPC_FILTCFG_MASK)

#define SMC_RPC_FILTEN_MASK                      (0x100U)
#define SMC_RPC_FILTEN_SHIFT                     (8U)
/*! FILTEN - Filter Enable
 *  0b0..Slow clock reset pin filter disabled.
 *  0b1..Slow clock reset pin filter enabled in Run modes.
 */
#define SMC_RPC_FILTEN(x)                        (((uint32_t)(((uint32_t)(x)) << SMC_RPC_FILTEN_SHIFT)) & SMC_RPC_FILTEN_MASK)

#define SMC_RPC_LPOFEN_MASK                      (0x200U)
#define SMC_RPC_LPOFEN_SHIFT                     (9U)
/*! LPOFEN - LPO Filter Enable
 *  0b0..LPO clock reset pin filter disabled.
 *  0b1..LPO clock reset pin filter enabled in all modes.
 */
#define SMC_RPC_LPOFEN(x)                        (((uint32_t)(((uint32_t)(x)) << SMC_RPC_LPOFEN_SHIFT)) & SMC_RPC_LPOFEN_MASK)
/*! @} */

/*! @name SSRS - Sticky System Reset Status */
/*! @{ */

#define SMC_SSRS_WAKEUP_MASK                     (0x1U)
#define SMC_SSRS_WAKEUP_SHIFT                    (0U)
/*! WAKEUP - Wakeup Reset
 *  0b0..Reset not generated by wakeup from VLLS mode.
 *  0b1..Reset generated by wakeup from VLLS mode.
 */
#define SMC_SSRS_WAKEUP(x)                       (((uint32_t)(((uint32_t)(x)) << SMC_SSRS_WAKEUP_SHIFT)) & SMC_SSRS_WAKEUP_MASK)

#define SMC_SSRS_POR_MASK                        (0x2U)
#define SMC_SSRS_POR_SHIFT                       (1U)
/*! POR - POR Reset
 *  0b0..Reset not generated by POR.
 *  0b1..Reset generated by POR.
 */
#define SMC_SSRS_POR(x)                          (((uint32_t)(((uint32_t)(x)) << SMC_SSRS_POR_SHIFT)) & SMC_SSRS_POR_MASK)

#define SMC_SSRS_LVD_MASK                        (0x4U)
#define SMC_SSRS_LVD_SHIFT                       (2U)
/*! LVD - LVD Reset
 *  0b0..Reset not generated by LVD.
 *  0b1..Reset generated by LVD.
 */
#define SMC_SSRS_LVD(x)                          (((uint32_t)(((uint32_t)(x)) << SMC_SSRS_LVD_SHIFT)) & SMC_SSRS_LVD_MASK)

#define SMC_SSRS_HVD_MASK                        (0x8U)
#define SMC_SSRS_HVD_SHIFT                       (3U)
/*! HVD - HVD Reset
 *  0b0..Reset not generated by HVD.
 *  0b1..Reset generated by HVD.
 */
#define SMC_SSRS_HVD(x)                          (((uint32_t)(((uint32_t)(x)) << SMC_SSRS_HVD_SHIFT)) & SMC_SSRS_HVD_MASK)

#define SMC_SSRS_WARM_MASK                       (0x10U)
#define SMC_SSRS_WARM_SHIFT                      (4U)
/*! WARM - Warm Reset
 *  0b0..Reset not generated by system reset source.
 *  0b1..Reset generated by system reset source.
 */
#define SMC_SSRS_WARM(x)                         (((uint32_t)(((uint32_t)(x)) << SMC_SSRS_WARM_SHIFT)) & SMC_SSRS_WARM_MASK)

#define SMC_SSRS_FATAL_MASK                      (0x20U)
#define SMC_SSRS_FATAL_SHIFT                     (5U)
/*! FATAL - Fatal Reset
 *  0b0..Reset was not generated by a fatal reset source.
 *  0b1..Reset was generated by a fatal reset source.
 */
#define SMC_SSRS_FATAL(x)                        (((uint32_t)(((uint32_t)(x)) << SMC_SSRS_FATAL_SHIFT)) & SMC_SSRS_FATAL_MASK)

#define SMC_SSRS_PIN_MASK                        (0x100U)
#define SMC_SSRS_PIN_SHIFT                       (8U)
/*! PIN - Pin Reset
 *  0b0..Reset was not generated from the RESET_B pin.
 *  0b1..Reset was generated from the RESET_B pin.
 */
#define SMC_SSRS_PIN(x)                          (((uint32_t)(((uint32_t)(x)) << SMC_SSRS_PIN_SHIFT)) & SMC_SSRS_PIN_MASK)

#define SMC_SSRS_MDM_MASK                        (0x200U)
#define SMC_SSRS_MDM_SHIFT                       (9U)
/*! MDM - MDM Reset
 *  0b0..Reset was not generated from the MDM reset request.
 *  0b1..Reset was generated from the MDM reset request.
 */
#define SMC_SSRS_MDM(x)                          (((uint32_t)(((uint32_t)(x)) << SMC_SSRS_MDM_SHIFT)) & SMC_SSRS_MDM_MASK)

#define SMC_SSRS_RSTACK_MASK                     (0x400U)
#define SMC_SSRS_RSTACK_SHIFT                    (10U)
/*! RSTACK - Reset Timeout
 *  0b0..Reset not generated from Reset Controller Timeout.
 *  0b1..Reset generated from Reset Controller Timeout.
 */
#define SMC_SSRS_RSTACK(x)                       (((uint32_t)(((uint32_t)(x)) << SMC_SSRS_RSTACK_SHIFT)) & SMC_SSRS_RSTACK_MASK)

#define SMC_SSRS_STOPACK_MASK                    (0x800U)
#define SMC_SSRS_STOPACK_SHIFT                   (11U)
/*! STOPACK - Stop Timeout Reset
 *  0b0..Reset not generated by Stop Controller Timeout.
 *  0b1..Reset generated by Stop Controller Timeout.
 */
#define SMC_SSRS_STOPACK(x)                      (((uint32_t)(((uint32_t)(x)) << SMC_SSRS_STOPACK_SHIFT)) & SMC_SSRS_STOPACK_MASK)

#define SMC_SSRS_SCG_MASK                        (0x1000U)
#define SMC_SSRS_SCG_SHIFT                       (12U)
/*! SCG - SCG Reset
 *  0b0..Reset is not generated from an SCG loss of lock or loss of clock.
 *  0b1..Reset is generated from an SCG loss of lock or loss of clock.
 */
#define SMC_SSRS_SCG(x)                          (((uint32_t)(((uint32_t)(x)) << SMC_SSRS_SCG_SHIFT)) & SMC_SSRS_SCG_MASK)

#define SMC_SSRS_WDOG_MASK                       (0x2000U)
#define SMC_SSRS_WDOG_SHIFT                      (13U)
/*! WDOG - Watchdog Reset
 *  0b0..Reset is not generated from the WatchDog timeout.
 *  0b1..Reset is generated from the WatchDog timeout.
 */
#define SMC_SSRS_WDOG(x)                         (((uint32_t)(((uint32_t)(x)) << SMC_SSRS_WDOG_SHIFT)) & SMC_SSRS_WDOG_MASK)

#define SMC_SSRS_SW_MASK                         (0x4000U)
#define SMC_SSRS_SW_SHIFT                        (14U)
/*! SW - Software Reset
 *  0b0..Reset not generated by software request from core.
 *  0b1..Reset generated by software request from core.
 */
#define SMC_SSRS_SW(x)                           (((uint32_t)(((uint32_t)(x)) << SMC_SSRS_SW_SHIFT)) & SMC_SSRS_SW_MASK)

#define SMC_SSRS_LOCKUP_MASK                     (0x8000U)
#define SMC_SSRS_LOCKUP_SHIFT                    (15U)
/*! LOCKUP - Lockup Reset
 *  0b0..Reset not generated by core lockup.
 *  0b1..Reset generated by core lockup.
 */
#define SMC_SSRS_LOCKUP(x)                       (((uint32_t)(((uint32_t)(x)) << SMC_SSRS_LOCKUP_SHIFT)) & SMC_SSRS_LOCKUP_MASK)

#define SMC_SSRS_CORE0_MASK                      (0x10000U)
#define SMC_SSRS_CORE0_SHIFT                     (16U)
/*! CORE0 - Core0 Reset
 *  0b0..Reset not generated from Core0 reset source.
 *  0b1..Reset generated from Core0 reset source.
 */
#define SMC_SSRS_CORE0(x)                        (((uint32_t)(((uint32_t)(x)) << SMC_SSRS_CORE0_SHIFT)) & SMC_SSRS_CORE0_MASK)

#define SMC_SSRS_CORE1_MASK                      (0x20000U)
#define SMC_SSRS_CORE1_SHIFT                     (17U)
/*! CORE1 - Core1 Reset
 *  0b0..Reset not generated from Core1 reset source.
 *  0b1..Reset generated from Core1 reset source.
 */
#define SMC_SSRS_CORE1(x)                        (((uint32_t)(((uint32_t)(x)) << SMC_SSRS_CORE1_SHIFT)) & SMC_SSRS_CORE1_MASK)

#define SMC_SSRS_JTAG_MASK                       (0x10000000U)
#define SMC_SSRS_JTAG_SHIFT                      (28U)
/*! JTAG - JTAG System Reset
 *  0b0..Reset not generated by JTAG system reset.
 *  0b1..Reset generated by JTAG system reset.
 */
#define SMC_SSRS_JTAG(x)                         (((uint32_t)(((uint32_t)(x)) << SMC_SSRS_JTAG_SHIFT)) & SMC_SSRS_JTAG_MASK)
/*! @} */

/*! @name SRIE - System Reset Interrupt Enable */
/*! @{ */

#define SMC_SRIE_PIN_MASK                        (0x100U)
#define SMC_SRIE_PIN_SHIFT                       (8U)
/*! PIN - Pin Reset
 *  0b0..Interrupt disabled.
 *  0b1..Interrupt enabled.
 */
#define SMC_SRIE_PIN(x)                          (((uint32_t)(((uint32_t)(x)) << SMC_SRIE_PIN_SHIFT)) & SMC_SRIE_PIN_MASK)

#define SMC_SRIE_MDM_MASK                        (0x200U)
#define SMC_SRIE_MDM_SHIFT                       (9U)
/*! MDM - MDM Reset
 *  0b0..Interrupt disabled.
 *  0b1..Interrupt enabled.
 */
#define SMC_SRIE_MDM(x)                          (((uint32_t)(((uint32_t)(x)) << SMC_SRIE_MDM_SHIFT)) & SMC_SRIE_MDM_MASK)

#define SMC_SRIE_STOPACK_MASK                    (0x800U)
#define SMC_SRIE_STOPACK_SHIFT                   (11U)
/*! STOPACK - Stop Timeout Reset
 *  0b0..Interrupt disabled.
 *  0b1..Interrupt enabled.
 */
#define SMC_SRIE_STOPACK(x)                      (((uint32_t)(((uint32_t)(x)) << SMC_SRIE_STOPACK_SHIFT)) & SMC_SRIE_STOPACK_MASK)

#define SMC_SRIE_WDOG_MASK                       (0x2000U)
#define SMC_SRIE_WDOG_SHIFT                      (13U)
/*! WDOG - Watchdog Reset
 *  0b0..Interrupt disabled.
 *  0b1..Interrupt enabled.
 */
#define SMC_SRIE_WDOG(x)                         (((uint32_t)(((uint32_t)(x)) << SMC_SRIE_WDOG_SHIFT)) & SMC_SRIE_WDOG_MASK)

#define SMC_SRIE_SW_MASK                         (0x4000U)
#define SMC_SRIE_SW_SHIFT                        (14U)
/*! SW - Software Reset
 *  0b0..Interrupt disabled.
 *  0b1..Interrupt enabled.
 */
#define SMC_SRIE_SW(x)                           (((uint32_t)(((uint32_t)(x)) << SMC_SRIE_SW_SHIFT)) & SMC_SRIE_SW_MASK)

#define SMC_SRIE_LOCKUP_MASK                     (0x8000U)
#define SMC_SRIE_LOCKUP_SHIFT                    (15U)
/*! LOCKUP - Lockup Reset
 *  0b0..Interrupt disabled.
 *  0b1..Interrupt enabled.
 */
#define SMC_SRIE_LOCKUP(x)                       (((uint32_t)(((uint32_t)(x)) << SMC_SRIE_LOCKUP_SHIFT)) & SMC_SRIE_LOCKUP_MASK)

#define SMC_SRIE_CORE0_MASK                      (0x10000U)
#define SMC_SRIE_CORE0_SHIFT                     (16U)
/*! CORE0 - Core0 Reset
 *  0b0..Interrupt disabled.
 *  0b1..Interrupt enabled.
 */
#define SMC_SRIE_CORE0(x)                        (((uint32_t)(((uint32_t)(x)) << SMC_SRIE_CORE0_SHIFT)) & SMC_SRIE_CORE0_MASK)

#define SMC_SRIE_CORE1_MASK                      (0x20000U)
#define SMC_SRIE_CORE1_SHIFT                     (17U)
/*! CORE1 - Core1 Reset
 *  0b0..Interrupt disabled.
 *  0b1..Interrupt enabled.
 */
#define SMC_SRIE_CORE1(x)                        (((uint32_t)(((uint32_t)(x)) << SMC_SRIE_CORE1_SHIFT)) & SMC_SRIE_CORE1_MASK)
/*! @} */

/*! @name SRIF - System Reset Interrupt Flag */
/*! @{ */

#define SMC_SRIF_PIN_MASK                        (0x100U)
#define SMC_SRIF_PIN_SHIFT                       (8U)
/*! PIN - Pin Reset
 *  0b0..Reset source not pending.
 *  0b1..Reset source pending.
 */
#define SMC_SRIF_PIN(x)                          (((uint32_t)(((uint32_t)(x)) << SMC_SRIF_PIN_SHIFT)) & SMC_SRIF_PIN_MASK)

#define SMC_SRIF_MDM_MASK                        (0x200U)
#define SMC_SRIF_MDM_SHIFT                       (9U)
/*! MDM - MDM Reset
 *  0b0..Reset source not pending.
 *  0b1..Reset source pending.
 */
#define SMC_SRIF_MDM(x)                          (((uint32_t)(((uint32_t)(x)) << SMC_SRIF_MDM_SHIFT)) & SMC_SRIF_MDM_MASK)

#define SMC_SRIF_STOPACK_MASK                    (0x800U)
#define SMC_SRIF_STOPACK_SHIFT                   (11U)
/*! STOPACK - Stop Timeout Reset
 *  0b0..Reset source not pending.
 *  0b1..Reset source pending.
 */
#define SMC_SRIF_STOPACK(x)                      (((uint32_t)(((uint32_t)(x)) << SMC_SRIF_STOPACK_SHIFT)) & SMC_SRIF_STOPACK_MASK)

#define SMC_SRIF_WDOG_MASK                       (0x2000U)
#define SMC_SRIF_WDOG_SHIFT                      (13U)
/*! WDOG - Watchdog Reset
 *  0b0..Reset source not pending.
 *  0b1..Reset source pending.
 */
#define SMC_SRIF_WDOG(x)                         (((uint32_t)(((uint32_t)(x)) << SMC_SRIF_WDOG_SHIFT)) & SMC_SRIF_WDOG_MASK)

#define SMC_SRIF_SW_MASK                         (0x4000U)
#define SMC_SRIF_SW_SHIFT                        (14U)
/*! SW - Software Reset
 *  0b0..Reset source not pending.
 *  0b1..Reset source pending.
 */
#define SMC_SRIF_SW(x)                           (((uint32_t)(((uint32_t)(x)) << SMC_SRIF_SW_SHIFT)) & SMC_SRIF_SW_MASK)

#define SMC_SRIF_LOCKUP_MASK                     (0x8000U)
#define SMC_SRIF_LOCKUP_SHIFT                    (15U)
/*! LOCKUP - Lockup Reset
 *  0b0..Reset source not pending.
 *  0b1..Reset source pending.
 */
#define SMC_SRIF_LOCKUP(x)                       (((uint32_t)(((uint32_t)(x)) << SMC_SRIF_LOCKUP_SHIFT)) & SMC_SRIF_LOCKUP_MASK)

#define SMC_SRIF_CORE0_MASK                      (0x10000U)
#define SMC_SRIF_CORE0_SHIFT                     (16U)
/*! CORE0 - Core0 Reset
 *  0b0..Reset source not pending.
 *  0b1..Reset source pending.
 */
#define SMC_SRIF_CORE0(x)                        (((uint32_t)(((uint32_t)(x)) << SMC_SRIF_CORE0_SHIFT)) & SMC_SRIF_CORE0_MASK)

#define SMC_SRIF_CORE1_MASK                      (0x20000U)
#define SMC_SRIF_CORE1_SHIFT                     (17U)
/*! CORE1 - Core1 Reset
 *  0b0..Reset source not pending.
 *  0b1..Reset source pending.
 */
#define SMC_SRIF_CORE1(x)                        (((uint32_t)(((uint32_t)(x)) << SMC_SRIF_CORE1_SHIFT)) & SMC_SRIF_CORE1_MASK)
/*! @} */

/*! @name MR - Mode Register */
/*! @{ */

#define SMC_MR_BOOTCFG_MASK                      (0x3U)
#define SMC_MR_BOOTCFG_SHIFT                     (0U)
/*! BOOTCFG - Boot Configuration
 *  0b00..Boot from Flash.
 *  0b01..Boot from ROM due to BOOTCFG0 pin assertion.
 *  0b10..Boot from ROM due to FOPT configuration.
 *  0b11..Boot from ROM due to both BOOTCFG0 pin assertion and FOPT configuration.
 */
#define SMC_MR_BOOTCFG(x)                        (((uint32_t)(((uint32_t)(x)) << SMC_MR_BOOTCFG_SHIFT)) & SMC_MR_BOOTCFG_MASK)
/*! @} */

/*! @name FM - Force Mode Register */
/*! @{ */

#define SMC_FM_FORCECFG_MASK                     (0x3U)
#define SMC_FM_FORCECFG_SHIFT                    (0U)
/*! FORCECFG - Boot Configuration
 *  0b00..No effect.
 *  0b01..Assert corresponding bit in Mode Register on next system reset.
 */
#define SMC_FM_FORCECFG(x)                       (((uint32_t)(((uint32_t)(x)) << SMC_FM_FORCECFG_SHIFT)) & SMC_FM_FORCECFG_MASK)
/*! @} */

/*! @name SRAMLPR - SRAM Low Power Register */
/*! @{ */

#define SMC_SRAMLPR_LPE_MASK                     (0xFFFFFFFFU)
#define SMC_SRAMLPR_LPE_SHIFT                    (0U)
/*! LPE - Low Power Enable */
#define SMC_SRAMLPR_LPE(x)                       (((uint32_t)(((uint32_t)(x)) << SMC_SRAMLPR_LPE_SHIFT)) & SMC_SRAMLPR_LPE_MASK)
/*! @} */

/*! @name SRAMDSR - SRAM Deep Sleep Register */
/*! @{ */

#define SMC_SRAMDSR_DSE_MASK                     (0xFFFFFFFFU)
#define SMC_SRAMDSR_DSE_SHIFT                    (0U)
/*! DSE - Deep Sleep Enable */
#define SMC_SRAMDSR_DSE(x)                       (((uint32_t)(((uint32_t)(x)) << SMC_SRAMDSR_DSE_SHIFT)) & SMC_SRAMDSR_DSE_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SMC_Register_Masks */


/*!
 * @}
 */ /* end of group SMC_Peripheral_Access_Layer */


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


#endif  /* PERI_SMC_H_ */

