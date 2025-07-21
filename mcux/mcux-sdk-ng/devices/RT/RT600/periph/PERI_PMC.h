/*
** ###################################################################
**     Processors:          MIMXRT633SFAWBR
**                          MIMXRT633SFFOB
**                          MIMXRT633SFVKB
**                          MIMXRT685SFAWBR_cm33
**                          MIMXRT685SFAWBR_dsp
**                          MIMXRT685SFFOB_cm33
**                          MIMXRT685SFFOB_dsp
**                          MIMXRT685SFVKB_cm33
**                          MIMXRT685SFVKB_dsp
**                          MIMXRT685SVFVKB_cm33
**                          MIMXRT685SVFVKB_dsp
**
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for PMC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2018-06-19)
**         Initial version.
**     - rev. 2.0 (2019-11-12)
**         Base on rev 0.95 RM (B0 Header)
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_PMC.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for PMC
 *
 * CMSIS Peripheral Access Layer for PMC
 */

#if !defined(PERI_PMC_H_)
#define PERI_PMC_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT633SFAWBR) || defined(CPU_MIMXRT633SFFOB) || defined(CPU_MIMXRT633SFVKB))
#include "MIMXRT633S_COMMON.h"
#elif (defined(CPU_MIMXRT685SFAWBR_cm33) || defined(CPU_MIMXRT685SFFOB_cm33) || defined(CPU_MIMXRT685SFVKB_cm33) || defined(CPU_MIMXRT685SVFVKB_cm33))
#include "MIMXRT685S_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT685SFAWBR_dsp) || defined(CPU_MIMXRT685SFFOB_dsp) || defined(CPU_MIMXRT685SFVKB_dsp) || defined(CPU_MIMXRT685SVFVKB_dsp))
#include "MIMXRT685S_dsp_COMMON.h"
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
#elif defined(__XTENSA__)
  /* anonymous unions are enabled by default */
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- PMC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PMC_Peripheral_Access_Layer PMC Peripheral Access Layer
 * @{
 */

/** PMC - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[4];
  __I  uint32_t STATUS;                            /**< PMC status, offset: 0x4 */
  __IO uint32_t FLAGS;                             /**< Wakeup, interrupt, and reset flags, offset: 0x8 */
  __IO uint32_t CTRL;                              /**< PMC control register, offset: 0xC */
  __IO uint32_t RUNCTRL;                           /**< PMC controls used during run mode, offset: 0x10 */
  __IO uint32_t SLEEPCTRL;                         /**< PMC controls used during deep sleep mode, offset: 0x14 */
  __IO uint32_t LVDCORECTRL;                       /**< Active vddcore LVD monitor trip adjust, offset: 0x18 */
       uint8_t RESERVED_1[8];
  __IO uint32_t AUTOWKUP;                          /**< Automatic wakeup from deepsleep / deep powerdown modes, offset: 0x24 */
  __IO uint32_t PMICCFG;                           /**< PMIC power mode select control configuration to let PMC know when vddcore or vdd1v8 will power off/on, offset: 0x28 */
  __IO uint32_t PADVRANGE;                         /**< GPIO vdde range selection control, offset: 0x2C */
  __IO uint32_t MEMSEQCTRL;                        /**< Memory Sequencer Control Register, offset: 0x30 */
} PMC_Type;

/* ----------------------------------------------------------------------------
   -- PMC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PMC_Register_Masks PMC Register Masks
 * @{
 */

/*! @name STATUS - PMC status */
/*! @{ */

#define PMC_STATUS_ACTIVEFSM_MASK                (0x1U)
#define PMC_STATUS_ACTIVEFSM_SHIFT               (0U)
/*! ACTIVEFSM - General sequencer and finite state machine status
 *  0b0..All PMC finite state machines are idle. OK to set APPLYCFG to trigger the PMC state machines.
 *  0b1..One or more PMC finite state machines are active, do not set APPLYCFG or write to any PDRUNCFG or CTRL
 *       register values that are used by the PMC state machines.
 */
#define PMC_STATUS_ACTIVEFSM(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_STATUS_ACTIVEFSM_SHIFT)) & PMC_STATUS_ACTIVEFSM_MASK)
/*! @} */

/*! @name FLAGS - Wakeup, interrupt, and reset flags */
/*! @{ */

#define PMC_FLAGS_PORCOREF_MASK                  (0x10000U)
#define PMC_FLAGS_PORCOREF_SHIFT                 (16U)
/*! PORCOREF
 *  0b0..vddcore POR was not tripped since the last cleared.
 *  0b1..POR triggered by the vddcore POR monitor. Write 1 to clear
 */
#define PMC_FLAGS_PORCOREF(x)                    (((uint32_t)(((uint32_t)(x)) << PMC_FLAGS_PORCOREF_SHIFT)) & PMC_FLAGS_PORCOREF_MASK)

#define PMC_FLAGS_POR1V8F_MASK                   (0x20000U)
#define PMC_FLAGS_POR1V8F_SHIFT                  (17U)
/*! POR1V8F
 *  0b0..No vdd1v8 power on event detected since last cleared.
 *  0b1..vdd1v8 power on detect caused a reset or deep pd wakeup. Write 1 to clear.
 */
#define PMC_FLAGS_POR1V8F(x)                     (((uint32_t)(((uint32_t)(x)) << PMC_FLAGS_POR1V8F_SHIFT)) & PMC_FLAGS_POR1V8F_MASK)

#define PMC_FLAGS_PORAO18F_MASK                  (0x40000U)
#define PMC_FLAGS_PORAO18F_SHIFT                 (18U)
/*! PORAO18F
 *  0b0..No vdd_ao18 power on event detected since last cleared.
 *  0b1..vdd_ao18 power on detect caused a reset. Write 1 to clear.
 */
#define PMC_FLAGS_PORAO18F(x)                    (((uint32_t)(((uint32_t)(x)) << PMC_FLAGS_PORAO18F_SHIFT)) & PMC_FLAGS_PORAO18F_MASK)

#define PMC_FLAGS_LVDCOREF_MASK                  (0x100000U)
#define PMC_FLAGS_LVDCOREF_SHIFT                 (20U)
/*! LVDCOREF
 *  0b0..vddcore LVD has not triggered an interrupt or reset since last clear
 *  0b1..vddcore LVD triggered an interrupt or reset since last time this bit was cleared. Write 1 to clear
 */
#define PMC_FLAGS_LVDCOREF(x)                    (((uint32_t)(((uint32_t)(x)) << PMC_FLAGS_LVDCOREF_SHIFT)) & PMC_FLAGS_LVDCOREF_MASK)

#define PMC_FLAGS_HVDCOREF_MASK                  (0x400000U)
#define PMC_FLAGS_HVDCOREF_SHIFT                 (22U)
/*! HVDCOREF
 *  0b0..vddcore HVD has not triggered an interrupt or reset since last clear
 *  0b1..vddcore HVD triggered an interrupt or reset since last time this bit was cleared. Write 1 to clear
 */
#define PMC_FLAGS_HVDCOREF(x)                    (((uint32_t)(((uint32_t)(x)) << PMC_FLAGS_HVDCOREF_SHIFT)) & PMC_FLAGS_HVDCOREF_MASK)

#define PMC_FLAGS_HVD1V8F_MASK                   (0x1000000U)
#define PMC_FLAGS_HVD1V8F_SHIFT                  (24U)
/*! HVD1V8F
 *  0b0..vdd1v8 HVD has not triggered an interrupt or reset since last clear
 *  0b1..vdd1v8 HVD triggered an interrupt or reset since last time this bit was cleared. Write 1 to clear
 */
#define PMC_FLAGS_HVD1V8F(x)                     (((uint32_t)(((uint32_t)(x)) << PMC_FLAGS_HVD1V8F_SHIFT)) & PMC_FLAGS_HVD1V8F_MASK)

#define PMC_FLAGS_RTCF_MASK                      (0x8000000U)
#define PMC_FLAGS_RTCF_SHIFT                     (27U)
/*! RTCF
 *  0b0..No RTC wakeup detected since last time flag was cleared.
 *  0b1..RTC wakeup caused a deep powerdown wakeup. Write 1 to clear.
 */
#define PMC_FLAGS_RTCF(x)                        (((uint32_t)(((uint32_t)(x)) << PMC_FLAGS_RTCF_SHIFT)) & PMC_FLAGS_RTCF_MASK)

#define PMC_FLAGS_AUTOWKF_MASK                   (0x10000000U)
#define PMC_FLAGS_AUTOWKF_SHIFT                  (28U)
/*! AUTOWKF
 *  0b0..No PMC Auto Wakeup Interrupt detected since last time cleared.
 *  0b1..PMC Auto wakeup caused a deep sleep wakeup and interrupt. Write 1 to clear.
 */
#define PMC_FLAGS_AUTOWKF(x)                     (((uint32_t)(((uint32_t)(x)) << PMC_FLAGS_AUTOWKF_SHIFT)) & PMC_FLAGS_AUTOWKF_MASK)

#define PMC_FLAGS_INTNPADF_MASK                  (0x20000000U)
#define PMC_FLAGS_INTNPADF_SHIFT                 (29U)
/*! INTNPADF
 *  0b0..No interrupt detected since flag last cleared.
 *  0b1..Pad interrupt caused a wakeup or interrupt event since the last time this flag was cleared. Write 1 to clear.
 */
#define PMC_FLAGS_INTNPADF(x)                    (((uint32_t)(((uint32_t)(x)) << PMC_FLAGS_INTNPADF_SHIFT)) & PMC_FLAGS_INTNPADF_MASK)

#define PMC_FLAGS_RESETNPADF_MASK                (0x40000000U)
#define PMC_FLAGS_RESETNPADF_SHIFT               (30U)
/*! RESETNPADF
 *  0b0..No reset detected since last time this flag was cleared.
 *  0b1..Reset pad wakeup caused a wakeup or reset event since the last time this bit was cleared. Write 1 to clear.
 */
#define PMC_FLAGS_RESETNPADF(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_FLAGS_RESETNPADF_SHIFT)) & PMC_FLAGS_RESETNPADF_MASK)

#define PMC_FLAGS_DEEPPDF_MASK                   (0x80000000U)
#define PMC_FLAGS_DEEPPDF_SHIFT                  (31U)
/*! DEEPPDF
 *  0b0..No deep powerdown wakeup since last time flag was cleared.
 *  0b1..Deep powerdown was entered since the last time this flag was cleared. Write 1 to clear
 */
#define PMC_FLAGS_DEEPPDF(x)                     (((uint32_t)(((uint32_t)(x)) << PMC_FLAGS_DEEPPDF_SHIFT)) & PMC_FLAGS_DEEPPDF_MASK)
/*! @} */

/*! @name CTRL - PMC control register */
/*! @{ */

#define PMC_CTRL_APPLYCFG_MASK                   (0x1U)
#define PMC_CTRL_APPLYCFG_SHIFT                  (0U)
/*! APPLYCFG
 *  0b0..Always reads 0. Write 0 has no effect
 *  0b1..Write 1 = initiate update sequencing of PMC state machines
 */
#define PMC_CTRL_APPLYCFG(x)                     (((uint32_t)(((uint32_t)(x)) << PMC_CTRL_APPLYCFG_SHIFT)) & PMC_CTRL_APPLYCFG_MASK)

#define PMC_CTRL_BUFEN_MASK                      (0x10U)
#define PMC_CTRL_BUFEN_SHIFT                     (4U)
/*! BUFEN
 *  0b0..disabled
 *  0b1..enabled
 */
#define PMC_CTRL_BUFEN(x)                        (((uint32_t)(((uint32_t)(x)) << PMC_CTRL_BUFEN_SHIFT)) & PMC_CTRL_BUFEN_MASK)

#define PMC_CTRL_LVDCOREIE_MASK                  (0x100000U)
#define PMC_CTRL_LVDCOREIE_SHIFT                 (20U)
/*! LVDCOREIE
 *  0b0..vddcore LVD interrupt disabled
 *  0b1..vddcore LVD causes interrupt and wakeup from deep sleep.
 */
#define PMC_CTRL_LVDCOREIE(x)                    (((uint32_t)(((uint32_t)(x)) << PMC_CTRL_LVDCOREIE_SHIFT)) & PMC_CTRL_LVDCOREIE_MASK)

#define PMC_CTRL_LVDCORERE_MASK                  (0x200000U)
#define PMC_CTRL_LVDCORERE_SHIFT                 (21U)
/*! LVDCORERE
 *  0b0..vddcore LVD reset disabled
 *  0b1..vddcore LVD causes reset
 */
#define PMC_CTRL_LVDCORERE(x)                    (((uint32_t)(((uint32_t)(x)) << PMC_CTRL_LVDCORERE_SHIFT)) & PMC_CTRL_LVDCORERE_MASK)

#define PMC_CTRL_HVDCOREIE_MASK                  (0x400000U)
#define PMC_CTRL_HVDCOREIE_SHIFT                 (22U)
/*! HVDCOREIE
 *  0b0..vddcore HVD interrupt disabled
 *  0b1..vddcore HVD causes interrupt and wakeup from deep sleep.
 */
#define PMC_CTRL_HVDCOREIE(x)                    (((uint32_t)(((uint32_t)(x)) << PMC_CTRL_HVDCOREIE_SHIFT)) & PMC_CTRL_HVDCOREIE_MASK)

#define PMC_CTRL_HVDCORERE_MASK                  (0x800000U)
#define PMC_CTRL_HVDCORERE_SHIFT                 (23U)
/*! HVDCORERE
 *  0b0..vddcore HVD reset disabled
 *  0b1..vddcore HVD causes reset
 */
#define PMC_CTRL_HVDCORERE(x)                    (((uint32_t)(((uint32_t)(x)) << PMC_CTRL_HVDCORERE_SHIFT)) & PMC_CTRL_HVDCORERE_MASK)

#define PMC_CTRL_HVD1V8IE_MASK                   (0x1000000U)
#define PMC_CTRL_HVD1V8IE_SHIFT                  (24U)
/*! HVD1V8IE
 *  0b0..vdd1v8 HVD interrupt disabled
 *  0b1..vdd1v8 HVD causes interrupt and wakeup from deep sleep or deep power down mode
 */
#define PMC_CTRL_HVD1V8IE(x)                     (((uint32_t)(((uint32_t)(x)) << PMC_CTRL_HVD1V8IE_SHIFT)) & PMC_CTRL_HVD1V8IE_MASK)

#define PMC_CTRL_HVD1V8RE_MASK                   (0x2000000U)
#define PMC_CTRL_HVD1V8RE_SHIFT                  (25U)
/*! HVD1V8RE
 *  0b0..vdd1v8 HVD reset disabled
 *  0b1..vdd1v8 HVD causes reset
 */
#define PMC_CTRL_HVD1V8RE(x)                     (((uint32_t)(((uint32_t)(x)) << PMC_CTRL_HVD1V8RE_SHIFT)) & PMC_CTRL_HVD1V8RE_MASK)

#define PMC_CTRL_AUTOWKEN_MASK                   (0x10000000U)
#define PMC_CTRL_AUTOWKEN_SHIFT                  (28U)
/*! AUTOWKEN
 *  0b0..Auto wakeup interrupt and counter disabled
 *  0b1..Auto wakeup interrupt generated when PMC sequencer finishes and AUTOWAKE counter = 0 after entering deep
 *       sleep mode (but not deep powerdown mode). Interrupt will wake up the M33.
 */
#define PMC_CTRL_AUTOWKEN(x)                     (((uint32_t)(((uint32_t)(x)) << PMC_CTRL_AUTOWKEN_SHIFT)) & PMC_CTRL_AUTOWKEN_MASK)

#define PMC_CTRL_INTRPADEN_MASK                  (0x20000000U)
#define PMC_CTRL_INTRPADEN_SHIFT                 (29U)
/*! INTRPADEN
 *  0b0..Interrupt pad low has no effect
 *  0b1..Interrupt pad low triggers an interrupt and deep sleep wakeup or deep powerdown wakeup event.
 */
#define PMC_CTRL_INTRPADEN(x)                    (((uint32_t)(((uint32_t)(x)) << PMC_CTRL_INTRPADEN_SHIFT)) & PMC_CTRL_INTRPADEN_MASK)
/*! @} */

/*! @name RUNCTRL - PMC controls used during run mode */
/*! @{ */

#define PMC_RUNCTRL_CORELVL_MASK                 (0x3FU)
#define PMC_RUNCTRL_CORELVL_SHIFT                (0U)
#define PMC_RUNCTRL_CORELVL(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_RUNCTRL_CORELVL_SHIFT)) & PMC_RUNCTRL_CORELVL_MASK)
/*! @} */

/*! @name SLEEPCTRL - PMC controls used during deep sleep mode */
/*! @{ */

#define PMC_SLEEPCTRL_CORELVL_MASK               (0x3FU)
#define PMC_SLEEPCTRL_CORELVL_SHIFT              (0U)
#define PMC_SLEEPCTRL_CORELVL(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_SLEEPCTRL_CORELVL_SHIFT)) & PMC_SLEEPCTRL_CORELVL_MASK)
/*! @} */

/*! @name LVDCORECTRL - Active vddcore LVD monitor trip adjust */
/*! @{ */

#define PMC_LVDCORECTRL_LVDCORELVL_MASK          (0xFU)
#define PMC_LVDCORECTRL_LVDCORELVL_SHIFT         (0U)
/*! LVDCORELVL - Vddcore LVD falling trip voltage */
#define PMC_LVDCORECTRL_LVDCORELVL(x)            (((uint32_t)(((uint32_t)(x)) << PMC_LVDCORECTRL_LVDCORELVL_SHIFT)) & PMC_LVDCORECTRL_LVDCORELVL_MASK)
/*! @} */

/*! @name AUTOWKUP - Automatic wakeup from deepsleep / deep powerdown modes */
/*! @{ */

#define PMC_AUTOWKUP_AUTOWKTIME_MASK             (0xFFFFU)
#define PMC_AUTOWKUP_AUTOWKTIME_SHIFT            (0U)
#define PMC_AUTOWKUP_AUTOWKTIME(x)               (((uint32_t)(((uint32_t)(x)) << PMC_AUTOWKUP_AUTOWKTIME_SHIFT)) & PMC_AUTOWKUP_AUTOWKTIME_MASK)
/*! @} */

/*! @name PMICCFG - PMIC power mode select control configuration to let PMC know when vddcore or vdd1v8 will power off/on */
/*! @{ */

#define PMC_PMICCFG_VDDCOREM0_MASK               (0x1U)
#define PMC_PMICCFG_VDDCOREM0_SHIFT              (0U)
/*! VDDCOREM0 - vddcore state in PMIC mode 0
 *  0b0..off
 *  0b1..powered
 */
#define PMC_PMICCFG_VDDCOREM0(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_PMICCFG_VDDCOREM0_SHIFT)) & PMC_PMICCFG_VDDCOREM0_MASK)

#define PMC_PMICCFG_VDDCOREM1_MASK               (0x2U)
#define PMC_PMICCFG_VDDCOREM1_SHIFT              (1U)
/*! VDDCOREM1 - vddcore state in PMIC mode 1
 *  0b0..off
 *  0b1..powered
 */
#define PMC_PMICCFG_VDDCOREM1(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_PMICCFG_VDDCOREM1_SHIFT)) & PMC_PMICCFG_VDDCOREM1_MASK)

#define PMC_PMICCFG_VDDCOREM2_MASK               (0x4U)
#define PMC_PMICCFG_VDDCOREM2_SHIFT              (2U)
/*! VDDCOREM2 - vddcore state in PMIC mode 2
 *  0b0..off
 *  0b1..powered
 */
#define PMC_PMICCFG_VDDCOREM2(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_PMICCFG_VDDCOREM2_SHIFT)) & PMC_PMICCFG_VDDCOREM2_MASK)

#define PMC_PMICCFG_VDDCOREM3_MASK               (0x8U)
#define PMC_PMICCFG_VDDCOREM3_SHIFT              (3U)
/*! VDDCOREM3 - vddcore state in PMIC mode 3
 *  0b0..off
 *  0b1..powered
 */
#define PMC_PMICCFG_VDDCOREM3(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_PMICCFG_VDDCOREM3_SHIFT)) & PMC_PMICCFG_VDDCOREM3_MASK)

#define PMC_PMICCFG_VDD1V8M0_MASK                (0x10U)
#define PMC_PMICCFG_VDD1V8M0_SHIFT               (4U)
/*! VDD1V8M0 - vdd1v8 state in PMIC mode 0
 *  0b0..off
 *  0b1..powered
 */
#define PMC_PMICCFG_VDD1V8M0(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_PMICCFG_VDD1V8M0_SHIFT)) & PMC_PMICCFG_VDD1V8M0_MASK)

#define PMC_PMICCFG_VDD1V8M1_MASK                (0x20U)
#define PMC_PMICCFG_VDD1V8M1_SHIFT               (5U)
/*! VDD1V8M1 - vdd1v8 state in PMIC mode 1
 *  0b0..off
 *  0b1..powered
 */
#define PMC_PMICCFG_VDD1V8M1(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_PMICCFG_VDD1V8M1_SHIFT)) & PMC_PMICCFG_VDD1V8M1_MASK)

#define PMC_PMICCFG_VDD1V8M2_MASK                (0x40U)
#define PMC_PMICCFG_VDD1V8M2_SHIFT               (6U)
/*! VDD1V8M2 - vdd1v8 state in PMIC mode 2
 *  0b0..off
 *  0b1..powered
 */
#define PMC_PMICCFG_VDD1V8M2(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_PMICCFG_VDD1V8M2_SHIFT)) & PMC_PMICCFG_VDD1V8M2_MASK)

#define PMC_PMICCFG_VDD1V8M3_MASK                (0x80U)
#define PMC_PMICCFG_VDD1V8M3_SHIFT               (7U)
/*! VDD1V8M3 - vdd1v8 state in PMIC mode 3
 *  0b0..off
 *  0b1..powered
 */
#define PMC_PMICCFG_VDD1V8M3(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_PMICCFG_VDD1V8M3_SHIFT)) & PMC_PMICCFG_VDD1V8M3_MASK)
/*! @} */

/*! @name PADVRANGE - GPIO vdde range selection control */
/*! @{ */

#define PMC_PADVRANGE_VDDIO_0RANGE_MASK          (0x3U)
#define PMC_PADVRANGE_VDDIO_0RANGE_SHIFT         (0U)
/*! VDDIO_0RANGE
 *  0b00..1.71 - 3.6V. Consumes static current to detect VDDE0 level
 *  0b01..1.71 - 1.98V, vdde detector off
 *  0b10..3.00 - 3.6V, vdde detector off
 *  0b11..Not allowed (hardware should translate to 10)
 */
#define PMC_PADVRANGE_VDDIO_0RANGE(x)            (((uint32_t)(((uint32_t)(x)) << PMC_PADVRANGE_VDDIO_0RANGE_SHIFT)) & PMC_PADVRANGE_VDDIO_0RANGE_MASK)

#define PMC_PADVRANGE_VDDIO_1RANGE_MASK          (0xCU)
#define PMC_PADVRANGE_VDDIO_1RANGE_SHIFT         (2U)
/*! VDDIO_1RANGE
 *  0b00..1.71-3.6V. Consumes static current to detect VDDE1 level
 *  0b01..1.71 - 1.98V, vdde detector off
 *  0b10..3.00 - 3.6V, vdde detector off
 *  0b11..Not allowed (hardware should translate to 10)
 */
#define PMC_PADVRANGE_VDDIO_1RANGE(x)            (((uint32_t)(((uint32_t)(x)) << PMC_PADVRANGE_VDDIO_1RANGE_SHIFT)) & PMC_PADVRANGE_VDDIO_1RANGE_MASK)

#define PMC_PADVRANGE_VDDIO_2RANGE_MASK          (0x30U)
#define PMC_PADVRANGE_VDDIO_2RANGE_SHIFT         (4U)
/*! VDDIO_2RANGE
 *  0b00..1.71 - 3.6V. Consumes static current to detect VDDE2 level
 *  0b01..1.71 - 1.98V, vdde detector off
 *  0b10..3.00 - 3.6V, vdde detector off
 *  0b11..Not allowed (hardware should translate to 10)
 */
#define PMC_PADVRANGE_VDDIO_2RANGE(x)            (((uint32_t)(((uint32_t)(x)) << PMC_PADVRANGE_VDDIO_2RANGE_SHIFT)) & PMC_PADVRANGE_VDDIO_2RANGE_MASK)
/*! @} */

/*! @name MEMSEQCTRL - Memory Sequencer Control Register */
/*! @{ */

#define PMC_MEMSEQCTRL_MEMSEQNUM_MASK            (0x3FU)
#define PMC_MEMSEQCTRL_MEMSEQNUM_SHIFT           (0U)
/*! MEMSEQNUM - Number of memories to turn on/off at a time. */
#define PMC_MEMSEQCTRL_MEMSEQNUM(x)              (((uint32_t)(((uint32_t)(x)) << PMC_MEMSEQCTRL_MEMSEQNUM_SHIFT)) & PMC_MEMSEQCTRL_MEMSEQNUM_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group PMC_Register_Masks */


/*!
 * @}
 */ /* end of group PMC_Peripheral_Access_Layer */


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
#elif defined(__XTENSA__)
  /* leave anonymous unions enabled */
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_PMC_H_ */

