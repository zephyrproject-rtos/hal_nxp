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
**     Version:             rev. 2.0, 2024-05-28
**     Build:               b241121
**
**     Abstract:
**         CMSIS Peripheral Access Layer for IOPCTL2
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
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
**
** ###################################################################
*/

/*!
 * @file IOPCTL2.h
 * @version 2.0
 * @date 2024-05-28
 * @brief CMSIS Peripheral Access Layer for IOPCTL2
 *
 * CMSIS Peripheral Access Layer for IOPCTL2
 */

#if !defined(IOPCTL2_H_)
#define IOPCTL2_H_                               /**< Symbol preventing repeated inclusion */

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
   -- IOPCTL2 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IOPCTL2_Peripheral_Access_Layer IOPCTL2 Peripheral Access Layer
 * @{
 */

/** IOPCTL2 - Size of Registers Arrays */
#define IOPCTL2_PIO_PIO_COUNT                     26u
#define IOPCTL2_PIO_COUNT                         4u

/** IOPCTL2 - Register Layout Typedef */
typedef struct {
  struct {                                         /* offset: 0x0, array step: 0x80 */
    __IO uint32_t PIO[IOPCTL2_PIO_PIO_COUNT];        /**< IOPCTL Configuration, array offset: 0x0, array step: index*0x80, index2*0x4, valid indices: [0][0-20], [1][0-20], [2][0-12], [3][0-25] */
         uint8_t RESERVED_0[24];
  } PIO[IOPCTL2_PIO_COUNT];
} IOPCTL2_Type;

/* ----------------------------------------------------------------------------
   -- IOPCTL2 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IOPCTL2_Register_Masks IOPCTL2 Register Masks
 * @{
 */

/*! @name PIO - IOPCTL Configuration */
/*! @{ */

#define IOPCTL2_PIO_FSEL_MASK                    (0xFU)
#define IOPCTL2_PIO_FSEL_SHIFT                   (0U)
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
#define IOPCTL2_PIO_FSEL(x)                      (((uint32_t)(((uint32_t)(x)) << IOPCTL2_PIO_FSEL_SHIFT)) & IOPCTL2_PIO_FSEL_MASK)

#define IOPCTL2_PIO_PUPDENA_MASK                 (0x10U)
#define IOPCTL2_PIO_PUPDENA_SHIFT                (4U)
/*! PUPDENA - Pullup / Pulldown Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define IOPCTL2_PIO_PUPDENA(x)                   (((uint32_t)(((uint32_t)(x)) << IOPCTL2_PIO_PUPDENA_SHIFT)) & IOPCTL2_PIO_PUPDENA_MASK)

#define IOPCTL2_PIO_PUPDSEL_MASK                 (0x20U)
#define IOPCTL2_PIO_PUPDSEL_SHIFT                (5U)
/*! PUPDSEL - Pullup or Pulldown Selector
 *  0b0..Enables the internal pull-down resistor.
 *  0b1..Enables the internal pull-up resistor.
 */
#define IOPCTL2_PIO_PUPDSEL(x)                   (((uint32_t)(((uint32_t)(x)) << IOPCTL2_PIO_PUPDSEL_SHIFT)) & IOPCTL2_PIO_PUPDSEL_MASK)

#define IOPCTL2_PIO_IBENA_MASK                   (0x40U)
#define IOPCTL2_PIO_IBENA_SHIFT                  (6U)
/*! IBENA - Input Buffer Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define IOPCTL2_PIO_IBENA(x)                     (((uint32_t)(((uint32_t)(x)) << IOPCTL2_PIO_IBENA_SHIFT)) & IOPCTL2_PIO_IBENA_MASK)

#define IOPCTL2_PIO_ODENA_MASK                   (0x400U)
#define IOPCTL2_PIO_ODENA_SHIFT                  (10U)
/*! ODENA - Open-drain Mode Enable
 *  0b0..Disables for normal push-pull output
 *  0b1..Enables for simulated open-drain output (high drive disabled)
 */
#define IOPCTL2_PIO_ODENA(x)                     (((uint32_t)(((uint32_t)(x)) << IOPCTL2_PIO_ODENA_SHIFT)) & IOPCTL2_PIO_ODENA_MASK)

#define IOPCTL2_PIO_IIENA_MASK                   (0x800U)
#define IOPCTL2_PIO_IIENA_SHIFT                  (11U)
/*! IIENA - Input Invert Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define IOPCTL2_PIO_IIENA(x)                     (((uint32_t)(((uint32_t)(x)) << IOPCTL2_PIO_IIENA_SHIFT)) & IOPCTL2_PIO_IIENA_MASK)

#define IOPCTL2_PIO_DRIVE_MASK                   (0x3000U)
#define IOPCTL2_PIO_DRIVE_SHIFT                  (12U)
/*! DRIVE - Drive
 *  0b00..100 ohm
 *  0b01..66 ohm
 *  0b10..50 ohm
 *  0b11..33 ohm
 */
#define IOPCTL2_PIO_DRIVE(x)                     (((uint32_t)(((uint32_t)(x)) << IOPCTL2_PIO_DRIVE_SHIFT)) & IOPCTL2_PIO_DRIVE_MASK)
/*! @} */

/* The count of IOPCTL2_PIO */
#define IOPCTL2_PIO_COUNT2                       (26U)


/*!
 * @}
 */ /* end of group IOPCTL2_Register_Masks */


/*!
 * @}
 */ /* end of group IOPCTL2_Peripheral_Access_Layer */


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


#endif  /* IOPCTL2_H_ */

