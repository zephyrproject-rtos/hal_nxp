/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_SEC_S250.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_SEC_S250
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
#if !defined(S32Z2_SEC_S250_H_)  /* Check if memory map has not been already included */
#define S32Z2_SEC_S250_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- SEC_S250 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SEC_S250_Peripheral_Access_Layer SEC_S250 Peripheral Access Layer
 * @{
 */

/** SEC_S250 - Size of Registers Arrays */
#define SEC_S250_HSE_GPR_2TO11_COUNT              10u

/** SEC_S250 - Register Layout Typedef */
typedef struct {
  uint8_t RESERVED_0[8];
  __I  uint32_t MISCDAT0;                          /**< Miscellaneous Data 0, offset: 0x8 */
  uint8_t RESERVED_1[16];
  __IO uint32_t HSE_DAT0;                          /**< HSE_H Data 0, offset: 0x1C */
  uint8_t RESERVED_2[4];
  __IO uint32_t HSE_DAT[SEC_S250_HSE_GPR_2TO11_COUNT]; /**< HSE_H Data n, array offset: 0x24, array step: 0x4 */
  __IO uint32_t HSE_QSPI0_DAT0;                    /**< QuadSPI_0 Data 0, offset: 0x4C */
  __IO uint32_t HSE_QSPI0_DAT1;                    /**< QuadSPI_0 Data 1, offset: 0x50 */
  __IO uint32_t HSE_QSPI1_DAT0;                    /**< QuadSPI_1 Data 0, offset: 0x54 */
  __IO uint32_t HSE_QSPI1_DAT1;                    /**< QuadSPI_1 Data 1, offset: 0x58 */
} SEC_S250_Type, *SEC_S250_MemMapPtr;

/** Number of instances of the SEC_S250 module. */
#define SEC_S250_INSTANCE_COUNT                  (1u)

/* SEC_S250 - Peripheral instance base addresses */
/** Peripheral SEC base address */
#define IP_SEC_BASE                              (0x42280000u)
/** Peripheral SEC base pointer */
#define IP_SEC                                   ((SEC_S250_Type *)IP_SEC_BASE)
/** Array initializer of SEC_S250 peripheral base addresses */
#define IP_SEC_S250_BASE_ADDRS                   { IP_SEC_BASE }
/** Array initializer of SEC_S250 peripheral base pointers */
#define IP_SEC_S250_BASE_PTRS                    { IP_SEC }

/* ----------------------------------------------------------------------------
   -- SEC_S250 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SEC_S250_Register_Masks SEC_S250 Register Masks
 * @{
 */

/*! @name MISCDAT0 - Miscellaneous Data 0 */
/*! @{ */

#define SEC_S250_MISCDAT0_EDB_MASK               (0x1U)
#define SEC_S250_MISCDAT0_EDB_SHIFT              (0U)
#define SEC_S250_MISCDAT0_EDB_WIDTH              (1U)
#define SEC_S250_MISCDAT0_EDB(x)                 (((uint32_t)(((uint32_t)(x)) << SEC_S250_MISCDAT0_EDB_SHIFT)) & SEC_S250_MISCDAT0_EDB_MASK)
/*! @} */

/*! @name HSE_DAT0 - HSE_H Data 0 */
/*! @{ */

#define SEC_S250_HSE_DAT0_DATA0_MASK             (0x3FU)
#define SEC_S250_HSE_DAT0_DATA0_SHIFT            (0U)
#define SEC_S250_HSE_DAT0_DATA0_WIDTH            (6U)
#define SEC_S250_HSE_DAT0_DATA0(x)               (((uint32_t)(((uint32_t)(x)) << SEC_S250_HSE_DAT0_DATA0_SHIFT)) & SEC_S250_HSE_DAT0_DATA0_MASK)

#define SEC_S250_HSE_DAT0_EDB_NEW_MASK           (0x40U)
#define SEC_S250_HSE_DAT0_EDB_NEW_SHIFT          (6U)
#define SEC_S250_HSE_DAT0_EDB_NEW_WIDTH          (1U)
#define SEC_S250_HSE_DAT0_EDB_NEW(x)             (((uint32_t)(((uint32_t)(x)) << SEC_S250_HSE_DAT0_EDB_NEW_SHIFT)) & SEC_S250_HSE_DAT0_EDB_NEW_MASK)

#define SEC_S250_HSE_DAT0_DATA1_MASK             (0xFFFFFF80U)
#define SEC_S250_HSE_DAT0_DATA1_SHIFT            (7U)
#define SEC_S250_HSE_DAT0_DATA1_WIDTH            (25U)
#define SEC_S250_HSE_DAT0_DATA1(x)               (((uint32_t)(((uint32_t)(x)) << SEC_S250_HSE_DAT0_DATA1_SHIFT)) & SEC_S250_HSE_DAT0_DATA1_MASK)
/*! @} */

/*! @name HSE_DAT - HSE_H Data n */
/*! @{ */

#define SEC_S250_HSE_DAT_DATA_MASK               (0xFFFFFFFFU)
#define SEC_S250_HSE_DAT_DATA_SHIFT              (0U)
#define SEC_S250_HSE_DAT_DATA_WIDTH              (32U)
#define SEC_S250_HSE_DAT_DATA(x)                 (((uint32_t)(((uint32_t)(x)) << SEC_S250_HSE_DAT_DATA_SHIFT)) & SEC_S250_HSE_DAT_DATA_MASK)
/*! @} */

/*! @name HSE_QSPI0_DAT0 - QuadSPI_0 Data 0 */
/*! @{ */

#define SEC_S250_HSE_QSPI0_DAT0_DATA0_MASK       (0x3FU)
#define SEC_S250_HSE_QSPI0_DAT0_DATA0_SHIFT      (0U)
#define SEC_S250_HSE_QSPI0_DAT0_DATA0_WIDTH      (6U)
#define SEC_S250_HSE_QSPI0_DAT0_DATA0(x)         (((uint32_t)(((uint32_t)(x)) << SEC_S250_HSE_QSPI0_DAT0_DATA0_SHIFT)) & SEC_S250_HSE_QSPI0_DAT0_DATA0_MASK)

#define SEC_S250_HSE_QSPI0_DAT0_DATA1_MASK       (0x100U)
#define SEC_S250_HSE_QSPI0_DAT0_DATA1_SHIFT      (8U)
#define SEC_S250_HSE_QSPI0_DAT0_DATA1_WIDTH      (1U)
#define SEC_S250_HSE_QSPI0_DAT0_DATA1(x)         (((uint32_t)(((uint32_t)(x)) << SEC_S250_HSE_QSPI0_DAT0_DATA1_SHIFT)) & SEC_S250_HSE_QSPI0_DAT0_DATA1_MASK)
/*! @} */

/*! @name HSE_QSPI0_DAT1 - QuadSPI_0 Data 1 */
/*! @{ */

#define SEC_S250_HSE_QSPI0_DAT1_DATA0_MASK       (0x7FFU)
#define SEC_S250_HSE_QSPI0_DAT1_DATA0_SHIFT      (0U)
#define SEC_S250_HSE_QSPI0_DAT1_DATA0_WIDTH      (11U)
#define SEC_S250_HSE_QSPI0_DAT1_DATA0(x)         (((uint32_t)(((uint32_t)(x)) << SEC_S250_HSE_QSPI0_DAT1_DATA0_SHIFT)) & SEC_S250_HSE_QSPI0_DAT1_DATA0_MASK)

#define SEC_S250_HSE_QSPI0_DAT1_DATA1_MASK       (0x10000U)
#define SEC_S250_HSE_QSPI0_DAT1_DATA1_SHIFT      (16U)
#define SEC_S250_HSE_QSPI0_DAT1_DATA1_WIDTH      (1U)
#define SEC_S250_HSE_QSPI0_DAT1_DATA1(x)         (((uint32_t)(((uint32_t)(x)) << SEC_S250_HSE_QSPI0_DAT1_DATA1_SHIFT)) & SEC_S250_HSE_QSPI0_DAT1_DATA1_MASK)
/*! @} */

/*! @name HSE_QSPI1_DAT0 - QuadSPI_1 Data 0 */
/*! @{ */

#define SEC_S250_HSE_QSPI1_DAT0_DATA0_MASK       (0x3FU)
#define SEC_S250_HSE_QSPI1_DAT0_DATA0_SHIFT      (0U)
#define SEC_S250_HSE_QSPI1_DAT0_DATA0_WIDTH      (6U)
#define SEC_S250_HSE_QSPI1_DAT0_DATA0(x)         (((uint32_t)(((uint32_t)(x)) << SEC_S250_HSE_QSPI1_DAT0_DATA0_SHIFT)) & SEC_S250_HSE_QSPI1_DAT0_DATA0_MASK)

#define SEC_S250_HSE_QSPI1_DAT0_DATA1_MASK       (0x100U)
#define SEC_S250_HSE_QSPI1_DAT0_DATA1_SHIFT      (8U)
#define SEC_S250_HSE_QSPI1_DAT0_DATA1_WIDTH      (1U)
#define SEC_S250_HSE_QSPI1_DAT0_DATA1(x)         (((uint32_t)(((uint32_t)(x)) << SEC_S250_HSE_QSPI1_DAT0_DATA1_SHIFT)) & SEC_S250_HSE_QSPI1_DAT0_DATA1_MASK)
/*! @} */

/*! @name HSE_QSPI1_DAT1 - QuadSPI_1 Data 1 */
/*! @{ */

#define SEC_S250_HSE_QSPI1_DAT1_DATA0_MASK       (0x7FFU)
#define SEC_S250_HSE_QSPI1_DAT1_DATA0_SHIFT      (0U)
#define SEC_S250_HSE_QSPI1_DAT1_DATA0_WIDTH      (11U)
#define SEC_S250_HSE_QSPI1_DAT1_DATA0(x)         (((uint32_t)(((uint32_t)(x)) << SEC_S250_HSE_QSPI1_DAT1_DATA0_SHIFT)) & SEC_S250_HSE_QSPI1_DAT1_DATA0_MASK)

#define SEC_S250_HSE_QSPI1_DAT1_DATA1_MASK       (0x10000U)
#define SEC_S250_HSE_QSPI1_DAT1_DATA1_SHIFT      (16U)
#define SEC_S250_HSE_QSPI1_DAT1_DATA1_WIDTH      (1U)
#define SEC_S250_HSE_QSPI1_DAT1_DATA1(x)         (((uint32_t)(((uint32_t)(x)) << SEC_S250_HSE_QSPI1_DAT1_DATA1_SHIFT)) & SEC_S250_HSE_QSPI1_DAT1_DATA1_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group SEC_S250_Register_Masks */

/*!
 * @}
 */ /* end of group SEC_S250_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_SEC_S250_H_) */
