/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K566_ieprc_pci.h
 * @version 2.2
 * @date 2025-10-16
 * @brief Peripheral Access Layer for S32K566_ieprc_pci
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
#if !defined(S32K566_ieprc_pci_H_)  /* Check if memory map has not been already included */
#define S32K566_ieprc_pci_H_

#include "S32K566_COMMON.h"

/* ----------------------------------------------------------------------------
   -- ieprc_pci Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ieprc_pci_Peripheral_Access_Layer ieprc_pci Peripheral Access Layer
 * @{
 */

/** ieprc_pci - Register Layout Typedef */
typedef struct ieprc_pci_Struct {
  __I  uint32_t PCI_CFH_DID_VID;                   /**< PCI device ID and vendor ID register, offset: 0x0 */
  __IO uint16_t PCI_CFH_CMD;                       /**< PCI command register, offset: 0x4 */
  __I  uint16_t PCI_CFH_STAT;                      /**< PCI status register, offset: 0x6 */
  __I  uint32_t PCI_CFH_REVID_CLASSCODE;           /**< PCI revision ID and classcode register, offset: 0x8 */
  __IO uint8_t PCI_CFH_CL_SIZE;                    /**< PCI cache line size register, offset: 0xC */
  uint8_t RESERVED_0[1];
  __I  uint8_t PCI_CFH_HDR_TYPE;                   /**< PCI header type register, offset: 0xE */
  uint8_t RESERVED_1[29];
  __I  uint16_t PCI_CFH_SUBSYS_VID;                /**< PCI subsystem vendor ID register, offset: 0x2C */
  __I  uint16_t PCI_CFH_SUBSYS_ID;                 /**< PCI subsystem ID register, offset: 0x2E */
  uint8_t RESERVED_2[4];
  __I  uint8_t PCI_CFH_CAP_PTR;                    /**< PCI capabilities pointer register, offset: 0x34 */
  uint8_t RESERVED_3[7];
  __IO uint8_t PCI_CFH_INT_LINE;                   /**< PCI interrupt line register, offset: 0x3C */
  __I  uint8_t PCI_CFH_INT_PIN;                    /**< PCI interrupt pin register, offset: 0x3D */
  uint8_t RESERVED_4[2];
  __I  uint16_t PCI_CFC_PCIE_CAP_LIST;             /**< PCI PCIe capabilities list register, offset: 0x40 */
  __I  uint16_t PCI_CFC_PCIE_CAP;                  /**< PCI PCIe capabilities register, offset: 0x42 */
  __I  uint32_t PCI_CFC_PCIE_DEV_CAP;              /**< PCI PCIe device capabilities register, offset: 0x44 */
  uint8_t RESERVED_5[2];
  __I  uint16_t PCI_CFC_PCIE_DEV_STAT;             /**< PCI PCIe device status register, offset: 0x4A */
  uint8_t RESERVED_6[16];
  __IO uint16_t PCI_CFC_PCIE_ROOT_CTL;             /**< PCI PCIe root control register, offset: 0x5C */
  uint8_t RESERVED_7[2];
  __IO uint32_t PCI_CFC_PCIE_ROOT_STAT;            /**< PCI PCIe root status register, offset: 0x60 */
  uint8_t RESERVED_8[28];
  __I  uint16_t PCI_CFC_PCIPM_CAP_LIST;            /**< PCI PCI-PM capabilities list register, offset: 0x80 */
  __I  uint16_t PCI_CFC_PCIPM_CAP;                 /**< PCI PCI-PM capabilities register, offset: 0x82 */
  __IO uint16_t PCI_CFC_PCIPM_CTL_STAT;            /**< PCI PCI-PM control and status register, offset: 0x84 */
  uint8_t RESERVED_9[1];
  __I  uint8_t PCI_CFC_PCIPM_DATA;                 /**< PCI PCI-PM capabilities data register, offset: 0x87 */
  uint8_t RESERVED_10[120];
  __I  uint32_t PCIE_CFC_AER_EXT_CAP_HDR;          /**< PCIe AER extended capability header, offset: 0x100 */
  uint8_t RESERVED_11[40];
  __IO uint32_t PCIE_CFC_AER_ROOT_ERR_CMD;         /**< PCIe AER root error command register, offset: 0x12C */
  __IO uint32_t PCIE_CFC_AER_ROOT_ERR_STAT;        /**< PCIe AER root error status register, offset: 0x130 */
  __I  uint32_t PCIE_CFC_AER_ERR_SRC_ID;           /**< PCIe AER error source identification register, offset: 0x134 */
  __I  uint32_t PCIE_CFC_RCEC_EPA_EXT_CAP_HDR;     /**< PCIe RCEC Endpoint association extended capability header, offset: 0x138 */
  __I  uint32_t PCIE_CFC_RCEC_EPA_BITMAP;          /**< PCIe RCEC Endpoint association bitmap register, offset: 0x13C */
} ieprc_pci_Type, *ieprc_pci_MemMapPtr;

/** Number of instances of the ieprc_pci module. */
#define ieprc_pci_INSTANCE_COUNT                 (2u)

/* ieprc_pci - Peripheral instance base addresses */
/** Peripheral IEPRC_1__IEPRC_B0_EC_F0_PCI_HDR_TYPE0 base address */
#define IP_IEPRC_1__IEPRC_B0_EC_F0_PCI_HDR_TYPE0_BASE (0x6D408000u)
/** Peripheral IEPRC_1__IEPRC_B0_EC_F0_PCI_HDR_TYPE0 base pointer */
#define IP_IEPRC_1__IEPRC_B0_EC_F0_PCI_HDR_TYPE0 ((ieprc_pci_Type *)IP_IEPRC_1__IEPRC_B0_EC_F0_PCI_HDR_TYPE0_BASE)
/** Peripheral IEPRC_1__IEPRC_B1_EC_F0_PCI_HDR_TYPE0 base address */
#define IP_IEPRC_1__IEPRC_B1_EC_F0_PCI_HDR_TYPE0_BASE (0x6D508000u)
/** Peripheral IEPRC_1__IEPRC_B1_EC_F0_PCI_HDR_TYPE0 base pointer */
#define IP_IEPRC_1__IEPRC_B1_EC_F0_PCI_HDR_TYPE0 ((ieprc_pci_Type *)IP_IEPRC_1__IEPRC_B1_EC_F0_PCI_HDR_TYPE0_BASE)
/** Array initializer of ieprc_pci peripheral base addresses */
#define IP_ieprc_pci_BASE_ADDRS                  { IP_IEPRC_1__IEPRC_B0_EC_F0_PCI_HDR_TYPE0_BASE, IP_IEPRC_1__IEPRC_B1_EC_F0_PCI_HDR_TYPE0_BASE }
/** Array initializer of ieprc_pci peripheral base pointers */
#define IP_ieprc_pci_BASE_PTRS                   { IP_IEPRC_1__IEPRC_B0_EC_F0_PCI_HDR_TYPE0, IP_IEPRC_1__IEPRC_B1_EC_F0_PCI_HDR_TYPE0 }

/* ----------------------------------------------------------------------------
   -- ieprc_pci Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ieprc_pci_Register_Masks ieprc_pci Register Masks
 * @{
 */

/*! @name PCI_CFH_DID_VID - PCI device ID and vendor ID register */
/*! @{ */

#define ieprc_pci_PCI_CFH_DID_VID_VENDOR_ID_MASK (0xFFFFU)
#define ieprc_pci_PCI_CFH_DID_VID_VENDOR_ID_SHIFT (0U)
#define ieprc_pci_PCI_CFH_DID_VID_VENDOR_ID_WIDTH (16U)
#define ieprc_pci_PCI_CFH_DID_VID_VENDOR_ID(x)   (((uint32_t)(((uint32_t)(x)) << ieprc_pci_PCI_CFH_DID_VID_VENDOR_ID_SHIFT)) & ieprc_pci_PCI_CFH_DID_VID_VENDOR_ID_MASK)

#define ieprc_pci_PCI_CFH_DID_VID_DEVICE_ID_MASK (0xFFFF0000U)
#define ieprc_pci_PCI_CFH_DID_VID_DEVICE_ID_SHIFT (16U)
#define ieprc_pci_PCI_CFH_DID_VID_DEVICE_ID_WIDTH (16U)
#define ieprc_pci_PCI_CFH_DID_VID_DEVICE_ID(x)   (((uint32_t)(((uint32_t)(x)) << ieprc_pci_PCI_CFH_DID_VID_DEVICE_ID_SHIFT)) & ieprc_pci_PCI_CFH_DID_VID_DEVICE_ID_MASK)
/*! @} */

/*! @name PCI_CFH_CMD - PCI command register */
/*! @{ */

#define ieprc_pci_PCI_CFH_CMD_INTR_DISABLE_MASK  (0x400U)
#define ieprc_pci_PCI_CFH_CMD_INTR_DISABLE_SHIFT (10U)
#define ieprc_pci_PCI_CFH_CMD_INTR_DISABLE_WIDTH (1U)
#define ieprc_pci_PCI_CFH_CMD_INTR_DISABLE(x)    (((uint16_t)(((uint16_t)(x)) << ieprc_pci_PCI_CFH_CMD_INTR_DISABLE_SHIFT)) & ieprc_pci_PCI_CFH_CMD_INTR_DISABLE_MASK)
/*! @} */

/*! @name PCI_CFH_STAT - PCI status register */
/*! @{ */

#define ieprc_pci_PCI_CFH_STAT_INTR_STATUS_MASK  (0x8U)
#define ieprc_pci_PCI_CFH_STAT_INTR_STATUS_SHIFT (3U)
#define ieprc_pci_PCI_CFH_STAT_INTR_STATUS_WIDTH (1U)
#define ieprc_pci_PCI_CFH_STAT_INTR_STATUS(x)    (((uint16_t)(((uint16_t)(x)) << ieprc_pci_PCI_CFH_STAT_INTR_STATUS_SHIFT)) & ieprc_pci_PCI_CFH_STAT_INTR_STATUS_MASK)

#define ieprc_pci_PCI_CFH_STAT_CAP_LIST_MASK     (0x10U)
#define ieprc_pci_PCI_CFH_STAT_CAP_LIST_SHIFT    (4U)
#define ieprc_pci_PCI_CFH_STAT_CAP_LIST_WIDTH    (1U)
#define ieprc_pci_PCI_CFH_STAT_CAP_LIST(x)       (((uint16_t)(((uint16_t)(x)) << ieprc_pci_PCI_CFH_STAT_CAP_LIST_SHIFT)) & ieprc_pci_PCI_CFH_STAT_CAP_LIST_MASK)
/*! @} */

/*! @name PCI_CFH_REVID_CLASSCODE - PCI revision ID and classcode register */
/*! @{ */

#define ieprc_pci_PCI_CFH_REVID_CLASSCODE_REV_ID_MASK (0xFFU)
#define ieprc_pci_PCI_CFH_REVID_CLASSCODE_REV_ID_SHIFT (0U)
#define ieprc_pci_PCI_CFH_REVID_CLASSCODE_REV_ID_WIDTH (8U)
#define ieprc_pci_PCI_CFH_REVID_CLASSCODE_REV_ID(x) (((uint32_t)(((uint32_t)(x)) << ieprc_pci_PCI_CFH_REVID_CLASSCODE_REV_ID_SHIFT)) & ieprc_pci_PCI_CFH_REVID_CLASSCODE_REV_ID_MASK)

#define ieprc_pci_PCI_CFH_REVID_CLASSCODE_CLASS_CODE_MASK (0xFFFFFF00U)
#define ieprc_pci_PCI_CFH_REVID_CLASSCODE_CLASS_CODE_SHIFT (8U)
#define ieprc_pci_PCI_CFH_REVID_CLASSCODE_CLASS_CODE_WIDTH (24U)
#define ieprc_pci_PCI_CFH_REVID_CLASSCODE_CLASS_CODE(x) (((uint32_t)(((uint32_t)(x)) << ieprc_pci_PCI_CFH_REVID_CLASSCODE_CLASS_CODE_SHIFT)) & ieprc_pci_PCI_CFH_REVID_CLASSCODE_CLASS_CODE_MASK)
/*! @} */

/*! @name PCI_CFH_CL_SIZE - PCI cache line size register */
/*! @{ */

#define ieprc_pci_PCI_CFH_CL_SIZE_CACHE_LINE_SIZE_MASK (0xFFU)
#define ieprc_pci_PCI_CFH_CL_SIZE_CACHE_LINE_SIZE_SHIFT (0U)
#define ieprc_pci_PCI_CFH_CL_SIZE_CACHE_LINE_SIZE_WIDTH (8U)
#define ieprc_pci_PCI_CFH_CL_SIZE_CACHE_LINE_SIZE(x) (((uint8_t)(((uint8_t)(x)) << ieprc_pci_PCI_CFH_CL_SIZE_CACHE_LINE_SIZE_SHIFT)) & ieprc_pci_PCI_CFH_CL_SIZE_CACHE_LINE_SIZE_MASK)
/*! @} */

/*! @name PCI_CFH_HDR_TYPE - PCI header type register */
/*! @{ */

#define ieprc_pci_PCI_CFH_HDR_TYPE_HDR_TYPE_MASK (0x7FU)
#define ieprc_pci_PCI_CFH_HDR_TYPE_HDR_TYPE_SHIFT (0U)
#define ieprc_pci_PCI_CFH_HDR_TYPE_HDR_TYPE_WIDTH (7U)
#define ieprc_pci_PCI_CFH_HDR_TYPE_HDR_TYPE(x)   (((uint8_t)(((uint8_t)(x)) << ieprc_pci_PCI_CFH_HDR_TYPE_HDR_TYPE_SHIFT)) & ieprc_pci_PCI_CFH_HDR_TYPE_HDR_TYPE_MASK)

#define ieprc_pci_PCI_CFH_HDR_TYPE_MULT_FUNC_DEV_MASK (0x80U)
#define ieprc_pci_PCI_CFH_HDR_TYPE_MULT_FUNC_DEV_SHIFT (7U)
#define ieprc_pci_PCI_CFH_HDR_TYPE_MULT_FUNC_DEV_WIDTH (1U)
#define ieprc_pci_PCI_CFH_HDR_TYPE_MULT_FUNC_DEV(x) (((uint8_t)(((uint8_t)(x)) << ieprc_pci_PCI_CFH_HDR_TYPE_MULT_FUNC_DEV_SHIFT)) & ieprc_pci_PCI_CFH_HDR_TYPE_MULT_FUNC_DEV_MASK)
/*! @} */

/*! @name PCI_CFH_SUBSYS_VID - PCI subsystem vendor ID register */
/*! @{ */

#define ieprc_pci_PCI_CFH_SUBSYS_VID_SUBSYSTEM_VENDOR_ID_MASK (0xFFFFU)
#define ieprc_pci_PCI_CFH_SUBSYS_VID_SUBSYSTEM_VENDOR_ID_SHIFT (0U)
#define ieprc_pci_PCI_CFH_SUBSYS_VID_SUBSYSTEM_VENDOR_ID_WIDTH (16U)
#define ieprc_pci_PCI_CFH_SUBSYS_VID_SUBSYSTEM_VENDOR_ID(x) (((uint16_t)(((uint16_t)(x)) << ieprc_pci_PCI_CFH_SUBSYS_VID_SUBSYSTEM_VENDOR_ID_SHIFT)) & ieprc_pci_PCI_CFH_SUBSYS_VID_SUBSYSTEM_VENDOR_ID_MASK)
/*! @} */

/*! @name PCI_CFH_SUBSYS_ID - PCI subsystem ID register */
/*! @{ */

#define ieprc_pci_PCI_CFH_SUBSYS_ID_SUBSYSTEM_ID_MASK (0xFFFFU)
#define ieprc_pci_PCI_CFH_SUBSYS_ID_SUBSYSTEM_ID_SHIFT (0U)
#define ieprc_pci_PCI_CFH_SUBSYS_ID_SUBSYSTEM_ID_WIDTH (16U)
#define ieprc_pci_PCI_CFH_SUBSYS_ID_SUBSYSTEM_ID(x) (((uint16_t)(((uint16_t)(x)) << ieprc_pci_PCI_CFH_SUBSYS_ID_SUBSYSTEM_ID_SHIFT)) & ieprc_pci_PCI_CFH_SUBSYS_ID_SUBSYSTEM_ID_MASK)
/*! @} */

/*! @name PCI_CFH_CAP_PTR - PCI capabilities pointer register */
/*! @{ */

#define ieprc_pci_PCI_CFH_CAP_PTR_CAP_PTR_MASK   (0xFFU)
#define ieprc_pci_PCI_CFH_CAP_PTR_CAP_PTR_SHIFT  (0U)
#define ieprc_pci_PCI_CFH_CAP_PTR_CAP_PTR_WIDTH  (8U)
#define ieprc_pci_PCI_CFH_CAP_PTR_CAP_PTR(x)     (((uint8_t)(((uint8_t)(x)) << ieprc_pci_PCI_CFH_CAP_PTR_CAP_PTR_SHIFT)) & ieprc_pci_PCI_CFH_CAP_PTR_CAP_PTR_MASK)
/*! @} */

/*! @name PCI_CFH_INT_LINE - PCI interrupt line register */
/*! @{ */

#define ieprc_pci_PCI_CFH_INT_LINE_INT_LINE_MASK (0xFFU)
#define ieprc_pci_PCI_CFH_INT_LINE_INT_LINE_SHIFT (0U)
#define ieprc_pci_PCI_CFH_INT_LINE_INT_LINE_WIDTH (8U)
#define ieprc_pci_PCI_CFH_INT_LINE_INT_LINE(x)   (((uint8_t)(((uint8_t)(x)) << ieprc_pci_PCI_CFH_INT_LINE_INT_LINE_SHIFT)) & ieprc_pci_PCI_CFH_INT_LINE_INT_LINE_MASK)
/*! @} */

/*! @name PCI_CFH_INT_PIN - PCI interrupt pin register */
/*! @{ */

#define ieprc_pci_PCI_CFH_INT_PIN_INT_PIN_MASK   (0xFFU)
#define ieprc_pci_PCI_CFH_INT_PIN_INT_PIN_SHIFT  (0U)
#define ieprc_pci_PCI_CFH_INT_PIN_INT_PIN_WIDTH  (8U)
#define ieprc_pci_PCI_CFH_INT_PIN_INT_PIN(x)     (((uint8_t)(((uint8_t)(x)) << ieprc_pci_PCI_CFH_INT_PIN_INT_PIN_SHIFT)) & ieprc_pci_PCI_CFH_INT_PIN_INT_PIN_MASK)
/*! @} */

/*! @name PCI_CFC_PCIE_CAP_LIST - PCI PCIe capabilities list register */
/*! @{ */

#define ieprc_pci_PCI_CFC_PCIE_CAP_LIST_CAP_ID_MASK (0xFFU)
#define ieprc_pci_PCI_CFC_PCIE_CAP_LIST_CAP_ID_SHIFT (0U)
#define ieprc_pci_PCI_CFC_PCIE_CAP_LIST_CAP_ID_WIDTH (8U)
#define ieprc_pci_PCI_CFC_PCIE_CAP_LIST_CAP_ID(x) (((uint16_t)(((uint16_t)(x)) << ieprc_pci_PCI_CFC_PCIE_CAP_LIST_CAP_ID_SHIFT)) & ieprc_pci_PCI_CFC_PCIE_CAP_LIST_CAP_ID_MASK)

#define ieprc_pci_PCI_CFC_PCIE_CAP_LIST_NEXT_CAP_PTR_MASK (0xFF00U)
#define ieprc_pci_PCI_CFC_PCIE_CAP_LIST_NEXT_CAP_PTR_SHIFT (8U)
#define ieprc_pci_PCI_CFC_PCIE_CAP_LIST_NEXT_CAP_PTR_WIDTH (8U)
#define ieprc_pci_PCI_CFC_PCIE_CAP_LIST_NEXT_CAP_PTR(x) (((uint16_t)(((uint16_t)(x)) << ieprc_pci_PCI_CFC_PCIE_CAP_LIST_NEXT_CAP_PTR_SHIFT)) & ieprc_pci_PCI_CFC_PCIE_CAP_LIST_NEXT_CAP_PTR_MASK)
/*! @} */

/*! @name PCI_CFC_PCIE_CAP - PCI PCIe capabilities register */
/*! @{ */

#define ieprc_pci_PCI_CFC_PCIE_CAP_CAP_VER_MASK  (0xFU)
#define ieprc_pci_PCI_CFC_PCIE_CAP_CAP_VER_SHIFT (0U)
#define ieprc_pci_PCI_CFC_PCIE_CAP_CAP_VER_WIDTH (4U)
#define ieprc_pci_PCI_CFC_PCIE_CAP_CAP_VER(x)    (((uint16_t)(((uint16_t)(x)) << ieprc_pci_PCI_CFC_PCIE_CAP_CAP_VER_SHIFT)) & ieprc_pci_PCI_CFC_PCIE_CAP_CAP_VER_MASK)

#define ieprc_pci_PCI_CFC_PCIE_CAP_DEV_PORT_TYPE_MASK (0xF0U)
#define ieprc_pci_PCI_CFC_PCIE_CAP_DEV_PORT_TYPE_SHIFT (4U)
#define ieprc_pci_PCI_CFC_PCIE_CAP_DEV_PORT_TYPE_WIDTH (4U)
#define ieprc_pci_PCI_CFC_PCIE_CAP_DEV_PORT_TYPE(x) (((uint16_t)(((uint16_t)(x)) << ieprc_pci_PCI_CFC_PCIE_CAP_DEV_PORT_TYPE_SHIFT)) & ieprc_pci_PCI_CFC_PCIE_CAP_DEV_PORT_TYPE_MASK)

#define ieprc_pci_PCI_CFC_PCIE_CAP_INT_MSG_NUM_MASK (0x3E00U)
#define ieprc_pci_PCI_CFC_PCIE_CAP_INT_MSG_NUM_SHIFT (9U)
#define ieprc_pci_PCI_CFC_PCIE_CAP_INT_MSG_NUM_WIDTH (5U)
#define ieprc_pci_PCI_CFC_PCIE_CAP_INT_MSG_NUM(x) (((uint16_t)(((uint16_t)(x)) << ieprc_pci_PCI_CFC_PCIE_CAP_INT_MSG_NUM_SHIFT)) & ieprc_pci_PCI_CFC_PCIE_CAP_INT_MSG_NUM_MASK)
/*! @} */

/*! @name PCI_CFC_PCIE_DEV_CAP - PCI PCIe device capabilities register */
/*! @{ */

#define ieprc_pci_PCI_CFC_PCIE_DEV_CAP_FLR_CAP_MASK (0x10000000U)
#define ieprc_pci_PCI_CFC_PCIE_DEV_CAP_FLR_CAP_SHIFT (28U)
#define ieprc_pci_PCI_CFC_PCIE_DEV_CAP_FLR_CAP_WIDTH (1U)
#define ieprc_pci_PCI_CFC_PCIE_DEV_CAP_FLR_CAP(x) (((uint32_t)(((uint32_t)(x)) << ieprc_pci_PCI_CFC_PCIE_DEV_CAP_FLR_CAP_SHIFT)) & ieprc_pci_PCI_CFC_PCIE_DEV_CAP_FLR_CAP_MASK)
/*! @} */

/*! @name PCI_CFC_PCIE_DEV_STAT - PCI PCIe device status register */
/*! @{ */

#define ieprc_pci_PCI_CFC_PCIE_DEV_STAT_TRANS_PEND_MASK (0x20U)
#define ieprc_pci_PCI_CFC_PCIE_DEV_STAT_TRANS_PEND_SHIFT (5U)
#define ieprc_pci_PCI_CFC_PCIE_DEV_STAT_TRANS_PEND_WIDTH (1U)
#define ieprc_pci_PCI_CFC_PCIE_DEV_STAT_TRANS_PEND(x) (((uint16_t)(((uint16_t)(x)) << ieprc_pci_PCI_CFC_PCIE_DEV_STAT_TRANS_PEND_SHIFT)) & ieprc_pci_PCI_CFC_PCIE_DEV_STAT_TRANS_PEND_MASK)
/*! @} */

/*! @name PCI_CFC_PCIE_ROOT_CTL - PCI PCIe root control register */
/*! @{ */

#define ieprc_pci_PCI_CFC_PCIE_ROOT_CTL_PME_INT_EN_MASK (0x8U)
#define ieprc_pci_PCI_CFC_PCIE_ROOT_CTL_PME_INT_EN_SHIFT (3U)
#define ieprc_pci_PCI_CFC_PCIE_ROOT_CTL_PME_INT_EN_WIDTH (1U)
#define ieprc_pci_PCI_CFC_PCIE_ROOT_CTL_PME_INT_EN(x) (((uint16_t)(((uint16_t)(x)) << ieprc_pci_PCI_CFC_PCIE_ROOT_CTL_PME_INT_EN_SHIFT)) & ieprc_pci_PCI_CFC_PCIE_ROOT_CTL_PME_INT_EN_MASK)
/*! @} */

/*! @name PCI_CFC_PCIE_ROOT_STAT - PCI PCIe root status register */
/*! @{ */

#define ieprc_pci_PCI_CFC_PCIE_ROOT_STAT_PME_REQ_ID_MASK (0xFFFFU)
#define ieprc_pci_PCI_CFC_PCIE_ROOT_STAT_PME_REQ_ID_SHIFT (0U)
#define ieprc_pci_PCI_CFC_PCIE_ROOT_STAT_PME_REQ_ID_WIDTH (16U)
#define ieprc_pci_PCI_CFC_PCIE_ROOT_STAT_PME_REQ_ID(x) (((uint32_t)(((uint32_t)(x)) << ieprc_pci_PCI_CFC_PCIE_ROOT_STAT_PME_REQ_ID_SHIFT)) & ieprc_pci_PCI_CFC_PCIE_ROOT_STAT_PME_REQ_ID_MASK)

#define ieprc_pci_PCI_CFC_PCIE_ROOT_STAT_PME_STATUS_MASK (0x10000U)
#define ieprc_pci_PCI_CFC_PCIE_ROOT_STAT_PME_STATUS_SHIFT (16U)
#define ieprc_pci_PCI_CFC_PCIE_ROOT_STAT_PME_STATUS_WIDTH (1U)
#define ieprc_pci_PCI_CFC_PCIE_ROOT_STAT_PME_STATUS(x) (((uint32_t)(((uint32_t)(x)) << ieprc_pci_PCI_CFC_PCIE_ROOT_STAT_PME_STATUS_SHIFT)) & ieprc_pci_PCI_CFC_PCIE_ROOT_STAT_PME_STATUS_MASK)

#define ieprc_pci_PCI_CFC_PCIE_ROOT_STAT_PME_PEND_MASK (0x20000U)
#define ieprc_pci_PCI_CFC_PCIE_ROOT_STAT_PME_PEND_SHIFT (17U)
#define ieprc_pci_PCI_CFC_PCIE_ROOT_STAT_PME_PEND_WIDTH (1U)
#define ieprc_pci_PCI_CFC_PCIE_ROOT_STAT_PME_PEND(x) (((uint32_t)(((uint32_t)(x)) << ieprc_pci_PCI_CFC_PCIE_ROOT_STAT_PME_PEND_SHIFT)) & ieprc_pci_PCI_CFC_PCIE_ROOT_STAT_PME_PEND_MASK)
/*! @} */

/*! @name PCI_CFC_PCIPM_CAP_LIST - PCI PCI-PM capabilities list register */
/*! @{ */

#define ieprc_pci_PCI_CFC_PCIPM_CAP_LIST_CAP_ID_MASK (0xFFU)
#define ieprc_pci_PCI_CFC_PCIPM_CAP_LIST_CAP_ID_SHIFT (0U)
#define ieprc_pci_PCI_CFC_PCIPM_CAP_LIST_CAP_ID_WIDTH (8U)
#define ieprc_pci_PCI_CFC_PCIPM_CAP_LIST_CAP_ID(x) (((uint16_t)(((uint16_t)(x)) << ieprc_pci_PCI_CFC_PCIPM_CAP_LIST_CAP_ID_SHIFT)) & ieprc_pci_PCI_CFC_PCIPM_CAP_LIST_CAP_ID_MASK)

#define ieprc_pci_PCI_CFC_PCIPM_CAP_LIST_NEXT_CAP_PTR_MASK (0xFF00U)
#define ieprc_pci_PCI_CFC_PCIPM_CAP_LIST_NEXT_CAP_PTR_SHIFT (8U)
#define ieprc_pci_PCI_CFC_PCIPM_CAP_LIST_NEXT_CAP_PTR_WIDTH (8U)
#define ieprc_pci_PCI_CFC_PCIPM_CAP_LIST_NEXT_CAP_PTR(x) (((uint16_t)(((uint16_t)(x)) << ieprc_pci_PCI_CFC_PCIPM_CAP_LIST_NEXT_CAP_PTR_SHIFT)) & ieprc_pci_PCI_CFC_PCIPM_CAP_LIST_NEXT_CAP_PTR_MASK)
/*! @} */

/*! @name PCI_CFC_PCIPM_CAP - PCI PCI-PM capabilities register */
/*! @{ */

#define ieprc_pci_PCI_CFC_PCIPM_CAP_VERSION_MASK (0x7U)
#define ieprc_pci_PCI_CFC_PCIPM_CAP_VERSION_SHIFT (0U)
#define ieprc_pci_PCI_CFC_PCIPM_CAP_VERSION_WIDTH (3U)
#define ieprc_pci_PCI_CFC_PCIPM_CAP_VERSION(x)   (((uint16_t)(((uint16_t)(x)) << ieprc_pci_PCI_CFC_PCIPM_CAP_VERSION_SHIFT)) & ieprc_pci_PCI_CFC_PCIPM_CAP_VERSION_MASK)

#define ieprc_pci_PCI_CFC_PCIPM_CAP_PME_SUPPORT_MASK (0xF800U)
#define ieprc_pci_PCI_CFC_PCIPM_CAP_PME_SUPPORT_SHIFT (11U)
#define ieprc_pci_PCI_CFC_PCIPM_CAP_PME_SUPPORT_WIDTH (5U)
#define ieprc_pci_PCI_CFC_PCIPM_CAP_PME_SUPPORT(x) (((uint16_t)(((uint16_t)(x)) << ieprc_pci_PCI_CFC_PCIPM_CAP_PME_SUPPORT_SHIFT)) & ieprc_pci_PCI_CFC_PCIPM_CAP_PME_SUPPORT_MASK)
/*! @} */

/*! @name PCI_CFC_PCIPM_CTL_STAT - PCI PCI-PM control and status register */
/*! @{ */

#define ieprc_pci_PCI_CFC_PCIPM_CTL_STAT_PWR_STATE_MASK (0x3U)
#define ieprc_pci_PCI_CFC_PCIPM_CTL_STAT_PWR_STATE_SHIFT (0U)
#define ieprc_pci_PCI_CFC_PCIPM_CTL_STAT_PWR_STATE_WIDTH (2U)
#define ieprc_pci_PCI_CFC_PCIPM_CTL_STAT_PWR_STATE(x) (((uint16_t)(((uint16_t)(x)) << ieprc_pci_PCI_CFC_PCIPM_CTL_STAT_PWR_STATE_SHIFT)) & ieprc_pci_PCI_CFC_PCIPM_CTL_STAT_PWR_STATE_MASK)

#define ieprc_pci_PCI_CFC_PCIPM_CTL_STAT_NO_SOFT_RST_MASK (0x8U)
#define ieprc_pci_PCI_CFC_PCIPM_CTL_STAT_NO_SOFT_RST_SHIFT (3U)
#define ieprc_pci_PCI_CFC_PCIPM_CTL_STAT_NO_SOFT_RST_WIDTH (1U)
#define ieprc_pci_PCI_CFC_PCIPM_CTL_STAT_NO_SOFT_RST(x) (((uint16_t)(((uint16_t)(x)) << ieprc_pci_PCI_CFC_PCIPM_CTL_STAT_NO_SOFT_RST_SHIFT)) & ieprc_pci_PCI_CFC_PCIPM_CTL_STAT_NO_SOFT_RST_MASK)
/*! @} */

/*! @name PCI_CFC_PCIPM_DATA - PCI PCI-PM capabilities data register */
/*! @{ */

#define ieprc_pci_PCI_CFC_PCIPM_DATA_DATA_MASK   (0xFFU)
#define ieprc_pci_PCI_CFC_PCIPM_DATA_DATA_SHIFT  (0U)
#define ieprc_pci_PCI_CFC_PCIPM_DATA_DATA_WIDTH  (8U)
#define ieprc_pci_PCI_CFC_PCIPM_DATA_DATA(x)     (((uint8_t)(((uint8_t)(x)) << ieprc_pci_PCI_CFC_PCIPM_DATA_DATA_SHIFT)) & ieprc_pci_PCI_CFC_PCIPM_DATA_DATA_MASK)
/*! @} */

/*! @name PCIE_CFC_AER_EXT_CAP_HDR - PCIe AER extended capability header */
/*! @{ */

#define ieprc_pci_PCIE_CFC_AER_EXT_CAP_HDR_PCIE_EXT_CAP_ID_MASK (0xFFFFU)
#define ieprc_pci_PCIE_CFC_AER_EXT_CAP_HDR_PCIE_EXT_CAP_ID_SHIFT (0U)
#define ieprc_pci_PCIE_CFC_AER_EXT_CAP_HDR_PCIE_EXT_CAP_ID_WIDTH (16U)
#define ieprc_pci_PCIE_CFC_AER_EXT_CAP_HDR_PCIE_EXT_CAP_ID(x) (((uint32_t)(((uint32_t)(x)) << ieprc_pci_PCIE_CFC_AER_EXT_CAP_HDR_PCIE_EXT_CAP_ID_SHIFT)) & ieprc_pci_PCIE_CFC_AER_EXT_CAP_HDR_PCIE_EXT_CAP_ID_MASK)

#define ieprc_pci_PCIE_CFC_AER_EXT_CAP_HDR_CAP_VER_MASK (0xF0000U)
#define ieprc_pci_PCIE_CFC_AER_EXT_CAP_HDR_CAP_VER_SHIFT (16U)
#define ieprc_pci_PCIE_CFC_AER_EXT_CAP_HDR_CAP_VER_WIDTH (4U)
#define ieprc_pci_PCIE_CFC_AER_EXT_CAP_HDR_CAP_VER(x) (((uint32_t)(((uint32_t)(x)) << ieprc_pci_PCIE_CFC_AER_EXT_CAP_HDR_CAP_VER_SHIFT)) & ieprc_pci_PCIE_CFC_AER_EXT_CAP_HDR_CAP_VER_MASK)

#define ieprc_pci_PCIE_CFC_AER_EXT_CAP_HDR_NEXT_CAP_OFF_MASK (0xFFF00000U)
#define ieprc_pci_PCIE_CFC_AER_EXT_CAP_HDR_NEXT_CAP_OFF_SHIFT (20U)
#define ieprc_pci_PCIE_CFC_AER_EXT_CAP_HDR_NEXT_CAP_OFF_WIDTH (12U)
#define ieprc_pci_PCIE_CFC_AER_EXT_CAP_HDR_NEXT_CAP_OFF(x) (((uint32_t)(((uint32_t)(x)) << ieprc_pci_PCIE_CFC_AER_EXT_CAP_HDR_NEXT_CAP_OFF_SHIFT)) & ieprc_pci_PCIE_CFC_AER_EXT_CAP_HDR_NEXT_CAP_OFF_MASK)
/*! @} */

/*! @name PCIE_CFC_AER_ROOT_ERR_CMD - PCIe AER root error command register */
/*! @{ */

#define ieprc_pci_PCIE_CFC_AER_ROOT_ERR_CMD_CORR_ERR_RPT_EN_MASK (0x1U)
#define ieprc_pci_PCIE_CFC_AER_ROOT_ERR_CMD_CORR_ERR_RPT_EN_SHIFT (0U)
#define ieprc_pci_PCIE_CFC_AER_ROOT_ERR_CMD_CORR_ERR_RPT_EN_WIDTH (1U)
#define ieprc_pci_PCIE_CFC_AER_ROOT_ERR_CMD_CORR_ERR_RPT_EN(x) (((uint32_t)(((uint32_t)(x)) << ieprc_pci_PCIE_CFC_AER_ROOT_ERR_CMD_CORR_ERR_RPT_EN_SHIFT)) & ieprc_pci_PCIE_CFC_AER_ROOT_ERR_CMD_CORR_ERR_RPT_EN_MASK)

#define ieprc_pci_PCIE_CFC_AER_ROOT_ERR_CMD_NON_FATAL_ERR_RPT_EN_MASK (0x2U)
#define ieprc_pci_PCIE_CFC_AER_ROOT_ERR_CMD_NON_FATAL_ERR_RPT_EN_SHIFT (1U)
#define ieprc_pci_PCIE_CFC_AER_ROOT_ERR_CMD_NON_FATAL_ERR_RPT_EN_WIDTH (1U)
#define ieprc_pci_PCIE_CFC_AER_ROOT_ERR_CMD_NON_FATAL_ERR_RPT_EN(x) (((uint32_t)(((uint32_t)(x)) << ieprc_pci_PCIE_CFC_AER_ROOT_ERR_CMD_NON_FATAL_ERR_RPT_EN_SHIFT)) & ieprc_pci_PCIE_CFC_AER_ROOT_ERR_CMD_NON_FATAL_ERR_RPT_EN_MASK)

#define ieprc_pci_PCIE_CFC_AER_ROOT_ERR_CMD_FATAL_ERR_RPT_EN_MASK (0x4U)
#define ieprc_pci_PCIE_CFC_AER_ROOT_ERR_CMD_FATAL_ERR_RPT_EN_SHIFT (2U)
#define ieprc_pci_PCIE_CFC_AER_ROOT_ERR_CMD_FATAL_ERR_RPT_EN_WIDTH (1U)
#define ieprc_pci_PCIE_CFC_AER_ROOT_ERR_CMD_FATAL_ERR_RPT_EN(x) (((uint32_t)(((uint32_t)(x)) << ieprc_pci_PCIE_CFC_AER_ROOT_ERR_CMD_FATAL_ERR_RPT_EN_SHIFT)) & ieprc_pci_PCIE_CFC_AER_ROOT_ERR_CMD_FATAL_ERR_RPT_EN_MASK)
/*! @} */

/*! @name PCIE_CFC_AER_ROOT_ERR_STAT - PCIe AER root error status register */
/*! @{ */

#define ieprc_pci_PCIE_CFC_AER_ROOT_ERR_STAT_ERR_CORR_MASK (0x1U)
#define ieprc_pci_PCIE_CFC_AER_ROOT_ERR_STAT_ERR_CORR_SHIFT (0U)
#define ieprc_pci_PCIE_CFC_AER_ROOT_ERR_STAT_ERR_CORR_WIDTH (1U)
#define ieprc_pci_PCIE_CFC_AER_ROOT_ERR_STAT_ERR_CORR(x) (((uint32_t)(((uint32_t)(x)) << ieprc_pci_PCIE_CFC_AER_ROOT_ERR_STAT_ERR_CORR_SHIFT)) & ieprc_pci_PCIE_CFC_AER_ROOT_ERR_STAT_ERR_CORR_MASK)

#define ieprc_pci_PCIE_CFC_AER_ROOT_ERR_STAT_MULT_ERR_CORR_MASK (0x2U)
#define ieprc_pci_PCIE_CFC_AER_ROOT_ERR_STAT_MULT_ERR_CORR_SHIFT (1U)
#define ieprc_pci_PCIE_CFC_AER_ROOT_ERR_STAT_MULT_ERR_CORR_WIDTH (1U)
#define ieprc_pci_PCIE_CFC_AER_ROOT_ERR_STAT_MULT_ERR_CORR(x) (((uint32_t)(((uint32_t)(x)) << ieprc_pci_PCIE_CFC_AER_ROOT_ERR_STAT_MULT_ERR_CORR_SHIFT)) & ieprc_pci_PCIE_CFC_AER_ROOT_ERR_STAT_MULT_ERR_CORR_MASK)

#define ieprc_pci_PCIE_CFC_AER_ROOT_ERR_STAT_ERR_FATAL_NON_FATAL_MASK (0x4U)
#define ieprc_pci_PCIE_CFC_AER_ROOT_ERR_STAT_ERR_FATAL_NON_FATAL_SHIFT (2U)
#define ieprc_pci_PCIE_CFC_AER_ROOT_ERR_STAT_ERR_FATAL_NON_FATAL_WIDTH (1U)
#define ieprc_pci_PCIE_CFC_AER_ROOT_ERR_STAT_ERR_FATAL_NON_FATAL(x) (((uint32_t)(((uint32_t)(x)) << ieprc_pci_PCIE_CFC_AER_ROOT_ERR_STAT_ERR_FATAL_NON_FATAL_SHIFT)) & ieprc_pci_PCIE_CFC_AER_ROOT_ERR_STAT_ERR_FATAL_NON_FATAL_MASK)

#define ieprc_pci_PCIE_CFC_AER_ROOT_ERR_STAT_MULT_ERR_FATAL_NON_FATAL_MASK (0x8U)
#define ieprc_pci_PCIE_CFC_AER_ROOT_ERR_STAT_MULT_ERR_FATAL_NON_FATAL_SHIFT (3U)
#define ieprc_pci_PCIE_CFC_AER_ROOT_ERR_STAT_MULT_ERR_FATAL_NON_FATAL_WIDTH (1U)
#define ieprc_pci_PCIE_CFC_AER_ROOT_ERR_STAT_MULT_ERR_FATAL_NON_FATAL(x) (((uint32_t)(((uint32_t)(x)) << ieprc_pci_PCIE_CFC_AER_ROOT_ERR_STAT_MULT_ERR_FATAL_NON_FATAL_SHIFT)) & ieprc_pci_PCIE_CFC_AER_ROOT_ERR_STAT_MULT_ERR_FATAL_NON_FATAL_MASK)

#define ieprc_pci_PCIE_CFC_AER_ROOT_ERR_STAT_FIRST_UCORR_FATAL_MASK (0x10U)
#define ieprc_pci_PCIE_CFC_AER_ROOT_ERR_STAT_FIRST_UCORR_FATAL_SHIFT (4U)
#define ieprc_pci_PCIE_CFC_AER_ROOT_ERR_STAT_FIRST_UCORR_FATAL_WIDTH (1U)
#define ieprc_pci_PCIE_CFC_AER_ROOT_ERR_STAT_FIRST_UCORR_FATAL(x) (((uint32_t)(((uint32_t)(x)) << ieprc_pci_PCIE_CFC_AER_ROOT_ERR_STAT_FIRST_UCORR_FATAL_SHIFT)) & ieprc_pci_PCIE_CFC_AER_ROOT_ERR_STAT_FIRST_UCORR_FATAL_MASK)

#define ieprc_pci_PCIE_CFC_AER_ROOT_ERR_STAT_ERR_NON_FATAL_MASK (0x20U)
#define ieprc_pci_PCIE_CFC_AER_ROOT_ERR_STAT_ERR_NON_FATAL_SHIFT (5U)
#define ieprc_pci_PCIE_CFC_AER_ROOT_ERR_STAT_ERR_NON_FATAL_WIDTH (1U)
#define ieprc_pci_PCIE_CFC_AER_ROOT_ERR_STAT_ERR_NON_FATAL(x) (((uint32_t)(((uint32_t)(x)) << ieprc_pci_PCIE_CFC_AER_ROOT_ERR_STAT_ERR_NON_FATAL_SHIFT)) & ieprc_pci_PCIE_CFC_AER_ROOT_ERR_STAT_ERR_NON_FATAL_MASK)

#define ieprc_pci_PCIE_CFC_AER_ROOT_ERR_STAT_ERR_FATAL_MASK (0x40U)
#define ieprc_pci_PCIE_CFC_AER_ROOT_ERR_STAT_ERR_FATAL_SHIFT (6U)
#define ieprc_pci_PCIE_CFC_AER_ROOT_ERR_STAT_ERR_FATAL_WIDTH (1U)
#define ieprc_pci_PCIE_CFC_AER_ROOT_ERR_STAT_ERR_FATAL(x) (((uint32_t)(((uint32_t)(x)) << ieprc_pci_PCIE_CFC_AER_ROOT_ERR_STAT_ERR_FATAL_SHIFT)) & ieprc_pci_PCIE_CFC_AER_ROOT_ERR_STAT_ERR_FATAL_MASK)
/*! @} */

/*! @name PCIE_CFC_AER_ERR_SRC_ID - PCIe AER error source identification register */
/*! @{ */

#define ieprc_pci_PCIE_CFC_AER_ERR_SRC_ID_ERR_CORR_SRC_ID_MASK (0xFFFFU)
#define ieprc_pci_PCIE_CFC_AER_ERR_SRC_ID_ERR_CORR_SRC_ID_SHIFT (0U)
#define ieprc_pci_PCIE_CFC_AER_ERR_SRC_ID_ERR_CORR_SRC_ID_WIDTH (16U)
#define ieprc_pci_PCIE_CFC_AER_ERR_SRC_ID_ERR_CORR_SRC_ID(x) (((uint32_t)(((uint32_t)(x)) << ieprc_pci_PCIE_CFC_AER_ERR_SRC_ID_ERR_CORR_SRC_ID_SHIFT)) & ieprc_pci_PCIE_CFC_AER_ERR_SRC_ID_ERR_CORR_SRC_ID_MASK)

#define ieprc_pci_PCIE_CFC_AER_ERR_SRC_ID_ERR_FATAL_NON_FATAL_SRC_ID_MASK (0xFFFF0000U)
#define ieprc_pci_PCIE_CFC_AER_ERR_SRC_ID_ERR_FATAL_NON_FATAL_SRC_ID_SHIFT (16U)
#define ieprc_pci_PCIE_CFC_AER_ERR_SRC_ID_ERR_FATAL_NON_FATAL_SRC_ID_WIDTH (16U)
#define ieprc_pci_PCIE_CFC_AER_ERR_SRC_ID_ERR_FATAL_NON_FATAL_SRC_ID(x) (((uint32_t)(((uint32_t)(x)) << ieprc_pci_PCIE_CFC_AER_ERR_SRC_ID_ERR_FATAL_NON_FATAL_SRC_ID_SHIFT)) & ieprc_pci_PCIE_CFC_AER_ERR_SRC_ID_ERR_FATAL_NON_FATAL_SRC_ID_MASK)
/*! @} */

/*! @name PCIE_CFC_RCEC_EPA_EXT_CAP_HDR - PCIe RCEC Endpoint association extended capability header */
/*! @{ */

#define ieprc_pci_PCIE_CFC_RCEC_EPA_EXT_CAP_HDR_PCIE_EXT_CAP_ID_MASK (0xFFFFU)
#define ieprc_pci_PCIE_CFC_RCEC_EPA_EXT_CAP_HDR_PCIE_EXT_CAP_ID_SHIFT (0U)
#define ieprc_pci_PCIE_CFC_RCEC_EPA_EXT_CAP_HDR_PCIE_EXT_CAP_ID_WIDTH (16U)
#define ieprc_pci_PCIE_CFC_RCEC_EPA_EXT_CAP_HDR_PCIE_EXT_CAP_ID(x) (((uint32_t)(((uint32_t)(x)) << ieprc_pci_PCIE_CFC_RCEC_EPA_EXT_CAP_HDR_PCIE_EXT_CAP_ID_SHIFT)) & ieprc_pci_PCIE_CFC_RCEC_EPA_EXT_CAP_HDR_PCIE_EXT_CAP_ID_MASK)

#define ieprc_pci_PCIE_CFC_RCEC_EPA_EXT_CAP_HDR_CAP_VER_MASK (0xF0000U)
#define ieprc_pci_PCIE_CFC_RCEC_EPA_EXT_CAP_HDR_CAP_VER_SHIFT (16U)
#define ieprc_pci_PCIE_CFC_RCEC_EPA_EXT_CAP_HDR_CAP_VER_WIDTH (4U)
#define ieprc_pci_PCIE_CFC_RCEC_EPA_EXT_CAP_HDR_CAP_VER(x) (((uint32_t)(((uint32_t)(x)) << ieprc_pci_PCIE_CFC_RCEC_EPA_EXT_CAP_HDR_CAP_VER_SHIFT)) & ieprc_pci_PCIE_CFC_RCEC_EPA_EXT_CAP_HDR_CAP_VER_MASK)

#define ieprc_pci_PCIE_CFC_RCEC_EPA_EXT_CAP_HDR_NEXT_CAP_OFF_MASK (0xFFF00000U)
#define ieprc_pci_PCIE_CFC_RCEC_EPA_EXT_CAP_HDR_NEXT_CAP_OFF_SHIFT (20U)
#define ieprc_pci_PCIE_CFC_RCEC_EPA_EXT_CAP_HDR_NEXT_CAP_OFF_WIDTH (12U)
#define ieprc_pci_PCIE_CFC_RCEC_EPA_EXT_CAP_HDR_NEXT_CAP_OFF(x) (((uint32_t)(((uint32_t)(x)) << ieprc_pci_PCIE_CFC_RCEC_EPA_EXT_CAP_HDR_NEXT_CAP_OFF_SHIFT)) & ieprc_pci_PCIE_CFC_RCEC_EPA_EXT_CAP_HDR_NEXT_CAP_OFF_MASK)
/*! @} */

/*! @name PCIE_CFC_RCEC_EPA_BITMAP - PCIe RCEC Endpoint association bitmap register */
/*! @{ */

#define ieprc_pci_PCIE_CFC_RCEC_EPA_BITMAP_DEV_BITMAP_MASK (0xFFFFFFFFU)
#define ieprc_pci_PCIE_CFC_RCEC_EPA_BITMAP_DEV_BITMAP_SHIFT (0U)
#define ieprc_pci_PCIE_CFC_RCEC_EPA_BITMAP_DEV_BITMAP_WIDTH (32U)
#define ieprc_pci_PCIE_CFC_RCEC_EPA_BITMAP_DEV_BITMAP(x) (((uint32_t)(((uint32_t)(x)) << ieprc_pci_PCIE_CFC_RCEC_EPA_BITMAP_DEV_BITMAP_SHIFT)) & ieprc_pci_PCIE_CFC_RCEC_EPA_BITMAP_DEV_BITMAP_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group ieprc_pci_Register_Masks */

/*!
 * @}
 */ /* end of group ieprc_pci_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K566_ieprc_pci_H_) */
