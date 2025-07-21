/*
** ###################################################################
**     Processors:          MIMX8ML2CVNKZ_ca53
**                          MIMX8ML2CVNKZ_cm7
**                          MIMX8ML2CVNKZ_dsp
**                          MIMX8ML2DVNLZ_ca53
**                          MIMX8ML2DVNLZ_cm7
**                          MIMX8ML2DVNLZ_dsp
**                          MIMX8ML3CVNKZ_ca53
**                          MIMX8ML3CVNKZ_cm7
**                          MIMX8ML3CVNKZ_dsp
**                          MIMX8ML3DVNLZ_ca53
**                          MIMX8ML3DVNLZ_cm7
**                          MIMX8ML3DVNLZ_dsp
**                          MIMX8ML4CVNKZ_ca53
**                          MIMX8ML4CVNKZ_cm7
**                          MIMX8ML4DVNLZ_ca53
**                          MIMX8ML4DVNLZ_cm7
**                          MIMX8ML5CVNKZ_ca53
**                          MIMX8ML5CVNKZ_cm7
**                          MIMX8ML5CVNKZ_dsp
**                          MIMX8ML5DVNLZ_ca53
**                          MIMX8ML5DVNLZ_cm7
**                          MIMX8ML5DVNLZ_dsp
**                          MIMX8ML6CVNKZ_ca53
**                          MIMX8ML6CVNKZ_cm7
**                          MIMX8ML6DVNLZ_ca53
**                          MIMX8ML6DVNLZ_cm7
**                          MIMX8ML8CVNKZ_ca53
**                          MIMX8ML8CVNKZ_cm7
**                          MIMX8ML8CVNKZ_dsp
**                          MIMX8ML8DVNLZ_ca53
**                          MIMX8ML8DVNLZ_cm7
**                          MIMX8ML8DVNLZ_dsp
**
**     Version:             rev. 6.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for TMU
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2019-10-11)
**         Initial version.
**     - rev. 2.0 (2020-02-21)
**         Rev.B Header.
**     - rev. 3.0 (2020-06-22)
**         Rev.C Header.
**     - rev. 4.0 (2020-11-16)
**         Rev.D Header.
**     - rev. 5.0 (2021-03-01)
**         Rev.D Header Final.
**     - rev. 6.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_TMU.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for TMU
 *
 * CMSIS Peripheral Access Layer for TMU
 */

#if !defined(PERI_TMU_H_)
#define PERI_TMU_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8ML2CVNKZ_ca53) || defined(CPU_MIMX8ML2DVNLZ_ca53))
#include "MIMX8ML2_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML2CVNKZ_cm7) || defined(CPU_MIMX8ML2DVNLZ_cm7))
#include "MIMX8ML2_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML2CVNKZ_dsp) || defined(CPU_MIMX8ML2DVNLZ_dsp))
#include "MIMX8ML2_dsp_COMMON.h"
#elif (defined(CPU_MIMX8ML3CVNKZ_ca53) || defined(CPU_MIMX8ML3DVNLZ_ca53))
#include "MIMX8ML3_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML3CVNKZ_cm7) || defined(CPU_MIMX8ML3DVNLZ_cm7))
#include "MIMX8ML3_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML3CVNKZ_dsp) || defined(CPU_MIMX8ML3DVNLZ_dsp))
#include "MIMX8ML3_dsp_COMMON.h"
#elif (defined(CPU_MIMX8ML4CVNKZ_ca53) || defined(CPU_MIMX8ML4DVNLZ_ca53))
#include "MIMX8ML4_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML4CVNKZ_cm7) || defined(CPU_MIMX8ML4DVNLZ_cm7))
#include "MIMX8ML4_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML5CVNKZ_ca53) || defined(CPU_MIMX8ML5DVNLZ_ca53))
#include "MIMX8ML5_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML5CVNKZ_cm7) || defined(CPU_MIMX8ML5DVNLZ_cm7))
#include "MIMX8ML5_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML5CVNKZ_dsp) || defined(CPU_MIMX8ML5DVNLZ_dsp))
#include "MIMX8ML5_dsp_COMMON.h"
#elif (defined(CPU_MIMX8ML6CVNKZ_ca53) || defined(CPU_MIMX8ML6DVNLZ_ca53))
#include "MIMX8ML6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML6CVNKZ_cm7) || defined(CPU_MIMX8ML6DVNLZ_cm7))
#include "MIMX8ML6_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML8CVNKZ_ca53) || defined(CPU_MIMX8ML8DVNLZ_ca53))
#include "MIMX8ML8_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML8CVNKZ_cm7) || defined(CPU_MIMX8ML8DVNLZ_cm7))
#include "MIMX8ML8_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML8CVNKZ_dsp) || defined(CPU_MIMX8ML8DVNLZ_dsp))
#include "MIMX8ML8_dsp_COMMON.h"
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
   -- TMU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TMU_Peripheral_Access_Layer TMU Peripheral Access Layer
 * @{
 */

/** TMU - Register Layout Typedef */
typedef struct {
  __IO uint32_t TER;                               /**< TMU Enable register, offset: 0x0 */
  __IO uint32_t TPS;                               /**< TMU Probe Select register, offset: 0x4 */
  __IO uint32_t TIER;                              /**< TMU Interrupt Enable register, offset: 0x8 */
  __IO uint32_t TIDR;                              /**< TMU Interrupt Detect register, offset: 0xC */
  __IO uint32_t TMHTITR;                           /**< TMU Monitor High Temperature Immediate Threshold register, offset: 0x10 */
  __IO uint32_t TMHTATR;                           /**< TMU Monitor High Temperature Average threshold register, offset: 0x14 */
  __IO uint32_t TMHTACTR;                          /**< TMU Monitor High Temperature Average Critical Threshold register, offset: 0x18 */
  __I  uint32_t TSCR;                              /**< TMU Sensor Calibration register, offset: 0x1C */
  __I  uint32_t TRITSR;                            /**< TMU Report Immediate Temperature Site register n, offset: 0x20 */
  __I  uint32_t TRATSR;                            /**< TMU Report Average Temperature Site register n, offset: 0x24 */
} TMU_Type;

/* ----------------------------------------------------------------------------
   -- TMU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TMU_Register_Masks TMU Register Masks
 * @{
 */

/*! @name TER - TMU Enable register */
/*! @{ */

#define TMU_TER_ALPF_MASK                        (0x3U)
#define TMU_TER_ALPF_SHIFT                       (0U)
/*! ALPF
 *  0b00..1.0
 *  0b01..0.5
 *  0b10..0.25
 *  0b11..0.125
 */
#define TMU_TER_ALPF(x)                          (((uint32_t)(((uint32_t)(x)) << TMU_TER_ALPF_SHIFT)) & TMU_TER_ALPF_MASK)

#define TMU_TER_ADC_PD_MASK                      (0x40000000U)
#define TMU_TER_ADC_PD_SHIFT                     (30U)
/*! ADC_PD
 *  0b0..normal operating mode
 *  0b1..power down mode
 */
#define TMU_TER_ADC_PD(x)                        (((uint32_t)(((uint32_t)(x)) << TMU_TER_ADC_PD_SHIFT)) & TMU_TER_ADC_PD_MASK)

#define TMU_TER_EN_MASK                          (0x80000000U)
#define TMU_TER_EN_SHIFT                         (31U)
/*! EN
 *  0b0..Disable
 *  0b1..Enable
 */
#define TMU_TER_EN(x)                            (((uint32_t)(((uint32_t)(x)) << TMU_TER_EN_SHIFT)) & TMU_TER_EN_MASK)
/*! @} */

/*! @name TPS - TMU Probe Select register */
/*! @{ */

#define TMU_TPS_PROBE_SEL_MASK                   (0xC0000000U)
#define TMU_TPS_PROBE_SEL_SHIFT                  (30U)
/*! PROBE_SEL
 *  0b00..select the main probe only
 *  0b01..select the remote probe(near A53) only
 *  0b1x..select both 2 probes
 */
#define TMU_TPS_PROBE_SEL(x)                     (((uint32_t)(((uint32_t)(x)) << TMU_TPS_PROBE_SEL_SHIFT)) & TMU_TPS_PROBE_SEL_MASK)
/*! @} */

/*! @name TIER - TMU Interrupt Enable register */
/*! @{ */

#define TMU_TIER_ATCTEIE0_MASK                   (0x2000000U)
#define TMU_TIER_ATCTEIE0_SHIFT                  (25U)
/*! ATCTEIE0
 *  0b0..Disabled.
 *  0b1..Interrupt enabled. Generate an interrupt if TIDR[ATCTE] is set.
 */
#define TMU_TIER_ATCTEIE0(x)                     (((uint32_t)(((uint32_t)(x)) << TMU_TIER_ATCTEIE0_SHIFT)) & TMU_TIER_ATCTEIE0_MASK)

#define TMU_TIER_ATTEIE0_MASK                    (0x4000000U)
#define TMU_TIER_ATTEIE0_SHIFT                   (26U)
/*! ATTEIE0
 *  0b0..Disabled.
 *  0b1..Interrupt enabled. Generate an interrupt if TIDR[ATTE] is set.
 */
#define TMU_TIER_ATTEIE0(x)                      (((uint32_t)(((uint32_t)(x)) << TMU_TIER_ATTEIE0_SHIFT)) & TMU_TIER_ATTEIE0_MASK)

#define TMU_TIER_ITTEIE0_MASK                    (0x8000000U)
#define TMU_TIER_ITTEIE0_SHIFT                   (27U)
/*! ITTEIE0
 *  0b0..Disabled.
 *  0b1..Interrupt enabled. Generate an interrupt if TIDR[ITTE] is set.
 */
#define TMU_TIER_ITTEIE0(x)                      (((uint32_t)(((uint32_t)(x)) << TMU_TIER_ITTEIE0_SHIFT)) & TMU_TIER_ITTEIE0_MASK)

#define TMU_TIER_ATCTEIE1_MASK                   (0x20000000U)
#define TMU_TIER_ATCTEIE1_SHIFT                  (29U)
/*! ATCTEIE1
 *  0b0..Disabled.
 *  0b1..Interrupt enabled. Generate an interrupt if TIDR[ATCTE] is set.
 */
#define TMU_TIER_ATCTEIE1(x)                     (((uint32_t)(((uint32_t)(x)) << TMU_TIER_ATCTEIE1_SHIFT)) & TMU_TIER_ATCTEIE1_MASK)

#define TMU_TIER_ATTEIE1_MASK                    (0x40000000U)
#define TMU_TIER_ATTEIE1_SHIFT                   (30U)
/*! ATTEIE1
 *  0b0..Disabled.
 *  0b1..Interrupt enabled. Generate an interrupt if TIDR[ATTE] is set.
 */
#define TMU_TIER_ATTEIE1(x)                      (((uint32_t)(((uint32_t)(x)) << TMU_TIER_ATTEIE1_SHIFT)) & TMU_TIER_ATTEIE1_MASK)

#define TMU_TIER_ITTEIE1_MASK                    (0x80000000U)
#define TMU_TIER_ITTEIE1_SHIFT                   (31U)
/*! ITTEIE1
 *  0b0..Disabled.
 *  0b1..Interrupt enabled. Generate an interrupt if TIDR[ITTE] is set.
 */
#define TMU_TIER_ITTEIE1(x)                      (((uint32_t)(((uint32_t)(x)) << TMU_TIER_ITTEIE1_SHIFT)) & TMU_TIER_ITTEIE1_MASK)
/*! @} */

/*! @name TIDR - TMU Interrupt Detect register */
/*! @{ */

#define TMU_TIDR_ATCTE0_MASK                     (0x2000000U)
#define TMU_TIDR_ATCTE0_SHIFT                    (25U)
/*! ATCTE0
 *  0b0..No threshold exceeded.
 *  0b1..Average temperature critical threshold, as defined by TMHTACTR, has been exceeded.
 */
#define TMU_TIDR_ATCTE0(x)                       (((uint32_t)(((uint32_t)(x)) << TMU_TIDR_ATCTE0_SHIFT)) & TMU_TIDR_ATCTE0_MASK)

#define TMU_TIDR_ATTE0_MASK                      (0x4000000U)
#define TMU_TIDR_ATTE0_SHIFT                     (26U)
/*! ATTE0
 *  0b0..No threshold exceeded.
 *  0b1..Average temperature threshold, as defined by TMHTATR, has been exceeded.
 */
#define TMU_TIDR_ATTE0(x)                        (((uint32_t)(((uint32_t)(x)) << TMU_TIDR_ATTE0_SHIFT)) & TMU_TIDR_ATTE0_MASK)

#define TMU_TIDR_ITTE0_MASK                      (0x8000000U)
#define TMU_TIDR_ITTE0_SHIFT                     (27U)
/*! ITTE0
 *  0b0..No threshold exceeded.
 *  0b1..Immediate temperature threshold, as defined by TMHTITR, has been exceeded. This includes an out-of-range
 *       measured temperature above 125 degree C.
 */
#define TMU_TIDR_ITTE0(x)                        (((uint32_t)(((uint32_t)(x)) << TMU_TIDR_ITTE0_SHIFT)) & TMU_TIDR_ITTE0_MASK)

#define TMU_TIDR_ATCTE1_MASK                     (0x20000000U)
#define TMU_TIDR_ATCTE1_SHIFT                    (29U)
/*! ATCTE1
 *  0b0..No threshold exceeded.
 *  0b1..Average temperature critical threshold, as defined by TMHTACTR, has been exceeded.
 */
#define TMU_TIDR_ATCTE1(x)                       (((uint32_t)(((uint32_t)(x)) << TMU_TIDR_ATCTE1_SHIFT)) & TMU_TIDR_ATCTE1_MASK)

#define TMU_TIDR_ATTE1_MASK                      (0x40000000U)
#define TMU_TIDR_ATTE1_SHIFT                     (30U)
/*! ATTE1
 *  0b0..No threshold exceeded.
 *  0b1..Average temperature threshold, as defined by TMHTATR, has been exceeded.
 */
#define TMU_TIDR_ATTE1(x)                        (((uint32_t)(((uint32_t)(x)) << TMU_TIDR_ATTE1_SHIFT)) & TMU_TIDR_ATTE1_MASK)

#define TMU_TIDR_ITTE1_MASK                      (0x80000000U)
#define TMU_TIDR_ITTE1_SHIFT                     (31U)
/*! ITTE1
 *  0b0..No threshold exceeded.
 *  0b1..Immediate temperature threshold, as defined by TMHTITR, has been exceeded. This includes an out-of-range
 *       measured temperature above 125 degree C.
 */
#define TMU_TIDR_ITTE1(x)                        (((uint32_t)(((uint32_t)(x)) << TMU_TIDR_ITTE1_SHIFT)) & TMU_TIDR_ITTE1_MASK)
/*! @} */

/*! @name TMHTITR - TMU Monitor High Temperature Immediate Threshold register */
/*! @{ */

#define TMU_TMHTITR_TEMP0_MASK                   (0xFFU)
#define TMU_TMHTITR_TEMP0_SHIFT                  (0U)
#define TMU_TMHTITR_TEMP0(x)                     (((uint32_t)(((uint32_t)(x)) << TMU_TMHTITR_TEMP0_SHIFT)) & TMU_TMHTITR_TEMP0_MASK)

#define TMU_TMHTITR_TEMP1_MASK                   (0xFF0000U)
#define TMU_TMHTITR_TEMP1_SHIFT                  (16U)
#define TMU_TMHTITR_TEMP1(x)                     (((uint32_t)(((uint32_t)(x)) << TMU_TMHTITR_TEMP1_SHIFT)) & TMU_TMHTITR_TEMP1_MASK)

#define TMU_TMHTITR_EN0_MASK                     (0x40000000U)
#define TMU_TMHTITR_EN0_SHIFT                    (30U)
/*! EN0
 *  0b0..Disabled.
 *  0b1..Threshold enabled.
 */
#define TMU_TMHTITR_EN0(x)                       (((uint32_t)(((uint32_t)(x)) << TMU_TMHTITR_EN0_SHIFT)) & TMU_TMHTITR_EN0_MASK)

#define TMU_TMHTITR_EN1_MASK                     (0x80000000U)
#define TMU_TMHTITR_EN1_SHIFT                    (31U)
/*! EN1
 *  0b0..Disabled.
 *  0b1..Threshold enabled.
 */
#define TMU_TMHTITR_EN1(x)                       (((uint32_t)(((uint32_t)(x)) << TMU_TMHTITR_EN1_SHIFT)) & TMU_TMHTITR_EN1_MASK)
/*! @} */

/*! @name TMHTATR - TMU Monitor High Temperature Average threshold register */
/*! @{ */

#define TMU_TMHTATR_TEMP0_MASK                   (0xFFU)
#define TMU_TMHTATR_TEMP0_SHIFT                  (0U)
#define TMU_TMHTATR_TEMP0(x)                     (((uint32_t)(((uint32_t)(x)) << TMU_TMHTATR_TEMP0_SHIFT)) & TMU_TMHTATR_TEMP0_MASK)

#define TMU_TMHTATR_TEMP1_MASK                   (0xFF0000U)
#define TMU_TMHTATR_TEMP1_SHIFT                  (16U)
#define TMU_TMHTATR_TEMP1(x)                     (((uint32_t)(((uint32_t)(x)) << TMU_TMHTATR_TEMP1_SHIFT)) & TMU_TMHTATR_TEMP1_MASK)

#define TMU_TMHTATR_EN0_MASK                     (0x40000000U)
#define TMU_TMHTATR_EN0_SHIFT                    (30U)
/*! EN0
 *  0b0..Disabled.
 *  0b1..Threshold enabled.
 */
#define TMU_TMHTATR_EN0(x)                       (((uint32_t)(((uint32_t)(x)) << TMU_TMHTATR_EN0_SHIFT)) & TMU_TMHTATR_EN0_MASK)

#define TMU_TMHTATR_EN1_MASK                     (0x80000000U)
#define TMU_TMHTATR_EN1_SHIFT                    (31U)
/*! EN1
 *  0b0..Disabled.
 *  0b1..Threshold enabled.
 */
#define TMU_TMHTATR_EN1(x)                       (((uint32_t)(((uint32_t)(x)) << TMU_TMHTATR_EN1_SHIFT)) & TMU_TMHTATR_EN1_MASK)
/*! @} */

/*! @name TMHTACTR - TMU Monitor High Temperature Average Critical Threshold register */
/*! @{ */

#define TMU_TMHTACTR_TEMP0_MASK                  (0xFFU)
#define TMU_TMHTACTR_TEMP0_SHIFT                 (0U)
#define TMU_TMHTACTR_TEMP0(x)                    (((uint32_t)(((uint32_t)(x)) << TMU_TMHTACTR_TEMP0_SHIFT)) & TMU_TMHTACTR_TEMP0_MASK)

#define TMU_TMHTACTR_TEMP1_MASK                  (0xFF0000U)
#define TMU_TMHTACTR_TEMP1_SHIFT                 (16U)
#define TMU_TMHTACTR_TEMP1(x)                    (((uint32_t)(((uint32_t)(x)) << TMU_TMHTACTR_TEMP1_SHIFT)) & TMU_TMHTACTR_TEMP1_MASK)

#define TMU_TMHTACTR_EN0_MASK                    (0x40000000U)
#define TMU_TMHTACTR_EN0_SHIFT                   (30U)
/*! EN0
 *  0b0..Disabled.
 *  0b1..Threshold enabled.
 */
#define TMU_TMHTACTR_EN0(x)                      (((uint32_t)(((uint32_t)(x)) << TMU_TMHTACTR_EN0_SHIFT)) & TMU_TMHTACTR_EN0_MASK)

#define TMU_TMHTACTR_EN1_MASK                    (0x80000000U)
#define TMU_TMHTACTR_EN1_SHIFT                   (31U)
/*! EN1
 *  0b0..Disabled.
 *  0b1..Threshold enabled.
 */
#define TMU_TMHTACTR_EN1(x)                      (((uint32_t)(((uint32_t)(x)) << TMU_TMHTACTR_EN1_SHIFT)) & TMU_TMHTACTR_EN1_MASK)
/*! @} */

/*! @name TSCR - TMU Sensor Calibration register */
/*! @{ */

#define TMU_TSCR_SNSR0_MASK                      (0xFFFU)
#define TMU_TSCR_SNSR0_SHIFT                     (0U)
#define TMU_TSCR_SNSR0(x)                        (((uint32_t)(((uint32_t)(x)) << TMU_TSCR_SNSR0_SHIFT)) & TMU_TSCR_SNSR0_MASK)

#define TMU_TSCR_SNSR1_MASK                      (0xFFF0000U)
#define TMU_TSCR_SNSR1_SHIFT                     (16U)
#define TMU_TSCR_SNSR1(x)                        (((uint32_t)(((uint32_t)(x)) << TMU_TSCR_SNSR1_SHIFT)) & TMU_TSCR_SNSR1_MASK)

#define TMU_TSCR_V0_MASK                         (0x40000000U)
#define TMU_TSCR_V0_SHIFT                        (30U)
/*! V0
 *  0b0..Not ready. First measurement still pending.
 *  0b1..Ready. Extra 1us delay is needed to read the first [SNSR0] value after this bit is set.
 */
#define TMU_TSCR_V0(x)                           (((uint32_t)(((uint32_t)(x)) << TMU_TSCR_V0_SHIFT)) & TMU_TSCR_V0_MASK)

#define TMU_TSCR_V1_MASK                         (0x80000000U)
#define TMU_TSCR_V1_SHIFT                        (31U)
/*! V1
 *  0b0..Not ready. First measurement still pending.
 *  0b1..Ready. Extra 1us delay is needed to read the first [SNSR1] value after this bit is set.
 */
#define TMU_TSCR_V1(x)                           (((uint32_t)(((uint32_t)(x)) << TMU_TSCR_V1_SHIFT)) & TMU_TSCR_V1_MASK)
/*! @} */

/*! @name TRITSR - TMU Report Immediate Temperature Site register n */
/*! @{ */

#define TMU_TRITSR_TEMP0_MASK                    (0xFFU)
#define TMU_TRITSR_TEMP0_SHIFT                   (0U)
#define TMU_TRITSR_TEMP0(x)                      (((uint32_t)(((uint32_t)(x)) << TMU_TRITSR_TEMP0_SHIFT)) & TMU_TRITSR_TEMP0_MASK)

#define TMU_TRITSR_TEMP1_MASK                    (0xFF0000U)
#define TMU_TRITSR_TEMP1_SHIFT                   (16U)
#define TMU_TRITSR_TEMP1(x)                      (((uint32_t)(((uint32_t)(x)) << TMU_TRITSR_TEMP1_SHIFT)) & TMU_TRITSR_TEMP1_MASK)

#define TMU_TRITSR_V0_MASK                       (0x40000000U)
#define TMU_TRITSR_V0_SHIFT                      (30U)
/*! V0
 *  0b0..Not ready. First measurement still pending.
 *  0b1..Ready. Extra 1us delay is needed to read the first [TEMP0] value after this bit is set.
 */
#define TMU_TRITSR_V0(x)                         (((uint32_t)(((uint32_t)(x)) << TMU_TRITSR_V0_SHIFT)) & TMU_TRITSR_V0_MASK)

#define TMU_TRITSR_V1_MASK                       (0x80000000U)
#define TMU_TRITSR_V1_SHIFT                      (31U)
/*! V1
 *  0b0..Not ready. First measurement still pending.
 *  0b1..Ready. Extra 1us delay is needed to read the first [TEMP1] value after this bit is set.
 */
#define TMU_TRITSR_V1(x)                         (((uint32_t)(((uint32_t)(x)) << TMU_TRITSR_V1_SHIFT)) & TMU_TRITSR_V1_MASK)
/*! @} */

/*! @name TRATSR - TMU Report Average Temperature Site register n */
/*! @{ */

#define TMU_TRATSR_TEMP0_MASK                    (0xFFU)
#define TMU_TRATSR_TEMP0_SHIFT                   (0U)
#define TMU_TRATSR_TEMP0(x)                      (((uint32_t)(((uint32_t)(x)) << TMU_TRATSR_TEMP0_SHIFT)) & TMU_TRATSR_TEMP0_MASK)

#define TMU_TRATSR_TEMP1_MASK                    (0xFF0000U)
#define TMU_TRATSR_TEMP1_SHIFT                   (16U)
#define TMU_TRATSR_TEMP1(x)                      (((uint32_t)(((uint32_t)(x)) << TMU_TRATSR_TEMP1_SHIFT)) & TMU_TRATSR_TEMP1_MASK)

#define TMU_TRATSR_V0_MASK                       (0x40000000U)
#define TMU_TRATSR_V0_SHIFT                      (30U)
/*! V0
 *  0b0..Not ready. First measurement still pending.
 *  0b1..Ready. Extra 1us delay is needed to read the first [TEMP0] value after this bit is set.
 */
#define TMU_TRATSR_V0(x)                         (((uint32_t)(((uint32_t)(x)) << TMU_TRATSR_V0_SHIFT)) & TMU_TRATSR_V0_MASK)

#define TMU_TRATSR_V1_MASK                       (0x80000000U)
#define TMU_TRATSR_V1_SHIFT                      (31U)
/*! V1
 *  0b0..Not ready. First measurement still pending.
 *  0b1..Ready. Extra 1us delay is needed to read the first [TEMP1] value after this bit is set.
 */
#define TMU_TRATSR_V1(x)                         (((uint32_t)(((uint32_t)(x)) << TMU_TRATSR_V1_SHIFT)) & TMU_TRATSR_V1_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group TMU_Register_Masks */


/*!
 * @}
 */ /* end of group TMU_Peripheral_Access_Layer */


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


#endif  /* PERI_TMU_H_ */

