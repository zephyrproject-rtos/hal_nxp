/*
** ###################################################################
**     Processors:          MC56F84441VLF
**                          MC56F84442VLH
**                          MC56F84451VLF
**                          MC56F84452VLH
**                          MC56F84462VLH
**                          MC56F84540VLF
**                          MC56F84543VLH
**                          MC56F84550VLF
**                          MC56F84553VLH
**                          MC56F84565VLK
**                          MC56F84567VLL
**                          MC56F84587VLL
**                          MC56F84763VLH
**                          MC56F84766VLK
**                          MC56F84769VLL
**                          MC56F84786VLK
**                          MC56F84789VLL
**
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for PDB
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 2.0 (2021-02-06)
**         Initial version.
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_PDB.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for PDB
 *
 * CMSIS Peripheral Access Layer for PDB
 */

#if !defined(PERI_PDB_H_)
#define PERI_PDB_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MC56F84441VLF))
#include "MC56F84441_COMMON.h"
#elif (defined(CPU_MC56F84442VLH))
#include "MC56F84442_COMMON.h"
#elif (defined(CPU_MC56F84451VLF))
#include "MC56F84451_COMMON.h"
#elif (defined(CPU_MC56F84452VLH))
#include "MC56F84452_COMMON.h"
#elif (defined(CPU_MC56F84462VLH))
#include "MC56F84462_COMMON.h"
#elif (defined(CPU_MC56F84540VLF))
#include "MC56F84540_COMMON.h"
#elif (defined(CPU_MC56F84543VLH))
#include "MC56F84543_COMMON.h"
#elif (defined(CPU_MC56F84550VLF))
#include "MC56F84550_COMMON.h"
#elif (defined(CPU_MC56F84553VLH))
#include "MC56F84553_COMMON.h"
#elif (defined(CPU_MC56F84565VLK))
#include "MC56F84565_COMMON.h"
#elif (defined(CPU_MC56F84567VLL))
#include "MC56F84567_COMMON.h"
#elif (defined(CPU_MC56F84587VLL))
#include "MC56F84587_COMMON.h"
#elif (defined(CPU_MC56F84763VLH))
#include "MC56F84763_COMMON.h"
#elif (defined(CPU_MC56F84766VLK))
#include "MC56F84766_COMMON.h"
#elif (defined(CPU_MC56F84769VLL))
#include "MC56F84769_COMMON.h"
#elif (defined(CPU_MC56F84786VLK))
#include "MC56F84786_COMMON.h"
#elif (defined(CPU_MC56F84789VLL))
#include "MC56F84789_COMMON.h"
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

#if defined(__CWCC__)
  #pragma push
  #pragma cpp_extensions on
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- PDB Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PDB_Peripheral_Access_Layer PDB Peripheral Access Layer
 * @{
 */

/** PDB - Register Layout Typedef */
typedef struct {
  __IO uint16_t MCTRL;                             /**< Master Control Register, offset: 0x0 */
  __IO uint16_t CTRLA;                             /**< Control A Register, offset: 0x1 */
  __IO uint16_t CTRLC;                             /**< Control C Register, offset: 0x2 */
  __IO uint16_t DELAYA;                            /**< DelayA Register, offset: 0x3 */
  __IO uint16_t DELAYB;                            /**< DelayB Register, offset: 0x4 */
  __IO uint16_t DELAYC;                            /**< DelayC Register, offset: 0x5 */
  __IO uint16_t DELAYD;                            /**< DelayD Register, offset: 0x6 */
  __IO uint16_t MOD;                               /**< Modulus Register, offset: 0x7 */
  __I  uint16_t CNTR;                              /**< Counter Register, offset: 0x8 */
} PDB_Type;

/* ----------------------------------------------------------------------------
   -- PDB Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PDB_Register_Masks PDB Register Masks
 * @{
 */

/*! @name MCTRL - Master Control Register */
/*! @{ */

#define PDB_MCTRL_PDBEN_MASK                     (0x1U)
#define PDB_MCTRL_PDBEN_SHIFT                    (0U)
/*! PDBEN - PDB Module Enable
 *  0b0..Counter is off and all Trigger and PreTrigger outputs are low.
 *  0b1..Counter is enabled.
 */
#define PDB_MCTRL_PDBEN(x)                       (((uint16_t)(((uint16_t)(x)) << PDB_MCTRL_PDBEN_SHIFT)) & PDB_MCTRL_PDBEN_MASK)

#define PDB_MCTRL_TRIGSEL_MASK                   (0x70U)
#define PDB_MCTRL_TRIGSEL_SHIFT                  (4U)
/*! TRIGSEL - Input Trigger Select
 *  0b000..TriggerIn0 is selected.
 *  0b001..TriggerIn1 is selected.
 *  0b010..TriggerIn2 is selected.
 *  0b011..TriggerIn3 is selected.
 *  0b100..TriggerIn4 is selected.
 *  0b101..TriggerIn5 is selected.
 *  0b110..TriggerIn6 is selected.
 *  0b111..SWTRIG is selected.
 */
#define PDB_MCTRL_TRIGSEL(x)                     (((uint16_t)(((uint16_t)(x)) << PDB_MCTRL_TRIGSEL_SHIFT)) & PDB_MCTRL_TRIGSEL_MASK)

#define PDB_MCTRL_SWTRIG_MASK                    (0x80U)
#define PDB_MCTRL_SWTRIG_SHIFT                   (7U)
/*! SWTRIG - Software Trigger */
#define PDB_MCTRL_SWTRIG(x)                      (((uint16_t)(((uint16_t)(x)) << PDB_MCTRL_SWTRIG_SHIFT)) & PDB_MCTRL_SWTRIG_MASK)

#define PDB_MCTRL_COIE_MASK                      (0x100U)
#define PDB_MCTRL_COIE_SHIFT                     (8U)
/*! COIE - Counter Overflow Interrupt Enable
 *  0b0..Counter roll over interrupt requests disabled.
 *  0b1..Counter roll over interrupt requests enabled.
 */
#define PDB_MCTRL_COIE(x)                        (((uint16_t)(((uint16_t)(x)) << PDB_MCTRL_COIE_SHIFT)) & PDB_MCTRL_COIE_MASK)

#define PDB_MCTRL_COF_MASK                       (0x200U)
#define PDB_MCTRL_COF_SHIFT                      (9U)
/*! COF - Counter Overflow Flag */
#define PDB_MCTRL_COF(x)                         (((uint16_t)(((uint16_t)(x)) << PDB_MCTRL_COF_SHIFT)) & PDB_MCTRL_COF_MASK)

#define PDB_MCTRL_CONT_MASK                      (0x400U)
#define PDB_MCTRL_CONT_SHIFT                     (10U)
/*! CONT - Continuous Mode Enable
 *  0b0..Module is in one-shot mode.
 *  0b1..Module is in continuous mode.
 */
#define PDB_MCTRL_CONT(x)                        (((uint16_t)(((uint16_t)(x)) << PDB_MCTRL_CONT_SHIFT)) & PDB_MCTRL_CONT_MASK)

#define PDB_MCTRL_LDOK_MASK                      (0x800U)
#define PDB_MCTRL_LDOK_SHIFT                     (11U)
/*! LDOK - Load OK */
#define PDB_MCTRL_LDOK(x)                        (((uint16_t)(((uint16_t)(x)) << PDB_MCTRL_LDOK_SHIFT)) & PDB_MCTRL_LDOK_MASK)

#define PDB_MCTRL_LDMOD_MASK                     (0x1000U)
#define PDB_MCTRL_LDMOD_SHIFT                    (12U)
/*! LDMOD - Load Mode Select
 *  0b0..DELAY* and MOD registers are loaded into a set of buffers and take effect immediately after logic 1 is written to the MCTRL[LDOK] bit.
 *  0b1..DELAY* and MOD registers are loaded into a set of buffers and take effect when the counter rolls over or
 *       a trigger signal is received after logic 1 is written to the MCTRL[LDOK] bit.
 */
#define PDB_MCTRL_LDMOD(x)                       (((uint16_t)(((uint16_t)(x)) << PDB_MCTRL_LDMOD_SHIFT)) & PDB_MCTRL_LDMOD_MASK)

#define PDB_MCTRL_PRESCALER_MASK                 (0xE000U)
#define PDB_MCTRL_PRESCALER_SHIFT                (13U)
/*! PRESCALER - Clock Prescaler Select
 *  0b000..Timer uses peripheral clock.
 *  0b001..Timer uses peripheral clock / 2.
 *  0b010..Timer uses peripheral clock / 4.
 *  0b011..Timer uses peripheral clock / 8.
 *  0b100..Timer uses peripheral clock / 16.
 *  0b101..Timer uses peripheral clock / 32.
 *  0b110..Timer uses peripheral clock / 64.
 *  0b111..Timer uses peripheral clock / 128.
 */
#define PDB_MCTRL_PRESCALER(x)                   (((uint16_t)(((uint16_t)(x)) << PDB_MCTRL_PRESCALER_SHIFT)) & PDB_MCTRL_PRESCALER_MASK)
/*! @} */

/*! @name CTRLA - Control A Register */
/*! @{ */

#define PDB_CTRLA_ENB_MASK                       (0x1U)
#define PDB_CTRLA_ENB_SHIFT                      (0U)
/*! ENB - Trigger B Enable
 *  0b0..Trigger B is disabled and forced to 0.
 *  0b1..Trigger B is enabled.
 */
#define PDB_CTRLA_ENB(x)                         (((uint16_t)(((uint16_t)(x)) << PDB_CTRLA_ENB_SHIFT)) & PDB_CTRLA_ENB_MASK)

#define PDB_CTRLA_ENA_MASK                       (0x2U)
#define PDB_CTRLA_ENA_SHIFT                      (1U)
/*! ENA - Trigger A Enable
 *  0b0..Trigger A is disabled and forced to 0.
 *  0b1..Trigger A is enabled.
 */
#define PDB_CTRLA_ENA(x)                         (((uint16_t)(((uint16_t)(x)) << PDB_CTRLA_ENA_SHIFT)) & PDB_CTRLA_ENA_MASK)

#define PDB_CTRLA_BYPB_MASK                      (0x4U)
#define PDB_CTRLA_BYPB_SHIFT                     (2U)
/*! BYPB - Bypass B
 *  0b0..Trigger B is generated normally.
 *  0b1..Trigger B generation is bypassed and Trigger B is a single pulse created by the selected trigger source.
 */
#define PDB_CTRLA_BYPB(x)                        (((uint16_t)(((uint16_t)(x)) << PDB_CTRLA_BYPB_SHIFT)) & PDB_CTRLA_BYPB_MASK)

#define PDB_CTRLA_BYPA_MASK                      (0x8U)
#define PDB_CTRLA_BYPA_SHIFT                     (3U)
/*! BYPA - Bypass A
 *  0b0..Trigger A is generated normally.
 *  0b1..Trigger A generation is bypassed and Trigger A is a single pulse created by the selected trigger source.
 */
#define PDB_CTRLA_BYPA(x)                        (((uint16_t)(((uint16_t)(x)) << PDB_CTRLA_BYPA_SHIFT)) & PDB_CTRLA_BYPA_MASK)

#define PDB_CTRLA_ABSEL_MASK                     (0x10U)
#define PDB_CTRLA_ABSEL_SHIFT                    (4U)
/*! ABSEL - Trigger A Output Select
 *  0b0..Trigger A is a function of DELAYA only. Trigger B is a function of DELAYB only.
 *  0b1..Trigger A and Trigger B outputs are a function of combined DELAYA and DELAYB. Trigger A is an extended
 *       pulse (as in trigger pulsed output operation) and Trigger B is a dual pulse (as in two-shot mode with
 *       trigger configured for simultaneous sampling).
 */
#define PDB_CTRLA_ABSEL(x)                       (((uint16_t)(((uint16_t)(x)) << PDB_CTRLA_ABSEL_SHIFT)) & PDB_CTRLA_ABSEL_MASK)

#define PDB_CTRLA_AINIT_MASK                     (0x20U)
#define PDB_CTRLA_AINIT_SHIFT                    (5U)
/*! AINIT - Initial Value A */
#define PDB_CTRLA_AINIT(x)                       (((uint16_t)(((uint16_t)(x)) << PDB_CTRLA_AINIT_SHIFT)) & PDB_CTRLA_AINIT_MASK)

#define PDB_CTRLA_DBIE_MASK                      (0x100U)
#define PDB_CTRLA_DBIE_SHIFT                     (8U)
/*! DBIE - Delay B Interrupt Enable
 *  0b0..DELAYB successful compare interrupt requests disabled.
 *  0b1..DELAYB successful compare interrupt requests enabled.
 */
#define PDB_CTRLA_DBIE(x)                        (((uint16_t)(((uint16_t)(x)) << PDB_CTRLA_DBIE_SHIFT)) & PDB_CTRLA_DBIE_MASK)

#define PDB_CTRLA_DBF_MASK                       (0x200U)
#define PDB_CTRLA_DBF_SHIFT                      (9U)
/*! DBF - Delay B Flag */
#define PDB_CTRLA_DBF(x)                         (((uint16_t)(((uint16_t)(x)) << PDB_CTRLA_DBF_SHIFT)) & PDB_CTRLA_DBF_MASK)

#define PDB_CTRLA_DAIE_MASK                      (0x400U)
#define PDB_CTRLA_DAIE_SHIFT                     (10U)
/*! DAIE - Delay A Interrupt Enable
 *  0b0..DELAYA successful compare interrupt requests disabled.
 *  0b1..DELAYA successful compare interrupt requests enabled.
 */
#define PDB_CTRLA_DAIE(x)                        (((uint16_t)(((uint16_t)(x)) << PDB_CTRLA_DAIE_SHIFT)) & PDB_CTRLA_DAIE_MASK)

#define PDB_CTRLA_DAF_MASK                       (0x800U)
#define PDB_CTRLA_DAF_SHIFT                      (11U)
/*! DAF - Delay A Flag */
#define PDB_CTRLA_DAF(x)                         (((uint16_t)(((uint16_t)(x)) << PDB_CTRLA_DAF_SHIFT)) & PDB_CTRLA_DAF_MASK)

#define PDB_CTRLA_FLENA_MASK                     (0x1000U)
#define PDB_CTRLA_FLENA_SHIFT                    (12U)
/*! FLENA - Fault A Length
 *  0b0..Fault input must be active at least 2 IPBus clock cycles.
 *  0b1..Fault input must be active at least 4 IPBus clock cycles.
 */
#define PDB_CTRLA_FLENA(x)                       (((uint16_t)(((uint16_t)(x)) << PDB_CTRLA_FLENA_SHIFT)) & PDB_CTRLA_FLENA_MASK)

#define PDB_CTRLA_FPOLA_MASK                     (0x2000U)
#define PDB_CTRLA_FPOLA_SHIFT                    (13U)
/*! FPOLA - Fault A Polarity
 *  0b0..A logic 0 on Fault A indicates a fault condition
 *  0b1..A logic 1 on Fault A indicates a fault condition.
 */
#define PDB_CTRLA_FPOLA(x)                       (((uint16_t)(((uint16_t)(x)) << PDB_CTRLA_FPOLA_SHIFT)) & PDB_CTRLA_FPOLA_MASK)

#define PDB_CTRLA_FLTAEN_MASK                    (0x4000U)
#define PDB_CTRLA_FLTAEN_SHIFT                   (14U)
/*! FLTAEN - Fault A Enable
 *  0b0..Fault A input is ignored.
 *  0b1..A logic 1 on the Fault A input forces TriggerA output to CTRLA[AINIT] until a counter reload occurs.
 */
#define PDB_CTRLA_FLTAEN(x)                      (((uint16_t)(((uint16_t)(x)) << PDB_CTRLA_FLTAEN_SHIFT)) & PDB_CTRLA_FLTAEN_MASK)

#define PDB_CTRLA_FLTA_MASK                      (0x8000U)
#define PDB_CTRLA_FLTA_SHIFT                     (15U)
/*! FLTA - Fault A Input Status */
#define PDB_CTRLA_FLTA(x)                        (((uint16_t)(((uint16_t)(x)) << PDB_CTRLA_FLTA_SHIFT)) & PDB_CTRLA_FLTA_MASK)
/*! @} */

/*! @name CTRLC - Control C Register */
/*! @{ */

#define PDB_CTRLC_END_MASK                       (0x1U)
#define PDB_CTRLC_END_SHIFT                      (0U)
/*! END - Trigger D Enable
 *  0b0..Trigger D is disabled and forced to 0.
 *  0b1..Trigger D is enabled.
 */
#define PDB_CTRLC_END(x)                         (((uint16_t)(((uint16_t)(x)) << PDB_CTRLC_END_SHIFT)) & PDB_CTRLC_END_MASK)

#define PDB_CTRLC_ENC_MASK                       (0x2U)
#define PDB_CTRLC_ENC_SHIFT                      (1U)
/*! ENC - Trigger C Enable
 *  0b0..Trigger C is disabled and forced to 0.
 *  0b1..Trigger C is enabled.
 */
#define PDB_CTRLC_ENC(x)                         (((uint16_t)(((uint16_t)(x)) << PDB_CTRLC_ENC_SHIFT)) & PDB_CTRLC_ENC_MASK)

#define PDB_CTRLC_BYPD_MASK                      (0x4U)
#define PDB_CTRLC_BYPD_SHIFT                     (2U)
/*! BYPD - Bypass D
 *  0b0..Trigger D is generated normally.
 *  0b1..Trigger D generation is bypassed and Trigger D is a single pulse created by the selected trigger source.
 */
#define PDB_CTRLC_BYPD(x)                        (((uint16_t)(((uint16_t)(x)) << PDB_CTRLC_BYPD_SHIFT)) & PDB_CTRLC_BYPD_MASK)

#define PDB_CTRLC_BYPC_MASK                      (0x8U)
#define PDB_CTRLC_BYPC_SHIFT                     (3U)
/*! BYPC - Bypass C
 *  0b0..Trigger C is generated normally.
 *  0b1..Trigger C generation is bypassed and Trigger C is a single pulse created by the selected trigger source.
 */
#define PDB_CTRLC_BYPC(x)                        (((uint16_t)(((uint16_t)(x)) << PDB_CTRLC_BYPC_SHIFT)) & PDB_CTRLC_BYPC_MASK)

#define PDB_CTRLC_CDSEL_MASK                     (0x10U)
#define PDB_CTRLC_CDSEL_SHIFT                    (4U)
/*! CDSEL - Trigger C Output Select
 *  0b0..Trigger C is a function of DELAYC only. Trigger D is a function of DELAYD only.
 *  0b1..Trigger C and Trigger D outputs are a function of combined DELAYC and DELAYD. Trigger C is an extended
 *       pulse (as in trigger pulsed output operation) and Trigger D is a dual pulse (as in two-shot mode with
 *       trigger configured for simultaneous sampling).
 */
#define PDB_CTRLC_CDSEL(x)                       (((uint16_t)(((uint16_t)(x)) << PDB_CTRLC_CDSEL_SHIFT)) & PDB_CTRLC_CDSEL_MASK)

#define PDB_CTRLC_CINIT_MASK                     (0x20U)
#define PDB_CTRLC_CINIT_SHIFT                    (5U)
/*! CINIT - Initial Value C */
#define PDB_CTRLC_CINIT(x)                       (((uint16_t)(((uint16_t)(x)) << PDB_CTRLC_CINIT_SHIFT)) & PDB_CTRLC_CINIT_MASK)

#define PDB_CTRLC_DDIE_MASK                      (0x100U)
#define PDB_CTRLC_DDIE_SHIFT                     (8U)
/*! DDIE - Delay D Interrupt Enable
 *  0b0..DELAYD successful compare interrupt requests disabled.
 *  0b1..DELAYD successful compare interrupt requests enabled.
 */
#define PDB_CTRLC_DDIE(x)                        (((uint16_t)(((uint16_t)(x)) << PDB_CTRLC_DDIE_SHIFT)) & PDB_CTRLC_DDIE_MASK)

#define PDB_CTRLC_DDF_MASK                       (0x200U)
#define PDB_CTRLC_DDF_SHIFT                      (9U)
/*! DDF - Delay D Flag */
#define PDB_CTRLC_DDF(x)                         (((uint16_t)(((uint16_t)(x)) << PDB_CTRLC_DDF_SHIFT)) & PDB_CTRLC_DDF_MASK)

#define PDB_CTRLC_DCIE_MASK                      (0x400U)
#define PDB_CTRLC_DCIE_SHIFT                     (10U)
/*! DCIE - Delay C Interrupt Enable
 *  0b0..DELAYC successful compare interrupt requests disabled.
 *  0b1..DELAYC successful compare interrupt requests enabled.
 */
#define PDB_CTRLC_DCIE(x)                        (((uint16_t)(((uint16_t)(x)) << PDB_CTRLC_DCIE_SHIFT)) & PDB_CTRLC_DCIE_MASK)

#define PDB_CTRLC_DCF_MASK                       (0x800U)
#define PDB_CTRLC_DCF_SHIFT                      (11U)
/*! DCF - Delay C Flag */
#define PDB_CTRLC_DCF(x)                         (((uint16_t)(((uint16_t)(x)) << PDB_CTRLC_DCF_SHIFT)) & PDB_CTRLC_DCF_MASK)

#define PDB_CTRLC_FLENC_MASK                     (0x1000U)
#define PDB_CTRLC_FLENC_SHIFT                    (12U)
/*! FLENC - Fault C Length
 *  0b0..Fault input must be active at least 2 IPBus clock cycles.
 *  0b1..Fault input must be active at least 4 IPBus clock cycles.
 */
#define PDB_CTRLC_FLENC(x)                       (((uint16_t)(((uint16_t)(x)) << PDB_CTRLC_FLENC_SHIFT)) & PDB_CTRLC_FLENC_MASK)

#define PDB_CTRLC_FPOLC_MASK                     (0x2000U)
#define PDB_CTRLC_FPOLC_SHIFT                    (13U)
/*! FPOLC - Fault C Polarity
 *  0b0..A logic 0 on Fault C indicates a fault condition.
 *  0b1..A logic 1 on Fault C indicates a fault condition.
 */
#define PDB_CTRLC_FPOLC(x)                       (((uint16_t)(((uint16_t)(x)) << PDB_CTRLC_FPOLC_SHIFT)) & PDB_CTRLC_FPOLC_MASK)

#define PDB_CTRLC_FLTCEN_MASK                    (0x4000U)
#define PDB_CTRLC_FLTCEN_SHIFT                   (14U)
/*! FLTCEN - Fault C Enable.
 *  0b0..Fault C input is ignored.
 *  0b1..A logic 1 on the Fault C input forces Trigger C output to CTRLC[CINIT] until a counter reload occurs.
 */
#define PDB_CTRLC_FLTCEN(x)                      (((uint16_t)(((uint16_t)(x)) << PDB_CTRLC_FLTCEN_SHIFT)) & PDB_CTRLC_FLTCEN_MASK)

#define PDB_CTRLC_FLTC_MASK                      (0x8000U)
#define PDB_CTRLC_FLTC_SHIFT                     (15U)
/*! FLTC - Fault C Input Status */
#define PDB_CTRLC_FLTC(x)                        (((uint16_t)(((uint16_t)(x)) << PDB_CTRLC_FLTC_SHIFT)) & PDB_CTRLC_FLTC_MASK)
/*! @} */

/*! @name DELAYA - DelayA Register */
/*! @{ */

#define PDB_DELAYA_DELAYA_MASK                   (0xFFFFU)
#define PDB_DELAYA_DELAYA_SHIFT                  (0U)
/*! DELAYA - Delay A */
#define PDB_DELAYA_DELAYA(x)                     (((uint16_t)(((uint16_t)(x)) << PDB_DELAYA_DELAYA_SHIFT)) & PDB_DELAYA_DELAYA_MASK)
/*! @} */

/*! @name DELAYB - DelayB Register */
/*! @{ */

#define PDB_DELAYB_DELAYB_MASK                   (0xFFFFU)
#define PDB_DELAYB_DELAYB_SHIFT                  (0U)
/*! DELAYB - Delay B */
#define PDB_DELAYB_DELAYB(x)                     (((uint16_t)(((uint16_t)(x)) << PDB_DELAYB_DELAYB_SHIFT)) & PDB_DELAYB_DELAYB_MASK)
/*! @} */

/*! @name DELAYC - DelayC Register */
/*! @{ */

#define PDB_DELAYC_DELAYC_MASK                   (0xFFFFU)
#define PDB_DELAYC_DELAYC_SHIFT                  (0U)
/*! DELAYC - Delay C */
#define PDB_DELAYC_DELAYC(x)                     (((uint16_t)(((uint16_t)(x)) << PDB_DELAYC_DELAYC_SHIFT)) & PDB_DELAYC_DELAYC_MASK)
/*! @} */

/*! @name DELAYD - DelayD Register */
/*! @{ */

#define PDB_DELAYD_DELAYD_MASK                   (0xFFFFU)
#define PDB_DELAYD_DELAYD_SHIFT                  (0U)
/*! DELAYD - Delay D */
#define PDB_DELAYD_DELAYD(x)                     (((uint16_t)(((uint16_t)(x)) << PDB_DELAYD_DELAYD_SHIFT)) & PDB_DELAYD_DELAYD_MASK)
/*! @} */

/*! @name MOD - Modulus Register */
/*! @{ */

#define PDB_MOD_MOD_MASK                         (0xFFFFU)
#define PDB_MOD_MOD_SHIFT                        (0U)
#define PDB_MOD_MOD(x)                           (((uint16_t)(((uint16_t)(x)) << PDB_MOD_MOD_SHIFT)) & PDB_MOD_MOD_MASK)
/*! @} */

/*! @name CNTR - Counter Register */
/*! @{ */

#define PDB_CNTR_COUNT_MASK                      (0xFFFFU)
#define PDB_CNTR_COUNT_SHIFT                     (0U)
#define PDB_CNTR_COUNT(x)                        (((uint16_t)(((uint16_t)(x)) << PDB_CNTR_COUNT_SHIFT)) & PDB_CNTR_COUNT_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group PDB_Register_Masks */


/*!
 * @}
 */ /* end of group PDB_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

#if defined(__CWCC__)
  #pragma pop
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_PDB_H_ */

