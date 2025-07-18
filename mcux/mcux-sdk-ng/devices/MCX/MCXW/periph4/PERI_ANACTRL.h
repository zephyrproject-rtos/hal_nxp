/*
** ###################################################################
**     Processors:          MCXW235BIHNAR
**                          MCXW235BIUKAR
**                          MCXW236AIHNAR
**                          MCXW236AIUKAR
**                          MCXW236BIHNAR
**                          MCXW236BIUKAR
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for ANACTRL
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2022-03-08)
**         Initial version based on v0.1UM
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_ANACTRL.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for ANACTRL
 *
 * CMSIS Peripheral Access Layer for ANACTRL
 */

#if !defined(PERI_ANACTRL_H_)
#define PERI_ANACTRL_H_                          /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXW235BIHNAR) || defined(CPU_MCXW235BIUKAR))
#include "MCXW235_COMMON.h"
#elif (defined(CPU_MCXW236AIHNAR) || defined(CPU_MCXW236AIUKAR) || defined(CPU_MCXW236BIHNAR) || defined(CPU_MCXW236BIUKAR))
#include "MCXW236_COMMON.h"
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
   -- ANACTRL Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ANACTRL_Peripheral_Access_Layer ANACTRL Peripheral Access Layer
 * @{
 */

/** ANACTRL - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[4];
  __I  uint32_t ANALOG_CTRL_STATUS;                /**< Analog Macroblock Identity registers, Flash Status registers, offset: 0x4 */
       uint8_t RESERVED_1[4];
  __IO uint32_t FREQ_ME_CTRL;                      /**< Frequency Measure function control register, offset: 0xC */
  __IO uint32_t FRO192M_CTRL;                      /**< 192MHz Free Running OScillator (FRO) Clock Control register, offset: 0x10 */
  __I  uint32_t FRO192M_STATUS;                    /**< 192MHz Free Running OScillator (FRO) Status register, offset: 0x14 */
       uint8_t RESERVED_2[16];
  __I  uint32_t BLE_STATUS;                        /**< Status of the analog components of the BLE radio, offset: 0x28 */
  __IO uint32_t BLE_CTRL;                          /**< BLE Control, offset: 0x2C */
  __IO uint32_t BOD_DCDC_INT_CTRL;                 /**< Brown Out Detectors (BoDs) & DCDC interrupts generation control register, offset: 0x30 */
  __I  uint32_t BOD_DCDC_INT_STATUS;               /**< BoDs & DCDC interrupts status register, offset: 0x34 */
} ANACTRL_Type;

/* ----------------------------------------------------------------------------
   -- ANACTRL Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ANACTRL_Register_Masks ANACTRL Register Masks
 * @{
 */

/*! @name ANALOG_CTRL_STATUS - Analog Macroblock Identity registers, Flash Status registers */
/*! @{ */

#define ANACTRL_ANALOG_CTRL_STATUS_FLASH_PWRDWN_MASK (0x1000U)
#define ANACTRL_ANALOG_CTRL_STATUS_FLASH_PWRDWN_SHIFT (12U)
/*! FLASH_PWRDWN - Flash Power Down status.
 *  0b0..Flash is not in power down mode.
 *  0b1..Flash is in power down mode.
 */
#define ANACTRL_ANALOG_CTRL_STATUS_FLASH_PWRDWN(x) (((uint32_t)(((uint32_t)(x)) << ANACTRL_ANALOG_CTRL_STATUS_FLASH_PWRDWN_SHIFT)) & ANACTRL_ANALOG_CTRL_STATUS_FLASH_PWRDWN_MASK)

#define ANACTRL_ANALOG_CTRL_STATUS_FLASH_INIT_ERROR_MASK (0x2000U)
#define ANACTRL_ANALOG_CTRL_STATUS_FLASH_INIT_ERROR_SHIFT (13U)
/*! FLASH_INIT_ERROR - Flash initialization error status.
 *  0b0..No error.
 *  0b1..At least one error occured during flash initialization..
 */
#define ANACTRL_ANALOG_CTRL_STATUS_FLASH_INIT_ERROR(x) (((uint32_t)(((uint32_t)(x)) << ANACTRL_ANALOG_CTRL_STATUS_FLASH_INIT_ERROR_SHIFT)) & ANACTRL_ANALOG_CTRL_STATUS_FLASH_INIT_ERROR_MASK)
/*! @} */

/*! @name FREQ_ME_CTRL - Frequency Measure function control register */
/*! @{ */

#define ANACTRL_FREQ_ME_CTRL_CAPVAL_SCALE_MASK   (0x7FFFFFFFU)
#define ANACTRL_FREQ_ME_CTRL_CAPVAL_SCALE_SHIFT  (0U)
/*! CAPVAL_SCALE - Frequency measure result /Frequency measure scale */
#define ANACTRL_FREQ_ME_CTRL_CAPVAL_SCALE(x)     (((uint32_t)(((uint32_t)(x)) << ANACTRL_FREQ_ME_CTRL_CAPVAL_SCALE_SHIFT)) & ANACTRL_FREQ_ME_CTRL_CAPVAL_SCALE_MASK)

#define ANACTRL_FREQ_ME_CTRL_PROG_MASK           (0x80000000U)
#define ANACTRL_FREQ_ME_CTRL_PROG_SHIFT          (31U)
/*! PROG - Set this bit to one to initiate a frequency measurement cycle. */
#define ANACTRL_FREQ_ME_CTRL_PROG(x)             (((uint32_t)(((uint32_t)(x)) << ANACTRL_FREQ_ME_CTRL_PROG_SHIFT)) & ANACTRL_FREQ_ME_CTRL_PROG_MASK)
/*! @} */

/*! @name FRO192M_CTRL - 192MHz Free Running OScillator (FRO) Clock Control register */
/*! @{ */

#define ANACTRL_FRO192M_CTRL_ENA_12MHZCLK_MASK   (0x4000U)
#define ANACTRL_FRO192M_CTRL_ENA_12MHZCLK_SHIFT  (14U)
/*! ENA_12MHZCLK - 12 MHz clock control (both PMC and other blocks).
 *  0b0..12 MHz clock is disabled.
 *  0b1..12 MHz clock is enabled.
 */
#define ANACTRL_FRO192M_CTRL_ENA_12MHZCLK(x)     (((uint32_t)(((uint32_t)(x)) << ANACTRL_FRO192M_CTRL_ENA_12MHZCLK_SHIFT)) & ANACTRL_FRO192M_CTRL_ENA_12MHZCLK_MASK)

#define ANACTRL_FRO192M_CTRL_ENA_24MHZCLK_MASK   (0x8000U)
#define ANACTRL_FRO192M_CTRL_ENA_24MHZCLK_SHIFT  (15U)
/*! ENA_24MHZCLK - 24 MHz clock control.
 *  0b0..24 MHz clock is disabled.
 *  0b1..24 MHz clock is enabled.
 */
#define ANACTRL_FRO192M_CTRL_ENA_24MHZCLK(x)     (((uint32_t)(((uint32_t)(x)) << ANACTRL_FRO192M_CTRL_ENA_24MHZCLK_SHIFT)) & ANACTRL_FRO192M_CTRL_ENA_24MHZCLK_MASK)

#define ANACTRL_FRO192M_CTRL_ENA_32MHZCLK_MASK   (0x10000U)
#define ANACTRL_FRO192M_CTRL_ENA_32MHZCLK_SHIFT  (16U)
/*! ENA_32MHZCLK - 32 MHz clock control.
 *  0b0..32 MHz clock is disabled.
 *  0b1..32 MHz clock is enabled.
 */
#define ANACTRL_FRO192M_CTRL_ENA_32MHZCLK(x)     (((uint32_t)(((uint32_t)(x)) << ANACTRL_FRO192M_CTRL_ENA_32MHZCLK_SHIFT)) & ANACTRL_FRO192M_CTRL_ENA_32MHZCLK_MASK)

#define ANACTRL_FRO192M_CTRL_ENA_48MHZCLK_MASK   (0x20000U)
#define ANACTRL_FRO192M_CTRL_ENA_48MHZCLK_SHIFT  (17U)
/*! ENA_48MHZCLK - 48 MHz clock control.
 *  0b0..48 MHz clock is disabled.
 *  0b1..48 MHz clock is enabled.
 */
#define ANACTRL_FRO192M_CTRL_ENA_48MHZCLK(x)     (((uint32_t)(((uint32_t)(x)) << ANACTRL_FRO192M_CTRL_ENA_48MHZCLK_SHIFT)) & ANACTRL_FRO192M_CTRL_ENA_48MHZCLK_MASK)

#define ANACTRL_FRO192M_CTRL_ENA_64MHZCLK_MASK   (0x40000U)
#define ANACTRL_FRO192M_CTRL_ENA_64MHZCLK_SHIFT  (18U)
/*! ENA_64MHZCLK - 64 MHz clock control.
 *  0b0..64 MHz clock is disabled.
 *  0b1..64 MHz clock is enabled.
 */
#define ANACTRL_FRO192M_CTRL_ENA_64MHZCLK(x)     (((uint32_t)(((uint32_t)(x)) << ANACTRL_FRO192M_CTRL_ENA_64MHZCLK_SHIFT)) & ANACTRL_FRO192M_CTRL_ENA_64MHZCLK_MASK)
/*! @} */

/*! @name FRO192M_STATUS - 192MHz Free Running OScillator (FRO) Status register */
/*! @{ */

#define ANACTRL_FRO192M_STATUS_CLK_VALID_MASK    (0x1U)
#define ANACTRL_FRO192M_STATUS_CLK_VALID_SHIFT   (0U)
/*! CLK_VALID - Output clock valid signal.
 *  0b0..No output clock present (None of 12 MHz, 48 MHz or 96 MHz clock is available).
 *  0b1..Clock is present (12 MHz, 48 MHz or 96 MHz can be output if they are enable respectively by
 *       FRO192M_CTRL.ENA_12MHZCLK/ENA_48MHZCLK/ENA_96MHZCLK).
 */
#define ANACTRL_FRO192M_STATUS_CLK_VALID(x)      (((uint32_t)(((uint32_t)(x)) << ANACTRL_FRO192M_STATUS_CLK_VALID_SHIFT)) & ANACTRL_FRO192M_STATUS_CLK_VALID_MASK)

#define ANACTRL_FRO192M_STATUS_ATB_VCTRL_MASK    (0x2U)
#define ANACTRL_FRO192M_STATUS_ATB_VCTRL_SHIFT   (1U)
/*! ATB_VCTRL - CCO threshold voltage detector output (signal vcco_ok). */
#define ANACTRL_FRO192M_STATUS_ATB_VCTRL(x)      (((uint32_t)(((uint32_t)(x)) << ANACTRL_FRO192M_STATUS_ATB_VCTRL_SHIFT)) & ANACTRL_FRO192M_STATUS_ATB_VCTRL_MASK)
/*! @} */

/*! @name BLE_STATUS - Status of the analog components of the BLE radio */
/*! @{ */

#define ANACTRL_BLE_STATUS_DTST_XOCLKRDY_MASK    (0x1U)
#define ANACTRL_BLE_STATUS_DTST_XOCLKRDY_SHIFT   (0U)
/*! DTST_XOCLKRDY - Clock ready signal from BLE 32MHz XTAL Oscillator
 *  0b0..Clock not ready
 *  0b1..Clock ready
 */
#define ANACTRL_BLE_STATUS_DTST_XOCLKRDY(x)      (((uint32_t)(((uint32_t)(x)) << ANACTRL_BLE_STATUS_DTST_XOCLKRDY_SHIFT)) & ANACTRL_BLE_STATUS_DTST_XOCLKRDY_MASK)

#define ANACTRL_BLE_STATUS_PLLFLGCLK_MASK        (0x2U)
#define ANACTRL_BLE_STATUS_PLLFLGCLK_SHIFT       (1U)
/*! PLLFLGCLK - BLE PLL lock indicator output
 *  0b0..PLL not locked
 *  0b1..PLL locked
 */
#define ANACTRL_BLE_STATUS_PLLFLGCLK(x)          (((uint32_t)(((uint32_t)(x)) << ANACTRL_BLE_STATUS_PLLFLGCLK_SHIFT)) & ANACTRL_BLE_STATUS_PLLFLGCLK_MASK)

#define ANACTRL_BLE_STATUS_BLE_DST_STATUS_MASK   (0x4U)
#define ANACTRL_BLE_STATUS_BLE_DST_STATUS_SHIFT  (2U)
/*! BLE_DST_STATUS - BLE Deep sleep timer interrupt status before interrupt enable
 *  0b0..No interrupt pending
 *  0b1..Interrupt pending
 */
#define ANACTRL_BLE_STATUS_BLE_DST_STATUS(x)     (((uint32_t)(((uint32_t)(x)) << ANACTRL_BLE_STATUS_BLE_DST_STATUS_SHIFT)) & ANACTRL_BLE_STATUS_BLE_DST_STATUS_MASK)

#define ANACTRL_BLE_STATUS_BLE_DST_INT_STATUS_MASK (0x8U)
#define ANACTRL_BLE_STATUS_BLE_DST_INT_STATUS_SHIFT (3U)
/*! BLE_DST_INT_STATUS - BLE Deep sleep timer interrupt status after interrupt enable
 *  0b0..No interrupt pending
 *  0b1..Interrupt pending
 */
#define ANACTRL_BLE_STATUS_BLE_DST_INT_STATUS(x) (((uint32_t)(((uint32_t)(x)) << ANACTRL_BLE_STATUS_BLE_DST_INT_STATUS_SHIFT)) & ANACTRL_BLE_STATUS_BLE_DST_INT_STATUS_MASK)
/*! @} */

/*! @name BLE_CTRL - BLE Control */
/*! @{ */

#define ANACTRL_BLE_CTRL_BLE_DST_INT_ENABLE_MASK (0x1U)
#define ANACTRL_BLE_CTRL_BLE_DST_INT_ENABLE_SHIFT (0U)
/*! BLE_DST_INT_ENABLE - BLE Deep sleep timer interrupt control
 *  0b0..BLE Deep sleep timer interrupt is disabled
 *  0b1..BLE Deep sleep timer interrupt is enabled
 */
#define ANACTRL_BLE_CTRL_BLE_DST_INT_ENABLE(x)   (((uint32_t)(((uint32_t)(x)) << ANACTRL_BLE_CTRL_BLE_DST_INT_ENABLE_SHIFT)) & ANACTRL_BLE_CTRL_BLE_DST_INT_ENABLE_MASK)

#define ANACTRL_BLE_CTRL_BLE_DST_INT_CLR_MASK    (0x2U)
#define ANACTRL_BLE_CTRL_BLE_DST_INT_CLR_SHIFT   (1U)
/*! BLE_DST_INT_CLR - BLE Deep sleep timer interrupt clear. Write 1 to clear the interrupt */
#define ANACTRL_BLE_CTRL_BLE_DST_INT_CLR(x)      (((uint32_t)(((uint32_t)(x)) << ANACTRL_BLE_CTRL_BLE_DST_INT_CLR_SHIFT)) & ANACTRL_BLE_CTRL_BLE_DST_INT_CLR_MASK)
/*! @} */

/*! @name BOD_DCDC_INT_CTRL - Brown Out Detectors (BoDs) & DCDC interrupts generation control register */
/*! @{ */

#define ANACTRL_BOD_DCDC_INT_CTRL_BOD1_INT_ENABLE_MASK (0x1U)
#define ANACTRL_BOD_DCDC_INT_CTRL_BOD1_INT_ENABLE_SHIFT (0U)
/*! BOD1_INT_ENABLE - BOD1 interrupt control.
 *  0b0..BOD1 interrupt is disabled.
 *  0b1..BOD1 interrupt is enabled.
 */
#define ANACTRL_BOD_DCDC_INT_CTRL_BOD1_INT_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << ANACTRL_BOD_DCDC_INT_CTRL_BOD1_INT_ENABLE_SHIFT)) & ANACTRL_BOD_DCDC_INT_CTRL_BOD1_INT_ENABLE_MASK)

#define ANACTRL_BOD_DCDC_INT_CTRL_BOD1_INT_CLEAR_MASK (0x2U)
#define ANACTRL_BOD_DCDC_INT_CTRL_BOD1_INT_CLEAR_SHIFT (1U)
/*! BOD1_INT_CLEAR - BOD1 interrupt clear. */
#define ANACTRL_BOD_DCDC_INT_CTRL_BOD1_INT_CLEAR(x) (((uint32_t)(((uint32_t)(x)) << ANACTRL_BOD_DCDC_INT_CTRL_BOD1_INT_CLEAR_SHIFT)) & ANACTRL_BOD_DCDC_INT_CTRL_BOD1_INT_CLEAR_MASK)

#define ANACTRL_BOD_DCDC_INT_CTRL_BOD2_INT_ENABLE_MASK (0x4U)
#define ANACTRL_BOD_DCDC_INT_CTRL_BOD2_INT_ENABLE_SHIFT (2U)
/*! BOD2_INT_ENABLE - BOD2 interrupt control.
 *  0b0..BOD2 interrupt is disabled.
 *  0b1..BOD2 interrupt is enabled.
 */
#define ANACTRL_BOD_DCDC_INT_CTRL_BOD2_INT_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << ANACTRL_BOD_DCDC_INT_CTRL_BOD2_INT_ENABLE_SHIFT)) & ANACTRL_BOD_DCDC_INT_CTRL_BOD2_INT_ENABLE_MASK)

#define ANACTRL_BOD_DCDC_INT_CTRL_BOD2_INT_CLEAR_MASK (0x8U)
#define ANACTRL_BOD_DCDC_INT_CTRL_BOD2_INT_CLEAR_SHIFT (3U)
/*! BOD2_INT_CLEAR - BOD2 interrupt clear. */
#define ANACTRL_BOD_DCDC_INT_CTRL_BOD2_INT_CLEAR(x) (((uint32_t)(((uint32_t)(x)) << ANACTRL_BOD_DCDC_INT_CTRL_BOD2_INT_CLEAR_SHIFT)) & ANACTRL_BOD_DCDC_INT_CTRL_BOD2_INT_CLEAR_MASK)

#define ANACTRL_BOD_DCDC_INT_CTRL_DCDC_INT_ENABLE_MASK (0x10U)
#define ANACTRL_BOD_DCDC_INT_CTRL_DCDC_INT_ENABLE_SHIFT (4U)
/*! DCDC_INT_ENABLE - DCDC interrupt control.
 *  0b0..DCDC interrupt is disabled.
 *  0b1..DCDC interrupt is enabled.
 */
#define ANACTRL_BOD_DCDC_INT_CTRL_DCDC_INT_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << ANACTRL_BOD_DCDC_INT_CTRL_DCDC_INT_ENABLE_SHIFT)) & ANACTRL_BOD_DCDC_INT_CTRL_DCDC_INT_ENABLE_MASK)

#define ANACTRL_BOD_DCDC_INT_CTRL_DCDC_INT_CLEAR_MASK (0x20U)
#define ANACTRL_BOD_DCDC_INT_CTRL_DCDC_INT_CLEAR_SHIFT (5U)
/*! DCDC_INT_CLEAR - DCDC interrupt clear. */
#define ANACTRL_BOD_DCDC_INT_CTRL_DCDC_INT_CLEAR(x) (((uint32_t)(((uint32_t)(x)) << ANACTRL_BOD_DCDC_INT_CTRL_DCDC_INT_CLEAR_SHIFT)) & ANACTRL_BOD_DCDC_INT_CTRL_DCDC_INT_CLEAR_MASK)
/*! @} */

/*! @name BOD_DCDC_INT_STATUS - BoDs & DCDC interrupts status register */
/*! @{ */

#define ANACTRL_BOD_DCDC_INT_STATUS_BOD1_STATUS_MASK (0x1U)
#define ANACTRL_BOD_DCDC_INT_STATUS_BOD1_STATUS_SHIFT (0U)
/*! BOD1_STATUS - BOD1 Interrupt status before Interrupt Enable.
 *  0b0..No interrupt pending..
 *  0b1..Interrupt pending..
 */
#define ANACTRL_BOD_DCDC_INT_STATUS_BOD1_STATUS(x) (((uint32_t)(((uint32_t)(x)) << ANACTRL_BOD_DCDC_INT_STATUS_BOD1_STATUS_SHIFT)) & ANACTRL_BOD_DCDC_INT_STATUS_BOD1_STATUS_MASK)

#define ANACTRL_BOD_DCDC_INT_STATUS_BOD1_INT_STATUS_MASK (0x2U)
#define ANACTRL_BOD_DCDC_INT_STATUS_BOD1_INT_STATUS_SHIFT (1U)
/*! BOD1_INT_STATUS - BOD1 Interrupt status after Interrupt Enable.
 *  0b0..No interrupt pending..
 *  0b1..Interrupt pending..
 */
#define ANACTRL_BOD_DCDC_INT_STATUS_BOD1_INT_STATUS(x) (((uint32_t)(((uint32_t)(x)) << ANACTRL_BOD_DCDC_INT_STATUS_BOD1_INT_STATUS_SHIFT)) & ANACTRL_BOD_DCDC_INT_STATUS_BOD1_INT_STATUS_MASK)

#define ANACTRL_BOD_DCDC_INT_STATUS_BOD1_VAL_MASK (0x4U)
#define ANACTRL_BOD_DCDC_INT_STATUS_BOD1_VAL_SHIFT (2U)
/*! BOD1_VAL - Current value of BOD1 power status output.
 *  0b0..VBAT INT voltage level is below the threshold.
 *  0b1..VBAT INT voltage level is above the threshold.
 */
#define ANACTRL_BOD_DCDC_INT_STATUS_BOD1_VAL(x)  (((uint32_t)(((uint32_t)(x)) << ANACTRL_BOD_DCDC_INT_STATUS_BOD1_VAL_SHIFT)) & ANACTRL_BOD_DCDC_INT_STATUS_BOD1_VAL_MASK)

#define ANACTRL_BOD_DCDC_INT_STATUS_BOD2_STATUS_MASK (0x8U)
#define ANACTRL_BOD_DCDC_INT_STATUS_BOD2_STATUS_SHIFT (3U)
/*! BOD2_STATUS - BOD2 Interrupt status before Interrupt Enable.
 *  0b0..No interrupt pending..
 *  0b1..Interrupt pending..
 */
#define ANACTRL_BOD_DCDC_INT_STATUS_BOD2_STATUS(x) (((uint32_t)(((uint32_t)(x)) << ANACTRL_BOD_DCDC_INT_STATUS_BOD2_STATUS_SHIFT)) & ANACTRL_BOD_DCDC_INT_STATUS_BOD2_STATUS_MASK)

#define ANACTRL_BOD_DCDC_INT_STATUS_BOD2_INT_STATUS_MASK (0x10U)
#define ANACTRL_BOD_DCDC_INT_STATUS_BOD2_INT_STATUS_SHIFT (4U)
/*! BOD2_INT_STATUS - BOD2 Interrupt status after Interrupt Enable.
 *  0b0..No interrupt pending..
 *  0b1..Interrupt pending..
 */
#define ANACTRL_BOD_DCDC_INT_STATUS_BOD2_INT_STATUS(x) (((uint32_t)(((uint32_t)(x)) << ANACTRL_BOD_DCDC_INT_STATUS_BOD2_INT_STATUS_SHIFT)) & ANACTRL_BOD_DCDC_INT_STATUS_BOD2_INT_STATUS_MASK)

#define ANACTRL_BOD_DCDC_INT_STATUS_BOD2_VAL_MASK (0x20U)
#define ANACTRL_BOD_DCDC_INT_STATUS_BOD2_VAL_SHIFT (5U)
/*! BOD2_VAL - Current value of BOD2 power status output.
 *  0b0..VBAT INT voltage level is below the threshold.
 *  0b1..VBAT INT voltage level is above the threshold.
 */
#define ANACTRL_BOD_DCDC_INT_STATUS_BOD2_VAL(x)  (((uint32_t)(((uint32_t)(x)) << ANACTRL_BOD_DCDC_INT_STATUS_BOD2_VAL_SHIFT)) & ANACTRL_BOD_DCDC_INT_STATUS_BOD2_VAL_MASK)

#define ANACTRL_BOD_DCDC_INT_STATUS_DCDC_STATUS_MASK (0x40U)
#define ANACTRL_BOD_DCDC_INT_STATUS_DCDC_STATUS_SHIFT (6U)
/*! DCDC_STATUS - DCDC Interrupt status before Interrupt Enable.
 *  0b0..No interrupt pending..
 *  0b1..Interrupt pending..
 */
#define ANACTRL_BOD_DCDC_INT_STATUS_DCDC_STATUS(x) (((uint32_t)(((uint32_t)(x)) << ANACTRL_BOD_DCDC_INT_STATUS_DCDC_STATUS_SHIFT)) & ANACTRL_BOD_DCDC_INT_STATUS_DCDC_STATUS_MASK)

#define ANACTRL_BOD_DCDC_INT_STATUS_DCDC_INT_STATUS_MASK (0x80U)
#define ANACTRL_BOD_DCDC_INT_STATUS_DCDC_INT_STATUS_SHIFT (7U)
/*! DCDC_INT_STATUS - DCDC Interrupt status after Interrupt Enable.
 *  0b0..No interrupt pending..
 *  0b1..Interrupt pending..
 */
#define ANACTRL_BOD_DCDC_INT_STATUS_DCDC_INT_STATUS(x) (((uint32_t)(((uint32_t)(x)) << ANACTRL_BOD_DCDC_INT_STATUS_DCDC_INT_STATUS_SHIFT)) & ANACTRL_BOD_DCDC_INT_STATUS_DCDC_INT_STATUS_MASK)

#define ANACTRL_BOD_DCDC_INT_STATUS_DCDC_VAL_MASK (0x100U)
#define ANACTRL_BOD_DCDC_INT_STATUS_DCDC_VAL_SHIFT (8U)
/*! DCDC_VAL - Current value of DCDC power status output.
 *  0b0..DCDC output Voltage is below the targeted regulation level.
 *  0b1..DCDC output Voltage is above the targeted regulation level.
 */
#define ANACTRL_BOD_DCDC_INT_STATUS_DCDC_VAL(x)  (((uint32_t)(((uint32_t)(x)) << ANACTRL_BOD_DCDC_INT_STATUS_DCDC_VAL_SHIFT)) & ANACTRL_BOD_DCDC_INT_STATUS_DCDC_VAL_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group ANACTRL_Register_Masks */


/*!
 * @}
 */ /* end of group ANACTRL_Peripheral_Access_Layer */


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


#endif  /* PERI_ANACTRL_H_ */

