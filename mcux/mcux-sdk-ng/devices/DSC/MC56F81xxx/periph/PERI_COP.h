/*
** ###################################################################
**     Processors:          MC56F81643LVLC
**                          MC56F81646LVLF
**                          MC56F81648LVLH
**                          MC56F81663LVLC
**                          MC56F81666LVLF
**                          MC56F81668LVLH
**                          MC56F81743LVLC
**                          MC56F81746LMLF
**                          MC56F81746LVLF
**                          MC56F81748LMLH
**                          MC56F81748LVLH
**                          MC56F81763LVLC
**                          MC56F81766AMLFA
**                          MC56F81766LMLF
**                          MC56F81766LVLF
**                          MC56F81768AMLHA
**                          MC56F81768LMLH
**                          MC56F81768LVLH
**                          MC56F81866AMLFA
**                          MC56F81866LVLF
**                          MC56F81868AMLHA
**                          MC56F81868LVLH
**
**     Version:             rev. 1.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for COP
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 0.1 (2019-12-10)
**         Initial version.
**     - rev. 1.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_COP.h
 * @version 1.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for COP
 *
 * CMSIS Peripheral Access Layer for COP
 */

#if !defined(PERI_COP_H_)
#define PERI_COP_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MC56F81643LVLC))
#include "MC56F81643_COMMON.h"
#elif (defined(CPU_MC56F81646LVLF))
#include "MC56F81646_COMMON.h"
#elif (defined(CPU_MC56F81648LVLH))
#include "MC56F81648_COMMON.h"
#elif (defined(CPU_MC56F81663LVLC))
#include "MC56F81663_COMMON.h"
#elif (defined(CPU_MC56F81666LVLF))
#include "MC56F81666_COMMON.h"
#elif (defined(CPU_MC56F81668LVLH))
#include "MC56F81668_COMMON.h"
#elif (defined(CPU_MC56F81743LVLC))
#include "MC56F81743_COMMON.h"
#elif (defined(CPU_MC56F81746LMLF) || defined(CPU_MC56F81746LVLF))
#include "MC56F81746_COMMON.h"
#elif (defined(CPU_MC56F81748LMLH) || defined(CPU_MC56F81748LVLH))
#include "MC56F81748_COMMON.h"
#elif (defined(CPU_MC56F81763LVLC))
#include "MC56F81763_COMMON.h"
#elif (defined(CPU_MC56F81766AMLFA) || defined(CPU_MC56F81766LMLF) || defined(CPU_MC56F81766LVLF))
#include "MC56F81766_COMMON.h"
#elif (defined(CPU_MC56F81768AMLHA) || defined(CPU_MC56F81768LMLH) || defined(CPU_MC56F81768LVLH))
#include "MC56F81768_COMMON.h"
#elif (defined(CPU_MC56F81866AMLFA) || defined(CPU_MC56F81866LVLF))
#include "MC56F81866_COMMON.h"
#elif (defined(CPU_MC56F81868AMLHA) || defined(CPU_MC56F81868LVLH))
#include "MC56F81868_COMMON.h"
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

#if defined(__CWCC__)
  #pragma push
  #pragma cpp_extensions on
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- COP Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup COP_Peripheral_Access_Layer COP Peripheral Access Layer
 * @{
 */

/** COP - Register Layout Typedef */
typedef struct {
  __IO uint16_t CTRL;                              /**< COP Control Register, offset: 0x0 */
  __IO uint16_t TOUT;                              /**< COP Timeout Register, offset: 0x1 */
  __IO uint16_t CNTR;                              /**< COP Counter Register, offset: 0x2 */
  __IO uint16_t INTVAL;                            /**< COP Interrupt Value Register, offset: 0x3 */
  __IO uint16_t WINDOW;                            /**< COP Window Timeout Register, offset: 0x4 */
} COP_Type;

/* ----------------------------------------------------------------------------
   -- COP Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup COP_Register_Masks COP Register Masks
 * @{
 */

/*! @name CTRL - COP Control Register */
/*! @{ */

#define COP_CTRL_CWP_MASK                        (0x1U)
#define COP_CTRL_CWP_SHIFT                       (0U)
/*! CWP - COP Write Protect
 *  0b0..The CTRL, INTVAL , WINDOW and TOUT registers are readable and writable. (default)
 *  0b1..The CTRL, INTVAL , WINDOW and TOUT registers are read-only.
 */
#define COP_CTRL_CWP(x)                          (((uint16_t)(((uint16_t)(x)) << COP_CTRL_CWP_SHIFT)) & COP_CTRL_CWP_MASK)

#define COP_CTRL_CEN_MASK                        (0x2U)
#define COP_CTRL_CEN_SHIFT                       (1U)
/*! CEN - COP Enable
 *  0b0..COP counter is disabled.
 *  0b1..COP counter is enabled. (default)
 */
#define COP_CTRL_CEN(x)                          (((uint16_t)(((uint16_t)(x)) << COP_CTRL_CEN_SHIFT)) & COP_CTRL_CEN_MASK)

#define COP_CTRL_CWEN_MASK                       (0x4U)
#define COP_CTRL_CWEN_SHIFT                      (2U)
/*! CWEN - COP Wait Mode Enable
 *  0b0..COP counter stops in wait mode. (default)
 *  0b1..COP counter runs in wait mode if CEN is set to one.
 */
#define COP_CTRL_CWEN(x)                         (((uint16_t)(((uint16_t)(x)) << COP_CTRL_CWEN_SHIFT)) & COP_CTRL_CWEN_MASK)

#define COP_CTRL_CSEN_MASK                       (0x8U)
#define COP_CTRL_CSEN_SHIFT                      (3U)
/*! CSEN - COP Stop Mode Enable
 *  0b0..COP counter stops in stop mode. (default)
 *  0b1..COP counter runs in stop mode if CEN is set to one.
 */
#define COP_CTRL_CSEN(x)                         (((uint16_t)(((uint16_t)(x)) << COP_CTRL_CSEN_SHIFT)) & COP_CTRL_CSEN_MASK)

#define COP_CTRL_CLOREN_MASK                     (0x10U)
#define COP_CTRL_CLOREN_SHIFT                    (4U)
/*! CLOREN - COP Loss of Reference Enable
 *  0b0..COP loss of reference counter is disabled. (default)
 *  0b1..COP loss of reference counter is enabled.
 */
#define COP_CTRL_CLOREN(x)                       (((uint16_t)(((uint16_t)(x)) << COP_CTRL_CLOREN_SHIFT)) & COP_CTRL_CLOREN_MASK)

#define COP_CTRL_CLKSEL_MASK                     (0x60U)
#define COP_CTRL_CLKSEL_SHIFT                    (5U)
/*! CLKSEL - Clock Source Select
 *  0b00..Relaxation oscillator output (ROSC) is used to clock the counter (default)
 *  0b01..Crystal oscillator output (COSC) is used to clock the counter
 *  0b10..IP bus clock is used to clock the counter Do not select the IP bus clock to clock the counter if the
 *        application requires the COP to wake the device from stop mode.
 *  0b11..Low speed oscillator is used to clock the counter
 */
#define COP_CTRL_CLKSEL(x)                       (((uint16_t)(((uint16_t)(x)) << COP_CTRL_CLKSEL_SHIFT)) & COP_CTRL_CLKSEL_MASK)

#define COP_CTRL_INTEN_MASK                      (0x80U)
#define COP_CTRL_INTEN_SHIFT                     (7U)
/*! INTEN - Interrupt Enable
 *  0b0..COP interrupt is disabled. (default)
 *  0b1..COP interrupt is enabled.
 */
#define COP_CTRL_INTEN(x)                        (((uint16_t)(((uint16_t)(x)) << COP_CTRL_INTEN_SHIFT)) & COP_CTRL_INTEN_MASK)

#define COP_CTRL_PSS_MASK                        (0x300U)
#define COP_CTRL_PSS_SHIFT                       (8U)
/*! PSS - Prescaler Select
 *  0b00..No division
 *  0b01..Divide by 16
 *  0b10..Divide by 256
 *  0b11..Divide by 1024
 */
#define COP_CTRL_PSS(x)                          (((uint16_t)(((uint16_t)(x)) << COP_CTRL_PSS_SHIFT)) & COP_CTRL_PSS_MASK)
/*! @} */

/*! @name TOUT - COP Timeout Register */
/*! @{ */

#define COP_TOUT_TIMEOUT_MASK                    (0xFFFFU)
#define COP_TOUT_TIMEOUT_SHIFT                   (0U)
/*! TIMEOUT - COP Timeout Period */
#define COP_TOUT_TIMEOUT(x)                      (((uint16_t)(((uint16_t)(x)) << COP_TOUT_TIMEOUT_SHIFT)) & COP_TOUT_TIMEOUT_MASK)
/*! @} */

/*! @name CNTR - COP Counter Register */
/*! @{ */

#define COP_CNTR_COUNT_SERVICE_MASK              (0xFFFFU)
#define COP_CNTR_COUNT_SERVICE_SHIFT             (0U)
/*! COUNT_SERVICE - COP Count/Service */
#define COP_CNTR_COUNT_SERVICE(x)                (((uint16_t)(((uint16_t)(x)) << COP_CNTR_COUNT_SERVICE_SHIFT)) & COP_CNTR_COUNT_SERVICE_MASK)
/*! @} */

/*! @name INTVAL - COP Interrupt Value Register */
/*! @{ */

#define COP_INTVAL_INTERRUPT_VALUE_MASK          (0xFFFFU)
#define COP_INTVAL_INTERRUPT_VALUE_SHIFT         (0U)
/*! INTERRUPT_VALUE - COP Interrupt Value */
#define COP_INTVAL_INTERRUPT_VALUE(x)            (((uint16_t)(((uint16_t)(x)) << COP_INTVAL_INTERRUPT_VALUE_SHIFT)) & COP_INTVAL_INTERRUPT_VALUE_MASK)
/*! @} */

/*! @name WINDOW - COP Window Timeout Register */
/*! @{ */

#define COP_WINDOW_WINDOW_VALUE_MASK             (0xFFFFU)
#define COP_WINDOW_WINDOW_VALUE_SHIFT            (0U)
/*! WINDOW_VALUE - COP Window Timeout Value */
#define COP_WINDOW_WINDOW_VALUE(x)               (((uint16_t)(((uint16_t)(x)) << COP_WINDOW_WINDOW_VALUE_SHIFT)) & COP_WINDOW_WINDOW_VALUE_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group COP_Register_Masks */


/*!
 * @}
 */ /* end of group COP_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

#if defined(__CWCC__)
  #pragma pop
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_COP_H_ */

