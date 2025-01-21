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
**         CMSIS Peripheral Access Layer for ENETC_PCI_TYPE0
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
 * @file ENETC_PCI_TYPE0.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for ENETC_PCI_TYPE0
 *
 * CMSIS Peripheral Access Layer for ENETC_PCI_TYPE0
 */

#if !defined(ENETC_PCI_TYPE0_H_)
#define ENETC_PCI_TYPE0_H_                       /**< Symbol preventing repeated inclusion */

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
   -- ENETC_PCI_TYPE0 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ENETC_PCI_TYPE0_Peripheral_Access_Layer ENETC_PCI_TYPE0 Peripheral Access Layer
 * @{
 */

/** ENETC_PCI_TYPE0 - Size of Registers Arrays */
#define ENETC_PCI_TYPE0_NUM_EA_COUNT              3u
#define ENETC_PCI_TYPE0_NUM_VF_BARL_COUNT         6u

/** ENETC_PCI_TYPE0 - Register Layout Typedef */
typedef struct {
  __I  uint32_t PCI_CFH_DID_VID;                   /**< PCI device ID and vendor ID register, offset: 0x0 */
  __IO uint16_t PCI_CFH_CMD;                       /**< PCI command register, offset: 0x4 */
  __I  uint16_t PCI_CFH_STAT;                      /**< PCI status register, offset: 0x6 */
  __I  uint32_t PCI_CFH_REVID_CLASSCODE;           /**< PCI revision ID and classcode register, offset: 0x8 */
  __IO uint8_t PCI_CFH_CL_SIZE;                    /**< PCI cache line size register, offset: 0xC */
       uint8_t RESERVED_0[1];
  __I  uint8_t PCI_CFH_HDR_TYPE;                   /**< PCI header type register, offset: 0xE */
       uint8_t RESERVED_1[1];
  __I  uint32_t PCI_CFH_BAR0;                      /**< PCI base address register 0, offset: 0x10 */
  __I  uint32_t PCI_CFH_BAR1;                      /**< PCI base address register 1, offset: 0x14 */
  __I  uint32_t PCI_CFH_BAR2;                      /**< PCI base address register 2, offset: 0x18 */
  __I  uint32_t PCI_CFH_BAR3;                      /**< PCI base address register 3, offset: 0x1C */
  __I  uint32_t PCI_CFH_BAR4;                      /**< PCI base address register 4, offset: 0x20 */
  __I  uint32_t PCI_CFH_BAR5;                      /**< PCI base address register 5, offset: 0x24 */
       uint8_t RESERVED_2[4];
  __I  uint16_t PCI_CFH_SUBSYS_VID;                /**< PCI subsystem vendor ID register, offset: 0x2C */
  __I  uint16_t PCI_CFH_SUBSYS_ID;                 /**< PCI subsystem ID register, offset: 0x2E */
       uint8_t RESERVED_3[4];
  __I  uint8_t PCI_CFH_CAP_PTR;                    /**< PCI capabilities pointer register, offset: 0x34 */
       uint8_t RESERVED_4[11];
  __I  uint16_t PCI_CFC_PCIE_CAP_LIST;             /**< PCI PCIe capabilities list register, offset: 0x40 */
  __I  uint16_t PCI_CFC_PCIE_CAP;                  /**< PCI PCIe capabilities register, offset: 0x42 */
  __I  uint32_t PCI_CFC_PCIE_DEV_CAP;              /**< PCI PCIe device capabilities register, offset: 0x44 */
  __IO uint16_t PCI_CFC_PCIE_DEV_CTL;              /**< PCI PCIe device control register, offset: 0x48 */
  __I  uint16_t PCI_CFC_PCIE_DEV_STAT;             /**< PCI PCIe device status register, offset: 0x4A */
       uint8_t RESERVED_5[24];
  __I  uint32_t PCI_CFC_PCIE_DEV_CAP2;             /**< PCI PCIe device capabilities 2 register, offset: 0x64 */
  __I  uint16_t PCI_CFC_PCIE_DEV_CTL2;             /**< PCI PCIe device control 2 register, offset: 0x68 */
       uint8_t RESERVED_6[22];
  __I  uint16_t PCI_CFC_MSIX_CAP_LIST;             /**< PCI MSI-X capabilities list register, offset: 0x80 */
  __IO uint16_t PCI_CFC_MSIX_MSG_CTL;              /**< PCI MSI-X message control register, offset: 0x82 */
  __I  uint32_t PCI_CFC_MSIX_TABLE_OFF_BIR;        /**< PCI MSI-X table offset/BIR register, offset: 0x84 */
  __I  uint32_t PCI_CFC_MSIX_PBA_OFF_BIR;          /**< PCI MSI-X PBA offset/BIR register, offset: 0x88 */
       uint8_t RESERVED_7[4];
  __I  uint16_t PCI_CFC_PCIPM_CAP_LIST;            /**< PCI PCI-PM capabilities list register, offset: 0x90 */
  __I  uint16_t PCI_CFC_PCIPM_CAP;                 /**< PCI PCI-PM capabilities register, offset: 0x92 */
  __IO uint16_t PCI_CFC_PCIPM_CTL_STAT;            /**< PCI PCI-PM control and status register, offset: 0x94 */
       uint8_t RESERVED_8[1];
       uint8_t PCI_CFC_PCIPM_DATA;                 /**< PCI PCI-PM capabilities data register, offset: 0x97 */
       uint8_t RESERVED_9[4];
  __I  uint16_t PCI_CFC_EA_CAP_LIST;               /**< PCI EA capabilities list register, offset: 0x9C */
  __I  uint16_t PCI_CFC_EA_CAP;                    /**< PCI EA capabilities register, offset: 0x9E */
  struct {                                         /* offset: 0xA0, array step: 0x10 */
    __I  uint32_t PCI_CFC_EA_PE_FMT;                 /**< PCI EA per-entry 0 format register..PCI EA per-entry 2 format register, array offset: 0xA0, array step: 0x10, irregular array, not all indices are valid */
    __I  uint32_t PCI_CFC_EA_PE_BASE;                /**< PCI EA per-entry 0 base register..PCI EA per-entry 2 base register, array offset: 0xA4, array step: 0x10, irregular array, not all indices are valid */
    __I  uint32_t PCI_CFC_EA_PE_MAXOFF;              /**< PCI EA per-entry 0 max offset register..PCI EA per-entry 2 max offset register, array offset: 0xA8, array step: 0x10, irregular array, not all indices are valid */
    __I  uint32_t PCI_CFC_EA_PE_EXT_BASE;            /**< PCI EA per-entry 0 extended base register..PCI EA per-entry 2 extended base register, array offset: 0xAC, array step: 0x10, irregular array, not all indices are valid */
  } NUM_EA[ENETC_PCI_TYPE0_NUM_EA_COUNT];
       uint8_t RESERVED_10[48];
  __I  uint32_t PCIE_CFC_AER_EXT_CAP_HDR;          /**< PCIe AER extended capability header, offset: 0x100 */
  __IO uint32_t PCIE_CFC_AER_UCORR_ERR_STAT;       /**< PCIe AER uncorrectable error status register, offset: 0x104 */
  __IO uint32_t PCIE_CFC_AER_UCORR_ERR_MASK;       /**< PCIe AER uncorrectable error mask register, offset: 0x108 */
  __IO uint32_t PCIE_CFC_AER_UCORR_ERR_SEV;        /**< PCIe AER uncorrectable error severity register, offset: 0x10C */
  __IO uint32_t PCIE_CFC_AER_CORR_ERR_STAT;        /**< PCIe AER correctable error status register, offset: 0x110 */
  __IO uint32_t PCIE_CFC_AER_CORR_ERR_MASK;        /**< PCIe AER correctable error mask register, offset: 0x114 */
  __I  uint32_t PCIE_CFC_AER_CAP_CTL;              /**< PCIe AER capabilities and control register, offset: 0x118 */
       uint8_t RESERVED_11[20];
  __I  uint32_t PCIE_CFC_ACS_CAP_HDR;              /**< PCIe ACS capability header, offset: 0x130 */
  __I  uint16_t PCIE_CFC_ACS_CAP;                  /**< PCIe ACS capability register, offset: 0x134 */
  __I  uint16_t PCIE_CFC_ACS_CTL;                  /**< PCIe ACS control register, offset: 0x136 */
       uint8_t RESERVED_12[8];
  __I  uint32_t PCIE_CFC_RTR_CAP_HDR;              /**< PCIe readiness time reporting capability header, offset: 0x140 */
  __I  uint32_t PCIE_CFC_RTR_RTR1;                 /**< PCIe RTR readiness time reporting 1 register, offset: 0x144 */
  __I  uint32_t PCIE_CFC_RTR_RTR2;                 /**< PCIe RTR readiness time reporting 2 register, offset: 0x148 */
       uint8_t RESERVED_13[4];
  __I  uint32_t PCIE_CFC_SRIOV_CAP_HDR;            /**< PCIe SR-IOV capability header, offset: 0x150, not available in all instances (available on 42 out of 70) */
  __I  uint32_t PCIE_CFC_SRIOV_CAP;                /**< PCIe SR-IOV capability register, offset: 0x154, not available in all instances (available on 42 out of 70) */
  __IO uint16_t PCIE_CFC_SRIOV_CTL;                /**< PCIe SR-IOV control register, offset: 0x158, not available in all instances (available on 42 out of 70) */
  __I  uint16_t PCIE_CFC_SRIOV_STAT;               /**< PCIe SR-IOV status register, offset: 0x15A, not available in all instances (available on 42 out of 70) */
  __I  uint16_t PCIE_CFC_SRIOV_INIT_VFS;           /**< PCIe SR-IOV initial VFs register, offset: 0x15C, not available in all instances (available on 42 out of 70) */
  __I  uint16_t PCIE_CFC_SRIOV_TOTAL_VFS;          /**< PCIe SR-IOV total VFs register, offset: 0x15E, not available in all instances (available on 42 out of 70) */
  __IO uint16_t PCIE_CFC_SRIOV_NUM_VFS;            /**< PCIe SR-IOV num VFs register, offset: 0x160, not available in all instances (available on 42 out of 70) */
  __I  uint16_t PCIE_CFC_SRIOV_FUNC_DEP_LIST;      /**< PCIe SR-IOV function dependency list register, offset: 0x162, not available in all instances (available on 42 out of 70) */
  __I  uint16_t PCIE_CFC_SRIOV_FIRST_VF_OFF;       /**< PCIe SR-IOV first VF offset register, offset: 0x164, not available in all instances (available on 42 out of 70) */
  __I  uint16_t PCIE_CFC_SRIOV_VF_STRIDE;          /**< PCIe SR-IOV VF stride register, offset: 0x166, not available in all instances (available on 42 out of 70) */
       uint8_t RESERVED_14[2];
  __I  uint16_t PCIE_CFC_SRIOV_VF_DEV_ID;          /**< PCIe SR-IOV VF device ID register, offset: 0x16A, not available in all instances (available on 42 out of 70) */
  __I  uint32_t PCIE_CFC_SRIOV_SUP_PAGE_SIZES;     /**< PCIe SR-IOV supported page sizes ID register, offset: 0x16C, not available in all instances (available on 42 out of 70) */
  __I  uint32_t PCIE_CFC_SRIOV_SYS_PAGE_SIZE;      /**< PCIe SR-IOV system page size ID register, offset: 0x170, not available in all instances (available on 42 out of 70) */
  __I  uint32_t PCIE_CFC_VF_BAR[ENETC_PCI_TYPE0_NUM_VF_BARL_COUNT]; /**< PCIe SR-IOV VF base address register 0..PCIe SR-IOV VF base address register 5, array offset: 0x174, array step: 0x4, not available in all instances (available on 42 out of 70) */
  __I  uint32_t PCIE_CFC_SRIOV_VF_MIG_STATE_ARR_OFF; /**< PCIe SR-IOV VF migration state array offset register, offset: 0x18C, not available in all instances (available on 42 out of 70) */
} ENETC_PCI_TYPE0_Type;

/* ----------------------------------------------------------------------------
   -- ENETC_PCI_TYPE0 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ENETC_PCI_TYPE0_Register_Masks ENETC_PCI_TYPE0 Register Masks
 * @{
 */

/*! @name PCI_CFH_DID_VID - PCI device ID and vendor ID register */
/*! @{ */

#define ENETC_PCI_TYPE0_PCI_CFH_DID_VID_VENDOR_ID_MASK (0xFFFFU)
#define ENETC_PCI_TYPE0_PCI_CFH_DID_VID_VENDOR_ID_SHIFT (0U)
#define ENETC_PCI_TYPE0_PCI_CFH_DID_VID_VENDOR_ID(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PCI_TYPE0_PCI_CFH_DID_VID_VENDOR_ID_SHIFT)) & ENETC_PCI_TYPE0_PCI_CFH_DID_VID_VENDOR_ID_MASK)

#define ENETC_PCI_TYPE0_PCI_CFH_DID_VID_DEVICE_ID_MASK (0xFFFF0000U)
#define ENETC_PCI_TYPE0_PCI_CFH_DID_VID_DEVICE_ID_SHIFT (16U)
#define ENETC_PCI_TYPE0_PCI_CFH_DID_VID_DEVICE_ID(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PCI_TYPE0_PCI_CFH_DID_VID_DEVICE_ID_SHIFT)) & ENETC_PCI_TYPE0_PCI_CFH_DID_VID_DEVICE_ID_MASK)
/*! @} */

/*! @name PCI_CFH_CMD - PCI command register */
/*! @{ */

#define ENETC_PCI_TYPE0_PCI_CFH_CMD_MEM_ACCESS_MASK (0x2U)
#define ENETC_PCI_TYPE0_PCI_CFH_CMD_MEM_ACCESS_SHIFT (1U)
#define ENETC_PCI_TYPE0_PCI_CFH_CMD_MEM_ACCESS(x) (((uint16_t)(((uint16_t)(x)) << ENETC_PCI_TYPE0_PCI_CFH_CMD_MEM_ACCESS_SHIFT)) & ENETC_PCI_TYPE0_PCI_CFH_CMD_MEM_ACCESS_MASK)

#define ENETC_PCI_TYPE0_PCI_CFH_CMD_BUS_MASTER_EN_MASK (0x4U)
#define ENETC_PCI_TYPE0_PCI_CFH_CMD_BUS_MASTER_EN_SHIFT (2U)
#define ENETC_PCI_TYPE0_PCI_CFH_CMD_BUS_MASTER_EN(x) (((uint16_t)(((uint16_t)(x)) << ENETC_PCI_TYPE0_PCI_CFH_CMD_BUS_MASTER_EN_SHIFT)) & ENETC_PCI_TYPE0_PCI_CFH_CMD_BUS_MASTER_EN_MASK)
/*! @} */

/*! @name PCI_CFH_STAT - PCI status register */
/*! @{ */

#define ENETC_PCI_TYPE0_PCI_CFH_STAT_CAP_LIST_MASK (0x10U)
#define ENETC_PCI_TYPE0_PCI_CFH_STAT_CAP_LIST_SHIFT (4U)
#define ENETC_PCI_TYPE0_PCI_CFH_STAT_CAP_LIST(x) (((uint16_t)(((uint16_t)(x)) << ENETC_PCI_TYPE0_PCI_CFH_STAT_CAP_LIST_SHIFT)) & ENETC_PCI_TYPE0_PCI_CFH_STAT_CAP_LIST_MASK)
/*! @} */

/*! @name PCI_CFH_REVID_CLASSCODE - PCI revision ID and classcode register */
/*! @{ */

#define ENETC_PCI_TYPE0_PCI_CFH_REVID_CLASSCODE_REV_ID_MASK (0xFFU)
#define ENETC_PCI_TYPE0_PCI_CFH_REVID_CLASSCODE_REV_ID_SHIFT (0U)
#define ENETC_PCI_TYPE0_PCI_CFH_REVID_CLASSCODE_REV_ID(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PCI_TYPE0_PCI_CFH_REVID_CLASSCODE_REV_ID_SHIFT)) & ENETC_PCI_TYPE0_PCI_CFH_REVID_CLASSCODE_REV_ID_MASK)

#define ENETC_PCI_TYPE0_PCI_CFH_REVID_CLASSCODE_CLASS_CODE_MASK (0xFFFFFF00U)
#define ENETC_PCI_TYPE0_PCI_CFH_REVID_CLASSCODE_CLASS_CODE_SHIFT (8U)
#define ENETC_PCI_TYPE0_PCI_CFH_REVID_CLASSCODE_CLASS_CODE(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PCI_TYPE0_PCI_CFH_REVID_CLASSCODE_CLASS_CODE_SHIFT)) & ENETC_PCI_TYPE0_PCI_CFH_REVID_CLASSCODE_CLASS_CODE_MASK)
/*! @} */

/*! @name PCI_CFH_CL_SIZE - PCI cache line size register */
/*! @{ */

#define ENETC_PCI_TYPE0_PCI_CFH_CL_SIZE_CACHE_LINE_SIZE_MASK (0xFFU)
#define ENETC_PCI_TYPE0_PCI_CFH_CL_SIZE_CACHE_LINE_SIZE_SHIFT (0U)
#define ENETC_PCI_TYPE0_PCI_CFH_CL_SIZE_CACHE_LINE_SIZE(x) (((uint8_t)(((uint8_t)(x)) << ENETC_PCI_TYPE0_PCI_CFH_CL_SIZE_CACHE_LINE_SIZE_SHIFT)) & ENETC_PCI_TYPE0_PCI_CFH_CL_SIZE_CACHE_LINE_SIZE_MASK)
/*! @} */

/*! @name PCI_CFH_HDR_TYPE - PCI header type register */
/*! @{ */

#define ENETC_PCI_TYPE0_PCI_CFH_HDR_TYPE_HDR_TYPE_MASK (0x7FU)
#define ENETC_PCI_TYPE0_PCI_CFH_HDR_TYPE_HDR_TYPE_SHIFT (0U)
#define ENETC_PCI_TYPE0_PCI_CFH_HDR_TYPE_HDR_TYPE(x) (((uint8_t)(((uint8_t)(x)) << ENETC_PCI_TYPE0_PCI_CFH_HDR_TYPE_HDR_TYPE_SHIFT)) & ENETC_PCI_TYPE0_PCI_CFH_HDR_TYPE_HDR_TYPE_MASK)

#define ENETC_PCI_TYPE0_PCI_CFH_HDR_TYPE_MULT_FUNC_DEV_MASK (0x80U)
#define ENETC_PCI_TYPE0_PCI_CFH_HDR_TYPE_MULT_FUNC_DEV_SHIFT (7U)
#define ENETC_PCI_TYPE0_PCI_CFH_HDR_TYPE_MULT_FUNC_DEV(x) (((uint8_t)(((uint8_t)(x)) << ENETC_PCI_TYPE0_PCI_CFH_HDR_TYPE_MULT_FUNC_DEV_SHIFT)) & ENETC_PCI_TYPE0_PCI_CFH_HDR_TYPE_MULT_FUNC_DEV_MASK)
/*! @} */

/*! @name PCI_CFH_BAR0 - PCI base address register 0 */
/*! @{ */

#define ENETC_PCI_TYPE0_PCI_CFH_BAR0_MEM_IO_IND_MASK (0x1U)
#define ENETC_PCI_TYPE0_PCI_CFH_BAR0_MEM_IO_IND_SHIFT (0U)
#define ENETC_PCI_TYPE0_PCI_CFH_BAR0_MEM_IO_IND(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PCI_TYPE0_PCI_CFH_BAR0_MEM_IO_IND_SHIFT)) & ENETC_PCI_TYPE0_PCI_CFH_BAR0_MEM_IO_IND_MASK)

#define ENETC_PCI_TYPE0_PCI_CFH_BAR0_MEM_TYPE_MASK (0x6U)
#define ENETC_PCI_TYPE0_PCI_CFH_BAR0_MEM_TYPE_SHIFT (1U)
#define ENETC_PCI_TYPE0_PCI_CFH_BAR0_MEM_TYPE(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PCI_TYPE0_PCI_CFH_BAR0_MEM_TYPE_SHIFT)) & ENETC_PCI_TYPE0_PCI_CFH_BAR0_MEM_TYPE_MASK)

#define ENETC_PCI_TYPE0_PCI_CFH_BAR0_PF_MEM_MASK (0x8U)
#define ENETC_PCI_TYPE0_PCI_CFH_BAR0_PF_MEM_SHIFT (3U)
#define ENETC_PCI_TYPE0_PCI_CFH_BAR0_PF_MEM(x)   (((uint32_t)(((uint32_t)(x)) << ENETC_PCI_TYPE0_PCI_CFH_BAR0_PF_MEM_SHIFT)) & ENETC_PCI_TYPE0_PCI_CFH_BAR0_PF_MEM_MASK)

#define ENETC_PCI_TYPE0_PCI_CFH_BAR0_ADDR_MASK   (0xFFFFFFF0U)
#define ENETC_PCI_TYPE0_PCI_CFH_BAR0_ADDR_SHIFT  (4U)
#define ENETC_PCI_TYPE0_PCI_CFH_BAR0_ADDR(x)     (((uint32_t)(((uint32_t)(x)) << ENETC_PCI_TYPE0_PCI_CFH_BAR0_ADDR_SHIFT)) & ENETC_PCI_TYPE0_PCI_CFH_BAR0_ADDR_MASK)
/*! @} */

/*! @name PCI_CFH_BAR1 - PCI base address register 1 */
/*! @{ */

#define ENETC_PCI_TYPE0_PCI_CFH_BAR1_MEM_IO_IND_MASK (0x1U)
#define ENETC_PCI_TYPE0_PCI_CFH_BAR1_MEM_IO_IND_SHIFT (0U)
#define ENETC_PCI_TYPE0_PCI_CFH_BAR1_MEM_IO_IND(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PCI_TYPE0_PCI_CFH_BAR1_MEM_IO_IND_SHIFT)) & ENETC_PCI_TYPE0_PCI_CFH_BAR1_MEM_IO_IND_MASK)

#define ENETC_PCI_TYPE0_PCI_CFH_BAR1_MEM_TYPE_MASK (0x6U)
#define ENETC_PCI_TYPE0_PCI_CFH_BAR1_MEM_TYPE_SHIFT (1U)
#define ENETC_PCI_TYPE0_PCI_CFH_BAR1_MEM_TYPE(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PCI_TYPE0_PCI_CFH_BAR1_MEM_TYPE_SHIFT)) & ENETC_PCI_TYPE0_PCI_CFH_BAR1_MEM_TYPE_MASK)

#define ENETC_PCI_TYPE0_PCI_CFH_BAR1_PF_MEM_MASK (0x8U)
#define ENETC_PCI_TYPE0_PCI_CFH_BAR1_PF_MEM_SHIFT (3U)
#define ENETC_PCI_TYPE0_PCI_CFH_BAR1_PF_MEM(x)   (((uint32_t)(((uint32_t)(x)) << ENETC_PCI_TYPE0_PCI_CFH_BAR1_PF_MEM_SHIFT)) & ENETC_PCI_TYPE0_PCI_CFH_BAR1_PF_MEM_MASK)

#define ENETC_PCI_TYPE0_PCI_CFH_BAR1_ADDR_MASK   (0xFFFFFFF0U)
#define ENETC_PCI_TYPE0_PCI_CFH_BAR1_ADDR_SHIFT  (4U)
#define ENETC_PCI_TYPE0_PCI_CFH_BAR1_ADDR(x)     (((uint32_t)(((uint32_t)(x)) << ENETC_PCI_TYPE0_PCI_CFH_BAR1_ADDR_SHIFT)) & ENETC_PCI_TYPE0_PCI_CFH_BAR1_ADDR_MASK)
/*! @} */

/*! @name PCI_CFH_BAR2 - PCI base address register 2 */
/*! @{ */

#define ENETC_PCI_TYPE0_PCI_CFH_BAR2_MEM_IO_IND_MASK (0x1U)
#define ENETC_PCI_TYPE0_PCI_CFH_BAR2_MEM_IO_IND_SHIFT (0U)
#define ENETC_PCI_TYPE0_PCI_CFH_BAR2_MEM_IO_IND(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PCI_TYPE0_PCI_CFH_BAR2_MEM_IO_IND_SHIFT)) & ENETC_PCI_TYPE0_PCI_CFH_BAR2_MEM_IO_IND_MASK)

#define ENETC_PCI_TYPE0_PCI_CFH_BAR2_MEM_TYPE_MASK (0x6U)
#define ENETC_PCI_TYPE0_PCI_CFH_BAR2_MEM_TYPE_SHIFT (1U)
#define ENETC_PCI_TYPE0_PCI_CFH_BAR2_MEM_TYPE(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PCI_TYPE0_PCI_CFH_BAR2_MEM_TYPE_SHIFT)) & ENETC_PCI_TYPE0_PCI_CFH_BAR2_MEM_TYPE_MASK)

#define ENETC_PCI_TYPE0_PCI_CFH_BAR2_PF_MEM_MASK (0x8U)
#define ENETC_PCI_TYPE0_PCI_CFH_BAR2_PF_MEM_SHIFT (3U)
#define ENETC_PCI_TYPE0_PCI_CFH_BAR2_PF_MEM(x)   (((uint32_t)(((uint32_t)(x)) << ENETC_PCI_TYPE0_PCI_CFH_BAR2_PF_MEM_SHIFT)) & ENETC_PCI_TYPE0_PCI_CFH_BAR2_PF_MEM_MASK)

#define ENETC_PCI_TYPE0_PCI_CFH_BAR2_ADDR_MASK   (0xFFFFFFF0U)
#define ENETC_PCI_TYPE0_PCI_CFH_BAR2_ADDR_SHIFT  (4U)
#define ENETC_PCI_TYPE0_PCI_CFH_BAR2_ADDR(x)     (((uint32_t)(((uint32_t)(x)) << ENETC_PCI_TYPE0_PCI_CFH_BAR2_ADDR_SHIFT)) & ENETC_PCI_TYPE0_PCI_CFH_BAR2_ADDR_MASK)
/*! @} */

/*! @name PCI_CFH_BAR3 - PCI base address register 3 */
/*! @{ */

#define ENETC_PCI_TYPE0_PCI_CFH_BAR3_MEM_IO_IND_MASK (0x1U)
#define ENETC_PCI_TYPE0_PCI_CFH_BAR3_MEM_IO_IND_SHIFT (0U)
#define ENETC_PCI_TYPE0_PCI_CFH_BAR3_MEM_IO_IND(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PCI_TYPE0_PCI_CFH_BAR3_MEM_IO_IND_SHIFT)) & ENETC_PCI_TYPE0_PCI_CFH_BAR3_MEM_IO_IND_MASK)

#define ENETC_PCI_TYPE0_PCI_CFH_BAR3_MEM_TYPE_MASK (0x6U)
#define ENETC_PCI_TYPE0_PCI_CFH_BAR3_MEM_TYPE_SHIFT (1U)
#define ENETC_PCI_TYPE0_PCI_CFH_BAR3_MEM_TYPE(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PCI_TYPE0_PCI_CFH_BAR3_MEM_TYPE_SHIFT)) & ENETC_PCI_TYPE0_PCI_CFH_BAR3_MEM_TYPE_MASK)

#define ENETC_PCI_TYPE0_PCI_CFH_BAR3_PF_MEM_MASK (0x8U)
#define ENETC_PCI_TYPE0_PCI_CFH_BAR3_PF_MEM_SHIFT (3U)
#define ENETC_PCI_TYPE0_PCI_CFH_BAR3_PF_MEM(x)   (((uint32_t)(((uint32_t)(x)) << ENETC_PCI_TYPE0_PCI_CFH_BAR3_PF_MEM_SHIFT)) & ENETC_PCI_TYPE0_PCI_CFH_BAR3_PF_MEM_MASK)

#define ENETC_PCI_TYPE0_PCI_CFH_BAR3_ADDR_MASK   (0xFFFFFFF0U)
#define ENETC_PCI_TYPE0_PCI_CFH_BAR3_ADDR_SHIFT  (4U)
#define ENETC_PCI_TYPE0_PCI_CFH_BAR3_ADDR(x)     (((uint32_t)(((uint32_t)(x)) << ENETC_PCI_TYPE0_PCI_CFH_BAR3_ADDR_SHIFT)) & ENETC_PCI_TYPE0_PCI_CFH_BAR3_ADDR_MASK)
/*! @} */

/*! @name PCI_CFH_BAR4 - PCI base address register 4 */
/*! @{ */

#define ENETC_PCI_TYPE0_PCI_CFH_BAR4_MEM_IO_IND_MASK (0x1U)
#define ENETC_PCI_TYPE0_PCI_CFH_BAR4_MEM_IO_IND_SHIFT (0U)
#define ENETC_PCI_TYPE0_PCI_CFH_BAR4_MEM_IO_IND(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PCI_TYPE0_PCI_CFH_BAR4_MEM_IO_IND_SHIFT)) & ENETC_PCI_TYPE0_PCI_CFH_BAR4_MEM_IO_IND_MASK)

#define ENETC_PCI_TYPE0_PCI_CFH_BAR4_MEM_TYPE_MASK (0x6U)
#define ENETC_PCI_TYPE0_PCI_CFH_BAR4_MEM_TYPE_SHIFT (1U)
#define ENETC_PCI_TYPE0_PCI_CFH_BAR4_MEM_TYPE(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PCI_TYPE0_PCI_CFH_BAR4_MEM_TYPE_SHIFT)) & ENETC_PCI_TYPE0_PCI_CFH_BAR4_MEM_TYPE_MASK)

#define ENETC_PCI_TYPE0_PCI_CFH_BAR4_PF_MEM_MASK (0x8U)
#define ENETC_PCI_TYPE0_PCI_CFH_BAR4_PF_MEM_SHIFT (3U)
#define ENETC_PCI_TYPE0_PCI_CFH_BAR4_PF_MEM(x)   (((uint32_t)(((uint32_t)(x)) << ENETC_PCI_TYPE0_PCI_CFH_BAR4_PF_MEM_SHIFT)) & ENETC_PCI_TYPE0_PCI_CFH_BAR4_PF_MEM_MASK)

#define ENETC_PCI_TYPE0_PCI_CFH_BAR4_ADDR_MASK   (0xFFFFFFF0U)
#define ENETC_PCI_TYPE0_PCI_CFH_BAR4_ADDR_SHIFT  (4U)
#define ENETC_PCI_TYPE0_PCI_CFH_BAR4_ADDR(x)     (((uint32_t)(((uint32_t)(x)) << ENETC_PCI_TYPE0_PCI_CFH_BAR4_ADDR_SHIFT)) & ENETC_PCI_TYPE0_PCI_CFH_BAR4_ADDR_MASK)
/*! @} */

/*! @name PCI_CFH_BAR5 - PCI base address register 5 */
/*! @{ */

#define ENETC_PCI_TYPE0_PCI_CFH_BAR5_MEM_IO_IND_MASK (0x1U)
#define ENETC_PCI_TYPE0_PCI_CFH_BAR5_MEM_IO_IND_SHIFT (0U)
#define ENETC_PCI_TYPE0_PCI_CFH_BAR5_MEM_IO_IND(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PCI_TYPE0_PCI_CFH_BAR5_MEM_IO_IND_SHIFT)) & ENETC_PCI_TYPE0_PCI_CFH_BAR5_MEM_IO_IND_MASK)

#define ENETC_PCI_TYPE0_PCI_CFH_BAR5_MEM_TYPE_MASK (0x6U)
#define ENETC_PCI_TYPE0_PCI_CFH_BAR5_MEM_TYPE_SHIFT (1U)
#define ENETC_PCI_TYPE0_PCI_CFH_BAR5_MEM_TYPE(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PCI_TYPE0_PCI_CFH_BAR5_MEM_TYPE_SHIFT)) & ENETC_PCI_TYPE0_PCI_CFH_BAR5_MEM_TYPE_MASK)

#define ENETC_PCI_TYPE0_PCI_CFH_BAR5_PF_MEM_MASK (0x8U)
#define ENETC_PCI_TYPE0_PCI_CFH_BAR5_PF_MEM_SHIFT (3U)
#define ENETC_PCI_TYPE0_PCI_CFH_BAR5_PF_MEM(x)   (((uint32_t)(((uint32_t)(x)) << ENETC_PCI_TYPE0_PCI_CFH_BAR5_PF_MEM_SHIFT)) & ENETC_PCI_TYPE0_PCI_CFH_BAR5_PF_MEM_MASK)

#define ENETC_PCI_TYPE0_PCI_CFH_BAR5_ADDR_MASK   (0xFFFFFFF0U)
#define ENETC_PCI_TYPE0_PCI_CFH_BAR5_ADDR_SHIFT  (4U)
#define ENETC_PCI_TYPE0_PCI_CFH_BAR5_ADDR(x)     (((uint32_t)(((uint32_t)(x)) << ENETC_PCI_TYPE0_PCI_CFH_BAR5_ADDR_SHIFT)) & ENETC_PCI_TYPE0_PCI_CFH_BAR5_ADDR_MASK)
/*! @} */

/*! @name PCI_CFH_SUBSYS_VID - PCI subsystem vendor ID register */
/*! @{ */

#define ENETC_PCI_TYPE0_PCI_CFH_SUBSYS_VID_SUBSYSTEM_VENDOR_ID_MASK (0xFFFFU)
#define ENETC_PCI_TYPE0_PCI_CFH_SUBSYS_VID_SUBSYSTEM_VENDOR_ID_SHIFT (0U)
#define ENETC_PCI_TYPE0_PCI_CFH_SUBSYS_VID_SUBSYSTEM_VENDOR_ID(x) (((uint16_t)(((uint16_t)(x)) << ENETC_PCI_TYPE0_PCI_CFH_SUBSYS_VID_SUBSYSTEM_VENDOR_ID_SHIFT)) & ENETC_PCI_TYPE0_PCI_CFH_SUBSYS_VID_SUBSYSTEM_VENDOR_ID_MASK)
/*! @} */

/*! @name PCI_CFH_SUBSYS_ID - PCI subsystem ID register */
/*! @{ */

#define ENETC_PCI_TYPE0_PCI_CFH_SUBSYS_ID_SUBSYSTEM_ID_MASK (0xFFFFU)
#define ENETC_PCI_TYPE0_PCI_CFH_SUBSYS_ID_SUBSYSTEM_ID_SHIFT (0U)
#define ENETC_PCI_TYPE0_PCI_CFH_SUBSYS_ID_SUBSYSTEM_ID(x) (((uint16_t)(((uint16_t)(x)) << ENETC_PCI_TYPE0_PCI_CFH_SUBSYS_ID_SUBSYSTEM_ID_SHIFT)) & ENETC_PCI_TYPE0_PCI_CFH_SUBSYS_ID_SUBSYSTEM_ID_MASK)
/*! @} */

/*! @name PCI_CFH_CAP_PTR - PCI capabilities pointer register */
/*! @{ */

#define ENETC_PCI_TYPE0_PCI_CFH_CAP_PTR_CAP_PTR_MASK (0xFFU)
#define ENETC_PCI_TYPE0_PCI_CFH_CAP_PTR_CAP_PTR_SHIFT (0U)
#define ENETC_PCI_TYPE0_PCI_CFH_CAP_PTR_CAP_PTR(x) (((uint8_t)(((uint8_t)(x)) << ENETC_PCI_TYPE0_PCI_CFH_CAP_PTR_CAP_PTR_SHIFT)) & ENETC_PCI_TYPE0_PCI_CFH_CAP_PTR_CAP_PTR_MASK)
/*! @} */

/*! @name PCI_CFC_PCIE_CAP_LIST - PCI PCIe capabilities list register */
/*! @{ */

#define ENETC_PCI_TYPE0_PCI_CFC_PCIE_CAP_LIST_CAP_ID_MASK (0xFFU)
#define ENETC_PCI_TYPE0_PCI_CFC_PCIE_CAP_LIST_CAP_ID_SHIFT (0U)
#define ENETC_PCI_TYPE0_PCI_CFC_PCIE_CAP_LIST_CAP_ID(x) (((uint16_t)(((uint16_t)(x)) << ENETC_PCI_TYPE0_PCI_CFC_PCIE_CAP_LIST_CAP_ID_SHIFT)) & ENETC_PCI_TYPE0_PCI_CFC_PCIE_CAP_LIST_CAP_ID_MASK)

#define ENETC_PCI_TYPE0_PCI_CFC_PCIE_CAP_LIST_NEXT_CAP_PTR_MASK (0xFF00U)
#define ENETC_PCI_TYPE0_PCI_CFC_PCIE_CAP_LIST_NEXT_CAP_PTR_SHIFT (8U)
#define ENETC_PCI_TYPE0_PCI_CFC_PCIE_CAP_LIST_NEXT_CAP_PTR(x) (((uint16_t)(((uint16_t)(x)) << ENETC_PCI_TYPE0_PCI_CFC_PCIE_CAP_LIST_NEXT_CAP_PTR_SHIFT)) & ENETC_PCI_TYPE0_PCI_CFC_PCIE_CAP_LIST_NEXT_CAP_PTR_MASK)
/*! @} */

/*! @name PCI_CFC_PCIE_CAP - PCI PCIe capabilities register */
/*! @{ */

#define ENETC_PCI_TYPE0_PCI_CFC_PCIE_CAP_CAP_VER_MASK (0xFU)
#define ENETC_PCI_TYPE0_PCI_CFC_PCIE_CAP_CAP_VER_SHIFT (0U)
#define ENETC_PCI_TYPE0_PCI_CFC_PCIE_CAP_CAP_VER(x) (((uint16_t)(((uint16_t)(x)) << ENETC_PCI_TYPE0_PCI_CFC_PCIE_CAP_CAP_VER_SHIFT)) & ENETC_PCI_TYPE0_PCI_CFC_PCIE_CAP_CAP_VER_MASK)

#define ENETC_PCI_TYPE0_PCI_CFC_PCIE_CAP_DEV_PORT_TYPE_MASK (0xF0U)
#define ENETC_PCI_TYPE0_PCI_CFC_PCIE_CAP_DEV_PORT_TYPE_SHIFT (4U)
#define ENETC_PCI_TYPE0_PCI_CFC_PCIE_CAP_DEV_PORT_TYPE(x) (((uint16_t)(((uint16_t)(x)) << ENETC_PCI_TYPE0_PCI_CFC_PCIE_CAP_DEV_PORT_TYPE_SHIFT)) & ENETC_PCI_TYPE0_PCI_CFC_PCIE_CAP_DEV_PORT_TYPE_MASK)

#define ENETC_PCI_TYPE0_PCI_CFC_PCIE_CAP_INT_MSG_NUM_MASK (0x3E00U)
#define ENETC_PCI_TYPE0_PCI_CFC_PCIE_CAP_INT_MSG_NUM_SHIFT (9U)
#define ENETC_PCI_TYPE0_PCI_CFC_PCIE_CAP_INT_MSG_NUM(x) (((uint16_t)(((uint16_t)(x)) << ENETC_PCI_TYPE0_PCI_CFC_PCIE_CAP_INT_MSG_NUM_SHIFT)) & ENETC_PCI_TYPE0_PCI_CFC_PCIE_CAP_INT_MSG_NUM_MASK)
/*! @} */

/*! @name PCI_CFC_PCIE_DEV_CAP - PCI PCIe device capabilities register */
/*! @{ */

#define ENETC_PCI_TYPE0_PCI_CFC_PCIE_DEV_CAP_FLR_CAP_MASK (0x10000000U)
#define ENETC_PCI_TYPE0_PCI_CFC_PCIE_DEV_CAP_FLR_CAP_SHIFT (28U)
#define ENETC_PCI_TYPE0_PCI_CFC_PCIE_DEV_CAP_FLR_CAP(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PCI_TYPE0_PCI_CFC_PCIE_DEV_CAP_FLR_CAP_SHIFT)) & ENETC_PCI_TYPE0_PCI_CFC_PCIE_DEV_CAP_FLR_CAP_MASK)
/*! @} */

/*! @name PCI_CFC_PCIE_DEV_CTL - PCI PCIe device control register */
/*! @{ */

#define ENETC_PCI_TYPE0_PCI_CFC_PCIE_DEV_CTL_INIT_FLR_MASK (0x8000U)
#define ENETC_PCI_TYPE0_PCI_CFC_PCIE_DEV_CTL_INIT_FLR_SHIFT (15U)
#define ENETC_PCI_TYPE0_PCI_CFC_PCIE_DEV_CTL_INIT_FLR(x) (((uint16_t)(((uint16_t)(x)) << ENETC_PCI_TYPE0_PCI_CFC_PCIE_DEV_CTL_INIT_FLR_SHIFT)) & ENETC_PCI_TYPE0_PCI_CFC_PCIE_DEV_CTL_INIT_FLR_MASK)
/*! @} */

/*! @name PCI_CFC_PCIE_DEV_STAT - PCI PCIe device status register */
/*! @{ */

#define ENETC_PCI_TYPE0_PCI_CFC_PCIE_DEV_STAT_TRANS_PEND_MASK (0x20U)
#define ENETC_PCI_TYPE0_PCI_CFC_PCIE_DEV_STAT_TRANS_PEND_SHIFT (5U)
#define ENETC_PCI_TYPE0_PCI_CFC_PCIE_DEV_STAT_TRANS_PEND(x) (((uint16_t)(((uint16_t)(x)) << ENETC_PCI_TYPE0_PCI_CFC_PCIE_DEV_STAT_TRANS_PEND_SHIFT)) & ENETC_PCI_TYPE0_PCI_CFC_PCIE_DEV_STAT_TRANS_PEND_MASK)
/*! @} */

/*! @name PCI_CFC_PCIE_DEV_CAP2 - PCI PCIe device capabilities 2 register */
/*! @{ */

#define ENETC_PCI_TYPE0_PCI_CFC_PCIE_DEV_CAP2_CMPL_TO_RNG_SUPP_MASK (0xFU)
#define ENETC_PCI_TYPE0_PCI_CFC_PCIE_DEV_CAP2_CMPL_TO_RNG_SUPP_SHIFT (0U)
#define ENETC_PCI_TYPE0_PCI_CFC_PCIE_DEV_CAP2_CMPL_TO_RNG_SUPP(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PCI_TYPE0_PCI_CFC_PCIE_DEV_CAP2_CMPL_TO_RNG_SUPP_SHIFT)) & ENETC_PCI_TYPE0_PCI_CFC_PCIE_DEV_CAP2_CMPL_TO_RNG_SUPP_MASK)

#define ENETC_PCI_TYPE0_PCI_CFC_PCIE_DEV_CAP2_CMPL_TO_DIS_SUPP_MASK (0x10U)
#define ENETC_PCI_TYPE0_PCI_CFC_PCIE_DEV_CAP2_CMPL_TO_DIS_SUPP_SHIFT (4U)
#define ENETC_PCI_TYPE0_PCI_CFC_PCIE_DEV_CAP2_CMPL_TO_DIS_SUPP(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PCI_TYPE0_PCI_CFC_PCIE_DEV_CAP2_CMPL_TO_DIS_SUPP_SHIFT)) & ENETC_PCI_TYPE0_PCI_CFC_PCIE_DEV_CAP2_CMPL_TO_DIS_SUPP_MASK)
/*! @} */

/*! @name PCI_CFC_PCIE_DEV_CTL2 - PCI PCIe device control 2 register */
/*! @{ */

#define ENETC_PCI_TYPE0_PCI_CFC_PCIE_DEV_CTL2_CMPL_TO_VALUE_MASK (0xFU)
#define ENETC_PCI_TYPE0_PCI_CFC_PCIE_DEV_CTL2_CMPL_TO_VALUE_SHIFT (0U)
#define ENETC_PCI_TYPE0_PCI_CFC_PCIE_DEV_CTL2_CMPL_TO_VALUE(x) (((uint16_t)(((uint16_t)(x)) << ENETC_PCI_TYPE0_PCI_CFC_PCIE_DEV_CTL2_CMPL_TO_VALUE_SHIFT)) & ENETC_PCI_TYPE0_PCI_CFC_PCIE_DEV_CTL2_CMPL_TO_VALUE_MASK)

#define ENETC_PCI_TYPE0_PCI_CFC_PCIE_DEV_CTL2_CMPL_TO_EN_MASK (0x10U)
#define ENETC_PCI_TYPE0_PCI_CFC_PCIE_DEV_CTL2_CMPL_TO_EN_SHIFT (4U)
#define ENETC_PCI_TYPE0_PCI_CFC_PCIE_DEV_CTL2_CMPL_TO_EN(x) (((uint16_t)(((uint16_t)(x)) << ENETC_PCI_TYPE0_PCI_CFC_PCIE_DEV_CTL2_CMPL_TO_EN_SHIFT)) & ENETC_PCI_TYPE0_PCI_CFC_PCIE_DEV_CTL2_CMPL_TO_EN_MASK)
/*! @} */

/*! @name PCI_CFC_MSIX_CAP_LIST - PCI MSI-X capabilities list register */
/*! @{ */

#define ENETC_PCI_TYPE0_PCI_CFC_MSIX_CAP_LIST_CAP_ID_MASK (0xFFU)
#define ENETC_PCI_TYPE0_PCI_CFC_MSIX_CAP_LIST_CAP_ID_SHIFT (0U)
#define ENETC_PCI_TYPE0_PCI_CFC_MSIX_CAP_LIST_CAP_ID(x) (((uint16_t)(((uint16_t)(x)) << ENETC_PCI_TYPE0_PCI_CFC_MSIX_CAP_LIST_CAP_ID_SHIFT)) & ENETC_PCI_TYPE0_PCI_CFC_MSIX_CAP_LIST_CAP_ID_MASK)

#define ENETC_PCI_TYPE0_PCI_CFC_MSIX_CAP_LIST_NEXT_CAP_PTR_MASK (0xFF00U)
#define ENETC_PCI_TYPE0_PCI_CFC_MSIX_CAP_LIST_NEXT_CAP_PTR_SHIFT (8U)
#define ENETC_PCI_TYPE0_PCI_CFC_MSIX_CAP_LIST_NEXT_CAP_PTR(x) (((uint16_t)(((uint16_t)(x)) << ENETC_PCI_TYPE0_PCI_CFC_MSIX_CAP_LIST_NEXT_CAP_PTR_SHIFT)) & ENETC_PCI_TYPE0_PCI_CFC_MSIX_CAP_LIST_NEXT_CAP_PTR_MASK)
/*! @} */

/*! @name PCI_CFC_MSIX_MSG_CTL - PCI MSI-X message control register */
/*! @{ */

#define ENETC_PCI_TYPE0_PCI_CFC_MSIX_MSG_CTL_TABLE_SIZE_MASK (0x7FFU)
#define ENETC_PCI_TYPE0_PCI_CFC_MSIX_MSG_CTL_TABLE_SIZE_SHIFT (0U)
#define ENETC_PCI_TYPE0_PCI_CFC_MSIX_MSG_CTL_TABLE_SIZE(x) (((uint16_t)(((uint16_t)(x)) << ENETC_PCI_TYPE0_PCI_CFC_MSIX_MSG_CTL_TABLE_SIZE_SHIFT)) & ENETC_PCI_TYPE0_PCI_CFC_MSIX_MSG_CTL_TABLE_SIZE_MASK)

#define ENETC_PCI_TYPE0_PCI_CFC_MSIX_MSG_CTL_FUNC_MASK_MASK (0x4000U)
#define ENETC_PCI_TYPE0_PCI_CFC_MSIX_MSG_CTL_FUNC_MASK_SHIFT (14U)
#define ENETC_PCI_TYPE0_PCI_CFC_MSIX_MSG_CTL_FUNC_MASK(x) (((uint16_t)(((uint16_t)(x)) << ENETC_PCI_TYPE0_PCI_CFC_MSIX_MSG_CTL_FUNC_MASK_SHIFT)) & ENETC_PCI_TYPE0_PCI_CFC_MSIX_MSG_CTL_FUNC_MASK_MASK)

#define ENETC_PCI_TYPE0_PCI_CFC_MSIX_MSG_CTL_MSIX_EN_MASK (0x8000U)
#define ENETC_PCI_TYPE0_PCI_CFC_MSIX_MSG_CTL_MSIX_EN_SHIFT (15U)
#define ENETC_PCI_TYPE0_PCI_CFC_MSIX_MSG_CTL_MSIX_EN(x) (((uint16_t)(((uint16_t)(x)) << ENETC_PCI_TYPE0_PCI_CFC_MSIX_MSG_CTL_MSIX_EN_SHIFT)) & ENETC_PCI_TYPE0_PCI_CFC_MSIX_MSG_CTL_MSIX_EN_MASK)
/*! @} */

/*! @name PCI_CFC_MSIX_TABLE_OFF_BIR - PCI MSI-X table offset/BIR register */
/*! @{ */

#define ENETC_PCI_TYPE0_PCI_CFC_MSIX_TABLE_OFF_BIR_TABLE_BIR_MASK (0x7U)
#define ENETC_PCI_TYPE0_PCI_CFC_MSIX_TABLE_OFF_BIR_TABLE_BIR_SHIFT (0U)
#define ENETC_PCI_TYPE0_PCI_CFC_MSIX_TABLE_OFF_BIR_TABLE_BIR(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PCI_TYPE0_PCI_CFC_MSIX_TABLE_OFF_BIR_TABLE_BIR_SHIFT)) & ENETC_PCI_TYPE0_PCI_CFC_MSIX_TABLE_OFF_BIR_TABLE_BIR_MASK)

#define ENETC_PCI_TYPE0_PCI_CFC_MSIX_TABLE_OFF_BIR_TABLE_OFFSET_MASK (0xFFFFFFF8U)
#define ENETC_PCI_TYPE0_PCI_CFC_MSIX_TABLE_OFF_BIR_TABLE_OFFSET_SHIFT (3U)
#define ENETC_PCI_TYPE0_PCI_CFC_MSIX_TABLE_OFF_BIR_TABLE_OFFSET(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PCI_TYPE0_PCI_CFC_MSIX_TABLE_OFF_BIR_TABLE_OFFSET_SHIFT)) & ENETC_PCI_TYPE0_PCI_CFC_MSIX_TABLE_OFF_BIR_TABLE_OFFSET_MASK)
/*! @} */

/*! @name PCI_CFC_MSIX_PBA_OFF_BIR - PCI MSI-X PBA offset/BIR register */
/*! @{ */

#define ENETC_PCI_TYPE0_PCI_CFC_MSIX_PBA_OFF_BIR_PBA_BIR_MASK (0x7U)
#define ENETC_PCI_TYPE0_PCI_CFC_MSIX_PBA_OFF_BIR_PBA_BIR_SHIFT (0U)
#define ENETC_PCI_TYPE0_PCI_CFC_MSIX_PBA_OFF_BIR_PBA_BIR(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PCI_TYPE0_PCI_CFC_MSIX_PBA_OFF_BIR_PBA_BIR_SHIFT)) & ENETC_PCI_TYPE0_PCI_CFC_MSIX_PBA_OFF_BIR_PBA_BIR_MASK)

#define ENETC_PCI_TYPE0_PCI_CFC_MSIX_PBA_OFF_BIR_PBA_OFFSET_MASK (0xFFFFFFF8U)
#define ENETC_PCI_TYPE0_PCI_CFC_MSIX_PBA_OFF_BIR_PBA_OFFSET_SHIFT (3U)
#define ENETC_PCI_TYPE0_PCI_CFC_MSIX_PBA_OFF_BIR_PBA_OFFSET(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PCI_TYPE0_PCI_CFC_MSIX_PBA_OFF_BIR_PBA_OFFSET_SHIFT)) & ENETC_PCI_TYPE0_PCI_CFC_MSIX_PBA_OFF_BIR_PBA_OFFSET_MASK)
/*! @} */

/*! @name PCI_CFC_PCIPM_CAP_LIST - PCI PCI-PM capabilities list register */
/*! @{ */

#define ENETC_PCI_TYPE0_PCI_CFC_PCIPM_CAP_LIST_CAP_ID_MASK (0xFFU)
#define ENETC_PCI_TYPE0_PCI_CFC_PCIPM_CAP_LIST_CAP_ID_SHIFT (0U)
#define ENETC_PCI_TYPE0_PCI_CFC_PCIPM_CAP_LIST_CAP_ID(x) (((uint16_t)(((uint16_t)(x)) << ENETC_PCI_TYPE0_PCI_CFC_PCIPM_CAP_LIST_CAP_ID_SHIFT)) & ENETC_PCI_TYPE0_PCI_CFC_PCIPM_CAP_LIST_CAP_ID_MASK)

#define ENETC_PCI_TYPE0_PCI_CFC_PCIPM_CAP_LIST_NEXT_CAP_PTR_MASK (0xFF00U)
#define ENETC_PCI_TYPE0_PCI_CFC_PCIPM_CAP_LIST_NEXT_CAP_PTR_SHIFT (8U)
#define ENETC_PCI_TYPE0_PCI_CFC_PCIPM_CAP_LIST_NEXT_CAP_PTR(x) (((uint16_t)(((uint16_t)(x)) << ENETC_PCI_TYPE0_PCI_CFC_PCIPM_CAP_LIST_NEXT_CAP_PTR_SHIFT)) & ENETC_PCI_TYPE0_PCI_CFC_PCIPM_CAP_LIST_NEXT_CAP_PTR_MASK)
/*! @} */

/*! @name PCI_CFC_PCIPM_CAP - PCI PCI-PM capabilities register */
/*! @{ */

#define ENETC_PCI_TYPE0_PCI_CFC_PCIPM_CAP_VERSION_MASK (0x7U)
#define ENETC_PCI_TYPE0_PCI_CFC_PCIPM_CAP_VERSION_SHIFT (0U)
#define ENETC_PCI_TYPE0_PCI_CFC_PCIPM_CAP_VERSION(x) (((uint16_t)(((uint16_t)(x)) << ENETC_PCI_TYPE0_PCI_CFC_PCIPM_CAP_VERSION_SHIFT)) & ENETC_PCI_TYPE0_PCI_CFC_PCIPM_CAP_VERSION_MASK)

#define ENETC_PCI_TYPE0_PCI_CFC_PCIPM_CAP_PME_SUPPORT_MASK (0xF800U)
#define ENETC_PCI_TYPE0_PCI_CFC_PCIPM_CAP_PME_SUPPORT_SHIFT (11U)
#define ENETC_PCI_TYPE0_PCI_CFC_PCIPM_CAP_PME_SUPPORT(x) (((uint16_t)(((uint16_t)(x)) << ENETC_PCI_TYPE0_PCI_CFC_PCIPM_CAP_PME_SUPPORT_SHIFT)) & ENETC_PCI_TYPE0_PCI_CFC_PCIPM_CAP_PME_SUPPORT_MASK)
/*! @} */

/*! @name PCI_CFC_PCIPM_CTL_STAT - PCI PCI-PM control and status register */
/*! @{ */

#define ENETC_PCI_TYPE0_PCI_CFC_PCIPM_CTL_STAT_PWR_STATE_MASK (0x3U)
#define ENETC_PCI_TYPE0_PCI_CFC_PCIPM_CTL_STAT_PWR_STATE_SHIFT (0U)
#define ENETC_PCI_TYPE0_PCI_CFC_PCIPM_CTL_STAT_PWR_STATE(x) (((uint16_t)(((uint16_t)(x)) << ENETC_PCI_TYPE0_PCI_CFC_PCIPM_CTL_STAT_PWR_STATE_SHIFT)) & ENETC_PCI_TYPE0_PCI_CFC_PCIPM_CTL_STAT_PWR_STATE_MASK)

#define ENETC_PCI_TYPE0_PCI_CFC_PCIPM_CTL_STAT_NO_SOFT_RST_MASK (0x8U)
#define ENETC_PCI_TYPE0_PCI_CFC_PCIPM_CTL_STAT_NO_SOFT_RST_SHIFT (3U)
#define ENETC_PCI_TYPE0_PCI_CFC_PCIPM_CTL_STAT_NO_SOFT_RST(x) (((uint16_t)(((uint16_t)(x)) << ENETC_PCI_TYPE0_PCI_CFC_PCIPM_CTL_STAT_NO_SOFT_RST_SHIFT)) & ENETC_PCI_TYPE0_PCI_CFC_PCIPM_CTL_STAT_NO_SOFT_RST_MASK)

#define ENETC_PCI_TYPE0_PCI_CFC_PCIPM_CTL_STAT_PME_EN_MASK (0x100U)
#define ENETC_PCI_TYPE0_PCI_CFC_PCIPM_CTL_STAT_PME_EN_SHIFT (8U)
#define ENETC_PCI_TYPE0_PCI_CFC_PCIPM_CTL_STAT_PME_EN(x) (((uint16_t)(((uint16_t)(x)) << ENETC_PCI_TYPE0_PCI_CFC_PCIPM_CTL_STAT_PME_EN_SHIFT)) & ENETC_PCI_TYPE0_PCI_CFC_PCIPM_CTL_STAT_PME_EN_MASK)

#define ENETC_PCI_TYPE0_PCI_CFC_PCIPM_CTL_STAT_PME_STATUS_MASK (0x8000U)
#define ENETC_PCI_TYPE0_PCI_CFC_PCIPM_CTL_STAT_PME_STATUS_SHIFT (15U)
#define ENETC_PCI_TYPE0_PCI_CFC_PCIPM_CTL_STAT_PME_STATUS(x) (((uint16_t)(((uint16_t)(x)) << ENETC_PCI_TYPE0_PCI_CFC_PCIPM_CTL_STAT_PME_STATUS_SHIFT)) & ENETC_PCI_TYPE0_PCI_CFC_PCIPM_CTL_STAT_PME_STATUS_MASK)
/*! @} */

/*! @name PCI_CFC_EA_CAP_LIST - PCI EA capabilities list register */
/*! @{ */

#define ENETC_PCI_TYPE0_PCI_CFC_EA_CAP_LIST_CAP_ID_MASK (0xFFU)
#define ENETC_PCI_TYPE0_PCI_CFC_EA_CAP_LIST_CAP_ID_SHIFT (0U)
#define ENETC_PCI_TYPE0_PCI_CFC_EA_CAP_LIST_CAP_ID(x) (((uint16_t)(((uint16_t)(x)) << ENETC_PCI_TYPE0_PCI_CFC_EA_CAP_LIST_CAP_ID_SHIFT)) & ENETC_PCI_TYPE0_PCI_CFC_EA_CAP_LIST_CAP_ID_MASK)

#define ENETC_PCI_TYPE0_PCI_CFC_EA_CAP_LIST_NEXT_CAP_PTR_MASK (0xFF00U)
#define ENETC_PCI_TYPE0_PCI_CFC_EA_CAP_LIST_NEXT_CAP_PTR_SHIFT (8U)
#define ENETC_PCI_TYPE0_PCI_CFC_EA_CAP_LIST_NEXT_CAP_PTR(x) (((uint16_t)(((uint16_t)(x)) << ENETC_PCI_TYPE0_PCI_CFC_EA_CAP_LIST_NEXT_CAP_PTR_SHIFT)) & ENETC_PCI_TYPE0_PCI_CFC_EA_CAP_LIST_NEXT_CAP_PTR_MASK)
/*! @} */

/*! @name PCI_CFC_EA_CAP - PCI EA capabilities register */
/*! @{ */

#define ENETC_PCI_TYPE0_PCI_CFC_EA_CAP_NUM_ENTRIES_MASK (0x3FU)
#define ENETC_PCI_TYPE0_PCI_CFC_EA_CAP_NUM_ENTRIES_SHIFT (0U)
#define ENETC_PCI_TYPE0_PCI_CFC_EA_CAP_NUM_ENTRIES(x) (((uint16_t)(((uint16_t)(x)) << ENETC_PCI_TYPE0_PCI_CFC_EA_CAP_NUM_ENTRIES_SHIFT)) & ENETC_PCI_TYPE0_PCI_CFC_EA_CAP_NUM_ENTRIES_MASK)
/*! @} */

/*! @name PCI_CFC_EA_PE_FMT - PCI EA per-entry 0 format register..PCI EA per-entry 2 format register */
/*! @{ */

#define ENETC_PCI_TYPE0_PCI_CFC_EA_PE_FMT_ENTRY_SIZE_MASK (0x7U)
#define ENETC_PCI_TYPE0_PCI_CFC_EA_PE_FMT_ENTRY_SIZE_SHIFT (0U)
#define ENETC_PCI_TYPE0_PCI_CFC_EA_PE_FMT_ENTRY_SIZE(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PCI_TYPE0_PCI_CFC_EA_PE_FMT_ENTRY_SIZE_SHIFT)) & ENETC_PCI_TYPE0_PCI_CFC_EA_PE_FMT_ENTRY_SIZE_MASK)

#define ENETC_PCI_TYPE0_PCI_CFC_EA_PE_FMT_BEI_MASK (0xF0U)
#define ENETC_PCI_TYPE0_PCI_CFC_EA_PE_FMT_BEI_SHIFT (4U)
#define ENETC_PCI_TYPE0_PCI_CFC_EA_PE_FMT_BEI(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PCI_TYPE0_PCI_CFC_EA_PE_FMT_BEI_SHIFT)) & ENETC_PCI_TYPE0_PCI_CFC_EA_PE_FMT_BEI_MASK)

#define ENETC_PCI_TYPE0_PCI_CFC_EA_PE_FMT_PRIM_PROP_MASK (0xFF00U)
#define ENETC_PCI_TYPE0_PCI_CFC_EA_PE_FMT_PRIM_PROP_SHIFT (8U)
#define ENETC_PCI_TYPE0_PCI_CFC_EA_PE_FMT_PRIM_PROP(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PCI_TYPE0_PCI_CFC_EA_PE_FMT_PRIM_PROP_SHIFT)) & ENETC_PCI_TYPE0_PCI_CFC_EA_PE_FMT_PRIM_PROP_MASK)

#define ENETC_PCI_TYPE0_PCI_CFC_EA_PE_FMT_SEC_PROP_MASK (0xFF0000U)
#define ENETC_PCI_TYPE0_PCI_CFC_EA_PE_FMT_SEC_PROP_SHIFT (16U)
#define ENETC_PCI_TYPE0_PCI_CFC_EA_PE_FMT_SEC_PROP(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PCI_TYPE0_PCI_CFC_EA_PE_FMT_SEC_PROP_SHIFT)) & ENETC_PCI_TYPE0_PCI_CFC_EA_PE_FMT_SEC_PROP_MASK)

#define ENETC_PCI_TYPE0_PCI_CFC_EA_PE_FMT_WRITABLE_MASK (0x40000000U)
#define ENETC_PCI_TYPE0_PCI_CFC_EA_PE_FMT_WRITABLE_SHIFT (30U)
#define ENETC_PCI_TYPE0_PCI_CFC_EA_PE_FMT_WRITABLE(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PCI_TYPE0_PCI_CFC_EA_PE_FMT_WRITABLE_SHIFT)) & ENETC_PCI_TYPE0_PCI_CFC_EA_PE_FMT_WRITABLE_MASK)

#define ENETC_PCI_TYPE0_PCI_CFC_EA_PE_FMT_ENABLE_MASK (0x80000000U)
#define ENETC_PCI_TYPE0_PCI_CFC_EA_PE_FMT_ENABLE_SHIFT (31U)
#define ENETC_PCI_TYPE0_PCI_CFC_EA_PE_FMT_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PCI_TYPE0_PCI_CFC_EA_PE_FMT_ENABLE_SHIFT)) & ENETC_PCI_TYPE0_PCI_CFC_EA_PE_FMT_ENABLE_MASK)
/*! @} */

/* The count of ENETC_PCI_TYPE0_PCI_CFC_EA_PE_FMT */
#define ENETC_PCI_TYPE0_PCI_CFC_EA_PE_FMT_COUNT  (3U)

/*! @name PCI_CFC_EA_PE_BASE - PCI EA per-entry 0 base register..PCI EA per-entry 2 base register */
/*! @{ */

#define ENETC_PCI_TYPE0_PCI_CFC_EA_PE_BASE_S_MASK (0x2U)
#define ENETC_PCI_TYPE0_PCI_CFC_EA_PE_BASE_S_SHIFT (1U)
#define ENETC_PCI_TYPE0_PCI_CFC_EA_PE_BASE_S(x)  (((uint32_t)(((uint32_t)(x)) << ENETC_PCI_TYPE0_PCI_CFC_EA_PE_BASE_S_SHIFT)) & ENETC_PCI_TYPE0_PCI_CFC_EA_PE_BASE_S_MASK)

#define ENETC_PCI_TYPE0_PCI_CFC_EA_PE_BASE_BASE_MASK (0xFFFFFFFCU)
#define ENETC_PCI_TYPE0_PCI_CFC_EA_PE_BASE_BASE_SHIFT (2U)
#define ENETC_PCI_TYPE0_PCI_CFC_EA_PE_BASE_BASE(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PCI_TYPE0_PCI_CFC_EA_PE_BASE_BASE_SHIFT)) & ENETC_PCI_TYPE0_PCI_CFC_EA_PE_BASE_BASE_MASK)
/*! @} */

/* The count of ENETC_PCI_TYPE0_PCI_CFC_EA_PE_BASE */
#define ENETC_PCI_TYPE0_PCI_CFC_EA_PE_BASE_COUNT (3U)

/*! @name PCI_CFC_EA_PE_MAXOFF - PCI EA per-entry 0 max offset register..PCI EA per-entry 2 max offset register */
/*! @{ */

#define ENETC_PCI_TYPE0_PCI_CFC_EA_PE_MAXOFF_S_MASK (0x2U)
#define ENETC_PCI_TYPE0_PCI_CFC_EA_PE_MAXOFF_S_SHIFT (1U)
#define ENETC_PCI_TYPE0_PCI_CFC_EA_PE_MAXOFF_S(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PCI_TYPE0_PCI_CFC_EA_PE_MAXOFF_S_SHIFT)) & ENETC_PCI_TYPE0_PCI_CFC_EA_PE_MAXOFF_S_MASK)

#define ENETC_PCI_TYPE0_PCI_CFC_EA_PE_MAXOFF_MAX_OFFSET_MASK (0xFFFFFFFCU)
#define ENETC_PCI_TYPE0_PCI_CFC_EA_PE_MAXOFF_MAX_OFFSET_SHIFT (2U)
#define ENETC_PCI_TYPE0_PCI_CFC_EA_PE_MAXOFF_MAX_OFFSET(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PCI_TYPE0_PCI_CFC_EA_PE_MAXOFF_MAX_OFFSET_SHIFT)) & ENETC_PCI_TYPE0_PCI_CFC_EA_PE_MAXOFF_MAX_OFFSET_MASK)
/*! @} */

/* The count of ENETC_PCI_TYPE0_PCI_CFC_EA_PE_MAXOFF */
#define ENETC_PCI_TYPE0_PCI_CFC_EA_PE_MAXOFF_COUNT (3U)

/*! @name PCI_CFC_EA_PE_EXT_BASE - PCI EA per-entry 0 extended base register..PCI EA per-entry 2 extended base register */
/*! @{ */

#define ENETC_PCI_TYPE0_PCI_CFC_EA_PE_EXT_BASE_BASE_MASK (0xFFFFFFFFU)
#define ENETC_PCI_TYPE0_PCI_CFC_EA_PE_EXT_BASE_BASE_SHIFT (0U)
#define ENETC_PCI_TYPE0_PCI_CFC_EA_PE_EXT_BASE_BASE(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PCI_TYPE0_PCI_CFC_EA_PE_EXT_BASE_BASE_SHIFT)) & ENETC_PCI_TYPE0_PCI_CFC_EA_PE_EXT_BASE_BASE_MASK)
/*! @} */

/* The count of ENETC_PCI_TYPE0_PCI_CFC_EA_PE_EXT_BASE */
#define ENETC_PCI_TYPE0_PCI_CFC_EA_PE_EXT_BASE_COUNT (3U)

/*! @name PCIE_CFC_AER_EXT_CAP_HDR - PCIe AER extended capability header */
/*! @{ */

#define ENETC_PCI_TYPE0_PCIE_CFC_AER_EXT_CAP_HDR_PCIE_EXT_CAP_ID_MASK (0xFFFFU)
#define ENETC_PCI_TYPE0_PCIE_CFC_AER_EXT_CAP_HDR_PCIE_EXT_CAP_ID_SHIFT (0U)
#define ENETC_PCI_TYPE0_PCIE_CFC_AER_EXT_CAP_HDR_PCIE_EXT_CAP_ID(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PCI_TYPE0_PCIE_CFC_AER_EXT_CAP_HDR_PCIE_EXT_CAP_ID_SHIFT)) & ENETC_PCI_TYPE0_PCIE_CFC_AER_EXT_CAP_HDR_PCIE_EXT_CAP_ID_MASK)

#define ENETC_PCI_TYPE0_PCIE_CFC_AER_EXT_CAP_HDR_CAP_VER_MASK (0xF0000U)
#define ENETC_PCI_TYPE0_PCIE_CFC_AER_EXT_CAP_HDR_CAP_VER_SHIFT (16U)
#define ENETC_PCI_TYPE0_PCIE_CFC_AER_EXT_CAP_HDR_CAP_VER(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PCI_TYPE0_PCIE_CFC_AER_EXT_CAP_HDR_CAP_VER_SHIFT)) & ENETC_PCI_TYPE0_PCIE_CFC_AER_EXT_CAP_HDR_CAP_VER_MASK)

#define ENETC_PCI_TYPE0_PCIE_CFC_AER_EXT_CAP_HDR_NEXT_CAP_OFF_MASK (0xFFF00000U)
#define ENETC_PCI_TYPE0_PCIE_CFC_AER_EXT_CAP_HDR_NEXT_CAP_OFF_SHIFT (20U)
#define ENETC_PCI_TYPE0_PCIE_CFC_AER_EXT_CAP_HDR_NEXT_CAP_OFF(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PCI_TYPE0_PCIE_CFC_AER_EXT_CAP_HDR_NEXT_CAP_OFF_SHIFT)) & ENETC_PCI_TYPE0_PCIE_CFC_AER_EXT_CAP_HDR_NEXT_CAP_OFF_MASK)
/*! @} */

/*! @name PCIE_CFC_AER_UCORR_ERR_STAT - PCIe AER uncorrectable error status register */
/*! @{ */

#define ENETC_PCI_TYPE0_PCIE_CFC_AER_UCORR_ERR_STAT_ACS_VIOLATION_STAT_MASK (0x200000U)
#define ENETC_PCI_TYPE0_PCIE_CFC_AER_UCORR_ERR_STAT_ACS_VIOLATION_STAT_SHIFT (21U)
#define ENETC_PCI_TYPE0_PCIE_CFC_AER_UCORR_ERR_STAT_ACS_VIOLATION_STAT(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PCI_TYPE0_PCIE_CFC_AER_UCORR_ERR_STAT_ACS_VIOLATION_STAT_SHIFT)) & ENETC_PCI_TYPE0_PCIE_CFC_AER_UCORR_ERR_STAT_ACS_VIOLATION_STAT_MASK)

#define ENETC_PCI_TYPE0_PCIE_CFC_AER_UCORR_ERR_STAT_UCORR_INT_ERR_MASK (0x400000U)
#define ENETC_PCI_TYPE0_PCIE_CFC_AER_UCORR_ERR_STAT_UCORR_INT_ERR_SHIFT (22U)
#define ENETC_PCI_TYPE0_PCIE_CFC_AER_UCORR_ERR_STAT_UCORR_INT_ERR(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PCI_TYPE0_PCIE_CFC_AER_UCORR_ERR_STAT_UCORR_INT_ERR_SHIFT)) & ENETC_PCI_TYPE0_PCIE_CFC_AER_UCORR_ERR_STAT_UCORR_INT_ERR_MASK)
/*! @} */

/*! @name PCIE_CFC_AER_UCORR_ERR_MASK - PCIe AER uncorrectable error mask register */
/*! @{ */

#define ENETC_PCI_TYPE0_PCIE_CFC_AER_UCORR_ERR_MASK_UCORR_INT_ERR_MASK_MASK (0x400000U)
#define ENETC_PCI_TYPE0_PCIE_CFC_AER_UCORR_ERR_MASK_UCORR_INT_ERR_MASK_SHIFT (22U)
#define ENETC_PCI_TYPE0_PCIE_CFC_AER_UCORR_ERR_MASK_UCORR_INT_ERR_MASK(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PCI_TYPE0_PCIE_CFC_AER_UCORR_ERR_MASK_UCORR_INT_ERR_MASK_SHIFT)) & ENETC_PCI_TYPE0_PCIE_CFC_AER_UCORR_ERR_MASK_UCORR_INT_ERR_MASK_MASK)
/*! @} */

/*! @name PCIE_CFC_AER_UCORR_ERR_SEV - PCIe AER uncorrectable error severity register */
/*! @{ */

#define ENETC_PCI_TYPE0_PCIE_CFC_AER_UCORR_ERR_SEV_UCORR_INT_SEV_MASK (0x400000U)
#define ENETC_PCI_TYPE0_PCIE_CFC_AER_UCORR_ERR_SEV_UCORR_INT_SEV_SHIFT (22U)
#define ENETC_PCI_TYPE0_PCIE_CFC_AER_UCORR_ERR_SEV_UCORR_INT_SEV(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PCI_TYPE0_PCIE_CFC_AER_UCORR_ERR_SEV_UCORR_INT_SEV_SHIFT)) & ENETC_PCI_TYPE0_PCIE_CFC_AER_UCORR_ERR_SEV_UCORR_INT_SEV_MASK)
/*! @} */

/*! @name PCIE_CFC_AER_CORR_ERR_STAT - PCIe AER correctable error status register */
/*! @{ */

#define ENETC_PCI_TYPE0_PCIE_CFC_AER_CORR_ERR_STAT_CORR_INT_ERR_MASK (0x4000U)
#define ENETC_PCI_TYPE0_PCIE_CFC_AER_CORR_ERR_STAT_CORR_INT_ERR_SHIFT (14U)
#define ENETC_PCI_TYPE0_PCIE_CFC_AER_CORR_ERR_STAT_CORR_INT_ERR(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PCI_TYPE0_PCIE_CFC_AER_CORR_ERR_STAT_CORR_INT_ERR_SHIFT)) & ENETC_PCI_TYPE0_PCIE_CFC_AER_CORR_ERR_STAT_CORR_INT_ERR_MASK)
/*! @} */

/*! @name PCIE_CFC_AER_CORR_ERR_MASK - PCIe AER correctable error mask register */
/*! @{ */

#define ENETC_PCI_TYPE0_PCIE_CFC_AER_CORR_ERR_MASK_CORR_INT_MASK_MASK (0x4000U)
#define ENETC_PCI_TYPE0_PCIE_CFC_AER_CORR_ERR_MASK_CORR_INT_MASK_SHIFT (14U)
#define ENETC_PCI_TYPE0_PCIE_CFC_AER_CORR_ERR_MASK_CORR_INT_MASK(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PCI_TYPE0_PCIE_CFC_AER_CORR_ERR_MASK_CORR_INT_MASK_SHIFT)) & ENETC_PCI_TYPE0_PCIE_CFC_AER_CORR_ERR_MASK_CORR_INT_MASK_MASK)
/*! @} */

/*! @name PCIE_CFC_AER_CAP_CTL - PCIe AER capabilities and control register */
/*! @{ */

#define ENETC_PCI_TYPE0_PCIE_CFC_AER_CAP_CTL_FIRST_ERR_PTR_MASK (0x1FU)
#define ENETC_PCI_TYPE0_PCIE_CFC_AER_CAP_CTL_FIRST_ERR_PTR_SHIFT (0U)
#define ENETC_PCI_TYPE0_PCIE_CFC_AER_CAP_CTL_FIRST_ERR_PTR(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PCI_TYPE0_PCIE_CFC_AER_CAP_CTL_FIRST_ERR_PTR_SHIFT)) & ENETC_PCI_TYPE0_PCIE_CFC_AER_CAP_CTL_FIRST_ERR_PTR_MASK)
/*! @} */

/*! @name PCIE_CFC_ACS_CAP_HDR - PCIe ACS capability header */
/*! @{ */

#define ENETC_PCI_TYPE0_PCIE_CFC_ACS_CAP_HDR_PCIE_EXT_CAP_ID_MASK (0xFFFFU)
#define ENETC_PCI_TYPE0_PCIE_CFC_ACS_CAP_HDR_PCIE_EXT_CAP_ID_SHIFT (0U)
#define ENETC_PCI_TYPE0_PCIE_CFC_ACS_CAP_HDR_PCIE_EXT_CAP_ID(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PCI_TYPE0_PCIE_CFC_ACS_CAP_HDR_PCIE_EXT_CAP_ID_SHIFT)) & ENETC_PCI_TYPE0_PCIE_CFC_ACS_CAP_HDR_PCIE_EXT_CAP_ID_MASK)

#define ENETC_PCI_TYPE0_PCIE_CFC_ACS_CAP_HDR_CAP_VER_MASK (0xF0000U)
#define ENETC_PCI_TYPE0_PCIE_CFC_ACS_CAP_HDR_CAP_VER_SHIFT (16U)
#define ENETC_PCI_TYPE0_PCIE_CFC_ACS_CAP_HDR_CAP_VER(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PCI_TYPE0_PCIE_CFC_ACS_CAP_HDR_CAP_VER_SHIFT)) & ENETC_PCI_TYPE0_PCIE_CFC_ACS_CAP_HDR_CAP_VER_MASK)

#define ENETC_PCI_TYPE0_PCIE_CFC_ACS_CAP_HDR_NEXT_CAP_OFF_MASK (0xFFF00000U)
#define ENETC_PCI_TYPE0_PCIE_CFC_ACS_CAP_HDR_NEXT_CAP_OFF_SHIFT (20U)
#define ENETC_PCI_TYPE0_PCIE_CFC_ACS_CAP_HDR_NEXT_CAP_OFF(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PCI_TYPE0_PCIE_CFC_ACS_CAP_HDR_NEXT_CAP_OFF_SHIFT)) & ENETC_PCI_TYPE0_PCIE_CFC_ACS_CAP_HDR_NEXT_CAP_OFF_MASK)
/*! @} */

/*! @name PCIE_CFC_ACS_CAP - PCIe ACS capability register */
/*! @{ */

#define ENETC_PCI_TYPE0_PCIE_CFC_ACS_CAP_ACS_TRANS_BLOCK_MASK (0x2U)
#define ENETC_PCI_TYPE0_PCIE_CFC_ACS_CAP_ACS_TRANS_BLOCK_SHIFT (1U)
#define ENETC_PCI_TYPE0_PCIE_CFC_ACS_CAP_ACS_TRANS_BLOCK(x) (((uint16_t)(((uint16_t)(x)) << ENETC_PCI_TYPE0_PCIE_CFC_ACS_CAP_ACS_TRANS_BLOCK_SHIFT)) & ENETC_PCI_TYPE0_PCIE_CFC_ACS_CAP_ACS_TRANS_BLOCK_MASK)

#define ENETC_PCI_TYPE0_PCIE_CFC_ACS_CAP_ACS_P2P_REQ_REDIR_MASK (0x4U)
#define ENETC_PCI_TYPE0_PCIE_CFC_ACS_CAP_ACS_P2P_REQ_REDIR_SHIFT (2U)
#define ENETC_PCI_TYPE0_PCIE_CFC_ACS_CAP_ACS_P2P_REQ_REDIR(x) (((uint16_t)(((uint16_t)(x)) << ENETC_PCI_TYPE0_PCIE_CFC_ACS_CAP_ACS_P2P_REQ_REDIR_SHIFT)) & ENETC_PCI_TYPE0_PCIE_CFC_ACS_CAP_ACS_P2P_REQ_REDIR_MASK)

#define ENETC_PCI_TYPE0_PCIE_CFC_ACS_CAP_ACS_DIR_TRANS_P2P_MASK (0x40U)
#define ENETC_PCI_TYPE0_PCIE_CFC_ACS_CAP_ACS_DIR_TRANS_P2P_SHIFT (6U)
#define ENETC_PCI_TYPE0_PCIE_CFC_ACS_CAP_ACS_DIR_TRANS_P2P(x) (((uint16_t)(((uint16_t)(x)) << ENETC_PCI_TYPE0_PCIE_CFC_ACS_CAP_ACS_DIR_TRANS_P2P_SHIFT)) & ENETC_PCI_TYPE0_PCIE_CFC_ACS_CAP_ACS_DIR_TRANS_P2P_MASK)
/*! @} */

/*! @name PCIE_CFC_ACS_CTL - PCIe ACS control register */
/*! @{ */

#define ENETC_PCI_TYPE0_PCIE_CFC_ACS_CTL_ACS_TRANS_BLOCK_EN_MASK (0x2U)
#define ENETC_PCI_TYPE0_PCIE_CFC_ACS_CTL_ACS_TRANS_BLOCK_EN_SHIFT (1U)
#define ENETC_PCI_TYPE0_PCIE_CFC_ACS_CTL_ACS_TRANS_BLOCK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENETC_PCI_TYPE0_PCIE_CFC_ACS_CTL_ACS_TRANS_BLOCK_EN_SHIFT)) & ENETC_PCI_TYPE0_PCIE_CFC_ACS_CTL_ACS_TRANS_BLOCK_EN_MASK)

#define ENETC_PCI_TYPE0_PCIE_CFC_ACS_CTL_ACS_P2P_REQ_REDIR_EN_MASK (0x4U)
#define ENETC_PCI_TYPE0_PCIE_CFC_ACS_CTL_ACS_P2P_REQ_REDIR_EN_SHIFT (2U)
#define ENETC_PCI_TYPE0_PCIE_CFC_ACS_CTL_ACS_P2P_REQ_REDIR_EN(x) (((uint16_t)(((uint16_t)(x)) << ENETC_PCI_TYPE0_PCIE_CFC_ACS_CTL_ACS_P2P_REQ_REDIR_EN_SHIFT)) & ENETC_PCI_TYPE0_PCIE_CFC_ACS_CTL_ACS_P2P_REQ_REDIR_EN_MASK)

#define ENETC_PCI_TYPE0_PCIE_CFC_ACS_CTL_ACS_DIR_TRANS_P2P_EN_MASK (0x40U)
#define ENETC_PCI_TYPE0_PCIE_CFC_ACS_CTL_ACS_DIR_TRANS_P2P_EN_SHIFT (6U)
#define ENETC_PCI_TYPE0_PCIE_CFC_ACS_CTL_ACS_DIR_TRANS_P2P_EN(x) (((uint16_t)(((uint16_t)(x)) << ENETC_PCI_TYPE0_PCIE_CFC_ACS_CTL_ACS_DIR_TRANS_P2P_EN_SHIFT)) & ENETC_PCI_TYPE0_PCIE_CFC_ACS_CTL_ACS_DIR_TRANS_P2P_EN_MASK)
/*! @} */

/*! @name PCIE_CFC_RTR_CAP_HDR - PCIe readiness time reporting capability header */
/*! @{ */

#define ENETC_PCI_TYPE0_PCIE_CFC_RTR_CAP_HDR_PCIE_EXT_CAP_ID_MASK (0xFFFFU)
#define ENETC_PCI_TYPE0_PCIE_CFC_RTR_CAP_HDR_PCIE_EXT_CAP_ID_SHIFT (0U)
#define ENETC_PCI_TYPE0_PCIE_CFC_RTR_CAP_HDR_PCIE_EXT_CAP_ID(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PCI_TYPE0_PCIE_CFC_RTR_CAP_HDR_PCIE_EXT_CAP_ID_SHIFT)) & ENETC_PCI_TYPE0_PCIE_CFC_RTR_CAP_HDR_PCIE_EXT_CAP_ID_MASK)

#define ENETC_PCI_TYPE0_PCIE_CFC_RTR_CAP_HDR_CAP_VER_MASK (0xF0000U)
#define ENETC_PCI_TYPE0_PCIE_CFC_RTR_CAP_HDR_CAP_VER_SHIFT (16U)
#define ENETC_PCI_TYPE0_PCIE_CFC_RTR_CAP_HDR_CAP_VER(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PCI_TYPE0_PCIE_CFC_RTR_CAP_HDR_CAP_VER_SHIFT)) & ENETC_PCI_TYPE0_PCIE_CFC_RTR_CAP_HDR_CAP_VER_MASK)

#define ENETC_PCI_TYPE0_PCIE_CFC_RTR_CAP_HDR_NEXT_CAP_OFF_MASK (0xFFF00000U)
#define ENETC_PCI_TYPE0_PCIE_CFC_RTR_CAP_HDR_NEXT_CAP_OFF_SHIFT (20U)
#define ENETC_PCI_TYPE0_PCIE_CFC_RTR_CAP_HDR_NEXT_CAP_OFF(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PCI_TYPE0_PCIE_CFC_RTR_CAP_HDR_NEXT_CAP_OFF_SHIFT)) & ENETC_PCI_TYPE0_PCIE_CFC_RTR_CAP_HDR_NEXT_CAP_OFF_MASK)
/*! @} */

/*! @name PCIE_CFC_RTR_RTR1 - PCIe RTR readiness time reporting 1 register */
/*! @{ */

#define ENETC_PCI_TYPE0_PCIE_CFC_RTR_RTR1_RESET_TIME_MASK (0xFFFU)
#define ENETC_PCI_TYPE0_PCIE_CFC_RTR_RTR1_RESET_TIME_SHIFT (0U)
/*! RESET_TIME - Reset Time */
#define ENETC_PCI_TYPE0_PCIE_CFC_RTR_RTR1_RESET_TIME(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PCI_TYPE0_PCIE_CFC_RTR_RTR1_RESET_TIME_SHIFT)) & ENETC_PCI_TYPE0_PCIE_CFC_RTR_RTR1_RESET_TIME_MASK)

#define ENETC_PCI_TYPE0_PCIE_CFC_RTR_RTR1_VALID_MASK (0x80000000U)
#define ENETC_PCI_TYPE0_PCIE_CFC_RTR_RTR1_VALID_SHIFT (31U)
/*! VALID - Valid */
#define ENETC_PCI_TYPE0_PCIE_CFC_RTR_RTR1_VALID(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PCI_TYPE0_PCIE_CFC_RTR_RTR1_VALID_SHIFT)) & ENETC_PCI_TYPE0_PCIE_CFC_RTR_RTR1_VALID_MASK)
/*! @} */

/*! @name PCIE_CFC_RTR_RTR2 - PCIe RTR readiness time reporting 2 register */
/*! @{ */

#define ENETC_PCI_TYPE0_PCIE_CFC_RTR_RTR2_FLR_TIME_MASK (0xFFFU)
#define ENETC_PCI_TYPE0_PCIE_CFC_RTR_RTR2_FLR_TIME_SHIFT (0U)
/*! FLR_TIME - FLR Time */
#define ENETC_PCI_TYPE0_PCIE_CFC_RTR_RTR2_FLR_TIME(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PCI_TYPE0_PCIE_CFC_RTR_RTR2_FLR_TIME_SHIFT)) & ENETC_PCI_TYPE0_PCIE_CFC_RTR_RTR2_FLR_TIME_MASK)

#define ENETC_PCI_TYPE0_PCIE_CFC_RTR_RTR2_D3HOT_D0_TIME_MASK (0xFFF000U)
#define ENETC_PCI_TYPE0_PCIE_CFC_RTR_RTR2_D3HOT_D0_TIME_SHIFT (12U)
/*! D3HOT_D0_TIME - D3 hot to D0 time */
#define ENETC_PCI_TYPE0_PCIE_CFC_RTR_RTR2_D3HOT_D0_TIME(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PCI_TYPE0_PCIE_CFC_RTR_RTR2_D3HOT_D0_TIME_SHIFT)) & ENETC_PCI_TYPE0_PCIE_CFC_RTR_RTR2_D3HOT_D0_TIME_MASK)
/*! @} */

/*! @name PCIE_CFC_SRIOV_CAP_HDR - PCIe SR-IOV capability header */
/*! @{ */

#define ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_CAP_HDR_PCIE_EXT_CAP_ID_MASK (0xFFFFU)
#define ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_CAP_HDR_PCIE_EXT_CAP_ID_SHIFT (0U)
#define ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_CAP_HDR_PCIE_EXT_CAP_ID(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_CAP_HDR_PCIE_EXT_CAP_ID_SHIFT)) & ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_CAP_HDR_PCIE_EXT_CAP_ID_MASK)

#define ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_CAP_HDR_CAP_VER_MASK (0xF0000U)
#define ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_CAP_HDR_CAP_VER_SHIFT (16U)
#define ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_CAP_HDR_CAP_VER(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_CAP_HDR_CAP_VER_SHIFT)) & ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_CAP_HDR_CAP_VER_MASK)

#define ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_CAP_HDR_NEXT_CAP_OFF_MASK (0xFFF00000U)
#define ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_CAP_HDR_NEXT_CAP_OFF_SHIFT (20U)
#define ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_CAP_HDR_NEXT_CAP_OFF(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_CAP_HDR_NEXT_CAP_OFF_SHIFT)) & ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_CAP_HDR_NEXT_CAP_OFF_MASK)
/*! @} */

/*! @name PCIE_CFC_SRIOV_CAP - PCIe SR-IOV capability register */
/*! @{ */

#define ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_CAP_VF_MIGRATION_CAP_MASK (0x1U)
#define ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_CAP_VF_MIGRATION_CAP_SHIFT (0U)
#define ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_CAP_VF_MIGRATION_CAP(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_CAP_VF_MIGRATION_CAP_SHIFT)) & ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_CAP_VF_MIGRATION_CAP_MASK)

#define ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_CAP_ARI_CAP_HIER_PRSV_MASK (0x2U)
#define ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_CAP_ARI_CAP_HIER_PRSV_SHIFT (1U)
#define ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_CAP_ARI_CAP_HIER_PRSV(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_CAP_ARI_CAP_HIER_PRSV_SHIFT)) & ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_CAP_ARI_CAP_HIER_PRSV_MASK)

#define ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_CAP_VF_MIGRATION_ING_MSG_NUM_MASK (0xFFE00000U)
#define ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_CAP_VF_MIGRATION_ING_MSG_NUM_SHIFT (21U)
#define ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_CAP_VF_MIGRATION_ING_MSG_NUM(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_CAP_VF_MIGRATION_ING_MSG_NUM_SHIFT)) & ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_CAP_VF_MIGRATION_ING_MSG_NUM_MASK)
/*! @} */

/*! @name PCIE_CFC_SRIOV_CTL - PCIe SR-IOV control register */
/*! @{ */

#define ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_CTL_VF_ENABLE_MASK (0x1U)
#define ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_CTL_VF_ENABLE_SHIFT (0U)
#define ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_CTL_VF_ENABLE(x) (((uint16_t)(((uint16_t)(x)) << ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_CTL_VF_ENABLE_SHIFT)) & ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_CTL_VF_ENABLE_MASK)

#define ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_CTL_VF_MIGRATION_ENABLE_MASK (0x2U)
#define ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_CTL_VF_MIGRATION_ENABLE_SHIFT (1U)
#define ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_CTL_VF_MIGRATION_ENABLE(x) (((uint16_t)(((uint16_t)(x)) << ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_CTL_VF_MIGRATION_ENABLE_SHIFT)) & ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_CTL_VF_MIGRATION_ENABLE_MASK)

#define ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_CTL_VF_MIGRATION_INT_ENABLE_MASK (0x4U)
#define ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_CTL_VF_MIGRATION_INT_ENABLE_SHIFT (2U)
#define ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_CTL_VF_MIGRATION_INT_ENABLE(x) (((uint16_t)(((uint16_t)(x)) << ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_CTL_VF_MIGRATION_INT_ENABLE_SHIFT)) & ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_CTL_VF_MIGRATION_INT_ENABLE_MASK)

#define ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_CTL_VF_MSE_MASK (0x8U)
#define ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_CTL_VF_MSE_SHIFT (3U)
#define ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_CTL_VF_MSE(x) (((uint16_t)(((uint16_t)(x)) << ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_CTL_VF_MSE_SHIFT)) & ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_CTL_VF_MSE_MASK)

#define ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_CTL_ARI_CAP_HIERARCHY_MASK (0x10U)
#define ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_CTL_ARI_CAP_HIERARCHY_SHIFT (4U)
#define ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_CTL_ARI_CAP_HIERARCHY(x) (((uint16_t)(((uint16_t)(x)) << ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_CTL_ARI_CAP_HIERARCHY_SHIFT)) & ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_CTL_ARI_CAP_HIERARCHY_MASK)

#define ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_CTL_D2_SUPPORT_MASK (0x400U)
#define ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_CTL_D2_SUPPORT_SHIFT (10U)
#define ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_CTL_D2_SUPPORT(x) (((uint16_t)(((uint16_t)(x)) << ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_CTL_D2_SUPPORT_SHIFT)) & ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_CTL_D2_SUPPORT_MASK)

#define ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_CTL_PME_SUPPORT_MASK (0xF800U)
#define ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_CTL_PME_SUPPORT_SHIFT (11U)
#define ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_CTL_PME_SUPPORT(x) (((uint16_t)(((uint16_t)(x)) << ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_CTL_PME_SUPPORT_SHIFT)) & ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_CTL_PME_SUPPORT_MASK)
/*! @} */

/*! @name PCIE_CFC_SRIOV_STAT - PCIe SR-IOV status register */
/*! @{ */

#define ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_STAT_VF_MIGRATION_STATUS_MASK (0x1U)
#define ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_STAT_VF_MIGRATION_STATUS_SHIFT (0U)
#define ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_STAT_VF_MIGRATION_STATUS(x) (((uint16_t)(((uint16_t)(x)) << ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_STAT_VF_MIGRATION_STATUS_SHIFT)) & ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_STAT_VF_MIGRATION_STATUS_MASK)
/*! @} */

/*! @name PCIE_CFC_SRIOV_INIT_VFS - PCIe SR-IOV initial VFs register */
/*! @{ */

#define ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_INIT_VFS_INITIAL_VFS_MASK (0xFFFFU)
#define ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_INIT_VFS_INITIAL_VFS_SHIFT (0U)
#define ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_INIT_VFS_INITIAL_VFS(x) (((uint16_t)(((uint16_t)(x)) << ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_INIT_VFS_INITIAL_VFS_SHIFT)) & ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_INIT_VFS_INITIAL_VFS_MASK)
/*! @} */

/*! @name PCIE_CFC_SRIOV_TOTAL_VFS - PCIe SR-IOV total VFs register */
/*! @{ */

#define ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_TOTAL_VFS_TOTAL_VFS_MASK (0xFFFFU)
#define ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_TOTAL_VFS_TOTAL_VFS_SHIFT (0U)
#define ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_TOTAL_VFS_TOTAL_VFS(x) (((uint16_t)(((uint16_t)(x)) << ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_TOTAL_VFS_TOTAL_VFS_SHIFT)) & ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_TOTAL_VFS_TOTAL_VFS_MASK)
/*! @} */

/*! @name PCIE_CFC_SRIOV_NUM_VFS - PCIe SR-IOV num VFs register */
/*! @{ */

#define ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_NUM_VFS_NUM_VFS_MASK (0xFFFFU)
#define ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_NUM_VFS_NUM_VFS_SHIFT (0U)
#define ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_NUM_VFS_NUM_VFS(x) (((uint16_t)(((uint16_t)(x)) << ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_NUM_VFS_NUM_VFS_SHIFT)) & ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_NUM_VFS_NUM_VFS_MASK)
/*! @} */

/*! @name PCIE_CFC_SRIOV_FUNC_DEP_LIST - PCIe SR-IOV function dependency list register */
/*! @{ */

#define ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_FUNC_DEP_LIST_FUNC_DEP_LIST_MASK (0xFFFFU)
#define ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_FUNC_DEP_LIST_FUNC_DEP_LIST_SHIFT (0U)
#define ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_FUNC_DEP_LIST_FUNC_DEP_LIST(x) (((uint16_t)(((uint16_t)(x)) << ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_FUNC_DEP_LIST_FUNC_DEP_LIST_SHIFT)) & ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_FUNC_DEP_LIST_FUNC_DEP_LIST_MASK)
/*! @} */

/*! @name PCIE_CFC_SRIOV_FIRST_VF_OFF - PCIe SR-IOV first VF offset register */
/*! @{ */

#define ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_FIRST_VF_OFF_FIRST_VF_OFFSET_MASK (0xFFFFU)
#define ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_FIRST_VF_OFF_FIRST_VF_OFFSET_SHIFT (0U)
#define ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_FIRST_VF_OFF_FIRST_VF_OFFSET(x) (((uint16_t)(((uint16_t)(x)) << ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_FIRST_VF_OFF_FIRST_VF_OFFSET_SHIFT)) & ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_FIRST_VF_OFF_FIRST_VF_OFFSET_MASK)
/*! @} */

/*! @name PCIE_CFC_SRIOV_VF_STRIDE - PCIe SR-IOV VF stride register */
/*! @{ */

#define ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_VF_STRIDE_VF_STRIDE_MASK (0xFFFFU)
#define ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_VF_STRIDE_VF_STRIDE_SHIFT (0U)
#define ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_VF_STRIDE_VF_STRIDE(x) (((uint16_t)(((uint16_t)(x)) << ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_VF_STRIDE_VF_STRIDE_SHIFT)) & ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_VF_STRIDE_VF_STRIDE_MASK)
/*! @} */

/*! @name PCIE_CFC_SRIOV_VF_DEV_ID - PCIe SR-IOV VF device ID register */
/*! @{ */

#define ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_VF_DEV_ID_VF_DEVICE_ID_MASK (0xFFFFU)
#define ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_VF_DEV_ID_VF_DEVICE_ID_SHIFT (0U)
#define ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_VF_DEV_ID_VF_DEVICE_ID(x) (((uint16_t)(((uint16_t)(x)) << ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_VF_DEV_ID_VF_DEVICE_ID_SHIFT)) & ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_VF_DEV_ID_VF_DEVICE_ID_MASK)
/*! @} */

/*! @name PCIE_CFC_SRIOV_SUP_PAGE_SIZES - PCIe SR-IOV supported page sizes ID register */
/*! @{ */

#define ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_SUP_PAGE_SIZES_SUP_PAGE_SIZES_MASK (0xFFFFFFFFU)
#define ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_SUP_PAGE_SIZES_SUP_PAGE_SIZES_SHIFT (0U)
#define ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_SUP_PAGE_SIZES_SUP_PAGE_SIZES(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_SUP_PAGE_SIZES_SUP_PAGE_SIZES_SHIFT)) & ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_SUP_PAGE_SIZES_SUP_PAGE_SIZES_MASK)
/*! @} */

/*! @name PCIE_CFC_SRIOV_SYS_PAGE_SIZE - PCIe SR-IOV system page size ID register */
/*! @{ */

#define ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_SYS_PAGE_SIZE_SYS_PAGE_SIZE_MASK (0xFFFFFFFFU)
#define ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_SYS_PAGE_SIZE_SYS_PAGE_SIZE_SHIFT (0U)
#define ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_SYS_PAGE_SIZE_SYS_PAGE_SIZE(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_SYS_PAGE_SIZE_SYS_PAGE_SIZE_SHIFT)) & ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_SYS_PAGE_SIZE_SYS_PAGE_SIZE_MASK)
/*! @} */

/*! @name PCIE_CFC_VF_BAR - PCIe SR-IOV VF base address register 0..PCIe SR-IOV VF base address register 5 */
/*! @{ */

#define ENETC_PCI_TYPE0_PCIE_CFC_VF_BAR_MEM_IO_IND_MASK (0x1U)
#define ENETC_PCI_TYPE0_PCIE_CFC_VF_BAR_MEM_IO_IND_SHIFT (0U)
#define ENETC_PCI_TYPE0_PCIE_CFC_VF_BAR_MEM_IO_IND(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PCI_TYPE0_PCIE_CFC_VF_BAR_MEM_IO_IND_SHIFT)) & ENETC_PCI_TYPE0_PCIE_CFC_VF_BAR_MEM_IO_IND_MASK)

#define ENETC_PCI_TYPE0_PCIE_CFC_VF_BAR_MEM_TYPE_MASK (0x6U)
#define ENETC_PCI_TYPE0_PCIE_CFC_VF_BAR_MEM_TYPE_SHIFT (1U)
#define ENETC_PCI_TYPE0_PCIE_CFC_VF_BAR_MEM_TYPE(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PCI_TYPE0_PCIE_CFC_VF_BAR_MEM_TYPE_SHIFT)) & ENETC_PCI_TYPE0_PCIE_CFC_VF_BAR_MEM_TYPE_MASK)

#define ENETC_PCI_TYPE0_PCIE_CFC_VF_BAR_PF_MEM_MASK (0x8U)
#define ENETC_PCI_TYPE0_PCIE_CFC_VF_BAR_PF_MEM_SHIFT (3U)
#define ENETC_PCI_TYPE0_PCIE_CFC_VF_BAR_PF_MEM(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PCI_TYPE0_PCIE_CFC_VF_BAR_PF_MEM_SHIFT)) & ENETC_PCI_TYPE0_PCIE_CFC_VF_BAR_PF_MEM_MASK)

#define ENETC_PCI_TYPE0_PCIE_CFC_VF_BAR_ADDR_MASK (0xFFFFFFF0U)
#define ENETC_PCI_TYPE0_PCIE_CFC_VF_BAR_ADDR_SHIFT (4U)
#define ENETC_PCI_TYPE0_PCIE_CFC_VF_BAR_ADDR(x)  (((uint32_t)(((uint32_t)(x)) << ENETC_PCI_TYPE0_PCIE_CFC_VF_BAR_ADDR_SHIFT)) & ENETC_PCI_TYPE0_PCIE_CFC_VF_BAR_ADDR_MASK)
/*! @} */

/* The count of ENETC_PCI_TYPE0_PCIE_CFC_VF_BAR */
#define ENETC_PCI_TYPE0_PCIE_CFC_VF_BAR_COUNT    (6U)

/*! @name PCIE_CFC_SRIOV_VF_MIG_STATE_ARR_OFF - PCIe SR-IOV VF migration state array offset register */
/*! @{ */

#define ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_VF_MIG_STATE_ARR_OFF_VF_MIG_STATE_ARR_OFF_MASK (0xFFFFFFFFU)
#define ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_VF_MIG_STATE_ARR_OFF_VF_MIG_STATE_ARR_OFF_SHIFT (0U)
#define ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_VF_MIG_STATE_ARR_OFF_VF_MIG_STATE_ARR_OFF(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_VF_MIG_STATE_ARR_OFF_VF_MIG_STATE_ARR_OFF_SHIFT)) & ENETC_PCI_TYPE0_PCIE_CFC_SRIOV_VF_MIG_STATE_ARR_OFF_VF_MIG_STATE_ARR_OFF_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group ENETC_PCI_TYPE0_Register_Masks */


/*!
 * @}
 */ /* end of group ENETC_PCI_TYPE0_Peripheral_Access_Layer */


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


#endif  /* ENETC_PCI_TYPE0_H_ */

