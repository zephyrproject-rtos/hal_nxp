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
**     Version:             rev. 5.0, 2023-04-27
**     Build:               b240823
**
**     Abstract:
**         CMSIS Peripheral Access Layer for DAC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
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
**
** ###################################################################
*/

/*!
 * @file DAC.h
 * @version 5.0
 * @date 2023-04-27
 * @brief CMSIS Peripheral Access Layer for DAC
 *
 * CMSIS Peripheral Access Layer for DAC
 */

#if !defined(DAC_H_)
#define DAC_H_                                   /**< Symbol preventing repeated inclusion */

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
   -- DAC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DAC_Peripheral_Access_Layer DAC Peripheral Access Layer
 * @{
 */

/** DAC - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< Version Identifier Register, offset: 0x0 */
  __I  uint32_t PARAM;                             /**< Parameter Register, offset: 0x4 */
  __O  uint32_t DATA;                              /**< DAC Data Register, offset: 0x8 */
  __IO uint32_t CR;                                /**< DAC Status and Control Register, offset: 0xC */
  __I  uint32_t PTR;                               /**< DAC FIFO Pointer Register, offset: 0x10 */
  __IO uint32_t CR2;                               /**< DAC Status and Control Register 2, offset: 0x14 */
} DAC_Type;

/* ----------------------------------------------------------------------------
   -- DAC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DAC_Register_Masks DAC Register Masks
 * @{
 */

/*! @name VERID - Version Identifier Register */
/*! @{ */

#define DAC_VERID_FEATURE_MASK                   (0xFFFFU)
#define DAC_VERID_FEATURE_SHIFT                  (0U)
/*! FEATURE - Feature Identification Number
 *  0b0000000000000000..Standard feature set
 *  0b0000000000000001..C40 feature set
 *  0b0000000000000010..5V DAC feature set
 *  0b0000000000000100..ADC BIST feature set
 */
#define DAC_VERID_FEATURE(x)                     (((uint32_t)(((uint32_t)(x)) << DAC_VERID_FEATURE_SHIFT)) & DAC_VERID_FEATURE_MASK)

#define DAC_VERID_MINOR_MASK                     (0xFF0000U)
#define DAC_VERID_MINOR_SHIFT                    (16U)
/*! MINOR - Minor version number */
#define DAC_VERID_MINOR(x)                       (((uint32_t)(((uint32_t)(x)) << DAC_VERID_MINOR_SHIFT)) & DAC_VERID_MINOR_MASK)

#define DAC_VERID_MAJOR_MASK                     (0xFF000000U)
#define DAC_VERID_MAJOR_SHIFT                    (24U)
/*! MAJOR - Major version number */
#define DAC_VERID_MAJOR(x)                       (((uint32_t)(((uint32_t)(x)) << DAC_VERID_MAJOR_SHIFT)) & DAC_VERID_MAJOR_MASK)
/*! @} */

/*! @name PARAM - Parameter Register */
/*! @{ */

#define DAC_PARAM_FIFOSZ_MASK                    (0x7U)
#define DAC_PARAM_FIFOSZ_SHIFT                   (0U)
/*! FIFOSZ - FIFO size
 *  0b000..FIFO depth is 2
 *  0b001..FIFO depth is 4
 *  0b010..FIFO depth is 8
 *  0b011..FIFO depth is 16
 *  0b100..FIFO depth is 32
 *  0b101..FIFO depth is 64
 *  0b110..FIFO depth is 128
 *  0b111..FIFO depth is 256
 */
#define DAC_PARAM_FIFOSZ(x)                      (((uint32_t)(((uint32_t)(x)) << DAC_PARAM_FIFOSZ_SHIFT)) & DAC_PARAM_FIFOSZ_MASK)
/*! @} */

/*! @name DATA - DAC Data Register */
/*! @{ */

#define DAC_DATA_DATA0_MASK                      (0xFFFU)
#define DAC_DATA_DATA0_SHIFT                     (0U)
/*! DATA0 - FIFO DATA0 */
#define DAC_DATA_DATA0(x)                        (((uint32_t)(((uint32_t)(x)) << DAC_DATA_DATA0_SHIFT)) & DAC_DATA_DATA0_MASK)
/*! @} */

/*! @name CR - DAC Status and Control Register */
/*! @{ */

#define DAC_CR_FULLF_MASK                        (0x1U)
#define DAC_CR_FULLF_SHIFT                       (0U)
/*! FULLF - Full Flag
 *  0b0..FIFO is not full.
 *  0b1..FIFO is full.
 */
#define DAC_CR_FULLF(x)                          (((uint32_t)(((uint32_t)(x)) << DAC_CR_FULLF_SHIFT)) & DAC_CR_FULLF_MASK)

#define DAC_CR_NEMPTF_MASK                       (0x2U)
#define DAC_CR_NEMPTF_SHIFT                      (1U)
/*! NEMPTF - Nearly Empty Flag
 *  0b0..More than one data is available in the FIFO.
 *  0b1..One data is available in the FIFO.
 */
#define DAC_CR_NEMPTF(x)                         (((uint32_t)(((uint32_t)(x)) << DAC_CR_NEMPTF_SHIFT)) & DAC_CR_NEMPTF_MASK)

#define DAC_CR_WMF_MASK                          (0x4U)
#define DAC_CR_WMF_SHIFT                         (2U)
/*! WMF - FIFO Watermark Status Flag
 *  0b0..The DAC buffer read pointer has not reached the watermark level.
 *  0b1..The DAC buffer read pointer has reached the watermark level.
 */
#define DAC_CR_WMF(x)                            (((uint32_t)(((uint32_t)(x)) << DAC_CR_WMF_SHIFT)) & DAC_CR_WMF_MASK)

#define DAC_CR_UDFF_MASK                         (0x8U)
#define DAC_CR_UDFF_SHIFT                        (3U)
/*! UDFF - Underflow Flag
 *  0b0..No underflow has occurred since the last time the flag was cleared.
 *  0b1..At least one trigger underflow has occurred since the last time the flag was cleared.
 */
#define DAC_CR_UDFF(x)                           (((uint32_t)(((uint32_t)(x)) << DAC_CR_UDFF_SHIFT)) & DAC_CR_UDFF_MASK)

#define DAC_CR_OVFF_MASK                         (0x10U)
#define DAC_CR_OVFF_SHIFT                        (4U)
/*! OVFF - Overflow Flag
 *  0b0..No overflow has occurred since the last time the flag was cleared.
 *  0b1..At least one FIFO overflow has occurred since the last time the flag was cleared.
 */
#define DAC_CR_OVFF(x)                           (((uint32_t)(((uint32_t)(x)) << DAC_CR_OVFF_SHIFT)) & DAC_CR_OVFF_MASK)

#define DAC_CR_FULLIE_MASK                       (0x100U)
#define DAC_CR_FULLIE_SHIFT                      (8U)
/*! FULLIE - Full Interrupt Enable
 *  0b0..FIFO Full interrupt is disabled.
 *  0b1..FIFO Full interrupt is enabled.
 */
#define DAC_CR_FULLIE(x)                         (((uint32_t)(((uint32_t)(x)) << DAC_CR_FULLIE_SHIFT)) & DAC_CR_FULLIE_MASK)

#define DAC_CR_EMPTIE_MASK                       (0x200U)
#define DAC_CR_EMPTIE_SHIFT                      (9U)
/*! EMPTIE - Nearly Empty Interrupt Enable
 *  0b0..FIFO Nearly Empty interrupt is disabled.
 *  0b1..FIFO Nearly Empty interrupt is enabled.
 */
#define DAC_CR_EMPTIE(x)                         (((uint32_t)(((uint32_t)(x)) << DAC_CR_EMPTIE_SHIFT)) & DAC_CR_EMPTIE_MASK)

#define DAC_CR_WTMIE_MASK                        (0x400U)
#define DAC_CR_WTMIE_SHIFT                       (10U)
/*! WTMIE - Watermark Interrupt Enable
 *  0b0..Watermark interrupt is disabled.
 *  0b1..Watermark interrupt is enabled.
 */
#define DAC_CR_WTMIE(x)                          (((uint32_t)(((uint32_t)(x)) << DAC_CR_WTMIE_SHIFT)) & DAC_CR_WTMIE_MASK)

#define DAC_CR_SWTRG_MASK                        (0x1000U)
#define DAC_CR_SWTRG_SHIFT                       (12U)
/*! SWTRG - DAC Software Trigger
 *  0b0..The DAC soft trigger is not valid.
 *  0b1..The DAC soft trigger is valid.
 */
#define DAC_CR_SWTRG(x)                          (((uint32_t)(((uint32_t)(x)) << DAC_CR_SWTRG_SHIFT)) & DAC_CR_SWTRG_MASK)

#define DAC_CR_TRGSEL_MASK                       (0x2000U)
#define DAC_CR_TRGSEL_SHIFT                      (13U)
/*! TRGSEL - DAC Trigger Select
 *  0b0..The DAC hardware trigger is selected.
 *  0b1..The DAC software trigger is selected.
 */
#define DAC_CR_TRGSEL(x)                         (((uint32_t)(((uint32_t)(x)) << DAC_CR_TRGSEL_SHIFT)) & DAC_CR_TRGSEL_MASK)

#define DAC_CR_DACRFS_MASK                       (0x4000U)
#define DAC_CR_DACRFS_SHIFT                      (14U)
/*! DACRFS - DAC Reference Select
 *  0b0..The DAC selects DACREF_1 as the reference voltage.
 *  0b1..The DAC selects DACREF_2 as the reference voltage.
 */
#define DAC_CR_DACRFS(x)                         (((uint32_t)(((uint32_t)(x)) << DAC_CR_DACRFS_SHIFT)) & DAC_CR_DACRFS_MASK)

#define DAC_CR_DACEN_MASK                        (0x8000U)
#define DAC_CR_DACEN_SHIFT                       (15U)
/*! DACEN - DAC Enable
 *  0b0..The DAC system is disabled.
 *  0b1..The DAC system is enabled.
 */
#define DAC_CR_DACEN(x)                          (((uint32_t)(((uint32_t)(x)) << DAC_CR_DACEN_SHIFT)) & DAC_CR_DACEN_MASK)

#define DAC_CR_FIFOEN_MASK                       (0x10000U)
#define DAC_CR_FIFOEN_SHIFT                      (16U)
/*! FIFOEN - FIFO Enable
 *  0b0..FIFO is disabled and only one level buffer is enabled. Any data written from this buffer goes to conversion.
 *  0b1..FIFO is enabled. Data will first read from FIFO to buffer then go to conversion.
 */
#define DAC_CR_FIFOEN(x)                         (((uint32_t)(((uint32_t)(x)) << DAC_CR_FIFOEN_SHIFT)) & DAC_CR_FIFOEN_MASK)

#define DAC_CR_SWMD_MASK                         (0x20000U)
#define DAC_CR_SWMD_SHIFT                        (17U)
/*! SWMD - DAC FIFO Mode Select
 *  0b0..Normal mode
 *  0b1..Swing back mode
 */
#define DAC_CR_SWMD(x)                           (((uint32_t)(((uint32_t)(x)) << DAC_CR_SWMD_SHIFT)) & DAC_CR_SWMD_MASK)

#define DAC_CR_UVIE_MASK                         (0x40000U)
#define DAC_CR_UVIE_SHIFT                        (18U)
/*! UVIE - Underflow and overflow interrupt enable
 *  0b0..Underflow and overflow interrupt is disabled.
 *  0b1..Underflow and overflow interrupt is enabled.
 */
#define DAC_CR_UVIE(x)                           (((uint32_t)(((uint32_t)(x)) << DAC_CR_UVIE_SHIFT)) & DAC_CR_UVIE_MASK)

#define DAC_CR_FIFORST_MASK                      (0x200000U)
#define DAC_CR_FIFORST_SHIFT                     (21U)
/*! FIFORST - FIFO Reset
 *  0b0..No effect
 *  0b1..FIFO reset
 */
#define DAC_CR_FIFORST(x)                        (((uint32_t)(((uint32_t)(x)) << DAC_CR_FIFORST_SHIFT)) & DAC_CR_FIFORST_MASK)

#define DAC_CR_SWRST_MASK                        (0x400000U)
#define DAC_CR_SWRST_SHIFT                       (22U)
/*! SWRST - Software reset */
#define DAC_CR_SWRST(x)                          (((uint32_t)(((uint32_t)(x)) << DAC_CR_SWRST_SHIFT)) & DAC_CR_SWRST_MASK)

#define DAC_CR_DMAEN_MASK                        (0x800000U)
#define DAC_CR_DMAEN_SHIFT                       (23U)
/*! DMAEN - DMA Enable Select
 *  0b0..DMA is disabled.
 *  0b1..DMA is enabled. When DMA is enabled, the DMA request will be generated by original interrupts. The
 *       interrupts will not be presented on this module at the same time.
 */
#define DAC_CR_DMAEN(x)                          (((uint32_t)(((uint32_t)(x)) << DAC_CR_DMAEN_SHIFT)) & DAC_CR_DMAEN_MASK)

#define DAC_CR_WML_MASK                          (0xFF000000U)
#define DAC_CR_WML_SHIFT                         (24U)
/*! WML - Watermark Level Select */
#define DAC_CR_WML(x)                            (((uint32_t)(((uint32_t)(x)) << DAC_CR_WML_SHIFT)) & DAC_CR_WML_MASK)
/*! @} */

/*! @name PTR - DAC FIFO Pointer Register */
/*! @{ */

#define DAC_PTR_DACWFP_MASK                      (0xFFU)
#define DAC_PTR_DACWFP_SHIFT                     (0U)
/*! DACWFP - DACWFP */
#define DAC_PTR_DACWFP(x)                        (((uint32_t)(((uint32_t)(x)) << DAC_PTR_DACWFP_SHIFT)) & DAC_PTR_DACWFP_MASK)

#define DAC_PTR_DACRFP_MASK                      (0xFF0000U)
#define DAC_PTR_DACRFP_SHIFT                     (16U)
/*! DACRFP - DACRFP */
#define DAC_PTR_DACRFP(x)                        (((uint32_t)(((uint32_t)(x)) << DAC_PTR_DACRFP_SHIFT)) & DAC_PTR_DACRFP_MASK)
/*! @} */

/*! @name CR2 - DAC Status and Control Register 2 */
/*! @{ */

#define DAC_CR2_BFEN_MASK                        (0x1U)
#define DAC_CR2_BFEN_SHIFT                       (0U)
/*! BFEN - Buffer Enable
 *  0b0..Opamp is not used as buffer
 *  0b1..Opamp is used as buffer
 */
#define DAC_CR2_BFEN(x)                          (((uint32_t)(((uint32_t)(x)) << DAC_CR2_BFEN_SHIFT)) & DAC_CR2_BFEN_MASK)

#define DAC_CR2_OEN_MASK                         (0x2U)
#define DAC_CR2_OEN_SHIFT                        (1U)
/*! OEN - Optional Enable
 *  0b0..Output buffer is not bypassed
 *  0b1..Output buffer is bypassed
 */
#define DAC_CR2_OEN(x)                           (((uint32_t)(((uint32_t)(x)) << DAC_CR2_OEN_SHIFT)) & DAC_CR2_OEN_MASK)

#define DAC_CR2_BFMS_MASK                        (0x4U)
#define DAC_CR2_BFMS_SHIFT                       (2U)
/*! BFMS - Buffer Middle Speed Select
 *  0b0..Buffer middle speed not selected
 *  0b1..Buffer middle speed selected
 */
#define DAC_CR2_BFMS(x)                          (((uint32_t)(((uint32_t)(x)) << DAC_CR2_BFMS_SHIFT)) & DAC_CR2_BFMS_MASK)

#define DAC_CR2_BFHS_MASK                        (0x8U)
#define DAC_CR2_BFHS_SHIFT                       (3U)
/*! BFHS - Buffer High Speed Select
 *  0b0..Buffer high speed not selected
 *  0b1..Buffer high speed selected
 */
#define DAC_CR2_BFHS(x)                          (((uint32_t)(((uint32_t)(x)) << DAC_CR2_BFHS_SHIFT)) & DAC_CR2_BFHS_MASK)

#define DAC_CR2_IREF2_MASK                       (0x10U)
#define DAC_CR2_IREF2_SHIFT                      (4U)
/*! IREF2 - Internal PTAT (Proportional To Absolute Temperature) Current Reference Select
 *  0b0..Internal PTAT Current Reference not selected
 *  0b1..Internal PTAT Current Reference selected
 */
#define DAC_CR2_IREF2(x)                         (((uint32_t)(((uint32_t)(x)) << DAC_CR2_IREF2_SHIFT)) & DAC_CR2_IREF2_MASK)

#define DAC_CR2_IREF1_MASK                       (0x20U)
#define DAC_CR2_IREF1_SHIFT                      (5U)
/*! IREF1 - Internal ZTC (Zero Temperature Coefficient) Current Reference Select
 *  0b0..Internal ZTC Current Reference not selected
 *  0b1..Internal ZTC Current Reference selected
 */
#define DAC_CR2_IREF1(x)                         (((uint32_t)(((uint32_t)(x)) << DAC_CR2_IREF1_SHIFT)) & DAC_CR2_IREF1_MASK)

#define DAC_CR2_IREF_MASK                        (0x40U)
#define DAC_CR2_IREF_SHIFT                       (6U)
/*! IREF - Internal Current Reference Select
 *  0b0..Internal Current Reference not selected
 *  0b1..Internal Current Reference selected
 */
#define DAC_CR2_IREF(x)                          (((uint32_t)(((uint32_t)(x)) << DAC_CR2_IREF_SHIFT)) & DAC_CR2_IREF_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group DAC_Register_Masks */


/*!
 * @}
 */ /* end of group DAC_Peripheral_Access_Layer */


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


#endif  /* DAC_H_ */

