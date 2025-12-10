/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K566_LPE_EDMA_MP.h
 * @version 2.2
 * @date 2025-10-16
 * @brief Peripheral Access Layer for S32K566_LPE_EDMA_MP
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
#if !defined(S32K566_LPE_EDMA_MP_H_)  /* Check if memory map has not been already included */
#define S32K566_LPE_EDMA_MP_H_

#include "S32K566_COMMON.h"

/* ----------------------------------------------------------------------------
   -- LPE_EDMA_MP Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPE_EDMA_MP_Peripheral_Access_Layer LPE_EDMA_MP Peripheral Access Layer
 * @{
 */

/** LPE_EDMA_MP - Size of Registers Arrays */
#define LPE_EDMA_MP_MP_GRPRI_COUNT                12u

/** LPE_EDMA_MP - Register Layout Typedef */
typedef struct LPE_EDMA_MP_Struct {
  __IO uint32_t CSR;                               /**< Management Page Control, offset: 0x0 */
  __I  uint32_t ES;                                /**< Management Page Error Status, offset: 0x4 */
  __I  uint32_t INT;                               /**< Management Page Interrupt Request Status, offset: 0x8 */
  __I  uint32_t HRS;                               /**< Management Page Hardware Request Status, offset: 0xC */
  uint8_t RESERVED_0[240];
  __IO uint32_t CH_GRPRI[LPE_EDMA_MP_MP_GRPRI_COUNT]; /**< Channel Arbitration Group, array offset: 0x100, array step: 0x4 */
} LPE_EDMA_MP_Type, *LPE_EDMA_MP_MemMapPtr;

/** Number of instances of the LPE_EDMA_MP module. */
#define LPE_EDMA_MP_INSTANCE_COUNT               (1u)

/* LPE_EDMA_MP - Peripheral instance base addresses */
/** Peripheral LPE_EDMA3 base address */
#define IP_LPE_EDMA3_BASE                        (0x42008000u)
/** Peripheral LPE_EDMA3 base pointer */
#define IP_LPE_EDMA3                             ((LPE_EDMA_MP_Type *)IP_LPE_EDMA3_BASE)
/** Array initializer of LPE_EDMA_MP peripheral base addresses */
#define IP_LPE_EDMA_MP_BASE_ADDRS                { IP_LPE_EDMA3_BASE }
/** Array initializer of LPE_EDMA_MP peripheral base pointers */
#define IP_LPE_EDMA_MP_BASE_PTRS                 { IP_LPE_EDMA3 }

/* ----------------------------------------------------------------------------
   -- LPE_EDMA_MP Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPE_EDMA_MP_Register_Masks LPE_EDMA_MP Register Masks
 * @{
 */

/*! @name CSR - Management Page Control */
/*! @{ */

#define LPE_EDMA_MP_CSR_EDBG_MASK                (0x2U)
#define LPE_EDMA_MP_CSR_EDBG_SHIFT               (1U)
#define LPE_EDMA_MP_CSR_EDBG_WIDTH               (1U)
#define LPE_EDMA_MP_CSR_EDBG(x)                  (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_MP_CSR_EDBG_SHIFT)) & LPE_EDMA_MP_CSR_EDBG_MASK)

#define LPE_EDMA_MP_CSR_ERCA_MASK                (0x4U)
#define LPE_EDMA_MP_CSR_ERCA_SHIFT               (2U)
#define LPE_EDMA_MP_CSR_ERCA_WIDTH               (1U)
#define LPE_EDMA_MP_CSR_ERCA(x)                  (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_MP_CSR_ERCA_SHIFT)) & LPE_EDMA_MP_CSR_ERCA_MASK)

#define LPE_EDMA_MP_CSR_HAE_MASK                 (0x10U)
#define LPE_EDMA_MP_CSR_HAE_SHIFT                (4U)
#define LPE_EDMA_MP_CSR_HAE_WIDTH                (1U)
#define LPE_EDMA_MP_CSR_HAE(x)                   (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_MP_CSR_HAE_SHIFT)) & LPE_EDMA_MP_CSR_HAE_MASK)

#define LPE_EDMA_MP_CSR_HALT_MASK                (0x20U)
#define LPE_EDMA_MP_CSR_HALT_SHIFT               (5U)
#define LPE_EDMA_MP_CSR_HALT_WIDTH               (1U)
#define LPE_EDMA_MP_CSR_HALT(x)                  (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_MP_CSR_HALT_SHIFT)) & LPE_EDMA_MP_CSR_HALT_MASK)

#define LPE_EDMA_MP_CSR_GCLC_MASK                (0x40U)
#define LPE_EDMA_MP_CSR_GCLC_SHIFT               (6U)
#define LPE_EDMA_MP_CSR_GCLC_WIDTH               (1U)
#define LPE_EDMA_MP_CSR_GCLC(x)                  (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_MP_CSR_GCLC_SHIFT)) & LPE_EDMA_MP_CSR_GCLC_MASK)

#define LPE_EDMA_MP_CSR_GMRC_MASK                (0x80U)
#define LPE_EDMA_MP_CSR_GMRC_SHIFT               (7U)
#define LPE_EDMA_MP_CSR_GMRC_WIDTH               (1U)
#define LPE_EDMA_MP_CSR_GMRC(x)                  (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_MP_CSR_GMRC_SHIFT)) & LPE_EDMA_MP_CSR_GMRC_MASK)

#define LPE_EDMA_MP_CSR_ECX_MASK                 (0x100U)
#define LPE_EDMA_MP_CSR_ECX_SHIFT                (8U)
#define LPE_EDMA_MP_CSR_ECX_WIDTH                (1U)
#define LPE_EDMA_MP_CSR_ECX(x)                   (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_MP_CSR_ECX_SHIFT)) & LPE_EDMA_MP_CSR_ECX_MASK)

#define LPE_EDMA_MP_CSR_CX_MASK                  (0x200U)
#define LPE_EDMA_MP_CSR_CX_SHIFT                 (9U)
#define LPE_EDMA_MP_CSR_CX_WIDTH                 (1U)
#define LPE_EDMA_MP_CSR_CX(x)                    (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_MP_CSR_CX_SHIFT)) & LPE_EDMA_MP_CSR_CX_MASK)

#define LPE_EDMA_MP_CSR_ACTIVE_ID_MASK           (0xF000000U)
#define LPE_EDMA_MP_CSR_ACTIVE_ID_SHIFT          (24U)
#define LPE_EDMA_MP_CSR_ACTIVE_ID_WIDTH          (4U)
#define LPE_EDMA_MP_CSR_ACTIVE_ID(x)             (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_MP_CSR_ACTIVE_ID_SHIFT)) & LPE_EDMA_MP_CSR_ACTIVE_ID_MASK)

#define LPE_EDMA_MP_CSR_ACTIVE_MASK              (0x80000000U)
#define LPE_EDMA_MP_CSR_ACTIVE_SHIFT             (31U)
#define LPE_EDMA_MP_CSR_ACTIVE_WIDTH             (1U)
#define LPE_EDMA_MP_CSR_ACTIVE(x)                (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_MP_CSR_ACTIVE_SHIFT)) & LPE_EDMA_MP_CSR_ACTIVE_MASK)
/*! @} */

/*! @name ES - Management Page Error Status */
/*! @{ */

#define LPE_EDMA_MP_ES_DBE_MASK                  (0x1U)
#define LPE_EDMA_MP_ES_DBE_SHIFT                 (0U)
#define LPE_EDMA_MP_ES_DBE_WIDTH                 (1U)
#define LPE_EDMA_MP_ES_DBE(x)                    (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_MP_ES_DBE_SHIFT)) & LPE_EDMA_MP_ES_DBE_MASK)

#define LPE_EDMA_MP_ES_SBE_MASK                  (0x2U)
#define LPE_EDMA_MP_ES_SBE_SHIFT                 (1U)
#define LPE_EDMA_MP_ES_SBE_WIDTH                 (1U)
#define LPE_EDMA_MP_ES_SBE(x)                    (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_MP_ES_SBE_SHIFT)) & LPE_EDMA_MP_ES_SBE_MASK)

#define LPE_EDMA_MP_ES_SGE_MASK                  (0x4U)
#define LPE_EDMA_MP_ES_SGE_SHIFT                 (2U)
#define LPE_EDMA_MP_ES_SGE_WIDTH                 (1U)
#define LPE_EDMA_MP_ES_SGE(x)                    (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_MP_ES_SGE_SHIFT)) & LPE_EDMA_MP_ES_SGE_MASK)

#define LPE_EDMA_MP_ES_NCE_MASK                  (0x8U)
#define LPE_EDMA_MP_ES_NCE_SHIFT                 (3U)
#define LPE_EDMA_MP_ES_NCE_WIDTH                 (1U)
#define LPE_EDMA_MP_ES_NCE(x)                    (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_MP_ES_NCE_SHIFT)) & LPE_EDMA_MP_ES_NCE_MASK)

#define LPE_EDMA_MP_ES_DOE_MASK                  (0x10U)
#define LPE_EDMA_MP_ES_DOE_SHIFT                 (4U)
#define LPE_EDMA_MP_ES_DOE_WIDTH                 (1U)
#define LPE_EDMA_MP_ES_DOE(x)                    (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_MP_ES_DOE_SHIFT)) & LPE_EDMA_MP_ES_DOE_MASK)

#define LPE_EDMA_MP_ES_DAE_MASK                  (0x20U)
#define LPE_EDMA_MP_ES_DAE_SHIFT                 (5U)
#define LPE_EDMA_MP_ES_DAE_WIDTH                 (1U)
#define LPE_EDMA_MP_ES_DAE(x)                    (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_MP_ES_DAE_SHIFT)) & LPE_EDMA_MP_ES_DAE_MASK)

#define LPE_EDMA_MP_ES_SOE_MASK                  (0x40U)
#define LPE_EDMA_MP_ES_SOE_SHIFT                 (6U)
#define LPE_EDMA_MP_ES_SOE_WIDTH                 (1U)
#define LPE_EDMA_MP_ES_SOE(x)                    (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_MP_ES_SOE_SHIFT)) & LPE_EDMA_MP_ES_SOE_MASK)

#define LPE_EDMA_MP_ES_SAE_MASK                  (0x80U)
#define LPE_EDMA_MP_ES_SAE_SHIFT                 (7U)
#define LPE_EDMA_MP_ES_SAE_WIDTH                 (1U)
#define LPE_EDMA_MP_ES_SAE(x)                    (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_MP_ES_SAE_SHIFT)) & LPE_EDMA_MP_ES_SAE_MASK)

#define LPE_EDMA_MP_ES_ECX_MASK                  (0x100U)
#define LPE_EDMA_MP_ES_ECX_SHIFT                 (8U)
#define LPE_EDMA_MP_ES_ECX_WIDTH                 (1U)
#define LPE_EDMA_MP_ES_ECX(x)                    (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_MP_ES_ECX_SHIFT)) & LPE_EDMA_MP_ES_ECX_MASK)

#define LPE_EDMA_MP_ES_UCE_MASK                  (0x200U)
#define LPE_EDMA_MP_ES_UCE_SHIFT                 (9U)
#define LPE_EDMA_MP_ES_UCE_WIDTH                 (1U)
#define LPE_EDMA_MP_ES_UCE(x)                    (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_MP_ES_UCE_SHIFT)) & LPE_EDMA_MP_ES_UCE_MASK)

#define LPE_EDMA_MP_ES_ERRCHN_MASK               (0xF000000U)
#define LPE_EDMA_MP_ES_ERRCHN_SHIFT              (24U)
#define LPE_EDMA_MP_ES_ERRCHN_WIDTH              (4U)
#define LPE_EDMA_MP_ES_ERRCHN(x)                 (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_MP_ES_ERRCHN_SHIFT)) & LPE_EDMA_MP_ES_ERRCHN_MASK)

#define LPE_EDMA_MP_ES_VLD_MASK                  (0x80000000U)
#define LPE_EDMA_MP_ES_VLD_SHIFT                 (31U)
#define LPE_EDMA_MP_ES_VLD_WIDTH                 (1U)
#define LPE_EDMA_MP_ES_VLD(x)                    (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_MP_ES_VLD_SHIFT)) & LPE_EDMA_MP_ES_VLD_MASK)
/*! @} */

/*! @name INT - Management Page Interrupt Request Status */
/*! @{ */

#define LPE_EDMA_MP_INT_INT_MASK                 (0xFFFU)
#define LPE_EDMA_MP_INT_INT_SHIFT                (0U)
#define LPE_EDMA_MP_INT_INT_WIDTH                (12U)
#define LPE_EDMA_MP_INT_INT(x)                   (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_MP_INT_INT_SHIFT)) & LPE_EDMA_MP_INT_INT_MASK)
/*! @} */

/*! @name HRS - Management Page Hardware Request Status */
/*! @{ */

#define LPE_EDMA_MP_HRS_HRS_MASK                 (0xFFFFFFFFU)
#define LPE_EDMA_MP_HRS_HRS_SHIFT                (0U)
#define LPE_EDMA_MP_HRS_HRS_WIDTH                (32U)
#define LPE_EDMA_MP_HRS_HRS(x)                   (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_MP_HRS_HRS_SHIFT)) & LPE_EDMA_MP_HRS_HRS_MASK)
/*! @} */

/*! @name CH_GRPRI - Channel Arbitration Group */
/*! @{ */

#define LPE_EDMA_MP_CH_GRPRI_GRPRI_MASK          (0x1FU)
#define LPE_EDMA_MP_CH_GRPRI_GRPRI_SHIFT         (0U)
#define LPE_EDMA_MP_CH_GRPRI_GRPRI_WIDTH         (5U)
#define LPE_EDMA_MP_CH_GRPRI_GRPRI(x)            (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_MP_CH_GRPRI_GRPRI_SHIFT)) & LPE_EDMA_MP_CH_GRPRI_GRPRI_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group LPE_EDMA_MP_Register_Masks */

/*!
 * @}
 */ /* end of group LPE_EDMA_MP_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K566_LPE_EDMA_MP_H_) */
