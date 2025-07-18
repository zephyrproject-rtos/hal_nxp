/*
** ###################################################################
**     Processors:          MC56F80623VLC
**                          MC56F80626VLF
**                          MC56F80643VLC
**                          MC56F80646VLF
**                          MC56F80648VLH
**                          MC56F80723VLC
**                          MC56F80726VLF
**                          MC56F80733VFM
**                          MC56F80736VLF
**                          MC56F80738VLH
**                          MC56F80743VFM
**                          MC56F80743VLC
**                          MC56F80746MLF
**                          MC56F80746VLF
**                          MC56F80748MLH
**                          MC56F80748VLH
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
**     - rev. 0.1 (2022-01-12)
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

#if (defined(CPU_MC56F80623VLC))
#include "MC56F80623_COMMON.h"
#elif (defined(CPU_MC56F80626VLF))
#include "MC56F80626_COMMON.h"
#elif (defined(CPU_MC56F80643VLC))
#include "MC56F80643_COMMON.h"
#elif (defined(CPU_MC56F80646VLF))
#include "MC56F80646_COMMON.h"
#elif (defined(CPU_MC56F80648VLH))
#include "MC56F80648_COMMON.h"
#elif (defined(CPU_MC56F80723VLC))
#include "MC56F80723_COMMON.h"
#elif (defined(CPU_MC56F80726VLF))
#include "MC56F80726_COMMON.h"
#elif (defined(CPU_MC56F80733VFM))
#include "MC56F80733_COMMON.h"
#elif (defined(CPU_MC56F80736VLF))
#include "MC56F80736_COMMON.h"
#elif (defined(CPU_MC56F80738VLH))
#include "MC56F80738_COMMON.h"
#elif (defined(CPU_MC56F80743VFM) || defined(CPU_MC56F80743VLC))
#include "MC56F80743_COMMON.h"
#elif (defined(CPU_MC56F80746MLF) || defined(CPU_MC56F80746VLF))
#include "MC56F80746_COMMON.h"
#elif (defined(CPU_MC56F80748MLH) || defined(CPU_MC56F80748VLH))
#include "MC56F80748_COMMON.h"
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
  __IO uint16_t CTRL;                              /**< Control Register, offset: 0x0 */
  __IO uint16_t MOD_L;                             /**< Modulo Register Low Half Word, offset: 0x1 */
  __IO uint16_t MOD_H;                             /**< Modulo Register High Half Word, offset: 0x2 */
  __I  uint16_t CNTR_L;                            /**< Counter low half word Register, offset: 0x3 */
  __I  uint16_t CNTR_H;                            /**< Counter high half word Register, offset: 0x4 */
  __IO uint16_t FILT;                              /**< Preset Filter Register, offset: 0x5 */
  __IO uint16_t CTRL2;                             /**< Control 2 Register, offset: 0x6 */
} PIT_Type;

/* ----------------------------------------------------------------------------
   -- PIT Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PIT_Register_Masks PIT Register Masks
 * @{
 */

/*! @name CTRL - Control Register */
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
 *  0b00..Selects IPBus clock
 *  0b01..Selects alternate clock 1
 *  0b10..Selects alternate clock 2
 *  0b11..Selects alternate clock 3
 */
#define PIT_CTRL_CLKSEL(x)                       (((uint16_t)(((uint16_t)(x)) << PIT_CTRL_CLKSEL_SHIFT)) & PIT_CTRL_CLKSEL_MASK)

#define PIT_CTRL_SLAVE_MASK                      (0x8000U)
#define PIT_CTRL_SLAVE_SHIFT                     (15U)
/*! SLAVE - SLAVE
 *  0b0..CNT_EN from this PIT is used to control operation (default).
 *  0b1..CNT_EN from master PIT is used to control operation.
 */
#define PIT_CTRL_SLAVE(x)                        (((uint16_t)(((uint16_t)(x)) << PIT_CTRL_SLAVE_SHIFT)) & PIT_CTRL_SLAVE_MASK)
/*! @} */

/*! @name MOD_L - Modulo Register Low Half Word */
/*! @{ */

#define PIT_MOD_L_MODULO_VALUE_MASK              (0xFFFFU)
#define PIT_MOD_L_MODULO_VALUE_SHIFT             (0U)
/*! MODULO_VALUE - MODULO_VALUE */
#define PIT_MOD_L_MODULO_VALUE(x)                (((uint16_t)(((uint16_t)(x)) << PIT_MOD_L_MODULO_VALUE_SHIFT)) & PIT_MOD_L_MODULO_VALUE_MASK)
/*! @} */

/*! @name MOD_H - Modulo Register High Half Word */
/*! @{ */

#define PIT_MOD_H_MODULO_VALUE_MASK              (0xFFFFU)
#define PIT_MOD_H_MODULO_VALUE_SHIFT             (0U)
/*! MODULO_VALUE - MODULO_VALUE */
#define PIT_MOD_H_MODULO_VALUE(x)                (((uint16_t)(((uint16_t)(x)) << PIT_MOD_H_MODULO_VALUE_SHIFT)) & PIT_MOD_H_MODULO_VALUE_MASK)
/*! @} */

/*! @name CNTR_L - Counter low half word Register */
/*! @{ */

#define PIT_CNTR_L_COUNTER_VALUE_MASK            (0xFFFFU)
#define PIT_CNTR_L_COUNTER_VALUE_SHIFT           (0U)
/*! COUNTER_VALUE - COUNTER_VALUE */
#define PIT_CNTR_L_COUNTER_VALUE(x)              (((uint16_t)(((uint16_t)(x)) << PIT_CNTR_L_COUNTER_VALUE_SHIFT)) & PIT_CNTR_L_COUNTER_VALUE_MASK)
/*! @} */

/*! @name CNTR_H - Counter high half word Register */
/*! @{ */

#define PIT_CNTR_H_COUNTER_VALUE_MASK            (0xFFFFU)
#define PIT_CNTR_H_COUNTER_VALUE_SHIFT           (0U)
/*! COUNTER_VALUE - COUNTER_VALUE */
#define PIT_CNTR_H_COUNTER_VALUE(x)              (((uint16_t)(((uint16_t)(x)) << PIT_CNTR_H_COUNTER_VALUE_SHIFT)) & PIT_CNTR_H_COUNTER_VALUE_MASK)
/*! @} */

/*! @name FILT - Preset Filter Register */
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
/*! CS - Clock Select for Filter
 *  0b0..module clock
 *  0b1..filter clock (prescaled module clock by PRSC)
 */
#define PIT_FILT_CS(x)                           (((uint16_t)(((uint16_t)(x)) << PIT_FILT_CS_SHIFT)) & PIT_FILT_CS_MASK)

#define PIT_FILT_PRSC_MASK                       (0xF000U)
#define PIT_FILT_PRSC_SHIFT                      (12U)
/*! PRSC - Prescaler */
#define PIT_FILT_PRSC(x)                         (((uint16_t)(((uint16_t)(x)) << PIT_FILT_PRSC_SHIFT)) & PIT_FILT_PRSC_MASK)
/*! @} */

/*! @name CTRL2 - Control 2 Register */
/*! @{ */

#define PIT_CTRL2_STRETCH_COUNT_MASK             (0x7U)
#define PIT_CTRL2_STRETCH_COUNT_SHIFT            (0U)
/*! STRETCH_COUNT - The cycle number to be stretched for SYNC_OUT signal */
#define PIT_CTRL2_STRETCH_COUNT(x)               (((uint16_t)(((uint16_t)(x)) << PIT_CTRL2_STRETCH_COUNT_SHIFT)) & PIT_CTRL2_STRETCH_COUNT_MASK)

#define PIT_CTRL2_SYNC_OUT_SEL_MASK              (0x8000U)
#define PIT_CTRL2_SYNC_OUT_SEL_SHIFT             (15U)
/*! SYNC_OUT_SEL - SYNC_OUT_SEL
 *  0b0..SYNC_OUT is in pulse mode: SYNC_OUT will assert a pulse when PIT counter equals to the MODULO value. The
 *       pulse width is decided by CTRL2[STRETCH_COUNT].
 *  0b1..SYNC_OUT is in toggle mode: after reset, SYNC_OUT is low-level, when PIT counter equals to MODULO value
 *       the first time, SYNC_OUT toggles to high-level and keep it until PIT counter equals to MODULO value the
 *       next time, SYNC_OUT toggles to low-level, and so on.
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

#if defined(__CWCC__)
  #pragma pop
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_PIT_H_ */

