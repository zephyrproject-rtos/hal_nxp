/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_FEED_DMA_MP.h
 * @version 1.8
 * @date 2022-07-13
 * @brief Peripheral Access Layer for S32Z2_FEED_DMA_MP
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
#if !defined(S32Z2_FEED_DMA_MP_H_)  /* Check if memory map has not been already included */
#define S32Z2_FEED_DMA_MP_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- FEED_DMA_MP Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FEED_DMA_MP_Peripheral_Access_Layer FEED_DMA_MP Peripheral Access Layer
 * @{
 */

/** FEED_DMA_MP - Size of Registers Arrays */
#define FEED_DMA_MP_MP_GRPRI_COUNT                24u

/** FEED_DMA_MP - Register Layout Typedef */
typedef struct {
  __IO uint32_t CSR;                               /**< Management Page Control, offset: 0x0 */
  __I  uint32_t ES;                                /**< Management Page Error Status, offset: 0x4 */
  __I  uint32_t INT;                               /**< Management Page Interrupt Request Status, offset: 0x8 */
  __I  uint32_t HRS;                               /**< Management Page Hardware Request Status, offset: 0xC */
  uint8_t RESERVED_0[240];
  __IO uint32_t CH_GRPRI[FEED_DMA_MP_MP_GRPRI_COUNT]; /**< Channel Arbitration Group, array offset: 0x100, array step: 0x4 */
} FEED_DMA_MP_Type, *FEED_DMA_MP_MemMapPtr;

/** Number of instances of the FEED_DMA_MP module. */
#define FEED_DMA_MP_INSTANCE_COUNT               (1u)

/* FEED_DMA_MP - Peripheral instance base addresses */
/** Peripheral AES__FEED_DMA_MP base address */
#define IP_AES__FEED_DMA_MP_BASE                 (0x47200000u)
/** Peripheral AES__FEED_DMA_MP base pointer */
#define IP_AES__FEED_DMA_MP                      ((FEED_DMA_MP_Type *)IP_AES__FEED_DMA_MP_BASE)
/** Array initializer of FEED_DMA_MP peripheral base addresses */
#define IP_FEED_DMA_MP_BASE_ADDRS                { IP_AES__FEED_DMA_MP_BASE }
/** Array initializer of FEED_DMA_MP peripheral base pointers */
#define IP_FEED_DMA_MP_BASE_PTRS                 { IP_AES__FEED_DMA_MP }

/* ----------------------------------------------------------------------------
   -- FEED_DMA_MP Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FEED_DMA_MP_Register_Masks FEED_DMA_MP Register Masks
 * @{
 */

/*! @name CSR - Management Page Control */
/*! @{ */

#define FEED_DMA_MP_CSR_EDBG_MASK                (0x2U)
#define FEED_DMA_MP_CSR_EDBG_SHIFT               (1U)
#define FEED_DMA_MP_CSR_EDBG_WIDTH               (1U)
#define FEED_DMA_MP_CSR_EDBG(x)                  (((uint32_t)(((uint32_t)(x)) << FEED_DMA_MP_CSR_EDBG_SHIFT)) & FEED_DMA_MP_CSR_EDBG_MASK)

#define FEED_DMA_MP_CSR_ERCA_MASK                (0x4U)
#define FEED_DMA_MP_CSR_ERCA_SHIFT               (2U)
#define FEED_DMA_MP_CSR_ERCA_WIDTH               (1U)
#define FEED_DMA_MP_CSR_ERCA(x)                  (((uint32_t)(((uint32_t)(x)) << FEED_DMA_MP_CSR_ERCA_SHIFT)) & FEED_DMA_MP_CSR_ERCA_MASK)

#define FEED_DMA_MP_CSR_HAE_MASK                 (0x10U)
#define FEED_DMA_MP_CSR_HAE_SHIFT                (4U)
#define FEED_DMA_MP_CSR_HAE_WIDTH                (1U)
#define FEED_DMA_MP_CSR_HAE(x)                   (((uint32_t)(((uint32_t)(x)) << FEED_DMA_MP_CSR_HAE_SHIFT)) & FEED_DMA_MP_CSR_HAE_MASK)

#define FEED_DMA_MP_CSR_HALT_MASK                (0x20U)
#define FEED_DMA_MP_CSR_HALT_SHIFT               (5U)
#define FEED_DMA_MP_CSR_HALT_WIDTH               (1U)
#define FEED_DMA_MP_CSR_HALT(x)                  (((uint32_t)(((uint32_t)(x)) << FEED_DMA_MP_CSR_HALT_SHIFT)) & FEED_DMA_MP_CSR_HALT_MASK)

#define FEED_DMA_MP_CSR_GCLC_MASK                (0x40U)
#define FEED_DMA_MP_CSR_GCLC_SHIFT               (6U)
#define FEED_DMA_MP_CSR_GCLC_WIDTH               (1U)
#define FEED_DMA_MP_CSR_GCLC(x)                  (((uint32_t)(((uint32_t)(x)) << FEED_DMA_MP_CSR_GCLC_SHIFT)) & FEED_DMA_MP_CSR_GCLC_MASK)

#define FEED_DMA_MP_CSR_GMRC_MASK                (0x80U)
#define FEED_DMA_MP_CSR_GMRC_SHIFT               (7U)
#define FEED_DMA_MP_CSR_GMRC_WIDTH               (1U)
#define FEED_DMA_MP_CSR_GMRC(x)                  (((uint32_t)(((uint32_t)(x)) << FEED_DMA_MP_CSR_GMRC_SHIFT)) & FEED_DMA_MP_CSR_GMRC_MASK)

#define FEED_DMA_MP_CSR_ECX_MASK                 (0x100U)
#define FEED_DMA_MP_CSR_ECX_SHIFT                (8U)
#define FEED_DMA_MP_CSR_ECX_WIDTH                (1U)
#define FEED_DMA_MP_CSR_ECX(x)                   (((uint32_t)(((uint32_t)(x)) << FEED_DMA_MP_CSR_ECX_SHIFT)) & FEED_DMA_MP_CSR_ECX_MASK)

#define FEED_DMA_MP_CSR_CX_MASK                  (0x200U)
#define FEED_DMA_MP_CSR_CX_SHIFT                 (9U)
#define FEED_DMA_MP_CSR_CX_WIDTH                 (1U)
#define FEED_DMA_MP_CSR_CX(x)                    (((uint32_t)(((uint32_t)(x)) << FEED_DMA_MP_CSR_CX_SHIFT)) & FEED_DMA_MP_CSR_CX_MASK)

#define FEED_DMA_MP_CSR_ACTIVE_ID_MASK           (0x1F000000U)
#define FEED_DMA_MP_CSR_ACTIVE_ID_SHIFT          (24U)
#define FEED_DMA_MP_CSR_ACTIVE_ID_WIDTH          (5U)
#define FEED_DMA_MP_CSR_ACTIVE_ID(x)             (((uint32_t)(((uint32_t)(x)) << FEED_DMA_MP_CSR_ACTIVE_ID_SHIFT)) & FEED_DMA_MP_CSR_ACTIVE_ID_MASK)

#define FEED_DMA_MP_CSR_ACTIVE_MASK              (0x80000000U)
#define FEED_DMA_MP_CSR_ACTIVE_SHIFT             (31U)
#define FEED_DMA_MP_CSR_ACTIVE_WIDTH             (1U)
#define FEED_DMA_MP_CSR_ACTIVE(x)                (((uint32_t)(((uint32_t)(x)) << FEED_DMA_MP_CSR_ACTIVE_SHIFT)) & FEED_DMA_MP_CSR_ACTIVE_MASK)
/*! @} */

/*! @name ES - Management Page Error Status */
/*! @{ */

#define FEED_DMA_MP_ES_DBE_MASK                  (0x1U)
#define FEED_DMA_MP_ES_DBE_SHIFT                 (0U)
#define FEED_DMA_MP_ES_DBE_WIDTH                 (1U)
#define FEED_DMA_MP_ES_DBE(x)                    (((uint32_t)(((uint32_t)(x)) << FEED_DMA_MP_ES_DBE_SHIFT)) & FEED_DMA_MP_ES_DBE_MASK)

#define FEED_DMA_MP_ES_SBE_MASK                  (0x2U)
#define FEED_DMA_MP_ES_SBE_SHIFT                 (1U)
#define FEED_DMA_MP_ES_SBE_WIDTH                 (1U)
#define FEED_DMA_MP_ES_SBE(x)                    (((uint32_t)(((uint32_t)(x)) << FEED_DMA_MP_ES_SBE_SHIFT)) & FEED_DMA_MP_ES_SBE_MASK)

#define FEED_DMA_MP_ES_SGE_MASK                  (0x4U)
#define FEED_DMA_MP_ES_SGE_SHIFT                 (2U)
#define FEED_DMA_MP_ES_SGE_WIDTH                 (1U)
#define FEED_DMA_MP_ES_SGE(x)                    (((uint32_t)(((uint32_t)(x)) << FEED_DMA_MP_ES_SGE_SHIFT)) & FEED_DMA_MP_ES_SGE_MASK)

#define FEED_DMA_MP_ES_NCE_MASK                  (0x8U)
#define FEED_DMA_MP_ES_NCE_SHIFT                 (3U)
#define FEED_DMA_MP_ES_NCE_WIDTH                 (1U)
#define FEED_DMA_MP_ES_NCE(x)                    (((uint32_t)(((uint32_t)(x)) << FEED_DMA_MP_ES_NCE_SHIFT)) & FEED_DMA_MP_ES_NCE_MASK)

#define FEED_DMA_MP_ES_DOE_MASK                  (0x10U)
#define FEED_DMA_MP_ES_DOE_SHIFT                 (4U)
#define FEED_DMA_MP_ES_DOE_WIDTH                 (1U)
#define FEED_DMA_MP_ES_DOE(x)                    (((uint32_t)(((uint32_t)(x)) << FEED_DMA_MP_ES_DOE_SHIFT)) & FEED_DMA_MP_ES_DOE_MASK)

#define FEED_DMA_MP_ES_DAE_MASK                  (0x20U)
#define FEED_DMA_MP_ES_DAE_SHIFT                 (5U)
#define FEED_DMA_MP_ES_DAE_WIDTH                 (1U)
#define FEED_DMA_MP_ES_DAE(x)                    (((uint32_t)(((uint32_t)(x)) << FEED_DMA_MP_ES_DAE_SHIFT)) & FEED_DMA_MP_ES_DAE_MASK)

#define FEED_DMA_MP_ES_SOE_MASK                  (0x40U)
#define FEED_DMA_MP_ES_SOE_SHIFT                 (6U)
#define FEED_DMA_MP_ES_SOE_WIDTH                 (1U)
#define FEED_DMA_MP_ES_SOE(x)                    (((uint32_t)(((uint32_t)(x)) << FEED_DMA_MP_ES_SOE_SHIFT)) & FEED_DMA_MP_ES_SOE_MASK)

#define FEED_DMA_MP_ES_SAE_MASK                  (0x80U)
#define FEED_DMA_MP_ES_SAE_SHIFT                 (7U)
#define FEED_DMA_MP_ES_SAE_WIDTH                 (1U)
#define FEED_DMA_MP_ES_SAE(x)                    (((uint32_t)(((uint32_t)(x)) << FEED_DMA_MP_ES_SAE_SHIFT)) & FEED_DMA_MP_ES_SAE_MASK)

#define FEED_DMA_MP_ES_ECX_MASK                  (0x100U)
#define FEED_DMA_MP_ES_ECX_SHIFT                 (8U)
#define FEED_DMA_MP_ES_ECX_WIDTH                 (1U)
#define FEED_DMA_MP_ES_ECX(x)                    (((uint32_t)(((uint32_t)(x)) << FEED_DMA_MP_ES_ECX_SHIFT)) & FEED_DMA_MP_ES_ECX_MASK)

#define FEED_DMA_MP_ES_UCE_MASK                  (0x200U)
#define FEED_DMA_MP_ES_UCE_SHIFT                 (9U)
#define FEED_DMA_MP_ES_UCE_WIDTH                 (1U)
#define FEED_DMA_MP_ES_UCE(x)                    (((uint32_t)(((uint32_t)(x)) << FEED_DMA_MP_ES_UCE_SHIFT)) & FEED_DMA_MP_ES_UCE_MASK)

#define FEED_DMA_MP_ES_ERRCHN_MASK               (0x1F000000U)
#define FEED_DMA_MP_ES_ERRCHN_SHIFT              (24U)
#define FEED_DMA_MP_ES_ERRCHN_WIDTH              (5U)
#define FEED_DMA_MP_ES_ERRCHN(x)                 (((uint32_t)(((uint32_t)(x)) << FEED_DMA_MP_ES_ERRCHN_SHIFT)) & FEED_DMA_MP_ES_ERRCHN_MASK)

#define FEED_DMA_MP_ES_VLD_MASK                  (0x80000000U)
#define FEED_DMA_MP_ES_VLD_SHIFT                 (31U)
#define FEED_DMA_MP_ES_VLD_WIDTH                 (1U)
#define FEED_DMA_MP_ES_VLD(x)                    (((uint32_t)(((uint32_t)(x)) << FEED_DMA_MP_ES_VLD_SHIFT)) & FEED_DMA_MP_ES_VLD_MASK)
/*! @} */

/*! @name INT - Management Page Interrupt Request Status */
/*! @{ */

#define FEED_DMA_MP_INT_INT_MASK                 (0xFFFFFFU)
#define FEED_DMA_MP_INT_INT_SHIFT                (0U)
#define FEED_DMA_MP_INT_INT_WIDTH                (24U)
#define FEED_DMA_MP_INT_INT(x)                   (((uint32_t)(((uint32_t)(x)) << FEED_DMA_MP_INT_INT_SHIFT)) & FEED_DMA_MP_INT_INT_MASK)
/*! @} */

/*! @name HRS - Management Page Hardware Request Status */
/*! @{ */

#define FEED_DMA_MP_HRS_HRS_MASK                 (0xFFFFFFFFU)
#define FEED_DMA_MP_HRS_HRS_SHIFT                (0U)
#define FEED_DMA_MP_HRS_HRS_WIDTH                (32U)
#define FEED_DMA_MP_HRS_HRS(x)                   (((uint32_t)(((uint32_t)(x)) << FEED_DMA_MP_HRS_HRS_SHIFT)) & FEED_DMA_MP_HRS_HRS_MASK)
/*! @} */

/*! @name CH_GRPRI - Channel Arbitration Group */
/*! @{ */

#define FEED_DMA_MP_CH_GRPRI_GRPRI_MASK          (0x1FU)
#define FEED_DMA_MP_CH_GRPRI_GRPRI_SHIFT         (0U)
#define FEED_DMA_MP_CH_GRPRI_GRPRI_WIDTH         (5U)
#define FEED_DMA_MP_CH_GRPRI_GRPRI(x)            (((uint32_t)(((uint32_t)(x)) << FEED_DMA_MP_CH_GRPRI_GRPRI_SHIFT)) & FEED_DMA_MP_CH_GRPRI_GRPRI_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group FEED_DMA_MP_Register_Masks */

/*!
 * @}
 */ /* end of group FEED_DMA_MP_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_FEED_DMA_MP_H_) */
