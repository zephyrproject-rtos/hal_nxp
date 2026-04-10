/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K39_TRGMUX_APP.h
 * @version 1.7
 * @date 2022-11-18
 * @brief Peripheral Access Layer for S32K39_TRGMUX_APP
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
#if !defined(S32K39_TRGMUX_APP_H_)  /* Check if memory map has not been already included */
#define S32K39_TRGMUX_APP_H_

#include "S32K39_COMMON.h"

/* ----------------------------------------------------------------------------
   -- TRGMUX_APP Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TRGMUX_APP_Peripheral_Access_Layer TRGMUX_APP Peripheral Access Layer
 * @{
 */

/** TRGMUX_APP - Size of Registers Arrays */
#define TRGMUX_APP_TRGMUXn_COUNT                  62u

/** TRGMUX_APP - Register Layout Typedef */
typedef struct {
  __IO uint32_t TRGMUXn[TRGMUX_APP_TRGMUXn_COUNT]; /**< TRGMUX ADC12_0 Register..TRGMUX LPI2C_0_Triggered Register, array offset: 0x0, array step: 0x4 */
} TRGMUX_APP_Type, *TRGMUX_APP_MemMapPtr;

/** Number of instances of the TRGMUX_APP module. */
#define TRGMUX_APP_INSTANCE_COUNT                (1u)

/* TRGMUX_APP - Peripheral instance base addresses */
/** Peripheral TRGMUX_APP base address */
#define IP_TRGMUX_APP_BASE                       (0x40080000u)
/** Peripheral TRGMUX_APP base pointer */
#define IP_TRGMUX_APP                            ((TRGMUX_APP_Type *)IP_TRGMUX_APP_BASE)
/** Array initializer of TRGMUX_APP peripheral base addresses */
#define IP_TRGMUX_APP_BASE_ADDRS                 { IP_TRGMUX_APP_BASE }
/** Array initializer of TRGMUX_APP peripheral base pointers */
#define IP_TRGMUX_APP_BASE_PTRS                  { IP_TRGMUX_APP }

/* ----------------------------------------------------------------------------
   -- TRGMUX_APP Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TRGMUX_APP_Register_Masks TRGMUX_APP Register Masks
 * @{
 */

/*! @name TRGMUXn - TRGMUX ADC12_0 Register..TRGMUX LPI2C_0_Triggered Register */
/*! @{ */

#define TRGMUX_APP_TRGMUXn_SEL0_MASK             (0x7FU)
#define TRGMUX_APP_TRGMUXn_SEL0_SHIFT            (0U)
#define TRGMUX_APP_TRGMUXn_SEL0_WIDTH            (7U)
#define TRGMUX_APP_TRGMUXn_SEL0(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_APP_TRGMUXn_SEL0_SHIFT)) & TRGMUX_APP_TRGMUXn_SEL0_MASK)

#define TRGMUX_APP_TRGMUXn_SEL1_MASK             (0x7F00U)
#define TRGMUX_APP_TRGMUXn_SEL1_SHIFT            (8U)
#define TRGMUX_APP_TRGMUXn_SEL1_WIDTH            (7U)
#define TRGMUX_APP_TRGMUXn_SEL1(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_APP_TRGMUXn_SEL1_SHIFT)) & TRGMUX_APP_TRGMUXn_SEL1_MASK)

#define TRGMUX_APP_TRGMUXn_SEL2_MASK             (0x7F0000U)
#define TRGMUX_APP_TRGMUXn_SEL2_SHIFT            (16U)
#define TRGMUX_APP_TRGMUXn_SEL2_WIDTH            (7U)
#define TRGMUX_APP_TRGMUXn_SEL2(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_APP_TRGMUXn_SEL2_SHIFT)) & TRGMUX_APP_TRGMUXn_SEL2_MASK)

#define TRGMUX_APP_TRGMUXn_SEL3_MASK             (0x7F000000U)
#define TRGMUX_APP_TRGMUXn_SEL3_SHIFT            (24U)
#define TRGMUX_APP_TRGMUXn_SEL3_WIDTH            (7U)
#define TRGMUX_APP_TRGMUXn_SEL3(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_APP_TRGMUXn_SEL3_SHIFT)) & TRGMUX_APP_TRGMUXn_SEL3_MASK)

#define TRGMUX_APP_TRGMUXn_LK_MASK               (0x80000000U)
#define TRGMUX_APP_TRGMUXn_LK_SHIFT              (31U)
#define TRGMUX_APP_TRGMUXn_LK_WIDTH              (1U)
#define TRGMUX_APP_TRGMUXn_LK(x)                 (((uint32_t)(((uint32_t)(x)) << TRGMUX_APP_TRGMUXn_LK_SHIFT)) & TRGMUX_APP_TRGMUXn_LK_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group TRGMUX_APP_Register_Masks */
#define TRGMUX_ADC12_0_INDEX 0
#define TRGMUX_ADC12_1_INDEX 1
#define TRGMUX_ADC12_2_INDEX 2
#define TRGMUX_ADC12_3_INDEX 3
#define TRGMUX_ADC12_4_INDEX 4
#define TRGMUX_ADC12_5_INDEX 5
#define TRGMUX_ADC12_6_INDEX 6
#define TRGMUX_SD_0_INDEX 7
#define TRGMUX_SD_1_INDEX 8
#define TRGMUX_SD_2_INDEX 9
#define TRGMUX_SD_3_INDEX 10
#define TRGMUX_LPCMP_0_INDEX 11
#define TRGMUX_LPCMP_1_INDEX 12
#define TRGMUX_BCTU_0_INDEX 13
#define TRGMUX_BCTU_1_INDEX 14
#define TRGMUX_SWG_0_INDEX 15
#define TRGMUX_SWG_1_INDEX 16
#define TRGMUX_eMIOS012_ODIS_INDEX 17
#define TRGMUX_eMIOS0_ipp_0_INDEX 18
#define TRGMUX_eMIOS0_ipp_1_INDEX 19
#define TRGMUX_eMIOS0_ipp_2_INDEX 20
#define TRGMUX_eMIOS0_ipp_3_INDEX 21
#define TRGMUX_eTPU_A_input_INDEX 22
#define TRGMUX_eTPU_AB_input_INDEX 23
#define TRGMUX_eTPU_B_input_INDEX 24
#define TRGMUX_PWM0_fault_INDEX 25
#define TRGMUX_PWM1_fault_INDEX 26
#define TRGMUX_PWM_EXT_SYNC_INDEX 27
#define TRGMUX_PWM_EXT_AB_0_INDEX 28
#define TRGMUX_PWM_EXT_AB_1_INDEX 29
#define TRGMUX_PWM_EXT_CLK_FORCE_INDEX 30
#define TRGMUX_FlexIO_INDEX 31
#define TRGMUX_SIUL_OUT_0_INDEX 32
#define TRGMUX_SIUL_OUT_1_INDEX 33
#define TRGMUX_SIUL_OUT_2_INDEX 34
#define TRGMUX_SIUL_OUT_3_INDEX 35
#define TRGMUX_LPSPI_0_INDEX 36
#define TRGMUX_LPSPI_1_INDEX 37
#define TRGMUX_LPSPI_2_INDEX 38
#define TRGMUX_LPUART_0_INDEX 39
#define TRGMUX_LPUART_1_INDEX 40
#define TRGMUX_LPUART_2_INDEX 41
#define TRGMUX_LPUART_3_INDEX 42
#define TRGMUX_DSPI_MSC_INDEX 43
#define TRGMUX_LCU0_sync_INDEX 44
#define TRGMUX_LCU0_force_INDEX 45
#define TRGMUX_LCU0_0_INDEX 46
#define TRGMUX_LCU0_1_INDEX 47
#define TRGMUX_LCU0_2_INDEX 48
#define TRGMUX_LCU1_sync_INDEX 49
#define TRGMUX_LCU1_force_INDEX 50
#define TRGMUX_LCU1_0_INDEX 51
#define TRGMUX_LCU1_1_INDEX 52
#define TRGMUX_LCU1_2_INDEX 53
#define TRGMUX_TRGMUX_MSC_OUT_0_INDEX 54
#define TRGMUX_TRGMUX_MSC_OUT_1_INDEX 55
#define TRGMUX_TRGMUX_MSC_OUT_2_INDEX 56
#define TRGMUX_COOLFLUX_OUT_INDEX 57
#define TRGMUX_CM7_RXEV_INDEX 58
#define TRGMUX_eTPU1_odis_INDEX 59
#define TRGMUX_eTPU2_odis_INDEX 60
#define TRGMUX_LPI2C_0_Triggered_INDEX 61


/*!
 * @}
 */ /* end of group TRGMUX_APP_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K39_TRGMUX_APP_H_) */
