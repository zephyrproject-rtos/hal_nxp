/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K566_spp_dma5_MP.h
 * @version 2.2
 * @date 2025-10-16
 * @brief Peripheral Access Layer for S32K566_spp_dma5_MP
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
#if !defined(S32K566_spp_dma5_MP_H_)  /* Check if memory map has not been already included */
#define S32K566_spp_dma5_MP_H_

#include "S32K566_COMMON.h"

/* ----------------------------------------------------------------------------
   -- spp_dma5_MP Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup spp_dma5_MP_Peripheral_Access_Layer spp_dma5_MP Peripheral Access Layer
 * @{
 */

/** spp_dma5_MP - Size of Registers Arrays */
#define spp_dma5_MP_MP_GRPRI_COUNT                32u
#define spp_dma5_MP_MP_CHPROT_COUNT               32u

/** spp_dma5_MP - Register Layout Typedef */
typedef struct spp_dma5_MP_Struct {
  __IO uint32_t MP_CSR;                            /**< Management Page Control, offset: 0x0 */
  __I  uint32_t MP_ES;                             /**< Management Page Error Status, offset: 0x4 */
  __I  uint32_t MP_INT_LOW;                        /**< Management Page Interrupt Request Status, offset: 0x8 */
  uint8_t RESERVED_0[4];
  __I  uint32_t MP_HRS_LOW;                        /**< Hardware Request Status, offset: 0x10 */
  uint8_t RESERVED_1[12];
  __IO uint32_t MP_STOPCH;                         /**< Stop Channel, offset: 0x20 */
  uint8_t RESERVED_2[12];
  __I  uint32_t MP_SSR_LOW;                        /**< Stop Status, offset: 0x30 */
  uint8_t RESERVED_3[204];
  __IO uint32_t CH_GRPRI[spp_dma5_MP_MP_GRPRI_COUNT]; /**< Channel Arbitration Group, array offset: 0x100, array step: 0x4 */
  uint8_t RESERVED_4[640];
  __IO uint32_t CH_PROT[spp_dma5_MP_MP_CHPROT_COUNT]; /**< Channel Protection, array offset: 0x400, array step: 0x4 */
} spp_dma5_MP_Type, *spp_dma5_MP_MemMapPtr;

/** Number of instances of the spp_dma5_MP module. */
#define spp_dma5_MP_INSTANCE_COUNT               (1u)

/* spp_dma5_MP - Peripheral instance base addresses */
/** Peripheral EDMA5 base address */
#define IP_EDMA5_BASE                            (0x40410000u)
/** Peripheral EDMA5 base pointer */
#define IP_EDMA5                                 ((spp_dma5_MP_Type *)IP_EDMA5_BASE)
/** Array initializer of spp_dma5_MP peripheral base addresses */
#define IP_spp_dma5_MP_BASE_ADDRS                { IP_EDMA5_BASE }
/** Array initializer of spp_dma5_MP peripheral base pointers */
#define IP_spp_dma5_MP_BASE_PTRS                 { IP_EDMA5 }

/* ----------------------------------------------------------------------------
   -- spp_dma5_MP Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup spp_dma5_MP_Register_Masks spp_dma5_MP Register Masks
 * @{
 */

/*! @name MP_CSR - Management Page Control */
/*! @{ */

#define spp_dma5_MP_MP_CSR_EDBG_MASK             (0x2U)
#define spp_dma5_MP_MP_CSR_EDBG_SHIFT            (1U)
#define spp_dma5_MP_MP_CSR_EDBG_WIDTH            (1U)
#define spp_dma5_MP_MP_CSR_EDBG(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_MP_MP_CSR_EDBG_SHIFT)) & spp_dma5_MP_MP_CSR_EDBG_MASK)

#define spp_dma5_MP_MP_CSR_ERCA_MASK             (0x4U)
#define spp_dma5_MP_MP_CSR_ERCA_SHIFT            (2U)
#define spp_dma5_MP_MP_CSR_ERCA_WIDTH            (1U)
#define spp_dma5_MP_MP_CSR_ERCA(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_MP_MP_CSR_ERCA_SHIFT)) & spp_dma5_MP_MP_CSR_ERCA_MASK)

#define spp_dma5_MP_MP_CSR_GCPC_MASK             (0x8U)
#define spp_dma5_MP_MP_CSR_GCPC_SHIFT            (3U)
#define spp_dma5_MP_MP_CSR_GCPC_WIDTH            (1U)
#define spp_dma5_MP_MP_CSR_GCPC(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_MP_MP_CSR_GCPC_SHIFT)) & spp_dma5_MP_MP_CSR_GCPC_MASK)

#define spp_dma5_MP_MP_CSR_HAE_MASK              (0x10U)
#define spp_dma5_MP_MP_CSR_HAE_SHIFT             (4U)
#define spp_dma5_MP_MP_CSR_HAE_WIDTH             (1U)
#define spp_dma5_MP_MP_CSR_HAE(x)                (((uint32_t)(((uint32_t)(x)) << spp_dma5_MP_MP_CSR_HAE_SHIFT)) & spp_dma5_MP_MP_CSR_HAE_MASK)

#define spp_dma5_MP_MP_CSR_HALT_MASK             (0x20U)
#define spp_dma5_MP_MP_CSR_HALT_SHIFT            (5U)
#define spp_dma5_MP_MP_CSR_HALT_WIDTH            (1U)
#define spp_dma5_MP_MP_CSR_HALT(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_MP_MP_CSR_HALT_SHIFT)) & spp_dma5_MP_MP_CSR_HALT_MASK)

#define spp_dma5_MP_MP_CSR_GCLC_MASK             (0x40U)
#define spp_dma5_MP_MP_CSR_GCLC_SHIFT            (6U)
#define spp_dma5_MP_MP_CSR_GCLC_WIDTH            (1U)
#define spp_dma5_MP_MP_CSR_GCLC(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_MP_MP_CSR_GCLC_SHIFT)) & spp_dma5_MP_MP_CSR_GCLC_MASK)

#define spp_dma5_MP_MP_CSR_GMRC_MASK             (0x80U)
#define spp_dma5_MP_MP_CSR_GMRC_SHIFT            (7U)
#define spp_dma5_MP_MP_CSR_GMRC_WIDTH            (1U)
#define spp_dma5_MP_MP_CSR_GMRC(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_MP_MP_CSR_GMRC_SHIFT)) & spp_dma5_MP_MP_CSR_GMRC_MASK)

#define spp_dma5_MP_MP_CSR_VER_MASK              (0xFF0000U)
#define spp_dma5_MP_MP_CSR_VER_SHIFT             (16U)
#define spp_dma5_MP_MP_CSR_VER_WIDTH             (8U)
#define spp_dma5_MP_MP_CSR_VER(x)                (((uint32_t)(((uint32_t)(x)) << spp_dma5_MP_MP_CSR_VER_SHIFT)) & spp_dma5_MP_MP_CSR_VER_MASK)

#define spp_dma5_MP_MP_CSR_ACTIVE_ID_MASK        (0x1F000000U)
#define spp_dma5_MP_MP_CSR_ACTIVE_ID_SHIFT       (24U)
#define spp_dma5_MP_MP_CSR_ACTIVE_ID_WIDTH       (5U)
#define spp_dma5_MP_MP_CSR_ACTIVE_ID(x)          (((uint32_t)(((uint32_t)(x)) << spp_dma5_MP_MP_CSR_ACTIVE_ID_SHIFT)) & spp_dma5_MP_MP_CSR_ACTIVE_ID_MASK)

#define spp_dma5_MP_MP_CSR_ACTIVE_MASK           (0x80000000U)
#define spp_dma5_MP_MP_CSR_ACTIVE_SHIFT          (31U)
#define spp_dma5_MP_MP_CSR_ACTIVE_WIDTH          (1U)
#define spp_dma5_MP_MP_CSR_ACTIVE(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_MP_MP_CSR_ACTIVE_SHIFT)) & spp_dma5_MP_MP_CSR_ACTIVE_MASK)
/*! @} */

/*! @name MP_ES - Management Page Error Status */
/*! @{ */

#define spp_dma5_MP_MP_ES_DBE_MASK               (0x1U)
#define spp_dma5_MP_MP_ES_DBE_SHIFT              (0U)
#define spp_dma5_MP_MP_ES_DBE_WIDTH              (1U)
#define spp_dma5_MP_MP_ES_DBE(x)                 (((uint32_t)(((uint32_t)(x)) << spp_dma5_MP_MP_ES_DBE_SHIFT)) & spp_dma5_MP_MP_ES_DBE_MASK)

#define spp_dma5_MP_MP_ES_SBE_MASK               (0x2U)
#define spp_dma5_MP_MP_ES_SBE_SHIFT              (1U)
#define spp_dma5_MP_MP_ES_SBE_WIDTH              (1U)
#define spp_dma5_MP_MP_ES_SBE(x)                 (((uint32_t)(((uint32_t)(x)) << spp_dma5_MP_MP_ES_SBE_SHIFT)) & spp_dma5_MP_MP_ES_SBE_MASK)

#define spp_dma5_MP_MP_ES_SGE_MASK               (0x4U)
#define spp_dma5_MP_MP_ES_SGE_SHIFT              (2U)
#define spp_dma5_MP_MP_ES_SGE_WIDTH              (1U)
#define spp_dma5_MP_MP_ES_SGE(x)                 (((uint32_t)(((uint32_t)(x)) << spp_dma5_MP_MP_ES_SGE_SHIFT)) & spp_dma5_MP_MP_ES_SGE_MASK)

#define spp_dma5_MP_MP_ES_NCE_MASK               (0x8U)
#define spp_dma5_MP_MP_ES_NCE_SHIFT              (3U)
#define spp_dma5_MP_MP_ES_NCE_WIDTH              (1U)
#define spp_dma5_MP_MP_ES_NCE(x)                 (((uint32_t)(((uint32_t)(x)) << spp_dma5_MP_MP_ES_NCE_SHIFT)) & spp_dma5_MP_MP_ES_NCE_MASK)

#define spp_dma5_MP_MP_ES_DOE_MASK               (0x10U)
#define spp_dma5_MP_MP_ES_DOE_SHIFT              (4U)
#define spp_dma5_MP_MP_ES_DOE_WIDTH              (1U)
#define spp_dma5_MP_MP_ES_DOE(x)                 (((uint32_t)(((uint32_t)(x)) << spp_dma5_MP_MP_ES_DOE_SHIFT)) & spp_dma5_MP_MP_ES_DOE_MASK)

#define spp_dma5_MP_MP_ES_DAE_MASK               (0x20U)
#define spp_dma5_MP_MP_ES_DAE_SHIFT              (5U)
#define spp_dma5_MP_MP_ES_DAE_WIDTH              (1U)
#define spp_dma5_MP_MP_ES_DAE(x)                 (((uint32_t)(((uint32_t)(x)) << spp_dma5_MP_MP_ES_DAE_SHIFT)) & spp_dma5_MP_MP_ES_DAE_MASK)

#define spp_dma5_MP_MP_ES_SOE_MASK               (0x40U)
#define spp_dma5_MP_MP_ES_SOE_SHIFT              (6U)
#define spp_dma5_MP_MP_ES_SOE_WIDTH              (1U)
#define spp_dma5_MP_MP_ES_SOE(x)                 (((uint32_t)(((uint32_t)(x)) << spp_dma5_MP_MP_ES_SOE_SHIFT)) & spp_dma5_MP_MP_ES_SOE_MASK)

#define spp_dma5_MP_MP_ES_SAE_MASK               (0x80U)
#define spp_dma5_MP_MP_ES_SAE_SHIFT              (7U)
#define spp_dma5_MP_MP_ES_SAE_WIDTH              (1U)
#define spp_dma5_MP_MP_ES_SAE(x)                 (((uint32_t)(((uint32_t)(x)) << spp_dma5_MP_MP_ES_SAE_SHIFT)) & spp_dma5_MP_MP_ES_SAE_MASK)

#define spp_dma5_MP_MP_ES_ECX_MASK               (0x100U)
#define spp_dma5_MP_MP_ES_ECX_SHIFT              (8U)
#define spp_dma5_MP_MP_ES_ECX_WIDTH              (1U)
#define spp_dma5_MP_MP_ES_ECX(x)                 (((uint32_t)(((uint32_t)(x)) << spp_dma5_MP_MP_ES_ECX_SHIFT)) & spp_dma5_MP_MP_ES_ECX_MASK)

#define spp_dma5_MP_MP_ES_UCE_MASK               (0x200U)
#define spp_dma5_MP_MP_ES_UCE_SHIFT              (9U)
#define spp_dma5_MP_MP_ES_UCE_WIDTH              (1U)
#define spp_dma5_MP_MP_ES_UCE(x)                 (((uint32_t)(((uint32_t)(x)) << spp_dma5_MP_MP_ES_UCE_SHIFT)) & spp_dma5_MP_MP_ES_UCE_MASK)

#define spp_dma5_MP_MP_ES_ERRCHN_MASK            (0x1F000000U)
#define spp_dma5_MP_MP_ES_ERRCHN_SHIFT           (24U)
#define spp_dma5_MP_MP_ES_ERRCHN_WIDTH           (5U)
#define spp_dma5_MP_MP_ES_ERRCHN(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_MP_MP_ES_ERRCHN_SHIFT)) & spp_dma5_MP_MP_ES_ERRCHN_MASK)

#define spp_dma5_MP_MP_ES_VLD_MASK               (0x80000000U)
#define spp_dma5_MP_MP_ES_VLD_SHIFT              (31U)
#define spp_dma5_MP_MP_ES_VLD_WIDTH              (1U)
#define spp_dma5_MP_MP_ES_VLD(x)                 (((uint32_t)(((uint32_t)(x)) << spp_dma5_MP_MP_ES_VLD_SHIFT)) & spp_dma5_MP_MP_ES_VLD_MASK)
/*! @} */

/*! @name MP_INT_LOW - Management Page Interrupt Request Status */
/*! @{ */

#define spp_dma5_MP_MP_INT_LOW_INT_MASK          (0xFFFFFFFFU)
#define spp_dma5_MP_MP_INT_LOW_INT_SHIFT         (0U)
#define spp_dma5_MP_MP_INT_LOW_INT_WIDTH         (32U)
#define spp_dma5_MP_MP_INT_LOW_INT(x)            (((uint32_t)(((uint32_t)(x)) << spp_dma5_MP_MP_INT_LOW_INT_SHIFT)) & spp_dma5_MP_MP_INT_LOW_INT_MASK)
/*! @} */

/*! @name MP_HRS_LOW - Hardware Request Status */
/*! @{ */

#define spp_dma5_MP_MP_HRS_LOW_HRS_MASK          (0xFFFFFFFFU)
#define spp_dma5_MP_MP_HRS_LOW_HRS_SHIFT         (0U)
#define spp_dma5_MP_MP_HRS_LOW_HRS_WIDTH         (32U)
#define spp_dma5_MP_MP_HRS_LOW_HRS(x)            (((uint32_t)(((uint32_t)(x)) << spp_dma5_MP_MP_HRS_LOW_HRS_SHIFT)) & spp_dma5_MP_MP_HRS_LOW_HRS_MASK)
/*! @} */

/*! @name MP_STOPCH - Stop Channel */
/*! @{ */

#define spp_dma5_MP_MP_STOPCH_STOPCH_MASK        (0x1FU)
#define spp_dma5_MP_MP_STOPCH_STOPCH_SHIFT       (0U)
#define spp_dma5_MP_MP_STOPCH_STOPCH_WIDTH       (5U)
#define spp_dma5_MP_MP_STOPCH_STOPCH(x)          (((uint32_t)(((uint32_t)(x)) << spp_dma5_MP_MP_STOPCH_STOPCH_SHIFT)) & spp_dma5_MP_MP_STOPCH_STOPCH_MASK)

#define spp_dma5_MP_MP_STOPCH_ERR_MASK           (0x80U)
#define spp_dma5_MP_MP_STOPCH_ERR_SHIFT          (7U)
#define spp_dma5_MP_MP_STOPCH_ERR_WIDTH          (1U)
#define spp_dma5_MP_MP_STOPCH_ERR(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_MP_MP_STOPCH_ERR_SHIFT)) & spp_dma5_MP_MP_STOPCH_ERR_MASK)
/*! @} */

/*! @name MP_SSR_LOW - Stop Status */
/*! @{ */

#define spp_dma5_MP_MP_SSR_LOW_CSS_MASK          (0xFFFFFFFFU)
#define spp_dma5_MP_MP_SSR_LOW_CSS_SHIFT         (0U)
#define spp_dma5_MP_MP_SSR_LOW_CSS_WIDTH         (32U)
#define spp_dma5_MP_MP_SSR_LOW_CSS(x)            (((uint32_t)(((uint32_t)(x)) << spp_dma5_MP_MP_SSR_LOW_CSS_SHIFT)) & spp_dma5_MP_MP_SSR_LOW_CSS_MASK)
/*! @} */

/*! @name CH_GRPRI - Channel Arbitration Group */
/*! @{ */

#define spp_dma5_MP_CH_GRPRI_GRPRI_MASK          (0x3FU)
#define spp_dma5_MP_CH_GRPRI_GRPRI_SHIFT         (0U)
#define spp_dma5_MP_CH_GRPRI_GRPRI_WIDTH         (6U)
#define spp_dma5_MP_CH_GRPRI_GRPRI(x)            (((uint32_t)(((uint32_t)(x)) << spp_dma5_MP_CH_GRPRI_GRPRI_SHIFT)) & spp_dma5_MP_CH_GRPRI_GRPRI_MASK)
/*! @} */

/*! @name CH_PROT - Channel Protection */
/*! @{ */

#define spp_dma5_MP_CH_PROT_MID_MASK             (0x3FU)
#define spp_dma5_MP_CH_PROT_MID_SHIFT            (0U)
#define spp_dma5_MP_CH_PROT_MID_WIDTH            (6U)
#define spp_dma5_MP_CH_PROT_MID(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_MP_CH_PROT_MID_SHIFT)) & spp_dma5_MP_CH_PROT_MID_MASK)

#define spp_dma5_MP_CH_PROT_INSTR_MASK           (0x2000U)
#define spp_dma5_MP_CH_PROT_INSTR_SHIFT          (13U)
#define spp_dma5_MP_CH_PROT_INSTR_WIDTH          (1U)
#define spp_dma5_MP_CH_PROT_INSTR(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_MP_CH_PROT_INSTR_SHIFT)) & spp_dma5_MP_CH_PROT_INSTR_MASK)

#define spp_dma5_MP_CH_PROT_SEC_MASK             (0x4000U)
#define spp_dma5_MP_CH_PROT_SEC_SHIFT            (14U)
#define spp_dma5_MP_CH_PROT_SEC_WIDTH            (1U)
#define spp_dma5_MP_CH_PROT_SEC(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_MP_CH_PROT_SEC_SHIFT)) & spp_dma5_MP_CH_PROT_SEC_MASK)

#define spp_dma5_MP_CH_PROT_PAL_MASK             (0x8000U)
#define spp_dma5_MP_CH_PROT_PAL_SHIFT            (15U)
#define spp_dma5_MP_CH_PROT_PAL_WIDTH            (1U)
#define spp_dma5_MP_CH_PROT_PAL(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_MP_CH_PROT_PAL_SHIFT)) & spp_dma5_MP_CH_PROT_PAL_MASK)

#define spp_dma5_MP_CH_PROT_EMI_MASK             (0x10000U)
#define spp_dma5_MP_CH_PROT_EMI_SHIFT            (16U)
#define spp_dma5_MP_CH_PROT_EMI_WIDTH            (1U)
#define spp_dma5_MP_CH_PROT_EMI(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_MP_CH_PROT_EMI_SHIFT)) & spp_dma5_MP_CH_PROT_EMI_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group spp_dma5_MP_Register_Masks */

/*!
 * @}
 */ /* end of group spp_dma5_MP_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K566_spp_dma5_MP_H_) */
