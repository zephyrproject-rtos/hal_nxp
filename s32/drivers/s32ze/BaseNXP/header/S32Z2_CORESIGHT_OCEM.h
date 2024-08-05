/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_CORESIGHT_OCEM.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_CORESIGHT_OCEM
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
#if !defined(S32Z2_CORESIGHT_OCEM_H_)  /* Check if memory map has not been already included */
#define S32Z2_CORESIGHT_OCEM_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- CORESIGHT_OCEM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CORESIGHT_OCEM_Peripheral_Access_Layer CORESIGHT_OCEM Peripheral Access Layer
 * @{
 */

/** CORESIGHT_OCEM - Register Layout Typedef */
typedef struct {
  __IO uint32_t SCCO;                              /**< SCCO Register, offset: 0x0 */
  __IO uint32_t SCDA;                              /**< SCDA Register, offset: 0x4 */
} CORESIGHT_OCEM_Type, *CORESIGHT_OCEM_MemMapPtr;

/** Number of instances of the CORESIGHT_OCEM module. */
#define CORESIGHT_OCEM_INSTANCE_COUNT            (1u)

/* CORESIGHT_OCEM - Peripheral instance base addresses */
/** Peripheral CEVA_SPF2_APB__CORESIGHT_OCEM base address */
#define IP_CEVA_SPF2_APB__CORESIGHT_OCEM_BASE    (0x4D180CFCu)
/** Peripheral CEVA_SPF2_APB__CORESIGHT_OCEM base pointer */
#define IP_CEVA_SPF2_APB__CORESIGHT_OCEM         ((CORESIGHT_OCEM_Type *)IP_CEVA_SPF2_APB__CORESIGHT_OCEM_BASE)
/** Array initializer of CORESIGHT_OCEM peripheral base addresses */
#define IP_CORESIGHT_OCEM_BASE_ADDRS             { IP_CEVA_SPF2_APB__CORESIGHT_OCEM_BASE }
/** Array initializer of CORESIGHT_OCEM peripheral base pointers */
#define IP_CORESIGHT_OCEM_BASE_PTRS              { IP_CEVA_SPF2_APB__CORESIGHT_OCEM }

/* ----------------------------------------------------------------------------
   -- CORESIGHT_OCEM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CORESIGHT_OCEM_Register_Masks CORESIGHT_OCEM Register Masks
 * @{
 */

/*! @name SCCO - SCCO Register */
/*! @{ */

#define CORESIGHT_OCEM_SCCO_SCC_MASK             (0xFFFFU)
#define CORESIGHT_OCEM_SCCO_SCC_SHIFT            (0U)
#define CORESIGHT_OCEM_SCCO_SCC_WIDTH            (16U)
#define CORESIGHT_OCEM_SCCO_SCC(x)               (((uint32_t)(((uint32_t)(x)) << CORESIGHT_OCEM_SCCO_SCC_SHIFT)) & CORESIGHT_OCEM_SCCO_SCC_MASK)

#define CORESIGHT_OCEM_SCCO_DIREC_MASK           (0x10000U)
#define CORESIGHT_OCEM_SCCO_DIREC_SHIFT          (16U)
#define CORESIGHT_OCEM_SCCO_DIREC_WIDTH          (1U)
#define CORESIGHT_OCEM_SCCO_DIREC(x)             (((uint32_t)(((uint32_t)(x)) << CORESIGHT_OCEM_SCCO_DIREC_SHIFT)) & CORESIGHT_OCEM_SCCO_DIREC_MASK)

#define CORESIGHT_OCEM_SCCO_SIZE_MASK            (0xFF000000U)
#define CORESIGHT_OCEM_SCCO_SIZE_SHIFT           (24U)
#define CORESIGHT_OCEM_SCCO_SIZE_WIDTH           (8U)
#define CORESIGHT_OCEM_SCCO_SIZE(x)              (((uint32_t)(((uint32_t)(x)) << CORESIGHT_OCEM_SCCO_SIZE_SHIFT)) & CORESIGHT_OCEM_SCCO_SIZE_MASK)
/*! @} */

/*! @name SCDA - SCDA Register */
/*! @{ */

#define CORESIGHT_OCEM_SCDA_SCD_MASK             (0xFFFFFFFFU)
#define CORESIGHT_OCEM_SCDA_SCD_SHIFT            (0U)
#define CORESIGHT_OCEM_SCDA_SCD_WIDTH            (32U)
#define CORESIGHT_OCEM_SCDA_SCD(x)               (((uint32_t)(((uint32_t)(x)) << CORESIGHT_OCEM_SCDA_SCD_SHIFT)) & CORESIGHT_OCEM_SCDA_SCD_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group CORESIGHT_OCEM_Register_Masks */

/*!
 * @}
 */ /* end of group CORESIGHT_OCEM_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_CORESIGHT_OCEM_H_) */
