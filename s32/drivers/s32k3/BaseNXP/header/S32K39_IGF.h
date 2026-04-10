/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K39_IGF.h
 * @version 1.7
 * @date 2022-11-18
 * @brief Peripheral Access Layer for S32K39_IGF
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
#if !defined(S32K39_IGF_H_)  /* Check if memory map has not been already included */
#define S32K39_IGF_H_

#include "S32K39_COMMON.h"

/* ----------------------------------------------------------------------------
   -- IGF Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IGF_Peripheral_Access_Layer IGF Peripheral Access Layer
 * @{
 */

/** IGF - Size of Registers Arrays */
#define IGF_MCR_COUNT                             32u

/** IGF - Register Layout Typedef */
typedef struct {
  struct {                                         /* offset: 0x0, array step: 0x40 */
    __IO uint32_t MCR;                               /**< Module Configuration Register, array offset: 0x0, array step: 0x40 */
    __IO uint32_t MSR;                               /**< Module Status Register, array offset: 0x4, array step: 0x40 */
    uint8_t RESERVED_0[8];
    __IO uint32_t PRESR;                             /**< Prescaler Register, array offset: 0x10, array step: 0x40 */
    uint8_t RESERVED_1[8];
    __IO uint32_t RTHR;                              /**< Rising edge Threshold Register, array offset: 0x1C, array step: 0x40 */
    __IO uint32_t FTHR;                              /**< Falling edge Threshold Register, array offset: 0x20, array step: 0x40 */
    uint8_t RESERVED_2[28];
  } MCR[IGF_MCR_COUNT];
} IGF_Type, *IGF_MemMapPtr;

/** Number of instances of the IGF module. */
#define IGF_INSTANCE_COUNT                       (1u)

/* IGF - Peripheral instance base addresses */
/** Peripheral IGF base address */
#define IP_IGF_BASE                              (0x406B0000u)
/** Peripheral IGF base pointer */
#define IP_IGF                                   ((IGF_Type *)IP_IGF_BASE)
/** Array initializer of IGF peripheral base addresses */
#define IP_IGF_BASE_ADDRS                        { IP_IGF_BASE }
/** Array initializer of IGF peripheral base pointers */
#define IP_IGF_BASE_PTRS                         { IP_IGF }

/* ----------------------------------------------------------------------------
   -- IGF Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IGF_Register_Masks IGF Register Masks
 * @{
 */

/*! @name MCR - Module Configuration Register */
/*! @{ */

#define IGF_MCR_RFM_MASK                         (0x7U)
#define IGF_MCR_RFM_SHIFT                        (0U)
#define IGF_MCR_RFM_WIDTH                        (3U)
#define IGF_MCR_RFM(x)                           (((uint32_t)(((uint32_t)(x)) << IGF_MCR_RFM_SHIFT)) & IGF_MCR_RFM_MASK)

#define IGF_MCR_FFM_MASK                         (0x38U)
#define IGF_MCR_FFM_SHIFT                        (3U)
#define IGF_MCR_FFM_WIDTH                        (3U)
#define IGF_MCR_FFM(x)                           (((uint32_t)(((uint32_t)(x)) << IGF_MCR_FFM_SHIFT)) & IGF_MCR_FFM_MASK)

#define IGF_MCR_FGEN_MASK                        (0x40U)
#define IGF_MCR_FGEN_SHIFT                       (6U)
#define IGF_MCR_FGEN_WIDTH                       (1U)
#define IGF_MCR_FGEN(x)                          (((uint32_t)(((uint32_t)(x)) << IGF_MCR_FGEN_SHIFT)) & IGF_MCR_FGEN_MASK)

#define IGF_MCR_POL_MASK                         (0x80U)
#define IGF_MCR_POL_SHIFT                        (7U)
#define IGF_MCR_POL_WIDTH                        (1U)
#define IGF_MCR_POL(x)                           (((uint32_t)(((uint32_t)(x)) << IGF_MCR_POL_SHIFT)) & IGF_MCR_POL_MASK)

#define IGF_MCR_PSSEL_MASK                       (0x100U)
#define IGF_MCR_PSSEL_SHIFT                      (8U)
#define IGF_MCR_PSSEL_WIDTH                      (1U)
#define IGF_MCR_PSSEL(x)                         (((uint32_t)(((uint32_t)(x)) << IGF_MCR_PSSEL_SHIFT)) & IGF_MCR_PSSEL_MASK)

#define IGF_MCR_IMM_MASK                         (0x200U)
#define IGF_MCR_IMM_SHIFT                        (9U)
#define IGF_MCR_IMM_WIDTH                        (1U)
#define IGF_MCR_IMM(x)                           (((uint32_t)(((uint32_t)(x)) << IGF_MCR_IMM_SHIFT)) & IGF_MCR_IMM_MASK)

#define IGF_MCR_FOL_MASK                         (0x4000000U)
#define IGF_MCR_FOL_SHIFT                        (26U)
#define IGF_MCR_FOL_WIDTH                        (1U)
#define IGF_MCR_FOL(x)                           (((uint32_t)(((uint32_t)(x)) << IGF_MCR_FOL_SHIFT)) & IGF_MCR_FOL_MASK)

#define IGF_MCR_FOH_MASK                         (0x8000000U)
#define IGF_MCR_FOH_SHIFT                        (27U)
#define IGF_MCR_FOH_WIDTH                        (1U)
#define IGF_MCR_FOH(x)                           (((uint32_t)(((uint32_t)(x)) << IGF_MCR_FOH_SHIFT)) & IGF_MCR_FOH_MASK)

#define IGF_MCR_FBP_MASK                         (0x10000000U)
#define IGF_MCR_FBP_SHIFT                        (28U)
#define IGF_MCR_FBP_WIDTH                        (1U)
#define IGF_MCR_FBP(x)                           (((uint32_t)(((uint32_t)(x)) << IGF_MCR_FBP_SHIFT)) & IGF_MCR_FBP_MASK)

#define IGF_MCR_FRZ_MASK                         (0x20000000U)
#define IGF_MCR_FRZ_SHIFT                        (29U)
#define IGF_MCR_FRZ_WIDTH                        (1U)
#define IGF_MCR_FRZ(x)                           (((uint32_t)(((uint32_t)(x)) << IGF_MCR_FRZ_SHIFT)) & IGF_MCR_FRZ_MASK)

#define IGF_MCR_MDIS_MASK                        (0x40000000U)
#define IGF_MCR_MDIS_SHIFT                       (30U)
#define IGF_MCR_MDIS_WIDTH                       (1U)
#define IGF_MCR_MDIS(x)                          (((uint32_t)(((uint32_t)(x)) << IGF_MCR_MDIS_SHIFT)) & IGF_MCR_MDIS_MASK)
/*! @} */

/*! @name MSR - Module Status Register */
/*! @{ */

#define IGF_MSR_FLO_MASK                         (0x1U)
#define IGF_MSR_FLO_SHIFT                        (0U)
#define IGF_MSR_FLO_WIDTH                        (1U)
#define IGF_MSR_FLO(x)                           (((uint32_t)(((uint32_t)(x)) << IGF_MSR_FLO_SHIFT)) & IGF_MSR_FLO_MASK)

#define IGF_MSR_FLI_MASK                         (0x2U)
#define IGF_MSR_FLI_SHIFT                        (1U)
#define IGF_MSR_FLI_WIDTH                        (1U)
#define IGF_MSR_FLI(x)                           (((uint32_t)(((uint32_t)(x)) << IGF_MSR_FLI_SHIFT)) & IGF_MSR_FLI_MASK)

#define IGF_MSR_FNDET_MASK                       (0x4U)
#define IGF_MSR_FNDET_SHIFT                      (2U)
#define IGF_MSR_FNDET_WIDTH                      (1U)
#define IGF_MSR_FNDET(x)                         (((uint32_t)(((uint32_t)(x)) << IGF_MSR_FNDET_SHIFT)) & IGF_MSR_FNDET_MASK)

#define IGF_MSR_RNDET_MASK                       (0x8U)
#define IGF_MSR_RNDET_SHIFT                      (3U)
#define IGF_MSR_RNDET_WIDTH                      (1U)
#define IGF_MSR_RNDET(x)                         (((uint32_t)(((uint32_t)(x)) << IGF_MSR_RNDET_SHIFT)) & IGF_MSR_RNDET_MASK)

#define IGF_MSR_FEDGE_MASK                       (0x10U)
#define IGF_MSR_FEDGE_SHIFT                      (4U)
#define IGF_MSR_FEDGE_WIDTH                      (1U)
#define IGF_MSR_FEDGE(x)                         (((uint32_t)(((uint32_t)(x)) << IGF_MSR_FEDGE_SHIFT)) & IGF_MSR_FEDGE_MASK)

#define IGF_MSR_WEDGE_MASK                       (0x20U)
#define IGF_MSR_WEDGE_SHIFT                      (5U)
#define IGF_MSR_WEDGE_WIDTH                      (1U)
#define IGF_MSR_WEDGE(x)                         (((uint32_t)(((uint32_t)(x)) << IGF_MSR_WEDGE_SHIFT)) & IGF_MSR_WEDGE_MASK)
/*! @} */

/*! @name PRESR - Prescaler Register */
/*! @{ */

#define IGF_PRESR_FPRE_MASK                      (0x3FU)
#define IGF_PRESR_FPRE_SHIFT                     (0U)
#define IGF_PRESR_FPRE_WIDTH                     (6U)
#define IGF_PRESR_FPRE(x)                        (((uint32_t)(((uint32_t)(x)) << IGF_PRESR_FPRE_SHIFT)) & IGF_PRESR_FPRE_MASK)
/*! @} */

/*! @name RTHR - Rising edge Threshold Register */
/*! @{ */

#define IGF_RTHR_RTH_MASK                        (0x3FU)
#define IGF_RTHR_RTH_SHIFT                       (0U)
#define IGF_RTHR_RTH_WIDTH                       (6U)
#define IGF_RTHR_RTH(x)                          (((uint32_t)(((uint32_t)(x)) << IGF_RTHR_RTH_SHIFT)) & IGF_RTHR_RTH_MASK)
/*! @} */

/*! @name FTHR - Falling edge Threshold Register */
/*! @{ */

#define IGF_FTHR_FTH_MASK                        (0x3FU)
#define IGF_FTHR_FTH_SHIFT                       (0U)
#define IGF_FTHR_FTH_WIDTH                       (6U)
#define IGF_FTHR_FTH(x)                          (((uint32_t)(((uint32_t)(x)) << IGF_FTHR_FTH_SHIFT)) & IGF_FTHR_FTH_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group IGF_Register_Masks */

/*!
 * @}
 */ /* end of group IGF_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K39_IGF_H_) */
