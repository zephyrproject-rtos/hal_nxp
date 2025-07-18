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
**         CMSIS Peripheral Access Layer for PIT
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
 * @file PERI_PIT.h
 * @version 1.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for PIT
 *
 * CMSIS Peripheral Access Layer for PIT
 */

#if !defined(PERI_PIT_H_)
#define PERI_PIT_H_                              /**< Symbol preventing repeated inclusion */

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
   -- PIT Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PIT_Peripheral_Access_Layer PIT Peripheral Access Layer
 * @{
 */

/** PIT - Register Layout Typedef */
typedef struct {
  __IO uint16_t CTRL;                              /**< PIT Control Register, offset: 0x0 */
  __IO uint16_t MOD_L;                             /**< PIT Modulo Register Low Half Word, offset: 0x1 */
  __IO uint16_t MOD_H;                             /**< PIT Modulo Register High Half Word, offset: 0x2 */
  __I  uint16_t CNTR_L;                            /**< PIT Counter low half word Register, offset: 0x3 */
  __I  uint16_t CNTR_H;                            /**< PIT Counter high half word Register, offset: 0x4 */
} PIT_Type;

/* ----------------------------------------------------------------------------
   -- PIT Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PIT_Register_Masks PIT Register Masks
 * @{
 */

/*! @name CTRL - PIT Control Register */
/*! @{ */

#define PIT_CTRL_CNT_EN_MASK                     (0x1U)
#define PIT_CTRL_CNT_EN_SHIFT                    (0U)
/*! CNT_EN - Count Enable
 *  0b0..PIT counter reset (default).
 *  0b1..PIT counter active.
 */
#define PIT_CTRL_CNT_EN(x)                       (((uint16_t)(((uint16_t)(x)) << PIT_CTRL_CNT_EN_SHIFT)) & PIT_CTRL_CNT_EN_MASK)

#define PIT_CTRL_PRIE_MASK                       (0x2U)
#define PIT_CTRL_PRIE_SHIFT                      (1U)
/*! PRIE - PIT Roll-Over Interrupt Enable.
 *  0b0..PIT roll-over interrupt disabled (default).
 *  0b1..PIT roll-over interrupt enabled.
 */
#define PIT_CTRL_PRIE(x)                         (((uint16_t)(((uint16_t)(x)) << PIT_CTRL_PRIE_SHIFT)) & PIT_CTRL_PRIE_MASK)

#define PIT_CTRL_PRF_MASK                        (0x4U)
#define PIT_CTRL_PRF_SHIFT                       (2U)
/*! PRF - PIT Roll-Over Flag.
 *  0b0..PIT counter has not reached the modulo value. (default)
 *  0b1..PIT counter has reached the modulo value.
 */
#define PIT_CTRL_PRF(x)                          (((uint16_t)(((uint16_t)(x)) << PIT_CTRL_PRF_SHIFT)) & PIT_CTRL_PRF_MASK)

#define PIT_CTRL_PRESCALER_MASK                  (0x78U)
#define PIT_CTRL_PRESCALER_SHIFT                 (3U)
/*! PRESCALER
 *  0b0000..Clock
 *  0b0001..Clock divided by 2
 *  0b0010..Clock divided by 4
 *  0b0011..Clock divided by 8
 *  0b0100..Clock divided by 16
 *  0b0101..Clock divided by 32
 *  0b0110..Clock divided by 64
 *  0b0111..Clock divided by 128
 *  0b1000..Clock divided by 256
 *  0b1001..Clock divided by 512
 *  0b1010..Clock divided by 1024
 *  0b1011..Clock divided by 2048
 *  0b1100..Clock divided by 4096
 *  0b1101..Clock divided by 8192
 *  0b1110..Clock divided by 16384
 *  0b1111..Clock divided by 32768
 */
#define PIT_CTRL_PRESCALER(x)                    (((uint16_t)(((uint16_t)(x)) << PIT_CTRL_PRESCALER_SHIFT)) & PIT_CTRL_PRESCALER_MASK)

#define PIT_CTRL_CLKSEL_MASK                     (0x300U)
#define PIT_CTRL_CLKSEL_SHIFT                    (8U)
/*! CLKSEL
 *  0b00..Selects IPBus clock
 *  0b01..Selects alternate clock 1
 *  0b10..Selects alternate clock 2
 *  0b11..Selects alternate clock 3
 */
#define PIT_CTRL_CLKSEL(x)                       (((uint16_t)(((uint16_t)(x)) << PIT_CTRL_CLKSEL_SHIFT)) & PIT_CTRL_CLKSEL_MASK)

#define PIT_CTRL_SLAVE_MASK                      (0x8000U)
#define PIT_CTRL_SLAVE_SHIFT                     (15U)
/*! SLAVE
 *  0b0..CNT_EN from this PIT is used to control operation (default).
 *  0b1..CNT_EN from master PIT is used to control operation.
 */
#define PIT_CTRL_SLAVE(x)                        (((uint16_t)(((uint16_t)(x)) << PIT_CTRL_SLAVE_SHIFT)) & PIT_CTRL_SLAVE_MASK)
/*! @} */

/*! @name MOD_L - PIT Modulo Register Low Half Word */
/*! @{ */

#define PIT_MOD_L_MODULO_VALUE_MASK              (0xFFFFU)
#define PIT_MOD_L_MODULO_VALUE_SHIFT             (0U)
#define PIT_MOD_L_MODULO_VALUE(x)                (((uint16_t)(((uint16_t)(x)) << PIT_MOD_L_MODULO_VALUE_SHIFT)) & PIT_MOD_L_MODULO_VALUE_MASK)
/*! @} */

/*! @name MOD_H - PIT Modulo Register High Half Word */
/*! @{ */

#define PIT_MOD_H_MODULO_VALUE_MASK              (0xFFFFU)
#define PIT_MOD_H_MODULO_VALUE_SHIFT             (0U)
#define PIT_MOD_H_MODULO_VALUE(x)                (((uint16_t)(((uint16_t)(x)) << PIT_MOD_H_MODULO_VALUE_SHIFT)) & PIT_MOD_H_MODULO_VALUE_MASK)
/*! @} */

/*! @name CNTR_L - PIT Counter low half word Register */
/*! @{ */

#define PIT_CNTR_L_COUNTER_VALUE_MASK            (0xFFFFU)
#define PIT_CNTR_L_COUNTER_VALUE_SHIFT           (0U)
#define PIT_CNTR_L_COUNTER_VALUE(x)              (((uint16_t)(((uint16_t)(x)) << PIT_CNTR_L_COUNTER_VALUE_SHIFT)) & PIT_CNTR_L_COUNTER_VALUE_MASK)
/*! @} */

/*! @name CNTR_H - PIT Counter high half word Register */
/*! @{ */

#define PIT_CNTR_H_COUNTER_VALUE_MASK            (0xFFFFU)
#define PIT_CNTR_H_COUNTER_VALUE_SHIFT           (0U)
#define PIT_CNTR_H_COUNTER_VALUE(x)              (((uint16_t)(((uint16_t)(x)) << PIT_CNTR_H_COUNTER_VALUE_SHIFT)) & PIT_CNTR_H_COUNTER_VALUE_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group PIT_Register_Masks */


/*!
 * @}
 */ /* end of group PIT_Peripheral_Access_Layer */


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


#endif  /* PERI_PIT_H_ */

