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
**         CMSIS Peripheral Access Layer for IOMUXC_SNVS
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
 * @file PERI_IOMUXC_SNVS.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for IOMUXC_SNVS
 *
 * CMSIS Peripheral Access Layer for IOMUXC_SNVS
 */

#if !defined(PERI_IOMUXC_SNVS_H_)
#define PERI_IOMUXC_SNVS_H_                      /**< Symbol preventing repeated inclusion */

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
   -- IOMUXC_SNVS Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IOMUXC_SNVS_Peripheral_Access_Layer IOMUXC_SNVS Peripheral Access Layer
 * @{
 */

/** IOMUXC_SNVS - Register Layout Typedef */
typedef struct {
  __IO uint32_t SW_MUX_CTL_PAD_WAKEUP;             /**< SW_MUX_CTL_PAD_WAKEUP SW MUX Control Register, offset: 0x0 */
  __IO uint32_t SW_MUX_CTL_PAD_PMIC_ON_REQ;        /**< SW_MUX_CTL_PAD_PMIC_ON_REQ SW MUX Control Register, offset: 0x4 */
  __IO uint32_t SW_MUX_CTL_PAD_PMIC_STBY_REQ;      /**< SW_MUX_CTL_PAD_PMIC_STBY_REQ SW MUX Control Register, offset: 0x8 */
  __IO uint32_t SW_PAD_CTL_PAD_TEST_MODE;          /**< SW_PAD_CTL_PAD_TEST_MODE SW PAD Control Register, offset: 0xC */
  __IO uint32_t SW_PAD_CTL_PAD_POR_B;              /**< SW_PAD_CTL_PAD_POR_B SW PAD Control Register, offset: 0x10 */
  __IO uint32_t SW_PAD_CTL_PAD_ONOFF;              /**< SW_PAD_CTL_PAD_ONOFF SW PAD Control Register, offset: 0x14 */
  __IO uint32_t SW_PAD_CTL_PAD_WAKEUP;             /**< SW_PAD_CTL_PAD_WAKEUP SW PAD Control Register, offset: 0x18 */
  __IO uint32_t SW_PAD_CTL_PAD_PMIC_ON_REQ;        /**< SW_PAD_CTL_PAD_PMIC_ON_REQ SW PAD Control Register, offset: 0x1C */
  __IO uint32_t SW_PAD_CTL_PAD_PMIC_STBY_REQ;      /**< SW_PAD_CTL_PAD_PMIC_STBY_REQ SW PAD Control Register, offset: 0x20 */
} IOMUXC_SNVS_Type;

/* ----------------------------------------------------------------------------
   -- IOMUXC_SNVS Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IOMUXC_SNVS_Register_Masks IOMUXC_SNVS Register Masks
 * @{
 */

/*! @name SW_MUX_CTL_PAD_WAKEUP - SW_MUX_CTL_PAD_WAKEUP SW MUX Control Register */
/*! @{ */

#define IOMUXC_SNVS_SW_MUX_CTL_PAD_WAKEUP_MUX_MODE_MASK (0x7U)
#define IOMUXC_SNVS_SW_MUX_CTL_PAD_WAKEUP_MUX_MODE_SHIFT (0U)
/*! MUX_MODE - MUX Mode Select Field.
 *  0b101..Select mux mode: ALT5 mux port: GPIO5_IO00 of instance: gpio5
 *  0b111..Select mux mode: ALT7 mux port: NMI of instance: CM7
 */
#define IOMUXC_SNVS_SW_MUX_CTL_PAD_WAKEUP_MUX_MODE(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_SNVS_SW_MUX_CTL_PAD_WAKEUP_MUX_MODE_SHIFT)) & IOMUXC_SNVS_SW_MUX_CTL_PAD_WAKEUP_MUX_MODE_MASK)

#define IOMUXC_SNVS_SW_MUX_CTL_PAD_WAKEUP_SION_MASK (0x10U)
#define IOMUXC_SNVS_SW_MUX_CTL_PAD_WAKEUP_SION_SHIFT (4U)
/*! SION - Software Input On Field.
 *  0b0..Input Path is determined by functionality
 *  0b1..Force input path of pad WAKEUP
 */
#define IOMUXC_SNVS_SW_MUX_CTL_PAD_WAKEUP_SION(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_SNVS_SW_MUX_CTL_PAD_WAKEUP_SION_SHIFT)) & IOMUXC_SNVS_SW_MUX_CTL_PAD_WAKEUP_SION_MASK)
/*! @} */

/*! @name SW_MUX_CTL_PAD_PMIC_ON_REQ - SW_MUX_CTL_PAD_PMIC_ON_REQ SW MUX Control Register */
/*! @{ */

#define IOMUXC_SNVS_SW_MUX_CTL_PAD_PMIC_ON_REQ_MUX_MODE_MASK (0x7U)
#define IOMUXC_SNVS_SW_MUX_CTL_PAD_PMIC_ON_REQ_MUX_MODE_SHIFT (0U)
/*! MUX_MODE - MUX Mode Select Field.
 *  0b000..Select mux mode: ALT0 mux port: SNVS_PMIC_ON_REQ of instance: snvs
 *  0b101..Select mux mode: ALT5 mux port: GPIO5_IO01 of instance: gpio5
 */
#define IOMUXC_SNVS_SW_MUX_CTL_PAD_PMIC_ON_REQ_MUX_MODE(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_SNVS_SW_MUX_CTL_PAD_PMIC_ON_REQ_MUX_MODE_SHIFT)) & IOMUXC_SNVS_SW_MUX_CTL_PAD_PMIC_ON_REQ_MUX_MODE_MASK)

#define IOMUXC_SNVS_SW_MUX_CTL_PAD_PMIC_ON_REQ_SION_MASK (0x10U)
#define IOMUXC_SNVS_SW_MUX_CTL_PAD_PMIC_ON_REQ_SION_SHIFT (4U)
/*! SION - Software Input On Field.
 *  0b0..Input Path is determined by functionality
 *  0b1..Force input path of pad PMIC_ON_REQ
 */
#define IOMUXC_SNVS_SW_MUX_CTL_PAD_PMIC_ON_REQ_SION(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_SNVS_SW_MUX_CTL_PAD_PMIC_ON_REQ_SION_SHIFT)) & IOMUXC_SNVS_SW_MUX_CTL_PAD_PMIC_ON_REQ_SION_MASK)
/*! @} */

/*! @name SW_MUX_CTL_PAD_PMIC_STBY_REQ - SW_MUX_CTL_PAD_PMIC_STBY_REQ SW MUX Control Register */
/*! @{ */

#define IOMUXC_SNVS_SW_MUX_CTL_PAD_PMIC_STBY_REQ_MUX_MODE_MASK (0x7U)
#define IOMUXC_SNVS_SW_MUX_CTL_PAD_PMIC_STBY_REQ_MUX_MODE_SHIFT (0U)
/*! MUX_MODE - MUX Mode Select Field.
 *  0b000..Select mux mode: ALT0 mux port: CCM_PMIC_STBY_REQ of instance: ccm
 *  0b101..Select mux mode: ALT5 mux port: GPIO5_IO02 of instance: gpio5
 */
#define IOMUXC_SNVS_SW_MUX_CTL_PAD_PMIC_STBY_REQ_MUX_MODE(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_SNVS_SW_MUX_CTL_PAD_PMIC_STBY_REQ_MUX_MODE_SHIFT)) & IOMUXC_SNVS_SW_MUX_CTL_PAD_PMIC_STBY_REQ_MUX_MODE_MASK)

#define IOMUXC_SNVS_SW_MUX_CTL_PAD_PMIC_STBY_REQ_SION_MASK (0x10U)
#define IOMUXC_SNVS_SW_MUX_CTL_PAD_PMIC_STBY_REQ_SION_SHIFT (4U)
/*! SION - Software Input On Field.
 *  0b0..Input Path is determined by functionality
 *  0b1..Force input path of pad PMIC_STBY_REQ
 */
#define IOMUXC_SNVS_SW_MUX_CTL_PAD_PMIC_STBY_REQ_SION(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_SNVS_SW_MUX_CTL_PAD_PMIC_STBY_REQ_SION_SHIFT)) & IOMUXC_SNVS_SW_MUX_CTL_PAD_PMIC_STBY_REQ_SION_MASK)
/*! @} */

/*! @name SW_PAD_CTL_PAD_TEST_MODE - SW_PAD_CTL_PAD_TEST_MODE SW PAD Control Register */
/*! @{ */

#define IOMUXC_SNVS_SW_PAD_CTL_PAD_TEST_MODE_SRE_MASK (0x1U)
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_TEST_MODE_SRE_SHIFT (0U)
/*! SRE - Slew Rate Field
 *  0b0..Slow Slew Rate
 *  0b1..Fast Slew Rate
 */
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_TEST_MODE_SRE(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_SNVS_SW_PAD_CTL_PAD_TEST_MODE_SRE_SHIFT)) & IOMUXC_SNVS_SW_PAD_CTL_PAD_TEST_MODE_SRE_MASK)

#define IOMUXC_SNVS_SW_PAD_CTL_PAD_TEST_MODE_DSE_MASK (0x38U)
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_TEST_MODE_DSE_SHIFT (3U)
/*! DSE - Drive Strength Field
 *  0b000..HI-Z
 *  0b001..Dual/Single voltage: 262/260 Ohm @ 1.8V, 247/157 Ohm @ 3.3V
 *  0b010..Dual/Single voltage: 134/130 Ohm @ 1.8V, 126/78 Ohm @ 3.3V
 *  0b011..Dual/Single voltage: 88/88 Ohm @ 1.8V, 84/53 Ohm @ 3.3V
 *  0b100..Dual/Single voltage: 62/65 Ohm @ 1.8V, 57/39 Ohm @ 3.3V
 *  0b101..Dual/Single voltage: 51/52 Ohm @ 1.8V, 47/32 Ohm @ 3.3V
 *  0b110..Dual/Single voltage: 43/43 Ohm @ 1.8V, 40/26 Ohm @ 3.3V
 *  0b111..Dual/Single voltage: 37/37 Ohm @ 1.8V, 34/23 Ohm @ 3.3V
 */
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_TEST_MODE_DSE(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_SNVS_SW_PAD_CTL_PAD_TEST_MODE_DSE_SHIFT)) & IOMUXC_SNVS_SW_PAD_CTL_PAD_TEST_MODE_DSE_MASK)

#define IOMUXC_SNVS_SW_PAD_CTL_PAD_TEST_MODE_SPEED_MASK (0xC0U)
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_TEST_MODE_SPEED_SHIFT (6U)
/*! SPEED - Speed Field
 *  0b10..100MHz
 */
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_TEST_MODE_SPEED(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_SNVS_SW_PAD_CTL_PAD_TEST_MODE_SPEED_SHIFT)) & IOMUXC_SNVS_SW_PAD_CTL_PAD_TEST_MODE_SPEED_MASK)

#define IOMUXC_SNVS_SW_PAD_CTL_PAD_TEST_MODE_ODE_MASK (0x800U)
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_TEST_MODE_ODE_SHIFT (11U)
/*! ODE - Open Drain Enable Field
 *  0b0..Open Drain Disabled (Output is CMOS)
 *  0b1..Open Drain Enabled (Output is Open Drain)
 */
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_TEST_MODE_ODE(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_SNVS_SW_PAD_CTL_PAD_TEST_MODE_ODE_SHIFT)) & IOMUXC_SNVS_SW_PAD_CTL_PAD_TEST_MODE_ODE_MASK)

#define IOMUXC_SNVS_SW_PAD_CTL_PAD_TEST_MODE_PKE_MASK (0x1000U)
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_TEST_MODE_PKE_SHIFT (12U)
/*! PKE - Pull / Keep Enable Field
 *  0b0..Pull/Keeper Disabled
 *  0b1..Pull/Keeper Enabled
 */
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_TEST_MODE_PKE(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_SNVS_SW_PAD_CTL_PAD_TEST_MODE_PKE_SHIFT)) & IOMUXC_SNVS_SW_PAD_CTL_PAD_TEST_MODE_PKE_MASK)

#define IOMUXC_SNVS_SW_PAD_CTL_PAD_TEST_MODE_PUE_MASK (0x2000U)
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_TEST_MODE_PUE_SHIFT (13U)
/*! PUE - Pull / Keep Select Field Control signal to enable internal pull-up/down resistors or pad keeper functionality.
 *  0b0..Keep the previous output value when the output driver is disabled.
 *  0b1..Pull-up or pull-down (determined by PUS field).
 */
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_TEST_MODE_PUE(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_SNVS_SW_PAD_CTL_PAD_TEST_MODE_PUE_SHIFT)) & IOMUXC_SNVS_SW_PAD_CTL_PAD_TEST_MODE_PUE_MASK)

#define IOMUXC_SNVS_SW_PAD_CTL_PAD_TEST_MODE_PUS_MASK (0xC000U)
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_TEST_MODE_PUS_SHIFT (14U)
/*! PUS - Pull Up / Down Config. Field Controls signals to select pull-up or pull-down internal resistance strength.
 *  0b00..100K Ohm Pull Down
 *  0b01..47K Ohm Pull Up
 *  0b10..100K Ohm Pull Up
 *  0b11..22K Ohm Pull Up
 */
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_TEST_MODE_PUS(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_SNVS_SW_PAD_CTL_PAD_TEST_MODE_PUS_SHIFT)) & IOMUXC_SNVS_SW_PAD_CTL_PAD_TEST_MODE_PUS_MASK)

#define IOMUXC_SNVS_SW_PAD_CTL_PAD_TEST_MODE_HYS_MASK (0x10000U)
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_TEST_MODE_HYS_SHIFT (16U)
/*! HYS - Hyst. Enable Field
 *  0b0..Hysteresis Disabled (CMOS input)
 *  0b1..Hysteresis Enabled (Schmitt Trigger input)
 */
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_TEST_MODE_HYS(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_SNVS_SW_PAD_CTL_PAD_TEST_MODE_HYS_SHIFT)) & IOMUXC_SNVS_SW_PAD_CTL_PAD_TEST_MODE_HYS_MASK)
/*! @} */

/*! @name SW_PAD_CTL_PAD_POR_B - SW_PAD_CTL_PAD_POR_B SW PAD Control Register */
/*! @{ */

#define IOMUXC_SNVS_SW_PAD_CTL_PAD_POR_B_SRE_MASK (0x1U)
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_POR_B_SRE_SHIFT (0U)
/*! SRE - Slew Rate Field
 *  0b0..Slow Slew Rate
 *  0b1..Fast Slew Rate
 */
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_POR_B_SRE(x)  (((uint32_t)(((uint32_t)(x)) << IOMUXC_SNVS_SW_PAD_CTL_PAD_POR_B_SRE_SHIFT)) & IOMUXC_SNVS_SW_PAD_CTL_PAD_POR_B_SRE_MASK)

#define IOMUXC_SNVS_SW_PAD_CTL_PAD_POR_B_DSE_MASK (0x38U)
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_POR_B_DSE_SHIFT (3U)
/*! DSE - Drive Strength Field
 *  0b000..HI-Z
 *  0b001..Dual/Single voltage: 262/260 Ohm @ 1.8V, 247/157 Ohm @ 3.3V
 *  0b010..Dual/Single voltage: 134/130 Ohm @ 1.8V, 126/78 Ohm @ 3.3V
 *  0b011..Dual/Single voltage: 88/88 Ohm @ 1.8V, 84/53 Ohm @ 3.3V
 *  0b100..Dual/Single voltage: 62/65 Ohm @ 1.8V, 57/39 Ohm @ 3.3V
 *  0b101..Dual/Single voltage: 51/52 Ohm @ 1.8V, 47/32 Ohm @ 3.3V
 *  0b110..Dual/Single voltage: 43/43 Ohm @ 1.8V, 40/26 Ohm @ 3.3V
 *  0b111..Dual/Single voltage: 37/37 Ohm @ 1.8V, 34/23 Ohm @ 3.3V
 */
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_POR_B_DSE(x)  (((uint32_t)(((uint32_t)(x)) << IOMUXC_SNVS_SW_PAD_CTL_PAD_POR_B_DSE_SHIFT)) & IOMUXC_SNVS_SW_PAD_CTL_PAD_POR_B_DSE_MASK)

#define IOMUXC_SNVS_SW_PAD_CTL_PAD_POR_B_SPEED_MASK (0xC0U)
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_POR_B_SPEED_SHIFT (6U)
/*! SPEED - Speed Field
 *  0b10..100MHz
 */
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_POR_B_SPEED(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_SNVS_SW_PAD_CTL_PAD_POR_B_SPEED_SHIFT)) & IOMUXC_SNVS_SW_PAD_CTL_PAD_POR_B_SPEED_MASK)

#define IOMUXC_SNVS_SW_PAD_CTL_PAD_POR_B_ODE_MASK (0x800U)
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_POR_B_ODE_SHIFT (11U)
/*! ODE - Open Drain Enable Field
 *  0b0..Open Drain Disabled (Output is CMOS)
 *  0b1..Open Drain Enabled (Output is Open Drain)
 */
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_POR_B_ODE(x)  (((uint32_t)(((uint32_t)(x)) << IOMUXC_SNVS_SW_PAD_CTL_PAD_POR_B_ODE_SHIFT)) & IOMUXC_SNVS_SW_PAD_CTL_PAD_POR_B_ODE_MASK)

#define IOMUXC_SNVS_SW_PAD_CTL_PAD_POR_B_PKE_MASK (0x1000U)
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_POR_B_PKE_SHIFT (12U)
/*! PKE - Pull / Keep Enable Field
 *  0b0..Pull/Keeper Disabled
 *  0b1..Pull/Keeper Enabled
 */
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_POR_B_PKE(x)  (((uint32_t)(((uint32_t)(x)) << IOMUXC_SNVS_SW_PAD_CTL_PAD_POR_B_PKE_SHIFT)) & IOMUXC_SNVS_SW_PAD_CTL_PAD_POR_B_PKE_MASK)

#define IOMUXC_SNVS_SW_PAD_CTL_PAD_POR_B_PUE_MASK (0x2000U)
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_POR_B_PUE_SHIFT (13U)
/*! PUE - Pull / Keep Select Field Control signal to enable internal pull-up/down resistors or pad keeper functionality.
 *  0b0..Keep the previous output value when the output driver is disabled.
 *  0b1..Pull-up or pull-down (determined by PUS field).
 */
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_POR_B_PUE(x)  (((uint32_t)(((uint32_t)(x)) << IOMUXC_SNVS_SW_PAD_CTL_PAD_POR_B_PUE_SHIFT)) & IOMUXC_SNVS_SW_PAD_CTL_PAD_POR_B_PUE_MASK)

#define IOMUXC_SNVS_SW_PAD_CTL_PAD_POR_B_PUS_MASK (0xC000U)
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_POR_B_PUS_SHIFT (14U)
/*! PUS - Pull Up / Down Config. Field Controls signals to select pull-up or pull-down internal resistance strength.
 *  0b00..100K Ohm Pull Down
 *  0b01..47K Ohm Pull Up
 *  0b10..100K Ohm Pull Up
 *  0b11..22K Ohm Pull Up
 */
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_POR_B_PUS(x)  (((uint32_t)(((uint32_t)(x)) << IOMUXC_SNVS_SW_PAD_CTL_PAD_POR_B_PUS_SHIFT)) & IOMUXC_SNVS_SW_PAD_CTL_PAD_POR_B_PUS_MASK)

#define IOMUXC_SNVS_SW_PAD_CTL_PAD_POR_B_HYS_MASK (0x10000U)
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_POR_B_HYS_SHIFT (16U)
/*! HYS - Hyst. Enable Field
 *  0b0..Hysteresis Disabled (CMOS input)
 *  0b1..Hysteresis Enabled (Schmitt Trigger input)
 */
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_POR_B_HYS(x)  (((uint32_t)(((uint32_t)(x)) << IOMUXC_SNVS_SW_PAD_CTL_PAD_POR_B_HYS_SHIFT)) & IOMUXC_SNVS_SW_PAD_CTL_PAD_POR_B_HYS_MASK)
/*! @} */

/*! @name SW_PAD_CTL_PAD_ONOFF - SW_PAD_CTL_PAD_ONOFF SW PAD Control Register */
/*! @{ */

#define IOMUXC_SNVS_SW_PAD_CTL_PAD_ONOFF_SRE_MASK (0x1U)
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_ONOFF_SRE_SHIFT (0U)
/*! SRE - Slew Rate Field
 *  0b0..Slow Slew Rate
 *  0b1..Fast Slew Rate
 */
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_ONOFF_SRE(x)  (((uint32_t)(((uint32_t)(x)) << IOMUXC_SNVS_SW_PAD_CTL_PAD_ONOFF_SRE_SHIFT)) & IOMUXC_SNVS_SW_PAD_CTL_PAD_ONOFF_SRE_MASK)

#define IOMUXC_SNVS_SW_PAD_CTL_PAD_ONOFF_DSE_MASK (0x38U)
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_ONOFF_DSE_SHIFT (3U)
/*! DSE - Drive Strength Field
 *  0b000..HI-Z
 *  0b001..Dual/Single voltage: 262/260 Ohm @ 1.8V, 247/157 Ohm @ 3.3V
 *  0b010..Dual/Single voltage: 134/130 Ohm @ 1.8V, 126/78 Ohm @ 3.3V
 *  0b011..Dual/Single voltage: 88/88 Ohm @ 1.8V, 84/53 Ohm @ 3.3V
 *  0b100..Dual/Single voltage: 62/65 Ohm @ 1.8V, 57/39 Ohm @ 3.3V
 *  0b101..Dual/Single voltage: 51/52 Ohm @ 1.8V, 47/32 Ohm @ 3.3V
 *  0b110..Dual/Single voltage: 43/43 Ohm @ 1.8V, 40/26 Ohm @ 3.3V
 *  0b111..Dual/Single voltage: 37/37 Ohm @ 1.8V, 34/23 Ohm @ 3.3V
 */
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_ONOFF_DSE(x)  (((uint32_t)(((uint32_t)(x)) << IOMUXC_SNVS_SW_PAD_CTL_PAD_ONOFF_DSE_SHIFT)) & IOMUXC_SNVS_SW_PAD_CTL_PAD_ONOFF_DSE_MASK)

#define IOMUXC_SNVS_SW_PAD_CTL_PAD_ONOFF_SPEED_MASK (0xC0U)
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_ONOFF_SPEED_SHIFT (6U)
/*! SPEED - Speed Field
 *  0b10..100MHz
 */
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_ONOFF_SPEED(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_SNVS_SW_PAD_CTL_PAD_ONOFF_SPEED_SHIFT)) & IOMUXC_SNVS_SW_PAD_CTL_PAD_ONOFF_SPEED_MASK)

#define IOMUXC_SNVS_SW_PAD_CTL_PAD_ONOFF_ODE_MASK (0x800U)
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_ONOFF_ODE_SHIFT (11U)
/*! ODE - Open Drain Enable Field
 *  0b0..Open Drain Disabled (Output is CMOS)
 *  0b1..Open Drain Enabled (Output is Open Drain)
 */
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_ONOFF_ODE(x)  (((uint32_t)(((uint32_t)(x)) << IOMUXC_SNVS_SW_PAD_CTL_PAD_ONOFF_ODE_SHIFT)) & IOMUXC_SNVS_SW_PAD_CTL_PAD_ONOFF_ODE_MASK)

#define IOMUXC_SNVS_SW_PAD_CTL_PAD_ONOFF_PKE_MASK (0x1000U)
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_ONOFF_PKE_SHIFT (12U)
/*! PKE - Pull / Keep Enable Field
 *  0b0..Pull/Keeper Disabled
 *  0b1..Pull/Keeper Enabled
 */
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_ONOFF_PKE(x)  (((uint32_t)(((uint32_t)(x)) << IOMUXC_SNVS_SW_PAD_CTL_PAD_ONOFF_PKE_SHIFT)) & IOMUXC_SNVS_SW_PAD_CTL_PAD_ONOFF_PKE_MASK)

#define IOMUXC_SNVS_SW_PAD_CTL_PAD_ONOFF_PUE_MASK (0x2000U)
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_ONOFF_PUE_SHIFT (13U)
/*! PUE - Pull / Keep Select Field Control signal to enable internal pull-up/down resistors or pad keeper functionality.
 *  0b0..Keep the previous output value when the output driver is disabled.
 *  0b1..Pull-up or pull-down (determined by PUS field).
 */
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_ONOFF_PUE(x)  (((uint32_t)(((uint32_t)(x)) << IOMUXC_SNVS_SW_PAD_CTL_PAD_ONOFF_PUE_SHIFT)) & IOMUXC_SNVS_SW_PAD_CTL_PAD_ONOFF_PUE_MASK)

#define IOMUXC_SNVS_SW_PAD_CTL_PAD_ONOFF_PUS_MASK (0xC000U)
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_ONOFF_PUS_SHIFT (14U)
/*! PUS - Pull Up / Down Config. Field Controls signals to select pull-up or pull-down internal resistance strength.
 *  0b00..100K Ohm Pull Down
 *  0b01..47K Ohm Pull Up
 *  0b10..100K Ohm Pull Up
 *  0b11..22K Ohm Pull Up
 */
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_ONOFF_PUS(x)  (((uint32_t)(((uint32_t)(x)) << IOMUXC_SNVS_SW_PAD_CTL_PAD_ONOFF_PUS_SHIFT)) & IOMUXC_SNVS_SW_PAD_CTL_PAD_ONOFF_PUS_MASK)

#define IOMUXC_SNVS_SW_PAD_CTL_PAD_ONOFF_HYS_MASK (0x10000U)
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_ONOFF_HYS_SHIFT (16U)
/*! HYS - Hyst. Enable Field
 *  0b0..Hysteresis Disabled (CMOS input)
 *  0b1..Hysteresis Enabled (Schmitt Trigger input)
 */
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_ONOFF_HYS(x)  (((uint32_t)(((uint32_t)(x)) << IOMUXC_SNVS_SW_PAD_CTL_PAD_ONOFF_HYS_SHIFT)) & IOMUXC_SNVS_SW_PAD_CTL_PAD_ONOFF_HYS_MASK)
/*! @} */

/*! @name SW_PAD_CTL_PAD_WAKEUP - SW_PAD_CTL_PAD_WAKEUP SW PAD Control Register */
/*! @{ */

#define IOMUXC_SNVS_SW_PAD_CTL_PAD_WAKEUP_SRE_MASK (0x1U)
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_WAKEUP_SRE_SHIFT (0U)
/*! SRE - Slew Rate Field
 *  0b0..Slow Slew Rate
 *  0b1..Fast Slew Rate
 */
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_WAKEUP_SRE(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_SNVS_SW_PAD_CTL_PAD_WAKEUP_SRE_SHIFT)) & IOMUXC_SNVS_SW_PAD_CTL_PAD_WAKEUP_SRE_MASK)

#define IOMUXC_SNVS_SW_PAD_CTL_PAD_WAKEUP_DSE_MASK (0x38U)
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_WAKEUP_DSE_SHIFT (3U)
/*! DSE - Drive Strength Field
 *  0b000..HI-Z
 *  0b001..Dual/Single voltage: 262/260 Ohm @ 1.8V, 247/157 Ohm @ 3.3V
 *  0b010..Dual/Single voltage: 134/130 Ohm @ 1.8V, 126/78 Ohm @ 3.3V
 *  0b011..Dual/Single voltage: 88/88 Ohm @ 1.8V, 84/53 Ohm @ 3.3V
 *  0b100..Dual/Single voltage: 62/65 Ohm @ 1.8V, 57/39 Ohm @ 3.3V
 *  0b101..Dual/Single voltage: 51/52 Ohm @ 1.8V, 47/32 Ohm @ 3.3V
 *  0b110..Dual/Single voltage: 43/43 Ohm @ 1.8V, 40/26 Ohm @ 3.3V
 *  0b111..Dual/Single voltage: 37/37 Ohm @ 1.8V, 34/23 Ohm @ 3.3V
 */
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_WAKEUP_DSE(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_SNVS_SW_PAD_CTL_PAD_WAKEUP_DSE_SHIFT)) & IOMUXC_SNVS_SW_PAD_CTL_PAD_WAKEUP_DSE_MASK)

#define IOMUXC_SNVS_SW_PAD_CTL_PAD_WAKEUP_SPEED_MASK (0xC0U)
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_WAKEUP_SPEED_SHIFT (6U)
/*! SPEED - Speed Field
 *  0b10..100MHz
 */
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_WAKEUP_SPEED(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_SNVS_SW_PAD_CTL_PAD_WAKEUP_SPEED_SHIFT)) & IOMUXC_SNVS_SW_PAD_CTL_PAD_WAKEUP_SPEED_MASK)

#define IOMUXC_SNVS_SW_PAD_CTL_PAD_WAKEUP_ODE_MASK (0x800U)
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_WAKEUP_ODE_SHIFT (11U)
/*! ODE - Open Drain Enable Field
 *  0b0..Open Drain Disabled (Output is CMOS)
 *  0b1..Open Drain Enabled (Output is Open Drain)
 */
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_WAKEUP_ODE(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_SNVS_SW_PAD_CTL_PAD_WAKEUP_ODE_SHIFT)) & IOMUXC_SNVS_SW_PAD_CTL_PAD_WAKEUP_ODE_MASK)

#define IOMUXC_SNVS_SW_PAD_CTL_PAD_WAKEUP_PKE_MASK (0x1000U)
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_WAKEUP_PKE_SHIFT (12U)
/*! PKE - Pull / Keep Enable Field
 *  0b0..Pull/Keeper Disabled
 *  0b1..Pull/Keeper Enabled
 */
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_WAKEUP_PKE(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_SNVS_SW_PAD_CTL_PAD_WAKEUP_PKE_SHIFT)) & IOMUXC_SNVS_SW_PAD_CTL_PAD_WAKEUP_PKE_MASK)

#define IOMUXC_SNVS_SW_PAD_CTL_PAD_WAKEUP_PUE_MASK (0x2000U)
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_WAKEUP_PUE_SHIFT (13U)
/*! PUE - Pull / Keep Select Field Control signal to enable internal pull-up/down resistors or pad keeper functionality.
 *  0b0..Keep the previous output value when the output driver is disabled.
 *  0b1..Pull-up or pull-down (determined by PUS field).
 */
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_WAKEUP_PUE(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_SNVS_SW_PAD_CTL_PAD_WAKEUP_PUE_SHIFT)) & IOMUXC_SNVS_SW_PAD_CTL_PAD_WAKEUP_PUE_MASK)

#define IOMUXC_SNVS_SW_PAD_CTL_PAD_WAKEUP_PUS_MASK (0xC000U)
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_WAKEUP_PUS_SHIFT (14U)
/*! PUS - Pull Up / Down Config. Field Controls signals to select pull-up or pull-down internal resistance strength.
 *  0b00..100K Ohm Pull Down
 *  0b01..47K Ohm Pull Up
 *  0b10..100K Ohm Pull Up
 *  0b11..22K Ohm Pull Up
 */
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_WAKEUP_PUS(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_SNVS_SW_PAD_CTL_PAD_WAKEUP_PUS_SHIFT)) & IOMUXC_SNVS_SW_PAD_CTL_PAD_WAKEUP_PUS_MASK)

#define IOMUXC_SNVS_SW_PAD_CTL_PAD_WAKEUP_HYS_MASK (0x10000U)
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_WAKEUP_HYS_SHIFT (16U)
/*! HYS - Hyst. Enable Field
 *  0b0..Hysteresis Disabled (CMOS input)
 *  0b1..Hysteresis Enabled (Schmitt Trigger input)
 */
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_WAKEUP_HYS(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_SNVS_SW_PAD_CTL_PAD_WAKEUP_HYS_SHIFT)) & IOMUXC_SNVS_SW_PAD_CTL_PAD_WAKEUP_HYS_MASK)
/*! @} */

/*! @name SW_PAD_CTL_PAD_PMIC_ON_REQ - SW_PAD_CTL_PAD_PMIC_ON_REQ SW PAD Control Register */
/*! @{ */

#define IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_ON_REQ_SRE_MASK (0x1U)
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_ON_REQ_SRE_SHIFT (0U)
/*! SRE - Slew Rate Field
 *  0b0..Slow Slew Rate
 *  0b1..Fast Slew Rate
 */
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_ON_REQ_SRE(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_ON_REQ_SRE_SHIFT)) & IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_ON_REQ_SRE_MASK)

#define IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_ON_REQ_DSE_MASK (0x38U)
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_ON_REQ_DSE_SHIFT (3U)
/*! DSE - Drive Strength Field
 *  0b000..HI-Z
 *  0b001..Dual/Single voltage: 262/260 Ohm @ 1.8V, 247/157 Ohm @ 3.3V
 *  0b010..Dual/Single voltage: 134/130 Ohm @ 1.8V, 126/78 Ohm @ 3.3V
 *  0b011..Dual/Single voltage: 88/88 Ohm @ 1.8V, 84/53 Ohm @ 3.3V
 *  0b100..Dual/Single voltage: 62/65 Ohm @ 1.8V, 57/39 Ohm @ 3.3V
 *  0b101..Dual/Single voltage: 51/52 Ohm @ 1.8V, 47/32 Ohm @ 3.3V
 *  0b110..Dual/Single voltage: 43/43 Ohm @ 1.8V, 40/26 Ohm @ 3.3V
 *  0b111..Dual/Single voltage: 37/37 Ohm @ 1.8V, 34/23 Ohm @ 3.3V
 */
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_ON_REQ_DSE(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_ON_REQ_DSE_SHIFT)) & IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_ON_REQ_DSE_MASK)

#define IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_ON_REQ_SPEED_MASK (0xC0U)
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_ON_REQ_SPEED_SHIFT (6U)
/*! SPEED - Speed Field
 *  0b10..100MHz
 */
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_ON_REQ_SPEED(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_ON_REQ_SPEED_SHIFT)) & IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_ON_REQ_SPEED_MASK)

#define IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_ON_REQ_ODE_MASK (0x800U)
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_ON_REQ_ODE_SHIFT (11U)
/*! ODE - Open Drain Enable Field
 *  0b0..Open Drain Disabled (Output is CMOS)
 *  0b1..Open Drain Enabled (Output is Open Drain)
 */
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_ON_REQ_ODE(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_ON_REQ_ODE_SHIFT)) & IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_ON_REQ_ODE_MASK)

#define IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_ON_REQ_PKE_MASK (0x1000U)
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_ON_REQ_PKE_SHIFT (12U)
/*! PKE - Pull / Keep Enable Field
 *  0b0..Pull/Keeper Disabled
 *  0b1..Pull/Keeper Enabled
 */
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_ON_REQ_PKE(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_ON_REQ_PKE_SHIFT)) & IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_ON_REQ_PKE_MASK)

#define IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_ON_REQ_PUE_MASK (0x2000U)
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_ON_REQ_PUE_SHIFT (13U)
/*! PUE - Pull / Keep Select Field Control signal to enable internal pull-up/down resistors or pad keeper functionality.
 *  0b0..Keep the previous output value when the output driver is disabled.
 *  0b1..Pull-up or pull-down (determined by PUS field).
 */
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_ON_REQ_PUE(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_ON_REQ_PUE_SHIFT)) & IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_ON_REQ_PUE_MASK)

#define IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_ON_REQ_PUS_MASK (0xC000U)
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_ON_REQ_PUS_SHIFT (14U)
/*! PUS - Pull Up / Down Config. Field Controls signals to select pull-up or pull-down internal resistance strength.
 *  0b00..100K Ohm Pull Down
 *  0b01..47K Ohm Pull Up
 *  0b10..100K Ohm Pull Up
 *  0b11..22K Ohm Pull Up
 */
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_ON_REQ_PUS(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_ON_REQ_PUS_SHIFT)) & IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_ON_REQ_PUS_MASK)

#define IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_ON_REQ_HYS_MASK (0x10000U)
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_ON_REQ_HYS_SHIFT (16U)
/*! HYS - Hyst. Enable Field
 *  0b0..Hysteresis Disabled (CMOS input)
 *  0b1..Hysteresis Enabled (Schmitt Trigger input)
 */
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_ON_REQ_HYS(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_ON_REQ_HYS_SHIFT)) & IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_ON_REQ_HYS_MASK)
/*! @} */

/*! @name SW_PAD_CTL_PAD_PMIC_STBY_REQ - SW_PAD_CTL_PAD_PMIC_STBY_REQ SW PAD Control Register */
/*! @{ */

#define IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_STBY_REQ_SRE_MASK (0x1U)
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_STBY_REQ_SRE_SHIFT (0U)
/*! SRE - Slew Rate Field
 *  0b0..Slow Slew Rate
 *  0b1..Fast Slew Rate
 */
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_STBY_REQ_SRE(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_STBY_REQ_SRE_SHIFT)) & IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_STBY_REQ_SRE_MASK)

#define IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_STBY_REQ_DSE_MASK (0x38U)
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_STBY_REQ_DSE_SHIFT (3U)
/*! DSE - Drive Strength Field
 *  0b000..HI-Z
 *  0b001..Dual/Single voltage: 262/260 Ohm @ 1.8V, 247/157 Ohm @ 3.3V
 *  0b010..Dual/Single voltage: 134/130 Ohm @ 1.8V, 126/78 Ohm @ 3.3V
 *  0b011..Dual/Single voltage: 88/88 Ohm @ 1.8V, 84/53 Ohm @ 3.3V
 *  0b100..Dual/Single voltage: 62/65 Ohm @ 1.8V, 57/39 Ohm @ 3.3V
 *  0b101..Dual/Single voltage: 51/52 Ohm @ 1.8V, 47/32 Ohm @ 3.3V
 *  0b110..Dual/Single voltage: 43/43 Ohm @ 1.8V, 40/26 Ohm @ 3.3V
 *  0b111..Dual/Single voltage: 37/37 Ohm @ 1.8V, 34/23 Ohm @ 3.3V
 */
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_STBY_REQ_DSE(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_STBY_REQ_DSE_SHIFT)) & IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_STBY_REQ_DSE_MASK)

#define IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_STBY_REQ_SPEED_MASK (0xC0U)
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_STBY_REQ_SPEED_SHIFT (6U)
/*! SPEED - Speed Field
 *  0b10..100MHz
 */
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_STBY_REQ_SPEED(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_STBY_REQ_SPEED_SHIFT)) & IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_STBY_REQ_SPEED_MASK)

#define IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_STBY_REQ_ODE_MASK (0x800U)
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_STBY_REQ_ODE_SHIFT (11U)
/*! ODE - Open Drain Enable Field
 *  0b0..Open Drain Disabled (Output is CMOS)
 *  0b1..Open Drain Enabled (Output is Open Drain)
 */
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_STBY_REQ_ODE(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_STBY_REQ_ODE_SHIFT)) & IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_STBY_REQ_ODE_MASK)

#define IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_STBY_REQ_PKE_MASK (0x1000U)
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_STBY_REQ_PKE_SHIFT (12U)
/*! PKE - Pull / Keep Enable Field
 *  0b0..Pull/Keeper Disabled
 *  0b1..Pull/Keeper Enabled
 */
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_STBY_REQ_PKE(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_STBY_REQ_PKE_SHIFT)) & IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_STBY_REQ_PKE_MASK)

#define IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_STBY_REQ_PUE_MASK (0x2000U)
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_STBY_REQ_PUE_SHIFT (13U)
/*! PUE - Pull / Keep Select Field Control signal to enable internal pull-up/down resistors or pad keeper functionality.
 *  0b0..Keep the previous output value when the output driver is disabled.
 *  0b1..Pull-up or pull-down (determined by PUS field).
 */
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_STBY_REQ_PUE(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_STBY_REQ_PUE_SHIFT)) & IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_STBY_REQ_PUE_MASK)

#define IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_STBY_REQ_PUS_MASK (0xC000U)
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_STBY_REQ_PUS_SHIFT (14U)
/*! PUS - Pull Up / Down Config. Field Controls signals to select pull-up or pull-down internal resistance strength.
 *  0b00..100K Ohm Pull Down
 *  0b01..47K Ohm Pull Up
 *  0b10..100K Ohm Pull Up
 *  0b11..22K Ohm Pull Up
 */
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_STBY_REQ_PUS(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_STBY_REQ_PUS_SHIFT)) & IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_STBY_REQ_PUS_MASK)

#define IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_STBY_REQ_HYS_MASK (0x10000U)
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_STBY_REQ_HYS_SHIFT (16U)
/*! HYS - Hyst. Enable Field
 *  0b0..Hysteresis Disabled (CMOS input)
 *  0b1..Hysteresis Enabled (Schmitt Trigger input)
 */
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_STBY_REQ_HYS(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_STBY_REQ_HYS_SHIFT)) & IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_STBY_REQ_HYS_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group IOMUXC_SNVS_Register_Masks */


/*!
 * @}
 */ /* end of group IOMUXC_SNVS_Peripheral_Access_Layer */


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


#endif  /* PERI_IOMUXC_SNVS_H_ */

