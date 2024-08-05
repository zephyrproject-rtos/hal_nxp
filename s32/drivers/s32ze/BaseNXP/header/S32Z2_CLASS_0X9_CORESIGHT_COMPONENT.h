/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_CLASS_0X9_CORESIGHT_COMPONENT.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_CLASS_0X9_CORESIGHT_COMPONENT
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
#if !defined(S32Z2_CLASS_0X9_CORESIGHT_COMPONENT_H_)  /* Check if memory map has not been already included */
#define S32Z2_CLASS_0X9_CORESIGHT_COMPONENT_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- CLASS_0X9_CORESIGHT_COMPONENT Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CLASS_0X9_CORESIGHT_COMPONENT_Peripheral_Access_Layer CLASS_0X9_CORESIGHT_COMPONENT Peripheral Access Layer
 * @{
 */

/** CLASS_0X9_CORESIGHT_COMPONENT - Register Layout Typedef */
typedef struct {
  __I  uint32_t DTIR;                              /**< DTIR Register, offset: 0x0 */
} CLASS_0X9_CORESIGHT_COMPONENT_Type, *CLASS_0X9_CORESIGHT_COMPONENT_MemMapPtr;

/** Number of instances of the CLASS_0X9_CORESIGHT_COMPONENT module. */
#define CLASS_0X9_CORESIGHT_COMPONENT_INSTANCE_COUNT (1u)

/* CLASS_0X9_CORESIGHT_COMPONENT - Peripheral instance base addresses */
/** Peripheral CEVA_SPF2_APB__CLASS_0X9_CORESIGHT_COMPONENT base address */
#define IP_CEVA_SPF2_APB__CLASS_0X9_CORESIGHT_COMPONENT_BASE (0x4D180FCCu)
/** Peripheral CEVA_SPF2_APB__CLASS_0X9_CORESIGHT_COMPONENT base pointer */
#define IP_CEVA_SPF2_APB__CLASS_0X9_CORESIGHT_COMPONENT ((CLASS_0X9_CORESIGHT_COMPONENT_Type *)IP_CEVA_SPF2_APB__CLASS_0X9_CORESIGHT_COMPONENT_BASE)
/** Array initializer of CLASS_0X9_CORESIGHT_COMPONENT peripheral base addresses
 * */
#define IP_CLASS_0X9_CORESIGHT_COMPONENT_BASE_ADDRS { IP_CEVA_SPF2_APB__CLASS_0X9_CORESIGHT_COMPONENT_BASE }
/** Array initializer of CLASS_0X9_CORESIGHT_COMPONENT peripheral base pointers
 * */
#define IP_CLASS_0X9_CORESIGHT_COMPONENT_BASE_PTRS { IP_CEVA_SPF2_APB__CLASS_0X9_CORESIGHT_COMPONENT }

/* ----------------------------------------------------------------------------
   -- CLASS_0X9_CORESIGHT_COMPONENT Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CLASS_0X9_CORESIGHT_COMPONENT_Register_Masks CLASS_0X9_CORESIGHT_COMPONENT Register Masks
 * @{
 */

/*! @name DTIR - DTIR Register */
/*! @{ */

#define CLASS_0X9_CORESIGHT_COMPONENT_DTIR_MAJ_T_MASK (0xFU)
#define CLASS_0X9_CORESIGHT_COMPONENT_DTIR_MAJ_T_SHIFT (0U)
#define CLASS_0X9_CORESIGHT_COMPONENT_DTIR_MAJ_T_WIDTH (4U)
#define CLASS_0X9_CORESIGHT_COMPONENT_DTIR_MAJ_T(x) (((uint32_t)(((uint32_t)(x)) << CLASS_0X9_CORESIGHT_COMPONENT_DTIR_MAJ_T_SHIFT)) & CLASS_0X9_CORESIGHT_COMPONENT_DTIR_MAJ_T_MASK)

#define CLASS_0X9_CORESIGHT_COMPONENT_DTIR_SUB_T_MASK (0xF0U)
#define CLASS_0X9_CORESIGHT_COMPONENT_DTIR_SUB_T_SHIFT (4U)
#define CLASS_0X9_CORESIGHT_COMPONENT_DTIR_SUB_T_WIDTH (4U)
#define CLASS_0X9_CORESIGHT_COMPONENT_DTIR_SUB_T(x) (((uint32_t)(((uint32_t)(x)) << CLASS_0X9_CORESIGHT_COMPONENT_DTIR_SUB_T_SHIFT)) & CLASS_0X9_CORESIGHT_COMPONENT_DTIR_SUB_T_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group CLASS_0X9_CORESIGHT_COMPONENT_Register_Masks */

/*!
 * @}
 */ /* end of group CLASS_0X9_CORESIGHT_COMPONENT_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_CLASS_0X9_CORESIGHT_COMPONENT_H_) */
