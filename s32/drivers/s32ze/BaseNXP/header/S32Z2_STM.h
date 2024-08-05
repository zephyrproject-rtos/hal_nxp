/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_STM.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_STM
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
#if !defined(S32Z2_STM_H_)  /* Check if memory map has not been already included */
#define S32Z2_STM_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- STM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup STM_Peripheral_Access_Layer STM Peripheral Access Layer
 * @{
 */

/** STM - Size of Registers Arrays */
#define STM_CHANNEL_COUNT                         4u

/** STM - Register Layout Typedef */
typedef struct {
  __IO uint32_t CR;                                /**< Control, offset: 0x0 */
  __IO uint32_t CNT;                               /**< Count, offset: 0x4 */
  uint8_t RESERVED_0[8];
  struct STM_CHANNEL {                             /* offset: 0x10, array step: 0x10 */
    __IO uint32_t CCR;                               /**< Channel Control, array offset: 0x10, array step: 0x10 */
    __IO uint32_t CIR;                               /**< Channel Interrupt, array offset: 0x14, array step: 0x10 */
    __IO uint32_t CMP;                               /**< Channel Compare, array offset: 0x18, array step: 0x10 */
    uint8_t RESERVED_0[4];
  } CHANNEL[STM_CHANNEL_COUNT];
} STM_Type, *STM_MemMapPtr;

/** Number of instances of the STM module. */
#define STM_INSTANCE_COUNT                       (13u)

/* STM - Peripheral instance base addresses */
/** Peripheral CE_STM_0 base address */
#define IP_CE_STM_0_BASE                         (0x44820000u)
/** Peripheral CE_STM_0 base pointer */
#define IP_CE_STM_0                              ((STM_Type *)IP_CE_STM_0_BASE)
/** Peripheral CE_STM_1 base address */
#define IP_CE_STM_1_BASE                         (0x44A20000u)
/** Peripheral CE_STM_1 base pointer */
#define IP_CE_STM_1                              ((STM_Type *)IP_CE_STM_1_BASE)
/** Peripheral CE_STM_2 base address */
#define IP_CE_STM_2_BASE                         (0x44A40000u)
/** Peripheral CE_STM_2 base pointer */
#define IP_CE_STM_2                              ((STM_Type *)IP_CE_STM_2_BASE)
/** Peripheral RTU0__STM_0 base address */
#define IP_RTU0__STM_0_BASE                      (0x76200000u)
/** Peripheral RTU0__STM_0 base pointer */
#define IP_RTU0__STM_0                           ((STM_Type *)IP_RTU0__STM_0_BASE)
/** Peripheral RTU0__STM_1 base address */
#define IP_RTU0__STM_1_BASE                      (0x76210000u)
/** Peripheral RTU0__STM_1 base pointer */
#define IP_RTU0__STM_1                           ((STM_Type *)IP_RTU0__STM_1_BASE)
/** Peripheral RTU0__STM_2 base address */
#define IP_RTU0__STM_2_BASE                      (0x76020000u)
/** Peripheral RTU0__STM_2 base pointer */
#define IP_RTU0__STM_2                           ((STM_Type *)IP_RTU0__STM_2_BASE)
/** Peripheral RTU0__STM_3 base address */
#define IP_RTU0__STM_3_BASE                      (0x76030000u)
/** Peripheral RTU0__STM_3 base pointer */
#define IP_RTU0__STM_3                           ((STM_Type *)IP_RTU0__STM_3_BASE)
/** Peripheral RTU1__STM_0 base address */
#define IP_RTU1__STM_0_BASE                      (0x76A00000u)
/** Peripheral RTU1__STM_0 base pointer */
#define IP_RTU1__STM_0                           ((STM_Type *)IP_RTU1__STM_0_BASE)
/** Peripheral RTU1__STM_1 base address */
#define IP_RTU1__STM_1_BASE                      (0x76A10000u)
/** Peripheral RTU1__STM_1 base pointer */
#define IP_RTU1__STM_1                           ((STM_Type *)IP_RTU1__STM_1_BASE)
/** Peripheral RTU1__STM_2 base address */
#define IP_RTU1__STM_2_BASE                      (0x76820000u)
/** Peripheral RTU1__STM_2 base pointer */
#define IP_RTU1__STM_2                           ((STM_Type *)IP_RTU1__STM_2_BASE)
/** Peripheral RTU1__STM_3 base address */
#define IP_RTU1__STM_3_BASE                      (0x76830000u)
/** Peripheral RTU1__STM_3 base pointer */
#define IP_RTU1__STM_3                           ((STM_Type *)IP_RTU1__STM_3_BASE)
/** Peripheral SMU__STM_0 base address */
#define IP_SMU__STM_0_BASE                       (0x45020000u)
/** Peripheral SMU__STM_0 base pointer */
#define IP_SMU__STM_0                            ((STM_Type *)IP_SMU__STM_0_BASE)
/** Peripheral SMU__STM_2 base address */
#define IP_SMU__STM_2_BASE                       (0x45240000u)
/** Peripheral SMU__STM_2 base pointer */
#define IP_SMU__STM_2                            ((STM_Type *)IP_SMU__STM_2_BASE)
/** Array initializer of STM peripheral base addresses */
#define IP_STM_BASE_ADDRS                        { IP_CE_STM_0_BASE, IP_CE_STM_1_BASE, IP_CE_STM_2_BASE, IP_RTU0__STM_0_BASE, IP_RTU0__STM_1_BASE, IP_RTU0__STM_2_BASE, IP_RTU0__STM_3_BASE, IP_RTU1__STM_0_BASE, IP_RTU1__STM_1_BASE, IP_RTU1__STM_2_BASE, IP_RTU1__STM_3_BASE, IP_SMU__STM_0_BASE, IP_SMU__STM_2_BASE }
/** Array initializer of STM peripheral base pointers */
#define IP_STM_BASE_PTRS                         { IP_CE_STM_0, IP_CE_STM_1, IP_CE_STM_2, IP_RTU0__STM_0, IP_RTU0__STM_1, IP_RTU0__STM_2, IP_RTU0__STM_3, IP_RTU1__STM_0, IP_RTU1__STM_1, IP_RTU1__STM_2, IP_RTU1__STM_3, IP_SMU__STM_0, IP_SMU__STM_2 }

/* ----------------------------------------------------------------------------
   -- STM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup STM_Register_Masks STM Register Masks
 * @{
 */

/*! @name CR - Control */
/*! @{ */

#define STM_CR_TEN_MASK                          (0x1U)
#define STM_CR_TEN_SHIFT                         (0U)
#define STM_CR_TEN_WIDTH                         (1U)
#define STM_CR_TEN(x)                            (((uint32_t)(((uint32_t)(x)) << STM_CR_TEN_SHIFT)) & STM_CR_TEN_MASK)

#define STM_CR_FRZ_MASK                          (0x2U)
#define STM_CR_FRZ_SHIFT                         (1U)
#define STM_CR_FRZ_WIDTH                         (1U)
#define STM_CR_FRZ(x)                            (((uint32_t)(((uint32_t)(x)) << STM_CR_FRZ_SHIFT)) & STM_CR_FRZ_MASK)

#define STM_CR_CPS_MASK                          (0xFF00U)
#define STM_CR_CPS_SHIFT                         (8U)
#define STM_CR_CPS_WIDTH                         (8U)
#define STM_CR_CPS(x)                            (((uint32_t)(((uint32_t)(x)) << STM_CR_CPS_SHIFT)) & STM_CR_CPS_MASK)
/*! @} */

/*! @name CNT - Count */
/*! @{ */

#define STM_CNT_CNT_MASK                         (0xFFFFFFFFU)
#define STM_CNT_CNT_SHIFT                        (0U)
#define STM_CNT_CNT_WIDTH                        (32U)
#define STM_CNT_CNT(x)                           (((uint32_t)(((uint32_t)(x)) << STM_CNT_CNT_SHIFT)) & STM_CNT_CNT_MASK)
/*! @} */

/*! @name CCR - Channel Control */
/*! @{ */

#define STM_CCR_CEN_MASK                         (0x1U)
#define STM_CCR_CEN_SHIFT                        (0U)
#define STM_CCR_CEN_WIDTH                        (1U)
#define STM_CCR_CEN(x)                           (((uint32_t)(((uint32_t)(x)) << STM_CCR_CEN_SHIFT)) & STM_CCR_CEN_MASK)
/*! @} */

/*! @name CIR - Channel Interrupt */
/*! @{ */

#define STM_CIR_CIF_MASK                         (0x1U)
#define STM_CIR_CIF_SHIFT                        (0U)
#define STM_CIR_CIF_WIDTH                        (1U)
#define STM_CIR_CIF(x)                           (((uint32_t)(((uint32_t)(x)) << STM_CIR_CIF_SHIFT)) & STM_CIR_CIF_MASK)
/*! @} */

/*! @name CMP - Channel Compare */
/*! @{ */

#define STM_CMP_CMP_MASK                         (0xFFFFFFFFU)
#define STM_CMP_CMP_SHIFT                        (0U)
#define STM_CMP_CMP_WIDTH                        (32U)
#define STM_CMP_CMP(x)                           (((uint32_t)(((uint32_t)(x)) << STM_CMP_CMP_SHIFT)) & STM_CMP_CMP_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group STM_Register_Masks */

/*!
 * @}
 */ /* end of group STM_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_STM_H_) */
