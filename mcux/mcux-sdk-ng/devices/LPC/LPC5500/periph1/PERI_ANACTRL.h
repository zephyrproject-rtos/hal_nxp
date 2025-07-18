/*
** ###################################################################
**     Processors:          LPC5534JBD100
**                          LPC5534JBD64
**                          LPC5534JHI48
**                          LPC5536JBD100
**                          LPC5536JBD64
**                          LPC5536JHI48
**                          LPC55S36JBD100
**                          LPC55S36JHI48
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
**     - rev. 1.0 (2021-04-12)
**         Initial version based on RM DraftF
**     - rev. 1.1 (2021-08-04)
**         Initial version based on RM DraftG
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

#if (defined(CPU_LPC5534JBD100) || defined(CPU_LPC5534JBD64) || defined(CPU_LPC5534JHI48))
#include "LPC5534_COMMON.h"
#elif (defined(CPU_LPC5536JBD100) || defined(CPU_LPC5536JBD64) || defined(CPU_LPC5536JHI48))
#include "LPC5536_COMMON.h"
#elif (defined(CPU_LPC55S36JBD100) || defined(CPU_LPC55S36JHI48))
#include "LPC55S36_COMMON.h"
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
  __IO uint32_t ANALOG_CTRL_CFG;                   /**< Various Analog blocks configuration (like FRO 192MHz trimmings source ...), offset: 0x0 */
  __I  uint32_t ANALOG_CTRL_STATUS;                /**< Analog Control and Status, offset: 0x4 */
       uint8_t RESERVED_0[8];
  __IO uint32_t FRO192M_CTRL;                      /**< 192MHz Free Running Oscillator (FRO) Control, offset: 0x10 */
  __I  uint32_t FRO192M_STATUS;                    /**< 192MHz Free Running Oscillator (FRO) Status, offset: 0x14 */
  __IO uint32_t ADC_CTRL;                          /**< General Purpose ADC VBAT Divider branch control, offset: 0x18 */
       uint8_t RESERVED_1[4];
  __IO uint32_t XO32M_CTRL;                        /**< High speed Crystal Oscillator Control register, offset: 0x20 */
  __I  uint32_t XO32M_STATUS;                      /**< High speed Crystal Oscillator Status, offset: 0x24 */
       uint8_t RESERVED_2[8];
  __IO uint32_t BOD_DCDC_INT_CTRL;                 /**< Brown Out Detectors & DCDC interrupt control, offset: 0x30 */
  __I  uint32_t BOD_DCDC_INT_STATUS;               /**< BoDs & DCDC interrupt status, offset: 0x34 */
       uint8_t RESERVED_3[120];
  __IO uint32_t LDO_XO32M;                         /**< High Speed Crystal Oscillator (16 MHz - 32 MHz) Voltage Source Supply Control register, offset: 0xB0 */
  __IO uint32_t AUX_BIAS;                          /**< AUX_BIAS, offset: 0xB4 */
       uint8_t RESERVED_4[56];
  __IO uint32_t OSC_TESTBUS;                       /**< Oscillators Analog Macrobloc ACBUS and DCBUS control, offset: 0xF0 */
       uint8_t RESERVED_5[4];
  __IO uint32_t DUMMY_CTRL;                        /**< Dummy Control bus to analog modules, offset: 0xF8 */
} ANACTRL_Type;

/* ----------------------------------------------------------------------------
   -- ANACTRL Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ANACTRL_Register_Masks ANACTRL Register Masks
 * @{
 */

/*! @name ANALOG_CTRL_CFG - Various Analog blocks configuration (like FRO 192MHz trimmings source ...) */
/*! @{ */

#define ANACTRL_ANALOG_CTRL_CFG_FRO192M_TRIM_SRC_MASK (0x1U)
#define ANACTRL_ANALOG_CTRL_CFG_FRO192M_TRIM_SRC_SHIFT (0U)
/*! FRO192M_TRIM_SRC - FRO192M trimming and 'Enable' source.
 *  0b0..FRO192M trimming and 'Enable' comes from OTP-eFUSE.
 *  0b1..FRO192M trimming and 'Enable' comes from FRO192M_CTRL registers.
 */
#define ANACTRL_ANALOG_CTRL_CFG_FRO192M_TRIM_SRC(x) (((uint32_t)(((uint32_t)(x)) << ANACTRL_ANALOG_CTRL_CFG_FRO192M_TRIM_SRC_SHIFT)) & ANACTRL_ANALOG_CTRL_CFG_FRO192M_TRIM_SRC_MASK)
/*! @} */

/*! @name ANALOG_CTRL_STATUS - Analog Control and Status */
/*! @{ */

#define ANACTRL_ANALOG_CTRL_STATUS_FLASH_PWRDWN_MASK (0x1000U)
#define ANACTRL_ANALOG_CTRL_STATUS_FLASH_PWRDWN_SHIFT (12U)
/*! FLASH_PWRDWN - Flash Power Down status
 *  0b0..Not in power down mode.
 *  0b1..In power down mode.
 */
#define ANACTRL_ANALOG_CTRL_STATUS_FLASH_PWRDWN(x) (((uint32_t)(((uint32_t)(x)) << ANACTRL_ANALOG_CTRL_STATUS_FLASH_PWRDWN_SHIFT)) & ANACTRL_ANALOG_CTRL_STATUS_FLASH_PWRDWN_MASK)

#define ANACTRL_ANALOG_CTRL_STATUS_FLASH_INIT_ERROR_MASK (0x2000U)
#define ANACTRL_ANALOG_CTRL_STATUS_FLASH_INIT_ERROR_SHIFT (13U)
/*! FLASH_INIT_ERROR - Flash initialization error status
 *  0b0..No error
 *  0b1..At least one error occurred
 */
#define ANACTRL_ANALOG_CTRL_STATUS_FLASH_INIT_ERROR(x) (((uint32_t)(((uint32_t)(x)) << ANACTRL_ANALOG_CTRL_STATUS_FLASH_INIT_ERROR_SHIFT)) & ANACTRL_ANALOG_CTRL_STATUS_FLASH_INIT_ERROR_MASK)

#define ANACTRL_ANALOG_CTRL_STATUS_FLASH_ECC_ERROR_FLAG_MASK (0x10000U)
#define ANACTRL_ANALOG_CTRL_STATUS_FLASH_ECC_ERROR_FLAG_SHIFT (16U)
/*! FLASH_ECC_ERROR_FLAG - Flash ECC Error Flag */
#define ANACTRL_ANALOG_CTRL_STATUS_FLASH_ECC_ERROR_FLAG(x) (((uint32_t)(((uint32_t)(x)) << ANACTRL_ANALOG_CTRL_STATUS_FLASH_ECC_ERROR_FLAG_SHIFT)) & ANACTRL_ANALOG_CTRL_STATUS_FLASH_ECC_ERROR_FLAG_MASK)
/*! @} */

/*! @name FRO192M_CTRL - 192MHz Free Running Oscillator (FRO) Control */
/*! @{ */

#define ANACTRL_FRO192M_CTRL_ENA_12MHZCLK_MASK   (0x4000U)
#define ANACTRL_FRO192M_CTRL_ENA_12MHZCLK_SHIFT  (14U)
/*! ENA_12MHZCLK - 12 MHz clock control.
 *  0b0..Disable the 12 MHz clock.
 *  0b1..Enable the 12 MHz clock.
 */
#define ANACTRL_FRO192M_CTRL_ENA_12MHZCLK(x)     (((uint32_t)(((uint32_t)(x)) << ANACTRL_FRO192M_CTRL_ENA_12MHZCLK_SHIFT)) & ANACTRL_FRO192M_CTRL_ENA_12MHZCLK_MASK)

#define ANACTRL_FRO192M_CTRL_FREQ_TRIM_MASK      (0xFF0000U)
#define ANACTRL_FRO192M_CTRL_FREQ_TRIM_SHIFT     (16U)
/*! FREQ_TRIM - Frequency trim. */
#define ANACTRL_FRO192M_CTRL_FREQ_TRIM(x)        (((uint32_t)(((uint32_t)(x)) << ANACTRL_FRO192M_CTRL_FREQ_TRIM_SHIFT)) & ANACTRL_FRO192M_CTRL_FREQ_TRIM_MASK)

#define ANACTRL_FRO192M_CTRL_USBCLKADJ_MASK      (0x1000000U)
#define ANACTRL_FRO192M_CTRL_USBCLKADJ_SHIFT     (24U)
/*! USBCLKADJ - If USBCLKADJ bit is set and the USB peripheral is enabled for full speed device
 *    mode, the USB block will provide FRO clock adjustments to synchronize the frequency to the host
 *    clock using the SOF packets.
 */
#define ANACTRL_FRO192M_CTRL_USBCLKADJ(x)        (((uint32_t)(((uint32_t)(x)) << ANACTRL_FRO192M_CTRL_USBCLKADJ_SHIFT)) & ANACTRL_FRO192M_CTRL_USBCLKADJ_MASK)

#define ANACTRL_FRO192M_CTRL_USBMODCHG_MASK      (0x2000000U)
#define ANACTRL_FRO192M_CTRL_USBMODCHG_SHIFT     (25U)
/*! USBMODCHG - USBCLKADJ mode trim change */
#define ANACTRL_FRO192M_CTRL_USBMODCHG(x)        (((uint32_t)(((uint32_t)(x)) << ANACTRL_FRO192M_CTRL_USBMODCHG_SHIFT)) & ANACTRL_FRO192M_CTRL_USBMODCHG_MASK)

#define ANACTRL_FRO192M_CTRL_ENA_96MHZCLK_MASK   (0x40000000U)
#define ANACTRL_FRO192M_CTRL_ENA_96MHZCLK_SHIFT  (30U)
/*! ENA_96MHZCLK - 96 MHz clock control
 *  0b0..Disable the 96 MHz clock.
 *  0b1..Enable the 96 MHz clock.
 */
#define ANACTRL_FRO192M_CTRL_ENA_96MHZCLK(x)     (((uint32_t)(((uint32_t)(x)) << ANACTRL_FRO192M_CTRL_ENA_96MHZCLK_SHIFT)) & ANACTRL_FRO192M_CTRL_ENA_96MHZCLK_MASK)

#define ANACTRL_FRO192M_CTRL_WRTRIM_MASK         (0x80000000U)
#define ANACTRL_FRO192M_CTRL_WRTRIM_SHIFT        (31U)
/*! WRTRIM - This must be written to 1 to modify the BIAS_TRIM and TEMP_TRIM fields. */
#define ANACTRL_FRO192M_CTRL_WRTRIM(x)           (((uint32_t)(((uint32_t)(x)) << ANACTRL_FRO192M_CTRL_WRTRIM_SHIFT)) & ANACTRL_FRO192M_CTRL_WRTRIM_MASK)
/*! @} */

/*! @name FRO192M_STATUS - 192MHz Free Running Oscillator (FRO) Status */
/*! @{ */

#define ANACTRL_FRO192M_STATUS_CLK_VALID_MASK    (0x1U)
#define ANACTRL_FRO192M_STATUS_CLK_VALID_SHIFT   (0U)
/*! CLK_VALID - Output clock valid.
 *  0b0..No output clock available
 *  0b1..Output clock is available
 */
#define ANACTRL_FRO192M_STATUS_CLK_VALID(x)      (((uint32_t)(((uint32_t)(x)) << ANACTRL_FRO192M_STATUS_CLK_VALID_SHIFT)) & ANACTRL_FRO192M_STATUS_CLK_VALID_MASK)

#define ANACTRL_FRO192M_STATUS_ATB_VCTRL_MASK    (0x2U)
#define ANACTRL_FRO192M_STATUS_ATB_VCTRL_SHIFT   (1U)
/*! ATB_VCTRL - CCO threshold voltage detector output (signal vcco_ok). */
#define ANACTRL_FRO192M_STATUS_ATB_VCTRL(x)      (((uint32_t)(((uint32_t)(x)) << ANACTRL_FRO192M_STATUS_ATB_VCTRL_SHIFT)) & ANACTRL_FRO192M_STATUS_ATB_VCTRL_MASK)
/*! @} */

/*! @name ADC_CTRL - General Purpose ADC VBAT Divider branch control */
/*! @{ */

#define ANACTRL_ADC_CTRL_VBATDIVENABLE_MASK      (0x1U)
#define ANACTRL_ADC_CTRL_VBATDIVENABLE_SHIFT     (0U)
/*! VBATDIVENABLE - Switch On/Off VDDMAIN divider branch.
 *  0b0..VDDMAIN divider branch is disabled.
 *  0b1..VDDMAIN divider branch is enabled.
 */
#define ANACTRL_ADC_CTRL_VBATDIVENABLE(x)        (((uint32_t)(((uint32_t)(x)) << ANACTRL_ADC_CTRL_VBATDIVENABLE_SHIFT)) & ANACTRL_ADC_CTRL_VBATDIVENABLE_MASK)
/*! @} */

/*! @name XO32M_CTRL - High speed Crystal Oscillator Control register */
/*! @{ */

#define ANACTRL_XO32M_CTRL_SLAVE_MASK            (0x10U)
#define ANACTRL_XO32M_CTRL_SLAVE_SHIFT           (4U)
/*! SLAVE - XO in slave mode. */
#define ANACTRL_XO32M_CTRL_SLAVE(x)              (((uint32_t)(((uint32_t)(x)) << ANACTRL_XO32M_CTRL_SLAVE_SHIFT)) & ANACTRL_XO32M_CTRL_SLAVE_MASK)

#define ANACTRL_XO32M_CTRL_OSC_CAP_IN_MASK       (0x7F00U)
#define ANACTRL_XO32M_CTRL_OSC_CAP_IN_SHIFT      (8U)
/*! OSC_CAP_IN - Tune capa banks of High speed Crystal Oscillator input pin */
#define ANACTRL_XO32M_CTRL_OSC_CAP_IN(x)         (((uint32_t)(((uint32_t)(x)) << ANACTRL_XO32M_CTRL_OSC_CAP_IN_SHIFT)) & ANACTRL_XO32M_CTRL_OSC_CAP_IN_MASK)

#define ANACTRL_XO32M_CTRL_OSC_CAP_OUT_MASK      (0x3F8000U)
#define ANACTRL_XO32M_CTRL_OSC_CAP_OUT_SHIFT     (15U)
/*! OSC_CAP_OUT - Tune capa banks of High speed Crystal Oscillator output pin */
#define ANACTRL_XO32M_CTRL_OSC_CAP_OUT(x)        (((uint32_t)(((uint32_t)(x)) << ANACTRL_XO32M_CTRL_OSC_CAP_OUT_SHIFT)) & ANACTRL_XO32M_CTRL_OSC_CAP_OUT_MASK)

#define ANACTRL_XO32M_CTRL_ACBUF_PASS_ENABLE_MASK (0x400000U)
#define ANACTRL_XO32M_CTRL_ACBUF_PASS_ENABLE_SHIFT (22U)
/*! ACBUF_PASS_ENABLE - Allows XO32M to be configured in bypass mode.
 *  0b0..XO bypass is disabled.
 *  0b1..XO bypass is enabled.
 */
#define ANACTRL_XO32M_CTRL_ACBUF_PASS_ENABLE(x)  (((uint32_t)(((uint32_t)(x)) << ANACTRL_XO32M_CTRL_ACBUF_PASS_ENABLE_SHIFT)) & ANACTRL_XO32M_CTRL_ACBUF_PASS_ENABLE_MASK)

#define ANACTRL_XO32M_CTRL_ENABLE_SYSTEM_CLK_OUT_MASK (0x1000000U)
#define ANACTRL_XO32M_CTRL_ENABLE_SYSTEM_CLK_OUT_SHIFT (24U)
/*! ENABLE_SYSTEM_CLK_OUT - Enable High speed Crystal oscillator output to CPU system.
 *  0b0..Disable the oscillator.
 *  0b1..Enable the oscillator.
 */
#define ANACTRL_XO32M_CTRL_ENABLE_SYSTEM_CLK_OUT(x) (((uint32_t)(((uint32_t)(x)) << ANACTRL_XO32M_CTRL_ENABLE_SYSTEM_CLK_OUT_SHIFT)) & ANACTRL_XO32M_CTRL_ENABLE_SYSTEM_CLK_OUT_MASK)
/*! @} */

/*! @name XO32M_STATUS - High speed Crystal Oscillator Status */
/*! @{ */

#define ANACTRL_XO32M_STATUS_XO_READY_MASK       (0x1U)
#define ANACTRL_XO32M_STATUS_XO_READY_SHIFT      (0U)
/*! XO_READY - Crystal Oscillator Ready
 *  0b0..Frequency is not yet stable.
 *  0b1..Frequency is stable.
 */
#define ANACTRL_XO32M_STATUS_XO_READY(x)         (((uint32_t)(((uint32_t)(x)) << ANACTRL_XO32M_STATUS_XO_READY_SHIFT)) & ANACTRL_XO32M_STATUS_XO_READY_MASK)
/*! @} */

/*! @name BOD_DCDC_INT_CTRL - Brown Out Detectors & DCDC interrupt control */
/*! @{ */

#define ANACTRL_BOD_DCDC_INT_CTRL_BODVBAT_INT_ENABLE_MASK (0x1U)
#define ANACTRL_BOD_DCDC_INT_CTRL_BODVBAT_INT_ENABLE_SHIFT (0U)
/*! BODVBAT_INT_ENABLE - BOD VDDMAIN interrupt control.
 *  0b0..Disable the interrupt.
 *  0b1..Enable the interrupt.
 */
#define ANACTRL_BOD_DCDC_INT_CTRL_BODVBAT_INT_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << ANACTRL_BOD_DCDC_INT_CTRL_BODVBAT_INT_ENABLE_SHIFT)) & ANACTRL_BOD_DCDC_INT_CTRL_BODVBAT_INT_ENABLE_MASK)

#define ANACTRL_BOD_DCDC_INT_CTRL_BODVBAT_INT_CLEAR_MASK (0x2U)
#define ANACTRL_BOD_DCDC_INT_CTRL_BODVBAT_INT_CLEAR_SHIFT (1U)
/*! BODVBAT_INT_CLEAR - BOD VDDMAIN interrupt clear.1: Clear the interrupt. Self-cleared bit. */
#define ANACTRL_BOD_DCDC_INT_CTRL_BODVBAT_INT_CLEAR(x) (((uint32_t)(((uint32_t)(x)) << ANACTRL_BOD_DCDC_INT_CTRL_BODVBAT_INT_CLEAR_SHIFT)) & ANACTRL_BOD_DCDC_INT_CTRL_BODVBAT_INT_CLEAR_MASK)

#define ANACTRL_BOD_DCDC_INT_CTRL_BODCORE_INT_ENABLE_MASK (0x4U)
#define ANACTRL_BOD_DCDC_INT_CTRL_BODCORE_INT_ENABLE_SHIFT (2U)
/*! BODCORE_INT_ENABLE - BOD CORE interrupt control.
 *  0b0..Disable the interrupt.
 *  0b1..Enable the interrupt.
 */
#define ANACTRL_BOD_DCDC_INT_CTRL_BODCORE_INT_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << ANACTRL_BOD_DCDC_INT_CTRL_BODCORE_INT_ENABLE_SHIFT)) & ANACTRL_BOD_DCDC_INT_CTRL_BODCORE_INT_ENABLE_MASK)

#define ANACTRL_BOD_DCDC_INT_CTRL_BODCORE_INT_CLEAR_MASK (0x8U)
#define ANACTRL_BOD_DCDC_INT_CTRL_BODCORE_INT_CLEAR_SHIFT (3U)
/*! BODCORE_INT_CLEAR - BOD CORE interrupt clear.1: Clear the interrupt. Self-cleared bit. */
#define ANACTRL_BOD_DCDC_INT_CTRL_BODCORE_INT_CLEAR(x) (((uint32_t)(((uint32_t)(x)) << ANACTRL_BOD_DCDC_INT_CTRL_BODCORE_INT_CLEAR_SHIFT)) & ANACTRL_BOD_DCDC_INT_CTRL_BODCORE_INT_CLEAR_MASK)

#define ANACTRL_BOD_DCDC_INT_CTRL_DCDC_INT_ENABLE_MASK (0x10U)
#define ANACTRL_BOD_DCDC_INT_CTRL_DCDC_INT_ENABLE_SHIFT (4U)
/*! DCDC_INT_ENABLE - DCDC interrupt control.
 *  0b0..Disable the interrupt.
 *  0b1..Enable the interrupt.
 */
#define ANACTRL_BOD_DCDC_INT_CTRL_DCDC_INT_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << ANACTRL_BOD_DCDC_INT_CTRL_DCDC_INT_ENABLE_SHIFT)) & ANACTRL_BOD_DCDC_INT_CTRL_DCDC_INT_ENABLE_MASK)

#define ANACTRL_BOD_DCDC_INT_CTRL_DCDC_INT_CLEAR_MASK (0x20U)
#define ANACTRL_BOD_DCDC_INT_CTRL_DCDC_INT_CLEAR_SHIFT (5U)
/*! DCDC_INT_CLEAR - DCDC interrupt clear.1: Clear the interrupt. Self-cleared bit. */
#define ANACTRL_BOD_DCDC_INT_CTRL_DCDC_INT_CLEAR(x) (((uint32_t)(((uint32_t)(x)) << ANACTRL_BOD_DCDC_INT_CTRL_DCDC_INT_CLEAR_SHIFT)) & ANACTRL_BOD_DCDC_INT_CTRL_DCDC_INT_CLEAR_MASK)
/*! @} */

/*! @name BOD_DCDC_INT_STATUS - BoDs & DCDC interrupt status */
/*! @{ */

#define ANACTRL_BOD_DCDC_INT_STATUS_BODVBAT_STATUS_MASK (0x1U)
#define ANACTRL_BOD_DCDC_INT_STATUS_BODVBAT_STATUS_SHIFT (0U)
/*! BODVBAT_STATUS - BOD VDDMAIN Interrupt status before Interrupt Enable.
 *  0b0..No interrupt pending.
 *  0b1..Interrupt pending.
 */
#define ANACTRL_BOD_DCDC_INT_STATUS_BODVBAT_STATUS(x) (((uint32_t)(((uint32_t)(x)) << ANACTRL_BOD_DCDC_INT_STATUS_BODVBAT_STATUS_SHIFT)) & ANACTRL_BOD_DCDC_INT_STATUS_BODVBAT_STATUS_MASK)

#define ANACTRL_BOD_DCDC_INT_STATUS_BODVBAT_INT_STATUS_MASK (0x2U)
#define ANACTRL_BOD_DCDC_INT_STATUS_BODVBAT_INT_STATUS_SHIFT (1U)
/*! BODVBAT_INT_STATUS - BOD VDDMAIN Interrupt status after Interrupt Enable.
 *  0b0..No interrupt pending.
 *  0b1..Interrupt pending.
 */
#define ANACTRL_BOD_DCDC_INT_STATUS_BODVBAT_INT_STATUS(x) (((uint32_t)(((uint32_t)(x)) << ANACTRL_BOD_DCDC_INT_STATUS_BODVBAT_INT_STATUS_SHIFT)) & ANACTRL_BOD_DCDC_INT_STATUS_BODVBAT_INT_STATUS_MASK)

#define ANACTRL_BOD_DCDC_INT_STATUS_BODVBAT_VAL_MASK (0x4U)
#define ANACTRL_BOD_DCDC_INT_STATUS_BODVBAT_VAL_SHIFT (2U)
/*! BODVBAT_VAL - BOD VDDMAIN power status
 *  0b0..Below the threshold.
 *  0b1..Above the threshold.
 */
#define ANACTRL_BOD_DCDC_INT_STATUS_BODVBAT_VAL(x) (((uint32_t)(((uint32_t)(x)) << ANACTRL_BOD_DCDC_INT_STATUS_BODVBAT_VAL_SHIFT)) & ANACTRL_BOD_DCDC_INT_STATUS_BODVBAT_VAL_MASK)

#define ANACTRL_BOD_DCDC_INT_STATUS_BODCORE_STATUS_MASK (0x8U)
#define ANACTRL_BOD_DCDC_INT_STATUS_BODCORE_STATUS_SHIFT (3U)
/*! BODCORE_STATUS - BOD CORE Interrupt status before Interrupt Enable.
 *  0b0..No interrupt pending.
 *  0b1..Interrupt pending.
 */
#define ANACTRL_BOD_DCDC_INT_STATUS_BODCORE_STATUS(x) (((uint32_t)(((uint32_t)(x)) << ANACTRL_BOD_DCDC_INT_STATUS_BODCORE_STATUS_SHIFT)) & ANACTRL_BOD_DCDC_INT_STATUS_BODCORE_STATUS_MASK)

#define ANACTRL_BOD_DCDC_INT_STATUS_BODCORE_INT_STATUS_MASK (0x10U)
#define ANACTRL_BOD_DCDC_INT_STATUS_BODCORE_INT_STATUS_SHIFT (4U)
/*! BODCORE_INT_STATUS - BOD CORE Interrupt status after Interrupt Enable.
 *  0b0..No interrupt pending.
 *  0b1..Interrupt pending.
 */
#define ANACTRL_BOD_DCDC_INT_STATUS_BODCORE_INT_STATUS(x) (((uint32_t)(((uint32_t)(x)) << ANACTRL_BOD_DCDC_INT_STATUS_BODCORE_INT_STATUS_SHIFT)) & ANACTRL_BOD_DCDC_INT_STATUS_BODCORE_INT_STATUS_MASK)

#define ANACTRL_BOD_DCDC_INT_STATUS_BODCORE_VAL_MASK (0x20U)
#define ANACTRL_BOD_DCDC_INT_STATUS_BODCORE_VAL_SHIFT (5U)
/*! BODCORE_VAL - BOD CORE power status
 *  0b0..Below the threshold.
 *  0b1..Above the threshold.
 */
#define ANACTRL_BOD_DCDC_INT_STATUS_BODCORE_VAL(x) (((uint32_t)(((uint32_t)(x)) << ANACTRL_BOD_DCDC_INT_STATUS_BODCORE_VAL_SHIFT)) & ANACTRL_BOD_DCDC_INT_STATUS_BODCORE_VAL_MASK)

#define ANACTRL_BOD_DCDC_INT_STATUS_DCDC_STATUS_MASK (0x40U)
#define ANACTRL_BOD_DCDC_INT_STATUS_DCDC_STATUS_SHIFT (6U)
/*! DCDC_STATUS - DCDC Interrupt status before Interrupt Enable.
 *  0b0..No interrupt pending.
 *  0b1..Interrupt pending.
 */
#define ANACTRL_BOD_DCDC_INT_STATUS_DCDC_STATUS(x) (((uint32_t)(((uint32_t)(x)) << ANACTRL_BOD_DCDC_INT_STATUS_DCDC_STATUS_SHIFT)) & ANACTRL_BOD_DCDC_INT_STATUS_DCDC_STATUS_MASK)

#define ANACTRL_BOD_DCDC_INT_STATUS_DCDC_INT_STATUS_MASK (0x80U)
#define ANACTRL_BOD_DCDC_INT_STATUS_DCDC_INT_STATUS_SHIFT (7U)
/*! DCDC_INT_STATUS - DCDC Interrupt status after Interrupt Enable.
 *  0b0..No interrupt pending.
 *  0b1..Interrupt pending.
 */
#define ANACTRL_BOD_DCDC_INT_STATUS_DCDC_INT_STATUS(x) (((uint32_t)(((uint32_t)(x)) << ANACTRL_BOD_DCDC_INT_STATUS_DCDC_INT_STATUS_SHIFT)) & ANACTRL_BOD_DCDC_INT_STATUS_DCDC_INT_STATUS_MASK)

#define ANACTRL_BOD_DCDC_INT_STATUS_DCDC_VAL_MASK (0x100U)
#define ANACTRL_BOD_DCDC_INT_STATUS_DCDC_VAL_SHIFT (8U)
/*! DCDC_VAL - DCDC power status
 *  0b0..Below the target.
 *  0b1..Above the target.
 */
#define ANACTRL_BOD_DCDC_INT_STATUS_DCDC_VAL(x)  (((uint32_t)(((uint32_t)(x)) << ANACTRL_BOD_DCDC_INT_STATUS_DCDC_VAL_SHIFT)) & ANACTRL_BOD_DCDC_INT_STATUS_DCDC_VAL_MASK)
/*! @} */

/*! @name LDO_XO32M - High Speed Crystal Oscillator (16 MHz - 32 MHz) Voltage Source Supply Control register */
/*! @{ */

#define ANACTRL_LDO_XO32M_BYPASS_MASK            (0x2U)
#define ANACTRL_LDO_XO32M_BYPASS_SHIFT           (1U)
/*! BYPASS - Activate LDO bypass.
 *  0b0..Disable bypass mode (for normal operations).
 *  0b1..Activate LDO bypass.
 */
#define ANACTRL_LDO_XO32M_BYPASS(x)              (((uint32_t)(((uint32_t)(x)) << ANACTRL_LDO_XO32M_BYPASS_SHIFT)) & ANACTRL_LDO_XO32M_BYPASS_MASK)

#define ANACTRL_LDO_XO32M_HIGHZ_MASK             (0x4U)
#define ANACTRL_LDO_XO32M_HIGHZ_SHIFT            (2U)
/*! HIGHZ - .
 *  0b0..Output in High normal state.
 *  0b1..Output in High Impedance state.
 */
#define ANACTRL_LDO_XO32M_HIGHZ(x)               (((uint32_t)(((uint32_t)(x)) << ANACTRL_LDO_XO32M_HIGHZ_SHIFT)) & ANACTRL_LDO_XO32M_HIGHZ_MASK)

#define ANACTRL_LDO_XO32M_VOUT_MASK              (0x38U)
#define ANACTRL_LDO_XO32M_VOUT_SHIFT             (3U)
/*! VOUT - Sets the LDO output level.
 *  0b000..0.750 V.
 *  0b001..0.775 V.
 *  0b010..0.800 V.
 *  0b011..0.825 V.
 *  0b100..0.850 V.
 *  0b101..0.875 V.
 *  0b110..0.900 V.
 *  0b111..0.925 V.
 */
#define ANACTRL_LDO_XO32M_VOUT(x)                (((uint32_t)(((uint32_t)(x)) << ANACTRL_LDO_XO32M_VOUT_SHIFT)) & ANACTRL_LDO_XO32M_VOUT_MASK)

#define ANACTRL_LDO_XO32M_IBIAS_MASK             (0xC0U)
#define ANACTRL_LDO_XO32M_IBIAS_SHIFT            (6U)
/*! IBIAS - Adjust the biasing current. */
#define ANACTRL_LDO_XO32M_IBIAS(x)               (((uint32_t)(((uint32_t)(x)) << ANACTRL_LDO_XO32M_IBIAS_SHIFT)) & ANACTRL_LDO_XO32M_IBIAS_MASK)

#define ANACTRL_LDO_XO32M_STABMODE_MASK          (0x300U)
#define ANACTRL_LDO_XO32M_STABMODE_SHIFT         (8U)
/*! STABMODE - Stability configuration. */
#define ANACTRL_LDO_XO32M_STABMODE(x)            (((uint32_t)(((uint32_t)(x)) << ANACTRL_LDO_XO32M_STABMODE_SHIFT)) & ANACTRL_LDO_XO32M_STABMODE_MASK)
/*! @} */

/*! @name AUX_BIAS - AUX_BIAS */
/*! @{ */

#define ANACTRL_AUX_BIAS_VREF1VENABLE_MASK       (0x2U)
#define ANACTRL_AUX_BIAS_VREF1VENABLE_SHIFT      (1U)
/*! VREF1VENABLE - Control output of 1V reference voltage.
 *  0b0..Output of 1V reference voltage buffer is bypassed.
 *  0b1..Output of 1V reference voltage is enabled.
 */
#define ANACTRL_AUX_BIAS_VREF1VENABLE(x)         (((uint32_t)(((uint32_t)(x)) << ANACTRL_AUX_BIAS_VREF1VENABLE_SHIFT)) & ANACTRL_AUX_BIAS_VREF1VENABLE_MASK)

#define ANACTRL_AUX_BIAS_ITRIM_MASK              (0x7CU)
#define ANACTRL_AUX_BIAS_ITRIM_SHIFT             (2U)
/*! ITRIM - current trimming control word. */
#define ANACTRL_AUX_BIAS_ITRIM(x)                (((uint32_t)(((uint32_t)(x)) << ANACTRL_AUX_BIAS_ITRIM_SHIFT)) & ANACTRL_AUX_BIAS_ITRIM_MASK)

#define ANACTRL_AUX_BIAS_PTATITRIM_MASK          (0xF80U)
#define ANACTRL_AUX_BIAS_PTATITRIM_SHIFT         (7U)
/*! PTATITRIM - current trimming control word for ptat current. */
#define ANACTRL_AUX_BIAS_PTATITRIM(x)            (((uint32_t)(((uint32_t)(x)) << ANACTRL_AUX_BIAS_PTATITRIM_SHIFT)) & ANACTRL_AUX_BIAS_PTATITRIM_MASK)

#define ANACTRL_AUX_BIAS_VREF1VTRIM_MASK         (0x1F000U)
#define ANACTRL_AUX_BIAS_VREF1VTRIM_SHIFT        (12U)
/*! VREF1VTRIM - voltage trimming control word. */
#define ANACTRL_AUX_BIAS_VREF1VTRIM(x)           (((uint32_t)(((uint32_t)(x)) << ANACTRL_AUX_BIAS_VREF1VTRIM_SHIFT)) & ANACTRL_AUX_BIAS_VREF1VTRIM_MASK)

#define ANACTRL_AUX_BIAS_VREF1VCURVETRIM_MASK    (0xE0000U)
#define ANACTRL_AUX_BIAS_VREF1VCURVETRIM_SHIFT   (17U)
/*! VREF1VCURVETRIM - Control bit to configure trimming state of mirror. */
#define ANACTRL_AUX_BIAS_VREF1VCURVETRIM(x)      (((uint32_t)(((uint32_t)(x)) << ANACTRL_AUX_BIAS_VREF1VCURVETRIM_SHIFT)) & ANACTRL_AUX_BIAS_VREF1VCURVETRIM_MASK)

#define ANACTRL_AUX_BIAS_ITRIMCTRL0_MASK         (0x100000U)
#define ANACTRL_AUX_BIAS_ITRIMCTRL0_SHIFT        (20U)
/*! ITRIMCTRL0 - Control bit to configure trimming state of mirror. */
#define ANACTRL_AUX_BIAS_ITRIMCTRL0(x)           (((uint32_t)(((uint32_t)(x)) << ANACTRL_AUX_BIAS_ITRIMCTRL0_SHIFT)) & ANACTRL_AUX_BIAS_ITRIMCTRL0_MASK)

#define ANACTRL_AUX_BIAS_ITRIMCTRL1_MASK         (0x200000U)
#define ANACTRL_AUX_BIAS_ITRIMCTRL1_SHIFT        (21U)
/*! ITRIMCTRL1 - Control bit to configure trimming state of mirror. */
#define ANACTRL_AUX_BIAS_ITRIMCTRL1(x)           (((uint32_t)(((uint32_t)(x)) << ANACTRL_AUX_BIAS_ITRIMCTRL1_SHIFT)) & ANACTRL_AUX_BIAS_ITRIMCTRL1_MASK)
/*! @} */

/*! @name OSC_TESTBUS - Oscillators Analog Macrobloc ACBUS and DCBUS control */
/*! @{ */

#define ANACTRL_OSC_TESTBUS_ACBUS_MASK           (0x3FU)
#define ANACTRL_OSC_TESTBUS_ACBUS_SHIFT          (0U)
/*! ACBUS - Alternate current BUS */
#define ANACTRL_OSC_TESTBUS_ACBUS(x)             (((uint32_t)(((uint32_t)(x)) << ANACTRL_OSC_TESTBUS_ACBUS_SHIFT)) & ANACTRL_OSC_TESTBUS_ACBUS_MASK)

#define ANACTRL_OSC_TESTBUS_DCBUS_MASK           (0x3F0000U)
#define ANACTRL_OSC_TESTBUS_DCBUS_SHIFT          (16U)
/*! DCBUS - Direct current BUS */
#define ANACTRL_OSC_TESTBUS_DCBUS(x)             (((uint32_t)(((uint32_t)(x)) << ANACTRL_OSC_TESTBUS_DCBUS_SHIFT)) & ANACTRL_OSC_TESTBUS_DCBUS_MASK)
/*! @} */

/*! @name DUMMY_CTRL - Dummy Control bus to analog modules */
/*! @{ */

#define ANACTRL_DUMMY_CTRL_XO32M_ADC_CLK_MODE_MASK (0xC00U)
#define ANACTRL_DUMMY_CTRL_XO32M_ADC_CLK_MODE_SHIFT (10U)
/*! XO32M_ADC_CLK_MODE - Control High speed Crystal oscillator mode of the ADC clock.
 *  0b00..High speed Crystal oscillator output to ADC is disabled.
 *  0b01..High speed Crystal oscillator output to ADC is enable.
 */
#define ANACTRL_DUMMY_CTRL_XO32M_ADC_CLK_MODE(x) (((uint32_t)(((uint32_t)(x)) << ANACTRL_DUMMY_CTRL_XO32M_ADC_CLK_MODE_SHIFT)) & ANACTRL_DUMMY_CTRL_XO32M_ADC_CLK_MODE_MASK)
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

