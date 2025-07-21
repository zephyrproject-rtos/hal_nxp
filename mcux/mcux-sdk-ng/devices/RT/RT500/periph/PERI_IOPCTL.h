/*
** ###################################################################
**     Processors:          MIMXRT533SFAWC
**                          MIMXRT533SFFOC
**                          MIMXRT555SFAWC
**                          MIMXRT555SFFOC
**                          MIMXRT595SFAWC_cm33
**                          MIMXRT595SFAWC_dsp
**                          MIMXRT595SFFOC_cm33
**                          MIMXRT595SFFOC_dsp
**
**     Version:             rev. 6.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for IOPCTL
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2019-04-19)
**         Initial version.
**     - rev. 2.0 (2019-07-22)
**         Base on rev 0.7 RM.
**     - rev. 3.0 (2020-03-16)
**         Base on Rev.A RM.
**     - rev. 4.0 (2020-05-18)
**         Base on Rev.B RM.
**     - rev. 5.0 (2020-08-27)
**         Base on Rev.C RM.
**     - rev. 6.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_IOPCTL.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for IOPCTL
 *
 * CMSIS Peripheral Access Layer for IOPCTL
 */

#if !defined(PERI_IOPCTL_H_)
#define PERI_IOPCTL_H_                           /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT533SFAWC) || defined(CPU_MIMXRT533SFFOC))
#include "MIMXRT533S_COMMON.h"
#elif (defined(CPU_MIMXRT555SFAWC) || defined(CPU_MIMXRT555SFFOC))
#include "MIMXRT555S_COMMON.h"
#elif (defined(CPU_MIMXRT595SFAWC_cm33) || defined(CPU_MIMXRT595SFFOC_cm33))
#include "MIMXRT595S_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT595SFAWC_dsp) || defined(CPU_MIMXRT595SFFOC_dsp))
#include "MIMXRT595S_dsp_COMMON.h"
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
   -- IOPCTL Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IOPCTL_Peripheral_Access_Layer IOPCTL Peripheral Access Layer
 * @{
 */

/** IOPCTL - Size of Registers Arrays */
#define IOPCTL_PIO_COUNT                          7u
#define IOPCTL_PIO_PIO_COUNT                      32u

/** IOPCTL - Register Layout Typedef */
typedef struct {
  __IO uint32_t PIO[IOPCTL_PIO_COUNT][IOPCTL_PIO_PIO_COUNT]; /**< IOPCTL configuration, array offset: 0x0, array step: index*0x80, index2*0x4, valid indices: [0][0-31], [1][0-31], [2][0-31], [3][0-31], [4][0-31], [5][0-31], [6][0-27] */
       uint8_t RESERVED_0[128];
  __IO uint32_t FC15_I2C_SCL;                      /**< Flexcomm 15 SCL, offset: 0x400 */
  __IO uint32_t FC15_I2C_SDA;                      /**< Flexcomm 15 SDA, offset: 0x404 */
} IOPCTL_Type;

/* ----------------------------------------------------------------------------
   -- IOPCTL Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IOPCTL_Register_Masks IOPCTL Register Masks
 * @{
 */

/*! @name PIO - IOPCTL configuration */
/*! @{ */

#define IOPCTL_PIO_FSEL_MASK                     (0xFU)
#define IOPCTL_PIO_FSEL_SHIFT                    (0U)
/*! FSEL - Function Selector (Digital Function)
 *  0b0000..Function 0
 *  0b0001..Function 1
 *  0b0010..Function 2
 *  0b0011..Function 3
 *  0b0100..Function 4
 *  0b0101..Function 5
 *  0b0110..Function 6
 *  0b0111..Function 7
 *  0b1000..Function 8
 *  0b1001..Function 9
 *  0b1010..Function 10
 *  0b1011..Function 11
 *  0b1100..Function 12
 *  0b1101..Function 13
 *  0b1110..Function 14
 *  0b1111..Function 15
 */
#define IOPCTL_PIO_FSEL(x)                       (((uint32_t)(((uint32_t)(x)) << IOPCTL_PIO_FSEL_SHIFT)) & IOPCTL_PIO_FSEL_MASK)

#define IOPCTL_PIO_PUPDENA_MASK                  (0x10U)
#define IOPCTL_PIO_PUPDENA_SHIFT                 (4U)
/*! PUPDENA - Pullup / Pulldown Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define IOPCTL_PIO_PUPDENA(x)                    (((uint32_t)(((uint32_t)(x)) << IOPCTL_PIO_PUPDENA_SHIFT)) & IOPCTL_PIO_PUPDENA_MASK)

#define IOPCTL_PIO_PUPDSEL_MASK                  (0x20U)
#define IOPCTL_PIO_PUPDSEL_SHIFT                 (5U)
/*! PUPDSEL - Pullup or Pulldown Selector
 *  0b0..Pull-down
 *  0b1..Pull-up
 */
#define IOPCTL_PIO_PUPDSEL(x)                    (((uint32_t)(((uint32_t)(x)) << IOPCTL_PIO_PUPDSEL_SHIFT)) & IOPCTL_PIO_PUPDSEL_MASK)

#define IOPCTL_PIO_IBENA_MASK                    (0x40U)
#define IOPCTL_PIO_IBENA_SHIFT                   (6U)
/*! IBENA - Input Buffer Enable
 *  0b0..Input buffer disabled
 *  0b1..Input buffer enabled
 */
#define IOPCTL_PIO_IBENA(x)                      (((uint32_t)(((uint32_t)(x)) << IOPCTL_PIO_IBENA_SHIFT)) & IOPCTL_PIO_IBENA_MASK)

#define IOPCTL_PIO_SLEWRATE_MASK                 (0x80U)
#define IOPCTL_PIO_SLEWRATE_SHIFT                (7U)
/*! SLEWRATE - Slew Rate Control
 *  0b0..Standard mode, output slew rate is not controlled.
 *  0b1..Slow mode, output slew rate control is enabled, limiting the output rate change and maximum toggle
 *       frequency. See device datasheet for details.
 */
#define IOPCTL_PIO_SLEWRATE(x)                   (((uint32_t)(((uint32_t)(x)) << IOPCTL_PIO_SLEWRATE_SHIFT)) & IOPCTL_PIO_SLEWRATE_MASK)

#define IOPCTL_PIO_FULLDRIVE_MASK                (0x100U)
#define IOPCTL_PIO_FULLDRIVE_SHIFT               (8U)
/*! FULLDRIVE - Drive Selector
 *  0b0..Normal output drive
 *  0b1..Full output drive, twice the drive of normal mode.
 */
#define IOPCTL_PIO_FULLDRIVE(x)                  (((uint32_t)(((uint32_t)(x)) << IOPCTL_PIO_FULLDRIVE_SHIFT)) & IOPCTL_PIO_FULLDRIVE_MASK)

#define IOPCTL_PIO_AMENA_MASK                    (0x200U)
#define IOPCTL_PIO_AMENA_SHIFT                   (9U)
/*! AMENA - Analog Mux Enable
 *  0b0..Analog multiplexor disabled, required for digital pin function
 *  0b1..Analog multiplexor enabled, required for analog pin function
 */
#define IOPCTL_PIO_AMENA(x)                      (((uint32_t)(((uint32_t)(x)) << IOPCTL_PIO_AMENA_SHIFT)) & IOPCTL_PIO_AMENA_MASK)

#define IOPCTL_PIO_ODENA_MASK                    (0x400U)
#define IOPCTL_PIO_ODENA_SHIFT                   (10U)
/*! ODENA - Open-drain mode enable
 *  0b0..Normal push-pull output
 *  0b1..Pseudo open-drain output (high drive disabled)
 */
#define IOPCTL_PIO_ODENA(x)                      (((uint32_t)(((uint32_t)(x)) << IOPCTL_PIO_ODENA_SHIFT)) & IOPCTL_PIO_ODENA_MASK)

#define IOPCTL_PIO_IIENA_MASK                    (0x800U)
#define IOPCTL_PIO_IIENA_SHIFT                   (11U)
/*! IIENA - Input Invert Enable
 *  0b0..Disabled, Input function is not inverted
 *  0b1..Enabled, Input is function inverted
 */
#define IOPCTL_PIO_IIENA(x)                      (((uint32_t)(((uint32_t)(x)) << IOPCTL_PIO_IIENA_SHIFT)) & IOPCTL_PIO_IIENA_MASK)
/*! @} */

/* The count of IOPCTL_PIO */
#define IOPCTL_PIO_COUNT2                        (32U)

/*! @name FC15_I2C_SCL - Flexcomm 15 SCL */
/*! @{ */

#define IOPCTL_FC15_I2C_SCL_FSEL_MASK            (0xFU)
#define IOPCTL_FC15_I2C_SCL_FSEL_SHIFT           (0U)
/*! FSEL - Function Selector (Digital Function)
 *  0b0000..Function 0
 *  0b0001..Function 1
 *  0b0010..Function 2
 *  0b0011..Function 3
 *  0b0100..Function 4
 *  0b0101..Function 5
 *  0b0110..Function 6
 *  0b0111..Function 7
 *  0b1000..Function 8
 *  0b1001..Function 9
 *  0b1010..Function 10
 *  0b1011..Function 11
 *  0b1100..Function 12
 *  0b1101..Function 13
 *  0b1110..Function 14
 *  0b1111..Function 15
 */
#define IOPCTL_FC15_I2C_SCL_FSEL(x)              (((uint32_t)(((uint32_t)(x)) << IOPCTL_FC15_I2C_SCL_FSEL_SHIFT)) & IOPCTL_FC15_I2C_SCL_FSEL_MASK)

#define IOPCTL_FC15_I2C_SCL_PUPDENA_MASK         (0x10U)
#define IOPCTL_FC15_I2C_SCL_PUPDENA_SHIFT        (4U)
/*! PUPDENA - Pullup / Pulldown Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define IOPCTL_FC15_I2C_SCL_PUPDENA(x)           (((uint32_t)(((uint32_t)(x)) << IOPCTL_FC15_I2C_SCL_PUPDENA_SHIFT)) & IOPCTL_FC15_I2C_SCL_PUPDENA_MASK)

#define IOPCTL_FC15_I2C_SCL_PUPDSEL_MASK         (0x20U)
#define IOPCTL_FC15_I2C_SCL_PUPDSEL_SHIFT        (5U)
/*! PUPDSEL - Pullup or Pulldown Selector
 *  0b0..Pull-down
 *  0b1..Pull-up
 */
#define IOPCTL_FC15_I2C_SCL_PUPDSEL(x)           (((uint32_t)(((uint32_t)(x)) << IOPCTL_FC15_I2C_SCL_PUPDSEL_SHIFT)) & IOPCTL_FC15_I2C_SCL_PUPDSEL_MASK)

#define IOPCTL_FC15_I2C_SCL_IBENA_MASK           (0x40U)
#define IOPCTL_FC15_I2C_SCL_IBENA_SHIFT          (6U)
/*! IBENA - Input Buffer Enable
 *  0b0..Input buffer disabled
 *  0b1..Input buffer enabled
 */
#define IOPCTL_FC15_I2C_SCL_IBENA(x)             (((uint32_t)(((uint32_t)(x)) << IOPCTL_FC15_I2C_SCL_IBENA_SHIFT)) & IOPCTL_FC15_I2C_SCL_IBENA_MASK)

#define IOPCTL_FC15_I2C_SCL_SLEWRATE_MASK        (0x80U)
#define IOPCTL_FC15_I2C_SCL_SLEWRATE_SHIFT       (7U)
/*! SLEWRATE - Slew Rate Control
 *  0b0..Standard mode, output slew rate is not controlled.
 *  0b1..Slow mode, output slew rate control is enabled, limiting the output rate change and maximum toggle
 *       frequency. See device datasheet for details.
 */
#define IOPCTL_FC15_I2C_SCL_SLEWRATE(x)          (((uint32_t)(((uint32_t)(x)) << IOPCTL_FC15_I2C_SCL_SLEWRATE_SHIFT)) & IOPCTL_FC15_I2C_SCL_SLEWRATE_MASK)

#define IOPCTL_FC15_I2C_SCL_FULLDRIVE_MASK       (0x100U)
#define IOPCTL_FC15_I2C_SCL_FULLDRIVE_SHIFT      (8U)
/*! FULLDRIVE - Drive Selector
 *  0b0..Normal output drive
 *  0b1..Full output drive, twice the drive of normal mode.
 */
#define IOPCTL_FC15_I2C_SCL_FULLDRIVE(x)         (((uint32_t)(((uint32_t)(x)) << IOPCTL_FC15_I2C_SCL_FULLDRIVE_SHIFT)) & IOPCTL_FC15_I2C_SCL_FULLDRIVE_MASK)

#define IOPCTL_FC15_I2C_SCL_AMENA_MASK           (0x200U)
#define IOPCTL_FC15_I2C_SCL_AMENA_SHIFT          (9U)
/*! AMENA - Analog Mux Enable
 *  0b0..Analog multiplexor disabled, required for digital pin function
 *  0b1..Analog multiplexor enabled, required for analog pin function
 */
#define IOPCTL_FC15_I2C_SCL_AMENA(x)             (((uint32_t)(((uint32_t)(x)) << IOPCTL_FC15_I2C_SCL_AMENA_SHIFT)) & IOPCTL_FC15_I2C_SCL_AMENA_MASK)

#define IOPCTL_FC15_I2C_SCL_ODENA_MASK           (0x400U)
#define IOPCTL_FC15_I2C_SCL_ODENA_SHIFT          (10U)
/*! ODENA - Open-drain mode enable
 *  0b0..Normal push-pull output
 *  0b1..Pseudo open-drain output (high drive disabled)
 */
#define IOPCTL_FC15_I2C_SCL_ODENA(x)             (((uint32_t)(((uint32_t)(x)) << IOPCTL_FC15_I2C_SCL_ODENA_SHIFT)) & IOPCTL_FC15_I2C_SCL_ODENA_MASK)

#define IOPCTL_FC15_I2C_SCL_IIENA_MASK           (0x800U)
#define IOPCTL_FC15_I2C_SCL_IIENA_SHIFT          (11U)
/*! IIENA - Input Invert Enable
 *  0b0..Disabled, Input function is not inverted
 *  0b1..Enabled, Input is function inverted
 */
#define IOPCTL_FC15_I2C_SCL_IIENA(x)             (((uint32_t)(((uint32_t)(x)) << IOPCTL_FC15_I2C_SCL_IIENA_SHIFT)) & IOPCTL_FC15_I2C_SCL_IIENA_MASK)
/*! @} */

/*! @name FC15_I2C_SDA - Flexcomm 15 SDA */
/*! @{ */

#define IOPCTL_FC15_I2C_SDA_FSEL_MASK            (0xFU)
#define IOPCTL_FC15_I2C_SDA_FSEL_SHIFT           (0U)
/*! FSEL - Function Selector (Digital Function)
 *  0b0000..Function 0
 *  0b0001..Function 1
 *  0b0010..Function 2
 *  0b0011..Function 3
 *  0b0100..Function 4
 *  0b0101..Function 5
 *  0b0110..Function 6
 *  0b0111..Function 7
 *  0b1000..Function 8
 *  0b1001..Function 9
 *  0b1010..Function 10
 *  0b1011..Function 11
 *  0b1100..Function 12
 *  0b1101..Function 13
 *  0b1110..Function 14
 *  0b1111..Function 15
 */
#define IOPCTL_FC15_I2C_SDA_FSEL(x)              (((uint32_t)(((uint32_t)(x)) << IOPCTL_FC15_I2C_SDA_FSEL_SHIFT)) & IOPCTL_FC15_I2C_SDA_FSEL_MASK)

#define IOPCTL_FC15_I2C_SDA_PUPDENA_MASK         (0x10U)
#define IOPCTL_FC15_I2C_SDA_PUPDENA_SHIFT        (4U)
/*! PUPDENA - Pullup / Pulldown Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define IOPCTL_FC15_I2C_SDA_PUPDENA(x)           (((uint32_t)(((uint32_t)(x)) << IOPCTL_FC15_I2C_SDA_PUPDENA_SHIFT)) & IOPCTL_FC15_I2C_SDA_PUPDENA_MASK)

#define IOPCTL_FC15_I2C_SDA_PUPDSEL_MASK         (0x20U)
#define IOPCTL_FC15_I2C_SDA_PUPDSEL_SHIFT        (5U)
/*! PUPDSEL - Pullup or Pulldown Selector
 *  0b0..Pull-down
 *  0b1..Pull-up
 */
#define IOPCTL_FC15_I2C_SDA_PUPDSEL(x)           (((uint32_t)(((uint32_t)(x)) << IOPCTL_FC15_I2C_SDA_PUPDSEL_SHIFT)) & IOPCTL_FC15_I2C_SDA_PUPDSEL_MASK)

#define IOPCTL_FC15_I2C_SDA_IBENA_MASK           (0x40U)
#define IOPCTL_FC15_I2C_SDA_IBENA_SHIFT          (6U)
/*! IBENA - Input Buffer Enable
 *  0b0..Input buffer disabled
 *  0b1..Input buffer enabled
 */
#define IOPCTL_FC15_I2C_SDA_IBENA(x)             (((uint32_t)(((uint32_t)(x)) << IOPCTL_FC15_I2C_SDA_IBENA_SHIFT)) & IOPCTL_FC15_I2C_SDA_IBENA_MASK)

#define IOPCTL_FC15_I2C_SDA_SLEWRATE_MASK        (0x80U)
#define IOPCTL_FC15_I2C_SDA_SLEWRATE_SHIFT       (7U)
/*! SLEWRATE - Slew Rate Control
 *  0b0..Standard mode, output slew rate is not controlled.
 *  0b1..Slow mode, output slew rate control is enabled, limiting the output rate change and maximum toggle
 *       frequency. See device datasheet for details.
 */
#define IOPCTL_FC15_I2C_SDA_SLEWRATE(x)          (((uint32_t)(((uint32_t)(x)) << IOPCTL_FC15_I2C_SDA_SLEWRATE_SHIFT)) & IOPCTL_FC15_I2C_SDA_SLEWRATE_MASK)

#define IOPCTL_FC15_I2C_SDA_FULLDRIVE_MASK       (0x100U)
#define IOPCTL_FC15_I2C_SDA_FULLDRIVE_SHIFT      (8U)
/*! FULLDRIVE - Drive Selector
 *  0b0..Normal output drive
 *  0b1..Full output drive, twice the drive of normal mode.
 */
#define IOPCTL_FC15_I2C_SDA_FULLDRIVE(x)         (((uint32_t)(((uint32_t)(x)) << IOPCTL_FC15_I2C_SDA_FULLDRIVE_SHIFT)) & IOPCTL_FC15_I2C_SDA_FULLDRIVE_MASK)

#define IOPCTL_FC15_I2C_SDA_AMENA_MASK           (0x200U)
#define IOPCTL_FC15_I2C_SDA_AMENA_SHIFT          (9U)
/*! AMENA - Analog Mux Enable
 *  0b0..Analog multiplexor disabled, required for digital pin function
 *  0b1..Analog multiplexor enabled, required for analog pin function
 */
#define IOPCTL_FC15_I2C_SDA_AMENA(x)             (((uint32_t)(((uint32_t)(x)) << IOPCTL_FC15_I2C_SDA_AMENA_SHIFT)) & IOPCTL_FC15_I2C_SDA_AMENA_MASK)

#define IOPCTL_FC15_I2C_SDA_ODENA_MASK           (0x400U)
#define IOPCTL_FC15_I2C_SDA_ODENA_SHIFT          (10U)
/*! ODENA - Open-drain mode enable
 *  0b0..Normal push-pull output
 *  0b1..Pseudo open-drain output (high drive disabled)
 */
#define IOPCTL_FC15_I2C_SDA_ODENA(x)             (((uint32_t)(((uint32_t)(x)) << IOPCTL_FC15_I2C_SDA_ODENA_SHIFT)) & IOPCTL_FC15_I2C_SDA_ODENA_MASK)

#define IOPCTL_FC15_I2C_SDA_IIENA_MASK           (0x800U)
#define IOPCTL_FC15_I2C_SDA_IIENA_SHIFT          (11U)
/*! IIENA - Input Invert Enable
 *  0b0..Disabled, Input function is not inverted
 *  0b1..Enabled, Input is function inverted
 */
#define IOPCTL_FC15_I2C_SDA_IIENA(x)             (((uint32_t)(((uint32_t)(x)) << IOPCTL_FC15_I2C_SDA_IIENA_SHIFT)) & IOPCTL_FC15_I2C_SDA_IIENA_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group IOPCTL_Register_Masks */


/*!
 * @}
 */ /* end of group IOPCTL_Peripheral_Access_Layer */


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


#endif  /* PERI_IOPCTL_H_ */

