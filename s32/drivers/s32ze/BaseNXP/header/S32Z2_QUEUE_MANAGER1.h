/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_Queue_Manager1.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_Queue_Manager1
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
#if !defined(S32Z2_Queue_Manager1_H_)  /* Check if memory map has not been already included */
#define S32Z2_Queue_Manager1_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- Queue_Manager1 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Queue_Manager1_Peripheral_Access_Layer Queue_Manager1 Peripheral Access Layer
 * @{
 */

/** Queue_Manager1 - Register Layout Typedef */
typedef struct {
  __IO uint32_t Q1_EN_DEPTH;                       /**< QX EN DEPTH, offset: 0x0 */
  __IO uint32_t Q1_FIRST_ADDR;                     /**< Q1 FIRST ADDR, offset: 0x4 */
  __IO uint32_t Q1_BASE_PTR;                       /**< Q1 BASE PTR, offset: 0x8 */
  __IO uint32_t Q1_CHNK_SIZE;                      /**< Q1 CHNK SIZE, offset: 0xC */
  __IO uint32_t Q1_DSC_EN_INC0;                    /**< Q1 DSC EN INC0, offset: 0x10 */
  __I  uint32_t Q1_STATUS;                         /**< Q1 STATUS, offset: 0x14 */
  __I  uint32_t Q1_RPTR_INT;                       /**< Q1 RPTR INT, offset: 0x18 */
  __I  uint32_t Q1_DSC_CFG;                        /**< Q1 DSC CFG, offset: 0x1C */
  __I  uint32_t Q1_DSC_SRCP;                       /**< Q1 DSC SRCP, offset: 0x20 */
  __I  uint32_t Q1_DSC_DSTP;                       /**< Q1 DSC DSTP, offset: 0x24 */
  __I  uint32_t Q1_DSC_DMASZ;                      /**< Q1 DSC DMASZ, offset: 0x28 */
  __I  uint32_t Q1_DSC_SRC;                        /**< Q1 DSC SRC, offset: 0x2C */
  __I  uint32_t Q1_DSC_LINE;                       /**< Q1 DSC LINE, offset: 0x30 */
  __I  uint32_t Q1_DSC_DST;                        /**< Q1 DSC DST, offset: 0x34 */
  __I  uint32_t Q1_DSC_HGHT;                       /**< Q1 DSC HGHT, offset: 0x38 */
  uint8_t RESERVED_0[4];
  __IO uint32_t Q1_DSC_EN_INC1;                    /**< Q1 DSC EN INC1, offset: 0x40 */
  __I  uint32_t Q1_EN_CNT;                         /**< Q1 EN CNT, offset: 0x44 */
} Queue_Manager1_Type, *Queue_Manager1_MemMapPtr;

/** Number of instances of the Queue_Manager1 module. */
#define Queue_Manager1_INSTANCE_COUNT            (1u)

/* Queue_Manager1 - Peripheral instance base addresses */
/** Peripheral CEVA_SPF2__QUEUE_MANAGER1 base address */
#define IP_CEVA_SPF2__QUEUE_MANAGER1_BASE        (0x24401280u)
/** Peripheral CEVA_SPF2__QUEUE_MANAGER1 base pointer */
#define IP_CEVA_SPF2__QUEUE_MANAGER1             ((Queue_Manager1_Type *)IP_CEVA_SPF2__QUEUE_MANAGER1_BASE)
/** Array initializer of Queue_Manager1 peripheral base addresses */
#define IP_Queue_Manager1_BASE_ADDRS             { IP_CEVA_SPF2__QUEUE_MANAGER1_BASE }
/** Array initializer of Queue_Manager1 peripheral base pointers */
#define IP_Queue_Manager1_BASE_PTRS              { IP_CEVA_SPF2__QUEUE_MANAGER1 }

/* ----------------------------------------------------------------------------
   -- Queue_Manager1 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Queue_Manager1_Register_Masks Queue_Manager1 Register Masks
 * @{
 */

/*! @name Q1_EN_DEPTH - QX EN DEPTH */
/*! @{ */

#define Queue_Manager1_Q1_EN_DEPTH_QX_DEPTH_MASK (0x1FFFU)
#define Queue_Manager1_Q1_EN_DEPTH_QX_DEPTH_SHIFT (0U)
#define Queue_Manager1_Q1_EN_DEPTH_QX_DEPTH_WIDTH (13U)
#define Queue_Manager1_Q1_EN_DEPTH_QX_DEPTH(x)   (((uint32_t)(((uint32_t)(x)) << Queue_Manager1_Q1_EN_DEPTH_QX_DEPTH_SHIFT)) & Queue_Manager1_Q1_EN_DEPTH_QX_DEPTH_MASK)

#define Queue_Manager1_Q1_EN_DEPTH_QX_PRI_ABS_MASK (0xF0000U)
#define Queue_Manager1_Q1_EN_DEPTH_QX_PRI_ABS_SHIFT (16U)
#define Queue_Manager1_Q1_EN_DEPTH_QX_PRI_ABS_WIDTH (4U)
#define Queue_Manager1_Q1_EN_DEPTH_QX_PRI_ABS(x) (((uint32_t)(((uint32_t)(x)) << Queue_Manager1_Q1_EN_DEPTH_QX_PRI_ABS_SHIFT)) & Queue_Manager1_Q1_EN_DEPTH_QX_PRI_ABS_MASK)

#define Queue_Manager1_Q1_EN_DEPTH_QX_PRI_ABS_SEL_MASK (0x100000U)
#define Queue_Manager1_Q1_EN_DEPTH_QX_PRI_ABS_SEL_SHIFT (20U)
#define Queue_Manager1_Q1_EN_DEPTH_QX_PRI_ABS_SEL_WIDTH (1U)
#define Queue_Manager1_Q1_EN_DEPTH_QX_PRI_ABS_SEL(x) (((uint32_t)(((uint32_t)(x)) << Queue_Manager1_Q1_EN_DEPTH_QX_PRI_ABS_SEL_SHIFT)) & Queue_Manager1_Q1_EN_DEPTH_QX_PRI_ABS_SEL_MASK)

#define Queue_Manager1_Q1_EN_DEPTH_QX_AUTO_MASK  (0x200000U)
#define Queue_Manager1_Q1_EN_DEPTH_QX_AUTO_SHIFT (21U)
#define Queue_Manager1_Q1_EN_DEPTH_QX_AUTO_WIDTH (1U)
#define Queue_Manager1_Q1_EN_DEPTH_QX_AUTO(x)    (((uint32_t)(((uint32_t)(x)) << Queue_Manager1_Q1_EN_DEPTH_QX_AUTO_SHIFT)) & Queue_Manager1_Q1_EN_DEPTH_QX_AUTO_MASK)

#define Queue_Manager1_Q1_EN_DEPTH_QX_CEX_PAUSE_MASK (0x400000U)
#define Queue_Manager1_Q1_EN_DEPTH_QX_CEX_PAUSE_SHIFT (22U)
#define Queue_Manager1_Q1_EN_DEPTH_QX_CEX_PAUSE_WIDTH (1U)
#define Queue_Manager1_Q1_EN_DEPTH_QX_CEX_PAUSE(x) (((uint32_t)(((uint32_t)(x)) << Queue_Manager1_Q1_EN_DEPTH_QX_CEX_PAUSE_SHIFT)) & Queue_Manager1_Q1_EN_DEPTH_QX_CEX_PAUSE_MASK)

#define Queue_Manager1_Q1_EN_DEPTH_QX_CONT_FRAME_MASK (0x40000000U)
#define Queue_Manager1_Q1_EN_DEPTH_QX_CONT_FRAME_SHIFT (30U)
#define Queue_Manager1_Q1_EN_DEPTH_QX_CONT_FRAME_WIDTH (1U)
#define Queue_Manager1_Q1_EN_DEPTH_QX_CONT_FRAME(x) (((uint32_t)(((uint32_t)(x)) << Queue_Manager1_Q1_EN_DEPTH_QX_CONT_FRAME_SHIFT)) & Queue_Manager1_Q1_EN_DEPTH_QX_CONT_FRAME_MASK)

#define Queue_Manager1_Q1_EN_DEPTH_QX_EN_MASK    (0x80000000U)
#define Queue_Manager1_Q1_EN_DEPTH_QX_EN_SHIFT   (31U)
#define Queue_Manager1_Q1_EN_DEPTH_QX_EN_WIDTH   (1U)
#define Queue_Manager1_Q1_EN_DEPTH_QX_EN(x)      (((uint32_t)(((uint32_t)(x)) << Queue_Manager1_Q1_EN_DEPTH_QX_EN_SHIFT)) & Queue_Manager1_Q1_EN_DEPTH_QX_EN_MASK)
/*! @} */

/*! @name Q1_FIRST_ADDR - Q1 FIRST ADDR */
/*! @{ */

#define Queue_Manager1_Q1_FIRST_ADDR_QX_FIRST_ADDR_MASK (0xFFFFFFFFU)
#define Queue_Manager1_Q1_FIRST_ADDR_QX_FIRST_ADDR_SHIFT (0U)
#define Queue_Manager1_Q1_FIRST_ADDR_QX_FIRST_ADDR_WIDTH (32U)
#define Queue_Manager1_Q1_FIRST_ADDR_QX_FIRST_ADDR(x) (((uint32_t)(((uint32_t)(x)) << Queue_Manager1_Q1_FIRST_ADDR_QX_FIRST_ADDR_SHIFT)) & Queue_Manager1_Q1_FIRST_ADDR_QX_FIRST_ADDR_MASK)
/*! @} */

/*! @name Q1_BASE_PTR - Q1 BASE PTR */
/*! @{ */

#define Queue_Manager1_Q1_BASE_PTR_QX_BASE_PTR_MASK (0xFFFFFFFFU)
#define Queue_Manager1_Q1_BASE_PTR_QX_BASE_PTR_SHIFT (0U)
#define Queue_Manager1_Q1_BASE_PTR_QX_BASE_PTR_WIDTH (32U)
#define Queue_Manager1_Q1_BASE_PTR_QX_BASE_PTR(x) (((uint32_t)(((uint32_t)(x)) << Queue_Manager1_Q1_BASE_PTR_QX_BASE_PTR_SHIFT)) & Queue_Manager1_Q1_BASE_PTR_QX_BASE_PTR_MASK)
/*! @} */

/*! @name Q1_CHNK_SIZE - Q1 CHNK SIZE */
/*! @{ */

#define Queue_Manager1_Q1_CHNK_SIZE_QX_CHNK_SIZE_MASK (0x3FFFU)
#define Queue_Manager1_Q1_CHNK_SIZE_QX_CHNK_SIZE_SHIFT (0U)
#define Queue_Manager1_Q1_CHNK_SIZE_QX_CHNK_SIZE_WIDTH (14U)
#define Queue_Manager1_Q1_CHNK_SIZE_QX_CHNK_SIZE(x) (((uint32_t)(((uint32_t)(x)) << Queue_Manager1_Q1_CHNK_SIZE_QX_CHNK_SIZE_SHIFT)) & Queue_Manager1_Q1_CHNK_SIZE_QX_CHNK_SIZE_MASK)

#define Queue_Manager1_Q1_CHNK_SIZE_QX_CHNK_LINES_MASK (0xFFFF0000U)
#define Queue_Manager1_Q1_CHNK_SIZE_QX_CHNK_LINES_SHIFT (16U)
#define Queue_Manager1_Q1_CHNK_SIZE_QX_CHNK_LINES_WIDTH (16U)
#define Queue_Manager1_Q1_CHNK_SIZE_QX_CHNK_LINES(x) (((uint32_t)(((uint32_t)(x)) << Queue_Manager1_Q1_CHNK_SIZE_QX_CHNK_LINES_SHIFT)) & Queue_Manager1_Q1_CHNK_SIZE_QX_CHNK_LINES_MASK)
/*! @} */

/*! @name Q1_DSC_EN_INC0 - Q1 DSC EN INC0 */
/*! @{ */

#define Queue_Manager1_Q1_DSC_EN_INC0_QX_EN_INC_VAL0_MASK (0x7FFU)
#define Queue_Manager1_Q1_DSC_EN_INC0_QX_EN_INC_VAL0_SHIFT (0U)
#define Queue_Manager1_Q1_DSC_EN_INC0_QX_EN_INC_VAL0_WIDTH (11U)
#define Queue_Manager1_Q1_DSC_EN_INC0_QX_EN_INC_VAL0(x) (((uint32_t)(((uint32_t)(x)) << Queue_Manager1_Q1_DSC_EN_INC0_QX_EN_INC_VAL0_SHIFT)) & Queue_Manager1_Q1_DSC_EN_INC0_QX_EN_INC_VAL0_MASK)

#define Queue_Manager1_Q1_DSC_EN_INC0_QX_DSC_EN0_MASK (0x10000U)
#define Queue_Manager1_Q1_DSC_EN_INC0_QX_DSC_EN0_SHIFT (16U)
#define Queue_Manager1_Q1_DSC_EN_INC0_QX_DSC_EN0_WIDTH (1U)
#define Queue_Manager1_Q1_DSC_EN_INC0_QX_DSC_EN0(x) (((uint32_t)(((uint32_t)(x)) << Queue_Manager1_Q1_DSC_EN_INC0_QX_DSC_EN0_SHIFT)) & Queue_Manager1_Q1_DSC_EN_INC0_QX_DSC_EN0_MASK)

#define Queue_Manager1_Q1_DSC_EN_INC0_QX_DSC_CNT_CFG_0_MASK (0x20000U)
#define Queue_Manager1_Q1_DSC_EN_INC0_QX_DSC_CNT_CFG_0_SHIFT (17U)
#define Queue_Manager1_Q1_DSC_EN_INC0_QX_DSC_CNT_CFG_0_WIDTH (1U)
#define Queue_Manager1_Q1_DSC_EN_INC0_QX_DSC_CNT_CFG_0(x) (((uint32_t)(((uint32_t)(x)) << Queue_Manager1_Q1_DSC_EN_INC0_QX_DSC_CNT_CFG_0_SHIFT)) & Queue_Manager1_Q1_DSC_EN_INC0_QX_DSC_CNT_CFG_0_MASK)

#define Queue_Manager1_Q1_DSC_EN_INC0_QX_EN_CNT_DIS0_MASK (0x80000000U)
#define Queue_Manager1_Q1_DSC_EN_INC0_QX_EN_CNT_DIS0_SHIFT (31U)
#define Queue_Manager1_Q1_DSC_EN_INC0_QX_EN_CNT_DIS0_WIDTH (1U)
#define Queue_Manager1_Q1_DSC_EN_INC0_QX_EN_CNT_DIS0(x) (((uint32_t)(((uint32_t)(x)) << Queue_Manager1_Q1_DSC_EN_INC0_QX_EN_CNT_DIS0_SHIFT)) & Queue_Manager1_Q1_DSC_EN_INC0_QX_EN_CNT_DIS0_MASK)
/*! @} */

/*! @name Q1_STATUS - Q1 STATUS */
/*! @{ */

#define Queue_Manager1_Q1_STATUS_QX_WD_WAIT_MASK (0x40000000U)
#define Queue_Manager1_Q1_STATUS_QX_WD_WAIT_SHIFT (30U)
#define Queue_Manager1_Q1_STATUS_QX_WD_WAIT_WIDTH (1U)
#define Queue_Manager1_Q1_STATUS_QX_WD_WAIT(x)   (((uint32_t)(((uint32_t)(x)) << Queue_Manager1_Q1_STATUS_QX_WD_WAIT_SHIFT)) & Queue_Manager1_Q1_STATUS_QX_WD_WAIT_MASK)

#define Queue_Manager1_Q1_STATUS_QX_STATUS_MASK  (0x80000000U)
#define Queue_Manager1_Q1_STATUS_QX_STATUS_SHIFT (31U)
#define Queue_Manager1_Q1_STATUS_QX_STATUS_WIDTH (1U)
#define Queue_Manager1_Q1_STATUS_QX_STATUS(x)    (((uint32_t)(((uint32_t)(x)) << Queue_Manager1_Q1_STATUS_QX_STATUS_SHIFT)) & Queue_Manager1_Q1_STATUS_QX_STATUS_MASK)
/*! @} */

/*! @name Q1_RPTR_INT - Q1 RPTR INT */
/*! @{ */

#define Queue_Manager1_Q1_RPTR_INT_QX_RPTR_INT_MASK (0x3FFFFU)
#define Queue_Manager1_Q1_RPTR_INT_QX_RPTR_INT_SHIFT (0U)
#define Queue_Manager1_Q1_RPTR_INT_QX_RPTR_INT_WIDTH (18U)
#define Queue_Manager1_Q1_RPTR_INT_QX_RPTR_INT(x) (((uint32_t)(((uint32_t)(x)) << Queue_Manager1_Q1_RPTR_INT_QX_RPTR_INT_SHIFT)) & Queue_Manager1_Q1_RPTR_INT_QX_RPTR_INT_MASK)
/*! @} */

/*! @name Q1_DSC_CFG - Q1 DSC CFG */
/*! @{ */

#define Queue_Manager1_Q1_DSC_CFG_QX_DSC_CFG_MASK (0xFFFFFFFFU)
#define Queue_Manager1_Q1_DSC_CFG_QX_DSC_CFG_SHIFT (0U)
#define Queue_Manager1_Q1_DSC_CFG_QX_DSC_CFG_WIDTH (32U)
#define Queue_Manager1_Q1_DSC_CFG_QX_DSC_CFG(x)  (((uint32_t)(((uint32_t)(x)) << Queue_Manager1_Q1_DSC_CFG_QX_DSC_CFG_SHIFT)) & Queue_Manager1_Q1_DSC_CFG_QX_DSC_CFG_MASK)
/*! @} */

/*! @name Q1_DSC_SRCP - Q1 DSC SRCP */
/*! @{ */

#define Queue_Manager1_Q1_DSC_SRCP_QX_DSC_SRCP_MASK (0xFFFFFFFFU)
#define Queue_Manager1_Q1_DSC_SRCP_QX_DSC_SRCP_SHIFT (0U)
#define Queue_Manager1_Q1_DSC_SRCP_QX_DSC_SRCP_WIDTH (32U)
#define Queue_Manager1_Q1_DSC_SRCP_QX_DSC_SRCP(x) (((uint32_t)(((uint32_t)(x)) << Queue_Manager1_Q1_DSC_SRCP_QX_DSC_SRCP_SHIFT)) & Queue_Manager1_Q1_DSC_SRCP_QX_DSC_SRCP_MASK)
/*! @} */

/*! @name Q1_DSC_DSTP - Q1 DSC DSTP */
/*! @{ */

#define Queue_Manager1_Q1_DSC_DSTP_QX_DSC_DSTP_MASK (0xFFFFFFFFU)
#define Queue_Manager1_Q1_DSC_DSTP_QX_DSC_DSTP_SHIFT (0U)
#define Queue_Manager1_Q1_DSC_DSTP_QX_DSC_DSTP_WIDTH (32U)
#define Queue_Manager1_Q1_DSC_DSTP_QX_DSC_DSTP(x) (((uint32_t)(((uint32_t)(x)) << Queue_Manager1_Q1_DSC_DSTP_QX_DSC_DSTP_SHIFT)) & Queue_Manager1_Q1_DSC_DSTP_QX_DSC_DSTP_MASK)
/*! @} */

/*! @name Q1_DSC_DMASZ - Q1 DSC DMASZ */
/*! @{ */

#define Queue_Manager1_Q1_DSC_DMASZ_QX_DSC_DMASZ_MASK (0xFFFFFFFFU)
#define Queue_Manager1_Q1_DSC_DMASZ_QX_DSC_DMASZ_SHIFT (0U)
#define Queue_Manager1_Q1_DSC_DMASZ_QX_DSC_DMASZ_WIDTH (32U)
#define Queue_Manager1_Q1_DSC_DMASZ_QX_DSC_DMASZ(x) (((uint32_t)(((uint32_t)(x)) << Queue_Manager1_Q1_DSC_DMASZ_QX_DSC_DMASZ_SHIFT)) & Queue_Manager1_Q1_DSC_DMASZ_QX_DSC_DMASZ_MASK)
/*! @} */

/*! @name Q1_DSC_SRC - Q1 DSC SRC */
/*! @{ */

#define Queue_Manager1_Q1_DSC_SRC_QX_DSC_SRC_MASK (0xFFFFFFFFU)
#define Queue_Manager1_Q1_DSC_SRC_QX_DSC_SRC_SHIFT (0U)
#define Queue_Manager1_Q1_DSC_SRC_QX_DSC_SRC_WIDTH (32U)
#define Queue_Manager1_Q1_DSC_SRC_QX_DSC_SRC(x)  (((uint32_t)(((uint32_t)(x)) << Queue_Manager1_Q1_DSC_SRC_QX_DSC_SRC_SHIFT)) & Queue_Manager1_Q1_DSC_SRC_QX_DSC_SRC_MASK)
/*! @} */

/*! @name Q1_DSC_LINE - Q1 DSC LINE */
/*! @{ */

#define Queue_Manager1_Q1_DSC_LINE_QX_DSC_LINE_MASK (0xFFFFFFFFU)
#define Queue_Manager1_Q1_DSC_LINE_QX_DSC_LINE_SHIFT (0U)
#define Queue_Manager1_Q1_DSC_LINE_QX_DSC_LINE_WIDTH (32U)
#define Queue_Manager1_Q1_DSC_LINE_QX_DSC_LINE(x) (((uint32_t)(((uint32_t)(x)) << Queue_Manager1_Q1_DSC_LINE_QX_DSC_LINE_SHIFT)) & Queue_Manager1_Q1_DSC_LINE_QX_DSC_LINE_MASK)
/*! @} */

/*! @name Q1_DSC_DST - Q1 DSC DST */
/*! @{ */

#define Queue_Manager1_Q1_DSC_DST_QX_DSC_DST_MASK (0xFFFFFFFFU)
#define Queue_Manager1_Q1_DSC_DST_QX_DSC_DST_SHIFT (0U)
#define Queue_Manager1_Q1_DSC_DST_QX_DSC_DST_WIDTH (32U)
#define Queue_Manager1_Q1_DSC_DST_QX_DSC_DST(x)  (((uint32_t)(((uint32_t)(x)) << Queue_Manager1_Q1_DSC_DST_QX_DSC_DST_SHIFT)) & Queue_Manager1_Q1_DSC_DST_QX_DSC_DST_MASK)
/*! @} */

/*! @name Q1_DSC_HGHT - Q1 DSC HGHT */
/*! @{ */

#define Queue_Manager1_Q1_DSC_HGHT_QX_DSC_HGHT_MASK (0xFFFFFFFFU)
#define Queue_Manager1_Q1_DSC_HGHT_QX_DSC_HGHT_SHIFT (0U)
#define Queue_Manager1_Q1_DSC_HGHT_QX_DSC_HGHT_WIDTH (32U)
#define Queue_Manager1_Q1_DSC_HGHT_QX_DSC_HGHT(x) (((uint32_t)(((uint32_t)(x)) << Queue_Manager1_Q1_DSC_HGHT_QX_DSC_HGHT_SHIFT)) & Queue_Manager1_Q1_DSC_HGHT_QX_DSC_HGHT_MASK)
/*! @} */

/*! @name Q1_DSC_EN_INC1 - Q1 DSC EN INC1 */
/*! @{ */

#define Queue_Manager1_Q1_DSC_EN_INC1_QX_EN_INC_VAL1_MASK (0x7FFU)
#define Queue_Manager1_Q1_DSC_EN_INC1_QX_EN_INC_VAL1_SHIFT (0U)
#define Queue_Manager1_Q1_DSC_EN_INC1_QX_EN_INC_VAL1_WIDTH (11U)
#define Queue_Manager1_Q1_DSC_EN_INC1_QX_EN_INC_VAL1(x) (((uint32_t)(((uint32_t)(x)) << Queue_Manager1_Q1_DSC_EN_INC1_QX_EN_INC_VAL1_SHIFT)) & Queue_Manager1_Q1_DSC_EN_INC1_QX_EN_INC_VAL1_MASK)

#define Queue_Manager1_Q1_DSC_EN_INC1_QX_DSC_EN1_MASK (0x10000U)
#define Queue_Manager1_Q1_DSC_EN_INC1_QX_DSC_EN1_SHIFT (16U)
#define Queue_Manager1_Q1_DSC_EN_INC1_QX_DSC_EN1_WIDTH (1U)
#define Queue_Manager1_Q1_DSC_EN_INC1_QX_DSC_EN1(x) (((uint32_t)(((uint32_t)(x)) << Queue_Manager1_Q1_DSC_EN_INC1_QX_DSC_EN1_SHIFT)) & Queue_Manager1_Q1_DSC_EN_INC1_QX_DSC_EN1_MASK)

#define Queue_Manager1_Q1_DSC_EN_INC1_QX_DSC_CNT_CFG_1_MASK (0x20000U)
#define Queue_Manager1_Q1_DSC_EN_INC1_QX_DSC_CNT_CFG_1_SHIFT (17U)
#define Queue_Manager1_Q1_DSC_EN_INC1_QX_DSC_CNT_CFG_1_WIDTH (1U)
#define Queue_Manager1_Q1_DSC_EN_INC1_QX_DSC_CNT_CFG_1(x) (((uint32_t)(((uint32_t)(x)) << Queue_Manager1_Q1_DSC_EN_INC1_QX_DSC_CNT_CFG_1_SHIFT)) & Queue_Manager1_Q1_DSC_EN_INC1_QX_DSC_CNT_CFG_1_MASK)

#define Queue_Manager1_Q1_DSC_EN_INC1_QX_EN_CNT_DIS1_MASK (0x80000000U)
#define Queue_Manager1_Q1_DSC_EN_INC1_QX_EN_CNT_DIS1_SHIFT (31U)
#define Queue_Manager1_Q1_DSC_EN_INC1_QX_EN_CNT_DIS1_WIDTH (1U)
#define Queue_Manager1_Q1_DSC_EN_INC1_QX_EN_CNT_DIS1(x) (((uint32_t)(((uint32_t)(x)) << Queue_Manager1_Q1_DSC_EN_INC1_QX_EN_CNT_DIS1_SHIFT)) & Queue_Manager1_Q1_DSC_EN_INC1_QX_EN_CNT_DIS1_MASK)
/*! @} */

/*! @name Q1_EN_CNT - Q1 EN CNT */
/*! @{ */

#define Queue_Manager1_Q1_EN_CNT_QX_EN_CNT0_MASK (0x3FFFU)
#define Queue_Manager1_Q1_EN_CNT_QX_EN_CNT0_SHIFT (0U)
#define Queue_Manager1_Q1_EN_CNT_QX_EN_CNT0_WIDTH (14U)
#define Queue_Manager1_Q1_EN_CNT_QX_EN_CNT0(x)   (((uint32_t)(((uint32_t)(x)) << Queue_Manager1_Q1_EN_CNT_QX_EN_CNT0_SHIFT)) & Queue_Manager1_Q1_EN_CNT_QX_EN_CNT0_MASK)

#define Queue_Manager1_Q1_EN_CNT_QX_EN_CNT1_MASK (0x3FFF0000U)
#define Queue_Manager1_Q1_EN_CNT_QX_EN_CNT1_SHIFT (16U)
#define Queue_Manager1_Q1_EN_CNT_QX_EN_CNT1_WIDTH (14U)
#define Queue_Manager1_Q1_EN_CNT_QX_EN_CNT1(x)   (((uint32_t)(((uint32_t)(x)) << Queue_Manager1_Q1_EN_CNT_QX_EN_CNT1_SHIFT)) & Queue_Manager1_Q1_EN_CNT_QX_EN_CNT1_MASK)

#define Queue_Manager1_Q1_EN_CNT_QX_WD_WAIT_MASK (0x40000000U)
#define Queue_Manager1_Q1_EN_CNT_QX_WD_WAIT_SHIFT (30U)
#define Queue_Manager1_Q1_EN_CNT_QX_WD_WAIT_WIDTH (1U)
#define Queue_Manager1_Q1_EN_CNT_QX_WD_WAIT(x)   (((uint32_t)(((uint32_t)(x)) << Queue_Manager1_Q1_EN_CNT_QX_WD_WAIT_SHIFT)) & Queue_Manager1_Q1_EN_CNT_QX_WD_WAIT_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group Queue_Manager1_Register_Masks */

/*!
 * @}
 */ /* end of group Queue_Manager1_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_Queue_Manager1_H_) */
