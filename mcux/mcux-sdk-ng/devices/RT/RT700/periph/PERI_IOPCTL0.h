/*
** ###################################################################
**     Processors:          MIMXRT735SGAWAR_cm33_core0
**                          MIMXRT735SGAWAR_cm33_core1
**                          MIMXRT735SGAWAR_ezhv
**                          MIMXRT735SGAWAR_hifi1
**                          MIMXRT735SGFOA_cm33_core0
**                          MIMXRT735SGFOA_cm33_core1
**                          MIMXRT735SGFOA_ezhv
**                          MIMXRT735SGFOA_hifi1
**                          MIMXRT758SGAWAR_cm33_core0
**                          MIMXRT758SGAWAR_cm33_core1
**                          MIMXRT758SGAWAR_ezhv
**                          MIMXRT758SGAWAR_hifi1
**                          MIMXRT758SGFOA_cm33_core0
**                          MIMXRT758SGFOA_cm33_core1
**                          MIMXRT758SGFOA_ezhv
**                          MIMXRT758SGFOA_hifi1
**                          MIMXRT798SGAWAR_cm33_core0
**                          MIMXRT798SGAWAR_cm33_core1
**                          MIMXRT798SGAWAR_ezhv
**                          MIMXRT798SGAWAR_hifi1
**                          MIMXRT798SGAWAR_hifi4
**                          MIMXRT798SGFOA_cm33_core0
**                          MIMXRT798SGFOA_cm33_core1
**                          MIMXRT798SGFOA_ezhv
**                          MIMXRT798SGFOA_hifi1
**                          MIMXRT798SGFOA_hifi4
**
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250526
**
**     Abstract:
**         CMSIS Peripheral Access Layer for IOPCTL0
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2022-09-15)
**         Initial version.
**     - rev. 2.0 (2024-05-28)
**         Rev2 DraftA.
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_IOPCTL0.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for IOPCTL0
 *
 * CMSIS Peripheral Access Layer for IOPCTL0
 */

#if !defined(PERI_IOPCTL0_H_)
#define PERI_IOPCTL0_H_                          /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT735SGAWAR_cm33_core0) || defined(CPU_MIMXRT735SGFOA_cm33_core0))
#include "MIMXRT735S_cm33_core0_COMMON.h"
#elif (defined(CPU_MIMXRT735SGAWAR_cm33_core1) || defined(CPU_MIMXRT735SGFOA_cm33_core1))
#include "MIMXRT735S_cm33_core1_COMMON.h"
#elif (defined(CPU_MIMXRT735SGAWAR_ezhv) || defined(CPU_MIMXRT735SGFOA_ezhv))
#include "MIMXRT735S_ezhv_COMMON.h"
#elif (defined(CPU_MIMXRT735SGAWAR_hifi1) || defined(CPU_MIMXRT735SGFOA_hifi1))
#include "MIMXRT735S_hifi1_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_cm33_core0) || defined(CPU_MIMXRT758SGFOA_cm33_core0))
#include "MIMXRT758S_cm33_core0_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_cm33_core1) || defined(CPU_MIMXRT758SGFOA_cm33_core1))
#include "MIMXRT758S_cm33_core1_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_ezhv) || defined(CPU_MIMXRT758SGFOA_ezhv))
#include "MIMXRT758S_ezhv_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_hifi1) || defined(CPU_MIMXRT758SGFOA_hifi1))
#include "MIMXRT758S_hifi1_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_cm33_core0) || defined(CPU_MIMXRT798SGFOA_cm33_core0))
#include "MIMXRT798S_cm33_core0_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_cm33_core1) || defined(CPU_MIMXRT798SGFOA_cm33_core1))
#include "MIMXRT798S_cm33_core1_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_ezhv) || defined(CPU_MIMXRT798SGFOA_ezhv))
#include "MIMXRT798S_ezhv_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_hifi1) || defined(CPU_MIMXRT798SGFOA_hifi1))
#include "MIMXRT798S_hifi1_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_hifi4) || defined(CPU_MIMXRT798SGFOA_hifi4))
#include "MIMXRT798S_hifi4_COMMON.h"
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
   -- IOPCTL0 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IOPCTL0_Peripheral_Access_Layer IOPCTL0 Peripheral Access Layer
 * @{
 */

/** IOPCTL0 - Size of Registers Arrays */
#define IOPCTL0_PIO_COUNT                         4u
#define IOPCTL0_PIO_PIO_COUNT                     32u

/** IOPCTL0 - Register Layout Typedef */
typedef struct {
  __IO uint32_t PIO[IOPCTL0_PIO_COUNT][IOPCTL0_PIO_PIO_COUNT]; /**< IOPCTL Configuration, array offset: 0x0, array step: index*0x80, index2*0x4, valid indices: [0][0-31], [1][0-19], [2][0-15], [3][0-14] */
} IOPCTL0_Type;

/* ----------------------------------------------------------------------------
   -- IOPCTL0 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IOPCTL0_Register_Masks IOPCTL0 Register Masks
 * @{
 */

/*! @name PIO - IOPCTL Configuration */
/*! @{ */

#define IOPCTL0_PIO_FSEL_MASK                    (0xFU)
#define IOPCTL0_PIO_FSEL_SHIFT                   (0U)
/*! FSEL - Function Selector (Digital Function)
 *  0b0000..Function 0
 *  0b0001..Function 1
 *  0b0010..Function 2
 *  0b0011..Function 3
 *  0b0100..Function 4
 *  0b0101..Function 5
 *  0b0110..Function 6
 *  0b0111..Function 7
 */
#define IOPCTL0_PIO_FSEL(x)                      (((uint32_t)(((uint32_t)(x)) << IOPCTL0_PIO_FSEL_SHIFT)) & IOPCTL0_PIO_FSEL_MASK)

#define IOPCTL0_PIO_PUPDENA_MASK                 (0x10U)
#define IOPCTL0_PIO_PUPDENA_SHIFT                (4U)
/*! PUPDENA - Pullup / Pulldown Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define IOPCTL0_PIO_PUPDENA(x)                   (((uint32_t)(((uint32_t)(x)) << IOPCTL0_PIO_PUPDENA_SHIFT)) & IOPCTL0_PIO_PUPDENA_MASK)

#define IOPCTL0_PIO_PUPDSEL_MASK                 (0x20U)
#define IOPCTL0_PIO_PUPDSEL_SHIFT                (5U)
/*! PUPDSEL - Pullup or Pulldown Selector
 *  0b0..Enables the internal pull-down resistor.
 *  0b1..Enables the internal pull-up resistor.
 */
#define IOPCTL0_PIO_PUPDSEL(x)                   (((uint32_t)(((uint32_t)(x)) << IOPCTL0_PIO_PUPDSEL_SHIFT)) & IOPCTL0_PIO_PUPDSEL_MASK)

#define IOPCTL0_PIO_IBENA_MASK                   (0x40U)
#define IOPCTL0_PIO_IBENA_SHIFT                  (6U)
/*! IBENA - Input Buffer Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define IOPCTL0_PIO_IBENA(x)                     (((uint32_t)(((uint32_t)(x)) << IOPCTL0_PIO_IBENA_SHIFT)) & IOPCTL0_PIO_IBENA_MASK)

#define IOPCTL0_PIO_SLEWRATE_MASK                (0x80U)
#define IOPCTL0_PIO_SLEWRATE_SHIFT               (7U)
/*! SLEWRATE - Slew Rate Control
 *  0b0..Disables, in standard mode.
 *  0b1..Enables, in slow mode.
 */
#define IOPCTL0_PIO_SLEWRATE(x)                  (((uint32_t)(((uint32_t)(x)) << IOPCTL0_PIO_SLEWRATE_SHIFT)) & IOPCTL0_PIO_SLEWRATE_MASK)

#define IOPCTL0_PIO_AMENA_MASK                   (0x200U)
#define IOPCTL0_PIO_AMENA_SHIFT                  (9U)
/*! AMENA - Analog Mux Enable
 *  0b0..Disables for digital pin function
 *  0b1..Enables for analog pin function
 */
#define IOPCTL0_PIO_AMENA(x)                     (((uint32_t)(((uint32_t)(x)) << IOPCTL0_PIO_AMENA_SHIFT)) & IOPCTL0_PIO_AMENA_MASK)

#define IOPCTL0_PIO_ODENA_MASK                   (0x400U)
#define IOPCTL0_PIO_ODENA_SHIFT                  (10U)
/*! ODENA - Open-drain Mode Enable
 *  0b0..Disables for normal push-pull output
 *  0b1..Enables for simulated open-drain output (high drive disabled)
 */
#define IOPCTL0_PIO_ODENA(x)                     (((uint32_t)(((uint32_t)(x)) << IOPCTL0_PIO_ODENA_SHIFT)) & IOPCTL0_PIO_ODENA_MASK)

#define IOPCTL0_PIO_IIENA_MASK                   (0x800U)
#define IOPCTL0_PIO_IIENA_SHIFT                  (11U)
/*! IIENA - Input Invert Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define IOPCTL0_PIO_IIENA(x)                     (((uint32_t)(((uint32_t)(x)) << IOPCTL0_PIO_IIENA_SHIFT)) & IOPCTL0_PIO_IIENA_MASK)

#define IOPCTL0_PIO_DRIVE_MASK                   (0x3000U)
#define IOPCTL0_PIO_DRIVE_SHIFT                  (12U)
/*! DRIVE - Drive */
#define IOPCTL0_PIO_DRIVE(x)                     (((uint32_t)(((uint32_t)(x)) << IOPCTL0_PIO_DRIVE_SHIFT)) & IOPCTL0_PIO_DRIVE_MASK)
/*! @} */

/* The count of IOPCTL0_PIO */
#define IOPCTL0_PIO_COUNT2                       (32U)


/*!
 * @}
 */ /* end of group IOPCTL0_Register_Masks */


/*!
 * @}
 */ /* end of group IOPCTL0_Peripheral_Access_Layer */


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


#endif  /* PERI_IOPCTL0_H_ */

