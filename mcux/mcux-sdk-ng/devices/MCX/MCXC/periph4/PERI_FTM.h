/*
** ###################################################################
**     Processors:          MCXC352GAMFM
**                          MCXC352GAMFT
**                          MCXC352MLF
**                          MCXC353GAMFM
**                          MCXC353GAMFT
**                          MCXC353MLF
**
**     Version:             rev. 1.0, 2025-11-26
**     Build:               b260826
**
**     Abstract:
**         CMSIS Peripheral Access Layer for FTM
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2026 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2025-11-26)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_FTM.h
 * @version 1.0
 * @date 2025-11-26
 * @brief CMSIS Peripheral Access Layer for FTM
 *
 * CMSIS Peripheral Access Layer for FTM
 */

#if !defined(PERI_FTM_H_)
#define PERI_FTM_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXC352GAMFM) || defined(CPU_MCXC352GAMFT) || defined(CPU_MCXC352MLF))
#include "MCXC352_COMMON.h"
#elif (defined(CPU_MCXC353GAMFM) || defined(CPU_MCXC353GAMFT) || defined(CPU_MCXC353MLF))
#include "MCXC353_COMMON.h"
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
   -- FTM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FTM_Peripheral_Access_Layer FTM Peripheral Access Layer
 * @{
 */

/** FTM - Size of Registers Arrays */
#define FTM_CONTROLS_COUNT                        2u
#define FTM_CV_MIRROR_COUNT                       2u

/** FTM - Register Layout Typedef */
typedef struct {
  __IO uint32_t SC;                                /**< Status and Control, offset: 0x0 */
  __IO uint32_t CNT;                               /**< Counter, offset: 0x4 */
  __IO uint32_t MOD;                               /**< Modulo, offset: 0x8 */
  struct {                                         /* offset: 0xC, array step: 0x8 */
    __IO uint32_t CnSC;                              /**< Channel n Status and Control, array offset: 0xC, array step: 0x8 */
    __IO uint32_t CnV;                               /**< Channel n Value, array offset: 0x10, array step: 0x8 */
  } CONTROLS[FTM_CONTROLS_COUNT];
       uint8_t RESERVED_0[48];
  __IO uint32_t CNTIN;                             /**< Counter Initial Value, offset: 0x4C */
  __IO uint32_t STATUS;                            /**< Capture and Compare Status, offset: 0x50 */
  __IO uint32_t MODE;                              /**< Feature Mode Selection, offset: 0x54 */
  __IO uint32_t SYNC;                              /**< Synchronization, offset: 0x58 */
  __IO uint32_t OUTINIT;                           /**< Initial State for Channel Output, offset: 0x5C */
  __IO uint32_t OUTMASK;                           /**< Output Mask, offset: 0x60 */
  __IO uint32_t COMBINE;                           /**< Functions for Linked Channels, offset: 0x64 */
  __IO uint32_t DEADTIME;                          /**< Dead Time Configuration, offset: 0x68 */
  __IO uint32_t EXTTRIG;                           /**< FTM External Trigger, offset: 0x6C */
  __IO uint32_t POL;                               /**< Channel Polarity, offset: 0x70 */
  __IO uint32_t FMS;                               /**< Fault Mode Status, offset: 0x74 */
  __IO uint32_t FILTER;                            /**< Input Capture Filter Control, offset: 0x78 */
       uint8_t RESERVED_1[8];
  __IO uint32_t CONF;                              /**< Configuration, offset: 0x84 */
       uint8_t RESERVED_2[4];
  __IO uint32_t SYNCONF;                           /**< Synchronization Configuration, offset: 0x8C */
  __IO uint32_t INVCTRL;                           /**< FTM Inverting Control, offset: 0x90 */
  __IO uint32_t SWOCTRL;                           /**< FTM Software Output Control, offset: 0x94 */
  __IO uint32_t PWMLOAD;                           /**< FTM PWM Load, offset: 0x98 */
  __IO uint32_t HCR;                               /**< Half-Cycle Reload, offset: 0x9C */
       uint8_t RESERVED_3[352];
  __IO uint32_t MOD_MIRROR;                        /**< Mirror of Modulo Value, offset: 0x200 */
  __IO uint32_t CV_MIRROR[FTM_CV_MIRROR_COUNT];    /**< Mirror of Channel n Match Value, array offset: 0x204, array step: 0x4 */
} FTM_Type;

/* ----------------------------------------------------------------------------
   -- FTM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FTM_Register_Masks FTM Register Masks
 * @{
 */

/*! @name SC - Status and Control */
/*! @{ */

#define FTM_SC_PS_MASK                           (0x7U)
#define FTM_SC_PS_SHIFT                          (0U)
/*! PS - Prescale Factor Selection
 *  0b000..1
 *  0b001..2
 *  0b010..4
 *  0b011..8
 *  0b100..16
 *  0b101..32
 *  0b110..64
 *  0b111..128
 */
#define FTM_SC_PS(x)                             (((uint32_t)(((uint32_t)(x)) << FTM_SC_PS_SHIFT)) & FTM_SC_PS_MASK)

#define FTM_SC_CLKS_MASK                         (0x18U)
#define FTM_SC_CLKS_SHIFT                        (3U)
/*! CLKS - Clock Source Selection
 *  0b00..No clock selected; FTM counter disabled
 *  0b01..FTM input clock
 *  0b10..Fixed-frequency clock
 *  0b11..External clock
 */
#define FTM_SC_CLKS(x)                           (((uint32_t)(((uint32_t)(x)) << FTM_SC_CLKS_SHIFT)) & FTM_SC_CLKS_MASK)

#define FTM_SC_CPWMS_MASK                        (0x20U)
#define FTM_SC_CPWMS_SHIFT                       (5U)
/*! CPWMS - Center-Aligned PWM Select
 *  0b0..Up Counting mode
 *  0b1..Up-Down Counting mode
 */
#define FTM_SC_CPWMS(x)                          (((uint32_t)(((uint32_t)(x)) << FTM_SC_CPWMS_SHIFT)) & FTM_SC_CPWMS_MASK)

#define FTM_SC_RIE_MASK                          (0x40U)
#define FTM_SC_RIE_SHIFT                         (6U)
/*! RIE - Reload Point Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define FTM_SC_RIE(x)                            (((uint32_t)(((uint32_t)(x)) << FTM_SC_RIE_SHIFT)) & FTM_SC_RIE_MASK)

#define FTM_SC_RF_MASK                           (0x80U)
#define FTM_SC_RF_SHIFT                          (7U)
/*! RF - Reload Flag
 *  0b0..Reload point did not occur
 *  0b1..Reload point occurred
 */
#define FTM_SC_RF(x)                             (((uint32_t)(((uint32_t)(x)) << FTM_SC_RF_SHIFT)) & FTM_SC_RF_MASK)

#define FTM_SC_TOIE_MASK                         (0x100U)
#define FTM_SC_TOIE_SHIFT                        (8U)
/*! TOIE - Timer Overflow Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define FTM_SC_TOIE(x)                           (((uint32_t)(((uint32_t)(x)) << FTM_SC_TOIE_SHIFT)) & FTM_SC_TOIE_MASK)

#define FTM_SC_TOF_MASK                          (0x200U)
#define FTM_SC_TOF_SHIFT                         (9U)
/*! TOF - Timer Overflow Flag
 *  0b0..No overflow
 *  0b1..Overflow
 */
#define FTM_SC_TOF(x)                            (((uint32_t)(((uint32_t)(x)) << FTM_SC_TOF_SHIFT)) & FTM_SC_TOF_MASK)

#define FTM_SC_PWMEN0_MASK                       (0x10000U)
#define FTM_SC_PWMEN0_SHIFT                      (16U)
/*! PWMEN0 - Channel 0 PWM Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define FTM_SC_PWMEN0(x)                         (((uint32_t)(((uint32_t)(x)) << FTM_SC_PWMEN0_SHIFT)) & FTM_SC_PWMEN0_MASK)

#define FTM_SC_PWMEN1_MASK                       (0x20000U)
#define FTM_SC_PWMEN1_SHIFT                      (17U)
/*! PWMEN1 - Channel 1 PWM Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define FTM_SC_PWMEN1(x)                         (((uint32_t)(((uint32_t)(x)) << FTM_SC_PWMEN1_SHIFT)) & FTM_SC_PWMEN1_MASK)

#define FTM_SC_FLTPS_MASK                        (0xF000000U)
#define FTM_SC_FLTPS_SHIFT                       (24U)
/*! FLTPS - Filter Prescaler
 *  0b0000..1
 *  0b0001..2
 *  0b0010..3
 *  0b0011..4
 *  0b0100..5
 *  0b0101..6
 *  0b0110..7
 *  0b0111..8
 *  0b1000..9
 *  0b1001..10
 *  0b1010..11
 *  0b1011..12
 *  0b1100..13
 *  0b1101..14
 *  0b1110..15
 *  0b1111..16
 */
#define FTM_SC_FLTPS(x)                          (((uint32_t)(((uint32_t)(x)) << FTM_SC_FLTPS_SHIFT)) & FTM_SC_FLTPS_MASK)
/*! @} */

/*! @name CNT - Counter */
/*! @{ */

#define FTM_CNT_COUNT_MASK                       (0xFFFFU)
#define FTM_CNT_COUNT_SHIFT                      (0U)
/*! COUNT - Counter Value */
#define FTM_CNT_COUNT(x)                         (((uint32_t)(((uint32_t)(x)) << FTM_CNT_COUNT_SHIFT)) & FTM_CNT_COUNT_MASK)
/*! @} */

/*! @name MOD - Modulo */
/*! @{ */

#define FTM_MOD_MOD_MASK                         (0xFFFFU)
#define FTM_MOD_MOD_SHIFT                        (0U)
/*! MOD - Modulo Value */
#define FTM_MOD_MOD(x)                           (((uint32_t)(((uint32_t)(x)) << FTM_MOD_MOD_SHIFT)) & FTM_MOD_MOD_MASK)
/*! @} */

/*! @name CnSC - Channel n Status and Control */
/*! @{ */

#define FTM_CnSC_DMA_MASK                        (0x1U)
#define FTM_CnSC_DMA_SHIFT                       (0U)
/*! DMA - DMA Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define FTM_CnSC_DMA(x)                          (((uint32_t)(((uint32_t)(x)) << FTM_CnSC_DMA_SHIFT)) & FTM_CnSC_DMA_MASK)

#define FTM_CnSC_ICRST_MASK                      (0x2U)
#define FTM_CnSC_ICRST_SHIFT                     (1U)
/*! ICRST - Input Capture Reset
 *  0b0..Disable
 *  0b1..Enable
 */
#define FTM_CnSC_ICRST(x)                        (((uint32_t)(((uint32_t)(x)) << FTM_CnSC_ICRST_SHIFT)) & FTM_CnSC_ICRST_MASK)

#define FTM_CnSC_ELSA_MASK                       (0x4U)
#define FTM_CnSC_ELSA_SHIFT                      (2U)
/*! ELSA - Channel n Edge or Level Select A */
#define FTM_CnSC_ELSA(x)                         (((uint32_t)(((uint32_t)(x)) << FTM_CnSC_ELSA_SHIFT)) & FTM_CnSC_ELSA_MASK)

#define FTM_CnSC_ELSB_MASK                       (0x8U)
#define FTM_CnSC_ELSB_SHIFT                      (3U)
/*! ELSB - Channel n Edge or Level Select B */
#define FTM_CnSC_ELSB(x)                         (((uint32_t)(((uint32_t)(x)) << FTM_CnSC_ELSB_SHIFT)) & FTM_CnSC_ELSB_MASK)

#define FTM_CnSC_MSA_MASK                        (0x10U)
#define FTM_CnSC_MSA_SHIFT                       (4U)
/*! MSA - Channel n Mode Select A */
#define FTM_CnSC_MSA(x)                          (((uint32_t)(((uint32_t)(x)) << FTM_CnSC_MSA_SHIFT)) & FTM_CnSC_MSA_MASK)

#define FTM_CnSC_MSB_MASK                        (0x20U)
#define FTM_CnSC_MSB_SHIFT                       (5U)
/*! MSB - Channel n Mode Select B */
#define FTM_CnSC_MSB(x)                          (((uint32_t)(((uint32_t)(x)) << FTM_CnSC_MSB_SHIFT)) & FTM_CnSC_MSB_MASK)

#define FTM_CnSC_CHIE_MASK                       (0x40U)
#define FTM_CnSC_CHIE_SHIFT                      (6U)
/*! CHIE - Channel n Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define FTM_CnSC_CHIE(x)                         (((uint32_t)(((uint32_t)(x)) << FTM_CnSC_CHIE_SHIFT)) & FTM_CnSC_CHIE_MASK)

#define FTM_CnSC_CHF_MASK                        (0x80U)
#define FTM_CnSC_CHF_SHIFT                       (7U)
/*! CHF - Channel n Flag
 *  0b0..No event occurred
 *  0b1..Event occurred
 */
#define FTM_CnSC_CHF(x)                          (((uint32_t)(((uint32_t)(x)) << FTM_CnSC_CHF_SHIFT)) & FTM_CnSC_CHF_MASK)

#define FTM_CnSC_TRIGMODE_MASK                   (0x100U)
#define FTM_CnSC_TRIGMODE_SHIFT                  (8U)
/*! TRIGMODE - Trigger Mode Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define FTM_CnSC_TRIGMODE(x)                     (((uint32_t)(((uint32_t)(x)) << FTM_CnSC_TRIGMODE_SHIFT)) & FTM_CnSC_TRIGMODE_MASK)

#define FTM_CnSC_CHIS_MASK                       (0x200U)
#define FTM_CnSC_CHIS_SHIFT                      (9U)
/*! CHIS - Channel n Input State
 *  0b0..0
 *  0b1..1
 */
#define FTM_CnSC_CHIS(x)                         (((uint32_t)(((uint32_t)(x)) << FTM_CnSC_CHIS_SHIFT)) & FTM_CnSC_CHIS_MASK)

#define FTM_CnSC_CHOV_MASK                       (0x400U)
#define FTM_CnSC_CHOV_SHIFT                      (10U)
/*! CHOV - Channel n Output Value
 *  0b0..0
 *  0b1..1
 */
#define FTM_CnSC_CHOV(x)                         (((uint32_t)(((uint32_t)(x)) << FTM_CnSC_CHOV_SHIFT)) & FTM_CnSC_CHOV_MASK)
/*! @} */

/* The count of FTM_CnSC */
#define FTM_CnSC_COUNT                           (2U)

/*! @name CnV - Channel n Value */
/*! @{ */

#define FTM_CnV_VAL_MASK                         (0xFFFFU)
#define FTM_CnV_VAL_SHIFT                        (0U)
/*! VAL - Channel Value */
#define FTM_CnV_VAL(x)                           (((uint32_t)(((uint32_t)(x)) << FTM_CnV_VAL_SHIFT)) & FTM_CnV_VAL_MASK)
/*! @} */

/* The count of FTM_CnV */
#define FTM_CnV_COUNT                            (2U)

/*! @name CNTIN - Counter Initial Value */
/*! @{ */

#define FTM_CNTIN_INIT_MASK                      (0xFFFFU)
#define FTM_CNTIN_INIT_SHIFT                     (0U)
/*! INIT - Initial Value of FTM Counter */
#define FTM_CNTIN_INIT(x)                        (((uint32_t)(((uint32_t)(x)) << FTM_CNTIN_INIT_SHIFT)) & FTM_CNTIN_INIT_MASK)
/*! @} */

/*! @name STATUS - Capture and Compare Status */
/*! @{ */

#define FTM_STATUS_CH0F_MASK                     (0x1U)
#define FTM_STATUS_CH0F_SHIFT                    (0U)
/*! CH0F - Channel 0 Flag
 *  0b0..No channel event occurred
 *  0b1..A channel event occurred
 */
#define FTM_STATUS_CH0F(x)                       (((uint32_t)(((uint32_t)(x)) << FTM_STATUS_CH0F_SHIFT)) & FTM_STATUS_CH0F_MASK)

#define FTM_STATUS_CH1F_MASK                     (0x2U)
#define FTM_STATUS_CH1F_SHIFT                    (1U)
/*! CH1F - Channel 1 Flag
 *  0b0..No channel event occurred
 *  0b1..A channel event occurred
 */
#define FTM_STATUS_CH1F(x)                       (((uint32_t)(((uint32_t)(x)) << FTM_STATUS_CH1F_SHIFT)) & FTM_STATUS_CH1F_MASK)
/*! @} */

/*! @name MODE - Feature Mode Selection */
/*! @{ */

#define FTM_MODE_FTMEN_MASK                      (0x1U)
#define FTM_MODE_FTMEN_SHIFT                     (0U)
/*! FTMEN - FTM Mode Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define FTM_MODE_FTMEN(x)                        (((uint32_t)(((uint32_t)(x)) << FTM_MODE_FTMEN_SHIFT)) & FTM_MODE_FTMEN_MASK)

#define FTM_MODE_INIT_MASK                       (0x2U)
#define FTM_MODE_INIT_SHIFT                      (1U)
/*! INIT - Initialize Channel Outputs
 *  0b0..No effect
 *  0b1..Initialize channel outputs
 */
#define FTM_MODE_INIT(x)                         (((uint32_t)(((uint32_t)(x)) << FTM_MODE_INIT_SHIFT)) & FTM_MODE_INIT_MASK)

#define FTM_MODE_WPDIS_MASK                      (0x4U)
#define FTM_MODE_WPDIS_SHIFT                     (2U)
/*! WPDIS - Write Protection Disable
 *  0b0..Enable
 *  0b1..Disable
 */
#define FTM_MODE_WPDIS(x)                        (((uint32_t)(((uint32_t)(x)) << FTM_MODE_WPDIS_SHIFT)) & FTM_MODE_WPDIS_MASK)

#define FTM_MODE_PWMSYNC_MASK                    (0x8U)
#define FTM_MODE_PWMSYNC_SHIFT                   (3U)
/*! PWMSYNC - PWM Synchronization Mode
 *  0b0..No restrictions.
 *  0b1..MOD and CnV use the software trigger only; OUTMASK and FTM counter synchronization use hardware triggers only
 */
#define FTM_MODE_PWMSYNC(x)                      (((uint32_t)(((uint32_t)(x)) << FTM_MODE_PWMSYNC_SHIFT)) & FTM_MODE_PWMSYNC_MASK)

#define FTM_MODE_CAPTEST_MASK                    (0x10U)
#define FTM_MODE_CAPTEST_SHIFT                   (4U)
/*! CAPTEST - Capture Test Mode Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define FTM_MODE_CAPTEST(x)                      (((uint32_t)(((uint32_t)(x)) << FTM_MODE_CAPTEST_SHIFT)) & FTM_MODE_CAPTEST_MASK)
/*! @} */

/*! @name SYNC - Synchronization */
/*! @{ */

#define FTM_SYNC_CNTMIN_MASK                     (0x1U)
#define FTM_SYNC_CNTMIN_SHIFT                    (0U)
/*! CNTMIN - Minimum Loading Point Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define FTM_SYNC_CNTMIN(x)                       (((uint32_t)(((uint32_t)(x)) << FTM_SYNC_CNTMIN_SHIFT)) & FTM_SYNC_CNTMIN_MASK)

#define FTM_SYNC_CNTMAX_MASK                     (0x2U)
#define FTM_SYNC_CNTMAX_SHIFT                    (1U)
/*! CNTMAX - Maximum Loading Point Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define FTM_SYNC_CNTMAX(x)                       (((uint32_t)(((uint32_t)(x)) << FTM_SYNC_CNTMAX_SHIFT)) & FTM_SYNC_CNTMAX_MASK)

#define FTM_SYNC_REINIT_MASK                     (0x4U)
#define FTM_SYNC_REINIT_SHIFT                    (2U)
/*! REINIT - FTM Counter Reinitialization by Synchronization Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define FTM_SYNC_REINIT(x)                       (((uint32_t)(((uint32_t)(x)) << FTM_SYNC_REINIT_SHIFT)) & FTM_SYNC_REINIT_MASK)

#define FTM_SYNC_SYNCHOM_MASK                    (0x8U)
#define FTM_SYNC_SYNCHOM_SHIFT                   (3U)
/*! SYNCHOM - Output Mask Synchronization
 *  0b0..On all rising edges of the FTM input clock
 *  0b1..By PWM synchronization only
 */
#define FTM_SYNC_SYNCHOM(x)                      (((uint32_t)(((uint32_t)(x)) << FTM_SYNC_SYNCHOM_SHIFT)) & FTM_SYNC_SYNCHOM_MASK)

#define FTM_SYNC_TRIG0_MASK                      (0x10U)
#define FTM_SYNC_TRIG0_SHIFT                     (4U)
/*! TRIG0 - PWM Synchronization Hardware Trigger 0
 *  0b0..Disable
 *  0b1..Enable
 */
#define FTM_SYNC_TRIG0(x)                        (((uint32_t)(((uint32_t)(x)) << FTM_SYNC_TRIG0_SHIFT)) & FTM_SYNC_TRIG0_MASK)

#define FTM_SYNC_TRIG1_MASK                      (0x20U)
#define FTM_SYNC_TRIG1_SHIFT                     (5U)
/*! TRIG1 - PWM Synchronization Hardware Trigger 1
 *  0b0..Disable
 *  0b1..Enable
 */
#define FTM_SYNC_TRIG1(x)                        (((uint32_t)(((uint32_t)(x)) << FTM_SYNC_TRIG1_SHIFT)) & FTM_SYNC_TRIG1_MASK)

#define FTM_SYNC_TRIG2_MASK                      (0x40U)
#define FTM_SYNC_TRIG2_SHIFT                     (6U)
/*! TRIG2 - PWM Synchronization Hardware Trigger 2
 *  0b0..Disable
 *  0b1..Enable
 */
#define FTM_SYNC_TRIG2(x)                        (((uint32_t)(((uint32_t)(x)) << FTM_SYNC_TRIG2_SHIFT)) & FTM_SYNC_TRIG2_MASK)

#define FTM_SYNC_SWSYNC_MASK                     (0x80U)
#define FTM_SYNC_SWSYNC_SHIFT                    (7U)
/*! SWSYNC - PWM Synchronization Software Trigger
 *  0b0..Not selected
 *  0b1..Selected
 */
#define FTM_SYNC_SWSYNC(x)                       (((uint32_t)(((uint32_t)(x)) << FTM_SYNC_SWSYNC_SHIFT)) & FTM_SYNC_SWSYNC_MASK)
/*! @} */

/*! @name OUTINIT - Initial State for Channel Output */
/*! @{ */

#define FTM_OUTINIT_CH0OI_MASK                   (0x1U)
#define FTM_OUTINIT_CH0OI_SHIFT                  (0U)
/*! CH0OI - Channel 0 Output Initialization Value
 *  0b0..0
 *  0b1..1
 */
#define FTM_OUTINIT_CH0OI(x)                     (((uint32_t)(((uint32_t)(x)) << FTM_OUTINIT_CH0OI_SHIFT)) & FTM_OUTINIT_CH0OI_MASK)

#define FTM_OUTINIT_CH1OI_MASK                   (0x2U)
#define FTM_OUTINIT_CH1OI_SHIFT                  (1U)
/*! CH1OI - Channel 1 Output Initialization Value
 *  0b0..0
 *  0b1..1
 */
#define FTM_OUTINIT_CH1OI(x)                     (((uint32_t)(((uint32_t)(x)) << FTM_OUTINIT_CH1OI_SHIFT)) & FTM_OUTINIT_CH1OI_MASK)
/*! @} */

/*! @name OUTMASK - Output Mask */
/*! @{ */

#define FTM_OUTMASK_CH0OM_MASK                   (0x1U)
#define FTM_OUTMASK_CH0OM_SHIFT                  (0U)
/*! CH0OM - Channel 0 Output Mask
 *  0b0..Unmask
 *  0b1..Mask
 */
#define FTM_OUTMASK_CH0OM(x)                     (((uint32_t)(((uint32_t)(x)) << FTM_OUTMASK_CH0OM_SHIFT)) & FTM_OUTMASK_CH0OM_MASK)

#define FTM_OUTMASK_CH1OM_MASK                   (0x2U)
#define FTM_OUTMASK_CH1OM_SHIFT                  (1U)
/*! CH1OM - Channel 1 Output Mask
 *  0b0..Unmask
 *  0b1..Mask
 */
#define FTM_OUTMASK_CH1OM(x)                     (((uint32_t)(((uint32_t)(x)) << FTM_OUTMASK_CH1OM_SHIFT)) & FTM_OUTMASK_CH1OM_MASK)
/*! @} */

/*! @name COMBINE - Functions for Linked Channels */
/*! @{ */

#define FTM_COMBINE_COMBINE0_MASK                (0x1U)
#define FTM_COMBINE_COMBINE0_SHIFT               (0U)
/*! COMBINE0 - Combine Mode Enable for Channels 0 and 1
 *  0b0..Disable
 *  0b1..Enable
 */
#define FTM_COMBINE_COMBINE0(x)                  (((uint32_t)(((uint32_t)(x)) << FTM_COMBINE_COMBINE0_SHIFT)) & FTM_COMBINE_COMBINE0_MASK)

#define FTM_COMBINE_COMP0_MASK                   (0x2U)
#define FTM_COMBINE_COMP0_SHIFT                  (1U)
/*! COMP0 - Complementary Mode Enable for Channels 0 and 1
 *  0b0..Disable
 *  0b1..Enable
 */
#define FTM_COMBINE_COMP0(x)                     (((uint32_t)(((uint32_t)(x)) << FTM_COMBINE_COMP0_SHIFT)) & FTM_COMBINE_COMP0_MASK)

#define FTM_COMBINE_DECAPEN0_MASK                (0x4U)
#define FTM_COMBINE_DECAPEN0_SHIFT               (2U)
/*! DECAPEN0 - Dual-Edge Capture Mode Enable for Channels 0 and 1
 *  0b0..Disable
 *  0b1..Enable
 */
#define FTM_COMBINE_DECAPEN0(x)                  (((uint32_t)(((uint32_t)(x)) << FTM_COMBINE_DECAPEN0_SHIFT)) & FTM_COMBINE_DECAPEN0_MASK)

#define FTM_COMBINE_DECAP0_MASK                  (0x8U)
#define FTM_COMBINE_DECAP0_SHIFT                 (3U)
/*! DECAP0 - Dual-Edge Capture Mode Captures for Channels 0 and 1
 *  0b0..Disable
 *  0b1..Enable
 */
#define FTM_COMBINE_DECAP0(x)                    (((uint32_t)(((uint32_t)(x)) << FTM_COMBINE_DECAP0_SHIFT)) & FTM_COMBINE_DECAP0_MASK)

#define FTM_COMBINE_DTEN0_MASK                   (0x10U)
#define FTM_COMBINE_DTEN0_SHIFT                  (4U)
/*! DTEN0 - Dead Time Enable for Channels 0 and 1
 *  0b0..Disable
 *  0b1..Enable
 */
#define FTM_COMBINE_DTEN0(x)                     (((uint32_t)(((uint32_t)(x)) << FTM_COMBINE_DTEN0_SHIFT)) & FTM_COMBINE_DTEN0_MASK)

#define FTM_COMBINE_SYNCEN0_MASK                 (0x20U)
#define FTM_COMBINE_SYNCEN0_SHIFT                (5U)
/*! SYNCEN0 - Synchronization Enable for C0V and C1V
 *  0b0..Disable
 *  0b1..Enable
 */
#define FTM_COMBINE_SYNCEN0(x)                   (((uint32_t)(((uint32_t)(x)) << FTM_COMBINE_SYNCEN0_SHIFT)) & FTM_COMBINE_SYNCEN0_MASK)

#define FTM_COMBINE_MCOMBINE0_MASK               (0x80U)
#define FTM_COMBINE_MCOMBINE0_SHIFT              (7U)
/*! MCOMBINE0 - Modified Combine Mode for Channels 0 and 1
 *  0b0..Disable
 *  0b1..Enable
 */
#define FTM_COMBINE_MCOMBINE0(x)                 (((uint32_t)(((uint32_t)(x)) << FTM_COMBINE_MCOMBINE0_SHIFT)) & FTM_COMBINE_MCOMBINE0_MASK)
/*! @} */

/*! @name DEADTIME - Dead Time Configuration */
/*! @{ */

#define FTM_DEADTIME_DTVAL_MASK                  (0x3FU)
#define FTM_DEADTIME_DTVAL_SHIFT                 (0U)
/*! DTVAL - Dead Time Value */
#define FTM_DEADTIME_DTVAL(x)                    (((uint32_t)(((uint32_t)(x)) << FTM_DEADTIME_DTVAL_SHIFT)) & FTM_DEADTIME_DTVAL_MASK)

#define FTM_DEADTIME_DTPS_MASK                   (0xC0U)
#define FTM_DEADTIME_DTPS_SHIFT                  (6U)
/*! DTPS - Dead Time Prescaler Value
 *  0b0x..1
 *  0b10..4
 *  0b11..16
 */
#define FTM_DEADTIME_DTPS(x)                     (((uint32_t)(((uint32_t)(x)) << FTM_DEADTIME_DTPS_SHIFT)) & FTM_DEADTIME_DTPS_MASK)

#define FTM_DEADTIME_DTVALEX_MASK                (0xF0000U)
#define FTM_DEADTIME_DTVALEX_SHIFT               (16U)
/*! DTVALEX - Extended Dead Time Value */
#define FTM_DEADTIME_DTVALEX(x)                  (((uint32_t)(((uint32_t)(x)) << FTM_DEADTIME_DTVALEX_SHIFT)) & FTM_DEADTIME_DTVALEX_MASK)
/*! @} */

/*! @name EXTTRIG - FTM External Trigger */
/*! @{ */

#define FTM_EXTTRIG_CH0TRIG_MASK                 (0x10U)
#define FTM_EXTTRIG_CH0TRIG_SHIFT                (4U)
/*! CH0TRIG - Channel 0 External Trigger Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define FTM_EXTTRIG_CH0TRIG(x)                   (((uint32_t)(((uint32_t)(x)) << FTM_EXTTRIG_CH0TRIG_SHIFT)) & FTM_EXTTRIG_CH0TRIG_MASK)

#define FTM_EXTTRIG_CH1TRIG_MASK                 (0x20U)
#define FTM_EXTTRIG_CH1TRIG_SHIFT                (5U)
/*! CH1TRIG - Channel 1 External Trigger Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define FTM_EXTTRIG_CH1TRIG(x)                   (((uint32_t)(((uint32_t)(x)) << FTM_EXTTRIG_CH1TRIG_SHIFT)) & FTM_EXTTRIG_CH1TRIG_MASK)

#define FTM_EXTTRIG_INITTRIGEN_MASK              (0x40U)
#define FTM_EXTTRIG_INITTRIGEN_SHIFT             (6U)
/*! INITTRIGEN - Initialization Trigger Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define FTM_EXTTRIG_INITTRIGEN(x)                (((uint32_t)(((uint32_t)(x)) << FTM_EXTTRIG_INITTRIGEN_SHIFT)) & FTM_EXTTRIG_INITTRIGEN_MASK)

#define FTM_EXTTRIG_TRIGF_MASK                   (0x80U)
#define FTM_EXTTRIG_TRIGF_SHIFT                  (7U)
/*! TRIGF - Channel Trigger Flag
 *  0b0..No channel trigger generated
 *  0b1..Channel trigger generated
 */
#define FTM_EXTTRIG_TRIGF(x)                     (((uint32_t)(((uint32_t)(x)) << FTM_EXTTRIG_TRIGF_SHIFT)) & FTM_EXTTRIG_TRIGF_MASK)
/*! @} */

/*! @name POL - Channel Polarity */
/*! @{ */

#define FTM_POL_POL0_MASK                        (0x1U)
#define FTM_POL_POL0_SHIFT                       (0U)
/*! POL0 - Channel 0 Polarity
 *  0b0..Active high
 *  0b1..Active low
 */
#define FTM_POL_POL0(x)                          (((uint32_t)(((uint32_t)(x)) << FTM_POL_POL0_SHIFT)) & FTM_POL_POL0_MASK)

#define FTM_POL_POL1_MASK                        (0x2U)
#define FTM_POL_POL1_SHIFT                       (1U)
/*! POL1 - Channel 1 Polarity
 *  0b0..Active high
 *  0b1..Active low
 */
#define FTM_POL_POL1(x)                          (((uint32_t)(((uint32_t)(x)) << FTM_POL_POL1_SHIFT)) & FTM_POL_POL1_MASK)
/*! @} */

/*! @name FMS - Fault Mode Status */
/*! @{ */

#define FTM_FMS_WPEN_MASK                        (0x40U)
#define FTM_FMS_WPEN_SHIFT                       (6U)
/*! WPEN - Write Protection Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define FTM_FMS_WPEN(x)                          (((uint32_t)(((uint32_t)(x)) << FTM_FMS_WPEN_SHIFT)) & FTM_FMS_WPEN_MASK)
/*! @} */

/*! @name FILTER - Input Capture Filter Control */
/*! @{ */

#define FTM_FILTER_CH0FVAL_MASK                  (0xFU)
#define FTM_FILTER_CH0FVAL_SHIFT                 (0U)
/*! CH0FVAL - Channel 0 Input Filter */
#define FTM_FILTER_CH0FVAL(x)                    (((uint32_t)(((uint32_t)(x)) << FTM_FILTER_CH0FVAL_SHIFT)) & FTM_FILTER_CH0FVAL_MASK)

#define FTM_FILTER_CH1FVAL_MASK                  (0xF0U)
#define FTM_FILTER_CH1FVAL_SHIFT                 (4U)
/*! CH1FVAL - Channel 1 Input Filter */
#define FTM_FILTER_CH1FVAL(x)                    (((uint32_t)(((uint32_t)(x)) << FTM_FILTER_CH1FVAL_SHIFT)) & FTM_FILTER_CH1FVAL_MASK)
/*! @} */

/*! @name CONF - Configuration */
/*! @{ */

#define FTM_CONF_LDFQ_MASK                       (0x1FU)
#define FTM_CONF_LDFQ_SHIFT                      (0U)
/*! LDFQ - Frequency of Reload Opportunities */
#define FTM_CONF_LDFQ(x)                         (((uint32_t)(((uint32_t)(x)) << FTM_CONF_LDFQ_SHIFT)) & FTM_CONF_LDFQ_MASK)

#define FTM_CONF_BDMMODE_MASK                    (0xC0U)
#define FTM_CONF_BDMMODE_SHIFT                   (6U)
/*! BDMMODE - BDM Mode */
#define FTM_CONF_BDMMODE(x)                      (((uint32_t)(((uint32_t)(x)) << FTM_CONF_BDMMODE_SHIFT)) & FTM_CONF_BDMMODE_MASK)

#define FTM_CONF_GTBEEN_MASK                     (0x200U)
#define FTM_CONF_GTBEEN_SHIFT                    (9U)
/*! GTBEEN - Global Timebase Enable */
#define FTM_CONF_GTBEEN(x)                       (((uint32_t)(((uint32_t)(x)) << FTM_CONF_GTBEEN_SHIFT)) & FTM_CONF_GTBEEN_MASK)

#define FTM_CONF_GTBEOUT_MASK                    (0x400U)
#define FTM_CONF_GTBEOUT_SHIFT                   (10U)
/*! GTBEOUT - Global Timebase Output */
#define FTM_CONF_GTBEOUT(x)                      (((uint32_t)(((uint32_t)(x)) << FTM_CONF_GTBEOUT_SHIFT)) & FTM_CONF_GTBEOUT_MASK)

#define FTM_CONF_ITRIGR_MASK                     (0x800U)
#define FTM_CONF_ITRIGR_SHIFT                    (11U)
/*! ITRIGR - Initialization Trigger on Reload Point
 *  0b0..After counter wrap events
 *  0b1..When a reload point is reached
 */
#define FTM_CONF_ITRIGR(x)                       (((uint32_t)(((uint32_t)(x)) << FTM_CONF_ITRIGR_SHIFT)) & FTM_CONF_ITRIGR_MASK)
/*! @} */

/*! @name SYNCONF - Synchronization Configuration */
/*! @{ */

#define FTM_SYNCONF_HWTRIGMODE_MASK              (0x1U)
#define FTM_SYNCONF_HWTRIGMODE_SHIFT             (0U)
/*! HWTRIGMODE - Hardware Trigger Mode
 *  0b0..Enable
 *  0b1..Disable
 */
#define FTM_SYNCONF_HWTRIGMODE(x)                (((uint32_t)(((uint32_t)(x)) << FTM_SYNCONF_HWTRIGMODE_SHIFT)) & FTM_SYNCONF_HWTRIGMODE_MASK)

#define FTM_SYNCONF_CNTINC_MASK                  (0x4U)
#define FTM_SYNCONF_CNTINC_SHIFT                 (2U)
/*! CNTINC - CNTIN Register Synchronization
 *  0b0..At all rising edges of the FTM input clock
 *  0b1..When PWM synchronization occurs
 */
#define FTM_SYNCONF_CNTINC(x)                    (((uint32_t)(((uint32_t)(x)) << FTM_SYNCONF_CNTINC_SHIFT)) & FTM_SYNCONF_CNTINC_MASK)

#define FTM_SYNCONF_INVC_MASK                    (0x10U)
#define FTM_SYNCONF_INVC_SHIFT                   (4U)
/*! INVC - INVCTRL Register Synchronization
 *  0b0..At all rising edges of the FTM input clock
 *  0b1..When PWM synchronization occurs
 */
#define FTM_SYNCONF_INVC(x)                      (((uint32_t)(((uint32_t)(x)) << FTM_SYNCONF_INVC_SHIFT)) & FTM_SYNCONF_INVC_MASK)

#define FTM_SYNCONF_SWOC_MASK                    (0x20U)
#define FTM_SYNCONF_SWOC_SHIFT                   (5U)
/*! SWOC - SWOCTRL Register Synchronization
 *  0b0..At all rising edges of the FTM input clock
 *  0b1..When PWM synchronization occurs
 */
#define FTM_SYNCONF_SWOC(x)                      (((uint32_t)(((uint32_t)(x)) << FTM_SYNCONF_SWOC_SHIFT)) & FTM_SYNCONF_SWOC_MASK)

#define FTM_SYNCONF_SYNCMODE_MASK                (0x80U)
#define FTM_SYNCONF_SYNCMODE_SHIFT               (7U)
/*! SYNCMODE - Synchronization Mode
 *  0b0..Legacy PWM
 *  0b1..Enhanced PWM
 */
#define FTM_SYNCONF_SYNCMODE(x)                  (((uint32_t)(((uint32_t)(x)) << FTM_SYNCONF_SYNCMODE_SHIFT)) & FTM_SYNCONF_SYNCMODE_MASK)

#define FTM_SYNCONF_SWRSTCNT_MASK                (0x100U)
#define FTM_SYNCONF_SWRSTCNT_SHIFT               (8U)
/*! SWRSTCNT - Software Trigger Counter Synchronization
 *  0b0..Does not activate
 *  0b1..Activates
 */
#define FTM_SYNCONF_SWRSTCNT(x)                  (((uint32_t)(((uint32_t)(x)) << FTM_SYNCONF_SWRSTCNT_SHIFT)) & FTM_SYNCONF_SWRSTCNT_MASK)

#define FTM_SYNCONF_SWWRBUF_MASK                 (0x200U)
#define FTM_SYNCONF_SWWRBUF_SHIFT                (9U)
/*! SWWRBUF - Software Trigger Register Synchronization
 *  0b0..Does not activate
 *  0b1..Activates
 */
#define FTM_SYNCONF_SWWRBUF(x)                   (((uint32_t)(((uint32_t)(x)) << FTM_SYNCONF_SWWRBUF_SHIFT)) & FTM_SYNCONF_SWWRBUF_MASK)

#define FTM_SYNCONF_SWOM_MASK                    (0x400U)
#define FTM_SYNCONF_SWOM_SHIFT                   (10U)
/*! SWOM - Software Trigger Output Mask
 *  0b0..Does not activate
 *  0b1..Activates
 */
#define FTM_SYNCONF_SWOM(x)                      (((uint32_t)(((uint32_t)(x)) << FTM_SYNCONF_SWOM_SHIFT)) & FTM_SYNCONF_SWOM_MASK)

#define FTM_SYNCONF_SWINVC_MASK                  (0x800U)
#define FTM_SYNCONF_SWINVC_SHIFT                 (11U)
/*! SWINVC - Software Trigger Inverting Control Synchronization
 *  0b0..Does not activate
 *  0b1..Activates
 */
#define FTM_SYNCONF_SWINVC(x)                    (((uint32_t)(((uint32_t)(x)) << FTM_SYNCONF_SWINVC_SHIFT)) & FTM_SYNCONF_SWINVC_MASK)

#define FTM_SYNCONF_SWSOC_MASK                   (0x1000U)
#define FTM_SYNCONF_SWSOC_SHIFT                  (12U)
/*! SWSOC - Software Trigger Output Control Synchronization
 *  0b0..Does not activate
 *  0b1..Activates
 */
#define FTM_SYNCONF_SWSOC(x)                     (((uint32_t)(((uint32_t)(x)) << FTM_SYNCONF_SWSOC_SHIFT)) & FTM_SYNCONF_SWSOC_MASK)

#define FTM_SYNCONF_HWRSTCNT_MASK                (0x10000U)
#define FTM_SYNCONF_HWRSTCNT_SHIFT               (16U)
/*! HWRSTCNT - Hardware Trigger Counter Synchronization
 *  0b0..Does not activate
 *  0b1..Activates
 */
#define FTM_SYNCONF_HWRSTCNT(x)                  (((uint32_t)(((uint32_t)(x)) << FTM_SYNCONF_HWRSTCNT_SHIFT)) & FTM_SYNCONF_HWRSTCNT_MASK)

#define FTM_SYNCONF_HWWRBUF_MASK                 (0x20000U)
#define FTM_SYNCONF_HWWRBUF_SHIFT                (17U)
/*! HWWRBUF - Hardware Trigger Register Synchronization
 *  0b0..Does not activate
 *  0b1..Activates
 */
#define FTM_SYNCONF_HWWRBUF(x)                   (((uint32_t)(((uint32_t)(x)) << FTM_SYNCONF_HWWRBUF_SHIFT)) & FTM_SYNCONF_HWWRBUF_MASK)

#define FTM_SYNCONF_HWOM_MASK                    (0x40000U)
#define FTM_SYNCONF_HWOM_SHIFT                   (18U)
/*! HWOM - Hardware Trigger Output Mask
 *  0b0..Does not activate
 *  0b1..Activates
 */
#define FTM_SYNCONF_HWOM(x)                      (((uint32_t)(((uint32_t)(x)) << FTM_SYNCONF_HWOM_SHIFT)) & FTM_SYNCONF_HWOM_MASK)

#define FTM_SYNCONF_HWINVC_MASK                  (0x80000U)
#define FTM_SYNCONF_HWINVC_SHIFT                 (19U)
/*! HWINVC - Hardware Trigger Inverting Control Synchronization
 *  0b0..Does not activate
 *  0b1..Activates
 */
#define FTM_SYNCONF_HWINVC(x)                    (((uint32_t)(((uint32_t)(x)) << FTM_SYNCONF_HWINVC_SHIFT)) & FTM_SYNCONF_HWINVC_MASK)

#define FTM_SYNCONF_HWSOC_MASK                   (0x100000U)
#define FTM_SYNCONF_HWSOC_SHIFT                  (20U)
/*! HWSOC - Hardware Trigger Software Output Control Synchronization
 *  0b0..Does not activate
 *  0b1..Activates
 */
#define FTM_SYNCONF_HWSOC(x)                     (((uint32_t)(((uint32_t)(x)) << FTM_SYNCONF_HWSOC_SHIFT)) & FTM_SYNCONF_HWSOC_MASK)
/*! @} */

/*! @name INVCTRL - FTM Inverting Control */
/*! @{ */

#define FTM_INVCTRL_INV0EN_MASK                  (0x1U)
#define FTM_INVCTRL_INV0EN_SHIFT                 (0U)
/*! INV0EN - Channel Pair 0 Inversion Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define FTM_INVCTRL_INV0EN(x)                    (((uint32_t)(((uint32_t)(x)) << FTM_INVCTRL_INV0EN_SHIFT)) & FTM_INVCTRL_INV0EN_MASK)
/*! @} */

/*! @name SWOCTRL - FTM Software Output Control */
/*! @{ */

#define FTM_SWOCTRL_CH0OC_MASK                   (0x1U)
#define FTM_SWOCTRL_CH0OC_SHIFT                  (0U)
/*! CH0OC - Channel 0 Software Output Control Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define FTM_SWOCTRL_CH0OC(x)                     (((uint32_t)(((uint32_t)(x)) << FTM_SWOCTRL_CH0OC_SHIFT)) & FTM_SWOCTRL_CH0OC_MASK)

#define FTM_SWOCTRL_CH1OC_MASK                   (0x2U)
#define FTM_SWOCTRL_CH1OC_SHIFT                  (1U)
/*! CH1OC - Channel 1 Software Output Control Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define FTM_SWOCTRL_CH1OC(x)                     (((uint32_t)(((uint32_t)(x)) << FTM_SWOCTRL_CH1OC_SHIFT)) & FTM_SWOCTRL_CH1OC_MASK)

#define FTM_SWOCTRL_CH0OCV_MASK                  (0x100U)
#define FTM_SWOCTRL_CH0OCV_SHIFT                 (8U)
/*! CH0OCV - Channel 0 Software Output Control Value
 *  0b0..0
 *  0b1..1
 */
#define FTM_SWOCTRL_CH0OCV(x)                    (((uint32_t)(((uint32_t)(x)) << FTM_SWOCTRL_CH0OCV_SHIFT)) & FTM_SWOCTRL_CH0OCV_MASK)

#define FTM_SWOCTRL_CH1OCV_MASK                  (0x200U)
#define FTM_SWOCTRL_CH1OCV_SHIFT                 (9U)
/*! CH1OCV - Channel 1 Software Output Control Value
 *  0b0..0
 *  0b1..1
 */
#define FTM_SWOCTRL_CH1OCV(x)                    (((uint32_t)(((uint32_t)(x)) << FTM_SWOCTRL_CH1OCV_SHIFT)) & FTM_SWOCTRL_CH1OCV_MASK)
/*! @} */

/*! @name PWMLOAD - FTM PWM Load */
/*! @{ */

#define FTM_PWMLOAD_CH0SEL_MASK                  (0x1U)
#define FTM_PWMLOAD_CH0SEL_SHIFT                 (0U)
/*! CH0SEL - Channel 0 Select
 *  0b0..Not a reload opportunity
 *  0b1..Reload opportunity
 */
#define FTM_PWMLOAD_CH0SEL(x)                    (((uint32_t)(((uint32_t)(x)) << FTM_PWMLOAD_CH0SEL_SHIFT)) & FTM_PWMLOAD_CH0SEL_MASK)

#define FTM_PWMLOAD_CH1SEL_MASK                  (0x2U)
#define FTM_PWMLOAD_CH1SEL_SHIFT                 (1U)
/*! CH1SEL - Channel 1 Select
 *  0b0..Not a reload opportunity
 *  0b1..Reload opportunity
 */
#define FTM_PWMLOAD_CH1SEL(x)                    (((uint32_t)(((uint32_t)(x)) << FTM_PWMLOAD_CH1SEL_SHIFT)) & FTM_PWMLOAD_CH1SEL_MASK)

#define FTM_PWMLOAD_HCSEL_MASK                   (0x100U)
#define FTM_PWMLOAD_HCSEL_SHIFT                  (8U)
/*! HCSEL - Half-Cycle Select
 *  0b0..Disable
 *  0b1..Enable
 */
#define FTM_PWMLOAD_HCSEL(x)                     (((uint32_t)(((uint32_t)(x)) << FTM_PWMLOAD_HCSEL_SHIFT)) & FTM_PWMLOAD_HCSEL_MASK)

#define FTM_PWMLOAD_LDOK_MASK                    (0x200U)
#define FTM_PWMLOAD_LDOK_SHIFT                   (9U)
/*! LDOK - Load Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define FTM_PWMLOAD_LDOK(x)                      (((uint32_t)(((uint32_t)(x)) << FTM_PWMLOAD_LDOK_SHIFT)) & FTM_PWMLOAD_LDOK_MASK)

#define FTM_PWMLOAD_GLEN_MASK                    (0x400U)
#define FTM_PWMLOAD_GLEN_SHIFT                   (10U)
/*! GLEN - Global Load Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define FTM_PWMLOAD_GLEN(x)                      (((uint32_t)(((uint32_t)(x)) << FTM_PWMLOAD_GLEN_SHIFT)) & FTM_PWMLOAD_GLEN_MASK)

#define FTM_PWMLOAD_GLDOK_MASK                   (0x800U)
#define FTM_PWMLOAD_GLDOK_SHIFT                  (11U)
/*! GLDOK - Global Load OK
 *  0b0..No action
 *  0b1..Causes LDOK to become 1
 */
#define FTM_PWMLOAD_GLDOK(x)                     (((uint32_t)(((uint32_t)(x)) << FTM_PWMLOAD_GLDOK_SHIFT)) & FTM_PWMLOAD_GLDOK_MASK)
/*! @} */

/*! @name HCR - Half-Cycle Reload */
/*! @{ */

#define FTM_HCR_HCVAL_MASK                       (0xFFFFU)
#define FTM_HCR_HCVAL_SHIFT                      (0U)
/*! HCVAL - Half-Cycle Value */
#define FTM_HCR_HCVAL(x)                         (((uint32_t)(((uint32_t)(x)) << FTM_HCR_HCVAL_SHIFT)) & FTM_HCR_HCVAL_MASK)
/*! @} */

/*! @name MOD_MIRROR - Mirror of Modulo Value */
/*! @{ */

#define FTM_MOD_MIRROR_FRACMOD_MASK              (0xF800U)
#define FTM_MOD_MIRROR_FRACMOD_SHIFT             (11U)
/*! FRACMOD - Modulo Fractional Value */
#define FTM_MOD_MIRROR_FRACMOD(x)                (((uint32_t)(((uint32_t)(x)) << FTM_MOD_MIRROR_FRACMOD_SHIFT)) & FTM_MOD_MIRROR_FRACMOD_MASK)

#define FTM_MOD_MIRROR_MOD_MASK                  (0xFFFF0000U)
#define FTM_MOD_MIRROR_MOD_SHIFT                 (16U)
/*! MOD - Mirror of the Modulo Integer Value */
#define FTM_MOD_MIRROR_MOD(x)                    (((uint32_t)(((uint32_t)(x)) << FTM_MOD_MIRROR_MOD_SHIFT)) & FTM_MOD_MIRROR_MOD_MASK)
/*! @} */

/*! @name CV_MIRROR - Mirror of Channel n Match Value */
/*! @{ */

#define FTM_CV_MIRROR_FRACVAL_MASK               (0xF800U)
#define FTM_CV_MIRROR_FRACVAL_SHIFT              (11U)
/*! FRACVAL - Channel n Match Fractional Value */
#define FTM_CV_MIRROR_FRACVAL(x)                 (((uint32_t)(((uint32_t)(x)) << FTM_CV_MIRROR_FRACVAL_SHIFT)) & FTM_CV_MIRROR_FRACVAL_MASK)

#define FTM_CV_MIRROR_VAL_MASK                   (0xFFFF0000U)
#define FTM_CV_MIRROR_VAL_SHIFT                  (16U)
/*! VAL - Mirror of the Channel n Match Integer Value */
#define FTM_CV_MIRROR_VAL(x)                     (((uint32_t)(((uint32_t)(x)) << FTM_CV_MIRROR_VAL_SHIFT)) & FTM_CV_MIRROR_VAL_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group FTM_Register_Masks */


/*!
 * @}
 */ /* end of group FTM_Peripheral_Access_Layer */


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


#endif  /* PERI_FTM_H_ */

