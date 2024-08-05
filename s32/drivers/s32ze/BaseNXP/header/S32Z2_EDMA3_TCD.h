/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_EDMA3_TCD.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_EDMA3_TCD
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
#if !defined(S32Z2_EDMA3_TCD_H_)  /* Check if memory map has not been already included */
#define S32Z2_EDMA3_TCD_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- EDMA3_TCD Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup EDMA3_TCD_Peripheral_Access_Layer EDMA3_TCD Peripheral Access Layer
 * @{
 */

/** EDMA3_TCD - Size of Registers Arrays */
#define EDMA3_TCD_TCD_COUNT                       32u

/** EDMA3_TCD - Register Layout Typedef */
typedef struct {
  struct EDMA3_TCD_TCD {                           /* offset: 0x0, array step: 0x10000 */
    __IO uint32_t CH_CSR;                            /**< Channel Control and Status, array offset: 0x0, array step: 0x10000, irregular array, not all indices are valid */
    __IO uint32_t CH_ES;                             /**< Channel Error Status, array offset: 0x4, array step: 0x10000, irregular array, not all indices are valid */
    __IO uint32_t CH_INT;                            /**< Channel Interrupt Status, array offset: 0x8, array step: 0x10000, irregular array, not all indices are valid */
    __IO uint32_t CH_SBR;                            /**< Channel System Bus, array offset: 0xC, array step: 0x10000, irregular array, not all indices are valid */
    __IO uint32_t CH_PRI;                            /**< Channel Priority, array offset: 0x10, array step: 0x10000, irregular array, not all indices are valid */
    uint8_t RESERVED_0[12];
    __IO uint32_t SADDR;                             /**< TCD Source Address, array offset: 0x20, array step: 0x10000, irregular array, not all indices are valid */
    __IO uint16_t SOFF;                              /**< TCD Signed Source Address Offset, array offset: 0x24, array step: 0x10000, irregular array, not all indices are valid */
    __IO uint16_t ATTR;                              /**< TCD Transfer Attributes, array offset: 0x26, array step: 0x10000, irregular array, not all indices are valid */
    union {                                          /* offset: 0x28, array step: 0x10000 */
      __IO uint32_t NBYTES_MLOFFNO;                    /**< TCD Transfer Size Without Minor Loop Offsets, array offset: 0x28, array step: 0x10000, irregular array, not all indices are valid */
      __IO uint32_t NBYTES_MLOFFYES;                   /**< TCD Transfer Size with Minor Loop Offsets, array offset: 0x28, array step: 0x10000, irregular array, not all indices are valid */
    } NBYTES;
    __IO uint32_t SLAST_SDA;                         /**< TCD Last Source Address Adjustment / Store DADDR Address, array offset: 0x2C, array step: 0x10000, irregular array, not all indices are valid */
    __IO uint32_t DADDR;                             /**< TCD Destination Address, array offset: 0x30, array step: 0x10000, irregular array, not all indices are valid */
    __IO uint16_t DOFF;                              /**< TCD Signed Destination Address Offset, array offset: 0x34, array step: 0x10000, irregular array, not all indices are valid */
    union {                                          /* offset: 0x36, array step: 0x10000 */
      __IO uint16_t CITER_ELINKNO;                     /**< TCD Current Major Loop Count (Minor Loop Channel Linking Disabled), array offset: 0x36, array step: 0x10000, irregular array, not all indices are valid */
      __IO uint16_t CITER_ELINKYES;                    /**< TCD Current Major Loop Count (Minor Loop Channel Linking Enabled), array offset: 0x36, array step: 0x10000, irregular array, not all indices are valid */
    } CITER;
    __IO uint32_t DLAST_SGA;                         /**< TCD Last Destination Address Adjustment / Scatter Gather Address, array offset: 0x38, array step: 0x10000, irregular array, not all indices are valid */
    __IO uint16_t CSR;                               /**< TCD Control and Status, array offset: 0x3C, array step: 0x10000, irregular array, not all indices are valid */
    union {                                          /* offset: 0x3E, array step: 0x10000 */
      __IO uint16_t BITER_ELINKNO;                     /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled), array offset: 0x3E, array step: 0x10000, irregular array, not all indices are valid */
      __IO uint16_t BITER_ELINKYES;                    /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled), array offset: 0x3E, array step: 0x10000, irregular array, not all indices are valid */
    } BITER;
    uint8_t RESERVED_1[65472];
  } TCD[EDMA3_TCD_TCD_COUNT];
} EDMA3_TCD_Type, *EDMA3_TCD_MemMapPtr;

/** Number of instances of the EDMA3_TCD module. */
#define EDMA3_TCD_INSTANCE_COUNT                 (5u)

/* EDMA3_TCD - Peripheral instance base addresses */
/** Peripheral EDMA_0_TCD base address */
#define IP_EDMA_0_TCD_BASE                       (0x40600000u)
/** Peripheral EDMA_0_TCD base pointer */
#define IP_EDMA_0_TCD                            ((EDMA3_TCD_Type *)IP_EDMA_0_TCD_BASE)
/** Peripheral EDMA_1_TCD base address */
#define IP_EDMA_1_TCD_BASE                       (0x40E00000u)
/** Peripheral EDMA_1_TCD base pointer */
#define IP_EDMA_1_TCD                            ((EDMA3_TCD_Type *)IP_EDMA_1_TCD_BASE)
/** Peripheral EDMA_4_TCD base address */
#define IP_EDMA_4_TCD_BASE                       (0x42600000u)
/** Peripheral EDMA_4_TCD base pointer */
#define IP_EDMA_4_TCD                            ((EDMA3_TCD_Type *)IP_EDMA_4_TCD_BASE)
/** Peripheral EDMA_5_TCD base address */
#define IP_EDMA_5_TCD_BASE                       (0x42E00000u)
/** Peripheral EDMA_5_TCD base pointer */
#define IP_EDMA_5_TCD                            ((EDMA3_TCD_Type *)IP_EDMA_5_TCD_BASE)
/** Peripheral CE_EDMA_TCD base address */
#define IP_CE_EDMA_TCD_BASE                      (0x44E04000u)
/** Peripheral CE_EDMA_TCD base pointer */
#define IP_CE_EDMA_TCD                           ((EDMA3_TCD_Type *)IP_CE_EDMA_TCD_BASE)
/** Array initializer of EDMA3_TCD peripheral base addresses */
#define IP_EDMA3_TCD_BASE_ADDRS                  { IP_EDMA_0_TCD_BASE, IP_EDMA_1_TCD_BASE, IP_EDMA_4_TCD_BASE, IP_EDMA_5_TCD_BASE, IP_CE_EDMA_TCD_BASE }
/** Array initializer of EDMA3_TCD peripheral base pointers */
#define IP_EDMA3_TCD_BASE_PTRS                   { IP_EDMA_0_TCD, IP_EDMA_1_TCD, IP_EDMA_4_TCD, IP_EDMA_5_TCD, IP_CE_EDMA_TCD }

/* ----------------------------------------------------------------------------
   -- EDMA3_TCD Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup EDMA3_TCD_Register_Masks EDMA3_TCD Register Masks
 * @{
 */

/*! @name CH_CSR - Channel Control and Status */
/*! @{ */

#define EDMA3_TCD_CH_CSR_ERQ_MASK                (0x1U)
#define EDMA3_TCD_CH_CSR_ERQ_SHIFT               (0U)
#define EDMA3_TCD_CH_CSR_ERQ_WIDTH               (1U)
#define EDMA3_TCD_CH_CSR_ERQ(x)                  (((uint32_t)(((uint32_t)(x)) << EDMA3_TCD_CH_CSR_ERQ_SHIFT)) & EDMA3_TCD_CH_CSR_ERQ_MASK)

#define EDMA3_TCD_CH_CSR_EARQ_MASK               (0x2U)
#define EDMA3_TCD_CH_CSR_EARQ_SHIFT              (1U)
#define EDMA3_TCD_CH_CSR_EARQ_WIDTH              (1U)
#define EDMA3_TCD_CH_CSR_EARQ(x)                 (((uint32_t)(((uint32_t)(x)) << EDMA3_TCD_CH_CSR_EARQ_SHIFT)) & EDMA3_TCD_CH_CSR_EARQ_MASK)

#define EDMA3_TCD_CH_CSR_EEI_MASK                (0x4U)
#define EDMA3_TCD_CH_CSR_EEI_SHIFT               (2U)
#define EDMA3_TCD_CH_CSR_EEI_WIDTH               (1U)
#define EDMA3_TCD_CH_CSR_EEI(x)                  (((uint32_t)(((uint32_t)(x)) << EDMA3_TCD_CH_CSR_EEI_SHIFT)) & EDMA3_TCD_CH_CSR_EEI_MASK)

#define EDMA3_TCD_CH_CSR_EBW_MASK                (0x8U)
#define EDMA3_TCD_CH_CSR_EBW_SHIFT               (3U)
#define EDMA3_TCD_CH_CSR_EBW_WIDTH               (1U)
#define EDMA3_TCD_CH_CSR_EBW(x)                  (((uint32_t)(((uint32_t)(x)) << EDMA3_TCD_CH_CSR_EBW_SHIFT)) & EDMA3_TCD_CH_CSR_EBW_MASK)

#define EDMA3_TCD_CH_CSR_DONE_MASK               (0x40000000U)
#define EDMA3_TCD_CH_CSR_DONE_SHIFT              (30U)
#define EDMA3_TCD_CH_CSR_DONE_WIDTH              (1U)
#define EDMA3_TCD_CH_CSR_DONE(x)                 (((uint32_t)(((uint32_t)(x)) << EDMA3_TCD_CH_CSR_DONE_SHIFT)) & EDMA3_TCD_CH_CSR_DONE_MASK)

#define EDMA3_TCD_CH_CSR_ACTIVE_MASK             (0x80000000U)
#define EDMA3_TCD_CH_CSR_ACTIVE_SHIFT            (31U)
#define EDMA3_TCD_CH_CSR_ACTIVE_WIDTH            (1U)
#define EDMA3_TCD_CH_CSR_ACTIVE(x)               (((uint32_t)(((uint32_t)(x)) << EDMA3_TCD_CH_CSR_ACTIVE_SHIFT)) & EDMA3_TCD_CH_CSR_ACTIVE_MASK)
/*! @} */

/*! @name CH_ES - Channel Error Status */
/*! @{ */

#define EDMA3_TCD_CH_ES_DBE_MASK                 (0x1U)
#define EDMA3_TCD_CH_ES_DBE_SHIFT                (0U)
#define EDMA3_TCD_CH_ES_DBE_WIDTH                (1U)
#define EDMA3_TCD_CH_ES_DBE(x)                   (((uint32_t)(((uint32_t)(x)) << EDMA3_TCD_CH_ES_DBE_SHIFT)) & EDMA3_TCD_CH_ES_DBE_MASK)

#define EDMA3_TCD_CH_ES_SBE_MASK                 (0x2U)
#define EDMA3_TCD_CH_ES_SBE_SHIFT                (1U)
#define EDMA3_TCD_CH_ES_SBE_WIDTH                (1U)
#define EDMA3_TCD_CH_ES_SBE(x)                   (((uint32_t)(((uint32_t)(x)) << EDMA3_TCD_CH_ES_SBE_SHIFT)) & EDMA3_TCD_CH_ES_SBE_MASK)

#define EDMA3_TCD_CH_ES_SGE_MASK                 (0x4U)
#define EDMA3_TCD_CH_ES_SGE_SHIFT                (2U)
#define EDMA3_TCD_CH_ES_SGE_WIDTH                (1U)
#define EDMA3_TCD_CH_ES_SGE(x)                   (((uint32_t)(((uint32_t)(x)) << EDMA3_TCD_CH_ES_SGE_SHIFT)) & EDMA3_TCD_CH_ES_SGE_MASK)

#define EDMA3_TCD_CH_ES_NCE_MASK                 (0x8U)
#define EDMA3_TCD_CH_ES_NCE_SHIFT                (3U)
#define EDMA3_TCD_CH_ES_NCE_WIDTH                (1U)
#define EDMA3_TCD_CH_ES_NCE(x)                   (((uint32_t)(((uint32_t)(x)) << EDMA3_TCD_CH_ES_NCE_SHIFT)) & EDMA3_TCD_CH_ES_NCE_MASK)

#define EDMA3_TCD_CH_ES_DOE_MASK                 (0x10U)
#define EDMA3_TCD_CH_ES_DOE_SHIFT                (4U)
#define EDMA3_TCD_CH_ES_DOE_WIDTH                (1U)
#define EDMA3_TCD_CH_ES_DOE(x)                   (((uint32_t)(((uint32_t)(x)) << EDMA3_TCD_CH_ES_DOE_SHIFT)) & EDMA3_TCD_CH_ES_DOE_MASK)

#define EDMA3_TCD_CH_ES_DAE_MASK                 (0x20U)
#define EDMA3_TCD_CH_ES_DAE_SHIFT                (5U)
#define EDMA3_TCD_CH_ES_DAE_WIDTH                (1U)
#define EDMA3_TCD_CH_ES_DAE(x)                   (((uint32_t)(((uint32_t)(x)) << EDMA3_TCD_CH_ES_DAE_SHIFT)) & EDMA3_TCD_CH_ES_DAE_MASK)

#define EDMA3_TCD_CH_ES_SOE_MASK                 (0x40U)
#define EDMA3_TCD_CH_ES_SOE_SHIFT                (6U)
#define EDMA3_TCD_CH_ES_SOE_WIDTH                (1U)
#define EDMA3_TCD_CH_ES_SOE(x)                   (((uint32_t)(((uint32_t)(x)) << EDMA3_TCD_CH_ES_SOE_SHIFT)) & EDMA3_TCD_CH_ES_SOE_MASK)

#define EDMA3_TCD_CH_ES_SAE_MASK                 (0x80U)
#define EDMA3_TCD_CH_ES_SAE_SHIFT                (7U)
#define EDMA3_TCD_CH_ES_SAE_WIDTH                (1U)
#define EDMA3_TCD_CH_ES_SAE(x)                   (((uint32_t)(((uint32_t)(x)) << EDMA3_TCD_CH_ES_SAE_SHIFT)) & EDMA3_TCD_CH_ES_SAE_MASK)

#define EDMA3_TCD_CH_ES_ERR_MASK                 (0x80000000U)
#define EDMA3_TCD_CH_ES_ERR_SHIFT                (31U)
#define EDMA3_TCD_CH_ES_ERR_WIDTH                (1U)
#define EDMA3_TCD_CH_ES_ERR(x)                   (((uint32_t)(((uint32_t)(x)) << EDMA3_TCD_CH_ES_ERR_SHIFT)) & EDMA3_TCD_CH_ES_ERR_MASK)
/*! @} */

/*! @name CH_INT - Channel Interrupt Status */
/*! @{ */

#define EDMA3_TCD_CH_INT_INT_MASK                (0x1U)
#define EDMA3_TCD_CH_INT_INT_SHIFT               (0U)
#define EDMA3_TCD_CH_INT_INT_WIDTH               (1U)
#define EDMA3_TCD_CH_INT_INT(x)                  (((uint32_t)(((uint32_t)(x)) << EDMA3_TCD_CH_INT_INT_SHIFT)) & EDMA3_TCD_CH_INT_INT_MASK)
/*! @} */

/*! @name CH_SBR - Channel System Bus */
/*! @{ */

#define EDMA3_TCD_CH_SBR_MID_MASK                (0x3FU)
#define EDMA3_TCD_CH_SBR_MID_SHIFT               (0U)
#define EDMA3_TCD_CH_SBR_MID_WIDTH               (6U)
#define EDMA3_TCD_CH_SBR_MID(x)                  (((uint32_t)(((uint32_t)(x)) << EDMA3_TCD_CH_SBR_MID_SHIFT)) & EDMA3_TCD_CH_SBR_MID_MASK)

#define EDMA3_TCD_CH_SBR_PAL_MASK                (0x8000U)
#define EDMA3_TCD_CH_SBR_PAL_SHIFT               (15U)
#define EDMA3_TCD_CH_SBR_PAL_WIDTH               (1U)
#define EDMA3_TCD_CH_SBR_PAL(x)                  (((uint32_t)(((uint32_t)(x)) << EDMA3_TCD_CH_SBR_PAL_SHIFT)) & EDMA3_TCD_CH_SBR_PAL_MASK)

#define EDMA3_TCD_CH_SBR_EMI_MASK                (0x10000U)
#define EDMA3_TCD_CH_SBR_EMI_SHIFT               (16U)
#define EDMA3_TCD_CH_SBR_EMI_WIDTH               (1U)
#define EDMA3_TCD_CH_SBR_EMI(x)                  (((uint32_t)(((uint32_t)(x)) << EDMA3_TCD_CH_SBR_EMI_SHIFT)) & EDMA3_TCD_CH_SBR_EMI_MASK)

#define EDMA3_TCD_CH_SBR_ATTR_MASK               (0x7E0000U)  /* Merged from fields with different position or width, of widths (3, 6), largest definition used */
#define EDMA3_TCD_CH_SBR_ATTR_SHIFT              (17U)
#define EDMA3_TCD_CH_SBR_ATTR_WIDTH              (6U)
#define EDMA3_TCD_CH_SBR_ATTR(x)                 (((uint32_t)(((uint32_t)(x)) << EDMA3_TCD_CH_SBR_ATTR_SHIFT)) & EDMA3_TCD_CH_SBR_ATTR_MASK)  /* Merged from fields with different position or width, of widths (3, 6), largest definition used */
/*! @} */

/*! @name CH_PRI - Channel Priority */
/*! @{ */

#define EDMA3_TCD_CH_PRI_APL_MASK                (0x7U)
#define EDMA3_TCD_CH_PRI_APL_SHIFT               (0U)
#define EDMA3_TCD_CH_PRI_APL_WIDTH               (3U)
#define EDMA3_TCD_CH_PRI_APL(x)                  (((uint32_t)(((uint32_t)(x)) << EDMA3_TCD_CH_PRI_APL_SHIFT)) & EDMA3_TCD_CH_PRI_APL_MASK)

#define EDMA3_TCD_CH_PRI_DPA_MASK                (0x40000000U)
#define EDMA3_TCD_CH_PRI_DPA_SHIFT               (30U)
#define EDMA3_TCD_CH_PRI_DPA_WIDTH               (1U)
#define EDMA3_TCD_CH_PRI_DPA(x)                  (((uint32_t)(((uint32_t)(x)) << EDMA3_TCD_CH_PRI_DPA_SHIFT)) & EDMA3_TCD_CH_PRI_DPA_MASK)

#define EDMA3_TCD_CH_PRI_ECP_MASK                (0x80000000U)
#define EDMA3_TCD_CH_PRI_ECP_SHIFT               (31U)
#define EDMA3_TCD_CH_PRI_ECP_WIDTH               (1U)
#define EDMA3_TCD_CH_PRI_ECP(x)                  (((uint32_t)(((uint32_t)(x)) << EDMA3_TCD_CH_PRI_ECP_SHIFT)) & EDMA3_TCD_CH_PRI_ECP_MASK)
/*! @} */

/*! @name SADDR - TCD Source Address */
/*! @{ */

#define EDMA3_TCD_SADDR_SADDR_MASK               (0xFFFFFFFFU)
#define EDMA3_TCD_SADDR_SADDR_SHIFT              (0U)
#define EDMA3_TCD_SADDR_SADDR_WIDTH              (32U)
#define EDMA3_TCD_SADDR_SADDR(x)                 (((uint32_t)(((uint32_t)(x)) << EDMA3_TCD_SADDR_SADDR_SHIFT)) & EDMA3_TCD_SADDR_SADDR_MASK)
/*! @} */

/*! @name SOFF - TCD Signed Source Address Offset */
/*! @{ */

#define EDMA3_TCD_SOFF_SOFF_MASK                 (0xFFFFU)
#define EDMA3_TCD_SOFF_SOFF_SHIFT                (0U)
#define EDMA3_TCD_SOFF_SOFF_WIDTH                (16U)
#define EDMA3_TCD_SOFF_SOFF(x)                   (((uint16_t)(((uint16_t)(x)) << EDMA3_TCD_SOFF_SOFF_SHIFT)) & EDMA3_TCD_SOFF_SOFF_MASK)
/*! @} */

/*! @name ATTR - TCD Transfer Attributes */
/*! @{ */

#define EDMA3_TCD_ATTR_DSIZE_MASK                (0x7U)
#define EDMA3_TCD_ATTR_DSIZE_SHIFT               (0U)
#define EDMA3_TCD_ATTR_DSIZE_WIDTH               (3U)
#define EDMA3_TCD_ATTR_DSIZE(x)                  (((uint16_t)(((uint16_t)(x)) << EDMA3_TCD_ATTR_DSIZE_SHIFT)) & EDMA3_TCD_ATTR_DSIZE_MASK)

#define EDMA3_TCD_ATTR_DMOD_MASK                 (0xF8U)
#define EDMA3_TCD_ATTR_DMOD_SHIFT                (3U)
#define EDMA3_TCD_ATTR_DMOD_WIDTH                (5U)
#define EDMA3_TCD_ATTR_DMOD(x)                   (((uint16_t)(((uint16_t)(x)) << EDMA3_TCD_ATTR_DMOD_SHIFT)) & EDMA3_TCD_ATTR_DMOD_MASK)

#define EDMA3_TCD_ATTR_SSIZE_MASK                (0x700U)
#define EDMA3_TCD_ATTR_SSIZE_SHIFT               (8U)
#define EDMA3_TCD_ATTR_SSIZE_WIDTH               (3U)
#define EDMA3_TCD_ATTR_SSIZE(x)                  (((uint16_t)(((uint16_t)(x)) << EDMA3_TCD_ATTR_SSIZE_SHIFT)) & EDMA3_TCD_ATTR_SSIZE_MASK)

#define EDMA3_TCD_ATTR_SMOD_MASK                 (0xF800U)
#define EDMA3_TCD_ATTR_SMOD_SHIFT                (11U)
#define EDMA3_TCD_ATTR_SMOD_WIDTH                (5U)
#define EDMA3_TCD_ATTR_SMOD(x)                   (((uint16_t)(((uint16_t)(x)) << EDMA3_TCD_ATTR_SMOD_SHIFT)) & EDMA3_TCD_ATTR_SMOD_MASK)
/*! @} */

/*! @name NBYTES_MLOFFNO - TCD Transfer Size Without Minor Loop Offsets */
/*! @{ */

#define EDMA3_TCD_NBYTES_MLOFFNO_NBYTES_MASK     (0x3FFFFFFFU)
#define EDMA3_TCD_NBYTES_MLOFFNO_NBYTES_SHIFT    (0U)
#define EDMA3_TCD_NBYTES_MLOFFNO_NBYTES_WIDTH    (30U)
#define EDMA3_TCD_NBYTES_MLOFFNO_NBYTES(x)       (((uint32_t)(((uint32_t)(x)) << EDMA3_TCD_NBYTES_MLOFFNO_NBYTES_SHIFT)) & EDMA3_TCD_NBYTES_MLOFFNO_NBYTES_MASK)

#define EDMA3_TCD_NBYTES_MLOFFNO_DMLOE_MASK      (0x40000000U)
#define EDMA3_TCD_NBYTES_MLOFFNO_DMLOE_SHIFT     (30U)
#define EDMA3_TCD_NBYTES_MLOFFNO_DMLOE_WIDTH     (1U)
#define EDMA3_TCD_NBYTES_MLOFFNO_DMLOE(x)        (((uint32_t)(((uint32_t)(x)) << EDMA3_TCD_NBYTES_MLOFFNO_DMLOE_SHIFT)) & EDMA3_TCD_NBYTES_MLOFFNO_DMLOE_MASK)

#define EDMA3_TCD_NBYTES_MLOFFNO_SMLOE_MASK      (0x80000000U)
#define EDMA3_TCD_NBYTES_MLOFFNO_SMLOE_SHIFT     (31U)
#define EDMA3_TCD_NBYTES_MLOFFNO_SMLOE_WIDTH     (1U)
#define EDMA3_TCD_NBYTES_MLOFFNO_SMLOE(x)        (((uint32_t)(((uint32_t)(x)) << EDMA3_TCD_NBYTES_MLOFFNO_SMLOE_SHIFT)) & EDMA3_TCD_NBYTES_MLOFFNO_SMLOE_MASK)
/*! @} */

/*! @name NBYTES_MLOFFYES - TCD Transfer Size with Minor Loop Offsets */
/*! @{ */

#define EDMA3_TCD_NBYTES_MLOFFYES_NBYTES_MASK    (0x3FFU)
#define EDMA3_TCD_NBYTES_MLOFFYES_NBYTES_SHIFT   (0U)
#define EDMA3_TCD_NBYTES_MLOFFYES_NBYTES_WIDTH   (10U)
#define EDMA3_TCD_NBYTES_MLOFFYES_NBYTES(x)      (((uint32_t)(((uint32_t)(x)) << EDMA3_TCD_NBYTES_MLOFFYES_NBYTES_SHIFT)) & EDMA3_TCD_NBYTES_MLOFFYES_NBYTES_MASK)

#define EDMA3_TCD_NBYTES_MLOFFYES_MLOFF_MASK     (0x3FFFFC00U)
#define EDMA3_TCD_NBYTES_MLOFFYES_MLOFF_SHIFT    (10U)
#define EDMA3_TCD_NBYTES_MLOFFYES_MLOFF_WIDTH    (20U)
#define EDMA3_TCD_NBYTES_MLOFFYES_MLOFF(x)       (((uint32_t)(((uint32_t)(x)) << EDMA3_TCD_NBYTES_MLOFFYES_MLOFF_SHIFT)) & EDMA3_TCD_NBYTES_MLOFFYES_MLOFF_MASK)

#define EDMA3_TCD_NBYTES_MLOFFYES_DMLOE_MASK     (0x40000000U)
#define EDMA3_TCD_NBYTES_MLOFFYES_DMLOE_SHIFT    (30U)
#define EDMA3_TCD_NBYTES_MLOFFYES_DMLOE_WIDTH    (1U)
#define EDMA3_TCD_NBYTES_MLOFFYES_DMLOE(x)       (((uint32_t)(((uint32_t)(x)) << EDMA3_TCD_NBYTES_MLOFFYES_DMLOE_SHIFT)) & EDMA3_TCD_NBYTES_MLOFFYES_DMLOE_MASK)

#define EDMA3_TCD_NBYTES_MLOFFYES_SMLOE_MASK     (0x80000000U)
#define EDMA3_TCD_NBYTES_MLOFFYES_SMLOE_SHIFT    (31U)
#define EDMA3_TCD_NBYTES_MLOFFYES_SMLOE_WIDTH    (1U)
#define EDMA3_TCD_NBYTES_MLOFFYES_SMLOE(x)       (((uint32_t)(((uint32_t)(x)) << EDMA3_TCD_NBYTES_MLOFFYES_SMLOE_SHIFT)) & EDMA3_TCD_NBYTES_MLOFFYES_SMLOE_MASK)
/*! @} */

/*! @name SLAST_SDA - TCD Last Source Address Adjustment / Store DADDR Address */
/*! @{ */

#define EDMA3_TCD_SLAST_SDA_SLAST_SDA_MASK       (0xFFFFFFFFU)
#define EDMA3_TCD_SLAST_SDA_SLAST_SDA_SHIFT      (0U)
#define EDMA3_TCD_SLAST_SDA_SLAST_SDA_WIDTH      (32U)
#define EDMA3_TCD_SLAST_SDA_SLAST_SDA(x)         (((uint32_t)(((uint32_t)(x)) << EDMA3_TCD_SLAST_SDA_SLAST_SDA_SHIFT)) & EDMA3_TCD_SLAST_SDA_SLAST_SDA_MASK)
/*! @} */

/*! @name DADDR - TCD Destination Address */
/*! @{ */

#define EDMA3_TCD_DADDR_DADDR_MASK               (0xFFFFFFFFU)
#define EDMA3_TCD_DADDR_DADDR_SHIFT              (0U)
#define EDMA3_TCD_DADDR_DADDR_WIDTH              (32U)
#define EDMA3_TCD_DADDR_DADDR(x)                 (((uint32_t)(((uint32_t)(x)) << EDMA3_TCD_DADDR_DADDR_SHIFT)) & EDMA3_TCD_DADDR_DADDR_MASK)
/*! @} */

/*! @name DOFF - TCD Signed Destination Address Offset */
/*! @{ */

#define EDMA3_TCD_DOFF_DOFF_MASK                 (0xFFFFU)
#define EDMA3_TCD_DOFF_DOFF_SHIFT                (0U)
#define EDMA3_TCD_DOFF_DOFF_WIDTH                (16U)
#define EDMA3_TCD_DOFF_DOFF(x)                   (((uint16_t)(((uint16_t)(x)) << EDMA3_TCD_DOFF_DOFF_SHIFT)) & EDMA3_TCD_DOFF_DOFF_MASK)
/*! @} */

/*! @name CITER_ELINKNO - TCD Current Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define EDMA3_TCD_CITER_ELINKNO_CITER_MASK       (0x7FFFU)
#define EDMA3_TCD_CITER_ELINKNO_CITER_SHIFT      (0U)
#define EDMA3_TCD_CITER_ELINKNO_CITER_WIDTH      (15U)
#define EDMA3_TCD_CITER_ELINKNO_CITER(x)         (((uint16_t)(((uint16_t)(x)) << EDMA3_TCD_CITER_ELINKNO_CITER_SHIFT)) & EDMA3_TCD_CITER_ELINKNO_CITER_MASK)

#define EDMA3_TCD_CITER_ELINKNO_ELINK_MASK       (0x8000U)
#define EDMA3_TCD_CITER_ELINKNO_ELINK_SHIFT      (15U)
#define EDMA3_TCD_CITER_ELINKNO_ELINK_WIDTH      (1U)
#define EDMA3_TCD_CITER_ELINKNO_ELINK(x)         (((uint16_t)(((uint16_t)(x)) << EDMA3_TCD_CITER_ELINKNO_ELINK_SHIFT)) & EDMA3_TCD_CITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name CITER_ELINKYES - TCD Current Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define EDMA3_TCD_CITER_ELINKYES_CITER_MASK      (0x1FFU)
#define EDMA3_TCD_CITER_ELINKYES_CITER_SHIFT     (0U)
#define EDMA3_TCD_CITER_ELINKYES_CITER_WIDTH     (9U)
#define EDMA3_TCD_CITER_ELINKYES_CITER(x)        (((uint16_t)(((uint16_t)(x)) << EDMA3_TCD_CITER_ELINKYES_CITER_SHIFT)) & EDMA3_TCD_CITER_ELINKYES_CITER_MASK)

#define EDMA3_TCD_CITER_ELINKYES_LINKCH_MASK     (0x3E00U)  /* Merged from fields with different position or width, of widths (4, 5), largest definition used */
#define EDMA3_TCD_CITER_ELINKYES_LINKCH_SHIFT    (9U)
#define EDMA3_TCD_CITER_ELINKYES_LINKCH_WIDTH    (5U)
#define EDMA3_TCD_CITER_ELINKYES_LINKCH(x)       (((uint16_t)(((uint16_t)(x)) << EDMA3_TCD_CITER_ELINKYES_LINKCH_SHIFT)) & EDMA3_TCD_CITER_ELINKYES_LINKCH_MASK)  /* Merged from fields with different position or width, of widths (4, 5), largest definition used */

#define EDMA3_TCD_CITER_ELINKYES_ELINK_MASK      (0x8000U)
#define EDMA3_TCD_CITER_ELINKYES_ELINK_SHIFT     (15U)
#define EDMA3_TCD_CITER_ELINKYES_ELINK_WIDTH     (1U)
#define EDMA3_TCD_CITER_ELINKYES_ELINK(x)        (((uint16_t)(((uint16_t)(x)) << EDMA3_TCD_CITER_ELINKYES_ELINK_SHIFT)) & EDMA3_TCD_CITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name DLAST_SGA - TCD Last Destination Address Adjustment / Scatter Gather Address */
/*! @{ */

#define EDMA3_TCD_DLAST_SGA_DLAST_SGA_MASK       (0xFFFFFFFFU)
#define EDMA3_TCD_DLAST_SGA_DLAST_SGA_SHIFT      (0U)
#define EDMA3_TCD_DLAST_SGA_DLAST_SGA_WIDTH      (32U)
#define EDMA3_TCD_DLAST_SGA_DLAST_SGA(x)         (((uint32_t)(((uint32_t)(x)) << EDMA3_TCD_DLAST_SGA_DLAST_SGA_SHIFT)) & EDMA3_TCD_DLAST_SGA_DLAST_SGA_MASK)
/*! @} */

/*! @name CSR - TCD Control and Status */
/*! @{ */

#define EDMA3_TCD_CSR_START_MASK                 (0x1U)
#define EDMA3_TCD_CSR_START_SHIFT                (0U)
#define EDMA3_TCD_CSR_START_WIDTH                (1U)
#define EDMA3_TCD_CSR_START(x)                   (((uint16_t)(((uint16_t)(x)) << EDMA3_TCD_CSR_START_SHIFT)) & EDMA3_TCD_CSR_START_MASK)

#define EDMA3_TCD_CSR_INTMAJOR_MASK              (0x2U)
#define EDMA3_TCD_CSR_INTMAJOR_SHIFT             (1U)
#define EDMA3_TCD_CSR_INTMAJOR_WIDTH             (1U)
#define EDMA3_TCD_CSR_INTMAJOR(x)                (((uint16_t)(((uint16_t)(x)) << EDMA3_TCD_CSR_INTMAJOR_SHIFT)) & EDMA3_TCD_CSR_INTMAJOR_MASK)

#define EDMA3_TCD_CSR_INTHALF_MASK               (0x4U)
#define EDMA3_TCD_CSR_INTHALF_SHIFT              (2U)
#define EDMA3_TCD_CSR_INTHALF_WIDTH              (1U)
#define EDMA3_TCD_CSR_INTHALF(x)                 (((uint16_t)(((uint16_t)(x)) << EDMA3_TCD_CSR_INTHALF_SHIFT)) & EDMA3_TCD_CSR_INTHALF_MASK)

#define EDMA3_TCD_CSR_DREQ_MASK                  (0x8U)
#define EDMA3_TCD_CSR_DREQ_SHIFT                 (3U)
#define EDMA3_TCD_CSR_DREQ_WIDTH                 (1U)
#define EDMA3_TCD_CSR_DREQ(x)                    (((uint16_t)(((uint16_t)(x)) << EDMA3_TCD_CSR_DREQ_SHIFT)) & EDMA3_TCD_CSR_DREQ_MASK)

#define EDMA3_TCD_CSR_ESG_MASK                   (0x10U)
#define EDMA3_TCD_CSR_ESG_SHIFT                  (4U)
#define EDMA3_TCD_CSR_ESG_WIDTH                  (1U)
#define EDMA3_TCD_CSR_ESG(x)                     (((uint16_t)(((uint16_t)(x)) << EDMA3_TCD_CSR_ESG_SHIFT)) & EDMA3_TCD_CSR_ESG_MASK)

#define EDMA3_TCD_CSR_MAJORELINK_MASK            (0x20U)
#define EDMA3_TCD_CSR_MAJORELINK_SHIFT           (5U)
#define EDMA3_TCD_CSR_MAJORELINK_WIDTH           (1U)
#define EDMA3_TCD_CSR_MAJORELINK(x)              (((uint16_t)(((uint16_t)(x)) << EDMA3_TCD_CSR_MAJORELINK_SHIFT)) & EDMA3_TCD_CSR_MAJORELINK_MASK)

#define EDMA3_TCD_CSR_ESDA_MASK                  (0x80U)
#define EDMA3_TCD_CSR_ESDA_SHIFT                 (7U)
#define EDMA3_TCD_CSR_ESDA_WIDTH                 (1U)
#define EDMA3_TCD_CSR_ESDA(x)                    (((uint16_t)(((uint16_t)(x)) << EDMA3_TCD_CSR_ESDA_SHIFT)) & EDMA3_TCD_CSR_ESDA_MASK)

#define EDMA3_TCD_CSR_MAJORLINKCH_MASK           (0x1F00U)  /* Merged from fields with different position or width, of widths (4, 5), largest definition used */
#define EDMA3_TCD_CSR_MAJORLINKCH_SHIFT          (8U)
#define EDMA3_TCD_CSR_MAJORLINKCH_WIDTH          (5U)
#define EDMA3_TCD_CSR_MAJORLINKCH(x)             (((uint16_t)(((uint16_t)(x)) << EDMA3_TCD_CSR_MAJORLINKCH_SHIFT)) & EDMA3_TCD_CSR_MAJORLINKCH_MASK)  /* Merged from fields with different position or width, of widths (4, 5), largest definition used */

#define EDMA3_TCD_CSR_BWC_MASK                   (0xC000U)
#define EDMA3_TCD_CSR_BWC_SHIFT                  (14U)
#define EDMA3_TCD_CSR_BWC_WIDTH                  (2U)
#define EDMA3_TCD_CSR_BWC(x)                     (((uint16_t)(((uint16_t)(x)) << EDMA3_TCD_CSR_BWC_SHIFT)) & EDMA3_TCD_CSR_BWC_MASK)
/*! @} */

/*! @name BITER_ELINKNO - TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define EDMA3_TCD_BITER_ELINKNO_BITER_MASK       (0x7FFFU)
#define EDMA3_TCD_BITER_ELINKNO_BITER_SHIFT      (0U)
#define EDMA3_TCD_BITER_ELINKNO_BITER_WIDTH      (15U)
#define EDMA3_TCD_BITER_ELINKNO_BITER(x)         (((uint16_t)(((uint16_t)(x)) << EDMA3_TCD_BITER_ELINKNO_BITER_SHIFT)) & EDMA3_TCD_BITER_ELINKNO_BITER_MASK)

#define EDMA3_TCD_BITER_ELINKNO_ELINK_MASK       (0x8000U)
#define EDMA3_TCD_BITER_ELINKNO_ELINK_SHIFT      (15U)
#define EDMA3_TCD_BITER_ELINKNO_ELINK_WIDTH      (1U)
#define EDMA3_TCD_BITER_ELINKNO_ELINK(x)         (((uint16_t)(((uint16_t)(x)) << EDMA3_TCD_BITER_ELINKNO_ELINK_SHIFT)) & EDMA3_TCD_BITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name BITER_ELINKYES - TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define EDMA3_TCD_BITER_ELINKYES_BITER_MASK      (0x1FFU)
#define EDMA3_TCD_BITER_ELINKYES_BITER_SHIFT     (0U)
#define EDMA3_TCD_BITER_ELINKYES_BITER_WIDTH     (9U)
#define EDMA3_TCD_BITER_ELINKYES_BITER(x)        (((uint16_t)(((uint16_t)(x)) << EDMA3_TCD_BITER_ELINKYES_BITER_SHIFT)) & EDMA3_TCD_BITER_ELINKYES_BITER_MASK)

#define EDMA3_TCD_BITER_ELINKYES_LINKCH_MASK     (0x3E00U)  /* Merged from fields with different position or width, of widths (4, 5), largest definition used */
#define EDMA3_TCD_BITER_ELINKYES_LINKCH_SHIFT    (9U)
#define EDMA3_TCD_BITER_ELINKYES_LINKCH_WIDTH    (5U)
#define EDMA3_TCD_BITER_ELINKYES_LINKCH(x)       (((uint16_t)(((uint16_t)(x)) << EDMA3_TCD_BITER_ELINKYES_LINKCH_SHIFT)) & EDMA3_TCD_BITER_ELINKYES_LINKCH_MASK)  /* Merged from fields with different position or width, of widths (4, 5), largest definition used */

#define EDMA3_TCD_BITER_ELINKYES_ELINK_MASK      (0x8000U)
#define EDMA3_TCD_BITER_ELINKYES_ELINK_SHIFT     (15U)
#define EDMA3_TCD_BITER_ELINKYES_ELINK_WIDTH     (1U)
#define EDMA3_TCD_BITER_ELINKYES_ELINK(x)        (((uint16_t)(((uint16_t)(x)) << EDMA3_TCD_BITER_ELINKYES_ELINK_SHIFT)) & EDMA3_TCD_BITER_ELINKYES_ELINK_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group EDMA3_TCD_Register_Masks */

/*!
 * @}
 */ /* end of group EDMA3_TCD_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_EDMA3_TCD_H_) */
