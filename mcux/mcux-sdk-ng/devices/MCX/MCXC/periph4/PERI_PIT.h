/*
** ###################################################################
**     Processors:          MCXC352GAMFM
**                          MCXC352GAMFT
**                          MCXC352MLF
**                          MCXC353GAMFM
**                          MCXC353GAMFT
**                          MCXC353MLF
**
**     Version:             rev. 1.0, 2025-11-26
**     Build:               b260826
**
**     Abstract:
**         CMSIS Peripheral Access Layer for PIT
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2026 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2025-11-26)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_PIT.h
 * @version 1.0
 * @date 2025-11-26
 * @brief CMSIS Peripheral Access Layer for PIT
 *
 * CMSIS Peripheral Access Layer for PIT
 */

#if !defined(PERI_PIT_H_)
#define PERI_PIT_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXC352GAMFM) || defined(CPU_MCXC352GAMFT) || defined(CPU_MCXC352MLF))
#include "MCXC352_COMMON.h"
#elif (defined(CPU_MCXC353GAMFM) || defined(CPU_MCXC353GAMFT) || defined(CPU_MCXC353MLF))
#include "MCXC353_COMMON.h"
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
   -- PIT Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PIT_Peripheral_Access_Layer PIT Peripheral Access Layer
 * @{
 */

/** PIT - Register Layout Typedef */
typedef struct {
  __IO uint16_t CTRL;                              /**< PIT Control Register, offset: 0x0 */
  __IO uint16_t MOD_L;                             /**< PIT Modulo Register Low Half Word, offset: 0x2 */
  __IO uint16_t MOD_H;                             /**< PIT Modulo Register High Half Word, offset: 0x4 */
  __I  uint16_t CNTR_L;                            /**< PIT Counter low half word Register, offset: 0x6 */
  __I  uint16_t CNTR_H;                            /**< PIT Counter high half word Register, offset: 0x8 */
  __IO uint16_t FILT;                              /**< PIT Preset Filter Register, offset: 0xA */
  __IO uint16_t CTRL2;                             /**< PIT Preset Filter Register, offset: 0xC */
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
/*! PRESCALER - PRESCALER
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

#define PIT_CTRL_PRESET_POLARITY_MASK            (0x80U)
#define PIT_CTRL_PRESET_POLARITY_SHIFT           (7U)
/*! PRESET_POLARITY - Preset Polarity.
 *  0b0..Preset signal take affect at positive edge. (default)
 *  0b1..Preset signal take affect at negative edge.
 */
#define PIT_CTRL_PRESET_POLARITY(x)              (((uint16_t)(((uint16_t)(x)) << PIT_CTRL_PRESET_POLARITY_SHIFT)) & PIT_CTRL_PRESET_POLARITY_MASK)

#define PIT_CTRL_CLKSEL_MASK                     (0x300U)
#define PIT_CTRL_CLKSEL_SHIFT                    (8U)
/*! CLKSEL - CLKSEL
 *  0b00..Selects IP Bus clock
 *  0b01..Selects alternate clock 1
 *  0b10..Selects alternate clock 2
 *  0b11..Selects alternate clock 3
 */
#define PIT_CTRL_CLKSEL(x)                       (((uint16_t)(((uint16_t)(x)) << PIT_CTRL_CLKSEL_SHIFT)) & PIT_CTRL_CLKSEL_MASK)
/*! @} */

/*! @name MOD_L - PIT Modulo Register Low Half Word */
/*! @{ */

#define PIT_MOD_L_MODULO_VALUE_MASK              (0xFFFFU)
#define PIT_MOD_L_MODULO_VALUE_SHIFT             (0U)
/*! MODULO_VALUE - MODULO_VALUE */
#define PIT_MOD_L_MODULO_VALUE(x)                (((uint16_t)(((uint16_t)(x)) << PIT_MOD_L_MODULO_VALUE_SHIFT)) & PIT_MOD_L_MODULO_VALUE_MASK)
/*! @} */

/*! @name MOD_H - PIT Modulo Register High Half Word */
/*! @{ */

#define PIT_MOD_H_MODULO_VALUE_MASK              (0xFFFFU)
#define PIT_MOD_H_MODULO_VALUE_SHIFT             (0U)
/*! MODULO_VALUE - MODULO_VALUE */
#define PIT_MOD_H_MODULO_VALUE(x)                (((uint16_t)(((uint16_t)(x)) << PIT_MOD_H_MODULO_VALUE_SHIFT)) & PIT_MOD_H_MODULO_VALUE_MASK)
/*! @} */

/*! @name CNTR_L - PIT Counter low half word Register */
/*! @{ */

#define PIT_CNTR_L_COUNTER_VALUE_MASK            (0xFFFFU)
#define PIT_CNTR_L_COUNTER_VALUE_SHIFT           (0U)
/*! COUNTER_VALUE - COUNTER_VALUE */
#define PIT_CNTR_L_COUNTER_VALUE(x)              (((uint16_t)(((uint16_t)(x)) << PIT_CNTR_L_COUNTER_VALUE_SHIFT)) & PIT_CNTR_L_COUNTER_VALUE_MASK)
/*! @} */

/*! @name CNTR_H - PIT Counter high half word Register */
/*! @{ */

#define PIT_CNTR_H_COUNTER_VALUE_MASK            (0xFFFFU)
#define PIT_CNTR_H_COUNTER_VALUE_SHIFT           (0U)
/*! COUNTER_VALUE - COUNTER_VALUE */
#define PIT_CNTR_H_COUNTER_VALUE(x)              (((uint16_t)(((uint16_t)(x)) << PIT_CNTR_H_COUNTER_VALUE_SHIFT)) & PIT_CNTR_H_COUNTER_VALUE_MASK)
/*! @} */

/*! @name FILT - PIT Preset Filter Register */
/*! @{ */

#define PIT_FILT_PER_MASK                        (0xFFU)
#define PIT_FILT_PER_SHIFT                       (0U)
/*! PER - Input Filter Sample Period */
#define PIT_FILT_PER(x)                          (((uint16_t)(((uint16_t)(x)) << PIT_FILT_PER_SHIFT)) & PIT_FILT_PER_MASK)

#define PIT_FILT_CNT_MASK                        (0x700U)
#define PIT_FILT_CNT_SHIFT                       (8U)
/*! CNT - Input Filter Sample Count */
#define PIT_FILT_CNT(x)                          (((uint16_t)(((uint16_t)(x)) << PIT_FILT_CNT_SHIFT)) & PIT_FILT_CNT_MASK)

#define PIT_FILT_CS_MASK                         (0x800U)
#define PIT_FILT_CS_SHIFT                        (11U)
/*! CS - Filter Clock Source selection
 *  0b0..Peripheral Clock
 *  0b1..Prescaled peripheral clock by PRSC
 */
#define PIT_FILT_CS(x)                           (((uint16_t)(((uint16_t)(x)) << PIT_FILT_CS_SHIFT)) & PIT_FILT_CS_MASK)

#define PIT_FILT_PRSC_MASK                       (0xF000U)
#define PIT_FILT_PRSC_SHIFT                      (12U)
/*! PRSC - Prescaler */
#define PIT_FILT_PRSC(x)                         (((uint16_t)(((uint16_t)(x)) << PIT_FILT_PRSC_SHIFT)) & PIT_FILT_PRSC_MASK)
/*! @} */

/*! @name CTRL2 - PIT Preset Filter Register */
/*! @{ */

#define PIT_CTRL2_STRETCH_COUNT_MASK             (0x7U)
#define PIT_CTRL2_STRETCH_COUNT_SHIFT            (0U)
/*! STRETCH_COUNT - The cycle number to be stretched for SYNC_OUT signal */
#define PIT_CTRL2_STRETCH_COUNT(x)               (((uint16_t)(((uint16_t)(x)) << PIT_CTRL2_STRETCH_COUNT_SHIFT)) & PIT_CTRL2_STRETCH_COUNT_MASK)

#define PIT_CTRL2_SYNC_OUT_SEL_MASK              (0x8000U)
#define PIT_CTRL2_SYNC_OUT_SEL_SHIFT             (15U)
/*! SYNC_OUT_SEL - SYNC_OUT_SEL
 *  0b0..SYNC_OUT take affect when PIT counter equal MODULO value.(default).
 *  0b1..SYNC_OUT is in toggle mode: after reset, SYNC_OUT is low-level, when PIT counter equals MODULO value
 *       firstly, SYNC_OUT toggles to high-level and keep high-level until PIT counter equal MODULO value next time,
 *       SYNC_OUT toggles to low-level, and so on....
 */
#define PIT_CTRL2_SYNC_OUT_SEL(x)                (((uint16_t)(((uint16_t)(x)) << PIT_CTRL2_SYNC_OUT_SEL_SHIFT)) & PIT_CTRL2_SYNC_OUT_SEL_MASK)
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


#endif  /* PERI_PIT_H_ */

