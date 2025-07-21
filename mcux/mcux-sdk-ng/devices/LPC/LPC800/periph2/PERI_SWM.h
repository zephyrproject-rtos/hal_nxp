/*
** ###################################################################
**     Processors:          LPC844M201JBD48
**                          LPC844M201JBD64
**                          LPC844M201JHI33
**                          LPC844M201JHI48
**                          LPC845M301JBD48
**                          LPC845M301JBD64
**                          LPC845M301JHI33
**                          LPC845M301JHI48
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for SWM
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2016-08-12)
**         Initial version.
**     - rev. 1.1 (2016-11-25)
**         Update CANFD and Classic CAN register.
**         Add MAC TIMERSTAMP registers.
**     - rev. 1.2 (2017-06-08)
**         Remove RTC_CTRL_RTC_OSC_BYPASS.
**         SYSCON_ARMTRCLKDIV rename to SYSCON_ARMTRACECLKDIV.
**         Remove RESET and HALT from SYSCON_AHBCLKDIV.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_SWM.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for SWM
 *
 * CMSIS Peripheral Access Layer for SWM
 */

#if !defined(PERI_SWM_H_)
#define PERI_SWM_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_LPC844M201JBD48) || defined(CPU_LPC844M201JBD64) || defined(CPU_LPC844M201JHI33) || defined(CPU_LPC844M201JHI48))
#include "LPC844_COMMON.h"
#elif (defined(CPU_LPC845M301JBD48) || defined(CPU_LPC845M301JBD64) || defined(CPU_LPC845M301JHI33) || defined(CPU_LPC845M301JHI48))
#include "LPC845_COMMON.h"
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
   -- SWM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SWM_Peripheral_Access_Layer SWM Peripheral Access Layer
 * @{
 */

/** SWM - Size of Registers Arrays */
#define SWM_PINASSIGN_PINASSIGN_DATA_PINASSIGN_DATA_PINASSIGN_DATA_COUNT 15u

/** SWM - Register Layout Typedef */
typedef struct {
  union {                                          /* offset: 0x0 */
    struct {                                         /* offset: 0x0 */
      __IO uint32_t PINASSIGN0;                        /**< Pin assign register 0. Assign movable functions U0_TXD, U0_RXD, U0_RTS, U0_CTS., offset: 0x0 */
      __IO uint32_t PINASSIGN1;                        /**< Pin assign register 1. Assign movable functions U0_SCLK, U1_TXD, U1_RXD, U1_RTS., offset: 0x4 */
      __IO uint32_t PINASSIGN2;                        /**< Pin assign register 2. Assign movable functions U1_CTS, U1_SCLK, U2_TXD, U2_RXD., offset: 0x8 */
      __IO uint32_t PINASSIGN3;                        /**< Pin assign register 3. Assign movable function U2_RTS, U2_CTS, U2_SCLK, SPI0_SCK., offset: 0xC */
      __IO uint32_t PINASSIGN4;                        /**< Pin assign register 4. Assign movable functions SPI0_MOSI, SPI0_MISO, SPI0_SSEL0, SPI0_SSEL1., offset: 0x10 */
      __IO uint32_t PINASSIGN5;                        /**< Pin assign register 5. Assign movable functions SPI0_SSEL2, SPI0_SSEL3, SPI1_SCK, SPI1_MOSI, offset: 0x14 */
      __IO uint32_t PINASSIGN6;                        /**< Pin assign register 6. Assign movable functions SPI1_MISO, SPI1_SSEL0, SPI1_SSEL1, SCT0_IN0., offset: 0x18 */
      __IO uint32_t PINASSIGN7;                        /**< Pin assign register 7. Assign movable functions SCT_IN1, SCT_IN2, SCT_IN3, SCT_OUT0., offset: 0x1C */
      __IO uint32_t PINASSIGN8;                        /**< Pin assign register 8. Assign movable functions SCT_OUT1, SCT_OUT2, SCT_OUT3, SCT_OUT4., offset: 0x20 */
      __IO uint32_t PINASSIGN9;                        /**< Pin assign register 9. Assign movable functions SCT_OUT5, SCT_OUT6, I2C1_SDA, I2C1_SCL., offset: 0x24 */
      __IO uint32_t PINASSIGN10;                       /**< Pin assign register 10. Assign movable functions I2C2_SDA, I2C2_SCL, I2C3_SDA, I2C3_SCL., offset: 0x28 */
      __IO uint32_t PINASSIGN11;                       /**< Pin assign register 11. Assign movable functions COMP0_OUT, CLKOUT, GPIOINT_BMATCH, UART3_TXD, offset: 0x2C */
      __IO uint32_t PINASSIGN12;                       /**< Pin assign register 12. Assign movable functions UART3_RXD, UART3_SCLK, UART4_TXD, UART4_RXD., offset: 0x30 */
      __IO uint32_t PINASSIGN13;                       /**< Pin assign register 13. Assign movable functions UART4_SCLK, T0_MAT0, T0_MAT1, T0_MAT2., offset: 0x34 */
      __IO uint32_t PINASSIGN14;                       /**< Pin assign register 14. Assign movable functions T0_MAT3, T0_CAP0, T0_CAP1, T0_CAP2., offset: 0x38 */
    } PINASSIGN;
    __IO uint32_t PINASSIGN_DATA[SWM_PINASSIGN_PINASSIGN_DATA_PINASSIGN_DATA_PINASSIGN_DATA_COUNT];   /**< Pin assign register, array offset: 0x0, array step: 0x4 */
  };
       uint8_t RESERVED_0[388];
  __IO uint32_t PINENABLE0;                        /**< Pin enable register 0. Enables fixed-pin functions ACMP_I0, ACMP_I1, SWCLK, SWDIO, XTALIN, XTALOUT, RESET, CLKIN, VDDCMP and so on., offset: 0x1C0 */
  __IO uint32_t PINENABLE1;                        /**< Pin enable register 1. Enables fixed-pin functions CAPT_X4, CAPT_X5, CAPT_X6, CAPT_X7, CAPT_X8, CAPT_X4, CAPT_YL and CAPT_YH., offset: 0x1C4 */
} SWM_Type;

/* ----------------------------------------------------------------------------
   -- SWM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SWM_Register_Masks SWM Register Masks
 * @{
 */

/*! @name PINASSIGN0 - Pin assign register 0. Assign movable functions U0_TXD, U0_RXD, U0_RTS, U0_CTS. */
/*! @{ */

#define SWM_PINASSIGN0_U0_TXD_O_MASK             (0xFFU)
#define SWM_PINASSIGN0_U0_TXD_O_SHIFT            (0U)
/*! U0_TXD_O - U0_TXD function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0 (=0x20)
 *    to PIO1_21(=0x35) .
 */
#define SWM_PINASSIGN0_U0_TXD_O(x)               (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN0_U0_TXD_O_SHIFT)) & SWM_PINASSIGN0_U0_TXD_O_MASK)

#define SWM_PINASSIGN0_U0_RXD_I_MASK             (0xFF00U)
#define SWM_PINASSIGN0_U0_RXD_I_SHIFT            (8U)
/*! U0_RXD_I - U0_RXD function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0 (=0x20)
 *    to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN0_U0_RXD_I(x)               (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN0_U0_RXD_I_SHIFT)) & SWM_PINASSIGN0_U0_RXD_I_MASK)

#define SWM_PINASSIGN0_U0_RTS_O_MASK             (0xFF0000U)
#define SWM_PINASSIGN0_U0_RTS_O_SHIFT            (16U)
/*! U0_RTS_O - U0_RTS function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0 (=0x20)
 *    to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN0_U0_RTS_O(x)               (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN0_U0_RTS_O_SHIFT)) & SWM_PINASSIGN0_U0_RTS_O_MASK)

#define SWM_PINASSIGN0_U0_CTS_I_MASK             (0xFF000000U)
#define SWM_PINASSIGN0_U0_CTS_I_SHIFT            (24U)
/*! U0_CTS_I - U0_CTS function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0 (=0x20)
 *    to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN0_U0_CTS_I(x)               (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN0_U0_CTS_I_SHIFT)) & SWM_PINASSIGN0_U0_CTS_I_MASK)
/*! @} */

/*! @name PINASSIGN1 - Pin assign register 1. Assign movable functions U0_SCLK, U1_TXD, U1_RXD, U1_RTS. */
/*! @{ */

#define SWM_PINASSIGN1_U0_SCLK_IO_MASK           (0xFFU)
#define SWM_PINASSIGN1_U0_SCLK_IO_SHIFT          (0U)
/*! U0_SCLK_IO - U0_SCLK function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0
 *    (=0x20) to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN1_U0_SCLK_IO(x)             (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN1_U0_SCLK_IO_SHIFT)) & SWM_PINASSIGN1_U0_SCLK_IO_MASK)

#define SWM_PINASSIGN1_U1_TXD_O_MASK             (0xFF00U)
#define SWM_PINASSIGN1_U1_TXD_O_SHIFT            (8U)
/*! U1_TXD_O - U1_TXD function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0 (=0x20)
 *    to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN1_U1_TXD_O(x)               (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN1_U1_TXD_O_SHIFT)) & SWM_PINASSIGN1_U1_TXD_O_MASK)

#define SWM_PINASSIGN1_U1_RXD_I_MASK             (0xFF0000U)
#define SWM_PINASSIGN1_U1_RXD_I_SHIFT            (16U)
/*! U1_RXD_I - U1_RXD function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0 (=0x20)
 *    to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN1_U1_RXD_I(x)               (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN1_U1_RXD_I_SHIFT)) & SWM_PINASSIGN1_U1_RXD_I_MASK)

#define SWM_PINASSIGN1_U1_RTS_O_MASK             (0xFF000000U)
#define SWM_PINASSIGN1_U1_RTS_O_SHIFT            (24U)
/*! U1_RTS_O - U1_RTS function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0 (=0x20)
 *    to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN1_U1_RTS_O(x)               (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN1_U1_RTS_O_SHIFT)) & SWM_PINASSIGN1_U1_RTS_O_MASK)
/*! @} */

/*! @name PINASSIGN2 - Pin assign register 2. Assign movable functions U1_CTS, U1_SCLK, U2_TXD, U2_RXD. */
/*! @{ */

#define SWM_PINASSIGN2_U1_CTS_I_MASK             (0xFFU)
#define SWM_PINASSIGN2_U1_CTS_I_SHIFT            (0U)
/*! U1_CTS_I - U1_CTS function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0 (=0x20)
 *    to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN2_U1_CTS_I(x)               (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN2_U1_CTS_I_SHIFT)) & SWM_PINASSIGN2_U1_CTS_I_MASK)

#define SWM_PINASSIGN2_U1_SCLK_IO_MASK           (0xFF00U)
#define SWM_PINASSIGN2_U1_SCLK_IO_SHIFT          (8U)
/*! U1_SCLK_IO - U1_SCLK function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0
 *    (=0x20) to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN2_U1_SCLK_IO(x)             (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN2_U1_SCLK_IO_SHIFT)) & SWM_PINASSIGN2_U1_SCLK_IO_MASK)

#define SWM_PINASSIGN2_U2_TXD_O_MASK             (0xFF0000U)
#define SWM_PINASSIGN2_U2_TXD_O_SHIFT            (16U)
/*! U2_TXD_O - U2_TXD function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0 (=0x20)
 *    to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN2_U2_TXD_O(x)               (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN2_U2_TXD_O_SHIFT)) & SWM_PINASSIGN2_U2_TXD_O_MASK)

#define SWM_PINASSIGN2_U2_RXD_I_MASK             (0xFF000000U)
#define SWM_PINASSIGN2_U2_RXD_I_SHIFT            (24U)
/*! U2_RXD_I - U2_RXD function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0 (=0x20)
 *    to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN2_U2_RXD_I(x)               (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN2_U2_RXD_I_SHIFT)) & SWM_PINASSIGN2_U2_RXD_I_MASK)
/*! @} */

/*! @name PINASSIGN3 - Pin assign register 3. Assign movable function U2_RTS, U2_CTS, U2_SCLK, SPI0_SCK. */
/*! @{ */

#define SWM_PINASSIGN3_U2_RTS_O_MASK             (0xFFU)
#define SWM_PINASSIGN3_U2_RTS_O_SHIFT            (0U)
/*! U2_RTS_O - U2_RTS function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0 (=0x20)
 *    to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN3_U2_RTS_O(x)               (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN3_U2_RTS_O_SHIFT)) & SWM_PINASSIGN3_U2_RTS_O_MASK)

#define SWM_PINASSIGN3_U2_CTS_I_MASK             (0xFF00U)
#define SWM_PINASSIGN3_U2_CTS_I_SHIFT            (8U)
/*! U2_CTS_I - U2_CTS function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0 (=0x20)
 *    to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN3_U2_CTS_I(x)               (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN3_U2_CTS_I_SHIFT)) & SWM_PINASSIGN3_U2_CTS_I_MASK)

#define SWM_PINASSIGN3_U2_SCLK_IO_MASK           (0xFF0000U)
#define SWM_PINASSIGN3_U2_SCLK_IO_SHIFT          (16U)
/*! U2_SCLK_IO - U2_SCLK function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0
 *    (=0x20) to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN3_U2_SCLK_IO(x)             (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN3_U2_SCLK_IO_SHIFT)) & SWM_PINASSIGN3_U2_SCLK_IO_MASK)

#define SWM_PINASSIGN3_SPI0_SCK_IO_MASK          (0xFF000000U)
#define SWM_PINASSIGN3_SPI0_SCK_IO_SHIFT         (24U)
/*! SPI0_SCK_IO - SPI0_SCK function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0
 *    (=0x20) to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN3_SPI0_SCK_IO(x)            (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN3_SPI0_SCK_IO_SHIFT)) & SWM_PINASSIGN3_SPI0_SCK_IO_MASK)
/*! @} */

/*! @name PINASSIGN4 - Pin assign register 4. Assign movable functions SPI0_MOSI, SPI0_MISO, SPI0_SSEL0, SPI0_SSEL1. */
/*! @{ */

#define SWM_PINASSIGN4_SPI0_MOSI_IO_MASK         (0xFFU)
#define SWM_PINASSIGN4_SPI0_MOSI_IO_SHIFT        (0U)
/*! SPI0_MOSI_IO - SPI0_MOSI function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0
 *    (=0x20) to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN4_SPI0_MOSI_IO(x)           (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN4_SPI0_MOSI_IO_SHIFT)) & SWM_PINASSIGN4_SPI0_MOSI_IO_MASK)

#define SWM_PINASSIGN4_SPI0_MISO_IO_MASK         (0xFF00U)
#define SWM_PINASSIGN4_SPI0_MISO_IO_SHIFT        (8U)
/*! SPI0_MISO_IO - SPI0_MISIO function assignment. The value is the pin number to be assigned to
 *    this function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0
 *    (=0x20) to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN4_SPI0_MISO_IO(x)           (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN4_SPI0_MISO_IO_SHIFT)) & SWM_PINASSIGN4_SPI0_MISO_IO_MASK)

#define SWM_PINASSIGN4_SPI0_SSEL0_IO_MASK        (0xFF0000U)
#define SWM_PINASSIGN4_SPI0_SSEL0_IO_SHIFT       (16U)
/*! SPI0_SSEL0_IO - SPI0_SSEL0 function assignment. The value is the pin number to be assigned to
 *    this function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from
 *    PIO1_0 (=0x20) to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN4_SPI0_SSEL0_IO(x)          (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN4_SPI0_SSEL0_IO_SHIFT)) & SWM_PINASSIGN4_SPI0_SSEL0_IO_MASK)

#define SWM_PINASSIGN4_SPI0_SSEL1_IO_MASK        (0xFF000000U)
#define SWM_PINASSIGN4_SPI0_SSEL1_IO_SHIFT       (24U)
/*! SPI0_SSEL1_IO - SPI0_SSEL1 function assignment. The value is the pin number to be assigned to
 *    this function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from
 *    PIO1_0 (=0x20) to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN4_SPI0_SSEL1_IO(x)          (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN4_SPI0_SSEL1_IO_SHIFT)) & SWM_PINASSIGN4_SPI0_SSEL1_IO_MASK)
/*! @} */

/*! @name PINASSIGN5 - Pin assign register 5. Assign movable functions SPI0_SSEL2, SPI0_SSEL3, SPI1_SCK, SPI1_MOSI */
/*! @{ */

#define SWM_PINASSIGN5_SPI0_SSEL2_IO_MASK        (0xFFU)
#define SWM_PINASSIGN5_SPI0_SSEL2_IO_SHIFT       (0U)
/*! SPI0_SSEL2_IO - SPI0_SSEL2 function assignment. The value is the pin number to be assigned to
 *    this function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from
 *    PIO1_0 (=0x20) to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN5_SPI0_SSEL2_IO(x)          (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN5_SPI0_SSEL2_IO_SHIFT)) & SWM_PINASSIGN5_SPI0_SSEL2_IO_MASK)

#define SWM_PINASSIGN5_SPI0_SSEL3_IO_MASK        (0xFF00U)
#define SWM_PINASSIGN5_SPI0_SSEL3_IO_SHIFT       (8U)
/*! SPI0_SSEL3_IO - SPI0_SSEL3 function assignment. The value is the pin number to be assigned to
 *    this function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from
 *    PIO1_0 (=0x20) to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN5_SPI0_SSEL3_IO(x)          (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN5_SPI0_SSEL3_IO_SHIFT)) & SWM_PINASSIGN5_SPI0_SSEL3_IO_MASK)

#define SWM_PINASSIGN5_SPI1_SCK_IO_MASK          (0xFF0000U)
#define SWM_PINASSIGN5_SPI1_SCK_IO_SHIFT         (16U)
/*! SPI1_SCK_IO - SPI1_SCK function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0
 *    (=0x20) to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN5_SPI1_SCK_IO(x)            (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN5_SPI1_SCK_IO_SHIFT)) & SWM_PINASSIGN5_SPI1_SCK_IO_MASK)

#define SWM_PINASSIGN5_SPI1_MOSI_IO_MASK         (0xFF000000U)
#define SWM_PINASSIGN5_SPI1_MOSI_IO_SHIFT        (24U)
/*! SPI1_MOSI_IO - SPI1_MOSI function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0
 *    (=0x20) to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN5_SPI1_MOSI_IO(x)           (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN5_SPI1_MOSI_IO_SHIFT)) & SWM_PINASSIGN5_SPI1_MOSI_IO_MASK)
/*! @} */

/*! @name PINASSIGN6 - Pin assign register 6. Assign movable functions SPI1_MISO, SPI1_SSEL0, SPI1_SSEL1, SCT0_IN0. */
/*! @{ */

#define SWM_PINASSIGN6_SPI1_MISO_IO_MASK         (0xFFU)
#define SWM_PINASSIGN6_SPI1_MISO_IO_SHIFT        (0U)
/*! SPI1_MISO_IO - SPI1_MISO function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0
 *    (=0x20) to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN6_SPI1_MISO_IO(x)           (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN6_SPI1_MISO_IO_SHIFT)) & SWM_PINASSIGN6_SPI1_MISO_IO_MASK)

#define SWM_PINASSIGN6_SPI1_SSEL0_IO_MASK        (0xFF00U)
#define SWM_PINASSIGN6_SPI1_SSEL0_IO_SHIFT       (8U)
/*! SPI1_SSEL0_IO - SPI1_SSEL0 function assignment. The value is the pin number to be assigned to
 *    this function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from
 *    PIO1_0 (=0x20) to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN6_SPI1_SSEL0_IO(x)          (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN6_SPI1_SSEL0_IO_SHIFT)) & SWM_PINASSIGN6_SPI1_SSEL0_IO_MASK)

#define SWM_PINASSIGN6_SPI1_SSEL1_IO_MASK        (0xFF0000U)
#define SWM_PINASSIGN6_SPI1_SSEL1_IO_SHIFT       (16U)
/*! SPI1_SSEL1_IO - SPI1_SSEL1 function assignment. The value is the pin number to be assigned to
 *    this function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from
 *    PIO1_0 (=0x20) to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN6_SPI1_SSEL1_IO(x)          (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN6_SPI1_SSEL1_IO_SHIFT)) & SWM_PINASSIGN6_SPI1_SSEL1_IO_MASK)

#define SWM_PINASSIGN6_SCT0_GPIO_IN_A_I_MASK     (0xFF000000U)
#define SWM_PINASSIGN6_SCT0_GPIO_IN_A_I_SHIFT    (24U)
/*! SCT0_GPIO_IN_A_I - SCT0_GPIO_IN_A function assignment. The value is the pin number to be
 *    assigned to this function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and
 *    from PIO1_0 (=0x20) to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN6_SCT0_GPIO_IN_A_I(x)       (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN6_SCT0_GPIO_IN_A_I_SHIFT)) & SWM_PINASSIGN6_SCT0_GPIO_IN_A_I_MASK)
/*! @} */

/*! @name PINASSIGN7 - Pin assign register 7. Assign movable functions SCT_IN1, SCT_IN2, SCT_IN3, SCT_OUT0. */
/*! @{ */

#define SWM_PINASSIGN7_SCT0_GPIO_IN_B_I_MASK     (0xFFU)
#define SWM_PINASSIGN7_SCT0_GPIO_IN_B_I_SHIFT    (0U)
/*! SCT0_GPIO_IN_B_I - SCT0_GPIO_IN_B function assignment. The value is the pin number to be
 *    assigned to this function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and
 *    from PIO1_0 (=0x20) to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN7_SCT0_GPIO_IN_B_I(x)       (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN7_SCT0_GPIO_IN_B_I_SHIFT)) & SWM_PINASSIGN7_SCT0_GPIO_IN_B_I_MASK)

#define SWM_PINASSIGN7_SCT0_GPIO_IN_C_I_MASK     (0xFF00U)
#define SWM_PINASSIGN7_SCT0_GPIO_IN_C_I_SHIFT    (8U)
/*! SCT0_GPIO_IN_C_I - SCT0_GPIO_IN_C function assignment. The value is the pin number to be
 *    assigned to this function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and
 *    from PIO1_0 (=0x20) to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN7_SCT0_GPIO_IN_C_I(x)       (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN7_SCT0_GPIO_IN_C_I_SHIFT)) & SWM_PINASSIGN7_SCT0_GPIO_IN_C_I_MASK)

#define SWM_PINASSIGN7_SCT0_GPIO_IN_D_I_MASK     (0xFF0000U)
#define SWM_PINASSIGN7_SCT0_GPIO_IN_D_I_SHIFT    (16U)
/*! SCT0_GPIO_IN_D_I - SCT0_GPIO_IN_D function assignment. The value is the pin number to be
 *    assigned to this function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and
 *    from PIO1_0 (=0x20) to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN7_SCT0_GPIO_IN_D_I(x)       (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN7_SCT0_GPIO_IN_D_I_SHIFT)) & SWM_PINASSIGN7_SCT0_GPIO_IN_D_I_MASK)

#define SWM_PINASSIGN7_SCT_OUT0_O_MASK           (0xFF000000U)
#define SWM_PINASSIGN7_SCT_OUT0_O_SHIFT          (24U)
/*! SCT_OUT0_O - SCT_OUT0 function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0
 *    (=0x20) to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN7_SCT_OUT0_O(x)             (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN7_SCT_OUT0_O_SHIFT)) & SWM_PINASSIGN7_SCT_OUT0_O_MASK)
/*! @} */

/*! @name PINASSIGN8 - Pin assign register 8. Assign movable functions SCT_OUT1, SCT_OUT2, SCT_OUT3, SCT_OUT4. */
/*! @{ */

#define SWM_PINASSIGN8_SCT_OUT1_O_MASK           (0xFFU)
#define SWM_PINASSIGN8_SCT_OUT1_O_SHIFT          (0U)
/*! SCT_OUT1_O - SCT_OUT1 function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0
 *    (=0x20) to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN8_SCT_OUT1_O(x)             (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN8_SCT_OUT1_O_SHIFT)) & SWM_PINASSIGN8_SCT_OUT1_O_MASK)

#define SWM_PINASSIGN8_SCT_OUT2_O_MASK           (0xFF00U)
#define SWM_PINASSIGN8_SCT_OUT2_O_SHIFT          (8U)
/*! SCT_OUT2_O - SCT_OUT2 function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0
 *    (=0x20) to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN8_SCT_OUT2_O(x)             (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN8_SCT_OUT2_O_SHIFT)) & SWM_PINASSIGN8_SCT_OUT2_O_MASK)

#define SWM_PINASSIGN8_SCT_OUT3_O_MASK           (0xFF0000U)
#define SWM_PINASSIGN8_SCT_OUT3_O_SHIFT          (16U)
/*! SCT_OUT3_O - SCT_OUT3 function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0
 *    (=0x20) to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN8_SCT_OUT3_O(x)             (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN8_SCT_OUT3_O_SHIFT)) & SWM_PINASSIGN8_SCT_OUT3_O_MASK)

#define SWM_PINASSIGN8_SCT_OUT4_O_MASK           (0xFF000000U)
#define SWM_PINASSIGN8_SCT_OUT4_O_SHIFT          (24U)
/*! SCT_OUT4_O - SCT_OUT4 function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0
 *    (=0x20) to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN8_SCT_OUT4_O(x)             (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN8_SCT_OUT4_O_SHIFT)) & SWM_PINASSIGN8_SCT_OUT4_O_MASK)
/*! @} */

/*! @name PINASSIGN9 - Pin assign register 9. Assign movable functions SCT_OUT5, SCT_OUT6, I2C1_SDA, I2C1_SCL. */
/*! @{ */

#define SWM_PINASSIGN9_SCT_OUT5_O_MASK           (0xFFU)
#define SWM_PINASSIGN9_SCT_OUT5_O_SHIFT          (0U)
/*! SCT_OUT5_O - SCT_OUT5 function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0
 *    (=0x20) to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN9_SCT_OUT5_O(x)             (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN9_SCT_OUT5_O_SHIFT)) & SWM_PINASSIGN9_SCT_OUT5_O_MASK)

#define SWM_PINASSIGN9_SCT_OUT6_O_MASK           (0xFF00U)
#define SWM_PINASSIGN9_SCT_OUT6_O_SHIFT          (8U)
/*! SCT_OUT6_O - SCT_OUT6 function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0
 *    (=0x20) to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN9_SCT_OUT6_O(x)             (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN9_SCT_OUT6_O_SHIFT)) & SWM_PINASSIGN9_SCT_OUT6_O_MASK)

#define SWM_PINASSIGN9_I2C1_SDA_IO_MASK          (0xFF0000U)
#define SWM_PINASSIGN9_I2C1_SDA_IO_SHIFT         (16U)
/*! I2C1_SDA_IO - I2C1_SDA function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0
 *    (=0x20) to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN9_I2C1_SDA_IO(x)            (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN9_I2C1_SDA_IO_SHIFT)) & SWM_PINASSIGN9_I2C1_SDA_IO_MASK)

#define SWM_PINASSIGN9_I2C1_SCL_IO_MASK          (0xFF000000U)
#define SWM_PINASSIGN9_I2C1_SCL_IO_SHIFT         (24U)
/*! I2C1_SCL_IO - I2C1_SCL function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0
 *    (=0x20) to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN9_I2C1_SCL_IO(x)            (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN9_I2C1_SCL_IO_SHIFT)) & SWM_PINASSIGN9_I2C1_SCL_IO_MASK)
/*! @} */

/*! @name PINASSIGN10 - Pin assign register 10. Assign movable functions I2C2_SDA, I2C2_SCL, I2C3_SDA, I2C3_SCL. */
/*! @{ */

#define SWM_PINASSIGN10_I2C2_SDA_IO_MASK         (0xFFU)
#define SWM_PINASSIGN10_I2C2_SDA_IO_SHIFT        (0U)
/*! I2C2_SDA_IO - I2C1_SDA function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0
 *    (=0x20) to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN10_I2C2_SDA_IO(x)           (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN10_I2C2_SDA_IO_SHIFT)) & SWM_PINASSIGN10_I2C2_SDA_IO_MASK)

#define SWM_PINASSIGN10_I2C2_SCL_IO_MASK         (0xFF00U)
#define SWM_PINASSIGN10_I2C2_SCL_IO_SHIFT        (8U)
/*! I2C2_SCL_IO - I2C1_SCL function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0
 *    (=0x20) to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN10_I2C2_SCL_IO(x)           (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN10_I2C2_SCL_IO_SHIFT)) & SWM_PINASSIGN10_I2C2_SCL_IO_MASK)

#define SWM_PINASSIGN10_I2C3_SDA_IO_MASK         (0xFF0000U)
#define SWM_PINASSIGN10_I2C3_SDA_IO_SHIFT        (16U)
/*! I2C3_SDA_IO - I2C3_SDA function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0
 *    (=0x20) to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN10_I2C3_SDA_IO(x)           (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN10_I2C3_SDA_IO_SHIFT)) & SWM_PINASSIGN10_I2C3_SDA_IO_MASK)

#define SWM_PINASSIGN10_I2C3_SCL_IO_MASK         (0xFF000000U)
#define SWM_PINASSIGN10_I2C3_SCL_IO_SHIFT        (24U)
/*! I2C3_SCL_IO - I2C3_SCL function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0
 *    (=0x20) to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN10_I2C3_SCL_IO(x)           (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN10_I2C3_SCL_IO_SHIFT)) & SWM_PINASSIGN10_I2C3_SCL_IO_MASK)
/*! @} */

/*! @name PINASSIGN11 - Pin assign register 11. Assign movable functions COMP0_OUT, CLKOUT, GPIOINT_BMATCH, UART3_TXD */
/*! @{ */

#define SWM_PINASSIGN11_COMP0_OUT_O_MASK         (0xFFU)
#define SWM_PINASSIGN11_COMP0_OUT_O_SHIFT        (0U)
/*! COMP0_OUT_O - COMP0_OUT function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0
 *    (=0x20) to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN11_COMP0_OUT_O(x)           (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN11_COMP0_OUT_O_SHIFT)) & SWM_PINASSIGN11_COMP0_OUT_O_MASK)

#define SWM_PINASSIGN11_CLKOUT_O_MASK            (0xFF00U)
#define SWM_PINASSIGN11_CLKOUT_O_SHIFT           (8U)
/*! CLKOUT_O - CLKOUT function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0 (=0x20)
 *    to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN11_CLKOUT_O(x)              (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN11_CLKOUT_O_SHIFT)) & SWM_PINASSIGN11_CLKOUT_O_MASK)

#define SWM_PINASSIGN11_GPIO_INT_BMAT_O_MASK     (0xFF0000U)
#define SWM_PINASSIGN11_GPIO_INT_BMAT_O_SHIFT    (16U)
/*! GPIO_INT_BMAT_O - GPIO_INT_BMAT function assignment. The value is the pin number to be assigned
 *    to this function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from
 *    PIO1_0 (=0x20) to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN11_GPIO_INT_BMAT_O(x)       (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN11_GPIO_INT_BMAT_O_SHIFT)) & SWM_PINASSIGN11_GPIO_INT_BMAT_O_MASK)

#define SWM_PINASSIGN11_UART3_TXD_MASK           (0xFF000000U)
#define SWM_PINASSIGN11_UART3_TXD_SHIFT          (24U)
/*! UART3_TXD - UART3_TXD function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0
 *    (=0x20) to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN11_UART3_TXD(x)             (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN11_UART3_TXD_SHIFT)) & SWM_PINASSIGN11_UART3_TXD_MASK)
/*! @} */

/*! @name PINASSIGN12 - Pin assign register 12. Assign movable functions UART3_RXD, UART3_SCLK, UART4_TXD, UART4_RXD. */
/*! @{ */

#define SWM_PINASSIGN12_UART3_RXD_MASK           (0xFFU)
#define SWM_PINASSIGN12_UART3_RXD_SHIFT          (0U)
/*! UART3_RXD - UART3_RXD function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0
 *    (=0x20) to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN12_UART3_RXD(x)             (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN12_UART3_RXD_SHIFT)) & SWM_PINASSIGN12_UART3_RXD_MASK)

#define SWM_PINASSIGN12_UART3_SCLK_MASK          (0xFF00U)
#define SWM_PINASSIGN12_UART3_SCLK_SHIFT         (8U)
/*! UART3_SCLK - UART3_SCLK function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0
 *    (=0x20) to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN12_UART3_SCLK(x)            (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN12_UART3_SCLK_SHIFT)) & SWM_PINASSIGN12_UART3_SCLK_MASK)

#define SWM_PINASSIGN12_UART4_TXD_MASK           (0xFF0000U)
#define SWM_PINASSIGN12_UART4_TXD_SHIFT          (16U)
/*! UART4_TXD - UART4_TXD function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0
 *    (=0x20) to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN12_UART4_TXD(x)             (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN12_UART4_TXD_SHIFT)) & SWM_PINASSIGN12_UART4_TXD_MASK)

#define SWM_PINASSIGN12_UART4_RXD_MASK           (0xFF000000U)
#define SWM_PINASSIGN12_UART4_RXD_SHIFT          (24U)
/*! UART4_RXD - UART4_TXD function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0
 *    (=0x20) to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN12_UART4_RXD(x)             (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN12_UART4_RXD_SHIFT)) & SWM_PINASSIGN12_UART4_RXD_MASK)
/*! @} */

/*! @name PINASSIGN13 - Pin assign register 13. Assign movable functions UART4_SCLK, T0_MAT0, T0_MAT1, T0_MAT2. */
/*! @{ */

#define SWM_PINASSIGN13_UART4_SCLK_MASK          (0xFFU)
#define SWM_PINASSIGN13_UART4_SCLK_SHIFT         (0U)
/*! UART4_SCLK - UART4_SCLK function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0
 *    (=0x20) to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN13_UART4_SCLK(x)            (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN13_UART4_SCLK_SHIFT)) & SWM_PINASSIGN13_UART4_SCLK_MASK)

#define SWM_PINASSIGN13_T0_MAT0_MASK             (0xFF00U)
#define SWM_PINASSIGN13_T0_MAT0_SHIFT            (8U)
/*! T0_MAT0 - T0_MAT0 function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0 (=0x20)
 *    to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN13_T0_MAT0(x)               (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN13_T0_MAT0_SHIFT)) & SWM_PINASSIGN13_T0_MAT0_MASK)

#define SWM_PINASSIGN13_T0_MAT1_MASK             (0xFF0000U)
#define SWM_PINASSIGN13_T0_MAT1_SHIFT            (16U)
/*! T0_MAT1 - T0_MAT1 function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0 (=0x20)
 *    to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN13_T0_MAT1(x)               (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN13_T0_MAT1_SHIFT)) & SWM_PINASSIGN13_T0_MAT1_MASK)

#define SWM_PINASSIGN13_T0_MAT2_MASK             (0xFF000000U)
#define SWM_PINASSIGN13_T0_MAT2_SHIFT            (24U)
/*! T0_MAT2 - T0_MAT2 function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0 (=0x20)
 *    to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN13_T0_MAT2(x)               (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN13_T0_MAT2_SHIFT)) & SWM_PINASSIGN13_T0_MAT2_MASK)
/*! @} */

/*! @name PINASSIGN14 - Pin assign register 14. Assign movable functions T0_MAT3, T0_CAP0, T0_CAP1, T0_CAP2. */
/*! @{ */

#define SWM_PINASSIGN14_T0_MAT3_MASK             (0xFFU)
#define SWM_PINASSIGN14_T0_MAT3_SHIFT            (0U)
/*! T0_MAT3 - T0_MAT3 function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0 (=0x20)
 *    to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN14_T0_MAT3(x)               (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN14_T0_MAT3_SHIFT)) & SWM_PINASSIGN14_T0_MAT3_MASK)

#define SWM_PINASSIGN14_T0_CAP0_MASK             (0xFF00U)
#define SWM_PINASSIGN14_T0_CAP0_SHIFT            (8U)
/*! T0_CAP0 - T0_CAP0 function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0 (=0x20)
 *    to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN14_T0_CAP0(x)               (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN14_T0_CAP0_SHIFT)) & SWM_PINASSIGN14_T0_CAP0_MASK)

#define SWM_PINASSIGN14_T0_CAP1_MASK             (0xFF0000U)
#define SWM_PINASSIGN14_T0_CAP1_SHIFT            (16U)
/*! T0_CAP1 - T0_CAP1 function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0 (=0x20)
 *    to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN14_T0_CAP1(x)               (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN14_T0_CAP1_SHIFT)) & SWM_PINASSIGN14_T0_CAP1_MASK)

#define SWM_PINASSIGN14_T0_CAP2_MASK             (0xFF000000U)
#define SWM_PINASSIGN14_T0_CAP2_SHIFT            (24U)
/*! T0_CAP2 - T0_CAP2 function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0 (=0x20)
 *    to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN14_T0_CAP2(x)               (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN14_T0_CAP2_SHIFT)) & SWM_PINASSIGN14_T0_CAP2_MASK)
/*! @} */

/*! @name PINASSIGN_DATA - Pin assign register */
/*! @{ */

#define SWM_PINASSIGN_DATA_DATA0_MASK            (0xFFU)
#define SWM_PINASSIGN_DATA_DATA0_SHIFT           (0U)
/*! DATA0 - T0_MAT3 function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0 (=0x20)
 *    to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN_DATA_DATA0(x)              (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN_DATA_DATA0_SHIFT)) & SWM_PINASSIGN_DATA_DATA0_MASK)

#define SWM_PINASSIGN_DATA_DATA1_MASK            (0xFF00U)
#define SWM_PINASSIGN_DATA_DATA1_SHIFT           (8U)
/*! DATA1 - T0_CAP0 function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0 (=0x20)
 *    to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN_DATA_DATA1(x)              (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN_DATA_DATA1_SHIFT)) & SWM_PINASSIGN_DATA_DATA1_MASK)

#define SWM_PINASSIGN_DATA_DATA2_MASK            (0xFF0000U)
#define SWM_PINASSIGN_DATA_DATA2_SHIFT           (16U)
/*! DATA2 - T0_CAP1 function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0 (=0x20)
 *    to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN_DATA_DATA2(x)              (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN_DATA_DATA2_SHIFT)) & SWM_PINASSIGN_DATA_DATA2_MASK)

#define SWM_PINASSIGN_DATA_DATA3_MASK            (0xFF000000U)
#define SWM_PINASSIGN_DATA_DATA3_SHIFT           (24U)
/*! DATA3 - T0_CAP2 function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0 (=0x20)
 *    to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN_DATA_DATA3(x)              (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN_DATA_DATA3_SHIFT)) & SWM_PINASSIGN_DATA_DATA3_MASK)
/*! @} */

/* The count of SWM_PINASSIGN_DATA */
#define SWM_PINASSIGN_DATA_COUNT                 (15U)

/*! @name PINENABLE0 - Pin enable register 0. Enables fixed-pin functions ACMP_I0, ACMP_I1, SWCLK, SWDIO, XTALIN, XTALOUT, RESET, CLKIN, VDDCMP and so on. */
/*! @{ */

#define SWM_PINENABLE0_ACMP_I1_MASK              (0x1U)
#define SWM_PINENABLE0_ACMP_I1_SHIFT             (0U)
/*! ACMP_I1 - ACMP_I1 function select.
 *  0b0..ACMP_I1 enabled on pin PIO0_00.
 *  0b1..ACMP_I1 disabled.
 */
#define SWM_PINENABLE0_ACMP_I1(x)                (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_ACMP_I1_SHIFT)) & SWM_PINENABLE0_ACMP_I1_MASK)

#define SWM_PINENABLE0_ACMP_I2_MASK              (0x2U)
#define SWM_PINENABLE0_ACMP_I2_SHIFT             (1U)
/*! ACMP_I2 - ACMP_I2 function select.
 *  0b0..ACMP_I2 enabled on pin PIO0_1.
 *  0b1..ACMP_I2 disabled.
 */
#define SWM_PINENABLE0_ACMP_I2(x)                (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_ACMP_I2_SHIFT)) & SWM_PINENABLE0_ACMP_I2_MASK)

#define SWM_PINENABLE0_ACMP_I3_MASK              (0x4U)
#define SWM_PINENABLE0_ACMP_I3_SHIFT             (2U)
/*! ACMP_I3 - ACMP_I3 function select.
 *  0b0..ACMP_I3 enabled on pin PIO0_14.
 *  0b1..ACMP_I3 disabled.
 */
#define SWM_PINENABLE0_ACMP_I3(x)                (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_ACMP_I3_SHIFT)) & SWM_PINENABLE0_ACMP_I3_MASK)

#define SWM_PINENABLE0_ACMP_I4_MASK              (0x8U)
#define SWM_PINENABLE0_ACMP_I4_SHIFT             (3U)
/*! ACMP_I4 - ACMP_I4 function select.
 *  0b0..ACMP_I4 enabled on pin PIO0_23.
 *  0b1..ACMP_I4 disabled.
 */
#define SWM_PINENABLE0_ACMP_I4(x)                (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_ACMP_I4_SHIFT)) & SWM_PINENABLE0_ACMP_I4_MASK)

#define SWM_PINENABLE0_ACMP_I5_MASK              (0x10U)
#define SWM_PINENABLE0_ACMP_I5_SHIFT             (4U)
/*! ACMP_I5 - ACMP_I5 function select.
 *  0b0..ACMP_I5 enabled on pin PIO0_30.
 *  0b1..ACMP_I5 disabled.
 */
#define SWM_PINENABLE0_ACMP_I5(x)                (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_ACMP_I5_SHIFT)) & SWM_PINENABLE0_ACMP_I5_MASK)

#define SWM_PINENABLE0_SWCLK_MASK                (0x20U)
#define SWM_PINENABLE0_SWCLK_SHIFT               (5U)
/*! SWCLK - SWCLK function select.
 *  0b0..SWCLK enabled on pin PIO0_3.
 *  0b1..SWCLK disabled.
 */
#define SWM_PINENABLE0_SWCLK(x)                  (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_SWCLK_SHIFT)) & SWM_PINENABLE0_SWCLK_MASK)

#define SWM_PINENABLE0_SWDIO_MASK                (0x40U)
#define SWM_PINENABLE0_SWDIO_SHIFT               (6U)
/*! SWDIO - SWDIO function select.
 *  0b0..SWDIO enabled on pin PIO0_2.
 *  0b1..SWDIO disabled.
 */
#define SWM_PINENABLE0_SWDIO(x)                  (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_SWDIO_SHIFT)) & SWM_PINENABLE0_SWDIO_MASK)

#define SWM_PINENABLE0_XTALIN_MASK               (0x80U)
#define SWM_PINENABLE0_XTALIN_SHIFT              (7U)
/*! XTALIN - XTALIN function select.
 *  0b0..XTALIN enabled on pin PIO0_8.
 *  0b1..XTALIN disabled.
 */
#define SWM_PINENABLE0_XTALIN(x)                 (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_XTALIN_SHIFT)) & SWM_PINENABLE0_XTALIN_MASK)

#define SWM_PINENABLE0_XTALOUT_MASK              (0x100U)
#define SWM_PINENABLE0_XTALOUT_SHIFT             (8U)
/*! XTALOUT - XTALOUT function select.
 *  0b0..XTALOUT enabled on pin PIO0_9.
 *  0b1..XTALOUT disabled.
 */
#define SWM_PINENABLE0_XTALOUT(x)                (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_XTALOUT_SHIFT)) & SWM_PINENABLE0_XTALOUT_MASK)

#define SWM_PINENABLE0_RESETN_MASK               (0x200U)
#define SWM_PINENABLE0_RESETN_SHIFT              (9U)
/*! RESETN - RESETN function select.
 *  0b0..RESETN enabled on pin PIO0_5.
 *  0b1..RESETN disabled.
 */
#define SWM_PINENABLE0_RESETN(x)                 (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_RESETN_SHIFT)) & SWM_PINENABLE0_RESETN_MASK)

#define SWM_PINENABLE0_CLKIN_MASK                (0x400U)
#define SWM_PINENABLE0_CLKIN_SHIFT               (10U)
/*! CLKIN - CLKIN function select.
 *  0b0..CLKIN enabled on pin PIO0_1.
 *  0b1..CLKIN disabled.
 */
#define SWM_PINENABLE0_CLKIN(x)                  (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_CLKIN_SHIFT)) & SWM_PINENABLE0_CLKIN_MASK)

#define SWM_PINENABLE0_VDDCMP_MASK               (0x800U)
#define SWM_PINENABLE0_VDDCMP_SHIFT              (11U)
/*! VDDCMP - VDDCMP function select.
 *  0b0..VDDCMP enabled on pin PIO0_6.
 *  0b1..VDDCMP disabled.
 */
#define SWM_PINENABLE0_VDDCMP(x)                 (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_VDDCMP_SHIFT)) & SWM_PINENABLE0_VDDCMP_MASK)

#define SWM_PINENABLE0_I2C0_SDA_MASK             (0x1000U)
#define SWM_PINENABLE0_I2C0_SDA_SHIFT            (12U)
/*! I2C0_SDA - I2C0_SDA function select.
 *  0b0..I2C0_SDA enabled on pin PIO0_11.
 *  0b1..I2C0_SDA disabled.
 */
#define SWM_PINENABLE0_I2C0_SDA(x)               (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_I2C0_SDA_SHIFT)) & SWM_PINENABLE0_I2C0_SDA_MASK)

#define SWM_PINENABLE0_I2C0_SCL_MASK             (0x2000U)
#define SWM_PINENABLE0_I2C0_SCL_SHIFT            (13U)
/*! I2C0_SCL - I2C0_SCL function select.
 *  0b0..I2C0_SCL enabled on pin PIO0_10.
 *  0b1..I2C0_SCL disabled.
 */
#define SWM_PINENABLE0_I2C0_SCL(x)               (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_I2C0_SCL_SHIFT)) & SWM_PINENABLE0_I2C0_SCL_MASK)

#define SWM_PINENABLE0_ADC_0_MASK                (0x4000U)
#define SWM_PINENABLE0_ADC_0_SHIFT               (14U)
/*! ADC_0 - ADC_0 function select.
 *  0b0..ADC_0 enabled on pin PIO0_7.
 *  0b1..ADC_0 disabled.
 */
#define SWM_PINENABLE0_ADC_0(x)                  (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_ADC_0_SHIFT)) & SWM_PINENABLE0_ADC_0_MASK)

#define SWM_PINENABLE0_ADC_1_MASK                (0x8000U)
#define SWM_PINENABLE0_ADC_1_SHIFT               (15U)
/*! ADC_1 - ADC_1 function select.
 *  0b0..ADC_1 enabled on pin PIO0_6.
 *  0b1..ADC_1 disabled.
 */
#define SWM_PINENABLE0_ADC_1(x)                  (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_ADC_1_SHIFT)) & SWM_PINENABLE0_ADC_1_MASK)

#define SWM_PINENABLE0_ADC_2_MASK                (0x10000U)
#define SWM_PINENABLE0_ADC_2_SHIFT               (16U)
/*! ADC_2 - ADC_2 function select.
 *  0b0..ADC_2 enabled on pin PIO0_14.
 *  0b1..ADC_2 disabled.
 */
#define SWM_PINENABLE0_ADC_2(x)                  (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_ADC_2_SHIFT)) & SWM_PINENABLE0_ADC_2_MASK)

#define SWM_PINENABLE0_ADC_3_MASK                (0x20000U)
#define SWM_PINENABLE0_ADC_3_SHIFT               (17U)
/*! ADC_3 - ADC_3 function select.
 *  0b0..ADC_3 enabled on pin PIO0_23.
 *  0b1..ADC_3 disabled.
 */
#define SWM_PINENABLE0_ADC_3(x)                  (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_ADC_3_SHIFT)) & SWM_PINENABLE0_ADC_3_MASK)

#define SWM_PINENABLE0_ADC_4_MASK                (0x40000U)
#define SWM_PINENABLE0_ADC_4_SHIFT               (18U)
/*! ADC_4 - ADC_4 function select.
 *  0b0..ADC_4 enabled on pin PIO0_22.
 *  0b1..ADC_4 disabled.
 */
#define SWM_PINENABLE0_ADC_4(x)                  (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_ADC_4_SHIFT)) & SWM_PINENABLE0_ADC_4_MASK)

#define SWM_PINENABLE0_ADC_5_MASK                (0x80000U)
#define SWM_PINENABLE0_ADC_5_SHIFT               (19U)
/*! ADC_5 - ADC_5 function select.
 *  0b0..ADC_5 enabled on pin PIO0_21.
 *  0b1..ADC_5 disabled.
 */
#define SWM_PINENABLE0_ADC_5(x)                  (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_ADC_5_SHIFT)) & SWM_PINENABLE0_ADC_5_MASK)

#define SWM_PINENABLE0_ADC_6_MASK                (0x100000U)
#define SWM_PINENABLE0_ADC_6_SHIFT               (20U)
/*! ADC_6 - ADC_6 function select.
 *  0b0..ADC_6 enabled on pin PIO0_20.
 *  0b1..ADC_6 disabled.
 */
#define SWM_PINENABLE0_ADC_6(x)                  (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_ADC_6_SHIFT)) & SWM_PINENABLE0_ADC_6_MASK)

#define SWM_PINENABLE0_ADC_7_MASK                (0x200000U)
#define SWM_PINENABLE0_ADC_7_SHIFT               (21U)
/*! ADC_7 - ADC_7 function select.
 *  0b0..ADC_7 enabled on pin PIO0_19.
 *  0b1..ADC_7 disabled.
 */
#define SWM_PINENABLE0_ADC_7(x)                  (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_ADC_7_SHIFT)) & SWM_PINENABLE0_ADC_7_MASK)

#define SWM_PINENABLE0_ADC_8_MASK                (0x400000U)
#define SWM_PINENABLE0_ADC_8_SHIFT               (22U)
/*! ADC_8 - ADC_8 function select.
 *  0b0..ADC_8 enabled on pin PIO0_18.
 *  0b1..ADC_8 disabled.
 */
#define SWM_PINENABLE0_ADC_8(x)                  (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_ADC_8_SHIFT)) & SWM_PINENABLE0_ADC_8_MASK)

#define SWM_PINENABLE0_ADC_9_MASK                (0x800000U)
#define SWM_PINENABLE0_ADC_9_SHIFT               (23U)
/*! ADC_9 - ADC_9 function select.
 *  0b0..ADC_9 enabled on pin PIO0_17.
 *  0b1..ADC_9 disabled.
 */
#define SWM_PINENABLE0_ADC_9(x)                  (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_ADC_9_SHIFT)) & SWM_PINENABLE0_ADC_9_MASK)

#define SWM_PINENABLE0_ADC_10_MASK               (0x1000000U)
#define SWM_PINENABLE0_ADC_10_SHIFT              (24U)
/*! ADC_10 - ADC_10 function select.
 *  0b0..ADC_10 enabled on pin PIO0_13.
 *  0b1..ADC_10 disabled.
 */
#define SWM_PINENABLE0_ADC_10(x)                 (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_ADC_10_SHIFT)) & SWM_PINENABLE0_ADC_10_MASK)

#define SWM_PINENABLE0_ADC_11_MASK               (0x2000000U)
#define SWM_PINENABLE0_ADC_11_SHIFT              (25U)
/*! ADC_11 - ADC_11 function select.
 *  0b0..ADC_11 enabled on pin PIO0_4.
 *  0b1..ADC_11 disabled.
 */
#define SWM_PINENABLE0_ADC_11(x)                 (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_ADC_11_SHIFT)) & SWM_PINENABLE0_ADC_11_MASK)

#define SWM_PINENABLE0_DACOUT0_MASK              (0x4000000U)
#define SWM_PINENABLE0_DACOUT0_SHIFT             (26U)
/*! DACOUT0 - DACOUT0 function select.
 *  0b0..DACOUT0 enabled on pin PIO0_17.
 *  0b1..DACOUT0 disabled.
 */
#define SWM_PINENABLE0_DACOUT0(x)                (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_DACOUT0_SHIFT)) & SWM_PINENABLE0_DACOUT0_MASK)

#define SWM_PINENABLE0_DACOUT1_MASK              (0x8000000U)
#define SWM_PINENABLE0_DACOUT1_SHIFT             (27U)
/*! DACOUT1 - DACOUT1 function select.
 *  0b0..DACOUT1 enabled on pin PIO0_29.
 *  0b1..DACOUT1 disabled.
 */
#define SWM_PINENABLE0_DACOUT1(x)                (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_DACOUT1_SHIFT)) & SWM_PINENABLE0_DACOUT1_MASK)

#define SWM_PINENABLE0_CAPT_X0_MASK              (0x10000000U)
#define SWM_PINENABLE0_CAPT_X0_SHIFT             (28U)
/*! CAPT_X0 - CAPT_X0 function select.
 *  0b0..CAPT_X0 enabled on pin PIO0_31.
 *  0b1..CAPT_X0 disabled.
 */
#define SWM_PINENABLE0_CAPT_X0(x)                (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_CAPT_X0_SHIFT)) & SWM_PINENABLE0_CAPT_X0_MASK)

#define SWM_PINENABLE0_CAPT_X1_MASK              (0x20000000U)
#define SWM_PINENABLE0_CAPT_X1_SHIFT             (29U)
/*! CAPT_X1 - CAPT_X1 function select.
 *  0b0..CAPT_X1 enabled on pin PIO1_0.
 *  0b1..CAPT_X1 disabled.
 */
#define SWM_PINENABLE0_CAPT_X1(x)                (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_CAPT_X1_SHIFT)) & SWM_PINENABLE0_CAPT_X1_MASK)

#define SWM_PINENABLE0_CAPT_X2_MASK              (0x40000000U)
#define SWM_PINENABLE0_CAPT_X2_SHIFT             (30U)
/*! CAPT_X2 - CAPT_X2 function select.
 *  0b0..CAPT_X2 enabled on pin PIO1_1.
 *  0b1..CAPT_X2 disabled.
 */
#define SWM_PINENABLE0_CAPT_X2(x)                (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_CAPT_X2_SHIFT)) & SWM_PINENABLE0_CAPT_X2_MASK)

#define SWM_PINENABLE0_CAPT_X3_MASK              (0x80000000U)
#define SWM_PINENABLE0_CAPT_X3_SHIFT             (31U)
/*! CAPT_X3 - CAPT_X3 function select.
 *  0b0..CAPT_X3 enabled on pin PIO1_2.
 *  0b1..CAPT_X3 disabled.
 */
#define SWM_PINENABLE0_CAPT_X3(x)                (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_CAPT_X3_SHIFT)) & SWM_PINENABLE0_CAPT_X3_MASK)
/*! @} */

/*! @name PINENABLE1 - Pin enable register 1. Enables fixed-pin functions CAPT_X4, CAPT_X5, CAPT_X6, CAPT_X7, CAPT_X8, CAPT_X4, CAPT_YL and CAPT_YH. */
/*! @{ */

#define SWM_PINENABLE1_CAPT_X4_MASK              (0x1U)
#define SWM_PINENABLE1_CAPT_X4_SHIFT             (0U)
/*! CAPT_X4 - CAPT_X4 function select.
 *  0b0..CAPT_X4 enabled on pin PIO1_3.
 *  0b1..CAPT_X4 disabled.
 */
#define SWM_PINENABLE1_CAPT_X4(x)                (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE1_CAPT_X4_SHIFT)) & SWM_PINENABLE1_CAPT_X4_MASK)

#define SWM_PINENABLE1_CAPT_X5_MASK              (0x2U)
#define SWM_PINENABLE1_CAPT_X5_SHIFT             (1U)
/*! CAPT_X5 - CAPT_X5 function select.
 *  0b0..CAPT_X5 enabled on pin PIO1_4.
 *  0b1..CAPT_X5 disabled.
 */
#define SWM_PINENABLE1_CAPT_X5(x)                (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE1_CAPT_X5_SHIFT)) & SWM_PINENABLE1_CAPT_X5_MASK)

#define SWM_PINENABLE1_CAPT_X6_MASK              (0x4U)
#define SWM_PINENABLE1_CAPT_X6_SHIFT             (2U)
/*! CAPT_X6 - CAPT_X6 function select.
 *  0b0..CAPT_X6 enabled on pin PIO1_5.
 *  0b1..CAPT_X6 disabled.
 */
#define SWM_PINENABLE1_CAPT_X6(x)                (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE1_CAPT_X6_SHIFT)) & SWM_PINENABLE1_CAPT_X6_MASK)

#define SWM_PINENABLE1_CAPT_X7_MASK              (0x8U)
#define SWM_PINENABLE1_CAPT_X7_SHIFT             (3U)
/*! CAPT_X7 - CAPT_X7 function select.
 *  0b0..CAPT_X7 enabled on pin PIO1_6.
 *  0b1..CAPT_X7 disabled.
 */
#define SWM_PINENABLE1_CAPT_X7(x)                (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE1_CAPT_X7_SHIFT)) & SWM_PINENABLE1_CAPT_X7_MASK)

#define SWM_PINENABLE1_CAPT_X8_MASK              (0x10U)
#define SWM_PINENABLE1_CAPT_X8_SHIFT             (4U)
/*! CAPT_X8 - CAPT_X8 function select.
 *  0b0..CAPT_X8 enabled on pin PIO1_7.
 *  0b1..CAPT_X8 disabled.
 */
#define SWM_PINENABLE1_CAPT_X8(x)                (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE1_CAPT_X8_SHIFT)) & SWM_PINENABLE1_CAPT_X8_MASK)

#define SWM_PINENABLE1_CAPT_YL_MASK              (0x20U)
#define SWM_PINENABLE1_CAPT_YL_SHIFT             (5U)
/*! CAPT_YL - CAPT_YL function select.
 *  0b0..CAPT_YL enabled on pin PIO1_8.
 *  0b1..CAPT_YL disabled.
 */
#define SWM_PINENABLE1_CAPT_YL(x)                (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE1_CAPT_YL_SHIFT)) & SWM_PINENABLE1_CAPT_YL_MASK)

#define SWM_PINENABLE1_CAPT_YH_MASK              (0x40U)
#define SWM_PINENABLE1_CAPT_YH_SHIFT             (6U)
/*! CAPT_YH - CAPT_YH function select.
 *  0b0..CAPT_YH enabled on pin PIO1_9.
 *  0b1..CAPT_YH disabled.
 */
#define SWM_PINENABLE1_CAPT_YH(x)                (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE1_CAPT_YH_SHIFT)) & SWM_PINENABLE1_CAPT_YH_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SWM_Register_Masks */


/*!
 * @}
 */ /* end of group SWM_Peripheral_Access_Layer */


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


#endif  /* PERI_SWM_H_ */

