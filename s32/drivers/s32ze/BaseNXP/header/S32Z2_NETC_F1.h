/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_NETC_F1.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_NETC_F1
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
#if !defined(S32Z2_NETC_F1_H_)  /* Check if memory map has not been already included */
#define S32Z2_NETC_F1_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- NETC_F1 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NETC_F1_Peripheral_Access_Layer NETC_F1 Peripheral Access Layer
 * @{
 */

/** NETC_F1 - Register Layout Typedef */
typedef struct {
  uint8_t RESERVED_0[7168];
  __IO uint32_t EMDIO_CFG;                         /**< External MDIO configuration register, offset: 0x1C00 */
  __IO uint32_t EMDIO_CTL;                         /**< External MDIO interface control register, offset: 0x1C04 */
  __IO uint32_t EMDIO_DATA;                        /**< External MDIO interface data register, offset: 0x1C08 */
  __IO uint32_t EMDIO_ADDR;                        /**< External MDIO register address register, offset: 0x1C0C */
  __I  uint32_t EMDIO_STAT;                        /**< External MDIO status register, offset: 0x1C10 */
  uint8_t RESERVED_1[12];
  __IO uint32_t PHY_STATUS_CFG;                    /**< PHY status configuration register, offset: 0x1C20 */
  __IO uint32_t PHY_STATUS_CTL;                    /**< PHY status control register, offset: 0x1C24 */
  __I  uint32_t PHY_STATUS_DATA;                   /**< PHY status data register, offset: 0x1C28 */
  __IO uint32_t PHY_STATUS_ADDR;                   /**< PHY status register address register, offset: 0x1C2C */
  __IO uint32_t PHY_STATUS_EVENT;                  /**< PHY status event register, offset: 0x1C30 */
  __IO uint32_t PHY_STATUS_MASK;                   /**< PHY status mask register, offset: 0x1C34 */
  uint8_t RESERVED_2[8];
  __I  uint32_t MDIO_CFG;                          /**< MDIO configuration register, offset: 0x1C40 */
} NETC_F1_Type, *NETC_F1_MemMapPtr;

/** Number of instances of the NETC_F1 module. */
#define NETC_F1_INSTANCE_COUNT                   (1)

/* NETC_F1 - Peripheral instance base addresses */
/** Peripheral NETC__EMDIO_BASE base address */
#define IP_NETC__EMDIO_BASE_BASE                 (0x74B60000u)
/** Peripheral NETC__EMDIO_BASE base pointer */
#define IP_NETC__EMDIO_BASE                      ((NETC_F1_Type *)IP_NETC__EMDIO_BASE_BASE)
/** Array initializer of NETC_F1 peripheral base addresses */
#define IP_NETC_F1_BASE_ADDRS                    { IP_NETC__EMDIO_BASE_BASE }
/** Array initializer of NETC_F1 peripheral base pointers */
#define IP_NETC_F1_BASE_PTRS                     { IP_NETC__EMDIO_BASE }

/* ----------------------------------------------------------------------------
   -- NETC_F1 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NETC_F1_Register_Masks NETC_F1 Register Masks
 * @{
 */

/*! @name EMDIO_CFG - External MDIO configuration register */
/*! @{ */

#define NETC_F1_EMDIO_CFG_BSY2_MASK              (0x1U)
#define NETC_F1_EMDIO_CFG_BSY2_SHIFT             (0U)
#define NETC_F1_EMDIO_CFG_BSY2_WIDTH             (1U)
#define NETC_F1_EMDIO_CFG_BSY2(x)                (((uint32_t)(((uint32_t)(x)) << NETC_F1_EMDIO_CFG_BSY2_SHIFT)) & NETC_F1_EMDIO_CFG_BSY2_MASK)

#define NETC_F1_EMDIO_CFG_MDIO_RD_ER_MASK        (0x2U)
#define NETC_F1_EMDIO_CFG_MDIO_RD_ER_SHIFT       (1U)
#define NETC_F1_EMDIO_CFG_MDIO_RD_ER_WIDTH       (1U)
#define NETC_F1_EMDIO_CFG_MDIO_RD_ER(x)          (((uint32_t)(((uint32_t)(x)) << NETC_F1_EMDIO_CFG_MDIO_RD_ER_SHIFT)) & NETC_F1_EMDIO_CFG_MDIO_RD_ER_MASK)

#define NETC_F1_EMDIO_CFG_MDIO_HOLD_MASK         (0x1CU)
#define NETC_F1_EMDIO_CFG_MDIO_HOLD_SHIFT        (2U)
#define NETC_F1_EMDIO_CFG_MDIO_HOLD_WIDTH        (3U)
#define NETC_F1_EMDIO_CFG_MDIO_HOLD(x)           (((uint32_t)(((uint32_t)(x)) << NETC_F1_EMDIO_CFG_MDIO_HOLD_SHIFT)) & NETC_F1_EMDIO_CFG_MDIO_HOLD_MASK)

#define NETC_F1_EMDIO_CFG_PRE_DIS_MASK           (0x20U)
#define NETC_F1_EMDIO_CFG_PRE_DIS_SHIFT          (5U)
#define NETC_F1_EMDIO_CFG_PRE_DIS_WIDTH          (1U)
#define NETC_F1_EMDIO_CFG_PRE_DIS(x)             (((uint32_t)(((uint32_t)(x)) << NETC_F1_EMDIO_CFG_PRE_DIS_SHIFT)) & NETC_F1_EMDIO_CFG_PRE_DIS_MASK)

#define NETC_F1_EMDIO_CFG_ENC45_MASK             (0x40U)
#define NETC_F1_EMDIO_CFG_ENC45_SHIFT            (6U)
#define NETC_F1_EMDIO_CFG_ENC45_WIDTH            (1U)
#define NETC_F1_EMDIO_CFG_ENC45(x)               (((uint32_t)(((uint32_t)(x)) << NETC_F1_EMDIO_CFG_ENC45_SHIFT)) & NETC_F1_EMDIO_CFG_ENC45_MASK)

#define NETC_F1_EMDIO_CFG_MDIO_CLK_DIV_MASK      (0xFF80U)
#define NETC_F1_EMDIO_CFG_MDIO_CLK_DIV_SHIFT     (7U)
#define NETC_F1_EMDIO_CFG_MDIO_CLK_DIV_WIDTH     (9U)
#define NETC_F1_EMDIO_CFG_MDIO_CLK_DIV(x)        (((uint32_t)(((uint32_t)(x)) << NETC_F1_EMDIO_CFG_MDIO_CLK_DIV_SHIFT)) & NETC_F1_EMDIO_CFG_MDIO_CLK_DIV_MASK)

#define NETC_F1_EMDIO_CFG_WHOAMI_MASK            (0x70000U)
#define NETC_F1_EMDIO_CFG_WHOAMI_SHIFT           (16U)
#define NETC_F1_EMDIO_CFG_WHOAMI_WIDTH           (3U)
#define NETC_F1_EMDIO_CFG_WHOAMI(x)              (((uint32_t)(((uint32_t)(x)) << NETC_F1_EMDIO_CFG_WHOAMI_SHIFT)) & NETC_F1_EMDIO_CFG_WHOAMI_MASK)

#define NETC_F1_EMDIO_CFG_EHOLD_MASK             (0x400000U)
#define NETC_F1_EMDIO_CFG_EHOLD_SHIFT            (22U)
#define NETC_F1_EMDIO_CFG_EHOLD_WIDTH            (1U)
#define NETC_F1_EMDIO_CFG_EHOLD(x)               (((uint32_t)(((uint32_t)(x)) << NETC_F1_EMDIO_CFG_EHOLD_SHIFT)) & NETC_F1_EMDIO_CFG_EHOLD_MASK)

#define NETC_F1_EMDIO_CFG_NEG_MASK               (0x800000U)
#define NETC_F1_EMDIO_CFG_NEG_SHIFT              (23U)
#define NETC_F1_EMDIO_CFG_NEG_WIDTH              (1U)
#define NETC_F1_EMDIO_CFG_NEG(x)                 (((uint32_t)(((uint32_t)(x)) << NETC_F1_EMDIO_CFG_NEG_SHIFT)) & NETC_F1_EMDIO_CFG_NEG_MASK)

#define NETC_F1_EMDIO_CFG_ADDR_ERR_MASK          (0x10000000U)
#define NETC_F1_EMDIO_CFG_ADDR_ERR_SHIFT         (28U)
#define NETC_F1_EMDIO_CFG_ADDR_ERR_WIDTH         (1U)
#define NETC_F1_EMDIO_CFG_ADDR_ERR(x)            (((uint32_t)(((uint32_t)(x)) << NETC_F1_EMDIO_CFG_ADDR_ERR_SHIFT)) & NETC_F1_EMDIO_CFG_ADDR_ERR_MASK)

#define NETC_F1_EMDIO_CFG_CIM_MASK               (0x20000000U)
#define NETC_F1_EMDIO_CFG_CIM_SHIFT              (29U)
#define NETC_F1_EMDIO_CFG_CIM_WIDTH              (1U)
#define NETC_F1_EMDIO_CFG_CIM(x)                 (((uint32_t)(((uint32_t)(x)) << NETC_F1_EMDIO_CFG_CIM_SHIFT)) & NETC_F1_EMDIO_CFG_CIM_MASK)

#define NETC_F1_EMDIO_CFG_CMP_MASK               (0x40000000U)
#define NETC_F1_EMDIO_CFG_CMP_SHIFT              (30U)
#define NETC_F1_EMDIO_CFG_CMP_WIDTH              (1U)
#define NETC_F1_EMDIO_CFG_CMP(x)                 (((uint32_t)(((uint32_t)(x)) << NETC_F1_EMDIO_CFG_CMP_SHIFT)) & NETC_F1_EMDIO_CFG_CMP_MASK)

#define NETC_F1_EMDIO_CFG_BSY1_MASK              (0x80000000U)
#define NETC_F1_EMDIO_CFG_BSY1_SHIFT             (31U)
#define NETC_F1_EMDIO_CFG_BSY1_WIDTH             (1U)
#define NETC_F1_EMDIO_CFG_BSY1(x)                (((uint32_t)(((uint32_t)(x)) << NETC_F1_EMDIO_CFG_BSY1_SHIFT)) & NETC_F1_EMDIO_CFG_BSY1_MASK)
/*! @} */

/*! @name EMDIO_CTL - External MDIO interface control register */
/*! @{ */

#define NETC_F1_EMDIO_CTL_DEV_ADDR_MASK          (0x1FU)
#define NETC_F1_EMDIO_CTL_DEV_ADDR_SHIFT         (0U)
#define NETC_F1_EMDIO_CTL_DEV_ADDR_WIDTH         (5U)
#define NETC_F1_EMDIO_CTL_DEV_ADDR(x)            (((uint32_t)(((uint32_t)(x)) << NETC_F1_EMDIO_CTL_DEV_ADDR_SHIFT)) & NETC_F1_EMDIO_CTL_DEV_ADDR_MASK)

#define NETC_F1_EMDIO_CTL_PORT_ADDR_MASK         (0x3E0U)
#define NETC_F1_EMDIO_CTL_PORT_ADDR_SHIFT        (5U)
#define NETC_F1_EMDIO_CTL_PORT_ADDR_WIDTH        (5U)
#define NETC_F1_EMDIO_CTL_PORT_ADDR(x)           (((uint32_t)(((uint32_t)(x)) << NETC_F1_EMDIO_CTL_PORT_ADDR_SHIFT)) & NETC_F1_EMDIO_CTL_PORT_ADDR_MASK)

#define NETC_F1_EMDIO_CTL_POST_INC_MASK          (0x4000U)
#define NETC_F1_EMDIO_CTL_POST_INC_SHIFT         (14U)
#define NETC_F1_EMDIO_CTL_POST_INC_WIDTH         (1U)
#define NETC_F1_EMDIO_CTL_POST_INC(x)            (((uint32_t)(((uint32_t)(x)) << NETC_F1_EMDIO_CTL_POST_INC_SHIFT)) & NETC_F1_EMDIO_CTL_POST_INC_MASK)

#define NETC_F1_EMDIO_CTL_READ_MASK              (0x8000U)
#define NETC_F1_EMDIO_CTL_READ_SHIFT             (15U)
#define NETC_F1_EMDIO_CTL_READ_WIDTH             (1U)
#define NETC_F1_EMDIO_CTL_READ(x)                (((uint32_t)(((uint32_t)(x)) << NETC_F1_EMDIO_CTL_READ_SHIFT)) & NETC_F1_EMDIO_CTL_READ_MASK)

#define NETC_F1_EMDIO_CTL_BSY_MASK               (0x80000000U)
#define NETC_F1_EMDIO_CTL_BSY_SHIFT              (31U)
#define NETC_F1_EMDIO_CTL_BSY_WIDTH              (1U)
#define NETC_F1_EMDIO_CTL_BSY(x)                 (((uint32_t)(((uint32_t)(x)) << NETC_F1_EMDIO_CTL_BSY_SHIFT)) & NETC_F1_EMDIO_CTL_BSY_MASK)
/*! @} */

/*! @name EMDIO_DATA - External MDIO interface data register */
/*! @{ */

#define NETC_F1_EMDIO_DATA_MDIO_DATA_MASK        (0xFFFFU)
#define NETC_F1_EMDIO_DATA_MDIO_DATA_SHIFT       (0U)
#define NETC_F1_EMDIO_DATA_MDIO_DATA_WIDTH       (16U)
#define NETC_F1_EMDIO_DATA_MDIO_DATA(x)          (((uint32_t)(((uint32_t)(x)) << NETC_F1_EMDIO_DATA_MDIO_DATA_SHIFT)) & NETC_F1_EMDIO_DATA_MDIO_DATA_MASK)
/*! @} */

/*! @name EMDIO_ADDR - External MDIO register address register */
/*! @{ */

#define NETC_F1_EMDIO_ADDR_REGADDR_MASK          (0xFFFFU)
#define NETC_F1_EMDIO_ADDR_REGADDR_SHIFT         (0U)
#define NETC_F1_EMDIO_ADDR_REGADDR_WIDTH         (16U)
#define NETC_F1_EMDIO_ADDR_REGADDR(x)            (((uint32_t)(((uint32_t)(x)) << NETC_F1_EMDIO_ADDR_REGADDR_SHIFT)) & NETC_F1_EMDIO_ADDR_REGADDR_MASK)
/*! @} */

/*! @name EMDIO_STAT - External MDIO status register */
/*! @{ */

#define NETC_F1_EMDIO_STAT_BSY_MASK              (0x1U)
#define NETC_F1_EMDIO_STAT_BSY_SHIFT             (0U)
#define NETC_F1_EMDIO_STAT_BSY_WIDTH             (1U)
#define NETC_F1_EMDIO_STAT_BSY(x)                (((uint32_t)(((uint32_t)(x)) << NETC_F1_EMDIO_STAT_BSY_SHIFT)) & NETC_F1_EMDIO_STAT_BSY_MASK)

#define NETC_F1_EMDIO_STAT_WHT_LIST_MASK         (0x1F00U)
#define NETC_F1_EMDIO_STAT_WHT_LIST_SHIFT        (8U)
#define NETC_F1_EMDIO_STAT_WHT_LIST_WIDTH        (5U)
#define NETC_F1_EMDIO_STAT_WHT_LIST(x)           (((uint32_t)(((uint32_t)(x)) << NETC_F1_EMDIO_STAT_WHT_LIST_SHIFT)) & NETC_F1_EMDIO_STAT_WHT_LIST_MASK)

#define NETC_F1_EMDIO_STAT_WHT_LIST_ENA_MASK     (0x8000U)
#define NETC_F1_EMDIO_STAT_WHT_LIST_ENA_SHIFT    (15U)
#define NETC_F1_EMDIO_STAT_WHT_LIST_ENA_WIDTH    (1U)
#define NETC_F1_EMDIO_STAT_WHT_LIST_ENA(x)       (((uint32_t)(((uint32_t)(x)) << NETC_F1_EMDIO_STAT_WHT_LIST_ENA_SHIFT)) & NETC_F1_EMDIO_STAT_WHT_LIST_ENA_MASK)

#define NETC_F1_EMDIO_STAT_PORT_ID_MASK          (0x70000U)
#define NETC_F1_EMDIO_STAT_PORT_ID_SHIFT         (16U)
#define NETC_F1_EMDIO_STAT_PORT_ID_WIDTH         (3U)
#define NETC_F1_EMDIO_STAT_PORT_ID(x)            (((uint32_t)(((uint32_t)(x)) << NETC_F1_EMDIO_STAT_PORT_ID_SHIFT)) & NETC_F1_EMDIO_STAT_PORT_ID_MASK)

#define NETC_F1_EMDIO_STAT_REQ_TYPE_MASK         (0x80000U)
#define NETC_F1_EMDIO_STAT_REQ_TYPE_SHIFT        (19U)
#define NETC_F1_EMDIO_STAT_REQ_TYPE_WIDTH        (1U)
#define NETC_F1_EMDIO_STAT_REQ_TYPE(x)           (((uint32_t)(((uint32_t)(x)) << NETC_F1_EMDIO_STAT_REQ_TYPE_SHIFT)) & NETC_F1_EMDIO_STAT_REQ_TYPE_MASK)
/*! @} */

/*! @name PHY_STATUS_CFG - PHY status configuration register */
/*! @{ */

#define NETC_F1_PHY_STATUS_CFG_BSY_MASK          (0x1U)
#define NETC_F1_PHY_STATUS_CFG_BSY_SHIFT         (0U)
#define NETC_F1_PHY_STATUS_CFG_BSY_WIDTH         (1U)
#define NETC_F1_PHY_STATUS_CFG_BSY(x)            (((uint32_t)(((uint32_t)(x)) << NETC_F1_PHY_STATUS_CFG_BSY_SHIFT)) & NETC_F1_PHY_STATUS_CFG_BSY_MASK)

#define NETC_F1_PHY_STATUS_CFG_MDIO_RD_ER_MASK   (0x2U)
#define NETC_F1_PHY_STATUS_CFG_MDIO_RD_ER_SHIFT  (1U)
#define NETC_F1_PHY_STATUS_CFG_MDIO_RD_ER_WIDTH  (1U)
#define NETC_F1_PHY_STATUS_CFG_MDIO_RD_ER(x)     (((uint32_t)(((uint32_t)(x)) << NETC_F1_PHY_STATUS_CFG_MDIO_RD_ER_SHIFT)) & NETC_F1_PHY_STATUS_CFG_MDIO_RD_ER_MASK)

#define NETC_F1_PHY_STATUS_CFG_STATUS_INTERVAL_MASK (0xFFFF0000U)
#define NETC_F1_PHY_STATUS_CFG_STATUS_INTERVAL_SHIFT (16U)
#define NETC_F1_PHY_STATUS_CFG_STATUS_INTERVAL_WIDTH (16U)
#define NETC_F1_PHY_STATUS_CFG_STATUS_INTERVAL(x) (((uint32_t)(((uint32_t)(x)) << NETC_F1_PHY_STATUS_CFG_STATUS_INTERVAL_SHIFT)) & NETC_F1_PHY_STATUS_CFG_STATUS_INTERVAL_MASK)
/*! @} */

/*! @name PHY_STATUS_CTL - PHY status control register */
/*! @{ */

#define NETC_F1_PHY_STATUS_CTL_DEV_ADDR_MASK     (0x1FU)
#define NETC_F1_PHY_STATUS_CTL_DEV_ADDR_SHIFT    (0U)
#define NETC_F1_PHY_STATUS_CTL_DEV_ADDR_WIDTH    (5U)
#define NETC_F1_PHY_STATUS_CTL_DEV_ADDR(x)       (((uint32_t)(((uint32_t)(x)) << NETC_F1_PHY_STATUS_CTL_DEV_ADDR_SHIFT)) & NETC_F1_PHY_STATUS_CTL_DEV_ADDR_MASK)

#define NETC_F1_PHY_STATUS_CTL_PORT_ADDR_MASK    (0x3E0U)
#define NETC_F1_PHY_STATUS_CTL_PORT_ADDR_SHIFT   (5U)
#define NETC_F1_PHY_STATUS_CTL_PORT_ADDR_WIDTH   (5U)
#define NETC_F1_PHY_STATUS_CTL_PORT_ADDR(x)      (((uint32_t)(((uint32_t)(x)) << NETC_F1_PHY_STATUS_CTL_PORT_ADDR_SHIFT)) & NETC_F1_PHY_STATUS_CTL_PORT_ADDR_MASK)
/*! @} */

/*! @name PHY_STATUS_DATA - PHY status data register */
/*! @{ */

#define NETC_F1_PHY_STATUS_DATA_MDIO_DATA_MASK   (0xFFFFU)
#define NETC_F1_PHY_STATUS_DATA_MDIO_DATA_SHIFT  (0U)
#define NETC_F1_PHY_STATUS_DATA_MDIO_DATA_WIDTH  (16U)
#define NETC_F1_PHY_STATUS_DATA_MDIO_DATA(x)     (((uint32_t)(((uint32_t)(x)) << NETC_F1_PHY_STATUS_DATA_MDIO_DATA_SHIFT)) & NETC_F1_PHY_STATUS_DATA_MDIO_DATA_MASK)

#define NETC_F1_PHY_STATUS_DATA_CURR_CNT_MASK    (0xFFFF0000U)
#define NETC_F1_PHY_STATUS_DATA_CURR_CNT_SHIFT   (16U)
#define NETC_F1_PHY_STATUS_DATA_CURR_CNT_WIDTH   (16U)
#define NETC_F1_PHY_STATUS_DATA_CURR_CNT(x)      (((uint32_t)(((uint32_t)(x)) << NETC_F1_PHY_STATUS_DATA_CURR_CNT_SHIFT)) & NETC_F1_PHY_STATUS_DATA_CURR_CNT_MASK)
/*! @} */

/*! @name PHY_STATUS_ADDR - PHY status register address register */
/*! @{ */

#define NETC_F1_PHY_STATUS_ADDR_REGADDR_MASK     (0xFFFFU)
#define NETC_F1_PHY_STATUS_ADDR_REGADDR_SHIFT    (0U)
#define NETC_F1_PHY_STATUS_ADDR_REGADDR_WIDTH    (16U)
#define NETC_F1_PHY_STATUS_ADDR_REGADDR(x)       (((uint32_t)(((uint32_t)(x)) << NETC_F1_PHY_STATUS_ADDR_REGADDR_SHIFT)) & NETC_F1_PHY_STATUS_ADDR_REGADDR_MASK)
/*! @} */

/*! @name PHY_STATUS_EVENT - PHY status event register */
/*! @{ */

#define NETC_F1_PHY_STATUS_EVENT_STATUS_EVENT_HL_MASK (0xFFFFU)
#define NETC_F1_PHY_STATUS_EVENT_STATUS_EVENT_HL_SHIFT (0U)
#define NETC_F1_PHY_STATUS_EVENT_STATUS_EVENT_HL_WIDTH (16U)
#define NETC_F1_PHY_STATUS_EVENT_STATUS_EVENT_HL(x) (((uint32_t)(((uint32_t)(x)) << NETC_F1_PHY_STATUS_EVENT_STATUS_EVENT_HL_SHIFT)) & NETC_F1_PHY_STATUS_EVENT_STATUS_EVENT_HL_MASK)

#define NETC_F1_PHY_STATUS_EVENT_STATUS_EVENT_LH_MASK (0xFFFF0000U)
#define NETC_F1_PHY_STATUS_EVENT_STATUS_EVENT_LH_SHIFT (16U)
#define NETC_F1_PHY_STATUS_EVENT_STATUS_EVENT_LH_WIDTH (16U)
#define NETC_F1_PHY_STATUS_EVENT_STATUS_EVENT_LH(x) (((uint32_t)(((uint32_t)(x)) << NETC_F1_PHY_STATUS_EVENT_STATUS_EVENT_LH_SHIFT)) & NETC_F1_PHY_STATUS_EVENT_STATUS_EVENT_LH_MASK)
/*! @} */

/*! @name PHY_STATUS_MASK - PHY status mask register */
/*! @{ */

#define NETC_F1_PHY_STATUS_MASK_STATUS_MASK_HL_MASK (0xFFFFU)
#define NETC_F1_PHY_STATUS_MASK_STATUS_MASK_HL_SHIFT (0U)
#define NETC_F1_PHY_STATUS_MASK_STATUS_MASK_HL_WIDTH (16U)
#define NETC_F1_PHY_STATUS_MASK_STATUS_MASK_HL(x) (((uint32_t)(((uint32_t)(x)) << NETC_F1_PHY_STATUS_MASK_STATUS_MASK_HL_SHIFT)) & NETC_F1_PHY_STATUS_MASK_STATUS_MASK_HL_MASK)

#define NETC_F1_PHY_STATUS_MASK_STATUS_MASK_LH_MASK (0xFFFF0000U)
#define NETC_F1_PHY_STATUS_MASK_STATUS_MASK_LH_SHIFT (16U)
#define NETC_F1_PHY_STATUS_MASK_STATUS_MASK_LH_WIDTH (16U)
#define NETC_F1_PHY_STATUS_MASK_STATUS_MASK_LH(x) (((uint32_t)(((uint32_t)(x)) << NETC_F1_PHY_STATUS_MASK_STATUS_MASK_LH_SHIFT)) & NETC_F1_PHY_STATUS_MASK_STATUS_MASK_LH_MASK)
/*! @} */

/*! @name MDIO_CFG - MDIO configuration register */
/*! @{ */

#define NETC_F1_MDIO_CFG_MDIO_MODE_MASK          (0x10U)
#define NETC_F1_MDIO_CFG_MDIO_MODE_SHIFT         (4U)
#define NETC_F1_MDIO_CFG_MDIO_MODE_WIDTH         (1U)
#define NETC_F1_MDIO_CFG_MDIO_MODE(x)            (((uint32_t)(((uint32_t)(x)) << NETC_F1_MDIO_CFG_MDIO_MODE_SHIFT)) & NETC_F1_MDIO_CFG_MDIO_MODE_MASK)

#define NETC_F1_MDIO_CFG_MDC_MODE_MASK           (0x20U)
#define NETC_F1_MDIO_CFG_MDC_MODE_SHIFT          (5U)
#define NETC_F1_MDIO_CFG_MDC_MODE_WIDTH          (1U)
#define NETC_F1_MDIO_CFG_MDC_MODE(x)             (((uint32_t)(((uint32_t)(x)) << NETC_F1_MDIO_CFG_MDC_MODE_SHIFT)) & NETC_F1_MDIO_CFG_MDC_MODE_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group NETC_F1_Register_Masks */

/*!
 * @}
 */ /* end of group NETC_F1_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_NETC_F1_H_) */
