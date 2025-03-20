/*
** ###################################################################
**     Processors:          MIMXRT1011CAE4A
**                          MIMXRT1011DAE5A
**
**     Version:             rev. 1.2, 2021-08-10
**     Build:               b240705
**
**     Abstract:
**         CMSIS Peripheral Access Layer for IOMUXC_SNVS
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 0.1 (2019-02-14)
**         Initial version.
**     - rev. 1.0 (2019-08-01)
**         Rev.0 Header GA
**     - rev. 1.1 (2019-08-06)
**         Update header files to align with IMXRT1010RM Rev.B.
**     - rev. 1.2 (2021-08-10)
**         Update header files to align with IMXRT1010RM Rev.1.
**
** ###################################################################
*/

/*!
 * @file IOMUXC_SNVS.h
 * @version 1.2
 * @date 2021-08-10
 * @brief CMSIS Peripheral Access Layer for IOMUXC_SNVS
 *
 * CMSIS Peripheral Access Layer for IOMUXC_SNVS
 */

#if !defined(IOMUXC_SNVS_H_)
#define IOMUXC_SNVS_H_                           /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT1011CAE4A) || defined(CPU_MIMXRT1011DAE5A))
#include "MIMXRT1011_COMMON.h"
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
  __IO uint32_t SW_MUX_CTL_PAD_PMIC_ON_REQ;        /**< SW_MUX_CTL_PAD_PMIC_ON_REQ SW MUX Control Register, offset: 0x0 */
  __IO uint32_t SW_PAD_CTL_PAD_TEST_MODE;          /**< SW_PAD_CTL_PAD_TEST_MODE SW PAD Control Register, offset: 0x4 */
  __IO uint32_t SW_PAD_CTL_PAD_POR_B;              /**< SW_PAD_CTL_PAD_POR_B SW PAD Control Register, offset: 0x8 */
  __IO uint32_t SW_PAD_CTL_PAD_ONOFF;              /**< SW_PAD_CTL_PAD_ONOFF SW PAD Control Register, offset: 0xC */
  __IO uint32_t SW_PAD_CTL_PAD_PMIC_ON_REQ;        /**< SW_PAD_CTL_PAD_PMIC_ON_REQ SW PAD Control Register, offset: 0x10 */
} IOMUXC_SNVS_Type;

/* ----------------------------------------------------------------------------
   -- IOMUXC_SNVS Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IOMUXC_SNVS_Register_Masks IOMUXC_SNVS Register Masks
 * @{
 */

/*! @name SW_MUX_CTL_PAD_PMIC_ON_REQ - SW_MUX_CTL_PAD_PMIC_ON_REQ SW MUX Control Register */
/*! @{ */

#define IOMUXC_SNVS_SW_MUX_CTL_PAD_PMIC_ON_REQ_MUX_MODE_MASK (0x7U)
#define IOMUXC_SNVS_SW_MUX_CTL_PAD_PMIC_ON_REQ_MUX_MODE_SHIFT (0U)
/*! MUX_MODE - MUX Mode Select Field.
 *  0b000..Select mux mode: ALT0 mux port: SNVS_LP_PMIC_ON_REQ of instance: snvs_lp
 *  0b101..Select mux mode: ALT5 mux port: GPIO5_IO00 of instance: gpio5
 */
#define IOMUXC_SNVS_SW_MUX_CTL_PAD_PMIC_ON_REQ_MUX_MODE(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_SNVS_SW_MUX_CTL_PAD_PMIC_ON_REQ_MUX_MODE_SHIFT)) & IOMUXC_SNVS_SW_MUX_CTL_PAD_PMIC_ON_REQ_MUX_MODE_MASK)

#define IOMUXC_SNVS_SW_MUX_CTL_PAD_PMIC_ON_REQ_SION_MASK (0x10U)
#define IOMUXC_SNVS_SW_MUX_CTL_PAD_PMIC_ON_REQ_SION_SHIFT (4U)
/*! SION - Software Input On Field.
 *  0b1..Force input path of pad PMIC_ON_REQ
 *  0b0..Input Path is determined by functionality
 */
#define IOMUXC_SNVS_SW_MUX_CTL_PAD_PMIC_ON_REQ_SION(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_SNVS_SW_MUX_CTL_PAD_PMIC_ON_REQ_SION_SHIFT)) & IOMUXC_SNVS_SW_MUX_CTL_PAD_PMIC_ON_REQ_SION_MASK)
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
 *  0b000..output driver disabled;
 *  0b001..R0(150 Ohm @ 3.3V, 260 Ohm@1.8V)
 *  0b010..R0/2
 *  0b011..R0/3
 *  0b100..R0/4
 *  0b101..R0/5
 *  0b110..R0/6
 *  0b111..R0/7
 */
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_TEST_MODE_DSE(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_SNVS_SW_PAD_CTL_PAD_TEST_MODE_DSE_SHIFT)) & IOMUXC_SNVS_SW_PAD_CTL_PAD_TEST_MODE_DSE_MASK)

#define IOMUXC_SNVS_SW_PAD_CTL_PAD_TEST_MODE_SPEED_MASK (0xC0U)
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_TEST_MODE_SPEED_SHIFT (6U)
/*! SPEED - Speed Field
 *  0b10..medium(100MHz)
 */
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_TEST_MODE_SPEED(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_SNVS_SW_PAD_CTL_PAD_TEST_MODE_SPEED_SHIFT)) & IOMUXC_SNVS_SW_PAD_CTL_PAD_TEST_MODE_SPEED_MASK)

#define IOMUXC_SNVS_SW_PAD_CTL_PAD_TEST_MODE_ODE_MASK (0x800U)
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_TEST_MODE_ODE_SHIFT (11U)
/*! ODE - Open Drain Enable Field
 *  0b0..Open Drain Disabled
 *  0b1..Open Drain Enabled
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
/*! PUE - Pull / Keep Select Field
 *  0b0..Keeper
 *  0b1..Pull
 */
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_TEST_MODE_PUE(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_SNVS_SW_PAD_CTL_PAD_TEST_MODE_PUE_SHIFT)) & IOMUXC_SNVS_SW_PAD_CTL_PAD_TEST_MODE_PUE_MASK)

#define IOMUXC_SNVS_SW_PAD_CTL_PAD_TEST_MODE_PUS_MASK (0xC000U)
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_TEST_MODE_PUS_SHIFT (14U)
/*! PUS - Pull Up / Down Config. Field
 *  0b00..100K Ohm Pull Down
 *  0b01..47K Ohm Pull Up
 *  0b10..100K Ohm Pull Up
 *  0b11..22K Ohm Pull Up
 */
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_TEST_MODE_PUS(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_SNVS_SW_PAD_CTL_PAD_TEST_MODE_PUS_SHIFT)) & IOMUXC_SNVS_SW_PAD_CTL_PAD_TEST_MODE_PUS_MASK)

#define IOMUXC_SNVS_SW_PAD_CTL_PAD_TEST_MODE_HYS_MASK (0x10000U)
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_TEST_MODE_HYS_SHIFT (16U)
/*! HYS - Hyst. Enable Field
 *  0b0..Hysteresis Disabled
 *  0b1..Hysteresis Enabled
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
 *  0b000..output driver disabled;
 *  0b001..R0(150 Ohm @ 3.3V, 260 Ohm@1.8V)
 *  0b010..R0/2
 *  0b011..R0/3
 *  0b100..R0/4
 *  0b101..R0/5
 *  0b110..R0/6
 *  0b111..R0/7
 */
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_POR_B_DSE(x)  (((uint32_t)(((uint32_t)(x)) << IOMUXC_SNVS_SW_PAD_CTL_PAD_POR_B_DSE_SHIFT)) & IOMUXC_SNVS_SW_PAD_CTL_PAD_POR_B_DSE_MASK)

#define IOMUXC_SNVS_SW_PAD_CTL_PAD_POR_B_SPEED_MASK (0xC0U)
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_POR_B_SPEED_SHIFT (6U)
/*! SPEED - Speed Field
 *  0b10..medium(100MHz)
 */
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_POR_B_SPEED(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_SNVS_SW_PAD_CTL_PAD_POR_B_SPEED_SHIFT)) & IOMUXC_SNVS_SW_PAD_CTL_PAD_POR_B_SPEED_MASK)

#define IOMUXC_SNVS_SW_PAD_CTL_PAD_POR_B_ODE_MASK (0x800U)
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_POR_B_ODE_SHIFT (11U)
/*! ODE - Open Drain Enable Field
 *  0b0..Open Drain Disabled
 *  0b1..Open Drain Enabled
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
/*! PUE - Pull / Keep Select Field
 *  0b0..Keeper
 *  0b1..Pull
 */
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_POR_B_PUE(x)  (((uint32_t)(((uint32_t)(x)) << IOMUXC_SNVS_SW_PAD_CTL_PAD_POR_B_PUE_SHIFT)) & IOMUXC_SNVS_SW_PAD_CTL_PAD_POR_B_PUE_MASK)

#define IOMUXC_SNVS_SW_PAD_CTL_PAD_POR_B_PUS_MASK (0xC000U)
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_POR_B_PUS_SHIFT (14U)
/*! PUS - Pull Up / Down Config. Field
 *  0b00..100K Ohm Pull Down
 *  0b01..47K Ohm Pull Up
 *  0b10..100K Ohm Pull Up
 *  0b11..22K Ohm Pull Up
 */
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_POR_B_PUS(x)  (((uint32_t)(((uint32_t)(x)) << IOMUXC_SNVS_SW_PAD_CTL_PAD_POR_B_PUS_SHIFT)) & IOMUXC_SNVS_SW_PAD_CTL_PAD_POR_B_PUS_MASK)

#define IOMUXC_SNVS_SW_PAD_CTL_PAD_POR_B_HYS_MASK (0x10000U)
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_POR_B_HYS_SHIFT (16U)
/*! HYS - Hyst. Enable Field
 *  0b0..Hysteresis Disabled
 *  0b1..Hysteresis Enabled
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
 *  0b000..output driver disabled;
 *  0b001..R0(150 Ohm @ 3.3V, 260 Ohm@1.8V)
 *  0b010..R0/2
 *  0b011..R0/3
 *  0b100..R0/4
 *  0b101..R0/5
 *  0b110..R0/6
 *  0b111..R0/7
 */
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_ONOFF_DSE(x)  (((uint32_t)(((uint32_t)(x)) << IOMUXC_SNVS_SW_PAD_CTL_PAD_ONOFF_DSE_SHIFT)) & IOMUXC_SNVS_SW_PAD_CTL_PAD_ONOFF_DSE_MASK)

#define IOMUXC_SNVS_SW_PAD_CTL_PAD_ONOFF_SPEED_MASK (0xC0U)
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_ONOFF_SPEED_SHIFT (6U)
/*! SPEED - Speed Field
 *  0b10..medium(100MHz)
 */
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_ONOFF_SPEED(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_SNVS_SW_PAD_CTL_PAD_ONOFF_SPEED_SHIFT)) & IOMUXC_SNVS_SW_PAD_CTL_PAD_ONOFF_SPEED_MASK)

#define IOMUXC_SNVS_SW_PAD_CTL_PAD_ONOFF_ODE_MASK (0x800U)
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_ONOFF_ODE_SHIFT (11U)
/*! ODE - Open Drain Enable Field
 *  0b0..Open Drain Disabled
 *  0b1..Open Drain Enabled
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
/*! PUE - Pull / Keep Select Field
 *  0b0..Keeper
 *  0b1..Pull
 */
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_ONOFF_PUE(x)  (((uint32_t)(((uint32_t)(x)) << IOMUXC_SNVS_SW_PAD_CTL_PAD_ONOFF_PUE_SHIFT)) & IOMUXC_SNVS_SW_PAD_CTL_PAD_ONOFF_PUE_MASK)

#define IOMUXC_SNVS_SW_PAD_CTL_PAD_ONOFF_PUS_MASK (0xC000U)
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_ONOFF_PUS_SHIFT (14U)
/*! PUS - Pull Up / Down Config. Field
 *  0b00..100K Ohm Pull Down
 *  0b01..47K Ohm Pull Up
 *  0b10..100K Ohm Pull Up
 *  0b11..22K Ohm Pull Up
 */
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_ONOFF_PUS(x)  (((uint32_t)(((uint32_t)(x)) << IOMUXC_SNVS_SW_PAD_CTL_PAD_ONOFF_PUS_SHIFT)) & IOMUXC_SNVS_SW_PAD_CTL_PAD_ONOFF_PUS_MASK)

#define IOMUXC_SNVS_SW_PAD_CTL_PAD_ONOFF_HYS_MASK (0x10000U)
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_ONOFF_HYS_SHIFT (16U)
/*! HYS - Hyst. Enable Field
 *  0b0..Hysteresis Disabled
 *  0b1..Hysteresis Enabled
 */
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_ONOFF_HYS(x)  (((uint32_t)(((uint32_t)(x)) << IOMUXC_SNVS_SW_PAD_CTL_PAD_ONOFF_HYS_SHIFT)) & IOMUXC_SNVS_SW_PAD_CTL_PAD_ONOFF_HYS_MASK)
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
 *  0b000..output driver disabled;
 *  0b001..R0(150 Ohm @ 3.3V, 260 Ohm@1.8V)
 *  0b010..R0/2
 *  0b011..R0/3
 *  0b100..R0/4
 *  0b101..R0/5
 *  0b110..R0/6
 *  0b111..R0/7
 */
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_ON_REQ_DSE(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_ON_REQ_DSE_SHIFT)) & IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_ON_REQ_DSE_MASK)

#define IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_ON_REQ_SPEED_MASK (0xC0U)
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_ON_REQ_SPEED_SHIFT (6U)
/*! SPEED - Speed Field
 *  0b10..medium(100MHz)
 */
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_ON_REQ_SPEED(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_ON_REQ_SPEED_SHIFT)) & IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_ON_REQ_SPEED_MASK)

#define IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_ON_REQ_ODE_MASK (0x800U)
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_ON_REQ_ODE_SHIFT (11U)
/*! ODE - Open Drain Enable Field
 *  0b0..Open Drain Disabled
 *  0b1..Open Drain Enabled
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
/*! PUE - Pull / Keep Select Field
 *  0b0..Keeper
 *  0b1..Pull
 */
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_ON_REQ_PUE(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_ON_REQ_PUE_SHIFT)) & IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_ON_REQ_PUE_MASK)

#define IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_ON_REQ_PUS_MASK (0xC000U)
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_ON_REQ_PUS_SHIFT (14U)
/*! PUS - Pull Up / Down Config. Field
 *  0b00..100K Ohm Pull Down
 *  0b01..47K Ohm Pull Up
 *  0b10..100K Ohm Pull Up
 *  0b11..22K Ohm Pull Up
 */
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_ON_REQ_PUS(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_ON_REQ_PUS_SHIFT)) & IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_ON_REQ_PUS_MASK)

#define IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_ON_REQ_HYS_MASK (0x10000U)
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_ON_REQ_HYS_SHIFT (16U)
/*! HYS - Hyst. Enable Field
 *  0b0..Hysteresis Disabled
 *  0b1..Hysteresis Enabled
 */
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_ON_REQ_HYS(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_ON_REQ_HYS_SHIFT)) & IOMUXC_SNVS_SW_PAD_CTL_PAD_PMIC_ON_REQ_HYS_MASK)
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


#endif  /* IOMUXC_SNVS_H_ */

