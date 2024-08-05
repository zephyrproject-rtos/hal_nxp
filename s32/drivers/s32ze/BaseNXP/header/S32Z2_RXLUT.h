/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_RXLUT.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_RXLUT
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
#if !defined(S32Z2_RXLUT_H_)  /* Check if memory map has not been already included */
#define S32Z2_RXLUT_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- RXLUT Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RXLUT_Peripheral_Access_Layer RXLUT Peripheral Access Layer
 * @{
 */

/** RXLUT - Size of Registers Arrays */
#define RXLUT_RLSOIXR_COUNT                       12u
#define RXLUT_RLSOFSR_COUNT                       2u
#define RXLUT_RLICEC_COUNT                        2u

/** RXLUT - Register Layout Typedef */
typedef struct {
  __IO uint32_t RLCR;                              /**< RXLUT Configuration, offset: 0x0 */
  __IO uint32_t RLSR;                              /**< RXLUT Status, offset: 0x4 */
  __IO uint32_t RLSRIER;                           /**< RXLUT Search Result Interrupt Enable, offset: 0x8 */
  __I  uint32_t RLSRSR;                            /**< RXLUT Search Result Status, offset: 0xC */
  __IO uint32_t RLFIMER;                           /**< RXLUT Frame ID End, offset: 0x10 */
  __IO uint32_t RLFISR;                            /**< RXLUT Frame ID Start, offset: 0x14 */
  __IO uint32_t RLCIXR;                            /**< RXLUT Channel ID AND Index, offset: 0x18 */
  __IO uint32_t RLADRCR;                           /**< RXLUT Address and Command, offset: 0x1C */
  __I  uint32_t RLFIMESR;                          /**< RXLUT Frame ID End Status, offset: 0x20 */
  __I  uint32_t RLFISSR;                           /**< RXLUT Frame ID Start Status, offset: 0x24 */
  __I  uint32_t RLCIXSR;                           /**< RXLUT Channel ID AND Index Status, offset: 0x28 */
  __I  uint32_t RLADRSR;                           /**< RXLUT Address Status, offset: 0x2C */
  uint8_t RESERVED_0[16];
  __IO uint32_t RLSICR;                            /**< RXLUT Search Input Command, offset: 0x40 */
  __IO uint32_t RLSICFIR;                          /**< RXLUT Search Input Command Frame ID, offset: 0x44 */
  struct RXLUT_RLSOIXR {                           /* offset: 0x48, array step: 0x8 */
    __I  uint32_t RLSOIXR;                           /**< RXLUT Search Output, array offset: 0x48, array step: 0x8 */
    __I  uint32_t RLSOADR;                           /**< RXLUT Search Output Address, array offset: 0x4C, array step: 0x8 */
  } RLSOIXR[RXLUT_RLSOIXR_COUNT];
  uint8_t RESERVED_1[168];
  __I  uint32_t RLSICFSR;                          /**< RXLUT Search Input Command FIFO Status, offset: 0x150 */
  __I  uint32_t RLSOFSR[RXLUT_RLSOFSR_COUNT];      /**< RXLUT Search Output FIFO Status, array offset: 0x154, array step: 0x4 */
  __I  uint32_t RLICEC[RXLUT_RLICEC_COUNT];        /**< RXLUT Input Command Entry Counter, array offset: 0x15C, array step: 0x4 */
  __IO uint32_t RLER;                              /**< RXLUT Error, offset: 0x164 */
  __IO uint32_t RLOOR;                             /**< RXLUT Output Overflow, offset: 0x168 */
} RXLUT_Type, *RXLUT_MemMapPtr;

/** Number of instances of the RXLUT module. */
#define RXLUT_INSTANCE_COUNT                     (1u)

/* RXLUT - Peripheral instance base addresses */
/** Peripheral CE_RXLUT base address */
#define IP_CE_RXLUT_BASE                         (0x4488C000u)
/** Peripheral CE_RXLUT base pointer */
#define IP_CE_RXLUT                              ((RXLUT_Type *)IP_CE_RXLUT_BASE)
/** Array initializer of RXLUT peripheral base addresses */
#define IP_RXLUT_BASE_ADDRS                      { IP_CE_RXLUT_BASE }
/** Array initializer of RXLUT peripheral base pointers */
#define IP_RXLUT_BASE_PTRS                       { IP_CE_RXLUT }

/* ----------------------------------------------------------------------------
   -- RXLUT Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RXLUT_Register_Masks RXLUT Register Masks
 * @{
 */

/*! @name RLCR - RXLUT Configuration */
/*! @{ */

#define RXLUT_RLCR_RXLEN_MASK                    (0x1U)
#define RXLUT_RLCR_RXLEN_SHIFT                   (0U)
#define RXLUT_RLCR_RXLEN_WIDTH                   (1U)
#define RXLUT_RLCR_RXLEN(x)                      (((uint32_t)(((uint32_t)(x)) << RXLUT_RLCR_RXLEN_SHIFT)) & RXLUT_RLCR_RXLEN_MASK)

#define RXLUT_RLCR_SRCH_EN_MASK                  (0x2U)
#define RXLUT_RLCR_SRCH_EN_SHIFT                 (1U)
#define RXLUT_RLCR_SRCH_EN_WIDTH                 (1U)
#define RXLUT_RLCR_SRCH_EN(x)                    (((uint32_t)(((uint32_t)(x)) << RXLUT_RLCR_SRCH_EN_SHIFT)) & RXLUT_RLCR_SRCH_EN_MASK)

#define RXLUT_RLCR_PS_EN_MASK                    (0x4U)
#define RXLUT_RLCR_PS_EN_SHIFT                   (2U)
#define RXLUT_RLCR_PS_EN_WIDTH                   (1U)
#define RXLUT_RLCR_PS_EN(x)                      (((uint32_t)(((uint32_t)(x)) << RXLUT_RLCR_PS_EN_SHIFT)) & RXLUT_RLCR_PS_EN_MASK)

#define RXLUT_RLCR_SOVR_MASK                     (0x8U)
#define RXLUT_RLCR_SOVR_SHIFT                    (3U)
#define RXLUT_RLCR_SOVR_WIDTH                    (1U)
#define RXLUT_RLCR_SOVR(x)                       (((uint32_t)(((uint32_t)(x)) << RXLUT_RLCR_SOVR_SHIFT)) & RXLUT_RLCR_SOVR_MASK)

#define RXLUT_RLCR_FLUSH_MASK                    (0x10U)
#define RXLUT_RLCR_FLUSH_SHIFT                   (4U)
#define RXLUT_RLCR_FLUSH_WIDTH                   (1U)
#define RXLUT_RLCR_FLUSH(x)                      (((uint32_t)(((uint32_t)(x)) << RXLUT_RLCR_FLUSH_SHIFT)) & RXLUT_RLCR_FLUSH_MASK)

#define RXLUT_RLCR_ECC_EN_MASK                   (0x20U)
#define RXLUT_RLCR_ECC_EN_SHIFT                  (5U)
#define RXLUT_RLCR_ECC_EN_WIDTH                  (1U)
#define RXLUT_RLCR_ECC_EN(x)                     (((uint32_t)(((uint32_t)(x)) << RXLUT_RLCR_ECC_EN_SHIFT)) & RXLUT_RLCR_ECC_EN_MASK)

#define RXLUT_RLCR_FID_RAR_EN_MASK               (0x40U)
#define RXLUT_RLCR_FID_RAR_EN_SHIFT              (6U)
#define RXLUT_RLCR_FID_RAR_EN_WIDTH              (1U)
#define RXLUT_RLCR_FID_RAR_EN(x)                 (((uint32_t)(((uint32_t)(x)) << RXLUT_RLCR_FID_RAR_EN_SHIFT)) & RXLUT_RLCR_FID_RAR_EN_MASK)
/*! @} */

/*! @name RLSR - RXLUT Status */
/*! @{ */

#define RXLUT_RLSR_BUSY_MASK                     (0x1U)
#define RXLUT_RLSR_BUSY_SHIFT                    (0U)
#define RXLUT_RLSR_BUSY_WIDTH                    (1U)
#define RXLUT_RLSR_BUSY(x)                       (((uint32_t)(((uint32_t)(x)) << RXLUT_RLSR_BUSY_SHIFT)) & RXLUT_RLSR_BUSY_MASK)

#define RXLUT_RLSR_FLUSH_MASK                    (0x2U)
#define RXLUT_RLSR_FLUSH_SHIFT                   (1U)
#define RXLUT_RLSR_FLUSH_WIDTH                   (1U)
#define RXLUT_RLSR_FLUSH(x)                      (((uint32_t)(((uint32_t)(x)) << RXLUT_RLSR_FLUSH_SHIFT)) & RXLUT_RLSR_FLUSH_MASK)

#define RXLUT_RLSR_PENDS_MASK                    (0x4U)
#define RXLUT_RLSR_PENDS_SHIFT                   (2U)
#define RXLUT_RLSR_PENDS_WIDTH                   (1U)
#define RXLUT_RLSR_PENDS(x)                      (((uint32_t)(((uint32_t)(x)) << RXLUT_RLSR_PENDS_SHIFT)) & RXLUT_RLSR_PENDS_MASK)

#define RXLUT_RLSR_MS_MASK                       (0x8U)
#define RXLUT_RLSR_MS_SHIFT                      (3U)
#define RXLUT_RLSR_MS_WIDTH                      (1U)
#define RXLUT_RLSR_MS(x)                         (((uint32_t)(((uint32_t)(x)) << RXLUT_RLSR_MS_SHIFT)) & RXLUT_RLSR_MS_MASK)

#define RXLUT_RLSR_CIE_MASK                      (0x10U)
#define RXLUT_RLSR_CIE_SHIFT                     (4U)
#define RXLUT_RLSR_CIE_WIDTH                     (1U)
#define RXLUT_RLSR_CIE(x)                        (((uint32_t)(((uint32_t)(x)) << RXLUT_RLSR_CIE_SHIFT)) & RXLUT_RLSR_CIE_MASK)
/*! @} */

/*! @name RLSRIER - RXLUT Search Result Interrupt Enable */
/*! @{ */

#define RXLUT_RLSRIER_AVLIE_MASK                 (0xFFFU)
#define RXLUT_RLSRIER_AVLIE_SHIFT                (0U)
#define RXLUT_RLSRIER_AVLIE_WIDTH                (12U)
#define RXLUT_RLSRIER_AVLIE(x)                   (((uint32_t)(((uint32_t)(x)) << RXLUT_RLSRIER_AVLIE_SHIFT)) & RXLUT_RLSRIER_AVLIE_MASK)

#define RXLUT_RLSRIER_PS_AVLIE_MASK              (0x10000000U)
#define RXLUT_RLSRIER_PS_AVLIE_SHIFT             (28U)
#define RXLUT_RLSRIER_PS_AVLIE_WIDTH             (1U)
#define RXLUT_RLSRIER_PS_AVLIE(x)                (((uint32_t)(((uint32_t)(x)) << RXLUT_RLSRIER_PS_AVLIE_SHIFT)) & RXLUT_RLSRIER_PS_AVLIE_MASK)
/*! @} */

/*! @name RLSRSR - RXLUT Search Result Status */
/*! @{ */

#define RXLUT_RLSRSR_AVL_MASK                    (0xFFFU)
#define RXLUT_RLSRSR_AVL_SHIFT                   (0U)
#define RXLUT_RLSRSR_AVL_WIDTH                   (12U)
#define RXLUT_RLSRSR_AVL(x)                      (((uint32_t)(((uint32_t)(x)) << RXLUT_RLSRSR_AVL_SHIFT)) & RXLUT_RLSRSR_AVL_MASK)

#define RXLUT_RLSRSR_PS_AVL_MASK                 (0x10000000U)
#define RXLUT_RLSRSR_PS_AVL_SHIFT                (28U)
#define RXLUT_RLSRSR_PS_AVL_WIDTH                (1U)
#define RXLUT_RLSRSR_PS_AVL(x)                   (((uint32_t)(((uint32_t)(x)) << RXLUT_RLSRSR_PS_AVL_SHIFT)) & RXLUT_RLSRSR_PS_AVL_MASK)
/*! @} */

/*! @name RLFIMER - RXLUT Frame ID End */
/*! @{ */

#define RXLUT_RLFIMER_FIME_MASK                  (0xFFFFFFFFU)
#define RXLUT_RLFIMER_FIME_SHIFT                 (0U)
#define RXLUT_RLFIMER_FIME_WIDTH                 (32U)
#define RXLUT_RLFIMER_FIME(x)                    (((uint32_t)(((uint32_t)(x)) << RXLUT_RLFIMER_FIME_SHIFT)) & RXLUT_RLFIMER_FIME_MASK)
/*! @} */

/*! @name RLFISR - RXLUT Frame ID Start */
/*! @{ */

#define RXLUT_RLFISR_FIS_MASK                    (0xFFFFFFFFU)
#define RXLUT_RLFISR_FIS_SHIFT                   (0U)
#define RXLUT_RLFISR_FIS_WIDTH                   (32U)
#define RXLUT_RLFISR_FIS(x)                      (((uint32_t)(((uint32_t)(x)) << RXLUT_RLFISR_FIS_SHIFT)) & RXLUT_RLFISR_FIS_MASK)
/*! @} */

/*! @name RLCIXR - RXLUT Channel ID AND Index */
/*! @{ */

#define RXLUT_RLCIXR_SRCH_MASK                   (0x1U)
#define RXLUT_RLCIXR_SRCH_SHIFT                  (0U)
#define RXLUT_RLCIXR_SRCH_WIDTH                  (1U)
#define RXLUT_RLCIXR_SRCH(x)                     (((uint32_t)(((uint32_t)(x)) << RXLUT_RLCIXR_SRCH_SHIFT)) & RXLUT_RLCIXR_SRCH_MASK)

#define RXLUT_RLCIXR_ENABLE_MASK                 (0x2U)
#define RXLUT_RLCIXR_ENABLE_SHIFT                (1U)
#define RXLUT_RLCIXR_ENABLE_WIDTH                (1U)
#define RXLUT_RLCIXR_ENABLE(x)                   (((uint32_t)(((uint32_t)(x)) << RXLUT_RLCIXR_ENABLE_SHIFT)) & RXLUT_RLCIXR_ENABLE_MASK)

#define RXLUT_RLCIXR_CID_MASK                    (0xFCU)
#define RXLUT_RLCIXR_CID_SHIFT                   (2U)
#define RXLUT_RLCIXR_CID_WIDTH                   (6U)
#define RXLUT_RLCIXR_CID(x)                      (((uint32_t)(((uint32_t)(x)) << RXLUT_RLCIXR_CID_SHIFT)) & RXLUT_RLCIXR_CID_MASK)

#define RXLUT_RLCIXR_CTRL_MASK                   (0x300U)
#define RXLUT_RLCIXR_CTRL_SHIFT                  (8U)
#define RXLUT_RLCIXR_CTRL_WIDTH                  (2U)
#define RXLUT_RLCIXR_CTRL(x)                     (((uint32_t)(((uint32_t)(x)) << RXLUT_RLCIXR_CTRL_SHIFT)) & RXLUT_RLCIXR_CTRL_MASK)

#define RXLUT_RLCIXR_INDX_MASK                   (0xFFFF0000U)
#define RXLUT_RLCIXR_INDX_SHIFT                  (16U)
#define RXLUT_RLCIXR_INDX_WIDTH                  (16U)
#define RXLUT_RLCIXR_INDX(x)                     (((uint32_t)(((uint32_t)(x)) << RXLUT_RLCIXR_INDX_SHIFT)) & RXLUT_RLCIXR_INDX_MASK)
/*! @} */

/*! @name RLADRCR - RXLUT Address and Command */
/*! @{ */

#define RXLUT_RLADRCR_ADDR_MASK                  (0xFFFFU)
#define RXLUT_RLADRCR_ADDR_SHIFT                 (0U)
#define RXLUT_RLADRCR_ADDR_WIDTH                 (16U)
#define RXLUT_RLADRCR_ADDR(x)                    (((uint32_t)(((uint32_t)(x)) << RXLUT_RLADRCR_ADDR_SHIFT)) & RXLUT_RLADRCR_ADDR_MASK)

#define RXLUT_RLADRCR_CMD_MASK                   (0x10000U)
#define RXLUT_RLADRCR_CMD_SHIFT                  (16U)
#define RXLUT_RLADRCR_CMD_WIDTH                  (1U)
#define RXLUT_RLADRCR_CMD(x)                     (((uint32_t)(((uint32_t)(x)) << RXLUT_RLADRCR_CMD_SHIFT)) & RXLUT_RLADRCR_CMD_MASK)
/*! @} */

/*! @name RLFIMESR - RXLUT Frame ID End Status */
/*! @{ */

#define RXLUT_RLFIMESR_FIMES_MASK                (0xFFFFFFFFU)
#define RXLUT_RLFIMESR_FIMES_SHIFT               (0U)
#define RXLUT_RLFIMESR_FIMES_WIDTH               (32U)
#define RXLUT_RLFIMESR_FIMES(x)                  (((uint32_t)(((uint32_t)(x)) << RXLUT_RLFIMESR_FIMES_SHIFT)) & RXLUT_RLFIMESR_FIMES_MASK)
/*! @} */

/*! @name RLFISSR - RXLUT Frame ID Start Status */
/*! @{ */

#define RXLUT_RLFISSR_FISS_MASK                  (0xFFFFFFFFU)
#define RXLUT_RLFISSR_FISS_SHIFT                 (0U)
#define RXLUT_RLFISSR_FISS_WIDTH                 (32U)
#define RXLUT_RLFISSR_FISS(x)                    (((uint32_t)(((uint32_t)(x)) << RXLUT_RLFISSR_FISS_SHIFT)) & RXLUT_RLFISSR_FISS_MASK)
/*! @} */

/*! @name RLCIXSR - RXLUT Channel ID AND Index Status */
/*! @{ */

#define RXLUT_RLCIXSR_ENABLE_MASK                (0x2U)
#define RXLUT_RLCIXSR_ENABLE_SHIFT               (1U)
#define RXLUT_RLCIXSR_ENABLE_WIDTH               (1U)
#define RXLUT_RLCIXSR_ENABLE(x)                  (((uint32_t)(((uint32_t)(x)) << RXLUT_RLCIXSR_ENABLE_SHIFT)) & RXLUT_RLCIXSR_ENABLE_MASK)

#define RXLUT_RLCIXSR_CIDS_MASK                  (0xFCU)
#define RXLUT_RLCIXSR_CIDS_SHIFT                 (2U)
#define RXLUT_RLCIXSR_CIDS_WIDTH                 (6U)
#define RXLUT_RLCIXSR_CIDS(x)                    (((uint32_t)(((uint32_t)(x)) << RXLUT_RLCIXSR_CIDS_SHIFT)) & RXLUT_RLCIXSR_CIDS_MASK)

#define RXLUT_RLCIXSR_CTRLS_MASK                 (0x300U)
#define RXLUT_RLCIXSR_CTRLS_SHIFT                (8U)
#define RXLUT_RLCIXSR_CTRLS_WIDTH                (2U)
#define RXLUT_RLCIXSR_CTRLS(x)                   (((uint32_t)(((uint32_t)(x)) << RXLUT_RLCIXSR_CTRLS_SHIFT)) & RXLUT_RLCIXSR_CTRLS_MASK)

#define RXLUT_RLCIXSR_INDXS_MASK                 (0xFFFF0000U)
#define RXLUT_RLCIXSR_INDXS_SHIFT                (16U)
#define RXLUT_RLCIXSR_INDXS_WIDTH                (16U)
#define RXLUT_RLCIXSR_INDXS(x)                   (((uint32_t)(((uint32_t)(x)) << RXLUT_RLCIXSR_INDXS_SHIFT)) & RXLUT_RLCIXSR_INDXS_MASK)
/*! @} */

/*! @name RLADRSR - RXLUT Address Status */
/*! @{ */

#define RXLUT_RLADRSR_ADDRS_MASK                 (0xFFFFU)
#define RXLUT_RLADRSR_ADDRS_SHIFT                (0U)
#define RXLUT_RLADRSR_ADDRS_WIDTH                (16U)
#define RXLUT_RLADRSR_ADDRS(x)                   (((uint32_t)(((uint32_t)(x)) << RXLUT_RLADRSR_ADDRS_SHIFT)) & RXLUT_RLADRSR_ADDRS_MASK)
/*! @} */

/*! @name RLSICR - RXLUT Search Input Command */
/*! @{ */

#define RXLUT_RLSICR_CID_MASK                    (0x3FU)
#define RXLUT_RLSICR_CID_SHIFT                   (0U)
#define RXLUT_RLSICR_CID_WIDTH                   (6U)
#define RXLUT_RLSICR_CID(x)                      (((uint32_t)(((uint32_t)(x)) << RXLUT_RLSICR_CID_SHIFT)) & RXLUT_RLSICR_CID_MASK)

#define RXLUT_RLSICR_SYNC_ID_MASK                (0x3FFF0000U)
#define RXLUT_RLSICR_SYNC_ID_SHIFT               (16U)
#define RXLUT_RLSICR_SYNC_ID_WIDTH               (14U)
#define RXLUT_RLSICR_SYNC_ID(x)                  (((uint32_t)(((uint32_t)(x)) << RXLUT_RLSICR_SYNC_ID_SHIFT)) & RXLUT_RLSICR_SYNC_ID_MASK)
/*! @} */

/*! @name RLSICFIR - RXLUT Search Input Command Frame ID */
/*! @{ */

#define RXLUT_RLSICFIR_FID_MASK                  (0xFFFFFFFFU)
#define RXLUT_RLSICFIR_FID_SHIFT                 (0U)
#define RXLUT_RLSICFIR_FID_WIDTH                 (32U)
#define RXLUT_RLSICFIR_FID(x)                    (((uint32_t)(((uint32_t)(x)) << RXLUT_RLSICFIR_FID_SHIFT)) & RXLUT_RLSICFIR_FID_MASK)
/*! @} */

/*! @name RLSOIXR - RXLUT Search Output */
/*! @{ */

#define RXLUT_RLSOIXR_MS_MASK                    (0x1U)
#define RXLUT_RLSOIXR_MS_SHIFT                   (0U)
#define RXLUT_RLSOIXR_MS_WIDTH                   (1U)
#define RXLUT_RLSOIXR_MS(x)                      (((uint32_t)(((uint32_t)(x)) << RXLUT_RLSOIXR_MS_SHIFT)) & RXLUT_RLSOIXR_MS_MASK)

#define RXLUT_RLSOIXR_ENABLE_MASK                (0x2U)
#define RXLUT_RLSOIXR_ENABLE_SHIFT               (1U)
#define RXLUT_RLSOIXR_ENABLE_WIDTH               (1U)
#define RXLUT_RLSOIXR_ENABLE(x)                  (((uint32_t)(((uint32_t)(x)) << RXLUT_RLSOIXR_ENABLE_SHIFT)) & RXLUT_RLSOIXR_ENABLE_MASK)

#define RXLUT_RLSOIXR_SYNC_ID_MASK               (0xFFFCU)
#define RXLUT_RLSOIXR_SYNC_ID_SHIFT              (2U)
#define RXLUT_RLSOIXR_SYNC_ID_WIDTH              (14U)
#define RXLUT_RLSOIXR_SYNC_ID(x)                 (((uint32_t)(((uint32_t)(x)) << RXLUT_RLSOIXR_SYNC_ID_SHIFT)) & RXLUT_RLSOIXR_SYNC_ID_MASK)

#define RXLUT_RLSOIXR_IDX_MASK                   (0xFFFF0000U)
#define RXLUT_RLSOIXR_IDX_SHIFT                  (16U)
#define RXLUT_RLSOIXR_IDX_WIDTH                  (16U)
#define RXLUT_RLSOIXR_IDX(x)                     (((uint32_t)(((uint32_t)(x)) << RXLUT_RLSOIXR_IDX_SHIFT)) & RXLUT_RLSOIXR_IDX_MASK)
/*! @} */

/*! @name RLSOADR - RXLUT Search Output Address */
/*! @{ */

#define RXLUT_RLSOADR_ADR_MASK                   (0xFFFFU)
#define RXLUT_RLSOADR_ADR_SHIFT                  (0U)
#define RXLUT_RLSOADR_ADR_WIDTH                  (16U)
#define RXLUT_RLSOADR_ADR(x)                     (((uint32_t)(((uint32_t)(x)) << RXLUT_RLSOADR_ADR_SHIFT)) & RXLUT_RLSOADR_ADR_MASK)
/*! @} */

/*! @name RLSICFSR - RXLUT Search Input Command FIFO Status */
/*! @{ */

#define RXLUT_RLSICFSR_EMPTY_MASK                (0x1U)
#define RXLUT_RLSICFSR_EMPTY_SHIFT               (0U)
#define RXLUT_RLSICFSR_EMPTY_WIDTH               (1U)
#define RXLUT_RLSICFSR_EMPTY(x)                  (((uint32_t)(((uint32_t)(x)) << RXLUT_RLSICFSR_EMPTY_SHIFT)) & RXLUT_RLSICFSR_EMPTY_MASK)

#define RXLUT_RLSICFSR_FULL_MASK                 (0x2U)
#define RXLUT_RLSICFSR_FULL_SHIFT                (1U)
#define RXLUT_RLSICFSR_FULL_WIDTH                (1U)
#define RXLUT_RLSICFSR_FULL(x)                   (((uint32_t)(((uint32_t)(x)) << RXLUT_RLSICFSR_FULL_SHIFT)) & RXLUT_RLSICFSR_FULL_MASK)
/*! @} */

/*! @name RLSOFSR - RXLUT Search Output FIFO Status */
/*! @{ */

#define RXLUT_RLSOFSR_EMPTY0_MASK                (0x1U)
#define RXLUT_RLSOFSR_EMPTY0_SHIFT               (0U)
#define RXLUT_RLSOFSR_EMPTY0_WIDTH               (1U)
#define RXLUT_RLSOFSR_EMPTY0(x)                  (((uint32_t)(((uint32_t)(x)) << RXLUT_RLSOFSR_EMPTY0_SHIFT)) & RXLUT_RLSOFSR_EMPTY0_MASK)

#define RXLUT_RLSOFSR_FULL0_MASK                 (0x2U)
#define RXLUT_RLSOFSR_FULL0_SHIFT                (1U)
#define RXLUT_RLSOFSR_FULL0_WIDTH                (1U)
#define RXLUT_RLSOFSR_FULL0(x)                   (((uint32_t)(((uint32_t)(x)) << RXLUT_RLSOFSR_FULL0_SHIFT)) & RXLUT_RLSOFSR_FULL0_MASK)

#define RXLUT_RLSOFSR_EMPTY1_MASK                (0x10U)
#define RXLUT_RLSOFSR_EMPTY1_SHIFT               (4U)
#define RXLUT_RLSOFSR_EMPTY1_WIDTH               (1U)
#define RXLUT_RLSOFSR_EMPTY1(x)                  (((uint32_t)(((uint32_t)(x)) << RXLUT_RLSOFSR_EMPTY1_SHIFT)) & RXLUT_RLSOFSR_EMPTY1_MASK)

#define RXLUT_RLSOFSR_FULL1_MASK                 (0x20U)
#define RXLUT_RLSOFSR_FULL1_SHIFT                (5U)
#define RXLUT_RLSOFSR_FULL1_WIDTH                (1U)
#define RXLUT_RLSOFSR_FULL1(x)                   (((uint32_t)(((uint32_t)(x)) << RXLUT_RLSOFSR_FULL1_SHIFT)) & RXLUT_RLSOFSR_FULL1_MASK)

#define RXLUT_RLSOFSR_EMPTY2_MASK                (0x100U)
#define RXLUT_RLSOFSR_EMPTY2_SHIFT               (8U)
#define RXLUT_RLSOFSR_EMPTY2_WIDTH               (1U)
#define RXLUT_RLSOFSR_EMPTY2(x)                  (((uint32_t)(((uint32_t)(x)) << RXLUT_RLSOFSR_EMPTY2_SHIFT)) & RXLUT_RLSOFSR_EMPTY2_MASK)

#define RXLUT_RLSOFSR_FULL2_MASK                 (0x200U)
#define RXLUT_RLSOFSR_FULL2_SHIFT                (9U)
#define RXLUT_RLSOFSR_FULL2_WIDTH                (1U)
#define RXLUT_RLSOFSR_FULL2(x)                   (((uint32_t)(((uint32_t)(x)) << RXLUT_RLSOFSR_FULL2_SHIFT)) & RXLUT_RLSOFSR_FULL2_MASK)

#define RXLUT_RLSOFSR_EMPTY3_MASK                (0x1000U)
#define RXLUT_RLSOFSR_EMPTY3_SHIFT               (12U)
#define RXLUT_RLSOFSR_EMPTY3_WIDTH               (1U)
#define RXLUT_RLSOFSR_EMPTY3(x)                  (((uint32_t)(((uint32_t)(x)) << RXLUT_RLSOFSR_EMPTY3_SHIFT)) & RXLUT_RLSOFSR_EMPTY3_MASK)

#define RXLUT_RLSOFSR_FULL3_MASK                 (0x2000U)
#define RXLUT_RLSOFSR_FULL3_SHIFT                (13U)
#define RXLUT_RLSOFSR_FULL3_WIDTH                (1U)
#define RXLUT_RLSOFSR_FULL3(x)                   (((uint32_t)(((uint32_t)(x)) << RXLUT_RLSOFSR_FULL3_SHIFT)) & RXLUT_RLSOFSR_FULL3_MASK)

#define RXLUT_RLSOFSR_EMPTY4_MASK                (0x10000U)
#define RXLUT_RLSOFSR_EMPTY4_SHIFT               (16U)
#define RXLUT_RLSOFSR_EMPTY4_WIDTH               (1U)
#define RXLUT_RLSOFSR_EMPTY4(x)                  (((uint32_t)(((uint32_t)(x)) << RXLUT_RLSOFSR_EMPTY4_SHIFT)) & RXLUT_RLSOFSR_EMPTY4_MASK)

#define RXLUT_RLSOFSR_FULL4_MASK                 (0x20000U)
#define RXLUT_RLSOFSR_FULL4_SHIFT                (17U)
#define RXLUT_RLSOFSR_FULL4_WIDTH                (1U)
#define RXLUT_RLSOFSR_FULL4(x)                   (((uint32_t)(((uint32_t)(x)) << RXLUT_RLSOFSR_FULL4_SHIFT)) & RXLUT_RLSOFSR_FULL4_MASK)

#define RXLUT_RLSOFSR_EMPTY5_MASK                (0x100000U)
#define RXLUT_RLSOFSR_EMPTY5_SHIFT               (20U)
#define RXLUT_RLSOFSR_EMPTY5_WIDTH               (1U)
#define RXLUT_RLSOFSR_EMPTY5(x)                  (((uint32_t)(((uint32_t)(x)) << RXLUT_RLSOFSR_EMPTY5_SHIFT)) & RXLUT_RLSOFSR_EMPTY5_MASK)

#define RXLUT_RLSOFSR_FULL5_MASK                 (0x200000U)
#define RXLUT_RLSOFSR_FULL5_SHIFT                (21U)
#define RXLUT_RLSOFSR_FULL5_WIDTH                (1U)
#define RXLUT_RLSOFSR_FULL5(x)                   (((uint32_t)(((uint32_t)(x)) << RXLUT_RLSOFSR_FULL5_SHIFT)) & RXLUT_RLSOFSR_FULL5_MASK)

#define RXLUT_RLSOFSR_EMPTY6_MASK                (0x1000000U)
#define RXLUT_RLSOFSR_EMPTY6_SHIFT               (24U)
#define RXLUT_RLSOFSR_EMPTY6_WIDTH               (1U)
#define RXLUT_RLSOFSR_EMPTY6(x)                  (((uint32_t)(((uint32_t)(x)) << RXLUT_RLSOFSR_EMPTY6_SHIFT)) & RXLUT_RLSOFSR_EMPTY6_MASK)

#define RXLUT_RLSOFSR_FULL6_MASK                 (0x2000000U)
#define RXLUT_RLSOFSR_FULL6_SHIFT                (25U)
#define RXLUT_RLSOFSR_FULL6_WIDTH                (1U)
#define RXLUT_RLSOFSR_FULL6(x)                   (((uint32_t)(((uint32_t)(x)) << RXLUT_RLSOFSR_FULL6_SHIFT)) & RXLUT_RLSOFSR_FULL6_MASK)

#define RXLUT_RLSOFSR_EMPTY7_MASK                (0x10000000U)
#define RXLUT_RLSOFSR_EMPTY7_SHIFT               (28U)
#define RXLUT_RLSOFSR_EMPTY7_WIDTH               (1U)
#define RXLUT_RLSOFSR_EMPTY7(x)                  (((uint32_t)(((uint32_t)(x)) << RXLUT_RLSOFSR_EMPTY7_SHIFT)) & RXLUT_RLSOFSR_EMPTY7_MASK)

#define RXLUT_RLSOFSR_FULL7_MASK                 (0x20000000U)
#define RXLUT_RLSOFSR_FULL7_SHIFT                (29U)
#define RXLUT_RLSOFSR_FULL7_WIDTH                (1U)
#define RXLUT_RLSOFSR_FULL7(x)                   (((uint32_t)(((uint32_t)(x)) << RXLUT_RLSOFSR_FULL7_SHIFT)) & RXLUT_RLSOFSR_FULL7_MASK)

#define RXLUT_RLSOFSR_EMPTY8_MASK                (0x1U)
#define RXLUT_RLSOFSR_EMPTY8_SHIFT               (0U)
#define RXLUT_RLSOFSR_EMPTY8_WIDTH               (1U)
#define RXLUT_RLSOFSR_EMPTY8(x)                  (((uint32_t)(((uint32_t)(x)) << RXLUT_RLSOFSR_EMPTY8_SHIFT)) & RXLUT_RLSOFSR_EMPTY8_MASK)

#define RXLUT_RLSOFSR_FULL8_MASK                 (0x2U)
#define RXLUT_RLSOFSR_FULL8_SHIFT                (1U)
#define RXLUT_RLSOFSR_FULL8_WIDTH                (1U)
#define RXLUT_RLSOFSR_FULL8(x)                   (((uint32_t)(((uint32_t)(x)) << RXLUT_RLSOFSR_FULL8_SHIFT)) & RXLUT_RLSOFSR_FULL8_MASK)

#define RXLUT_RLSOFSR_EMPTY9_MASK                (0x10U)
#define RXLUT_RLSOFSR_EMPTY9_SHIFT               (4U)
#define RXLUT_RLSOFSR_EMPTY9_WIDTH               (1U)
#define RXLUT_RLSOFSR_EMPTY9(x)                  (((uint32_t)(((uint32_t)(x)) << RXLUT_RLSOFSR_EMPTY9_SHIFT)) & RXLUT_RLSOFSR_EMPTY9_MASK)

#define RXLUT_RLSOFSR_FULL9_MASK                 (0x20U)
#define RXLUT_RLSOFSR_FULL9_SHIFT                (5U)
#define RXLUT_RLSOFSR_FULL9_WIDTH                (1U)
#define RXLUT_RLSOFSR_FULL9(x)                   (((uint32_t)(((uint32_t)(x)) << RXLUT_RLSOFSR_FULL9_SHIFT)) & RXLUT_RLSOFSR_FULL9_MASK)

#define RXLUT_RLSOFSR_EMPTY10_MASK               (0x100U)
#define RXLUT_RLSOFSR_EMPTY10_SHIFT              (8U)
#define RXLUT_RLSOFSR_EMPTY10_WIDTH              (1U)
#define RXLUT_RLSOFSR_EMPTY10(x)                 (((uint32_t)(((uint32_t)(x)) << RXLUT_RLSOFSR_EMPTY10_SHIFT)) & RXLUT_RLSOFSR_EMPTY10_MASK)

#define RXLUT_RLSOFSR_FULL10_MASK                (0x200U)
#define RXLUT_RLSOFSR_FULL10_SHIFT               (9U)
#define RXLUT_RLSOFSR_FULL10_WIDTH               (1U)
#define RXLUT_RLSOFSR_FULL10(x)                  (((uint32_t)(((uint32_t)(x)) << RXLUT_RLSOFSR_FULL10_SHIFT)) & RXLUT_RLSOFSR_FULL10_MASK)

#define RXLUT_RLSOFSR_EMPTY11_MASK               (0x1000U)
#define RXLUT_RLSOFSR_EMPTY11_SHIFT              (12U)
#define RXLUT_RLSOFSR_EMPTY11_WIDTH              (1U)
#define RXLUT_RLSOFSR_EMPTY11(x)                 (((uint32_t)(((uint32_t)(x)) << RXLUT_RLSOFSR_EMPTY11_SHIFT)) & RXLUT_RLSOFSR_EMPTY11_MASK)

#define RXLUT_RLSOFSR_FULL11_MASK                (0x2000U)
#define RXLUT_RLSOFSR_FULL11_SHIFT               (13U)
#define RXLUT_RLSOFSR_FULL11_WIDTH               (1U)
#define RXLUT_RLSOFSR_FULL11(x)                  (((uint32_t)(((uint32_t)(x)) << RXLUT_RLSOFSR_FULL11_SHIFT)) & RXLUT_RLSOFSR_FULL11_MASK)
/*! @} */

/*! @name RLICEC - RXLUT Input Command Entry Counter */
/*! @{ */

#define RXLUT_RLICEC_CNTR0_MASK                  (0xFU)
#define RXLUT_RLICEC_CNTR0_SHIFT                 (0U)
#define RXLUT_RLICEC_CNTR0_WIDTH                 (4U)
#define RXLUT_RLICEC_CNTR0(x)                    (((uint32_t)(((uint32_t)(x)) << RXLUT_RLICEC_CNTR0_SHIFT)) & RXLUT_RLICEC_CNTR0_MASK)

#define RXLUT_RLICEC_CNTR1_MASK                  (0xF0U)
#define RXLUT_RLICEC_CNTR1_SHIFT                 (4U)
#define RXLUT_RLICEC_CNTR1_WIDTH                 (4U)
#define RXLUT_RLICEC_CNTR1(x)                    (((uint32_t)(((uint32_t)(x)) << RXLUT_RLICEC_CNTR1_SHIFT)) & RXLUT_RLICEC_CNTR1_MASK)

#define RXLUT_RLICEC_CNTR2_MASK                  (0xF00U)
#define RXLUT_RLICEC_CNTR2_SHIFT                 (8U)
#define RXLUT_RLICEC_CNTR2_WIDTH                 (4U)
#define RXLUT_RLICEC_CNTR2(x)                    (((uint32_t)(((uint32_t)(x)) << RXLUT_RLICEC_CNTR2_SHIFT)) & RXLUT_RLICEC_CNTR2_MASK)

#define RXLUT_RLICEC_CNTR3_MASK                  (0xF000U)
#define RXLUT_RLICEC_CNTR3_SHIFT                 (12U)
#define RXLUT_RLICEC_CNTR3_WIDTH                 (4U)
#define RXLUT_RLICEC_CNTR3(x)                    (((uint32_t)(((uint32_t)(x)) << RXLUT_RLICEC_CNTR3_SHIFT)) & RXLUT_RLICEC_CNTR3_MASK)

#define RXLUT_RLICEC_CNTR4_MASK                  (0xF0000U)
#define RXLUT_RLICEC_CNTR4_SHIFT                 (16U)
#define RXLUT_RLICEC_CNTR4_WIDTH                 (4U)
#define RXLUT_RLICEC_CNTR4(x)                    (((uint32_t)(((uint32_t)(x)) << RXLUT_RLICEC_CNTR4_SHIFT)) & RXLUT_RLICEC_CNTR4_MASK)

#define RXLUT_RLICEC_CNTR5_MASK                  (0xF00000U)
#define RXLUT_RLICEC_CNTR5_SHIFT                 (20U)
#define RXLUT_RLICEC_CNTR5_WIDTH                 (4U)
#define RXLUT_RLICEC_CNTR5(x)                    (((uint32_t)(((uint32_t)(x)) << RXLUT_RLICEC_CNTR5_SHIFT)) & RXLUT_RLICEC_CNTR5_MASK)

#define RXLUT_RLICEC_CNTR6_MASK                  (0xF000000U)
#define RXLUT_RLICEC_CNTR6_SHIFT                 (24U)
#define RXLUT_RLICEC_CNTR6_WIDTH                 (4U)
#define RXLUT_RLICEC_CNTR6(x)                    (((uint32_t)(((uint32_t)(x)) << RXLUT_RLICEC_CNTR6_SHIFT)) & RXLUT_RLICEC_CNTR6_MASK)

#define RXLUT_RLICEC_CNTR7_MASK                  (0xF0000000U)
#define RXLUT_RLICEC_CNTR7_SHIFT                 (28U)
#define RXLUT_RLICEC_CNTR7_WIDTH                 (4U)
#define RXLUT_RLICEC_CNTR7(x)                    (((uint32_t)(((uint32_t)(x)) << RXLUT_RLICEC_CNTR7_SHIFT)) & RXLUT_RLICEC_CNTR7_MASK)

#define RXLUT_RLICEC_CNTR8_MASK                  (0xFU)
#define RXLUT_RLICEC_CNTR8_SHIFT                 (0U)
#define RXLUT_RLICEC_CNTR8_WIDTH                 (4U)
#define RXLUT_RLICEC_CNTR8(x)                    (((uint32_t)(((uint32_t)(x)) << RXLUT_RLICEC_CNTR8_SHIFT)) & RXLUT_RLICEC_CNTR8_MASK)

#define RXLUT_RLICEC_CNTR9_MASK                  (0xF0U)
#define RXLUT_RLICEC_CNTR9_SHIFT                 (4U)
#define RXLUT_RLICEC_CNTR9_WIDTH                 (4U)
#define RXLUT_RLICEC_CNTR9(x)                    (((uint32_t)(((uint32_t)(x)) << RXLUT_RLICEC_CNTR9_SHIFT)) & RXLUT_RLICEC_CNTR9_MASK)

#define RXLUT_RLICEC_CNTR10_MASK                 (0xF00U)
#define RXLUT_RLICEC_CNTR10_SHIFT                (8U)
#define RXLUT_RLICEC_CNTR10_WIDTH                (4U)
#define RXLUT_RLICEC_CNTR10(x)                   (((uint32_t)(((uint32_t)(x)) << RXLUT_RLICEC_CNTR10_SHIFT)) & RXLUT_RLICEC_CNTR10_MASK)

#define RXLUT_RLICEC_CNTR11_MASK                 (0xF000U)
#define RXLUT_RLICEC_CNTR11_SHIFT                (12U)
#define RXLUT_RLICEC_CNTR11_WIDTH                (4U)
#define RXLUT_RLICEC_CNTR11(x)                   (((uint32_t)(((uint32_t)(x)) << RXLUT_RLICEC_CNTR11_SHIFT)) & RXLUT_RLICEC_CNTR11_MASK)
/*! @} */

/*! @name RLER - RXLUT Error */
/*! @{ */

#define RXLUT_RLER_SBIT_MASK                     (0x1U)
#define RXLUT_RLER_SBIT_SHIFT                    (0U)
#define RXLUT_RLER_SBIT_WIDTH                    (1U)
#define RXLUT_RLER_SBIT(x)                       (((uint32_t)(((uint32_t)(x)) << RXLUT_RLER_SBIT_SHIFT)) & RXLUT_RLER_SBIT_MASK)

#define RXLUT_RLER_MBIT_MASK                     (0x10000U)
#define RXLUT_RLER_MBIT_SHIFT                    (16U)
#define RXLUT_RLER_MBIT_WIDTH                    (1U)
#define RXLUT_RLER_MBIT(x)                       (((uint32_t)(((uint32_t)(x)) << RXLUT_RLER_MBIT_SHIFT)) & RXLUT_RLER_MBIT_MASK)
/*! @} */

/*! @name RLOOR - RXLUT Output Overflow */
/*! @{ */

#define RXLUT_RLOOR_LOR_MASK                     (0xFFFU)
#define RXLUT_RLOOR_LOR_SHIFT                    (0U)
#define RXLUT_RLOOR_LOR_WIDTH                    (12U)
#define RXLUT_RLOOR_LOR(x)                       (((uint32_t)(((uint32_t)(x)) << RXLUT_RLOOR_LOR_SHIFT)) & RXLUT_RLOOR_LOR_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group RXLUT_Register_Masks */

/*!
 * @}
 */ /* end of group RXLUT_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_RXLUT_H_) */
