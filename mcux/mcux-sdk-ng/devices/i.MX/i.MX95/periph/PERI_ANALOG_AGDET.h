/*
** ###################################################################
**     Processors:          MIMX9594AVZXN_ca55
**                          MIMX9594AVZXN_cm33
**                          MIMX9594AVZXN_cm7
**                          MIMX9596AVTXN_ca55
**                          MIMX9596AVTXN_cm33
**                          MIMX9596AVTXN_cm7
**                          MIMX9596AVYXN_ca55
**                          MIMX9596AVYXN_cm33
**                          MIMX9596AVYXN_cm7
**                          MIMX9596AVZXN_ca55
**                          MIMX9596AVZXN_cm33
**                          MIMX9596AVZXN_cm7
**                          MIMX9596CVTXN_ca55
**                          MIMX9596CVTXN_cm33
**                          MIMX9596CVTXN_cm7
**                          MIMX9596CVYXN_ca55
**                          MIMX9596CVYXN_cm33
**                          MIMX9596CVYXN_cm7
**                          MIMX9596CVZXN_ca55
**                          MIMX9596CVZXN_cm33
**                          MIMX9596CVZXN_cm7
**                          MIMX9596DVTXN_ca55
**                          MIMX9596DVTXN_cm33
**                          MIMX9596DVTXN_cm7
**                          MIMX9596DVYXN_ca55
**                          MIMX9596DVYXN_cm33
**                          MIMX9596DVYXN_cm7
**                          MIMX9596DVYXQ_ca55
**                          MIMX9596DVYXQ_cm33
**                          MIMX9596DVYXQ_cm7
**                          MIMX9596DVZXN_ca55
**                          MIMX9596DVZXN_cm33
**                          MIMX9596DVZXN_cm7
**                          MIMX9596XVTXN_ca55
**                          MIMX9596XVTXN_cm33
**                          MIMX9596XVTXN_cm7
**                          MIMX9596XVYXN_ca55
**                          MIMX9596XVYXN_cm33
**                          MIMX9596XVYXN_cm7
**                          MIMX9596XVZXN_ca55
**                          MIMX9596XVZXN_cm33
**                          MIMX9596XVZXN_cm7
**
**     Version:             rev. 1.0, 2023-01-10
**     Build:               b240728
**
**     Abstract:
**         CMSIS Peripheral Access Layer for ANALOG_AGDET
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2023-01-10)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file ANALOG_AGDET.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for ANALOG_AGDET
 *
 * CMSIS Peripheral Access Layer for ANALOG_AGDET
 */

#if !defined(ANALOG_AGDET_H_)
#define ANALOG_AGDET_H_                          /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX9594AVZXN_ca55))
#include "MIMX9594_ca55_COMMON.h"
#elif (defined(CPU_MIMX9594AVZXN_cm33))
#include "MIMX9594_cm33_COMMON.h"
#elif (defined(CPU_MIMX9594AVZXN_cm7))
#include "MIMX9594_cm7_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_ca55) || defined(CPU_MIMX9596AVYXN_ca55) || defined(CPU_MIMX9596AVZXN_ca55) || defined(CPU_MIMX9596CVTXN_ca55) || defined(CPU_MIMX9596CVYXN_ca55) || defined(CPU_MIMX9596CVZXN_ca55) || defined(CPU_MIMX9596DVTXN_ca55) || defined(CPU_MIMX9596DVYXN_ca55) || defined(CPU_MIMX9596DVYXQ_ca55) || defined(CPU_MIMX9596DVZXN_ca55) || defined(CPU_MIMX9596XVTXN_ca55) || defined(CPU_MIMX9596XVYXN_ca55) || defined(CPU_MIMX9596XVZXN_ca55))
#include "MIMX9596_ca55_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_cm33) || defined(CPU_MIMX9596AVYXN_cm33) || defined(CPU_MIMX9596AVZXN_cm33) || defined(CPU_MIMX9596CVTXN_cm33) || defined(CPU_MIMX9596CVYXN_cm33) || defined(CPU_MIMX9596CVZXN_cm33) || defined(CPU_MIMX9596DVTXN_cm33) || defined(CPU_MIMX9596DVYXN_cm33) || defined(CPU_MIMX9596DVYXQ_cm33) || defined(CPU_MIMX9596DVZXN_cm33) || defined(CPU_MIMX9596XVTXN_cm33) || defined(CPU_MIMX9596XVYXN_cm33) || defined(CPU_MIMX9596XVZXN_cm33))
#include "MIMX9596_cm33_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_cm7) || defined(CPU_MIMX9596AVYXN_cm7) || defined(CPU_MIMX9596AVZXN_cm7) || defined(CPU_MIMX9596CVTXN_cm7) || defined(CPU_MIMX9596CVYXN_cm7) || defined(CPU_MIMX9596CVZXN_cm7) || defined(CPU_MIMX9596DVTXN_cm7) || defined(CPU_MIMX9596DVYXN_cm7) || defined(CPU_MIMX9596DVYXQ_cm7) || defined(CPU_MIMX9596DVZXN_cm7) || defined(CPU_MIMX9596XVTXN_cm7) || defined(CPU_MIMX9596XVYXN_cm7) || defined(CPU_MIMX9596XVZXN_cm7))
#include "MIMX9596_cm7_COMMON.h"
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
   -- ANALOG_AGDET Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ANALOG_AGDET_Peripheral_Access_Layer ANALOG_AGDET Peripheral Access Layer
 * @{
 */

/** ANALOG_AGDET - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[4];
  __IO uint32_t GD_TEST;                           /**< Glitch Detector Test Register, offset: 0x4 */
  __IO uint32_t GD_MISC;                           /**< Glitch Detector MISC Register, offset: 0x8 */
       uint8_t RESERVED_1[500];
  __IO uint32_t GD_CTRL;                           /**< Glitch Detector Control Register, offset: 0x200 */
} ANALOG_AGDET_Type;

/* ----------------------------------------------------------------------------
   -- ANALOG_AGDET Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ANALOG_AGDET_Register_Masks ANALOG_AGDET Register Masks
 * @{
 */

/*! @name GD_TEST - Glitch Detector Test Register */
/*! @{ */

#define ANALOG_AGDET_GD_TEST_TEST_EN_MASK        (0x1U)
#define ANALOG_AGDET_GD_TEST_TEST_EN_SHIFT       (0U)
/*! TEST_EN - Enable Signal Of Self-Test
 *  0b0..Disable glitch detector self-test
 *  0b1..Enable glitch detector self-test
 */
#define ANALOG_AGDET_GD_TEST_TEST_EN(x)          (((uint32_t)(((uint32_t)(x)) << ANALOG_AGDET_GD_TEST_TEST_EN_SHIFT)) & ANALOG_AGDET_GD_TEST_TEST_EN_MASK)

#define ANALOG_AGDET_GD_TEST_TEST_VOLTAGE_SEL_MASK (0xF0U)
#define ANALOG_AGDET_GD_TEST_TEST_VOLTAGE_SEL_SHIFT (4U)
/*! TEST_VOLTAGE_SEL - Test Glitch Voltage Selection
 *  0b0000..select the test glitch voltage 0
 *  0b0001..select the test glitch voltage 1
 *  0b0010..select the test glitch voltage 2
 *  0b0011..select the test glitch voltage 3
 *  0b0100..select the test glitch voltage 4
 *  0b0101..select the test glitch voltage 5
 *  0b0110..select the test glitch voltage 6
 *  0b0111..select the test glitch voltage 7
 *  0b1000..select the test glitch voltage 8
 *  0b1001..select the test glitch voltage 9
 *  0b1010..select the test glitch voltage 10
 *  0b1011..select the test glitch voltage 11
 *  0b1100..select the test glitch voltage 12
 *  0b1101..select the test glitch voltage 13
 *  0b1110..select the test glitch voltage 14
 *  0b1111..select the test glitch voltage 15
 */
#define ANALOG_AGDET_GD_TEST_TEST_VOLTAGE_SEL(x) (((uint32_t)(((uint32_t)(x)) << ANALOG_AGDET_GD_TEST_TEST_VOLTAGE_SEL_SHIFT)) & ANALOG_AGDET_GD_TEST_TEST_VOLTAGE_SEL_MASK)

#define ANALOG_AGDET_GD_TEST_TEST_DONE_MASK      (0x100U)
#define ANALOG_AGDET_GD_TEST_TEST_DONE_SHIFT     (8U)
/*! TEST_DONE - Self-Test Done
 *  0b0..Self-test is not done
 *  0b1..Self-test is done
 */
#define ANALOG_AGDET_GD_TEST_TEST_DONE(x)        (((uint32_t)(((uint32_t)(x)) << ANALOG_AGDET_GD_TEST_TEST_DONE_SHIFT)) & ANALOG_AGDET_GD_TEST_TEST_DONE_MASK)

#define ANALOG_AGDET_GD_TEST_TEST_NEG_DETECTED_MASK (0x400U)
#define ANALOG_AGDET_GD_TEST_TEST_NEG_DETECTED_SHIFT (10U)
/*! TEST_NEG_DETECTED - Test Negative Glitch Detect Flag
 *  0b0..Neg edge is not detected during test
 *  0b1..Neg edge is detected during test
 */
#define ANALOG_AGDET_GD_TEST_TEST_NEG_DETECTED(x) (((uint32_t)(((uint32_t)(x)) << ANALOG_AGDET_GD_TEST_TEST_NEG_DETECTED_SHIFT)) & ANALOG_AGDET_GD_TEST_TEST_NEG_DETECTED_MASK)

#define ANALOG_AGDET_GD_TEST_TEST_POS_DETECTED_MASK (0x800U)
#define ANALOG_AGDET_GD_TEST_TEST_POS_DETECTED_SHIFT (11U)
/*! TEST_POS_DETECTED - Test Positive Glitch Detect Flag
 *  0b0..Pos edge is not detected in during self-test
 *  0b1..Pos edge is detected in during self-test
 */
#define ANALOG_AGDET_GD_TEST_TEST_POS_DETECTED(x) (((uint32_t)(((uint32_t)(x)) << ANALOG_AGDET_GD_TEST_TEST_POS_DETECTED_SHIFT)) & ANALOG_AGDET_GD_TEST_TEST_POS_DETECTED_MASK)

#define ANALOG_AGDET_GD_TEST_TEST_SEL_MASK       (0xF00000U)
#define ANALOG_AGDET_GD_TEST_TEST_SEL_SHIFT      (20U)
/*! TEST_SEL - Test Mode Item Selection
 *  0b0000..Enter positive glitch self-test mode when GD_TEST[TEST_EN]=1
 *  0b0001..Enter negative glitch self-test mode when GD_TEST[TEST_EN]=1
 *  0b0010..BG bias current is conducted to ATX when GD_TEST[TEST_EN]=1
 *  0b0011..Reserved
 *  0b0100..Negedge threshold is conducted to ATX when GD_TEST[TEST_EN]=1
 *  0b0101..Posedge threshold is conducted to ATX when GD_TEST[TEST_EN]=1
 *  0b0110..No function, for further extension
 *  0b0111..No function, for further extension
 *  0b1000..vddsoc is conducted to ATX when GD_TEST[TEST_EN]=1
 */
#define ANALOG_AGDET_GD_TEST_TEST_SEL(x)         (((uint32_t)(((uint32_t)(x)) << ANALOG_AGDET_GD_TEST_TEST_SEL_SHIFT)) & ANALOG_AGDET_GD_TEST_TEST_SEL_MASK)

#define ANALOG_AGDET_GD_TEST_TEST_DURATION_SEL_MASK (0xFF000000U)
#define ANALOG_AGDET_GD_TEST_TEST_DURATION_SEL_SHIFT (24U)
/*! TEST_DURATION_SEL - Test Duration Selection
 *  0b00000000..The duration of test glitch is configured to (3.3 x 1)ns
 *  0b00000001..The duration of test glitch is configured to (3.3 x 2)ns
 *  0b00000010..The duration of test glitch is configured to (3.3 x 3)ns
 *  0b00000011..The duration of test glitch is configured to (3.3 x 4)ns
 *  0b00000100..The duration of test glitch is configured to (3.3 x 5)ns
 *  0b00000101..The duration of test glitch is configured to (3.3 x 6)ns
 *  0b00000110..The duration of test glitch is configured to (3.3 x 7)ns
 *  0b00000111..The duration of test glitch is configured to (3.3 x 8)ns
 *  0b00001000..The duration of test glitch is configured to (3.3 x 9)ns
 *  0b00001001..The duration of test glitch is configured to (3.3 x 10)ns
 */
#define ANALOG_AGDET_GD_TEST_TEST_DURATION_SEL(x) (((uint32_t)(((uint32_t)(x)) << ANALOG_AGDET_GD_TEST_TEST_DURATION_SEL_SHIFT)) & ANALOG_AGDET_GD_TEST_TEST_DURATION_SEL_MASK)
/*! @} */

/*! @name GD_MISC - Glitch Detector MISC Register */
/*! @{ */

#define ANALOG_AGDET_GD_MISC_glitch_det_trim_MASK (0xFF000000U)
#define ANALOG_AGDET_GD_MISC_glitch_det_trim_SHIFT (24U)
/*! glitch_det_trim - Glitch Detector Trim
 *  0b00000000..Glitch_det_trim
 */
#define ANALOG_AGDET_GD_MISC_glitch_det_trim(x)  (((uint32_t)(((uint32_t)(x)) << ANALOG_AGDET_GD_MISC_glitch_det_trim_SHIFT)) & ANALOG_AGDET_GD_MISC_glitch_det_trim_MASK)
/*! @} */

/*! @name GD_CTRL - Glitch Detector Control Register */
/*! @{ */

#define ANALOG_AGDET_GD_CTRL_ENABLE_MASK         (0x1U)
#define ANALOG_AGDET_GD_CTRL_ENABLE_SHIFT        (0U)
/*! ENABLE - Enable Signal For Glitch Detector
 *  0b0..Glitch detector is disabled
 *  0b1..Glitch detector is enabled
 */
#define ANALOG_AGDET_GD_CTRL_ENABLE(x)           (((uint32_t)(((uint32_t)(x)) << ANALOG_AGDET_GD_CTRL_ENABLE_SHIFT)) & ANALOG_AGDET_GD_CTRL_ENABLE_MASK)

#define ANALOG_AGDET_GD_CTRL_RST_LATCH_MASK      (0x2U)
#define ANALOG_AGDET_GD_CTRL_RST_LATCH_SHIFT     (1U)
/*! RST_LATCH - Reset Glitch Detector Output
 *  0b1..Write logic 1 to this bit resets the glitch detector output
 */
#define ANALOG_AGDET_GD_CTRL_RST_LATCH(x)        (((uint32_t)(((uint32_t)(x)) << ANALOG_AGDET_GD_CTRL_RST_LATCH_SHIFT)) & ANALOG_AGDET_GD_CTRL_RST_LATCH_MASK)

#define ANALOG_AGDET_GD_CTRL_TH_LO_TRIM_MASK     (0xF00U)
#define ANALOG_AGDET_GD_CTRL_TH_LO_TRIM_SHIFT    (8U)
/*! TH_LO_TRIM - Trim Code For Negative Edge Threshold
 *  0b0000..Sel trim code 0 for negative glitch threshold
 *  0b0001..Sel trim code 1 for negative glitch threshold
 *  0b0010..Sel trim code 2 for negative glitch threshold
 *  0b0011..Sel trim code 3 for negative glitch threshold
 *  0b0100..Sel trim code 4 for negative glitch threshold
 *  0b0101..Sel trim code 5 for negative glitch threshold
 *  0b0110..Sel trim code 6 for negative glitch threshold
 *  0b0111..Sel trim code 7 for negative glitch threshold
 *  0b1000..Sel trim code 8 for negative glitch threshold
 *  0b1001..Sel trim code 9 for negative glitch threshold
 *  0b1010..Sel trim code 10 for negative glitch threshold
 *  0b1011..Sel trim code 11 for negative glitch threshold
 *  0b1100..Sel trim code 12 for negative glitch threshold
 *  0b1101..Sel trim code 13 for negative glitch threshold
 *  0b1110..Sel trim code 14 for negative glitch threshold
 *  0b1111..Sel trim code 15 for negative glitch threshold
 */
#define ANALOG_AGDET_GD_CTRL_TH_LO_TRIM(x)       (((uint32_t)(((uint32_t)(x)) << ANALOG_AGDET_GD_CTRL_TH_LO_TRIM_SHIFT)) & ANALOG_AGDET_GD_CTRL_TH_LO_TRIM_MASK)

#define ANALOG_AGDET_GD_CTRL_TH_HI_TRIM_MASK     (0xF000U)
#define ANALOG_AGDET_GD_CTRL_TH_HI_TRIM_SHIFT    (12U)
/*! TH_HI_TRIM - Trim Code for Positive Edge Threshold
 *  0b0000..Sel trim code 0 for positive glitch threshold
 *  0b0001..Sel trim code 1 for positive glitch threshold
 *  0b0010..Sel trim code 2 for positive glitch threshold
 *  0b0011..Sel trim code 3 for positive glitch threshold
 *  0b0100..Sel trim code 4 for positive glitch threshold
 *  0b0101..Sel trim code 5 for positive glitch threshold
 *  0b0110..Sel trim code 6 for positive glitch threshold
 *  0b0111..Sel trim code 7 for positive glitch threshold
 *  0b1000..Sel trim code 8 for positive glitch threshold
 *  0b1001..Sel trim code 9 for positive glitch threshold
 *  0b1010..Sel trim code 10 for positive glitch threshold
 *  0b1011..Sel trim code 11 for positive glitch threshold
 *  0b1100..Sel trim code 12 for positive glitch threshold
 *  0b1101..Sel trim code 13 for positive glitch threshold
 *  0b1110..Sel trim code 14 for positive glitch threshold
 *  0b1111..Sel trim code 15 for positive glitch threshold
 */
#define ANALOG_AGDET_GD_CTRL_TH_HI_TRIM(x)       (((uint32_t)(((uint32_t)(x)) << ANALOG_AGDET_GD_CTRL_TH_HI_TRIM_SHIFT)) & ANALOG_AGDET_GD_CTRL_TH_HI_TRIM_MASK)

#define ANALOG_AGDET_GD_CTRL_NEG_DETECTED_MASK   (0x10000U)
#define ANALOG_AGDET_GD_CTRL_NEG_DETECTED_SHIFT  (16U)
/*! NEG_DETECTED - Negedge Detected Flag
 *  0b0..Negedge is not detected on vdd_soc
 *  0b1..Negedge is detected on vdd_soc
 */
#define ANALOG_AGDET_GD_CTRL_NEG_DETECTED(x)     (((uint32_t)(((uint32_t)(x)) << ANALOG_AGDET_GD_CTRL_NEG_DETECTED_SHIFT)) & ANALOG_AGDET_GD_CTRL_NEG_DETECTED_MASK)

#define ANALOG_AGDET_GD_CTRL_POS_DETECTED_MASK   (0x20000U)
#define ANALOG_AGDET_GD_CTRL_POS_DETECTED_SHIFT  (17U)
/*! POS_DETECTED - Posedge Detected Flag
 *  0b0..Posedge is not detected on vdd_soc
 *  0b1..Posedge is detected on vdd_soc
 */
#define ANALOG_AGDET_GD_CTRL_POS_DETECTED(x)     (((uint32_t)(((uint32_t)(x)) << ANALOG_AGDET_GD_CTRL_POS_DETECTED_SHIFT)) & ANALOG_AGDET_GD_CTRL_POS_DETECTED_MASK)

#define ANALOG_AGDET_GD_CTRL_NEG_DET_MASK_MASK   (0x1000000U)
#define ANALOG_AGDET_GD_CTRL_NEG_DET_MASK_SHIFT  (24U)
/*! NEG_DET_MASK - Mask the Negative Glitch Detection
 *  0b0..Detection is enabled
 *  0b1..Detection is disabled
 */
#define ANALOG_AGDET_GD_CTRL_NEG_DET_MASK(x)     (((uint32_t)(((uint32_t)(x)) << ANALOG_AGDET_GD_CTRL_NEG_DET_MASK_SHIFT)) & ANALOG_AGDET_GD_CTRL_NEG_DET_MASK_MASK)

#define ANALOG_AGDET_GD_CTRL_POS_DET_MASK_MASK   (0x2000000U)
#define ANALOG_AGDET_GD_CTRL_POS_DET_MASK_SHIFT  (25U)
/*! POS_DET_MASK - Mask the Positive Glitch Detection
 *  0b0..Detection is enabled
 *  0b1..Detection is disabled
 */
#define ANALOG_AGDET_GD_CTRL_POS_DET_MASK(x)     (((uint32_t)(((uint32_t)(x)) << ANALOG_AGDET_GD_CTRL_POS_DET_MASK_SHIFT)) & ANALOG_AGDET_GD_CTRL_POS_DET_MASK_MASK)

#define ANALOG_AGDET_GD_CTRL_AUTO_RST_MASK       (0x10000000U)
#define ANALOG_AGDET_GD_CTRL_AUTO_RST_SHIFT      (28U)
/*! AUTO_RST - Auto Reset Analog Latches After Enablement
 *  0b0..There is an auto reset on analog latches, before glitch detector is ready
 *  0b1..No internal analog latches reset
 */
#define ANALOG_AGDET_GD_CTRL_AUTO_RST(x)         (((uint32_t)(((uint32_t)(x)) << ANALOG_AGDET_GD_CTRL_AUTO_RST_SHIFT)) & ANALOG_AGDET_GD_CTRL_AUTO_RST_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group ANALOG_AGDET_Register_Masks */


/*!
 * @}
 */ /* end of group ANALOG_AGDET_Peripheral_Access_Layer */


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


#endif  /* ANALOG_AGDET_H_ */

