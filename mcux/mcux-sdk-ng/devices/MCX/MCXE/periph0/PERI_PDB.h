/*
** ###################################################################
**     Processors:          MCXE247VLL
**                          MCXE247VLQ
**
**     Version:             rev. 1.0, 2025-02-21
**     Build:               b250417
**
**     Abstract:
**         CMSIS Peripheral Access Layer for PDB
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2025-02-21)
**         Generated based on Rev1 Draft RM..
**
** ###################################################################
*/

/*!
 * @file PERI_PDB.h
 * @version 1.0
 * @date 2025-02-21
 * @brief CMSIS Peripheral Access Layer for PDB
 *
 * CMSIS Peripheral Access Layer for PDB
 */

#if !defined(PERI_PDB_H_)
#define PERI_PDB_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXE247VLL) || defined(CPU_MCXE247VLQ))
#include "MCXE247_COMMON.h"
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
   -- PDB Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PDB_Peripheral_Access_Layer PDB Peripheral Access Layer
 * @{
 */

/** PDB - Size of Registers Arrays */
#define PDB_CH_DLY_COUNT                          8u
#define PDB_CH_COUNT                              4u
#define PDB_POnDLY_COUNT                          1u

/** PDB - Register Layout Typedef */
typedef struct {
  __IO uint32_t SC;                                /**< Status and Control register, offset: 0x0 */
  __IO uint32_t MOD;                               /**< Modulus register, offset: 0x4 */
  __I  uint32_t CNT;                               /**< Counter register, offset: 0x8 */
  __IO uint32_t IDLY;                              /**< Interrupt Delay register, offset: 0xC */
  struct {                                         /* offset: 0x10, array step: 0x28 */
    __IO uint32_t C1;                                /**< Channel n Control register 1, array offset: 0x10, array step: 0x28 */
    __IO uint32_t S;                                 /**< Channel n Status register, array offset: 0x14, array step: 0x28 */
    __IO uint32_t DLY[PDB_CH_DLY_COUNT];             /**< Channel n Delay 0 register..Channel n Delay 1 register, array offset: 0x18, array step: index*0x28, index2*0x4, valid indices: [0][0-7], [1][0-7], [2][0-1], [3][0-1] */
  } CH[PDB_CH_COUNT];
       uint8_t RESERVED_0[224];
  __IO uint32_t POEN;                              /**< Pulse-Out n Enable register, offset: 0x190 */
  union {                                          /* offset: 0x194, array step: 0x4 */
    struct {                                         /* offset: 0x194, array step: 0x4 */
      __IO uint16_t PODLYL;                            /**< PDB_PODLYL register, array offset: 0x194, array step: 0x4 */
      __IO uint16_t PODLYH;                            /**< PDB_PODLYH register, array offset: 0x196, array step: 0x4 */
    } ACCESS16BIT[PDB_POnDLY_COUNT];
    __IO uint32_t PODLY[PDB_POnDLY_COUNT];           /**< Pulse-Out n Delay register, array offset: 0x194, array step: 0x4 */
  };
} PDB_Type;

/* ----------------------------------------------------------------------------
   -- PDB Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PDB_Register_Masks PDB Register Masks
 * @{
 */

/*! @name SC - Status and Control register */
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
 *  0b00..Multiplication factor is 1.
 *  0b01..Multiplication factor is 10.
 *  0b10..Multiplication factor is 20.
 *  0b11..Multiplication factor is 40.
 */
#define PDB_SC_MULT(x)                           (((uint32_t)(((uint32_t)(x)) << PDB_SC_MULT_SHIFT)) & PDB_SC_MULT_MASK)

#define PDB_SC_PDBIE_MASK                        (0x20U)
#define PDB_SC_PDBIE_SHIFT                       (5U)
/*! PDBIE - PDB Interrupt Enable
 *  0b0..PDB interrupt disabled.
 *  0b1..PDB interrupt enabled.
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
 *  0b0000..Trigger-In 0 is selected.
 *  0b0001..Trigger-In 1 is selected.
 *  0b0010..Trigger-In 2 is selected.
 *  0b0011..Trigger-In 3 is selected.
 *  0b0100..Trigger-In 4 is selected.
 *  0b0101..Trigger-In 5 is selected.
 *  0b0110..Trigger-In 6 is selected.
 *  0b0111..Trigger-In 7 is selected.
 *  0b1000..Trigger-In 8 is selected.
 *  0b1001..Trigger-In 9 is selected.
 *  0b1010..Trigger-In 10 is selected.
 *  0b1011..Trigger-In 11 is selected.
 *  0b1100..Trigger-In 12 is selected.
 *  0b1101..Trigger-In 13 is selected.
 *  0b1110..Trigger-In 14 is selected.
 *  0b1111..Software trigger is selected.
 */
#define PDB_SC_TRGSEL(x)                         (((uint32_t)(((uint32_t)(x)) << PDB_SC_TRGSEL_SHIFT)) & PDB_SC_TRGSEL_MASK)

#define PDB_SC_PRESCALER_MASK                    (0x7000U)
#define PDB_SC_PRESCALER_SHIFT                   (12U)
/*! PRESCALER - Prescaler Divider Select
 *  0b000..Counting uses the peripheral clock divided by MULT (the multiplication factor).
 *  0b001..Counting uses the peripheral clock divided by 2 x MULT (the multiplication factor).
 *  0b010..Counting uses the peripheral clock divided by 4 x MULT (the multiplication factor).
 *  0b011..Counting uses the peripheral clock divided by 8 x MULT (the multiplication factor).
 *  0b100..Counting uses the peripheral clock divided by 16 x MULT (the multiplication factor).
 *  0b101..Counting uses the peripheral clock divided by 32 x MULT (the multiplication factor).
 *  0b110..Counting uses the peripheral clock divided by 64 x MULT (the multiplication factor).
 *  0b111..Counting uses the peripheral clock divided by 128 x MULT (the multiplication factor).
 */
#define PDB_SC_PRESCALER(x)                      (((uint32_t)(((uint32_t)(x)) << PDB_SC_PRESCALER_SHIFT)) & PDB_SC_PRESCALER_MASK)

#define PDB_SC_DMAEN_MASK                        (0x8000U)
#define PDB_SC_DMAEN_SHIFT                       (15U)
/*! DMAEN - DMA Enable
 *  0b0..DMA disabled.
 *  0b1..DMA enabled.
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
 *  0b00..The internal registers are loaded with the values from their buffers, immediately after 1 is written to LDOK.
 *  0b01..The internal registers are loaded with the values from their buffers when the PDB counter (CNT) = MOD +
 *        1 CNT delay elapsed, after 1 is written to LDOK.
 *  0b10..The internal registers are loaded with the values from their buffers when a trigger input event is detected, after 1 is written to LDOK.
 *  0b11..The internal registers are loaded with the values from their buffers when either the PDB counter (CNT) =
 *        MOD + 1 CNT delay elapsed, or a trigger input event is detected, after 1 is written to LDOK.
 */
#define PDB_SC_LDMOD(x)                          (((uint32_t)(((uint32_t)(x)) << PDB_SC_LDMOD_SHIFT)) & PDB_SC_LDMOD_MASK)
/*! @} */

/*! @name MOD - Modulus register */
/*! @{ */

#define PDB_MOD_MOD_MASK                         (0xFFFFU)
#define PDB_MOD_MOD_SHIFT                        (0U)
/*! MOD - PDB Modulus */
#define PDB_MOD_MOD(x)                           (((uint32_t)(((uint32_t)(x)) << PDB_MOD_MOD_SHIFT)) & PDB_MOD_MOD_MASK)
/*! @} */

/*! @name CNT - Counter register */
/*! @{ */

#define PDB_CNT_CNT_MASK                         (0xFFFFU)
#define PDB_CNT_CNT_SHIFT                        (0U)
/*! CNT - PDB Counter */
#define PDB_CNT_CNT(x)                           (((uint32_t)(((uint32_t)(x)) << PDB_CNT_CNT_SHIFT)) & PDB_CNT_CNT_MASK)
/*! @} */

/*! @name IDLY - Interrupt Delay register */
/*! @{ */

#define PDB_IDLY_IDLY_MASK                       (0xFFFFU)
#define PDB_IDLY_IDLY_SHIFT                      (0U)
/*! IDLY - PDB Interrupt Delay */
#define PDB_IDLY_IDLY(x)                         (((uint32_t)(((uint32_t)(x)) << PDB_IDLY_IDLY_SHIFT)) & PDB_IDLY_IDLY_MASK)
/*! @} */

/*! @name C1 - Channel n Control register 1 */
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
 *              register plus one peripheral clock cycle after a rising edge is detected on selected trigger input source
 *              or software trigger is selected and SWTRIG is written with 1.
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
#define PDB_C1_COUNT                             (4U)

/*! @name S - Channel n Status register */
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
#define PDB_S_COUNT                              (4U)

/*! @name DLY - Channel n Delay 0 register..Channel n Delay 1 register */
/*! @{ */

#define PDB_DLY_DLY_MASK                         (0xFFFFU)
#define PDB_DLY_DLY_SHIFT                        (0U)
/*! DLY - PDB Channel Delay */
#define PDB_DLY_DLY(x)                           (((uint32_t)(((uint32_t)(x)) << PDB_DLY_DLY_SHIFT)) & PDB_DLY_DLY_MASK)
/*! @} */

/* The count of PDB_DLY */
#define PDB_DLY_COUNT                            (4U)

/* The count of PDB_DLY */
#define PDB_DLY_COUNT2                           (8U)

/*! @name POEN - Pulse-Out n Enable register */
/*! @{ */

#define PDB_POEN_POEN_MASK                       (0xFFU)
#define PDB_POEN_POEN_SHIFT                      (0U)
/*! POEN - PDB Pulse-Out Enable
 *  0b00000000..PDB Pulse-Out disabled
 *  0b00000001..PDB Pulse-Out enabled
 */
#define PDB_POEN_POEN(x)                         (((uint32_t)(((uint32_t)(x)) << PDB_POEN_POEN_SHIFT)) & PDB_POEN_POEN_MASK)
/*! @} */

/*! @name PODLYL - PDB_PODLYL register */
/*! @{ */

#define PDB_PODLYL_PODLYL_MASK                   (0xFFFFU)
#define PDB_PODLYL_PODLYL_SHIFT                  (0U)
#define PDB_PODLYL_PODLYL(x)                     (((uint16_t)(((uint16_t)(x)) << PDB_PODLYL_PODLYL_SHIFT)) & PDB_PODLYL_PODLYL_MASK)
/*! @} */

/* The count of PDB_PODLYL */
#define PDB_PODLYL_COUNT                         (1U)

/*! @name PODLYH - PDB_PODLYH register */
/*! @{ */

#define PDB_PODLYH_PODLYH_MASK                   (0xFFFFU)
#define PDB_PODLYH_PODLYH_SHIFT                  (0U)
#define PDB_PODLYH_PODLYH(x)                     (((uint16_t)(((uint16_t)(x)) << PDB_PODLYH_PODLYH_SHIFT)) & PDB_PODLYH_PODLYH_MASK)
/*! @} */

/* The count of PDB_PODLYH */
#define PDB_PODLYH_COUNT                         (1U)

/*! @name PODLY - Pulse-Out n Delay register */
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

/* The count of PDB_PODLY */
#define PDB_PODLY_COUNT                          (1U)


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


#endif  /* PERI_PDB_H_ */

