/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_EDMA3_MP.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_EDMA3_MP
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
#if !defined(S32Z2_EDMA3_MP_H_)  /* Check if memory map has not been already included */
#define S32Z2_EDMA3_MP_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- EDMA3_MP Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup EDMA3_MP_Peripheral_Access_Layer EDMA3_MP Peripheral Access Layer
 * @{
 */

/** EDMA3_MP - Size of Registers Arrays */
#define EDMA3_MP_MP_GRPRI_COUNT                   32u

/** EDMA3_MP - Register Layout Typedef */
typedef struct {
  __IO uint32_t CSR;                               /**< Management Page Control, offset: 0x0 */
  __I  uint32_t ES;                                /**< Management Page Error Status, offset: 0x4 */
  __I  uint32_t INT;                               /**< Management Page Interrupt Request Status, offset: 0x8 */
  __I  uint32_t HRS;                               /**< Management Page Hardware Request Status, offset: 0xC */
  uint8_t RESERVED_0[240];
  __IO uint32_t CH_GRPRI[EDMA3_MP_MP_GRPRI_COUNT]; /**< Channel Arbitration Group, array offset: 0x100, array step: 0x4, irregular array, not all indices are valid */
} EDMA3_MP_Type, *EDMA3_MP_MemMapPtr;

/** Number of instances of the EDMA3_MP module. */
#define EDMA3_MP_INSTANCE_COUNT                  (5u)

/* EDMA3_MP - Peripheral instance base addresses */
/** Peripheral EDMA_0_MP base address */
#define IP_EDMA_0_MP_BASE                        (0x405D0000u)
/** Peripheral EDMA_0_MP base pointer */
#define IP_EDMA_0_MP                             ((EDMA3_MP_Type *)IP_EDMA_0_MP_BASE)
/** Peripheral EDMA_1_MP base address */
#define IP_EDMA_1_MP_BASE                        (0x40DD0000u)
/** Peripheral EDMA_1_MP base pointer */
#define IP_EDMA_1_MP                             ((EDMA3_MP_Type *)IP_EDMA_1_MP_BASE)
/** Peripheral EDMA_4_MP base address */
#define IP_EDMA_4_MP_BASE                        (0x425D0000u)
/** Peripheral EDMA_4_MP base pointer */
#define IP_EDMA_4_MP                             ((EDMA3_MP_Type *)IP_EDMA_4_MP_BASE)
/** Peripheral EDMA_5_MP base address */
#define IP_EDMA_5_MP_BASE                        (0x42DD0000u)
/** Peripheral EDMA_5_MP base pointer */
#define IP_EDMA_5_MP                             ((EDMA3_MP_Type *)IP_EDMA_5_MP_BASE)
/** Peripheral CE_EDMA_MP base address */
#define IP_CE_EDMA_MP_BASE                       (0x44E00000u)
/** Peripheral CE_EDMA_MP base pointer */
#define IP_CE_EDMA_MP                            ((EDMA3_MP_Type *)IP_CE_EDMA_MP_BASE)
/** Array initializer of EDMA3_MP peripheral base addresses */
#define IP_EDMA3_MP_BASE_ADDRS                   { IP_EDMA_0_MP_BASE, IP_EDMA_1_MP_BASE, IP_EDMA_4_MP_BASE, IP_EDMA_5_MP_BASE, IP_CE_EDMA_MP_BASE }
/** Array initializer of EDMA3_MP peripheral base pointers */
#define IP_EDMA3_MP_BASE_PTRS                    { IP_EDMA_0_MP, IP_EDMA_1_MP, IP_EDMA_4_MP, IP_EDMA_5_MP, IP_CE_EDMA_MP }

/* ----------------------------------------------------------------------------
   -- EDMA3_MP Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup EDMA3_MP_Register_Masks EDMA3_MP Register Masks
 * @{
 */

/*! @name CSR - Management Page Control */
/*! @{ */

#define EDMA3_MP_CSR_EDBG_MASK                   (0x2U)
#define EDMA3_MP_CSR_EDBG_SHIFT                  (1U)
#define EDMA3_MP_CSR_EDBG_WIDTH                  (1U)
#define EDMA3_MP_CSR_EDBG(x)                     (((uint32_t)(((uint32_t)(x)) << EDMA3_MP_CSR_EDBG_SHIFT)) & EDMA3_MP_CSR_EDBG_MASK)

#define EDMA3_MP_CSR_ERCA_MASK                   (0x4U)
#define EDMA3_MP_CSR_ERCA_SHIFT                  (2U)
#define EDMA3_MP_CSR_ERCA_WIDTH                  (1U)
#define EDMA3_MP_CSR_ERCA(x)                     (((uint32_t)(((uint32_t)(x)) << EDMA3_MP_CSR_ERCA_SHIFT)) & EDMA3_MP_CSR_ERCA_MASK)

#define EDMA3_MP_CSR_HAE_MASK                    (0x10U)
#define EDMA3_MP_CSR_HAE_SHIFT                   (4U)
#define EDMA3_MP_CSR_HAE_WIDTH                   (1U)
#define EDMA3_MP_CSR_HAE(x)                      (((uint32_t)(((uint32_t)(x)) << EDMA3_MP_CSR_HAE_SHIFT)) & EDMA3_MP_CSR_HAE_MASK)

#define EDMA3_MP_CSR_HALT_MASK                   (0x20U)
#define EDMA3_MP_CSR_HALT_SHIFT                  (5U)
#define EDMA3_MP_CSR_HALT_WIDTH                  (1U)
#define EDMA3_MP_CSR_HALT(x)                     (((uint32_t)(((uint32_t)(x)) << EDMA3_MP_CSR_HALT_SHIFT)) & EDMA3_MP_CSR_HALT_MASK)

#define EDMA3_MP_CSR_GCLC_MASK                   (0x40U)
#define EDMA3_MP_CSR_GCLC_SHIFT                  (6U)
#define EDMA3_MP_CSR_GCLC_WIDTH                  (1U)
#define EDMA3_MP_CSR_GCLC(x)                     (((uint32_t)(((uint32_t)(x)) << EDMA3_MP_CSR_GCLC_SHIFT)) & EDMA3_MP_CSR_GCLC_MASK)

#define EDMA3_MP_CSR_GMRC_MASK                   (0x80U)
#define EDMA3_MP_CSR_GMRC_SHIFT                  (7U)
#define EDMA3_MP_CSR_GMRC_WIDTH                  (1U)
#define EDMA3_MP_CSR_GMRC(x)                     (((uint32_t)(((uint32_t)(x)) << EDMA3_MP_CSR_GMRC_SHIFT)) & EDMA3_MP_CSR_GMRC_MASK)

#define EDMA3_MP_CSR_ECX_MASK                    (0x100U)
#define EDMA3_MP_CSR_ECX_SHIFT                   (8U)
#define EDMA3_MP_CSR_ECX_WIDTH                   (1U)
#define EDMA3_MP_CSR_ECX(x)                      (((uint32_t)(((uint32_t)(x)) << EDMA3_MP_CSR_ECX_SHIFT)) & EDMA3_MP_CSR_ECX_MASK)

#define EDMA3_MP_CSR_CX_MASK                     (0x200U)
#define EDMA3_MP_CSR_CX_SHIFT                    (9U)
#define EDMA3_MP_CSR_CX_WIDTH                    (1U)
#define EDMA3_MP_CSR_CX(x)                       (((uint32_t)(((uint32_t)(x)) << EDMA3_MP_CSR_CX_SHIFT)) & EDMA3_MP_CSR_CX_MASK)

#define EDMA3_MP_CSR_ACTIVE_ID_MASK              (0x1F000000U)  /* Merged from fields with different position or width, of widths (4, 5), largest definition used */
#define EDMA3_MP_CSR_ACTIVE_ID_SHIFT             (24U)
#define EDMA3_MP_CSR_ACTIVE_ID_WIDTH             (5U)
#define EDMA3_MP_CSR_ACTIVE_ID(x)                (((uint32_t)(((uint32_t)(x)) << EDMA3_MP_CSR_ACTIVE_ID_SHIFT)) & EDMA3_MP_CSR_ACTIVE_ID_MASK)  /* Merged from fields with different position or width, of widths (4, 5), largest definition used */

#define EDMA3_MP_CSR_ACTIVE_MASK                 (0x80000000U)
#define EDMA3_MP_CSR_ACTIVE_SHIFT                (31U)
#define EDMA3_MP_CSR_ACTIVE_WIDTH                (1U)
#define EDMA3_MP_CSR_ACTIVE(x)                   (((uint32_t)(((uint32_t)(x)) << EDMA3_MP_CSR_ACTIVE_SHIFT)) & EDMA3_MP_CSR_ACTIVE_MASK)
/*! @} */

/*! @name ES - Management Page Error Status */
/*! @{ */

#define EDMA3_MP_ES_DBE_MASK                     (0x1U)
#define EDMA3_MP_ES_DBE_SHIFT                    (0U)
#define EDMA3_MP_ES_DBE_WIDTH                    (1U)
#define EDMA3_MP_ES_DBE(x)                       (((uint32_t)(((uint32_t)(x)) << EDMA3_MP_ES_DBE_SHIFT)) & EDMA3_MP_ES_DBE_MASK)

#define EDMA3_MP_ES_SBE_MASK                     (0x2U)
#define EDMA3_MP_ES_SBE_SHIFT                    (1U)
#define EDMA3_MP_ES_SBE_WIDTH                    (1U)
#define EDMA3_MP_ES_SBE(x)                       (((uint32_t)(((uint32_t)(x)) << EDMA3_MP_ES_SBE_SHIFT)) & EDMA3_MP_ES_SBE_MASK)

#define EDMA3_MP_ES_SGE_MASK                     (0x4U)
#define EDMA3_MP_ES_SGE_SHIFT                    (2U)
#define EDMA3_MP_ES_SGE_WIDTH                    (1U)
#define EDMA3_MP_ES_SGE(x)                       (((uint32_t)(((uint32_t)(x)) << EDMA3_MP_ES_SGE_SHIFT)) & EDMA3_MP_ES_SGE_MASK)

#define EDMA3_MP_ES_NCE_MASK                     (0x8U)
#define EDMA3_MP_ES_NCE_SHIFT                    (3U)
#define EDMA3_MP_ES_NCE_WIDTH                    (1U)
#define EDMA3_MP_ES_NCE(x)                       (((uint32_t)(((uint32_t)(x)) << EDMA3_MP_ES_NCE_SHIFT)) & EDMA3_MP_ES_NCE_MASK)

#define EDMA3_MP_ES_DOE_MASK                     (0x10U)
#define EDMA3_MP_ES_DOE_SHIFT                    (4U)
#define EDMA3_MP_ES_DOE_WIDTH                    (1U)
#define EDMA3_MP_ES_DOE(x)                       (((uint32_t)(((uint32_t)(x)) << EDMA3_MP_ES_DOE_SHIFT)) & EDMA3_MP_ES_DOE_MASK)

#define EDMA3_MP_ES_DAE_MASK                     (0x20U)
#define EDMA3_MP_ES_DAE_SHIFT                    (5U)
#define EDMA3_MP_ES_DAE_WIDTH                    (1U)
#define EDMA3_MP_ES_DAE(x)                       (((uint32_t)(((uint32_t)(x)) << EDMA3_MP_ES_DAE_SHIFT)) & EDMA3_MP_ES_DAE_MASK)

#define EDMA3_MP_ES_SOE_MASK                     (0x40U)
#define EDMA3_MP_ES_SOE_SHIFT                    (6U)
#define EDMA3_MP_ES_SOE_WIDTH                    (1U)
#define EDMA3_MP_ES_SOE(x)                       (((uint32_t)(((uint32_t)(x)) << EDMA3_MP_ES_SOE_SHIFT)) & EDMA3_MP_ES_SOE_MASK)

#define EDMA3_MP_ES_SAE_MASK                     (0x80U)
#define EDMA3_MP_ES_SAE_SHIFT                    (7U)
#define EDMA3_MP_ES_SAE_WIDTH                    (1U)
#define EDMA3_MP_ES_SAE(x)                       (((uint32_t)(((uint32_t)(x)) << EDMA3_MP_ES_SAE_SHIFT)) & EDMA3_MP_ES_SAE_MASK)

#define EDMA3_MP_ES_ECX_MASK                     (0x100U)
#define EDMA3_MP_ES_ECX_SHIFT                    (8U)
#define EDMA3_MP_ES_ECX_WIDTH                    (1U)
#define EDMA3_MP_ES_ECX(x)                       (((uint32_t)(((uint32_t)(x)) << EDMA3_MP_ES_ECX_SHIFT)) & EDMA3_MP_ES_ECX_MASK)

#define EDMA3_MP_ES_UCE_MASK                     (0x200U)
#define EDMA3_MP_ES_UCE_SHIFT                    (9U)
#define EDMA3_MP_ES_UCE_WIDTH                    (1U)
#define EDMA3_MP_ES_UCE(x)                       (((uint32_t)(((uint32_t)(x)) << EDMA3_MP_ES_UCE_SHIFT)) & EDMA3_MP_ES_UCE_MASK)

#define EDMA3_MP_ES_ERRCHN_MASK                  (0x1F000000U)  /* Merged from fields with different position or width, of widths (4, 5), largest definition used */
#define EDMA3_MP_ES_ERRCHN_SHIFT                 (24U)
#define EDMA3_MP_ES_ERRCHN_WIDTH                 (5U)
#define EDMA3_MP_ES_ERRCHN(x)                    (((uint32_t)(((uint32_t)(x)) << EDMA3_MP_ES_ERRCHN_SHIFT)) & EDMA3_MP_ES_ERRCHN_MASK)  /* Merged from fields with different position or width, of widths (4, 5), largest definition used */

#define EDMA3_MP_ES_VLD_MASK                     (0x80000000U)
#define EDMA3_MP_ES_VLD_SHIFT                    (31U)
#define EDMA3_MP_ES_VLD_WIDTH                    (1U)
#define EDMA3_MP_ES_VLD(x)                       (((uint32_t)(((uint32_t)(x)) << EDMA3_MP_ES_VLD_SHIFT)) & EDMA3_MP_ES_VLD_MASK)
/*! @} */

/*! @name INT - Management Page Interrupt Request Status */
/*! @{ */

#define EDMA3_MP_INT_INT_MASK                    (0xFFFFFFFFU)  /* Merged from fields with different position or width, of widths (16, 32), largest definition used */
#define EDMA3_MP_INT_INT_SHIFT                   (0U)
#define EDMA3_MP_INT_INT_WIDTH                   (32U)
#define EDMA3_MP_INT_INT(x)                      (((uint32_t)(((uint32_t)(x)) << EDMA3_MP_INT_INT_SHIFT)) & EDMA3_MP_INT_INT_MASK)  /* Merged from fields with different position or width, of widths (16, 32), largest definition used */
/*! @} */

/*! @name HRS - Management Page Hardware Request Status */
/*! @{ */

#define EDMA3_MP_HRS_HRS_MASK                    (0xFFFFFFFFU)
#define EDMA3_MP_HRS_HRS_SHIFT                   (0U)
#define EDMA3_MP_HRS_HRS_WIDTH                   (32U)
#define EDMA3_MP_HRS_HRS(x)                      (((uint32_t)(((uint32_t)(x)) << EDMA3_MP_HRS_HRS_SHIFT)) & EDMA3_MP_HRS_HRS_MASK)
/*! @} */

/*! @name CH_GRPRI - Channel Arbitration Group */
/*! @{ */

#define EDMA3_MP_CH_GRPRI_GRPRI_MASK             (0x1FU)
#define EDMA3_MP_CH_GRPRI_GRPRI_SHIFT            (0U)
#define EDMA3_MP_CH_GRPRI_GRPRI_WIDTH            (5U)
#define EDMA3_MP_CH_GRPRI_GRPRI(x)               (((uint32_t)(((uint32_t)(x)) << EDMA3_MP_CH_GRPRI_GRPRI_SHIFT)) & EDMA3_MP_CH_GRPRI_GRPRI_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group EDMA3_MP_Register_Masks */

/*!
 * @}
 */ /* end of group EDMA3_MP_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_EDMA3_MP_H_) */
