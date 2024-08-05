/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_QUEUE_DESCRIPTOR.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_QUEUE_DESCRIPTOR
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
#if !defined(S32Z2_QUEUE_DESCRIPTOR_H_)  /* Check if memory map has not been already included */
#define S32Z2_QUEUE_DESCRIPTOR_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- QUEUE_DESCRIPTOR Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup QUEUE_DESCRIPTOR_Peripheral_Access_Layer QUEUE_DESCRIPTOR Peripheral Access Layer
 * @{
 */

/** QUEUE_DESCRIPTOR - Register Layout Typedef */
typedef struct {
  __IO uint32_t QPUSH_DSC_CFG;                     /**< QPUSH DSC CFG, offset: 0x0 */
  __IO uint32_t QPUSH_DSC_SRCP;                    /**< QPUSH DSC SRCP, offset: 0x4 */
  __IO uint32_t QPUSH_DSC_DSTP;                    /**< QPUSH DSC DSTP, offset: 0x8 */
  __IO uint32_t QPUSH_DSC_DMASZ;                   /**< QPUSH DSC DMASZ, offset: 0xC */
  __IO uint32_t QPUSH_DSC_SRC;                     /**< QPUSH DSC SRC, offset: 0x10 */
  __IO uint32_t QPUSH_DSC_LINE;                    /**< QPUSH DSC LINE, offset: 0x14 */
  __IO uint32_t QPUSH_DSC_DST;                     /**< QPUSH DSC DST, offset: 0x18 */
  __IO uint32_t QPUSH_DSC_HGHT;                    /**< QPUSH DSC HGHT, offset: 0x1C */
  __IO uint32_t QPUSH_NUM;                         /**< QPUSH NUM, offset: 0x20 */
} QUEUE_DESCRIPTOR_Type, *QUEUE_DESCRIPTOR_MemMapPtr;

/** Number of instances of the QUEUE_DESCRIPTOR module. */
#define QUEUE_DESCRIPTOR_INSTANCE_COUNT          (1u)

/* QUEUE_DESCRIPTOR - Peripheral instance base addresses */
/** Peripheral CEVA_SPF2__QUEUE_DESCRIPTOR base address */
#define IP_CEVA_SPF2__QUEUE_DESCRIPTOR_BASE      (0x24401100u)
/** Peripheral CEVA_SPF2__QUEUE_DESCRIPTOR base pointer */
#define IP_CEVA_SPF2__QUEUE_DESCRIPTOR           ((QUEUE_DESCRIPTOR_Type *)IP_CEVA_SPF2__QUEUE_DESCRIPTOR_BASE)
/** Array initializer of QUEUE_DESCRIPTOR peripheral base addresses */
#define IP_QUEUE_DESCRIPTOR_BASE_ADDRS           { IP_CEVA_SPF2__QUEUE_DESCRIPTOR_BASE }
/** Array initializer of QUEUE_DESCRIPTOR peripheral base pointers */
#define IP_QUEUE_DESCRIPTOR_BASE_PTRS            { IP_CEVA_SPF2__QUEUE_DESCRIPTOR }

/* ----------------------------------------------------------------------------
   -- QUEUE_DESCRIPTOR Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup QUEUE_DESCRIPTOR_Register_Masks QUEUE_DESCRIPTOR Register Masks
 * @{
 */

/*! @name QPUSH_DSC_CFG - QPUSH DSC CFG */
/*! @{ */

#define QUEUE_DESCRIPTOR_QPUSH_DSC_CFG_QPUSH_DSC_CFG_MASK (0xFFFFFFFFU)
#define QUEUE_DESCRIPTOR_QPUSH_DSC_CFG_QPUSH_DSC_CFG_SHIFT (0U)
#define QUEUE_DESCRIPTOR_QPUSH_DSC_CFG_QPUSH_DSC_CFG_WIDTH (32U)
#define QUEUE_DESCRIPTOR_QPUSH_DSC_CFG_QPUSH_DSC_CFG(x) (((uint32_t)(((uint32_t)(x)) << QUEUE_DESCRIPTOR_QPUSH_DSC_CFG_QPUSH_DSC_CFG_SHIFT)) & QUEUE_DESCRIPTOR_QPUSH_DSC_CFG_QPUSH_DSC_CFG_MASK)
/*! @} */

/*! @name QPUSH_DSC_SRCP - QPUSH DSC SRCP */
/*! @{ */

#define QUEUE_DESCRIPTOR_QPUSH_DSC_SRCP_QPUSH_DSC_SRCP_MASK (0xFFFFFFFFU)
#define QUEUE_DESCRIPTOR_QPUSH_DSC_SRCP_QPUSH_DSC_SRCP_SHIFT (0U)
#define QUEUE_DESCRIPTOR_QPUSH_DSC_SRCP_QPUSH_DSC_SRCP_WIDTH (32U)
#define QUEUE_DESCRIPTOR_QPUSH_DSC_SRCP_QPUSH_DSC_SRCP(x) (((uint32_t)(((uint32_t)(x)) << QUEUE_DESCRIPTOR_QPUSH_DSC_SRCP_QPUSH_DSC_SRCP_SHIFT)) & QUEUE_DESCRIPTOR_QPUSH_DSC_SRCP_QPUSH_DSC_SRCP_MASK)
/*! @} */

/*! @name QPUSH_DSC_DSTP - QPUSH DSC DSTP */
/*! @{ */

#define QUEUE_DESCRIPTOR_QPUSH_DSC_DSTP_QPUSH_DSC_DSTP_MASK (0xFFFFFFFFU)
#define QUEUE_DESCRIPTOR_QPUSH_DSC_DSTP_QPUSH_DSC_DSTP_SHIFT (0U)
#define QUEUE_DESCRIPTOR_QPUSH_DSC_DSTP_QPUSH_DSC_DSTP_WIDTH (32U)
#define QUEUE_DESCRIPTOR_QPUSH_DSC_DSTP_QPUSH_DSC_DSTP(x) (((uint32_t)(((uint32_t)(x)) << QUEUE_DESCRIPTOR_QPUSH_DSC_DSTP_QPUSH_DSC_DSTP_SHIFT)) & QUEUE_DESCRIPTOR_QPUSH_DSC_DSTP_QPUSH_DSC_DSTP_MASK)
/*! @} */

/*! @name QPUSH_DSC_DMASZ - QPUSH DSC DMASZ */
/*! @{ */

#define QUEUE_DESCRIPTOR_QPUSH_DSC_DMASZ_QPUSH_DSC_DMASZ_MASK (0xFFFFFFFFU)
#define QUEUE_DESCRIPTOR_QPUSH_DSC_DMASZ_QPUSH_DSC_DMASZ_SHIFT (0U)
#define QUEUE_DESCRIPTOR_QPUSH_DSC_DMASZ_QPUSH_DSC_DMASZ_WIDTH (32U)
#define QUEUE_DESCRIPTOR_QPUSH_DSC_DMASZ_QPUSH_DSC_DMASZ(x) (((uint32_t)(((uint32_t)(x)) << QUEUE_DESCRIPTOR_QPUSH_DSC_DMASZ_QPUSH_DSC_DMASZ_SHIFT)) & QUEUE_DESCRIPTOR_QPUSH_DSC_DMASZ_QPUSH_DSC_DMASZ_MASK)
/*! @} */

/*! @name QPUSH_DSC_SRC - QPUSH DSC SRC */
/*! @{ */

#define QUEUE_DESCRIPTOR_QPUSH_DSC_SRC_QPUSH_DSC_SRC_MASK (0xFFFFFFFFU)
#define QUEUE_DESCRIPTOR_QPUSH_DSC_SRC_QPUSH_DSC_SRC_SHIFT (0U)
#define QUEUE_DESCRIPTOR_QPUSH_DSC_SRC_QPUSH_DSC_SRC_WIDTH (32U)
#define QUEUE_DESCRIPTOR_QPUSH_DSC_SRC_QPUSH_DSC_SRC(x) (((uint32_t)(((uint32_t)(x)) << QUEUE_DESCRIPTOR_QPUSH_DSC_SRC_QPUSH_DSC_SRC_SHIFT)) & QUEUE_DESCRIPTOR_QPUSH_DSC_SRC_QPUSH_DSC_SRC_MASK)
/*! @} */

/*! @name QPUSH_DSC_LINE - QPUSH DSC LINE */
/*! @{ */

#define QUEUE_DESCRIPTOR_QPUSH_DSC_LINE_QPUSH_DSC_LINE_MASK (0xFFFFFFFFU)
#define QUEUE_DESCRIPTOR_QPUSH_DSC_LINE_QPUSH_DSC_LINE_SHIFT (0U)
#define QUEUE_DESCRIPTOR_QPUSH_DSC_LINE_QPUSH_DSC_LINE_WIDTH (32U)
#define QUEUE_DESCRIPTOR_QPUSH_DSC_LINE_QPUSH_DSC_LINE(x) (((uint32_t)(((uint32_t)(x)) << QUEUE_DESCRIPTOR_QPUSH_DSC_LINE_QPUSH_DSC_LINE_SHIFT)) & QUEUE_DESCRIPTOR_QPUSH_DSC_LINE_QPUSH_DSC_LINE_MASK)
/*! @} */

/*! @name QPUSH_DSC_DST - QPUSH DSC DST */
/*! @{ */

#define QUEUE_DESCRIPTOR_QPUSH_DSC_DST_QPUSH_DSC_DST_MASK (0xFFFFFFFFU)
#define QUEUE_DESCRIPTOR_QPUSH_DSC_DST_QPUSH_DSC_DST_SHIFT (0U)
#define QUEUE_DESCRIPTOR_QPUSH_DSC_DST_QPUSH_DSC_DST_WIDTH (32U)
#define QUEUE_DESCRIPTOR_QPUSH_DSC_DST_QPUSH_DSC_DST(x) (((uint32_t)(((uint32_t)(x)) << QUEUE_DESCRIPTOR_QPUSH_DSC_DST_QPUSH_DSC_DST_SHIFT)) & QUEUE_DESCRIPTOR_QPUSH_DSC_DST_QPUSH_DSC_DST_MASK)
/*! @} */

/*! @name QPUSH_DSC_HGHT - QPUSH DSC HGHT */
/*! @{ */

#define QUEUE_DESCRIPTOR_QPUSH_DSC_HGHT_QPUSH_DSC_HGHT_MASK (0xFFFFFFFFU)
#define QUEUE_DESCRIPTOR_QPUSH_DSC_HGHT_QPUSH_DSC_HGHT_SHIFT (0U)
#define QUEUE_DESCRIPTOR_QPUSH_DSC_HGHT_QPUSH_DSC_HGHT_WIDTH (32U)
#define QUEUE_DESCRIPTOR_QPUSH_DSC_HGHT_QPUSH_DSC_HGHT(x) (((uint32_t)(((uint32_t)(x)) << QUEUE_DESCRIPTOR_QPUSH_DSC_HGHT_QPUSH_DSC_HGHT_SHIFT)) & QUEUE_DESCRIPTOR_QPUSH_DSC_HGHT_QPUSH_DSC_HGHT_MASK)
/*! @} */

/*! @name QPUSH_NUM - QPUSH NUM */
/*! @{ */

#define QUEUE_DESCRIPTOR_QPUSH_NUM_QPUSH_NUM_MASK (0x1FU)
#define QUEUE_DESCRIPTOR_QPUSH_NUM_QPUSH_NUM_SHIFT (0U)
#define QUEUE_DESCRIPTOR_QPUSH_NUM_QPUSH_NUM_WIDTH (5U)
#define QUEUE_DESCRIPTOR_QPUSH_NUM_QPUSH_NUM(x)  (((uint32_t)(((uint32_t)(x)) << QUEUE_DESCRIPTOR_QPUSH_NUM_QPUSH_NUM_SHIFT)) & QUEUE_DESCRIPTOR_QPUSH_NUM_QPUSH_NUM_MASK)

#define QUEUE_DESCRIPTOR_QPUSH_NUM_QPUSH_AUTO_INC_MASK (0x40U)
#define QUEUE_DESCRIPTOR_QPUSH_NUM_QPUSH_AUTO_INC_SHIFT (6U)
#define QUEUE_DESCRIPTOR_QPUSH_NUM_QPUSH_AUTO_INC_WIDTH (1U)
#define QUEUE_DESCRIPTOR_QPUSH_NUM_QPUSH_AUTO_INC(x) (((uint32_t)(((uint32_t)(x)) << QUEUE_DESCRIPTOR_QPUSH_NUM_QPUSH_AUTO_INC_SHIFT)) & QUEUE_DESCRIPTOR_QPUSH_NUM_QPUSH_AUTO_INC_MASK)

#define QUEUE_DESCRIPTOR_QPUSH_NUM_QPUSH_STATUS_RLS_MASK (0x10000U)
#define QUEUE_DESCRIPTOR_QPUSH_NUM_QPUSH_STATUS_RLS_SHIFT (16U)
#define QUEUE_DESCRIPTOR_QPUSH_NUM_QPUSH_STATUS_RLS_WIDTH (1U)
#define QUEUE_DESCRIPTOR_QPUSH_NUM_QPUSH_STATUS_RLS(x) (((uint32_t)(((uint32_t)(x)) << QUEUE_DESCRIPTOR_QPUSH_NUM_QPUSH_STATUS_RLS_SHIFT)) & QUEUE_DESCRIPTOR_QPUSH_NUM_QPUSH_STATUS_RLS_MASK)

#define QUEUE_DESCRIPTOR_QPUSH_NUM_QPUSH_STATUS_MASK (0x20000U)
#define QUEUE_DESCRIPTOR_QPUSH_NUM_QPUSH_STATUS_SHIFT (17U)
#define QUEUE_DESCRIPTOR_QPUSH_NUM_QPUSH_STATUS_WIDTH (1U)
#define QUEUE_DESCRIPTOR_QPUSH_NUM_QPUSH_STATUS(x) (((uint32_t)(((uint32_t)(x)) << QUEUE_DESCRIPTOR_QPUSH_NUM_QPUSH_STATUS_SHIFT)) & QUEUE_DESCRIPTOR_QPUSH_NUM_QPUSH_STATUS_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group QUEUE_DESCRIPTOR_Register_Masks */

/*!
 * @}
 */ /* end of group QUEUE_DESCRIPTOR_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_QUEUE_DESCRIPTOR_H_) */
