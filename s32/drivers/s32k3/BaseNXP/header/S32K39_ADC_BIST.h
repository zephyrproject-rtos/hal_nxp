/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K39_ADC_BIST.h
 * @version 1.7
 * @date 2022-11-18
 * @brief Peripheral Access Layer for S32K39_ADC_BIST
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
#if !defined(S32K39_ADC_BIST_H_)  /* Check if memory map has not been already included */
#define S32K39_ADC_BIST_H_

#include "S32K39_COMMON.h"

/* ----------------------------------------------------------------------------
   -- ADC_BIST Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ADC_BIST_Peripheral_Access_Layer ADC_BIST Peripheral Access Layer
 * @{
 */

/** ADC_BIST - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< Version ID, offset: 0x0 */
  __IO uint32_t BISTCFG;                           /**< ADCBIST Configuration, offset: 0x4 */
  __IO uint32_t BISTCTL;                           /**< ADCBIST Control, offset: 0x8 */
  __I  uint32_t BISTSTAT;                          /**< ADCBIST Status, offset: 0xC */
  uint8_t RESERVED_0[496];
  __IO uint32_t SDCFG;                             /**< SDADC Test Configuration, offset: 0x200 */
  __IO uint32_t SDSINECFG;                         /**< SDADC Sine Wave Configuration, offset: 0x204 */
  uint8_t RESERVED_1[1528];
  __IO uint32_t FIRF;                              /**< Finite Impulse Response Filter, offset: 0x800 */
} ADC_BIST_Type, *ADC_BIST_MemMapPtr;

/** Number of instances of the ADC_BIST module. */
#define ADC_BIST_INSTANCE_COUNT                  (1u)

/* ADC_BIST - Peripheral instance base addresses */
/** Peripheral ADC_BIST base address */
#define IP_ADC_BIST_BASE                         (0x40704000u)
/** Peripheral ADC_BIST base pointer */
#define IP_ADC_BIST                              ((ADC_BIST_Type *)IP_ADC_BIST_BASE)
/** Array initializer of ADC_BIST peripheral base addresses */
#define IP_ADC_BIST_BASE_ADDRS                   { IP_ADC_BIST_BASE }
/** Array initializer of ADC_BIST peripheral base pointers */
#define IP_ADC_BIST_BASE_PTRS                    { IP_ADC_BIST }

/* ----------------------------------------------------------------------------
   -- ADC_BIST Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ADC_BIST_Register_Masks ADC_BIST Register Masks
 * @{
 */

/*! @name VERID - Version ID */
/*! @{ */

#define ADC_BIST_VERID_NUMSDADC_MASK             (0xF0U)
#define ADC_BIST_VERID_NUMSDADC_SHIFT            (4U)
#define ADC_BIST_VERID_NUMSDADC_WIDTH            (4U)
#define ADC_BIST_VERID_NUMSDADC(x)               (((uint32_t)(((uint32_t)(x)) << ADC_BIST_VERID_NUMSDADC_SHIFT)) & ADC_BIST_VERID_NUMSDADC_MASK)

#define ADC_BIST_VERID_MINOR_MASK                (0xFF0000U)
#define ADC_BIST_VERID_MINOR_SHIFT               (16U)
#define ADC_BIST_VERID_MINOR_WIDTH               (8U)
#define ADC_BIST_VERID_MINOR(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_BIST_VERID_MINOR_SHIFT)) & ADC_BIST_VERID_MINOR_MASK)

#define ADC_BIST_VERID_MAJOR_MASK                (0xFF000000U)
#define ADC_BIST_VERID_MAJOR_SHIFT               (24U)
#define ADC_BIST_VERID_MAJOR_WIDTH               (8U)
#define ADC_BIST_VERID_MAJOR(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_BIST_VERID_MAJOR_SHIFT)) & ADC_BIST_VERID_MAJOR_MASK)
/*! @} */

/*! @name BISTCFG - ADCBIST Configuration */
/*! @{ */

#define ADC_BIST_BISTCFG_ADCBISTEN_MASK          (0x1U)
#define ADC_BIST_BISTCFG_ADCBISTEN_SHIFT         (0U)
#define ADC_BIST_BISTCFG_ADCBISTEN_WIDTH         (1U)
#define ADC_BIST_BISTCFG_ADCBISTEN(x)            (((uint32_t)(((uint32_t)(x)) << ADC_BIST_BISTCFG_ADCBISTEN_SHIFT)) & ADC_BIST_BISTCFG_ADCBISTEN_MASK)

#define ADC_BIST_BISTCFG_TESTSEL_MASK            (0x6U)
#define ADC_BIST_BISTCFG_TESTSEL_SHIFT           (1U)
#define ADC_BIST_BISTCFG_TESTSEL_WIDTH           (2U)
#define ADC_BIST_BISTCFG_TESTSEL(x)              (((uint32_t)(((uint32_t)(x)) << ADC_BIST_BISTCFG_TESTSEL_SHIFT)) & ADC_BIST_BISTCFG_TESTSEL_MASK)
/*! @} */

/*! @name BISTCTL - ADCBIST Control */
/*! @{ */

#define ADC_BIST_BISTCTL_TESTRUN_MASK            (0x1U)
#define ADC_BIST_BISTCTL_TESTRUN_SHIFT           (0U)
#define ADC_BIST_BISTCTL_TESTRUN_WIDTH           (1U)
#define ADC_BIST_BISTCTL_TESTRUN(x)              (((uint32_t)(((uint32_t)(x)) << ADC_BIST_BISTCTL_TESTRUN_SHIFT)) & ADC_BIST_BISTCTL_TESTRUN_MASK)

#define ADC_BIST_BISTCTL_CLEAR_MASK              (0x2U)
#define ADC_BIST_BISTCTL_CLEAR_SHIFT             (1U)
#define ADC_BIST_BISTCTL_CLEAR_WIDTH             (1U)
#define ADC_BIST_BISTCTL_CLEAR(x)                (((uint32_t)(((uint32_t)(x)) << ADC_BIST_BISTCTL_CLEAR_SHIFT)) & ADC_BIST_BISTCTL_CLEAR_MASK)

#define ADC_BIST_BISTCTL_STOPSD_MASK             (0x4U)
#define ADC_BIST_BISTCTL_STOPSD_SHIFT            (2U)
#define ADC_BIST_BISTCTL_STOPSD_WIDTH            (1U)
#define ADC_BIST_BISTCTL_STOPSD(x)               (((uint32_t)(((uint32_t)(x)) << ADC_BIST_BISTCTL_STOPSD_SHIFT)) & ADC_BIST_BISTCTL_STOPSD_MASK)
/*! @} */

/*! @name BISTSTAT - ADCBIST Status */
/*! @{ */

#define ADC_BIST_BISTSTAT_SDSUM_MASK             (0x30000U)
#define ADC_BIST_BISTSTAT_SDSUM_SHIFT            (16U)
#define ADC_BIST_BISTSTAT_SDSUM_WIDTH            (2U)
#define ADC_BIST_BISTSTAT_SDSUM(x)               (((uint32_t)(((uint32_t)(x)) << ADC_BIST_BISTSTAT_SDSUM_SHIFT)) & ADC_BIST_BISTSTAT_SDSUM_MASK)
/*! @} */

/*! @name SDCFG - SDADC Test Configuration */
/*! @{ */

#define ADC_BIST_SDCFG_SDSEL_MASK                (0xFU)
#define ADC_BIST_SDCFG_SDSEL_SHIFT               (0U)
#define ADC_BIST_SDCFG_SDSEL_WIDTH               (4U)
#define ADC_BIST_SDCFG_SDSEL(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_BIST_SDCFG_SDSEL_SHIFT)) & ADC_BIST_SDCFG_SDSEL_MASK)

#define ADC_BIST_SDCFG_DACSR_MASK                (0xFF0000U)
#define ADC_BIST_SDCFG_DACSR_SHIFT               (16U)
#define ADC_BIST_SDCFG_DACSR_WIDTH               (8U)
#define ADC_BIST_SDCFG_DACSR(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_BIST_SDCFG_DACSR_SHIFT)) & ADC_BIST_SDCFG_DACSR_MASK)
/*! @} */

/*! @name SDSINECFG - SDADC Sine Wave Configuration */
/*! @{ */

#define ADC_BIST_SDSINECFG_SINESTEP_MASK         (0xFFFFFFFFU)
#define ADC_BIST_SDSINECFG_SINESTEP_SHIFT        (0U)
#define ADC_BIST_SDSINECFG_SINESTEP_WIDTH        (32U)
#define ADC_BIST_SDSINECFG_SINESTEP(x)           (((uint32_t)(((uint32_t)(x)) << ADC_BIST_SDSINECFG_SINESTEP_SHIFT)) & ADC_BIST_SDSINECFG_SINESTEP_MASK)
/*! @} */

/*! @name FIRF - Finite Impulse Response Filter */
/*! @{ */

#define ADC_BIST_FIRF_PLACEHOLDER_MASK           (0xFFFFFFFFU)
#define ADC_BIST_FIRF_PLACEHOLDER_SHIFT          (0U)
#define ADC_BIST_FIRF_PLACEHOLDER_WIDTH          (32U)
#define ADC_BIST_FIRF_PLACEHOLDER(x)             (((uint32_t)(((uint32_t)(x)) << ADC_BIST_FIRF_PLACEHOLDER_SHIFT)) & ADC_BIST_FIRF_PLACEHOLDER_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group ADC_BIST_Register_Masks */

/*!
 * @}
 */ /* end of group ADC_BIST_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K39_ADC_BIST_H_) */
