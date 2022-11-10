/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_QUEUE_MANAGER.h
 * @version 1.8
 * @date 2022-07-13
 * @brief Peripheral Access Layer for S32Z2_QUEUE_MANAGER
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
#if !defined(S32Z2_QUEUE_MANAGER_H_)  /* Check if memory map has not been already included */
#define S32Z2_QUEUE_MANAGER_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- QUEUE_MANAGER Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup QUEUE_MANAGER_Peripheral_Access_Layer QUEUE_MANAGER Peripheral Access Layer
 * @{
 */

/** QUEUE_MANAGER - Register Layout Typedef */
typedef struct {
  __IO uint32_t Q0_EN_DEPTH;                       /**< QX EN DEPTH, offset: 0x0 */
  __IO uint32_t Q0_FIRST_ADDR;                     /**< Q0 FIRST ADDR, offset: 0x4 */
  __IO uint32_t Q0_BASE_PTR;                       /**< Q0 BASE PTR, offset: 0x8 */
  __IO uint32_t Q0_CHNK_SIZE;                      /**< Q0 CHNK SIZE, offset: 0xC */
  __IO uint32_t Q0_DSC_EN_INC0;                    /**< Q0 DSC EN INC0, offset: 0x10 */
  __I  uint32_t Q0_STATUS;                         /**< Q0 STATUS, offset: 0x14 */
  __I  uint32_t Q0_RPTR_INT;                       /**< Q0 RPTR INT, offset: 0x18 */
  __I  uint32_t Q0_DSC_CFG;                        /**< Q0 DSC CFG, offset: 0x1C */
  __I  uint32_t Q0_DSC_SRCP;                       /**< Q0 DSC SRCP, offset: 0x20 */
  __I  uint32_t Q0_DSC_DSTP;                       /**< Q0 DSC DSTP, offset: 0x24 */
  __I  uint32_t Q0_DSC_DMASZ;                      /**< Q0 DSC DMASZ, offset: 0x28 */
  __I  uint32_t Q0_DSC_SRC;                        /**< Q0 DSC SRC, offset: 0x2C */
  __I  uint32_t Q0_DSC_LINE;                       /**< Q0 DSC LINE, offset: 0x30 */
  __I  uint32_t Q0_DSC_DST;                        /**< Q0 DSC DST, offset: 0x34 */
  __I  uint32_t Q0_DSC_HGHT;                       /**< Q0 DSC HGHT, offset: 0x38 */
  uint8_t RESERVED_0[4];
  __IO uint32_t Q0_DSC_EN_INC1;                    /**< Q0 DSC EN INC1, offset: 0x40 */
  __I  uint32_t Q0_EN_CNT;                         /**< Q0 EN CNT, offset: 0x44 */
} QUEUE_MANAGER_Type, *QUEUE_MANAGER_MemMapPtr;

/** Number of instances of the QUEUE_MANAGER module. */
#define QUEUE_MANAGER_INSTANCE_COUNT             (1u)

/* QUEUE_MANAGER - Peripheral instance base addresses */
/** Peripheral CEVA_SPF2__QUEUE_MANAGER base address */
#define IP_CEVA_SPF2__QUEUE_MANAGER_BASE         (0x24401200u)
/** Peripheral CEVA_SPF2__QUEUE_MANAGER base pointer */
#define IP_CEVA_SPF2__QUEUE_MANAGER              ((QUEUE_MANAGER_Type *)IP_CEVA_SPF2__QUEUE_MANAGER_BASE)
/** Array initializer of QUEUE_MANAGER peripheral base addresses */
#define IP_QUEUE_MANAGER_BASE_ADDRS              { IP_CEVA_SPF2__QUEUE_MANAGER_BASE }
/** Array initializer of QUEUE_MANAGER peripheral base pointers */
#define IP_QUEUE_MANAGER_BASE_PTRS               { IP_CEVA_SPF2__QUEUE_MANAGER }

/* ----------------------------------------------------------------------------
   -- QUEUE_MANAGER Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup QUEUE_MANAGER_Register_Masks QUEUE_MANAGER Register Masks
 * @{
 */

/*! @name Q0_EN_DEPTH - QX EN DEPTH */
/*! @{ */

#define QUEUE_MANAGER_Q0_EN_DEPTH_QX_DEPTH_MASK  (0x1FFFU)
#define QUEUE_MANAGER_Q0_EN_DEPTH_QX_DEPTH_SHIFT (0U)
#define QUEUE_MANAGER_Q0_EN_DEPTH_QX_DEPTH_WIDTH (13U)
#define QUEUE_MANAGER_Q0_EN_DEPTH_QX_DEPTH(x)    (((uint32_t)(((uint32_t)(x)) << QUEUE_MANAGER_Q0_EN_DEPTH_QX_DEPTH_SHIFT)) & QUEUE_MANAGER_Q0_EN_DEPTH_QX_DEPTH_MASK)

#define QUEUE_MANAGER_Q0_EN_DEPTH_QX_PRI_ABS_MASK (0xF0000U)
#define QUEUE_MANAGER_Q0_EN_DEPTH_QX_PRI_ABS_SHIFT (16U)
#define QUEUE_MANAGER_Q0_EN_DEPTH_QX_PRI_ABS_WIDTH (4U)
#define QUEUE_MANAGER_Q0_EN_DEPTH_QX_PRI_ABS(x)  (((uint32_t)(((uint32_t)(x)) << QUEUE_MANAGER_Q0_EN_DEPTH_QX_PRI_ABS_SHIFT)) & QUEUE_MANAGER_Q0_EN_DEPTH_QX_PRI_ABS_MASK)

#define QUEUE_MANAGER_Q0_EN_DEPTH_QX_PRI_ABS_SEL_MASK (0x100000U)
#define QUEUE_MANAGER_Q0_EN_DEPTH_QX_PRI_ABS_SEL_SHIFT (20U)
#define QUEUE_MANAGER_Q0_EN_DEPTH_QX_PRI_ABS_SEL_WIDTH (1U)
#define QUEUE_MANAGER_Q0_EN_DEPTH_QX_PRI_ABS_SEL(x) (((uint32_t)(((uint32_t)(x)) << QUEUE_MANAGER_Q0_EN_DEPTH_QX_PRI_ABS_SEL_SHIFT)) & QUEUE_MANAGER_Q0_EN_DEPTH_QX_PRI_ABS_SEL_MASK)

#define QUEUE_MANAGER_Q0_EN_DEPTH_QX_AUTO_MASK   (0x200000U)
#define QUEUE_MANAGER_Q0_EN_DEPTH_QX_AUTO_SHIFT  (21U)
#define QUEUE_MANAGER_Q0_EN_DEPTH_QX_AUTO_WIDTH  (1U)
#define QUEUE_MANAGER_Q0_EN_DEPTH_QX_AUTO(x)     (((uint32_t)(((uint32_t)(x)) << QUEUE_MANAGER_Q0_EN_DEPTH_QX_AUTO_SHIFT)) & QUEUE_MANAGER_Q0_EN_DEPTH_QX_AUTO_MASK)

#define QUEUE_MANAGER_Q0_EN_DEPTH_QX_CEX_PAUSE_MASK (0x400000U)
#define QUEUE_MANAGER_Q0_EN_DEPTH_QX_CEX_PAUSE_SHIFT (22U)
#define QUEUE_MANAGER_Q0_EN_DEPTH_QX_CEX_PAUSE_WIDTH (1U)
#define QUEUE_MANAGER_Q0_EN_DEPTH_QX_CEX_PAUSE(x) (((uint32_t)(((uint32_t)(x)) << QUEUE_MANAGER_Q0_EN_DEPTH_QX_CEX_PAUSE_SHIFT)) & QUEUE_MANAGER_Q0_EN_DEPTH_QX_CEX_PAUSE_MASK)

#define QUEUE_MANAGER_Q0_EN_DEPTH_QX_CONT_FRAME_MASK (0x40000000U)
#define QUEUE_MANAGER_Q0_EN_DEPTH_QX_CONT_FRAME_SHIFT (30U)
#define QUEUE_MANAGER_Q0_EN_DEPTH_QX_CONT_FRAME_WIDTH (1U)
#define QUEUE_MANAGER_Q0_EN_DEPTH_QX_CONT_FRAME(x) (((uint32_t)(((uint32_t)(x)) << QUEUE_MANAGER_Q0_EN_DEPTH_QX_CONT_FRAME_SHIFT)) & QUEUE_MANAGER_Q0_EN_DEPTH_QX_CONT_FRAME_MASK)

#define QUEUE_MANAGER_Q0_EN_DEPTH_QX_EN_MASK     (0x80000000U)
#define QUEUE_MANAGER_Q0_EN_DEPTH_QX_EN_SHIFT    (31U)
#define QUEUE_MANAGER_Q0_EN_DEPTH_QX_EN_WIDTH    (1U)
#define QUEUE_MANAGER_Q0_EN_DEPTH_QX_EN(x)       (((uint32_t)(((uint32_t)(x)) << QUEUE_MANAGER_Q0_EN_DEPTH_QX_EN_SHIFT)) & QUEUE_MANAGER_Q0_EN_DEPTH_QX_EN_MASK)
/*! @} */

/*! @name Q0_FIRST_ADDR - Q0 FIRST ADDR */
/*! @{ */

#define QUEUE_MANAGER_Q0_FIRST_ADDR_QX_FIRST_ADDR_MASK (0xFFFFFFFFU)
#define QUEUE_MANAGER_Q0_FIRST_ADDR_QX_FIRST_ADDR_SHIFT (0U)
#define QUEUE_MANAGER_Q0_FIRST_ADDR_QX_FIRST_ADDR_WIDTH (32U)
#define QUEUE_MANAGER_Q0_FIRST_ADDR_QX_FIRST_ADDR(x) (((uint32_t)(((uint32_t)(x)) << QUEUE_MANAGER_Q0_FIRST_ADDR_QX_FIRST_ADDR_SHIFT)) & QUEUE_MANAGER_Q0_FIRST_ADDR_QX_FIRST_ADDR_MASK)
/*! @} */

/*! @name Q0_BASE_PTR - Q0 BASE PTR */
/*! @{ */

#define QUEUE_MANAGER_Q0_BASE_PTR_QX_BASE_PTR_MASK (0xFFFFFFFFU)
#define QUEUE_MANAGER_Q0_BASE_PTR_QX_BASE_PTR_SHIFT (0U)
#define QUEUE_MANAGER_Q0_BASE_PTR_QX_BASE_PTR_WIDTH (32U)
#define QUEUE_MANAGER_Q0_BASE_PTR_QX_BASE_PTR(x) (((uint32_t)(((uint32_t)(x)) << QUEUE_MANAGER_Q0_BASE_PTR_QX_BASE_PTR_SHIFT)) & QUEUE_MANAGER_Q0_BASE_PTR_QX_BASE_PTR_MASK)
/*! @} */

/*! @name Q0_CHNK_SIZE - Q0 CHNK SIZE */
/*! @{ */

#define QUEUE_MANAGER_Q0_CHNK_SIZE_QX_CHNK_SIZE_MASK (0x3FFFU)
#define QUEUE_MANAGER_Q0_CHNK_SIZE_QX_CHNK_SIZE_SHIFT (0U)
#define QUEUE_MANAGER_Q0_CHNK_SIZE_QX_CHNK_SIZE_WIDTH (14U)
#define QUEUE_MANAGER_Q0_CHNK_SIZE_QX_CHNK_SIZE(x) (((uint32_t)(((uint32_t)(x)) << QUEUE_MANAGER_Q0_CHNK_SIZE_QX_CHNK_SIZE_SHIFT)) & QUEUE_MANAGER_Q0_CHNK_SIZE_QX_CHNK_SIZE_MASK)

#define QUEUE_MANAGER_Q0_CHNK_SIZE_QX_CHNK_LINES_MASK (0xFFFF0000U)
#define QUEUE_MANAGER_Q0_CHNK_SIZE_QX_CHNK_LINES_SHIFT (16U)
#define QUEUE_MANAGER_Q0_CHNK_SIZE_QX_CHNK_LINES_WIDTH (16U)
#define QUEUE_MANAGER_Q0_CHNK_SIZE_QX_CHNK_LINES(x) (((uint32_t)(((uint32_t)(x)) << QUEUE_MANAGER_Q0_CHNK_SIZE_QX_CHNK_LINES_SHIFT)) & QUEUE_MANAGER_Q0_CHNK_SIZE_QX_CHNK_LINES_MASK)
/*! @} */

/*! @name Q0_DSC_EN_INC0 - Q0 DSC EN INC0 */
/*! @{ */

#define QUEUE_MANAGER_Q0_DSC_EN_INC0_QX_EN_INC_VAL0_MASK (0x7FFU)
#define QUEUE_MANAGER_Q0_DSC_EN_INC0_QX_EN_INC_VAL0_SHIFT (0U)
#define QUEUE_MANAGER_Q0_DSC_EN_INC0_QX_EN_INC_VAL0_WIDTH (11U)
#define QUEUE_MANAGER_Q0_DSC_EN_INC0_QX_EN_INC_VAL0(x) (((uint32_t)(((uint32_t)(x)) << QUEUE_MANAGER_Q0_DSC_EN_INC0_QX_EN_INC_VAL0_SHIFT)) & QUEUE_MANAGER_Q0_DSC_EN_INC0_QX_EN_INC_VAL0_MASK)

#define QUEUE_MANAGER_Q0_DSC_EN_INC0_QX_DSC_EN0_MASK (0x10000U)
#define QUEUE_MANAGER_Q0_DSC_EN_INC0_QX_DSC_EN0_SHIFT (16U)
#define QUEUE_MANAGER_Q0_DSC_EN_INC0_QX_DSC_EN0_WIDTH (1U)
#define QUEUE_MANAGER_Q0_DSC_EN_INC0_QX_DSC_EN0(x) (((uint32_t)(((uint32_t)(x)) << QUEUE_MANAGER_Q0_DSC_EN_INC0_QX_DSC_EN0_SHIFT)) & QUEUE_MANAGER_Q0_DSC_EN_INC0_QX_DSC_EN0_MASK)

#define QUEUE_MANAGER_Q0_DSC_EN_INC0_QX_DSC_CNT_CFG_0_MASK (0x20000U)
#define QUEUE_MANAGER_Q0_DSC_EN_INC0_QX_DSC_CNT_CFG_0_SHIFT (17U)
#define QUEUE_MANAGER_Q0_DSC_EN_INC0_QX_DSC_CNT_CFG_0_WIDTH (1U)
#define QUEUE_MANAGER_Q0_DSC_EN_INC0_QX_DSC_CNT_CFG_0(x) (((uint32_t)(((uint32_t)(x)) << QUEUE_MANAGER_Q0_DSC_EN_INC0_QX_DSC_CNT_CFG_0_SHIFT)) & QUEUE_MANAGER_Q0_DSC_EN_INC0_QX_DSC_CNT_CFG_0_MASK)

#define QUEUE_MANAGER_Q0_DSC_EN_INC0_QX_EN_CNT_DIS0_MASK (0x80000000U)
#define QUEUE_MANAGER_Q0_DSC_EN_INC0_QX_EN_CNT_DIS0_SHIFT (31U)
#define QUEUE_MANAGER_Q0_DSC_EN_INC0_QX_EN_CNT_DIS0_WIDTH (1U)
#define QUEUE_MANAGER_Q0_DSC_EN_INC0_QX_EN_CNT_DIS0(x) (((uint32_t)(((uint32_t)(x)) << QUEUE_MANAGER_Q0_DSC_EN_INC0_QX_EN_CNT_DIS0_SHIFT)) & QUEUE_MANAGER_Q0_DSC_EN_INC0_QX_EN_CNT_DIS0_MASK)
/*! @} */

/*! @name Q0_STATUS - Q0 STATUS */
/*! @{ */

#define QUEUE_MANAGER_Q0_STATUS_QX_WD_WAIT_MASK  (0x40000000U)
#define QUEUE_MANAGER_Q0_STATUS_QX_WD_WAIT_SHIFT (30U)
#define QUEUE_MANAGER_Q0_STATUS_QX_WD_WAIT_WIDTH (1U)
#define QUEUE_MANAGER_Q0_STATUS_QX_WD_WAIT(x)    (((uint32_t)(((uint32_t)(x)) << QUEUE_MANAGER_Q0_STATUS_QX_WD_WAIT_SHIFT)) & QUEUE_MANAGER_Q0_STATUS_QX_WD_WAIT_MASK)

#define QUEUE_MANAGER_Q0_STATUS_QX_STATUS_MASK   (0x80000000U)
#define QUEUE_MANAGER_Q0_STATUS_QX_STATUS_SHIFT  (31U)
#define QUEUE_MANAGER_Q0_STATUS_QX_STATUS_WIDTH  (1U)
#define QUEUE_MANAGER_Q0_STATUS_QX_STATUS(x)     (((uint32_t)(((uint32_t)(x)) << QUEUE_MANAGER_Q0_STATUS_QX_STATUS_SHIFT)) & QUEUE_MANAGER_Q0_STATUS_QX_STATUS_MASK)
/*! @} */

/*! @name Q0_RPTR_INT - Q0 RPTR INT */
/*! @{ */

#define QUEUE_MANAGER_Q0_RPTR_INT_QX_RPTR_INT_MASK (0x3FFFFU)
#define QUEUE_MANAGER_Q0_RPTR_INT_QX_RPTR_INT_SHIFT (0U)
#define QUEUE_MANAGER_Q0_RPTR_INT_QX_RPTR_INT_WIDTH (18U)
#define QUEUE_MANAGER_Q0_RPTR_INT_QX_RPTR_INT(x) (((uint32_t)(((uint32_t)(x)) << QUEUE_MANAGER_Q0_RPTR_INT_QX_RPTR_INT_SHIFT)) & QUEUE_MANAGER_Q0_RPTR_INT_QX_RPTR_INT_MASK)
/*! @} */

/*! @name Q0_DSC_CFG - Q0 DSC CFG */
/*! @{ */

#define QUEUE_MANAGER_Q0_DSC_CFG_QX_DSC_CFG_MASK (0xFFFFFFFFU)
#define QUEUE_MANAGER_Q0_DSC_CFG_QX_DSC_CFG_SHIFT (0U)
#define QUEUE_MANAGER_Q0_DSC_CFG_QX_DSC_CFG_WIDTH (32U)
#define QUEUE_MANAGER_Q0_DSC_CFG_QX_DSC_CFG(x)   (((uint32_t)(((uint32_t)(x)) << QUEUE_MANAGER_Q0_DSC_CFG_QX_DSC_CFG_SHIFT)) & QUEUE_MANAGER_Q0_DSC_CFG_QX_DSC_CFG_MASK)
/*! @} */

/*! @name Q0_DSC_SRCP - Q0 DSC SRCP */
/*! @{ */

#define QUEUE_MANAGER_Q0_DSC_SRCP_QX_DSC_SRCP_MASK (0xFFFFFFFFU)
#define QUEUE_MANAGER_Q0_DSC_SRCP_QX_DSC_SRCP_SHIFT (0U)
#define QUEUE_MANAGER_Q0_DSC_SRCP_QX_DSC_SRCP_WIDTH (32U)
#define QUEUE_MANAGER_Q0_DSC_SRCP_QX_DSC_SRCP(x) (((uint32_t)(((uint32_t)(x)) << QUEUE_MANAGER_Q0_DSC_SRCP_QX_DSC_SRCP_SHIFT)) & QUEUE_MANAGER_Q0_DSC_SRCP_QX_DSC_SRCP_MASK)
/*! @} */

/*! @name Q0_DSC_DSTP - Q0 DSC DSTP */
/*! @{ */

#define QUEUE_MANAGER_Q0_DSC_DSTP_QX_DSC_DSTP_MASK (0xFFFFFFFFU)
#define QUEUE_MANAGER_Q0_DSC_DSTP_QX_DSC_DSTP_SHIFT (0U)
#define QUEUE_MANAGER_Q0_DSC_DSTP_QX_DSC_DSTP_WIDTH (32U)
#define QUEUE_MANAGER_Q0_DSC_DSTP_QX_DSC_DSTP(x) (((uint32_t)(((uint32_t)(x)) << QUEUE_MANAGER_Q0_DSC_DSTP_QX_DSC_DSTP_SHIFT)) & QUEUE_MANAGER_Q0_DSC_DSTP_QX_DSC_DSTP_MASK)
/*! @} */

/*! @name Q0_DSC_DMASZ - Q0 DSC DMASZ */
/*! @{ */

#define QUEUE_MANAGER_Q0_DSC_DMASZ_QX_DSC_DMASZ_MASK (0xFFFFFFFFU)
#define QUEUE_MANAGER_Q0_DSC_DMASZ_QX_DSC_DMASZ_SHIFT (0U)
#define QUEUE_MANAGER_Q0_DSC_DMASZ_QX_DSC_DMASZ_WIDTH (32U)
#define QUEUE_MANAGER_Q0_DSC_DMASZ_QX_DSC_DMASZ(x) (((uint32_t)(((uint32_t)(x)) << QUEUE_MANAGER_Q0_DSC_DMASZ_QX_DSC_DMASZ_SHIFT)) & QUEUE_MANAGER_Q0_DSC_DMASZ_QX_DSC_DMASZ_MASK)
/*! @} */

/*! @name Q0_DSC_SRC - Q0 DSC SRC */
/*! @{ */

#define QUEUE_MANAGER_Q0_DSC_SRC_QX_DSC_SRC_MASK (0xFFFFFFFFU)
#define QUEUE_MANAGER_Q0_DSC_SRC_QX_DSC_SRC_SHIFT (0U)
#define QUEUE_MANAGER_Q0_DSC_SRC_QX_DSC_SRC_WIDTH (32U)
#define QUEUE_MANAGER_Q0_DSC_SRC_QX_DSC_SRC(x)   (((uint32_t)(((uint32_t)(x)) << QUEUE_MANAGER_Q0_DSC_SRC_QX_DSC_SRC_SHIFT)) & QUEUE_MANAGER_Q0_DSC_SRC_QX_DSC_SRC_MASK)
/*! @} */

/*! @name Q0_DSC_LINE - Q0 DSC LINE */
/*! @{ */

#define QUEUE_MANAGER_Q0_DSC_LINE_QX_DSC_LINE_MASK (0xFFFFFFFFU)
#define QUEUE_MANAGER_Q0_DSC_LINE_QX_DSC_LINE_SHIFT (0U)
#define QUEUE_MANAGER_Q0_DSC_LINE_QX_DSC_LINE_WIDTH (32U)
#define QUEUE_MANAGER_Q0_DSC_LINE_QX_DSC_LINE(x) (((uint32_t)(((uint32_t)(x)) << QUEUE_MANAGER_Q0_DSC_LINE_QX_DSC_LINE_SHIFT)) & QUEUE_MANAGER_Q0_DSC_LINE_QX_DSC_LINE_MASK)
/*! @} */

/*! @name Q0_DSC_DST - Q0 DSC DST */
/*! @{ */

#define QUEUE_MANAGER_Q0_DSC_DST_QX_DSC_DST_MASK (0xFFFFFFFFU)
#define QUEUE_MANAGER_Q0_DSC_DST_QX_DSC_DST_SHIFT (0U)
#define QUEUE_MANAGER_Q0_DSC_DST_QX_DSC_DST_WIDTH (32U)
#define QUEUE_MANAGER_Q0_DSC_DST_QX_DSC_DST(x)   (((uint32_t)(((uint32_t)(x)) << QUEUE_MANAGER_Q0_DSC_DST_QX_DSC_DST_SHIFT)) & QUEUE_MANAGER_Q0_DSC_DST_QX_DSC_DST_MASK)
/*! @} */

/*! @name Q0_DSC_HGHT - Q0 DSC HGHT */
/*! @{ */

#define QUEUE_MANAGER_Q0_DSC_HGHT_QX_DSC_HGHT_MASK (0xFFFFFFFFU)
#define QUEUE_MANAGER_Q0_DSC_HGHT_QX_DSC_HGHT_SHIFT (0U)
#define QUEUE_MANAGER_Q0_DSC_HGHT_QX_DSC_HGHT_WIDTH (32U)
#define QUEUE_MANAGER_Q0_DSC_HGHT_QX_DSC_HGHT(x) (((uint32_t)(((uint32_t)(x)) << QUEUE_MANAGER_Q0_DSC_HGHT_QX_DSC_HGHT_SHIFT)) & QUEUE_MANAGER_Q0_DSC_HGHT_QX_DSC_HGHT_MASK)
/*! @} */

/*! @name Q0_DSC_EN_INC1 - Q0 DSC EN INC1 */
/*! @{ */

#define QUEUE_MANAGER_Q0_DSC_EN_INC1_QX_EN_INC_VAL1_MASK (0x7FFU)
#define QUEUE_MANAGER_Q0_DSC_EN_INC1_QX_EN_INC_VAL1_SHIFT (0U)
#define QUEUE_MANAGER_Q0_DSC_EN_INC1_QX_EN_INC_VAL1_WIDTH (11U)
#define QUEUE_MANAGER_Q0_DSC_EN_INC1_QX_EN_INC_VAL1(x) (((uint32_t)(((uint32_t)(x)) << QUEUE_MANAGER_Q0_DSC_EN_INC1_QX_EN_INC_VAL1_SHIFT)) & QUEUE_MANAGER_Q0_DSC_EN_INC1_QX_EN_INC_VAL1_MASK)

#define QUEUE_MANAGER_Q0_DSC_EN_INC1_QX_DSC_EN1_MASK (0x10000U)
#define QUEUE_MANAGER_Q0_DSC_EN_INC1_QX_DSC_EN1_SHIFT (16U)
#define QUEUE_MANAGER_Q0_DSC_EN_INC1_QX_DSC_EN1_WIDTH (1U)
#define QUEUE_MANAGER_Q0_DSC_EN_INC1_QX_DSC_EN1(x) (((uint32_t)(((uint32_t)(x)) << QUEUE_MANAGER_Q0_DSC_EN_INC1_QX_DSC_EN1_SHIFT)) & QUEUE_MANAGER_Q0_DSC_EN_INC1_QX_DSC_EN1_MASK)

#define QUEUE_MANAGER_Q0_DSC_EN_INC1_QX_DSC_CNT_CFG_1_MASK (0x20000U)
#define QUEUE_MANAGER_Q0_DSC_EN_INC1_QX_DSC_CNT_CFG_1_SHIFT (17U)
#define QUEUE_MANAGER_Q0_DSC_EN_INC1_QX_DSC_CNT_CFG_1_WIDTH (1U)
#define QUEUE_MANAGER_Q0_DSC_EN_INC1_QX_DSC_CNT_CFG_1(x) (((uint32_t)(((uint32_t)(x)) << QUEUE_MANAGER_Q0_DSC_EN_INC1_QX_DSC_CNT_CFG_1_SHIFT)) & QUEUE_MANAGER_Q0_DSC_EN_INC1_QX_DSC_CNT_CFG_1_MASK)

#define QUEUE_MANAGER_Q0_DSC_EN_INC1_QX_EN_CNT_DIS1_MASK (0x80000000U)
#define QUEUE_MANAGER_Q0_DSC_EN_INC1_QX_EN_CNT_DIS1_SHIFT (31U)
#define QUEUE_MANAGER_Q0_DSC_EN_INC1_QX_EN_CNT_DIS1_WIDTH (1U)
#define QUEUE_MANAGER_Q0_DSC_EN_INC1_QX_EN_CNT_DIS1(x) (((uint32_t)(((uint32_t)(x)) << QUEUE_MANAGER_Q0_DSC_EN_INC1_QX_EN_CNT_DIS1_SHIFT)) & QUEUE_MANAGER_Q0_DSC_EN_INC1_QX_EN_CNT_DIS1_MASK)
/*! @} */

/*! @name Q0_EN_CNT - Q0 EN CNT */
/*! @{ */

#define QUEUE_MANAGER_Q0_EN_CNT_QX_EN_CNT0_MASK  (0x3FFFU)
#define QUEUE_MANAGER_Q0_EN_CNT_QX_EN_CNT0_SHIFT (0U)
#define QUEUE_MANAGER_Q0_EN_CNT_QX_EN_CNT0_WIDTH (14U)
#define QUEUE_MANAGER_Q0_EN_CNT_QX_EN_CNT0(x)    (((uint32_t)(((uint32_t)(x)) << QUEUE_MANAGER_Q0_EN_CNT_QX_EN_CNT0_SHIFT)) & QUEUE_MANAGER_Q0_EN_CNT_QX_EN_CNT0_MASK)

#define QUEUE_MANAGER_Q0_EN_CNT_QX_EN_CNT1_MASK  (0x3FFF0000U)
#define QUEUE_MANAGER_Q0_EN_CNT_QX_EN_CNT1_SHIFT (16U)
#define QUEUE_MANAGER_Q0_EN_CNT_QX_EN_CNT1_WIDTH (14U)
#define QUEUE_MANAGER_Q0_EN_CNT_QX_EN_CNT1(x)    (((uint32_t)(((uint32_t)(x)) << QUEUE_MANAGER_Q0_EN_CNT_QX_EN_CNT1_SHIFT)) & QUEUE_MANAGER_Q0_EN_CNT_QX_EN_CNT1_MASK)

#define QUEUE_MANAGER_Q0_EN_CNT_QX_WD_WAIT_MASK  (0x40000000U)
#define QUEUE_MANAGER_Q0_EN_CNT_QX_WD_WAIT_SHIFT (30U)
#define QUEUE_MANAGER_Q0_EN_CNT_QX_WD_WAIT_WIDTH (1U)
#define QUEUE_MANAGER_Q0_EN_CNT_QX_WD_WAIT(x)    (((uint32_t)(((uint32_t)(x)) << QUEUE_MANAGER_Q0_EN_CNT_QX_WD_WAIT_SHIFT)) & QUEUE_MANAGER_Q0_EN_CNT_QX_WD_WAIT_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group QUEUE_MANAGER_Register_Masks */

/*!
 * @}
 */ /* end of group QUEUE_MANAGER_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_QUEUE_MANAGER_H_) */
