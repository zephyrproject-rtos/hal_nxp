/*
** ###################################################################
**     Processors:          MKW21D256VHA5
**                          MKW21D512VHA5
**                          MKW22D512VHA5
**                          MKW24D512VHA5
**
**     Version:             rev. 2.0, 2015-01-06
**     Build:               b240710
**
**     Abstract:
**         CMSIS Peripheral Access Layer for PDB
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2013-11-22)
**         Initial version.
**     - rev. 2.0 (2015-01-06)
**         update of SystemInit() imlementation
**         Module access macro module_BASES replaced by module_BASE_PTRS.
**         Register accessor macros added to the memory map.
**         MCG - bit LOLS in MCG_S register renamed to LOLS0.
**         DAC0 registers removed.
**
** ###################################################################
*/

/*!
 * @file PDB.h
 * @version 2.0
 * @date 2015-01-06
 * @brief CMSIS Peripheral Access Layer for PDB
 *
 * CMSIS Peripheral Access Layer for PDB
 */

#if !defined(PDB_H_)
#define PDB_H_                                   /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MKW21D256VHA5) || defined(CPU_MKW21D512VHA5))
#include "MKW21D5_COMMON.h"
#elif (defined(CPU_MKW21D256VHA5) || defined(CPU_MKW21D512VHA5))
#include "MKW21D5WS_COMMON.h"
#elif (defined(CPU_MKW22D512VHA5))
#include "MKW22D5_COMMON.h"
#elif (defined(CPU_MKW22D512VHA5))
#include "MKW22D5WS_COMMON.h"
#elif (defined(CPU_MKW24D512VHA5))
#include "MKW24D5_COMMON.h"
#elif (defined(CPU_MKW24D512VHA5))
#include "MKW24D5WS_COMMON.h"
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
   -- PDB Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PDB_Peripheral_Access_Layer PDB Peripheral Access Layer
 * @{
 */

/** PDB - Size of Registers Arrays */
#define PDB_CH_DLY_COUNT                          2u
#define PDB_CH_COUNT                              2u
#define PDB_DAC_COUNT                             1u
#define PDB_PODLY_COUNT                           2u

/** PDB - Register Layout Typedef */
typedef struct {
  __IO uint32_t SC;                                /**< Status and Control Register, offset: 0x0 */
  __IO uint32_t MOD;                               /**< Modulus Register, offset: 0x4 */
  __I  uint32_t CNT;                               /**< Counter Register, offset: 0x8 */
  __IO uint32_t IDLY;                              /**< Interrupt Delay Register, offset: 0xC */
  struct {                                         /* offset: 0x10, array step: 0x28 */
    __IO uint32_t C1;                                /**< Channel n Control Register 1, array offset: 0x10, array step: 0x28 */
    __IO uint32_t S;                                 /**< Channel n Status Register, array offset: 0x14, array step: 0x28 */
    __IO uint32_t DLY[PDB_CH_DLY_COUNT];             /**< Channel n Delay 0 Register..Channel n Delay 1 Register, array offset: 0x18, array step: index*0x28, index2*0x4 */
         uint8_t RESERVED_0[24];
  } CH[PDB_CH_COUNT];
       uint8_t RESERVED_0[240];
  struct {                                         /* offset: 0x150, array step: 0x8 */
    __IO uint32_t INTC;                              /**< DAC Interval Trigger n Control Register, array offset: 0x150, array step: 0x8 */
    __IO uint32_t INT;                               /**< DAC Interval n Register, array offset: 0x154, array step: 0x8 */
  } DAC[PDB_DAC_COUNT];
       uint8_t RESERVED_1[56];
  __IO uint32_t POEN;                              /**< Pulse-Out n Enable Register, offset: 0x190 */
  __IO uint32_t PODLY[PDB_PODLY_COUNT];            /**< Pulse-Out n Delay Register, array offset: 0x194, array step: 0x4 */
} PDB_Type;

/* ----------------------------------------------------------------------------
   -- PDB Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PDB_Register_Masks PDB Register Masks
 * @{
 */

/*! @name SC - Status and Control Register */
/*! @{ */

#define PDB_SC_LDOK_MASK                         (0x1U)
#define PDB_SC_LDOK_SHIFT                        (0U)
/*! LDOK - Load OK */
#define PDB_SC_LDOK(x)                           (((uint32_t)(((uint32_t)(x)) << PDB_SC_LDOK_SHIFT)) & PDB_SC_LDOK_MASK)

#define PDB_SC_CONT_MASK                         (0x2U)
#define PDB_SC_CONT_SHIFT                        (1U)
/*! CONT - Continuous Mode Enable
 *  0b0..PDB operation in One-Shot mode
 *  0b1..PDB operation in Continuous mode
 */
#define PDB_SC_CONT(x)                           (((uint32_t)(((uint32_t)(x)) << PDB_SC_CONT_SHIFT)) & PDB_SC_CONT_MASK)

#define PDB_SC_MULT_MASK                         (0xCU)
#define PDB_SC_MULT_SHIFT                        (2U)
/*! MULT - Multiplication Factor Select for Prescaler
 *  0b00..Multiplication factor is 1
 *  0b01..Multiplication factor is 10
 *  0b10..Multiplication factor is 20
 *  0b11..Multiplication factor is 40
 */
#define PDB_SC_MULT(x)                           (((uint32_t)(((uint32_t)(x)) << PDB_SC_MULT_SHIFT)) & PDB_SC_MULT_MASK)

#define PDB_SC_PDBIE_MASK                        (0x20U)
#define PDB_SC_PDBIE_SHIFT                       (5U)
/*! PDBIE - PDB Interrupt Enable.
 *  0b0..PDB interrupt disabled
 *  0b1..PDB interrupt enabled
 */
#define PDB_SC_PDBIE(x)                          (((uint32_t)(((uint32_t)(x)) << PDB_SC_PDBIE_SHIFT)) & PDB_SC_PDBIE_MASK)

#define PDB_SC_PDBIF_MASK                        (0x40U)
#define PDB_SC_PDBIF_SHIFT                       (6U)
/*! PDBIF - PDB Interrupt Flag */
#define PDB_SC_PDBIF(x)                          (((uint32_t)(((uint32_t)(x)) << PDB_SC_PDBIF_SHIFT)) & PDB_SC_PDBIF_MASK)

#define PDB_SC_PDBEN_MASK                        (0x80U)
#define PDB_SC_PDBEN_SHIFT                       (7U)
/*! PDBEN - PDB Enable
 *  0b0..PDB disabled. Counter is off.
 *  0b1..PDB enabled.
 */
#define PDB_SC_PDBEN(x)                          (((uint32_t)(((uint32_t)(x)) << PDB_SC_PDBEN_SHIFT)) & PDB_SC_PDBEN_MASK)

#define PDB_SC_TRGSEL_MASK                       (0xF00U)
#define PDB_SC_TRGSEL_SHIFT                      (8U)
/*! TRGSEL - Trigger Input Source Select
 *  0b0000..Trigger-In 0 is selected
 *  0b0001..Trigger-In 1 is selected
 *  0b0010..Trigger-In 2 is selected
 *  0b0011..Trigger-In 3 is selected
 *  0b0100..Trigger-In 4 is selected
 *  0b0101..Trigger-In 5 is selected
 *  0b0110..Trigger-In 6 is selected
 *  0b0111..Trigger-In 7 is selected
 *  0b1000..Trigger-In 8 is selected
 *  0b1001..Trigger-In 9 is selected
 *  0b1010..Trigger-In 10 is selected
 *  0b1011..Trigger-In 11 is selected
 *  0b1100..Trigger-In 12 is selected
 *  0b1101..Trigger-In 13 is selected
 *  0b1110..Trigger-In 14 is selected
 *  0b1111..Software trigger is selected
 */
#define PDB_SC_TRGSEL(x)                         (((uint32_t)(((uint32_t)(x)) << PDB_SC_TRGSEL_SHIFT)) & PDB_SC_TRGSEL_MASK)

#define PDB_SC_PRESCALER_MASK                    (0x7000U)
#define PDB_SC_PRESCALER_SHIFT                   (12U)
/*! PRESCALER - Prescaler Divider Select
 *  0b000..Counting uses the peripheral clock divided by multiplication factor selected by MULT.
 *  0b001..Counting uses the peripheral clock divided by twice of the multiplication factor selected by MULT.
 *  0b010..Counting uses the peripheral clock divided by four times of the multiplication factor selected by MULT.
 *  0b011..Counting uses the peripheral clock divided by eight times of the multiplication factor selected by MULT.
 *  0b100..Counting uses the peripheral clock divided by 16 times of the multiplication factor selected by MULT.
 *  0b101..Counting uses the peripheral clock divided by 32 times of the multiplication factor selected by MULT.
 *  0b110..Counting uses the peripheral clock divided by 64 times of the multiplication factor selected by MULT.
 *  0b111..Counting uses the peripheral clock divided by 128 times of the multiplication factor selected by MULT.
 */
#define PDB_SC_PRESCALER(x)                      (((uint32_t)(((uint32_t)(x)) << PDB_SC_PRESCALER_SHIFT)) & PDB_SC_PRESCALER_MASK)

#define PDB_SC_DMAEN_MASK                        (0x8000U)
#define PDB_SC_DMAEN_SHIFT                       (15U)
/*! DMAEN - DMA Enable
 *  0b0..DMA disabled
 *  0b1..DMA enabled
 */
#define PDB_SC_DMAEN(x)                          (((uint32_t)(((uint32_t)(x)) << PDB_SC_DMAEN_SHIFT)) & PDB_SC_DMAEN_MASK)

#define PDB_SC_SWTRIG_MASK                       (0x10000U)
#define PDB_SC_SWTRIG_SHIFT                      (16U)
/*! SWTRIG - Software Trigger */
#define PDB_SC_SWTRIG(x)                         (((uint32_t)(((uint32_t)(x)) << PDB_SC_SWTRIG_SHIFT)) & PDB_SC_SWTRIG_MASK)

#define PDB_SC_PDBEIE_MASK                       (0x20000U)
#define PDB_SC_PDBEIE_SHIFT                      (17U)
/*! PDBEIE - PDB Sequence Error Interrupt Enable
 *  0b0..PDB sequence error interrupt disabled.
 *  0b1..PDB sequence error interrupt enabled.
 */
#define PDB_SC_PDBEIE(x)                         (((uint32_t)(((uint32_t)(x)) << PDB_SC_PDBEIE_SHIFT)) & PDB_SC_PDBEIE_MASK)

#define PDB_SC_LDMOD_MASK                        (0xC0000U)
#define PDB_SC_LDMOD_SHIFT                       (18U)
/*! LDMOD - Load Mode Select
 *  0b00..The internal registers are loaded with the values from their buffers immediately after 1 is written to LDOK.
 *  0b01..The internal registers are loaded with the values from their buffers when the PDB counter reaches the
 *        MOD register value after 1 is written to LDOK.
 *  0b10..The internal registers are loaded with the values from their buffers when a trigger input event is detected after 1 is written to LDOK.
 *  0b11..The internal registers are loaded with the values from their buffers when either the PDB counter reaches
 *        the MOD register value or a trigger input event is detected, after 1 is written to LDOK.
 */
#define PDB_SC_LDMOD(x)                          (((uint32_t)(((uint32_t)(x)) << PDB_SC_LDMOD_SHIFT)) & PDB_SC_LDMOD_MASK)
/*! @} */

/*! @name MOD - Modulus Register */
/*! @{ */

#define PDB_MOD_MOD_MASK                         (0xFFFFU)
#define PDB_MOD_MOD_SHIFT                        (0U)
/*! MOD - PDB Modulus */
#define PDB_MOD_MOD(x)                           (((uint32_t)(((uint32_t)(x)) << PDB_MOD_MOD_SHIFT)) & PDB_MOD_MOD_MASK)
/*! @} */

/*! @name CNT - Counter Register */
/*! @{ */

#define PDB_CNT_CNT_MASK                         (0xFFFFU)
#define PDB_CNT_CNT_SHIFT                        (0U)
/*! CNT - PDB Counter */
#define PDB_CNT_CNT(x)                           (((uint32_t)(((uint32_t)(x)) << PDB_CNT_CNT_SHIFT)) & PDB_CNT_CNT_MASK)
/*! @} */

/*! @name IDLY - Interrupt Delay Register */
/*! @{ */

#define PDB_IDLY_IDLY_MASK                       (0xFFFFU)
#define PDB_IDLY_IDLY_SHIFT                      (0U)
/*! IDLY - PDB Interrupt Delay */
#define PDB_IDLY_IDLY(x)                         (((uint32_t)(((uint32_t)(x)) << PDB_IDLY_IDLY_SHIFT)) & PDB_IDLY_IDLY_MASK)
/*! @} */

/*! @name C1 - Channel n Control Register 1 */
/*! @{ */

#define PDB_C1_EN_MASK                           (0xFFU)
#define PDB_C1_EN_SHIFT                          (0U)
/*! EN - PDB Channel Pre-Trigger Enable
 *  0b00000000..PDB channel's corresponding pre-trigger disabled.
 *  0b00000001..PDB channel's corresponding pre-trigger enabled.
 */
#define PDB_C1_EN(x)                             (((uint32_t)(((uint32_t)(x)) << PDB_C1_EN_SHIFT)) & PDB_C1_EN_MASK)

#define PDB_C1_TOS_MASK                          (0xFF00U)
#define PDB_C1_TOS_SHIFT                         (8U)
/*! TOS - PDB Channel Pre-Trigger Output Select
 *  0b00000000..PDB channel's corresponding pre-trigger is in bypassed mode. The pre-trigger asserts one
 *              peripheral clock cycle after a rising edge is detected on selected trigger input source or software trigger
 *              is selected and SWTRIG is written with 1.
 *  0b00000001..PDB channel's corresponding pre-trigger asserts when the counter reaches the channel delay
 *              register and one peripheral clock cycle after a rising edge is detected on selected trigger input source
 *              or software trigger is selected and SETRIG is written with 1.
 */
#define PDB_C1_TOS(x)                            (((uint32_t)(((uint32_t)(x)) << PDB_C1_TOS_SHIFT)) & PDB_C1_TOS_MASK)

#define PDB_C1_BB_MASK                           (0xFF0000U)
#define PDB_C1_BB_SHIFT                          (16U)
/*! BB - PDB Channel Pre-Trigger Back-to-Back Operation Enable
 *  0b00000000..PDB channel's corresponding pre-trigger back-to-back operation disabled.
 *  0b00000001..PDB channel's corresponding pre-trigger back-to-back operation enabled.
 */
#define PDB_C1_BB(x)                             (((uint32_t)(((uint32_t)(x)) << PDB_C1_BB_SHIFT)) & PDB_C1_BB_MASK)
/*! @} */

/* The count of PDB_C1 */
#define PDB_C1_COUNT                             (2U)

/*! @name S - Channel n Status Register */
/*! @{ */

#define PDB_S_ERR_MASK                           (0xFFU)
#define PDB_S_ERR_SHIFT                          (0U)
/*! ERR - PDB Channel Sequence Error Flags
 *  0b00000000..Sequence error not detected on PDB channel's corresponding pre-trigger.
 *  0b00000001..Sequence error detected on PDB channel's corresponding pre-trigger. ADCn block can be triggered
 *              for a conversion by one pre-trigger from PDB channel n. When one conversion, which is triggered by
 *              one of the pre-triggers from PDB channel n, is in progress, new trigger from PDB channel's
 *              corresponding pre-trigger m cannot be accepted by ADCn, and ERR[m] is set. Writing 0's to clear the sequence
 *              error flags.
 */
#define PDB_S_ERR(x)                             (((uint32_t)(((uint32_t)(x)) << PDB_S_ERR_SHIFT)) & PDB_S_ERR_MASK)

#define PDB_S_CF_MASK                            (0xFF0000U)
#define PDB_S_CF_SHIFT                           (16U)
/*! CF - PDB Channel Flags */
#define PDB_S_CF(x)                              (((uint32_t)(((uint32_t)(x)) << PDB_S_CF_SHIFT)) & PDB_S_CF_MASK)
/*! @} */

/* The count of PDB_S */
#define PDB_S_COUNT                              (2U)

/*! @name DLY - Channel n Delay 0 Register..Channel n Delay 1 Register */
/*! @{ */

#define PDB_DLY_DLY_MASK                         (0xFFFFU)
#define PDB_DLY_DLY_SHIFT                        (0U)
/*! DLY - PDB Channel Delay */
#define PDB_DLY_DLY(x)                           (((uint32_t)(((uint32_t)(x)) << PDB_DLY_DLY_SHIFT)) & PDB_DLY_DLY_MASK)
/*! @} */

/* The count of PDB_DLY */
#define PDB_DLY_COUNT                            (2U)

/* The count of PDB_DLY */
#define PDB_DLY_COUNT2                           (2U)

/*! @name INTC - DAC Interval Trigger n Control Register */
/*! @{ */

#define PDB_INTC_TOE_MASK                        (0x1U)
#define PDB_INTC_TOE_SHIFT                       (0U)
/*! TOE - DAC Interval Trigger Enable
 *  0b0..DAC interval trigger disabled.
 *  0b1..DAC interval trigger enabled.
 */
#define PDB_INTC_TOE(x)                          (((uint32_t)(((uint32_t)(x)) << PDB_INTC_TOE_SHIFT)) & PDB_INTC_TOE_MASK)

#define PDB_INTC_EXT_MASK                        (0x2U)
#define PDB_INTC_EXT_SHIFT                       (1U)
/*! EXT - DAC External Trigger Input Enable
 *  0b0..DAC external trigger input disabled. DAC interval counter is reset and started counting when a rising
 *       edge is detected on selected trigger input source or software trigger is selected and SWTRIG is written with
 *       1.
 *  0b1..DAC external trigger input enabled. DAC interval counter is bypassed and DAC external trigger input triggers the DAC interval trigger.
 */
#define PDB_INTC_EXT(x)                          (((uint32_t)(((uint32_t)(x)) << PDB_INTC_EXT_SHIFT)) & PDB_INTC_EXT_MASK)
/*! @} */

/* The count of PDB_INTC */
#define PDB_INTC_COUNT                           (1U)

/*! @name INT - DAC Interval n Register */
/*! @{ */

#define PDB_INT_INT_MASK                         (0xFFFFU)
#define PDB_INT_INT_SHIFT                        (0U)
/*! INT - DAC Interval */
#define PDB_INT_INT(x)                           (((uint32_t)(((uint32_t)(x)) << PDB_INT_INT_SHIFT)) & PDB_INT_INT_MASK)
/*! @} */

/* The count of PDB_INT */
#define PDB_INT_COUNT                            (1U)

/*! @name POEN - Pulse-Out n Enable Register */
/*! @{ */

#define PDB_POEN_POEN_MASK                       (0xFFU)
#define PDB_POEN_POEN_SHIFT                      (0U)
/*! POEN - PDB Pulse-Out Enable
 *  0b00000000..PDB Pulse-Out disabled
 *  0b00000001..PDB Pulse-Out enabled
 */
#define PDB_POEN_POEN(x)                         (((uint32_t)(((uint32_t)(x)) << PDB_POEN_POEN_SHIFT)) & PDB_POEN_POEN_MASK)
/*! @} */

/*! @name PODLY - Pulse-Out n Delay Register */
/*! @{ */

#define PDB_PODLY_DLY2_MASK                      (0xFFFFU)
#define PDB_PODLY_DLY2_SHIFT                     (0U)
/*! DLY2 - PDB Pulse-Out Delay 2 */
#define PDB_PODLY_DLY2(x)                        (((uint32_t)(((uint32_t)(x)) << PDB_PODLY_DLY2_SHIFT)) & PDB_PODLY_DLY2_MASK)

#define PDB_PODLY_DLY1_MASK                      (0xFFFF0000U)
#define PDB_PODLY_DLY1_SHIFT                     (16U)
/*! DLY1 - PDB Pulse-Out Delay 1 */
#define PDB_PODLY_DLY1(x)                        (((uint32_t)(((uint32_t)(x)) << PDB_PODLY_DLY1_SHIFT)) & PDB_PODLY_DLY1_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group PDB_Register_Masks */


/*!
 * @}
 */ /* end of group PDB_Peripheral_Access_Layer */


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


#endif  /* PDB_H_ */

