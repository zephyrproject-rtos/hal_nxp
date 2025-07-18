/*
** ###################################################################
**     Processors:          MIMXRT1061CVJ5A
**                          MIMXRT1061CVJ5B
**                          MIMXRT1061CVL5A
**                          MIMXRT1061CVL5B
**                          MIMXRT1061DVJ6A
**                          MIMXRT1061DVJ6B
**                          MIMXRT1061DVL6A
**                          MIMXRT1061DVL6B
**                          MIMXRT1061XVN5B
**                          MIMXRT1062CVJ5A
**                          MIMXRT1062CVJ5B
**                          MIMXRT1062CVL5A
**                          MIMXRT1062CVL5B
**                          MIMXRT1062DVJ6A
**                          MIMXRT1062DVJ6B
**                          MIMXRT1062DVL6A
**                          MIMXRT1062DVL6B
**                          MIMXRT1062DVN6B
**                          MIMXRT1062XVN5B
**                          MIMXRT106ADVL6A
**                          MIMXRT106CDVL6A
**                          MIMXRT106FDVL6A
**                          MIMXRT106LDVL6A
**                          MIMXRT106SDVL6A
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for USB_ANALOG
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
**     - rev. 1.0 (2018-11-16)
**         Update header files to align with IMXRT1060RM Rev.0.
**     - rev. 1.1 (2018-11-27)
**         Update header files to align with IMXRT1060RM Rev.1.
**     - rev. 1.2 (2019-04-29)
**         Add SET/CLR/TOG register group to register CTRL, STAT, CHANNELCTRL, CH0STAT, CH0OPTS, CH1STAT, CH1OPTS, CH2STAT, CH2OPTS, CH3STAT, CH3OPTS of DCP module.
**     - rev. 1.3 (2021-08-10)
**         Update header files to align with IMXRT1060RM Rev.3.
**     - rev. 1.4 (2022-03-25)
**         Add RT1060X device
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_USB_ANALOG.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for USB_ANALOG
 *
 * CMSIS Peripheral Access Layer for USB_ANALOG
 */

#if !defined(PERI_USB_ANALOG_H_)
#define PERI_USB_ANALOG_H_                       /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT1061CVJ5A) || defined(CPU_MIMXRT1061CVJ5B) || defined(CPU_MIMXRT1061CVL5A) || defined(CPU_MIMXRT1061CVL5B) || defined(CPU_MIMXRT1061DVJ6A) || defined(CPU_MIMXRT1061DVJ6B) || defined(CPU_MIMXRT1061DVL6A) || defined(CPU_MIMXRT1061DVL6B) || defined(CPU_MIMXRT1061XVN5B))
#include "MIMXRT1061_COMMON.h"
#elif (defined(CPU_MIMXRT1062CVJ5A) || defined(CPU_MIMXRT1062CVJ5B) || defined(CPU_MIMXRT1062CVL5A) || defined(CPU_MIMXRT1062CVL5B) || defined(CPU_MIMXRT1062DVJ6A) || defined(CPU_MIMXRT1062DVJ6B) || defined(CPU_MIMXRT1062DVL6A) || defined(CPU_MIMXRT1062DVL6B) || defined(CPU_MIMXRT1062DVN6B) || defined(CPU_MIMXRT1062XVN5B))
#include "MIMXRT1062_COMMON.h"
#elif (defined(CPU_MIMXRT106ADVL6A))
#include "MIMXRT106A_COMMON.h"
#elif (defined(CPU_MIMXRT106CDVL6A))
#include "MIMXRT106C_COMMON.h"
#elif (defined(CPU_MIMXRT106FDVL6A))
#include "MIMXRT106F_COMMON.h"
#elif (defined(CPU_MIMXRT106LDVL6A))
#include "MIMXRT106L_COMMON.h"
#elif (defined(CPU_MIMXRT106SDVL6A))
#include "MIMXRT106S_COMMON.h"
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
   -- USB_ANALOG Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup USB_ANALOG_Peripheral_Access_Layer USB_ANALOG Peripheral Access Layer
 * @{
 */

/** USB_ANALOG - Size of Registers Arrays */
#define USB_ANALOG_INSTANCE_COUNT                 2u

/** USB_ANALOG - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[416];
  struct {                                         /* offset: 0x1A0, array step: 0x60 */
    __IO uint32_t VBUS_DETECT;                       /**< USB VBUS Detect Register, array offset: 0x1A0, array step: 0x60 */
    __IO uint32_t VBUS_DETECT_SET;                   /**< USB VBUS Detect Register, array offset: 0x1A4, array step: 0x60 */
    __IO uint32_t VBUS_DETECT_CLR;                   /**< USB VBUS Detect Register, array offset: 0x1A8, array step: 0x60 */
    __IO uint32_t VBUS_DETECT_TOG;                   /**< USB VBUS Detect Register, array offset: 0x1AC, array step: 0x60 */
    __IO uint32_t CHRG_DETECT;                       /**< USB Charger Detect Register, array offset: 0x1B0, array step: 0x60 */
    __IO uint32_t CHRG_DETECT_SET;                   /**< USB Charger Detect Register, array offset: 0x1B4, array step: 0x60 */
    __IO uint32_t CHRG_DETECT_CLR;                   /**< USB Charger Detect Register, array offset: 0x1B8, array step: 0x60 */
    __IO uint32_t CHRG_DETECT_TOG;                   /**< USB Charger Detect Register, array offset: 0x1BC, array step: 0x60 */
    __I  uint32_t VBUS_DETECT_STAT;                  /**< USB VBUS Detect Status Register, array offset: 0x1C0, array step: 0x60 */
         uint8_t RESERVED_0[12];
    __I  uint32_t CHRG_DETECT_STAT;                  /**< USB Charger Detect Status Register, array offset: 0x1D0, array step: 0x60 */
         uint8_t RESERVED_1[12];
    __IO uint32_t LOOPBACK;                          /**< USB Loopback Test Register, array offset: 0x1E0, array step: 0x60 */
    __IO uint32_t LOOPBACK_SET;                      /**< USB Loopback Test Register, array offset: 0x1E4, array step: 0x60 */
    __IO uint32_t LOOPBACK_CLR;                      /**< USB Loopback Test Register, array offset: 0x1E8, array step: 0x60 */
    __IO uint32_t LOOPBACK_TOG;                      /**< USB Loopback Test Register, array offset: 0x1EC, array step: 0x60 */
    __IO uint32_t MISC;                              /**< USB Misc Register, array offset: 0x1F0, array step: 0x60 */
    __IO uint32_t MISC_SET;                          /**< USB Misc Register, array offset: 0x1F4, array step: 0x60 */
    __IO uint32_t MISC_CLR;                          /**< USB Misc Register, array offset: 0x1F8, array step: 0x60 */
    __IO uint32_t MISC_TOG;                          /**< USB Misc Register, array offset: 0x1FC, array step: 0x60 */
  } INSTANCE[USB_ANALOG_INSTANCE_COUNT];
  __I  uint32_t DIGPROG;                           /**< Chip Silicon Version, offset: 0x260 */
} USB_ANALOG_Type;

/* ----------------------------------------------------------------------------
   -- USB_ANALOG Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup USB_ANALOG_Register_Masks USB_ANALOG Register Masks
 * @{
 */

/*! @name VBUS_DETECT - USB VBUS Detect Register */
/*! @{ */

#define USB_ANALOG_VBUS_DETECT_VBUSVALID_THRESH_MASK (0x7U)
#define USB_ANALOG_VBUS_DETECT_VBUSVALID_THRESH_SHIFT (0U)
/*! VBUSVALID_THRESH
 *  0b000..4.0V
 *  0b001..4.1V
 *  0b010..4.2V
 *  0b011..4.3V
 *  0b100..4.4V (default)
 *  0b101..4.5V
 *  0b110..4.6V
 *  0b111..4.7V
 */
#define USB_ANALOG_VBUS_DETECT_VBUSVALID_THRESH(x) (((uint32_t)(((uint32_t)(x)) << USB_ANALOG_VBUS_DETECT_VBUSVALID_THRESH_SHIFT)) & USB_ANALOG_VBUS_DETECT_VBUSVALID_THRESH_MASK)

#define USB_ANALOG_VBUS_DETECT_VBUSVALID_PWRUP_CMPS_MASK (0x100000U)
#define USB_ANALOG_VBUS_DETECT_VBUSVALID_PWRUP_CMPS_SHIFT (20U)
#define USB_ANALOG_VBUS_DETECT_VBUSVALID_PWRUP_CMPS(x) (((uint32_t)(((uint32_t)(x)) << USB_ANALOG_VBUS_DETECT_VBUSVALID_PWRUP_CMPS_SHIFT)) & USB_ANALOG_VBUS_DETECT_VBUSVALID_PWRUP_CMPS_MASK)

#define USB_ANALOG_VBUS_DETECT_DISCHARGE_VBUS_MASK (0x4000000U)
#define USB_ANALOG_VBUS_DETECT_DISCHARGE_VBUS_SHIFT (26U)
#define USB_ANALOG_VBUS_DETECT_DISCHARGE_VBUS(x) (((uint32_t)(((uint32_t)(x)) << USB_ANALOG_VBUS_DETECT_DISCHARGE_VBUS_SHIFT)) & USB_ANALOG_VBUS_DETECT_DISCHARGE_VBUS_MASK)

#define USB_ANALOG_VBUS_DETECT_CHARGE_VBUS_MASK  (0x8000000U)
#define USB_ANALOG_VBUS_DETECT_CHARGE_VBUS_SHIFT (27U)
#define USB_ANALOG_VBUS_DETECT_CHARGE_VBUS(x)    (((uint32_t)(((uint32_t)(x)) << USB_ANALOG_VBUS_DETECT_CHARGE_VBUS_SHIFT)) & USB_ANALOG_VBUS_DETECT_CHARGE_VBUS_MASK)
/*! @} */

/* The count of USB_ANALOG_VBUS_DETECT */
#define USB_ANALOG_VBUS_DETECT_COUNT             (2U)

/*! @name VBUS_DETECT_SET - USB VBUS Detect Register */
/*! @{ */

#define USB_ANALOG_VBUS_DETECT_SET_VBUSVALID_THRESH_MASK (0x7U)
#define USB_ANALOG_VBUS_DETECT_SET_VBUSVALID_THRESH_SHIFT (0U)
/*! VBUSVALID_THRESH
 *  0b000..4.0V
 *  0b001..4.1V
 *  0b010..4.2V
 *  0b011..4.3V
 *  0b100..4.4V (default)
 *  0b101..4.5V
 *  0b110..4.6V
 *  0b111..4.7V
 */
#define USB_ANALOG_VBUS_DETECT_SET_VBUSVALID_THRESH(x) (((uint32_t)(((uint32_t)(x)) << USB_ANALOG_VBUS_DETECT_SET_VBUSVALID_THRESH_SHIFT)) & USB_ANALOG_VBUS_DETECT_SET_VBUSVALID_THRESH_MASK)

#define USB_ANALOG_VBUS_DETECT_SET_VBUSVALID_PWRUP_CMPS_MASK (0x100000U)
#define USB_ANALOG_VBUS_DETECT_SET_VBUSVALID_PWRUP_CMPS_SHIFT (20U)
#define USB_ANALOG_VBUS_DETECT_SET_VBUSVALID_PWRUP_CMPS(x) (((uint32_t)(((uint32_t)(x)) << USB_ANALOG_VBUS_DETECT_SET_VBUSVALID_PWRUP_CMPS_SHIFT)) & USB_ANALOG_VBUS_DETECT_SET_VBUSVALID_PWRUP_CMPS_MASK)

#define USB_ANALOG_VBUS_DETECT_SET_DISCHARGE_VBUS_MASK (0x4000000U)
#define USB_ANALOG_VBUS_DETECT_SET_DISCHARGE_VBUS_SHIFT (26U)
#define USB_ANALOG_VBUS_DETECT_SET_DISCHARGE_VBUS(x) (((uint32_t)(((uint32_t)(x)) << USB_ANALOG_VBUS_DETECT_SET_DISCHARGE_VBUS_SHIFT)) & USB_ANALOG_VBUS_DETECT_SET_DISCHARGE_VBUS_MASK)

#define USB_ANALOG_VBUS_DETECT_SET_CHARGE_VBUS_MASK (0x8000000U)
#define USB_ANALOG_VBUS_DETECT_SET_CHARGE_VBUS_SHIFT (27U)
#define USB_ANALOG_VBUS_DETECT_SET_CHARGE_VBUS(x) (((uint32_t)(((uint32_t)(x)) << USB_ANALOG_VBUS_DETECT_SET_CHARGE_VBUS_SHIFT)) & USB_ANALOG_VBUS_DETECT_SET_CHARGE_VBUS_MASK)
/*! @} */

/* The count of USB_ANALOG_VBUS_DETECT_SET */
#define USB_ANALOG_VBUS_DETECT_SET_COUNT         (2U)

/*! @name VBUS_DETECT_CLR - USB VBUS Detect Register */
/*! @{ */

#define USB_ANALOG_VBUS_DETECT_CLR_VBUSVALID_THRESH_MASK (0x7U)
#define USB_ANALOG_VBUS_DETECT_CLR_VBUSVALID_THRESH_SHIFT (0U)
/*! VBUSVALID_THRESH
 *  0b000..4.0V
 *  0b001..4.1V
 *  0b010..4.2V
 *  0b011..4.3V
 *  0b100..4.4V (default)
 *  0b101..4.5V
 *  0b110..4.6V
 *  0b111..4.7V
 */
#define USB_ANALOG_VBUS_DETECT_CLR_VBUSVALID_THRESH(x) (((uint32_t)(((uint32_t)(x)) << USB_ANALOG_VBUS_DETECT_CLR_VBUSVALID_THRESH_SHIFT)) & USB_ANALOG_VBUS_DETECT_CLR_VBUSVALID_THRESH_MASK)

#define USB_ANALOG_VBUS_DETECT_CLR_VBUSVALID_PWRUP_CMPS_MASK (0x100000U)
#define USB_ANALOG_VBUS_DETECT_CLR_VBUSVALID_PWRUP_CMPS_SHIFT (20U)
#define USB_ANALOG_VBUS_DETECT_CLR_VBUSVALID_PWRUP_CMPS(x) (((uint32_t)(((uint32_t)(x)) << USB_ANALOG_VBUS_DETECT_CLR_VBUSVALID_PWRUP_CMPS_SHIFT)) & USB_ANALOG_VBUS_DETECT_CLR_VBUSVALID_PWRUP_CMPS_MASK)

#define USB_ANALOG_VBUS_DETECT_CLR_DISCHARGE_VBUS_MASK (0x4000000U)
#define USB_ANALOG_VBUS_DETECT_CLR_DISCHARGE_VBUS_SHIFT (26U)
#define USB_ANALOG_VBUS_DETECT_CLR_DISCHARGE_VBUS(x) (((uint32_t)(((uint32_t)(x)) << USB_ANALOG_VBUS_DETECT_CLR_DISCHARGE_VBUS_SHIFT)) & USB_ANALOG_VBUS_DETECT_CLR_DISCHARGE_VBUS_MASK)

#define USB_ANALOG_VBUS_DETECT_CLR_CHARGE_VBUS_MASK (0x8000000U)
#define USB_ANALOG_VBUS_DETECT_CLR_CHARGE_VBUS_SHIFT (27U)
#define USB_ANALOG_VBUS_DETECT_CLR_CHARGE_VBUS(x) (((uint32_t)(((uint32_t)(x)) << USB_ANALOG_VBUS_DETECT_CLR_CHARGE_VBUS_SHIFT)) & USB_ANALOG_VBUS_DETECT_CLR_CHARGE_VBUS_MASK)
/*! @} */

/* The count of USB_ANALOG_VBUS_DETECT_CLR */
#define USB_ANALOG_VBUS_DETECT_CLR_COUNT         (2U)

/*! @name VBUS_DETECT_TOG - USB VBUS Detect Register */
/*! @{ */

#define USB_ANALOG_VBUS_DETECT_TOG_VBUSVALID_THRESH_MASK (0x7U)
#define USB_ANALOG_VBUS_DETECT_TOG_VBUSVALID_THRESH_SHIFT (0U)
/*! VBUSVALID_THRESH
 *  0b000..4.0V
 *  0b001..4.1V
 *  0b010..4.2V
 *  0b011..4.3V
 *  0b100..4.4V (default)
 *  0b101..4.5V
 *  0b110..4.6V
 *  0b111..4.7V
 */
#define USB_ANALOG_VBUS_DETECT_TOG_VBUSVALID_THRESH(x) (((uint32_t)(((uint32_t)(x)) << USB_ANALOG_VBUS_DETECT_TOG_VBUSVALID_THRESH_SHIFT)) & USB_ANALOG_VBUS_DETECT_TOG_VBUSVALID_THRESH_MASK)

#define USB_ANALOG_VBUS_DETECT_TOG_VBUSVALID_PWRUP_CMPS_MASK (0x100000U)
#define USB_ANALOG_VBUS_DETECT_TOG_VBUSVALID_PWRUP_CMPS_SHIFT (20U)
#define USB_ANALOG_VBUS_DETECT_TOG_VBUSVALID_PWRUP_CMPS(x) (((uint32_t)(((uint32_t)(x)) << USB_ANALOG_VBUS_DETECT_TOG_VBUSVALID_PWRUP_CMPS_SHIFT)) & USB_ANALOG_VBUS_DETECT_TOG_VBUSVALID_PWRUP_CMPS_MASK)

#define USB_ANALOG_VBUS_DETECT_TOG_DISCHARGE_VBUS_MASK (0x4000000U)
#define USB_ANALOG_VBUS_DETECT_TOG_DISCHARGE_VBUS_SHIFT (26U)
#define USB_ANALOG_VBUS_DETECT_TOG_DISCHARGE_VBUS(x) (((uint32_t)(((uint32_t)(x)) << USB_ANALOG_VBUS_DETECT_TOG_DISCHARGE_VBUS_SHIFT)) & USB_ANALOG_VBUS_DETECT_TOG_DISCHARGE_VBUS_MASK)

#define USB_ANALOG_VBUS_DETECT_TOG_CHARGE_VBUS_MASK (0x8000000U)
#define USB_ANALOG_VBUS_DETECT_TOG_CHARGE_VBUS_SHIFT (27U)
#define USB_ANALOG_VBUS_DETECT_TOG_CHARGE_VBUS(x) (((uint32_t)(((uint32_t)(x)) << USB_ANALOG_VBUS_DETECT_TOG_CHARGE_VBUS_SHIFT)) & USB_ANALOG_VBUS_DETECT_TOG_CHARGE_VBUS_MASK)
/*! @} */

/* The count of USB_ANALOG_VBUS_DETECT_TOG */
#define USB_ANALOG_VBUS_DETECT_TOG_COUNT         (2U)

/*! @name CHRG_DETECT - USB Charger Detect Register */
/*! @{ */

#define USB_ANALOG_CHRG_DETECT_CHK_CONTACT_MASK  (0x40000U)
#define USB_ANALOG_CHRG_DETECT_CHK_CONTACT_SHIFT (18U)
/*! CHK_CONTACT - Check the contact of USB plug
 *  0b0..Do not check the contact of USB plug.
 *  0b1..Check whether the USB plug has been in contact with each other
 */
#define USB_ANALOG_CHRG_DETECT_CHK_CONTACT(x)    (((uint32_t)(((uint32_t)(x)) << USB_ANALOG_CHRG_DETECT_CHK_CONTACT_SHIFT)) & USB_ANALOG_CHRG_DETECT_CHK_CONTACT_MASK)

#define USB_ANALOG_CHRG_DETECT_CHK_CHRG_B_MASK   (0x80000U)
#define USB_ANALOG_CHRG_DETECT_CHK_CHRG_B_SHIFT  (19U)
/*! CHK_CHRG_B - Check the charger connection
 *  0b0..Check whether a charger (either a dedicated charger or a host charger) is connected to USB port.
 *  0b1..Do not check whether a charger is connected to the USB port.
 */
#define USB_ANALOG_CHRG_DETECT_CHK_CHRG_B(x)     (((uint32_t)(((uint32_t)(x)) << USB_ANALOG_CHRG_DETECT_CHK_CHRG_B_SHIFT)) & USB_ANALOG_CHRG_DETECT_CHK_CHRG_B_MASK)

#define USB_ANALOG_CHRG_DETECT_EN_B_MASK         (0x100000U)
#define USB_ANALOG_CHRG_DETECT_EN_B_SHIFT        (20U)
/*! EN_B
 *  0b0..Enable the charger detector.
 *  0b1..Disable the charger detector.
 */
#define USB_ANALOG_CHRG_DETECT_EN_B(x)           (((uint32_t)(((uint32_t)(x)) << USB_ANALOG_CHRG_DETECT_EN_B_SHIFT)) & USB_ANALOG_CHRG_DETECT_EN_B_MASK)
/*! @} */

/* The count of USB_ANALOG_CHRG_DETECT */
#define USB_ANALOG_CHRG_DETECT_COUNT             (2U)

/*! @name CHRG_DETECT_SET - USB Charger Detect Register */
/*! @{ */

#define USB_ANALOG_CHRG_DETECT_SET_CHK_CONTACT_MASK (0x40000U)
#define USB_ANALOG_CHRG_DETECT_SET_CHK_CONTACT_SHIFT (18U)
/*! CHK_CONTACT - Check the contact of USB plug
 *  0b0..Do not check the contact of USB plug.
 *  0b1..Check whether the USB plug has been in contact with each other
 */
#define USB_ANALOG_CHRG_DETECT_SET_CHK_CONTACT(x) (((uint32_t)(((uint32_t)(x)) << USB_ANALOG_CHRG_DETECT_SET_CHK_CONTACT_SHIFT)) & USB_ANALOG_CHRG_DETECT_SET_CHK_CONTACT_MASK)

#define USB_ANALOG_CHRG_DETECT_SET_CHK_CHRG_B_MASK (0x80000U)
#define USB_ANALOG_CHRG_DETECT_SET_CHK_CHRG_B_SHIFT (19U)
/*! CHK_CHRG_B - Check the charger connection
 *  0b0..Check whether a charger (either a dedicated charger or a host charger) is connected to USB port.
 *  0b1..Do not check whether a charger is connected to the USB port.
 */
#define USB_ANALOG_CHRG_DETECT_SET_CHK_CHRG_B(x) (((uint32_t)(((uint32_t)(x)) << USB_ANALOG_CHRG_DETECT_SET_CHK_CHRG_B_SHIFT)) & USB_ANALOG_CHRG_DETECT_SET_CHK_CHRG_B_MASK)

#define USB_ANALOG_CHRG_DETECT_SET_EN_B_MASK     (0x100000U)
#define USB_ANALOG_CHRG_DETECT_SET_EN_B_SHIFT    (20U)
/*! EN_B
 *  0b0..Enable the charger detector.
 *  0b1..Disable the charger detector.
 */
#define USB_ANALOG_CHRG_DETECT_SET_EN_B(x)       (((uint32_t)(((uint32_t)(x)) << USB_ANALOG_CHRG_DETECT_SET_EN_B_SHIFT)) & USB_ANALOG_CHRG_DETECT_SET_EN_B_MASK)
/*! @} */

/* The count of USB_ANALOG_CHRG_DETECT_SET */
#define USB_ANALOG_CHRG_DETECT_SET_COUNT         (2U)

/*! @name CHRG_DETECT_CLR - USB Charger Detect Register */
/*! @{ */

#define USB_ANALOG_CHRG_DETECT_CLR_CHK_CONTACT_MASK (0x40000U)
#define USB_ANALOG_CHRG_DETECT_CLR_CHK_CONTACT_SHIFT (18U)
/*! CHK_CONTACT - Check the contact of USB plug
 *  0b0..Do not check the contact of USB plug.
 *  0b1..Check whether the USB plug has been in contact with each other
 */
#define USB_ANALOG_CHRG_DETECT_CLR_CHK_CONTACT(x) (((uint32_t)(((uint32_t)(x)) << USB_ANALOG_CHRG_DETECT_CLR_CHK_CONTACT_SHIFT)) & USB_ANALOG_CHRG_DETECT_CLR_CHK_CONTACT_MASK)

#define USB_ANALOG_CHRG_DETECT_CLR_CHK_CHRG_B_MASK (0x80000U)
#define USB_ANALOG_CHRG_DETECT_CLR_CHK_CHRG_B_SHIFT (19U)
/*! CHK_CHRG_B - Check the charger connection
 *  0b0..Check whether a charger (either a dedicated charger or a host charger) is connected to USB port.
 *  0b1..Do not check whether a charger is connected to the USB port.
 */
#define USB_ANALOG_CHRG_DETECT_CLR_CHK_CHRG_B(x) (((uint32_t)(((uint32_t)(x)) << USB_ANALOG_CHRG_DETECT_CLR_CHK_CHRG_B_SHIFT)) & USB_ANALOG_CHRG_DETECT_CLR_CHK_CHRG_B_MASK)

#define USB_ANALOG_CHRG_DETECT_CLR_EN_B_MASK     (0x100000U)
#define USB_ANALOG_CHRG_DETECT_CLR_EN_B_SHIFT    (20U)
/*! EN_B
 *  0b0..Enable the charger detector.
 *  0b1..Disable the charger detector.
 */
#define USB_ANALOG_CHRG_DETECT_CLR_EN_B(x)       (((uint32_t)(((uint32_t)(x)) << USB_ANALOG_CHRG_DETECT_CLR_EN_B_SHIFT)) & USB_ANALOG_CHRG_DETECT_CLR_EN_B_MASK)
/*! @} */

/* The count of USB_ANALOG_CHRG_DETECT_CLR */
#define USB_ANALOG_CHRG_DETECT_CLR_COUNT         (2U)

/*! @name CHRG_DETECT_TOG - USB Charger Detect Register */
/*! @{ */

#define USB_ANALOG_CHRG_DETECT_TOG_CHK_CONTACT_MASK (0x40000U)
#define USB_ANALOG_CHRG_DETECT_TOG_CHK_CONTACT_SHIFT (18U)
/*! CHK_CONTACT - Check the contact of USB plug
 *  0b0..Do not check the contact of USB plug.
 *  0b1..Check whether the USB plug has been in contact with each other
 */
#define USB_ANALOG_CHRG_DETECT_TOG_CHK_CONTACT(x) (((uint32_t)(((uint32_t)(x)) << USB_ANALOG_CHRG_DETECT_TOG_CHK_CONTACT_SHIFT)) & USB_ANALOG_CHRG_DETECT_TOG_CHK_CONTACT_MASK)

#define USB_ANALOG_CHRG_DETECT_TOG_CHK_CHRG_B_MASK (0x80000U)
#define USB_ANALOG_CHRG_DETECT_TOG_CHK_CHRG_B_SHIFT (19U)
/*! CHK_CHRG_B - Check the charger connection
 *  0b0..Check whether a charger (either a dedicated charger or a host charger) is connected to USB port.
 *  0b1..Do not check whether a charger is connected to the USB port.
 */
#define USB_ANALOG_CHRG_DETECT_TOG_CHK_CHRG_B(x) (((uint32_t)(((uint32_t)(x)) << USB_ANALOG_CHRG_DETECT_TOG_CHK_CHRG_B_SHIFT)) & USB_ANALOG_CHRG_DETECT_TOG_CHK_CHRG_B_MASK)

#define USB_ANALOG_CHRG_DETECT_TOG_EN_B_MASK     (0x100000U)
#define USB_ANALOG_CHRG_DETECT_TOG_EN_B_SHIFT    (20U)
/*! EN_B
 *  0b0..Enable the charger detector.
 *  0b1..Disable the charger detector.
 */
#define USB_ANALOG_CHRG_DETECT_TOG_EN_B(x)       (((uint32_t)(((uint32_t)(x)) << USB_ANALOG_CHRG_DETECT_TOG_EN_B_SHIFT)) & USB_ANALOG_CHRG_DETECT_TOG_EN_B_MASK)
/*! @} */

/* The count of USB_ANALOG_CHRG_DETECT_TOG */
#define USB_ANALOG_CHRG_DETECT_TOG_COUNT         (2U)

/*! @name VBUS_DETECT_STAT - USB VBUS Detect Status Register */
/*! @{ */

#define USB_ANALOG_VBUS_DETECT_STAT_SESSEND_MASK (0x1U)
#define USB_ANALOG_VBUS_DETECT_STAT_SESSEND_SHIFT (0U)
#define USB_ANALOG_VBUS_DETECT_STAT_SESSEND(x)   (((uint32_t)(((uint32_t)(x)) << USB_ANALOG_VBUS_DETECT_STAT_SESSEND_SHIFT)) & USB_ANALOG_VBUS_DETECT_STAT_SESSEND_MASK)

#define USB_ANALOG_VBUS_DETECT_STAT_BVALID_MASK  (0x2U)
#define USB_ANALOG_VBUS_DETECT_STAT_BVALID_SHIFT (1U)
#define USB_ANALOG_VBUS_DETECT_STAT_BVALID(x)    (((uint32_t)(((uint32_t)(x)) << USB_ANALOG_VBUS_DETECT_STAT_BVALID_SHIFT)) & USB_ANALOG_VBUS_DETECT_STAT_BVALID_MASK)

#define USB_ANALOG_VBUS_DETECT_STAT_AVALID_MASK  (0x4U)
#define USB_ANALOG_VBUS_DETECT_STAT_AVALID_SHIFT (2U)
#define USB_ANALOG_VBUS_DETECT_STAT_AVALID(x)    (((uint32_t)(((uint32_t)(x)) << USB_ANALOG_VBUS_DETECT_STAT_AVALID_SHIFT)) & USB_ANALOG_VBUS_DETECT_STAT_AVALID_MASK)

#define USB_ANALOG_VBUS_DETECT_STAT_VBUS_VALID_MASK (0x8U)
#define USB_ANALOG_VBUS_DETECT_STAT_VBUS_VALID_SHIFT (3U)
#define USB_ANALOG_VBUS_DETECT_STAT_VBUS_VALID(x) (((uint32_t)(((uint32_t)(x)) << USB_ANALOG_VBUS_DETECT_STAT_VBUS_VALID_SHIFT)) & USB_ANALOG_VBUS_DETECT_STAT_VBUS_VALID_MASK)
/*! @} */

/* The count of USB_ANALOG_VBUS_DETECT_STAT */
#define USB_ANALOG_VBUS_DETECT_STAT_COUNT        (2U)

/*! @name CHRG_DETECT_STAT - USB Charger Detect Status Register */
/*! @{ */

#define USB_ANALOG_CHRG_DETECT_STAT_PLUG_CONTACT_MASK (0x1U)
#define USB_ANALOG_CHRG_DETECT_STAT_PLUG_CONTACT_SHIFT (0U)
/*! PLUG_CONTACT
 *  0b0..The USB plug has not made contact.
 *  0b1..The USB plug has made good contact.
 */
#define USB_ANALOG_CHRG_DETECT_STAT_PLUG_CONTACT(x) (((uint32_t)(((uint32_t)(x)) << USB_ANALOG_CHRG_DETECT_STAT_PLUG_CONTACT_SHIFT)) & USB_ANALOG_CHRG_DETECT_STAT_PLUG_CONTACT_MASK)

#define USB_ANALOG_CHRG_DETECT_STAT_CHRG_DETECTED_MASK (0x2U)
#define USB_ANALOG_CHRG_DETECT_STAT_CHRG_DETECTED_SHIFT (1U)
/*! CHRG_DETECTED
 *  0b0..The USB port is not connected to a charger.
 *  0b1..A charger (either a dedicated charger or a host charger) is connected to the USB port.
 */
#define USB_ANALOG_CHRG_DETECT_STAT_CHRG_DETECTED(x) (((uint32_t)(((uint32_t)(x)) << USB_ANALOG_CHRG_DETECT_STAT_CHRG_DETECTED_SHIFT)) & USB_ANALOG_CHRG_DETECT_STAT_CHRG_DETECTED_MASK)

#define USB_ANALOG_CHRG_DETECT_STAT_DM_STATE_MASK (0x4U)
#define USB_ANALOG_CHRG_DETECT_STAT_DM_STATE_SHIFT (2U)
#define USB_ANALOG_CHRG_DETECT_STAT_DM_STATE(x)  (((uint32_t)(((uint32_t)(x)) << USB_ANALOG_CHRG_DETECT_STAT_DM_STATE_SHIFT)) & USB_ANALOG_CHRG_DETECT_STAT_DM_STATE_MASK)

#define USB_ANALOG_CHRG_DETECT_STAT_DP_STATE_MASK (0x8U)
#define USB_ANALOG_CHRG_DETECT_STAT_DP_STATE_SHIFT (3U)
#define USB_ANALOG_CHRG_DETECT_STAT_DP_STATE(x)  (((uint32_t)(((uint32_t)(x)) << USB_ANALOG_CHRG_DETECT_STAT_DP_STATE_SHIFT)) & USB_ANALOG_CHRG_DETECT_STAT_DP_STATE_MASK)
/*! @} */

/* The count of USB_ANALOG_CHRG_DETECT_STAT */
#define USB_ANALOG_CHRG_DETECT_STAT_COUNT        (2U)

/*! @name LOOPBACK - USB Loopback Test Register */
/*! @{ */

#define USB_ANALOG_LOOPBACK_UTMI_TESTSTART_MASK  (0x1U)
#define USB_ANALOG_LOOPBACK_UTMI_TESTSTART_SHIFT (0U)
#define USB_ANALOG_LOOPBACK_UTMI_TESTSTART(x)    (((uint32_t)(((uint32_t)(x)) << USB_ANALOG_LOOPBACK_UTMI_TESTSTART_SHIFT)) & USB_ANALOG_LOOPBACK_UTMI_TESTSTART_MASK)
/*! @} */

/* The count of USB_ANALOG_LOOPBACK */
#define USB_ANALOG_LOOPBACK_COUNT                (2U)

/*! @name LOOPBACK_SET - USB Loopback Test Register */
/*! @{ */

#define USB_ANALOG_LOOPBACK_SET_UTMI_TESTSTART_MASK (0x1U)
#define USB_ANALOG_LOOPBACK_SET_UTMI_TESTSTART_SHIFT (0U)
#define USB_ANALOG_LOOPBACK_SET_UTMI_TESTSTART(x) (((uint32_t)(((uint32_t)(x)) << USB_ANALOG_LOOPBACK_SET_UTMI_TESTSTART_SHIFT)) & USB_ANALOG_LOOPBACK_SET_UTMI_TESTSTART_MASK)
/*! @} */

/* The count of USB_ANALOG_LOOPBACK_SET */
#define USB_ANALOG_LOOPBACK_SET_COUNT            (2U)

/*! @name LOOPBACK_CLR - USB Loopback Test Register */
/*! @{ */

#define USB_ANALOG_LOOPBACK_CLR_UTMI_TESTSTART_MASK (0x1U)
#define USB_ANALOG_LOOPBACK_CLR_UTMI_TESTSTART_SHIFT (0U)
#define USB_ANALOG_LOOPBACK_CLR_UTMI_TESTSTART(x) (((uint32_t)(((uint32_t)(x)) << USB_ANALOG_LOOPBACK_CLR_UTMI_TESTSTART_SHIFT)) & USB_ANALOG_LOOPBACK_CLR_UTMI_TESTSTART_MASK)
/*! @} */

/* The count of USB_ANALOG_LOOPBACK_CLR */
#define USB_ANALOG_LOOPBACK_CLR_COUNT            (2U)

/*! @name LOOPBACK_TOG - USB Loopback Test Register */
/*! @{ */

#define USB_ANALOG_LOOPBACK_TOG_UTMI_TESTSTART_MASK (0x1U)
#define USB_ANALOG_LOOPBACK_TOG_UTMI_TESTSTART_SHIFT (0U)
#define USB_ANALOG_LOOPBACK_TOG_UTMI_TESTSTART(x) (((uint32_t)(((uint32_t)(x)) << USB_ANALOG_LOOPBACK_TOG_UTMI_TESTSTART_SHIFT)) & USB_ANALOG_LOOPBACK_TOG_UTMI_TESTSTART_MASK)
/*! @} */

/* The count of USB_ANALOG_LOOPBACK_TOG */
#define USB_ANALOG_LOOPBACK_TOG_COUNT            (2U)

/*! @name MISC - USB Misc Register */
/*! @{ */

#define USB_ANALOG_MISC_HS_USE_EXTERNAL_R_MASK   (0x1U)
#define USB_ANALOG_MISC_HS_USE_EXTERNAL_R_SHIFT  (0U)
#define USB_ANALOG_MISC_HS_USE_EXTERNAL_R(x)     (((uint32_t)(((uint32_t)(x)) << USB_ANALOG_MISC_HS_USE_EXTERNAL_R_SHIFT)) & USB_ANALOG_MISC_HS_USE_EXTERNAL_R_MASK)

#define USB_ANALOG_MISC_EN_DEGLITCH_MASK         (0x2U)
#define USB_ANALOG_MISC_EN_DEGLITCH_SHIFT        (1U)
#define USB_ANALOG_MISC_EN_DEGLITCH(x)           (((uint32_t)(((uint32_t)(x)) << USB_ANALOG_MISC_EN_DEGLITCH_SHIFT)) & USB_ANALOG_MISC_EN_DEGLITCH_MASK)

#define USB_ANALOG_MISC_EN_CLK_UTMI_MASK         (0x40000000U)
#define USB_ANALOG_MISC_EN_CLK_UTMI_SHIFT        (30U)
#define USB_ANALOG_MISC_EN_CLK_UTMI(x)           (((uint32_t)(((uint32_t)(x)) << USB_ANALOG_MISC_EN_CLK_UTMI_SHIFT)) & USB_ANALOG_MISC_EN_CLK_UTMI_MASK)
/*! @} */

/* The count of USB_ANALOG_MISC */
#define USB_ANALOG_MISC_COUNT                    (2U)

/*! @name MISC_SET - USB Misc Register */
/*! @{ */

#define USB_ANALOG_MISC_SET_HS_USE_EXTERNAL_R_MASK (0x1U)
#define USB_ANALOG_MISC_SET_HS_USE_EXTERNAL_R_SHIFT (0U)
#define USB_ANALOG_MISC_SET_HS_USE_EXTERNAL_R(x) (((uint32_t)(((uint32_t)(x)) << USB_ANALOG_MISC_SET_HS_USE_EXTERNAL_R_SHIFT)) & USB_ANALOG_MISC_SET_HS_USE_EXTERNAL_R_MASK)

#define USB_ANALOG_MISC_SET_EN_DEGLITCH_MASK     (0x2U)
#define USB_ANALOG_MISC_SET_EN_DEGLITCH_SHIFT    (1U)
#define USB_ANALOG_MISC_SET_EN_DEGLITCH(x)       (((uint32_t)(((uint32_t)(x)) << USB_ANALOG_MISC_SET_EN_DEGLITCH_SHIFT)) & USB_ANALOG_MISC_SET_EN_DEGLITCH_MASK)

#define USB_ANALOG_MISC_SET_EN_CLK_UTMI_MASK     (0x40000000U)
#define USB_ANALOG_MISC_SET_EN_CLK_UTMI_SHIFT    (30U)
#define USB_ANALOG_MISC_SET_EN_CLK_UTMI(x)       (((uint32_t)(((uint32_t)(x)) << USB_ANALOG_MISC_SET_EN_CLK_UTMI_SHIFT)) & USB_ANALOG_MISC_SET_EN_CLK_UTMI_MASK)
/*! @} */

/* The count of USB_ANALOG_MISC_SET */
#define USB_ANALOG_MISC_SET_COUNT                (2U)

/*! @name MISC_CLR - USB Misc Register */
/*! @{ */

#define USB_ANALOG_MISC_CLR_HS_USE_EXTERNAL_R_MASK (0x1U)
#define USB_ANALOG_MISC_CLR_HS_USE_EXTERNAL_R_SHIFT (0U)
#define USB_ANALOG_MISC_CLR_HS_USE_EXTERNAL_R(x) (((uint32_t)(((uint32_t)(x)) << USB_ANALOG_MISC_CLR_HS_USE_EXTERNAL_R_SHIFT)) & USB_ANALOG_MISC_CLR_HS_USE_EXTERNAL_R_MASK)

#define USB_ANALOG_MISC_CLR_EN_DEGLITCH_MASK     (0x2U)
#define USB_ANALOG_MISC_CLR_EN_DEGLITCH_SHIFT    (1U)
#define USB_ANALOG_MISC_CLR_EN_DEGLITCH(x)       (((uint32_t)(((uint32_t)(x)) << USB_ANALOG_MISC_CLR_EN_DEGLITCH_SHIFT)) & USB_ANALOG_MISC_CLR_EN_DEGLITCH_MASK)

#define USB_ANALOG_MISC_CLR_EN_CLK_UTMI_MASK     (0x40000000U)
#define USB_ANALOG_MISC_CLR_EN_CLK_UTMI_SHIFT    (30U)
#define USB_ANALOG_MISC_CLR_EN_CLK_UTMI(x)       (((uint32_t)(((uint32_t)(x)) << USB_ANALOG_MISC_CLR_EN_CLK_UTMI_SHIFT)) & USB_ANALOG_MISC_CLR_EN_CLK_UTMI_MASK)
/*! @} */

/* The count of USB_ANALOG_MISC_CLR */
#define USB_ANALOG_MISC_CLR_COUNT                (2U)

/*! @name MISC_TOG - USB Misc Register */
/*! @{ */

#define USB_ANALOG_MISC_TOG_HS_USE_EXTERNAL_R_MASK (0x1U)
#define USB_ANALOG_MISC_TOG_HS_USE_EXTERNAL_R_SHIFT (0U)
#define USB_ANALOG_MISC_TOG_HS_USE_EXTERNAL_R(x) (((uint32_t)(((uint32_t)(x)) << USB_ANALOG_MISC_TOG_HS_USE_EXTERNAL_R_SHIFT)) & USB_ANALOG_MISC_TOG_HS_USE_EXTERNAL_R_MASK)

#define USB_ANALOG_MISC_TOG_EN_DEGLITCH_MASK     (0x2U)
#define USB_ANALOG_MISC_TOG_EN_DEGLITCH_SHIFT    (1U)
#define USB_ANALOG_MISC_TOG_EN_DEGLITCH(x)       (((uint32_t)(((uint32_t)(x)) << USB_ANALOG_MISC_TOG_EN_DEGLITCH_SHIFT)) & USB_ANALOG_MISC_TOG_EN_DEGLITCH_MASK)

#define USB_ANALOG_MISC_TOG_EN_CLK_UTMI_MASK     (0x40000000U)
#define USB_ANALOG_MISC_TOG_EN_CLK_UTMI_SHIFT    (30U)
#define USB_ANALOG_MISC_TOG_EN_CLK_UTMI(x)       (((uint32_t)(((uint32_t)(x)) << USB_ANALOG_MISC_TOG_EN_CLK_UTMI_SHIFT)) & USB_ANALOG_MISC_TOG_EN_CLK_UTMI_MASK)
/*! @} */

/* The count of USB_ANALOG_MISC_TOG */
#define USB_ANALOG_MISC_TOG_COUNT                (2U)

/*! @name DIGPROG - Chip Silicon Version */
/*! @{ */

#define USB_ANALOG_DIGPROG_SILICON_REVISION_MASK (0xFFFFFFFFU)
#define USB_ANALOG_DIGPROG_SILICON_REVISION_SHIFT (0U)
/*! SILICON_REVISION
 *  0b00000000011011000000000000000000..Silicon revision 1.0
 */
#define USB_ANALOG_DIGPROG_SILICON_REVISION(x)   (((uint32_t)(((uint32_t)(x)) << USB_ANALOG_DIGPROG_SILICON_REVISION_SHIFT)) & USB_ANALOG_DIGPROG_SILICON_REVISION_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group USB_ANALOG_Register_Masks */


/*!
 * @}
 */ /* end of group USB_ANALOG_Peripheral_Access_Layer */


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


#endif  /* PERI_USB_ANALOG_H_ */

