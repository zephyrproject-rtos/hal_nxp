/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K39_TRGMUX_MSC.h
 * @version 1.7
 * @date 2022-11-18
 * @brief Peripheral Access Layer for S32K39_TRGMUX_MSC
 *
 * This file contains register definitions and macros for easy access to their
 * bit fields.
 *
 * This file assumes LITTLE endian system.
 */

/**
* @page misra_violations MISRA-C:2012 violations
*
* @section [global]
* Violates MISRA 2012 Advisory Rule 2.3, local typedef not referenced
* The SoC header defines typedef for all modules.
*
* @section [global]
* Violates MISRA 2012 Advisory Rule 2.5, local macro not referenced
* The SoC header defines macros for all modules and registers.
*
* @section [global]
* Violates MISRA 2012 Advisory Directive 4.9, Function-like macro
* These are generated macros used for accessing the bit-fields from registers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.1, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.2, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.4, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.5, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 21.1, defined macro '__I' is reserved to the compiler
* This type qualifier is needed to ensure correct I/O access and addressing.
*/

/* Prevention from multiple including the same memory map */
#if !defined(S32K39_TRGMUX_MSC_H_)  /* Check if memory map has not been already included */
#define S32K39_TRGMUX_MSC_H_

#include "S32K39_COMMON.h"

/* ----------------------------------------------------------------------------
   -- TRGMUX_MSC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TRGMUX_MSC_Peripheral_Access_Layer TRGMUX_MSC Peripheral Access Layer
 * @{
 */

/** TRGMUX_MSC - Size of Registers Arrays */
#define TRGMUX_MSC_TRGMUXn_COUNT                  19u

/** TRGMUX_MSC - Register Layout Typedef */
typedef struct {
  __IO uint32_t TRGMUXn[TRGMUX_MSC_TRGMUXn_COUNT]; /**< TRGMUX DSPI_MSC_Input_0 Register..TRGMUX TRGMUX_APP_TRGMUX_OUT_2 Register, array offset: 0x0, array step: 0x4 */
} TRGMUX_MSC_Type, *TRGMUX_MSC_MemMapPtr;

/** Number of instances of the TRGMUX_MSC module. */
#define TRGMUX_MSC_INSTANCE_COUNT                (1u)

/* TRGMUX_MSC - Peripheral instance base addresses */
/** Peripheral TRGMUX_MSC base address */
#define IP_TRGMUX_MSC_BASE                       (0x406C0000u)
/** Peripheral TRGMUX_MSC base pointer */
#define IP_TRGMUX_MSC                            ((TRGMUX_MSC_Type *)IP_TRGMUX_MSC_BASE)
/** Array initializer of TRGMUX_MSC peripheral base addresses */
#define IP_TRGMUX_MSC_BASE_ADDRS                 { IP_TRGMUX_MSC_BASE }
/** Array initializer of TRGMUX_MSC peripheral base pointers */
#define IP_TRGMUX_MSC_BASE_PTRS                  { IP_TRGMUX_MSC }

/* ----------------------------------------------------------------------------
   -- TRGMUX_MSC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TRGMUX_MSC_Register_Masks TRGMUX_MSC Register Masks
 * @{
 */

/*! @name TRGMUXn - TRGMUX DSPI_MSC_Input_0 Register..TRGMUX TRGMUX_APP_TRGMUX_OUT_2 Register */
/*! @{ */

#define TRGMUX_MSC_TRGMUXn_SEL0_MASK             (0x7FU)
#define TRGMUX_MSC_TRGMUXn_SEL0_SHIFT            (0U)
#define TRGMUX_MSC_TRGMUXn_SEL0_WIDTH            (7U)
#define TRGMUX_MSC_TRGMUXn_SEL0(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_MSC_TRGMUXn_SEL0_SHIFT)) & TRGMUX_MSC_TRGMUXn_SEL0_MASK)

#define TRGMUX_MSC_TRGMUXn_SEL1_MASK             (0x7F00U)
#define TRGMUX_MSC_TRGMUXn_SEL1_SHIFT            (8U)
#define TRGMUX_MSC_TRGMUXn_SEL1_WIDTH            (7U)
#define TRGMUX_MSC_TRGMUXn_SEL1(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_MSC_TRGMUXn_SEL1_SHIFT)) & TRGMUX_MSC_TRGMUXn_SEL1_MASK)

#define TRGMUX_MSC_TRGMUXn_SEL2_MASK             (0x7F0000U)
#define TRGMUX_MSC_TRGMUXn_SEL2_SHIFT            (16U)
#define TRGMUX_MSC_TRGMUXn_SEL2_WIDTH            (7U)
#define TRGMUX_MSC_TRGMUXn_SEL2(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_MSC_TRGMUXn_SEL2_SHIFT)) & TRGMUX_MSC_TRGMUXn_SEL2_MASK)

#define TRGMUX_MSC_TRGMUXn_SEL3_MASK             (0x7F000000U)
#define TRGMUX_MSC_TRGMUXn_SEL3_SHIFT            (24U)
#define TRGMUX_MSC_TRGMUXn_SEL3_WIDTH            (7U)
#define TRGMUX_MSC_TRGMUXn_SEL3(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_MSC_TRGMUXn_SEL3_SHIFT)) & TRGMUX_MSC_TRGMUXn_SEL3_MASK)

#define TRGMUX_MSC_TRGMUXn_LK_MASK               (0x80000000U)
#define TRGMUX_MSC_TRGMUXn_LK_SHIFT              (31U)
#define TRGMUX_MSC_TRGMUXn_LK_WIDTH              (1U)
#define TRGMUX_MSC_TRGMUXn_LK(x)                 (((uint32_t)(((uint32_t)(x)) << TRGMUX_MSC_TRGMUXn_LK_SHIFT)) & TRGMUX_MSC_TRGMUXn_LK_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group TRGMUX_MSC_Register_Masks */
#define TRGMUX_DSPI_MSC_Input_0_INDEX 0
#define TRGMUX_DSPI_MSC_Input_1_INDEX 1
#define TRGMUX_DSPI_MSC_Input_2_INDEX 2
#define TRGMUX_DSPI_MSC_Input_3_INDEX 3
#define TRGMUX_DSPI_MSC_Input_4_INDEX 4
#define TRGMUX_DSPI_MSC_Input_5_INDEX 5
#define TRGMUX_DSPI_MSC_Input_6_INDEX 6
#define TRGMUX_DSPI_MSC_Input_7_INDEX 7
#define TRGMUX_DSPI_MSC_Input_8_INDEX 8
#define TRGMUX_DSPI_MSC_Input_9_INDEX 9
#define TRGMUX_DSPI_MSC_Input_10_INDEX 10
#define TRGMUX_DSPI_MSC_Input_11_INDEX 11
#define TRGMUX_DSPI_MSC_Input_12_INDEX 12
#define TRGMUX_DSPI_MSC_Input_13_INDEX 13
#define TRGMUX_DSPI_MSC_Input_14_INDEX 14
#define TRGMUX_DSPI_MSC_Input_15_INDEX 15
#define TRGMUX_TRGMUX_APP_TRGMUX_OUT_0_INDEX 16
#define TRGMUX_TRGMUX_APP_TRGMUX_OUT_1_INDEX 17
#define TRGMUX_TRGMUX_APP_TRGMUX_OUT_2_INDEX 18


/*!
 * @}
 */ /* end of group TRGMUX_MSC_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K39_TRGMUX_MSC_H_) */
