/*
** ###################################################################
**     Processors:          LPC802M001JDH16
**                          LPC802M001JDH20
**                          LPC802M001JHI33
**                          LPC802M011JDH20
**                          LPC802UK
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
**     - rev. 1.0 (2018-01-09)
**         Initial version.
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

#if (defined(CPU_LPC802M001JDH16) || defined(CPU_LPC802M001JDH20) || defined(CPU_LPC802M001JHI33) || defined(CPU_LPC802M011JDH20) || defined(CPU_LPC802UK))
#include "LPC802_COMMON.h"
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
#define SWM_PINASSIGN_PINASSIGN_DATA_PINASSIGN_DATA_PINASSIGN_DATA_COUNT 8u

/** SWM - Register Layout Typedef */
typedef struct {
  union {                                          /* offset: 0x0 */
    struct {                                         /* offset: 0x0 */
      __IO uint32_t PINASSIGN0;                        /**< Pin assign register 0. Assign movable functions U0_TXD, U0_RXD, U0_RTS, U0_CTS., offset: 0x0 */
      __IO uint32_t PINASSIGN1;                        /**< Pin assign register 1. Assign movable functions U0_SCLK, U1_TXD, U1_RXD, U1_SCLK., offset: 0x4 */
      __IO uint32_t PINASSIGN2;                        /**< Pin assign register 2. Assign movable functions SPI0_SCK, SPI0_MOSI, SPI0_MISO, SPI0_SSEL0., offset: 0x8 */
      __IO uint32_t PINASSIGN3;                        /**< Pin assign register 3. Assign movable function SPI0_SSEL1, T0_CAP0, T0_CAP1, T0_CAP2., offset: 0xC */
      __IO uint32_t PINASSIGN4;                        /**< Pin assign register 4. Assign movable functions T0_MAT0, T0_MAT1, T0_MAT2,T0_MAT3., offset: 0x10 */
      __IO uint32_t PINASSIGN5;                        /**< Pin assign register 5. Assign movable functions I2C0_SDA, I2C0_SCL, COMP0_OUT, CLKOUT, offset: 0x14 */
      __IO uint32_t PINASSIGN6;                        /**< Pin assign register 6. Assign movable functions GPIO_INT_BMAT, LVLSHFT_IN0, LVLSHFT_IN1, LVLSHFT_OUT0., offset: 0x18 */
      __IO uint32_t PINASSIGN7;                        /**< Pin assign register 7. Assign movable functions LVLSHFT_OUT1., offset: 0x1C */
    } PINASSIGN;
    __IO uint32_t PINASSIGN_DATA[SWM_PINASSIGN_PINASSIGN_DATA_PINASSIGN_DATA_PINASSIGN_DATA_COUNT];   /**< Pin assign register, array offset: 0x0, array step: 0x4 */
  };
       uint8_t RESERVED_0[416];
  __IO uint32_t PINENABLE0;                        /**< Pin enable register 0. Enables fixed-pin functions ACMP_I1, ACMP_I2, ACMP_I3,ACMP_I4, SWCLK, SWDIO, RESET, CLKIN, WKCLK_IN, VDDCMP, ADC_0 - ADC_11., offset: 0x1C0 */
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
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_0 (= 0) to PIO0_5 (= 0x5) and from
 *    PIO0_7 (= 0x7) to PIO0_17 (= 0x11).
 */
#define SWM_PINASSIGN0_U0_TXD_O(x)               (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN0_U0_TXD_O_SHIFT)) & SWM_PINASSIGN0_U0_TXD_O_MASK)

#define SWM_PINASSIGN0_U0_RXD_I_MASK             (0xFF00U)
#define SWM_PINASSIGN0_U0_RXD_I_SHIFT            (8U)
/*! U0_RXD_I - U0_RXD function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_0 (= 0) to PIO0_5 (= 0x5) and from
 *    PIO0_7 (= 0x7) to PIO0_17 (= 0x11).
 */
#define SWM_PINASSIGN0_U0_RXD_I(x)               (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN0_U0_RXD_I_SHIFT)) & SWM_PINASSIGN0_U0_RXD_I_MASK)

#define SWM_PINASSIGN0_U0_RTS_O_MASK             (0xFF0000U)
#define SWM_PINASSIGN0_U0_RTS_O_SHIFT            (16U)
/*! U0_RTS_O - U0_RTS function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_0 (= 0) to PIO0_5 (= 0x5) and from
 *    PIO0_7 (= 0x7) to PIO0_17 (= 0x11).
 */
#define SWM_PINASSIGN0_U0_RTS_O(x)               (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN0_U0_RTS_O_SHIFT)) & SWM_PINASSIGN0_U0_RTS_O_MASK)

#define SWM_PINASSIGN0_U0_CTS_I_MASK             (0xFF000000U)
#define SWM_PINASSIGN0_U0_CTS_I_SHIFT            (24U)
/*! U0_CTS_I - U0_CTS function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_0 (= 0) to PIO0_5 (= 0x5) and from
 *    PIO0_7 (= 0x7) to PIO0_17 (= 0x11).
 */
#define SWM_PINASSIGN0_U0_CTS_I(x)               (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN0_U0_CTS_I_SHIFT)) & SWM_PINASSIGN0_U0_CTS_I_MASK)
/*! @} */

/*! @name PINASSIGN1 - Pin assign register 1. Assign movable functions U0_SCLK, U1_TXD, U1_RXD, U1_SCLK. */
/*! @{ */

#define SWM_PINASSIGN1_U0_SCLK_IO_MASK           (0xFFU)
#define SWM_PINASSIGN1_U0_SCLK_IO_SHIFT          (0U)
/*! U0_SCLK_IO - U0_SCLK function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_0 (= 0) to PIO0_5 (= 0x5) and
 *    from PIO0_7 (= 0x7) to PIO0_17 (= 0x11).
 */
#define SWM_PINASSIGN1_U0_SCLK_IO(x)             (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN1_U0_SCLK_IO_SHIFT)) & SWM_PINASSIGN1_U0_SCLK_IO_MASK)

#define SWM_PINASSIGN1_U1_TXD_O_MASK             (0xFF00U)
#define SWM_PINASSIGN1_U1_TXD_O_SHIFT            (8U)
/*! U1_TXD_O - U1_TXD function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_0 (= 0) to PIO0_5 (= 0x5) and from
 *    PIO0_7 (= 0x7) to PIO0_17 (= 0x11).
 */
#define SWM_PINASSIGN1_U1_TXD_O(x)               (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN1_U1_TXD_O_SHIFT)) & SWM_PINASSIGN1_U1_TXD_O_MASK)

#define SWM_PINASSIGN1_U1_RXD_I_MASK             (0xFF0000U)
#define SWM_PINASSIGN1_U1_RXD_I_SHIFT            (16U)
/*! U1_RXD_I - U1_RXD function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_0 (= 0) to PIO0_5 (= 0x5) and from
 *    PIO0_7 (= 0x7) to PIO0_17 (= 0x11).
 */
#define SWM_PINASSIGN1_U1_RXD_I(x)               (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN1_U1_RXD_I_SHIFT)) & SWM_PINASSIGN1_U1_RXD_I_MASK)

#define SWM_PINASSIGN1_U1_SCLK_IO_MASK           (0xFF000000U)
#define SWM_PINASSIGN1_U1_SCLK_IO_SHIFT          (24U)
/*! U1_SCLK_IO - U1_SCLK function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_5 (= 0x5) and from PIO0_7 (=
 *    0x7) to PIO0_17 (= 0x11).
 */
#define SWM_PINASSIGN1_U1_SCLK_IO(x)             (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN1_U1_SCLK_IO_SHIFT)) & SWM_PINASSIGN1_U1_SCLK_IO_MASK)
/*! @} */

/*! @name PINASSIGN2 - Pin assign register 2. Assign movable functions SPI0_SCK, SPI0_MOSI, SPI0_MISO, SPI0_SSEL0. */
/*! @{ */

#define SWM_PINASSIGN2_SPI0_SCK_IO_MASK          (0xFFU)
#define SWM_PINASSIGN2_SPI0_SCK_IO_SHIFT         (0U)
/*! SPI0_SCK_IO - SPI0_SCK function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_5 (= 0x5) and from PIO0_7 (=
 *    0x7) to PIO0_17 (= 0x11).
 */
#define SWM_PINASSIGN2_SPI0_SCK_IO(x)            (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN2_SPI0_SCK_IO_SHIFT)) & SWM_PINASSIGN2_SPI0_SCK_IO_MASK)

#define SWM_PINASSIGN2_SPI0_MOSI_IO_MASK         (0xFF00U)
#define SWM_PINASSIGN2_SPI0_MOSI_IO_SHIFT        (8U)
/*! SPI0_MOSI_IO - SPI0_MOSI function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_5 (= 0x5) and from PIO0_7 (=
 *    0x7) to PIO0_17 (= 0x11).
 */
#define SWM_PINASSIGN2_SPI0_MOSI_IO(x)           (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN2_SPI0_MOSI_IO_SHIFT)) & SWM_PINASSIGN2_SPI0_MOSI_IO_MASK)

#define SWM_PINASSIGN2_SPI0_MISO_IO_MASK         (0xFF0000U)
#define SWM_PINASSIGN2_SPI0_MISO_IO_SHIFT        (16U)
/*! SPI0_MISO_IO - SPI0_MISO function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_5 (= 0x5) and from PIO0_7 (=
 *    0x7) to PIO0_17 (= 0x11).
 */
#define SWM_PINASSIGN2_SPI0_MISO_IO(x)           (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN2_SPI0_MISO_IO_SHIFT)) & SWM_PINASSIGN2_SPI0_MISO_IO_MASK)

#define SWM_PINASSIGN2_SPI0_SSEL0_IO_MASK        (0xFF000000U)
#define SWM_PINASSIGN2_SPI0_SSEL0_IO_SHIFT       (24U)
/*! SPI0_SSEL0_IO - SPI0_SSEL0 function assignment. The value is the pin number to be assigned to
 *    this function. The following pins are available: PIO0_0 (= 0) to PIO0_5 (= 0x5) and from PIO0_7
 *    (= 0x7) to PIO0_17 (= 0x11).
 */
#define SWM_PINASSIGN2_SPI0_SSEL0_IO(x)          (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN2_SPI0_SSEL0_IO_SHIFT)) & SWM_PINASSIGN2_SPI0_SSEL0_IO_MASK)
/*! @} */

/*! @name PINASSIGN3 - Pin assign register 3. Assign movable function SPI0_SSEL1, T0_CAP0, T0_CAP1, T0_CAP2. */
/*! @{ */

#define SWM_PINASSIGN3_SPI0_SSEL1_IO_MASK        (0xFFU)
#define SWM_PINASSIGN3_SPI0_SSEL1_IO_SHIFT       (0U)
/*! SPI0_SSEL1_IO - SPI0_SSEL1 function assignment. The value is the pin number to be assigned to
 *    this function. The following pins are available: PIO0_0 (= 0) to PIO0_5 (= 0x5) and from PIO0_7
 *    (= 0x7) to PIO0_17 (= 0x11).
 */
#define SWM_PINASSIGN3_SPI0_SSEL1_IO(x)          (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN3_SPI0_SSEL1_IO_SHIFT)) & SWM_PINASSIGN3_SPI0_SSEL1_IO_MASK)

#define SWM_PINASSIGN3_T0_CAP0_MASK              (0xFF00U)
#define SWM_PINASSIGN3_T0_CAP0_SHIFT             (8U)
/*! T0_CAP0 - T0_CAP0 function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_5 (= 0x5) and from PIO0_7 (= 0x7)
 *    to PIO0_17 (= 0x11).
 */
#define SWM_PINASSIGN3_T0_CAP0(x)                (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN3_T0_CAP0_SHIFT)) & SWM_PINASSIGN3_T0_CAP0_MASK)

#define SWM_PINASSIGN3_T0_CAP1_MASK              (0xFF0000U)
#define SWM_PINASSIGN3_T0_CAP1_SHIFT             (16U)
/*! T0_CAP1 - T0_CAP1 function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_5 (= 0x5) and from PIO0_7 (= 0x7)
 *    to PIO0_17 (= 0x11).
 */
#define SWM_PINASSIGN3_T0_CAP1(x)                (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN3_T0_CAP1_SHIFT)) & SWM_PINASSIGN3_T0_CAP1_MASK)

#define SWM_PINASSIGN3_T0_CAP2_MASK              (0xFF000000U)
#define SWM_PINASSIGN3_T0_CAP2_SHIFT             (24U)
/*! T0_CAP2 - T0_CAP2 function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_5 (= 0x5) and from PIO0_7 (= 0x7)
 *    to PIO0_17 (= 0x11).
 */
#define SWM_PINASSIGN3_T0_CAP2(x)                (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN3_T0_CAP2_SHIFT)) & SWM_PINASSIGN3_T0_CAP2_MASK)
/*! @} */

/*! @name PINASSIGN4 - Pin assign register 4. Assign movable functions T0_MAT0, T0_MAT1, T0_MAT2,T0_MAT3. */
/*! @{ */

#define SWM_PINASSIGN4_T0_MAT0_MASK              (0xFFU)
#define SWM_PINASSIGN4_T0_MAT0_SHIFT             (0U)
/*! T0_MAT0 - T0_MAT0 function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_5 (= 0x5) and from PIO0_7 (= 0x7)
 *    to PIO0_17 (= 0x11).
 */
#define SWM_PINASSIGN4_T0_MAT0(x)                (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN4_T0_MAT0_SHIFT)) & SWM_PINASSIGN4_T0_MAT0_MASK)

#define SWM_PINASSIGN4_T0_MAT1_MASK              (0xFF00U)
#define SWM_PINASSIGN4_T0_MAT1_SHIFT             (8U)
/*! T0_MAT1 - T0_MAT1 function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_5 (= 0x5) and from PIO0_7 (= 0x7)
 *    to PIO0_17 (= 0x11).
 */
#define SWM_PINASSIGN4_T0_MAT1(x)                (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN4_T0_MAT1_SHIFT)) & SWM_PINASSIGN4_T0_MAT1_MASK)

#define SWM_PINASSIGN4_T0_MAT2_MASK              (0xFF0000U)
#define SWM_PINASSIGN4_T0_MAT2_SHIFT             (16U)
/*! T0_MAT2 - T0_MAT2 function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_5 (= 0x5) and from PIO0_7 (= 0x7)
 *    to PIO0_17 (= 0x11).
 */
#define SWM_PINASSIGN4_T0_MAT2(x)                (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN4_T0_MAT2_SHIFT)) & SWM_PINASSIGN4_T0_MAT2_MASK)

#define SWM_PINASSIGN4_T0_MAT3_MASK              (0xFF000000U)
#define SWM_PINASSIGN4_T0_MAT3_SHIFT             (24U)
/*! T0_MAT3 - T0_MAT3 function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_5 (= 0x5) and from PIO0_7 (= 0x7)
 *    to PIO0_17 (= 0x11).
 */
#define SWM_PINASSIGN4_T0_MAT3(x)                (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN4_T0_MAT3_SHIFT)) & SWM_PINASSIGN4_T0_MAT3_MASK)
/*! @} */

/*! @name PINASSIGN5 - Pin assign register 5. Assign movable functions I2C0_SDA, I2C0_SCL, COMP0_OUT, CLKOUT */
/*! @{ */

#define SWM_PINASSIGN5_I2C0_SDA_IO_MASK          (0xFFU)
#define SWM_PINASSIGN5_I2C0_SDA_IO_SHIFT         (0U)
/*! I2C0_SDA_IO - I2C0_SDA function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_5 (= 0x5) and from PIO0_7 (=
 *    0x7) to PIO0_17 (= 0x11).
 */
#define SWM_PINASSIGN5_I2C0_SDA_IO(x)            (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN5_I2C0_SDA_IO_SHIFT)) & SWM_PINASSIGN5_I2C0_SDA_IO_MASK)

#define SWM_PINASSIGN5_I2C0_SCL_IO_MASK          (0xFF00U)
#define SWM_PINASSIGN5_I2C0_SCL_IO_SHIFT         (8U)
/*! I2C0_SCL_IO - I2C0_SCL function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_5 (= 0x5) and from PIO0_7 (=
 *    0x7) to PIO0_17 (= 0x11).
 */
#define SWM_PINASSIGN5_I2C0_SCL_IO(x)            (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN5_I2C0_SCL_IO_SHIFT)) & SWM_PINASSIGN5_I2C0_SCL_IO_MASK)

#define SWM_PINASSIGN5_COMP0_OUT_O_MASK          (0xFF0000U)
#define SWM_PINASSIGN5_COMP0_OUT_O_SHIFT         (16U)
/*! COMP0_OUT_O - COMP0_OUT function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_5 (= 0x5) and from PIO0_7 (=
 *    0x7) to PIO0_17 (= 0x11).
 */
#define SWM_PINASSIGN5_COMP0_OUT_O(x)            (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN5_COMP0_OUT_O_SHIFT)) & SWM_PINASSIGN5_COMP0_OUT_O_MASK)

#define SWM_PINASSIGN5_CLKOUT_O_MASK             (0xFF000000U)
#define SWM_PINASSIGN5_CLKOUT_O_SHIFT            (24U)
/*! CLKOUT_O - CLKOUT function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_5 (= 0x5) and from PIO0_7 (= 0x7)
 *    to PIO0_17 (= 0x11).
 */
#define SWM_PINASSIGN5_CLKOUT_O(x)               (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN5_CLKOUT_O_SHIFT)) & SWM_PINASSIGN5_CLKOUT_O_MASK)
/*! @} */

/*! @name PINASSIGN6 - Pin assign register 6. Assign movable functions GPIO_INT_BMAT, LVLSHFT_IN0, LVLSHFT_IN1, LVLSHFT_OUT0. */
/*! @{ */

#define SWM_PINASSIGN6_GPIO_INT_BMAT_O_MASK      (0xFFU)
#define SWM_PINASSIGN6_GPIO_INT_BMAT_O_SHIFT     (0U)
/*! GPIO_INT_BMAT_O - GPIO_INT_BMAT function assignment. The value is the pin number to be assigned
 *    to this function. The following pins are available: PIO0_0 (= 0) to PIO0_5 (= 0x5) and from
 *    PIO0_7 (= 0x7) to PIO0_17 (= 0x11).
 */
#define SWM_PINASSIGN6_GPIO_INT_BMAT_O(x)        (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN6_GPIO_INT_BMAT_O_SHIFT)) & SWM_PINASSIGN6_GPIO_INT_BMAT_O_MASK)

#define SWM_PINASSIGN6_LVLSHFT_IN0_MASK          (0xFF00U)
#define SWM_PINASSIGN6_LVLSHFT_IN0_SHIFT         (8U)
/*! LVLSHFT_IN0 - LVLSHFT_IN0 function assignment. The value is the pin number to be assigned to
 *    this function. The following pins are available: PIO0_0 (= 0) to PIO0_5 (= 0x5) and from PIO0_7
 *    (= 0x7) to PIO0_17 (= 0x11).
 */
#define SWM_PINASSIGN6_LVLSHFT_IN0(x)            (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN6_LVLSHFT_IN0_SHIFT)) & SWM_PINASSIGN6_LVLSHFT_IN0_MASK)

#define SWM_PINASSIGN6_LVLSHFT_IN1_MASK          (0xFF0000U)
#define SWM_PINASSIGN6_LVLSHFT_IN1_SHIFT         (16U)
/*! LVLSHFT_IN1 - LVLSHFT_IN1 function assignment. The value is the pin number to be assigned to
 *    this function. The following pins are available: PIO0_0 (= 0) to PIO0_5 (= 0x5) and from PIO0_7
 *    (= 0x7) to PIO0_17 (= 0x11).
 */
#define SWM_PINASSIGN6_LVLSHFT_IN1(x)            (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN6_LVLSHFT_IN1_SHIFT)) & SWM_PINASSIGN6_LVLSHFT_IN1_MASK)

#define SWM_PINASSIGN6_LVLSHFT_OUT0_MASK         (0xFF000000U)
#define SWM_PINASSIGN6_LVLSHFT_OUT0_SHIFT        (24U)
/*! LVLSHFT_OUT0 - LVLSHFT_OUT0 function assignment. The value is the pin number to be assigned to
 *    this function. The following pins are available: PIO0_0 (= 0) to PIO0_5 (= 0x5) and from PIO0_7
 *    (= 0x7) to PIO0_17 (= 0x11).
 */
#define SWM_PINASSIGN6_LVLSHFT_OUT0(x)           (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN6_LVLSHFT_OUT0_SHIFT)) & SWM_PINASSIGN6_LVLSHFT_OUT0_MASK)
/*! @} */

/*! @name PINASSIGN7 - Pin assign register 7. Assign movable functions LVLSHFT_OUT1. */
/*! @{ */

#define SWM_PINASSIGN7_LVLSHFT_OUT1_MASK         (0xFFU)
#define SWM_PINASSIGN7_LVLSHFT_OUT1_SHIFT        (0U)
/*! LVLSHFT_OUT1 - LVLSHFT_OUT1 function assignment. The value is the pin number to be assigned to
 *    this function. The following pins are available: PIO0_0 (= 0) to PIO0_5 (= 0x5) and from PIO0_7
 *    (= 0x7) to PIO0_17 (= 0x11).
 */
#define SWM_PINASSIGN7_LVLSHFT_OUT1(x)           (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN7_LVLSHFT_OUT1_SHIFT)) & SWM_PINASSIGN7_LVLSHFT_OUT1_MASK)
/*! @} */

/*! @name PINASSIGN_DATA - Pin assign register */
/*! @{ */

#define SWM_PINASSIGN_DATA_DATA0_MASK            (0xFFU)
#define SWM_PINASSIGN_DATA_DATA0_SHIFT           (0U)
/*! DATA0 - T0_MAT3 function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_0 (= 0) to PIO0_5 (= 0x5) and from
 *    PIO0_7 (= 0x7) to PIO0_17 (= 0x11).
 */
#define SWM_PINASSIGN_DATA_DATA0(x)              (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN_DATA_DATA0_SHIFT)) & SWM_PINASSIGN_DATA_DATA0_MASK)

#define SWM_PINASSIGN_DATA_DATA1_MASK            (0xFF00U)
#define SWM_PINASSIGN_DATA_DATA1_SHIFT           (8U)
/*! DATA1 - T0_CAP0 function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_0 (= 0) to PIO0_5 (= 0x5) and from
 *    PIO0_7 (= 0x7) to PIO0_17 (= 0x11).
 */
#define SWM_PINASSIGN_DATA_DATA1(x)              (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN_DATA_DATA1_SHIFT)) & SWM_PINASSIGN_DATA_DATA1_MASK)

#define SWM_PINASSIGN_DATA_DATA2_MASK            (0xFF0000U)
#define SWM_PINASSIGN_DATA_DATA2_SHIFT           (16U)
/*! DATA2 - T0_CAP1 function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_0 (= 0) to PIO0_5 (= 0x5) and from
 *    PIO0_7 (= 0x7) to PIO0_17 (= 0x11).
 */
#define SWM_PINASSIGN_DATA_DATA2(x)              (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN_DATA_DATA2_SHIFT)) & SWM_PINASSIGN_DATA_DATA2_MASK)

#define SWM_PINASSIGN_DATA_DATA3_MASK            (0xFF000000U)
#define SWM_PINASSIGN_DATA_DATA3_SHIFT           (24U)
/*! DATA3 - T0_CAP2 function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_0 (= 0) to PIO0_5 (= 0x5) and from
 *    PIO0_7 (= 0x7) to PIO0_17 (= 0x11).
 */
#define SWM_PINASSIGN_DATA_DATA3(x)              (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN_DATA_DATA3_SHIFT)) & SWM_PINASSIGN_DATA_DATA3_MASK)
/*! @} */

/* The count of SWM_PINASSIGN_DATA */
#define SWM_PINASSIGN_DATA_COUNT                 (8U)

/*! @name PINENABLE0 - Pin enable register 0. Enables fixed-pin functions ACMP_I1, ACMP_I2, ACMP_I3,ACMP_I4, SWCLK, SWDIO, RESET, CLKIN, WKCLK_IN, VDDCMP, ADC_0 - ADC_11. */
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
 *  0b0..ACMP_I4 enabled on pin PIO0_16.
 *  0b1..ACMP_I4 disabled.
 */
#define SWM_PINENABLE0_ACMP_I4(x)                (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_ACMP_I4_SHIFT)) & SWM_PINENABLE0_ACMP_I4_MASK)

#define SWM_PINENABLE0_SWCLK_MASK                (0x10U)
#define SWM_PINENABLE0_SWCLK_SHIFT               (4U)
/*! SWCLK - SWCLK function select.
 *  0b0..SWCLK enabled on pin PIO0_3.
 *  0b1..SWCLK disabled.
 */
#define SWM_PINENABLE0_SWCLK(x)                  (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_SWCLK_SHIFT)) & SWM_PINENABLE0_SWCLK_MASK)

#define SWM_PINENABLE0_SWDIO_MASK                (0x20U)
#define SWM_PINENABLE0_SWDIO_SHIFT               (5U)
/*! SWDIO - SWDIO function select.
 *  0b0..SWDIO enabled on pin PIO0_2.
 *  0b1..SWDIO disabled.
 */
#define SWM_PINENABLE0_SWDIO(x)                  (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_SWDIO_SHIFT)) & SWM_PINENABLE0_SWDIO_MASK)

#define SWM_PINENABLE0_RESETN_MASK               (0x40U)
#define SWM_PINENABLE0_RESETN_SHIFT              (6U)
/*! RESETN - RESETN function select.
 *  0b0..RESETN enabled on pin PIO0_5.
 *  0b1..RESETN disabled.
 */
#define SWM_PINENABLE0_RESETN(x)                 (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_RESETN_SHIFT)) & SWM_PINENABLE0_RESETN_MASK)

#define SWM_PINENABLE0_CLKIN_MASK                (0x80U)
#define SWM_PINENABLE0_CLKIN_SHIFT               (7U)
/*! CLKIN - CLKIN function select.
 *  0b0..CLKIN enabled on pin PIO0_1.
 *  0b1..CLKIN disabled.
 */
#define SWM_PINENABLE0_CLKIN(x)                  (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_CLKIN_SHIFT)) & SWM_PINENABLE0_CLKIN_MASK)

#define SWM_PINENABLE0_WKCLKIN_MASK              (0x100U)
#define SWM_PINENABLE0_WKCLKIN_SHIFT             (8U)
/*! WKCLKIN - WKCLK_IN function select.
 *  0b0..WKCLK_IN enabled on pin PIO0_11.
 *  0b1..WKCLK_IN disabled.
 */
#define SWM_PINENABLE0_WKCLKIN(x)                (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_WKCLKIN_SHIFT)) & SWM_PINENABLE0_WKCLKIN_MASK)

#define SWM_PINENABLE0_VDDCMP_MASK               (0x200U)
#define SWM_PINENABLE0_VDDCMP_SHIFT              (9U)
/*! VDDCMP - VDDCMP function select.
 *  0b0..VDDCMP enabled on pin PIO0_6.
 *  0b1..VDDCMP disabled.
 */
#define SWM_PINENABLE0_VDDCMP(x)                 (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_VDDCMP_SHIFT)) & SWM_PINENABLE0_VDDCMP_MASK)

#define SWM_PINENABLE0_ADC_0_MASK                (0x400U)
#define SWM_PINENABLE0_ADC_0_SHIFT               (10U)
/*! ADC_0 - ADC_0 function select.
 *  0b0..ADC_0 enabled on pin PIO0_1.
 *  0b1..ADC_0 disabled.
 */
#define SWM_PINENABLE0_ADC_0(x)                  (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_ADC_0_SHIFT)) & SWM_PINENABLE0_ADC_0_MASK)

#define SWM_PINENABLE0_ADC_1_MASK                (0x800U)
#define SWM_PINENABLE0_ADC_1_SHIFT               (11U)
/*! ADC_1 - ADC_1 function select.
 *  0b0..ADC_1 enabled on pin PIO0_7.
 *  0b1..ADC_1 disabled.
 */
#define SWM_PINENABLE0_ADC_1(x)                  (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_ADC_1_SHIFT)) & SWM_PINENABLE0_ADC_1_MASK)

#define SWM_PINENABLE0_ADC_2_MASK                (0x1000U)
#define SWM_PINENABLE0_ADC_2_SHIFT               (12U)
/*! ADC_2 - ADC_2 function select.
 *  0b0..ADC_2 enabled on pin PIO0_14.
 *  0b1..ADC_2 disabled.
 */
#define SWM_PINENABLE0_ADC_2(x)                  (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_ADC_2_SHIFT)) & SWM_PINENABLE0_ADC_2_MASK)

#define SWM_PINENABLE0_ADC_3_MASK                (0x2000U)
#define SWM_PINENABLE0_ADC_3_SHIFT               (13U)
/*! ADC_3 - ADC_3 function select.
 *  0b0..ADC_3 enabled on pin PIO0_16.
 *  0b1..ADC_3 disabled.
 */
#define SWM_PINENABLE0_ADC_3(x)                  (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_ADC_3_SHIFT)) & SWM_PINENABLE0_ADC_3_MASK)

#define SWM_PINENABLE0_ADC_4_MASK                (0x4000U)
#define SWM_PINENABLE0_ADC_4_SHIFT               (14U)
/*! ADC_4 - ADC_4 function select.
 *  0b0..ADC_4 enabled on pin PIO0_9.
 *  0b1..ADC_4 disabled.
 */
#define SWM_PINENABLE0_ADC_4(x)                  (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_ADC_4_SHIFT)) & SWM_PINENABLE0_ADC_4_MASK)

#define SWM_PINENABLE0_ADC_5_MASK                (0x8000U)
#define SWM_PINENABLE0_ADC_5_SHIFT               (15U)
/*! ADC_5 - ADC_5 function select.
 *  0b0..ADC_5 enabled on pin PIO0_8.
 *  0b1..ADC_5 disabled.
 */
#define SWM_PINENABLE0_ADC_5(x)                  (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_ADC_5_SHIFT)) & SWM_PINENABLE0_ADC_5_MASK)

#define SWM_PINENABLE0_ADC_6_MASK                (0x10000U)
#define SWM_PINENABLE0_ADC_6_SHIFT               (16U)
/*! ADC_6 - ADC_6 function select.
 *  0b0..ADC_6 enabled on pin PIO0_11.
 *  0b1..ADC_6 disabled.
 */
#define SWM_PINENABLE0_ADC_6(x)                  (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_ADC_6_SHIFT)) & SWM_PINENABLE0_ADC_6_MASK)

#define SWM_PINENABLE0_ADC_7_MASK                (0x20000U)
#define SWM_PINENABLE0_ADC_7_SHIFT               (17U)
/*! ADC_7 - ADC_7 function select.
 *  0b0..ADC_7 enabled on pin PIO0_10.
 *  0b1..ADC_7 disabled.
 */
#define SWM_PINENABLE0_ADC_7(x)                  (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_ADC_7_SHIFT)) & SWM_PINENABLE0_ADC_7_MASK)

#define SWM_PINENABLE0_ADC_8_MASK                (0x40000U)
#define SWM_PINENABLE0_ADC_8_SHIFT               (18U)
/*! ADC_8 - ADC_8 function select.
 *  0b0..ADC_8 enabled on pin PIO0_15.
 *  0b1..ADC_8 disabled.
 */
#define SWM_PINENABLE0_ADC_8(x)                  (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_ADC_8_SHIFT)) & SWM_PINENABLE0_ADC_8_MASK)

#define SWM_PINENABLE0_ADC_9_MASK                (0x80000U)
#define SWM_PINENABLE0_ADC_9_SHIFT               (19U)
/*! ADC_9 - ADC_9 function select.
 *  0b0..ADC_9 enabled on pin PIO0_17.
 *  0b1..ADC_9 disabled.
 */
#define SWM_PINENABLE0_ADC_9(x)                  (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_ADC_9_SHIFT)) & SWM_PINENABLE0_ADC_9_MASK)

#define SWM_PINENABLE0_ADC_10_MASK               (0x100000U)
#define SWM_PINENABLE0_ADC_10_SHIFT              (20U)
/*! ADC_10 - ADC_10 function select.
 *  0b0..ADC_10 enabled on pin PIO0_13.
 *  0b1..ADC_10 disabled.
 */
#define SWM_PINENABLE0_ADC_10(x)                 (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_ADC_10_SHIFT)) & SWM_PINENABLE0_ADC_10_MASK)

#define SWM_PINENABLE0_ADC_11_MASK               (0x200000U)
#define SWM_PINENABLE0_ADC_11_SHIFT              (21U)
/*! ADC_11 - ADC_11 function select.
 *  0b0..ADC_11 enabled on pin PIO0_4.
 *  0b1..ADC_11 disabled.
 */
#define SWM_PINENABLE0_ADC_11(x)                 (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_ADC_11_SHIFT)) & SWM_PINENABLE0_ADC_11_MASK)
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

