/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_CAN_TBS.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_CAN_TBS
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
#if !defined(S32Z2_CAN_TBS_H_)  /* Check if memory map has not been already included */
#define S32Z2_CAN_TBS_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- CAN_TBS Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CAN_TBS_Peripheral_Access_Layer CAN_TBS Peripheral Access Layer
 * @{
 */

/** CAN_TBS - Register Layout Typedef */
typedef struct {
  __I  uint32_t CAN_TB_VALUE;                      /**< CAN Time Base Output Value, offset: 0x0 */
  uint8_t RESERVED_0[2044];
  __IO uint32_t CAN_TS_SEL;                        /**< CAN Timestamp Mux Selector, offset: 0x800 */
} CAN_TBS_Type, *CAN_TBS_MemMapPtr;

/** Number of instances of the CAN_TBS module. */
#define CAN_TBS_INSTANCE_COUNT                   (26u)

/* CAN_TBS - Peripheral instance base addresses */
/** Peripheral CANXL_0_TBS base address */
#define IP_CANXL_0_TBS_BASE                      (0x419B0000u)
/** Peripheral CANXL_0_TBS base pointer */
#define IP_CANXL_0_TBS                           ((CAN_TBS_Type *)IP_CANXL_0_TBS_BASE)
/** Peripheral CANXL_1_TBS base address */
#define IP_CANXL_1_TBS_BASE                      (0x419C0000u)
/** Peripheral CANXL_1_TBS base pointer */
#define IP_CANXL_1_TBS                           ((CAN_TBS_Type *)IP_CANXL_1_TBS_BASE)
/** Peripheral CE_CAN_TBS_0 base address */
#define IP_CE_CAN_TBS_0_BASE                     (0x449A8000u)
/** Peripheral CE_CAN_TBS_0 base pointer */
#define IP_CE_CAN_TBS_0                          ((CAN_TBS_Type *)IP_CE_CAN_TBS_0_BASE)
/** Peripheral CE_CAN_TBS_1 base address */
#define IP_CE_CAN_TBS_1_BASE                     (0x449B8000u)
/** Peripheral CE_CAN_TBS_1 base pointer */
#define IP_CE_CAN_TBS_1                          ((CAN_TBS_Type *)IP_CE_CAN_TBS_1_BASE)
/** Peripheral CE_CAN_TBS_2 base address */
#define IP_CE_CAN_TBS_2_BASE                     (0x449C8000u)
/** Peripheral CE_CAN_TBS_2 base pointer */
#define IP_CE_CAN_TBS_2                          ((CAN_TBS_Type *)IP_CE_CAN_TBS_2_BASE)
/** Peripheral CE_CAN_TBS_3 base address */
#define IP_CE_CAN_TBS_3_BASE                     (0x449D8000u)
/** Peripheral CE_CAN_TBS_3 base pointer */
#define IP_CE_CAN_TBS_3                          ((CAN_TBS_Type *)IP_CE_CAN_TBS_3_BASE)
/** Peripheral CE_CAN_TBS_4 base address */
#define IP_CE_CAN_TBS_4_BASE                     (0x449E8000u)
/** Peripheral CE_CAN_TBS_4 base pointer */
#define IP_CE_CAN_TBS_4                          ((CAN_TBS_Type *)IP_CE_CAN_TBS_4_BASE)
/** Peripheral CE_CAN_TBS_5 base address */
#define IP_CE_CAN_TBS_5_BASE                     (0x449F8000u)
/** Peripheral CE_CAN_TBS_5 base pointer */
#define IP_CE_CAN_TBS_5                          ((CAN_TBS_Type *)IP_CE_CAN_TBS_5_BASE)
/** Peripheral CE_CAN_TBS_6 base address */
#define IP_CE_CAN_TBS_6_BASE                     (0x44BA8000u)
/** Peripheral CE_CAN_TBS_6 base pointer */
#define IP_CE_CAN_TBS_6                          ((CAN_TBS_Type *)IP_CE_CAN_TBS_6_BASE)
/** Peripheral CE_CAN_TBS_7 base address */
#define IP_CE_CAN_TBS_7_BASE                     (0x44BB8000u)
/** Peripheral CE_CAN_TBS_7 base pointer */
#define IP_CE_CAN_TBS_7                          ((CAN_TBS_Type *)IP_CE_CAN_TBS_7_BASE)
/** Peripheral CE_CAN_TBS_8 base address */
#define IP_CE_CAN_TBS_8_BASE                     (0x44BC8000u)
/** Peripheral CE_CAN_TBS_8 base pointer */
#define IP_CE_CAN_TBS_8                          ((CAN_TBS_Type *)IP_CE_CAN_TBS_8_BASE)
/** Peripheral CE_CAN_TBS_9 base address */
#define IP_CE_CAN_TBS_9_BASE                     (0x44BD8000u)
/** Peripheral CE_CAN_TBS_9 base pointer */
#define IP_CE_CAN_TBS_9                          ((CAN_TBS_Type *)IP_CE_CAN_TBS_9_BASE)
/** Peripheral CE_CAN_TBS_10 base address */
#define IP_CE_CAN_TBS_10_BASE                    (0x44BE8000u)
/** Peripheral CE_CAN_TBS_10 base pointer */
#define IP_CE_CAN_TBS_10                         ((CAN_TBS_Type *)IP_CE_CAN_TBS_10_BASE)
/** Peripheral CE_CAN_TBS_11 base address */
#define IP_CE_CAN_TBS_11_BASE                    (0x44BF8000u)
/** Peripheral CE_CAN_TBS_11 base pointer */
#define IP_CE_CAN_TBS_11                         ((CAN_TBS_Type *)IP_CE_CAN_TBS_11_BASE)
/** Peripheral CE_CAN_TBS_12 base address */
#define IP_CE_CAN_TBS_12_BASE                    (0x44DA8000u)
/** Peripheral CE_CAN_TBS_12 base pointer */
#define IP_CE_CAN_TBS_12                         ((CAN_TBS_Type *)IP_CE_CAN_TBS_12_BASE)
/** Peripheral CE_CAN_TBS_13 base address */
#define IP_CE_CAN_TBS_13_BASE                    (0x44DB8000u)
/** Peripheral CE_CAN_TBS_13 base pointer */
#define IP_CE_CAN_TBS_13                         ((CAN_TBS_Type *)IP_CE_CAN_TBS_13_BASE)
/** Peripheral CE_CAN_TBS_14 base address */
#define IP_CE_CAN_TBS_14_BASE                    (0x44DC8000u)
/** Peripheral CE_CAN_TBS_14 base pointer */
#define IP_CE_CAN_TBS_14                         ((CAN_TBS_Type *)IP_CE_CAN_TBS_14_BASE)
/** Peripheral CE_CAN_TBS_15 base address */
#define IP_CE_CAN_TBS_15_BASE                    (0x44DD8000u)
/** Peripheral CE_CAN_TBS_15 base pointer */
#define IP_CE_CAN_TBS_15                         ((CAN_TBS_Type *)IP_CE_CAN_TBS_15_BASE)
/** Peripheral CE_CAN_TBS_16 base address */
#define IP_CE_CAN_TBS_16_BASE                    (0x44DE8000u)
/** Peripheral CE_CAN_TBS_16 base pointer */
#define IP_CE_CAN_TBS_16                         ((CAN_TBS_Type *)IP_CE_CAN_TBS_16_BASE)
/** Peripheral CE_CAN_TBS_17 base address */
#define IP_CE_CAN_TBS_17_BASE                    (0x44DF8000u)
/** Peripheral CE_CAN_TBS_17 base pointer */
#define IP_CE_CAN_TBS_17                         ((CAN_TBS_Type *)IP_CE_CAN_TBS_17_BASE)
/** Peripheral CE_CAN_TBS_18 base address */
#define IP_CE_CAN_TBS_18_BASE                    (0x44FA8000u)
/** Peripheral CE_CAN_TBS_18 base pointer */
#define IP_CE_CAN_TBS_18                         ((CAN_TBS_Type *)IP_CE_CAN_TBS_18_BASE)
/** Peripheral CE_CAN_TBS_19 base address */
#define IP_CE_CAN_TBS_19_BASE                    (0x44FB8000u)
/** Peripheral CE_CAN_TBS_19 base pointer */
#define IP_CE_CAN_TBS_19                         ((CAN_TBS_Type *)IP_CE_CAN_TBS_19_BASE)
/** Peripheral CE_CAN_TBS_20 base address */
#define IP_CE_CAN_TBS_20_BASE                    (0x44FC8000u)
/** Peripheral CE_CAN_TBS_20 base pointer */
#define IP_CE_CAN_TBS_20                         ((CAN_TBS_Type *)IP_CE_CAN_TBS_20_BASE)
/** Peripheral CE_CAN_TBS_21 base address */
#define IP_CE_CAN_TBS_21_BASE                    (0x44FD8000u)
/** Peripheral CE_CAN_TBS_21 base pointer */
#define IP_CE_CAN_TBS_21                         ((CAN_TBS_Type *)IP_CE_CAN_TBS_21_BASE)
/** Peripheral CE_CAN_TBS_22 base address */
#define IP_CE_CAN_TBS_22_BASE                    (0x44FE8000u)
/** Peripheral CE_CAN_TBS_22 base pointer */
#define IP_CE_CAN_TBS_22                         ((CAN_TBS_Type *)IP_CE_CAN_TBS_22_BASE)
/** Peripheral CE_CAN_TBS_23 base address */
#define IP_CE_CAN_TBS_23_BASE                    (0x44FF8000u)
/** Peripheral CE_CAN_TBS_23 base pointer */
#define IP_CE_CAN_TBS_23                         ((CAN_TBS_Type *)IP_CE_CAN_TBS_23_BASE)
/** Array initializer of CAN_TBS peripheral base addresses */
#define IP_CAN_TBS_BASE_ADDRS                    { IP_CANXL_0_TBS_BASE, IP_CANXL_1_TBS_BASE, IP_CE_CAN_TBS_0_BASE, IP_CE_CAN_TBS_1_BASE, IP_CE_CAN_TBS_2_BASE, IP_CE_CAN_TBS_3_BASE, IP_CE_CAN_TBS_4_BASE, IP_CE_CAN_TBS_5_BASE, IP_CE_CAN_TBS_6_BASE, IP_CE_CAN_TBS_7_BASE, IP_CE_CAN_TBS_8_BASE, IP_CE_CAN_TBS_9_BASE, IP_CE_CAN_TBS_10_BASE, IP_CE_CAN_TBS_11_BASE, IP_CE_CAN_TBS_12_BASE, IP_CE_CAN_TBS_13_BASE, IP_CE_CAN_TBS_14_BASE, IP_CE_CAN_TBS_15_BASE, IP_CE_CAN_TBS_16_BASE, IP_CE_CAN_TBS_17_BASE, IP_CE_CAN_TBS_18_BASE, IP_CE_CAN_TBS_19_BASE, IP_CE_CAN_TBS_20_BASE, IP_CE_CAN_TBS_21_BASE, IP_CE_CAN_TBS_22_BASE, IP_CE_CAN_TBS_23_BASE }
/** Array initializer of CAN_TBS peripheral base pointers */
#define IP_CAN_TBS_BASE_PTRS                     { IP_CANXL_0_TBS, IP_CANXL_1_TBS, IP_CE_CAN_TBS_0, IP_CE_CAN_TBS_1, IP_CE_CAN_TBS_2, IP_CE_CAN_TBS_3, IP_CE_CAN_TBS_4, IP_CE_CAN_TBS_5, IP_CE_CAN_TBS_6, IP_CE_CAN_TBS_7, IP_CE_CAN_TBS_8, IP_CE_CAN_TBS_9, IP_CE_CAN_TBS_10, IP_CE_CAN_TBS_11, IP_CE_CAN_TBS_12, IP_CE_CAN_TBS_13, IP_CE_CAN_TBS_14, IP_CE_CAN_TBS_15, IP_CE_CAN_TBS_16, IP_CE_CAN_TBS_17, IP_CE_CAN_TBS_18, IP_CE_CAN_TBS_19, IP_CE_CAN_TBS_20, IP_CE_CAN_TBS_21, IP_CE_CAN_TBS_22, IP_CE_CAN_TBS_23 }

/* ----------------------------------------------------------------------------
   -- CAN_TBS Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CAN_TBS_Register_Masks CAN_TBS Register Masks
 * @{
 */

/*! @name CAN_TB_VALUE - CAN Time Base Output Value */
/*! @{ */

#define CAN_TBS_CAN_TB_VALUE_TB_VALUE_MASK       (0xFFFFFFFFU)
#define CAN_TBS_CAN_TB_VALUE_TB_VALUE_SHIFT      (0U)
#define CAN_TBS_CAN_TB_VALUE_TB_VALUE_WIDTH      (32U)
#define CAN_TBS_CAN_TB_VALUE_TB_VALUE(x)         (((uint32_t)(((uint32_t)(x)) << CAN_TBS_CAN_TB_VALUE_TB_VALUE_SHIFT)) & CAN_TBS_CAN_TB_VALUE_TB_VALUE_MASK)
/*! @} */

/*! @name CAN_TS_SEL - CAN Timestamp Mux Selector */
/*! @{ */

#define CAN_TBS_CAN_TS_SEL_TS_SEL_MASK           (0x3U)
#define CAN_TBS_CAN_TS_SEL_TS_SEL_SHIFT          (0U)
#define CAN_TBS_CAN_TS_SEL_TS_SEL_WIDTH          (2U)
#define CAN_TBS_CAN_TS_SEL_TS_SEL(x)             (((uint32_t)(((uint32_t)(x)) << CAN_TBS_CAN_TS_SEL_TS_SEL_SHIFT)) & CAN_TBS_CAN_TS_SEL_TS_SEL_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group CAN_TBS_Register_Masks */

/*!
 * @}
 */ /* end of group CAN_TBS_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_CAN_TBS_H_) */
