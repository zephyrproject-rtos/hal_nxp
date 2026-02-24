/*
** ###################################################################
**     Processors:          MIMX95294AVTN_ca55
**                          MIMX95294AVTN_cm33
**                          MIMX95294AVTN_cm7
**                          MIMX95294AVYN_ca55
**                          MIMX95294AVYN_cm33
**                          MIMX95294AVYN_cm7
**                          MIMX95294AVZN_ca55
**                          MIMX95294AVZN_cm33
**                          MIMX95294AVZN_cm7
**                          MIMX95294CVTN_ca55
**                          MIMX95294CVTN_cm33
**                          MIMX95294CVTN_cm7
**                          MIMX95294CVYN_ca55
**                          MIMX95294CVYN_cm33
**                          MIMX95294CVYN_cm7
**                          MIMX95294CVZN_ca55
**                          MIMX95294CVZN_cm33
**                          MIMX95294CVZN_cm7
**                          MIMX95294DVTN_ca55
**                          MIMX95294DVTN_cm33
**                          MIMX95294DVTN_cm7
**                          MIMX95294DVYN_ca55
**                          MIMX95294DVYN_cm33
**                          MIMX95294DVYN_cm7
**                          MIMX95294DVZN_ca55
**                          MIMX95294DVZN_cm33
**                          MIMX95294DVZN_cm7
**                          MIMX95294XVTN_ca55
**                          MIMX95294XVTN_cm33
**                          MIMX95294XVTN_cm7
**                          MIMX95294XVYN_ca55
**                          MIMX95294XVYN_cm33
**                          MIMX95294XVYN_cm7
**                          MIMX95294XVZN_ca55
**                          MIMX95294XVZN_cm33
**                          MIMX95294XVZN_cm7
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250903
**
**     Abstract:
**         CMSIS Peripheral Access Layer for VPU_VPU_DEC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2023-01-10)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_VPU_VPU_DEC.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for VPU_VPU_DEC
 *
 * CMSIS Peripheral Access Layer for VPU_VPU_DEC
 */

#if !defined(PERI_VPU_VPU_DEC_H_)
#define PERI_VPU_VPU_DEC_H_                      /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX95294AVTN_ca55) || defined(CPU_MIMX95294AVYN_ca55) || defined(CPU_MIMX95294AVZN_ca55) || defined(CPU_MIMX95294CVTN_ca55) || defined(CPU_MIMX95294CVYN_ca55) || defined(CPU_MIMX95294CVZN_ca55) || defined(CPU_MIMX95294DVTN_ca55) || defined(CPU_MIMX95294DVYN_ca55) || defined(CPU_MIMX95294DVZN_ca55) || defined(CPU_MIMX95294XVTN_ca55) || defined(CPU_MIMX95294XVYN_ca55) || defined(CPU_MIMX95294XVZN_ca55))
#include "MIMX95294_ca55_COMMON.h"
#elif (defined(CPU_MIMX95294AVTN_cm33) || defined(CPU_MIMX95294AVYN_cm33) || defined(CPU_MIMX95294AVZN_cm33) || defined(CPU_MIMX95294CVTN_cm33) || defined(CPU_MIMX95294CVYN_cm33) || defined(CPU_MIMX95294CVZN_cm33) || defined(CPU_MIMX95294DVTN_cm33) || defined(CPU_MIMX95294DVYN_cm33) || defined(CPU_MIMX95294DVZN_cm33) || defined(CPU_MIMX95294XVTN_cm33) || defined(CPU_MIMX95294XVYN_cm33) || defined(CPU_MIMX95294XVZN_cm33))
#include "MIMX95294_cm33_COMMON.h"
#elif (defined(CPU_MIMX95294AVTN_cm7) || defined(CPU_MIMX95294AVYN_cm7) || defined(CPU_MIMX95294AVZN_cm7) || defined(CPU_MIMX95294CVTN_cm7) || defined(CPU_MIMX95294CVYN_cm7) || defined(CPU_MIMX95294CVZN_cm7) || defined(CPU_MIMX95294DVTN_cm7) || defined(CPU_MIMX95294DVYN_cm7) || defined(CPU_MIMX95294DVZN_cm7) || defined(CPU_MIMX95294XVTN_cm7) || defined(CPU_MIMX95294XVYN_cm7) || defined(CPU_MIMX95294XVZN_cm7))
#include "MIMX95294_cm7_COMMON.h"
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
   -- VPU_VPU_DEC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VPU_VPU_DEC_Peripheral_Access_Layer VPU_VPU_DEC Peripheral Access Layer
 * @{
 */

/** VPU_VPU_DEC - Register Layout Typedef */
typedef struct {
  union {                                          /* offset: 0x0 */
    __O  uint32_t VPU_PO_CONF_CONTROL_REG;           /**< Power On Configurations, offset: 0x0 */
    __O  uint32_t VPU_PO_CONF_CONTROL_REG_VM;        /**< Power On Configurations, offset: 0x0 */
  };
  union {                                          /* offset: 0x4 */
    __I  uint32_t VCPU_CUR_PC_CONTROL_REG;           /**< Current PC, offset: 0x4 */
    __I  uint32_t VCPU_CUR_PC_CONTROL_REG_VM;        /**< Current PC, offset: 0x4 */
  };
  union {                                          /* offset: 0x8 */
    __I  uint32_t VCPU_CUR_LR_CONTROL_REG;           /**< Current LR, offset: 0x8 */
    __I  uint32_t VCPU_CUR_LR_CONTROL_REG_VM;        /**< Current LR, offset: 0x8 */
  };
  union {                                          /* offset: 0xC */
    __IO uint32_t VPU_PDBG_STEP_MASK_CONTROL_REG;    /**< V-CPU Debugger Step Mask, offset: 0xC */
    __IO uint32_t VPU_PDBG_STEP_MASK_CONTROL_REG_VM;   /**< V-CPU Debugger Step Mask, offset: 0xC */
  };
  union {                                          /* offset: 0x10 */
    __O  uint32_t VPU_PDBG_CTRL_CONTROL_REG;         /**< V-CPU Debugger Control, offset: 0x10 */
    __O  uint32_t VPU_PDBG_CTRL_CONTROL_REG_VM;      /**< V-CPU Debugger Control, offset: 0x10 */
  };
  union {                                          /* offset: 0x14 */
    __O  uint32_t VPU_PDBG_IDX_REG_CONTROL_REG;      /**< V-CPU Debugger Index, offset: 0x14 */
    __O  uint32_t VPU_PDBG_IDX_REG_CONTROL_REG_VM;   /**< V-CPU Debugger Index, offset: 0x14 */
  };
  union {                                          /* offset: 0x18 */
    __O  uint32_t VPU_PDBG_WDATA_REG_CONTROL_REG;    /**< V-CPU Debugger Write Data, offset: 0x18 */
    __O  uint32_t VPU_PDBG_WDATA_REG_CONTROL_REG_VM;   /**< V-CPU Debugger Write Data, offset: 0x18 */
  };
  union {                                          /* offset: 0x1C */
    __I  uint32_t VPU_PDBG_RDATA_REG_CONTROL_REG;    /**< V-CPU Debugger Read Data, offset: 0x1C */
    __I  uint32_t VPU_PDBG_RDATA_REG_CONTROL_REG_VM;   /**< V-CPU Debugger Read Data, offset: 0x1C */
  };
  union {                                          /* offset: 0x20 */
    __IO uint32_t VPU_FIO_CTRL_ADDR_CONTROL_REG;     /**< FastIO Control/Address, offset: 0x20 */
    __IO uint32_t VPU_FIO_CTRL_ADDR_CONTROL_REG_VM;   /**< FastIO Control/Address, offset: 0x20 */
  };
  union {                                          /* offset: 0x24 */
    __IO uint32_t VPU_FIO_DATA_CONTROL_REG;          /**< FastIO Data, offset: 0x24 */
    __IO uint32_t VPU_FIO_DATA_CONTROL_REG_VM;       /**< FastIO Data, offset: 0x24 */
  };
       uint8_t RESERVED_0[8];
  union {                                          /* offset: 0x30 */
    __IO uint32_t VPU_VINT_REASON_USR_CONTROL_REG;   /**< Interrupt Reason User, offset: 0x30 */
    __IO uint32_t VPU_VINT_REASON_USR_CONTROL_REG_VM;   /**< Interrupt Reason User, offset: 0x30 */
  };
  union {                                          /* offset: 0x34 */
    __O  uint32_t VPU_VINT_REASON_CLR_CONTROL_REG;   /**< Interrupt Reason Clear, offset: 0x34 */
    __O  uint32_t VPU_VINT_REASON_CLR_CONTROL_REG_VM;   /**< Interrupt Reason Clear, offset: 0x34 */
  };
  union {                                          /* offset: 0x38 */
    __O  uint32_t VPU_HOST_INT_REQ0_CONTROL_REG;     /**< Host Interrupt Request, offset: 0x38 */
    __O  uint32_t VPU_HOST_INT_REQ0_CONTROL_REG_VM;   /**< Host Interrupt Request, offset: 0x38 */
  };
  union {                                          /* offset: 0x3C */
    __O  uint32_t VPU_VINT_CLEAR_CONTROL_REG;        /**< VPU Interrupt Clear, offset: 0x3C */
    __O  uint32_t VPU_VINT_CLEAR_CONTROL_REG_VM;     /**< VPU Interrupt Clear, offset: 0x3C */
  };
  union {                                          /* offset: 0x40 */
    __I  uint32_t VPU_HINT_CLEAR_CONTROL_REG;        /**< Host Interrupt Clear, offset: 0x40 */
    __I  uint32_t VPU_HINT_CLEAR_CONTROL_REG_VM;     /**< Host Interrupt Clear, offset: 0x40 */
  };
  union {                                          /* offset: 0x44 */
    __I  uint32_t VPU_VPU_INT_STS_CONTROL_REG;       /**< VPU Interrupt Status, offset: 0x44 */
    __I  uint32_t VPU_VPU_INT_STS_CONTROL_REG_VM;    /**< VPU Interrupt Status, offset: 0x44 */
  };
  union {                                          /* offset: 0x48 */
    __IO uint32_t VPU_VINT_ENABLE_CONTROL_REG;       /**< VPU Interrupt Enable, offset: 0x48 */
    __IO uint32_t VPU_VINT_ENABLE_CONTROL_REG_VM;    /**< VPU Interrupt Enable, offset: 0x48 */
  };
  union {                                          /* offset: 0x4C */
    __IO uint32_t VPU_VINT_REASON_CONTROL_REG;       /**< VPU Interrupt Reason, offset: 0x4C */
    __IO uint32_t VPU_VINT_REASON_CONTROL_REG_VM;    /**< VPU Interrupt Reason, offset: 0x4C */
  };
  union {                                          /* offset: 0x50 */
    __IO uint32_t VPU_RESET_REQ_CONTROL_REG;         /**< VPU Reset Request, offset: 0x50 */
    __I  uint32_t VPU_RESET_REQ_CONTROL_REG_VM;      /**< VPU Reset Request, offset: 0x50 */
  };
  union {                                          /* offset: 0x54 */
    __I  uint32_t VPU_RESET_STATUS_CONTROL_REG;      /**< VPU Reset Status, offset: 0x54 */
    __I  uint32_t VPU_RESET_STATUS_CONTROL_REG_VM;   /**< VPU Reset Status, offset: 0x54 */
  };
  __O  uint32_t VCPU_RESTART_CONTROL_REG;          /**< V-CPU Restart Request, offset: 0x58 */
  union {                                          /* offset: 0x5C */
    __IO uint32_t VPU_CLK_MASK_CONTROL_REG;          /**< VPU Clock Control, offset: 0x5C */
    __I  uint32_t VPU_CLK_MASK_CONTROL_REG_VM;       /**< VPU Clock Control, offset: 0x5C */
  };
  union {                                          /* offset: 0x60 */
    __IO uint32_t VPU_REMAP_CTRL_CONTROL_REG;        /**< Remap Control, offset: 0x60 */
    __I  uint32_t VPU_REMAP_CTRL_CONTROL_REG_VM;     /**< Remap Control, offset: 0x60 */
  };
  union {                                          /* offset: 0x64 */
    __IO uint32_t VPU_REMAP_VADDR_CONTROL_REG;       /**< Remap Virutal Address, offset: 0x64 */
    __I  uint32_t VPU_REMAP_VADDR_CONTROL_REG_VM;    /**< Remap Virutal Address, offset: 0x64 */
  };
  union {                                          /* offset: 0x68 */
    __IO uint32_t VPU_REMAP_PADDR_CONTROL_REG;       /**< Remap Physical Address, offset: 0x68 */
    __I  uint32_t VPU_REMAP_PADDR_CONTROL_REG_VM;    /**< Remap Physical Address, offset: 0x68 */
  };
  union {                                          /* offset: 0x6C */
    __IO uint32_t VPU_REMAP_CORE_START_CONTROL_REG;   /**< VPU Start Request, offset: 0x6C */
    __I  uint32_t VPU_REMAP_CORE_START_CONTROL_REG_VM;   /**< VPU Start Request, offset: 0x6C */
  };
  union {                                          /* offset: 0x70 */
    __IO uint32_t VPU_BUSY_STATUS_CONTROL_REG;       /**< VPU Busy Status, offset: 0x70 */
    __IO uint32_t VPU_BUSY_STATUS_CONTROL_REG_VM;    /**< VPU Busy Status, offset: 0x70 */
  };
  union {                                          /* offset: 0x74 */
    __I  uint32_t VPU_HALT_STATUS_CONTROL_REG;       /**< VPU Halt Status, offset: 0x74 */
    __I  uint32_t VPU_HALT_STATUS_CONTROL_REG_VM;    /**< VPU Halt Status, offset: 0x74 */
  };
  union {                                          /* offset: 0x78 */
    __I  uint32_t VPU_VCPU_STATUS_CONTROL_REG;       /**< VPU_VCPU_STATUS, offset: 0x78 */
    __I  uint32_t VPU_VCPU_STATUS_CONTROL_REG_VM;    /**< VPU_VCPU_STATUS, offset: 0x78 */
  };
       uint8_t RESERVED_1[4];
  union {                                          /* offset: 0x80 */
    __I  uint32_t RET_FIO_STATUS_CONTROL_REG;        /**< RET_FIO_STATUS, offset: 0x80 */
    __I  uint32_t RET_FIO_STATUS_CONTROL_REG_VM;     /**< RET_FIO_STATUS, offset: 0x80 */
  };
       uint8_t RESERVED_2[12];
  union {                                          /* offset: 0x90 */
    __I  uint32_t RET_PRODUCT_NAME_CONTROL_REG;      /**< HW product name, offset: 0x90 */
    __I  uint32_t RET_PRODUCT_NAME_CONTROL_REG_VM;   /**< HW product name, offset: 0x90 */
  };
  union {                                          /* offset: 0x94 */
    __I  uint32_t RET_PRODUCT_VERSION_CONTROL_REG;   /**< HW product version, offset: 0x94 */
    __I  uint32_t RET_PRODUCT_VERSION_CONTROL_REG_VM;   /**< HW product version, offset: 0x94 */
  };
  union {                                          /* offset: 0x98 */
    __I  uint32_t RET_VCPU_CONFIG0_CONTROL_REG;      /**< Configuration Information #0, offset: 0x98 */
    __I  uint32_t RET_VCPU_CONFIG0_CONTROL_REG_VM;   /**< Configuration Information #0, offset: 0x98 */
  };
  union {                                          /* offset: 0x9C */
    __I  uint32_t RET_VCPU_CONFIG1_CONTROL_REG;      /**< Configuration Information #1, offset: 0x9C */
    __I  uint32_t RET_VCPU_CONFIG1_CONTROL_REG_VM;   /**< Configuration Information #1, offset: 0x9C */
  };
  union {                                          /* offset: 0xA0 */
    __I  uint32_t RET_CODEC_STD_CONTROL_REG;         /**< Standard Definition, offset: 0xA0 */
    __I  uint32_t RET_CODEC_STD_CONTROL_REG_VM;      /**< Standard Definition, offset: 0xA0 */
  };
  union {                                          /* offset: 0xA4 */
    __I  uint32_t RET_CONF_DATE_CONTROL_REG;         /**< Configuration Date, offset: 0xA4 */
    __I  uint32_t RET_CONF_DATE_CONTROL_REG_VM;      /**< Configuration Date, offset: 0xA4 */
  };
  union {                                          /* offset: 0xA8 */
    __I  uint32_t RET_CONF_REVISION_CONTROL_REG;     /**< The revision of H/W configuration, offset: 0xA8 */
    __I  uint32_t RET_CONF_REVISION_CONTROL_REG_VM;   /**< The revision of H/W configuration, offset: 0xA8 */
  };
  union {                                          /* offset: 0xAC */
    __I  uint32_t RET_CONF_TYPE_CONTROL_REG;         /**< The define value of H/W configuration, offset: 0xAC */
    __I  uint32_t RET_CONF_TYPE_CONTROL_REG_VM;      /**< The define value of H/W configuration, offset: 0xAC */
  };
  union {                                          /* offset: 0xB0 */
    __I  uint32_t RET_VCORE0_CFG_CONTROL_REG;        /**< Configuration Information of VCORE0, offset: 0xB0 */
    __I  uint32_t RET_VCORE0_CFG_CONTROL_REG_VM;     /**< Configuration Information of VCORE0, offset: 0xB0 */
  };
  union {                                          /* offset: 0xB4 */
    __I  uint32_t RET_VCORE1_CFG_CONTROL_REG;        /**< Configuration Information of VCORE1, offset: 0xB4 */
    __I  uint32_t RET_VCORE1_CFG_CONTROL_REG_VM;     /**< Configuration Information of VCORE1, offset: 0xB4 */
  };
  union {                                          /* offset: 0xB8 */
    __I  uint32_t RET_VCORE2_CFG_CONTROL_REG;        /**< Configuration Information of VCORE2, offset: 0xB8 */
    __I  uint32_t RET_VCORE2_CFG_CONTROL_REG_VM;     /**< Configuration Information of VCORE2, offset: 0xB8 */
  };
  union {                                          /* offset: 0xBC */
    __I  uint32_t VPU_CMD_BUSY_STATUS_V_CONTROL_REG;   /**< Command busy status, offset: 0xBC */
    __I  uint32_t VPU_CMD_BUSY_STATUS_V_CONTROL_REG_VM;   /**< Command busy status, offset: 0xBC */
  };
  union {                                          /* offset: 0xC0 */
    __I  uint32_t VPU_RET_VCORE_PRESET_CONTROL_REG;   /**< Number of VCOREs present, offset: 0xC0 */
    __I  uint32_t VPU_RET_VCORE_PRESET_CONTROL_REG_VM;   /**< Number of VCOREs present, offset: 0xC0 */
  };
       uint8_t RESERVED_3[44];
  union {                                          /* offset: 0xF0 */
    __IO uint32_t VPU_DBG_SW_UART_STATUS_CONTROL_REG;   /**< VPU_dbg_sw_uart_status, offset: 0xF0 */
    __IO uint32_t VPU_DBG_SW_UART_STATUS_CONTROL_REG_VM;   /**< VPU_dbg_sw_uart_status, offset: 0xF0 */
  };
  union {                                          /* offset: 0xF4 */
    __IO uint32_t VPU_DBG_SW_UART_TX_CONTROL_REG;    /**< VPU_ dbg_sw_uart_tx, offset: 0xF4 */
    __IO uint32_t VPU_DBG_SW_UART_TX_CONTROL_REG_VM;   /**< VPU_ dbg_sw_uart_tx, offset: 0xF4 */
  };
  union {                                          /* offset: 0xF8 */
    __IO uint32_t VPU_REQUIRE_WORK_BUF_ADDR_CONTROL_REG;   /**< Work buffer base address, offset: 0xF8 */
    __IO uint32_t VPU_REQUIRE_WORK_BUF_ADDR_CONTROL_REG_VM;   /**< Work buffer base address, offset: 0xF8 */
  };
  union {                                          /* offset: 0xFC */
    __IO uint32_t VPU_REQUIRE_WORK_BUF_SIZE_CONTROL_REG;   /**< Work buffer size, offset: 0xFC */
    __IO uint32_t VPU_REQUIRE_WORK_BUF_SIZE_CONTROL_REG_VM;   /**< Work buffer size, offset: 0xFC */
  };
  __IO uint32_t COMMAND;                           /**< Command, offset: 0x100 */
  union {                                          /* offset: 0x104 */
    __IO uint32_t CMD_DEC_PIC_OPTION;                /**< Run command option, offset: 0x104 */
    __IO uint32_t CMD_INIT_SEQ_OPTION;               /**< Run command option, offset: 0x104 */
    __IO uint32_t CMD_OPTION;                        /**< Command Option, offset: 0x104 */
    __IO uint32_t CMD_QUERY_OPTION;                  /**< QUERY command option, offset: 0x104 */
    __IO uint32_t CMD_QUERY_OPTION_QUERY_GET_BS_RD_PTR;   /**< QUERY command option, offset: 0x104 */
    __IO uint32_t CMD_QUERY_OPTION_QUERY_GET_BW_RESULT;   /**< QUERY command option, offset: 0x104 */
    __IO uint32_t CMD_QUERY_OPTION_QUERY_GET_PF_RESULT;   /**< QUERY command option, offset: 0x104 */
    __IO uint32_t CMD_QUERY_OPTION_QUERY_GET_RESULT_DEC;   /**< Run command option, offset: 0x104 */
    __IO uint32_t CMD_QUERY_OPTION_QUERY_SET_BS_RD_PTR;   /**< QUERY command option, offset: 0x104 */
    __IO uint32_t CMD_QUERY_OPTION_QUERY_UPDATE_DISP_IDC;   /**< Run command option, offset: 0x104 */
    __IO uint32_t CMD_SET_FB_OPTION;                 /**< Run command option, offset: 0x104 */
    __IO uint32_t CMD_SET_FB_OPTION_SET_FB_DEC;      /**< Run command option, offset: 0x104 */
  };
  __IO uint32_t RET_SUCCESS;                       /**< Result of the command, offset: 0x108 */
  __IO uint32_t RET_FAIL_REASON;                   /**< Fail reason of the run command, offset: 0x10C */
  union {                                          /* offset: 0x110 */
    __IO uint32_t ADDR_CODE_BASE;                    /**< Code buffer base address, offset: 0x110 */
    __IO uint32_t CMD_INSTANCE_INFO;                 /**< Instance information, offset: 0x110 */
    __IO uint32_t CMD_WAKEUP_ADDR_CODE_BASE;         /**< Code buffer base address, offset: 0x110 */
    __I  uint32_t RET_DETAIL_REASON;                 /**< host command detail fail reason, offset: 0x110 */
    __I  uint32_t RET_DETAIL_REASON_DEC_PIC;         /**< host command detail fail reason, offset: 0x110 */
  };
  union {                                          /* offset: 0x114 */
    __IO uint32_t CMD_DEC_ADDR_USERDATA_BASE;        /**< User Data Buffer Base Address, offset: 0x114 */
    __IO uint32_t CMD_WAKEUP_CODE_SIZE;              /**< Code buffer size, offset: 0x114 */
    __IO uint32_t CODE_SIZE;                         /**< Code buffer size, offset: 0x114 */
  };
  union {                                          /* offset: 0x118 */
    __IO uint32_t CMD_BS_RD_PTR;                     /**< Bistream buffer read pointer, offset: 0x118 */
    __IO uint32_t CMD_BS_RD_PTR_DEC_PIC;             /**< Bistream Buffer Read Pointer, offset: 0x118 */
    __IO uint32_t CMD_DEC_USERDATA_SIZE;             /**< User Data Buffer Size, offset: 0x118 */
    __IO uint32_t CMD_QUERY_DEC_SET_DISP_IDC;        /**< CMD_QUERY_DEC_SET_DISP_IDC, offset: 0x118 */
    __IO uint32_t CMD_SET_FB_COMMON_PIC_INFO;        /**< DPB Information, offset: 0x118 */
    __IO uint32_t CMD_SET_FB_STRIDE;                 /**< DPB Information, offset: 0x118 */
    __IO uint32_t CMD_WAKEUP_CODE_PARAM;             /**< Code buffer parameter, offset: 0x118 */
    __IO uint32_t CODE_PARAM;                        /**< Code buffer parameters, offset: 0x118 */
    __I  uint32_t RET_QUERY_BW_PRP_AXI_READ;         /**< PRP AXI read bandwidth, offset: 0x118 */
    __I  uint32_t RET_QUERY_FW_VERSION;              /**< Firmware Version, offset: 0x118 */
    __I  uint32_t RET_QUERY_PF_CMD_IDX;              /**< host cmd order idx, offset: 0x118 */
  };
  union {                                          /* offset: 0x11C */
    __IO uint32_t CMD_BS_WR_PTR;                     /**< Bistream buffer write pointer, offset: 0x11C */
    __IO uint32_t CMD_BS_WR_PTR_DEC_PIC;             /**< Bistream Buffer Write Pointer, offset: 0x11C */
    __IO uint32_t CMD_BS_WR_PTR_UPDATE_BS_DEC;       /**< Bitstream buffer write pointer, offset: 0x11C */
    __IO uint32_t CMD_CREATE_INST_BS_START_ADDR;     /**< Bitstream buffer start address, offset: 0x11C */
    __IO uint32_t CMD_DEC_USERDATA_PARAM;            /**< User Data Buffer Parameter, offset: 0x11C */
    __IO uint32_t CMD_QUERY_DEC_CLR_DISP_IDC;        /**< CMD_QUERY_DEC_CLR_DISP_IDC, offset: 0x11C */
    __IO uint32_t CMD_SET_FB_PIC_SIZE;               /**< Decoded Picture Size, offset: 0x11C */
    __IO uint32_t CMD_SET_FB_PIC_SIZE_SET_FB_DEC;    /**< Decoded Picture Size, offset: 0x11C */
    __IO uint32_t CMD_VLC_BASE;                      /**< Update VLC buffer base address, offset: 0x11C */
    __IO uint32_t CMD_WAKEUP_ADDR_TEMP_BASE;         /**< Temporal buffer base address, offset: 0x11C */
    __I  uint32_t RET_QUERY_BW_PRP_AXI_WRITE;        /**< PRP AXI write bandwidth, offset: 0x11C */
    __I  uint32_t RET_QUERY_DEC_BS_RD_PTR;           /**< Bitstream buffer read pointer, offset: 0x11C */
    __I  uint32_t RET_QUERY_ENC_BS_RD_PTR;           /**< The start position of bitstream buffer, offset: 0x11C */
    __I  uint32_t RET_QUERY_PF_HOST_CMD_TICK;        /**< Tick of host cmd, offset: 0x11C */
    __I  uint32_t RET_QUERY_PRODUCT_NAME;            /**< HW product name, offset: 0x11C */
    __I  uint32_t SET_QUERY_BS_RD_PTR;               /**< The start position of bitstream buffer, offset: 0x11C */
  };
  union {                                          /* offset: 0x120 */
    __IO uint32_t CMD_BS_OPTIONS;                    /**< Bistream buffer option, offset: 0x120 */
    __IO uint32_t CMD_BS_OPTIONS_DEC_PIC;            /**< Bistream buffer option, offset: 0x120 */
    __IO uint32_t CMD_BS_OPTIONS_UPDATE_BS_DEC;      /**< Bistream buffer option, offset: 0x120 */
    __IO uint32_t CMD_CREATE_INST_BS_SIZE;           /**< Bitstream buffer size, offset: 0x120 */
    __IO uint32_t CMD_SET_FB_INDICE;                 /**< DPB index to be updated, offset: 0x120 */
    __IO uint32_t CMD_SET_FB_NUM;                    /**< Set frame Number, offset: 0x120 */
    __IO uint32_t CMD_VLC_SIZE;                      /**< Update VLC buffer size, offset: 0x120 */
    __IO uint32_t CMD_WAKEUP_TEMP_SIZE;              /**< Temporal buffer size, offset: 0x120 */
    __I  uint32_t RET_QUERY_BW_FBD_Y_AXI_READ;       /**< FBD AXI read luma bandwidth, offset: 0x120 */
    __I  uint32_t RET_QUERY_DEC_SEQ_PARAM;           /**< Bitstream sequence parameter information, offset: 0x120 */
    __I  uint32_t RET_QUERY_PF_STG_0_START;          /**< Start tick of stage 0, offset: 0x120 */
    __I  uint32_t RET_QUERY_PRODUCT_VERSION;         /**< HW product version, offset: 0x120 */
  };
  union {                                          /* offset: 0x124 */
    __IO uint32_t CMD_CREATE_INST_BS_PARAM;          /**< Bitstream buffer parameter, offset: 0x124 */
    __IO uint32_t CMD_INIT_ADDR_SEC_AXI;             /**< Secondary AXI base address, offset: 0x124 */
    __IO uint32_t CMD_WAKEUP_ADDR_SEC_AXI;           /**< Secondary AXI base address, offset: 0x124 */
    __I  uint32_t RET_QUERY_BW_FBC_Y_AXI_WRITE;      /**< FBC AXI write luma bandwidth, offset: 0x124 */
    __I  uint32_t RET_QUERY_DEC_COLOR_SAMPLE_INFO;   /**< Color Sample Information, offset: 0x124 */
    __I  uint32_t RET_QUERY_PF_STG_0_END;            /**< End tick of stage 0, offset: 0x124 */
    __I  uint32_t RET_QUERY_STD_DEF0;                /**< Standard definition, offset: 0x124 */
  };
  union {                                          /* offset: 0x128 */
    __IO uint32_t CMD_INIT_SEC_AXI_SIZE;             /**< Seconary AXI memory size, offset: 0x128 */
    __IO uint32_t CMD_SEQ_CHANGE_ENABLE_FLAG;        /**< Sequence change flag, offset: 0x128 */
    __IO uint32_t CMD_WAKEUP_SEC_AXI_SIZE;           /**< Seconary AXI memory size, offset: 0x128 */
    __I  uint32_t RET_QUERY_BW_FBD_C_AXI_READ;       /**< FBD AXI read chroma bandwidth, offset: 0x128 */
    __I  uint32_t RET_QUERY_DEC_ASPECT_RATIO;        /**< Sample Aspect Ratio, offset: 0x128 */
    __I  uint32_t RET_QUERY_PF_STG_0_BLOCK_START;    /**< Blocking start tick of stage 0, offset: 0x128 */
    __I  uint32_t RET_QUERY_STD_DEF1;                /**< Standard definition, offset: 0x128 */
  };
  union {                                          /* offset: 0x12C */
    __IO uint32_t CMD_CREATE_INST_ADDR_TEMP_BASE;    /**< Temporal buffer base address, offset: 0x12C */
    __IO uint32_t CMD_DEC_SEI_MASK;                  /**< User Data Mask, offset: 0x12C */
    __IO uint32_t CMD_INIT_HW_OPTION;                /**< VPU hardware option, offset: 0x12C */
    __IO uint32_t CMD_WAKEUP_HW_OPTION;              /**< VPU hardware option, offset: 0x12C */
    __I  uint32_t RET_QUERY_BW_FBC_C_AXI_WRITE;      /**< FBC AXI write chroma bandwidth, offset: 0x12C */
    __I  uint32_t RET_QUERY_CONF_FEATURE;            /**< Configuration feature, offset: 0x12C */
    __I  uint32_t RET_QUERY_DEC_BIT_RATE;            /**< Maximum Bit Rate, offset: 0x12C */
    __I  uint32_t RET_QUERY_PF_STG_0_BLOCK_END;      /**< Blocking end tick of stage 0, offset: 0x12C */
  };
  union {                                          /* offset: 0x130 */
    __IO uint32_t CMD_CREATE_INST_TEMP_SIZE;         /**< Temporal buffer size, offset: 0x130 */
    __IO uint32_t CMD_DEC_TEMPORAL_ID_PLUS1;         /**< Max Decode Temporal ID, offset: 0x130 */
    __I  uint32_t RET_QUERY_BW_PRI_AXI_READ;         /**< Primary AXI read bandwidth, offset: 0x130 */
    __I  uint32_t RET_QUERY_CONF_DATE;               /**< Configuration date, offset: 0x130 */
    __I  uint32_t RET_QUERY_DEC_FRAME_RATE_NR;       /**< Frame Rate Numerator, offset: 0x130 */
    __I  uint32_t RET_QUERY_PF_STG_1_START;          /**< Start tick of stage 1, offset: 0x130 */
  };
  union {                                          /* offset: 0x134 */
    __IO uint32_t CMD_DEC_FORCE_FB_LATENCY_PLUS1;    /**< User define display latency, offset: 0x134 */
    __IO uint32_t CMD_SET_FB_ADDR_LUMA_BASE;         /**< Luma base of BWB idx to be update, offset: 0x134 */
    __IO uint32_t CMD_SET_FB_ADDR_LUMA_BASE0;        /**< Luma base address of DPB index 0, offset: 0x134 */
    __I  uint32_t RET_QUERY_BW_PRI_AXI_WRITE;        /**< Primary AXI write bandwidth, offset: 0x134 */
    __I  uint32_t RET_QUERY_CONF_REVISION;           /**< The revision of H/W configuration, offset: 0x134 */
    __I  uint32_t RET_QUERY_DEC_FRAME_RATE_DR;       /**< Frame Rate Denominator, offset: 0x134 */
    __I  uint32_t RET_QUERY_PF_STG_1_END;            /**< End tick of stage 1, offset: 0x134 */
  };
  union {                                          /* offset: 0x138 */
    __IO uint32_t CMD_CREATE_INST_EXT_ADDR;          /**< Ext address for instance, offset: 0x138 */
    __IO uint32_t CMD_SET_FB_ADDR_CB_BASE;           /**< Cb base of BWB idx to be update, offset: 0x138 */
    __IO uint32_t CMD_SET_FB_ADDR_CB_BASE0;          /**< Cb base address of DPB index 0, offset: 0x138 */
    __I  uint32_t RET_QUERY_BW_SEC_AXI_READ;         /**< Secondary AXI read bandwidth, offset: 0x138 */
    __I  uint32_t RET_QUERY_CONF_TYPE;               /**< The define value of H/W configuration, offset: 0x138 */
    __I  uint32_t RET_QUERY_DEC_NUM_REQURED_FB;      /**< Required Number of Minimum DPB, offset: 0x138 */
    __I  uint32_t RET_QUERY_PF_STG_1_BLOCK_START;    /**< Blocking start tick of stage 1, offset: 0x138 */
  };
  union {                                          /* offset: 0x13C */
    __IO uint32_t CMD_CREATE_INST_NUM_CQ_DEPTH_M1;   /**< Number of CQ depth_minus1, offset: 0x13C */
    __IO uint32_t CMD_SET_FB_ADDR_CR_BASE;           /**< Cr base of BWB idx to be update, offset: 0x13C */
    __IO uint32_t CMD_SET_FB_ADDR_CR_BASE0;          /**< Cr base address of DPB index 0, offset: 0x13C */
    __IO uint32_t CMD_SET_FB_ADDR_FBC_Y_OFFSET0;     /**< Compressed luma offset base address of DPB index 0, offset: 0x13C */
    __I  uint32_t RET_QUERY_BW_SEC_AXI_WRITE;        /**< Secondary AXI write bandwidth, offset: 0x13C */
    __I  uint32_t RET_QUERY_DEC_NUM_REORDER_DELAY;   /**< Reorder frame number, offset: 0x13C */
    __I  uint32_t RET_QUERY_PF_STG_1_BLOCK_END;      /**< Blocking end tick of stage 1, offset: 0x13C */
    __I  uint32_t RET_QUERY_PRODUCT_ID;              /**< The product ID, offset: 0x13C */
  };
  union {                                          /* offset: 0x140 */
    __IO uint32_t CMD_SET_FB_ADDR_FBC_C_OFFSET0;     /**< Compressed chroma offset base address of DPB index 0, offset: 0x140 */
    __IO uint32_t CMD_SET_FB_ADDR_MV_COL;            /**< Colocated mv buffer base of MvCol idx to be update, offset: 0x140 */
    __I  uint32_t RET_QUERY_BW_PROC_AXI_READ;        /**< Proc AXI read bandwidth, offset: 0x140 */
    __I  uint32_t RET_QUERY_CUSTOMER_ID;             /**< The customer ID, offset: 0x140 */
    __IO uint32_t RET_QUERY_DEC_SUB_LAYER_INFO;      /**< Sub-layer information, offset: 0x140 */
    __I  uint32_t RET_QUERY_PF_STG_2_START;          /**< Start tick of stage 2, offset: 0x140 */
  };
  union {                                          /* offset: 0x144 */
    __IO uint32_t CMD_SET_FB_ADDR_FBC_Y_BASE;        /**< FBC luma base of FBC idx to be update, offset: 0x144 */
    __IO uint32_t CMD_SET_FB_ADDR_LUMA_BASE1;        /**< Luma base address of DPB index 1, offset: 0x144 */
    __I  uint32_t RET_QUERY_BW_PROC_AXI_WRITE;       /**< Proc AXI write bandwidth, offset: 0x144 */
    __IO uint32_t RET_QUERY_DEC_NOTIFICATION;        /**< Sequence change flag, offset: 0x144 */
    __I  uint32_t RET_QUERY_PF_STG_2_END;            /**< End tick of stage 2, offset: 0x144 */
  };
  union {                                          /* offset: 0x148 */
    __IO uint32_t CMD_SET_FB_ADDR_CB_BASE1;          /**< Cb base address of DPB index 1, offset: 0x148 */
    __IO uint32_t CMD_SET_FB_ADDR_FBC_C_BASE;        /**< FBC chroma base of FBC idx to be update, offset: 0x148 */
    __I  uint32_t RET_QUERY_BW_BWB_AXI_WRITE;        /**< BWB AXI write bandwidth, offset: 0x148 */
    __I  uint32_t RET_QUERY_DEC_USERDATA_IDC;        /**< User data flag, offset: 0x148 */
    __I  uint32_t RET_QUERY_PF_STG_2_BLOCK_START;    /**< Blocking start tick of stage 2, offset: 0x148 */
  };
  union {                                          /* offset: 0x14C */
    __O  uint32_t CMD_QUERY_BW_OPTION;               /**< bandwidth selection, offset: 0x14C */
    __IO uint32_t CMD_SET_FB_ADDR_CR_BASE1;          /**< Cr base address of DPB index 1, offset: 0x14C */
    __IO uint32_t CMD_SET_FB_ADDR_FBC_Y_OFFSET;      /**< FBC luma offset base of FBC idx to be update, offset: 0x14C */
    __IO uint32_t CMD_SET_FB_ADDR_FBC_Y_OFFSET1;     /**< Compressed luma offset base address of DPB index 1, offset: 0x14C */
    __I  uint32_t RET_QUERY_DEC_PIC_SIZE;            /**< Decoded Picture Size, offset: 0x14C */
    __I  uint32_t RET_QUERY_PF_STG_2_BLOCK_END;      /**< Blocking end tick of stage 2, offset: 0x14C */
  };
  union {                                          /* offset: 0x150 */
    __IO uint32_t CMD_DEC_USE_SEC_AXI;               /**< Secondary AXI Usage, offset: 0x150 */
    __IO uint32_t CMD_SET_FB_ADDR_FBC_C_OFFSET;      /**< FBC chroma offset base of FBC idx to be update, offset: 0x150 */
    __IO uint32_t CMD_SET_FB_ADDR_FBC_C_OFFSET1;     /**< Compressed chroma offset base address of DPB index 1, offset: 0x150 */
    __I  uint32_t RET_QUERY_DEC_CROP_TOP_BOTTOM;     /**< Display Crop Offset Top/Bottom, offset: 0x150 */
    __I  uint32_t RET_QUERY_PF_STG_0_BLOCK_TICK;     /**< Blocking tick of stage 0, offset: 0x150 */
  };
  union {                                          /* offset: 0x154 */
    __IO uint32_t CMD_DEC_SCALE_SIZE;                /**< Scaled picture size, offset: 0x154 */
    __IO uint32_t CMD_SET_FB_ADDR_LUMA_BASE2;        /**< Luma base address of DPB index 2, offset: 0x154 */
    __I  uint32_t RET_QUERY_DEC_CROP_LEFT_RIGHT;     /**< Display Crop Offset Left/Right, offset: 0x154 */
    __I  uint32_t RET_QUERY_PF_STG_1_BLOCK_TICK;     /**< Blocking tick of stage 1, offset: 0x154 */
  };
  union {                                          /* offset: 0x158 */
    __IO uint32_t CMD_SET_FB_ADDR_CB_BASE2;          /**< Cb base address of DPB index 2, offset: 0x158 */
    __I  uint32_t RET_QUERY_DEC_AU_START_POS;        /**< AU Bitstream Start Position, offset: 0x158 */
    __I  uint32_t RET_QUERY_PF_STG_2_BLOCK_TICK;     /**< Blocking tick of stage 2, offset: 0x158 */
  };
  union {                                          /* offset: 0x15C */
    __IO uint32_t CMD_SET_FB_ADDR_CR_BASE2;          /**< Cr base address of DPB index 2, offset: 0x15C */
    __IO uint32_t CMD_SET_FB_ADDR_FBC_Y_OFFSET2;     /**< Compressed luma offset base address of DPB index 2, offset: 0x15C */
    __I  uint32_t RET_QUERY_DEC_AU_END_POS;          /**< AU Bitstream End Position, offset: 0x15C */
    __I  uint32_t RET_QUERY_PF_PIC_DONE_TICK;        /**< Pic done interrupt tick, offset: 0x15C */
  };
  union {                                          /* offset: 0x160 */
    __IO uint32_t CMD_SET_FB_ADDR_FBC_C_OFFSET2;     /**< Compressed chroma offset base address of DPB index 2, offset: 0x160 */
    __I  uint32_t RET_QUERY_DEC_PIC_TYPE;            /**< Decoded picture type, offset: 0x160 */
  };
  union {                                          /* offset: 0x164 */
    __IO uint32_t CMD_SET_FB_ADDR_LUMA_BASE3;        /**< Luma base address of DPB index 3, offset: 0x164 */
    __I  uint32_t RET_QUERY_DEC_PIC_POC;             /**< Picture Order Count, offset: 0x164 */
  };
  union {                                          /* offset: 0x168 */
    __IO uint32_t CMD_SET_FB_ADDR_CB_BASE3;          /**< Cb base address of DPB index 3, offset: 0x168 */
    __I  uint32_t RET_QUERY_DEC_RECOVERY_POINT;      /**< Recovery point, offset: 0x168 */
  };
  union {                                          /* offset: 0x16C */
    __IO uint32_t CMD_SET_FB_ADDR_CR_BASE3;          /**< Cr base address of DPB index 3, offset: 0x16C */
    __IO uint32_t CMD_SET_FB_ADDR_FBC_Y_OFFSET3;     /**< Compressed luma offset base address of DPB index 3, offset: 0x16C */
    __I  uint32_t RET_QUERY_DEC_DEBUG_INDEX;         /**< FBC and BWB frame buffer index for internal use, offset: 0x16C */
  };
  union {                                          /* offset: 0x170 */
    __IO uint32_t CMD_SET_FB_ADDR_FBC_C_OFFSET3;     /**< Compressed chroma offset base address of DPB index 3, offset: 0x170 */
    __I  uint32_t RET_QUERY_DEC_DECODED_INDEX;       /**< Decoded picture index of DPB, offset: 0x170 */
  };
  union {                                          /* offset: 0x174 */
    __IO uint32_t CMD_SET_FB_ADDR_LUMA_BASE4;        /**< Luma base address of DPB index 4, offset: 0x174 */
    __I  uint32_t RET_QUERY_DEC_DISPLAY_INDEX;       /**< Display picture index of DPB, offset: 0x174 */
  };
  union {                                          /* offset: 0x178 */
    __IO uint32_t CMD_SET_FB_ADDR_CB_BASE4;          /**< Cb base address of DPB index 4, offset: 0x178 */
    __I  uint32_t RET_QUERY_DEC_REALLOC_INDEX;       /**< Display picture index of DPB, offset: 0x178 */
  };
  union {                                          /* offset: 0x17C */
    __IO uint32_t CMD_SET_FB_ADDR_CR_BASE4;          /**< Cr base address of DPB index 4, offset: 0x17C */
    __IO uint32_t CMD_SET_FB_ADDR_FBC_Y_OFFSET4;     /**< Compressed luma offset base address of DPB index 4, offset: 0x17C */
    __I  uint32_t RET_QUERY_DEC_DISP_IDC;            /**< Display flag, offset: 0x17C */
    __IO uint32_t RET_QUERY_DEC_DISP_IDC_QUERY_UPDATE_DISP_IDC;   /**< RET_QUERY_DEC_DISP_IDC, offset: 0x17C */
  };
  union {                                          /* offset: 0x180 */
    __IO uint32_t CMD_SET_FB_ADDR_FBC_C_OFFSET4;     /**< Compressed chroma offset base address of DPB index 4, offset: 0x180 */
    __I  uint32_t RET_QUERY_DEC_NUM_ERR_CTB;         /**< Number of error CTU, offset: 0x180 */
  };
  union {                                          /* offset: 0x184 */
    __IO uint32_t CMD_SET_FB_ADDR_LUMA_BASE5;        /**< Luma base address of DPB index 5, offset: 0x184 */
    __IO uint32_t RET_QUERY_VLC_BASE;                /**< Base address of VLC buffer, offset: 0x184 */
  };
  union {                                          /* offset: 0x188 */
    __IO uint32_t CMD_SET_FB_ADDR_CB_BASE5;          /**< Cb base address of DPB index 5, offset: 0x188 */
    __IO uint32_t RET_QUERY_LINEAR_Y_BASE;           /**< Luma display frame buffer address, offset: 0x188 */
  };
  union {                                          /* offset: 0x18C */
    __IO uint32_t CMD_SET_FB_ADDR_CR_BASE5;          /**< Cr base address of DPB index 5, offset: 0x18C */
    __IO uint32_t CMD_SET_FB_ADDR_FBC_Y_OFFSET5;     /**< Compressed luma offset base address of DPB index 5, offset: 0x18C */
    __IO uint32_t RET_QUERY_LINEAR_CB_BASE;          /**< Cb display frame buffer address, offset: 0x18C */
  };
  union {                                          /* offset: 0x190 */
    __IO uint32_t CMD_SET_FB_ADDR_FBC_C_OFFSET5;     /**< Compressed chroma offset base address of DPB index 5, offset: 0x190 */
    __IO uint32_t RET_QUERY_LINEAR_CR_BASE;          /**< Cr display frame buffer address, offset: 0x190 */
  };
  union {                                          /* offset: 0x194 */
    __IO uint32_t CMD_DEC_VCORE_INFO;                /**< VCORE information, offset: 0x194 */
    __IO uint32_t CMD_SET_FB_ADDR_LUMA_BASE6;        /**< Luma base address of DPB index 6, offset: 0x194 */
    __IO uint32_t RET_QUERY_INPLACE_Y_BASE;          /**< Inplace ring buffer luma base address, offset: 0x194 */
  };
  union {                                          /* offset: 0x198 */
    __IO uint32_t CMD_SET_FB_ADDR_CB_BASE6;          /**< Cb base address of DPB index 6, offset: 0x198 */
    __IO uint32_t RET_QUERY_INPLACE_C_BASE;          /**< Inplace ring buffer chroma base address, offset: 0x198 */
  };
  union {                                          /* offset: 0x19C */
    __IO uint32_t CMD_SET_FB_ADDR_CR_BASE6;          /**< Cr base address of DPB index 6, offset: 0x19C */
    __IO uint32_t CMD_SET_FB_ADDR_FBC_Y_OFFSET6;     /**< Compressed luma offset base address of DPB index 6, offset: 0x19C */
    __I  uint32_t RET_QUERY_CORE_IDC;                /**< Core_IDC, offset: 0x19C */
  };
  union {                                          /* offset: 0x1A0 */
    __IO uint32_t CMD_SET_FB_ADDR_FBC_C_OFFSET6;     /**< Compressed chroma offset base address of DPB index 6, offset: 0x1A0 */
    __I  uint32_t RET_QUERY_DEC_PIC_PARAM;           /**< Bitstream sequence/pic parameter information, offset: 0x1A0 */
  };
  __IO uint32_t CMD_SET_FB_ADDR_LUMA_BASE7;        /**< Luma base address of DPB index 7, offset: 0x1A4 */
  __IO uint32_t CMD_SET_FB_ADDR_CB_BASE7;          /**< Cb base address of DPB index 7, offset: 0x1A8 */
  union {                                          /* offset: 0x1AC */
    __IO uint32_t CMD_SET_FB_ADDR_CR_BASE7;          /**< Cr base address of DPB index 7, offset: 0x1AC */
    __IO uint32_t CMD_SET_FB_ADDR_FBC_Y_OFFSET7;     /**< Compressed luma offset base address of DPB index 7, offset: 0x1AC */
  };
  union {                                          /* offset: 0x1B0 */
    __IO uint32_t CMD_SET_FB_ADDR_FBC_C_OFFSET7;     /**< Compressed chroma offset base address of DPB index 7, offset: 0x1B0 */
    __I  uint32_t RET_QUERY_DEC_VLC_BUF_SIZE;        /**< The size of a VLC buffer, offset: 0x1B0 */
  };
  union {                                          /* offset: 0x1B4 */
    __IO uint32_t CMD_SET_FB_ADDR_MV_COL0;           /**< Colocated MV buffer base of DPB index 0, offset: 0x1B4 */
    __I  uint32_t RET_QUERY_DEC_PARAM_BUF_SIZE;      /**< The size of a parameter buffer, offset: 0x1B4 */
  };
  union {                                          /* offset: 0x1B8 */
    __IO uint32_t CMD_SET_FB_ADDR_MV_COL1;           /**< Colocated MV buffer base of DPB index 1, offset: 0x1B8 */
    __IO uint32_t RET_QUERY_HOST_CMD_TICK;           /**< Host cmd queue tick, offset: 0x1B8 */
  };
  union {                                          /* offset: 0x1BC */
    __IO uint32_t CMD_SET_FB_ADDR_MV_COL2;           /**< Colocated MV buffer base of DPB index 2, offset: 0x1BC */
    __IO uint32_t RET_QUERY_DEC_SEEK_START_TICK;     /**< Seek start tick, offset: 0x1BC */
  };
  union {                                          /* offset: 0x1C0 */
    __IO uint32_t CMD_SET_FB_ADDR_MV_COL3;           /**< Colocated MV buffer base of DPB index 3, offset: 0x1C0 */
    __IO uint32_t RET_QUERY_DEC_SEEK_END_TICK;       /**< Seek end tick, offset: 0x1C0 */
  };
  union {                                          /* offset: 0x1C4 */
    __IO uint32_t CMD_SET_FB_ADDR_MV_COL4;           /**< Colocated MV buffer base of DPB index 4, offset: 0x1C4 */
    __IO uint32_t RET_QUERY_DEC_PARSING_START_TICK;   /**< Parsing start tick, offset: 0x1C4 */
  };
  union {                                          /* offset: 0x1C8 */
    __IO uint32_t CMD_SET_FB_ADDR_MV_COL5;           /**< Colocated MV buffer base of DPB index 5, offset: 0x1C8 */
    __IO uint32_t RET_QUERY_DEC_PARSING_END_TICK;    /**< Parsing end tick, offset: 0x1C8 */
  };
  union {                                          /* offset: 0x1CC */
    __IO uint32_t CMD_SET_FB_ADDR_MV_COL6;           /**< Colocated MV buffer base of DPB index 6, offset: 0x1CC */
    __IO uint32_t RET_QUERY_DEC_DECODING_START_TICK;   /**< Decoding start tick, offset: 0x1CC */
  };
  union {                                          /* offset: 0x1D0 */
    __IO uint32_t CMD_SET_FB_ADDR_MV_COL7;           /**< Colocated MV buffer base of DPB index 7, offset: 0x1D0 */
    __IO uint32_t RET_QUERY_DEC_DECODING_END_TICK;   /**< Decoding end tick, offset: 0x1D0 */
  };
  __IO uint32_t RET_QUERY_DEC_WARN_INFO;           /**< Warning information, offset: 0x1D4 */
  __IO uint32_t RET_QUERY_DEC_ERR_INFO;            /**< Error information, offset: 0x1D8 */
  __IO uint32_t RET_QUERY_DEC_SUCCESS;             /**< Query result, offset: 0x1DC */
  __IO uint32_t RET_QUEUE_STATUS;                  /**< Queued command information, offset: 0x1E0 */
  __IO uint32_t RET_BS_EMPTY;                      /**< Bitstream buffer empty flag, offset: 0x1E4 */
  __IO uint32_t RET_QUEUED_CMD_DONE;               /**< Queued command done flag, offset: 0x1E8 */
  __IO uint32_t RET_SRC_RELEASE;                   /**< Flag for source buffer releasing, offset: 0x1EC */
  __IO uint32_t RET_PARSING_INSTANCE_INFO;         /**< A working instance index on prescan stage (for internal use only), offset: 0x1F0 */
  __IO uint32_t RET_DECODING_INSTANCE_INFO;        /**< A working instance index on decoding stage (for internal use only), offset: 0x1F4 */
  __IO uint32_t RET_ENCODING_INSTANCE_INFO;        /**< A working instance index on packing stage (for internal use only), offset: 0x1F8 */
  __IO uint32_t RET_DONE_INSTANCE_INFO;            /**< Done interrupt instance index, offset: 0x1FC */
       uint8_t RESERVED_4[3664];
  __IO uint32_t VPU_RESET_REQ;                     /**< VPU Reset Request, offset: 0x1050 */
  __I  uint32_t VPU_RESET_STATUS;                  /**< VPU Reset Status, offset: 0x1054 */
  __O  uint32_t VCPU_RESTART;                      /**< V-CPU Restart Request, offset: 0x1058 */
  __IO uint32_t VPU_CLK_MASK;                      /**< VPU Clock Control, offset: 0x105C */
  __IO uint32_t VPU_REMAP_CTRL;                    /**< Remap Control, offset: 0x1060 */
  __IO uint32_t VPU_REMAP_VADDR;                   /**< Remap Virutal Address, offset: 0x1064 */
  __IO uint32_t VPU_REMAP_PADDR;                   /**< Remap Physical Address, offset: 0x1068 */
  __IO uint32_t VPU_REMAP_CORE_START;              /**< VPU Start Request, offset: 0x106C */
  __IO uint32_t VPU_BUSY_STATUS;                   /**< VPU Busy Status, offset: 0x1070 */
       uint8_t RESERVED_5[144];
  __IO uint32_t VPU_GLOBAL_H_COMMAND;              /**< Global Command, offset: 0x1104 */
       uint8_t RESERVED_6[32008];
  __O  uint32_t BACKBONE_BUS_CTRL_VCORE;           /**< Backbone bus control register for VCORE, offset: 0x8E10 */
  __I  uint32_t BACKBONE_BUS_STATUS_VCORE;         /**< Backbone bus status register for VCORE, offset: 0x8E14 */
       uint8_t RESERVED_7[28664];
  __O  uint32_t BACKBONE_BUS_CTRL_VCPU;            /**< Backbone bus control register for VCPU, offset: 0xFE10 */
  __I  uint32_t BACKBONE_BUS_STATUS_VCPU;          /**< Backbone bus status register for VCPU, offset: 0xFE14 */
       uint8_t RESERVED_8[168];
  __IO uint32_t BACKBONE_BUS_PROC_EXT_ADDR;        /**< Backbone bus status register for VCPU, offset: 0xFEC0 */
} VPU_VPU_DEC_Type;

/* ----------------------------------------------------------------------------
   -- VPU_VPU_DEC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VPU_VPU_DEC_Register_Masks VPU_VPU_DEC Register Masks
 * @{
 */

/*! @name VPU_PO_CONF_CONTROL_REG - Power On Configurations */
/*! @{ */

#define VPU_VPU_DEC_VPU_PO_CONF_CONTROL_REG_DEBUGMODE_MASK (0x1U)
#define VPU_VPU_DEC_VPU_PO_CONF_CONTROL_REG_DEBUGMODE_SHIFT (0U)
#define VPU_VPU_DEC_VPU_PO_CONF_CONTROL_REG_DEBUGMODE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_PO_CONF_CONTROL_REG_DEBUGMODE_SHIFT)) & VPU_VPU_DEC_VPU_PO_CONF_CONTROL_REG_DEBUGMODE_MASK)

#define VPU_VPU_DEC_VPU_PO_CONF_CONTROL_REG_USE_PO_CONF_MASK (0x8U)
#define VPU_VPU_DEC_VPU_PO_CONF_CONTROL_REG_USE_PO_CONF_SHIFT (3U)
#define VPU_VPU_DEC_VPU_PO_CONF_CONTROL_REG_USE_PO_CONF(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_PO_CONF_CONTROL_REG_USE_PO_CONF_SHIFT)) & VPU_VPU_DEC_VPU_PO_CONF_CONTROL_REG_USE_PO_CONF_MASK)
/*! @} */

/*! @name VPU_PO_CONF_CONTROL_REG_VM - Power On Configurations */
/*! @{ */

#define VPU_VPU_DEC_VPU_PO_CONF_CONTROL_REG_VM_DEBUGMODE_MASK (0x1U)
#define VPU_VPU_DEC_VPU_PO_CONF_CONTROL_REG_VM_DEBUGMODE_SHIFT (0U)
#define VPU_VPU_DEC_VPU_PO_CONF_CONTROL_REG_VM_DEBUGMODE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_PO_CONF_CONTROL_REG_VM_DEBUGMODE_SHIFT)) & VPU_VPU_DEC_VPU_PO_CONF_CONTROL_REG_VM_DEBUGMODE_MASK)

#define VPU_VPU_DEC_VPU_PO_CONF_CONTROL_REG_VM_USE_PO_CONF_MASK (0x8U)
#define VPU_VPU_DEC_VPU_PO_CONF_CONTROL_REG_VM_USE_PO_CONF_SHIFT (3U)
#define VPU_VPU_DEC_VPU_PO_CONF_CONTROL_REG_VM_USE_PO_CONF(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_PO_CONF_CONTROL_REG_VM_USE_PO_CONF_SHIFT)) & VPU_VPU_DEC_VPU_PO_CONF_CONTROL_REG_VM_USE_PO_CONF_MASK)
/*! @} */

/*! @name VCPU_CUR_PC_CONTROL_REG - Current PC */
/*! @{ */

#define VPU_VPU_DEC_VCPU_CUR_PC_CONTROL_REG_CUR_PC_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_VCPU_CUR_PC_CONTROL_REG_CUR_PC_SHIFT (0U)
#define VPU_VPU_DEC_VCPU_CUR_PC_CONTROL_REG_CUR_PC(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VCPU_CUR_PC_CONTROL_REG_CUR_PC_SHIFT)) & VPU_VPU_DEC_VCPU_CUR_PC_CONTROL_REG_CUR_PC_MASK)
/*! @} */

/*! @name VCPU_CUR_PC_CONTROL_REG_VM - Current PC */
/*! @{ */

#define VPU_VPU_DEC_VCPU_CUR_PC_CONTROL_REG_VM_CUR_PC_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_VCPU_CUR_PC_CONTROL_REG_VM_CUR_PC_SHIFT (0U)
#define VPU_VPU_DEC_VCPU_CUR_PC_CONTROL_REG_VM_CUR_PC(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VCPU_CUR_PC_CONTROL_REG_VM_CUR_PC_SHIFT)) & VPU_VPU_DEC_VCPU_CUR_PC_CONTROL_REG_VM_CUR_PC_MASK)
/*! @} */

/*! @name VCPU_CUR_LR_CONTROL_REG - Current LR */
/*! @{ */

#define VPU_VPU_DEC_VCPU_CUR_LR_CONTROL_REG_CUR_LR_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_VCPU_CUR_LR_CONTROL_REG_CUR_LR_SHIFT (0U)
#define VPU_VPU_DEC_VCPU_CUR_LR_CONTROL_REG_CUR_LR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VCPU_CUR_LR_CONTROL_REG_CUR_LR_SHIFT)) & VPU_VPU_DEC_VCPU_CUR_LR_CONTROL_REG_CUR_LR_MASK)
/*! @} */

/*! @name VCPU_CUR_LR_CONTROL_REG_VM - Current LR */
/*! @{ */

#define VPU_VPU_DEC_VCPU_CUR_LR_CONTROL_REG_VM_CUR_LR_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_VCPU_CUR_LR_CONTROL_REG_VM_CUR_LR_SHIFT (0U)
#define VPU_VPU_DEC_VCPU_CUR_LR_CONTROL_REG_VM_CUR_LR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VCPU_CUR_LR_CONTROL_REG_VM_CUR_LR_SHIFT)) & VPU_VPU_DEC_VCPU_CUR_LR_CONTROL_REG_VM_CUR_LR_MASK)
/*! @} */

/*! @name VPU_PDBG_STEP_MASK_CONTROL_REG - V-CPU Debugger Step Mask */
/*! @{ */

#define VPU_VPU_DEC_VPU_PDBG_STEP_MASK_CONTROL_REG_STEP_MASK_ENABLE_MASK (0x1U)
#define VPU_VPU_DEC_VPU_PDBG_STEP_MASK_CONTROL_REG_STEP_MASK_ENABLE_SHIFT (0U)
#define VPU_VPU_DEC_VPU_PDBG_STEP_MASK_CONTROL_REG_STEP_MASK_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_PDBG_STEP_MASK_CONTROL_REG_STEP_MASK_ENABLE_SHIFT)) & VPU_VPU_DEC_VPU_PDBG_STEP_MASK_CONTROL_REG_STEP_MASK_ENABLE_MASK)
/*! @} */

/*! @name VPU_PDBG_STEP_MASK_CONTROL_REG_VM - V-CPU Debugger Step Mask */
/*! @{ */

#define VPU_VPU_DEC_VPU_PDBG_STEP_MASK_CONTROL_REG_VM_STEP_MASK_ENABLE_MASK (0x1U)
#define VPU_VPU_DEC_VPU_PDBG_STEP_MASK_CONTROL_REG_VM_STEP_MASK_ENABLE_SHIFT (0U)
#define VPU_VPU_DEC_VPU_PDBG_STEP_MASK_CONTROL_REG_VM_STEP_MASK_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_PDBG_STEP_MASK_CONTROL_REG_VM_STEP_MASK_ENABLE_SHIFT)) & VPU_VPU_DEC_VPU_PDBG_STEP_MASK_CONTROL_REG_VM_STEP_MASK_ENABLE_MASK)
/*! @} */

/*! @name VPU_PDBG_CTRL_CONTROL_REG - V-CPU Debugger Control */
/*! @{ */

#define VPU_VPU_DEC_VPU_PDBG_CTRL_CONTROL_REG_STEP_MASK (0x1U)
#define VPU_VPU_DEC_VPU_PDBG_CTRL_CONTROL_REG_STEP_SHIFT (0U)
#define VPU_VPU_DEC_VPU_PDBG_CTRL_CONTROL_REG_STEP(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_PDBG_CTRL_CONTROL_REG_STEP_SHIFT)) & VPU_VPU_DEC_VPU_PDBG_CTRL_CONTROL_REG_STEP_MASK)

#define VPU_VPU_DEC_VPU_PDBG_CTRL_CONTROL_REG_RESUME_MASK (0x2U)
#define VPU_VPU_DEC_VPU_PDBG_CTRL_CONTROL_REG_RESUME_SHIFT (1U)
#define VPU_VPU_DEC_VPU_PDBG_CTRL_CONTROL_REG_RESUME(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_PDBG_CTRL_CONTROL_REG_RESUME_SHIFT)) & VPU_VPU_DEC_VPU_PDBG_CTRL_CONTROL_REG_RESUME_MASK)

#define VPU_VPU_DEC_VPU_PDBG_CTRL_CONTROL_REG_STABLEBRK_MASK (0x4U)
#define VPU_VPU_DEC_VPU_PDBG_CTRL_CONTROL_REG_STABLEBRK_SHIFT (2U)
#define VPU_VPU_DEC_VPU_PDBG_CTRL_CONTROL_REG_STABLEBRK(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_PDBG_CTRL_CONTROL_REG_STABLEBRK_SHIFT)) & VPU_VPU_DEC_VPU_PDBG_CTRL_CONTROL_REG_STABLEBRK_MASK)

#define VPU_VPU_DEC_VPU_PDBG_CTRL_CONTROL_REG_IMMBRK_MASK (0x8U)
#define VPU_VPU_DEC_VPU_PDBG_CTRL_CONTROL_REG_IMMBRK_SHIFT (3U)
#define VPU_VPU_DEC_VPU_PDBG_CTRL_CONTROL_REG_IMMBRK(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_PDBG_CTRL_CONTROL_REG_IMMBRK_SHIFT)) & VPU_VPU_DEC_VPU_PDBG_CTRL_CONTROL_REG_IMMBRK_MASK)
/*! @} */

/*! @name VPU_PDBG_CTRL_CONTROL_REG_VM - V-CPU Debugger Control */
/*! @{ */

#define VPU_VPU_DEC_VPU_PDBG_CTRL_CONTROL_REG_VM_STEP_MASK (0x1U)
#define VPU_VPU_DEC_VPU_PDBG_CTRL_CONTROL_REG_VM_STEP_SHIFT (0U)
#define VPU_VPU_DEC_VPU_PDBG_CTRL_CONTROL_REG_VM_STEP(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_PDBG_CTRL_CONTROL_REG_VM_STEP_SHIFT)) & VPU_VPU_DEC_VPU_PDBG_CTRL_CONTROL_REG_VM_STEP_MASK)

#define VPU_VPU_DEC_VPU_PDBG_CTRL_CONTROL_REG_VM_RESUME_MASK (0x2U)
#define VPU_VPU_DEC_VPU_PDBG_CTRL_CONTROL_REG_VM_RESUME_SHIFT (1U)
#define VPU_VPU_DEC_VPU_PDBG_CTRL_CONTROL_REG_VM_RESUME(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_PDBG_CTRL_CONTROL_REG_VM_RESUME_SHIFT)) & VPU_VPU_DEC_VPU_PDBG_CTRL_CONTROL_REG_VM_RESUME_MASK)

#define VPU_VPU_DEC_VPU_PDBG_CTRL_CONTROL_REG_VM_STABLEBRK_MASK (0x4U)
#define VPU_VPU_DEC_VPU_PDBG_CTRL_CONTROL_REG_VM_STABLEBRK_SHIFT (2U)
#define VPU_VPU_DEC_VPU_PDBG_CTRL_CONTROL_REG_VM_STABLEBRK(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_PDBG_CTRL_CONTROL_REG_VM_STABLEBRK_SHIFT)) & VPU_VPU_DEC_VPU_PDBG_CTRL_CONTROL_REG_VM_STABLEBRK_MASK)

#define VPU_VPU_DEC_VPU_PDBG_CTRL_CONTROL_REG_VM_IMMBRK_MASK (0x8U)
#define VPU_VPU_DEC_VPU_PDBG_CTRL_CONTROL_REG_VM_IMMBRK_SHIFT (3U)
#define VPU_VPU_DEC_VPU_PDBG_CTRL_CONTROL_REG_VM_IMMBRK(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_PDBG_CTRL_CONTROL_REG_VM_IMMBRK_SHIFT)) & VPU_VPU_DEC_VPU_PDBG_CTRL_CONTROL_REG_VM_IMMBRK_MASK)
/*! @} */

/*! @name VPU_PDBG_IDX_REG_CONTROL_REG - V-CPU Debugger Index */
/*! @{ */

#define VPU_VPU_DEC_VPU_PDBG_IDX_REG_CONTROL_REG_DBGIDX_MASK (0xFFU)
#define VPU_VPU_DEC_VPU_PDBG_IDX_REG_CONTROL_REG_DBGIDX_SHIFT (0U)
#define VPU_VPU_DEC_VPU_PDBG_IDX_REG_CONTROL_REG_DBGIDX(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_PDBG_IDX_REG_CONTROL_REG_DBGIDX_SHIFT)) & VPU_VPU_DEC_VPU_PDBG_IDX_REG_CONTROL_REG_DBGIDX_MASK)

#define VPU_VPU_DEC_VPU_PDBG_IDX_REG_CONTROL_REG_WRDBG_MASK (0x100U)
#define VPU_VPU_DEC_VPU_PDBG_IDX_REG_CONTROL_REG_WRDBG_SHIFT (8U)
#define VPU_VPU_DEC_VPU_PDBG_IDX_REG_CONTROL_REG_WRDBG(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_PDBG_IDX_REG_CONTROL_REG_WRDBG_SHIFT)) & VPU_VPU_DEC_VPU_PDBG_IDX_REG_CONTROL_REG_WRDBG_MASK)

#define VPU_VPU_DEC_VPU_PDBG_IDX_REG_CONTROL_REG_RDDBG_MASK (0x200U)
#define VPU_VPU_DEC_VPU_PDBG_IDX_REG_CONTROL_REG_RDDBG_SHIFT (9U)
#define VPU_VPU_DEC_VPU_PDBG_IDX_REG_CONTROL_REG_RDDBG(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_PDBG_IDX_REG_CONTROL_REG_RDDBG_SHIFT)) & VPU_VPU_DEC_VPU_PDBG_IDX_REG_CONTROL_REG_RDDBG_MASK)
/*! @} */

/*! @name VPU_PDBG_IDX_REG_CONTROL_REG_VM - V-CPU Debugger Index */
/*! @{ */

#define VPU_VPU_DEC_VPU_PDBG_IDX_REG_CONTROL_REG_VM_DBGIDX_MASK (0xFFU)
#define VPU_VPU_DEC_VPU_PDBG_IDX_REG_CONTROL_REG_VM_DBGIDX_SHIFT (0U)
#define VPU_VPU_DEC_VPU_PDBG_IDX_REG_CONTROL_REG_VM_DBGIDX(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_PDBG_IDX_REG_CONTROL_REG_VM_DBGIDX_SHIFT)) & VPU_VPU_DEC_VPU_PDBG_IDX_REG_CONTROL_REG_VM_DBGIDX_MASK)

#define VPU_VPU_DEC_VPU_PDBG_IDX_REG_CONTROL_REG_VM_WRDBG_MASK (0x100U)
#define VPU_VPU_DEC_VPU_PDBG_IDX_REG_CONTROL_REG_VM_WRDBG_SHIFT (8U)
#define VPU_VPU_DEC_VPU_PDBG_IDX_REG_CONTROL_REG_VM_WRDBG(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_PDBG_IDX_REG_CONTROL_REG_VM_WRDBG_SHIFT)) & VPU_VPU_DEC_VPU_PDBG_IDX_REG_CONTROL_REG_VM_WRDBG_MASK)

#define VPU_VPU_DEC_VPU_PDBG_IDX_REG_CONTROL_REG_VM_RDDBG_MASK (0x200U)
#define VPU_VPU_DEC_VPU_PDBG_IDX_REG_CONTROL_REG_VM_RDDBG_SHIFT (9U)
#define VPU_VPU_DEC_VPU_PDBG_IDX_REG_CONTROL_REG_VM_RDDBG(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_PDBG_IDX_REG_CONTROL_REG_VM_RDDBG_SHIFT)) & VPU_VPU_DEC_VPU_PDBG_IDX_REG_CONTROL_REG_VM_RDDBG_MASK)
/*! @} */

/*! @name VPU_PDBG_WDATA_REG_CONTROL_REG - V-CPU Debugger Write Data */
/*! @{ */

#define VPU_VPU_DEC_VPU_PDBG_WDATA_REG_CONTROL_REG_VPU_PDBG_WDATA_REG_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_VPU_PDBG_WDATA_REG_CONTROL_REG_VPU_PDBG_WDATA_REG_SHIFT (0U)
#define VPU_VPU_DEC_VPU_PDBG_WDATA_REG_CONTROL_REG_VPU_PDBG_WDATA_REG(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_PDBG_WDATA_REG_CONTROL_REG_VPU_PDBG_WDATA_REG_SHIFT)) & VPU_VPU_DEC_VPU_PDBG_WDATA_REG_CONTROL_REG_VPU_PDBG_WDATA_REG_MASK)
/*! @} */

/*! @name VPU_PDBG_WDATA_REG_CONTROL_REG_VM - V-CPU Debugger Write Data */
/*! @{ */

#define VPU_VPU_DEC_VPU_PDBG_WDATA_REG_CONTROL_REG_VM_VPU_PDBG_WDATA_REG_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_VPU_PDBG_WDATA_REG_CONTROL_REG_VM_VPU_PDBG_WDATA_REG_SHIFT (0U)
#define VPU_VPU_DEC_VPU_PDBG_WDATA_REG_CONTROL_REG_VM_VPU_PDBG_WDATA_REG(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_PDBG_WDATA_REG_CONTROL_REG_VM_VPU_PDBG_WDATA_REG_SHIFT)) & VPU_VPU_DEC_VPU_PDBG_WDATA_REG_CONTROL_REG_VM_VPU_PDBG_WDATA_REG_MASK)
/*! @} */

/*! @name VPU_PDBG_RDATA_REG_CONTROL_REG - V-CPU Debugger Read Data */
/*! @{ */

#define VPU_VPU_DEC_VPU_PDBG_RDATA_REG_CONTROL_REG_VPU_PDBG_RDATA_REG_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_VPU_PDBG_RDATA_REG_CONTROL_REG_VPU_PDBG_RDATA_REG_SHIFT (0U)
#define VPU_VPU_DEC_VPU_PDBG_RDATA_REG_CONTROL_REG_VPU_PDBG_RDATA_REG(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_PDBG_RDATA_REG_CONTROL_REG_VPU_PDBG_RDATA_REG_SHIFT)) & VPU_VPU_DEC_VPU_PDBG_RDATA_REG_CONTROL_REG_VPU_PDBG_RDATA_REG_MASK)
/*! @} */

/*! @name VPU_PDBG_RDATA_REG_CONTROL_REG_VM - V-CPU Debugger Read Data */
/*! @{ */

#define VPU_VPU_DEC_VPU_PDBG_RDATA_REG_CONTROL_REG_VM_VPU_PDBG_RDATA_REG_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_VPU_PDBG_RDATA_REG_CONTROL_REG_VM_VPU_PDBG_RDATA_REG_SHIFT (0U)
#define VPU_VPU_DEC_VPU_PDBG_RDATA_REG_CONTROL_REG_VM_VPU_PDBG_RDATA_REG(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_PDBG_RDATA_REG_CONTROL_REG_VM_VPU_PDBG_RDATA_REG_SHIFT)) & VPU_VPU_DEC_VPU_PDBG_RDATA_REG_CONTROL_REG_VM_VPU_PDBG_RDATA_REG_MASK)
/*! @} */

/*! @name VPU_FIO_CTRL_ADDR_CONTROL_REG - FastIO Control/Address */
/*! @{ */

#define VPU_VPU_DEC_VPU_FIO_CTRL_ADDR_CONTROL_REG_FIO_ADDR_MASK (0xFFFFU)
#define VPU_VPU_DEC_VPU_FIO_CTRL_ADDR_CONTROL_REG_FIO_ADDR_SHIFT (0U)
#define VPU_VPU_DEC_VPU_FIO_CTRL_ADDR_CONTROL_REG_FIO_ADDR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_FIO_CTRL_ADDR_CONTROL_REG_FIO_ADDR_SHIFT)) & VPU_VPU_DEC_VPU_FIO_CTRL_ADDR_CONTROL_REG_FIO_ADDR_MASK)

#define VPU_VPU_DEC_VPU_FIO_CTRL_ADDR_CONTROL_REG_RW_FLAG_MASK (0x10000U)
#define VPU_VPU_DEC_VPU_FIO_CTRL_ADDR_CONTROL_REG_RW_FLAG_SHIFT (16U)
#define VPU_VPU_DEC_VPU_FIO_CTRL_ADDR_CONTROL_REG_RW_FLAG(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_FIO_CTRL_ADDR_CONTROL_REG_RW_FLAG_SHIFT)) & VPU_VPU_DEC_VPU_FIO_CTRL_ADDR_CONTROL_REG_RW_FLAG_MASK)

#define VPU_VPU_DEC_VPU_FIO_CTRL_ADDR_CONTROL_REG_READY_MASK (0x80000000U)
#define VPU_VPU_DEC_VPU_FIO_CTRL_ADDR_CONTROL_REG_READY_SHIFT (31U)
#define VPU_VPU_DEC_VPU_FIO_CTRL_ADDR_CONTROL_REG_READY(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_FIO_CTRL_ADDR_CONTROL_REG_READY_SHIFT)) & VPU_VPU_DEC_VPU_FIO_CTRL_ADDR_CONTROL_REG_READY_MASK)
/*! @} */

/*! @name VPU_FIO_CTRL_ADDR_CONTROL_REG_VM - FastIO Control/Address */
/*! @{ */

#define VPU_VPU_DEC_VPU_FIO_CTRL_ADDR_CONTROL_REG_VM_FIO_ADDR_MASK (0xFFFFU)
#define VPU_VPU_DEC_VPU_FIO_CTRL_ADDR_CONTROL_REG_VM_FIO_ADDR_SHIFT (0U)
#define VPU_VPU_DEC_VPU_FIO_CTRL_ADDR_CONTROL_REG_VM_FIO_ADDR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_FIO_CTRL_ADDR_CONTROL_REG_VM_FIO_ADDR_SHIFT)) & VPU_VPU_DEC_VPU_FIO_CTRL_ADDR_CONTROL_REG_VM_FIO_ADDR_MASK)

#define VPU_VPU_DEC_VPU_FIO_CTRL_ADDR_CONTROL_REG_VM_RW_FLAG_MASK (0x10000U)
#define VPU_VPU_DEC_VPU_FIO_CTRL_ADDR_CONTROL_REG_VM_RW_FLAG_SHIFT (16U)
#define VPU_VPU_DEC_VPU_FIO_CTRL_ADDR_CONTROL_REG_VM_RW_FLAG(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_FIO_CTRL_ADDR_CONTROL_REG_VM_RW_FLAG_SHIFT)) & VPU_VPU_DEC_VPU_FIO_CTRL_ADDR_CONTROL_REG_VM_RW_FLAG_MASK)

#define VPU_VPU_DEC_VPU_FIO_CTRL_ADDR_CONTROL_REG_VM_READY_MASK (0x80000000U)
#define VPU_VPU_DEC_VPU_FIO_CTRL_ADDR_CONTROL_REG_VM_READY_SHIFT (31U)
#define VPU_VPU_DEC_VPU_FIO_CTRL_ADDR_CONTROL_REG_VM_READY(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_FIO_CTRL_ADDR_CONTROL_REG_VM_READY_SHIFT)) & VPU_VPU_DEC_VPU_FIO_CTRL_ADDR_CONTROL_REG_VM_READY_MASK)
/*! @} */

/*! @name VPU_FIO_DATA_CONTROL_REG - FastIO Data */
/*! @{ */

#define VPU_VPU_DEC_VPU_FIO_DATA_CONTROL_REG_FIO_DATA_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_VPU_FIO_DATA_CONTROL_REG_FIO_DATA_SHIFT (0U)
#define VPU_VPU_DEC_VPU_FIO_DATA_CONTROL_REG_FIO_DATA(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_FIO_DATA_CONTROL_REG_FIO_DATA_SHIFT)) & VPU_VPU_DEC_VPU_FIO_DATA_CONTROL_REG_FIO_DATA_MASK)
/*! @} */

/*! @name VPU_FIO_DATA_CONTROL_REG_VM - FastIO Data */
/*! @{ */

#define VPU_VPU_DEC_VPU_FIO_DATA_CONTROL_REG_VM_FIO_DATA_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_VPU_FIO_DATA_CONTROL_REG_VM_FIO_DATA_SHIFT (0U)
#define VPU_VPU_DEC_VPU_FIO_DATA_CONTROL_REG_VM_FIO_DATA(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_FIO_DATA_CONTROL_REG_VM_FIO_DATA_SHIFT)) & VPU_VPU_DEC_VPU_FIO_DATA_CONTROL_REG_VM_FIO_DATA_MASK)
/*! @} */

/*! @name VPU_VINT_REASON_USR_CONTROL_REG - Interrupt Reason User */
/*! @{ */

#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_CMD0_INTR_USER_MASK (0x1U)
#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_CMD0_INTR_USER_SHIFT (0U)
#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_CMD0_INTR_USER(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_CMD0_INTR_USER_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_CMD0_INTR_USER_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_CMD1_INTR_USER_MASK (0x2U)
#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_CMD1_INTR_USER_SHIFT (1U)
#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_CMD1_INTR_USER(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_CMD1_INTR_USER_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_CMD1_INTR_USER_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_CMD2_INTR_USER_MASK (0x4U)
#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_CMD2_INTR_USER_SHIFT (2U)
#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_CMD2_INTR_USER(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_CMD2_INTR_USER_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_CMD2_INTR_USER_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_CMD3_INTR_USER_MASK (0x8U)
#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_CMD3_INTR_USER_SHIFT (3U)
#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_CMD3_INTR_USER(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_CMD3_INTR_USER_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_CMD3_INTR_USER_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_CMD4_INTR_USER_MASK (0x10U)
#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_CMD4_INTR_USER_SHIFT (4U)
#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_CMD4_INTR_USER(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_CMD4_INTR_USER_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_CMD4_INTR_USER_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_CMD5_INTR_USER_MASK (0x20U)
#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_CMD5_INTR_USER_SHIFT (5U)
#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_CMD5_INTR_USER(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_CMD5_INTR_USER_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_CMD5_INTR_USER_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_CMD6_INTR_USER_MASK (0x40U)
#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_CMD6_INTR_USER_SHIFT (6U)
#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_CMD6_INTR_USER(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_CMD6_INTR_USER_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_CMD6_INTR_USER_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_CMD7_INTR_USER_MASK (0x80U)
#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_CMD7_INTR_USER_SHIFT (7U)
#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_CMD7_INTR_USER(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_CMD7_INTR_USER_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_CMD7_INTR_USER_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_CMD8_INTR_USER_MASK (0x100U)
#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_CMD8_INTR_USER_SHIFT (8U)
#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_CMD8_INTR_USER(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_CMD8_INTR_USER_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_CMD8_INTR_USER_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_CMD9_INTR_USER_MASK (0x200U)
#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_CMD9_INTR_USER_SHIFT (9U)
#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_CMD9_INTR_USER(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_CMD9_INTR_USER_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_CMD9_INTR_USER_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_REL_SRC_INTR_USER_MASK (0x400U)
#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_REL_SRC_INTR_USER_SHIFT (10U)
#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_REL_SRC_INTR_USER(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_REL_SRC_INTR_USER_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_REL_SRC_INTR_USER_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_RSVD1_MASK (0x800U)
#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_RSVD1_SHIFT (11U)
#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_RSVD1(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_RSVD1_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_RSVD1_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_RSVD0_MASK (0x1000U)
#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_RSVD0_SHIFT (12U)
#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_RSVD0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_RSVD0_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_RSVD0_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_CMDD_INTR_USER_MASK (0x2000U)
#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_CMDD_INTR_USER_SHIFT (13U)
#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_CMDD_INTR_USER(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_CMDD_INTR_USER_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_CMDD_INTR_USER_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_CMDE_INTR_USER_MASK (0x4000U)
#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_CMDE_INTR_USER_SHIFT (14U)
#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_CMDE_INTR_USER(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_CMDE_INTR_USER_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_CMDE_INTR_USER_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_BSEMPTY_INTR_USER_MASK (0x8000U)
#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_BSEMPTY_INTR_USER_SHIFT (15U)
#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_BSEMPTY_INTR_USER(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_BSEMPTY_INTR_USER_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_BSEMPTY_INTR_USER_MASK)
/*! @} */

/*! @name VPU_VINT_REASON_USR_CONTROL_REG_VM - Interrupt Reason User */
/*! @{ */

#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_VM_CMD0_INTR_USER_MASK (0x1U)
#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_VM_CMD0_INTR_USER_SHIFT (0U)
#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_VM_CMD0_INTR_USER(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_VM_CMD0_INTR_USER_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_VM_CMD0_INTR_USER_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_VM_CMD1_INTR_USER_MASK (0x2U)
#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_VM_CMD1_INTR_USER_SHIFT (1U)
#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_VM_CMD1_INTR_USER(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_VM_CMD1_INTR_USER_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_VM_CMD1_INTR_USER_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_VM_CMD2_INTR_USER_MASK (0x4U)
#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_VM_CMD2_INTR_USER_SHIFT (2U)
#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_VM_CMD2_INTR_USER(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_VM_CMD2_INTR_USER_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_VM_CMD2_INTR_USER_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_VM_CMD3_INTR_USER_MASK (0x8U)
#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_VM_CMD3_INTR_USER_SHIFT (3U)
#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_VM_CMD3_INTR_USER(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_VM_CMD3_INTR_USER_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_VM_CMD3_INTR_USER_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_VM_CMD4_INTR_USER_MASK (0x10U)
#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_VM_CMD4_INTR_USER_SHIFT (4U)
#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_VM_CMD4_INTR_USER(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_VM_CMD4_INTR_USER_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_VM_CMD4_INTR_USER_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_VM_CMD5_INTR_USER_MASK (0x20U)
#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_VM_CMD5_INTR_USER_SHIFT (5U)
#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_VM_CMD5_INTR_USER(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_VM_CMD5_INTR_USER_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_VM_CMD5_INTR_USER_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_VM_CMD6_INTR_USER_MASK (0x40U)
#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_VM_CMD6_INTR_USER_SHIFT (6U)
#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_VM_CMD6_INTR_USER(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_VM_CMD6_INTR_USER_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_VM_CMD6_INTR_USER_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_VM_CMD7_INTR_USER_MASK (0x80U)
#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_VM_CMD7_INTR_USER_SHIFT (7U)
#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_VM_CMD7_INTR_USER(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_VM_CMD7_INTR_USER_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_VM_CMD7_INTR_USER_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_VM_CMD8_INTR_USER_MASK (0x100U)
#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_VM_CMD8_INTR_USER_SHIFT (8U)
#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_VM_CMD8_INTR_USER(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_VM_CMD8_INTR_USER_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_VM_CMD8_INTR_USER_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_VM_CMD9_INTR_USER_MASK (0x200U)
#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_VM_CMD9_INTR_USER_SHIFT (9U)
#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_VM_CMD9_INTR_USER(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_VM_CMD9_INTR_USER_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_VM_CMD9_INTR_USER_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_VM_REL_SRC_INTR_USER_MASK (0x400U)
#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_VM_REL_SRC_INTR_USER_SHIFT (10U)
#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_VM_REL_SRC_INTR_USER(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_VM_REL_SRC_INTR_USER_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_VM_REL_SRC_INTR_USER_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_VM_RSVD0_MASK (0x800U)
#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_VM_RSVD0_SHIFT (11U)
#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_VM_RSVD0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_VM_RSVD0_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_VM_RSVD0_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_VM_CMDC_INTR_USER_MASK (0x1000U)
#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_VM_CMDC_INTR_USER_SHIFT (12U)
#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_VM_CMDC_INTR_USER(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_VM_CMDC_INTR_USER_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_VM_CMDC_INTR_USER_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_VM_CMDD_INTR_USER_MASK (0x2000U)
#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_VM_CMDD_INTR_USER_SHIFT (13U)
#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_VM_CMDD_INTR_USER(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_VM_CMDD_INTR_USER_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_VM_CMDD_INTR_USER_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_VM_CMDE_INTR_USER_MASK (0x4000U)
#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_VM_CMDE_INTR_USER_SHIFT (14U)
#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_VM_CMDE_INTR_USER(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_VM_CMDE_INTR_USER_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_VM_CMDE_INTR_USER_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_VM_BSEMPTY_INTR_USER_MASK (0x8000U)
#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_VM_BSEMPTY_INTR_USER_SHIFT (15U)
#define VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_VM_BSEMPTY_INTR_USER(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_VM_BSEMPTY_INTR_USER_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_USR_CONTROL_REG_VM_BSEMPTY_INTR_USER_MASK)
/*! @} */

/*! @name VPU_VINT_REASON_CLR_CONTROL_REG - Interrupt Reason Clear */
/*! @{ */

#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_CMD0_CLR_MASK (0x1U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_CMD0_CLR_SHIFT (0U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_CMD0_CLR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_CMD0_CLR_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_CMD0_CLR_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_CMD1_CLR_MASK (0x2U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_CMD1_CLR_SHIFT (1U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_CMD1_CLR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_CMD1_CLR_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_CMD1_CLR_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_CMD2_CLR_MASK (0x4U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_CMD2_CLR_SHIFT (2U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_CMD2_CLR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_CMD2_CLR_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_CMD2_CLR_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_CMD3_CLR_MASK (0x8U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_CMD3_CLR_SHIFT (3U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_CMD3_CLR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_CMD3_CLR_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_CMD3_CLR_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_CMD4_CLR_MASK (0x10U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_CMD4_CLR_SHIFT (4U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_CMD4_CLR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_CMD4_CLR_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_CMD4_CLR_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_CMD5_CLR_MASK (0x20U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_CMD5_CLR_SHIFT (5U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_CMD5_CLR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_CMD5_CLR_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_CMD5_CLR_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_CMD6_CLR_MASK (0x40U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_CMD6_CLR_SHIFT (6U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_CMD6_CLR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_CMD6_CLR_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_CMD6_CLR_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_CMD7_CLR_MASK (0x80U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_CMD7_CLR_SHIFT (7U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_CMD7_CLR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_CMD7_CLR_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_CMD7_CLR_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_CMD8_CLR_MASK (0x100U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_CMD8_CLR_SHIFT (8U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_CMD8_CLR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_CMD8_CLR_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_CMD8_CLR_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_CMD9_CLR_MASK (0x200U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_CMD9_CLR_SHIFT (9U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_CMD9_CLR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_CMD9_CLR_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_CMD9_CLR_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_REL_SRC_CLR_MASK (0x400U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_REL_SRC_CLR_SHIFT (10U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_REL_SRC_CLR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_REL_SRC_CLR_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_REL_SRC_CLR_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_INSUFFICIENT_VLC_BUFFER_MASK (0x800U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_INSUFFICIENT_VLC_BUFFER_SHIFT (11U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_INSUFFICIENT_VLC_BUFFER(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_INSUFFICIENT_VLC_BUFFER_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_INSUFFICIENT_VLC_BUFFER_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_RSVD0_MASK (0x1000U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_RSVD0_SHIFT (12U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_RSVD0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_RSVD0_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_RSVD0_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_CMDD_CLR_MASK (0x2000U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_CMDD_CLR_SHIFT (13U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_CMDD_CLR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_CMDD_CLR_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_CMDD_CLR_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_CMDE_CLR_MASK (0x4000U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_CMDE_CLR_SHIFT (14U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_CMDE_CLR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_CMDE_CLR_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_CMDE_CLR_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_BSEMPTY_CLR_MASK (0x8000U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_BSEMPTY_CLR_SHIFT (15U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_BSEMPTY_CLR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_BSEMPTY_CLR_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_BSEMPTY_CLR_MASK)
/*! @} */

/*! @name VPU_VINT_REASON_CLR_CONTROL_REG_VM - Interrupt Reason Clear */
/*! @{ */

#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_VM_CMD0_CLR_MASK (0x1U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_VM_CMD0_CLR_SHIFT (0U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_VM_CMD0_CLR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_VM_CMD0_CLR_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_VM_CMD0_CLR_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_VM_CMD1_CLR_MASK (0x2U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_VM_CMD1_CLR_SHIFT (1U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_VM_CMD1_CLR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_VM_CMD1_CLR_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_VM_CMD1_CLR_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_VM_CMD2_CLR_MASK (0x4U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_VM_CMD2_CLR_SHIFT (2U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_VM_CMD2_CLR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_VM_CMD2_CLR_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_VM_CMD2_CLR_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_VM_CMD3_CLR_MASK (0x8U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_VM_CMD3_CLR_SHIFT (3U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_VM_CMD3_CLR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_VM_CMD3_CLR_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_VM_CMD3_CLR_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_VM_CMD4_CLR_MASK (0x10U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_VM_CMD4_CLR_SHIFT (4U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_VM_CMD4_CLR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_VM_CMD4_CLR_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_VM_CMD4_CLR_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_VM_CMD5_CLR_MASK (0x20U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_VM_CMD5_CLR_SHIFT (5U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_VM_CMD5_CLR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_VM_CMD5_CLR_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_VM_CMD5_CLR_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_VM_CMD6_CLR_MASK (0x40U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_VM_CMD6_CLR_SHIFT (6U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_VM_CMD6_CLR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_VM_CMD6_CLR_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_VM_CMD6_CLR_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_VM_CMD7_CLR_MASK (0x80U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_VM_CMD7_CLR_SHIFT (7U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_VM_CMD7_CLR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_VM_CMD7_CLR_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_VM_CMD7_CLR_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_VM_CMD8_CLR_MASK (0x100U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_VM_CMD8_CLR_SHIFT (8U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_VM_CMD8_CLR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_VM_CMD8_CLR_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_VM_CMD8_CLR_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_VM_CMD9_CLR_MASK (0x200U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_VM_CMD9_CLR_SHIFT (9U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_VM_CMD9_CLR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_VM_CMD9_CLR_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_VM_CMD9_CLR_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_VM_REL_SRC_CLR_MASK (0x400U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_VM_REL_SRC_CLR_SHIFT (10U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_VM_REL_SRC_CLR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_VM_REL_SRC_CLR_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_VM_REL_SRC_CLR_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_VM_INSUFFICIENT_VLC_BUFFER_MASK (0x800U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_VM_INSUFFICIENT_VLC_BUFFER_SHIFT (11U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_VM_INSUFFICIENT_VLC_BUFFER(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_VM_INSUFFICIENT_VLC_BUFFER_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_VM_INSUFFICIENT_VLC_BUFFER_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_VM_RSVD0_MASK (0x1000U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_VM_RSVD0_SHIFT (12U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_VM_RSVD0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_VM_RSVD0_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_VM_RSVD0_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_VM_CMDD_CLR_MASK (0x2000U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_VM_CMDD_CLR_SHIFT (13U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_VM_CMDD_CLR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_VM_CMDD_CLR_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_VM_CMDD_CLR_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_VM_CMDE_CLR_MASK (0x4000U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_VM_CMDE_CLR_SHIFT (14U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_VM_CMDE_CLR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_VM_CMDE_CLR_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_VM_CMDE_CLR_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_VM_BSEMPTY_CLR_MASK (0x8000U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_VM_BSEMPTY_CLR_SHIFT (15U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_VM_BSEMPTY_CLR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_VM_BSEMPTY_CLR_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_CLR_CONTROL_REG_VM_BSEMPTY_CLR_MASK)
/*! @} */

/*! @name VPU_HOST_INT_REQ0_CONTROL_REG - Host Interrupt Request */
/*! @{ */

#define VPU_VPU_DEC_VPU_HOST_INT_REQ0_CONTROL_REG_HINTREQ_MASK (0x1U)
#define VPU_VPU_DEC_VPU_HOST_INT_REQ0_CONTROL_REG_HINTREQ_SHIFT (0U)
#define VPU_VPU_DEC_VPU_HOST_INT_REQ0_CONTROL_REG_HINTREQ(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_HOST_INT_REQ0_CONTROL_REG_HINTREQ_SHIFT)) & VPU_VPU_DEC_VPU_HOST_INT_REQ0_CONTROL_REG_HINTREQ_MASK)
/*! @} */

/*! @name VPU_HOST_INT_REQ0_CONTROL_REG_VM - Host Interrupt Request */
/*! @{ */

#define VPU_VPU_DEC_VPU_HOST_INT_REQ0_CONTROL_REG_VM_HINTREQ_MASK (0x1U)
#define VPU_VPU_DEC_VPU_HOST_INT_REQ0_CONTROL_REG_VM_HINTREQ_SHIFT (0U)
#define VPU_VPU_DEC_VPU_HOST_INT_REQ0_CONTROL_REG_VM_HINTREQ(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_HOST_INT_REQ0_CONTROL_REG_VM_HINTREQ_SHIFT)) & VPU_VPU_DEC_VPU_HOST_INT_REQ0_CONTROL_REG_VM_HINTREQ_MASK)
/*! @} */

/*! @name VPU_VINT_CLEAR_CONTROL_REG - VPU Interrupt Clear */
/*! @{ */

#define VPU_VPU_DEC_VPU_VINT_CLEAR_CONTROL_REG_VINTCLR_MASK (0x1U)
#define VPU_VPU_DEC_VPU_VINT_CLEAR_CONTROL_REG_VINTCLR_SHIFT (0U)
#define VPU_VPU_DEC_VPU_VINT_CLEAR_CONTROL_REG_VINTCLR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_CLEAR_CONTROL_REG_VINTCLR_SHIFT)) & VPU_VPU_DEC_VPU_VINT_CLEAR_CONTROL_REG_VINTCLR_MASK)
/*! @} */

/*! @name VPU_VINT_CLEAR_CONTROL_REG_VM - VPU Interrupt Clear */
/*! @{ */

#define VPU_VPU_DEC_VPU_VINT_CLEAR_CONTROL_REG_VM_VINTCLR_MASK (0x1U)
#define VPU_VPU_DEC_VPU_VINT_CLEAR_CONTROL_REG_VM_VINTCLR_SHIFT (0U)
#define VPU_VPU_DEC_VPU_VINT_CLEAR_CONTROL_REG_VM_VINTCLR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_CLEAR_CONTROL_REG_VM_VINTCLR_SHIFT)) & VPU_VPU_DEC_VPU_VINT_CLEAR_CONTROL_REG_VM_VINTCLR_MASK)
/*! @} */

/*! @name VPU_HINT_CLEAR_CONTROL_REG - Host Interrupt Clear */
/*! @{ */

#define VPU_VPU_DEC_VPU_HINT_CLEAR_CONTROL_REG_HINTCLR_MASK (0x1U)
#define VPU_VPU_DEC_VPU_HINT_CLEAR_CONTROL_REG_HINTCLR_SHIFT (0U)
#define VPU_VPU_DEC_VPU_HINT_CLEAR_CONTROL_REG_HINTCLR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_HINT_CLEAR_CONTROL_REG_HINTCLR_SHIFT)) & VPU_VPU_DEC_VPU_HINT_CLEAR_CONTROL_REG_HINTCLR_MASK)
/*! @} */

/*! @name VPU_HINT_CLEAR_CONTROL_REG_VM - Host Interrupt Clear */
/*! @{ */

#define VPU_VPU_DEC_VPU_HINT_CLEAR_CONTROL_REG_VM_HINTCLR_MASK (0x1U)
#define VPU_VPU_DEC_VPU_HINT_CLEAR_CONTROL_REG_VM_HINTCLR_SHIFT (0U)
#define VPU_VPU_DEC_VPU_HINT_CLEAR_CONTROL_REG_VM_HINTCLR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_HINT_CLEAR_CONTROL_REG_VM_HINTCLR_SHIFT)) & VPU_VPU_DEC_VPU_HINT_CLEAR_CONTROL_REG_VM_HINTCLR_MASK)
/*! @} */

/*! @name VPU_VPU_INT_STS_CONTROL_REG - VPU Interrupt Status */
/*! @{ */

#define VPU_VPU_DEC_VPU_VPU_INT_STS_CONTROL_REG_VPU_VPU_INT_STS_MASK (0x1U)
#define VPU_VPU_DEC_VPU_VPU_INT_STS_CONTROL_REG_VPU_VPU_INT_STS_SHIFT (0U)
#define VPU_VPU_DEC_VPU_VPU_INT_STS_CONTROL_REG_VPU_VPU_INT_STS(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VPU_INT_STS_CONTROL_REG_VPU_VPU_INT_STS_SHIFT)) & VPU_VPU_DEC_VPU_VPU_INT_STS_CONTROL_REG_VPU_VPU_INT_STS_MASK)
/*! @} */

/*! @name VPU_VPU_INT_STS_CONTROL_REG_VM - VPU Interrupt Status */
/*! @{ */

#define VPU_VPU_DEC_VPU_VPU_INT_STS_CONTROL_REG_VM_VPU_VPU_INT_STS_MASK (0x1U)
#define VPU_VPU_DEC_VPU_VPU_INT_STS_CONTROL_REG_VM_VPU_VPU_INT_STS_SHIFT (0U)
#define VPU_VPU_DEC_VPU_VPU_INT_STS_CONTROL_REG_VM_VPU_VPU_INT_STS(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VPU_INT_STS_CONTROL_REG_VM_VPU_VPU_INT_STS_SHIFT)) & VPU_VPU_DEC_VPU_VPU_INT_STS_CONTROL_REG_VM_VPU_VPU_INT_STS_MASK)
/*! @} */

/*! @name VPU_VINT_ENABLE_CONTROL_REG - VPU Interrupt Enable */
/*! @{ */

#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_CMD0_EN_MASK (0x1U)
#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_CMD0_EN_SHIFT (0U)
#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_CMD0_EN(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_CMD0_EN_SHIFT)) & VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_CMD0_EN_MASK)

#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_CMD1_EN_MASK (0x2U)
#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_CMD1_EN_SHIFT (1U)
#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_CMD1_EN(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_CMD1_EN_SHIFT)) & VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_CMD1_EN_MASK)

#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_CMD2_EN_MASK (0x4U)
#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_CMD2_EN_SHIFT (2U)
#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_CMD2_EN(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_CMD2_EN_SHIFT)) & VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_CMD2_EN_MASK)

#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_CMD3_EN_MASK (0x8U)
#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_CMD3_EN_SHIFT (3U)
#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_CMD3_EN(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_CMD3_EN_SHIFT)) & VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_CMD3_EN_MASK)

#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_CMD4_EN_MASK (0x10U)
#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_CMD4_EN_SHIFT (4U)
#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_CMD4_EN(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_CMD4_EN_SHIFT)) & VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_CMD4_EN_MASK)

#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_CMD5_EN_MASK (0x20U)
#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_CMD5_EN_SHIFT (5U)
#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_CMD5_EN(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_CMD5_EN_SHIFT)) & VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_CMD5_EN_MASK)

#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_CMD6_EN_MASK (0x40U)
#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_CMD6_EN_SHIFT (6U)
#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_CMD6_EN(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_CMD6_EN_SHIFT)) & VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_CMD6_EN_MASK)

#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_CMD7_EN_MASK (0x80U)
#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_CMD7_EN_SHIFT (7U)
#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_CMD7_EN(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_CMD7_EN_SHIFT)) & VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_CMD7_EN_MASK)

#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_CMD8_EN_MASK (0x100U)
#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_CMD8_EN_SHIFT (8U)
#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_CMD8_EN(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_CMD8_EN_SHIFT)) & VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_CMD8_EN_MASK)

#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_CMD9_EN_MASK (0x200U)
#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_CMD9_EN_SHIFT (9U)
#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_CMD9_EN(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_CMD9_EN_SHIFT)) & VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_CMD9_EN_MASK)

#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_REL_SRC_EN_MASK (0x400U)
#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_REL_SRC_EN_SHIFT (10U)
#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_REL_SRC_EN(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_REL_SRC_EN_SHIFT)) & VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_REL_SRC_EN_MASK)

#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_INSUFFICIENT_VLC_BUFFER_MASK (0x800U)
#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_INSUFFICIENT_VLC_BUFFER_SHIFT (11U)
#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_INSUFFICIENT_VLC_BUFFER(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_INSUFFICIENT_VLC_BUFFER_SHIFT)) & VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_INSUFFICIENT_VLC_BUFFER_MASK)

#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_RSVD0_MASK (0x1000U)
#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_RSVD0_SHIFT (12U)
#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_RSVD0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_RSVD0_SHIFT)) & VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_RSVD0_MASK)

#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_CMDD_EN_MASK (0x2000U)
#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_CMDD_EN_SHIFT (13U)
#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_CMDD_EN(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_CMDD_EN_SHIFT)) & VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_CMDD_EN_MASK)

#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_CMDE_EN_MASK (0x4000U)
#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_CMDE_EN_SHIFT (14U)
#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_CMDE_EN(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_CMDE_EN_SHIFT)) & VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_CMDE_EN_MASK)

#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_CMDF_EN_MASK (0x8000U)
#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_CMDF_EN_SHIFT (15U)
#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_CMDF_EN(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_CMDF_EN_SHIFT)) & VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_CMDF_EN_MASK)
/*! @} */

/*! @name VPU_VINT_ENABLE_CONTROL_REG_VM - VPU Interrupt Enable */
/*! @{ */

#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_VM_CMD0_EN_MASK (0x1U)
#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_VM_CMD0_EN_SHIFT (0U)
#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_VM_CMD0_EN(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_VM_CMD0_EN_SHIFT)) & VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_VM_CMD0_EN_MASK)

#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_VM_CMD1_EN_MASK (0x2U)
#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_VM_CMD1_EN_SHIFT (1U)
#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_VM_CMD1_EN(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_VM_CMD1_EN_SHIFT)) & VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_VM_CMD1_EN_MASK)

#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_VM_CMD2_EN_MASK (0x4U)
#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_VM_CMD2_EN_SHIFT (2U)
#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_VM_CMD2_EN(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_VM_CMD2_EN_SHIFT)) & VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_VM_CMD2_EN_MASK)

#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_VM_CMD3_EN_MASK (0x8U)
#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_VM_CMD3_EN_SHIFT (3U)
#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_VM_CMD3_EN(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_VM_CMD3_EN_SHIFT)) & VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_VM_CMD3_EN_MASK)

#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_VM_CMD4_EN_MASK (0x10U)
#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_VM_CMD4_EN_SHIFT (4U)
#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_VM_CMD4_EN(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_VM_CMD4_EN_SHIFT)) & VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_VM_CMD4_EN_MASK)

#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_VM_CMD5_EN_MASK (0x20U)
#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_VM_CMD5_EN_SHIFT (5U)
#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_VM_CMD5_EN(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_VM_CMD5_EN_SHIFT)) & VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_VM_CMD5_EN_MASK)

#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_VM_CMD6_EN_MASK (0x40U)
#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_VM_CMD6_EN_SHIFT (6U)
#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_VM_CMD6_EN(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_VM_CMD6_EN_SHIFT)) & VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_VM_CMD6_EN_MASK)

#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_VM_CMD7_EN_MASK (0x80U)
#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_VM_CMD7_EN_SHIFT (7U)
#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_VM_CMD7_EN(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_VM_CMD7_EN_SHIFT)) & VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_VM_CMD7_EN_MASK)

#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_VM_CMD8_EN_MASK (0x100U)
#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_VM_CMD8_EN_SHIFT (8U)
#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_VM_CMD8_EN(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_VM_CMD8_EN_SHIFT)) & VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_VM_CMD8_EN_MASK)

#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_VM_CMD9_EN_MASK (0x200U)
#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_VM_CMD9_EN_SHIFT (9U)
#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_VM_CMD9_EN(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_VM_CMD9_EN_SHIFT)) & VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_VM_CMD9_EN_MASK)

#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_VM_REL_SRC_EN_MASK (0x400U)
#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_VM_REL_SRC_EN_SHIFT (10U)
#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_VM_REL_SRC_EN(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_VM_REL_SRC_EN_SHIFT)) & VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_VM_REL_SRC_EN_MASK)

#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_VM_INSUFFICIENT_VLC_BUFFER_MASK (0x800U)
#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_VM_INSUFFICIENT_VLC_BUFFER_SHIFT (11U)
#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_VM_INSUFFICIENT_VLC_BUFFER(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_VM_INSUFFICIENT_VLC_BUFFER_SHIFT)) & VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_VM_INSUFFICIENT_VLC_BUFFER_MASK)

#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_VM_RSVD0_MASK (0x1000U)
#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_VM_RSVD0_SHIFT (12U)
#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_VM_RSVD0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_VM_RSVD0_SHIFT)) & VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_VM_RSVD0_MASK)

#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_VM_CMDD_EN_MASK (0x2000U)
#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_VM_CMDD_EN_SHIFT (13U)
#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_VM_CMDD_EN(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_VM_CMDD_EN_SHIFT)) & VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_VM_CMDD_EN_MASK)

#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_VM_CMDE_EN_MASK (0x4000U)
#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_VM_CMDE_EN_SHIFT (14U)
#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_VM_CMDE_EN(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_VM_CMDE_EN_SHIFT)) & VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_VM_CMDE_EN_MASK)

#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_VM_CMDF_EN_MASK (0x8000U)
#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_VM_CMDF_EN_SHIFT (15U)
#define VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_VM_CMDF_EN(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_VM_CMDF_EN_SHIFT)) & VPU_VPU_DEC_VPU_VINT_ENABLE_CONTROL_REG_VM_CMDF_EN_MASK)
/*! @} */

/*! @name VPU_VINT_REASON_CONTROL_REG - VPU Interrupt Reason */
/*! @{ */

#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_CMD0_INTR_MASK (0x1U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_CMD0_INTR_SHIFT (0U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_CMD0_INTR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_CMD0_INTR_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_CMD0_INTR_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_CMD1_INTR_MASK (0x2U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_CMD1_INTR_SHIFT (1U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_CMD1_INTR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_CMD1_INTR_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_CMD1_INTR_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_CMD2_INTR_MASK (0x4U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_CMD2_INTR_SHIFT (2U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_CMD2_INTR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_CMD2_INTR_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_CMD2_INTR_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_CMD3_INTR_MASK (0x8U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_CMD3_INTR_SHIFT (3U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_CMD3_INTR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_CMD3_INTR_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_CMD3_INTR_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_CMD4_INTR_MASK (0x10U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_CMD4_INTR_SHIFT (4U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_CMD4_INTR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_CMD4_INTR_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_CMD4_INTR_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_CMD5_INTR_MASK (0x20U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_CMD5_INTR_SHIFT (5U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_CMD5_INTR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_CMD5_INTR_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_CMD5_INTR_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_CMD6_INTR_MASK (0x40U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_CMD6_INTR_SHIFT (6U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_CMD6_INTR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_CMD6_INTR_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_CMD6_INTR_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_CMD7_INTR_MASK (0x80U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_CMD7_INTR_SHIFT (7U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_CMD7_INTR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_CMD7_INTR_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_CMD7_INTR_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_CMD8_INTR_MASK (0x100U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_CMD8_INTR_SHIFT (8U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_CMD8_INTR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_CMD8_INTR_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_CMD8_INTR_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_CMD9_INTR_MASK (0x200U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_CMD9_INTR_SHIFT (9U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_CMD9_INTR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_CMD9_INTR_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_CMD9_INTR_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_REL_SRC_INTR_MASK (0x400U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_REL_SRC_INTR_SHIFT (10U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_REL_SRC_INTR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_REL_SRC_INTR_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_REL_SRC_INTR_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_INSUFFICIENT_VLC_BUFFER_MASK (0x800U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_INSUFFICIENT_VLC_BUFFER_SHIFT (11U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_INSUFFICIENT_VLC_BUFFER(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_INSUFFICIENT_VLC_BUFFER_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_INSUFFICIENT_VLC_BUFFER_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_RSVD0_MASK (0x1000U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_RSVD0_SHIFT (12U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_RSVD0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_RSVD0_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_RSVD0_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_CMDD_INTR_MASK (0x2000U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_CMDD_INTR_SHIFT (13U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_CMDD_INTR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_CMDD_INTR_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_CMDD_INTR_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_CMDE_INTR_MASK (0x4000U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_CMDE_INTR_SHIFT (14U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_CMDE_INTR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_CMDE_INTR_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_CMDE_INTR_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_BSEMPTY_INTR_MASK (0x8000U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_BSEMPTY_INTR_SHIFT (15U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_BSEMPTY_INTR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_BSEMPTY_INTR_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_BSEMPTY_INTR_MASK)
/*! @} */

/*! @name VPU_VINT_REASON_CONTROL_REG_VM - VPU Interrupt Reason */
/*! @{ */

#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_VM_CMD0_INTR_MASK (0x1U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_VM_CMD0_INTR_SHIFT (0U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_VM_CMD0_INTR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_VM_CMD0_INTR_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_VM_CMD0_INTR_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_VM_CMD1_INTR_MASK (0x2U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_VM_CMD1_INTR_SHIFT (1U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_VM_CMD1_INTR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_VM_CMD1_INTR_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_VM_CMD1_INTR_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_VM_CMD2_INTR_MASK (0x4U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_VM_CMD2_INTR_SHIFT (2U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_VM_CMD2_INTR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_VM_CMD2_INTR_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_VM_CMD2_INTR_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_VM_CMD3_INTR_MASK (0x8U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_VM_CMD3_INTR_SHIFT (3U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_VM_CMD3_INTR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_VM_CMD3_INTR_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_VM_CMD3_INTR_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_VM_CMD4_INTR_MASK (0x10U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_VM_CMD4_INTR_SHIFT (4U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_VM_CMD4_INTR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_VM_CMD4_INTR_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_VM_CMD4_INTR_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_VM_CMD5_INTR_MASK (0x20U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_VM_CMD5_INTR_SHIFT (5U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_VM_CMD5_INTR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_VM_CMD5_INTR_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_VM_CMD5_INTR_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_VM_CMD6_INTR_MASK (0x40U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_VM_CMD6_INTR_SHIFT (6U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_VM_CMD6_INTR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_VM_CMD6_INTR_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_VM_CMD6_INTR_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_VM_CMD7_INTR_MASK (0x80U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_VM_CMD7_INTR_SHIFT (7U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_VM_CMD7_INTR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_VM_CMD7_INTR_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_VM_CMD7_INTR_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_VM_CMD8_INTR_MASK (0x100U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_VM_CMD8_INTR_SHIFT (8U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_VM_CMD8_INTR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_VM_CMD8_INTR_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_VM_CMD8_INTR_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_VM_CMD9_INTR_MASK (0x200U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_VM_CMD9_INTR_SHIFT (9U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_VM_CMD9_INTR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_VM_CMD9_INTR_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_VM_CMD9_INTR_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_VM_REL_SRC_INTR_MASK (0x400U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_VM_REL_SRC_INTR_SHIFT (10U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_VM_REL_SRC_INTR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_VM_REL_SRC_INTR_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_VM_REL_SRC_INTR_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_VM_INSUFFICIENT_VLC_BUFFER_MASK (0x800U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_VM_INSUFFICIENT_VLC_BUFFER_SHIFT (11U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_VM_INSUFFICIENT_VLC_BUFFER(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_VM_INSUFFICIENT_VLC_BUFFER_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_VM_INSUFFICIENT_VLC_BUFFER_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_VM_RSVD0_MASK (0x1000U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_VM_RSVD0_SHIFT (12U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_VM_RSVD0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_VM_RSVD0_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_VM_RSVD0_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_VM_CMDD_INTR_MASK (0x2000U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_VM_CMDD_INTR_SHIFT (13U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_VM_CMDD_INTR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_VM_CMDD_INTR_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_VM_CMDD_INTR_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_VM_CMDE_INTR_MASK (0x4000U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_VM_CMDE_INTR_SHIFT (14U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_VM_CMDE_INTR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_VM_CMDE_INTR_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_VM_CMDE_INTR_MASK)

#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_VM_BSEMPTY_INTR_MASK (0x8000U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_VM_BSEMPTY_INTR_SHIFT (15U)
#define VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_VM_BSEMPTY_INTR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_VM_BSEMPTY_INTR_SHIFT)) & VPU_VPU_DEC_VPU_VINT_REASON_CONTROL_REG_VM_BSEMPTY_INTR_MASK)
/*! @} */

/*! @name VPU_RESET_REQ_CONTROL_REG - VPU Reset Request */
/*! @{ */

#define VPU_VPU_DEC_VPU_RESET_REQ_CONTROL_REG_CRST_REQ_MASK (0xFFU)
#define VPU_VPU_DEC_VPU_RESET_REQ_CONTROL_REG_CRST_REQ_SHIFT (0U)
#define VPU_VPU_DEC_VPU_RESET_REQ_CONTROL_REG_CRST_REQ(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_RESET_REQ_CONTROL_REG_CRST_REQ_SHIFT)) & VPU_VPU_DEC_VPU_RESET_REQ_CONTROL_REG_CRST_REQ_MASK)

#define VPU_VPU_DEC_VPU_RESET_REQ_CONTROL_REG_BRST_REQ_MASK (0xFF00U)
#define VPU_VPU_DEC_VPU_RESET_REQ_CONTROL_REG_BRST_REQ_SHIFT (8U)
#define VPU_VPU_DEC_VPU_RESET_REQ_CONTROL_REG_BRST_REQ(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_RESET_REQ_CONTROL_REG_BRST_REQ_SHIFT)) & VPU_VPU_DEC_VPU_RESET_REQ_CONTROL_REG_BRST_REQ_MASK)

#define VPU_VPU_DEC_VPU_RESET_REQ_CONTROL_REG_ARST_REQ_MASK (0xFF0000U)
#define VPU_VPU_DEC_VPU_RESET_REQ_CONTROL_REG_ARST_REQ_SHIFT (16U)
#define VPU_VPU_DEC_VPU_RESET_REQ_CONTROL_REG_ARST_REQ(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_RESET_REQ_CONTROL_REG_ARST_REQ_SHIFT)) & VPU_VPU_DEC_VPU_RESET_REQ_CONTROL_REG_ARST_REQ_MASK)

#define VPU_VPU_DEC_VPU_RESET_REQ_CONTROL_REG_VARST_REQ1_MASK (0x1000000U)
#define VPU_VPU_DEC_VPU_RESET_REQ_CONTROL_REG_VARST_REQ1_SHIFT (24U)
#define VPU_VPU_DEC_VPU_RESET_REQ_CONTROL_REG_VARST_REQ1(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_RESET_REQ_CONTROL_REG_VARST_REQ1_SHIFT)) & VPU_VPU_DEC_VPU_RESET_REQ_CONTROL_REG_VARST_REQ1_MASK)

#define VPU_VPU_DEC_VPU_RESET_REQ_CONTROL_REG_VBRST_REQ1_MASK (0x2000000U)
#define VPU_VPU_DEC_VPU_RESET_REQ_CONTROL_REG_VBRST_REQ1_SHIFT (25U)
#define VPU_VPU_DEC_VPU_RESET_REQ_CONTROL_REG_VBRST_REQ1(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_RESET_REQ_CONTROL_REG_VBRST_REQ1_SHIFT)) & VPU_VPU_DEC_VPU_RESET_REQ_CONTROL_REG_VBRST_REQ1_MASK)

#define VPU_VPU_DEC_VPU_RESET_REQ_CONTROL_REG_VARST_REQ0_MASK (0x4000000U)
#define VPU_VPU_DEC_VPU_RESET_REQ_CONTROL_REG_VARST_REQ0_SHIFT (26U)
#define VPU_VPU_DEC_VPU_RESET_REQ_CONTROL_REG_VARST_REQ0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_RESET_REQ_CONTROL_REG_VARST_REQ0_SHIFT)) & VPU_VPU_DEC_VPU_RESET_REQ_CONTROL_REG_VARST_REQ0_MASK)

#define VPU_VPU_DEC_VPU_RESET_REQ_CONTROL_REG_VBRST_REQ0_MASK (0x8000000U)
#define VPU_VPU_DEC_VPU_RESET_REQ_CONTROL_REG_VBRST_REQ0_SHIFT (27U)
#define VPU_VPU_DEC_VPU_RESET_REQ_CONTROL_REG_VBRST_REQ0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_RESET_REQ_CONTROL_REG_VBRST_REQ0_SHIFT)) & VPU_VPU_DEC_VPU_RESET_REQ_CONTROL_REG_VBRST_REQ0_MASK)
/*! @} */

/*! @name VPU_RESET_REQ_CONTROL_REG_VM - VPU Reset Request */
/*! @{ */

#define VPU_VPU_DEC_VPU_RESET_REQ_CONTROL_REG_VM_CRST_REQ_MASK (0xFFU)
#define VPU_VPU_DEC_VPU_RESET_REQ_CONTROL_REG_VM_CRST_REQ_SHIFT (0U)
#define VPU_VPU_DEC_VPU_RESET_REQ_CONTROL_REG_VM_CRST_REQ(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_RESET_REQ_CONTROL_REG_VM_CRST_REQ_SHIFT)) & VPU_VPU_DEC_VPU_RESET_REQ_CONTROL_REG_VM_CRST_REQ_MASK)

#define VPU_VPU_DEC_VPU_RESET_REQ_CONTROL_REG_VM_BRST_REQ_MASK (0xFF00U)
#define VPU_VPU_DEC_VPU_RESET_REQ_CONTROL_REG_VM_BRST_REQ_SHIFT (8U)
#define VPU_VPU_DEC_VPU_RESET_REQ_CONTROL_REG_VM_BRST_REQ(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_RESET_REQ_CONTROL_REG_VM_BRST_REQ_SHIFT)) & VPU_VPU_DEC_VPU_RESET_REQ_CONTROL_REG_VM_BRST_REQ_MASK)

#define VPU_VPU_DEC_VPU_RESET_REQ_CONTROL_REG_VM_ARST_REQ_MASK (0xFF0000U)
#define VPU_VPU_DEC_VPU_RESET_REQ_CONTROL_REG_VM_ARST_REQ_SHIFT (16U)
#define VPU_VPU_DEC_VPU_RESET_REQ_CONTROL_REG_VM_ARST_REQ(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_RESET_REQ_CONTROL_REG_VM_ARST_REQ_SHIFT)) & VPU_VPU_DEC_VPU_RESET_REQ_CONTROL_REG_VM_ARST_REQ_MASK)

#define VPU_VPU_DEC_VPU_RESET_REQ_CONTROL_REG_VM_VARST_REQ1_MASK (0x1000000U)
#define VPU_VPU_DEC_VPU_RESET_REQ_CONTROL_REG_VM_VARST_REQ1_SHIFT (24U)
#define VPU_VPU_DEC_VPU_RESET_REQ_CONTROL_REG_VM_VARST_REQ1(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_RESET_REQ_CONTROL_REG_VM_VARST_REQ1_SHIFT)) & VPU_VPU_DEC_VPU_RESET_REQ_CONTROL_REG_VM_VARST_REQ1_MASK)

#define VPU_VPU_DEC_VPU_RESET_REQ_CONTROL_REG_VM_VBRST_REQ1_MASK (0x2000000U)
#define VPU_VPU_DEC_VPU_RESET_REQ_CONTROL_REG_VM_VBRST_REQ1_SHIFT (25U)
#define VPU_VPU_DEC_VPU_RESET_REQ_CONTROL_REG_VM_VBRST_REQ1(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_RESET_REQ_CONTROL_REG_VM_VBRST_REQ1_SHIFT)) & VPU_VPU_DEC_VPU_RESET_REQ_CONTROL_REG_VM_VBRST_REQ1_MASK)

#define VPU_VPU_DEC_VPU_RESET_REQ_CONTROL_REG_VM_VARST_REQ0_MASK (0x4000000U)
#define VPU_VPU_DEC_VPU_RESET_REQ_CONTROL_REG_VM_VARST_REQ0_SHIFT (26U)
#define VPU_VPU_DEC_VPU_RESET_REQ_CONTROL_REG_VM_VARST_REQ0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_RESET_REQ_CONTROL_REG_VM_VARST_REQ0_SHIFT)) & VPU_VPU_DEC_VPU_RESET_REQ_CONTROL_REG_VM_VARST_REQ0_MASK)

#define VPU_VPU_DEC_VPU_RESET_REQ_CONTROL_REG_VM_VBRST_REQ0_MASK (0x8000000U)
#define VPU_VPU_DEC_VPU_RESET_REQ_CONTROL_REG_VM_VBRST_REQ0_SHIFT (27U)
#define VPU_VPU_DEC_VPU_RESET_REQ_CONTROL_REG_VM_VBRST_REQ0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_RESET_REQ_CONTROL_REG_VM_VBRST_REQ0_SHIFT)) & VPU_VPU_DEC_VPU_RESET_REQ_CONTROL_REG_VM_VBRST_REQ0_MASK)
/*! @} */

/*! @name VPU_RESET_STATUS_CONTROL_REG - VPU Reset Status */
/*! @{ */

#define VPU_VPU_DEC_VPU_RESET_STATUS_CONTROL_REG_CRST_STS_MASK (0xFFU)
#define VPU_VPU_DEC_VPU_RESET_STATUS_CONTROL_REG_CRST_STS_SHIFT (0U)
#define VPU_VPU_DEC_VPU_RESET_STATUS_CONTROL_REG_CRST_STS(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_RESET_STATUS_CONTROL_REG_CRST_STS_SHIFT)) & VPU_VPU_DEC_VPU_RESET_STATUS_CONTROL_REG_CRST_STS_MASK)

#define VPU_VPU_DEC_VPU_RESET_STATUS_CONTROL_REG_BRST_STS_MASK (0xFF00U)
#define VPU_VPU_DEC_VPU_RESET_STATUS_CONTROL_REG_BRST_STS_SHIFT (8U)
#define VPU_VPU_DEC_VPU_RESET_STATUS_CONTROL_REG_BRST_STS(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_RESET_STATUS_CONTROL_REG_BRST_STS_SHIFT)) & VPU_VPU_DEC_VPU_RESET_STATUS_CONTROL_REG_BRST_STS_MASK)

#define VPU_VPU_DEC_VPU_RESET_STATUS_CONTROL_REG_ARST_STS_MASK (0xFF0000U)
#define VPU_VPU_DEC_VPU_RESET_STATUS_CONTROL_REG_ARST_STS_SHIFT (16U)
#define VPU_VPU_DEC_VPU_RESET_STATUS_CONTROL_REG_ARST_STS(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_RESET_STATUS_CONTROL_REG_ARST_STS_SHIFT)) & VPU_VPU_DEC_VPU_RESET_STATUS_CONTROL_REG_ARST_STS_MASK)

#define VPU_VPU_DEC_VPU_RESET_STATUS_CONTROL_REG_VARST_STS1_MASK (0x1000000U)
#define VPU_VPU_DEC_VPU_RESET_STATUS_CONTROL_REG_VARST_STS1_SHIFT (24U)
#define VPU_VPU_DEC_VPU_RESET_STATUS_CONTROL_REG_VARST_STS1(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_RESET_STATUS_CONTROL_REG_VARST_STS1_SHIFT)) & VPU_VPU_DEC_VPU_RESET_STATUS_CONTROL_REG_VARST_STS1_MASK)

#define VPU_VPU_DEC_VPU_RESET_STATUS_CONTROL_REG_VBRST_STS1_MASK (0x2000000U)
#define VPU_VPU_DEC_VPU_RESET_STATUS_CONTROL_REG_VBRST_STS1_SHIFT (25U)
#define VPU_VPU_DEC_VPU_RESET_STATUS_CONTROL_REG_VBRST_STS1(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_RESET_STATUS_CONTROL_REG_VBRST_STS1_SHIFT)) & VPU_VPU_DEC_VPU_RESET_STATUS_CONTROL_REG_VBRST_STS1_MASK)

#define VPU_VPU_DEC_VPU_RESET_STATUS_CONTROL_REG_VARST_STS0_MASK (0x4000000U)
#define VPU_VPU_DEC_VPU_RESET_STATUS_CONTROL_REG_VARST_STS0_SHIFT (26U)
#define VPU_VPU_DEC_VPU_RESET_STATUS_CONTROL_REG_VARST_STS0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_RESET_STATUS_CONTROL_REG_VARST_STS0_SHIFT)) & VPU_VPU_DEC_VPU_RESET_STATUS_CONTROL_REG_VARST_STS0_MASK)

#define VPU_VPU_DEC_VPU_RESET_STATUS_CONTROL_REG_VBRST_STS0_MASK (0x8000000U)
#define VPU_VPU_DEC_VPU_RESET_STATUS_CONTROL_REG_VBRST_STS0_SHIFT (27U)
#define VPU_VPU_DEC_VPU_RESET_STATUS_CONTROL_REG_VBRST_STS0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_RESET_STATUS_CONTROL_REG_VBRST_STS0_SHIFT)) & VPU_VPU_DEC_VPU_RESET_STATUS_CONTROL_REG_VBRST_STS0_MASK)
/*! @} */

/*! @name VPU_RESET_STATUS_CONTROL_REG_VM - VPU Reset Status */
/*! @{ */

#define VPU_VPU_DEC_VPU_RESET_STATUS_CONTROL_REG_VM_CRST_STS_MASK (0xFFU)
#define VPU_VPU_DEC_VPU_RESET_STATUS_CONTROL_REG_VM_CRST_STS_SHIFT (0U)
#define VPU_VPU_DEC_VPU_RESET_STATUS_CONTROL_REG_VM_CRST_STS(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_RESET_STATUS_CONTROL_REG_VM_CRST_STS_SHIFT)) & VPU_VPU_DEC_VPU_RESET_STATUS_CONTROL_REG_VM_CRST_STS_MASK)

#define VPU_VPU_DEC_VPU_RESET_STATUS_CONTROL_REG_VM_BRST_STS_MASK (0xFF00U)
#define VPU_VPU_DEC_VPU_RESET_STATUS_CONTROL_REG_VM_BRST_STS_SHIFT (8U)
#define VPU_VPU_DEC_VPU_RESET_STATUS_CONTROL_REG_VM_BRST_STS(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_RESET_STATUS_CONTROL_REG_VM_BRST_STS_SHIFT)) & VPU_VPU_DEC_VPU_RESET_STATUS_CONTROL_REG_VM_BRST_STS_MASK)

#define VPU_VPU_DEC_VPU_RESET_STATUS_CONTROL_REG_VM_ARST_STS_MASK (0xFF0000U)
#define VPU_VPU_DEC_VPU_RESET_STATUS_CONTROL_REG_VM_ARST_STS_SHIFT (16U)
#define VPU_VPU_DEC_VPU_RESET_STATUS_CONTROL_REG_VM_ARST_STS(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_RESET_STATUS_CONTROL_REG_VM_ARST_STS_SHIFT)) & VPU_VPU_DEC_VPU_RESET_STATUS_CONTROL_REG_VM_ARST_STS_MASK)

#define VPU_VPU_DEC_VPU_RESET_STATUS_CONTROL_REG_VM_VARST_STS1_MASK (0x1000000U)
#define VPU_VPU_DEC_VPU_RESET_STATUS_CONTROL_REG_VM_VARST_STS1_SHIFT (24U)
#define VPU_VPU_DEC_VPU_RESET_STATUS_CONTROL_REG_VM_VARST_STS1(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_RESET_STATUS_CONTROL_REG_VM_VARST_STS1_SHIFT)) & VPU_VPU_DEC_VPU_RESET_STATUS_CONTROL_REG_VM_VARST_STS1_MASK)

#define VPU_VPU_DEC_VPU_RESET_STATUS_CONTROL_REG_VM_VBRST_STS1_MASK (0x2000000U)
#define VPU_VPU_DEC_VPU_RESET_STATUS_CONTROL_REG_VM_VBRST_STS1_SHIFT (25U)
#define VPU_VPU_DEC_VPU_RESET_STATUS_CONTROL_REG_VM_VBRST_STS1(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_RESET_STATUS_CONTROL_REG_VM_VBRST_STS1_SHIFT)) & VPU_VPU_DEC_VPU_RESET_STATUS_CONTROL_REG_VM_VBRST_STS1_MASK)

#define VPU_VPU_DEC_VPU_RESET_STATUS_CONTROL_REG_VM_VARST_STS0_MASK (0x4000000U)
#define VPU_VPU_DEC_VPU_RESET_STATUS_CONTROL_REG_VM_VARST_STS0_SHIFT (26U)
#define VPU_VPU_DEC_VPU_RESET_STATUS_CONTROL_REG_VM_VARST_STS0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_RESET_STATUS_CONTROL_REG_VM_VARST_STS0_SHIFT)) & VPU_VPU_DEC_VPU_RESET_STATUS_CONTROL_REG_VM_VARST_STS0_MASK)

#define VPU_VPU_DEC_VPU_RESET_STATUS_CONTROL_REG_VM_VBRST_STS0_MASK (0x8000000U)
#define VPU_VPU_DEC_VPU_RESET_STATUS_CONTROL_REG_VM_VBRST_STS0_SHIFT (27U)
#define VPU_VPU_DEC_VPU_RESET_STATUS_CONTROL_REG_VM_VBRST_STS0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_RESET_STATUS_CONTROL_REG_VM_VBRST_STS0_SHIFT)) & VPU_VPU_DEC_VPU_RESET_STATUS_CONTROL_REG_VM_VBRST_STS0_MASK)
/*! @} */

/*! @name VCPU_RESTART_CONTROL_REG - V-CPU Restart Request */
/*! @{ */

#define VPU_VPU_DEC_VCPU_RESTART_CONTROL_REG_VCPU_RESTART_MASK (0x1U)
#define VPU_VPU_DEC_VCPU_RESTART_CONTROL_REG_VCPU_RESTART_SHIFT (0U)
#define VPU_VPU_DEC_VCPU_RESTART_CONTROL_REG_VCPU_RESTART(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VCPU_RESTART_CONTROL_REG_VCPU_RESTART_SHIFT)) & VPU_VPU_DEC_VCPU_RESTART_CONTROL_REG_VCPU_RESTART_MASK)
/*! @} */

/*! @name VPU_CLK_MASK_CONTROL_REG - VPU Clock Control */
/*! @{ */

#define VPU_VPU_DEC_VPU_CLK_MASK_CONTROL_REG_CCLK_EN_MASK (0xFFU)
#define VPU_VPU_DEC_VPU_CLK_MASK_CONTROL_REG_CCLK_EN_SHIFT (0U)
#define VPU_VPU_DEC_VPU_CLK_MASK_CONTROL_REG_CCLK_EN(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_CLK_MASK_CONTROL_REG_CCLK_EN_SHIFT)) & VPU_VPU_DEC_VPU_CLK_MASK_CONTROL_REG_CCLK_EN_MASK)

#define VPU_VPU_DEC_VPU_CLK_MASK_CONTROL_REG_BCLK_EN_MASK (0xFF00U)
#define VPU_VPU_DEC_VPU_CLK_MASK_CONTROL_REG_BCLK_EN_SHIFT (8U)
#define VPU_VPU_DEC_VPU_CLK_MASK_CONTROL_REG_BCLK_EN(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_CLK_MASK_CONTROL_REG_BCLK_EN_SHIFT)) & VPU_VPU_DEC_VPU_CLK_MASK_CONTROL_REG_BCLK_EN_MASK)

#define VPU_VPU_DEC_VPU_CLK_MASK_CONTROL_REG_ACLK_EN_MASK (0xFF0000U)
#define VPU_VPU_DEC_VPU_CLK_MASK_CONTROL_REG_ACLK_EN_SHIFT (16U)
#define VPU_VPU_DEC_VPU_CLK_MASK_CONTROL_REG_ACLK_EN(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_CLK_MASK_CONTROL_REG_ACLK_EN_SHIFT)) & VPU_VPU_DEC_VPU_CLK_MASK_CONTROL_REG_ACLK_EN_MASK)

#define VPU_VPU_DEC_VPU_CLK_MASK_CONTROL_REG_ACLK_CPU_EN_MASK (0x1000000U)
#define VPU_VPU_DEC_VPU_CLK_MASK_CONTROL_REG_ACLK_CPU_EN_SHIFT (24U)
#define VPU_VPU_DEC_VPU_CLK_MASK_CONTROL_REG_ACLK_CPU_EN(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_CLK_MASK_CONTROL_REG_ACLK_CPU_EN_SHIFT)) & VPU_VPU_DEC_VPU_CLK_MASK_CONTROL_REG_ACLK_CPU_EN_MASK)

#define VPU_VPU_DEC_VPU_CLK_MASK_CONTROL_REG_VCLK_CPU_EN_MASK (0x2000000U)
#define VPU_VPU_DEC_VPU_CLK_MASK_CONTROL_REG_VCLK_CPU_EN_SHIFT (25U)
#define VPU_VPU_DEC_VPU_CLK_MASK_CONTROL_REG_VCLK_CPU_EN(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_CLK_MASK_CONTROL_REG_VCLK_CPU_EN_SHIFT)) & VPU_VPU_DEC_VPU_CLK_MASK_CONTROL_REG_VCLK_CPU_EN_MASK)

#define VPU_VPU_DEC_VPU_CLK_MASK_CONTROL_REG_CCLK_CPU_EN_MASK (0x4000000U)
#define VPU_VPU_DEC_VPU_CLK_MASK_CONTROL_REG_CCLK_CPU_EN_SHIFT (26U)
#define VPU_VPU_DEC_VPU_CLK_MASK_CONTROL_REG_CCLK_CPU_EN(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_CLK_MASK_CONTROL_REG_CCLK_CPU_EN_SHIFT)) & VPU_VPU_DEC_VPU_CLK_MASK_CONTROL_REG_CCLK_CPU_EN_MASK)
/*! @} */

/*! @name VPU_CLK_MASK_CONTROL_REG_VM - VPU Clock Control */
/*! @{ */

#define VPU_VPU_DEC_VPU_CLK_MASK_CONTROL_REG_VM_CCLK_EN_MASK (0xFFU)
#define VPU_VPU_DEC_VPU_CLK_MASK_CONTROL_REG_VM_CCLK_EN_SHIFT (0U)
#define VPU_VPU_DEC_VPU_CLK_MASK_CONTROL_REG_VM_CCLK_EN(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_CLK_MASK_CONTROL_REG_VM_CCLK_EN_SHIFT)) & VPU_VPU_DEC_VPU_CLK_MASK_CONTROL_REG_VM_CCLK_EN_MASK)

#define VPU_VPU_DEC_VPU_CLK_MASK_CONTROL_REG_VM_BCLK_EN_MASK (0xFF00U)
#define VPU_VPU_DEC_VPU_CLK_MASK_CONTROL_REG_VM_BCLK_EN_SHIFT (8U)
#define VPU_VPU_DEC_VPU_CLK_MASK_CONTROL_REG_VM_BCLK_EN(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_CLK_MASK_CONTROL_REG_VM_BCLK_EN_SHIFT)) & VPU_VPU_DEC_VPU_CLK_MASK_CONTROL_REG_VM_BCLK_EN_MASK)

#define VPU_VPU_DEC_VPU_CLK_MASK_CONTROL_REG_VM_ACLK_EN_MASK (0xFF0000U)
#define VPU_VPU_DEC_VPU_CLK_MASK_CONTROL_REG_VM_ACLK_EN_SHIFT (16U)
#define VPU_VPU_DEC_VPU_CLK_MASK_CONTROL_REG_VM_ACLK_EN(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_CLK_MASK_CONTROL_REG_VM_ACLK_EN_SHIFT)) & VPU_VPU_DEC_VPU_CLK_MASK_CONTROL_REG_VM_ACLK_EN_MASK)

#define VPU_VPU_DEC_VPU_CLK_MASK_CONTROL_REG_VM_ACLK_CPU_EN_MASK (0x1000000U)
#define VPU_VPU_DEC_VPU_CLK_MASK_CONTROL_REG_VM_ACLK_CPU_EN_SHIFT (24U)
#define VPU_VPU_DEC_VPU_CLK_MASK_CONTROL_REG_VM_ACLK_CPU_EN(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_CLK_MASK_CONTROL_REG_VM_ACLK_CPU_EN_SHIFT)) & VPU_VPU_DEC_VPU_CLK_MASK_CONTROL_REG_VM_ACLK_CPU_EN_MASK)

#define VPU_VPU_DEC_VPU_CLK_MASK_CONTROL_REG_VM_VCLK_CPU_EN_MASK (0x2000000U)
#define VPU_VPU_DEC_VPU_CLK_MASK_CONTROL_REG_VM_VCLK_CPU_EN_SHIFT (25U)
#define VPU_VPU_DEC_VPU_CLK_MASK_CONTROL_REG_VM_VCLK_CPU_EN(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_CLK_MASK_CONTROL_REG_VM_VCLK_CPU_EN_SHIFT)) & VPU_VPU_DEC_VPU_CLK_MASK_CONTROL_REG_VM_VCLK_CPU_EN_MASK)

#define VPU_VPU_DEC_VPU_CLK_MASK_CONTROL_REG_VM_CCLK_CPU_EN_MASK (0x4000000U)
#define VPU_VPU_DEC_VPU_CLK_MASK_CONTROL_REG_VM_CCLK_CPU_EN_SHIFT (26U)
#define VPU_VPU_DEC_VPU_CLK_MASK_CONTROL_REG_VM_CCLK_CPU_EN(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_CLK_MASK_CONTROL_REG_VM_CCLK_CPU_EN_SHIFT)) & VPU_VPU_DEC_VPU_CLK_MASK_CONTROL_REG_VM_CCLK_CPU_EN_MASK)
/*! @} */

/*! @name VPU_REMAP_CTRL_CONTROL_REG - Remap Control */
/*! @{ */

#define VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_REMAP_PSIZE_MASK (0x1FFU)
#define VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_REMAP_PSIZE_SHIFT (0U)
#define VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_REMAP_PSIZE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_REMAP_PSIZE_SHIFT)) & VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_REMAP_PSIZE_MASK)

#define VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_REMAP_BUS_ERR_MASK (0x200U)
#define VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_REMAP_BUS_ERR_SHIFT (9U)
#define VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_REMAP_BUS_ERR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_REMAP_BUS_ERR_SHIFT)) & VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_REMAP_BUS_ERR_MASK)

#define VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_REMAP_BYPASS_MASK (0x400U)
#define VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_REMAP_BYPASS_SHIFT (10U)
#define VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_REMAP_BYPASS(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_REMAP_BYPASS_SHIFT)) & VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_REMAP_BYPASS_MASK)

#define VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_RSVD3_MASK (0x800U)
#define VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_RSVD3_SHIFT (11U)
#define VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_RSVD3(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_RSVD3_SHIFT)) & VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_RSVD3_MASK)

#define VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_REMAP_IDX_MASK (0x3000U)
#define VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_REMAP_IDX_SHIFT (12U)
#define VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_REMAP_IDX(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_REMAP_IDX_SHIFT)) & VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_REMAP_IDX_MASK)

#define VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_RSVD2_MASK (0xC000U)
#define VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_RSVD2_SHIFT (14U)
#define VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_RSVD2(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_RSVD2_SHIFT)) & VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_RSVD2_MASK)

#define VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_ENDIAN_MASK (0xF0000U)
#define VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_ENDIAN_SHIFT (16U)
#define VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_ENDIAN(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_ENDIAN_SHIFT)) & VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_ENDIAN_MASK)

#define VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_AXIID_PROC_MASK (0xF00000U)
#define VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_AXIID_PROC_SHIFT (20U)
#define VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_AXIID_PROC(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_AXIID_PROC_SHIFT)) & VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_AXIID_PROC_MASK)

#define VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_RSVD1_MASK (0x1F000000U)
#define VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_RSVD1_SHIFT (24U)
#define VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_RSVD1(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_RSVD1_SHIFT)) & VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_RSVD1_MASK)

#define VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_REMAP_INF_ERR_MASK (0x20000000U)
#define VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_REMAP_INF_ERR_SHIFT (29U)
#define VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_REMAP_INF_ERR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_REMAP_INF_ERR_SHIFT)) & VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_REMAP_INF_ERR_MASK)

#define VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_REMAP_INF_BYPASS_MASK (0x40000000U)
#define VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_REMAP_INF_BYPASS_SHIFT (30U)
#define VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_REMAP_INF_BYPASS(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_REMAP_INF_BYPASS_SHIFT)) & VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_REMAP_INF_BYPASS_MASK)

#define VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_RSVD0_MASK (0x80000000U)
#define VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_RSVD0_SHIFT (31U)
#define VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_RSVD0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_RSVD0_SHIFT)) & VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_RSVD0_MASK)
/*! @} */

/*! @name VPU_REMAP_CTRL_CONTROL_REG_VM - Remap Control */
/*! @{ */

#define VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_VM_REMAP_PSIZE_MASK (0x1FFU)
#define VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_VM_REMAP_PSIZE_SHIFT (0U)
#define VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_VM_REMAP_PSIZE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_VM_REMAP_PSIZE_SHIFT)) & VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_VM_REMAP_PSIZE_MASK)

#define VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_VM_REMAP_BUS_ERR_MASK (0x200U)
#define VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_VM_REMAP_BUS_ERR_SHIFT (9U)
#define VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_VM_REMAP_BUS_ERR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_VM_REMAP_BUS_ERR_SHIFT)) & VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_VM_REMAP_BUS_ERR_MASK)

#define VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_VM_REMAP_BYPASS_MASK (0x400U)
#define VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_VM_REMAP_BYPASS_SHIFT (10U)
#define VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_VM_REMAP_BYPASS(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_VM_REMAP_BYPASS_SHIFT)) & VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_VM_REMAP_BYPASS_MASK)

#define VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_VM_RSVD3_MASK (0x800U)
#define VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_VM_RSVD3_SHIFT (11U)
#define VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_VM_RSVD3(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_VM_RSVD3_SHIFT)) & VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_VM_RSVD3_MASK)

#define VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_VM_REMAP_IDX_MASK (0x3000U)
#define VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_VM_REMAP_IDX_SHIFT (12U)
#define VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_VM_REMAP_IDX(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_VM_REMAP_IDX_SHIFT)) & VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_VM_REMAP_IDX_MASK)

#define VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_VM_RSVD2_MASK (0xC000U)
#define VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_VM_RSVD2_SHIFT (14U)
#define VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_VM_RSVD2(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_VM_RSVD2_SHIFT)) & VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_VM_RSVD2_MASK)

#define VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_VM_ENDIAN_MASK (0xF0000U)
#define VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_VM_ENDIAN_SHIFT (16U)
#define VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_VM_ENDIAN(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_VM_ENDIAN_SHIFT)) & VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_VM_ENDIAN_MASK)

#define VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_VM_AXIID_PROC_MASK (0xF00000U)
#define VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_VM_AXIID_PROC_SHIFT (20U)
#define VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_VM_AXIID_PROC(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_VM_AXIID_PROC_SHIFT)) & VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_VM_AXIID_PROC_MASK)

#define VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_VM_RSVD1_MASK (0x1F000000U)
#define VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_VM_RSVD1_SHIFT (24U)
#define VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_VM_RSVD1(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_VM_RSVD1_SHIFT)) & VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_VM_RSVD1_MASK)

#define VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_VM_REMAP_INF_ERR_MASK (0x20000000U)
#define VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_VM_REMAP_INF_ERR_SHIFT (29U)
#define VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_VM_REMAP_INF_ERR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_VM_REMAP_INF_ERR_SHIFT)) & VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_VM_REMAP_INF_ERR_MASK)

#define VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_VM_REMAP_INF_BYPASS_MASK (0x40000000U)
#define VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_VM_REMAP_INF_BYPASS_SHIFT (30U)
#define VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_VM_REMAP_INF_BYPASS(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_VM_REMAP_INF_BYPASS_SHIFT)) & VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_VM_REMAP_INF_BYPASS_MASK)

#define VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_VM_RSVD0_MASK (0x80000000U)
#define VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_VM_RSVD0_SHIFT (31U)
#define VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_VM_RSVD0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_VM_RSVD0_SHIFT)) & VPU_VPU_DEC_VPU_REMAP_CTRL_CONTROL_REG_VM_RSVD0_MASK)
/*! @} */

/*! @name VPU_REMAP_VADDR_CONTROL_REG - Remap Virutal Address */
/*! @{ */

#define VPU_VPU_DEC_VPU_REMAP_VADDR_CONTROL_REG_VPU_REMAP_VADDR_MASK (0xFFFFF000U)
#define VPU_VPU_DEC_VPU_REMAP_VADDR_CONTROL_REG_VPU_REMAP_VADDR_SHIFT (12U)
#define VPU_VPU_DEC_VPU_REMAP_VADDR_CONTROL_REG_VPU_REMAP_VADDR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_REMAP_VADDR_CONTROL_REG_VPU_REMAP_VADDR_SHIFT)) & VPU_VPU_DEC_VPU_REMAP_VADDR_CONTROL_REG_VPU_REMAP_VADDR_MASK)
/*! @} */

/*! @name VPU_REMAP_VADDR_CONTROL_REG_VM - Remap Virutal Address */
/*! @{ */

#define VPU_VPU_DEC_VPU_REMAP_VADDR_CONTROL_REG_VM_VPU_REMAP_VADDR_MASK (0xFFFFF000U)
#define VPU_VPU_DEC_VPU_REMAP_VADDR_CONTROL_REG_VM_VPU_REMAP_VADDR_SHIFT (12U)
#define VPU_VPU_DEC_VPU_REMAP_VADDR_CONTROL_REG_VM_VPU_REMAP_VADDR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_REMAP_VADDR_CONTROL_REG_VM_VPU_REMAP_VADDR_SHIFT)) & VPU_VPU_DEC_VPU_REMAP_VADDR_CONTROL_REG_VM_VPU_REMAP_VADDR_MASK)
/*! @} */

/*! @name VPU_REMAP_PADDR_CONTROL_REG - Remap Physical Address */
/*! @{ */

#define VPU_VPU_DEC_VPU_REMAP_PADDR_CONTROL_REG_VPU_REMAP_PADDR_MASK (0xFFFFF000U)
#define VPU_VPU_DEC_VPU_REMAP_PADDR_CONTROL_REG_VPU_REMAP_PADDR_SHIFT (12U)
#define VPU_VPU_DEC_VPU_REMAP_PADDR_CONTROL_REG_VPU_REMAP_PADDR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_REMAP_PADDR_CONTROL_REG_VPU_REMAP_PADDR_SHIFT)) & VPU_VPU_DEC_VPU_REMAP_PADDR_CONTROL_REG_VPU_REMAP_PADDR_MASK)
/*! @} */

/*! @name VPU_REMAP_PADDR_CONTROL_REG_VM - Remap Physical Address */
/*! @{ */

#define VPU_VPU_DEC_VPU_REMAP_PADDR_CONTROL_REG_VM_VPU_REMAP_PADDR_MASK (0xFFFFF000U)
#define VPU_VPU_DEC_VPU_REMAP_PADDR_CONTROL_REG_VM_VPU_REMAP_PADDR_SHIFT (12U)
#define VPU_VPU_DEC_VPU_REMAP_PADDR_CONTROL_REG_VM_VPU_REMAP_PADDR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_REMAP_PADDR_CONTROL_REG_VM_VPU_REMAP_PADDR_SHIFT)) & VPU_VPU_DEC_VPU_REMAP_PADDR_CONTROL_REG_VM_VPU_REMAP_PADDR_MASK)
/*! @} */

/*! @name VPU_REMAP_CORE_START_CONTROL_REG - VPU Start Request */
/*! @{ */

#define VPU_VPU_DEC_VPU_REMAP_CORE_START_CONTROL_REG_VPU_REMAP_CORE_START_MASK (0x1U)
#define VPU_VPU_DEC_VPU_REMAP_CORE_START_CONTROL_REG_VPU_REMAP_CORE_START_SHIFT (0U)
#define VPU_VPU_DEC_VPU_REMAP_CORE_START_CONTROL_REG_VPU_REMAP_CORE_START(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_REMAP_CORE_START_CONTROL_REG_VPU_REMAP_CORE_START_SHIFT)) & VPU_VPU_DEC_VPU_REMAP_CORE_START_CONTROL_REG_VPU_REMAP_CORE_START_MASK)
/*! @} */

/*! @name VPU_REMAP_CORE_START_CONTROL_REG_VM - VPU Start Request */
/*! @{ */

#define VPU_VPU_DEC_VPU_REMAP_CORE_START_CONTROL_REG_VM_VPU_REMAP_CORE_START_MASK (0x1U)
#define VPU_VPU_DEC_VPU_REMAP_CORE_START_CONTROL_REG_VM_VPU_REMAP_CORE_START_SHIFT (0U)
#define VPU_VPU_DEC_VPU_REMAP_CORE_START_CONTROL_REG_VM_VPU_REMAP_CORE_START(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_REMAP_CORE_START_CONTROL_REG_VM_VPU_REMAP_CORE_START_SHIFT)) & VPU_VPU_DEC_VPU_REMAP_CORE_START_CONTROL_REG_VM_VPU_REMAP_CORE_START_MASK)
/*! @} */

/*! @name VPU_BUSY_STATUS_CONTROL_REG - VPU Busy Status */
/*! @{ */

#define VPU_VPU_DEC_VPU_BUSY_STATUS_CONTROL_REG_VPU_BUSY_STATUS_MASK (0x1U)
#define VPU_VPU_DEC_VPU_BUSY_STATUS_CONTROL_REG_VPU_BUSY_STATUS_SHIFT (0U)
#define VPU_VPU_DEC_VPU_BUSY_STATUS_CONTROL_REG_VPU_BUSY_STATUS(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_BUSY_STATUS_CONTROL_REG_VPU_BUSY_STATUS_SHIFT)) & VPU_VPU_DEC_VPU_BUSY_STATUS_CONTROL_REG_VPU_BUSY_STATUS_MASK)
/*! @} */

/*! @name VPU_BUSY_STATUS_CONTROL_REG_VM - VPU Busy Status */
/*! @{ */

#define VPU_VPU_DEC_VPU_BUSY_STATUS_CONTROL_REG_VM_VPU_BUSY_STATUS_MASK (0x1U)
#define VPU_VPU_DEC_VPU_BUSY_STATUS_CONTROL_REG_VM_VPU_BUSY_STATUS_SHIFT (0U)
#define VPU_VPU_DEC_VPU_BUSY_STATUS_CONTROL_REG_VM_VPU_BUSY_STATUS(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_BUSY_STATUS_CONTROL_REG_VM_VPU_BUSY_STATUS_SHIFT)) & VPU_VPU_DEC_VPU_BUSY_STATUS_CONTROL_REG_VM_VPU_BUSY_STATUS_MASK)
/*! @} */

/*! @name VPU_HALT_STATUS_CONTROL_REG - VPU Halt Status */
/*! @{ */

#define VPU_VPU_DEC_VPU_HALT_STATUS_CONTROL_REG_VPU_HALT_STATUS_DEBUG_MASK (0xFU)
#define VPU_VPU_DEC_VPU_HALT_STATUS_CONTROL_REG_VPU_HALT_STATUS_DEBUG_SHIFT (0U)
#define VPU_VPU_DEC_VPU_HALT_STATUS_CONTROL_REG_VPU_HALT_STATUS_DEBUG(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_HALT_STATUS_CONTROL_REG_VPU_HALT_STATUS_DEBUG_SHIFT)) & VPU_VPU_DEC_VPU_HALT_STATUS_CONTROL_REG_VPU_HALT_STATUS_DEBUG_MASK)

#define VPU_VPU_DEC_VPU_HALT_STATUS_CONTROL_REG_VPU_HALT_STATUS_MASK (0x10U)
#define VPU_VPU_DEC_VPU_HALT_STATUS_CONTROL_REG_VPU_HALT_STATUS_SHIFT (4U)
#define VPU_VPU_DEC_VPU_HALT_STATUS_CONTROL_REG_VPU_HALT_STATUS(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_HALT_STATUS_CONTROL_REG_VPU_HALT_STATUS_SHIFT)) & VPU_VPU_DEC_VPU_HALT_STATUS_CONTROL_REG_VPU_HALT_STATUS_MASK)
/*! @} */

/*! @name VPU_HALT_STATUS_CONTROL_REG_VM - VPU Halt Status */
/*! @{ */

#define VPU_VPU_DEC_VPU_HALT_STATUS_CONTROL_REG_VM_VPU_HALT_STATUS_DEBUG_MASK (0xFU)
#define VPU_VPU_DEC_VPU_HALT_STATUS_CONTROL_REG_VM_VPU_HALT_STATUS_DEBUG_SHIFT (0U)
#define VPU_VPU_DEC_VPU_HALT_STATUS_CONTROL_REG_VM_VPU_HALT_STATUS_DEBUG(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_HALT_STATUS_CONTROL_REG_VM_VPU_HALT_STATUS_DEBUG_SHIFT)) & VPU_VPU_DEC_VPU_HALT_STATUS_CONTROL_REG_VM_VPU_HALT_STATUS_DEBUG_MASK)

#define VPU_VPU_DEC_VPU_HALT_STATUS_CONTROL_REG_VM_VPU_HALT_STATUS_MASK (0x10U)
#define VPU_VPU_DEC_VPU_HALT_STATUS_CONTROL_REG_VM_VPU_HALT_STATUS_SHIFT (4U)
#define VPU_VPU_DEC_VPU_HALT_STATUS_CONTROL_REG_VM_VPU_HALT_STATUS(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_HALT_STATUS_CONTROL_REG_VM_VPU_HALT_STATUS_SHIFT)) & VPU_VPU_DEC_VPU_HALT_STATUS_CONTROL_REG_VM_VPU_HALT_STATUS_MASK)
/*! @} */

/*! @name VPU_VCPU_STATUS_CONTROL_REG - VPU_VCPU_STATUS */
/*! @{ */

#define VPU_VPU_DEC_VPU_VCPU_STATUS_CONTROL_REG_VPU_VCPU_STATUS_MASK (0x7FFFU)
#define VPU_VPU_DEC_VPU_VCPU_STATUS_CONTROL_REG_VPU_VCPU_STATUS_SHIFT (0U)
#define VPU_VPU_DEC_VPU_VCPU_STATUS_CONTROL_REG_VPU_VCPU_STATUS(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VCPU_STATUS_CONTROL_REG_VPU_VCPU_STATUS_SHIFT)) & VPU_VPU_DEC_VPU_VCPU_STATUS_CONTROL_REG_VPU_VCPU_STATUS_MASK)

#define VPU_VPU_DEC_VPU_VCPU_STATUS_CONTROL_REG_VCPU_BUS_STATUS_MASK (0xFFFF0000U)
#define VPU_VPU_DEC_VPU_VCPU_STATUS_CONTROL_REG_VCPU_BUS_STATUS_SHIFT (16U)
#define VPU_VPU_DEC_VPU_VCPU_STATUS_CONTROL_REG_VCPU_BUS_STATUS(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VCPU_STATUS_CONTROL_REG_VCPU_BUS_STATUS_SHIFT)) & VPU_VPU_DEC_VPU_VCPU_STATUS_CONTROL_REG_VCPU_BUS_STATUS_MASK)
/*! @} */

/*! @name VPU_VCPU_STATUS_CONTROL_REG_VM - VPU_VCPU_STATUS */
/*! @{ */

#define VPU_VPU_DEC_VPU_VCPU_STATUS_CONTROL_REG_VM_VPU_VCPU_STATUS_MASK (0x7FFFU)
#define VPU_VPU_DEC_VPU_VCPU_STATUS_CONTROL_REG_VM_VPU_VCPU_STATUS_SHIFT (0U)
#define VPU_VPU_DEC_VPU_VCPU_STATUS_CONTROL_REG_VM_VPU_VCPU_STATUS(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VCPU_STATUS_CONTROL_REG_VM_VPU_VCPU_STATUS_SHIFT)) & VPU_VPU_DEC_VPU_VCPU_STATUS_CONTROL_REG_VM_VPU_VCPU_STATUS_MASK)

#define VPU_VPU_DEC_VPU_VCPU_STATUS_CONTROL_REG_VM_VCPU_BUS_STATUS_MASK (0xFFFF0000U)
#define VPU_VPU_DEC_VPU_VCPU_STATUS_CONTROL_REG_VM_VCPU_BUS_STATUS_SHIFT (16U)
#define VPU_VPU_DEC_VPU_VCPU_STATUS_CONTROL_REG_VM_VCPU_BUS_STATUS(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_VCPU_STATUS_CONTROL_REG_VM_VCPU_BUS_STATUS_SHIFT)) & VPU_VPU_DEC_VPU_VCPU_STATUS_CONTROL_REG_VM_VCPU_BUS_STATUS_MASK)
/*! @} */

/*! @name RET_FIO_STATUS_CONTROL_REG - RET_FIO_STATUS */
/*! @{ */

#define VPU_VPU_DEC_RET_FIO_STATUS_CONTROL_REG_RSVD0_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_FIO_STATUS_CONTROL_REG_RSVD0_SHIFT (0U)
#define VPU_VPU_DEC_RET_FIO_STATUS_CONTROL_REG_RSVD0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_FIO_STATUS_CONTROL_REG_RSVD0_SHIFT)) & VPU_VPU_DEC_RET_FIO_STATUS_CONTROL_REG_RSVD0_MASK)
/*! @} */

/*! @name RET_FIO_STATUS_CONTROL_REG_VM - RET_FIO_STATUS */
/*! @{ */

#define VPU_VPU_DEC_RET_FIO_STATUS_CONTROL_REG_VM_RSVD0_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_FIO_STATUS_CONTROL_REG_VM_RSVD0_SHIFT (0U)
#define VPU_VPU_DEC_RET_FIO_STATUS_CONTROL_REG_VM_RSVD0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_FIO_STATUS_CONTROL_REG_VM_RSVD0_SHIFT)) & VPU_VPU_DEC_RET_FIO_STATUS_CONTROL_REG_VM_RSVD0_MASK)
/*! @} */

/*! @name RET_PRODUCT_NAME_CONTROL_REG - HW product name */
/*! @{ */

#define VPU_VPU_DEC_RET_PRODUCT_NAME_CONTROL_REG_HW_NAME_MASK (0xFU)
#define VPU_VPU_DEC_RET_PRODUCT_NAME_CONTROL_REG_HW_NAME_SHIFT (0U)
#define VPU_VPU_DEC_RET_PRODUCT_NAME_CONTROL_REG_HW_NAME(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_PRODUCT_NAME_CONTROL_REG_HW_NAME_SHIFT)) & VPU_VPU_DEC_RET_PRODUCT_NAME_CONTROL_REG_HW_NAME_MASK)
/*! @} */

/*! @name RET_PRODUCT_NAME_CONTROL_REG_VM - HW product name */
/*! @{ */

#define VPU_VPU_DEC_RET_PRODUCT_NAME_CONTROL_REG_VM_HW_NAME_MASK (0xFU)
#define VPU_VPU_DEC_RET_PRODUCT_NAME_CONTROL_REG_VM_HW_NAME_SHIFT (0U)
#define VPU_VPU_DEC_RET_PRODUCT_NAME_CONTROL_REG_VM_HW_NAME(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_PRODUCT_NAME_CONTROL_REG_VM_HW_NAME_SHIFT)) & VPU_VPU_DEC_RET_PRODUCT_NAME_CONTROL_REG_VM_HW_NAME_MASK)
/*! @} */

/*! @name RET_PRODUCT_VERSION_CONTROL_REG - HW product version */
/*! @{ */

#define VPU_VPU_DEC_RET_PRODUCT_VERSION_CONTROL_REG_HW_VERSION_MASK (0xFU)
#define VPU_VPU_DEC_RET_PRODUCT_VERSION_CONTROL_REG_HW_VERSION_SHIFT (0U)
#define VPU_VPU_DEC_RET_PRODUCT_VERSION_CONTROL_REG_HW_VERSION(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_PRODUCT_VERSION_CONTROL_REG_HW_VERSION_SHIFT)) & VPU_VPU_DEC_RET_PRODUCT_VERSION_CONTROL_REG_HW_VERSION_MASK)
/*! @} */

/*! @name RET_PRODUCT_VERSION_CONTROL_REG_VM - HW product version */
/*! @{ */

#define VPU_VPU_DEC_RET_PRODUCT_VERSION_CONTROL_REG_VM_HW_VERSION_MASK (0xFU)
#define VPU_VPU_DEC_RET_PRODUCT_VERSION_CONTROL_REG_VM_HW_VERSION_SHIFT (0U)
#define VPU_VPU_DEC_RET_PRODUCT_VERSION_CONTROL_REG_VM_HW_VERSION(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_PRODUCT_VERSION_CONTROL_REG_VM_HW_VERSION_SHIFT)) & VPU_VPU_DEC_RET_PRODUCT_VERSION_CONTROL_REG_VM_HW_VERSION_MASK)
/*! @} */

/*! @name RET_VCPU_CONFIG0_CONTROL_REG - Configuration Information #0 */
/*! @{ */

#define VPU_VPU_DEC_RET_VCPU_CONFIG0_CONTROL_REG_RSVD0_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_VCPU_CONFIG0_CONTROL_REG_RSVD0_SHIFT (0U)
#define VPU_VPU_DEC_RET_VCPU_CONFIG0_CONTROL_REG_RSVD0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_VCPU_CONFIG0_CONTROL_REG_RSVD0_SHIFT)) & VPU_VPU_DEC_RET_VCPU_CONFIG0_CONTROL_REG_RSVD0_MASK)
/*! @} */

/*! @name RET_VCPU_CONFIG0_CONTROL_REG_VM - Configuration Information #0 */
/*! @{ */

#define VPU_VPU_DEC_RET_VCPU_CONFIG0_CONTROL_REG_VM_RSVD0_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_VCPU_CONFIG0_CONTROL_REG_VM_RSVD0_SHIFT (0U)
#define VPU_VPU_DEC_RET_VCPU_CONFIG0_CONTROL_REG_VM_RSVD0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_VCPU_CONFIG0_CONTROL_REG_VM_RSVD0_SHIFT)) & VPU_VPU_DEC_RET_VCPU_CONFIG0_CONTROL_REG_VM_RSVD0_MASK)
/*! @} */

/*! @name RET_VCPU_CONFIG1_CONTROL_REG - Configuration Information #1 */
/*! @{ */

#define VPU_VPU_DEC_RET_VCPU_CONFIG1_CONTROL_REG_RSVD0_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_VCPU_CONFIG1_CONTROL_REG_RSVD0_SHIFT (0U)
#define VPU_VPU_DEC_RET_VCPU_CONFIG1_CONTROL_REG_RSVD0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_VCPU_CONFIG1_CONTROL_REG_RSVD0_SHIFT)) & VPU_VPU_DEC_RET_VCPU_CONFIG1_CONTROL_REG_RSVD0_MASK)
/*! @} */

/*! @name RET_VCPU_CONFIG1_CONTROL_REG_VM - Configuration Information #1 */
/*! @{ */

#define VPU_VPU_DEC_RET_VCPU_CONFIG1_CONTROL_REG_VM_RSVD0_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_VCPU_CONFIG1_CONTROL_REG_VM_RSVD0_SHIFT (0U)
#define VPU_VPU_DEC_RET_VCPU_CONFIG1_CONTROL_REG_VM_RSVD0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_VCPU_CONFIG1_CONTROL_REG_VM_RSVD0_SHIFT)) & VPU_VPU_DEC_RET_VCPU_CONFIG1_CONTROL_REG_VM_RSVD0_MASK)
/*! @} */

/*! @name RET_CODEC_STD_CONTROL_REG - Standard Definition */
/*! @{ */

#define VPU_VPU_DEC_RET_CODEC_STD_CONTROL_REG_CODEC_STD_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_CODEC_STD_CONTROL_REG_CODEC_STD_SHIFT (0U)
#define VPU_VPU_DEC_RET_CODEC_STD_CONTROL_REG_CODEC_STD(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_CODEC_STD_CONTROL_REG_CODEC_STD_SHIFT)) & VPU_VPU_DEC_RET_CODEC_STD_CONTROL_REG_CODEC_STD_MASK)
/*! @} */

/*! @name RET_CODEC_STD_CONTROL_REG_VM - Standard Definition */
/*! @{ */

#define VPU_VPU_DEC_RET_CODEC_STD_CONTROL_REG_VM_CODEC_STD_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_CODEC_STD_CONTROL_REG_VM_CODEC_STD_SHIFT (0U)
#define VPU_VPU_DEC_RET_CODEC_STD_CONTROL_REG_VM_CODEC_STD(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_CODEC_STD_CONTROL_REG_VM_CODEC_STD_SHIFT)) & VPU_VPU_DEC_RET_CODEC_STD_CONTROL_REG_VM_CODEC_STD_MASK)
/*! @} */

/*! @name RET_CONF_DATE_CONTROL_REG - Configuration Date */
/*! @{ */

#define VPU_VPU_DEC_RET_CONF_DATE_CONTROL_REG_HW_DATE_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_CONF_DATE_CONTROL_REG_HW_DATE_SHIFT (0U)
#define VPU_VPU_DEC_RET_CONF_DATE_CONTROL_REG_HW_DATE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_CONF_DATE_CONTROL_REG_HW_DATE_SHIFT)) & VPU_VPU_DEC_RET_CONF_DATE_CONTROL_REG_HW_DATE_MASK)
/*! @} */

/*! @name RET_CONF_DATE_CONTROL_REG_VM - Configuration Date */
/*! @{ */

#define VPU_VPU_DEC_RET_CONF_DATE_CONTROL_REG_VM_HW_DATE_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_CONF_DATE_CONTROL_REG_VM_HW_DATE_SHIFT (0U)
#define VPU_VPU_DEC_RET_CONF_DATE_CONTROL_REG_VM_HW_DATE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_CONF_DATE_CONTROL_REG_VM_HW_DATE_SHIFT)) & VPU_VPU_DEC_RET_CONF_DATE_CONTROL_REG_VM_HW_DATE_MASK)
/*! @} */

/*! @name RET_CONF_REVISION_CONTROL_REG - The revision of H/W configuration */
/*! @{ */

#define VPU_VPU_DEC_RET_CONF_REVISION_CONTROL_REG_HW_REVISION_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_CONF_REVISION_CONTROL_REG_HW_REVISION_SHIFT (0U)
#define VPU_VPU_DEC_RET_CONF_REVISION_CONTROL_REG_HW_REVISION(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_CONF_REVISION_CONTROL_REG_HW_REVISION_SHIFT)) & VPU_VPU_DEC_RET_CONF_REVISION_CONTROL_REG_HW_REVISION_MASK)
/*! @} */

/*! @name RET_CONF_REVISION_CONTROL_REG_VM - The revision of H/W configuration */
/*! @{ */

#define VPU_VPU_DEC_RET_CONF_REVISION_CONTROL_REG_VM_HW_REVISION_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_CONF_REVISION_CONTROL_REG_VM_HW_REVISION_SHIFT (0U)
#define VPU_VPU_DEC_RET_CONF_REVISION_CONTROL_REG_VM_HW_REVISION(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_CONF_REVISION_CONTROL_REG_VM_HW_REVISION_SHIFT)) & VPU_VPU_DEC_RET_CONF_REVISION_CONTROL_REG_VM_HW_REVISION_MASK)
/*! @} */

/*! @name RET_CONF_TYPE_CONTROL_REG - The define value of H/W configuration */
/*! @{ */

#define VPU_VPU_DEC_RET_CONF_TYPE_CONTROL_REG_HW_TYPE_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_CONF_TYPE_CONTROL_REG_HW_TYPE_SHIFT (0U)
#define VPU_VPU_DEC_RET_CONF_TYPE_CONTROL_REG_HW_TYPE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_CONF_TYPE_CONTROL_REG_HW_TYPE_SHIFT)) & VPU_VPU_DEC_RET_CONF_TYPE_CONTROL_REG_HW_TYPE_MASK)
/*! @} */

/*! @name RET_CONF_TYPE_CONTROL_REG_VM - The define value of H/W configuration */
/*! @{ */

#define VPU_VPU_DEC_RET_CONF_TYPE_CONTROL_REG_VM_HW_TYPE_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_CONF_TYPE_CONTROL_REG_VM_HW_TYPE_SHIFT (0U)
#define VPU_VPU_DEC_RET_CONF_TYPE_CONTROL_REG_VM_HW_TYPE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_CONF_TYPE_CONTROL_REG_VM_HW_TYPE_SHIFT)) & VPU_VPU_DEC_RET_CONF_TYPE_CONTROL_REG_VM_HW_TYPE_MASK)
/*! @} */

/*! @name RET_VCORE0_CFG_CONTROL_REG - Configuration Information of VCORE0 */
/*! @{ */

#define VPU_VPU_DEC_RET_VCORE0_CFG_CONTROL_REG_CONFIG_VORE0_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_VCORE0_CFG_CONTROL_REG_CONFIG_VORE0_SHIFT (0U)
#define VPU_VPU_DEC_RET_VCORE0_CFG_CONTROL_REG_CONFIG_VORE0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_VCORE0_CFG_CONTROL_REG_CONFIG_VORE0_SHIFT)) & VPU_VPU_DEC_RET_VCORE0_CFG_CONTROL_REG_CONFIG_VORE0_MASK)
/*! @} */

/*! @name RET_VCORE0_CFG_CONTROL_REG_VM - Configuration Information of VCORE0 */
/*! @{ */

#define VPU_VPU_DEC_RET_VCORE0_CFG_CONTROL_REG_VM_CONFIG_VORE0_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_VCORE0_CFG_CONTROL_REG_VM_CONFIG_VORE0_SHIFT (0U)
#define VPU_VPU_DEC_RET_VCORE0_CFG_CONTROL_REG_VM_CONFIG_VORE0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_VCORE0_CFG_CONTROL_REG_VM_CONFIG_VORE0_SHIFT)) & VPU_VPU_DEC_RET_VCORE0_CFG_CONTROL_REG_VM_CONFIG_VORE0_MASK)
/*! @} */

/*! @name RET_VCORE1_CFG_CONTROL_REG - Configuration Information of VCORE1 */
/*! @{ */

#define VPU_VPU_DEC_RET_VCORE1_CFG_CONTROL_REG_CONFIG_VORE1_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_VCORE1_CFG_CONTROL_REG_CONFIG_VORE1_SHIFT (0U)
#define VPU_VPU_DEC_RET_VCORE1_CFG_CONTROL_REG_CONFIG_VORE1(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_VCORE1_CFG_CONTROL_REG_CONFIG_VORE1_SHIFT)) & VPU_VPU_DEC_RET_VCORE1_CFG_CONTROL_REG_CONFIG_VORE1_MASK)
/*! @} */

/*! @name RET_VCORE1_CFG_CONTROL_REG_VM - Configuration Information of VCORE1 */
/*! @{ */

#define VPU_VPU_DEC_RET_VCORE1_CFG_CONTROL_REG_VM_CONFIG_VORE1_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_VCORE1_CFG_CONTROL_REG_VM_CONFIG_VORE1_SHIFT (0U)
#define VPU_VPU_DEC_RET_VCORE1_CFG_CONTROL_REG_VM_CONFIG_VORE1(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_VCORE1_CFG_CONTROL_REG_VM_CONFIG_VORE1_SHIFT)) & VPU_VPU_DEC_RET_VCORE1_CFG_CONTROL_REG_VM_CONFIG_VORE1_MASK)
/*! @} */

/*! @name RET_VCORE2_CFG_CONTROL_REG - Configuration Information of VCORE2 */
/*! @{ */

#define VPU_VPU_DEC_RET_VCORE2_CFG_CONTROL_REG_CONFIG_VORE2_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_VCORE2_CFG_CONTROL_REG_CONFIG_VORE2_SHIFT (0U)
#define VPU_VPU_DEC_RET_VCORE2_CFG_CONTROL_REG_CONFIG_VORE2(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_VCORE2_CFG_CONTROL_REG_CONFIG_VORE2_SHIFT)) & VPU_VPU_DEC_RET_VCORE2_CFG_CONTROL_REG_CONFIG_VORE2_MASK)
/*! @} */

/*! @name RET_VCORE2_CFG_CONTROL_REG_VM - Configuration Information of VCORE2 */
/*! @{ */

#define VPU_VPU_DEC_RET_VCORE2_CFG_CONTROL_REG_VM_CONFIG_VORE2_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_VCORE2_CFG_CONTROL_REG_VM_CONFIG_VORE2_SHIFT (0U)
#define VPU_VPU_DEC_RET_VCORE2_CFG_CONTROL_REG_VM_CONFIG_VORE2(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_VCORE2_CFG_CONTROL_REG_VM_CONFIG_VORE2_SHIFT)) & VPU_VPU_DEC_RET_VCORE2_CFG_CONTROL_REG_VM_CONFIG_VORE2_MASK)
/*! @} */

/*! @name VPU_CMD_BUSY_STATUS_V_CONTROL_REG - Command busy status */
/*! @{ */

#define VPU_VPU_DEC_VPU_CMD_BUSY_STATUS_V_CONTROL_REG_VPU_CMD_BUSY_STATUS_MASK (0x1U)
#define VPU_VPU_DEC_VPU_CMD_BUSY_STATUS_V_CONTROL_REG_VPU_CMD_BUSY_STATUS_SHIFT (0U)
#define VPU_VPU_DEC_VPU_CMD_BUSY_STATUS_V_CONTROL_REG_VPU_CMD_BUSY_STATUS(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_CMD_BUSY_STATUS_V_CONTROL_REG_VPU_CMD_BUSY_STATUS_SHIFT)) & VPU_VPU_DEC_VPU_CMD_BUSY_STATUS_V_CONTROL_REG_VPU_CMD_BUSY_STATUS_MASK)

#define VPU_VPU_DEC_VPU_CMD_BUSY_STATUS_V_CONTROL_REG_RSVD0_MASK (0xFFFFFFFEU)
#define VPU_VPU_DEC_VPU_CMD_BUSY_STATUS_V_CONTROL_REG_RSVD0_SHIFT (1U)
#define VPU_VPU_DEC_VPU_CMD_BUSY_STATUS_V_CONTROL_REG_RSVD0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_CMD_BUSY_STATUS_V_CONTROL_REG_RSVD0_SHIFT)) & VPU_VPU_DEC_VPU_CMD_BUSY_STATUS_V_CONTROL_REG_RSVD0_MASK)
/*! @} */

/*! @name VPU_CMD_BUSY_STATUS_V_CONTROL_REG_VM - Command busy status */
/*! @{ */

#define VPU_VPU_DEC_VPU_CMD_BUSY_STATUS_V_CONTROL_REG_VM_VPU_CMD_BUSY_STATUS_MASK (0x1U)
#define VPU_VPU_DEC_VPU_CMD_BUSY_STATUS_V_CONTROL_REG_VM_VPU_CMD_BUSY_STATUS_SHIFT (0U)
#define VPU_VPU_DEC_VPU_CMD_BUSY_STATUS_V_CONTROL_REG_VM_VPU_CMD_BUSY_STATUS(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_CMD_BUSY_STATUS_V_CONTROL_REG_VM_VPU_CMD_BUSY_STATUS_SHIFT)) & VPU_VPU_DEC_VPU_CMD_BUSY_STATUS_V_CONTROL_REG_VM_VPU_CMD_BUSY_STATUS_MASK)

#define VPU_VPU_DEC_VPU_CMD_BUSY_STATUS_V_CONTROL_REG_VM_RSVD0_MASK (0xFFFFFFFEU)
#define VPU_VPU_DEC_VPU_CMD_BUSY_STATUS_V_CONTROL_REG_VM_RSVD0_SHIFT (1U)
#define VPU_VPU_DEC_VPU_CMD_BUSY_STATUS_V_CONTROL_REG_VM_RSVD0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_CMD_BUSY_STATUS_V_CONTROL_REG_VM_RSVD0_SHIFT)) & VPU_VPU_DEC_VPU_CMD_BUSY_STATUS_V_CONTROL_REG_VM_RSVD0_MASK)
/*! @} */

/*! @name VPU_RET_VCORE_PRESET_CONTROL_REG - Number of VCOREs present */
/*! @{ */

#define VPU_VPU_DEC_VPU_RET_VCORE_PRESET_CONTROL_REG_VCORE_PRESENT_MASK (0xFU)
#define VPU_VPU_DEC_VPU_RET_VCORE_PRESET_CONTROL_REG_VCORE_PRESENT_SHIFT (0U)
#define VPU_VPU_DEC_VPU_RET_VCORE_PRESET_CONTROL_REG_VCORE_PRESENT(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_RET_VCORE_PRESET_CONTROL_REG_VCORE_PRESENT_SHIFT)) & VPU_VPU_DEC_VPU_RET_VCORE_PRESET_CONTROL_REG_VCORE_PRESENT_MASK)
/*! @} */

/*! @name VPU_RET_VCORE_PRESET_CONTROL_REG_VM - Number of VCOREs present */
/*! @{ */

#define VPU_VPU_DEC_VPU_RET_VCORE_PRESET_CONTROL_REG_VM_VCORE_PRESENT_MASK (0xFU)
#define VPU_VPU_DEC_VPU_RET_VCORE_PRESET_CONTROL_REG_VM_VCORE_PRESENT_SHIFT (0U)
#define VPU_VPU_DEC_VPU_RET_VCORE_PRESET_CONTROL_REG_VM_VCORE_PRESENT(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_RET_VCORE_PRESET_CONTROL_REG_VM_VCORE_PRESENT_SHIFT)) & VPU_VPU_DEC_VPU_RET_VCORE_PRESET_CONTROL_REG_VM_VCORE_PRESENT_MASK)
/*! @} */

/*! @name VPU_DBG_SW_UART_STATUS_CONTROL_REG - VPU_dbg_sw_uart_status */
/*! @{ */

#define VPU_VPU_DEC_VPU_DBG_SW_UART_STATUS_CONTROL_REG_VPU_DBG_SW_UART_STATUS_MASK (0xFU)
#define VPU_VPU_DEC_VPU_DBG_SW_UART_STATUS_CONTROL_REG_VPU_DBG_SW_UART_STATUS_SHIFT (0U)
#define VPU_VPU_DEC_VPU_DBG_SW_UART_STATUS_CONTROL_REG_VPU_DBG_SW_UART_STATUS(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_DBG_SW_UART_STATUS_CONTROL_REG_VPU_DBG_SW_UART_STATUS_SHIFT)) & VPU_VPU_DEC_VPU_DBG_SW_UART_STATUS_CONTROL_REG_VPU_DBG_SW_UART_STATUS_MASK)
/*! @} */

/*! @name VPU_DBG_SW_UART_STATUS_CONTROL_REG_VM - VPU_dbg_sw_uart_status */
/*! @{ */

#define VPU_VPU_DEC_VPU_DBG_SW_UART_STATUS_CONTROL_REG_VM_VPU_DBG_SW_UART_STATUS_MASK (0xFU)
#define VPU_VPU_DEC_VPU_DBG_SW_UART_STATUS_CONTROL_REG_VM_VPU_DBG_SW_UART_STATUS_SHIFT (0U)
#define VPU_VPU_DEC_VPU_DBG_SW_UART_STATUS_CONTROL_REG_VM_VPU_DBG_SW_UART_STATUS(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_DBG_SW_UART_STATUS_CONTROL_REG_VM_VPU_DBG_SW_UART_STATUS_SHIFT)) & VPU_VPU_DEC_VPU_DBG_SW_UART_STATUS_CONTROL_REG_VM_VPU_DBG_SW_UART_STATUS_MASK)
/*! @} */

/*! @name VPU_DBG_SW_UART_TX_CONTROL_REG - VPU_ dbg_sw_uart_tx */
/*! @{ */

#define VPU_VPU_DEC_VPU_DBG_SW_UART_TX_CONTROL_REG_VPU_DBG_SW_UART_TX_MASK (0xFU)
#define VPU_VPU_DEC_VPU_DBG_SW_UART_TX_CONTROL_REG_VPU_DBG_SW_UART_TX_SHIFT (0U)
#define VPU_VPU_DEC_VPU_DBG_SW_UART_TX_CONTROL_REG_VPU_DBG_SW_UART_TX(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_DBG_SW_UART_TX_CONTROL_REG_VPU_DBG_SW_UART_TX_SHIFT)) & VPU_VPU_DEC_VPU_DBG_SW_UART_TX_CONTROL_REG_VPU_DBG_SW_UART_TX_MASK)
/*! @} */

/*! @name VPU_DBG_SW_UART_TX_CONTROL_REG_VM - VPU_ dbg_sw_uart_tx */
/*! @{ */

#define VPU_VPU_DEC_VPU_DBG_SW_UART_TX_CONTROL_REG_VM_VPU_DBG_SW_UART_TX_MASK (0xFU)
#define VPU_VPU_DEC_VPU_DBG_SW_UART_TX_CONTROL_REG_VM_VPU_DBG_SW_UART_TX_SHIFT (0U)
#define VPU_VPU_DEC_VPU_DBG_SW_UART_TX_CONTROL_REG_VM_VPU_DBG_SW_UART_TX(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_DBG_SW_UART_TX_CONTROL_REG_VM_VPU_DBG_SW_UART_TX_SHIFT)) & VPU_VPU_DEC_VPU_DBG_SW_UART_TX_CONTROL_REG_VM_VPU_DBG_SW_UART_TX_MASK)
/*! @} */

/*! @name VPU_REQUIRE_WORK_BUF_ADDR_CONTROL_REG - Work buffer base address */
/*! @{ */

#define VPU_VPU_DEC_VPU_REQUIRE_WORK_BUF_ADDR_CONTROL_REG_VPU_REQUIRE_WORK_BUF_ADDR_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_VPU_REQUIRE_WORK_BUF_ADDR_CONTROL_REG_VPU_REQUIRE_WORK_BUF_ADDR_SHIFT (0U)
#define VPU_VPU_DEC_VPU_REQUIRE_WORK_BUF_ADDR_CONTROL_REG_VPU_REQUIRE_WORK_BUF_ADDR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_REQUIRE_WORK_BUF_ADDR_CONTROL_REG_VPU_REQUIRE_WORK_BUF_ADDR_SHIFT)) & VPU_VPU_DEC_VPU_REQUIRE_WORK_BUF_ADDR_CONTROL_REG_VPU_REQUIRE_WORK_BUF_ADDR_MASK)
/*! @} */

/*! @name VPU_REQUIRE_WORK_BUF_ADDR_CONTROL_REG_VM - Work buffer base address */
/*! @{ */

#define VPU_VPU_DEC_VPU_REQUIRE_WORK_BUF_ADDR_CONTROL_REG_VM_VPU_REQUIRE_WORK_BUF_ADDR_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_VPU_REQUIRE_WORK_BUF_ADDR_CONTROL_REG_VM_VPU_REQUIRE_WORK_BUF_ADDR_SHIFT (0U)
#define VPU_VPU_DEC_VPU_REQUIRE_WORK_BUF_ADDR_CONTROL_REG_VM_VPU_REQUIRE_WORK_BUF_ADDR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_REQUIRE_WORK_BUF_ADDR_CONTROL_REG_VM_VPU_REQUIRE_WORK_BUF_ADDR_SHIFT)) & VPU_VPU_DEC_VPU_REQUIRE_WORK_BUF_ADDR_CONTROL_REG_VM_VPU_REQUIRE_WORK_BUF_ADDR_MASK)
/*! @} */

/*! @name VPU_REQUIRE_WORK_BUF_SIZE_CONTROL_REG - Work buffer size */
/*! @{ */

#define VPU_VPU_DEC_VPU_REQUIRE_WORK_BUF_SIZE_CONTROL_REG_VPU_REQUIRE_WORK_BUF_SIZE_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_VPU_REQUIRE_WORK_BUF_SIZE_CONTROL_REG_VPU_REQUIRE_WORK_BUF_SIZE_SHIFT (0U)
#define VPU_VPU_DEC_VPU_REQUIRE_WORK_BUF_SIZE_CONTROL_REG_VPU_REQUIRE_WORK_BUF_SIZE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_REQUIRE_WORK_BUF_SIZE_CONTROL_REG_VPU_REQUIRE_WORK_BUF_SIZE_SHIFT)) & VPU_VPU_DEC_VPU_REQUIRE_WORK_BUF_SIZE_CONTROL_REG_VPU_REQUIRE_WORK_BUF_SIZE_MASK)
/*! @} */

/*! @name VPU_REQUIRE_WORK_BUF_SIZE_CONTROL_REG_VM - Work buffer size */
/*! @{ */

#define VPU_VPU_DEC_VPU_REQUIRE_WORK_BUF_SIZE_CONTROL_REG_VM_VPU_REQUIRE_WORK_BUF_SIZE_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_VPU_REQUIRE_WORK_BUF_SIZE_CONTROL_REG_VM_VPU_REQUIRE_WORK_BUF_SIZE_SHIFT (0U)
#define VPU_VPU_DEC_VPU_REQUIRE_WORK_BUF_SIZE_CONTROL_REG_VM_VPU_REQUIRE_WORK_BUF_SIZE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_REQUIRE_WORK_BUF_SIZE_CONTROL_REG_VM_VPU_REQUIRE_WORK_BUF_SIZE_SHIFT)) & VPU_VPU_DEC_VPU_REQUIRE_WORK_BUF_SIZE_CONTROL_REG_VM_VPU_REQUIRE_WORK_BUF_SIZE_MASK)
/*! @} */

/*! @name COMMAND - Command */
/*! @{ */

#define VPU_VPU_DEC_COMMAND_COMMAND_MASK         (0xFFFFFFFFU)
#define VPU_VPU_DEC_COMMAND_COMMAND_SHIFT        (0U)
#define VPU_VPU_DEC_COMMAND_COMMAND(x)           (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_COMMAND_COMMAND_SHIFT)) & VPU_VPU_DEC_COMMAND_COMMAND_MASK)
/*! @} */

/*! @name CMD_DEC_PIC_OPTION - Run command option */
/*! @{ */

#define VPU_VPU_DEC_CMD_DEC_PIC_OPTION_SKIP_MODE_MASK (0x3FU)
#define VPU_VPU_DEC_CMD_DEC_PIC_OPTION_SKIP_MODE_SHIFT (0U)
#define VPU_VPU_DEC_CMD_DEC_PIC_OPTION_SKIP_MODE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_DEC_PIC_OPTION_SKIP_MODE_SHIFT)) & VPU_VPU_DEC_CMD_DEC_PIC_OPTION_SKIP_MODE_MASK)

#define VPU_VPU_DEC_CMD_DEC_PIC_OPTION_force_film_grain_off_MASK (0x40U)
#define VPU_VPU_DEC_CMD_DEC_PIC_OPTION_force_film_grain_off_SHIFT (6U)
#define VPU_VPU_DEC_CMD_DEC_PIC_OPTION_force_film_grain_off(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_DEC_PIC_OPTION_force_film_grain_off_SHIFT)) & VPU_VPU_DEC_CMD_DEC_PIC_OPTION_force_film_grain_off_MASK)
/*! @} */

/*! @name CMD_INIT_SEQ_OPTION - Run command option */
/*! @{ */

#define VPU_VPU_DEC_CMD_INIT_SEQ_OPTION_INIT_SEQ_OPTION_MASK (0x3FU)
#define VPU_VPU_DEC_CMD_INIT_SEQ_OPTION_INIT_SEQ_OPTION_SHIFT (0U)
#define VPU_VPU_DEC_CMD_INIT_SEQ_OPTION_INIT_SEQ_OPTION(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_INIT_SEQ_OPTION_INIT_SEQ_OPTION_SHIFT)) & VPU_VPU_DEC_CMD_INIT_SEQ_OPTION_INIT_SEQ_OPTION_MASK)
/*! @} */

/*! @name CMD_OPTION - Command Option */
/*! @{ */

#define VPU_VPU_DEC_CMD_OPTION_RSVD0_MASK        (0xFFFFFFFFU)
#define VPU_VPU_DEC_CMD_OPTION_RSVD0_SHIFT       (0U)
#define VPU_VPU_DEC_CMD_OPTION_RSVD0(x)          (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_OPTION_RSVD0_SHIFT)) & VPU_VPU_DEC_CMD_OPTION_RSVD0_MASK)
/*! @} */

/*! @name CMD_QUERY_OPTION - QUERY command option */
/*! @{ */

#define VPU_VPU_DEC_CMD_QUERY_OPTION_QUERY_OPTION_MASK (0x3FU)
#define VPU_VPU_DEC_CMD_QUERY_OPTION_QUERY_OPTION_SHIFT (0U)
#define VPU_VPU_DEC_CMD_QUERY_OPTION_QUERY_OPTION(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_QUERY_OPTION_QUERY_OPTION_SHIFT)) & VPU_VPU_DEC_CMD_QUERY_OPTION_QUERY_OPTION_MASK)
/*! @} */

/*! @name CMD_QUERY_OPTION_QUERY_GET_BS_RD_PTR - QUERY command option */
/*! @{ */

#define VPU_VPU_DEC_CMD_QUERY_OPTION_QUERY_GET_BS_RD_PTR_QUERY_OPTION_MASK (0x3FU)
#define VPU_VPU_DEC_CMD_QUERY_OPTION_QUERY_GET_BS_RD_PTR_QUERY_OPTION_SHIFT (0U)
#define VPU_VPU_DEC_CMD_QUERY_OPTION_QUERY_GET_BS_RD_PTR_QUERY_OPTION(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_QUERY_OPTION_QUERY_GET_BS_RD_PTR_QUERY_OPTION_SHIFT)) & VPU_VPU_DEC_CMD_QUERY_OPTION_QUERY_GET_BS_RD_PTR_QUERY_OPTION_MASK)
/*! @} */

/*! @name CMD_QUERY_OPTION_QUERY_GET_BW_RESULT - QUERY command option */
/*! @{ */

#define VPU_VPU_DEC_CMD_QUERY_OPTION_QUERY_GET_BW_RESULT_QUERY_OPTION_MASK (0x3FU)
#define VPU_VPU_DEC_CMD_QUERY_OPTION_QUERY_GET_BW_RESULT_QUERY_OPTION_SHIFT (0U)
#define VPU_VPU_DEC_CMD_QUERY_OPTION_QUERY_GET_BW_RESULT_QUERY_OPTION(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_QUERY_OPTION_QUERY_GET_BW_RESULT_QUERY_OPTION_SHIFT)) & VPU_VPU_DEC_CMD_QUERY_OPTION_QUERY_GET_BW_RESULT_QUERY_OPTION_MASK)
/*! @} */

/*! @name CMD_QUERY_OPTION_QUERY_GET_PF_RESULT - QUERY command option */
/*! @{ */

#define VPU_VPU_DEC_CMD_QUERY_OPTION_QUERY_GET_PF_RESULT_QUERY_OPTION_MASK (0x3FU)
#define VPU_VPU_DEC_CMD_QUERY_OPTION_QUERY_GET_PF_RESULT_QUERY_OPTION_SHIFT (0U)
#define VPU_VPU_DEC_CMD_QUERY_OPTION_QUERY_GET_PF_RESULT_QUERY_OPTION(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_QUERY_OPTION_QUERY_GET_PF_RESULT_QUERY_OPTION_SHIFT)) & VPU_VPU_DEC_CMD_QUERY_OPTION_QUERY_GET_PF_RESULT_QUERY_OPTION_MASK)
/*! @} */

/*! @name CMD_QUERY_OPTION_QUERY_GET_RESULT_DEC - Run command option */
/*! @{ */

#define VPU_VPU_DEC_CMD_QUERY_OPTION_QUERY_GET_RESULT_DEC_QUERY_OPTION_MASK (0x3FU)
#define VPU_VPU_DEC_CMD_QUERY_OPTION_QUERY_GET_RESULT_DEC_QUERY_OPTION_SHIFT (0U)
#define VPU_VPU_DEC_CMD_QUERY_OPTION_QUERY_GET_RESULT_DEC_QUERY_OPTION(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_QUERY_OPTION_QUERY_GET_RESULT_DEC_QUERY_OPTION_SHIFT)) & VPU_VPU_DEC_CMD_QUERY_OPTION_QUERY_GET_RESULT_DEC_QUERY_OPTION_MASK)
/*! @} */

/*! @name CMD_QUERY_OPTION_QUERY_SET_BS_RD_PTR - QUERY command option */
/*! @{ */

#define VPU_VPU_DEC_CMD_QUERY_OPTION_QUERY_SET_BS_RD_PTR_QUERY_OPTION_MASK (0x3FU)
#define VPU_VPU_DEC_CMD_QUERY_OPTION_QUERY_SET_BS_RD_PTR_QUERY_OPTION_SHIFT (0U)
#define VPU_VPU_DEC_CMD_QUERY_OPTION_QUERY_SET_BS_RD_PTR_QUERY_OPTION(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_QUERY_OPTION_QUERY_SET_BS_RD_PTR_QUERY_OPTION_SHIFT)) & VPU_VPU_DEC_CMD_QUERY_OPTION_QUERY_SET_BS_RD_PTR_QUERY_OPTION_MASK)
/*! @} */

/*! @name CMD_QUERY_OPTION_QUERY_UPDATE_DISP_IDC - Run command option */
/*! @{ */

#define VPU_VPU_DEC_CMD_QUERY_OPTION_QUERY_UPDATE_DISP_IDC_QUERY_OPTION_MASK (0x3FU)
#define VPU_VPU_DEC_CMD_QUERY_OPTION_QUERY_UPDATE_DISP_IDC_QUERY_OPTION_SHIFT (0U)
#define VPU_VPU_DEC_CMD_QUERY_OPTION_QUERY_UPDATE_DISP_IDC_QUERY_OPTION(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_QUERY_OPTION_QUERY_UPDATE_DISP_IDC_QUERY_OPTION_SHIFT)) & VPU_VPU_DEC_CMD_QUERY_OPTION_QUERY_UPDATE_DISP_IDC_QUERY_OPTION_MASK)
/*! @} */

/*! @name CMD_SET_FB_OPTION - Run command option */
/*! @{ */

#define VPU_VPU_DEC_CMD_SET_FB_OPTION_SET_FB_MODE_MASK (0x7U)
#define VPU_VPU_DEC_CMD_SET_FB_OPTION_SET_FB_MODE_SHIFT (0U)
#define VPU_VPU_DEC_CMD_SET_FB_OPTION_SET_FB_MODE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_OPTION_SET_FB_MODE_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_OPTION_SET_FB_MODE_MASK)

#define VPU_VPU_DEC_CMD_SET_FB_OPTION_FB_GROUP_INDICATOR_MASK (0x8U)
#define VPU_VPU_DEC_CMD_SET_FB_OPTION_FB_GROUP_INDICATOR_SHIFT (3U)
#define VPU_VPU_DEC_CMD_SET_FB_OPTION_FB_GROUP_INDICATOR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_OPTION_FB_GROUP_INDICATOR_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_OPTION_FB_GROUP_INDICATOR_MASK)

#define VPU_VPU_DEC_CMD_SET_FB_OPTION_SETUP_DONE_MASK (0x10U)
#define VPU_VPU_DEC_CMD_SET_FB_OPTION_SETUP_DONE_SHIFT (4U)
#define VPU_VPU_DEC_CMD_SET_FB_OPTION_SETUP_DONE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_OPTION_SETUP_DONE_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_OPTION_SETUP_DONE_MASK)

#define VPU_VPU_DEC_CMD_SET_FB_OPTION_FB_ENDIAN_MASK (0xF0000U)
#define VPU_VPU_DEC_CMD_SET_FB_OPTION_FB_ENDIAN_SHIFT (16U)
#define VPU_VPU_DEC_CMD_SET_FB_OPTION_FB_ENDIAN(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_OPTION_FB_ENDIAN_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_OPTION_FB_ENDIAN_MASK)

#define VPU_VPU_DEC_CMD_SET_FB_OPTION_RSVD0_MASK (0x3F00000U)
#define VPU_VPU_DEC_CMD_SET_FB_OPTION_RSVD0_SHIFT (20U)
#define VPU_VPU_DEC_CMD_SET_FB_OPTION_RSVD0(x)   (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_OPTION_RSVD0_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_OPTION_RSVD0_MASK)

#define VPU_VPU_DEC_CMD_SET_FB_OPTION_NON_REF_FBC_WRITING_MASK (0x4000000U)
#define VPU_VPU_DEC_CMD_SET_FB_OPTION_NON_REF_FBC_WRITING_SHIFT (26U)
#define VPU_VPU_DEC_CMD_SET_FB_OPTION_NON_REF_FBC_WRITING(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_OPTION_NON_REF_FBC_WRITING_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_OPTION_NON_REF_FBC_WRITING_MASK)
/*! @} */

/*! @name CMD_SET_FB_OPTION_SET_FB_DEC - Run command option */
/*! @{ */

#define VPU_VPU_DEC_CMD_SET_FB_OPTION_SET_FB_DEC_SET_FB_MODE_MASK (0x7U)
#define VPU_VPU_DEC_CMD_SET_FB_OPTION_SET_FB_DEC_SET_FB_MODE_SHIFT (0U)
#define VPU_VPU_DEC_CMD_SET_FB_OPTION_SET_FB_DEC_SET_FB_MODE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_OPTION_SET_FB_DEC_SET_FB_MODE_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_OPTION_SET_FB_DEC_SET_FB_MODE_MASK)

#define VPU_VPU_DEC_CMD_SET_FB_OPTION_SET_FB_DEC_FB_GROUP_INDICATOR_MASK (0x8U)
#define VPU_VPU_DEC_CMD_SET_FB_OPTION_SET_FB_DEC_FB_GROUP_INDICATOR_SHIFT (3U)
#define VPU_VPU_DEC_CMD_SET_FB_OPTION_SET_FB_DEC_FB_GROUP_INDICATOR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_OPTION_SET_FB_DEC_FB_GROUP_INDICATOR_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_OPTION_SET_FB_DEC_FB_GROUP_INDICATOR_MASK)

#define VPU_VPU_DEC_CMD_SET_FB_OPTION_SET_FB_DEC_SETUP_DONE_MASK (0x10U)
#define VPU_VPU_DEC_CMD_SET_FB_OPTION_SET_FB_DEC_SETUP_DONE_SHIFT (4U)
#define VPU_VPU_DEC_CMD_SET_FB_OPTION_SET_FB_DEC_SETUP_DONE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_OPTION_SET_FB_DEC_SETUP_DONE_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_OPTION_SET_FB_DEC_SETUP_DONE_MASK)

#define VPU_VPU_DEC_CMD_SET_FB_OPTION_SET_FB_DEC_FB_ENDIAN_MASK (0xF0000U)
#define VPU_VPU_DEC_CMD_SET_FB_OPTION_SET_FB_DEC_FB_ENDIAN_SHIFT (16U)
#define VPU_VPU_DEC_CMD_SET_FB_OPTION_SET_FB_DEC_FB_ENDIAN(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_OPTION_SET_FB_DEC_FB_ENDIAN_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_OPTION_SET_FB_DEC_FB_ENDIAN_MASK)

#define VPU_VPU_DEC_CMD_SET_FB_OPTION_SET_FB_DEC_RSVD0_MASK (0x3F00000U)
#define VPU_VPU_DEC_CMD_SET_FB_OPTION_SET_FB_DEC_RSVD0_SHIFT (20U)
#define VPU_VPU_DEC_CMD_SET_FB_OPTION_SET_FB_DEC_RSVD0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_OPTION_SET_FB_DEC_RSVD0_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_OPTION_SET_FB_DEC_RSVD0_MASK)

#define VPU_VPU_DEC_CMD_SET_FB_OPTION_SET_FB_DEC_NON_REF_FBC_WRITING_MASK (0x4000000U)
#define VPU_VPU_DEC_CMD_SET_FB_OPTION_SET_FB_DEC_NON_REF_FBC_WRITING_SHIFT (26U)
#define VPU_VPU_DEC_CMD_SET_FB_OPTION_SET_FB_DEC_NON_REF_FBC_WRITING(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_OPTION_SET_FB_DEC_NON_REF_FBC_WRITING_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_OPTION_SET_FB_DEC_NON_REF_FBC_WRITING_MASK)
/*! @} */

/*! @name RET_SUCCESS - Result of the command */
/*! @{ */

#define VPU_VPU_DEC_RET_SUCCESS_RUN_CMD_STATUS_MASK (0x3U)
#define VPU_VPU_DEC_RET_SUCCESS_RUN_CMD_STATUS_SHIFT (0U)
#define VPU_VPU_DEC_RET_SUCCESS_RUN_CMD_STATUS(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_SUCCESS_RUN_CMD_STATUS_SHIFT)) & VPU_VPU_DEC_RET_SUCCESS_RUN_CMD_STATUS_MASK)
/*! @} */

/*! @name RET_FAIL_REASON - Fail reason of the run command */
/*! @{ */

#define VPU_VPU_DEC_RET_FAIL_REASON_FAIL_REASON_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_FAIL_REASON_FAIL_REASON_SHIFT (0U)
#define VPU_VPU_DEC_RET_FAIL_REASON_FAIL_REASON(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_FAIL_REASON_FAIL_REASON_SHIFT)) & VPU_VPU_DEC_RET_FAIL_REASON_FAIL_REASON_MASK)
/*! @} */

/*! @name ADDR_CODE_BASE - Code buffer base address */
/*! @{ */

#define VPU_VPU_DEC_ADDR_CODE_BASE_CODE_BUF_BASE_MASK (0xFFFFF000U)
#define VPU_VPU_DEC_ADDR_CODE_BASE_CODE_BUF_BASE_SHIFT (12U)
#define VPU_VPU_DEC_ADDR_CODE_BASE_CODE_BUF_BASE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_ADDR_CODE_BASE_CODE_BUF_BASE_SHIFT)) & VPU_VPU_DEC_ADDR_CODE_BASE_CODE_BUF_BASE_MASK)
/*! @} */

/*! @name CMD_INSTANCE_INFO - Instance information */
/*! @{ */

#define VPU_VPU_DEC_CMD_INSTANCE_INFO_INST_INDEX_MASK (0xFFFFU)
#define VPU_VPU_DEC_CMD_INSTANCE_INFO_INST_INDEX_SHIFT (0U)
#define VPU_VPU_DEC_CMD_INSTANCE_INFO_INST_INDEX(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_INSTANCE_INFO_INST_INDEX_SHIFT)) & VPU_VPU_DEC_CMD_INSTANCE_INFO_INST_INDEX_MASK)

#define VPU_VPU_DEC_CMD_INSTANCE_INFO_CODEC_STD_MASK (0xFFFF0000U)
#define VPU_VPU_DEC_CMD_INSTANCE_INFO_CODEC_STD_SHIFT (16U)
#define VPU_VPU_DEC_CMD_INSTANCE_INFO_CODEC_STD(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_INSTANCE_INFO_CODEC_STD_SHIFT)) & VPU_VPU_DEC_CMD_INSTANCE_INFO_CODEC_STD_MASK)
/*! @} */

/*! @name CMD_WAKEUP_ADDR_CODE_BASE - Code buffer base address */
/*! @{ */

#define VPU_VPU_DEC_CMD_WAKEUP_ADDR_CODE_BASE_CODE_BUF_BASE_MASK (0xFFFFF000U)
#define VPU_VPU_DEC_CMD_WAKEUP_ADDR_CODE_BASE_CODE_BUF_BASE_SHIFT (12U)
#define VPU_VPU_DEC_CMD_WAKEUP_ADDR_CODE_BASE_CODE_BUF_BASE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_WAKEUP_ADDR_CODE_BASE_CODE_BUF_BASE_SHIFT)) & VPU_VPU_DEC_CMD_WAKEUP_ADDR_CODE_BASE_CODE_BUF_BASE_MASK)
/*! @} */

/*! @name RET_DETAIL_REASON - host command detail fail reason */
/*! @{ */

#define VPU_VPU_DEC_RET_DETAIL_REASON_HOST_CMD_QUE_FAIL_REASON_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_DETAIL_REASON_HOST_CMD_QUE_FAIL_REASON_SHIFT (0U)
#define VPU_VPU_DEC_RET_DETAIL_REASON_HOST_CMD_QUE_FAIL_REASON(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_DETAIL_REASON_HOST_CMD_QUE_FAIL_REASON_SHIFT)) & VPU_VPU_DEC_RET_DETAIL_REASON_HOST_CMD_QUE_FAIL_REASON_MASK)
/*! @} */

/*! @name RET_DETAIL_REASON_DEC_PIC - host command detail fail reason */
/*! @{ */

#define VPU_VPU_DEC_RET_DETAIL_REASON_DEC_PIC_HOST_CMD_QUE_FAIL_REASON_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_DETAIL_REASON_DEC_PIC_HOST_CMD_QUE_FAIL_REASON_SHIFT (0U)
#define VPU_VPU_DEC_RET_DETAIL_REASON_DEC_PIC_HOST_CMD_QUE_FAIL_REASON(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_DETAIL_REASON_DEC_PIC_HOST_CMD_QUE_FAIL_REASON_SHIFT)) & VPU_VPU_DEC_RET_DETAIL_REASON_DEC_PIC_HOST_CMD_QUE_FAIL_REASON_MASK)
/*! @} */

/*! @name CMD_DEC_ADDR_USERDATA_BASE - User Data Buffer Base Address */
/*! @{ */

#define VPU_VPU_DEC_CMD_DEC_ADDR_USERDATA_BASE_USER_DATA_BUF_BASE_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_CMD_DEC_ADDR_USERDATA_BASE_USER_DATA_BUF_BASE_SHIFT (0U)
#define VPU_VPU_DEC_CMD_DEC_ADDR_USERDATA_BASE_USER_DATA_BUF_BASE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_DEC_ADDR_USERDATA_BASE_USER_DATA_BUF_BASE_SHIFT)) & VPU_VPU_DEC_CMD_DEC_ADDR_USERDATA_BASE_USER_DATA_BUF_BASE_MASK)
/*! @} */

/*! @name CMD_WAKEUP_CODE_SIZE - Code buffer size */
/*! @{ */

#define VPU_VPU_DEC_CMD_WAKEUP_CODE_SIZE_CODE_BUF_SIZE_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_CMD_WAKEUP_CODE_SIZE_CODE_BUF_SIZE_SHIFT (0U)
#define VPU_VPU_DEC_CMD_WAKEUP_CODE_SIZE_CODE_BUF_SIZE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_WAKEUP_CODE_SIZE_CODE_BUF_SIZE_SHIFT)) & VPU_VPU_DEC_CMD_WAKEUP_CODE_SIZE_CODE_BUF_SIZE_MASK)
/*! @} */

/*! @name CODE_SIZE - Code buffer size */
/*! @{ */

#define VPU_VPU_DEC_CODE_SIZE_CODE_BUF_SIZE_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_CODE_SIZE_CODE_BUF_SIZE_SHIFT (0U)
#define VPU_VPU_DEC_CODE_SIZE_CODE_BUF_SIZE(x)   (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CODE_SIZE_CODE_BUF_SIZE_SHIFT)) & VPU_VPU_DEC_CODE_SIZE_CODE_BUF_SIZE_MASK)
/*! @} */

/*! @name CMD_BS_RD_PTR - Bistream buffer read pointer */
/*! @{ */

#define VPU_VPU_DEC_CMD_BS_RD_PTR_RD_PTR_MASK    (0xFFFFFFFFU)
#define VPU_VPU_DEC_CMD_BS_RD_PTR_RD_PTR_SHIFT   (0U)
#define VPU_VPU_DEC_CMD_BS_RD_PTR_RD_PTR(x)      (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_BS_RD_PTR_RD_PTR_SHIFT)) & VPU_VPU_DEC_CMD_BS_RD_PTR_RD_PTR_MASK)
/*! @} */

/*! @name CMD_BS_RD_PTR_DEC_PIC - Bistream Buffer Read Pointer */
/*! @{ */

#define VPU_VPU_DEC_CMD_BS_RD_PTR_DEC_PIC_RD_PTR_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_CMD_BS_RD_PTR_DEC_PIC_RD_PTR_SHIFT (0U)
#define VPU_VPU_DEC_CMD_BS_RD_PTR_DEC_PIC_RD_PTR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_BS_RD_PTR_DEC_PIC_RD_PTR_SHIFT)) & VPU_VPU_DEC_CMD_BS_RD_PTR_DEC_PIC_RD_PTR_MASK)
/*! @} */

/*! @name CMD_DEC_USERDATA_SIZE - User Data Buffer Size */
/*! @{ */

#define VPU_VPU_DEC_CMD_DEC_USERDATA_SIZE_USER_DATA_BUF_SIZE_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_CMD_DEC_USERDATA_SIZE_USER_DATA_BUF_SIZE_SHIFT (0U)
#define VPU_VPU_DEC_CMD_DEC_USERDATA_SIZE_USER_DATA_BUF_SIZE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_DEC_USERDATA_SIZE_USER_DATA_BUF_SIZE_SHIFT)) & VPU_VPU_DEC_CMD_DEC_USERDATA_SIZE_USER_DATA_BUF_SIZE_MASK)
/*! @} */

/*! @name CMD_QUERY_DEC_SET_DISP_IDC - CMD_QUERY_DEC_SET_DISP_IDC */
/*! @{ */

#define VPU_VPU_DEC_CMD_QUERY_DEC_SET_DISP_IDC_SET_DISP_IDC_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_CMD_QUERY_DEC_SET_DISP_IDC_SET_DISP_IDC_SHIFT (0U)
#define VPU_VPU_DEC_CMD_QUERY_DEC_SET_DISP_IDC_SET_DISP_IDC(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_QUERY_DEC_SET_DISP_IDC_SET_DISP_IDC_SHIFT)) & VPU_VPU_DEC_CMD_QUERY_DEC_SET_DISP_IDC_SET_DISP_IDC_MASK)
/*! @} */

/*! @name CMD_SET_FB_COMMON_PIC_INFO - DPB Information */
/*! @{ */

#define VPU_VPU_DEC_CMD_SET_FB_COMMON_PIC_INFO_DPB_STRIDE_MASK (0xFFFFU)
#define VPU_VPU_DEC_CMD_SET_FB_COMMON_PIC_INFO_DPB_STRIDE_SHIFT (0U)
#define VPU_VPU_DEC_CMD_SET_FB_COMMON_PIC_INFO_DPB_STRIDE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_COMMON_PIC_INFO_DPB_STRIDE_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_COMMON_PIC_INFO_DPB_STRIDE_MASK)

#define VPU_VPU_DEC_CMD_SET_FB_COMMON_PIC_INFO_CHROMA_OUTPUT_FORMAT_MASK (0x70000U)
#define VPU_VPU_DEC_CMD_SET_FB_COMMON_PIC_INFO_CHROMA_OUTPUT_FORMAT_SHIFT (16U)
#define VPU_VPU_DEC_CMD_SET_FB_COMMON_PIC_INFO_CHROMA_OUTPUT_FORMAT(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_COMMON_PIC_INFO_CHROMA_OUTPUT_FORMAT_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_COMMON_PIC_INFO_CHROMA_OUTPUT_FORMAT_MASK)

#define VPU_VPU_DEC_CMD_SET_FB_COMMON_PIC_INFO_PIXEL_FORMAT_MASK (0x80000U)
#define VPU_VPU_DEC_CMD_SET_FB_COMMON_PIC_INFO_PIXEL_FORMAT_SHIFT (19U)
#define VPU_VPU_DEC_CMD_SET_FB_COMMON_PIC_INFO_PIXEL_FORMAT(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_COMMON_PIC_INFO_PIXEL_FORMAT_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_COMMON_PIC_INFO_PIXEL_FORMAT_MASK)

#define VPU_VPU_DEC_CMD_SET_FB_COMMON_PIC_INFO_PIXEL_OUTPUT_MODE_MASK (0x700000U)
#define VPU_VPU_DEC_CMD_SET_FB_COMMON_PIC_INFO_PIXEL_OUTPUT_MODE_SHIFT (20U)
#define VPU_VPU_DEC_CMD_SET_FB_COMMON_PIC_INFO_PIXEL_OUTPUT_MODE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_COMMON_PIC_INFO_PIXEL_OUTPUT_MODE_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_COMMON_PIC_INFO_PIXEL_OUTPUT_MODE_MASK)

#define VPU_VPU_DEC_CMD_SET_FB_COMMON_PIC_INFO_PIXEL_ORDER_MODE_MASK (0x800000U)
#define VPU_VPU_DEC_CMD_SET_FB_COMMON_PIC_INFO_PIXEL_ORDER_MODE_SHIFT (23U)
#define VPU_VPU_DEC_CMD_SET_FB_COMMON_PIC_INFO_PIXEL_ORDER_MODE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_COMMON_PIC_INFO_PIXEL_ORDER_MODE_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_COMMON_PIC_INFO_PIXEL_ORDER_MODE_MASK)

#define VPU_VPU_DEC_CMD_SET_FB_COMMON_PIC_INFO_RSVD0_MASK (0xF000000U)
#define VPU_VPU_DEC_CMD_SET_FB_COMMON_PIC_INFO_RSVD0_SHIFT (24U)
#define VPU_VPU_DEC_CMD_SET_FB_COMMON_PIC_INFO_RSVD0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_COMMON_PIC_INFO_RSVD0_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_COMMON_PIC_INFO_RSVD0_MASK)

#define VPU_VPU_DEC_CMD_SET_FB_COMMON_PIC_INFO_BWB_ENABLE_MASK (0x10000000U)
#define VPU_VPU_DEC_CMD_SET_FB_COMMON_PIC_INFO_BWB_ENABLE_SHIFT (28U)
#define VPU_VPU_DEC_CMD_SET_FB_COMMON_PIC_INFO_BWB_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_COMMON_PIC_INFO_BWB_ENABLE_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_COMMON_PIC_INFO_BWB_ENABLE_MASK)

#define VPU_VPU_DEC_CMD_SET_FB_COMMON_PIC_INFO_SCL_ENABLE_MASK (0x20000000U)
#define VPU_VPU_DEC_CMD_SET_FB_COMMON_PIC_INFO_SCL_ENABLE_SHIFT (29U)
#define VPU_VPU_DEC_CMD_SET_FB_COMMON_PIC_INFO_SCL_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_COMMON_PIC_INFO_SCL_ENABLE_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_COMMON_PIC_INFO_SCL_ENABLE_MASK)

#define VPU_VPU_DEC_CMD_SET_FB_COMMON_PIC_INFO_AFBC_ENABLE_MASK (0x40000000U)
#define VPU_VPU_DEC_CMD_SET_FB_COMMON_PIC_INFO_AFBC_ENABLE_SHIFT (30U)
#define VPU_VPU_DEC_CMD_SET_FB_COMMON_PIC_INFO_AFBC_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_COMMON_PIC_INFO_AFBC_ENABLE_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_COMMON_PIC_INFO_AFBC_ENABLE_MASK)

#define VPU_VPU_DEC_CMD_SET_FB_COMMON_PIC_INFO_PVRIC_ENABLE_MASK (0x80000000U)
#define VPU_VPU_DEC_CMD_SET_FB_COMMON_PIC_INFO_PVRIC_ENABLE_SHIFT (31U)
#define VPU_VPU_DEC_CMD_SET_FB_COMMON_PIC_INFO_PVRIC_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_COMMON_PIC_INFO_PVRIC_ENABLE_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_COMMON_PIC_INFO_PVRIC_ENABLE_MASK)
/*! @} */

/*! @name CMD_SET_FB_STRIDE - DPB Information */
/*! @{ */

#define VPU_VPU_DEC_CMD_SET_FB_STRIDE_FBC_STRIDE_MASK (0xFFFFU)
#define VPU_VPU_DEC_CMD_SET_FB_STRIDE_FBC_STRIDE_SHIFT (0U)
#define VPU_VPU_DEC_CMD_SET_FB_STRIDE_FBC_STRIDE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_STRIDE_FBC_STRIDE_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_STRIDE_FBC_STRIDE_MASK)

#define VPU_VPU_DEC_CMD_SET_FB_STRIDE_BWB_STRIDE_MASK (0xFFFF0000U)
#define VPU_VPU_DEC_CMD_SET_FB_STRIDE_BWB_STRIDE_SHIFT (16U)
#define VPU_VPU_DEC_CMD_SET_FB_STRIDE_BWB_STRIDE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_STRIDE_BWB_STRIDE_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_STRIDE_BWB_STRIDE_MASK)
/*! @} */

/*! @name CMD_WAKEUP_CODE_PARAM - Code buffer parameter */
/*! @{ */

#define VPU_VPU_DEC_CMD_WAKEUP_CODE_PARAM_CODE_ENDIAN_MASK (0xFU)
#define VPU_VPU_DEC_CMD_WAKEUP_CODE_PARAM_CODE_ENDIAN_SHIFT (0U)
#define VPU_VPU_DEC_CMD_WAKEUP_CODE_PARAM_CODE_ENDIAN(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_WAKEUP_CODE_PARAM_CODE_ENDIAN_SHIFT)) & VPU_VPU_DEC_CMD_WAKEUP_CODE_PARAM_CODE_ENDIAN_MASK)

#define VPU_VPU_DEC_CMD_WAKEUP_CODE_PARAM_CODE_AXIID_MASK (0xF0U)
#define VPU_VPU_DEC_CMD_WAKEUP_CODE_PARAM_CODE_AXIID_SHIFT (4U)
#define VPU_VPU_DEC_CMD_WAKEUP_CODE_PARAM_CODE_AXIID(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_WAKEUP_CODE_PARAM_CODE_AXIID_SHIFT)) & VPU_VPU_DEC_CMD_WAKEUP_CODE_PARAM_CODE_AXIID_MASK)
/*! @} */

/*! @name CODE_PARAM - Code buffer parameters */
/*! @{ */

#define VPU_VPU_DEC_CODE_PARAM_CODE_ENDIAN_MASK  (0xFU)
#define VPU_VPU_DEC_CODE_PARAM_CODE_ENDIAN_SHIFT (0U)
#define VPU_VPU_DEC_CODE_PARAM_CODE_ENDIAN(x)    (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CODE_PARAM_CODE_ENDIAN_SHIFT)) & VPU_VPU_DEC_CODE_PARAM_CODE_ENDIAN_MASK)

#define VPU_VPU_DEC_CODE_PARAM_CODE_AXIID_MASK   (0xF0U)
#define VPU_VPU_DEC_CODE_PARAM_CODE_AXIID_SHIFT  (4U)
#define VPU_VPU_DEC_CODE_PARAM_CODE_AXIID(x)     (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CODE_PARAM_CODE_AXIID_SHIFT)) & VPU_VPU_DEC_CODE_PARAM_CODE_AXIID_MASK)
/*! @} */

/*! @name RET_QUERY_BW_PRP_AXI_READ - PRP AXI read bandwidth */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_BW_PRP_AXI_READ_BW_PRP_AXI_READ_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_QUERY_BW_PRP_AXI_READ_BW_PRP_AXI_READ_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_BW_PRP_AXI_READ_BW_PRP_AXI_READ(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_BW_PRP_AXI_READ_BW_PRP_AXI_READ_SHIFT)) & VPU_VPU_DEC_RET_QUERY_BW_PRP_AXI_READ_BW_PRP_AXI_READ_MASK)
/*! @} */

/*! @name RET_QUERY_FW_VERSION - Firmware Version */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_FW_VERSION_RET_FW_VERSION_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_QUERY_FW_VERSION_RET_FW_VERSION_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_FW_VERSION_RET_FW_VERSION(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_FW_VERSION_RET_FW_VERSION_SHIFT)) & VPU_VPU_DEC_RET_QUERY_FW_VERSION_RET_FW_VERSION_MASK)
/*! @} */

/*! @name RET_QUERY_PF_CMD_IDX - host cmd order idx */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_PF_CMD_IDX_PF_HOST_CMD_IDX_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_QUERY_PF_CMD_IDX_PF_HOST_CMD_IDX_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_PF_CMD_IDX_PF_HOST_CMD_IDX(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_PF_CMD_IDX_PF_HOST_CMD_IDX_SHIFT)) & VPU_VPU_DEC_RET_QUERY_PF_CMD_IDX_PF_HOST_CMD_IDX_MASK)
/*! @} */

/*! @name CMD_BS_WR_PTR - Bistream buffer write pointer */
/*! @{ */

#define VPU_VPU_DEC_CMD_BS_WR_PTR_WR_PTR_MASK    (0xFFFFFFFFU)
#define VPU_VPU_DEC_CMD_BS_WR_PTR_WR_PTR_SHIFT   (0U)
#define VPU_VPU_DEC_CMD_BS_WR_PTR_WR_PTR(x)      (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_BS_WR_PTR_WR_PTR_SHIFT)) & VPU_VPU_DEC_CMD_BS_WR_PTR_WR_PTR_MASK)
/*! @} */

/*! @name CMD_BS_WR_PTR_DEC_PIC - Bistream Buffer Write Pointer */
/*! @{ */

#define VPU_VPU_DEC_CMD_BS_WR_PTR_DEC_PIC_WR_PTR_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_CMD_BS_WR_PTR_DEC_PIC_WR_PTR_SHIFT (0U)
#define VPU_VPU_DEC_CMD_BS_WR_PTR_DEC_PIC_WR_PTR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_BS_WR_PTR_DEC_PIC_WR_PTR_SHIFT)) & VPU_VPU_DEC_CMD_BS_WR_PTR_DEC_PIC_WR_PTR_MASK)
/*! @} */

/*! @name CMD_BS_WR_PTR_UPDATE_BS_DEC - Bitstream buffer write pointer */
/*! @{ */

#define VPU_VPU_DEC_CMD_BS_WR_PTR_UPDATE_BS_DEC_BS_WR_PTR_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_CMD_BS_WR_PTR_UPDATE_BS_DEC_BS_WR_PTR_SHIFT (0U)
#define VPU_VPU_DEC_CMD_BS_WR_PTR_UPDATE_BS_DEC_BS_WR_PTR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_BS_WR_PTR_UPDATE_BS_DEC_BS_WR_PTR_SHIFT)) & VPU_VPU_DEC_CMD_BS_WR_PTR_UPDATE_BS_DEC_BS_WR_PTR_MASK)
/*! @} */

/*! @name CMD_CREATE_INST_BS_START_ADDR - Bitstream buffer start address */
/*! @{ */

#define VPU_VPU_DEC_CMD_CREATE_INST_BS_START_ADDR_BS_START_ADDR_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_CMD_CREATE_INST_BS_START_ADDR_BS_START_ADDR_SHIFT (0U)
#define VPU_VPU_DEC_CMD_CREATE_INST_BS_START_ADDR_BS_START_ADDR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_CREATE_INST_BS_START_ADDR_BS_START_ADDR_SHIFT)) & VPU_VPU_DEC_CMD_CREATE_INST_BS_START_ADDR_BS_START_ADDR_MASK)
/*! @} */

/*! @name CMD_DEC_USERDATA_PARAM - User Data Buffer Parameter */
/*! @{ */

#define VPU_VPU_DEC_CMD_DEC_USERDATA_PARAM_USER_DATA_ENDIAN_MASK (0xFU)
#define VPU_VPU_DEC_CMD_DEC_USERDATA_PARAM_USER_DATA_ENDIAN_SHIFT (0U)
#define VPU_VPU_DEC_CMD_DEC_USERDATA_PARAM_USER_DATA_ENDIAN(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_DEC_USERDATA_PARAM_USER_DATA_ENDIAN_SHIFT)) & VPU_VPU_DEC_CMD_DEC_USERDATA_PARAM_USER_DATA_ENDIAN_MASK)
/*! @} */

/*! @name CMD_QUERY_DEC_CLR_DISP_IDC - CMD_QUERY_DEC_CLR_DISP_IDC */
/*! @{ */

#define VPU_VPU_DEC_CMD_QUERY_DEC_CLR_DISP_IDC_CLR_DISP_IDC_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_CMD_QUERY_DEC_CLR_DISP_IDC_CLR_DISP_IDC_SHIFT (0U)
#define VPU_VPU_DEC_CMD_QUERY_DEC_CLR_DISP_IDC_CLR_DISP_IDC(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_QUERY_DEC_CLR_DISP_IDC_CLR_DISP_IDC_SHIFT)) & VPU_VPU_DEC_CMD_QUERY_DEC_CLR_DISP_IDC_CLR_DISP_IDC_MASK)
/*! @} */

/*! @name CMD_SET_FB_PIC_SIZE - Decoded Picture Size */
/*! @{ */

#define VPU_VPU_DEC_CMD_SET_FB_PIC_SIZE_DPB_HEIGHT_MASK (0xFFFFU)
#define VPU_VPU_DEC_CMD_SET_FB_PIC_SIZE_DPB_HEIGHT_SHIFT (0U)
#define VPU_VPU_DEC_CMD_SET_FB_PIC_SIZE_DPB_HEIGHT(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_PIC_SIZE_DPB_HEIGHT_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_PIC_SIZE_DPB_HEIGHT_MASK)

#define VPU_VPU_DEC_CMD_SET_FB_PIC_SIZE_DPB_WIDTH_MASK (0xFFFF0000U)
#define VPU_VPU_DEC_CMD_SET_FB_PIC_SIZE_DPB_WIDTH_SHIFT (16U)
#define VPU_VPU_DEC_CMD_SET_FB_PIC_SIZE_DPB_WIDTH(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_PIC_SIZE_DPB_WIDTH_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_PIC_SIZE_DPB_WIDTH_MASK)
/*! @} */

/*! @name CMD_SET_FB_PIC_SIZE_SET_FB_DEC - Decoded Picture Size */
/*! @{ */

#define VPU_VPU_DEC_CMD_SET_FB_PIC_SIZE_SET_FB_DEC_DPB_HEIGHT_MASK (0xFFFFU)
#define VPU_VPU_DEC_CMD_SET_FB_PIC_SIZE_SET_FB_DEC_DPB_HEIGHT_SHIFT (0U)
#define VPU_VPU_DEC_CMD_SET_FB_PIC_SIZE_SET_FB_DEC_DPB_HEIGHT(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_PIC_SIZE_SET_FB_DEC_DPB_HEIGHT_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_PIC_SIZE_SET_FB_DEC_DPB_HEIGHT_MASK)

#define VPU_VPU_DEC_CMD_SET_FB_PIC_SIZE_SET_FB_DEC_DPB_WIDTH_MASK (0xFFFF0000U)
#define VPU_VPU_DEC_CMD_SET_FB_PIC_SIZE_SET_FB_DEC_DPB_WIDTH_SHIFT (16U)
#define VPU_VPU_DEC_CMD_SET_FB_PIC_SIZE_SET_FB_DEC_DPB_WIDTH(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_PIC_SIZE_SET_FB_DEC_DPB_WIDTH_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_PIC_SIZE_SET_FB_DEC_DPB_WIDTH_MASK)
/*! @} */

/*! @name CMD_VLC_BASE - Update VLC buffer base address */
/*! @{ */

#define VPU_VPU_DEC_CMD_VLC_BASE_UPDATE_VLC_BASE_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_CMD_VLC_BASE_UPDATE_VLC_BASE_SHIFT (0U)
#define VPU_VPU_DEC_CMD_VLC_BASE_UPDATE_VLC_BASE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_VLC_BASE_UPDATE_VLC_BASE_SHIFT)) & VPU_VPU_DEC_CMD_VLC_BASE_UPDATE_VLC_BASE_MASK)
/*! @} */

/*! @name CMD_WAKEUP_ADDR_TEMP_BASE - Temporal buffer base address */
/*! @{ */

#define VPU_VPU_DEC_CMD_WAKEUP_ADDR_TEMP_BASE_TEMP_BUF_BASE_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_CMD_WAKEUP_ADDR_TEMP_BASE_TEMP_BUF_BASE_SHIFT (0U)
#define VPU_VPU_DEC_CMD_WAKEUP_ADDR_TEMP_BASE_TEMP_BUF_BASE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_WAKEUP_ADDR_TEMP_BASE_TEMP_BUF_BASE_SHIFT)) & VPU_VPU_DEC_CMD_WAKEUP_ADDR_TEMP_BASE_TEMP_BUF_BASE_MASK)
/*! @} */

/*! @name RET_QUERY_BW_PRP_AXI_WRITE - PRP AXI write bandwidth */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_BW_PRP_AXI_WRITE_BW_PRP_AXI_WRITE_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_QUERY_BW_PRP_AXI_WRITE_BW_PRP_AXI_WRITE_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_BW_PRP_AXI_WRITE_BW_PRP_AXI_WRITE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_BW_PRP_AXI_WRITE_BW_PRP_AXI_WRITE_SHIFT)) & VPU_VPU_DEC_RET_QUERY_BW_PRP_AXI_WRITE_BW_PRP_AXI_WRITE_MASK)
/*! @} */

/*! @name RET_QUERY_DEC_BS_RD_PTR - Bitstream buffer read pointer */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_DEC_BS_RD_PTR_BS_RD_PTR_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_QUERY_DEC_BS_RD_PTR_BS_RD_PTR_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_DEC_BS_RD_PTR_BS_RD_PTR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_BS_RD_PTR_BS_RD_PTR_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_BS_RD_PTR_BS_RD_PTR_MASK)
/*! @} */

/*! @name RET_QUERY_ENC_BS_RD_PTR - The start position of bitstream buffer */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_ENC_BS_RD_PTR_QUERY_DEC_BS_RD_PTR_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_QUERY_ENC_BS_RD_PTR_QUERY_DEC_BS_RD_PTR_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_ENC_BS_RD_PTR_QUERY_DEC_BS_RD_PTR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_ENC_BS_RD_PTR_QUERY_DEC_BS_RD_PTR_SHIFT)) & VPU_VPU_DEC_RET_QUERY_ENC_BS_RD_PTR_QUERY_DEC_BS_RD_PTR_MASK)
/*! @} */

/*! @name RET_QUERY_PF_HOST_CMD_TICK - Tick of host cmd */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_PF_HOST_CMD_TICK_PF_HOST_CMD_TICK_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_QUERY_PF_HOST_CMD_TICK_PF_HOST_CMD_TICK_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_PF_HOST_CMD_TICK_PF_HOST_CMD_TICK(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_PF_HOST_CMD_TICK_PF_HOST_CMD_TICK_SHIFT)) & VPU_VPU_DEC_RET_QUERY_PF_HOST_CMD_TICK_PF_HOST_CMD_TICK_MASK)
/*! @} */

/*! @name RET_QUERY_PRODUCT_NAME - HW product name */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_PRODUCT_NAME_HW_NAME_MASK (0xFU)
#define VPU_VPU_DEC_RET_QUERY_PRODUCT_NAME_HW_NAME_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_PRODUCT_NAME_HW_NAME(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_PRODUCT_NAME_HW_NAME_SHIFT)) & VPU_VPU_DEC_RET_QUERY_PRODUCT_NAME_HW_NAME_MASK)
/*! @} */

/*! @name SET_QUERY_BS_RD_PTR - The start position of bitstream buffer */
/*! @{ */

#define VPU_VPU_DEC_SET_QUERY_BS_RD_PTR_QUERY_SET_BS_RD_PTR_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_SET_QUERY_BS_RD_PTR_QUERY_SET_BS_RD_PTR_SHIFT (0U)
#define VPU_VPU_DEC_SET_QUERY_BS_RD_PTR_QUERY_SET_BS_RD_PTR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_SET_QUERY_BS_RD_PTR_QUERY_SET_BS_RD_PTR_SHIFT)) & VPU_VPU_DEC_SET_QUERY_BS_RD_PTR_QUERY_SET_BS_RD_PTR_MASK)
/*! @} */

/*! @name CMD_BS_OPTIONS - Bistream buffer option */
/*! @{ */

#define VPU_VPU_DEC_CMD_BS_OPTIONS_EXPLICIT_END_MASK (0x1U)
#define VPU_VPU_DEC_CMD_BS_OPTIONS_EXPLICIT_END_SHIFT (0U)
#define VPU_VPU_DEC_CMD_BS_OPTIONS_EXPLICIT_END(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_BS_OPTIONS_EXPLICIT_END_SHIFT)) & VPU_VPU_DEC_CMD_BS_OPTIONS_EXPLICIT_END_MASK)

#define VPU_VPU_DEC_CMD_BS_OPTIONS_STREAM_END_MASK (0x2U)
#define VPU_VPU_DEC_CMD_BS_OPTIONS_STREAM_END_SHIFT (1U)
#define VPU_VPU_DEC_CMD_BS_OPTIONS_STREAM_END(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_BS_OPTIONS_STREAM_END_SHIFT)) & VPU_VPU_DEC_CMD_BS_OPTIONS_STREAM_END_MASK)

#define VPU_VPU_DEC_CMD_BS_OPTIONS_STREAM_FORMAT_MASK (0xCU)
#define VPU_VPU_DEC_CMD_BS_OPTIONS_STREAM_FORMAT_SHIFT (2U)
#define VPU_VPU_DEC_CMD_BS_OPTIONS_STREAM_FORMAT(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_BS_OPTIONS_STREAM_FORMAT_SHIFT)) & VPU_VPU_DEC_CMD_BS_OPTIONS_STREAM_FORMAT_MASK)

#define VPU_VPU_DEC_CMD_BS_OPTIONS_RSVD0_MASK    (0xFFFFFFF0U)
#define VPU_VPU_DEC_CMD_BS_OPTIONS_RSVD0_SHIFT   (4U)
#define VPU_VPU_DEC_CMD_BS_OPTIONS_RSVD0(x)      (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_BS_OPTIONS_RSVD0_SHIFT)) & VPU_VPU_DEC_CMD_BS_OPTIONS_RSVD0_MASK)
/*! @} */

/*! @name CMD_BS_OPTIONS_DEC_PIC - Bistream buffer option */
/*! @{ */

#define VPU_VPU_DEC_CMD_BS_OPTIONS_DEC_PIC_EXPLICIT_END_MASK (0x1U)
#define VPU_VPU_DEC_CMD_BS_OPTIONS_DEC_PIC_EXPLICIT_END_SHIFT (0U)
#define VPU_VPU_DEC_CMD_BS_OPTIONS_DEC_PIC_EXPLICIT_END(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_BS_OPTIONS_DEC_PIC_EXPLICIT_END_SHIFT)) & VPU_VPU_DEC_CMD_BS_OPTIONS_DEC_PIC_EXPLICIT_END_MASK)

#define VPU_VPU_DEC_CMD_BS_OPTIONS_DEC_PIC_STREAM_END_MASK (0x2U)
#define VPU_VPU_DEC_CMD_BS_OPTIONS_DEC_PIC_STREAM_END_SHIFT (1U)
#define VPU_VPU_DEC_CMD_BS_OPTIONS_DEC_PIC_STREAM_END(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_BS_OPTIONS_DEC_PIC_STREAM_END_SHIFT)) & VPU_VPU_DEC_CMD_BS_OPTIONS_DEC_PIC_STREAM_END_MASK)

#define VPU_VPU_DEC_CMD_BS_OPTIONS_DEC_PIC_STREAM_FMT_MASK (0xCU)
#define VPU_VPU_DEC_CMD_BS_OPTIONS_DEC_PIC_STREAM_FMT_SHIFT (2U)
#define VPU_VPU_DEC_CMD_BS_OPTIONS_DEC_PIC_STREAM_FMT(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_BS_OPTIONS_DEC_PIC_STREAM_FMT_SHIFT)) & VPU_VPU_DEC_CMD_BS_OPTIONS_DEC_PIC_STREAM_FMT_MASK)

#define VPU_VPU_DEC_CMD_BS_OPTIONS_DEC_PIC_RSVD0_MASK (0x7FFFFFF0U)
#define VPU_VPU_DEC_CMD_BS_OPTIONS_DEC_PIC_RSVD0_SHIFT (4U)
#define VPU_VPU_DEC_CMD_BS_OPTIONS_DEC_PIC_RSVD0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_BS_OPTIONS_DEC_PIC_RSVD0_SHIFT)) & VPU_VPU_DEC_CMD_BS_OPTIONS_DEC_PIC_RSVD0_MASK)

#define VPU_VPU_DEC_CMD_BS_OPTIONS_DEC_PIC_RD_PTR_VALID_FLAG_MASK (0x80000000U)
#define VPU_VPU_DEC_CMD_BS_OPTIONS_DEC_PIC_RD_PTR_VALID_FLAG_SHIFT (31U)
#define VPU_VPU_DEC_CMD_BS_OPTIONS_DEC_PIC_RD_PTR_VALID_FLAG(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_BS_OPTIONS_DEC_PIC_RD_PTR_VALID_FLAG_SHIFT)) & VPU_VPU_DEC_CMD_BS_OPTIONS_DEC_PIC_RD_PTR_VALID_FLAG_MASK)
/*! @} */

/*! @name CMD_BS_OPTIONS_UPDATE_BS_DEC - Bistream buffer option */
/*! @{ */

#define VPU_VPU_DEC_CMD_BS_OPTIONS_UPDATE_BS_DEC_EXPLICIT_END_MASK (0x1U)
#define VPU_VPU_DEC_CMD_BS_OPTIONS_UPDATE_BS_DEC_EXPLICIT_END_SHIFT (0U)
#define VPU_VPU_DEC_CMD_BS_OPTIONS_UPDATE_BS_DEC_EXPLICIT_END(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_BS_OPTIONS_UPDATE_BS_DEC_EXPLICIT_END_SHIFT)) & VPU_VPU_DEC_CMD_BS_OPTIONS_UPDATE_BS_DEC_EXPLICIT_END_MASK)

#define VPU_VPU_DEC_CMD_BS_OPTIONS_UPDATE_BS_DEC_END_OF_STREAM_MASK (0x2U)
#define VPU_VPU_DEC_CMD_BS_OPTIONS_UPDATE_BS_DEC_END_OF_STREAM_SHIFT (1U)
#define VPU_VPU_DEC_CMD_BS_OPTIONS_UPDATE_BS_DEC_END_OF_STREAM(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_BS_OPTIONS_UPDATE_BS_DEC_END_OF_STREAM_SHIFT)) & VPU_VPU_DEC_CMD_BS_OPTIONS_UPDATE_BS_DEC_END_OF_STREAM_MASK)
/*! @} */

/*! @name CMD_CREATE_INST_BS_SIZE - Bitstream buffer size */
/*! @{ */

#define VPU_VPU_DEC_CMD_CREATE_INST_BS_SIZE_BS_BUF_SIZE_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_CMD_CREATE_INST_BS_SIZE_BS_BUF_SIZE_SHIFT (0U)
#define VPU_VPU_DEC_CMD_CREATE_INST_BS_SIZE_BS_BUF_SIZE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_CREATE_INST_BS_SIZE_BS_BUF_SIZE_SHIFT)) & VPU_VPU_DEC_CMD_CREATE_INST_BS_SIZE_BS_BUF_SIZE_MASK)
/*! @} */

/*! @name CMD_SET_FB_INDICE - DPB index to be updated */
/*! @{ */

#define VPU_VPU_DEC_CMD_SET_FB_INDICE_FBC_IDX_MASK (0xFFU)
#define VPU_VPU_DEC_CMD_SET_FB_INDICE_FBC_IDX_SHIFT (0U)
#define VPU_VPU_DEC_CMD_SET_FB_INDICE_FBC_IDX(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_INDICE_FBC_IDX_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_INDICE_FBC_IDX_MASK)

#define VPU_VPU_DEC_CMD_SET_FB_INDICE_BWB_IDX_MASK (0xFF00U)
#define VPU_VPU_DEC_CMD_SET_FB_INDICE_BWB_IDX_SHIFT (8U)
#define VPU_VPU_DEC_CMD_SET_FB_INDICE_BWB_IDX(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_INDICE_BWB_IDX_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_INDICE_BWB_IDX_MASK)

#define VPU_VPU_DEC_CMD_SET_FB_INDICE_MVCOL_IDX_MASK (0xFF0000U)
#define VPU_VPU_DEC_CMD_SET_FB_INDICE_MVCOL_IDX_SHIFT (16U)
#define VPU_VPU_DEC_CMD_SET_FB_INDICE_MVCOL_IDX(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_INDICE_MVCOL_IDX_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_INDICE_MVCOL_IDX_MASK)
/*! @} */

/*! @name CMD_SET_FB_NUM - Set frame Number */
/*! @{ */

#define VPU_VPU_DEC_CMD_SET_FB_NUM_FB_NUM_END_MASK (0x1FU)
#define VPU_VPU_DEC_CMD_SET_FB_NUM_FB_NUM_END_SHIFT (0U)
#define VPU_VPU_DEC_CMD_SET_FB_NUM_FB_NUM_END(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_NUM_FB_NUM_END_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_NUM_FB_NUM_END_MASK)

#define VPU_VPU_DEC_CMD_SET_FB_NUM_FB_NUM_START_MASK (0x1F00U)
#define VPU_VPU_DEC_CMD_SET_FB_NUM_FB_NUM_START_SHIFT (8U)
#define VPU_VPU_DEC_CMD_SET_FB_NUM_FB_NUM_START(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_NUM_FB_NUM_START_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_NUM_FB_NUM_START_MASK)
/*! @} */

/*! @name CMD_VLC_SIZE - Update VLC buffer size */
/*! @{ */

#define VPU_VPU_DEC_CMD_VLC_SIZE_UPDATE_VLC_SIZE_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_CMD_VLC_SIZE_UPDATE_VLC_SIZE_SHIFT (0U)
#define VPU_VPU_DEC_CMD_VLC_SIZE_UPDATE_VLC_SIZE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_VLC_SIZE_UPDATE_VLC_SIZE_SHIFT)) & VPU_VPU_DEC_CMD_VLC_SIZE_UPDATE_VLC_SIZE_MASK)
/*! @} */

/*! @name CMD_WAKEUP_TEMP_SIZE - Temporal buffer size */
/*! @{ */

#define VPU_VPU_DEC_CMD_WAKEUP_TEMP_SIZE_TEMP_BUF_SIZE_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_CMD_WAKEUP_TEMP_SIZE_TEMP_BUF_SIZE_SHIFT (0U)
#define VPU_VPU_DEC_CMD_WAKEUP_TEMP_SIZE_TEMP_BUF_SIZE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_WAKEUP_TEMP_SIZE_TEMP_BUF_SIZE_SHIFT)) & VPU_VPU_DEC_CMD_WAKEUP_TEMP_SIZE_TEMP_BUF_SIZE_MASK)
/*! @} */

/*! @name RET_QUERY_BW_FBD_Y_AXI_READ - FBD AXI read luma bandwidth */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_BW_FBD_Y_AXI_READ_BW_FBD_Y_AXI_READ_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_QUERY_BW_FBD_Y_AXI_READ_BW_FBD_Y_AXI_READ_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_BW_FBD_Y_AXI_READ_BW_FBD_Y_AXI_READ(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_BW_FBD_Y_AXI_READ_BW_FBD_Y_AXI_READ_SHIFT)) & VPU_VPU_DEC_RET_QUERY_BW_FBD_Y_AXI_READ_BW_FBD_Y_AXI_READ_MASK)
/*! @} */

/*! @name RET_QUERY_DEC_SEQ_PARAM - Bitstream sequence parameter information */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_DEC_SEQ_PARAM_LEVEL_IDC_MASK (0xFFU)
#define VPU_VPU_DEC_RET_QUERY_DEC_SEQ_PARAM_LEVEL_IDC_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_DEC_SEQ_PARAM_LEVEL_IDC(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_SEQ_PARAM_LEVEL_IDC_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_SEQ_PARAM_LEVEL_IDC_MASK)

#define VPU_VPU_DEC_RET_QUERY_DEC_SEQ_PARAM_FRAME_ONLY_CONSTRAINT_FLAG_MASK (0x100U)
#define VPU_VPU_DEC_RET_QUERY_DEC_SEQ_PARAM_FRAME_ONLY_CONSTRAINT_FLAG_SHIFT (8U)
#define VPU_VPU_DEC_RET_QUERY_DEC_SEQ_PARAM_FRAME_ONLY_CONSTRAINT_FLAG(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_SEQ_PARAM_FRAME_ONLY_CONSTRAINT_FLAG_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_SEQ_PARAM_FRAME_ONLY_CONSTRAINT_FLAG_MASK)

#define VPU_VPU_DEC_RET_QUERY_DEC_SEQ_PARAM_NON_PACKED_CONSTRAINT_FLAG_MASK (0x200U)
#define VPU_VPU_DEC_RET_QUERY_DEC_SEQ_PARAM_NON_PACKED_CONSTRAINT_FLAG_SHIFT (9U)
#define VPU_VPU_DEC_RET_QUERY_DEC_SEQ_PARAM_NON_PACKED_CONSTRAINT_FLAG(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_SEQ_PARAM_NON_PACKED_CONSTRAINT_FLAG_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_SEQ_PARAM_NON_PACKED_CONSTRAINT_FLAG_MASK)

#define VPU_VPU_DEC_RET_QUERY_DEC_SEQ_PARAM_INTERLACE_SOURCE_FLAG_MASK (0x400U)
#define VPU_VPU_DEC_RET_QUERY_DEC_SEQ_PARAM_INTERLACE_SOURCE_FLAG_SHIFT (10U)
#define VPU_VPU_DEC_RET_QUERY_DEC_SEQ_PARAM_INTERLACE_SOURCE_FLAG(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_SEQ_PARAM_INTERLACE_SOURCE_FLAG_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_SEQ_PARAM_INTERLACE_SOURCE_FLAG_MASK)

#define VPU_VPU_DEC_RET_QUERY_DEC_SEQ_PARAM_PROGRESS_SOURCE_FLAG_MASK (0x800U)
#define VPU_VPU_DEC_RET_QUERY_DEC_SEQ_PARAM_PROGRESS_SOURCE_FLAG_SHIFT (11U)
#define VPU_VPU_DEC_RET_QUERY_DEC_SEQ_PARAM_PROGRESS_SOURCE_FLAG(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_SEQ_PARAM_PROGRESS_SOURCE_FLAG_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_SEQ_PARAM_PROGRESS_SOURCE_FLAG_MASK)

#define VPU_VPU_DEC_RET_QUERY_DEC_SEQ_PARAM_PROFILE_COMPATIBILITY_FLAG_MASK (0xFF000U)
#define VPU_VPU_DEC_RET_QUERY_DEC_SEQ_PARAM_PROFILE_COMPATIBILITY_FLAG_SHIFT (12U)
#define VPU_VPU_DEC_RET_QUERY_DEC_SEQ_PARAM_PROFILE_COMPATIBILITY_FLAG(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_SEQ_PARAM_PROFILE_COMPATIBILITY_FLAG_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_SEQ_PARAM_PROFILE_COMPATIBILITY_FLAG_MASK)

#define VPU_VPU_DEC_RET_QUERY_DEC_SEQ_PARAM_RSVD0_MASK (0x100000U)
#define VPU_VPU_DEC_RET_QUERY_DEC_SEQ_PARAM_RSVD0_SHIFT (20U)
#define VPU_VPU_DEC_RET_QUERY_DEC_SEQ_PARAM_RSVD0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_SEQ_PARAM_RSVD0_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_SEQ_PARAM_RSVD0_MASK)

#define VPU_VPU_DEC_RET_QUERY_DEC_SEQ_PARAM_SPS_MAX_SUB_LAYER_MASK (0xE00000U)
#define VPU_VPU_DEC_RET_QUERY_DEC_SEQ_PARAM_SPS_MAX_SUB_LAYER_SHIFT (21U)
#define VPU_VPU_DEC_RET_QUERY_DEC_SEQ_PARAM_SPS_MAX_SUB_LAYER(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_SEQ_PARAM_SPS_MAX_SUB_LAYER_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_SEQ_PARAM_SPS_MAX_SUB_LAYER_MASK)

#define VPU_VPU_DEC_RET_QUERY_DEC_SEQ_PARAM_PROFILE_IDC_MASK (0x1F000000U)
#define VPU_VPU_DEC_RET_QUERY_DEC_SEQ_PARAM_PROFILE_IDC_SHIFT (24U)
#define VPU_VPU_DEC_RET_QUERY_DEC_SEQ_PARAM_PROFILE_IDC(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_SEQ_PARAM_PROFILE_IDC_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_SEQ_PARAM_PROFILE_IDC_MASK)

#define VPU_VPU_DEC_RET_QUERY_DEC_SEQ_PARAM_PROFILE_TIER_FLAG_MASK (0x20000000U)
#define VPU_VPU_DEC_RET_QUERY_DEC_SEQ_PARAM_PROFILE_TIER_FLAG_SHIFT (29U)
#define VPU_VPU_DEC_RET_QUERY_DEC_SEQ_PARAM_PROFILE_TIER_FLAG(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_SEQ_PARAM_PROFILE_TIER_FLAG_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_SEQ_PARAM_PROFILE_TIER_FLAG_MASK)

#define VPU_VPU_DEC_RET_QUERY_DEC_SEQ_PARAM_PROFILE_SPACE_MASK (0xC0000000U)
#define VPU_VPU_DEC_RET_QUERY_DEC_SEQ_PARAM_PROFILE_SPACE_SHIFT (30U)
#define VPU_VPU_DEC_RET_QUERY_DEC_SEQ_PARAM_PROFILE_SPACE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_SEQ_PARAM_PROFILE_SPACE_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_SEQ_PARAM_PROFILE_SPACE_MASK)
/*! @} */

/*! @name RET_QUERY_PF_STG_0_START - Start tick of stage 0 */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_PF_STG_0_START_PF_STAGE_0_START_TICK_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_QUERY_PF_STG_0_START_PF_STAGE_0_START_TICK_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_PF_STG_0_START_PF_STAGE_0_START_TICK(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_PF_STG_0_START_PF_STAGE_0_START_TICK_SHIFT)) & VPU_VPU_DEC_RET_QUERY_PF_STG_0_START_PF_STAGE_0_START_TICK_MASK)
/*! @} */

/*! @name RET_QUERY_PRODUCT_VERSION - HW product version */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_PRODUCT_VERSION_HW_VERSION_MASK (0xFU)
#define VPU_VPU_DEC_RET_QUERY_PRODUCT_VERSION_HW_VERSION_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_PRODUCT_VERSION_HW_VERSION(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_PRODUCT_VERSION_HW_VERSION_SHIFT)) & VPU_VPU_DEC_RET_QUERY_PRODUCT_VERSION_HW_VERSION_MASK)
/*! @} */

/*! @name CMD_CREATE_INST_BS_PARAM - Bitstream buffer parameter */
/*! @{ */

#define VPU_VPU_DEC_CMD_CREATE_INST_BS_PARAM_BS_ENDIAN_MASK (0xFU)
#define VPU_VPU_DEC_CMD_CREATE_INST_BS_PARAM_BS_ENDIAN_SHIFT (0U)
#define VPU_VPU_DEC_CMD_CREATE_INST_BS_PARAM_BS_ENDIAN(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_CREATE_INST_BS_PARAM_BS_ENDIAN_SHIFT)) & VPU_VPU_DEC_CMD_CREATE_INST_BS_PARAM_BS_ENDIAN_MASK)
/*! @} */

/*! @name CMD_INIT_ADDR_SEC_AXI - Secondary AXI base address */
/*! @{ */

#define VPU_VPU_DEC_CMD_INIT_ADDR_SEC_AXI_SEC_AXI_BASE_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_CMD_INIT_ADDR_SEC_AXI_SEC_AXI_BASE_SHIFT (0U)
#define VPU_VPU_DEC_CMD_INIT_ADDR_SEC_AXI_SEC_AXI_BASE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_INIT_ADDR_SEC_AXI_SEC_AXI_BASE_SHIFT)) & VPU_VPU_DEC_CMD_INIT_ADDR_SEC_AXI_SEC_AXI_BASE_MASK)
/*! @} */

/*! @name CMD_WAKEUP_ADDR_SEC_AXI - Secondary AXI base address */
/*! @{ */

#define VPU_VPU_DEC_CMD_WAKEUP_ADDR_SEC_AXI_SEC_AXI_BASE_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_CMD_WAKEUP_ADDR_SEC_AXI_SEC_AXI_BASE_SHIFT (0U)
#define VPU_VPU_DEC_CMD_WAKEUP_ADDR_SEC_AXI_SEC_AXI_BASE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_WAKEUP_ADDR_SEC_AXI_SEC_AXI_BASE_SHIFT)) & VPU_VPU_DEC_CMD_WAKEUP_ADDR_SEC_AXI_SEC_AXI_BASE_MASK)
/*! @} */

/*! @name RET_QUERY_BW_FBC_Y_AXI_WRITE - FBC AXI write luma bandwidth */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_BW_FBC_Y_AXI_WRITE_BW_FBC_Y_AXI_WRITE_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_QUERY_BW_FBC_Y_AXI_WRITE_BW_FBC_Y_AXI_WRITE_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_BW_FBC_Y_AXI_WRITE_BW_FBC_Y_AXI_WRITE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_BW_FBC_Y_AXI_WRITE_BW_FBC_Y_AXI_WRITE_SHIFT)) & VPU_VPU_DEC_RET_QUERY_BW_FBC_Y_AXI_WRITE_BW_FBC_Y_AXI_WRITE_MASK)
/*! @} */

/*! @name RET_QUERY_DEC_COLOR_SAMPLE_INFO - Color Sample Information */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_DEC_COLOR_SAMPLE_INFO_BIT_DEPTH_LUMA_MASK (0xFU)
#define VPU_VPU_DEC_RET_QUERY_DEC_COLOR_SAMPLE_INFO_BIT_DEPTH_LUMA_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_DEC_COLOR_SAMPLE_INFO_BIT_DEPTH_LUMA(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_COLOR_SAMPLE_INFO_BIT_DEPTH_LUMA_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_COLOR_SAMPLE_INFO_BIT_DEPTH_LUMA_MASK)

#define VPU_VPU_DEC_RET_QUERY_DEC_COLOR_SAMPLE_INFO_BIT_DEPTH_CHROMA_MASK (0xF0U)
#define VPU_VPU_DEC_RET_QUERY_DEC_COLOR_SAMPLE_INFO_BIT_DEPTH_CHROMA_SHIFT (4U)
#define VPU_VPU_DEC_RET_QUERY_DEC_COLOR_SAMPLE_INFO_BIT_DEPTH_CHROMA(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_COLOR_SAMPLE_INFO_BIT_DEPTH_CHROMA_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_COLOR_SAMPLE_INFO_BIT_DEPTH_CHROMA_MASK)

#define VPU_VPU_DEC_RET_QUERY_DEC_COLOR_SAMPLE_INFO_COLOR_FORMAT_IDC_MASK (0xF00U)
#define VPU_VPU_DEC_RET_QUERY_DEC_COLOR_SAMPLE_INFO_COLOR_FORMAT_IDC_SHIFT (8U)
#define VPU_VPU_DEC_RET_QUERY_DEC_COLOR_SAMPLE_INFO_COLOR_FORMAT_IDC(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_COLOR_SAMPLE_INFO_COLOR_FORMAT_IDC_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_COLOR_SAMPLE_INFO_COLOR_FORMAT_IDC_MASK)

#define VPU_VPU_DEC_RET_QUERY_DEC_COLOR_SAMPLE_INFO_LF_PIC_DBK_DISABLE_MASK (0x1000U)
#define VPU_VPU_DEC_RET_QUERY_DEC_COLOR_SAMPLE_INFO_LF_PIC_DBK_DISABLE_SHIFT (12U)
#define VPU_VPU_DEC_RET_QUERY_DEC_COLOR_SAMPLE_INFO_LF_PIC_DBK_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_COLOR_SAMPLE_INFO_LF_PIC_DBK_DISABLE_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_COLOR_SAMPLE_INFO_LF_PIC_DBK_DISABLE_MASK)

#define VPU_VPU_DEC_RET_QUERY_DEC_COLOR_SAMPLE_INFO_ASPECT_RATIO_IDC_MASK (0xFF0000U)
#define VPU_VPU_DEC_RET_QUERY_DEC_COLOR_SAMPLE_INFO_ASPECT_RATIO_IDC_SHIFT (16U)
#define VPU_VPU_DEC_RET_QUERY_DEC_COLOR_SAMPLE_INFO_ASPECT_RATIO_IDC(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_COLOR_SAMPLE_INFO_ASPECT_RATIO_IDC_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_COLOR_SAMPLE_INFO_ASPECT_RATIO_IDC_MASK)
/*! @} */

/*! @name RET_QUERY_PF_STG_0_END - End tick of stage 0 */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_PF_STG_0_END_PF_STAGE_0_END_TICK_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_QUERY_PF_STG_0_END_PF_STAGE_0_END_TICK_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_PF_STG_0_END_PF_STAGE_0_END_TICK(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_PF_STG_0_END_PF_STAGE_0_END_TICK_SHIFT)) & VPU_VPU_DEC_RET_QUERY_PF_STG_0_END_PF_STAGE_0_END_TICK_MASK)
/*! @} */

/*! @name RET_QUERY_STD_DEF0 - Standard definition */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_STD_DEF0_BWB_EN_MASK (0x8U)
#define VPU_VPU_DEC_RET_QUERY_STD_DEF0_BWB_EN_SHIFT (3U)
#define VPU_VPU_DEC_RET_QUERY_STD_DEF0_BWB_EN(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_STD_DEF0_BWB_EN_SHIFT)) & VPU_VPU_DEC_RET_QUERY_STD_DEF0_BWB_EN_MASK)

#define VPU_VPU_DEC_RET_QUERY_STD_DEF0_SCALER_EN_MASK (0xF0U)
#define VPU_VPU_DEC_RET_QUERY_STD_DEF0_SCALER_EN_SHIFT (4U)
#define VPU_VPU_DEC_RET_QUERY_STD_DEF0_SCALER_EN(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_STD_DEF0_SCALER_EN_SHIFT)) & VPU_VPU_DEC_RET_QUERY_STD_DEF0_SCALER_EN_MASK)

#define VPU_VPU_DEC_RET_QUERY_STD_DEF0_FBC_EN_MASK (0xF00U)
#define VPU_VPU_DEC_RET_QUERY_STD_DEF0_FBC_EN_SHIFT (8U)
#define VPU_VPU_DEC_RET_QUERY_STD_DEF0_FBC_EN(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_STD_DEF0_FBC_EN_SHIFT)) & VPU_VPU_DEC_RET_QUERY_STD_DEF0_FBC_EN_MASK)

#define VPU_VPU_DEC_RET_QUERY_STD_DEF0_AFBC_EN_MASK (0xF000U)
#define VPU_VPU_DEC_RET_QUERY_STD_DEF0_AFBC_EN_SHIFT (12U)
#define VPU_VPU_DEC_RET_QUERY_STD_DEF0_AFBC_EN(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_STD_DEF0_AFBC_EN_SHIFT)) & VPU_VPU_DEC_RET_QUERY_STD_DEF0_AFBC_EN_MASK)

#define VPU_VPU_DEC_RET_QUERY_STD_DEF0_CONFIG_INFO_MASK (0x3FFF0000U)
#define VPU_VPU_DEC_RET_QUERY_STD_DEF0_CONFIG_INFO_SHIFT (16U)
#define VPU_VPU_DEC_RET_QUERY_STD_DEF0_CONFIG_INFO(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_STD_DEF0_CONFIG_INFO_SHIFT)) & VPU_VPU_DEC_RET_QUERY_STD_DEF0_CONFIG_INFO_MASK)

#define VPU_VPU_DEC_RET_QUERY_STD_DEF0_MAP_CONVERTER_SIG_MASK (0x40000000U)
#define VPU_VPU_DEC_RET_QUERY_STD_DEF0_MAP_CONVERTER_SIG_SHIFT (30U)
#define VPU_VPU_DEC_RET_QUERY_STD_DEF0_MAP_CONVERTER_SIG(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_STD_DEF0_MAP_CONVERTER_SIG_SHIFT)) & VPU_VPU_DEC_RET_QUERY_STD_DEF0_MAP_CONVERTER_SIG_MASK)

#define VPU_VPU_DEC_RET_QUERY_STD_DEF0_MAP_CONVERTER_REG_MASK (0x80000000U)
#define VPU_VPU_DEC_RET_QUERY_STD_DEF0_MAP_CONVERTER_REG_SHIFT (31U)
#define VPU_VPU_DEC_RET_QUERY_STD_DEF0_MAP_CONVERTER_REG(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_STD_DEF0_MAP_CONVERTER_REG_SHIFT)) & VPU_VPU_DEC_RET_QUERY_STD_DEF0_MAP_CONVERTER_REG_MASK)
/*! @} */

/*! @name CMD_INIT_SEC_AXI_SIZE - Seconary AXI memory size */
/*! @{ */

#define VPU_VPU_DEC_CMD_INIT_SEC_AXI_SIZE_SEC_AXI_MEM_SIZE_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_CMD_INIT_SEC_AXI_SIZE_SEC_AXI_MEM_SIZE_SHIFT (0U)
#define VPU_VPU_DEC_CMD_INIT_SEC_AXI_SIZE_SEC_AXI_MEM_SIZE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_INIT_SEC_AXI_SIZE_SEC_AXI_MEM_SIZE_SHIFT)) & VPU_VPU_DEC_CMD_INIT_SEC_AXI_SIZE_SEC_AXI_MEM_SIZE_MASK)
/*! @} */

/*! @name CMD_SEQ_CHANGE_ENABLE_FLAG - Sequence change flag */
/*! @{ */

#define VPU_VPU_DEC_CMD_SEQ_CHANGE_ENABLE_FLAG_RSVD2_MASK (0x1FU)
#define VPU_VPU_DEC_CMD_SEQ_CHANGE_ENABLE_FLAG_RSVD2_SHIFT (0U)
#define VPU_VPU_DEC_CMD_SEQ_CHANGE_ENABLE_FLAG_RSVD2(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SEQ_CHANGE_ENABLE_FLAG_RSVD2_SHIFT)) & VPU_VPU_DEC_CMD_SEQ_CHANGE_ENABLE_FLAG_RSVD2_MASK)

#define VPU_VPU_DEC_CMD_SEQ_CHANGE_ENABLE_FLAG_SEQ_CHANGE_ENABLE_FLAG_PROFILE_MASK (0x20U)
#define VPU_VPU_DEC_CMD_SEQ_CHANGE_ENABLE_FLAG_SEQ_CHANGE_ENABLE_FLAG_PROFILE_SHIFT (5U)
#define VPU_VPU_DEC_CMD_SEQ_CHANGE_ENABLE_FLAG_SEQ_CHANGE_ENABLE_FLAG_PROFILE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SEQ_CHANGE_ENABLE_FLAG_SEQ_CHANGE_ENABLE_FLAG_PROFILE_SHIFT)) & VPU_VPU_DEC_CMD_SEQ_CHANGE_ENABLE_FLAG_SEQ_CHANGE_ENABLE_FLAG_PROFILE_MASK)

#define VPU_VPU_DEC_CMD_SEQ_CHANGE_ENABLE_FLAG_RSVD1_MASK (0x7FC0U)
#define VPU_VPU_DEC_CMD_SEQ_CHANGE_ENABLE_FLAG_RSVD1_SHIFT (6U)
#define VPU_VPU_DEC_CMD_SEQ_CHANGE_ENABLE_FLAG_RSVD1(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SEQ_CHANGE_ENABLE_FLAG_RSVD1_SHIFT)) & VPU_VPU_DEC_CMD_SEQ_CHANGE_ENABLE_FLAG_RSVD1_MASK)

#define VPU_VPU_DEC_CMD_SEQ_CHANGE_ENABLE_FLAG_SEQ_CHANGE_ENABLE_FLAG_CHROMA_FORMAT_MASK (0x8000U)
#define VPU_VPU_DEC_CMD_SEQ_CHANGE_ENABLE_FLAG_SEQ_CHANGE_ENABLE_FLAG_CHROMA_FORMAT_SHIFT (15U)
#define VPU_VPU_DEC_CMD_SEQ_CHANGE_ENABLE_FLAG_SEQ_CHANGE_ENABLE_FLAG_CHROMA_FORMAT(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SEQ_CHANGE_ENABLE_FLAG_SEQ_CHANGE_ENABLE_FLAG_CHROMA_FORMAT_SHIFT)) & VPU_VPU_DEC_CMD_SEQ_CHANGE_ENABLE_FLAG_SEQ_CHANGE_ENABLE_FLAG_CHROMA_FORMAT_MASK)

#define VPU_VPU_DEC_CMD_SEQ_CHANGE_ENABLE_FLAG_SEQ_CHANGE_ENABLE_FLAG_SIZE_MASK (0x10000U)
#define VPU_VPU_DEC_CMD_SEQ_CHANGE_ENABLE_FLAG_SEQ_CHANGE_ENABLE_FLAG_SIZE_SHIFT (16U)
#define VPU_VPU_DEC_CMD_SEQ_CHANGE_ENABLE_FLAG_SEQ_CHANGE_ENABLE_FLAG_SIZE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SEQ_CHANGE_ENABLE_FLAG_SEQ_CHANGE_ENABLE_FLAG_SIZE_SHIFT)) & VPU_VPU_DEC_CMD_SEQ_CHANGE_ENABLE_FLAG_SEQ_CHANGE_ENABLE_FLAG_SIZE_MASK)

#define VPU_VPU_DEC_CMD_SEQ_CHANGE_ENABLE_FLAG_SEQ_CHANGE_ENABLE_FLAG_INTER_RES_CHANGE_MASK (0x20000U)
#define VPU_VPU_DEC_CMD_SEQ_CHANGE_ENABLE_FLAG_SEQ_CHANGE_ENABLE_FLAG_INTER_RES_CHANGE_SHIFT (17U)
#define VPU_VPU_DEC_CMD_SEQ_CHANGE_ENABLE_FLAG_SEQ_CHANGE_ENABLE_FLAG_INTER_RES_CHANGE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SEQ_CHANGE_ENABLE_FLAG_SEQ_CHANGE_ENABLE_FLAG_INTER_RES_CHANGE_SHIFT)) & VPU_VPU_DEC_CMD_SEQ_CHANGE_ENABLE_FLAG_SEQ_CHANGE_ENABLE_FLAG_INTER_RES_CHANGE_MASK)

#define VPU_VPU_DEC_CMD_SEQ_CHANGE_ENABLE_FLAG_SEQ_CHANGE_ENABLE_FLAG_BITDEPTH_MASK (0x40000U)
#define VPU_VPU_DEC_CMD_SEQ_CHANGE_ENABLE_FLAG_SEQ_CHANGE_ENABLE_FLAG_BITDEPTH_SHIFT (18U)
#define VPU_VPU_DEC_CMD_SEQ_CHANGE_ENABLE_FLAG_SEQ_CHANGE_ENABLE_FLAG_BITDEPTH(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SEQ_CHANGE_ENABLE_FLAG_SEQ_CHANGE_ENABLE_FLAG_BITDEPTH_SHIFT)) & VPU_VPU_DEC_CMD_SEQ_CHANGE_ENABLE_FLAG_SEQ_CHANGE_ENABLE_FLAG_BITDEPTH_MASK)

#define VPU_VPU_DEC_CMD_SEQ_CHANGE_ENABLE_FLAG_SEQ_CHANGE_ENABLE_FLAG_DPB_COUNT_MASK (0x80000U)
#define VPU_VPU_DEC_CMD_SEQ_CHANGE_ENABLE_FLAG_SEQ_CHANGE_ENABLE_FLAG_DPB_COUNT_SHIFT (19U)
#define VPU_VPU_DEC_CMD_SEQ_CHANGE_ENABLE_FLAG_SEQ_CHANGE_ENABLE_FLAG_DPB_COUNT(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SEQ_CHANGE_ENABLE_FLAG_SEQ_CHANGE_ENABLE_FLAG_DPB_COUNT_SHIFT)) & VPU_VPU_DEC_CMD_SEQ_CHANGE_ENABLE_FLAG_SEQ_CHANGE_ENABLE_FLAG_DPB_COUNT_MASK)

#define VPU_VPU_DEC_CMD_SEQ_CHANGE_ENABLE_FLAG_RSVD0_MASK (0xFFF00000U)
#define VPU_VPU_DEC_CMD_SEQ_CHANGE_ENABLE_FLAG_RSVD0_SHIFT (20U)
#define VPU_VPU_DEC_CMD_SEQ_CHANGE_ENABLE_FLAG_RSVD0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SEQ_CHANGE_ENABLE_FLAG_RSVD0_SHIFT)) & VPU_VPU_DEC_CMD_SEQ_CHANGE_ENABLE_FLAG_RSVD0_MASK)
/*! @} */

/*! @name CMD_WAKEUP_SEC_AXI_SIZE - Seconary AXI memory size */
/*! @{ */

#define VPU_VPU_DEC_CMD_WAKEUP_SEC_AXI_SIZE_SEC_AXI_MEM_SIZE_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_CMD_WAKEUP_SEC_AXI_SIZE_SEC_AXI_MEM_SIZE_SHIFT (0U)
#define VPU_VPU_DEC_CMD_WAKEUP_SEC_AXI_SIZE_SEC_AXI_MEM_SIZE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_WAKEUP_SEC_AXI_SIZE_SEC_AXI_MEM_SIZE_SHIFT)) & VPU_VPU_DEC_CMD_WAKEUP_SEC_AXI_SIZE_SEC_AXI_MEM_SIZE_MASK)
/*! @} */

/*! @name RET_QUERY_BW_FBD_C_AXI_READ - FBD AXI read chroma bandwidth */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_BW_FBD_C_AXI_READ_BW_FBD_C_AXI_READ_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_QUERY_BW_FBD_C_AXI_READ_BW_FBD_C_AXI_READ_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_BW_FBD_C_AXI_READ_BW_FBD_C_AXI_READ(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_BW_FBD_C_AXI_READ_BW_FBD_C_AXI_READ_SHIFT)) & VPU_VPU_DEC_RET_QUERY_BW_FBD_C_AXI_READ_BW_FBD_C_AXI_READ_MASK)
/*! @} */

/*! @name RET_QUERY_DEC_ASPECT_RATIO - Sample Aspect Ratio */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_DEC_ASPECT_RATIO_SAR_HEIGHT_MASK (0xFFFFU)
#define VPU_VPU_DEC_RET_QUERY_DEC_ASPECT_RATIO_SAR_HEIGHT_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_DEC_ASPECT_RATIO_SAR_HEIGHT(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_ASPECT_RATIO_SAR_HEIGHT_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_ASPECT_RATIO_SAR_HEIGHT_MASK)

#define VPU_VPU_DEC_RET_QUERY_DEC_ASPECT_RATIO_SAR_WIDTH_MASK (0xFFFF0000U)
#define VPU_VPU_DEC_RET_QUERY_DEC_ASPECT_RATIO_SAR_WIDTH_SHIFT (16U)
#define VPU_VPU_DEC_RET_QUERY_DEC_ASPECT_RATIO_SAR_WIDTH(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_ASPECT_RATIO_SAR_WIDTH_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_ASPECT_RATIO_SAR_WIDTH_MASK)
/*! @} */

/*! @name RET_QUERY_PF_STG_0_BLOCK_START - Blocking start tick of stage 0 */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_PF_STG_0_BLOCK_START_PF_STAGE_0_BLOCK_START_TICK_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_QUERY_PF_STG_0_BLOCK_START_PF_STAGE_0_BLOCK_START_TICK_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_PF_STG_0_BLOCK_START_PF_STAGE_0_BLOCK_START_TICK(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_PF_STG_0_BLOCK_START_PF_STAGE_0_BLOCK_START_TICK_SHIFT)) & VPU_VPU_DEC_RET_QUERY_PF_STG_0_BLOCK_START_PF_STAGE_0_BLOCK_START_TICK_MASK)
/*! @} */

/*! @name RET_QUERY_STD_DEF1 - Standard definition */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_STD_DEF1_FEATURE_SET_MASK (0xFFFFU)
#define VPU_VPU_DEC_RET_QUERY_STD_DEF1_FEATURE_SET_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_STD_DEF1_FEATURE_SET(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_STD_DEF1_FEATURE_SET_SHIFT)) & VPU_VPU_DEC_RET_QUERY_STD_DEF1_FEATURE_SET_MASK)

#define VPU_VPU_DEC_RET_QUERY_STD_DEF1_INTERNAL_BLOCK_MASK (0xFFFF0000U)
#define VPU_VPU_DEC_RET_QUERY_STD_DEF1_INTERNAL_BLOCK_SHIFT (16U)
#define VPU_VPU_DEC_RET_QUERY_STD_DEF1_INTERNAL_BLOCK(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_STD_DEF1_INTERNAL_BLOCK_SHIFT)) & VPU_VPU_DEC_RET_QUERY_STD_DEF1_INTERNAL_BLOCK_MASK)
/*! @} */

/*! @name CMD_CREATE_INST_ADDR_TEMP_BASE - Temporal buffer base address */
/*! @{ */

#define VPU_VPU_DEC_CMD_CREATE_INST_ADDR_TEMP_BASE_TEMP_BUF_BASE_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_CMD_CREATE_INST_ADDR_TEMP_BASE_TEMP_BUF_BASE_SHIFT (0U)
#define VPU_VPU_DEC_CMD_CREATE_INST_ADDR_TEMP_BASE_TEMP_BUF_BASE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_CREATE_INST_ADDR_TEMP_BASE_TEMP_BUF_BASE_SHIFT)) & VPU_VPU_DEC_CMD_CREATE_INST_ADDR_TEMP_BASE_TEMP_BUF_BASE_MASK)
/*! @} */

/*! @name CMD_DEC_SEI_MASK - User Data Mask */
/*! @{ */

#define VPU_VPU_DEC_CMD_DEC_SEI_MASK_RSVD3_MASK  (0x3U)
#define VPU_VPU_DEC_CMD_DEC_SEI_MASK_RSVD3_SHIFT (0U)
#define VPU_VPU_DEC_CMD_DEC_SEI_MASK_RSVD3(x)    (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_DEC_SEI_MASK_RSVD3_SHIFT)) & VPU_VPU_DEC_CMD_DEC_SEI_MASK_RSVD3_MASK)

#define VPU_VPU_DEC_CMD_DEC_SEI_MASK_REPORT_VUI_MASK (0x4U)
#define VPU_VPU_DEC_CMD_DEC_SEI_MASK_REPORT_VUI_SHIFT (2U)
#define VPU_VPU_DEC_CMD_DEC_SEI_MASK_REPORT_VUI(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_DEC_SEI_MASK_REPORT_VUI_SHIFT)) & VPU_VPU_DEC_CMD_DEC_SEI_MASK_REPORT_VUI_MASK)

#define VPU_VPU_DEC_CMD_DEC_SEI_MASK_RSVD2_MASK  (0x8U)
#define VPU_VPU_DEC_CMD_DEC_SEI_MASK_RSVD2_SHIFT (3U)
#define VPU_VPU_DEC_CMD_DEC_SEI_MASK_RSVD2(x)    (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_DEC_SEI_MASK_RSVD2_SHIFT)) & VPU_VPU_DEC_CMD_DEC_SEI_MASK_RSVD2_MASK)

#define VPU_VPU_DEC_CMD_DEC_SEI_MASK_PREFIX_SEI_PIC_TIMING_MASK (0x10U)
#define VPU_VPU_DEC_CMD_DEC_SEI_MASK_PREFIX_SEI_PIC_TIMING_SHIFT (4U)
#define VPU_VPU_DEC_CMD_DEC_SEI_MASK_PREFIX_SEI_PIC_TIMING(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_DEC_SEI_MASK_PREFIX_SEI_PIC_TIMING_SHIFT)) & VPU_VPU_DEC_CMD_DEC_SEI_MASK_PREFIX_SEI_PIC_TIMING_MASK)

#define VPU_VPU_DEC_CMD_DEC_SEI_MASK_PREFIX_SEI_USER_DATA_REGISTERED_ITU_T_T35_0_MASK (0x20U)
#define VPU_VPU_DEC_CMD_DEC_SEI_MASK_PREFIX_SEI_USER_DATA_REGISTERED_ITU_T_T35_0_SHIFT (5U)
#define VPU_VPU_DEC_CMD_DEC_SEI_MASK_PREFIX_SEI_USER_DATA_REGISTERED_ITU_T_T35_0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_DEC_SEI_MASK_PREFIX_SEI_USER_DATA_REGISTERED_ITU_T_T35_0_SHIFT)) & VPU_VPU_DEC_CMD_DEC_SEI_MASK_PREFIX_SEI_USER_DATA_REGISTERED_ITU_T_T35_0_MASK)

#define VPU_VPU_DEC_CMD_DEC_SEI_MASK_PREFIX_SEI_USER_DATA_UNREGISTERED_MASK (0x40U)
#define VPU_VPU_DEC_CMD_DEC_SEI_MASK_PREFIX_SEI_USER_DATA_UNREGISTERED_SHIFT (6U)
#define VPU_VPU_DEC_CMD_DEC_SEI_MASK_PREFIX_SEI_USER_DATA_UNREGISTERED(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_DEC_SEI_MASK_PREFIX_SEI_USER_DATA_UNREGISTERED_SHIFT)) & VPU_VPU_DEC_CMD_DEC_SEI_MASK_PREFIX_SEI_USER_DATA_UNREGISTERED_MASK)

#define VPU_VPU_DEC_CMD_DEC_SEI_MASK_SUFFIX_SEI_USER_DATA_REGISTERED_ITU_T_T35_0_MASK (0x80U)
#define VPU_VPU_DEC_CMD_DEC_SEI_MASK_SUFFIX_SEI_USER_DATA_REGISTERED_ITU_T_T35_0_SHIFT (7U)
#define VPU_VPU_DEC_CMD_DEC_SEI_MASK_SUFFIX_SEI_USER_DATA_REGISTERED_ITU_T_T35_0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_DEC_SEI_MASK_SUFFIX_SEI_USER_DATA_REGISTERED_ITU_T_T35_0_SHIFT)) & VPU_VPU_DEC_CMD_DEC_SEI_MASK_SUFFIX_SEI_USER_DATA_REGISTERED_ITU_T_T35_0_MASK)

#define VPU_VPU_DEC_CMD_DEC_SEI_MASK_SUFFIX_SEI_USER_DATA_UNREGISTERED_MASK (0x100U)
#define VPU_VPU_DEC_CMD_DEC_SEI_MASK_SUFFIX_SEI_USER_DATA_UNREGISTERED_SHIFT (8U)
#define VPU_VPU_DEC_CMD_DEC_SEI_MASK_SUFFIX_SEI_USER_DATA_UNREGISTERED(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_DEC_SEI_MASK_SUFFIX_SEI_USER_DATA_UNREGISTERED_SHIFT)) & VPU_VPU_DEC_CMD_DEC_SEI_MASK_SUFFIX_SEI_USER_DATA_UNREGISTERED_MASK)

#define VPU_VPU_DEC_CMD_DEC_SEI_MASK_RSVD1_MASK  (0x200U)
#define VPU_VPU_DEC_CMD_DEC_SEI_MASK_RSVD1_SHIFT (9U)
#define VPU_VPU_DEC_CMD_DEC_SEI_MASK_RSVD1(x)    (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_DEC_SEI_MASK_RSVD1_SHIFT)) & VPU_VPU_DEC_CMD_DEC_SEI_MASK_RSVD1_MASK)

#define VPU_VPU_DEC_CMD_DEC_SEI_MASK_PREFIX_SEI_MASTERING_DISPLAY_COLOUR_VOLUME_MASK (0x400U)
#define VPU_VPU_DEC_CMD_DEC_SEI_MASK_PREFIX_SEI_MASTERING_DISPLAY_COLOUR_VOLUME_SHIFT (10U)
#define VPU_VPU_DEC_CMD_DEC_SEI_MASK_PREFIX_SEI_MASTERING_DISPLAY_COLOUR_VOLUME(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_DEC_SEI_MASK_PREFIX_SEI_MASTERING_DISPLAY_COLOUR_VOLUME_SHIFT)) & VPU_VPU_DEC_CMD_DEC_SEI_MASK_PREFIX_SEI_MASTERING_DISPLAY_COLOUR_VOLUME_MASK)

#define VPU_VPU_DEC_CMD_DEC_SEI_MASK_PREFIX_SEI_CHROMA_RESAMPLING_FILTER_HINT_MASK (0x800U)
#define VPU_VPU_DEC_CMD_DEC_SEI_MASK_PREFIX_SEI_CHROMA_RESAMPLING_FILTER_HINT_SHIFT (11U)
#define VPU_VPU_DEC_CMD_DEC_SEI_MASK_PREFIX_SEI_CHROMA_RESAMPLING_FILTER_HINT(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_DEC_SEI_MASK_PREFIX_SEI_CHROMA_RESAMPLING_FILTER_HINT_SHIFT)) & VPU_VPU_DEC_CMD_DEC_SEI_MASK_PREFIX_SEI_CHROMA_RESAMPLING_FILTER_HINT_MASK)

#define VPU_VPU_DEC_CMD_DEC_SEI_MASK_PREFIX_SEI_KNEE_FUNCTION_INFO_MASK (0x1000U)
#define VPU_VPU_DEC_CMD_DEC_SEI_MASK_PREFIX_SEI_KNEE_FUNCTION_INFO_SHIFT (12U)
#define VPU_VPU_DEC_CMD_DEC_SEI_MASK_PREFIX_SEI_KNEE_FUNCTION_INFO(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_DEC_SEI_MASK_PREFIX_SEI_KNEE_FUNCTION_INFO_SHIFT)) & VPU_VPU_DEC_CMD_DEC_SEI_MASK_PREFIX_SEI_KNEE_FUNCTION_INFO_MASK)

#define VPU_VPU_DEC_CMD_DEC_SEI_MASK_PREFIX_SEI_TONE_MAPPING_INFO_MASK (0x2000U)
#define VPU_VPU_DEC_CMD_DEC_SEI_MASK_PREFIX_SEI_TONE_MAPPING_INFO_SHIFT (13U)
#define VPU_VPU_DEC_CMD_DEC_SEI_MASK_PREFIX_SEI_TONE_MAPPING_INFO(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_DEC_SEI_MASK_PREFIX_SEI_TONE_MAPPING_INFO_SHIFT)) & VPU_VPU_DEC_CMD_DEC_SEI_MASK_PREFIX_SEI_TONE_MAPPING_INFO_MASK)

#define VPU_VPU_DEC_CMD_DEC_SEI_MASK_PREFIX_SEI_FILM_GRAIN_CHARACTERISTICS_INFO_MASK (0x4000U)
#define VPU_VPU_DEC_CMD_DEC_SEI_MASK_PREFIX_SEI_FILM_GRAIN_CHARACTERISTICS_INFO_SHIFT (14U)
#define VPU_VPU_DEC_CMD_DEC_SEI_MASK_PREFIX_SEI_FILM_GRAIN_CHARACTERISTICS_INFO(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_DEC_SEI_MASK_PREFIX_SEI_FILM_GRAIN_CHARACTERISTICS_INFO_SHIFT)) & VPU_VPU_DEC_CMD_DEC_SEI_MASK_PREFIX_SEI_FILM_GRAIN_CHARACTERISTICS_INFO_MASK)

#define VPU_VPU_DEC_CMD_DEC_SEI_MASK_PREFIX_SEI_CONTENT_LIGHT_LEVEL_INFO_MASK (0x8000U)
#define VPU_VPU_DEC_CMD_DEC_SEI_MASK_PREFIX_SEI_CONTENT_LIGHT_LEVEL_INFO_SHIFT (15U)
#define VPU_VPU_DEC_CMD_DEC_SEI_MASK_PREFIX_SEI_CONTENT_LIGHT_LEVEL_INFO(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_DEC_SEI_MASK_PREFIX_SEI_CONTENT_LIGHT_LEVEL_INFO_SHIFT)) & VPU_VPU_DEC_CMD_DEC_SEI_MASK_PREFIX_SEI_CONTENT_LIGHT_LEVEL_INFO_MASK)

#define VPU_VPU_DEC_CMD_DEC_SEI_MASK_SUFFIX_SEI_COLOUR_REAMPPING_INFO_MASK (0x10000U)
#define VPU_VPU_DEC_CMD_DEC_SEI_MASK_SUFFIX_SEI_COLOUR_REAMPPING_INFO_SHIFT (16U)
#define VPU_VPU_DEC_CMD_DEC_SEI_MASK_SUFFIX_SEI_COLOUR_REAMPPING_INFO(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_DEC_SEI_MASK_SUFFIX_SEI_COLOUR_REAMPPING_INFO_SHIFT)) & VPU_VPU_DEC_CMD_DEC_SEI_MASK_SUFFIX_SEI_COLOUR_REAMPPING_INFO_MASK)

#define VPU_VPU_DEC_CMD_DEC_SEI_MASK_RSVD0_MASK  (0xFFFE0000U)
#define VPU_VPU_DEC_CMD_DEC_SEI_MASK_RSVD0_SHIFT (17U)
#define VPU_VPU_DEC_CMD_DEC_SEI_MASK_RSVD0(x)    (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_DEC_SEI_MASK_RSVD0_SHIFT)) & VPU_VPU_DEC_CMD_DEC_SEI_MASK_RSVD0_MASK)
/*! @} */

/*! @name CMD_INIT_HW_OPTION - VPU hardware option */
/*! @{ */

#define VPU_VPU_DEC_CMD_INIT_HW_OPTION_UART_OPTION_MASK (0xFFFF0000U)
#define VPU_VPU_DEC_CMD_INIT_HW_OPTION_UART_OPTION_SHIFT (16U)
#define VPU_VPU_DEC_CMD_INIT_HW_OPTION_UART_OPTION(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_INIT_HW_OPTION_UART_OPTION_SHIFT)) & VPU_VPU_DEC_CMD_INIT_HW_OPTION_UART_OPTION_MASK)
/*! @} */

/*! @name CMD_WAKEUP_HW_OPTION - VPU hardware option */
/*! @{ */

#define VPU_VPU_DEC_CMD_WAKEUP_HW_OPTION_UART_OPTION_MASK (0xFFFF0000U)
#define VPU_VPU_DEC_CMD_WAKEUP_HW_OPTION_UART_OPTION_SHIFT (16U)
#define VPU_VPU_DEC_CMD_WAKEUP_HW_OPTION_UART_OPTION(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_WAKEUP_HW_OPTION_UART_OPTION_SHIFT)) & VPU_VPU_DEC_CMD_WAKEUP_HW_OPTION_UART_OPTION_MASK)
/*! @} */

/*! @name RET_QUERY_BW_FBC_C_AXI_WRITE - FBC AXI write chroma bandwidth */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_BW_FBC_C_AXI_WRITE_BW_FBC_C_AXI_WRITE_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_QUERY_BW_FBC_C_AXI_WRITE_BW_FBC_C_AXI_WRITE_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_BW_FBC_C_AXI_WRITE_BW_FBC_C_AXI_WRITE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_BW_FBC_C_AXI_WRITE_BW_FBC_C_AXI_WRITE_SHIFT)) & VPU_VPU_DEC_RET_QUERY_BW_FBC_C_AXI_WRITE_BW_FBC_C_AXI_WRITE_MASK)
/*! @} */

/*! @name RET_QUERY_CONF_FEATURE - Configuration feature */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_CONF_FEATURE_CONFIG_FEATURE_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_QUERY_CONF_FEATURE_CONFIG_FEATURE_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_CONF_FEATURE_CONFIG_FEATURE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_CONF_FEATURE_CONFIG_FEATURE_SHIFT)) & VPU_VPU_DEC_RET_QUERY_CONF_FEATURE_CONFIG_FEATURE_MASK)
/*! @} */

/*! @name RET_QUERY_DEC_BIT_RATE - Maximum Bit Rate */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_DEC_BIT_RATE_MAX_BIT_RATE_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_QUERY_DEC_BIT_RATE_MAX_BIT_RATE_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_DEC_BIT_RATE_MAX_BIT_RATE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_BIT_RATE_MAX_BIT_RATE_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_BIT_RATE_MAX_BIT_RATE_MASK)
/*! @} */

/*! @name RET_QUERY_PF_STG_0_BLOCK_END - Blocking end tick of stage 0 */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_PF_STG_0_BLOCK_END_PF_STAGE_0_BLOCK_END_TICK_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_QUERY_PF_STG_0_BLOCK_END_PF_STAGE_0_BLOCK_END_TICK_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_PF_STG_0_BLOCK_END_PF_STAGE_0_BLOCK_END_TICK(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_PF_STG_0_BLOCK_END_PF_STAGE_0_BLOCK_END_TICK_SHIFT)) & VPU_VPU_DEC_RET_QUERY_PF_STG_0_BLOCK_END_PF_STAGE_0_BLOCK_END_TICK_MASK)
/*! @} */

/*! @name CMD_CREATE_INST_TEMP_SIZE - Temporal buffer size */
/*! @{ */

#define VPU_VPU_DEC_CMD_CREATE_INST_TEMP_SIZE_TEMP_BUF_SIZE_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_CMD_CREATE_INST_TEMP_SIZE_TEMP_BUF_SIZE_SHIFT (0U)
#define VPU_VPU_DEC_CMD_CREATE_INST_TEMP_SIZE_TEMP_BUF_SIZE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_CREATE_INST_TEMP_SIZE_TEMP_BUF_SIZE_SHIFT)) & VPU_VPU_DEC_CMD_CREATE_INST_TEMP_SIZE_TEMP_BUF_SIZE_MASK)
/*! @} */

/*! @name CMD_DEC_TEMPORAL_ID_PLUS1 - Max Decode Temporal ID */
/*! @{ */

#define VPU_VPU_DEC_CMD_DEC_TEMPORAL_ID_PLUS1_TARGET_DEC_TEMP_ID_PLUS1_MASK (0xFFU)
#define VPU_VPU_DEC_CMD_DEC_TEMPORAL_ID_PLUS1_TARGET_DEC_TEMP_ID_PLUS1_SHIFT (0U)
#define VPU_VPU_DEC_CMD_DEC_TEMPORAL_ID_PLUS1_TARGET_DEC_TEMP_ID_PLUS1(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_DEC_TEMPORAL_ID_PLUS1_TARGET_DEC_TEMP_ID_PLUS1_SHIFT)) & VPU_VPU_DEC_CMD_DEC_TEMPORAL_ID_PLUS1_TARGET_DEC_TEMP_ID_PLUS1_MASK)

#define VPU_VPU_DEC_CMD_DEC_TEMPORAL_ID_PLUS1_DEC_TEMP_ID_MODE_MASK (0x100U)
#define VPU_VPU_DEC_CMD_DEC_TEMPORAL_ID_PLUS1_DEC_TEMP_ID_MODE_SHIFT (8U)
#define VPU_VPU_DEC_CMD_DEC_TEMPORAL_ID_PLUS1_DEC_TEMP_ID_MODE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_DEC_TEMPORAL_ID_PLUS1_DEC_TEMP_ID_MODE_SHIFT)) & VPU_VPU_DEC_CMD_DEC_TEMPORAL_ID_PLUS1_DEC_TEMP_ID_MODE_MASK)

#define VPU_VPU_DEC_CMD_DEC_TEMPORAL_ID_PLUS1_TARGET_DEC_SPATIAL_ID_PLUS1_MASK (0xE00U)
#define VPU_VPU_DEC_CMD_DEC_TEMPORAL_ID_PLUS1_TARGET_DEC_SPATIAL_ID_PLUS1_SHIFT (9U)
#define VPU_VPU_DEC_CMD_DEC_TEMPORAL_ID_PLUS1_TARGET_DEC_SPATIAL_ID_PLUS1(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_DEC_TEMPORAL_ID_PLUS1_TARGET_DEC_SPATIAL_ID_PLUS1_SHIFT)) & VPU_VPU_DEC_CMD_DEC_TEMPORAL_ID_PLUS1_TARGET_DEC_SPATIAL_ID_PLUS1_MASK)
/*! @} */

/*! @name RET_QUERY_BW_PRI_AXI_READ - Primary AXI read bandwidth */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_BW_PRI_AXI_READ_BW_PRI_AXI_READ_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_QUERY_BW_PRI_AXI_READ_BW_PRI_AXI_READ_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_BW_PRI_AXI_READ_BW_PRI_AXI_READ(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_BW_PRI_AXI_READ_BW_PRI_AXI_READ_SHIFT)) & VPU_VPU_DEC_RET_QUERY_BW_PRI_AXI_READ_BW_PRI_AXI_READ_MASK)
/*! @} */

/*! @name RET_QUERY_CONF_DATE - Configuration date */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_CONF_DATE_HW_DATE_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_QUERY_CONF_DATE_HW_DATE_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_CONF_DATE_HW_DATE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_CONF_DATE_HW_DATE_SHIFT)) & VPU_VPU_DEC_RET_QUERY_CONF_DATE_HW_DATE_MASK)
/*! @} */

/*! @name RET_QUERY_DEC_FRAME_RATE_NR - Frame Rate Numerator */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_DEC_FRAME_RATE_NR_FRAME_RATE_NR_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_QUERY_DEC_FRAME_RATE_NR_FRAME_RATE_NR_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_DEC_FRAME_RATE_NR_FRAME_RATE_NR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_FRAME_RATE_NR_FRAME_RATE_NR_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_FRAME_RATE_NR_FRAME_RATE_NR_MASK)
/*! @} */

/*! @name RET_QUERY_PF_STG_1_START - Start tick of stage 1 */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_PF_STG_1_START_PF_STAGE_1_START_TICK_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_QUERY_PF_STG_1_START_PF_STAGE_1_START_TICK_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_PF_STG_1_START_PF_STAGE_1_START_TICK(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_PF_STG_1_START_PF_STAGE_1_START_TICK_SHIFT)) & VPU_VPU_DEC_RET_QUERY_PF_STG_1_START_PF_STAGE_1_START_TICK_MASK)
/*! @} */

/*! @name CMD_DEC_FORCE_FB_LATENCY_PLUS1 - User define display latency */
/*! @{ */

#define VPU_VPU_DEC_CMD_DEC_FORCE_FB_LATENCY_PLUS1_USER_DEF_DISP_LATENCY_PLUS1_MASK (0x1FU)
#define VPU_VPU_DEC_CMD_DEC_FORCE_FB_LATENCY_PLUS1_USER_DEF_DISP_LATENCY_PLUS1_SHIFT (0U)
#define VPU_VPU_DEC_CMD_DEC_FORCE_FB_LATENCY_PLUS1_USER_DEF_DISP_LATENCY_PLUS1(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_DEC_FORCE_FB_LATENCY_PLUS1_USER_DEF_DISP_LATENCY_PLUS1_SHIFT)) & VPU_VPU_DEC_CMD_DEC_FORCE_FB_LATENCY_PLUS1_USER_DEF_DISP_LATENCY_PLUS1_MASK)
/*! @} */

/*! @name CMD_SET_FB_ADDR_LUMA_BASE - Luma base of BWB idx to be update */
/*! @{ */

#define VPU_VPU_DEC_CMD_SET_FB_ADDR_LUMA_BASE_LUMA_BASE0_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_LUMA_BASE_LUMA_BASE0_SHIFT (0U)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_LUMA_BASE_LUMA_BASE0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_ADDR_LUMA_BASE_LUMA_BASE0_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_ADDR_LUMA_BASE_LUMA_BASE0_MASK)
/*! @} */

/*! @name CMD_SET_FB_ADDR_LUMA_BASE0 - Luma base address of DPB index 0 */
/*! @{ */

#define VPU_VPU_DEC_CMD_SET_FB_ADDR_LUMA_BASE0_LUMA_BASE0_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_LUMA_BASE0_LUMA_BASE0_SHIFT (0U)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_LUMA_BASE0_LUMA_BASE0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_ADDR_LUMA_BASE0_LUMA_BASE0_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_ADDR_LUMA_BASE0_LUMA_BASE0_MASK)
/*! @} */

/*! @name RET_QUERY_BW_PRI_AXI_WRITE - Primary AXI write bandwidth */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_BW_PRI_AXI_WRITE_BW_PRI_AXI_WRITE_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_QUERY_BW_PRI_AXI_WRITE_BW_PRI_AXI_WRITE_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_BW_PRI_AXI_WRITE_BW_PRI_AXI_WRITE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_BW_PRI_AXI_WRITE_BW_PRI_AXI_WRITE_SHIFT)) & VPU_VPU_DEC_RET_QUERY_BW_PRI_AXI_WRITE_BW_PRI_AXI_WRITE_MASK)
/*! @} */

/*! @name RET_QUERY_CONF_REVISION - The revision of H/W configuration */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_CONF_REVISION_HW_REVISION_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_QUERY_CONF_REVISION_HW_REVISION_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_CONF_REVISION_HW_REVISION(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_CONF_REVISION_HW_REVISION_SHIFT)) & VPU_VPU_DEC_RET_QUERY_CONF_REVISION_HW_REVISION_MASK)
/*! @} */

/*! @name RET_QUERY_DEC_FRAME_RATE_DR - Frame Rate Denominator */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_DEC_FRAME_RATE_DR_FRAME_RATE_DR_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_QUERY_DEC_FRAME_RATE_DR_FRAME_RATE_DR_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_DEC_FRAME_RATE_DR_FRAME_RATE_DR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_FRAME_RATE_DR_FRAME_RATE_DR_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_FRAME_RATE_DR_FRAME_RATE_DR_MASK)
/*! @} */

/*! @name RET_QUERY_PF_STG_1_END - End tick of stage 1 */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_PF_STG_1_END_PF_STAGE_1_END_TICK_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_QUERY_PF_STG_1_END_PF_STAGE_1_END_TICK_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_PF_STG_1_END_PF_STAGE_1_END_TICK(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_PF_STG_1_END_PF_STAGE_1_END_TICK_SHIFT)) & VPU_VPU_DEC_RET_QUERY_PF_STG_1_END_PF_STAGE_1_END_TICK_MASK)
/*! @} */

/*! @name CMD_CREATE_INST_EXT_ADDR - Ext address for instance */
/*! @{ */

#define VPU_VPU_DEC_CMD_CREATE_INST_EXT_ADDR_PRI_AXI_EXT_ADDR_MASK (0xFFU)
#define VPU_VPU_DEC_CMD_CREATE_INST_EXT_ADDR_PRI_AXI_EXT_ADDR_SHIFT (0U)
#define VPU_VPU_DEC_CMD_CREATE_INST_EXT_ADDR_PRI_AXI_EXT_ADDR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_CREATE_INST_EXT_ADDR_PRI_AXI_EXT_ADDR_SHIFT)) & VPU_VPU_DEC_CMD_CREATE_INST_EXT_ADDR_PRI_AXI_EXT_ADDR_MASK)

#define VPU_VPU_DEC_CMD_CREATE_INST_EXT_ADDR_RSVD0_MASK (0xFFFFFF00U)
#define VPU_VPU_DEC_CMD_CREATE_INST_EXT_ADDR_RSVD0_SHIFT (8U)
#define VPU_VPU_DEC_CMD_CREATE_INST_EXT_ADDR_RSVD0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_CREATE_INST_EXT_ADDR_RSVD0_SHIFT)) & VPU_VPU_DEC_CMD_CREATE_INST_EXT_ADDR_RSVD0_MASK)
/*! @} */

/*! @name CMD_SET_FB_ADDR_CB_BASE - Cb base of BWB idx to be update */
/*! @{ */

#define VPU_VPU_DEC_CMD_SET_FB_ADDR_CB_BASE_CB_BASE0_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_CB_BASE_CB_BASE0_SHIFT (0U)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_CB_BASE_CB_BASE0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_ADDR_CB_BASE_CB_BASE0_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_ADDR_CB_BASE_CB_BASE0_MASK)
/*! @} */

/*! @name CMD_SET_FB_ADDR_CB_BASE0 - Cb base address of DPB index 0 */
/*! @{ */

#define VPU_VPU_DEC_CMD_SET_FB_ADDR_CB_BASE0_CB_BASE0_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_CB_BASE0_CB_BASE0_SHIFT (0U)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_CB_BASE0_CB_BASE0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_ADDR_CB_BASE0_CB_BASE0_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_ADDR_CB_BASE0_CB_BASE0_MASK)
/*! @} */

/*! @name RET_QUERY_BW_SEC_AXI_READ - Secondary AXI read bandwidth */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_BW_SEC_AXI_READ_BW_SEC_AXI_READ_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_QUERY_BW_SEC_AXI_READ_BW_SEC_AXI_READ_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_BW_SEC_AXI_READ_BW_SEC_AXI_READ(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_BW_SEC_AXI_READ_BW_SEC_AXI_READ_SHIFT)) & VPU_VPU_DEC_RET_QUERY_BW_SEC_AXI_READ_BW_SEC_AXI_READ_MASK)
/*! @} */

/*! @name RET_QUERY_CONF_TYPE - The define value of H/W configuration */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_CONF_TYPE_HW_TYPE_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_QUERY_CONF_TYPE_HW_TYPE_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_CONF_TYPE_HW_TYPE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_CONF_TYPE_HW_TYPE_SHIFT)) & VPU_VPU_DEC_RET_QUERY_CONF_TYPE_HW_TYPE_MASK)
/*! @} */

/*! @name RET_QUERY_DEC_NUM_REQURED_FB - Required Number of Minimum DPB */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_DEC_NUM_REQURED_FB_MIN_DPB_NUM_MASK (0x1FU)
#define VPU_VPU_DEC_RET_QUERY_DEC_NUM_REQURED_FB_MIN_DPB_NUM_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_DEC_NUM_REQURED_FB_MIN_DPB_NUM(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_NUM_REQURED_FB_MIN_DPB_NUM_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_NUM_REQURED_FB_MIN_DPB_NUM_MASK)
/*! @} */

/*! @name RET_QUERY_PF_STG_1_BLOCK_START - Blocking start tick of stage 1 */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_PF_STG_1_BLOCK_START_PF_STAGE_1_BLOCK_START_TICK_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_QUERY_PF_STG_1_BLOCK_START_PF_STAGE_1_BLOCK_START_TICK_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_PF_STG_1_BLOCK_START_PF_STAGE_1_BLOCK_START_TICK(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_PF_STG_1_BLOCK_START_PF_STAGE_1_BLOCK_START_TICK_SHIFT)) & VPU_VPU_DEC_RET_QUERY_PF_STG_1_BLOCK_START_PF_STAGE_1_BLOCK_START_TICK_MASK)
/*! @} */

/*! @name CMD_CREATE_INST_NUM_CQ_DEPTH_M1 - Number of CQ depth_minus1 */
/*! @{ */

#define VPU_VPU_DEC_CMD_CREATE_INST_NUM_CQ_DEPTH_M1_NUM_CQ_DEPTH_M1_MASK (0xFU)
#define VPU_VPU_DEC_CMD_CREATE_INST_NUM_CQ_DEPTH_M1_NUM_CQ_DEPTH_M1_SHIFT (0U)
#define VPU_VPU_DEC_CMD_CREATE_INST_NUM_CQ_DEPTH_M1_NUM_CQ_DEPTH_M1(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_CREATE_INST_NUM_CQ_DEPTH_M1_NUM_CQ_DEPTH_M1_SHIFT)) & VPU_VPU_DEC_CMD_CREATE_INST_NUM_CQ_DEPTH_M1_NUM_CQ_DEPTH_M1_MASK)
/*! @} */

/*! @name CMD_SET_FB_ADDR_CR_BASE - Cr base of BWB idx to be update */
/*! @{ */

#define VPU_VPU_DEC_CMD_SET_FB_ADDR_CR_BASE_CR_BASE0_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_CR_BASE_CR_BASE0_SHIFT (0U)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_CR_BASE_CR_BASE0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_ADDR_CR_BASE_CR_BASE0_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_ADDR_CR_BASE_CR_BASE0_MASK)
/*! @} */

/*! @name CMD_SET_FB_ADDR_CR_BASE0 - Cr base address of DPB index 0 */
/*! @{ */

#define VPU_VPU_DEC_CMD_SET_FB_ADDR_CR_BASE0_CR_BASE0_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_CR_BASE0_CR_BASE0_SHIFT (0U)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_CR_BASE0_CR_BASE0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_ADDR_CR_BASE0_CR_BASE0_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_ADDR_CR_BASE0_CR_BASE0_MASK)
/*! @} */

/*! @name CMD_SET_FB_ADDR_FBC_Y_OFFSET0 - Compressed luma offset base address of DPB index 0 */
/*! @{ */

#define VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_Y_OFFSET0_FBC_LUMA_OFFSET_BASE0_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_Y_OFFSET0_FBC_LUMA_OFFSET_BASE0_SHIFT (0U)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_Y_OFFSET0_FBC_LUMA_OFFSET_BASE0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_Y_OFFSET0_FBC_LUMA_OFFSET_BASE0_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_Y_OFFSET0_FBC_LUMA_OFFSET_BASE0_MASK)
/*! @} */

/*! @name RET_QUERY_BW_SEC_AXI_WRITE - Secondary AXI write bandwidth */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_BW_SEC_AXI_WRITE_BW_SEC_AXI_WRITE_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_QUERY_BW_SEC_AXI_WRITE_BW_SEC_AXI_WRITE_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_BW_SEC_AXI_WRITE_BW_SEC_AXI_WRITE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_BW_SEC_AXI_WRITE_BW_SEC_AXI_WRITE_SHIFT)) & VPU_VPU_DEC_RET_QUERY_BW_SEC_AXI_WRITE_BW_SEC_AXI_WRITE_MASK)
/*! @} */

/*! @name RET_QUERY_DEC_NUM_REORDER_DELAY - Reorder frame number */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_DEC_NUM_REORDER_DELAY_REORDER_DELAY_NUM_MASK (0x1FU)
#define VPU_VPU_DEC_RET_QUERY_DEC_NUM_REORDER_DELAY_REORDER_DELAY_NUM_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_DEC_NUM_REORDER_DELAY_REORDER_DELAY_NUM(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_NUM_REORDER_DELAY_REORDER_DELAY_NUM_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_NUM_REORDER_DELAY_REORDER_DELAY_NUM_MASK)
/*! @} */

/*! @name RET_QUERY_PF_STG_1_BLOCK_END - Blocking end tick of stage 1 */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_PF_STG_1_BLOCK_END_PF_STAGE_1_BLOCK_END_TICK_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_QUERY_PF_STG_1_BLOCK_END_PF_STAGE_1_BLOCK_END_TICK_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_PF_STG_1_BLOCK_END_PF_STAGE_1_BLOCK_END_TICK(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_PF_STG_1_BLOCK_END_PF_STAGE_1_BLOCK_END_TICK_SHIFT)) & VPU_VPU_DEC_RET_QUERY_PF_STG_1_BLOCK_END_PF_STAGE_1_BLOCK_END_TICK_MASK)
/*! @} */

/*! @name RET_QUERY_PRODUCT_ID - The product ID */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_PRODUCT_ID_PRODUCT_ID_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_QUERY_PRODUCT_ID_PRODUCT_ID_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_PRODUCT_ID_PRODUCT_ID(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_PRODUCT_ID_PRODUCT_ID_SHIFT)) & VPU_VPU_DEC_RET_QUERY_PRODUCT_ID_PRODUCT_ID_MASK)
/*! @} */

/*! @name CMD_SET_FB_ADDR_FBC_C_OFFSET0 - Compressed chroma offset base address of DPB index 0 */
/*! @{ */

#define VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_C_OFFSET0_FBC_CHROMA_OFFSET_BASE0_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_C_OFFSET0_FBC_CHROMA_OFFSET_BASE0_SHIFT (0U)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_C_OFFSET0_FBC_CHROMA_OFFSET_BASE0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_C_OFFSET0_FBC_CHROMA_OFFSET_BASE0_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_C_OFFSET0_FBC_CHROMA_OFFSET_BASE0_MASK)
/*! @} */

/*! @name CMD_SET_FB_ADDR_MV_COL - Colocated mv buffer base of MvCol idx to be update */
/*! @{ */

#define VPU_VPU_DEC_CMD_SET_FB_ADDR_MV_COL_COL_MV_BUF_BASE0_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_MV_COL_COL_MV_BUF_BASE0_SHIFT (0U)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_MV_COL_COL_MV_BUF_BASE0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_ADDR_MV_COL_COL_MV_BUF_BASE0_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_ADDR_MV_COL_COL_MV_BUF_BASE0_MASK)
/*! @} */

/*! @name RET_QUERY_BW_PROC_AXI_READ - Proc AXI read bandwidth */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_BW_PROC_AXI_READ_BW_PROC_AXI_READ_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_QUERY_BW_PROC_AXI_READ_BW_PROC_AXI_READ_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_BW_PROC_AXI_READ_BW_PROC_AXI_READ(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_BW_PROC_AXI_READ_BW_PROC_AXI_READ_SHIFT)) & VPU_VPU_DEC_RET_QUERY_BW_PROC_AXI_READ_BW_PROC_AXI_READ_MASK)
/*! @} */

/*! @name RET_QUERY_CUSTOMER_ID - The customer ID */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_CUSTOMER_ID_CUSTOMER_ID_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_QUERY_CUSTOMER_ID_CUSTOMER_ID_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_CUSTOMER_ID_CUSTOMER_ID(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_CUSTOMER_ID_CUSTOMER_ID_SHIFT)) & VPU_VPU_DEC_RET_QUERY_CUSTOMER_ID_CUSTOMER_ID_MASK)
/*! @} */

/*! @name RET_QUERY_DEC_SUB_LAYER_INFO - Sub-layer information */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_DEC_SUB_LAYER_INFO_TEMPORAL_ID_MASK (0xFFU)
#define VPU_VPU_DEC_RET_QUERY_DEC_SUB_LAYER_INFO_TEMPORAL_ID_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_DEC_SUB_LAYER_INFO_TEMPORAL_ID(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_SUB_LAYER_INFO_TEMPORAL_ID_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_SUB_LAYER_INFO_TEMPORAL_ID_MASK)

#define VPU_VPU_DEC_RET_QUERY_DEC_SUB_LAYER_INFO_MAX_TEMPORAL_ID_MASK (0xFF00U)
#define VPU_VPU_DEC_RET_QUERY_DEC_SUB_LAYER_INFO_MAX_TEMPORAL_ID_SHIFT (8U)
#define VPU_VPU_DEC_RET_QUERY_DEC_SUB_LAYER_INFO_MAX_TEMPORAL_ID(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_SUB_LAYER_INFO_MAX_TEMPORAL_ID_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_SUB_LAYER_INFO_MAX_TEMPORAL_ID_MASK)

#define VPU_VPU_DEC_RET_QUERY_DEC_SUB_LAYER_INFO_SPATIAL_SVC_FLAG_MASK (0x10000U)
#define VPU_VPU_DEC_RET_QUERY_DEC_SUB_LAYER_INFO_SPATIAL_SVC_FLAG_SHIFT (16U)
#define VPU_VPU_DEC_RET_QUERY_DEC_SUB_LAYER_INFO_SPATIAL_SVC_FLAG(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_SUB_LAYER_INFO_SPATIAL_SVC_FLAG_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_SUB_LAYER_INFO_SPATIAL_SVC_FLAG_MASK)

#define VPU_VPU_DEC_RET_QUERY_DEC_SUB_LAYER_INFO_SPATIAL_SVC_MODE_MASK (0x20000U)
#define VPU_VPU_DEC_RET_QUERY_DEC_SUB_LAYER_INFO_SPATIAL_SVC_MODE_SHIFT (17U)
#define VPU_VPU_DEC_RET_QUERY_DEC_SUB_LAYER_INFO_SPATIAL_SVC_MODE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_SUB_LAYER_INFO_SPATIAL_SVC_MODE_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_SUB_LAYER_INFO_SPATIAL_SVC_MODE_MASK)

#define VPU_VPU_DEC_RET_QUERY_DEC_SUB_LAYER_INFO_SPATIAL_SVC_LAYER_MASK (0x40000U)
#define VPU_VPU_DEC_RET_QUERY_DEC_SUB_LAYER_INFO_SPATIAL_SVC_LAYER_SHIFT (18U)
#define VPU_VPU_DEC_RET_QUERY_DEC_SUB_LAYER_INFO_SPATIAL_SVC_LAYER(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_SUB_LAYER_INFO_SPATIAL_SVC_LAYER_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_SUB_LAYER_INFO_SPATIAL_SVC_LAYER_MASK)

#define VPU_VPU_DEC_RET_QUERY_DEC_SUB_LAYER_INFO_SPATIAL_ID_MASK (0x180000U)
#define VPU_VPU_DEC_RET_QUERY_DEC_SUB_LAYER_INFO_SPATIAL_ID_SHIFT (19U)
#define VPU_VPU_DEC_RET_QUERY_DEC_SUB_LAYER_INFO_SPATIAL_ID(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_SUB_LAYER_INFO_SPATIAL_ID_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_SUB_LAYER_INFO_SPATIAL_ID_MASK)

#define VPU_VPU_DEC_RET_QUERY_DEC_SUB_LAYER_INFO_MAX_SPATIAL_ID_MASK (0x3000000U)
#define VPU_VPU_DEC_RET_QUERY_DEC_SUB_LAYER_INFO_MAX_SPATIAL_ID_SHIFT (24U)
#define VPU_VPU_DEC_RET_QUERY_DEC_SUB_LAYER_INFO_MAX_SPATIAL_ID(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_SUB_LAYER_INFO_MAX_SPATIAL_ID_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_SUB_LAYER_INFO_MAX_SPATIAL_ID_MASK)
/*! @} */

/*! @name RET_QUERY_PF_STG_2_START - Start tick of stage 2 */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_PF_STG_2_START_PF_STAGE_2_START_TICK_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_QUERY_PF_STG_2_START_PF_STAGE_2_START_TICK_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_PF_STG_2_START_PF_STAGE_2_START_TICK(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_PF_STG_2_START_PF_STAGE_2_START_TICK_SHIFT)) & VPU_VPU_DEC_RET_QUERY_PF_STG_2_START_PF_STAGE_2_START_TICK_MASK)
/*! @} */

/*! @name CMD_SET_FB_ADDR_FBC_Y_BASE - FBC luma base of FBC idx to be update */
/*! @{ */

#define VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_Y_BASE_FBC_LUMA_BASE_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_Y_BASE_FBC_LUMA_BASE_SHIFT (0U)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_Y_BASE_FBC_LUMA_BASE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_Y_BASE_FBC_LUMA_BASE_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_Y_BASE_FBC_LUMA_BASE_MASK)
/*! @} */

/*! @name CMD_SET_FB_ADDR_LUMA_BASE1 - Luma base address of DPB index 1 */
/*! @{ */

#define VPU_VPU_DEC_CMD_SET_FB_ADDR_LUMA_BASE1_LUMA_BASE1_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_LUMA_BASE1_LUMA_BASE1_SHIFT (0U)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_LUMA_BASE1_LUMA_BASE1(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_ADDR_LUMA_BASE1_LUMA_BASE1_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_ADDR_LUMA_BASE1_LUMA_BASE1_MASK)
/*! @} */

/*! @name RET_QUERY_BW_PROC_AXI_WRITE - Proc AXI write bandwidth */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_BW_PROC_AXI_WRITE_BW_PROC_AXI_WRITE_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_QUERY_BW_PROC_AXI_WRITE_BW_PROC_AXI_WRITE_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_BW_PROC_AXI_WRITE_BW_PROC_AXI_WRITE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_BW_PROC_AXI_WRITE_BW_PROC_AXI_WRITE_SHIFT)) & VPU_VPU_DEC_RET_QUERY_BW_PROC_AXI_WRITE_BW_PROC_AXI_WRITE_MASK)
/*! @} */

/*! @name RET_QUERY_DEC_NOTIFICATION - Sequence change flag */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_DEC_NOTIFICATION_RSVD2_MASK (0x1FU)
#define VPU_VPU_DEC_RET_QUERY_DEC_NOTIFICATION_RSVD2_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_DEC_NOTIFICATION_RSVD2(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_NOTIFICATION_RSVD2_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_NOTIFICATION_RSVD2_MASK)

#define VPU_VPU_DEC_RET_QUERY_DEC_NOTIFICATION_NOTI_FLAG_PROFILE_MASK (0x20U)
#define VPU_VPU_DEC_RET_QUERY_DEC_NOTIFICATION_NOTI_FLAG_PROFILE_SHIFT (5U)
#define VPU_VPU_DEC_RET_QUERY_DEC_NOTIFICATION_NOTI_FLAG_PROFILE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_NOTIFICATION_NOTI_FLAG_PROFILE_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_NOTIFICATION_NOTI_FLAG_PROFILE_MASK)

#define VPU_VPU_DEC_RET_QUERY_DEC_NOTIFICATION_RSVD1_MASK (0x7FC0U)
#define VPU_VPU_DEC_RET_QUERY_DEC_NOTIFICATION_RSVD1_SHIFT (6U)
#define VPU_VPU_DEC_RET_QUERY_DEC_NOTIFICATION_RSVD1(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_NOTIFICATION_RSVD1_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_NOTIFICATION_RSVD1_MASK)

#define VPU_VPU_DEC_RET_QUERY_DEC_NOTIFICATION_NOTI_FLAG_CHROMA_FORMAT_CHANGE_MASK (0x8000U)
#define VPU_VPU_DEC_RET_QUERY_DEC_NOTIFICATION_NOTI_FLAG_CHROMA_FORMAT_CHANGE_SHIFT (15U)
#define VPU_VPU_DEC_RET_QUERY_DEC_NOTIFICATION_NOTI_FLAG_CHROMA_FORMAT_CHANGE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_NOTIFICATION_NOTI_FLAG_CHROMA_FORMAT_CHANGE_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_NOTIFICATION_NOTI_FLAG_CHROMA_FORMAT_CHANGE_MASK)

#define VPU_VPU_DEC_RET_QUERY_DEC_NOTIFICATION_NOTI_FLAG_SIZE_MASK (0x10000U)
#define VPU_VPU_DEC_RET_QUERY_DEC_NOTIFICATION_NOTI_FLAG_SIZE_SHIFT (16U)
#define VPU_VPU_DEC_RET_QUERY_DEC_NOTIFICATION_NOTI_FLAG_SIZE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_NOTIFICATION_NOTI_FLAG_SIZE_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_NOTIFICATION_NOTI_FLAG_SIZE_MASK)

#define VPU_VPU_DEC_RET_QUERY_DEC_NOTIFICATION_NOTI_FLAG_INTER_RES_CHANGE_MASK (0x20000U)
#define VPU_VPU_DEC_RET_QUERY_DEC_NOTIFICATION_NOTI_FLAG_INTER_RES_CHANGE_SHIFT (17U)
#define VPU_VPU_DEC_RET_QUERY_DEC_NOTIFICATION_NOTI_FLAG_INTER_RES_CHANGE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_NOTIFICATION_NOTI_FLAG_INTER_RES_CHANGE_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_NOTIFICATION_NOTI_FLAG_INTER_RES_CHANGE_MASK)

#define VPU_VPU_DEC_RET_QUERY_DEC_NOTIFICATION_NOTI_FLAG_BITDEPTH_MASK (0x40000U)
#define VPU_VPU_DEC_RET_QUERY_DEC_NOTIFICATION_NOTI_FLAG_BITDEPTH_SHIFT (18U)
#define VPU_VPU_DEC_RET_QUERY_DEC_NOTIFICATION_NOTI_FLAG_BITDEPTH(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_NOTIFICATION_NOTI_FLAG_BITDEPTH_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_NOTIFICATION_NOTI_FLAG_BITDEPTH_MASK)

#define VPU_VPU_DEC_RET_QUERY_DEC_NOTIFICATION_NOTI_FLAG_DPB_COUNT_MASK (0x80000U)
#define VPU_VPU_DEC_RET_QUERY_DEC_NOTIFICATION_NOTI_FLAG_DPB_COUNT_SHIFT (19U)
#define VPU_VPU_DEC_RET_QUERY_DEC_NOTIFICATION_NOTI_FLAG_DPB_COUNT(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_NOTIFICATION_NOTI_FLAG_DPB_COUNT_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_NOTIFICATION_NOTI_FLAG_DPB_COUNT_MASK)

#define VPU_VPU_DEC_RET_QUERY_DEC_NOTIFICATION_RSVD0_MASK (0xFFF00000U)
#define VPU_VPU_DEC_RET_QUERY_DEC_NOTIFICATION_RSVD0_SHIFT (20U)
#define VPU_VPU_DEC_RET_QUERY_DEC_NOTIFICATION_RSVD0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_NOTIFICATION_RSVD0_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_NOTIFICATION_RSVD0_MASK)
/*! @} */

/*! @name RET_QUERY_PF_STG_2_END - End tick of stage 2 */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_PF_STG_2_END_PF_STAGE_2_END_TICK_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_QUERY_PF_STG_2_END_PF_STAGE_2_END_TICK_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_PF_STG_2_END_PF_STAGE_2_END_TICK(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_PF_STG_2_END_PF_STAGE_2_END_TICK_SHIFT)) & VPU_VPU_DEC_RET_QUERY_PF_STG_2_END_PF_STAGE_2_END_TICK_MASK)
/*! @} */

/*! @name CMD_SET_FB_ADDR_CB_BASE1 - Cb base address of DPB index 1 */
/*! @{ */

#define VPU_VPU_DEC_CMD_SET_FB_ADDR_CB_BASE1_CB_BASE1_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_CB_BASE1_CB_BASE1_SHIFT (0U)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_CB_BASE1_CB_BASE1(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_ADDR_CB_BASE1_CB_BASE1_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_ADDR_CB_BASE1_CB_BASE1_MASK)
/*! @} */

/*! @name CMD_SET_FB_ADDR_FBC_C_BASE - FBC chroma base of FBC idx to be update */
/*! @{ */

#define VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_C_BASE_FBC_CHROMA_BASE_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_C_BASE_FBC_CHROMA_BASE_SHIFT (0U)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_C_BASE_FBC_CHROMA_BASE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_C_BASE_FBC_CHROMA_BASE_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_C_BASE_FBC_CHROMA_BASE_MASK)
/*! @} */

/*! @name RET_QUERY_BW_BWB_AXI_WRITE - BWB AXI write bandwidth */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_BW_BWB_AXI_WRITE_BW_BWB_AXI_WRITE_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_QUERY_BW_BWB_AXI_WRITE_BW_BWB_AXI_WRITE_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_BW_BWB_AXI_WRITE_BW_BWB_AXI_WRITE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_BW_BWB_AXI_WRITE_BW_BWB_AXI_WRITE_SHIFT)) & VPU_VPU_DEC_RET_QUERY_BW_BWB_AXI_WRITE_BW_BWB_AXI_WRITE_MASK)
/*! @} */

/*! @name RET_QUERY_DEC_USERDATA_IDC - User data flag */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_RSVD21_MASK (0x1U)
#define VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_RSVD21_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_RSVD21(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_RSVD21_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_RSVD21_MASK)

#define VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG20_MASK (0x2U)
#define VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG20_SHIFT (1U)
#define VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG20(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG20_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG20_MASK)

#define VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG19_MASK (0x4U)
#define VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG19_SHIFT (2U)
#define VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG19(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG19_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG19_MASK)

#define VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_RSVD18_MASK (0x8U)
#define VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_RSVD18_SHIFT (3U)
#define VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_RSVD18(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_RSVD18_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_RSVD18_MASK)

#define VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG17_MASK (0x10U)
#define VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG17_SHIFT (4U)
#define VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG17(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG17_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG17_MASK)

#define VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG16_MASK (0x20U)
#define VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG16_SHIFT (5U)
#define VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG16(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG16_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG16_MASK)

#define VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG15_MASK (0x40U)
#define VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG15_SHIFT (6U)
#define VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG15(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG15_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG15_MASK)

#define VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG14_MASK (0x80U)
#define VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG14_SHIFT (7U)
#define VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG14(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG14_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG14_MASK)

#define VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG13_MASK (0x100U)
#define VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG13_SHIFT (8U)
#define VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG13(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG13_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG13_MASK)

#define VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_RSVD12_MASK (0x200U)
#define VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_RSVD12_SHIFT (9U)
#define VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_RSVD12(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_RSVD12_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_RSVD12_MASK)

#define VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG11_MASK (0x400U)
#define VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG11_SHIFT (10U)
#define VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG11(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG11_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG11_MASK)

#define VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG10_MASK (0x800U)
#define VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG10_SHIFT (11U)
#define VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG10(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG10_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG10_MASK)

#define VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG9_MASK (0x1000U)
#define VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG9_SHIFT (12U)
#define VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG9(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG9_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG9_MASK)

#define VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG8_MASK (0x2000U)
#define VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG8_SHIFT (13U)
#define VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG8(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG8_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG8_MASK)

#define VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG7_MASK (0x4000U)
#define VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG7_SHIFT (14U)
#define VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG7(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG7_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG7_MASK)

#define VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG6_MASK (0x8000U)
#define VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG6_SHIFT (15U)
#define VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG6(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG6_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG6_MASK)

#define VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG5_MASK (0x10000U)
#define VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG5_SHIFT (16U)
#define VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG5(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG5_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG5_MASK)

#define VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG4_MASK (0xFFE0000U)
#define VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG4_SHIFT (17U)
#define VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG4(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG4_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG4_MASK)

#define VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG3_MASK (0x10000000U)
#define VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG3_SHIFT (28U)
#define VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG3(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG3_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG3_MASK)

#define VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG2_MASK (0x20000000U)
#define VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG2_SHIFT (29U)
#define VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG2(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG2_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG2_MASK)

#define VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG1_MASK (0x40000000U)
#define VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG1_SHIFT (30U)
#define VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG1(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG1_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG1_MASK)

#define VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG0_MASK (0x80000000U)
#define VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG0_SHIFT (31U)
#define VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG0_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_USERDATA_IDC_USERDATA_FLAG0_MASK)
/*! @} */

/*! @name RET_QUERY_PF_STG_2_BLOCK_START - Blocking start tick of stage 2 */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_PF_STG_2_BLOCK_START_PF_STAGE_2_BLOCK_START_TICK_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_QUERY_PF_STG_2_BLOCK_START_PF_STAGE_2_BLOCK_START_TICK_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_PF_STG_2_BLOCK_START_PF_STAGE_2_BLOCK_START_TICK(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_PF_STG_2_BLOCK_START_PF_STAGE_2_BLOCK_START_TICK_SHIFT)) & VPU_VPU_DEC_RET_QUERY_PF_STG_2_BLOCK_START_PF_STAGE_2_BLOCK_START_TICK_MASK)
/*! @} */

/*! @name CMD_QUERY_BW_OPTION - bandwidth selection */
/*! @{ */

#define VPU_VPU_DEC_CMD_QUERY_BW_OPTION_BW_QUERY_BL_SEL_MASK (0xFU)
#define VPU_VPU_DEC_CMD_QUERY_BW_OPTION_BW_QUERY_BL_SEL_SHIFT (0U)
#define VPU_VPU_DEC_CMD_QUERY_BW_OPTION_BW_QUERY_BL_SEL(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_QUERY_BW_OPTION_BW_QUERY_BL_SEL_SHIFT)) & VPU_VPU_DEC_CMD_QUERY_BW_OPTION_BW_QUERY_BL_SEL_MASK)

#define VPU_VPU_DEC_CMD_QUERY_BW_OPTION_BW_QUERY_BW_SEL_MASK (0x10U)
#define VPU_VPU_DEC_CMD_QUERY_BW_OPTION_BW_QUERY_BW_SEL_SHIFT (4U)
#define VPU_VPU_DEC_CMD_QUERY_BW_OPTION_BW_QUERY_BW_SEL(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_QUERY_BW_OPTION_BW_QUERY_BW_SEL_SHIFT)) & VPU_VPU_DEC_CMD_QUERY_BW_OPTION_BW_QUERY_BW_SEL_MASK)
/*! @} */

/*! @name CMD_SET_FB_ADDR_CR_BASE1 - Cr base address of DPB index 1 */
/*! @{ */

#define VPU_VPU_DEC_CMD_SET_FB_ADDR_CR_BASE1_CR_BASE1_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_CR_BASE1_CR_BASE1_SHIFT (0U)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_CR_BASE1_CR_BASE1(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_ADDR_CR_BASE1_CR_BASE1_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_ADDR_CR_BASE1_CR_BASE1_MASK)
/*! @} */

/*! @name CMD_SET_FB_ADDR_FBC_Y_OFFSET - FBC luma offset base of FBC idx to be update */
/*! @{ */

#define VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_Y_OFFSET_FBC_LUMA_OFFSET_BASE_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_Y_OFFSET_FBC_LUMA_OFFSET_BASE_SHIFT (0U)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_Y_OFFSET_FBC_LUMA_OFFSET_BASE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_Y_OFFSET_FBC_LUMA_OFFSET_BASE_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_Y_OFFSET_FBC_LUMA_OFFSET_BASE_MASK)
/*! @} */

/*! @name CMD_SET_FB_ADDR_FBC_Y_OFFSET1 - Compressed luma offset base address of DPB index 1 */
/*! @{ */

#define VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_Y_OFFSET1_FBC_LUMA_OFFSET_BASE1_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_Y_OFFSET1_FBC_LUMA_OFFSET_BASE1_SHIFT (0U)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_Y_OFFSET1_FBC_LUMA_OFFSET_BASE1(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_Y_OFFSET1_FBC_LUMA_OFFSET_BASE1_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_Y_OFFSET1_FBC_LUMA_OFFSET_BASE1_MASK)
/*! @} */

/*! @name RET_QUERY_DEC_PIC_SIZE - Decoded Picture Size */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_DEC_PIC_SIZE_DECODED_PIC_HEIGHT_MASK (0xFFFFU)
#define VPU_VPU_DEC_RET_QUERY_DEC_PIC_SIZE_DECODED_PIC_HEIGHT_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_DEC_PIC_SIZE_DECODED_PIC_HEIGHT(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_PIC_SIZE_DECODED_PIC_HEIGHT_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_PIC_SIZE_DECODED_PIC_HEIGHT_MASK)

#define VPU_VPU_DEC_RET_QUERY_DEC_PIC_SIZE_DECODED_PIC_WIDTH_MASK (0xFFFF0000U)
#define VPU_VPU_DEC_RET_QUERY_DEC_PIC_SIZE_DECODED_PIC_WIDTH_SHIFT (16U)
#define VPU_VPU_DEC_RET_QUERY_DEC_PIC_SIZE_DECODED_PIC_WIDTH(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_PIC_SIZE_DECODED_PIC_WIDTH_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_PIC_SIZE_DECODED_PIC_WIDTH_MASK)
/*! @} */

/*! @name RET_QUERY_PF_STG_2_BLOCK_END - Blocking end tick of stage 2 */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_PF_STG_2_BLOCK_END_PF_STAGE_2_BLOCK_END_TICK_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_QUERY_PF_STG_2_BLOCK_END_PF_STAGE_2_BLOCK_END_TICK_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_PF_STG_2_BLOCK_END_PF_STAGE_2_BLOCK_END_TICK(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_PF_STG_2_BLOCK_END_PF_STAGE_2_BLOCK_END_TICK_SHIFT)) & VPU_VPU_DEC_RET_QUERY_PF_STG_2_BLOCK_END_PF_STAGE_2_BLOCK_END_TICK_MASK)
/*! @} */

/*! @name CMD_DEC_USE_SEC_AXI - Secondary AXI Usage */
/*! @{ */

#define VPU_VPU_DEC_CMD_DEC_USE_SEC_AXI_SEC_AXI_BPU_MASK (0x1U)
#define VPU_VPU_DEC_CMD_DEC_USE_SEC_AXI_SEC_AXI_BPU_SHIFT (0U)
#define VPU_VPU_DEC_CMD_DEC_USE_SEC_AXI_SEC_AXI_BPU(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_DEC_USE_SEC_AXI_SEC_AXI_BPU_SHIFT)) & VPU_VPU_DEC_CMD_DEC_USE_SEC_AXI_SEC_AXI_BPU_MASK)

#define VPU_VPU_DEC_CMD_DEC_USE_SEC_AXI_SEC_AXI_SCL_MASK (0x20U)
#define VPU_VPU_DEC_CMD_DEC_USE_SEC_AXI_SEC_AXI_SCL_SHIFT (5U)
#define VPU_VPU_DEC_CMD_DEC_USE_SEC_AXI_SEC_AXI_SCL(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_DEC_USE_SEC_AXI_SEC_AXI_SCL_SHIFT)) & VPU_VPU_DEC_CMD_DEC_USE_SEC_AXI_SEC_AXI_SCL_MASK)

#define VPU_VPU_DEC_CMD_DEC_USE_SEC_AXI_SEC_AXI_SCL_PACKED_MASK (0x40U)
#define VPU_VPU_DEC_CMD_DEC_USE_SEC_AXI_SEC_AXI_SCL_PACKED_SHIFT (6U)
#define VPU_VPU_DEC_CMD_DEC_USE_SEC_AXI_SEC_AXI_SCL_PACKED(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_DEC_USE_SEC_AXI_SEC_AXI_SCL_PACKED_SHIFT)) & VPU_VPU_DEC_CMD_DEC_USE_SEC_AXI_SEC_AXI_SCL_PACKED_MASK)

#define VPU_VPU_DEC_CMD_DEC_USE_SEC_AXI_SEC_AXI_VCE_IP_MASK (0x200U)
#define VPU_VPU_DEC_CMD_DEC_USE_SEC_AXI_SEC_AXI_VCE_IP_SHIFT (9U)
#define VPU_VPU_DEC_CMD_DEC_USE_SEC_AXI_SEC_AXI_VCE_IP(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_DEC_USE_SEC_AXI_SEC_AXI_VCE_IP_SHIFT)) & VPU_VPU_DEC_CMD_DEC_USE_SEC_AXI_SEC_AXI_VCE_IP_MASK)

#define VPU_VPU_DEC_CMD_DEC_USE_SEC_AXI_RSVD0_MASK (0x7C00U)
#define VPU_VPU_DEC_CMD_DEC_USE_SEC_AXI_RSVD0_SHIFT (10U)
#define VPU_VPU_DEC_CMD_DEC_USE_SEC_AXI_RSVD0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_DEC_USE_SEC_AXI_RSVD0_SHIFT)) & VPU_VPU_DEC_CMD_DEC_USE_SEC_AXI_RSVD0_MASK)

#define VPU_VPU_DEC_CMD_DEC_USE_SEC_AXI_SEC_AXI_VCE_LF_MASK (0x8000U)
#define VPU_VPU_DEC_CMD_DEC_USE_SEC_AXI_SEC_AXI_VCE_LF_SHIFT (15U)
#define VPU_VPU_DEC_CMD_DEC_USE_SEC_AXI_SEC_AXI_VCE_LF(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_DEC_USE_SEC_AXI_SEC_AXI_VCE_LF_SHIFT)) & VPU_VPU_DEC_CMD_DEC_USE_SEC_AXI_SEC_AXI_VCE_LF_MASK)
/*! @} */

/*! @name CMD_SET_FB_ADDR_FBC_C_OFFSET - FBC chroma offset base of FBC idx to be update */
/*! @{ */

#define VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_C_OFFSET_FBC_CHROMA_OFFSET_BASE_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_C_OFFSET_FBC_CHROMA_OFFSET_BASE_SHIFT (0U)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_C_OFFSET_FBC_CHROMA_OFFSET_BASE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_C_OFFSET_FBC_CHROMA_OFFSET_BASE_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_C_OFFSET_FBC_CHROMA_OFFSET_BASE_MASK)
/*! @} */

/*! @name CMD_SET_FB_ADDR_FBC_C_OFFSET1 - Compressed chroma offset base address of DPB index 1 */
/*! @{ */

#define VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_C_OFFSET1_FBC_CHROMA_OFFSET_BASE1_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_C_OFFSET1_FBC_CHROMA_OFFSET_BASE1_SHIFT (0U)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_C_OFFSET1_FBC_CHROMA_OFFSET_BASE1(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_C_OFFSET1_FBC_CHROMA_OFFSET_BASE1_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_C_OFFSET1_FBC_CHROMA_OFFSET_BASE1_MASK)
/*! @} */

/*! @name RET_QUERY_DEC_CROP_TOP_BOTTOM - Display Crop Offset Top/Bottom */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_DEC_CROP_TOP_BOTTOM_DISPLAY_BOTTOM_OFFSET_MASK (0xFFFFU)
#define VPU_VPU_DEC_RET_QUERY_DEC_CROP_TOP_BOTTOM_DISPLAY_BOTTOM_OFFSET_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_DEC_CROP_TOP_BOTTOM_DISPLAY_BOTTOM_OFFSET(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_CROP_TOP_BOTTOM_DISPLAY_BOTTOM_OFFSET_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_CROP_TOP_BOTTOM_DISPLAY_BOTTOM_OFFSET_MASK)

#define VPU_VPU_DEC_RET_QUERY_DEC_CROP_TOP_BOTTOM_DISPLAY_TOP_OFFSET_MASK (0xFFFF0000U)
#define VPU_VPU_DEC_RET_QUERY_DEC_CROP_TOP_BOTTOM_DISPLAY_TOP_OFFSET_SHIFT (16U)
#define VPU_VPU_DEC_RET_QUERY_DEC_CROP_TOP_BOTTOM_DISPLAY_TOP_OFFSET(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_CROP_TOP_BOTTOM_DISPLAY_TOP_OFFSET_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_CROP_TOP_BOTTOM_DISPLAY_TOP_OFFSET_MASK)
/*! @} */

/*! @name RET_QUERY_PF_STG_0_BLOCK_TICK - Blocking tick of stage 0 */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_PF_STG_0_BLOCK_TICK_PF_STAGE_0_BLOCK_TICK_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_QUERY_PF_STG_0_BLOCK_TICK_PF_STAGE_0_BLOCK_TICK_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_PF_STG_0_BLOCK_TICK_PF_STAGE_0_BLOCK_TICK(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_PF_STG_0_BLOCK_TICK_PF_STAGE_0_BLOCK_TICK_SHIFT)) & VPU_VPU_DEC_RET_QUERY_PF_STG_0_BLOCK_TICK_PF_STAGE_0_BLOCK_TICK_MASK)
/*! @} */

/*! @name CMD_DEC_SCALE_SIZE - Scaled picture size */
/*! @{ */

#define VPU_VPU_DEC_CMD_DEC_SCALE_SIZE_SCALED_HEIGHT_MASK (0xFFFFU)
#define VPU_VPU_DEC_CMD_DEC_SCALE_SIZE_SCALED_HEIGHT_SHIFT (0U)
#define VPU_VPU_DEC_CMD_DEC_SCALE_SIZE_SCALED_HEIGHT(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_DEC_SCALE_SIZE_SCALED_HEIGHT_SHIFT)) & VPU_VPU_DEC_CMD_DEC_SCALE_SIZE_SCALED_HEIGHT_MASK)

#define VPU_VPU_DEC_CMD_DEC_SCALE_SIZE_SCALED_WIDTH_MASK (0xFFFF0000U)
#define VPU_VPU_DEC_CMD_DEC_SCALE_SIZE_SCALED_WIDTH_SHIFT (16U)
#define VPU_VPU_DEC_CMD_DEC_SCALE_SIZE_SCALED_WIDTH(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_DEC_SCALE_SIZE_SCALED_WIDTH_SHIFT)) & VPU_VPU_DEC_CMD_DEC_SCALE_SIZE_SCALED_WIDTH_MASK)
/*! @} */

/*! @name CMD_SET_FB_ADDR_LUMA_BASE2 - Luma base address of DPB index 2 */
/*! @{ */

#define VPU_VPU_DEC_CMD_SET_FB_ADDR_LUMA_BASE2_LUMA_BASE2_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_LUMA_BASE2_LUMA_BASE2_SHIFT (0U)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_LUMA_BASE2_LUMA_BASE2(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_ADDR_LUMA_BASE2_LUMA_BASE2_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_ADDR_LUMA_BASE2_LUMA_BASE2_MASK)
/*! @} */

/*! @name RET_QUERY_DEC_CROP_LEFT_RIGHT - Display Crop Offset Left/Right */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_DEC_CROP_LEFT_RIGHT_DISPLAY_RIGHT_OFFSET_MASK (0xFFFFU)
#define VPU_VPU_DEC_RET_QUERY_DEC_CROP_LEFT_RIGHT_DISPLAY_RIGHT_OFFSET_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_DEC_CROP_LEFT_RIGHT_DISPLAY_RIGHT_OFFSET(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_CROP_LEFT_RIGHT_DISPLAY_RIGHT_OFFSET_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_CROP_LEFT_RIGHT_DISPLAY_RIGHT_OFFSET_MASK)

#define VPU_VPU_DEC_RET_QUERY_DEC_CROP_LEFT_RIGHT_DISPLAY_LEFT_OFFSET_MASK (0xFFFF0000U)
#define VPU_VPU_DEC_RET_QUERY_DEC_CROP_LEFT_RIGHT_DISPLAY_LEFT_OFFSET_SHIFT (16U)
#define VPU_VPU_DEC_RET_QUERY_DEC_CROP_LEFT_RIGHT_DISPLAY_LEFT_OFFSET(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_CROP_LEFT_RIGHT_DISPLAY_LEFT_OFFSET_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_CROP_LEFT_RIGHT_DISPLAY_LEFT_OFFSET_MASK)
/*! @} */

/*! @name RET_QUERY_PF_STG_1_BLOCK_TICK - Blocking tick of stage 1 */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_PF_STG_1_BLOCK_TICK_PF_STAGE_1_BLOCK_TICK_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_QUERY_PF_STG_1_BLOCK_TICK_PF_STAGE_1_BLOCK_TICK_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_PF_STG_1_BLOCK_TICK_PF_STAGE_1_BLOCK_TICK(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_PF_STG_1_BLOCK_TICK_PF_STAGE_1_BLOCK_TICK_SHIFT)) & VPU_VPU_DEC_RET_QUERY_PF_STG_1_BLOCK_TICK_PF_STAGE_1_BLOCK_TICK_MASK)
/*! @} */

/*! @name CMD_SET_FB_ADDR_CB_BASE2 - Cb base address of DPB index 2 */
/*! @{ */

#define VPU_VPU_DEC_CMD_SET_FB_ADDR_CB_BASE2_CB_BASE2_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_CB_BASE2_CB_BASE2_SHIFT (0U)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_CB_BASE2_CB_BASE2(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_ADDR_CB_BASE2_CB_BASE2_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_ADDR_CB_BASE2_CB_BASE2_MASK)
/*! @} */

/*! @name RET_QUERY_DEC_AU_START_POS - AU Bitstream Start Position */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_DEC_AU_START_POS_AU_START_POS_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_QUERY_DEC_AU_START_POS_AU_START_POS_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_DEC_AU_START_POS_AU_START_POS(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_AU_START_POS_AU_START_POS_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_AU_START_POS_AU_START_POS_MASK)
/*! @} */

/*! @name RET_QUERY_PF_STG_2_BLOCK_TICK - Blocking tick of stage 2 */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_PF_STG_2_BLOCK_TICK_PF_STAGE_2_BLOCK_TICK_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_QUERY_PF_STG_2_BLOCK_TICK_PF_STAGE_2_BLOCK_TICK_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_PF_STG_2_BLOCK_TICK_PF_STAGE_2_BLOCK_TICK(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_PF_STG_2_BLOCK_TICK_PF_STAGE_2_BLOCK_TICK_SHIFT)) & VPU_VPU_DEC_RET_QUERY_PF_STG_2_BLOCK_TICK_PF_STAGE_2_BLOCK_TICK_MASK)
/*! @} */

/*! @name CMD_SET_FB_ADDR_CR_BASE2 - Cr base address of DPB index 2 */
/*! @{ */

#define VPU_VPU_DEC_CMD_SET_FB_ADDR_CR_BASE2_CR_BASE2_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_CR_BASE2_CR_BASE2_SHIFT (0U)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_CR_BASE2_CR_BASE2(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_ADDR_CR_BASE2_CR_BASE2_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_ADDR_CR_BASE2_CR_BASE2_MASK)
/*! @} */

/*! @name CMD_SET_FB_ADDR_FBC_Y_OFFSET2 - Compressed luma offset base address of DPB index 2 */
/*! @{ */

#define VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_Y_OFFSET2_FBC_LUMA_OFFSET_BASE2_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_Y_OFFSET2_FBC_LUMA_OFFSET_BASE2_SHIFT (0U)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_Y_OFFSET2_FBC_LUMA_OFFSET_BASE2(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_Y_OFFSET2_FBC_LUMA_OFFSET_BASE2_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_Y_OFFSET2_FBC_LUMA_OFFSET_BASE2_MASK)
/*! @} */

/*! @name RET_QUERY_DEC_AU_END_POS - AU Bitstream End Position */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_DEC_AU_END_POS_AU_END_POS_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_QUERY_DEC_AU_END_POS_AU_END_POS_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_DEC_AU_END_POS_AU_END_POS(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_AU_END_POS_AU_END_POS_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_AU_END_POS_AU_END_POS_MASK)
/*! @} */

/*! @name RET_QUERY_PF_PIC_DONE_TICK - Pic done interrupt tick */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_PF_PIC_DONE_TICK_PF_PIC_DONE_TICK_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_QUERY_PF_PIC_DONE_TICK_PF_PIC_DONE_TICK_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_PF_PIC_DONE_TICK_PF_PIC_DONE_TICK(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_PF_PIC_DONE_TICK_PF_PIC_DONE_TICK_SHIFT)) & VPU_VPU_DEC_RET_QUERY_PF_PIC_DONE_TICK_PF_PIC_DONE_TICK_MASK)
/*! @} */

/*! @name CMD_SET_FB_ADDR_FBC_C_OFFSET2 - Compressed chroma offset base address of DPB index 2 */
/*! @{ */

#define VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_C_OFFSET2_FBC_CHROMA_OFFSET_BASE2_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_C_OFFSET2_FBC_CHROMA_OFFSET_BASE2_SHIFT (0U)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_C_OFFSET2_FBC_CHROMA_OFFSET_BASE2(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_C_OFFSET2_FBC_CHROMA_OFFSET_BASE2_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_C_OFFSET2_FBC_CHROMA_OFFSET_BASE2_MASK)
/*! @} */

/*! @name RET_QUERY_DEC_PIC_TYPE - Decoded picture type */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_DEC_PIC_TYPE_PIC_TYPE_MASK (0x7U)
#define VPU_VPU_DEC_RET_QUERY_DEC_PIC_TYPE_PIC_TYPE_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_DEC_PIC_TYPE_PIC_TYPE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_PIC_TYPE_PIC_TYPE_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_PIC_TYPE_PIC_TYPE_MASK)

#define VPU_VPU_DEC_RET_QUERY_DEC_PIC_TYPE_RSVD0_MASK (0x8U)
#define VPU_VPU_DEC_RET_QUERY_DEC_PIC_TYPE_RSVD0_SHIFT (3U)
#define VPU_VPU_DEC_RET_QUERY_DEC_PIC_TYPE_RSVD0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_PIC_TYPE_RSVD0_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_PIC_TYPE_RSVD0_MASK)

#define VPU_VPU_DEC_RET_QUERY_DEC_PIC_TYPE_VCL_NAL_UNIT_TYPE_MASK (0x3F0U)
#define VPU_VPU_DEC_RET_QUERY_DEC_PIC_TYPE_VCL_NAL_UNIT_TYPE_SHIFT (4U)
#define VPU_VPU_DEC_RET_QUERY_DEC_PIC_TYPE_VCL_NAL_UNIT_TYPE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_PIC_TYPE_VCL_NAL_UNIT_TYPE_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_PIC_TYPE_VCL_NAL_UNIT_TYPE_MASK)

#define VPU_VPU_DEC_RET_QUERY_DEC_PIC_TYPE_CTU_SIZE_MASK (0xC00U)
#define VPU_VPU_DEC_RET_QUERY_DEC_PIC_TYPE_CTU_SIZE_SHIFT (10U)
#define VPU_VPU_DEC_RET_QUERY_DEC_PIC_TYPE_CTU_SIZE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_PIC_TYPE_CTU_SIZE_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_PIC_TYPE_CTU_SIZE_MASK)

#define VPU_VPU_DEC_RET_QUERY_DEC_PIC_TYPE_REF_PIC_FLAG_MASK (0x40000000U)
#define VPU_VPU_DEC_RET_QUERY_DEC_PIC_TYPE_REF_PIC_FLAG_SHIFT (30U)
#define VPU_VPU_DEC_RET_QUERY_DEC_PIC_TYPE_REF_PIC_FLAG(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_PIC_TYPE_REF_PIC_FLAG_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_PIC_TYPE_REF_PIC_FLAG_MASK)

#define VPU_VPU_DEC_RET_QUERY_DEC_PIC_TYPE_OUTPUT_FLAG_MASK (0x80000000U)
#define VPU_VPU_DEC_RET_QUERY_DEC_PIC_TYPE_OUTPUT_FLAG_SHIFT (31U)
#define VPU_VPU_DEC_RET_QUERY_DEC_PIC_TYPE_OUTPUT_FLAG(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_PIC_TYPE_OUTPUT_FLAG_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_PIC_TYPE_OUTPUT_FLAG_MASK)
/*! @} */

/*! @name CMD_SET_FB_ADDR_LUMA_BASE3 - Luma base address of DPB index 3 */
/*! @{ */

#define VPU_VPU_DEC_CMD_SET_FB_ADDR_LUMA_BASE3_LUMA_BASE3_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_LUMA_BASE3_LUMA_BASE3_SHIFT (0U)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_LUMA_BASE3_LUMA_BASE3(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_ADDR_LUMA_BASE3_LUMA_BASE3_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_ADDR_LUMA_BASE3_LUMA_BASE3_MASK)
/*! @} */

/*! @name RET_QUERY_DEC_PIC_POC - Picture Order Count */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_DEC_PIC_POC_PIC_ORDER_COUNT_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_QUERY_DEC_PIC_POC_PIC_ORDER_COUNT_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_DEC_PIC_POC_PIC_ORDER_COUNT(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_PIC_POC_PIC_ORDER_COUNT_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_PIC_POC_PIC_ORDER_COUNT_MASK)
/*! @} */

/*! @name CMD_SET_FB_ADDR_CB_BASE3 - Cb base address of DPB index 3 */
/*! @{ */

#define VPU_VPU_DEC_CMD_SET_FB_ADDR_CB_BASE3_CB_BASE_FBC_CBCR_BASE3_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_CB_BASE3_CB_BASE_FBC_CBCR_BASE3_SHIFT (0U)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_CB_BASE3_CB_BASE_FBC_CBCR_BASE3(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_ADDR_CB_BASE3_CB_BASE_FBC_CBCR_BASE3_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_ADDR_CB_BASE3_CB_BASE_FBC_CBCR_BASE3_MASK)
/*! @} */

/*! @name RET_QUERY_DEC_RECOVERY_POINT - Recovery point */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_DEC_RECOVERY_POINT_SIGNED_RECOVERY_POC_CNT_MASK (0xFFFFU)
#define VPU_VPU_DEC_RET_QUERY_DEC_RECOVERY_POINT_SIGNED_RECOVERY_POC_CNT_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_DEC_RECOVERY_POINT_SIGNED_RECOVERY_POC_CNT(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_RECOVERY_POINT_SIGNED_RECOVERY_POC_CNT_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_RECOVERY_POINT_SIGNED_RECOVERY_POC_CNT_MASK)

#define VPU_VPU_DEC_RET_QUERY_DEC_RECOVERY_POINT_EXACT_MATCH_FLAG_MASK (0x10000U)
#define VPU_VPU_DEC_RET_QUERY_DEC_RECOVERY_POINT_EXACT_MATCH_FLAG_SHIFT (16U)
#define VPU_VPU_DEC_RET_QUERY_DEC_RECOVERY_POINT_EXACT_MATCH_FLAG(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_RECOVERY_POINT_EXACT_MATCH_FLAG_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_RECOVERY_POINT_EXACT_MATCH_FLAG_MASK)

#define VPU_VPU_DEC_RET_QUERY_DEC_RECOVERY_POINT_BROKEN_LINK_FLAG_MASK (0x20000U)
#define VPU_VPU_DEC_RET_QUERY_DEC_RECOVERY_POINT_BROKEN_LINK_FLAG_SHIFT (17U)
#define VPU_VPU_DEC_RET_QUERY_DEC_RECOVERY_POINT_BROKEN_LINK_FLAG(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_RECOVERY_POINT_BROKEN_LINK_FLAG_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_RECOVERY_POINT_BROKEN_LINK_FLAG_MASK)

#define VPU_VPU_DEC_RET_QUERY_DEC_RECOVERY_POINT_EXIST_FLAG_MASK (0x40000U)
#define VPU_VPU_DEC_RET_QUERY_DEC_RECOVERY_POINT_EXIST_FLAG_SHIFT (18U)
#define VPU_VPU_DEC_RET_QUERY_DEC_RECOVERY_POINT_EXIST_FLAG(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_RECOVERY_POINT_EXIST_FLAG_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_RECOVERY_POINT_EXIST_FLAG_MASK)
/*! @} */

/*! @name CMD_SET_FB_ADDR_CR_BASE3 - Cr base address of DPB index 3 */
/*! @{ */

#define VPU_VPU_DEC_CMD_SET_FB_ADDR_CR_BASE3_CR_BASE_FBC_Y_OFFSET_BASE3_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_CR_BASE3_CR_BASE_FBC_Y_OFFSET_BASE3_SHIFT (0U)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_CR_BASE3_CR_BASE_FBC_Y_OFFSET_BASE3(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_ADDR_CR_BASE3_CR_BASE_FBC_Y_OFFSET_BASE3_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_ADDR_CR_BASE3_CR_BASE_FBC_Y_OFFSET_BASE3_MASK)
/*! @} */

/*! @name CMD_SET_FB_ADDR_FBC_Y_OFFSET3 - Compressed luma offset base address of DPB index 3 */
/*! @{ */

#define VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_Y_OFFSET3_CR_BASE_FBC_Y_OFFSET_BASE3_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_Y_OFFSET3_CR_BASE_FBC_Y_OFFSET_BASE3_SHIFT (0U)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_Y_OFFSET3_CR_BASE_FBC_Y_OFFSET_BASE3(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_Y_OFFSET3_CR_BASE_FBC_Y_OFFSET_BASE3_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_Y_OFFSET3_CR_BASE_FBC_Y_OFFSET_BASE3_MASK)
/*! @} */

/*! @name RET_QUERY_DEC_DEBUG_INDEX - FBC and BWB frame buffer index for internal use */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_DEC_DEBUG_INDEX_DEC_BWB_FB_INDEX_MASK (0xFFFFU)
#define VPU_VPU_DEC_RET_QUERY_DEC_DEBUG_INDEX_DEC_BWB_FB_INDEX_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_DEC_DEBUG_INDEX_DEC_BWB_FB_INDEX(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_DEBUG_INDEX_DEC_BWB_FB_INDEX_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_DEBUG_INDEX_DEC_BWB_FB_INDEX_MASK)

#define VPU_VPU_DEC_RET_QUERY_DEC_DEBUG_INDEX_DEC_FBC_FB_INDEX_MASK (0xFFFF0000U)
#define VPU_VPU_DEC_RET_QUERY_DEC_DEBUG_INDEX_DEC_FBC_FB_INDEX_SHIFT (16U)
#define VPU_VPU_DEC_RET_QUERY_DEC_DEBUG_INDEX_DEC_FBC_FB_INDEX(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_DEBUG_INDEX_DEC_FBC_FB_INDEX_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_DEBUG_INDEX_DEC_FBC_FB_INDEX_MASK)
/*! @} */

/*! @name CMD_SET_FB_ADDR_FBC_C_OFFSET3 - Compressed chroma offset base address of DPB index 3 */
/*! @{ */

#define VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_C_OFFSET3_FBC_CHROMA_OFFSET_BASE3_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_C_OFFSET3_FBC_CHROMA_OFFSET_BASE3_SHIFT (0U)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_C_OFFSET3_FBC_CHROMA_OFFSET_BASE3(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_C_OFFSET3_FBC_CHROMA_OFFSET_BASE3_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_C_OFFSET3_FBC_CHROMA_OFFSET_BASE3_MASK)
/*! @} */

/*! @name RET_QUERY_DEC_DECODED_INDEX - Decoded picture index of DPB */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_DEC_DECODED_INDEX_DEC_PIC_INDEX_MASK (0x1FU)
#define VPU_VPU_DEC_RET_QUERY_DEC_DECODED_INDEX_DEC_PIC_INDEX_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_DEC_DECODED_INDEX_DEC_PIC_INDEX(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_DECODED_INDEX_DEC_PIC_INDEX_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_DECODED_INDEX_DEC_PIC_INDEX_MASK)
/*! @} */

/*! @name CMD_SET_FB_ADDR_LUMA_BASE4 - Luma base address of DPB index 4 */
/*! @{ */

#define VPU_VPU_DEC_CMD_SET_FB_ADDR_LUMA_BASE4_LUMA_BASE4_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_LUMA_BASE4_LUMA_BASE4_SHIFT (0U)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_LUMA_BASE4_LUMA_BASE4(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_ADDR_LUMA_BASE4_LUMA_BASE4_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_ADDR_LUMA_BASE4_LUMA_BASE4_MASK)
/*! @} */

/*! @name RET_QUERY_DEC_DISPLAY_INDEX - Display picture index of DPB */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_DEC_DISPLAY_INDEX_DISPLAY_PIC_INDEX_MASK (0x1FU)
#define VPU_VPU_DEC_RET_QUERY_DEC_DISPLAY_INDEX_DISPLAY_PIC_INDEX_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_DEC_DISPLAY_INDEX_DISPLAY_PIC_INDEX(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_DISPLAY_INDEX_DISPLAY_PIC_INDEX_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_DISPLAY_INDEX_DISPLAY_PIC_INDEX_MASK)
/*! @} */

/*! @name CMD_SET_FB_ADDR_CB_BASE4 - Cb base address of DPB index 4 */
/*! @{ */

#define VPU_VPU_DEC_CMD_SET_FB_ADDR_CB_BASE4_CB_BASE_FBC_CBCR_BASE4_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_CB_BASE4_CB_BASE_FBC_CBCR_BASE4_SHIFT (0U)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_CB_BASE4_CB_BASE_FBC_CBCR_BASE4(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_ADDR_CB_BASE4_CB_BASE_FBC_CBCR_BASE4_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_ADDR_CB_BASE4_CB_BASE_FBC_CBCR_BASE4_MASK)
/*! @} */

/*! @name RET_QUERY_DEC_REALLOC_INDEX - Display picture index of DPB */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_DEC_REALLOC_INDEX_DISPLAY_PIC_INDEX_MASK (0x1FU)
#define VPU_VPU_DEC_RET_QUERY_DEC_REALLOC_INDEX_DISPLAY_PIC_INDEX_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_DEC_REALLOC_INDEX_DISPLAY_PIC_INDEX(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_REALLOC_INDEX_DISPLAY_PIC_INDEX_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_REALLOC_INDEX_DISPLAY_PIC_INDEX_MASK)
/*! @} */

/*! @name CMD_SET_FB_ADDR_CR_BASE4 - Cr base address of DPB index 4 */
/*! @{ */

#define VPU_VPU_DEC_CMD_SET_FB_ADDR_CR_BASE4_CR_BASE_FBC_Y_OFFSET_BASE4_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_CR_BASE4_CR_BASE_FBC_Y_OFFSET_BASE4_SHIFT (0U)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_CR_BASE4_CR_BASE_FBC_Y_OFFSET_BASE4(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_ADDR_CR_BASE4_CR_BASE_FBC_Y_OFFSET_BASE4_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_ADDR_CR_BASE4_CR_BASE_FBC_Y_OFFSET_BASE4_MASK)
/*! @} */

/*! @name CMD_SET_FB_ADDR_FBC_Y_OFFSET4 - Compressed luma offset base address of DPB index 4 */
/*! @{ */

#define VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_Y_OFFSET4_CR_BASE_FBC_Y_OFFSET_BASE4_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_Y_OFFSET4_CR_BASE_FBC_Y_OFFSET_BASE4_SHIFT (0U)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_Y_OFFSET4_CR_BASE_FBC_Y_OFFSET_BASE4(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_Y_OFFSET4_CR_BASE_FBC_Y_OFFSET_BASE4_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_Y_OFFSET4_CR_BASE_FBC_Y_OFFSET_BASE4_MASK)
/*! @} */

/*! @name RET_QUERY_DEC_DISP_IDC - Display flag */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_DEC_DISP_IDC_DISPLAY_FLAG_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_QUERY_DEC_DISP_IDC_DISPLAY_FLAG_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_DEC_DISP_IDC_DISPLAY_FLAG(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_DISP_IDC_DISPLAY_FLAG_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_DISP_IDC_DISPLAY_FLAG_MASK)
/*! @} */

/*! @name RET_QUERY_DEC_DISP_IDC_QUERY_UPDATE_DISP_IDC - RET_QUERY_DEC_DISP_IDC */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_DEC_DISP_IDC_QUERY_UPDATE_DISP_IDC_DEC_DISP_IDC_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_QUERY_DEC_DISP_IDC_QUERY_UPDATE_DISP_IDC_DEC_DISP_IDC_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_DEC_DISP_IDC_QUERY_UPDATE_DISP_IDC_DEC_DISP_IDC(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_DISP_IDC_QUERY_UPDATE_DISP_IDC_DEC_DISP_IDC_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_DISP_IDC_QUERY_UPDATE_DISP_IDC_DEC_DISP_IDC_MASK)
/*! @} */

/*! @name CMD_SET_FB_ADDR_FBC_C_OFFSET4 - Compressed chroma offset base address of DPB index 4 */
/*! @{ */

#define VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_C_OFFSET4_FBC_CHROMA_OFFSET_BASE4_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_C_OFFSET4_FBC_CHROMA_OFFSET_BASE4_SHIFT (0U)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_C_OFFSET4_FBC_CHROMA_OFFSET_BASE4(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_C_OFFSET4_FBC_CHROMA_OFFSET_BASE4_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_C_OFFSET4_FBC_CHROMA_OFFSET_BASE4_MASK)
/*! @} */

/*! @name RET_QUERY_DEC_NUM_ERR_CTB - Number of error CTU */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_DEC_NUM_ERR_CTB_ERROR_CTU_NUMBER_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_QUERY_DEC_NUM_ERR_CTB_ERROR_CTU_NUMBER_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_DEC_NUM_ERR_CTB_ERROR_CTU_NUMBER(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_NUM_ERR_CTB_ERROR_CTU_NUMBER_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_NUM_ERR_CTB_ERROR_CTU_NUMBER_MASK)
/*! @} */

/*! @name CMD_SET_FB_ADDR_LUMA_BASE5 - Luma base address of DPB index 5 */
/*! @{ */

#define VPU_VPU_DEC_CMD_SET_FB_ADDR_LUMA_BASE5_LUMA_BASE5_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_LUMA_BASE5_LUMA_BASE5_SHIFT (0U)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_LUMA_BASE5_LUMA_BASE5(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_ADDR_LUMA_BASE5_LUMA_BASE5_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_ADDR_LUMA_BASE5_LUMA_BASE5_MASK)
/*! @} */

/*! @name RET_QUERY_VLC_BASE - Base address of VLC buffer */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_VLC_BASE_VLC_BUF_BASE_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_QUERY_VLC_BASE_VLC_BUF_BASE_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_VLC_BASE_VLC_BUF_BASE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_VLC_BASE_VLC_BUF_BASE_SHIFT)) & VPU_VPU_DEC_RET_QUERY_VLC_BASE_VLC_BUF_BASE_MASK)
/*! @} */

/*! @name CMD_SET_FB_ADDR_CB_BASE5 - Cb base address of DPB index 5 */
/*! @{ */

#define VPU_VPU_DEC_CMD_SET_FB_ADDR_CB_BASE5_CB_BASE_FBC_CBCR_BASE5_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_CB_BASE5_CB_BASE_FBC_CBCR_BASE5_SHIFT (0U)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_CB_BASE5_CB_BASE_FBC_CBCR_BASE5(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_ADDR_CB_BASE5_CB_BASE_FBC_CBCR_BASE5_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_ADDR_CB_BASE5_CB_BASE_FBC_CBCR_BASE5_MASK)
/*! @} */

/*! @name RET_QUERY_LINEAR_Y_BASE - Luma display frame buffer address */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_LINEAR_Y_BASE_LINEAR_Y_BUF_BASE_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_QUERY_LINEAR_Y_BASE_LINEAR_Y_BUF_BASE_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_LINEAR_Y_BASE_LINEAR_Y_BUF_BASE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_LINEAR_Y_BASE_LINEAR_Y_BUF_BASE_SHIFT)) & VPU_VPU_DEC_RET_QUERY_LINEAR_Y_BASE_LINEAR_Y_BUF_BASE_MASK)
/*! @} */

/*! @name CMD_SET_FB_ADDR_CR_BASE5 - Cr base address of DPB index 5 */
/*! @{ */

#define VPU_VPU_DEC_CMD_SET_FB_ADDR_CR_BASE5_CR_BASE_FBC_Y_OFFSET_BASE5_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_CR_BASE5_CR_BASE_FBC_Y_OFFSET_BASE5_SHIFT (0U)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_CR_BASE5_CR_BASE_FBC_Y_OFFSET_BASE5(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_ADDR_CR_BASE5_CR_BASE_FBC_Y_OFFSET_BASE5_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_ADDR_CR_BASE5_CR_BASE_FBC_Y_OFFSET_BASE5_MASK)
/*! @} */

/*! @name CMD_SET_FB_ADDR_FBC_Y_OFFSET5 - Compressed luma offset base address of DPB index 5 */
/*! @{ */

#define VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_Y_OFFSET5_CR_BASE_FBC_Y_OFFSET_BASE5_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_Y_OFFSET5_CR_BASE_FBC_Y_OFFSET_BASE5_SHIFT (0U)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_Y_OFFSET5_CR_BASE_FBC_Y_OFFSET_BASE5(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_Y_OFFSET5_CR_BASE_FBC_Y_OFFSET_BASE5_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_Y_OFFSET5_CR_BASE_FBC_Y_OFFSET_BASE5_MASK)
/*! @} */

/*! @name RET_QUERY_LINEAR_CB_BASE - Cb display frame buffer address */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_LINEAR_CB_BASE_LINEAR_CB_BUF_BASE_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_QUERY_LINEAR_CB_BASE_LINEAR_CB_BUF_BASE_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_LINEAR_CB_BASE_LINEAR_CB_BUF_BASE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_LINEAR_CB_BASE_LINEAR_CB_BUF_BASE_SHIFT)) & VPU_VPU_DEC_RET_QUERY_LINEAR_CB_BASE_LINEAR_CB_BUF_BASE_MASK)
/*! @} */

/*! @name CMD_SET_FB_ADDR_FBC_C_OFFSET5 - Compressed chroma offset base address of DPB index 5 */
/*! @{ */

#define VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_C_OFFSET5_FBC_CHROMA_OFFSET_BASE5_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_C_OFFSET5_FBC_CHROMA_OFFSET_BASE5_SHIFT (0U)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_C_OFFSET5_FBC_CHROMA_OFFSET_BASE5(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_C_OFFSET5_FBC_CHROMA_OFFSET_BASE5_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_C_OFFSET5_FBC_CHROMA_OFFSET_BASE5_MASK)
/*! @} */

/*! @name RET_QUERY_LINEAR_CR_BASE - Cr display frame buffer address */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_LINEAR_CR_BASE_LINEAR_CR_BUF_BASE_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_QUERY_LINEAR_CR_BASE_LINEAR_CR_BUF_BASE_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_LINEAR_CR_BASE_LINEAR_CR_BUF_BASE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_LINEAR_CR_BASE_LINEAR_CR_BUF_BASE_SHIFT)) & VPU_VPU_DEC_RET_QUERY_LINEAR_CR_BASE_LINEAR_CR_BUF_BASE_MASK)
/*! @} */

/*! @name CMD_DEC_VCORE_INFO - VCORE information */
/*! @{ */

#define VPU_VPU_DEC_CMD_DEC_VCORE_INFO_USE_VCORE_NUM_MASK (0xFU)
#define VPU_VPU_DEC_CMD_DEC_VCORE_INFO_USE_VCORE_NUM_SHIFT (0U)
#define VPU_VPU_DEC_CMD_DEC_VCORE_INFO_USE_VCORE_NUM(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_DEC_VCORE_INFO_USE_VCORE_NUM_SHIFT)) & VPU_VPU_DEC_CMD_DEC_VCORE_INFO_USE_VCORE_NUM_MASK)

#define VPU_VPU_DEC_CMD_DEC_VCORE_INFO_VCORE_CORE_IDC_MASK (0xF0U)
#define VPU_VPU_DEC_CMD_DEC_VCORE_INFO_VCORE_CORE_IDC_SHIFT (4U)
#define VPU_VPU_DEC_CMD_DEC_VCORE_INFO_VCORE_CORE_IDC(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_DEC_VCORE_INFO_VCORE_CORE_IDC_SHIFT)) & VPU_VPU_DEC_CMD_DEC_VCORE_INFO_VCORE_CORE_IDC_MASK)
/*! @} */

/*! @name CMD_SET_FB_ADDR_LUMA_BASE6 - Luma base address of DPB index 6 */
/*! @{ */

#define VPU_VPU_DEC_CMD_SET_FB_ADDR_LUMA_BASE6_LUMA_BASE6_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_LUMA_BASE6_LUMA_BASE6_SHIFT (0U)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_LUMA_BASE6_LUMA_BASE6(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_ADDR_LUMA_BASE6_LUMA_BASE6_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_ADDR_LUMA_BASE6_LUMA_BASE6_MASK)
/*! @} */

/*! @name RET_QUERY_INPLACE_Y_BASE - Inplace ring buffer luma base address */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_INPLACE_Y_BASE_INPLACE_Y_BASE_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_QUERY_INPLACE_Y_BASE_INPLACE_Y_BASE_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_INPLACE_Y_BASE_INPLACE_Y_BASE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_INPLACE_Y_BASE_INPLACE_Y_BASE_SHIFT)) & VPU_VPU_DEC_RET_QUERY_INPLACE_Y_BASE_INPLACE_Y_BASE_MASK)
/*! @} */

/*! @name CMD_SET_FB_ADDR_CB_BASE6 - Cb base address of DPB index 6 */
/*! @{ */

#define VPU_VPU_DEC_CMD_SET_FB_ADDR_CB_BASE6_CB_BASE_FBC_CBCR_BASE6_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_CB_BASE6_CB_BASE_FBC_CBCR_BASE6_SHIFT (0U)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_CB_BASE6_CB_BASE_FBC_CBCR_BASE6(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_ADDR_CB_BASE6_CB_BASE_FBC_CBCR_BASE6_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_ADDR_CB_BASE6_CB_BASE_FBC_CBCR_BASE6_MASK)
/*! @} */

/*! @name RET_QUERY_INPLACE_C_BASE - Inplace ring buffer chroma base address */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_INPLACE_C_BASE_INPLACE_C_BASE_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_QUERY_INPLACE_C_BASE_INPLACE_C_BASE_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_INPLACE_C_BASE_INPLACE_C_BASE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_INPLACE_C_BASE_INPLACE_C_BASE_SHIFT)) & VPU_VPU_DEC_RET_QUERY_INPLACE_C_BASE_INPLACE_C_BASE_MASK)
/*! @} */

/*! @name CMD_SET_FB_ADDR_CR_BASE6 - Cr base address of DPB index 6 */
/*! @{ */

#define VPU_VPU_DEC_CMD_SET_FB_ADDR_CR_BASE6_CR_BASE_FBC_Y_OFFSET_BASE6_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_CR_BASE6_CR_BASE_FBC_Y_OFFSET_BASE6_SHIFT (0U)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_CR_BASE6_CR_BASE_FBC_Y_OFFSET_BASE6(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_ADDR_CR_BASE6_CR_BASE_FBC_Y_OFFSET_BASE6_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_ADDR_CR_BASE6_CR_BASE_FBC_Y_OFFSET_BASE6_MASK)
/*! @} */

/*! @name CMD_SET_FB_ADDR_FBC_Y_OFFSET6 - Compressed luma offset base address of DPB index 6 */
/*! @{ */

#define VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_Y_OFFSET6_CR_BASE_FBC_Y_OFFSET_BASE6_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_Y_OFFSET6_CR_BASE_FBC_Y_OFFSET_BASE6_SHIFT (0U)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_Y_OFFSET6_CR_BASE_FBC_Y_OFFSET_BASE6(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_Y_OFFSET6_CR_BASE_FBC_Y_OFFSET_BASE6_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_Y_OFFSET6_CR_BASE_FBC_Y_OFFSET_BASE6_MASK)
/*! @} */

/*! @name RET_QUERY_CORE_IDC - Core_IDC */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_CORE_IDC_STAGE0_CORE_IDC_MASK (0xFU)
#define VPU_VPU_DEC_RET_QUERY_CORE_IDC_STAGE0_CORE_IDC_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_CORE_IDC_STAGE0_CORE_IDC(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_CORE_IDC_STAGE0_CORE_IDC_SHIFT)) & VPU_VPU_DEC_RET_QUERY_CORE_IDC_STAGE0_CORE_IDC_MASK)

#define VPU_VPU_DEC_RET_QUERY_CORE_IDC_STAGE1_CORE_IDC_MASK (0xF0U)
#define VPU_VPU_DEC_RET_QUERY_CORE_IDC_STAGE1_CORE_IDC_SHIFT (4U)
#define VPU_VPU_DEC_RET_QUERY_CORE_IDC_STAGE1_CORE_IDC(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_CORE_IDC_STAGE1_CORE_IDC_SHIFT)) & VPU_VPU_DEC_RET_QUERY_CORE_IDC_STAGE1_CORE_IDC_MASK)

#define VPU_VPU_DEC_RET_QUERY_CORE_IDC_STAGE2_CORE_IDC_MASK (0xF00U)
#define VPU_VPU_DEC_RET_QUERY_CORE_IDC_STAGE2_CORE_IDC_SHIFT (8U)
#define VPU_VPU_DEC_RET_QUERY_CORE_IDC_STAGE2_CORE_IDC(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_CORE_IDC_STAGE2_CORE_IDC_SHIFT)) & VPU_VPU_DEC_RET_QUERY_CORE_IDC_STAGE2_CORE_IDC_MASK)

#define VPU_VPU_DEC_RET_QUERY_CORE_IDC_STAGE3_CORE_IDC_MASK (0xF000U)
#define VPU_VPU_DEC_RET_QUERY_CORE_IDC_STAGE3_CORE_IDC_SHIFT (12U)
#define VPU_VPU_DEC_RET_QUERY_CORE_IDC_STAGE3_CORE_IDC(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_CORE_IDC_STAGE3_CORE_IDC_SHIFT)) & VPU_VPU_DEC_RET_QUERY_CORE_IDC_STAGE3_CORE_IDC_MASK)

#define VPU_VPU_DEC_RET_QUERY_CORE_IDC_RSVD0_MASK (0xFFFF0000U)
#define VPU_VPU_DEC_RET_QUERY_CORE_IDC_RSVD0_SHIFT (16U)
#define VPU_VPU_DEC_RET_QUERY_CORE_IDC_RSVD0(x)  (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_CORE_IDC_RSVD0_SHIFT)) & VPU_VPU_DEC_RET_QUERY_CORE_IDC_RSVD0_MASK)
/*! @} */

/*! @name CMD_SET_FB_ADDR_FBC_C_OFFSET6 - Compressed chroma offset base address of DPB index 6 */
/*! @{ */

#define VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_C_OFFSET6_FBC_CHROMA_OFFSET_BASE6_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_C_OFFSET6_FBC_CHROMA_OFFSET_BASE6_SHIFT (0U)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_C_OFFSET6_FBC_CHROMA_OFFSET_BASE6(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_C_OFFSET6_FBC_CHROMA_OFFSET_BASE6_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_C_OFFSET6_FBC_CHROMA_OFFSET_BASE6_MASK)
/*! @} */

/*! @name RET_QUERY_DEC_PIC_PARAM - Bitstream sequence/pic parameter information */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_DEC_PIC_PARAM_ENABLE_INTRABC_MASK (0x1U)
#define VPU_VPU_DEC_RET_QUERY_DEC_PIC_PARAM_ENABLE_INTRABC_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_DEC_PIC_PARAM_ENABLE_INTRABC(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_PIC_PARAM_ENABLE_INTRABC_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_PIC_PARAM_ENABLE_INTRABC_MASK)

#define VPU_VPU_DEC_RET_QUERY_DEC_PIC_PARAM_ENABLE_SCREEN_CONT_TOOLS_MASK (0x2U)
#define VPU_VPU_DEC_RET_QUERY_DEC_PIC_PARAM_ENABLE_SCREEN_CONT_TOOLS_SHIFT (1U)
#define VPU_VPU_DEC_RET_QUERY_DEC_PIC_PARAM_ENABLE_SCREEN_CONT_TOOLS(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_PIC_PARAM_ENABLE_SCREEN_CONT_TOOLS_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_PIC_PARAM_ENABLE_SCREEN_CONT_TOOLS_MASK)

#define VPU_VPU_DEC_RET_QUERY_DEC_PIC_PARAM_RSVD0_MASK (0xFFFFFFFCU)
#define VPU_VPU_DEC_RET_QUERY_DEC_PIC_PARAM_RSVD0_SHIFT (2U)
#define VPU_VPU_DEC_RET_QUERY_DEC_PIC_PARAM_RSVD0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_PIC_PARAM_RSVD0_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_PIC_PARAM_RSVD0_MASK)
/*! @} */

/*! @name CMD_SET_FB_ADDR_LUMA_BASE7 - Luma base address of DPB index 7 */
/*! @{ */

#define VPU_VPU_DEC_CMD_SET_FB_ADDR_LUMA_BASE7_LUMA_BASE7_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_LUMA_BASE7_LUMA_BASE7_SHIFT (0U)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_LUMA_BASE7_LUMA_BASE7(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_ADDR_LUMA_BASE7_LUMA_BASE7_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_ADDR_LUMA_BASE7_LUMA_BASE7_MASK)
/*! @} */

/*! @name CMD_SET_FB_ADDR_CB_BASE7 - Cb base address of DPB index 7 */
/*! @{ */

#define VPU_VPU_DEC_CMD_SET_FB_ADDR_CB_BASE7_CB_BASE_FBC_CBCR_BASE7_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_CB_BASE7_CB_BASE_FBC_CBCR_BASE7_SHIFT (0U)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_CB_BASE7_CB_BASE_FBC_CBCR_BASE7(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_ADDR_CB_BASE7_CB_BASE_FBC_CBCR_BASE7_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_ADDR_CB_BASE7_CB_BASE_FBC_CBCR_BASE7_MASK)
/*! @} */

/*! @name CMD_SET_FB_ADDR_CR_BASE7 - Cr base address of DPB index 7 */
/*! @{ */

#define VPU_VPU_DEC_CMD_SET_FB_ADDR_CR_BASE7_CR_BASE_FBC_Y_OFFSET_BASE7_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_CR_BASE7_CR_BASE_FBC_Y_OFFSET_BASE7_SHIFT (0U)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_CR_BASE7_CR_BASE_FBC_Y_OFFSET_BASE7(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_ADDR_CR_BASE7_CR_BASE_FBC_Y_OFFSET_BASE7_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_ADDR_CR_BASE7_CR_BASE_FBC_Y_OFFSET_BASE7_MASK)
/*! @} */

/*! @name CMD_SET_FB_ADDR_FBC_Y_OFFSET7 - Compressed luma offset base address of DPB index 7 */
/*! @{ */

#define VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_Y_OFFSET7_CR_BASE_FBC_Y_OFFSET_BASE7_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_Y_OFFSET7_CR_BASE_FBC_Y_OFFSET_BASE7_SHIFT (0U)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_Y_OFFSET7_CR_BASE_FBC_Y_OFFSET_BASE7(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_Y_OFFSET7_CR_BASE_FBC_Y_OFFSET_BASE7_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_Y_OFFSET7_CR_BASE_FBC_Y_OFFSET_BASE7_MASK)
/*! @} */

/*! @name CMD_SET_FB_ADDR_FBC_C_OFFSET7 - Compressed chroma offset base address of DPB index 7 */
/*! @{ */

#define VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_C_OFFSET7_FBC_CHROMA_OFFSET_BASE7_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_C_OFFSET7_FBC_CHROMA_OFFSET_BASE7_SHIFT (0U)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_C_OFFSET7_FBC_CHROMA_OFFSET_BASE7(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_C_OFFSET7_FBC_CHROMA_OFFSET_BASE7_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_ADDR_FBC_C_OFFSET7_FBC_CHROMA_OFFSET_BASE7_MASK)
/*! @} */

/*! @name RET_QUERY_DEC_VLC_BUF_SIZE - The size of a VLC buffer */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_DEC_VLC_BUF_SIZE_VLC_BUF_SIZE_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_QUERY_DEC_VLC_BUF_SIZE_VLC_BUF_SIZE_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_DEC_VLC_BUF_SIZE_VLC_BUF_SIZE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_VLC_BUF_SIZE_VLC_BUF_SIZE_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_VLC_BUF_SIZE_VLC_BUF_SIZE_MASK)
/*! @} */

/*! @name CMD_SET_FB_ADDR_MV_COL0 - Colocated MV buffer base of DPB index 0 */
/*! @{ */

#define VPU_VPU_DEC_CMD_SET_FB_ADDR_MV_COL0_COL_MV_BUF_BASE0_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_MV_COL0_COL_MV_BUF_BASE0_SHIFT (0U)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_MV_COL0_COL_MV_BUF_BASE0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_ADDR_MV_COL0_COL_MV_BUF_BASE0_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_ADDR_MV_COL0_COL_MV_BUF_BASE0_MASK)
/*! @} */

/*! @name RET_QUERY_DEC_PARAM_BUF_SIZE - The size of a parameter buffer */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_DEC_PARAM_BUF_SIZE_PARAM_BUF_SIZE_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_QUERY_DEC_PARAM_BUF_SIZE_PARAM_BUF_SIZE_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_DEC_PARAM_BUF_SIZE_PARAM_BUF_SIZE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_PARAM_BUF_SIZE_PARAM_BUF_SIZE_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_PARAM_BUF_SIZE_PARAM_BUF_SIZE_MASK)
/*! @} */

/*! @name CMD_SET_FB_ADDR_MV_COL1 - Colocated MV buffer base of DPB index 1 */
/*! @{ */

#define VPU_VPU_DEC_CMD_SET_FB_ADDR_MV_COL1_COL_MV_BUF_BASE1_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_MV_COL1_COL_MV_BUF_BASE1_SHIFT (0U)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_MV_COL1_COL_MV_BUF_BASE1(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_ADDR_MV_COL1_COL_MV_BUF_BASE1_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_ADDR_MV_COL1_COL_MV_BUF_BASE1_MASK)
/*! @} */

/*! @name RET_QUERY_HOST_CMD_TICK - Host cmd queue tick */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_HOST_CMD_TICK_HOST_CMD_TICK_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_QUERY_HOST_CMD_TICK_HOST_CMD_TICK_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_HOST_CMD_TICK_HOST_CMD_TICK(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_HOST_CMD_TICK_HOST_CMD_TICK_SHIFT)) & VPU_VPU_DEC_RET_QUERY_HOST_CMD_TICK_HOST_CMD_TICK_MASK)
/*! @} */

/*! @name CMD_SET_FB_ADDR_MV_COL2 - Colocated MV buffer base of DPB index 2 */
/*! @{ */

#define VPU_VPU_DEC_CMD_SET_FB_ADDR_MV_COL2_COL_MV_BUF_BASE2_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_MV_COL2_COL_MV_BUF_BASE2_SHIFT (0U)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_MV_COL2_COL_MV_BUF_BASE2(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_ADDR_MV_COL2_COL_MV_BUF_BASE2_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_ADDR_MV_COL2_COL_MV_BUF_BASE2_MASK)
/*! @} */

/*! @name RET_QUERY_DEC_SEEK_START_TICK - Seek start tick */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_DEC_SEEK_START_TICK_SEEK_START_TICK_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_QUERY_DEC_SEEK_START_TICK_SEEK_START_TICK_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_DEC_SEEK_START_TICK_SEEK_START_TICK(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_SEEK_START_TICK_SEEK_START_TICK_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_SEEK_START_TICK_SEEK_START_TICK_MASK)
/*! @} */

/*! @name CMD_SET_FB_ADDR_MV_COL3 - Colocated MV buffer base of DPB index 3 */
/*! @{ */

#define VPU_VPU_DEC_CMD_SET_FB_ADDR_MV_COL3_COL_MV_BUF_BASE3_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_MV_COL3_COL_MV_BUF_BASE3_SHIFT (0U)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_MV_COL3_COL_MV_BUF_BASE3(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_ADDR_MV_COL3_COL_MV_BUF_BASE3_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_ADDR_MV_COL3_COL_MV_BUF_BASE3_MASK)
/*! @} */

/*! @name RET_QUERY_DEC_SEEK_END_TICK - Seek end tick */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_DEC_SEEK_END_TICK_SEEK_END_TICK_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_QUERY_DEC_SEEK_END_TICK_SEEK_END_TICK_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_DEC_SEEK_END_TICK_SEEK_END_TICK(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_SEEK_END_TICK_SEEK_END_TICK_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_SEEK_END_TICK_SEEK_END_TICK_MASK)
/*! @} */

/*! @name CMD_SET_FB_ADDR_MV_COL4 - Colocated MV buffer base of DPB index 4 */
/*! @{ */

#define VPU_VPU_DEC_CMD_SET_FB_ADDR_MV_COL4_COL_MV_BUF_BASE4_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_MV_COL4_COL_MV_BUF_BASE4_SHIFT (0U)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_MV_COL4_COL_MV_BUF_BASE4(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_ADDR_MV_COL4_COL_MV_BUF_BASE4_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_ADDR_MV_COL4_COL_MV_BUF_BASE4_MASK)
/*! @} */

/*! @name RET_QUERY_DEC_PARSING_START_TICK - Parsing start tick */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_DEC_PARSING_START_TICK_PARSE_START_TICK_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_QUERY_DEC_PARSING_START_TICK_PARSE_START_TICK_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_DEC_PARSING_START_TICK_PARSE_START_TICK(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_PARSING_START_TICK_PARSE_START_TICK_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_PARSING_START_TICK_PARSE_START_TICK_MASK)
/*! @} */

/*! @name CMD_SET_FB_ADDR_MV_COL5 - Colocated MV buffer base of DPB index 5 */
/*! @{ */

#define VPU_VPU_DEC_CMD_SET_FB_ADDR_MV_COL5_COL_MV_BUF_BASE5_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_MV_COL5_COL_MV_BUF_BASE5_SHIFT (0U)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_MV_COL5_COL_MV_BUF_BASE5(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_ADDR_MV_COL5_COL_MV_BUF_BASE5_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_ADDR_MV_COL5_COL_MV_BUF_BASE5_MASK)
/*! @} */

/*! @name RET_QUERY_DEC_PARSING_END_TICK - Parsing end tick */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_DEC_PARSING_END_TICK_PARSE_END_TICK_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_QUERY_DEC_PARSING_END_TICK_PARSE_END_TICK_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_DEC_PARSING_END_TICK_PARSE_END_TICK(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_PARSING_END_TICK_PARSE_END_TICK_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_PARSING_END_TICK_PARSE_END_TICK_MASK)
/*! @} */

/*! @name CMD_SET_FB_ADDR_MV_COL6 - Colocated MV buffer base of DPB index 6 */
/*! @{ */

#define VPU_VPU_DEC_CMD_SET_FB_ADDR_MV_COL6_COL_MV_BUF_BASE6_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_MV_COL6_COL_MV_BUF_BASE6_SHIFT (0U)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_MV_COL6_COL_MV_BUF_BASE6(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_ADDR_MV_COL6_COL_MV_BUF_BASE6_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_ADDR_MV_COL6_COL_MV_BUF_BASE6_MASK)
/*! @} */

/*! @name RET_QUERY_DEC_DECODING_START_TICK - Decoding start tick */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_DEC_DECODING_START_TICK_DEC_START_TICK_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_QUERY_DEC_DECODING_START_TICK_DEC_START_TICK_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_DEC_DECODING_START_TICK_DEC_START_TICK(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_DECODING_START_TICK_DEC_START_TICK_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_DECODING_START_TICK_DEC_START_TICK_MASK)
/*! @} */

/*! @name CMD_SET_FB_ADDR_MV_COL7 - Colocated MV buffer base of DPB index 7 */
/*! @{ */

#define VPU_VPU_DEC_CMD_SET_FB_ADDR_MV_COL7_COL_MV_BUF_BASE7_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_MV_COL7_COL_MV_BUF_BASE7_SHIFT (0U)
#define VPU_VPU_DEC_CMD_SET_FB_ADDR_MV_COL7_COL_MV_BUF_BASE7(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_CMD_SET_FB_ADDR_MV_COL7_COL_MV_BUF_BASE7_SHIFT)) & VPU_VPU_DEC_CMD_SET_FB_ADDR_MV_COL7_COL_MV_BUF_BASE7_MASK)
/*! @} */

/*! @name RET_QUERY_DEC_DECODING_END_TICK - Decoding end tick */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_DEC_DECODING_END_TICK_DEC_END_TICK_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_QUERY_DEC_DECODING_END_TICK_DEC_END_TICK_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_DEC_DECODING_END_TICK_DEC_END_TICK(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_DECODING_END_TICK_DEC_END_TICK_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_DECODING_END_TICK_DEC_END_TICK_MASK)
/*! @} */

/*! @name RET_QUERY_DEC_WARN_INFO - Warning information */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_DEC_WARN_INFO_DEC_WARN_INFO_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_QUERY_DEC_WARN_INFO_DEC_WARN_INFO_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_DEC_WARN_INFO_DEC_WARN_INFO(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_WARN_INFO_DEC_WARN_INFO_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_WARN_INFO_DEC_WARN_INFO_MASK)
/*! @} */

/*! @name RET_QUERY_DEC_ERR_INFO - Error information */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_DEC_ERR_INFO_ERROR_INFO_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_QUERY_DEC_ERR_INFO_ERROR_INFO_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_DEC_ERR_INFO_ERROR_INFO(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_ERR_INFO_ERROR_INFO_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_ERR_INFO_ERROR_INFO_MASK)
/*! @} */

/*! @name RET_QUERY_DEC_SUCCESS - Query result */
/*! @{ */

#define VPU_VPU_DEC_RET_QUERY_DEC_SUCCESS_QUERY_DEC_SUCCESS_MASK (0x3U)
#define VPU_VPU_DEC_RET_QUERY_DEC_SUCCESS_QUERY_DEC_SUCCESS_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUERY_DEC_SUCCESS_QUERY_DEC_SUCCESS(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUERY_DEC_SUCCESS_QUERY_DEC_SUCCESS_SHIFT)) & VPU_VPU_DEC_RET_QUERY_DEC_SUCCESS_QUERY_DEC_SUCCESS_MASK)
/*! @} */

/*! @name RET_QUEUE_STATUS - Queued command information */
/*! @{ */

#define VPU_VPU_DEC_RET_QUEUE_STATUS_QUEUED_COMMAND_NUM_MASK (0xFFFFU)
#define VPU_VPU_DEC_RET_QUEUE_STATUS_QUEUED_COMMAND_NUM_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUEUE_STATUS_QUEUED_COMMAND_NUM(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUEUE_STATUS_QUEUED_COMMAND_NUM_SHIFT)) & VPU_VPU_DEC_RET_QUEUE_STATUS_QUEUED_COMMAND_NUM_MASK)

#define VPU_VPU_DEC_RET_QUEUE_STATUS_QUEUED_COMMAND_NUM_CURRENT_ISNT_MASK (0xFF0000U)
#define VPU_VPU_DEC_RET_QUEUE_STATUS_QUEUED_COMMAND_NUM_CURRENT_ISNT_SHIFT (16U)
#define VPU_VPU_DEC_RET_QUEUE_STATUS_QUEUED_COMMAND_NUM_CURRENT_ISNT(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUEUE_STATUS_QUEUED_COMMAND_NUM_CURRENT_ISNT_SHIFT)) & VPU_VPU_DEC_RET_QUEUE_STATUS_QUEUED_COMMAND_NUM_CURRENT_ISNT_MASK)
/*! @} */

/*! @name RET_BS_EMPTY - Bitstream buffer empty flag */
/*! @{ */

#define VPU_VPU_DEC_RET_BS_EMPTY_BS_EMPTY_INST_FLAG_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_BS_EMPTY_BS_EMPTY_INST_FLAG_SHIFT (0U)
#define VPU_VPU_DEC_RET_BS_EMPTY_BS_EMPTY_INST_FLAG(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_BS_EMPTY_BS_EMPTY_INST_FLAG_SHIFT)) & VPU_VPU_DEC_RET_BS_EMPTY_BS_EMPTY_INST_FLAG_MASK)
/*! @} */

/*! @name RET_QUEUED_CMD_DONE - Queued command done flag */
/*! @{ */

#define VPU_VPU_DEC_RET_QUEUED_CMD_DONE_QUEUED_CMD_INST_FLAG_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_QUEUED_CMD_DONE_QUEUED_CMD_INST_FLAG_SHIFT (0U)
#define VPU_VPU_DEC_RET_QUEUED_CMD_DONE_QUEUED_CMD_INST_FLAG(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_QUEUED_CMD_DONE_QUEUED_CMD_INST_FLAG_SHIFT)) & VPU_VPU_DEC_RET_QUEUED_CMD_DONE_QUEUED_CMD_INST_FLAG_MASK)
/*! @} */

/*! @name RET_SRC_RELEASE - Flag for source buffer releasing */
/*! @{ */

#define VPU_VPU_DEC_RET_SRC_RELEASE_SRC_RELEASE_INST_FLAG_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_RET_SRC_RELEASE_SRC_RELEASE_INST_FLAG_SHIFT (0U)
#define VPU_VPU_DEC_RET_SRC_RELEASE_SRC_RELEASE_INST_FLAG(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_SRC_RELEASE_SRC_RELEASE_INST_FLAG_SHIFT)) & VPU_VPU_DEC_RET_SRC_RELEASE_SRC_RELEASE_INST_FLAG_MASK)
/*! @} */

/*! @name RET_PARSING_INSTANCE_INFO - A working instance index on prescan stage (for internal use only) */
/*! @{ */

#define VPU_VPU_DEC_RET_PARSING_INSTANCE_INFO_PRES_INST_ID_CORE0_MASK (0xFFU)
#define VPU_VPU_DEC_RET_PARSING_INSTANCE_INFO_PRES_INST_ID_CORE0_SHIFT (0U)
#define VPU_VPU_DEC_RET_PARSING_INSTANCE_INFO_PRES_INST_ID_CORE0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_PARSING_INSTANCE_INFO_PRES_INST_ID_CORE0_SHIFT)) & VPU_VPU_DEC_RET_PARSING_INSTANCE_INFO_PRES_INST_ID_CORE0_MASK)

#define VPU_VPU_DEC_RET_PARSING_INSTANCE_INFO_PRES_INST_ID_CORE1_MASK (0xFF00U)
#define VPU_VPU_DEC_RET_PARSING_INSTANCE_INFO_PRES_INST_ID_CORE1_SHIFT (8U)
#define VPU_VPU_DEC_RET_PARSING_INSTANCE_INFO_PRES_INST_ID_CORE1(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_PARSING_INSTANCE_INFO_PRES_INST_ID_CORE1_SHIFT)) & VPU_VPU_DEC_RET_PARSING_INSTANCE_INFO_PRES_INST_ID_CORE1_MASK)

#define VPU_VPU_DEC_RET_PARSING_INSTANCE_INFO_PRES_INST_ID_CORE2_MASK (0xFF0000U)
#define VPU_VPU_DEC_RET_PARSING_INSTANCE_INFO_PRES_INST_ID_CORE2_SHIFT (16U)
#define VPU_VPU_DEC_RET_PARSING_INSTANCE_INFO_PRES_INST_ID_CORE2(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_PARSING_INSTANCE_INFO_PRES_INST_ID_CORE2_SHIFT)) & VPU_VPU_DEC_RET_PARSING_INSTANCE_INFO_PRES_INST_ID_CORE2_MASK)

#define VPU_VPU_DEC_RET_PARSING_INSTANCE_INFO_PRES_INST_ID_CORE3_MASK (0xFF000000U)
#define VPU_VPU_DEC_RET_PARSING_INSTANCE_INFO_PRES_INST_ID_CORE3_SHIFT (24U)
#define VPU_VPU_DEC_RET_PARSING_INSTANCE_INFO_PRES_INST_ID_CORE3(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_PARSING_INSTANCE_INFO_PRES_INST_ID_CORE3_SHIFT)) & VPU_VPU_DEC_RET_PARSING_INSTANCE_INFO_PRES_INST_ID_CORE3_MASK)
/*! @} */

/*! @name RET_DECODING_INSTANCE_INFO - A working instance index on decoding stage (for internal use only) */
/*! @{ */

#define VPU_VPU_DEC_RET_DECODING_INSTANCE_INFO_DEC_INST_ID_CORE0_MASK (0xFFU)
#define VPU_VPU_DEC_RET_DECODING_INSTANCE_INFO_DEC_INST_ID_CORE0_SHIFT (0U)
#define VPU_VPU_DEC_RET_DECODING_INSTANCE_INFO_DEC_INST_ID_CORE0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_DECODING_INSTANCE_INFO_DEC_INST_ID_CORE0_SHIFT)) & VPU_VPU_DEC_RET_DECODING_INSTANCE_INFO_DEC_INST_ID_CORE0_MASK)

#define VPU_VPU_DEC_RET_DECODING_INSTANCE_INFO_DEC_INST_ID_CORE1_MASK (0xFF00U)
#define VPU_VPU_DEC_RET_DECODING_INSTANCE_INFO_DEC_INST_ID_CORE1_SHIFT (8U)
#define VPU_VPU_DEC_RET_DECODING_INSTANCE_INFO_DEC_INST_ID_CORE1(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_DECODING_INSTANCE_INFO_DEC_INST_ID_CORE1_SHIFT)) & VPU_VPU_DEC_RET_DECODING_INSTANCE_INFO_DEC_INST_ID_CORE1_MASK)

#define VPU_VPU_DEC_RET_DECODING_INSTANCE_INFO_DEC_INST_ID_CORE2_MASK (0xFF0000U)
#define VPU_VPU_DEC_RET_DECODING_INSTANCE_INFO_DEC_INST_ID_CORE2_SHIFT (16U)
#define VPU_VPU_DEC_RET_DECODING_INSTANCE_INFO_DEC_INST_ID_CORE2(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_DECODING_INSTANCE_INFO_DEC_INST_ID_CORE2_SHIFT)) & VPU_VPU_DEC_RET_DECODING_INSTANCE_INFO_DEC_INST_ID_CORE2_MASK)

#define VPU_VPU_DEC_RET_DECODING_INSTANCE_INFO_DEC_INST_ID_CORE3_MASK (0xFF000000U)
#define VPU_VPU_DEC_RET_DECODING_INSTANCE_INFO_DEC_INST_ID_CORE3_SHIFT (24U)
#define VPU_VPU_DEC_RET_DECODING_INSTANCE_INFO_DEC_INST_ID_CORE3(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_DECODING_INSTANCE_INFO_DEC_INST_ID_CORE3_SHIFT)) & VPU_VPU_DEC_RET_DECODING_INSTANCE_INFO_DEC_INST_ID_CORE3_MASK)
/*! @} */

/*! @name RET_ENCODING_INSTANCE_INFO - A working instance index on packing stage (for internal use only) */
/*! @{ */

#define VPU_VPU_DEC_RET_ENCODING_INSTANCE_INFO_PACK_INST_ID_CORE0_MASK (0xFFU)
#define VPU_VPU_DEC_RET_ENCODING_INSTANCE_INFO_PACK_INST_ID_CORE0_SHIFT (0U)
#define VPU_VPU_DEC_RET_ENCODING_INSTANCE_INFO_PACK_INST_ID_CORE0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_ENCODING_INSTANCE_INFO_PACK_INST_ID_CORE0_SHIFT)) & VPU_VPU_DEC_RET_ENCODING_INSTANCE_INFO_PACK_INST_ID_CORE0_MASK)

#define VPU_VPU_DEC_RET_ENCODING_INSTANCE_INFO_PACK_INST_ID_CORE1_MASK (0xFF00U)
#define VPU_VPU_DEC_RET_ENCODING_INSTANCE_INFO_PACK_INST_ID_CORE1_SHIFT (8U)
#define VPU_VPU_DEC_RET_ENCODING_INSTANCE_INFO_PACK_INST_ID_CORE1(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_ENCODING_INSTANCE_INFO_PACK_INST_ID_CORE1_SHIFT)) & VPU_VPU_DEC_RET_ENCODING_INSTANCE_INFO_PACK_INST_ID_CORE1_MASK)

#define VPU_VPU_DEC_RET_ENCODING_INSTANCE_INFO_PACK_INST_ID_CORE2_MASK (0xFF0000U)
#define VPU_VPU_DEC_RET_ENCODING_INSTANCE_INFO_PACK_INST_ID_CORE2_SHIFT (16U)
#define VPU_VPU_DEC_RET_ENCODING_INSTANCE_INFO_PACK_INST_ID_CORE2(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_ENCODING_INSTANCE_INFO_PACK_INST_ID_CORE2_SHIFT)) & VPU_VPU_DEC_RET_ENCODING_INSTANCE_INFO_PACK_INST_ID_CORE2_MASK)

#define VPU_VPU_DEC_RET_ENCODING_INSTANCE_INFO_PACK_INST_ID_CORE3_MASK (0xFF000000U)
#define VPU_VPU_DEC_RET_ENCODING_INSTANCE_INFO_PACK_INST_ID_CORE3_SHIFT (24U)
#define VPU_VPU_DEC_RET_ENCODING_INSTANCE_INFO_PACK_INST_ID_CORE3(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_ENCODING_INSTANCE_INFO_PACK_INST_ID_CORE3_SHIFT)) & VPU_VPU_DEC_RET_ENCODING_INSTANCE_INFO_PACK_INST_ID_CORE3_MASK)
/*! @} */

/*! @name RET_DONE_INSTANCE_INFO - Done interrupt instance index */
/*! @{ */

#define VPU_VPU_DEC_RET_DONE_INSTANCE_INFO_DONE_INST_IDX_MASK (0x1FU)
#define VPU_VPU_DEC_RET_DONE_INSTANCE_INFO_DONE_INST_IDX_SHIFT (0U)
#define VPU_VPU_DEC_RET_DONE_INSTANCE_INFO_DONE_INST_IDX(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_RET_DONE_INSTANCE_INFO_DONE_INST_IDX_SHIFT)) & VPU_VPU_DEC_RET_DONE_INSTANCE_INFO_DONE_INST_IDX_MASK)
/*! @} */

/*! @name VPU_RESET_REQ - VPU Reset Request */
/*! @{ */

#define VPU_VPU_DEC_VPU_RESET_REQ_CRST_REQ_MASK  (0xFFU)
#define VPU_VPU_DEC_VPU_RESET_REQ_CRST_REQ_SHIFT (0U)
#define VPU_VPU_DEC_VPU_RESET_REQ_CRST_REQ(x)    (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_RESET_REQ_CRST_REQ_SHIFT)) & VPU_VPU_DEC_VPU_RESET_REQ_CRST_REQ_MASK)

#define VPU_VPU_DEC_VPU_RESET_REQ_BRST_REQ_MASK  (0xFF00U)
#define VPU_VPU_DEC_VPU_RESET_REQ_BRST_REQ_SHIFT (8U)
#define VPU_VPU_DEC_VPU_RESET_REQ_BRST_REQ(x)    (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_RESET_REQ_BRST_REQ_SHIFT)) & VPU_VPU_DEC_VPU_RESET_REQ_BRST_REQ_MASK)

#define VPU_VPU_DEC_VPU_RESET_REQ_ARST_REQ_MASK  (0xFF0000U)
#define VPU_VPU_DEC_VPU_RESET_REQ_ARST_REQ_SHIFT (16U)
#define VPU_VPU_DEC_VPU_RESET_REQ_ARST_REQ(x)    (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_RESET_REQ_ARST_REQ_SHIFT)) & VPU_VPU_DEC_VPU_RESET_REQ_ARST_REQ_MASK)

#define VPU_VPU_DEC_VPU_RESET_REQ_VARST_REQ1_MASK (0x1000000U)
#define VPU_VPU_DEC_VPU_RESET_REQ_VARST_REQ1_SHIFT (24U)
#define VPU_VPU_DEC_VPU_RESET_REQ_VARST_REQ1(x)  (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_RESET_REQ_VARST_REQ1_SHIFT)) & VPU_VPU_DEC_VPU_RESET_REQ_VARST_REQ1_MASK)

#define VPU_VPU_DEC_VPU_RESET_REQ_VBRST_REQ1_MASK (0x2000000U)
#define VPU_VPU_DEC_VPU_RESET_REQ_VBRST_REQ1_SHIFT (25U)
#define VPU_VPU_DEC_VPU_RESET_REQ_VBRST_REQ1(x)  (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_RESET_REQ_VBRST_REQ1_SHIFT)) & VPU_VPU_DEC_VPU_RESET_REQ_VBRST_REQ1_MASK)

#define VPU_VPU_DEC_VPU_RESET_REQ_VARST_REQ0_MASK (0x4000000U)
#define VPU_VPU_DEC_VPU_RESET_REQ_VARST_REQ0_SHIFT (26U)
#define VPU_VPU_DEC_VPU_RESET_REQ_VARST_REQ0(x)  (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_RESET_REQ_VARST_REQ0_SHIFT)) & VPU_VPU_DEC_VPU_RESET_REQ_VARST_REQ0_MASK)

#define VPU_VPU_DEC_VPU_RESET_REQ_VBRST_REQ0_MASK (0x8000000U)
#define VPU_VPU_DEC_VPU_RESET_REQ_VBRST_REQ0_SHIFT (27U)
#define VPU_VPU_DEC_VPU_RESET_REQ_VBRST_REQ0(x)  (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_RESET_REQ_VBRST_REQ0_SHIFT)) & VPU_VPU_DEC_VPU_RESET_REQ_VBRST_REQ0_MASK)
/*! @} */

/*! @name VPU_RESET_STATUS - VPU Reset Status */
/*! @{ */

#define VPU_VPU_DEC_VPU_RESET_STATUS_CRST_STS_MASK (0xFFU)
#define VPU_VPU_DEC_VPU_RESET_STATUS_CRST_STS_SHIFT (0U)
#define VPU_VPU_DEC_VPU_RESET_STATUS_CRST_STS(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_RESET_STATUS_CRST_STS_SHIFT)) & VPU_VPU_DEC_VPU_RESET_STATUS_CRST_STS_MASK)

#define VPU_VPU_DEC_VPU_RESET_STATUS_BRST_STS_MASK (0xFF00U)
#define VPU_VPU_DEC_VPU_RESET_STATUS_BRST_STS_SHIFT (8U)
#define VPU_VPU_DEC_VPU_RESET_STATUS_BRST_STS(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_RESET_STATUS_BRST_STS_SHIFT)) & VPU_VPU_DEC_VPU_RESET_STATUS_BRST_STS_MASK)

#define VPU_VPU_DEC_VPU_RESET_STATUS_ARST_STS_MASK (0xFF0000U)
#define VPU_VPU_DEC_VPU_RESET_STATUS_ARST_STS_SHIFT (16U)
#define VPU_VPU_DEC_VPU_RESET_STATUS_ARST_STS(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_RESET_STATUS_ARST_STS_SHIFT)) & VPU_VPU_DEC_VPU_RESET_STATUS_ARST_STS_MASK)

#define VPU_VPU_DEC_VPU_RESET_STATUS_VARST_STS1_MASK (0x1000000U)
#define VPU_VPU_DEC_VPU_RESET_STATUS_VARST_STS1_SHIFT (24U)
#define VPU_VPU_DEC_VPU_RESET_STATUS_VARST_STS1(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_RESET_STATUS_VARST_STS1_SHIFT)) & VPU_VPU_DEC_VPU_RESET_STATUS_VARST_STS1_MASK)

#define VPU_VPU_DEC_VPU_RESET_STATUS_VBRST_STS1_MASK (0x2000000U)
#define VPU_VPU_DEC_VPU_RESET_STATUS_VBRST_STS1_SHIFT (25U)
#define VPU_VPU_DEC_VPU_RESET_STATUS_VBRST_STS1(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_RESET_STATUS_VBRST_STS1_SHIFT)) & VPU_VPU_DEC_VPU_RESET_STATUS_VBRST_STS1_MASK)

#define VPU_VPU_DEC_VPU_RESET_STATUS_VARST_STS0_MASK (0x4000000U)
#define VPU_VPU_DEC_VPU_RESET_STATUS_VARST_STS0_SHIFT (26U)
#define VPU_VPU_DEC_VPU_RESET_STATUS_VARST_STS0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_RESET_STATUS_VARST_STS0_SHIFT)) & VPU_VPU_DEC_VPU_RESET_STATUS_VARST_STS0_MASK)

#define VPU_VPU_DEC_VPU_RESET_STATUS_VBRST_STS0_MASK (0x8000000U)
#define VPU_VPU_DEC_VPU_RESET_STATUS_VBRST_STS0_SHIFT (27U)
#define VPU_VPU_DEC_VPU_RESET_STATUS_VBRST_STS0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_RESET_STATUS_VBRST_STS0_SHIFT)) & VPU_VPU_DEC_VPU_RESET_STATUS_VBRST_STS0_MASK)
/*! @} */

/*! @name VCPU_RESTART - V-CPU Restart Request */
/*! @{ */

#define VPU_VPU_DEC_VCPU_RESTART_VCPU_RESTART_MASK (0x1U)
#define VPU_VPU_DEC_VCPU_RESTART_VCPU_RESTART_SHIFT (0U)
#define VPU_VPU_DEC_VCPU_RESTART_VCPU_RESTART(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VCPU_RESTART_VCPU_RESTART_SHIFT)) & VPU_VPU_DEC_VCPU_RESTART_VCPU_RESTART_MASK)
/*! @} */

/*! @name VPU_CLK_MASK - VPU Clock Control */
/*! @{ */

#define VPU_VPU_DEC_VPU_CLK_MASK_CCLK_EN_MASK    (0xFFU)
#define VPU_VPU_DEC_VPU_CLK_MASK_CCLK_EN_SHIFT   (0U)
#define VPU_VPU_DEC_VPU_CLK_MASK_CCLK_EN(x)      (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_CLK_MASK_CCLK_EN_SHIFT)) & VPU_VPU_DEC_VPU_CLK_MASK_CCLK_EN_MASK)

#define VPU_VPU_DEC_VPU_CLK_MASK_BCLK_EN_MASK    (0xFF00U)
#define VPU_VPU_DEC_VPU_CLK_MASK_BCLK_EN_SHIFT   (8U)
#define VPU_VPU_DEC_VPU_CLK_MASK_BCLK_EN(x)      (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_CLK_MASK_BCLK_EN_SHIFT)) & VPU_VPU_DEC_VPU_CLK_MASK_BCLK_EN_MASK)

#define VPU_VPU_DEC_VPU_CLK_MASK_ACLK_EN_MASK    (0xFF0000U)
#define VPU_VPU_DEC_VPU_CLK_MASK_ACLK_EN_SHIFT   (16U)
#define VPU_VPU_DEC_VPU_CLK_MASK_ACLK_EN(x)      (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_CLK_MASK_ACLK_EN_SHIFT)) & VPU_VPU_DEC_VPU_CLK_MASK_ACLK_EN_MASK)

#define VPU_VPU_DEC_VPU_CLK_MASK_ACLK_CPU_EN_MASK (0x1000000U)
#define VPU_VPU_DEC_VPU_CLK_MASK_ACLK_CPU_EN_SHIFT (24U)
#define VPU_VPU_DEC_VPU_CLK_MASK_ACLK_CPU_EN(x)  (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_CLK_MASK_ACLK_CPU_EN_SHIFT)) & VPU_VPU_DEC_VPU_CLK_MASK_ACLK_CPU_EN_MASK)

#define VPU_VPU_DEC_VPU_CLK_MASK_VCLK_CPU_EN_MASK (0x2000000U)
#define VPU_VPU_DEC_VPU_CLK_MASK_VCLK_CPU_EN_SHIFT (25U)
#define VPU_VPU_DEC_VPU_CLK_MASK_VCLK_CPU_EN(x)  (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_CLK_MASK_VCLK_CPU_EN_SHIFT)) & VPU_VPU_DEC_VPU_CLK_MASK_VCLK_CPU_EN_MASK)

#define VPU_VPU_DEC_VPU_CLK_MASK_CCLK_CPU_EN_MASK (0x4000000U)
#define VPU_VPU_DEC_VPU_CLK_MASK_CCLK_CPU_EN_SHIFT (26U)
#define VPU_VPU_DEC_VPU_CLK_MASK_CCLK_CPU_EN(x)  (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_CLK_MASK_CCLK_CPU_EN_SHIFT)) & VPU_VPU_DEC_VPU_CLK_MASK_CCLK_CPU_EN_MASK)
/*! @} */

/*! @name VPU_REMAP_CTRL - Remap Control */
/*! @{ */

#define VPU_VPU_DEC_VPU_REMAP_CTRL_REMAP_PSIZE_MASK (0x1FFU)
#define VPU_VPU_DEC_VPU_REMAP_CTRL_REMAP_PSIZE_SHIFT (0U)
#define VPU_VPU_DEC_VPU_REMAP_CTRL_REMAP_PSIZE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_REMAP_CTRL_REMAP_PSIZE_SHIFT)) & VPU_VPU_DEC_VPU_REMAP_CTRL_REMAP_PSIZE_MASK)

#define VPU_VPU_DEC_VPU_REMAP_CTRL_REMAP_BUS_ERR_MASK (0x200U)
#define VPU_VPU_DEC_VPU_REMAP_CTRL_REMAP_BUS_ERR_SHIFT (9U)
#define VPU_VPU_DEC_VPU_REMAP_CTRL_REMAP_BUS_ERR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_REMAP_CTRL_REMAP_BUS_ERR_SHIFT)) & VPU_VPU_DEC_VPU_REMAP_CTRL_REMAP_BUS_ERR_MASK)

#define VPU_VPU_DEC_VPU_REMAP_CTRL_REMAP_BYPASS_MASK (0x400U)
#define VPU_VPU_DEC_VPU_REMAP_CTRL_REMAP_BYPASS_SHIFT (10U)
#define VPU_VPU_DEC_VPU_REMAP_CTRL_REMAP_BYPASS(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_REMAP_CTRL_REMAP_BYPASS_SHIFT)) & VPU_VPU_DEC_VPU_REMAP_CTRL_REMAP_BYPASS_MASK)

#define VPU_VPU_DEC_VPU_REMAP_CTRL_EN_REMAP_SIZE_MASK (0x800U)
#define VPU_VPU_DEC_VPU_REMAP_CTRL_EN_REMAP_SIZE_SHIFT (11U)
#define VPU_VPU_DEC_VPU_REMAP_CTRL_EN_REMAP_SIZE(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_REMAP_CTRL_EN_REMAP_SIZE_SHIFT)) & VPU_VPU_DEC_VPU_REMAP_CTRL_EN_REMAP_SIZE_MASK)

#define VPU_VPU_DEC_VPU_REMAP_CTRL_REMAP_IDX_MASK (0x3000U)
#define VPU_VPU_DEC_VPU_REMAP_CTRL_REMAP_IDX_SHIFT (12U)
#define VPU_VPU_DEC_VPU_REMAP_CTRL_REMAP_IDX(x)  (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_REMAP_CTRL_REMAP_IDX_SHIFT)) & VPU_VPU_DEC_VPU_REMAP_CTRL_REMAP_IDX_MASK)

#define VPU_VPU_DEC_VPU_REMAP_CTRL_RSVD1_MASK    (0xC000U)
#define VPU_VPU_DEC_VPU_REMAP_CTRL_RSVD1_SHIFT   (14U)
#define VPU_VPU_DEC_VPU_REMAP_CTRL_RSVD1(x)      (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_REMAP_CTRL_RSVD1_SHIFT)) & VPU_VPU_DEC_VPU_REMAP_CTRL_RSVD1_MASK)

#define VPU_VPU_DEC_VPU_REMAP_CTRL_ENDIAN_MASK   (0xF0000U)
#define VPU_VPU_DEC_VPU_REMAP_CTRL_ENDIAN_SHIFT  (16U)
#define VPU_VPU_DEC_VPU_REMAP_CTRL_ENDIAN(x)     (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_REMAP_CTRL_ENDIAN_SHIFT)) & VPU_VPU_DEC_VPU_REMAP_CTRL_ENDIAN_MASK)

#define VPU_VPU_DEC_VPU_REMAP_CTRL_AXIID_PROC_MASK (0xF00000U)
#define VPU_VPU_DEC_VPU_REMAP_CTRL_AXIID_PROC_SHIFT (20U)
#define VPU_VPU_DEC_VPU_REMAP_CTRL_AXIID_PROC(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_REMAP_CTRL_AXIID_PROC_SHIFT)) & VPU_VPU_DEC_VPU_REMAP_CTRL_AXIID_PROC_MASK)

#define VPU_VPU_DEC_VPU_REMAP_CTRL_RSVD0_MASK    (0x1F000000U)
#define VPU_VPU_DEC_VPU_REMAP_CTRL_RSVD0_SHIFT   (24U)
#define VPU_VPU_DEC_VPU_REMAP_CTRL_RSVD0(x)      (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_REMAP_CTRL_RSVD0_SHIFT)) & VPU_VPU_DEC_VPU_REMAP_CTRL_RSVD0_MASK)

#define VPU_VPU_DEC_VPU_REMAP_CTRL_REMAP_INF_ERR_MASK (0x20000000U)
#define VPU_VPU_DEC_VPU_REMAP_CTRL_REMAP_INF_ERR_SHIFT (29U)
#define VPU_VPU_DEC_VPU_REMAP_CTRL_REMAP_INF_ERR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_REMAP_CTRL_REMAP_INF_ERR_SHIFT)) & VPU_VPU_DEC_VPU_REMAP_CTRL_REMAP_INF_ERR_MASK)

#define VPU_VPU_DEC_VPU_REMAP_CTRL_REMAP_INF_BYPASS_MASK (0x40000000U)
#define VPU_VPU_DEC_VPU_REMAP_CTRL_REMAP_INF_BYPASS_SHIFT (30U)
#define VPU_VPU_DEC_VPU_REMAP_CTRL_REMAP_INF_BYPASS(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_REMAP_CTRL_REMAP_INF_BYPASS_SHIFT)) & VPU_VPU_DEC_VPU_REMAP_CTRL_REMAP_INF_BYPASS_MASK)

#define VPU_VPU_DEC_VPU_REMAP_CTRL_EN_REMAP_INFO_MASK (0x80000000U)
#define VPU_VPU_DEC_VPU_REMAP_CTRL_EN_REMAP_INFO_SHIFT (31U)
#define VPU_VPU_DEC_VPU_REMAP_CTRL_EN_REMAP_INFO(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_REMAP_CTRL_EN_REMAP_INFO_SHIFT)) & VPU_VPU_DEC_VPU_REMAP_CTRL_EN_REMAP_INFO_MASK)
/*! @} */

/*! @name VPU_REMAP_VADDR - Remap Virutal Address */
/*! @{ */

#define VPU_VPU_DEC_VPU_REMAP_VADDR_VPU_REMAP_VADDR_MASK (0xFFFFF000U)
#define VPU_VPU_DEC_VPU_REMAP_VADDR_VPU_REMAP_VADDR_SHIFT (12U)
#define VPU_VPU_DEC_VPU_REMAP_VADDR_VPU_REMAP_VADDR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_REMAP_VADDR_VPU_REMAP_VADDR_SHIFT)) & VPU_VPU_DEC_VPU_REMAP_VADDR_VPU_REMAP_VADDR_MASK)
/*! @} */

/*! @name VPU_REMAP_PADDR - Remap Physical Address */
/*! @{ */

#define VPU_VPU_DEC_VPU_REMAP_PADDR_VPU_REMAP_PADDR_MASK (0xFFFFF000U)
#define VPU_VPU_DEC_VPU_REMAP_PADDR_VPU_REMAP_PADDR_SHIFT (12U)
#define VPU_VPU_DEC_VPU_REMAP_PADDR_VPU_REMAP_PADDR(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_REMAP_PADDR_VPU_REMAP_PADDR_SHIFT)) & VPU_VPU_DEC_VPU_REMAP_PADDR_VPU_REMAP_PADDR_MASK)
/*! @} */

/*! @name VPU_REMAP_CORE_START - VPU Start Request */
/*! @{ */

#define VPU_VPU_DEC_VPU_REMAP_CORE_START_VPU_REMAP_CORE_START_MASK (0x1U)
#define VPU_VPU_DEC_VPU_REMAP_CORE_START_VPU_REMAP_CORE_START_SHIFT (0U)
#define VPU_VPU_DEC_VPU_REMAP_CORE_START_VPU_REMAP_CORE_START(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_REMAP_CORE_START_VPU_REMAP_CORE_START_SHIFT)) & VPU_VPU_DEC_VPU_REMAP_CORE_START_VPU_REMAP_CORE_START_MASK)
/*! @} */

/*! @name VPU_BUSY_STATUS - VPU Busy Status */
/*! @{ */

#define VPU_VPU_DEC_VPU_BUSY_STATUS_VPU_BUSY_STATUS_MASK (0x1U)
#define VPU_VPU_DEC_VPU_BUSY_STATUS_VPU_BUSY_STATUS_SHIFT (0U)
#define VPU_VPU_DEC_VPU_BUSY_STATUS_VPU_BUSY_STATUS(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_BUSY_STATUS_VPU_BUSY_STATUS_SHIFT)) & VPU_VPU_DEC_VPU_BUSY_STATUS_VPU_BUSY_STATUS_MASK)
/*! @} */

/*! @name VPU_GLOBAL_H_COMMAND - Global Command */
/*! @{ */

#define VPU_VPU_DEC_VPU_GLOBAL_H_COMMAND_GLOBAL_COMMAND_MASK (0xFFFFFFFFU)
#define VPU_VPU_DEC_VPU_GLOBAL_H_COMMAND_GLOBAL_COMMAND_SHIFT (0U)
#define VPU_VPU_DEC_VPU_GLOBAL_H_COMMAND_GLOBAL_COMMAND(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_VPU_GLOBAL_H_COMMAND_GLOBAL_COMMAND_SHIFT)) & VPU_VPU_DEC_VPU_GLOBAL_H_COMMAND_GLOBAL_COMMAND_MASK)
/*! @} */

/*! @name BACKBONE_BUS_CTRL_VCORE - Backbone bus control register for VCORE */
/*! @{ */

#define VPU_VPU_DEC_BACKBONE_BUS_CTRL_VCORE_NO_MORE_REQ0_MASK (0x1U)
#define VPU_VPU_DEC_BACKBONE_BUS_CTRL_VCORE_NO_MORE_REQ0_SHIFT (0U)
#define VPU_VPU_DEC_BACKBONE_BUS_CTRL_VCORE_NO_MORE_REQ0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_BACKBONE_BUS_CTRL_VCORE_NO_MORE_REQ0_SHIFT)) & VPU_VPU_DEC_BACKBONE_BUS_CTRL_VCORE_NO_MORE_REQ0_MASK)

#define VPU_VPU_DEC_BACKBONE_BUS_CTRL_VCORE_NO_MORE_REQ1_MASK (0x2U)
#define VPU_VPU_DEC_BACKBONE_BUS_CTRL_VCORE_NO_MORE_REQ1_SHIFT (1U)
#define VPU_VPU_DEC_BACKBONE_BUS_CTRL_VCORE_NO_MORE_REQ1(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_BACKBONE_BUS_CTRL_VCORE_NO_MORE_REQ1_SHIFT)) & VPU_VPU_DEC_BACKBONE_BUS_CTRL_VCORE_NO_MORE_REQ1_MASK)

#define VPU_VPU_DEC_BACKBONE_BUS_CTRL_VCORE_NO_MORE_REQ2_MASK (0x4U)
#define VPU_VPU_DEC_BACKBONE_BUS_CTRL_VCORE_NO_MORE_REQ2_SHIFT (2U)
#define VPU_VPU_DEC_BACKBONE_BUS_CTRL_VCORE_NO_MORE_REQ2(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_BACKBONE_BUS_CTRL_VCORE_NO_MORE_REQ2_SHIFT)) & VPU_VPU_DEC_BACKBONE_BUS_CTRL_VCORE_NO_MORE_REQ2_MASK)
/*! @} */

/*! @name BACKBONE_BUS_STATUS_VCORE - Backbone bus status register for VCORE */
/*! @{ */

#define VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCORE_EMPTY_FLAG0_MASK (0x1U)
#define VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCORE_EMPTY_FLAG0_SHIFT (0U)
#define VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCORE_EMPTY_FLAG0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCORE_EMPTY_FLAG0_SHIFT)) & VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCORE_EMPTY_FLAG0_MASK)

#define VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCORE_EMPTY_FLAG1_MASK (0x2U)
#define VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCORE_EMPTY_FLAG1_SHIFT (1U)
#define VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCORE_EMPTY_FLAG1(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCORE_EMPTY_FLAG1_SHIFT)) & VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCORE_EMPTY_FLAG1_MASK)

#define VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCORE_EMPTY_FLAG2_MASK (0x4U)
#define VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCORE_EMPTY_FLAG2_SHIFT (2U)
#define VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCORE_EMPTY_FLAG2(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCORE_EMPTY_FLAG2_SHIFT)) & VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCORE_EMPTY_FLAG2_MASK)

#define VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCORE_EMPTY_FLAG3_MASK (0x8U)
#define VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCORE_EMPTY_FLAG3_SHIFT (3U)
#define VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCORE_EMPTY_FLAG3(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCORE_EMPTY_FLAG3_SHIFT)) & VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCORE_EMPTY_FLAG3_MASK)

#define VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCORE_EMPTY_FLAG4_MASK (0x10U)
#define VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCORE_EMPTY_FLAG4_SHIFT (4U)
#define VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCORE_EMPTY_FLAG4(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCORE_EMPTY_FLAG4_SHIFT)) & VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCORE_EMPTY_FLAG4_MASK)

#define VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCORE_EMPTY_FLAG5_MASK (0x20U)
#define VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCORE_EMPTY_FLAG5_SHIFT (5U)
#define VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCORE_EMPTY_FLAG5(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCORE_EMPTY_FLAG5_SHIFT)) & VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCORE_EMPTY_FLAG5_MASK)

#define VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCORE_BUSY_FLAG6_MASK (0x40U)
#define VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCORE_BUSY_FLAG6_SHIFT (6U)
#define VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCORE_BUSY_FLAG6(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCORE_BUSY_FLAG6_SHIFT)) & VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCORE_BUSY_FLAG6_MASK)

#define VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCORE_BUSY_FLAG7_MASK (0x80U)
#define VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCORE_BUSY_FLAG7_SHIFT (7U)
#define VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCORE_BUSY_FLAG7(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCORE_BUSY_FLAG7_SHIFT)) & VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCORE_BUSY_FLAG7_MASK)

#define VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCORE_RSVD0_MASK (0x700U)
#define VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCORE_RSVD0_SHIFT (8U)
#define VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCORE_RSVD0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCORE_RSVD0_SHIFT)) & VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCORE_RSVD0_MASK)

#define VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCORE_BUSY_FLAG11_MASK (0x800U)
#define VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCORE_BUSY_FLAG11_SHIFT (11U)
#define VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCORE_BUSY_FLAG11(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCORE_BUSY_FLAG11_SHIFT)) & VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCORE_BUSY_FLAG11_MASK)
/*! @} */

/*! @name BACKBONE_BUS_CTRL_VCPU - Backbone bus control register for VCPU */
/*! @{ */

#define VPU_VPU_DEC_BACKBONE_BUS_CTRL_VCPU_NO_MORE_REQ0_MASK (0x1U)
#define VPU_VPU_DEC_BACKBONE_BUS_CTRL_VCPU_NO_MORE_REQ0_SHIFT (0U)
#define VPU_VPU_DEC_BACKBONE_BUS_CTRL_VCPU_NO_MORE_REQ0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_BACKBONE_BUS_CTRL_VCPU_NO_MORE_REQ0_SHIFT)) & VPU_VPU_DEC_BACKBONE_BUS_CTRL_VCPU_NO_MORE_REQ0_MASK)

#define VPU_VPU_DEC_BACKBONE_BUS_CTRL_VCPU_NO_MORE_REQ1_MASK (0x2U)
#define VPU_VPU_DEC_BACKBONE_BUS_CTRL_VCPU_NO_MORE_REQ1_SHIFT (1U)
#define VPU_VPU_DEC_BACKBONE_BUS_CTRL_VCPU_NO_MORE_REQ1(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_BACKBONE_BUS_CTRL_VCPU_NO_MORE_REQ1_SHIFT)) & VPU_VPU_DEC_BACKBONE_BUS_CTRL_VCPU_NO_MORE_REQ1_MASK)

#define VPU_VPU_DEC_BACKBONE_BUS_CTRL_VCPU_NO_MORE_REQ2_MASK (0x4U)
#define VPU_VPU_DEC_BACKBONE_BUS_CTRL_VCPU_NO_MORE_REQ2_SHIFT (2U)
#define VPU_VPU_DEC_BACKBONE_BUS_CTRL_VCPU_NO_MORE_REQ2(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_BACKBONE_BUS_CTRL_VCPU_NO_MORE_REQ2_SHIFT)) & VPU_VPU_DEC_BACKBONE_BUS_CTRL_VCPU_NO_MORE_REQ2_MASK)

#define VPU_VPU_DEC_BACKBONE_BUS_CTRL_VCPU_NO_MORE_REQ3_MASK (0x8U)
#define VPU_VPU_DEC_BACKBONE_BUS_CTRL_VCPU_NO_MORE_REQ3_SHIFT (3U)
#define VPU_VPU_DEC_BACKBONE_BUS_CTRL_VCPU_NO_MORE_REQ3(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_BACKBONE_BUS_CTRL_VCPU_NO_MORE_REQ3_SHIFT)) & VPU_VPU_DEC_BACKBONE_BUS_CTRL_VCPU_NO_MORE_REQ3_MASK)

#define VPU_VPU_DEC_BACKBONE_BUS_CTRL_VCPU_NO_MORE_REQ4_MASK (0x10U)
#define VPU_VPU_DEC_BACKBONE_BUS_CTRL_VCPU_NO_MORE_REQ4_SHIFT (4U)
#define VPU_VPU_DEC_BACKBONE_BUS_CTRL_VCPU_NO_MORE_REQ4(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_BACKBONE_BUS_CTRL_VCPU_NO_MORE_REQ4_SHIFT)) & VPU_VPU_DEC_BACKBONE_BUS_CTRL_VCPU_NO_MORE_REQ4_MASK)

#define VPU_VPU_DEC_BACKBONE_BUS_CTRL_VCPU_NO_MORE_REQ5_MASK (0x20U)
#define VPU_VPU_DEC_BACKBONE_BUS_CTRL_VCPU_NO_MORE_REQ5_SHIFT (5U)
#define VPU_VPU_DEC_BACKBONE_BUS_CTRL_VCPU_NO_MORE_REQ5(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_BACKBONE_BUS_CTRL_VCPU_NO_MORE_REQ5_SHIFT)) & VPU_VPU_DEC_BACKBONE_BUS_CTRL_VCPU_NO_MORE_REQ5_MASK)

#define VPU_VPU_DEC_BACKBONE_BUS_CTRL_VCPU_NO_MORE_REQ6_MASK (0x40U)
#define VPU_VPU_DEC_BACKBONE_BUS_CTRL_VCPU_NO_MORE_REQ6_SHIFT (6U)
#define VPU_VPU_DEC_BACKBONE_BUS_CTRL_VCPU_NO_MORE_REQ6(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_BACKBONE_BUS_CTRL_VCPU_NO_MORE_REQ6_SHIFT)) & VPU_VPU_DEC_BACKBONE_BUS_CTRL_VCPU_NO_MORE_REQ6_MASK)

#define VPU_VPU_DEC_BACKBONE_BUS_CTRL_VCPU_NO_MORE_REQ7_MASK (0x80U)
#define VPU_VPU_DEC_BACKBONE_BUS_CTRL_VCPU_NO_MORE_REQ7_SHIFT (7U)
#define VPU_VPU_DEC_BACKBONE_BUS_CTRL_VCPU_NO_MORE_REQ7(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_BACKBONE_BUS_CTRL_VCPU_NO_MORE_REQ7_SHIFT)) & VPU_VPU_DEC_BACKBONE_BUS_CTRL_VCPU_NO_MORE_REQ7_MASK)
/*! @} */

/*! @name BACKBONE_BUS_STATUS_VCPU - Backbone bus status register for VCPU */
/*! @{ */

#define VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCPU_EMPTY_FLAG0_MASK (0x1U)
#define VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCPU_EMPTY_FLAG0_SHIFT (0U)
#define VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCPU_EMPTY_FLAG0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCPU_EMPTY_FLAG0_SHIFT)) & VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCPU_EMPTY_FLAG0_MASK)

#define VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCPU_EMPTY_FLAG1_MASK (0x2U)
#define VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCPU_EMPTY_FLAG1_SHIFT (1U)
#define VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCPU_EMPTY_FLAG1(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCPU_EMPTY_FLAG1_SHIFT)) & VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCPU_EMPTY_FLAG1_MASK)

#define VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCPU_EMPTY_FLAG2_MASK (0x4U)
#define VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCPU_EMPTY_FLAG2_SHIFT (2U)
#define VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCPU_EMPTY_FLAG2(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCPU_EMPTY_FLAG2_SHIFT)) & VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCPU_EMPTY_FLAG2_MASK)

#define VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCPU_EMPTY_FLAG3_MASK (0x8U)
#define VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCPU_EMPTY_FLAG3_SHIFT (3U)
#define VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCPU_EMPTY_FLAG3(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCPU_EMPTY_FLAG3_SHIFT)) & VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCPU_EMPTY_FLAG3_MASK)

#define VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCPU_EMPTY_FLAG4_MASK (0x10U)
#define VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCPU_EMPTY_FLAG4_SHIFT (4U)
#define VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCPU_EMPTY_FLAG4(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCPU_EMPTY_FLAG4_SHIFT)) & VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCPU_EMPTY_FLAG4_MASK)

#define VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCPU_EMPTY_FLAG5_MASK (0x20U)
#define VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCPU_EMPTY_FLAG5_SHIFT (5U)
#define VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCPU_EMPTY_FLAG5(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCPU_EMPTY_FLAG5_SHIFT)) & VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCPU_EMPTY_FLAG5_MASK)

#define VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCPU_EMPTY_FLAG6_MASK (0x40U)
#define VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCPU_EMPTY_FLAG6_SHIFT (6U)
#define VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCPU_EMPTY_FLAG6(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCPU_EMPTY_FLAG6_SHIFT)) & VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCPU_EMPTY_FLAG6_MASK)

#define VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCPU_EMPTY_FLAG7_MASK (0x80U)
#define VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCPU_EMPTY_FLAG7_SHIFT (7U)
#define VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCPU_EMPTY_FLAG7(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCPU_EMPTY_FLAG7_SHIFT)) & VPU_VPU_DEC_BACKBONE_BUS_STATUS_VCPU_EMPTY_FLAG7_MASK)
/*! @} */

/*! @name BACKBONE_BUS_PROC_EXT_ADDR - Backbone bus status register for VCPU */
/*! @{ */

#define VPU_VPU_DEC_BACKBONE_BUS_PROC_EXT_ADDR_BACKBONE_BUS_PROC_MASK (0xFFU)
#define VPU_VPU_DEC_BACKBONE_BUS_PROC_EXT_ADDR_BACKBONE_BUS_PROC_SHIFT (0U)
#define VPU_VPU_DEC_BACKBONE_BUS_PROC_EXT_ADDR_BACKBONE_BUS_PROC(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_BACKBONE_BUS_PROC_EXT_ADDR_BACKBONE_BUS_PROC_SHIFT)) & VPU_VPU_DEC_BACKBONE_BUS_PROC_EXT_ADDR_BACKBONE_BUS_PROC_MASK)

#define VPU_VPU_DEC_BACKBONE_BUS_PROC_EXT_ADDR_RSVD0_MASK (0xFFFFFF00U)
#define VPU_VPU_DEC_BACKBONE_BUS_PROC_EXT_ADDR_RSVD0_SHIFT (8U)
#define VPU_VPU_DEC_BACKBONE_BUS_PROC_EXT_ADDR_RSVD0(x) (((uint32_t)(((uint32_t)(x)) << VPU_VPU_DEC_BACKBONE_BUS_PROC_EXT_ADDR_RSVD0_SHIFT)) & VPU_VPU_DEC_BACKBONE_BUS_PROC_EXT_ADDR_RSVD0_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group VPU_VPU_DEC_Register_Masks */


/*!
 * @}
 */ /* end of group VPU_VPU_DEC_Peripheral_Access_Layer */


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


#endif  /* PERI_VPU_VPU_DEC_H_ */

