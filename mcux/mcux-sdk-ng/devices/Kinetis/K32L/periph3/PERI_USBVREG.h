/*
** ###################################################################
**     Processors:          K32L3A60VPJ1A_cm0plus
**                          K32L3A60VPJ1A_cm4
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for USBVREG
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2019-04-22)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_USBVREG.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for USBVREG
 *
 * CMSIS Peripheral Access Layer for USBVREG
 */

#if !defined(PERI_USBVREG_H_)
#define PERI_USBVREG_H_                          /**< Symbol preventing repeated inclusion */

#if (defined(CPU_K32L3A60VPJ1A_cm0plus))
#include "K32L3A60_cm0plus_COMMON.h"
#elif (defined(CPU_K32L3A60VPJ1A_cm4))
#include "K32L3A60_cm4_COMMON.h"
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
   -- USBVREG Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup USBVREG_Peripheral_Access_Layer USBVREG Peripheral Access Layer
 * @{
 */

/** USBVREG - Register Layout Typedef */
typedef struct {
  __IO uint32_t CTRL;                              /**< USB VREG Control Register, offset: 0x0 */
  __IO uint32_t CFGCTRL;                           /**< USB VREG Configuration Control Register, offset: 0x4 */
} USBVREG_Type;

/* ----------------------------------------------------------------------------
   -- USBVREG Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup USBVREG_Register_Masks USBVREG Register Masks
 * @{
 */

/*! @name CTRL - USB VREG Control Register */
/*! @{ */

#define USBVREG_CTRL_VSTBY_MASK                  (0x20000000U)
#define USBVREG_CTRL_VSTBY_SHIFT                 (29U)
/*! VSTBY - USB Voltage Regulator in Standby Mode during VLPR and VLPW modes
 *  0b0..USB voltage regulator is not in standby during VLPR and VLPW modes.
 *  0b1..USB voltage regulator in standby during VLPR and VLPW modes.
 */
#define USBVREG_CTRL_VSTBY(x)                    (((uint32_t)(((uint32_t)(x)) << USBVREG_CTRL_VSTBY_SHIFT)) & USBVREG_CTRL_VSTBY_MASK)

#define USBVREG_CTRL_SSTBY_MASK                  (0x40000000U)
#define USBVREG_CTRL_SSTBY_SHIFT                 (30U)
/*! SSTBY - USB Voltage Regulator in Standby Mode during Stop, VLPS, LLS and VLLS Modes
 *  0b0..USB voltage regulator is not in standby during Stop,VLPS,LLS and VLLS modes.
 *  0b1..USB voltage regulator is in standby during Stop,VLPS,LLS and VLLS modes.
 */
#define USBVREG_CTRL_SSTBY(x)                    (((uint32_t)(((uint32_t)(x)) << USBVREG_CTRL_SSTBY_SHIFT)) & USBVREG_CTRL_SSTBY_MASK)

#define USBVREG_CTRL_EN_MASK                     (0x80000000U)
#define USBVREG_CTRL_EN_SHIFT                    (31U)
/*! EN - USB Voltage Regulator Enable
 *  0b0..USB voltage regulator is disabled.
 *  0b1..USB voltage regulator is enabled.
 */
#define USBVREG_CTRL_EN(x)                       (((uint32_t)(((uint32_t)(x)) << USBVREG_CTRL_EN_SHIFT)) & USBVREG_CTRL_EN_MASK)
/*! @} */

/*! @name CFGCTRL - USB VREG Configuration Control Register */
/*! @{ */

#define USBVREG_CFGCTRL_URWE_MASK                (0x1000000U)
#define USBVREG_CFGCTRL_URWE_SHIFT               (24U)
/*! URWE - USB Voltage Regulator Enable Write Enable
 *  0b0..CTRL[EN] can not be written.
 *  0b1..CTRL[EN] can be written.
 */
#define USBVREG_CFGCTRL_URWE(x)                  (((uint32_t)(((uint32_t)(x)) << USBVREG_CFGCTRL_URWE_SHIFT)) & USBVREG_CFGCTRL_URWE_MASK)

#define USBVREG_CFGCTRL_UVSWE_MASK               (0x2000000U)
#define USBVREG_CFGCTRL_UVSWE_SHIFT              (25U)
/*! UVSWE - USB Voltage Regulator VLP Standby Write Enable
 *  0b0..CTRL[VSTBY] cannot be written.
 *  0b1..CTRL[VSTBY] can be written.
 */
#define USBVREG_CFGCTRL_UVSWE(x)                 (((uint32_t)(((uint32_t)(x)) << USBVREG_CFGCTRL_UVSWE_SHIFT)) & USBVREG_CFGCTRL_UVSWE_MASK)

#define USBVREG_CFGCTRL_USSWE_MASK               (0x4000000U)
#define USBVREG_CFGCTRL_USSWE_SHIFT              (26U)
/*! USSWE - USB Voltage Rregulator Stop Standby Write Enable
 *  0b0..CTRL[SSTBY] field cannot be written.
 *  0b1..CTRL[SSTBY] can be written.
 */
#define USBVREG_CFGCTRL_USSWE(x)                 (((uint32_t)(((uint32_t)(x)) << USBVREG_CFGCTRL_USSWE_SHIFT)) & USBVREG_CFGCTRL_USSWE_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group USBVREG_Register_Masks */


/*!
 * @}
 */ /* end of group USBVREG_Peripheral_Access_Layer */


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


#endif  /* PERI_USBVREG_H_ */

