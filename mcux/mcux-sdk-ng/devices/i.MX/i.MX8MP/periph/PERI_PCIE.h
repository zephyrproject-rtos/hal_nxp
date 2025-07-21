/*
** ###################################################################
**     Processors:          MIMX8ML2CVNKZ_ca53
**                          MIMX8ML2CVNKZ_cm7
**                          MIMX8ML2CVNKZ_dsp
**                          MIMX8ML2DVNLZ_ca53
**                          MIMX8ML2DVNLZ_cm7
**                          MIMX8ML2DVNLZ_dsp
**                          MIMX8ML3CVNKZ_ca53
**                          MIMX8ML3CVNKZ_cm7
**                          MIMX8ML3CVNKZ_dsp
**                          MIMX8ML3DVNLZ_ca53
**                          MIMX8ML3DVNLZ_cm7
**                          MIMX8ML3DVNLZ_dsp
**                          MIMX8ML4CVNKZ_ca53
**                          MIMX8ML4CVNKZ_cm7
**                          MIMX8ML4DVNLZ_ca53
**                          MIMX8ML4DVNLZ_cm7
**                          MIMX8ML5CVNKZ_ca53
**                          MIMX8ML5CVNKZ_cm7
**                          MIMX8ML5CVNKZ_dsp
**                          MIMX8ML5DVNLZ_ca53
**                          MIMX8ML5DVNLZ_cm7
**                          MIMX8ML5DVNLZ_dsp
**                          MIMX8ML6CVNKZ_ca53
**                          MIMX8ML6CVNKZ_cm7
**                          MIMX8ML6DVNLZ_ca53
**                          MIMX8ML6DVNLZ_cm7
**                          MIMX8ML8CVNKZ_ca53
**                          MIMX8ML8CVNKZ_cm7
**                          MIMX8ML8CVNKZ_dsp
**                          MIMX8ML8DVNLZ_ca53
**                          MIMX8ML8DVNLZ_cm7
**                          MIMX8ML8DVNLZ_dsp
**
**     Version:             rev. 6.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for PCIE
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2019-10-11)
**         Initial version.
**     - rev. 2.0 (2020-02-21)
**         Rev.B Header.
**     - rev. 3.0 (2020-06-22)
**         Rev.C Header.
**     - rev. 4.0 (2020-11-16)
**         Rev.D Header.
**     - rev. 5.0 (2021-03-01)
**         Rev.D Header Final.
**     - rev. 6.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_PCIE.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for PCIE
 *
 * CMSIS Peripheral Access Layer for PCIE
 */

#if !defined(PERI_PCIE_H_)
#define PERI_PCIE_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8ML2CVNKZ_ca53) || defined(CPU_MIMX8ML2DVNLZ_ca53))
#include "MIMX8ML2_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML2CVNKZ_cm7) || defined(CPU_MIMX8ML2DVNLZ_cm7))
#include "MIMX8ML2_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML2CVNKZ_dsp) || defined(CPU_MIMX8ML2DVNLZ_dsp))
#include "MIMX8ML2_dsp_COMMON.h"
#elif (defined(CPU_MIMX8ML3CVNKZ_ca53) || defined(CPU_MIMX8ML3DVNLZ_ca53))
#include "MIMX8ML3_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML3CVNKZ_cm7) || defined(CPU_MIMX8ML3DVNLZ_cm7))
#include "MIMX8ML3_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML3CVNKZ_dsp) || defined(CPU_MIMX8ML3DVNLZ_dsp))
#include "MIMX8ML3_dsp_COMMON.h"
#elif (defined(CPU_MIMX8ML4CVNKZ_ca53) || defined(CPU_MIMX8ML4DVNLZ_ca53))
#include "MIMX8ML4_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML4CVNKZ_cm7) || defined(CPU_MIMX8ML4DVNLZ_cm7))
#include "MIMX8ML4_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML5CVNKZ_ca53) || defined(CPU_MIMX8ML5DVNLZ_ca53))
#include "MIMX8ML5_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML5CVNKZ_cm7) || defined(CPU_MIMX8ML5DVNLZ_cm7))
#include "MIMX8ML5_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML5CVNKZ_dsp) || defined(CPU_MIMX8ML5DVNLZ_dsp))
#include "MIMX8ML5_dsp_COMMON.h"
#elif (defined(CPU_MIMX8ML6CVNKZ_ca53) || defined(CPU_MIMX8ML6DVNLZ_ca53))
#include "MIMX8ML6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML6CVNKZ_cm7) || defined(CPU_MIMX8ML6DVNLZ_cm7))
#include "MIMX8ML6_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML8CVNKZ_ca53) || defined(CPU_MIMX8ML8DVNLZ_ca53))
#include "MIMX8ML8_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML8CVNKZ_cm7) || defined(CPU_MIMX8ML8DVNLZ_cm7))
#include "MIMX8ML8_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML8CVNKZ_dsp) || defined(CPU_MIMX8ML8DVNLZ_dsp))
#include "MIMX8ML8_dsp_COMMON.h"
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
#elif defined(__XTENSA__)
  /* anonymous unions are enabled by default */
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- PCIE Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PCIE_Peripheral_Access_Layer PCIE Peripheral Access Layer
 * @{
 */

/** PCIE - Register Layout Typedef */
typedef struct {
  __IO uint32_t TYPE1_DEV_ID_VEND_ID_REG;          /**< Device ID and Vendor ID Register., offset: 0x0 */
  __IO uint32_t TYPE1_STATUS_COMMAND_REG;          /**< Status and Command Register., offset: 0x4 */
  __IO uint32_t TYPE1_CLASS_CODE_REV_ID_REG;       /**< Class Code and Revision ID Register., offset: 0x8 */
  __IO uint32_t TYPE1_HDR_TYPE_LAT_CACHE_LINE_SIZE_REG; /**< Header Type, Latency Timer, and Cache Line Size Register., offset: 0xC */
       uint8_t RESERVED_0[8];
  __IO uint32_t SEC_LAT_TIMER_SUB_BUS_SEC_BUS_PRI_BUS_REG; /**< Secondary Latency Timer, Subordinate Bus Number, Secondary Bus Number, and Primary Bus Number Register., offset: 0x18 */
  __IO uint32_t SEC_STAT_IO_LIMIT_IO_BASE_REG;     /**< Secondary Status, and I/O Limit and Base Register., offset: 0x1C */
  __IO uint32_t MEM_LIMIT_MEM_BASE_REG;            /**< Memory Limit and Base Register., offset: 0x20 */
  __IO uint32_t PREF_MEM_LIMIT_PREF_MEM_BASE_REG;  /**< Prefetchable Memory Limit and Base Register., offset: 0x24 */
  __I  uint32_t PREF_BASE_UPPER_REG;               /**< Prefetchable Base Upper 32 Bits Register., offset: 0x28 */
  __I  uint32_t PREF_LIMIT_UPPER_REG;              /**< Prefetchable Limit Upper 32 Bits Register., offset: 0x2C */
  __I  uint32_t IO_LIMIT_UPPER_IO_BASE_UPPER_REG;  /**< I/O Limit and Base Upper 16 Bits Register., offset: 0x30 */
  __IO uint32_t TYPE1_CAP_PTR_REG;                 /**< Capabilities Pointer Register., offset: 0x34 */
  __IO uint32_t TYPE1_EXP_ROM_BASE_REG;            /**< Expansion ROM Base Address Register., offset: 0x38 */
  __IO uint32_t BRIDGE_CTRL_INT_PIN_INT_LINE_REG;  /**< Bridge Control, Interrupt Pin, and Interrupt Line Register., offset: 0x3C */
  __IO uint32_t CAP_ID_NXT_PTR_REG;                /**< Power Management Capabilities Register., offset: 0x40 */
  __IO uint32_t CON_STATUS_REG;                    /**< Power Management Control and Status Register., offset: 0x44 */
       uint8_t RESERVED_1[8];
  __IO uint32_t PCI_MSI_CAP_ID_NEXT_CTRL_REG;      /**< MSI Capability ID, Next Pointer, Capability/Control Registers., offset: 0x50 */
  __IO uint32_t MSI_CAP_OFF_04H_REG;               /**< MSI Message Lower Address Register., offset: 0x54 */
  __IO uint32_t MSI_CAP_OFF_08H_REG;               /**< For a 32 bit MSI Message, this register contains Data., offset: 0x58 */
  __IO uint32_t MSI_CAP_OFF_0CH_REG;               /**< For a 64 bit MSI Message, this register contains Data., offset: 0x5C */
  __IO uint32_t MSI_CAP_OFF_10H_REG;               /**< Used for MSI when Vector Masking Capable., offset: 0x60 */
  __I  uint32_t MSI_CAP_OFF_14H_REG;               /**< Used for MSI 64 bit messaging when Vector Masking Capable., offset: 0x64 */
       uint8_t RESERVED_2[8];
  __IO uint32_t PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG; /**< PCI Express Capabilities, ID, Next Pointer Register., offset: 0x70 */
  __IO uint32_t DEVICE_CAPABILITIES_REG;           /**< Device Capabilities Register., offset: 0x74 */
  __IO uint32_t DEVICE_CONTROL_DEVICE_STATUS;      /**< Device Control and Status Register., offset: 0x78 */
  __IO uint32_t LINK_CAPABILITIES_REG;             /**< Link Capabilities Register., offset: 0x7C */
  __IO uint32_t LINK_CONTROL_LINK_STATUS_REG;      /**< Link Control and Status Register., offset: 0x80 */
  __IO uint32_t SLOT_CAPABILITIES_REG;             /**< Slot Capabilities Register., offset: 0x84 */
  __IO uint32_t SLOT_CONTROL_SLOT_STATUS;          /**< Slot Control and Status Register., offset: 0x88 */
  __IO uint32_t ROOT_CONTROL_ROOT_CAPABILITIES_REG; /**< Root Control and Capabilities Register., offset: 0x8C */
  __IO uint32_t ROOT_STATUS_REG;                   /**< Root Status Register., offset: 0x90 */
  __I  uint32_t DEVICE_CAPABILITIES2_REG;          /**< Device Capabilities 2 Register., offset: 0x94 */
  __IO uint32_t DEVICE_CONTROL2_DEVICE_STATUS2_REG; /**< Device Control 2 and Status 2 Register., offset: 0x98 */
  __I  uint32_t LINK_CAPABILITIES2_REG;            /**< Link Capabilities 2 Register., offset: 0x9C */
  __IO uint32_t LINK_CONTROL2_LINK_STATUS2_REG;    /**< Link Control 2 and Status 2 Register., offset: 0xA0 */
       uint8_t RESERVED_3[92];
  __IO uint32_t AER_EXT_CAP_HDR_OFF;               /**< Advanced Error Reporting Extended Capability Header., offset: 0x100 */
  __IO uint32_t UNCORR_ERR_STATUS_OFF;             /**< Uncorrectable Error Status Register., offset: 0x104 */
  __IO uint32_t UNCORR_ERR_MASK_OFF;               /**< Uncorrectable Error Mask Register., offset: 0x108 */
  __IO uint32_t UNCORR_ERR_SEV_OFF;                /**< Uncorrectable Error Severity Register., offset: 0x10C */
  __IO uint32_t CORR_ERR_STATUS_OFF;               /**< Correctable Error Status Register., offset: 0x110 */
  __IO uint32_t CORR_ERR_MASK_OFF;                 /**< Correctable Error Mask Register., offset: 0x114 */
  __IO uint32_t ADV_ERR_CAP_CTRL_OFF;              /**< Advanced Error Capabilities and Control Register., offset: 0x118 */
  __I  uint32_t HDR_LOG_0_OFF;                     /**< Header Log Register 0., offset: 0x11C */
  __I  uint32_t HDR_LOG_1_OFF;                     /**< Header Log Register 1., offset: 0x120 */
  __I  uint32_t HDR_LOG_2_OFF;                     /**< Header Log Register 2., offset: 0x124 */
  __I  uint32_t HDR_LOG_3_OFF;                     /**< Header Log Register 3., offset: 0x128 */
  __IO uint32_t ROOT_ERR_CMD_OFF;                  /**< Root Error Command Register., offset: 0x12C */
  __IO uint32_t ROOT_ERR_STATUS_OFF;               /**< Root Error Status Register., offset: 0x130 */
  __I  uint32_t ERR_SRC_ID_OFF;                    /**< Error Source Identification Register., offset: 0x134 */
  __I  uint32_t TLP_PREFIX_LOG_1_OFF;              /**< TLP Prefix Log Register 1., offset: 0x138 */
  __I  uint32_t TLP_PREFIX_LOG_2_OFF;              /**< TLP Prefix Log Register 2., offset: 0x13C */
  __I  uint32_t TLP_PREFIX_LOG_3_OFF;              /**< TLP Prefix Log Register 3., offset: 0x140 */
  __I  uint32_t TLP_PREFIX_LOG_4_OFF;              /**< TLP Prefix Log Register 4., offset: 0x144 */
       uint8_t RESERVED_4[16];
  __IO uint32_t L1SUB_CAP_HEADER_REG;              /**< L1 Substates Extended Capability Header., offset: 0x158 */
  __IO uint32_t L1SUB_CAPABILITY_REG;              /**< L1 Substates Capability Register., offset: 0x15C */
  __IO uint32_t L1SUB_CONTROL1_REG;                /**< L1 Substates Control 1 Register., offset: 0x160 */
  __IO uint32_t L1SUB_CONTROL2_REG;                /**< L1 Substates Control 2 Register., offset: 0x164 */
       uint8_t RESERVED_5[1432];
  __IO uint32_t ACK_LATENCY_TIMER_OFF;             /**< Ack Latency Timer and Replay Timer Register., offset: 0x700 */
  __IO uint32_t VENDOR_SPEC_DLLP_OFF;              /**< Vendor Specific DLLP Register., offset: 0x704 */
  __IO uint32_t PORT_FORCE_OFF;                    /**< Port Force Link Register., offset: 0x708 */
  __IO uint32_t ACK_F_ASPM_CTRL_OFF;               /**< Ack Frequency and L0-L1 ASPM Control Register., offset: 0x70C */
  __IO uint32_t PORT_LINK_CTRL_OFF;                /**< Port Link Control Register., offset: 0x710 */
  __IO uint32_t LANE_SKEW_OFF;                     /**< Lane Skew Register., offset: 0x714 */
  __IO uint32_t TIMER_CTRL_MAX_FUNC_NUM_OFF;       /**< Timer Control and Max Function Number Register., offset: 0x718 */
  __IO uint32_t SYMBOL_TIMER_FILTER_1_OFF;         /**< Symbol Timer Register and Filter Mask 1 Register., offset: 0x71C */
  __IO uint32_t FILTER_MASK_2_OFF;                 /**< Filter Mask 2 Register., offset: 0x720 */
  __IO uint32_t AMBA_MUL_OB_DECOMP_NP_SUB_REQ_CTRL_OFF; /**< AMBA Multiple Outbound Decomposed NP SubRequests Control Register., offset: 0x724 */
  __I  uint32_t PL_DEBUG0_OFF;                     /**< Debug Register 0, offset: 0x728 */
  __I  uint32_t PL_DEBUG1_OFF;                     /**< Debug Register 1, offset: 0x72C */
  __I  uint32_t TX_P_FC_CREDIT_STATUS_OFF;         /**< Transmit Posted FC Credit Status, offset: 0x730 */
  __I  uint32_t TX_NP_FC_CREDIT_STATUS_OFF;        /**< Transmit Non-Posted FC Credit Status, offset: 0x734 */
  __I  uint32_t TX_CPL_FC_CREDIT_STATUS_OFF;       /**< Transmit Completion FC Credit Status, offset: 0x738 */
  __IO uint32_t QUEUE_STATUS_OFF;                  /**< Queue Status, offset: 0x73C */
  __I  uint32_t VC_TX_ARBI_1_OFF;                  /**< VC Transmit Arbitration Register 1, offset: 0x740 */
       uint8_t RESERVED_6[4];
  __IO uint32_t VC0_P_RX_Q_CTRL_OFF;               /**< Segmented-Buffer VC0 Posted Receive Queue Control., offset: 0x748 */
  __IO uint32_t VC0_NP_RX_Q_CTRL_OFF;              /**< Segmented-Buffer VC0 Non-Posted Receive Queue Control., offset: 0x74C */
  __IO uint32_t VC0_CPL_RX_Q_CTRL_OFF;             /**< Segmented-Buffer VC0 Completion Receive Queue Control., offset: 0x750 */
       uint8_t RESERVED_7[184];
  __IO uint32_t GEN2_CTRL_OFF;                     /**< Link Width and Speed Change Control Register., offset: 0x80C */
  __I  uint32_t PHY_STATUS_OFF;                    /**< PHY Status Register., offset: 0x810 */
  __IO uint32_t PHY_CONTROL_OFF;                   /**< PHY Control Register., offset: 0x814 */
       uint8_t RESERVED_8[4];
  __IO uint32_t TRGT_MAP_CTRL_OFF;                 /**< Programmable Target Map Control Register., offset: 0x81C */
  __IO uint32_t MSI_CTRL_ADDR_OFF;                 /**< Integrated MSI Reception Module (iMRM) Address Register., offset: 0x820 */
  __IO uint32_t MSI_CTRL_UPPER_ADDR_OFF;           /**< Integrated MSI Reception Module Upper Address Register., offset: 0x824 */
  __IO uint32_t MSI_CTRL_INT_0_EN_OFF;             /**< Integrated MSI Reception Module Interrupt#i Enable Register., offset: 0x828 */
  __IO uint32_t MSI_CTRL_INT_0_MASK_OFF;           /**< Integrated MSI Reception Module Interrupt#i Mask Register., offset: 0x82C */
  __IO uint32_t MSI_CTRL_INT_0_STATUS_OFF;         /**< Integrated MSI Reception Module Interrupt#i Status Register., offset: 0x830 */
  __IO uint32_t MSI_CTRL_INT_1_EN_OFF;             /**< Integrated MSI Reception Module Interrupt#i Enable Register., offset: 0x834 */
  __IO uint32_t MSI_CTRL_INT_1_MASK_OFF;           /**< Integrated MSI Reception Module Interrupt#i Mask Register., offset: 0x838 */
  __IO uint32_t MSI_CTRL_INT_1_STATUS_OFF;         /**< Integrated MSI Reception Module Interrupt#i Status Register., offset: 0x83C */
  __IO uint32_t MSI_CTRL_INT_2_EN_OFF;             /**< Integrated MSI Reception Module Interrupt#i Enable Register., offset: 0x840 */
  __IO uint32_t MSI_CTRL_INT_2_MASK_OFF;           /**< Integrated MSI Reception Module Interrupt#i Mask Register., offset: 0x844 */
  __IO uint32_t MSI_CTRL_INT_2_STATUS_OFF;         /**< Integrated MSI Reception Module Interrupt#i Status Register., offset: 0x848 */
  __IO uint32_t MSI_CTRL_INT_3_EN_OFF;             /**< Integrated MSI Reception Module Interrupt#i Enable Register., offset: 0x84C */
  __IO uint32_t MSI_CTRL_INT_3_MASK_OFF;           /**< Integrated MSI Reception Module Interrupt#i Mask Register., offset: 0x850 */
  __IO uint32_t MSI_CTRL_INT_3_STATUS_OFF;         /**< Integrated MSI Reception Module Interrupt#i Status Register., offset: 0x854 */
  __IO uint32_t MSI_CTRL_INT_4_EN_OFF;             /**< Integrated MSI Reception Module Interrupt#i Enable Register., offset: 0x858 */
  __IO uint32_t MSI_CTRL_INT_4_MASK_OFF;           /**< Integrated MSI Reception Module Interrupt#i Mask Register., offset: 0x85C */
  __IO uint32_t MSI_CTRL_INT_4_STATUS_OFF;         /**< Integrated MSI Reception Module Interrupt#i Status Register., offset: 0x860 */
  __IO uint32_t MSI_CTRL_INT_5_EN_OFF;             /**< Integrated MSI Reception Module Interrupt#i Enable Register., offset: 0x864 */
  __IO uint32_t MSI_CTRL_INT_5_MASK_OFF;           /**< Integrated MSI Reception Module Interrupt#i Mask Register., offset: 0x868 */
  __IO uint32_t MSI_CTRL_INT_5_STATUS_OFF;         /**< Integrated MSI Reception Module Interrupt#i Status Register., offset: 0x86C */
  __IO uint32_t MSI_CTRL_INT_6_EN_OFF;             /**< Integrated MSI Reception Module Interrupt#i Enable Register., offset: 0x870 */
  __IO uint32_t MSI_CTRL_INT_6_MASK_OFF;           /**< Integrated MSI Reception Module Interrupt#i Mask Register., offset: 0x874 */
  __IO uint32_t MSI_CTRL_INT_6_STATUS_OFF;         /**< Integrated MSI Reception Module Interrupt#i Status Register., offset: 0x878 */
  __IO uint32_t MSI_CTRL_INT_7_EN_OFF;             /**< Integrated MSI Reception Module Interrupt#i Enable Register., offset: 0x87C */
  __IO uint32_t MSI_CTRL_INT_7_MASK_OFF;           /**< Integrated MSI Reception Module Interrupt#i Mask Register., offset: 0x880 */
  __IO uint32_t MSI_CTRL_INT_7_STATUS_OFF;         /**< Integrated MSI Reception Module Interrupt#i Status Register., offset: 0x884 */
  __IO uint32_t MSI_GPIO_IO_OFF;                   /**< Integrated MSI Reception Module General Purpose IO Register., offset: 0x888 */
  __IO uint32_t CLOCK_GATING_CTRL_OFF;             /**< RADM clock gating enable control register., offset: 0x88C */
       uint8_t RESERVED_9[36];
  __IO uint32_t ORDER_RULE_CTRL_OFF;               /**< Order Rule Control Register., offset: 0x8B4 */
  __IO uint32_t PIPE_LOOPBACK_CONTROL_OFF;         /**< PIPE Loopback Control Register., offset: 0x8B8 */
  __IO uint32_t MISC_CONTROL_1_OFF;                /**< DBI Read-Only Write Enable Register., offset: 0x8BC */
  __IO uint32_t MULTI_LANE_CONTROL_OFF;            /**< UpConfigure Multi-lane Control Register., offset: 0x8C0 */
  __IO uint32_t PHY_INTEROP_CTRL_OFF;              /**< PHY Interoperability Control Register., offset: 0x8C4 */
  __IO uint32_t TRGT_CPL_LUT_DELETE_ENTRY_OFF;     /**< TRGT_CPL_LUT Delete Entry Control register., offset: 0x8C8 */
  __IO uint32_t LINK_FLUSH_CONTROL_OFF;            /**< Link Reset Request Flush Control Register., offset: 0x8CC */
  __IO uint32_t AMBA_ERROR_RESPONSE_DEFAULT_OFF;   /**< AXI Bridge Slave Error Response Register., offset: 0x8D0 */
  __IO uint32_t AMBA_LINK_TIMEOUT_OFF;             /**< Link Down AXI Bridge Slave Timeout Register., offset: 0x8D4 */
  __IO uint32_t AMBA_ORDERING_CTRL_OFF;            /**< AMBA Ordering Control., offset: 0x8D8 */
       uint8_t RESERVED_10[20];
  __IO uint32_t AXI_MSTR_MSG_ADDR_LOW_OFF;         /**< Lower 20 bits of the programmable AXI address where Messages coming from wire are mapped to., offset: 0x8F0 */
  __IO uint32_t AXI_MSTR_MSG_ADDR_HIGH_OFF;        /**< Upper 32 bits of the programmable AXI address where Messages coming from wire are mapped to., offset: 0x8F4 */
  __I  uint32_t PCIE_VERSION_NUMBER_OFF;           /**< PCIe Controller IIP Release Version Number., offset: 0x8F8 */
  __I  uint32_t PCIE_VERSION_TYPE_OFF;             /**< PCIe Controller IIP Release Version Type., offset: 0x8FC */
       uint8_t RESERVED_11[576];
  __IO uint32_t AUX_CLK_FREQ_OFF;                  /**< Auxiliary Clock Frequency Control Register., offset: 0xB40 */
  __IO uint32_t L1_SUBSTATES_OFF;                  /**< L1 Substates Timing Register., offset: 0xB44 */
       uint8_t RESERVED_12[3142840];
  __IO uint32_t IATU_REGION_CTRL_1_OFF_OUTBOUND_0; /**< iATU Region Control 1 Register., offset: 0x300000 */
  __IO uint32_t IATU_REGION_CTRL_2_OFF_OUTBOUND_0; /**< iATU Region Control 2 Register., offset: 0x300004 */
  __IO uint32_t IATU_LWR_BASE_ADDR_OFF_OUTBOUND_0; /**< iATU Lower Base Address Register., offset: 0x300008 */
  __IO uint32_t IATU_UPPER_BASE_ADDR_OFF_OUTBOUND_0; /**< iATU Upper Base Address Register., offset: 0x30000C */
  __IO uint32_t IATU_LIMIT_ADDR_OFF_OUTBOUND_0;    /**< iATU Limit Address Register., offset: 0x300010 */
  __IO uint32_t IATU_LWR_TARGET_ADDR_OFF_OUTBOUND_0; /**< iATU Lower Target Address Register., offset: 0x300014 */
  __IO uint32_t IATU_UPPER_TARGET_ADDR_OFF_OUTBOUND_0; /**< iATU Upper Target Address Register., offset: 0x300018 */
       uint8_t RESERVED_13[228];
  __IO uint32_t IATU_REGION_CTRL_1_OFF_INBOUND_0;  /**< iATU Region Control 1 Register., offset: 0x300100 */
  __IO uint32_t IATU_REGION_CTRL_2_OFF_INBOUND_0;  /**< iATU Region Control 2 Register., offset: 0x300104 */
  __IO uint32_t IATU_LWR_BASE_ADDR_OFF_INBOUND_0;  /**< iATU Lower Base Address Register., offset: 0x300108 */
  __IO uint32_t IATU_UPPER_BASE_ADDR_OFF_INBOUND_0; /**< iATU Upper Base Address Register., offset: 0x30010C */
  __IO uint32_t IATU_LIMIT_ADDR_OFF_INBOUND_0;     /**< iATU Limit Address Register., offset: 0x300110 */
  __IO uint32_t IATU_LWR_TARGET_ADDR_OFF_INBOUND_0; /**< iATU Lower Target Address Register., offset: 0x300114 */
       uint8_t RESERVED_14[232];
  __IO uint32_t IATU_REGION_CTRL_1_OFF_OUTBOUND_1; /**< iATU Region Control 1 Register., offset: 0x300200 */
  __IO uint32_t IATU_REGION_CTRL_2_OFF_OUTBOUND_1; /**< iATU Region Control 2 Register., offset: 0x300204 */
  __IO uint32_t IATU_LWR_BASE_ADDR_OFF_OUTBOUND_1; /**< iATU Lower Base Address Register., offset: 0x300208 */
  __IO uint32_t IATU_UPPER_BASE_ADDR_OFF_OUTBOUND_1; /**< iATU Upper Base Address Register., offset: 0x30020C */
  __IO uint32_t IATU_LIMIT_ADDR_OFF_OUTBOUND_1;    /**< iATU Limit Address Register., offset: 0x300210 */
  __IO uint32_t IATU_LWR_TARGET_ADDR_OFF_OUTBOUND_1; /**< iATU Lower Target Address Register., offset: 0x300214 */
  __IO uint32_t IATU_UPPER_TARGET_ADDR_OFF_OUTBOUND_1; /**< iATU Upper Target Address Register., offset: 0x300218 */
       uint8_t RESERVED_15[228];
  __IO uint32_t IATU_REGION_CTRL_1_OFF_INBOUND_1;  /**< iATU Region Control 1 Register., offset: 0x300300 */
  __IO uint32_t IATU_REGION_CTRL_2_OFF_INBOUND_1;  /**< iATU Region Control 2 Register., offset: 0x300304 */
  __IO uint32_t IATU_LWR_BASE_ADDR_OFF_INBOUND_1;  /**< iATU Lower Base Address Register., offset: 0x300308 */
  __IO uint32_t IATU_UPPER_BASE_ADDR_OFF_INBOUND_1; /**< iATU Upper Base Address Register., offset: 0x30030C */
  __IO uint32_t IATU_LIMIT_ADDR_OFF_INBOUND_1;     /**< iATU Limit Address Register., offset: 0x300310 */
  __IO uint32_t IATU_LWR_TARGET_ADDR_OFF_INBOUND_1; /**< iATU Lower Target Address Register., offset: 0x300314 */
       uint8_t RESERVED_16[232];
  __IO uint32_t IATU_REGION_CTRL_1_OFF_OUTBOUND_2; /**< iATU Region Control 1 Register., offset: 0x300400 */
  __IO uint32_t IATU_REGION_CTRL_2_OFF_OUTBOUND_2; /**< iATU Region Control 2 Register., offset: 0x300404 */
  __IO uint32_t IATU_LWR_BASE_ADDR_OFF_OUTBOUND_2; /**< iATU Lower Base Address Register., offset: 0x300408 */
  __IO uint32_t IATU_UPPER_BASE_ADDR_OFF_OUTBOUND_2; /**< iATU Upper Base Address Register., offset: 0x30040C */
  __IO uint32_t IATU_LIMIT_ADDR_OFF_OUTBOUND_2;    /**< iATU Limit Address Register., offset: 0x300410 */
  __IO uint32_t IATU_LWR_TARGET_ADDR_OFF_OUTBOUND_2; /**< iATU Lower Target Address Register., offset: 0x300414 */
  __IO uint32_t IATU_UPPER_TARGET_ADDR_OFF_OUTBOUND_2; /**< iATU Upper Target Address Register., offset: 0x300418 */
       uint8_t RESERVED_17[228];
  __IO uint32_t IATU_REGION_CTRL_1_OFF_INBOUND_2;  /**< iATU Region Control 1 Register., offset: 0x300500 */
  __IO uint32_t IATU_REGION_CTRL_2_OFF_INBOUND_2;  /**< iATU Region Control 2 Register., offset: 0x300504 */
  __IO uint32_t IATU_LWR_BASE_ADDR_OFF_INBOUND_2;  /**< iATU Lower Base Address Register., offset: 0x300508 */
  __IO uint32_t IATU_UPPER_BASE_ADDR_OFF_INBOUND_2; /**< iATU Upper Base Address Register., offset: 0x30050C */
  __IO uint32_t IATU_LIMIT_ADDR_OFF_INBOUND_2;     /**< iATU Limit Address Register., offset: 0x300510 */
  __IO uint32_t IATU_LWR_TARGET_ADDR_OFF_INBOUND_2; /**< iATU Lower Target Address Register., offset: 0x300514 */
       uint8_t RESERVED_18[232];
  __IO uint32_t IATU_REGION_CTRL_1_OFF_OUTBOUND_3; /**< iATU Region Control 1 Register., offset: 0x300600 */
  __IO uint32_t IATU_REGION_CTRL_2_OFF_OUTBOUND_3; /**< iATU Region Control 2 Register., offset: 0x300604 */
  __IO uint32_t IATU_LWR_BASE_ADDR_OFF_OUTBOUND_3; /**< iATU Lower Base Address Register., offset: 0x300608 */
  __IO uint32_t IATU_UPPER_BASE_ADDR_OFF_OUTBOUND_3; /**< iATU Upper Base Address Register., offset: 0x30060C */
  __IO uint32_t IATU_LIMIT_ADDR_OFF_OUTBOUND_3;    /**< iATU Limit Address Register., offset: 0x300610 */
  __IO uint32_t IATU_LWR_TARGET_ADDR_OFF_OUTBOUND_3; /**< iATU Lower Target Address Register., offset: 0x300614 */
  __IO uint32_t IATU_UPPER_TARGET_ADDR_OFF_OUTBOUND_3; /**< iATU Upper Target Address Register., offset: 0x300618 */
       uint8_t RESERVED_19[228];
  __IO uint32_t IATU_REGION_CTRL_1_OFF_INBOUND_3;  /**< iATU Region Control 1 Register., offset: 0x300700 */
  __IO uint32_t IATU_REGION_CTRL_2_OFF_INBOUND_3;  /**< iATU Region Control 2 Register., offset: 0x300704 */
  __IO uint32_t IATU_LWR_BASE_ADDR_OFF_INBOUND_3;  /**< iATU Lower Base Address Register., offset: 0x300708 */
  __IO uint32_t IATU_UPPER_BASE_ADDR_OFF_INBOUND_3; /**< iATU Upper Base Address Register., offset: 0x30070C */
  __IO uint32_t IATU_LIMIT_ADDR_OFF_INBOUND_3;     /**< iATU Limit Address Register., offset: 0x300710 */
  __IO uint32_t IATU_LWR_TARGET_ADDR_OFF_INBOUND_3; /**< iATU Lower Target Address Register., offset: 0x300714 */
       uint8_t RESERVED_20[522472];
  __IO uint32_t DMA_CTRL_DATA_ARB_PRIOR_OFF;       /**< DMA Arbitration Scheme for TRGT1 Interface., offset: 0x380000 */
       uint8_t RESERVED_21[4];
  __IO uint32_t DMA_CTRL_OFF;                      /**< DMA Number of Channels Register., offset: 0x380008 */
  __IO uint32_t DMA_WRITE_ENGINE_EN_OFF;           /**< DMA Write Engine Enable Register., offset: 0x38000C */
  __IO uint32_t DMA_WRITE_DOORBELL_OFF;            /**< DMA Write Doorbell Register., offset: 0x380010 */
       uint8_t RESERVED_22[4];
  __IO uint32_t DMA_WRITE_CHANNEL_ARB_WEIGHT_LOW_OFF; /**< DMA Write Engine Channel Arbitration Weight Low Register., offset: 0x380018 */
  __IO uint32_t DMA_WRITE_CHANNEL_ARB_WEIGHT_HIGH_OFF; /**< DMA Write Engine Channel Arbitration Weight High Register., offset: 0x38001C */
       uint8_t RESERVED_23[12];
  __IO uint32_t DMA_READ_ENGINE_EN_OFF;            /**< DMA Read Engine Enable Register., offset: 0x38002C */
  __IO uint32_t DMA_READ_DOORBELL_OFF;             /**< DMA Read Doorbell Register., offset: 0x380030 */
       uint8_t RESERVED_24[4];
  __IO uint32_t DMA_READ_CHANNEL_ARB_WEIGHT_LOW_OFF; /**< DMA Read Engine Channel Arbitration Weight Low Register., offset: 0x380038 */
  __IO uint32_t DMA_READ_CHANNEL_ARB_WEIGHT_HIGH_OFF; /**< DMA Read Engine Channel Arbitration Weight High Register., offset: 0x38003C */
       uint8_t RESERVED_25[12];
  __IO uint32_t DMA_WRITE_INT_STATUS_OFF;          /**< DMA Write Interrupt Status Register., offset: 0x38004C */
       uint8_t RESERVED_26[4];
  __IO uint32_t DMA_WRITE_INT_MASK_OFF;            /**< DMA Write Interrupt Mask Register., offset: 0x380054 */
  __IO uint32_t DMA_WRITE_INT_CLEAR_OFF;           /**< DMA Write Interrupt Clear Register., offset: 0x380058 */
  __I  uint32_t DMA_WRITE_ERR_STATUS_OFF;          /**< DMA Write Error Status Register, offset: 0x38005C */
  __IO uint32_t DMA_WRITE_DONE_IMWR_LOW_OFF;       /**< DMA Write Done IMWr Address Low Register., offset: 0x380060 */
  __IO uint32_t DMA_WRITE_DONE_IMWR_HIGH_OFF;      /**< DMA Write Done IMWr Interrupt Address High Register., offset: 0x380064 */
  __IO uint32_t DMA_WRITE_ABORT_IMWR_LOW_OFF;      /**< DMA Write Abort IMWr Address Low Register., offset: 0x380068 */
  __IO uint32_t DMA_WRITE_ABORT_IMWR_HIGH_OFF;     /**< DMA Write Abort IMWr Address High Register., offset: 0x38006C */
  __IO uint32_t DMA_WRITE_CH01_IMWR_DATA_OFF;      /**< DMA Write Channel 1 and 0 IMWr Data Register., offset: 0x380070 */
  __IO uint32_t DMA_WRITE_CH23_IMWR_DATA_OFF;      /**< DMA Write Channel 3 and 2 IMWr Data Register., offset: 0x380074 */
  __IO uint32_t DMA_WRITE_CH45_IMWR_DATA_OFF;      /**< DMA Write Channel 5 and 4 IMWr Data Register., offset: 0x380078 */
  __IO uint32_t DMA_WRITE_CH67_IMWR_DATA_OFF;      /**< DMA Write Channel 7 and 6 IMWr Data Register., offset: 0x38007C */
       uint8_t RESERVED_27[16];
  __IO uint32_t DMA_WRITE_LINKED_LIST_ERR_EN_OFF;  /**< DMA Write Linked List Error Enable Register., offset: 0x380090 */
       uint8_t RESERVED_28[12];
  __IO uint32_t DMA_READ_INT_STATUS_OFF;           /**< DMA Read Interrupt Status Register., offset: 0x3800A0 */
       uint8_t RESERVED_29[4];
  __IO uint32_t DMA_READ_INT_MASK_OFF;             /**< DMA Read Interrupt Mask Register., offset: 0x3800A8 */
  __IO uint32_t DMA_READ_INT_CLEAR_OFF;            /**< DMA Read Interrupt Clear Register., offset: 0x3800AC */
       uint8_t RESERVED_30[4];
  __I  uint32_t DMA_READ_ERR_STATUS_LOW_OFF;       /**< DMA Read Error Status Low Register., offset: 0x3800B4 */
  __I  uint32_t DMA_READ_ERR_STATUS_HIGH_OFF;      /**< DMA Read Error Status High Register., offset: 0x3800B8 */
       uint8_t RESERVED_31[8];
  __IO uint32_t DMA_READ_LINKED_LIST_ERR_EN_OFF;   /**< DMA Read Linked List Error Enable Register., offset: 0x3800C4 */
       uint8_t RESERVED_32[4];
  __IO uint32_t DMA_READ_DONE_IMWR_LOW_OFF;        /**< DMA Read Done IMWr Address Low Register., offset: 0x3800CC */
  __IO uint32_t DMA_READ_DONE_IMWR_HIGH_OFF;       /**< DMA Read Done IMWr Address High Register., offset: 0x3800D0 */
  __IO uint32_t DMA_READ_ABORT_IMWR_LOW_OFF;       /**< DMA Read Abort IMWr Address Low Register., offset: 0x3800D4 */
  __IO uint32_t DMA_READ_ABORT_IMWR_HIGH_OFF;      /**< DMA Read Abort IMWr Address High Register., offset: 0x3800D8 */
  __IO uint32_t DMA_READ_CH01_IMWR_DATA_OFF;       /**< DMA Read Channel 1 and 0 IMWr Data Register., offset: 0x3800DC */
  __IO uint32_t DMA_READ_CH23_IMWR_DATA_OFF;       /**< DMA Read Channel 3 and 2 IMWr Data Register., offset: 0x3800E0 */
  __IO uint32_t DMA_READ_CH45_IMWR_DATA_OFF;       /**< DMA Read Channel 5 and 4 IMWr Data Register., offset: 0x3800E4 */
  __IO uint32_t DMA_READ_CH67_IMWR_DATA_OFF;       /**< DMA Read Channel 7 and 6 IMWr Data Register., offset: 0x3800E8 */
       uint8_t RESERVED_33[276];
  __IO uint32_t DMA_CH_CONTROL1_OFF_WRCH_0;        /**< DMA Write Channel Control 1 Register., offset: 0x380200 */
       uint8_t RESERVED_34[4];
  __IO uint32_t DMA_TRANSFER_SIZE_OFF_WRCH_0;      /**< DMA Write Transfer Size Register., offset: 0x380208 */
  __IO uint32_t DMA_SAR_LOW_OFF_WRCH_0;            /**< DMA Write SAR Low Register., offset: 0x38020C */
  __IO uint32_t DMA_SAR_HIGH_OFF_WRCH_0;           /**< DMA Write SAR High Register., offset: 0x380210 */
  __IO uint32_t DMA_DAR_LOW_OFF_WRCH_0;            /**< DMA Write DAR Low Register., offset: 0x380214 */
  __IO uint32_t DMA_DAR_HIGH_OFF_WRCH_0;           /**< DMA Write DAR High Register., offset: 0x380218 */
  __IO uint32_t DMA_LLP_LOW_OFF_WRCH_0;            /**< DMA Write Linked List Pointer Low Register., offset: 0x38021C */
  __IO uint32_t DMA_LLP_HIGH_OFF_WRCH_0;           /**< DMA Write Linked List Pointer High Register., offset: 0x380220 */
       uint8_t RESERVED_35[220];
  __IO uint32_t DMA_CH_CONTROL1_OFF_RDCH_0;        /**< DMA Read Channel Control 1 Register., offset: 0x380300 */
       uint8_t RESERVED_36[4];
  __IO uint32_t DMA_TRANSFER_SIZE_OFF_RDCH_0;      /**< DMA Read Transfer Size Register., offset: 0x380308 */
  __IO uint32_t DMA_SAR_LOW_OFF_RDCH_0;            /**< DMA Read SAR Low Register., offset: 0x38030C */
  __IO uint32_t DMA_SAR_HIGH_OFF_RDCH_0;           /**< DMA Read SAR High Register., offset: 0x380310 */
  __IO uint32_t DMA_DAR_LOW_OFF_RDCH_0;            /**< DMA Read DAR Low Register., offset: 0x380314 */
  __IO uint32_t DMA_DAR_HIGH_OFF_RDCH_0;           /**< DMA Read DAR High Register., offset: 0x380318 */
  __IO uint32_t DMA_LLP_LOW_OFF_RDCH_0;            /**< DMA Read Linked List Pointer Low Register., offset: 0x38031C */
  __IO uint32_t DMA_LLP_HIGH_OFF_RDCH_0;           /**< DMA Read Linked List Pointer High Register., offset: 0x380320 */
} PCIE_Type;

/* ----------------------------------------------------------------------------
   -- PCIE Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PCIE_Register_Masks PCIE Register Masks
 * @{
 */

/*! @name TYPE1_DEV_ID_VEND_ID_REG - Device ID and Vendor ID Register. */
/*! @{ */

#define PCIE_TYPE1_DEV_ID_VEND_ID_REG_VENDOR_ID_MASK (0xFFFFU)
#define PCIE_TYPE1_DEV_ID_VEND_ID_REG_VENDOR_ID_SHIFT (0U)
/*! VENDOR_ID - Vendor ID. The Vendor ID register identifies the manufacturer of the Function. Valid
 *    vendor identifiers are allocated by the PCI-SIG to ensure uniqueness. It is not permitted to
 *    populate this register with a value of FFFFh, which is an invalid value for Vendor ID. Note:
 *    The access attributes of this field are as follows: - Dbi: if (DBI_RO_WR_EN == 1) then
 *    R/W(sticky) else R(sticky) Note: This register field is sticky.
 */
#define PCIE_TYPE1_DEV_ID_VEND_ID_REG_VENDOR_ID(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TYPE1_DEV_ID_VEND_ID_REG_VENDOR_ID_SHIFT)) & PCIE_TYPE1_DEV_ID_VEND_ID_REG_VENDOR_ID_MASK)

#define PCIE_TYPE1_DEV_ID_VEND_ID_REG_DEVICE_ID_MASK (0xFFFF0000U)
#define PCIE_TYPE1_DEV_ID_VEND_ID_REG_DEVICE_ID_SHIFT (16U)
/*! DEVICE_ID - Device ID. The Device ID register identifies the particular Function. This
 *    identifier is allocated by the vendor. Note: The access attributes of this field are as follows: - Dbi:
 *    if (DBI_RO_WR_EN == 1) then R/W(sticky) else R(sticky) Note: This register field is sticky.
 */
#define PCIE_TYPE1_DEV_ID_VEND_ID_REG_DEVICE_ID(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TYPE1_DEV_ID_VEND_ID_REG_DEVICE_ID_SHIFT)) & PCIE_TYPE1_DEV_ID_VEND_ID_REG_DEVICE_ID_MASK)
/*! @} */

/*! @name TYPE1_STATUS_COMMAND_REG - Status and Command Register. */
/*! @{ */

#define PCIE_TYPE1_STATUS_COMMAND_REG_IO_EN_MASK (0x1U)
#define PCIE_TYPE1_STATUS_COMMAND_REG_IO_EN_SHIFT (0U)
/*! IO_EN - IO Space Enable. This bit controls a Function's response to I/O Space accesses received
 *    on its primary side. - When set, the Function is enabled to decode the address and further
 *    process I/O Space accesses. - When clear, all received I/O accesses are caused to be handled as
 *    Unsupported Requests. You cannot write to this register if your configuration has no IO bars;
 *    that is, the internal signal has_io_bar =0. Note: The access attributes of this field are as
 *    follows: - Dbi: !has_io_bar ? RO : RW
 */
#define PCIE_TYPE1_STATUS_COMMAND_REG_IO_EN(x)   (((uint32_t)(((uint32_t)(x)) << PCIE_TYPE1_STATUS_COMMAND_REG_IO_EN_SHIFT)) & PCIE_TYPE1_STATUS_COMMAND_REG_IO_EN_MASK)

#define PCIE_TYPE1_STATUS_COMMAND_REG_MSE_MASK   (0x2U)
#define PCIE_TYPE1_STATUS_COMMAND_REG_MSE_SHIFT  (1U)
/*! MSE - Memory Space Enable. This bit controls a Function's response to Memory Space accesses
 *    received on its primary side. - When set, the Function is enabled to decode the address and
 *    further process Memory Space accesses. - When clear, all received Memory Space accesses are caused
 *    to be handled as Unsupported Requests. You cannot write to this register if your configuration
 *    has no MEM bars; that is, the internal signal has_mem_bar =0. Note: The access attributes of
 *    this field are as follows: - Dbi: !has_mem_bar ? RO : RW
 */
#define PCIE_TYPE1_STATUS_COMMAND_REG_MSE(x)     (((uint32_t)(((uint32_t)(x)) << PCIE_TYPE1_STATUS_COMMAND_REG_MSE_SHIFT)) & PCIE_TYPE1_STATUS_COMMAND_REG_MSE_MASK)

#define PCIE_TYPE1_STATUS_COMMAND_REG_BME_MASK   (0x4U)
#define PCIE_TYPE1_STATUS_COMMAND_REG_BME_SHIFT  (2U)
/*! BME - Bus Master Enable. This bit controls forwarding of Memory or I/O requests by a port in the
 *    Upstream direction. When this bit is 0b, Memory and I/O Requests received at a Root Port must
 *    be handled as Unsupported Requests (UR) For Non-Posted Requests a Completion with UR
 *    completion status must be returned. This bit does not affect forwarding of Completions in either the
 *    Upstream or Downstream direction. The forwarding of Requests other than Memory or I/O Requests
 *    is not controlled by this bit.
 */
#define PCIE_TYPE1_STATUS_COMMAND_REG_BME(x)     (((uint32_t)(((uint32_t)(x)) << PCIE_TYPE1_STATUS_COMMAND_REG_BME_SHIFT)) & PCIE_TYPE1_STATUS_COMMAND_REG_BME_MASK)

#define PCIE_TYPE1_STATUS_COMMAND_REG_SCO_MASK   (0x8U)
#define PCIE_TYPE1_STATUS_COMMAND_REG_SCO_SHIFT  (3U)
/*! SCO - Special Cycle Enable. This bit was originally described in the PCI Local Bus
 *    Specification. Its functionality does not apply to PCI Express. The controller hardwires this bit to 0b.
 */
#define PCIE_TYPE1_STATUS_COMMAND_REG_SCO(x)     (((uint32_t)(((uint32_t)(x)) << PCIE_TYPE1_STATUS_COMMAND_REG_SCO_SHIFT)) & PCIE_TYPE1_STATUS_COMMAND_REG_SCO_MASK)

#define PCIE_TYPE1_STATUS_COMMAND_REG_MWI_EN_MASK (0x10U)
#define PCIE_TYPE1_STATUS_COMMAND_REG_MWI_EN_SHIFT (4U)
/*! MWI_EN - Memory Write and Invalidate. This bit was originally described in the PCI Local Bus
 *    Specification and the PCI-to-PCI Bridge Architecture Specification. Its functionality does not
 *    apply to PCI Express. The controller hardwires this bit to 0b. For PCI Express to PCI/PCI-X
 *    Bridges, refer to the PCI Express to PCI/PCI-X Bridge Specification for requirements for this
 *    register.
 */
#define PCIE_TYPE1_STATUS_COMMAND_REG_MWI_EN(x)  (((uint32_t)(((uint32_t)(x)) << PCIE_TYPE1_STATUS_COMMAND_REG_MWI_EN_SHIFT)) & PCIE_TYPE1_STATUS_COMMAND_REG_MWI_EN_MASK)

#define PCIE_TYPE1_STATUS_COMMAND_REG_VGAPS_MASK (0x20U)
#define PCIE_TYPE1_STATUS_COMMAND_REG_VGAPS_SHIFT (5U)
/*! VGAPS - VGA Palette Snoop. This bit was originally described in the PCI Local Bus Specification
 *    and the PCI-to-PCI Bridge Architecture Specification. Its functionality does not apply to PCI
 *    Express. The controller hardwires this bit to 0b.
 */
#define PCIE_TYPE1_STATUS_COMMAND_REG_VGAPS(x)   (((uint32_t)(((uint32_t)(x)) << PCIE_TYPE1_STATUS_COMMAND_REG_VGAPS_SHIFT)) & PCIE_TYPE1_STATUS_COMMAND_REG_VGAPS_MASK)

#define PCIE_TYPE1_STATUS_COMMAND_REG_PERREN_MASK (0x40U)
#define PCIE_TYPE1_STATUS_COMMAND_REG_PERREN_SHIFT (6U)
/*! PERREN - Parity Error Response. This bit controls the logging of poisoned TLPs in the Master
 *    Data Parity Error bit in the Status register. For more details see the "Error Registers" section
 *    of the PCI Express Specification.
 */
#define PCIE_TYPE1_STATUS_COMMAND_REG_PERREN(x)  (((uint32_t)(((uint32_t)(x)) << PCIE_TYPE1_STATUS_COMMAND_REG_PERREN_SHIFT)) & PCIE_TYPE1_STATUS_COMMAND_REG_PERREN_MASK)

#define PCIE_TYPE1_STATUS_COMMAND_REG_IDSEL_MASK (0x80U)
#define PCIE_TYPE1_STATUS_COMMAND_REG_IDSEL_SHIFT (7U)
/*! IDSEL - IDSEL Stepping/Wait Cycle Control. This bit was originally described in the PCI Local
 *    Bus Specification. Its functionality does not apply to PCI Express. The controller hardwires
 *    this bit to 0b.
 */
#define PCIE_TYPE1_STATUS_COMMAND_REG_IDSEL(x)   (((uint32_t)(((uint32_t)(x)) << PCIE_TYPE1_STATUS_COMMAND_REG_IDSEL_SHIFT)) & PCIE_TYPE1_STATUS_COMMAND_REG_IDSEL_MASK)

#define PCIE_TYPE1_STATUS_COMMAND_REG_SERREN_MASK (0x100U)
#define PCIE_TYPE1_STATUS_COMMAND_REG_SERREN_SHIFT (8U)
/*! SERREN - SERR# Enable. When set, this bit enables reporting upstream of Non-fatal and Fatal
 *    errors detected by the Function. Note: The errors are reported if enabled either through this bit
 *    or through the PCI Express specific bits in the Device Control register. For more details see
 *    the "Error Registers" section of the PCI Express Specification. In addition, this bit controls
 *    transmission by the primary interface of ERR_NONFATAL and ERR_FATAL error Messages forwarded
 *    from the secondary interface. This bit does not affect the transmission of forwarded ERR_COR
 *    messages.
 */
#define PCIE_TYPE1_STATUS_COMMAND_REG_SERREN(x)  (((uint32_t)(((uint32_t)(x)) << PCIE_TYPE1_STATUS_COMMAND_REG_SERREN_SHIFT)) & PCIE_TYPE1_STATUS_COMMAND_REG_SERREN_MASK)

#define PCIE_TYPE1_STATUS_COMMAND_REG_RSVDP_9_MASK (0x200U)
#define PCIE_TYPE1_STATUS_COMMAND_REG_RSVDP_9_SHIFT (9U)
/*! RSVDP_9 - Reserved for future use. */
#define PCIE_TYPE1_STATUS_COMMAND_REG_RSVDP_9(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TYPE1_STATUS_COMMAND_REG_RSVDP_9_SHIFT)) & PCIE_TYPE1_STATUS_COMMAND_REG_RSVDP_9_MASK)

#define PCIE_TYPE1_STATUS_COMMAND_REG_INT_EN_MASK (0x400U)
#define PCIE_TYPE1_STATUS_COMMAND_REG_INT_EN_SHIFT (10U)
/*! INT_EN - Interrupt Disable. Controls the ability of a Function to generate INTx emulation
 *    interrupts. When set, Functions are prevented from asserting INTx interrupts. Note: - Any INTx
 *    emulation interrupts already asserted by the Function must be deasserted when this bit is set. INTx
 *    interrupts use virtual wires that must, if asserted, be deasserted using the appropriate
 *    Deassert_INTx message(s) when this bit is set. - Only the INTx virtual wire interrupt(s)
 *    associated with the Function(s) for which this bit is set are affected. - For Functions that generate
 *    INTx interrupts on their own behalf, this bit is required. This bit has no effect on interrupts
 *    forwarded from the secondary side. For Functions that do not generate INTx interrupts on
 *    their own behalf this bit is optional. If this bit is not implemented, the controller hardwires it
 *    to 0b.
 */
#define PCIE_TYPE1_STATUS_COMMAND_REG_INT_EN(x)  (((uint32_t)(((uint32_t)(x)) << PCIE_TYPE1_STATUS_COMMAND_REG_INT_EN_SHIFT)) & PCIE_TYPE1_STATUS_COMMAND_REG_INT_EN_MASK)

#define PCIE_TYPE1_STATUS_COMMAND_REG_RESERV_MASK (0xF800U)
#define PCIE_TYPE1_STATUS_COMMAND_REG_RESERV_SHIFT (11U)
/*! RESERV - Reserved. */
#define PCIE_TYPE1_STATUS_COMMAND_REG_RESERV(x)  (((uint32_t)(((uint32_t)(x)) << PCIE_TYPE1_STATUS_COMMAND_REG_RESERV_SHIFT)) & PCIE_TYPE1_STATUS_COMMAND_REG_RESERV_MASK)

#define PCIE_TYPE1_STATUS_COMMAND_REG_RSVDP_17_MASK (0x60000U)
#define PCIE_TYPE1_STATUS_COMMAND_REG_RSVDP_17_SHIFT (17U)
/*! RSVDP_17 - Reserved for future use. */
#define PCIE_TYPE1_STATUS_COMMAND_REG_RSVDP_17(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TYPE1_STATUS_COMMAND_REG_RSVDP_17_SHIFT)) & PCIE_TYPE1_STATUS_COMMAND_REG_RSVDP_17_MASK)

#define PCIE_TYPE1_STATUS_COMMAND_REG_INT_STATUS_MASK (0x80000U)
#define PCIE_TYPE1_STATUS_COMMAND_REG_INT_STATUS_SHIFT (19U)
/*! INT_STATUS - Interrupt Status. When set, indicates that an INTx emulation interrupt is pending
 *    internally in the Function. INTx emulation interrupts forwarded by Functions from the secondary
 *    side are not reflected in this bit. Setting the Interrupt Disable bit has no effect on the
 *    state of this bit. For Functions that do not generate INTx interrupts, the controller hardwires
 *    this bit to 0b.
 */
#define PCIE_TYPE1_STATUS_COMMAND_REG_INT_STATUS(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TYPE1_STATUS_COMMAND_REG_INT_STATUS_SHIFT)) & PCIE_TYPE1_STATUS_COMMAND_REG_INT_STATUS_MASK)

#define PCIE_TYPE1_STATUS_COMMAND_REG_CAP_LIST_MASK (0x100000U)
#define PCIE_TYPE1_STATUS_COMMAND_REG_CAP_LIST_SHIFT (20U)
/*! CAP_LIST - Capabilities List. Indicates the presence of an Extended Capability list item. Since
 *    all PCI Express device Functions are required to implement the PCI Express Capability
 *    structure, the controller hardwires this bit to 1b.
 */
#define PCIE_TYPE1_STATUS_COMMAND_REG_CAP_LIST(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TYPE1_STATUS_COMMAND_REG_CAP_LIST_SHIFT)) & PCIE_TYPE1_STATUS_COMMAND_REG_CAP_LIST_MASK)

#define PCIE_TYPE1_STATUS_COMMAND_REG_FAST_66MHZ_CAP_MASK (0x200000U)
#define PCIE_TYPE1_STATUS_COMMAND_REG_FAST_66MHZ_CAP_SHIFT (21U)
/*! FAST_66MHZ_CAP - 66 MHz Capable. This bit was originally described in the PCI Local Bus
 *    Specification. Its functionality does not apply to PCI Express. The controller hardwires this bit to
 *    0b.
 */
#define PCIE_TYPE1_STATUS_COMMAND_REG_FAST_66MHZ_CAP(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TYPE1_STATUS_COMMAND_REG_FAST_66MHZ_CAP_SHIFT)) & PCIE_TYPE1_STATUS_COMMAND_REG_FAST_66MHZ_CAP_MASK)

#define PCIE_TYPE1_STATUS_COMMAND_REG_RSVDP_22_MASK (0x400000U)
#define PCIE_TYPE1_STATUS_COMMAND_REG_RSVDP_22_SHIFT (22U)
/*! RSVDP_22 - Reserved for future use. */
#define PCIE_TYPE1_STATUS_COMMAND_REG_RSVDP_22(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TYPE1_STATUS_COMMAND_REG_RSVDP_22_SHIFT)) & PCIE_TYPE1_STATUS_COMMAND_REG_RSVDP_22_MASK)

#define PCIE_TYPE1_STATUS_COMMAND_REG_FAST_B2B_CAP_MASK (0x800000U)
#define PCIE_TYPE1_STATUS_COMMAND_REG_FAST_B2B_CAP_SHIFT (23U)
/*! FAST_B2B_CAP - Fast Back-to-Back Transactions Capable. This bit was originally described in the
 *    PCI Local Bus Specification. Its functionality does not apply to PCI Express. The controller
 *    hardwires this bit to 0b.
 */
#define PCIE_TYPE1_STATUS_COMMAND_REG_FAST_B2B_CAP(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TYPE1_STATUS_COMMAND_REG_FAST_B2B_CAP_SHIFT)) & PCIE_TYPE1_STATUS_COMMAND_REG_FAST_B2B_CAP_MASK)

#define PCIE_TYPE1_STATUS_COMMAND_REG_MASTER_DPE_MASK (0x1000000U)
#define PCIE_TYPE1_STATUS_COMMAND_REG_MASTER_DPE_SHIFT (24U)
/*! MASTER_DPE - Master Data Parity Error. This bit is set by a Function if the Parity Error
 *    Response bit in the Command register is 1b and either of the following two conditions occurs: - Port
 *    receives a Poisoned Completion going downstream - Port transmits a Poisoned Request upstream
 *    If the Parity Error Response bit is 0b, this bit is never set.
 */
#define PCIE_TYPE1_STATUS_COMMAND_REG_MASTER_DPE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TYPE1_STATUS_COMMAND_REG_MASTER_DPE_SHIFT)) & PCIE_TYPE1_STATUS_COMMAND_REG_MASTER_DPE_MASK)

#define PCIE_TYPE1_STATUS_COMMAND_REG_DEV_SEL_TIMING_MASK (0x6000000U)
#define PCIE_TYPE1_STATUS_COMMAND_REG_DEV_SEL_TIMING_SHIFT (25U)
/*! DEV_SEL_TIMING - DEVSEL Timing. This field was originally described in the PCI Local Bus
 *    Specification. Its functionality does not apply to PCI Express. The controller hardwires it to 00b.
 */
#define PCIE_TYPE1_STATUS_COMMAND_REG_DEV_SEL_TIMING(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TYPE1_STATUS_COMMAND_REG_DEV_SEL_TIMING_SHIFT)) & PCIE_TYPE1_STATUS_COMMAND_REG_DEV_SEL_TIMING_MASK)

#define PCIE_TYPE1_STATUS_COMMAND_REG_SIGNALED_TARGET_ABORT_MASK (0x8000000U)
#define PCIE_TYPE1_STATUS_COMMAND_REG_SIGNALED_TARGET_ABORT_SHIFT (27U)
/*! SIGNALED_TARGET_ABORT - Signaled Target Abort. This bit is set when a Function completes a
 *    Posted or Non-Posted Request as a Completer Abort error. This applies to a Function when the
 *    Completer Abort was generated by its primary side.
 */
#define PCIE_TYPE1_STATUS_COMMAND_REG_SIGNALED_TARGET_ABORT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TYPE1_STATUS_COMMAND_REG_SIGNALED_TARGET_ABORT_SHIFT)) & PCIE_TYPE1_STATUS_COMMAND_REG_SIGNALED_TARGET_ABORT_MASK)

#define PCIE_TYPE1_STATUS_COMMAND_REG_RCVD_TARGET_ABORT_MASK (0x10000000U)
#define PCIE_TYPE1_STATUS_COMMAND_REG_RCVD_TARGET_ABORT_SHIFT (28U)
/*! RCVD_TARGET_ABORT - Received Target Abort. This bit is set when a Requester receives a
 *    Completion with Completer Abort Completion status. The bit is set when the Completer Abort is received
 *    by a Function's primary side.
 */
#define PCIE_TYPE1_STATUS_COMMAND_REG_RCVD_TARGET_ABORT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TYPE1_STATUS_COMMAND_REG_RCVD_TARGET_ABORT_SHIFT)) & PCIE_TYPE1_STATUS_COMMAND_REG_RCVD_TARGET_ABORT_MASK)

#define PCIE_TYPE1_STATUS_COMMAND_REG_RCVD_MASTER_ABORT_MASK (0x20000000U)
#define PCIE_TYPE1_STATUS_COMMAND_REG_RCVD_MASTER_ABORT_SHIFT (29U)
/*! RCVD_MASTER_ABORT - Received Master Abort. This bit is set when a Requester receives a
 *    Completion with Unsupported Request Completion status. The bit is set when the Unsupported Request is
 *    received by a Function's primary side.
 */
#define PCIE_TYPE1_STATUS_COMMAND_REG_RCVD_MASTER_ABORT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TYPE1_STATUS_COMMAND_REG_RCVD_MASTER_ABORT_SHIFT)) & PCIE_TYPE1_STATUS_COMMAND_REG_RCVD_MASTER_ABORT_MASK)

#define PCIE_TYPE1_STATUS_COMMAND_REG_SIGNALED_SYS_ERROR_MASK (0x40000000U)
#define PCIE_TYPE1_STATUS_COMMAND_REG_SIGNALED_SYS_ERROR_SHIFT (30U)
/*! SIGNALED_SYS_ERROR - Signaled System Error. This bit is set when a Function sends an ERR_FATAL
 *    or ERR_NONFATAL Message, and the SERR# Enable bit in the Command register is 1b.
 */
#define PCIE_TYPE1_STATUS_COMMAND_REG_SIGNALED_SYS_ERROR(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TYPE1_STATUS_COMMAND_REG_SIGNALED_SYS_ERROR_SHIFT)) & PCIE_TYPE1_STATUS_COMMAND_REG_SIGNALED_SYS_ERROR_MASK)

#define PCIE_TYPE1_STATUS_COMMAND_REG_DETECTED_PARITY_ERROR_MASK (0x80000000U)
#define PCIE_TYPE1_STATUS_COMMAND_REG_DETECTED_PARITY_ERROR_SHIFT (31U)
/*! DETECTED_PARITY_ERROR - Detected Parity Error. This bit is set by a Function whenever it
 *    receives a Poisoned TLP, regardless of the state the Parity Error Response bit in the Command
 *    register. The bit is set when the Poisoned TLP is received by a Function's primary side.
 */
#define PCIE_TYPE1_STATUS_COMMAND_REG_DETECTED_PARITY_ERROR(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TYPE1_STATUS_COMMAND_REG_DETECTED_PARITY_ERROR_SHIFT)) & PCIE_TYPE1_STATUS_COMMAND_REG_DETECTED_PARITY_ERROR_MASK)
/*! @} */

/*! @name TYPE1_CLASS_CODE_REV_ID_REG - Class Code and Revision ID Register. */
/*! @{ */

#define PCIE_TYPE1_CLASS_CODE_REV_ID_REG_REVISION_ID_MASK (0xFFU)
#define PCIE_TYPE1_CLASS_CODE_REV_ID_REG_REVISION_ID_SHIFT (0U)
/*! REVISION_ID - Revision ID. The value of this field specifies a Function specific revision
 *    identifier. The value is chosen by the vendor. Zero is an acceptable value. The Revision ID should
 *    be viewed as a vendor defined extension to the Device ID. Note: The access attributes of this
 *    field are as follows: - Dbi: if (DBI_RO_WR_EN == 1) then R/W(sticky) else R(sticky) Note: This
 *    register field is sticky.
 */
#define PCIE_TYPE1_CLASS_CODE_REV_ID_REG_REVISION_ID(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TYPE1_CLASS_CODE_REV_ID_REG_REVISION_ID_SHIFT)) & PCIE_TYPE1_CLASS_CODE_REV_ID_REG_REVISION_ID_MASK)

#define PCIE_TYPE1_CLASS_CODE_REV_ID_REG_PROGRAM_INTERFACE_MASK (0xFF00U)
#define PCIE_TYPE1_CLASS_CODE_REV_ID_REG_PROGRAM_INTERFACE_SHIFT (8U)
/*! PROGRAM_INTERFACE - Programming Interface. This field identifies a specific register level
 *    programming interface (if any) so that device independent software can interact with the Function.
 *    Encodings for interface are provided in the PCI Code and ID Assignment Specification. All
 *    unspecified encodings are reserved. Note: The access attributes of this field are as follows: -
 *    Dbi: if (DBI_RO_WR_EN == 1) then R/W(sticky) else R(sticky) Note: This register field is sticky.
 */
#define PCIE_TYPE1_CLASS_CODE_REV_ID_REG_PROGRAM_INTERFACE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TYPE1_CLASS_CODE_REV_ID_REG_PROGRAM_INTERFACE_SHIFT)) & PCIE_TYPE1_CLASS_CODE_REV_ID_REG_PROGRAM_INTERFACE_MASK)

#define PCIE_TYPE1_CLASS_CODE_REV_ID_REG_SUBCLASS_CODE_MASK (0xFF0000U)
#define PCIE_TYPE1_CLASS_CODE_REV_ID_REG_SUBCLASS_CODE_SHIFT (16U)
/*! SUBCLASS_CODE - Sub-Class Code. Specifies a base class sub-class, which identifies more
 *    specifically the operation of the Function. Encodings for sub-class are provided in the PCI Code and
 *    ID Assignment Specification. All unspecified encodings are reserved. Note: The access
 *    attributes of this field are as follows: - Dbi: if (DBI_RO_WR_EN == 1) then R/W(sticky) else R(sticky)
 *    Note: This register field is sticky.
 */
#define PCIE_TYPE1_CLASS_CODE_REV_ID_REG_SUBCLASS_CODE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TYPE1_CLASS_CODE_REV_ID_REG_SUBCLASS_CODE_SHIFT)) & PCIE_TYPE1_CLASS_CODE_REV_ID_REG_SUBCLASS_CODE_MASK)

#define PCIE_TYPE1_CLASS_CODE_REV_ID_REG_BASE_CLASS_CODE_MASK (0xFF000000U)
#define PCIE_TYPE1_CLASS_CODE_REV_ID_REG_BASE_CLASS_CODE_SHIFT (24U)
/*! BASE_CLASS_CODE - Base Class Code. A code that broadly classifies the type of operation the
 *    Function performs. Encodings for base class, are provided in the PCI Code and ID Assignment
 *    Specification. All unspecified encodings are reserved. Note: The access attributes of this field are
 *    as follows: - Dbi: if (DBI_RO_WR_EN == 1) then R/W(sticky) else R(sticky) Note: This register
 *    field is sticky.
 */
#define PCIE_TYPE1_CLASS_CODE_REV_ID_REG_BASE_CLASS_CODE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TYPE1_CLASS_CODE_REV_ID_REG_BASE_CLASS_CODE_SHIFT)) & PCIE_TYPE1_CLASS_CODE_REV_ID_REG_BASE_CLASS_CODE_MASK)
/*! @} */

/*! @name TYPE1_HDR_TYPE_LAT_CACHE_LINE_SIZE_REG - Header Type, Latency Timer, and Cache Line Size Register. */
/*! @{ */

#define PCIE_TYPE1_HDR_TYPE_LAT_CACHE_LINE_SIZE_REG_CACHE_LINE_SIZE_MASK (0xFFU)
#define PCIE_TYPE1_HDR_TYPE_LAT_CACHE_LINE_SIZE_REG_CACHE_LINE_SIZE_SHIFT (0U)
/*! CACHE_LINE_SIZE - Cache Line Size. The Cache Line Size register is programmed by the system
 *    firmware or the operating system to system cache line size. However, legacy conventional PCI
 *    software may not always be able to program this register correctly especially in the case of
 *    Hot-Plug devices. This read-write register is implemented for legacy compatibility purposes but has
 *    no effect on any PCI Express device behavior.
 */
#define PCIE_TYPE1_HDR_TYPE_LAT_CACHE_LINE_SIZE_REG_CACHE_LINE_SIZE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TYPE1_HDR_TYPE_LAT_CACHE_LINE_SIZE_REG_CACHE_LINE_SIZE_SHIFT)) & PCIE_TYPE1_HDR_TYPE_LAT_CACHE_LINE_SIZE_REG_CACHE_LINE_SIZE_MASK)

#define PCIE_TYPE1_HDR_TYPE_LAT_CACHE_LINE_SIZE_REG_LATENCY_MASTER_TIMER_MASK (0xFF00U)
#define PCIE_TYPE1_HDR_TYPE_LAT_CACHE_LINE_SIZE_REG_LATENCY_MASTER_TIMER_SHIFT (8U)
/*! LATENCY_MASTER_TIMER - Latency Timer. This register is also referred to as Primary Latency
 *    Timer. The Latency Timer was originally described in the PCI Local Bus Specification and the
 *    PCI-to-PCI Bridge Architecture Specification. Its functionality does not apply to PCI Express. The
 *    controller hardwires this register to 00h.
 */
#define PCIE_TYPE1_HDR_TYPE_LAT_CACHE_LINE_SIZE_REG_LATENCY_MASTER_TIMER(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TYPE1_HDR_TYPE_LAT_CACHE_LINE_SIZE_REG_LATENCY_MASTER_TIMER_SHIFT)) & PCIE_TYPE1_HDR_TYPE_LAT_CACHE_LINE_SIZE_REG_LATENCY_MASTER_TIMER_MASK)

#define PCIE_TYPE1_HDR_TYPE_LAT_CACHE_LINE_SIZE_REG_HEADER_TYPE_MASK (0x7F0000U)
#define PCIE_TYPE1_HDR_TYPE_LAT_CACHE_LINE_SIZE_REG_HEADER_TYPE_SHIFT (16U)
/*! HEADER_TYPE - Header Layout. This field identifies the layout of the second part of the
 *    predefined header. The controller uses 000 0001b encoding. The encoding 000 0010b is reserved. This
 *    encoding was originally described in the PC Card Standard Electrical Specification and is used
 *    in previous versions of the programming model. Careful consideration should be given to any
 *    attempt to repurpose it.
 */
#define PCIE_TYPE1_HDR_TYPE_LAT_CACHE_LINE_SIZE_REG_HEADER_TYPE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TYPE1_HDR_TYPE_LAT_CACHE_LINE_SIZE_REG_HEADER_TYPE_SHIFT)) & PCIE_TYPE1_HDR_TYPE_LAT_CACHE_LINE_SIZE_REG_HEADER_TYPE_MASK)

#define PCIE_TYPE1_HDR_TYPE_LAT_CACHE_LINE_SIZE_REG_MULTI_FUNC_MASK (0x800000U)
#define PCIE_TYPE1_HDR_TYPE_LAT_CACHE_LINE_SIZE_REG_MULTI_FUNC_SHIFT (23U)
/*! MULTI_FUNC - Multi-Function Device. - When set, indicates that the device may contain multiple
 *    Functions, but not necessarily. Software is permitted to probe for Functions other than
 *    Function 0. - When clear, software must not probe for Functions other than Function 0 unless
 *    explicitly indicated by another mechanism, such as an ARI or SR-IOV Capability structure. Except where
 *    stated otherwise, it is recommended that this bit be set if there are multiple Functions, and
 *    clear if there is only one Function. Note: This register field is sticky.
 */
#define PCIE_TYPE1_HDR_TYPE_LAT_CACHE_LINE_SIZE_REG_MULTI_FUNC(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TYPE1_HDR_TYPE_LAT_CACHE_LINE_SIZE_REG_MULTI_FUNC_SHIFT)) & PCIE_TYPE1_HDR_TYPE_LAT_CACHE_LINE_SIZE_REG_MULTI_FUNC_MASK)

#define PCIE_TYPE1_HDR_TYPE_LAT_CACHE_LINE_SIZE_REG_BIST_MASK (0xFF000000U)
#define PCIE_TYPE1_HDR_TYPE_LAT_CACHE_LINE_SIZE_REG_BIST_SHIFT (24U)
/*! BIST - BIST. This register is used for control and status of BIST. Functions that do not support
 *    BIST must hardwire the register to 00h. A Function whose BIST is invoked must not prevent
 *    normal operation of the PCI Express Link. Bit descriptions: - [31]: BIST Capable. When set, this
 *    bit indicates that the Function supports BIST. When Clear, the Function does not support BIST.
 *    - [30]: Start BIST. If BIST Capable is set, set this bit to invoke BIST. The Function resets
 *    the bit when BIST is complete. Software is permitted to fail the device if this bit is not
 *    Clear (BIST is not complete) 2 seconds after it had been set. Writing this bit to 0b has no
 *    effect. The controller hardwires this bit to 0b if BIST Capable is clear. - [29:28]: Reserved. -
 *    [27:24]: Completion Code. This field encodes the status of the most recent test. A value of
 *    0000b means that the Function has passed its test. Non-zero values mean the Function failed.
 *    Function-specific failure codes can be encoded in the non-zero values. This field's value is only
 *    meaningful when BIST Capable is set and Start BIST is Clear. This field must be hardwired to
 *    0000b if BIST Capable is clear.
 */
#define PCIE_TYPE1_HDR_TYPE_LAT_CACHE_LINE_SIZE_REG_BIST(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TYPE1_HDR_TYPE_LAT_CACHE_LINE_SIZE_REG_BIST_SHIFT)) & PCIE_TYPE1_HDR_TYPE_LAT_CACHE_LINE_SIZE_REG_BIST_MASK)
/*! @} */

/*! @name SEC_LAT_TIMER_SUB_BUS_SEC_BUS_PRI_BUS_REG - Secondary Latency Timer, Subordinate Bus Number, Secondary Bus Number, and Primary Bus Number Register. */
/*! @{ */

#define PCIE_SEC_LAT_TIMER_SUB_BUS_SEC_BUS_PRI_BUS_REG_PRIM_BUS_MASK (0xFFU)
#define PCIE_SEC_LAT_TIMER_SUB_BUS_SEC_BUS_PRI_BUS_REG_PRIM_BUS_SHIFT (0U)
/*! PRIM_BUS - Primary Bus Number. This register is not used by PCI Express Functions. It is
 *    implemented for compatibility with legacy software.
 */
#define PCIE_SEC_LAT_TIMER_SUB_BUS_SEC_BUS_PRI_BUS_REG_PRIM_BUS(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SEC_LAT_TIMER_SUB_BUS_SEC_BUS_PRI_BUS_REG_PRIM_BUS_SHIFT)) & PCIE_SEC_LAT_TIMER_SUB_BUS_SEC_BUS_PRI_BUS_REG_PRIM_BUS_MASK)

#define PCIE_SEC_LAT_TIMER_SUB_BUS_SEC_BUS_PRI_BUS_REG_SEC_BUS_MASK (0xFF00U)
#define PCIE_SEC_LAT_TIMER_SUB_BUS_SEC_BUS_PRI_BUS_REG_SEC_BUS_SHIFT (8U)
/*! SEC_BUS - Secondary Bus Number. The Secondary Bus Number register is used to record the bus
 *    number of the PCI bus segment to which the secondary interface of the bridge is connected.
 *    Configuration software programs the value in this register. The bridge uses this register to
 *    determine when to respond to and convert a Type 1 configuration transaction on the primary interface
 *    into a Type 0 transaction on the secondary interface.
 */
#define PCIE_SEC_LAT_TIMER_SUB_BUS_SEC_BUS_PRI_BUS_REG_SEC_BUS(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SEC_LAT_TIMER_SUB_BUS_SEC_BUS_PRI_BUS_REG_SEC_BUS_SHIFT)) & PCIE_SEC_LAT_TIMER_SUB_BUS_SEC_BUS_PRI_BUS_REG_SEC_BUS_MASK)

#define PCIE_SEC_LAT_TIMER_SUB_BUS_SEC_BUS_PRI_BUS_REG_SUB_BUS_MASK (0xFF0000U)
#define PCIE_SEC_LAT_TIMER_SUB_BUS_SEC_BUS_PRI_BUS_REG_SUB_BUS_SHIFT (16U)
/*! SUB_BUS - Subordinate Bus Number. The Subordinate Bus Number register is used to record the bus
 *    number of the highest numbered PCI bus segment which is behind (or subordinate to) the bridge.
 *    Configuration software programs the value in this register. The bridge uses this register in
 *    conjunction with the Secondary Bus Number register to determine when to respond to and pass on
 *    a Type 1 configuration transaction on the primary interface to the secondary interface.
 */
#define PCIE_SEC_LAT_TIMER_SUB_BUS_SEC_BUS_PRI_BUS_REG_SUB_BUS(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SEC_LAT_TIMER_SUB_BUS_SEC_BUS_PRI_BUS_REG_SUB_BUS_SHIFT)) & PCIE_SEC_LAT_TIMER_SUB_BUS_SEC_BUS_PRI_BUS_REG_SUB_BUS_MASK)

#define PCIE_SEC_LAT_TIMER_SUB_BUS_SEC_BUS_PRI_BUS_REG_SEC_LAT_TIMER_MASK (0xFF000000U)
#define PCIE_SEC_LAT_TIMER_SUB_BUS_SEC_BUS_PRI_BUS_REG_SEC_LAT_TIMER_SHIFT (24U)
/*! SEC_LAT_TIMER - Secondary Latency Timer. This register does not apply to PCI Express. The controller hardwires it to 00h. */
#define PCIE_SEC_LAT_TIMER_SUB_BUS_SEC_BUS_PRI_BUS_REG_SEC_LAT_TIMER(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SEC_LAT_TIMER_SUB_BUS_SEC_BUS_PRI_BUS_REG_SEC_LAT_TIMER_SHIFT)) & PCIE_SEC_LAT_TIMER_SUB_BUS_SEC_BUS_PRI_BUS_REG_SEC_LAT_TIMER_MASK)
/*! @} */

/*! @name SEC_STAT_IO_LIMIT_IO_BASE_REG - Secondary Status, and I/O Limit and Base Register. */
/*! @{ */

#define PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_IO_DECODE_MASK (0x1U)
#define PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_IO_DECODE_SHIFT (0U)
/*! IO_DECODE - I/O Addressing Encode (IO Base Address) This bit encodes the IO addressing
 *    capability of the bridge. IO_DECODE indicates the following: - 0h: The bridge supports only 16-bit I/O
 *    addressing (for ISA compatibility). For the purpose of address decoding, the bridge assumes
 *    that the upper 16 address bits, Address[31:16], of the I/O base address (not implemented in I/O
 *    base register) are zero. Note: The bridge must still perform a full 32-bit decode of the I/O
 *    address (that is, check that Address[31:16] are 0000h). In this case, the I/O address range
 *    supported by the bridge will be restricted to the first 64 KB of I/O Space (0000 0000h to 0000
 *    FFFFh). - 01h: The bridge supports 32-bit I/O address decoding, and the I/O Base Upper 16 Bits
 *    hold the upper 16 bits, corresponding to Address[31:16], of the 32-bit Base address. In this
 *    case, system configuration software is permitted to locate the I/O address range supported by
 *    the bridge anywhere in the 4-GB I/O Space. Note: The 4-KB alignment and granularity restrictions
 *    still apply when the bridge supports 32-bit I/O addressing. Note: The access attributes of
 *    this field are as follows: - Dbi: if (DBI_RO_WR_EN == 1) then R/W else R
 */
#define PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_IO_DECODE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_IO_DECODE_SHIFT)) & PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_IO_DECODE_MASK)

#define PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_IO_RESERV_MASK (0xEU)
#define PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_IO_RESERV_SHIFT (1U)
/*! IO_RESERV - Reserved. */
#define PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_IO_RESERV(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_IO_RESERV_SHIFT)) & PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_IO_RESERV_MASK)

#define PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_IO_BASE_MASK (0xF0U)
#define PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_IO_BASE_SHIFT (4U)
/*! IO_BASE - I/O Base Address. These bits correspond to the address[15:12] of IO address range. For
 *    the purpose of address decoding, the bridge assumes that the lower 12 address bits,
 *    address[11:0], of the I/O base address (not implemented in the I/O Base register) are zero.
 */
#define PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_IO_BASE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_IO_BASE_SHIFT)) & PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_IO_BASE_MASK)

#define PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_IO_DECODE_BIT8_MASK (0x100U)
#define PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_IO_DECODE_BIT8_SHIFT (8U)
/*! IO_DECODE_BIT8 - I/O Addressing Encode (IO Limit Address). This bit encodes the IO addressing
 *    capability of the bridge. IO_DECODE_BIT8 indicates the following: - 0h: The bridge supports only
 *    16-bit I/O addressing (for ISA compatibility). For the purpose of address decoding, the
 *    bridge assumes that the upper 16 address bits, Address[31:16], of the I/O limit address (not
 *    implemented in I/O Limit register) are zero. Note: The bridge must still perform a full 32-bit
 *    decode of the I/O address (that is, check that Address[31:16] are 0000h). In this case, the I/O
 *    address range supported by the bridge will be restricted to the first 64 KB of I/O Space (0000
 *    0000h to 0000 FFFFh). - 01h: The bridge supports 32-bit I/O address decoding, and the I/O Limit
 *    Upper 16 Bits hold the upper 16 bits, corresponding to Address[31:16], of the 32-bit Limit
 *    address. In this case, system configuration software is permitted to locate the I/O address range
 *    supported by the bridge anywhere in the 4-GB I/O Space. Note: The 4-KB alignment and
 *    granularity restrictions still apply when the bridge supports 32-bit I/O addressing. Note: The access
 *    attributes of this field are as follows: - Dbi: R
 */
#define PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_IO_DECODE_BIT8(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_IO_DECODE_BIT8_SHIFT)) & PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_IO_DECODE_BIT8_MASK)

#define PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_IO_RESERV1_MASK (0xE00U)
#define PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_IO_RESERV1_SHIFT (9U)
/*! IO_RESERV1 - Reserved. */
#define PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_IO_RESERV1(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_IO_RESERV1_SHIFT)) & PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_IO_RESERV1_MASK)

#define PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_IO_LIMIT_MASK (0xF000U)
#define PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_IO_LIMIT_SHIFT (12U)
/*! IO_LIMIT - I/O Limit Address. These bits correspond to the address[15:12] of IO address range.
 *    For the purpose of address decoding, the bridge assumes that the lower 12 address bits,
 *    address[11:0], of the I/O limit address (not implemented in the I/O Limit register) are FFFh. The I/O
 *    Limit register can be programmed to a smaller value than the I/O Base register, if there are
 *    no I/O addresses on the secondary side of the bridge. In this case, the bridge will not
 *    forward any I/O transactions from the primary bus to the secondary and will forward all I/O
 *    transactions from the secondary bus to the primary bus.
 */
#define PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_IO_LIMIT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_IO_LIMIT_SHIFT)) & PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_IO_LIMIT_MASK)

#define PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_SEC_STAT_RESERV_MASK (0x7F0000U)
#define PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_SEC_STAT_RESERV_SHIFT (16U)
/*! SEC_STAT_RESERV - Reserved. */
#define PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_SEC_STAT_RESERV(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_SEC_STAT_RESERV_SHIFT)) & PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_SEC_STAT_RESERV_MASK)

#define PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_RSVDP_23_MASK (0x800000U)
#define PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_RSVDP_23_SHIFT (23U)
/*! RSVDP_23 - Reserved for future use. */
#define PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_RSVDP_23(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_RSVDP_23_SHIFT)) & PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_RSVDP_23_MASK)

#define PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_SEC_STAT_MDPE_MASK (0x1000000U)
#define PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_SEC_STAT_MDPE_SHIFT (24U)
/*! SEC_STAT_MDPE - Master Data Parity Error. This bit is set by a Function if the Parity Error
 *    Response Enable bit in the Bridge Control register is set, and either of the following two
 *    conditions occurs: - Port receives a Poisoned Completion coming Upstream - Port transmits a Poisoned
 *    Request Downstream If the Parity Error Response Enable bit is clear, this bit is never set.
 */
#define PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_SEC_STAT_MDPE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_SEC_STAT_MDPE_SHIFT)) & PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_SEC_STAT_MDPE_MASK)

#define PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_RSVDP_25_MASK (0x6000000U)
#define PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_RSVDP_25_SHIFT (25U)
/*! RSVDP_25 - Reserved for future use. */
#define PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_RSVDP_25(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_RSVDP_25_SHIFT)) & PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_RSVDP_25_MASK)

#define PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_SEC_STAT_SIG_TRGT_ABRT_MASK (0x8000000U)
#define PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_SEC_STAT_SIG_TRGT_ABRT_SHIFT (27U)
/*! SEC_STAT_SIG_TRGT_ABRT - Signaled Target Abort. This bit is set when the secondary side of the
 *    Function (for Requests completed by the Type 1 header Function itself) completes a Posted or
 *    Non-Posted request as a Completer Abort error.
 */
#define PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_SEC_STAT_SIG_TRGT_ABRT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_SEC_STAT_SIG_TRGT_ABRT_SHIFT)) & PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_SEC_STAT_SIG_TRGT_ABRT_MASK)

#define PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_SEC_STAT_RCVD_TRGT_ABRT_MASK (0x10000000U)
#define PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_SEC_STAT_RCVD_TRGT_ABRT_SHIFT (28U)
/*! SEC_STAT_RCVD_TRGT_ABRT - Received Target Abort. This bit is set when the secondary side of a
 *    Function (for requests initiated by the Type 1 header Function itself) receives a Completion
 *    with Completer Abort Completion status.
 */
#define PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_SEC_STAT_RCVD_TRGT_ABRT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_SEC_STAT_RCVD_TRGT_ABRT_SHIFT)) & PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_SEC_STAT_RCVD_TRGT_ABRT_MASK)

#define PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_SEC_STAT_RCVD_MSTR_ABRT_MASK (0x20000000U)
#define PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_SEC_STAT_RCVD_MSTR_ABRT_SHIFT (29U)
/*! SEC_STAT_RCVD_MSTR_ABRT - Received Master Abort. This bit is set when the secondary side of a
 *    Function (for requests initiated by the Type 1 header Function itself) receives a Completion
 *    with Unsupported Request Completion status.
 */
#define PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_SEC_STAT_RCVD_MSTR_ABRT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_SEC_STAT_RCVD_MSTR_ABRT_SHIFT)) & PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_SEC_STAT_RCVD_MSTR_ABRT_MASK)

#define PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_SEC_STAT_RCVD_SYS_ERR_MASK (0x40000000U)
#define PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_SEC_STAT_RCVD_SYS_ERR_SHIFT (30U)
/*! SEC_STAT_RCVD_SYS_ERR - Received System Error. This bit is set when the secondary side of a
 *    Function receives an ERR_FATAL or ERR_NONFATAL message.
 */
#define PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_SEC_STAT_RCVD_SYS_ERR(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_SEC_STAT_RCVD_SYS_ERR_SHIFT)) & PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_SEC_STAT_RCVD_SYS_ERR_MASK)

#define PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_SEC_STAT_DPE_MASK (0x80000000U)
#define PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_SEC_STAT_DPE_SHIFT (31U)
/*! SEC_STAT_DPE - Detected Parity Error. This bit is set by a Function when a Poisoned TLP is
 *    received by its secondary side, regardless of the state the Parity Error Response Enable bit in the
 *    Bridge Control register.
 */
#define PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_SEC_STAT_DPE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_SEC_STAT_DPE_SHIFT)) & PCIE_SEC_STAT_IO_LIMIT_IO_BASE_REG_SEC_STAT_DPE_MASK)
/*! @} */

/*! @name MEM_LIMIT_MEM_BASE_REG - Memory Limit and Base Register. */
/*! @{ */

#define PCIE_MEM_LIMIT_MEM_BASE_REG_MEM_BASE_RESERV_MASK (0xFU)
#define PCIE_MEM_LIMIT_MEM_BASE_REG_MEM_BASE_RESERV_SHIFT (0U)
/*! MEM_BASE_RESERV - Reserved. */
#define PCIE_MEM_LIMIT_MEM_BASE_REG_MEM_BASE_RESERV(x) (((uint32_t)(((uint32_t)(x)) << PCIE_MEM_LIMIT_MEM_BASE_REG_MEM_BASE_RESERV_SHIFT)) & PCIE_MEM_LIMIT_MEM_BASE_REG_MEM_BASE_RESERV_MASK)

#define PCIE_MEM_LIMIT_MEM_BASE_REG_MEM_BASE_MASK (0xFFF0U)
#define PCIE_MEM_LIMIT_MEM_BASE_REG_MEM_BASE_SHIFT (4U)
/*! MEM_BASE - Memory Base Address. These bits correspond to the upper 12 address bits,
 *    Address[31:20], of 32-bit addresses. For the purpose of address decoding, the bridge assumes that the
 *    lower 20 address bits, Address[19:0], of the memory base address (not implemented in the Memory
 *    Base register) are zero.
 */
#define PCIE_MEM_LIMIT_MEM_BASE_REG_MEM_BASE(x)  (((uint32_t)(((uint32_t)(x)) << PCIE_MEM_LIMIT_MEM_BASE_REG_MEM_BASE_SHIFT)) & PCIE_MEM_LIMIT_MEM_BASE_REG_MEM_BASE_MASK)

#define PCIE_MEM_LIMIT_MEM_BASE_REG_MEM_LIMIT_RESERV_MASK (0xF0000U)
#define PCIE_MEM_LIMIT_MEM_BASE_REG_MEM_LIMIT_RESERV_SHIFT (16U)
/*! MEM_LIMIT_RESERV - Reserved. */
#define PCIE_MEM_LIMIT_MEM_BASE_REG_MEM_LIMIT_RESERV(x) (((uint32_t)(((uint32_t)(x)) << PCIE_MEM_LIMIT_MEM_BASE_REG_MEM_LIMIT_RESERV_SHIFT)) & PCIE_MEM_LIMIT_MEM_BASE_REG_MEM_LIMIT_RESERV_MASK)

#define PCIE_MEM_LIMIT_MEM_BASE_REG_MEM_LIMIT_MASK (0xFFF00000U)
#define PCIE_MEM_LIMIT_MEM_BASE_REG_MEM_LIMIT_SHIFT (20U)
/*! MEM_LIMIT - Memory Limit Address. These bits correspond to the upper 12 address bits,
 *    Address[31:20], of 32-bit addresses. For the purpose of address decoding, the bridge assumes that the
 *    lower 20 address bits, Address[19:0], of the memory limit address (not implemented in the Memory
 *    Limit register) are F FFFFh. The Memory Limit register must be programmed to a smaller value
 *    than the Memory Base register if there is no memory-mapped address space on the secondary side
 *    of the bridge.
 */
#define PCIE_MEM_LIMIT_MEM_BASE_REG_MEM_LIMIT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_MEM_LIMIT_MEM_BASE_REG_MEM_LIMIT_SHIFT)) & PCIE_MEM_LIMIT_MEM_BASE_REG_MEM_LIMIT_MASK)
/*! @} */

/*! @name PREF_MEM_LIMIT_PREF_MEM_BASE_REG - Prefetchable Memory Limit and Base Register. */
/*! @{ */

#define PCIE_PREF_MEM_LIMIT_PREF_MEM_BASE_REG_PREF_MEM_DECODE_MASK (0x1U)
#define PCIE_PREF_MEM_LIMIT_PREF_MEM_BASE_REG_PREF_MEM_DECODE_SHIFT (0U)
/*! PREF_MEM_DECODE - Prefetchable Memory Base Decode. This bit encodes whether or not the bridge
 *    supports 64-bit addresses. The value of PREF_MEM_DECODE indicates the following: - 0b: Indicates
 *    that the bridge supports only 32 bit addresses. - 1b: Indicates that the bridge supports 64
 *    bit addresses. Prefetchable Base Upper 32 Bits registers holds the rest of the 64-bit
 *    prefetchable base address. Note: The access attributes of this field are as follows: - Dbi: if
 *    (DBI_RO_WR_EN == 1) then R/W else R Note: This register field is sticky.
 */
#define PCIE_PREF_MEM_LIMIT_PREF_MEM_BASE_REG_PREF_MEM_DECODE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_PREF_MEM_LIMIT_PREF_MEM_BASE_REG_PREF_MEM_DECODE_SHIFT)) & PCIE_PREF_MEM_LIMIT_PREF_MEM_BASE_REG_PREF_MEM_DECODE_MASK)

#define PCIE_PREF_MEM_LIMIT_PREF_MEM_BASE_REG_PREF_RESERV_MASK (0xEU)
#define PCIE_PREF_MEM_LIMIT_PREF_MEM_BASE_REG_PREF_RESERV_SHIFT (1U)
/*! PREF_RESERV - Reserved. */
#define PCIE_PREF_MEM_LIMIT_PREF_MEM_BASE_REG_PREF_RESERV(x) (((uint32_t)(((uint32_t)(x)) << PCIE_PREF_MEM_LIMIT_PREF_MEM_BASE_REG_PREF_RESERV_SHIFT)) & PCIE_PREF_MEM_LIMIT_PREF_MEM_BASE_REG_PREF_RESERV_MASK)

#define PCIE_PREF_MEM_LIMIT_PREF_MEM_BASE_REG_PREF_MEM_BASE_MASK (0xFFF0U)
#define PCIE_PREF_MEM_LIMIT_PREF_MEM_BASE_REG_PREF_MEM_BASE_SHIFT (4U)
/*! PREF_MEM_BASE - Prefetchable Memory Base Address. If the Prefetchable Memory Base register
 *    indicates support for 32-bit addressing, then the Prefetchable Base Upper 32 Bits register is
 *    implemented as a read-only register that returns zero when read. If the Prefetchable Memory Base
 *    register indicates support for 64-bit addressing, then the Prefetchable Limit Upper 32 Bits
 *    register is implemented as a read/write register which must be initialized by configuration
 *    software. If a 64-bit prefetchable memory address range is supported, the Prefetchable Base Upper 32
 *    Bits register specifies the upper 32 bits, corresponding to Address[63:32], of the 64-bit
 *    base addresses which specify the prefetchable memory address range.
 */
#define PCIE_PREF_MEM_LIMIT_PREF_MEM_BASE_REG_PREF_MEM_BASE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_PREF_MEM_LIMIT_PREF_MEM_BASE_REG_PREF_MEM_BASE_SHIFT)) & PCIE_PREF_MEM_LIMIT_PREF_MEM_BASE_REG_PREF_MEM_BASE_MASK)

#define PCIE_PREF_MEM_LIMIT_PREF_MEM_BASE_REG_PREF_MEM_LIMIT_DECODE_MASK (0x10000U)
#define PCIE_PREF_MEM_LIMIT_PREF_MEM_BASE_REG_PREF_MEM_LIMIT_DECODE_SHIFT (16U)
/*! PREF_MEM_LIMIT_DECODE - Prefetchable Memory Limit Decode. This bit encodes whether or not the
 *    bridge supports 64-bit addresses. The value of PREF_MEM_LIMIT_DECODE indicates the following: -
 *    0b: Indicates that the bridge supports only 32 bit addresses - 1b: Indicates that the bridge
 *    supports 64 bit addresses. Prefetchable Limit Upper 32 Bits registers holds the rest of the
 *    64-bit prefetchable limit address.
 */
#define PCIE_PREF_MEM_LIMIT_PREF_MEM_BASE_REG_PREF_MEM_LIMIT_DECODE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_PREF_MEM_LIMIT_PREF_MEM_BASE_REG_PREF_MEM_LIMIT_DECODE_SHIFT)) & PCIE_PREF_MEM_LIMIT_PREF_MEM_BASE_REG_PREF_MEM_LIMIT_DECODE_MASK)

#define PCIE_PREF_MEM_LIMIT_PREF_MEM_BASE_REG_PREF_RESERV1_MASK (0xE0000U)
#define PCIE_PREF_MEM_LIMIT_PREF_MEM_BASE_REG_PREF_RESERV1_SHIFT (17U)
/*! PREF_RESERV1 - Reserved. */
#define PCIE_PREF_MEM_LIMIT_PREF_MEM_BASE_REG_PREF_RESERV1(x) (((uint32_t)(((uint32_t)(x)) << PCIE_PREF_MEM_LIMIT_PREF_MEM_BASE_REG_PREF_RESERV1_SHIFT)) & PCIE_PREF_MEM_LIMIT_PREF_MEM_BASE_REG_PREF_RESERV1_MASK)

#define PCIE_PREF_MEM_LIMIT_PREF_MEM_BASE_REG_PREF_MEM_LIMIT_MASK (0xFFF00000U)
#define PCIE_PREF_MEM_LIMIT_PREF_MEM_BASE_REG_PREF_MEM_LIMIT_SHIFT (20U)
/*! PREF_MEM_LIMIT - Prefetchable Memory Limit Address. If the Prefetchable Memory Limit register
 *    indicates support for 32-bit addressing, then the Prefetchable Limit Upper 32 Bits register is
 *    implemented as a read-only register that returns zero when read. If the Prefetchable Memory
 *    Limit registers indicate support for 64-bit addressing, then the Prefetchable Limit Upper 32 Bits
 *    register is implemented as a read/write register which must be initialized by configuration
 *    software. If a 64-bit prefetchable memory address range is supported, the Prefetchable Limit
 *    Upper 32 Bits register specifies the upper 32 bits, corresponding to Address[63:32], of the
 *    64-bit limit addresses which specify the prefetchable memory address range.
 */
#define PCIE_PREF_MEM_LIMIT_PREF_MEM_BASE_REG_PREF_MEM_LIMIT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_PREF_MEM_LIMIT_PREF_MEM_BASE_REG_PREF_MEM_LIMIT_SHIFT)) & PCIE_PREF_MEM_LIMIT_PREF_MEM_BASE_REG_PREF_MEM_LIMIT_MASK)
/*! @} */

/*! @name PREF_BASE_UPPER_REG - Prefetchable Base Upper 32 Bits Register. */
/*! @{ */

#define PCIE_PREF_BASE_UPPER_REG_PREF_MEM_BASE_UPPER_MASK (0xFFFFFFFFU)
#define PCIE_PREF_BASE_UPPER_REG_PREF_MEM_BASE_UPPER_SHIFT (0U)
/*! PREF_MEM_BASE_UPPER - Prefetchable Base Upper 32 Bit. If the Prefetchable Memory Base register
 *    indicates support for 32-bit addressing, then this register is implemented as read-only
 *    register that returns zero when read. If the Prefetchable Memory Base register indicate support for
 *    64-bit addressing, then this register is implemented as read/write register which must be
 *    initialized by configuration software. This register specifies the upper 32 bits, corresponding to
 *    Address[63:32], of the 64-bit base addresses which specify the prefetchable memory address
 *    range. Note: The access attributes of this field are as follows: - Dbi: if (DBI_RO_WR_EN == 1)
 *    then R/W else R
 */
#define PCIE_PREF_BASE_UPPER_REG_PREF_MEM_BASE_UPPER(x) (((uint32_t)(((uint32_t)(x)) << PCIE_PREF_BASE_UPPER_REG_PREF_MEM_BASE_UPPER_SHIFT)) & PCIE_PREF_BASE_UPPER_REG_PREF_MEM_BASE_UPPER_MASK)
/*! @} */

/*! @name PREF_LIMIT_UPPER_REG - Prefetchable Limit Upper 32 Bits Register. */
/*! @{ */

#define PCIE_PREF_LIMIT_UPPER_REG_PREF_MEM_LIMIT_UPPER_MASK (0xFFFFFFFFU)
#define PCIE_PREF_LIMIT_UPPER_REG_PREF_MEM_LIMIT_UPPER_SHIFT (0U)
/*! PREF_MEM_LIMIT_UPPER - Prefetchable Limit Upper 32 Bit. If the Prefetchable Memory Limit
 *    register indicate support for 64-bit addressing, then this register is implemented as read/write
 *    register which must be initialized by configuration software. This register specifies the upper 32
 *    bits, corresponding to Address[63:32], of the 64-bit base addresses which specify the
 *    prefetchable memory address range. Note: The access attributes of this field are as follows: - Dbi:
 *    if (DBI_RO_WR_EN == 1) then R/W else R
 */
#define PCIE_PREF_LIMIT_UPPER_REG_PREF_MEM_LIMIT_UPPER(x) (((uint32_t)(((uint32_t)(x)) << PCIE_PREF_LIMIT_UPPER_REG_PREF_MEM_LIMIT_UPPER_SHIFT)) & PCIE_PREF_LIMIT_UPPER_REG_PREF_MEM_LIMIT_UPPER_MASK)
/*! @} */

/*! @name IO_LIMIT_UPPER_IO_BASE_UPPER_REG - I/O Limit and Base Upper 16 Bits Register. */
/*! @{ */

#define PCIE_IO_LIMIT_UPPER_IO_BASE_UPPER_REG_IO_BASE_UPPER_MASK (0xFFFFU)
#define PCIE_IO_LIMIT_UPPER_IO_BASE_UPPER_REG_IO_BASE_UPPER_SHIFT (0U)
/*! IO_BASE_UPPER - I/O Base Upper 16 Bits. If the I/O Base register indicates support for 16-bit
 *    I/O address decoding, then this register is implemented as a read-only register which return
 *    zero when read. If the I/O base register indicates support for 32-bit I/O addressing, then this
 *    register must be initialized by configuration software. If 32-bit I/O address decoding is
 *    supported, this register specifies the upper 16 bits, corresponding to Address[31:16], of the
 *    32-bit base address, that specify the I/O address range. See the PCI-to-PCI Bridge Architecture
 *    Specification for additional details. Note: The access attributes of this field are as follows: -
 *    Dbi: if (DBI_RO_WR_EN == 1) then R/W else R
 */
#define PCIE_IO_LIMIT_UPPER_IO_BASE_UPPER_REG_IO_BASE_UPPER(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IO_LIMIT_UPPER_IO_BASE_UPPER_REG_IO_BASE_UPPER_SHIFT)) & PCIE_IO_LIMIT_UPPER_IO_BASE_UPPER_REG_IO_BASE_UPPER_MASK)

#define PCIE_IO_LIMIT_UPPER_IO_BASE_UPPER_REG_IO_LIMIT_UPPER_MASK (0xFFFF0000U)
#define PCIE_IO_LIMIT_UPPER_IO_BASE_UPPER_REG_IO_LIMIT_UPPER_SHIFT (16U)
/*! IO_LIMIT_UPPER - I/O Limit Upper 16 Bits. If the I/O Limit register indicates support for 16-bit
 *    I/O address decoding, then this register is implemented as a read-only register which return
 *    zero when read. If the I/O Limit register indicates support for 32-bit I/O addressing, then
 *    this register must be initialized by configuration software. If 32-bit I/O address decoding is
 *    supported, this register specifies the upper 16 bits, corresponding to Address[31:16], of the
 *    32-bit limit address, that specify the I/O address range. See the PCI-to-PCI Bridge
 *    Architecture Specification for additional details). Note: The access attributes of this field are as
 *    follows: - Dbi: if (DBI_RO_WR_EN == 1) then R/W else R
 */
#define PCIE_IO_LIMIT_UPPER_IO_BASE_UPPER_REG_IO_LIMIT_UPPER(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IO_LIMIT_UPPER_IO_BASE_UPPER_REG_IO_LIMIT_UPPER_SHIFT)) & PCIE_IO_LIMIT_UPPER_IO_BASE_UPPER_REG_IO_LIMIT_UPPER_MASK)
/*! @} */

/*! @name TYPE1_CAP_PTR_REG - Capabilities Pointer Register. */
/*! @{ */

#define PCIE_TYPE1_CAP_PTR_REG_CAP_POINTER_MASK  (0xFFU)
#define PCIE_TYPE1_CAP_PTR_REG_CAP_POINTER_SHIFT (0U)
/*! CAP_POINTER - Capabilities Pointer. This register is used to point to a linked list of
 *    capabilities implemented by this Function. Since all PCI Express Functions are required to implement
 *    the PCI Express Capability structure, this register must point to a valid capability structure
 *    and either this structure is the PCI Express Capability structure, or a subsequent list item
 *    points to the PCI Express Capability structure. The bottom two bits are Reserved and must be set
 *    to 00b. Software must mask these bits off before using this register as a pointer in
 *    Configuration Space to the first entry of a linked list of new capabilities. Note: The access
 *    attributes of this field are as follows: - Dbi: if (DBI_RO_WR_EN == 1) then R/W(sticky) else R(sticky)
 *    Note: This register field is sticky.
 */
#define PCIE_TYPE1_CAP_PTR_REG_CAP_POINTER(x)    (((uint32_t)(((uint32_t)(x)) << PCIE_TYPE1_CAP_PTR_REG_CAP_POINTER_SHIFT)) & PCIE_TYPE1_CAP_PTR_REG_CAP_POINTER_MASK)

#define PCIE_TYPE1_CAP_PTR_REG_RSVDP_8_MASK      (0xFFFFFF00U)
#define PCIE_TYPE1_CAP_PTR_REG_RSVDP_8_SHIFT     (8U)
/*! RSVDP_8 - Reserved for future use. */
#define PCIE_TYPE1_CAP_PTR_REG_RSVDP_8(x)        (((uint32_t)(((uint32_t)(x)) << PCIE_TYPE1_CAP_PTR_REG_RSVDP_8_SHIFT)) & PCIE_TYPE1_CAP_PTR_REG_RSVDP_8_MASK)
/*! @} */

/*! @name TYPE1_EXP_ROM_BASE_REG - Expansion ROM Base Address Register. */
/*! @{ */

#define PCIE_TYPE1_EXP_ROM_BASE_REG_ROM_BAR_ENABLE_MASK (0x1U)
#define PCIE_TYPE1_EXP_ROM_BASE_REG_ROM_BAR_ENABLE_SHIFT (0U)
/*! ROM_BAR_ENABLE - Expansion ROM Enable. This bit controls whether or not the Function accepts
 *    accesses to its expansion ROM. When this bit is 0b, the Function's expansion ROM address space is
 *    disabled. When the bit is 1b, address decoding is enabled using the parameters in the other
 *    part of the Expansion ROM Base Address register. The Memory Space Enable bit in the Command
 *    register has precedence over the Expansion ROM Enable bit. A Function must claim accesses to its
 *    expansion ROM only if both the Memory Space Enable bit and the Expansion ROM Enable bit are
 *    set. Note: The access attributes of this field are as follows: - Dbi: R/W
 */
#define PCIE_TYPE1_EXP_ROM_BASE_REG_ROM_BAR_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TYPE1_EXP_ROM_BASE_REG_ROM_BAR_ENABLE_SHIFT)) & PCIE_TYPE1_EXP_ROM_BASE_REG_ROM_BAR_ENABLE_MASK)

#define PCIE_TYPE1_EXP_ROM_BASE_REG_RSVDP_1_MASK (0x7FEU)
#define PCIE_TYPE1_EXP_ROM_BASE_REG_RSVDP_1_SHIFT (1U)
/*! RSVDP_1 - Reserved for future use. */
#define PCIE_TYPE1_EXP_ROM_BASE_REG_RSVDP_1(x)   (((uint32_t)(((uint32_t)(x)) << PCIE_TYPE1_EXP_ROM_BASE_REG_RSVDP_1_SHIFT)) & PCIE_TYPE1_EXP_ROM_BASE_REG_RSVDP_1_MASK)

#define PCIE_TYPE1_EXP_ROM_BASE_REG_EXP_ROM_BASE_ADDRESS_MASK (0xFFFFF800U)
#define PCIE_TYPE1_EXP_ROM_BASE_REG_EXP_ROM_BASE_ADDRESS_SHIFT (11U)
/*! EXP_ROM_BASE_ADDRESS - Expansion ROM Base Address. Upper 21 bits of the Expansion ROM base
 *    address. The number of bits (out of these 21) that a Function actually implements depends on how
 *    much address space the Function requires. The mask for this ROM BAR exists (if implemented) as a
 *    shadow register at this address. The assertion of CS2 (that is, assert the dbi_cs2 input, or
 *    the CS2 address bit for the AXI bridge) is required to write to the second register at this
 *    address. Note: The access attributes of this field are as follows: - Dbi: R/W
 */
#define PCIE_TYPE1_EXP_ROM_BASE_REG_EXP_ROM_BASE_ADDRESS(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TYPE1_EXP_ROM_BASE_REG_EXP_ROM_BASE_ADDRESS_SHIFT)) & PCIE_TYPE1_EXP_ROM_BASE_REG_EXP_ROM_BASE_ADDRESS_MASK)
/*! @} */

/*! @name BRIDGE_CTRL_INT_PIN_INT_LINE_REG - Bridge Control, Interrupt Pin, and Interrupt Line Register. */
/*! @{ */

#define PCIE_BRIDGE_CTRL_INT_PIN_INT_LINE_REG_INT_LINE_MASK (0xFFU)
#define PCIE_BRIDGE_CTRL_INT_PIN_INT_LINE_REG_INT_LINE_SHIFT (0U)
/*! INT_LINE - Interrupt Line. The Interrupt Line register communicates interrupt line routing
 *    information. The register must be implemented by any Function that uses an interrupt pin. Values in
 *    this register are programmed by system software and are system architecture specific. The
 *    Function itself does not use this value; rather the value in this register is used by device
 *    drivers and operating systems.
 */
#define PCIE_BRIDGE_CTRL_INT_PIN_INT_LINE_REG_INT_LINE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_BRIDGE_CTRL_INT_PIN_INT_LINE_REG_INT_LINE_SHIFT)) & PCIE_BRIDGE_CTRL_INT_PIN_INT_LINE_REG_INT_LINE_MASK)

#define PCIE_BRIDGE_CTRL_INT_PIN_INT_LINE_REG_INT_PIN_MASK (0xFF00U)
#define PCIE_BRIDGE_CTRL_INT_PIN_INT_LINE_REG_INT_PIN_SHIFT (8U)
/*! INT_PIN - Interrupt PIN. The Interrupt Pin register register that identifies the legacy
 *    interrupt Message(s) the Function uses. Valid values are: - 01h, 02h, 03h, and 04h: map to legacy
 *    interrupt Messages for INTA, INTB, INTC, and INTD respectively. - 00h: indicates that the Function
 *    uses no legacy interrupt Message(s). - 05h through FFh: Reserved. PCI Express defines one
 *    legacy interrupt Message for a single Function device and up to four legacy interrupt Messages
 *    for a multi-Function device. For a single Function device, only INTA may be used. Any Function
 *    on a multi-Function device can use any of the INTx Messages. If a device implements a single
 *    legacy interrupt Message, it must be INTA; if it implements two legacy interrupt Messages, they
 *    must be INTA and INTB; and so forth. For a multi-Function device, all Functions may use the
 *    same INTx Message or each may have its own (up to a maximum of four Functions) or any
 *    combination thereof. A single Function can never generate an interrupt request on more than one INTx
 *    Message. Note: The access attributes of this field are as follows: - Dbi: if (DBI_RO_WR_EN == 1)
 *    then R/W else R Note: This register field is sticky.
 */
#define PCIE_BRIDGE_CTRL_INT_PIN_INT_LINE_REG_INT_PIN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_BRIDGE_CTRL_INT_PIN_INT_LINE_REG_INT_PIN_SHIFT)) & PCIE_BRIDGE_CTRL_INT_PIN_INT_LINE_REG_INT_PIN_MASK)

#define PCIE_BRIDGE_CTRL_INT_PIN_INT_LINE_REG_PERE_MASK (0x10000U)
#define PCIE_BRIDGE_CTRL_INT_PIN_INT_LINE_REG_PERE_SHIFT (16U)
/*! PERE - Parity Error Response Enable. This bit controls the logging of poisoned TLPs in the
 *    Master Data Parity Error bit in the Secondary Status register.
 */
#define PCIE_BRIDGE_CTRL_INT_PIN_INT_LINE_REG_PERE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_BRIDGE_CTRL_INT_PIN_INT_LINE_REG_PERE_SHIFT)) & PCIE_BRIDGE_CTRL_INT_PIN_INT_LINE_REG_PERE_MASK)

#define PCIE_BRIDGE_CTRL_INT_PIN_INT_LINE_REG_SERR_EN_MASK (0x20000U)
#define PCIE_BRIDGE_CTRL_INT_PIN_INT_LINE_REG_SERR_EN_SHIFT (17U)
/*! SERR_EN - SERR# Enable. This bit controls forwarding of ERR_COR, ERR_NONFATAL and ERR_FATAL from secondary to primary. */
#define PCIE_BRIDGE_CTRL_INT_PIN_INT_LINE_REG_SERR_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_BRIDGE_CTRL_INT_PIN_INT_LINE_REG_SERR_EN_SHIFT)) & PCIE_BRIDGE_CTRL_INT_PIN_INT_LINE_REG_SERR_EN_MASK)

#define PCIE_BRIDGE_CTRL_INT_PIN_INT_LINE_REG_ISA_EN_MASK (0x40000U)
#define PCIE_BRIDGE_CTRL_INT_PIN_INT_LINE_REG_ISA_EN_SHIFT (18U)
/*! ISA_EN - ISA Enable. Modifies the response by the bridge to ISA I/O addresses. This applies only
 *    to I/O addresses that are enabled by the I/O Base and I/O Limit registers and are in the
 *    first 64 KB of I/O address space (0000 0000h to 0000 FFFFh). If this bit is set, the bridge will
 *    block any forwarding from primary to secondary of I/O transactions addressing the last 768
 *    bytes in each 1-KB block. In the opposite direction (secondary to primary), I/O transactions will
 *    be forwarded if they address the last 768 bytes in each 1-KB block. The following actions are
 *    taken based on the value of the ISA_EN bit: - 0b: Forward downstream all I/O addresses in the
 *    address range defined by the I/O Base and I/O Limit registers - 1b: Forward upstream ISA I/O
 *    addresses in the address range defined by the I/O Base and I/O Limit registers that are in the
 *    first 64 KB of PCI I/O address space (top 768 bytes of each 1-KB block.
 */
#define PCIE_BRIDGE_CTRL_INT_PIN_INT_LINE_REG_ISA_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_BRIDGE_CTRL_INT_PIN_INT_LINE_REG_ISA_EN_SHIFT)) & PCIE_BRIDGE_CTRL_INT_PIN_INT_LINE_REG_ISA_EN_MASK)

#define PCIE_BRIDGE_CTRL_INT_PIN_INT_LINE_REG_VGA_EN_MASK (0x80000U)
#define PCIE_BRIDGE_CTRL_INT_PIN_INT_LINE_REG_VGA_EN_SHIFT (19U)
/*! VGA_EN - VGA Enable. Modifies the response by the bridge to VGA compatible addresses. If the VGA
 *    Enable bit is set, the bridge will positively decode and forward the following accesses on
 *    the primary interface to the secondary interface (and, conversely, block the forwarding of these
 *    addresses from the secondary to primary interface): - Memory accesses in the range 000A 0000h
 *    to 000B FFFFh - I/O addresses in the first 64 KB of the I/O address space (Address[31:16] are
 *    0000h) where Address[9:0] are in the ranges 3B0h to 3BBh and 3C0h to 3DFh (inclusive of ISA
 *    address aliases determined by the setting of VGA 16-bit Decode ) If the VGA Enable bit is set,
 *    forwarding of these accesses is independent of the I/O address range and memory address ranges
 *    defined by the I/O Base and Limit registers, the Memory Base and Limit registers, and the
 *    Prefetchable Memory Base and Limit registers of the bridge. (Forwarding of these accesses is also
 *    independent of the setting of the ISA Enable bit (in the Bridge Control register) when the
 *    VGA Enable bit is set. Forwarding of these accesses is qualified by the I/O Space Enable and
 *    Memory Space Enable bits in the Command register.) The following actions are taken based on the
 *    value of the VGA_EN bit: - 0b: Do not forward VGA compatible memory and I/O addresses from the
 *    primary to the secondary interface (addresses defined above) unless they are enabled for
 *    forwarding by the defined I/O and memory address ranges - 1b: Forward VGA compatible memory and I/O
 *    addresses (addresses defined above) from the primary interface to the secondary interface (if
 *    the I/O Space Enable and Memory Space Enable bits are set) independent of the I/O and memory
 *    address ranges and independent of the ISA Enable bit For Functions that do not support VGA,
 *    the controller hardwires this bit to 0b. Note: The access attributes of this field are as
 *    follows: - Dbi: R
 */
#define PCIE_BRIDGE_CTRL_INT_PIN_INT_LINE_REG_VGA_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_BRIDGE_CTRL_INT_PIN_INT_LINE_REG_VGA_EN_SHIFT)) & PCIE_BRIDGE_CTRL_INT_PIN_INT_LINE_REG_VGA_EN_MASK)

#define PCIE_BRIDGE_CTRL_INT_PIN_INT_LINE_REG_VGA_16B_DEC_MASK (0x100000U)
#define PCIE_BRIDGE_CTRL_INT_PIN_INT_LINE_REG_VGA_16B_DEC_SHIFT (20U)
/*! VGA_16B_DEC - VGA 16 bit decode. This bit only has meaning if VGA Enable bit is set. This bit
 *    enables system configuration software to select between 10-bit and 16-bit I/O address decoding
 *    for all VGA I/O register accesses that are forwarded from primary to secondary. The following
 *    actions are taken based on the value of the VGA_16B_DEC bit: - 0b: Execute 10-bit address
 *    decodes on VGA I/O accesses - 1b: Execute 16-bit address decodes on VGA I/O accesses For Functions
 *    that do not support VGA, the controller hardwires this bit to 0b. Note: The access attributes
 *    of this field are as follows: - Dbi: R
 */
#define PCIE_BRIDGE_CTRL_INT_PIN_INT_LINE_REG_VGA_16B_DEC(x) (((uint32_t)(((uint32_t)(x)) << PCIE_BRIDGE_CTRL_INT_PIN_INT_LINE_REG_VGA_16B_DEC_SHIFT)) & PCIE_BRIDGE_CTRL_INT_PIN_INT_LINE_REG_VGA_16B_DEC_MASK)

#define PCIE_BRIDGE_CTRL_INT_PIN_INT_LINE_REG_MSTR_ABORT_MODE_MASK (0x200000U)
#define PCIE_BRIDGE_CTRL_INT_PIN_INT_LINE_REG_MSTR_ABORT_MODE_SHIFT (21U)
/*! MSTR_ABORT_MODE - Master Abort Mode. This bit was originally described in the PCI-to-PCI Bridge
 *    Architecture Specification. Its functionality does not apply to PCI Express. The controller
 *    hardwires this bit to 0b. Note: The access attributes of this field are as follows: - Dbi: R/W
 */
#define PCIE_BRIDGE_CTRL_INT_PIN_INT_LINE_REG_MSTR_ABORT_MODE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_BRIDGE_CTRL_INT_PIN_INT_LINE_REG_MSTR_ABORT_MODE_SHIFT)) & PCIE_BRIDGE_CTRL_INT_PIN_INT_LINE_REG_MSTR_ABORT_MODE_MASK)

#define PCIE_BRIDGE_CTRL_INT_PIN_INT_LINE_REG_SBR_MASK (0x400000U)
#define PCIE_BRIDGE_CTRL_INT_PIN_INT_LINE_REG_SBR_SHIFT (22U)
/*! SBR - Secondary Bus Reset. Setting this bit triggers a hot reset on the corresponding PCI
 *    Express Port. Software must ensure a minimum reset duration (Trst) as defined in the PCI Local Bus
 *    Specification. Software and systems must honor first-access-following-reset timing
 *    requirements, unless the Readiness Notifications mechanism is used or if the Immediate Readiness bit in
 *    the relevant Function's Status Register register is set. Port configuration registers must not
 *    be changed, except as required to update Port status.
 */
#define PCIE_BRIDGE_CTRL_INT_PIN_INT_LINE_REG_SBR(x) (((uint32_t)(((uint32_t)(x)) << PCIE_BRIDGE_CTRL_INT_PIN_INT_LINE_REG_SBR_SHIFT)) & PCIE_BRIDGE_CTRL_INT_PIN_INT_LINE_REG_SBR_MASK)

#define PCIE_BRIDGE_CTRL_INT_PIN_INT_LINE_REG_BRIDGE_CTRL_RESERV_MASK (0xFF800000U)
#define PCIE_BRIDGE_CTRL_INT_PIN_INT_LINE_REG_BRIDGE_CTRL_RESERV_SHIFT (23U)
/*! BRIDGE_CTRL_RESERV - Reserved. */
#define PCIE_BRIDGE_CTRL_INT_PIN_INT_LINE_REG_BRIDGE_CTRL_RESERV(x) (((uint32_t)(((uint32_t)(x)) << PCIE_BRIDGE_CTRL_INT_PIN_INT_LINE_REG_BRIDGE_CTRL_RESERV_SHIFT)) & PCIE_BRIDGE_CTRL_INT_PIN_INT_LINE_REG_BRIDGE_CTRL_RESERV_MASK)
/*! @} */

/*! @name CAP_ID_NXT_PTR_REG - Power Management Capabilities Register. */
/*! @{ */

#define PCIE_CAP_ID_NXT_PTR_REG_PM_CAP_ID_MASK   (0xFFU)
#define PCIE_CAP_ID_NXT_PTR_REG_PM_CAP_ID_SHIFT  (0U)
/*! PM_CAP_ID - Power Management Capability ID. For a description of this standard PCIe register
 *    field, see the PCI Express Specification.
 */
#define PCIE_CAP_ID_NXT_PTR_REG_PM_CAP_ID(x)     (((uint32_t)(((uint32_t)(x)) << PCIE_CAP_ID_NXT_PTR_REG_PM_CAP_ID_SHIFT)) & PCIE_CAP_ID_NXT_PTR_REG_PM_CAP_ID_MASK)

#define PCIE_CAP_ID_NXT_PTR_REG_PM_NEXT_POINTER_MASK (0xFF00U)
#define PCIE_CAP_ID_NXT_PTR_REG_PM_NEXT_POINTER_SHIFT (8U)
/*! PM_NEXT_POINTER - Next Capability Pointer. For a description of this standard PCIe register
 *    field, see the PCI Express Specification. Note: The access attributes of this field are as
 *    follows: - Dbi: if (DBI_RO_WR_EN == 1) then R/W else R Note: This register field is sticky.
 */
#define PCIE_CAP_ID_NXT_PTR_REG_PM_NEXT_POINTER(x) (((uint32_t)(((uint32_t)(x)) << PCIE_CAP_ID_NXT_PTR_REG_PM_NEXT_POINTER_SHIFT)) & PCIE_CAP_ID_NXT_PTR_REG_PM_NEXT_POINTER_MASK)

#define PCIE_CAP_ID_NXT_PTR_REG_PM_SPEC_VER_MASK (0x70000U)
#define PCIE_CAP_ID_NXT_PTR_REG_PM_SPEC_VER_SHIFT (16U)
/*! PM_SPEC_VER - Power Management Spec Version. For a description of this standard PCIe register
 *    field, see the PCI Express Specification. Note: The access attributes of this field are as
 *    follows: - Dbi: if (DBI_RO_WR_EN == 1) then R/W else R Note: This register field is sticky.
 */
#define PCIE_CAP_ID_NXT_PTR_REG_PM_SPEC_VER(x)   (((uint32_t)(((uint32_t)(x)) << PCIE_CAP_ID_NXT_PTR_REG_PM_SPEC_VER_SHIFT)) & PCIE_CAP_ID_NXT_PTR_REG_PM_SPEC_VER_MASK)

#define PCIE_CAP_ID_NXT_PTR_REG_PME_CLK_MASK     (0x80000U)
#define PCIE_CAP_ID_NXT_PTR_REG_PME_CLK_SHIFT    (19U)
/*! PME_CLK - PCI Clock Requirement. For a description of this standard PCIe register field, see the
 *    PCI Express Specification. Note: This register field is sticky.
 */
#define PCIE_CAP_ID_NXT_PTR_REG_PME_CLK(x)       (((uint32_t)(((uint32_t)(x)) << PCIE_CAP_ID_NXT_PTR_REG_PME_CLK_SHIFT)) & PCIE_CAP_ID_NXT_PTR_REG_PME_CLK_MASK)

#define PCIE_CAP_ID_NXT_PTR_REG_DSI_MASK         (0x200000U)
#define PCIE_CAP_ID_NXT_PTR_REG_DSI_SHIFT        (21U)
/*! DSI - Device Specific Initialization Bit. For a description of this standard PCIe register
 *    field, see the PCI Express Specification. Note: The access attributes of this field are as follows:
 *    - Dbi: if (DBI_RO_WR_EN == 1) then R/W else R Note: This register field is sticky.
 */
#define PCIE_CAP_ID_NXT_PTR_REG_DSI(x)           (((uint32_t)(((uint32_t)(x)) << PCIE_CAP_ID_NXT_PTR_REG_DSI_SHIFT)) & PCIE_CAP_ID_NXT_PTR_REG_DSI_MASK)

#define PCIE_CAP_ID_NXT_PTR_REG_AUX_CURR_MASK    (0x1C00000U)
#define PCIE_CAP_ID_NXT_PTR_REG_AUX_CURR_SHIFT   (22U)
/*! AUX_CURR - Auxiliary Current Requirements. For a description of this standard PCIe register
 *    field, see the PCI Express Specification. Note: The access attributes of this field are as
 *    follows: - Dbi: if (DBI_RO_WR_EN == 1) then R/W else R Note: This register field is sticky.
 */
#define PCIE_CAP_ID_NXT_PTR_REG_AUX_CURR(x)      (((uint32_t)(((uint32_t)(x)) << PCIE_CAP_ID_NXT_PTR_REG_AUX_CURR_SHIFT)) & PCIE_CAP_ID_NXT_PTR_REG_AUX_CURR_MASK)

#define PCIE_CAP_ID_NXT_PTR_REG_D1_SUPPORT_MASK  (0x2000000U)
#define PCIE_CAP_ID_NXT_PTR_REG_D1_SUPPORT_SHIFT (25U)
/*! D1_SUPPORT - D1 State Support. For a description of this standard PCIe register field, see the
 *    PCI Express Specification. Note: The access attributes of this field are as follows: - Dbi: if
 *    (DBI_RO_WR_EN == 1) then R/W else R Note: This register field is sticky.
 */
#define PCIE_CAP_ID_NXT_PTR_REG_D1_SUPPORT(x)    (((uint32_t)(((uint32_t)(x)) << PCIE_CAP_ID_NXT_PTR_REG_D1_SUPPORT_SHIFT)) & PCIE_CAP_ID_NXT_PTR_REG_D1_SUPPORT_MASK)

#define PCIE_CAP_ID_NXT_PTR_REG_D2_SUPPORT_MASK  (0x4000000U)
#define PCIE_CAP_ID_NXT_PTR_REG_D2_SUPPORT_SHIFT (26U)
/*! D2_SUPPORT - D2 State Support. For a description of this standard PCIe register field, see the
 *    PCI Express Specification. Note: The access attributes of this field are as follows: - Dbi: if
 *    (DBI_RO_WR_EN == 1) then R/W else R Note: This register field is sticky.
 */
#define PCIE_CAP_ID_NXT_PTR_REG_D2_SUPPORT(x)    (((uint32_t)(((uint32_t)(x)) << PCIE_CAP_ID_NXT_PTR_REG_D2_SUPPORT_SHIFT)) & PCIE_CAP_ID_NXT_PTR_REG_D2_SUPPORT_MASK)

#define PCIE_CAP_ID_NXT_PTR_REG_PME_SUPPORT_MASK (0xF8000000U)
#define PCIE_CAP_ID_NXT_PTR_REG_PME_SUPPORT_SHIFT (27U)
/*! PME_SUPPORT - Power Management Event Support. For a description of this standard PCIe register
 *    field, see the PCI Express Specification. The read value from this field is the write value &&
 *    (sys_aux_pwr_det, 1'b1, D2_SUPPORT, D1_SUPPORT, 1'b1), where D1_SUPPORT and D2_SUPPORT are
 *    fields in this register. The reset value PME_SUPPORT_n && (sys_aux_pwr_det, 1'b1, D2_SUPPORT,
 *    D1_SUPPORT, 1'b1), where PME_SUPPORT_n is a configuration parameter. Note: The access attributes
 *    of this field are as follows: - Dbi: if (DBI_RO_WR_EN == 1) then R/W else R Note: This
 *    register field is sticky.
 */
#define PCIE_CAP_ID_NXT_PTR_REG_PME_SUPPORT(x)   (((uint32_t)(((uint32_t)(x)) << PCIE_CAP_ID_NXT_PTR_REG_PME_SUPPORT_SHIFT)) & PCIE_CAP_ID_NXT_PTR_REG_PME_SUPPORT_MASK)
/*! @} */

/*! @name CON_STATUS_REG - Power Management Control and Status Register. */
/*! @{ */

#define PCIE_CON_STATUS_REG_POWER_STATE_MASK     (0x3U)
#define PCIE_CON_STATUS_REG_POWER_STATE_SHIFT    (0U)
/*! POWER_STATE - Power State. For a description of this standard PCIe register field, see the PCI
 *    Express Specification. You can write to this register. However, the read-back value is the
 *    actual power state, not the write value. Note: The access attributes of this field are as follows:
 *    - Dbi: R/W
 */
#define PCIE_CON_STATUS_REG_POWER_STATE(x)       (((uint32_t)(((uint32_t)(x)) << PCIE_CON_STATUS_REG_POWER_STATE_SHIFT)) & PCIE_CON_STATUS_REG_POWER_STATE_MASK)

#define PCIE_CON_STATUS_REG_RSVDP_2_MASK         (0x4U)
#define PCIE_CON_STATUS_REG_RSVDP_2_SHIFT        (2U)
/*! RSVDP_2 - Reserved for future use. */
#define PCIE_CON_STATUS_REG_RSVDP_2(x)           (((uint32_t)(((uint32_t)(x)) << PCIE_CON_STATUS_REG_RSVDP_2_SHIFT)) & PCIE_CON_STATUS_REG_RSVDP_2_MASK)

#define PCIE_CON_STATUS_REG_NO_SOFT_RST_MASK     (0x8U)
#define PCIE_CON_STATUS_REG_NO_SOFT_RST_SHIFT    (3U)
/*! NO_SOFT_RST - No soft Reset. For a description of this standard PCIe register field, see the PCI
 *    Express Specification. Note: The access attributes of this field are as follows: - Dbi: if
 *    (DBI_RO_WR_EN == 1) then R/W else R Note: This register field is sticky.
 */
#define PCIE_CON_STATUS_REG_NO_SOFT_RST(x)       (((uint32_t)(((uint32_t)(x)) << PCIE_CON_STATUS_REG_NO_SOFT_RST_SHIFT)) & PCIE_CON_STATUS_REG_NO_SOFT_RST_MASK)

#define PCIE_CON_STATUS_REG_RSVDP_4_MASK         (0xF0U)
#define PCIE_CON_STATUS_REG_RSVDP_4_SHIFT        (4U)
/*! RSVDP_4 - Reserved for future use. */
#define PCIE_CON_STATUS_REG_RSVDP_4(x)           (((uint32_t)(((uint32_t)(x)) << PCIE_CON_STATUS_REG_RSVDP_4_SHIFT)) & PCIE_CON_STATUS_REG_RSVDP_4_MASK)

#define PCIE_CON_STATUS_REG_PME_ENABLE_MASK      (0x100U)
#define PCIE_CON_STATUS_REG_PME_ENABLE_SHIFT     (8U)
/*! PME_ENABLE - PME Enable. For a description of this standard PCIe register field, see the PCI
 *    Express Specification. The PMC registers this value under aux power. Sometimes it might remember
 *    the old value, even if you try to clear it by writing '0'. Note: This register field is sticky.
 */
#define PCIE_CON_STATUS_REG_PME_ENABLE(x)        (((uint32_t)(((uint32_t)(x)) << PCIE_CON_STATUS_REG_PME_ENABLE_SHIFT)) & PCIE_CON_STATUS_REG_PME_ENABLE_MASK)

#define PCIE_CON_STATUS_REG_DATA_SELECT_MASK     (0x1E00U)
#define PCIE_CON_STATUS_REG_DATA_SELECT_SHIFT    (9U)
/*! DATA_SELECT - Data Select. For a description of this standard PCIe register field, see the PCI Express Specification. */
#define PCIE_CON_STATUS_REG_DATA_SELECT(x)       (((uint32_t)(((uint32_t)(x)) << PCIE_CON_STATUS_REG_DATA_SELECT_SHIFT)) & PCIE_CON_STATUS_REG_DATA_SELECT_MASK)

#define PCIE_CON_STATUS_REG_DATA_SCALE_MASK      (0x6000U)
#define PCIE_CON_STATUS_REG_DATA_SCALE_SHIFT     (13U)
/*! DATA_SCALE - Data Scaling Factor. For a description of this standard PCIe register field, see the PCI Express Specification. */
#define PCIE_CON_STATUS_REG_DATA_SCALE(x)        (((uint32_t)(((uint32_t)(x)) << PCIE_CON_STATUS_REG_DATA_SCALE_SHIFT)) & PCIE_CON_STATUS_REG_DATA_SCALE_MASK)

#define PCIE_CON_STATUS_REG_PME_STATUS_MASK      (0x8000U)
#define PCIE_CON_STATUS_REG_PME_STATUS_SHIFT     (15U)
/*! PME_STATUS - PME Status. For a description of this standard PCIe register field, see the PCI Express Specification. */
#define PCIE_CON_STATUS_REG_PME_STATUS(x)        (((uint32_t)(((uint32_t)(x)) << PCIE_CON_STATUS_REG_PME_STATUS_SHIFT)) & PCIE_CON_STATUS_REG_PME_STATUS_MASK)

#define PCIE_CON_STATUS_REG_RSVDP_16_MASK        (0x3F0000U)
#define PCIE_CON_STATUS_REG_RSVDP_16_SHIFT       (16U)
/*! RSVDP_16 - Reserved for future use. */
#define PCIE_CON_STATUS_REG_RSVDP_16(x)          (((uint32_t)(((uint32_t)(x)) << PCIE_CON_STATUS_REG_RSVDP_16_SHIFT)) & PCIE_CON_STATUS_REG_RSVDP_16_MASK)

#define PCIE_CON_STATUS_REG_B2_B3_SUPPORT_MASK   (0x400000U)
#define PCIE_CON_STATUS_REG_B2_B3_SUPPORT_SHIFT  (22U)
/*! B2_B3_SUPPORT - B2B3 Support for D3hot. For a description of this standard PCIe register field, see the PCI Express Specification. */
#define PCIE_CON_STATUS_REG_B2_B3_SUPPORT(x)     (((uint32_t)(((uint32_t)(x)) << PCIE_CON_STATUS_REG_B2_B3_SUPPORT_SHIFT)) & PCIE_CON_STATUS_REG_B2_B3_SUPPORT_MASK)

#define PCIE_CON_STATUS_REG_BUS_PWR_CLK_CON_EN_MASK (0x800000U)
#define PCIE_CON_STATUS_REG_BUS_PWR_CLK_CON_EN_SHIFT (23U)
/*! BUS_PWR_CLK_CON_EN - Bus Power/Clock Control Enable. For a description of this standard PCIe
 *    register field, see the PCI Express Specification.
 */
#define PCIE_CON_STATUS_REG_BUS_PWR_CLK_CON_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_CON_STATUS_REG_BUS_PWR_CLK_CON_EN_SHIFT)) & PCIE_CON_STATUS_REG_BUS_PWR_CLK_CON_EN_MASK)

#define PCIE_CON_STATUS_REG_DATA_REG_ADD_INFO_MASK (0xFF000000U)
#define PCIE_CON_STATUS_REG_DATA_REG_ADD_INFO_SHIFT (24U)
/*! DATA_REG_ADD_INFO - Power Data Information Register. For a description of this standard PCIe
 *    register field, see the PCI Express Specification.
 */
#define PCIE_CON_STATUS_REG_DATA_REG_ADD_INFO(x) (((uint32_t)(((uint32_t)(x)) << PCIE_CON_STATUS_REG_DATA_REG_ADD_INFO_SHIFT)) & PCIE_CON_STATUS_REG_DATA_REG_ADD_INFO_MASK)
/*! @} */

/*! @name PCI_MSI_CAP_ID_NEXT_CTRL_REG - MSI Capability ID, Next Pointer, Capability/Control Registers. */
/*! @{ */

#define PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_MSI_CAP_ID_MASK (0xFFU)
#define PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_MSI_CAP_ID_SHIFT (0U)
/*! PCI_MSI_CAP_ID - MSI Capability ID. For a description of this standard PCIe register field, see the PCI Express Specification. */
#define PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_MSI_CAP_ID(x) (((uint32_t)(((uint32_t)(x)) << PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_MSI_CAP_ID_SHIFT)) & PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_MSI_CAP_ID_MASK)

#define PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_MSI_CAP_NEXT_OFFSET_MASK (0xFF00U)
#define PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_MSI_CAP_NEXT_OFFSET_SHIFT (8U)
/*! PCI_MSI_CAP_NEXT_OFFSET - MSI Capability Next Pointer. For a description of this standard PCIe
 *    register field, see the PCI Express Specification. Note: The access attributes of this field
 *    are as follows: - Dbi: if (DBI_RO_WR_EN == 1) then R/W else R Note: This register field is
 *    sticky.
 */
#define PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_MSI_CAP_NEXT_OFFSET(x) (((uint32_t)(((uint32_t)(x)) << PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_MSI_CAP_NEXT_OFFSET_SHIFT)) & PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_MSI_CAP_NEXT_OFFSET_MASK)

#define PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_MSI_ENABLE_MASK (0x10000U)
#define PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_MSI_ENABLE_SHIFT (16U)
/*! PCI_MSI_ENABLE - MSI Enable. For a description of this standard PCIe register field, see the PCI Express Specification. */
#define PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_MSI_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_MSI_ENABLE_SHIFT)) & PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_MSI_ENABLE_MASK)

#define PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_MSI_MULTIPLE_MSG_CAP_MASK (0xE0000U)
#define PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_MSI_MULTIPLE_MSG_CAP_SHIFT (17U)
/*! PCI_MSI_MULTIPLE_MSG_CAP - MSI Multiple Message Capable. For a description of this standard PCIe
 *    register field, see the PCI Express Specification. Note: The access attributes of this field
 *    are as follows: - Dbi: if (DBI_RO_WR_EN == 1) then R/W else R Note: This register field is
 *    sticky.
 */
#define PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_MSI_MULTIPLE_MSG_CAP(x) (((uint32_t)(((uint32_t)(x)) << PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_MSI_MULTIPLE_MSG_CAP_SHIFT)) & PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_MSI_MULTIPLE_MSG_CAP_MASK)

#define PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_MSI_MULTIPLE_MSG_EN_MASK (0x700000U)
#define PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_MSI_MULTIPLE_MSG_EN_SHIFT (20U)
/*! PCI_MSI_MULTIPLE_MSG_EN - MSI Multiple Message Enable. For a description of this standard PCIe register field, see the PCI Express Specification. */
#define PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_MSI_MULTIPLE_MSG_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_MSI_MULTIPLE_MSG_EN_SHIFT)) & PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_MSI_MULTIPLE_MSG_EN_MASK)

#define PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_MSI_64_BIT_ADDR_CAP_MASK (0x800000U)
#define PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_MSI_64_BIT_ADDR_CAP_SHIFT (23U)
/*! PCI_MSI_64_BIT_ADDR_CAP - MSI 64-bit Address Capable. For a description of this standard PCIe
 *    register field, see the PCI Express Specification. Note: The access attributes of this field are
 *    as follows: - Dbi: if (DBI_RO_WR_EN == 1) then R/W else R Note: This register field is sticky.
 */
#define PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_MSI_64_BIT_ADDR_CAP(x) (((uint32_t)(((uint32_t)(x)) << PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_MSI_64_BIT_ADDR_CAP_SHIFT)) & PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_MSI_64_BIT_ADDR_CAP_MASK)

#define PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_PVM_SUPPORT_MASK (0x1000000U)
#define PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_PVM_SUPPORT_SHIFT (24U)
/*! PCI_PVM_SUPPORT - MSI Per Vector Masking Capable. For a description of this standard PCIe
 *    register field, see the PCI Express Specification.
 */
#define PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_PVM_SUPPORT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_PVM_SUPPORT_SHIFT)) & PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_PVM_SUPPORT_MASK)

#define PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_MSI_EXT_DATA_CAP_MASK (0x2000000U)
#define PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_MSI_EXT_DATA_CAP_SHIFT (25U)
/*! PCI_MSI_EXT_DATA_CAP - Extended Message Data Capable. For a description of this standard PCIe
 *    register, see the PCI-SIG ECN for Extended MSI Data, Feb 24, 2016, affecting PCI Express
 *    Specification. Note: The access attributes of this field are as follows: - Dbi: if (DBI_RO_WR_EN ==
 *    1) then R/W else R Note: This register field is sticky.
 */
#define PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_MSI_EXT_DATA_CAP(x) (((uint32_t)(((uint32_t)(x)) << PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_MSI_EXT_DATA_CAP_SHIFT)) & PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_MSI_EXT_DATA_CAP_MASK)

#define PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_MSI_EXT_DATA_EN_MASK (0x4000000U)
#define PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_MSI_EXT_DATA_EN_SHIFT (26U)
/*! PCI_MSI_EXT_DATA_EN - Extended Message Data Enable. For a description of this standard PCIe
 *    register, see the PCI-SIG ECN for Extended MSI Data, Feb 24, 2016, affecting PCI Express
 *    Specification. Note: The access attributes of this field are as follows: - Dbi:
 *    PCI_MSI_CAP_ID_NEXT_CTRL_REG.PCI_MSI_EXT_DATA_CAP ? RW : RO
 */
#define PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_MSI_EXT_DATA_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_MSI_EXT_DATA_EN_SHIFT)) & PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_PCI_MSI_EXT_DATA_EN_MASK)

#define PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_RSVDP_27_MASK (0xF8000000U)
#define PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_RSVDP_27_SHIFT (27U)
/*! RSVDP_27 - Reserved for future use. */
#define PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_RSVDP_27(x) (((uint32_t)(((uint32_t)(x)) << PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_RSVDP_27_SHIFT)) & PCIE_PCI_MSI_CAP_ID_NEXT_CTRL_REG_RSVDP_27_MASK)
/*! @} */

/*! @name MSI_CAP_OFF_04H_REG - MSI Message Lower Address Register. */
/*! @{ */

#define PCIE_MSI_CAP_OFF_04H_REG_RSVDP_0_MASK    (0x3U)
#define PCIE_MSI_CAP_OFF_04H_REG_RSVDP_0_SHIFT   (0U)
/*! RSVDP_0 - Reserved for future use. */
#define PCIE_MSI_CAP_OFF_04H_REG_RSVDP_0(x)      (((uint32_t)(((uint32_t)(x)) << PCIE_MSI_CAP_OFF_04H_REG_RSVDP_0_SHIFT)) & PCIE_MSI_CAP_OFF_04H_REG_RSVDP_0_MASK)

#define PCIE_MSI_CAP_OFF_04H_REG_PCI_MSI_CAP_OFF_04H_MASK (0xFFFFFFFCU)
#define PCIE_MSI_CAP_OFF_04H_REG_PCI_MSI_CAP_OFF_04H_SHIFT (2U)
/*! PCI_MSI_CAP_OFF_04H - MSI Message Lower Address Field. For a description of this standard PCIe
 *    register field, see the PCI Express Specification. Note: The access attributes of this field
 *    are as follows: - Dbi: R/W
 */
#define PCIE_MSI_CAP_OFF_04H_REG_PCI_MSI_CAP_OFF_04H(x) (((uint32_t)(((uint32_t)(x)) << PCIE_MSI_CAP_OFF_04H_REG_PCI_MSI_CAP_OFF_04H_SHIFT)) & PCIE_MSI_CAP_OFF_04H_REG_PCI_MSI_CAP_OFF_04H_MASK)
/*! @} */

/*! @name MSI_CAP_OFF_08H_REG - For a 32 bit MSI Message, this register contains Data. */
/*! @{ */

#define PCIE_MSI_CAP_OFF_08H_REG_PCI_MSI_CAP_OFF_08H_MASK (0xFFFFU)
#define PCIE_MSI_CAP_OFF_08H_REG_PCI_MSI_CAP_OFF_08H_SHIFT (0U)
/*! PCI_MSI_CAP_OFF_08H - For a 32-bit MSI Message, this field contains Data. For 64-bit it contains
 *    lower 16 bits of the Upper Address. For a description of this standard PCIe register field,
 *    see the PCI Express Specification. Note: The access attributes of this field are as follows: -
 *    Dbi: PCI_MSI_64_BIT_ADDR_CAP ? R/W : R
 */
#define PCIE_MSI_CAP_OFF_08H_REG_PCI_MSI_CAP_OFF_08H(x) (((uint32_t)(((uint32_t)(x)) << PCIE_MSI_CAP_OFF_08H_REG_PCI_MSI_CAP_OFF_08H_SHIFT)) & PCIE_MSI_CAP_OFF_08H_REG_PCI_MSI_CAP_OFF_08H_MASK)

#define PCIE_MSI_CAP_OFF_08H_REG_PCI_MSI_CAP_OFF_0AH_MASK (0xFFFF0000U)
#define PCIE_MSI_CAP_OFF_08H_REG_PCI_MSI_CAP_OFF_0AH_SHIFT (16U)
/*! PCI_MSI_CAP_OFF_0AH - For a 32 bit MSI Message, this field contains Ext MSI Data. For 64-bit it
 *    contains upper 16 bits of the Upper Address. For a description of this standard PCIe register
 *    field, see the PCI Express Specification Note: The access attributes of this field are as
 *    follows: - Dbi: PCI_MSI_64_BIT_ADDR_CAP || `DEFAULT_EXT_MSI_DATA_CAPABLE ? R/W : R
 */
#define PCIE_MSI_CAP_OFF_08H_REG_PCI_MSI_CAP_OFF_0AH(x) (((uint32_t)(((uint32_t)(x)) << PCIE_MSI_CAP_OFF_08H_REG_PCI_MSI_CAP_OFF_0AH_SHIFT)) & PCIE_MSI_CAP_OFF_08H_REG_PCI_MSI_CAP_OFF_0AH_MASK)
/*! @} */

/*! @name MSI_CAP_OFF_0CH_REG - For a 64 bit MSI Message, this register contains Data. */
/*! @{ */

#define PCIE_MSI_CAP_OFF_0CH_REG_PCI_MSI_CAP_OFF_0CH_MASK (0xFFFFU)
#define PCIE_MSI_CAP_OFF_0CH_REG_PCI_MSI_CAP_OFF_0CH_SHIFT (0U)
/*! PCI_MSI_CAP_OFF_0CH - For a 64-bit MSI Message, this field contains Data. For 32-bit, it
 *    contains the lower Mask Bits if PVM is enabled. For a description of this standard PCIe register
 *    field, see the PCI Express Specification Note: The access attributes of this field are as follows:
 *    - Dbi: PCI_MSI_64_BIT_ADDR_CAP || MSI_PVM_EN ? R/W : R
 */
#define PCIE_MSI_CAP_OFF_0CH_REG_PCI_MSI_CAP_OFF_0CH(x) (((uint32_t)(((uint32_t)(x)) << PCIE_MSI_CAP_OFF_0CH_REG_PCI_MSI_CAP_OFF_0CH_SHIFT)) & PCIE_MSI_CAP_OFF_0CH_REG_PCI_MSI_CAP_OFF_0CH_MASK)

#define PCIE_MSI_CAP_OFF_0CH_REG_PCI_MSI_CAP_OFF_0EH_MASK (0xFFFF0000U)
#define PCIE_MSI_CAP_OFF_0CH_REG_PCI_MSI_CAP_OFF_0EH_SHIFT (16U)
/*! PCI_MSI_CAP_OFF_0EH - For a 64-bit MSI Message, this field contains Data. For 32-bit, it
 *    contains the upper Mask Bits if PVM is enabled. For a description of this standard PCIe register
 *    field, see the PCI Express Specification Note: The access attributes of this field are as follows:
 *    - Dbi: (!MSI_64_EN && MSI_PVM_EN_VALUE) ? RW: MSI_64_EN && DEFAULT_EXT_MSI_DATA_CAPABLE ? RW
 *    : RO
 */
#define PCIE_MSI_CAP_OFF_0CH_REG_PCI_MSI_CAP_OFF_0EH(x) (((uint32_t)(((uint32_t)(x)) << PCIE_MSI_CAP_OFF_0CH_REG_PCI_MSI_CAP_OFF_0EH_SHIFT)) & PCIE_MSI_CAP_OFF_0CH_REG_PCI_MSI_CAP_OFF_0EH_MASK)
/*! @} */

/*! @name MSI_CAP_OFF_10H_REG - Used for MSI when Vector Masking Capable. */
/*! @{ */

#define PCIE_MSI_CAP_OFF_10H_REG_PCI_MSI_CAP_OFF_10H_MASK (0xFFFFFFFFU)
#define PCIE_MSI_CAP_OFF_10H_REG_PCI_MSI_CAP_OFF_10H_SHIFT (0U)
/*! PCI_MSI_CAP_OFF_10H - Used for MSI when Vector Masking Capable. For 32-bit contains Pending
 *    Bits. For 64-bit, contains Mask Bits. For a description of this standard PCIe register field, see
 *    the PCI Express Specification. Note: The access attributes of this field are as follows: -
 *    Dbi: PCI_MSI_64_BIT_ADDR_CAP && MSI_PVM_EN ? R/W : R
 */
#define PCIE_MSI_CAP_OFF_10H_REG_PCI_MSI_CAP_OFF_10H(x) (((uint32_t)(((uint32_t)(x)) << PCIE_MSI_CAP_OFF_10H_REG_PCI_MSI_CAP_OFF_10H_SHIFT)) & PCIE_MSI_CAP_OFF_10H_REG_PCI_MSI_CAP_OFF_10H_MASK)
/*! @} */

/*! @name MSI_CAP_OFF_14H_REG - Used for MSI 64 bit messaging when Vector Masking Capable. */
/*! @{ */

#define PCIE_MSI_CAP_OFF_14H_REG_PCI_MSI_CAP_OFF_14H_MASK (0xFFFFFFFFU)
#define PCIE_MSI_CAP_OFF_14H_REG_PCI_MSI_CAP_OFF_14H_SHIFT (0U)
/*! PCI_MSI_CAP_OFF_14H - Used for MSI 64-bit messaging when Vector Masking Capable. Contains
 *    Pending Bits. For a description of this standard PCIe register field, see the PCI Express
 *    Specification.
 */
#define PCIE_MSI_CAP_OFF_14H_REG_PCI_MSI_CAP_OFF_14H(x) (((uint32_t)(((uint32_t)(x)) << PCIE_MSI_CAP_OFF_14H_REG_PCI_MSI_CAP_OFF_14H_SHIFT)) & PCIE_MSI_CAP_OFF_14H_REG_PCI_MSI_CAP_OFF_14H_MASK)
/*! @} */

/*! @name PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG - PCI Express Capabilities, ID, Next Pointer Register. */
/*! @{ */

#define PCIE_PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_PCIE_CAP_ID_MASK (0xFFU)
#define PCIE_PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_PCIE_CAP_ID_SHIFT (0U)
/*! PCIE_CAP_ID - PCIE Capability ID. For a description of this standard PCIe register field, see the PCI Express Specification. */
#define PCIE_PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_PCIE_CAP_ID(x) (((uint32_t)(((uint32_t)(x)) << PCIE_PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_PCIE_CAP_ID_SHIFT)) & PCIE_PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_PCIE_CAP_ID_MASK)

#define PCIE_PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_PCIE_CAP_NEXT_PTR_MASK (0xFF00U)
#define PCIE_PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_PCIE_CAP_NEXT_PTR_SHIFT (8U)
/*! PCIE_CAP_NEXT_PTR - PCIE Next Capability Pointer. For a description of this standard PCIe
 *    register field, see the PCI Express Specification. Note: The access attributes of this field are as
 *    follows: - Dbi: if (DBI_RO_WR_EN == 1) then R/W else R Note: This register field is sticky.
 */
#define PCIE_PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_PCIE_CAP_NEXT_PTR(x) (((uint32_t)(((uint32_t)(x)) << PCIE_PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_PCIE_CAP_NEXT_PTR_SHIFT)) & PCIE_PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_PCIE_CAP_NEXT_PTR_MASK)

#define PCIE_PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_PCIE_CAP_REG_MASK (0xF0000U)
#define PCIE_PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_PCIE_CAP_REG_SHIFT (16U)
/*! PCIE_CAP_REG - PCIE Capability Version Number. For a description of this standard PCIe register
 *    field, see the PCI Express Specification. Note: This register field is sticky.
 */
#define PCIE_PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_PCIE_CAP_REG(x) (((uint32_t)(((uint32_t)(x)) << PCIE_PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_PCIE_CAP_REG_SHIFT)) & PCIE_PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_PCIE_CAP_REG_MASK)

#define PCIE_PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_PCIE_DEV_PORT_TYPE_MASK (0xF00000U)
#define PCIE_PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_PCIE_DEV_PORT_TYPE_SHIFT (20U)
/*! PCIE_DEV_PORT_TYPE - PCIE Device/PortType. For a description of this standard PCIe register field, see the PCI Express Specification. */
#define PCIE_PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_PCIE_DEV_PORT_TYPE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_PCIE_DEV_PORT_TYPE_SHIFT)) & PCIE_PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_PCIE_DEV_PORT_TYPE_MASK)

#define PCIE_PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_PCIE_SLOT_IMP_MASK (0x1000000U)
#define PCIE_PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_PCIE_SLOT_IMP_SHIFT (24U)
/*! PCIE_SLOT_IMP - PCIe Slot Implemented Valid. For a description of this standard PCIe register
 *    field, see the PCI Express Specification. Note: The access attributes of this field are as
 *    follows: - Dbi: if (DBI_RO_WR_EN == 1) then R/W else R
 */
#define PCIE_PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_PCIE_SLOT_IMP(x) (((uint32_t)(((uint32_t)(x)) << PCIE_PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_PCIE_SLOT_IMP_SHIFT)) & PCIE_PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_PCIE_SLOT_IMP_MASK)

#define PCIE_PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_PCIE_INT_MSG_NUM_MASK (0x3E000000U)
#define PCIE_PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_PCIE_INT_MSG_NUM_SHIFT (25U)
/*! PCIE_INT_MSG_NUM - PCIE Interrupt Message Number. For a description of this standard PCIe
 *    register field, see the PCI Express Specification. Note: The access attributes of this field are as
 *    follows: - Dbi: if (DBI_RO_WR_EN == 1) then R/W else R Note: This register field is sticky.
 */
#define PCIE_PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_PCIE_INT_MSG_NUM(x) (((uint32_t)(((uint32_t)(x)) << PCIE_PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_PCIE_INT_MSG_NUM_SHIFT)) & PCIE_PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_PCIE_INT_MSG_NUM_MASK)

#define PCIE_PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_RSVD_MASK (0x40000000U)
#define PCIE_PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_RSVD_SHIFT (30U)
/*! RSVD - Reserved. For a description of this standard PCIe register field, see the PCI Express Specification. */
#define PCIE_PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_RSVD(x) (((uint32_t)(((uint32_t)(x)) << PCIE_PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_RSVD_SHIFT)) & PCIE_PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_RSVD_MASK)

#define PCIE_PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_RSVDP_31_MASK (0x80000000U)
#define PCIE_PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_RSVDP_31_SHIFT (31U)
/*! RSVDP_31 - Reserved for future use. */
#define PCIE_PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_RSVDP_31(x) (((uint32_t)(((uint32_t)(x)) << PCIE_PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_RSVDP_31_SHIFT)) & PCIE_PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG_RSVDP_31_MASK)
/*! @} */

/*! @name DEVICE_CAPABILITIES_REG - Device Capabilities Register. */
/*! @{ */

#define PCIE_DEVICE_CAPABILITIES_REG_PCIE_CAP_MAX_PAYLOAD_SIZE_MASK (0x7U)
#define PCIE_DEVICE_CAPABILITIES_REG_PCIE_CAP_MAX_PAYLOAD_SIZE_SHIFT (0U)
/*! PCIE_CAP_MAX_PAYLOAD_SIZE - Max Payload Size Supported. For a description of this standard PCIe
 *    register field, see the PCI Express Specification. Note: The access attributes of this field
 *    are as follows: - Dbi: if (DBI_RO_WR_EN == 1) then R/W else R Note: This register field is
 *    sticky.
 */
#define PCIE_DEVICE_CAPABILITIES_REG_PCIE_CAP_MAX_PAYLOAD_SIZE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DEVICE_CAPABILITIES_REG_PCIE_CAP_MAX_PAYLOAD_SIZE_SHIFT)) & PCIE_DEVICE_CAPABILITIES_REG_PCIE_CAP_MAX_PAYLOAD_SIZE_MASK)

#define PCIE_DEVICE_CAPABILITIES_REG_PCIE_CAP_PHANTOM_FUNC_SUPPORT_MASK (0x18U)
#define PCIE_DEVICE_CAPABILITIES_REG_PCIE_CAP_PHANTOM_FUNC_SUPPORT_SHIFT (3U)
/*! PCIE_CAP_PHANTOM_FUNC_SUPPORT - Phantom Functions Supported. For a description of this standard
 *    PCIe register field, see the PCI Express Specification. Note: The access attributes of this
 *    field are as follows: - Dbi: if (DBI_RO_WR_EN == 1) then R/W else R Note: This register field is
 *    sticky.
 */
#define PCIE_DEVICE_CAPABILITIES_REG_PCIE_CAP_PHANTOM_FUNC_SUPPORT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DEVICE_CAPABILITIES_REG_PCIE_CAP_PHANTOM_FUNC_SUPPORT_SHIFT)) & PCIE_DEVICE_CAPABILITIES_REG_PCIE_CAP_PHANTOM_FUNC_SUPPORT_MASK)

#define PCIE_DEVICE_CAPABILITIES_REG_PCIE_CAP_EXT_TAG_SUPP_MASK (0x20U)
#define PCIE_DEVICE_CAPABILITIES_REG_PCIE_CAP_EXT_TAG_SUPP_SHIFT (5U)
/*! PCIE_CAP_EXT_TAG_SUPP - Extended Tag Field Supported. For a description of this standard PCIe
 *    register field, see the PCI Express Specification. Note: The access attributes of this field are
 *    as follows: - Dbi: if (DBI_RO_WR_EN == 1) then R/W else R Note: This register field is sticky.
 */
#define PCIE_DEVICE_CAPABILITIES_REG_PCIE_CAP_EXT_TAG_SUPP(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DEVICE_CAPABILITIES_REG_PCIE_CAP_EXT_TAG_SUPP_SHIFT)) & PCIE_DEVICE_CAPABILITIES_REG_PCIE_CAP_EXT_TAG_SUPP_MASK)

#define PCIE_DEVICE_CAPABILITIES_REG_RSVDP_6_MASK (0x7FC0U)
#define PCIE_DEVICE_CAPABILITIES_REG_RSVDP_6_SHIFT (6U)
/*! RSVDP_6 - Reserved for future use. */
#define PCIE_DEVICE_CAPABILITIES_REG_RSVDP_6(x)  (((uint32_t)(((uint32_t)(x)) << PCIE_DEVICE_CAPABILITIES_REG_RSVDP_6_SHIFT)) & PCIE_DEVICE_CAPABILITIES_REG_RSVDP_6_MASK)

#define PCIE_DEVICE_CAPABILITIES_REG_PCIE_CAP_ROLE_BASED_ERR_REPORT_MASK (0x8000U)
#define PCIE_DEVICE_CAPABILITIES_REG_PCIE_CAP_ROLE_BASED_ERR_REPORT_SHIFT (15U)
/*! PCIE_CAP_ROLE_BASED_ERR_REPORT - Role-based Error Reporting Implemented. For a description of
 *    this standard PCIe register field, see the PCI Express Specification. Note: The access
 *    attributes of this field are as follows: - Dbi: if (DBI_RO_WR_EN == 1) then R/W else R Note: This
 *    register field is sticky.
 */
#define PCIE_DEVICE_CAPABILITIES_REG_PCIE_CAP_ROLE_BASED_ERR_REPORT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DEVICE_CAPABILITIES_REG_PCIE_CAP_ROLE_BASED_ERR_REPORT_SHIFT)) & PCIE_DEVICE_CAPABILITIES_REG_PCIE_CAP_ROLE_BASED_ERR_REPORT_MASK)

#define PCIE_DEVICE_CAPABILITIES_REG_RSVDP_16_MASK (0xFFFF0000U)
#define PCIE_DEVICE_CAPABILITIES_REG_RSVDP_16_SHIFT (16U)
/*! RSVDP_16 - Reserved for future use. */
#define PCIE_DEVICE_CAPABILITIES_REG_RSVDP_16(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DEVICE_CAPABILITIES_REG_RSVDP_16_SHIFT)) & PCIE_DEVICE_CAPABILITIES_REG_RSVDP_16_MASK)
/*! @} */

/*! @name DEVICE_CONTROL_DEVICE_STATUS - Device Control and Status Register. */
/*! @{ */

#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_CORR_ERR_REPORT_EN_MASK (0x1U)
#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_CORR_ERR_REPORT_EN_SHIFT (0U)
/*! PCIE_CAP_CORR_ERR_REPORT_EN - Correctable Error Reporting Enable. For a description of this
 *    standard PCIe register field, see the PCI Express Specification.
 */
#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_CORR_ERR_REPORT_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_CORR_ERR_REPORT_EN_SHIFT)) & PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_CORR_ERR_REPORT_EN_MASK)

#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_NON_FATAL_ERR_REPORT_EN_MASK (0x2U)
#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_NON_FATAL_ERR_REPORT_EN_SHIFT (1U)
/*! PCIE_CAP_NON_FATAL_ERR_REPORT_EN - Non-fatal Error Reporting Enable. For a description of this
 *    standard PCIe register field, see the PCI Express Specification.
 */
#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_NON_FATAL_ERR_REPORT_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_NON_FATAL_ERR_REPORT_EN_SHIFT)) & PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_NON_FATAL_ERR_REPORT_EN_MASK)

#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_FATAL_ERR_REPORT_EN_MASK (0x4U)
#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_FATAL_ERR_REPORT_EN_SHIFT (2U)
/*! PCIE_CAP_FATAL_ERR_REPORT_EN - Fatal Error Reporting Enable. For a description of this standard PCIe register field, see the PCI Express Specification. */
#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_FATAL_ERR_REPORT_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_FATAL_ERR_REPORT_EN_SHIFT)) & PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_FATAL_ERR_REPORT_EN_MASK)

#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_UNSUPPORT_REQ_REP_EN_MASK (0x8U)
#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_UNSUPPORT_REQ_REP_EN_SHIFT (3U)
/*! PCIE_CAP_UNSUPPORT_REQ_REP_EN - Unsupported Request Reporting Enable. For a description of this
 *    standard PCIe register field, see the PCI Express Specification.
 */
#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_UNSUPPORT_REQ_REP_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_UNSUPPORT_REQ_REP_EN_SHIFT)) & PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_UNSUPPORT_REQ_REP_EN_MASK)

#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_EN_REL_ORDER_MASK (0x10U)
#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_EN_REL_ORDER_SHIFT (4U)
/*! PCIE_CAP_EN_REL_ORDER - Enable Relaxed Ordering. For a description of this standard PCIe
 *    register field, see the PCI Express Specification. Note: The access attributes of this field are as
 *    follows: - Dbi: R/W
 */
#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_EN_REL_ORDER(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_EN_REL_ORDER_SHIFT)) & PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_EN_REL_ORDER_MASK)

#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_MAX_PAYLOAD_SIZE_CS_MASK (0xE0U)
#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_MAX_PAYLOAD_SIZE_CS_SHIFT (5U)
/*! PCIE_CAP_MAX_PAYLOAD_SIZE_CS - Max Payload Size. Max_Payload_Size . This field sets maximum TLP
 *    payload size for the Function. Permissible values that can be programmed are indicated by the
 *    Max_Payload_Size Supported field (PCIE_CAP_MAX_PAYLOAD_SIZE) in the Device Capabilities
 *    register (DEVICE_CAPABILITIES_REG).
 */
#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_MAX_PAYLOAD_SIZE_CS(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_MAX_PAYLOAD_SIZE_CS_SHIFT)) & PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_MAX_PAYLOAD_SIZE_CS_MASK)

#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_EXT_TAG_EN_MASK (0x100U)
#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_EXT_TAG_EN_SHIFT (8U)
/*! PCIE_CAP_EXT_TAG_EN - Extended Tag Field Enable. For a description of this standard PCIe
 *    register field, see the PCI Express Specification. The write value is gated with the
 *    PCIE_CAP_EXT_TAG_SUPP field of DEVICE_CAPABILITIES_REG. Note: The access attributes of this field are as
 *    follows: - Dbi: DEVICE_CAPABILITIES_REG.PCIE_CAP_EXT_TAG_SUPP ? RW : RO
 */
#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_EXT_TAG_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_EXT_TAG_EN_SHIFT)) & PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_EXT_TAG_EN_MASK)

#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_PHANTOM_FUNC_EN_MASK (0x200U)
#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_PHANTOM_FUNC_EN_SHIFT (9U)
/*! PCIE_CAP_PHANTOM_FUNC_EN - Phantom Functions Enable. For a description of this standard PCIe
 *    register field, see the PCI Express Specification. The write value is gated with the
 *    PCIE_CAP_PHANTOM_FUNC_SUPPORT field of DEVICE_CAPABILITIES_REG. Note: The access attributes of this field
 *    are as follows: - Dbi: DEVICE_CAPABILITIES_REG.PCIE_CAP_PHANTOM_FUNC_SUPPORT ? RW : RO
 */
#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_PHANTOM_FUNC_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_PHANTOM_FUNC_EN_SHIFT)) & PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_PHANTOM_FUNC_EN_MASK)

#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_AUX_POWER_PM_EN_MASK (0x400U)
#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_AUX_POWER_PM_EN_SHIFT (10U)
/*! PCIE_CAP_AUX_POWER_PM_EN - Aux Power PM Enable. For a description of this standard PCIe register
 *    field, see the PCI Express Specification. This bit is derived by sampling the sys_aux_pwr_det
 *    input. Note: This register field is sticky.
 */
#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_AUX_POWER_PM_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_AUX_POWER_PM_EN_SHIFT)) & PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_AUX_POWER_PM_EN_MASK)

#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_EN_NO_SNOOP_MASK (0x800U)
#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_EN_NO_SNOOP_SHIFT (11U)
/*! PCIE_CAP_EN_NO_SNOOP - Enable No Snoop. For a description of this standard PCIe register field,
 *    see the PCI Express Specification. Note: The access attributes of this field are as follows: -
 *    Dbi: R
 */
#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_EN_NO_SNOOP(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_EN_NO_SNOOP_SHIFT)) & PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_EN_NO_SNOOP_MASK)

#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_MAX_READ_REQ_SIZE_MASK (0x7000U)
#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_MAX_READ_REQ_SIZE_SHIFT (12U)
/*! PCIE_CAP_MAX_READ_REQ_SIZE - Max Read Request Size. For a description of this standard PCIe register field, see the PCI Express Specification. */
#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_MAX_READ_REQ_SIZE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_MAX_READ_REQ_SIZE_SHIFT)) & PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_MAX_READ_REQ_SIZE_MASK)

#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_INITIATE_FLR_MASK (0x8000U)
#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_INITIATE_FLR_SHIFT (15U)
/*! PCIE_CAP_INITIATE_FLR - Initiate Function Level Reset (for endpoints). For a description of this
 *    standard PCIe register field, see the PCI Express Specification.
 */
#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_INITIATE_FLR(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_INITIATE_FLR_SHIFT)) & PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_INITIATE_FLR_MASK)

#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_CORR_ERR_DETECTED_MASK (0x10000U)
#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_CORR_ERR_DETECTED_SHIFT (16U)
/*! PCIE_CAP_CORR_ERR_DETECTED - Correctable Error Detected Status. For a description of this
 *    standard PCIe register field, see the PCI Express Specification.
 */
#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_CORR_ERR_DETECTED(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_CORR_ERR_DETECTED_SHIFT)) & PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_CORR_ERR_DETECTED_MASK)

#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_NON_FATAL_ERR_DETECTED_MASK (0x20000U)
#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_NON_FATAL_ERR_DETECTED_SHIFT (17U)
/*! PCIE_CAP_NON_FATAL_ERR_DETECTED - Non-Fatal Error Detected Status. For a description of this
 *    standard PCIe register field, see the PCI Express Specification.
 */
#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_NON_FATAL_ERR_DETECTED(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_NON_FATAL_ERR_DETECTED_SHIFT)) & PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_NON_FATAL_ERR_DETECTED_MASK)

#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_FATAL_ERR_DETECTED_MASK (0x40000U)
#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_FATAL_ERR_DETECTED_SHIFT (18U)
/*! PCIE_CAP_FATAL_ERR_DETECTED - Fatal Error Detected Status. For a description of this standard PCIe register field, see the PCI Express Specification. */
#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_FATAL_ERR_DETECTED(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_FATAL_ERR_DETECTED_SHIFT)) & PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_FATAL_ERR_DETECTED_MASK)

#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_UNSUPPORTED_REQ_DETECTED_MASK (0x80000U)
#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_UNSUPPORTED_REQ_DETECTED_SHIFT (19U)
/*! PCIE_CAP_UNSUPPORTED_REQ_DETECTED - Unsupported Request Detected Status. For a description of
 *    this standard PCIe register field, see the PCI Express Specification.
 */
#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_UNSUPPORTED_REQ_DETECTED(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_UNSUPPORTED_REQ_DETECTED_SHIFT)) & PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_UNSUPPORTED_REQ_DETECTED_MASK)

#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_AUX_POWER_DETECTED_MASK (0x100000U)
#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_AUX_POWER_DETECTED_SHIFT (20U)
/*! PCIE_CAP_AUX_POWER_DETECTED - Aux Power Detected Status. For a description of this standard PCIe
 *    register field, see the PCI Express Specification. This bit is derived by sampling the
 *    sys_aux_pwr_det input.
 */
#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_AUX_POWER_DETECTED(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_AUX_POWER_DETECTED_SHIFT)) & PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_AUX_POWER_DETECTED_MASK)

#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_TRANS_PENDING_MASK (0x200000U)
#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_TRANS_PENDING_SHIFT (21U)
/*! PCIE_CAP_TRANS_PENDING - Transactions Pending Status. For a description of this standard PCIe register field, see the PCI Express Specification. */
#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_TRANS_PENDING(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_TRANS_PENDING_SHIFT)) & PCIE_DEVICE_CONTROL_DEVICE_STATUS_PCIE_CAP_TRANS_PENDING_MASK)

#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_RSVDP_22_MASK (0xFFC00000U)
#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_RSVDP_22_SHIFT (22U)
/*! RSVDP_22 - Reserved for future use. */
#define PCIE_DEVICE_CONTROL_DEVICE_STATUS_RSVDP_22(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DEVICE_CONTROL_DEVICE_STATUS_RSVDP_22_SHIFT)) & PCIE_DEVICE_CONTROL_DEVICE_STATUS_RSVDP_22_MASK)
/*! @} */

/*! @name LINK_CAPABILITIES_REG - Link Capabilities Register. */
/*! @{ */

#define PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_MAX_LINK_SPEED_MASK (0xFU)
#define PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_MAX_LINK_SPEED_SHIFT (0U)
/*! PCIE_CAP_MAX_LINK_SPEED - Maximum Link Speed. For a description of this standard PCIe register
 *    field, see the PCI Express Specification. In M-PCIe mode, the reset and dynamic values of this
 *    field are calculated by the controller. Note: The access attributes of this field are as
 *    follows: - Dbi: if (DBI_RO_WR_EN == 1) then R/W else R Note: This register field is sticky.
 */
#define PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_MAX_LINK_SPEED(x) (((uint32_t)(((uint32_t)(x)) << PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_MAX_LINK_SPEED_SHIFT)) & PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_MAX_LINK_SPEED_MASK)

#define PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_MAX_LINK_WIDTH_MASK (0x3F0U)
#define PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_MAX_LINK_WIDTH_SHIFT (4U)
/*! PCIE_CAP_MAX_LINK_WIDTH - Maximum Link Width. For a description of this standard PCIe register
 *    field, see the PCI Express Specification. In M-PCIe mode, the reset and dynamic values of this
 *    field are calculated by the controller. Note: The access attributes of this field are as
 *    follows: - Dbi: if (DBI_RO_WR_EN == 1) then R/W else R Note: This register field is sticky.
 */
#define PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_MAX_LINK_WIDTH(x) (((uint32_t)(((uint32_t)(x)) << PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_MAX_LINK_WIDTH_SHIFT)) & PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_MAX_LINK_WIDTH_MASK)

#define PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_ACTIVE_STATE_LINK_PM_SUPPORT_MASK (0xC00U)
#define PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_ACTIVE_STATE_LINK_PM_SUPPORT_SHIFT (10U)
/*! PCIE_CAP_ACTIVE_STATE_LINK_PM_SUPPORT - Level of ASPM (Active State Power Management) Support.
 *    For a description of this standard PCIe register field, see the PCI Express Specification.
 *    Note: The access attributes of this field are as follows: - Dbi: if (DBI_RO_WR_EN == 1) then R/W
 *    else R Note: This register field is sticky.
 */
#define PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_ACTIVE_STATE_LINK_PM_SUPPORT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_ACTIVE_STATE_LINK_PM_SUPPORT_SHIFT)) & PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_ACTIVE_STATE_LINK_PM_SUPPORT_MASK)

#define PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_L0S_EXIT_LATENCY_MASK (0x7000U)
#define PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_L0S_EXIT_LATENCY_SHIFT (12U)
/*! PCIE_CAP_L0S_EXIT_LATENCY - LOs Exit Latency. For a description of this standard PCIe register
 *    field, see the PCI Express Specification. There are two each of these register fields, this one
 *    and a shadow one at the same address. The Common Clock bit (PCIE_CAP_COMMON_CLK_CONFIG) of
 *    the Link Control Register (LINK_CONTROL_LINK_STATUS_REG) determines which one is used by the
 *    controller and which one is accessed by a read request. Common Clock operation is supported
 *    (possible) in the controller when one or more of the following expressions is true: - CX_NFTS
 *    !=CX_COMM_NFTS - DEFAULT_L0S_EXIT_LATENCY !=DEFAULT_COMM_L0S_EXIT_LATENCY - DEFAULT_L1_EXIT_LATENCY
 *    !=DEFAULT_COMM_L1_EXIT_LATENCY Common Clock operation is enabled in the controller when you
 *    set the Common Clock bit (PCIE_CAP_COMMON_CLK_CONFIG) of the Link Control Register
 *    (LINK_CONTROL_LINK_STATUS_REG). The assertion of CS2 (that is, assert the dbi_cs2 input, or the CS2
 *    address bit for the AXI bridge) is required to write to the shadow field at this location. Note: The
 *    access attributes of this field are as follows: - Dbi: if (DBI_RO_WR_EN == 1) then R/W else R
 *    Note: This register field is sticky.
 */
#define PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_L0S_EXIT_LATENCY(x) (((uint32_t)(((uint32_t)(x)) << PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_L0S_EXIT_LATENCY_SHIFT)) & PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_L0S_EXIT_LATENCY_MASK)

#define PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_L1_EXIT_LATENCY_MASK (0x38000U)
#define PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_L1_EXIT_LATENCY_SHIFT (15U)
/*! PCIE_CAP_L1_EXIT_LATENCY - L1 Exit Latency. For a description of this standard PCIe register
 *    field, see the PCI Express Specification. There are two each of these register fields, this one
 *    and a shadow one at the same address. The Common Clock bit (PCIE_CAP_COMMON_CLK_CONFIG) of the
 *    Link Control Register (LINK_CONTROL_LINK_STATUS_REG) determines which one is used by the
 *    controller and which one is accessed by a read request. Common Clock operation is supported
 *    (possible) in the controller when one or more of the following expressions is true: - CX_NFTS
 *    !=CX_COMM_NFTS - DEFAULT_L0S_EXIT_LATENCY !=DEFAULT_COMM_L0S_EXIT_LATENCY - DEFAULT_L1_EXIT_LATENCY
 *    !=DEFAULT_COMM_L1_EXIT_LATENCY Common Clock operation is enabled in the controller when you set
 *    the Common Clock bit (PCIE_CAP_COMMON_CLK_CONFIG) of the Link Control Register
 *    (LINK_CONTROL_LINK_STATUS_REG). The assertion of CS2 (that is, assert the dbi_cs2 input, or the CS2 address
 *    bit for the AXI bridge) is required to write to the shadow field at this location. Note: The
 *    access attributes of this field are as follows: - Dbi: if (DBI_RO_WR_EN == 1) then R/W else R
 *    Note: This register field is sticky.
 */
#define PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_L1_EXIT_LATENCY(x) (((uint32_t)(((uint32_t)(x)) << PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_L1_EXIT_LATENCY_SHIFT)) & PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_L1_EXIT_LATENCY_MASK)

#define PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_CLOCK_POWER_MAN_MASK (0x40000U)
#define PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_CLOCK_POWER_MAN_SHIFT (18U)
/*! PCIE_CAP_CLOCK_POWER_MAN - Clock Power Management. For a description of this standard PCIe
 *    register field, see the PCI Express Specification. Note: This register field is sticky.
 */
#define PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_CLOCK_POWER_MAN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_CLOCK_POWER_MAN_SHIFT)) & PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_CLOCK_POWER_MAN_MASK)

#define PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_SURPRISE_DOWN_ERR_REP_CAP_MASK (0x80000U)
#define PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_SURPRISE_DOWN_ERR_REP_CAP_SHIFT (19U)
/*! PCIE_CAP_SURPRISE_DOWN_ERR_REP_CAP - Surprise Down Error Reporting Capable. For a description of
 *    this standard PCIe register field, see the PCI Express Specification. Note: The access
 *    attributes of this field are as follows: - Dbi: if (DBI_RO_WR_EN == 1) then R/W else R Note: This
 *    register field is sticky.
 */
#define PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_SURPRISE_DOWN_ERR_REP_CAP(x) (((uint32_t)(((uint32_t)(x)) << PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_SURPRISE_DOWN_ERR_REP_CAP_SHIFT)) & PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_SURPRISE_DOWN_ERR_REP_CAP_MASK)

#define PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_DLL_ACTIVE_REP_CAP_MASK (0x100000U)
#define PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_DLL_ACTIVE_REP_CAP_SHIFT (20U)
/*! PCIE_CAP_DLL_ACTIVE_REP_CAP - Data Link Layer Link Active Reporting Capable. For a description
 *    of this standard PCIe register field, see the PCI Express Specification.
 */
#define PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_DLL_ACTIVE_REP_CAP(x) (((uint32_t)(((uint32_t)(x)) << PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_DLL_ACTIVE_REP_CAP_SHIFT)) & PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_DLL_ACTIVE_REP_CAP_MASK)

#define PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_LINK_BW_NOT_CAP_MASK (0x200000U)
#define PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_LINK_BW_NOT_CAP_SHIFT (21U)
/*! PCIE_CAP_LINK_BW_NOT_CAP - Link Bandwidth Notification Capable. For a description of this
 *    standard PCIe register field, see the PCI Express Specification. Note: The access attributes of this
 *    field are as follows: - Dbi: if (DBI_RO_WR_EN == 1) then R/W else R Note: This register field
 *    is sticky.
 */
#define PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_LINK_BW_NOT_CAP(x) (((uint32_t)(((uint32_t)(x)) << PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_LINK_BW_NOT_CAP_SHIFT)) & PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_LINK_BW_NOT_CAP_MASK)

#define PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_ASPM_OPT_COMPLIANCE_MASK (0x400000U)
#define PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_ASPM_OPT_COMPLIANCE_SHIFT (22U)
/*! PCIE_CAP_ASPM_OPT_COMPLIANCE - ASPM Optionality Compliance. For a description of this standard
 *    PCIe register field, see the PCI Express Specification. Note: The access attributes of this
 *    field are as follows: - Dbi: if (DBI_RO_WR_EN == 1) then R/W else R
 */
#define PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_ASPM_OPT_COMPLIANCE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_ASPM_OPT_COMPLIANCE_SHIFT)) & PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_ASPM_OPT_COMPLIANCE_MASK)

#define PCIE_LINK_CAPABILITIES_REG_RSVDP_23_MASK (0x800000U)
#define PCIE_LINK_CAPABILITIES_REG_RSVDP_23_SHIFT (23U)
/*! RSVDP_23 - Reserved for future use. */
#define PCIE_LINK_CAPABILITIES_REG_RSVDP_23(x)   (((uint32_t)(((uint32_t)(x)) << PCIE_LINK_CAPABILITIES_REG_RSVDP_23_SHIFT)) & PCIE_LINK_CAPABILITIES_REG_RSVDP_23_MASK)

#define PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_PORT_NUM_MASK (0xFF000000U)
#define PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_PORT_NUM_SHIFT (24U)
/*! PCIE_CAP_PORT_NUM - Port Number. For a description of this standard PCIe register field, see the
 *    PCI Express Specification. Note: The access attributes of this field are as follows: - Dbi:
 *    if (DBI_RO_WR_EN == 1) then R/W else R
 */
#define PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_PORT_NUM(x) (((uint32_t)(((uint32_t)(x)) << PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_PORT_NUM_SHIFT)) & PCIE_LINK_CAPABILITIES_REG_PCIE_CAP_PORT_NUM_MASK)
/*! @} */

/*! @name LINK_CONTROL_LINK_STATUS_REG - Link Control and Status Register. */
/*! @{ */

#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_ACTIVE_STATE_LINK_PM_CONTROL_MASK (0x3U)
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_ACTIVE_STATE_LINK_PM_CONTROL_SHIFT (0U)
/*! PCIE_CAP_ACTIVE_STATE_LINK_PM_CONTROL - Active State Power Management (ASPM) Control. Software
 *    must not enable L0s in either direction on a given Link unless components on both sides of the
 *    Link each support L0s; otherwise, the result is undefined. For a description of this standard
 *    PCIe register field, see the PCI Express Specification.
 */
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_ACTIVE_STATE_LINK_PM_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_ACTIVE_STATE_LINK_PM_CONTROL_SHIFT)) & PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_ACTIVE_STATE_LINK_PM_CONTROL_MASK)

#define PCIE_LINK_CONTROL_LINK_STATUS_REG_RSVDP_2_MASK (0x4U)
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_RSVDP_2_SHIFT (2U)
/*! RSVDP_2 - Reserved for future use. */
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_RSVDP_2(x) (((uint32_t)(((uint32_t)(x)) << PCIE_LINK_CONTROL_LINK_STATUS_REG_RSVDP_2_SHIFT)) & PCIE_LINK_CONTROL_LINK_STATUS_REG_RSVDP_2_MASK)

#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_RCB_MASK (0x8U)
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_RCB_SHIFT (3U)
/*! PCIE_CAP_RCB - Read Completion Boundary (RCB). Note: The access attributes of this field are as
 *    follows: - Dbi: if (DBI_RO_WR_EN == 1) then R/W else R
 */
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_RCB(x) (((uint32_t)(((uint32_t)(x)) << PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_RCB_SHIFT)) & PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_RCB_MASK)

#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_LINK_DISABLE_MASK (0x10U)
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_LINK_DISABLE_SHIFT (4U)
/*! PCIE_CAP_LINK_DISABLE - Initiate Link Disable. For a description of this standard PCIe register
 *    field, see the PCI Express Specification. In a DSP that supports crosslink, the controller
 *    gates the write value with the CROSS_LINK_EN field in PORT_LINK_CTRL_OFF. Note: The access
 *    attributes of this field are as follows: - Dbi: CX_CROSSLINK_ENABLE=1 &&
 *    PORT_LINK_CTRL_OFF.CROSS_LINK_EN=1||CX_CROSSLINK_ENABLE=0 && dsp=1? RW : RO
 */
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_LINK_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_LINK_DISABLE_SHIFT)) & PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_LINK_DISABLE_MASK)

#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_RETRAIN_LINK_MASK (0x20U)
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_RETRAIN_LINK_SHIFT (5U)
/*! PCIE_CAP_RETRAIN_LINK - Initiate Link Retrain. For a description of this standard PCIe register
 *    field, see the PCI Express Specification. Note: The access attributes of this field are as
 *    follows: - Dbi: see description
 */
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_RETRAIN_LINK(x) (((uint32_t)(((uint32_t)(x)) << PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_RETRAIN_LINK_SHIFT)) & PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_RETRAIN_LINK_MASK)

#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_COMMON_CLK_CONFIG_MASK (0x40U)
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_COMMON_CLK_CONFIG_SHIFT (6U)
/*! PCIE_CAP_COMMON_CLK_CONFIG - Common Clock Configuration. For a description of this standard PCIe register field, see the PCI Express Specification. */
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_COMMON_CLK_CONFIG(x) (((uint32_t)(((uint32_t)(x)) << PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_COMMON_CLK_CONFIG_SHIFT)) & PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_COMMON_CLK_CONFIG_MASK)

#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_EXTENDED_SYNCH_MASK (0x80U)
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_EXTENDED_SYNCH_SHIFT (7U)
/*! PCIE_CAP_EXTENDED_SYNCH - Extended Synch. For a description of this standard PCIe register field, see the PCI Express Specification. */
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_EXTENDED_SYNCH(x) (((uint32_t)(((uint32_t)(x)) << PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_EXTENDED_SYNCH_SHIFT)) & PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_EXTENDED_SYNCH_MASK)

#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_EN_CLK_POWER_MAN_MASK (0x100U)
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_EN_CLK_POWER_MAN_SHIFT (8U)
/*! PCIE_CAP_EN_CLK_POWER_MAN - Enable Clock Power Management. For a description of this standard
 *    PCIe register field, see the PCI Express Specification. The write value is gated with the
 *    PCIE_CAP_CLOCK_POWER_MAN field in LINK_CAPABILITIES_REG. Note: The access attributes of this field
 *    are as follows: - Dbi: LINK_CAPABILITIES_REG.PCIE_CAP_CLOCK_POWER_MAN ? RWS : ROS Note: This
 *    register field is sticky.
 */
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_EN_CLK_POWER_MAN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_EN_CLK_POWER_MAN_SHIFT)) & PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_EN_CLK_POWER_MAN_MASK)

#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_HW_AUTO_WIDTH_DISABLE_MASK (0x200U)
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_HW_AUTO_WIDTH_DISABLE_SHIFT (9U)
/*! PCIE_CAP_HW_AUTO_WIDTH_DISABLE - Hardware Autonomous Width Disable. For a description of this
 *    standard PCIe register field, see the PCI Express Specification. Note: The access attributes of
 *    this field are as follows: - Dbi: R/W
 */
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_HW_AUTO_WIDTH_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_HW_AUTO_WIDTH_DISABLE_SHIFT)) & PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_HW_AUTO_WIDTH_DISABLE_MASK)

#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_LINK_BW_MAN_INT_EN_MASK (0x400U)
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_LINK_BW_MAN_INT_EN_SHIFT (10U)
/*! PCIE_CAP_LINK_BW_MAN_INT_EN - Link Bandwidth Management Interrupt Enable. For a description of
 *    this standard PCIe register field, see the PCI Express Specification. The write value is gated
 *    with the PCIE_CAP_LINK_BW_NOT_CAP field in LINK_CAPABILITIES_REG. Note: The access attributes
 *    of this field are as follows: - Dbi: LINK_CAPABILITIES_REG.PCIE_CAP_LINK_BW_NOT_CAP ? RW : RO
 */
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_LINK_BW_MAN_INT_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_LINK_BW_MAN_INT_EN_SHIFT)) & PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_LINK_BW_MAN_INT_EN_MASK)

#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_LINK_AUTO_BW_INT_EN_MASK (0x800U)
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_LINK_AUTO_BW_INT_EN_SHIFT (11U)
/*! PCIE_CAP_LINK_AUTO_BW_INT_EN - Link Autonomous Bandwidth Management Interrupt Enable. For a
 *    description of this standard PCIe register field, see the PCI Express Specification. The write
 *    value is gated with the PCIE_CAP_LINK_BW_NOT_CAP field in LINK_CAPABILITIES_REG. Note: The access
 *    attributes of this field are as follows: - Dbi:
 *    LINK_CAPABILITIES_REG.PCIE_CAP_LINK_BW_NOT_CAP ? RW : RO
 */
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_LINK_AUTO_BW_INT_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_LINK_AUTO_BW_INT_EN_SHIFT)) & PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_LINK_AUTO_BW_INT_EN_MASK)

#define PCIE_LINK_CONTROL_LINK_STATUS_REG_RSVDP_12_MASK (0x3000U)
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_RSVDP_12_SHIFT (12U)
/*! RSVDP_12 - Reserved for future use. */
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_RSVDP_12(x) (((uint32_t)(((uint32_t)(x)) << PCIE_LINK_CONTROL_LINK_STATUS_REG_RSVDP_12_SHIFT)) & PCIE_LINK_CONTROL_LINK_STATUS_REG_RSVDP_12_MASK)

#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_DRS_SIGNALING_CONTROL_MASK (0xC000U)
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_DRS_SIGNALING_CONTROL_SHIFT (14U)
/*! PCIE_CAP_DRS_SIGNALING_CONTROL - DRS Signaling Control. For a description of this standard PCIe
 *    register field, see the PCI Express Specification. Note: The access attributes of this field
 *    are as follows: - Dbi: LINK_CAPABILITIES2_REG.DRS_SUPPORTED ? RW : RO
 */
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_DRS_SIGNALING_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_DRS_SIGNALING_CONTROL_SHIFT)) & PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_DRS_SIGNALING_CONTROL_MASK)

#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_LINK_SPEED_MASK (0xF0000U)
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_LINK_SPEED_SHIFT (16U)
/*! PCIE_CAP_LINK_SPEED - Current Link Speed. For a description of this standard PCIe register field, see the PCI Express Specification. */
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_LINK_SPEED(x) (((uint32_t)(((uint32_t)(x)) << PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_LINK_SPEED_SHIFT)) & PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_LINK_SPEED_MASK)

#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_NEGO_LINK_WIDTH_MASK (0x3F00000U)
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_NEGO_LINK_WIDTH_SHIFT (20U)
/*! PCIE_CAP_NEGO_LINK_WIDTH - Negotiated Link Width. For a description of this standard PCIe register field, see the PCI Express Specification. */
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_NEGO_LINK_WIDTH(x) (((uint32_t)(((uint32_t)(x)) << PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_NEGO_LINK_WIDTH_SHIFT)) & PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_NEGO_LINK_WIDTH_MASK)

#define PCIE_LINK_CONTROL_LINK_STATUS_REG_RSVDP_26_MASK (0x4000000U)
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_RSVDP_26_SHIFT (26U)
/*! RSVDP_26 - Reserved for future use. */
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_RSVDP_26(x) (((uint32_t)(((uint32_t)(x)) << PCIE_LINK_CONTROL_LINK_STATUS_REG_RSVDP_26_SHIFT)) & PCIE_LINK_CONTROL_LINK_STATUS_REG_RSVDP_26_MASK)

#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_LINK_TRAINING_MASK (0x8000000U)
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_LINK_TRAINING_SHIFT (27U)
/*! PCIE_CAP_LINK_TRAINING - LTSSM is in Configuration or Recovery State. For a description of this
 *    standard PCIe register field, see the PCI Express Specification.
 */
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_LINK_TRAINING(x) (((uint32_t)(((uint32_t)(x)) << PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_LINK_TRAINING_SHIFT)) & PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_LINK_TRAINING_MASK)

#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_SLOT_CLK_CONFIG_MASK (0x10000000U)
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_SLOT_CLK_CONFIG_SHIFT (28U)
/*! PCIE_CAP_SLOT_CLK_CONFIG - Slot Clock Configuration. For a description of this standard PCIe
 *    register field, see the PCI Express Specification. Note: The access attributes of this field are
 *    as follows: - Dbi: if (DBI_RO_WR_EN == 1) then R/W else R
 */
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_SLOT_CLK_CONFIG(x) (((uint32_t)(((uint32_t)(x)) << PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_SLOT_CLK_CONFIG_SHIFT)) & PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_SLOT_CLK_CONFIG_MASK)

#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_DLL_ACTIVE_MASK (0x20000000U)
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_DLL_ACTIVE_SHIFT (29U)
/*! PCIE_CAP_DLL_ACTIVE - Data Link Layer Active. For a description of this standard PCIe register field, see the PCI Express Specification. */
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_DLL_ACTIVE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_DLL_ACTIVE_SHIFT)) & PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_DLL_ACTIVE_MASK)

#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_LINK_BW_MAN_STATUS_MASK (0x40000000U)
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_LINK_BW_MAN_STATUS_SHIFT (30U)
/*! PCIE_CAP_LINK_BW_MAN_STATUS - Link Bandwidth Management Status. For a description of this
 *    standard PCIe register field, see the PCI Express Specification. The write value is gated with the
 *    PCIE_CAP_LINK_BW_NOT_CAP field in LINK_CAPABILITIES_REG.
 */
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_LINK_BW_MAN_STATUS(x) (((uint32_t)(((uint32_t)(x)) << PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_LINK_BW_MAN_STATUS_SHIFT)) & PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_LINK_BW_MAN_STATUS_MASK)

#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_LINK_AUTO_BW_STATUS_MASK (0x80000000U)
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_LINK_AUTO_BW_STATUS_SHIFT (31U)
/*! PCIE_CAP_LINK_AUTO_BW_STATUS - Link Autonomous Bandwidth Status. For a description of this
 *    standard PCIe register field, see the PCI Express Specification. The write value is gated with the
 *    PCIE_CAP_LINK_BW_NOT_CAP field in LINK_CAPABILITIES_REG.
 */
#define PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_LINK_AUTO_BW_STATUS(x) (((uint32_t)(((uint32_t)(x)) << PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_LINK_AUTO_BW_STATUS_SHIFT)) & PCIE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_LINK_AUTO_BW_STATUS_MASK)
/*! @} */

/*! @name SLOT_CAPABILITIES_REG - Slot Capabilities Register. */
/*! @{ */

#define PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_ATTENTION_INDICATOR_BUTTON_MASK (0x1U)
#define PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_ATTENTION_INDICATOR_BUTTON_SHIFT (0U)
/*! PCIE_CAP_ATTENTION_INDICATOR_BUTTON - Attention Button Present. For a description of this
 *    standard PCIe register field, see the PCI Express Specification. Note: The access attributes of this
 *    field are as follows: - Dbi: if (DBI_RO_WR_EN == 1) then R/W else R
 */
#define PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_ATTENTION_INDICATOR_BUTTON(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_ATTENTION_INDICATOR_BUTTON_SHIFT)) & PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_ATTENTION_INDICATOR_BUTTON_MASK)

#define PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_POWER_CONTROLLER_MASK (0x2U)
#define PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_POWER_CONTROLLER_SHIFT (1U)
/*! PCIE_CAP_POWER_CONTROLLER - Power Controller Present. For a description of this standard PCIe
 *    register field, see the PCI Express Specification. Note: The access attributes of this field are
 *    as follows: - Dbi: if (DBI_RO_WR_EN == 1) then R/W else R
 */
#define PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_POWER_CONTROLLER(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_POWER_CONTROLLER_SHIFT)) & PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_POWER_CONTROLLER_MASK)

#define PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_MRL_SENSOR_MASK (0x4U)
#define PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_MRL_SENSOR_SHIFT (2U)
/*! PCIE_CAP_MRL_SENSOR - MRL Present. For a description of this standard PCIe register field, see
 *    the PCI Express Specification. Note: The access attributes of this field are as follows: - Dbi:
 *    if (DBI_RO_WR_EN == 1) then R/W else R
 */
#define PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_MRL_SENSOR(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_MRL_SENSOR_SHIFT)) & PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_MRL_SENSOR_MASK)

#define PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_ATTENTION_INDICATOR_MASK (0x8U)
#define PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_ATTENTION_INDICATOR_SHIFT (3U)
/*! PCIE_CAP_ATTENTION_INDICATOR - Attention Indicator Present. For a description of this standard
 *    PCIe register field, see the PCI Express Specification. Note: The access attributes of this
 *    field are as follows: - Dbi: if (DBI_RO_WR_EN == 1) then R/W else R
 */
#define PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_ATTENTION_INDICATOR(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_ATTENTION_INDICATOR_SHIFT)) & PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_ATTENTION_INDICATOR_MASK)

#define PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_POWER_INDICATOR_MASK (0x10U)
#define PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_POWER_INDICATOR_SHIFT (4U)
/*! PCIE_CAP_POWER_INDICATOR - Power Indicator Present. For a description of this standard PCIe
 *    register field, see the PCI Express Specification. Note: The access attributes of this field are
 *    as follows: - Dbi: if (DBI_RO_WR_EN == 1) then R/W else R
 */
#define PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_POWER_INDICATOR(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_POWER_INDICATOR_SHIFT)) & PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_POWER_INDICATOR_MASK)

#define PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_HOT_PLUG_SURPRISE_MASK (0x20U)
#define PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_HOT_PLUG_SURPRISE_SHIFT (5U)
/*! PCIE_CAP_HOT_PLUG_SURPRISE - Hot Plug Surprise possible. For a description of this standard PCIe
 *    register field, see the PCI Express Specification. Note: The access attributes of this field
 *    are as follows: - Dbi: if (DBI_RO_WR_EN == 1) then R/W else R
 */
#define PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_HOT_PLUG_SURPRISE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_HOT_PLUG_SURPRISE_SHIFT)) & PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_HOT_PLUG_SURPRISE_MASK)

#define PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_HOT_PLUG_CAPABLE_MASK (0x40U)
#define PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_HOT_PLUG_CAPABLE_SHIFT (6U)
/*! PCIE_CAP_HOT_PLUG_CAPABLE - Hot Plug Capable. For a description of this standard PCIe register
 *    field, see the PCI Express Specification. Note: The access attributes of this field are as
 *    follows: - Dbi: if (DBI_RO_WR_EN == 1) then R/W else R
 */
#define PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_HOT_PLUG_CAPABLE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_HOT_PLUG_CAPABLE_SHIFT)) & PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_HOT_PLUG_CAPABLE_MASK)

#define PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_SLOT_POWER_LIMIT_VALUE_MASK (0x7F80U)
#define PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_SLOT_POWER_LIMIT_VALUE_SHIFT (7U)
/*! PCIE_CAP_SLOT_POWER_LIMIT_VALUE - Slot Power Limit Value. For a description of this standard
 *    PCIe register field, see the PCI Express Specification. Note: The access attributes of this field
 *    are as follows: - Dbi: if (DBI_RO_WR_EN == 1) then R/W else R
 */
#define PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_SLOT_POWER_LIMIT_VALUE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_SLOT_POWER_LIMIT_VALUE_SHIFT)) & PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_SLOT_POWER_LIMIT_VALUE_MASK)

#define PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_SLOT_POWER_LIMIT_SCALE_MASK (0x18000U)
#define PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_SLOT_POWER_LIMIT_SCALE_SHIFT (15U)
/*! PCIE_CAP_SLOT_POWER_LIMIT_SCALE - Slot Power Limit Scale. For a description of this standard
 *    PCIe register field, see the PCI Express Specification. Note: The access attributes of this field
 *    are as follows: - Dbi: if (DBI_RO_WR_EN == 1) then R/W else R
 */
#define PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_SLOT_POWER_LIMIT_SCALE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_SLOT_POWER_LIMIT_SCALE_SHIFT)) & PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_SLOT_POWER_LIMIT_SCALE_MASK)

#define PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_ELECTROMECH_INTERLOCK_MASK (0x20000U)
#define PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_ELECTROMECH_INTERLOCK_SHIFT (17U)
/*! PCIE_CAP_ELECTROMECH_INTERLOCK - Electromechanical Interlock Present. For a description of this
 *    standard PCIe register field, see the PCI Express Specification. Note: The access attributes
 *    of this field are as follows: - Dbi: if (DBI_RO_WR_EN == 1) then R/W else R
 */
#define PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_ELECTROMECH_INTERLOCK(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_ELECTROMECH_INTERLOCK_SHIFT)) & PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_ELECTROMECH_INTERLOCK_MASK)

#define PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_NO_CMD_CPL_SUPPORT_MASK (0x40000U)
#define PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_NO_CMD_CPL_SUPPORT_SHIFT (18U)
/*! PCIE_CAP_NO_CMD_CPL_SUPPORT - No Command Completed Support. For a description of this standard
 *    PCIe register field, see the PCI Express Specification. Note: The access attributes of this
 *    field are as follows: - Dbi: if (DBI_RO_WR_EN == 1) then R/W else R
 */
#define PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_NO_CMD_CPL_SUPPORT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_NO_CMD_CPL_SUPPORT_SHIFT)) & PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_NO_CMD_CPL_SUPPORT_MASK)

#define PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_PHY_SLOT_NUM_MASK (0xFFF80000U)
#define PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_PHY_SLOT_NUM_SHIFT (19U)
/*! PCIE_CAP_PHY_SLOT_NUM - Physical Slot Number. For a description of this standard PCIe register
 *    field, see the PCI Express Specification. Note: The access attributes of this field are as
 *    follows: - Dbi: if (DBI_RO_WR_EN == 1) then R/W else R
 */
#define PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_PHY_SLOT_NUM(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_PHY_SLOT_NUM_SHIFT)) & PCIE_SLOT_CAPABILITIES_REG_PCIE_CAP_PHY_SLOT_NUM_MASK)
/*! @} */

/*! @name SLOT_CONTROL_SLOT_STATUS - Slot Control and Status Register. */
/*! @{ */

#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_ATTENTION_BUTTON_PRESSED_EN_MASK (0x1U)
#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_ATTENTION_BUTTON_PRESSED_EN_SHIFT (0U)
/*! PCIE_CAP_ATTENTION_BUTTON_PRESSED_EN - Attention Button Pressed Enable. For a description of
 *    this standard PCIe register field, see the PCI Express Specification.
 */
#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_ATTENTION_BUTTON_PRESSED_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_ATTENTION_BUTTON_PRESSED_EN_SHIFT)) & PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_ATTENTION_BUTTON_PRESSED_EN_MASK)

#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_POWER_FAULT_DETECTED_EN_MASK (0x2U)
#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_POWER_FAULT_DETECTED_EN_SHIFT (1U)
/*! PCIE_CAP_POWER_FAULT_DETECTED_EN - Power Fault Detected Enable. For a description of this standard PCIe register field, see the PCI Express Specification. */
#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_POWER_FAULT_DETECTED_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_POWER_FAULT_DETECTED_EN_SHIFT)) & PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_POWER_FAULT_DETECTED_EN_MASK)

#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_MRL_SENSOR_CHANGED_EN_MASK (0x4U)
#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_MRL_SENSOR_CHANGED_EN_SHIFT (2U)
/*! PCIE_CAP_MRL_SENSOR_CHANGED_EN - MRL Sensor Changed Enable. For a description of this standard PCIe register field, see the PCI Express Specification. */
#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_MRL_SENSOR_CHANGED_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_MRL_SENSOR_CHANGED_EN_SHIFT)) & PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_MRL_SENSOR_CHANGED_EN_MASK)

#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_PRESENCE_DETECT_CHANGE_EN_MASK (0x8U)
#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_PRESENCE_DETECT_CHANGE_EN_SHIFT (3U)
/*! PCIE_CAP_PRESENCE_DETECT_CHANGE_EN - Presence Detect Changed Enable. For a description of this
 *    standard PCIe register field, see the PCI Express Specification.
 */
#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_PRESENCE_DETECT_CHANGE_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_PRESENCE_DETECT_CHANGE_EN_SHIFT)) & PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_PRESENCE_DETECT_CHANGE_EN_MASK)

#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_CMD_CPL_INT_EN_MASK (0x10U)
#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_CMD_CPL_INT_EN_SHIFT (4U)
/*! PCIE_CAP_CMD_CPL_INT_EN - Command Completed Interrupt Enable. For a description of this standard
 *    PCIe register field, see the PCI Express Specification. Write value is gated with
 *    PCIE_CAP_NO_CMD_CPL_SUPPORT field in SLOT_CAPABILITIES_REG. Note: The access attributes of this field are
 *    as follows: - Dbi: SLOT_CAPABILITIES_REG.PCIE_CAP_NO_CMD_CPL_SUPPORT ? RO : RW
 */
#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_CMD_CPL_INT_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_CMD_CPL_INT_EN_SHIFT)) & PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_CMD_CPL_INT_EN_MASK)

#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_HOT_PLUG_INT_EN_MASK (0x20U)
#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_HOT_PLUG_INT_EN_SHIFT (5U)
/*! PCIE_CAP_HOT_PLUG_INT_EN - Hot Plug Interrupt Enable. For a description of this standard PCIe register field, see the PCI Express Specification. */
#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_HOT_PLUG_INT_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_HOT_PLUG_INT_EN_SHIFT)) & PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_HOT_PLUG_INT_EN_MASK)

#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_ATTENTION_INDICATOR_CTRL_MASK (0xC0U)
#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_ATTENTION_INDICATOR_CTRL_SHIFT (6U)
/*! PCIE_CAP_ATTENTION_INDICATOR_CTRL - Attention Indicator Control. For a description of this standard PCIe register field, see the PCI Express Specification. */
#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_ATTENTION_INDICATOR_CTRL(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_ATTENTION_INDICATOR_CTRL_SHIFT)) & PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_ATTENTION_INDICATOR_CTRL_MASK)

#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_POWER_INDICATOR_CTRL_MASK (0x300U)
#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_POWER_INDICATOR_CTRL_SHIFT (8U)
/*! PCIE_CAP_POWER_INDICATOR_CTRL - Power Indicator Control. For a description of this standard PCIe register field, see the PCI Express Specification. */
#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_POWER_INDICATOR_CTRL(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_POWER_INDICATOR_CTRL_SHIFT)) & PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_POWER_INDICATOR_CTRL_MASK)

#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_POWER_CONTROLLER_CTRL_MASK (0x400U)
#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_POWER_CONTROLLER_CTRL_SHIFT (10U)
/*! PCIE_CAP_POWER_CONTROLLER_CTRL - Power Controller Control. For a description of this standard PCIe register field, see the PCI Express Specification. */
#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_POWER_CONTROLLER_CTRL(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_POWER_CONTROLLER_CTRL_SHIFT)) & PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_POWER_CONTROLLER_CTRL_MASK)

#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_ELECTROMECH_INTERLOCK_CTRL_MASK (0x800U)
#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_ELECTROMECH_INTERLOCK_CTRL_SHIFT (11U)
/*! PCIE_CAP_ELECTROMECH_INTERLOCK_CTRL - Electromechanical Interlock Control. For a description of
 *    this standard PCIe register field, see the PCI Express Specification.
 */
#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_ELECTROMECH_INTERLOCK_CTRL(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_ELECTROMECH_INTERLOCK_CTRL_SHIFT)) & PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_ELECTROMECH_INTERLOCK_CTRL_MASK)

#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_DLL_STATE_CHANGED_EN_MASK (0x1000U)
#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_DLL_STATE_CHANGED_EN_SHIFT (12U)
/*! PCIE_CAP_DLL_STATE_CHANGED_EN - Data Link Layer State Changed Enable. For a description of this
 *    standard PCIe register field, see the PCI Express Specification.
 */
#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_DLL_STATE_CHANGED_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_DLL_STATE_CHANGED_EN_SHIFT)) & PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_DLL_STATE_CHANGED_EN_MASK)

#define PCIE_SLOT_CONTROL_SLOT_STATUS_RSVDP_13_MASK (0xE000U)
#define PCIE_SLOT_CONTROL_SLOT_STATUS_RSVDP_13_SHIFT (13U)
/*! RSVDP_13 - Reserved for future use. */
#define PCIE_SLOT_CONTROL_SLOT_STATUS_RSVDP_13(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SLOT_CONTROL_SLOT_STATUS_RSVDP_13_SHIFT)) & PCIE_SLOT_CONTROL_SLOT_STATUS_RSVDP_13_MASK)

#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_ATTENTION_BUTTON_PRESSED_MASK (0x10000U)
#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_ATTENTION_BUTTON_PRESSED_SHIFT (16U)
/*! PCIE_CAP_ATTENTION_BUTTON_PRESSED - Attention Button Pressed. For a description of this standard PCIe register field, see the PCI Express Specification. */
#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_ATTENTION_BUTTON_PRESSED(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_ATTENTION_BUTTON_PRESSED_SHIFT)) & PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_ATTENTION_BUTTON_PRESSED_MASK)

#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_POWER_FAULT_DETECTED_MASK (0x20000U)
#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_POWER_FAULT_DETECTED_SHIFT (17U)
/*! PCIE_CAP_POWER_FAULT_DETECTED - Power Fault Detected. For a description of this standard PCIe register field, see the PCI Express Specification. */
#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_POWER_FAULT_DETECTED(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_POWER_FAULT_DETECTED_SHIFT)) & PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_POWER_FAULT_DETECTED_MASK)

#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_MRL_SENSOR_CHANGED_MASK (0x40000U)
#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_MRL_SENSOR_CHANGED_SHIFT (18U)
/*! PCIE_CAP_MRL_SENSOR_CHANGED - MRL Sensor Changed. For a description of this standard PCIe register field, see the PCI Express Specification. */
#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_MRL_SENSOR_CHANGED(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_MRL_SENSOR_CHANGED_SHIFT)) & PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_MRL_SENSOR_CHANGED_MASK)

#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_PRESENCE_DETECTED_CHANGED_MASK (0x80000U)
#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_PRESENCE_DETECTED_CHANGED_SHIFT (19U)
/*! PCIE_CAP_PRESENCE_DETECTED_CHANGED - Presence Detect Changed. For a description of this standard PCIe register field, see the PCI Express Specification. */
#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_PRESENCE_DETECTED_CHANGED(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_PRESENCE_DETECTED_CHANGED_SHIFT)) & PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_PRESENCE_DETECTED_CHANGED_MASK)

#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_CMD_CPLD_MASK (0x100000U)
#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_CMD_CPLD_SHIFT (20U)
/*! PCIE_CAP_CMD_CPLD - Command Completed. For a description of this standard PCIe register field, see the PCI Express Specification. */
#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_CMD_CPLD(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_CMD_CPLD_SHIFT)) & PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_CMD_CPLD_MASK)

#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_MRL_SENSOR_STATE_MASK (0x200000U)
#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_MRL_SENSOR_STATE_SHIFT (21U)
/*! PCIE_CAP_MRL_SENSOR_STATE - MRL Sensor State. For a description of this standard PCIe register field, see the PCI Express Specification. */
#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_MRL_SENSOR_STATE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_MRL_SENSOR_STATE_SHIFT)) & PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_MRL_SENSOR_STATE_MASK)

#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_PRESENCE_DETECT_STATE_MASK (0x400000U)
#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_PRESENCE_DETECT_STATE_SHIFT (22U)
/*! PCIE_CAP_PRESENCE_DETECT_STATE - Presence Detect State. For a description of this standard PCIe
 *    register field, see the PCI Express Specification. Note: The access attributes of this field
 *    are as follows: - Dbi: R
 */
#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_PRESENCE_DETECT_STATE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_PRESENCE_DETECT_STATE_SHIFT)) & PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_PRESENCE_DETECT_STATE_MASK)

#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_ELECTROMECH_INTERLOCK_STATUS_MASK (0x800000U)
#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_ELECTROMECH_INTERLOCK_STATUS_SHIFT (23U)
/*! PCIE_CAP_ELECTROMECH_INTERLOCK_STATUS - Electromechanical Interlock Status. For a description of
 *    this standard PCIe register field, see the PCI Express Specification.
 */
#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_ELECTROMECH_INTERLOCK_STATUS(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_ELECTROMECH_INTERLOCK_STATUS_SHIFT)) & PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_ELECTROMECH_INTERLOCK_STATUS_MASK)

#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_DLL_STATE_CHANGED_MASK (0x1000000U)
#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_DLL_STATE_CHANGED_SHIFT (24U)
/*! PCIE_CAP_DLL_STATE_CHANGED - Data Link Layer State Changed. For a description of this standard
 *    PCIe register field, see the PCI Express Specification.
 */
#define PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_DLL_STATE_CHANGED(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_DLL_STATE_CHANGED_SHIFT)) & PCIE_SLOT_CONTROL_SLOT_STATUS_PCIE_CAP_DLL_STATE_CHANGED_MASK)

#define PCIE_SLOT_CONTROL_SLOT_STATUS_RSVDP_25_MASK (0xFE000000U)
#define PCIE_SLOT_CONTROL_SLOT_STATUS_RSVDP_25_SHIFT (25U)
/*! RSVDP_25 - Reserved for future use. */
#define PCIE_SLOT_CONTROL_SLOT_STATUS_RSVDP_25(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SLOT_CONTROL_SLOT_STATUS_RSVDP_25_SHIFT)) & PCIE_SLOT_CONTROL_SLOT_STATUS_RSVDP_25_MASK)
/*! @} */

/*! @name ROOT_CONTROL_ROOT_CAPABILITIES_REG - Root Control and Capabilities Register. */
/*! @{ */

#define PCIE_ROOT_CONTROL_ROOT_CAPABILITIES_REG_PCIE_CAP_SYS_ERR_ON_CORR_ERR_EN_MASK (0x1U)
#define PCIE_ROOT_CONTROL_ROOT_CAPABILITIES_REG_PCIE_CAP_SYS_ERR_ON_CORR_ERR_EN_SHIFT (0U)
/*! PCIE_CAP_SYS_ERR_ON_CORR_ERR_EN - System Error on Correctable Error Enable. For a description of
 *    this standard PCIe register field, see the PCI Express Specification.
 */
#define PCIE_ROOT_CONTROL_ROOT_CAPABILITIES_REG_PCIE_CAP_SYS_ERR_ON_CORR_ERR_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_ROOT_CONTROL_ROOT_CAPABILITIES_REG_PCIE_CAP_SYS_ERR_ON_CORR_ERR_EN_SHIFT)) & PCIE_ROOT_CONTROL_ROOT_CAPABILITIES_REG_PCIE_CAP_SYS_ERR_ON_CORR_ERR_EN_MASK)

#define PCIE_ROOT_CONTROL_ROOT_CAPABILITIES_REG_PCIE_CAP_SYS_ERR_ON_NON_FATAL_ERR_EN_MASK (0x2U)
#define PCIE_ROOT_CONTROL_ROOT_CAPABILITIES_REG_PCIE_CAP_SYS_ERR_ON_NON_FATAL_ERR_EN_SHIFT (1U)
/*! PCIE_CAP_SYS_ERR_ON_NON_FATAL_ERR_EN - System Error on Non-fatal Error Enable. For a description
 *    of this standard PCIe register field, see the PCI Express Specification.
 */
#define PCIE_ROOT_CONTROL_ROOT_CAPABILITIES_REG_PCIE_CAP_SYS_ERR_ON_NON_FATAL_ERR_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_ROOT_CONTROL_ROOT_CAPABILITIES_REG_PCIE_CAP_SYS_ERR_ON_NON_FATAL_ERR_EN_SHIFT)) & PCIE_ROOT_CONTROL_ROOT_CAPABILITIES_REG_PCIE_CAP_SYS_ERR_ON_NON_FATAL_ERR_EN_MASK)

#define PCIE_ROOT_CONTROL_ROOT_CAPABILITIES_REG_PCIE_CAP_SYS_ERR_ON_FATAL_ERR_EN_MASK (0x4U)
#define PCIE_ROOT_CONTROL_ROOT_CAPABILITIES_REG_PCIE_CAP_SYS_ERR_ON_FATAL_ERR_EN_SHIFT (2U)
/*! PCIE_CAP_SYS_ERR_ON_FATAL_ERR_EN - System Error on Fatal Error Enable. For a description of this
 *    standard PCIe register field, see the PCI Express Specification.
 */
#define PCIE_ROOT_CONTROL_ROOT_CAPABILITIES_REG_PCIE_CAP_SYS_ERR_ON_FATAL_ERR_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_ROOT_CONTROL_ROOT_CAPABILITIES_REG_PCIE_CAP_SYS_ERR_ON_FATAL_ERR_EN_SHIFT)) & PCIE_ROOT_CONTROL_ROOT_CAPABILITIES_REG_PCIE_CAP_SYS_ERR_ON_FATAL_ERR_EN_MASK)

#define PCIE_ROOT_CONTROL_ROOT_CAPABILITIES_REG_PCIE_CAP_PME_INT_EN_MASK (0x8U)
#define PCIE_ROOT_CONTROL_ROOT_CAPABILITIES_REG_PCIE_CAP_PME_INT_EN_SHIFT (3U)
/*! PCIE_CAP_PME_INT_EN - PME Interrupt Enable. For a description of this standard PCIe register field, see the PCI Express Specification. */
#define PCIE_ROOT_CONTROL_ROOT_CAPABILITIES_REG_PCIE_CAP_PME_INT_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_ROOT_CONTROL_ROOT_CAPABILITIES_REG_PCIE_CAP_PME_INT_EN_SHIFT)) & PCIE_ROOT_CONTROL_ROOT_CAPABILITIES_REG_PCIE_CAP_PME_INT_EN_MASK)

#define PCIE_ROOT_CONTROL_ROOT_CAPABILITIES_REG_PCIE_CAP_CRS_SW_VISIBILITY_EN_MASK (0x10U)
#define PCIE_ROOT_CONTROL_ROOT_CAPABILITIES_REG_PCIE_CAP_CRS_SW_VISIBILITY_EN_SHIFT (4U)
/*! PCIE_CAP_CRS_SW_VISIBILITY_EN - Configuration Request Retry Status (CRS) Software Visibility
 *    Enable. For a description of this standard PCIe register field, see the PCI Express
 *    Specification. Note: The access attributes of this field are as follows: - Dbi:
 *    ROOT_CONTROL_ROOT_CAPABILITIES_REG.PCIE_CAP_CRS_SW_VISIBILITY ? RW : RO
 */
#define PCIE_ROOT_CONTROL_ROOT_CAPABILITIES_REG_PCIE_CAP_CRS_SW_VISIBILITY_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_ROOT_CONTROL_ROOT_CAPABILITIES_REG_PCIE_CAP_CRS_SW_VISIBILITY_EN_SHIFT)) & PCIE_ROOT_CONTROL_ROOT_CAPABILITIES_REG_PCIE_CAP_CRS_SW_VISIBILITY_EN_MASK)

#define PCIE_ROOT_CONTROL_ROOT_CAPABILITIES_REG_RSVDP_5_MASK (0xFFE0U)
#define PCIE_ROOT_CONTROL_ROOT_CAPABILITIES_REG_RSVDP_5_SHIFT (5U)
/*! RSVDP_5 - Reserved for future use. */
#define PCIE_ROOT_CONTROL_ROOT_CAPABILITIES_REG_RSVDP_5(x) (((uint32_t)(((uint32_t)(x)) << PCIE_ROOT_CONTROL_ROOT_CAPABILITIES_REG_RSVDP_5_SHIFT)) & PCIE_ROOT_CONTROL_ROOT_CAPABILITIES_REG_RSVDP_5_MASK)

#define PCIE_ROOT_CONTROL_ROOT_CAPABILITIES_REG_PCIE_CAP_CRS_SW_VISIBILITY_MASK (0x10000U)
#define PCIE_ROOT_CONTROL_ROOT_CAPABILITIES_REG_PCIE_CAP_CRS_SW_VISIBILITY_SHIFT (16U)
/*! PCIE_CAP_CRS_SW_VISIBILITY - CRS Software Visibility Capable. For a description of this standard
 *    PCIe register field, see the PCI Express Specification. Note: The access attributes of this
 *    field are as follows: - Dbi: if (DBI_RO_WR_EN == 1) then R/W (Sticky) else R (Sticky) Note:
 *    This register field is sticky.
 */
#define PCIE_ROOT_CONTROL_ROOT_CAPABILITIES_REG_PCIE_CAP_CRS_SW_VISIBILITY(x) (((uint32_t)(((uint32_t)(x)) << PCIE_ROOT_CONTROL_ROOT_CAPABILITIES_REG_PCIE_CAP_CRS_SW_VISIBILITY_SHIFT)) & PCIE_ROOT_CONTROL_ROOT_CAPABILITIES_REG_PCIE_CAP_CRS_SW_VISIBILITY_MASK)

#define PCIE_ROOT_CONTROL_ROOT_CAPABILITIES_REG_RSVDP_17_MASK (0xFFFE0000U)
#define PCIE_ROOT_CONTROL_ROOT_CAPABILITIES_REG_RSVDP_17_SHIFT (17U)
/*! RSVDP_17 - Reserved for future use. */
#define PCIE_ROOT_CONTROL_ROOT_CAPABILITIES_REG_RSVDP_17(x) (((uint32_t)(((uint32_t)(x)) << PCIE_ROOT_CONTROL_ROOT_CAPABILITIES_REG_RSVDP_17_SHIFT)) & PCIE_ROOT_CONTROL_ROOT_CAPABILITIES_REG_RSVDP_17_MASK)
/*! @} */

/*! @name ROOT_STATUS_REG - Root Status Register. */
/*! @{ */

#define PCIE_ROOT_STATUS_REG_PCIE_CAP_PME_REQ_ID_MASK (0xFFFFU)
#define PCIE_ROOT_STATUS_REG_PCIE_CAP_PME_REQ_ID_SHIFT (0U)
/*! PCIE_CAP_PME_REQ_ID - PME Requester ID. For a description of this standard PCIe register field, see the PCI Express Specification. */
#define PCIE_ROOT_STATUS_REG_PCIE_CAP_PME_REQ_ID(x) (((uint32_t)(((uint32_t)(x)) << PCIE_ROOT_STATUS_REG_PCIE_CAP_PME_REQ_ID_SHIFT)) & PCIE_ROOT_STATUS_REG_PCIE_CAP_PME_REQ_ID_MASK)

#define PCIE_ROOT_STATUS_REG_PCIE_CAP_PME_STATUS_MASK (0x10000U)
#define PCIE_ROOT_STATUS_REG_PCIE_CAP_PME_STATUS_SHIFT (16U)
/*! PCIE_CAP_PME_STATUS - PME Status. For a description of this standard PCIe register field, see the PCI Express Specification. */
#define PCIE_ROOT_STATUS_REG_PCIE_CAP_PME_STATUS(x) (((uint32_t)(((uint32_t)(x)) << PCIE_ROOT_STATUS_REG_PCIE_CAP_PME_STATUS_SHIFT)) & PCIE_ROOT_STATUS_REG_PCIE_CAP_PME_STATUS_MASK)

#define PCIE_ROOT_STATUS_REG_PCIE_CAP_PME_PENDING_MASK (0x20000U)
#define PCIE_ROOT_STATUS_REG_PCIE_CAP_PME_PENDING_SHIFT (17U)
/*! PCIE_CAP_PME_PENDING - PME Pending. For a description of this standard PCIe register field, see the PCI Express Specification. */
#define PCIE_ROOT_STATUS_REG_PCIE_CAP_PME_PENDING(x) (((uint32_t)(((uint32_t)(x)) << PCIE_ROOT_STATUS_REG_PCIE_CAP_PME_PENDING_SHIFT)) & PCIE_ROOT_STATUS_REG_PCIE_CAP_PME_PENDING_MASK)

#define PCIE_ROOT_STATUS_REG_RSVDP_18_MASK       (0xFFFC0000U)
#define PCIE_ROOT_STATUS_REG_RSVDP_18_SHIFT      (18U)
/*! RSVDP_18 - Reserved for future use. */
#define PCIE_ROOT_STATUS_REG_RSVDP_18(x)         (((uint32_t)(((uint32_t)(x)) << PCIE_ROOT_STATUS_REG_RSVDP_18_SHIFT)) & PCIE_ROOT_STATUS_REG_RSVDP_18_MASK)
/*! @} */

/*! @name DEVICE_CAPABILITIES2_REG - Device Capabilities 2 Register. */
/*! @{ */

#define PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_CPL_TIMEOUT_RANGE_MASK (0xFU)
#define PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_CPL_TIMEOUT_RANGE_SHIFT (0U)
/*! PCIE_CAP_CPL_TIMEOUT_RANGE - Completion Timeout Ranges Supported. For a description of this
 *    standard PCIe register field, see the PCI Express Specification.
 */
#define PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_CPL_TIMEOUT_RANGE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_CPL_TIMEOUT_RANGE_SHIFT)) & PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_CPL_TIMEOUT_RANGE_MASK)

#define PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_CPL_TIMEOUT_DISABLE_SUPPORT_MASK (0x10U)
#define PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_CPL_TIMEOUT_DISABLE_SUPPORT_SHIFT (4U)
/*! PCIE_CAP_CPL_TIMEOUT_DISABLE_SUPPORT - Completion Timeout Disable Supported. For a description
 *    of this standard PCIe register field, see the PCI Express Specification.
 */
#define PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_CPL_TIMEOUT_DISABLE_SUPPORT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_CPL_TIMEOUT_DISABLE_SUPPORT_SHIFT)) & PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_CPL_TIMEOUT_DISABLE_SUPPORT_MASK)

#define PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_ARI_FORWARD_SUPPORT_MASK (0x20U)
#define PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_ARI_FORWARD_SUPPORT_SHIFT (5U)
/*! PCIE_CAP_ARI_FORWARD_SUPPORT - ARI Forwarding Supported. For a description of this standard PCIe register field, see the PCI Express Specification. */
#define PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_ARI_FORWARD_SUPPORT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_ARI_FORWARD_SUPPORT_SHIFT)) & PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_ARI_FORWARD_SUPPORT_MASK)

#define PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_ATOMIC_ROUTING_SUPP_MASK (0x40U)
#define PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_ATOMIC_ROUTING_SUPP_SHIFT (6U)
/*! PCIE_CAP_ATOMIC_ROUTING_SUPP - Atomic Operation Routing Supported. For a description of this
 *    standard PCIe register field, see the PCI Express Specification.
 */
#define PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_ATOMIC_ROUTING_SUPP(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_ATOMIC_ROUTING_SUPP_SHIFT)) & PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_ATOMIC_ROUTING_SUPP_MASK)

#define PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_32_ATOMIC_CPL_SUPP_MASK (0x80U)
#define PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_32_ATOMIC_CPL_SUPP_SHIFT (7U)
/*! PCIE_CAP_32_ATOMIC_CPL_SUPP - 32 Bit AtomicOp Completer Supported. For a description of this
 *    standard PCIe register field, see the PCI Express Specification.
 */
#define PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_32_ATOMIC_CPL_SUPP(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_32_ATOMIC_CPL_SUPP_SHIFT)) & PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_32_ATOMIC_CPL_SUPP_MASK)

#define PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_64_ATOMIC_CPL_SUPP_MASK (0x100U)
#define PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_64_ATOMIC_CPL_SUPP_SHIFT (8U)
/*! PCIE_CAP_64_ATOMIC_CPL_SUPP - 64 Bit AtomicOp Completer Supported. For a description of this
 *    standard PCIe register field, see the PCI Express Specification.
 */
#define PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_64_ATOMIC_CPL_SUPP(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_64_ATOMIC_CPL_SUPP_SHIFT)) & PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_64_ATOMIC_CPL_SUPP_MASK)

#define PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_128_CAS_CPL_SUPP_MASK (0x200U)
#define PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_128_CAS_CPL_SUPP_SHIFT (9U)
/*! PCIE_CAP_128_CAS_CPL_SUPP - 128 Bit CAS Completer Supported. For a description of this standard
 *    PCIe register field, see the PCI Express Specification.
 */
#define PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_128_CAS_CPL_SUPP(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_128_CAS_CPL_SUPP_SHIFT)) & PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_128_CAS_CPL_SUPP_MASK)

#define PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_NO_RO_EN_PR2PR_PAR_MASK (0x400U)
#define PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_NO_RO_EN_PR2PR_PAR_SHIFT (10U)
/*! PCIE_CAP_NO_RO_EN_PR2PR_PAR - No Relaxed Ordering Enabled PR-PR Passing. For a description of
 *    this standard PCIe register field, see the PCI Express Specification.
 */
#define PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_NO_RO_EN_PR2PR_PAR(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_NO_RO_EN_PR2PR_PAR_SHIFT)) & PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_NO_RO_EN_PR2PR_PAR_MASK)

#define PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_LTR_SUPP_MASK (0x800U)
#define PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_LTR_SUPP_SHIFT (11U)
/*! PCIE_CAP_LTR_SUPP - LTR Mechanism Supported. For a description of this standard PCIe register field, see the PCI Express Specification. */
#define PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_LTR_SUPP(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_LTR_SUPP_SHIFT)) & PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_LTR_SUPP_MASK)

#define PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_TPH_CMPLT_SUPPORT_0_MASK (0x1000U)
#define PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_TPH_CMPLT_SUPPORT_0_SHIFT (12U)
/*! PCIE_CAP_TPH_CMPLT_SUPPORT_0 - TPH Completer Supported Bit 0. For a description of this standard
 *    PCIe register field, see the PCI Express Specification.
 */
#define PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_TPH_CMPLT_SUPPORT_0(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_TPH_CMPLT_SUPPORT_0_SHIFT)) & PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_TPH_CMPLT_SUPPORT_0_MASK)

#define PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_TPH_CMPLT_SUPPORT_1_MASK (0x2000U)
#define PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_TPH_CMPLT_SUPPORT_1_SHIFT (13U)
/*! PCIE_CAP_TPH_CMPLT_SUPPORT_1 - TPH Completer Supported Bit 1. For a description of this standard
 *    PCIe register field, see the PCI Express Specification.
 */
#define PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_TPH_CMPLT_SUPPORT_1(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_TPH_CMPLT_SUPPORT_1_SHIFT)) & PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_TPH_CMPLT_SUPPORT_1_MASK)

#define PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP2_10_BIT_TAG_COMP_SUPPORT_MASK (0x10000U)
#define PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP2_10_BIT_TAG_COMP_SUPPORT_SHIFT (16U)
/*! PCIE_CAP2_10_BIT_TAG_COMP_SUPPORT - 10-Bit Tag Completer Supported. For a description of this
 *    standard PCIe register field, see the PCI Express Base Specification 4.0.
 */
#define PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP2_10_BIT_TAG_COMP_SUPPORT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP2_10_BIT_TAG_COMP_SUPPORT_SHIFT)) & PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP2_10_BIT_TAG_COMP_SUPPORT_MASK)

#define PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP2_10_BIT_TAG_REQ_SUPPORT_MASK (0x20000U)
#define PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP2_10_BIT_TAG_REQ_SUPPORT_SHIFT (17U)
/*! PCIE_CAP2_10_BIT_TAG_REQ_SUPPORT - 10-Bit Tag Requester Supported. For a description of this
 *    standard PCIe register field, see the PCI Express Base Specification 4.0.
 */
#define PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP2_10_BIT_TAG_REQ_SUPPORT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP2_10_BIT_TAG_REQ_SUPPORT_SHIFT)) & PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP2_10_BIT_TAG_REQ_SUPPORT_MASK)

#define PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_OBFF_SUPPORT_MASK (0xC0000U)
#define PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_OBFF_SUPPORT_SHIFT (18U)
/*! PCIE_CAP_OBFF_SUPPORT - (OBFF) Optimized Buffer Flush/fill Supported. For a description of this
 *    standard PCIe register field, see the PCI Express Specification.
 */
#define PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_OBFF_SUPPORT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_OBFF_SUPPORT_SHIFT)) & PCIE_DEVICE_CAPABILITIES2_REG_PCIE_CAP_OBFF_SUPPORT_MASK)

#define PCIE_DEVICE_CAPABILITIES2_REG_RSVDP_24_MASK (0x7F000000U)
#define PCIE_DEVICE_CAPABILITIES2_REG_RSVDP_24_SHIFT (24U)
/*! RSVDP_24 - Reserved for future use. */
#define PCIE_DEVICE_CAPABILITIES2_REG_RSVDP_24(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DEVICE_CAPABILITIES2_REG_RSVDP_24_SHIFT)) & PCIE_DEVICE_CAPABILITIES2_REG_RSVDP_24_MASK)
/*! @} */

/*! @name DEVICE_CONTROL2_DEVICE_STATUS2_REG - Device Control 2 and Status 2 Register. */
/*! @{ */

#define PCIE_DEVICE_CONTROL2_DEVICE_STATUS2_REG_PCIE_CAP_CPL_TIMEOUT_VALUE_MASK (0xFU)
#define PCIE_DEVICE_CONTROL2_DEVICE_STATUS2_REG_PCIE_CAP_CPL_TIMEOUT_VALUE_SHIFT (0U)
/*! PCIE_CAP_CPL_TIMEOUT_VALUE - Completion Timeout Value. For a description of this standard PCIe
 *    register field, see the PCI Express Specification. Note: The access attributes of this field
 *    are as follows: - Dbi: R/W
 */
#define PCIE_DEVICE_CONTROL2_DEVICE_STATUS2_REG_PCIE_CAP_CPL_TIMEOUT_VALUE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DEVICE_CONTROL2_DEVICE_STATUS2_REG_PCIE_CAP_CPL_TIMEOUT_VALUE_SHIFT)) & PCIE_DEVICE_CONTROL2_DEVICE_STATUS2_REG_PCIE_CAP_CPL_TIMEOUT_VALUE_MASK)

#define PCIE_DEVICE_CONTROL2_DEVICE_STATUS2_REG_PCIE_CAP_CPL_TIMEOUT_DISABLE_MASK (0x10U)
#define PCIE_DEVICE_CONTROL2_DEVICE_STATUS2_REG_PCIE_CAP_CPL_TIMEOUT_DISABLE_SHIFT (4U)
/*! PCIE_CAP_CPL_TIMEOUT_DISABLE - Completion Timeout Disable. For a description of this standard PCIe register field, see the PCI Express Specification. */
#define PCIE_DEVICE_CONTROL2_DEVICE_STATUS2_REG_PCIE_CAP_CPL_TIMEOUT_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DEVICE_CONTROL2_DEVICE_STATUS2_REG_PCIE_CAP_CPL_TIMEOUT_DISABLE_SHIFT)) & PCIE_DEVICE_CONTROL2_DEVICE_STATUS2_REG_PCIE_CAP_CPL_TIMEOUT_DISABLE_MASK)

#define PCIE_DEVICE_CONTROL2_DEVICE_STATUS2_REG_PCIE_CAP_ARI_FORWARD_SUPPORT_CS_MASK (0x20U)
#define PCIE_DEVICE_CONTROL2_DEVICE_STATUS2_REG_PCIE_CAP_ARI_FORWARD_SUPPORT_CS_SHIFT (5U)
/*! PCIE_CAP_ARI_FORWARD_SUPPORT_CS - ARI Forwarding Enable. For a description of this standard PCIe
 *    register field, see the PCI Express Specification. Note: The access attributes of this field
 *    are as follows: - Dbi: R/W
 */
#define PCIE_DEVICE_CONTROL2_DEVICE_STATUS2_REG_PCIE_CAP_ARI_FORWARD_SUPPORT_CS(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DEVICE_CONTROL2_DEVICE_STATUS2_REG_PCIE_CAP_ARI_FORWARD_SUPPORT_CS_SHIFT)) & PCIE_DEVICE_CONTROL2_DEVICE_STATUS2_REG_PCIE_CAP_ARI_FORWARD_SUPPORT_CS_MASK)
/*! @} */

/*! @name LINK_CAPABILITIES2_REG - Link Capabilities 2 Register. */
/*! @{ */

#define PCIE_LINK_CAPABILITIES2_REG_RSVDP_0_MASK (0x1U)
#define PCIE_LINK_CAPABILITIES2_REG_RSVDP_0_SHIFT (0U)
/*! RSVDP_0 - Reserved for future use. */
#define PCIE_LINK_CAPABILITIES2_REG_RSVDP_0(x)   (((uint32_t)(((uint32_t)(x)) << PCIE_LINK_CAPABILITIES2_REG_RSVDP_0_SHIFT)) & PCIE_LINK_CAPABILITIES2_REG_RSVDP_0_MASK)

#define PCIE_LINK_CAPABILITIES2_REG_PCIE_CAP_SUPPORT_LINK_SPEED_VECTOR_MASK (0xFEU)
#define PCIE_LINK_CAPABILITIES2_REG_PCIE_CAP_SUPPORT_LINK_SPEED_VECTOR_SHIFT (1U)
/*! PCIE_CAP_SUPPORT_LINK_SPEED_VECTOR - Supported Link Speeds Vector. For a description of this
 *    standard PCIe register field, see the PCI Express Specification. This field has a default of
 *    (PCIE_CAP_MAX_LINK_SPEED == 0100) ? 0001111 : (PCIE_CAP_MAX_LINK_SPEED == 0011) ? 0000111 :
 *    (PCIE_CAP_MAX_LINK_SPEED == 0010) ? 0000011 : 0000001 where PCIE_CAP_MAX_LINK_SPEED is a field in
 *    the LINK_CAPABILITIES_REG register.
 */
#define PCIE_LINK_CAPABILITIES2_REG_PCIE_CAP_SUPPORT_LINK_SPEED_VECTOR(x) (((uint32_t)(((uint32_t)(x)) << PCIE_LINK_CAPABILITIES2_REG_PCIE_CAP_SUPPORT_LINK_SPEED_VECTOR_SHIFT)) & PCIE_LINK_CAPABILITIES2_REG_PCIE_CAP_SUPPORT_LINK_SPEED_VECTOR_MASK)

#define PCIE_LINK_CAPABILITIES2_REG_PCIE_CAP_CROSS_LINK_SUPPORT_MASK (0x100U)
#define PCIE_LINK_CAPABILITIES2_REG_PCIE_CAP_CROSS_LINK_SUPPORT_SHIFT (8U)
/*! PCIE_CAP_CROSS_LINK_SUPPORT - Cross Link Supported. For a description of this standard PCIe register field, see the PCI Express Specification. */
#define PCIE_LINK_CAPABILITIES2_REG_PCIE_CAP_CROSS_LINK_SUPPORT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_LINK_CAPABILITIES2_REG_PCIE_CAP_CROSS_LINK_SUPPORT_SHIFT)) & PCIE_LINK_CAPABILITIES2_REG_PCIE_CAP_CROSS_LINK_SUPPORT_MASK)

#define PCIE_LINK_CAPABILITIES2_REG_RSVDP_9_MASK (0x7FFE00U)
#define PCIE_LINK_CAPABILITIES2_REG_RSVDP_9_SHIFT (9U)
/*! RSVDP_9 - Reserved for future use. */
#define PCIE_LINK_CAPABILITIES2_REG_RSVDP_9(x)   (((uint32_t)(((uint32_t)(x)) << PCIE_LINK_CAPABILITIES2_REG_RSVDP_9_SHIFT)) & PCIE_LINK_CAPABILITIES2_REG_RSVDP_9_MASK)

#define PCIE_LINK_CAPABILITIES2_REG_RSVDP_25_MASK (0x7E000000U)
#define PCIE_LINK_CAPABILITIES2_REG_RSVDP_25_SHIFT (25U)
/*! RSVDP_25 - Reserved for future use. */
#define PCIE_LINK_CAPABILITIES2_REG_RSVDP_25(x)  (((uint32_t)(((uint32_t)(x)) << PCIE_LINK_CAPABILITIES2_REG_RSVDP_25_SHIFT)) & PCIE_LINK_CAPABILITIES2_REG_RSVDP_25_MASK)
/*! @} */

/*! @name LINK_CONTROL2_LINK_STATUS2_REG - Link Control 2 and Status 2 Register. */
/*! @{ */

#define PCIE_LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_TARGET_LINK_SPEED_MASK (0xFU)
#define PCIE_LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_TARGET_LINK_SPEED_SHIFT (0U)
/*! PCIE_CAP_TARGET_LINK_SPEED - Target Link Speed. For a description of this standard PCIe register
 *    field, see the PCI Express Specification. In M-PCIe mode, the contents of this field are
 *    derived from other registers. Note: This register field is sticky.
 */
#define PCIE_LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_TARGET_LINK_SPEED(x) (((uint32_t)(((uint32_t)(x)) << PCIE_LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_TARGET_LINK_SPEED_SHIFT)) & PCIE_LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_TARGET_LINK_SPEED_MASK)

#define PCIE_LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_ENTER_COMPLIANCE_MASK (0x10U)
#define PCIE_LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_ENTER_COMPLIANCE_SHIFT (4U)
/*! PCIE_CAP_ENTER_COMPLIANCE - Enter Compliance Mode. For a description of this standard PCIe
 *    register field, see the PCI Express Specification. Note: This register field is sticky.
 */
#define PCIE_LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_ENTER_COMPLIANCE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_ENTER_COMPLIANCE_SHIFT)) & PCIE_LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_ENTER_COMPLIANCE_MASK)

#define PCIE_LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_HW_AUTO_SPEED_DISABLE_MASK (0x20U)
#define PCIE_LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_HW_AUTO_SPEED_DISABLE_SHIFT (5U)
/*! PCIE_CAP_HW_AUTO_SPEED_DISABLE - Hardware Autonomous Speed Disable. For a description of this
 *    standard PCIe register field, see the PCI Express Specification. Note: The access attributes of
 *    this field are as follows: - Dbi: R/W (sticky) Note: This register field is sticky.
 */
#define PCIE_LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_HW_AUTO_SPEED_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_HW_AUTO_SPEED_DISABLE_SHIFT)) & PCIE_LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_HW_AUTO_SPEED_DISABLE_MASK)

#define PCIE_LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_SEL_DEEMPHASIS_MASK (0x40U)
#define PCIE_LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_SEL_DEEMPHASIS_SHIFT (6U)
/*! PCIE_CAP_SEL_DEEMPHASIS - Controls Selectable De-emphasis for 5 GT/s. For a description of this
 *    standard PCIe register field, see the PCI Express Specification. Note: The access attributes
 *    of this field are as follows: - Dbi: if (DBI_RO_WR_EN == 1) then R/W(sticky) else R(sticky)
 *    Note: This register field is sticky.
 */
#define PCIE_LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_SEL_DEEMPHASIS(x) (((uint32_t)(((uint32_t)(x)) << PCIE_LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_SEL_DEEMPHASIS_SHIFT)) & PCIE_LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_SEL_DEEMPHASIS_MASK)

#define PCIE_LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_TX_MARGIN_MASK (0x380U)
#define PCIE_LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_TX_MARGIN_SHIFT (7U)
/*! PCIE_CAP_TX_MARGIN - Controls Transmit Margin for Debug or Compliance. For a description of this
 *    standard PCIe register field, see the PCI Express Specification. Note: This register field is
 *    sticky.
 */
#define PCIE_LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_TX_MARGIN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_TX_MARGIN_SHIFT)) & PCIE_LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_TX_MARGIN_MASK)

#define PCIE_LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_ENTER_MODIFIED_COMPLIANCE_MASK (0x400U)
#define PCIE_LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_ENTER_MODIFIED_COMPLIANCE_SHIFT (10U)
/*! PCIE_CAP_ENTER_MODIFIED_COMPLIANCE - Enter Modified Compliance. For a description of this
 *    standard PCIe register field, see the PCI Express Specification. Note: The access attributes of this
 *    field are as follows: - Dbi: R/W (sticky) Note: This register field is sticky.
 */
#define PCIE_LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_ENTER_MODIFIED_COMPLIANCE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_ENTER_MODIFIED_COMPLIANCE_SHIFT)) & PCIE_LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_ENTER_MODIFIED_COMPLIANCE_MASK)

#define PCIE_LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_COMPLIANCE_SOS_MASK (0x800U)
#define PCIE_LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_COMPLIANCE_SOS_SHIFT (11U)
/*! PCIE_CAP_COMPLIANCE_SOS - Sets Compliance Skip Ordered Sets transmission. For a description of
 *    this standard PCIe register field, see the PCI Express Specification. Note: The access
 *    attributes of this field are as follows: - Dbi: R/W (sticky) Note: This register field is sticky.
 */
#define PCIE_LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_COMPLIANCE_SOS(x) (((uint32_t)(((uint32_t)(x)) << PCIE_LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_COMPLIANCE_SOS_SHIFT)) & PCIE_LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_COMPLIANCE_SOS_MASK)

#define PCIE_LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_COMPLIANCE_PRESET_MASK (0xF000U)
#define PCIE_LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_COMPLIANCE_PRESET_SHIFT (12U)
/*! PCIE_CAP_COMPLIANCE_PRESET - Sets Compliance Preset/De-emphasis for 5 GT/s and 8 GT/s. For a
 *    description of this standard PCIe register field, see the PCI Express Specification. Note: The
 *    access attributes of this field are as follows: - Dbi: R/W (sticky) Note: This register field is
 *    sticky.
 */
#define PCIE_LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_COMPLIANCE_PRESET(x) (((uint32_t)(((uint32_t)(x)) << PCIE_LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_COMPLIANCE_PRESET_SHIFT)) & PCIE_LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_COMPLIANCE_PRESET_MASK)

#define PCIE_LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_CURR_DEEMPHASIS_MASK (0x10000U)
#define PCIE_LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_CURR_DEEMPHASIS_SHIFT (16U)
/*! PCIE_CAP_CURR_DEEMPHASIS - Current De-emphasis Level. For a description of this standard PCIe
 *    register field, see the PCI Express Specification. In M-PCIe mode this register is always 0x0.
 *    In C-PCIe mode, its contents are derived by sampling the PIPE
 */
#define PCIE_LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_CURR_DEEMPHASIS(x) (((uint32_t)(((uint32_t)(x)) << PCIE_LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_CURR_DEEMPHASIS_SHIFT)) & PCIE_LINK_CONTROL2_LINK_STATUS2_REG_PCIE_CAP_CURR_DEEMPHASIS_MASK)

#define PCIE_LINK_CONTROL2_LINK_STATUS2_REG_RSVDP_26_MASK (0xC000000U)
#define PCIE_LINK_CONTROL2_LINK_STATUS2_REG_RSVDP_26_SHIFT (26U)
/*! RSVDP_26 - Reserved for future use. */
#define PCIE_LINK_CONTROL2_LINK_STATUS2_REG_RSVDP_26(x) (((uint32_t)(((uint32_t)(x)) << PCIE_LINK_CONTROL2_LINK_STATUS2_REG_RSVDP_26_SHIFT)) & PCIE_LINK_CONTROL2_LINK_STATUS2_REG_RSVDP_26_MASK)

#define PCIE_LINK_CONTROL2_LINK_STATUS2_REG_DOWNSTREAM_COMPO_PRESENCE_MASK (0x70000000U)
#define PCIE_LINK_CONTROL2_LINK_STATUS2_REG_DOWNSTREAM_COMPO_PRESENCE_SHIFT (28U)
/*! DOWNSTREAM_COMPO_PRESENCE - Downstream Component Presence. For a description of this standard
 *    PCIe register field, see the PCI Express Base Specification 4.0.
 */
#define PCIE_LINK_CONTROL2_LINK_STATUS2_REG_DOWNSTREAM_COMPO_PRESENCE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_LINK_CONTROL2_LINK_STATUS2_REG_DOWNSTREAM_COMPO_PRESENCE_SHIFT)) & PCIE_LINK_CONTROL2_LINK_STATUS2_REG_DOWNSTREAM_COMPO_PRESENCE_MASK)

#define PCIE_LINK_CONTROL2_LINK_STATUS2_REG_DRS_MESSAGE_RECEIVED_MASK (0x80000000U)
#define PCIE_LINK_CONTROL2_LINK_STATUS2_REG_DRS_MESSAGE_RECEIVED_SHIFT (31U)
/*! DRS_MESSAGE_RECEIVED - DRS Message Received. For a description of this standard PCIe register
 *    field, see the PCI Express Base Specification 4.0. Note: The access attributes of this field are
 *    as follows: - Dbi: RW1C
 */
#define PCIE_LINK_CONTROL2_LINK_STATUS2_REG_DRS_MESSAGE_RECEIVED(x) (((uint32_t)(((uint32_t)(x)) << PCIE_LINK_CONTROL2_LINK_STATUS2_REG_DRS_MESSAGE_RECEIVED_SHIFT)) & PCIE_LINK_CONTROL2_LINK_STATUS2_REG_DRS_MESSAGE_RECEIVED_MASK)
/*! @} */

/*! @name AER_EXT_CAP_HDR_OFF - Advanced Error Reporting Extended Capability Header. */
/*! @{ */

#define PCIE_AER_EXT_CAP_HDR_OFF_CAP_ID_MASK     (0xFFFFU)
#define PCIE_AER_EXT_CAP_HDR_OFF_CAP_ID_SHIFT    (0U)
/*! CAP_ID - AER Extended Capability ID. For a description of this standard PCIe register field, see
 *    the PCI Express Specification. Note: The access attributes of this field are as follows: -
 *    Dbi: if (DBI_RO_WR_EN == 1) then R/W(sticky) else R(sticky) Note: This register field is sticky.
 */
#define PCIE_AER_EXT_CAP_HDR_OFF_CAP_ID(x)       (((uint32_t)(((uint32_t)(x)) << PCIE_AER_EXT_CAP_HDR_OFF_CAP_ID_SHIFT)) & PCIE_AER_EXT_CAP_HDR_OFF_CAP_ID_MASK)

#define PCIE_AER_EXT_CAP_HDR_OFF_CAP_VERSION_MASK (0xF0000U)
#define PCIE_AER_EXT_CAP_HDR_OFF_CAP_VERSION_SHIFT (16U)
/*! CAP_VERSION - Capability Version. For a description of this standard PCIe register field, see
 *    the PCI Express Specification. Note: The access attributes of this field are as follows: - Dbi:
 *    if (DBI_RO_WR_EN == 1) then R/W(sticky) else R(sticky) Note: This register field is sticky.
 */
#define PCIE_AER_EXT_CAP_HDR_OFF_CAP_VERSION(x)  (((uint32_t)(((uint32_t)(x)) << PCIE_AER_EXT_CAP_HDR_OFF_CAP_VERSION_SHIFT)) & PCIE_AER_EXT_CAP_HDR_OFF_CAP_VERSION_MASK)

#define PCIE_AER_EXT_CAP_HDR_OFF_NEXT_OFFSET_MASK (0xFFF00000U)
#define PCIE_AER_EXT_CAP_HDR_OFF_NEXT_OFFSET_SHIFT (20U)
/*! NEXT_OFFSET - Next Capability Offset. For a description of this standard PCIe register field,
 *    see the PCI Express Specification. Note: The access attributes of this field are as follows: -
 *    Dbi: if (DBI_RO_WR_EN == 1) then R/W(sticky) else R(sticky) Note: This register field is sticky.
 */
#define PCIE_AER_EXT_CAP_HDR_OFF_NEXT_OFFSET(x)  (((uint32_t)(((uint32_t)(x)) << PCIE_AER_EXT_CAP_HDR_OFF_NEXT_OFFSET_SHIFT)) & PCIE_AER_EXT_CAP_HDR_OFF_NEXT_OFFSET_MASK)
/*! @} */

/*! @name UNCORR_ERR_STATUS_OFF - Uncorrectable Error Status Register. */
/*! @{ */

#define PCIE_UNCORR_ERR_STATUS_OFF_RSVDP_0_MASK  (0xFU)
#define PCIE_UNCORR_ERR_STATUS_OFF_RSVDP_0_SHIFT (0U)
/*! RSVDP_0 - Reserved for future use. */
#define PCIE_UNCORR_ERR_STATUS_OFF_RSVDP_0(x)    (((uint32_t)(((uint32_t)(x)) << PCIE_UNCORR_ERR_STATUS_OFF_RSVDP_0_SHIFT)) & PCIE_UNCORR_ERR_STATUS_OFF_RSVDP_0_MASK)

#define PCIE_UNCORR_ERR_STATUS_OFF_DL_PROTOCOL_ERR_STATUS_MASK (0x10U)
#define PCIE_UNCORR_ERR_STATUS_OFF_DL_PROTOCOL_ERR_STATUS_SHIFT (4U)
/*! DL_PROTOCOL_ERR_STATUS - Data Link Protocol Error Status. For a description of this standard
 *    PCIe register field, see the PCI Express Specification.
 */
#define PCIE_UNCORR_ERR_STATUS_OFF_DL_PROTOCOL_ERR_STATUS(x) (((uint32_t)(((uint32_t)(x)) << PCIE_UNCORR_ERR_STATUS_OFF_DL_PROTOCOL_ERR_STATUS_SHIFT)) & PCIE_UNCORR_ERR_STATUS_OFF_DL_PROTOCOL_ERR_STATUS_MASK)

#define PCIE_UNCORR_ERR_STATUS_OFF_SURPRISE_DOWN_ERR_STATUS_MASK (0x20U)
#define PCIE_UNCORR_ERR_STATUS_OFF_SURPRISE_DOWN_ERR_STATUS_SHIFT (5U)
/*! SURPRISE_DOWN_ERR_STATUS - Surprise Down Error Status (Optional). For a description of this
 *    standard PCIe register field, see the PCI Express Specification.
 */
#define PCIE_UNCORR_ERR_STATUS_OFF_SURPRISE_DOWN_ERR_STATUS(x) (((uint32_t)(((uint32_t)(x)) << PCIE_UNCORR_ERR_STATUS_OFF_SURPRISE_DOWN_ERR_STATUS_SHIFT)) & PCIE_UNCORR_ERR_STATUS_OFF_SURPRISE_DOWN_ERR_STATUS_MASK)

#define PCIE_UNCORR_ERR_STATUS_OFF_RSVDP_6_MASK  (0xFC0U)
#define PCIE_UNCORR_ERR_STATUS_OFF_RSVDP_6_SHIFT (6U)
/*! RSVDP_6 - Reserved for future use. */
#define PCIE_UNCORR_ERR_STATUS_OFF_RSVDP_6(x)    (((uint32_t)(((uint32_t)(x)) << PCIE_UNCORR_ERR_STATUS_OFF_RSVDP_6_SHIFT)) & PCIE_UNCORR_ERR_STATUS_OFF_RSVDP_6_MASK)

#define PCIE_UNCORR_ERR_STATUS_OFF_POIS_TLP_ERR_STATUS_MASK (0x1000U)
#define PCIE_UNCORR_ERR_STATUS_OFF_POIS_TLP_ERR_STATUS_SHIFT (12U)
/*! POIS_TLP_ERR_STATUS - Poisoned TLP Status. For a description of this standard PCIe register field, see the PCI Express Specification. */
#define PCIE_UNCORR_ERR_STATUS_OFF_POIS_TLP_ERR_STATUS(x) (((uint32_t)(((uint32_t)(x)) << PCIE_UNCORR_ERR_STATUS_OFF_POIS_TLP_ERR_STATUS_SHIFT)) & PCIE_UNCORR_ERR_STATUS_OFF_POIS_TLP_ERR_STATUS_MASK)

#define PCIE_UNCORR_ERR_STATUS_OFF_FC_PROTOCOL_ERR_STATUS_MASK (0x2000U)
#define PCIE_UNCORR_ERR_STATUS_OFF_FC_PROTOCOL_ERR_STATUS_SHIFT (13U)
/*! FC_PROTOCOL_ERR_STATUS - Flow Control Protocol Error Status. For a description of this standard
 *    PCIe register field, see the PCI Express Specification.
 */
#define PCIE_UNCORR_ERR_STATUS_OFF_FC_PROTOCOL_ERR_STATUS(x) (((uint32_t)(((uint32_t)(x)) << PCIE_UNCORR_ERR_STATUS_OFF_FC_PROTOCOL_ERR_STATUS_SHIFT)) & PCIE_UNCORR_ERR_STATUS_OFF_FC_PROTOCOL_ERR_STATUS_MASK)

#define PCIE_UNCORR_ERR_STATUS_OFF_CMPLT_TIMEOUT_ERR_STATUS_MASK (0x4000U)
#define PCIE_UNCORR_ERR_STATUS_OFF_CMPLT_TIMEOUT_ERR_STATUS_SHIFT (14U)
/*! CMPLT_TIMEOUT_ERR_STATUS - Completion Timeout Status. For a description of this standard PCIe register field, see the PCI Express Specification. */
#define PCIE_UNCORR_ERR_STATUS_OFF_CMPLT_TIMEOUT_ERR_STATUS(x) (((uint32_t)(((uint32_t)(x)) << PCIE_UNCORR_ERR_STATUS_OFF_CMPLT_TIMEOUT_ERR_STATUS_SHIFT)) & PCIE_UNCORR_ERR_STATUS_OFF_CMPLT_TIMEOUT_ERR_STATUS_MASK)

#define PCIE_UNCORR_ERR_STATUS_OFF_CMPLT_ABORT_ERR_STATUS_MASK (0x8000U)
#define PCIE_UNCORR_ERR_STATUS_OFF_CMPLT_ABORT_ERR_STATUS_SHIFT (15U)
/*! CMPLT_ABORT_ERR_STATUS - Completer Abort Status. For a description of this standard PCIe register field, see the PCI Express Specification. */
#define PCIE_UNCORR_ERR_STATUS_OFF_CMPLT_ABORT_ERR_STATUS(x) (((uint32_t)(((uint32_t)(x)) << PCIE_UNCORR_ERR_STATUS_OFF_CMPLT_ABORT_ERR_STATUS_SHIFT)) & PCIE_UNCORR_ERR_STATUS_OFF_CMPLT_ABORT_ERR_STATUS_MASK)

#define PCIE_UNCORR_ERR_STATUS_OFF_UNEXP_CMPLT_ERR_STATUS_MASK (0x10000U)
#define PCIE_UNCORR_ERR_STATUS_OFF_UNEXP_CMPLT_ERR_STATUS_SHIFT (16U)
/*! UNEXP_CMPLT_ERR_STATUS - Unexpected Completion Status. For a description of this standard PCIe register field, see the PCI Express Specification. */
#define PCIE_UNCORR_ERR_STATUS_OFF_UNEXP_CMPLT_ERR_STATUS(x) (((uint32_t)(((uint32_t)(x)) << PCIE_UNCORR_ERR_STATUS_OFF_UNEXP_CMPLT_ERR_STATUS_SHIFT)) & PCIE_UNCORR_ERR_STATUS_OFF_UNEXP_CMPLT_ERR_STATUS_MASK)

#define PCIE_UNCORR_ERR_STATUS_OFF_REC_OVERFLOW_ERR_STATUS_MASK (0x20000U)
#define PCIE_UNCORR_ERR_STATUS_OFF_REC_OVERFLOW_ERR_STATUS_SHIFT (17U)
/*! REC_OVERFLOW_ERR_STATUS - Receiver Overflow Status. For a description of this standard PCIe register field, see the PCI Express Specification. */
#define PCIE_UNCORR_ERR_STATUS_OFF_REC_OVERFLOW_ERR_STATUS(x) (((uint32_t)(((uint32_t)(x)) << PCIE_UNCORR_ERR_STATUS_OFF_REC_OVERFLOW_ERR_STATUS_SHIFT)) & PCIE_UNCORR_ERR_STATUS_OFF_REC_OVERFLOW_ERR_STATUS_MASK)

#define PCIE_UNCORR_ERR_STATUS_OFF_MALF_TLP_ERR_STATUS_MASK (0x40000U)
#define PCIE_UNCORR_ERR_STATUS_OFF_MALF_TLP_ERR_STATUS_SHIFT (18U)
/*! MALF_TLP_ERR_STATUS - Malformed TLP Status. For a description of this standard PCIe register field, see the PCI Express Specification. */
#define PCIE_UNCORR_ERR_STATUS_OFF_MALF_TLP_ERR_STATUS(x) (((uint32_t)(((uint32_t)(x)) << PCIE_UNCORR_ERR_STATUS_OFF_MALF_TLP_ERR_STATUS_SHIFT)) & PCIE_UNCORR_ERR_STATUS_OFF_MALF_TLP_ERR_STATUS_MASK)

#define PCIE_UNCORR_ERR_STATUS_OFF_ECRC_ERR_STATUS_MASK (0x80000U)
#define PCIE_UNCORR_ERR_STATUS_OFF_ECRC_ERR_STATUS_SHIFT (19U)
/*! ECRC_ERR_STATUS - ECRC Error Status. For a description of this standard PCIe register field, see the PCI Express Specification. */
#define PCIE_UNCORR_ERR_STATUS_OFF_ECRC_ERR_STATUS(x) (((uint32_t)(((uint32_t)(x)) << PCIE_UNCORR_ERR_STATUS_OFF_ECRC_ERR_STATUS_SHIFT)) & PCIE_UNCORR_ERR_STATUS_OFF_ECRC_ERR_STATUS_MASK)

#define PCIE_UNCORR_ERR_STATUS_OFF_UNSUPPORTED_REQ_ERR_STATUS_MASK (0x100000U)
#define PCIE_UNCORR_ERR_STATUS_OFF_UNSUPPORTED_REQ_ERR_STATUS_SHIFT (20U)
/*! UNSUPPORTED_REQ_ERR_STATUS - Unsupported Request Error Status. For a description of this
 *    standard PCIe register field, see the PCI Express Specification.
 */
#define PCIE_UNCORR_ERR_STATUS_OFF_UNSUPPORTED_REQ_ERR_STATUS(x) (((uint32_t)(((uint32_t)(x)) << PCIE_UNCORR_ERR_STATUS_OFF_UNSUPPORTED_REQ_ERR_STATUS_SHIFT)) & PCIE_UNCORR_ERR_STATUS_OFF_UNSUPPORTED_REQ_ERR_STATUS_MASK)

#define PCIE_UNCORR_ERR_STATUS_OFF_INTERNAL_ERR_STATUS_MASK (0x400000U)
#define PCIE_UNCORR_ERR_STATUS_OFF_INTERNAL_ERR_STATUS_SHIFT (22U)
/*! INTERNAL_ERR_STATUS - Uncorrectable Internal Error Status. For a description of this standard
 *    PCIe register field, see the PCI Express Specification. The controller sets this bit when your
 *    application asserts app_err_bus[9]. It does not set this bit when it detects internal
 *    uncorrectable internal errors such as parity and ECC failures. You should use the outputs from these
 *    errors to drive the app_err_bus[9] input. For more details, see the "Data Integrity (Wire,
 *    Datapath, and RAM Protection)" section in the Databook.
 */
#define PCIE_UNCORR_ERR_STATUS_OFF_INTERNAL_ERR_STATUS(x) (((uint32_t)(((uint32_t)(x)) << PCIE_UNCORR_ERR_STATUS_OFF_INTERNAL_ERR_STATUS_SHIFT)) & PCIE_UNCORR_ERR_STATUS_OFF_INTERNAL_ERR_STATUS_MASK)

#define PCIE_UNCORR_ERR_STATUS_OFF_RSVDP_23_MASK (0x800000U)
#define PCIE_UNCORR_ERR_STATUS_OFF_RSVDP_23_SHIFT (23U)
/*! RSVDP_23 - Reserved for future use. */
#define PCIE_UNCORR_ERR_STATUS_OFF_RSVDP_23(x)   (((uint32_t)(((uint32_t)(x)) << PCIE_UNCORR_ERR_STATUS_OFF_RSVDP_23_SHIFT)) & PCIE_UNCORR_ERR_STATUS_OFF_RSVDP_23_MASK)

#define PCIE_UNCORR_ERR_STATUS_OFF_TLP_PRFX_BLOCKED_ERR_STATUS_MASK (0x2000000U)
#define PCIE_UNCORR_ERR_STATUS_OFF_TLP_PRFX_BLOCKED_ERR_STATUS_SHIFT (25U)
/*! TLP_PRFX_BLOCKED_ERR_STATUS - TLP Prefix Blocked Error Status. For a description of this
 *    standard PCIe register field, see the PCI Express Specification. Note: Not supported.
 */
#define PCIE_UNCORR_ERR_STATUS_OFF_TLP_PRFX_BLOCKED_ERR_STATUS(x) (((uint32_t)(((uint32_t)(x)) << PCIE_UNCORR_ERR_STATUS_OFF_TLP_PRFX_BLOCKED_ERR_STATUS_SHIFT)) & PCIE_UNCORR_ERR_STATUS_OFF_TLP_PRFX_BLOCKED_ERR_STATUS_MASK)

#define PCIE_UNCORR_ERR_STATUS_OFF_RSVDP_26_MASK (0xFC000000U)
#define PCIE_UNCORR_ERR_STATUS_OFF_RSVDP_26_SHIFT (26U)
/*! RSVDP_26 - Reserved for future use. */
#define PCIE_UNCORR_ERR_STATUS_OFF_RSVDP_26(x)   (((uint32_t)(((uint32_t)(x)) << PCIE_UNCORR_ERR_STATUS_OFF_RSVDP_26_SHIFT)) & PCIE_UNCORR_ERR_STATUS_OFF_RSVDP_26_MASK)
/*! @} */

/*! @name UNCORR_ERR_MASK_OFF - Uncorrectable Error Mask Register. */
/*! @{ */

#define PCIE_UNCORR_ERR_MASK_OFF_RSVDP_0_MASK    (0xFU)
#define PCIE_UNCORR_ERR_MASK_OFF_RSVDP_0_SHIFT   (0U)
/*! RSVDP_0 - Reserved for future use. */
#define PCIE_UNCORR_ERR_MASK_OFF_RSVDP_0(x)      (((uint32_t)(((uint32_t)(x)) << PCIE_UNCORR_ERR_MASK_OFF_RSVDP_0_SHIFT)) & PCIE_UNCORR_ERR_MASK_OFF_RSVDP_0_MASK)

#define PCIE_UNCORR_ERR_MASK_OFF_DL_PROTOCOL_ERR_MASK_MASK (0x10U)
#define PCIE_UNCORR_ERR_MASK_OFF_DL_PROTOCOL_ERR_MASK_SHIFT (4U)
/*! DL_PROTOCOL_ERR_MASK - Data Link Protocol Error Mask. For a description of this standard PCIe
 *    register field, see the PCI Express Specification. Note: This register field is sticky.
 */
#define PCIE_UNCORR_ERR_MASK_OFF_DL_PROTOCOL_ERR_MASK(x) (((uint32_t)(((uint32_t)(x)) << PCIE_UNCORR_ERR_MASK_OFF_DL_PROTOCOL_ERR_MASK_SHIFT)) & PCIE_UNCORR_ERR_MASK_OFF_DL_PROTOCOL_ERR_MASK_MASK)

#define PCIE_UNCORR_ERR_MASK_OFF_SURPRISE_DOWN_ERR_MASK_MASK (0x20U)
#define PCIE_UNCORR_ERR_MASK_OFF_SURPRISE_DOWN_ERR_MASK_SHIFT (5U)
/*! SURPRISE_DOWN_ERR_MASK - Surprise Down Error Mask. For a description of this standard PCIe
 *    register field, see the PCI Express Specification. Note: The access attributes of this field are as
 *    follows: - Dbi: LINK_CAPABILITIES_REG.PCIE_CAP_SURPRISE_DOWN_ERR_REP_CAP ? RW : RO Note: This
 *    register field is sticky.
 */
#define PCIE_UNCORR_ERR_MASK_OFF_SURPRISE_DOWN_ERR_MASK(x) (((uint32_t)(((uint32_t)(x)) << PCIE_UNCORR_ERR_MASK_OFF_SURPRISE_DOWN_ERR_MASK_SHIFT)) & PCIE_UNCORR_ERR_MASK_OFF_SURPRISE_DOWN_ERR_MASK_MASK)

#define PCIE_UNCORR_ERR_MASK_OFF_RSVDP_6_MASK    (0xFC0U)
#define PCIE_UNCORR_ERR_MASK_OFF_RSVDP_6_SHIFT   (6U)
/*! RSVDP_6 - Reserved for future use. */
#define PCIE_UNCORR_ERR_MASK_OFF_RSVDP_6(x)      (((uint32_t)(((uint32_t)(x)) << PCIE_UNCORR_ERR_MASK_OFF_RSVDP_6_SHIFT)) & PCIE_UNCORR_ERR_MASK_OFF_RSVDP_6_MASK)

#define PCIE_UNCORR_ERR_MASK_OFF_POIS_TLP_ERR_MASK_MASK (0x1000U)
#define PCIE_UNCORR_ERR_MASK_OFF_POIS_TLP_ERR_MASK_SHIFT (12U)
/*! POIS_TLP_ERR_MASK - Poisoned TLP Error Mask. For a description of this standard PCIe register
 *    field, see the PCI Express Specification. Note: This register field is sticky.
 */
#define PCIE_UNCORR_ERR_MASK_OFF_POIS_TLP_ERR_MASK(x) (((uint32_t)(((uint32_t)(x)) << PCIE_UNCORR_ERR_MASK_OFF_POIS_TLP_ERR_MASK_SHIFT)) & PCIE_UNCORR_ERR_MASK_OFF_POIS_TLP_ERR_MASK_MASK)

#define PCIE_UNCORR_ERR_MASK_OFF_FC_PROTOCOL_ERR_MASK_MASK (0x2000U)
#define PCIE_UNCORR_ERR_MASK_OFF_FC_PROTOCOL_ERR_MASK_SHIFT (13U)
/*! FC_PROTOCOL_ERR_MASK - Flow Control Protocol Error Mask. For a description of this standard PCIe
 *    register field, see the PCI Express Specification. Note: This register field is sticky.
 */
#define PCIE_UNCORR_ERR_MASK_OFF_FC_PROTOCOL_ERR_MASK(x) (((uint32_t)(((uint32_t)(x)) << PCIE_UNCORR_ERR_MASK_OFF_FC_PROTOCOL_ERR_MASK_SHIFT)) & PCIE_UNCORR_ERR_MASK_OFF_FC_PROTOCOL_ERR_MASK_MASK)

#define PCIE_UNCORR_ERR_MASK_OFF_CMPLT_TIMEOUT_ERR_MASK_MASK (0x4000U)
#define PCIE_UNCORR_ERR_MASK_OFF_CMPLT_TIMEOUT_ERR_MASK_SHIFT (14U)
/*! CMPLT_TIMEOUT_ERR_MASK - Completion Timeout Error Mask. For a description of this standard PCIe
 *    register field, see the PCI Express Specification. Note: This register field is sticky.
 */
#define PCIE_UNCORR_ERR_MASK_OFF_CMPLT_TIMEOUT_ERR_MASK(x) (((uint32_t)(((uint32_t)(x)) << PCIE_UNCORR_ERR_MASK_OFF_CMPLT_TIMEOUT_ERR_MASK_SHIFT)) & PCIE_UNCORR_ERR_MASK_OFF_CMPLT_TIMEOUT_ERR_MASK_MASK)

#define PCIE_UNCORR_ERR_MASK_OFF_CMPLT_ABORT_ERR_MASK_MASK (0x8000U)
#define PCIE_UNCORR_ERR_MASK_OFF_CMPLT_ABORT_ERR_MASK_SHIFT (15U)
/*! CMPLT_ABORT_ERR_MASK - Completer Abort Error Mask (Optional). For a description of this standard
 *    PCIe register field, see the PCI Express Specification. Note: This register field is sticky.
 */
#define PCIE_UNCORR_ERR_MASK_OFF_CMPLT_ABORT_ERR_MASK(x) (((uint32_t)(((uint32_t)(x)) << PCIE_UNCORR_ERR_MASK_OFF_CMPLT_ABORT_ERR_MASK_SHIFT)) & PCIE_UNCORR_ERR_MASK_OFF_CMPLT_ABORT_ERR_MASK_MASK)

#define PCIE_UNCORR_ERR_MASK_OFF_UNEXP_CMPLT_ERR_MASK_MASK (0x10000U)
#define PCIE_UNCORR_ERR_MASK_OFF_UNEXP_CMPLT_ERR_MASK_SHIFT (16U)
/*! UNEXP_CMPLT_ERR_MASK - Unexpected Completion Mask. For a description of this standard PCIe
 *    register field, see the PCI Express Specification. Note: This register field is sticky.
 */
#define PCIE_UNCORR_ERR_MASK_OFF_UNEXP_CMPLT_ERR_MASK(x) (((uint32_t)(((uint32_t)(x)) << PCIE_UNCORR_ERR_MASK_OFF_UNEXP_CMPLT_ERR_MASK_SHIFT)) & PCIE_UNCORR_ERR_MASK_OFF_UNEXP_CMPLT_ERR_MASK_MASK)

#define PCIE_UNCORR_ERR_MASK_OFF_REC_OVERFLOW_ERR_MASK_MASK (0x20000U)
#define PCIE_UNCORR_ERR_MASK_OFF_REC_OVERFLOW_ERR_MASK_SHIFT (17U)
/*! REC_OVERFLOW_ERR_MASK - Receiver Overflow Mask (Optional). For a description of this standard
 *    PCIe register field, see the PCI Express Specification. Note: This register field is sticky.
 */
#define PCIE_UNCORR_ERR_MASK_OFF_REC_OVERFLOW_ERR_MASK(x) (((uint32_t)(((uint32_t)(x)) << PCIE_UNCORR_ERR_MASK_OFF_REC_OVERFLOW_ERR_MASK_SHIFT)) & PCIE_UNCORR_ERR_MASK_OFF_REC_OVERFLOW_ERR_MASK_MASK)

#define PCIE_UNCORR_ERR_MASK_OFF_MALF_TLP_ERR_MASK_MASK (0x40000U)
#define PCIE_UNCORR_ERR_MASK_OFF_MALF_TLP_ERR_MASK_SHIFT (18U)
/*! MALF_TLP_ERR_MASK - Malformed TLP Mask. For a description of this standard PCIe register field,
 *    see the PCI Express Specification. Note: This register field is sticky.
 */
#define PCIE_UNCORR_ERR_MASK_OFF_MALF_TLP_ERR_MASK(x) (((uint32_t)(((uint32_t)(x)) << PCIE_UNCORR_ERR_MASK_OFF_MALF_TLP_ERR_MASK_SHIFT)) & PCIE_UNCORR_ERR_MASK_OFF_MALF_TLP_ERR_MASK_MASK)

#define PCIE_UNCORR_ERR_MASK_OFF_ECRC_ERR_MASK_MASK (0x80000U)
#define PCIE_UNCORR_ERR_MASK_OFF_ECRC_ERR_MASK_SHIFT (19U)
/*! ECRC_ERR_MASK - ECRC Error Mask (Optional). For a description of this standard PCIe register
 *    field, see the PCI Express Specification. Note: The access attributes of this field are as
 *    follows: - Dbi: R/W (sticky) Note: This register field is sticky.
 */
#define PCIE_UNCORR_ERR_MASK_OFF_ECRC_ERR_MASK(x) (((uint32_t)(((uint32_t)(x)) << PCIE_UNCORR_ERR_MASK_OFF_ECRC_ERR_MASK_SHIFT)) & PCIE_UNCORR_ERR_MASK_OFF_ECRC_ERR_MASK_MASK)

#define PCIE_UNCORR_ERR_MASK_OFF_UNSUPPORTED_REQ_ERR_MASK_MASK (0x100000U)
#define PCIE_UNCORR_ERR_MASK_OFF_UNSUPPORTED_REQ_ERR_MASK_SHIFT (20U)
/*! UNSUPPORTED_REQ_ERR_MASK - Unsupported Request Error Mask. For a description of this standard
 *    PCIe register field, see the PCI Express Specification. Note: This register field is sticky.
 */
#define PCIE_UNCORR_ERR_MASK_OFF_UNSUPPORTED_REQ_ERR_MASK(x) (((uint32_t)(((uint32_t)(x)) << PCIE_UNCORR_ERR_MASK_OFF_UNSUPPORTED_REQ_ERR_MASK_SHIFT)) & PCIE_UNCORR_ERR_MASK_OFF_UNSUPPORTED_REQ_ERR_MASK_MASK)

#define PCIE_UNCORR_ERR_MASK_OFF_INTERNAL_ERR_MASK_MASK (0x400000U)
#define PCIE_UNCORR_ERR_MASK_OFF_INTERNAL_ERR_MASK_SHIFT (22U)
/*! INTERNAL_ERR_MASK - Uncorrectable Internal Error Mask (Optional). For a description of this
 *    standard PCIe register field, see the PCI Express Specification. Note: This register field is
 *    sticky.
 */
#define PCIE_UNCORR_ERR_MASK_OFF_INTERNAL_ERR_MASK(x) (((uint32_t)(((uint32_t)(x)) << PCIE_UNCORR_ERR_MASK_OFF_INTERNAL_ERR_MASK_SHIFT)) & PCIE_UNCORR_ERR_MASK_OFF_INTERNAL_ERR_MASK_MASK)

#define PCIE_UNCORR_ERR_MASK_OFF_RSVDP_23_MASK   (0x800000U)
#define PCIE_UNCORR_ERR_MASK_OFF_RSVDP_23_SHIFT  (23U)
/*! RSVDP_23 - Reserved for future use. */
#define PCIE_UNCORR_ERR_MASK_OFF_RSVDP_23(x)     (((uint32_t)(((uint32_t)(x)) << PCIE_UNCORR_ERR_MASK_OFF_RSVDP_23_SHIFT)) & PCIE_UNCORR_ERR_MASK_OFF_RSVDP_23_MASK)

#define PCIE_UNCORR_ERR_MASK_OFF_ATOMIC_EGRESS_BLOCKED_ERR_MASK_MASK (0x1000000U)
#define PCIE_UNCORR_ERR_MASK_OFF_ATOMIC_EGRESS_BLOCKED_ERR_MASK_SHIFT (24U)
/*! ATOMIC_EGRESS_BLOCKED_ERR_MASK - AtomicOp Egress Block Mask (Optional). For a description of
 *    this standard PCIe register field, see the PCI Express Specification. Note: The access attributes
 *    of this field are as follows: - Dbi: R/W (sticky) Note: This register field is sticky.
 */
#define PCIE_UNCORR_ERR_MASK_OFF_ATOMIC_EGRESS_BLOCKED_ERR_MASK(x) (((uint32_t)(((uint32_t)(x)) << PCIE_UNCORR_ERR_MASK_OFF_ATOMIC_EGRESS_BLOCKED_ERR_MASK_SHIFT)) & PCIE_UNCORR_ERR_MASK_OFF_ATOMIC_EGRESS_BLOCKED_ERR_MASK_MASK)

#define PCIE_UNCORR_ERR_MASK_OFF_TLP_PRFX_BLOCKED_ERR_MASK_MASK (0x2000000U)
#define PCIE_UNCORR_ERR_MASK_OFF_TLP_PRFX_BLOCKED_ERR_MASK_SHIFT (25U)
/*! TLP_PRFX_BLOCKED_ERR_MASK - TLP Prefix Blocked Error Mask. For a description of this standard
 *    PCIe register field, see the PCI Express Specification. Note: Not supported. Note: The access
 *    attributes of this field are as follows: - Dbi: R/W (sticky) Note: This register field is sticky.
 */
#define PCIE_UNCORR_ERR_MASK_OFF_TLP_PRFX_BLOCKED_ERR_MASK(x) (((uint32_t)(((uint32_t)(x)) << PCIE_UNCORR_ERR_MASK_OFF_TLP_PRFX_BLOCKED_ERR_MASK_SHIFT)) & PCIE_UNCORR_ERR_MASK_OFF_TLP_PRFX_BLOCKED_ERR_MASK_MASK)

#define PCIE_UNCORR_ERR_MASK_OFF_RSVDP_26_MASK   (0xFC000000U)
#define PCIE_UNCORR_ERR_MASK_OFF_RSVDP_26_SHIFT  (26U)
/*! RSVDP_26 - Reserved for future use. */
#define PCIE_UNCORR_ERR_MASK_OFF_RSVDP_26(x)     (((uint32_t)(((uint32_t)(x)) << PCIE_UNCORR_ERR_MASK_OFF_RSVDP_26_SHIFT)) & PCIE_UNCORR_ERR_MASK_OFF_RSVDP_26_MASK)
/*! @} */

/*! @name UNCORR_ERR_SEV_OFF - Uncorrectable Error Severity Register. */
/*! @{ */

#define PCIE_UNCORR_ERR_SEV_OFF_RSVDP_0_MASK     (0xFU)
#define PCIE_UNCORR_ERR_SEV_OFF_RSVDP_0_SHIFT    (0U)
/*! RSVDP_0 - Reserved for future use. */
#define PCIE_UNCORR_ERR_SEV_OFF_RSVDP_0(x)       (((uint32_t)(((uint32_t)(x)) << PCIE_UNCORR_ERR_SEV_OFF_RSVDP_0_SHIFT)) & PCIE_UNCORR_ERR_SEV_OFF_RSVDP_0_MASK)

#define PCIE_UNCORR_ERR_SEV_OFF_DL_PROTOCOL_ERR_SEVERITY_MASK (0x10U)
#define PCIE_UNCORR_ERR_SEV_OFF_DL_PROTOCOL_ERR_SEVERITY_SHIFT (4U)
/*! DL_PROTOCOL_ERR_SEVERITY - Data Link Protocol Error Severity. For a description of this standard
 *    PCIe register field, see the PCI Express Specification. Note: This register field is sticky.
 */
#define PCIE_UNCORR_ERR_SEV_OFF_DL_PROTOCOL_ERR_SEVERITY(x) (((uint32_t)(((uint32_t)(x)) << PCIE_UNCORR_ERR_SEV_OFF_DL_PROTOCOL_ERR_SEVERITY_SHIFT)) & PCIE_UNCORR_ERR_SEV_OFF_DL_PROTOCOL_ERR_SEVERITY_MASK)

#define PCIE_UNCORR_ERR_SEV_OFF_SURPRISE_DOWN_ERR_SVRITY_MASK (0x20U)
#define PCIE_UNCORR_ERR_SEV_OFF_SURPRISE_DOWN_ERR_SVRITY_SHIFT (5U)
/*! SURPRISE_DOWN_ERR_SVRITY - Surprise Down Error Severity (Optional). For a description of this
 *    standard PCIe register field, see the PCI Express Specification. Note: The access attributes of
 *    this field are as follows: - Dbi: LINK_CAPABILITIES_REG.PCIE_CAP_SURPRISE_DOWN_ERR_REP_CAP ?
 *    RW : RO Note: This register field is sticky.
 */
#define PCIE_UNCORR_ERR_SEV_OFF_SURPRISE_DOWN_ERR_SVRITY(x) (((uint32_t)(((uint32_t)(x)) << PCIE_UNCORR_ERR_SEV_OFF_SURPRISE_DOWN_ERR_SVRITY_SHIFT)) & PCIE_UNCORR_ERR_SEV_OFF_SURPRISE_DOWN_ERR_SVRITY_MASK)

#define PCIE_UNCORR_ERR_SEV_OFF_RSVDP_6_MASK     (0xFC0U)
#define PCIE_UNCORR_ERR_SEV_OFF_RSVDP_6_SHIFT    (6U)
/*! RSVDP_6 - Reserved for future use. */
#define PCIE_UNCORR_ERR_SEV_OFF_RSVDP_6(x)       (((uint32_t)(((uint32_t)(x)) << PCIE_UNCORR_ERR_SEV_OFF_RSVDP_6_SHIFT)) & PCIE_UNCORR_ERR_SEV_OFF_RSVDP_6_MASK)

#define PCIE_UNCORR_ERR_SEV_OFF_POIS_TLP_ERR_SEVERITY_MASK (0x1000U)
#define PCIE_UNCORR_ERR_SEV_OFF_POIS_TLP_ERR_SEVERITY_SHIFT (12U)
/*! POIS_TLP_ERR_SEVERITY - Poisoned TLP Severity. For a description of this standard PCIe register
 *    field, see the PCI Express Specification. Note: This register field is sticky.
 */
#define PCIE_UNCORR_ERR_SEV_OFF_POIS_TLP_ERR_SEVERITY(x) (((uint32_t)(((uint32_t)(x)) << PCIE_UNCORR_ERR_SEV_OFF_POIS_TLP_ERR_SEVERITY_SHIFT)) & PCIE_UNCORR_ERR_SEV_OFF_POIS_TLP_ERR_SEVERITY_MASK)

#define PCIE_UNCORR_ERR_SEV_OFF_FC_PROTOCOL_ERR_SEVERITY_MASK (0x2000U)
#define PCIE_UNCORR_ERR_SEV_OFF_FC_PROTOCOL_ERR_SEVERITY_SHIFT (13U)
/*! FC_PROTOCOL_ERR_SEVERITY - Flow Control Protocol Error Severity (Optional). For a description of
 *    this standard PCIe register field, see the PCI Express Specification. Note: This register
 *    field is sticky.
 */
#define PCIE_UNCORR_ERR_SEV_OFF_FC_PROTOCOL_ERR_SEVERITY(x) (((uint32_t)(((uint32_t)(x)) << PCIE_UNCORR_ERR_SEV_OFF_FC_PROTOCOL_ERR_SEVERITY_SHIFT)) & PCIE_UNCORR_ERR_SEV_OFF_FC_PROTOCOL_ERR_SEVERITY_MASK)

#define PCIE_UNCORR_ERR_SEV_OFF_CMPLT_TIMEOUT_ERR_SEVERITY_MASK (0x4000U)
#define PCIE_UNCORR_ERR_SEV_OFF_CMPLT_TIMEOUT_ERR_SEVERITY_SHIFT (14U)
/*! CMPLT_TIMEOUT_ERR_SEVERITY - Completion Timeout Error Severity. For a description of this
 *    standard PCIe register field, see the PCI Express Specification. Note: This register field is sticky.
 */
#define PCIE_UNCORR_ERR_SEV_OFF_CMPLT_TIMEOUT_ERR_SEVERITY(x) (((uint32_t)(((uint32_t)(x)) << PCIE_UNCORR_ERR_SEV_OFF_CMPLT_TIMEOUT_ERR_SEVERITY_SHIFT)) & PCIE_UNCORR_ERR_SEV_OFF_CMPLT_TIMEOUT_ERR_SEVERITY_MASK)

#define PCIE_UNCORR_ERR_SEV_OFF_CMPLT_ABORT_ERR_SEVERITY_MASK (0x8000U)
#define PCIE_UNCORR_ERR_SEV_OFF_CMPLT_ABORT_ERR_SEVERITY_SHIFT (15U)
/*! CMPLT_ABORT_ERR_SEVERITY - Completer Abort Error Severity (Optional). For a description of this
 *    standard PCIe register field, see the PCI Express Specification. Note: This register field is
 *    sticky.
 */
#define PCIE_UNCORR_ERR_SEV_OFF_CMPLT_ABORT_ERR_SEVERITY(x) (((uint32_t)(((uint32_t)(x)) << PCIE_UNCORR_ERR_SEV_OFF_CMPLT_ABORT_ERR_SEVERITY_SHIFT)) & PCIE_UNCORR_ERR_SEV_OFF_CMPLT_ABORT_ERR_SEVERITY_MASK)

#define PCIE_UNCORR_ERR_SEV_OFF_UNEXP_CMPLT_ERR_SEVERITY_MASK (0x10000U)
#define PCIE_UNCORR_ERR_SEV_OFF_UNEXP_CMPLT_ERR_SEVERITY_SHIFT (16U)
/*! UNEXP_CMPLT_ERR_SEVERITY - Unexpected Completion Error Severity. For a description of this
 *    standard PCIe register field, see the PCI Express Specification. Note: This register field is
 *    sticky.
 */
#define PCIE_UNCORR_ERR_SEV_OFF_UNEXP_CMPLT_ERR_SEVERITY(x) (((uint32_t)(((uint32_t)(x)) << PCIE_UNCORR_ERR_SEV_OFF_UNEXP_CMPLT_ERR_SEVERITY_SHIFT)) & PCIE_UNCORR_ERR_SEV_OFF_UNEXP_CMPLT_ERR_SEVERITY_MASK)

#define PCIE_UNCORR_ERR_SEV_OFF_REC_OVERFLOW_ERR_SEVERITY_MASK (0x20000U)
#define PCIE_UNCORR_ERR_SEV_OFF_REC_OVERFLOW_ERR_SEVERITY_SHIFT (17U)
/*! REC_OVERFLOW_ERR_SEVERITY - Receiver Overflow Error Severity (Optional). For a description of
 *    this standard PCIe register field, see the PCI Express Specification. Note: This register field
 *    is sticky.
 */
#define PCIE_UNCORR_ERR_SEV_OFF_REC_OVERFLOW_ERR_SEVERITY(x) (((uint32_t)(((uint32_t)(x)) << PCIE_UNCORR_ERR_SEV_OFF_REC_OVERFLOW_ERR_SEVERITY_SHIFT)) & PCIE_UNCORR_ERR_SEV_OFF_REC_OVERFLOW_ERR_SEVERITY_MASK)

#define PCIE_UNCORR_ERR_SEV_OFF_MALF_TLP_ERR_SEVERITY_MASK (0x40000U)
#define PCIE_UNCORR_ERR_SEV_OFF_MALF_TLP_ERR_SEVERITY_SHIFT (18U)
/*! MALF_TLP_ERR_SEVERITY - Malformed TLP Severity. For a description of this standard PCIe register
 *    field, see the PCI Express Specification. Note: This register field is sticky.
 */
#define PCIE_UNCORR_ERR_SEV_OFF_MALF_TLP_ERR_SEVERITY(x) (((uint32_t)(((uint32_t)(x)) << PCIE_UNCORR_ERR_SEV_OFF_MALF_TLP_ERR_SEVERITY_SHIFT)) & PCIE_UNCORR_ERR_SEV_OFF_MALF_TLP_ERR_SEVERITY_MASK)

#define PCIE_UNCORR_ERR_SEV_OFF_ECRC_ERR_SEVERITY_MASK (0x80000U)
#define PCIE_UNCORR_ERR_SEV_OFF_ECRC_ERR_SEVERITY_SHIFT (19U)
/*! ECRC_ERR_SEVERITY - ECRC Error Severity (Optional). For a description of this standard PCIe
 *    register field, see the PCI Express Specification. Note: The access attributes of this field are
 *    as follows: - Dbi: R/W (sticky) Note: This register field is sticky.
 */
#define PCIE_UNCORR_ERR_SEV_OFF_ECRC_ERR_SEVERITY(x) (((uint32_t)(((uint32_t)(x)) << PCIE_UNCORR_ERR_SEV_OFF_ECRC_ERR_SEVERITY_SHIFT)) & PCIE_UNCORR_ERR_SEV_OFF_ECRC_ERR_SEVERITY_MASK)

#define PCIE_UNCORR_ERR_SEV_OFF_UNSUPPORTED_REQ_ERR_SEVERITY_MASK (0x100000U)
#define PCIE_UNCORR_ERR_SEV_OFF_UNSUPPORTED_REQ_ERR_SEVERITY_SHIFT (20U)
/*! UNSUPPORTED_REQ_ERR_SEVERITY - Unsupported Request Error Severity. For a description of this
 *    standard PCIe register field, see the PCI Express Specification. Note: This register field is
 *    sticky.
 */
#define PCIE_UNCORR_ERR_SEV_OFF_UNSUPPORTED_REQ_ERR_SEVERITY(x) (((uint32_t)(((uint32_t)(x)) << PCIE_UNCORR_ERR_SEV_OFF_UNSUPPORTED_REQ_ERR_SEVERITY_SHIFT)) & PCIE_UNCORR_ERR_SEV_OFF_UNSUPPORTED_REQ_ERR_SEVERITY_MASK)

#define PCIE_UNCORR_ERR_SEV_OFF_INTERNAL_ERR_SEVERITY_MASK (0x400000U)
#define PCIE_UNCORR_ERR_SEV_OFF_INTERNAL_ERR_SEVERITY_SHIFT (22U)
/*! INTERNAL_ERR_SEVERITY - Uncorrectable Internal Error Severity (Optional). For a description of
 *    this standard PCIe register field, see the PCI Express Specification. Note: This register field
 *    is sticky.
 */
#define PCIE_UNCORR_ERR_SEV_OFF_INTERNAL_ERR_SEVERITY(x) (((uint32_t)(((uint32_t)(x)) << PCIE_UNCORR_ERR_SEV_OFF_INTERNAL_ERR_SEVERITY_SHIFT)) & PCIE_UNCORR_ERR_SEV_OFF_INTERNAL_ERR_SEVERITY_MASK)

#define PCIE_UNCORR_ERR_SEV_OFF_RSVDP_23_MASK    (0x800000U)
#define PCIE_UNCORR_ERR_SEV_OFF_RSVDP_23_SHIFT   (23U)
/*! RSVDP_23 - Reserved for future use. */
#define PCIE_UNCORR_ERR_SEV_OFF_RSVDP_23(x)      (((uint32_t)(((uint32_t)(x)) << PCIE_UNCORR_ERR_SEV_OFF_RSVDP_23_SHIFT)) & PCIE_UNCORR_ERR_SEV_OFF_RSVDP_23_MASK)

#define PCIE_UNCORR_ERR_SEV_OFF_ATOMIC_EGRESS_BLOCKED_ERR_SEVERITY_MASK (0x1000000U)
#define PCIE_UNCORR_ERR_SEV_OFF_ATOMIC_EGRESS_BLOCKED_ERR_SEVERITY_SHIFT (24U)
/*! ATOMIC_EGRESS_BLOCKED_ERR_SEVERITY - AtomicOp Egress Blocked Severity (Optional). For a
 *    description of this standard PCIe register field, see the PCI Express Specification. Note: The access
 *    attributes of this field are as follows: - Dbi: R/W (sticky) Note: This register field is
 *    sticky.
 */
#define PCIE_UNCORR_ERR_SEV_OFF_ATOMIC_EGRESS_BLOCKED_ERR_SEVERITY(x) (((uint32_t)(((uint32_t)(x)) << PCIE_UNCORR_ERR_SEV_OFF_ATOMIC_EGRESS_BLOCKED_ERR_SEVERITY_SHIFT)) & PCIE_UNCORR_ERR_SEV_OFF_ATOMIC_EGRESS_BLOCKED_ERR_SEVERITY_MASK)

#define PCIE_UNCORR_ERR_SEV_OFF_TLP_PRFX_BLOCKED_ERR_SEVERITY_MASK (0x2000000U)
#define PCIE_UNCORR_ERR_SEV_OFF_TLP_PRFX_BLOCKED_ERR_SEVERITY_SHIFT (25U)
/*! TLP_PRFX_BLOCKED_ERR_SEVERITY - TLP Prefix Blocked Error Severity (Optional). For a description
 *    of this standard PCIe register field, see the PCI Express Specification. Note: Not supported.
 *    Note: The access attributes of this field are as follows: - Dbi: R/W (sticky) Note: This
 *    register field is sticky.
 */
#define PCIE_UNCORR_ERR_SEV_OFF_TLP_PRFX_BLOCKED_ERR_SEVERITY(x) (((uint32_t)(((uint32_t)(x)) << PCIE_UNCORR_ERR_SEV_OFF_TLP_PRFX_BLOCKED_ERR_SEVERITY_SHIFT)) & PCIE_UNCORR_ERR_SEV_OFF_TLP_PRFX_BLOCKED_ERR_SEVERITY_MASK)

#define PCIE_UNCORR_ERR_SEV_OFF_RSVDP_26_MASK    (0xFC000000U)
#define PCIE_UNCORR_ERR_SEV_OFF_RSVDP_26_SHIFT   (26U)
/*! RSVDP_26 - Reserved for future use. */
#define PCIE_UNCORR_ERR_SEV_OFF_RSVDP_26(x)      (((uint32_t)(((uint32_t)(x)) << PCIE_UNCORR_ERR_SEV_OFF_RSVDP_26_SHIFT)) & PCIE_UNCORR_ERR_SEV_OFF_RSVDP_26_MASK)
/*! @} */

/*! @name CORR_ERR_STATUS_OFF - Correctable Error Status Register. */
/*! @{ */

#define PCIE_CORR_ERR_STATUS_OFF_RX_ERR_STATUS_MASK (0x1U)
#define PCIE_CORR_ERR_STATUS_OFF_RX_ERR_STATUS_SHIFT (0U)
/*! RX_ERR_STATUS - Receiver Error Status (Optional). For a description of this standard PCIe
 *    register field, see the PCI Express Specification.
 */
#define PCIE_CORR_ERR_STATUS_OFF_RX_ERR_STATUS(x) (((uint32_t)(((uint32_t)(x)) << PCIE_CORR_ERR_STATUS_OFF_RX_ERR_STATUS_SHIFT)) & PCIE_CORR_ERR_STATUS_OFF_RX_ERR_STATUS_MASK)

#define PCIE_CORR_ERR_STATUS_OFF_RSVDP_1_MASK    (0x3EU)
#define PCIE_CORR_ERR_STATUS_OFF_RSVDP_1_SHIFT   (1U)
/*! RSVDP_1 - Reserved for future use. */
#define PCIE_CORR_ERR_STATUS_OFF_RSVDP_1(x)      (((uint32_t)(((uint32_t)(x)) << PCIE_CORR_ERR_STATUS_OFF_RSVDP_1_SHIFT)) & PCIE_CORR_ERR_STATUS_OFF_RSVDP_1_MASK)

#define PCIE_CORR_ERR_STATUS_OFF_BAD_TLP_STATUS_MASK (0x40U)
#define PCIE_CORR_ERR_STATUS_OFF_BAD_TLP_STATUS_SHIFT (6U)
/*! BAD_TLP_STATUS - Bad TLP Status. For a description of this standard PCIe register field, see the PCI Express Specification. */
#define PCIE_CORR_ERR_STATUS_OFF_BAD_TLP_STATUS(x) (((uint32_t)(((uint32_t)(x)) << PCIE_CORR_ERR_STATUS_OFF_BAD_TLP_STATUS_SHIFT)) & PCIE_CORR_ERR_STATUS_OFF_BAD_TLP_STATUS_MASK)

#define PCIE_CORR_ERR_STATUS_OFF_BAD_DLLP_STATUS_MASK (0x80U)
#define PCIE_CORR_ERR_STATUS_OFF_BAD_DLLP_STATUS_SHIFT (7U)
/*! BAD_DLLP_STATUS - Bad DLLP Status. For a description of this standard PCIe register field, see the PCI Express Specification. */
#define PCIE_CORR_ERR_STATUS_OFF_BAD_DLLP_STATUS(x) (((uint32_t)(((uint32_t)(x)) << PCIE_CORR_ERR_STATUS_OFF_BAD_DLLP_STATUS_SHIFT)) & PCIE_CORR_ERR_STATUS_OFF_BAD_DLLP_STATUS_MASK)

#define PCIE_CORR_ERR_STATUS_OFF_REPLAY_NO_ROLEOVER_STATUS_MASK (0x100U)
#define PCIE_CORR_ERR_STATUS_OFF_REPLAY_NO_ROLEOVER_STATUS_SHIFT (8U)
/*! REPLAY_NO_ROLEOVER_STATUS - REPLAY_NUM Rollover Status. For a description of this standard PCIe register field, see the PCI Express Specification. */
#define PCIE_CORR_ERR_STATUS_OFF_REPLAY_NO_ROLEOVER_STATUS(x) (((uint32_t)(((uint32_t)(x)) << PCIE_CORR_ERR_STATUS_OFF_REPLAY_NO_ROLEOVER_STATUS_SHIFT)) & PCIE_CORR_ERR_STATUS_OFF_REPLAY_NO_ROLEOVER_STATUS_MASK)

#define PCIE_CORR_ERR_STATUS_OFF_RSVDP_9_MASK    (0xE00U)
#define PCIE_CORR_ERR_STATUS_OFF_RSVDP_9_SHIFT   (9U)
/*! RSVDP_9 - Reserved for future use. */
#define PCIE_CORR_ERR_STATUS_OFF_RSVDP_9(x)      (((uint32_t)(((uint32_t)(x)) << PCIE_CORR_ERR_STATUS_OFF_RSVDP_9_SHIFT)) & PCIE_CORR_ERR_STATUS_OFF_RSVDP_9_MASK)

#define PCIE_CORR_ERR_STATUS_OFF_RPL_TIMER_TIMEOUT_STATUS_MASK (0x1000U)
#define PCIE_CORR_ERR_STATUS_OFF_RPL_TIMER_TIMEOUT_STATUS_SHIFT (12U)
/*! RPL_TIMER_TIMEOUT_STATUS - Replay Timer Timeout Status. For a description of this standard PCIe register field, see the PCI Express Specification. */
#define PCIE_CORR_ERR_STATUS_OFF_RPL_TIMER_TIMEOUT_STATUS(x) (((uint32_t)(((uint32_t)(x)) << PCIE_CORR_ERR_STATUS_OFF_RPL_TIMER_TIMEOUT_STATUS_SHIFT)) & PCIE_CORR_ERR_STATUS_OFF_RPL_TIMER_TIMEOUT_STATUS_MASK)

#define PCIE_CORR_ERR_STATUS_OFF_ADVISORY_NON_FATAL_ERR_STATUS_MASK (0x2000U)
#define PCIE_CORR_ERR_STATUS_OFF_ADVISORY_NON_FATAL_ERR_STATUS_SHIFT (13U)
/*! ADVISORY_NON_FATAL_ERR_STATUS - Advisory Non-Fatal Error Status. For a description of this
 *    standard PCIe register field, see the PCI Express Specification.
 */
#define PCIE_CORR_ERR_STATUS_OFF_ADVISORY_NON_FATAL_ERR_STATUS(x) (((uint32_t)(((uint32_t)(x)) << PCIE_CORR_ERR_STATUS_OFF_ADVISORY_NON_FATAL_ERR_STATUS_SHIFT)) & PCIE_CORR_ERR_STATUS_OFF_ADVISORY_NON_FATAL_ERR_STATUS_MASK)

#define PCIE_CORR_ERR_STATUS_OFF_CORRECTED_INT_ERR_STATUS_MASK (0x4000U)
#define PCIE_CORR_ERR_STATUS_OFF_CORRECTED_INT_ERR_STATUS_SHIFT (14U)
/*! CORRECTED_INT_ERR_STATUS - Corrected Internal Error Status (Optional). For a description of this
 *    standard PCIe register field, see the PCI Express Specification.
 */
#define PCIE_CORR_ERR_STATUS_OFF_CORRECTED_INT_ERR_STATUS(x) (((uint32_t)(((uint32_t)(x)) << PCIE_CORR_ERR_STATUS_OFF_CORRECTED_INT_ERR_STATUS_SHIFT)) & PCIE_CORR_ERR_STATUS_OFF_CORRECTED_INT_ERR_STATUS_MASK)

#define PCIE_CORR_ERR_STATUS_OFF_HEADER_LOG_OVERFLOW_STATUS_MASK (0x8000U)
#define PCIE_CORR_ERR_STATUS_OFF_HEADER_LOG_OVERFLOW_STATUS_SHIFT (15U)
/*! HEADER_LOG_OVERFLOW_STATUS - Header Log Overflow Error Status (Optional). For a description of
 *    this standard PCIe register field, see the PCI Express Specification.
 */
#define PCIE_CORR_ERR_STATUS_OFF_HEADER_LOG_OVERFLOW_STATUS(x) (((uint32_t)(((uint32_t)(x)) << PCIE_CORR_ERR_STATUS_OFF_HEADER_LOG_OVERFLOW_STATUS_SHIFT)) & PCIE_CORR_ERR_STATUS_OFF_HEADER_LOG_OVERFLOW_STATUS_MASK)

#define PCIE_CORR_ERR_STATUS_OFF_RSVDP_16_MASK   (0xFFFF0000U)
#define PCIE_CORR_ERR_STATUS_OFF_RSVDP_16_SHIFT  (16U)
/*! RSVDP_16 - Reserved for future use. */
#define PCIE_CORR_ERR_STATUS_OFF_RSVDP_16(x)     (((uint32_t)(((uint32_t)(x)) << PCIE_CORR_ERR_STATUS_OFF_RSVDP_16_SHIFT)) & PCIE_CORR_ERR_STATUS_OFF_RSVDP_16_MASK)
/*! @} */

/*! @name CORR_ERR_MASK_OFF - Correctable Error Mask Register. */
/*! @{ */

#define PCIE_CORR_ERR_MASK_OFF_RX_ERR_MASK_MASK  (0x1U)
#define PCIE_CORR_ERR_MASK_OFF_RX_ERR_MASK_SHIFT (0U)
/*! RX_ERR_MASK - Receiver Error Mask (Optional). For a description of this standard PCIe register
 *    field, see the PCI Express Specification. Note: This register field is sticky.
 */
#define PCIE_CORR_ERR_MASK_OFF_RX_ERR_MASK(x)    (((uint32_t)(((uint32_t)(x)) << PCIE_CORR_ERR_MASK_OFF_RX_ERR_MASK_SHIFT)) & PCIE_CORR_ERR_MASK_OFF_RX_ERR_MASK_MASK)

#define PCIE_CORR_ERR_MASK_OFF_RSVDP_1_MASK      (0x3EU)
#define PCIE_CORR_ERR_MASK_OFF_RSVDP_1_SHIFT     (1U)
/*! RSVDP_1 - Reserved for future use. */
#define PCIE_CORR_ERR_MASK_OFF_RSVDP_1(x)        (((uint32_t)(((uint32_t)(x)) << PCIE_CORR_ERR_MASK_OFF_RSVDP_1_SHIFT)) & PCIE_CORR_ERR_MASK_OFF_RSVDP_1_MASK)

#define PCIE_CORR_ERR_MASK_OFF_BAD_TLP_MASK_MASK (0x40U)
#define PCIE_CORR_ERR_MASK_OFF_BAD_TLP_MASK_SHIFT (6U)
/*! BAD_TLP_MASK - Bad TLP Mask. For a description of this standard PCIe register field, see the PCI
 *    Express Specification. Note: This register field is sticky.
 */
#define PCIE_CORR_ERR_MASK_OFF_BAD_TLP_MASK(x)   (((uint32_t)(((uint32_t)(x)) << PCIE_CORR_ERR_MASK_OFF_BAD_TLP_MASK_SHIFT)) & PCIE_CORR_ERR_MASK_OFF_BAD_TLP_MASK_MASK)

#define PCIE_CORR_ERR_MASK_OFF_BAD_DLLP_MASK_MASK (0x80U)
#define PCIE_CORR_ERR_MASK_OFF_BAD_DLLP_MASK_SHIFT (7U)
/*! BAD_DLLP_MASK - Bad DLLP Mask. For a description of this standard PCIe register field, see the
 *    PCI Express Specification. Note: This register field is sticky.
 */
#define PCIE_CORR_ERR_MASK_OFF_BAD_DLLP_MASK(x)  (((uint32_t)(((uint32_t)(x)) << PCIE_CORR_ERR_MASK_OFF_BAD_DLLP_MASK_SHIFT)) & PCIE_CORR_ERR_MASK_OFF_BAD_DLLP_MASK_MASK)

#define PCIE_CORR_ERR_MASK_OFF_REPLAY_NO_ROLEOVER_MASK_MASK (0x100U)
#define PCIE_CORR_ERR_MASK_OFF_REPLAY_NO_ROLEOVER_MASK_SHIFT (8U)
/*! REPLAY_NO_ROLEOVER_MASK - REPLAY_NUM Rollover Mask. For a description of this standard PCIe
 *    register field, see the PCI Express Specification. Note: This register field is sticky.
 */
#define PCIE_CORR_ERR_MASK_OFF_REPLAY_NO_ROLEOVER_MASK(x) (((uint32_t)(((uint32_t)(x)) << PCIE_CORR_ERR_MASK_OFF_REPLAY_NO_ROLEOVER_MASK_SHIFT)) & PCIE_CORR_ERR_MASK_OFF_REPLAY_NO_ROLEOVER_MASK_MASK)

#define PCIE_CORR_ERR_MASK_OFF_RSVDP_9_MASK      (0xE00U)
#define PCIE_CORR_ERR_MASK_OFF_RSVDP_9_SHIFT     (9U)
/*! RSVDP_9 - Reserved for future use. */
#define PCIE_CORR_ERR_MASK_OFF_RSVDP_9(x)        (((uint32_t)(((uint32_t)(x)) << PCIE_CORR_ERR_MASK_OFF_RSVDP_9_SHIFT)) & PCIE_CORR_ERR_MASK_OFF_RSVDP_9_MASK)

#define PCIE_CORR_ERR_MASK_OFF_RPL_TIMER_TIMEOUT_MASK_MASK (0x1000U)
#define PCIE_CORR_ERR_MASK_OFF_RPL_TIMER_TIMEOUT_MASK_SHIFT (12U)
/*! RPL_TIMER_TIMEOUT_MASK - Replay Timer Timeout Mask. For a description of this standard PCIe
 *    register field, see the PCI Express Specification. Note: This register field is sticky.
 */
#define PCIE_CORR_ERR_MASK_OFF_RPL_TIMER_TIMEOUT_MASK(x) (((uint32_t)(((uint32_t)(x)) << PCIE_CORR_ERR_MASK_OFF_RPL_TIMER_TIMEOUT_MASK_SHIFT)) & PCIE_CORR_ERR_MASK_OFF_RPL_TIMER_TIMEOUT_MASK_MASK)

#define PCIE_CORR_ERR_MASK_OFF_ADVISORY_NON_FATAL_ERR_MASK_MASK (0x2000U)
#define PCIE_CORR_ERR_MASK_OFF_ADVISORY_NON_FATAL_ERR_MASK_SHIFT (13U)
/*! ADVISORY_NON_FATAL_ERR_MASK - Advisory Non-Fatal Error Mask. For a description of this standard
 *    PCIe register field, see the PCI Express Specification. Note: This register field is sticky.
 */
#define PCIE_CORR_ERR_MASK_OFF_ADVISORY_NON_FATAL_ERR_MASK(x) (((uint32_t)(((uint32_t)(x)) << PCIE_CORR_ERR_MASK_OFF_ADVISORY_NON_FATAL_ERR_MASK_SHIFT)) & PCIE_CORR_ERR_MASK_OFF_ADVISORY_NON_FATAL_ERR_MASK_MASK)

#define PCIE_CORR_ERR_MASK_OFF_CORRECTED_INT_ERR_MASK_MASK (0x4000U)
#define PCIE_CORR_ERR_MASK_OFF_CORRECTED_INT_ERR_MASK_SHIFT (14U)
/*! CORRECTED_INT_ERR_MASK - Corrected Internal Error Mask (Optional). For a description of this
 *    standard PCIe register field, see the PCI Express Specification. Note: This register field is
 *    sticky.
 */
#define PCIE_CORR_ERR_MASK_OFF_CORRECTED_INT_ERR_MASK(x) (((uint32_t)(((uint32_t)(x)) << PCIE_CORR_ERR_MASK_OFF_CORRECTED_INT_ERR_MASK_SHIFT)) & PCIE_CORR_ERR_MASK_OFF_CORRECTED_INT_ERR_MASK_MASK)

#define PCIE_CORR_ERR_MASK_OFF_HEADER_LOG_OVERFLOW_MASK_MASK (0x8000U)
#define PCIE_CORR_ERR_MASK_OFF_HEADER_LOG_OVERFLOW_MASK_SHIFT (15U)
/*! HEADER_LOG_OVERFLOW_MASK - Header Log Overflow Error Mask (Optional). For a description of this
 *    standard PCIe register field, see the PCI Express Specification. Note: This register field is
 *    sticky.
 */
#define PCIE_CORR_ERR_MASK_OFF_HEADER_LOG_OVERFLOW_MASK(x) (((uint32_t)(((uint32_t)(x)) << PCIE_CORR_ERR_MASK_OFF_HEADER_LOG_OVERFLOW_MASK_SHIFT)) & PCIE_CORR_ERR_MASK_OFF_HEADER_LOG_OVERFLOW_MASK_MASK)

#define PCIE_CORR_ERR_MASK_OFF_RSVDP_16_MASK     (0xFFFF0000U)
#define PCIE_CORR_ERR_MASK_OFF_RSVDP_16_SHIFT    (16U)
/*! RSVDP_16 - Reserved for future use. */
#define PCIE_CORR_ERR_MASK_OFF_RSVDP_16(x)       (((uint32_t)(((uint32_t)(x)) << PCIE_CORR_ERR_MASK_OFF_RSVDP_16_SHIFT)) & PCIE_CORR_ERR_MASK_OFF_RSVDP_16_MASK)
/*! @} */

/*! @name ADV_ERR_CAP_CTRL_OFF - Advanced Error Capabilities and Control Register. */
/*! @{ */

#define PCIE_ADV_ERR_CAP_CTRL_OFF_FIRST_ERR_POINTER_MASK (0x1FU)
#define PCIE_ADV_ERR_CAP_CTRL_OFF_FIRST_ERR_POINTER_SHIFT (0U)
/*! FIRST_ERR_POINTER - First Error Pointer. For a description of this standard PCIe register field,
 *    see the PCI Express Specification. Note: This register field is sticky.
 */
#define PCIE_ADV_ERR_CAP_CTRL_OFF_FIRST_ERR_POINTER(x) (((uint32_t)(((uint32_t)(x)) << PCIE_ADV_ERR_CAP_CTRL_OFF_FIRST_ERR_POINTER_SHIFT)) & PCIE_ADV_ERR_CAP_CTRL_OFF_FIRST_ERR_POINTER_MASK)

#define PCIE_ADV_ERR_CAP_CTRL_OFF_ECRC_GEN_CAP_MASK (0x20U)
#define PCIE_ADV_ERR_CAP_CTRL_OFF_ECRC_GEN_CAP_SHIFT (5U)
/*! ECRC_GEN_CAP - ECRC Generation Capable. For a description of this standard PCIe register field,
 *    see the PCI Express Specification. Note: This register field is sticky.
 */
#define PCIE_ADV_ERR_CAP_CTRL_OFF_ECRC_GEN_CAP(x) (((uint32_t)(((uint32_t)(x)) << PCIE_ADV_ERR_CAP_CTRL_OFF_ECRC_GEN_CAP_SHIFT)) & PCIE_ADV_ERR_CAP_CTRL_OFF_ECRC_GEN_CAP_MASK)

#define PCIE_ADV_ERR_CAP_CTRL_OFF_ECRC_GEN_EN_MASK (0x40U)
#define PCIE_ADV_ERR_CAP_CTRL_OFF_ECRC_GEN_EN_SHIFT (6U)
/*! ECRC_GEN_EN - ECRC Generation Enable. For a description of this standard PCIe register field,
 *    see the PCI Express Specification. Note: This register field is sticky.
 */
#define PCIE_ADV_ERR_CAP_CTRL_OFF_ECRC_GEN_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_ADV_ERR_CAP_CTRL_OFF_ECRC_GEN_EN_SHIFT)) & PCIE_ADV_ERR_CAP_CTRL_OFF_ECRC_GEN_EN_MASK)

#define PCIE_ADV_ERR_CAP_CTRL_OFF_ECRC_CHECK_CAP_MASK (0x80U)
#define PCIE_ADV_ERR_CAP_CTRL_OFF_ECRC_CHECK_CAP_SHIFT (7U)
/*! ECRC_CHECK_CAP - ECRC Check Capable. For a description of this standard PCIe register field, see
 *    the PCI Express Specification. Note: This register field is sticky.
 */
#define PCIE_ADV_ERR_CAP_CTRL_OFF_ECRC_CHECK_CAP(x) (((uint32_t)(((uint32_t)(x)) << PCIE_ADV_ERR_CAP_CTRL_OFF_ECRC_CHECK_CAP_SHIFT)) & PCIE_ADV_ERR_CAP_CTRL_OFF_ECRC_CHECK_CAP_MASK)

#define PCIE_ADV_ERR_CAP_CTRL_OFF_ECRC_CHECK_EN_MASK (0x100U)
#define PCIE_ADV_ERR_CAP_CTRL_OFF_ECRC_CHECK_EN_SHIFT (8U)
/*! ECRC_CHECK_EN - ECRC Check Enable. For a description of this standard PCIe register field, see
 *    the PCI Express Specification. Note: This register field is sticky.
 */
#define PCIE_ADV_ERR_CAP_CTRL_OFF_ECRC_CHECK_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_ADV_ERR_CAP_CTRL_OFF_ECRC_CHECK_EN_SHIFT)) & PCIE_ADV_ERR_CAP_CTRL_OFF_ECRC_CHECK_EN_MASK)

#define PCIE_ADV_ERR_CAP_CTRL_OFF_MULTIPLE_HEADER_CAP_MASK (0x200U)
#define PCIE_ADV_ERR_CAP_CTRL_OFF_MULTIPLE_HEADER_CAP_SHIFT (9U)
/*! MULTIPLE_HEADER_CAP - Multiple Header Recording Capable. For a description of this standard PCIe
 *    register field, see the PCI Express Specification. Note: This register field is sticky.
 */
#define PCIE_ADV_ERR_CAP_CTRL_OFF_MULTIPLE_HEADER_CAP(x) (((uint32_t)(((uint32_t)(x)) << PCIE_ADV_ERR_CAP_CTRL_OFF_MULTIPLE_HEADER_CAP_SHIFT)) & PCIE_ADV_ERR_CAP_CTRL_OFF_MULTIPLE_HEADER_CAP_MASK)

#define PCIE_ADV_ERR_CAP_CTRL_OFF_MULTIPLE_HEADER_EN_MASK (0x400U)
#define PCIE_ADV_ERR_CAP_CTRL_OFF_MULTIPLE_HEADER_EN_SHIFT (10U)
/*! MULTIPLE_HEADER_EN - Multiple Header Recording Enable. For a description of this standard PCIe
 *    register field, see the PCI Express Specification. Note: This register field is sticky.
 */
#define PCIE_ADV_ERR_CAP_CTRL_OFF_MULTIPLE_HEADER_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_ADV_ERR_CAP_CTRL_OFF_MULTIPLE_HEADER_EN_SHIFT)) & PCIE_ADV_ERR_CAP_CTRL_OFF_MULTIPLE_HEADER_EN_MASK)

#define PCIE_ADV_ERR_CAP_CTRL_OFF_RSVDP_12_MASK  (0xFFFFF000U)
#define PCIE_ADV_ERR_CAP_CTRL_OFF_RSVDP_12_SHIFT (12U)
/*! RSVDP_12 - Reserved for future use. */
#define PCIE_ADV_ERR_CAP_CTRL_OFF_RSVDP_12(x)    (((uint32_t)(((uint32_t)(x)) << PCIE_ADV_ERR_CAP_CTRL_OFF_RSVDP_12_SHIFT)) & PCIE_ADV_ERR_CAP_CTRL_OFF_RSVDP_12_MASK)
/*! @} */

/*! @name HDR_LOG_0_OFF - Header Log Register 0. */
/*! @{ */

#define PCIE_HDR_LOG_0_OFF_FIRST_DWORD_FIRST_BYTE_MASK (0xFFU)
#define PCIE_HDR_LOG_0_OFF_FIRST_DWORD_FIRST_BYTE_SHIFT (0U)
/*! FIRST_DWORD_FIRST_BYTE - Byte 0 of Header log register of First 32 bit Data Word. For a
 *    description of this standard PCIe register field, see the PCI Express Specification. Note: This
 *    register field is sticky.
 */
#define PCIE_HDR_LOG_0_OFF_FIRST_DWORD_FIRST_BYTE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_HDR_LOG_0_OFF_FIRST_DWORD_FIRST_BYTE_SHIFT)) & PCIE_HDR_LOG_0_OFF_FIRST_DWORD_FIRST_BYTE_MASK)

#define PCIE_HDR_LOG_0_OFF_FIRST_DWORD_SECOND_BYTE_MASK (0xFF00U)
#define PCIE_HDR_LOG_0_OFF_FIRST_DWORD_SECOND_BYTE_SHIFT (8U)
/*! FIRST_DWORD_SECOND_BYTE - Byte 1 of Header log register of First 32 bit Data Word. For a
 *    description of this standard PCIe register field, see the PCI Express Specification. Note: This
 *    register field is sticky.
 */
#define PCIE_HDR_LOG_0_OFF_FIRST_DWORD_SECOND_BYTE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_HDR_LOG_0_OFF_FIRST_DWORD_SECOND_BYTE_SHIFT)) & PCIE_HDR_LOG_0_OFF_FIRST_DWORD_SECOND_BYTE_MASK)

#define PCIE_HDR_LOG_0_OFF_FIRST_DWORD_THIRD_BYTE_MASK (0xFF0000U)
#define PCIE_HDR_LOG_0_OFF_FIRST_DWORD_THIRD_BYTE_SHIFT (16U)
/*! FIRST_DWORD_THIRD_BYTE - Byte 2 of Header log register of First 32 bit Data Word. For a
 *    description of this standard PCIe register field, see the PCI Express Specification. Note: This
 *    register field is sticky.
 */
#define PCIE_HDR_LOG_0_OFF_FIRST_DWORD_THIRD_BYTE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_HDR_LOG_0_OFF_FIRST_DWORD_THIRD_BYTE_SHIFT)) & PCIE_HDR_LOG_0_OFF_FIRST_DWORD_THIRD_BYTE_MASK)

#define PCIE_HDR_LOG_0_OFF_FIRST_DWORD_FOURTH_BYTE_MASK (0xFF000000U)
#define PCIE_HDR_LOG_0_OFF_FIRST_DWORD_FOURTH_BYTE_SHIFT (24U)
/*! FIRST_DWORD_FOURTH_BYTE - Byte 3 of Header log register of First 32 bit Data Word. For a
 *    description of this standard PCIe register field, see the PCI Express Specification. Note: This
 *    register field is sticky.
 */
#define PCIE_HDR_LOG_0_OFF_FIRST_DWORD_FOURTH_BYTE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_HDR_LOG_0_OFF_FIRST_DWORD_FOURTH_BYTE_SHIFT)) & PCIE_HDR_LOG_0_OFF_FIRST_DWORD_FOURTH_BYTE_MASK)
/*! @} */

/*! @name HDR_LOG_1_OFF - Header Log Register 1. */
/*! @{ */

#define PCIE_HDR_LOG_1_OFF_SECOND_DWORD_FIRST_BYTE_MASK (0xFFU)
#define PCIE_HDR_LOG_1_OFF_SECOND_DWORD_FIRST_BYTE_SHIFT (0U)
/*! SECOND_DWORD_FIRST_BYTE - Byte 0 of Header log register of Second 32 bit Data Word. For a
 *    description of this standard PCIe register field, see the PCI Express Specification. Note: This
 *    register field is sticky.
 */
#define PCIE_HDR_LOG_1_OFF_SECOND_DWORD_FIRST_BYTE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_HDR_LOG_1_OFF_SECOND_DWORD_FIRST_BYTE_SHIFT)) & PCIE_HDR_LOG_1_OFF_SECOND_DWORD_FIRST_BYTE_MASK)

#define PCIE_HDR_LOG_1_OFF_SECOND_DWORD_SECOND_BYTE_MASK (0xFF00U)
#define PCIE_HDR_LOG_1_OFF_SECOND_DWORD_SECOND_BYTE_SHIFT (8U)
/*! SECOND_DWORD_SECOND_BYTE - Byte 1 of Header log register of Second 32 bit Data Word. For a
 *    description of this standard PCIe register field, see the PCI Express Specification. Note: This
 *    register field is sticky.
 */
#define PCIE_HDR_LOG_1_OFF_SECOND_DWORD_SECOND_BYTE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_HDR_LOG_1_OFF_SECOND_DWORD_SECOND_BYTE_SHIFT)) & PCIE_HDR_LOG_1_OFF_SECOND_DWORD_SECOND_BYTE_MASK)

#define PCIE_HDR_LOG_1_OFF_SECOND_DWORD_THIRD_BYTE_MASK (0xFF0000U)
#define PCIE_HDR_LOG_1_OFF_SECOND_DWORD_THIRD_BYTE_SHIFT (16U)
/*! SECOND_DWORD_THIRD_BYTE - Byte 2 of Header log register of Second 32 bit Data Word. For a
 *    description of this standard PCIe register field, see the PCI Express Specification. Note: This
 *    register field is sticky.
 */
#define PCIE_HDR_LOG_1_OFF_SECOND_DWORD_THIRD_BYTE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_HDR_LOG_1_OFF_SECOND_DWORD_THIRD_BYTE_SHIFT)) & PCIE_HDR_LOG_1_OFF_SECOND_DWORD_THIRD_BYTE_MASK)

#define PCIE_HDR_LOG_1_OFF_SECOND_DWORD_FOURTH_BYTE_MASK (0xFF000000U)
#define PCIE_HDR_LOG_1_OFF_SECOND_DWORD_FOURTH_BYTE_SHIFT (24U)
/*! SECOND_DWORD_FOURTH_BYTE - Byte 3 of Header log register of Second 32 bit Data Word. For a
 *    description of this standard PCIe register field, see the PCI Express Specification. Note: This
 *    register field is sticky.
 */
#define PCIE_HDR_LOG_1_OFF_SECOND_DWORD_FOURTH_BYTE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_HDR_LOG_1_OFF_SECOND_DWORD_FOURTH_BYTE_SHIFT)) & PCIE_HDR_LOG_1_OFF_SECOND_DWORD_FOURTH_BYTE_MASK)
/*! @} */

/*! @name HDR_LOG_2_OFF - Header Log Register 2. */
/*! @{ */

#define PCIE_HDR_LOG_2_OFF_THIRD_DWORD_FIRST_BYTE_MASK (0xFFU)
#define PCIE_HDR_LOG_2_OFF_THIRD_DWORD_FIRST_BYTE_SHIFT (0U)
/*! THIRD_DWORD_FIRST_BYTE - Byte 0 of Header log register of Third 32 bit Data Word. For a
 *    description of this standard PCIe register field, see the PCI Express Specification. Note: This
 *    register field is sticky.
 */
#define PCIE_HDR_LOG_2_OFF_THIRD_DWORD_FIRST_BYTE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_HDR_LOG_2_OFF_THIRD_DWORD_FIRST_BYTE_SHIFT)) & PCIE_HDR_LOG_2_OFF_THIRD_DWORD_FIRST_BYTE_MASK)

#define PCIE_HDR_LOG_2_OFF_THIRD_DWORD_SECOND_BYTE_MASK (0xFF00U)
#define PCIE_HDR_LOG_2_OFF_THIRD_DWORD_SECOND_BYTE_SHIFT (8U)
/*! THIRD_DWORD_SECOND_BYTE - Byte 1 of Header log register of Third 32 bit Data Word. For a
 *    description of this standard PCIe register field, see the PCI Express Specification. Note: This
 *    register field is sticky.
 */
#define PCIE_HDR_LOG_2_OFF_THIRD_DWORD_SECOND_BYTE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_HDR_LOG_2_OFF_THIRD_DWORD_SECOND_BYTE_SHIFT)) & PCIE_HDR_LOG_2_OFF_THIRD_DWORD_SECOND_BYTE_MASK)

#define PCIE_HDR_LOG_2_OFF_THIRD_DWORD_THIRD_BYTE_MASK (0xFF0000U)
#define PCIE_HDR_LOG_2_OFF_THIRD_DWORD_THIRD_BYTE_SHIFT (16U)
/*! THIRD_DWORD_THIRD_BYTE - Byte 2 of Header log register of Third 32 bit Data Word. For a
 *    description of this standard PCIe register field, see the PCI Express Specification. Note: This
 *    register field is sticky.
 */
#define PCIE_HDR_LOG_2_OFF_THIRD_DWORD_THIRD_BYTE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_HDR_LOG_2_OFF_THIRD_DWORD_THIRD_BYTE_SHIFT)) & PCIE_HDR_LOG_2_OFF_THIRD_DWORD_THIRD_BYTE_MASK)

#define PCIE_HDR_LOG_2_OFF_THIRD_DWORD_FOURTH_BYTE_MASK (0xFF000000U)
#define PCIE_HDR_LOG_2_OFF_THIRD_DWORD_FOURTH_BYTE_SHIFT (24U)
/*! THIRD_DWORD_FOURTH_BYTE - Byte 3 of Header log register of Third 32 bit Data Word. For a
 *    description of this standard PCIe register field, see the PCI Express Specification. Note: This
 *    register field is sticky.
 */
#define PCIE_HDR_LOG_2_OFF_THIRD_DWORD_FOURTH_BYTE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_HDR_LOG_2_OFF_THIRD_DWORD_FOURTH_BYTE_SHIFT)) & PCIE_HDR_LOG_2_OFF_THIRD_DWORD_FOURTH_BYTE_MASK)
/*! @} */

/*! @name HDR_LOG_3_OFF - Header Log Register 3. */
/*! @{ */

#define PCIE_HDR_LOG_3_OFF_FOURTH_DWORD_FIRST_BYTE_MASK (0xFFU)
#define PCIE_HDR_LOG_3_OFF_FOURTH_DWORD_FIRST_BYTE_SHIFT (0U)
/*! FOURTH_DWORD_FIRST_BYTE - Byte 0 of Header log register of Fourth 32 bit Data Word. For a
 *    description of this standard PCIe register field, see the PCI Express Specification. Note: This
 *    register field is sticky.
 */
#define PCIE_HDR_LOG_3_OFF_FOURTH_DWORD_FIRST_BYTE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_HDR_LOG_3_OFF_FOURTH_DWORD_FIRST_BYTE_SHIFT)) & PCIE_HDR_LOG_3_OFF_FOURTH_DWORD_FIRST_BYTE_MASK)

#define PCIE_HDR_LOG_3_OFF_FOURTH_DWORD_SECOND_BYTE_MASK (0xFF00U)
#define PCIE_HDR_LOG_3_OFF_FOURTH_DWORD_SECOND_BYTE_SHIFT (8U)
/*! FOURTH_DWORD_SECOND_BYTE - Byte 1 of Header log register of Fourth 32 bit Data Word. For a
 *    description of this standard PCIe register field, see the PCI Express Specification. Note: This
 *    register field is sticky.
 */
#define PCIE_HDR_LOG_3_OFF_FOURTH_DWORD_SECOND_BYTE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_HDR_LOG_3_OFF_FOURTH_DWORD_SECOND_BYTE_SHIFT)) & PCIE_HDR_LOG_3_OFF_FOURTH_DWORD_SECOND_BYTE_MASK)

#define PCIE_HDR_LOG_3_OFF_FOURTH_DWORD_THIRD_BYTE_MASK (0xFF0000U)
#define PCIE_HDR_LOG_3_OFF_FOURTH_DWORD_THIRD_BYTE_SHIFT (16U)
/*! FOURTH_DWORD_THIRD_BYTE - Byte 2 of Header log register of Fourth 32 bit Data Word. For a
 *    description of this standard PCIe register field, see the PCI Express Specification. Note: This
 *    register field is sticky.
 */
#define PCIE_HDR_LOG_3_OFF_FOURTH_DWORD_THIRD_BYTE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_HDR_LOG_3_OFF_FOURTH_DWORD_THIRD_BYTE_SHIFT)) & PCIE_HDR_LOG_3_OFF_FOURTH_DWORD_THIRD_BYTE_MASK)

#define PCIE_HDR_LOG_3_OFF_FOURTH_DWORD_FOURTH_BYTE_MASK (0xFF000000U)
#define PCIE_HDR_LOG_3_OFF_FOURTH_DWORD_FOURTH_BYTE_SHIFT (24U)
/*! FOURTH_DWORD_FOURTH_BYTE - Byte 3 of Header log register of Fourth 32 bit Data Word. For a
 *    description of this standard PCIe register field, see the PCI Express Specification. Note: This
 *    register field is sticky.
 */
#define PCIE_HDR_LOG_3_OFF_FOURTH_DWORD_FOURTH_BYTE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_HDR_LOG_3_OFF_FOURTH_DWORD_FOURTH_BYTE_SHIFT)) & PCIE_HDR_LOG_3_OFF_FOURTH_DWORD_FOURTH_BYTE_MASK)
/*! @} */

/*! @name ROOT_ERR_CMD_OFF - Root Error Command Register. */
/*! @{ */

#define PCIE_ROOT_ERR_CMD_OFF_CORR_ERR_REPORTING_EN_MASK (0x1U)
#define PCIE_ROOT_ERR_CMD_OFF_CORR_ERR_REPORTING_EN_SHIFT (0U)
/*! CORR_ERR_REPORTING_EN - Correctable Error Reporting Enable. For a description of this standard
 *    PCIe register field, see the PCI Express Specification.
 */
#define PCIE_ROOT_ERR_CMD_OFF_CORR_ERR_REPORTING_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_ROOT_ERR_CMD_OFF_CORR_ERR_REPORTING_EN_SHIFT)) & PCIE_ROOT_ERR_CMD_OFF_CORR_ERR_REPORTING_EN_MASK)

#define PCIE_ROOT_ERR_CMD_OFF_NON_FATAL_ERR_REPORTING_EN_MASK (0x2U)
#define PCIE_ROOT_ERR_CMD_OFF_NON_FATAL_ERR_REPORTING_EN_SHIFT (1U)
/*! NON_FATAL_ERR_REPORTING_EN - Non-Fatal Error Reporting Enable. For a description of this
 *    standard PCIe register field, see the PCI Express Specification.
 */
#define PCIE_ROOT_ERR_CMD_OFF_NON_FATAL_ERR_REPORTING_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_ROOT_ERR_CMD_OFF_NON_FATAL_ERR_REPORTING_EN_SHIFT)) & PCIE_ROOT_ERR_CMD_OFF_NON_FATAL_ERR_REPORTING_EN_MASK)

#define PCIE_ROOT_ERR_CMD_OFF_FATAL_ERR_REPORTING_EN_MASK (0x4U)
#define PCIE_ROOT_ERR_CMD_OFF_FATAL_ERR_REPORTING_EN_SHIFT (2U)
/*! FATAL_ERR_REPORTING_EN - Fatal Error Reporting Enable. For a description of this standard PCIe register field, see the PCI Express Specification. */
#define PCIE_ROOT_ERR_CMD_OFF_FATAL_ERR_REPORTING_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_ROOT_ERR_CMD_OFF_FATAL_ERR_REPORTING_EN_SHIFT)) & PCIE_ROOT_ERR_CMD_OFF_FATAL_ERR_REPORTING_EN_MASK)

#define PCIE_ROOT_ERR_CMD_OFF_RSVDP_3_MASK       (0xFFFFFFF8U)
#define PCIE_ROOT_ERR_CMD_OFF_RSVDP_3_SHIFT      (3U)
/*! RSVDP_3 - Reserved for future use. */
#define PCIE_ROOT_ERR_CMD_OFF_RSVDP_3(x)         (((uint32_t)(((uint32_t)(x)) << PCIE_ROOT_ERR_CMD_OFF_RSVDP_3_SHIFT)) & PCIE_ROOT_ERR_CMD_OFF_RSVDP_3_MASK)
/*! @} */

/*! @name ROOT_ERR_STATUS_OFF - Root Error Status Register. */
/*! @{ */

#define PCIE_ROOT_ERR_STATUS_OFF_ERR_COR_RX_MASK (0x1U)
#define PCIE_ROOT_ERR_STATUS_OFF_ERR_COR_RX_SHIFT (0U)
/*! ERR_COR_RX - Correctable Error Received. For a description of this standard PCIe register field, see the PCI Express Specification. */
#define PCIE_ROOT_ERR_STATUS_OFF_ERR_COR_RX(x)   (((uint32_t)(((uint32_t)(x)) << PCIE_ROOT_ERR_STATUS_OFF_ERR_COR_RX_SHIFT)) & PCIE_ROOT_ERR_STATUS_OFF_ERR_COR_RX_MASK)

#define PCIE_ROOT_ERR_STATUS_OFF_MUL_ERR_COR_RX_MASK (0x2U)
#define PCIE_ROOT_ERR_STATUS_OFF_MUL_ERR_COR_RX_SHIFT (1U)
/*! MUL_ERR_COR_RX - Multiple Correctable Errors Received. For a description of this standard PCIe
 *    register field, see the PCI Express Specification.
 */
#define PCIE_ROOT_ERR_STATUS_OFF_MUL_ERR_COR_RX(x) (((uint32_t)(((uint32_t)(x)) << PCIE_ROOT_ERR_STATUS_OFF_MUL_ERR_COR_RX_SHIFT)) & PCIE_ROOT_ERR_STATUS_OFF_MUL_ERR_COR_RX_MASK)

#define PCIE_ROOT_ERR_STATUS_OFF_ERR_FATAL_NON_FATAL_RX_MASK (0x4U)
#define PCIE_ROOT_ERR_STATUS_OFF_ERR_FATAL_NON_FATAL_RX_SHIFT (2U)
/*! ERR_FATAL_NON_FATAL_RX - Fatal or Non-Fatal Error Received. For a description of this standard
 *    PCIe register field, see the PCI Express Specification.
 */
#define PCIE_ROOT_ERR_STATUS_OFF_ERR_FATAL_NON_FATAL_RX(x) (((uint32_t)(((uint32_t)(x)) << PCIE_ROOT_ERR_STATUS_OFF_ERR_FATAL_NON_FATAL_RX_SHIFT)) & PCIE_ROOT_ERR_STATUS_OFF_ERR_FATAL_NON_FATAL_RX_MASK)

#define PCIE_ROOT_ERR_STATUS_OFF_MUL_ERR_FATAL_NON_FATAL_RX_MASK (0x8U)
#define PCIE_ROOT_ERR_STATUS_OFF_MUL_ERR_FATAL_NON_FATAL_RX_SHIFT (3U)
/*! MUL_ERR_FATAL_NON_FATAL_RX - Multiple Fatal or Non-Fatal Errors Received. For a description of
 *    this standard PCIe register field, see the PCI Express Specification.
 */
#define PCIE_ROOT_ERR_STATUS_OFF_MUL_ERR_FATAL_NON_FATAL_RX(x) (((uint32_t)(((uint32_t)(x)) << PCIE_ROOT_ERR_STATUS_OFF_MUL_ERR_FATAL_NON_FATAL_RX_SHIFT)) & PCIE_ROOT_ERR_STATUS_OFF_MUL_ERR_FATAL_NON_FATAL_RX_MASK)

#define PCIE_ROOT_ERR_STATUS_OFF_FIRST_UNCORR_FATAL_MASK (0x10U)
#define PCIE_ROOT_ERR_STATUS_OFF_FIRST_UNCORR_FATAL_SHIFT (4U)
/*! FIRST_UNCORR_FATAL - First Uncorrectable Error is Fatal. For a description of this standard PCIe
 *    register field, see the PCI Express Specification.
 */
#define PCIE_ROOT_ERR_STATUS_OFF_FIRST_UNCORR_FATAL(x) (((uint32_t)(((uint32_t)(x)) << PCIE_ROOT_ERR_STATUS_OFF_FIRST_UNCORR_FATAL_SHIFT)) & PCIE_ROOT_ERR_STATUS_OFF_FIRST_UNCORR_FATAL_MASK)

#define PCIE_ROOT_ERR_STATUS_OFF_NON_FATAL_ERR_MSG_RX_MASK (0x20U)
#define PCIE_ROOT_ERR_STATUS_OFF_NON_FATAL_ERR_MSG_RX_SHIFT (5U)
/*! NON_FATAL_ERR_MSG_RX - One or more Non-Fatal Error Messages Received. For a description of this
 *    standard PCIe register field, see the PCI Express Specification.
 */
#define PCIE_ROOT_ERR_STATUS_OFF_NON_FATAL_ERR_MSG_RX(x) (((uint32_t)(((uint32_t)(x)) << PCIE_ROOT_ERR_STATUS_OFF_NON_FATAL_ERR_MSG_RX_SHIFT)) & PCIE_ROOT_ERR_STATUS_OFF_NON_FATAL_ERR_MSG_RX_MASK)

#define PCIE_ROOT_ERR_STATUS_OFF_FATAL_ERR_MSG_RX_MASK (0x40U)
#define PCIE_ROOT_ERR_STATUS_OFF_FATAL_ERR_MSG_RX_SHIFT (6U)
/*! FATAL_ERR_MSG_RX - One or more Fatal Error Messages Received. For a description of this standard
 *    PCIe register field, see the PCI Express Specification.
 */
#define PCIE_ROOT_ERR_STATUS_OFF_FATAL_ERR_MSG_RX(x) (((uint32_t)(((uint32_t)(x)) << PCIE_ROOT_ERR_STATUS_OFF_FATAL_ERR_MSG_RX_SHIFT)) & PCIE_ROOT_ERR_STATUS_OFF_FATAL_ERR_MSG_RX_MASK)

#define PCIE_ROOT_ERR_STATUS_OFF_RSVDP_7_MASK    (0x7FFFF80U)
#define PCIE_ROOT_ERR_STATUS_OFF_RSVDP_7_SHIFT   (7U)
/*! RSVDP_7 - Reserved for future use. */
#define PCIE_ROOT_ERR_STATUS_OFF_RSVDP_7(x)      (((uint32_t)(((uint32_t)(x)) << PCIE_ROOT_ERR_STATUS_OFF_RSVDP_7_SHIFT)) & PCIE_ROOT_ERR_STATUS_OFF_RSVDP_7_MASK)

#define PCIE_ROOT_ERR_STATUS_OFF_ADV_ERR_INT_MSG_NUM_MASK (0xF8000000U)
#define PCIE_ROOT_ERR_STATUS_OFF_ADV_ERR_INT_MSG_NUM_SHIFT (27U)
/*! ADV_ERR_INT_MSG_NUM - Advanced Error Interrupt Message Number. For a description of this
 *    standard PCIe register field, see the PCI Express Specification. Note: The access attributes of this
 *    field are as follows: - Dbi: if (DBI_RO_WR_EN == 1) then R/W(sticky) else R(sticky) Note: This
 *    register field is sticky.
 */
#define PCIE_ROOT_ERR_STATUS_OFF_ADV_ERR_INT_MSG_NUM(x) (((uint32_t)(((uint32_t)(x)) << PCIE_ROOT_ERR_STATUS_OFF_ADV_ERR_INT_MSG_NUM_SHIFT)) & PCIE_ROOT_ERR_STATUS_OFF_ADV_ERR_INT_MSG_NUM_MASK)
/*! @} */

/*! @name ERR_SRC_ID_OFF - Error Source Identification Register. */
/*! @{ */

#define PCIE_ERR_SRC_ID_OFF_ERR_COR_SOURCE_ID_MASK (0xFFFFU)
#define PCIE_ERR_SRC_ID_OFF_ERR_COR_SOURCE_ID_SHIFT (0U)
/*! ERR_COR_SOURCE_ID - Source of Correctable Error. For a description of this standard PCIe
 *    register field, see the PCI Express Specification. Note: This register field is sticky.
 */
#define PCIE_ERR_SRC_ID_OFF_ERR_COR_SOURCE_ID(x) (((uint32_t)(((uint32_t)(x)) << PCIE_ERR_SRC_ID_OFF_ERR_COR_SOURCE_ID_SHIFT)) & PCIE_ERR_SRC_ID_OFF_ERR_COR_SOURCE_ID_MASK)

#define PCIE_ERR_SRC_ID_OFF_ERR_FATAL_NON_FATAL_SOURCE_ID_MASK (0xFFFF0000U)
#define PCIE_ERR_SRC_ID_OFF_ERR_FATAL_NON_FATAL_SOURCE_ID_SHIFT (16U)
/*! ERR_FATAL_NON_FATAL_SOURCE_ID - Source of Fatal/Non-Fatal Error. For a description of this
 *    standard PCIe register field, see the PCI Express Specification. Note: This register field is
 *    sticky.
 */
#define PCIE_ERR_SRC_ID_OFF_ERR_FATAL_NON_FATAL_SOURCE_ID(x) (((uint32_t)(((uint32_t)(x)) << PCIE_ERR_SRC_ID_OFF_ERR_FATAL_NON_FATAL_SOURCE_ID_SHIFT)) & PCIE_ERR_SRC_ID_OFF_ERR_FATAL_NON_FATAL_SOURCE_ID_MASK)
/*! @} */

/*! @name TLP_PREFIX_LOG_1_OFF - TLP Prefix Log Register 1. */
/*! @{ */

#define PCIE_TLP_PREFIX_LOG_1_OFF_CFG_TLP_PFX_LOG_1_FIRST_BYTE_MASK (0xFFU)
#define PCIE_TLP_PREFIX_LOG_1_OFF_CFG_TLP_PFX_LOG_1_FIRST_BYTE_SHIFT (0U)
/*! CFG_TLP_PFX_LOG_1_FIRST_BYTE - Byte 0 of Error TLP Prefix Log 1. For a description of this
 *    standard PCIe register field, see the PCI Express Specification. Note: This register field is
 *    sticky.
 */
#define PCIE_TLP_PREFIX_LOG_1_OFF_CFG_TLP_PFX_LOG_1_FIRST_BYTE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TLP_PREFIX_LOG_1_OFF_CFG_TLP_PFX_LOG_1_FIRST_BYTE_SHIFT)) & PCIE_TLP_PREFIX_LOG_1_OFF_CFG_TLP_PFX_LOG_1_FIRST_BYTE_MASK)

#define PCIE_TLP_PREFIX_LOG_1_OFF_CFG_TLP_PFX_LOG_1_SECOND_BYTE_MASK (0xFF00U)
#define PCIE_TLP_PREFIX_LOG_1_OFF_CFG_TLP_PFX_LOG_1_SECOND_BYTE_SHIFT (8U)
/*! CFG_TLP_PFX_LOG_1_SECOND_BYTE - Byte 1 of Error TLP Prefix Log 1. For a description of this
 *    standard PCIe register field, see the PCI Express Specification. Note: This register field is
 *    sticky.
 */
#define PCIE_TLP_PREFIX_LOG_1_OFF_CFG_TLP_PFX_LOG_1_SECOND_BYTE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TLP_PREFIX_LOG_1_OFF_CFG_TLP_PFX_LOG_1_SECOND_BYTE_SHIFT)) & PCIE_TLP_PREFIX_LOG_1_OFF_CFG_TLP_PFX_LOG_1_SECOND_BYTE_MASK)

#define PCIE_TLP_PREFIX_LOG_1_OFF_CFG_TLP_PFX_LOG_1_THIRD_BYTE_MASK (0xFF0000U)
#define PCIE_TLP_PREFIX_LOG_1_OFF_CFG_TLP_PFX_LOG_1_THIRD_BYTE_SHIFT (16U)
/*! CFG_TLP_PFX_LOG_1_THIRD_BYTE - Byte 2 of Error TLP Prefix Log 1. For a description of this
 *    standard PCIe register field, see the PCI Express Specification. Note: This register field is
 *    sticky.
 */
#define PCIE_TLP_PREFIX_LOG_1_OFF_CFG_TLP_PFX_LOG_1_THIRD_BYTE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TLP_PREFIX_LOG_1_OFF_CFG_TLP_PFX_LOG_1_THIRD_BYTE_SHIFT)) & PCIE_TLP_PREFIX_LOG_1_OFF_CFG_TLP_PFX_LOG_1_THIRD_BYTE_MASK)

#define PCIE_TLP_PREFIX_LOG_1_OFF_CFG_TLP_PFX_LOG_1_FOURTH_BYTE_MASK (0xFF000000U)
#define PCIE_TLP_PREFIX_LOG_1_OFF_CFG_TLP_PFX_LOG_1_FOURTH_BYTE_SHIFT (24U)
/*! CFG_TLP_PFX_LOG_1_FOURTH_BYTE - Byte 3 of Error TLP Prefix Log 1. For a description of this
 *    standard PCIe register field, see the PCI Express Specification. Note: This register field is
 *    sticky.
 */
#define PCIE_TLP_PREFIX_LOG_1_OFF_CFG_TLP_PFX_LOG_1_FOURTH_BYTE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TLP_PREFIX_LOG_1_OFF_CFG_TLP_PFX_LOG_1_FOURTH_BYTE_SHIFT)) & PCIE_TLP_PREFIX_LOG_1_OFF_CFG_TLP_PFX_LOG_1_FOURTH_BYTE_MASK)
/*! @} */

/*! @name TLP_PREFIX_LOG_2_OFF - TLP Prefix Log Register 2. */
/*! @{ */

#define PCIE_TLP_PREFIX_LOG_2_OFF_CFG_TLP_PFX_LOG_2_FIRST_BYTE_MASK (0xFFU)
#define PCIE_TLP_PREFIX_LOG_2_OFF_CFG_TLP_PFX_LOG_2_FIRST_BYTE_SHIFT (0U)
/*! CFG_TLP_PFX_LOG_2_FIRST_BYTE - Byte 0 Error TLP Prefix Log 2. For a description of this standard
 *    PCIe register field, see the PCI Express Specification. Note: This register field is sticky.
 */
#define PCIE_TLP_PREFIX_LOG_2_OFF_CFG_TLP_PFX_LOG_2_FIRST_BYTE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TLP_PREFIX_LOG_2_OFF_CFG_TLP_PFX_LOG_2_FIRST_BYTE_SHIFT)) & PCIE_TLP_PREFIX_LOG_2_OFF_CFG_TLP_PFX_LOG_2_FIRST_BYTE_MASK)

#define PCIE_TLP_PREFIX_LOG_2_OFF_CFG_TLP_PFX_LOG_2_SECOND_BYTE_MASK (0xFF00U)
#define PCIE_TLP_PREFIX_LOG_2_OFF_CFG_TLP_PFX_LOG_2_SECOND_BYTE_SHIFT (8U)
/*! CFG_TLP_PFX_LOG_2_SECOND_BYTE - Byte 1 Error TLP Prefix Log 2. For a description of this
 *    standard PCIe register field, see the PCI Express Specification. Note: This register field is sticky.
 */
#define PCIE_TLP_PREFIX_LOG_2_OFF_CFG_TLP_PFX_LOG_2_SECOND_BYTE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TLP_PREFIX_LOG_2_OFF_CFG_TLP_PFX_LOG_2_SECOND_BYTE_SHIFT)) & PCIE_TLP_PREFIX_LOG_2_OFF_CFG_TLP_PFX_LOG_2_SECOND_BYTE_MASK)

#define PCIE_TLP_PREFIX_LOG_2_OFF_CFG_TLP_PFX_LOG_2_THIRD_BYTE_MASK (0xFF0000U)
#define PCIE_TLP_PREFIX_LOG_2_OFF_CFG_TLP_PFX_LOG_2_THIRD_BYTE_SHIFT (16U)
/*! CFG_TLP_PFX_LOG_2_THIRD_BYTE - Byte 2 Error TLP Prefix Log 2. For a description of this standard
 *    PCIe register field, see the PCI Express Specification. Note: This register field is sticky.
 */
#define PCIE_TLP_PREFIX_LOG_2_OFF_CFG_TLP_PFX_LOG_2_THIRD_BYTE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TLP_PREFIX_LOG_2_OFF_CFG_TLP_PFX_LOG_2_THIRD_BYTE_SHIFT)) & PCIE_TLP_PREFIX_LOG_2_OFF_CFG_TLP_PFX_LOG_2_THIRD_BYTE_MASK)

#define PCIE_TLP_PREFIX_LOG_2_OFF_CFG_TLP_PFX_LOG_2_FOURTH_BYTE_MASK (0xFF000000U)
#define PCIE_TLP_PREFIX_LOG_2_OFF_CFG_TLP_PFX_LOG_2_FOURTH_BYTE_SHIFT (24U)
/*! CFG_TLP_PFX_LOG_2_FOURTH_BYTE - Byte 3 Error TLP Prefix Log 2. For a description of this
 *    standard PCIe register field, see the PCI Express Specification. Note: This register field is sticky.
 */
#define PCIE_TLP_PREFIX_LOG_2_OFF_CFG_TLP_PFX_LOG_2_FOURTH_BYTE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TLP_PREFIX_LOG_2_OFF_CFG_TLP_PFX_LOG_2_FOURTH_BYTE_SHIFT)) & PCIE_TLP_PREFIX_LOG_2_OFF_CFG_TLP_PFX_LOG_2_FOURTH_BYTE_MASK)
/*! @} */

/*! @name TLP_PREFIX_LOG_3_OFF - TLP Prefix Log Register 3. */
/*! @{ */

#define PCIE_TLP_PREFIX_LOG_3_OFF_CFG_TLP_PFX_LOG_3_FIRST_BYTE_MASK (0xFFU)
#define PCIE_TLP_PREFIX_LOG_3_OFF_CFG_TLP_PFX_LOG_3_FIRST_BYTE_SHIFT (0U)
/*! CFG_TLP_PFX_LOG_3_FIRST_BYTE - Byte 0 Error TLP Prefix Log 3. For a description of this standard
 *    PCIe register field, see the PCI Express Specification. Note: This register field is sticky.
 */
#define PCIE_TLP_PREFIX_LOG_3_OFF_CFG_TLP_PFX_LOG_3_FIRST_BYTE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TLP_PREFIX_LOG_3_OFF_CFG_TLP_PFX_LOG_3_FIRST_BYTE_SHIFT)) & PCIE_TLP_PREFIX_LOG_3_OFF_CFG_TLP_PFX_LOG_3_FIRST_BYTE_MASK)

#define PCIE_TLP_PREFIX_LOG_3_OFF_CFG_TLP_PFX_LOG_3_SECOND_BYTE_MASK (0xFF00U)
#define PCIE_TLP_PREFIX_LOG_3_OFF_CFG_TLP_PFX_LOG_3_SECOND_BYTE_SHIFT (8U)
/*! CFG_TLP_PFX_LOG_3_SECOND_BYTE - Byte 1 Error TLP Prefix Log 3. For a description of this
 *    standard PCIe register field, see the PCI Express Specification. Note: This register field is sticky.
 */
#define PCIE_TLP_PREFIX_LOG_3_OFF_CFG_TLP_PFX_LOG_3_SECOND_BYTE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TLP_PREFIX_LOG_3_OFF_CFG_TLP_PFX_LOG_3_SECOND_BYTE_SHIFT)) & PCIE_TLP_PREFIX_LOG_3_OFF_CFG_TLP_PFX_LOG_3_SECOND_BYTE_MASK)

#define PCIE_TLP_PREFIX_LOG_3_OFF_CFG_TLP_PFX_LOG_3_THIRD_BYTE_MASK (0xFF0000U)
#define PCIE_TLP_PREFIX_LOG_3_OFF_CFG_TLP_PFX_LOG_3_THIRD_BYTE_SHIFT (16U)
/*! CFG_TLP_PFX_LOG_3_THIRD_BYTE - Byte 2 Error TLP Prefix Log 3. For a description of this standard
 *    PCIe register field, see the PCI Express Specification. Note: This register field is sticky.
 */
#define PCIE_TLP_PREFIX_LOG_3_OFF_CFG_TLP_PFX_LOG_3_THIRD_BYTE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TLP_PREFIX_LOG_3_OFF_CFG_TLP_PFX_LOG_3_THIRD_BYTE_SHIFT)) & PCIE_TLP_PREFIX_LOG_3_OFF_CFG_TLP_PFX_LOG_3_THIRD_BYTE_MASK)

#define PCIE_TLP_PREFIX_LOG_3_OFF_CFG_TLP_PFX_LOG_3_FOURTH_BYTE_MASK (0xFF000000U)
#define PCIE_TLP_PREFIX_LOG_3_OFF_CFG_TLP_PFX_LOG_3_FOURTH_BYTE_SHIFT (24U)
/*! CFG_TLP_PFX_LOG_3_FOURTH_BYTE - Byte 3 Error TLP Prefix Log 3. For a description of this
 *    standard PCIe register field, see the PCI Express Specification. Note: This register field is sticky.
 */
#define PCIE_TLP_PREFIX_LOG_3_OFF_CFG_TLP_PFX_LOG_3_FOURTH_BYTE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TLP_PREFIX_LOG_3_OFF_CFG_TLP_PFX_LOG_3_FOURTH_BYTE_SHIFT)) & PCIE_TLP_PREFIX_LOG_3_OFF_CFG_TLP_PFX_LOG_3_FOURTH_BYTE_MASK)
/*! @} */

/*! @name TLP_PREFIX_LOG_4_OFF - TLP Prefix Log Register 4. */
/*! @{ */

#define PCIE_TLP_PREFIX_LOG_4_OFF_CFG_TLP_PFX_LOG_4_FIRST_BYTE_MASK (0xFFU)
#define PCIE_TLP_PREFIX_LOG_4_OFF_CFG_TLP_PFX_LOG_4_FIRST_BYTE_SHIFT (0U)
/*! CFG_TLP_PFX_LOG_4_FIRST_BYTE - Byte 0 Error TLP Prefix Log 4. For a description of this standard
 *    PCIe register field, see the PCI Express Specification. Note: This register field is sticky.
 */
#define PCIE_TLP_PREFIX_LOG_4_OFF_CFG_TLP_PFX_LOG_4_FIRST_BYTE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TLP_PREFIX_LOG_4_OFF_CFG_TLP_PFX_LOG_4_FIRST_BYTE_SHIFT)) & PCIE_TLP_PREFIX_LOG_4_OFF_CFG_TLP_PFX_LOG_4_FIRST_BYTE_MASK)

#define PCIE_TLP_PREFIX_LOG_4_OFF_CFG_TLP_PFX_LOG_4_SECOND_BYTE_MASK (0xFF00U)
#define PCIE_TLP_PREFIX_LOG_4_OFF_CFG_TLP_PFX_LOG_4_SECOND_BYTE_SHIFT (8U)
/*! CFG_TLP_PFX_LOG_4_SECOND_BYTE - Byte 1 Error TLP Prefix Log 4. For a description of this
 *    standard PCIe register field, see the PCI Express Specification. Note: This register field is sticky.
 */
#define PCIE_TLP_PREFIX_LOG_4_OFF_CFG_TLP_PFX_LOG_4_SECOND_BYTE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TLP_PREFIX_LOG_4_OFF_CFG_TLP_PFX_LOG_4_SECOND_BYTE_SHIFT)) & PCIE_TLP_PREFIX_LOG_4_OFF_CFG_TLP_PFX_LOG_4_SECOND_BYTE_MASK)

#define PCIE_TLP_PREFIX_LOG_4_OFF_CFG_TLP_PFX_LOG_4_THIRD_BYTE_MASK (0xFF0000U)
#define PCIE_TLP_PREFIX_LOG_4_OFF_CFG_TLP_PFX_LOG_4_THIRD_BYTE_SHIFT (16U)
/*! CFG_TLP_PFX_LOG_4_THIRD_BYTE - Byte 2 Error TLP Prefix Log 4. For a description of this standard
 *    PCIe register field, see the PCI Express Specification. Note: This register field is sticky.
 */
#define PCIE_TLP_PREFIX_LOG_4_OFF_CFG_TLP_PFX_LOG_4_THIRD_BYTE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TLP_PREFIX_LOG_4_OFF_CFG_TLP_PFX_LOG_4_THIRD_BYTE_SHIFT)) & PCIE_TLP_PREFIX_LOG_4_OFF_CFG_TLP_PFX_LOG_4_THIRD_BYTE_MASK)

#define PCIE_TLP_PREFIX_LOG_4_OFF_CFG_TLP_PFX_LOG_4_FOURTH_BYTE_MASK (0xFF000000U)
#define PCIE_TLP_PREFIX_LOG_4_OFF_CFG_TLP_PFX_LOG_4_FOURTH_BYTE_SHIFT (24U)
/*! CFG_TLP_PFX_LOG_4_FOURTH_BYTE - Byte 3 Error TLP Prefix Log 4. For a description of this
 *    standard PCIe register field, see the PCI Express Specification. Note: This register field is sticky.
 */
#define PCIE_TLP_PREFIX_LOG_4_OFF_CFG_TLP_PFX_LOG_4_FOURTH_BYTE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TLP_PREFIX_LOG_4_OFF_CFG_TLP_PFX_LOG_4_FOURTH_BYTE_SHIFT)) & PCIE_TLP_PREFIX_LOG_4_OFF_CFG_TLP_PFX_LOG_4_FOURTH_BYTE_MASK)
/*! @} */

/*! @name L1SUB_CAP_HEADER_REG - L1 Substates Extended Capability Header. */
/*! @{ */

#define PCIE_L1SUB_CAP_HEADER_REG_EXTENDED_CAP_ID_MASK (0xFFFFU)
#define PCIE_L1SUB_CAP_HEADER_REG_EXTENDED_CAP_ID_SHIFT (0U)
/*! EXTENDED_CAP_ID - L1SUB Extended Capability ID. For a description of this standard PCIe register
 *    field, see the PCI Express Specification. Note: The access attributes of this field are as
 *    follows: - Dbi: if (DBI_RO_WR_EN == 1) then R/W(sticky) else R(sticky) Note: This register field
 *    is sticky.
 */
#define PCIE_L1SUB_CAP_HEADER_REG_EXTENDED_CAP_ID(x) (((uint32_t)(((uint32_t)(x)) << PCIE_L1SUB_CAP_HEADER_REG_EXTENDED_CAP_ID_SHIFT)) & PCIE_L1SUB_CAP_HEADER_REG_EXTENDED_CAP_ID_MASK)

#define PCIE_L1SUB_CAP_HEADER_REG_CAP_VERSION_MASK (0xF0000U)
#define PCIE_L1SUB_CAP_HEADER_REG_CAP_VERSION_SHIFT (16U)
/*! CAP_VERSION - Capability Version. For a description of this standard PCIe register field, see
 *    the PCI Express Specification. Note: The access attributes of this field are as follows: - Dbi:
 *    if (DBI_RO_WR_EN == 1) then R/W(sticky) else R(sticky) Note: This register field is sticky.
 */
#define PCIE_L1SUB_CAP_HEADER_REG_CAP_VERSION(x) (((uint32_t)(((uint32_t)(x)) << PCIE_L1SUB_CAP_HEADER_REG_CAP_VERSION_SHIFT)) & PCIE_L1SUB_CAP_HEADER_REG_CAP_VERSION_MASK)

#define PCIE_L1SUB_CAP_HEADER_REG_NEXT_OFFSET_MASK (0xFFF00000U)
#define PCIE_L1SUB_CAP_HEADER_REG_NEXT_OFFSET_SHIFT (20U)
/*! NEXT_OFFSET - Next Capability Offset. For a description of this standard PCIe register field,
 *    see the PCI Express Specification. Note: The access attributes of this field are as follows: -
 *    Dbi: if (DBI_RO_WR_EN == 1) then R/W(sticky) else R(sticky) Note: This register field is sticky.
 */
#define PCIE_L1SUB_CAP_HEADER_REG_NEXT_OFFSET(x) (((uint32_t)(((uint32_t)(x)) << PCIE_L1SUB_CAP_HEADER_REG_NEXT_OFFSET_SHIFT)) & PCIE_L1SUB_CAP_HEADER_REG_NEXT_OFFSET_MASK)
/*! @} */

/*! @name L1SUB_CAPABILITY_REG - L1 Substates Capability Register. */
/*! @{ */

#define PCIE_L1SUB_CAPABILITY_REG_L1_2_PCIPM_SUPPORT_MASK (0x1U)
#define PCIE_L1SUB_CAPABILITY_REG_L1_2_PCIPM_SUPPORT_SHIFT (0U)
/*! L1_2_PCIPM_SUPPORT - PCI-PM L12 Supported. For a description of this standard PCIe register
 *    field, see the PCI Express Specification. Note: The access attributes of this field are as
 *    follows: - Dbi: R/W
 */
#define PCIE_L1SUB_CAPABILITY_REG_L1_2_PCIPM_SUPPORT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_L1SUB_CAPABILITY_REG_L1_2_PCIPM_SUPPORT_SHIFT)) & PCIE_L1SUB_CAPABILITY_REG_L1_2_PCIPM_SUPPORT_MASK)

#define PCIE_L1SUB_CAPABILITY_REG_L1_1_PCIPM_SUPPORT_MASK (0x2U)
#define PCIE_L1SUB_CAPABILITY_REG_L1_1_PCIPM_SUPPORT_SHIFT (1U)
/*! L1_1_PCIPM_SUPPORT - PCI-PM L11 Supported. For a description of this standard PCIe register
 *    field, see the PCI Express Specification. Note: The access attributes of this field are as
 *    follows: - Dbi: R/W
 */
#define PCIE_L1SUB_CAPABILITY_REG_L1_1_PCIPM_SUPPORT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_L1SUB_CAPABILITY_REG_L1_1_PCIPM_SUPPORT_SHIFT)) & PCIE_L1SUB_CAPABILITY_REG_L1_1_PCIPM_SUPPORT_MASK)

#define PCIE_L1SUB_CAPABILITY_REG_L1_2_ASPM_SUPPORT_MASK (0x4U)
#define PCIE_L1SUB_CAPABILITY_REG_L1_2_ASPM_SUPPORT_SHIFT (2U)
/*! L1_2_ASPM_SUPPORT - ASPM L12 Supported. For a description of this standard PCIe register field,
 *    see the PCI Express Specification. Note: The access attributes of this field are as follows: -
 *    Dbi: R/W
 */
#define PCIE_L1SUB_CAPABILITY_REG_L1_2_ASPM_SUPPORT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_L1SUB_CAPABILITY_REG_L1_2_ASPM_SUPPORT_SHIFT)) & PCIE_L1SUB_CAPABILITY_REG_L1_2_ASPM_SUPPORT_MASK)

#define PCIE_L1SUB_CAPABILITY_REG_L1_1_ASPM_SUPPORT_MASK (0x8U)
#define PCIE_L1SUB_CAPABILITY_REG_L1_1_ASPM_SUPPORT_SHIFT (3U)
/*! L1_1_ASPM_SUPPORT - ASPM L11 Supported. For a description of this standard PCIe register field,
 *    see the PCI Express Specification. Note: The access attributes of this field are as follows: -
 *    Dbi: R/W
 */
#define PCIE_L1SUB_CAPABILITY_REG_L1_1_ASPM_SUPPORT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_L1SUB_CAPABILITY_REG_L1_1_ASPM_SUPPORT_SHIFT)) & PCIE_L1SUB_CAPABILITY_REG_L1_1_ASPM_SUPPORT_MASK)

#define PCIE_L1SUB_CAPABILITY_REG_L1_PMSUB_SUPPORT_MASK (0x10U)
#define PCIE_L1SUB_CAPABILITY_REG_L1_PMSUB_SUPPORT_SHIFT (4U)
/*! L1_PMSUB_SUPPORT - L1 PM Substates ECN Supported. For a description of this standard PCIe
 *    register field, see the PCI Express Specification. Note: The access attributes of this field are as
 *    follows: - Dbi: R/W
 */
#define PCIE_L1SUB_CAPABILITY_REG_L1_PMSUB_SUPPORT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_L1SUB_CAPABILITY_REG_L1_PMSUB_SUPPORT_SHIFT)) & PCIE_L1SUB_CAPABILITY_REG_L1_PMSUB_SUPPORT_MASK)

#define PCIE_L1SUB_CAPABILITY_REG_RSVDP_5_MASK   (0xE0U)
#define PCIE_L1SUB_CAPABILITY_REG_RSVDP_5_SHIFT  (5U)
/*! RSVDP_5 - Reserved for future use. */
#define PCIE_L1SUB_CAPABILITY_REG_RSVDP_5(x)     (((uint32_t)(((uint32_t)(x)) << PCIE_L1SUB_CAPABILITY_REG_RSVDP_5_SHIFT)) & PCIE_L1SUB_CAPABILITY_REG_RSVDP_5_MASK)

#define PCIE_L1SUB_CAPABILITY_REG_COMM_MODE_SUPPORT_MASK (0xFF00U)
#define PCIE_L1SUB_CAPABILITY_REG_COMM_MODE_SUPPORT_SHIFT (8U)
/*! COMM_MODE_SUPPORT - Port Common Mode Restore Time. For a description of this standard PCIe
 *    register field, see the PCI Express Specification. Note: The access attributes of this field are as
 *    follows: - Dbi: R/W
 */
#define PCIE_L1SUB_CAPABILITY_REG_COMM_MODE_SUPPORT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_L1SUB_CAPABILITY_REG_COMM_MODE_SUPPORT_SHIFT)) & PCIE_L1SUB_CAPABILITY_REG_COMM_MODE_SUPPORT_MASK)

#define PCIE_L1SUB_CAPABILITY_REG_PWR_ON_SCALE_SUPPORT_MASK (0x30000U)
#define PCIE_L1SUB_CAPABILITY_REG_PWR_ON_SCALE_SUPPORT_SHIFT (16U)
/*! PWR_ON_SCALE_SUPPORT - Port T Power On Scale. For a description of this standard PCIe register
 *    field, see the PCI Express Specification. Note: The access attributes of this field are as
 *    follows: - Dbi: R/W
 */
#define PCIE_L1SUB_CAPABILITY_REG_PWR_ON_SCALE_SUPPORT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_L1SUB_CAPABILITY_REG_PWR_ON_SCALE_SUPPORT_SHIFT)) & PCIE_L1SUB_CAPABILITY_REG_PWR_ON_SCALE_SUPPORT_MASK)

#define PCIE_L1SUB_CAPABILITY_REG_RSVDP_18_MASK  (0x40000U)
#define PCIE_L1SUB_CAPABILITY_REG_RSVDP_18_SHIFT (18U)
/*! RSVDP_18 - Reserved for future use. */
#define PCIE_L1SUB_CAPABILITY_REG_RSVDP_18(x)    (((uint32_t)(((uint32_t)(x)) << PCIE_L1SUB_CAPABILITY_REG_RSVDP_18_SHIFT)) & PCIE_L1SUB_CAPABILITY_REG_RSVDP_18_MASK)

#define PCIE_L1SUB_CAPABILITY_REG_PWR_ON_VALUE_SUPPORT_MASK (0xF80000U)
#define PCIE_L1SUB_CAPABILITY_REG_PWR_ON_VALUE_SUPPORT_SHIFT (19U)
/*! PWR_ON_VALUE_SUPPORT - Port T Power On Value. For a description of this standard PCIe register
 *    field, see the PCI Express Specification. Note: The access attributes of this field are as
 *    follows: - Dbi: R/W
 */
#define PCIE_L1SUB_CAPABILITY_REG_PWR_ON_VALUE_SUPPORT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_L1SUB_CAPABILITY_REG_PWR_ON_VALUE_SUPPORT_SHIFT)) & PCIE_L1SUB_CAPABILITY_REG_PWR_ON_VALUE_SUPPORT_MASK)

#define PCIE_L1SUB_CAPABILITY_REG_RSVDP_24_MASK  (0xFF000000U)
#define PCIE_L1SUB_CAPABILITY_REG_RSVDP_24_SHIFT (24U)
/*! RSVDP_24 - Reserved for future use. */
#define PCIE_L1SUB_CAPABILITY_REG_RSVDP_24(x)    (((uint32_t)(((uint32_t)(x)) << PCIE_L1SUB_CAPABILITY_REG_RSVDP_24_SHIFT)) & PCIE_L1SUB_CAPABILITY_REG_RSVDP_24_MASK)
/*! @} */

/*! @name L1SUB_CONTROL1_REG - L1 Substates Control 1 Register. */
/*! @{ */

#define PCIE_L1SUB_CONTROL1_REG_L1_2_PCIPM_EN_MASK (0x1U)
#define PCIE_L1SUB_CONTROL1_REG_L1_2_PCIPM_EN_SHIFT (0U)
/*! L1_2_PCIPM_EN - PCI-PM L12 Enable. For a description of this standard PCIe register field, see the PCI Express Specification. */
#define PCIE_L1SUB_CONTROL1_REG_L1_2_PCIPM_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_L1SUB_CONTROL1_REG_L1_2_PCIPM_EN_SHIFT)) & PCIE_L1SUB_CONTROL1_REG_L1_2_PCIPM_EN_MASK)

#define PCIE_L1SUB_CONTROL1_REG_L1_1_PCIPM_EN_MASK (0x2U)
#define PCIE_L1SUB_CONTROL1_REG_L1_1_PCIPM_EN_SHIFT (1U)
/*! L1_1_PCIPM_EN - PCI-PM L11 Enable. For a description of this standard PCIe register field, see the PCI Express Specification. */
#define PCIE_L1SUB_CONTROL1_REG_L1_1_PCIPM_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_L1SUB_CONTROL1_REG_L1_1_PCIPM_EN_SHIFT)) & PCIE_L1SUB_CONTROL1_REG_L1_1_PCIPM_EN_MASK)

#define PCIE_L1SUB_CONTROL1_REG_L1_2_ASPM_EN_MASK (0x4U)
#define PCIE_L1SUB_CONTROL1_REG_L1_2_ASPM_EN_SHIFT (2U)
/*! L1_2_ASPM_EN - ASPM L12 Enable. For a description of this standard PCIe register field, see the PCI Express Specification. */
#define PCIE_L1SUB_CONTROL1_REG_L1_2_ASPM_EN(x)  (((uint32_t)(((uint32_t)(x)) << PCIE_L1SUB_CONTROL1_REG_L1_2_ASPM_EN_SHIFT)) & PCIE_L1SUB_CONTROL1_REG_L1_2_ASPM_EN_MASK)

#define PCIE_L1SUB_CONTROL1_REG_L1_1_ASPM_EN_MASK (0x8U)
#define PCIE_L1SUB_CONTROL1_REG_L1_1_ASPM_EN_SHIFT (3U)
/*! L1_1_ASPM_EN - ASPM L11 Enable. For a description of this standard PCIe register field, see the PCI Express Specification. */
#define PCIE_L1SUB_CONTROL1_REG_L1_1_ASPM_EN(x)  (((uint32_t)(((uint32_t)(x)) << PCIE_L1SUB_CONTROL1_REG_L1_1_ASPM_EN_SHIFT)) & PCIE_L1SUB_CONTROL1_REG_L1_1_ASPM_EN_MASK)

#define PCIE_L1SUB_CONTROL1_REG_RSVDP_4_MASK     (0xF0U)
#define PCIE_L1SUB_CONTROL1_REG_RSVDP_4_SHIFT    (4U)
/*! RSVDP_4 - Reserved for future use. */
#define PCIE_L1SUB_CONTROL1_REG_RSVDP_4(x)       (((uint32_t)(((uint32_t)(x)) << PCIE_L1SUB_CONTROL1_REG_RSVDP_4_SHIFT)) & PCIE_L1SUB_CONTROL1_REG_RSVDP_4_MASK)

#define PCIE_L1SUB_CONTROL1_REG_T_COMMON_MODE_MASK (0xFF00U)
#define PCIE_L1SUB_CONTROL1_REG_T_COMMON_MODE_SHIFT (8U)
/*! T_COMMON_MODE - Common Mode Restore Time. For a description of this standard PCIe register
 *    field, see the PCI Express Specification. Note: The access attributes of this field are as follows:
 *    - Dbi: R/W
 */
#define PCIE_L1SUB_CONTROL1_REG_T_COMMON_MODE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_L1SUB_CONTROL1_REG_T_COMMON_MODE_SHIFT)) & PCIE_L1SUB_CONTROL1_REG_T_COMMON_MODE_MASK)

#define PCIE_L1SUB_CONTROL1_REG_L1_2_TH_VAL_MASK (0x3FF0000U)
#define PCIE_L1SUB_CONTROL1_REG_L1_2_TH_VAL_SHIFT (16U)
/*! L1_2_TH_VAL - LTR L12 Threshold Value. For a description of this standard PCIe register field, see the PCI Express Specification. */
#define PCIE_L1SUB_CONTROL1_REG_L1_2_TH_VAL(x)   (((uint32_t)(((uint32_t)(x)) << PCIE_L1SUB_CONTROL1_REG_L1_2_TH_VAL_SHIFT)) & PCIE_L1SUB_CONTROL1_REG_L1_2_TH_VAL_MASK)

#define PCIE_L1SUB_CONTROL1_REG_RSVDP_26_MASK    (0x1C000000U)
#define PCIE_L1SUB_CONTROL1_REG_RSVDP_26_SHIFT   (26U)
/*! RSVDP_26 - Reserved for future use. */
#define PCIE_L1SUB_CONTROL1_REG_RSVDP_26(x)      (((uint32_t)(((uint32_t)(x)) << PCIE_L1SUB_CONTROL1_REG_RSVDP_26_SHIFT)) & PCIE_L1SUB_CONTROL1_REG_RSVDP_26_MASK)

#define PCIE_L1SUB_CONTROL1_REG_L1_2_TH_SCA_MASK (0xE0000000U)
#define PCIE_L1SUB_CONTROL1_REG_L1_2_TH_SCA_SHIFT (29U)
/*! L1_2_TH_SCA - LTR L12 Threshold Scale. For a description of this standard PCIe register field, see the PCI Express Specification. */
#define PCIE_L1SUB_CONTROL1_REG_L1_2_TH_SCA(x)   (((uint32_t)(((uint32_t)(x)) << PCIE_L1SUB_CONTROL1_REG_L1_2_TH_SCA_SHIFT)) & PCIE_L1SUB_CONTROL1_REG_L1_2_TH_SCA_MASK)
/*! @} */

/*! @name L1SUB_CONTROL2_REG - L1 Substates Control 2 Register. */
/*! @{ */

#define PCIE_L1SUB_CONTROL2_REG_T_POWER_ON_SCALE_MASK (0x3U)
#define PCIE_L1SUB_CONTROL2_REG_T_POWER_ON_SCALE_SHIFT (0U)
/*! T_POWER_ON_SCALE - T Power On Scale. For a description of this standard PCIe register field, see the PCI Express Specification. */
#define PCIE_L1SUB_CONTROL2_REG_T_POWER_ON_SCALE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_L1SUB_CONTROL2_REG_T_POWER_ON_SCALE_SHIFT)) & PCIE_L1SUB_CONTROL2_REG_T_POWER_ON_SCALE_MASK)

#define PCIE_L1SUB_CONTROL2_REG_RSVDP_2_MASK     (0x4U)
#define PCIE_L1SUB_CONTROL2_REG_RSVDP_2_SHIFT    (2U)
/*! RSVDP_2 - Reserved for future use. */
#define PCIE_L1SUB_CONTROL2_REG_RSVDP_2(x)       (((uint32_t)(((uint32_t)(x)) << PCIE_L1SUB_CONTROL2_REG_RSVDP_2_SHIFT)) & PCIE_L1SUB_CONTROL2_REG_RSVDP_2_MASK)

#define PCIE_L1SUB_CONTROL2_REG_T_POWER_ON_VALUE_MASK (0xF8U)
#define PCIE_L1SUB_CONTROL2_REG_T_POWER_ON_VALUE_SHIFT (3U)
/*! T_POWER_ON_VALUE - T Power On Value. For a description of this standard PCIe register field, see the PCI Express Specification. */
#define PCIE_L1SUB_CONTROL2_REG_T_POWER_ON_VALUE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_L1SUB_CONTROL2_REG_T_POWER_ON_VALUE_SHIFT)) & PCIE_L1SUB_CONTROL2_REG_T_POWER_ON_VALUE_MASK)

#define PCIE_L1SUB_CONTROL2_REG_RSVDP_8_MASK     (0xFFFFFF00U)
#define PCIE_L1SUB_CONTROL2_REG_RSVDP_8_SHIFT    (8U)
/*! RSVDP_8 - Reserved for future use. */
#define PCIE_L1SUB_CONTROL2_REG_RSVDP_8(x)       (((uint32_t)(((uint32_t)(x)) << PCIE_L1SUB_CONTROL2_REG_RSVDP_8_SHIFT)) & PCIE_L1SUB_CONTROL2_REG_RSVDP_8_MASK)
/*! @} */

/*! @name ACK_LATENCY_TIMER_OFF - Ack Latency Timer and Replay Timer Register. */
/*! @{ */

#define PCIE_ACK_LATENCY_TIMER_OFF_ROUND_TRIP_LATENCY_TIME_LIMIT_MASK (0xFFFFU)
#define PCIE_ACK_LATENCY_TIMER_OFF_ROUND_TRIP_LATENCY_TIME_LIMIT_SHIFT (0U)
/*! ROUND_TRIP_LATENCY_TIME_LIMIT - Ack Latency Timer Limit. The Ack latency timer expires when it
 *    reaches this limit. For more details, see "Ack Scheduling". You can modify the effective timer
 *    limit with the TIMER_MOD_ACK_NAK field of the TIMER_CTRL_MAX_FUNC_NUM_OFF register. After
 *    reset, the controller updates the default according to the Negotiated Link Width,
 *    Max_Payload_Size, and speed. The value is determined from Tables 3-7, 3-8, and 3-9 of the PCIe 3.0
 *    specification. The limit must reflect the round trip latency from requester to completer. If there is a
 *    change in the payload size or link width, the controller will override any value that you have
 *    written to this register field, and reset the field back to the specification-defined value.
 *    It will not change the value in the TIMER_MOD_ACK_NAK field of the TIMER_CTRL_MAX_FUNC_NUM_OFF
 *    register.
 */
#define PCIE_ACK_LATENCY_TIMER_OFF_ROUND_TRIP_LATENCY_TIME_LIMIT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_ACK_LATENCY_TIMER_OFF_ROUND_TRIP_LATENCY_TIME_LIMIT_SHIFT)) & PCIE_ACK_LATENCY_TIMER_OFF_ROUND_TRIP_LATENCY_TIME_LIMIT_MASK)

#define PCIE_ACK_LATENCY_TIMER_OFF_REPLAY_TIME_LIMIT_MASK (0xFFFF0000U)
#define PCIE_ACK_LATENCY_TIMER_OFF_REPLAY_TIME_LIMIT_SHIFT (16U)
/*! REPLAY_TIME_LIMIT - Replay Timer Limit. The replay timer expires when it reaches this limit. The
 *    controller initiates a replay upon reception of a NAK or when the replay timer expires. For
 *    more details, see "Transmit Replay". You can modify the effective timer limit with the
 *    TIMER_MOD_REPLAY_TIMER field of the TIMER_CTRL_MAX_FUNC_NUM_OFF register. After reset, the controller
 *    updates the default according to the Negotiated Link Width, Max_Payload_Size, and speed. The
 *    value is determined from Tables 3-4, 3-5, and 3-6 of the PCIe 3.0 specification. If there is a
 *    change in the payload size or link speed, the controller will override any value that you have
 *    written to this register field, and reset the field back to the specification-defined value.
 *    It will not change the value in the TIMER_MOD_REPLAY_TIMER field of the
 *    TIMER_CTRL_MAX_FUNC_NUM_OFF register.
 */
#define PCIE_ACK_LATENCY_TIMER_OFF_REPLAY_TIME_LIMIT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_ACK_LATENCY_TIMER_OFF_REPLAY_TIME_LIMIT_SHIFT)) & PCIE_ACK_LATENCY_TIMER_OFF_REPLAY_TIME_LIMIT_MASK)
/*! @} */

/*! @name VENDOR_SPEC_DLLP_OFF - Vendor Specific DLLP Register. */
/*! @{ */

#define PCIE_VENDOR_SPEC_DLLP_OFF_VENDOR_SPEC_DLLP_MASK (0xFFFFFFFFU)
#define PCIE_VENDOR_SPEC_DLLP_OFF_VENDOR_SPEC_DLLP_SHIFT (0U)
/*! VENDOR_SPEC_DLLP - Vendor Specific DLLP Register. Used to send a specific PCI Express DLLP. Your
 *    application writes the 8-bit DLLP Type and 24-bits of Payload data into this register, then
 *    sets the field VENDOR_SPECIFIC_DLLP_REQ of PORT_LINK_CTRL_OFF to send the DLLP. - [7:0] = Type
 *    - [31:8] = Payload (24 bits) The dllp type is in bits [7:0] while the remainder is the vendor
 *    defined payload. Note: This register field is sticky.
 */
#define PCIE_VENDOR_SPEC_DLLP_OFF_VENDOR_SPEC_DLLP(x) (((uint32_t)(((uint32_t)(x)) << PCIE_VENDOR_SPEC_DLLP_OFF_VENDOR_SPEC_DLLP_SHIFT)) & PCIE_VENDOR_SPEC_DLLP_OFF_VENDOR_SPEC_DLLP_MASK)
/*! @} */

/*! @name PORT_FORCE_OFF - Port Force Link Register. */
/*! @{ */

#define PCIE_PORT_FORCE_OFF_LINK_NUM_MASK        (0xFFU)
#define PCIE_PORT_FORCE_OFF_LINK_NUM_SHIFT       (0U)
/*! LINK_NUM - Link Number. Not used for endpoint. Not used for M-PCIe. Note: This register field is sticky. */
#define PCIE_PORT_FORCE_OFF_LINK_NUM(x)          (((uint32_t)(((uint32_t)(x)) << PCIE_PORT_FORCE_OFF_LINK_NUM_SHIFT)) & PCIE_PORT_FORCE_OFF_LINK_NUM_MASK)

#define PCIE_PORT_FORCE_OFF_FORCED_LTSSM_MASK    (0xF00U)
#define PCIE_PORT_FORCE_OFF_FORCED_LTSSM_SHIFT   (8U)
/*! FORCED_LTSSM - Forced Link Command. The link command that the controller is forced to transmit
 *    when you set FORCE_EN bit (Force Link). Link command encoding is defined by the ltssm_cmd
 *    variable in workspace/src/Layer1/smlh_ltssm.v. Note: This register field is sticky.
 */
#define PCIE_PORT_FORCE_OFF_FORCED_LTSSM(x)      (((uint32_t)(((uint32_t)(x)) << PCIE_PORT_FORCE_OFF_FORCED_LTSSM_SHIFT)) & PCIE_PORT_FORCE_OFF_FORCED_LTSSM_MASK)

#define PCIE_PORT_FORCE_OFF_RSVDP_12_MASK        (0x7000U)
#define PCIE_PORT_FORCE_OFF_RSVDP_12_SHIFT       (12U)
/*! RSVDP_12 - Reserved for future use. */
#define PCIE_PORT_FORCE_OFF_RSVDP_12(x)          (((uint32_t)(((uint32_t)(x)) << PCIE_PORT_FORCE_OFF_RSVDP_12_SHIFT)) & PCIE_PORT_FORCE_OFF_RSVDP_12_MASK)

#define PCIE_PORT_FORCE_OFF_FORCE_EN_MASK        (0x8000U)
#define PCIE_PORT_FORCE_OFF_FORCE_EN_SHIFT       (15U)
/*! FORCE_EN - Force Link. The controller supports a testing and debug capability to allow your
 *    software to force the LTSSM state machine into a specific state, and to force the controller to
 *    transmit a specific Link Command. Asserting this bit triggers the following actions: - Forces
 *    the LTSSM to the state specified by the Forced LTSSM State field. - Forces the controller to
 *    transmit the command specified by the Forced Link Command field. This is a self-clearing register
 *    field. Reading from this register field always returns a "0".
 */
#define PCIE_PORT_FORCE_OFF_FORCE_EN(x)          (((uint32_t)(((uint32_t)(x)) << PCIE_PORT_FORCE_OFF_FORCE_EN_SHIFT)) & PCIE_PORT_FORCE_OFF_FORCE_EN_MASK)

#define PCIE_PORT_FORCE_OFF_LINK_STATE_MASK      (0x3F0000U)
#define PCIE_PORT_FORCE_OFF_LINK_STATE_SHIFT     (16U)
/*! LINK_STATE - Forced LTSSM State. The LTSSM state that the controller is forced to when you set
 *    the FORCE_EN bit (Force Link). LTSSM state encoding is defined by the lts_state variable in
 *    workspace/src/Layer1/smlh_ltssm.v. Note: This register field is sticky.
 */
#define PCIE_PORT_FORCE_OFF_LINK_STATE(x)        (((uint32_t)(((uint32_t)(x)) << PCIE_PORT_FORCE_OFF_LINK_STATE_SHIFT)) & PCIE_PORT_FORCE_OFF_LINK_STATE_MASK)

#define PCIE_PORT_FORCE_OFF_RSVDP_22_MASK        (0x400000U)
#define PCIE_PORT_FORCE_OFF_RSVDP_22_SHIFT       (22U)
/*! RSVDP_22 - Reserved for future use. */
#define PCIE_PORT_FORCE_OFF_RSVDP_22(x)          (((uint32_t)(((uint32_t)(x)) << PCIE_PORT_FORCE_OFF_RSVDP_22_SHIFT)) & PCIE_PORT_FORCE_OFF_RSVDP_22_MASK)

#define PCIE_PORT_FORCE_OFF_DO_DESKEW_FOR_SRIS_MASK (0x800000U)
#define PCIE_PORT_FORCE_OFF_DO_DESKEW_FOR_SRIS_SHIFT (23U)
/*! DO_DESKEW_FOR_SRIS - Use the transitions from TS2 to Logical Idle Symbol, SKP OS to Logical Idle
 *    Symbol, and FTS Sequence to SKP OS to do deskew for SRIS instead of using received SKP OS if
 *    DO_DESKEW_FOR_SRIS is set to 1. Note: This register field is sticky.
 */
#define PCIE_PORT_FORCE_OFF_DO_DESKEW_FOR_SRIS(x) (((uint32_t)(((uint32_t)(x)) << PCIE_PORT_FORCE_OFF_DO_DESKEW_FOR_SRIS_SHIFT)) & PCIE_PORT_FORCE_OFF_DO_DESKEW_FOR_SRIS_MASK)

#define PCIE_PORT_FORCE_OFF_RSVDP_24_MASK        (0xFF000000U)
#define PCIE_PORT_FORCE_OFF_RSVDP_24_SHIFT       (24U)
/*! RSVDP_24 - Reserved for future use. */
#define PCIE_PORT_FORCE_OFF_RSVDP_24(x)          (((uint32_t)(((uint32_t)(x)) << PCIE_PORT_FORCE_OFF_RSVDP_24_SHIFT)) & PCIE_PORT_FORCE_OFF_RSVDP_24_MASK)
/*! @} */

/*! @name ACK_F_ASPM_CTRL_OFF - Ack Frequency and L0-L1 ASPM Control Register. */
/*! @{ */

#define PCIE_ACK_F_ASPM_CTRL_OFF_ACK_FREQ_MASK   (0xFFU)
#define PCIE_ACK_F_ASPM_CTRL_OFF_ACK_FREQ_SHIFT  (0U)
/*! ACK_FREQ - Ack Frequency. The controller accumulates the number of pending ACKs specified here
 *    (up to 255) before sending an ACK DLLP. - 0: Indicates that this Ack frequency control feature
 *    is turned off. The controller schedules a low-priority ACK DLLP for every TLP that it
 *    receives. - 1-255: Indicates that the controller will schedule a high-priority ACK after receiving
 *    this number of TLPs. It might schedule the ACK before receiving this number of TLPs, but never
 *    later. For a typical system, you do not have to modify the default setting. For more details,
 *    see "ACK/NAK Scheduling". Note: This register field is sticky.
 */
#define PCIE_ACK_F_ASPM_CTRL_OFF_ACK_FREQ(x)     (((uint32_t)(((uint32_t)(x)) << PCIE_ACK_F_ASPM_CTRL_OFF_ACK_FREQ_SHIFT)) & PCIE_ACK_F_ASPM_CTRL_OFF_ACK_FREQ_MASK)

#define PCIE_ACK_F_ASPM_CTRL_OFF_ACK_N_FTS_MASK  (0xFF00U)
#define PCIE_ACK_F_ASPM_CTRL_OFF_ACK_N_FTS_SHIFT (8U)
/*! ACK_N_FTS - N_FTS. The number of Fast Training Sequence ordered sets to be transmitted when
 *    transitioning from L0s to L0. The maximum number of FTS ordered-sets that a component can request
 *    is 255. The controller does not support a value of zero; a value of zero can cause the LTSSM
 *    to go into the recovery state when exiting from L0s. This field is reserved (fixed to '0') for
 *    M-PCIe. Note: This register field is sticky.
 */
#define PCIE_ACK_F_ASPM_CTRL_OFF_ACK_N_FTS(x)    (((uint32_t)(((uint32_t)(x)) << PCIE_ACK_F_ASPM_CTRL_OFF_ACK_N_FTS_SHIFT)) & PCIE_ACK_F_ASPM_CTRL_OFF_ACK_N_FTS_MASK)

#define PCIE_ACK_F_ASPM_CTRL_OFF_COMMON_CLK_N_FTS_MASK (0xFF0000U)
#define PCIE_ACK_F_ASPM_CTRL_OFF_COMMON_CLK_N_FTS_SHIFT (16U)
/*! COMMON_CLK_N_FTS - Common Clock N_FTS. This is the N_FTS when common clock is used. The number
 *    of Fast Training Sequence ordered sets to be transmitted when transitioning from L0s to L0. The
 *    maximum number of FTS ordered-sets that a component can request is 255. This field is only
 *    writable (sticky) when all of the following configuration parameter equations are true: -
 *    CX_NFTS !=CX_COMM_NFTS - DEFAULT_L0S_EXIT_LATENCY !=DEFAULT_COMM_L0S_EXIT_LATENCY -
 *    DEFAULT_L1_EXIT_LATENCY !=DEFAULT_COMM_L1_EXIT_LATENCY The controller does not support a value of zero; a
 *    value of zero can cause the LTSSM to go into the recovery state when exiting from L0s. This field
 *    is reserved (fixed to '0') for M-PCIe. Note: The access attributes of this field are as
 *    follows: - Dbi: R
 */
#define PCIE_ACK_F_ASPM_CTRL_OFF_COMMON_CLK_N_FTS(x) (((uint32_t)(((uint32_t)(x)) << PCIE_ACK_F_ASPM_CTRL_OFF_COMMON_CLK_N_FTS_SHIFT)) & PCIE_ACK_F_ASPM_CTRL_OFF_COMMON_CLK_N_FTS_MASK)

#define PCIE_ACK_F_ASPM_CTRL_OFF_L0S_ENTRANCE_LATENCY_MASK (0x7000000U)
#define PCIE_ACK_F_ASPM_CTRL_OFF_L0S_ENTRANCE_LATENCY_SHIFT (24U)
/*! L0S_ENTRANCE_LATENCY - L0s Entrance Latency. Values correspond to: - 000: 1 us - 001: 2 us -
 *    010: 3 us - 011: 4 us - 100: 5 us - 101: 6 us - 110 or 111: 7 us This field is applicable to
 *    STALL while in L0 for M-PCIe. Note: This register field is sticky.
 */
#define PCIE_ACK_F_ASPM_CTRL_OFF_L0S_ENTRANCE_LATENCY(x) (((uint32_t)(((uint32_t)(x)) << PCIE_ACK_F_ASPM_CTRL_OFF_L0S_ENTRANCE_LATENCY_SHIFT)) & PCIE_ACK_F_ASPM_CTRL_OFF_L0S_ENTRANCE_LATENCY_MASK)

#define PCIE_ACK_F_ASPM_CTRL_OFF_L1_ENTRANCE_LATENCY_MASK (0x38000000U)
#define PCIE_ACK_F_ASPM_CTRL_OFF_L1_ENTRANCE_LATENCY_SHIFT (27U)
/*! L1_ENTRANCE_LATENCY - L1 Entrance Latency. Value range is: - 000: 1 us - 001: 2 us - 010: 4 us -
 *    011: 8 us - 100: 16 us - 101: 32 us - 110 or 111: 64 us Note: Programming this timer with a
 *    value greater that 32us has no effect unless extended sync is used, or all of the credits are
 *    infinite. Note: This register field is sticky.
 */
#define PCIE_ACK_F_ASPM_CTRL_OFF_L1_ENTRANCE_LATENCY(x) (((uint32_t)(((uint32_t)(x)) << PCIE_ACK_F_ASPM_CTRL_OFF_L1_ENTRANCE_LATENCY_SHIFT)) & PCIE_ACK_F_ASPM_CTRL_OFF_L1_ENTRANCE_LATENCY_MASK)

#define PCIE_ACK_F_ASPM_CTRL_OFF_ENTER_ASPM_MASK (0x40000000U)
#define PCIE_ACK_F_ASPM_CTRL_OFF_ENTER_ASPM_SHIFT (30U)
/*! ENTER_ASPM - ASPM L1 Entry Control. - 1: Core enters ASPM L1 after a period in which it has been
 *    idle. - 0: Core enters ASPM L1 only after idle period during which both receive and transmit
 *    are in L0s. Note: This register field is sticky.
 */
#define PCIE_ACK_F_ASPM_CTRL_OFF_ENTER_ASPM(x)   (((uint32_t)(((uint32_t)(x)) << PCIE_ACK_F_ASPM_CTRL_OFF_ENTER_ASPM_SHIFT)) & PCIE_ACK_F_ASPM_CTRL_OFF_ENTER_ASPM_MASK)

#define PCIE_ACK_F_ASPM_CTRL_OFF_RSVDP_31_MASK   (0x80000000U)
#define PCIE_ACK_F_ASPM_CTRL_OFF_RSVDP_31_SHIFT  (31U)
/*! RSVDP_31 - Reserved for future use. */
#define PCIE_ACK_F_ASPM_CTRL_OFF_RSVDP_31(x)     (((uint32_t)(((uint32_t)(x)) << PCIE_ACK_F_ASPM_CTRL_OFF_RSVDP_31_SHIFT)) & PCIE_ACK_F_ASPM_CTRL_OFF_RSVDP_31_MASK)
/*! @} */

/*! @name PORT_LINK_CTRL_OFF - Port Link Control Register. */
/*! @{ */

#define PCIE_PORT_LINK_CTRL_OFF_VENDOR_SPECIFIC_DLLP_REQ_MASK (0x1U)
#define PCIE_PORT_LINK_CTRL_OFF_VENDOR_SPECIFIC_DLLP_REQ_SHIFT (0U)
/*! VENDOR_SPECIFIC_DLLP_REQ - Vendor Specific DLLP Request. When software writes a '1' to this bit,
 *    the controller transmits the DLLP contained in the VENDOR_SPEC_DLLP field of
 *    VENDOR_SPEC_DLLP_OFF. Reading from this self-clearing register field always returns a '0'.
 */
#define PCIE_PORT_LINK_CTRL_OFF_VENDOR_SPECIFIC_DLLP_REQ(x) (((uint32_t)(((uint32_t)(x)) << PCIE_PORT_LINK_CTRL_OFF_VENDOR_SPECIFIC_DLLP_REQ_SHIFT)) & PCIE_PORT_LINK_CTRL_OFF_VENDOR_SPECIFIC_DLLP_REQ_MASK)

#define PCIE_PORT_LINK_CTRL_OFF_SCRAMBLE_DISABLE_MASK (0x2U)
#define PCIE_PORT_LINK_CTRL_OFF_SCRAMBLE_DISABLE_SHIFT (1U)
/*! SCRAMBLE_DISABLE - Scramble Disable. Turns off data scrambling. Note: This register field is sticky. */
#define PCIE_PORT_LINK_CTRL_OFF_SCRAMBLE_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_PORT_LINK_CTRL_OFF_SCRAMBLE_DISABLE_SHIFT)) & PCIE_PORT_LINK_CTRL_OFF_SCRAMBLE_DISABLE_MASK)

#define PCIE_PORT_LINK_CTRL_OFF_LOOPBACK_ENABLE_MASK (0x4U)
#define PCIE_PORT_LINK_CTRL_OFF_LOOPBACK_ENABLE_SHIFT (2U)
/*! LOOPBACK_ENABLE - Loopback Enable. Turns on loopback. For more details, see "Loopback". For
 *    M-PCIe, to force the master to enter Digital Loopback mode, you must set this field to "1" during
 *    Configuration.start state(initial discovery/configuration). M-PCIe doesn't support loopback
 *    mode from L0 state - only from Configuration.start. Note: This register field is sticky.
 */
#define PCIE_PORT_LINK_CTRL_OFF_LOOPBACK_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_PORT_LINK_CTRL_OFF_LOOPBACK_ENABLE_SHIFT)) & PCIE_PORT_LINK_CTRL_OFF_LOOPBACK_ENABLE_MASK)

#define PCIE_PORT_LINK_CTRL_OFF_RESET_ASSERT_MASK (0x8U)
#define PCIE_PORT_LINK_CTRL_OFF_RESET_ASSERT_SHIFT (3U)
/*! RESET_ASSERT - Reset Assert. Triggers a recovery and forces the LTSSM to the hot reset state
 *    (downstream port only). Note: This register field is sticky.
 */
#define PCIE_PORT_LINK_CTRL_OFF_RESET_ASSERT(x)  (((uint32_t)(((uint32_t)(x)) << PCIE_PORT_LINK_CTRL_OFF_RESET_ASSERT_SHIFT)) & PCIE_PORT_LINK_CTRL_OFF_RESET_ASSERT_MASK)

#define PCIE_PORT_LINK_CTRL_OFF_RSVDP_4_MASK     (0x10U)
#define PCIE_PORT_LINK_CTRL_OFF_RSVDP_4_SHIFT    (4U)
/*! RSVDP_4 - Reserved for future use. */
#define PCIE_PORT_LINK_CTRL_OFF_RSVDP_4(x)       (((uint32_t)(((uint32_t)(x)) << PCIE_PORT_LINK_CTRL_OFF_RSVDP_4_SHIFT)) & PCIE_PORT_LINK_CTRL_OFF_RSVDP_4_MASK)

#define PCIE_PORT_LINK_CTRL_OFF_DLL_LINK_EN_MASK (0x20U)
#define PCIE_PORT_LINK_CTRL_OFF_DLL_LINK_EN_SHIFT (5U)
/*! DLL_LINK_EN - DLL Link Enable. Enables link initialization. When DLL Link Enable =0, the
 *    controller does not transmit InitFC DLLPs and does not establish a link. Note: This register field is
 *    sticky.
 */
#define PCIE_PORT_LINK_CTRL_OFF_DLL_LINK_EN(x)   (((uint32_t)(((uint32_t)(x)) << PCIE_PORT_LINK_CTRL_OFF_DLL_LINK_EN_SHIFT)) & PCIE_PORT_LINK_CTRL_OFF_DLL_LINK_EN_MASK)

#define PCIE_PORT_LINK_CTRL_OFF_LINK_DISABLE_MASK (0x40U)
#define PCIE_PORT_LINK_CTRL_OFF_LINK_DISABLE_SHIFT (6U)
/*! LINK_DISABLE - LINK_DISABLE is an internally reserved field. Do not use. Note: This register field is sticky. */
#define PCIE_PORT_LINK_CTRL_OFF_LINK_DISABLE(x)  (((uint32_t)(((uint32_t)(x)) << PCIE_PORT_LINK_CTRL_OFF_LINK_DISABLE_SHIFT)) & PCIE_PORT_LINK_CTRL_OFF_LINK_DISABLE_MASK)

#define PCIE_PORT_LINK_CTRL_OFF_FAST_LINK_MODE_MASK (0x80U)
#define PCIE_PORT_LINK_CTRL_OFF_FAST_LINK_MODE_SHIFT (7U)
/*! FAST_LINK_MODE - Fast Link Mode. Sets all internal LTSSM millisecond timers to Fast Mode for
 *    speeding up simulation. Forces the LTSSM training (link initialization) to use shorter time-outs
 *    and to link up faster. The default scaling factor can be changed using the
 *    DEFAULT_FAST_LINK_SCALING_FACTOR parameter or through the FAST_LINK_SCALING_FACTOR field in the
 *    TIMER_CTRL_MAX_FUNC_NUM_OFF register. Fast Link Mode can also be activated by setting the diag_ctrl_bus[2] pin
 *    to '1'. For more details, see the "Fast Link Simulation Mode" section in the "Integrating the
 *    Core with the PHY or Application RTL or Verification IP" chapter of the User Guide. For
 *    M-PCIe, this field also affects Remain Hibern8 Time, Minimum Activate Time, and RRAP timeout. If
 *    this bit is set to '1', tRRAPInitiatorResponse is set to 1.88 ms(60 ms/32). Note: This register
 *    field is sticky.
 */
#define PCIE_PORT_LINK_CTRL_OFF_FAST_LINK_MODE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_PORT_LINK_CTRL_OFF_FAST_LINK_MODE_SHIFT)) & PCIE_PORT_LINK_CTRL_OFF_FAST_LINK_MODE_MASK)

#define PCIE_PORT_LINK_CTRL_OFF_LINK_RATE_MASK   (0xF00U)
#define PCIE_PORT_LINK_CTRL_OFF_LINK_RATE_SHIFT  (8U)
/*! LINK_RATE - LINK_RATE is an internally reserved field. Do not use. Note: This register field is sticky. */
#define PCIE_PORT_LINK_CTRL_OFF_LINK_RATE(x)     (((uint32_t)(((uint32_t)(x)) << PCIE_PORT_LINK_CTRL_OFF_LINK_RATE_SHIFT)) & PCIE_PORT_LINK_CTRL_OFF_LINK_RATE_MASK)

#define PCIE_PORT_LINK_CTRL_OFF_RSVDP_12_MASK    (0xF000U)
#define PCIE_PORT_LINK_CTRL_OFF_RSVDP_12_SHIFT   (12U)
/*! RSVDP_12 - Reserved for future use. */
#define PCIE_PORT_LINK_CTRL_OFF_RSVDP_12(x)      (((uint32_t)(((uint32_t)(x)) << PCIE_PORT_LINK_CTRL_OFF_RSVDP_12_SHIFT)) & PCIE_PORT_LINK_CTRL_OFF_RSVDP_12_MASK)

#define PCIE_PORT_LINK_CTRL_OFF_LINK_CAPABLE_MASK (0x3F0000U)
#define PCIE_PORT_LINK_CTRL_OFF_LINK_CAPABLE_SHIFT (16U)
/*! LINK_CAPABLE - Link Mode Enable. Sets the number of lanes in the link that you want to connect
 *    to the link partner. When you have unused lanes in your system, then you must change the value
 *    in this register to reflect the number of lanes. You must also change the value in the
 *    "Predetermined Number of Lanes" field of the "Link Width and Speed Change Control Register". For more
 *    information, see "How to Tie Off Unused Lanes". For information on upsizing and downsizing
 *    the link width, see "Link Establishment". - 000001: x1 - 000011: x2 - 000111: x4 - 001111: x8 -
 *    011111: x16 - 111111: x32 (not supported) This field is reserved (fixed to '0') for M-PCIe.
 *    Note: This register field is sticky.
 */
#define PCIE_PORT_LINK_CTRL_OFF_LINK_CAPABLE(x)  (((uint32_t)(((uint32_t)(x)) << PCIE_PORT_LINK_CTRL_OFF_LINK_CAPABLE_SHIFT)) & PCIE_PORT_LINK_CTRL_OFF_LINK_CAPABLE_MASK)

#define PCIE_PORT_LINK_CTRL_OFF_BEACON_ENABLE_MASK (0x1000000U)
#define PCIE_PORT_LINK_CTRL_OFF_BEACON_ENABLE_SHIFT (24U)
/*! BEACON_ENABLE - BEACON_ENABLE is an internally reserved field. Do not use. Note: This register field is sticky. */
#define PCIE_PORT_LINK_CTRL_OFF_BEACON_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_PORT_LINK_CTRL_OFF_BEACON_ENABLE_SHIFT)) & PCIE_PORT_LINK_CTRL_OFF_BEACON_ENABLE_MASK)

#define PCIE_PORT_LINK_CTRL_OFF_CORRUPT_LCRC_ENABLE_MASK (0x2000000U)
#define PCIE_PORT_LINK_CTRL_OFF_CORRUPT_LCRC_ENABLE_SHIFT (25U)
/*! CORRUPT_LCRC_ENABLE - CORRUPT_LCRC_ENABLE is an internally reserved field. Do not use. Note: This register field is sticky. */
#define PCIE_PORT_LINK_CTRL_OFF_CORRUPT_LCRC_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_PORT_LINK_CTRL_OFF_CORRUPT_LCRC_ENABLE_SHIFT)) & PCIE_PORT_LINK_CTRL_OFF_CORRUPT_LCRC_ENABLE_MASK)

#define PCIE_PORT_LINK_CTRL_OFF_EXTENDED_SYNCH_MASK (0x4000000U)
#define PCIE_PORT_LINK_CTRL_OFF_EXTENDED_SYNCH_SHIFT (26U)
/*! EXTENDED_SYNCH - EXTENDED_SYNCH is an internally reserved field. Do not use. Note: This register field is sticky. */
#define PCIE_PORT_LINK_CTRL_OFF_EXTENDED_SYNCH(x) (((uint32_t)(((uint32_t)(x)) << PCIE_PORT_LINK_CTRL_OFF_EXTENDED_SYNCH_SHIFT)) & PCIE_PORT_LINK_CTRL_OFF_EXTENDED_SYNCH_MASK)

#define PCIE_PORT_LINK_CTRL_OFF_TRANSMIT_LANE_REVERSALE_ENABLE_MASK (0x8000000U)
#define PCIE_PORT_LINK_CTRL_OFF_TRANSMIT_LANE_REVERSALE_ENABLE_SHIFT (27U)
/*! TRANSMIT_LANE_REVERSALE_ENABLE - TRANSMIT_LANE_REVERSALE_ENABLE is an internally reserved field. Do not use. Note: This register field is sticky. */
#define PCIE_PORT_LINK_CTRL_OFF_TRANSMIT_LANE_REVERSALE_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_PORT_LINK_CTRL_OFF_TRANSMIT_LANE_REVERSALE_ENABLE_SHIFT)) & PCIE_PORT_LINK_CTRL_OFF_TRANSMIT_LANE_REVERSALE_ENABLE_MASK)

#define PCIE_PORT_LINK_CTRL_OFF_RSVDP_28_MASK    (0xF0000000U)
#define PCIE_PORT_LINK_CTRL_OFF_RSVDP_28_SHIFT   (28U)
/*! RSVDP_28 - Reserved for future use. */
#define PCIE_PORT_LINK_CTRL_OFF_RSVDP_28(x)      (((uint32_t)(((uint32_t)(x)) << PCIE_PORT_LINK_CTRL_OFF_RSVDP_28_SHIFT)) & PCIE_PORT_LINK_CTRL_OFF_RSVDP_28_MASK)
/*! @} */

/*! @name LANE_SKEW_OFF - Lane Skew Register. */
/*! @{ */

#define PCIE_LANE_SKEW_OFF_INSERT_LANE_SKEW_MASK (0xFFFFFFU)
#define PCIE_LANE_SKEW_OFF_INSERT_LANE_SKEW_SHIFT (0U)
/*! INSERT_LANE_SKEW - INSERT_LANE_SKEW is an internally reserved field. Do not use. Note: This register field is sticky. */
#define PCIE_LANE_SKEW_OFF_INSERT_LANE_SKEW(x)   (((uint32_t)(((uint32_t)(x)) << PCIE_LANE_SKEW_OFF_INSERT_LANE_SKEW_SHIFT)) & PCIE_LANE_SKEW_OFF_INSERT_LANE_SKEW_MASK)

#define PCIE_LANE_SKEW_OFF_FLOW_CTRL_DISABLE_MASK (0x1000000U)
#define PCIE_LANE_SKEW_OFF_FLOW_CTRL_DISABLE_SHIFT (24U)
/*! FLOW_CTRL_DISABLE - Flow Control Disable. Prevents the controller from sending FC DLLPs. Note: This register field is sticky. */
#define PCIE_LANE_SKEW_OFF_FLOW_CTRL_DISABLE(x)  (((uint32_t)(((uint32_t)(x)) << PCIE_LANE_SKEW_OFF_FLOW_CTRL_DISABLE_SHIFT)) & PCIE_LANE_SKEW_OFF_FLOW_CTRL_DISABLE_MASK)

#define PCIE_LANE_SKEW_OFF_ACK_NAK_DISABLE_MASK  (0x2000000U)
#define PCIE_LANE_SKEW_OFF_ACK_NAK_DISABLE_SHIFT (25U)
/*! ACK_NAK_DISABLE - Ack/Nak Disable. Prevents the controller from sending ACK and NAK DLLPs. Note: This register field is sticky. */
#define PCIE_LANE_SKEW_OFF_ACK_NAK_DISABLE(x)    (((uint32_t)(((uint32_t)(x)) << PCIE_LANE_SKEW_OFF_ACK_NAK_DISABLE_SHIFT)) & PCIE_LANE_SKEW_OFF_ACK_NAK_DISABLE_MASK)

#define PCIE_LANE_SKEW_OFF_GEN34_ELASTIC_BUFFER_MODE_MASK (0x4000000U)
#define PCIE_LANE_SKEW_OFF_GEN34_ELASTIC_BUFFER_MODE_SHIFT (26U)
/*! GEN34_ELASTIC_BUFFER_MODE - Selects Elasticity Buffer operating mode in Gen3 or Gen4 rate: 0:
 *    Nominal Half Full Buffer mode 1: Nominal Empty Buffer Mode This register bit only affects Gen3
 *    or Gen4 operating rate. For Gen1 or Gen2 operating rate the Elasticity Buffer operating mode is
 *    always the Nominal Half Full Buffer mode. Note: This register field is sticky.
 */
#define PCIE_LANE_SKEW_OFF_GEN34_ELASTIC_BUFFER_MODE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_LANE_SKEW_OFF_GEN34_ELASTIC_BUFFER_MODE_SHIFT)) & PCIE_LANE_SKEW_OFF_GEN34_ELASTIC_BUFFER_MODE_MASK)

#define PCIE_LANE_SKEW_OFF_IMPLEMENT_NUM_LANES_MASK (0x78000000U)
#define PCIE_LANE_SKEW_OFF_IMPLEMENT_NUM_LANES_SHIFT (27U)
/*! IMPLEMENT_NUM_LANES - Implementation-specific Number of Lanes. Set the implementation-specific
 *    number of lanes. Allowed values are: - 4'b0000: 1 lane - 4'b0001: 2 lanes - 4'b0011: 4 lanes -
 *    4'b0111: 8 lanes - 4'b1111: 16 lanes The number of lanes to be used when in Loopback Master.
 *    The number of lanes programmed must be equal to or less than the valid number of lanes set in
 *    LINK_CAPABLE field. You must configure this field before initiating Loopback by writing in the
 *    LOOPBACK_ENABLE field. The controller will transition from Loopback.Entry to Loopback.Active
 *    after receiving two consecutive TS1 Ordered Sets with the Loopback bit asserted on the
 *    implementation specific number of lanes configured in this field. Note: This register field is sticky.
 */
#define PCIE_LANE_SKEW_OFF_IMPLEMENT_NUM_LANES(x) (((uint32_t)(((uint32_t)(x)) << PCIE_LANE_SKEW_OFF_IMPLEMENT_NUM_LANES_SHIFT)) & PCIE_LANE_SKEW_OFF_IMPLEMENT_NUM_LANES_MASK)

#define PCIE_LANE_SKEW_OFF_DISABLE_LANE_TO_LANE_DESKEW_MASK (0x80000000U)
#define PCIE_LANE_SKEW_OFF_DISABLE_LANE_TO_LANE_DESKEW_SHIFT (31U)
/*! DISABLE_LANE_TO_LANE_DESKEW - Disable Lane-to-Lane Deskew. Causes the controller to disable the
 *    internal Lane-to-Lane deskew logic. Note: This register field is sticky.
 */
#define PCIE_LANE_SKEW_OFF_DISABLE_LANE_TO_LANE_DESKEW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_LANE_SKEW_OFF_DISABLE_LANE_TO_LANE_DESKEW_SHIFT)) & PCIE_LANE_SKEW_OFF_DISABLE_LANE_TO_LANE_DESKEW_MASK)
/*! @} */

/*! @name TIMER_CTRL_MAX_FUNC_NUM_OFF - Timer Control and Max Function Number Register. */
/*! @{ */

#define PCIE_TIMER_CTRL_MAX_FUNC_NUM_OFF_MAX_FUNC_NUM_MASK (0xFFU)
#define PCIE_TIMER_CTRL_MAX_FUNC_NUM_OFF_MAX_FUNC_NUM_SHIFT (0U)
/*! MAX_FUNC_NUM - Maximum function number that can be used in a request. Configuration requests
 *    targeted at function numbers above this value are returned with UR (unsupported request). Note:
 *    This register field is sticky.
 */
#define PCIE_TIMER_CTRL_MAX_FUNC_NUM_OFF_MAX_FUNC_NUM(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TIMER_CTRL_MAX_FUNC_NUM_OFF_MAX_FUNC_NUM_SHIFT)) & PCIE_TIMER_CTRL_MAX_FUNC_NUM_OFF_MAX_FUNC_NUM_MASK)

#define PCIE_TIMER_CTRL_MAX_FUNC_NUM_OFF_RSVDP_8_MASK (0x3F00U)
#define PCIE_TIMER_CTRL_MAX_FUNC_NUM_OFF_RSVDP_8_SHIFT (8U)
/*! RSVDP_8 - Reserved for future use. */
#define PCIE_TIMER_CTRL_MAX_FUNC_NUM_OFF_RSVDP_8(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TIMER_CTRL_MAX_FUNC_NUM_OFF_RSVDP_8_SHIFT)) & PCIE_TIMER_CTRL_MAX_FUNC_NUM_OFF_RSVDP_8_MASK)

#define PCIE_TIMER_CTRL_MAX_FUNC_NUM_OFF_TIMER_MOD_REPLAY_TIMER_MASK (0x7C000U)
#define PCIE_TIMER_CTRL_MAX_FUNC_NUM_OFF_TIMER_MOD_REPLAY_TIMER_SHIFT (14U)
/*! TIMER_MOD_REPLAY_TIMER - Replay Timer Limit Modifier. Increases the time-out value for the
 *    replay timer in increments of 64 clock cycles at Gen1 or Gen2 speed, and in increments of 256 clock
 *    cycles at Gen3 speed. A value of "0" represents no modification to the timer limit. For more
 *    details, see the REPLAY_TIME_LIMIT field of the ACK_LATENCY_TIMER_OFF register. At Gen3 speed,
 *    the controller automatically changes the value of this field to DEFAULT_GEN3_REPLAY_ADJ. For
 *    M-PCIe, this field increases the time-out value for the replay timer in increments of 64 clock
 *    cycles at HS-Gear1, HS-Gear2, or HS-Gear3 speed. Note: This register field is sticky.
 */
#define PCIE_TIMER_CTRL_MAX_FUNC_NUM_OFF_TIMER_MOD_REPLAY_TIMER(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TIMER_CTRL_MAX_FUNC_NUM_OFF_TIMER_MOD_REPLAY_TIMER_SHIFT)) & PCIE_TIMER_CTRL_MAX_FUNC_NUM_OFF_TIMER_MOD_REPLAY_TIMER_MASK)

#define PCIE_TIMER_CTRL_MAX_FUNC_NUM_OFF_TIMER_MOD_ACK_NAK_MASK (0xF80000U)
#define PCIE_TIMER_CTRL_MAX_FUNC_NUM_OFF_TIMER_MOD_ACK_NAK_SHIFT (19U)
/*! TIMER_MOD_ACK_NAK - Ack Latency Timer Modifier. Increases the timer value for the Ack latency
 *    timer in increments of 64 clock cycles. A value of "0" represents no modification to the timer
 *    value. For more details, see the ROUND_TRIP_LATENCY_TIME_LIMIT field of the
 *    ACK_LATENCY_TIMER_OFF register. Note: This register field is sticky.
 */
#define PCIE_TIMER_CTRL_MAX_FUNC_NUM_OFF_TIMER_MOD_ACK_NAK(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TIMER_CTRL_MAX_FUNC_NUM_OFF_TIMER_MOD_ACK_NAK_SHIFT)) & PCIE_TIMER_CTRL_MAX_FUNC_NUM_OFF_TIMER_MOD_ACK_NAK_MASK)

#define PCIE_TIMER_CTRL_MAX_FUNC_NUM_OFF_UPDATE_FREQ_TIMER_MASK (0x1F000000U)
#define PCIE_TIMER_CTRL_MAX_FUNC_NUM_OFF_UPDATE_FREQ_TIMER_SHIFT (24U)
/*! UPDATE_FREQ_TIMER - UPDATE_FREQ_TIMER is an internally reserved field. Do not use. Note: This register field is sticky. */
#define PCIE_TIMER_CTRL_MAX_FUNC_NUM_OFF_UPDATE_FREQ_TIMER(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TIMER_CTRL_MAX_FUNC_NUM_OFF_UPDATE_FREQ_TIMER_SHIFT)) & PCIE_TIMER_CTRL_MAX_FUNC_NUM_OFF_UPDATE_FREQ_TIMER_MASK)

#define PCIE_TIMER_CTRL_MAX_FUNC_NUM_OFF_FAST_LINK_SCALING_FACTOR_MASK (0x60000000U)
#define PCIE_TIMER_CTRL_MAX_FUNC_NUM_OFF_FAST_LINK_SCALING_FACTOR_SHIFT (29U)
/*! FAST_LINK_SCALING_FACTOR - Fast Link Timer Scaling Factor. Sets the scaling factor of LTSSM
 *    timer when FAST_LINK_MODE field in PORT_LINK_CTRL_OFF is set to '1'. - 0: Scaling Factor is 1024
 *    (1ms is 1us) - 1: Scaling Factor is 256 (1ms is 4us) - 2: Scaling Factor is 64 (1ms is 16us) -
 *    3: Scaling Factor is 16 (1ms is 64us) Default is set by the hidden configuration parameter
 *    DEFAULT_FAST_LINK_SCALING_FACTOR which defaults to '0'. Not used for M-PCIe. Note: This register
 *    field is sticky.
 */
#define PCIE_TIMER_CTRL_MAX_FUNC_NUM_OFF_FAST_LINK_SCALING_FACTOR(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TIMER_CTRL_MAX_FUNC_NUM_OFF_FAST_LINK_SCALING_FACTOR_SHIFT)) & PCIE_TIMER_CTRL_MAX_FUNC_NUM_OFF_FAST_LINK_SCALING_FACTOR_MASK)

#define PCIE_TIMER_CTRL_MAX_FUNC_NUM_OFF_RSVDP_31_MASK (0x80000000U)
#define PCIE_TIMER_CTRL_MAX_FUNC_NUM_OFF_RSVDP_31_SHIFT (31U)
/*! RSVDP_31 - Reserved for future use. */
#define PCIE_TIMER_CTRL_MAX_FUNC_NUM_OFF_RSVDP_31(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TIMER_CTRL_MAX_FUNC_NUM_OFF_RSVDP_31_SHIFT)) & PCIE_TIMER_CTRL_MAX_FUNC_NUM_OFF_RSVDP_31_MASK)
/*! @} */

/*! @name SYMBOL_TIMER_FILTER_1_OFF - Symbol Timer Register and Filter Mask 1 Register. */
/*! @{ */

#define PCIE_SYMBOL_TIMER_FILTER_1_OFF_SKP_INT_VAL_MASK (0x7FFU)
#define PCIE_SYMBOL_TIMER_FILTER_1_OFF_SKP_INT_VAL_SHIFT (0U)
/*! SKP_INT_VAL - SKP Interval Value. The number of symbol times to wait between transmitting SKP
 *    ordered sets. Note that the controller actually waits the number of symbol times in this
 *    register plus 1 between transmitting SKP ordered sets. Your application must program this register
 *    accordingly. For example, if 1536 were programmed into this register (in a 250 MHz controller),
 *    then the controller actually transmits SKP ordered sets once every 1537 symbol times. The
 *    value programmed to this register is actually clock ticks and not symbol times. In a 125 MHz
 *    controller, programming the value programmed to this register should be scaled down by a factor of
 *    2 (because one clock tick = two symbol times in this case). Note: This value is not used at
 *    Gen3 speed; the skip interval is hardcoded to 370 blocks. For M-PCIe configurations, if the
 *    2K_PPM_DISABLED field in the M-PCIe Configuration Attribute is changed, then this field is changed
 *    automatically as follows. - 2K_PPM_DISABLED=1: 1280 / CX_NB - 2K_PPM_DISABLED=0: 228/CX_NB
 *    You need to set this field again if necessary when 2K_PPM_DISABLED is changed. Note: This
 *    register field is sticky.
 */
#define PCIE_SYMBOL_TIMER_FILTER_1_OFF_SKP_INT_VAL(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SYMBOL_TIMER_FILTER_1_OFF_SKP_INT_VAL_SHIFT)) & PCIE_SYMBOL_TIMER_FILTER_1_OFF_SKP_INT_VAL_MASK)

#define PCIE_SYMBOL_TIMER_FILTER_1_OFF_EIDLE_TIMER_MASK (0x7800U)
#define PCIE_SYMBOL_TIMER_FILTER_1_OFF_EIDLE_TIMER_SHIFT (11U)
/*! EIDLE_TIMER - EIDLE_TIMER is an internally reserved field. Do not use. Note: This register field is sticky. */
#define PCIE_SYMBOL_TIMER_FILTER_1_OFF_EIDLE_TIMER(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SYMBOL_TIMER_FILTER_1_OFF_EIDLE_TIMER_SHIFT)) & PCIE_SYMBOL_TIMER_FILTER_1_OFF_EIDLE_TIMER_MASK)

#define PCIE_SYMBOL_TIMER_FILTER_1_OFF_DISABLE_FC_WD_TIMER_MASK (0x8000U)
#define PCIE_SYMBOL_TIMER_FILTER_1_OFF_DISABLE_FC_WD_TIMER_SHIFT (15U)
/*! DISABLE_FC_WD_TIMER - Disable FC Watchdog Timer. Note: This register field is sticky. */
#define PCIE_SYMBOL_TIMER_FILTER_1_OFF_DISABLE_FC_WD_TIMER(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SYMBOL_TIMER_FILTER_1_OFF_DISABLE_FC_WD_TIMER_SHIFT)) & PCIE_SYMBOL_TIMER_FILTER_1_OFF_DISABLE_FC_WD_TIMER_MASK)

#define PCIE_SYMBOL_TIMER_FILTER_1_OFF_MASK_RADM_1_MASK (0xFFFF0000U)
#define PCIE_SYMBOL_TIMER_FILTER_1_OFF_MASK_RADM_1_SHIFT (16U)
/*! MASK_RADM_1 - Filter Mask 1. The Filter Mask 1 Register modifies the RADM filtering and error
 *    handling rules. For more details, see the "Receive Filtering" section. In each case, '0' applies
 *    the associated filtering rule and '1' masks the associated filtering rule. [31]:
 *    CX_FLT_MASK_RC_CFG_DISCARD - 0: For RADM RC filter to not allow CFG transaction being received - 1: For
 *    RADM RC filter to allow CFG transaction being received [30]: CX_FLT_MASK_RC_IO_DISCARD - 0: For
 *    RADM RC filter to not allow IO transaction being received - 1: For RADM RC filter to allow IO
 *    transaction being received [29]: CX_FLT_MASK_MSG_DROP - 0: Drop MSG TLP (except for Vendor
 *    MSG). Send decoded message on the SII. - 1: Do not Drop MSG (except for Vendor MSG). Send message
 *    TLPs to your application on TRGT1 and send decoded message on the SII. - The default for this
 *    bit is the inverse of FLT_DROP_MSG. That is, if FLT_DROP_MSG =1, then the default of this bit
 *    is "0" (drop message TLPs). This bit only controls message TLPs other than Vendor MSGs.
 *    Vendor MSGs are controlled by Filter Mask Register 2, bits [1:0]. The controller never passes ATS
 *    Invalidate messages to the SII interface regardless of this filter rule setting. The controller
 *    passes all ATS Invalidate messages to TRGT1 (or AXI bridge master), as they are too big for
 *    the SII. [28]: CX_FLT_MASK_CPL_ECRC_DISCARD - Only used when completion queue is advertised
 *    with infinite credits and is in store-and-forward mode. - 0: Discard completions with ECRC errors
 *    - 1: Allow completions with ECRC errors to be passed up - Reserved field for SW. [27]:
 *    CX_FLT_MASK_ECRC_DISCARD - 0: Discard TLPs with ECRC errors - 1: Allow TLPs with ECRC errors to be
 *    passed up [26]: CX_FLT_MASK_CPL_LEN_MATCH - 0: Enforce length match for completions; a
 *    violation results in cpl_abort, and possibly AER of unexp_cpl_err - 1: MASK length match for
 *    completions [25]: CX_FLT_MASK_CPL_ATTR_MATCH - 0: Enforce attribute match for completions; a violation
 *    results in a malformed TLP error, and possibly AER of unexp_cpl_err, cpl_rcvd_ur, cpl_rcvd_ca
 *    - 1: Mask attribute match for completions [24]: CX_FLT_MASK_CPL_TC_MATCH - 0: Enforce Traffic
 *    Class match for completions; a violation results in a malformed TLP error, and possibly AER of
 *    unexp_cpl_err, cpl_rcvd_ur, cpl_rcvd_ca - 1: Mask Traffic Class match for completions [23]:
 *    CX_FLT_MASK_CPL_FUNC_MATCH - 0: Enforce function match for completions; a violation results in
 *    cpl_abort, and possibly AER of unexp_cpl_err, cpl_rcvd_ur, cpl_rcvd_ca - 1: Mask function
 *    match for completions [22]: CX_FLT_MASK_CPL_REQID_MATCH - 0: Enforce Req. Id match for
 *    completions; a violation result in cpl_abort, and possibly AER of unexp_cpl_err, cpl_rcvd_ur, cpl_rcvd_ca
 *    - 1: Mask Req. Id match for completions [21]: CX_FLT_MASK_CPL_TAGERR_MATCH - 0: Enforce Tag
 *    Error Rules for completions; a violation result in cpl_abort, and possibly AER of
 *    unexp_cpl_err, cpl_rcvd_ur, cpl_rcvd_ca - 1: Mask Tag Error Rules for completions [20]:
 *    CX_FLT_MASK_LOCKED_RD_AS_UR - 0: Treat locked Read TLPs as UR for EP; Supported for RC - 1: Treat locked Read
 *    TLPs as Supported for EP; UR for RC [19]: CX_FLT_MASK_CFG_TYPE1_REQ_AS_UR - 0: Treat CFG type1
 *    TLPs as UR for EP; Supported for RC - 1: Treat CFG type1 TLPs as Supported for EP; UR for RC -
 *    When CX_SRIOV_ENABLE is set then this bit is set to allow the filter to process Type 1 Config
 *    requests if the EP consumes more than one bus number. [18]: CX_FLT_MASK_UR_OUTSIDE_BAR - 0:
 *    Treat out-of-bar TLPs as UR - 1: Do not treat out-of-bar TLPs as UR [17]: CX_FLT_MASK_UR_POIS -
 *    0: Treat poisoned request TLPs as UR - 1: Do not treat poisoned request TLPs as UR - The native
 *    controller always passes poisoned completions to your application except when you are using
 *    the DMA read channel. [16]: CX_FLT_MASK_UR_FUNC_MISMATCH - 0: Treat Function MisMatched TLPs as
 *    UR - 1: Do not treat Function MisMatched TLPs as UR Note: This register field is sticky.
 */
#define PCIE_SYMBOL_TIMER_FILTER_1_OFF_MASK_RADM_1(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SYMBOL_TIMER_FILTER_1_OFF_MASK_RADM_1_SHIFT)) & PCIE_SYMBOL_TIMER_FILTER_1_OFF_MASK_RADM_1_MASK)
/*! @} */

/*! @name FILTER_MASK_2_OFF - Filter Mask 2 Register. */
/*! @{ */

#define PCIE_FILTER_MASK_2_OFF_MASK_RADM_2_MASK  (0xFFFFFFFFU)
#define PCIE_FILTER_MASK_2_OFF_MASK_RADM_2_SHIFT (0U)
/*! MASK_RADM_2 - Filter Mask 2. This field modifies the RADM filtering and error handling rules.
 *    For more details, see the "Receive Filtering" section. In each case, '0' applies the associated
 *    filtering rule and '1' masks the associated filtering rule. [31:8]: Reserved [7]:
 *    CX_FLT_MASK_PRS_DROP - 0: Allow PRS message to pass through - 1: Drop PRS Messages silently - This bit is
 *    ignored when the CX_FLT_MASK_MSG_DROP bit in the MASK_RADM_1 field of the
 *    SYMBOL_TIMER_FILTER_1_OFF register is set to '1'. [6]: CX_FLT_UNMASK_TD - 0: Disable unmask TD bit if
 *    CX_STRIP_ECRC_ENABLE - 1: Enable unmask TD bit if CX_STRIP_ECRC_ENABLE [5]: CX_FLT_UNMASK_UR_POIS_TRGT0 -
 *    0: Disable unmask CX_FLT_MASK_UR_POIS with TRGT0 destination - 1: Enable unmask
 *    CX_FLT_MASK_UR_POIS with TRGT0 destination [4]: CX_FLT_MASK_LN_VENMSG1_DROP - 0: Allow LN message to pass
 *    through - 1: Drop LN Messages silently [3]: CX_FLT_MASK_HANDLE_FLUSH - 0: Disable controller
 *    Filter to handle flush request - 1: Enable controller Filter to handle flush request [2]:
 *    CX_FLT_MASK_DABORT_4UCPL - 0: Enable DLLP abort for unexpected completion - 1: Do not enable DLLP
 *    abort for unexpected completion [1]: CX_FLT_MASK_VENMSG1_DROP - 0: Vendor MSG Type 1 dropped
 *    silently - 1: Vendor MSG Type 1 not dropped [0]: CX_FLT_MASK_VENMSG0_DROP - 0: Vendor MSG Type 0
 *    dropped with UR error reporting - 1: Vendor MSG Type 0 not dropped Note: This register field is
 *    sticky.
 */
#define PCIE_FILTER_MASK_2_OFF_MASK_RADM_2(x)    (((uint32_t)(((uint32_t)(x)) << PCIE_FILTER_MASK_2_OFF_MASK_RADM_2_SHIFT)) & PCIE_FILTER_MASK_2_OFF_MASK_RADM_2_MASK)
/*! @} */

/*! @name AMBA_MUL_OB_DECOMP_NP_SUB_REQ_CTRL_OFF - AMBA Multiple Outbound Decomposed NP SubRequests Control Register. */
/*! @{ */

#define PCIE_AMBA_MUL_OB_DECOMP_NP_SUB_REQ_CTRL_OFF_OB_RD_SPLIT_BURST_EN_MASK (0x1U)
#define PCIE_AMBA_MUL_OB_DECOMP_NP_SUB_REQ_CTRL_OFF_OB_RD_SPLIT_BURST_EN_SHIFT (0U)
/*! OB_RD_SPLIT_BURST_EN - Enable AMBA Multiple Outbound Decomposed NP SubRequests. This bit when
 *    set to "0" disables the possibility of having multiple outstanding non-posted requests that were
 *    derived from decomposition of an outbound AMBA request. For more details, see "AXI Bridge
 *    Ordering" in the AXI chapter of the Databook. You should not clear this register unless your
 *    application master is requesting an amount of read data greater than Max_Read_Request_Size, and
 *    the remote device (or switch) is reordering completions that have different tags. Note: The
 *    access attributes of this field are as follows: - Dbi: R/W (sticky) Note: This register field is
 *    sticky.
 */
#define PCIE_AMBA_MUL_OB_DECOMP_NP_SUB_REQ_CTRL_OFF_OB_RD_SPLIT_BURST_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_AMBA_MUL_OB_DECOMP_NP_SUB_REQ_CTRL_OFF_OB_RD_SPLIT_BURST_EN_SHIFT)) & PCIE_AMBA_MUL_OB_DECOMP_NP_SUB_REQ_CTRL_OFF_OB_RD_SPLIT_BURST_EN_MASK)

#define PCIE_AMBA_MUL_OB_DECOMP_NP_SUB_REQ_CTRL_OFF_RSVDP_1_MASK (0xFFFFFFFEU)
#define PCIE_AMBA_MUL_OB_DECOMP_NP_SUB_REQ_CTRL_OFF_RSVDP_1_SHIFT (1U)
/*! RSVDP_1 - Reserved for future use. */
#define PCIE_AMBA_MUL_OB_DECOMP_NP_SUB_REQ_CTRL_OFF_RSVDP_1(x) (((uint32_t)(((uint32_t)(x)) << PCIE_AMBA_MUL_OB_DECOMP_NP_SUB_REQ_CTRL_OFF_RSVDP_1_SHIFT)) & PCIE_AMBA_MUL_OB_DECOMP_NP_SUB_REQ_CTRL_OFF_RSVDP_1_MASK)
/*! @} */

/*! @name PL_DEBUG0_OFF - Debug Register 0 */
/*! @{ */

#define PCIE_PL_DEBUG0_OFF_DEB_REG_0_MASK        (0xFFFFFFFFU)
#define PCIE_PL_DEBUG0_OFF_DEB_REG_0_SHIFT       (0U)
/*! DEB_REG_0 - The value on cxpl_debug_info[31:0]. */
#define PCIE_PL_DEBUG0_OFF_DEB_REG_0(x)          (((uint32_t)(((uint32_t)(x)) << PCIE_PL_DEBUG0_OFF_DEB_REG_0_SHIFT)) & PCIE_PL_DEBUG0_OFF_DEB_REG_0_MASK)
/*! @} */

/*! @name PL_DEBUG1_OFF - Debug Register 1 */
/*! @{ */

#define PCIE_PL_DEBUG1_OFF_DEB_REG_1_MASK        (0xFFFFFFFFU)
#define PCIE_PL_DEBUG1_OFF_DEB_REG_1_SHIFT       (0U)
/*! DEB_REG_1 - The value on cxpl_debug_info[63:32]. */
#define PCIE_PL_DEBUG1_OFF_DEB_REG_1(x)          (((uint32_t)(((uint32_t)(x)) << PCIE_PL_DEBUG1_OFF_DEB_REG_1_SHIFT)) & PCIE_PL_DEBUG1_OFF_DEB_REG_1_MASK)
/*! @} */

/*! @name TX_P_FC_CREDIT_STATUS_OFF - Transmit Posted FC Credit Status */
/*! @{ */

#define PCIE_TX_P_FC_CREDIT_STATUS_OFF_TX_P_DATA_FC_CREDIT_MASK (0xFFFU)
#define PCIE_TX_P_FC_CREDIT_STATUS_OFF_TX_P_DATA_FC_CREDIT_SHIFT (0U)
/*! TX_P_DATA_FC_CREDIT - Transmit Posted Data FC Credits. The posted Data credits advertised by the
 *    receiver at the other end of the link, updated with each UpdateFC DLLP. Default value depends
 *    on the number of advertised credits for header and data [12'b0, xtlh_xadm_ph_cdts,
 *    xtlh_xadm_pd_cdts]; When the number of advertised completion credits (both header and data) are
 *    infinite, then the default would be [12'b0, 8'hFF, 12'hFFF].
 */
#define PCIE_TX_P_FC_CREDIT_STATUS_OFF_TX_P_DATA_FC_CREDIT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TX_P_FC_CREDIT_STATUS_OFF_TX_P_DATA_FC_CREDIT_SHIFT)) & PCIE_TX_P_FC_CREDIT_STATUS_OFF_TX_P_DATA_FC_CREDIT_MASK)

#define PCIE_TX_P_FC_CREDIT_STATUS_OFF_TX_P_HEADER_FC_CREDIT_MASK (0xFF000U)
#define PCIE_TX_P_FC_CREDIT_STATUS_OFF_TX_P_HEADER_FC_CREDIT_SHIFT (12U)
/*! TX_P_HEADER_FC_CREDIT - Transmit Posted Header FC Credits. The posted Header credits advertised
 *    by the receiver at the other end of the link, updated with each UpdateFC DLLP. Default value
 *    depends on the number of advertised credits for header and data [12'b0, xtlh_xadm_ph_cdts,
 *    xtlh_xadm_pd_cdts]; When the number of advertised completion credits (both header and data) are
 *    infinite, then the default would be [12'b0, 8'hFF, 12'hFFF].
 */
#define PCIE_TX_P_FC_CREDIT_STATUS_OFF_TX_P_HEADER_FC_CREDIT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TX_P_FC_CREDIT_STATUS_OFF_TX_P_HEADER_FC_CREDIT_SHIFT)) & PCIE_TX_P_FC_CREDIT_STATUS_OFF_TX_P_HEADER_FC_CREDIT_MASK)

#define PCIE_TX_P_FC_CREDIT_STATUS_OFF_RSVDP_20_MASK (0xFFF00000U)
#define PCIE_TX_P_FC_CREDIT_STATUS_OFF_RSVDP_20_SHIFT (20U)
/*! RSVDP_20 - Reserved for future use. */
#define PCIE_TX_P_FC_CREDIT_STATUS_OFF_RSVDP_20(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TX_P_FC_CREDIT_STATUS_OFF_RSVDP_20_SHIFT)) & PCIE_TX_P_FC_CREDIT_STATUS_OFF_RSVDP_20_MASK)
/*! @} */

/*! @name TX_NP_FC_CREDIT_STATUS_OFF - Transmit Non-Posted FC Credit Status */
/*! @{ */

#define PCIE_TX_NP_FC_CREDIT_STATUS_OFF_TX_NP_DATA_FC_CREDIT_MASK (0xFFFU)
#define PCIE_TX_NP_FC_CREDIT_STATUS_OFF_TX_NP_DATA_FC_CREDIT_SHIFT (0U)
/*! TX_NP_DATA_FC_CREDIT - Transmit Non-Posted Data FC Credits. The non-posted Data credits
 *    advertised by the receiver at the other end of the link, updated with each UpdateFC DLLP. Default
 *    value depends on the number of advertised credits for header and data [12'b0, xtlh_xadm_nph_cdts,
 *    xtlh_xadm_npd_cdts]; When the number of advertised completion credits (both header and data)
 *    are infinite, then the default would be [12'b0, 8'hFF, 12'hFFF].
 */
#define PCIE_TX_NP_FC_CREDIT_STATUS_OFF_TX_NP_DATA_FC_CREDIT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TX_NP_FC_CREDIT_STATUS_OFF_TX_NP_DATA_FC_CREDIT_SHIFT)) & PCIE_TX_NP_FC_CREDIT_STATUS_OFF_TX_NP_DATA_FC_CREDIT_MASK)

#define PCIE_TX_NP_FC_CREDIT_STATUS_OFF_TX_NP_HEADER_FC_CREDIT_MASK (0xFF000U)
#define PCIE_TX_NP_FC_CREDIT_STATUS_OFF_TX_NP_HEADER_FC_CREDIT_SHIFT (12U)
/*! TX_NP_HEADER_FC_CREDIT - Transmit Non-Posted Header FC Credits. The non-posted Header credits
 *    advertised by the receiver at the other end of the link, updated with each UpdateFC DLLP.
 *    Default value depends on the number of advertised credits for header and data [12'b0,
 *    xtlh_xadm_nph_cdts, xtlh_xadm_npd_cdts]; When the number of advertised completion credits (both header and
 *    data) are infinite, then the default would be [12'b0, 8'hFF, 12'hFFF].
 */
#define PCIE_TX_NP_FC_CREDIT_STATUS_OFF_TX_NP_HEADER_FC_CREDIT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TX_NP_FC_CREDIT_STATUS_OFF_TX_NP_HEADER_FC_CREDIT_SHIFT)) & PCIE_TX_NP_FC_CREDIT_STATUS_OFF_TX_NP_HEADER_FC_CREDIT_MASK)

#define PCIE_TX_NP_FC_CREDIT_STATUS_OFF_RSVDP_20_MASK (0xFFF00000U)
#define PCIE_TX_NP_FC_CREDIT_STATUS_OFF_RSVDP_20_SHIFT (20U)
/*! RSVDP_20 - Reserved for future use. */
#define PCIE_TX_NP_FC_CREDIT_STATUS_OFF_RSVDP_20(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TX_NP_FC_CREDIT_STATUS_OFF_RSVDP_20_SHIFT)) & PCIE_TX_NP_FC_CREDIT_STATUS_OFF_RSVDP_20_MASK)
/*! @} */

/*! @name TX_CPL_FC_CREDIT_STATUS_OFF - Transmit Completion FC Credit Status */
/*! @{ */

#define PCIE_TX_CPL_FC_CREDIT_STATUS_OFF_TX_CPL_DATA_FC_CREDIT_MASK (0xFFFU)
#define PCIE_TX_CPL_FC_CREDIT_STATUS_OFF_TX_CPL_DATA_FC_CREDIT_SHIFT (0U)
/*! TX_CPL_DATA_FC_CREDIT - Transmit Completion Data FC Credits. The Completion Data credits
 *    advertised by the receiver at the other end of the link, updated with each UpdateFC DLLP. Default
 *    value depends on the number of advertised credits for header and data [12'b0,
 *    xtlh_xadm_cplh_cdts, xtlh_xadm_cpld_cdts]; When the number of advertised completion credits (both header and
 *    data) are infinite, then the default would be [12'b0, 8'hFF, 12'hFFF].
 */
#define PCIE_TX_CPL_FC_CREDIT_STATUS_OFF_TX_CPL_DATA_FC_CREDIT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TX_CPL_FC_CREDIT_STATUS_OFF_TX_CPL_DATA_FC_CREDIT_SHIFT)) & PCIE_TX_CPL_FC_CREDIT_STATUS_OFF_TX_CPL_DATA_FC_CREDIT_MASK)

#define PCIE_TX_CPL_FC_CREDIT_STATUS_OFF_TX_CPL_HEADER_FC_CREDIT_MASK (0xFF000U)
#define PCIE_TX_CPL_FC_CREDIT_STATUS_OFF_TX_CPL_HEADER_FC_CREDIT_SHIFT (12U)
/*! TX_CPL_HEADER_FC_CREDIT - Transmit Completion Header FC Credits. The Completion Header credits
 *    advertised by the receiver at the other end of the link, updated with each UpdateFC DLLP.
 *    Default value depends on the number of advertised credits for header and data [12'b0,
 *    xtlh_xadm_cplh_cdts, xtlh_xadm_cpld_cdts]; When the number of advertised completion credits (both header
 *    and data) are infinite, then the default would be [12'b0, 8'hFF, 12'hFFF].
 */
#define PCIE_TX_CPL_FC_CREDIT_STATUS_OFF_TX_CPL_HEADER_FC_CREDIT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TX_CPL_FC_CREDIT_STATUS_OFF_TX_CPL_HEADER_FC_CREDIT_SHIFT)) & PCIE_TX_CPL_FC_CREDIT_STATUS_OFF_TX_CPL_HEADER_FC_CREDIT_MASK)

#define PCIE_TX_CPL_FC_CREDIT_STATUS_OFF_RSVDP_20_MASK (0xFFF00000U)
#define PCIE_TX_CPL_FC_CREDIT_STATUS_OFF_RSVDP_20_SHIFT (20U)
/*! RSVDP_20 - Reserved for future use. */
#define PCIE_TX_CPL_FC_CREDIT_STATUS_OFF_RSVDP_20(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TX_CPL_FC_CREDIT_STATUS_OFF_RSVDP_20_SHIFT)) & PCIE_TX_CPL_FC_CREDIT_STATUS_OFF_RSVDP_20_MASK)
/*! @} */

/*! @name QUEUE_STATUS_OFF - Queue Status */
/*! @{ */

#define PCIE_QUEUE_STATUS_OFF_RX_TLP_FC_CREDIT_NON_RETURN_MASK (0x1U)
#define PCIE_QUEUE_STATUS_OFF_RX_TLP_FC_CREDIT_NON_RETURN_SHIFT (0U)
/*! RX_TLP_FC_CREDIT_NON_RETURN - Received TLP FC Credits Not Returned. Indicates that the
 *    controller has received a TLP but has not yet sent an UpdateFC DLLP indicating that the credits for
 *    that TLP have been restored by the receiver at the other end of the link.
 */
#define PCIE_QUEUE_STATUS_OFF_RX_TLP_FC_CREDIT_NON_RETURN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_QUEUE_STATUS_OFF_RX_TLP_FC_CREDIT_NON_RETURN_SHIFT)) & PCIE_QUEUE_STATUS_OFF_RX_TLP_FC_CREDIT_NON_RETURN_MASK)

#define PCIE_QUEUE_STATUS_OFF_TX_RETRY_BUFFER_NE_MASK (0x2U)
#define PCIE_QUEUE_STATUS_OFF_TX_RETRY_BUFFER_NE_SHIFT (1U)
/*! TX_RETRY_BUFFER_NE - Transmit Retry Buffer Not Empty. Indicates that there is data in the transmit retry buffer. */
#define PCIE_QUEUE_STATUS_OFF_TX_RETRY_BUFFER_NE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_QUEUE_STATUS_OFF_TX_RETRY_BUFFER_NE_SHIFT)) & PCIE_QUEUE_STATUS_OFF_TX_RETRY_BUFFER_NE_MASK)

#define PCIE_QUEUE_STATUS_OFF_RX_QUEUE_NON_EMPTY_MASK (0x4U)
#define PCIE_QUEUE_STATUS_OFF_RX_QUEUE_NON_EMPTY_SHIFT (2U)
/*! RX_QUEUE_NON_EMPTY - Receive Credit Queue Not Empty. Indicates there is data in one or more of the receive buffers. */
#define PCIE_QUEUE_STATUS_OFF_RX_QUEUE_NON_EMPTY(x) (((uint32_t)(((uint32_t)(x)) << PCIE_QUEUE_STATUS_OFF_RX_QUEUE_NON_EMPTY_SHIFT)) & PCIE_QUEUE_STATUS_OFF_RX_QUEUE_NON_EMPTY_MASK)

#define PCIE_QUEUE_STATUS_OFF_RX_QUEUE_OVERFLOW_MASK (0x8U)
#define PCIE_QUEUE_STATUS_OFF_RX_QUEUE_OVERFLOW_SHIFT (3U)
/*! RX_QUEUE_OVERFLOW - Receive Credit Queue Overflow. Indicates insufficient buffer space available to write to the P/NP/CPL credit queue. */
#define PCIE_QUEUE_STATUS_OFF_RX_QUEUE_OVERFLOW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_QUEUE_STATUS_OFF_RX_QUEUE_OVERFLOW_SHIFT)) & PCIE_QUEUE_STATUS_OFF_RX_QUEUE_OVERFLOW_MASK)

#define PCIE_QUEUE_STATUS_OFF_RSVDP_4_MASK       (0x1FF0U)
#define PCIE_QUEUE_STATUS_OFF_RSVDP_4_SHIFT      (4U)
/*! RSVDP_4 - Reserved for future use. */
#define PCIE_QUEUE_STATUS_OFF_RSVDP_4(x)         (((uint32_t)(((uint32_t)(x)) << PCIE_QUEUE_STATUS_OFF_RSVDP_4_SHIFT)) & PCIE_QUEUE_STATUS_OFF_RSVDP_4_MASK)

#define PCIE_QUEUE_STATUS_OFF_RX_SERIALIZATION_Q_NON_EMPTY_MASK (0x2000U)
#define PCIE_QUEUE_STATUS_OFF_RX_SERIALIZATION_Q_NON_EMPTY_SHIFT (13U)
/*! RX_SERIALIZATION_Q_NON_EMPTY - Receive Serialization Queue Not Empty. Indicates there is data in the serialization queue. */
#define PCIE_QUEUE_STATUS_OFF_RX_SERIALIZATION_Q_NON_EMPTY(x) (((uint32_t)(((uint32_t)(x)) << PCIE_QUEUE_STATUS_OFF_RX_SERIALIZATION_Q_NON_EMPTY_SHIFT)) & PCIE_QUEUE_STATUS_OFF_RX_SERIALIZATION_Q_NON_EMPTY_MASK)

#define PCIE_QUEUE_STATUS_OFF_RX_SERIALIZATION_Q_WRITE_ERR_MASK (0x4000U)
#define PCIE_QUEUE_STATUS_OFF_RX_SERIALIZATION_Q_WRITE_ERR_SHIFT (14U)
/*! RX_SERIALIZATION_Q_WRITE_ERR - Receive Serialization Queue Write Error. Indicates insufficient
 *    buffer space available to write to the serialization queue.
 */
#define PCIE_QUEUE_STATUS_OFF_RX_SERIALIZATION_Q_WRITE_ERR(x) (((uint32_t)(((uint32_t)(x)) << PCIE_QUEUE_STATUS_OFF_RX_SERIALIZATION_Q_WRITE_ERR_SHIFT)) & PCIE_QUEUE_STATUS_OFF_RX_SERIALIZATION_Q_WRITE_ERR_MASK)

#define PCIE_QUEUE_STATUS_OFF_RX_SERIALIZATION_Q_READ_ERR_MASK (0x8000U)
#define PCIE_QUEUE_STATUS_OFF_RX_SERIALIZATION_Q_READ_ERR_SHIFT (15U)
/*! RX_SERIALIZATION_Q_READ_ERR - Receive Serialization Read Error. Indicates the serialization queue has attempted to read an incorrectly formatted TLP. */
#define PCIE_QUEUE_STATUS_OFF_RX_SERIALIZATION_Q_READ_ERR(x) (((uint32_t)(((uint32_t)(x)) << PCIE_QUEUE_STATUS_OFF_RX_SERIALIZATION_Q_READ_ERR_SHIFT)) & PCIE_QUEUE_STATUS_OFF_RX_SERIALIZATION_Q_READ_ERR_MASK)

#define PCIE_QUEUE_STATUS_OFF_TIMER_MOD_FLOW_CONTROL_MASK (0x1FFF0000U)
#define PCIE_QUEUE_STATUS_OFF_TIMER_MOD_FLOW_CONTROL_SHIFT (16U)
/*! TIMER_MOD_FLOW_CONTROL - FC Latency Timer Override Value. When you set the "FC Latency Timer
 *    Override Enable" in this register, the value in this field will override the FC latency timer
 *    value that the controller calculates according to the PCIe specification. For more details, see
 *    "Flow Control". Note: This register field is sticky.
 */
#define PCIE_QUEUE_STATUS_OFF_TIMER_MOD_FLOW_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << PCIE_QUEUE_STATUS_OFF_TIMER_MOD_FLOW_CONTROL_SHIFT)) & PCIE_QUEUE_STATUS_OFF_TIMER_MOD_FLOW_CONTROL_MASK)

#define PCIE_QUEUE_STATUS_OFF_RSVDP_29_MASK      (0x60000000U)
#define PCIE_QUEUE_STATUS_OFF_RSVDP_29_SHIFT     (29U)
/*! RSVDP_29 - Reserved for future use. */
#define PCIE_QUEUE_STATUS_OFF_RSVDP_29(x)        (((uint32_t)(((uint32_t)(x)) << PCIE_QUEUE_STATUS_OFF_RSVDP_29_SHIFT)) & PCIE_QUEUE_STATUS_OFF_RSVDP_29_MASK)

#define PCIE_QUEUE_STATUS_OFF_TIMER_MOD_FLOW_CONTROL_EN_MASK (0x80000000U)
#define PCIE_QUEUE_STATUS_OFF_TIMER_MOD_FLOW_CONTROL_EN_SHIFT (31U)
/*! TIMER_MOD_FLOW_CONTROL_EN - FC Latency Timer Override Enable. When this bit is set, the value
 *    from the "FC Latency Timer Override Value" field in this register will override the FC latency
 *    timer value that the controller calculates according to the PCIe specification. Note: This
 *    register field is sticky.
 */
#define PCIE_QUEUE_STATUS_OFF_TIMER_MOD_FLOW_CONTROL_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_QUEUE_STATUS_OFF_TIMER_MOD_FLOW_CONTROL_EN_SHIFT)) & PCIE_QUEUE_STATUS_OFF_TIMER_MOD_FLOW_CONTROL_EN_MASK)
/*! @} */

/*! @name VC_TX_ARBI_1_OFF - VC Transmit Arbitration Register 1 */
/*! @{ */

#define PCIE_VC_TX_ARBI_1_OFF_WRR_WEIGHT_VC_0_MASK (0xFFU)
#define PCIE_VC_TX_ARBI_1_OFF_WRR_WEIGHT_VC_0_SHIFT (0U)
/*! WRR_WEIGHT_VC_0 - WRR Weight for VC0. Note: The access attributes of this field are as follows: - Dbi: R */
#define PCIE_VC_TX_ARBI_1_OFF_WRR_WEIGHT_VC_0(x) (((uint32_t)(((uint32_t)(x)) << PCIE_VC_TX_ARBI_1_OFF_WRR_WEIGHT_VC_0_SHIFT)) & PCIE_VC_TX_ARBI_1_OFF_WRR_WEIGHT_VC_0_MASK)
/*! @} */

/*! @name VC0_P_RX_Q_CTRL_OFF - Segmented-Buffer VC0 Posted Receive Queue Control. */
/*! @{ */

#define PCIE_VC0_P_RX_Q_CTRL_OFF_VC0_P_DATA_CREDIT_MASK (0xFFFU)
#define PCIE_VC0_P_RX_Q_CTRL_OFF_VC0_P_DATA_CREDIT_SHIFT (0U)
/*! VC0_P_DATA_CREDIT - VC0 Posted Data Credits. The number of initial posted data credits for VC0,
 *    used only in the segmented-buffer configuration. Note: The access attributes of this field are
 *    as follows: - Dbi: R (sticky) Note: This register field is sticky.
 */
#define PCIE_VC0_P_RX_Q_CTRL_OFF_VC0_P_DATA_CREDIT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_VC0_P_RX_Q_CTRL_OFF_VC0_P_DATA_CREDIT_SHIFT)) & PCIE_VC0_P_RX_Q_CTRL_OFF_VC0_P_DATA_CREDIT_MASK)

#define PCIE_VC0_P_RX_Q_CTRL_OFF_VC0_P_HEADER_CREDIT_MASK (0xFF000U)
#define PCIE_VC0_P_RX_Q_CTRL_OFF_VC0_P_HEADER_CREDIT_SHIFT (12U)
/*! VC0_P_HEADER_CREDIT - VC0 Posted Header Credits. The number of initial posted header credits for
 *    VC0, used only in the segmented-buffer configuration. Note: The access attributes of this
 *    field are as follows: - Dbi: R (sticky) Note: This register field is sticky.
 */
#define PCIE_VC0_P_RX_Q_CTRL_OFF_VC0_P_HEADER_CREDIT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_VC0_P_RX_Q_CTRL_OFF_VC0_P_HEADER_CREDIT_SHIFT)) & PCIE_VC0_P_RX_Q_CTRL_OFF_VC0_P_HEADER_CREDIT_MASK)

#define PCIE_VC0_P_RX_Q_CTRL_OFF_RESERVED4_MASK  (0x100000U)
#define PCIE_VC0_P_RX_Q_CTRL_OFF_RESERVED4_SHIFT (20U)
/*! RESERVED4 - Reserved. Note: This register field is sticky. */
#define PCIE_VC0_P_RX_Q_CTRL_OFF_RESERVED4(x)    (((uint32_t)(((uint32_t)(x)) << PCIE_VC0_P_RX_Q_CTRL_OFF_RESERVED4_SHIFT)) & PCIE_VC0_P_RX_Q_CTRL_OFF_RESERVED4_MASK)

#define PCIE_VC0_P_RX_Q_CTRL_OFF_VC0_P_TLP_Q_MODE_MASK (0xE00000U)
#define PCIE_VC0_P_RX_Q_CTRL_OFF_VC0_P_TLP_Q_MODE_SHIFT (21U)
/*! VC0_P_TLP_Q_MODE - Reserved. Note: This register field is sticky. */
#define PCIE_VC0_P_RX_Q_CTRL_OFF_VC0_P_TLP_Q_MODE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_VC0_P_RX_Q_CTRL_OFF_VC0_P_TLP_Q_MODE_SHIFT)) & PCIE_VC0_P_RX_Q_CTRL_OFF_VC0_P_TLP_Q_MODE_MASK)

#define PCIE_VC0_P_RX_Q_CTRL_OFF_VC0_P_HDR_SCALE_MASK (0x3000000U)
#define PCIE_VC0_P_RX_Q_CTRL_OFF_VC0_P_HDR_SCALE_SHIFT (24U)
/*! VC0_P_HDR_SCALE - VC0 Scale Posted Header Credites. Note: This register field is sticky. */
#define PCIE_VC0_P_RX_Q_CTRL_OFF_VC0_P_HDR_SCALE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_VC0_P_RX_Q_CTRL_OFF_VC0_P_HDR_SCALE_SHIFT)) & PCIE_VC0_P_RX_Q_CTRL_OFF_VC0_P_HDR_SCALE_MASK)

#define PCIE_VC0_P_RX_Q_CTRL_OFF_VC0_P_DATA_SCALE_MASK (0xC000000U)
#define PCIE_VC0_P_RX_Q_CTRL_OFF_VC0_P_DATA_SCALE_SHIFT (26U)
/*! VC0_P_DATA_SCALE - VC0 Scale Posted Data Credites. Note: This register field is sticky. */
#define PCIE_VC0_P_RX_Q_CTRL_OFF_VC0_P_DATA_SCALE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_VC0_P_RX_Q_CTRL_OFF_VC0_P_DATA_SCALE_SHIFT)) & PCIE_VC0_P_RX_Q_CTRL_OFF_VC0_P_DATA_SCALE_MASK)

#define PCIE_VC0_P_RX_Q_CTRL_OFF_RESERVED5_MASK  (0x30000000U)
#define PCIE_VC0_P_RX_Q_CTRL_OFF_RESERVED5_SHIFT (28U)
/*! RESERVED5 - Reserved. Note: This register field is sticky. */
#define PCIE_VC0_P_RX_Q_CTRL_OFF_RESERVED5(x)    (((uint32_t)(((uint32_t)(x)) << PCIE_VC0_P_RX_Q_CTRL_OFF_RESERVED5_SHIFT)) & PCIE_VC0_P_RX_Q_CTRL_OFF_RESERVED5_MASK)

#define PCIE_VC0_P_RX_Q_CTRL_OFF_TLP_TYPE_ORDERING_VC0_MASK (0x40000000U)
#define PCIE_VC0_P_RX_Q_CTRL_OFF_TLP_TYPE_ORDERING_VC0_SHIFT (30U)
/*! TLP_TYPE_ORDERING_VC0 - TLP Type Ordering for VC0. Determines the TLP type ordering rule for VC0
 *    receive queues, used only in the segmented-buffer configuration: - 1: PCIe ordering rules
 *    (recommended) - 0: Strict ordering: posted, completion, then non-posted Note: This register field
 *    is sticky.
 */
#define PCIE_VC0_P_RX_Q_CTRL_OFF_TLP_TYPE_ORDERING_VC0(x) (((uint32_t)(((uint32_t)(x)) << PCIE_VC0_P_RX_Q_CTRL_OFF_TLP_TYPE_ORDERING_VC0_SHIFT)) & PCIE_VC0_P_RX_Q_CTRL_OFF_TLP_TYPE_ORDERING_VC0_MASK)

#define PCIE_VC0_P_RX_Q_CTRL_OFF_VC_ORDERING_RX_Q_MASK (0x80000000U)
#define PCIE_VC0_P_RX_Q_CTRL_OFF_VC_ORDERING_RX_Q_SHIFT (31U)
/*! VC_ORDERING_RX_Q - VC Ordering for Receive Queues. Determines the VC ordering rule for the
 *    receive queues, used only in the segmented-buffer configuration: - 1: Strict ordering, higher
 *    numbered VCs have higher priority - 0: Round robin Note: This register field is sticky.
 */
#define PCIE_VC0_P_RX_Q_CTRL_OFF_VC_ORDERING_RX_Q(x) (((uint32_t)(((uint32_t)(x)) << PCIE_VC0_P_RX_Q_CTRL_OFF_VC_ORDERING_RX_Q_SHIFT)) & PCIE_VC0_P_RX_Q_CTRL_OFF_VC_ORDERING_RX_Q_MASK)
/*! @} */

/*! @name VC0_NP_RX_Q_CTRL_OFF - Segmented-Buffer VC0 Non-Posted Receive Queue Control. */
/*! @{ */

#define PCIE_VC0_NP_RX_Q_CTRL_OFF_VC0_NP_DATA_CREDIT_MASK (0xFFFU)
#define PCIE_VC0_NP_RX_Q_CTRL_OFF_VC0_NP_DATA_CREDIT_SHIFT (0U)
/*! VC0_NP_DATA_CREDIT - VC0 Non-Posted Data Credits. The number of initial non-posted data credits
 *    for VC0, used only in the segmented-buffer configuration. Note: The access attributes of this
 *    field are as follows: - Dbi: R (sticky) Note: This register field is sticky.
 */
#define PCIE_VC0_NP_RX_Q_CTRL_OFF_VC0_NP_DATA_CREDIT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_VC0_NP_RX_Q_CTRL_OFF_VC0_NP_DATA_CREDIT_SHIFT)) & PCIE_VC0_NP_RX_Q_CTRL_OFF_VC0_NP_DATA_CREDIT_MASK)

#define PCIE_VC0_NP_RX_Q_CTRL_OFF_VC0_NP_HEADER_CREDIT_MASK (0xFF000U)
#define PCIE_VC0_NP_RX_Q_CTRL_OFF_VC0_NP_HEADER_CREDIT_SHIFT (12U)
/*! VC0_NP_HEADER_CREDIT - VC0 Non-Posted Header Credits. The number of initial non-posted header
 *    credits for VC0, used only in the segmented-buffer configuration. Note: The access attributes of
 *    this field are as follows: - Dbi: R (sticky) Note: This register field is sticky.
 */
#define PCIE_VC0_NP_RX_Q_CTRL_OFF_VC0_NP_HEADER_CREDIT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_VC0_NP_RX_Q_CTRL_OFF_VC0_NP_HEADER_CREDIT_SHIFT)) & PCIE_VC0_NP_RX_Q_CTRL_OFF_VC0_NP_HEADER_CREDIT_MASK)

#define PCIE_VC0_NP_RX_Q_CTRL_OFF_RESERVED6_MASK (0x100000U)
#define PCIE_VC0_NP_RX_Q_CTRL_OFF_RESERVED6_SHIFT (20U)
/*! RESERVED6 - Reserved. Note: This register field is sticky. */
#define PCIE_VC0_NP_RX_Q_CTRL_OFF_RESERVED6(x)   (((uint32_t)(((uint32_t)(x)) << PCIE_VC0_NP_RX_Q_CTRL_OFF_RESERVED6_SHIFT)) & PCIE_VC0_NP_RX_Q_CTRL_OFF_RESERVED6_MASK)

#define PCIE_VC0_NP_RX_Q_CTRL_OFF_VC0_NP_TLP_Q_MODE_MASK (0xE00000U)
#define PCIE_VC0_NP_RX_Q_CTRL_OFF_VC0_NP_TLP_Q_MODE_SHIFT (21U)
/*! VC0_NP_TLP_Q_MODE - Reserved. Note: This register field is sticky. */
#define PCIE_VC0_NP_RX_Q_CTRL_OFF_VC0_NP_TLP_Q_MODE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_VC0_NP_RX_Q_CTRL_OFF_VC0_NP_TLP_Q_MODE_SHIFT)) & PCIE_VC0_NP_RX_Q_CTRL_OFF_VC0_NP_TLP_Q_MODE_MASK)

#define PCIE_VC0_NP_RX_Q_CTRL_OFF_VC0_NP_HDR_SCALE_MASK (0x3000000U)
#define PCIE_VC0_NP_RX_Q_CTRL_OFF_VC0_NP_HDR_SCALE_SHIFT (24U)
/*! VC0_NP_HDR_SCALE - VC0 Scale Non-Posted Header Credites. Note: This register field is sticky. */
#define PCIE_VC0_NP_RX_Q_CTRL_OFF_VC0_NP_HDR_SCALE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_VC0_NP_RX_Q_CTRL_OFF_VC0_NP_HDR_SCALE_SHIFT)) & PCIE_VC0_NP_RX_Q_CTRL_OFF_VC0_NP_HDR_SCALE_MASK)

#define PCIE_VC0_NP_RX_Q_CTRL_OFF_VC0_NP_DATA_SCALE_MASK (0xC000000U)
#define PCIE_VC0_NP_RX_Q_CTRL_OFF_VC0_NP_DATA_SCALE_SHIFT (26U)
/*! VC0_NP_DATA_SCALE - VC0 Scale Non-Posted Data Credites. Note: This register field is sticky. */
#define PCIE_VC0_NP_RX_Q_CTRL_OFF_VC0_NP_DATA_SCALE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_VC0_NP_RX_Q_CTRL_OFF_VC0_NP_DATA_SCALE_SHIFT)) & PCIE_VC0_NP_RX_Q_CTRL_OFF_VC0_NP_DATA_SCALE_MASK)

#define PCIE_VC0_NP_RX_Q_CTRL_OFF_RESERVED7_MASK (0xF0000000U)
#define PCIE_VC0_NP_RX_Q_CTRL_OFF_RESERVED7_SHIFT (28U)
/*! RESERVED7 - Reserved. Note: This register field is sticky. */
#define PCIE_VC0_NP_RX_Q_CTRL_OFF_RESERVED7(x)   (((uint32_t)(((uint32_t)(x)) << PCIE_VC0_NP_RX_Q_CTRL_OFF_RESERVED7_SHIFT)) & PCIE_VC0_NP_RX_Q_CTRL_OFF_RESERVED7_MASK)
/*! @} */

/*! @name VC0_CPL_RX_Q_CTRL_OFF - Segmented-Buffer VC0 Completion Receive Queue Control. */
/*! @{ */

#define PCIE_VC0_CPL_RX_Q_CTRL_OFF_VC0_CPL_DATA_CREDIT_MASK (0xFFFU)
#define PCIE_VC0_CPL_RX_Q_CTRL_OFF_VC0_CPL_DATA_CREDIT_SHIFT (0U)
/*! VC0_CPL_DATA_CREDIT - VC0 Completion Data Credits. The number of initial Completion data credits
 *    for VC0, used only in the segmented-buffer configuration. Note: The access attributes of this
 *    field are as follows: - Dbi: R (sticky) Note: This register field is sticky.
 */
#define PCIE_VC0_CPL_RX_Q_CTRL_OFF_VC0_CPL_DATA_CREDIT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_VC0_CPL_RX_Q_CTRL_OFF_VC0_CPL_DATA_CREDIT_SHIFT)) & PCIE_VC0_CPL_RX_Q_CTRL_OFF_VC0_CPL_DATA_CREDIT_MASK)

#define PCIE_VC0_CPL_RX_Q_CTRL_OFF_VC0_CPL_HEADER_CREDIT_MASK (0xFF000U)
#define PCIE_VC0_CPL_RX_Q_CTRL_OFF_VC0_CPL_HEADER_CREDIT_SHIFT (12U)
/*! VC0_CPL_HEADER_CREDIT - VC0 Completion Header Credits. The number of initial Completion header
 *    credits for VC0, used only in the segmented-buffer configuration. Note: The access attributes
 *    of this field are as follows: - Dbi: R (sticky) Note: This register field is sticky.
 */
#define PCIE_VC0_CPL_RX_Q_CTRL_OFF_VC0_CPL_HEADER_CREDIT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_VC0_CPL_RX_Q_CTRL_OFF_VC0_CPL_HEADER_CREDIT_SHIFT)) & PCIE_VC0_CPL_RX_Q_CTRL_OFF_VC0_CPL_HEADER_CREDIT_MASK)

#define PCIE_VC0_CPL_RX_Q_CTRL_OFF_RESERVED8_MASK (0x100000U)
#define PCIE_VC0_CPL_RX_Q_CTRL_OFF_RESERVED8_SHIFT (20U)
/*! RESERVED8 - Reserved. Note: This register field is sticky. */
#define PCIE_VC0_CPL_RX_Q_CTRL_OFF_RESERVED8(x)  (((uint32_t)(((uint32_t)(x)) << PCIE_VC0_CPL_RX_Q_CTRL_OFF_RESERVED8_SHIFT)) & PCIE_VC0_CPL_RX_Q_CTRL_OFF_RESERVED8_MASK)

#define PCIE_VC0_CPL_RX_Q_CTRL_OFF_VC0_CPL_TLP_Q_MODE_MASK (0xE00000U)
#define PCIE_VC0_CPL_RX_Q_CTRL_OFF_VC0_CPL_TLP_Q_MODE_SHIFT (21U)
/*! VC0_CPL_TLP_Q_MODE - Reserved. Note: This register field is sticky. */
#define PCIE_VC0_CPL_RX_Q_CTRL_OFF_VC0_CPL_TLP_Q_MODE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_VC0_CPL_RX_Q_CTRL_OFF_VC0_CPL_TLP_Q_MODE_SHIFT)) & PCIE_VC0_CPL_RX_Q_CTRL_OFF_VC0_CPL_TLP_Q_MODE_MASK)

#define PCIE_VC0_CPL_RX_Q_CTRL_OFF_VC0_CPL_HDR_SCALE_MASK (0x3000000U)
#define PCIE_VC0_CPL_RX_Q_CTRL_OFF_VC0_CPL_HDR_SCALE_SHIFT (24U)
/*! VC0_CPL_HDR_SCALE - VC0 Scale CPL Header Credites. Note: This register field is sticky. */
#define PCIE_VC0_CPL_RX_Q_CTRL_OFF_VC0_CPL_HDR_SCALE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_VC0_CPL_RX_Q_CTRL_OFF_VC0_CPL_HDR_SCALE_SHIFT)) & PCIE_VC0_CPL_RX_Q_CTRL_OFF_VC0_CPL_HDR_SCALE_MASK)

#define PCIE_VC0_CPL_RX_Q_CTRL_OFF_VC0_CPL_DATA_SCALE_MASK (0xC000000U)
#define PCIE_VC0_CPL_RX_Q_CTRL_OFF_VC0_CPL_DATA_SCALE_SHIFT (26U)
/*! VC0_CPL_DATA_SCALE - VC0 Scale CPL Data Credites. Note: This register field is sticky. */
#define PCIE_VC0_CPL_RX_Q_CTRL_OFF_VC0_CPL_DATA_SCALE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_VC0_CPL_RX_Q_CTRL_OFF_VC0_CPL_DATA_SCALE_SHIFT)) & PCIE_VC0_CPL_RX_Q_CTRL_OFF_VC0_CPL_DATA_SCALE_MASK)

#define PCIE_VC0_CPL_RX_Q_CTRL_OFF_RESERVED9_MASK (0xF0000000U)
#define PCIE_VC0_CPL_RX_Q_CTRL_OFF_RESERVED9_SHIFT (28U)
/*! RESERVED9 - Reserved. Note: This register field is sticky. */
#define PCIE_VC0_CPL_RX_Q_CTRL_OFF_RESERVED9(x)  (((uint32_t)(((uint32_t)(x)) << PCIE_VC0_CPL_RX_Q_CTRL_OFF_RESERVED9_SHIFT)) & PCIE_VC0_CPL_RX_Q_CTRL_OFF_RESERVED9_MASK)
/*! @} */

/*! @name GEN2_CTRL_OFF - Link Width and Speed Change Control Register. */
/*! @{ */

#define PCIE_GEN2_CTRL_OFF_FAST_TRAINING_SEQ_MASK (0xFFU)
#define PCIE_GEN2_CTRL_OFF_FAST_TRAINING_SEQ_SHIFT (0U)
/*! FAST_TRAINING_SEQ - Sets the Number of Fast Training Sequences (N_FTS) that the controller
 *    advertises as its N_FTS during Gen2 or Gen3 link training. This value is used to inform the link
 *    partner about the PHY's ability to recover synchronization after a low power state. The number
 *    should be provided by the PHY vendor. Do not set N_FTS to zero; doing so can cause the LTSSM to
 *    go into the recovery state when exiting from L0s. This field is reserved (fixed to '0') for
 *    M-PCIe. Note: The access attributes of this field are as follows: - Dbi: R/W (sticky) Note:
 *    This register field is sticky.
 */
#define PCIE_GEN2_CTRL_OFF_FAST_TRAINING_SEQ(x)  (((uint32_t)(((uint32_t)(x)) << PCIE_GEN2_CTRL_OFF_FAST_TRAINING_SEQ_SHIFT)) & PCIE_GEN2_CTRL_OFF_FAST_TRAINING_SEQ_MASK)

#define PCIE_GEN2_CTRL_OFF_NUM_OF_LANES_MASK     (0x1F00U)
#define PCIE_GEN2_CTRL_OFF_NUM_OF_LANES_SHIFT    (8U)
/*! NUM_OF_LANES - Predetermined Number of Lanes. Defines the number of lanes which are connected
 *    and not bad. Used to limit the effective link width to ignore 'broken" or "unused" lanes that
 *    detect a receiver. Indicates the number of lanes to check for exit from Electrical Idle in
 *    Polling.Active and L2.Idle. It is possible that the LTSSM might detect a receiver on a bad or
 *    broken lane during the Detect Substate. However, it is also possible that such a lane might also
 *    fail to exit Electrical Idle and therefore prevent a valid link from being configured. This
 *    value is referred to as the "Predetermined Number of Lanes" in section 4.2.6.2.1 of the PCI
 *    Express Base 3.0 Specification, revision 1.0. Encoding is as follows: - 0x01: 1 lane - 0x02: 2 lanes
 *    - 0x03: 3 lanes - .. When you have unused lanes in your system, then you must change the
 *    value in this register to reflect the number of lanes. You must also change the value in the "Link
 *    Mode Enable" field of PORT_LINK_CTRL_OFF. The value in this register is normally the same as
 *    the encoded value in PORT_LINK_CTRL_OFF. If you find that one of your used lanes is bad then
 *    you must reduce the value in this register. For more information, see "How to Tie Off Unused
 *    Lanes." For information on upsizing and downsizing the link width, see "Link Establishment."
 *    This field is reserved (fixed to '0') for M-PCIe. Note: The access attributes of this field are
 *    as follows: - Dbi: R/W (sticky) Note: This register field is sticky.
 */
#define PCIE_GEN2_CTRL_OFF_NUM_OF_LANES(x)       (((uint32_t)(((uint32_t)(x)) << PCIE_GEN2_CTRL_OFF_NUM_OF_LANES_SHIFT)) & PCIE_GEN2_CTRL_OFF_NUM_OF_LANES_MASK)

#define PCIE_GEN2_CTRL_OFF_PRE_DET_LANE_MASK     (0xE000U)
#define PCIE_GEN2_CTRL_OFF_PRE_DET_LANE_SHIFT    (13U)
/*! PRE_DET_LANE - Predetermined Lane for Auto Flip. This field defines which physical lane is
 *    connected to logical Lane0 by the flip operation performed in Detect. Allowed values are: - 3'b000:
 *    Connect logical Lane0 to physical lane 0 or CX_NL-1 or CX_NL/2-1 or CX_NL/4-1 or CX_NL/8-1,
 *    depending on which lane is detected - 3'b001: Connect logical Lane0 to physical lane 1 -
 *    3'b010: Connect logical Lane0 to physical lane 3 - 3'b011: Connect logical Lane0 to physical lane 7
 *    - 3'b100: Connect logical Lane0 to physical lane 15 This field is used to restrict the
 *    receiver detect procedure to a particular lane when the default detect and polling procedure
 *    performed on all lanes cannot be successful. A notable example of when it is useful to program this
 *    field to a value different from the default, is when a lane is asymmetrically broken, that is,
 *    it is detected in Detect LTSSM state but it cannot exit Electrical Idle in Polling LTSSM state.
 *    Note: This field is reserved (fixed to '0') for M-PCIe. Note: The access attributes of this
 *    field are as follows: - Dbi: R/W (sticky) Note: This register field is sticky.
 */
#define PCIE_GEN2_CTRL_OFF_PRE_DET_LANE(x)       (((uint32_t)(((uint32_t)(x)) << PCIE_GEN2_CTRL_OFF_PRE_DET_LANE_SHIFT)) & PCIE_GEN2_CTRL_OFF_PRE_DET_LANE_MASK)

#define PCIE_GEN2_CTRL_OFF_AUTO_LANE_FLIP_CTRL_EN_MASK (0x10000U)
#define PCIE_GEN2_CTRL_OFF_AUTO_LANE_FLIP_CTRL_EN_SHIFT (16U)
/*! AUTO_LANE_FLIP_CTRL_EN - Enable Auto flipping of the lanes. You must set the
 *    CX_AUTO_LANE_FLIP_CTRL_EN configuration parameter to include the hardware for this feature in the controller. For
 *    more details, see the 'Lane Reversal' appendix in the Databook. This field is reserved (fixed
 *    to '0') for M-PCIe. Note: The access attributes of this field are as follows: - Dbi: R/W
 *    (sticky) Note: This register field is sticky.
 */
#define PCIE_GEN2_CTRL_OFF_AUTO_LANE_FLIP_CTRL_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_GEN2_CTRL_OFF_AUTO_LANE_FLIP_CTRL_EN_SHIFT)) & PCIE_GEN2_CTRL_OFF_AUTO_LANE_FLIP_CTRL_EN_MASK)

#define PCIE_GEN2_CTRL_OFF_DIRECT_SPEED_CHANGE_MASK (0x20000U)
#define PCIE_GEN2_CTRL_OFF_DIRECT_SPEED_CHANGE_SHIFT (17U)
/*! DIRECT_SPEED_CHANGE - Directed Speed Change. Writing "1" to this field instructs the LTSSM to
 *    initiate a speed change to Gen2 or Gen3 after the link is initialized at Gen1 speed. When the
 *    speed change occurs, the controller will clear the contents of this field; and a read to this
 *    field by your software will return a "0". To manually initiate the speed change: - Write to
 *    LINK_CONTROL2_LINK_STATUS2_REG . PCIE_CAP_TARGET_LINK_SPEED in the local device - Deassert this
 *    field - Assert this field If you set the default of this field using the
 *    DEFAULT_GEN2_SPEED_CHANGE configuration parameter to "1", then the speed change is initiated automatically after link
 *    up, and the controller clears the contents of this field. If you want to prevent this
 *    automatic speed change, then write a lower speed value to the Target Link Speed field of the Link
 *    Control 2 register (LINK_CONTROL2_LINK_STATUS2_OFF . PCIE_CAP_TARGET_LINK_SPEED) through the DBI
 *    before link up. This field is reserved (fixed to '0') for M-PCIe. Note: The access attributes
 *    of this field are as follows: - Dbi: R/W
 */
#define PCIE_GEN2_CTRL_OFF_DIRECT_SPEED_CHANGE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_GEN2_CTRL_OFF_DIRECT_SPEED_CHANGE_SHIFT)) & PCIE_GEN2_CTRL_OFF_DIRECT_SPEED_CHANGE_MASK)

#define PCIE_GEN2_CTRL_OFF_CONFIG_PHY_TX_CHANGE_MASK (0x40000U)
#define PCIE_GEN2_CTRL_OFF_CONFIG_PHY_TX_CHANGE_SHIFT (18U)
/*! CONFIG_PHY_TX_CHANGE - Config PHY Tx Swing. Controls the PHY transmitter voltage swing level.
 *    The controller drives the mac_phy_txswing output from this register bit field. - 0: Full Swing -
 *    1: Low Swing This field is reserved (fixed to '0') for M-PCIe. Note: The access attributes of
 *    this field are as follows: - Dbi: R/W (sticky) Note: This register field is sticky.
 */
#define PCIE_GEN2_CTRL_OFF_CONFIG_PHY_TX_CHANGE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_GEN2_CTRL_OFF_CONFIG_PHY_TX_CHANGE_SHIFT)) & PCIE_GEN2_CTRL_OFF_CONFIG_PHY_TX_CHANGE_MASK)

#define PCIE_GEN2_CTRL_OFF_CONFIG_TX_COMP_RX_MASK (0x80000U)
#define PCIE_GEN2_CTRL_OFF_CONFIG_TX_COMP_RX_SHIFT (19U)
/*! CONFIG_TX_COMP_RX - Config Tx Compliance Receive Bit. When set to 1, signals LTSSM to transmit
 *    TS ordered sets with the compliance receive bit assert (equal to "1"). This field is reserved
 *    (fixed to '0') for M-PCIe. Note: The access attributes of this field are as follows: - Dbi: R/W
 *    (sticky) Note: This register field is sticky.
 */
#define PCIE_GEN2_CTRL_OFF_CONFIG_TX_COMP_RX(x)  (((uint32_t)(((uint32_t)(x)) << PCIE_GEN2_CTRL_OFF_CONFIG_TX_COMP_RX_SHIFT)) & PCIE_GEN2_CTRL_OFF_CONFIG_TX_COMP_RX_MASK)

#define PCIE_GEN2_CTRL_OFF_SEL_DEEMPHASIS_MASK   (0x100000U)
#define PCIE_GEN2_CTRL_OFF_SEL_DEEMPHASIS_SHIFT  (20U)
/*! SEL_DEEMPHASIS - Used to set the de-emphasis level for upstream ports. This bit selects the
 *    level of de-emphasis the link operates at. - 0: -6 dB - 1: -3.5 dB This field is reserved (fixed
 *    to '0') for M-PCIe. Note: The access attributes of this field are as follows: - Dbi: R/W
 *    (sticky) Note: This register field is sticky.
 */
#define PCIE_GEN2_CTRL_OFF_SEL_DEEMPHASIS(x)     (((uint32_t)(((uint32_t)(x)) << PCIE_GEN2_CTRL_OFF_SEL_DEEMPHASIS_SHIFT)) & PCIE_GEN2_CTRL_OFF_SEL_DEEMPHASIS_MASK)

#define PCIE_GEN2_CTRL_OFF_GEN1_EI_INFERENCE_MASK (0x200000U)
#define PCIE_GEN2_CTRL_OFF_GEN1_EI_INFERENCE_SHIFT (21U)
/*! GEN1_EI_INFERENCE - Electrical Idle Inference Mode at Gen1 Rate. Programmable mode to determine
 *    inferred electrical idle (EI) in Recovery.Speed or Loopback.Active (as slave) state at Gen1
 *    speed by looking for a "1" value on RxElecIdle instead of looking for a "0" on RxValid. If the
 *    PHY fails to deassert the RxValid signal in Recovery.Speed or Loopback.Active (because of
 *    corrupted EIOS for example), then EI cannot be inferred successfully in the controller by just
 *    detecting the condition RxValid=0. - 0: Use RxElecIdle signal to infer Electrical Idle - 1: Use
 *    RxValid signal to infer Electrical Idle Note: This register field is sticky.
 */
#define PCIE_GEN2_CTRL_OFF_GEN1_EI_INFERENCE(x)  (((uint32_t)(((uint32_t)(x)) << PCIE_GEN2_CTRL_OFF_GEN1_EI_INFERENCE_SHIFT)) & PCIE_GEN2_CTRL_OFF_GEN1_EI_INFERENCE_MASK)

#define PCIE_GEN2_CTRL_OFF_RSVDP_22_MASK         (0xFFC00000U)
#define PCIE_GEN2_CTRL_OFF_RSVDP_22_SHIFT        (22U)
/*! RSVDP_22 - Reserved for future use. */
#define PCIE_GEN2_CTRL_OFF_RSVDP_22(x)           (((uint32_t)(((uint32_t)(x)) << PCIE_GEN2_CTRL_OFF_RSVDP_22_SHIFT)) & PCIE_GEN2_CTRL_OFF_RSVDP_22_MASK)
/*! @} */

/*! @name PHY_STATUS_OFF - PHY Status Register. */
/*! @{ */

#define PCIE_PHY_STATUS_OFF_PHY_STATUS_MASK      (0xFFFFFFFFU)
#define PCIE_PHY_STATUS_OFF_PHY_STATUS_SHIFT     (0U)
/*! PHY_STATUS - PHY Status. Data received directly from the phy_cfg_status bus. These is a GPIO
 *    register reflecting the values on the static phy_cfg_status input signals. The usage is left
 *    completely to the user and does not in any way influence controller functionality. You can use it
 *    for any static sideband status signalling requirements that you have for your PHY. This field
 *    is reserved (fixed to '0') for M-PCIe. Note: This register field is sticky.
 */
#define PCIE_PHY_STATUS_OFF_PHY_STATUS(x)        (((uint32_t)(((uint32_t)(x)) << PCIE_PHY_STATUS_OFF_PHY_STATUS_SHIFT)) & PCIE_PHY_STATUS_OFF_PHY_STATUS_MASK)
/*! @} */

/*! @name PHY_CONTROL_OFF - PHY Control Register. */
/*! @{ */

#define PCIE_PHY_CONTROL_OFF_PHY_CONTROL_MASK    (0xFFFFFFFFU)
#define PCIE_PHY_CONTROL_OFF_PHY_CONTROL_SHIFT   (0U)
/*! PHY_CONTROL - PHY Control. Data sent directly to the cfg_phy_control bus. These is a GPIO
 *    register driving the values on the static cfg_phy_control output signals. The usage is left
 *    completely to the user and does not in any way influence controller functionality. You can use it for
 *    any static sideband control signalling requirements that you have for your PHY. This field is
 *    reserved (fixed to '0') for M-PCIe. Note: This register field is sticky.
 */
#define PCIE_PHY_CONTROL_OFF_PHY_CONTROL(x)      (((uint32_t)(((uint32_t)(x)) << PCIE_PHY_CONTROL_OFF_PHY_CONTROL_SHIFT)) & PCIE_PHY_CONTROL_OFF_PHY_CONTROL_MASK)
/*! @} */

/*! @name TRGT_MAP_CTRL_OFF - Programmable Target Map Control Register. */
/*! @{ */

#define PCIE_TRGT_MAP_CTRL_OFF_TARGET_MAP_PF_MASK (0x3FU)
#define PCIE_TRGT_MAP_CTRL_OFF_TARGET_MAP_PF_SHIFT (0U)
/*! TARGET_MAP_PF - Target Values for each BAR on the PF Function selected by the index number. This
 *    register does not respect the Byte Enable setting. any write will affect all register bits.
 */
#define PCIE_TRGT_MAP_CTRL_OFF_TARGET_MAP_PF(x)  (((uint32_t)(((uint32_t)(x)) << PCIE_TRGT_MAP_CTRL_OFF_TARGET_MAP_PF_SHIFT)) & PCIE_TRGT_MAP_CTRL_OFF_TARGET_MAP_PF_MASK)

#define PCIE_TRGT_MAP_CTRL_OFF_TARGET_MAP_ROM_MASK (0x40U)
#define PCIE_TRGT_MAP_CTRL_OFF_TARGET_MAP_ROM_SHIFT (6U)
/*! TARGET_MAP_ROM - Target Value for the ROM page of the PF Function selected by the index number.
 *    This register does not respect the Byte Enable setting. any write will affect all register
 *    bits.
 */
#define PCIE_TRGT_MAP_CTRL_OFF_TARGET_MAP_ROM(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TRGT_MAP_CTRL_OFF_TARGET_MAP_ROM_SHIFT)) & PCIE_TRGT_MAP_CTRL_OFF_TARGET_MAP_ROM_MASK)

#define PCIE_TRGT_MAP_CTRL_OFF_TARGET_MAP_RESERVED_13_15_MASK (0xE000U)
#define PCIE_TRGT_MAP_CTRL_OFF_TARGET_MAP_RESERVED_13_15_SHIFT (13U)
/*! TARGET_MAP_RESERVED_13_15 - Reserved. Note: The access attributes of this field are as follows: - Dbi: R (sticky) */
#define PCIE_TRGT_MAP_CTRL_OFF_TARGET_MAP_RESERVED_13_15(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TRGT_MAP_CTRL_OFF_TARGET_MAP_RESERVED_13_15_SHIFT)) & PCIE_TRGT_MAP_CTRL_OFF_TARGET_MAP_RESERVED_13_15_MASK)

#define PCIE_TRGT_MAP_CTRL_OFF_TARGET_MAP_INDEX_MASK (0x1F0000U)
#define PCIE_TRGT_MAP_CTRL_OFF_TARGET_MAP_INDEX_SHIFT (16U)
/*! TARGET_MAP_INDEX - The number of the PF Function on which the Target Values are set. This
 *    register does not respect the Byte Enable setting. any write will affect all register bits.
 */
#define PCIE_TRGT_MAP_CTRL_OFF_TARGET_MAP_INDEX(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TRGT_MAP_CTRL_OFF_TARGET_MAP_INDEX_SHIFT)) & PCIE_TRGT_MAP_CTRL_OFF_TARGET_MAP_INDEX_MASK)

#define PCIE_TRGT_MAP_CTRL_OFF_TARGET_MAP_RESERVED_21_31_MASK (0xFFE00000U)
#define PCIE_TRGT_MAP_CTRL_OFF_TARGET_MAP_RESERVED_21_31_SHIFT (21U)
/*! TARGET_MAP_RESERVED_21_31 - Reserved. Note: The access attributes of this field are as follows: - Dbi: R (sticky) */
#define PCIE_TRGT_MAP_CTRL_OFF_TARGET_MAP_RESERVED_21_31(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TRGT_MAP_CTRL_OFF_TARGET_MAP_RESERVED_21_31_SHIFT)) & PCIE_TRGT_MAP_CTRL_OFF_TARGET_MAP_RESERVED_21_31_MASK)
/*! @} */

/*! @name MSI_CTRL_ADDR_OFF - Integrated MSI Reception Module (iMRM) Address Register. */
/*! @{ */

#define PCIE_MSI_CTRL_ADDR_OFF_MSI_CTRL_ADDR_MASK (0xFFFFFFFFU)
#define PCIE_MSI_CTRL_ADDR_OFF_MSI_CTRL_ADDR_SHIFT (0U)
/*! MSI_CTRL_ADDR - Integrated MSI Reception Module Address. System specified address for MSI memory
 *    write transaction termination. Within the AXI Bridge, every received Memory Write request is
 *    examined to see if it targets the MSI Address that has been specified in this register; and
 *    also to see if it satisfies the definition of an MSI interrupt request. When these conditions
 *    are satisfied the Memory Write request is marked as an MSI request. Note: This register field is
 *    sticky.
 */
#define PCIE_MSI_CTRL_ADDR_OFF_MSI_CTRL_ADDR(x)  (((uint32_t)(((uint32_t)(x)) << PCIE_MSI_CTRL_ADDR_OFF_MSI_CTRL_ADDR_SHIFT)) & PCIE_MSI_CTRL_ADDR_OFF_MSI_CTRL_ADDR_MASK)
/*! @} */

/*! @name MSI_CTRL_UPPER_ADDR_OFF - Integrated MSI Reception Module Upper Address Register. */
/*! @{ */

#define PCIE_MSI_CTRL_UPPER_ADDR_OFF_MSI_CTRL_UPPER_ADDR_MASK (0xFFFFFFFFU)
#define PCIE_MSI_CTRL_UPPER_ADDR_OFF_MSI_CTRL_UPPER_ADDR_SHIFT (0U)
/*! MSI_CTRL_UPPER_ADDR - Integrated MSI Reception Module Upper Address. System specified upper
 *    address for MSI memory write transaction termination. Allows functions to support a 64-bit MSI
 *    address. Note: This register field is sticky.
 */
#define PCIE_MSI_CTRL_UPPER_ADDR_OFF_MSI_CTRL_UPPER_ADDR(x) (((uint32_t)(((uint32_t)(x)) << PCIE_MSI_CTRL_UPPER_ADDR_OFF_MSI_CTRL_UPPER_ADDR_SHIFT)) & PCIE_MSI_CTRL_UPPER_ADDR_OFF_MSI_CTRL_UPPER_ADDR_MASK)
/*! @} */

/*! @name MSI_CTRL_INT_0_EN_OFF - Integrated MSI Reception Module Interrupt#i Enable Register. */
/*! @{ */

#define PCIE_MSI_CTRL_INT_0_EN_OFF_MSI_CTRL_INT_0_EN_MASK (0xFFFFFFFFU)
#define PCIE_MSI_CTRL_INT_0_EN_OFF_MSI_CTRL_INT_0_EN_SHIFT (0U)
/*! MSI_CTRL_INT_0_EN - MSI Interrupt#i Enable. Specifies which interrupts are enabled. When an MSI
 *    is received from a disabled interrupt, no status bit gets set in MSI controller interrupt
 *    status register. Each bit corresponds to a single MSI Interrupt Vector. Note: This register field
 *    is sticky.
 */
#define PCIE_MSI_CTRL_INT_0_EN_OFF_MSI_CTRL_INT_0_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_MSI_CTRL_INT_0_EN_OFF_MSI_CTRL_INT_0_EN_SHIFT)) & PCIE_MSI_CTRL_INT_0_EN_OFF_MSI_CTRL_INT_0_EN_MASK)
/*! @} */

/*! @name MSI_CTRL_INT_0_MASK_OFF - Integrated MSI Reception Module Interrupt#i Mask Register. */
/*! @{ */

#define PCIE_MSI_CTRL_INT_0_MASK_OFF_MSI_CTRL_INT_0_MASK_MASK (0xFFFFFFFFU)
#define PCIE_MSI_CTRL_INT_0_MASK_OFF_MSI_CTRL_INT_0_MASK_SHIFT (0U)
/*! MSI_CTRL_INT_0_MASK - MSI Interrupt#i Mask. Allows enabled interrupts to be masked. When an MSI
 *    is received for a masked interrupt, the corresponding status bit gets set in the interrupt
 *    status register but the msi_ctrl_int output is not set HIGH. Each bit corresponds to a single MSI
 *    Interrupt Vector. Note: This register field is sticky.
 */
#define PCIE_MSI_CTRL_INT_0_MASK_OFF_MSI_CTRL_INT_0_MASK(x) (((uint32_t)(((uint32_t)(x)) << PCIE_MSI_CTRL_INT_0_MASK_OFF_MSI_CTRL_INT_0_MASK_SHIFT)) & PCIE_MSI_CTRL_INT_0_MASK_OFF_MSI_CTRL_INT_0_MASK_MASK)
/*! @} */

/*! @name MSI_CTRL_INT_0_STATUS_OFF - Integrated MSI Reception Module Interrupt#i Status Register. */
/*! @{ */

#define PCIE_MSI_CTRL_INT_0_STATUS_OFF_MSI_CTRL_INT_0_STATUS_MASK (0xFFFFFFFFU)
#define PCIE_MSI_CTRL_INT_0_STATUS_OFF_MSI_CTRL_INT_0_STATUS_SHIFT (0U)
/*! MSI_CTRL_INT_0_STATUS - MSI Interrupt#i Status. When an MSI is detected for EP#i, one bit in
 *    this register is set. The decoding of the data payload of the MSI Memory Write request determines
 *    which bit gets set. A status is bit is cleared by writing a 1 to the bit. Each bit
 *    corresponds to a single MSI Interrupt Vector.
 */
#define PCIE_MSI_CTRL_INT_0_STATUS_OFF_MSI_CTRL_INT_0_STATUS(x) (((uint32_t)(((uint32_t)(x)) << PCIE_MSI_CTRL_INT_0_STATUS_OFF_MSI_CTRL_INT_0_STATUS_SHIFT)) & PCIE_MSI_CTRL_INT_0_STATUS_OFF_MSI_CTRL_INT_0_STATUS_MASK)
/*! @} */

/*! @name MSI_CTRL_INT_1_EN_OFF - Integrated MSI Reception Module Interrupt#i Enable Register. */
/*! @{ */

#define PCIE_MSI_CTRL_INT_1_EN_OFF_MSI_CTRL_INT_1_EN_MASK (0xFFFFFFFFU)
#define PCIE_MSI_CTRL_INT_1_EN_OFF_MSI_CTRL_INT_1_EN_SHIFT (0U)
/*! MSI_CTRL_INT_1_EN - MSI Interrupt#i Enable. Specifies which interrupts are enabled. When an MSI
 *    is received from a disabled interrupt, no status bit gets set in MSI controller interrupt
 *    status register. Each bit corresponds to a single MSI Interrupt Vector. Note: This register field
 *    is sticky.
 */
#define PCIE_MSI_CTRL_INT_1_EN_OFF_MSI_CTRL_INT_1_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_MSI_CTRL_INT_1_EN_OFF_MSI_CTRL_INT_1_EN_SHIFT)) & PCIE_MSI_CTRL_INT_1_EN_OFF_MSI_CTRL_INT_1_EN_MASK)
/*! @} */

/*! @name MSI_CTRL_INT_1_MASK_OFF - Integrated MSI Reception Module Interrupt#i Mask Register. */
/*! @{ */

#define PCIE_MSI_CTRL_INT_1_MASK_OFF_MSI_CTRL_INT_1_MASK_MASK (0xFFFFFFFFU)
#define PCIE_MSI_CTRL_INT_1_MASK_OFF_MSI_CTRL_INT_1_MASK_SHIFT (0U)
/*! MSI_CTRL_INT_1_MASK - MSI Interrupt#i Mask. Allows enabled interrupts to be masked. When an MSI
 *    is received for a masked interrupt, the corresponding status bit gets set in the interrupt
 *    status register but the msi_ctrl_int output is not set HIGH. Each bit corresponds to a single MSI
 *    Interrupt Vector. Note: This register field is sticky.
 */
#define PCIE_MSI_CTRL_INT_1_MASK_OFF_MSI_CTRL_INT_1_MASK(x) (((uint32_t)(((uint32_t)(x)) << PCIE_MSI_CTRL_INT_1_MASK_OFF_MSI_CTRL_INT_1_MASK_SHIFT)) & PCIE_MSI_CTRL_INT_1_MASK_OFF_MSI_CTRL_INT_1_MASK_MASK)
/*! @} */

/*! @name MSI_CTRL_INT_1_STATUS_OFF - Integrated MSI Reception Module Interrupt#i Status Register. */
/*! @{ */

#define PCIE_MSI_CTRL_INT_1_STATUS_OFF_MSI_CTRL_INT_1_STATUS_MASK (0xFFFFFFFFU)
#define PCIE_MSI_CTRL_INT_1_STATUS_OFF_MSI_CTRL_INT_1_STATUS_SHIFT (0U)
/*! MSI_CTRL_INT_1_STATUS - MSI Interrupt#i Status. When an MSI is detected for EP#i, one bit in
 *    this register is set. The decoding of the data payload of the MSI Memory Write request determines
 *    which bit gets set. A status is bit is cleared by writing a 1 to the bit. Each bit
 *    corresponds to a single MSI Interrupt Vector.
 */
#define PCIE_MSI_CTRL_INT_1_STATUS_OFF_MSI_CTRL_INT_1_STATUS(x) (((uint32_t)(((uint32_t)(x)) << PCIE_MSI_CTRL_INT_1_STATUS_OFF_MSI_CTRL_INT_1_STATUS_SHIFT)) & PCIE_MSI_CTRL_INT_1_STATUS_OFF_MSI_CTRL_INT_1_STATUS_MASK)
/*! @} */

/*! @name MSI_CTRL_INT_2_EN_OFF - Integrated MSI Reception Module Interrupt#i Enable Register. */
/*! @{ */

#define PCIE_MSI_CTRL_INT_2_EN_OFF_MSI_CTRL_INT_2_EN_MASK (0xFFFFFFFFU)
#define PCIE_MSI_CTRL_INT_2_EN_OFF_MSI_CTRL_INT_2_EN_SHIFT (0U)
/*! MSI_CTRL_INT_2_EN - MSI Interrupt#i Enable. Specifies which interrupts are enabled. When an MSI
 *    is received from a disabled interrupt, no status bit gets set in MSI controller interrupt
 *    status register. Each bit corresponds to a single MSI Interrupt Vector. Note: This register field
 *    is sticky.
 */
#define PCIE_MSI_CTRL_INT_2_EN_OFF_MSI_CTRL_INT_2_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_MSI_CTRL_INT_2_EN_OFF_MSI_CTRL_INT_2_EN_SHIFT)) & PCIE_MSI_CTRL_INT_2_EN_OFF_MSI_CTRL_INT_2_EN_MASK)
/*! @} */

/*! @name MSI_CTRL_INT_2_MASK_OFF - Integrated MSI Reception Module Interrupt#i Mask Register. */
/*! @{ */

#define PCIE_MSI_CTRL_INT_2_MASK_OFF_MSI_CTRL_INT_2_MASK_MASK (0xFFFFFFFFU)
#define PCIE_MSI_CTRL_INT_2_MASK_OFF_MSI_CTRL_INT_2_MASK_SHIFT (0U)
/*! MSI_CTRL_INT_2_MASK - MSI Interrupt#i Mask. Allows enabled interrupts to be masked. When an MSI
 *    is received for a masked interrupt, the corresponding status bit gets set in the interrupt
 *    status register but the msi_ctrl_int output is not set HIGH. Each bit corresponds to a single MSI
 *    Interrupt Vector. Note: This register field is sticky.
 */
#define PCIE_MSI_CTRL_INT_2_MASK_OFF_MSI_CTRL_INT_2_MASK(x) (((uint32_t)(((uint32_t)(x)) << PCIE_MSI_CTRL_INT_2_MASK_OFF_MSI_CTRL_INT_2_MASK_SHIFT)) & PCIE_MSI_CTRL_INT_2_MASK_OFF_MSI_CTRL_INT_2_MASK_MASK)
/*! @} */

/*! @name MSI_CTRL_INT_2_STATUS_OFF - Integrated MSI Reception Module Interrupt#i Status Register. */
/*! @{ */

#define PCIE_MSI_CTRL_INT_2_STATUS_OFF_MSI_CTRL_INT_2_STATUS_MASK (0xFFFFFFFFU)
#define PCIE_MSI_CTRL_INT_2_STATUS_OFF_MSI_CTRL_INT_2_STATUS_SHIFT (0U)
/*! MSI_CTRL_INT_2_STATUS - MSI Interrupt#i Status. When an MSI is detected for EP#i, one bit in
 *    this register is set. The decoding of the data payload of the MSI Memory Write request determines
 *    which bit gets set. A status is bit is cleared by writing a 1 to the bit. Each bit
 *    corresponds to a single MSI Interrupt Vector.
 */
#define PCIE_MSI_CTRL_INT_2_STATUS_OFF_MSI_CTRL_INT_2_STATUS(x) (((uint32_t)(((uint32_t)(x)) << PCIE_MSI_CTRL_INT_2_STATUS_OFF_MSI_CTRL_INT_2_STATUS_SHIFT)) & PCIE_MSI_CTRL_INT_2_STATUS_OFF_MSI_CTRL_INT_2_STATUS_MASK)
/*! @} */

/*! @name MSI_CTRL_INT_3_EN_OFF - Integrated MSI Reception Module Interrupt#i Enable Register. */
/*! @{ */

#define PCIE_MSI_CTRL_INT_3_EN_OFF_MSI_CTRL_INT_3_EN_MASK (0xFFFFFFFFU)
#define PCIE_MSI_CTRL_INT_3_EN_OFF_MSI_CTRL_INT_3_EN_SHIFT (0U)
/*! MSI_CTRL_INT_3_EN - MSI Interrupt#i Enable. Specifies which interrupts are enabled. When an MSI
 *    is received from a disabled interrupt, no status bit gets set in MSI controller interrupt
 *    status register. Each bit corresponds to a single MSI Interrupt Vector. Note: This register field
 *    is sticky.
 */
#define PCIE_MSI_CTRL_INT_3_EN_OFF_MSI_CTRL_INT_3_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_MSI_CTRL_INT_3_EN_OFF_MSI_CTRL_INT_3_EN_SHIFT)) & PCIE_MSI_CTRL_INT_3_EN_OFF_MSI_CTRL_INT_3_EN_MASK)
/*! @} */

/*! @name MSI_CTRL_INT_3_MASK_OFF - Integrated MSI Reception Module Interrupt#i Mask Register. */
/*! @{ */

#define PCIE_MSI_CTRL_INT_3_MASK_OFF_MSI_CTRL_INT_3_MASK_MASK (0xFFFFFFFFU)
#define PCIE_MSI_CTRL_INT_3_MASK_OFF_MSI_CTRL_INT_3_MASK_SHIFT (0U)
/*! MSI_CTRL_INT_3_MASK - MSI Interrupt#i Mask. Allows enabled interrupts to be masked. When an MSI
 *    is received for a masked interrupt, the corresponding status bit gets set in the interrupt
 *    status register but the msi_ctrl_int output is not set HIGH. Each bit corresponds to a single MSI
 *    Interrupt Vector. Note: This register field is sticky.
 */
#define PCIE_MSI_CTRL_INT_3_MASK_OFF_MSI_CTRL_INT_3_MASK(x) (((uint32_t)(((uint32_t)(x)) << PCIE_MSI_CTRL_INT_3_MASK_OFF_MSI_CTRL_INT_3_MASK_SHIFT)) & PCIE_MSI_CTRL_INT_3_MASK_OFF_MSI_CTRL_INT_3_MASK_MASK)
/*! @} */

/*! @name MSI_CTRL_INT_3_STATUS_OFF - Integrated MSI Reception Module Interrupt#i Status Register. */
/*! @{ */

#define PCIE_MSI_CTRL_INT_3_STATUS_OFF_MSI_CTRL_INT_3_STATUS_MASK (0xFFFFFFFFU)
#define PCIE_MSI_CTRL_INT_3_STATUS_OFF_MSI_CTRL_INT_3_STATUS_SHIFT (0U)
/*! MSI_CTRL_INT_3_STATUS - MSI Interrupt#i Status. When an MSI is detected for EP#i, one bit in
 *    this register is set. The decoding of the data payload of the MSI Memory Write request determines
 *    which bit gets set. A status is bit is cleared by writing a 1 to the bit. Each bit
 *    corresponds to a single MSI Interrupt Vector.
 */
#define PCIE_MSI_CTRL_INT_3_STATUS_OFF_MSI_CTRL_INT_3_STATUS(x) (((uint32_t)(((uint32_t)(x)) << PCIE_MSI_CTRL_INT_3_STATUS_OFF_MSI_CTRL_INT_3_STATUS_SHIFT)) & PCIE_MSI_CTRL_INT_3_STATUS_OFF_MSI_CTRL_INT_3_STATUS_MASK)
/*! @} */

/*! @name MSI_CTRL_INT_4_EN_OFF - Integrated MSI Reception Module Interrupt#i Enable Register. */
/*! @{ */

#define PCIE_MSI_CTRL_INT_4_EN_OFF_MSI_CTRL_INT_4_EN_MASK (0xFFFFFFFFU)
#define PCIE_MSI_CTRL_INT_4_EN_OFF_MSI_CTRL_INT_4_EN_SHIFT (0U)
/*! MSI_CTRL_INT_4_EN - MSI Interrupt#i Enable. Specifies which interrupts are enabled. When an MSI
 *    is received from a disabled interrupt, no status bit gets set in MSI controller interrupt
 *    status register. Each bit corresponds to a single MSI Interrupt Vector. Note: This register field
 *    is sticky.
 */
#define PCIE_MSI_CTRL_INT_4_EN_OFF_MSI_CTRL_INT_4_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_MSI_CTRL_INT_4_EN_OFF_MSI_CTRL_INT_4_EN_SHIFT)) & PCIE_MSI_CTRL_INT_4_EN_OFF_MSI_CTRL_INT_4_EN_MASK)
/*! @} */

/*! @name MSI_CTRL_INT_4_MASK_OFF - Integrated MSI Reception Module Interrupt#i Mask Register. */
/*! @{ */

#define PCIE_MSI_CTRL_INT_4_MASK_OFF_MSI_CTRL_INT_4_MASK_MASK (0xFFFFFFFFU)
#define PCIE_MSI_CTRL_INT_4_MASK_OFF_MSI_CTRL_INT_4_MASK_SHIFT (0U)
/*! MSI_CTRL_INT_4_MASK - MSI Interrupt#i Mask. Allows enabled interrupts to be masked. When an MSI
 *    is received for a masked interrupt, the corresponding status bit gets set in the interrupt
 *    status register but the msi_ctrl_int output is not set HIGH. Each bit corresponds to a single MSI
 *    Interrupt Vector. Note: This register field is sticky.
 */
#define PCIE_MSI_CTRL_INT_4_MASK_OFF_MSI_CTRL_INT_4_MASK(x) (((uint32_t)(((uint32_t)(x)) << PCIE_MSI_CTRL_INT_4_MASK_OFF_MSI_CTRL_INT_4_MASK_SHIFT)) & PCIE_MSI_CTRL_INT_4_MASK_OFF_MSI_CTRL_INT_4_MASK_MASK)
/*! @} */

/*! @name MSI_CTRL_INT_4_STATUS_OFF - Integrated MSI Reception Module Interrupt#i Status Register. */
/*! @{ */

#define PCIE_MSI_CTRL_INT_4_STATUS_OFF_MSI_CTRL_INT_4_STATUS_MASK (0xFFFFFFFFU)
#define PCIE_MSI_CTRL_INT_4_STATUS_OFF_MSI_CTRL_INT_4_STATUS_SHIFT (0U)
/*! MSI_CTRL_INT_4_STATUS - MSI Interrupt#i Status. When an MSI is detected for EP#i, one bit in
 *    this register is set. The decoding of the data payload of the MSI Memory Write request determines
 *    which bit gets set. A status is bit is cleared by writing a 1 to the bit. Each bit
 *    corresponds to a single MSI Interrupt Vector.
 */
#define PCIE_MSI_CTRL_INT_4_STATUS_OFF_MSI_CTRL_INT_4_STATUS(x) (((uint32_t)(((uint32_t)(x)) << PCIE_MSI_CTRL_INT_4_STATUS_OFF_MSI_CTRL_INT_4_STATUS_SHIFT)) & PCIE_MSI_CTRL_INT_4_STATUS_OFF_MSI_CTRL_INT_4_STATUS_MASK)
/*! @} */

/*! @name MSI_CTRL_INT_5_EN_OFF - Integrated MSI Reception Module Interrupt#i Enable Register. */
/*! @{ */

#define PCIE_MSI_CTRL_INT_5_EN_OFF_MSI_CTRL_INT_5_EN_MASK (0xFFFFFFFFU)
#define PCIE_MSI_CTRL_INT_5_EN_OFF_MSI_CTRL_INT_5_EN_SHIFT (0U)
/*! MSI_CTRL_INT_5_EN - MSI Interrupt#i Enable. Specifies which interrupts are enabled. When an MSI
 *    is received from a disabled interrupt, no status bit gets set in MSI controller interrupt
 *    status register. Each bit corresponds to a single MSI Interrupt Vector. Note: This register field
 *    is sticky.
 */
#define PCIE_MSI_CTRL_INT_5_EN_OFF_MSI_CTRL_INT_5_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_MSI_CTRL_INT_5_EN_OFF_MSI_CTRL_INT_5_EN_SHIFT)) & PCIE_MSI_CTRL_INT_5_EN_OFF_MSI_CTRL_INT_5_EN_MASK)
/*! @} */

/*! @name MSI_CTRL_INT_5_MASK_OFF - Integrated MSI Reception Module Interrupt#i Mask Register. */
/*! @{ */

#define PCIE_MSI_CTRL_INT_5_MASK_OFF_MSI_CTRL_INT_5_MASK_MASK (0xFFFFFFFFU)
#define PCIE_MSI_CTRL_INT_5_MASK_OFF_MSI_CTRL_INT_5_MASK_SHIFT (0U)
/*! MSI_CTRL_INT_5_MASK - MSI Interrupt#i Mask. Allows enabled interrupts to be masked. When an MSI
 *    is received for a masked interrupt, the corresponding status bit gets set in the interrupt
 *    status register but the msi_ctrl_int output is not set HIGH. Each bit corresponds to a single MSI
 *    Interrupt Vector. Note: This register field is sticky.
 */
#define PCIE_MSI_CTRL_INT_5_MASK_OFF_MSI_CTRL_INT_5_MASK(x) (((uint32_t)(((uint32_t)(x)) << PCIE_MSI_CTRL_INT_5_MASK_OFF_MSI_CTRL_INT_5_MASK_SHIFT)) & PCIE_MSI_CTRL_INT_5_MASK_OFF_MSI_CTRL_INT_5_MASK_MASK)
/*! @} */

/*! @name MSI_CTRL_INT_5_STATUS_OFF - Integrated MSI Reception Module Interrupt#i Status Register. */
/*! @{ */

#define PCIE_MSI_CTRL_INT_5_STATUS_OFF_MSI_CTRL_INT_5_STATUS_MASK (0xFFFFFFFFU)
#define PCIE_MSI_CTRL_INT_5_STATUS_OFF_MSI_CTRL_INT_5_STATUS_SHIFT (0U)
/*! MSI_CTRL_INT_5_STATUS - MSI Interrupt#i Status. When an MSI is detected for EP#i, one bit in
 *    this register is set. The decoding of the data payload of the MSI Memory Write request determines
 *    which bit gets set. A status is bit is cleared by writing a 1 to the bit. Each bit
 *    corresponds to a single MSI Interrupt Vector.
 */
#define PCIE_MSI_CTRL_INT_5_STATUS_OFF_MSI_CTRL_INT_5_STATUS(x) (((uint32_t)(((uint32_t)(x)) << PCIE_MSI_CTRL_INT_5_STATUS_OFF_MSI_CTRL_INT_5_STATUS_SHIFT)) & PCIE_MSI_CTRL_INT_5_STATUS_OFF_MSI_CTRL_INT_5_STATUS_MASK)
/*! @} */

/*! @name MSI_CTRL_INT_6_EN_OFF - Integrated MSI Reception Module Interrupt#i Enable Register. */
/*! @{ */

#define PCIE_MSI_CTRL_INT_6_EN_OFF_MSI_CTRL_INT_6_EN_MASK (0xFFFFFFFFU)
#define PCIE_MSI_CTRL_INT_6_EN_OFF_MSI_CTRL_INT_6_EN_SHIFT (0U)
/*! MSI_CTRL_INT_6_EN - MSI Interrupt#i Enable. Specifies which interrupts are enabled. When an MSI
 *    is received from a disabled interrupt, no status bit gets set in MSI controller interrupt
 *    status register. Each bit corresponds to a single MSI Interrupt Vector. Note: This register field
 *    is sticky.
 */
#define PCIE_MSI_CTRL_INT_6_EN_OFF_MSI_CTRL_INT_6_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_MSI_CTRL_INT_6_EN_OFF_MSI_CTRL_INT_6_EN_SHIFT)) & PCIE_MSI_CTRL_INT_6_EN_OFF_MSI_CTRL_INT_6_EN_MASK)
/*! @} */

/*! @name MSI_CTRL_INT_6_MASK_OFF - Integrated MSI Reception Module Interrupt#i Mask Register. */
/*! @{ */

#define PCIE_MSI_CTRL_INT_6_MASK_OFF_MSI_CTRL_INT_6_MASK_MASK (0xFFFFFFFFU)
#define PCIE_MSI_CTRL_INT_6_MASK_OFF_MSI_CTRL_INT_6_MASK_SHIFT (0U)
/*! MSI_CTRL_INT_6_MASK - MSI Interrupt#i Mask. Allows enabled interrupts to be masked. When an MSI
 *    is received for a masked interrupt, the corresponding status bit gets set in the interrupt
 *    status register but the msi_ctrl_int output is not set HIGH. Each bit corresponds to a single MSI
 *    Interrupt Vector. Note: This register field is sticky.
 */
#define PCIE_MSI_CTRL_INT_6_MASK_OFF_MSI_CTRL_INT_6_MASK(x) (((uint32_t)(((uint32_t)(x)) << PCIE_MSI_CTRL_INT_6_MASK_OFF_MSI_CTRL_INT_6_MASK_SHIFT)) & PCIE_MSI_CTRL_INT_6_MASK_OFF_MSI_CTRL_INT_6_MASK_MASK)
/*! @} */

/*! @name MSI_CTRL_INT_6_STATUS_OFF - Integrated MSI Reception Module Interrupt#i Status Register. */
/*! @{ */

#define PCIE_MSI_CTRL_INT_6_STATUS_OFF_MSI_CTRL_INT_6_STATUS_MASK (0xFFFFFFFFU)
#define PCIE_MSI_CTRL_INT_6_STATUS_OFF_MSI_CTRL_INT_6_STATUS_SHIFT (0U)
/*! MSI_CTRL_INT_6_STATUS - MSI Interrupt#i Status. When an MSI is detected for EP#i, one bit in
 *    this register is set. The decoding of the data payload of the MSI Memory Write request determines
 *    which bit gets set. A status is bit is cleared by writing a 1 to the bit. Each bit
 *    corresponds to a single MSI Interrupt Vector.
 */
#define PCIE_MSI_CTRL_INT_6_STATUS_OFF_MSI_CTRL_INT_6_STATUS(x) (((uint32_t)(((uint32_t)(x)) << PCIE_MSI_CTRL_INT_6_STATUS_OFF_MSI_CTRL_INT_6_STATUS_SHIFT)) & PCIE_MSI_CTRL_INT_6_STATUS_OFF_MSI_CTRL_INT_6_STATUS_MASK)
/*! @} */

/*! @name MSI_CTRL_INT_7_EN_OFF - Integrated MSI Reception Module Interrupt#i Enable Register. */
/*! @{ */

#define PCIE_MSI_CTRL_INT_7_EN_OFF_MSI_CTRL_INT_7_EN_MASK (0xFFFFFFFFU)
#define PCIE_MSI_CTRL_INT_7_EN_OFF_MSI_CTRL_INT_7_EN_SHIFT (0U)
/*! MSI_CTRL_INT_7_EN - MSI Interrupt#i Enable. Specifies which interrupts are enabled. When an MSI
 *    is received from a disabled interrupt, no status bit gets set in MSI controller interrupt
 *    status register. Each bit corresponds to a single MSI Interrupt Vector. Note: This register field
 *    is sticky.
 */
#define PCIE_MSI_CTRL_INT_7_EN_OFF_MSI_CTRL_INT_7_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_MSI_CTRL_INT_7_EN_OFF_MSI_CTRL_INT_7_EN_SHIFT)) & PCIE_MSI_CTRL_INT_7_EN_OFF_MSI_CTRL_INT_7_EN_MASK)
/*! @} */

/*! @name MSI_CTRL_INT_7_MASK_OFF - Integrated MSI Reception Module Interrupt#i Mask Register. */
/*! @{ */

#define PCIE_MSI_CTRL_INT_7_MASK_OFF_MSI_CTRL_INT_7_MASK_MASK (0xFFFFFFFFU)
#define PCIE_MSI_CTRL_INT_7_MASK_OFF_MSI_CTRL_INT_7_MASK_SHIFT (0U)
/*! MSI_CTRL_INT_7_MASK - MSI Interrupt#i Mask. Allows enabled interrupts to be masked. When an MSI
 *    is received for a masked interrupt, the corresponding status bit gets set in the interrupt
 *    status register but the msi_ctrl_int output is not set HIGH. Each bit corresponds to a single MSI
 *    Interrupt Vector. Note: This register field is sticky.
 */
#define PCIE_MSI_CTRL_INT_7_MASK_OFF_MSI_CTRL_INT_7_MASK(x) (((uint32_t)(((uint32_t)(x)) << PCIE_MSI_CTRL_INT_7_MASK_OFF_MSI_CTRL_INT_7_MASK_SHIFT)) & PCIE_MSI_CTRL_INT_7_MASK_OFF_MSI_CTRL_INT_7_MASK_MASK)
/*! @} */

/*! @name MSI_CTRL_INT_7_STATUS_OFF - Integrated MSI Reception Module Interrupt#i Status Register. */
/*! @{ */

#define PCIE_MSI_CTRL_INT_7_STATUS_OFF_MSI_CTRL_INT_7_STATUS_MASK (0xFFFFFFFFU)
#define PCIE_MSI_CTRL_INT_7_STATUS_OFF_MSI_CTRL_INT_7_STATUS_SHIFT (0U)
/*! MSI_CTRL_INT_7_STATUS - MSI Interrupt#i Status. When an MSI is detected for EP#i, one bit in
 *    this register is set. The decoding of the data payload of the MSI Memory Write request determines
 *    which bit gets set. A status is bit is cleared by writing a 1 to the bit. Each bit
 *    corresponds to a single MSI Interrupt Vector.
 */
#define PCIE_MSI_CTRL_INT_7_STATUS_OFF_MSI_CTRL_INT_7_STATUS(x) (((uint32_t)(((uint32_t)(x)) << PCIE_MSI_CTRL_INT_7_STATUS_OFF_MSI_CTRL_INT_7_STATUS_SHIFT)) & PCIE_MSI_CTRL_INT_7_STATUS_OFF_MSI_CTRL_INT_7_STATUS_MASK)
/*! @} */

/*! @name MSI_GPIO_IO_OFF - Integrated MSI Reception Module General Purpose IO Register. */
/*! @{ */

#define PCIE_MSI_GPIO_IO_OFF_MSI_GPIO_REG_MASK   (0xFFFFFFFFU)
#define PCIE_MSI_GPIO_IO_OFF_MSI_GPIO_REG_SHIFT  (0U)
/*! MSI_GPIO_REG - MSI GPIO Register. The contents of this register drives the top-level GPIO
 *    msi_ctrl_io[31:0] Note: This register field is sticky.
 */
#define PCIE_MSI_GPIO_IO_OFF_MSI_GPIO_REG(x)     (((uint32_t)(((uint32_t)(x)) << PCIE_MSI_GPIO_IO_OFF_MSI_GPIO_REG_SHIFT)) & PCIE_MSI_GPIO_IO_OFF_MSI_GPIO_REG_MASK)
/*! @} */

/*! @name CLOCK_GATING_CTRL_OFF - RADM clock gating enable control register. */
/*! @{ */

#define PCIE_CLOCK_GATING_CTRL_OFF_RADM_CLK_GATING_EN_MASK (0x1U)
#define PCIE_CLOCK_GATING_CTRL_OFF_RADM_CLK_GATING_EN_SHIFT (0U)
/*! RADM_CLK_GATING_EN - Enable Radm clock gating feature. - 0: Disable - 1: Enable(default) */
#define PCIE_CLOCK_GATING_CTRL_OFF_RADM_CLK_GATING_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_CLOCK_GATING_CTRL_OFF_RADM_CLK_GATING_EN_SHIFT)) & PCIE_CLOCK_GATING_CTRL_OFF_RADM_CLK_GATING_EN_MASK)

#define PCIE_CLOCK_GATING_CTRL_OFF_RSVDP_1_MASK  (0xFFFFFFFEU)
#define PCIE_CLOCK_GATING_CTRL_OFF_RSVDP_1_SHIFT (1U)
/*! RSVDP_1 - Reserved for future use. */
#define PCIE_CLOCK_GATING_CTRL_OFF_RSVDP_1(x)    (((uint32_t)(((uint32_t)(x)) << PCIE_CLOCK_GATING_CTRL_OFF_RSVDP_1_SHIFT)) & PCIE_CLOCK_GATING_CTRL_OFF_RSVDP_1_MASK)
/*! @} */

/*! @name ORDER_RULE_CTRL_OFF - Order Rule Control Register. */
/*! @{ */

#define PCIE_ORDER_RULE_CTRL_OFF_NP_PASS_P_MASK  (0xFFU)
#define PCIE_ORDER_RULE_CTRL_OFF_NP_PASS_P_SHIFT (0U)
/*! NP_PASS_P - Non-Posted Passing Posted Ordering Rule Control. Determines if NP can pass halted P
 *    queue. - 0 : NP can not pass P (recommended). - 1 : NP can pass P
 */
#define PCIE_ORDER_RULE_CTRL_OFF_NP_PASS_P(x)    (((uint32_t)(((uint32_t)(x)) << PCIE_ORDER_RULE_CTRL_OFF_NP_PASS_P_SHIFT)) & PCIE_ORDER_RULE_CTRL_OFF_NP_PASS_P_MASK)

#define PCIE_ORDER_RULE_CTRL_OFF_CPL_PASS_P_MASK (0xFF00U)
#define PCIE_ORDER_RULE_CTRL_OFF_CPL_PASS_P_SHIFT (8U)
/*! CPL_PASS_P - Completion Passing Posted Ordering Rule Control. Determines if CPL can pass halted
 *    P queue. - 0: CPL can not pass P (recommended) - 1: CPL can pass P
 */
#define PCIE_ORDER_RULE_CTRL_OFF_CPL_PASS_P(x)   (((uint32_t)(((uint32_t)(x)) << PCIE_ORDER_RULE_CTRL_OFF_CPL_PASS_P_SHIFT)) & PCIE_ORDER_RULE_CTRL_OFF_CPL_PASS_P_MASK)

#define PCIE_ORDER_RULE_CTRL_OFF_RSVDP_16_MASK   (0xFFFF0000U)
#define PCIE_ORDER_RULE_CTRL_OFF_RSVDP_16_SHIFT  (16U)
/*! RSVDP_16 - Reserved for future use. */
#define PCIE_ORDER_RULE_CTRL_OFF_RSVDP_16(x)     (((uint32_t)(((uint32_t)(x)) << PCIE_ORDER_RULE_CTRL_OFF_RSVDP_16_SHIFT)) & PCIE_ORDER_RULE_CTRL_OFF_RSVDP_16_MASK)
/*! @} */

/*! @name PIPE_LOOPBACK_CONTROL_OFF - PIPE Loopback Control Register. */
/*! @{ */

#define PCIE_PIPE_LOOPBACK_CONTROL_OFF_LPBK_RXVALID_MASK (0xFFFFU)
#define PCIE_PIPE_LOOPBACK_CONTROL_OFF_LPBK_RXVALID_SHIFT (0U)
/*! LPBK_RXVALID - LPBK_RXVALID is an internally reserved field. Do not use. Note: This register field is sticky. */
#define PCIE_PIPE_LOOPBACK_CONTROL_OFF_LPBK_RXVALID(x) (((uint32_t)(((uint32_t)(x)) << PCIE_PIPE_LOOPBACK_CONTROL_OFF_LPBK_RXVALID_SHIFT)) & PCIE_PIPE_LOOPBACK_CONTROL_OFF_LPBK_RXVALID_MASK)

#define PCIE_PIPE_LOOPBACK_CONTROL_OFF_RXSTATUS_LANE_MASK (0x3F0000U)
#define PCIE_PIPE_LOOPBACK_CONTROL_OFF_RXSTATUS_LANE_SHIFT (16U)
/*! RXSTATUS_LANE - RXSTATUS_LANE is an internally reserved field. Do not use. Note: This register field is sticky. */
#define PCIE_PIPE_LOOPBACK_CONTROL_OFF_RXSTATUS_LANE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_PIPE_LOOPBACK_CONTROL_OFF_RXSTATUS_LANE_SHIFT)) & PCIE_PIPE_LOOPBACK_CONTROL_OFF_RXSTATUS_LANE_MASK)

#define PCIE_PIPE_LOOPBACK_CONTROL_OFF_RSVDP_22_MASK (0xC00000U)
#define PCIE_PIPE_LOOPBACK_CONTROL_OFF_RSVDP_22_SHIFT (22U)
/*! RSVDP_22 - Reserved for future use. */
#define PCIE_PIPE_LOOPBACK_CONTROL_OFF_RSVDP_22(x) (((uint32_t)(((uint32_t)(x)) << PCIE_PIPE_LOOPBACK_CONTROL_OFF_RSVDP_22_SHIFT)) & PCIE_PIPE_LOOPBACK_CONTROL_OFF_RSVDP_22_MASK)

#define PCIE_PIPE_LOOPBACK_CONTROL_OFF_RXSTATUS_VALUE_MASK (0x7000000U)
#define PCIE_PIPE_LOOPBACK_CONTROL_OFF_RXSTATUS_VALUE_SHIFT (24U)
/*! RXSTATUS_VALUE - RXSTATUS_VALUE is an internally reserved field. Do not use. */
#define PCIE_PIPE_LOOPBACK_CONTROL_OFF_RXSTATUS_VALUE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_PIPE_LOOPBACK_CONTROL_OFF_RXSTATUS_VALUE_SHIFT)) & PCIE_PIPE_LOOPBACK_CONTROL_OFF_RXSTATUS_VALUE_MASK)

#define PCIE_PIPE_LOOPBACK_CONTROL_OFF_RSVDP_27_MASK (0x78000000U)
#define PCIE_PIPE_LOOPBACK_CONTROL_OFF_RSVDP_27_SHIFT (27U)
/*! RSVDP_27 - Reserved for future use. */
#define PCIE_PIPE_LOOPBACK_CONTROL_OFF_RSVDP_27(x) (((uint32_t)(((uint32_t)(x)) << PCIE_PIPE_LOOPBACK_CONTROL_OFF_RSVDP_27_SHIFT)) & PCIE_PIPE_LOOPBACK_CONTROL_OFF_RSVDP_27_MASK)

#define PCIE_PIPE_LOOPBACK_CONTROL_OFF_PIPE_LOOPBACK_MASK (0x80000000U)
#define PCIE_PIPE_LOOPBACK_CONTROL_OFF_PIPE_LOOPBACK_SHIFT (31U)
/*! PIPE_LOOPBACK - PIPE Loopback Enable. Indicates RMMI Loopback if M-PCIe. Note: This register field is sticky. */
#define PCIE_PIPE_LOOPBACK_CONTROL_OFF_PIPE_LOOPBACK(x) (((uint32_t)(((uint32_t)(x)) << PCIE_PIPE_LOOPBACK_CONTROL_OFF_PIPE_LOOPBACK_SHIFT)) & PCIE_PIPE_LOOPBACK_CONTROL_OFF_PIPE_LOOPBACK_MASK)
/*! @} */

/*! @name MISC_CONTROL_1_OFF - DBI Read-Only Write Enable Register. */
/*! @{ */

#define PCIE_MISC_CONTROL_1_OFF_DBI_RO_WR_EN_MASK (0x1U)
#define PCIE_MISC_CONTROL_1_OFF_DBI_RO_WR_EN_SHIFT (0U)
/*! DBI_RO_WR_EN - Write to RO Registers Using DBI. When you set this field to "1", then some RO and
 *    HwInit bits are writable from the local application through the DBI. For more details, see
 *    "Writing to Read-Only Registers." Note: This register field is sticky.
 */
#define PCIE_MISC_CONTROL_1_OFF_DBI_RO_WR_EN(x)  (((uint32_t)(((uint32_t)(x)) << PCIE_MISC_CONTROL_1_OFF_DBI_RO_WR_EN_SHIFT)) & PCIE_MISC_CONTROL_1_OFF_DBI_RO_WR_EN_MASK)

#define PCIE_MISC_CONTROL_1_OFF_DEFAULT_TARGET_MASK (0x2U)
#define PCIE_MISC_CONTROL_1_OFF_DEFAULT_TARGET_SHIFT (1U)
/*! DEFAULT_TARGET - Default target a received IO or MEM request with UR/CA/CRS is sent to by the
 *    controller. - 0: The controller drops all incoming I/O or MEM requests (after corresponding
 *    error reporting). A completion with UR status will be generated for non-posted requests. - 1: The
 *    controller forwards all incoming I/O or MEM requests with UR/CA/CRS status to your application
 *    For more details, see "ECRC Handling" and "Request TLP Routing Rules" in "Receive Routing"
 *    section of the "Controller Operations" chapter of the Databook. Default value is DEFAULT_TARGET
 *    configuration parameter. Note: This register field is sticky.
 */
#define PCIE_MISC_CONTROL_1_OFF_DEFAULT_TARGET(x) (((uint32_t)(((uint32_t)(x)) << PCIE_MISC_CONTROL_1_OFF_DEFAULT_TARGET_SHIFT)) & PCIE_MISC_CONTROL_1_OFF_DEFAULT_TARGET_MASK)

#define PCIE_MISC_CONTROL_1_OFF_UR_CA_MASK_4_TRGT1_MASK (0x4U)
#define PCIE_MISC_CONTROL_1_OFF_UR_CA_MASK_4_TRGT1_SHIFT (2U)
/*! UR_CA_MASK_4_TRGT1 - This field only applies to request TLPs (with UR filtering status) that you
 *    have chosen to forward to the application (when you set DEFAULT_TARGET in this register). -
 *    When you set this field to '1', the core suppresses error logging, Error Message generation,
 *    and CPL generation (for non-posted requests). - For more details, refer to the "Advanced Error
 *    Handling For Received TLPs" chapter of the Databook. You should set this if you have set the
 *    Default Target port logic register to '1'. Default is CX_MASK_UR_CA_4_TRGT1 configuration
 *    parameter. Note: This register field is sticky.
 */
#define PCIE_MISC_CONTROL_1_OFF_UR_CA_MASK_4_TRGT1(x) (((uint32_t)(((uint32_t)(x)) << PCIE_MISC_CONTROL_1_OFF_UR_CA_MASK_4_TRGT1_SHIFT)) & PCIE_MISC_CONTROL_1_OFF_UR_CA_MASK_4_TRGT1_MASK)

#define PCIE_MISC_CONTROL_1_OFF_SIMPLIFIED_REPLAY_TIMER_MASK (0x8U)
#define PCIE_MISC_CONTROL_1_OFF_SIMPLIFIED_REPLAY_TIMER_SHIFT (3U)
/*! SIMPLIFIED_REPLAY_TIMER - Enables Simplified Replay Timer (Gen4). For more details, see
 *    "Transmit Replay" in the Controller Operations chapter of the Databook. Simplified Replay Timer Values
 *    are: - A value from 24,000 to 31,000 Symbol Times when Extended Synch is 0b. - A value from
 *    80,000 to 100,000 Symbol Times when Extended Synch is 1b. Must not be changed while link is in
 *    use. Note: This register field is sticky.
 */
#define PCIE_MISC_CONTROL_1_OFF_SIMPLIFIED_REPLAY_TIMER(x) (((uint32_t)(((uint32_t)(x)) << PCIE_MISC_CONTROL_1_OFF_SIMPLIFIED_REPLAY_TIMER_SHIFT)) & PCIE_MISC_CONTROL_1_OFF_SIMPLIFIED_REPLAY_TIMER_MASK)

#define PCIE_MISC_CONTROL_1_OFF_ARI_DEVICE_NUMBER_MASK (0x20U)
#define PCIE_MISC_CONTROL_1_OFF_ARI_DEVICE_NUMBER_SHIFT (5U)
/*! ARI_DEVICE_NUMBER - When ARI is enabled, this field enables use of the device ID. Note: This register field is sticky. */
#define PCIE_MISC_CONTROL_1_OFF_ARI_DEVICE_NUMBER(x) (((uint32_t)(((uint32_t)(x)) << PCIE_MISC_CONTROL_1_OFF_ARI_DEVICE_NUMBER_SHIFT)) & PCIE_MISC_CONTROL_1_OFF_ARI_DEVICE_NUMBER_MASK)

#define PCIE_MISC_CONTROL_1_OFF_RSVDP_6_MASK     (0xFFFFFFC0U)
#define PCIE_MISC_CONTROL_1_OFF_RSVDP_6_SHIFT    (6U)
/*! RSVDP_6 - Reserved for future use. */
#define PCIE_MISC_CONTROL_1_OFF_RSVDP_6(x)       (((uint32_t)(((uint32_t)(x)) << PCIE_MISC_CONTROL_1_OFF_RSVDP_6_SHIFT)) & PCIE_MISC_CONTROL_1_OFF_RSVDP_6_MASK)
/*! @} */

/*! @name MULTI_LANE_CONTROL_OFF - UpConfigure Multi-lane Control Register. */
/*! @{ */

#define PCIE_MULTI_LANE_CONTROL_OFF_TARGET_LINK_WIDTH_MASK (0x3FU)
#define PCIE_MULTI_LANE_CONTROL_OFF_TARGET_LINK_WIDTH_SHIFT (0U)
/*! TARGET_LINK_WIDTH - Target Link Width. Values correspond to: - 6'b000000: Core does not start
 *    upconfigure or autonomous width downsizing in the Configuration state. - 6'b000001: x1 -
 *    6'b000010: x2 - 6'b000100: x4 - 6'b001000: x8 - 6'b010000: x16 - 6'b100000: x32 This field is
 *    reserved (fixed to '0') for M-PCIe.
 */
#define PCIE_MULTI_LANE_CONTROL_OFF_TARGET_LINK_WIDTH(x) (((uint32_t)(((uint32_t)(x)) << PCIE_MULTI_LANE_CONTROL_OFF_TARGET_LINK_WIDTH_SHIFT)) & PCIE_MULTI_LANE_CONTROL_OFF_TARGET_LINK_WIDTH_MASK)

#define PCIE_MULTI_LANE_CONTROL_OFF_DIRECT_LINK_WIDTH_CHANGE_MASK (0x40U)
#define PCIE_MULTI_LANE_CONTROL_OFF_DIRECT_LINK_WIDTH_CHANGE_SHIFT (6U)
/*! DIRECT_LINK_WIDTH_CHANGE - Directed Link Width Change. The controller always moves to
 *    Configuration state through Recovery state when this bit is set to '1'. - If the upconfigure_capable
 *    variable is '1' and the PCIE_CAP_HW_AUTO_WIDTH_DISABLE bit in LINK_CONTROL_LINK_STATUS_REG is
 *    '0', the controller starts upconfigure or autonomous width downsizing (to the TARGET_LINK_WIDTH
 *    value) in the Configuration state. - If TARGET_LINK_WIDTH value is 0x0, the controller does not
 *    start upconfigure or autonomous width downsizing in the Configuration state. The controller
 *    self-clears this field when the controller accepts this request. This field is reserved (fixed
 *    to '0') for M-PCIe.
 */
#define PCIE_MULTI_LANE_CONTROL_OFF_DIRECT_LINK_WIDTH_CHANGE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_MULTI_LANE_CONTROL_OFF_DIRECT_LINK_WIDTH_CHANGE_SHIFT)) & PCIE_MULTI_LANE_CONTROL_OFF_DIRECT_LINK_WIDTH_CHANGE_MASK)

#define PCIE_MULTI_LANE_CONTROL_OFF_UPCONFIGURE_SUPPORT_MASK (0x80U)
#define PCIE_MULTI_LANE_CONTROL_OFF_UPCONFIGURE_SUPPORT_SHIFT (7U)
/*! UPCONFIGURE_SUPPORT - Upconfigure Support. The controller sends this value as the Link
 *    Upconfigure Capability in TS2 Ordered Sets in Configuration.Complete state. This field is reserved
 *    (fixed to '0') for M-PCIe. Note: This register field is sticky.
 */
#define PCIE_MULTI_LANE_CONTROL_OFF_UPCONFIGURE_SUPPORT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_MULTI_LANE_CONTROL_OFF_UPCONFIGURE_SUPPORT_SHIFT)) & PCIE_MULTI_LANE_CONTROL_OFF_UPCONFIGURE_SUPPORT_MASK)

#define PCIE_MULTI_LANE_CONTROL_OFF_RSVDP_8_MASK (0xFFFFFF00U)
#define PCIE_MULTI_LANE_CONTROL_OFF_RSVDP_8_SHIFT (8U)
/*! RSVDP_8 - Reserved for future use. */
#define PCIE_MULTI_LANE_CONTROL_OFF_RSVDP_8(x)   (((uint32_t)(((uint32_t)(x)) << PCIE_MULTI_LANE_CONTROL_OFF_RSVDP_8_SHIFT)) & PCIE_MULTI_LANE_CONTROL_OFF_RSVDP_8_MASK)
/*! @} */

/*! @name PHY_INTEROP_CTRL_OFF - PHY Interoperability Control Register. */
/*! @{ */

#define PCIE_PHY_INTEROP_CTRL_OFF_RXSTANDBY_CONTROL_MASK (0x7FU)
#define PCIE_PHY_INTEROP_CTRL_OFF_RXSTANDBY_CONTROL_SHIFT (0U)
/*! RXSTANDBY_CONTROL - Rxstandby Control. Bits 0..5 determine if the controller asserts the
 *    RxStandby signal (mac_phy_rxstandby) in the indicated condition. Bit 6 enables the controller to
 *    perform the RxStandby/RxStandbyStatus handshake. - [0]: Rx EIOS and subsequent T TX-IDLE-MIN -
 *    [1]: Rate Change - [2]: Inactive lane for upconfigure/downconfigure - [3]: PowerDown=P1orP2 -
 *    [4]: RxL0s.Idle - [5]: EI Infer in L0 - [6]: Execute RxStandby/RxStandbyStatus Handshake This
 *    field is reserved (fixed to '0') for M-PCIe. Note: This register field is sticky.
 */
#define PCIE_PHY_INTEROP_CTRL_OFF_RXSTANDBY_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << PCIE_PHY_INTEROP_CTRL_OFF_RXSTANDBY_CONTROL_SHIFT)) & PCIE_PHY_INTEROP_CTRL_OFF_RXSTANDBY_CONTROL_MASK)

#define PCIE_PHY_INTEROP_CTRL_OFF_RSVDP_7_MASK   (0x80U)
#define PCIE_PHY_INTEROP_CTRL_OFF_RSVDP_7_SHIFT  (7U)
/*! RSVDP_7 - Reserved for future use. */
#define PCIE_PHY_INTEROP_CTRL_OFF_RSVDP_7(x)     (((uint32_t)(((uint32_t)(x)) << PCIE_PHY_INTEROP_CTRL_OFF_RSVDP_7_SHIFT)) & PCIE_PHY_INTEROP_CTRL_OFF_RSVDP_7_MASK)

#define PCIE_PHY_INTEROP_CTRL_OFF_L1SUB_EXIT_MODE_MASK (0x100U)
#define PCIE_PHY_INTEROP_CTRL_OFF_L1SUB_EXIT_MODE_SHIFT (8U)
/*! L1SUB_EXIT_MODE - L1 Exit Control Using phy_mac_pclkack_n. - 1: Core exits L1 without waiting
 *    for the PHY to assert phy_mac_pclkack_n. - 0: Core waits for the PHY to assert phy_mac_pclkack_n
 *    before exiting L1. Note: This register field is sticky.
 */
#define PCIE_PHY_INTEROP_CTRL_OFF_L1SUB_EXIT_MODE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_PHY_INTEROP_CTRL_OFF_L1SUB_EXIT_MODE_SHIFT)) & PCIE_PHY_INTEROP_CTRL_OFF_L1SUB_EXIT_MODE_MASK)

#define PCIE_PHY_INTEROP_CTRL_OFF_L1_NOWAIT_P1_MASK (0x200U)
#define PCIE_PHY_INTEROP_CTRL_OFF_L1_NOWAIT_P1_SHIFT (9U)
/*! L1_NOWAIT_P1 - L1 entry control bit. - 1: Core does not wait for PHY to acknowledge transition
 *    to P1 before entering L1. - 0: Core waits for the PHY to acknowledge transition to P1 before
 *    entering L1. Note: The access attributes of this field are as follows: - Dbi: R/W (sticky) Note:
 *    This register field is sticky.
 */
#define PCIE_PHY_INTEROP_CTRL_OFF_L1_NOWAIT_P1(x) (((uint32_t)(((uint32_t)(x)) << PCIE_PHY_INTEROP_CTRL_OFF_L1_NOWAIT_P1_SHIFT)) & PCIE_PHY_INTEROP_CTRL_OFF_L1_NOWAIT_P1_MASK)

#define PCIE_PHY_INTEROP_CTRL_OFF_L1_CLK_SEL_MASK (0x400U)
#define PCIE_PHY_INTEROP_CTRL_OFF_L1_CLK_SEL_SHIFT (10U)
/*! L1_CLK_SEL - L1 Clock control bit. - 1: Controller does not request aux_clk switch and core_clk
 *    gating in L1. - 0: Controller requests aux_clk switch and core_clk gating in L1. Note: This
 *    register field is sticky.
 */
#define PCIE_PHY_INTEROP_CTRL_OFF_L1_CLK_SEL(x)  (((uint32_t)(((uint32_t)(x)) << PCIE_PHY_INTEROP_CTRL_OFF_L1_CLK_SEL_SHIFT)) & PCIE_PHY_INTEROP_CTRL_OFF_L1_CLK_SEL_MASK)

#define PCIE_PHY_INTEROP_CTRL_OFF_RSVDP_11_MASK  (0xFFFFF800U)
#define PCIE_PHY_INTEROP_CTRL_OFF_RSVDP_11_SHIFT (11U)
/*! RSVDP_11 - Reserved for future use. */
#define PCIE_PHY_INTEROP_CTRL_OFF_RSVDP_11(x)    (((uint32_t)(((uint32_t)(x)) << PCIE_PHY_INTEROP_CTRL_OFF_RSVDP_11_SHIFT)) & PCIE_PHY_INTEROP_CTRL_OFF_RSVDP_11_MASK)
/*! @} */

/*! @name TRGT_CPL_LUT_DELETE_ENTRY_OFF - TRGT_CPL_LUT Delete Entry Control register. */
/*! @{ */

#define PCIE_TRGT_CPL_LUT_DELETE_ENTRY_OFF_LOOK_UP_ID_MASK (0x7FFFFFFFU)
#define PCIE_TRGT_CPL_LUT_DELETE_ENTRY_OFF_LOOK_UP_ID_SHIFT (0U)
/*! LOOK_UP_ID - This number selects one entry to delete of the TRGT_CPL_LUT. */
#define PCIE_TRGT_CPL_LUT_DELETE_ENTRY_OFF_LOOK_UP_ID(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TRGT_CPL_LUT_DELETE_ENTRY_OFF_LOOK_UP_ID_SHIFT)) & PCIE_TRGT_CPL_LUT_DELETE_ENTRY_OFF_LOOK_UP_ID_MASK)

#define PCIE_TRGT_CPL_LUT_DELETE_ENTRY_OFF_DELETE_EN_MASK (0x80000000U)
#define PCIE_TRGT_CPL_LUT_DELETE_ENTRY_OFF_DELETE_EN_SHIFT (31U)
/*! DELETE_EN - This is a one-shot bit. A '1' write to this bit triggers the deletion of the target
 *    completion LUT entry that is specified in the LOOK_UP_ID field. This is a self-clearing
 *    register field. Reading from this register field always returns a '0'.
 */
#define PCIE_TRGT_CPL_LUT_DELETE_ENTRY_OFF_DELETE_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_TRGT_CPL_LUT_DELETE_ENTRY_OFF_DELETE_EN_SHIFT)) & PCIE_TRGT_CPL_LUT_DELETE_ENTRY_OFF_DELETE_EN_MASK)
/*! @} */

/*! @name LINK_FLUSH_CONTROL_OFF - Link Reset Request Flush Control Register. */
/*! @{ */

#define PCIE_LINK_FLUSH_CONTROL_OFF_AUTO_FLUSH_EN_MASK (0x1U)
#define PCIE_LINK_FLUSH_CONTROL_OFF_AUTO_FLUSH_EN_SHIFT (0U)
/*! AUTO_FLUSH_EN - Enables automatic flushing of pending requests before sending the reset request
 *    to the application logic to reset the PCIe controller and the AXI Bridge. The flushing process
 *    is initiated if any of the following events occur: - Hot reset request. A downstream port
 *    (DSP) can "hot reset" an upstream port (USP) by sending two consecutive TS1 ordered sets with the
 *    hot reset bit asserted. - Warm (Soft) reset request. Generated when exiting from D3 to D0 and
 *    cfg_pm_no_soft_rst=0. - Link down reset request. A high to low transition on smlh_req_rst_not
 *    indicates the link has gone down and the controller is requesting a reset. If you disable
 *    automatic flushing, your application is responsible for resetting the PCIe controller and the AXI
 *    Bridge. For more details see "Warm and Hot Resets" section in the Architecture chapter of the
 *    Databook. Note: This register field is sticky.
 */
#define PCIE_LINK_FLUSH_CONTROL_OFF_AUTO_FLUSH_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_LINK_FLUSH_CONTROL_OFF_AUTO_FLUSH_EN_SHIFT)) & PCIE_LINK_FLUSH_CONTROL_OFF_AUTO_FLUSH_EN_MASK)

#define PCIE_LINK_FLUSH_CONTROL_OFF_RSVDP_1_MASK (0xFFFFFEU)
#define PCIE_LINK_FLUSH_CONTROL_OFF_RSVDP_1_SHIFT (1U)
/*! RSVDP_1 - Reserved for future use. */
#define PCIE_LINK_FLUSH_CONTROL_OFF_RSVDP_1(x)   (((uint32_t)(((uint32_t)(x)) << PCIE_LINK_FLUSH_CONTROL_OFF_RSVDP_1_SHIFT)) & PCIE_LINK_FLUSH_CONTROL_OFF_RSVDP_1_MASK)

#define PCIE_LINK_FLUSH_CONTROL_OFF_RSVD_I_8_MASK (0xFF000000U)
#define PCIE_LINK_FLUSH_CONTROL_OFF_RSVD_I_8_SHIFT (24U)
/*! RSVD_I_8 - This is an internally reserved field. Do not use. Note: This register field is sticky. */
#define PCIE_LINK_FLUSH_CONTROL_OFF_RSVD_I_8(x)  (((uint32_t)(((uint32_t)(x)) << PCIE_LINK_FLUSH_CONTROL_OFF_RSVD_I_8_SHIFT)) & PCIE_LINK_FLUSH_CONTROL_OFF_RSVD_I_8_MASK)
/*! @} */

/*! @name AMBA_ERROR_RESPONSE_DEFAULT_OFF - AXI Bridge Slave Error Response Register. */
/*! @{ */

#define PCIE_AMBA_ERROR_RESPONSE_DEFAULT_OFF_AMBA_ERROR_RESPONSE_GLOBAL_MASK (0x1U)
#define PCIE_AMBA_ERROR_RESPONSE_DEFAULT_OFF_AMBA_ERROR_RESPONSE_GLOBAL_SHIFT (0U)
/*! AMBA_ERROR_RESPONSE_GLOBAL - Global Slave Error Response Mapping. Determines the AXI slave
 *    response for all error scenarios on non-posted requests. For more details see "Error Handling" in
 *    the AXI chapter of the Databook. AHB: - 0: OKAY (with FFFF data for non-posted requests) and
 *    ignore the setting in bit [2] of this register. - 1: ERROR for normal link (data) accesses and
 *    look at bit [2] for other scenarios. AXI: - 0: OKAY (with FFFF data for non-posted requests) -
 *    1: SLVERR/DECERR (the AXI_ERROR_RESPONSE_MAP field determines the PCIe-to-AXI Slave error
 *    response mapping) The error response mapping is not applicable to Non-existent Vendor ID register
 *    reads. Note: This register field is sticky.
 */
#define PCIE_AMBA_ERROR_RESPONSE_DEFAULT_OFF_AMBA_ERROR_RESPONSE_GLOBAL(x) (((uint32_t)(((uint32_t)(x)) << PCIE_AMBA_ERROR_RESPONSE_DEFAULT_OFF_AMBA_ERROR_RESPONSE_GLOBAL_SHIFT)) & PCIE_AMBA_ERROR_RESPONSE_DEFAULT_OFF_AMBA_ERROR_RESPONSE_GLOBAL_MASK)

#define PCIE_AMBA_ERROR_RESPONSE_DEFAULT_OFF_RSVDP_1_MASK (0x2U)
#define PCIE_AMBA_ERROR_RESPONSE_DEFAULT_OFF_RSVDP_1_SHIFT (1U)
/*! RSVDP_1 - Reserved for future use. */
#define PCIE_AMBA_ERROR_RESPONSE_DEFAULT_OFF_RSVDP_1(x) (((uint32_t)(((uint32_t)(x)) << PCIE_AMBA_ERROR_RESPONSE_DEFAULT_OFF_RSVDP_1_SHIFT)) & PCIE_AMBA_ERROR_RESPONSE_DEFAULT_OFF_RSVDP_1_MASK)

#define PCIE_AMBA_ERROR_RESPONSE_DEFAULT_OFF_AMBA_ERROR_RESPONSE_VENDORID_MASK (0x4U)
#define PCIE_AMBA_ERROR_RESPONSE_DEFAULT_OFF_AMBA_ERROR_RESPONSE_VENDORID_SHIFT (2U)
/*! AMBA_ERROR_RESPONSE_VENDORID - Vendor ID Non-existent Slave Error Response Mapping. Determines
 *    the AXI slave response for errors on reads to non-existent Vendor ID register. For more details
 *    see "Error Handling" in the AXI chapter of the Databook. AHB: - 0: OKAY (with FFFF data). The
 *    controller ignores the setting in the bit when bit 0 of this register is '0'. - 1: ERROR AXI:
 *    - 0: OKAY (with FFFF data). - 1: SLVERR/DECERR (the AXI_ERROR_RESPONSE_MAP field determines
 *    the PCIe-to-AXI Slave error response mapping) Note: This register field is sticky.
 */
#define PCIE_AMBA_ERROR_RESPONSE_DEFAULT_OFF_AMBA_ERROR_RESPONSE_VENDORID(x) (((uint32_t)(((uint32_t)(x)) << PCIE_AMBA_ERROR_RESPONSE_DEFAULT_OFF_AMBA_ERROR_RESPONSE_VENDORID_SHIFT)) & PCIE_AMBA_ERROR_RESPONSE_DEFAULT_OFF_AMBA_ERROR_RESPONSE_VENDORID_MASK)

#define PCIE_AMBA_ERROR_RESPONSE_DEFAULT_OFF_AMBA_ERROR_RESPONSE_CRS_MASK (0x18U)
#define PCIE_AMBA_ERROR_RESPONSE_DEFAULT_OFF_AMBA_ERROR_RESPONSE_CRS_SHIFT (3U)
/*! AMBA_ERROR_RESPONSE_CRS - CRS Slave Error Response Mapping. Determines the AXI slave response
 *    for CRS completions. For more details see "Error Handling" in the AXI chapter of the Databook.
 *    AHB: - always returns OKAY AXI: - 00: OKAY - 01: OKAY with all FFFF_FFFF data for all CRS
 *    completions - 10: OKAY with FFFF_0001 data for CRS completions to vendor ID read requests, OKAY
 *    with FFFF_FFFF data for all other CRS completions - 11: SLVERR/DECERR (the AXI_ERROR_RESPONSE_MAP
 *    field determines the PCIe-to-AXI Slave error response mapping) Note: This register field is
 *    sticky.
 */
#define PCIE_AMBA_ERROR_RESPONSE_DEFAULT_OFF_AMBA_ERROR_RESPONSE_CRS(x) (((uint32_t)(((uint32_t)(x)) << PCIE_AMBA_ERROR_RESPONSE_DEFAULT_OFF_AMBA_ERROR_RESPONSE_CRS_SHIFT)) & PCIE_AMBA_ERROR_RESPONSE_DEFAULT_OFF_AMBA_ERROR_RESPONSE_CRS_MASK)

#define PCIE_AMBA_ERROR_RESPONSE_DEFAULT_OFF_RSVDP_5_MASK (0x3E0U)
#define PCIE_AMBA_ERROR_RESPONSE_DEFAULT_OFF_RSVDP_5_SHIFT (5U)
/*! RSVDP_5 - Reserved for future use. */
#define PCIE_AMBA_ERROR_RESPONSE_DEFAULT_OFF_RSVDP_5(x) (((uint32_t)(((uint32_t)(x)) << PCIE_AMBA_ERROR_RESPONSE_DEFAULT_OFF_RSVDP_5_SHIFT)) & PCIE_AMBA_ERROR_RESPONSE_DEFAULT_OFF_RSVDP_5_MASK)

#define PCIE_AMBA_ERROR_RESPONSE_DEFAULT_OFF_AMBA_ERROR_RESPONSE_MAP_MASK (0xFC00U)
#define PCIE_AMBA_ERROR_RESPONSE_DEFAULT_OFF_AMBA_ERROR_RESPONSE_MAP_SHIFT (10U)
/*! AMBA_ERROR_RESPONSE_MAP - AXI Slave Response Error Map. Allows you to selectively map the errors
 *    received from the PCIe completion (for non-posted requests) to the AXI slave responses,
 *    slv_rresp or slv_bresp. The recommended setting is SLVERR. CRS is always mapped to OKAY. - [0] - 0:
 *    UR (unsupported request) -> DECERR - 1: UR (unsupported request) -> SLVERR - [1] - 0: CRS
 *    (configuration retry status) -> DECERR - 1: CRS (configuration retry status) -> SLVERR - [2] - 0:
 *    CA (completer abort) -> DECERR - 1: CA (completer abort) -> SLVERR - [3]: Reserved - [4]:
 *    Reserved - [5]: - 0: Completion Timeout -> DECERR - 1: Completion Timeout -> SLVERR The AXI
 *    bridge internally drops (processes internally but not passed to your application) a completion that
 *    has been marked by the Rx filter as UC or MLF, and does not pass its status directly down to
 *    the slave interface. It waits for a timeout and then signals "Completion Timeout" to the slave
 *    interface. The controller sets the AXI slave read databus to 0xFFFF for all error responses.
 *    Note: This register field is sticky.
 */
#define PCIE_AMBA_ERROR_RESPONSE_DEFAULT_OFF_AMBA_ERROR_RESPONSE_MAP(x) (((uint32_t)(((uint32_t)(x)) << PCIE_AMBA_ERROR_RESPONSE_DEFAULT_OFF_AMBA_ERROR_RESPONSE_MAP_SHIFT)) & PCIE_AMBA_ERROR_RESPONSE_DEFAULT_OFF_AMBA_ERROR_RESPONSE_MAP_MASK)

#define PCIE_AMBA_ERROR_RESPONSE_DEFAULT_OFF_RSVDP_16_MASK (0xFFFF0000U)
#define PCIE_AMBA_ERROR_RESPONSE_DEFAULT_OFF_RSVDP_16_SHIFT (16U)
/*! RSVDP_16 - Reserved for future use. */
#define PCIE_AMBA_ERROR_RESPONSE_DEFAULT_OFF_RSVDP_16(x) (((uint32_t)(((uint32_t)(x)) << PCIE_AMBA_ERROR_RESPONSE_DEFAULT_OFF_RSVDP_16_SHIFT)) & PCIE_AMBA_ERROR_RESPONSE_DEFAULT_OFF_RSVDP_16_MASK)
/*! @} */

/*! @name AMBA_LINK_TIMEOUT_OFF - Link Down AXI Bridge Slave Timeout Register. */
/*! @{ */

#define PCIE_AMBA_LINK_TIMEOUT_OFF_LINK_TIMEOUT_PERIOD_DEFAULT_MASK (0xFFU)
#define PCIE_AMBA_LINK_TIMEOUT_OFF_LINK_TIMEOUT_PERIOD_DEFAULT_SHIFT (0U)
/*! LINK_TIMEOUT_PERIOD_DEFAULT - Timeout Value (ms). The timer will timeout and then flush the
 *    bridge TX request queues after this amount of time. The timer counts when there are pending
 *    outbound AXI slave interface requests and the PCIe TX link is not transmitting any of these
 *    requests. The timer is clocked by core_clk. For an M-PCIe configuration: - Time unit of this field is
 *    4 ms. - Margin of error for RateA clock is < 1%. - Margin of error for RateB clock is between
 *    16% and 17%. Note: This register field is sticky.
 */
#define PCIE_AMBA_LINK_TIMEOUT_OFF_LINK_TIMEOUT_PERIOD_DEFAULT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_AMBA_LINK_TIMEOUT_OFF_LINK_TIMEOUT_PERIOD_DEFAULT_SHIFT)) & PCIE_AMBA_LINK_TIMEOUT_OFF_LINK_TIMEOUT_PERIOD_DEFAULT_MASK)

#define PCIE_AMBA_LINK_TIMEOUT_OFF_LINK_TIMEOUT_ENABLE_DEFAULT_MASK (0x100U)
#define PCIE_AMBA_LINK_TIMEOUT_OFF_LINK_TIMEOUT_ENABLE_DEFAULT_SHIFT (8U)
/*! LINK_TIMEOUT_ENABLE_DEFAULT - Disable Flush. You can disable the flush feature by setting this field to "1". Note: This register field is sticky. */
#define PCIE_AMBA_LINK_TIMEOUT_OFF_LINK_TIMEOUT_ENABLE_DEFAULT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_AMBA_LINK_TIMEOUT_OFF_LINK_TIMEOUT_ENABLE_DEFAULT_SHIFT)) & PCIE_AMBA_LINK_TIMEOUT_OFF_LINK_TIMEOUT_ENABLE_DEFAULT_MASK)

#define PCIE_AMBA_LINK_TIMEOUT_OFF_RSVDP_9_MASK  (0xFFFFFE00U)
#define PCIE_AMBA_LINK_TIMEOUT_OFF_RSVDP_9_SHIFT (9U)
/*! RSVDP_9 - Reserved for future use. */
#define PCIE_AMBA_LINK_TIMEOUT_OFF_RSVDP_9(x)    (((uint32_t)(((uint32_t)(x)) << PCIE_AMBA_LINK_TIMEOUT_OFF_RSVDP_9_SHIFT)) & PCIE_AMBA_LINK_TIMEOUT_OFF_RSVDP_9_MASK)
/*! @} */

/*! @name AMBA_ORDERING_CTRL_OFF - AMBA Ordering Control. */
/*! @{ */

#define PCIE_AMBA_ORDERING_CTRL_OFF_RSVDP_0_MASK (0x1U)
#define PCIE_AMBA_ORDERING_CTRL_OFF_RSVDP_0_SHIFT (0U)
/*! RSVDP_0 - Reserved for future use. */
#define PCIE_AMBA_ORDERING_CTRL_OFF_RSVDP_0(x)   (((uint32_t)(((uint32_t)(x)) << PCIE_AMBA_ORDERING_CTRL_OFF_RSVDP_0_SHIFT)) & PCIE_AMBA_ORDERING_CTRL_OFF_RSVDP_0_MASK)

#define PCIE_AMBA_ORDERING_CTRL_OFF_AX_SNP_EN_MASK (0x2U)
#define PCIE_AMBA_ORDERING_CTRL_OFF_AX_SNP_EN_SHIFT (1U)
/*! AX_SNP_EN - AXI Serialize Non-Posted Requests Enable. This field enables the AXI Bridge to
 *    serialize same ID Non-Posted Read/Write Requests on the wire. Serialization implies one outstanding
 *    same ID NP Read or Write on the wire and used to avoid AXI RAR and WAW hazards at the remote
 *    link partner. For more details, see the "Optional Serialization of AXI Slave Non-posted
 *    Requests" section in the AXI chapter of the Databook.
 */
#define PCIE_AMBA_ORDERING_CTRL_OFF_AX_SNP_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_AMBA_ORDERING_CTRL_OFF_AX_SNP_EN_SHIFT)) & PCIE_AMBA_ORDERING_CTRL_OFF_AX_SNP_EN_MASK)

#define PCIE_AMBA_ORDERING_CTRL_OFF_RSVDP_2_MASK (0x4U)
#define PCIE_AMBA_ORDERING_CTRL_OFF_RSVDP_2_SHIFT (2U)
/*! RSVDP_2 - Reserved for future use. */
#define PCIE_AMBA_ORDERING_CTRL_OFF_RSVDP_2(x)   (((uint32_t)(((uint32_t)(x)) << PCIE_AMBA_ORDERING_CTRL_OFF_RSVDP_2_SHIFT)) & PCIE_AMBA_ORDERING_CTRL_OFF_RSVDP_2_MASK)

#define PCIE_AMBA_ORDERING_CTRL_OFF_AX_MSTR_ORDR_P_EVENT_SEL_MASK (0x18U)
#define PCIE_AMBA_ORDERING_CTRL_OFF_AX_MSTR_ORDR_P_EVENT_SEL_SHIFT (3U)
/*! AX_MSTR_ORDR_P_EVENT_SEL - AXI Master Posted Ordering Event Selector. This field selects how the
 *    master interface determines when a P write is completed when enforcing the PCIe ordering
 *    rule, "NP must not pass P" at the AXI Master Interface. The AXI protocol does not support ordering
 *    between channels. Therefore, NP reads can pass P on your AXI bus fabric. This can result in
 *    an ordering violation when the read overtakes a P that is going to the same address. Therefore,
 *    the bridge master does not issue any NP requests until all outstanding P writes reach their
 *    destination. It does this by waiting for the all of the write responses on the B channel. This
 *    can affect the performance of the master read channel. For scenarios where the interconnect
 *    serializes the AXI master "AW", "W" and "AR" channels,you can increase the performance by
 *    reducing the need to wait until the complete Posted transaction has effectively reached the
 *    application slave. - 00: B'last event: wait for the all of the write responses on the B channel
 *    thereby ensuring that the complete Posted transaction has effectively reached the application slave
 *    (default). - 01: AW'last event: wait until the complete Posted transaction has left the AXI
 *    address channel at the bridge master. - 10: W'last event: wait until the complete Posted
 *    transaction has left the AXI data channel at the bridge master. - 11: Reserved Note 2: This setting
 *    will not affect: - MSI interrupt catcher and P data ordering. This is always driven by the
 *    B'last event. - DMA read engine TLP ordering. This is always driven by the B'last event. - NP
 *    write transactions which are always serialized with P write transactions.
 */
#define PCIE_AMBA_ORDERING_CTRL_OFF_AX_MSTR_ORDR_P_EVENT_SEL(x) (((uint32_t)(((uint32_t)(x)) << PCIE_AMBA_ORDERING_CTRL_OFF_AX_MSTR_ORDR_P_EVENT_SEL_SHIFT)) & PCIE_AMBA_ORDERING_CTRL_OFF_AX_MSTR_ORDR_P_EVENT_SEL_MASK)

#define PCIE_AMBA_ORDERING_CTRL_OFF_RSVDP_5_MASK (0x60U)
#define PCIE_AMBA_ORDERING_CTRL_OFF_RSVDP_5_SHIFT (5U)
/*! RSVDP_5 - Reserved for future use. */
#define PCIE_AMBA_ORDERING_CTRL_OFF_RSVDP_5(x)   (((uint32_t)(((uint32_t)(x)) << PCIE_AMBA_ORDERING_CTRL_OFF_RSVDP_5_SHIFT)) & PCIE_AMBA_ORDERING_CTRL_OFF_RSVDP_5_MASK)

#define PCIE_AMBA_ORDERING_CTRL_OFF_AX_MSTR_ZEROLREAD_FW_MASK (0x80U)
#define PCIE_AMBA_ORDERING_CTRL_OFF_AX_MSTR_ZEROLREAD_FW_SHIFT (7U)
/*! AX_MSTR_ZEROLREAD_FW - AXI Master Zero Length Read Forward to the application. The DW PCIe
 *    controller AXI bridge is able to terminate in order with the Posted transactions the zero length
 *    read, implementing the PCIe express flush semantics of the Posted transactions. - 0x0: The zero
 *    length Read is terminated at the DW PCIe AXI bridge master - 0x1: The zero length Read is
 *    forward to the application.
 */
#define PCIE_AMBA_ORDERING_CTRL_OFF_AX_MSTR_ZEROLREAD_FW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_AMBA_ORDERING_CTRL_OFF_AX_MSTR_ZEROLREAD_FW_SHIFT)) & PCIE_AMBA_ORDERING_CTRL_OFF_AX_MSTR_ZEROLREAD_FW_MASK)

#define PCIE_AMBA_ORDERING_CTRL_OFF_RSVDP_8_MASK (0xFFFFFF00U)
#define PCIE_AMBA_ORDERING_CTRL_OFF_RSVDP_8_SHIFT (8U)
/*! RSVDP_8 - Reserved for future use. */
#define PCIE_AMBA_ORDERING_CTRL_OFF_RSVDP_8(x)   (((uint32_t)(((uint32_t)(x)) << PCIE_AMBA_ORDERING_CTRL_OFF_RSVDP_8_SHIFT)) & PCIE_AMBA_ORDERING_CTRL_OFF_RSVDP_8_MASK)
/*! @} */

/*! @name AXI_MSTR_MSG_ADDR_LOW_OFF - Lower 20 bits of the programmable AXI address where Messages coming from wire are mapped to. */
/*! @{ */

#define PCIE_AXI_MSTR_MSG_ADDR_LOW_OFF_CFG_AXIMSTR_MSG_ADDR_LOW_RESERVED_MASK (0xFFFU)
#define PCIE_AXI_MSTR_MSG_ADDR_LOW_OFF_CFG_AXIMSTR_MSG_ADDR_LOW_RESERVED_SHIFT (0U)
/*! CFG_AXIMSTR_MSG_ADDR_LOW_RESERVED - Reserved for future use. Note: This register field is sticky. */
#define PCIE_AXI_MSTR_MSG_ADDR_LOW_OFF_CFG_AXIMSTR_MSG_ADDR_LOW_RESERVED(x) (((uint32_t)(((uint32_t)(x)) << PCIE_AXI_MSTR_MSG_ADDR_LOW_OFF_CFG_AXIMSTR_MSG_ADDR_LOW_RESERVED_SHIFT)) & PCIE_AXI_MSTR_MSG_ADDR_LOW_OFF_CFG_AXIMSTR_MSG_ADDR_LOW_RESERVED_MASK)

#define PCIE_AXI_MSTR_MSG_ADDR_LOW_OFF_CFG_AXIMSTR_MSG_ADDR_LOW_MASK (0xFFFFF000U)
#define PCIE_AXI_MSTR_MSG_ADDR_LOW_OFF_CFG_AXIMSTR_MSG_ADDR_LOW_SHIFT (12U)
/*! CFG_AXIMSTR_MSG_ADDR_LOW - Lower 20 bits of the programmable AXI address for Messages. Note: This register field is sticky. */
#define PCIE_AXI_MSTR_MSG_ADDR_LOW_OFF_CFG_AXIMSTR_MSG_ADDR_LOW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_AXI_MSTR_MSG_ADDR_LOW_OFF_CFG_AXIMSTR_MSG_ADDR_LOW_SHIFT)) & PCIE_AXI_MSTR_MSG_ADDR_LOW_OFF_CFG_AXIMSTR_MSG_ADDR_LOW_MASK)
/*! @} */

/*! @name AXI_MSTR_MSG_ADDR_HIGH_OFF - Upper 32 bits of the programmable AXI address where Messages coming from wire are mapped to. */
/*! @{ */

#define PCIE_AXI_MSTR_MSG_ADDR_HIGH_OFF_CFG_AXIMSTR_MSG_ADDR_HIGH_MASK (0xFFFFFFFFU)
#define PCIE_AXI_MSTR_MSG_ADDR_HIGH_OFF_CFG_AXIMSTR_MSG_ADDR_HIGH_SHIFT (0U)
/*! CFG_AXIMSTR_MSG_ADDR_HIGH - Upper 32 bits of the programmable AXI address for Messages. Note: This register field is sticky. */
#define PCIE_AXI_MSTR_MSG_ADDR_HIGH_OFF_CFG_AXIMSTR_MSG_ADDR_HIGH(x) (((uint32_t)(((uint32_t)(x)) << PCIE_AXI_MSTR_MSG_ADDR_HIGH_OFF_CFG_AXIMSTR_MSG_ADDR_HIGH_SHIFT)) & PCIE_AXI_MSTR_MSG_ADDR_HIGH_OFF_CFG_AXIMSTR_MSG_ADDR_HIGH_MASK)
/*! @} */

/*! @name PCIE_VERSION_NUMBER_OFF - PCIe Controller IIP Release Version Number. */
/*! @{ */

#define PCIE_PCIE_VERSION_NUMBER_OFF_VERSION_NUMBER_MASK (0xFFFFFFFFU)
#define PCIE_PCIE_VERSION_NUMBER_OFF_VERSION_NUMBER_SHIFT (0U)
/*! VERSION_NUMBER - Version Number. */
#define PCIE_PCIE_VERSION_NUMBER_OFF_VERSION_NUMBER(x) (((uint32_t)(((uint32_t)(x)) << PCIE_PCIE_VERSION_NUMBER_OFF_VERSION_NUMBER_SHIFT)) & PCIE_PCIE_VERSION_NUMBER_OFF_VERSION_NUMBER_MASK)
/*! @} */

/*! @name PCIE_VERSION_TYPE_OFF - PCIe Controller IIP Release Version Type. */
/*! @{ */

#define PCIE_PCIE_VERSION_TYPE_OFF_VERSION_TYPE_MASK (0xFFFFFFFFU)
#define PCIE_PCIE_VERSION_TYPE_OFF_VERSION_TYPE_SHIFT (0U)
/*! VERSION_TYPE - Version Type. */
#define PCIE_PCIE_VERSION_TYPE_OFF_VERSION_TYPE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_PCIE_VERSION_TYPE_OFF_VERSION_TYPE_SHIFT)) & PCIE_PCIE_VERSION_TYPE_OFF_VERSION_TYPE_MASK)
/*! @} */

/*! @name AUX_CLK_FREQ_OFF - Auxiliary Clock Frequency Control Register. */
/*! @{ */

#define PCIE_AUX_CLK_FREQ_OFF_AUX_CLK_FREQ_MASK  (0x3FFU)
#define PCIE_AUX_CLK_FREQ_OFF_AUX_CLK_FREQ_SHIFT (0U)
/*! AUX_CLK_FREQ - The aux_clk frequency in MHz. This value is used to provide a 1 us reference for
 *    counting time during low-power states with aux_clk when the PHY has removed the pipe_clk.
 *    Frequencies lower than 1 MHz are possible but with a loss of accuracy in the time counted. If the
 *    actual frequency (f) of aux_clk does not exactly match the programmed frequency (f_prog), then
 *    there is an error in the time counted by the controller that can be expressed in percentage
 *    as: err% = (f_prog/f-1)*100. For example if f=2.5 MHz and f_prog=3 MHz, then err%
 *    =(3/2.5-1)*100 =20%, meaning that the time counted by the controller on aux_clk will be 20% greater than
 *    the time in us programmed in the corresponding time register (for example T_POWER_ON). Note:
 *    This register field is sticky.
 */
#define PCIE_AUX_CLK_FREQ_OFF_AUX_CLK_FREQ(x)    (((uint32_t)(((uint32_t)(x)) << PCIE_AUX_CLK_FREQ_OFF_AUX_CLK_FREQ_SHIFT)) & PCIE_AUX_CLK_FREQ_OFF_AUX_CLK_FREQ_MASK)

#define PCIE_AUX_CLK_FREQ_OFF_RSVDP_10_MASK      (0xFFFFFC00U)
#define PCIE_AUX_CLK_FREQ_OFF_RSVDP_10_SHIFT     (10U)
/*! RSVDP_10 - Reserved for future use. */
#define PCIE_AUX_CLK_FREQ_OFF_RSVDP_10(x)        (((uint32_t)(((uint32_t)(x)) << PCIE_AUX_CLK_FREQ_OFF_RSVDP_10_SHIFT)) & PCIE_AUX_CLK_FREQ_OFF_RSVDP_10_MASK)
/*! @} */

/*! @name L1_SUBSTATES_OFF - L1 Substates Timing Register. */
/*! @{ */

#define PCIE_L1_SUBSTATES_OFF_L1SUB_T_POWER_OFF_MASK (0x3U)
#define PCIE_L1_SUBSTATES_OFF_L1SUB_T_POWER_OFF_SHIFT (0U)
/*! L1SUB_T_POWER_OFF - Duration (in 1us units) of L1.2.Entry. Range is 0.3. Note: The timeout value
 *    can vary by 50%. Note: This register field is sticky.
 */
#define PCIE_L1_SUBSTATES_OFF_L1SUB_T_POWER_OFF(x) (((uint32_t)(((uint32_t)(x)) << PCIE_L1_SUBSTATES_OFF_L1SUB_T_POWER_OFF_SHIFT)) & PCIE_L1_SUBSTATES_OFF_L1SUB_T_POWER_OFF_MASK)

#define PCIE_L1_SUBSTATES_OFF_L1SUB_T_L1_2_MASK  (0x3CU)
#define PCIE_L1_SUBSTATES_OFF_L1SUB_T_L1_2_SHIFT (2U)
/*! L1SUB_T_L1_2 - Duration (in 1us units) of L1.2. Range is 0.15. Note: The timeout value can vary
 *    by 50%. Note: This register field is sticky.
 */
#define PCIE_L1_SUBSTATES_OFF_L1SUB_T_L1_2(x)    (((uint32_t)(((uint32_t)(x)) << PCIE_L1_SUBSTATES_OFF_L1SUB_T_L1_2_SHIFT)) & PCIE_L1_SUBSTATES_OFF_L1SUB_T_L1_2_MASK)

#define PCIE_L1_SUBSTATES_OFF_L1SUB_T_PCLKACK_MASK (0xC0U)
#define PCIE_L1_SUBSTATES_OFF_L1SUB_T_PCLKACK_SHIFT (6U)
/*! L1SUB_T_PCLKACK - Max delay (in 1us units) between a MAC request to remove the clock on
 *    mac_phy_pclkreq_n and a PHY response on phy_mac_pclkack_n. If the PHY does not respond within this
 *    time the request is aborted. Range is 0..3 Note: This register field is sticky.
 */
#define PCIE_L1_SUBSTATES_OFF_L1SUB_T_PCLKACK(x) (((uint32_t)(((uint32_t)(x)) << PCIE_L1_SUBSTATES_OFF_L1SUB_T_PCLKACK_SHIFT)) & PCIE_L1_SUBSTATES_OFF_L1SUB_T_PCLKACK_MASK)

#define PCIE_L1_SUBSTATES_OFF_RSVDP_8_MASK       (0xFFFFFF00U)
#define PCIE_L1_SUBSTATES_OFF_RSVDP_8_SHIFT      (8U)
/*! RSVDP_8 - Reserved for future use. */
#define PCIE_L1_SUBSTATES_OFF_RSVDP_8(x)         (((uint32_t)(((uint32_t)(x)) << PCIE_L1_SUBSTATES_OFF_RSVDP_8_SHIFT)) & PCIE_L1_SUBSTATES_OFF_RSVDP_8_MASK)
/*! @} */

/*! @name IATU_REGION_CTRL_1_OFF_OUTBOUND_0 - iATU Region Control 1 Register. */
/*! @{ */

#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_0_TYPE_MASK (0x1FU)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_0_TYPE_SHIFT (0U)
/*! TYPE - When the address of an outbound TLP is matched to this region, then the TYPE field of the
 *    TLP is changed to the value in this register. Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_0_TYPE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_0_TYPE_SHIFT)) & PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_0_TYPE_MASK)

#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_0_TC_MASK (0xE0U)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_0_TC_SHIFT (5U)
/*! TC - When the address of an outbound TLP is matched to this region, then the TC field of the TLP
 *    is changed to the value in this register. Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_0_TC(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_0_TC_SHIFT)) & PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_0_TC_MASK)

#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_0_TD_MASK (0x100U)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_0_TD_SHIFT (8U)
/*! TD - When the address of an outbound TLP is matched to this region, then the TD field of the TLP
 *    is changed to the value in this register. Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_0_TD(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_0_TD_SHIFT)) & PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_0_TD_MASK)

#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_0_ATTR_MASK (0x600U)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_0_ATTR_SHIFT (9U)
/*! ATTR - When the address of an outbound TLP is matched to this region, then the ATTR field of the
 *    TLP is changed to the value in this register. Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_0_ATTR(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_0_ATTR_SHIFT)) & PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_0_ATTR_MASK)

#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_0_INCREASE_REGION_SIZE_MASK (0x2000U)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_0_INCREASE_REGION_SIZE_SHIFT (13U)
/*! INCREASE_REGION_SIZE - Increase the maximum ATU Region size. When set, the maximum ATU Region
 *    size is determined by CX_ATU_MAX_REGION_SIZEMaximum Size of iATU Region When clear, the maximum
 *    ATU Region size is 4 GB (default). Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_0_INCREASE_REGION_SIZE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_0_INCREASE_REGION_SIZE_SHIFT)) & PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_0_INCREASE_REGION_SIZE_MASK)

#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_0_CTRL_1_FUNC_NUM_MASK (0x700000U)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_0_CTRL_1_FUNC_NUM_SHIFT (20U)
/*! CTRL_1_FUNC_NUM - Function Number. - When the address of an outbound TLP is matched to this
 *    region and the FUNC_BYPASS field in the "iATU Control 2 Register" is '0', then the function number
 *    used in generating the function part of the requester ID (RID) field of the TLP is taken from
 *    this 5-bit register. The value in this register must be 0x0 unless multifunction operation in
 *    the controller is enabled (CX_NFUNC > 1). - When you are using the AXI Bridge, then this
 *    field is swapped before AXI decomposition occurs so that the correct "Max_Read_Request_Size" and
 *    "Max_Payload_Size" values are used. Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_0_CTRL_1_FUNC_NUM(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_0_CTRL_1_FUNC_NUM_SHIFT)) & PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_0_CTRL_1_FUNC_NUM_MASK)
/*! @} */

/*! @name IATU_REGION_CTRL_2_OFF_OUTBOUND_0 - iATU Region Control 2 Register. */
/*! @{ */

#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_MSG_CODE_MASK (0xFFU)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_MSG_CODE_SHIFT (0U)
/*! MSG_CODE - MSG TLPs (Message Code). When the address of an outbound TLP is matched to this
 *    region, and the translated TLP TYPE field is Msg or MsgD; then the message field of the TLP is
 *    changed to the value in this register. Memory TLPs: (ST;Steering Tag). When the ST field of an
 *    outbound TLP is matched to this region, and the translated TLP TYPE field targets memory space;
 *    then the ST field of the TLP is changed to the value in this register. Only Valid when the
 *    CX_TPH_ENABLE configuration parameter is 1. Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_MSG_CODE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_MSG_CODE_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_MSG_CODE_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_TAG_MASK (0xFF00U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_TAG_SHIFT (8U)
/*! TAG - TAG. The substituted TAG field (byte 6) in the outgoing TLP header when TAG_SUBSTITUTE_EN
 *    is set. Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_TAG(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_TAG_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_TAG_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_TAG_SUBSTITUTE_EN_MASK (0x10000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_TAG_SUBSTITUTE_EN_SHIFT (16U)
/*! TAG_SUBSTITUTE_EN - TAG Substitute Enable. When enabled and region address is matched, the iATU
 *    substitutes the TAG field of the outbound TLP header with the contents of the TAG field in
 *    this register. The expected usage scenario is translation from AXI MWr to Vendor Defined
 *    Msg/MsgD. Note (CX_TPH_ENABLE=1): TAG substitution for MWr will not occur because this field (byte 6)
 *    in the TLP header is the ST field. ST substitution can still take place using the MSG_CODE
 *    field in IATU_REGION_CTRL_2_OFF_OUTBOUND_i. Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_TAG_SUBSTITUTE_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_TAG_SUBSTITUTE_EN_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_TAG_SUBSTITUTE_EN_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_FUNC_BYPASS_MASK (0x80000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_FUNC_BYPASS_SHIFT (19U)
/*! FUNC_BYPASS - Function Number Translation Bypass. In this mode, the function number of the
 *    translated TLP is taken from your application transmit interface and not from the CTRL_1_FUNC_NUM
 *    field of the "iATU Control 1 Register" or the VF_NUMBER field of the "iATU Control 3 Register."
 *    Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_FUNC_BYPASS(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_FUNC_BYPASS_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_FUNC_BYPASS_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_SNP_MASK (0x100000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_SNP_SHIFT (20U)
/*! SNP - Serialize Non-Posted Requests. In this mode, when the AXI Bridge is populated, same AXI ID
 *    Non-Posted Read/Write Requests are transmitted on the wire if there are no other same ID
 *    Non-Posted Requests outstanding. Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_SNP(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_SNP_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_SNP_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_INHIBIT_PAYLOAD_MASK (0x400000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_INHIBIT_PAYLOAD_SHIFT (22U)
/*! INHIBIT_PAYLOAD - Inhibit TLP Payload Data for TLP's in Matched Region; assign iATU region to be
 *    TLP without data. When enabled and region address is matched, the iATU marks all TLPs as
 *    having no payload data by forcing the TLP header Fmt[1] bit =0, regardless of the application
 *    inputs such as slv_wstrb. - 1: Fmt[1] =0 so that only TLP type without data is sent. For example,
 *    a Msg instead of MsgD will be sent. - 0: Fmt[1] =0/1 so that TLPs with or without data can be
 *    sent. Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_INHIBIT_PAYLOAD(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_INHIBIT_PAYLOAD_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_INHIBIT_PAYLOAD_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_HEADER_SUBSTITUTE_EN_MASK (0x800000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_HEADER_SUBSTITUTE_EN_SHIFT (23U)
/*! HEADER_SUBSTITUTE_EN - Header Substitute Enable. When enabled and region address is matched, the
 *    iATU fully substitutes bytes 8-11 (for 3 DWORD header) or bytes 12-15 (for 4 DWORD header) of
 *    the outbound TLP header with the contents of the LWR_TARGET_RW field in
 *    IATU_LWR_TARGET_ADDR_OFF_OUTBOUND_i. - 1: LWR_TARGET_RW in the iATU_LWR_TARGET_ADDR_OFF_OUTBOUND_i register is used
 *    to fill bytes 8-to-11 (for 3 DWORD header) or bytes 12-to-15 (for 4 DWORD header) of the
 *    translated TLP header. - 0: LWR_TARGET_RW in the iATU_LWR_TARGET_ADDR_OFF_OUTBOUND_i register
 *    forms the new address of the translated region. Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_HEADER_SUBSTITUTE_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_HEADER_SUBSTITUTE_EN_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_HEADER_SUBSTITUTE_EN_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_DMA_BYPASS_MASK (0x8000000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_DMA_BYPASS_SHIFT (27U)
/*! DMA_BYPASS - DMA Bypass Mode. Allows request TLPs which are initiated by the DMA controller to
 *    pass through the iATU untranslated. Note: This field is reserved for the SW product. You must
 *    set it to '0'. Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_DMA_BYPASS(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_DMA_BYPASS_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_DMA_BYPASS_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_CFG_SHIFT_MODE_MASK (0x10000000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_CFG_SHIFT_MODE_SHIFT (28U)
/*! CFG_SHIFT_MODE - CFG Shift Mode. The iATU uses bits [27:12] of the untranslated address (on the
 *    XALI0/1/2 interface or AXI slave interface address) to form the BDF number of the outgoing CFG
 *    TLP. This supports the Enhanced Configuration Address Mapping (ECAM) mechanism (Section 7.2.2
 *    of the PCI Express Base 3.1 Specification, revision 1.0) by allowing all outgoing I/O and MEM
 *    TLPs (that have been translated to CFG) to be mapped from memory space into any 256 MB region
 *    of the PCIe configuration space. Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_CFG_SHIFT_MODE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_CFG_SHIFT_MODE_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_CFG_SHIFT_MODE_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_INVERT_MODE_MASK (0x20000000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_INVERT_MODE_SHIFT (29U)
/*! INVERT_MODE - Invert Mode. When set the address matching region is inverted. Therefore, an
 *    address match occurs when the untranslated address is in the region outside the defined range (Base
 *    Address to Limit Address). Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_INVERT_MODE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_INVERT_MODE_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_INVERT_MODE_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_REGION_EN_MASK (0x80000000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_REGION_EN_SHIFT (31U)
/*! REGION_EN - Region Enable. This bit must be set to '1' for address translation to take place. Note: This register field is sticky. */
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_REGION_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_REGION_EN_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_0_REGION_EN_MASK)
/*! @} */

/*! @name IATU_LWR_BASE_ADDR_OFF_OUTBOUND_0 - iATU Lower Base Address Register. */
/*! @{ */

#define PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_0_LWR_BASE_HW_MASK (0xFFFFU)
#define PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_0_LWR_BASE_HW_SHIFT (0U)
/*! LWR_BASE_HW - Forms bits [n-1:0] of the start address of the address region to be translated.
 *    The start address must be aligned to a CX_ATU_MIN_REGION_SIZEMinimum Size of iATU Region kB
 *    boundary, so these bits are always 0. A write to this location is ignored by the PCIe controller.
 *    n is log2(CX_ATU_MIN_REGION_SIZEMinimum Size of iATU Region)
 */
#define PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_0_LWR_BASE_HW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_0_LWR_BASE_HW_SHIFT)) & PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_0_LWR_BASE_HW_MASK)

#define PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_0_LWR_BASE_RW_MASK (0xFFFF0000U)
#define PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_0_LWR_BASE_RW_SHIFT (16U)
/*! LWR_BASE_RW - Forms bits [31:n] of the start address of the address region to be translated. n
 *    is log2(CX_ATU_MIN_REGION_SIZEMinimum Size of iATU Region) Note: This register field is sticky.
 */
#define PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_0_LWR_BASE_RW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_0_LWR_BASE_RW_SHIFT)) & PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_0_LWR_BASE_RW_MASK)
/*! @} */

/*! @name IATU_UPPER_BASE_ADDR_OFF_OUTBOUND_0 - iATU Upper Base Address Register. */
/*! @{ */

#define PCIE_IATU_UPPER_BASE_ADDR_OFF_OUTBOUND_0_UPPER_BASE_RW_MASK (0xFFFFFFFFU)
#define PCIE_IATU_UPPER_BASE_ADDR_OFF_OUTBOUND_0_UPPER_BASE_RW_SHIFT (0U)
/*! UPPER_BASE_RW - Forms bits [63:32] of the start (and end) address of the address region to be
 *    translated. In systems with a 32-bit address space, this register is not used and therefore
 *    writing to this register has no effect. Note: This register field is sticky.
 */
#define PCIE_IATU_UPPER_BASE_ADDR_OFF_OUTBOUND_0_UPPER_BASE_RW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_UPPER_BASE_ADDR_OFF_OUTBOUND_0_UPPER_BASE_RW_SHIFT)) & PCIE_IATU_UPPER_BASE_ADDR_OFF_OUTBOUND_0_UPPER_BASE_RW_MASK)
/*! @} */

/*! @name IATU_LIMIT_ADDR_OFF_OUTBOUND_0 - iATU Limit Address Register. */
/*! @{ */

#define PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_0_LIMIT_ADDR_HW_MASK (0xFFFFU)
#define PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_0_LIMIT_ADDR_HW_SHIFT (0U)
/*! LIMIT_ADDR_HW - Forms lower bits of the end address of the address region to be translated. The
 *    end address must be aligned to a CX_ATU_MIN_REGION_SIZEMinimum Size of iATU Region kB
 *    boundary, so these bits are always 0. A write to this location is ignored by the PCIe controller.
 */
#define PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_0_LIMIT_ADDR_HW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_0_LIMIT_ADDR_HW_SHIFT)) & PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_0_LIMIT_ADDR_HW_MASK)

#define PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_0_LIMIT_ADDR_RW_MASK (0xFFFF0000U)
#define PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_0_LIMIT_ADDR_RW_SHIFT (16U)
/*! LIMIT_ADDR_RW - Forms upper bits of the end address of the address region to be translated. The
 *    end address must be aligned to a CX_ATU_MIN_REGION_SIZEMinimum Size of iATU Region kB
 *    boundary, so these bits are always 0. A write to this location is ignored by the PCIe controller.
 *    Note: This register field is sticky.
 */
#define PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_0_LIMIT_ADDR_RW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_0_LIMIT_ADDR_RW_SHIFT)) & PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_0_LIMIT_ADDR_RW_MASK)
/*! @} */

/*! @name IATU_LWR_TARGET_ADDR_OFF_OUTBOUND_0 - iATU Lower Target Address Register. */
/*! @{ */

#define PCIE_IATU_LWR_TARGET_ADDR_OFF_OUTBOUND_0_LWR_TARGET_RW_OUTBOUND_MASK (0xFFFFFFFFU)
#define PCIE_IATU_LWR_TARGET_ADDR_OFF_OUTBOUND_0_LWR_TARGET_RW_OUTBOUND_SHIFT (0U)
/*! LWR_TARGET_RW_OUTBOUND - When HEADER_SUBSTITUTE_EN in IATU_REGION_CTRL_2_OFF_OUTBOUND_ is '0'
 *    (normal operation): - LWR_TARGET_RW[31:n] forms MSB's of the Lower Target part of the new
 *    address of the translated region; - LWR_TARGET_RW[n-1:0] are not used. (The start address must be
 *    aligned to a CX_ATU_MIN_REGION_SIZEMinimum Size of iATU Region kB boundary, so the lower bits of
 *    the start address of the new address of the translated region (bits n-1:0) are always '0'). -
 *    n is log2(CX_ATU_MIN_REGION_SIZEMinimum Size of iATU Region). When HEADER_SUBSTITUTE_EN in
 *    IATU_REGION_CTRL_2_OFF_OUTBOUND_i is '1': - LWR_TARGET_RW[31:0] forms bytes 8-11 (for 3 dword
 *    header) or bytes 12-15 (for 4 dword header) of the outbound TLP header. Usage scenarios include
 *    the transmission of Vendor Defined Messages where the controller determines the content of
 *    bytes 12 to 15 of the TLP header. Note: This register field is sticky.
 */
#define PCIE_IATU_LWR_TARGET_ADDR_OFF_OUTBOUND_0_LWR_TARGET_RW_OUTBOUND(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LWR_TARGET_ADDR_OFF_OUTBOUND_0_LWR_TARGET_RW_OUTBOUND_SHIFT)) & PCIE_IATU_LWR_TARGET_ADDR_OFF_OUTBOUND_0_LWR_TARGET_RW_OUTBOUND_MASK)
/*! @} */

/*! @name IATU_UPPER_TARGET_ADDR_OFF_OUTBOUND_0 - iATU Upper Target Address Register. */
/*! @{ */

#define PCIE_IATU_UPPER_TARGET_ADDR_OFF_OUTBOUND_0_UPPER_TARGET_RW_MASK (0xFFFFFFFFU)
#define PCIE_IATU_UPPER_TARGET_ADDR_OFF_OUTBOUND_0_UPPER_TARGET_RW_SHIFT (0U)
/*! UPPER_TARGET_RW - Forms bits [63:32] of the start address (Upper Target part) of the new address
 *    of the translated region. Note: This register field is sticky.
 */
#define PCIE_IATU_UPPER_TARGET_ADDR_OFF_OUTBOUND_0_UPPER_TARGET_RW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_UPPER_TARGET_ADDR_OFF_OUTBOUND_0_UPPER_TARGET_RW_SHIFT)) & PCIE_IATU_UPPER_TARGET_ADDR_OFF_OUTBOUND_0_UPPER_TARGET_RW_MASK)
/*! @} */

/*! @name IATU_REGION_CTRL_1_OFF_INBOUND_0 - iATU Region Control 1 Register. */
/*! @{ */

#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_0_TYPE_MASK (0x1FU)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_0_TYPE_SHIFT (0U)
/*! TYPE - When the TYPE field of an inbound TLP is matched to this value, then address translation
 *    proceeds (when all other enabled field-matches are successful). Note: This register field is
 *    sticky.
 */
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_0_TYPE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_0_TYPE_SHIFT)) & PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_0_TYPE_MASK)

#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_0_TC_MASK (0xE0U)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_0_TC_SHIFT (5U)
/*! TC - When the TC field of an inbound TLP is matched to this value, then address translation
 *    proceeds (when all other enabled field-matches are successful). This check is only performed if
 *    the "TC Match Enable" bit of the "iATU Control 2 Register" is set. Note: This register field is
 *    sticky.
 */
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_0_TC(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_0_TC_SHIFT)) & PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_0_TC_MASK)

#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_0_TD_MASK (0x100U)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_0_TD_SHIFT (8U)
/*! TD - When the TD field of an inbound TLP is matched to this value, then address translation
 *    proceeds (when all other enabled field-matches are successful). This check is only performed if
 *    the "TD Match Enable" bit of the "iATU Control 2 Register" is set. Note: This register field is
 *    sticky.
 */
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_0_TD(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_0_TD_SHIFT)) & PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_0_TD_MASK)

#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_0_ATTR_MASK (0x600U)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_0_ATTR_SHIFT (9U)
/*! ATTR - When the ATTR field of an inbound TLP is matched to this value, then address translation
 *    proceeds (when all other enabled field-matches are successful). This check is only performed
 *    if the "ATTR Match Enable" bit of the "iATU Control 2 Register" is set. Note: This register
 *    field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_0_ATTR(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_0_ATTR_SHIFT)) & PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_0_ATTR_MASK)

#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_0_INCREASE_REGION_SIZE_MASK (0x2000U)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_0_INCREASE_REGION_SIZE_SHIFT (13U)
/*! INCREASE_REGION_SIZE - Increase the maximum ATU Region size. When set, the maximum ATU Region
 *    size is determined by CX_ATU_MAX_REGION_SIZEMaximum Size of iATU Region When clear, the maximum
 *    ATU Region size is 4 GB (default). Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_0_INCREASE_REGION_SIZE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_0_INCREASE_REGION_SIZE_SHIFT)) & PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_0_INCREASE_REGION_SIZE_MASK)

#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_0_CTRL_1_FUNC_NUM_MASK (0x700000U)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_0_CTRL_1_FUNC_NUM_SHIFT (20U)
/*! CTRL_1_FUNC_NUM - Function Number. - MEM-I/O: When the Address and BAR matching logic in the
 *    controller indicate that a MEM-I/O transaction matches a BAR in the function corresponding to
 *    this value, then address translation proceeds. This check is only performed if the "Function
 *    Number Match Enable" bit of the "iATU Control 2 Register" is set. - CFG0/CFG1: When the
 *    destination function number as specified in the routing ID of the TLP header matches the function, then
 *    address translation proceeds. This check is only performed if the "Function Number Match
 *    Enable" bit of the "iATU Control 2 Register" is set. Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_0_CTRL_1_FUNC_NUM(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_0_CTRL_1_FUNC_NUM_SHIFT)) & PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_0_CTRL_1_FUNC_NUM_MASK)
/*! @} */

/*! @name IATU_REGION_CTRL_2_OFF_INBOUND_0 - iATU Region Control 2 Register. */
/*! @{ */

#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_MSG_CODE_MASK (0xFFU)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_MSG_CODE_SHIFT (0U)
/*! MSG_CODE - MSG TLPs: (Message Code). When the TYPE field of an inbound Msg/MsgD TLP is matched
 *    to this value, then address translation proceeds (when all other enabled field-matches are
 *    successful). This check is only performed if the "Message Code Match Enable" bit of the "iATU
 *    Control 2 Register" is set. Memory TLPs: (ST;Steering Tag). When the ST field of an inbound TLP is
 *    matched to this value, then address translation proceeds. This check is only performed if the
 *    "ST Match Enable" bit of the "iATU Control2 Register" is set. The setting is independent of
 *    the setting of the TH field. Only Valid when the CX_TPH_ENABLE configuration parameter is 1.
 *    Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_MSG_CODE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_MSG_CODE_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_MSG_CODE_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_BAR_NUM_MASK (0x700U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_BAR_NUM_SHIFT (8U)
/*! BAR_NUM - BAR Number. When the BAR number of an inbound MEM or IO TLP " that is matched by the
 *    normal internal BAR address matching mechanism " is the same as this field, address translation
 *    proceeds (when all other enabled field-matches are successful). This check is only performed
 *    if the "Match Mode" bit of the "iATU Control 2 Register" is set. - 000b - BAR0 - 001b - BAR1 -
 *    010b - BAR2 - 011b - BAR3 - 100b - BAR4 - 101b - BAR5 - 110b - ROM - 111b - reserved - IO
 *    translation would require either 00100b or 00101b in the inbound TLP TYPE; the BAR Number set in
 *    the range 000b - 101b and that BAR configured as an IO BAR. Note: This register field is
 *    sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_BAR_NUM(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_BAR_NUM_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_BAR_NUM_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_MSG_TYPE_MATCH_MODE_MASK (0x2000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_MSG_TYPE_MATCH_MODE_SHIFT (13U)
/*! MSG_TYPE_MATCH_MODE - Message Type Match Mode. When enabled, and if single address location
 *    translate enable is set, then inbound TLPs of type MSG/MSGd which match the type field of the
 *    iatu_region_ctrl_1_OFF_inbound register (=>TYPE[4:3]=2'b10) will be translated. Message type match
 *    mode overrides any value of MATCH_MODE field in this register. Usage scenarios for this are
 *    translation of VDM or ATS messages when AXI bridge is configured on client interface. Note:
 *    This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_MSG_TYPE_MATCH_MODE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_MSG_TYPE_MATCH_MODE_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_MSG_TYPE_MATCH_MODE_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_TC_MATCH_EN_MASK (0x4000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_TC_MATCH_EN_SHIFT (14U)
/*! TC_MATCH_EN - TC Match Enable. Ensures that a successful TC TLP field comparison match (see TC
 *    field of the "iATU Control 1 Register") occurs for address translation to proceed. Note: This
 *    register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_TC_MATCH_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_TC_MATCH_EN_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_TC_MATCH_EN_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_TD_MATCH_EN_MASK (0x8000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_TD_MATCH_EN_SHIFT (15U)
/*! TD_MATCH_EN - TD Match Enable. Ensures that a successful TD TLP field comparison match (see TD
 *    field of the "iATU Control 1 Register") occurs for address translation to proceed. Note: This
 *    register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_TD_MATCH_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_TD_MATCH_EN_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_TD_MATCH_EN_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_ATTR_MATCH_EN_MASK (0x10000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_ATTR_MATCH_EN_SHIFT (16U)
/*! ATTR_MATCH_EN - ATTR Match Enable. Ensures that a successful ATTR TLP field comparison match
 *    (see ATTR field of the "iATU Control 1 Register") occurs for address translation to proceed.
 *    Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_ATTR_MATCH_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_ATTR_MATCH_EN_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_ATTR_MATCH_EN_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_FUNC_NUM_MATCH_EN_MASK (0x80000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_FUNC_NUM_MATCH_EN_SHIFT (19U)
/*! FUNC_NUM_MATCH_EN - Function Number Match Enable. Ensures that a successful Function Number TLP
 *    field comparison match (see Function Number field of the "iATU Control 1 Register") occurs (in
 *    MEM-I/O and CFG0/CFG1 transactions) for address translation to proceed. Note: This register
 *    field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_FUNC_NUM_MATCH_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_FUNC_NUM_MATCH_EN_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_FUNC_NUM_MATCH_EN_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_MSG_CODE_MATCH_EN_MASK (0x200000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_MSG_CODE_MATCH_EN_SHIFT (21U)
/*! MSG_CODE_MATCH_EN - Message Code Match Enable (Msg TLPS). Ensures that a successful message Code
 *    TLP field comparison match (see Message Code field of the "iATU Control 2 Register") occurs
 *    (in MSG transactions) for address translation to proceed. ST Match Enable (Mem TLPs). Ensures
 *    that a successful ST TLP field comparison match (see ST field of the "iATU Control 2 Register")
 *    occurs (in MEM transactions) for address translation to proceed. Only Valid when the
 *    CX_TPH_ENABLE configuration parameter is 1 Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_MSG_CODE_MATCH_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_MSG_CODE_MATCH_EN_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_MSG_CODE_MATCH_EN_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_SINGLE_ADDR_LOC_TRANS_EN_MASK (0x800000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_SINGLE_ADDR_LOC_TRANS_EN_SHIFT (23U)
/*! SINGLE_ADDR_LOC_TRANS_EN - Single Address Location Translate Enable. When enabled, Rx TLPs can
 *    be translated to a single address location as determined by the target address register of the
 *    iATU region. The main usage scenario is translation of Messages (such as Vendor Defined or ATS
 *    Messages) to MWr TLPs when the AXI bridge is enabled. Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_SINGLE_ADDR_LOC_TRANS_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_SINGLE_ADDR_LOC_TRANS_EN_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_SINGLE_ADDR_LOC_TRANS_EN_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_RESPONSE_CODE_MASK (0x3000000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_RESPONSE_CODE_SHIFT (24U)
/*! RESPONSE_CODE - Response Code. Defines the type of response to give for accesses matching this
 *    region. This overrides the normal RADM filter response. Note that this feature is not available
 *    for any region where Single Address Location Translate is enabled. - 00 - Normal RADM filter
 *    response is used. - 01 - Unsupported request (UR) - 10 - Completer abort (CA) - 11 - Not used
 *    / undefined / reserved. Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_RESPONSE_CODE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_RESPONSE_CODE_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_RESPONSE_CODE_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_FUZZY_TYPE_MATCH_CODE_MASK (0x8000000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_FUZZY_TYPE_MATCH_CODE_SHIFT (27U)
/*! FUZZY_TYPE_MATCH_CODE - Fuzzy Type Match Mode. When enabled, the iATU relaxes the matching of
 *    the TLP TYPE field against the expected TYPE field so that - CfgRd0 and CfgRd1 TLPs are seen as
 *    identical. Similarly with CfgWr0 and CfgWr1. - MWr, MRd and MRdLk TLPs are seen as identical -
 *    The Routing field of Msg/MsgD TLPs is ignored - FetchAdd, Swap and CAS are seen as identical.
 *    For example, CFG0 in the TYPE field in the "iATU Control 1 Register" matches against an
 *    inbound CfgRd0, CfgRd1, CfgWr0 or CfgWr1 TLP. Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_FUZZY_TYPE_MATCH_CODE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_FUZZY_TYPE_MATCH_CODE_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_FUZZY_TYPE_MATCH_CODE_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_CFG_SHIFT_MODE_MASK (0x10000000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_CFG_SHIFT_MODE_SHIFT (28U)
/*! CFG_SHIFT_MODE - CFG Shift Mode. This is useful for CFG transactions where the PCIe
 *    configuration mechanism maps bits [27:12] of the address to the bus/device and function number. This
 *    allows a CFG configuration space to be located in any 256MB window of your application memory space
 *    using a 28-bit effective address. Shifts bits [31:16] of the untranslated address to form
 *    bits [27:12] of the translated address. Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_CFG_SHIFT_MODE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_CFG_SHIFT_MODE_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_CFG_SHIFT_MODE_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_INVERT_MODE_MASK (0x20000000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_INVERT_MODE_SHIFT (29U)
/*! INVERT_MODE - Invert Mode. When set the address matching region is inverted. Therefore, an
 *    address match occurs when the untranslated address is in the region outside the defined range (Base
 *    Address to Limit Address). Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_INVERT_MODE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_INVERT_MODE_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_INVERT_MODE_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_MATCH_MODE_MASK (0x40000000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_MATCH_MODE_SHIFT (30U)
/*! MATCH_MODE - Match Mode. Determines Inbound matching mode for TLPs. The mode depends on the type
 *    of TLP that is received as follows: For MEM-I/O TLPs, this field is interpreted as follows: -
 *    0: Address Match Mode. The iATU operates using addresses as in the outbound direction. The
 *    Region Base and Limit Registers must be setup. - 1:BAR Match Mode. BAR matching is used. The
 *    "BAR Number" field is relevant. Not used for RC. For CFG0 TLPs, this field is interpreted as
 *    follows: - 0: Routing ID Match Mode. The iATU interprets the Routing ID (Bytes 8 to 11 of TLP
 *    header) as an address. This corresponds to the upper 16 bits of the address in MEM-I/O
 *    transactions. The Routing ID of the TLP must be within the base and limit of the iATU region for matching
 *    to proceed. - 1: Accept Mode. The iATU accepts all CFG0 transactions as address matches. The
 *    routing ID in the CFG0 TLP is ignored. This is useful as all received CFG0 TLPs should be
 *    processed regardless of the Bus number. For MSG/MSGD TLPs, this field is interpreted as follows: -
 *    0: Address Match Mode. The iATU treats the third dword and fourth dword of the inbound
 *    MSG/MSGD TLP as an address and it is matched against the Region Base and Limit Registers. - 1:
 *    Vendor ID Match Mode. This mode is relevant for ID-routed Vendor Defined Messages. The iATU ignores
 *    the Routing ID (Bus, Device, Function) in bits [31:16] of the third dword of the TLP header,
 *    but matches against the Vendor ID in bits [15:0] of the third dword of the TLP header. Bits
 *    [15:0] of the Region Upper Base register should be programmed with the required Vendor ID. The
 *    lower Base and Limit Register should be programmed to translate TLPs based on vendor specific
 *    information in the fourth dword of the TLP header. - If SINGLE_ADDRESS_LOCATION_TRANSLATE_EN =
 *    1 AND MSG_TYPE_MATCH_MODE = 1, then Match Mode is ignored. Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_MATCH_MODE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_MATCH_MODE_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_MATCH_MODE_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_REGION_EN_MASK (0x80000000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_REGION_EN_SHIFT (31U)
/*! REGION_EN - Region Enable. This bit must be set to '1' for address translation to take place. Note: This register field is sticky. */
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_REGION_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_REGION_EN_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_0_REGION_EN_MASK)
/*! @} */

/*! @name IATU_LWR_BASE_ADDR_OFF_INBOUND_0 - iATU Lower Base Address Register. */
/*! @{ */

#define PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_0_LWR_BASE_HW_MASK (0xFFFFU)
#define PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_0_LWR_BASE_HW_SHIFT (0U)
/*! LWR_BASE_HW - Forms bits [n-1:0] of the start address of the address region to be translated.
 *    The start address must be aligned to a CX_ATU_MIN_REGION_SIZEMinimum Size of iATU Region kB
 *    boundary, so these bits are always 0. A write to this location is ignored by the PCIe controller.
 *    n is log2(CX_ATU_MIN_REGION_SIZEMinimum Size of iATU Region)
 */
#define PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_0_LWR_BASE_HW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_0_LWR_BASE_HW_SHIFT)) & PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_0_LWR_BASE_HW_MASK)

#define PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_0_LWR_BASE_RW_MASK (0xFFFF0000U)
#define PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_0_LWR_BASE_RW_SHIFT (16U)
/*! LWR_BASE_RW - Forms bits [31:n] of the start address of the address region to be translated. n
 *    is log2(CX_ATU_MIN_REGION_SIZEMinimum Size of iATU Region) Note: This register field is sticky.
 */
#define PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_0_LWR_BASE_RW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_0_LWR_BASE_RW_SHIFT)) & PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_0_LWR_BASE_RW_MASK)
/*! @} */

/*! @name IATU_UPPER_BASE_ADDR_OFF_INBOUND_0 - iATU Upper Base Address Register. */
/*! @{ */

#define PCIE_IATU_UPPER_BASE_ADDR_OFF_INBOUND_0_UPPER_BASE_RW_MASK (0xFFFFFFFFU)
#define PCIE_IATU_UPPER_BASE_ADDR_OFF_INBOUND_0_UPPER_BASE_RW_SHIFT (0U)
/*! UPPER_BASE_RW - Forms bits [63:32] of the start (and end) address of the address region to be
 *    translated. Note: This register field is sticky.
 */
#define PCIE_IATU_UPPER_BASE_ADDR_OFF_INBOUND_0_UPPER_BASE_RW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_UPPER_BASE_ADDR_OFF_INBOUND_0_UPPER_BASE_RW_SHIFT)) & PCIE_IATU_UPPER_BASE_ADDR_OFF_INBOUND_0_UPPER_BASE_RW_MASK)
/*! @} */

/*! @name IATU_LIMIT_ADDR_OFF_INBOUND_0 - iATU Limit Address Register. */
/*! @{ */

#define PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_0_LIMIT_ADDR_HW_MASK (0xFFFFU)
#define PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_0_LIMIT_ADDR_HW_SHIFT (0U)
/*! LIMIT_ADDR_HW - Forms lower bits of the end address of the address region to be translated. The
 *    end address must be aligned to a CX_ATU_MIN_REGION_SIZEMinimum Size of iATU Region kB
 *    boundary, so these bits are always 0. A write to this location is ignored by the PCIe controller.
 */
#define PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_0_LIMIT_ADDR_HW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_0_LIMIT_ADDR_HW_SHIFT)) & PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_0_LIMIT_ADDR_HW_MASK)

#define PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_0_LIMIT_ADDR_RW_MASK (0xFFFF0000U)
#define PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_0_LIMIT_ADDR_RW_SHIFT (16U)
/*! LIMIT_ADDR_RW - Forms upper bits of the end address of the address region to be translated. The
 *    end address must be aligned to a CX_ATU_MIN_REGION_SIZEMinimum Size of iATU Region kB
 *    boundary, so these bits are always 0. A write to this location is ignored by the PCIe controller.
 *    Note: This register field is sticky.
 */
#define PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_0_LIMIT_ADDR_RW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_0_LIMIT_ADDR_RW_SHIFT)) & PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_0_LIMIT_ADDR_RW_MASK)
/*! @} */

/*! @name IATU_LWR_TARGET_ADDR_OFF_INBOUND_0 - iATU Lower Target Address Register. */
/*! @{ */

#define PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_0_LWR_TARGET_HW_MASK (0xFFFFU)
#define PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_0_LWR_TARGET_HW_SHIFT (0U)
/*! LWR_TARGET_HW - Forms the LSB's of the Lower Target part of the new address of the translated
 *    region. The start address must be aligned to a CX_ATU_MIN_REGION_SIZEMinimum Size of iATU Region
 *    kB boundary (in address match mode); and to the Bar size boundary (in BAR match mode) so that
 *    these bits are always '0'. If the BAR is smaller than the iATU region size, then the iATU
 *    target address must align to the iATU region size; otherwise it must align to the BAR size. A
 *    write to this location is ignored by the PCIe controller. - Field size depends on
 *    log2(CX_ATU_MIN_REGION_SIZEMinimum Size of iATU Region) in address match mode. - Field size depends on
 *    log2(BAR_MASK+1) in BAR match mode.
 */
#define PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_0_LWR_TARGET_HW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_0_LWR_TARGET_HW_SHIFT)) & PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_0_LWR_TARGET_HW_MASK)

#define PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_0_LWR_TARGET_RW_MASK (0xFFFF0000U)
#define PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_0_LWR_TARGET_RW_SHIFT (16U)
/*! LWR_TARGET_RW - Forms MSB's of the Lower Target part of the new address of the translated
 *    region. These bits are always '0'. - Field size depends on log2(CX_ATU_MIN_REGION_SIZEMinimum Size
 *    of iATU Region) in address match mode. - Field size depends on log2(BAR_MASK+1) in BAR match
 *    mode. Note: This register field is sticky.
 */
#define PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_0_LWR_TARGET_RW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_0_LWR_TARGET_RW_SHIFT)) & PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_0_LWR_TARGET_RW_MASK)
/*! @} */

/*! @name IATU_REGION_CTRL_1_OFF_OUTBOUND_1 - iATU Region Control 1 Register. */
/*! @{ */

#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_1_TYPE_MASK (0x1FU)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_1_TYPE_SHIFT (0U)
/*! TYPE - When the address of an outbound TLP is matched to this region, then the TYPE field of the
 *    TLP is changed to the value in this register. Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_1_TYPE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_1_TYPE_SHIFT)) & PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_1_TYPE_MASK)

#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_1_TC_MASK (0xE0U)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_1_TC_SHIFT (5U)
/*! TC - When the address of an outbound TLP is matched to this region, then the TC field of the TLP
 *    is changed to the value in this register. Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_1_TC(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_1_TC_SHIFT)) & PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_1_TC_MASK)

#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_1_TD_MASK (0x100U)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_1_TD_SHIFT (8U)
/*! TD - When the address of an outbound TLP is matched to this region, then the TD field of the TLP
 *    is changed to the value in this register. Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_1_TD(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_1_TD_SHIFT)) & PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_1_TD_MASK)

#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_1_ATTR_MASK (0x600U)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_1_ATTR_SHIFT (9U)
/*! ATTR - When the address of an outbound TLP is matched to this region, then the ATTR field of the
 *    TLP is changed to the value in this register. Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_1_ATTR(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_1_ATTR_SHIFT)) & PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_1_ATTR_MASK)

#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_1_INCREASE_REGION_SIZE_MASK (0x2000U)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_1_INCREASE_REGION_SIZE_SHIFT (13U)
/*! INCREASE_REGION_SIZE - Increase the maximum ATU Region size. When set, the maximum ATU Region
 *    size is determined by CX_ATU_MAX_REGION_SIZEMaximum Size of iATU Region When clear, the maximum
 *    ATU Region size is 4 GB (default). Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_1_INCREASE_REGION_SIZE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_1_INCREASE_REGION_SIZE_SHIFT)) & PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_1_INCREASE_REGION_SIZE_MASK)

#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_1_CTRL_1_FUNC_NUM_MASK (0x700000U)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_1_CTRL_1_FUNC_NUM_SHIFT (20U)
/*! CTRL_1_FUNC_NUM - Function Number. - When the address of an outbound TLP is matched to this
 *    region and the FUNC_BYPASS field in the "iATU Control 2 Register" is '0', then the function number
 *    used in generating the function part of the requester ID (RID) field of the TLP is taken from
 *    this 5-bit register. The value in this register must be 0x0 unless multifunction operation in
 *    the controller is enabled (CX_NFUNC > 1). - When you are using the AXI Bridge, then this
 *    field is swapped before AXI decomposition occurs so that the correct "Max_Read_Request_Size" and
 *    "Max_Payload_Size" values are used. Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_1_CTRL_1_FUNC_NUM(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_1_CTRL_1_FUNC_NUM_SHIFT)) & PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_1_CTRL_1_FUNC_NUM_MASK)
/*! @} */

/*! @name IATU_REGION_CTRL_2_OFF_OUTBOUND_1 - iATU Region Control 2 Register. */
/*! @{ */

#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_1_MSG_CODE_MASK (0xFFU)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_1_MSG_CODE_SHIFT (0U)
/*! MSG_CODE - MSG TLPs (Message Code). When the address of an outbound TLP is matched to this
 *    region, and the translated TLP TYPE field is Msg or MsgD; then the message field of the TLP is
 *    changed to the value in this register. Memory TLPs: (ST;Steering Tag). When the ST field of an
 *    outbound TLP is matched to this region, and the translated TLP TYPE field targets memory space;
 *    then the ST field of the TLP is changed to the value in this register. Only Valid when the
 *    CX_TPH_ENABLE configuration parameter is 1. Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_1_MSG_CODE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_1_MSG_CODE_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_1_MSG_CODE_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_1_TAG_MASK (0xFF00U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_1_TAG_SHIFT (8U)
/*! TAG - TAG. The substituted TAG field (byte 6) in the outgoing TLP header when TAG_SUBSTITUTE_EN
 *    is set. Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_1_TAG(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_1_TAG_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_1_TAG_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_1_TAG_SUBSTITUTE_EN_MASK (0x10000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_1_TAG_SUBSTITUTE_EN_SHIFT (16U)
/*! TAG_SUBSTITUTE_EN - TAG Substitute Enable. When enabled and region address is matched, the iATU
 *    substitutes the TAG field of the outbound TLP header with the contents of the TAG field in
 *    this register. The expected usage scenario is translation from AXI MWr to Vendor Defined
 *    Msg/MsgD. Note (CX_TPH_ENABLE=1): TAG substitution for MWr will not occur because this field (byte 6)
 *    in the TLP header is the ST field. ST substitution can still take place using the MSG_CODE
 *    field in IATU_REGION_CTRL_2_OFF_OUTBOUND_i. Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_1_TAG_SUBSTITUTE_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_1_TAG_SUBSTITUTE_EN_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_1_TAG_SUBSTITUTE_EN_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_1_FUNC_BYPASS_MASK (0x80000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_1_FUNC_BYPASS_SHIFT (19U)
/*! FUNC_BYPASS - Function Number Translation Bypass. In this mode, the function number of the
 *    translated TLP is taken from your application transmit interface and not from the CTRL_1_FUNC_NUM
 *    field of the "iATU Control 1 Register" or the VF_NUMBER field of the "iATU Control 3 Register."
 *    Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_1_FUNC_BYPASS(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_1_FUNC_BYPASS_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_1_FUNC_BYPASS_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_1_SNP_MASK (0x100000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_1_SNP_SHIFT (20U)
/*! SNP - Serialize Non-Posted Requests. In this mode, when the AXI Bridge is populated, same AXI ID
 *    Non-Posted Read/Write Requests are transmitted on the wire if there are no other same ID
 *    Non-Posted Requests outstanding. Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_1_SNP(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_1_SNP_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_1_SNP_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_1_INHIBIT_PAYLOAD_MASK (0x400000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_1_INHIBIT_PAYLOAD_SHIFT (22U)
/*! INHIBIT_PAYLOAD - Inhibit TLP Payload Data for TLP's in Matched Region; assign iATU region to be
 *    TLP without data. When enabled and region address is matched, the iATU marks all TLPs as
 *    having no payload data by forcing the TLP header Fmt[1] bit =0, regardless of the application
 *    inputs such as slv_wstrb. - 1: Fmt[1] =0 so that only TLP type without data is sent. For example,
 *    a Msg instead of MsgD will be sent. - 0: Fmt[1] =0/1 so that TLPs with or without data can be
 *    sent. Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_1_INHIBIT_PAYLOAD(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_1_INHIBIT_PAYLOAD_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_1_INHIBIT_PAYLOAD_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_1_HEADER_SUBSTITUTE_EN_MASK (0x800000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_1_HEADER_SUBSTITUTE_EN_SHIFT (23U)
/*! HEADER_SUBSTITUTE_EN - Header Substitute Enable. When enabled and region address is matched, the
 *    iATU fully substitutes bytes 8-11 (for 3 DWORD header) or bytes 12-15 (for 4 DWORD header) of
 *    the outbound TLP header with the contents of the LWR_TARGET_RW field in
 *    IATU_LWR_TARGET_ADDR_OFF_OUTBOUND_i. - 1: LWR_TARGET_RW in the iATU_LWR_TARGET_ADDR_OFF_OUTBOUND_i register is used
 *    to fill bytes 8-to-11 (for 3 DWORD header) or bytes 12-to-15 (for 4 DWORD header) of the
 *    translated TLP header. - 0: LWR_TARGET_RW in the iATU_LWR_TARGET_ADDR_OFF_OUTBOUND_i register
 *    forms the new address of the translated region. Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_1_HEADER_SUBSTITUTE_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_1_HEADER_SUBSTITUTE_EN_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_1_HEADER_SUBSTITUTE_EN_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_1_DMA_BYPASS_MASK (0x8000000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_1_DMA_BYPASS_SHIFT (27U)
/*! DMA_BYPASS - DMA Bypass Mode. Allows request TLPs which are initiated by the DMA controller to
 *    pass through the iATU untranslated. Note: This field is reserved for the SW product. You must
 *    set it to '0'. Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_1_DMA_BYPASS(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_1_DMA_BYPASS_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_1_DMA_BYPASS_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_1_CFG_SHIFT_MODE_MASK (0x10000000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_1_CFG_SHIFT_MODE_SHIFT (28U)
/*! CFG_SHIFT_MODE - CFG Shift Mode. The iATU uses bits [27:12] of the untranslated address (on the
 *    XALI0/1/2 interface or AXI slave interface address) to form the BDF number of the outgoing CFG
 *    TLP. This supports the Enhanced Configuration Address Mapping (ECAM) mechanism (Section 7.2.2
 *    of the PCI Express Base 3.1 Specification, revision 1.0) by allowing all outgoing I/O and MEM
 *    TLPs (that have been translated to CFG) to be mapped from memory space into any 256 MB region
 *    of the PCIe configuration space. Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_1_CFG_SHIFT_MODE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_1_CFG_SHIFT_MODE_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_1_CFG_SHIFT_MODE_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_1_INVERT_MODE_MASK (0x20000000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_1_INVERT_MODE_SHIFT (29U)
/*! INVERT_MODE - Invert Mode. When set the address matching region is inverted. Therefore, an
 *    address match occurs when the untranslated address is in the region outside the defined range (Base
 *    Address to Limit Address). Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_1_INVERT_MODE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_1_INVERT_MODE_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_1_INVERT_MODE_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_1_REGION_EN_MASK (0x80000000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_1_REGION_EN_SHIFT (31U)
/*! REGION_EN - Region Enable. This bit must be set to '1' for address translation to take place. Note: This register field is sticky. */
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_1_REGION_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_1_REGION_EN_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_1_REGION_EN_MASK)
/*! @} */

/*! @name IATU_LWR_BASE_ADDR_OFF_OUTBOUND_1 - iATU Lower Base Address Register. */
/*! @{ */

#define PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_1_LWR_BASE_HW_MASK (0xFFFFU)
#define PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_1_LWR_BASE_HW_SHIFT (0U)
/*! LWR_BASE_HW - Forms bits [n-1:0] of the start address of the address region to be translated.
 *    The start address must be aligned to a CX_ATU_MIN_REGION_SIZEMinimum Size of iATU Region kB
 *    boundary, so these bits are always 0. A write to this location is ignored by the PCIe controller.
 *    n is log2(CX_ATU_MIN_REGION_SIZEMinimum Size of iATU Region)
 */
#define PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_1_LWR_BASE_HW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_1_LWR_BASE_HW_SHIFT)) & PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_1_LWR_BASE_HW_MASK)

#define PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_1_LWR_BASE_RW_MASK (0xFFFF0000U)
#define PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_1_LWR_BASE_RW_SHIFT (16U)
/*! LWR_BASE_RW - Forms bits [31:n] of the start address of the address region to be translated. n
 *    is log2(CX_ATU_MIN_REGION_SIZEMinimum Size of iATU Region) Note: This register field is sticky.
 */
#define PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_1_LWR_BASE_RW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_1_LWR_BASE_RW_SHIFT)) & PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_1_LWR_BASE_RW_MASK)
/*! @} */

/*! @name IATU_UPPER_BASE_ADDR_OFF_OUTBOUND_1 - iATU Upper Base Address Register. */
/*! @{ */

#define PCIE_IATU_UPPER_BASE_ADDR_OFF_OUTBOUND_1_UPPER_BASE_RW_MASK (0xFFFFFFFFU)
#define PCIE_IATU_UPPER_BASE_ADDR_OFF_OUTBOUND_1_UPPER_BASE_RW_SHIFT (0U)
/*! UPPER_BASE_RW - Forms bits [63:32] of the start (and end) address of the address region to be
 *    translated. In systems with a 32-bit address space, this register is not used and therefore
 *    writing to this register has no effect. Note: This register field is sticky.
 */
#define PCIE_IATU_UPPER_BASE_ADDR_OFF_OUTBOUND_1_UPPER_BASE_RW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_UPPER_BASE_ADDR_OFF_OUTBOUND_1_UPPER_BASE_RW_SHIFT)) & PCIE_IATU_UPPER_BASE_ADDR_OFF_OUTBOUND_1_UPPER_BASE_RW_MASK)
/*! @} */

/*! @name IATU_LIMIT_ADDR_OFF_OUTBOUND_1 - iATU Limit Address Register. */
/*! @{ */

#define PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_1_LIMIT_ADDR_HW_MASK (0xFFFFU)
#define PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_1_LIMIT_ADDR_HW_SHIFT (0U)
/*! LIMIT_ADDR_HW - Forms lower bits of the end address of the address region to be translated. The
 *    end address must be aligned to a CX_ATU_MIN_REGION_SIZEMinimum Size of iATU Region kB
 *    boundary, so these bits are always 0. A write to this location is ignored by the PCIe controller.
 */
#define PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_1_LIMIT_ADDR_HW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_1_LIMIT_ADDR_HW_SHIFT)) & PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_1_LIMIT_ADDR_HW_MASK)

#define PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_1_LIMIT_ADDR_RW_MASK (0xFFFF0000U)
#define PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_1_LIMIT_ADDR_RW_SHIFT (16U)
/*! LIMIT_ADDR_RW - Forms upper bits of the end address of the address region to be translated. The
 *    end address must be aligned to a CX_ATU_MIN_REGION_SIZEMinimum Size of iATU Region kB
 *    boundary, so these bits are always 0. A write to this location is ignored by the PCIe controller.
 *    Note: This register field is sticky.
 */
#define PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_1_LIMIT_ADDR_RW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_1_LIMIT_ADDR_RW_SHIFT)) & PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_1_LIMIT_ADDR_RW_MASK)
/*! @} */

/*! @name IATU_LWR_TARGET_ADDR_OFF_OUTBOUND_1 - iATU Lower Target Address Register. */
/*! @{ */

#define PCIE_IATU_LWR_TARGET_ADDR_OFF_OUTBOUND_1_LWR_TARGET_RW_OUTBOUND_MASK (0xFFFFFFFFU)
#define PCIE_IATU_LWR_TARGET_ADDR_OFF_OUTBOUND_1_LWR_TARGET_RW_OUTBOUND_SHIFT (0U)
/*! LWR_TARGET_RW_OUTBOUND - When HEADER_SUBSTITUTE_EN in IATU_REGION_CTRL_2_OFF_OUTBOUND_ is '0'
 *    (normal operation): - LWR_TARGET_RW[31:n] forms MSB's of the Lower Target part of the new
 *    address of the translated region; - LWR_TARGET_RW[n-1:0] are not used. (The start address must be
 *    aligned to a CX_ATU_MIN_REGION_SIZEMinimum Size of iATU Region kB boundary, so the lower bits of
 *    the start address of the new address of the translated region (bits n-1:0) are always '0'). -
 *    n is log2(CX_ATU_MIN_REGION_SIZEMinimum Size of iATU Region). When HEADER_SUBSTITUTE_EN in
 *    IATU_REGION_CTRL_2_OFF_OUTBOUND_i is '1': - LWR_TARGET_RW[31:0] forms bytes 8-11 (for 3 dword
 *    header) or bytes 12-15 (for 4 dword header) of the outbound TLP header. Usage scenarios include
 *    the transmission of Vendor Defined Messages where the controller determines the content of
 *    bytes 12 to 15 of the TLP header. Note: This register field is sticky.
 */
#define PCIE_IATU_LWR_TARGET_ADDR_OFF_OUTBOUND_1_LWR_TARGET_RW_OUTBOUND(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LWR_TARGET_ADDR_OFF_OUTBOUND_1_LWR_TARGET_RW_OUTBOUND_SHIFT)) & PCIE_IATU_LWR_TARGET_ADDR_OFF_OUTBOUND_1_LWR_TARGET_RW_OUTBOUND_MASK)
/*! @} */

/*! @name IATU_UPPER_TARGET_ADDR_OFF_OUTBOUND_1 - iATU Upper Target Address Register. */
/*! @{ */

#define PCIE_IATU_UPPER_TARGET_ADDR_OFF_OUTBOUND_1_UPPER_TARGET_RW_MASK (0xFFFFFFFFU)
#define PCIE_IATU_UPPER_TARGET_ADDR_OFF_OUTBOUND_1_UPPER_TARGET_RW_SHIFT (0U)
/*! UPPER_TARGET_RW - Forms bits [63:32] of the start address (Upper Target part) of the new address
 *    of the translated region. Note: This register field is sticky.
 */
#define PCIE_IATU_UPPER_TARGET_ADDR_OFF_OUTBOUND_1_UPPER_TARGET_RW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_UPPER_TARGET_ADDR_OFF_OUTBOUND_1_UPPER_TARGET_RW_SHIFT)) & PCIE_IATU_UPPER_TARGET_ADDR_OFF_OUTBOUND_1_UPPER_TARGET_RW_MASK)
/*! @} */

/*! @name IATU_REGION_CTRL_1_OFF_INBOUND_1 - iATU Region Control 1 Register. */
/*! @{ */

#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_1_TYPE_MASK (0x1FU)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_1_TYPE_SHIFT (0U)
/*! TYPE - When the TYPE field of an inbound TLP is matched to this value, then address translation
 *    proceeds (when all other enabled field-matches are successful). Note: This register field is
 *    sticky.
 */
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_1_TYPE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_1_TYPE_SHIFT)) & PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_1_TYPE_MASK)

#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_1_TC_MASK (0xE0U)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_1_TC_SHIFT (5U)
/*! TC - When the TC field of an inbound TLP is matched to this value, then address translation
 *    proceeds (when all other enabled field-matches are successful). This check is only performed if
 *    the "TC Match Enable" bit of the "iATU Control 2 Register" is set. Note: This register field is
 *    sticky.
 */
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_1_TC(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_1_TC_SHIFT)) & PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_1_TC_MASK)

#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_1_TD_MASK (0x100U)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_1_TD_SHIFT (8U)
/*! TD - When the TD field of an inbound TLP is matched to this value, then address translation
 *    proceeds (when all other enabled field-matches are successful). This check is only performed if
 *    the "TD Match Enable" bit of the "iATU Control 2 Register" is set. Note: This register field is
 *    sticky.
 */
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_1_TD(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_1_TD_SHIFT)) & PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_1_TD_MASK)

#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_1_ATTR_MASK (0x600U)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_1_ATTR_SHIFT (9U)
/*! ATTR - When the ATTR field of an inbound TLP is matched to this value, then address translation
 *    proceeds (when all other enabled field-matches are successful). This check is only performed
 *    if the "ATTR Match Enable" bit of the "iATU Control 2 Register" is set. Note: This register
 *    field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_1_ATTR(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_1_ATTR_SHIFT)) & PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_1_ATTR_MASK)

#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_1_INCREASE_REGION_SIZE_MASK (0x2000U)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_1_INCREASE_REGION_SIZE_SHIFT (13U)
/*! INCREASE_REGION_SIZE - Increase the maximum ATU Region size. When set, the maximum ATU Region
 *    size is determined by CX_ATU_MAX_REGION_SIZEMaximum Size of iATU Region When clear, the maximum
 *    ATU Region size is 4 GB (default). Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_1_INCREASE_REGION_SIZE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_1_INCREASE_REGION_SIZE_SHIFT)) & PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_1_INCREASE_REGION_SIZE_MASK)

#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_1_CTRL_1_FUNC_NUM_MASK (0x700000U)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_1_CTRL_1_FUNC_NUM_SHIFT (20U)
/*! CTRL_1_FUNC_NUM - Function Number. - MEM-I/O: When the Address and BAR matching logic in the
 *    controller indicate that a MEM-I/O transaction matches a BAR in the function corresponding to
 *    this value, then address translation proceeds. This check is only performed if the "Function
 *    Number Match Enable" bit of the "iATU Control 2 Register" is set. - CFG0/CFG1: When the
 *    destination function number as specified in the routing ID of the TLP header matches the function, then
 *    address translation proceeds. This check is only performed if the "Function Number Match
 *    Enable" bit of the "iATU Control 2 Register" is set. Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_1_CTRL_1_FUNC_NUM(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_1_CTRL_1_FUNC_NUM_SHIFT)) & PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_1_CTRL_1_FUNC_NUM_MASK)
/*! @} */

/*! @name IATU_REGION_CTRL_2_OFF_INBOUND_1 - iATU Region Control 2 Register. */
/*! @{ */

#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_MSG_CODE_MASK (0xFFU)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_MSG_CODE_SHIFT (0U)
/*! MSG_CODE - MSG TLPs: (Message Code). When the TYPE field of an inbound Msg/MsgD TLP is matched
 *    to this value, then address translation proceeds (when all other enabled field-matches are
 *    successful). This check is only performed if the "Message Code Match Enable" bit of the "iATU
 *    Control 2 Register" is set. Memory TLPs: (ST;Steering Tag). When the ST field of an inbound TLP is
 *    matched to this value, then address translation proceeds. This check is only performed if the
 *    "ST Match Enable" bit of the "iATU Control2 Register" is set. The setting is independent of
 *    the setting of the TH field. Only Valid when the CX_TPH_ENABLE configuration parameter is 1.
 *    Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_MSG_CODE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_MSG_CODE_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_MSG_CODE_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_BAR_NUM_MASK (0x700U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_BAR_NUM_SHIFT (8U)
/*! BAR_NUM - BAR Number. When the BAR number of an inbound MEM or IO TLP " that is matched by the
 *    normal internal BAR address matching mechanism " is the same as this field, address translation
 *    proceeds (when all other enabled field-matches are successful). This check is only performed
 *    if the "Match Mode" bit of the "iATU Control 2 Register" is set. - 000b - BAR0 - 001b - BAR1 -
 *    010b - BAR2 - 011b - BAR3 - 100b - BAR4 - 101b - BAR5 - 110b - ROM - 111b - reserved - IO
 *    translation would require either 00100b or 00101b in the inbound TLP TYPE; the BAR Number set in
 *    the range 000b - 101b and that BAR configured as an IO BAR. Note: This register field is
 *    sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_BAR_NUM(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_BAR_NUM_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_BAR_NUM_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_MSG_TYPE_MATCH_MODE_MASK (0x2000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_MSG_TYPE_MATCH_MODE_SHIFT (13U)
/*! MSG_TYPE_MATCH_MODE - Message Type Match Mode. When enabled, and if single address location
 *    translate enable is set, then inbound TLPs of type MSG/MSGd which match the type field of the
 *    iatu_region_ctrl_1_OFF_inbound register (=>TYPE[4:3]=2'b10) will be translated. Message type match
 *    mode overrides any value of MATCH_MODE field in this register. Usage scenarios for this are
 *    translation of VDM or ATS messages when AXI bridge is configured on client interface. Note:
 *    This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_MSG_TYPE_MATCH_MODE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_MSG_TYPE_MATCH_MODE_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_MSG_TYPE_MATCH_MODE_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_TC_MATCH_EN_MASK (0x4000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_TC_MATCH_EN_SHIFT (14U)
/*! TC_MATCH_EN - TC Match Enable. Ensures that a successful TC TLP field comparison match (see TC
 *    field of the "iATU Control 1 Register") occurs for address translation to proceed. Note: This
 *    register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_TC_MATCH_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_TC_MATCH_EN_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_TC_MATCH_EN_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_TD_MATCH_EN_MASK (0x8000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_TD_MATCH_EN_SHIFT (15U)
/*! TD_MATCH_EN - TD Match Enable. Ensures that a successful TD TLP field comparison match (see TD
 *    field of the "iATU Control 1 Register") occurs for address translation to proceed. Note: This
 *    register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_TD_MATCH_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_TD_MATCH_EN_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_TD_MATCH_EN_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_ATTR_MATCH_EN_MASK (0x10000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_ATTR_MATCH_EN_SHIFT (16U)
/*! ATTR_MATCH_EN - ATTR Match Enable. Ensures that a successful ATTR TLP field comparison match
 *    (see ATTR field of the "iATU Control 1 Register") occurs for address translation to proceed.
 *    Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_ATTR_MATCH_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_ATTR_MATCH_EN_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_ATTR_MATCH_EN_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_FUNC_NUM_MATCH_EN_MASK (0x80000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_FUNC_NUM_MATCH_EN_SHIFT (19U)
/*! FUNC_NUM_MATCH_EN - Function Number Match Enable. Ensures that a successful Function Number TLP
 *    field comparison match (see Function Number field of the "iATU Control 1 Register") occurs (in
 *    MEM-I/O and CFG0/CFG1 transactions) for address translation to proceed. Note: This register
 *    field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_FUNC_NUM_MATCH_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_FUNC_NUM_MATCH_EN_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_FUNC_NUM_MATCH_EN_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_MSG_CODE_MATCH_EN_MASK (0x200000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_MSG_CODE_MATCH_EN_SHIFT (21U)
/*! MSG_CODE_MATCH_EN - Message Code Match Enable (Msg TLPS). Ensures that a successful message Code
 *    TLP field comparison match (see Message Code field of the "iATU Control 2 Register") occurs
 *    (in MSG transactions) for address translation to proceed. ST Match Enable (Mem TLPs). Ensures
 *    that a successful ST TLP field comparison match (see ST field of the "iATU Control 2 Register")
 *    occurs (in MEM transactions) for address translation to proceed. Only Valid when the
 *    CX_TPH_ENABLE configuration parameter is 1 Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_MSG_CODE_MATCH_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_MSG_CODE_MATCH_EN_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_MSG_CODE_MATCH_EN_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_SINGLE_ADDR_LOC_TRANS_EN_MASK (0x800000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_SINGLE_ADDR_LOC_TRANS_EN_SHIFT (23U)
/*! SINGLE_ADDR_LOC_TRANS_EN - Single Address Location Translate Enable. When enabled, Rx TLPs can
 *    be translated to a single address location as determined by the target address register of the
 *    iATU region. The main usage scenario is translation of Messages (such as Vendor Defined or ATS
 *    Messages) to MWr TLPs when the AXI bridge is enabled. Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_SINGLE_ADDR_LOC_TRANS_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_SINGLE_ADDR_LOC_TRANS_EN_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_SINGLE_ADDR_LOC_TRANS_EN_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_RESPONSE_CODE_MASK (0x3000000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_RESPONSE_CODE_SHIFT (24U)
/*! RESPONSE_CODE - Response Code. Defines the type of response to give for accesses matching this
 *    region. This overrides the normal RADM filter response. Note that this feature is not available
 *    for any region where Single Address Location Translate is enabled. - 00 - Normal RADM filter
 *    response is used. - 01 - Unsupported request (UR) - 10 - Completer abort (CA) - 11 - Not used
 *    / undefined / reserved. Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_RESPONSE_CODE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_RESPONSE_CODE_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_RESPONSE_CODE_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_FUZZY_TYPE_MATCH_CODE_MASK (0x8000000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_FUZZY_TYPE_MATCH_CODE_SHIFT (27U)
/*! FUZZY_TYPE_MATCH_CODE - Fuzzy Type Match Mode. When enabled, the iATU relaxes the matching of
 *    the TLP TYPE field against the expected TYPE field so that - CfgRd0 and CfgRd1 TLPs are seen as
 *    identical. Similarly with CfgWr0 and CfgWr1. - MWr, MRd and MRdLk TLPs are seen as identical -
 *    The Routing field of Msg/MsgD TLPs is ignored - FetchAdd, Swap and CAS are seen as identical.
 *    For example, CFG0 in the TYPE field in the "iATU Control 1 Register" matches against an
 *    inbound CfgRd0, CfgRd1, CfgWr0 or CfgWr1 TLP. Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_FUZZY_TYPE_MATCH_CODE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_FUZZY_TYPE_MATCH_CODE_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_FUZZY_TYPE_MATCH_CODE_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_CFG_SHIFT_MODE_MASK (0x10000000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_CFG_SHIFT_MODE_SHIFT (28U)
/*! CFG_SHIFT_MODE - CFG Shift Mode. This is useful for CFG transactions where the PCIe
 *    configuration mechanism maps bits [27:12] of the address to the bus/device and function number. This
 *    allows a CFG configuration space to be located in any 256MB window of your application memory space
 *    using a 28-bit effective address. Shifts bits [31:16] of the untranslated address to form
 *    bits [27:12] of the translated address. Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_CFG_SHIFT_MODE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_CFG_SHIFT_MODE_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_CFG_SHIFT_MODE_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_INVERT_MODE_MASK (0x20000000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_INVERT_MODE_SHIFT (29U)
/*! INVERT_MODE - Invert Mode. When set the address matching region is inverted. Therefore, an
 *    address match occurs when the untranslated address is in the region outside the defined range (Base
 *    Address to Limit Address). Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_INVERT_MODE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_INVERT_MODE_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_INVERT_MODE_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_MATCH_MODE_MASK (0x40000000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_MATCH_MODE_SHIFT (30U)
/*! MATCH_MODE - Match Mode. Determines Inbound matching mode for TLPs. The mode depends on the type
 *    of TLP that is received as follows: For MEM-I/O TLPs, this field is interpreted as follows: -
 *    0: Address Match Mode. The iATU operates using addresses as in the outbound direction. The
 *    Region Base and Limit Registers must be setup. - 1:BAR Match Mode. BAR matching is used. The
 *    "BAR Number" field is relevant. Not used for RC. For CFG0 TLPs, this field is interpreted as
 *    follows: - 0: Routing ID Match Mode. The iATU interprets the Routing ID (Bytes 8 to 11 of TLP
 *    header) as an address. This corresponds to the upper 16 bits of the address in MEM-I/O
 *    transactions. The Routing ID of the TLP must be within the base and limit of the iATU region for matching
 *    to proceed. - 1: Accept Mode. The iATU accepts all CFG0 transactions as address matches. The
 *    routing ID in the CFG0 TLP is ignored. This is useful as all received CFG0 TLPs should be
 *    processed regardless of the Bus number. For MSG/MSGD TLPs, this field is interpreted as follows: -
 *    0: Address Match Mode. The iATU treats the third dword and fourth dword of the inbound
 *    MSG/MSGD TLP as an address and it is matched against the Region Base and Limit Registers. - 1:
 *    Vendor ID Match Mode. This mode is relevant for ID-routed Vendor Defined Messages. The iATU ignores
 *    the Routing ID (Bus, Device, Function) in bits [31:16] of the third dword of the TLP header,
 *    but matches against the Vendor ID in bits [15:0] of the third dword of the TLP header. Bits
 *    [15:0] of the Region Upper Base register should be programmed with the required Vendor ID. The
 *    lower Base and Limit Register should be programmed to translate TLPs based on vendor specific
 *    information in the fourth dword of the TLP header. - If SINGLE_ADDRESS_LOCATION_TRANSLATE_EN =
 *    1 AND MSG_TYPE_MATCH_MODE = 1, then Match Mode is ignored. Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_MATCH_MODE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_MATCH_MODE_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_MATCH_MODE_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_REGION_EN_MASK (0x80000000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_REGION_EN_SHIFT (31U)
/*! REGION_EN - Region Enable. This bit must be set to '1' for address translation to take place. Note: This register field is sticky. */
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_REGION_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_REGION_EN_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_1_REGION_EN_MASK)
/*! @} */

/*! @name IATU_LWR_BASE_ADDR_OFF_INBOUND_1 - iATU Lower Base Address Register. */
/*! @{ */

#define PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_1_LWR_BASE_HW_MASK (0xFFFFU)
#define PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_1_LWR_BASE_HW_SHIFT (0U)
/*! LWR_BASE_HW - Forms bits [n-1:0] of the start address of the address region to be translated.
 *    The start address must be aligned to a CX_ATU_MIN_REGION_SIZEMinimum Size of iATU Region kB
 *    boundary, so these bits are always 0. A write to this location is ignored by the PCIe controller.
 *    n is log2(CX_ATU_MIN_REGION_SIZEMinimum Size of iATU Region)
 */
#define PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_1_LWR_BASE_HW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_1_LWR_BASE_HW_SHIFT)) & PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_1_LWR_BASE_HW_MASK)

#define PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_1_LWR_BASE_RW_MASK (0xFFFF0000U)
#define PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_1_LWR_BASE_RW_SHIFT (16U)
/*! LWR_BASE_RW - Forms bits [31:n] of the start address of the address region to be translated. n
 *    is log2(CX_ATU_MIN_REGION_SIZEMinimum Size of iATU Region) Note: This register field is sticky.
 */
#define PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_1_LWR_BASE_RW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_1_LWR_BASE_RW_SHIFT)) & PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_1_LWR_BASE_RW_MASK)
/*! @} */

/*! @name IATU_UPPER_BASE_ADDR_OFF_INBOUND_1 - iATU Upper Base Address Register. */
/*! @{ */

#define PCIE_IATU_UPPER_BASE_ADDR_OFF_INBOUND_1_UPPER_BASE_RW_MASK (0xFFFFFFFFU)
#define PCIE_IATU_UPPER_BASE_ADDR_OFF_INBOUND_1_UPPER_BASE_RW_SHIFT (0U)
/*! UPPER_BASE_RW - Forms bits [63:32] of the start (and end) address of the address region to be
 *    translated. Note: This register field is sticky.
 */
#define PCIE_IATU_UPPER_BASE_ADDR_OFF_INBOUND_1_UPPER_BASE_RW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_UPPER_BASE_ADDR_OFF_INBOUND_1_UPPER_BASE_RW_SHIFT)) & PCIE_IATU_UPPER_BASE_ADDR_OFF_INBOUND_1_UPPER_BASE_RW_MASK)
/*! @} */

/*! @name IATU_LIMIT_ADDR_OFF_INBOUND_1 - iATU Limit Address Register. */
/*! @{ */

#define PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_1_LIMIT_ADDR_HW_MASK (0xFFFFU)
#define PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_1_LIMIT_ADDR_HW_SHIFT (0U)
/*! LIMIT_ADDR_HW - Forms lower bits of the end address of the address region to be translated. The
 *    end address must be aligned to a CX_ATU_MIN_REGION_SIZEMinimum Size of iATU Region kB
 *    boundary, so these bits are always 0. A write to this location is ignored by the PCIe controller.
 */
#define PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_1_LIMIT_ADDR_HW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_1_LIMIT_ADDR_HW_SHIFT)) & PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_1_LIMIT_ADDR_HW_MASK)

#define PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_1_LIMIT_ADDR_RW_MASK (0xFFFF0000U)
#define PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_1_LIMIT_ADDR_RW_SHIFT (16U)
/*! LIMIT_ADDR_RW - Forms upper bits of the end address of the address region to be translated. The
 *    end address must be aligned to a CX_ATU_MIN_REGION_SIZEMinimum Size of iATU Region kB
 *    boundary, so these bits are always 0. A write to this location is ignored by the PCIe controller.
 *    Note: This register field is sticky.
 */
#define PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_1_LIMIT_ADDR_RW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_1_LIMIT_ADDR_RW_SHIFT)) & PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_1_LIMIT_ADDR_RW_MASK)
/*! @} */

/*! @name IATU_LWR_TARGET_ADDR_OFF_INBOUND_1 - iATU Lower Target Address Register. */
/*! @{ */

#define PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_1_LWR_TARGET_HW_MASK (0xFFFFU)
#define PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_1_LWR_TARGET_HW_SHIFT (0U)
/*! LWR_TARGET_HW - Forms the LSB's of the Lower Target part of the new address of the translated
 *    region. The start address must be aligned to a CX_ATU_MIN_REGION_SIZEMinimum Size of iATU Region
 *    kB boundary (in address match mode); and to the Bar size boundary (in BAR match mode) so that
 *    these bits are always '0'. If the BAR is smaller than the iATU region size, then the iATU
 *    target address must align to the iATU region size; otherwise it must align to the BAR size. A
 *    write to this location is ignored by the PCIe controller. - Field size depends on
 *    log2(CX_ATU_MIN_REGION_SIZEMinimum Size of iATU Region) in address match mode. - Field size depends on
 *    log2(BAR_MASK+1) in BAR match mode.
 */
#define PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_1_LWR_TARGET_HW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_1_LWR_TARGET_HW_SHIFT)) & PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_1_LWR_TARGET_HW_MASK)

#define PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_1_LWR_TARGET_RW_MASK (0xFFFF0000U)
#define PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_1_LWR_TARGET_RW_SHIFT (16U)
/*! LWR_TARGET_RW - Forms MSB's of the Lower Target part of the new address of the translated
 *    region. These bits are always '0'. - Field size depends on log2(CX_ATU_MIN_REGION_SIZEMinimum Size
 *    of iATU Region) in address match mode. - Field size depends on log2(BAR_MASK+1) in BAR match
 *    mode. Note: This register field is sticky.
 */
#define PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_1_LWR_TARGET_RW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_1_LWR_TARGET_RW_SHIFT)) & PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_1_LWR_TARGET_RW_MASK)
/*! @} */

/*! @name IATU_REGION_CTRL_1_OFF_OUTBOUND_2 - iATU Region Control 1 Register. */
/*! @{ */

#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_2_TYPE_MASK (0x1FU)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_2_TYPE_SHIFT (0U)
/*! TYPE - When the address of an outbound TLP is matched to this region, then the TYPE field of the
 *    TLP is changed to the value in this register. Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_2_TYPE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_2_TYPE_SHIFT)) & PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_2_TYPE_MASK)

#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_2_TC_MASK (0xE0U)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_2_TC_SHIFT (5U)
/*! TC - When the address of an outbound TLP is matched to this region, then the TC field of the TLP
 *    is changed to the value in this register. Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_2_TC(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_2_TC_SHIFT)) & PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_2_TC_MASK)

#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_2_TD_MASK (0x100U)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_2_TD_SHIFT (8U)
/*! TD - When the address of an outbound TLP is matched to this region, then the TD field of the TLP
 *    is changed to the value in this register. Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_2_TD(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_2_TD_SHIFT)) & PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_2_TD_MASK)

#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_2_ATTR_MASK (0x600U)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_2_ATTR_SHIFT (9U)
/*! ATTR - When the address of an outbound TLP is matched to this region, then the ATTR field of the
 *    TLP is changed to the value in this register. Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_2_ATTR(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_2_ATTR_SHIFT)) & PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_2_ATTR_MASK)

#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_2_INCREASE_REGION_SIZE_MASK (0x2000U)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_2_INCREASE_REGION_SIZE_SHIFT (13U)
/*! INCREASE_REGION_SIZE - Increase the maximum ATU Region size. When set, the maximum ATU Region
 *    size is determined by CX_ATU_MAX_REGION_SIZEMaximum Size of iATU Region When clear, the maximum
 *    ATU Region size is 4 GB (default). Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_2_INCREASE_REGION_SIZE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_2_INCREASE_REGION_SIZE_SHIFT)) & PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_2_INCREASE_REGION_SIZE_MASK)

#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_2_CTRL_1_FUNC_NUM_MASK (0x700000U)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_2_CTRL_1_FUNC_NUM_SHIFT (20U)
/*! CTRL_1_FUNC_NUM - Function Number. - When the address of an outbound TLP is matched to this
 *    region and the FUNC_BYPASS field in the "iATU Control 2 Register" is '0', then the function number
 *    used in generating the function part of the requester ID (RID) field of the TLP is taken from
 *    this 5-bit register. The value in this register must be 0x0 unless multifunction operation in
 *    the controller is enabled (CX_NFUNC > 1). - When you are using the AXI Bridge, then this
 *    field is swapped before AXI decomposition occurs so that the correct "Max_Read_Request_Size" and
 *    "Max_Payload_Size" values are used. Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_2_CTRL_1_FUNC_NUM(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_2_CTRL_1_FUNC_NUM_SHIFT)) & PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_2_CTRL_1_FUNC_NUM_MASK)
/*! @} */

/*! @name IATU_REGION_CTRL_2_OFF_OUTBOUND_2 - iATU Region Control 2 Register. */
/*! @{ */

#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_2_MSG_CODE_MASK (0xFFU)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_2_MSG_CODE_SHIFT (0U)
/*! MSG_CODE - MSG TLPs (Message Code). When the address of an outbound TLP is matched to this
 *    region, and the translated TLP TYPE field is Msg or MsgD; then the message field of the TLP is
 *    changed to the value in this register. Memory TLPs: (ST;Steering Tag). When the ST field of an
 *    outbound TLP is matched to this region, and the translated TLP TYPE field targets memory space;
 *    then the ST field of the TLP is changed to the value in this register. Only Valid when the
 *    CX_TPH_ENABLE configuration parameter is 1. Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_2_MSG_CODE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_2_MSG_CODE_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_2_MSG_CODE_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_2_TAG_MASK (0xFF00U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_2_TAG_SHIFT (8U)
/*! TAG - TAG. The substituted TAG field (byte 6) in the outgoing TLP header when TAG_SUBSTITUTE_EN
 *    is set. Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_2_TAG(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_2_TAG_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_2_TAG_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_2_TAG_SUBSTITUTE_EN_MASK (0x10000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_2_TAG_SUBSTITUTE_EN_SHIFT (16U)
/*! TAG_SUBSTITUTE_EN - TAG Substitute Enable. When enabled and region address is matched, the iATU
 *    substitutes the TAG field of the outbound TLP header with the contents of the TAG field in
 *    this register. The expected usage scenario is translation from AXI MWr to Vendor Defined
 *    Msg/MsgD. Note (CX_TPH_ENABLE=1): TAG substitution for MWr will not occur because this field (byte 6)
 *    in the TLP header is the ST field. ST substitution can still take place using the MSG_CODE
 *    field in IATU_REGION_CTRL_2_OFF_OUTBOUND_i. Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_2_TAG_SUBSTITUTE_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_2_TAG_SUBSTITUTE_EN_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_2_TAG_SUBSTITUTE_EN_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_2_FUNC_BYPASS_MASK (0x80000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_2_FUNC_BYPASS_SHIFT (19U)
/*! FUNC_BYPASS - Function Number Translation Bypass. In this mode, the function number of the
 *    translated TLP is taken from your application transmit interface and not from the CTRL_1_FUNC_NUM
 *    field of the "iATU Control 1 Register" or the VF_NUMBER field of the "iATU Control 3 Register."
 *    Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_2_FUNC_BYPASS(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_2_FUNC_BYPASS_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_2_FUNC_BYPASS_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_2_SNP_MASK (0x100000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_2_SNP_SHIFT (20U)
/*! SNP - Serialize Non-Posted Requests. In this mode, when the AXI Bridge is populated, same AXI ID
 *    Non-Posted Read/Write Requests are transmitted on the wire if there are no other same ID
 *    Non-Posted Requests outstanding. Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_2_SNP(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_2_SNP_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_2_SNP_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_2_INHIBIT_PAYLOAD_MASK (0x400000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_2_INHIBIT_PAYLOAD_SHIFT (22U)
/*! INHIBIT_PAYLOAD - Inhibit TLP Payload Data for TLP's in Matched Region; assign iATU region to be
 *    TLP without data. When enabled and region address is matched, the iATU marks all TLPs as
 *    having no payload data by forcing the TLP header Fmt[1] bit =0, regardless of the application
 *    inputs such as slv_wstrb. - 1: Fmt[1] =0 so that only TLP type without data is sent. For example,
 *    a Msg instead of MsgD will be sent. - 0: Fmt[1] =0/1 so that TLPs with or without data can be
 *    sent. Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_2_INHIBIT_PAYLOAD(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_2_INHIBIT_PAYLOAD_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_2_INHIBIT_PAYLOAD_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_2_HEADER_SUBSTITUTE_EN_MASK (0x800000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_2_HEADER_SUBSTITUTE_EN_SHIFT (23U)
/*! HEADER_SUBSTITUTE_EN - Header Substitute Enable. When enabled and region address is matched, the
 *    iATU fully substitutes bytes 8-11 (for 3 DWORD header) or bytes 12-15 (for 4 DWORD header) of
 *    the outbound TLP header with the contents of the LWR_TARGET_RW field in
 *    IATU_LWR_TARGET_ADDR_OFF_OUTBOUND_i. - 1: LWR_TARGET_RW in the iATU_LWR_TARGET_ADDR_OFF_OUTBOUND_i register is used
 *    to fill bytes 8-to-11 (for 3 DWORD header) or bytes 12-to-15 (for 4 DWORD header) of the
 *    translated TLP header. - 0: LWR_TARGET_RW in the iATU_LWR_TARGET_ADDR_OFF_OUTBOUND_i register
 *    forms the new address of the translated region. Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_2_HEADER_SUBSTITUTE_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_2_HEADER_SUBSTITUTE_EN_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_2_HEADER_SUBSTITUTE_EN_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_2_DMA_BYPASS_MASK (0x8000000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_2_DMA_BYPASS_SHIFT (27U)
/*! DMA_BYPASS - DMA Bypass Mode. Allows request TLPs which are initiated by the DMA controller to
 *    pass through the iATU untranslated. Note: This field is reserved for the SW product. You must
 *    set it to '0'. Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_2_DMA_BYPASS(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_2_DMA_BYPASS_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_2_DMA_BYPASS_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_2_CFG_SHIFT_MODE_MASK (0x10000000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_2_CFG_SHIFT_MODE_SHIFT (28U)
/*! CFG_SHIFT_MODE - CFG Shift Mode. The iATU uses bits [27:12] of the untranslated address (on the
 *    XALI0/1/2 interface or AXI slave interface address) to form the BDF number of the outgoing CFG
 *    TLP. This supports the Enhanced Configuration Address Mapping (ECAM) mechanism (Section 7.2.2
 *    of the PCI Express Base 3.1 Specification, revision 1.0) by allowing all outgoing I/O and MEM
 *    TLPs (that have been translated to CFG) to be mapped from memory space into any 256 MB region
 *    of the PCIe configuration space. Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_2_CFG_SHIFT_MODE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_2_CFG_SHIFT_MODE_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_2_CFG_SHIFT_MODE_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_2_INVERT_MODE_MASK (0x20000000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_2_INVERT_MODE_SHIFT (29U)
/*! INVERT_MODE - Invert Mode. When set the address matching region is inverted. Therefore, an
 *    address match occurs when the untranslated address is in the region outside the defined range (Base
 *    Address to Limit Address). Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_2_INVERT_MODE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_2_INVERT_MODE_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_2_INVERT_MODE_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_2_REGION_EN_MASK (0x80000000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_2_REGION_EN_SHIFT (31U)
/*! REGION_EN - Region Enable. This bit must be set to '1' for address translation to take place. Note: This register field is sticky. */
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_2_REGION_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_2_REGION_EN_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_2_REGION_EN_MASK)
/*! @} */

/*! @name IATU_LWR_BASE_ADDR_OFF_OUTBOUND_2 - iATU Lower Base Address Register. */
/*! @{ */

#define PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_2_LWR_BASE_HW_MASK (0xFFFFU)
#define PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_2_LWR_BASE_HW_SHIFT (0U)
/*! LWR_BASE_HW - Forms bits [n-1:0] of the start address of the address region to be translated.
 *    The start address must be aligned to a CX_ATU_MIN_REGION_SIZEMinimum Size of iATU Region kB
 *    boundary, so these bits are always 0. A write to this location is ignored by the PCIe controller.
 *    n is log2(CX_ATU_MIN_REGION_SIZEMinimum Size of iATU Region)
 */
#define PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_2_LWR_BASE_HW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_2_LWR_BASE_HW_SHIFT)) & PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_2_LWR_BASE_HW_MASK)

#define PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_2_LWR_BASE_RW_MASK (0xFFFF0000U)
#define PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_2_LWR_BASE_RW_SHIFT (16U)
/*! LWR_BASE_RW - Forms bits [31:n] of the start address of the address region to be translated. n
 *    is log2(CX_ATU_MIN_REGION_SIZEMinimum Size of iATU Region) Note: This register field is sticky.
 */
#define PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_2_LWR_BASE_RW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_2_LWR_BASE_RW_SHIFT)) & PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_2_LWR_BASE_RW_MASK)
/*! @} */

/*! @name IATU_UPPER_BASE_ADDR_OFF_OUTBOUND_2 - iATU Upper Base Address Register. */
/*! @{ */

#define PCIE_IATU_UPPER_BASE_ADDR_OFF_OUTBOUND_2_UPPER_BASE_RW_MASK (0xFFFFFFFFU)
#define PCIE_IATU_UPPER_BASE_ADDR_OFF_OUTBOUND_2_UPPER_BASE_RW_SHIFT (0U)
/*! UPPER_BASE_RW - Forms bits [63:32] of the start (and end) address of the address region to be
 *    translated. In systems with a 32-bit address space, this register is not used and therefore
 *    writing to this register has no effect. Note: This register field is sticky.
 */
#define PCIE_IATU_UPPER_BASE_ADDR_OFF_OUTBOUND_2_UPPER_BASE_RW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_UPPER_BASE_ADDR_OFF_OUTBOUND_2_UPPER_BASE_RW_SHIFT)) & PCIE_IATU_UPPER_BASE_ADDR_OFF_OUTBOUND_2_UPPER_BASE_RW_MASK)
/*! @} */

/*! @name IATU_LIMIT_ADDR_OFF_OUTBOUND_2 - iATU Limit Address Register. */
/*! @{ */

#define PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_2_LIMIT_ADDR_HW_MASK (0xFFFFU)
#define PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_2_LIMIT_ADDR_HW_SHIFT (0U)
/*! LIMIT_ADDR_HW - Forms lower bits of the end address of the address region to be translated. The
 *    end address must be aligned to a CX_ATU_MIN_REGION_SIZEMinimum Size of iATU Region kB
 *    boundary, so these bits are always 0. A write to this location is ignored by the PCIe controller.
 */
#define PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_2_LIMIT_ADDR_HW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_2_LIMIT_ADDR_HW_SHIFT)) & PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_2_LIMIT_ADDR_HW_MASK)

#define PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_2_LIMIT_ADDR_RW_MASK (0xFFFF0000U)
#define PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_2_LIMIT_ADDR_RW_SHIFT (16U)
/*! LIMIT_ADDR_RW - Forms upper bits of the end address of the address region to be translated. The
 *    end address must be aligned to a CX_ATU_MIN_REGION_SIZEMinimum Size of iATU Region kB
 *    boundary, so these bits are always 0. A write to this location is ignored by the PCIe controller.
 *    Note: This register field is sticky.
 */
#define PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_2_LIMIT_ADDR_RW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_2_LIMIT_ADDR_RW_SHIFT)) & PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_2_LIMIT_ADDR_RW_MASK)
/*! @} */

/*! @name IATU_LWR_TARGET_ADDR_OFF_OUTBOUND_2 - iATU Lower Target Address Register. */
/*! @{ */

#define PCIE_IATU_LWR_TARGET_ADDR_OFF_OUTBOUND_2_LWR_TARGET_RW_OUTBOUND_MASK (0xFFFFFFFFU)
#define PCIE_IATU_LWR_TARGET_ADDR_OFF_OUTBOUND_2_LWR_TARGET_RW_OUTBOUND_SHIFT (0U)
/*! LWR_TARGET_RW_OUTBOUND - When HEADER_SUBSTITUTE_EN in IATU_REGION_CTRL_2_OFF_OUTBOUND_ is '0'
 *    (normal operation): - LWR_TARGET_RW[31:n] forms MSB's of the Lower Target part of the new
 *    address of the translated region; - LWR_TARGET_RW[n-1:0] are not used. (The start address must be
 *    aligned to a CX_ATU_MIN_REGION_SIZEMinimum Size of iATU Region kB boundary, so the lower bits of
 *    the start address of the new address of the translated region (bits n-1:0) are always '0'). -
 *    n is log2(CX_ATU_MIN_REGION_SIZEMinimum Size of iATU Region). When HEADER_SUBSTITUTE_EN in
 *    IATU_REGION_CTRL_2_OFF_OUTBOUND_i is '1': - LWR_TARGET_RW[31:0] forms bytes 8-11 (for 3 dword
 *    header) or bytes 12-15 (for 4 dword header) of the outbound TLP header. Usage scenarios include
 *    the transmission of Vendor Defined Messages where the controller determines the content of
 *    bytes 12 to 15 of the TLP header. Note: This register field is sticky.
 */
#define PCIE_IATU_LWR_TARGET_ADDR_OFF_OUTBOUND_2_LWR_TARGET_RW_OUTBOUND(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LWR_TARGET_ADDR_OFF_OUTBOUND_2_LWR_TARGET_RW_OUTBOUND_SHIFT)) & PCIE_IATU_LWR_TARGET_ADDR_OFF_OUTBOUND_2_LWR_TARGET_RW_OUTBOUND_MASK)
/*! @} */

/*! @name IATU_UPPER_TARGET_ADDR_OFF_OUTBOUND_2 - iATU Upper Target Address Register. */
/*! @{ */

#define PCIE_IATU_UPPER_TARGET_ADDR_OFF_OUTBOUND_2_UPPER_TARGET_RW_MASK (0xFFFFFFFFU)
#define PCIE_IATU_UPPER_TARGET_ADDR_OFF_OUTBOUND_2_UPPER_TARGET_RW_SHIFT (0U)
/*! UPPER_TARGET_RW - Forms bits [63:32] of the start address (Upper Target part) of the new address
 *    of the translated region. Note: This register field is sticky.
 */
#define PCIE_IATU_UPPER_TARGET_ADDR_OFF_OUTBOUND_2_UPPER_TARGET_RW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_UPPER_TARGET_ADDR_OFF_OUTBOUND_2_UPPER_TARGET_RW_SHIFT)) & PCIE_IATU_UPPER_TARGET_ADDR_OFF_OUTBOUND_2_UPPER_TARGET_RW_MASK)
/*! @} */

/*! @name IATU_REGION_CTRL_1_OFF_INBOUND_2 - iATU Region Control 1 Register. */
/*! @{ */

#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_2_TYPE_MASK (0x1FU)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_2_TYPE_SHIFT (0U)
/*! TYPE - When the TYPE field of an inbound TLP is matched to this value, then address translation
 *    proceeds (when all other enabled field-matches are successful). Note: This register field is
 *    sticky.
 */
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_2_TYPE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_2_TYPE_SHIFT)) & PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_2_TYPE_MASK)

#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_2_TC_MASK (0xE0U)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_2_TC_SHIFT (5U)
/*! TC - When the TC field of an inbound TLP is matched to this value, then address translation
 *    proceeds (when all other enabled field-matches are successful). This check is only performed if
 *    the "TC Match Enable" bit of the "iATU Control 2 Register" is set. Note: This register field is
 *    sticky.
 */
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_2_TC(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_2_TC_SHIFT)) & PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_2_TC_MASK)

#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_2_TD_MASK (0x100U)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_2_TD_SHIFT (8U)
/*! TD - When the TD field of an inbound TLP is matched to this value, then address translation
 *    proceeds (when all other enabled field-matches are successful). This check is only performed if
 *    the "TD Match Enable" bit of the "iATU Control 2 Register" is set. Note: This register field is
 *    sticky.
 */
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_2_TD(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_2_TD_SHIFT)) & PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_2_TD_MASK)

#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_2_ATTR_MASK (0x600U)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_2_ATTR_SHIFT (9U)
/*! ATTR - When the ATTR field of an inbound TLP is matched to this value, then address translation
 *    proceeds (when all other enabled field-matches are successful). This check is only performed
 *    if the "ATTR Match Enable" bit of the "iATU Control 2 Register" is set. Note: This register
 *    field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_2_ATTR(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_2_ATTR_SHIFT)) & PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_2_ATTR_MASK)

#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_2_INCREASE_REGION_SIZE_MASK (0x2000U)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_2_INCREASE_REGION_SIZE_SHIFT (13U)
/*! INCREASE_REGION_SIZE - Increase the maximum ATU Region size. When set, the maximum ATU Region
 *    size is determined by CX_ATU_MAX_REGION_SIZEMaximum Size of iATU Region When clear, the maximum
 *    ATU Region size is 4 GB (default). Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_2_INCREASE_REGION_SIZE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_2_INCREASE_REGION_SIZE_SHIFT)) & PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_2_INCREASE_REGION_SIZE_MASK)

#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_2_CTRL_1_FUNC_NUM_MASK (0x700000U)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_2_CTRL_1_FUNC_NUM_SHIFT (20U)
/*! CTRL_1_FUNC_NUM - Function Number. - MEM-I/O: When the Address and BAR matching logic in the
 *    controller indicate that a MEM-I/O transaction matches a BAR in the function corresponding to
 *    this value, then address translation proceeds. This check is only performed if the "Function
 *    Number Match Enable" bit of the "iATU Control 2 Register" is set. - CFG0/CFG1: When the
 *    destination function number as specified in the routing ID of the TLP header matches the function, then
 *    address translation proceeds. This check is only performed if the "Function Number Match
 *    Enable" bit of the "iATU Control 2 Register" is set. Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_2_CTRL_1_FUNC_NUM(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_2_CTRL_1_FUNC_NUM_SHIFT)) & PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_2_CTRL_1_FUNC_NUM_MASK)
/*! @} */

/*! @name IATU_REGION_CTRL_2_OFF_INBOUND_2 - iATU Region Control 2 Register. */
/*! @{ */

#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_MSG_CODE_MASK (0xFFU)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_MSG_CODE_SHIFT (0U)
/*! MSG_CODE - MSG TLPs: (Message Code). When the TYPE field of an inbound Msg/MsgD TLP is matched
 *    to this value, then address translation proceeds (when all other enabled field-matches are
 *    successful). This check is only performed if the "Message Code Match Enable" bit of the "iATU
 *    Control 2 Register" is set. Memory TLPs: (ST;Steering Tag). When the ST field of an inbound TLP is
 *    matched to this value, then address translation proceeds. This check is only performed if the
 *    "ST Match Enable" bit of the "iATU Control2 Register" is set. The setting is independent of
 *    the setting of the TH field. Only Valid when the CX_TPH_ENABLE configuration parameter is 1.
 *    Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_MSG_CODE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_MSG_CODE_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_MSG_CODE_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_BAR_NUM_MASK (0x700U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_BAR_NUM_SHIFT (8U)
/*! BAR_NUM - BAR Number. When the BAR number of an inbound MEM or IO TLP " that is matched by the
 *    normal internal BAR address matching mechanism " is the same as this field, address translation
 *    proceeds (when all other enabled field-matches are successful). This check is only performed
 *    if the "Match Mode" bit of the "iATU Control 2 Register" is set. - 000b - BAR0 - 001b - BAR1 -
 *    010b - BAR2 - 011b - BAR3 - 100b - BAR4 - 101b - BAR5 - 110b - ROM - 111b - reserved - IO
 *    translation would require either 00100b or 00101b in the inbound TLP TYPE; the BAR Number set in
 *    the range 000b - 101b and that BAR configured as an IO BAR. Note: This register field is
 *    sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_BAR_NUM(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_BAR_NUM_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_BAR_NUM_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_MSG_TYPE_MATCH_MODE_MASK (0x2000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_MSG_TYPE_MATCH_MODE_SHIFT (13U)
/*! MSG_TYPE_MATCH_MODE - Message Type Match Mode. When enabled, and if single address location
 *    translate enable is set, then inbound TLPs of type MSG/MSGd which match the type field of the
 *    iatu_region_ctrl_1_OFF_inbound register (=>TYPE[4:3]=2'b10) will be translated. Message type match
 *    mode overrides any value of MATCH_MODE field in this register. Usage scenarios for this are
 *    translation of VDM or ATS messages when AXI bridge is configured on client interface. Note:
 *    This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_MSG_TYPE_MATCH_MODE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_MSG_TYPE_MATCH_MODE_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_MSG_TYPE_MATCH_MODE_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_TC_MATCH_EN_MASK (0x4000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_TC_MATCH_EN_SHIFT (14U)
/*! TC_MATCH_EN - TC Match Enable. Ensures that a successful TC TLP field comparison match (see TC
 *    field of the "iATU Control 1 Register") occurs for address translation to proceed. Note: This
 *    register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_TC_MATCH_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_TC_MATCH_EN_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_TC_MATCH_EN_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_TD_MATCH_EN_MASK (0x8000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_TD_MATCH_EN_SHIFT (15U)
/*! TD_MATCH_EN - TD Match Enable. Ensures that a successful TD TLP field comparison match (see TD
 *    field of the "iATU Control 1 Register") occurs for address translation to proceed. Note: This
 *    register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_TD_MATCH_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_TD_MATCH_EN_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_TD_MATCH_EN_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_ATTR_MATCH_EN_MASK (0x10000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_ATTR_MATCH_EN_SHIFT (16U)
/*! ATTR_MATCH_EN - ATTR Match Enable. Ensures that a successful ATTR TLP field comparison match
 *    (see ATTR field of the "iATU Control 1 Register") occurs for address translation to proceed.
 *    Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_ATTR_MATCH_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_ATTR_MATCH_EN_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_ATTR_MATCH_EN_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_FUNC_NUM_MATCH_EN_MASK (0x80000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_FUNC_NUM_MATCH_EN_SHIFT (19U)
/*! FUNC_NUM_MATCH_EN - Function Number Match Enable. Ensures that a successful Function Number TLP
 *    field comparison match (see Function Number field of the "iATU Control 1 Register") occurs (in
 *    MEM-I/O and CFG0/CFG1 transactions) for address translation to proceed. Note: This register
 *    field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_FUNC_NUM_MATCH_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_FUNC_NUM_MATCH_EN_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_FUNC_NUM_MATCH_EN_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_MSG_CODE_MATCH_EN_MASK (0x200000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_MSG_CODE_MATCH_EN_SHIFT (21U)
/*! MSG_CODE_MATCH_EN - Message Code Match Enable (Msg TLPS). Ensures that a successful message Code
 *    TLP field comparison match (see Message Code field of the "iATU Control 2 Register") occurs
 *    (in MSG transactions) for address translation to proceed. ST Match Enable (Mem TLPs). Ensures
 *    that a successful ST TLP field comparison match (see ST field of the "iATU Control 2 Register")
 *    occurs (in MEM transactions) for address translation to proceed. Only Valid when the
 *    CX_TPH_ENABLE configuration parameter is 1 Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_MSG_CODE_MATCH_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_MSG_CODE_MATCH_EN_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_MSG_CODE_MATCH_EN_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_SINGLE_ADDR_LOC_TRANS_EN_MASK (0x800000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_SINGLE_ADDR_LOC_TRANS_EN_SHIFT (23U)
/*! SINGLE_ADDR_LOC_TRANS_EN - Single Address Location Translate Enable. When enabled, Rx TLPs can
 *    be translated to a single address location as determined by the target address register of the
 *    iATU region. The main usage scenario is translation of Messages (such as Vendor Defined or ATS
 *    Messages) to MWr TLPs when the AXI bridge is enabled. Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_SINGLE_ADDR_LOC_TRANS_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_SINGLE_ADDR_LOC_TRANS_EN_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_SINGLE_ADDR_LOC_TRANS_EN_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_RESPONSE_CODE_MASK (0x3000000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_RESPONSE_CODE_SHIFT (24U)
/*! RESPONSE_CODE - Response Code. Defines the type of response to give for accesses matching this
 *    region. This overrides the normal RADM filter response. Note that this feature is not available
 *    for any region where Single Address Location Translate is enabled. - 00 - Normal RADM filter
 *    response is used. - 01 - Unsupported request (UR) - 10 - Completer abort (CA) - 11 - Not used
 *    / undefined / reserved. Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_RESPONSE_CODE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_RESPONSE_CODE_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_RESPONSE_CODE_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_FUZZY_TYPE_MATCH_CODE_MASK (0x8000000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_FUZZY_TYPE_MATCH_CODE_SHIFT (27U)
/*! FUZZY_TYPE_MATCH_CODE - Fuzzy Type Match Mode. When enabled, the iATU relaxes the matching of
 *    the TLP TYPE field against the expected TYPE field so that - CfgRd0 and CfgRd1 TLPs are seen as
 *    identical. Similarly with CfgWr0 and CfgWr1. - MWr, MRd and MRdLk TLPs are seen as identical -
 *    The Routing field of Msg/MsgD TLPs is ignored - FetchAdd, Swap and CAS are seen as identical.
 *    For example, CFG0 in the TYPE field in the "iATU Control 1 Register" matches against an
 *    inbound CfgRd0, CfgRd1, CfgWr0 or CfgWr1 TLP. Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_FUZZY_TYPE_MATCH_CODE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_FUZZY_TYPE_MATCH_CODE_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_FUZZY_TYPE_MATCH_CODE_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_CFG_SHIFT_MODE_MASK (0x10000000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_CFG_SHIFT_MODE_SHIFT (28U)
/*! CFG_SHIFT_MODE - CFG Shift Mode. This is useful for CFG transactions where the PCIe
 *    configuration mechanism maps bits [27:12] of the address to the bus/device and function number. This
 *    allows a CFG configuration space to be located in any 256MB window of your application memory space
 *    using a 28-bit effective address. Shifts bits [31:16] of the untranslated address to form
 *    bits [27:12] of the translated address. Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_CFG_SHIFT_MODE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_CFG_SHIFT_MODE_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_CFG_SHIFT_MODE_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_INVERT_MODE_MASK (0x20000000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_INVERT_MODE_SHIFT (29U)
/*! INVERT_MODE - Invert Mode. When set the address matching region is inverted. Therefore, an
 *    address match occurs when the untranslated address is in the region outside the defined range (Base
 *    Address to Limit Address). Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_INVERT_MODE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_INVERT_MODE_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_INVERT_MODE_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_MATCH_MODE_MASK (0x40000000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_MATCH_MODE_SHIFT (30U)
/*! MATCH_MODE - Match Mode. Determines Inbound matching mode for TLPs. The mode depends on the type
 *    of TLP that is received as follows: For MEM-I/O TLPs, this field is interpreted as follows: -
 *    0: Address Match Mode. The iATU operates using addresses as in the outbound direction. The
 *    Region Base and Limit Registers must be setup. - 1:BAR Match Mode. BAR matching is used. The
 *    "BAR Number" field is relevant. Not used for RC. For CFG0 TLPs, this field is interpreted as
 *    follows: - 0: Routing ID Match Mode. The iATU interprets the Routing ID (Bytes 8 to 11 of TLP
 *    header) as an address. This corresponds to the upper 16 bits of the address in MEM-I/O
 *    transactions. The Routing ID of the TLP must be within the base and limit of the iATU region for matching
 *    to proceed. - 1: Accept Mode. The iATU accepts all CFG0 transactions as address matches. The
 *    routing ID in the CFG0 TLP is ignored. This is useful as all received CFG0 TLPs should be
 *    processed regardless of the Bus number. For MSG/MSGD TLPs, this field is interpreted as follows: -
 *    0: Address Match Mode. The iATU treats the third dword and fourth dword of the inbound
 *    MSG/MSGD TLP as an address and it is matched against the Region Base and Limit Registers. - 1:
 *    Vendor ID Match Mode. This mode is relevant for ID-routed Vendor Defined Messages. The iATU ignores
 *    the Routing ID (Bus, Device, Function) in bits [31:16] of the third dword of the TLP header,
 *    but matches against the Vendor ID in bits [15:0] of the third dword of the TLP header. Bits
 *    [15:0] of the Region Upper Base register should be programmed with the required Vendor ID. The
 *    lower Base and Limit Register should be programmed to translate TLPs based on vendor specific
 *    information in the fourth dword of the TLP header. - If SINGLE_ADDRESS_LOCATION_TRANSLATE_EN =
 *    1 AND MSG_TYPE_MATCH_MODE = 1, then Match Mode is ignored. Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_MATCH_MODE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_MATCH_MODE_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_MATCH_MODE_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_REGION_EN_MASK (0x80000000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_REGION_EN_SHIFT (31U)
/*! REGION_EN - Region Enable. This bit must be set to '1' for address translation to take place. Note: This register field is sticky. */
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_REGION_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_REGION_EN_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_2_REGION_EN_MASK)
/*! @} */

/*! @name IATU_LWR_BASE_ADDR_OFF_INBOUND_2 - iATU Lower Base Address Register. */
/*! @{ */

#define PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_2_LWR_BASE_HW_MASK (0xFFFFU)
#define PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_2_LWR_BASE_HW_SHIFT (0U)
/*! LWR_BASE_HW - Forms bits [n-1:0] of the start address of the address region to be translated.
 *    The start address must be aligned to a CX_ATU_MIN_REGION_SIZEMinimum Size of iATU Region kB
 *    boundary, so these bits are always 0. A write to this location is ignored by the PCIe controller.
 *    n is log2(CX_ATU_MIN_REGION_SIZEMinimum Size of iATU Region)
 */
#define PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_2_LWR_BASE_HW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_2_LWR_BASE_HW_SHIFT)) & PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_2_LWR_BASE_HW_MASK)

#define PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_2_LWR_BASE_RW_MASK (0xFFFF0000U)
#define PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_2_LWR_BASE_RW_SHIFT (16U)
/*! LWR_BASE_RW - Forms bits [31:n] of the start address of the address region to be translated. n
 *    is log2(CX_ATU_MIN_REGION_SIZEMinimum Size of iATU Region) Note: This register field is sticky.
 */
#define PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_2_LWR_BASE_RW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_2_LWR_BASE_RW_SHIFT)) & PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_2_LWR_BASE_RW_MASK)
/*! @} */

/*! @name IATU_UPPER_BASE_ADDR_OFF_INBOUND_2 - iATU Upper Base Address Register. */
/*! @{ */

#define PCIE_IATU_UPPER_BASE_ADDR_OFF_INBOUND_2_UPPER_BASE_RW_MASK (0xFFFFFFFFU)
#define PCIE_IATU_UPPER_BASE_ADDR_OFF_INBOUND_2_UPPER_BASE_RW_SHIFT (0U)
/*! UPPER_BASE_RW - Forms bits [63:32] of the start (and end) address of the address region to be
 *    translated. Note: This register field is sticky.
 */
#define PCIE_IATU_UPPER_BASE_ADDR_OFF_INBOUND_2_UPPER_BASE_RW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_UPPER_BASE_ADDR_OFF_INBOUND_2_UPPER_BASE_RW_SHIFT)) & PCIE_IATU_UPPER_BASE_ADDR_OFF_INBOUND_2_UPPER_BASE_RW_MASK)
/*! @} */

/*! @name IATU_LIMIT_ADDR_OFF_INBOUND_2 - iATU Limit Address Register. */
/*! @{ */

#define PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_2_LIMIT_ADDR_HW_MASK (0xFFFFU)
#define PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_2_LIMIT_ADDR_HW_SHIFT (0U)
/*! LIMIT_ADDR_HW - Forms lower bits of the end address of the address region to be translated. The
 *    end address must be aligned to a CX_ATU_MIN_REGION_SIZEMinimum Size of iATU Region kB
 *    boundary, so these bits are always 0. A write to this location is ignored by the PCIe controller.
 */
#define PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_2_LIMIT_ADDR_HW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_2_LIMIT_ADDR_HW_SHIFT)) & PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_2_LIMIT_ADDR_HW_MASK)

#define PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_2_LIMIT_ADDR_RW_MASK (0xFFFF0000U)
#define PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_2_LIMIT_ADDR_RW_SHIFT (16U)
/*! LIMIT_ADDR_RW - Forms upper bits of the end address of the address region to be translated. The
 *    end address must be aligned to a CX_ATU_MIN_REGION_SIZEMinimum Size of iATU Region kB
 *    boundary, so these bits are always 0. A write to this location is ignored by the PCIe controller.
 *    Note: This register field is sticky.
 */
#define PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_2_LIMIT_ADDR_RW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_2_LIMIT_ADDR_RW_SHIFT)) & PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_2_LIMIT_ADDR_RW_MASK)
/*! @} */

/*! @name IATU_LWR_TARGET_ADDR_OFF_INBOUND_2 - iATU Lower Target Address Register. */
/*! @{ */

#define PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_2_LWR_TARGET_HW_MASK (0xFFFFU)
#define PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_2_LWR_TARGET_HW_SHIFT (0U)
/*! LWR_TARGET_HW - Forms the LSB's of the Lower Target part of the new address of the translated
 *    region. The start address must be aligned to a CX_ATU_MIN_REGION_SIZEMinimum Size of iATU Region
 *    kB boundary (in address match mode); and to the Bar size boundary (in BAR match mode) so that
 *    these bits are always '0'. If the BAR is smaller than the iATU region size, then the iATU
 *    target address must align to the iATU region size; otherwise it must align to the BAR size. A
 *    write to this location is ignored by the PCIe controller. - Field size depends on
 *    log2(CX_ATU_MIN_REGION_SIZEMinimum Size of iATU Region) in address match mode. - Field size depends on
 *    log2(BAR_MASK+1) in BAR match mode.
 */
#define PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_2_LWR_TARGET_HW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_2_LWR_TARGET_HW_SHIFT)) & PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_2_LWR_TARGET_HW_MASK)

#define PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_2_LWR_TARGET_RW_MASK (0xFFFF0000U)
#define PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_2_LWR_TARGET_RW_SHIFT (16U)
/*! LWR_TARGET_RW - Forms MSB's of the Lower Target part of the new address of the translated
 *    region. These bits are always '0'. - Field size depends on log2(CX_ATU_MIN_REGION_SIZEMinimum Size
 *    of iATU Region) in address match mode. - Field size depends on log2(BAR_MASK+1) in BAR match
 *    mode. Note: This register field is sticky.
 */
#define PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_2_LWR_TARGET_RW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_2_LWR_TARGET_RW_SHIFT)) & PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_2_LWR_TARGET_RW_MASK)
/*! @} */

/*! @name IATU_REGION_CTRL_1_OFF_OUTBOUND_3 - iATU Region Control 1 Register. */
/*! @{ */

#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_3_TYPE_MASK (0x1FU)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_3_TYPE_SHIFT (0U)
/*! TYPE - When the address of an outbound TLP is matched to this region, then the TYPE field of the
 *    TLP is changed to the value in this register. Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_3_TYPE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_3_TYPE_SHIFT)) & PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_3_TYPE_MASK)

#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_3_TC_MASK (0xE0U)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_3_TC_SHIFT (5U)
/*! TC - When the address of an outbound TLP is matched to this region, then the TC field of the TLP
 *    is changed to the value in this register. Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_3_TC(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_3_TC_SHIFT)) & PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_3_TC_MASK)

#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_3_TD_MASK (0x100U)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_3_TD_SHIFT (8U)
/*! TD - When the address of an outbound TLP is matched to this region, then the TD field of the TLP
 *    is changed to the value in this register. Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_3_TD(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_3_TD_SHIFT)) & PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_3_TD_MASK)

#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_3_ATTR_MASK (0x600U)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_3_ATTR_SHIFT (9U)
/*! ATTR - When the address of an outbound TLP is matched to this region, then the ATTR field of the
 *    TLP is changed to the value in this register. Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_3_ATTR(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_3_ATTR_SHIFT)) & PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_3_ATTR_MASK)

#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_3_INCREASE_REGION_SIZE_MASK (0x2000U)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_3_INCREASE_REGION_SIZE_SHIFT (13U)
/*! INCREASE_REGION_SIZE - Increase the maximum ATU Region size. When set, the maximum ATU Region
 *    size is determined by CX_ATU_MAX_REGION_SIZEMaximum Size of iATU Region When clear, the maximum
 *    ATU Region size is 4 GB (default). Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_3_INCREASE_REGION_SIZE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_3_INCREASE_REGION_SIZE_SHIFT)) & PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_3_INCREASE_REGION_SIZE_MASK)

#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_3_CTRL_1_FUNC_NUM_MASK (0x700000U)
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_3_CTRL_1_FUNC_NUM_SHIFT (20U)
/*! CTRL_1_FUNC_NUM - Function Number. - When the address of an outbound TLP is matched to this
 *    region and the FUNC_BYPASS field in the "iATU Control 2 Register" is '0', then the function number
 *    used in generating the function part of the requester ID (RID) field of the TLP is taken from
 *    this 5-bit register. The value in this register must be 0x0 unless multifunction operation in
 *    the controller is enabled (CX_NFUNC > 1). - When you are using the AXI Bridge, then this
 *    field is swapped before AXI decomposition occurs so that the correct "Max_Read_Request_Size" and
 *    "Max_Payload_Size" values are used. Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_3_CTRL_1_FUNC_NUM(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_3_CTRL_1_FUNC_NUM_SHIFT)) & PCIE_IATU_REGION_CTRL_1_OFF_OUTBOUND_3_CTRL_1_FUNC_NUM_MASK)
/*! @} */

/*! @name IATU_REGION_CTRL_2_OFF_OUTBOUND_3 - iATU Region Control 2 Register. */
/*! @{ */

#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_3_MSG_CODE_MASK (0xFFU)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_3_MSG_CODE_SHIFT (0U)
/*! MSG_CODE - MSG TLPs (Message Code). When the address of an outbound TLP is matched to this
 *    region, and the translated TLP TYPE field is Msg or MsgD; then the message field of the TLP is
 *    changed to the value in this register. Memory TLPs: (ST;Steering Tag). When the ST field of an
 *    outbound TLP is matched to this region, and the translated TLP TYPE field targets memory space;
 *    then the ST field of the TLP is changed to the value in this register. Only Valid when the
 *    CX_TPH_ENABLE configuration parameter is 1. Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_3_MSG_CODE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_3_MSG_CODE_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_3_MSG_CODE_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_3_TAG_MASK (0xFF00U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_3_TAG_SHIFT (8U)
/*! TAG - TAG. The substituted TAG field (byte 6) in the outgoing TLP header when TAG_SUBSTITUTE_EN
 *    is set. Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_3_TAG(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_3_TAG_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_3_TAG_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_3_TAG_SUBSTITUTE_EN_MASK (0x10000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_3_TAG_SUBSTITUTE_EN_SHIFT (16U)
/*! TAG_SUBSTITUTE_EN - TAG Substitute Enable. When enabled and region address is matched, the iATU
 *    substitutes the TAG field of the outbound TLP header with the contents of the TAG field in
 *    this register. The expected usage scenario is translation from AXI MWr to Vendor Defined
 *    Msg/MsgD. Note (CX_TPH_ENABLE=1): TAG substitution for MWr will not occur because this field (byte 6)
 *    in the TLP header is the ST field. ST substitution can still take place using the MSG_CODE
 *    field in IATU_REGION_CTRL_2_OFF_OUTBOUND_i. Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_3_TAG_SUBSTITUTE_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_3_TAG_SUBSTITUTE_EN_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_3_TAG_SUBSTITUTE_EN_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_3_FUNC_BYPASS_MASK (0x80000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_3_FUNC_BYPASS_SHIFT (19U)
/*! FUNC_BYPASS - Function Number Translation Bypass. In this mode, the function number of the
 *    translated TLP is taken from your application transmit interface and not from the CTRL_1_FUNC_NUM
 *    field of the "iATU Control 1 Register" or the VF_NUMBER field of the "iATU Control 3 Register."
 *    Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_3_FUNC_BYPASS(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_3_FUNC_BYPASS_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_3_FUNC_BYPASS_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_3_SNP_MASK (0x100000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_3_SNP_SHIFT (20U)
/*! SNP - Serialize Non-Posted Requests. In this mode, when the AXI Bridge is populated, same AXI ID
 *    Non-Posted Read/Write Requests are transmitted on the wire if there are no other same ID
 *    Non-Posted Requests outstanding. Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_3_SNP(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_3_SNP_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_3_SNP_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_3_INHIBIT_PAYLOAD_MASK (0x400000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_3_INHIBIT_PAYLOAD_SHIFT (22U)
/*! INHIBIT_PAYLOAD - Inhibit TLP Payload Data for TLP's in Matched Region; assign iATU region to be
 *    TLP without data. When enabled and region address is matched, the iATU marks all TLPs as
 *    having no payload data by forcing the TLP header Fmt[1] bit =0, regardless of the application
 *    inputs such as slv_wstrb. - 1: Fmt[1] =0 so that only TLP type without data is sent. For example,
 *    a Msg instead of MsgD will be sent. - 0: Fmt[1] =0/1 so that TLPs with or without data can be
 *    sent. Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_3_INHIBIT_PAYLOAD(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_3_INHIBIT_PAYLOAD_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_3_INHIBIT_PAYLOAD_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_3_HEADER_SUBSTITUTE_EN_MASK (0x800000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_3_HEADER_SUBSTITUTE_EN_SHIFT (23U)
/*! HEADER_SUBSTITUTE_EN - Header Substitute Enable. When enabled and region address is matched, the
 *    iATU fully substitutes bytes 8-11 (for 3 DWORD header) or bytes 12-15 (for 4 DWORD header) of
 *    the outbound TLP header with the contents of the LWR_TARGET_RW field in
 *    IATU_LWR_TARGET_ADDR_OFF_OUTBOUND_i. - 1: LWR_TARGET_RW in the iATU_LWR_TARGET_ADDR_OFF_OUTBOUND_i register is used
 *    to fill bytes 8-to-11 (for 3 DWORD header) or bytes 12-to-15 (for 4 DWORD header) of the
 *    translated TLP header. - 0: LWR_TARGET_RW in the iATU_LWR_TARGET_ADDR_OFF_OUTBOUND_i register
 *    forms the new address of the translated region. Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_3_HEADER_SUBSTITUTE_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_3_HEADER_SUBSTITUTE_EN_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_3_HEADER_SUBSTITUTE_EN_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_3_DMA_BYPASS_MASK (0x8000000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_3_DMA_BYPASS_SHIFT (27U)
/*! DMA_BYPASS - DMA Bypass Mode. Allows request TLPs which are initiated by the DMA controller to
 *    pass through the iATU untranslated. Note: This field is reserved for the SW product. You must
 *    set it to '0'. Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_3_DMA_BYPASS(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_3_DMA_BYPASS_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_3_DMA_BYPASS_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_3_CFG_SHIFT_MODE_MASK (0x10000000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_3_CFG_SHIFT_MODE_SHIFT (28U)
/*! CFG_SHIFT_MODE - CFG Shift Mode. The iATU uses bits [27:12] of the untranslated address (on the
 *    XALI0/1/2 interface or AXI slave interface address) to form the BDF number of the outgoing CFG
 *    TLP. This supports the Enhanced Configuration Address Mapping (ECAM) mechanism (Section 7.2.2
 *    of the PCI Express Base 3.1 Specification, revision 1.0) by allowing all outgoing I/O and MEM
 *    TLPs (that have been translated to CFG) to be mapped from memory space into any 256 MB region
 *    of the PCIe configuration space. Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_3_CFG_SHIFT_MODE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_3_CFG_SHIFT_MODE_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_3_CFG_SHIFT_MODE_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_3_INVERT_MODE_MASK (0x20000000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_3_INVERT_MODE_SHIFT (29U)
/*! INVERT_MODE - Invert Mode. When set the address matching region is inverted. Therefore, an
 *    address match occurs when the untranslated address is in the region outside the defined range (Base
 *    Address to Limit Address). Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_3_INVERT_MODE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_3_INVERT_MODE_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_3_INVERT_MODE_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_3_REGION_EN_MASK (0x80000000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_3_REGION_EN_SHIFT (31U)
/*! REGION_EN - Region Enable. This bit must be set to '1' for address translation to take place. Note: This register field is sticky. */
#define PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_3_REGION_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_3_REGION_EN_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_OUTBOUND_3_REGION_EN_MASK)
/*! @} */

/*! @name IATU_LWR_BASE_ADDR_OFF_OUTBOUND_3 - iATU Lower Base Address Register. */
/*! @{ */

#define PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_3_LWR_BASE_HW_MASK (0xFFFFU)
#define PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_3_LWR_BASE_HW_SHIFT (0U)
/*! LWR_BASE_HW - Forms bits [n-1:0] of the start address of the address region to be translated.
 *    The start address must be aligned to a CX_ATU_MIN_REGION_SIZEMinimum Size of iATU Region kB
 *    boundary, so these bits are always 0. A write to this location is ignored by the PCIe controller.
 *    n is log2(CX_ATU_MIN_REGION_SIZEMinimum Size of iATU Region)
 */
#define PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_3_LWR_BASE_HW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_3_LWR_BASE_HW_SHIFT)) & PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_3_LWR_BASE_HW_MASK)

#define PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_3_LWR_BASE_RW_MASK (0xFFFF0000U)
#define PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_3_LWR_BASE_RW_SHIFT (16U)
/*! LWR_BASE_RW - Forms bits [31:n] of the start address of the address region to be translated. n
 *    is log2(CX_ATU_MIN_REGION_SIZEMinimum Size of iATU Region) Note: This register field is sticky.
 */
#define PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_3_LWR_BASE_RW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_3_LWR_BASE_RW_SHIFT)) & PCIE_IATU_LWR_BASE_ADDR_OFF_OUTBOUND_3_LWR_BASE_RW_MASK)
/*! @} */

/*! @name IATU_UPPER_BASE_ADDR_OFF_OUTBOUND_3 - iATU Upper Base Address Register. */
/*! @{ */

#define PCIE_IATU_UPPER_BASE_ADDR_OFF_OUTBOUND_3_UPPER_BASE_RW_MASK (0xFFFFFFFFU)
#define PCIE_IATU_UPPER_BASE_ADDR_OFF_OUTBOUND_3_UPPER_BASE_RW_SHIFT (0U)
/*! UPPER_BASE_RW - Forms bits [63:32] of the start (and end) address of the address region to be
 *    translated. In systems with a 32-bit address space, this register is not used and therefore
 *    writing to this register has no effect. Note: This register field is sticky.
 */
#define PCIE_IATU_UPPER_BASE_ADDR_OFF_OUTBOUND_3_UPPER_BASE_RW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_UPPER_BASE_ADDR_OFF_OUTBOUND_3_UPPER_BASE_RW_SHIFT)) & PCIE_IATU_UPPER_BASE_ADDR_OFF_OUTBOUND_3_UPPER_BASE_RW_MASK)
/*! @} */

/*! @name IATU_LIMIT_ADDR_OFF_OUTBOUND_3 - iATU Limit Address Register. */
/*! @{ */

#define PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_3_LIMIT_ADDR_HW_MASK (0xFFFFU)
#define PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_3_LIMIT_ADDR_HW_SHIFT (0U)
/*! LIMIT_ADDR_HW - Forms lower bits of the end address of the address region to be translated. The
 *    end address must be aligned to a CX_ATU_MIN_REGION_SIZEMinimum Size of iATU Region kB
 *    boundary, so these bits are always 0. A write to this location is ignored by the PCIe controller.
 */
#define PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_3_LIMIT_ADDR_HW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_3_LIMIT_ADDR_HW_SHIFT)) & PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_3_LIMIT_ADDR_HW_MASK)

#define PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_3_LIMIT_ADDR_RW_MASK (0xFFFF0000U)
#define PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_3_LIMIT_ADDR_RW_SHIFT (16U)
/*! LIMIT_ADDR_RW - Forms upper bits of the end address of the address region to be translated. The
 *    end address must be aligned to a CX_ATU_MIN_REGION_SIZEMinimum Size of iATU Region kB
 *    boundary, so these bits are always 0. A write to this location is ignored by the PCIe controller.
 *    Note: This register field is sticky.
 */
#define PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_3_LIMIT_ADDR_RW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_3_LIMIT_ADDR_RW_SHIFT)) & PCIE_IATU_LIMIT_ADDR_OFF_OUTBOUND_3_LIMIT_ADDR_RW_MASK)
/*! @} */

/*! @name IATU_LWR_TARGET_ADDR_OFF_OUTBOUND_3 - iATU Lower Target Address Register. */
/*! @{ */

#define PCIE_IATU_LWR_TARGET_ADDR_OFF_OUTBOUND_3_LWR_TARGET_RW_OUTBOUND_MASK (0xFFFFFFFFU)
#define PCIE_IATU_LWR_TARGET_ADDR_OFF_OUTBOUND_3_LWR_TARGET_RW_OUTBOUND_SHIFT (0U)
/*! LWR_TARGET_RW_OUTBOUND - When HEADER_SUBSTITUTE_EN in IATU_REGION_CTRL_2_OFF_OUTBOUND_ is '0'
 *    (normal operation): - LWR_TARGET_RW[31:n] forms MSB's of the Lower Target part of the new
 *    address of the translated region; - LWR_TARGET_RW[n-1:0] are not used. (The start address must be
 *    aligned to a CX_ATU_MIN_REGION_SIZEMinimum Size of iATU Region kB boundary, so the lower bits of
 *    the start address of the new address of the translated region (bits n-1:0) are always '0'). -
 *    n is log2(CX_ATU_MIN_REGION_SIZEMinimum Size of iATU Region). When HEADER_SUBSTITUTE_EN in
 *    IATU_REGION_CTRL_2_OFF_OUTBOUND_i is '1': - LWR_TARGET_RW[31:0] forms bytes 8-11 (for 3 dword
 *    header) or bytes 12-15 (for 4 dword header) of the outbound TLP header. Usage scenarios include
 *    the transmission of Vendor Defined Messages where the controller determines the content of
 *    bytes 12 to 15 of the TLP header. Note: This register field is sticky.
 */
#define PCIE_IATU_LWR_TARGET_ADDR_OFF_OUTBOUND_3_LWR_TARGET_RW_OUTBOUND(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LWR_TARGET_ADDR_OFF_OUTBOUND_3_LWR_TARGET_RW_OUTBOUND_SHIFT)) & PCIE_IATU_LWR_TARGET_ADDR_OFF_OUTBOUND_3_LWR_TARGET_RW_OUTBOUND_MASK)
/*! @} */

/*! @name IATU_UPPER_TARGET_ADDR_OFF_OUTBOUND_3 - iATU Upper Target Address Register. */
/*! @{ */

#define PCIE_IATU_UPPER_TARGET_ADDR_OFF_OUTBOUND_3_UPPER_TARGET_RW_MASK (0xFFFFFFFFU)
#define PCIE_IATU_UPPER_TARGET_ADDR_OFF_OUTBOUND_3_UPPER_TARGET_RW_SHIFT (0U)
/*! UPPER_TARGET_RW - Forms bits [63:32] of the start address (Upper Target part) of the new address
 *    of the translated region. Note: This register field is sticky.
 */
#define PCIE_IATU_UPPER_TARGET_ADDR_OFF_OUTBOUND_3_UPPER_TARGET_RW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_UPPER_TARGET_ADDR_OFF_OUTBOUND_3_UPPER_TARGET_RW_SHIFT)) & PCIE_IATU_UPPER_TARGET_ADDR_OFF_OUTBOUND_3_UPPER_TARGET_RW_MASK)
/*! @} */

/*! @name IATU_REGION_CTRL_1_OFF_INBOUND_3 - iATU Region Control 1 Register. */
/*! @{ */

#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_3_TYPE_MASK (0x1FU)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_3_TYPE_SHIFT (0U)
/*! TYPE - When the TYPE field of an inbound TLP is matched to this value, then address translation
 *    proceeds (when all other enabled field-matches are successful). Note: This register field is
 *    sticky.
 */
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_3_TYPE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_3_TYPE_SHIFT)) & PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_3_TYPE_MASK)

#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_3_TC_MASK (0xE0U)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_3_TC_SHIFT (5U)
/*! TC - When the TC field of an inbound TLP is matched to this value, then address translation
 *    proceeds (when all other enabled field-matches are successful). This check is only performed if
 *    the "TC Match Enable" bit of the "iATU Control 2 Register" is set. Note: This register field is
 *    sticky.
 */
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_3_TC(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_3_TC_SHIFT)) & PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_3_TC_MASK)

#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_3_TD_MASK (0x100U)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_3_TD_SHIFT (8U)
/*! TD - When the TD field of an inbound TLP is matched to this value, then address translation
 *    proceeds (when all other enabled field-matches are successful). This check is only performed if
 *    the "TD Match Enable" bit of the "iATU Control 2 Register" is set. Note: This register field is
 *    sticky.
 */
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_3_TD(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_3_TD_SHIFT)) & PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_3_TD_MASK)

#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_3_ATTR_MASK (0x600U)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_3_ATTR_SHIFT (9U)
/*! ATTR - When the ATTR field of an inbound TLP is matched to this value, then address translation
 *    proceeds (when all other enabled field-matches are successful). This check is only performed
 *    if the "ATTR Match Enable" bit of the "iATU Control 2 Register" is set. Note: This register
 *    field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_3_ATTR(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_3_ATTR_SHIFT)) & PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_3_ATTR_MASK)

#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_3_INCREASE_REGION_SIZE_MASK (0x2000U)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_3_INCREASE_REGION_SIZE_SHIFT (13U)
/*! INCREASE_REGION_SIZE - Increase the maximum ATU Region size. When set, the maximum ATU Region
 *    size is determined by CX_ATU_MAX_REGION_SIZEMaximum Size of iATU Region When clear, the maximum
 *    ATU Region size is 4 GB (default). Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_3_INCREASE_REGION_SIZE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_3_INCREASE_REGION_SIZE_SHIFT)) & PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_3_INCREASE_REGION_SIZE_MASK)

#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_3_CTRL_1_FUNC_NUM_MASK (0x700000U)
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_3_CTRL_1_FUNC_NUM_SHIFT (20U)
/*! CTRL_1_FUNC_NUM - Function Number. - MEM-I/O: When the Address and BAR matching logic in the
 *    controller indicate that a MEM-I/O transaction matches a BAR in the function corresponding to
 *    this value, then address translation proceeds. This check is only performed if the "Function
 *    Number Match Enable" bit of the "iATU Control 2 Register" is set. - CFG0/CFG1: When the
 *    destination function number as specified in the routing ID of the TLP header matches the function, then
 *    address translation proceeds. This check is only performed if the "Function Number Match
 *    Enable" bit of the "iATU Control 2 Register" is set. Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_3_CTRL_1_FUNC_NUM(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_3_CTRL_1_FUNC_NUM_SHIFT)) & PCIE_IATU_REGION_CTRL_1_OFF_INBOUND_3_CTRL_1_FUNC_NUM_MASK)
/*! @} */

/*! @name IATU_REGION_CTRL_2_OFF_INBOUND_3 - iATU Region Control 2 Register. */
/*! @{ */

#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_MSG_CODE_MASK (0xFFU)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_MSG_CODE_SHIFT (0U)
/*! MSG_CODE - MSG TLPs: (Message Code). When the TYPE field of an inbound Msg/MsgD TLP is matched
 *    to this value, then address translation proceeds (when all other enabled field-matches are
 *    successful). This check is only performed if the "Message Code Match Enable" bit of the "iATU
 *    Control 2 Register" is set. Memory TLPs: (ST;Steering Tag). When the ST field of an inbound TLP is
 *    matched to this value, then address translation proceeds. This check is only performed if the
 *    "ST Match Enable" bit of the "iATU Control2 Register" is set. The setting is independent of
 *    the setting of the TH field. Only Valid when the CX_TPH_ENABLE configuration parameter is 1.
 *    Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_MSG_CODE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_MSG_CODE_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_MSG_CODE_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_BAR_NUM_MASK (0x700U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_BAR_NUM_SHIFT (8U)
/*! BAR_NUM - BAR Number. When the BAR number of an inbound MEM or IO TLP " that is matched by the
 *    normal internal BAR address matching mechanism " is the same as this field, address translation
 *    proceeds (when all other enabled field-matches are successful). This check is only performed
 *    if the "Match Mode" bit of the "iATU Control 2 Register" is set. - 000b - BAR0 - 001b - BAR1 -
 *    010b - BAR2 - 011b - BAR3 - 100b - BAR4 - 101b - BAR5 - 110b - ROM - 111b - reserved - IO
 *    translation would require either 00100b or 00101b in the inbound TLP TYPE; the BAR Number set in
 *    the range 000b - 101b and that BAR configured as an IO BAR. Note: This register field is
 *    sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_BAR_NUM(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_BAR_NUM_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_BAR_NUM_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_MSG_TYPE_MATCH_MODE_MASK (0x2000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_MSG_TYPE_MATCH_MODE_SHIFT (13U)
/*! MSG_TYPE_MATCH_MODE - Message Type Match Mode. When enabled, and if single address location
 *    translate enable is set, then inbound TLPs of type MSG/MSGd which match the type field of the
 *    iatu_region_ctrl_1_OFF_inbound register (=>TYPE[4:3]=2'b10) will be translated. Message type match
 *    mode overrides any value of MATCH_MODE field in this register. Usage scenarios for this are
 *    translation of VDM or ATS messages when AXI bridge is configured on client interface. Note:
 *    This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_MSG_TYPE_MATCH_MODE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_MSG_TYPE_MATCH_MODE_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_MSG_TYPE_MATCH_MODE_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_TC_MATCH_EN_MASK (0x4000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_TC_MATCH_EN_SHIFT (14U)
/*! TC_MATCH_EN - TC Match Enable. Ensures that a successful TC TLP field comparison match (see TC
 *    field of the "iATU Control 1 Register") occurs for address translation to proceed. Note: This
 *    register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_TC_MATCH_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_TC_MATCH_EN_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_TC_MATCH_EN_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_TD_MATCH_EN_MASK (0x8000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_TD_MATCH_EN_SHIFT (15U)
/*! TD_MATCH_EN - TD Match Enable. Ensures that a successful TD TLP field comparison match (see TD
 *    field of the "iATU Control 1 Register") occurs for address translation to proceed. Note: This
 *    register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_TD_MATCH_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_TD_MATCH_EN_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_TD_MATCH_EN_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_ATTR_MATCH_EN_MASK (0x10000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_ATTR_MATCH_EN_SHIFT (16U)
/*! ATTR_MATCH_EN - ATTR Match Enable. Ensures that a successful ATTR TLP field comparison match
 *    (see ATTR field of the "iATU Control 1 Register") occurs for address translation to proceed.
 *    Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_ATTR_MATCH_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_ATTR_MATCH_EN_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_ATTR_MATCH_EN_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_FUNC_NUM_MATCH_EN_MASK (0x80000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_FUNC_NUM_MATCH_EN_SHIFT (19U)
/*! FUNC_NUM_MATCH_EN - Function Number Match Enable. Ensures that a successful Function Number TLP
 *    field comparison match (see Function Number field of the "iATU Control 1 Register") occurs (in
 *    MEM-I/O and CFG0/CFG1 transactions) for address translation to proceed. Note: This register
 *    field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_FUNC_NUM_MATCH_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_FUNC_NUM_MATCH_EN_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_FUNC_NUM_MATCH_EN_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_MSG_CODE_MATCH_EN_MASK (0x200000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_MSG_CODE_MATCH_EN_SHIFT (21U)
/*! MSG_CODE_MATCH_EN - Message Code Match Enable (Msg TLPS). Ensures that a successful message Code
 *    TLP field comparison match (see Message Code field of the "iATU Control 2 Register") occurs
 *    (in MSG transactions) for address translation to proceed. ST Match Enable (Mem TLPs). Ensures
 *    that a successful ST TLP field comparison match (see ST field of the "iATU Control 2 Register")
 *    occurs (in MEM transactions) for address translation to proceed. Only Valid when the
 *    CX_TPH_ENABLE configuration parameter is 1 Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_MSG_CODE_MATCH_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_MSG_CODE_MATCH_EN_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_MSG_CODE_MATCH_EN_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_SINGLE_ADDR_LOC_TRANS_EN_MASK (0x800000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_SINGLE_ADDR_LOC_TRANS_EN_SHIFT (23U)
/*! SINGLE_ADDR_LOC_TRANS_EN - Single Address Location Translate Enable. When enabled, Rx TLPs can
 *    be translated to a single address location as determined by the target address register of the
 *    iATU region. The main usage scenario is translation of Messages (such as Vendor Defined or ATS
 *    Messages) to MWr TLPs when the AXI bridge is enabled. Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_SINGLE_ADDR_LOC_TRANS_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_SINGLE_ADDR_LOC_TRANS_EN_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_SINGLE_ADDR_LOC_TRANS_EN_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_RESPONSE_CODE_MASK (0x3000000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_RESPONSE_CODE_SHIFT (24U)
/*! RESPONSE_CODE - Response Code. Defines the type of response to give for accesses matching this
 *    region. This overrides the normal RADM filter response. Note that this feature is not available
 *    for any region where Single Address Location Translate is enabled. - 00 - Normal RADM filter
 *    response is used. - 01 - Unsupported request (UR) - 10 - Completer abort (CA) - 11 - Not used
 *    / undefined / reserved. Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_RESPONSE_CODE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_RESPONSE_CODE_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_RESPONSE_CODE_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_FUZZY_TYPE_MATCH_CODE_MASK (0x8000000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_FUZZY_TYPE_MATCH_CODE_SHIFT (27U)
/*! FUZZY_TYPE_MATCH_CODE - Fuzzy Type Match Mode. When enabled, the iATU relaxes the matching of
 *    the TLP TYPE field against the expected TYPE field so that - CfgRd0 and CfgRd1 TLPs are seen as
 *    identical. Similarly with CfgWr0 and CfgWr1. - MWr, MRd and MRdLk TLPs are seen as identical -
 *    The Routing field of Msg/MsgD TLPs is ignored - FetchAdd, Swap and CAS are seen as identical.
 *    For example, CFG0 in the TYPE field in the "iATU Control 1 Register" matches against an
 *    inbound CfgRd0, CfgRd1, CfgWr0 or CfgWr1 TLP. Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_FUZZY_TYPE_MATCH_CODE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_FUZZY_TYPE_MATCH_CODE_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_FUZZY_TYPE_MATCH_CODE_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_CFG_SHIFT_MODE_MASK (0x10000000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_CFG_SHIFT_MODE_SHIFT (28U)
/*! CFG_SHIFT_MODE - CFG Shift Mode. This is useful for CFG transactions where the PCIe
 *    configuration mechanism maps bits [27:12] of the address to the bus/device and function number. This
 *    allows a CFG configuration space to be located in any 256MB window of your application memory space
 *    using a 28-bit effective address. Shifts bits [31:16] of the untranslated address to form
 *    bits [27:12] of the translated address. Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_CFG_SHIFT_MODE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_CFG_SHIFT_MODE_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_CFG_SHIFT_MODE_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_INVERT_MODE_MASK (0x20000000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_INVERT_MODE_SHIFT (29U)
/*! INVERT_MODE - Invert Mode. When set the address matching region is inverted. Therefore, an
 *    address match occurs when the untranslated address is in the region outside the defined range (Base
 *    Address to Limit Address). Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_INVERT_MODE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_INVERT_MODE_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_INVERT_MODE_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_MATCH_MODE_MASK (0x40000000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_MATCH_MODE_SHIFT (30U)
/*! MATCH_MODE - Match Mode. Determines Inbound matching mode for TLPs. The mode depends on the type
 *    of TLP that is received as follows: For MEM-I/O TLPs, this field is interpreted as follows: -
 *    0: Address Match Mode. The iATU operates using addresses as in the outbound direction. The
 *    Region Base and Limit Registers must be setup. - 1:BAR Match Mode. BAR matching is used. The
 *    "BAR Number" field is relevant. Not used for RC. For CFG0 TLPs, this field is interpreted as
 *    follows: - 0: Routing ID Match Mode. The iATU interprets the Routing ID (Bytes 8 to 11 of TLP
 *    header) as an address. This corresponds to the upper 16 bits of the address in MEM-I/O
 *    transactions. The Routing ID of the TLP must be within the base and limit of the iATU region for matching
 *    to proceed. - 1: Accept Mode. The iATU accepts all CFG0 transactions as address matches. The
 *    routing ID in the CFG0 TLP is ignored. This is useful as all received CFG0 TLPs should be
 *    processed regardless of the Bus number. For MSG/MSGD TLPs, this field is interpreted as follows: -
 *    0: Address Match Mode. The iATU treats the third dword and fourth dword of the inbound
 *    MSG/MSGD TLP as an address and it is matched against the Region Base and Limit Registers. - 1:
 *    Vendor ID Match Mode. This mode is relevant for ID-routed Vendor Defined Messages. The iATU ignores
 *    the Routing ID (Bus, Device, Function) in bits [31:16] of the third dword of the TLP header,
 *    but matches against the Vendor ID in bits [15:0] of the third dword of the TLP header. Bits
 *    [15:0] of the Region Upper Base register should be programmed with the required Vendor ID. The
 *    lower Base and Limit Register should be programmed to translate TLPs based on vendor specific
 *    information in the fourth dword of the TLP header. - If SINGLE_ADDRESS_LOCATION_TRANSLATE_EN =
 *    1 AND MSG_TYPE_MATCH_MODE = 1, then Match Mode is ignored. Note: This register field is sticky.
 */
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_MATCH_MODE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_MATCH_MODE_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_MATCH_MODE_MASK)

#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_REGION_EN_MASK (0x80000000U)
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_REGION_EN_SHIFT (31U)
/*! REGION_EN - Region Enable. This bit must be set to '1' for address translation to take place. Note: This register field is sticky. */
#define PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_REGION_EN(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_REGION_EN_SHIFT)) & PCIE_IATU_REGION_CTRL_2_OFF_INBOUND_3_REGION_EN_MASK)
/*! @} */

/*! @name IATU_LWR_BASE_ADDR_OFF_INBOUND_3 - iATU Lower Base Address Register. */
/*! @{ */

#define PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_3_LWR_BASE_HW_MASK (0xFFFFU)
#define PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_3_LWR_BASE_HW_SHIFT (0U)
/*! LWR_BASE_HW - Forms bits [n-1:0] of the start address of the address region to be translated.
 *    The start address must be aligned to a CX_ATU_MIN_REGION_SIZEMinimum Size of iATU Region kB
 *    boundary, so these bits are always 0. A write to this location is ignored by the PCIe controller.
 *    n is log2(CX_ATU_MIN_REGION_SIZEMinimum Size of iATU Region)
 */
#define PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_3_LWR_BASE_HW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_3_LWR_BASE_HW_SHIFT)) & PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_3_LWR_BASE_HW_MASK)

#define PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_3_LWR_BASE_RW_MASK (0xFFFF0000U)
#define PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_3_LWR_BASE_RW_SHIFT (16U)
/*! LWR_BASE_RW - Forms bits [31:n] of the start address of the address region to be translated. n
 *    is log2(CX_ATU_MIN_REGION_SIZEMinimum Size of iATU Region) Note: This register field is sticky.
 */
#define PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_3_LWR_BASE_RW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_3_LWR_BASE_RW_SHIFT)) & PCIE_IATU_LWR_BASE_ADDR_OFF_INBOUND_3_LWR_BASE_RW_MASK)
/*! @} */

/*! @name IATU_UPPER_BASE_ADDR_OFF_INBOUND_3 - iATU Upper Base Address Register. */
/*! @{ */

#define PCIE_IATU_UPPER_BASE_ADDR_OFF_INBOUND_3_UPPER_BASE_RW_MASK (0xFFFFFFFFU)
#define PCIE_IATU_UPPER_BASE_ADDR_OFF_INBOUND_3_UPPER_BASE_RW_SHIFT (0U)
/*! UPPER_BASE_RW - Forms bits [63:32] of the start (and end) address of the address region to be
 *    translated. Note: This register field is sticky.
 */
#define PCIE_IATU_UPPER_BASE_ADDR_OFF_INBOUND_3_UPPER_BASE_RW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_UPPER_BASE_ADDR_OFF_INBOUND_3_UPPER_BASE_RW_SHIFT)) & PCIE_IATU_UPPER_BASE_ADDR_OFF_INBOUND_3_UPPER_BASE_RW_MASK)
/*! @} */

/*! @name IATU_LIMIT_ADDR_OFF_INBOUND_3 - iATU Limit Address Register. */
/*! @{ */

#define PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_3_LIMIT_ADDR_HW_MASK (0xFFFFU)
#define PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_3_LIMIT_ADDR_HW_SHIFT (0U)
/*! LIMIT_ADDR_HW - Forms lower bits of the end address of the address region to be translated. The
 *    end address must be aligned to a CX_ATU_MIN_REGION_SIZEMinimum Size of iATU Region kB
 *    boundary, so these bits are always 0. A write to this location is ignored by the PCIe controller.
 */
#define PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_3_LIMIT_ADDR_HW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_3_LIMIT_ADDR_HW_SHIFT)) & PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_3_LIMIT_ADDR_HW_MASK)

#define PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_3_LIMIT_ADDR_RW_MASK (0xFFFF0000U)
#define PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_3_LIMIT_ADDR_RW_SHIFT (16U)
/*! LIMIT_ADDR_RW - Forms upper bits of the end address of the address region to be translated. The
 *    end address must be aligned to a CX_ATU_MIN_REGION_SIZEMinimum Size of iATU Region kB
 *    boundary, so these bits are always 0. A write to this location is ignored by the PCIe controller.
 *    Note: This register field is sticky.
 */
#define PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_3_LIMIT_ADDR_RW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_3_LIMIT_ADDR_RW_SHIFT)) & PCIE_IATU_LIMIT_ADDR_OFF_INBOUND_3_LIMIT_ADDR_RW_MASK)
/*! @} */

/*! @name IATU_LWR_TARGET_ADDR_OFF_INBOUND_3 - iATU Lower Target Address Register. */
/*! @{ */

#define PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_3_LWR_TARGET_HW_MASK (0xFFFFU)
#define PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_3_LWR_TARGET_HW_SHIFT (0U)
/*! LWR_TARGET_HW - Forms the LSB's of the Lower Target part of the new address of the translated
 *    region. The start address must be aligned to a CX_ATU_MIN_REGION_SIZEMinimum Size of iATU Region
 *    kB boundary (in address match mode); and to the Bar size boundary (in BAR match mode) so that
 *    these bits are always '0'. If the BAR is smaller than the iATU region size, then the iATU
 *    target address must align to the iATU region size; otherwise it must align to the BAR size. A
 *    write to this location is ignored by the PCIe controller. - Field size depends on
 *    log2(CX_ATU_MIN_REGION_SIZEMinimum Size of iATU Region) in address match mode. - Field size depends on
 *    log2(BAR_MASK+1) in BAR match mode.
 */
#define PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_3_LWR_TARGET_HW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_3_LWR_TARGET_HW_SHIFT)) & PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_3_LWR_TARGET_HW_MASK)

#define PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_3_LWR_TARGET_RW_MASK (0xFFFF0000U)
#define PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_3_LWR_TARGET_RW_SHIFT (16U)
/*! LWR_TARGET_RW - Forms MSB's of the Lower Target part of the new address of the translated
 *    region. These bits are always '0'. - Field size depends on log2(CX_ATU_MIN_REGION_SIZEMinimum Size
 *    of iATU Region) in address match mode. - Field size depends on log2(BAR_MASK+1) in BAR match
 *    mode. Note: This register field is sticky.
 */
#define PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_3_LWR_TARGET_RW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_3_LWR_TARGET_RW_SHIFT)) & PCIE_IATU_LWR_TARGET_ADDR_OFF_INBOUND_3_LWR_TARGET_RW_MASK)
/*! @} */

/*! @name DMA_CTRL_DATA_ARB_PRIOR_OFF - DMA Arbitration Scheme for TRGT1 Interface. */
/*! @{ */

#define PCIE_DMA_CTRL_DATA_ARB_PRIOR_OFF_RTRGT1_WEIGHT_MASK (0x7U)
#define PCIE_DMA_CTRL_DATA_ARB_PRIOR_OFF_RTRGT1_WEIGHT_SHIFT (0U)
/*! RTRGT1_WEIGHT - Non-DMA Rx Requests. Note: The access attributes of this field are as follows: - Dbi: R/W */
#define PCIE_DMA_CTRL_DATA_ARB_PRIOR_OFF_RTRGT1_WEIGHT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_CTRL_DATA_ARB_PRIOR_OFF_RTRGT1_WEIGHT_SHIFT)) & PCIE_DMA_CTRL_DATA_ARB_PRIOR_OFF_RTRGT1_WEIGHT_MASK)

#define PCIE_DMA_CTRL_DATA_ARB_PRIOR_OFF_WR_CTRL_TRGT_WEIGHT_MASK (0x38U)
#define PCIE_DMA_CTRL_DATA_ARB_PRIOR_OFF_WR_CTRL_TRGT_WEIGHT_SHIFT (3U)
/*! WR_CTRL_TRGT_WEIGHT - DMA Write Channel MRd Requests. For DMA data requests and LL
 *    element/descriptor access. Note: The access attributes of this field are as follows: - Dbi: R/W
 */
#define PCIE_DMA_CTRL_DATA_ARB_PRIOR_OFF_WR_CTRL_TRGT_WEIGHT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_CTRL_DATA_ARB_PRIOR_OFF_WR_CTRL_TRGT_WEIGHT_SHIFT)) & PCIE_DMA_CTRL_DATA_ARB_PRIOR_OFF_WR_CTRL_TRGT_WEIGHT_MASK)

#define PCIE_DMA_CTRL_DATA_ARB_PRIOR_OFF_RD_CTRL_TRGT_WEIGHT_MASK (0x1C0U)
#define PCIE_DMA_CTRL_DATA_ARB_PRIOR_OFF_RD_CTRL_TRGT_WEIGHT_SHIFT (6U)
/*! RD_CTRL_TRGT_WEIGHT - DMA Read Channel MRd Requests. For LL element/descriptor access. Note: The
 *    access attributes of this field are as follows: - Dbi: R/W
 */
#define PCIE_DMA_CTRL_DATA_ARB_PRIOR_OFF_RD_CTRL_TRGT_WEIGHT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_CTRL_DATA_ARB_PRIOR_OFF_RD_CTRL_TRGT_WEIGHT_SHIFT)) & PCIE_DMA_CTRL_DATA_ARB_PRIOR_OFF_RD_CTRL_TRGT_WEIGHT_MASK)

#define PCIE_DMA_CTRL_DATA_ARB_PRIOR_OFF_RDBUFF_TRGT_WEIGHT_MASK (0xE00U)
#define PCIE_DMA_CTRL_DATA_ARB_PRIOR_OFF_RDBUFF_TRGT_WEIGHT_SHIFT (9U)
/*! RDBUFF_TRGT_WEIGHT - DMA Read Channel MWr Requests. Note: The access attributes of this field are as follows: - Dbi: R/W */
#define PCIE_DMA_CTRL_DATA_ARB_PRIOR_OFF_RDBUFF_TRGT_WEIGHT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_CTRL_DATA_ARB_PRIOR_OFF_RDBUFF_TRGT_WEIGHT_SHIFT)) & PCIE_DMA_CTRL_DATA_ARB_PRIOR_OFF_RDBUFF_TRGT_WEIGHT_MASK)

#define PCIE_DMA_CTRL_DATA_ARB_PRIOR_OFF_RSVDP_12_MASK (0xFFFFF000U)
#define PCIE_DMA_CTRL_DATA_ARB_PRIOR_OFF_RSVDP_12_SHIFT (12U)
/*! RSVDP_12 - Reserved for future use. */
#define PCIE_DMA_CTRL_DATA_ARB_PRIOR_OFF_RSVDP_12(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_CTRL_DATA_ARB_PRIOR_OFF_RSVDP_12_SHIFT)) & PCIE_DMA_CTRL_DATA_ARB_PRIOR_OFF_RSVDP_12_MASK)
/*! @} */

/*! @name DMA_CTRL_OFF - DMA Number of Channels Register. */
/*! @{ */

#define PCIE_DMA_CTRL_OFF_NUM_DMA_WR_CHAN_MASK   (0xFU)
#define PCIE_DMA_CTRL_OFF_NUM_DMA_WR_CHAN_SHIFT  (0U)
/*! NUM_DMA_WR_CHAN - Number of Write Channels. You can read this register to determine the number
 *    of write channels the DMA controller has been configured to support.
 */
#define PCIE_DMA_CTRL_OFF_NUM_DMA_WR_CHAN(x)     (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_CTRL_OFF_NUM_DMA_WR_CHAN_SHIFT)) & PCIE_DMA_CTRL_OFF_NUM_DMA_WR_CHAN_MASK)

#define PCIE_DMA_CTRL_OFF_RSVDP_4_MASK           (0xFFF0U)
#define PCIE_DMA_CTRL_OFF_RSVDP_4_SHIFT          (4U)
/*! RSVDP_4 - Reserved for future use. */
#define PCIE_DMA_CTRL_OFF_RSVDP_4(x)             (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_CTRL_OFF_RSVDP_4_SHIFT)) & PCIE_DMA_CTRL_OFF_RSVDP_4_MASK)

#define PCIE_DMA_CTRL_OFF_NUM_DMA_RD_CHAN_MASK   (0xF0000U)
#define PCIE_DMA_CTRL_OFF_NUM_DMA_RD_CHAN_SHIFT  (16U)
/*! NUM_DMA_RD_CHAN - Number of Read Channels. You can read this register to determine the number of
 *    read channels the DMA controller has been configured to support.
 */
#define PCIE_DMA_CTRL_OFF_NUM_DMA_RD_CHAN(x)     (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_CTRL_OFF_NUM_DMA_RD_CHAN_SHIFT)) & PCIE_DMA_CTRL_OFF_NUM_DMA_RD_CHAN_MASK)

#define PCIE_DMA_CTRL_OFF_RSVDP_20_MASK          (0xF00000U)
#define PCIE_DMA_CTRL_OFF_RSVDP_20_SHIFT         (20U)
/*! RSVDP_20 - Reserved for future use. */
#define PCIE_DMA_CTRL_OFF_RSVDP_20(x)            (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_CTRL_OFF_RSVDP_20_SHIFT)) & PCIE_DMA_CTRL_OFF_RSVDP_20_MASK)

#define PCIE_DMA_CTRL_OFF_DIS_C2W_CACHE_WR_MASK  (0x1000000U)
#define PCIE_DMA_CTRL_OFF_DIS_C2W_CACHE_WR_SHIFT (24U)
/*! DIS_C2W_CACHE_WR - Disable DMA Write Channels "completion to memory write" context cache
 *    pre-fetch function. Note: For internal debugging only. Note: The access attributes of this field are
 *    as follows: - Dbi: R/W
 */
#define PCIE_DMA_CTRL_OFF_DIS_C2W_CACHE_WR(x)    (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_CTRL_OFF_DIS_C2W_CACHE_WR_SHIFT)) & PCIE_DMA_CTRL_OFF_DIS_C2W_CACHE_WR_MASK)

#define PCIE_DMA_CTRL_OFF_DIS_C2W_CACHE_RD_MASK  (0x2000000U)
#define PCIE_DMA_CTRL_OFF_DIS_C2W_CACHE_RD_SHIFT (25U)
/*! DIS_C2W_CACHE_RD - Disable DMA Read Channels "completion to memory write" context cache
 *    pre-fetch function. Note: For internal debugging only. Note: The access attributes of this field are
 *    as follows: - Dbi: R/W
 */
#define PCIE_DMA_CTRL_OFF_DIS_C2W_CACHE_RD(x)    (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_CTRL_OFF_DIS_C2W_CACHE_RD_SHIFT)) & PCIE_DMA_CTRL_OFF_DIS_C2W_CACHE_RD_MASK)

#define PCIE_DMA_CTRL_OFF_RSVDP_26_MASK          (0xFC000000U)
#define PCIE_DMA_CTRL_OFF_RSVDP_26_SHIFT         (26U)
/*! RSVDP_26 - Reserved for future use. */
#define PCIE_DMA_CTRL_OFF_RSVDP_26(x)            (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_CTRL_OFF_RSVDP_26_SHIFT)) & PCIE_DMA_CTRL_OFF_RSVDP_26_MASK)
/*! @} */

/*! @name DMA_WRITE_ENGINE_EN_OFF - DMA Write Engine Enable Register. */
/*! @{ */

#define PCIE_DMA_WRITE_ENGINE_EN_OFF_DMA_WRITE_ENGINE_MASK (0x1U)
#define PCIE_DMA_WRITE_ENGINE_EN_OFF_DMA_WRITE_ENGINE_SHIFT (0U)
/*! DMA_WRITE_ENGINE - DMA Write Engine Enable. - 1: Enable - 0: Disable (Soft Reset) For normal
 *    operation, you must initially set this bit to "1", before any other software setup actions. You
 *    do not need to toggle or rewrite to this bit during normal operation. You should set this bit
 *    to "0" when you want to "Soft Reset" the DMA controller write logic. There are three possible
 *    reasons for resetting the DMA controller write logic: - The "Abort Interrupt Status" bit is set
 *    (in the "DMA Write Interrupt Status Register" DMA_WRITE_INT_STATUS_OFF), and any of the bits
 *    is in the "DMA Write Error Status Register" (DMA_WRITE_ERR_STATUS_OFF) are set. Resetting the
 *    DMA controller write logic re-initializes the control logic, ensuring that the next DMA write
 *    transfer is executed successfully. - You have executed the procedure outlined in "Stop Bit" ,
 *    after which, the "Abort Interrupt Status" bit is set and the Channel Status field (CS) of the
 *    DMA write "DMA Channel Control 1 Register " (DMA_CH_CONTROL1_OFF_WRCH_0) is set to "Stopped."
 *    Resetting the DMA controller write logic re-initializes the control logic ensuring that the
 *    next DMA write transfer is executed successfully. - During software development, when you
 *    incorrectly program the DMA write engine. To "Soft Reset" the DMA controller write logic, you must:
 *    - De-assert the DMA write engine enable bit. - Wait for the DMA to complete any in-progress
 *    TLP transfer, by waiting until a read on the DMA write engine enable bit returns a "0". - Assert
 *    the DMA write engine enable bit. This "Soft Reset" does not clear the DMA configuration
 *    registers. The DMA write transfer does not start until you write to the "DMA Write Doorbell
 *    Register" (DMA_WRITE_DOORBELL_OFF). Note: The access attributes of this field are as follows: - Dbi:
 *    R/W
 */
#define PCIE_DMA_WRITE_ENGINE_EN_OFF_DMA_WRITE_ENGINE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_ENGINE_EN_OFF_DMA_WRITE_ENGINE_SHIFT)) & PCIE_DMA_WRITE_ENGINE_EN_OFF_DMA_WRITE_ENGINE_MASK)

#define PCIE_DMA_WRITE_ENGINE_EN_OFF_RSVDP_1_MASK (0xFFFEU)
#define PCIE_DMA_WRITE_ENGINE_EN_OFF_RSVDP_1_SHIFT (1U)
/*! RSVDP_1 - Reserved for future use. */
#define PCIE_DMA_WRITE_ENGINE_EN_OFF_RSVDP_1(x)  (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_ENGINE_EN_OFF_RSVDP_1_SHIFT)) & PCIE_DMA_WRITE_ENGINE_EN_OFF_RSVDP_1_MASK)

#define PCIE_DMA_WRITE_ENGINE_EN_OFF_RSVDP_24_MASK (0xFF000000U)
#define PCIE_DMA_WRITE_ENGINE_EN_OFF_RSVDP_24_SHIFT (24U)
/*! RSVDP_24 - Reserved for future use. */
#define PCIE_DMA_WRITE_ENGINE_EN_OFF_RSVDP_24(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_ENGINE_EN_OFF_RSVDP_24_SHIFT)) & PCIE_DMA_WRITE_ENGINE_EN_OFF_RSVDP_24_MASK)
/*! @} */

/*! @name DMA_WRITE_DOORBELL_OFF - DMA Write Doorbell Register. */
/*! @{ */

#define PCIE_DMA_WRITE_DOORBELL_OFF_WR_DOORBELL_NUM_MASK (0x7U)
#define PCIE_DMA_WRITE_DOORBELL_OFF_WR_DOORBELL_NUM_SHIFT (0U)
/*! WR_DOORBELL_NUM - Doorbell Number. You must write the channel number to this register to start
 *    the DMA write transfer for that channel. The DMA detects a write to this register field even if
 *    the value of this field does not change. You do not need to toggle or write any other value
 *    to this register to start a new transfer. The range of this field is 0x0 to 0x7, and 0x0
 *    corresponds to channel 0. Also note that a write to this field triggers the controller to exit L1
 *    substates. Note: The access attributes of this field are as follows: - Dbi: R/W
 */
#define PCIE_DMA_WRITE_DOORBELL_OFF_WR_DOORBELL_NUM(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_DOORBELL_OFF_WR_DOORBELL_NUM_SHIFT)) & PCIE_DMA_WRITE_DOORBELL_OFF_WR_DOORBELL_NUM_MASK)

#define PCIE_DMA_WRITE_DOORBELL_OFF_RSVDP_3_MASK (0x7FFFFFF8U)
#define PCIE_DMA_WRITE_DOORBELL_OFF_RSVDP_3_SHIFT (3U)
/*! RSVDP_3 - Reserved for future use. */
#define PCIE_DMA_WRITE_DOORBELL_OFF_RSVDP_3(x)   (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_DOORBELL_OFF_RSVDP_3_SHIFT)) & PCIE_DMA_WRITE_DOORBELL_OFF_RSVDP_3_MASK)

#define PCIE_DMA_WRITE_DOORBELL_OFF_WR_STOP_MASK (0x80000000U)
#define PCIE_DMA_WRITE_DOORBELL_OFF_WR_STOP_SHIFT (31U)
/*! WR_STOP - Stop. Set in conjunction with the Doorbell Number field. The DMA write channel stops
 *    issuing requests, sets the channel status to "Stopped", and asserts the "Abort" interrupt if it
 *    is enabled. Before setting the Stop bit, you must read the channel Status field (CS) of the
 *    "DMA Channel Control 1 Register " (DMA_CH_CONTROL1_OFF_WRCH_0) to ensure that the write channel
 *    is "Running" (transferring data). For more information, see "Stopping the DMA Transfer
 *    (Software Stop)." Note: The access attributes of this field are as follows: - Dbi: R/W
 */
#define PCIE_DMA_WRITE_DOORBELL_OFF_WR_STOP(x)   (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_DOORBELL_OFF_WR_STOP_SHIFT)) & PCIE_DMA_WRITE_DOORBELL_OFF_WR_STOP_MASK)
/*! @} */

/*! @name DMA_WRITE_CHANNEL_ARB_WEIGHT_LOW_OFF - DMA Write Engine Channel Arbitration Weight Low Register. */
/*! @{ */

#define PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_LOW_OFF_WRITE_CHANNEL0_WEIGHT_MASK (0x1FU)
#define PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_LOW_OFF_WRITE_CHANNEL0_WEIGHT_SHIFT (0U)
/*! WRITE_CHANNEL0_WEIGHT - Channel 0 Weight. The weight is initialized by software before ringing
 *    the doorbell. The value is used by the channel weighted round robin arbiter to select the next
 *    channel read request. A value of '0' means that one TLP is issued before moving to the next
 *    channel. Note: The access attributes of this field are as follows: - Dbi: R/W
 */
#define PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_LOW_OFF_WRITE_CHANNEL0_WEIGHT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_LOW_OFF_WRITE_CHANNEL0_WEIGHT_SHIFT)) & PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_LOW_OFF_WRITE_CHANNEL0_WEIGHT_MASK)

#define PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_LOW_OFF_WRITE_CHANNEL1_WEIGHT_MASK (0x3E0U)
#define PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_LOW_OFF_WRITE_CHANNEL1_WEIGHT_SHIFT (5U)
/*! WRITE_CHANNEL1_WEIGHT - Channel 1 Weight. The weight is initialized by software before ringing
 *    the doorbell. The value is used by the channel weighted round robin arbiter to select the next
 *    channel read request. A value of '0' means that one TLP is issued before moving to the next
 *    channel. Note: The access attributes of this field are as follows: - Dbi: R/W
 */
#define PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_LOW_OFF_WRITE_CHANNEL1_WEIGHT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_LOW_OFF_WRITE_CHANNEL1_WEIGHT_SHIFT)) & PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_LOW_OFF_WRITE_CHANNEL1_WEIGHT_MASK)

#define PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_LOW_OFF_WRITE_CHANNEL2_WEIGHT_MASK (0x7C00U)
#define PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_LOW_OFF_WRITE_CHANNEL2_WEIGHT_SHIFT (10U)
/*! WRITE_CHANNEL2_WEIGHT - Channel 2 Weight. The weight is initialized by software before ringing
 *    the doorbell. The value is used by the channel weighted round robin arbiter to select the next
 *    channel read request. A value of '0' means that one TLP is issued before moving to the next
 *    channel. Note: The access attributes of this field are as follows: - Dbi: R/W
 */
#define PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_LOW_OFF_WRITE_CHANNEL2_WEIGHT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_LOW_OFF_WRITE_CHANNEL2_WEIGHT_SHIFT)) & PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_LOW_OFF_WRITE_CHANNEL2_WEIGHT_MASK)

#define PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_LOW_OFF_WRITE_CHANNEL3_WEIGHT_MASK (0xF8000U)
#define PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_LOW_OFF_WRITE_CHANNEL3_WEIGHT_SHIFT (15U)
/*! WRITE_CHANNEL3_WEIGHT - Channel 3 Weight. The weight is initialized by software before ringing
 *    the doorbell. The value is used by the channel weighted round robin arbiter to select the next
 *    channel read request. A value of '0' means that one TLP is issued before moving to the next
 *    channel. Note: The access attributes of this field are as follows: - Dbi: R/W
 */
#define PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_LOW_OFF_WRITE_CHANNEL3_WEIGHT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_LOW_OFF_WRITE_CHANNEL3_WEIGHT_SHIFT)) & PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_LOW_OFF_WRITE_CHANNEL3_WEIGHT_MASK)

#define PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_LOW_OFF_RSVDP_20_MASK (0xFFF00000U)
#define PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_LOW_OFF_RSVDP_20_SHIFT (20U)
/*! RSVDP_20 - Reserved for future use. */
#define PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_LOW_OFF_RSVDP_20(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_LOW_OFF_RSVDP_20_SHIFT)) & PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_LOW_OFF_RSVDP_20_MASK)
/*! @} */

/*! @name DMA_WRITE_CHANNEL_ARB_WEIGHT_HIGH_OFF - DMA Write Engine Channel Arbitration Weight High Register. */
/*! @{ */

#define PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_HIGH_OFF_WRITE_CHANNEL4_WEIGHT_MASK (0x1FU)
#define PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_HIGH_OFF_WRITE_CHANNEL4_WEIGHT_SHIFT (0U)
/*! WRITE_CHANNEL4_WEIGHT - Channel 4 Weight. The weight is initialized by software before ringing
 *    the doorbell. The value is used by the channel weighted round robin arbiter to select the next
 *    channel read request. A value of '0' means that one TLP is issued before moving to the next
 *    channel. Note: The access attributes of this field are as follows: - Dbi: R/W
 */
#define PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_HIGH_OFF_WRITE_CHANNEL4_WEIGHT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_HIGH_OFF_WRITE_CHANNEL4_WEIGHT_SHIFT)) & PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_HIGH_OFF_WRITE_CHANNEL4_WEIGHT_MASK)

#define PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_HIGH_OFF_WRITE_CHANNEL5_WEIGHT_MASK (0x3E0U)
#define PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_HIGH_OFF_WRITE_CHANNEL5_WEIGHT_SHIFT (5U)
/*! WRITE_CHANNEL5_WEIGHT - Channel 5 Weight. The weight is initialized by software before ringing
 *    the doorbell. The value is used by the channel weighted round robin arbiter to select the next
 *    channel read request. A value of '0' means that one TLP is issued before moving to the next
 *    channel. Note: The access attributes of this field are as follows: - Dbi: R/W
 */
#define PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_HIGH_OFF_WRITE_CHANNEL5_WEIGHT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_HIGH_OFF_WRITE_CHANNEL5_WEIGHT_SHIFT)) & PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_HIGH_OFF_WRITE_CHANNEL5_WEIGHT_MASK)

#define PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_HIGH_OFF_WRITE_CHANNEL6_WEIGHT_MASK (0x7C00U)
#define PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_HIGH_OFF_WRITE_CHANNEL6_WEIGHT_SHIFT (10U)
/*! WRITE_CHANNEL6_WEIGHT - Channel 6 Weight. The weight is initialized by software before ringing
 *    the doorbell. The value is used by the channel weighted round robin arbiter to select the next
 *    channel read request. A value of '0' means that one TLP is issued before moving to the next
 *    channel. Note: The access attributes of this field are as follows: - Dbi: R/W
 */
#define PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_HIGH_OFF_WRITE_CHANNEL6_WEIGHT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_HIGH_OFF_WRITE_CHANNEL6_WEIGHT_SHIFT)) & PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_HIGH_OFF_WRITE_CHANNEL6_WEIGHT_MASK)

#define PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_HIGH_OFF_WRITE_CHANNEL7_WEIGHT_MASK (0xF8000U)
#define PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_HIGH_OFF_WRITE_CHANNEL7_WEIGHT_SHIFT (15U)
/*! WRITE_CHANNEL7_WEIGHT - Channel 7 Weight. The weight is initialized by software before ringing
 *    the doorbell. The value is used by the channel weighted round robin arbiter to select the next
 *    channel read request. A value of '0' means that one TLP is issued before moving to the next
 *    channel. Note: The access attributes of this field are as follows: - Dbi: R/W
 */
#define PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_HIGH_OFF_WRITE_CHANNEL7_WEIGHT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_HIGH_OFF_WRITE_CHANNEL7_WEIGHT_SHIFT)) & PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_HIGH_OFF_WRITE_CHANNEL7_WEIGHT_MASK)

#define PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_HIGH_OFF_RSVDP_20_MASK (0xFFF00000U)
#define PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_HIGH_OFF_RSVDP_20_SHIFT (20U)
/*! RSVDP_20 - Reserved for future use. */
#define PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_HIGH_OFF_RSVDP_20(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_HIGH_OFF_RSVDP_20_SHIFT)) & PCIE_DMA_WRITE_CHANNEL_ARB_WEIGHT_HIGH_OFF_RSVDP_20_MASK)
/*! @} */

/*! @name DMA_READ_ENGINE_EN_OFF - DMA Read Engine Enable Register. */
/*! @{ */

#define PCIE_DMA_READ_ENGINE_EN_OFF_DMA_READ_ENGINE_MASK (0x1U)
#define PCIE_DMA_READ_ENGINE_EN_OFF_DMA_READ_ENGINE_SHIFT (0U)
/*! DMA_READ_ENGINE - DMA Read Engine Enable. - 1: Enable - 0: Disable (Soft Reset) For normal
 *    operation, you must initially set this bit to "1", before any other software setup actions. You do
 *    not need to toggle or rewrite to this bit during normal operation. You should set this field
 *    to "0" when you want to "Soft Reset" the DMA controller read logic. There are three possible
 *    reasons for resetting the DMA controller read logic: - The "Abort Interrupt Status" bit is set
 *    (in the "DMA Read Interrupt Status Register" (DMA_READ_INT_STATUS_OFF), and any of the bits in
 *    the "DMA Read Error Status Low Register" (DMA_READ_ERR_STATUS_LOW_OFF) is set. Resetting the
 *    DMA controller read logic re-initializes the control logic, ensuring that the next DMA read
 *    transfer is executed successfully. - You have executed the procedure outlined in "Stop Bit",
 *    after which, the "Abort Interrupt Status" bit is set and the channel Status field (CS) of the DMA
 *    read "DMA Channel Control 1 Register " (DMA_CH_CONTROL1_OFF_WRCH_0) is set to "Stopped".
 *    Resetting the DMA controller read logic re-initializes the control logic ensuring that the next DMA
 *    read transfer is executed successfully. - During software development, when you incorrectly
 *    program the DMA read engine. To "Soft Reset" the DMA controller read logic, you must: -
 *    De-assert the DMA read engine enable bit. - Wait for the DMA to complete any in-progress TLP
 *    transfer, by waiting until a read on the DMA read engine enable bit returns a "0". - Assert the DMA
 *    read engine enable bit. This "Soft Reset" does not clear the DMA configuration registers. The
 *    DMA read transfer does not start until you write to the "DMA Read Doorbell Register"
 *    (DMA_READ_DOORBELL_OFF). Note: The access attributes of this field are as follows: - Dbi: R/W
 */
#define PCIE_DMA_READ_ENGINE_EN_OFF_DMA_READ_ENGINE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_ENGINE_EN_OFF_DMA_READ_ENGINE_SHIFT)) & PCIE_DMA_READ_ENGINE_EN_OFF_DMA_READ_ENGINE_MASK)

#define PCIE_DMA_READ_ENGINE_EN_OFF_RSVDP_1_MASK (0xFFFEU)
#define PCIE_DMA_READ_ENGINE_EN_OFF_RSVDP_1_SHIFT (1U)
/*! RSVDP_1 - Reserved for future use. */
#define PCIE_DMA_READ_ENGINE_EN_OFF_RSVDP_1(x)   (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_ENGINE_EN_OFF_RSVDP_1_SHIFT)) & PCIE_DMA_READ_ENGINE_EN_OFF_RSVDP_1_MASK)

#define PCIE_DMA_READ_ENGINE_EN_OFF_RSVDP_24_MASK (0xFF000000U)
#define PCIE_DMA_READ_ENGINE_EN_OFF_RSVDP_24_SHIFT (24U)
/*! RSVDP_24 - Reserved for future use. */
#define PCIE_DMA_READ_ENGINE_EN_OFF_RSVDP_24(x)  (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_ENGINE_EN_OFF_RSVDP_24_SHIFT)) & PCIE_DMA_READ_ENGINE_EN_OFF_RSVDP_24_MASK)
/*! @} */

/*! @name DMA_READ_DOORBELL_OFF - DMA Read Doorbell Register. */
/*! @{ */

#define PCIE_DMA_READ_DOORBELL_OFF_RD_DOORBELL_NUM_MASK (0x7U)
#define PCIE_DMA_READ_DOORBELL_OFF_RD_DOORBELL_NUM_SHIFT (0U)
/*! RD_DOORBELL_NUM - Doorbell Number. You must write 0x0 to this register to start the DMA read
 *    transfer for that channel. The DMA detects a write to this register field even if the value of
 *    this field does not change. The range of this field is 0x0 to 0x7, and 0x0 corresponds to
 *    channel 0. Also note that a write to this field triggers the controller to exit L1 substates. Note:
 *    The access attributes of this field are as follows: - Dbi: R/W
 */
#define PCIE_DMA_READ_DOORBELL_OFF_RD_DOORBELL_NUM(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_DOORBELL_OFF_RD_DOORBELL_NUM_SHIFT)) & PCIE_DMA_READ_DOORBELL_OFF_RD_DOORBELL_NUM_MASK)

#define PCIE_DMA_READ_DOORBELL_OFF_RSVDP_3_MASK  (0x7FFFFFF8U)
#define PCIE_DMA_READ_DOORBELL_OFF_RSVDP_3_SHIFT (3U)
/*! RSVDP_3 - Reserved for future use. */
#define PCIE_DMA_READ_DOORBELL_OFF_RSVDP_3(x)    (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_DOORBELL_OFF_RSVDP_3_SHIFT)) & PCIE_DMA_READ_DOORBELL_OFF_RSVDP_3_MASK)

#define PCIE_DMA_READ_DOORBELL_OFF_RD_STOP_MASK  (0x80000000U)
#define PCIE_DMA_READ_DOORBELL_OFF_RD_STOP_SHIFT (31U)
/*! RD_STOP - Stop. Set in conjunction with the Doorbell Number field. The DMA read channel stops
 *    issuing requests, sets the channel status to "Stopped", and asserts the "Abort" interrupt if it
 *    is enabled. Before setting the Stop bit, you must read the channel Status field (CS) of the
 *    "DMA Channel Control 1 Register " (DMA_CH_CONTROL1_OFF_RDCH_0) to ensure that the read channel
 *    is "Running" (transferring data). For more information, see "Stopping the DMA Transfer
 *    (Software Stop)". Note: The access attributes of this field are as follows: - Dbi: R/W
 */
#define PCIE_DMA_READ_DOORBELL_OFF_RD_STOP(x)    (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_DOORBELL_OFF_RD_STOP_SHIFT)) & PCIE_DMA_READ_DOORBELL_OFF_RD_STOP_MASK)
/*! @} */

/*! @name DMA_READ_CHANNEL_ARB_WEIGHT_LOW_OFF - DMA Read Engine Channel Arbitration Weight Low Register. */
/*! @{ */

#define PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_LOW_OFF_READ_CHANNEL0_WEIGHT_MASK (0x1FU)
#define PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_LOW_OFF_READ_CHANNEL0_WEIGHT_SHIFT (0U)
/*! READ_CHANNEL0_WEIGHT - Channel 0 Weight. The weight is initialized by software before ringing
 *    the doorbell. The value is used by the channel weighted round robin arbiter to select the next
 *    channel read request. Note: The access attributes of this field are as follows: - Dbi: R/W
 */
#define PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_LOW_OFF_READ_CHANNEL0_WEIGHT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_LOW_OFF_READ_CHANNEL0_WEIGHT_SHIFT)) & PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_LOW_OFF_READ_CHANNEL0_WEIGHT_MASK)

#define PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_LOW_OFF_READ_CHANNEL1_WEIGHT_MASK (0x3E0U)
#define PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_LOW_OFF_READ_CHANNEL1_WEIGHT_SHIFT (5U)
/*! READ_CHANNEL1_WEIGHT - Channel 1 Weight. The weight is initialized by software before ringing
 *    the doorbell. The value is used by the channel weighted round robin arbiter to select the next
 *    channel read request. Note: The access attributes of this field are as follows: - Dbi: R/W
 */
#define PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_LOW_OFF_READ_CHANNEL1_WEIGHT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_LOW_OFF_READ_CHANNEL1_WEIGHT_SHIFT)) & PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_LOW_OFF_READ_CHANNEL1_WEIGHT_MASK)

#define PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_LOW_OFF_READ_CHANNEL2_WEIGHT_MASK (0x7C00U)
#define PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_LOW_OFF_READ_CHANNEL2_WEIGHT_SHIFT (10U)
/*! READ_CHANNEL2_WEIGHT - Channel 2 Weight. The weight is initialized by software before ringing
 *    the doorbell. The value is used by the channel weighted round robin arbiter to select the next
 *    channel read request. Note: The access attributes of this field are as follows: - Dbi: R/W
 */
#define PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_LOW_OFF_READ_CHANNEL2_WEIGHT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_LOW_OFF_READ_CHANNEL2_WEIGHT_SHIFT)) & PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_LOW_OFF_READ_CHANNEL2_WEIGHT_MASK)

#define PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_LOW_OFF_READ_CHANNEL3_WEIGHT_MASK (0xF8000U)
#define PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_LOW_OFF_READ_CHANNEL3_WEIGHT_SHIFT (15U)
/*! READ_CHANNEL3_WEIGHT - Channel 3 Weight. The weight is initialized by software before ringing
 *    the doorbell. The value is used by the channel weighted round robin arbiter to select the next
 *    channel read request. Note: The access attributes of this field are as follows: - Dbi: R/W
 */
#define PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_LOW_OFF_READ_CHANNEL3_WEIGHT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_LOW_OFF_READ_CHANNEL3_WEIGHT_SHIFT)) & PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_LOW_OFF_READ_CHANNEL3_WEIGHT_MASK)

#define PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_LOW_OFF_RSVDP_20_MASK (0xFFF00000U)
#define PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_LOW_OFF_RSVDP_20_SHIFT (20U)
/*! RSVDP_20 - Reserved for future use. */
#define PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_LOW_OFF_RSVDP_20(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_LOW_OFF_RSVDP_20_SHIFT)) & PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_LOW_OFF_RSVDP_20_MASK)
/*! @} */

/*! @name DMA_READ_CHANNEL_ARB_WEIGHT_HIGH_OFF - DMA Read Engine Channel Arbitration Weight High Register. */
/*! @{ */

#define PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_HIGH_OFF_READ_CHANNEL4_WEIGHT_MASK (0x1FU)
#define PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_HIGH_OFF_READ_CHANNEL4_WEIGHT_SHIFT (0U)
/*! READ_CHANNEL4_WEIGHT - Channel 4 Weight. The weight is initialized by software before ringing
 *    the doorbell. The value is used by the channel weighted round robin arbiter to select the next
 *    channel read request. Note: The access attributes of this field are as follows: - Dbi: R/W
 */
#define PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_HIGH_OFF_READ_CHANNEL4_WEIGHT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_HIGH_OFF_READ_CHANNEL4_WEIGHT_SHIFT)) & PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_HIGH_OFF_READ_CHANNEL4_WEIGHT_MASK)

#define PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_HIGH_OFF_READ_CHANNEL5_WEIGHT_MASK (0x3E0U)
#define PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_HIGH_OFF_READ_CHANNEL5_WEIGHT_SHIFT (5U)
/*! READ_CHANNEL5_WEIGHT - Channel 5 Weight. The weight is initialized by software before ringing
 *    the doorbell. The value is used by the channel weighted round robin arbiter to select the next
 *    channel read request. Note: The access attributes of this field are as follows: - Dbi: R/W
 */
#define PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_HIGH_OFF_READ_CHANNEL5_WEIGHT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_HIGH_OFF_READ_CHANNEL5_WEIGHT_SHIFT)) & PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_HIGH_OFF_READ_CHANNEL5_WEIGHT_MASK)

#define PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_HIGH_OFF_READ_CHANNEL6_WEIGHT_MASK (0x7C00U)
#define PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_HIGH_OFF_READ_CHANNEL6_WEIGHT_SHIFT (10U)
/*! READ_CHANNEL6_WEIGHT - Channel 6 Weight. The weight is initialized by software before ringing
 *    the doorbell. The value is used by the channel weighted round robin arbiter to select the next
 *    channel read request. Note: The access attributes of this field are as follows: - Dbi: R/W
 */
#define PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_HIGH_OFF_READ_CHANNEL6_WEIGHT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_HIGH_OFF_READ_CHANNEL6_WEIGHT_SHIFT)) & PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_HIGH_OFF_READ_CHANNEL6_WEIGHT_MASK)

#define PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_HIGH_OFF_READ_CHANNEL7_WEIGHT_MASK (0xF8000U)
#define PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_HIGH_OFF_READ_CHANNEL7_WEIGHT_SHIFT (15U)
/*! READ_CHANNEL7_WEIGHT - Channel 7 Weight. The weight is initialized by software before ringing
 *    the doorbell. The value is used by the channel weighted round robin arbiter to select the next
 *    channel read request. Note: The access attributes of this field are as follows: - Dbi: R/W
 */
#define PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_HIGH_OFF_READ_CHANNEL7_WEIGHT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_HIGH_OFF_READ_CHANNEL7_WEIGHT_SHIFT)) & PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_HIGH_OFF_READ_CHANNEL7_WEIGHT_MASK)

#define PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_HIGH_OFF_RSVDP_20_MASK (0xFFF00000U)
#define PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_HIGH_OFF_RSVDP_20_SHIFT (20U)
/*! RSVDP_20 - Reserved for future use. */
#define PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_HIGH_OFF_RSVDP_20(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_HIGH_OFF_RSVDP_20_SHIFT)) & PCIE_DMA_READ_CHANNEL_ARB_WEIGHT_HIGH_OFF_RSVDP_20_MASK)
/*! @} */

/*! @name DMA_WRITE_INT_STATUS_OFF - DMA Write Interrupt Status Register. */
/*! @{ */

#define PCIE_DMA_WRITE_INT_STATUS_OFF_WR_DONE_INT_STATUS_MASK (0xFFU)
#define PCIE_DMA_WRITE_INT_STATUS_OFF_WR_DONE_INT_STATUS_SHIFT (0U)
/*! WR_DONE_INT_STATUS - Done Interrupt Status. The DMA write channel has successfully completed the
 *    DMA transfer. For more details, see "Interrupts and Error Handling". Each bit corresponds to
 *    a DMA channel. Bit [0] corresponds to channel 0. - Enabling: For details, see "Interrupts and
 *    Error Handling". - Masking: The DMA write interrupt Mask register has no effect on this
 *    register. - Clearing: You must write a 1'b1 to the corresponding channel bit in the DMA write
 *    interrupt Clear register to clear this interrupt bit. Note: You can write to this register to
 *    emulate interrupt generation, during software or hardware testing. A write to the address triggers
 *    an interrupt, but the DMA does not set the Done or Abort bits in this register. Note: The
 *    access attributes of this field are as follows: - Dbi: R/W
 */
#define PCIE_DMA_WRITE_INT_STATUS_OFF_WR_DONE_INT_STATUS(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_INT_STATUS_OFF_WR_DONE_INT_STATUS_SHIFT)) & PCIE_DMA_WRITE_INT_STATUS_OFF_WR_DONE_INT_STATUS_MASK)

#define PCIE_DMA_WRITE_INT_STATUS_OFF_RSVDP_8_MASK (0xFF00U)
#define PCIE_DMA_WRITE_INT_STATUS_OFF_RSVDP_8_SHIFT (8U)
/*! RSVDP_8 - Reserved for future use. */
#define PCIE_DMA_WRITE_INT_STATUS_OFF_RSVDP_8(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_INT_STATUS_OFF_RSVDP_8_SHIFT)) & PCIE_DMA_WRITE_INT_STATUS_OFF_RSVDP_8_MASK)

#define PCIE_DMA_WRITE_INT_STATUS_OFF_WR_ABORT_INT_STATUS_MASK (0xFF0000U)
#define PCIE_DMA_WRITE_INT_STATUS_OFF_WR_ABORT_INT_STATUS_SHIFT (16U)
/*! WR_ABORT_INT_STATUS - Abort Interrupt Status. The DMA write channel has detected an error, or
 *    you manually stopped the transfer as described in "Error Handling Assistance by Remote
 *    Software". Each bit corresponds to a DMA channel. Bit [0] corresponds to channel 0. - Enabling: For
 *    details, see "Interrupts and Error Handling". - Masking: The DMA write interrupt Mask register
 *    has no effect on this register. - Clearing: You must write a 1'b1 to the corresponding channel
 *    bit in the DMA write interrupt Clear register to clear this interrupt bit. Note: You can write
 *    to this register to emulate interrupt generation, during software or hardware testing. A write
 *    to the address triggers an interrupt, but the DMA does not set the Done or Abort bits in this
 *    register. Note: The access attributes of this field are as follows: - Dbi: R/W
 */
#define PCIE_DMA_WRITE_INT_STATUS_OFF_WR_ABORT_INT_STATUS(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_INT_STATUS_OFF_WR_ABORT_INT_STATUS_SHIFT)) & PCIE_DMA_WRITE_INT_STATUS_OFF_WR_ABORT_INT_STATUS_MASK)

#define PCIE_DMA_WRITE_INT_STATUS_OFF_RSVDP_24_MASK (0xFF000000U)
#define PCIE_DMA_WRITE_INT_STATUS_OFF_RSVDP_24_SHIFT (24U)
/*! RSVDP_24 - Reserved for future use. */
#define PCIE_DMA_WRITE_INT_STATUS_OFF_RSVDP_24(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_INT_STATUS_OFF_RSVDP_24_SHIFT)) & PCIE_DMA_WRITE_INT_STATUS_OFF_RSVDP_24_MASK)
/*! @} */

/*! @name DMA_WRITE_INT_MASK_OFF - DMA Write Interrupt Mask Register. */
/*! @{ */

#define PCIE_DMA_WRITE_INT_MASK_OFF_WR_DONE_INT_MASK_MASK (0x1U)
#define PCIE_DMA_WRITE_INT_MASK_OFF_WR_DONE_INT_MASK_SHIFT (0U)
/*! WR_DONE_INT_MASK - Done Interrupt Mask. Prevents the Done interrupt status field in the DMA
 *    write interrupt status register from asserting the edma_int output. Each bit corresponds to a DMA
 *    channel. Bit [0] corresponds to channel 0. Note: The access attributes of this field are as
 *    follows: - Dbi: R/W
 */
#define PCIE_DMA_WRITE_INT_MASK_OFF_WR_DONE_INT_MASK(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_INT_MASK_OFF_WR_DONE_INT_MASK_SHIFT)) & PCIE_DMA_WRITE_INT_MASK_OFF_WR_DONE_INT_MASK_MASK)

#define PCIE_DMA_WRITE_INT_MASK_OFF_RSVDP_8_MASK (0xFF00U)
#define PCIE_DMA_WRITE_INT_MASK_OFF_RSVDP_8_SHIFT (8U)
/*! RSVDP_8 - Reserved for future use. */
#define PCIE_DMA_WRITE_INT_MASK_OFF_RSVDP_8(x)   (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_INT_MASK_OFF_RSVDP_8_SHIFT)) & PCIE_DMA_WRITE_INT_MASK_OFF_RSVDP_8_MASK)

#define PCIE_DMA_WRITE_INT_MASK_OFF_WR_ABORT_INT_MASK_MASK (0x10000U)
#define PCIE_DMA_WRITE_INT_MASK_OFF_WR_ABORT_INT_MASK_SHIFT (16U)
/*! WR_ABORT_INT_MASK - Abort Interrupt Mask. Prevents the Abort interrupt status field in the DMA
 *    write interrupt status register from asserting the edma_int output. Each bit corresponds to a
 *    DMA channel. Bit [0] corresponds to channel 0. Note: The access attributes of this field are as
 *    follows: - Dbi: R/W
 */
#define PCIE_DMA_WRITE_INT_MASK_OFF_WR_ABORT_INT_MASK(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_INT_MASK_OFF_WR_ABORT_INT_MASK_SHIFT)) & PCIE_DMA_WRITE_INT_MASK_OFF_WR_ABORT_INT_MASK_MASK)

#define PCIE_DMA_WRITE_INT_MASK_OFF_RSVDP_24_MASK (0xFF000000U)
#define PCIE_DMA_WRITE_INT_MASK_OFF_RSVDP_24_SHIFT (24U)
/*! RSVDP_24 - Reserved for future use. */
#define PCIE_DMA_WRITE_INT_MASK_OFF_RSVDP_24(x)  (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_INT_MASK_OFF_RSVDP_24_SHIFT)) & PCIE_DMA_WRITE_INT_MASK_OFF_RSVDP_24_MASK)
/*! @} */

/*! @name DMA_WRITE_INT_CLEAR_OFF - DMA Write Interrupt Clear Register. */
/*! @{ */

#define PCIE_DMA_WRITE_INT_CLEAR_OFF_WR_DONE_INT_CLEAR_MASK (0x1U)
#define PCIE_DMA_WRITE_INT_CLEAR_OFF_WR_DONE_INT_CLEAR_SHIFT (0U)
/*! WR_DONE_INT_CLEAR - Done Interrupt Clear. You must write a 1'b1 to clear the corresponding bit
 *    in the Done interrupt status field of the DMA write interrupt status register. Each bit
 *    corresponds to a DMA channel. Bit [0] corresponds to channel 0. Note: Reading from this self-clearing
 *    register field always returns a "0".
 */
#define PCIE_DMA_WRITE_INT_CLEAR_OFF_WR_DONE_INT_CLEAR(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_INT_CLEAR_OFF_WR_DONE_INT_CLEAR_SHIFT)) & PCIE_DMA_WRITE_INT_CLEAR_OFF_WR_DONE_INT_CLEAR_MASK)

#define PCIE_DMA_WRITE_INT_CLEAR_OFF_RSVDP_8_MASK (0xFF00U)
#define PCIE_DMA_WRITE_INT_CLEAR_OFF_RSVDP_8_SHIFT (8U)
/*! RSVDP_8 - Reserved for future use. */
#define PCIE_DMA_WRITE_INT_CLEAR_OFF_RSVDP_8(x)  (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_INT_CLEAR_OFF_RSVDP_8_SHIFT)) & PCIE_DMA_WRITE_INT_CLEAR_OFF_RSVDP_8_MASK)

#define PCIE_DMA_WRITE_INT_CLEAR_OFF_WR_ABORT_INT_CLEAR_MASK (0x10000U)
#define PCIE_DMA_WRITE_INT_CLEAR_OFF_WR_ABORT_INT_CLEAR_SHIFT (16U)
/*! WR_ABORT_INT_CLEAR - Abort Interrupt Clear. You must write a 1'b1 to clear the corresponding bit
 *    in the Abort interrupt status field of the DMA write interrupt status register. Each bit
 *    corresponds to a DMA channel. Bit [0] corresponds to channel 0. Note: Reading from this
 *    self-clearing register field always returns a "0".
 */
#define PCIE_DMA_WRITE_INT_CLEAR_OFF_WR_ABORT_INT_CLEAR(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_INT_CLEAR_OFF_WR_ABORT_INT_CLEAR_SHIFT)) & PCIE_DMA_WRITE_INT_CLEAR_OFF_WR_ABORT_INT_CLEAR_MASK)

#define PCIE_DMA_WRITE_INT_CLEAR_OFF_RSVDP_24_MASK (0xFF000000U)
#define PCIE_DMA_WRITE_INT_CLEAR_OFF_RSVDP_24_SHIFT (24U)
/*! RSVDP_24 - Reserved for future use. */
#define PCIE_DMA_WRITE_INT_CLEAR_OFF_RSVDP_24(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_INT_CLEAR_OFF_RSVDP_24_SHIFT)) & PCIE_DMA_WRITE_INT_CLEAR_OFF_RSVDP_24_MASK)
/*! @} */

/*! @name DMA_WRITE_ERR_STATUS_OFF - DMA Write Error Status Register */
/*! @{ */

#define PCIE_DMA_WRITE_ERR_STATUS_OFF_APP_READ_ERR_DETECT_MASK (0xFFU)
#define PCIE_DMA_WRITE_ERR_STATUS_OFF_APP_READ_ERR_DETECT_SHIFT (0U)
/*! APP_READ_ERR_DETECT - Application Read Error Detected. The DMA write channel has received an
 *    error response from the AXI bus (or TRGT1 interface when the AXI Bridge is not used) while
 *    reading data from it. Each bit corresponds to a DMA channel. Bit [0] corresponds to channel 0. -
 *    Enabling: For details, see "Interrupts and Error Handling". - Masking: The DMA write interrupt
 *    Mask register has no effect on this register. - Clearing: You must write a 1'b1 to the
 *    corresponding channel bit in the Abort interrupt field of the "DMA Write Interrupt Clear Register"
 *    (DMA_WRITE_INT_CLEAR_OFF) to clear this error bit.
 */
#define PCIE_DMA_WRITE_ERR_STATUS_OFF_APP_READ_ERR_DETECT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_ERR_STATUS_OFF_APP_READ_ERR_DETECT_SHIFT)) & PCIE_DMA_WRITE_ERR_STATUS_OFF_APP_READ_ERR_DETECT_MASK)

#define PCIE_DMA_WRITE_ERR_STATUS_OFF_RSVDP_8_MASK (0xFF00U)
#define PCIE_DMA_WRITE_ERR_STATUS_OFF_RSVDP_8_SHIFT (8U)
/*! RSVDP_8 - Reserved for future use. */
#define PCIE_DMA_WRITE_ERR_STATUS_OFF_RSVDP_8(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_ERR_STATUS_OFF_RSVDP_8_SHIFT)) & PCIE_DMA_WRITE_ERR_STATUS_OFF_RSVDP_8_MASK)

#define PCIE_DMA_WRITE_ERR_STATUS_OFF_LINKLIST_ELEMENT_FETCH_ERR_DETECT_MASK (0xFF0000U)
#define PCIE_DMA_WRITE_ERR_STATUS_OFF_LINKLIST_ELEMENT_FETCH_ERR_DETECT_SHIFT (16U)
/*! LINKLIST_ELEMENT_FETCH_ERR_DETECT - Linked List Element Fetch Error Detected. The DMA write
 *    channel has received an error response from the AXI bus (or TRGT1 interface when the AXI Bridge is
 *    not used) while reading a linked list element from local memory. Each bit corresponds to a
 *    DMA channel. Bit [0] corresponds to channel 0. - Enabling: For details, see "Interrupts and
 *    Error Handling". - Masking: The DMA write interrupt Mask register has no effect on this register.
 *    - Clearing: You must write a 1'b1 to the corresponding channel bit in the Abort interrupt
 *    field of the "DMA Write Interrupt Clear Register" (DMA_WRITE_INT_CLEAR_OFF) to clear this error
 *    bit.
 */
#define PCIE_DMA_WRITE_ERR_STATUS_OFF_LINKLIST_ELEMENT_FETCH_ERR_DETECT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_ERR_STATUS_OFF_LINKLIST_ELEMENT_FETCH_ERR_DETECT_SHIFT)) & PCIE_DMA_WRITE_ERR_STATUS_OFF_LINKLIST_ELEMENT_FETCH_ERR_DETECT_MASK)

#define PCIE_DMA_WRITE_ERR_STATUS_OFF_RSVDP_24_MASK (0xFF000000U)
#define PCIE_DMA_WRITE_ERR_STATUS_OFF_RSVDP_24_SHIFT (24U)
/*! RSVDP_24 - Reserved for future use. */
#define PCIE_DMA_WRITE_ERR_STATUS_OFF_RSVDP_24(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_ERR_STATUS_OFF_RSVDP_24_SHIFT)) & PCIE_DMA_WRITE_ERR_STATUS_OFF_RSVDP_24_MASK)
/*! @} */

/*! @name DMA_WRITE_DONE_IMWR_LOW_OFF - DMA Write Done IMWr Address Low Register. */
/*! @{ */

#define PCIE_DMA_WRITE_DONE_IMWR_LOW_OFF_DMA_WRITE_DONE_LOW_REG_MASK (0xFFFFFFFFU)
#define PCIE_DMA_WRITE_DONE_IMWR_LOW_OFF_DMA_WRITE_DONE_LOW_REG_SHIFT (0U)
/*! DMA_WRITE_DONE_LOW_REG - The DMA uses this field to generate bits [31:0] of the address field
 *    for the Done IMWr TLP. Bits [1:0] must be "00" as this address must be dword aligned. Note: The
 *    access attributes of this field are as follows: - Dbi: R/W
 */
#define PCIE_DMA_WRITE_DONE_IMWR_LOW_OFF_DMA_WRITE_DONE_LOW_REG(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_DONE_IMWR_LOW_OFF_DMA_WRITE_DONE_LOW_REG_SHIFT)) & PCIE_DMA_WRITE_DONE_IMWR_LOW_OFF_DMA_WRITE_DONE_LOW_REG_MASK)
/*! @} */

/*! @name DMA_WRITE_DONE_IMWR_HIGH_OFF - DMA Write Done IMWr Interrupt Address High Register. */
/*! @{ */

#define PCIE_DMA_WRITE_DONE_IMWR_HIGH_OFF_DMA_WRITE_DONE_HIGH_REG_MASK (0xFFFFFFFFU)
#define PCIE_DMA_WRITE_DONE_IMWR_HIGH_OFF_DMA_WRITE_DONE_HIGH_REG_SHIFT (0U)
/*! DMA_WRITE_DONE_HIGH_REG - The DMA uses this field to generate bits [63:32] of the address field
 *    for the Done IMWr TLP. Note: The access attributes of this field are as follows: - Dbi: R/W
 */
#define PCIE_DMA_WRITE_DONE_IMWR_HIGH_OFF_DMA_WRITE_DONE_HIGH_REG(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_DONE_IMWR_HIGH_OFF_DMA_WRITE_DONE_HIGH_REG_SHIFT)) & PCIE_DMA_WRITE_DONE_IMWR_HIGH_OFF_DMA_WRITE_DONE_HIGH_REG_MASK)
/*! @} */

/*! @name DMA_WRITE_ABORT_IMWR_LOW_OFF - DMA Write Abort IMWr Address Low Register. */
/*! @{ */

#define PCIE_DMA_WRITE_ABORT_IMWR_LOW_OFF_DMA_WRITE_ABORT_LOW_REG_MASK (0xFFFFFFFFU)
#define PCIE_DMA_WRITE_ABORT_IMWR_LOW_OFF_DMA_WRITE_ABORT_LOW_REG_SHIFT (0U)
/*! DMA_WRITE_ABORT_LOW_REG - The DMA uses this field to generate bits [31:0] of the address field
 *    for the Abort IMWr TLP it generates. Bits [1:0] must be "00" as this address must be dword
 *    aligned. Note: The access attributes of this field are as follows: - Dbi: R/W
 */
#define PCIE_DMA_WRITE_ABORT_IMWR_LOW_OFF_DMA_WRITE_ABORT_LOW_REG(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_ABORT_IMWR_LOW_OFF_DMA_WRITE_ABORT_LOW_REG_SHIFT)) & PCIE_DMA_WRITE_ABORT_IMWR_LOW_OFF_DMA_WRITE_ABORT_LOW_REG_MASK)
/*! @} */

/*! @name DMA_WRITE_ABORT_IMWR_HIGH_OFF - DMA Write Abort IMWr Address High Register. */
/*! @{ */

#define PCIE_DMA_WRITE_ABORT_IMWR_HIGH_OFF_DMA_WRITE_ABORT_HIGH_REG_MASK (0xFFFFFFFFU)
#define PCIE_DMA_WRITE_ABORT_IMWR_HIGH_OFF_DMA_WRITE_ABORT_HIGH_REG_SHIFT (0U)
/*! DMA_WRITE_ABORT_HIGH_REG - The DMA uses this field to generate bits [63:32] of the address field
 *    for the Abort IMWr TLP. Note: The access attributes of this field are as follows: - Dbi: R/W
 */
#define PCIE_DMA_WRITE_ABORT_IMWR_HIGH_OFF_DMA_WRITE_ABORT_HIGH_REG(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_ABORT_IMWR_HIGH_OFF_DMA_WRITE_ABORT_HIGH_REG_SHIFT)) & PCIE_DMA_WRITE_ABORT_IMWR_HIGH_OFF_DMA_WRITE_ABORT_HIGH_REG_MASK)
/*! @} */

/*! @name DMA_WRITE_CH01_IMWR_DATA_OFF - DMA Write Channel 1 and 0 IMWr Data Register. */
/*! @{ */

#define PCIE_DMA_WRITE_CH01_IMWR_DATA_OFF_WR_CHANNEL_0_DATA_MASK (0xFFFFU)
#define PCIE_DMA_WRITE_CH01_IMWR_DATA_OFF_WR_CHANNEL_0_DATA_SHIFT (0U)
/*! WR_CHANNEL_0_DATA - The DMA uses this field to generate the data field for the Done or Abort
 *    IMWr TLPs it generates for write channel 0. Note: The access attributes of this field are as
 *    follows: - Dbi: R/W
 */
#define PCIE_DMA_WRITE_CH01_IMWR_DATA_OFF_WR_CHANNEL_0_DATA(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_CH01_IMWR_DATA_OFF_WR_CHANNEL_0_DATA_SHIFT)) & PCIE_DMA_WRITE_CH01_IMWR_DATA_OFF_WR_CHANNEL_0_DATA_MASK)

#define PCIE_DMA_WRITE_CH01_IMWR_DATA_OFF_WR_CHANNEL_1_DATA_MASK (0xFFFF0000U)
#define PCIE_DMA_WRITE_CH01_IMWR_DATA_OFF_WR_CHANNEL_1_DATA_SHIFT (16U)
/*! WR_CHANNEL_1_DATA - The DMA uses this field to generate the data field for the Done or Abort
 *    IMWr TLPs it generates for write channel 1. Note: The access attributes of this field are as
 *    follows: - Dbi: R/W
 */
#define PCIE_DMA_WRITE_CH01_IMWR_DATA_OFF_WR_CHANNEL_1_DATA(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_CH01_IMWR_DATA_OFF_WR_CHANNEL_1_DATA_SHIFT)) & PCIE_DMA_WRITE_CH01_IMWR_DATA_OFF_WR_CHANNEL_1_DATA_MASK)
/*! @} */

/*! @name DMA_WRITE_CH23_IMWR_DATA_OFF - DMA Write Channel 3 and 2 IMWr Data Register. */
/*! @{ */

#define PCIE_DMA_WRITE_CH23_IMWR_DATA_OFF_WR_CHANNEL_2_DATA_MASK (0xFFFFU)
#define PCIE_DMA_WRITE_CH23_IMWR_DATA_OFF_WR_CHANNEL_2_DATA_SHIFT (0U)
/*! WR_CHANNEL_2_DATA - The DMA uses this field to generate the data field for the Done or Abort
 *    IMWr TLPs it generates for write channel 2. Note: The access attributes of this field are as
 *    follows: - Dbi: R/W
 */
#define PCIE_DMA_WRITE_CH23_IMWR_DATA_OFF_WR_CHANNEL_2_DATA(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_CH23_IMWR_DATA_OFF_WR_CHANNEL_2_DATA_SHIFT)) & PCIE_DMA_WRITE_CH23_IMWR_DATA_OFF_WR_CHANNEL_2_DATA_MASK)

#define PCIE_DMA_WRITE_CH23_IMWR_DATA_OFF_WR_CHANNEL_3_DATA_MASK (0xFFFF0000U)
#define PCIE_DMA_WRITE_CH23_IMWR_DATA_OFF_WR_CHANNEL_3_DATA_SHIFT (16U)
/*! WR_CHANNEL_3_DATA - The DMA uses this field to generate the data field for the Done or Abort
 *    IMWr TLPs it generates for write channel 3. Note: The access attributes of this field are as
 *    follows: - Dbi: R/W
 */
#define PCIE_DMA_WRITE_CH23_IMWR_DATA_OFF_WR_CHANNEL_3_DATA(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_CH23_IMWR_DATA_OFF_WR_CHANNEL_3_DATA_SHIFT)) & PCIE_DMA_WRITE_CH23_IMWR_DATA_OFF_WR_CHANNEL_3_DATA_MASK)
/*! @} */

/*! @name DMA_WRITE_CH45_IMWR_DATA_OFF - DMA Write Channel 5 and 4 IMWr Data Register. */
/*! @{ */

#define PCIE_DMA_WRITE_CH45_IMWR_DATA_OFF_WR_CHANNEL_4_DATA_MASK (0xFFFFU)
#define PCIE_DMA_WRITE_CH45_IMWR_DATA_OFF_WR_CHANNEL_4_DATA_SHIFT (0U)
/*! WR_CHANNEL_4_DATA - The DMA uses this field to generate the data field for the Done or Abort
 *    IMWr TLPs it generates for write channel 4. Note: The access attributes of this field are as
 *    follows: - Dbi: R/W
 */
#define PCIE_DMA_WRITE_CH45_IMWR_DATA_OFF_WR_CHANNEL_4_DATA(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_CH45_IMWR_DATA_OFF_WR_CHANNEL_4_DATA_SHIFT)) & PCIE_DMA_WRITE_CH45_IMWR_DATA_OFF_WR_CHANNEL_4_DATA_MASK)

#define PCIE_DMA_WRITE_CH45_IMWR_DATA_OFF_WR_CHANNEL_5_DATA_MASK (0xFFFF0000U)
#define PCIE_DMA_WRITE_CH45_IMWR_DATA_OFF_WR_CHANNEL_5_DATA_SHIFT (16U)
/*! WR_CHANNEL_5_DATA - The DMA uses this field to generate the data field for the Done or Abort
 *    IMWr TLPs it generates for write channel 5. Note: The access attributes of this field are as
 *    follows: - Dbi: R/W
 */
#define PCIE_DMA_WRITE_CH45_IMWR_DATA_OFF_WR_CHANNEL_5_DATA(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_CH45_IMWR_DATA_OFF_WR_CHANNEL_5_DATA_SHIFT)) & PCIE_DMA_WRITE_CH45_IMWR_DATA_OFF_WR_CHANNEL_5_DATA_MASK)
/*! @} */

/*! @name DMA_WRITE_CH67_IMWR_DATA_OFF - DMA Write Channel 7 and 6 IMWr Data Register. */
/*! @{ */

#define PCIE_DMA_WRITE_CH67_IMWR_DATA_OFF_WR_CHANNEL_6_DATA_MASK (0xFFFFU)
#define PCIE_DMA_WRITE_CH67_IMWR_DATA_OFF_WR_CHANNEL_6_DATA_SHIFT (0U)
/*! WR_CHANNEL_6_DATA - The DMA uses this field to generate the data field for the Done or Abort
 *    IMWr TLPs it generates for write channel 6. Note: The access attributes of this field are as
 *    follows: - Dbi: R/W
 */
#define PCIE_DMA_WRITE_CH67_IMWR_DATA_OFF_WR_CHANNEL_6_DATA(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_CH67_IMWR_DATA_OFF_WR_CHANNEL_6_DATA_SHIFT)) & PCIE_DMA_WRITE_CH67_IMWR_DATA_OFF_WR_CHANNEL_6_DATA_MASK)

#define PCIE_DMA_WRITE_CH67_IMWR_DATA_OFF_WR_CHANNEL_7_DATA_MASK (0xFFFF0000U)
#define PCIE_DMA_WRITE_CH67_IMWR_DATA_OFF_WR_CHANNEL_7_DATA_SHIFT (16U)
/*! WR_CHANNEL_7_DATA - The DMA uses this field to generate the data field for the Done or Abort
 *    IMWr TLPs it generates for write channel 7. Note: The access attributes of this field are as
 *    follows: - Dbi: R/W
 */
#define PCIE_DMA_WRITE_CH67_IMWR_DATA_OFF_WR_CHANNEL_7_DATA(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_CH67_IMWR_DATA_OFF_WR_CHANNEL_7_DATA_SHIFT)) & PCIE_DMA_WRITE_CH67_IMWR_DATA_OFF_WR_CHANNEL_7_DATA_MASK)
/*! @} */

/*! @name DMA_WRITE_LINKED_LIST_ERR_EN_OFF - DMA Write Linked List Error Enable Register. */
/*! @{ */

#define PCIE_DMA_WRITE_LINKED_LIST_ERR_EN_OFF_WR_CHANNEL_LLRAIE_MASK (0x1U)
#define PCIE_DMA_WRITE_LINKED_LIST_ERR_EN_OFF_WR_CHANNEL_LLRAIE_SHIFT (0U)
/*! WR_CHANNEL_LLRAIE - Write Channel LL Remote Abort Interrupt Enable (LLRAIE). You enable the
 *    write channel remote abort interrupt through this bit. The LIE and RIE bits in the LL element
 *    enable the write channel done interrupts. Each bit corresponds to a DMA channel. Bit [0]
 *    corresponds to channel 0. Used in linked list mode only. For more details, see "Interrupt Handling".
 *    Note: The access attributes of this field are as follows: - Dbi: R/W
 */
#define PCIE_DMA_WRITE_LINKED_LIST_ERR_EN_OFF_WR_CHANNEL_LLRAIE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_LINKED_LIST_ERR_EN_OFF_WR_CHANNEL_LLRAIE_SHIFT)) & PCIE_DMA_WRITE_LINKED_LIST_ERR_EN_OFF_WR_CHANNEL_LLRAIE_MASK)

#define PCIE_DMA_WRITE_LINKED_LIST_ERR_EN_OFF_RSVDP_8_MASK (0xFF00U)
#define PCIE_DMA_WRITE_LINKED_LIST_ERR_EN_OFF_RSVDP_8_SHIFT (8U)
/*! RSVDP_8 - Reserved for future use. */
#define PCIE_DMA_WRITE_LINKED_LIST_ERR_EN_OFF_RSVDP_8(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_LINKED_LIST_ERR_EN_OFF_RSVDP_8_SHIFT)) & PCIE_DMA_WRITE_LINKED_LIST_ERR_EN_OFF_RSVDP_8_MASK)

#define PCIE_DMA_WRITE_LINKED_LIST_ERR_EN_OFF_WR_CHANNEL_LLLAIE_MASK (0x10000U)
#define PCIE_DMA_WRITE_LINKED_LIST_ERR_EN_OFF_WR_CHANNEL_LLLAIE_SHIFT (16U)
/*! WR_CHANNEL_LLLAIE - Write Channel LL Local Abort Interrupt Enable (LLLAIE). You enable the write
 *    channel local abort interrupt through this bit. The LIE and RIE bits in the LL element enable
 *    the write channel done interrupts. Each bit corresponds to a DMA channel. Bit [0] corresponds
 *    to channel 0. Used in linked list mode only. For more details, see "Interrupt Handling".
 *    Note: The access attributes of this field are as follows: - Dbi: R/W
 */
#define PCIE_DMA_WRITE_LINKED_LIST_ERR_EN_OFF_WR_CHANNEL_LLLAIE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_LINKED_LIST_ERR_EN_OFF_WR_CHANNEL_LLLAIE_SHIFT)) & PCIE_DMA_WRITE_LINKED_LIST_ERR_EN_OFF_WR_CHANNEL_LLLAIE_MASK)

#define PCIE_DMA_WRITE_LINKED_LIST_ERR_EN_OFF_RSVDP_24_MASK (0xFF000000U)
#define PCIE_DMA_WRITE_LINKED_LIST_ERR_EN_OFF_RSVDP_24_SHIFT (24U)
/*! RSVDP_24 - Reserved for future use. */
#define PCIE_DMA_WRITE_LINKED_LIST_ERR_EN_OFF_RSVDP_24(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_WRITE_LINKED_LIST_ERR_EN_OFF_RSVDP_24_SHIFT)) & PCIE_DMA_WRITE_LINKED_LIST_ERR_EN_OFF_RSVDP_24_MASK)
/*! @} */

/*! @name DMA_READ_INT_STATUS_OFF - DMA Read Interrupt Status Register. */
/*! @{ */

#define PCIE_DMA_READ_INT_STATUS_OFF_RD_DONE_INT_STATUS_MASK (0xFFU)
#define PCIE_DMA_READ_INT_STATUS_OFF_RD_DONE_INT_STATUS_SHIFT (0U)
/*! RD_DONE_INT_STATUS - Done Interrupt Status. The DMA read channel has successfully completed the
 *    DMA read transfer. Each bit corresponds to a DMA channel. Bit [0] corresponds to channel 0. -
 *    Enabling: For details, see "Interrupts and Error Handling". - Masking: The DMA read interrupt
 *    Mask register has no effect on this register. - Clearing: You must write a 1'b1 to the
 *    corresponding channel bit in the DMA read interrupt Clear register to clear this interrupt bit. Note:
 *    You can write to this register to emulate interrupt generation, during software or hardware
 *    testing. A write to the address triggers an interrupt, but the DMA does not set the Done or
 *    Abort bits in this register. Note: The access attributes of this field are as follows: - Dbi: R/W
 */
#define PCIE_DMA_READ_INT_STATUS_OFF_RD_DONE_INT_STATUS(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_INT_STATUS_OFF_RD_DONE_INT_STATUS_SHIFT)) & PCIE_DMA_READ_INT_STATUS_OFF_RD_DONE_INT_STATUS_MASK)

#define PCIE_DMA_READ_INT_STATUS_OFF_RSVDP_8_MASK (0xFF00U)
#define PCIE_DMA_READ_INT_STATUS_OFF_RSVDP_8_SHIFT (8U)
/*! RSVDP_8 - Reserved for future use. */
#define PCIE_DMA_READ_INT_STATUS_OFF_RSVDP_8(x)  (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_INT_STATUS_OFF_RSVDP_8_SHIFT)) & PCIE_DMA_READ_INT_STATUS_OFF_RSVDP_8_MASK)

#define PCIE_DMA_READ_INT_STATUS_OFF_RD_ABORT_INT_STATUS_MASK (0xFF0000U)
#define PCIE_DMA_READ_INT_STATUS_OFF_RD_ABORT_INT_STATUS_SHIFT (16U)
/*! RD_ABORT_INT_STATUS - Abort Interrupt Status. The DMA read channel has detected an error, or you
 *    manually stopped the transfer as described in "Stopping the DMA Transfer (Software Stop)".
 *    Each bit corresponds to a DMA channel. Bit [0] corresponds to channel 0. You can read the "DMA
 *    Read Error Status Low Register" (DMA_READ_ERR_STATUS_LOW_OFF) and "DMA Read Error Status High
 *    Register" (DMA_READ_ERR_STATUS_HIGH_OFF) to determine the source of the error. - Enabling: For
 *    details, see "Interrupts and Error Handling". - Masking: The DMA read interrupt Mask register
 *    has no effect on this register. - Clearing: You must write a 1'b1 to the corresponding channel
 *    bit in the DMA read interrupt Clear register to clear this interrupt bit. Note: You can write
 *    to this register to emulate interrupt generation, during software or hardware testing. A
 *    write to the address triggers an interrupt, but the DMA does not set the Done or Abort bits in
 *    this register. Note: The access attributes of this field are as follows: - Dbi: R/W
 */
#define PCIE_DMA_READ_INT_STATUS_OFF_RD_ABORT_INT_STATUS(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_INT_STATUS_OFF_RD_ABORT_INT_STATUS_SHIFT)) & PCIE_DMA_READ_INT_STATUS_OFF_RD_ABORT_INT_STATUS_MASK)

#define PCIE_DMA_READ_INT_STATUS_OFF_RSVDP_24_MASK (0xFF000000U)
#define PCIE_DMA_READ_INT_STATUS_OFF_RSVDP_24_SHIFT (24U)
/*! RSVDP_24 - Reserved for future use. */
#define PCIE_DMA_READ_INT_STATUS_OFF_RSVDP_24(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_INT_STATUS_OFF_RSVDP_24_SHIFT)) & PCIE_DMA_READ_INT_STATUS_OFF_RSVDP_24_MASK)
/*! @} */

/*! @name DMA_READ_INT_MASK_OFF - DMA Read Interrupt Mask Register. */
/*! @{ */

#define PCIE_DMA_READ_INT_MASK_OFF_RD_DONE_INT_MASK_MASK (0x1U)
#define PCIE_DMA_READ_INT_MASK_OFF_RD_DONE_INT_MASK_SHIFT (0U)
/*! RD_DONE_INT_MASK - Done Interrupt Mask. Prevents the Done interrupt status field in the DMA read
 *    interrupt status register from asserting the edma_int output. Each bit corresponds to a DMA
 *    channel. Bit [0] corresponds to channel 0. Note: The access attributes of this field are as
 *    follows: - Dbi: R/W
 */
#define PCIE_DMA_READ_INT_MASK_OFF_RD_DONE_INT_MASK(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_INT_MASK_OFF_RD_DONE_INT_MASK_SHIFT)) & PCIE_DMA_READ_INT_MASK_OFF_RD_DONE_INT_MASK_MASK)

#define PCIE_DMA_READ_INT_MASK_OFF_RSVDP_8_MASK  (0xFF00U)
#define PCIE_DMA_READ_INT_MASK_OFF_RSVDP_8_SHIFT (8U)
/*! RSVDP_8 - Reserved for future use. */
#define PCIE_DMA_READ_INT_MASK_OFF_RSVDP_8(x)    (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_INT_MASK_OFF_RSVDP_8_SHIFT)) & PCIE_DMA_READ_INT_MASK_OFF_RSVDP_8_MASK)

#define PCIE_DMA_READ_INT_MASK_OFF_RD_ABORT_INT_MASK_MASK (0x10000U)
#define PCIE_DMA_READ_INT_MASK_OFF_RD_ABORT_INT_MASK_SHIFT (16U)
/*! RD_ABORT_INT_MASK - Abort Interrupt Mask. Prevents the Abort interrupt status field in the DMA
 *    read interrupt status register from asserting the edma_int output. Each bit corresponds to a
 *    DMA channel. Bit [0] corresponds to channel 0. Note: The access attributes of this field are as
 *    follows: - Dbi: R/W
 */
#define PCIE_DMA_READ_INT_MASK_OFF_RD_ABORT_INT_MASK(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_INT_MASK_OFF_RD_ABORT_INT_MASK_SHIFT)) & PCIE_DMA_READ_INT_MASK_OFF_RD_ABORT_INT_MASK_MASK)

#define PCIE_DMA_READ_INT_MASK_OFF_RSVDP_24_MASK (0xFF000000U)
#define PCIE_DMA_READ_INT_MASK_OFF_RSVDP_24_SHIFT (24U)
/*! RSVDP_24 - Reserved for future use. */
#define PCIE_DMA_READ_INT_MASK_OFF_RSVDP_24(x)   (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_INT_MASK_OFF_RSVDP_24_SHIFT)) & PCIE_DMA_READ_INT_MASK_OFF_RSVDP_24_MASK)
/*! @} */

/*! @name DMA_READ_INT_CLEAR_OFF - DMA Read Interrupt Clear Register. */
/*! @{ */

#define PCIE_DMA_READ_INT_CLEAR_OFF_RD_DONE_INT_CLEAR_MASK (0xFFU)
#define PCIE_DMA_READ_INT_CLEAR_OFF_RD_DONE_INT_CLEAR_SHIFT (0U)
/*! RD_DONE_INT_CLEAR - Done Interrupt Clear. You must write a 1'b1 to clear the corresponding bit
 *    in the Done interrupt status field of the DMA read interrupt status register. Each bit
 *    corresponds to a DMA channel. Bit [0] corresponds to channel 0. Note: Reading from this self-clearing
 *    register field always returns a "0".
 */
#define PCIE_DMA_READ_INT_CLEAR_OFF_RD_DONE_INT_CLEAR(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_INT_CLEAR_OFF_RD_DONE_INT_CLEAR_SHIFT)) & PCIE_DMA_READ_INT_CLEAR_OFF_RD_DONE_INT_CLEAR_MASK)

#define PCIE_DMA_READ_INT_CLEAR_OFF_RSVDP_8_MASK (0xFF00U)
#define PCIE_DMA_READ_INT_CLEAR_OFF_RSVDP_8_SHIFT (8U)
/*! RSVDP_8 - Reserved for future use. */
#define PCIE_DMA_READ_INT_CLEAR_OFF_RSVDP_8(x)   (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_INT_CLEAR_OFF_RSVDP_8_SHIFT)) & PCIE_DMA_READ_INT_CLEAR_OFF_RSVDP_8_MASK)

#define PCIE_DMA_READ_INT_CLEAR_OFF_RD_ABORT_INT_CLEAR_MASK (0xFF0000U)
#define PCIE_DMA_READ_INT_CLEAR_OFF_RD_ABORT_INT_CLEAR_SHIFT (16U)
/*! RD_ABORT_INT_CLEAR - Abort Interrupt Clear. You must write a 1'b1 to clear the corresponding bit
 *    in the Abort interrupt status field of the DMA read interrupt status register. Each bit
 *    corresponds to a DMA channel. Bit [0] corresponds to channel 0. Note: Reading from this
 *    self-clearing register field always returns a "0".
 */
#define PCIE_DMA_READ_INT_CLEAR_OFF_RD_ABORT_INT_CLEAR(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_INT_CLEAR_OFF_RD_ABORT_INT_CLEAR_SHIFT)) & PCIE_DMA_READ_INT_CLEAR_OFF_RD_ABORT_INT_CLEAR_MASK)

#define PCIE_DMA_READ_INT_CLEAR_OFF_RSVDP_24_MASK (0xFF000000U)
#define PCIE_DMA_READ_INT_CLEAR_OFF_RSVDP_24_SHIFT (24U)
/*! RSVDP_24 - Reserved for future use. */
#define PCIE_DMA_READ_INT_CLEAR_OFF_RSVDP_24(x)  (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_INT_CLEAR_OFF_RSVDP_24_SHIFT)) & PCIE_DMA_READ_INT_CLEAR_OFF_RSVDP_24_MASK)
/*! @} */

/*! @name DMA_READ_ERR_STATUS_LOW_OFF - DMA Read Error Status Low Register. */
/*! @{ */

#define PCIE_DMA_READ_ERR_STATUS_LOW_OFF_APP_WR_ERR_DETECT_MASK (0xFFU)
#define PCIE_DMA_READ_ERR_STATUS_LOW_OFF_APP_WR_ERR_DETECT_SHIFT (0U)
/*! APP_WR_ERR_DETECT - Application Write Error Detected. The DMA read channel has received an error
 *    response from the AXI bus (or TRGT1 interface when the AXI Bridge is not used) while writing
 *    data to it. This error is fatal. You must restart the transfer from the beginning, as the
 *    channel context is corrupted, and the transfer is not rolled back. For more details, see "Linked
 *    List Mode". Each bit corresponds to a DMA channel. Bit [0] corresponds to channel 0. -
 *    Enabling: For details, see "Interrupts and Error Handling". - Masking: The DMA read interrupt Mask
 *    register has no effect on this register. - Clearing: You must write a 1'b1 to the corresponding
 *    channel bit in the Abort interrupt field of the "DMA Read Interrupt Clear Register"
 *    (DMA_READ_INT_CLEAR_OFF) to clear this error bit. Note, this clears all bits in this register, and also
 *    the DMA Read Error Status High register (DMA_READ_ERR_STATUS_HIGH_OFF).
 */
#define PCIE_DMA_READ_ERR_STATUS_LOW_OFF_APP_WR_ERR_DETECT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_ERR_STATUS_LOW_OFF_APP_WR_ERR_DETECT_SHIFT)) & PCIE_DMA_READ_ERR_STATUS_LOW_OFF_APP_WR_ERR_DETECT_MASK)

#define PCIE_DMA_READ_ERR_STATUS_LOW_OFF_RSVDP_8_MASK (0xFF00U)
#define PCIE_DMA_READ_ERR_STATUS_LOW_OFF_RSVDP_8_SHIFT (8U)
/*! RSVDP_8 - Reserved for future use. */
#define PCIE_DMA_READ_ERR_STATUS_LOW_OFF_RSVDP_8(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_ERR_STATUS_LOW_OFF_RSVDP_8_SHIFT)) & PCIE_DMA_READ_ERR_STATUS_LOW_OFF_RSVDP_8_MASK)

#define PCIE_DMA_READ_ERR_STATUS_LOW_OFF_LINK_LIST_ELEMENT_FETCH_ERR_DETECT_MASK (0xFF0000U)
#define PCIE_DMA_READ_ERR_STATUS_LOW_OFF_LINK_LIST_ELEMENT_FETCH_ERR_DETECT_SHIFT (16U)
/*! LINK_LIST_ELEMENT_FETCH_ERR_DETECT - Linked List Element Fetch Error Detected. - The DMA read
 *    channel has received an error response from the AXI bus while reading a linked list element from
 *    local memory. Each bit corresponds to a DMA channel. Bit [0] corresponds to channel 0. -
 *    Enabling: For details, see "Interrupts and Error Handling". - Masking: The DMA read interrupt Mask
 *    register has no effect on this register. - Clearing: You must write a 1'b1 to the
 *    corresponding channel bit in the Abort interrupt field of the "DMA Read Interrupt Clear Register"
 *    (DMA_READ_INT_CLEAR_OFF) to clear this error bit. Note, this clears all bits in this register, and
 *    also the DMA Read Error Status High register (DMA_READ_ERR_STATUS_HIGH_OFF).
 */
#define PCIE_DMA_READ_ERR_STATUS_LOW_OFF_LINK_LIST_ELEMENT_FETCH_ERR_DETECT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_ERR_STATUS_LOW_OFF_LINK_LIST_ELEMENT_FETCH_ERR_DETECT_SHIFT)) & PCIE_DMA_READ_ERR_STATUS_LOW_OFF_LINK_LIST_ELEMENT_FETCH_ERR_DETECT_MASK)

#define PCIE_DMA_READ_ERR_STATUS_LOW_OFF_RSVDP_24_MASK (0xFF000000U)
#define PCIE_DMA_READ_ERR_STATUS_LOW_OFF_RSVDP_24_SHIFT (24U)
/*! RSVDP_24 - Reserved for future use. */
#define PCIE_DMA_READ_ERR_STATUS_LOW_OFF_RSVDP_24(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_ERR_STATUS_LOW_OFF_RSVDP_24_SHIFT)) & PCIE_DMA_READ_ERR_STATUS_LOW_OFF_RSVDP_24_MASK)
/*! @} */

/*! @name DMA_READ_ERR_STATUS_HIGH_OFF - DMA Read Error Status High Register. */
/*! @{ */

#define PCIE_DMA_READ_ERR_STATUS_HIGH_OFF_UNSUPPORTED_REQ_MASK (0xFFU)
#define PCIE_DMA_READ_ERR_STATUS_HIGH_OFF_UNSUPPORTED_REQ_SHIFT (0U)
/*! UNSUPPORTED_REQ - Unsupported Request. The DMA read channel has received a PCIe unsupported
 *    request completion status from the remote device in response to the MRd request. For more details,
 *    see "Linked List Mode". Each bit corresponds to a DMA channel. Bit [0] corresponds to channel
 *    0. - Enabling: For details, see "Interrupts and Error Handling". - Masking: The DMA read
 *    interrupt Mask register has no effect on this register. - Clearing: You must write a 1'b1 to the
 *    corresponding channel bit in the Abort interrupt field of the "DMA Read Interrupt Clear
 *    Register" (DMA_READ_INT_CLEAR_OFF) to clear this error bit. Note, this also clears the other error
 *    bits for the same channel in this register and in the DMA Read Error Status Low register.
 */
#define PCIE_DMA_READ_ERR_STATUS_HIGH_OFF_UNSUPPORTED_REQ(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_ERR_STATUS_HIGH_OFF_UNSUPPORTED_REQ_SHIFT)) & PCIE_DMA_READ_ERR_STATUS_HIGH_OFF_UNSUPPORTED_REQ_MASK)

#define PCIE_DMA_READ_ERR_STATUS_HIGH_OFF_CPL_ABORT_MASK (0xFF00U)
#define PCIE_DMA_READ_ERR_STATUS_HIGH_OFF_CPL_ABORT_SHIFT (8U)
/*! CPL_ABORT - Completer Abort. The DMA read channel has received a PCIe completer abort completion
 *    status from the remote device in response to the MRd request. For more details, see "Linked
 *    List Mode". Each bit corresponds to a DMA channel. Bit [0] corresponds to channel 0. -
 *    Enabling: For details, see "Interrupts and Error Handling". - Masking: The DMA read interrupt Mask
 *    register has no effect on this register. - Clearing: You must write a 1'b1 to the corresponding
 *    channel bit in the Abort interrupt field of the "DMA Read Interrupt Clear Register"
 *    (DMA_READ_INT_CLEAR_OFF) to clear this error bit. Note, this also clears the other error bits for the
 *    same channel in this register and in the DMA Read Error Status Low register.
 */
#define PCIE_DMA_READ_ERR_STATUS_HIGH_OFF_CPL_ABORT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_ERR_STATUS_HIGH_OFF_CPL_ABORT_SHIFT)) & PCIE_DMA_READ_ERR_STATUS_HIGH_OFF_CPL_ABORT_MASK)

#define PCIE_DMA_READ_ERR_STATUS_HIGH_OFF_CPL_TIMEOUT_MASK (0xFF0000U)
#define PCIE_DMA_READ_ERR_STATUS_HIGH_OFF_CPL_TIMEOUT_SHIFT (16U)
/*! CPL_TIMEOUT - Completion Time Out. The DMA read channel has timed-out while waiting for the
 *    remote device to respond to the MRd request, or a malformed CplD has been received. For more
 *    details, see "Linked List Mode". Each bit corresponds to a DMA channel. Bit [0] corresponds to
 *    channel 0. - Enabling: For details, see "Interrupts and Error Handling" . - Masking: The DMA read
 *    interrupt Mask register has no effect on this register. - Clearing: You must write a 1'b1 to
 *    the corresponding channel bit in the Abort interrupt field of the "DMA Read Interrupt Clear
 *    Register" (DMA_READ_INT_CLEAR_OFF) to clear this error bit. Note, this also clears the other
 *    error bits for the same channel in this register and in the DMA Read Error Status Low register.
 */
#define PCIE_DMA_READ_ERR_STATUS_HIGH_OFF_CPL_TIMEOUT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_ERR_STATUS_HIGH_OFF_CPL_TIMEOUT_SHIFT)) & PCIE_DMA_READ_ERR_STATUS_HIGH_OFF_CPL_TIMEOUT_MASK)

#define PCIE_DMA_READ_ERR_STATUS_HIGH_OFF_DATA_POISIONING_MASK (0xFF000000U)
#define PCIE_DMA_READ_ERR_STATUS_HIGH_OFF_DATA_POISIONING_SHIFT (24U)
/*! DATA_POISIONING - Data Poisoning. The DMA read channel has detected data poisoning in the
 *    completion from the remote device (in response to the MRd request). The DMA read channel will drop
 *    the completion and then be halted. The CX_FLT_MASK_UR_POIS filter rule does not affect this
 *    behavior. Each bit corresponds to a DMA channel. Bit [0] corresponds to channel 0. - Enabling:
 *    For details, see "Interrupts and Error Handling". - Masking: The DMA read interrupt Mask
 *    register has no effect on this register. - Clearing: You must write a 1'b1 to the corresponding
 *    channel bit in the Abort interrupt field of the "DMA Read Interrupt Clear Register"
 *    (DMA_READ_INT_CLEAR_OFF) to clear this error bit. Note, this also clears the other error bits for the same
 *    channel in this register and in the DMA Read Error Status Low register.
 */
#define PCIE_DMA_READ_ERR_STATUS_HIGH_OFF_DATA_POISIONING(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_ERR_STATUS_HIGH_OFF_DATA_POISIONING_SHIFT)) & PCIE_DMA_READ_ERR_STATUS_HIGH_OFF_DATA_POISIONING_MASK)
/*! @} */

/*! @name DMA_READ_LINKED_LIST_ERR_EN_OFF - DMA Read Linked List Error Enable Register. */
/*! @{ */

#define PCIE_DMA_READ_LINKED_LIST_ERR_EN_OFF_RD_CHANNEL_LLRAIE_MASK (0x1U)
#define PCIE_DMA_READ_LINKED_LIST_ERR_EN_OFF_RD_CHANNEL_LLRAIE_SHIFT (0U)
/*! RD_CHANNEL_LLRAIE - Read Channel LL Remote Abort Interrupt Enable (LLRAIE). You enable the read
 *    channel Remote Abort interrupt through this bit. The LIE and RIE bits in the LL element enable
 *    the read channel done interrupts. Each bit corresponds to a DMA channel. Bit [0] corresponds
 *    to channel 0. Used in linked list mode only. For more details, see "Interrupt Handling". Note:
 *    The access attributes of this field are as follows: - Dbi: R/W
 */
#define PCIE_DMA_READ_LINKED_LIST_ERR_EN_OFF_RD_CHANNEL_LLRAIE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_LINKED_LIST_ERR_EN_OFF_RD_CHANNEL_LLRAIE_SHIFT)) & PCIE_DMA_READ_LINKED_LIST_ERR_EN_OFF_RD_CHANNEL_LLRAIE_MASK)

#define PCIE_DMA_READ_LINKED_LIST_ERR_EN_OFF_RSVDP_8_MASK (0xFF00U)
#define PCIE_DMA_READ_LINKED_LIST_ERR_EN_OFF_RSVDP_8_SHIFT (8U)
/*! RSVDP_8 - Reserved for future use. */
#define PCIE_DMA_READ_LINKED_LIST_ERR_EN_OFF_RSVDP_8(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_LINKED_LIST_ERR_EN_OFF_RSVDP_8_SHIFT)) & PCIE_DMA_READ_LINKED_LIST_ERR_EN_OFF_RSVDP_8_MASK)

#define PCIE_DMA_READ_LINKED_LIST_ERR_EN_OFF_RD_CHANNEL_LLLAIE_MASK (0x10000U)
#define PCIE_DMA_READ_LINKED_LIST_ERR_EN_OFF_RD_CHANNEL_LLLAIE_SHIFT (16U)
/*! RD_CHANNEL_LLLAIE - Read Channel LL Local Abort Interrupt Enable (LLLAIE). You enable the read
 *    channel Local Abort interrupt through this bit. The LIE and RIE bits in the LL element enable
 *    the read channel done interrupts. Each bit corresponds to a DMA channel. Bit [0] corresponds to
 *    channel 0. Used in linked list mode only. For more details, see "Interrupt Handling". Note:
 *    The access attributes of this field are as follows: - Dbi: R/W
 */
#define PCIE_DMA_READ_LINKED_LIST_ERR_EN_OFF_RD_CHANNEL_LLLAIE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_LINKED_LIST_ERR_EN_OFF_RD_CHANNEL_LLLAIE_SHIFT)) & PCIE_DMA_READ_LINKED_LIST_ERR_EN_OFF_RD_CHANNEL_LLLAIE_MASK)

#define PCIE_DMA_READ_LINKED_LIST_ERR_EN_OFF_RSVDP_24_MASK (0xFF000000U)
#define PCIE_DMA_READ_LINKED_LIST_ERR_EN_OFF_RSVDP_24_SHIFT (24U)
/*! RSVDP_24 - Reserved for future use. */
#define PCIE_DMA_READ_LINKED_LIST_ERR_EN_OFF_RSVDP_24(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_LINKED_LIST_ERR_EN_OFF_RSVDP_24_SHIFT)) & PCIE_DMA_READ_LINKED_LIST_ERR_EN_OFF_RSVDP_24_MASK)
/*! @} */

/*! @name DMA_READ_DONE_IMWR_LOW_OFF - DMA Read Done IMWr Address Low Register. */
/*! @{ */

#define PCIE_DMA_READ_DONE_IMWR_LOW_OFF_DMA_READ_DONE_LOW_REG_MASK (0xFFFFFFFFU)
#define PCIE_DMA_READ_DONE_IMWR_LOW_OFF_DMA_READ_DONE_LOW_REG_SHIFT (0U)
/*! DMA_READ_DONE_LOW_REG - The DMA uses this field to generate bits [31:0] of the address field for
 *    the Done IMWr TLP. Bits [1:0] must be "00" as this address must be dword aligned. Note: The
 *    access attributes of this field are as follows: - Dbi: R/W
 */
#define PCIE_DMA_READ_DONE_IMWR_LOW_OFF_DMA_READ_DONE_LOW_REG(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_DONE_IMWR_LOW_OFF_DMA_READ_DONE_LOW_REG_SHIFT)) & PCIE_DMA_READ_DONE_IMWR_LOW_OFF_DMA_READ_DONE_LOW_REG_MASK)
/*! @} */

/*! @name DMA_READ_DONE_IMWR_HIGH_OFF - DMA Read Done IMWr Address High Register. */
/*! @{ */

#define PCIE_DMA_READ_DONE_IMWR_HIGH_OFF_DMA_READ_DONE_HIGH_REG_MASK (0xFFFFFFFFU)
#define PCIE_DMA_READ_DONE_IMWR_HIGH_OFF_DMA_READ_DONE_HIGH_REG_SHIFT (0U)
/*! DMA_READ_DONE_HIGH_REG - The DMA uses this field to generate bits [63:32] of the address field
 *    for the Done IMWr TLP. Note: The access attributes of this field are as follows: - Dbi: R/W
 */
#define PCIE_DMA_READ_DONE_IMWR_HIGH_OFF_DMA_READ_DONE_HIGH_REG(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_DONE_IMWR_HIGH_OFF_DMA_READ_DONE_HIGH_REG_SHIFT)) & PCIE_DMA_READ_DONE_IMWR_HIGH_OFF_DMA_READ_DONE_HIGH_REG_MASK)
/*! @} */

/*! @name DMA_READ_ABORT_IMWR_LOW_OFF - DMA Read Abort IMWr Address Low Register. */
/*! @{ */

#define PCIE_DMA_READ_ABORT_IMWR_LOW_OFF_DMA_READ_ABORT_LOW_REG_MASK (0xFFFFFFFFU)
#define PCIE_DMA_READ_ABORT_IMWR_LOW_OFF_DMA_READ_ABORT_LOW_REG_SHIFT (0U)
/*! DMA_READ_ABORT_LOW_REG - The DMA uses this field to generate bits [31:0] of the address field
 *    for the Abort IMWr TLP. Bits [1:0] must be "00" as this address must be dword aligned. Note: The
 *    access attributes of this field are as follows: - Dbi: R/W
 */
#define PCIE_DMA_READ_ABORT_IMWR_LOW_OFF_DMA_READ_ABORT_LOW_REG(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_ABORT_IMWR_LOW_OFF_DMA_READ_ABORT_LOW_REG_SHIFT)) & PCIE_DMA_READ_ABORT_IMWR_LOW_OFF_DMA_READ_ABORT_LOW_REG_MASK)
/*! @} */

/*! @name DMA_READ_ABORT_IMWR_HIGH_OFF - DMA Read Abort IMWr Address High Register. */
/*! @{ */

#define PCIE_DMA_READ_ABORT_IMWR_HIGH_OFF_DMA_READ_ABORT_HIGH_REG_MASK (0xFFFFFFFFU)
#define PCIE_DMA_READ_ABORT_IMWR_HIGH_OFF_DMA_READ_ABORT_HIGH_REG_SHIFT (0U)
/*! DMA_READ_ABORT_HIGH_REG - The DMA uses this field to generate bits [63:32] of the address field
 *    for the Abort IMWr TLP. Note: The access attributes of this field are as follows: - Dbi: R/W
 */
#define PCIE_DMA_READ_ABORT_IMWR_HIGH_OFF_DMA_READ_ABORT_HIGH_REG(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_ABORT_IMWR_HIGH_OFF_DMA_READ_ABORT_HIGH_REG_SHIFT)) & PCIE_DMA_READ_ABORT_IMWR_HIGH_OFF_DMA_READ_ABORT_HIGH_REG_MASK)
/*! @} */

/*! @name DMA_READ_CH01_IMWR_DATA_OFF - DMA Read Channel 1 and 0 IMWr Data Register. */
/*! @{ */

#define PCIE_DMA_READ_CH01_IMWR_DATA_OFF_RD_CHANNEL_0_DATA_MASK (0xFFFFU)
#define PCIE_DMA_READ_CH01_IMWR_DATA_OFF_RD_CHANNEL_0_DATA_SHIFT (0U)
/*! RD_CHANNEL_0_DATA - The DMA uses this field to generate the data field for the Done or Abort
 *    IMWr TLPs it generates for read channel 0. Note: The access attributes of this field are as
 *    follows: - Dbi: R/W
 */
#define PCIE_DMA_READ_CH01_IMWR_DATA_OFF_RD_CHANNEL_0_DATA(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_CH01_IMWR_DATA_OFF_RD_CHANNEL_0_DATA_SHIFT)) & PCIE_DMA_READ_CH01_IMWR_DATA_OFF_RD_CHANNEL_0_DATA_MASK)

#define PCIE_DMA_READ_CH01_IMWR_DATA_OFF_RD_CHANNEL_1_DATA_MASK (0xFFFF0000U)
#define PCIE_DMA_READ_CH01_IMWR_DATA_OFF_RD_CHANNEL_1_DATA_SHIFT (16U)
/*! RD_CHANNEL_1_DATA - The DMA uses this field to generate the data field for the Done or Abort
 *    IMWr TLPs it generates for read channel 1. Note: The access attributes of this field are as
 *    follows: - Dbi: R/W
 */
#define PCIE_DMA_READ_CH01_IMWR_DATA_OFF_RD_CHANNEL_1_DATA(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_CH01_IMWR_DATA_OFF_RD_CHANNEL_1_DATA_SHIFT)) & PCIE_DMA_READ_CH01_IMWR_DATA_OFF_RD_CHANNEL_1_DATA_MASK)
/*! @} */

/*! @name DMA_READ_CH23_IMWR_DATA_OFF - DMA Read Channel 3 and 2 IMWr Data Register. */
/*! @{ */

#define PCIE_DMA_READ_CH23_IMWR_DATA_OFF_RD_CHANNEL_2_DATA_MASK (0xFFFFU)
#define PCIE_DMA_READ_CH23_IMWR_DATA_OFF_RD_CHANNEL_2_DATA_SHIFT (0U)
/*! RD_CHANNEL_2_DATA - The DMA uses this field to generate the data field for the Done or Abort
 *    IMWr TLPs it generates for read channel 2. Note: The access attributes of this field are as
 *    follows: - Dbi: R/W
 */
#define PCIE_DMA_READ_CH23_IMWR_DATA_OFF_RD_CHANNEL_2_DATA(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_CH23_IMWR_DATA_OFF_RD_CHANNEL_2_DATA_SHIFT)) & PCIE_DMA_READ_CH23_IMWR_DATA_OFF_RD_CHANNEL_2_DATA_MASK)

#define PCIE_DMA_READ_CH23_IMWR_DATA_OFF_RD_CHANNEL_3_DATA_MASK (0xFFFF0000U)
#define PCIE_DMA_READ_CH23_IMWR_DATA_OFF_RD_CHANNEL_3_DATA_SHIFT (16U)
/*! RD_CHANNEL_3_DATA - The DMA uses this field to generate the data field for the Done or Abort
 *    IMWr TLPs it generates for read channel 3. Note: The access attributes of this field are as
 *    follows: - Dbi: R/W
 */
#define PCIE_DMA_READ_CH23_IMWR_DATA_OFF_RD_CHANNEL_3_DATA(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_CH23_IMWR_DATA_OFF_RD_CHANNEL_3_DATA_SHIFT)) & PCIE_DMA_READ_CH23_IMWR_DATA_OFF_RD_CHANNEL_3_DATA_MASK)
/*! @} */

/*! @name DMA_READ_CH45_IMWR_DATA_OFF - DMA Read Channel 5 and 4 IMWr Data Register. */
/*! @{ */

#define PCIE_DMA_READ_CH45_IMWR_DATA_OFF_RD_CHANNEL_4_DATA_MASK (0xFFFFU)
#define PCIE_DMA_READ_CH45_IMWR_DATA_OFF_RD_CHANNEL_4_DATA_SHIFT (0U)
/*! RD_CHANNEL_4_DATA - The DMA uses this field to generate the data field for the Done or Abort
 *    IMWr TLPs it generates for read channel 4. Note: The access attributes of this field are as
 *    follows: - Dbi: R/W
 */
#define PCIE_DMA_READ_CH45_IMWR_DATA_OFF_RD_CHANNEL_4_DATA(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_CH45_IMWR_DATA_OFF_RD_CHANNEL_4_DATA_SHIFT)) & PCIE_DMA_READ_CH45_IMWR_DATA_OFF_RD_CHANNEL_4_DATA_MASK)

#define PCIE_DMA_READ_CH45_IMWR_DATA_OFF_RD_CHANNEL_5_DATA_MASK (0xFFFF0000U)
#define PCIE_DMA_READ_CH45_IMWR_DATA_OFF_RD_CHANNEL_5_DATA_SHIFT (16U)
/*! RD_CHANNEL_5_DATA - The DMA uses this field to generate the data field for the Done or Abort
 *    IMWr TLPs it generates for read channel 5. Note: The access attributes of this field are as
 *    follows: - Dbi: R/W
 */
#define PCIE_DMA_READ_CH45_IMWR_DATA_OFF_RD_CHANNEL_5_DATA(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_CH45_IMWR_DATA_OFF_RD_CHANNEL_5_DATA_SHIFT)) & PCIE_DMA_READ_CH45_IMWR_DATA_OFF_RD_CHANNEL_5_DATA_MASK)
/*! @} */

/*! @name DMA_READ_CH67_IMWR_DATA_OFF - DMA Read Channel 7 and 6 IMWr Data Register. */
/*! @{ */

#define PCIE_DMA_READ_CH67_IMWR_DATA_OFF_RD_CHANNEL_6_DATA_MASK (0xFFFFU)
#define PCIE_DMA_READ_CH67_IMWR_DATA_OFF_RD_CHANNEL_6_DATA_SHIFT (0U)
/*! RD_CHANNEL_6_DATA - The DMA uses this field to generate the data field for the Done or Abort
 *    IMWr TLPs it generates for read channel 6. Note: The access attributes of this field are as
 *    follows: - Dbi: R/W
 */
#define PCIE_DMA_READ_CH67_IMWR_DATA_OFF_RD_CHANNEL_6_DATA(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_CH67_IMWR_DATA_OFF_RD_CHANNEL_6_DATA_SHIFT)) & PCIE_DMA_READ_CH67_IMWR_DATA_OFF_RD_CHANNEL_6_DATA_MASK)

#define PCIE_DMA_READ_CH67_IMWR_DATA_OFF_RD_CHANNEL_7_DATA_MASK (0xFFFF0000U)
#define PCIE_DMA_READ_CH67_IMWR_DATA_OFF_RD_CHANNEL_7_DATA_SHIFT (16U)
/*! RD_CHANNEL_7_DATA - The DMA uses this field to generate the data field for the Done or Abort
 *    IMWr TLPs it generates for read channel 7. Note: The access attributes of this field are as
 *    follows: - Dbi: R/W
 */
#define PCIE_DMA_READ_CH67_IMWR_DATA_OFF_RD_CHANNEL_7_DATA(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_READ_CH67_IMWR_DATA_OFF_RD_CHANNEL_7_DATA_SHIFT)) & PCIE_DMA_READ_CH67_IMWR_DATA_OFF_RD_CHANNEL_7_DATA_MASK)
/*! @} */

/*! @name DMA_CH_CONTROL1_OFF_WRCH_0 - DMA Write Channel Control 1 Register. */
/*! @{ */

#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_CB_MASK  (0x1U)
#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_CB_SHIFT (0U)
/*! CB - Cycle Bit (CB). Used in linked list mode only. It is used to synchronize the producer
 *    (software) and the consumer (DMA). For more details, see "PCS-CCS-CB-TCB Producer-Consumer
 *    Synchronization". The DMA loads this field with the CB of the linked list element. Note: The access
 *    attributes of this field are as follows: - Dbi: R/W
 */
#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_CB(x)    (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_CB_SHIFT)) & PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_CB_MASK)

#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_TCB_MASK (0x2U)
#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_TCB_SHIFT (1U)
/*! TCB - Toggle Cycle Bit (TCB). Indicates to the DMA to toggle its interpretation of the CB. Used
 *    in linked list mode only. It is used to synchronize the producer (software) and the consumer
 *    (DMA). For more details, see "PCS-CCS-CB-TCB Producer-Consumer Synchronization". The DMA loads
 *    this field with the TCB of the linked list element. this field is not defined in a data LL
 *    element. Note: The access attributes of this field are as follows: - Dbi: R/W
 */
#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_TCB(x)   (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_TCB_SHIFT)) & PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_TCB_MASK)

#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_LLP_MASK (0x4U)
#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_LLP_SHIFT (2U)
/*! LLP - Load Link Pointer (LLP). Used in linked list mode only. Indicates that this linked list
 *    element is a link element, and its LL element pointer dwords are pointing to the next
 *    (non-contiguous) element. The DMA loads this field with the LLP of the linked list element. Note: The
 *    access attributes of this field are as follows: - Dbi: R/W
 */
#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_LLP(x)   (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_LLP_SHIFT)) & PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_LLP_MASK)

#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_LIE_MASK (0x8U)
#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_LIE_SHIFT (3U)
/*! LIE - Local Interrupt Enable (LIE). You must set this bit to enable the generation of the Done
 *    or Abort Local interrupts. For more details, see "Interrupts and Error Handling". In LL mode,
 *    the DMA overwrites this with the LIE of the LL element. The LIE bit in a LL element only
 *    enables the Done interrupt. In non-LL mode, the LIE bit enables the Done and Abort interrupts. This
 *    field is not defined in a link LL element. Note: The access attributes of this field are as
 *    follows: - Dbi: R/W
 */
#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_LIE(x)   (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_LIE_SHIFT)) & PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_LIE_MASK)

#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_RIE_MASK (0x10U)
#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_RIE_SHIFT (4U)
/*! RIE - Remote Interrupt Enable (RIE). You must set this bit to enable the generation of the Done
 *    or Abort Remote interrupts. For more details, see "Interrupts and Error Handling". In LL mode,
 *    the DMA overwrites this with the RIE of the LL element. The RIE bit in a LL element only
 *    enables the Done interrupt. In non-LL mode, the RIE bit enables the Done and Abort interrupts.
 *    This field is not defined in a link LL element. Note: The access attributes of this field are as
 *    follows: - Dbi: R/W
 */
#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_RIE(x)   (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_RIE_SHIFT)) & PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_RIE_MASK)

#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_CS_MASK  (0x60U)
#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_CS_SHIFT (5U)
/*! CS - Channel Status (CS). The channel status bits identify the current operational state of the
 *    DMA channel. The operation state encoding for each DMA channel is a s follows: - 00: Reserved
 *    - 01: Running. This channel is active and transferring data. - 10: Halted. An error condition
 *    has been detected, and the DMA has stopped this channel. - 11: Stopped. The DMA has
 *    transferred all data for this channel, or you have prematurely stopped this channel by writing to the
 *    Stop field of the "DMA Write Doorbell Register" (DMA_WRITE_DOORBELL_OFF) or "DMA Read Doorbell
 *    Register" (DMA_READ_DOORBELL_OFF).
 */
#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_CS(x)    (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_CS_SHIFT)) & PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_CS_MASK)

#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_DMA_RESERVED0_MASK (0x80U)
#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_DMA_RESERVED0_SHIFT (7U)
/*! DMA_RESERVED0 - Reserved. Note: The access attributes of this field are as follows: - Dbi: R/W */
#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_DMA_RESERVED0(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_DMA_RESERVED0_SHIFT)) & PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_DMA_RESERVED0_MASK)

#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_CCS_MASK (0x100U)
#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_CCS_SHIFT (8U)
/*! CCS - Consumer Cycle State (CCS). Used in linked list mode only. It is used to synchronize the
 *    producer (software) and the consumer (DMA). For more details, see "PCS-CCS-CB-TCB
 *    Producer-Consumer Synchronization". You must initialize this bit. The DMA updates this bit during linked
 *    list operation. Note: The access attributes of this field are as follows: - Dbi: R/W
 */
#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_CCS(x)   (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_CCS_SHIFT)) & PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_CCS_MASK)

#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_LLE_MASK (0x200U)
#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_LLE_SHIFT (9U)
/*! LLE - Linked List Enable (LLE). - 0: Disable linked list operation - 1: Enable linked list
 *    operation Note: The access attributes of this field are as follows: - Dbi: R/W
 */
#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_LLE(x)   (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_LLE_SHIFT)) & PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_LLE_MASK)

#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_DMA_RESERVED1_MASK (0xC00U)
#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_DMA_RESERVED1_SHIFT (10U)
/*! DMA_RESERVED1 - Reserved. Note: The access attributes of this field are as follows: - Dbi: R/W */
#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_DMA_RESERVED1(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_DMA_RESERVED1_SHIFT)) & PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_DMA_RESERVED1_MASK)

#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_DMA_FUNC_NUM_MASK (0x1F000U)
#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_DMA_FUNC_NUM_SHIFT (12U)
/*! DMA_FUNC_NUM - Function Number (FN). The controller uses this field when generating the
 *    requester ID for the MRd/MWr DMA TLP. When you have enabled SR-IOV, then this field is ignored if you
 *    have set the VFE field in the "DMA Write Channel Control 2 Register"
 *    (DMA_CH_CONTROL2_OFF_WRCH_0). Note: The access attributes of this field are as follows: - Dbi: R/W
 */
#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_DMA_FUNC_NUM(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_DMA_FUNC_NUM_SHIFT)) & PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_DMA_FUNC_NUM_MASK)

#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_DMA_RESERVED2_MASK (0x7E0000U)
#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_DMA_RESERVED2_SHIFT (17U)
/*! DMA_RESERVED2 - Reserved. Note: The access attributes of this field are as follows: - Dbi: R/W */
#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_DMA_RESERVED2(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_DMA_RESERVED2_SHIFT)) & PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_DMA_RESERVED2_MASK)

#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_DMA_NS_DST_MASK (0x800000U)
#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_DMA_NS_DST_SHIFT (23U)
/*! DMA_NS_DST - Destination No Snoop TLP Header Bit (DMA_NS_DST). The DMA uses this TLP header
 *    field when generating MWr (DAR addressing space) (not IMWr) TLPs. Note: The access attributes of
 *    this field are as follows: - Dbi: R/W
 */
#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_DMA_NS_DST(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_DMA_NS_DST_SHIFT)) & PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_DMA_NS_DST_MASK)

#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_DMA_NS_SRC_MASK (0x1000000U)
#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_DMA_NS_SRC_SHIFT (24U)
/*! DMA_NS_SRC - Source No Snoop TLP Header Bit (DMA_NS_SRC). The DMA uses this TLP header field
 *    when generating MRd (SAR addressing space) (not IMWr) TLPs. Note: The access attributes of this
 *    field are as follows: - Dbi: R/W
 */
#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_DMA_NS_SRC(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_DMA_NS_SRC_SHIFT)) & PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_DMA_NS_SRC_MASK)

#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_DMA_RO_MASK (0x2000000U)
#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_DMA_RO_SHIFT (25U)
/*! DMA_RO - Relaxed Ordering TLP Header Bit (RO) The DMA uses this TLP header field when generating
 *    MRd/MWr (not IMWr) TLPs. Note: The access attributes of this field are as follows: - Dbi: R/W
 */
#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_DMA_RO(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_DMA_RO_SHIFT)) & PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_DMA_RO_MASK)

#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_DMA_RESERVED5_MASK (0x4000000U)
#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_DMA_RESERVED5_SHIFT (26U)
/*! DMA_RESERVED5 - Reserved. Note: The access attributes of this field are as follows: - Dbi: R/W */
#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_DMA_RESERVED5(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_DMA_RESERVED5_SHIFT)) & PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_DMA_RESERVED5_MASK)

#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_DMA_TC_MASK (0x38000000U)
#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_DMA_TC_SHIFT (27U)
/*! DMA_TC - Traffic Class TLP Header Bit (TC) The DMA uses this TLP header field when generating
 *    MRd/MWr (not IMWr) TLPs. Note: The access attributes of this field are as follows: - Dbi: R/W
 */
#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_DMA_TC(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_DMA_TC_SHIFT)) & PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_DMA_TC_MASK)

#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_DMA_AT_MASK (0xC0000000U)
#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_DMA_AT_SHIFT (30U)
/*! DMA_AT - Address Translation TLP Header Bit (AT) The DMA uses this TLP header field when
 *    generating MRd/MWr (not IMWr) TLPs. Note: The access attributes of this field are as follows: - Dbi:
 *    R/W
 */
#define PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_DMA_AT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_DMA_AT_SHIFT)) & PCIE_DMA_CH_CONTROL1_OFF_WRCH_0_DMA_AT_MASK)
/*! @} */

/*! @name DMA_TRANSFER_SIZE_OFF_WRCH_0 - DMA Write Transfer Size Register. */
/*! @{ */

#define PCIE_DMA_TRANSFER_SIZE_OFF_WRCH_0_DMA_TRANSFER_SIZE_MASK (0xFFFFFFFFU)
#define PCIE_DMA_TRANSFER_SIZE_OFF_WRCH_0_DMA_TRANSFER_SIZE_SHIFT (0U)
/*! DMA_TRANSFER_SIZE - DMA Transfer Size. You program this register with the size of the DMA
 *    transfer. The maximum DMA transfer size is 4Gbytes. The minimum transfer size is one byte (0x1).
 *    This field is automatically decremented by the DMA as the DMA write channel transfer progresses.
 *    This field indicates the number bytes remaining to be transferred. When all bytes are
 *    successfully transferred the current transfer size is zero. In LL mode, the DMA overwrites this
 *    register with the corresponding dword of the LL element. You can read this register to monitor the
 *    transfer progress, however in some scenarios this register is updated after a delay. For
 *    example, when less than 3 channels are doorbelled, this register is updated only after a descriptor
 *    finishes(linked list mode), or the transfer ends (non-linked list mode). Note: The access
 *    attributes of this field are as follows: - Dbi: R/W
 */
#define PCIE_DMA_TRANSFER_SIZE_OFF_WRCH_0_DMA_TRANSFER_SIZE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_TRANSFER_SIZE_OFF_WRCH_0_DMA_TRANSFER_SIZE_SHIFT)) & PCIE_DMA_TRANSFER_SIZE_OFF_WRCH_0_DMA_TRANSFER_SIZE_MASK)
/*! @} */

/*! @name DMA_SAR_LOW_OFF_WRCH_0 - DMA Write SAR Low Register. */
/*! @{ */

#define PCIE_DMA_SAR_LOW_OFF_WRCH_0_SRC_ADDR_REG_LOW_MASK (0xFFFFFFFFU)
#define PCIE_DMA_SAR_LOW_OFF_WRCH_0_SRC_ADDR_REG_LOW_SHIFT (0U)
/*! SRC_ADDR_REG_LOW - Source Address Register (Lower 32 bits). Indicates the next address to be
 *    read from. The DMA increments the SAR as the DMA transfer progresses. In LL mode, the DMA
 *    overwrites this with the corresponding dword of the LL element. - DMA Read: The SAR is the address of
 *    the remote memory. - DMA Write: The SAR is the address of the local memory. Note: The access
 *    attributes of this field are as follows: - Dbi: R/W
 */
#define PCIE_DMA_SAR_LOW_OFF_WRCH_0_SRC_ADDR_REG_LOW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_SAR_LOW_OFF_WRCH_0_SRC_ADDR_REG_LOW_SHIFT)) & PCIE_DMA_SAR_LOW_OFF_WRCH_0_SRC_ADDR_REG_LOW_MASK)
/*! @} */

/*! @name DMA_SAR_HIGH_OFF_WRCH_0 - DMA Write SAR High Register. */
/*! @{ */

#define PCIE_DMA_SAR_HIGH_OFF_WRCH_0_SRC_ADDR_REG_HIGH_MASK (0xFFFFFFFFU)
#define PCIE_DMA_SAR_HIGH_OFF_WRCH_0_SRC_ADDR_REG_HIGH_SHIFT (0U)
/*! SRC_ADDR_REG_HIGH - Source Address Register (Higher 32 bits). In LL mode, the DMA overwrites
 *    this with the corresponding dword of the LL element. Note: The access attributes of this field
 *    are as follows: - Dbi: R/W
 */
#define PCIE_DMA_SAR_HIGH_OFF_WRCH_0_SRC_ADDR_REG_HIGH(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_SAR_HIGH_OFF_WRCH_0_SRC_ADDR_REG_HIGH_SHIFT)) & PCIE_DMA_SAR_HIGH_OFF_WRCH_0_SRC_ADDR_REG_HIGH_MASK)
/*! @} */

/*! @name DMA_DAR_LOW_OFF_WRCH_0 - DMA Write DAR Low Register. */
/*! @{ */

#define PCIE_DMA_DAR_LOW_OFF_WRCH_0_DST_ADDR_REG_LOW_MASK (0xFFFFFFFFU)
#define PCIE_DMA_DAR_LOW_OFF_WRCH_0_DST_ADDR_REG_LOW_SHIFT (0U)
/*! DST_ADDR_REG_LOW - Destination Address Register (Lower 32 bits). Indicates the next address to
 *    be written to. The DMA increments the DAR as the DMA transfer progresses. In LL mode, the DMA
 *    overwrites this with the corresponding dword of the LL element. - DMA Read: The DAR is the
 *    address of the local memory. - DMA Write: The DAR is the address of the remote memory. Note: The
 *    access attributes of this field are as follows: - Dbi: R/W
 */
#define PCIE_DMA_DAR_LOW_OFF_WRCH_0_DST_ADDR_REG_LOW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_DAR_LOW_OFF_WRCH_0_DST_ADDR_REG_LOW_SHIFT)) & PCIE_DMA_DAR_LOW_OFF_WRCH_0_DST_ADDR_REG_LOW_MASK)
/*! @} */

/*! @name DMA_DAR_HIGH_OFF_WRCH_0 - DMA Write DAR High Register. */
/*! @{ */

#define PCIE_DMA_DAR_HIGH_OFF_WRCH_0_DST_ADDR_REG_HIGH_MASK (0xFFFFFFFFU)
#define PCIE_DMA_DAR_HIGH_OFF_WRCH_0_DST_ADDR_REG_HIGH_SHIFT (0U)
/*! DST_ADDR_REG_HIGH - Destination Address Register (Higher 32 bits). In LL mode, the DMA
 *    overwrites this with the corresponding dword of the LL element. Note: The access attributes of this
 *    field are as follows: - Dbi: R/W
 */
#define PCIE_DMA_DAR_HIGH_OFF_WRCH_0_DST_ADDR_REG_HIGH(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_DAR_HIGH_OFF_WRCH_0_DST_ADDR_REG_HIGH_SHIFT)) & PCIE_DMA_DAR_HIGH_OFF_WRCH_0_DST_ADDR_REG_HIGH_MASK)
/*! @} */

/*! @name DMA_LLP_LOW_OFF_WRCH_0 - DMA Write Linked List Pointer Low Register. */
/*! @{ */

#define PCIE_DMA_LLP_LOW_OFF_WRCH_0_LLP_LOW_MASK (0xFFFFFFFFU)
#define PCIE_DMA_LLP_LOW_OFF_WRCH_0_LLP_LOW_SHIFT (0U)
/*! LLP_LOW - Lower bits of the address of the linked list transfer list in local memory. Used in
 *    linked list mode only. Updated by the DMA to point to the next element in the transfer list
 *    after the previous element is consumed. - When the current element is a data element; this field
 *    is incremented by 6. - When the current element is a link element; this field is overwritten by
 *    the LL Element Pointer of the element. Note: The access attributes of this field are as
 *    follows: - Dbi: R/W
 */
#define PCIE_DMA_LLP_LOW_OFF_WRCH_0_LLP_LOW(x)   (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_LLP_LOW_OFF_WRCH_0_LLP_LOW_SHIFT)) & PCIE_DMA_LLP_LOW_OFF_WRCH_0_LLP_LOW_MASK)
/*! @} */

/*! @name DMA_LLP_HIGH_OFF_WRCH_0 - DMA Write Linked List Pointer High Register. */
/*! @{ */

#define PCIE_DMA_LLP_HIGH_OFF_WRCH_0_LLP_HIGH_MASK (0xFFFFFFFFU)
#define PCIE_DMA_LLP_HIGH_OFF_WRCH_0_LLP_HIGH_SHIFT (0U)
/*! LLP_HIGH - Upper 32 bits of the address of the linked list transfer list in local memory. Used
 *    in linked list mode only. Updated by the DMA to point to the next element in the transfer list
 *    as elements are consumed. Note: The access attributes of this field are as follows: - Dbi: R/W
 */
#define PCIE_DMA_LLP_HIGH_OFF_WRCH_0_LLP_HIGH(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_LLP_HIGH_OFF_WRCH_0_LLP_HIGH_SHIFT)) & PCIE_DMA_LLP_HIGH_OFF_WRCH_0_LLP_HIGH_MASK)
/*! @} */

/*! @name DMA_CH_CONTROL1_OFF_RDCH_0 - DMA Read Channel Control 1 Register. */
/*! @{ */

#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_CB_MASK  (0x1U)
#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_CB_SHIFT (0U)
/*! CB - Cycle Bit (CB). Used in linked list mode only. It is used to synchronize the producer
 *    (software) and the consumer (DMA). For more details, see "PCS-CCS-CB-TCB Producer-Consumer
 *    Synchronization". The DMA loads this field with the CB of the linked list element. Note: The access
 *    attributes of this field are as follows: - Dbi: R/W
 */
#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_CB(x)    (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_CB_SHIFT)) & PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_CB_MASK)

#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_TCB_MASK (0x2U)
#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_TCB_SHIFT (1U)
/*! TCB - Toggle Cycle Bit (TCB). Indicates to the DMA to toggle its interpretation of the CB. Used
 *    in linked list mode only. It is used to synchronize the producer (software) and the consumer
 *    (DMA). For more details, see "PCS-CCS-CB-TCB Producer-Consumer Synchronization". The DMA loads
 *    this field with the TCB of the linked list element. this field is not defined in a data LL
 *    element. Note: The access attributes of this field are as follows: - Dbi: R/W
 */
#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_TCB(x)   (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_TCB_SHIFT)) & PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_TCB_MASK)

#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_LLP_MASK (0x4U)
#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_LLP_SHIFT (2U)
/*! LLP - Load Link Pointer (LLP). Used in linked list mode only. Indicates that this linked list
 *    element is a link element, and its LL element pointer dwords are pointing to the next
 *    (non-contiguous) element. The DMA loads this field with the LLP of the linked list element. Note: The
 *    access attributes of this field are as follows: - Dbi: R/W
 */
#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_LLP(x)   (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_LLP_SHIFT)) & PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_LLP_MASK)

#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_LIE_MASK (0x8U)
#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_LIE_SHIFT (3U)
/*! LIE - Local Interrupt Enable (LIE). You must set this bit to enable the generation of the Done
 *    or Abort Local interrupts. For more details, see "Interrupts and Error Handling". In LL mode,
 *    the DMA overwrites this with the LIE of the LL element. The LIE bit in a LL element only
 *    enables the Done interrupt. In non-LL mode, the LIE bit enables the Done and Abort interrupts. This
 *    field is not defined in a link LL element. Note: The access attributes of this field are as
 *    follows: - Dbi: R/W
 */
#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_LIE(x)   (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_LIE_SHIFT)) & PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_LIE_MASK)

#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_RIE_MASK (0x10U)
#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_RIE_SHIFT (4U)
/*! RIE - Remote Interrupt Enable (RIE). You must set this bit to enable the generation of the Done
 *    or Abort Remote interrupts. For more details, see "Interrupts and Error Handling". In LL mode,
 *    the DMA overwrites this with the RIE of the LL element. The RIE bit in a LL element only
 *    enables the Done interrupt. In non-LL mode, the RIE bit enables the Done and Abort interrupts.
 *    This field is not defined in a link LL element. Note: The access attributes of this field are as
 *    follows: - Dbi: R/W
 */
#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_RIE(x)   (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_RIE_SHIFT)) & PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_RIE_MASK)

#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_CS_MASK  (0x60U)
#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_CS_SHIFT (5U)
/*! CS - Channel Status (CS). The channel status bits identify the current operational state of the
 *    DMA channel. The operation state encoding for each DMA channel is a s follows: - 00: Reserved
 *    - 01: Running. This channel is active and transferring data. - 10: Halted. An error condition
 *    has been detected, and the DMA has stopped this channel. - 11: Stopped. The DMA has
 *    transferred all data for this channel, or you have prematurely stopped this channel by writing to the
 *    Stop field of the "DMA Read Doorbell Register" (DMA_WRITE_DOORBELL_OFF) or "DMA Read Doorbell
 *    Register" (DMA_READ_DOORBELL_OFF).
 */
#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_CS(x)    (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_CS_SHIFT)) & PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_CS_MASK)

#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_DMA_RESERVED0_MASK (0x80U)
#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_DMA_RESERVED0_SHIFT (7U)
/*! DMA_RESERVED0 - Reserved. Note: The access attributes of this field are as follows: - Dbi: R/W */
#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_DMA_RESERVED0(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_DMA_RESERVED0_SHIFT)) & PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_DMA_RESERVED0_MASK)

#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_CCS_MASK (0x100U)
#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_CCS_SHIFT (8U)
/*! CCS - Consumer Cycle State (CCS). Used in linked list mode only. It is used to synchronize the
 *    producer (software) and the consumer (DMA). For more details, see "PCS-CCS-CB-TCB
 *    Producer-Consumer Synchronization". You must initialize this bit. The DMA updates this bit during linked
 *    list operation. Note: The access attributes of this field are as follows: - Dbi: R/W
 */
#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_CCS(x)   (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_CCS_SHIFT)) & PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_CCS_MASK)

#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_LLE_MASK (0x200U)
#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_LLE_SHIFT (9U)
/*! LLE - Linked List Enable (LLE). - 0: Disable linked list operation - 1: Enable linked list
 *    operation Note: The access attributes of this field are as follows: - Dbi: R/W
 */
#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_LLE(x)   (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_LLE_SHIFT)) & PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_LLE_MASK)

#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_DMA_RESERVED1_MASK (0xC00U)
#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_DMA_RESERVED1_SHIFT (10U)
/*! DMA_RESERVED1 - Reserved. Note: The access attributes of this field are as follows: - Dbi: R/W */
#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_DMA_RESERVED1(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_DMA_RESERVED1_SHIFT)) & PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_DMA_RESERVED1_MASK)

#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_DMA_FUNC_NUM_MASK (0x1F000U)
#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_DMA_FUNC_NUM_SHIFT (12U)
/*! DMA_FUNC_NUM - Function Number (FN). The controller uses this field when generating the
 *    requester ID for the MRd/MWr DMA TLP. When you have enabled SR-IOV, then this field is ignored if you
 *    have set the VFE field in the "DMA Read Channel Control 2 Register"
 *    (DMA_CH_CONTROL2_OFF_RDCH_0). Note: The access attributes of this field are as follows: - Dbi: R/W
 */
#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_DMA_FUNC_NUM(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_DMA_FUNC_NUM_SHIFT)) & PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_DMA_FUNC_NUM_MASK)

#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_DMA_RESERVED2_MASK (0x7E0000U)
#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_DMA_RESERVED2_SHIFT (17U)
/*! DMA_RESERVED2 - Reserved. Note: The access attributes of this field are as follows: - Dbi: R/W */
#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_DMA_RESERVED2(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_DMA_RESERVED2_SHIFT)) & PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_DMA_RESERVED2_MASK)

#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_DMA_NS_DST_MASK (0x800000U)
#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_DMA_NS_DST_SHIFT (23U)
/*! DMA_NS_DST - Destination No Snoop TLP Header Bit (DMA_NS_DST). The DMA uses this TLP header
 *    field when generating MWr (DAR addressing space) (not IMWr) TLPs. Note: The access attributes of
 *    this field are as follows: - Dbi: R/W
 */
#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_DMA_NS_DST(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_DMA_NS_DST_SHIFT)) & PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_DMA_NS_DST_MASK)

#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_DMA_NS_SRC_MASK (0x1000000U)
#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_DMA_NS_SRC_SHIFT (24U)
/*! DMA_NS_SRC - Source No Snoop TLP Header Bit (DMA_NS_SRC). The DMA uses this TLP header field
 *    when generating MRd (SAR addressing space) (not IMWr) TLPs. Note: The access attributes of this
 *    field are as follows: - Dbi: R/W
 */
#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_DMA_NS_SRC(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_DMA_NS_SRC_SHIFT)) & PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_DMA_NS_SRC_MASK)

#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_DMA_RO_MASK (0x2000000U)
#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_DMA_RO_SHIFT (25U)
/*! DMA_RO - Relaxed Ordering TLP Header Bit (RO) The DMA uses this TLP header field when generating
 *    MRd/MWr (not IMWr) TLPs. Note: The access attributes of this field are as follows: - Dbi: R/W
 */
#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_DMA_RO(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_DMA_RO_SHIFT)) & PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_DMA_RO_MASK)

#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_DMA_RESERVED5_MASK (0x4000000U)
#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_DMA_RESERVED5_SHIFT (26U)
/*! DMA_RESERVED5 - Reserved. Note: The access attributes of this field are as follows: - Dbi: R/W */
#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_DMA_RESERVED5(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_DMA_RESERVED5_SHIFT)) & PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_DMA_RESERVED5_MASK)

#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_DMA_TC_MASK (0x38000000U)
#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_DMA_TC_SHIFT (27U)
/*! DMA_TC - Traffic Class TLP Header Bit (TC) The DMA uses this TLP header field when generating
 *    MRd/MWr (not IMWr) TLPs. Note: The access attributes of this field are as follows: - Dbi: R/W
 */
#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_DMA_TC(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_DMA_TC_SHIFT)) & PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_DMA_TC_MASK)

#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_DMA_AT_MASK (0xC0000000U)
#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_DMA_AT_SHIFT (30U)
/*! DMA_AT - Address Translation TLP Header Bit (AT) The DMA uses this TLP header field when
 *    generating MRd/MWr (not IMWr) TLPs. Note: The access attributes of this field are as follows: - Dbi:
 *    R/W
 */
#define PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_DMA_AT(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_DMA_AT_SHIFT)) & PCIE_DMA_CH_CONTROL1_OFF_RDCH_0_DMA_AT_MASK)
/*! @} */

/*! @name DMA_TRANSFER_SIZE_OFF_RDCH_0 - DMA Read Transfer Size Register. */
/*! @{ */

#define PCIE_DMA_TRANSFER_SIZE_OFF_RDCH_0_DMA_TRANSFER_SIZE_MASK (0xFFFFFFFFU)
#define PCIE_DMA_TRANSFER_SIZE_OFF_RDCH_0_DMA_TRANSFER_SIZE_SHIFT (0U)
/*! DMA_TRANSFER_SIZE - DMA Transfer Size. You program this register with the size of the DMA
 *    transfer. The maximum DMA transfer size is 4Gbytes. The minimum transfer size is one byte (0x1).
 *    This field is automatically decremented by the DMA as the DMA read channel transfer progresses.
 *    This field indicates the number bytes remaining to be transferred. When all bytes are
 *    successfully transferred the current transfer size is zero. In LL mode, the DMA overwrites this
 *    register with the corresponding dword of the LL element. You can read this register to monitor the
 *    transfer progress, however in some scenarios this register is updated after a delay. For
 *    example, when less than 3 channels are doorbelled, this register is updated only after a descriptor
 *    finishes(linked list mode), or the transfer ends (non-linked list mode). Note: The access
 *    attributes of this field are as follows: - Dbi: R/W
 */
#define PCIE_DMA_TRANSFER_SIZE_OFF_RDCH_0_DMA_TRANSFER_SIZE(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_TRANSFER_SIZE_OFF_RDCH_0_DMA_TRANSFER_SIZE_SHIFT)) & PCIE_DMA_TRANSFER_SIZE_OFF_RDCH_0_DMA_TRANSFER_SIZE_MASK)
/*! @} */

/*! @name DMA_SAR_LOW_OFF_RDCH_0 - DMA Read SAR Low Register. */
/*! @{ */

#define PCIE_DMA_SAR_LOW_OFF_RDCH_0_SRC_ADDR_REG_LOW_MASK (0xFFFFFFFFU)
#define PCIE_DMA_SAR_LOW_OFF_RDCH_0_SRC_ADDR_REG_LOW_SHIFT (0U)
/*! SRC_ADDR_REG_LOW - Source Address Register (Lower 32 bits). Indicates the next address to be
 *    read from. The DMA increments the SAR as the DMA transfer progresses. In LL mode, the DMA
 *    overwrites this with the corresponding dword of the LL element. - DMA Read: The SAR is the address of
 *    the remote memory. - DMA Read: The SAR is the address of the local memory. Note: The access
 *    attributes of this field are as follows: - Dbi: R/W
 */
#define PCIE_DMA_SAR_LOW_OFF_RDCH_0_SRC_ADDR_REG_LOW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_SAR_LOW_OFF_RDCH_0_SRC_ADDR_REG_LOW_SHIFT)) & PCIE_DMA_SAR_LOW_OFF_RDCH_0_SRC_ADDR_REG_LOW_MASK)
/*! @} */

/*! @name DMA_SAR_HIGH_OFF_RDCH_0 - DMA Read SAR High Register. */
/*! @{ */

#define PCIE_DMA_SAR_HIGH_OFF_RDCH_0_SRC_ADDR_REG_HIGH_MASK (0xFFFFFFFFU)
#define PCIE_DMA_SAR_HIGH_OFF_RDCH_0_SRC_ADDR_REG_HIGH_SHIFT (0U)
/*! SRC_ADDR_REG_HIGH - Source Address Register (Higher 32 bits). In LL mode, the DMA overwrites
 *    this with the corresponding dword of the LL element. Note: The access attributes of this field
 *    are as follows: - Dbi: R/W
 */
#define PCIE_DMA_SAR_HIGH_OFF_RDCH_0_SRC_ADDR_REG_HIGH(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_SAR_HIGH_OFF_RDCH_0_SRC_ADDR_REG_HIGH_SHIFT)) & PCIE_DMA_SAR_HIGH_OFF_RDCH_0_SRC_ADDR_REG_HIGH_MASK)
/*! @} */

/*! @name DMA_DAR_LOW_OFF_RDCH_0 - DMA Read DAR Low Register. */
/*! @{ */

#define PCIE_DMA_DAR_LOW_OFF_RDCH_0_DST_ADDR_REG_LOW_MASK (0xFFFFFFFFU)
#define PCIE_DMA_DAR_LOW_OFF_RDCH_0_DST_ADDR_REG_LOW_SHIFT (0U)
/*! DST_ADDR_REG_LOW - Destination Address Register (Lower 32 bits). Indicates the next address to
 *    be written to. The DMA increments the DAR as the DMA transfer progresses. In LL mode, the DMA
 *    overwrites this with the corresponding dword of the LL element. - DMA Read: The DAR is the
 *    address of the local memory. - DMA Read: The DAR is the address of the remote memory. Note: The
 *    access attributes of this field are as follows: - Dbi: R/W
 */
#define PCIE_DMA_DAR_LOW_OFF_RDCH_0_DST_ADDR_REG_LOW(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_DAR_LOW_OFF_RDCH_0_DST_ADDR_REG_LOW_SHIFT)) & PCIE_DMA_DAR_LOW_OFF_RDCH_0_DST_ADDR_REG_LOW_MASK)
/*! @} */

/*! @name DMA_DAR_HIGH_OFF_RDCH_0 - DMA Read DAR High Register. */
/*! @{ */

#define PCIE_DMA_DAR_HIGH_OFF_RDCH_0_DST_ADDR_REG_HIGH_MASK (0xFFFFFFFFU)
#define PCIE_DMA_DAR_HIGH_OFF_RDCH_0_DST_ADDR_REG_HIGH_SHIFT (0U)
/*! DST_ADDR_REG_HIGH - Destination Address Register (Higher 32 bits). In LL mode, the DMA
 *    overwrites this with the corresponding dword of the LL element. Note: The access attributes of this
 *    field are as follows: - Dbi: R/W
 */
#define PCIE_DMA_DAR_HIGH_OFF_RDCH_0_DST_ADDR_REG_HIGH(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_DAR_HIGH_OFF_RDCH_0_DST_ADDR_REG_HIGH_SHIFT)) & PCIE_DMA_DAR_HIGH_OFF_RDCH_0_DST_ADDR_REG_HIGH_MASK)
/*! @} */

/*! @name DMA_LLP_LOW_OFF_RDCH_0 - DMA Read Linked List Pointer Low Register. */
/*! @{ */

#define PCIE_DMA_LLP_LOW_OFF_RDCH_0_LLP_LOW_MASK (0xFFFFFFFFU)
#define PCIE_DMA_LLP_LOW_OFF_RDCH_0_LLP_LOW_SHIFT (0U)
/*! LLP_LOW - Lower bits of the address of the linked list transfer list in local memory. Used in
 *    linked list mode only. Updated by the DMA to point to the next element in the transfer list
 *    after the previous element is consumed. - When the current element is a data element; this field
 *    is incremented by 6. - When the current element is a link element; this field is overwritten by
 *    the LL Element Pointer of the element. Note: The access attributes of this field are as
 *    follows: - Dbi: R/W
 */
#define PCIE_DMA_LLP_LOW_OFF_RDCH_0_LLP_LOW(x)   (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_LLP_LOW_OFF_RDCH_0_LLP_LOW_SHIFT)) & PCIE_DMA_LLP_LOW_OFF_RDCH_0_LLP_LOW_MASK)
/*! @} */

/*! @name DMA_LLP_HIGH_OFF_RDCH_0 - DMA Read Linked List Pointer High Register. */
/*! @{ */

#define PCIE_DMA_LLP_HIGH_OFF_RDCH_0_LLP_HIGH_MASK (0xFFFFFFFFU)
#define PCIE_DMA_LLP_HIGH_OFF_RDCH_0_LLP_HIGH_SHIFT (0U)
/*! LLP_HIGH - Upper 32 bits of the address of the linked list transfer list in local memory. Used
 *    in linked list mode only. Updated by the DMA to point to the next element in the transfer list
 *    as elements are consumed. Note: The access attributes of this field are as follows: - Dbi: R/W
 */
#define PCIE_DMA_LLP_HIGH_OFF_RDCH_0_LLP_HIGH(x) (((uint32_t)(((uint32_t)(x)) << PCIE_DMA_LLP_HIGH_OFF_RDCH_0_LLP_HIGH_SHIFT)) & PCIE_DMA_LLP_HIGH_OFF_RDCH_0_LLP_HIGH_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group PCIE_Register_Masks */


/*!
 * @}
 */ /* end of group PCIE_Peripheral_Access_Layer */


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
#elif defined(__XTENSA__)
  /* leave anonymous unions enabled */
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_PCIE_H_ */

