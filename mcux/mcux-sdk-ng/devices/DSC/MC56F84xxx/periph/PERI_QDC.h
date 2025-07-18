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
**         CMSIS Peripheral Access Layer for QDC
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
 * @file PERI_QDC.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for QDC
 *
 * CMSIS Peripheral Access Layer for QDC
 */

#if !defined(PERI_QDC_H_)
#define PERI_QDC_H_                              /**< Symbol preventing repeated inclusion */

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
   -- QDC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup QDC_Peripheral_Access_Layer QDC Peripheral Access Layer
 * @{
 */

/** QDC - Register Layout Typedef */
typedef struct {
  __IO uint16_t CTRL;                              /**< Control Register, offset: 0x0 */
  __IO uint16_t FILT;                              /**< Input Filter Register, offset: 0x1 */
  __IO uint16_t WTR;                               /**< Watchdog Timeout Register, offset: 0x2 */
  __IO uint16_t POSD;                              /**< Position Difference Counter Register, offset: 0x3 */
  __I  uint16_t POSDH;                             /**< Position Difference Hold Register, offset: 0x4 */
  __IO uint16_t REV;                               /**< Revolution Counter Register, offset: 0x5 */
  __I  uint16_t REVH;                              /**< Revolution Hold Register, offset: 0x6 */
  __IO uint16_t UPOS;                              /**< Upper Position Counter Register, offset: 0x7 */
  __IO uint16_t LPOS;                              /**< Lower Position Counter Register, offset: 0x8 */
  __I  uint16_t UPOSH;                             /**< Upper Position Hold Register, offset: 0x9 */
  __I  uint16_t LPOSH;                             /**< Lower Position Hold Register, offset: 0xA */
  __IO uint16_t UINIT;                             /**< Upper Initialization Register, offset: 0xB */
  __IO uint16_t LINIT;                             /**< Lower Initialization Register, offset: 0xC */
  __I  uint16_t IMR;                               /**< Input Monitor Register, offset: 0xD */
  __IO uint16_t TST;                               /**< Test Register, offset: 0xE */
  __IO uint16_t CTRL2;                             /**< Control 2 Register, offset: 0xF */
  __IO uint16_t UMOD;                              /**< Upper Modulus Register, offset: 0x10 */
  __IO uint16_t LMOD;                              /**< Lower Modulus Register, offset: 0x11 */
  __IO uint16_t UCOMP;                             /**< Upper Position Compare Register, offset: 0x12 */
  __IO uint16_t LCOMP;                             /**< Lower Position Compare Register, offset: 0x13 */
} QDC_Type;

/* ----------------------------------------------------------------------------
   -- QDC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup QDC_Register_Masks QDC Register Masks
 * @{
 */

/*! @name CTRL - Control Register */
/*! @{ */

#define QDC_CTRL_CMPIE_MASK                      (0x1U)
#define QDC_CTRL_CMPIE_SHIFT                     (0U)
/*! CMPIE - Compare Interrupt Enable
 *  0b0..Compare interrupt is disabled
 *  0b1..Compare interrupt is enabled
 */
#define QDC_CTRL_CMPIE(x)                        (((uint16_t)(((uint16_t)(x)) << QDC_CTRL_CMPIE_SHIFT)) & QDC_CTRL_CMPIE_MASK)

#define QDC_CTRL_CMPIRQ_MASK                     (0x2U)
#define QDC_CTRL_CMPIRQ_SHIFT                    (1U)
/*! CMPIRQ - Compare Interrupt Request
 *  0b0..No match has occurred
 *  0b1..COMP match has occurred
 */
#define QDC_CTRL_CMPIRQ(x)                       (((uint16_t)(((uint16_t)(x)) << QDC_CTRL_CMPIRQ_SHIFT)) & QDC_CTRL_CMPIRQ_MASK)

#define QDC_CTRL_WDE_MASK                        (0x4U)
#define QDC_CTRL_WDE_SHIFT                       (2U)
/*! WDE - Watchdog Enable
 *  0b0..Watchdog timer is disabled
 *  0b1..Watchdog timer is enabled
 */
#define QDC_CTRL_WDE(x)                          (((uint16_t)(((uint16_t)(x)) << QDC_CTRL_WDE_SHIFT)) & QDC_CTRL_WDE_MASK)

#define QDC_CTRL_DIE_MASK                        (0x8U)
#define QDC_CTRL_DIE_SHIFT                       (3U)
/*! DIE - Watchdog Timeout Interrupt Enable
 *  0b0..Watchdog timer interrupt is disabled
 *  0b1..Watchdog timer interrupt is enabled
 */
#define QDC_CTRL_DIE(x)                          (((uint16_t)(((uint16_t)(x)) << QDC_CTRL_DIE_SHIFT)) & QDC_CTRL_DIE_MASK)

#define QDC_CTRL_DIRQ_MASK                       (0x10U)
#define QDC_CTRL_DIRQ_SHIFT                      (4U)
/*! DIRQ - Watchdog Timeout Interrupt Request
 *  0b0..No interrupt has occurred
 *  0b1..Watchdog timeout interrupt has occurred
 */
#define QDC_CTRL_DIRQ(x)                         (((uint16_t)(((uint16_t)(x)) << QDC_CTRL_DIRQ_SHIFT)) & QDC_CTRL_DIRQ_MASK)

#define QDC_CTRL_XNE_MASK                        (0x20U)
#define QDC_CTRL_XNE_SHIFT                       (5U)
/*! XNE - Use Negative Edge of INDEX Pulse
 *  0b0..Use positive transition edge of INDEX pulse
 *  0b1..Use negative transition edge of INDEX pulse
 */
#define QDC_CTRL_XNE(x)                          (((uint16_t)(((uint16_t)(x)) << QDC_CTRL_XNE_SHIFT)) & QDC_CTRL_XNE_MASK)

#define QDC_CTRL_XIP_MASK                        (0x40U)
#define QDC_CTRL_XIP_SHIFT                       (6U)
/*! XIP - INDEX Triggered Initialization of Position Counters UPOS and LPOS
 *  0b0..No action
 *  0b1..INDEX pulse initializes the position counter
 */
#define QDC_CTRL_XIP(x)                          (((uint16_t)(((uint16_t)(x)) << QDC_CTRL_XIP_SHIFT)) & QDC_CTRL_XIP_MASK)

#define QDC_CTRL_XIE_MASK                        (0x80U)
#define QDC_CTRL_XIE_SHIFT                       (7U)
/*! XIE - INDEX Pulse Interrupt Enable
 *  0b0..INDEX pulse interrupt is disabled
 *  0b1..INDEX pulse interrupt is enabled
 */
#define QDC_CTRL_XIE(x)                          (((uint16_t)(((uint16_t)(x)) << QDC_CTRL_XIE_SHIFT)) & QDC_CTRL_XIE_MASK)

#define QDC_CTRL_XIRQ_MASK                       (0x100U)
#define QDC_CTRL_XIRQ_SHIFT                      (8U)
/*! XIRQ - INDEX Pulse Interrupt Request
 *  0b0..No interrupt has occurred
 *  0b1..INDEX pulse interrupt has occurred
 */
#define QDC_CTRL_XIRQ(x)                         (((uint16_t)(((uint16_t)(x)) << QDC_CTRL_XIRQ_SHIFT)) & QDC_CTRL_XIRQ_MASK)

#define QDC_CTRL_PH1_MASK                        (0x200U)
#define QDC_CTRL_PH1_SHIFT                       (9U)
/*! PH1 - Enable Signal Phase Count Mode
 *  0b0..Use standard quadrature decoder where PHASEA and PHASEB represent a two phase quadrature signal.
 *  0b1..Bypass the quadrature decoder. A positive transition of the PHASEA input generates a count signal. The
 *       PHASEB input and the REV bit control the counter direction. If CTRL[REV] = 0, PHASEB = 0, then count up If
 *       CTRL[REV] = 0, PHASEB = 1, then count down If CTRL[REV] = 1, PHASEB = 0, then count down If CTRL[REV] = 1,
 *       PHASEB = 1, then count up
 */
#define QDC_CTRL_PH1(x)                          (((uint16_t)(((uint16_t)(x)) << QDC_CTRL_PH1_SHIFT)) & QDC_CTRL_PH1_MASK)

#define QDC_CTRL_REV_MASK                        (0x400U)
#define QDC_CTRL_REV_SHIFT                       (10U)
/*! REV - Enable Reverse Direction Counting
 *  0b0..Count normally
 *  0b1..Count in the reverse direction
 */
#define QDC_CTRL_REV(x)                          (((uint16_t)(((uint16_t)(x)) << QDC_CTRL_REV_SHIFT)) & QDC_CTRL_REV_MASK)

#define QDC_CTRL_SWIP_MASK                       (0x800U)
#define QDC_CTRL_SWIP_SHIFT                      (11U)
/*! SWIP - Software Triggered Initialization of Position Counters UPOS and LPOS
 *  0b0..No action
 *  0b1..Initialize position counter
 */
#define QDC_CTRL_SWIP(x)                         (((uint16_t)(((uint16_t)(x)) << QDC_CTRL_SWIP_SHIFT)) & QDC_CTRL_SWIP_MASK)

#define QDC_CTRL_HNE_MASK                        (0x1000U)
#define QDC_CTRL_HNE_SHIFT                       (12U)
/*! HNE - Use Negative Edge of HOME Input
 *  0b0..Use positive going edge-to-trigger initialization of position counters UPOS and LPOS
 *  0b1..Use negative going edge-to-trigger initialization of position counters UPOS and LPOS
 */
#define QDC_CTRL_HNE(x)                          (((uint16_t)(((uint16_t)(x)) << QDC_CTRL_HNE_SHIFT)) & QDC_CTRL_HNE_MASK)

#define QDC_CTRL_HIP_MASK                        (0x2000U)
#define QDC_CTRL_HIP_SHIFT                       (13U)
/*! HIP - Enable HOME to Initialize Position Counters UPOS and LPOS
 *  0b0..No action
 *  0b1..HOME signal initializes the position counter
 */
#define QDC_CTRL_HIP(x)                          (((uint16_t)(((uint16_t)(x)) << QDC_CTRL_HIP_SHIFT)) & QDC_CTRL_HIP_MASK)

#define QDC_CTRL_HIE_MASK                        (0x4000U)
#define QDC_CTRL_HIE_SHIFT                       (14U)
/*! HIE - HOME Interrupt Enable
 *  0b0..Disable HOME interrupts
 *  0b1..Enable HOME interrupts
 */
#define QDC_CTRL_HIE(x)                          (((uint16_t)(((uint16_t)(x)) << QDC_CTRL_HIE_SHIFT)) & QDC_CTRL_HIE_MASK)

#define QDC_CTRL_HIRQ_MASK                       (0x8000U)
#define QDC_CTRL_HIRQ_SHIFT                      (15U)
/*! HIRQ - HOME Signal Transition Interrupt Request
 *  0b0..No interrupt
 *  0b1..HOME signal transition interrupt request
 */
#define QDC_CTRL_HIRQ(x)                         (((uint16_t)(((uint16_t)(x)) << QDC_CTRL_HIRQ_SHIFT)) & QDC_CTRL_HIRQ_MASK)
/*! @} */

/*! @name FILT - Input Filter Register */
/*! @{ */

#define QDC_FILT_FILT_PER_MASK                   (0xFFU)
#define QDC_FILT_FILT_PER_SHIFT                  (0U)
/*! FILT_PER - Input Filter Sample Period */
#define QDC_FILT_FILT_PER(x)                     (((uint16_t)(((uint16_t)(x)) << QDC_FILT_FILT_PER_SHIFT)) & QDC_FILT_FILT_PER_MASK)

#define QDC_FILT_FILT_CNT_MASK                   (0x700U)
#define QDC_FILT_FILT_CNT_SHIFT                  (8U)
/*! FILT_CNT - Input Filter Sample Count */
#define QDC_FILT_FILT_CNT(x)                     (((uint16_t)(((uint16_t)(x)) << QDC_FILT_FILT_CNT_SHIFT)) & QDC_FILT_FILT_CNT_MASK)
/*! @} */

/*! @name WTR - Watchdog Timeout Register */
/*! @{ */

#define QDC_WTR_WDOG_MASK                        (0xFFFFU)
#define QDC_WTR_WDOG_SHIFT                       (0U)
#define QDC_WTR_WDOG(x)                          (((uint16_t)(((uint16_t)(x)) << QDC_WTR_WDOG_SHIFT)) & QDC_WTR_WDOG_MASK)
/*! @} */

/*! @name POSD - Position Difference Counter Register */
/*! @{ */

#define QDC_POSD_POSD_MASK                       (0xFFFFU)
#define QDC_POSD_POSD_SHIFT                      (0U)
#define QDC_POSD_POSD(x)                         (((uint16_t)(((uint16_t)(x)) << QDC_POSD_POSD_SHIFT)) & QDC_POSD_POSD_MASK)
/*! @} */

/*! @name POSDH - Position Difference Hold Register */
/*! @{ */

#define QDC_POSDH_POSDH_MASK                     (0xFFFFU)
#define QDC_POSDH_POSDH_SHIFT                    (0U)
#define QDC_POSDH_POSDH(x)                       (((uint16_t)(((uint16_t)(x)) << QDC_POSDH_POSDH_SHIFT)) & QDC_POSDH_POSDH_MASK)
/*! @} */

/*! @name REV - Revolution Counter Register */
/*! @{ */

#define QDC_REV_REV_MASK                         (0xFFFFU)
#define QDC_REV_REV_SHIFT                        (0U)
#define QDC_REV_REV(x)                           (((uint16_t)(((uint16_t)(x)) << QDC_REV_REV_SHIFT)) & QDC_REV_REV_MASK)
/*! @} */

/*! @name REVH - Revolution Hold Register */
/*! @{ */

#define QDC_REVH_REVH_MASK                       (0xFFFFU)
#define QDC_REVH_REVH_SHIFT                      (0U)
#define QDC_REVH_REVH(x)                         (((uint16_t)(((uint16_t)(x)) << QDC_REVH_REVH_SHIFT)) & QDC_REVH_REVH_MASK)
/*! @} */

/*! @name UPOS - Upper Position Counter Register */
/*! @{ */

#define QDC_UPOS_POS_MASK                        (0xFFFFU)
#define QDC_UPOS_POS_SHIFT                       (0U)
#define QDC_UPOS_POS(x)                          (((uint16_t)(((uint16_t)(x)) << QDC_UPOS_POS_SHIFT)) & QDC_UPOS_POS_MASK)
/*! @} */

/*! @name LPOS - Lower Position Counter Register */
/*! @{ */

#define QDC_LPOS_POS_MASK                        (0xFFFFU)
#define QDC_LPOS_POS_SHIFT                       (0U)
#define QDC_LPOS_POS(x)                          (((uint16_t)(((uint16_t)(x)) << QDC_LPOS_POS_SHIFT)) & QDC_LPOS_POS_MASK)
/*! @} */

/*! @name UPOSH - Upper Position Hold Register */
/*! @{ */

#define QDC_UPOSH_POSH_MASK                      (0xFFFFU)
#define QDC_UPOSH_POSH_SHIFT                     (0U)
#define QDC_UPOSH_POSH(x)                        (((uint16_t)(((uint16_t)(x)) << QDC_UPOSH_POSH_SHIFT)) & QDC_UPOSH_POSH_MASK)
/*! @} */

/*! @name LPOSH - Lower Position Hold Register */
/*! @{ */

#define QDC_LPOSH_POSH_MASK                      (0xFFFFU)
#define QDC_LPOSH_POSH_SHIFT                     (0U)
#define QDC_LPOSH_POSH(x)                        (((uint16_t)(((uint16_t)(x)) << QDC_LPOSH_POSH_SHIFT)) & QDC_LPOSH_POSH_MASK)
/*! @} */

/*! @name UINIT - Upper Initialization Register */
/*! @{ */

#define QDC_UINIT_INIT_MASK                      (0xFFFFU)
#define QDC_UINIT_INIT_SHIFT                     (0U)
#define QDC_UINIT_INIT(x)                        (((uint16_t)(((uint16_t)(x)) << QDC_UINIT_INIT_SHIFT)) & QDC_UINIT_INIT_MASK)
/*! @} */

/*! @name LINIT - Lower Initialization Register */
/*! @{ */

#define QDC_LINIT_INIT_MASK                      (0xFFFFU)
#define QDC_LINIT_INIT_SHIFT                     (0U)
#define QDC_LINIT_INIT(x)                        (((uint16_t)(((uint16_t)(x)) << QDC_LINIT_INIT_SHIFT)) & QDC_LINIT_INIT_MASK)
/*! @} */

/*! @name IMR - Input Monitor Register */
/*! @{ */

#define QDC_IMR_HOME_MASK                        (0x1U)
#define QDC_IMR_HOME_SHIFT                       (0U)
#define QDC_IMR_HOME(x)                          (((uint16_t)(((uint16_t)(x)) << QDC_IMR_HOME_SHIFT)) & QDC_IMR_HOME_MASK)

#define QDC_IMR_INDEX_MASK                       (0x2U)
#define QDC_IMR_INDEX_SHIFT                      (1U)
#define QDC_IMR_INDEX(x)                         (((uint16_t)(((uint16_t)(x)) << QDC_IMR_INDEX_SHIFT)) & QDC_IMR_INDEX_MASK)

#define QDC_IMR_PHB_MASK                         (0x4U)
#define QDC_IMR_PHB_SHIFT                        (2U)
#define QDC_IMR_PHB(x)                           (((uint16_t)(((uint16_t)(x)) << QDC_IMR_PHB_SHIFT)) & QDC_IMR_PHB_MASK)

#define QDC_IMR_PHA_MASK                         (0x8U)
#define QDC_IMR_PHA_SHIFT                        (3U)
#define QDC_IMR_PHA(x)                           (((uint16_t)(((uint16_t)(x)) << QDC_IMR_PHA_SHIFT)) & QDC_IMR_PHA_MASK)

#define QDC_IMR_FHOM_MASK                        (0x10U)
#define QDC_IMR_FHOM_SHIFT                       (4U)
#define QDC_IMR_FHOM(x)                          (((uint16_t)(((uint16_t)(x)) << QDC_IMR_FHOM_SHIFT)) & QDC_IMR_FHOM_MASK)

#define QDC_IMR_FIND_MASK                        (0x20U)
#define QDC_IMR_FIND_SHIFT                       (5U)
#define QDC_IMR_FIND(x)                          (((uint16_t)(((uint16_t)(x)) << QDC_IMR_FIND_SHIFT)) & QDC_IMR_FIND_MASK)

#define QDC_IMR_FPHB_MASK                        (0x40U)
#define QDC_IMR_FPHB_SHIFT                       (6U)
#define QDC_IMR_FPHB(x)                          (((uint16_t)(((uint16_t)(x)) << QDC_IMR_FPHB_SHIFT)) & QDC_IMR_FPHB_MASK)

#define QDC_IMR_FPHA_MASK                        (0x80U)
#define QDC_IMR_FPHA_SHIFT                       (7U)
#define QDC_IMR_FPHA(x)                          (((uint16_t)(((uint16_t)(x)) << QDC_IMR_FPHA_SHIFT)) & QDC_IMR_FPHA_MASK)
/*! @} */

/*! @name TST - Test Register */
/*! @{ */

#define QDC_TST_TEST_COUNT_MASK                  (0xFFU)
#define QDC_TST_TEST_COUNT_SHIFT                 (0U)
#define QDC_TST_TEST_COUNT(x)                    (((uint16_t)(((uint16_t)(x)) << QDC_TST_TEST_COUNT_SHIFT)) & QDC_TST_TEST_COUNT_MASK)

#define QDC_TST_TEST_PERIOD_MASK                 (0x1F00U)
#define QDC_TST_TEST_PERIOD_SHIFT                (8U)
#define QDC_TST_TEST_PERIOD(x)                   (((uint16_t)(((uint16_t)(x)) << QDC_TST_TEST_PERIOD_SHIFT)) & QDC_TST_TEST_PERIOD_MASK)

#define QDC_TST_QDN_MASK                         (0x2000U)
#define QDC_TST_QDN_SHIFT                        (13U)
/*! QDN - Quadrature Decoder Negative Signal
 *  0b0..Leaves quadrature decoder signal in a positive direction
 *  0b1..Generates a negative quadrature decoder signal
 */
#define QDC_TST_QDN(x)                           (((uint16_t)(((uint16_t)(x)) << QDC_TST_QDN_SHIFT)) & QDC_TST_QDN_MASK)

#define QDC_TST_TCE_MASK                         (0x4000U)
#define QDC_TST_TCE_SHIFT                        (14U)
/*! TCE - Test Counter Enable
 *  0b0..Test count is not enabled
 *  0b1..Test count is enabled
 */
#define QDC_TST_TCE(x)                           (((uint16_t)(((uint16_t)(x)) << QDC_TST_TCE_SHIFT)) & QDC_TST_TCE_MASK)

#define QDC_TST_TEN_MASK                         (0x8000U)
#define QDC_TST_TEN_SHIFT                        (15U)
/*! TEN - Test Mode Enable
 *  0b0..Test module is not enabled
 *  0b1..Test module is enabled
 */
#define QDC_TST_TEN(x)                           (((uint16_t)(((uint16_t)(x)) << QDC_TST_TEN_SHIFT)) & QDC_TST_TEN_MASK)
/*! @} */

/*! @name CTRL2 - Control 2 Register */
/*! @{ */

#define QDC_CTRL2_UPDHLD_MASK                    (0x1U)
#define QDC_CTRL2_UPDHLD_SHIFT                   (0U)
/*! UPDHLD - Update Hold Registers
 *  0b0..Disable updates of hold registers on rising edge of TRIGGER
 *  0b1..Enable updates of hold registers on rising edge of TRIGGER
 */
#define QDC_CTRL2_UPDHLD(x)                      (((uint16_t)(((uint16_t)(x)) << QDC_CTRL2_UPDHLD_SHIFT)) & QDC_CTRL2_UPDHLD_MASK)

#define QDC_CTRL2_UPDPOS_MASK                    (0x2U)
#define QDC_CTRL2_UPDPOS_SHIFT                   (1U)
/*! UPDPOS - Update Position Registers
 *  0b0..No action for POSD, REV, UPOS and LPOS on rising edge of TRIGGER
 *  0b1..Clear POSD, REV, UPOS and LPOS on rising edge of TRIGGER
 */
#define QDC_CTRL2_UPDPOS(x)                      (((uint16_t)(((uint16_t)(x)) << QDC_CTRL2_UPDPOS_SHIFT)) & QDC_CTRL2_UPDPOS_MASK)

#define QDC_CTRL2_MOD_MASK                       (0x4U)
#define QDC_CTRL2_MOD_SHIFT                      (2U)
/*! MOD - Enable Modulo Counting
 *  0b0..Disable modulo counting
 *  0b1..Enable modulo counting
 */
#define QDC_CTRL2_MOD(x)                         (((uint16_t)(((uint16_t)(x)) << QDC_CTRL2_MOD_SHIFT)) & QDC_CTRL2_MOD_MASK)

#define QDC_CTRL2_DIR_MASK                       (0x8U)
#define QDC_CTRL2_DIR_SHIFT                      (3U)
/*! DIR - Count Direction Flag
 *  0b0..Last count was in the down direction
 *  0b1..Last count was in the up direction
 */
#define QDC_CTRL2_DIR(x)                         (((uint16_t)(((uint16_t)(x)) << QDC_CTRL2_DIR_SHIFT)) & QDC_CTRL2_DIR_MASK)

#define QDC_CTRL2_RUIE_MASK                      (0x10U)
#define QDC_CTRL2_RUIE_SHIFT                     (4U)
/*! RUIE - Roll-under Interrupt Enable
 *  0b0..Roll-under interrupt is disabled
 *  0b1..Roll-under interrupt is enabled
 */
#define QDC_CTRL2_RUIE(x)                        (((uint16_t)(((uint16_t)(x)) << QDC_CTRL2_RUIE_SHIFT)) & QDC_CTRL2_RUIE_MASK)

#define QDC_CTRL2_RUIRQ_MASK                     (0x20U)
#define QDC_CTRL2_RUIRQ_SHIFT                    (5U)
/*! RUIRQ - Roll-under Interrupt Request
 *  0b0..No roll-under has occurred
 *  0b1..Roll-under has occurred
 */
#define QDC_CTRL2_RUIRQ(x)                       (((uint16_t)(((uint16_t)(x)) << QDC_CTRL2_RUIRQ_SHIFT)) & QDC_CTRL2_RUIRQ_MASK)

#define QDC_CTRL2_ROIE_MASK                      (0x40U)
#define QDC_CTRL2_ROIE_SHIFT                     (6U)
/*! ROIE - Roll-over Interrupt Enable
 *  0b0..Roll-over interrupt is disabled
 *  0b1..Roll-over interrupt is enabled
 */
#define QDC_CTRL2_ROIE(x)                        (((uint16_t)(((uint16_t)(x)) << QDC_CTRL2_ROIE_SHIFT)) & QDC_CTRL2_ROIE_MASK)

#define QDC_CTRL2_ROIRQ_MASK                     (0x80U)
#define QDC_CTRL2_ROIRQ_SHIFT                    (7U)
/*! ROIRQ - Roll-over Interrupt Request
 *  0b0..No roll-over has occurred
 *  0b1..Roll-over has occurred
 */
#define QDC_CTRL2_ROIRQ(x)                       (((uint16_t)(((uint16_t)(x)) << QDC_CTRL2_ROIRQ_SHIFT)) & QDC_CTRL2_ROIRQ_MASK)

#define QDC_CTRL2_REVMOD_MASK                    (0x100U)
#define QDC_CTRL2_REVMOD_SHIFT                   (8U)
/*! REVMOD - Revolution Counter Modulus Enable
 *  0b0..Use INDEX pulse to increment/decrement revolution counter (REV).
 *  0b1..Use modulus counting roll-over/under to increment/decrement revolution counter (REV).
 */
#define QDC_CTRL2_REVMOD(x)                      (((uint16_t)(((uint16_t)(x)) << QDC_CTRL2_REVMOD_SHIFT)) & QDC_CTRL2_REVMOD_MASK)

#define QDC_CTRL2_OUTCTL_MASK                    (0x200U)
#define QDC_CTRL2_OUTCTL_SHIFT                   (9U)
/*! OUTCTL - Output Control
 *  0b0..POSMATCH pulses when a match occurs between the position counters (POS) and the compare value (COMP).
 *  0b1..POSMATCH pulses when the UPOS, LPOS, REV, or POSD registers are read.
 */
#define QDC_CTRL2_OUTCTL(x)                      (((uint16_t)(((uint16_t)(x)) << QDC_CTRL2_OUTCTL_SHIFT)) & QDC_CTRL2_OUTCTL_MASK)
/*! @} */

/*! @name UMOD - Upper Modulus Register */
/*! @{ */

#define QDC_UMOD_MOD_MASK                        (0xFFFFU)
#define QDC_UMOD_MOD_SHIFT                       (0U)
#define QDC_UMOD_MOD(x)                          (((uint16_t)(((uint16_t)(x)) << QDC_UMOD_MOD_SHIFT)) & QDC_UMOD_MOD_MASK)
/*! @} */

/*! @name LMOD - Lower Modulus Register */
/*! @{ */

#define QDC_LMOD_MOD_MASK                        (0xFFFFU)
#define QDC_LMOD_MOD_SHIFT                       (0U)
#define QDC_LMOD_MOD(x)                          (((uint16_t)(((uint16_t)(x)) << QDC_LMOD_MOD_SHIFT)) & QDC_LMOD_MOD_MASK)
/*! @} */

/*! @name UCOMP - Upper Position Compare Register */
/*! @{ */

#define QDC_UCOMP_COMP_MASK                      (0xFFFFU)
#define QDC_UCOMP_COMP_SHIFT                     (0U)
#define QDC_UCOMP_COMP(x)                        (((uint16_t)(((uint16_t)(x)) << QDC_UCOMP_COMP_SHIFT)) & QDC_UCOMP_COMP_MASK)
/*! @} */

/*! @name LCOMP - Lower Position Compare Register */
/*! @{ */

#define QDC_LCOMP_COMP_MASK                      (0xFFFFU)
#define QDC_LCOMP_COMP_SHIFT                     (0U)
#define QDC_LCOMP_COMP(x)                        (((uint16_t)(((uint16_t)(x)) << QDC_LCOMP_COMP_SHIFT)) & QDC_LCOMP_COMP_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group QDC_Register_Masks */


/*!
 * @}
 */ /* end of group QDC_Peripheral_Access_Layer */


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


#endif  /* PERI_QDC_H_ */

