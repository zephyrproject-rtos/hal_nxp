/*
** ###################################################################
**     Processors:          MIMX8UD3CVP08_ca35
**                          MIMX8UD3CVP08_cm33
**                          MIMX8UD3CVP08_dsp0
**                          MIMX8UD3CVP08_dsp1
**                          MIMX8UD3DVK08_ca35
**                          MIMX8UD3DVK08_cm33
**                          MIMX8UD3DVK08_dsp0
**                          MIMX8UD3DVK08_dsp1
**                          MIMX8UD3DVP08_ca35
**                          MIMX8UD3DVP08_cm33
**                          MIMX8UD3DVP08_dsp0
**                          MIMX8UD3DVP08_dsp1
**                          MIMX8UD5CVP08_ca35
**                          MIMX8UD5CVP08_cm33
**                          MIMX8UD5CVP08_dsp0
**                          MIMX8UD5CVP08_dsp1
**                          MIMX8UD5DVK08_ca35
**                          MIMX8UD5DVK08_cm33
**                          MIMX8UD5DVK08_dsp0
**                          MIMX8UD5DVK08_dsp1
**                          MIMX8UD5DVP08_ca35
**                          MIMX8UD5DVP08_cm33
**                          MIMX8UD5DVP08_dsp0
**                          MIMX8UD5DVP08_dsp1
**                          MIMX8UD7CVP08_ca35
**                          MIMX8UD7CVP08_cm33
**                          MIMX8UD7CVP08_dsp0
**                          MIMX8UD7CVP08_dsp1
**                          MIMX8UD7DVK08_ca35
**                          MIMX8UD7DVK08_cm33
**                          MIMX8UD7DVK08_dsp0
**                          MIMX8UD7DVK08_dsp1
**                          MIMX8UD7DVP08_ca35
**                          MIMX8UD7DVP08_cm33
**                          MIMX8UD7DVP08_dsp0
**                          MIMX8UD7DVP08_dsp1
**                          MIMX8US3CVP08_ca35
**                          MIMX8US3CVP08_cm33
**                          MIMX8US3CVP08_dsp0
**                          MIMX8US3CVP08_dsp1
**                          MIMX8US3DVK08_ca35
**                          MIMX8US3DVK08_cm33
**                          MIMX8US3DVK08_dsp0
**                          MIMX8US3DVK08_dsp1
**                          MIMX8US3DVP08_ca35
**                          MIMX8US3DVP08_cm33
**                          MIMX8US3DVP08_dsp0
**                          MIMX8US3DVP08_dsp1
**                          MIMX8US5CVP08_ca35
**                          MIMX8US5CVP08_cm33
**                          MIMX8US5CVP08_dsp0
**                          MIMX8US5CVP08_dsp1
**                          MIMX8US5DVK08_ca35
**                          MIMX8US5DVK08_cm33
**                          MIMX8US5DVK08_dsp0
**                          MIMX8US5DVK08_dsp1
**                          MIMX8US5DVP08_ca35
**                          MIMX8US5DVP08_cm33
**                          MIMX8US5DVP08_dsp0
**                          MIMX8US5DVP08_dsp1
**
**     Version:             rev. 6.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for WUU
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2020-05-25)
**         Initial version.
**     - rev. 2.0 (2020-09-18)
**         Base on rev A RM
**     - rev. 3.0 (2021-01-20)
**         Base on rev A.1 RM
**     - rev. 4.0 (2021-07-05)
**         Base on rev B RM
**     - rev. 5.0 (2023-04-27)
**         Base on rev D RM
**     - rev. 6.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_WUU.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for WUU
 *
 * CMSIS Peripheral Access Layer for WUU
 */

#if !defined(PERI_WUU_H_)
#define PERI_WUU_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8UD3CVP08_ca35) || defined(CPU_MIMX8UD3DVK08_ca35) || defined(CPU_MIMX8UD3DVP08_ca35))
#include "MIMX8UD3_ca35_COMMON.h"
#elif (defined(CPU_MIMX8UD3CVP08_cm33) || defined(CPU_MIMX8UD3DVK08_cm33) || defined(CPU_MIMX8UD3DVP08_cm33))
#include "MIMX8UD3_cm33_COMMON.h"
#elif (defined(CPU_MIMX8UD3CVP08_dsp0) || defined(CPU_MIMX8UD3DVK08_dsp0) || defined(CPU_MIMX8UD3DVP08_dsp0))
#include "MIMX8UD3_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8UD3CVP08_dsp1) || defined(CPU_MIMX8UD3DVK08_dsp1) || defined(CPU_MIMX8UD3DVP08_dsp1))
#include "MIMX8UD3_dsp1_COMMON.h"
#elif (defined(CPU_MIMX8UD5CVP08_ca35) || defined(CPU_MIMX8UD5DVK08_ca35) || defined(CPU_MIMX8UD5DVP08_ca35))
#include "MIMX8UD5_ca35_COMMON.h"
#elif (defined(CPU_MIMX8UD5CVP08_cm33) || defined(CPU_MIMX8UD5DVK08_cm33) || defined(CPU_MIMX8UD5DVP08_cm33))
#include "MIMX8UD5_cm33_COMMON.h"
#elif (defined(CPU_MIMX8UD5CVP08_dsp0) || defined(CPU_MIMX8UD5DVK08_dsp0) || defined(CPU_MIMX8UD5DVP08_dsp0))
#include "MIMX8UD5_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8UD5CVP08_dsp1) || defined(CPU_MIMX8UD5DVK08_dsp1) || defined(CPU_MIMX8UD5DVP08_dsp1))
#include "MIMX8UD5_dsp1_COMMON.h"
#elif (defined(CPU_MIMX8UD7CVP08_ca35) || defined(CPU_MIMX8UD7DVK08_ca35) || defined(CPU_MIMX8UD7DVP08_ca35))
#include "MIMX8UD7_ca35_COMMON.h"
#elif (defined(CPU_MIMX8UD7CVP08_cm33) || defined(CPU_MIMX8UD7DVK08_cm33) || defined(CPU_MIMX8UD7DVP08_cm33))
#include "MIMX8UD7_cm33_COMMON.h"
#elif (defined(CPU_MIMX8UD7CVP08_dsp0) || defined(CPU_MIMX8UD7DVK08_dsp0) || defined(CPU_MIMX8UD7DVP08_dsp0))
#include "MIMX8UD7_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8UD7CVP08_dsp1) || defined(CPU_MIMX8UD7DVK08_dsp1) || defined(CPU_MIMX8UD7DVP08_dsp1))
#include "MIMX8UD7_dsp1_COMMON.h"
#elif (defined(CPU_MIMX8US3CVP08_ca35) || defined(CPU_MIMX8US3DVK08_ca35) || defined(CPU_MIMX8US3DVP08_ca35))
#include "MIMX8US3_ca35_COMMON.h"
#elif (defined(CPU_MIMX8US3CVP08_cm33) || defined(CPU_MIMX8US3DVK08_cm33) || defined(CPU_MIMX8US3DVP08_cm33))
#include "MIMX8US3_cm33_COMMON.h"
#elif (defined(CPU_MIMX8US3CVP08_dsp0) || defined(CPU_MIMX8US3DVK08_dsp0) || defined(CPU_MIMX8US3DVP08_dsp0))
#include "MIMX8US3_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8US3CVP08_dsp1) || defined(CPU_MIMX8US3DVK08_dsp1) || defined(CPU_MIMX8US3DVP08_dsp1))
#include "MIMX8US3_dsp1_COMMON.h"
#elif (defined(CPU_MIMX8US5CVP08_ca35) || defined(CPU_MIMX8US5DVK08_ca35) || defined(CPU_MIMX8US5DVP08_ca35))
#include "MIMX8US5_ca35_COMMON.h"
#elif (defined(CPU_MIMX8US5CVP08_cm33) || defined(CPU_MIMX8US5DVK08_cm33) || defined(CPU_MIMX8US5DVP08_cm33))
#include "MIMX8US5_cm33_COMMON.h"
#elif (defined(CPU_MIMX8US5CVP08_dsp0) || defined(CPU_MIMX8US5DVK08_dsp0) || defined(CPU_MIMX8US5DVP08_dsp0))
#include "MIMX8US5_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8US5CVP08_dsp1) || defined(CPU_MIMX8US5DVK08_dsp1) || defined(CPU_MIMX8US5DVP08_dsp1))
#include "MIMX8US5_dsp1_COMMON.h"
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
   -- WUU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup WUU_Peripheral_Access_Layer WUU Peripheral Access Layer
 * @{
 */

/** WUU - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< Version ID, offset: 0x0 */
  __I  uint32_t PARAM;                             /**< Parameter, offset: 0x4 */
  __IO uint32_t PE1;                               /**< Pin Enable 1, offset: 0x8 */
  __IO uint32_t PE2;                               /**< Pin Enable 2, offset: 0xC */
       uint8_t RESERVED_0[8];
  __IO uint32_t ME;                                /**< Module Interrupt Enable, offset: 0x18 */
  __IO uint32_t DE;                                /**< Module DMA/Trigger Enable, offset: 0x1C */
  __IO uint32_t PF;                                /**< Pin Flag, offset: 0x20 */
       uint8_t RESERVED_1[4];
  __I  uint32_t MF;                                /**< Module Interrupt Flag, offset: 0x28 */
       uint8_t RESERVED_2[4];
  __IO uint32_t FILT;                              /**< Pin Filter, offset: 0x30 */
       uint8_t RESERVED_3[4];
  __IO uint32_t PDC1;                              /**< Pin DMA/Trigger Configuration 1, offset: 0x38 */
  __IO uint32_t PDC2;                              /**< Pin DMA/Trigger Configuration 2, offset: 0x3C */
       uint8_t RESERVED_4[8];
  __IO uint32_t FDC;                               /**< Pin Filter DMA/Trigger Configuration, offset: 0x48 */
       uint8_t RESERVED_5[4];
  __IO uint32_t PMC;                               /**< Pin Mode Configuration, offset: 0x50 */
       uint8_t RESERVED_6[4];
  __IO uint32_t FMC;                               /**< Pin Filter Mode Configuration, offset: 0x58 */
} WUU_Type;

/* ----------------------------------------------------------------------------
   -- WUU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup WUU_Register_Masks WUU Register Masks
 * @{
 */

/*! @name VERID - Version ID */
/*! @{ */

#define WUU_VERID_FEATURE_MASK                   (0xFFFFU)
#define WUU_VERID_FEATURE_SHIFT                  (0U)
/*! FEATURE - Feature Specification Number
 *  0b0000000000000000..Standard features implemented
 *  0b0000000000000001..Support for DMA/Trigger generation from wake-up pins and filters enabled. Support for
 *                      external pin/filter detection during all power modes enabled.
 */
#define WUU_VERID_FEATURE(x)                     (((uint32_t)(((uint32_t)(x)) << WUU_VERID_FEATURE_SHIFT)) & WUU_VERID_FEATURE_MASK)

#define WUU_VERID_MINOR_MASK                     (0xFF0000U)
#define WUU_VERID_MINOR_SHIFT                    (16U)
/*! MINOR - Minor Version Number */
#define WUU_VERID_MINOR(x)                       (((uint32_t)(((uint32_t)(x)) << WUU_VERID_MINOR_SHIFT)) & WUU_VERID_MINOR_MASK)

#define WUU_VERID_MAJOR_MASK                     (0xFF000000U)
#define WUU_VERID_MAJOR_SHIFT                    (24U)
/*! MAJOR - Major Version Number */
#define WUU_VERID_MAJOR(x)                       (((uint32_t)(((uint32_t)(x)) << WUU_VERID_MAJOR_SHIFT)) & WUU_VERID_MAJOR_MASK)
/*! @} */

/*! @name PARAM - Parameter */
/*! @{ */

#define WUU_PARAM_FILTERS_MASK                   (0xFFU)
#define WUU_PARAM_FILTERS_SHIFT                  (0U)
/*! FILTERS - Filter Number */
#define WUU_PARAM_FILTERS(x)                     (((uint32_t)(((uint32_t)(x)) << WUU_PARAM_FILTERS_SHIFT)) & WUU_PARAM_FILTERS_MASK)

#define WUU_PARAM_DMAS_MASK                      (0xFF00U)
#define WUU_PARAM_DMAS_SHIFT                     (8U)
/*! DMAS - DMA Number */
#define WUU_PARAM_DMAS(x)                        (((uint32_t)(((uint32_t)(x)) << WUU_PARAM_DMAS_SHIFT)) & WUU_PARAM_DMAS_MASK)

#define WUU_PARAM_MODULES_MASK                   (0xFF0000U)
#define WUU_PARAM_MODULES_SHIFT                  (16U)
/*! MODULES - Module Number */
#define WUU_PARAM_MODULES(x)                     (((uint32_t)(((uint32_t)(x)) << WUU_PARAM_MODULES_SHIFT)) & WUU_PARAM_MODULES_MASK)

#define WUU_PARAM_PINS_MASK                      (0xFF000000U)
#define WUU_PARAM_PINS_SHIFT                     (24U)
/*! PINS - Pin Number */
#define WUU_PARAM_PINS(x)                        (((uint32_t)(((uint32_t)(x)) << WUU_PARAM_PINS_SHIFT)) & WUU_PARAM_PINS_MASK)
/*! @} */

/*! @name PE1 - Pin Enable 1 */
/*! @{ */

#define WUU_PE1_WUPE0_MASK                       (0x3U)
#define WUU_PE1_WUPE0_SHIFT                      (0U)
/*! WUPE0 - Wake-up Pin Enable for WUU_Pn
 *  0b00..Disable
 *  0b01..Enable (detect on rising edge or high level)
 *  0b10..Enable (detect on falling edge or low level)
 *  0b11..Enable (detect on any edge)
 */
#define WUU_PE1_WUPE0(x)                         (((uint32_t)(((uint32_t)(x)) << WUU_PE1_WUPE0_SHIFT)) & WUU_PE1_WUPE0_MASK)

#define WUU_PE1_WUPE1_MASK                       (0xCU)
#define WUU_PE1_WUPE1_SHIFT                      (2U)
/*! WUPE1 - Wake-up Pin Enable for WUU_Pn
 *  0b00..Disable
 *  0b01..Enable (detect on rising edge or high level)
 *  0b10..Enable (detect on falling edge or low level)
 *  0b11..Enable (detect on any edge)
 */
#define WUU_PE1_WUPE1(x)                         (((uint32_t)(((uint32_t)(x)) << WUU_PE1_WUPE1_SHIFT)) & WUU_PE1_WUPE1_MASK)

#define WUU_PE1_WUPE2_MASK                       (0x30U)
#define WUU_PE1_WUPE2_SHIFT                      (4U)
/*! WUPE2 - Wake-up Pin Enable for WUU_Pn
 *  0b00..Disable
 *  0b01..Enable (detect on rising edge or high level)
 *  0b10..Enable (detect on falling edge or low level)
 *  0b11..Enable (detect on any edge)
 */
#define WUU_PE1_WUPE2(x)                         (((uint32_t)(((uint32_t)(x)) << WUU_PE1_WUPE2_SHIFT)) & WUU_PE1_WUPE2_MASK)

#define WUU_PE1_WUPE3_MASK                       (0xC0U)
#define WUU_PE1_WUPE3_SHIFT                      (6U)
/*! WUPE3 - Wake-up Pin Enable for WUU_Pn
 *  0b00..Disable
 *  0b01..Enable (detect on rising edge or high level)
 *  0b10..Enable (detect on falling edge or low level)
 *  0b11..Enable (detect on any edge)
 */
#define WUU_PE1_WUPE3(x)                         (((uint32_t)(((uint32_t)(x)) << WUU_PE1_WUPE3_SHIFT)) & WUU_PE1_WUPE3_MASK)

#define WUU_PE1_WUPE4_MASK                       (0x300U)
#define WUU_PE1_WUPE4_SHIFT                      (8U)
/*! WUPE4 - Wake-up Pin Enable for WUU_Pn
 *  0b00..Disable
 *  0b01..Enable (detect on rising edge or high level)
 *  0b10..Enable (detect on falling edge or low level)
 *  0b11..Enable (detect on any edge)
 */
#define WUU_PE1_WUPE4(x)                         (((uint32_t)(((uint32_t)(x)) << WUU_PE1_WUPE4_SHIFT)) & WUU_PE1_WUPE4_MASK)

#define WUU_PE1_WUPE5_MASK                       (0xC00U)
#define WUU_PE1_WUPE5_SHIFT                      (10U)
/*! WUPE5 - Wake-up Pin Enable for WUU_Pn
 *  0b00..Disable
 *  0b01..Enable (detect on rising edge or high level)
 *  0b10..Enable (detect on falling edge or low level)
 *  0b11..Enable (detect on any edge)
 */
#define WUU_PE1_WUPE5(x)                         (((uint32_t)(((uint32_t)(x)) << WUU_PE1_WUPE5_SHIFT)) & WUU_PE1_WUPE5_MASK)

#define WUU_PE1_WUPE6_MASK                       (0x3000U)
#define WUU_PE1_WUPE6_SHIFT                      (12U)
/*! WUPE6 - Wake-up Pin Enable for WUU_Pn
 *  0b00..Disable
 *  0b01..Enable (detect on rising edge or high level)
 *  0b10..Enable (detect on falling edge or low level)
 *  0b11..Enable (detect on any edge)
 */
#define WUU_PE1_WUPE6(x)                         (((uint32_t)(((uint32_t)(x)) << WUU_PE1_WUPE6_SHIFT)) & WUU_PE1_WUPE6_MASK)

#define WUU_PE1_WUPE7_MASK                       (0xC000U)
#define WUU_PE1_WUPE7_SHIFT                      (14U)
/*! WUPE7 - Wake-up Pin Enable for WUU_Pn
 *  0b00..Disable
 *  0b01..Enable (detect on rising edge or high level)
 *  0b10..Enable (detect on falling edge or low level)
 *  0b11..Enable (detect on any edge)
 */
#define WUU_PE1_WUPE7(x)                         (((uint32_t)(((uint32_t)(x)) << WUU_PE1_WUPE7_SHIFT)) & WUU_PE1_WUPE7_MASK)

#define WUU_PE1_WUPE8_MASK                       (0x30000U)
#define WUU_PE1_WUPE8_SHIFT                      (16U)
/*! WUPE8 - Wake-up Pin Enable for WUU_Pn
 *  0b00..Disable
 *  0b01..Enable (detect on rising edge or high level)
 *  0b10..Enable (detect on falling edge or low level)
 *  0b11..Enable (detect on any edge)
 */
#define WUU_PE1_WUPE8(x)                         (((uint32_t)(((uint32_t)(x)) << WUU_PE1_WUPE8_SHIFT)) & WUU_PE1_WUPE8_MASK)

#define WUU_PE1_WUPE9_MASK                       (0xC0000U)
#define WUU_PE1_WUPE9_SHIFT                      (18U)
/*! WUPE9 - Wake-up Pin Enable for WUU_Pn
 *  0b00..Disable
 *  0b01..Enable (detect on rising edge or high level)
 *  0b10..Enable (detect on falling edge or low level)
 *  0b11..Enable (detect on any edge)
 */
#define WUU_PE1_WUPE9(x)                         (((uint32_t)(((uint32_t)(x)) << WUU_PE1_WUPE9_SHIFT)) & WUU_PE1_WUPE9_MASK)

#define WUU_PE1_WUPE10_MASK                      (0x300000U)
#define WUU_PE1_WUPE10_SHIFT                     (20U)
/*! WUPE10 - Wake-up Pin Enable for WUU_Pn
 *  0b00..Disable
 *  0b01..Enable (detect on rising edge or high level)
 *  0b10..Enable (detect on falling edge or low level)
 *  0b11..Enable (detect on any edge)
 */
#define WUU_PE1_WUPE10(x)                        (((uint32_t)(((uint32_t)(x)) << WUU_PE1_WUPE10_SHIFT)) & WUU_PE1_WUPE10_MASK)

#define WUU_PE1_WUPE11_MASK                      (0xC00000U)
#define WUU_PE1_WUPE11_SHIFT                     (22U)
/*! WUPE11 - Wake-up Pin Enable for WUU_Pn
 *  0b00..Disable
 *  0b01..Enable (detect on rising edge or high level)
 *  0b10..Enable (detect on falling edge or low level)
 *  0b11..Enable (detect on any edge)
 */
#define WUU_PE1_WUPE11(x)                        (((uint32_t)(((uint32_t)(x)) << WUU_PE1_WUPE11_SHIFT)) & WUU_PE1_WUPE11_MASK)

#define WUU_PE1_WUPE12_MASK                      (0x3000000U)
#define WUU_PE1_WUPE12_SHIFT                     (24U)
/*! WUPE12 - Wake-up Pin Enable for WUU_Pn
 *  0b00..Disable
 *  0b01..Enable (detect on rising edge or high level)
 *  0b10..Enable (detect on falling edge or low level)
 *  0b11..Enable (detect on any edge)
 */
#define WUU_PE1_WUPE12(x)                        (((uint32_t)(((uint32_t)(x)) << WUU_PE1_WUPE12_SHIFT)) & WUU_PE1_WUPE12_MASK)

#define WUU_PE1_WUPE13_MASK                      (0xC000000U)
#define WUU_PE1_WUPE13_SHIFT                     (26U)
/*! WUPE13 - Wake-up Pin Enable for WUU_Pn
 *  0b00..Disable
 *  0b01..Enable (detect on rising edge or high level)
 *  0b10..Enable (detect on falling edge or low level)
 *  0b11..Enable (detect on any edge)
 */
#define WUU_PE1_WUPE13(x)                        (((uint32_t)(((uint32_t)(x)) << WUU_PE1_WUPE13_SHIFT)) & WUU_PE1_WUPE13_MASK)

#define WUU_PE1_WUPE14_MASK                      (0x30000000U)
#define WUU_PE1_WUPE14_SHIFT                     (28U)
/*! WUPE14 - Wake-up Pin Enable for WUU_Pn
 *  0b00..Disable
 *  0b01..Enable (detect on rising edge or high level)
 *  0b10..Enable (detect on falling edge or low level)
 *  0b11..Enable (detect on any edge)
 */
#define WUU_PE1_WUPE14(x)                        (((uint32_t)(((uint32_t)(x)) << WUU_PE1_WUPE14_SHIFT)) & WUU_PE1_WUPE14_MASK)

#define WUU_PE1_WUPE15_MASK                      (0xC0000000U)
#define WUU_PE1_WUPE15_SHIFT                     (30U)
/*! WUPE15 - Wake-up Pin Enable for WUU_Pn
 *  0b00..Disable
 *  0b01..Enable (detect on rising edge or high level)
 *  0b10..Enable (detect on falling edge or low level)
 *  0b11..Enable (detect on any edge)
 */
#define WUU_PE1_WUPE15(x)                        (((uint32_t)(((uint32_t)(x)) << WUU_PE1_WUPE15_SHIFT)) & WUU_PE1_WUPE15_MASK)
/*! @} */

/*! @name PE2 - Pin Enable 2 */
/*! @{ */

#define WUU_PE2_Reserved16_MASK                  (0x3U)
#define WUU_PE2_Reserved16_SHIFT                 (0U)
/*! Reserved16 - Reserved
 *  0b00..Not supported
 *  0b01..Not supported
 *  0b10..Not supported
 *  0b11..Not supported
 */
#define WUU_PE2_Reserved16(x)                    (((uint32_t)(((uint32_t)(x)) << WUU_PE2_Reserved16_SHIFT)) & WUU_PE2_Reserved16_MASK)

#define WUU_PE2_WUPE16_MASK                      (0x3U)
#define WUU_PE2_WUPE16_SHIFT                     (0U)
/*! WUPE16 - Wake-up Pin Enable for WUU_Pn
 *  0b00..Disable
 *  0b01..Enable (detect on rising edge or high level)
 *  0b10..Enable (detect on falling edge or low level)
 *  0b11..Enable (detect on any edge)
 */
#define WUU_PE2_WUPE16(x)                        (((uint32_t)(((uint32_t)(x)) << WUU_PE2_WUPE16_SHIFT)) & WUU_PE2_WUPE16_MASK)

#define WUU_PE2_Reserved17_MASK                  (0xCU)
#define WUU_PE2_Reserved17_SHIFT                 (2U)
/*! Reserved17 - Reserved
 *  0b00..Not supported
 *  0b01..Not supported
 *  0b10..Not supported
 *  0b11..Not supported
 */
#define WUU_PE2_Reserved17(x)                    (((uint32_t)(((uint32_t)(x)) << WUU_PE2_Reserved17_SHIFT)) & WUU_PE2_Reserved17_MASK)

#define WUU_PE2_WUPE17_MASK                      (0xCU)
#define WUU_PE2_WUPE17_SHIFT                     (2U)
/*! WUPE17 - Wake-up Pin Enable for WUU_Pn
 *  0b00..Disable
 *  0b01..Enable (detect on rising edge or high level)
 *  0b10..Enable (detect on falling edge or low level)
 *  0b11..Enable (detect on any edge)
 */
#define WUU_PE2_WUPE17(x)                        (((uint32_t)(((uint32_t)(x)) << WUU_PE2_WUPE17_SHIFT)) & WUU_PE2_WUPE17_MASK)

#define WUU_PE2_Reserved18_MASK                  (0x30U)
#define WUU_PE2_Reserved18_SHIFT                 (4U)
/*! Reserved18 - Reserved
 *  0b00..Not supported
 *  0b01..Not supported
 *  0b10..Not supported
 *  0b11..Not supported
 */
#define WUU_PE2_Reserved18(x)                    (((uint32_t)(((uint32_t)(x)) << WUU_PE2_Reserved18_SHIFT)) & WUU_PE2_Reserved18_MASK)

#define WUU_PE2_WUPE18_MASK                      (0x30U)
#define WUU_PE2_WUPE18_SHIFT                     (4U)
/*! WUPE18 - Wake-up Pin Enable for WUU_Pn
 *  0b00..Disable
 *  0b01..Enable (detect on rising edge or high level)
 *  0b10..Enable (detect on falling edge or low level)
 *  0b11..Enable (detect on any edge)
 */
#define WUU_PE2_WUPE18(x)                        (((uint32_t)(((uint32_t)(x)) << WUU_PE2_WUPE18_SHIFT)) & WUU_PE2_WUPE18_MASK)

#define WUU_PE2_Reserved19_MASK                  (0xC0U)
#define WUU_PE2_Reserved19_SHIFT                 (6U)
/*! Reserved19 - Reserved
 *  0b00..Not supported
 *  0b01..Not supported
 *  0b10..Not supported
 *  0b11..Not supported
 */
#define WUU_PE2_Reserved19(x)                    (((uint32_t)(((uint32_t)(x)) << WUU_PE2_Reserved19_SHIFT)) & WUU_PE2_Reserved19_MASK)

#define WUU_PE2_WUPE19_MASK                      (0xC0U)
#define WUU_PE2_WUPE19_SHIFT                     (6U)
/*! WUPE19 - Wake-up Pin Enable for WUU_Pn
 *  0b00..Disable
 *  0b01..Enable (detect on rising edge or high level)
 *  0b10..Enable (detect on falling edge or low level)
 *  0b11..Enable (detect on any edge)
 */
#define WUU_PE2_WUPE19(x)                        (((uint32_t)(((uint32_t)(x)) << WUU_PE2_WUPE19_SHIFT)) & WUU_PE2_WUPE19_MASK)

#define WUU_PE2_Reserved20_MASK                  (0x300U)
#define WUU_PE2_Reserved20_SHIFT                 (8U)
/*! Reserved20 - Reserved
 *  0b00..Not supported
 *  0b01..Not supported
 *  0b10..Not supported
 *  0b11..Not supported
 */
#define WUU_PE2_Reserved20(x)                    (((uint32_t)(((uint32_t)(x)) << WUU_PE2_Reserved20_SHIFT)) & WUU_PE2_Reserved20_MASK)

#define WUU_PE2_WUPE20_MASK                      (0x300U)
#define WUU_PE2_WUPE20_SHIFT                     (8U)
/*! WUPE20 - Wake-up Pin Enable for WUU_Pn
 *  0b00..Disable
 *  0b01..Enable (detect on rising edge or high level)
 *  0b10..Enable (detect on falling edge or low level)
 *  0b11..Enable (detect on any edge)
 */
#define WUU_PE2_WUPE20(x)                        (((uint32_t)(((uint32_t)(x)) << WUU_PE2_WUPE20_SHIFT)) & WUU_PE2_WUPE20_MASK)

#define WUU_PE2_Reserved21_MASK                  (0xC00U)
#define WUU_PE2_Reserved21_SHIFT                 (10U)
/*! Reserved21 - Reserved
 *  0b00..Not supported
 *  0b01..Not supported
 *  0b10..Not supported
 *  0b11..Not supported
 */
#define WUU_PE2_Reserved21(x)                    (((uint32_t)(((uint32_t)(x)) << WUU_PE2_Reserved21_SHIFT)) & WUU_PE2_Reserved21_MASK)

#define WUU_PE2_WUPE21_MASK                      (0xC00U)
#define WUU_PE2_WUPE21_SHIFT                     (10U)
/*! WUPE21 - Wake-up Pin Enable for WUU_Pn
 *  0b00..Disable
 *  0b01..Enable (detect on rising edge or high level)
 *  0b10..Enable (detect on falling edge or low level)
 *  0b11..Enable (detect on any edge)
 */
#define WUU_PE2_WUPE21(x)                        (((uint32_t)(((uint32_t)(x)) << WUU_PE2_WUPE21_SHIFT)) & WUU_PE2_WUPE21_MASK)

#define WUU_PE2_Reserved22_MASK                  (0x3000U)
#define WUU_PE2_Reserved22_SHIFT                 (12U)
/*! Reserved22 - Reserved
 *  0b00..Not supported
 *  0b01..Not supported
 *  0b10..Not supported
 *  0b11..Not supported
 */
#define WUU_PE2_Reserved22(x)                    (((uint32_t)(((uint32_t)(x)) << WUU_PE2_Reserved22_SHIFT)) & WUU_PE2_Reserved22_MASK)

#define WUU_PE2_WUPE22_MASK                      (0x3000U)
#define WUU_PE2_WUPE22_SHIFT                     (12U)
/*! WUPE22 - Wake-up Pin Enable for WUU_Pn
 *  0b00..Disable
 *  0b01..Enable (detect on rising edge or high level)
 *  0b10..Enable (detect on falling edge or low level)
 *  0b11..Enable (detect on any edge)
 */
#define WUU_PE2_WUPE22(x)                        (((uint32_t)(((uint32_t)(x)) << WUU_PE2_WUPE22_SHIFT)) & WUU_PE2_WUPE22_MASK)

#define WUU_PE2_Reserved23_MASK                  (0xC000U)
#define WUU_PE2_Reserved23_SHIFT                 (14U)
/*! Reserved23 - Reserved
 *  0b00..Not supported
 *  0b01..Not supported
 *  0b10..Not supported
 *  0b11..Not supported
 */
#define WUU_PE2_Reserved23(x)                    (((uint32_t)(((uint32_t)(x)) << WUU_PE2_Reserved23_SHIFT)) & WUU_PE2_Reserved23_MASK)

#define WUU_PE2_WUPE23_MASK                      (0xC000U)
#define WUU_PE2_WUPE23_SHIFT                     (14U)
/*! WUPE23 - Wake-up Pin Enable for WUU_Pn
 *  0b00..Disable
 *  0b01..Enable (detect on rising edge or high level)
 *  0b10..Enable (detect on falling edge or low level)
 *  0b11..Enable (detect on any edge)
 */
#define WUU_PE2_WUPE23(x)                        (((uint32_t)(((uint32_t)(x)) << WUU_PE2_WUPE23_SHIFT)) & WUU_PE2_WUPE23_MASK)

#define WUU_PE2_Reserved24_MASK                  (0x30000U)
#define WUU_PE2_Reserved24_SHIFT                 (16U)
/*! Reserved24 - Reserved
 *  0b00..Not supported
 *  0b01..Not supported
 *  0b10..Not supported
 *  0b11..Not supported
 */
#define WUU_PE2_Reserved24(x)                    (((uint32_t)(((uint32_t)(x)) << WUU_PE2_Reserved24_SHIFT)) & WUU_PE2_Reserved24_MASK)

#define WUU_PE2_WUPE24_MASK                      (0x30000U)
#define WUU_PE2_WUPE24_SHIFT                     (16U)
/*! WUPE24 - Wake-up Pin Enable for WUU_Pn
 *  0b00..Disable
 *  0b01..Enable (detect on rising edge or high level)
 *  0b10..Enable (detect on falling edge or low level)
 *  0b11..Enable (detect on any edge)
 */
#define WUU_PE2_WUPE24(x)                        (((uint32_t)(((uint32_t)(x)) << WUU_PE2_WUPE24_SHIFT)) & WUU_PE2_WUPE24_MASK)

#define WUU_PE2_Reserved25_MASK                  (0xC0000U)
#define WUU_PE2_Reserved25_SHIFT                 (18U)
/*! Reserved25 - Reserved
 *  0b00..Not supported
 *  0b01..Not supported
 *  0b10..Not supported
 *  0b11..Not supported
 */
#define WUU_PE2_Reserved25(x)                    (((uint32_t)(((uint32_t)(x)) << WUU_PE2_Reserved25_SHIFT)) & WUU_PE2_Reserved25_MASK)

#define WUU_PE2_WUPE25_MASK                      (0xC0000U)
#define WUU_PE2_WUPE25_SHIFT                     (18U)
/*! WUPE25 - Wake-up Pin Enable for WUU_Pn
 *  0b00..Disable
 *  0b01..Enable (detect on rising edge or high level)
 *  0b10..Enable (detect on falling edge or low level)
 *  0b11..Enable (detect on any edge)
 */
#define WUU_PE2_WUPE25(x)                        (((uint32_t)(((uint32_t)(x)) << WUU_PE2_WUPE25_SHIFT)) & WUU_PE2_WUPE25_MASK)

#define WUU_PE2_Reserved26_MASK                  (0x300000U)
#define WUU_PE2_Reserved26_SHIFT                 (20U)
/*! Reserved26 - Reserved
 *  0b00..Not supported
 *  0b01..Not supported
 *  0b10..Not supported
 *  0b11..Not supported
 */
#define WUU_PE2_Reserved26(x)                    (((uint32_t)(((uint32_t)(x)) << WUU_PE2_Reserved26_SHIFT)) & WUU_PE2_Reserved26_MASK)

#define WUU_PE2_WUPE26_MASK                      (0x300000U)
#define WUU_PE2_WUPE26_SHIFT                     (20U)
/*! WUPE26 - Wake-up Pin Enable for WUU_Pn
 *  0b00..Disable
 *  0b01..Enable (detect on rising edge or high level)
 *  0b10..Enable (detect on falling edge or low level)
 *  0b11..Enable (detect on any edge)
 */
#define WUU_PE2_WUPE26(x)                        (((uint32_t)(((uint32_t)(x)) << WUU_PE2_WUPE26_SHIFT)) & WUU_PE2_WUPE26_MASK)

#define WUU_PE2_Reserved27_MASK                  (0xC00000U)
#define WUU_PE2_Reserved27_SHIFT                 (22U)
/*! Reserved27 - Reserved
 *  0b00..Not supported
 *  0b01..Not supported
 *  0b10..Not supported
 *  0b11..Not supported
 */
#define WUU_PE2_Reserved27(x)                    (((uint32_t)(((uint32_t)(x)) << WUU_PE2_Reserved27_SHIFT)) & WUU_PE2_Reserved27_MASK)

#define WUU_PE2_WUPE27_MASK                      (0xC00000U)
#define WUU_PE2_WUPE27_SHIFT                     (22U)
/*! WUPE27 - Wake-up Pin Enable for WUU_Pn
 *  0b00..Disable
 *  0b01..Enable (detect on rising edge or high level)
 *  0b10..Enable (detect on falling edge or low level)
 *  0b11..Enable (detect on any edge)
 */
#define WUU_PE2_WUPE27(x)                        (((uint32_t)(((uint32_t)(x)) << WUU_PE2_WUPE27_SHIFT)) & WUU_PE2_WUPE27_MASK)

#define WUU_PE2_Reserved28_MASK                  (0x3000000U)
#define WUU_PE2_Reserved28_SHIFT                 (24U)
/*! Reserved28 - Reserved
 *  0b00..Not supported
 *  0b01..Not supported
 *  0b10..Not supported
 *  0b11..Not supported
 */
#define WUU_PE2_Reserved28(x)                    (((uint32_t)(((uint32_t)(x)) << WUU_PE2_Reserved28_SHIFT)) & WUU_PE2_Reserved28_MASK)

#define WUU_PE2_Reserved29_MASK                  (0xC000000U)
#define WUU_PE2_Reserved29_SHIFT                 (26U)
/*! Reserved29 - Reserved
 *  0b00..Not supported
 *  0b01..Not supported
 *  0b10..Not supported
 *  0b11..Not supported
 */
#define WUU_PE2_Reserved29(x)                    (((uint32_t)(((uint32_t)(x)) << WUU_PE2_Reserved29_SHIFT)) & WUU_PE2_Reserved29_MASK)

#define WUU_PE2_Reserved30_MASK                  (0x30000000U)
#define WUU_PE2_Reserved30_SHIFT                 (28U)
/*! Reserved30 - Reserved
 *  0b00..Not supported
 *  0b01..Not supported
 *  0b10..Not supported
 *  0b11..Not supported
 */
#define WUU_PE2_Reserved30(x)                    (((uint32_t)(((uint32_t)(x)) << WUU_PE2_Reserved30_SHIFT)) & WUU_PE2_Reserved30_MASK)

#define WUU_PE2_Reserved31_MASK                  (0xC0000000U)
#define WUU_PE2_Reserved31_SHIFT                 (30U)
/*! Reserved31 - Reserved
 *  0b00..Not supported
 *  0b01..Not supported
 *  0b10..Not supported
 *  0b11..Not supported
 */
#define WUU_PE2_Reserved31(x)                    (((uint32_t)(((uint32_t)(x)) << WUU_PE2_Reserved31_SHIFT)) & WUU_PE2_Reserved31_MASK)
/*! @} */

/*! @name ME - Module Interrupt Enable */
/*! @{ */

#define WUU_ME_WUME0_MASK                        (0x1U)
#define WUU_ME_WUME0_SHIFT                       (0U)
/*! WUME0 - Module Interrupt Wake-up Enable for Module 0 */
#define WUU_ME_WUME0(x)                          (((uint32_t)(((uint32_t)(x)) << WUU_ME_WUME0_SHIFT)) & WUU_ME_WUME0_MASK)

#define WUU_ME_WUME1_MASK                        (0x2U)
#define WUU_ME_WUME1_SHIFT                       (1U)
/*! WUME1 - Module Interrupt Wake-up Enable for Module 1 */
#define WUU_ME_WUME1(x)                          (((uint32_t)(((uint32_t)(x)) << WUU_ME_WUME1_SHIFT)) & WUU_ME_WUME1_MASK)

#define WUU_ME_WUME2_MASK                        (0x4U)
#define WUU_ME_WUME2_SHIFT                       (2U)
/*! WUME2 - Module Interrupt Wake-up Enable for Module 2 */
#define WUU_ME_WUME2(x)                          (((uint32_t)(((uint32_t)(x)) << WUU_ME_WUME2_SHIFT)) & WUU_ME_WUME2_MASK)

#define WUU_ME_WUME3_MASK                        (0x8U)
#define WUU_ME_WUME3_SHIFT                       (3U)
/*! WUME3 - Module Interrupt Wake-up Enable for Module 3 */
#define WUU_ME_WUME3(x)                          (((uint32_t)(((uint32_t)(x)) << WUU_ME_WUME3_SHIFT)) & WUU_ME_WUME3_MASK)

#define WUU_ME_WUME4_MASK                        (0x10U)
#define WUU_ME_WUME4_SHIFT                       (4U)
/*! WUME4 - Module Interrupt Wake-up Enable for Module 4 */
#define WUU_ME_WUME4(x)                          (((uint32_t)(((uint32_t)(x)) << WUU_ME_WUME4_SHIFT)) & WUU_ME_WUME4_MASK)

#define WUU_ME_WUME5_MASK                        (0x20U)
#define WUU_ME_WUME5_SHIFT                       (5U)
/*! WUME5 - Module Interrupt Wake-up Enable for Module 5 */
#define WUU_ME_WUME5(x)                          (((uint32_t)(((uint32_t)(x)) << WUU_ME_WUME5_SHIFT)) & WUU_ME_WUME5_MASK)

#define WUU_ME_WUME6_MASK                        (0x40U)
#define WUU_ME_WUME6_SHIFT                       (6U)
/*! WUME6 - Module Interrupt Wake-up Enable for Module 6 */
#define WUU_ME_WUME6(x)                          (((uint32_t)(((uint32_t)(x)) << WUU_ME_WUME6_SHIFT)) & WUU_ME_WUME6_MASK)

#define WUU_ME_WUME7_MASK                        (0x80U)
#define WUU_ME_WUME7_SHIFT                       (7U)
/*! WUME7 - Module Interrupt Wake-up Enable for Module 7 */
#define WUU_ME_WUME7(x)                          (((uint32_t)(((uint32_t)(x)) << WUU_ME_WUME7_SHIFT)) & WUU_ME_WUME7_MASK)
/*! @} */

/*! @name DE - Module DMA/Trigger Enable */
/*! @{ */

#define WUU_DE_WUDE0_MASK                        (0x1U)
#define WUU_DE_WUDE0_SHIFT                       (0U)
/*! WUDE0 - DMA/Trigger Wake-up Enable for Module 0 */
#define WUU_DE_WUDE0(x)                          (((uint32_t)(((uint32_t)(x)) << WUU_DE_WUDE0_SHIFT)) & WUU_DE_WUDE0_MASK)

#define WUU_DE_WUDE1_MASK                        (0x2U)
#define WUU_DE_WUDE1_SHIFT                       (1U)
/*! WUDE1 - DMA/Trigger Wake-up Enable for Module 1 */
#define WUU_DE_WUDE1(x)                          (((uint32_t)(((uint32_t)(x)) << WUU_DE_WUDE1_SHIFT)) & WUU_DE_WUDE1_MASK)
/*! @} */

/*! @name PF - Pin Flag */
/*! @{ */

#define WUU_PF_WUF0_MASK                         (0x1U)
#define WUU_PF_WUF0_SHIFT                        (0U)
/*! WUF0 - Wake-up Flag for WUU_Pn
 *  0b0..No
 *  0b1..Yes
 */
#define WUU_PF_WUF0(x)                           (((uint32_t)(((uint32_t)(x)) << WUU_PF_WUF0_SHIFT)) & WUU_PF_WUF0_MASK)

#define WUU_PF_WUF1_MASK                         (0x2U)
#define WUU_PF_WUF1_SHIFT                        (1U)
/*! WUF1 - Wake-up Flag for WUU_Pn
 *  0b0..No
 *  0b1..Yes
 */
#define WUU_PF_WUF1(x)                           (((uint32_t)(((uint32_t)(x)) << WUU_PF_WUF1_SHIFT)) & WUU_PF_WUF1_MASK)

#define WUU_PF_WUF2_MASK                         (0x4U)
#define WUU_PF_WUF2_SHIFT                        (2U)
/*! WUF2 - Wake-up Flag for WUU_Pn
 *  0b0..No
 *  0b1..Yes
 */
#define WUU_PF_WUF2(x)                           (((uint32_t)(((uint32_t)(x)) << WUU_PF_WUF2_SHIFT)) & WUU_PF_WUF2_MASK)

#define WUU_PF_WUF3_MASK                         (0x8U)
#define WUU_PF_WUF3_SHIFT                        (3U)
/*! WUF3 - Wake-up Flag for WUU_Pn
 *  0b0..No
 *  0b1..Yes
 */
#define WUU_PF_WUF3(x)                           (((uint32_t)(((uint32_t)(x)) << WUU_PF_WUF3_SHIFT)) & WUU_PF_WUF3_MASK)

#define WUU_PF_WUF4_MASK                         (0x10U)
#define WUU_PF_WUF4_SHIFT                        (4U)
/*! WUF4 - Wake-up Flag for WUU_Pn
 *  0b0..No
 *  0b1..Yes
 */
#define WUU_PF_WUF4(x)                           (((uint32_t)(((uint32_t)(x)) << WUU_PF_WUF4_SHIFT)) & WUU_PF_WUF4_MASK)

#define WUU_PF_WUF5_MASK                         (0x20U)
#define WUU_PF_WUF5_SHIFT                        (5U)
/*! WUF5 - Wake-up Flag for WUU_Pn
 *  0b0..No
 *  0b1..Yes
 */
#define WUU_PF_WUF5(x)                           (((uint32_t)(((uint32_t)(x)) << WUU_PF_WUF5_SHIFT)) & WUU_PF_WUF5_MASK)

#define WUU_PF_WUF6_MASK                         (0x40U)
#define WUU_PF_WUF6_SHIFT                        (6U)
/*! WUF6 - Wake-up Flag for WUU_Pn
 *  0b0..No
 *  0b1..Yes
 */
#define WUU_PF_WUF6(x)                           (((uint32_t)(((uint32_t)(x)) << WUU_PF_WUF6_SHIFT)) & WUU_PF_WUF6_MASK)

#define WUU_PF_WUF7_MASK                         (0x80U)
#define WUU_PF_WUF7_SHIFT                        (7U)
/*! WUF7 - Wake-up Flag for WUU_Pn
 *  0b0..No
 *  0b1..Yes
 */
#define WUU_PF_WUF7(x)                           (((uint32_t)(((uint32_t)(x)) << WUU_PF_WUF7_SHIFT)) & WUU_PF_WUF7_MASK)

#define WUU_PF_WUF8_MASK                         (0x100U)
#define WUU_PF_WUF8_SHIFT                        (8U)
/*! WUF8 - Wake-up Flag for WUU_Pn
 *  0b0..No
 *  0b1..Yes
 */
#define WUU_PF_WUF8(x)                           (((uint32_t)(((uint32_t)(x)) << WUU_PF_WUF8_SHIFT)) & WUU_PF_WUF8_MASK)

#define WUU_PF_WUF9_MASK                         (0x200U)
#define WUU_PF_WUF9_SHIFT                        (9U)
/*! WUF9 - Wake-up Flag for WUU_Pn
 *  0b0..No
 *  0b1..Yes
 */
#define WUU_PF_WUF9(x)                           (((uint32_t)(((uint32_t)(x)) << WUU_PF_WUF9_SHIFT)) & WUU_PF_WUF9_MASK)

#define WUU_PF_WUF10_MASK                        (0x400U)
#define WUU_PF_WUF10_SHIFT                       (10U)
/*! WUF10 - Wake-up Flag for WUU_Pn
 *  0b0..No
 *  0b1..Yes
 */
#define WUU_PF_WUF10(x)                          (((uint32_t)(((uint32_t)(x)) << WUU_PF_WUF10_SHIFT)) & WUU_PF_WUF10_MASK)

#define WUU_PF_WUF11_MASK                        (0x800U)
#define WUU_PF_WUF11_SHIFT                       (11U)
/*! WUF11 - Wake-up Flag for WUU_Pn
 *  0b0..No
 *  0b1..Yes
 */
#define WUU_PF_WUF11(x)                          (((uint32_t)(((uint32_t)(x)) << WUU_PF_WUF11_SHIFT)) & WUU_PF_WUF11_MASK)

#define WUU_PF_WUF12_MASK                        (0x1000U)
#define WUU_PF_WUF12_SHIFT                       (12U)
/*! WUF12 - Wake-up Flag for WUU_Pn
 *  0b0..No
 *  0b1..Yes
 */
#define WUU_PF_WUF12(x)                          (((uint32_t)(((uint32_t)(x)) << WUU_PF_WUF12_SHIFT)) & WUU_PF_WUF12_MASK)

#define WUU_PF_WUF13_MASK                        (0x2000U)
#define WUU_PF_WUF13_SHIFT                       (13U)
/*! WUF13 - Wake-up Flag for WUU_Pn
 *  0b0..No
 *  0b1..Yes
 */
#define WUU_PF_WUF13(x)                          (((uint32_t)(((uint32_t)(x)) << WUU_PF_WUF13_SHIFT)) & WUU_PF_WUF13_MASK)

#define WUU_PF_WUF14_MASK                        (0x4000U)
#define WUU_PF_WUF14_SHIFT                       (14U)
/*! WUF14 - Wake-up Flag for WUU_Pn
 *  0b0..No
 *  0b1..Yes
 */
#define WUU_PF_WUF14(x)                          (((uint32_t)(((uint32_t)(x)) << WUU_PF_WUF14_SHIFT)) & WUU_PF_WUF14_MASK)

#define WUU_PF_WUF15_MASK                        (0x8000U)
#define WUU_PF_WUF15_SHIFT                       (15U)
/*! WUF15 - Wake-up Flag for WUU_Pn
 *  0b0..No
 *  0b1..Yes
 */
#define WUU_PF_WUF15(x)                          (((uint32_t)(((uint32_t)(x)) << WUU_PF_WUF15_SHIFT)) & WUU_PF_WUF15_MASK)

#define WUU_PF_Reserved16_MASK                   (0x10000U)
#define WUU_PF_Reserved16_SHIFT                  (16U)
/*! Reserved16 - Reserved
 *  0b0..Not supported
 *  0b1..Not supported
 */
#define WUU_PF_Reserved16(x)                     (((uint32_t)(((uint32_t)(x)) << WUU_PF_Reserved16_SHIFT)) & WUU_PF_Reserved16_MASK)

#define WUU_PF_WUF16_MASK                        (0x10000U)
#define WUU_PF_WUF16_SHIFT                       (16U)
/*! WUF16 - Wake-up Flag for WUU_Pn
 *  0b0..No
 *  0b1..Yes
 */
#define WUU_PF_WUF16(x)                          (((uint32_t)(((uint32_t)(x)) << WUU_PF_WUF16_SHIFT)) & WUU_PF_WUF16_MASK)

#define WUU_PF_Reserved17_MASK                   (0x20000U)
#define WUU_PF_Reserved17_SHIFT                  (17U)
/*! Reserved17 - Reserved
 *  0b0..Not supported
 *  0b1..Not supported
 */
#define WUU_PF_Reserved17(x)                     (((uint32_t)(((uint32_t)(x)) << WUU_PF_Reserved17_SHIFT)) & WUU_PF_Reserved17_MASK)

#define WUU_PF_WUF17_MASK                        (0x20000U)
#define WUU_PF_WUF17_SHIFT                       (17U)
/*! WUF17 - Wake-up Flag for WUU_Pn
 *  0b0..No
 *  0b1..Yes
 */
#define WUU_PF_WUF17(x)                          (((uint32_t)(((uint32_t)(x)) << WUU_PF_WUF17_SHIFT)) & WUU_PF_WUF17_MASK)

#define WUU_PF_Reserved18_MASK                   (0x40000U)
#define WUU_PF_Reserved18_SHIFT                  (18U)
/*! Reserved18 - Reserved
 *  0b0..Not supported
 *  0b1..Not supported
 */
#define WUU_PF_Reserved18(x)                     (((uint32_t)(((uint32_t)(x)) << WUU_PF_Reserved18_SHIFT)) & WUU_PF_Reserved18_MASK)

#define WUU_PF_WUF18_MASK                        (0x40000U)
#define WUU_PF_WUF18_SHIFT                       (18U)
/*! WUF18 - Wake-up Flag for WUU_Pn
 *  0b0..No
 *  0b1..Yes
 */
#define WUU_PF_WUF18(x)                          (((uint32_t)(((uint32_t)(x)) << WUU_PF_WUF18_SHIFT)) & WUU_PF_WUF18_MASK)

#define WUU_PF_Reserved19_MASK                   (0x80000U)
#define WUU_PF_Reserved19_SHIFT                  (19U)
/*! Reserved19 - Reserved
 *  0b0..Not supported
 *  0b1..Not supported
 */
#define WUU_PF_Reserved19(x)                     (((uint32_t)(((uint32_t)(x)) << WUU_PF_Reserved19_SHIFT)) & WUU_PF_Reserved19_MASK)

#define WUU_PF_WUF19_MASK                        (0x80000U)
#define WUU_PF_WUF19_SHIFT                       (19U)
/*! WUF19 - Wake-up Flag for WUU_Pn
 *  0b0..No
 *  0b1..Yes
 */
#define WUU_PF_WUF19(x)                          (((uint32_t)(((uint32_t)(x)) << WUU_PF_WUF19_SHIFT)) & WUU_PF_WUF19_MASK)

#define WUU_PF_Reserved20_MASK                   (0x100000U)
#define WUU_PF_Reserved20_SHIFT                  (20U)
/*! Reserved20 - Reserved
 *  0b0..Not supported
 *  0b1..Not supported
 */
#define WUU_PF_Reserved20(x)                     (((uint32_t)(((uint32_t)(x)) << WUU_PF_Reserved20_SHIFT)) & WUU_PF_Reserved20_MASK)

#define WUU_PF_WUF20_MASK                        (0x100000U)
#define WUU_PF_WUF20_SHIFT                       (20U)
/*! WUF20 - Wake-up Flag for WUU_Pn
 *  0b0..No
 *  0b1..Yes
 */
#define WUU_PF_WUF20(x)                          (((uint32_t)(((uint32_t)(x)) << WUU_PF_WUF20_SHIFT)) & WUU_PF_WUF20_MASK)

#define WUU_PF_Reserved21_MASK                   (0x200000U)
#define WUU_PF_Reserved21_SHIFT                  (21U)
/*! Reserved21 - Reserved
 *  0b0..Not supported
 *  0b1..Not supported
 */
#define WUU_PF_Reserved21(x)                     (((uint32_t)(((uint32_t)(x)) << WUU_PF_Reserved21_SHIFT)) & WUU_PF_Reserved21_MASK)

#define WUU_PF_WUF21_MASK                        (0x200000U)
#define WUU_PF_WUF21_SHIFT                       (21U)
/*! WUF21 - Wake-up Flag for WUU_Pn
 *  0b0..No
 *  0b1..Yes
 */
#define WUU_PF_WUF21(x)                          (((uint32_t)(((uint32_t)(x)) << WUU_PF_WUF21_SHIFT)) & WUU_PF_WUF21_MASK)

#define WUU_PF_Reserved22_MASK                   (0x400000U)
#define WUU_PF_Reserved22_SHIFT                  (22U)
/*! Reserved22 - Reserved
 *  0b0..Not supported
 *  0b1..Not supported
 */
#define WUU_PF_Reserved22(x)                     (((uint32_t)(((uint32_t)(x)) << WUU_PF_Reserved22_SHIFT)) & WUU_PF_Reserved22_MASK)

#define WUU_PF_WUF22_MASK                        (0x400000U)
#define WUU_PF_WUF22_SHIFT                       (22U)
/*! WUF22 - Wake-up Flag for WUU_Pn
 *  0b0..No
 *  0b1..Yes
 */
#define WUU_PF_WUF22(x)                          (((uint32_t)(((uint32_t)(x)) << WUU_PF_WUF22_SHIFT)) & WUU_PF_WUF22_MASK)

#define WUU_PF_Reserved23_MASK                   (0x800000U)
#define WUU_PF_Reserved23_SHIFT                  (23U)
/*! Reserved23 - Reserved
 *  0b0..Not supported
 *  0b1..Not supported
 */
#define WUU_PF_Reserved23(x)                     (((uint32_t)(((uint32_t)(x)) << WUU_PF_Reserved23_SHIFT)) & WUU_PF_Reserved23_MASK)

#define WUU_PF_WUF23_MASK                        (0x800000U)
#define WUU_PF_WUF23_SHIFT                       (23U)
/*! WUF23 - Wake-up Flag for WUU_Pn
 *  0b0..No
 *  0b1..Yes
 */
#define WUU_PF_WUF23(x)                          (((uint32_t)(((uint32_t)(x)) << WUU_PF_WUF23_SHIFT)) & WUU_PF_WUF23_MASK)

#define WUU_PF_Reserved24_MASK                   (0x1000000U)
#define WUU_PF_Reserved24_SHIFT                  (24U)
/*! Reserved24 - Reserved
 *  0b0..Not supported
 *  0b1..Not supported
 */
#define WUU_PF_Reserved24(x)                     (((uint32_t)(((uint32_t)(x)) << WUU_PF_Reserved24_SHIFT)) & WUU_PF_Reserved24_MASK)

#define WUU_PF_WUF24_MASK                        (0x1000000U)
#define WUU_PF_WUF24_SHIFT                       (24U)
/*! WUF24 - Wake-up Flag for WUU_Pn
 *  0b0..No
 *  0b1..Yes
 */
#define WUU_PF_WUF24(x)                          (((uint32_t)(((uint32_t)(x)) << WUU_PF_WUF24_SHIFT)) & WUU_PF_WUF24_MASK)

#define WUU_PF_Reserved25_MASK                   (0x2000000U)
#define WUU_PF_Reserved25_SHIFT                  (25U)
/*! Reserved25 - Reserved
 *  0b0..Not supported
 *  0b1..Not supported
 */
#define WUU_PF_Reserved25(x)                     (((uint32_t)(((uint32_t)(x)) << WUU_PF_Reserved25_SHIFT)) & WUU_PF_Reserved25_MASK)

#define WUU_PF_WUF25_MASK                        (0x2000000U)
#define WUU_PF_WUF25_SHIFT                       (25U)
/*! WUF25 - Wake-up Flag for WUU_Pn
 *  0b0..No
 *  0b1..Yes
 */
#define WUU_PF_WUF25(x)                          (((uint32_t)(((uint32_t)(x)) << WUU_PF_WUF25_SHIFT)) & WUU_PF_WUF25_MASK)

#define WUU_PF_Reserved26_MASK                   (0x4000000U)
#define WUU_PF_Reserved26_SHIFT                  (26U)
/*! Reserved26 - Reserved
 *  0b0..Not supported
 *  0b1..Not supported
 */
#define WUU_PF_Reserved26(x)                     (((uint32_t)(((uint32_t)(x)) << WUU_PF_Reserved26_SHIFT)) & WUU_PF_Reserved26_MASK)

#define WUU_PF_WUF26_MASK                        (0x4000000U)
#define WUU_PF_WUF26_SHIFT                       (26U)
/*! WUF26 - Wake-up Flag for WUU_Pn
 *  0b0..No
 *  0b1..Yes
 */
#define WUU_PF_WUF26(x)                          (((uint32_t)(((uint32_t)(x)) << WUU_PF_WUF26_SHIFT)) & WUU_PF_WUF26_MASK)

#define WUU_PF_Reserved27_MASK                   (0x8000000U)
#define WUU_PF_Reserved27_SHIFT                  (27U)
/*! Reserved27 - Reserved
 *  0b0..Not supported
 *  0b1..Not supported
 */
#define WUU_PF_Reserved27(x)                     (((uint32_t)(((uint32_t)(x)) << WUU_PF_Reserved27_SHIFT)) & WUU_PF_Reserved27_MASK)

#define WUU_PF_WUF27_MASK                        (0x8000000U)
#define WUU_PF_WUF27_SHIFT                       (27U)
/*! WUF27 - Wake-up Flag for WUU_Pn
 *  0b0..No
 *  0b1..Yes
 */
#define WUU_PF_WUF27(x)                          (((uint32_t)(((uint32_t)(x)) << WUU_PF_WUF27_SHIFT)) & WUU_PF_WUF27_MASK)

#define WUU_PF_Reserved28_MASK                   (0x10000000U)
#define WUU_PF_Reserved28_SHIFT                  (28U)
/*! Reserved28 - Reserved
 *  0b0..Not supported
 *  0b1..Not supported
 */
#define WUU_PF_Reserved28(x)                     (((uint32_t)(((uint32_t)(x)) << WUU_PF_Reserved28_SHIFT)) & WUU_PF_Reserved28_MASK)

#define WUU_PF_Reserved29_MASK                   (0x20000000U)
#define WUU_PF_Reserved29_SHIFT                  (29U)
/*! Reserved29 - Reserved
 *  0b0..Not supported
 *  0b1..Not supported
 */
#define WUU_PF_Reserved29(x)                     (((uint32_t)(((uint32_t)(x)) << WUU_PF_Reserved29_SHIFT)) & WUU_PF_Reserved29_MASK)

#define WUU_PF_Reserved30_MASK                   (0x40000000U)
#define WUU_PF_Reserved30_SHIFT                  (30U)
/*! Reserved30 - Reserved
 *  0b0..Not supported
 *  0b1..Not supported
 */
#define WUU_PF_Reserved30(x)                     (((uint32_t)(((uint32_t)(x)) << WUU_PF_Reserved30_SHIFT)) & WUU_PF_Reserved30_MASK)

#define WUU_PF_Reserved31_MASK                   (0x80000000U)
#define WUU_PF_Reserved31_SHIFT                  (31U)
/*! Reserved31 - Reserved
 *  0b0..Not supported
 *  0b1..Not supported
 */
#define WUU_PF_Reserved31(x)                     (((uint32_t)(((uint32_t)(x)) << WUU_PF_Reserved31_SHIFT)) & WUU_PF_Reserved31_MASK)
/*! @} */

/*! @name MF - Module Interrupt Flag */
/*! @{ */

#define WUU_MF_MWUF0_MASK                        (0x1U)
#define WUU_MF_MWUF0_SHIFT                       (0U)
/*! MWUF0 - Wake-up Flag for Module n
 *  0b0..No
 *  0b1..Yes
 */
#define WUU_MF_MWUF0(x)                          (((uint32_t)(((uint32_t)(x)) << WUU_MF_MWUF0_SHIFT)) & WUU_MF_MWUF0_MASK)

#define WUU_MF_MWUF1_MASK                        (0x2U)
#define WUU_MF_MWUF1_SHIFT                       (1U)
/*! MWUF1 - Wake-up Flag for Module n
 *  0b0..No
 *  0b1..Yes
 */
#define WUU_MF_MWUF1(x)                          (((uint32_t)(((uint32_t)(x)) << WUU_MF_MWUF1_SHIFT)) & WUU_MF_MWUF1_MASK)

#define WUU_MF_MWUF2_MASK                        (0x4U)
#define WUU_MF_MWUF2_SHIFT                       (2U)
/*! MWUF2 - Wake-up Flag for Module n
 *  0b0..No
 *  0b1..Yes
 */
#define WUU_MF_MWUF2(x)                          (((uint32_t)(((uint32_t)(x)) << WUU_MF_MWUF2_SHIFT)) & WUU_MF_MWUF2_MASK)

#define WUU_MF_MWUF3_MASK                        (0x8U)
#define WUU_MF_MWUF3_SHIFT                       (3U)
/*! MWUF3 - Wake-up Flag for Module n
 *  0b0..No
 *  0b1..Yes
 */
#define WUU_MF_MWUF3(x)                          (((uint32_t)(((uint32_t)(x)) << WUU_MF_MWUF3_SHIFT)) & WUU_MF_MWUF3_MASK)

#define WUU_MF_MWUF4_MASK                        (0x10U)
#define WUU_MF_MWUF4_SHIFT                       (4U)
/*! MWUF4 - Wake-up Flag for Module n
 *  0b0..No
 *  0b1..Yes
 */
#define WUU_MF_MWUF4(x)                          (((uint32_t)(((uint32_t)(x)) << WUU_MF_MWUF4_SHIFT)) & WUU_MF_MWUF4_MASK)

#define WUU_MF_MWUF5_MASK                        (0x20U)
#define WUU_MF_MWUF5_SHIFT                       (5U)
/*! MWUF5 - Wake-up Flag for Module n
 *  0b0..No
 *  0b1..Yes
 */
#define WUU_MF_MWUF5(x)                          (((uint32_t)(((uint32_t)(x)) << WUU_MF_MWUF5_SHIFT)) & WUU_MF_MWUF5_MASK)

#define WUU_MF_MWUF6_MASK                        (0x40U)
#define WUU_MF_MWUF6_SHIFT                       (6U)
/*! MWUF6 - Wake-up Flag for Module n
 *  0b0..No
 *  0b1..Yes
 */
#define WUU_MF_MWUF6(x)                          (((uint32_t)(((uint32_t)(x)) << WUU_MF_MWUF6_SHIFT)) & WUU_MF_MWUF6_MASK)

#define WUU_MF_MWUF7_MASK                        (0x80U)
#define WUU_MF_MWUF7_SHIFT                       (7U)
/*! MWUF7 - Wake-up Flag for Module n
 *  0b0..No
 *  0b1..Yes
 */
#define WUU_MF_MWUF7(x)                          (((uint32_t)(((uint32_t)(x)) << WUU_MF_MWUF7_SHIFT)) & WUU_MF_MWUF7_MASK)
/*! @} */

/*! @name FILT - Pin Filter */
/*! @{ */

#define WUU_FILT_FILTSEL1_MASK                   (0x1FU)
#define WUU_FILT_FILTSEL1_SHIFT                  (0U)
/*! FILTSEL1 - Filter 1 Pin Select */
#define WUU_FILT_FILTSEL1(x)                     (((uint32_t)(((uint32_t)(x)) << WUU_FILT_FILTSEL1_SHIFT)) & WUU_FILT_FILTSEL1_MASK)

#define WUU_FILT_FILTE1_MASK                     (0x60U)
#define WUU_FILT_FILTE1_SHIFT                    (5U)
/*! FILTE1 - Filter 1 Enable
 *  0b00..Disable
 *  0b01..Enable (Detect on rising edge or high level)
 *  0b10..Enable (Detect on falling edge or low level)
 *  0b11..Enable (Detect on any edge)
 */
#define WUU_FILT_FILTE1(x)                       (((uint32_t)(((uint32_t)(x)) << WUU_FILT_FILTE1_SHIFT)) & WUU_FILT_FILTE1_MASK)

#define WUU_FILT_FILTF1_MASK                     (0x80U)
#define WUU_FILT_FILTF1_SHIFT                    (7U)
/*! FILTF1 - Filter 1 Flag
 *  0b0..No
 *  0b1..Yes
 */
#define WUU_FILT_FILTF1(x)                       (((uint32_t)(((uint32_t)(x)) << WUU_FILT_FILTF1_SHIFT)) & WUU_FILT_FILTF1_MASK)

#define WUU_FILT_FILTSEL2_MASK                   (0x1F00U)
#define WUU_FILT_FILTSEL2_SHIFT                  (8U)
/*! FILTSEL2 - Filter 2 Pin Select */
#define WUU_FILT_FILTSEL2(x)                     (((uint32_t)(((uint32_t)(x)) << WUU_FILT_FILTSEL2_SHIFT)) & WUU_FILT_FILTSEL2_MASK)

#define WUU_FILT_FILTE2_MASK                     (0x6000U)
#define WUU_FILT_FILTE2_SHIFT                    (13U)
/*! FILTE2 - Filter 2 Enable
 *  0b00..Disable
 *  0b01..Enable (Detect on rising edge or high level)
 *  0b10..Enable (Detect on falling edge or low level)
 *  0b11..Enable (Detect on any edge)
 */
#define WUU_FILT_FILTE2(x)                       (((uint32_t)(((uint32_t)(x)) << WUU_FILT_FILTE2_SHIFT)) & WUU_FILT_FILTE2_MASK)

#define WUU_FILT_FILTF2_MASK                     (0x8000U)
#define WUU_FILT_FILTF2_SHIFT                    (15U)
/*! FILTF2 - Filter 2 Flag
 *  0b0..No
 *  0b1..Yes
 */
#define WUU_FILT_FILTF2(x)                       (((uint32_t)(((uint32_t)(x)) << WUU_FILT_FILTF2_SHIFT)) & WUU_FILT_FILTF2_MASK)

#define WUU_FILT_FILTSEL3_MASK                   (0x1F0000U)
#define WUU_FILT_FILTSEL3_SHIFT                  (16U)
/*! FILTSEL3 - Filter 3 Pin Select */
#define WUU_FILT_FILTSEL3(x)                     (((uint32_t)(((uint32_t)(x)) << WUU_FILT_FILTSEL3_SHIFT)) & WUU_FILT_FILTSEL3_MASK)

#define WUU_FILT_FILTE3_MASK                     (0x600000U)
#define WUU_FILT_FILTE3_SHIFT                    (21U)
/*! FILTE3 - Filter 3 Enable
 *  0b00..Disable
 *  0b01..Enable (Detect on rising edge or high level)
 *  0b10..Enable (Detect on falling edge or low level)
 *  0b11..Enable (Detect on any edge)
 */
#define WUU_FILT_FILTE3(x)                       (((uint32_t)(((uint32_t)(x)) << WUU_FILT_FILTE3_SHIFT)) & WUU_FILT_FILTE3_MASK)

#define WUU_FILT_FILTF3_MASK                     (0x800000U)
#define WUU_FILT_FILTF3_SHIFT                    (23U)
/*! FILTF3 - Filter 3 Flag
 *  0b0..No
 *  0b1..Yes
 */
#define WUU_FILT_FILTF3(x)                       (((uint32_t)(((uint32_t)(x)) << WUU_FILT_FILTF3_SHIFT)) & WUU_FILT_FILTF3_MASK)

#define WUU_FILT_FILTSEL4_MASK                   (0x1F000000U)
#define WUU_FILT_FILTSEL4_SHIFT                  (24U)
/*! FILTSEL4 - Filter 4 Pin Select */
#define WUU_FILT_FILTSEL4(x)                     (((uint32_t)(((uint32_t)(x)) << WUU_FILT_FILTSEL4_SHIFT)) & WUU_FILT_FILTSEL4_MASK)

#define WUU_FILT_FILTE4_MASK                     (0x60000000U)
#define WUU_FILT_FILTE4_SHIFT                    (29U)
/*! FILTE4 - Filter 4 Enable
 *  0b00..Disable
 *  0b01..Enable (Detect on rising edge or high level)
 *  0b10..Enable (Detect on falling edge or low level)
 *  0b11..Enable (Detect on any edge)
 */
#define WUU_FILT_FILTE4(x)                       (((uint32_t)(((uint32_t)(x)) << WUU_FILT_FILTE4_SHIFT)) & WUU_FILT_FILTE4_MASK)

#define WUU_FILT_FILTF4_MASK                     (0x80000000U)
#define WUU_FILT_FILTF4_SHIFT                    (31U)
/*! FILTF4 - Filter 4 Flag
 *  0b0..No
 *  0b1..Yes
 */
#define WUU_FILT_FILTF4(x)                       (((uint32_t)(((uint32_t)(x)) << WUU_FILT_FILTF4_SHIFT)) & WUU_FILT_FILTF4_MASK)
/*! @} */

/*! @name PDC1 - Pin DMA/Trigger Configuration 1 */
/*! @{ */

#define WUU_PDC1_WUPDC0_MASK                     (0x3U)
#define WUU_PDC1_WUPDC0_SHIFT                    (0U)
/*! WUPDC0 - Wake-up Pin Configuration for WUU_Pn
 *  0b00..Interrupt
 *  0b01..DMA request
 *  0b10..Trigger event
 *  0b11..Reserved
 */
#define WUU_PDC1_WUPDC0(x)                       (((uint32_t)(((uint32_t)(x)) << WUU_PDC1_WUPDC0_SHIFT)) & WUU_PDC1_WUPDC0_MASK)

#define WUU_PDC1_WUPDC1_MASK                     (0xCU)
#define WUU_PDC1_WUPDC1_SHIFT                    (2U)
/*! WUPDC1 - Wake-up Pin Configuration for WUU_Pn
 *  0b00..Interrupt
 *  0b01..DMA request
 *  0b10..Trigger event
 *  0b11..Reserved
 */
#define WUU_PDC1_WUPDC1(x)                       (((uint32_t)(((uint32_t)(x)) << WUU_PDC1_WUPDC1_SHIFT)) & WUU_PDC1_WUPDC1_MASK)

#define WUU_PDC1_WUPDC2_MASK                     (0x30U)
#define WUU_PDC1_WUPDC2_SHIFT                    (4U)
/*! WUPDC2 - Wake-up Pin Configuration for WUU_Pn
 *  0b00..Interrupt
 *  0b01..DMA request
 *  0b10..Trigger event
 *  0b11..Reserved
 */
#define WUU_PDC1_WUPDC2(x)                       (((uint32_t)(((uint32_t)(x)) << WUU_PDC1_WUPDC2_SHIFT)) & WUU_PDC1_WUPDC2_MASK)

#define WUU_PDC1_WUPDC3_MASK                     (0xC0U)
#define WUU_PDC1_WUPDC3_SHIFT                    (6U)
/*! WUPDC3 - Wake-up Pin Configuration for WUU_Pn
 *  0b00..Interrupt
 *  0b01..DMA request
 *  0b10..Trigger event
 *  0b11..Reserved
 */
#define WUU_PDC1_WUPDC3(x)                       (((uint32_t)(((uint32_t)(x)) << WUU_PDC1_WUPDC3_SHIFT)) & WUU_PDC1_WUPDC3_MASK)

#define WUU_PDC1_WUPDC4_MASK                     (0x300U)
#define WUU_PDC1_WUPDC4_SHIFT                    (8U)
/*! WUPDC4 - Wake-up Pin Configuration for WUU_Pn
 *  0b00..Interrupt
 *  0b01..DMA request
 *  0b10..Trigger event
 *  0b11..Reserved
 */
#define WUU_PDC1_WUPDC4(x)                       (((uint32_t)(((uint32_t)(x)) << WUU_PDC1_WUPDC4_SHIFT)) & WUU_PDC1_WUPDC4_MASK)

#define WUU_PDC1_WUPDC5_MASK                     (0xC00U)
#define WUU_PDC1_WUPDC5_SHIFT                    (10U)
/*! WUPDC5 - Wake-up Pin Configuration for WUU_Pn
 *  0b00..Interrupt
 *  0b01..DMA request
 *  0b10..Trigger event
 *  0b11..Reserved
 */
#define WUU_PDC1_WUPDC5(x)                       (((uint32_t)(((uint32_t)(x)) << WUU_PDC1_WUPDC5_SHIFT)) & WUU_PDC1_WUPDC5_MASK)

#define WUU_PDC1_WUPDC6_MASK                     (0x3000U)
#define WUU_PDC1_WUPDC6_SHIFT                    (12U)
/*! WUPDC6 - Wake-up Pin Configuration for WUU_Pn
 *  0b00..Interrupt
 *  0b01..DMA request
 *  0b10..Trigger event
 *  0b11..Reserved
 */
#define WUU_PDC1_WUPDC6(x)                       (((uint32_t)(((uint32_t)(x)) << WUU_PDC1_WUPDC6_SHIFT)) & WUU_PDC1_WUPDC6_MASK)

#define WUU_PDC1_WUPDC7_MASK                     (0xC000U)
#define WUU_PDC1_WUPDC7_SHIFT                    (14U)
/*! WUPDC7 - Wake-up Pin Configuration for WUU_Pn
 *  0b00..Interrupt
 *  0b01..DMA request
 *  0b10..Trigger event
 *  0b11..Reserved
 */
#define WUU_PDC1_WUPDC7(x)                       (((uint32_t)(((uint32_t)(x)) << WUU_PDC1_WUPDC7_SHIFT)) & WUU_PDC1_WUPDC7_MASK)

#define WUU_PDC1_WUPDC8_MASK                     (0x30000U)
#define WUU_PDC1_WUPDC8_SHIFT                    (16U)
/*! WUPDC8 - Wake-up Pin Configuration for WUU_Pn
 *  0b00..Interrupt
 *  0b01..DMA request
 *  0b10..Trigger event
 *  0b11..Reserved
 */
#define WUU_PDC1_WUPDC8(x)                       (((uint32_t)(((uint32_t)(x)) << WUU_PDC1_WUPDC8_SHIFT)) & WUU_PDC1_WUPDC8_MASK)

#define WUU_PDC1_WUPDC9_MASK                     (0xC0000U)
#define WUU_PDC1_WUPDC9_SHIFT                    (18U)
/*! WUPDC9 - Wake-up Pin Configuration for WUU_Pn
 *  0b00..Interrupt
 *  0b01..DMA request
 *  0b10..Trigger event
 *  0b11..Reserved
 */
#define WUU_PDC1_WUPDC9(x)                       (((uint32_t)(((uint32_t)(x)) << WUU_PDC1_WUPDC9_SHIFT)) & WUU_PDC1_WUPDC9_MASK)

#define WUU_PDC1_WUPDC10_MASK                    (0x300000U)
#define WUU_PDC1_WUPDC10_SHIFT                   (20U)
/*! WUPDC10 - Wake-up Pin Configuration for WUU_Pn
 *  0b00..Interrupt
 *  0b01..DMA request
 *  0b10..Trigger event
 *  0b11..Reserved
 */
#define WUU_PDC1_WUPDC10(x)                      (((uint32_t)(((uint32_t)(x)) << WUU_PDC1_WUPDC10_SHIFT)) & WUU_PDC1_WUPDC10_MASK)

#define WUU_PDC1_WUPDC11_MASK                    (0xC00000U)
#define WUU_PDC1_WUPDC11_SHIFT                   (22U)
/*! WUPDC11 - Wake-up Pin Configuration for WUU_Pn
 *  0b00..Interrupt
 *  0b01..DMA request
 *  0b10..Trigger event
 *  0b11..Reserved
 */
#define WUU_PDC1_WUPDC11(x)                      (((uint32_t)(((uint32_t)(x)) << WUU_PDC1_WUPDC11_SHIFT)) & WUU_PDC1_WUPDC11_MASK)

#define WUU_PDC1_WUPDC12_MASK                    (0x3000000U)
#define WUU_PDC1_WUPDC12_SHIFT                   (24U)
/*! WUPDC12 - Wake-up Pin Configuration for WUU_Pn
 *  0b00..Interrupt
 *  0b01..DMA request
 *  0b10..Trigger event
 *  0b11..Reserved
 */
#define WUU_PDC1_WUPDC12(x)                      (((uint32_t)(((uint32_t)(x)) << WUU_PDC1_WUPDC12_SHIFT)) & WUU_PDC1_WUPDC12_MASK)

#define WUU_PDC1_WUPDC13_MASK                    (0xC000000U)
#define WUU_PDC1_WUPDC13_SHIFT                   (26U)
/*! WUPDC13 - Wake-up Pin Configuration for WUU_Pn
 *  0b00..Interrupt
 *  0b01..DMA request
 *  0b10..Trigger event
 *  0b11..Reserved
 */
#define WUU_PDC1_WUPDC13(x)                      (((uint32_t)(((uint32_t)(x)) << WUU_PDC1_WUPDC13_SHIFT)) & WUU_PDC1_WUPDC13_MASK)

#define WUU_PDC1_WUPDC14_MASK                    (0x30000000U)
#define WUU_PDC1_WUPDC14_SHIFT                   (28U)
/*! WUPDC14 - Wake-up Pin Configuration for WUU_Pn
 *  0b00..Interrupt
 *  0b01..DMA request
 *  0b10..Trigger event
 *  0b11..Reserved
 */
#define WUU_PDC1_WUPDC14(x)                      (((uint32_t)(((uint32_t)(x)) << WUU_PDC1_WUPDC14_SHIFT)) & WUU_PDC1_WUPDC14_MASK)

#define WUU_PDC1_WUPDC15_MASK                    (0xC0000000U)
#define WUU_PDC1_WUPDC15_SHIFT                   (30U)
/*! WUPDC15 - Wake-up Pin Configuration for WUU_Pn
 *  0b00..Interrupt
 *  0b01..DMA request
 *  0b10..Trigger event
 *  0b11..Reserved
 */
#define WUU_PDC1_WUPDC15(x)                      (((uint32_t)(((uint32_t)(x)) << WUU_PDC1_WUPDC15_SHIFT)) & WUU_PDC1_WUPDC15_MASK)
/*! @} */

/*! @name PDC2 - Pin DMA/Trigger Configuration 2 */
/*! @{ */

#define WUU_PDC2_Reserved16_MASK                 (0x3U)
#define WUU_PDC2_Reserved16_SHIFT                (0U)
/*! Reserved16 - Reserved
 *  0b00..Not supported
 *  0b01..Not supported
 *  0b10..Not supported
 *  0b11..Not supported
 */
#define WUU_PDC2_Reserved16(x)                   (((uint32_t)(((uint32_t)(x)) << WUU_PDC2_Reserved16_SHIFT)) & WUU_PDC2_Reserved16_MASK)

#define WUU_PDC2_WUPDC16_MASK                    (0x3U)
#define WUU_PDC2_WUPDC16_SHIFT                   (0U)
/*! WUPDC16 - Wake-up Pin Configuration for WUU_Pn
 *  0b00..Interrupt
 *  0b01..DMA request
 *  0b10..Trigger event
 *  0b11..Reserved
 */
#define WUU_PDC2_WUPDC16(x)                      (((uint32_t)(((uint32_t)(x)) << WUU_PDC2_WUPDC16_SHIFT)) & WUU_PDC2_WUPDC16_MASK)

#define WUU_PDC2_Reserved17_MASK                 (0xCU)
#define WUU_PDC2_Reserved17_SHIFT                (2U)
/*! Reserved17 - Reserved
 *  0b00..Not supported
 *  0b01..Not supported
 *  0b10..Not supported
 *  0b11..Not supported
 */
#define WUU_PDC2_Reserved17(x)                   (((uint32_t)(((uint32_t)(x)) << WUU_PDC2_Reserved17_SHIFT)) & WUU_PDC2_Reserved17_MASK)

#define WUU_PDC2_WUPDC17_MASK                    (0xCU)
#define WUU_PDC2_WUPDC17_SHIFT                   (2U)
/*! WUPDC17 - Wake-up Pin Configuration for WUU_Pn
 *  0b00..Interrupt
 *  0b01..DMA request
 *  0b10..Trigger event
 *  0b11..Reserved
 */
#define WUU_PDC2_WUPDC17(x)                      (((uint32_t)(((uint32_t)(x)) << WUU_PDC2_WUPDC17_SHIFT)) & WUU_PDC2_WUPDC17_MASK)

#define WUU_PDC2_Reserved18_MASK                 (0x30U)
#define WUU_PDC2_Reserved18_SHIFT                (4U)
/*! Reserved18 - Reserved
 *  0b00..Not supported
 *  0b01..Not supported
 *  0b10..Not supported
 *  0b11..Not supported
 */
#define WUU_PDC2_Reserved18(x)                   (((uint32_t)(((uint32_t)(x)) << WUU_PDC2_Reserved18_SHIFT)) & WUU_PDC2_Reserved18_MASK)

#define WUU_PDC2_WUPDC18_MASK                    (0x30U)
#define WUU_PDC2_WUPDC18_SHIFT                   (4U)
/*! WUPDC18 - Wake-up Pin Configuration for WUU_Pn
 *  0b00..Interrupt
 *  0b01..DMA request
 *  0b10..Trigger event
 *  0b11..Reserved
 */
#define WUU_PDC2_WUPDC18(x)                      (((uint32_t)(((uint32_t)(x)) << WUU_PDC2_WUPDC18_SHIFT)) & WUU_PDC2_WUPDC18_MASK)

#define WUU_PDC2_Reserved19_MASK                 (0xC0U)
#define WUU_PDC2_Reserved19_SHIFT                (6U)
/*! Reserved19 - Reserved
 *  0b00..Not supported
 *  0b01..Not supported
 *  0b10..Not supported
 *  0b11..Not supported
 */
#define WUU_PDC2_Reserved19(x)                   (((uint32_t)(((uint32_t)(x)) << WUU_PDC2_Reserved19_SHIFT)) & WUU_PDC2_Reserved19_MASK)

#define WUU_PDC2_WUPDC19_MASK                    (0xC0U)
#define WUU_PDC2_WUPDC19_SHIFT                   (6U)
/*! WUPDC19 - Wake-up Pin Configuration for WUU_Pn
 *  0b00..Interrupt
 *  0b01..DMA request
 *  0b10..Trigger event
 *  0b11..Reserved
 */
#define WUU_PDC2_WUPDC19(x)                      (((uint32_t)(((uint32_t)(x)) << WUU_PDC2_WUPDC19_SHIFT)) & WUU_PDC2_WUPDC19_MASK)

#define WUU_PDC2_Reserved20_MASK                 (0x300U)
#define WUU_PDC2_Reserved20_SHIFT                (8U)
/*! Reserved20 - Reserved
 *  0b00..Not supported
 *  0b01..Not supported
 *  0b10..Not supported
 *  0b11..Not supported
 */
#define WUU_PDC2_Reserved20(x)                   (((uint32_t)(((uint32_t)(x)) << WUU_PDC2_Reserved20_SHIFT)) & WUU_PDC2_Reserved20_MASK)

#define WUU_PDC2_WUPDC20_MASK                    (0x300U)
#define WUU_PDC2_WUPDC20_SHIFT                   (8U)
/*! WUPDC20 - Wake-up Pin Configuration for WUU_Pn
 *  0b00..Interrupt
 *  0b01..DMA request
 *  0b10..Trigger event
 *  0b11..Reserved
 */
#define WUU_PDC2_WUPDC20(x)                      (((uint32_t)(((uint32_t)(x)) << WUU_PDC2_WUPDC20_SHIFT)) & WUU_PDC2_WUPDC20_MASK)

#define WUU_PDC2_Reserved21_MASK                 (0xC00U)
#define WUU_PDC2_Reserved21_SHIFT                (10U)
/*! Reserved21 - Reserved
 *  0b00..Not supported
 *  0b01..Not supported
 *  0b10..Not supported
 *  0b11..Not supported
 */
#define WUU_PDC2_Reserved21(x)                   (((uint32_t)(((uint32_t)(x)) << WUU_PDC2_Reserved21_SHIFT)) & WUU_PDC2_Reserved21_MASK)

#define WUU_PDC2_WUPDC21_MASK                    (0xC00U)
#define WUU_PDC2_WUPDC21_SHIFT                   (10U)
/*! WUPDC21 - Wake-up Pin Configuration for WUU_Pn
 *  0b00..Interrupt
 *  0b01..DMA request
 *  0b10..Trigger event
 *  0b11..Reserved
 */
#define WUU_PDC2_WUPDC21(x)                      (((uint32_t)(((uint32_t)(x)) << WUU_PDC2_WUPDC21_SHIFT)) & WUU_PDC2_WUPDC21_MASK)

#define WUU_PDC2_Reserved22_MASK                 (0x3000U)
#define WUU_PDC2_Reserved22_SHIFT                (12U)
/*! Reserved22 - Reserved
 *  0b00..Not supported
 *  0b01..Not supported
 *  0b10..Not supported
 *  0b11..Not supported
 */
#define WUU_PDC2_Reserved22(x)                   (((uint32_t)(((uint32_t)(x)) << WUU_PDC2_Reserved22_SHIFT)) & WUU_PDC2_Reserved22_MASK)

#define WUU_PDC2_WUPDC22_MASK                    (0x3000U)
#define WUU_PDC2_WUPDC22_SHIFT                   (12U)
/*! WUPDC22 - Wake-up Pin Configuration for WUU_Pn
 *  0b00..Interrupt
 *  0b01..DMA request
 *  0b10..Trigger event
 *  0b11..Reserved
 */
#define WUU_PDC2_WUPDC22(x)                      (((uint32_t)(((uint32_t)(x)) << WUU_PDC2_WUPDC22_SHIFT)) & WUU_PDC2_WUPDC22_MASK)

#define WUU_PDC2_Reserved23_MASK                 (0xC000U)
#define WUU_PDC2_Reserved23_SHIFT                (14U)
/*! Reserved23 - Reserved
 *  0b00..Not supported
 *  0b01..Not supported
 *  0b10..Not supported
 *  0b11..Not supported
 */
#define WUU_PDC2_Reserved23(x)                   (((uint32_t)(((uint32_t)(x)) << WUU_PDC2_Reserved23_SHIFT)) & WUU_PDC2_Reserved23_MASK)

#define WUU_PDC2_WUPDC23_MASK                    (0xC000U)
#define WUU_PDC2_WUPDC23_SHIFT                   (14U)
/*! WUPDC23 - Wake-up Pin Configuration for WUU_Pn
 *  0b00..Interrupt
 *  0b01..DMA request
 *  0b10..Trigger event
 *  0b11..Reserved
 */
#define WUU_PDC2_WUPDC23(x)                      (((uint32_t)(((uint32_t)(x)) << WUU_PDC2_WUPDC23_SHIFT)) & WUU_PDC2_WUPDC23_MASK)

#define WUU_PDC2_Reserved24_MASK                 (0x30000U)
#define WUU_PDC2_Reserved24_SHIFT                (16U)
/*! Reserved24 - Reserved
 *  0b00..Not supported
 *  0b01..Not supported
 *  0b10..Not supported
 *  0b11..Not supported
 */
#define WUU_PDC2_Reserved24(x)                   (((uint32_t)(((uint32_t)(x)) << WUU_PDC2_Reserved24_SHIFT)) & WUU_PDC2_Reserved24_MASK)

#define WUU_PDC2_WUPDC24_MASK                    (0x30000U)
#define WUU_PDC2_WUPDC24_SHIFT                   (16U)
/*! WUPDC24 - Wake-up Pin Configuration for WUU_Pn
 *  0b00..Interrupt
 *  0b01..DMA request
 *  0b10..Trigger event
 *  0b11..Reserved
 */
#define WUU_PDC2_WUPDC24(x)                      (((uint32_t)(((uint32_t)(x)) << WUU_PDC2_WUPDC24_SHIFT)) & WUU_PDC2_WUPDC24_MASK)

#define WUU_PDC2_Reserved25_MASK                 (0xC0000U)
#define WUU_PDC2_Reserved25_SHIFT                (18U)
/*! Reserved25 - Reserved
 *  0b00..Not supported
 *  0b01..Not supported
 *  0b10..Not supported
 *  0b11..Not supported
 */
#define WUU_PDC2_Reserved25(x)                   (((uint32_t)(((uint32_t)(x)) << WUU_PDC2_Reserved25_SHIFT)) & WUU_PDC2_Reserved25_MASK)

#define WUU_PDC2_WUPDC25_MASK                    (0xC0000U)
#define WUU_PDC2_WUPDC25_SHIFT                   (18U)
/*! WUPDC25 - Wake-up Pin Configuration for WUU_Pn
 *  0b00..Interrupt
 *  0b01..DMA request
 *  0b10..Trigger event
 *  0b11..Reserved
 */
#define WUU_PDC2_WUPDC25(x)                      (((uint32_t)(((uint32_t)(x)) << WUU_PDC2_WUPDC25_SHIFT)) & WUU_PDC2_WUPDC25_MASK)

#define WUU_PDC2_Reserved26_MASK                 (0x300000U)
#define WUU_PDC2_Reserved26_SHIFT                (20U)
/*! Reserved26 - Reserved
 *  0b00..Not supported
 *  0b01..Not supported
 *  0b10..Not supported
 *  0b11..Not supported
 */
#define WUU_PDC2_Reserved26(x)                   (((uint32_t)(((uint32_t)(x)) << WUU_PDC2_Reserved26_SHIFT)) & WUU_PDC2_Reserved26_MASK)

#define WUU_PDC2_WUPDC26_MASK                    (0x300000U)
#define WUU_PDC2_WUPDC26_SHIFT                   (20U)
/*! WUPDC26 - Wake-up Pin Configuration for WUU_Pn
 *  0b00..Interrupt
 *  0b01..DMA request
 *  0b10..Trigger event
 *  0b11..Reserved
 */
#define WUU_PDC2_WUPDC26(x)                      (((uint32_t)(((uint32_t)(x)) << WUU_PDC2_WUPDC26_SHIFT)) & WUU_PDC2_WUPDC26_MASK)

#define WUU_PDC2_Reserved27_MASK                 (0xC00000U)
#define WUU_PDC2_Reserved27_SHIFT                (22U)
/*! Reserved27 - Reserved
 *  0b00..Not supported
 *  0b01..Not supported
 *  0b10..Not supported
 *  0b11..Not supported
 */
#define WUU_PDC2_Reserved27(x)                   (((uint32_t)(((uint32_t)(x)) << WUU_PDC2_Reserved27_SHIFT)) & WUU_PDC2_Reserved27_MASK)

#define WUU_PDC2_WUPDC27_MASK                    (0xC00000U)
#define WUU_PDC2_WUPDC27_SHIFT                   (22U)
/*! WUPDC27 - Wake-up Pin Configuration for WUU_Pn
 *  0b00..Interrupt
 *  0b01..DMA request
 *  0b10..Trigger event
 *  0b11..Reserved
 */
#define WUU_PDC2_WUPDC27(x)                      (((uint32_t)(((uint32_t)(x)) << WUU_PDC2_WUPDC27_SHIFT)) & WUU_PDC2_WUPDC27_MASK)

#define WUU_PDC2_Reserved28_MASK                 (0x3000000U)
#define WUU_PDC2_Reserved28_SHIFT                (24U)
/*! Reserved28 - Reserved
 *  0b00..Not supported
 *  0b01..Not supported
 *  0b10..Not supported
 *  0b11..Not supported
 */
#define WUU_PDC2_Reserved28(x)                   (((uint32_t)(((uint32_t)(x)) << WUU_PDC2_Reserved28_SHIFT)) & WUU_PDC2_Reserved28_MASK)

#define WUU_PDC2_Reserved29_MASK                 (0xC000000U)
#define WUU_PDC2_Reserved29_SHIFT                (26U)
/*! Reserved29 - Reserved
 *  0b00..Not supported
 *  0b01..Not supported
 *  0b10..Not supported
 *  0b11..Not supported
 */
#define WUU_PDC2_Reserved29(x)                   (((uint32_t)(((uint32_t)(x)) << WUU_PDC2_Reserved29_SHIFT)) & WUU_PDC2_Reserved29_MASK)

#define WUU_PDC2_Reserved30_MASK                 (0x30000000U)
#define WUU_PDC2_Reserved30_SHIFT                (28U)
/*! Reserved30 - Reserved
 *  0b00..Not supported
 *  0b01..Not supported
 *  0b10..Not supported
 *  0b11..Not supported
 */
#define WUU_PDC2_Reserved30(x)                   (((uint32_t)(((uint32_t)(x)) << WUU_PDC2_Reserved30_SHIFT)) & WUU_PDC2_Reserved30_MASK)

#define WUU_PDC2_Reserved31_MASK                 (0xC0000000U)
#define WUU_PDC2_Reserved31_SHIFT                (30U)
/*! Reserved31 - Reserved
 *  0b00..Not supported
 *  0b01..Not supported
 *  0b10..Not supported
 *  0b11..Not supported
 */
#define WUU_PDC2_Reserved31(x)                   (((uint32_t)(((uint32_t)(x)) << WUU_PDC2_Reserved31_SHIFT)) & WUU_PDC2_Reserved31_MASK)
/*! @} */

/*! @name FDC - Pin Filter DMA/Trigger Configuration */
/*! @{ */

#define WUU_FDC_FILTC1_MASK                      (0x3U)
#define WUU_FDC_FILTC1_SHIFT                     (0U)
/*! FILTC1 - Filter Configuration for FILTn
 *  0b00..Interrupt
 *  0b01..DMA request
 *  0b10..Trigger event
 *  0b11..Reserved
 */
#define WUU_FDC_FILTC1(x)                        (((uint32_t)(((uint32_t)(x)) << WUU_FDC_FILTC1_SHIFT)) & WUU_FDC_FILTC1_MASK)

#define WUU_FDC_FILTC2_MASK                      (0xCU)
#define WUU_FDC_FILTC2_SHIFT                     (2U)
/*! FILTC2 - Filter Configuration for FILTn
 *  0b00..Interrupt
 *  0b01..DMA request
 *  0b10..Trigger event
 *  0b11..Reserved
 */
#define WUU_FDC_FILTC2(x)                        (((uint32_t)(((uint32_t)(x)) << WUU_FDC_FILTC2_SHIFT)) & WUU_FDC_FILTC2_MASK)

#define WUU_FDC_FILTC3_MASK                      (0x30U)
#define WUU_FDC_FILTC3_SHIFT                     (4U)
/*! FILTC3 - Filter Configuration for FILTn
 *  0b00..Interrupt
 *  0b01..DMA request
 *  0b10..Trigger event
 *  0b11..Reserved
 */
#define WUU_FDC_FILTC3(x)                        (((uint32_t)(((uint32_t)(x)) << WUU_FDC_FILTC3_SHIFT)) & WUU_FDC_FILTC3_MASK)

#define WUU_FDC_FILTC4_MASK                      (0xC0U)
#define WUU_FDC_FILTC4_SHIFT                     (6U)
/*! FILTC4 - Filter Configuration for FILTn
 *  0b00..Interrupt
 *  0b01..DMA request
 *  0b10..Trigger event
 *  0b11..Reserved
 */
#define WUU_FDC_FILTC4(x)                        (((uint32_t)(((uint32_t)(x)) << WUU_FDC_FILTC4_SHIFT)) & WUU_FDC_FILTC4_MASK)
/*! @} */

/*! @name PMC - Pin Mode Configuration */
/*! @{ */

#define WUU_PMC_WUPMC0_MASK                      (0x1U)
#define WUU_PMC_WUPMC0_SHIFT                     (0U)
/*! WUPMC0 - Wake-up Pin Mode Configuration for WUU_Pn
 *  0b0..Active only during a low-leakage mode. You can modify the corresponding fields within Pin Enable (PEn) or
 *       Pin DMA/Trigger Configuration (PDCn).
 *  0b1..Active during all power modes. Do not modify the corresponding fields within Pin Enable (PEn) or Pin DMA/Trigger Configuration (PDCn).
 */
#define WUU_PMC_WUPMC0(x)                        (((uint32_t)(((uint32_t)(x)) << WUU_PMC_WUPMC0_SHIFT)) & WUU_PMC_WUPMC0_MASK)

#define WUU_PMC_WUPMC1_MASK                      (0x2U)
#define WUU_PMC_WUPMC1_SHIFT                     (1U)
/*! WUPMC1 - Wake-up Pin Mode Configuration for WUU_Pn
 *  0b0..Active only during a low-leakage mode. You can modify the corresponding fields within Pin Enable (PEn) or
 *       Pin DMA/Trigger Configuration (PDCn).
 *  0b1..Active during all power modes. Do not modify the corresponding fields within Pin Enable (PEn) or Pin DMA/Trigger Configuration (PDCn).
 */
#define WUU_PMC_WUPMC1(x)                        (((uint32_t)(((uint32_t)(x)) << WUU_PMC_WUPMC1_SHIFT)) & WUU_PMC_WUPMC1_MASK)

#define WUU_PMC_WUPMC2_MASK                      (0x4U)
#define WUU_PMC_WUPMC2_SHIFT                     (2U)
/*! WUPMC2 - Wake-up Pin Mode Configuration for WUU_Pn
 *  0b0..Active only during a low-leakage mode. You can modify the corresponding fields within Pin Enable (PEn) or
 *       Pin DMA/Trigger Configuration (PDCn).
 *  0b1..Active during all power modes. Do not modify the corresponding fields within Pin Enable (PEn) or Pin DMA/Trigger Configuration (PDCn).
 */
#define WUU_PMC_WUPMC2(x)                        (((uint32_t)(((uint32_t)(x)) << WUU_PMC_WUPMC2_SHIFT)) & WUU_PMC_WUPMC2_MASK)

#define WUU_PMC_WUPMC3_MASK                      (0x8U)
#define WUU_PMC_WUPMC3_SHIFT                     (3U)
/*! WUPMC3 - Wake-up Pin Mode Configuration for WUU_Pn
 *  0b0..Active only during a low-leakage mode. You can modify the corresponding fields within Pin Enable (PEn) or
 *       Pin DMA/Trigger Configuration (PDCn).
 *  0b1..Active during all power modes. Do not modify the corresponding fields within Pin Enable (PEn) or Pin DMA/Trigger Configuration (PDCn).
 */
#define WUU_PMC_WUPMC3(x)                        (((uint32_t)(((uint32_t)(x)) << WUU_PMC_WUPMC3_SHIFT)) & WUU_PMC_WUPMC3_MASK)

#define WUU_PMC_WUPMC4_MASK                      (0x10U)
#define WUU_PMC_WUPMC4_SHIFT                     (4U)
/*! WUPMC4 - Wake-up Pin Mode Configuration for WUU_Pn
 *  0b0..Active only during a low-leakage mode. You can modify the corresponding fields within Pin Enable (PEn) or
 *       Pin DMA/Trigger Configuration (PDCn).
 *  0b1..Active during all power modes. Do not modify the corresponding fields within Pin Enable (PEn) or Pin DMA/Trigger Configuration (PDCn).
 */
#define WUU_PMC_WUPMC4(x)                        (((uint32_t)(((uint32_t)(x)) << WUU_PMC_WUPMC4_SHIFT)) & WUU_PMC_WUPMC4_MASK)

#define WUU_PMC_WUPMC5_MASK                      (0x20U)
#define WUU_PMC_WUPMC5_SHIFT                     (5U)
/*! WUPMC5 - Wake-up Pin Mode Configuration for WUU_Pn
 *  0b0..Active only during a low-leakage mode. You can modify the corresponding fields within Pin Enable (PEn) or
 *       Pin DMA/Trigger Configuration (PDCn).
 *  0b1..Active during all power modes. Do not modify the corresponding fields within Pin Enable (PEn) or Pin DMA/Trigger Configuration (PDCn).
 */
#define WUU_PMC_WUPMC5(x)                        (((uint32_t)(((uint32_t)(x)) << WUU_PMC_WUPMC5_SHIFT)) & WUU_PMC_WUPMC5_MASK)

#define WUU_PMC_WUPMC6_MASK                      (0x40U)
#define WUU_PMC_WUPMC6_SHIFT                     (6U)
/*! WUPMC6 - Wake-up Pin Mode Configuration for WUU_Pn
 *  0b0..Active only during a low-leakage mode. You can modify the corresponding fields within Pin Enable (PEn) or
 *       Pin DMA/Trigger Configuration (PDCn).
 *  0b1..Active during all power modes. Do not modify the corresponding fields within Pin Enable (PEn) or Pin DMA/Trigger Configuration (PDCn).
 */
#define WUU_PMC_WUPMC6(x)                        (((uint32_t)(((uint32_t)(x)) << WUU_PMC_WUPMC6_SHIFT)) & WUU_PMC_WUPMC6_MASK)

#define WUU_PMC_WUPMC7_MASK                      (0x80U)
#define WUU_PMC_WUPMC7_SHIFT                     (7U)
/*! WUPMC7 - Wake-up Pin Mode Configuration for WUU_Pn
 *  0b0..Active only during a low-leakage mode. You can modify the corresponding fields within Pin Enable (PEn) or
 *       Pin DMA/Trigger Configuration (PDCn).
 *  0b1..Active during all power modes. Do not modify the corresponding fields within Pin Enable (PEn) or Pin DMA/Trigger Configuration (PDCn).
 */
#define WUU_PMC_WUPMC7(x)                        (((uint32_t)(((uint32_t)(x)) << WUU_PMC_WUPMC7_SHIFT)) & WUU_PMC_WUPMC7_MASK)

#define WUU_PMC_WUPMC8_MASK                      (0x100U)
#define WUU_PMC_WUPMC8_SHIFT                     (8U)
/*! WUPMC8 - Wake-up Pin Mode Configuration for WUU_Pn
 *  0b0..Active only during a low-leakage mode. You can modify the corresponding fields within Pin Enable (PEn) or
 *       Pin DMA/Trigger Configuration (PDCn).
 *  0b1..Active during all power modes. Do not modify the corresponding fields within Pin Enable (PEn) or Pin DMA/Trigger Configuration (PDCn).
 */
#define WUU_PMC_WUPMC8(x)                        (((uint32_t)(((uint32_t)(x)) << WUU_PMC_WUPMC8_SHIFT)) & WUU_PMC_WUPMC8_MASK)

#define WUU_PMC_WUPMC9_MASK                      (0x200U)
#define WUU_PMC_WUPMC9_SHIFT                     (9U)
/*! WUPMC9 - Wake-up Pin Mode Configuration for WUU_Pn
 *  0b0..Active only during a low-leakage mode. You can modify the corresponding fields within Pin Enable (PEn) or
 *       Pin DMA/Trigger Configuration (PDCn).
 *  0b1..Active during all power modes. Do not modify the corresponding fields within Pin Enable (PEn) or Pin DMA/Trigger Configuration (PDCn).
 */
#define WUU_PMC_WUPMC9(x)                        (((uint32_t)(((uint32_t)(x)) << WUU_PMC_WUPMC9_SHIFT)) & WUU_PMC_WUPMC9_MASK)

#define WUU_PMC_WUPMC10_MASK                     (0x400U)
#define WUU_PMC_WUPMC10_SHIFT                    (10U)
/*! WUPMC10 - Wake-up Pin Mode Configuration for WUU_Pn
 *  0b0..Active only during a low-leakage mode. You can modify the corresponding fields within Pin Enable (PEn) or
 *       Pin DMA/Trigger Configuration (PDCn).
 *  0b1..Active during all power modes. Do not modify the corresponding fields within Pin Enable (PEn) or Pin DMA/Trigger Configuration (PDCn).
 */
#define WUU_PMC_WUPMC10(x)                       (((uint32_t)(((uint32_t)(x)) << WUU_PMC_WUPMC10_SHIFT)) & WUU_PMC_WUPMC10_MASK)

#define WUU_PMC_WUPMC11_MASK                     (0x800U)
#define WUU_PMC_WUPMC11_SHIFT                    (11U)
/*! WUPMC11 - Wake-up Pin Mode Configuration for WUU_Pn
 *  0b0..Active only during a low-leakage mode. You can modify the corresponding fields within Pin Enable (PEn) or
 *       Pin DMA/Trigger Configuration (PDCn).
 *  0b1..Active during all power modes. Do not modify the corresponding fields within Pin Enable (PEn) or Pin DMA/Trigger Configuration (PDCn).
 */
#define WUU_PMC_WUPMC11(x)                       (((uint32_t)(((uint32_t)(x)) << WUU_PMC_WUPMC11_SHIFT)) & WUU_PMC_WUPMC11_MASK)

#define WUU_PMC_WUPMC12_MASK                     (0x1000U)
#define WUU_PMC_WUPMC12_SHIFT                    (12U)
/*! WUPMC12 - Wake-up Pin Mode Configuration for WUU_Pn
 *  0b0..Active only during a low-leakage mode. You can modify the corresponding fields within Pin Enable (PEn) or
 *       Pin DMA/Trigger Configuration (PDCn).
 *  0b1..Active during all power modes. Do not modify the corresponding fields within Pin Enable (PEn) or Pin DMA/Trigger Configuration (PDCn).
 */
#define WUU_PMC_WUPMC12(x)                       (((uint32_t)(((uint32_t)(x)) << WUU_PMC_WUPMC12_SHIFT)) & WUU_PMC_WUPMC12_MASK)

#define WUU_PMC_WUPMC13_MASK                     (0x2000U)
#define WUU_PMC_WUPMC13_SHIFT                    (13U)
/*! WUPMC13 - Wake-up Pin Mode Configuration for WUU_Pn
 *  0b0..Active only during a low-leakage mode. You can modify the corresponding fields within Pin Enable (PEn) or
 *       Pin DMA/Trigger Configuration (PDCn).
 *  0b1..Active during all power modes. Do not modify the corresponding fields within Pin Enable (PEn) or Pin DMA/Trigger Configuration (PDCn).
 */
#define WUU_PMC_WUPMC13(x)                       (((uint32_t)(((uint32_t)(x)) << WUU_PMC_WUPMC13_SHIFT)) & WUU_PMC_WUPMC13_MASK)

#define WUU_PMC_WUPMC14_MASK                     (0x4000U)
#define WUU_PMC_WUPMC14_SHIFT                    (14U)
/*! WUPMC14 - Wake-up Pin Mode Configuration for WUU_Pn
 *  0b0..Active only during a low-leakage mode. You can modify the corresponding fields within Pin Enable (PEn) or
 *       Pin DMA/Trigger Configuration (PDCn).
 *  0b1..Active during all power modes. Do not modify the corresponding fields within Pin Enable (PEn) or Pin DMA/Trigger Configuration (PDCn).
 */
#define WUU_PMC_WUPMC14(x)                       (((uint32_t)(((uint32_t)(x)) << WUU_PMC_WUPMC14_SHIFT)) & WUU_PMC_WUPMC14_MASK)

#define WUU_PMC_WUPMC15_MASK                     (0x8000U)
#define WUU_PMC_WUPMC15_SHIFT                    (15U)
/*! WUPMC15 - Wake-up Pin Mode Configuration for WUU_Pn
 *  0b0..Active only during a low-leakage mode. You can modify the corresponding fields within Pin Enable (PEn) or
 *       Pin DMA/Trigger Configuration (PDCn).
 *  0b1..Active during all power modes. Do not modify the corresponding fields within Pin Enable (PEn) or Pin DMA/Trigger Configuration (PDCn).
 */
#define WUU_PMC_WUPMC15(x)                       (((uint32_t)(((uint32_t)(x)) << WUU_PMC_WUPMC15_SHIFT)) & WUU_PMC_WUPMC15_MASK)

#define WUU_PMC_Reserved16_MASK                  (0x10000U)
#define WUU_PMC_Reserved16_SHIFT                 (16U)
/*! Reserved16 - Reserved
 *  0b0..Not supported
 *  0b1..Not supported
 */
#define WUU_PMC_Reserved16(x)                    (((uint32_t)(((uint32_t)(x)) << WUU_PMC_Reserved16_SHIFT)) & WUU_PMC_Reserved16_MASK)

#define WUU_PMC_WUPMC16_MASK                     (0x10000U)
#define WUU_PMC_WUPMC16_SHIFT                    (16U)
/*! WUPMC16 - Wake-up Pin Mode Configuration for WUU_Pn
 *  0b0..Active only during a low-leakage mode. You can modify the corresponding fields within Pin Enable (PEn) or
 *       Pin DMA/Trigger Configuration (PDCn).
 *  0b1..Active during all power modes. Do not modify the corresponding fields within Pin Enable (PEn) or Pin DMA/Trigger Configuration (PDCn).
 */
#define WUU_PMC_WUPMC16(x)                       (((uint32_t)(((uint32_t)(x)) << WUU_PMC_WUPMC16_SHIFT)) & WUU_PMC_WUPMC16_MASK)

#define WUU_PMC_Reserved17_MASK                  (0x20000U)
#define WUU_PMC_Reserved17_SHIFT                 (17U)
/*! Reserved17 - Reserved
 *  0b0..Not supported
 *  0b1..Not supported
 */
#define WUU_PMC_Reserved17(x)                    (((uint32_t)(((uint32_t)(x)) << WUU_PMC_Reserved17_SHIFT)) & WUU_PMC_Reserved17_MASK)

#define WUU_PMC_WUPMC17_MASK                     (0x20000U)
#define WUU_PMC_WUPMC17_SHIFT                    (17U)
/*! WUPMC17 - Wake-up Pin Mode Configuration for WUU_Pn
 *  0b0..Active only during a low-leakage mode. You can modify the corresponding fields within Pin Enable (PEn) or
 *       Pin DMA/Trigger Configuration (PDCn).
 *  0b1..Active during all power modes. Do not modify the corresponding fields within Pin Enable (PEn) or Pin DMA/Trigger Configuration (PDCn).
 */
#define WUU_PMC_WUPMC17(x)                       (((uint32_t)(((uint32_t)(x)) << WUU_PMC_WUPMC17_SHIFT)) & WUU_PMC_WUPMC17_MASK)

#define WUU_PMC_Reserved18_MASK                  (0x40000U)
#define WUU_PMC_Reserved18_SHIFT                 (18U)
/*! Reserved18 - Reserved
 *  0b0..Not supported
 *  0b1..Not supported
 */
#define WUU_PMC_Reserved18(x)                    (((uint32_t)(((uint32_t)(x)) << WUU_PMC_Reserved18_SHIFT)) & WUU_PMC_Reserved18_MASK)

#define WUU_PMC_WUPMC18_MASK                     (0x40000U)
#define WUU_PMC_WUPMC18_SHIFT                    (18U)
/*! WUPMC18 - Wake-up Pin Mode Configuration for WUU_Pn
 *  0b0..Active only during a low-leakage mode. You can modify the corresponding fields within Pin Enable (PEn) or
 *       Pin DMA/Trigger Configuration (PDCn).
 *  0b1..Active during all power modes. Do not modify the corresponding fields within Pin Enable (PEn) or Pin DMA/Trigger Configuration (PDCn).
 */
#define WUU_PMC_WUPMC18(x)                       (((uint32_t)(((uint32_t)(x)) << WUU_PMC_WUPMC18_SHIFT)) & WUU_PMC_WUPMC18_MASK)

#define WUU_PMC_Reserved19_MASK                  (0x80000U)
#define WUU_PMC_Reserved19_SHIFT                 (19U)
/*! Reserved19 - Reserved
 *  0b0..Not supported
 *  0b1..Not supported
 */
#define WUU_PMC_Reserved19(x)                    (((uint32_t)(((uint32_t)(x)) << WUU_PMC_Reserved19_SHIFT)) & WUU_PMC_Reserved19_MASK)

#define WUU_PMC_WUPMC19_MASK                     (0x80000U)
#define WUU_PMC_WUPMC19_SHIFT                    (19U)
/*! WUPMC19 - Wake-up Pin Mode Configuration for WUU_Pn
 *  0b0..Active only during a low-leakage mode. You can modify the corresponding fields within Pin Enable (PEn) or
 *       Pin DMA/Trigger Configuration (PDCn).
 *  0b1..Active during all power modes. Do not modify the corresponding fields within Pin Enable (PEn) or Pin DMA/Trigger Configuration (PDCn).
 */
#define WUU_PMC_WUPMC19(x)                       (((uint32_t)(((uint32_t)(x)) << WUU_PMC_WUPMC19_SHIFT)) & WUU_PMC_WUPMC19_MASK)

#define WUU_PMC_Reserved20_MASK                  (0x100000U)
#define WUU_PMC_Reserved20_SHIFT                 (20U)
/*! Reserved20 - Reserved
 *  0b0..Not supported
 *  0b1..Not supported
 */
#define WUU_PMC_Reserved20(x)                    (((uint32_t)(((uint32_t)(x)) << WUU_PMC_Reserved20_SHIFT)) & WUU_PMC_Reserved20_MASK)

#define WUU_PMC_WUPMC20_MASK                     (0x100000U)
#define WUU_PMC_WUPMC20_SHIFT                    (20U)
/*! WUPMC20 - Wake-up Pin Mode Configuration for WUU_Pn
 *  0b0..Active only during a low-leakage mode. You can modify the corresponding fields within Pin Enable (PEn) or
 *       Pin DMA/Trigger Configuration (PDCn).
 *  0b1..Active during all power modes. Do not modify the corresponding fields within Pin Enable (PEn) or Pin DMA/Trigger Configuration (PDCn).
 */
#define WUU_PMC_WUPMC20(x)                       (((uint32_t)(((uint32_t)(x)) << WUU_PMC_WUPMC20_SHIFT)) & WUU_PMC_WUPMC20_MASK)

#define WUU_PMC_Reserved21_MASK                  (0x200000U)
#define WUU_PMC_Reserved21_SHIFT                 (21U)
/*! Reserved21 - Reserved
 *  0b0..Not supported
 *  0b1..Not supported
 */
#define WUU_PMC_Reserved21(x)                    (((uint32_t)(((uint32_t)(x)) << WUU_PMC_Reserved21_SHIFT)) & WUU_PMC_Reserved21_MASK)

#define WUU_PMC_WUPMC21_MASK                     (0x200000U)
#define WUU_PMC_WUPMC21_SHIFT                    (21U)
/*! WUPMC21 - Wake-up Pin Mode Configuration for WUU_Pn
 *  0b0..Active only during a low-leakage mode. You can modify the corresponding fields within Pin Enable (PEn) or
 *       Pin DMA/Trigger Configuration (PDCn).
 *  0b1..Active during all power modes. Do not modify the corresponding fields within Pin Enable (PEn) or Pin DMA/Trigger Configuration (PDCn).
 */
#define WUU_PMC_WUPMC21(x)                       (((uint32_t)(((uint32_t)(x)) << WUU_PMC_WUPMC21_SHIFT)) & WUU_PMC_WUPMC21_MASK)

#define WUU_PMC_Reserved22_MASK                  (0x400000U)
#define WUU_PMC_Reserved22_SHIFT                 (22U)
/*! Reserved22 - Reserved
 *  0b0..Not supported
 *  0b1..Not supported
 */
#define WUU_PMC_Reserved22(x)                    (((uint32_t)(((uint32_t)(x)) << WUU_PMC_Reserved22_SHIFT)) & WUU_PMC_Reserved22_MASK)

#define WUU_PMC_WUPMC22_MASK                     (0x400000U)
#define WUU_PMC_WUPMC22_SHIFT                    (22U)
/*! WUPMC22 - Wake-up Pin Mode Configuration for WUU_Pn
 *  0b0..Active only during a low-leakage mode. You can modify the corresponding fields within Pin Enable (PEn) or
 *       Pin DMA/Trigger Configuration (PDCn).
 *  0b1..Active during all power modes. Do not modify the corresponding fields within Pin Enable (PEn) or Pin DMA/Trigger Configuration (PDCn).
 */
#define WUU_PMC_WUPMC22(x)                       (((uint32_t)(((uint32_t)(x)) << WUU_PMC_WUPMC22_SHIFT)) & WUU_PMC_WUPMC22_MASK)

#define WUU_PMC_Reserved23_MASK                  (0x800000U)
#define WUU_PMC_Reserved23_SHIFT                 (23U)
/*! Reserved23 - Reserved
 *  0b0..Not supported
 *  0b1..Not supported
 */
#define WUU_PMC_Reserved23(x)                    (((uint32_t)(((uint32_t)(x)) << WUU_PMC_Reserved23_SHIFT)) & WUU_PMC_Reserved23_MASK)

#define WUU_PMC_WUPMC23_MASK                     (0x800000U)
#define WUU_PMC_WUPMC23_SHIFT                    (23U)
/*! WUPMC23 - Wake-up Pin Mode Configuration for WUU_Pn
 *  0b0..Active only during a low-leakage mode. You can modify the corresponding fields within Pin Enable (PEn) or
 *       Pin DMA/Trigger Configuration (PDCn).
 *  0b1..Active during all power modes. Do not modify the corresponding fields within Pin Enable (PEn) or Pin DMA/Trigger Configuration (PDCn).
 */
#define WUU_PMC_WUPMC23(x)                       (((uint32_t)(((uint32_t)(x)) << WUU_PMC_WUPMC23_SHIFT)) & WUU_PMC_WUPMC23_MASK)

#define WUU_PMC_Reserved24_MASK                  (0x1000000U)
#define WUU_PMC_Reserved24_SHIFT                 (24U)
/*! Reserved24 - Reserved
 *  0b0..Not supported
 *  0b1..Not supported
 */
#define WUU_PMC_Reserved24(x)                    (((uint32_t)(((uint32_t)(x)) << WUU_PMC_Reserved24_SHIFT)) & WUU_PMC_Reserved24_MASK)

#define WUU_PMC_WUPMC24_MASK                     (0x1000000U)
#define WUU_PMC_WUPMC24_SHIFT                    (24U)
/*! WUPMC24 - Wake-up Pin Mode Configuration for WUU_Pn
 *  0b0..Active only during a low-leakage mode. You can modify the corresponding fields within Pin Enable (PEn) or
 *       Pin DMA/Trigger Configuration (PDCn).
 *  0b1..Active during all power modes. Do not modify the corresponding fields within Pin Enable (PEn) or Pin DMA/Trigger Configuration (PDCn).
 */
#define WUU_PMC_WUPMC24(x)                       (((uint32_t)(((uint32_t)(x)) << WUU_PMC_WUPMC24_SHIFT)) & WUU_PMC_WUPMC24_MASK)

#define WUU_PMC_Reserved25_MASK                  (0x2000000U)
#define WUU_PMC_Reserved25_SHIFT                 (25U)
/*! Reserved25 - Reserved
 *  0b0..Not supported
 *  0b1..Not supported
 */
#define WUU_PMC_Reserved25(x)                    (((uint32_t)(((uint32_t)(x)) << WUU_PMC_Reserved25_SHIFT)) & WUU_PMC_Reserved25_MASK)

#define WUU_PMC_WUPMC25_MASK                     (0x2000000U)
#define WUU_PMC_WUPMC25_SHIFT                    (25U)
/*! WUPMC25 - Wake-up Pin Mode Configuration for WUU_Pn
 *  0b0..Active only during a low-leakage mode. You can modify the corresponding fields within Pin Enable (PEn) or
 *       Pin DMA/Trigger Configuration (PDCn).
 *  0b1..Active during all power modes. Do not modify the corresponding fields within Pin Enable (PEn) or Pin DMA/Trigger Configuration (PDCn).
 */
#define WUU_PMC_WUPMC25(x)                       (((uint32_t)(((uint32_t)(x)) << WUU_PMC_WUPMC25_SHIFT)) & WUU_PMC_WUPMC25_MASK)

#define WUU_PMC_Reserved26_MASK                  (0x4000000U)
#define WUU_PMC_Reserved26_SHIFT                 (26U)
/*! Reserved26 - Reserved
 *  0b0..Not supported
 *  0b1..Not supported
 */
#define WUU_PMC_Reserved26(x)                    (((uint32_t)(((uint32_t)(x)) << WUU_PMC_Reserved26_SHIFT)) & WUU_PMC_Reserved26_MASK)

#define WUU_PMC_WUPMC26_MASK                     (0x4000000U)
#define WUU_PMC_WUPMC26_SHIFT                    (26U)
/*! WUPMC26 - Wake-up Pin Mode Configuration for WUU_Pn
 *  0b0..Active only during a low-leakage mode. You can modify the corresponding fields within Pin Enable (PEn) or
 *       Pin DMA/Trigger Configuration (PDCn).
 *  0b1..Active during all power modes. Do not modify the corresponding fields within Pin Enable (PEn) or Pin DMA/Trigger Configuration (PDCn).
 */
#define WUU_PMC_WUPMC26(x)                       (((uint32_t)(((uint32_t)(x)) << WUU_PMC_WUPMC26_SHIFT)) & WUU_PMC_WUPMC26_MASK)

#define WUU_PMC_Reserved27_MASK                  (0x8000000U)
#define WUU_PMC_Reserved27_SHIFT                 (27U)
/*! Reserved27 - Reserved
 *  0b0..Not supported
 *  0b1..Not supported
 */
#define WUU_PMC_Reserved27(x)                    (((uint32_t)(((uint32_t)(x)) << WUU_PMC_Reserved27_SHIFT)) & WUU_PMC_Reserved27_MASK)

#define WUU_PMC_WUPMC27_MASK                     (0x8000000U)
#define WUU_PMC_WUPMC27_SHIFT                    (27U)
/*! WUPMC27 - Wake-up Pin Mode Configuration for WUU_Pn
 *  0b0..Active only during a low-leakage mode. You can modify the corresponding fields within Pin Enable (PEn) or
 *       Pin DMA/Trigger Configuration (PDCn).
 *  0b1..Active during all power modes. Do not modify the corresponding fields within Pin Enable (PEn) or Pin DMA/Trigger Configuration (PDCn).
 */
#define WUU_PMC_WUPMC27(x)                       (((uint32_t)(((uint32_t)(x)) << WUU_PMC_WUPMC27_SHIFT)) & WUU_PMC_WUPMC27_MASK)

#define WUU_PMC_Reserved28_MASK                  (0x10000000U)
#define WUU_PMC_Reserved28_SHIFT                 (28U)
/*! Reserved28 - Reserved
 *  0b0..Not supported
 *  0b1..Not supported
 */
#define WUU_PMC_Reserved28(x)                    (((uint32_t)(((uint32_t)(x)) << WUU_PMC_Reserved28_SHIFT)) & WUU_PMC_Reserved28_MASK)

#define WUU_PMC_Reserved29_MASK                  (0x20000000U)
#define WUU_PMC_Reserved29_SHIFT                 (29U)
/*! Reserved29 - Reserved
 *  0b0..Not supported
 *  0b1..Not supported
 */
#define WUU_PMC_Reserved29(x)                    (((uint32_t)(((uint32_t)(x)) << WUU_PMC_Reserved29_SHIFT)) & WUU_PMC_Reserved29_MASK)

#define WUU_PMC_Reserved30_MASK                  (0x40000000U)
#define WUU_PMC_Reserved30_SHIFT                 (30U)
/*! Reserved30 - Reserved
 *  0b0..Not supported
 *  0b1..Not supported
 */
#define WUU_PMC_Reserved30(x)                    (((uint32_t)(((uint32_t)(x)) << WUU_PMC_Reserved30_SHIFT)) & WUU_PMC_Reserved30_MASK)

#define WUU_PMC_Reserved31_MASK                  (0x80000000U)
#define WUU_PMC_Reserved31_SHIFT                 (31U)
/*! Reserved31 - Reserved
 *  0b0..Not supported
 *  0b1..Not supported
 */
#define WUU_PMC_Reserved31(x)                    (((uint32_t)(((uint32_t)(x)) << WUU_PMC_Reserved31_SHIFT)) & WUU_PMC_Reserved31_MASK)
/*! @} */

/*! @name FMC - Pin Filter Mode Configuration */
/*! @{ */

#define WUU_FMC_FILTM1_MASK                      (0x1U)
#define WUU_FMC_FILTM1_SHIFT                     (0U)
/*! FILTM1 - Filter Mode for FILTn
 *  0b0..Active only during Power Down/Deep Power Down mode
 *  0b1..Active during all power modes
 */
#define WUU_FMC_FILTM1(x)                        (((uint32_t)(((uint32_t)(x)) << WUU_FMC_FILTM1_SHIFT)) & WUU_FMC_FILTM1_MASK)

#define WUU_FMC_FILTM2_MASK                      (0x2U)
#define WUU_FMC_FILTM2_SHIFT                     (1U)
/*! FILTM2 - Filter Mode for FILTn
 *  0b0..Active only during Power Down/Deep Power Down mode
 *  0b1..Active during all power modes
 */
#define WUU_FMC_FILTM2(x)                        (((uint32_t)(((uint32_t)(x)) << WUU_FMC_FILTM2_SHIFT)) & WUU_FMC_FILTM2_MASK)

#define WUU_FMC_FILTM3_MASK                      (0x4U)
#define WUU_FMC_FILTM3_SHIFT                     (2U)
/*! FILTM3 - Filter Mode for FILTn
 *  0b0..Active only during Power Down/Deep Power Down mode
 *  0b1..Active during all power modes
 */
#define WUU_FMC_FILTM3(x)                        (((uint32_t)(((uint32_t)(x)) << WUU_FMC_FILTM3_SHIFT)) & WUU_FMC_FILTM3_MASK)

#define WUU_FMC_FILTM4_MASK                      (0x8U)
#define WUU_FMC_FILTM4_SHIFT                     (3U)
/*! FILTM4 - Filter Mode for FILTn
 *  0b0..Active only during Power Down/Deep Power Down mode
 *  0b1..Active during all power modes
 */
#define WUU_FMC_FILTM4(x)                        (((uint32_t)(((uint32_t)(x)) << WUU_FMC_FILTM4_SHIFT)) & WUU_FMC_FILTM4_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group WUU_Register_Masks */


/*!
 * @}
 */ /* end of group WUU_Peripheral_Access_Layer */


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


#endif  /* PERI_WUU_H_ */

