/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K39_D_IP_SWG_SYN.h
 * @version 1.7
 * @date 2022-11-18
 * @brief Peripheral Access Layer for S32K39_D_IP_SWG_SYN
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
#if !defined(S32K39_D_IP_SWG_SYN_H_)  /* Check if memory map has not been already included */
#define S32K39_D_IP_SWG_SYN_H_

#include "S32K39_COMMON.h"

/* ----------------------------------------------------------------------------
   -- D_IP_SWG_SYN Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup D_IP_SWG_SYN_Peripheral_Access_Layer D_IP_SWG_SYN Peripheral Access Layer
 * @{
 */

/** D_IP_SWG_SYN - Register Layout Typedef */
typedef struct {
  __IO uint32_t CTRL;                              /**< Control Register, offset: 0x0 */
  __IO uint32_t STAT;                              /**< Status Register, offset: 0x4 */
} D_IP_SWG_SYN_Type, *D_IP_SWG_SYN_MemMapPtr;

/** Number of instances of the D_IP_SWG_SYN module. */
#define D_IP_SWG_SYN_INSTANCE_COUNT              (2u)

/* D_IP_SWG_SYN - Peripheral instance base addresses */
/** Peripheral SGEN_0 base address */
#define IP_SGEN_0_BASE                           (0x406C8000u)
/** Peripheral SGEN_0 base pointer */
#define IP_SGEN_0                                ((D_IP_SWG_SYN_Type *)IP_SGEN_0_BASE)
/** Peripheral SGEN_1 base address */
#define IP_SGEN_1_BASE                           (0x406CC000u)
/** Peripheral SGEN_1 base pointer */
#define IP_SGEN_1                                ((D_IP_SWG_SYN_Type *)IP_SGEN_1_BASE)
/** Array initializer of D_IP_SWG_SYN peripheral base addresses */
#define IP_D_IP_SWG_SYN_BASE_ADDRS               { IP_SGEN_0_BASE, IP_SGEN_1_BASE }
/** Array initializer of D_IP_SWG_SYN peripheral base pointers */
#define IP_D_IP_SWG_SYN_BASE_PTRS                { IP_SGEN_0, IP_SGEN_1 }

/* ----------------------------------------------------------------------------
   -- D_IP_SWG_SYN Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup D_IP_SWG_SYN_Register_Masks D_IP_SWG_SYN Register Masks
 * @{
 */

/*! @name CTRL - Control Register */
/*! @{ */

#define D_IP_SWG_SYN_CTRL_IOFREQ_MASK            (0xFFFFU)
#define D_IP_SWG_SYN_CTRL_IOFREQ_SHIFT           (0U)
#define D_IP_SWG_SYN_CTRL_IOFREQ_WIDTH           (16U)
#define D_IP_SWG_SYN_CTRL_IOFREQ(x)              (((uint32_t)(((uint32_t)(x)) << D_IP_SWG_SYN_CTRL_IOFREQ_SHIFT)) & D_IP_SWG_SYN_CTRL_IOFREQ_MASK)

#define D_IP_SWG_SYN_CTRL_PDS_MASK               (0x10000U)
#define D_IP_SWG_SYN_CTRL_PDS_SHIFT              (16U)
#define D_IP_SWG_SYN_CTRL_PDS_WIDTH              (1U)
#define D_IP_SWG_SYN_CTRL_PDS(x)                 (((uint32_t)(((uint32_t)(x)) << D_IP_SWG_SYN_CTRL_PDS_SHIFT)) & D_IP_SWG_SYN_CTRL_PDS_MASK)

#define D_IP_SWG_SYN_CTRL_TRIG_MODE_MASK         (0x40000U)
#define D_IP_SWG_SYN_CTRL_TRIG_MODE_SHIFT        (18U)
#define D_IP_SWG_SYN_CTRL_TRIG_MODE_WIDTH        (1U)
#define D_IP_SWG_SYN_CTRL_TRIG_MODE(x)           (((uint32_t)(((uint32_t)(x)) << D_IP_SWG_SYN_CTRL_TRIG_MODE_SHIFT)) & D_IP_SWG_SYN_CTRL_TRIG_MODE_MASK)

#define D_IP_SWG_SYN_CTRL_SEMASK_MASK            (0x800000U)
#define D_IP_SWG_SYN_CTRL_SEMASK_SHIFT           (23U)
#define D_IP_SWG_SYN_CTRL_SEMASK_WIDTH           (1U)
#define D_IP_SWG_SYN_CTRL_SEMASK(x)              (((uint32_t)(((uint32_t)(x)) << D_IP_SWG_SYN_CTRL_SEMASK_SHIFT)) & D_IP_SWG_SYN_CTRL_SEMASK_MASK)

#define D_IP_SWG_SYN_CTRL_WINDOW_MASK            (0x3000000U)
#define D_IP_SWG_SYN_CTRL_WINDOW_SHIFT           (24U)
#define D_IP_SWG_SYN_CTRL_WINDOW_WIDTH           (2U)
#define D_IP_SWG_SYN_CTRL_WINDOW(x)              (((uint32_t)(((uint32_t)(x)) << D_IP_SWG_SYN_CTRL_WINDOW_SHIFT)) & D_IP_SWG_SYN_CTRL_WINDOW_MASK)

#define D_IP_SWG_SYN_CTRL_IOAMPL_MASK            (0x3C000000U)
#define D_IP_SWG_SYN_CTRL_IOAMPL_SHIFT           (26U)
#define D_IP_SWG_SYN_CTRL_IOAMPL_WIDTH           (4U)
#define D_IP_SWG_SYN_CTRL_IOAMPL(x)              (((uint32_t)(((uint32_t)(x)) << D_IP_SWG_SYN_CTRL_IOAMPL_SHIFT)) & D_IP_SWG_SYN_CTRL_IOAMPL_MASK)

#define D_IP_SWG_SYN_CTRL_LDOS_MASK              (0x80000000U)
#define D_IP_SWG_SYN_CTRL_LDOS_SHIFT             (31U)
#define D_IP_SWG_SYN_CTRL_LDOS_WIDTH             (1U)
#define D_IP_SWG_SYN_CTRL_LDOS(x)                (((uint32_t)(((uint32_t)(x)) << D_IP_SWG_SYN_CTRL_LDOS_SHIFT)) & D_IP_SWG_SYN_CTRL_LDOS_MASK)
/*! @} */

/*! @name STAT - Status Register */
/*! @{ */

#define D_IP_SWG_SYN_STAT_PHERR_MASK             (0x40000U)
#define D_IP_SWG_SYN_STAT_PHERR_SHIFT            (18U)
#define D_IP_SWG_SYN_STAT_PHERR_WIDTH            (1U)
#define D_IP_SWG_SYN_STAT_PHERR(x)               (((uint32_t)(((uint32_t)(x)) << D_IP_SWG_SYN_STAT_PHERR_SHIFT)) & D_IP_SWG_SYN_STAT_PHERR_MASK)

#define D_IP_SWG_SYN_STAT_FERR_MASK              (0x80000U)
#define D_IP_SWG_SYN_STAT_FERR_SHIFT             (19U)
#define D_IP_SWG_SYN_STAT_FERR_WIDTH             (1U)
#define D_IP_SWG_SYN_STAT_FERR(x)                (((uint32_t)(((uint32_t)(x)) << D_IP_SWG_SYN_STAT_FERR_SHIFT)) & D_IP_SWG_SYN_STAT_FERR_MASK)

#define D_IP_SWG_SYN_STAT_SERR_MASK              (0x800000U)
#define D_IP_SWG_SYN_STAT_SERR_SHIFT             (23U)
#define D_IP_SWG_SYN_STAT_SERR_WIDTH             (1U)
#define D_IP_SWG_SYN_STAT_SERR(x)                (((uint32_t)(((uint32_t)(x)) << D_IP_SWG_SYN_STAT_SERR_SHIFT)) & D_IP_SWG_SYN_STAT_SERR_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group D_IP_SWG_SYN_Register_Masks */

/*!
 * @}
 */ /* end of group D_IP_SWG_SYN_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K39_D_IP_SWG_SYN_H_) */
