/*
** ###################################################################
**     Processors:          MIMXRT1051CVJ5B
**                          MIMXRT1051CVL5B
**                          MIMXRT1051DVJ6B
**                          MIMXRT1051DVL6B
**                          MIMXRT1052CVJ5B
**                          MIMXRT1052CVL5B
**                          MIMXRT1052DVJ6B
**                          MIMXRT1052DVL6B
**                          MIMXRT105SDVL6B
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for TSC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 0.1 (2017-01-10)
**         Initial version.
**     - rev. 1.0 (2018-09-21)
**         Update interrupt vector table and dma request source.
**         Update register BEE_ADDR_OFFSET1's bitfield name to ADDR_OFFSET1.
**         Split GPIO_COMBINED_IRQS to GPIO_COMBINED_LOW_IRQS and GPIO_COMBINED_HIGH_IRQS.
**     - rev. 1.1 (2018-11-16)
**         Update header files to align with IMXRT1050RM Rev.1.
**     - rev. 1.2 (2018-11-27)
**         Update header files to align with IMXRT1050RM Rev.2.1.
**     - rev. 1.3 (2019-04-29)
**         Add SET/CLR/TOG register group to register CTRL, STAT, CHANNELCTRL, CH0STAT, CH0OPTS, CH1STAT, CH1OPTS, CH2STAT, CH2OPTS, CH3STAT, CH3OPTS of DCP module.
**     - rev. 1.4 (2021-08-10)
**         Update header files to align with IMXRT1050RM Rev.5.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_TSC.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for TSC
 *
 * CMSIS Peripheral Access Layer for TSC
 */

#if !defined(PERI_TSC_H_)
#define PERI_TSC_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT1051CVJ5B) || defined(CPU_MIMXRT1051CVL5B) || defined(CPU_MIMXRT1051DVJ6B) || defined(CPU_MIMXRT1051DVL6B))
#include "MIMXRT1051_COMMON.h"
#elif (defined(CPU_MIMXRT1052CVJ5B) || defined(CPU_MIMXRT1052CVL5B) || defined(CPU_MIMXRT1052DVJ6B) || defined(CPU_MIMXRT1052DVL6B))
#include "MIMXRT1052_COMMON.h"
#elif (defined(CPU_MIMXRT105SDVL6B))
#include "MIMXRT105S_COMMON.h"
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
#elif defined(__CWCC__)
  #pragma push
  #pragma cpp_extensions on
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=extended
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- TSC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TSC_Peripheral_Access_Layer TSC Peripheral Access Layer
 * @{
 */

/** TSC - Register Layout Typedef */
typedef struct {
  __IO uint32_t BASIC_SETTING;                     /**< Basic Setting, offset: 0x0 */
       uint8_t RESERVED_0[12];
  __IO uint32_t PRE_CHARGE_TIME;                   /**< Pre-charge Time, offset: 0x10 */
       uint8_t RESERVED_1[12];
  __IO uint32_t FLOW_CONTROL;                      /**< Flow Control, offset: 0x20 */
       uint8_t RESERVED_2[12];
  __I  uint32_t MEASEURE_VALUE;                    /**< Measure Value, offset: 0x30 */
       uint8_t RESERVED_3[12];
  __IO uint32_t INT_EN;                            /**< Interrupt Enable, offset: 0x40 */
       uint8_t RESERVED_4[12];
  __IO uint32_t INT_SIG_EN;                        /**< Interrupt Signal Enable, offset: 0x50 */
       uint8_t RESERVED_5[12];
  __IO uint32_t INT_STATUS;                        /**< Intterrupt Status, offset: 0x60 */
       uint8_t RESERVED_6[12];
  __IO uint32_t DEBUG_MODE;                        /**< Debug Mode Register, offset: 0x70 */
       uint8_t RESERVED_7[12];
  __IO uint32_t DEBUG_MODE2;                       /**< Debug Mode Register 2, offset: 0x80 */
} TSC_Type;

/* ----------------------------------------------------------------------------
   -- TSC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TSC_Register_Masks TSC Register Masks
 * @{
 */

/*! @name BASIC_SETTING - Basic Setting */
/*! @{ */

#define TSC_BASIC_SETTING_AUTO_MEASURE_MASK      (0x1U)
#define TSC_BASIC_SETTING_AUTO_MEASURE_SHIFT     (0U)
/*! AUTO_MEASURE - Auto Measure
 *  0b0..Disable Auto Measure
 *  0b1..Auto Measure
 */
#define TSC_BASIC_SETTING_AUTO_MEASURE(x)        (((uint32_t)(((uint32_t)(x)) << TSC_BASIC_SETTING_AUTO_MEASURE_SHIFT)) & TSC_BASIC_SETTING_AUTO_MEASURE_MASK)

#define TSC_BASIC_SETTING_WIRE_4_5_MASK          (0x10U)
#define TSC_BASIC_SETTING_WIRE_4_5_SHIFT         (4U)
/*! WIRE_4_5 - 4/5 Wire detection
 *  0b0..4-Wire Detection Mode
 *  0b1..5-Wire Detection Mode
 */
#define TSC_BASIC_SETTING_WIRE_4_5(x)            (((uint32_t)(((uint32_t)(x)) << TSC_BASIC_SETTING_WIRE_4_5_SHIFT)) & TSC_BASIC_SETTING_WIRE_4_5_MASK)

#define TSC_BASIC_SETTING_MEASURE_DELAY_TIME_MASK (0xFFFFFF00U)
#define TSC_BASIC_SETTING_MEASURE_DELAY_TIME_SHIFT (8U)
/*! MEASURE_DELAY_TIME - Measure Delay Time */
#define TSC_BASIC_SETTING_MEASURE_DELAY_TIME(x)  (((uint32_t)(((uint32_t)(x)) << TSC_BASIC_SETTING_MEASURE_DELAY_TIME_SHIFT)) & TSC_BASIC_SETTING_MEASURE_DELAY_TIME_MASK)
/*! @} */

/*! @name PRE_CHARGE_TIME - Pre-charge Time */
/*! @{ */

#define TSC_PRE_CHARGE_TIME_PRE_CHARGE_TIME_MASK (0xFFFFFFFFU)
#define TSC_PRE_CHARGE_TIME_PRE_CHARGE_TIME_SHIFT (0U)
#define TSC_PRE_CHARGE_TIME_PRE_CHARGE_TIME(x)   (((uint32_t)(((uint32_t)(x)) << TSC_PRE_CHARGE_TIME_PRE_CHARGE_TIME_SHIFT)) & TSC_PRE_CHARGE_TIME_PRE_CHARGE_TIME_MASK)
/*! @} */

/*! @name FLOW_CONTROL - Flow Control */
/*! @{ */

#define TSC_FLOW_CONTROL_SW_RST_MASK             (0x1U)
#define TSC_FLOW_CONTROL_SW_RST_SHIFT            (0U)
/*! SW_RST - Soft Reset */
#define TSC_FLOW_CONTROL_SW_RST(x)               (((uint32_t)(((uint32_t)(x)) << TSC_FLOW_CONTROL_SW_RST_SHIFT)) & TSC_FLOW_CONTROL_SW_RST_MASK)

#define TSC_FLOW_CONTROL_START_MEASURE_MASK      (0x10U)
#define TSC_FLOW_CONTROL_START_MEASURE_SHIFT     (4U)
/*! START_MEASURE - Start Measure
 *  0b0..Do not start measure for now
 *  0b1..Start measure the X/Y coordinate value
 */
#define TSC_FLOW_CONTROL_START_MEASURE(x)        (((uint32_t)(((uint32_t)(x)) << TSC_FLOW_CONTROL_START_MEASURE_SHIFT)) & TSC_FLOW_CONTROL_START_MEASURE_MASK)

#define TSC_FLOW_CONTROL_DROP_MEASURE_MASK       (0x100U)
#define TSC_FLOW_CONTROL_DROP_MEASURE_SHIFT      (8U)
/*! DROP_MEASURE - Drop Measure
 *  0b0..Do not drop measure for now
 *  0b1..Drop the measure and controller return to idle status
 */
#define TSC_FLOW_CONTROL_DROP_MEASURE(x)         (((uint32_t)(((uint32_t)(x)) << TSC_FLOW_CONTROL_DROP_MEASURE_SHIFT)) & TSC_FLOW_CONTROL_DROP_MEASURE_MASK)

#define TSC_FLOW_CONTROL_START_SENSE_MASK        (0x1000U)
#define TSC_FLOW_CONTROL_START_SENSE_SHIFT       (12U)
/*! START_SENSE - Start Sense
 *  0b0..Stay at idle status
 *  0b1..Start sense detection and (if auto_measure set to 1) measure after detect a touch
 */
#define TSC_FLOW_CONTROL_START_SENSE(x)          (((uint32_t)(((uint32_t)(x)) << TSC_FLOW_CONTROL_START_SENSE_SHIFT)) & TSC_FLOW_CONTROL_START_SENSE_MASK)

#define TSC_FLOW_CONTROL_DISABLE_MASK            (0x10000U)
#define TSC_FLOW_CONTROL_DISABLE_SHIFT           (16U)
/*! DISABLE
 *  0b0..Leave HW state machine control
 *  0b1..SW set to idle status
 */
#define TSC_FLOW_CONTROL_DISABLE(x)              (((uint32_t)(((uint32_t)(x)) << TSC_FLOW_CONTROL_DISABLE_SHIFT)) & TSC_FLOW_CONTROL_DISABLE_MASK)
/*! @} */

/*! @name MEASEURE_VALUE - Measure Value */
/*! @{ */

#define TSC_MEASEURE_VALUE_Y_VALUE_MASK          (0xFFFU)
#define TSC_MEASEURE_VALUE_Y_VALUE_SHIFT         (0U)
/*! Y_VALUE - Y Value */
#define TSC_MEASEURE_VALUE_Y_VALUE(x)            (((uint32_t)(((uint32_t)(x)) << TSC_MEASEURE_VALUE_Y_VALUE_SHIFT)) & TSC_MEASEURE_VALUE_Y_VALUE_MASK)

#define TSC_MEASEURE_VALUE_X_VALUE_MASK          (0xFFF0000U)
#define TSC_MEASEURE_VALUE_X_VALUE_SHIFT         (16U)
/*! X_VALUE - X Value */
#define TSC_MEASEURE_VALUE_X_VALUE(x)            (((uint32_t)(((uint32_t)(x)) << TSC_MEASEURE_VALUE_X_VALUE_SHIFT)) & TSC_MEASEURE_VALUE_X_VALUE_MASK)
/*! @} */

/*! @name INT_EN - Interrupt Enable */
/*! @{ */

#define TSC_INT_EN_MEASURE_INT_EN_MASK           (0x1U)
#define TSC_INT_EN_MEASURE_INT_EN_SHIFT          (0U)
/*! MEASURE_INT_EN - Measure Interrupt Enable
 *  0b0..Disable measure interrupt
 *  0b1..Enable measure interrupt
 */
#define TSC_INT_EN_MEASURE_INT_EN(x)             (((uint32_t)(((uint32_t)(x)) << TSC_INT_EN_MEASURE_INT_EN_SHIFT)) & TSC_INT_EN_MEASURE_INT_EN_MASK)

#define TSC_INT_EN_DETECT_INT_EN_MASK            (0x10U)
#define TSC_INT_EN_DETECT_INT_EN_SHIFT           (4U)
/*! DETECT_INT_EN - Detect Interrupt Enable
 *  0b0..Disable detect interrupt
 *  0b1..Enable detect interrupt
 */
#define TSC_INT_EN_DETECT_INT_EN(x)              (((uint32_t)(((uint32_t)(x)) << TSC_INT_EN_DETECT_INT_EN_SHIFT)) & TSC_INT_EN_DETECT_INT_EN_MASK)

#define TSC_INT_EN_IDLE_SW_INT_EN_MASK           (0x1000U)
#define TSC_INT_EN_IDLE_SW_INT_EN_SHIFT          (12U)
/*! IDLE_SW_INT_EN - Idle Software Interrupt Enable
 *  0b0..Disable idle software interrupt
 *  0b1..Enable idle software interrupt
 */
#define TSC_INT_EN_IDLE_SW_INT_EN(x)             (((uint32_t)(((uint32_t)(x)) << TSC_INT_EN_IDLE_SW_INT_EN_SHIFT)) & TSC_INT_EN_IDLE_SW_INT_EN_MASK)
/*! @} */

/*! @name INT_SIG_EN - Interrupt Signal Enable */
/*! @{ */

#define TSC_INT_SIG_EN_MEASURE_SIG_EN_MASK       (0x1U)
#define TSC_INT_SIG_EN_MEASURE_SIG_EN_SHIFT      (0U)
/*! MEASURE_SIG_EN - Measure Signal Enable */
#define TSC_INT_SIG_EN_MEASURE_SIG_EN(x)         (((uint32_t)(((uint32_t)(x)) << TSC_INT_SIG_EN_MEASURE_SIG_EN_SHIFT)) & TSC_INT_SIG_EN_MEASURE_SIG_EN_MASK)

#define TSC_INT_SIG_EN_DETECT_SIG_EN_MASK        (0x10U)
#define TSC_INT_SIG_EN_DETECT_SIG_EN_SHIFT       (4U)
/*! DETECT_SIG_EN - Detect Signal Enable
 *  0b0..Disable detect signal
 *  0b1..Enable detect signal
 */
#define TSC_INT_SIG_EN_DETECT_SIG_EN(x)          (((uint32_t)(((uint32_t)(x)) << TSC_INT_SIG_EN_DETECT_SIG_EN_SHIFT)) & TSC_INT_SIG_EN_DETECT_SIG_EN_MASK)

#define TSC_INT_SIG_EN_VALID_SIG_EN_MASK         (0x100U)
#define TSC_INT_SIG_EN_VALID_SIG_EN_SHIFT        (8U)
/*! VALID_SIG_EN - Valid Signal Enable
 *  0b0..Disable valid signal
 *  0b1..Enable valid signal
 */
#define TSC_INT_SIG_EN_VALID_SIG_EN(x)           (((uint32_t)(((uint32_t)(x)) << TSC_INT_SIG_EN_VALID_SIG_EN_SHIFT)) & TSC_INT_SIG_EN_VALID_SIG_EN_MASK)

#define TSC_INT_SIG_EN_IDLE_SW_SIG_EN_MASK       (0x1000U)
#define TSC_INT_SIG_EN_IDLE_SW_SIG_EN_SHIFT      (12U)
/*! IDLE_SW_SIG_EN - Idle Software Signal Enable
 *  0b0..Disable idle software signal
 *  0b1..Enable idle software signal
 */
#define TSC_INT_SIG_EN_IDLE_SW_SIG_EN(x)         (((uint32_t)(((uint32_t)(x)) << TSC_INT_SIG_EN_IDLE_SW_SIG_EN_SHIFT)) & TSC_INT_SIG_EN_IDLE_SW_SIG_EN_MASK)
/*! @} */

/*! @name INT_STATUS - Intterrupt Status */
/*! @{ */

#define TSC_INT_STATUS_MEASURE_MASK              (0x1U)
#define TSC_INT_STATUS_MEASURE_SHIFT             (0U)
/*! MEASURE - Measure Signal
 *  0b0..Does not exist a measure signal
 *  0b1..Exist a measure signal
 */
#define TSC_INT_STATUS_MEASURE(x)                (((uint32_t)(((uint32_t)(x)) << TSC_INT_STATUS_MEASURE_SHIFT)) & TSC_INT_STATUS_MEASURE_MASK)

#define TSC_INT_STATUS_DETECT_MASK               (0x10U)
#define TSC_INT_STATUS_DETECT_SHIFT              (4U)
/*! DETECT - Detect Signal
 *  0b0..Does not exist a detect signal
 *  0b1..Exist detect signal
 */
#define TSC_INT_STATUS_DETECT(x)                 (((uint32_t)(((uint32_t)(x)) << TSC_INT_STATUS_DETECT_SHIFT)) & TSC_INT_STATUS_DETECT_MASK)

#define TSC_INT_STATUS_VALID_MASK                (0x100U)
#define TSC_INT_STATUS_VALID_SHIFT               (8U)
/*! VALID - Valid Signal
 *  0b0..There is no touch detected after measurement, indicates that the measured value is not valid
 *  0b1..There is touch detection after measurement, indicates that the measure is valid
 */
#define TSC_INT_STATUS_VALID(x)                  (((uint32_t)(((uint32_t)(x)) << TSC_INT_STATUS_VALID_SHIFT)) & TSC_INT_STATUS_VALID_MASK)

#define TSC_INT_STATUS_IDLE_SW_MASK              (0x1000U)
#define TSC_INT_STATUS_IDLE_SW_SHIFT             (12U)
/*! IDLE_SW - Idle Software
 *  0b0..Haven't return to idle status
 *  0b1..Already return to idle status
 */
#define TSC_INT_STATUS_IDLE_SW(x)                (((uint32_t)(((uint32_t)(x)) << TSC_INT_STATUS_IDLE_SW_SHIFT)) & TSC_INT_STATUS_IDLE_SW_MASK)
/*! @} */

/*! @name DEBUG_MODE - Debug Mode Register */
/*! @{ */

#define TSC_DEBUG_MODE_ADC_CONV_VALUE_MASK       (0xFFFU)
#define TSC_DEBUG_MODE_ADC_CONV_VALUE_SHIFT      (0U)
/*! ADC_CONV_VALUE - ADC Conversion Value */
#define TSC_DEBUG_MODE_ADC_CONV_VALUE(x)         (((uint32_t)(((uint32_t)(x)) << TSC_DEBUG_MODE_ADC_CONV_VALUE_SHIFT)) & TSC_DEBUG_MODE_ADC_CONV_VALUE_MASK)

#define TSC_DEBUG_MODE_ADC_COCO_MASK             (0x1000U)
#define TSC_DEBUG_MODE_ADC_COCO_SHIFT            (12U)
/*! ADC_COCO - ADC COCO Signal */
#define TSC_DEBUG_MODE_ADC_COCO(x)               (((uint32_t)(((uint32_t)(x)) << TSC_DEBUG_MODE_ADC_COCO_SHIFT)) & TSC_DEBUG_MODE_ADC_COCO_MASK)

#define TSC_DEBUG_MODE_EXT_HWTS_MASK             (0x1F0000U)
#define TSC_DEBUG_MODE_EXT_HWTS_SHIFT            (16U)
/*! EXT_HWTS - Hardware Trigger Select Signal */
#define TSC_DEBUG_MODE_EXT_HWTS(x)               (((uint32_t)(((uint32_t)(x)) << TSC_DEBUG_MODE_EXT_HWTS_SHIFT)) & TSC_DEBUG_MODE_EXT_HWTS_MASK)

#define TSC_DEBUG_MODE_TRIGGER_MASK              (0x1000000U)
#define TSC_DEBUG_MODE_TRIGGER_SHIFT             (24U)
/*! TRIGGER - Trigger
 *  0b0..No hardware trigger signal
 *  0b1..Hardware trigger signal, the signal must last at least 1 ips clock period
 */
#define TSC_DEBUG_MODE_TRIGGER(x)                (((uint32_t)(((uint32_t)(x)) << TSC_DEBUG_MODE_TRIGGER_SHIFT)) & TSC_DEBUG_MODE_TRIGGER_MASK)

#define TSC_DEBUG_MODE_ADC_COCO_CLEAR_MASK       (0x2000000U)
#define TSC_DEBUG_MODE_ADC_COCO_CLEAR_SHIFT      (25U)
/*! ADC_COCO_CLEAR - ADC Coco Clear
 *  0b0..No ADC COCO clear
 *  0b1..Set ADC COCO clear
 */
#define TSC_DEBUG_MODE_ADC_COCO_CLEAR(x)         (((uint32_t)(((uint32_t)(x)) << TSC_DEBUG_MODE_ADC_COCO_CLEAR_SHIFT)) & TSC_DEBUG_MODE_ADC_COCO_CLEAR_MASK)

#define TSC_DEBUG_MODE_ADC_COCO_CLEAR_DISABLE_MASK (0x4000000U)
#define TSC_DEBUG_MODE_ADC_COCO_CLEAR_DISABLE_SHIFT (26U)
/*! ADC_COCO_CLEAR_DISABLE - ADC COCO Clear Disable
 *  0b0..Allow TSC hardware generates ADC COCO clear
 *  0b1..Prevent TSC from generate ADC COCO clear signal
 */
#define TSC_DEBUG_MODE_ADC_COCO_CLEAR_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << TSC_DEBUG_MODE_ADC_COCO_CLEAR_DISABLE_SHIFT)) & TSC_DEBUG_MODE_ADC_COCO_CLEAR_DISABLE_MASK)

#define TSC_DEBUG_MODE_DEBUG_EN_MASK             (0x10000000U)
#define TSC_DEBUG_MODE_DEBUG_EN_SHIFT            (28U)
/*! DEBUG_EN - Debug Enable
 *  0b0..Enable debug mode
 *  0b1..Disable debug mode
 */
#define TSC_DEBUG_MODE_DEBUG_EN(x)               (((uint32_t)(((uint32_t)(x)) << TSC_DEBUG_MODE_DEBUG_EN_SHIFT)) & TSC_DEBUG_MODE_DEBUG_EN_MASK)
/*! @} */

/*! @name DEBUG_MODE2 - Debug Mode Register 2 */
/*! @{ */

#define TSC_DEBUG_MODE2_XPUL_PULL_DOWN_MASK      (0x1U)
#define TSC_DEBUG_MODE2_XPUL_PULL_DOWN_SHIFT     (0U)
/*! XPUL_PULL_DOWN - XPUL Wire Pull Down Switch
 *  0b0..Close the switch
 *  0b1..Open up the switch
 */
#define TSC_DEBUG_MODE2_XPUL_PULL_DOWN(x)        (((uint32_t)(((uint32_t)(x)) << TSC_DEBUG_MODE2_XPUL_PULL_DOWN_SHIFT)) & TSC_DEBUG_MODE2_XPUL_PULL_DOWN_MASK)

#define TSC_DEBUG_MODE2_XPUL_PULL_UP_MASK        (0x2U)
#define TSC_DEBUG_MODE2_XPUL_PULL_UP_SHIFT       (1U)
/*! XPUL_PULL_UP - XPUL Wire Pull Up Switch
 *  0b0..Close the switch
 *  0b1..Open up the switch
 */
#define TSC_DEBUG_MODE2_XPUL_PULL_UP(x)          (((uint32_t)(((uint32_t)(x)) << TSC_DEBUG_MODE2_XPUL_PULL_UP_SHIFT)) & TSC_DEBUG_MODE2_XPUL_PULL_UP_MASK)

#define TSC_DEBUG_MODE2_XPUL_200K_PULL_UP_MASK   (0x4U)
#define TSC_DEBUG_MODE2_XPUL_200K_PULL_UP_SHIFT  (2U)
/*! XPUL_200K_PULL_UP - XPUL Wire 200K Pull Up Switch
 *  0b0..Close the switch
 *  0b1..Open up the switch
 */
#define TSC_DEBUG_MODE2_XPUL_200K_PULL_UP(x)     (((uint32_t)(((uint32_t)(x)) << TSC_DEBUG_MODE2_XPUL_200K_PULL_UP_SHIFT)) & TSC_DEBUG_MODE2_XPUL_200K_PULL_UP_MASK)

#define TSC_DEBUG_MODE2_XNUR_PULL_DOWN_MASK      (0x8U)
#define TSC_DEBUG_MODE2_XNUR_PULL_DOWN_SHIFT     (3U)
/*! XNUR_PULL_DOWN - XNUR Wire Pull Down Switch
 *  0b0..Close the switch
 *  0b1..Open up the switch
 */
#define TSC_DEBUG_MODE2_XNUR_PULL_DOWN(x)        (((uint32_t)(((uint32_t)(x)) << TSC_DEBUG_MODE2_XNUR_PULL_DOWN_SHIFT)) & TSC_DEBUG_MODE2_XNUR_PULL_DOWN_MASK)

#define TSC_DEBUG_MODE2_XNUR_PULL_UP_MASK        (0x10U)
#define TSC_DEBUG_MODE2_XNUR_PULL_UP_SHIFT       (4U)
/*! XNUR_PULL_UP - XNUR Wire Pull Up Switch
 *  0b0..Close the switch
 *  0b1..Open up the switch
 */
#define TSC_DEBUG_MODE2_XNUR_PULL_UP(x)          (((uint32_t)(((uint32_t)(x)) << TSC_DEBUG_MODE2_XNUR_PULL_UP_SHIFT)) & TSC_DEBUG_MODE2_XNUR_PULL_UP_MASK)

#define TSC_DEBUG_MODE2_XNUR_200K_PULL_UP_MASK   (0x20U)
#define TSC_DEBUG_MODE2_XNUR_200K_PULL_UP_SHIFT  (5U)
/*! XNUR_200K_PULL_UP - XNUR Wire 200K Pull Up Switch
 *  0b0..Close the switch
 *  0b1..Open up the switch
 */
#define TSC_DEBUG_MODE2_XNUR_200K_PULL_UP(x)     (((uint32_t)(((uint32_t)(x)) << TSC_DEBUG_MODE2_XNUR_200K_PULL_UP_SHIFT)) & TSC_DEBUG_MODE2_XNUR_200K_PULL_UP_MASK)

#define TSC_DEBUG_MODE2_YPLL_PULL_DOWN_MASK      (0x40U)
#define TSC_DEBUG_MODE2_YPLL_PULL_DOWN_SHIFT     (6U)
/*! YPLL_PULL_DOWN - YPLL Wire Pull Down Switch
 *  0b0..Close the switch
 *  0b1..Open up the switch
 */
#define TSC_DEBUG_MODE2_YPLL_PULL_DOWN(x)        (((uint32_t)(((uint32_t)(x)) << TSC_DEBUG_MODE2_YPLL_PULL_DOWN_SHIFT)) & TSC_DEBUG_MODE2_YPLL_PULL_DOWN_MASK)

#define TSC_DEBUG_MODE2_YPLL_PULL_UP_MASK        (0x80U)
#define TSC_DEBUG_MODE2_YPLL_PULL_UP_SHIFT       (7U)
/*! YPLL_PULL_UP - YPLL Wire Pull Up Switch
 *  0b0..Close the switch
 *  0b1..Open the switch
 */
#define TSC_DEBUG_MODE2_YPLL_PULL_UP(x)          (((uint32_t)(((uint32_t)(x)) << TSC_DEBUG_MODE2_YPLL_PULL_UP_SHIFT)) & TSC_DEBUG_MODE2_YPLL_PULL_UP_MASK)

#define TSC_DEBUG_MODE2_YPLL_200K_PULL_UP_MASK   (0x100U)
#define TSC_DEBUG_MODE2_YPLL_200K_PULL_UP_SHIFT  (8U)
/*! YPLL_200K_PULL_UP - YPLL Wire 200K Pull Up Switch
 *  0b0..Close the switch
 *  0b1..Open up the switch
 */
#define TSC_DEBUG_MODE2_YPLL_200K_PULL_UP(x)     (((uint32_t)(((uint32_t)(x)) << TSC_DEBUG_MODE2_YPLL_200K_PULL_UP_SHIFT)) & TSC_DEBUG_MODE2_YPLL_200K_PULL_UP_MASK)

#define TSC_DEBUG_MODE2_YNLR_PULL_DOWN_MASK      (0x200U)
#define TSC_DEBUG_MODE2_YNLR_PULL_DOWN_SHIFT     (9U)
/*! YNLR_PULL_DOWN - YNLR Wire Pull Down Switch
 *  0b0..Close the switch
 *  0b1..Open up the switch
 */
#define TSC_DEBUG_MODE2_YNLR_PULL_DOWN(x)        (((uint32_t)(((uint32_t)(x)) << TSC_DEBUG_MODE2_YNLR_PULL_DOWN_SHIFT)) & TSC_DEBUG_MODE2_YNLR_PULL_DOWN_MASK)

#define TSC_DEBUG_MODE2_YNLR_PULL_UP_MASK        (0x400U)
#define TSC_DEBUG_MODE2_YNLR_PULL_UP_SHIFT       (10U)
/*! YNLR_PULL_UP - YNLR Wire Pull Up Switch
 *  0b0..Close the switch
 *  0b1..Open up the switch
 */
#define TSC_DEBUG_MODE2_YNLR_PULL_UP(x)          (((uint32_t)(((uint32_t)(x)) << TSC_DEBUG_MODE2_YNLR_PULL_UP_SHIFT)) & TSC_DEBUG_MODE2_YNLR_PULL_UP_MASK)

#define TSC_DEBUG_MODE2_YNLR_200K_PULL_UP_MASK   (0x800U)
#define TSC_DEBUG_MODE2_YNLR_200K_PULL_UP_SHIFT  (11U)
/*! YNLR_200K_PULL_UP - YNLR Wire 200K Pull Up Switch
 *  0b0..Close the switch
 *  0b1..Open up the switch
 */
#define TSC_DEBUG_MODE2_YNLR_200K_PULL_UP(x)     (((uint32_t)(((uint32_t)(x)) << TSC_DEBUG_MODE2_YNLR_200K_PULL_UP_SHIFT)) & TSC_DEBUG_MODE2_YNLR_200K_PULL_UP_MASK)

#define TSC_DEBUG_MODE2_WIPER_PULL_DOWN_MASK     (0x1000U)
#define TSC_DEBUG_MODE2_WIPER_PULL_DOWN_SHIFT    (12U)
/*! WIPER_PULL_DOWN - Wiper Wire Pull Down Switch
 *  0b0..Close the switch
 *  0b1..Open up the switch
 */
#define TSC_DEBUG_MODE2_WIPER_PULL_DOWN(x)       (((uint32_t)(((uint32_t)(x)) << TSC_DEBUG_MODE2_WIPER_PULL_DOWN_SHIFT)) & TSC_DEBUG_MODE2_WIPER_PULL_DOWN_MASK)

#define TSC_DEBUG_MODE2_WIPER_PULL_UP_MASK       (0x2000U)
#define TSC_DEBUG_MODE2_WIPER_PULL_UP_SHIFT      (13U)
/*! WIPER_PULL_UP - Wiper Wire Pull Up Switch
 *  0b0..Close the switch
 *  0b1..Open up the switch
 */
#define TSC_DEBUG_MODE2_WIPER_PULL_UP(x)         (((uint32_t)(((uint32_t)(x)) << TSC_DEBUG_MODE2_WIPER_PULL_UP_SHIFT)) & TSC_DEBUG_MODE2_WIPER_PULL_UP_MASK)

#define TSC_DEBUG_MODE2_WIPER_200K_PULL_UP_MASK  (0x4000U)
#define TSC_DEBUG_MODE2_WIPER_200K_PULL_UP_SHIFT (14U)
/*! WIPER_200K_PULL_UP - Wiper Wire 200K Pull Up Switch
 *  0b0..Close the switch
 *  0b1..Open up the switch
 */
#define TSC_DEBUG_MODE2_WIPER_200K_PULL_UP(x)    (((uint32_t)(((uint32_t)(x)) << TSC_DEBUG_MODE2_WIPER_200K_PULL_UP_SHIFT)) & TSC_DEBUG_MODE2_WIPER_200K_PULL_UP_MASK)

#define TSC_DEBUG_MODE2_DETECT_FOUR_WIRE_MASK    (0x10000U)
#define TSC_DEBUG_MODE2_DETECT_FOUR_WIRE_SHIFT   (16U)
/*! DETECT_FOUR_WIRE - Detect Four Wire
 *  0b0..No detect signal
 *  0b1..Yes, there is a detect on the touch screen.
 */
#define TSC_DEBUG_MODE2_DETECT_FOUR_WIRE(x)      (((uint32_t)(((uint32_t)(x)) << TSC_DEBUG_MODE2_DETECT_FOUR_WIRE_SHIFT)) & TSC_DEBUG_MODE2_DETECT_FOUR_WIRE_MASK)

#define TSC_DEBUG_MODE2_DETECT_FIVE_WIRE_MASK    (0x20000U)
#define TSC_DEBUG_MODE2_DETECT_FIVE_WIRE_SHIFT   (17U)
/*! DETECT_FIVE_WIRE - Detect Five Wire
 *  0b0..No detect signal
 *  0b1..Yes, there is a detect on the touch screen.
 */
#define TSC_DEBUG_MODE2_DETECT_FIVE_WIRE(x)      (((uint32_t)(((uint32_t)(x)) << TSC_DEBUG_MODE2_DETECT_FIVE_WIRE_SHIFT)) & TSC_DEBUG_MODE2_DETECT_FIVE_WIRE_MASK)

#define TSC_DEBUG_MODE2_STATE_MACHINE_MASK       (0x700000U)
#define TSC_DEBUG_MODE2_STATE_MACHINE_SHIFT      (20U)
/*! STATE_MACHINE - State Machine
 *  0b000..Idle
 *  0b001..Pre-charge
 *  0b010..Detect
 *  0b011..X-measure
 *  0b100..Y-measure
 *  0b101..Pre-charge
 *  0b110..Detect
 */
#define TSC_DEBUG_MODE2_STATE_MACHINE(x)         (((uint32_t)(((uint32_t)(x)) << TSC_DEBUG_MODE2_STATE_MACHINE_SHIFT)) & TSC_DEBUG_MODE2_STATE_MACHINE_MASK)

#define TSC_DEBUG_MODE2_INTERMEDIATE_MASK        (0x800000U)
#define TSC_DEBUG_MODE2_INTERMEDIATE_SHIFT       (23U)
/*! INTERMEDIATE - Intermediate State
 *  0b0..Not in intermedia
 *  0b1..Intermedia
 */
#define TSC_DEBUG_MODE2_INTERMEDIATE(x)          (((uint32_t)(((uint32_t)(x)) << TSC_DEBUG_MODE2_INTERMEDIATE_SHIFT)) & TSC_DEBUG_MODE2_INTERMEDIATE_MASK)

#define TSC_DEBUG_MODE2_DETECT_ENABLE_FOUR_WIRE_MASK (0x1000000U)
#define TSC_DEBUG_MODE2_DETECT_ENABLE_FOUR_WIRE_SHIFT (24U)
/*! DETECT_ENABLE_FOUR_WIRE - Detect Enable Four Wire
 *  0b0..Do not read four wire detect value, read default value from analogue
 *  0b1..Read four wire detect status from analogue
 */
#define TSC_DEBUG_MODE2_DETECT_ENABLE_FOUR_WIRE(x) (((uint32_t)(((uint32_t)(x)) << TSC_DEBUG_MODE2_DETECT_ENABLE_FOUR_WIRE_SHIFT)) & TSC_DEBUG_MODE2_DETECT_ENABLE_FOUR_WIRE_MASK)

#define TSC_DEBUG_MODE2_DETECT_ENABLE_FIVE_WIRE_MASK (0x10000000U)
#define TSC_DEBUG_MODE2_DETECT_ENABLE_FIVE_WIRE_SHIFT (28U)
/*! DETECT_ENABLE_FIVE_WIRE - Detect Enable Five Wire
 *  0b0..Do not read five wire detect value, read default value from analogue
 *  0b1..Read five wire detect status from analogue
 */
#define TSC_DEBUG_MODE2_DETECT_ENABLE_FIVE_WIRE(x) (((uint32_t)(((uint32_t)(x)) << TSC_DEBUG_MODE2_DETECT_ENABLE_FIVE_WIRE_SHIFT)) & TSC_DEBUG_MODE2_DETECT_ENABLE_FIVE_WIRE_MASK)

#define TSC_DEBUG_MODE2_DE_GLITCH_MASK           (0x60000000U)
#define TSC_DEBUG_MODE2_DE_GLITCH_SHIFT          (29U)
/*! DE_GLITCH
 *  0b00..Normal function: 0x1fff ipg clock cycles; Low power mode: 0x9 low power clock cycles
 *  0b01..Normal function: 0xfff ipg clock cycles; Low power mode: :0x7 low power clock cycles
 *  0b10..Normal function: 0x7ff ipg clock cycles; Low power mode:0x5 low power clock cycles
 *  0b11..Normal function: 0x3 ipg clock cycles; Low power mode:0x3 low power clock cycles
 */
#define TSC_DEBUG_MODE2_DE_GLITCH(x)             (((uint32_t)(((uint32_t)(x)) << TSC_DEBUG_MODE2_DE_GLITCH_SHIFT)) & TSC_DEBUG_MODE2_DE_GLITCH_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group TSC_Register_Masks */

/* Backward compatibility */
#define TSC_BASIC_SETTING__4_5_WIRE_MASK          TSC_BASIC_SETTING_WIRE_4_5_MASK
#define TSC_BASIC_SETTING__4_5_WIRE_SHIFT         TSC_BASIC_SETTING_WIRE_4_5_SHIFT
#define TSC_BASIC_SETTING__4_5_WIRE(x)            TSC_BASIC_SETTING_WIRE_4_5(x)


/*!
 * @}
 */ /* end of group TSC_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic pop
  #else
    #pragma pop
  #endif
#elif defined(__CWCC__)
  #pragma pop
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


#endif  /* PERI_TSC_H_ */

