/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K566_CXPI.h
 * @version 2.2
 * @date 2025-10-16
 * @brief Peripheral Access Layer for S32K566_CXPI
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
#if !defined(S32K566_CXPI_H_)  /* Check if memory map has not been already included */
#define S32K566_CXPI_H_

#include "S32K566_COMMON.h"

/* ----------------------------------------------------------------------------
   -- CXPI Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CXPI_Peripheral_Access_Layer CXPI Peripheral Access Layer
 * @{
 */

/** CXPI - Register Layout Typedef */
typedef struct CXPI_Struct {
  __IO uint32_t CTRL;                              /**< Control, offset: 0x0 */
  uint8_t RESERVED_0[12];
  __IO uint32_t INTE;                              /**< Interrupt Enable, offset: 0x10 */
  uint8_t RESERVED_1[12];
  __IO uint32_t STAT;                              /**< Status, offset: 0x20 */
} CXPI_Type, *CXPI_MemMapPtr;

/** Number of instances of the CXPI module. */
#define CXPI_INSTANCE_COUNT                      (2u)

/* CXPI - Peripheral instance base addresses */
/** Peripheral LPE_CXPI_0 base address */
#define IP_LPE_CXPI_0_BASE                       (0x4216C000u)
/** Peripheral LPE_CXPI_0 base pointer */
#define IP_LPE_CXPI_0                            ((CXPI_Type *)IP_LPE_CXPI_0_BASE)
/** Peripheral LPE_CXPI_1 base address */
#define IP_LPE_CXPI_1_BASE                       (0x42170000u)
/** Peripheral LPE_CXPI_1 base pointer */
#define IP_LPE_CXPI_1                            ((CXPI_Type *)IP_LPE_CXPI_1_BASE)
/** Array initializer of CXPI peripheral base addresses */
#define IP_CXPI_BASE_ADDRS                       { IP_LPE_CXPI_0_BASE, IP_LPE_CXPI_1_BASE }
/** Array initializer of CXPI peripheral base pointers */
#define IP_CXPI_BASE_PTRS                        { IP_LPE_CXPI_0, IP_LPE_CXPI_1 }

/* ----------------------------------------------------------------------------
   -- CXPI Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CXPI_Register_Masks CXPI Register Masks
 * @{
 */

/*! @name CTRL - Control */
/*! @{ */

#define CXPI_CTRL_MS_MASK                        (0x1U)
#define CXPI_CTRL_MS_SHIFT                       (0U)
#define CXPI_CTRL_MS_WIDTH                       (1U)
#define CXPI_CTRL_MS(x)                          (((uint32_t)(((uint32_t)(x)) << CXPI_CTRL_MS_SHIFT)) & CXPI_CTRL_MS_MASK)

#define CXPI_CTRL_NSLP_MASK                      (0x2U)
#define CXPI_CTRL_NSLP_SHIFT                     (1U)
#define CXPI_CTRL_NSLP_WIDTH                     (1U)
#define CXPI_CTRL_NSLP(x)                        (((uint32_t)(((uint32_t)(x)) << CXPI_CTRL_NSLP_SHIFT)) & CXPI_CTRL_NSLP_MASK)
/*! @} */

/*! @name INTE - Interrupt Enable */
/*! @{ */

#define CXPI_INTE_WUSMIE_MASK                    (0x1U)
#define CXPI_INTE_WUSMIE_SHIFT                   (0U)
#define CXPI_INTE_WUSMIE_WIDTH                   (1U)
#define CXPI_INTE_WUSMIE(x)                      (((uint32_t)(((uint32_t)(x)) << CXPI_INTE_WUSMIE_SHIFT)) & CXPI_INTE_WUSMIE_MASK)

#define CXPI_INTE_DTOIE_MASK                     (0x2U)
#define CXPI_INTE_DTOIE_SHIFT                    (1U)
#define CXPI_INTE_DTOIE_WIDTH                    (1U)
#define CXPI_INTE_DTOIE(x)                       (((uint32_t)(((uint32_t)(x)) << CXPI_INTE_DTOIE_SHIFT)) & CXPI_INTE_DTOIE_MASK)

#define CXPI_INTE_LOAIE_MASK                     (0x4U)
#define CXPI_INTE_LOAIE_SHIFT                    (2U)
#define CXPI_INTE_LOAIE_WIDTH                    (1U)
#define CXPI_INTE_LOAIE(x)                       (((uint32_t)(((uint32_t)(x)) << CXPI_INTE_LOAIE_SHIFT)) & CXPI_INTE_LOAIE_MASK)
/*! @} */

/*! @name STAT - Status */
/*! @{ */

#define CXPI_STAT_WUSM_MASK                      (0x1U)
#define CXPI_STAT_WUSM_SHIFT                     (0U)
#define CXPI_STAT_WUSM_WIDTH                     (1U)
#define CXPI_STAT_WUSM(x)                        (((uint32_t)(((uint32_t)(x)) << CXPI_STAT_WUSM_SHIFT)) & CXPI_STAT_WUSM_MASK)

#define CXPI_STAT_DTO_MASK                       (0x2U)
#define CXPI_STAT_DTO_SHIFT                      (1U)
#define CXPI_STAT_DTO_WIDTH                      (1U)
#define CXPI_STAT_DTO(x)                         (((uint32_t)(((uint32_t)(x)) << CXPI_STAT_DTO_SHIFT)) & CXPI_STAT_DTO_MASK)

#define CXPI_STAT_LOA_MASK                       (0x4U)
#define CXPI_STAT_LOA_SHIFT                      (2U)
#define CXPI_STAT_LOA_WIDTH                      (1U)
#define CXPI_STAT_LOA(x)                         (((uint32_t)(((uint32_t)(x)) << CXPI_STAT_LOA_SHIFT)) & CXPI_STAT_LOA_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group CXPI_Register_Masks */

/*!
 * @}
 */ /* end of group CXPI_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K566_CXPI_H_) */
