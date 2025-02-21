/*
** ###################################################################
**     Processors:          MKW21Z256VHT4
**                          MKW21Z512VHT4
**                          MKW31Z256VHT4
**                          MKW31Z512CAT4
**                          MKW31Z512VHT4
**                          MKW41Z256VHT4
**                          MKW41Z512CAT4
**                          MKW41Z512VHT4
**
**     Version:             rev. 1.0, 2015-09-23
**     Build:               b240710
**
**     Abstract:
**         CMSIS Peripheral Access Layer for XCVR_TSM
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2015-09-23)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file XCVR_TSM.h
 * @version 1.0
 * @date 2015-09-23
 * @brief CMSIS Peripheral Access Layer for XCVR_TSM
 *
 * CMSIS Peripheral Access Layer for XCVR_TSM
 */

#if !defined(XCVR_TSM_H_)
#define XCVR_TSM_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MKW21Z256VHT4) || defined(CPU_MKW21Z512VHT4))
#include "MKW21Z4_COMMON.h"
#elif (defined(CPU_MKW31Z256VHT4) || defined(CPU_MKW31Z512CAT4) || defined(CPU_MKW31Z512VHT4))
#include "MKW31Z4_COMMON.h"
#elif (defined(CPU_MKW41Z256VHT4) || defined(CPU_MKW41Z512CAT4) || defined(CPU_MKW41Z512VHT4))
#include "MKW41Z4_COMMON.h"
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
   -- XCVR_TSM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XCVR_TSM_Peripheral_Access_Layer XCVR_TSM Peripheral Access Layer
 * @{
 */

/** XCVR_TSM - Register Layout Typedef */
typedef struct {
  __IO uint32_t CTRL;                              /**< TRANSCEIVER SEQUENCE MANAGER CONTROL, offset: 0x0 */
  __IO uint32_t END_OF_SEQ;                        /**< TSM END OF SEQUENCE, offset: 0x4 */
  __IO uint32_t OVRD0;                             /**< TSM OVERRIDE REGISTER 0, offset: 0x8 */
  __IO uint32_t OVRD1;                             /**< TSM OVERRIDE REGISTER 1, offset: 0xC */
  __IO uint32_t OVRD2;                             /**< TSM OVERRIDE REGISTER 2, offset: 0x10 */
  __IO uint32_t OVRD3;                             /**< TSM OVERRIDE REGISTER 3, offset: 0x14 */
  __IO uint32_t PA_POWER;                          /**< PA POWER, offset: 0x18 */
  __IO uint32_t PA_RAMP_TBL0;                      /**< PA RAMP TABLE 0, offset: 0x1C */
  __IO uint32_t PA_RAMP_TBL1;                      /**< PA RAMP TABLE 1, offset: 0x20 */
  __IO uint32_t RECYCLE_COUNT;                     /**< TSM RECYCLE COUNT, offset: 0x24 */
  __IO uint32_t FAST_CTRL1;                        /**< TSM FAST WARMUP CONTROL REGISTER 1, offset: 0x28 */
  __IO uint32_t FAST_CTRL2;                        /**< TSM FAST WARMUP CONTROL REGISTER 2, offset: 0x2C */
  __IO uint32_t TIMING00;                          /**< TSM_TIMING00, offset: 0x30 */
  __IO uint32_t TIMING01;                          /**< TSM_TIMING01, offset: 0x34 */
  __IO uint32_t TIMING02;                          /**< TSM_TIMING02, offset: 0x38 */
  __IO uint32_t TIMING03;                          /**< TSM_TIMING03, offset: 0x3C */
  __IO uint32_t TIMING04;                          /**< TSM_TIMING04, offset: 0x40 */
  __IO uint32_t TIMING05;                          /**< TSM_TIMING05, offset: 0x44 */
  __IO uint32_t TIMING06;                          /**< TSM_TIMING06, offset: 0x48 */
  __IO uint32_t TIMING07;                          /**< TSM_TIMING07, offset: 0x4C */
  __IO uint32_t TIMING08;                          /**< TSM_TIMING08, offset: 0x50 */
  __IO uint32_t TIMING09;                          /**< TSM_TIMING09, offset: 0x54 */
  __IO uint32_t TIMING10;                          /**< TSM_TIMING10, offset: 0x58 */
  __IO uint32_t TIMING11;                          /**< TSM_TIMING11, offset: 0x5C */
  __IO uint32_t TIMING12;                          /**< TSM_TIMING12, offset: 0x60 */
  __IO uint32_t TIMING13;                          /**< TSM_TIMING13, offset: 0x64 */
  __IO uint32_t TIMING14;                          /**< TSM_TIMING14, offset: 0x68 */
  __IO uint32_t TIMING15;                          /**< TSM_TIMING15, offset: 0x6C */
  __IO uint32_t TIMING16;                          /**< TSM_TIMING16, offset: 0x70 */
  __IO uint32_t TIMING17;                          /**< TSM_TIMING17, offset: 0x74 */
  __IO uint32_t TIMING18;                          /**< TSM_TIMING18, offset: 0x78 */
  __IO uint32_t TIMING19;                          /**< TSM_TIMING19, offset: 0x7C */
  __IO uint32_t TIMING20;                          /**< TSM_TIMING20, offset: 0x80 */
  __IO uint32_t TIMING21;                          /**< TSM_TIMING21, offset: 0x84 */
  __IO uint32_t TIMING22;                          /**< TSM_TIMING22, offset: 0x88 */
  __IO uint32_t TIMING23;                          /**< TSM_TIMING23, offset: 0x8C */
  __IO uint32_t TIMING24;                          /**< TSM_TIMING24, offset: 0x90 */
  __IO uint32_t TIMING25;                          /**< TSM_TIMING25, offset: 0x94 */
  __IO uint32_t TIMING26;                          /**< TSM_TIMING26, offset: 0x98 */
  __IO uint32_t TIMING27;                          /**< TSM_TIMING27, offset: 0x9C */
  __IO uint32_t TIMING28;                          /**< TSM_TIMING28, offset: 0xA0 */
  __IO uint32_t TIMING29;                          /**< TSM_TIMING29, offset: 0xA4 */
  __IO uint32_t TIMING30;                          /**< TSM_TIMING30, offset: 0xA8 */
  __IO uint32_t TIMING31;                          /**< TSM_TIMING31, offset: 0xAC */
  __IO uint32_t TIMING32;                          /**< TSM_TIMING32, offset: 0xB0 */
  __IO uint32_t TIMING33;                          /**< TSM_TIMING33, offset: 0xB4 */
  __IO uint32_t TIMING34;                          /**< TSM_TIMING34, offset: 0xB8 */
  __IO uint32_t TIMING35;                          /**< TSM_TIMING35, offset: 0xBC */
  __IO uint32_t TIMING36;                          /**< TSM_TIMING36, offset: 0xC0 */
  __IO uint32_t TIMING37;                          /**< TSM_TIMING37, offset: 0xC4 */
  __IO uint32_t TIMING38;                          /**< TSM_TIMING38, offset: 0xC8 */
  __IO uint32_t TIMING39;                          /**< TSM_TIMING39, offset: 0xCC */
  __IO uint32_t TIMING40;                          /**< TSM_TIMING40, offset: 0xD0 */
  __IO uint32_t TIMING41;                          /**< TSM_TIMING41, offset: 0xD4 */
  __IO uint32_t TIMING42;                          /**< TSM_TIMING42, offset: 0xD8 */
  __IO uint32_t TIMING43;                          /**< TSM_TIMING43, offset: 0xDC */
  __IO uint32_t TIMING44;                          /**< TSM_TIMING44, offset: 0xE0 */
  __IO uint32_t TIMING45;                          /**< TSM_TIMING45, offset: 0xE4 */
  __IO uint32_t TIMING46;                          /**< TSM_TIMING46, offset: 0xE8 */
  __IO uint32_t TIMING47;                          /**< TSM_TIMING47, offset: 0xEC */
  __IO uint32_t TIMING48;                          /**< TSM_TIMING48, offset: 0xF0 */
  __IO uint32_t TIMING49;                          /**< TSM_TIMING49, offset: 0xF4 */
  __IO uint32_t TIMING50;                          /**< TSM_TIMING50, offset: 0xF8 */
  __IO uint32_t TIMING51;                          /**< TSM_TIMING51, offset: 0xFC */
  __IO uint32_t TIMING52;                          /**< TSM_TIMING52, offset: 0x100 */
  __IO uint32_t TIMING53;                          /**< TSM_TIMING53, offset: 0x104 */
  __IO uint32_t TIMING54;                          /**< TSM_TIMING54, offset: 0x108 */
  __IO uint32_t TIMING55;                          /**< TSM_TIMING55, offset: 0x10C */
  __IO uint32_t TIMING56;                          /**< TSM_TIMING56, offset: 0x110 */
  __IO uint32_t TIMING57;                          /**< TSM_TIMING57, offset: 0x114 */
  __IO uint32_t TIMING58;                          /**< TSM_TIMING58, offset: 0x118 */
} XCVR_TSM_Type;

/* ----------------------------------------------------------------------------
   -- XCVR_TSM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XCVR_TSM_Register_Masks XCVR_TSM Register Masks
 * @{
 */

/*! @name CTRL - TRANSCEIVER SEQUENCE MANAGER CONTROL */
/*! @{ */

#define XCVR_TSM_CTRL_FORCE_TX_EN_MASK           (0x4U)
#define XCVR_TSM_CTRL_FORCE_TX_EN_SHIFT          (2U)
/*! FORCE_TX_EN - Force Transmit Enable
 *  0b0..TSM Idle
 *  0b1..TSM executes a TX sequence
 */
#define XCVR_TSM_CTRL_FORCE_TX_EN(x)             (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_CTRL_FORCE_TX_EN_SHIFT)) & XCVR_TSM_CTRL_FORCE_TX_EN_MASK)

#define XCVR_TSM_CTRL_FORCE_RX_EN_MASK           (0x8U)
#define XCVR_TSM_CTRL_FORCE_RX_EN_SHIFT          (3U)
/*! FORCE_RX_EN - Force Receive Enable
 *  0b0..TSM Idle
 *  0b1..TSM executes a RX sequence
 */
#define XCVR_TSM_CTRL_FORCE_RX_EN(x)             (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_CTRL_FORCE_RX_EN_SHIFT)) & XCVR_TSM_CTRL_FORCE_RX_EN_MASK)

#define XCVR_TSM_CTRL_PA_RAMP_SEL_MASK           (0x30U)
#define XCVR_TSM_CTRL_PA_RAMP_SEL_SHIFT          (4U)
/*! PA_RAMP_SEL - PA Ramp Selection */
#define XCVR_TSM_CTRL_PA_RAMP_SEL(x)             (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_CTRL_PA_RAMP_SEL_SHIFT)) & XCVR_TSM_CTRL_PA_RAMP_SEL_MASK)

#define XCVR_TSM_CTRL_DATA_PADDING_EN_MASK       (0xC0U)
#define XCVR_TSM_CTRL_DATA_PADDING_EN_SHIFT      (6U)
/*! DATA_PADDING_EN - Data Padding Enable
 *  0b00..Disable TX Data Padding
 *  0b01..Enable TX Data Padding
 */
#define XCVR_TSM_CTRL_DATA_PADDING_EN(x)         (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_CTRL_DATA_PADDING_EN_SHIFT)) & XCVR_TSM_CTRL_DATA_PADDING_EN_MASK)

#define XCVR_TSM_CTRL_TSM_IRQ0_EN_MASK           (0x100U)
#define XCVR_TSM_CTRL_TSM_IRQ0_EN_SHIFT          (8U)
/*! TSM_IRQ0_EN - TSM_IRQ0 Enable/Disable bit
 *  0b0..TSM_IRQ0 is disabled
 *  0b1..TSM_IRQ0 is enabled
 */
#define XCVR_TSM_CTRL_TSM_IRQ0_EN(x)             (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_CTRL_TSM_IRQ0_EN_SHIFT)) & XCVR_TSM_CTRL_TSM_IRQ0_EN_MASK)

#define XCVR_TSM_CTRL_TSM_IRQ1_EN_MASK           (0x200U)
#define XCVR_TSM_CTRL_TSM_IRQ1_EN_SHIFT          (9U)
/*! TSM_IRQ1_EN - TSM_IRQ1 Enable/Disable bit
 *  0b0..TSM_IRQ1 is disabled
 *  0b1..TSM_IRQ1 is enabled
 */
#define XCVR_TSM_CTRL_TSM_IRQ1_EN(x)             (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_CTRL_TSM_IRQ1_EN_SHIFT)) & XCVR_TSM_CTRL_TSM_IRQ1_EN_MASK)

#define XCVR_TSM_CTRL_RAMP_DN_DELAY_MASK         (0xF000U)
#define XCVR_TSM_CTRL_RAMP_DN_DELAY_SHIFT        (12U)
/*! RAMP_DN_DELAY - PA Ramp Down Delay */
#define XCVR_TSM_CTRL_RAMP_DN_DELAY(x)           (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_CTRL_RAMP_DN_DELAY_SHIFT)) & XCVR_TSM_CTRL_RAMP_DN_DELAY_MASK)

#define XCVR_TSM_CTRL_TX_ABORT_DIS_MASK          (0x10000U)
#define XCVR_TSM_CTRL_TX_ABORT_DIS_SHIFT         (16U)
/*! TX_ABORT_DIS - Transmit Abort Disable */
#define XCVR_TSM_CTRL_TX_ABORT_DIS(x)            (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_CTRL_TX_ABORT_DIS_SHIFT)) & XCVR_TSM_CTRL_TX_ABORT_DIS_MASK)

#define XCVR_TSM_CTRL_RX_ABORT_DIS_MASK          (0x20000U)
#define XCVR_TSM_CTRL_RX_ABORT_DIS_SHIFT         (17U)
/*! RX_ABORT_DIS - Receive Abort Disable */
#define XCVR_TSM_CTRL_RX_ABORT_DIS(x)            (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_CTRL_RX_ABORT_DIS_SHIFT)) & XCVR_TSM_CTRL_RX_ABORT_DIS_MASK)

#define XCVR_TSM_CTRL_ABORT_ON_CTUNE_MASK        (0x40000U)
#define XCVR_TSM_CTRL_ABORT_ON_CTUNE_SHIFT       (18U)
/*! ABORT_ON_CTUNE - Abort On Coarse Tune Lock Detect Failure
 *  0b0..don't allow TSM abort on Coarse Tune Unlock Detect
 *  0b1..allow TSM abort on Coarse Tune Unlock Detect
 */
#define XCVR_TSM_CTRL_ABORT_ON_CTUNE(x)          (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_CTRL_ABORT_ON_CTUNE_SHIFT)) & XCVR_TSM_CTRL_ABORT_ON_CTUNE_MASK)

#define XCVR_TSM_CTRL_ABORT_ON_CYCLE_SLIP_MASK   (0x80000U)
#define XCVR_TSM_CTRL_ABORT_ON_CYCLE_SLIP_SHIFT  (19U)
/*! ABORT_ON_CYCLE_SLIP - Abort On Cycle Slip Lock Detect Failure
 *  0b0..don't allow TSM abort on Cycle Slip Unlock Detect
 *  0b1..allow TSM abort on Cycle Slip Unlock Detect
 */
#define XCVR_TSM_CTRL_ABORT_ON_CYCLE_SLIP(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_CTRL_ABORT_ON_CYCLE_SLIP_SHIFT)) & XCVR_TSM_CTRL_ABORT_ON_CYCLE_SLIP_MASK)

#define XCVR_TSM_CTRL_ABORT_ON_FREQ_TARG_MASK    (0x100000U)
#define XCVR_TSM_CTRL_ABORT_ON_FREQ_TARG_SHIFT   (20U)
/*! ABORT_ON_FREQ_TARG - Abort On Frequency Target Lock Detect Failure
 *  0b0..don't allow TSM abort on Frequency Target Unlock Detect
 *  0b1..allow TSM abort on Frequency Target Unlock Detect
 */
#define XCVR_TSM_CTRL_ABORT_ON_FREQ_TARG(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_CTRL_ABORT_ON_FREQ_TARG_SHIFT)) & XCVR_TSM_CTRL_ABORT_ON_FREQ_TARG_MASK)

#define XCVR_TSM_CTRL_BKPT_MASK                  (0xFF000000U)
#define XCVR_TSM_CTRL_BKPT_SHIFT                 (24U)
/*! BKPT - TSM Breakpoint */
#define XCVR_TSM_CTRL_BKPT(x)                    (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_CTRL_BKPT_SHIFT)) & XCVR_TSM_CTRL_BKPT_MASK)
/*! @} */

/*! @name END_OF_SEQ - TSM END OF SEQUENCE */
/*! @{ */

#define XCVR_TSM_END_OF_SEQ_END_OF_TX_WU_MASK    (0xFFU)
#define XCVR_TSM_END_OF_SEQ_END_OF_TX_WU_SHIFT   (0U)
/*! END_OF_TX_WU - End of TX Warmup */
#define XCVR_TSM_END_OF_SEQ_END_OF_TX_WU(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_END_OF_SEQ_END_OF_TX_WU_SHIFT)) & XCVR_TSM_END_OF_SEQ_END_OF_TX_WU_MASK)

#define XCVR_TSM_END_OF_SEQ_END_OF_TX_WD_MASK    (0xFF00U)
#define XCVR_TSM_END_OF_SEQ_END_OF_TX_WD_SHIFT   (8U)
/*! END_OF_TX_WD - End of TX Warmdown */
#define XCVR_TSM_END_OF_SEQ_END_OF_TX_WD(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_END_OF_SEQ_END_OF_TX_WD_SHIFT)) & XCVR_TSM_END_OF_SEQ_END_OF_TX_WD_MASK)

#define XCVR_TSM_END_OF_SEQ_END_OF_RX_WU_MASK    (0xFF0000U)
#define XCVR_TSM_END_OF_SEQ_END_OF_RX_WU_SHIFT   (16U)
/*! END_OF_RX_WU - End of RX Warmup */
#define XCVR_TSM_END_OF_SEQ_END_OF_RX_WU(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_END_OF_SEQ_END_OF_RX_WU_SHIFT)) & XCVR_TSM_END_OF_SEQ_END_OF_RX_WU_MASK)

#define XCVR_TSM_END_OF_SEQ_END_OF_RX_WD_MASK    (0xFF000000U)
#define XCVR_TSM_END_OF_SEQ_END_OF_RX_WD_SHIFT   (24U)
/*! END_OF_RX_WD - End of RX Warmdown */
#define XCVR_TSM_END_OF_SEQ_END_OF_RX_WD(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_END_OF_SEQ_END_OF_RX_WD_SHIFT)) & XCVR_TSM_END_OF_SEQ_END_OF_RX_WD_MASK)
/*! @} */

/*! @name OVRD0 - TSM OVERRIDE REGISTER 0 */
/*! @{ */

#define XCVR_TSM_OVRD0_BB_LDO_HF_EN_OVRD_EN_MASK (0x1U)
#define XCVR_TSM_OVRD0_BB_LDO_HF_EN_OVRD_EN_SHIFT (0U)
/*! BB_LDO_HF_EN_OVRD_EN - Override control for BB_LDO_HF_EN
 *  0b0..Normal operation.
 *  0b1..Use the state of BB_LDO_HF_EN_OVRD to override the signal "bb_ldo_hf_en".
 */
#define XCVR_TSM_OVRD0_BB_LDO_HF_EN_OVRD_EN(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD0_BB_LDO_HF_EN_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD0_BB_LDO_HF_EN_OVRD_EN_MASK)

#define XCVR_TSM_OVRD0_BB_LDO_HF_EN_OVRD_MASK    (0x2U)
#define XCVR_TSM_OVRD0_BB_LDO_HF_EN_OVRD_SHIFT   (1U)
/*! BB_LDO_HF_EN_OVRD - Override value for BB_LDO_HF_EN */
#define XCVR_TSM_OVRD0_BB_LDO_HF_EN_OVRD(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD0_BB_LDO_HF_EN_OVRD_SHIFT)) & XCVR_TSM_OVRD0_BB_LDO_HF_EN_OVRD_MASK)

#define XCVR_TSM_OVRD0_BB_LDO_ADCDAC_EN_OVRD_EN_MASK (0x4U)
#define XCVR_TSM_OVRD0_BB_LDO_ADCDAC_EN_OVRD_EN_SHIFT (2U)
/*! BB_LDO_ADCDAC_EN_OVRD_EN - Override control for BB_LDO_ADCDAC_EN
 *  0b0..Normal operation.
 *  0b1..Use the state of BB_LDO_ADCDAC_EN_OVRD to override the signal "bb_ldo_adcdac_en".
 */
#define XCVR_TSM_OVRD0_BB_LDO_ADCDAC_EN_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD0_BB_LDO_ADCDAC_EN_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD0_BB_LDO_ADCDAC_EN_OVRD_EN_MASK)

#define XCVR_TSM_OVRD0_BB_LDO_ADCDAC_EN_OVRD_MASK (0x8U)
#define XCVR_TSM_OVRD0_BB_LDO_ADCDAC_EN_OVRD_SHIFT (3U)
/*! BB_LDO_ADCDAC_EN_OVRD - Override value for BB_LDO_ADCDAC_EN */
#define XCVR_TSM_OVRD0_BB_LDO_ADCDAC_EN_OVRD(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD0_BB_LDO_ADCDAC_EN_OVRD_SHIFT)) & XCVR_TSM_OVRD0_BB_LDO_ADCDAC_EN_OVRD_MASK)

#define XCVR_TSM_OVRD0_BB_LDO_BBA_EN_OVRD_EN_MASK (0x10U)
#define XCVR_TSM_OVRD0_BB_LDO_BBA_EN_OVRD_EN_SHIFT (4U)
/*! BB_LDO_BBA_EN_OVRD_EN - Override control for BB_LDO_BBA_EN
 *  0b0..Normal operation.
 *  0b1..Use the state of BB_LDO_BBA_EN_OVRD to override the signal "bb_ldo_bba_en".
 */
#define XCVR_TSM_OVRD0_BB_LDO_BBA_EN_OVRD_EN(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD0_BB_LDO_BBA_EN_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD0_BB_LDO_BBA_EN_OVRD_EN_MASK)

#define XCVR_TSM_OVRD0_BB_LDO_BBA_EN_OVRD_MASK   (0x20U)
#define XCVR_TSM_OVRD0_BB_LDO_BBA_EN_OVRD_SHIFT  (5U)
/*! BB_LDO_BBA_EN_OVRD - Override value for BB_LDO_BBA_EN */
#define XCVR_TSM_OVRD0_BB_LDO_BBA_EN_OVRD(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD0_BB_LDO_BBA_EN_OVRD_SHIFT)) & XCVR_TSM_OVRD0_BB_LDO_BBA_EN_OVRD_MASK)

#define XCVR_TSM_OVRD0_BB_LDO_PD_EN_OVRD_EN_MASK (0x40U)
#define XCVR_TSM_OVRD0_BB_LDO_PD_EN_OVRD_EN_SHIFT (6U)
/*! BB_LDO_PD_EN_OVRD_EN - Override control for BB_LDO_PD_EN
 *  0b0..Normal operation.
 *  0b1..Use the state of BB_LDO_PD_EN_OVRD to override the signal "bb_ldo_pd_en".
 */
#define XCVR_TSM_OVRD0_BB_LDO_PD_EN_OVRD_EN(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD0_BB_LDO_PD_EN_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD0_BB_LDO_PD_EN_OVRD_EN_MASK)

#define XCVR_TSM_OVRD0_BB_LDO_PD_EN_OVRD_MASK    (0x80U)
#define XCVR_TSM_OVRD0_BB_LDO_PD_EN_OVRD_SHIFT   (7U)
/*! BB_LDO_PD_EN_OVRD - Override value for BB_LDO_PD_EN */
#define XCVR_TSM_OVRD0_BB_LDO_PD_EN_OVRD(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD0_BB_LDO_PD_EN_OVRD_SHIFT)) & XCVR_TSM_OVRD0_BB_LDO_PD_EN_OVRD_MASK)

#define XCVR_TSM_OVRD0_BB_LDO_FDBK_EN_OVRD_EN_MASK (0x100U)
#define XCVR_TSM_OVRD0_BB_LDO_FDBK_EN_OVRD_EN_SHIFT (8U)
/*! BB_LDO_FDBK_EN_OVRD_EN - Override control for BB_LDO_FDBK_EN
 *  0b0..Normal operation.
 *  0b1..Use the state of BB_LDO_FDBK_EN_OVRD to override the signal "bb_ldo_fdbk_en".
 */
#define XCVR_TSM_OVRD0_BB_LDO_FDBK_EN_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD0_BB_LDO_FDBK_EN_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD0_BB_LDO_FDBK_EN_OVRD_EN_MASK)

#define XCVR_TSM_OVRD0_BB_LDO_FDBK_EN_OVRD_MASK  (0x200U)
#define XCVR_TSM_OVRD0_BB_LDO_FDBK_EN_OVRD_SHIFT (9U)
/*! BB_LDO_FDBK_EN_OVRD - Override value for BB_LDO_FDBK_EN */
#define XCVR_TSM_OVRD0_BB_LDO_FDBK_EN_OVRD(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD0_BB_LDO_FDBK_EN_OVRD_SHIFT)) & XCVR_TSM_OVRD0_BB_LDO_FDBK_EN_OVRD_MASK)

#define XCVR_TSM_OVRD0_BB_LDO_VCOLO_EN_OVRD_EN_MASK (0x400U)
#define XCVR_TSM_OVRD0_BB_LDO_VCOLO_EN_OVRD_EN_SHIFT (10U)
/*! BB_LDO_VCOLO_EN_OVRD_EN - Override control for BB_LDO_VCOLO_EN
 *  0b0..Normal operation.
 *  0b1..Use the state of BB_LDO_VCOLO_EN_OVRD to override the signal "bb_ldo_vcolo_en".
 */
#define XCVR_TSM_OVRD0_BB_LDO_VCOLO_EN_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD0_BB_LDO_VCOLO_EN_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD0_BB_LDO_VCOLO_EN_OVRD_EN_MASK)

#define XCVR_TSM_OVRD0_BB_LDO_VCOLO_EN_OVRD_MASK (0x800U)
#define XCVR_TSM_OVRD0_BB_LDO_VCOLO_EN_OVRD_SHIFT (11U)
/*! BB_LDO_VCOLO_EN_OVRD - Override value for BB_LDO_VCOLO_EN */
#define XCVR_TSM_OVRD0_BB_LDO_VCOLO_EN_OVRD(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD0_BB_LDO_VCOLO_EN_OVRD_SHIFT)) & XCVR_TSM_OVRD0_BB_LDO_VCOLO_EN_OVRD_MASK)

#define XCVR_TSM_OVRD0_BB_LDO_VTREF_EN_OVRD_EN_MASK (0x1000U)
#define XCVR_TSM_OVRD0_BB_LDO_VTREF_EN_OVRD_EN_SHIFT (12U)
/*! BB_LDO_VTREF_EN_OVRD_EN - Override control for BB_LDO_VTREF_EN
 *  0b0..Normal operation.
 *  0b1..Use the state of BB_LDO_VTREF_EN_OVRD to override the signal "bb_ldo_vtref_en".
 */
#define XCVR_TSM_OVRD0_BB_LDO_VTREF_EN_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD0_BB_LDO_VTREF_EN_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD0_BB_LDO_VTREF_EN_OVRD_EN_MASK)

#define XCVR_TSM_OVRD0_BB_LDO_VTREF_EN_OVRD_MASK (0x2000U)
#define XCVR_TSM_OVRD0_BB_LDO_VTREF_EN_OVRD_SHIFT (13U)
/*! BB_LDO_VTREF_EN_OVRD - Override value for BB_LDO_VTREF_EN */
#define XCVR_TSM_OVRD0_BB_LDO_VTREF_EN_OVRD(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD0_BB_LDO_VTREF_EN_OVRD_SHIFT)) & XCVR_TSM_OVRD0_BB_LDO_VTREF_EN_OVRD_MASK)

#define XCVR_TSM_OVRD0_BB_LDO_FDBK_BLEED_EN_OVRD_EN_MASK (0x4000U)
#define XCVR_TSM_OVRD0_BB_LDO_FDBK_BLEED_EN_OVRD_EN_SHIFT (14U)
/*! BB_LDO_FDBK_BLEED_EN_OVRD_EN - Override control for BB_LDO_FDBK_BLEED_EN
 *  0b0..Normal operation.
 *  0b1..Use the state of BB_LDO_FDBK_BLEED_EN_OVRD to override the signal "bb_ldo_fdbk_bleed_en".
 */
#define XCVR_TSM_OVRD0_BB_LDO_FDBK_BLEED_EN_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD0_BB_LDO_FDBK_BLEED_EN_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD0_BB_LDO_FDBK_BLEED_EN_OVRD_EN_MASK)

#define XCVR_TSM_OVRD0_BB_LDO_FDBK_BLEED_EN_OVRD_MASK (0x8000U)
#define XCVR_TSM_OVRD0_BB_LDO_FDBK_BLEED_EN_OVRD_SHIFT (15U)
/*! BB_LDO_FDBK_BLEED_EN_OVRD - Override value for BB_LDO_FDBK_BLEED_EN */
#define XCVR_TSM_OVRD0_BB_LDO_FDBK_BLEED_EN_OVRD(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD0_BB_LDO_FDBK_BLEED_EN_OVRD_SHIFT)) & XCVR_TSM_OVRD0_BB_LDO_FDBK_BLEED_EN_OVRD_MASK)

#define XCVR_TSM_OVRD0_BB_LDO_VCOLO_BLEED_EN_OVRD_EN_MASK (0x10000U)
#define XCVR_TSM_OVRD0_BB_LDO_VCOLO_BLEED_EN_OVRD_EN_SHIFT (16U)
/*! BB_LDO_VCOLO_BLEED_EN_OVRD_EN - Override control for BB_LDO_VCOLO_BLEED_EN
 *  0b0..Normal operation.
 *  0b1..Use the state of BB_LDO_VCOLO_BLEED_EN_OVRD to override the signal "bb_ldo_vcolo_bleed_en".
 */
#define XCVR_TSM_OVRD0_BB_LDO_VCOLO_BLEED_EN_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD0_BB_LDO_VCOLO_BLEED_EN_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD0_BB_LDO_VCOLO_BLEED_EN_OVRD_EN_MASK)

#define XCVR_TSM_OVRD0_BB_LDO_VCOLO_BLEED_EN_OVRD_MASK (0x20000U)
#define XCVR_TSM_OVRD0_BB_LDO_VCOLO_BLEED_EN_OVRD_SHIFT (17U)
/*! BB_LDO_VCOLO_BLEED_EN_OVRD - Override value for BB_LDO_VCOLO_BLEED_EN */
#define XCVR_TSM_OVRD0_BB_LDO_VCOLO_BLEED_EN_OVRD(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD0_BB_LDO_VCOLO_BLEED_EN_OVRD_SHIFT)) & XCVR_TSM_OVRD0_BB_LDO_VCOLO_BLEED_EN_OVRD_MASK)

#define XCVR_TSM_OVRD0_BB_LDO_VCOLO_FASTCHARGE_EN_OVRD_EN_MASK (0x40000U)
#define XCVR_TSM_OVRD0_BB_LDO_VCOLO_FASTCHARGE_EN_OVRD_EN_SHIFT (18U)
/*! BB_LDO_VCOLO_FASTCHARGE_EN_OVRD_EN - Override control for BB_LDO_VCOLO_FASTCHARGE_EN
 *  0b0..Normal operation.
 *  0b1..Use the state of BB_LDO_VCOLO_FASTCHARGE_EN_OVRD to override the signal "bb_ldo_vcolo_fastcharge_en".
 */
#define XCVR_TSM_OVRD0_BB_LDO_VCOLO_FASTCHARGE_EN_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD0_BB_LDO_VCOLO_FASTCHARGE_EN_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD0_BB_LDO_VCOLO_FASTCHARGE_EN_OVRD_EN_MASK)

#define XCVR_TSM_OVRD0_BB_LDO_VCOLO_FASTCHARGE_EN_OVRD_MASK (0x80000U)
#define XCVR_TSM_OVRD0_BB_LDO_VCOLO_FASTCHARGE_EN_OVRD_SHIFT (19U)
/*! BB_LDO_VCOLO_FASTCHARGE_EN_OVRD - Override value for BB_LDO_VCOLO_FASTCHARGE_EN */
#define XCVR_TSM_OVRD0_BB_LDO_VCOLO_FASTCHARGE_EN_OVRD(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD0_BB_LDO_VCOLO_FASTCHARGE_EN_OVRD_SHIFT)) & XCVR_TSM_OVRD0_BB_LDO_VCOLO_FASTCHARGE_EN_OVRD_MASK)

#define XCVR_TSM_OVRD0_BB_XTAL_PLL_REF_CLK_EN_OVRD_EN_MASK (0x100000U)
#define XCVR_TSM_OVRD0_BB_XTAL_PLL_REF_CLK_EN_OVRD_EN_SHIFT (20U)
/*! BB_XTAL_PLL_REF_CLK_EN_OVRD_EN - Override control for BB_XTAL_PLL_REF_CLK_EN
 *  0b0..Normal operation.
 *  0b1..Use the state of BB_XTAL_PLL_REF_CLK_EN_OVRD to override the signal "bb_xtal_pll_ref_clk_en".
 */
#define XCVR_TSM_OVRD0_BB_XTAL_PLL_REF_CLK_EN_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD0_BB_XTAL_PLL_REF_CLK_EN_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD0_BB_XTAL_PLL_REF_CLK_EN_OVRD_EN_MASK)

#define XCVR_TSM_OVRD0_BB_XTAL_PLL_REF_CLK_EN_OVRD_MASK (0x200000U)
#define XCVR_TSM_OVRD0_BB_XTAL_PLL_REF_CLK_EN_OVRD_SHIFT (21U)
/*! BB_XTAL_PLL_REF_CLK_EN_OVRD - Override value for BB_XTAL_PLL_REF_CLK_EN */
#define XCVR_TSM_OVRD0_BB_XTAL_PLL_REF_CLK_EN_OVRD(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD0_BB_XTAL_PLL_REF_CLK_EN_OVRD_SHIFT)) & XCVR_TSM_OVRD0_BB_XTAL_PLL_REF_CLK_EN_OVRD_MASK)

#define XCVR_TSM_OVRD0_BB_XTAL_DAC_REF_CLK_EN_OVRD_EN_MASK (0x400000U)
#define XCVR_TSM_OVRD0_BB_XTAL_DAC_REF_CLK_EN_OVRD_EN_SHIFT (22U)
/*! BB_XTAL_DAC_REF_CLK_EN_OVRD_EN - Override control for BB_XTAL_DAC_REF_CLK_EN
 *  0b0..Normal operation.
 *  0b1..Use the state of BB_XTAL_DAC_REF_CLK_EN_OVRD to override the signal "bb_xtal_dac_ref_clk_en".
 */
#define XCVR_TSM_OVRD0_BB_XTAL_DAC_REF_CLK_EN_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD0_BB_XTAL_DAC_REF_CLK_EN_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD0_BB_XTAL_DAC_REF_CLK_EN_OVRD_EN_MASK)

#define XCVR_TSM_OVRD0_BB_XTAL_DAC_REF_CLK_EN_OVRD_MASK (0x800000U)
#define XCVR_TSM_OVRD0_BB_XTAL_DAC_REF_CLK_EN_OVRD_SHIFT (23U)
/*! BB_XTAL_DAC_REF_CLK_EN_OVRD - Override value for BB_XTAL_DAC_REF_CLK_EN */
#define XCVR_TSM_OVRD0_BB_XTAL_DAC_REF_CLK_EN_OVRD(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD0_BB_XTAL_DAC_REF_CLK_EN_OVRD_SHIFT)) & XCVR_TSM_OVRD0_BB_XTAL_DAC_REF_CLK_EN_OVRD_MASK)

#define XCVR_TSM_OVRD0_BB_XTAL_AUXPLL_REF_CLK_EN_OVRD_EN_MASK (0x1000000U)
#define XCVR_TSM_OVRD0_BB_XTAL_AUXPLL_REF_CLK_EN_OVRD_EN_SHIFT (24U)
/*! BB_XTAL_AUXPLL_REF_CLK_EN_OVRD_EN - Override control for BB_XTAL_AUXPLL_REF_CLK_EN
 *  0b0..Normal operation.
 *  0b1..Use the state of BB_XTAL_AUXPLL_REF_CLK_EN_OVRD to override the signal "bb_xtal_auxpll_ref_clk_en".
 */
#define XCVR_TSM_OVRD0_BB_XTAL_AUXPLL_REF_CLK_EN_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD0_BB_XTAL_AUXPLL_REF_CLK_EN_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD0_BB_XTAL_AUXPLL_REF_CLK_EN_OVRD_EN_MASK)

#define XCVR_TSM_OVRD0_BB_XTAL_AUXPLL_REF_CLK_EN_OVRD_MASK (0x2000000U)
#define XCVR_TSM_OVRD0_BB_XTAL_AUXPLL_REF_CLK_EN_OVRD_SHIFT (25U)
/*! BB_XTAL_AUXPLL_REF_CLK_EN_OVRD - Override value for BB_XTAL_AUXPLL_REF_CLK_EN */
#define XCVR_TSM_OVRD0_BB_XTAL_AUXPLL_REF_CLK_EN_OVRD(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD0_BB_XTAL_AUXPLL_REF_CLK_EN_OVRD_SHIFT)) & XCVR_TSM_OVRD0_BB_XTAL_AUXPLL_REF_CLK_EN_OVRD_MASK)

#define XCVR_TSM_OVRD0_SY_VCO_AUTOTUNE_EN_OVRD_EN_MASK (0x4000000U)
#define XCVR_TSM_OVRD0_SY_VCO_AUTOTUNE_EN_OVRD_EN_SHIFT (26U)
/*! SY_VCO_AUTOTUNE_EN_OVRD_EN - Override control for SY_VCO_AUTOTUNE_EN
 *  0b0..Normal operation.
 *  0b1..Use the state of SY_VCO_AUTOTUNE_EN_OVRD to override the signal "sy_vco_autotune_en".
 */
#define XCVR_TSM_OVRD0_SY_VCO_AUTOTUNE_EN_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD0_SY_VCO_AUTOTUNE_EN_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD0_SY_VCO_AUTOTUNE_EN_OVRD_EN_MASK)

#define XCVR_TSM_OVRD0_SY_VCO_AUTOTUNE_EN_OVRD_MASK (0x8000000U)
#define XCVR_TSM_OVRD0_SY_VCO_AUTOTUNE_EN_OVRD_SHIFT (27U)
/*! SY_VCO_AUTOTUNE_EN_OVRD - Override value for SY_VCO_AUTOTUNE_EN */
#define XCVR_TSM_OVRD0_SY_VCO_AUTOTUNE_EN_OVRD(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD0_SY_VCO_AUTOTUNE_EN_OVRD_SHIFT)) & XCVR_TSM_OVRD0_SY_VCO_AUTOTUNE_EN_OVRD_MASK)

#define XCVR_TSM_OVRD0_SY_PD_CYCLE_SLIP_LD_EN_OVRD_EN_MASK (0x10000000U)
#define XCVR_TSM_OVRD0_SY_PD_CYCLE_SLIP_LD_EN_OVRD_EN_SHIFT (28U)
/*! SY_PD_CYCLE_SLIP_LD_EN_OVRD_EN - Override control for SY_PD_CYCLE_SLIP_LD_EN
 *  0b0..Normal operation.
 *  0b1..Use the state of SY_PD_CYCLE_SLIP_LD_EN_OVRD to override the signal "sy_pd_cycle_slip_ld_en".
 */
#define XCVR_TSM_OVRD0_SY_PD_CYCLE_SLIP_LD_EN_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD0_SY_PD_CYCLE_SLIP_LD_EN_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD0_SY_PD_CYCLE_SLIP_LD_EN_OVRD_EN_MASK)

#define XCVR_TSM_OVRD0_SY_PD_CYCLE_SLIP_LD_EN_OVRD_MASK (0x20000000U)
#define XCVR_TSM_OVRD0_SY_PD_CYCLE_SLIP_LD_EN_OVRD_SHIFT (29U)
/*! SY_PD_CYCLE_SLIP_LD_EN_OVRD - Override value for SY_PD_CYCLE_SLIP_LD_EN */
#define XCVR_TSM_OVRD0_SY_PD_CYCLE_SLIP_LD_EN_OVRD(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD0_SY_PD_CYCLE_SLIP_LD_EN_OVRD_SHIFT)) & XCVR_TSM_OVRD0_SY_PD_CYCLE_SLIP_LD_EN_OVRD_MASK)

#define XCVR_TSM_OVRD0_SY_VCO_EN_OVRD_EN_MASK    (0x40000000U)
#define XCVR_TSM_OVRD0_SY_VCO_EN_OVRD_EN_SHIFT   (30U)
/*! SY_VCO_EN_OVRD_EN - Override control for SY_VCO_EN
 *  0b0..Normal operation.
 *  0b1..Use the state of SY_VCO_EN_OVRD to override the signal "sy_vco_en".
 */
#define XCVR_TSM_OVRD0_SY_VCO_EN_OVRD_EN(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD0_SY_VCO_EN_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD0_SY_VCO_EN_OVRD_EN_MASK)

#define XCVR_TSM_OVRD0_SY_VCO_EN_OVRD_MASK       (0x80000000U)
#define XCVR_TSM_OVRD0_SY_VCO_EN_OVRD_SHIFT      (31U)
/*! SY_VCO_EN_OVRD - Override value for SY_VCO_EN */
#define XCVR_TSM_OVRD0_SY_VCO_EN_OVRD(x)         (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD0_SY_VCO_EN_OVRD_SHIFT)) & XCVR_TSM_OVRD0_SY_VCO_EN_OVRD_MASK)
/*! @} */

/*! @name OVRD1 - TSM OVERRIDE REGISTER 1 */
/*! @{ */

#define XCVR_TSM_OVRD1_SY_LO_RX_BUF_EN_OVRD_EN_MASK (0x1U)
#define XCVR_TSM_OVRD1_SY_LO_RX_BUF_EN_OVRD_EN_SHIFT (0U)
/*! SY_LO_RX_BUF_EN_OVRD_EN - Override control for SY_LO_RX_BUF_EN
 *  0b0..Normal operation.
 *  0b1..Use the state of SY_LO_RX_BUF_EN_OVRD to override the signal "sy_lo_rx_buf_en".
 */
#define XCVR_TSM_OVRD1_SY_LO_RX_BUF_EN_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD1_SY_LO_RX_BUF_EN_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD1_SY_LO_RX_BUF_EN_OVRD_EN_MASK)

#define XCVR_TSM_OVRD1_SY_LO_RX_BUF_EN_OVRD_MASK (0x2U)
#define XCVR_TSM_OVRD1_SY_LO_RX_BUF_EN_OVRD_SHIFT (1U)
/*! SY_LO_RX_BUF_EN_OVRD - Override value for SY_LO_RX_BUF_EN */
#define XCVR_TSM_OVRD1_SY_LO_RX_BUF_EN_OVRD(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD1_SY_LO_RX_BUF_EN_OVRD_SHIFT)) & XCVR_TSM_OVRD1_SY_LO_RX_BUF_EN_OVRD_MASK)

#define XCVR_TSM_OVRD1_SY_LO_TX_BUF_EN_OVRD_EN_MASK (0x4U)
#define XCVR_TSM_OVRD1_SY_LO_TX_BUF_EN_OVRD_EN_SHIFT (2U)
/*! SY_LO_TX_BUF_EN_OVRD_EN - Override control for SY_LO_TX_BUF_EN
 *  0b0..Normal operation.
 *  0b1..Use the state of SY_LO_TX_BUF_EN_OVRD to override the signal "sy_lo_tx_buf_en".
 */
#define XCVR_TSM_OVRD1_SY_LO_TX_BUF_EN_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD1_SY_LO_TX_BUF_EN_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD1_SY_LO_TX_BUF_EN_OVRD_EN_MASK)

#define XCVR_TSM_OVRD1_SY_LO_TX_BUF_EN_OVRD_MASK (0x8U)
#define XCVR_TSM_OVRD1_SY_LO_TX_BUF_EN_OVRD_SHIFT (3U)
/*! SY_LO_TX_BUF_EN_OVRD - Override value for SY_LO_TX_BUF_EN */
#define XCVR_TSM_OVRD1_SY_LO_TX_BUF_EN_OVRD(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD1_SY_LO_TX_BUF_EN_OVRD_SHIFT)) & XCVR_TSM_OVRD1_SY_LO_TX_BUF_EN_OVRD_MASK)

#define XCVR_TSM_OVRD1_SY_DIVN_EN_OVRD_EN_MASK   (0x10U)
#define XCVR_TSM_OVRD1_SY_DIVN_EN_OVRD_EN_SHIFT  (4U)
/*! SY_DIVN_EN_OVRD_EN - Override control for SY_DIVN_EN
 *  0b0..Normal operation.
 *  0b1..Use the state of SY_DIVN_EN_OVRD to override the signal "sy_divn_en".
 */
#define XCVR_TSM_OVRD1_SY_DIVN_EN_OVRD_EN(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD1_SY_DIVN_EN_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD1_SY_DIVN_EN_OVRD_EN_MASK)

#define XCVR_TSM_OVRD1_SY_DIVN_EN_OVRD_MASK      (0x20U)
#define XCVR_TSM_OVRD1_SY_DIVN_EN_OVRD_SHIFT     (5U)
/*! SY_DIVN_EN_OVRD - Override value for SY_DIVN_EN */
#define XCVR_TSM_OVRD1_SY_DIVN_EN_OVRD(x)        (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD1_SY_DIVN_EN_OVRD_SHIFT)) & XCVR_TSM_OVRD1_SY_DIVN_EN_OVRD_MASK)

#define XCVR_TSM_OVRD1_SY_PD_FILTER_CHARGE_EN_OVRD_EN_MASK (0x40U)
#define XCVR_TSM_OVRD1_SY_PD_FILTER_CHARGE_EN_OVRD_EN_SHIFT (6U)
/*! SY_PD_FILTER_CHARGE_EN_OVRD_EN - Override control for SY_PD_FILTER_CHARGE_EN
 *  0b0..Normal operation.
 *  0b1..Use the state of SY_PD_FILTER_CHARGE_EN_OVRD to override the signal "sy_pd_filter_charge_en".
 */
#define XCVR_TSM_OVRD1_SY_PD_FILTER_CHARGE_EN_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD1_SY_PD_FILTER_CHARGE_EN_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD1_SY_PD_FILTER_CHARGE_EN_OVRD_EN_MASK)

#define XCVR_TSM_OVRD1_SY_PD_FILTER_CHARGE_EN_OVRD_MASK (0x80U)
#define XCVR_TSM_OVRD1_SY_PD_FILTER_CHARGE_EN_OVRD_SHIFT (7U)
/*! SY_PD_FILTER_CHARGE_EN_OVRD - Override value for SY_PD_FILTER_CHARGE_EN */
#define XCVR_TSM_OVRD1_SY_PD_FILTER_CHARGE_EN_OVRD(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD1_SY_PD_FILTER_CHARGE_EN_OVRD_SHIFT)) & XCVR_TSM_OVRD1_SY_PD_FILTER_CHARGE_EN_OVRD_MASK)

#define XCVR_TSM_OVRD1_SY_PD_EN_OVRD_EN_MASK     (0x100U)
#define XCVR_TSM_OVRD1_SY_PD_EN_OVRD_EN_SHIFT    (8U)
/*! SY_PD_EN_OVRD_EN - Override control for SY_PD_EN
 *  0b0..Normal operation.
 *  0b1..Use the state of SY_PD_EN_OVRD to override the signal "sy_pd_en".
 */
#define XCVR_TSM_OVRD1_SY_PD_EN_OVRD_EN(x)       (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD1_SY_PD_EN_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD1_SY_PD_EN_OVRD_EN_MASK)

#define XCVR_TSM_OVRD1_SY_PD_EN_OVRD_MASK        (0x200U)
#define XCVR_TSM_OVRD1_SY_PD_EN_OVRD_SHIFT       (9U)
/*! SY_PD_EN_OVRD - Override value for SY_PD_EN */
#define XCVR_TSM_OVRD1_SY_PD_EN_OVRD(x)          (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD1_SY_PD_EN_OVRD_SHIFT)) & XCVR_TSM_OVRD1_SY_PD_EN_OVRD_MASK)

#define XCVR_TSM_OVRD1_SY_LO_DIVN_EN_OVRD_EN_MASK (0x400U)
#define XCVR_TSM_OVRD1_SY_LO_DIVN_EN_OVRD_EN_SHIFT (10U)
/*! SY_LO_DIVN_EN_OVRD_EN - Override control for SY_LO_DIVN_EN
 *  0b0..Normal operation.
 *  0b1..Use the state of SY_LO_DIVN_EN_OVRD to override the signal "sy_lo_divn_en".
 */
#define XCVR_TSM_OVRD1_SY_LO_DIVN_EN_OVRD_EN(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD1_SY_LO_DIVN_EN_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD1_SY_LO_DIVN_EN_OVRD_EN_MASK)

#define XCVR_TSM_OVRD1_SY_LO_DIVN_EN_OVRD_MASK   (0x800U)
#define XCVR_TSM_OVRD1_SY_LO_DIVN_EN_OVRD_SHIFT  (11U)
/*! SY_LO_DIVN_EN_OVRD - Override value for SY_LO_DIVN_EN */
#define XCVR_TSM_OVRD1_SY_LO_DIVN_EN_OVRD(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD1_SY_LO_DIVN_EN_OVRD_SHIFT)) & XCVR_TSM_OVRD1_SY_LO_DIVN_EN_OVRD_MASK)

#define XCVR_TSM_OVRD1_SY_LO_RX_EN_OVRD_EN_MASK  (0x1000U)
#define XCVR_TSM_OVRD1_SY_LO_RX_EN_OVRD_EN_SHIFT (12U)
/*! SY_LO_RX_EN_OVRD_EN - Override control for SY_LO_RX_EN
 *  0b0..Normal operation.
 *  0b1..Use the state of SY_LO_RX_EN_OVRD to override the signal "sy_lo_rx_en".
 */
#define XCVR_TSM_OVRD1_SY_LO_RX_EN_OVRD_EN(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD1_SY_LO_RX_EN_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD1_SY_LO_RX_EN_OVRD_EN_MASK)

#define XCVR_TSM_OVRD1_SY_LO_RX_EN_OVRD_MASK     (0x2000U)
#define XCVR_TSM_OVRD1_SY_LO_RX_EN_OVRD_SHIFT    (13U)
/*! SY_LO_RX_EN_OVRD - Override value for SY_LO_RX_EN */
#define XCVR_TSM_OVRD1_SY_LO_RX_EN_OVRD(x)       (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD1_SY_LO_RX_EN_OVRD_SHIFT)) & XCVR_TSM_OVRD1_SY_LO_RX_EN_OVRD_MASK)

#define XCVR_TSM_OVRD1_SY_LO_TX_EN_OVRD_EN_MASK  (0x4000U)
#define XCVR_TSM_OVRD1_SY_LO_TX_EN_OVRD_EN_SHIFT (14U)
/*! SY_LO_TX_EN_OVRD_EN - Override control for SY_LO_TX_EN
 *  0b0..Normal operation.
 *  0b1..Use the state of SY_LO_TX_EN_OVRD to override the signal "sy_lo_tx_en".
 */
#define XCVR_TSM_OVRD1_SY_LO_TX_EN_OVRD_EN(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD1_SY_LO_TX_EN_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD1_SY_LO_TX_EN_OVRD_EN_MASK)

#define XCVR_TSM_OVRD1_SY_LO_TX_EN_OVRD_MASK     (0x8000U)
#define XCVR_TSM_OVRD1_SY_LO_TX_EN_OVRD_SHIFT    (15U)
/*! SY_LO_TX_EN_OVRD - Override value for SY_LO_TX_EN */
#define XCVR_TSM_OVRD1_SY_LO_TX_EN_OVRD(x)       (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD1_SY_LO_TX_EN_OVRD_SHIFT)) & XCVR_TSM_OVRD1_SY_LO_TX_EN_OVRD_MASK)

#define XCVR_TSM_OVRD1_SY_DIVN_CAL_EN_OVRD_EN_MASK (0x10000U)
#define XCVR_TSM_OVRD1_SY_DIVN_CAL_EN_OVRD_EN_SHIFT (16U)
/*! SY_DIVN_CAL_EN_OVRD_EN - Override control for SY_DIVN_CAL_EN
 *  0b0..Normal operation.
 *  0b1..Use the state of SY_DIVN_CAL_EN_OVRD to override the signal "sy_divn_cal_en".
 */
#define XCVR_TSM_OVRD1_SY_DIVN_CAL_EN_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD1_SY_DIVN_CAL_EN_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD1_SY_DIVN_CAL_EN_OVRD_EN_MASK)

#define XCVR_TSM_OVRD1_SY_DIVN_CAL_EN_OVRD_MASK  (0x20000U)
#define XCVR_TSM_OVRD1_SY_DIVN_CAL_EN_OVRD_SHIFT (17U)
/*! SY_DIVN_CAL_EN_OVRD - Override value for SY_DIVN_CAL_EN */
#define XCVR_TSM_OVRD1_SY_DIVN_CAL_EN_OVRD(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD1_SY_DIVN_CAL_EN_OVRD_SHIFT)) & XCVR_TSM_OVRD1_SY_DIVN_CAL_EN_OVRD_MASK)

#define XCVR_TSM_OVRD1_RX_MIXER_EN_OVRD_EN_MASK  (0x40000U)
#define XCVR_TSM_OVRD1_RX_MIXER_EN_OVRD_EN_SHIFT (18U)
/*! RX_MIXER_EN_OVRD_EN - Override control for RX_MIXER_EN
 *  0b0..Normal operation.
 *  0b1..Use the state of RX_MIXER_EN_OVRD to override the signal "rx_mixer_en".
 */
#define XCVR_TSM_OVRD1_RX_MIXER_EN_OVRD_EN(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD1_RX_MIXER_EN_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD1_RX_MIXER_EN_OVRD_EN_MASK)

#define XCVR_TSM_OVRD1_RX_MIXER_EN_OVRD_MASK     (0x80000U)
#define XCVR_TSM_OVRD1_RX_MIXER_EN_OVRD_SHIFT    (19U)
/*! RX_MIXER_EN_OVRD - Override value for RX_MIXER_EN */
#define XCVR_TSM_OVRD1_RX_MIXER_EN_OVRD(x)       (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD1_RX_MIXER_EN_OVRD_SHIFT)) & XCVR_TSM_OVRD1_RX_MIXER_EN_OVRD_MASK)

#define XCVR_TSM_OVRD1_TX_PA_EN_OVRD_EN_MASK     (0x100000U)
#define XCVR_TSM_OVRD1_TX_PA_EN_OVRD_EN_SHIFT    (20U)
/*! TX_PA_EN_OVRD_EN - Override control for TX_PA_EN
 *  0b0..Normal operation.
 *  0b1..Use the state of TX_PA_EN_OVRD to override the signal "tx_pa_en".
 */
#define XCVR_TSM_OVRD1_TX_PA_EN_OVRD_EN(x)       (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD1_TX_PA_EN_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD1_TX_PA_EN_OVRD_EN_MASK)

#define XCVR_TSM_OVRD1_TX_PA_EN_OVRD_MASK        (0x200000U)
#define XCVR_TSM_OVRD1_TX_PA_EN_OVRD_SHIFT       (21U)
/*! TX_PA_EN_OVRD - Override value for TX_PA_EN */
#define XCVR_TSM_OVRD1_TX_PA_EN_OVRD(x)          (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD1_TX_PA_EN_OVRD_SHIFT)) & XCVR_TSM_OVRD1_TX_PA_EN_OVRD_MASK)

#define XCVR_TSM_OVRD1_RX_ADC_I_EN_OVRD_EN_MASK  (0x400000U)
#define XCVR_TSM_OVRD1_RX_ADC_I_EN_OVRD_EN_SHIFT (22U)
/*! RX_ADC_I_EN_OVRD_EN - Override control for RX_ADC_I_EN
 *  0b0..Normal operation.
 *  0b1..Use the state of RX_ADC_I_EN_OVRD to override the signal "rx_adc_i_en".
 */
#define XCVR_TSM_OVRD1_RX_ADC_I_EN_OVRD_EN(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD1_RX_ADC_I_EN_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD1_RX_ADC_I_EN_OVRD_EN_MASK)

#define XCVR_TSM_OVRD1_RX_ADC_I_EN_OVRD_MASK     (0x800000U)
#define XCVR_TSM_OVRD1_RX_ADC_I_EN_OVRD_SHIFT    (23U)
/*! RX_ADC_I_EN_OVRD - Override value for RX_ADC_I_EN */
#define XCVR_TSM_OVRD1_RX_ADC_I_EN_OVRD(x)       (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD1_RX_ADC_I_EN_OVRD_SHIFT)) & XCVR_TSM_OVRD1_RX_ADC_I_EN_OVRD_MASK)

#define XCVR_TSM_OVRD1_RX_ADC_Q_EN_OVRD_EN_MASK  (0x1000000U)
#define XCVR_TSM_OVRD1_RX_ADC_Q_EN_OVRD_EN_SHIFT (24U)
/*! RX_ADC_Q_EN_OVRD_EN - Override control for RX_ADC_Q_EN
 *  0b0..Normal operation.
 *  0b1..Use the state of RX_ADC_Q_EN_OVRD to override the signal "rx_adc_q_en".
 */
#define XCVR_TSM_OVRD1_RX_ADC_Q_EN_OVRD_EN(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD1_RX_ADC_Q_EN_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD1_RX_ADC_Q_EN_OVRD_EN_MASK)

#define XCVR_TSM_OVRD1_RX_ADC_Q_EN_OVRD_MASK     (0x2000000U)
#define XCVR_TSM_OVRD1_RX_ADC_Q_EN_OVRD_SHIFT    (25U)
/*! RX_ADC_Q_EN_OVRD - Override value for RX_ADC_Q_EN */
#define XCVR_TSM_OVRD1_RX_ADC_Q_EN_OVRD(x)       (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD1_RX_ADC_Q_EN_OVRD_SHIFT)) & XCVR_TSM_OVRD1_RX_ADC_Q_EN_OVRD_MASK)

#define XCVR_TSM_OVRD1_RX_ADC_RESET_EN_OVRD_EN_MASK (0x4000000U)
#define XCVR_TSM_OVRD1_RX_ADC_RESET_EN_OVRD_EN_SHIFT (26U)
/*! RX_ADC_RESET_EN_OVRD_EN - Override control for RX_ADC_RESET_EN
 *  0b0..Normal operation.
 *  0b1..Use the state of RX_ADC_RESET_EN_OVRD to override the signal "rx_adc_reset_en".
 */
#define XCVR_TSM_OVRD1_RX_ADC_RESET_EN_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD1_RX_ADC_RESET_EN_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD1_RX_ADC_RESET_EN_OVRD_EN_MASK)

#define XCVR_TSM_OVRD1_RX_ADC_RESET_EN_OVRD_MASK (0x8000000U)
#define XCVR_TSM_OVRD1_RX_ADC_RESET_EN_OVRD_SHIFT (27U)
/*! RX_ADC_RESET_EN_OVRD - Override value for RX_ADC_RESET_EN */
#define XCVR_TSM_OVRD1_RX_ADC_RESET_EN_OVRD(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD1_RX_ADC_RESET_EN_OVRD_SHIFT)) & XCVR_TSM_OVRD1_RX_ADC_RESET_EN_OVRD_MASK)

#define XCVR_TSM_OVRD1_RX_BBA_I_EN_OVRD_EN_MASK  (0x10000000U)
#define XCVR_TSM_OVRD1_RX_BBA_I_EN_OVRD_EN_SHIFT (28U)
/*! RX_BBA_I_EN_OVRD_EN - Override control for RX_BBA_I_EN
 *  0b0..Normal operation.
 *  0b1..Use the state of RX_BBA_I_EN_OVRD to override the signal "rx_bba_i_en".
 */
#define XCVR_TSM_OVRD1_RX_BBA_I_EN_OVRD_EN(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD1_RX_BBA_I_EN_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD1_RX_BBA_I_EN_OVRD_EN_MASK)

#define XCVR_TSM_OVRD1_RX_BBA_I_EN_OVRD_MASK     (0x20000000U)
#define XCVR_TSM_OVRD1_RX_BBA_I_EN_OVRD_SHIFT    (29U)
/*! RX_BBA_I_EN_OVRD - Override value for RX_BBA_I_EN */
#define XCVR_TSM_OVRD1_RX_BBA_I_EN_OVRD(x)       (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD1_RX_BBA_I_EN_OVRD_SHIFT)) & XCVR_TSM_OVRD1_RX_BBA_I_EN_OVRD_MASK)

#define XCVR_TSM_OVRD1_RX_BBA_Q_EN_OVRD_EN_MASK  (0x40000000U)
#define XCVR_TSM_OVRD1_RX_BBA_Q_EN_OVRD_EN_SHIFT (30U)
/*! RX_BBA_Q_EN_OVRD_EN - Override control for RX_BBA_Q_EN
 *  0b0..Normal operation.
 *  0b1..Use the state of RX_BBA_Q_EN_OVRD to override the signal "rx_bba_q_en".
 */
#define XCVR_TSM_OVRD1_RX_BBA_Q_EN_OVRD_EN(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD1_RX_BBA_Q_EN_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD1_RX_BBA_Q_EN_OVRD_EN_MASK)

#define XCVR_TSM_OVRD1_RX_BBA_Q_EN_OVRD_MASK     (0x80000000U)
#define XCVR_TSM_OVRD1_RX_BBA_Q_EN_OVRD_SHIFT    (31U)
/*! RX_BBA_Q_EN_OVRD - Override value for RX_BBA_Q_EN */
#define XCVR_TSM_OVRD1_RX_BBA_Q_EN_OVRD(x)       (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD1_RX_BBA_Q_EN_OVRD_SHIFT)) & XCVR_TSM_OVRD1_RX_BBA_Q_EN_OVRD_MASK)
/*! @} */

/*! @name OVRD2 - TSM OVERRIDE REGISTER 2 */
/*! @{ */

#define XCVR_TSM_OVRD2_RX_BBA_PDET_EN_OVRD_EN_MASK (0x1U)
#define XCVR_TSM_OVRD2_RX_BBA_PDET_EN_OVRD_EN_SHIFT (0U)
/*! RX_BBA_PDET_EN_OVRD_EN - Override control for RX_BBA_PDET_EN
 *  0b0..Normal operation.
 *  0b1..Use the state of RX_BBA_PDET_EN_OVRD to override the signal "rx_bba_pdet_en".
 */
#define XCVR_TSM_OVRD2_RX_BBA_PDET_EN_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD2_RX_BBA_PDET_EN_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD2_RX_BBA_PDET_EN_OVRD_EN_MASK)

#define XCVR_TSM_OVRD2_RX_BBA_PDET_EN_OVRD_MASK  (0x2U)
#define XCVR_TSM_OVRD2_RX_BBA_PDET_EN_OVRD_SHIFT (1U)
/*! RX_BBA_PDET_EN_OVRD - Override value for RX_BBA_PDET_EN */
#define XCVR_TSM_OVRD2_RX_BBA_PDET_EN_OVRD(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD2_RX_BBA_PDET_EN_OVRD_SHIFT)) & XCVR_TSM_OVRD2_RX_BBA_PDET_EN_OVRD_MASK)

#define XCVR_TSM_OVRD2_RX_BBA_DCOC_EN_OVRD_EN_MASK (0x4U)
#define XCVR_TSM_OVRD2_RX_BBA_DCOC_EN_OVRD_EN_SHIFT (2U)
/*! RX_BBA_DCOC_EN_OVRD_EN - Override control for RX_BBA_DCOC_EN
 *  0b0..Normal operation.
 *  0b1..Use the state of RX_BBA_DCOC_EN_OVRD to override the signal "rx_bba_dcoc_en".
 */
#define XCVR_TSM_OVRD2_RX_BBA_DCOC_EN_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD2_RX_BBA_DCOC_EN_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD2_RX_BBA_DCOC_EN_OVRD_EN_MASK)

#define XCVR_TSM_OVRD2_RX_BBA_DCOC_EN_OVRD_MASK  (0x8U)
#define XCVR_TSM_OVRD2_RX_BBA_DCOC_EN_OVRD_SHIFT (3U)
/*! RX_BBA_DCOC_EN_OVRD - Override value for RX_BBA_DCOC_EN */
#define XCVR_TSM_OVRD2_RX_BBA_DCOC_EN_OVRD(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD2_RX_BBA_DCOC_EN_OVRD_SHIFT)) & XCVR_TSM_OVRD2_RX_BBA_DCOC_EN_OVRD_MASK)

#define XCVR_TSM_OVRD2_RX_LNA_EN_OVRD_EN_MASK    (0x10U)
#define XCVR_TSM_OVRD2_RX_LNA_EN_OVRD_EN_SHIFT   (4U)
/*! RX_LNA_EN_OVRD_EN - Override control for RX_LNA_EN
 *  0b0..Normal operation.
 *  0b1..Use the state of RX_LNA_EN_OVRD to override the signal "rx_lna_en".
 */
#define XCVR_TSM_OVRD2_RX_LNA_EN_OVRD_EN(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD2_RX_LNA_EN_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD2_RX_LNA_EN_OVRD_EN_MASK)

#define XCVR_TSM_OVRD2_RX_LNA_EN_OVRD_MASK       (0x20U)
#define XCVR_TSM_OVRD2_RX_LNA_EN_OVRD_SHIFT      (5U)
/*! RX_LNA_EN_OVRD - Override value for RX_LNA_EN */
#define XCVR_TSM_OVRD2_RX_LNA_EN_OVRD(x)         (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD2_RX_LNA_EN_OVRD_SHIFT)) & XCVR_TSM_OVRD2_RX_LNA_EN_OVRD_MASK)

#define XCVR_TSM_OVRD2_RX_TZA_I_EN_OVRD_EN_MASK  (0x40U)
#define XCVR_TSM_OVRD2_RX_TZA_I_EN_OVRD_EN_SHIFT (6U)
/*! RX_TZA_I_EN_OVRD_EN - Override control for RX_TZA_I_EN
 *  0b0..Normal operation.
 *  0b1..Use the state of RX_TZA_I_EN_OVRD to override the signal "rx_tza_i_en".
 */
#define XCVR_TSM_OVRD2_RX_TZA_I_EN_OVRD_EN(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD2_RX_TZA_I_EN_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD2_RX_TZA_I_EN_OVRD_EN_MASK)

#define XCVR_TSM_OVRD2_RX_TZA_I_EN_OVRD_MASK     (0x80U)
#define XCVR_TSM_OVRD2_RX_TZA_I_EN_OVRD_SHIFT    (7U)
/*! RX_TZA_I_EN_OVRD - Override value for RX_TZA_I_EN */
#define XCVR_TSM_OVRD2_RX_TZA_I_EN_OVRD(x)       (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD2_RX_TZA_I_EN_OVRD_SHIFT)) & XCVR_TSM_OVRD2_RX_TZA_I_EN_OVRD_MASK)

#define XCVR_TSM_OVRD2_RX_TZA_Q_EN_OVRD_EN_MASK  (0x100U)
#define XCVR_TSM_OVRD2_RX_TZA_Q_EN_OVRD_EN_SHIFT (8U)
/*! RX_TZA_Q_EN_OVRD_EN - Override control for RX_TZA_Q_EN
 *  0b0..Normal operation.
 *  0b1..Use the state of RX_TZA_Q_EN_OVRD to override the signal "rx_tza_q_en".
 */
#define XCVR_TSM_OVRD2_RX_TZA_Q_EN_OVRD_EN(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD2_RX_TZA_Q_EN_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD2_RX_TZA_Q_EN_OVRD_EN_MASK)

#define XCVR_TSM_OVRD2_RX_TZA_Q_EN_OVRD_MASK     (0x200U)
#define XCVR_TSM_OVRD2_RX_TZA_Q_EN_OVRD_SHIFT    (9U)
/*! RX_TZA_Q_EN_OVRD - Override value for RX_TZA_Q_EN */
#define XCVR_TSM_OVRD2_RX_TZA_Q_EN_OVRD(x)       (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD2_RX_TZA_Q_EN_OVRD_SHIFT)) & XCVR_TSM_OVRD2_RX_TZA_Q_EN_OVRD_MASK)

#define XCVR_TSM_OVRD2_RX_TZA_PDET_EN_OVRD_EN_MASK (0x400U)
#define XCVR_TSM_OVRD2_RX_TZA_PDET_EN_OVRD_EN_SHIFT (10U)
/*! RX_TZA_PDET_EN_OVRD_EN - Override control for RX_TZA_PDET_EN
 *  0b0..Normal operation.
 *  0b1..Use the state of RX_TZA_PDET_EN_OVRD to override the signal "rx_tza_pdet_en".
 */
#define XCVR_TSM_OVRD2_RX_TZA_PDET_EN_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD2_RX_TZA_PDET_EN_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD2_RX_TZA_PDET_EN_OVRD_EN_MASK)

#define XCVR_TSM_OVRD2_RX_TZA_PDET_EN_OVRD_MASK  (0x800U)
#define XCVR_TSM_OVRD2_RX_TZA_PDET_EN_OVRD_SHIFT (11U)
/*! RX_TZA_PDET_EN_OVRD - Override value for RX_TZA_PDET_EN */
#define XCVR_TSM_OVRD2_RX_TZA_PDET_EN_OVRD(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD2_RX_TZA_PDET_EN_OVRD_SHIFT)) & XCVR_TSM_OVRD2_RX_TZA_PDET_EN_OVRD_MASK)

#define XCVR_TSM_OVRD2_RX_TZA_DCOC_EN_OVRD_EN_MASK (0x1000U)
#define XCVR_TSM_OVRD2_RX_TZA_DCOC_EN_OVRD_EN_SHIFT (12U)
/*! RX_TZA_DCOC_EN_OVRD_EN - Override control for RX_TZA_DCOC_EN
 *  0b0..Normal operation.
 *  0b1..Use the state of RX_TZA_DCOC_EN_OVRD to override the signal "rx_tza_dcoc_en".
 */
#define XCVR_TSM_OVRD2_RX_TZA_DCOC_EN_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD2_RX_TZA_DCOC_EN_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD2_RX_TZA_DCOC_EN_OVRD_EN_MASK)

#define XCVR_TSM_OVRD2_RX_TZA_DCOC_EN_OVRD_MASK  (0x2000U)
#define XCVR_TSM_OVRD2_RX_TZA_DCOC_EN_OVRD_SHIFT (13U)
/*! RX_TZA_DCOC_EN_OVRD - Override control for RX_TZA_DCOC_EN
 *  0b0..Normal operation.
 *  0b1..Use the state of RX_TZA_DCOC_EN_OVRD to override the signal "rx_tza_dcoc_en".
 */
#define XCVR_TSM_OVRD2_RX_TZA_DCOC_EN_OVRD(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD2_RX_TZA_DCOC_EN_OVRD_SHIFT)) & XCVR_TSM_OVRD2_RX_TZA_DCOC_EN_OVRD_MASK)

#define XCVR_TSM_OVRD2_PLL_DIG_EN_OVRD_EN_MASK   (0x4000U)
#define XCVR_TSM_OVRD2_PLL_DIG_EN_OVRD_EN_SHIFT  (14U)
/*! PLL_DIG_EN_OVRD_EN - Override control for PLL_DIG_EN
 *  0b0..Normal operation.
 *  0b1..Use the state of PLL_DIG_EN_OVRD to override the signal "pll_dig_en".
 */
#define XCVR_TSM_OVRD2_PLL_DIG_EN_OVRD_EN(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD2_PLL_DIG_EN_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD2_PLL_DIG_EN_OVRD_EN_MASK)

#define XCVR_TSM_OVRD2_PLL_DIG_EN_OVRD_MASK      (0x8000U)
#define XCVR_TSM_OVRD2_PLL_DIG_EN_OVRD_SHIFT     (15U)
/*! PLL_DIG_EN_OVRD - Override value for PLL_DIG_EN */
#define XCVR_TSM_OVRD2_PLL_DIG_EN_OVRD(x)        (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD2_PLL_DIG_EN_OVRD_SHIFT)) & XCVR_TSM_OVRD2_PLL_DIG_EN_OVRD_MASK)

#define XCVR_TSM_OVRD2_TX_DIG_EN_OVRD_EN_MASK    (0x10000U)
#define XCVR_TSM_OVRD2_TX_DIG_EN_OVRD_EN_SHIFT   (16U)
/*! TX_DIG_EN_OVRD_EN - Override control for TX_DIG_EN
 *  0b0..Normal operation.
 *  0b1..Use the state of TX_DIG_EN_OVRD to override the signal "tx_dig_en".
 */
#define XCVR_TSM_OVRD2_TX_DIG_EN_OVRD_EN(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD2_TX_DIG_EN_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD2_TX_DIG_EN_OVRD_EN_MASK)

#define XCVR_TSM_OVRD2_TX_DIG_EN_OVRD_MASK       (0x20000U)
#define XCVR_TSM_OVRD2_TX_DIG_EN_OVRD_SHIFT      (17U)
/*! TX_DIG_EN_OVRD - Override value for TX_DIG_EN */
#define XCVR_TSM_OVRD2_TX_DIG_EN_OVRD(x)         (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD2_TX_DIG_EN_OVRD_SHIFT)) & XCVR_TSM_OVRD2_TX_DIG_EN_OVRD_MASK)

#define XCVR_TSM_OVRD2_RX_DIG_EN_OVRD_EN_MASK    (0x40000U)
#define XCVR_TSM_OVRD2_RX_DIG_EN_OVRD_EN_SHIFT   (18U)
/*! RX_DIG_EN_OVRD_EN - Override control for RX_DIG_EN
 *  0b0..Normal operation.
 *  0b1..Use the state of RX_DIG_EN_OVRD to override the signal "rx_dig_en".
 */
#define XCVR_TSM_OVRD2_RX_DIG_EN_OVRD_EN(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD2_RX_DIG_EN_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD2_RX_DIG_EN_OVRD_EN_MASK)

#define XCVR_TSM_OVRD2_RX_DIG_EN_OVRD_MASK       (0x80000U)
#define XCVR_TSM_OVRD2_RX_DIG_EN_OVRD_SHIFT      (19U)
/*! RX_DIG_EN_OVRD - Override value for RX_DIG_EN */
#define XCVR_TSM_OVRD2_RX_DIG_EN_OVRD(x)         (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD2_RX_DIG_EN_OVRD_SHIFT)) & XCVR_TSM_OVRD2_RX_DIG_EN_OVRD_MASK)

#define XCVR_TSM_OVRD2_RX_INIT_OVRD_EN_MASK      (0x100000U)
#define XCVR_TSM_OVRD2_RX_INIT_OVRD_EN_SHIFT     (20U)
/*! RX_INIT_OVRD_EN - Override control for RX_INIT
 *  0b0..Normal operation.
 *  0b1..Use the state of RX_INIT_OVRD to override the signal "rx_init".
 */
#define XCVR_TSM_OVRD2_RX_INIT_OVRD_EN(x)        (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD2_RX_INIT_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD2_RX_INIT_OVRD_EN_MASK)

#define XCVR_TSM_OVRD2_RX_INIT_OVRD_MASK         (0x200000U)
#define XCVR_TSM_OVRD2_RX_INIT_OVRD_SHIFT        (21U)
/*! RX_INIT_OVRD - Override value for RX_INIT */
#define XCVR_TSM_OVRD2_RX_INIT_OVRD(x)           (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD2_RX_INIT_OVRD_SHIFT)) & XCVR_TSM_OVRD2_RX_INIT_OVRD_MASK)

#define XCVR_TSM_OVRD2_SIGMA_DELTA_EN_OVRD_EN_MASK (0x400000U)
#define XCVR_TSM_OVRD2_SIGMA_DELTA_EN_OVRD_EN_SHIFT (22U)
/*! SIGMA_DELTA_EN_OVRD_EN - Override control for SIGMA_DELTA_EN
 *  0b0..Normal operation.
 *  0b1..Use the state of SIGMA_DELTA_EN_OVRD to override the signal "sigma_delta_en".
 */
#define XCVR_TSM_OVRD2_SIGMA_DELTA_EN_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD2_SIGMA_DELTA_EN_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD2_SIGMA_DELTA_EN_OVRD_EN_MASK)

#define XCVR_TSM_OVRD2_SIGMA_DELTA_EN_OVRD_MASK  (0x800000U)
#define XCVR_TSM_OVRD2_SIGMA_DELTA_EN_OVRD_SHIFT (23U)
/*! SIGMA_DELTA_EN_OVRD - Override value for SIGMA_DELTA_EN */
#define XCVR_TSM_OVRD2_SIGMA_DELTA_EN_OVRD(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD2_SIGMA_DELTA_EN_OVRD_SHIFT)) & XCVR_TSM_OVRD2_SIGMA_DELTA_EN_OVRD_MASK)

#define XCVR_TSM_OVRD2_RX_PHY_EN_OVRD_EN_MASK    (0x1000000U)
#define XCVR_TSM_OVRD2_RX_PHY_EN_OVRD_EN_SHIFT   (24U)
/*! RX_PHY_EN_OVRD_EN - Override control for RX_PHY_EN
 *  0b0..Normal operation.
 *  0b1..Use the state of RX_PHY_EN_OVRD to override the signal "rx_phy_en".
 */
#define XCVR_TSM_OVRD2_RX_PHY_EN_OVRD_EN(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD2_RX_PHY_EN_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD2_RX_PHY_EN_OVRD_EN_MASK)

#define XCVR_TSM_OVRD2_RX_PHY_EN_OVRD_MASK       (0x2000000U)
#define XCVR_TSM_OVRD2_RX_PHY_EN_OVRD_SHIFT      (25U)
/*! RX_PHY_EN_OVRD - Override value for RX_PHY_EN */
#define XCVR_TSM_OVRD2_RX_PHY_EN_OVRD(x)         (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD2_RX_PHY_EN_OVRD_SHIFT)) & XCVR_TSM_OVRD2_RX_PHY_EN_OVRD_MASK)

#define XCVR_TSM_OVRD2_DCOC_EN_OVRD_EN_MASK      (0x4000000U)
#define XCVR_TSM_OVRD2_DCOC_EN_OVRD_EN_SHIFT     (26U)
/*! DCOC_EN_OVRD_EN - Override control for DCOC_EN
 *  0b0..Normal operation.
 *  0b1..Use the state of DCOC_EN_OVRD to override the signal "dcoc_en".
 */
#define XCVR_TSM_OVRD2_DCOC_EN_OVRD_EN(x)        (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD2_DCOC_EN_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD2_DCOC_EN_OVRD_EN_MASK)

#define XCVR_TSM_OVRD2_DCOC_EN_OVRD_MASK         (0x8000000U)
#define XCVR_TSM_OVRD2_DCOC_EN_OVRD_SHIFT        (27U)
/*! DCOC_EN_OVRD - Override value for DCOC_EN */
#define XCVR_TSM_OVRD2_DCOC_EN_OVRD(x)           (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD2_DCOC_EN_OVRD_SHIFT)) & XCVR_TSM_OVRD2_DCOC_EN_OVRD_MASK)

#define XCVR_TSM_OVRD2_DCOC_INIT_OVRD_EN_MASK    (0x10000000U)
#define XCVR_TSM_OVRD2_DCOC_INIT_OVRD_EN_SHIFT   (28U)
/*! DCOC_INIT_OVRD_EN - Override control for DCOC_INIT
 *  0b0..Normal operation.
 *  0b1..Use the state of DCOC_INIT_OVRD to override the signal "dcoc_init".
 */
#define XCVR_TSM_OVRD2_DCOC_INIT_OVRD_EN(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD2_DCOC_INIT_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD2_DCOC_INIT_OVRD_EN_MASK)

#define XCVR_TSM_OVRD2_DCOC_INIT_OVRD_MASK       (0x20000000U)
#define XCVR_TSM_OVRD2_DCOC_INIT_OVRD_SHIFT      (29U)
/*! DCOC_INIT_OVRD - Override value for DCOC_INIT */
#define XCVR_TSM_OVRD2_DCOC_INIT_OVRD(x)         (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD2_DCOC_INIT_OVRD_SHIFT)) & XCVR_TSM_OVRD2_DCOC_INIT_OVRD_MASK)

#define XCVR_TSM_OVRD2_FREQ_TARG_LD_EN_OVRD_EN_MASK (0x40000000U)
#define XCVR_TSM_OVRD2_FREQ_TARG_LD_EN_OVRD_EN_SHIFT (30U)
/*! FREQ_TARG_LD_EN_OVRD_EN - Override control for FREQ_TARG_LD_EN
 *  0b0..Normal operation.
 *  0b1..Use the state of FREQ_TARG_LD_EN_OVRD to override the signal "freq_targ_ld_en".
 */
#define XCVR_TSM_OVRD2_FREQ_TARG_LD_EN_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD2_FREQ_TARG_LD_EN_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD2_FREQ_TARG_LD_EN_OVRD_EN_MASK)

#define XCVR_TSM_OVRD2_FREQ_TARG_LD_EN_OVRD_MASK (0x80000000U)
#define XCVR_TSM_OVRD2_FREQ_TARG_LD_EN_OVRD_SHIFT (31U)
/*! FREQ_TARG_LD_EN_OVRD - Override value for FREQ_TARG_LD_EN */
#define XCVR_TSM_OVRD2_FREQ_TARG_LD_EN_OVRD(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD2_FREQ_TARG_LD_EN_OVRD_SHIFT)) & XCVR_TSM_OVRD2_FREQ_TARG_LD_EN_OVRD_MASK)
/*! @} */

/*! @name OVRD3 - TSM OVERRIDE REGISTER 3 */
/*! @{ */

#define XCVR_TSM_OVRD3_TSM_SPARE0_EN_OVRD_EN_MASK (0x1U)
#define XCVR_TSM_OVRD3_TSM_SPARE0_EN_OVRD_EN_SHIFT (0U)
/*! TSM_SPARE0_EN_OVRD_EN - Override control for TSM_SPARE0_EN
 *  0b0..Normal operation.
 *  0b1..Use the state of TSM_SPARE0_EN_OVRD to override the signal "tsm_spare0_en".
 */
#define XCVR_TSM_OVRD3_TSM_SPARE0_EN_OVRD_EN(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD3_TSM_SPARE0_EN_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD3_TSM_SPARE0_EN_OVRD_EN_MASK)

#define XCVR_TSM_OVRD3_TSM_SPARE0_EN_OVRD_MASK   (0x2U)
#define XCVR_TSM_OVRD3_TSM_SPARE0_EN_OVRD_SHIFT  (1U)
/*! TSM_SPARE0_EN_OVRD - Override value for TSM_SPARE0_EN */
#define XCVR_TSM_OVRD3_TSM_SPARE0_EN_OVRD(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD3_TSM_SPARE0_EN_OVRD_SHIFT)) & XCVR_TSM_OVRD3_TSM_SPARE0_EN_OVRD_MASK)

#define XCVR_TSM_OVRD3_TSM_SPARE1_EN_OVRD_EN_MASK (0x4U)
#define XCVR_TSM_OVRD3_TSM_SPARE1_EN_OVRD_EN_SHIFT (2U)
/*! TSM_SPARE1_EN_OVRD_EN - Override control for TSM_SPARE1_EN
 *  0b0..Normal operation.
 *  0b1..Use the state of TSM_SPARE1_EN_OVRD to override the signal "tsm_spare1_en".
 */
#define XCVR_TSM_OVRD3_TSM_SPARE1_EN_OVRD_EN(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD3_TSM_SPARE1_EN_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD3_TSM_SPARE1_EN_OVRD_EN_MASK)

#define XCVR_TSM_OVRD3_TSM_SPARE1_EN_OVRD_MASK   (0x8U)
#define XCVR_TSM_OVRD3_TSM_SPARE1_EN_OVRD_SHIFT  (3U)
/*! TSM_SPARE1_EN_OVRD - Override value for TSM_SPARE1_EN */
#define XCVR_TSM_OVRD3_TSM_SPARE1_EN_OVRD(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD3_TSM_SPARE1_EN_OVRD_SHIFT)) & XCVR_TSM_OVRD3_TSM_SPARE1_EN_OVRD_MASK)

#define XCVR_TSM_OVRD3_TSM_SPARE2_EN_OVRD_EN_MASK (0x10U)
#define XCVR_TSM_OVRD3_TSM_SPARE2_EN_OVRD_EN_SHIFT (4U)
/*! TSM_SPARE2_EN_OVRD_EN - Override control for TSM_SPARE2_EN
 *  0b0..Normal operation.
 *  0b1..Use the state of TSM_SPARE2_EN_OVRD to override the signal "tsm_spare2_en".
 */
#define XCVR_TSM_OVRD3_TSM_SPARE2_EN_OVRD_EN(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD3_TSM_SPARE2_EN_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD3_TSM_SPARE2_EN_OVRD_EN_MASK)

#define XCVR_TSM_OVRD3_TSM_SPARE2_EN_OVRD_MASK   (0x20U)
#define XCVR_TSM_OVRD3_TSM_SPARE2_EN_OVRD_SHIFT  (5U)
/*! TSM_SPARE2_EN_OVRD - Override value for TSM_SPARE2_EN */
#define XCVR_TSM_OVRD3_TSM_SPARE2_EN_OVRD(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD3_TSM_SPARE2_EN_OVRD_SHIFT)) & XCVR_TSM_OVRD3_TSM_SPARE2_EN_OVRD_MASK)

#define XCVR_TSM_OVRD3_TSM_SPARE3_EN_OVRD_EN_MASK (0x40U)
#define XCVR_TSM_OVRD3_TSM_SPARE3_EN_OVRD_EN_SHIFT (6U)
/*! TSM_SPARE3_EN_OVRD_EN - Override control for TSM_SPARE3_EN
 *  0b0..Normal operation.
 *  0b1..Use the state of TSM_SPARE3_EN_OVRD to override the signal "tsm_spare3_en".
 */
#define XCVR_TSM_OVRD3_TSM_SPARE3_EN_OVRD_EN(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD3_TSM_SPARE3_EN_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD3_TSM_SPARE3_EN_OVRD_EN_MASK)

#define XCVR_TSM_OVRD3_TSM_SPARE3_EN_OVRD_MASK   (0x80U)
#define XCVR_TSM_OVRD3_TSM_SPARE3_EN_OVRD_SHIFT  (7U)
/*! TSM_SPARE3_EN_OVRD - Override value for TSM_SPARE3_EN */
#define XCVR_TSM_OVRD3_TSM_SPARE3_EN_OVRD(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD3_TSM_SPARE3_EN_OVRD_SHIFT)) & XCVR_TSM_OVRD3_TSM_SPARE3_EN_OVRD_MASK)

#define XCVR_TSM_OVRD3_RXTX_AUXPLL_BIAS_EN_OVRD_EN_MASK (0x100U)
#define XCVR_TSM_OVRD3_RXTX_AUXPLL_BIAS_EN_OVRD_EN_SHIFT (8U)
/*! RXTX_AUXPLL_BIAS_EN_OVRD_EN - Override control for RXTX_AUXPLL_BIAS_EN
 *  0b0..Normal operation.
 *  0b1..Use the state of RXTX_AUXPLL_BIAS_EN_OVRD to override the signal "rxtx_auxpll_bias_en".
 */
#define XCVR_TSM_OVRD3_RXTX_AUXPLL_BIAS_EN_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD3_RXTX_AUXPLL_BIAS_EN_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD3_RXTX_AUXPLL_BIAS_EN_OVRD_EN_MASK)

#define XCVR_TSM_OVRD3_RXTX_AUXPLL_BIAS_EN_OVRD_MASK (0x200U)
#define XCVR_TSM_OVRD3_RXTX_AUXPLL_BIAS_EN_OVRD_SHIFT (9U)
/*! RXTX_AUXPLL_BIAS_EN_OVRD - Override value for RXTX_AUXPLL_BIAS_EN */
#define XCVR_TSM_OVRD3_RXTX_AUXPLL_BIAS_EN_OVRD(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD3_RXTX_AUXPLL_BIAS_EN_OVRD_SHIFT)) & XCVR_TSM_OVRD3_RXTX_AUXPLL_BIAS_EN_OVRD_MASK)

#define XCVR_TSM_OVRD3_RXTX_AUXPLL_VCO_EN_OVRD_EN_MASK (0x400U)
#define XCVR_TSM_OVRD3_RXTX_AUXPLL_VCO_EN_OVRD_EN_SHIFT (10U)
/*! RXTX_AUXPLL_VCO_EN_OVRD_EN - Override control for RXTX_AUXPLL_VCO_EN
 *  0b0..Normal operation.
 *  0b1..Use the state of RXTX_AUXPLL_VCO_EN_OVRD to override the signal "rxtx_auxpll_vco_en".
 */
#define XCVR_TSM_OVRD3_RXTX_AUXPLL_VCO_EN_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD3_RXTX_AUXPLL_VCO_EN_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD3_RXTX_AUXPLL_VCO_EN_OVRD_EN_MASK)

#define XCVR_TSM_OVRD3_RXTX_AUXPLL_VCO_EN_OVRD_MASK (0x800U)
#define XCVR_TSM_OVRD3_RXTX_AUXPLL_VCO_EN_OVRD_SHIFT (11U)
/*! RXTX_AUXPLL_VCO_EN_OVRD - Override value for RXTX_AUXPLL_VCO_EN */
#define XCVR_TSM_OVRD3_RXTX_AUXPLL_VCO_EN_OVRD(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD3_RXTX_AUXPLL_VCO_EN_OVRD_SHIFT)) & XCVR_TSM_OVRD3_RXTX_AUXPLL_VCO_EN_OVRD_MASK)

#define XCVR_TSM_OVRD3_RXTX_AUXPLL_FCAL_EN_OVRD_EN_MASK (0x1000U)
#define XCVR_TSM_OVRD3_RXTX_AUXPLL_FCAL_EN_OVRD_EN_SHIFT (12U)
/*! RXTX_AUXPLL_FCAL_EN_OVRD_EN - Override control for RXTX_AUXPLL_FCAL_EN
 *  0b0..Normal operation.
 *  0b1..Use the state of RXTX_AUXPLL_FCAL_EN_OVRD to override the signal "rxtx_auxpll_fcal_en".
 */
#define XCVR_TSM_OVRD3_RXTX_AUXPLL_FCAL_EN_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD3_RXTX_AUXPLL_FCAL_EN_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD3_RXTX_AUXPLL_FCAL_EN_OVRD_EN_MASK)

#define XCVR_TSM_OVRD3_RXTX_AUXPLL_FCAL_EN_OVRD_MASK (0x2000U)
#define XCVR_TSM_OVRD3_RXTX_AUXPLL_FCAL_EN_OVRD_SHIFT (13U)
/*! RXTX_AUXPLL_FCAL_EN_OVRD - Override value for RXTX_AUXPLL_FCAL_EN */
#define XCVR_TSM_OVRD3_RXTX_AUXPLL_FCAL_EN_OVRD(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD3_RXTX_AUXPLL_FCAL_EN_OVRD_SHIFT)) & XCVR_TSM_OVRD3_RXTX_AUXPLL_FCAL_EN_OVRD_MASK)

#define XCVR_TSM_OVRD3_RXTX_AUXPLL_LF_EN_OVRD_EN_MASK (0x4000U)
#define XCVR_TSM_OVRD3_RXTX_AUXPLL_LF_EN_OVRD_EN_SHIFT (14U)
/*! RXTX_AUXPLL_LF_EN_OVRD_EN - Override control for RXTX_AUXPLL_LF_EN
 *  0b0..Normal operation.
 *  0b1..Use the state of RXTX_AUXPLL_LF_EN_OVRD to override the signal "rxtx_auxpll_lf_en".
 */
#define XCVR_TSM_OVRD3_RXTX_AUXPLL_LF_EN_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD3_RXTX_AUXPLL_LF_EN_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD3_RXTX_AUXPLL_LF_EN_OVRD_EN_MASK)

#define XCVR_TSM_OVRD3_RXTX_AUXPLL_LF_EN_OVRD_MASK (0x8000U)
#define XCVR_TSM_OVRD3_RXTX_AUXPLL_LF_EN_OVRD_SHIFT (15U)
/*! RXTX_AUXPLL_LF_EN_OVRD - Override value for RXTX_AUXPLL_LF_EN */
#define XCVR_TSM_OVRD3_RXTX_AUXPLL_LF_EN_OVRD(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD3_RXTX_AUXPLL_LF_EN_OVRD_SHIFT)) & XCVR_TSM_OVRD3_RXTX_AUXPLL_LF_EN_OVRD_MASK)

#define XCVR_TSM_OVRD3_RXTX_AUXPLL_PD_EN_OVRD_EN_MASK (0x10000U)
#define XCVR_TSM_OVRD3_RXTX_AUXPLL_PD_EN_OVRD_EN_SHIFT (16U)
/*! RXTX_AUXPLL_PD_EN_OVRD_EN - Override control for RXTX_AUXPLL_PD_EN
 *  0b0..Normal operation.
 *  0b1..Use the state of RXTX_AUXPLL_PD_EN_OVRD to override the signal "rxtx_auxpll_pd_en".
 */
#define XCVR_TSM_OVRD3_RXTX_AUXPLL_PD_EN_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD3_RXTX_AUXPLL_PD_EN_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD3_RXTX_AUXPLL_PD_EN_OVRD_EN_MASK)

#define XCVR_TSM_OVRD3_RXTX_AUXPLL_PD_EN_OVRD_MASK (0x20000U)
#define XCVR_TSM_OVRD3_RXTX_AUXPLL_PD_EN_OVRD_SHIFT (17U)
/*! RXTX_AUXPLL_PD_EN_OVRD - Override value for RXTX_AUXPLL_PD_EN */
#define XCVR_TSM_OVRD3_RXTX_AUXPLL_PD_EN_OVRD(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD3_RXTX_AUXPLL_PD_EN_OVRD_SHIFT)) & XCVR_TSM_OVRD3_RXTX_AUXPLL_PD_EN_OVRD_MASK)

#define XCVR_TSM_OVRD3_RXTX_AUXPLL_PD_LF_FILTER_CHARGE_EN_OVRD_EN_MASK (0x40000U)
#define XCVR_TSM_OVRD3_RXTX_AUXPLL_PD_LF_FILTER_CHARGE_EN_OVRD_EN_SHIFT (18U)
/*! RXTX_AUXPLL_PD_LF_FILTER_CHARGE_EN_OVRD_EN - Override control for RXTX_AUXPLL_PD_LF_FILTER_CHARGE_EN
 *  0b0..Normal operation.
 *  0b1..Use the state of RXTX_AUXPLL_PD_LF_FILTER_CHARGE_EN_OVRD to override the signal "rxtx_auxpll_pd_lf_filter_charge_en".
 */
#define XCVR_TSM_OVRD3_RXTX_AUXPLL_PD_LF_FILTER_CHARGE_EN_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD3_RXTX_AUXPLL_PD_LF_FILTER_CHARGE_EN_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD3_RXTX_AUXPLL_PD_LF_FILTER_CHARGE_EN_OVRD_EN_MASK)

#define XCVR_TSM_OVRD3_RXTX_AUXPLL_PD_LF_FILTER_CHARGE_EN_OVRD_MASK (0x80000U)
#define XCVR_TSM_OVRD3_RXTX_AUXPLL_PD_LF_FILTER_CHARGE_EN_OVRD_SHIFT (19U)
/*! RXTX_AUXPLL_PD_LF_FILTER_CHARGE_EN_OVRD - Override value for RXTX_AUXPLL_PD_LF_FILTER_CHARGE_EN */
#define XCVR_TSM_OVRD3_RXTX_AUXPLL_PD_LF_FILTER_CHARGE_EN_OVRD(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD3_RXTX_AUXPLL_PD_LF_FILTER_CHARGE_EN_OVRD_SHIFT)) & XCVR_TSM_OVRD3_RXTX_AUXPLL_PD_LF_FILTER_CHARGE_EN_OVRD_MASK)

#define XCVR_TSM_OVRD3_RXTX_AUXPLL_ADC_BUF_EN_OVRD_EN_MASK (0x100000U)
#define XCVR_TSM_OVRD3_RXTX_AUXPLL_ADC_BUF_EN_OVRD_EN_SHIFT (20U)
/*! RXTX_AUXPLL_ADC_BUF_EN_OVRD_EN - Override control for RXTX_AUXPLL_ADC_BUF_EN
 *  0b0..Normal operation.
 *  0b1..Use the state of RXTX_AUXPLL_ADC_BUF_EN_OVRD to override the signal "rxtx_auxpll_adc_buf_en".
 */
#define XCVR_TSM_OVRD3_RXTX_AUXPLL_ADC_BUF_EN_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD3_RXTX_AUXPLL_ADC_BUF_EN_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD3_RXTX_AUXPLL_ADC_BUF_EN_OVRD_EN_MASK)

#define XCVR_TSM_OVRD3_RXTX_AUXPLL_ADC_BUF_EN_OVRD_MASK (0x200000U)
#define XCVR_TSM_OVRD3_RXTX_AUXPLL_ADC_BUF_EN_OVRD_SHIFT (21U)
/*! RXTX_AUXPLL_ADC_BUF_EN_OVRD - Override value for RXTX_AUXPLL_ADC_BUF_EN */
#define XCVR_TSM_OVRD3_RXTX_AUXPLL_ADC_BUF_EN_OVRD(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD3_RXTX_AUXPLL_ADC_BUF_EN_OVRD_SHIFT)) & XCVR_TSM_OVRD3_RXTX_AUXPLL_ADC_BUF_EN_OVRD_MASK)

#define XCVR_TSM_OVRD3_RXTX_AUXPLL_DIG_BUF_EN_OVRD_EN_MASK (0x400000U)
#define XCVR_TSM_OVRD3_RXTX_AUXPLL_DIG_BUF_EN_OVRD_EN_SHIFT (22U)
/*! RXTX_AUXPLL_DIG_BUF_EN_OVRD_EN - Override control for RXTX_AUXPLL_DIG_BUF_EN
 *  0b0..Normal operation.
 *  0b1..Use the state of RXTX_AUXPLL_DIG_BUF_EN_OVRD to override the signal "rxtx_auxpll_dig_buf_en".
 */
#define XCVR_TSM_OVRD3_RXTX_AUXPLL_DIG_BUF_EN_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD3_RXTX_AUXPLL_DIG_BUF_EN_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD3_RXTX_AUXPLL_DIG_BUF_EN_OVRD_EN_MASK)

#define XCVR_TSM_OVRD3_RXTX_AUXPLL_DIG_BUF_EN_OVRD_MASK (0x800000U)
#define XCVR_TSM_OVRD3_RXTX_AUXPLL_DIG_BUF_EN_OVRD_SHIFT (23U)
/*! RXTX_AUXPLL_DIG_BUF_EN_OVRD - Override value for RXTX_AUXPLL_DIG_BUF_EN */
#define XCVR_TSM_OVRD3_RXTX_AUXPLL_DIG_BUF_EN_OVRD(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD3_RXTX_AUXPLL_DIG_BUF_EN_OVRD_SHIFT)) & XCVR_TSM_OVRD3_RXTX_AUXPLL_DIG_BUF_EN_OVRD_MASK)

#define XCVR_TSM_OVRD3_RXTX_RCCAL_EN_OVRD_EN_MASK (0x1000000U)
#define XCVR_TSM_OVRD3_RXTX_RCCAL_EN_OVRD_EN_SHIFT (24U)
/*! RXTX_RCCAL_EN_OVRD_EN - Override control for RXTX_RCCAL_EN
 *  0b0..Normal operation.
 *  0b1..Use the state of RXTX_RCCAL_EN_OVRD to override the signal "rxtx_rccal_en".
 */
#define XCVR_TSM_OVRD3_RXTX_RCCAL_EN_OVRD_EN(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD3_RXTX_RCCAL_EN_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD3_RXTX_RCCAL_EN_OVRD_EN_MASK)

#define XCVR_TSM_OVRD3_RXTX_RCCAL_EN_OVRD_MASK   (0x2000000U)
#define XCVR_TSM_OVRD3_RXTX_RCCAL_EN_OVRD_SHIFT  (25U)
/*! RXTX_RCCAL_EN_OVRD - Override value for RXTX_RCCAL_EN */
#define XCVR_TSM_OVRD3_RXTX_RCCAL_EN_OVRD(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD3_RXTX_RCCAL_EN_OVRD_SHIFT)) & XCVR_TSM_OVRD3_RXTX_RCCAL_EN_OVRD_MASK)

#define XCVR_TSM_OVRD3_TX_HPM_DAC_EN_OVRD_EN_MASK (0x4000000U)
#define XCVR_TSM_OVRD3_TX_HPM_DAC_EN_OVRD_EN_SHIFT (26U)
/*! TX_HPM_DAC_EN_OVRD_EN - Override control for TX_HPM_DAC_EN
 *  0b0..Normal operation.
 *  0b1..Use the state of TX_HPM_DAC_EN_OVRD to override the signal "tx_hpm_dac_en".
 */
#define XCVR_TSM_OVRD3_TX_HPM_DAC_EN_OVRD_EN(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD3_TX_HPM_DAC_EN_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD3_TX_HPM_DAC_EN_OVRD_EN_MASK)

#define XCVR_TSM_OVRD3_TX_HPM_DAC_EN_OVRD_MASK   (0x8000000U)
#define XCVR_TSM_OVRD3_TX_HPM_DAC_EN_OVRD_SHIFT  (27U)
/*! TX_HPM_DAC_EN_OVRD - Override value for TX_HPM_DAC_EN */
#define XCVR_TSM_OVRD3_TX_HPM_DAC_EN_OVRD(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD3_TX_HPM_DAC_EN_OVRD_SHIFT)) & XCVR_TSM_OVRD3_TX_HPM_DAC_EN_OVRD_MASK)

#define XCVR_TSM_OVRD3_TX_MODE_OVRD_EN_MASK      (0x10000000U)
#define XCVR_TSM_OVRD3_TX_MODE_OVRD_EN_SHIFT     (28U)
/*! TX_MODE_OVRD_EN - Override control for TX_MODE
 *  0b0..Normal operation.
 *  0b1..Use the state of TX_MODE_OVRD to override the signal "tx_mode".
 */
#define XCVR_TSM_OVRD3_TX_MODE_OVRD_EN(x)        (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD3_TX_MODE_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD3_TX_MODE_OVRD_EN_MASK)

#define XCVR_TSM_OVRD3_TX_MODE_OVRD_MASK         (0x20000000U)
#define XCVR_TSM_OVRD3_TX_MODE_OVRD_SHIFT        (29U)
/*! TX_MODE_OVRD - Override value for TX_MODE */
#define XCVR_TSM_OVRD3_TX_MODE_OVRD(x)           (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD3_TX_MODE_OVRD_SHIFT)) & XCVR_TSM_OVRD3_TX_MODE_OVRD_MASK)

#define XCVR_TSM_OVRD3_RX_MODE_OVRD_EN_MASK      (0x40000000U)
#define XCVR_TSM_OVRD3_RX_MODE_OVRD_EN_SHIFT     (30U)
/*! RX_MODE_OVRD_EN - Override control for RX_MODE
 *  0b0..Normal operation.
 *  0b1..Use the state of RX_MODE_OVRD to override the signal "rx_mode".
 */
#define XCVR_TSM_OVRD3_RX_MODE_OVRD_EN(x)        (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD3_RX_MODE_OVRD_EN_SHIFT)) & XCVR_TSM_OVRD3_RX_MODE_OVRD_EN_MASK)

#define XCVR_TSM_OVRD3_RX_MODE_OVRD_MASK         (0x80000000U)
#define XCVR_TSM_OVRD3_RX_MODE_OVRD_SHIFT        (31U)
/*! RX_MODE_OVRD - Override value for RX_MODE */
#define XCVR_TSM_OVRD3_RX_MODE_OVRD(x)           (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_OVRD3_RX_MODE_OVRD_SHIFT)) & XCVR_TSM_OVRD3_RX_MODE_OVRD_MASK)
/*! @} */

/*! @name PA_POWER - PA POWER */
/*! @{ */

#define XCVR_TSM_PA_POWER_PA_POWER_MASK          (0x3FU)
#define XCVR_TSM_PA_POWER_PA_POWER_SHIFT         (0U)
/*! PA_POWER - PA POWER */
#define XCVR_TSM_PA_POWER_PA_POWER(x)            (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_PA_POWER_PA_POWER_SHIFT)) & XCVR_TSM_PA_POWER_PA_POWER_MASK)
/*! @} */

/*! @name PA_RAMP_TBL0 - PA RAMP TABLE 0 */
/*! @{ */

#define XCVR_TSM_PA_RAMP_TBL0_PA_RAMP0_MASK      (0x3FU)
#define XCVR_TSM_PA_RAMP_TBL0_PA_RAMP0_SHIFT     (0U)
/*! PA_RAMP0 - PA_RAMP0 */
#define XCVR_TSM_PA_RAMP_TBL0_PA_RAMP0(x)        (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_PA_RAMP_TBL0_PA_RAMP0_SHIFT)) & XCVR_TSM_PA_RAMP_TBL0_PA_RAMP0_MASK)

#define XCVR_TSM_PA_RAMP_TBL0_PA_RAMP1_MASK      (0x3F00U)
#define XCVR_TSM_PA_RAMP_TBL0_PA_RAMP1_SHIFT     (8U)
/*! PA_RAMP1 - PA_RAMP1 */
#define XCVR_TSM_PA_RAMP_TBL0_PA_RAMP1(x)        (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_PA_RAMP_TBL0_PA_RAMP1_SHIFT)) & XCVR_TSM_PA_RAMP_TBL0_PA_RAMP1_MASK)

#define XCVR_TSM_PA_RAMP_TBL0_PA_RAMP2_MASK      (0x3F0000U)
#define XCVR_TSM_PA_RAMP_TBL0_PA_RAMP2_SHIFT     (16U)
/*! PA_RAMP2 - PA_RAMP2 */
#define XCVR_TSM_PA_RAMP_TBL0_PA_RAMP2(x)        (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_PA_RAMP_TBL0_PA_RAMP2_SHIFT)) & XCVR_TSM_PA_RAMP_TBL0_PA_RAMP2_MASK)

#define XCVR_TSM_PA_RAMP_TBL0_PA_RAMP3_MASK      (0x3F000000U)
#define XCVR_TSM_PA_RAMP_TBL0_PA_RAMP3_SHIFT     (24U)
/*! PA_RAMP3 - PA_RAMP3 */
#define XCVR_TSM_PA_RAMP_TBL0_PA_RAMP3(x)        (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_PA_RAMP_TBL0_PA_RAMP3_SHIFT)) & XCVR_TSM_PA_RAMP_TBL0_PA_RAMP3_MASK)
/*! @} */

/*! @name PA_RAMP_TBL1 - PA RAMP TABLE 1 */
/*! @{ */

#define XCVR_TSM_PA_RAMP_TBL1_PA_RAMP4_MASK      (0x3FU)
#define XCVR_TSM_PA_RAMP_TBL1_PA_RAMP4_SHIFT     (0U)
/*! PA_RAMP4 - PA_RAMP4 */
#define XCVR_TSM_PA_RAMP_TBL1_PA_RAMP4(x)        (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_PA_RAMP_TBL1_PA_RAMP4_SHIFT)) & XCVR_TSM_PA_RAMP_TBL1_PA_RAMP4_MASK)

#define XCVR_TSM_PA_RAMP_TBL1_PA_RAMP5_MASK      (0x3F00U)
#define XCVR_TSM_PA_RAMP_TBL1_PA_RAMP5_SHIFT     (8U)
/*! PA_RAMP5 - PA_RAMP5 */
#define XCVR_TSM_PA_RAMP_TBL1_PA_RAMP5(x)        (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_PA_RAMP_TBL1_PA_RAMP5_SHIFT)) & XCVR_TSM_PA_RAMP_TBL1_PA_RAMP5_MASK)

#define XCVR_TSM_PA_RAMP_TBL1_PA_RAMP6_MASK      (0x3F0000U)
#define XCVR_TSM_PA_RAMP_TBL1_PA_RAMP6_SHIFT     (16U)
/*! PA_RAMP6 - PA_RAMP6 */
#define XCVR_TSM_PA_RAMP_TBL1_PA_RAMP6(x)        (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_PA_RAMP_TBL1_PA_RAMP6_SHIFT)) & XCVR_TSM_PA_RAMP_TBL1_PA_RAMP6_MASK)

#define XCVR_TSM_PA_RAMP_TBL1_PA_RAMP7_MASK      (0x3F000000U)
#define XCVR_TSM_PA_RAMP_TBL1_PA_RAMP7_SHIFT     (24U)
/*! PA_RAMP7 - PA_RAMP7 */
#define XCVR_TSM_PA_RAMP_TBL1_PA_RAMP7(x)        (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_PA_RAMP_TBL1_PA_RAMP7_SHIFT)) & XCVR_TSM_PA_RAMP_TBL1_PA_RAMP7_MASK)
/*! @} */

/*! @name RECYCLE_COUNT - TSM RECYCLE COUNT */
/*! @{ */

#define XCVR_TSM_RECYCLE_COUNT_RECYCLE_COUNT0_MASK (0xFFU)
#define XCVR_TSM_RECYCLE_COUNT_RECYCLE_COUNT0_SHIFT (0U)
/*! RECYCLE_COUNT0 - TSM RX Recycle Count 0 */
#define XCVR_TSM_RECYCLE_COUNT_RECYCLE_COUNT0(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_RECYCLE_COUNT_RECYCLE_COUNT0_SHIFT)) & XCVR_TSM_RECYCLE_COUNT_RECYCLE_COUNT0_MASK)

#define XCVR_TSM_RECYCLE_COUNT_RECYCLE_COUNT1_MASK (0xFF00U)
#define XCVR_TSM_RECYCLE_COUNT_RECYCLE_COUNT1_SHIFT (8U)
/*! RECYCLE_COUNT1 - TSM RX Recycle Count 1 */
#define XCVR_TSM_RECYCLE_COUNT_RECYCLE_COUNT1(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_RECYCLE_COUNT_RECYCLE_COUNT1_SHIFT)) & XCVR_TSM_RECYCLE_COUNT_RECYCLE_COUNT1_MASK)

#define XCVR_TSM_RECYCLE_COUNT_RECYCLE_COUNT2_MASK (0xFF0000U)
#define XCVR_TSM_RECYCLE_COUNT_RECYCLE_COUNT2_SHIFT (16U)
/*! RECYCLE_COUNT2 - TSM RX Recycle Count 2 */
#define XCVR_TSM_RECYCLE_COUNT_RECYCLE_COUNT2(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_RECYCLE_COUNT_RECYCLE_COUNT2_SHIFT)) & XCVR_TSM_RECYCLE_COUNT_RECYCLE_COUNT2_MASK)
/*! @} */

/*! @name FAST_CTRL1 - TSM FAST WARMUP CONTROL REGISTER 1 */
/*! @{ */

#define XCVR_TSM_FAST_CTRL1_FAST_TX_WU_EN_MASK   (0x1U)
#define XCVR_TSM_FAST_CTRL1_FAST_TX_WU_EN_SHIFT  (0U)
/*! FAST_TX_WU_EN - Fast TSM TX Warmup Enable
 *  0b0..Fast TSM TX Warmups are disabled
 *  0b1..Fast TSM TX Warmups are enabled, if the RF channel has not changed since the last TX warmup, and for BLE
 *       mode, the RF channel is not an advertising channel.
 */
#define XCVR_TSM_FAST_CTRL1_FAST_TX_WU_EN(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_FAST_CTRL1_FAST_TX_WU_EN_SHIFT)) & XCVR_TSM_FAST_CTRL1_FAST_TX_WU_EN_MASK)

#define XCVR_TSM_FAST_CTRL1_FAST_RX_WU_EN_MASK   (0x2U)
#define XCVR_TSM_FAST_CTRL1_FAST_RX_WU_EN_SHIFT  (1U)
/*! FAST_RX_WU_EN - Fast TSM RX Warmup Enable
 *  0b0..Fast TSM RX Warmups are disabled
 *  0b1..Fast TSM RX Warmups are enabled, if the RF channel has not changed since the last RX warmup, and for BLE
 *       mode, the RF channel is not an advertising channel.
 */
#define XCVR_TSM_FAST_CTRL1_FAST_RX_WU_EN(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_FAST_CTRL1_FAST_RX_WU_EN_SHIFT)) & XCVR_TSM_FAST_CTRL1_FAST_RX_WU_EN_MASK)

#define XCVR_TSM_FAST_CTRL1_FAST_RX2TX_EN_MASK   (0x4U)
#define XCVR_TSM_FAST_CTRL1_FAST_RX2TX_EN_SHIFT  (2U)
/*! FAST_RX2TX_EN - Fast TSM RX-to-TX Transition Enable */
#define XCVR_TSM_FAST_CTRL1_FAST_RX2TX_EN(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_FAST_CTRL1_FAST_RX2TX_EN_SHIFT)) & XCVR_TSM_FAST_CTRL1_FAST_RX2TX_EN_MASK)

#define XCVR_TSM_FAST_CTRL1_FAST_WU_CLEAR_MASK   (0x8U)
#define XCVR_TSM_FAST_CTRL1_FAST_WU_CLEAR_SHIFT  (3U)
/*! FAST_WU_CLEAR - Fast TSM Warmup Clear State */
#define XCVR_TSM_FAST_CTRL1_FAST_WU_CLEAR(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_FAST_CTRL1_FAST_WU_CLEAR_SHIFT)) & XCVR_TSM_FAST_CTRL1_FAST_WU_CLEAR_MASK)

#define XCVR_TSM_FAST_CTRL1_FAST_RX2TX_START_MASK (0xFF00U)
#define XCVR_TSM_FAST_CTRL1_FAST_RX2TX_START_SHIFT (8U)
/*! FAST_RX2TX_START - TSM "Jump-to" point for a Fast TSM RX-to-TX Transition. */
#define XCVR_TSM_FAST_CTRL1_FAST_RX2TX_START(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_FAST_CTRL1_FAST_RX2TX_START_SHIFT)) & XCVR_TSM_FAST_CTRL1_FAST_RX2TX_START_MASK)
/*! @} */

/*! @name FAST_CTRL2 - TSM FAST WARMUP CONTROL REGISTER 2 */
/*! @{ */

#define XCVR_TSM_FAST_CTRL2_FAST_START_TX_MASK   (0xFFU)
#define XCVR_TSM_FAST_CTRL2_FAST_START_TX_SHIFT  (0U)
/*! FAST_START_TX - Fast TSM TX "Jump-from" Point */
#define XCVR_TSM_FAST_CTRL2_FAST_START_TX(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_FAST_CTRL2_FAST_START_TX_SHIFT)) & XCVR_TSM_FAST_CTRL2_FAST_START_TX_MASK)

#define XCVR_TSM_FAST_CTRL2_FAST_DEST_TX_MASK    (0xFF00U)
#define XCVR_TSM_FAST_CTRL2_FAST_DEST_TX_SHIFT   (8U)
/*! FAST_DEST_TX - Fast TSM TX "Jump-to" Point */
#define XCVR_TSM_FAST_CTRL2_FAST_DEST_TX(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_FAST_CTRL2_FAST_DEST_TX_SHIFT)) & XCVR_TSM_FAST_CTRL2_FAST_DEST_TX_MASK)

#define XCVR_TSM_FAST_CTRL2_FAST_START_RX_MASK   (0xFF0000U)
#define XCVR_TSM_FAST_CTRL2_FAST_START_RX_SHIFT  (16U)
/*! FAST_START_RX - Fast TSM RX "Jump-from" Point */
#define XCVR_TSM_FAST_CTRL2_FAST_START_RX(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_FAST_CTRL2_FAST_START_RX_SHIFT)) & XCVR_TSM_FAST_CTRL2_FAST_START_RX_MASK)

#define XCVR_TSM_FAST_CTRL2_FAST_DEST_RX_MASK    (0xFF000000U)
#define XCVR_TSM_FAST_CTRL2_FAST_DEST_RX_SHIFT   (24U)
/*! FAST_DEST_RX - Fast TSM RX "Jump-to" Point */
#define XCVR_TSM_FAST_CTRL2_FAST_DEST_RX(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_FAST_CTRL2_FAST_DEST_RX_SHIFT)) & XCVR_TSM_FAST_CTRL2_FAST_DEST_RX_MASK)
/*! @} */

/*! @name TIMING00 - TSM_TIMING00 */
/*! @{ */

#define XCVR_TSM_TIMING00_BB_LDO_HF_EN_TX_HI_MASK (0xFFU)
#define XCVR_TSM_TIMING00_BB_LDO_HF_EN_TX_HI_SHIFT (0U)
/*! BB_LDO_HF_EN_TX_HI - Assertion time setting for BB_LDO_HF_EN (TX) */
#define XCVR_TSM_TIMING00_BB_LDO_HF_EN_TX_HI(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING00_BB_LDO_HF_EN_TX_HI_SHIFT)) & XCVR_TSM_TIMING00_BB_LDO_HF_EN_TX_HI_MASK)

#define XCVR_TSM_TIMING00_BB_LDO_HF_EN_TX_LO_MASK (0xFF00U)
#define XCVR_TSM_TIMING00_BB_LDO_HF_EN_TX_LO_SHIFT (8U)
/*! BB_LDO_HF_EN_TX_LO - De-assertion time setting for BB_LDO_HF_EN (TX) */
#define XCVR_TSM_TIMING00_BB_LDO_HF_EN_TX_LO(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING00_BB_LDO_HF_EN_TX_LO_SHIFT)) & XCVR_TSM_TIMING00_BB_LDO_HF_EN_TX_LO_MASK)

#define XCVR_TSM_TIMING00_BB_LDO_HF_EN_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING00_BB_LDO_HF_EN_RX_HI_SHIFT (16U)
/*! BB_LDO_HF_EN_RX_HI - Assertion time setting for BB_LDO_HF_EN (RX) */
#define XCVR_TSM_TIMING00_BB_LDO_HF_EN_RX_HI(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING00_BB_LDO_HF_EN_RX_HI_SHIFT)) & XCVR_TSM_TIMING00_BB_LDO_HF_EN_RX_HI_MASK)

#define XCVR_TSM_TIMING00_BB_LDO_HF_EN_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING00_BB_LDO_HF_EN_RX_LO_SHIFT (24U)
/*! BB_LDO_HF_EN_RX_LO - De-assertion time setting for BB_LDO_HF_EN (RX) */
#define XCVR_TSM_TIMING00_BB_LDO_HF_EN_RX_LO(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING00_BB_LDO_HF_EN_RX_LO_SHIFT)) & XCVR_TSM_TIMING00_BB_LDO_HF_EN_RX_LO_MASK)
/*! @} */

/*! @name TIMING01 - TSM_TIMING01 */
/*! @{ */

#define XCVR_TSM_TIMING01_BB_LDO_ADCDAC_EN_TX_HI_MASK (0xFFU)
#define XCVR_TSM_TIMING01_BB_LDO_ADCDAC_EN_TX_HI_SHIFT (0U)
/*! BB_LDO_ADCDAC_EN_TX_HI - Assertion time setting for BB_LDO_ADCDAC_EN (TX) */
#define XCVR_TSM_TIMING01_BB_LDO_ADCDAC_EN_TX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING01_BB_LDO_ADCDAC_EN_TX_HI_SHIFT)) & XCVR_TSM_TIMING01_BB_LDO_ADCDAC_EN_TX_HI_MASK)

#define XCVR_TSM_TIMING01_BB_LDO_ADCDAC_EN_TX_LO_MASK (0xFF00U)
#define XCVR_TSM_TIMING01_BB_LDO_ADCDAC_EN_TX_LO_SHIFT (8U)
/*! BB_LDO_ADCDAC_EN_TX_LO - De-assertion time setting for BB_LDO_ADCDAC_EN (TX) */
#define XCVR_TSM_TIMING01_BB_LDO_ADCDAC_EN_TX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING01_BB_LDO_ADCDAC_EN_TX_LO_SHIFT)) & XCVR_TSM_TIMING01_BB_LDO_ADCDAC_EN_TX_LO_MASK)

#define XCVR_TSM_TIMING01_BB_LDO_ADCDAC_EN_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING01_BB_LDO_ADCDAC_EN_RX_HI_SHIFT (16U)
/*! BB_LDO_ADCDAC_EN_RX_HI - Assertion time setting for BB_LDO_ADCDAC_EN (RX) */
#define XCVR_TSM_TIMING01_BB_LDO_ADCDAC_EN_RX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING01_BB_LDO_ADCDAC_EN_RX_HI_SHIFT)) & XCVR_TSM_TIMING01_BB_LDO_ADCDAC_EN_RX_HI_MASK)

#define XCVR_TSM_TIMING01_BB_LDO_ADCDAC_EN_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING01_BB_LDO_ADCDAC_EN_RX_LO_SHIFT (24U)
/*! BB_LDO_ADCDAC_EN_RX_LO - De-assertion time setting for BB_LDO_ADCDAC_EN (RX) */
#define XCVR_TSM_TIMING01_BB_LDO_ADCDAC_EN_RX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING01_BB_LDO_ADCDAC_EN_RX_LO_SHIFT)) & XCVR_TSM_TIMING01_BB_LDO_ADCDAC_EN_RX_LO_MASK)
/*! @} */

/*! @name TIMING02 - TSM_TIMING02 */
/*! @{ */

#define XCVR_TSM_TIMING02_BB_LDO_BBA_EN_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING02_BB_LDO_BBA_EN_RX_HI_SHIFT (16U)
/*! BB_LDO_BBA_EN_RX_HI - Assertion time setting for BB_LDO_BBA_EN (RX) */
#define XCVR_TSM_TIMING02_BB_LDO_BBA_EN_RX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING02_BB_LDO_BBA_EN_RX_HI_SHIFT)) & XCVR_TSM_TIMING02_BB_LDO_BBA_EN_RX_HI_MASK)

#define XCVR_TSM_TIMING02_BB_LDO_BBA_EN_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING02_BB_LDO_BBA_EN_RX_LO_SHIFT (24U)
/*! BB_LDO_BBA_EN_RX_LO - De-assertion time setting for BB_LDO_BBA_EN (RX) */
#define XCVR_TSM_TIMING02_BB_LDO_BBA_EN_RX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING02_BB_LDO_BBA_EN_RX_LO_SHIFT)) & XCVR_TSM_TIMING02_BB_LDO_BBA_EN_RX_LO_MASK)
/*! @} */

/*! @name TIMING03 - TSM_TIMING03 */
/*! @{ */

#define XCVR_TSM_TIMING03_BB_LDO_PD_EN_TX_HI_MASK (0xFFU)
#define XCVR_TSM_TIMING03_BB_LDO_PD_EN_TX_HI_SHIFT (0U)
/*! BB_LDO_PD_EN_TX_HI - Assertion time setting for BB_LDO_PD_EN (TX) */
#define XCVR_TSM_TIMING03_BB_LDO_PD_EN_TX_HI(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING03_BB_LDO_PD_EN_TX_HI_SHIFT)) & XCVR_TSM_TIMING03_BB_LDO_PD_EN_TX_HI_MASK)

#define XCVR_TSM_TIMING03_BB_LDO_PD_EN_TX_LO_MASK (0xFF00U)
#define XCVR_TSM_TIMING03_BB_LDO_PD_EN_TX_LO_SHIFT (8U)
/*! BB_LDO_PD_EN_TX_LO - De-assertion time setting for BB_LDO_PD_EN (TX) */
#define XCVR_TSM_TIMING03_BB_LDO_PD_EN_TX_LO(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING03_BB_LDO_PD_EN_TX_LO_SHIFT)) & XCVR_TSM_TIMING03_BB_LDO_PD_EN_TX_LO_MASK)

#define XCVR_TSM_TIMING03_BB_LDO_PD_EN_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING03_BB_LDO_PD_EN_RX_HI_SHIFT (16U)
/*! BB_LDO_PD_EN_RX_HI - Assertion time setting for BB_LDO_PD_EN (RX) */
#define XCVR_TSM_TIMING03_BB_LDO_PD_EN_RX_HI(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING03_BB_LDO_PD_EN_RX_HI_SHIFT)) & XCVR_TSM_TIMING03_BB_LDO_PD_EN_RX_HI_MASK)

#define XCVR_TSM_TIMING03_BB_LDO_PD_EN_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING03_BB_LDO_PD_EN_RX_LO_SHIFT (24U)
/*! BB_LDO_PD_EN_RX_LO - De-assertion time setting for BB_LDO_PD_EN (RX) */
#define XCVR_TSM_TIMING03_BB_LDO_PD_EN_RX_LO(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING03_BB_LDO_PD_EN_RX_LO_SHIFT)) & XCVR_TSM_TIMING03_BB_LDO_PD_EN_RX_LO_MASK)
/*! @} */

/*! @name TIMING04 - TSM_TIMING04 */
/*! @{ */

#define XCVR_TSM_TIMING04_BB_LDO_FDBK_EN_TX_HI_MASK (0xFFU)
#define XCVR_TSM_TIMING04_BB_LDO_FDBK_EN_TX_HI_SHIFT (0U)
/*! BB_LDO_FDBK_EN_TX_HI - Assertion time setting for BB_LDO_FDBK_EN (TX) */
#define XCVR_TSM_TIMING04_BB_LDO_FDBK_EN_TX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING04_BB_LDO_FDBK_EN_TX_HI_SHIFT)) & XCVR_TSM_TIMING04_BB_LDO_FDBK_EN_TX_HI_MASK)

#define XCVR_TSM_TIMING04_BB_LDO_FDBK_EN_TX_LO_MASK (0xFF00U)
#define XCVR_TSM_TIMING04_BB_LDO_FDBK_EN_TX_LO_SHIFT (8U)
/*! BB_LDO_FDBK_EN_TX_LO - De-assertion time setting for BB_LDO_FDBK_EN (TX) */
#define XCVR_TSM_TIMING04_BB_LDO_FDBK_EN_TX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING04_BB_LDO_FDBK_EN_TX_LO_SHIFT)) & XCVR_TSM_TIMING04_BB_LDO_FDBK_EN_TX_LO_MASK)

#define XCVR_TSM_TIMING04_BB_LDO_FDBK_EN_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING04_BB_LDO_FDBK_EN_RX_HI_SHIFT (16U)
/*! BB_LDO_FDBK_EN_RX_HI - Assertion time setting for BB_LDO_FDBK_EN (RX) */
#define XCVR_TSM_TIMING04_BB_LDO_FDBK_EN_RX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING04_BB_LDO_FDBK_EN_RX_HI_SHIFT)) & XCVR_TSM_TIMING04_BB_LDO_FDBK_EN_RX_HI_MASK)

#define XCVR_TSM_TIMING04_BB_LDO_FDBK_EN_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING04_BB_LDO_FDBK_EN_RX_LO_SHIFT (24U)
/*! BB_LDO_FDBK_EN_RX_LO - De-assertion time setting for BB_LDO_FDBK_EN (RX) */
#define XCVR_TSM_TIMING04_BB_LDO_FDBK_EN_RX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING04_BB_LDO_FDBK_EN_RX_LO_SHIFT)) & XCVR_TSM_TIMING04_BB_LDO_FDBK_EN_RX_LO_MASK)
/*! @} */

/*! @name TIMING05 - TSM_TIMING05 */
/*! @{ */

#define XCVR_TSM_TIMING05_BB_LDO_VCOLO_EN_TX_HI_MASK (0xFFU)
#define XCVR_TSM_TIMING05_BB_LDO_VCOLO_EN_TX_HI_SHIFT (0U)
/*! BB_LDO_VCOLO_EN_TX_HI - Assertion time setting for BB_LDO_VCOLO_EN (TX) */
#define XCVR_TSM_TIMING05_BB_LDO_VCOLO_EN_TX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING05_BB_LDO_VCOLO_EN_TX_HI_SHIFT)) & XCVR_TSM_TIMING05_BB_LDO_VCOLO_EN_TX_HI_MASK)

#define XCVR_TSM_TIMING05_BB_LDO_VCOLO_EN_TX_LO_MASK (0xFF00U)
#define XCVR_TSM_TIMING05_BB_LDO_VCOLO_EN_TX_LO_SHIFT (8U)
/*! BB_LDO_VCOLO_EN_TX_LO - De-assertion time setting for BB_LDO_VCOLO_EN (TX) */
#define XCVR_TSM_TIMING05_BB_LDO_VCOLO_EN_TX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING05_BB_LDO_VCOLO_EN_TX_LO_SHIFT)) & XCVR_TSM_TIMING05_BB_LDO_VCOLO_EN_TX_LO_MASK)

#define XCVR_TSM_TIMING05_BB_LDO_VCOLO_EN_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING05_BB_LDO_VCOLO_EN_RX_HI_SHIFT (16U)
/*! BB_LDO_VCOLO_EN_RX_HI - Assertion time setting for BB_LDO_VCOLO_EN (RX) */
#define XCVR_TSM_TIMING05_BB_LDO_VCOLO_EN_RX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING05_BB_LDO_VCOLO_EN_RX_HI_SHIFT)) & XCVR_TSM_TIMING05_BB_LDO_VCOLO_EN_RX_HI_MASK)

#define XCVR_TSM_TIMING05_BB_LDO_VCOLO_EN_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING05_BB_LDO_VCOLO_EN_RX_LO_SHIFT (24U)
/*! BB_LDO_VCOLO_EN_RX_LO - De-assertion time setting for BB_LDO_VCOLO_EN (RX) */
#define XCVR_TSM_TIMING05_BB_LDO_VCOLO_EN_RX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING05_BB_LDO_VCOLO_EN_RX_LO_SHIFT)) & XCVR_TSM_TIMING05_BB_LDO_VCOLO_EN_RX_LO_MASK)
/*! @} */

/*! @name TIMING06 - TSM_TIMING06 */
/*! @{ */

#define XCVR_TSM_TIMING06_BB_LDO_VTREF_EN_TX_HI_MASK (0xFFU)
#define XCVR_TSM_TIMING06_BB_LDO_VTREF_EN_TX_HI_SHIFT (0U)
/*! BB_LDO_VTREF_EN_TX_HI - Assertion time setting for BB_LDO_VTREF_EN (TX) */
#define XCVR_TSM_TIMING06_BB_LDO_VTREF_EN_TX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING06_BB_LDO_VTREF_EN_TX_HI_SHIFT)) & XCVR_TSM_TIMING06_BB_LDO_VTREF_EN_TX_HI_MASK)

#define XCVR_TSM_TIMING06_BB_LDO_VTREF_EN_TX_LO_MASK (0xFF00U)
#define XCVR_TSM_TIMING06_BB_LDO_VTREF_EN_TX_LO_SHIFT (8U)
/*! BB_LDO_VTREF_EN_TX_LO - De-assertion time setting for BB_LDO_VTREF_EN (TX) */
#define XCVR_TSM_TIMING06_BB_LDO_VTREF_EN_TX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING06_BB_LDO_VTREF_EN_TX_LO_SHIFT)) & XCVR_TSM_TIMING06_BB_LDO_VTREF_EN_TX_LO_MASK)

#define XCVR_TSM_TIMING06_BB_LDO_VTREF_EN_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING06_BB_LDO_VTREF_EN_RX_HI_SHIFT (16U)
/*! BB_LDO_VTREF_EN_RX_HI - Assertion time setting for BB_LDO_VTREF_EN (RX) */
#define XCVR_TSM_TIMING06_BB_LDO_VTREF_EN_RX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING06_BB_LDO_VTREF_EN_RX_HI_SHIFT)) & XCVR_TSM_TIMING06_BB_LDO_VTREF_EN_RX_HI_MASK)

#define XCVR_TSM_TIMING06_BB_LDO_VTREF_EN_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING06_BB_LDO_VTREF_EN_RX_LO_SHIFT (24U)
/*! BB_LDO_VTREF_EN_RX_LO - De-assertion time setting for BB_LDO_VTREF_EN (RX) */
#define XCVR_TSM_TIMING06_BB_LDO_VTREF_EN_RX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING06_BB_LDO_VTREF_EN_RX_LO_SHIFT)) & XCVR_TSM_TIMING06_BB_LDO_VTREF_EN_RX_LO_MASK)
/*! @} */

/*! @name TIMING07 - TSM_TIMING07 */
/*! @{ */

#define XCVR_TSM_TIMING07_BB_LDO_FDBK_BLEED_EN_TX_HI_MASK (0xFFU)
#define XCVR_TSM_TIMING07_BB_LDO_FDBK_BLEED_EN_TX_HI_SHIFT (0U)
/*! BB_LDO_FDBK_BLEED_EN_TX_HI - Assertion time setting for BB_LDO_FDBK_BLEED_EN (TX) */
#define XCVR_TSM_TIMING07_BB_LDO_FDBK_BLEED_EN_TX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING07_BB_LDO_FDBK_BLEED_EN_TX_HI_SHIFT)) & XCVR_TSM_TIMING07_BB_LDO_FDBK_BLEED_EN_TX_HI_MASK)

#define XCVR_TSM_TIMING07_BB_LDO_FDBK_BLEED_EN_TX_LO_MASK (0xFF00U)
#define XCVR_TSM_TIMING07_BB_LDO_FDBK_BLEED_EN_TX_LO_SHIFT (8U)
/*! BB_LDO_FDBK_BLEED_EN_TX_LO - De-assertion time setting for BB_LDO_FDBK_BLEED_EN (TX) */
#define XCVR_TSM_TIMING07_BB_LDO_FDBK_BLEED_EN_TX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING07_BB_LDO_FDBK_BLEED_EN_TX_LO_SHIFT)) & XCVR_TSM_TIMING07_BB_LDO_FDBK_BLEED_EN_TX_LO_MASK)

#define XCVR_TSM_TIMING07_BB_LDO_FDBK_BLEED_EN_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING07_BB_LDO_FDBK_BLEED_EN_RX_HI_SHIFT (16U)
/*! BB_LDO_FDBK_BLEED_EN_RX_HI - Assertion time setting for BB_LDO_FDBK_BLEED_EN (RX) */
#define XCVR_TSM_TIMING07_BB_LDO_FDBK_BLEED_EN_RX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING07_BB_LDO_FDBK_BLEED_EN_RX_HI_SHIFT)) & XCVR_TSM_TIMING07_BB_LDO_FDBK_BLEED_EN_RX_HI_MASK)

#define XCVR_TSM_TIMING07_BB_LDO_FDBK_BLEED_EN_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING07_BB_LDO_FDBK_BLEED_EN_RX_LO_SHIFT (24U)
/*! BB_LDO_FDBK_BLEED_EN_RX_LO - De-assertion time setting for BB_LDO_FDBK_BLEED_EN (RX) */
#define XCVR_TSM_TIMING07_BB_LDO_FDBK_BLEED_EN_RX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING07_BB_LDO_FDBK_BLEED_EN_RX_LO_SHIFT)) & XCVR_TSM_TIMING07_BB_LDO_FDBK_BLEED_EN_RX_LO_MASK)
/*! @} */

/*! @name TIMING08 - TSM_TIMING08 */
/*! @{ */

#define XCVR_TSM_TIMING08_BB_LDO_VCOLO_BLEED_EN_TX_HI_MASK (0xFFU)
#define XCVR_TSM_TIMING08_BB_LDO_VCOLO_BLEED_EN_TX_HI_SHIFT (0U)
/*! BB_LDO_VCOLO_BLEED_EN_TX_HI - Assertion time setting for BB_LDO_VCOLO_BLEED_EN (TX) */
#define XCVR_TSM_TIMING08_BB_LDO_VCOLO_BLEED_EN_TX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING08_BB_LDO_VCOLO_BLEED_EN_TX_HI_SHIFT)) & XCVR_TSM_TIMING08_BB_LDO_VCOLO_BLEED_EN_TX_HI_MASK)

#define XCVR_TSM_TIMING08_BB_LDO_VCOLO_BLEED_EN_TX_LO_MASK (0xFF00U)
#define XCVR_TSM_TIMING08_BB_LDO_VCOLO_BLEED_EN_TX_LO_SHIFT (8U)
/*! BB_LDO_VCOLO_BLEED_EN_TX_LO - De-assertion time setting for BB_LDO_VCOLO_BLEED_EN (TX) */
#define XCVR_TSM_TIMING08_BB_LDO_VCOLO_BLEED_EN_TX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING08_BB_LDO_VCOLO_BLEED_EN_TX_LO_SHIFT)) & XCVR_TSM_TIMING08_BB_LDO_VCOLO_BLEED_EN_TX_LO_MASK)

#define XCVR_TSM_TIMING08_BB_LDO_VCOLO_BLEED_EN_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING08_BB_LDO_VCOLO_BLEED_EN_RX_HI_SHIFT (16U)
/*! BB_LDO_VCOLO_BLEED_EN_RX_HI - Assertion time setting for BB_LDO_VCOLO_BLEED_EN (RX) */
#define XCVR_TSM_TIMING08_BB_LDO_VCOLO_BLEED_EN_RX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING08_BB_LDO_VCOLO_BLEED_EN_RX_HI_SHIFT)) & XCVR_TSM_TIMING08_BB_LDO_VCOLO_BLEED_EN_RX_HI_MASK)

#define XCVR_TSM_TIMING08_BB_LDO_VCOLO_BLEED_EN_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING08_BB_LDO_VCOLO_BLEED_EN_RX_LO_SHIFT (24U)
/*! BB_LDO_VCOLO_BLEED_EN_RX_LO - De-assertion time setting for BB_LDO_VCOLO_BLEED_EN (RX) */
#define XCVR_TSM_TIMING08_BB_LDO_VCOLO_BLEED_EN_RX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING08_BB_LDO_VCOLO_BLEED_EN_RX_LO_SHIFT)) & XCVR_TSM_TIMING08_BB_LDO_VCOLO_BLEED_EN_RX_LO_MASK)
/*! @} */

/*! @name TIMING09 - TSM_TIMING09 */
/*! @{ */

#define XCVR_TSM_TIMING09_BB_LDO_VCOLO_FASTCHARGE_EN_TX_HI_MASK (0xFFU)
#define XCVR_TSM_TIMING09_BB_LDO_VCOLO_FASTCHARGE_EN_TX_HI_SHIFT (0U)
/*! BB_LDO_VCOLO_FASTCHARGE_EN_TX_HI - Assertion time setting for BB_LDO_VCOLO_FASTCHARGE_EN (TX) */
#define XCVR_TSM_TIMING09_BB_LDO_VCOLO_FASTCHARGE_EN_TX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING09_BB_LDO_VCOLO_FASTCHARGE_EN_TX_HI_SHIFT)) & XCVR_TSM_TIMING09_BB_LDO_VCOLO_FASTCHARGE_EN_TX_HI_MASK)

#define XCVR_TSM_TIMING09_BB_LDO_VCOLO_FASTCHARGE_EN_TX_LO_MASK (0xFF00U)
#define XCVR_TSM_TIMING09_BB_LDO_VCOLO_FASTCHARGE_EN_TX_LO_SHIFT (8U)
/*! BB_LDO_VCOLO_FASTCHARGE_EN_TX_LO - De-assertion time setting for BB_LDO_VCOLO_FASTCHARGE_EN (TX) */
#define XCVR_TSM_TIMING09_BB_LDO_VCOLO_FASTCHARGE_EN_TX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING09_BB_LDO_VCOLO_FASTCHARGE_EN_TX_LO_SHIFT)) & XCVR_TSM_TIMING09_BB_LDO_VCOLO_FASTCHARGE_EN_TX_LO_MASK)

#define XCVR_TSM_TIMING09_BB_LDO_VCOLO_FASTCHARGE_EN_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING09_BB_LDO_VCOLO_FASTCHARGE_EN_RX_HI_SHIFT (16U)
/*! BB_LDO_VCOLO_FASTCHARGE_EN_RX_HI - Assertion time setting for BB_LDO_VCOLO_FASTCHARGE_EN (RX) */
#define XCVR_TSM_TIMING09_BB_LDO_VCOLO_FASTCHARGE_EN_RX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING09_BB_LDO_VCOLO_FASTCHARGE_EN_RX_HI_SHIFT)) & XCVR_TSM_TIMING09_BB_LDO_VCOLO_FASTCHARGE_EN_RX_HI_MASK)

#define XCVR_TSM_TIMING09_BB_LDO_VCOLO_FASTCHARGE_EN_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING09_BB_LDO_VCOLO_FASTCHARGE_EN_RX_LO_SHIFT (24U)
/*! BB_LDO_VCOLO_FASTCHARGE_EN_RX_LO - De-assertion time setting for BB_LDO_VCOLO_FASTCHARGE_EN (RX) */
#define XCVR_TSM_TIMING09_BB_LDO_VCOLO_FASTCHARGE_EN_RX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING09_BB_LDO_VCOLO_FASTCHARGE_EN_RX_LO_SHIFT)) & XCVR_TSM_TIMING09_BB_LDO_VCOLO_FASTCHARGE_EN_RX_LO_MASK)
/*! @} */

/*! @name TIMING10 - TSM_TIMING10 */
/*! @{ */

#define XCVR_TSM_TIMING10_BB_XTAL_PLL_REF_CLK_EN_TX_HI_MASK (0xFFU)
#define XCVR_TSM_TIMING10_BB_XTAL_PLL_REF_CLK_EN_TX_HI_SHIFT (0U)
/*! BB_XTAL_PLL_REF_CLK_EN_TX_HI - Assertion time setting for BB_XTAL_PLL_REF_CLK_EN (TX) */
#define XCVR_TSM_TIMING10_BB_XTAL_PLL_REF_CLK_EN_TX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING10_BB_XTAL_PLL_REF_CLK_EN_TX_HI_SHIFT)) & XCVR_TSM_TIMING10_BB_XTAL_PLL_REF_CLK_EN_TX_HI_MASK)

#define XCVR_TSM_TIMING10_BB_XTAL_PLL_REF_CLK_EN_TX_LO_MASK (0xFF00U)
#define XCVR_TSM_TIMING10_BB_XTAL_PLL_REF_CLK_EN_TX_LO_SHIFT (8U)
/*! BB_XTAL_PLL_REF_CLK_EN_TX_LO - De-assertion time setting for BB_XTAL_PLL_REF_CLK_EN (TX) */
#define XCVR_TSM_TIMING10_BB_XTAL_PLL_REF_CLK_EN_TX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING10_BB_XTAL_PLL_REF_CLK_EN_TX_LO_SHIFT)) & XCVR_TSM_TIMING10_BB_XTAL_PLL_REF_CLK_EN_TX_LO_MASK)

#define XCVR_TSM_TIMING10_BB_XTAL_PLL_REF_CLK_EN_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING10_BB_XTAL_PLL_REF_CLK_EN_RX_HI_SHIFT (16U)
/*! BB_XTAL_PLL_REF_CLK_EN_RX_HI - Assertion time setting for BB_XTAL_PLL_REF_CLK_EN (RX) */
#define XCVR_TSM_TIMING10_BB_XTAL_PLL_REF_CLK_EN_RX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING10_BB_XTAL_PLL_REF_CLK_EN_RX_HI_SHIFT)) & XCVR_TSM_TIMING10_BB_XTAL_PLL_REF_CLK_EN_RX_HI_MASK)

#define XCVR_TSM_TIMING10_BB_XTAL_PLL_REF_CLK_EN_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING10_BB_XTAL_PLL_REF_CLK_EN_RX_LO_SHIFT (24U)
/*! BB_XTAL_PLL_REF_CLK_EN_RX_LO - De-assertion time setting for BB_XTAL_PLL_REF_CLK_EN (RX) */
#define XCVR_TSM_TIMING10_BB_XTAL_PLL_REF_CLK_EN_RX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING10_BB_XTAL_PLL_REF_CLK_EN_RX_LO_SHIFT)) & XCVR_TSM_TIMING10_BB_XTAL_PLL_REF_CLK_EN_RX_LO_MASK)
/*! @} */

/*! @name TIMING11 - TSM_TIMING11 */
/*! @{ */

#define XCVR_TSM_TIMING11_BB_XTAL_DAC_REF_CLK_EN_TX_HI_MASK (0xFFU)
#define XCVR_TSM_TIMING11_BB_XTAL_DAC_REF_CLK_EN_TX_HI_SHIFT (0U)
/*! BB_XTAL_DAC_REF_CLK_EN_TX_HI - Assertion time setting for BB_XTAL_DAC_REF_CLK_EN (TX) */
#define XCVR_TSM_TIMING11_BB_XTAL_DAC_REF_CLK_EN_TX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING11_BB_XTAL_DAC_REF_CLK_EN_TX_HI_SHIFT)) & XCVR_TSM_TIMING11_BB_XTAL_DAC_REF_CLK_EN_TX_HI_MASK)

#define XCVR_TSM_TIMING11_BB_XTAL_DAC_REF_CLK_EN_TX_LO_MASK (0xFF00U)
#define XCVR_TSM_TIMING11_BB_XTAL_DAC_REF_CLK_EN_TX_LO_SHIFT (8U)
/*! BB_XTAL_DAC_REF_CLK_EN_TX_LO - De-assertion time setting for BB_XTAL_DAC_REF_CLK_EN (TX) */
#define XCVR_TSM_TIMING11_BB_XTAL_DAC_REF_CLK_EN_TX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING11_BB_XTAL_DAC_REF_CLK_EN_TX_LO_SHIFT)) & XCVR_TSM_TIMING11_BB_XTAL_DAC_REF_CLK_EN_TX_LO_MASK)
/*! @} */

/*! @name TIMING12 - TSM_TIMING12 */
/*! @{ */

#define XCVR_TSM_TIMING12_RXTX_AUXPLL_VCO_REF_CLK_EN_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING12_RXTX_AUXPLL_VCO_REF_CLK_EN_RX_HI_SHIFT (16U)
/*! RXTX_AUXPLL_VCO_REF_CLK_EN_RX_HI - Assertion time setting for RXTX_AUXPLL_VCO_REF_CLK_EN (RX) */
#define XCVR_TSM_TIMING12_RXTX_AUXPLL_VCO_REF_CLK_EN_RX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING12_RXTX_AUXPLL_VCO_REF_CLK_EN_RX_HI_SHIFT)) & XCVR_TSM_TIMING12_RXTX_AUXPLL_VCO_REF_CLK_EN_RX_HI_MASK)

#define XCVR_TSM_TIMING12_RXTX_AUXPLL_VCO_REF_CLK_EN_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING12_RXTX_AUXPLL_VCO_REF_CLK_EN_RX_LO_SHIFT (24U)
/*! RXTX_AUXPLL_VCO_REF_CLK_EN_RX_LO - De-assertion time setting for RXTX_AUXPLL_VCO_REF_CLK_EN (RX) */
#define XCVR_TSM_TIMING12_RXTX_AUXPLL_VCO_REF_CLK_EN_RX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING12_RXTX_AUXPLL_VCO_REF_CLK_EN_RX_LO_SHIFT)) & XCVR_TSM_TIMING12_RXTX_AUXPLL_VCO_REF_CLK_EN_RX_LO_MASK)
/*! @} */

/*! @name TIMING13 - TSM_TIMING13 */
/*! @{ */

#define XCVR_TSM_TIMING13_SY_VCO_AUTOTUNE_EN_TX_HI_MASK (0xFFU)
#define XCVR_TSM_TIMING13_SY_VCO_AUTOTUNE_EN_TX_HI_SHIFT (0U)
/*! SY_VCO_AUTOTUNE_EN_TX_HI - Assertion time setting for SY_VCO_AUTOTUNE_EN (TX) */
#define XCVR_TSM_TIMING13_SY_VCO_AUTOTUNE_EN_TX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING13_SY_VCO_AUTOTUNE_EN_TX_HI_SHIFT)) & XCVR_TSM_TIMING13_SY_VCO_AUTOTUNE_EN_TX_HI_MASK)

#define XCVR_TSM_TIMING13_SY_VCO_AUTOTUNE_EN_TX_LO_MASK (0xFF00U)
#define XCVR_TSM_TIMING13_SY_VCO_AUTOTUNE_EN_TX_LO_SHIFT (8U)
/*! SY_VCO_AUTOTUNE_EN_TX_LO - De-assertion time setting for SY_VCO_AUTOTUNE_EN (TX) */
#define XCVR_TSM_TIMING13_SY_VCO_AUTOTUNE_EN_TX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING13_SY_VCO_AUTOTUNE_EN_TX_LO_SHIFT)) & XCVR_TSM_TIMING13_SY_VCO_AUTOTUNE_EN_TX_LO_MASK)

#define XCVR_TSM_TIMING13_SY_VCO_AUTOTUNE_EN_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING13_SY_VCO_AUTOTUNE_EN_RX_HI_SHIFT (16U)
/*! SY_VCO_AUTOTUNE_EN_RX_HI - Assertion time setting for SY_VCO_AUTOTUNE_EN (RX) */
#define XCVR_TSM_TIMING13_SY_VCO_AUTOTUNE_EN_RX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING13_SY_VCO_AUTOTUNE_EN_RX_HI_SHIFT)) & XCVR_TSM_TIMING13_SY_VCO_AUTOTUNE_EN_RX_HI_MASK)

#define XCVR_TSM_TIMING13_SY_VCO_AUTOTUNE_EN_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING13_SY_VCO_AUTOTUNE_EN_RX_LO_SHIFT (24U)
/*! SY_VCO_AUTOTUNE_EN_RX_LO - De-assertion time setting for SY_VCO_AUTOTUNE_EN (RX) */
#define XCVR_TSM_TIMING13_SY_VCO_AUTOTUNE_EN_RX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING13_SY_VCO_AUTOTUNE_EN_RX_LO_SHIFT)) & XCVR_TSM_TIMING13_SY_VCO_AUTOTUNE_EN_RX_LO_MASK)
/*! @} */

/*! @name TIMING14 - TSM_TIMING14 */
/*! @{ */

#define XCVR_TSM_TIMING14_SY_PD_CYCLE_SLIP_LD_FT_EN_TX_HI_MASK (0xFFU)
#define XCVR_TSM_TIMING14_SY_PD_CYCLE_SLIP_LD_FT_EN_TX_HI_SHIFT (0U)
/*! SY_PD_CYCLE_SLIP_LD_FT_EN_TX_HI - Assertion time setting for SY_PD_CYCLE_SLIP_LD_FT_EN (TX) */
#define XCVR_TSM_TIMING14_SY_PD_CYCLE_SLIP_LD_FT_EN_TX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING14_SY_PD_CYCLE_SLIP_LD_FT_EN_TX_HI_SHIFT)) & XCVR_TSM_TIMING14_SY_PD_CYCLE_SLIP_LD_FT_EN_TX_HI_MASK)

#define XCVR_TSM_TIMING14_SY_PD_CYCLE_SLIP_LD_FT_EN_TX_LO_MASK (0xFF00U)
#define XCVR_TSM_TIMING14_SY_PD_CYCLE_SLIP_LD_FT_EN_TX_LO_SHIFT (8U)
/*! SY_PD_CYCLE_SLIP_LD_FT_EN_TX_LO - De-assertion time setting for SY_PD_CYCLE_SLIP_LD_FT_EN (TX) */
#define XCVR_TSM_TIMING14_SY_PD_CYCLE_SLIP_LD_FT_EN_TX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING14_SY_PD_CYCLE_SLIP_LD_FT_EN_TX_LO_SHIFT)) & XCVR_TSM_TIMING14_SY_PD_CYCLE_SLIP_LD_FT_EN_TX_LO_MASK)

#define XCVR_TSM_TIMING14_SY_PD_CYCLE_SLIP_LD_FT_EN_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING14_SY_PD_CYCLE_SLIP_LD_FT_EN_RX_HI_SHIFT (16U)
/*! SY_PD_CYCLE_SLIP_LD_FT_EN_RX_HI - Assertion time setting for SY_PD_CYCLE_SLIP_LD_FT_EN (RX) */
#define XCVR_TSM_TIMING14_SY_PD_CYCLE_SLIP_LD_FT_EN_RX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING14_SY_PD_CYCLE_SLIP_LD_FT_EN_RX_HI_SHIFT)) & XCVR_TSM_TIMING14_SY_PD_CYCLE_SLIP_LD_FT_EN_RX_HI_MASK)

#define XCVR_TSM_TIMING14_SY_PD_CYCLE_SLIP_LD_FT_EN_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING14_SY_PD_CYCLE_SLIP_LD_FT_EN_RX_LO_SHIFT (24U)
/*! SY_PD_CYCLE_SLIP_LD_FT_EN_RX_LO - De-assertion time setting for SY_PD_CYCLE_SLIP_LD_FT_EN (RX) */
#define XCVR_TSM_TIMING14_SY_PD_CYCLE_SLIP_LD_FT_EN_RX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING14_SY_PD_CYCLE_SLIP_LD_FT_EN_RX_LO_SHIFT)) & XCVR_TSM_TIMING14_SY_PD_CYCLE_SLIP_LD_FT_EN_RX_LO_MASK)
/*! @} */

/*! @name TIMING15 - TSM_TIMING15 */
/*! @{ */

#define XCVR_TSM_TIMING15_SY_VCO_EN_TX_HI_MASK   (0xFFU)
#define XCVR_TSM_TIMING15_SY_VCO_EN_TX_HI_SHIFT  (0U)
/*! SY_VCO_EN_TX_HI - Assertion time setting for SY_VCO_EN (TX) */
#define XCVR_TSM_TIMING15_SY_VCO_EN_TX_HI(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING15_SY_VCO_EN_TX_HI_SHIFT)) & XCVR_TSM_TIMING15_SY_VCO_EN_TX_HI_MASK)

#define XCVR_TSM_TIMING15_SY_VCO_EN_TX_LO_MASK   (0xFF00U)
#define XCVR_TSM_TIMING15_SY_VCO_EN_TX_LO_SHIFT  (8U)
/*! SY_VCO_EN_TX_LO - De-assertion time setting for SY_VCO_EN (TX) */
#define XCVR_TSM_TIMING15_SY_VCO_EN_TX_LO(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING15_SY_VCO_EN_TX_LO_SHIFT)) & XCVR_TSM_TIMING15_SY_VCO_EN_TX_LO_MASK)

#define XCVR_TSM_TIMING15_SY_VCO_EN_RX_HI_MASK   (0xFF0000U)
#define XCVR_TSM_TIMING15_SY_VCO_EN_RX_HI_SHIFT  (16U)
/*! SY_VCO_EN_RX_HI - Assertion time setting for SY_VCO_EN (RX) */
#define XCVR_TSM_TIMING15_SY_VCO_EN_RX_HI(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING15_SY_VCO_EN_RX_HI_SHIFT)) & XCVR_TSM_TIMING15_SY_VCO_EN_RX_HI_MASK)

#define XCVR_TSM_TIMING15_SY_VCO_EN_RX_LO_MASK   (0xFF000000U)
#define XCVR_TSM_TIMING15_SY_VCO_EN_RX_LO_SHIFT  (24U)
/*! SY_VCO_EN_RX_LO - De-assertion time setting for SY_VCO_EN (RX) */
#define XCVR_TSM_TIMING15_SY_VCO_EN_RX_LO(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING15_SY_VCO_EN_RX_LO_SHIFT)) & XCVR_TSM_TIMING15_SY_VCO_EN_RX_LO_MASK)
/*! @} */

/*! @name TIMING16 - TSM_TIMING16 */
/*! @{ */

#define XCVR_TSM_TIMING16_SY_LO_RX_BUF_EN_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING16_SY_LO_RX_BUF_EN_RX_HI_SHIFT (16U)
/*! SY_LO_RX_BUF_EN_RX_HI - Assertion time setting for SY_LO_RX_BUF_EN (RX) */
#define XCVR_TSM_TIMING16_SY_LO_RX_BUF_EN_RX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING16_SY_LO_RX_BUF_EN_RX_HI_SHIFT)) & XCVR_TSM_TIMING16_SY_LO_RX_BUF_EN_RX_HI_MASK)

#define XCVR_TSM_TIMING16_SY_LO_RX_BUF_EN_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING16_SY_LO_RX_BUF_EN_RX_LO_SHIFT (24U)
/*! SY_LO_RX_BUF_EN_RX_LO - De-assertion time setting for SY_LO_RX_BUF_EN (RX) */
#define XCVR_TSM_TIMING16_SY_LO_RX_BUF_EN_RX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING16_SY_LO_RX_BUF_EN_RX_LO_SHIFT)) & XCVR_TSM_TIMING16_SY_LO_RX_BUF_EN_RX_LO_MASK)
/*! @} */

/*! @name TIMING17 - TSM_TIMING17 */
/*! @{ */

#define XCVR_TSM_TIMING17_SY_LO_TX_BUF_EN_TX_HI_MASK (0xFFU)
#define XCVR_TSM_TIMING17_SY_LO_TX_BUF_EN_TX_HI_SHIFT (0U)
/*! SY_LO_TX_BUF_EN_TX_HI - Assertion time setting for SY_LO_TX_BUF_EN (TX) */
#define XCVR_TSM_TIMING17_SY_LO_TX_BUF_EN_TX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING17_SY_LO_TX_BUF_EN_TX_HI_SHIFT)) & XCVR_TSM_TIMING17_SY_LO_TX_BUF_EN_TX_HI_MASK)

#define XCVR_TSM_TIMING17_SY_LO_TX_BUF_EN_TX_LO_MASK (0xFF00U)
#define XCVR_TSM_TIMING17_SY_LO_TX_BUF_EN_TX_LO_SHIFT (8U)
/*! SY_LO_TX_BUF_EN_TX_LO - De-assertion time setting for SY_LO_TX_BUF_EN (TX) */
#define XCVR_TSM_TIMING17_SY_LO_TX_BUF_EN_TX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING17_SY_LO_TX_BUF_EN_TX_LO_SHIFT)) & XCVR_TSM_TIMING17_SY_LO_TX_BUF_EN_TX_LO_MASK)
/*! @} */

/*! @name TIMING18 - TSM_TIMING18 */
/*! @{ */

#define XCVR_TSM_TIMING18_SY_DIVN_EN_TX_HI_MASK  (0xFFU)
#define XCVR_TSM_TIMING18_SY_DIVN_EN_TX_HI_SHIFT (0U)
/*! SY_DIVN_EN_TX_HI - Assertion time setting for SY_DIVN_EN (TX) */
#define XCVR_TSM_TIMING18_SY_DIVN_EN_TX_HI(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING18_SY_DIVN_EN_TX_HI_SHIFT)) & XCVR_TSM_TIMING18_SY_DIVN_EN_TX_HI_MASK)

#define XCVR_TSM_TIMING18_SY_DIVN_EN_TX_LO_MASK  (0xFF00U)
#define XCVR_TSM_TIMING18_SY_DIVN_EN_TX_LO_SHIFT (8U)
/*! SY_DIVN_EN_TX_LO - De-assertion time setting for SY_DIVN_EN (TX) */
#define XCVR_TSM_TIMING18_SY_DIVN_EN_TX_LO(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING18_SY_DIVN_EN_TX_LO_SHIFT)) & XCVR_TSM_TIMING18_SY_DIVN_EN_TX_LO_MASK)

#define XCVR_TSM_TIMING18_SY_DIVN_EN_RX_HI_MASK  (0xFF0000U)
#define XCVR_TSM_TIMING18_SY_DIVN_EN_RX_HI_SHIFT (16U)
/*! SY_DIVN_EN_RX_HI - Assertion time setting for SY_DIVN_EN (RX) */
#define XCVR_TSM_TIMING18_SY_DIVN_EN_RX_HI(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING18_SY_DIVN_EN_RX_HI_SHIFT)) & XCVR_TSM_TIMING18_SY_DIVN_EN_RX_HI_MASK)

#define XCVR_TSM_TIMING18_SY_DIVN_EN_RX_LO_MASK  (0xFF000000U)
#define XCVR_TSM_TIMING18_SY_DIVN_EN_RX_LO_SHIFT (24U)
/*! SY_DIVN_EN_RX_LO - De-assertion time setting for SY_DIVN_EN (RX) */
#define XCVR_TSM_TIMING18_SY_DIVN_EN_RX_LO(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING18_SY_DIVN_EN_RX_LO_SHIFT)) & XCVR_TSM_TIMING18_SY_DIVN_EN_RX_LO_MASK)
/*! @} */

/*! @name TIMING19 - TSM_TIMING19 */
/*! @{ */

#define XCVR_TSM_TIMING19_SY_PD_FILTER_CHARGE_EN_TX_HI_MASK (0xFFU)
#define XCVR_TSM_TIMING19_SY_PD_FILTER_CHARGE_EN_TX_HI_SHIFT (0U)
/*! SY_PD_FILTER_CHARGE_EN_TX_HI - Assertion time setting for SY_PD_FILTER_CHARGE_EN (TX) */
#define XCVR_TSM_TIMING19_SY_PD_FILTER_CHARGE_EN_TX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING19_SY_PD_FILTER_CHARGE_EN_TX_HI_SHIFT)) & XCVR_TSM_TIMING19_SY_PD_FILTER_CHARGE_EN_TX_HI_MASK)

#define XCVR_TSM_TIMING19_SY_PD_FILTER_CHARGE_EN_TX_LO_MASK (0xFF00U)
#define XCVR_TSM_TIMING19_SY_PD_FILTER_CHARGE_EN_TX_LO_SHIFT (8U)
/*! SY_PD_FILTER_CHARGE_EN_TX_LO - De-assertion time setting for SY_PD_FILTER_CHARGE_EN (TX) */
#define XCVR_TSM_TIMING19_SY_PD_FILTER_CHARGE_EN_TX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING19_SY_PD_FILTER_CHARGE_EN_TX_LO_SHIFT)) & XCVR_TSM_TIMING19_SY_PD_FILTER_CHARGE_EN_TX_LO_MASK)

#define XCVR_TSM_TIMING19_SY_PD_FILTER_CHARGE_EN_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING19_SY_PD_FILTER_CHARGE_EN_RX_HI_SHIFT (16U)
/*! SY_PD_FILTER_CHARGE_EN_RX_HI - Assertion time setting for SY_PD_FILTER_CHARGE_EN (RX) */
#define XCVR_TSM_TIMING19_SY_PD_FILTER_CHARGE_EN_RX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING19_SY_PD_FILTER_CHARGE_EN_RX_HI_SHIFT)) & XCVR_TSM_TIMING19_SY_PD_FILTER_CHARGE_EN_RX_HI_MASK)

#define XCVR_TSM_TIMING19_SY_PD_FILTER_CHARGE_EN_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING19_SY_PD_FILTER_CHARGE_EN_RX_LO_SHIFT (24U)
/*! SY_PD_FILTER_CHARGE_EN_RX_LO - De-assertion time setting for SY_PD_FILTER_CHARGE_EN (RX) */
#define XCVR_TSM_TIMING19_SY_PD_FILTER_CHARGE_EN_RX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING19_SY_PD_FILTER_CHARGE_EN_RX_LO_SHIFT)) & XCVR_TSM_TIMING19_SY_PD_FILTER_CHARGE_EN_RX_LO_MASK)
/*! @} */

/*! @name TIMING20 - TSM_TIMING20 */
/*! @{ */

#define XCVR_TSM_TIMING20_SY_PD_EN_TX_HI_MASK    (0xFFU)
#define XCVR_TSM_TIMING20_SY_PD_EN_TX_HI_SHIFT   (0U)
/*! SY_PD_EN_TX_HI - Assertion time setting for SY_PD_EN (TX) */
#define XCVR_TSM_TIMING20_SY_PD_EN_TX_HI(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING20_SY_PD_EN_TX_HI_SHIFT)) & XCVR_TSM_TIMING20_SY_PD_EN_TX_HI_MASK)

#define XCVR_TSM_TIMING20_SY_PD_EN_TX_LO_MASK    (0xFF00U)
#define XCVR_TSM_TIMING20_SY_PD_EN_TX_LO_SHIFT   (8U)
/*! SY_PD_EN_TX_LO - De-assertion time setting for SY_PD_EN (TX) */
#define XCVR_TSM_TIMING20_SY_PD_EN_TX_LO(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING20_SY_PD_EN_TX_LO_SHIFT)) & XCVR_TSM_TIMING20_SY_PD_EN_TX_LO_MASK)

#define XCVR_TSM_TIMING20_SY_PD_EN_RX_HI_MASK    (0xFF0000U)
#define XCVR_TSM_TIMING20_SY_PD_EN_RX_HI_SHIFT   (16U)
/*! SY_PD_EN_RX_HI - Assertion time setting for SY_PD_EN (RX) */
#define XCVR_TSM_TIMING20_SY_PD_EN_RX_HI(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING20_SY_PD_EN_RX_HI_SHIFT)) & XCVR_TSM_TIMING20_SY_PD_EN_RX_HI_MASK)

#define XCVR_TSM_TIMING20_SY_PD_EN_RX_LO_MASK    (0xFF000000U)
#define XCVR_TSM_TIMING20_SY_PD_EN_RX_LO_SHIFT   (24U)
/*! SY_PD_EN_RX_LO - De-assertion time setting for SY_PD_EN (RX) */
#define XCVR_TSM_TIMING20_SY_PD_EN_RX_LO(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING20_SY_PD_EN_RX_LO_SHIFT)) & XCVR_TSM_TIMING20_SY_PD_EN_RX_LO_MASK)
/*! @} */

/*! @name TIMING21 - TSM_TIMING21 */
/*! @{ */

#define XCVR_TSM_TIMING21_SY_LO_DIVN_EN_TX_HI_MASK (0xFFU)
#define XCVR_TSM_TIMING21_SY_LO_DIVN_EN_TX_HI_SHIFT (0U)
/*! SY_LO_DIVN_EN_TX_HI - Assertion time setting for SY_LO_DIVN_EN (TX) */
#define XCVR_TSM_TIMING21_SY_LO_DIVN_EN_TX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING21_SY_LO_DIVN_EN_TX_HI_SHIFT)) & XCVR_TSM_TIMING21_SY_LO_DIVN_EN_TX_HI_MASK)

#define XCVR_TSM_TIMING21_SY_LO_DIVN_EN_TX_LO_MASK (0xFF00U)
#define XCVR_TSM_TIMING21_SY_LO_DIVN_EN_TX_LO_SHIFT (8U)
/*! SY_LO_DIVN_EN_TX_LO - De-assertion time setting for SY_LO_DIVN_EN (TX) */
#define XCVR_TSM_TIMING21_SY_LO_DIVN_EN_TX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING21_SY_LO_DIVN_EN_TX_LO_SHIFT)) & XCVR_TSM_TIMING21_SY_LO_DIVN_EN_TX_LO_MASK)

#define XCVR_TSM_TIMING21_SY_LO_DIVN_EN_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING21_SY_LO_DIVN_EN_RX_HI_SHIFT (16U)
/*! SY_LO_DIVN_EN_RX_HI - Assertion time setting for SY_LO_DIVN_EN (RX) */
#define XCVR_TSM_TIMING21_SY_LO_DIVN_EN_RX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING21_SY_LO_DIVN_EN_RX_HI_SHIFT)) & XCVR_TSM_TIMING21_SY_LO_DIVN_EN_RX_HI_MASK)

#define XCVR_TSM_TIMING21_SY_LO_DIVN_EN_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING21_SY_LO_DIVN_EN_RX_LO_SHIFT (24U)
/*! SY_LO_DIVN_EN_RX_LO - De-assertion time setting for SY_LO_DIVN_EN (RX) */
#define XCVR_TSM_TIMING21_SY_LO_DIVN_EN_RX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING21_SY_LO_DIVN_EN_RX_LO_SHIFT)) & XCVR_TSM_TIMING21_SY_LO_DIVN_EN_RX_LO_MASK)
/*! @} */

/*! @name TIMING22 - TSM_TIMING22 */
/*! @{ */

#define XCVR_TSM_TIMING22_SY_LO_RX_EN_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING22_SY_LO_RX_EN_RX_HI_SHIFT (16U)
/*! SY_LO_RX_EN_RX_HI - Assertion time setting for SY_LO_RX_EN (RX) */
#define XCVR_TSM_TIMING22_SY_LO_RX_EN_RX_HI(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING22_SY_LO_RX_EN_RX_HI_SHIFT)) & XCVR_TSM_TIMING22_SY_LO_RX_EN_RX_HI_MASK)

#define XCVR_TSM_TIMING22_SY_LO_RX_EN_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING22_SY_LO_RX_EN_RX_LO_SHIFT (24U)
/*! SY_LO_RX_EN_RX_LO - De-assertion time setting for SY_LO_RX_EN (RX) */
#define XCVR_TSM_TIMING22_SY_LO_RX_EN_RX_LO(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING22_SY_LO_RX_EN_RX_LO_SHIFT)) & XCVR_TSM_TIMING22_SY_LO_RX_EN_RX_LO_MASK)
/*! @} */

/*! @name TIMING23 - TSM_TIMING23 */
/*! @{ */

#define XCVR_TSM_TIMING23_SY_LO_TX_EN_TX_HI_MASK (0xFFU)
#define XCVR_TSM_TIMING23_SY_LO_TX_EN_TX_HI_SHIFT (0U)
/*! SY_LO_TX_EN_TX_HI - Assertion time setting for SY_LO_TX_EN (TX) */
#define XCVR_TSM_TIMING23_SY_LO_TX_EN_TX_HI(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING23_SY_LO_TX_EN_TX_HI_SHIFT)) & XCVR_TSM_TIMING23_SY_LO_TX_EN_TX_HI_MASK)

#define XCVR_TSM_TIMING23_SY_LO_TX_EN_TX_LO_MASK (0xFF00U)
#define XCVR_TSM_TIMING23_SY_LO_TX_EN_TX_LO_SHIFT (8U)
/*! SY_LO_TX_EN_TX_LO - De-assertion time setting for SY_LO_TX_EN (TX) */
#define XCVR_TSM_TIMING23_SY_LO_TX_EN_TX_LO(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING23_SY_LO_TX_EN_TX_LO_SHIFT)) & XCVR_TSM_TIMING23_SY_LO_TX_EN_TX_LO_MASK)
/*! @} */

/*! @name TIMING24 - TSM_TIMING24 */
/*! @{ */

#define XCVR_TSM_TIMING24_SY_DIVN_CAL_EN_TX_HI_MASK (0xFFU)
#define XCVR_TSM_TIMING24_SY_DIVN_CAL_EN_TX_HI_SHIFT (0U)
/*! SY_DIVN_CAL_EN_TX_HI - Assertion time setting for SY_DIVN_CAL_EN (TX) */
#define XCVR_TSM_TIMING24_SY_DIVN_CAL_EN_TX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING24_SY_DIVN_CAL_EN_TX_HI_SHIFT)) & XCVR_TSM_TIMING24_SY_DIVN_CAL_EN_TX_HI_MASK)

#define XCVR_TSM_TIMING24_SY_DIVN_CAL_EN_TX_LO_MASK (0xFF00U)
#define XCVR_TSM_TIMING24_SY_DIVN_CAL_EN_TX_LO_SHIFT (8U)
/*! SY_DIVN_CAL_EN_TX_LO - De-assertion time setting for SY_DIVN_CAL_EN (TX) */
#define XCVR_TSM_TIMING24_SY_DIVN_CAL_EN_TX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING24_SY_DIVN_CAL_EN_TX_LO_SHIFT)) & XCVR_TSM_TIMING24_SY_DIVN_CAL_EN_TX_LO_MASK)

#define XCVR_TSM_TIMING24_SY_DIVN_CAL_EN_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING24_SY_DIVN_CAL_EN_RX_HI_SHIFT (16U)
/*! SY_DIVN_CAL_EN_RX_HI - Assertion time setting for SY_DIVN_CAL_EN (RX) */
#define XCVR_TSM_TIMING24_SY_DIVN_CAL_EN_RX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING24_SY_DIVN_CAL_EN_RX_HI_SHIFT)) & XCVR_TSM_TIMING24_SY_DIVN_CAL_EN_RX_HI_MASK)

#define XCVR_TSM_TIMING24_SY_DIVN_CAL_EN_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING24_SY_DIVN_CAL_EN_RX_LO_SHIFT (24U)
/*! SY_DIVN_CAL_EN_RX_LO - De-assertion time setting for SY_DIVN_CAL_EN (RX) */
#define XCVR_TSM_TIMING24_SY_DIVN_CAL_EN_RX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING24_SY_DIVN_CAL_EN_RX_LO_SHIFT)) & XCVR_TSM_TIMING24_SY_DIVN_CAL_EN_RX_LO_MASK)
/*! @} */

/*! @name TIMING25 - TSM_TIMING25 */
/*! @{ */

#define XCVR_TSM_TIMING25_RX_LNA_MIXER_EN_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING25_RX_LNA_MIXER_EN_RX_HI_SHIFT (16U)
/*! RX_LNA_MIXER_EN_RX_HI - Assertion time setting for RX_LNA_MIXER_EN (RX) */
#define XCVR_TSM_TIMING25_RX_LNA_MIXER_EN_RX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING25_RX_LNA_MIXER_EN_RX_HI_SHIFT)) & XCVR_TSM_TIMING25_RX_LNA_MIXER_EN_RX_HI_MASK)

#define XCVR_TSM_TIMING25_RX_LNA_MIXER_EN_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING25_RX_LNA_MIXER_EN_RX_LO_SHIFT (24U)
/*! RX_LNA_MIXER_EN_RX_LO - De-assertion time setting for RX_LNA_MIXER_EN (RX) */
#define XCVR_TSM_TIMING25_RX_LNA_MIXER_EN_RX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING25_RX_LNA_MIXER_EN_RX_LO_SHIFT)) & XCVR_TSM_TIMING25_RX_LNA_MIXER_EN_RX_LO_MASK)
/*! @} */

/*! @name TIMING26 - TSM_TIMING26 */
/*! @{ */

#define XCVR_TSM_TIMING26_TX_PA_EN_TX_HI_MASK    (0xFFU)
#define XCVR_TSM_TIMING26_TX_PA_EN_TX_HI_SHIFT   (0U)
/*! TX_PA_EN_TX_HI - Assertion time setting for TX_PA_EN (TX) */
#define XCVR_TSM_TIMING26_TX_PA_EN_TX_HI(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING26_TX_PA_EN_TX_HI_SHIFT)) & XCVR_TSM_TIMING26_TX_PA_EN_TX_HI_MASK)

#define XCVR_TSM_TIMING26_TX_PA_EN_TX_LO_MASK    (0xFF00U)
#define XCVR_TSM_TIMING26_TX_PA_EN_TX_LO_SHIFT   (8U)
/*! TX_PA_EN_TX_LO - De-assertion time setting for TX_PA_EN (TX) */
#define XCVR_TSM_TIMING26_TX_PA_EN_TX_LO(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING26_TX_PA_EN_TX_LO_SHIFT)) & XCVR_TSM_TIMING26_TX_PA_EN_TX_LO_MASK)
/*! @} */

/*! @name TIMING27 - TSM_TIMING27 */
/*! @{ */

#define XCVR_TSM_TIMING27_RX_ADC_I_Q_EN_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING27_RX_ADC_I_Q_EN_RX_HI_SHIFT (16U)
/*! RX_ADC_I_Q_EN_RX_HI - Assertion time setting for RX_ADC_I_Q_EN (RX) */
#define XCVR_TSM_TIMING27_RX_ADC_I_Q_EN_RX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING27_RX_ADC_I_Q_EN_RX_HI_SHIFT)) & XCVR_TSM_TIMING27_RX_ADC_I_Q_EN_RX_HI_MASK)

#define XCVR_TSM_TIMING27_RX_ADC_I_Q_EN_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING27_RX_ADC_I_Q_EN_RX_LO_SHIFT (24U)
/*! RX_ADC_I_Q_EN_RX_LO - De-assertion time setting for RX_ADC_I_Q_EN (RX) */
#define XCVR_TSM_TIMING27_RX_ADC_I_Q_EN_RX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING27_RX_ADC_I_Q_EN_RX_LO_SHIFT)) & XCVR_TSM_TIMING27_RX_ADC_I_Q_EN_RX_LO_MASK)
/*! @} */

/*! @name TIMING28 - TSM_TIMING28 */
/*! @{ */

#define XCVR_TSM_TIMING28_RX_ADC_RESET_EN_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING28_RX_ADC_RESET_EN_RX_HI_SHIFT (16U)
/*! RX_ADC_RESET_EN_RX_HI - Assertion time setting for RX_ADC_RESET_EN (RX) */
#define XCVR_TSM_TIMING28_RX_ADC_RESET_EN_RX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING28_RX_ADC_RESET_EN_RX_HI_SHIFT)) & XCVR_TSM_TIMING28_RX_ADC_RESET_EN_RX_HI_MASK)

#define XCVR_TSM_TIMING28_RX_ADC_RESET_EN_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING28_RX_ADC_RESET_EN_RX_LO_SHIFT (24U)
/*! RX_ADC_RESET_EN_RX_LO - De-assertion time setting for RX_ADC_RESET_EN (RX) */
#define XCVR_TSM_TIMING28_RX_ADC_RESET_EN_RX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING28_RX_ADC_RESET_EN_RX_LO_SHIFT)) & XCVR_TSM_TIMING28_RX_ADC_RESET_EN_RX_LO_MASK)
/*! @} */

/*! @name TIMING29 - TSM_TIMING29 */
/*! @{ */

#define XCVR_TSM_TIMING29_RX_BBA_I_Q_EN_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING29_RX_BBA_I_Q_EN_RX_HI_SHIFT (16U)
/*! RX_BBA_I_Q_EN_RX_HI - Assertion time setting for RX_BBA_I_Q_EN (RX) */
#define XCVR_TSM_TIMING29_RX_BBA_I_Q_EN_RX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING29_RX_BBA_I_Q_EN_RX_HI_SHIFT)) & XCVR_TSM_TIMING29_RX_BBA_I_Q_EN_RX_HI_MASK)

#define XCVR_TSM_TIMING29_RX_BBA_I_Q_EN_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING29_RX_BBA_I_Q_EN_RX_LO_SHIFT (24U)
/*! RX_BBA_I_Q_EN_RX_LO - De-assertion time setting for RX_BBA_I_Q_EN (RX) */
#define XCVR_TSM_TIMING29_RX_BBA_I_Q_EN_RX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING29_RX_BBA_I_Q_EN_RX_LO_SHIFT)) & XCVR_TSM_TIMING29_RX_BBA_I_Q_EN_RX_LO_MASK)
/*! @} */

/*! @name TIMING30 - TSM_TIMING30 */
/*! @{ */

#define XCVR_TSM_TIMING30_RX_BBA_PDET_EN_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING30_RX_BBA_PDET_EN_RX_HI_SHIFT (16U)
/*! RX_BBA_PDET_EN_RX_HI - Assertion time setting for RX_BBA_PDET_EN (RX) */
#define XCVR_TSM_TIMING30_RX_BBA_PDET_EN_RX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING30_RX_BBA_PDET_EN_RX_HI_SHIFT)) & XCVR_TSM_TIMING30_RX_BBA_PDET_EN_RX_HI_MASK)

#define XCVR_TSM_TIMING30_RX_BBA_PDET_EN_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING30_RX_BBA_PDET_EN_RX_LO_SHIFT (24U)
/*! RX_BBA_PDET_EN_RX_LO - De-assertion time setting for RX_BBA_PDET_EN (RX) */
#define XCVR_TSM_TIMING30_RX_BBA_PDET_EN_RX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING30_RX_BBA_PDET_EN_RX_LO_SHIFT)) & XCVR_TSM_TIMING30_RX_BBA_PDET_EN_RX_LO_MASK)
/*! @} */

/*! @name TIMING31 - TSM_TIMING31 */
/*! @{ */

#define XCVR_TSM_TIMING31_RX_BBA_TZA_DCOC_EN_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING31_RX_BBA_TZA_DCOC_EN_RX_HI_SHIFT (16U)
/*! RX_BBA_TZA_DCOC_EN_RX_HI - Assertion time setting for RX_BBA_TZA_DCOC_EN (RX) */
#define XCVR_TSM_TIMING31_RX_BBA_TZA_DCOC_EN_RX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING31_RX_BBA_TZA_DCOC_EN_RX_HI_SHIFT)) & XCVR_TSM_TIMING31_RX_BBA_TZA_DCOC_EN_RX_HI_MASK)

#define XCVR_TSM_TIMING31_RX_BBA_TZA_DCOC_EN_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING31_RX_BBA_TZA_DCOC_EN_RX_LO_SHIFT (24U)
/*! RX_BBA_TZA_DCOC_EN_RX_LO - De-assertion time setting for RX_BBA_TZA_DCOC_EN (RX) */
#define XCVR_TSM_TIMING31_RX_BBA_TZA_DCOC_EN_RX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING31_RX_BBA_TZA_DCOC_EN_RX_LO_SHIFT)) & XCVR_TSM_TIMING31_RX_BBA_TZA_DCOC_EN_RX_LO_MASK)
/*! @} */

/*! @name TIMING32 - TSM_TIMING32 */
/*! @{ */

#define XCVR_TSM_TIMING32_RX_TZA_I_Q_EN_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING32_RX_TZA_I_Q_EN_RX_HI_SHIFT (16U)
/*! RX_TZA_I_Q_EN_RX_HI - Assertion time setting for RX_TZA_I_Q_EN (RX) */
#define XCVR_TSM_TIMING32_RX_TZA_I_Q_EN_RX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING32_RX_TZA_I_Q_EN_RX_HI_SHIFT)) & XCVR_TSM_TIMING32_RX_TZA_I_Q_EN_RX_HI_MASK)

#define XCVR_TSM_TIMING32_RX_TZA_I_Q_EN_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING32_RX_TZA_I_Q_EN_RX_LO_SHIFT (24U)
/*! RX_TZA_I_Q_EN_RX_LO - De-assertion time setting for RX_TZA_I_Q_EN (RX) */
#define XCVR_TSM_TIMING32_RX_TZA_I_Q_EN_RX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING32_RX_TZA_I_Q_EN_RX_LO_SHIFT)) & XCVR_TSM_TIMING32_RX_TZA_I_Q_EN_RX_LO_MASK)
/*! @} */

/*! @name TIMING33 - TSM_TIMING33 */
/*! @{ */

#define XCVR_TSM_TIMING33_RX_TZA_PDET_EN_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING33_RX_TZA_PDET_EN_RX_HI_SHIFT (16U)
/*! RX_TZA_PDET_EN_RX_HI - Assertion time setting for RX_TZA_PDET_EN (RX) */
#define XCVR_TSM_TIMING33_RX_TZA_PDET_EN_RX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING33_RX_TZA_PDET_EN_RX_HI_SHIFT)) & XCVR_TSM_TIMING33_RX_TZA_PDET_EN_RX_HI_MASK)

#define XCVR_TSM_TIMING33_RX_TZA_PDET_EN_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING33_RX_TZA_PDET_EN_RX_LO_SHIFT (24U)
/*! RX_TZA_PDET_EN_RX_LO - De-assertion time setting for RX_TZA_PDET_EN (RX) */
#define XCVR_TSM_TIMING33_RX_TZA_PDET_EN_RX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING33_RX_TZA_PDET_EN_RX_LO_SHIFT)) & XCVR_TSM_TIMING33_RX_TZA_PDET_EN_RX_LO_MASK)
/*! @} */

/*! @name TIMING34 - TSM_TIMING34 */
/*! @{ */

#define XCVR_TSM_TIMING34_PLL_DIG_EN_TX_HI_MASK  (0xFFU)
#define XCVR_TSM_TIMING34_PLL_DIG_EN_TX_HI_SHIFT (0U)
/*! PLL_DIG_EN_TX_HI - Assertion time setting for PLL_DIG_EN (TX) */
#define XCVR_TSM_TIMING34_PLL_DIG_EN_TX_HI(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING34_PLL_DIG_EN_TX_HI_SHIFT)) & XCVR_TSM_TIMING34_PLL_DIG_EN_TX_HI_MASK)

#define XCVR_TSM_TIMING34_PLL_DIG_EN_TX_LO_MASK  (0xFF00U)
#define XCVR_TSM_TIMING34_PLL_DIG_EN_TX_LO_SHIFT (8U)
/*! PLL_DIG_EN_TX_LO - De-assertion time setting for PLL_DIG_EN (TX) */
#define XCVR_TSM_TIMING34_PLL_DIG_EN_TX_LO(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING34_PLL_DIG_EN_TX_LO_SHIFT)) & XCVR_TSM_TIMING34_PLL_DIG_EN_TX_LO_MASK)

#define XCVR_TSM_TIMING34_PLL_DIG_EN_RX_HI_MASK  (0xFF0000U)
#define XCVR_TSM_TIMING34_PLL_DIG_EN_RX_HI_SHIFT (16U)
/*! PLL_DIG_EN_RX_HI - Assertion time setting for PLL_DIG_EN (RX) */
#define XCVR_TSM_TIMING34_PLL_DIG_EN_RX_HI(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING34_PLL_DIG_EN_RX_HI_SHIFT)) & XCVR_TSM_TIMING34_PLL_DIG_EN_RX_HI_MASK)

#define XCVR_TSM_TIMING34_PLL_DIG_EN_RX_LO_MASK  (0xFF000000U)
#define XCVR_TSM_TIMING34_PLL_DIG_EN_RX_LO_SHIFT (24U)
/*! PLL_DIG_EN_RX_LO - De-assertion time setting for PLL_DIG_EN (RX) */
#define XCVR_TSM_TIMING34_PLL_DIG_EN_RX_LO(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING34_PLL_DIG_EN_RX_LO_SHIFT)) & XCVR_TSM_TIMING34_PLL_DIG_EN_RX_LO_MASK)
/*! @} */

/*! @name TIMING35 - TSM_TIMING35 */
/*! @{ */

#define XCVR_TSM_TIMING35_TX_DIG_EN_TX_HI_MASK   (0xFFU)
#define XCVR_TSM_TIMING35_TX_DIG_EN_TX_HI_SHIFT  (0U)
/*! TX_DIG_EN_TX_HI - Assertion time setting for TX_DIG_EN (TX) */
#define XCVR_TSM_TIMING35_TX_DIG_EN_TX_HI(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING35_TX_DIG_EN_TX_HI_SHIFT)) & XCVR_TSM_TIMING35_TX_DIG_EN_TX_HI_MASK)

#define XCVR_TSM_TIMING35_TX_DIG_EN_TX_LO_MASK   (0xFF00U)
#define XCVR_TSM_TIMING35_TX_DIG_EN_TX_LO_SHIFT  (8U)
/*! TX_DIG_EN_TX_LO - De-assertion time setting for TX_DIG_EN (TX) */
#define XCVR_TSM_TIMING35_TX_DIG_EN_TX_LO(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING35_TX_DIG_EN_TX_LO_SHIFT)) & XCVR_TSM_TIMING35_TX_DIG_EN_TX_LO_MASK)
/*! @} */

/*! @name TIMING36 - TSM_TIMING36 */
/*! @{ */

#define XCVR_TSM_TIMING36_RX_DIG_EN_RX_HI_MASK   (0xFF0000U)
#define XCVR_TSM_TIMING36_RX_DIG_EN_RX_HI_SHIFT  (16U)
/*! RX_DIG_EN_RX_HI - Assertion time setting for RX_DIG_EN (RX) */
#define XCVR_TSM_TIMING36_RX_DIG_EN_RX_HI(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING36_RX_DIG_EN_RX_HI_SHIFT)) & XCVR_TSM_TIMING36_RX_DIG_EN_RX_HI_MASK)

#define XCVR_TSM_TIMING36_RX_DIG_EN_RX_LO_MASK   (0xFF000000U)
#define XCVR_TSM_TIMING36_RX_DIG_EN_RX_LO_SHIFT  (24U)
/*! RX_DIG_EN_RX_LO - De-assertion time setting for RX_DIG_EN (RX) */
#define XCVR_TSM_TIMING36_RX_DIG_EN_RX_LO(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING36_RX_DIG_EN_RX_LO_SHIFT)) & XCVR_TSM_TIMING36_RX_DIG_EN_RX_LO_MASK)
/*! @} */

/*! @name TIMING37 - TSM_TIMING37 */
/*! @{ */

#define XCVR_TSM_TIMING37_RX_INIT_RX_HI_MASK     (0xFF0000U)
#define XCVR_TSM_TIMING37_RX_INIT_RX_HI_SHIFT    (16U)
/*! RX_INIT_RX_HI - Assertion time setting for RX_INIT (RX) */
#define XCVR_TSM_TIMING37_RX_INIT_RX_HI(x)       (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING37_RX_INIT_RX_HI_SHIFT)) & XCVR_TSM_TIMING37_RX_INIT_RX_HI_MASK)

#define XCVR_TSM_TIMING37_RX_INIT_RX_LO_MASK     (0xFF000000U)
#define XCVR_TSM_TIMING37_RX_INIT_RX_LO_SHIFT    (24U)
/*! RX_INIT_RX_LO - De-assertion time setting for RX_INIT (RX) */
#define XCVR_TSM_TIMING37_RX_INIT_RX_LO(x)       (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING37_RX_INIT_RX_LO_SHIFT)) & XCVR_TSM_TIMING37_RX_INIT_RX_LO_MASK)
/*! @} */

/*! @name TIMING38 - TSM_TIMING38 */
/*! @{ */

#define XCVR_TSM_TIMING38_SIGMA_DELTA_EN_TX_HI_MASK (0xFFU)
#define XCVR_TSM_TIMING38_SIGMA_DELTA_EN_TX_HI_SHIFT (0U)
/*! SIGMA_DELTA_EN_TX_HI - Assertion time setting for SIGMA_DELTA_EN (TX) */
#define XCVR_TSM_TIMING38_SIGMA_DELTA_EN_TX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING38_SIGMA_DELTA_EN_TX_HI_SHIFT)) & XCVR_TSM_TIMING38_SIGMA_DELTA_EN_TX_HI_MASK)

#define XCVR_TSM_TIMING38_SIGMA_DELTA_EN_TX_LO_MASK (0xFF00U)
#define XCVR_TSM_TIMING38_SIGMA_DELTA_EN_TX_LO_SHIFT (8U)
/*! SIGMA_DELTA_EN_TX_LO - De-assertion time setting for SIGMA_DELTA_EN (TX) */
#define XCVR_TSM_TIMING38_SIGMA_DELTA_EN_TX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING38_SIGMA_DELTA_EN_TX_LO_SHIFT)) & XCVR_TSM_TIMING38_SIGMA_DELTA_EN_TX_LO_MASK)

#define XCVR_TSM_TIMING38_SIGMA_DELTA_EN_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING38_SIGMA_DELTA_EN_RX_HI_SHIFT (16U)
/*! SIGMA_DELTA_EN_RX_HI - Assertion time setting for SIGMA_DELTA_EN (RX) */
#define XCVR_TSM_TIMING38_SIGMA_DELTA_EN_RX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING38_SIGMA_DELTA_EN_RX_HI_SHIFT)) & XCVR_TSM_TIMING38_SIGMA_DELTA_EN_RX_HI_MASK)

#define XCVR_TSM_TIMING38_SIGMA_DELTA_EN_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING38_SIGMA_DELTA_EN_RX_LO_SHIFT (24U)
/*! SIGMA_DELTA_EN_RX_LO - De-assertion time setting for SIGMA_DELTA_EN (RX) */
#define XCVR_TSM_TIMING38_SIGMA_DELTA_EN_RX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING38_SIGMA_DELTA_EN_RX_LO_SHIFT)) & XCVR_TSM_TIMING38_SIGMA_DELTA_EN_RX_LO_MASK)
/*! @} */

/*! @name TIMING39 - TSM_TIMING39 */
/*! @{ */

#define XCVR_TSM_TIMING39_RX_PHY_EN_RX_HI_MASK   (0xFF0000U)
#define XCVR_TSM_TIMING39_RX_PHY_EN_RX_HI_SHIFT  (16U)
/*! RX_PHY_EN_RX_HI - Assertion time setting for RX_PHY_EN (RX) */
#define XCVR_TSM_TIMING39_RX_PHY_EN_RX_HI(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING39_RX_PHY_EN_RX_HI_SHIFT)) & XCVR_TSM_TIMING39_RX_PHY_EN_RX_HI_MASK)

#define XCVR_TSM_TIMING39_RX_PHY_EN_RX_LO_MASK   (0xFF000000U)
#define XCVR_TSM_TIMING39_RX_PHY_EN_RX_LO_SHIFT  (24U)
/*! RX_PHY_EN_RX_LO - De-assertion time setting for RX_PHY_EN (RX) */
#define XCVR_TSM_TIMING39_RX_PHY_EN_RX_LO(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING39_RX_PHY_EN_RX_LO_SHIFT)) & XCVR_TSM_TIMING39_RX_PHY_EN_RX_LO_MASK)
/*! @} */

/*! @name TIMING40 - TSM_TIMING40 */
/*! @{ */

#define XCVR_TSM_TIMING40_DCOC_EN_RX_HI_MASK     (0xFF0000U)
#define XCVR_TSM_TIMING40_DCOC_EN_RX_HI_SHIFT    (16U)
/*! DCOC_EN_RX_HI - Assertion time setting for DCOC_EN (RX) */
#define XCVR_TSM_TIMING40_DCOC_EN_RX_HI(x)       (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING40_DCOC_EN_RX_HI_SHIFT)) & XCVR_TSM_TIMING40_DCOC_EN_RX_HI_MASK)

#define XCVR_TSM_TIMING40_DCOC_EN_RX_LO_MASK     (0xFF000000U)
#define XCVR_TSM_TIMING40_DCOC_EN_RX_LO_SHIFT    (24U)
/*! DCOC_EN_RX_LO - De-assertion time setting for DCOC_EN (RX) */
#define XCVR_TSM_TIMING40_DCOC_EN_RX_LO(x)       (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING40_DCOC_EN_RX_LO_SHIFT)) & XCVR_TSM_TIMING40_DCOC_EN_RX_LO_MASK)
/*! @} */

/*! @name TIMING41 - TSM_TIMING41 */
/*! @{ */

#define XCVR_TSM_TIMING41_DCOC_INIT_RX_HI_MASK   (0xFF0000U)
#define XCVR_TSM_TIMING41_DCOC_INIT_RX_HI_SHIFT  (16U)
/*! DCOC_INIT_RX_HI - Assertion time setting for DCOC_INIT (RX) */
#define XCVR_TSM_TIMING41_DCOC_INIT_RX_HI(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING41_DCOC_INIT_RX_HI_SHIFT)) & XCVR_TSM_TIMING41_DCOC_INIT_RX_HI_MASK)

#define XCVR_TSM_TIMING41_DCOC_INIT_RX_LO_MASK   (0xFF000000U)
#define XCVR_TSM_TIMING41_DCOC_INIT_RX_LO_SHIFT  (24U)
/*! DCOC_INIT_RX_LO - De-assertion time setting for DCOC_INIT (RX) */
#define XCVR_TSM_TIMING41_DCOC_INIT_RX_LO(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING41_DCOC_INIT_RX_LO_SHIFT)) & XCVR_TSM_TIMING41_DCOC_INIT_RX_LO_MASK)
/*! @} */

/*! @name TIMING42 - TSM_TIMING42 */
/*! @{ */

#define XCVR_TSM_TIMING42_SAR_ADC_TRIG_EN_TX_HI_MASK (0xFFU)
#define XCVR_TSM_TIMING42_SAR_ADC_TRIG_EN_TX_HI_SHIFT (0U)
/*! SAR_ADC_TRIG_EN_TX_HI - Assertion time setting for SAR_ADC_TRIG_EN (TX) */
#define XCVR_TSM_TIMING42_SAR_ADC_TRIG_EN_TX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING42_SAR_ADC_TRIG_EN_TX_HI_SHIFT)) & XCVR_TSM_TIMING42_SAR_ADC_TRIG_EN_TX_HI_MASK)

#define XCVR_TSM_TIMING42_SAR_ADC_TRIG_EN_TX_LO_MASK (0xFF00U)
#define XCVR_TSM_TIMING42_SAR_ADC_TRIG_EN_TX_LO_SHIFT (8U)
/*! SAR_ADC_TRIG_EN_TX_LO - De-assertion time setting for SAR_ADC_TRIG_EN (TX) */
#define XCVR_TSM_TIMING42_SAR_ADC_TRIG_EN_TX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING42_SAR_ADC_TRIG_EN_TX_LO_SHIFT)) & XCVR_TSM_TIMING42_SAR_ADC_TRIG_EN_TX_LO_MASK)

#define XCVR_TSM_TIMING42_SAR_ADC_TRIG_EN_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING42_SAR_ADC_TRIG_EN_RX_HI_SHIFT (16U)
/*! SAR_ADC_TRIG_EN_RX_HI - Assertion time setting for SAR_ADC_TRIG_EN (RX) */
#define XCVR_TSM_TIMING42_SAR_ADC_TRIG_EN_RX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING42_SAR_ADC_TRIG_EN_RX_HI_SHIFT)) & XCVR_TSM_TIMING42_SAR_ADC_TRIG_EN_RX_HI_MASK)

#define XCVR_TSM_TIMING42_SAR_ADC_TRIG_EN_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING42_SAR_ADC_TRIG_EN_RX_LO_SHIFT (24U)
/*! SAR_ADC_TRIG_EN_RX_LO - De-assertion time setting for SAR_ADC_TRIG_EN (RX) */
#define XCVR_TSM_TIMING42_SAR_ADC_TRIG_EN_RX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING42_SAR_ADC_TRIG_EN_RX_LO_SHIFT)) & XCVR_TSM_TIMING42_SAR_ADC_TRIG_EN_RX_LO_MASK)
/*! @} */

/*! @name TIMING43 - TSM_TIMING43 */
/*! @{ */

#define XCVR_TSM_TIMING43_TSM_SPARE0_EN_TX_HI_MASK (0xFFU)
#define XCVR_TSM_TIMING43_TSM_SPARE0_EN_TX_HI_SHIFT (0U)
/*! TSM_SPARE0_EN_TX_HI - Assertion time setting for TSM_SPARE0_EN (TX) */
#define XCVR_TSM_TIMING43_TSM_SPARE0_EN_TX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING43_TSM_SPARE0_EN_TX_HI_SHIFT)) & XCVR_TSM_TIMING43_TSM_SPARE0_EN_TX_HI_MASK)

#define XCVR_TSM_TIMING43_TSM_SPARE0_EN_TX_LO_MASK (0xFF00U)
#define XCVR_TSM_TIMING43_TSM_SPARE0_EN_TX_LO_SHIFT (8U)
/*! TSM_SPARE0_EN_TX_LO - De-assertion time setting for TSM_SPARE0_EN (TX) */
#define XCVR_TSM_TIMING43_TSM_SPARE0_EN_TX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING43_TSM_SPARE0_EN_TX_LO_SHIFT)) & XCVR_TSM_TIMING43_TSM_SPARE0_EN_TX_LO_MASK)

#define XCVR_TSM_TIMING43_TSM_SPARE0_EN_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING43_TSM_SPARE0_EN_RX_HI_SHIFT (16U)
/*! TSM_SPARE0_EN_RX_HI - Assertion time setting for TSM_SPARE0_EN (RX) */
#define XCVR_TSM_TIMING43_TSM_SPARE0_EN_RX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING43_TSM_SPARE0_EN_RX_HI_SHIFT)) & XCVR_TSM_TIMING43_TSM_SPARE0_EN_RX_HI_MASK)

#define XCVR_TSM_TIMING43_TSM_SPARE0_EN_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING43_TSM_SPARE0_EN_RX_LO_SHIFT (24U)
/*! TSM_SPARE0_EN_RX_LO - De-assertion time setting for TSM_SPARE0_EN (RX) */
#define XCVR_TSM_TIMING43_TSM_SPARE0_EN_RX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING43_TSM_SPARE0_EN_RX_LO_SHIFT)) & XCVR_TSM_TIMING43_TSM_SPARE0_EN_RX_LO_MASK)
/*! @} */

/*! @name TIMING44 - TSM_TIMING44 */
/*! @{ */

#define XCVR_TSM_TIMING44_TSM_SPARE1_EN_TX_HI_MASK (0xFFU)
#define XCVR_TSM_TIMING44_TSM_SPARE1_EN_TX_HI_SHIFT (0U)
/*! TSM_SPARE1_EN_TX_HI - Assertion time setting for TSM_SPARE1_EN (TX) */
#define XCVR_TSM_TIMING44_TSM_SPARE1_EN_TX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING44_TSM_SPARE1_EN_TX_HI_SHIFT)) & XCVR_TSM_TIMING44_TSM_SPARE1_EN_TX_HI_MASK)

#define XCVR_TSM_TIMING44_TSM_SPARE1_EN_TX_LO_MASK (0xFF00U)
#define XCVR_TSM_TIMING44_TSM_SPARE1_EN_TX_LO_SHIFT (8U)
/*! TSM_SPARE1_EN_TX_LO - De-assertion time setting for TSM_SPARE1_EN (TX) */
#define XCVR_TSM_TIMING44_TSM_SPARE1_EN_TX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING44_TSM_SPARE1_EN_TX_LO_SHIFT)) & XCVR_TSM_TIMING44_TSM_SPARE1_EN_TX_LO_MASK)

#define XCVR_TSM_TIMING44_TSM_SPARE1_EN_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING44_TSM_SPARE1_EN_RX_HI_SHIFT (16U)
/*! TSM_SPARE1_EN_RX_HI - Assertion time setting for TSM_SPARE1_EN (RX) */
#define XCVR_TSM_TIMING44_TSM_SPARE1_EN_RX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING44_TSM_SPARE1_EN_RX_HI_SHIFT)) & XCVR_TSM_TIMING44_TSM_SPARE1_EN_RX_HI_MASK)

#define XCVR_TSM_TIMING44_TSM_SPARE1_EN_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING44_TSM_SPARE1_EN_RX_LO_SHIFT (24U)
/*! TSM_SPARE1_EN_RX_LO - De-assertion time setting for TSM_SPARE1_EN (RX) */
#define XCVR_TSM_TIMING44_TSM_SPARE1_EN_RX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING44_TSM_SPARE1_EN_RX_LO_SHIFT)) & XCVR_TSM_TIMING44_TSM_SPARE1_EN_RX_LO_MASK)
/*! @} */

/*! @name TIMING45 - TSM_TIMING45 */
/*! @{ */

#define XCVR_TSM_TIMING45_TSM_SPARE2_EN_TX_HI_MASK (0xFFU)
#define XCVR_TSM_TIMING45_TSM_SPARE2_EN_TX_HI_SHIFT (0U)
/*! TSM_SPARE2_EN_TX_HI - Assertion time setting for TSM_SPARE2_EN (TX) */
#define XCVR_TSM_TIMING45_TSM_SPARE2_EN_TX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING45_TSM_SPARE2_EN_TX_HI_SHIFT)) & XCVR_TSM_TIMING45_TSM_SPARE2_EN_TX_HI_MASK)

#define XCVR_TSM_TIMING45_TSM_SPARE2_EN_TX_LO_MASK (0xFF00U)
#define XCVR_TSM_TIMING45_TSM_SPARE2_EN_TX_LO_SHIFT (8U)
/*! TSM_SPARE2_EN_TX_LO - De-assertion time setting for TSM_SPARE2_EN (TX) */
#define XCVR_TSM_TIMING45_TSM_SPARE2_EN_TX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING45_TSM_SPARE2_EN_TX_LO_SHIFT)) & XCVR_TSM_TIMING45_TSM_SPARE2_EN_TX_LO_MASK)

#define XCVR_TSM_TIMING45_TSM_SPARE2_EN_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING45_TSM_SPARE2_EN_RX_HI_SHIFT (16U)
/*! TSM_SPARE2_EN_RX_HI - Assertion time setting for TSM_SPARE2_EN (RX) */
#define XCVR_TSM_TIMING45_TSM_SPARE2_EN_RX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING45_TSM_SPARE2_EN_RX_HI_SHIFT)) & XCVR_TSM_TIMING45_TSM_SPARE2_EN_RX_HI_MASK)

#define XCVR_TSM_TIMING45_TSM_SPARE2_EN_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING45_TSM_SPARE2_EN_RX_LO_SHIFT (24U)
/*! TSM_SPARE2_EN_RX_LO - De-assertion time setting for TSM_SPARE2_EN (RX) */
#define XCVR_TSM_TIMING45_TSM_SPARE2_EN_RX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING45_TSM_SPARE2_EN_RX_LO_SHIFT)) & XCVR_TSM_TIMING45_TSM_SPARE2_EN_RX_LO_MASK)
/*! @} */

/*! @name TIMING46 - TSM_TIMING46 */
/*! @{ */

#define XCVR_TSM_TIMING46_TSM_SPARE3_EN_TX_HI_MASK (0xFFU)
#define XCVR_TSM_TIMING46_TSM_SPARE3_EN_TX_HI_SHIFT (0U)
/*! TSM_SPARE3_EN_TX_HI - Assertion time setting for TSM_SPARE3_EN (TX) */
#define XCVR_TSM_TIMING46_TSM_SPARE3_EN_TX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING46_TSM_SPARE3_EN_TX_HI_SHIFT)) & XCVR_TSM_TIMING46_TSM_SPARE3_EN_TX_HI_MASK)

#define XCVR_TSM_TIMING46_TSM_SPARE3_EN_TX_LO_MASK (0xFF00U)
#define XCVR_TSM_TIMING46_TSM_SPARE3_EN_TX_LO_SHIFT (8U)
/*! TSM_SPARE3_EN_TX_LO - De-assertion time setting for TSM_SPARE3_EN (TX) */
#define XCVR_TSM_TIMING46_TSM_SPARE3_EN_TX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING46_TSM_SPARE3_EN_TX_LO_SHIFT)) & XCVR_TSM_TIMING46_TSM_SPARE3_EN_TX_LO_MASK)

#define XCVR_TSM_TIMING46_TSM_SPARE3_EN_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING46_TSM_SPARE3_EN_RX_HI_SHIFT (16U)
/*! TSM_SPARE3_EN_RX_HI - Assertion time setting for TSM_SPARE3_EN (RX) */
#define XCVR_TSM_TIMING46_TSM_SPARE3_EN_RX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING46_TSM_SPARE3_EN_RX_HI_SHIFT)) & XCVR_TSM_TIMING46_TSM_SPARE3_EN_RX_HI_MASK)

#define XCVR_TSM_TIMING46_TSM_SPARE3_EN_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING46_TSM_SPARE3_EN_RX_LO_SHIFT (24U)
/*! TSM_SPARE3_EN_RX_LO - De-assertion time setting for TSM_SPARE3_EN (RX) */
#define XCVR_TSM_TIMING46_TSM_SPARE3_EN_RX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING46_TSM_SPARE3_EN_RX_LO_SHIFT)) & XCVR_TSM_TIMING46_TSM_SPARE3_EN_RX_LO_MASK)
/*! @} */

/*! @name TIMING47 - TSM_TIMING47 */
/*! @{ */

#define XCVR_TSM_TIMING47_GPIO0_TRIG_EN_TX_HI_MASK (0xFFU)
#define XCVR_TSM_TIMING47_GPIO0_TRIG_EN_TX_HI_SHIFT (0U)
/*! GPIO0_TRIG_EN_TX_HI - Assertion time setting for GPIO0_TRIG_EN (TX) */
#define XCVR_TSM_TIMING47_GPIO0_TRIG_EN_TX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING47_GPIO0_TRIG_EN_TX_HI_SHIFT)) & XCVR_TSM_TIMING47_GPIO0_TRIG_EN_TX_HI_MASK)

#define XCVR_TSM_TIMING47_GPIO0_TRIG_EN_TX_LO_MASK (0xFF00U)
#define XCVR_TSM_TIMING47_GPIO0_TRIG_EN_TX_LO_SHIFT (8U)
/*! GPIO0_TRIG_EN_TX_LO - De-assertion time setting for GPIO0_TRIG_EN (TX) */
#define XCVR_TSM_TIMING47_GPIO0_TRIG_EN_TX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING47_GPIO0_TRIG_EN_TX_LO_SHIFT)) & XCVR_TSM_TIMING47_GPIO0_TRIG_EN_TX_LO_MASK)

#define XCVR_TSM_TIMING47_GPIO0_TRIG_EN_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING47_GPIO0_TRIG_EN_RX_HI_SHIFT (16U)
/*! GPIO0_TRIG_EN_RX_HI - Assertion time setting for GPIO0_TRIG_EN (RX) */
#define XCVR_TSM_TIMING47_GPIO0_TRIG_EN_RX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING47_GPIO0_TRIG_EN_RX_HI_SHIFT)) & XCVR_TSM_TIMING47_GPIO0_TRIG_EN_RX_HI_MASK)

#define XCVR_TSM_TIMING47_GPIO0_TRIG_EN_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING47_GPIO0_TRIG_EN_RX_LO_SHIFT (24U)
/*! GPIO0_TRIG_EN_RX_LO - De-assertion time setting for GPIO0_TRIG_EN (RX) */
#define XCVR_TSM_TIMING47_GPIO0_TRIG_EN_RX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING47_GPIO0_TRIG_EN_RX_LO_SHIFT)) & XCVR_TSM_TIMING47_GPIO0_TRIG_EN_RX_LO_MASK)
/*! @} */

/*! @name TIMING48 - TSM_TIMING48 */
/*! @{ */

#define XCVR_TSM_TIMING48_GPIO1_TRIG_EN_TX_HI_MASK (0xFFU)
#define XCVR_TSM_TIMING48_GPIO1_TRIG_EN_TX_HI_SHIFT (0U)
/*! GPIO1_TRIG_EN_TX_HI - Assertion time setting for GPIO1_TRIG_EN (TX) */
#define XCVR_TSM_TIMING48_GPIO1_TRIG_EN_TX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING48_GPIO1_TRIG_EN_TX_HI_SHIFT)) & XCVR_TSM_TIMING48_GPIO1_TRIG_EN_TX_HI_MASK)

#define XCVR_TSM_TIMING48_GPIO1_TRIG_EN_TX_LO_MASK (0xFF00U)
#define XCVR_TSM_TIMING48_GPIO1_TRIG_EN_TX_LO_SHIFT (8U)
/*! GPIO1_TRIG_EN_TX_LO - De-assertion time setting for GPIO1_TRIG_EN (TX) */
#define XCVR_TSM_TIMING48_GPIO1_TRIG_EN_TX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING48_GPIO1_TRIG_EN_TX_LO_SHIFT)) & XCVR_TSM_TIMING48_GPIO1_TRIG_EN_TX_LO_MASK)

#define XCVR_TSM_TIMING48_GPIO1_TRIG_EN_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING48_GPIO1_TRIG_EN_RX_HI_SHIFT (16U)
/*! GPIO1_TRIG_EN_RX_HI - Assertion time setting for GPIO1_TRIG_EN (RX) */
#define XCVR_TSM_TIMING48_GPIO1_TRIG_EN_RX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING48_GPIO1_TRIG_EN_RX_HI_SHIFT)) & XCVR_TSM_TIMING48_GPIO1_TRIG_EN_RX_HI_MASK)

#define XCVR_TSM_TIMING48_GPIO1_TRIG_EN_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING48_GPIO1_TRIG_EN_RX_LO_SHIFT (24U)
/*! GPIO1_TRIG_EN_RX_LO - De-assertion time setting for GPIO1_TRIG_EN (RX) */
#define XCVR_TSM_TIMING48_GPIO1_TRIG_EN_RX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING48_GPIO1_TRIG_EN_RX_LO_SHIFT)) & XCVR_TSM_TIMING48_GPIO1_TRIG_EN_RX_LO_MASK)
/*! @} */

/*! @name TIMING49 - TSM_TIMING49 */
/*! @{ */

#define XCVR_TSM_TIMING49_GPIO2_TRIG_EN_TX_HI_MASK (0xFFU)
#define XCVR_TSM_TIMING49_GPIO2_TRIG_EN_TX_HI_SHIFT (0U)
/*! GPIO2_TRIG_EN_TX_HI - Assertion time setting for GPIO2_TRIG_EN (TX) */
#define XCVR_TSM_TIMING49_GPIO2_TRIG_EN_TX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING49_GPIO2_TRIG_EN_TX_HI_SHIFT)) & XCVR_TSM_TIMING49_GPIO2_TRIG_EN_TX_HI_MASK)

#define XCVR_TSM_TIMING49_GPIO2_TRIG_EN_TX_LO_MASK (0xFF00U)
#define XCVR_TSM_TIMING49_GPIO2_TRIG_EN_TX_LO_SHIFT (8U)
/*! GPIO2_TRIG_EN_TX_LO - De-assertion time setting for GPIO2_TRIG_EN (TX) */
#define XCVR_TSM_TIMING49_GPIO2_TRIG_EN_TX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING49_GPIO2_TRIG_EN_TX_LO_SHIFT)) & XCVR_TSM_TIMING49_GPIO2_TRIG_EN_TX_LO_MASK)

#define XCVR_TSM_TIMING49_GPIO2_TRIG_EN_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING49_GPIO2_TRIG_EN_RX_HI_SHIFT (16U)
/*! GPIO2_TRIG_EN_RX_HI - Assertion time setting for GPIO2_TRIG_EN (RX) */
#define XCVR_TSM_TIMING49_GPIO2_TRIG_EN_RX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING49_GPIO2_TRIG_EN_RX_HI_SHIFT)) & XCVR_TSM_TIMING49_GPIO2_TRIG_EN_RX_HI_MASK)

#define XCVR_TSM_TIMING49_GPIO2_TRIG_EN_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING49_GPIO2_TRIG_EN_RX_LO_SHIFT (24U)
/*! GPIO2_TRIG_EN_RX_LO - De-assertion time setting for GPIO2_TRIG_EN (RX) */
#define XCVR_TSM_TIMING49_GPIO2_TRIG_EN_RX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING49_GPIO2_TRIG_EN_RX_LO_SHIFT)) & XCVR_TSM_TIMING49_GPIO2_TRIG_EN_RX_LO_MASK)
/*! @} */

/*! @name TIMING50 - TSM_TIMING50 */
/*! @{ */

#define XCVR_TSM_TIMING50_GPIO3_TRIG_EN_TX_HI_MASK (0xFFU)
#define XCVR_TSM_TIMING50_GPIO3_TRIG_EN_TX_HI_SHIFT (0U)
/*! GPIO3_TRIG_EN_TX_HI - Assertion time setting for GPIO3_TRIG_EN (TX) */
#define XCVR_TSM_TIMING50_GPIO3_TRIG_EN_TX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING50_GPIO3_TRIG_EN_TX_HI_SHIFT)) & XCVR_TSM_TIMING50_GPIO3_TRIG_EN_TX_HI_MASK)

#define XCVR_TSM_TIMING50_GPIO3_TRIG_EN_TX_LO_MASK (0xFF00U)
#define XCVR_TSM_TIMING50_GPIO3_TRIG_EN_TX_LO_SHIFT (8U)
/*! GPIO3_TRIG_EN_TX_LO - De-assertion time setting for GPIO3_TRIG_EN (TX) */
#define XCVR_TSM_TIMING50_GPIO3_TRIG_EN_TX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING50_GPIO3_TRIG_EN_TX_LO_SHIFT)) & XCVR_TSM_TIMING50_GPIO3_TRIG_EN_TX_LO_MASK)

#define XCVR_TSM_TIMING50_GPIO3_TRIG_EN_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING50_GPIO3_TRIG_EN_RX_HI_SHIFT (16U)
/*! GPIO3_TRIG_EN_RX_HI - Assertion time setting for GPIO3_TRIG_EN (RX) */
#define XCVR_TSM_TIMING50_GPIO3_TRIG_EN_RX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING50_GPIO3_TRIG_EN_RX_HI_SHIFT)) & XCVR_TSM_TIMING50_GPIO3_TRIG_EN_RX_HI_MASK)

#define XCVR_TSM_TIMING50_GPIO3_TRIG_EN_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING50_GPIO3_TRIG_EN_RX_LO_SHIFT (24U)
/*! GPIO3_TRIG_EN_RX_LO - De-assertion time setting for GPIO3_TRIG_EN (RX) */
#define XCVR_TSM_TIMING50_GPIO3_TRIG_EN_RX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING50_GPIO3_TRIG_EN_RX_LO_SHIFT)) & XCVR_TSM_TIMING50_GPIO3_TRIG_EN_RX_LO_MASK)
/*! @} */

/*! @name TIMING51 - TSM_TIMING51 */
/*! @{ */

#define XCVR_TSM_TIMING51_RXTX_AUXPLL_BIAS_EN_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING51_RXTX_AUXPLL_BIAS_EN_RX_HI_SHIFT (16U)
/*! RXTX_AUXPLL_BIAS_EN_RX_HI - Assertion time setting for RXTX_AUXPLL_BIAS_EN (RX) */
#define XCVR_TSM_TIMING51_RXTX_AUXPLL_BIAS_EN_RX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING51_RXTX_AUXPLL_BIAS_EN_RX_HI_SHIFT)) & XCVR_TSM_TIMING51_RXTX_AUXPLL_BIAS_EN_RX_HI_MASK)

#define XCVR_TSM_TIMING51_RXTX_AUXPLL_BIAS_EN_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING51_RXTX_AUXPLL_BIAS_EN_RX_LO_SHIFT (24U)
/*! RXTX_AUXPLL_BIAS_EN_RX_LO - De-assertion time setting for RXTX_AUXPLL_BIAS_EN (RX) */
#define XCVR_TSM_TIMING51_RXTX_AUXPLL_BIAS_EN_RX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING51_RXTX_AUXPLL_BIAS_EN_RX_LO_SHIFT)) & XCVR_TSM_TIMING51_RXTX_AUXPLL_BIAS_EN_RX_LO_MASK)
/*! @} */

/*! @name TIMING52 - TSM_TIMING52 */
/*! @{ */

#define XCVR_TSM_TIMING52_RXTX_AUXPLL_FCAL_EN_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING52_RXTX_AUXPLL_FCAL_EN_RX_HI_SHIFT (16U)
/*! RXTX_AUXPLL_FCAL_EN_RX_HI - Assertion time setting for RXTX_AUXPLL_FCAL_EN (RX) */
#define XCVR_TSM_TIMING52_RXTX_AUXPLL_FCAL_EN_RX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING52_RXTX_AUXPLL_FCAL_EN_RX_HI_SHIFT)) & XCVR_TSM_TIMING52_RXTX_AUXPLL_FCAL_EN_RX_HI_MASK)

#define XCVR_TSM_TIMING52_RXTX_AUXPLL_FCAL_EN_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING52_RXTX_AUXPLL_FCAL_EN_RX_LO_SHIFT (24U)
/*! RXTX_AUXPLL_FCAL_EN_RX_LO - De-assertion time setting for RXTX_AUXPLL_FCAL_EN (RX) */
#define XCVR_TSM_TIMING52_RXTX_AUXPLL_FCAL_EN_RX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING52_RXTX_AUXPLL_FCAL_EN_RX_LO_SHIFT)) & XCVR_TSM_TIMING52_RXTX_AUXPLL_FCAL_EN_RX_LO_MASK)
/*! @} */

/*! @name TIMING53 - TSM_TIMING53 */
/*! @{ */

#define XCVR_TSM_TIMING53_RXTX_AUXPLL_LF_PD_EN_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING53_RXTX_AUXPLL_LF_PD_EN_RX_HI_SHIFT (16U)
/*! RXTX_AUXPLL_LF_PD_EN_RX_HI - Assertion time setting for RXTX_AUXPLL_LF_PD_EN (RX) */
#define XCVR_TSM_TIMING53_RXTX_AUXPLL_LF_PD_EN_RX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING53_RXTX_AUXPLL_LF_PD_EN_RX_HI_SHIFT)) & XCVR_TSM_TIMING53_RXTX_AUXPLL_LF_PD_EN_RX_HI_MASK)

#define XCVR_TSM_TIMING53_RXTX_AUXPLL_LF_PD_EN_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING53_RXTX_AUXPLL_LF_PD_EN_RX_LO_SHIFT (24U)
/*! RXTX_AUXPLL_LF_PD_EN_RX_LO - De-assertion time setting for RXTX_AUXPLL_LF_PD_EN (RX) */
#define XCVR_TSM_TIMING53_RXTX_AUXPLL_LF_PD_EN_RX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING53_RXTX_AUXPLL_LF_PD_EN_RX_LO_SHIFT)) & XCVR_TSM_TIMING53_RXTX_AUXPLL_LF_PD_EN_RX_LO_MASK)
/*! @} */

/*! @name TIMING54 - TSM_TIMING54 */
/*! @{ */

#define XCVR_TSM_TIMING54_RXTX_AUXPLL_PD_LF_FILTER_CHARGE_EN_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING54_RXTX_AUXPLL_PD_LF_FILTER_CHARGE_EN_RX_HI_SHIFT (16U)
/*! RXTX_AUXPLL_PD_LF_FILTER_CHARGE_EN_RX_HI - Assertion time setting for RXTX_AUXPLL_PD_LF_FILTER_CHARGE_EN (RX) */
#define XCVR_TSM_TIMING54_RXTX_AUXPLL_PD_LF_FILTER_CHARGE_EN_RX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING54_RXTX_AUXPLL_PD_LF_FILTER_CHARGE_EN_RX_HI_SHIFT)) & XCVR_TSM_TIMING54_RXTX_AUXPLL_PD_LF_FILTER_CHARGE_EN_RX_HI_MASK)

#define XCVR_TSM_TIMING54_RXTX_AUXPLL_PD_LF_FILTER_CHARGE_EN_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING54_RXTX_AUXPLL_PD_LF_FILTER_CHARGE_EN_RX_LO_SHIFT (24U)
/*! RXTX_AUXPLL_PD_LF_FILTER_CHARGE_EN_RX_LO - De-assertion time setting for RXTX_AUXPLL_PD_LF_FILTER_CHARGE_EN (RX) */
#define XCVR_TSM_TIMING54_RXTX_AUXPLL_PD_LF_FILTER_CHARGE_EN_RX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING54_RXTX_AUXPLL_PD_LF_FILTER_CHARGE_EN_RX_LO_SHIFT)) & XCVR_TSM_TIMING54_RXTX_AUXPLL_PD_LF_FILTER_CHARGE_EN_RX_LO_MASK)
/*! @} */

/*! @name TIMING55 - TSM_TIMING55 */
/*! @{ */

#define XCVR_TSM_TIMING55_RXTX_AUXPLL_ADC_BUF_EN_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING55_RXTX_AUXPLL_ADC_BUF_EN_RX_HI_SHIFT (16U)
/*! RXTX_AUXPLL_ADC_BUF_EN_RX_HI - Assertion time setting for RXTX_AUXPLL_ADC_BUF_EN (RX) */
#define XCVR_TSM_TIMING55_RXTX_AUXPLL_ADC_BUF_EN_RX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING55_RXTX_AUXPLL_ADC_BUF_EN_RX_HI_SHIFT)) & XCVR_TSM_TIMING55_RXTX_AUXPLL_ADC_BUF_EN_RX_HI_MASK)

#define XCVR_TSM_TIMING55_RXTX_AUXPLL_ADC_BUF_EN_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING55_RXTX_AUXPLL_ADC_BUF_EN_RX_LO_SHIFT (24U)
/*! RXTX_AUXPLL_ADC_BUF_EN_RX_LO - De-assertion time setting for RXTX_AUXPLL_ADC_BUF_EN (RX) */
#define XCVR_TSM_TIMING55_RXTX_AUXPLL_ADC_BUF_EN_RX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING55_RXTX_AUXPLL_ADC_BUF_EN_RX_LO_SHIFT)) & XCVR_TSM_TIMING55_RXTX_AUXPLL_ADC_BUF_EN_RX_LO_MASK)
/*! @} */

/*! @name TIMING56 - TSM_TIMING56 */
/*! @{ */

#define XCVR_TSM_TIMING56_RXTX_AUXPLL_DIG_BUF_EN_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING56_RXTX_AUXPLL_DIG_BUF_EN_RX_HI_SHIFT (16U)
/*! RXTX_AUXPLL_DIG_BUF_EN_RX_HI - Assertion time setting for RXTX_AUXPLL_DIG_BUF_EN (RX) */
#define XCVR_TSM_TIMING56_RXTX_AUXPLL_DIG_BUF_EN_RX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING56_RXTX_AUXPLL_DIG_BUF_EN_RX_HI_SHIFT)) & XCVR_TSM_TIMING56_RXTX_AUXPLL_DIG_BUF_EN_RX_HI_MASK)

#define XCVR_TSM_TIMING56_RXTX_AUXPLL_DIG_BUF_EN_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING56_RXTX_AUXPLL_DIG_BUF_EN_RX_LO_SHIFT (24U)
/*! RXTX_AUXPLL_DIG_BUF_EN_RX_LO - De-assertion time setting for RXTX_AUXPLL_DIG_BUF_EN (RX) */
#define XCVR_TSM_TIMING56_RXTX_AUXPLL_DIG_BUF_EN_RX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING56_RXTX_AUXPLL_DIG_BUF_EN_RX_LO_SHIFT)) & XCVR_TSM_TIMING56_RXTX_AUXPLL_DIG_BUF_EN_RX_LO_MASK)
/*! @} */

/*! @name TIMING57 - TSM_TIMING57 */
/*! @{ */

#define XCVR_TSM_TIMING57_RXTX_RCCAL_EN_RX_HI_MASK (0xFF0000U)
#define XCVR_TSM_TIMING57_RXTX_RCCAL_EN_RX_HI_SHIFT (16U)
/*! RXTX_RCCAL_EN_RX_HI - Assertion time setting for RXTX_RCCAL_EN (RX) */
#define XCVR_TSM_TIMING57_RXTX_RCCAL_EN_RX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING57_RXTX_RCCAL_EN_RX_HI_SHIFT)) & XCVR_TSM_TIMING57_RXTX_RCCAL_EN_RX_HI_MASK)

#define XCVR_TSM_TIMING57_RXTX_RCCAL_EN_RX_LO_MASK (0xFF000000U)
#define XCVR_TSM_TIMING57_RXTX_RCCAL_EN_RX_LO_SHIFT (24U)
/*! RXTX_RCCAL_EN_RX_LO - De-assertion time setting for RXTX_RCCAL_EN (RX) */
#define XCVR_TSM_TIMING57_RXTX_RCCAL_EN_RX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING57_RXTX_RCCAL_EN_RX_LO_SHIFT)) & XCVR_TSM_TIMING57_RXTX_RCCAL_EN_RX_LO_MASK)
/*! @} */

/*! @name TIMING58 - TSM_TIMING58 */
/*! @{ */

#define XCVR_TSM_TIMING58_TX_HPM_DAC_EN_TX_HI_MASK (0xFFU)
#define XCVR_TSM_TIMING58_TX_HPM_DAC_EN_TX_HI_SHIFT (0U)
/*! TX_HPM_DAC_EN_TX_HI - Assertion time setting for TX_HPM_DAC_EN (TX) */
#define XCVR_TSM_TIMING58_TX_HPM_DAC_EN_TX_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING58_TX_HPM_DAC_EN_TX_HI_SHIFT)) & XCVR_TSM_TIMING58_TX_HPM_DAC_EN_TX_HI_MASK)

#define XCVR_TSM_TIMING58_TX_HPM_DAC_EN_TX_LO_MASK (0xFF00U)
#define XCVR_TSM_TIMING58_TX_HPM_DAC_EN_TX_LO_SHIFT (8U)
/*! TX_HPM_DAC_EN_TX_LO - De-assertion time setting for TX_HPM_DAC_EN (TX) */
#define XCVR_TSM_TIMING58_TX_HPM_DAC_EN_TX_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TSM_TIMING58_TX_HPM_DAC_EN_TX_LO_SHIFT)) & XCVR_TSM_TIMING58_TX_HPM_DAC_EN_TX_LO_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group XCVR_TSM_Register_Masks */


/*!
 * @}
 */ /* end of group XCVR_TSM_Peripheral_Access_Layer */


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


#endif  /* XCVR_TSM_H_ */

