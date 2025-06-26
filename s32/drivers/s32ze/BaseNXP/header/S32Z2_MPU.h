/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_MPU.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_MPU
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
#if !defined(S32Z2_MPU_H_)  /* Check if memory map has not been already included */
#define S32Z2_MPU_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- S32_MPU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup S32_MPU_Peripheral_Access_Layer S32_MPU Peripheral Access Layer
 */
/** S32_MPU - Size of Registers Arrays */
#define S32_MPU_A_COUNT                          3u
#define S32_MPU_MAIR_COUNT                       2u

/** S32_MPU - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[3472];
  __I  uint32_t TYPE;                              /**< MPU Type Register, offset: 0xD90 */
  __IO uint32_t CTRL;                              /**< MPU Control Register, offset: 0xD94 */
  __IO uint32_t RNR;                               /**< MPU Region Number Register, offset: 0xD98 */
  __IO uint32_t RBAR;                              /**< MPU Region Base Address Register, offset: 0xD9C */
  __IO uint32_t RLAR;                              /**< MPU Region Limit Address Register, offset: 0xDA0 */
  struct {
    __IO uint32_t RBAR;                            /**< MPU RBAR Aliases, array offset: 0xDA4, array step: 0x8 */
    __IO uint32_t RLAR;                            /**< MPU RLAR Aliases, array offset: 0xDA8, array step: 0x8 */
  } A[S32_MPU_A_COUNT];
       uint8_t RESERVED_1[4];
  __IO uint32_t MAIR[S32_MPU_MAIR_COUNT];          /**< MPU Memory Attribute Indirection Register, array offset: 0xDC0, array step: 0x4*/
} S32_MPU_Type, *S32_MPU_MemMapPtr;

 /** Number of instances of the S32_MPU module. */
#define S32_MPU_INSTANCE_COUNT                   (1u)

/* S32_MPU - Peripheral instance base addresses */
/** Peripheral S32_MPU base address */
#define IP_S32_MPU_BASE                             (0xE000E000u)
/** Peripheral S32_MPU_NS base address */
#define IP_S32_MPU_NS_BASE                          (0xE002E000u)
/** Peripheral S32_MPU base pointer */
#define S32_MPU                                  ((S32_MPU_Type *)IP_S32_MPU_BASE)
/** Peripheral S32_MPU_NS base pointer */
#define S32_MPU_NS                               ((S32_MPU_Type *)IP_S32_MPU_NS_BASE)
/** Array initializer of S32_MPU peripheral base addresses */
#define IP_S32_MPU_BASE_ADDRS                       { IP_S32_MPU_BASE }
/** Array initializer of S32_MPU peripheral base pointers */
#define IP_S32_MPU_BASE_PTRS                        { IP_S32_MPU }

/* ----------------------------------------------------------------------------
   -- S32_MPU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup S32_MPU_Register_Masks S32_MPU Register Masks
 * @{
 */

/* TYPE Bit Fields */
#define S32_MPU_TYPE_SEPARATE_MASK               0x1u
#define S32_MPU_TYPE_SEPARATE_SHIFT              0u
#define S32_MPU_TYPE_SEPARATE_WIDTH              1u
#define S32_MPU_TYPE_SEPARATE(x)                 (((uint32_t)(((uint32_t)(x))<<S32_MPU_TYPE_SEPARATE_SHIFT))&S32_MPU_TYPE_SEPARATE_MASK)
#define S32_MPU_TYPE_DREGION_MASK                0xFF00u
#define S32_MPU_TYPE_DREGION_SHIFT               8u
#define S32_MPU_TYPE_DREGION_WIDTH               8u
#define S32_MPU_TYPE_DREGION(x)                  (((uint32_t)(((uint32_t)(x))<<S32_MPU_TYPE_DREGION_SHIFT))&S32_MPU_TYPE_DREGION_MASK)
#define S32_MPU_TYPE_IREGION_MASK                0xFF0000u
#define S32_MPU_TYPE_IREGION_SHIFT               16u
#define S32_MPU_TYPE_IREGION_WIDTH               8u
#define S32_MPU_TYPE_IREGION(x)                  (((uint32_t)(((uint32_t)(x))<<S32_MPU_TYPE_IREGION_SHIFT))&S32_MPU_TYPE_IREGION_MASK)
/* CTRL Bit Fields */
#define S32_MPU_CTRL_ENABLE_MASK                 0x1u
#define S32_MPU_CTRL_ENABLE_SHIFT                0u
#define S32_MPU_CTRL_ENABLE_WIDTH                1u
#define S32_MPU_CTRL_ENABLE(x)                   (((uint32_t)(((uint32_t)(x))<<S32_MPU_CTRL_ENABLE_SHIFT))&S32_MPU_CTRL_ENABLE_MASK)
#define S32_MPU_CTRL_HFNMIENA_MASK               0x2u
#define S32_MPU_CTRL_HFNMIENA_SHIFT              1u
#define S32_MPU_CTRL_HFNMIENA_WIDTH              1u
#define S32_MPU_CTRL_HFNMIENA(x)                 (((uint32_t)(((uint32_t)(x))<<S32_MPU_CTRL_HFNMIENA_SHIFT))&S32_MPU_CTRL_HFNMIENA_MASK)
#define S32_MPU_CTRL_PRIVDEFENA_MASK             0x4u
#define S32_MPU_CTRL_PRIVDEFENA_SHIFT            2u
#define S32_MPU_CTRL_PRIVDEFENA_WIDTH            1u
#define S32_MPU_CTRL_PRIVDEFENA(x)               (((uint32_t)(((uint32_t)(x))<<S32_MPU_CTRL_PRIVDEFENA_SHIFT))&S32_MPU_CTRL_PRIVDEFENA_MASK)
/* RNR Bit Fields */
#define S32_MPU_RNR_REGION_MASK                  0xFFu
#define S32_MPU_RNR_REGION_SHIFT                 0u
#define S32_MPU_RNR_REGION_WIDTH                 8u
#define S32_MPU_RNR_REGION(x)                    (((uint32_t)(((uint32_t)(x))<<S32_MPU_RNR_REGION_SHIFT))&S32_MPU_RNR_REGION_MASK)
/* RBAR Bit Fields */
#define S32_MPU_RBAR_REGION_MASK                 0xFu
#define S32_MPU_RBAR_REGION_SHIFT                0u
#define S32_MPU_RBAR_REGION_WIDTH                4u
#define S32_MPU_RBAR_REGION(x)                   (((uint32_t)(((uint32_t)(x))<<S32_MPU_RBAR_REGION_SHIFT))&S32_MPU_RBAR_REGION_MASK)
#define S32_MPU_RBAR_VALID_MASK                  0x10u
#define S32_MPU_RBAR_VALID_SHIFT                 4u
#define S32_MPU_RBAR_VALID_WIDTH                 1u
#define S32_MPU_RBAR_VALID(x)                    (((uint32_t)(((uint32_t)(x))<<S32_MPU_RBAR_VALID_SHIFT))&S32_MPU_RBAR_VALID_MASK)
#define S32_MPU_RBAR_ADDR_MASK                   0xFFFFFFE0u
#define S32_MPU_RBAR_ADDR_SHIFT                  5u
#define S32_MPU_RBAR_ADDR_WIDTH                  27u
#define S32_MPU_RBAR_ADDR(x)                     (((uint32_t)(((uint32_t)(x))<<S32_MPU_RBAR_ADDR_SHIFT))&S32_MPU_RBAR_ADDR_MASK)
/* RLAR Bit Fields */
#define S32_MPU_RLAR_ENABLE_MASK                 0x1u
#define S32_MPU_RLAR_ENABLE_SHIFT                0u
#define S32_MPU_RLAR_ENABLE_WIDTH                1u
#define S32_MPU_RLAR_ENABLE(x)                   (((uint32_t)(((uint32_t)(x))<<S32_MPU_RLAR_ENABLE_SHIFT))&S32_MPU_RLAR_ENABLE_MASK)
#define S32_MPU_RLAR_ATTRINDX_MASK               0xEu
#define S32_MPU_RLAR_ATTRINDX_SHIFT              1u
#define S32_MPU_RLAR_ATTRINDX_WIDTH              3u
#define S32_MPU_RLAR_ATTRINDX(x)                 (((uint32_t)(((uint32_t)(x))<<S32_MPU_RLAR_ATTRINDX_SHIFT))&S32_MPU_RLAR_ATTRINDX_MASK)
#define S32_MPU_RLAR_LIMIT_MASK                  0xFFFFFFE0u
#define S32_MPU_RLAR_LIMIT_SHIFT                 5u
#define S32_MPU_RLAR_LIMIT_WIDTH                 27u
#define S32_MPU_RLAR_LIMIT(x)                    (((uint32_t)(x))&S32_MPU_RLAR_LIMIT_MASK)
/* A_RBAR Bit Fields */
#define S32_MPU_A_RBAR_REGION_MASK               0xFu
#define S32_MPU_A_RBAR_REGION_SHIFT              0u
#define S32_MPU_A_RBAR_REGION_WIDTH              4u
#define S32_MPU_A_RBAR_REGION(x)                 (((uint32_t)(((uint32_t)(x))<<S32_MPU_A_RBAR_REGION_SHIFT))&S32_MPU_A_RBAR_REGION_MASK)
#define S32_MPU_A_RBAR_VALID_MASK                0x10u
#define S32_MPU_A_RBAR_VALID_SHIFT               4u
#define S32_MPU_A_RBAR_VALID_WIDTH               1u
#define S32_MPU_A_RBAR_VALID(x)                  (((uint32_t)(((uint32_t)(x))<<S32_MPU_A_RBAR_VALID_SHIFT))&S32_MPU_A_RBAR_VALID_MASK)
#define S32_MPU_A_RBAR_ADDR_MASK                 0xFFFFFFE0u
#define S32_MPU_A_RBAR_ADDR_SHIFT                5u
#define S32_MPU_A_RBAR_ADDR_WIDTH                27u
#define S32_MPU_A_RBAR_ADDR(x)                   (((uint32_t)(((uint32_t)(x))<<S32_MPU_A_RBAR_ADDR_SHIFT))&S32_MPU_A_RBAR_ADDR_MASK)
/* A_RLAR Bit Fields */
#define S32_MPU_A_RLAR_ENABLE_MASK               0x1u
#define S32_MPU_A_RLAR_ENABLE_SHIFT              0u
#define S32_MPU_A_RLAR_ENABLE_WIDTH              1u
#define S32_MPU_A_RLAR_ENABLE(x)                 (((uint32_t)(((uint32_t)(x))<<S32_MPU_A_RLAR_ENABLE_SHIFT))&S32_MPU_A_RLAR_ENABLE_MASK)
#define S32_MPU_A_RLAR_ATTRINDX_MASK             0xEu
#define S32_MPU_A_RLAR_ATTRINDX_SHIFT            1u
#define S32_MPU_A_RLAR_ATTRINDX_WIDTH            3u
#define S32_MPU_A_RLAR_ATTRINDX(x)               (((uint32_t)(((uint32_t)(x))<<S32_MPU_A_RLAR_ATTRINDX_SHIFT))&S32_MPU_A_RLAR_ATTRINDX_MASK)
#define S32_MPU_A_RLAR_LIMIT_MASK                0xFFFFFFE0u
#define S32_MPU_A_RLAR_LIMIT_SHIFT               5u
#define S32_MPU_A_RLAR_LIMIT_WIDTH               27u
#define S32_MPU_A_RLAR_LIMIT(x)                  (((uint32_t)(((uint32_t)(x))<<S32_MPU_A_RLAR_LIMIT_SHIFT))&S32_MPU_A_RLAR_LIMIT_MASK)

#define S32_MPU_RBAR_AP_MASK                     0x6u
#define S32_MPU_RBAR_AP_SHIFT                    1u
#define S32_MPU_RBAR_AP_WIDTH                    2u
#define S32_MPU_RBAR_AP(x)                       (((uint32_t)(((uint32_t)(x))<<S32_MPU_RBAR_AP_SHIFT))&S32_MPU_RBAR_AP_MASK)
#define S32_MPU_RBAR_XN_MASK                     0x1u
#define S32_MPU_RBAR_XN_SHIFT                    0u
#define S32_MPU_RBAR_XN_WIDTH                    1u
#define S32_MPU_RBAR_XN(x)                       (((uint32_t)(((uint32_t)(x))<<S32_MPU_RBAR_XN_SHIFT))&S32_MPU_RBAR_XN_MASK)
/* MAIR Bit Fields */
#define S32_MPU_MAIR_ATTRx_SHIFT(x)              ((uint32_t)(8u * ((uint32_t)(x))))
#define S32_MPU_MAIR_ATTRx_MASK(x)               ((uint32_t)(0xFFu << ((uint32_t)S32_MPU_MAIR_ATTRx_SHIFT(x))))
#define S32_MPU_MAIR_ATTRx_WIDTH                 8u
#define S32_MPU_MAIR_ATTRx(x,y)                  (((uint32_t)(((uint32_t)(y))<<S32_MPU_MAIR_ATTRx_SHIFT(x)))&S32_MPU_MAIR_ATTRx_MASK(x))

/*!
 * @}
 */ /* end of group S32_MPU_Register_Masks */

/*!
 * @}
 */ /* end of group S32_MPU_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_MPU_H_) */
