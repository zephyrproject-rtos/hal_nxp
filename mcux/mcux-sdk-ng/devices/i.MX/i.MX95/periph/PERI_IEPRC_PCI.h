/*
** ###################################################################
**     Processors:          MIMX9594AVZXN_ca55
**                          MIMX9594AVZXN_cm33
**                          MIMX9594AVZXN_cm7
**                          MIMX9596AVTXN_ca55
**                          MIMX9596AVTXN_cm33
**                          MIMX9596AVTXN_cm7
**                          MIMX9596AVYXN_ca55
**                          MIMX9596AVYXN_cm33
**                          MIMX9596AVYXN_cm7
**                          MIMX9596AVZXN_ca55
**                          MIMX9596AVZXN_cm33
**                          MIMX9596AVZXN_cm7
**                          MIMX9596CVTXN_ca55
**                          MIMX9596CVTXN_cm33
**                          MIMX9596CVTXN_cm7
**                          MIMX9596CVYXN_ca55
**                          MIMX9596CVYXN_cm33
**                          MIMX9596CVYXN_cm7
**                          MIMX9596CVZXN_ca55
**                          MIMX9596CVZXN_cm33
**                          MIMX9596CVZXN_cm7
**                          MIMX9596DVTXN_ca55
**                          MIMX9596DVTXN_cm33
**                          MIMX9596DVTXN_cm7
**                          MIMX9596DVYXN_ca55
**                          MIMX9596DVYXN_cm33
**                          MIMX9596DVYXN_cm7
**                          MIMX9596DVYXQ_ca55
**                          MIMX9596DVYXQ_cm33
**                          MIMX9596DVYXQ_cm7
**                          MIMX9596DVZXN_ca55
**                          MIMX9596DVZXN_cm33
**                          MIMX9596DVZXN_cm7
**                          MIMX9596XVTXN_ca55
**                          MIMX9596XVTXN_cm33
**                          MIMX9596XVTXN_cm7
**                          MIMX9596XVYXN_ca55
**                          MIMX9596XVYXN_cm33
**                          MIMX9596XVYXN_cm7
**                          MIMX9596XVZXN_ca55
**                          MIMX9596XVZXN_cm33
**                          MIMX9596XVZXN_cm7
**
**     Version:             rev. 1.0, 2023-01-10
**     Build:               b240728
**
**     Abstract:
**         CMSIS Peripheral Access Layer for ieprc_pci
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2023-01-10)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file ieprc_pci.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for ieprc_pci
 *
 * CMSIS Peripheral Access Layer for ieprc_pci
 */

#if !defined(ieprc_pci_H_)
#define ieprc_pci_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX9594AVZXN_ca55))
#include "MIMX9594_ca55_COMMON.h"
#elif (defined(CPU_MIMX9594AVZXN_cm33))
#include "MIMX9594_cm33_COMMON.h"
#elif (defined(CPU_MIMX9594AVZXN_cm7))
#include "MIMX9594_cm7_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_ca55) || defined(CPU_MIMX9596AVYXN_ca55) || defined(CPU_MIMX9596AVZXN_ca55) || defined(CPU_MIMX9596CVTXN_ca55) || defined(CPU_MIMX9596CVYXN_ca55) || defined(CPU_MIMX9596CVZXN_ca55) || defined(CPU_MIMX9596DVTXN_ca55) || defined(CPU_MIMX9596DVYXN_ca55) || defined(CPU_MIMX9596DVYXQ_ca55) || defined(CPU_MIMX9596DVZXN_ca55) || defined(CPU_MIMX9596XVTXN_ca55) || defined(CPU_MIMX9596XVYXN_ca55) || defined(CPU_MIMX9596XVZXN_ca55))
#include "MIMX9596_ca55_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_cm33) || defined(CPU_MIMX9596AVYXN_cm33) || defined(CPU_MIMX9596AVZXN_cm33) || defined(CPU_MIMX9596CVTXN_cm33) || defined(CPU_MIMX9596CVYXN_cm33) || defined(CPU_MIMX9596CVZXN_cm33) || defined(CPU_MIMX9596DVTXN_cm33) || defined(CPU_MIMX9596DVYXN_cm33) || defined(CPU_MIMX9596DVYXQ_cm33) || defined(CPU_MIMX9596DVZXN_cm33) || defined(CPU_MIMX9596XVTXN_cm33) || defined(CPU_MIMX9596XVYXN_cm33) || defined(CPU_MIMX9596XVZXN_cm33))
#include "MIMX9596_cm33_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_cm7) || defined(CPU_MIMX9596AVYXN_cm7) || defined(CPU_MIMX9596AVZXN_cm7) || defined(CPU_MIMX9596CVTXN_cm7) || defined(CPU_MIMX9596CVYXN_cm7) || defined(CPU_MIMX9596CVZXN_cm7) || defined(CPU_MIMX9596DVTXN_cm7) || defined(CPU_MIMX9596DVYXN_cm7) || defined(CPU_MIMX9596DVYXQ_cm7) || defined(CPU_MIMX9596DVZXN_cm7) || defined(CPU_MIMX9596XVTXN_cm7) || defined(CPU_MIMX9596XVYXN_cm7) || defined(CPU_MIMX9596XVZXN_cm7))
#include "MIMX9596_cm7_COMMON.h"
#else
  #error "No valid CPU defined!"
#endif

/* ----------------------------------------------------------------------------
   -- Device Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Peripheral_access_layer Device Peripheral Access Layer
 * @{
 */


/*
** Start of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic push
  #else
    #pragma push
    #pragma anon_unions
  #endif
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=extended
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- ieprc_pci Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ieprc_pci_Peripheral_Access_Layer ieprc_pci Peripheral Access Layer
 * @{
 */

/** ieprc_pci - Register Layout Typedef */
typedef struct {
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
       uint8_t PCI_CFC_PCIPM_DATA;                 /**< PCI PCI-PM capabilities data register, offset: 0x87 */
       uint8_t RESERVED_10[120];
  __I  uint32_t PCIE_CFC_AER_EXT_CAP_HDR;          /**< PCIe AER extended capability header, offset: 0x100 */
       uint8_t RESERVED_11[40];
  __IO uint32_t PCIE_CFC_AER_ROOT_ERR_CMD;         /**< PCIe AER root error command register, offset: 0x12C */
  __IO uint32_t PCIE_CFC_AER_ROOT_ERR_STAT;        /**< PCIe AER root error status register, offset: 0x130 */
  __I  uint32_t PCIE_CFC_AER_ERR_SRC_ID;           /**< PCIe AER error source identification register, offset: 0x134 */
  __I  uint32_t PCIE_CFC_RCEC_EPA_EXT_CAP_HDR;     /**< PCIe RCEC Endpoint association extended capability header, offset: 0x138 */
  __I  uint32_t PCIE_CFC_RCEC_EPA_BITMAP;          /**< PCIe RCEC Endpoint association bitmap register, offset: 0x13C */
} ieprc_pci_Type;

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
#define ieprc_pci_PCI_CFH_DID_VID_VENDOR_ID(x)   (((uint32_t)(((uint32_t)(x)) << ieprc_pci_PCI_CFH_DID_VID_VENDOR_ID_SHIFT)) & ieprc_pci_PCI_CFH_DID_VID_VENDOR_ID_MASK)

#define ieprc_pci_PCI_CFH_DID_VID_DEVICE_ID_MASK (0xFFFF0000U)
#define ieprc_pci_PCI_CFH_DID_VID_DEVICE_ID_SHIFT (16U)
#define ieprc_pci_PCI_CFH_DID_VID_DEVICE_ID(x)   (((uint32_t)(((uint32_t)(x)) << ieprc_pci_PCI_CFH_DID_VID_DEVICE_ID_SHIFT)) & ieprc_pci_PCI_CFH_DID_VID_DEVICE_ID_MASK)
/*! @} */

/*! @name PCI_CFH_CMD - PCI command register */
/*! @{ */

#define ieprc_pci_PCI_CFH_CMD_INTR_DISABLE_MASK  (0x400U)
#define ieprc_pci_PCI_CFH_CMD_INTR_DISABLE_SHIFT (10U)
#define ieprc_pci_PCI_CFH_CMD_INTR_DISABLE(x)    (((uint16_t)(((uint16_t)(x)) << ieprc_pci_PCI_CFH_CMD_INTR_DISABLE_SHIFT)) & ieprc_pci_PCI_CFH_CMD_INTR_DISABLE_MASK)
/*! @} */

/*! @name PCI_CFH_STAT - PCI status register */
/*! @{ */

#define ieprc_pci_PCI_CFH_STAT_INTR_STATUS_MASK  (0x8U)
#define ieprc_pci_PCI_CFH_STAT_INTR_STATUS_SHIFT (3U)
#define ieprc_pci_PCI_CFH_STAT_INTR_STATUS(x)    (((uint16_t)(((uint16_t)(x)) << ieprc_pci_PCI_CFH_STAT_INTR_STATUS_SHIFT)) & ieprc_pci_PCI_CFH_STAT_INTR_STATUS_MASK)

#define ieprc_pci_PCI_CFH_STAT_CAP_LIST_MASK     (0x10U)
#define ieprc_pci_PCI_CFH_STAT_CAP_LIST_SHIFT    (4U)
#define ieprc_pci_PCI_CFH_STAT_CAP_LIST(x)       (((uint16_t)(((uint16_t)(x)) << ieprc_pci_PCI_CFH_STAT_CAP_LIST_SHIFT)) & ieprc_pci_PCI_CFH_STAT_CAP_LIST_MASK)
/*! @} */

/*! @name PCI_CFH_REVID_CLASSCODE - PCI revision ID and classcode register */
/*! @{ */

#define ieprc_pci_PCI_CFH_REVID_CLASSCODE_REV_ID_MASK (0xFFU)
#define ieprc_pci_PCI_CFH_REVID_CLASSCODE_REV_ID_SHIFT (0U)
#define ieprc_pci_PCI_CFH_REVID_CLASSCODE_REV_ID(x) (((uint32_t)(((uint32_t)(x)) << ieprc_pci_PCI_CFH_REVID_CLASSCODE_REV_ID_SHIFT)) & ieprc_pci_PCI_CFH_REVID_CLASSCODE_REV_ID_MASK)

#define ieprc_pci_PCI_CFH_REVID_CLASSCODE_CLASS_CODE_MASK (0xFFFFFF00U)
#define ieprc_pci_PCI_CFH_REVID_CLASSCODE_CLASS_CODE_SHIFT (8U)
#define ieprc_pci_PCI_CFH_REVID_CLASSCODE_CLASS_CODE(x) (((uint32_t)(((uint32_t)(x)) << ieprc_pci_PCI_CFH_REVID_CLASSCODE_CLASS_CODE_SHIFT)) & ieprc_pci_PCI_CFH_REVID_CLASSCODE_CLASS_CODE_MASK)
/*! @} */

/*! @name PCI_CFH_CL_SIZE - PCI cache line size register */
/*! @{ */

#define ieprc_pci_PCI_CFH_CL_SIZE_CACHE_LINE_SIZE_MASK (0xFFU)
#define ieprc_pci_PCI_CFH_CL_SIZE_CACHE_LINE_SIZE_SHIFT (0U)
#define ieprc_pci_PCI_CFH_CL_SIZE_CACHE_LINE_SIZE(x) (((uint8_t)(((uint8_t)(x)) << ieprc_pci_PCI_CFH_CL_SIZE_CACHE_LINE_SIZE_SHIFT)) & ieprc_pci_PCI_CFH_CL_SIZE_CACHE_LINE_SIZE_MASK)
/*! @} */

/*! @name PCI_CFH_HDR_TYPE - PCI header type register */
/*! @{ */

#define ieprc_pci_PCI_CFH_HDR_TYPE_HDR_TYPE_MASK (0x7FU)
#define ieprc_pci_PCI_CFH_HDR_TYPE_HDR_TYPE_SHIFT (0U)
#define ieprc_pci_PCI_CFH_HDR_TYPE_HDR_TYPE(x)   (((uint8_t)(((uint8_t)(x)) << ieprc_pci_PCI_CFH_HDR_TYPE_HDR_TYPE_SHIFT)) & ieprc_pci_PCI_CFH_HDR_TYPE_HDR_TYPE_MASK)

#define ieprc_pci_PCI_CFH_HDR_TYPE_MULT_FUNC_DEV_MASK (0x80U)
#define ieprc_pci_PCI_CFH_HDR_TYPE_MULT_FUNC_DEV_SHIFT (7U)
#define ieprc_pci_PCI_CFH_HDR_TYPE_MULT_FUNC_DEV(x) (((uint8_t)(((uint8_t)(x)) << ieprc_pci_PCI_CFH_HDR_TYPE_MULT_FUNC_DEV_SHIFT)) & ieprc_pci_PCI_CFH_HDR_TYPE_MULT_FUNC_DEV_MASK)
/*! @} */

/*! @name PCI_CFH_SUBSYS_VID - PCI subsystem vendor ID register */
/*! @{ */

#define ieprc_pci_PCI_CFH_SUBSYS_VID_SUBSYSTEM_VENDOR_ID_MASK (0xFFFFU)
#define ieprc_pci_PCI_CFH_SUBSYS_VID_SUBSYSTEM_VENDOR_ID_SHIFT (0U)
#define ieprc_pci_PCI_CFH_SUBSYS_VID_SUBSYSTEM_VENDOR_ID(x) (((uint16_t)(((uint16_t)(x)) << ieprc_pci_PCI_CFH_SUBSYS_VID_SUBSYSTEM_VENDOR_ID_SHIFT)) & ieprc_pci_PCI_CFH_SUBSYS_VID_SUBSYSTEM_VENDOR_ID_MASK)
/*! @} */

/*! @name PCI_CFH_SUBSYS_ID - PCI subsystem ID register */
/*! @{ */

#define ieprc_pci_PCI_CFH_SUBSYS_ID_SUBSYSTEM_ID_MASK (0xFFFFU)
#define ieprc_pci_PCI_CFH_SUBSYS_ID_SUBSYSTEM_ID_SHIFT (0U)
#define ieprc_pci_PCI_CFH_SUBSYS_ID_SUBSYSTEM_ID(x) (((uint16_t)(((uint16_t)(x)) << ieprc_pci_PCI_CFH_SUBSYS_ID_SUBSYSTEM_ID_SHIFT)) & ieprc_pci_PCI_CFH_SUBSYS_ID_SUBSYSTEM_ID_MASK)
/*! @} */

/*! @name PCI_CFH_CAP_PTR - PCI capabilities pointer register */
/*! @{ */

#define ieprc_pci_PCI_CFH_CAP_PTR_CAP_PTR_MASK   (0xFFU)
#define ieprc_pci_PCI_CFH_CAP_PTR_CAP_PTR_SHIFT  (0U)
#define ieprc_pci_PCI_CFH_CAP_PTR_CAP_PTR(x)     (((uint8_t)(((uint8_t)(x)) << ieprc_pci_PCI_CFH_CAP_PTR_CAP_PTR_SHIFT)) & ieprc_pci_PCI_CFH_CAP_PTR_CAP_PTR_MASK)
/*! @} */

/*! @name PCI_CFH_INT_LINE - PCI interrupt line register */
/*! @{ */

#define ieprc_pci_PCI_CFH_INT_LINE_INT_LINE_MASK (0xFFU)
#define ieprc_pci_PCI_CFH_INT_LINE_INT_LINE_SHIFT (0U)
#define ieprc_pci_PCI_CFH_INT_LINE_INT_LINE(x)   (((uint8_t)(((uint8_t)(x)) << ieprc_pci_PCI_CFH_INT_LINE_INT_LINE_SHIFT)) & ieprc_pci_PCI_CFH_INT_LINE_INT_LINE_MASK)
/*! @} */

/*! @name PCI_CFH_INT_PIN - PCI interrupt pin register */
/*! @{ */

#define ieprc_pci_PCI_CFH_INT_PIN_INT_PIN_MASK   (0xFFU)
#define ieprc_pci_PCI_CFH_INT_PIN_INT_PIN_SHIFT  (0U)
#define ieprc_pci_PCI_CFH_INT_PIN_INT_PIN(x)     (((uint8_t)(((uint8_t)(x)) << ieprc_pci_PCI_CFH_INT_PIN_INT_PIN_SHIFT)) & ieprc_pci_PCI_CFH_INT_PIN_INT_PIN_MASK)
/*! @} */

/*! @name PCI_CFC_PCIE_CAP_LIST - PCI PCIe capabilities list register */
/*! @{ */

#define ieprc_pci_PCI_CFC_PCIE_CAP_LIST_CAP_ID_MASK (0xFFU)
#define ieprc_pci_PCI_CFC_PCIE_CAP_LIST_CAP_ID_SHIFT (0U)
#define ieprc_pci_PCI_CFC_PCIE_CAP_LIST_CAP_ID(x) (((uint16_t)(((uint16_t)(x)) << ieprc_pci_PCI_CFC_PCIE_CAP_LIST_CAP_ID_SHIFT)) & ieprc_pci_PCI_CFC_PCIE_CAP_LIST_CAP_ID_MASK)

#define ieprc_pci_PCI_CFC_PCIE_CAP_LIST_NEXT_CAP_PTR_MASK (0xFF00U)
#define ieprc_pci_PCI_CFC_PCIE_CAP_LIST_NEXT_CAP_PTR_SHIFT (8U)
#define ieprc_pci_PCI_CFC_PCIE_CAP_LIST_NEXT_CAP_PTR(x) (((uint16_t)(((uint16_t)(x)) << ieprc_pci_PCI_CFC_PCIE_CAP_LIST_NEXT_CAP_PTR_SHIFT)) & ieprc_pci_PCI_CFC_PCIE_CAP_LIST_NEXT_CAP_PTR_MASK)
/*! @} */

/*! @name PCI_CFC_PCIE_CAP - PCI PCIe capabilities register */
/*! @{ */

#define ieprc_pci_PCI_CFC_PCIE_CAP_CAP_VER_MASK  (0xFU)
#define ieprc_pci_PCI_CFC_PCIE_CAP_CAP_VER_SHIFT (0U)
#define ieprc_pci_PCI_CFC_PCIE_CAP_CAP_VER(x)    (((uint16_t)(((uint16_t)(x)) << ieprc_pci_PCI_CFC_PCIE_CAP_CAP_VER_SHIFT)) & ieprc_pci_PCI_CFC_PCIE_CAP_CAP_VER_MASK)

#define ieprc_pci_PCI_CFC_PCIE_CAP_DEV_PORT_TYPE_MASK (0xF0U)
#define ieprc_pci_PCI_CFC_PCIE_CAP_DEV_PORT_TYPE_SHIFT (4U)
#define ieprc_pci_PCI_CFC_PCIE_CAP_DEV_PORT_TYPE(x) (((uint16_t)(((uint16_t)(x)) << ieprc_pci_PCI_CFC_PCIE_CAP_DEV_PORT_TYPE_SHIFT)) & ieprc_pci_PCI_CFC_PCIE_CAP_DEV_PORT_TYPE_MASK)

#define ieprc_pci_PCI_CFC_PCIE_CAP_INT_MSG_NUM_MASK (0x3E00U)
#define ieprc_pci_PCI_CFC_PCIE_CAP_INT_MSG_NUM_SHIFT (9U)
#define ieprc_pci_PCI_CFC_PCIE_CAP_INT_MSG_NUM(x) (((uint16_t)(((uint16_t)(x)) << ieprc_pci_PCI_CFC_PCIE_CAP_INT_MSG_NUM_SHIFT)) & ieprc_pci_PCI_CFC_PCIE_CAP_INT_MSG_NUM_MASK)
/*! @} */

/*! @name PCI_CFC_PCIE_DEV_CAP - PCI PCIe device capabilities register */
/*! @{ */

#define ieprc_pci_PCI_CFC_PCIE_DEV_CAP_FLR_CAP_MASK (0x10000000U)
#define ieprc_pci_PCI_CFC_PCIE_DEV_CAP_FLR_CAP_SHIFT (28U)
#define ieprc_pci_PCI_CFC_PCIE_DEV_CAP_FLR_CAP(x) (((uint32_t)(((uint32_t)(x)) << ieprc_pci_PCI_CFC_PCIE_DEV_CAP_FLR_CAP_SHIFT)) & ieprc_pci_PCI_CFC_PCIE_DEV_CAP_FLR_CAP_MASK)
/*! @} */

/*! @name PCI_CFC_PCIE_DEV_STAT - PCI PCIe device status register */
/*! @{ */

#define ieprc_pci_PCI_CFC_PCIE_DEV_STAT_TRANS_PEND_MASK (0x20U)
#define ieprc_pci_PCI_CFC_PCIE_DEV_STAT_TRANS_PEND_SHIFT (5U)
#define ieprc_pci_PCI_CFC_PCIE_DEV_STAT_TRANS_PEND(x) (((uint16_t)(((uint16_t)(x)) << ieprc_pci_PCI_CFC_PCIE_DEV_STAT_TRANS_PEND_SHIFT)) & ieprc_pci_PCI_CFC_PCIE_DEV_STAT_TRANS_PEND_MASK)
/*! @} */

/*! @name PCI_CFC_PCIE_ROOT_CTL - PCI PCIe root control register */
/*! @{ */

#define ieprc_pci_PCI_CFC_PCIE_ROOT_CTL_PME_INT_EN_MASK (0x8U)
#define ieprc_pci_PCI_CFC_PCIE_ROOT_CTL_PME_INT_EN_SHIFT (3U)
#define ieprc_pci_PCI_CFC_PCIE_ROOT_CTL_PME_INT_EN(x) (((uint16_t)(((uint16_t)(x)) << ieprc_pci_PCI_CFC_PCIE_ROOT_CTL_PME_INT_EN_SHIFT)) & ieprc_pci_PCI_CFC_PCIE_ROOT_CTL_PME_INT_EN_MASK)
/*! @} */

/*! @name PCI_CFC_PCIE_ROOT_STAT - PCI PCIe root status register */
/*! @{ */

#define ieprc_pci_PCI_CFC_PCIE_ROOT_STAT_PME_REQ_ID_MASK (0xFFFFU)
#define ieprc_pci_PCI_CFC_PCIE_ROOT_STAT_PME_REQ_ID_SHIFT (0U)
#define ieprc_pci_PCI_CFC_PCIE_ROOT_STAT_PME_REQ_ID(x) (((uint32_t)(((uint32_t)(x)) << ieprc_pci_PCI_CFC_PCIE_ROOT_STAT_PME_REQ_ID_SHIFT)) & ieprc_pci_PCI_CFC_PCIE_ROOT_STAT_PME_REQ_ID_MASK)

#define ieprc_pci_PCI_CFC_PCIE_ROOT_STAT_PME_STATUS_MASK (0x10000U)
#define ieprc_pci_PCI_CFC_PCIE_ROOT_STAT_PME_STATUS_SHIFT (16U)
#define ieprc_pci_PCI_CFC_PCIE_ROOT_STAT_PME_STATUS(x) (((uint32_t)(((uint32_t)(x)) << ieprc_pci_PCI_CFC_PCIE_ROOT_STAT_PME_STATUS_SHIFT)) & ieprc_pci_PCI_CFC_PCIE_ROOT_STAT_PME_STATUS_MASK)

#define ieprc_pci_PCI_CFC_PCIE_ROOT_STAT_PME_PEND_MASK (0x20000U)
#define ieprc_pci_PCI_CFC_PCIE_ROOT_STAT_PME_PEND_SHIFT (17U)
#define ieprc_pci_PCI_CFC_PCIE_ROOT_STAT_PME_PEND(x) (((uint32_t)(((uint32_t)(x)) << ieprc_pci_PCI_CFC_PCIE_ROOT_STAT_PME_PEND_SHIFT)) & ieprc_pci_PCI_CFC_PCIE_ROOT_STAT_PME_PEND_MASK)
/*! @} */

/*! @name PCI_CFC_PCIPM_CAP_LIST - PCI PCI-PM capabilities list register */
/*! @{ */

#define ieprc_pci_PCI_CFC_PCIPM_CAP_LIST_CAP_ID_MASK (0xFFU)
#define ieprc_pci_PCI_CFC_PCIPM_CAP_LIST_CAP_ID_SHIFT (0U)
#define ieprc_pci_PCI_CFC_PCIPM_CAP_LIST_CAP_ID(x) (((uint16_t)(((uint16_t)(x)) << ieprc_pci_PCI_CFC_PCIPM_CAP_LIST_CAP_ID_SHIFT)) & ieprc_pci_PCI_CFC_PCIPM_CAP_LIST_CAP_ID_MASK)

#define ieprc_pci_PCI_CFC_PCIPM_CAP_LIST_NEXT_CAP_PTR_MASK (0xFF00U)
#define ieprc_pci_PCI_CFC_PCIPM_CAP_LIST_NEXT_CAP_PTR_SHIFT (8U)
#define ieprc_pci_PCI_CFC_PCIPM_CAP_LIST_NEXT_CAP_PTR(x) (((uint16_t)(((uint16_t)(x)) << ieprc_pci_PCI_CFC_PCIPM_CAP_LIST_NEXT_CAP_PTR_SHIFT)) & ieprc_pci_PCI_CFC_PCIPM_CAP_LIST_NEXT_CAP_PTR_MASK)
/*! @} */

/*! @name PCI_CFC_PCIPM_CAP - PCI PCI-PM capabilities register */
/*! @{ */

#define ieprc_pci_PCI_CFC_PCIPM_CAP_VERSION_MASK (0x7U)
#define ieprc_pci_PCI_CFC_PCIPM_CAP_VERSION_SHIFT (0U)
#define ieprc_pci_PCI_CFC_PCIPM_CAP_VERSION(x)   (((uint16_t)(((uint16_t)(x)) << ieprc_pci_PCI_CFC_PCIPM_CAP_VERSION_SHIFT)) & ieprc_pci_PCI_CFC_PCIPM_CAP_VERSION_MASK)

#define ieprc_pci_PCI_CFC_PCIPM_CAP_PME_SUPPORT_MASK (0xF800U)
#define ieprc_pci_PCI_CFC_PCIPM_CAP_PME_SUPPORT_SHIFT (11U)
#define ieprc_pci_PCI_CFC_PCIPM_CAP_PME_SUPPORT(x) (((uint16_t)(((uint16_t)(x)) << ieprc_pci_PCI_CFC_PCIPM_CAP_PME_SUPPORT_SHIFT)) & ieprc_pci_PCI_CFC_PCIPM_CAP_PME_SUPPORT_MASK)
/*! @} */

/*! @name PCI_CFC_PCIPM_CTL_STAT - PCI PCI-PM control and status register */
/*! @{ */

#define ieprc_pci_PCI_CFC_PCIPM_CTL_STAT_PWR_STATE_MASK (0x3U)
#define ieprc_pci_PCI_CFC_PCIPM_CTL_STAT_PWR_STATE_SHIFT (0U)
#define ieprc_pci_PCI_CFC_PCIPM_CTL_STAT_PWR_STATE(x) (((uint16_t)(((uint16_t)(x)) << ieprc_pci_PCI_CFC_PCIPM_CTL_STAT_PWR_STATE_SHIFT)) & ieprc_pci_PCI_CFC_PCIPM_CTL_STAT_PWR_STATE_MASK)

#define ieprc_pci_PCI_CFC_PCIPM_CTL_STAT_NO_SOFT_RST_MASK (0x8U)
#define ieprc_pci_PCI_CFC_PCIPM_CTL_STAT_NO_SOFT_RST_SHIFT (3U)
#define ieprc_pci_PCI_CFC_PCIPM_CTL_STAT_NO_SOFT_RST(x) (((uint16_t)(((uint16_t)(x)) << ieprc_pci_PCI_CFC_PCIPM_CTL_STAT_NO_SOFT_RST_SHIFT)) & ieprc_pci_PCI_CFC_PCIPM_CTL_STAT_NO_SOFT_RST_MASK)
/*! @} */

/*! @name PCIE_CFC_AER_EXT_CAP_HDR - PCIe AER extended capability header */
/*! @{ */

#define ieprc_pci_PCIE_CFC_AER_EXT_CAP_HDR_PCIE_EXT_CAP_ID_MASK (0xFFFFU)
#define ieprc_pci_PCIE_CFC_AER_EXT_CAP_HDR_PCIE_EXT_CAP_ID_SHIFT (0U)
#define ieprc_pci_PCIE_CFC_AER_EXT_CAP_HDR_PCIE_EXT_CAP_ID(x) (((uint32_t)(((uint32_t)(x)) << ieprc_pci_PCIE_CFC_AER_EXT_CAP_HDR_PCIE_EXT_CAP_ID_SHIFT)) & ieprc_pci_PCIE_CFC_AER_EXT_CAP_HDR_PCIE_EXT_CAP_ID_MASK)

#define ieprc_pci_PCIE_CFC_AER_EXT_CAP_HDR_CAP_VER_MASK (0xF0000U)
#define ieprc_pci_PCIE_CFC_AER_EXT_CAP_HDR_CAP_VER_SHIFT (16U)
#define ieprc_pci_PCIE_CFC_AER_EXT_CAP_HDR_CAP_VER(x) (((uint32_t)(((uint32_t)(x)) << ieprc_pci_PCIE_CFC_AER_EXT_CAP_HDR_CAP_VER_SHIFT)) & ieprc_pci_PCIE_CFC_AER_EXT_CAP_HDR_CAP_VER_MASK)

#define ieprc_pci_PCIE_CFC_AER_EXT_CAP_HDR_NEXT_CAP_OFF_MASK (0xFFF00000U)
#define ieprc_pci_PCIE_CFC_AER_EXT_CAP_HDR_NEXT_CAP_OFF_SHIFT (20U)
#define ieprc_pci_PCIE_CFC_AER_EXT_CAP_HDR_NEXT_CAP_OFF(x) (((uint32_t)(((uint32_t)(x)) << ieprc_pci_PCIE_CFC_AER_EXT_CAP_HDR_NEXT_CAP_OFF_SHIFT)) & ieprc_pci_PCIE_CFC_AER_EXT_CAP_HDR_NEXT_CAP_OFF_MASK)
/*! @} */

/*! @name PCIE_CFC_AER_ROOT_ERR_CMD - PCIe AER root error command register */
/*! @{ */

#define ieprc_pci_PCIE_CFC_AER_ROOT_ERR_CMD_CORR_ERR_RPT_EN_MASK (0x1U)
#define ieprc_pci_PCIE_CFC_AER_ROOT_ERR_CMD_CORR_ERR_RPT_EN_SHIFT (0U)
#define ieprc_pci_PCIE_CFC_AER_ROOT_ERR_CMD_CORR_ERR_RPT_EN(x) (((uint32_t)(((uint32_t)(x)) << ieprc_pci_PCIE_CFC_AER_ROOT_ERR_CMD_CORR_ERR_RPT_EN_SHIFT)) & ieprc_pci_PCIE_CFC_AER_ROOT_ERR_CMD_CORR_ERR_RPT_EN_MASK)

#define ieprc_pci_PCIE_CFC_AER_ROOT_ERR_CMD_NON_FATAL_ERR_RPT_EN_MASK (0x2U)
#define ieprc_pci_PCIE_CFC_AER_ROOT_ERR_CMD_NON_FATAL_ERR_RPT_EN_SHIFT (1U)
#define ieprc_pci_PCIE_CFC_AER_ROOT_ERR_CMD_NON_FATAL_ERR_RPT_EN(x) (((uint32_t)(((uint32_t)(x)) << ieprc_pci_PCIE_CFC_AER_ROOT_ERR_CMD_NON_FATAL_ERR_RPT_EN_SHIFT)) & ieprc_pci_PCIE_CFC_AER_ROOT_ERR_CMD_NON_FATAL_ERR_RPT_EN_MASK)

#define ieprc_pci_PCIE_CFC_AER_ROOT_ERR_CMD_FATAL_ERR_RPT_EN_MASK (0x4U)
#define ieprc_pci_PCIE_CFC_AER_ROOT_ERR_CMD_FATAL_ERR_RPT_EN_SHIFT (2U)
#define ieprc_pci_PCIE_CFC_AER_ROOT_ERR_CMD_FATAL_ERR_RPT_EN(x) (((uint32_t)(((uint32_t)(x)) << ieprc_pci_PCIE_CFC_AER_ROOT_ERR_CMD_FATAL_ERR_RPT_EN_SHIFT)) & ieprc_pci_PCIE_CFC_AER_ROOT_ERR_CMD_FATAL_ERR_RPT_EN_MASK)
/*! @} */

/*! @name PCIE_CFC_AER_ROOT_ERR_STAT - PCIe AER root error status register */
/*! @{ */

#define ieprc_pci_PCIE_CFC_AER_ROOT_ERR_STAT_ERR_CORR_MASK (0x1U)
#define ieprc_pci_PCIE_CFC_AER_ROOT_ERR_STAT_ERR_CORR_SHIFT (0U)
#define ieprc_pci_PCIE_CFC_AER_ROOT_ERR_STAT_ERR_CORR(x) (((uint32_t)(((uint32_t)(x)) << ieprc_pci_PCIE_CFC_AER_ROOT_ERR_STAT_ERR_CORR_SHIFT)) & ieprc_pci_PCIE_CFC_AER_ROOT_ERR_STAT_ERR_CORR_MASK)

#define ieprc_pci_PCIE_CFC_AER_ROOT_ERR_STAT_MULT_ERR_CORR_MASK (0x2U)
#define ieprc_pci_PCIE_CFC_AER_ROOT_ERR_STAT_MULT_ERR_CORR_SHIFT (1U)
#define ieprc_pci_PCIE_CFC_AER_ROOT_ERR_STAT_MULT_ERR_CORR(x) (((uint32_t)(((uint32_t)(x)) << ieprc_pci_PCIE_CFC_AER_ROOT_ERR_STAT_MULT_ERR_CORR_SHIFT)) & ieprc_pci_PCIE_CFC_AER_ROOT_ERR_STAT_MULT_ERR_CORR_MASK)

#define ieprc_pci_PCIE_CFC_AER_ROOT_ERR_STAT_ERR_FATAL_NON_FATAL_MASK (0x4U)
#define ieprc_pci_PCIE_CFC_AER_ROOT_ERR_STAT_ERR_FATAL_NON_FATAL_SHIFT (2U)
#define ieprc_pci_PCIE_CFC_AER_ROOT_ERR_STAT_ERR_FATAL_NON_FATAL(x) (((uint32_t)(((uint32_t)(x)) << ieprc_pci_PCIE_CFC_AER_ROOT_ERR_STAT_ERR_FATAL_NON_FATAL_SHIFT)) & ieprc_pci_PCIE_CFC_AER_ROOT_ERR_STAT_ERR_FATAL_NON_FATAL_MASK)

#define ieprc_pci_PCIE_CFC_AER_ROOT_ERR_STAT_MULT_ERR_FATAL_NON_FATAL_MASK (0x8U)
#define ieprc_pci_PCIE_CFC_AER_ROOT_ERR_STAT_MULT_ERR_FATAL_NON_FATAL_SHIFT (3U)
#define ieprc_pci_PCIE_CFC_AER_ROOT_ERR_STAT_MULT_ERR_FATAL_NON_FATAL(x) (((uint32_t)(((uint32_t)(x)) << ieprc_pci_PCIE_CFC_AER_ROOT_ERR_STAT_MULT_ERR_FATAL_NON_FATAL_SHIFT)) & ieprc_pci_PCIE_CFC_AER_ROOT_ERR_STAT_MULT_ERR_FATAL_NON_FATAL_MASK)

#define ieprc_pci_PCIE_CFC_AER_ROOT_ERR_STAT_FIRST_UCORR_FATAL_MASK (0x10U)
#define ieprc_pci_PCIE_CFC_AER_ROOT_ERR_STAT_FIRST_UCORR_FATAL_SHIFT (4U)
#define ieprc_pci_PCIE_CFC_AER_ROOT_ERR_STAT_FIRST_UCORR_FATAL(x) (((uint32_t)(((uint32_t)(x)) << ieprc_pci_PCIE_CFC_AER_ROOT_ERR_STAT_FIRST_UCORR_FATAL_SHIFT)) & ieprc_pci_PCIE_CFC_AER_ROOT_ERR_STAT_FIRST_UCORR_FATAL_MASK)

#define ieprc_pci_PCIE_CFC_AER_ROOT_ERR_STAT_ERR_NON_FATAL_MASK (0x20U)
#define ieprc_pci_PCIE_CFC_AER_ROOT_ERR_STAT_ERR_NON_FATAL_SHIFT (5U)
#define ieprc_pci_PCIE_CFC_AER_ROOT_ERR_STAT_ERR_NON_FATAL(x) (((uint32_t)(((uint32_t)(x)) << ieprc_pci_PCIE_CFC_AER_ROOT_ERR_STAT_ERR_NON_FATAL_SHIFT)) & ieprc_pci_PCIE_CFC_AER_ROOT_ERR_STAT_ERR_NON_FATAL_MASK)

#define ieprc_pci_PCIE_CFC_AER_ROOT_ERR_STAT_ERR_FATAL_MASK (0x40U)
#define ieprc_pci_PCIE_CFC_AER_ROOT_ERR_STAT_ERR_FATAL_SHIFT (6U)
#define ieprc_pci_PCIE_CFC_AER_ROOT_ERR_STAT_ERR_FATAL(x) (((uint32_t)(((uint32_t)(x)) << ieprc_pci_PCIE_CFC_AER_ROOT_ERR_STAT_ERR_FATAL_SHIFT)) & ieprc_pci_PCIE_CFC_AER_ROOT_ERR_STAT_ERR_FATAL_MASK)
/*! @} */

/*! @name PCIE_CFC_AER_ERR_SRC_ID - PCIe AER error source identification register */
/*! @{ */

#define ieprc_pci_PCIE_CFC_AER_ERR_SRC_ID_ERR_CORR_SRC_ID_MASK (0xFFFFU)
#define ieprc_pci_PCIE_CFC_AER_ERR_SRC_ID_ERR_CORR_SRC_ID_SHIFT (0U)
#define ieprc_pci_PCIE_CFC_AER_ERR_SRC_ID_ERR_CORR_SRC_ID(x) (((uint32_t)(((uint32_t)(x)) << ieprc_pci_PCIE_CFC_AER_ERR_SRC_ID_ERR_CORR_SRC_ID_SHIFT)) & ieprc_pci_PCIE_CFC_AER_ERR_SRC_ID_ERR_CORR_SRC_ID_MASK)

#define ieprc_pci_PCIE_CFC_AER_ERR_SRC_ID_ERR_FATAL_NON_FATAL_SRC_ID_MASK (0xFFFF0000U)
#define ieprc_pci_PCIE_CFC_AER_ERR_SRC_ID_ERR_FATAL_NON_FATAL_SRC_ID_SHIFT (16U)
#define ieprc_pci_PCIE_CFC_AER_ERR_SRC_ID_ERR_FATAL_NON_FATAL_SRC_ID(x) (((uint32_t)(((uint32_t)(x)) << ieprc_pci_PCIE_CFC_AER_ERR_SRC_ID_ERR_FATAL_NON_FATAL_SRC_ID_SHIFT)) & ieprc_pci_PCIE_CFC_AER_ERR_SRC_ID_ERR_FATAL_NON_FATAL_SRC_ID_MASK)
/*! @} */

/*! @name PCIE_CFC_RCEC_EPA_EXT_CAP_HDR - PCIe RCEC Endpoint association extended capability header */
/*! @{ */

#define ieprc_pci_PCIE_CFC_RCEC_EPA_EXT_CAP_HDR_PCIE_EXT_CAP_ID_MASK (0xFFFFU)
#define ieprc_pci_PCIE_CFC_RCEC_EPA_EXT_CAP_HDR_PCIE_EXT_CAP_ID_SHIFT (0U)
#define ieprc_pci_PCIE_CFC_RCEC_EPA_EXT_CAP_HDR_PCIE_EXT_CAP_ID(x) (((uint32_t)(((uint32_t)(x)) << ieprc_pci_PCIE_CFC_RCEC_EPA_EXT_CAP_HDR_PCIE_EXT_CAP_ID_SHIFT)) & ieprc_pci_PCIE_CFC_RCEC_EPA_EXT_CAP_HDR_PCIE_EXT_CAP_ID_MASK)

#define ieprc_pci_PCIE_CFC_RCEC_EPA_EXT_CAP_HDR_CAP_VER_MASK (0xF0000U)
#define ieprc_pci_PCIE_CFC_RCEC_EPA_EXT_CAP_HDR_CAP_VER_SHIFT (16U)
#define ieprc_pci_PCIE_CFC_RCEC_EPA_EXT_CAP_HDR_CAP_VER(x) (((uint32_t)(((uint32_t)(x)) << ieprc_pci_PCIE_CFC_RCEC_EPA_EXT_CAP_HDR_CAP_VER_SHIFT)) & ieprc_pci_PCIE_CFC_RCEC_EPA_EXT_CAP_HDR_CAP_VER_MASK)

#define ieprc_pci_PCIE_CFC_RCEC_EPA_EXT_CAP_HDR_NEXT_CAP_OFF_MASK (0xFFF00000U)
#define ieprc_pci_PCIE_CFC_RCEC_EPA_EXT_CAP_HDR_NEXT_CAP_OFF_SHIFT (20U)
#define ieprc_pci_PCIE_CFC_RCEC_EPA_EXT_CAP_HDR_NEXT_CAP_OFF(x) (((uint32_t)(((uint32_t)(x)) << ieprc_pci_PCIE_CFC_RCEC_EPA_EXT_CAP_HDR_NEXT_CAP_OFF_SHIFT)) & ieprc_pci_PCIE_CFC_RCEC_EPA_EXT_CAP_HDR_NEXT_CAP_OFF_MASK)
/*! @} */

/*! @name PCIE_CFC_RCEC_EPA_BITMAP - PCIe RCEC Endpoint association bitmap register */
/*! @{ */

#define ieprc_pci_PCIE_CFC_RCEC_EPA_BITMAP_DEV_BITMAP_MASK (0xFFFFFFFFU)
#define ieprc_pci_PCIE_CFC_RCEC_EPA_BITMAP_DEV_BITMAP_SHIFT (0U)
#define ieprc_pci_PCIE_CFC_RCEC_EPA_BITMAP_DEV_BITMAP(x) (((uint32_t)(((uint32_t)(x)) << ieprc_pci_PCIE_CFC_RCEC_EPA_BITMAP_DEV_BITMAP_SHIFT)) & ieprc_pci_PCIE_CFC_RCEC_EPA_BITMAP_DEV_BITMAP_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group ieprc_pci_Register_Masks */


/*!
 * @}
 */ /* end of group ieprc_pci_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic pop
  #else
    #pragma pop
  #endif
#elif defined(__GNUC__)
  /* leave anonymous unions enabled */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=default
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* ieprc_pci_H_ */

