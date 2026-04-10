/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K39_DSPSS.h
 * @version 1.7
 * @date 2022-11-18
 * @brief Peripheral Access Layer for S32K39_DSPSS
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
#if !defined(S32K39_DSPSS_H_)  /* Check if memory map has not been already included */
#define S32K39_DSPSS_H_

#include "S32K39_COMMON.h"

/* ----------------------------------------------------------------------------
   -- DSPSS Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DSPSS_Peripheral_Access_Layer DSPSS Peripheral Access Layer
 * @{
 */

/** DSPSS - Size of Registers Arrays */
#define DSPSS_DSPSS_DSP_THREAD_INFO_COUNT         4u

/** DSPSS - Register Layout Typedef */
typedef struct {
  __IO uint32_t DSPSS_SCHEDULER_XMEM_ADDR_TH0;     /**< Thread Start And End Address Location Configuration, offset: 0x0 */
  __IO uint32_t DSPSS_SCHEDULER_XMEM_TH0;          /**< Thread Threshold And Enable, offset: 0x4 */
  __IO uint32_t DSPSS_SCHEDULER_DSP_CFG_TH0;       /**< PC Initial Value, offset: 0x8 */
  __I  uint32_t DSPSS_SCHEDULER_CURR_XMEM_ADDR_TH0; /**< Current XMEM Write Pointer, offset: 0xC */
  uint8_t RESERVED_0[4];
  __I  uint32_t DSP_SDADC_CURR_READ_PTR0;          /**< Last Scheduled-Request Address, offset: 0x14 */
  uint8_t RESERVED_1[4];
  __IO uint32_t DSP_CORE_BUF_ADDR0;                /**< Start And End Pointers For DSP And Cortex-M7 Core Shared Buffer, offset: 0x1C */
  uint8_t RESERVED_2[8];
  __IO uint32_t DSP_CORE_CURR_RD_PTR0;             /**< Read Pointer In DSP Buffer, offset: 0x28 */
  __IO uint32_t DSP_CORE_CURR_WR_PTR0;             /**< Write Pointer In DSP Buffer, offset: 0x2C */
  __IO uint32_t DMA_READ_ADDR0;                    /**< Reference DMA Read Region, offset: 0x30 */
  uint8_t RESERVED_3[4];
  __IO uint32_t DMA_ERROR_STATUS0;                 /**< DMA Error Status, offset: 0x38 */
  uint8_t RESERVED_4[4];
  __IO uint32_t DMA_WRITE_ADDR0;                   /**< Reference DMA Write Region, offset: 0x40 */
  __IO uint32_t DMA_CURR_WR_PTR0;                  /**< DMA Current Write Pointer, offset: 0x44 */
  __IO uint32_t DMA_CURR_RD_PTR0;                  /**< DMA Current Read Pointer, offset: 0x48 */
  uint8_t RESERVED_5[4];
  __IO uint32_t DSP_TO_DMA_REQUEST_STATUS0;        /**< DMA Request Status, offset: 0x50 */
  __IO uint32_t THREAD_SUSPEND_REQ0;               /**< Thread Suspend Request For Thread Disabling/PCINIT Change, offset: 0x54 */
  uint8_t RESERVED_6[4];
  __IO uint32_t DSPSS_DSP_TH_STATUS0;              /**< Thread Status, offset: 0x5C */
  uint8_t RESERVED_7[28];
  __IO uint32_t DSP_CORE_BUFFER_STATUS0;           /**< DSP Core Buffer Status, offset: 0x7C */
  __IO uint32_t DSP_TO_CORE_TRIG_ERR_STATUS0;      /**< DSP To Cortex-M7 Core Error Trigger, offset: 0x80 */
  __I  uint32_t DS_GATE_STATUS_REGISTER0;          /**< DSP Output Control, offset: 0x84 */
  __IO uint32_t DS_GATE_TRIGMUX_REGISTER0;         /**< DSP Trigger To TRIGMUX, offset: 0x88 */
  __IO uint32_t HW_CTRL_DMA_REQ_STOP0;             /**< Stop DMA Request, offset: 0x8C */
  __IO uint32_t DMA_ERROR_CTRL0;                   /**< DMA Error Control, offset: 0x90 */
  __IO uint32_t HW_CTRL_DMA_REQ_RESPONSE0;         /**< Hardware Control Handling for DMA Request And Response, offset: 0x94 */
  uint8_t RESERVED_8[616];
  __IO uint32_t DSPSS_SCHEDULER_XMEM_ADDR_TH1;     /**< Thread Start And End Address Location Configuration, offset: 0x300 */
  __IO uint32_t DSPSS_SCHEDULER_XMEM_TH1;          /**< Thread Threshold And Enable, offset: 0x304 */
  __IO uint32_t DSPSS_SCHEDULER_DSP_CFG_TH1;       /**< PC Initial Value, offset: 0x308 */
  __I  uint32_t DSPSS_SCHEDULER_CURR_XMEM_ADDR_TH1; /**< Current XMEM Write Pointer, offset: 0x30C */
  uint8_t RESERVED_9[4];
  __I  uint32_t DSP_SDADC_CURR_READ_PTR1;          /**< Last Scheduled-Request Address, offset: 0x314 */
  uint8_t RESERVED_10[4];
  __IO uint32_t DSP_CORE_BUF_ADDR1;                /**< Start And End Pointers For DSP And Cortex-M7 Core Shared Buffer, offset: 0x31C */
  uint8_t RESERVED_11[8];
  __IO uint32_t DSP_CORE_CURR_RD_PTR1;             /**< Read Pointer In DSP Buffer, offset: 0x328 */
  __IO uint32_t DSP_CORE_CURR_WR_PTR1;             /**< Write Pointer In DSP Buffer, offset: 0x32C */
  __IO uint32_t DMA_READ_ADDR1;                    /**< Reference DMA Read Region, offset: 0x330 */
  uint8_t RESERVED_12[4];
  __IO uint32_t DMA_ERROR_STATUS1;                 /**< DMA Error Status, offset: 0x338 */
  uint8_t RESERVED_13[4];
  __IO uint32_t DMA_WRITE_ADDR1;                   /**< Reference DMA Write Region, offset: 0x340 */
  __IO uint32_t DMA_CURR_WR_PTR1;                  /**< DMA Current Write Pointer, offset: 0x344 */
  __IO uint32_t DMA_CURR_RD_PTR1;                  /**< DMA Current Read Pointer, offset: 0x348 */
  uint8_t RESERVED_14[4];
  __IO uint32_t DSP_TO_DMA_REQUEST_STATUS1;        /**< DMA Request Status, offset: 0x350 */
  __IO uint32_t THREAD_SUSPEND_REQ1;               /**< Thread Suspend Request For Thread Disabling/PCINIT Change, offset: 0x354 */
  uint8_t RESERVED_15[4];
  __IO uint32_t DSPSS_DSP_TH_STATUS1;              /**< Thread Status, offset: 0x35C */
  uint8_t RESERVED_16[28];
  __IO uint32_t DSP_CORE_BUFFER_STATUS1;           /**< DSP Core Buffer Status, offset: 0x37C */
  __IO uint32_t DSP_TO_CORE_TRIG_ERR_STATUS1;      /**< DSP To Cortex-M7 Core Error Trigger, offset: 0x380 */
  __I  uint32_t DS_GATE_STATUS_REGISTER1;          /**< DSP Output Control, offset: 0x384 */
  __IO uint32_t DS_GATE_TRIGMUX_REGISTER1;         /**< DSP Trigger To TRIGMUX, offset: 0x388 */
  __IO uint32_t HW_CTRL_DMA_REQ_STOP1;             /**< Stop DMA Request, offset: 0x38C */
  __IO uint32_t DMA_ERROR_CTRL1;                   /**< DMA Error Control, offset: 0x390 */
  __IO uint32_t HW_CTRL_DMA_REQ_RESPONSE1;         /**< Hardware Control Handling for DMA Request And Response, offset: 0x394 */
  uint8_t RESERVED_17[616];
  __IO uint32_t DSPSS_SCHEDULER_XMEM_ADDR_TH2;     /**< Thread Start And End Address Location Configuration, offset: 0x600 */
  __IO uint32_t DSPSS_SCHEDULER_XMEM_TH2;          /**< Thread Threshold And Enable, offset: 0x604 */
  __IO uint32_t DSPSS_SCHEDULER_DSP_CFG_TH2;       /**< PC Initial Value, offset: 0x608 */
  __I  uint32_t DSPSS_SCHEDULER_CURR_XMEM_ADDR_TH2; /**< Current XMEM Write Pointer, offset: 0x60C */
  uint8_t RESERVED_18[4];
  __I  uint32_t DSP_SDADC_CURR_READ_PTR2;          /**< Last Scheduled-Request Address, offset: 0x614 */
  uint8_t RESERVED_19[4];
  __IO uint32_t DSP_CORE_BUF_ADDR2;                /**< Start And End Pointers For DSP And Cortex-M7 Core Shared Buffer, offset: 0x61C */
  uint8_t RESERVED_20[8];
  __IO uint32_t DSP_CORE_CURR_RD_PTR2;             /**< Read Pointer In DSP Buffer, offset: 0x628 */
  __IO uint32_t DSP_CORE_CURR_WR_PTR2;             /**< Write Pointer In DSP Buffer, offset: 0x62C */
  __IO uint32_t DMA_READ_ADDR2;                    /**< Reference DMA Read Region, offset: 0x630 */
  uint8_t RESERVED_21[4];
  __IO uint32_t DMA_ERROR_STATUS2;                 /**< DMA Error Status, offset: 0x638 */
  uint8_t RESERVED_22[4];
  __IO uint32_t DMA_WRITE_ADDR2;                   /**< Reference DMA Write Region, offset: 0x640 */
  __IO uint32_t DMA_CURR_WR_PTR2;                  /**< DMA Current Write Pointer, offset: 0x644 */
  __IO uint32_t DMA_CURR_RD_PTR2;                  /**< DMA Current Read Pointer, offset: 0x648 */
  uint8_t RESERVED_23[4];
  __IO uint32_t DSP_TO_DMA_REQUEST_STATUS2;        /**< DMA Request Status, offset: 0x650 */
  __IO uint32_t THREAD_SUSPEND_REQ2;               /**< Thread Suspend Request For Thread Disabling/PCINIT Change, offset: 0x654 */
  uint8_t RESERVED_24[4];
  __IO uint32_t DSPSS_DSP_TH_STATUS2;              /**< Thread Status, offset: 0x65C */
  uint8_t RESERVED_25[28];
  __IO uint32_t DSP_CORE_BUFFER_STATUS2;           /**< DSP Core Buffer Status, offset: 0x67C */
  __IO uint32_t DSP_TO_CORE_TRIG_ERR_STATUS2;      /**< DSP To Cortex-M7 Core Error Trigger, offset: 0x680 */
  __I  uint32_t DS_GATE_STATUS_REGISTER2;          /**< DSP Output Control, offset: 0x684 */
  __IO uint32_t DS_GATE_TRIGMUX_REGISTER2;         /**< DSP Trigger To TRIGMUX, offset: 0x688 */
  __IO uint32_t HW_CTRL_DMA_REQ_STOP2;             /**< Stop DMA Request, offset: 0x68C */
  __IO uint32_t DMA_ERROR_CTRL2;                   /**< DMA Error Control, offset: 0x690 */
  __IO uint32_t HW_CTRL_DMA_REQ_RESPONSE2;         /**< Hardware Control Handling for DMA Request And Response, offset: 0x694 */
  uint8_t RESERVED_26[616];
  __IO uint32_t DSPSS_SCHEDULER_XMEM_ADDR_TH3;     /**< Thread Start And End Address Location Configuration, offset: 0x900 */
  __IO uint32_t DSPSS_SCHEDULER_XMEM_TH3;          /**< Thread Threshold And Enable, offset: 0x904 */
  __IO uint32_t DSPSS_SCHEDULER_DSP_CFG_TH3;       /**< PC Initial Value, offset: 0x908 */
  __I  uint32_t DSPSS_SCHEDULER_CURR_XMEM_ADDR_TH3; /**< Current XMEM Write Pointer, offset: 0x90C */
  uint8_t RESERVED_27[4];
  __I  uint32_t DSP_SDADC_CURR_READ_PTR3;          /**< Last Scheduled-Request Address, offset: 0x914 */
  uint8_t RESERVED_28[4];
  __IO uint32_t DSP_CORE_BUF_ADDR3;                /**< Start And End Pointers For DSP And Cortex-M7 Core Shared Buffer, offset: 0x91C */
  uint8_t RESERVED_29[8];
  __IO uint32_t DSP_CORE_CURR_RD_PTR3;             /**< Read Pointer In DSP Buffer, offset: 0x928 */
  __IO uint32_t DSP_CORE_CURR_WR_PTR3;             /**< Write Pointer In DSP Buffer, offset: 0x92C */
  __IO uint32_t DMA_READ_ADDR3;                    /**< Reference DMA Read Region, offset: 0x930 */
  uint8_t RESERVED_30[4];
  __IO uint32_t DMA_ERROR_STATUS3;                 /**< DMA Error Status, offset: 0x938 */
  uint8_t RESERVED_31[4];
  __IO uint32_t DMA_WRITE_ADDR3;                   /**< Reference DMA Write Region, offset: 0x940 */
  __IO uint32_t DMA_CURR_WR_PTR3;                  /**< DMA Current Write Pointer, offset: 0x944 */
  __IO uint32_t DMA_CURR_RD_PTR3;                  /**< DMA Current Read Pointer, offset: 0x948 */
  uint8_t RESERVED_32[4];
  __IO uint32_t DSP_TO_DMA_REQUEST_STATUS3;        /**< DMA Request Status, offset: 0x950 */
  __IO uint32_t THREAD_SUSPEND_REQ3;               /**< Thread Suspend Request For Thread Disabling/PCINIT Change, offset: 0x954 */
  uint8_t RESERVED_33[4];
  __IO uint32_t DSPSS_DSP_TH_STATUS3;              /**< Thread Status, offset: 0x95C */
  uint8_t RESERVED_34[28];
  __IO uint32_t DSP_CORE_BUFFER_STATUS3;           /**< DSP Core Buffer Status, offset: 0x97C */
  __IO uint32_t DSP_TO_CORE_TRIG_ERR_STATUS3;      /**< DSP To Cortex-M7 Core Error Trigger, offset: 0x980 */
  __I  uint32_t DS_GATE_STATUS_REGISTER3;          /**< DSP Output Control, offset: 0x984 */
  __IO uint32_t DS_GATE_TRIGMUX_REGISTER3;         /**< DSP Trigger To TRIGMUX, offset: 0x988 */
  __IO uint32_t HW_CTRL_DMA_REQ_STOP3;             /**< Stop DMA Request, offset: 0x98C */
  __IO uint32_t DMA_ERROR_CTRL3;                   /**< DMA Error Control, offset: 0x990 */
  __IO uint32_t HW_CTRL_DMA_REQ_RESPONSE3;         /**< Hardware Control Handling for DMA Request And Response, offset: 0x994 */
  uint8_t RESERVED_35[588];
  __IO uint32_t DSPSS_SOFT_RESET_REGISTER;         /**< DSPSS Soft Reset, offset: 0xBE4 */
  __IO uint32_t DSP_ACK_TIMEOUT_CFG_AND_ERR_CTRL;  /**< DSP ACK Timeout Configuration And Error Control, offset: 0xBE8 */
  __IO uint32_t ECC_ERROR_MONITOR_THREAD_SUSPEND_CTRL; /**< Disable Monitoring of ECC Errors In XMEM And PMEM, offset: 0xBEC */
  __IO uint32_t INTERRUPT_ENABLE_REGISTER2;        /**< Interrupt Enable, offset: 0xBF0 */
  __IO uint32_t SDADC_SYNC_FIFO_ERROR_STATUS;      /**< FIFO Overflow Status, offset: 0xBF4 */
  uint8_t RESERVED_36[4];
  __IO uint32_t DSP_CORE_BUFFER_CFG;               /**< Configuration For DSP-Core Buffer, offset: 0xBFC */
  __IO uint32_t DMA_BUFFER_CFG;                    /**< DMA Buffer Configuration, offset: 0xC00 */
  __IO uint32_t SCHEDULER_MODE_CFG;                /**< Thread Scheduling Mode Selection, offset: 0xC04 */
  __IO uint32_t DSPSS_DSP0_CFG;                    /**< DSP0 Reset And Core Trigger Configuration, offset: 0xC08 */
  uint8_t RESERVED_37[4];
  __IO uint32_t INTERRUPT_ENABLE_REGISTER;         /**< Interrupt Enable, offset: 0xC10 */
  __IO uint32_t DSPSS_DSP_IO_INTF0;                /**< DSP Trigger to Core, offset: 0xC14 */
  uint8_t RESERVED_38[4];
  __IO uint32_t CURR_ACTIVE_THRD;                  /**< DSP Core Status, offset: 0xC1C */
  uint8_t RESERVED_39[4];
  __IO uint32_t DSPSS_DSP_CORE_TRIGGER_SAFETY;     /**< >DSP Safety Trigger to Core..DSP Safety Trigger to Core, offset: 0xC24 */
  uint8_t RESERVED_40[8];
  __IO uint32_t DMA_READ_ADDR4;                    /**< Reference DMA Read Region, offset: 0xC30 */
  uint8_t RESERVED_41[4];
  __IO uint32_t DMA_ERROR_STATUS4;                 /**< DMA Error Status, offset: 0xC38 */
  uint8_t RESERVED_42[4];
  __IO uint32_t DMA_WRITE_ADDR4;                   /**< Reference DMA Write Region, offset: 0xC40 */
  __IO uint32_t DMA_CURR_WR_PTR4;                  /**< DMA Current Write Pointer, offset: 0xC44 */
  __IO uint32_t DMA_CURR_RD_PTR4;                  /**< DMA Current Read Pointer, offset: 0xC48 */
  uint8_t RESERVED_43[4];
  __IO uint32_t DSP_TO_DMA_REQUEST_STATUS4;        /**< DMA Request Status, offset: 0xC50 */
  uint8_t RESERVED_44[56];
  __IO uint32_t HW_CTRL_DMA_REQ_STOP4;             /**< Stop DMA Request, offset: 0xC8C */
  __IO uint32_t DMA_ERROR_CTRL4;                   /**< DMA Error Control, offset: 0xC90 */
  __IO uint32_t HW_CTRL_DMA_REQ_RESPONSE4;         /**< Hardware Control Handling for DMA Request And Response, offset: 0xC94 */
  uint8_t RESERVED_45[664];
  __IO uint32_t DMA_READ_ADDR5;                    /**< Reference DMA Read Region, offset: 0xF30 */
  uint8_t RESERVED_46[4];
  __IO uint32_t DMA_ERROR_STATUS5;                 /**< DMA Error Status, offset: 0xF38 */
  uint8_t RESERVED_47[4];
  __IO uint32_t DMA_WRITE_ADDR5;                   /**< Reference DMA Write Region, offset: 0xF40 */
  __IO uint32_t DMA_CURR_WR_PTR5;                  /**< DMA Current Write Pointer, offset: 0xF44 */
  __IO uint32_t DMA_CURR_RD_PTR5;                  /**< DMA Current Read Pointer, offset: 0xF48 */
  uint8_t RESERVED_48[4];
  __IO uint32_t DSP_TO_DMA_REQUEST_STATUS5;        /**< DMA Request Status, offset: 0xF50 */
  uint8_t RESERVED_49[56];
  __IO uint32_t HW_CTRL_DMA_REQ_STOP5;             /**< Stop DMA Request, offset: 0xF8C */
  __IO uint32_t DMA_ERROR_CTRL5;                   /**< DMA Error Control, offset: 0xF90 */
  __IO uint32_t HW_CTRL_DMA_REQ_RESPONSE5;         /**< Hardware Control Handling for DMA Request And Response, offset: 0xF94 */
  uint8_t RESERVED_50[616];
  __I  uint32_t DSPSS_DSP_THREAD_INFO[DSPSS_DSPSS_DSP_THREAD_INFO_COUNT]; /**< Thread Status Info 0..Thread Status Info 3, array offset: 0x1200, array step: 0x4 */
} DSPSS_Type, *DSPSS_MemMapPtr;

/** Number of instances of the DSPSS module. */
#define DSPSS_INSTANCE_COUNT                     (2u)

/* DSPSS - Peripheral instance base addresses */
/** Peripheral DSPSS_0 base address */
#define IP_DSPSS_0_BASE                          (0x406DC000u)
/** Peripheral DSPSS_0 base pointer */
#define IP_DSPSS_0                               ((DSPSS_Type *)IP_DSPSS_0_BASE)
/** Peripheral DSPSS_1 base address */
#define IP_DSPSS_1_BASE                          (0u)
/** Peripheral DSPSS_1 base pointer */
#define IP_DSPSS_1                               ((DSPSS_Type *)IP_DSPSS_1_BASE)
/** Array initializer of DSPSS peripheral base addresses */
#define IP_DSPSS_BASE_ADDRS                      { IP_DSPSS_0_BASE, IP_DSPSS_1_BASE }
/** Array initializer of DSPSS peripheral base pointers */
#define IP_DSPSS_BASE_PTRS                       { IP_DSPSS_0, IP_DSPSS_1 }

/* ----------------------------------------------------------------------------
   -- DSPSS Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DSPSS_Register_Masks DSPSS Register Masks
 * @{
 */

/*! @name DSPSS_SCHEDULER_XMEM_ADDR_TH0 - Thread Start And End Address Location Configuration */
/*! @{ */

#define DSPSS_DSPSS_SCHEDULER_XMEM_ADDR_TH0_SCHEDULER_THRD_START_ADDR_MASK (0xFFFFU)
#define DSPSS_DSPSS_SCHEDULER_XMEM_ADDR_TH0_SCHEDULER_THRD_START_ADDR_SHIFT (0U)
#define DSPSS_DSPSS_SCHEDULER_XMEM_ADDR_TH0_SCHEDULER_THRD_START_ADDR_WIDTH (16U)
#define DSPSS_DSPSS_SCHEDULER_XMEM_ADDR_TH0_SCHEDULER_THRD_START_ADDR(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSPSS_SCHEDULER_XMEM_ADDR_TH0_SCHEDULER_THRD_START_ADDR_SHIFT)) & DSPSS_DSPSS_SCHEDULER_XMEM_ADDR_TH0_SCHEDULER_THRD_START_ADDR_MASK)

#define DSPSS_DSPSS_SCHEDULER_XMEM_ADDR_TH0_SCHEDULER_THRD_END_ADDR_MASK (0xFFFF0000U)
#define DSPSS_DSPSS_SCHEDULER_XMEM_ADDR_TH0_SCHEDULER_THRD_END_ADDR_SHIFT (16U)
#define DSPSS_DSPSS_SCHEDULER_XMEM_ADDR_TH0_SCHEDULER_THRD_END_ADDR_WIDTH (16U)
#define DSPSS_DSPSS_SCHEDULER_XMEM_ADDR_TH0_SCHEDULER_THRD_END_ADDR(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSPSS_SCHEDULER_XMEM_ADDR_TH0_SCHEDULER_THRD_END_ADDR_SHIFT)) & DSPSS_DSPSS_SCHEDULER_XMEM_ADDR_TH0_SCHEDULER_THRD_END_ADDR_MASK)
/*! @} */

/*! @name DSPSS_SCHEDULER_XMEM_TH0 - Thread Threshold And Enable */
/*! @{ */

#define DSPSS_DSPSS_SCHEDULER_XMEM_TH0_SCHEDULER_THRD_TH_MASK (0xFFFFU)
#define DSPSS_DSPSS_SCHEDULER_XMEM_TH0_SCHEDULER_THRD_TH_SHIFT (0U)
#define DSPSS_DSPSS_SCHEDULER_XMEM_TH0_SCHEDULER_THRD_TH_WIDTH (16U)
#define DSPSS_DSPSS_SCHEDULER_XMEM_TH0_SCHEDULER_THRD_TH(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSPSS_SCHEDULER_XMEM_TH0_SCHEDULER_THRD_TH_SHIFT)) & DSPSS_DSPSS_SCHEDULER_XMEM_TH0_SCHEDULER_THRD_TH_MASK)

#define DSPSS_DSPSS_SCHEDULER_XMEM_TH0_SCHEDULER_THRD_EN_MASK (0x80000000U)
#define DSPSS_DSPSS_SCHEDULER_XMEM_TH0_SCHEDULER_THRD_EN_SHIFT (31U)
#define DSPSS_DSPSS_SCHEDULER_XMEM_TH0_SCHEDULER_THRD_EN_WIDTH (1U)
#define DSPSS_DSPSS_SCHEDULER_XMEM_TH0_SCHEDULER_THRD_EN(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSPSS_SCHEDULER_XMEM_TH0_SCHEDULER_THRD_EN_SHIFT)) & DSPSS_DSPSS_SCHEDULER_XMEM_TH0_SCHEDULER_THRD_EN_MASK)
/*! @} */

/*! @name DSPSS_SCHEDULER_DSP_CFG_TH0 - PC Initial Value */
/*! @{ */

#define DSPSS_DSPSS_SCHEDULER_DSP_CFG_TH0_DSPSS_SCHEDULER_DSP_PCINIT_MASK (0x3FFFU)
#define DSPSS_DSPSS_SCHEDULER_DSP_CFG_TH0_DSPSS_SCHEDULER_DSP_PCINIT_SHIFT (0U)
#define DSPSS_DSPSS_SCHEDULER_DSP_CFG_TH0_DSPSS_SCHEDULER_DSP_PCINIT_WIDTH (14U)
#define DSPSS_DSPSS_SCHEDULER_DSP_CFG_TH0_DSPSS_SCHEDULER_DSP_PCINIT(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSPSS_SCHEDULER_DSP_CFG_TH0_DSPSS_SCHEDULER_DSP_PCINIT_SHIFT)) & DSPSS_DSPSS_SCHEDULER_DSP_CFG_TH0_DSPSS_SCHEDULER_DSP_PCINIT_MASK)
/*! @} */

/*! @name DSPSS_SCHEDULER_CURR_XMEM_ADDR_TH0 - Current XMEM Write Pointer */
/*! @{ */

#define DSPSS_DSPSS_SCHEDULER_CURR_XMEM_ADDR_TH0_DSPSS_SCHEDULER_CURR_XMEM_ADDR_MASK (0x7FFFU)
#define DSPSS_DSPSS_SCHEDULER_CURR_XMEM_ADDR_TH0_DSPSS_SCHEDULER_CURR_XMEM_ADDR_SHIFT (0U)
#define DSPSS_DSPSS_SCHEDULER_CURR_XMEM_ADDR_TH0_DSPSS_SCHEDULER_CURR_XMEM_ADDR_WIDTH (15U)
#define DSPSS_DSPSS_SCHEDULER_CURR_XMEM_ADDR_TH0_DSPSS_SCHEDULER_CURR_XMEM_ADDR(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSPSS_SCHEDULER_CURR_XMEM_ADDR_TH0_DSPSS_SCHEDULER_CURR_XMEM_ADDR_SHIFT)) & DSPSS_DSPSS_SCHEDULER_CURR_XMEM_ADDR_TH0_DSPSS_SCHEDULER_CURR_XMEM_ADDR_MASK)
/*! @} */

/*! @name DSP_SDADC_CURR_READ_PTR0 - Last Scheduled-Request Address */
/*! @{ */

#define DSPSS_DSP_SDADC_CURR_READ_PTR0_DSP_SDADC_CURR_READ_PTR_MASK (0x3FFFU)
#define DSPSS_DSP_SDADC_CURR_READ_PTR0_DSP_SDADC_CURR_READ_PTR_SHIFT (0U)
#define DSPSS_DSP_SDADC_CURR_READ_PTR0_DSP_SDADC_CURR_READ_PTR_WIDTH (14U)
#define DSPSS_DSP_SDADC_CURR_READ_PTR0_DSP_SDADC_CURR_READ_PTR(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSP_SDADC_CURR_READ_PTR0_DSP_SDADC_CURR_READ_PTR_SHIFT)) & DSPSS_DSP_SDADC_CURR_READ_PTR0_DSP_SDADC_CURR_READ_PTR_MASK)
/*! @} */

/*! @name DSP_CORE_BUF_ADDR0 - Start And End Pointers For DSP And Cortex-M7 Core Shared Buffer */
/*! @{ */

#define DSPSS_DSP_CORE_BUF_ADDR0_DSP_CORE_BUF_START_ADDR_MASK (0x3FFFU)
#define DSPSS_DSP_CORE_BUF_ADDR0_DSP_CORE_BUF_START_ADDR_SHIFT (0U)
#define DSPSS_DSP_CORE_BUF_ADDR0_DSP_CORE_BUF_START_ADDR_WIDTH (14U)
#define DSPSS_DSP_CORE_BUF_ADDR0_DSP_CORE_BUF_START_ADDR(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSP_CORE_BUF_ADDR0_DSP_CORE_BUF_START_ADDR_SHIFT)) & DSPSS_DSP_CORE_BUF_ADDR0_DSP_CORE_BUF_START_ADDR_MASK)

#define DSPSS_DSP_CORE_BUF_ADDR0_DSP_CORE_BUF_END_ADDR_MASK (0xFFFC0000U)
#define DSPSS_DSP_CORE_BUF_ADDR0_DSP_CORE_BUF_END_ADDR_SHIFT (18U)
#define DSPSS_DSP_CORE_BUF_ADDR0_DSP_CORE_BUF_END_ADDR_WIDTH (14U)
#define DSPSS_DSP_CORE_BUF_ADDR0_DSP_CORE_BUF_END_ADDR(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSP_CORE_BUF_ADDR0_DSP_CORE_BUF_END_ADDR_SHIFT)) & DSPSS_DSP_CORE_BUF_ADDR0_DSP_CORE_BUF_END_ADDR_MASK)
/*! @} */

/*! @name DSP_CORE_CURR_RD_PTR0 - Read Pointer In DSP Buffer */
/*! @{ */

#define DSPSS_DSP_CORE_CURR_RD_PTR0_DSP_CORE_CURR_RD_PTR_MASK (0x3FFFU)
#define DSPSS_DSP_CORE_CURR_RD_PTR0_DSP_CORE_CURR_RD_PTR_SHIFT (0U)
#define DSPSS_DSP_CORE_CURR_RD_PTR0_DSP_CORE_CURR_RD_PTR_WIDTH (14U)
#define DSPSS_DSP_CORE_CURR_RD_PTR0_DSP_CORE_CURR_RD_PTR(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSP_CORE_CURR_RD_PTR0_DSP_CORE_CURR_RD_PTR_SHIFT)) & DSPSS_DSP_CORE_CURR_RD_PTR0_DSP_CORE_CURR_RD_PTR_MASK)

#define DSPSS_DSP_CORE_CURR_RD_PTR0_DSP_CORE_CURR_RD_PTR_WRAP_MASK (0x4000U)
#define DSPSS_DSP_CORE_CURR_RD_PTR0_DSP_CORE_CURR_RD_PTR_WRAP_SHIFT (14U)
#define DSPSS_DSP_CORE_CURR_RD_PTR0_DSP_CORE_CURR_RD_PTR_WRAP_WIDTH (1U)
#define DSPSS_DSP_CORE_CURR_RD_PTR0_DSP_CORE_CURR_RD_PTR_WRAP(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSP_CORE_CURR_RD_PTR0_DSP_CORE_CURR_RD_PTR_WRAP_SHIFT)) & DSPSS_DSP_CORE_CURR_RD_PTR0_DSP_CORE_CURR_RD_PTR_WRAP_MASK)
/*! @} */

/*! @name DSP_CORE_CURR_WR_PTR0 - Write Pointer In DSP Buffer */
/*! @{ */

#define DSPSS_DSP_CORE_CURR_WR_PTR0_DSP_CORE_CURR_WR_PTR_MASK (0x3FFFU)
#define DSPSS_DSP_CORE_CURR_WR_PTR0_DSP_CORE_CURR_WR_PTR_SHIFT (0U)
#define DSPSS_DSP_CORE_CURR_WR_PTR0_DSP_CORE_CURR_WR_PTR_WIDTH (14U)
#define DSPSS_DSP_CORE_CURR_WR_PTR0_DSP_CORE_CURR_WR_PTR(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSP_CORE_CURR_WR_PTR0_DSP_CORE_CURR_WR_PTR_SHIFT)) & DSPSS_DSP_CORE_CURR_WR_PTR0_DSP_CORE_CURR_WR_PTR_MASK)

#define DSPSS_DSP_CORE_CURR_WR_PTR0_DSP_CORE_CURR_WR_PTR_WRAP_MASK (0x4000U)
#define DSPSS_DSP_CORE_CURR_WR_PTR0_DSP_CORE_CURR_WR_PTR_WRAP_SHIFT (14U)
#define DSPSS_DSP_CORE_CURR_WR_PTR0_DSP_CORE_CURR_WR_PTR_WRAP_WIDTH (1U)
#define DSPSS_DSP_CORE_CURR_WR_PTR0_DSP_CORE_CURR_WR_PTR_WRAP(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSP_CORE_CURR_WR_PTR0_DSP_CORE_CURR_WR_PTR_WRAP_SHIFT)) & DSPSS_DSP_CORE_CURR_WR_PTR0_DSP_CORE_CURR_WR_PTR_WRAP_MASK)
/*! @} */

/*! @name DMA_READ_ADDR0 - Reference DMA Read Region */
/*! @{ */

#define DSPSS_DMA_READ_ADDR0_DMA_READ_START_ADDR_MASK (0x3FFFU)
#define DSPSS_DMA_READ_ADDR0_DMA_READ_START_ADDR_SHIFT (0U)
#define DSPSS_DMA_READ_ADDR0_DMA_READ_START_ADDR_WIDTH (14U)
#define DSPSS_DMA_READ_ADDR0_DMA_READ_START_ADDR(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DMA_READ_ADDR0_DMA_READ_START_ADDR_SHIFT)) & DSPSS_DMA_READ_ADDR0_DMA_READ_START_ADDR_MASK)

#define DSPSS_DMA_READ_ADDR0_DMA_READ_END_ADDR_MASK (0xFFFC0000U)
#define DSPSS_DMA_READ_ADDR0_DMA_READ_END_ADDR_SHIFT (18U)
#define DSPSS_DMA_READ_ADDR0_DMA_READ_END_ADDR_WIDTH (14U)
#define DSPSS_DMA_READ_ADDR0_DMA_READ_END_ADDR(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DMA_READ_ADDR0_DMA_READ_END_ADDR_SHIFT)) & DSPSS_DMA_READ_ADDR0_DMA_READ_END_ADDR_MASK)
/*! @} */

/*! @name DMA_ERROR_STATUS0 - DMA Error Status */
/*! @{ */

#define DSPSS_DMA_ERROR_STATUS0_DMA_ADDR_MISMATCH_WR_BUFFER_MASK (0x1U)
#define DSPSS_DMA_ERROR_STATUS0_DMA_ADDR_MISMATCH_WR_BUFFER_SHIFT (0U)
#define DSPSS_DMA_ERROR_STATUS0_DMA_ADDR_MISMATCH_WR_BUFFER_WIDTH (1U)
#define DSPSS_DMA_ERROR_STATUS0_DMA_ADDR_MISMATCH_WR_BUFFER(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DMA_ERROR_STATUS0_DMA_ADDR_MISMATCH_WR_BUFFER_SHIFT)) & DSPSS_DMA_ERROR_STATUS0_DMA_ADDR_MISMATCH_WR_BUFFER_MASK)

#define DSPSS_DMA_ERROR_STATUS0_DMA_ADDR_MISMATCH_RD_BUFFER_MASK (0x2U)
#define DSPSS_DMA_ERROR_STATUS0_DMA_ADDR_MISMATCH_RD_BUFFER_SHIFT (1U)
#define DSPSS_DMA_ERROR_STATUS0_DMA_ADDR_MISMATCH_RD_BUFFER_WIDTH (1U)
#define DSPSS_DMA_ERROR_STATUS0_DMA_ADDR_MISMATCH_RD_BUFFER(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DMA_ERROR_STATUS0_DMA_ADDR_MISMATCH_RD_BUFFER_SHIFT)) & DSPSS_DMA_ERROR_STATUS0_DMA_ADDR_MISMATCH_RD_BUFFER_MASK)

#define DSPSS_DMA_ERROR_STATUS0_DMA_XFR_ERR_WRITE_MASK (0x4U)
#define DSPSS_DMA_ERROR_STATUS0_DMA_XFR_ERR_WRITE_SHIFT (2U)
#define DSPSS_DMA_ERROR_STATUS0_DMA_XFR_ERR_WRITE_WIDTH (1U)
#define DSPSS_DMA_ERROR_STATUS0_DMA_XFR_ERR_WRITE(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DMA_ERROR_STATUS0_DMA_XFR_ERR_WRITE_SHIFT)) & DSPSS_DMA_ERROR_STATUS0_DMA_XFR_ERR_WRITE_MASK)

#define DSPSS_DMA_ERROR_STATUS0_DMA_XFR_ERR_READ_MASK (0x8U)
#define DSPSS_DMA_ERROR_STATUS0_DMA_XFR_ERR_READ_SHIFT (3U)
#define DSPSS_DMA_ERROR_STATUS0_DMA_XFR_ERR_READ_WIDTH (1U)
#define DSPSS_DMA_ERROR_STATUS0_DMA_XFR_ERR_READ(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DMA_ERROR_STATUS0_DMA_XFR_ERR_READ_SHIFT)) & DSPSS_DMA_ERROR_STATUS0_DMA_XFR_ERR_READ_MASK)
/*! @} */

/*! @name DMA_WRITE_ADDR0 - Reference DMA Write Region */
/*! @{ */

#define DSPSS_DMA_WRITE_ADDR0_DMA_WRITE_START_ADDR_MASK (0x3FFFU)
#define DSPSS_DMA_WRITE_ADDR0_DMA_WRITE_START_ADDR_SHIFT (0U)
#define DSPSS_DMA_WRITE_ADDR0_DMA_WRITE_START_ADDR_WIDTH (14U)
#define DSPSS_DMA_WRITE_ADDR0_DMA_WRITE_START_ADDR(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DMA_WRITE_ADDR0_DMA_WRITE_START_ADDR_SHIFT)) & DSPSS_DMA_WRITE_ADDR0_DMA_WRITE_START_ADDR_MASK)

#define DSPSS_DMA_WRITE_ADDR0_DMA_WRITE_END_ADDR_MASK (0xFFFC0000U)
#define DSPSS_DMA_WRITE_ADDR0_DMA_WRITE_END_ADDR_SHIFT (18U)
#define DSPSS_DMA_WRITE_ADDR0_DMA_WRITE_END_ADDR_WIDTH (14U)
#define DSPSS_DMA_WRITE_ADDR0_DMA_WRITE_END_ADDR(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DMA_WRITE_ADDR0_DMA_WRITE_END_ADDR_SHIFT)) & DSPSS_DMA_WRITE_ADDR0_DMA_WRITE_END_ADDR_MASK)
/*! @} */

/*! @name DMA_CURR_WR_PTR0 - DMA Current Write Pointer */
/*! @{ */

#define DSPSS_DMA_CURR_WR_PTR0_DMA_CURR_WRITE_PTR_MASK (0x3FFFU)
#define DSPSS_DMA_CURR_WR_PTR0_DMA_CURR_WRITE_PTR_SHIFT (0U)
#define DSPSS_DMA_CURR_WR_PTR0_DMA_CURR_WRITE_PTR_WIDTH (14U)
#define DSPSS_DMA_CURR_WR_PTR0_DMA_CURR_WRITE_PTR(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DMA_CURR_WR_PTR0_DMA_CURR_WRITE_PTR_SHIFT)) & DSPSS_DMA_CURR_WR_PTR0_DMA_CURR_WRITE_PTR_MASK)

#define DSPSS_DMA_CURR_WR_PTR0_DMA_WRITE_PTR_WRAP_MASK (0x80000000U)
#define DSPSS_DMA_CURR_WR_PTR0_DMA_WRITE_PTR_WRAP_SHIFT (31U)
#define DSPSS_DMA_CURR_WR_PTR0_DMA_WRITE_PTR_WRAP_WIDTH (1U)
#define DSPSS_DMA_CURR_WR_PTR0_DMA_WRITE_PTR_WRAP(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DMA_CURR_WR_PTR0_DMA_WRITE_PTR_WRAP_SHIFT)) & DSPSS_DMA_CURR_WR_PTR0_DMA_WRITE_PTR_WRAP_MASK)
/*! @} */

/*! @name DMA_CURR_RD_PTR0 - DMA Current Read Pointer */
/*! @{ */

#define DSPSS_DMA_CURR_RD_PTR0_DMA_CURR_READ_PTR_MASK (0x3FFFU)
#define DSPSS_DMA_CURR_RD_PTR0_DMA_CURR_READ_PTR_SHIFT (0U)
#define DSPSS_DMA_CURR_RD_PTR0_DMA_CURR_READ_PTR_WIDTH (14U)
#define DSPSS_DMA_CURR_RD_PTR0_DMA_CURR_READ_PTR(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DMA_CURR_RD_PTR0_DMA_CURR_READ_PTR_SHIFT)) & DSPSS_DMA_CURR_RD_PTR0_DMA_CURR_READ_PTR_MASK)

#define DSPSS_DMA_CURR_RD_PTR0_DMA_READ_PTR_WRAP_MASK (0x80000000U)
#define DSPSS_DMA_CURR_RD_PTR0_DMA_READ_PTR_WRAP_SHIFT (31U)
#define DSPSS_DMA_CURR_RD_PTR0_DMA_READ_PTR_WRAP_WIDTH (1U)
#define DSPSS_DMA_CURR_RD_PTR0_DMA_READ_PTR_WRAP(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DMA_CURR_RD_PTR0_DMA_READ_PTR_WRAP_SHIFT)) & DSPSS_DMA_CURR_RD_PTR0_DMA_READ_PTR_WRAP_MASK)
/*! @} */

/*! @name DSP_TO_DMA_REQUEST_STATUS0 - DMA Request Status */
/*! @{ */

#define DSPSS_DSP_TO_DMA_REQUEST_STATUS0_DSP_TO_DMA_REQUEST_STATUS_MASK (0x1U)
#define DSPSS_DSP_TO_DMA_REQUEST_STATUS0_DSP_TO_DMA_REQUEST_STATUS_SHIFT (0U)
#define DSPSS_DSP_TO_DMA_REQUEST_STATUS0_DSP_TO_DMA_REQUEST_STATUS_WIDTH (1U)
#define DSPSS_DSP_TO_DMA_REQUEST_STATUS0_DSP_TO_DMA_REQUEST_STATUS(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSP_TO_DMA_REQUEST_STATUS0_DSP_TO_DMA_REQUEST_STATUS_SHIFT)) & DSPSS_DSP_TO_DMA_REQUEST_STATUS0_DSP_TO_DMA_REQUEST_STATUS_MASK)

#define DSPSS_DSP_TO_DMA_REQUEST_STATUS0_DMA_TO_DSP_ACK_STATUS_MASK (0x2U)
#define DSPSS_DSP_TO_DMA_REQUEST_STATUS0_DMA_TO_DSP_ACK_STATUS_SHIFT (1U)
#define DSPSS_DSP_TO_DMA_REQUEST_STATUS0_DMA_TO_DSP_ACK_STATUS_WIDTH (1U)
#define DSPSS_DSP_TO_DMA_REQUEST_STATUS0_DMA_TO_DSP_ACK_STATUS(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSP_TO_DMA_REQUEST_STATUS0_DMA_TO_DSP_ACK_STATUS_SHIFT)) & DSPSS_DSP_TO_DMA_REQUEST_STATUS0_DMA_TO_DSP_ACK_STATUS_MASK)
/*! @} */

/*! @name THREAD_SUSPEND_REQ0 - Thread Suspend Request For Thread Disabling/PCINIT Change */
/*! @{ */

#define DSPSS_THREAD_SUSPEND_REQ0_SUSPEND_REQ_MASK (0x1U)
#define DSPSS_THREAD_SUSPEND_REQ0_SUSPEND_REQ_SHIFT (0U)
#define DSPSS_THREAD_SUSPEND_REQ0_SUSPEND_REQ_WIDTH (1U)
#define DSPSS_THREAD_SUSPEND_REQ0_SUSPEND_REQ(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_THREAD_SUSPEND_REQ0_SUSPEND_REQ_SHIFT)) & DSPSS_THREAD_SUSPEND_REQ0_SUSPEND_REQ_MASK)
/*! @} */

/*! @name DSPSS_DSP_TH_STATUS0 - Thread Status */
/*! @{ */

#define DSPSS_DSPSS_DSP_TH_STATUS0_dspss_th_suspended_MASK (0x1U)
#define DSPSS_DSPSS_DSP_TH_STATUS0_dspss_th_suspended_SHIFT (0U)
#define DSPSS_DSPSS_DSP_TH_STATUS0_dspss_th_suspended_WIDTH (1U)
#define DSPSS_DSPSS_DSP_TH_STATUS0_dspss_th_suspended(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSPSS_DSP_TH_STATUS0_dspss_th_suspended_SHIFT)) & DSPSS_DSPSS_DSP_TH_STATUS0_dspss_th_suspended_MASK)
/*! @} */

/*! @name DSP_CORE_BUFFER_STATUS0 - DSP Core Buffer Status */
/*! @{ */

#define DSPSS_DSP_CORE_BUFFER_STATUS0_DSP_CORE_BUFFER_OVF_MASK (0x2U)
#define DSPSS_DSP_CORE_BUFFER_STATUS0_DSP_CORE_BUFFER_OVF_SHIFT (1U)
#define DSPSS_DSP_CORE_BUFFER_STATUS0_DSP_CORE_BUFFER_OVF_WIDTH (1U)
#define DSPSS_DSP_CORE_BUFFER_STATUS0_DSP_CORE_BUFFER_OVF(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSP_CORE_BUFFER_STATUS0_DSP_CORE_BUFFER_OVF_SHIFT)) & DSPSS_DSP_CORE_BUFFER_STATUS0_DSP_CORE_BUFFER_OVF_MASK)

#define DSPSS_DSP_CORE_BUFFER_STATUS0_DSP_CORE_BUFFER_UNDF_MASK (0x4U)
#define DSPSS_DSP_CORE_BUFFER_STATUS0_DSP_CORE_BUFFER_UNDF_SHIFT (2U)
#define DSPSS_DSP_CORE_BUFFER_STATUS0_DSP_CORE_BUFFER_UNDF_WIDTH (1U)
#define DSPSS_DSP_CORE_BUFFER_STATUS0_DSP_CORE_BUFFER_UNDF(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSP_CORE_BUFFER_STATUS0_DSP_CORE_BUFFER_UNDF_SHIFT)) & DSPSS_DSP_CORE_BUFFER_STATUS0_DSP_CORE_BUFFER_UNDF_MASK)
/*! @} */

/*! @name DSP_TO_CORE_TRIG_ERR_STATUS0 - DSP To Cortex-M7 Core Error Trigger */
/*! @{ */

#define DSPSS_DSP_TO_CORE_TRIG_ERR_STATUS0_DSP_TO_CORE_TRIG_ERR_STATUS_MASK (0x1U)
#define DSPSS_DSP_TO_CORE_TRIG_ERR_STATUS0_DSP_TO_CORE_TRIG_ERR_STATUS_SHIFT (0U)
#define DSPSS_DSP_TO_CORE_TRIG_ERR_STATUS0_DSP_TO_CORE_TRIG_ERR_STATUS_WIDTH (1U)
#define DSPSS_DSP_TO_CORE_TRIG_ERR_STATUS0_DSP_TO_CORE_TRIG_ERR_STATUS(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSP_TO_CORE_TRIG_ERR_STATUS0_DSP_TO_CORE_TRIG_ERR_STATUS_SHIFT)) & DSPSS_DSP_TO_CORE_TRIG_ERR_STATUS0_DSP_TO_CORE_TRIG_ERR_STATUS_MASK)
/*! @} */

/*! @name DS_GATE_STATUS_REGISTER0 - DSP Output Control */
/*! @{ */

#define DSPSS_DS_GATE_STATUS_REGISTER0_DS_GATE_STATUS_REGISTER_MASK (0x1U)
#define DSPSS_DS_GATE_STATUS_REGISTER0_DS_GATE_STATUS_REGISTER_SHIFT (0U)
#define DSPSS_DS_GATE_STATUS_REGISTER0_DS_GATE_STATUS_REGISTER_WIDTH (1U)
#define DSPSS_DS_GATE_STATUS_REGISTER0_DS_GATE_STATUS_REGISTER(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DS_GATE_STATUS_REGISTER0_DS_GATE_STATUS_REGISTER_SHIFT)) & DSPSS_DS_GATE_STATUS_REGISTER0_DS_GATE_STATUS_REGISTER_MASK)
/*! @} */

/*! @name DS_GATE_TRIGMUX_REGISTER0 - DSP Trigger To TRIGMUX */
/*! @{ */

#define DSPSS_DS_GATE_TRIGMUX_REGISTER0_DS_GATE_TRIGMUX_TRIGGER_MASK (0x1U)
#define DSPSS_DS_GATE_TRIGMUX_REGISTER0_DS_GATE_TRIGMUX_TRIGGER_SHIFT (0U)
#define DSPSS_DS_GATE_TRIGMUX_REGISTER0_DS_GATE_TRIGMUX_TRIGGER_WIDTH (1U)
#define DSPSS_DS_GATE_TRIGMUX_REGISTER0_DS_GATE_TRIGMUX_TRIGGER(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DS_GATE_TRIGMUX_REGISTER0_DS_GATE_TRIGMUX_TRIGGER_SHIFT)) & DSPSS_DS_GATE_TRIGMUX_REGISTER0_DS_GATE_TRIGMUX_TRIGGER_MASK)
/*! @} */

/*! @name HW_CTRL_DMA_REQ_STOP0 - Stop DMA Request */
/*! @{ */

#define DSPSS_HW_CTRL_DMA_REQ_STOP0_STOP_MASK    (0x1U)
#define DSPSS_HW_CTRL_DMA_REQ_STOP0_STOP_SHIFT   (0U)
#define DSPSS_HW_CTRL_DMA_REQ_STOP0_STOP_WIDTH   (1U)
#define DSPSS_HW_CTRL_DMA_REQ_STOP0_STOP(x)      (((uint32_t)(((uint32_t)(x)) << DSPSS_HW_CTRL_DMA_REQ_STOP0_STOP_SHIFT)) & DSPSS_HW_CTRL_DMA_REQ_STOP0_STOP_MASK)
/*! @} */

/*! @name DMA_ERROR_CTRL0 - DMA Error Control */
/*! @{ */

#define DSPSS_DMA_ERROR_CTRL0_DONE_MASK          (0x1U)
#define DSPSS_DMA_ERROR_CTRL0_DONE_SHIFT         (0U)
#define DSPSS_DMA_ERROR_CTRL0_DONE_WIDTH         (1U)
#define DSPSS_DMA_ERROR_CTRL0_DONE(x)            (((uint32_t)(((uint32_t)(x)) << DSPSS_DMA_ERROR_CTRL0_DONE_SHIFT)) & DSPSS_DMA_ERROR_CTRL0_DONE_MASK)
/*! @} */

/*! @name HW_CTRL_DMA_REQ_RESPONSE0 - Hardware Control Handling for DMA Request And Response */
/*! @{ */

#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE0_START_MASK (0x1U)
#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE0_START_SHIFT (0U)
#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE0_START_WIDTH (1U)
#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE0_START(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_HW_CTRL_DMA_REQ_RESPONSE0_START_SHIFT)) & DSPSS_HW_CTRL_DMA_REQ_RESPONSE0_START_MASK)

#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE0_NUM_OF_DMA_REQ_MASK (0x1FEU)
#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE0_NUM_OF_DMA_REQ_SHIFT (1U)
#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE0_NUM_OF_DMA_REQ_WIDTH (8U)
#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE0_NUM_OF_DMA_REQ(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_HW_CTRL_DMA_REQ_RESPONSE0_NUM_OF_DMA_REQ_SHIFT)) & DSPSS_HW_CTRL_DMA_REQ_RESPONSE0_NUM_OF_DMA_REQ_MASK)

#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE0_DONE_MASK (0x200U)
#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE0_DONE_SHIFT (9U)
#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE0_DONE_WIDTH (1U)
#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE0_DONE(x)  (((uint32_t)(((uint32_t)(x)) << DSPSS_HW_CTRL_DMA_REQ_RESPONSE0_DONE_SHIFT)) & DSPSS_HW_CTRL_DMA_REQ_RESPONSE0_DONE_MASK)

#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE0_NUM_OF_DMA_REQ_PEND_MASK (0x3FC00U)
#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE0_NUM_OF_DMA_REQ_PEND_SHIFT (10U)
#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE0_NUM_OF_DMA_REQ_PEND_WIDTH (8U)
#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE0_NUM_OF_DMA_REQ_PEND(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_HW_CTRL_DMA_REQ_RESPONSE0_NUM_OF_DMA_REQ_PEND_SHIFT)) & DSPSS_HW_CTRL_DMA_REQ_RESPONSE0_NUM_OF_DMA_REQ_PEND_MASK)
/*! @} */

/*! @name DSPSS_SCHEDULER_XMEM_ADDR_TH1 - Thread Start And End Address Location Configuration */
/*! @{ */

#define DSPSS_DSPSS_SCHEDULER_XMEM_ADDR_TH1_SCHEDULER_THRD_START_ADDR_MASK (0xFFFFU)
#define DSPSS_DSPSS_SCHEDULER_XMEM_ADDR_TH1_SCHEDULER_THRD_START_ADDR_SHIFT (0U)
#define DSPSS_DSPSS_SCHEDULER_XMEM_ADDR_TH1_SCHEDULER_THRD_START_ADDR_WIDTH (16U)
#define DSPSS_DSPSS_SCHEDULER_XMEM_ADDR_TH1_SCHEDULER_THRD_START_ADDR(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSPSS_SCHEDULER_XMEM_ADDR_TH1_SCHEDULER_THRD_START_ADDR_SHIFT)) & DSPSS_DSPSS_SCHEDULER_XMEM_ADDR_TH1_SCHEDULER_THRD_START_ADDR_MASK)

#define DSPSS_DSPSS_SCHEDULER_XMEM_ADDR_TH1_SCHEDULER_THRD_END_ADDR_MASK (0xFFFF0000U)
#define DSPSS_DSPSS_SCHEDULER_XMEM_ADDR_TH1_SCHEDULER_THRD_END_ADDR_SHIFT (16U)
#define DSPSS_DSPSS_SCHEDULER_XMEM_ADDR_TH1_SCHEDULER_THRD_END_ADDR_WIDTH (16U)
#define DSPSS_DSPSS_SCHEDULER_XMEM_ADDR_TH1_SCHEDULER_THRD_END_ADDR(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSPSS_SCHEDULER_XMEM_ADDR_TH1_SCHEDULER_THRD_END_ADDR_SHIFT)) & DSPSS_DSPSS_SCHEDULER_XMEM_ADDR_TH1_SCHEDULER_THRD_END_ADDR_MASK)
/*! @} */

/*! @name DSPSS_SCHEDULER_XMEM_TH1 - Thread Threshold And Enable */
/*! @{ */

#define DSPSS_DSPSS_SCHEDULER_XMEM_TH1_SCHEDULER_THRD_TH_MASK (0xFFFFU)
#define DSPSS_DSPSS_SCHEDULER_XMEM_TH1_SCHEDULER_THRD_TH_SHIFT (0U)
#define DSPSS_DSPSS_SCHEDULER_XMEM_TH1_SCHEDULER_THRD_TH_WIDTH (16U)
#define DSPSS_DSPSS_SCHEDULER_XMEM_TH1_SCHEDULER_THRD_TH(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSPSS_SCHEDULER_XMEM_TH1_SCHEDULER_THRD_TH_SHIFT)) & DSPSS_DSPSS_SCHEDULER_XMEM_TH1_SCHEDULER_THRD_TH_MASK)

#define DSPSS_DSPSS_SCHEDULER_XMEM_TH1_SCHEDULER_THRD_EN_MASK (0x80000000U)
#define DSPSS_DSPSS_SCHEDULER_XMEM_TH1_SCHEDULER_THRD_EN_SHIFT (31U)
#define DSPSS_DSPSS_SCHEDULER_XMEM_TH1_SCHEDULER_THRD_EN_WIDTH (1U)
#define DSPSS_DSPSS_SCHEDULER_XMEM_TH1_SCHEDULER_THRD_EN(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSPSS_SCHEDULER_XMEM_TH1_SCHEDULER_THRD_EN_SHIFT)) & DSPSS_DSPSS_SCHEDULER_XMEM_TH1_SCHEDULER_THRD_EN_MASK)
/*! @} */

/*! @name DSPSS_SCHEDULER_DSP_CFG_TH1 - PC Initial Value */
/*! @{ */

#define DSPSS_DSPSS_SCHEDULER_DSP_CFG_TH1_DSPSS_SCHEDULER_DSP_PCINIT_MASK (0x3FFFU)
#define DSPSS_DSPSS_SCHEDULER_DSP_CFG_TH1_DSPSS_SCHEDULER_DSP_PCINIT_SHIFT (0U)
#define DSPSS_DSPSS_SCHEDULER_DSP_CFG_TH1_DSPSS_SCHEDULER_DSP_PCINIT_WIDTH (14U)
#define DSPSS_DSPSS_SCHEDULER_DSP_CFG_TH1_DSPSS_SCHEDULER_DSP_PCINIT(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSPSS_SCHEDULER_DSP_CFG_TH1_DSPSS_SCHEDULER_DSP_PCINIT_SHIFT)) & DSPSS_DSPSS_SCHEDULER_DSP_CFG_TH1_DSPSS_SCHEDULER_DSP_PCINIT_MASK)
/*! @} */

/*! @name DSPSS_SCHEDULER_CURR_XMEM_ADDR_TH1 - Current XMEM Write Pointer */
/*! @{ */

#define DSPSS_DSPSS_SCHEDULER_CURR_XMEM_ADDR_TH1_DSPSS_SCHEDULER_CURR_XMEM_ADDR_MASK (0x7FFFU)
#define DSPSS_DSPSS_SCHEDULER_CURR_XMEM_ADDR_TH1_DSPSS_SCHEDULER_CURR_XMEM_ADDR_SHIFT (0U)
#define DSPSS_DSPSS_SCHEDULER_CURR_XMEM_ADDR_TH1_DSPSS_SCHEDULER_CURR_XMEM_ADDR_WIDTH (15U)
#define DSPSS_DSPSS_SCHEDULER_CURR_XMEM_ADDR_TH1_DSPSS_SCHEDULER_CURR_XMEM_ADDR(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSPSS_SCHEDULER_CURR_XMEM_ADDR_TH1_DSPSS_SCHEDULER_CURR_XMEM_ADDR_SHIFT)) & DSPSS_DSPSS_SCHEDULER_CURR_XMEM_ADDR_TH1_DSPSS_SCHEDULER_CURR_XMEM_ADDR_MASK)
/*! @} */

/*! @name DSP_SDADC_CURR_READ_PTR1 - Last Scheduled-Request Address */
/*! @{ */

#define DSPSS_DSP_SDADC_CURR_READ_PTR1_DSP_SDADC_CURR_READ_PTR_MASK (0x3FFFU)
#define DSPSS_DSP_SDADC_CURR_READ_PTR1_DSP_SDADC_CURR_READ_PTR_SHIFT (0U)
#define DSPSS_DSP_SDADC_CURR_READ_PTR1_DSP_SDADC_CURR_READ_PTR_WIDTH (14U)
#define DSPSS_DSP_SDADC_CURR_READ_PTR1_DSP_SDADC_CURR_READ_PTR(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSP_SDADC_CURR_READ_PTR1_DSP_SDADC_CURR_READ_PTR_SHIFT)) & DSPSS_DSP_SDADC_CURR_READ_PTR1_DSP_SDADC_CURR_READ_PTR_MASK)
/*! @} */

/*! @name DSP_CORE_BUF_ADDR1 - Start And End Pointers For DSP And Cortex-M7 Core Shared Buffer */
/*! @{ */

#define DSPSS_DSP_CORE_BUF_ADDR1_DSP_CORE_BUF_START_ADDR_MASK (0x3FFFU)
#define DSPSS_DSP_CORE_BUF_ADDR1_DSP_CORE_BUF_START_ADDR_SHIFT (0U)
#define DSPSS_DSP_CORE_BUF_ADDR1_DSP_CORE_BUF_START_ADDR_WIDTH (14U)
#define DSPSS_DSP_CORE_BUF_ADDR1_DSP_CORE_BUF_START_ADDR(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSP_CORE_BUF_ADDR1_DSP_CORE_BUF_START_ADDR_SHIFT)) & DSPSS_DSP_CORE_BUF_ADDR1_DSP_CORE_BUF_START_ADDR_MASK)

#define DSPSS_DSP_CORE_BUF_ADDR1_DSP_CORE_BUF_END_ADDR_MASK (0xFFFC0000U)
#define DSPSS_DSP_CORE_BUF_ADDR1_DSP_CORE_BUF_END_ADDR_SHIFT (18U)
#define DSPSS_DSP_CORE_BUF_ADDR1_DSP_CORE_BUF_END_ADDR_WIDTH (14U)
#define DSPSS_DSP_CORE_BUF_ADDR1_DSP_CORE_BUF_END_ADDR(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSP_CORE_BUF_ADDR1_DSP_CORE_BUF_END_ADDR_SHIFT)) & DSPSS_DSP_CORE_BUF_ADDR1_DSP_CORE_BUF_END_ADDR_MASK)
/*! @} */

/*! @name DSP_CORE_CURR_RD_PTR1 - Read Pointer In DSP Buffer */
/*! @{ */

#define DSPSS_DSP_CORE_CURR_RD_PTR1_DSP_CORE_CURR_RD_PTR_MASK (0x3FFFU)
#define DSPSS_DSP_CORE_CURR_RD_PTR1_DSP_CORE_CURR_RD_PTR_SHIFT (0U)
#define DSPSS_DSP_CORE_CURR_RD_PTR1_DSP_CORE_CURR_RD_PTR_WIDTH (14U)
#define DSPSS_DSP_CORE_CURR_RD_PTR1_DSP_CORE_CURR_RD_PTR(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSP_CORE_CURR_RD_PTR1_DSP_CORE_CURR_RD_PTR_SHIFT)) & DSPSS_DSP_CORE_CURR_RD_PTR1_DSP_CORE_CURR_RD_PTR_MASK)

#define DSPSS_DSP_CORE_CURR_RD_PTR1_DSP_CORE_CURR_RD_PTR_WRAP_MASK (0x4000U)
#define DSPSS_DSP_CORE_CURR_RD_PTR1_DSP_CORE_CURR_RD_PTR_WRAP_SHIFT (14U)
#define DSPSS_DSP_CORE_CURR_RD_PTR1_DSP_CORE_CURR_RD_PTR_WRAP_WIDTH (1U)
#define DSPSS_DSP_CORE_CURR_RD_PTR1_DSP_CORE_CURR_RD_PTR_WRAP(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSP_CORE_CURR_RD_PTR1_DSP_CORE_CURR_RD_PTR_WRAP_SHIFT)) & DSPSS_DSP_CORE_CURR_RD_PTR1_DSP_CORE_CURR_RD_PTR_WRAP_MASK)
/*! @} */

/*! @name DSP_CORE_CURR_WR_PTR1 - Write Pointer In DSP Buffer */
/*! @{ */

#define DSPSS_DSP_CORE_CURR_WR_PTR1_DSP_CORE_CURR_WR_PTR_MASK (0x3FFFU)
#define DSPSS_DSP_CORE_CURR_WR_PTR1_DSP_CORE_CURR_WR_PTR_SHIFT (0U)
#define DSPSS_DSP_CORE_CURR_WR_PTR1_DSP_CORE_CURR_WR_PTR_WIDTH (14U)
#define DSPSS_DSP_CORE_CURR_WR_PTR1_DSP_CORE_CURR_WR_PTR(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSP_CORE_CURR_WR_PTR1_DSP_CORE_CURR_WR_PTR_SHIFT)) & DSPSS_DSP_CORE_CURR_WR_PTR1_DSP_CORE_CURR_WR_PTR_MASK)

#define DSPSS_DSP_CORE_CURR_WR_PTR1_DSP_CORE_CURR_WR_PTR_WRAP_MASK (0x4000U)
#define DSPSS_DSP_CORE_CURR_WR_PTR1_DSP_CORE_CURR_WR_PTR_WRAP_SHIFT (14U)
#define DSPSS_DSP_CORE_CURR_WR_PTR1_DSP_CORE_CURR_WR_PTR_WRAP_WIDTH (1U)
#define DSPSS_DSP_CORE_CURR_WR_PTR1_DSP_CORE_CURR_WR_PTR_WRAP(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSP_CORE_CURR_WR_PTR1_DSP_CORE_CURR_WR_PTR_WRAP_SHIFT)) & DSPSS_DSP_CORE_CURR_WR_PTR1_DSP_CORE_CURR_WR_PTR_WRAP_MASK)
/*! @} */

/*! @name DMA_READ_ADDR1 - Reference DMA Read Region */
/*! @{ */

#define DSPSS_DMA_READ_ADDR1_DMA_READ_START_ADDR_MASK (0x3FFFU)
#define DSPSS_DMA_READ_ADDR1_DMA_READ_START_ADDR_SHIFT (0U)
#define DSPSS_DMA_READ_ADDR1_DMA_READ_START_ADDR_WIDTH (14U)
#define DSPSS_DMA_READ_ADDR1_DMA_READ_START_ADDR(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DMA_READ_ADDR1_DMA_READ_START_ADDR_SHIFT)) & DSPSS_DMA_READ_ADDR1_DMA_READ_START_ADDR_MASK)

#define DSPSS_DMA_READ_ADDR1_DMA_READ_END_ADDR_MASK (0xFFFC0000U)
#define DSPSS_DMA_READ_ADDR1_DMA_READ_END_ADDR_SHIFT (18U)
#define DSPSS_DMA_READ_ADDR1_DMA_READ_END_ADDR_WIDTH (14U)
#define DSPSS_DMA_READ_ADDR1_DMA_READ_END_ADDR(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DMA_READ_ADDR1_DMA_READ_END_ADDR_SHIFT)) & DSPSS_DMA_READ_ADDR1_DMA_READ_END_ADDR_MASK)
/*! @} */

/*! @name DMA_ERROR_STATUS1 - DMA Error Status */
/*! @{ */

#define DSPSS_DMA_ERROR_STATUS1_DMA_ADDR_MISMATCH_WR_BUFFER_MASK (0x1U)
#define DSPSS_DMA_ERROR_STATUS1_DMA_ADDR_MISMATCH_WR_BUFFER_SHIFT (0U)
#define DSPSS_DMA_ERROR_STATUS1_DMA_ADDR_MISMATCH_WR_BUFFER_WIDTH (1U)
#define DSPSS_DMA_ERROR_STATUS1_DMA_ADDR_MISMATCH_WR_BUFFER(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DMA_ERROR_STATUS1_DMA_ADDR_MISMATCH_WR_BUFFER_SHIFT)) & DSPSS_DMA_ERROR_STATUS1_DMA_ADDR_MISMATCH_WR_BUFFER_MASK)

#define DSPSS_DMA_ERROR_STATUS1_DMA_ADDR_MISMATCH_RD_BUFFER_MASK (0x2U)
#define DSPSS_DMA_ERROR_STATUS1_DMA_ADDR_MISMATCH_RD_BUFFER_SHIFT (1U)
#define DSPSS_DMA_ERROR_STATUS1_DMA_ADDR_MISMATCH_RD_BUFFER_WIDTH (1U)
#define DSPSS_DMA_ERROR_STATUS1_DMA_ADDR_MISMATCH_RD_BUFFER(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DMA_ERROR_STATUS1_DMA_ADDR_MISMATCH_RD_BUFFER_SHIFT)) & DSPSS_DMA_ERROR_STATUS1_DMA_ADDR_MISMATCH_RD_BUFFER_MASK)

#define DSPSS_DMA_ERROR_STATUS1_DMA_XFR_ERR_WRITE_MASK (0x4U)
#define DSPSS_DMA_ERROR_STATUS1_DMA_XFR_ERR_WRITE_SHIFT (2U)
#define DSPSS_DMA_ERROR_STATUS1_DMA_XFR_ERR_WRITE_WIDTH (1U)
#define DSPSS_DMA_ERROR_STATUS1_DMA_XFR_ERR_WRITE(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DMA_ERROR_STATUS1_DMA_XFR_ERR_WRITE_SHIFT)) & DSPSS_DMA_ERROR_STATUS1_DMA_XFR_ERR_WRITE_MASK)

#define DSPSS_DMA_ERROR_STATUS1_DMA_XFR_ERR_READ_MASK (0x8U)
#define DSPSS_DMA_ERROR_STATUS1_DMA_XFR_ERR_READ_SHIFT (3U)
#define DSPSS_DMA_ERROR_STATUS1_DMA_XFR_ERR_READ_WIDTH (1U)
#define DSPSS_DMA_ERROR_STATUS1_DMA_XFR_ERR_READ(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DMA_ERROR_STATUS1_DMA_XFR_ERR_READ_SHIFT)) & DSPSS_DMA_ERROR_STATUS1_DMA_XFR_ERR_READ_MASK)
/*! @} */

/*! @name DMA_WRITE_ADDR1 - Reference DMA Write Region */
/*! @{ */

#define DSPSS_DMA_WRITE_ADDR1_DMA_WRITE_START_ADDR_MASK (0x3FFFU)
#define DSPSS_DMA_WRITE_ADDR1_DMA_WRITE_START_ADDR_SHIFT (0U)
#define DSPSS_DMA_WRITE_ADDR1_DMA_WRITE_START_ADDR_WIDTH (14U)
#define DSPSS_DMA_WRITE_ADDR1_DMA_WRITE_START_ADDR(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DMA_WRITE_ADDR1_DMA_WRITE_START_ADDR_SHIFT)) & DSPSS_DMA_WRITE_ADDR1_DMA_WRITE_START_ADDR_MASK)

#define DSPSS_DMA_WRITE_ADDR1_DMA_WRITE_END_ADDR_MASK (0xFFFC0000U)
#define DSPSS_DMA_WRITE_ADDR1_DMA_WRITE_END_ADDR_SHIFT (18U)
#define DSPSS_DMA_WRITE_ADDR1_DMA_WRITE_END_ADDR_WIDTH (14U)
#define DSPSS_DMA_WRITE_ADDR1_DMA_WRITE_END_ADDR(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DMA_WRITE_ADDR1_DMA_WRITE_END_ADDR_SHIFT)) & DSPSS_DMA_WRITE_ADDR1_DMA_WRITE_END_ADDR_MASK)
/*! @} */

/*! @name DMA_CURR_WR_PTR1 - DMA Current Write Pointer */
/*! @{ */

#define DSPSS_DMA_CURR_WR_PTR1_DMA_CURR_WRITE_PTR_MASK (0x3FFFU)
#define DSPSS_DMA_CURR_WR_PTR1_DMA_CURR_WRITE_PTR_SHIFT (0U)
#define DSPSS_DMA_CURR_WR_PTR1_DMA_CURR_WRITE_PTR_WIDTH (14U)
#define DSPSS_DMA_CURR_WR_PTR1_DMA_CURR_WRITE_PTR(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DMA_CURR_WR_PTR1_DMA_CURR_WRITE_PTR_SHIFT)) & DSPSS_DMA_CURR_WR_PTR1_DMA_CURR_WRITE_PTR_MASK)

#define DSPSS_DMA_CURR_WR_PTR1_DMA_WRITE_PTR_WRAP_MASK (0x80000000U)
#define DSPSS_DMA_CURR_WR_PTR1_DMA_WRITE_PTR_WRAP_SHIFT (31U)
#define DSPSS_DMA_CURR_WR_PTR1_DMA_WRITE_PTR_WRAP_WIDTH (1U)
#define DSPSS_DMA_CURR_WR_PTR1_DMA_WRITE_PTR_WRAP(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DMA_CURR_WR_PTR1_DMA_WRITE_PTR_WRAP_SHIFT)) & DSPSS_DMA_CURR_WR_PTR1_DMA_WRITE_PTR_WRAP_MASK)
/*! @} */

/*! @name DMA_CURR_RD_PTR1 - DMA Current Read Pointer */
/*! @{ */

#define DSPSS_DMA_CURR_RD_PTR1_DMA_CURR_READ_PTR_MASK (0x3FFFU)
#define DSPSS_DMA_CURR_RD_PTR1_DMA_CURR_READ_PTR_SHIFT (0U)
#define DSPSS_DMA_CURR_RD_PTR1_DMA_CURR_READ_PTR_WIDTH (14U)
#define DSPSS_DMA_CURR_RD_PTR1_DMA_CURR_READ_PTR(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DMA_CURR_RD_PTR1_DMA_CURR_READ_PTR_SHIFT)) & DSPSS_DMA_CURR_RD_PTR1_DMA_CURR_READ_PTR_MASK)

#define DSPSS_DMA_CURR_RD_PTR1_DMA_READ_PTR_WRAP_MASK (0x80000000U)
#define DSPSS_DMA_CURR_RD_PTR1_DMA_READ_PTR_WRAP_SHIFT (31U)
#define DSPSS_DMA_CURR_RD_PTR1_DMA_READ_PTR_WRAP_WIDTH (1U)
#define DSPSS_DMA_CURR_RD_PTR1_DMA_READ_PTR_WRAP(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DMA_CURR_RD_PTR1_DMA_READ_PTR_WRAP_SHIFT)) & DSPSS_DMA_CURR_RD_PTR1_DMA_READ_PTR_WRAP_MASK)
/*! @} */

/*! @name DSP_TO_DMA_REQUEST_STATUS1 - DMA Request Status */
/*! @{ */

#define DSPSS_DSP_TO_DMA_REQUEST_STATUS1_DSP_TO_DMA_REQUEST_STATUS_MASK (0x1U)
#define DSPSS_DSP_TO_DMA_REQUEST_STATUS1_DSP_TO_DMA_REQUEST_STATUS_SHIFT (0U)
#define DSPSS_DSP_TO_DMA_REQUEST_STATUS1_DSP_TO_DMA_REQUEST_STATUS_WIDTH (1U)
#define DSPSS_DSP_TO_DMA_REQUEST_STATUS1_DSP_TO_DMA_REQUEST_STATUS(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSP_TO_DMA_REQUEST_STATUS1_DSP_TO_DMA_REQUEST_STATUS_SHIFT)) & DSPSS_DSP_TO_DMA_REQUEST_STATUS1_DSP_TO_DMA_REQUEST_STATUS_MASK)

#define DSPSS_DSP_TO_DMA_REQUEST_STATUS1_DMA_TO_DSP_ACK_STATUS_MASK (0x2U)
#define DSPSS_DSP_TO_DMA_REQUEST_STATUS1_DMA_TO_DSP_ACK_STATUS_SHIFT (1U)
#define DSPSS_DSP_TO_DMA_REQUEST_STATUS1_DMA_TO_DSP_ACK_STATUS_WIDTH (1U)
#define DSPSS_DSP_TO_DMA_REQUEST_STATUS1_DMA_TO_DSP_ACK_STATUS(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSP_TO_DMA_REQUEST_STATUS1_DMA_TO_DSP_ACK_STATUS_SHIFT)) & DSPSS_DSP_TO_DMA_REQUEST_STATUS1_DMA_TO_DSP_ACK_STATUS_MASK)
/*! @} */

/*! @name THREAD_SUSPEND_REQ1 - Thread Suspend Request For Thread Disabling/PCINIT Change */
/*! @{ */

#define DSPSS_THREAD_SUSPEND_REQ1_SUSPEND_REQ_MASK (0x1U)
#define DSPSS_THREAD_SUSPEND_REQ1_SUSPEND_REQ_SHIFT (0U)
#define DSPSS_THREAD_SUSPEND_REQ1_SUSPEND_REQ_WIDTH (1U)
#define DSPSS_THREAD_SUSPEND_REQ1_SUSPEND_REQ(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_THREAD_SUSPEND_REQ1_SUSPEND_REQ_SHIFT)) & DSPSS_THREAD_SUSPEND_REQ1_SUSPEND_REQ_MASK)
/*! @} */

/*! @name DSPSS_DSP_TH_STATUS1 - Thread Status */
/*! @{ */

#define DSPSS_DSPSS_DSP_TH_STATUS1_dspss_th_suspended_MASK (0x1U)
#define DSPSS_DSPSS_DSP_TH_STATUS1_dspss_th_suspended_SHIFT (0U)
#define DSPSS_DSPSS_DSP_TH_STATUS1_dspss_th_suspended_WIDTH (1U)
#define DSPSS_DSPSS_DSP_TH_STATUS1_dspss_th_suspended(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSPSS_DSP_TH_STATUS1_dspss_th_suspended_SHIFT)) & DSPSS_DSPSS_DSP_TH_STATUS1_dspss_th_suspended_MASK)
/*! @} */

/*! @name DSP_CORE_BUFFER_STATUS1 - DSP Core Buffer Status */
/*! @{ */

#define DSPSS_DSP_CORE_BUFFER_STATUS1_DSP_CORE_BUFFER_OVF_MASK (0x2U)
#define DSPSS_DSP_CORE_BUFFER_STATUS1_DSP_CORE_BUFFER_OVF_SHIFT (1U)
#define DSPSS_DSP_CORE_BUFFER_STATUS1_DSP_CORE_BUFFER_OVF_WIDTH (1U)
#define DSPSS_DSP_CORE_BUFFER_STATUS1_DSP_CORE_BUFFER_OVF(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSP_CORE_BUFFER_STATUS1_DSP_CORE_BUFFER_OVF_SHIFT)) & DSPSS_DSP_CORE_BUFFER_STATUS1_DSP_CORE_BUFFER_OVF_MASK)

#define DSPSS_DSP_CORE_BUFFER_STATUS1_DSP_CORE_BUFFER_UNDF_MASK (0x4U)
#define DSPSS_DSP_CORE_BUFFER_STATUS1_DSP_CORE_BUFFER_UNDF_SHIFT (2U)
#define DSPSS_DSP_CORE_BUFFER_STATUS1_DSP_CORE_BUFFER_UNDF_WIDTH (1U)
#define DSPSS_DSP_CORE_BUFFER_STATUS1_DSP_CORE_BUFFER_UNDF(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSP_CORE_BUFFER_STATUS1_DSP_CORE_BUFFER_UNDF_SHIFT)) & DSPSS_DSP_CORE_BUFFER_STATUS1_DSP_CORE_BUFFER_UNDF_MASK)
/*! @} */

/*! @name DSP_TO_CORE_TRIG_ERR_STATUS1 - DSP To Cortex-M7 Core Error Trigger */
/*! @{ */

#define DSPSS_DSP_TO_CORE_TRIG_ERR_STATUS1_DSP_TO_CORE_TRIG_ERR_STATUS_MASK (0x1U)
#define DSPSS_DSP_TO_CORE_TRIG_ERR_STATUS1_DSP_TO_CORE_TRIG_ERR_STATUS_SHIFT (0U)
#define DSPSS_DSP_TO_CORE_TRIG_ERR_STATUS1_DSP_TO_CORE_TRIG_ERR_STATUS_WIDTH (1U)
#define DSPSS_DSP_TO_CORE_TRIG_ERR_STATUS1_DSP_TO_CORE_TRIG_ERR_STATUS(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSP_TO_CORE_TRIG_ERR_STATUS1_DSP_TO_CORE_TRIG_ERR_STATUS_SHIFT)) & DSPSS_DSP_TO_CORE_TRIG_ERR_STATUS1_DSP_TO_CORE_TRIG_ERR_STATUS_MASK)
/*! @} */

/*! @name DS_GATE_STATUS_REGISTER1 - DSP Output Control */
/*! @{ */

#define DSPSS_DS_GATE_STATUS_REGISTER1_DS_GATE_STATUS_REGISTER_MASK (0x1U)
#define DSPSS_DS_GATE_STATUS_REGISTER1_DS_GATE_STATUS_REGISTER_SHIFT (0U)
#define DSPSS_DS_GATE_STATUS_REGISTER1_DS_GATE_STATUS_REGISTER_WIDTH (1U)
#define DSPSS_DS_GATE_STATUS_REGISTER1_DS_GATE_STATUS_REGISTER(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DS_GATE_STATUS_REGISTER1_DS_GATE_STATUS_REGISTER_SHIFT)) & DSPSS_DS_GATE_STATUS_REGISTER1_DS_GATE_STATUS_REGISTER_MASK)
/*! @} */

/*! @name DS_GATE_TRIGMUX_REGISTER1 - DSP Trigger To TRIGMUX */
/*! @{ */

#define DSPSS_DS_GATE_TRIGMUX_REGISTER1_DS_GATE_TRIGMUX_TRIGGER_MASK (0x1U)
#define DSPSS_DS_GATE_TRIGMUX_REGISTER1_DS_GATE_TRIGMUX_TRIGGER_SHIFT (0U)
#define DSPSS_DS_GATE_TRIGMUX_REGISTER1_DS_GATE_TRIGMUX_TRIGGER_WIDTH (1U)
#define DSPSS_DS_GATE_TRIGMUX_REGISTER1_DS_GATE_TRIGMUX_TRIGGER(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DS_GATE_TRIGMUX_REGISTER1_DS_GATE_TRIGMUX_TRIGGER_SHIFT)) & DSPSS_DS_GATE_TRIGMUX_REGISTER1_DS_GATE_TRIGMUX_TRIGGER_MASK)
/*! @} */

/*! @name HW_CTRL_DMA_REQ_STOP1 - Stop DMA Request */
/*! @{ */

#define DSPSS_HW_CTRL_DMA_REQ_STOP1_STOP_MASK    (0x1U)
#define DSPSS_HW_CTRL_DMA_REQ_STOP1_STOP_SHIFT   (0U)
#define DSPSS_HW_CTRL_DMA_REQ_STOP1_STOP_WIDTH   (1U)
#define DSPSS_HW_CTRL_DMA_REQ_STOP1_STOP(x)      (((uint32_t)(((uint32_t)(x)) << DSPSS_HW_CTRL_DMA_REQ_STOP1_STOP_SHIFT)) & DSPSS_HW_CTRL_DMA_REQ_STOP1_STOP_MASK)
/*! @} */

/*! @name DMA_ERROR_CTRL1 - DMA Error Control */
/*! @{ */

#define DSPSS_DMA_ERROR_CTRL1_DONE_MASK          (0x1U)
#define DSPSS_DMA_ERROR_CTRL1_DONE_SHIFT         (0U)
#define DSPSS_DMA_ERROR_CTRL1_DONE_WIDTH         (1U)
#define DSPSS_DMA_ERROR_CTRL1_DONE(x)            (((uint32_t)(((uint32_t)(x)) << DSPSS_DMA_ERROR_CTRL1_DONE_SHIFT)) & DSPSS_DMA_ERROR_CTRL1_DONE_MASK)
/*! @} */

/*! @name HW_CTRL_DMA_REQ_RESPONSE1 - Hardware Control Handling for DMA Request And Response */
/*! @{ */

#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE1_START_MASK (0x1U)
#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE1_START_SHIFT (0U)
#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE1_START_WIDTH (1U)
#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE1_START(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_HW_CTRL_DMA_REQ_RESPONSE1_START_SHIFT)) & DSPSS_HW_CTRL_DMA_REQ_RESPONSE1_START_MASK)

#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE1_NUM_OF_DMA_REQ_MASK (0x1FEU)
#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE1_NUM_OF_DMA_REQ_SHIFT (1U)
#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE1_NUM_OF_DMA_REQ_WIDTH (8U)
#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE1_NUM_OF_DMA_REQ(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_HW_CTRL_DMA_REQ_RESPONSE1_NUM_OF_DMA_REQ_SHIFT)) & DSPSS_HW_CTRL_DMA_REQ_RESPONSE1_NUM_OF_DMA_REQ_MASK)

#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE1_DONE_MASK (0x200U)
#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE1_DONE_SHIFT (9U)
#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE1_DONE_WIDTH (1U)
#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE1_DONE(x)  (((uint32_t)(((uint32_t)(x)) << DSPSS_HW_CTRL_DMA_REQ_RESPONSE1_DONE_SHIFT)) & DSPSS_HW_CTRL_DMA_REQ_RESPONSE1_DONE_MASK)

#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE1_NUM_OF_DMA_REQ_PEND_MASK (0x3FC00U)
#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE1_NUM_OF_DMA_REQ_PEND_SHIFT (10U)
#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE1_NUM_OF_DMA_REQ_PEND_WIDTH (8U)
#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE1_NUM_OF_DMA_REQ_PEND(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_HW_CTRL_DMA_REQ_RESPONSE1_NUM_OF_DMA_REQ_PEND_SHIFT)) & DSPSS_HW_CTRL_DMA_REQ_RESPONSE1_NUM_OF_DMA_REQ_PEND_MASK)
/*! @} */

/*! @name DSPSS_SCHEDULER_XMEM_ADDR_TH2 - Thread Start And End Address Location Configuration */
/*! @{ */

#define DSPSS_DSPSS_SCHEDULER_XMEM_ADDR_TH2_SCHEDULER_THRD_START_ADDR_MASK (0xFFFFU)
#define DSPSS_DSPSS_SCHEDULER_XMEM_ADDR_TH2_SCHEDULER_THRD_START_ADDR_SHIFT (0U)
#define DSPSS_DSPSS_SCHEDULER_XMEM_ADDR_TH2_SCHEDULER_THRD_START_ADDR_WIDTH (16U)
#define DSPSS_DSPSS_SCHEDULER_XMEM_ADDR_TH2_SCHEDULER_THRD_START_ADDR(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSPSS_SCHEDULER_XMEM_ADDR_TH2_SCHEDULER_THRD_START_ADDR_SHIFT)) & DSPSS_DSPSS_SCHEDULER_XMEM_ADDR_TH2_SCHEDULER_THRD_START_ADDR_MASK)

#define DSPSS_DSPSS_SCHEDULER_XMEM_ADDR_TH2_SCHEDULER_THRD_END_ADDR_MASK (0xFFFF0000U)
#define DSPSS_DSPSS_SCHEDULER_XMEM_ADDR_TH2_SCHEDULER_THRD_END_ADDR_SHIFT (16U)
#define DSPSS_DSPSS_SCHEDULER_XMEM_ADDR_TH2_SCHEDULER_THRD_END_ADDR_WIDTH (16U)
#define DSPSS_DSPSS_SCHEDULER_XMEM_ADDR_TH2_SCHEDULER_THRD_END_ADDR(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSPSS_SCHEDULER_XMEM_ADDR_TH2_SCHEDULER_THRD_END_ADDR_SHIFT)) & DSPSS_DSPSS_SCHEDULER_XMEM_ADDR_TH2_SCHEDULER_THRD_END_ADDR_MASK)
/*! @} */

/*! @name DSPSS_SCHEDULER_XMEM_TH2 - Thread Threshold And Enable */
/*! @{ */

#define DSPSS_DSPSS_SCHEDULER_XMEM_TH2_SCHEDULER_THRD_TH_MASK (0xFFFFU)
#define DSPSS_DSPSS_SCHEDULER_XMEM_TH2_SCHEDULER_THRD_TH_SHIFT (0U)
#define DSPSS_DSPSS_SCHEDULER_XMEM_TH2_SCHEDULER_THRD_TH_WIDTH (16U)
#define DSPSS_DSPSS_SCHEDULER_XMEM_TH2_SCHEDULER_THRD_TH(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSPSS_SCHEDULER_XMEM_TH2_SCHEDULER_THRD_TH_SHIFT)) & DSPSS_DSPSS_SCHEDULER_XMEM_TH2_SCHEDULER_THRD_TH_MASK)

#define DSPSS_DSPSS_SCHEDULER_XMEM_TH2_SCHEDULER_THRD_EN_MASK (0x80000000U)
#define DSPSS_DSPSS_SCHEDULER_XMEM_TH2_SCHEDULER_THRD_EN_SHIFT (31U)
#define DSPSS_DSPSS_SCHEDULER_XMEM_TH2_SCHEDULER_THRD_EN_WIDTH (1U)
#define DSPSS_DSPSS_SCHEDULER_XMEM_TH2_SCHEDULER_THRD_EN(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSPSS_SCHEDULER_XMEM_TH2_SCHEDULER_THRD_EN_SHIFT)) & DSPSS_DSPSS_SCHEDULER_XMEM_TH2_SCHEDULER_THRD_EN_MASK)
/*! @} */

/*! @name DSPSS_SCHEDULER_DSP_CFG_TH2 - PC Initial Value */
/*! @{ */

#define DSPSS_DSPSS_SCHEDULER_DSP_CFG_TH2_DSPSS_SCHEDULER_DSP_PCINIT_MASK (0x3FFFU)
#define DSPSS_DSPSS_SCHEDULER_DSP_CFG_TH2_DSPSS_SCHEDULER_DSP_PCINIT_SHIFT (0U)
#define DSPSS_DSPSS_SCHEDULER_DSP_CFG_TH2_DSPSS_SCHEDULER_DSP_PCINIT_WIDTH (14U)
#define DSPSS_DSPSS_SCHEDULER_DSP_CFG_TH2_DSPSS_SCHEDULER_DSP_PCINIT(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSPSS_SCHEDULER_DSP_CFG_TH2_DSPSS_SCHEDULER_DSP_PCINIT_SHIFT)) & DSPSS_DSPSS_SCHEDULER_DSP_CFG_TH2_DSPSS_SCHEDULER_DSP_PCINIT_MASK)
/*! @} */

/*! @name DSPSS_SCHEDULER_CURR_XMEM_ADDR_TH2 - Current XMEM Write Pointer */
/*! @{ */

#define DSPSS_DSPSS_SCHEDULER_CURR_XMEM_ADDR_TH2_DSPSS_SCHEDULER_CURR_XMEM_ADDR_MASK (0x7FFFU)
#define DSPSS_DSPSS_SCHEDULER_CURR_XMEM_ADDR_TH2_DSPSS_SCHEDULER_CURR_XMEM_ADDR_SHIFT (0U)
#define DSPSS_DSPSS_SCHEDULER_CURR_XMEM_ADDR_TH2_DSPSS_SCHEDULER_CURR_XMEM_ADDR_WIDTH (15U)
#define DSPSS_DSPSS_SCHEDULER_CURR_XMEM_ADDR_TH2_DSPSS_SCHEDULER_CURR_XMEM_ADDR(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSPSS_SCHEDULER_CURR_XMEM_ADDR_TH2_DSPSS_SCHEDULER_CURR_XMEM_ADDR_SHIFT)) & DSPSS_DSPSS_SCHEDULER_CURR_XMEM_ADDR_TH2_DSPSS_SCHEDULER_CURR_XMEM_ADDR_MASK)
/*! @} */

/*! @name DSP_SDADC_CURR_READ_PTR2 - Last Scheduled-Request Address */
/*! @{ */

#define DSPSS_DSP_SDADC_CURR_READ_PTR2_DSP_SDADC_CURR_READ_PTR_MASK (0x3FFFU)
#define DSPSS_DSP_SDADC_CURR_READ_PTR2_DSP_SDADC_CURR_READ_PTR_SHIFT (0U)
#define DSPSS_DSP_SDADC_CURR_READ_PTR2_DSP_SDADC_CURR_READ_PTR_WIDTH (14U)
#define DSPSS_DSP_SDADC_CURR_READ_PTR2_DSP_SDADC_CURR_READ_PTR(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSP_SDADC_CURR_READ_PTR2_DSP_SDADC_CURR_READ_PTR_SHIFT)) & DSPSS_DSP_SDADC_CURR_READ_PTR2_DSP_SDADC_CURR_READ_PTR_MASK)
/*! @} */

/*! @name DSP_CORE_BUF_ADDR2 - Start And End Pointers For DSP And Cortex-M7 Core Shared Buffer */
/*! @{ */

#define DSPSS_DSP_CORE_BUF_ADDR2_DSP_CORE_BUF_START_ADDR_MASK (0x3FFFU)
#define DSPSS_DSP_CORE_BUF_ADDR2_DSP_CORE_BUF_START_ADDR_SHIFT (0U)
#define DSPSS_DSP_CORE_BUF_ADDR2_DSP_CORE_BUF_START_ADDR_WIDTH (14U)
#define DSPSS_DSP_CORE_BUF_ADDR2_DSP_CORE_BUF_START_ADDR(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSP_CORE_BUF_ADDR2_DSP_CORE_BUF_START_ADDR_SHIFT)) & DSPSS_DSP_CORE_BUF_ADDR2_DSP_CORE_BUF_START_ADDR_MASK)

#define DSPSS_DSP_CORE_BUF_ADDR2_DSP_CORE_BUF_END_ADDR_MASK (0xFFFC0000U)
#define DSPSS_DSP_CORE_BUF_ADDR2_DSP_CORE_BUF_END_ADDR_SHIFT (18U)
#define DSPSS_DSP_CORE_BUF_ADDR2_DSP_CORE_BUF_END_ADDR_WIDTH (14U)
#define DSPSS_DSP_CORE_BUF_ADDR2_DSP_CORE_BUF_END_ADDR(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSP_CORE_BUF_ADDR2_DSP_CORE_BUF_END_ADDR_SHIFT)) & DSPSS_DSP_CORE_BUF_ADDR2_DSP_CORE_BUF_END_ADDR_MASK)
/*! @} */

/*! @name DSP_CORE_CURR_RD_PTR2 - Read Pointer In DSP Buffer */
/*! @{ */

#define DSPSS_DSP_CORE_CURR_RD_PTR2_DSP_CORE_CURR_RD_PTR_MASK (0x3FFFU)
#define DSPSS_DSP_CORE_CURR_RD_PTR2_DSP_CORE_CURR_RD_PTR_SHIFT (0U)
#define DSPSS_DSP_CORE_CURR_RD_PTR2_DSP_CORE_CURR_RD_PTR_WIDTH (14U)
#define DSPSS_DSP_CORE_CURR_RD_PTR2_DSP_CORE_CURR_RD_PTR(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSP_CORE_CURR_RD_PTR2_DSP_CORE_CURR_RD_PTR_SHIFT)) & DSPSS_DSP_CORE_CURR_RD_PTR2_DSP_CORE_CURR_RD_PTR_MASK)

#define DSPSS_DSP_CORE_CURR_RD_PTR2_DSP_CORE_CURR_RD_PTR_WRAP_MASK (0x4000U)
#define DSPSS_DSP_CORE_CURR_RD_PTR2_DSP_CORE_CURR_RD_PTR_WRAP_SHIFT (14U)
#define DSPSS_DSP_CORE_CURR_RD_PTR2_DSP_CORE_CURR_RD_PTR_WRAP_WIDTH (1U)
#define DSPSS_DSP_CORE_CURR_RD_PTR2_DSP_CORE_CURR_RD_PTR_WRAP(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSP_CORE_CURR_RD_PTR2_DSP_CORE_CURR_RD_PTR_WRAP_SHIFT)) & DSPSS_DSP_CORE_CURR_RD_PTR2_DSP_CORE_CURR_RD_PTR_WRAP_MASK)
/*! @} */

/*! @name DSP_CORE_CURR_WR_PTR2 - Write Pointer In DSP Buffer */
/*! @{ */

#define DSPSS_DSP_CORE_CURR_WR_PTR2_DSP_CORE_CURR_WR_PTR_MASK (0x3FFFU)
#define DSPSS_DSP_CORE_CURR_WR_PTR2_DSP_CORE_CURR_WR_PTR_SHIFT (0U)
#define DSPSS_DSP_CORE_CURR_WR_PTR2_DSP_CORE_CURR_WR_PTR_WIDTH (14U)
#define DSPSS_DSP_CORE_CURR_WR_PTR2_DSP_CORE_CURR_WR_PTR(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSP_CORE_CURR_WR_PTR2_DSP_CORE_CURR_WR_PTR_SHIFT)) & DSPSS_DSP_CORE_CURR_WR_PTR2_DSP_CORE_CURR_WR_PTR_MASK)

#define DSPSS_DSP_CORE_CURR_WR_PTR2_DSP_CORE_CURR_WR_PTR_WRAP_MASK (0x4000U)
#define DSPSS_DSP_CORE_CURR_WR_PTR2_DSP_CORE_CURR_WR_PTR_WRAP_SHIFT (14U)
#define DSPSS_DSP_CORE_CURR_WR_PTR2_DSP_CORE_CURR_WR_PTR_WRAP_WIDTH (1U)
#define DSPSS_DSP_CORE_CURR_WR_PTR2_DSP_CORE_CURR_WR_PTR_WRAP(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSP_CORE_CURR_WR_PTR2_DSP_CORE_CURR_WR_PTR_WRAP_SHIFT)) & DSPSS_DSP_CORE_CURR_WR_PTR2_DSP_CORE_CURR_WR_PTR_WRAP_MASK)
/*! @} */

/*! @name DMA_READ_ADDR2 - Reference DMA Read Region */
/*! @{ */

#define DSPSS_DMA_READ_ADDR2_DMA_READ_START_ADDR_MASK (0x3FFFU)
#define DSPSS_DMA_READ_ADDR2_DMA_READ_START_ADDR_SHIFT (0U)
#define DSPSS_DMA_READ_ADDR2_DMA_READ_START_ADDR_WIDTH (14U)
#define DSPSS_DMA_READ_ADDR2_DMA_READ_START_ADDR(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DMA_READ_ADDR2_DMA_READ_START_ADDR_SHIFT)) & DSPSS_DMA_READ_ADDR2_DMA_READ_START_ADDR_MASK)

#define DSPSS_DMA_READ_ADDR2_DMA_READ_END_ADDR_MASK (0xFFFC0000U)
#define DSPSS_DMA_READ_ADDR2_DMA_READ_END_ADDR_SHIFT (18U)
#define DSPSS_DMA_READ_ADDR2_DMA_READ_END_ADDR_WIDTH (14U)
#define DSPSS_DMA_READ_ADDR2_DMA_READ_END_ADDR(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DMA_READ_ADDR2_DMA_READ_END_ADDR_SHIFT)) & DSPSS_DMA_READ_ADDR2_DMA_READ_END_ADDR_MASK)
/*! @} */

/*! @name DMA_ERROR_STATUS2 - DMA Error Status */
/*! @{ */

#define DSPSS_DMA_ERROR_STATUS2_DMA_ADDR_MISMATCH_WR_BUFFER_MASK (0x1U)
#define DSPSS_DMA_ERROR_STATUS2_DMA_ADDR_MISMATCH_WR_BUFFER_SHIFT (0U)
#define DSPSS_DMA_ERROR_STATUS2_DMA_ADDR_MISMATCH_WR_BUFFER_WIDTH (1U)
#define DSPSS_DMA_ERROR_STATUS2_DMA_ADDR_MISMATCH_WR_BUFFER(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DMA_ERROR_STATUS2_DMA_ADDR_MISMATCH_WR_BUFFER_SHIFT)) & DSPSS_DMA_ERROR_STATUS2_DMA_ADDR_MISMATCH_WR_BUFFER_MASK)

#define DSPSS_DMA_ERROR_STATUS2_DMA_ADDR_MISMATCH_RD_BUFFER_MASK (0x2U)
#define DSPSS_DMA_ERROR_STATUS2_DMA_ADDR_MISMATCH_RD_BUFFER_SHIFT (1U)
#define DSPSS_DMA_ERROR_STATUS2_DMA_ADDR_MISMATCH_RD_BUFFER_WIDTH (1U)
#define DSPSS_DMA_ERROR_STATUS2_DMA_ADDR_MISMATCH_RD_BUFFER(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DMA_ERROR_STATUS2_DMA_ADDR_MISMATCH_RD_BUFFER_SHIFT)) & DSPSS_DMA_ERROR_STATUS2_DMA_ADDR_MISMATCH_RD_BUFFER_MASK)

#define DSPSS_DMA_ERROR_STATUS2_DMA_XFR_ERR_WRITE_MASK (0x4U)
#define DSPSS_DMA_ERROR_STATUS2_DMA_XFR_ERR_WRITE_SHIFT (2U)
#define DSPSS_DMA_ERROR_STATUS2_DMA_XFR_ERR_WRITE_WIDTH (1U)
#define DSPSS_DMA_ERROR_STATUS2_DMA_XFR_ERR_WRITE(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DMA_ERROR_STATUS2_DMA_XFR_ERR_WRITE_SHIFT)) & DSPSS_DMA_ERROR_STATUS2_DMA_XFR_ERR_WRITE_MASK)

#define DSPSS_DMA_ERROR_STATUS2_DMA_XFR_ERR_READ_MASK (0x8U)
#define DSPSS_DMA_ERROR_STATUS2_DMA_XFR_ERR_READ_SHIFT (3U)
#define DSPSS_DMA_ERROR_STATUS2_DMA_XFR_ERR_READ_WIDTH (1U)
#define DSPSS_DMA_ERROR_STATUS2_DMA_XFR_ERR_READ(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DMA_ERROR_STATUS2_DMA_XFR_ERR_READ_SHIFT)) & DSPSS_DMA_ERROR_STATUS2_DMA_XFR_ERR_READ_MASK)
/*! @} */

/*! @name DMA_WRITE_ADDR2 - Reference DMA Write Region */
/*! @{ */

#define DSPSS_DMA_WRITE_ADDR2_DMA_WRITE_START_ADDR_MASK (0x3FFFU)
#define DSPSS_DMA_WRITE_ADDR2_DMA_WRITE_START_ADDR_SHIFT (0U)
#define DSPSS_DMA_WRITE_ADDR2_DMA_WRITE_START_ADDR_WIDTH (14U)
#define DSPSS_DMA_WRITE_ADDR2_DMA_WRITE_START_ADDR(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DMA_WRITE_ADDR2_DMA_WRITE_START_ADDR_SHIFT)) & DSPSS_DMA_WRITE_ADDR2_DMA_WRITE_START_ADDR_MASK)

#define DSPSS_DMA_WRITE_ADDR2_DMA_WRITE_END_ADDR_MASK (0xFFFC0000U)
#define DSPSS_DMA_WRITE_ADDR2_DMA_WRITE_END_ADDR_SHIFT (18U)
#define DSPSS_DMA_WRITE_ADDR2_DMA_WRITE_END_ADDR_WIDTH (14U)
#define DSPSS_DMA_WRITE_ADDR2_DMA_WRITE_END_ADDR(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DMA_WRITE_ADDR2_DMA_WRITE_END_ADDR_SHIFT)) & DSPSS_DMA_WRITE_ADDR2_DMA_WRITE_END_ADDR_MASK)
/*! @} */

/*! @name DMA_CURR_WR_PTR2 - DMA Current Write Pointer */
/*! @{ */

#define DSPSS_DMA_CURR_WR_PTR2_DMA_CURR_WRITE_PTR_MASK (0x3FFFU)
#define DSPSS_DMA_CURR_WR_PTR2_DMA_CURR_WRITE_PTR_SHIFT (0U)
#define DSPSS_DMA_CURR_WR_PTR2_DMA_CURR_WRITE_PTR_WIDTH (14U)
#define DSPSS_DMA_CURR_WR_PTR2_DMA_CURR_WRITE_PTR(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DMA_CURR_WR_PTR2_DMA_CURR_WRITE_PTR_SHIFT)) & DSPSS_DMA_CURR_WR_PTR2_DMA_CURR_WRITE_PTR_MASK)

#define DSPSS_DMA_CURR_WR_PTR2_DMA_WRITE_PTR_WRAP_MASK (0x80000000U)
#define DSPSS_DMA_CURR_WR_PTR2_DMA_WRITE_PTR_WRAP_SHIFT (31U)
#define DSPSS_DMA_CURR_WR_PTR2_DMA_WRITE_PTR_WRAP_WIDTH (1U)
#define DSPSS_DMA_CURR_WR_PTR2_DMA_WRITE_PTR_WRAP(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DMA_CURR_WR_PTR2_DMA_WRITE_PTR_WRAP_SHIFT)) & DSPSS_DMA_CURR_WR_PTR2_DMA_WRITE_PTR_WRAP_MASK)
/*! @} */

/*! @name DMA_CURR_RD_PTR2 - DMA Current Read Pointer */
/*! @{ */

#define DSPSS_DMA_CURR_RD_PTR2_DMA_CURR_READ_PTR_MASK (0x3FFFU)
#define DSPSS_DMA_CURR_RD_PTR2_DMA_CURR_READ_PTR_SHIFT (0U)
#define DSPSS_DMA_CURR_RD_PTR2_DMA_CURR_READ_PTR_WIDTH (14U)
#define DSPSS_DMA_CURR_RD_PTR2_DMA_CURR_READ_PTR(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DMA_CURR_RD_PTR2_DMA_CURR_READ_PTR_SHIFT)) & DSPSS_DMA_CURR_RD_PTR2_DMA_CURR_READ_PTR_MASK)

#define DSPSS_DMA_CURR_RD_PTR2_DMA_READ_PTR_WRAP_MASK (0x80000000U)
#define DSPSS_DMA_CURR_RD_PTR2_DMA_READ_PTR_WRAP_SHIFT (31U)
#define DSPSS_DMA_CURR_RD_PTR2_DMA_READ_PTR_WRAP_WIDTH (1U)
#define DSPSS_DMA_CURR_RD_PTR2_DMA_READ_PTR_WRAP(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DMA_CURR_RD_PTR2_DMA_READ_PTR_WRAP_SHIFT)) & DSPSS_DMA_CURR_RD_PTR2_DMA_READ_PTR_WRAP_MASK)
/*! @} */

/*! @name DSP_TO_DMA_REQUEST_STATUS2 - DMA Request Status */
/*! @{ */

#define DSPSS_DSP_TO_DMA_REQUEST_STATUS2_DSP_TO_DMA_REQUEST_STATUS_MASK (0x1U)
#define DSPSS_DSP_TO_DMA_REQUEST_STATUS2_DSP_TO_DMA_REQUEST_STATUS_SHIFT (0U)
#define DSPSS_DSP_TO_DMA_REQUEST_STATUS2_DSP_TO_DMA_REQUEST_STATUS_WIDTH (1U)
#define DSPSS_DSP_TO_DMA_REQUEST_STATUS2_DSP_TO_DMA_REQUEST_STATUS(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSP_TO_DMA_REQUEST_STATUS2_DSP_TO_DMA_REQUEST_STATUS_SHIFT)) & DSPSS_DSP_TO_DMA_REQUEST_STATUS2_DSP_TO_DMA_REQUEST_STATUS_MASK)

#define DSPSS_DSP_TO_DMA_REQUEST_STATUS2_DMA_TO_DSP_ACK_STATUS_MASK (0x2U)
#define DSPSS_DSP_TO_DMA_REQUEST_STATUS2_DMA_TO_DSP_ACK_STATUS_SHIFT (1U)
#define DSPSS_DSP_TO_DMA_REQUEST_STATUS2_DMA_TO_DSP_ACK_STATUS_WIDTH (1U)
#define DSPSS_DSP_TO_DMA_REQUEST_STATUS2_DMA_TO_DSP_ACK_STATUS(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSP_TO_DMA_REQUEST_STATUS2_DMA_TO_DSP_ACK_STATUS_SHIFT)) & DSPSS_DSP_TO_DMA_REQUEST_STATUS2_DMA_TO_DSP_ACK_STATUS_MASK)
/*! @} */

/*! @name THREAD_SUSPEND_REQ2 - Thread Suspend Request For Thread Disabling/PCINIT Change */
/*! @{ */

#define DSPSS_THREAD_SUSPEND_REQ2_SUSPEND_REQ_MASK (0x1U)
#define DSPSS_THREAD_SUSPEND_REQ2_SUSPEND_REQ_SHIFT (0U)
#define DSPSS_THREAD_SUSPEND_REQ2_SUSPEND_REQ_WIDTH (1U)
#define DSPSS_THREAD_SUSPEND_REQ2_SUSPEND_REQ(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_THREAD_SUSPEND_REQ2_SUSPEND_REQ_SHIFT)) & DSPSS_THREAD_SUSPEND_REQ2_SUSPEND_REQ_MASK)
/*! @} */

/*! @name DSPSS_DSP_TH_STATUS2 - Thread Status */
/*! @{ */

#define DSPSS_DSPSS_DSP_TH_STATUS2_dspss_th_suspended_MASK (0x1U)
#define DSPSS_DSPSS_DSP_TH_STATUS2_dspss_th_suspended_SHIFT (0U)
#define DSPSS_DSPSS_DSP_TH_STATUS2_dspss_th_suspended_WIDTH (1U)
#define DSPSS_DSPSS_DSP_TH_STATUS2_dspss_th_suspended(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSPSS_DSP_TH_STATUS2_dspss_th_suspended_SHIFT)) & DSPSS_DSPSS_DSP_TH_STATUS2_dspss_th_suspended_MASK)
/*! @} */

/*! @name DSP_CORE_BUFFER_STATUS2 - DSP Core Buffer Status */
/*! @{ */

#define DSPSS_DSP_CORE_BUFFER_STATUS2_DSP_CORE_BUFFER_OVF_MASK (0x2U)
#define DSPSS_DSP_CORE_BUFFER_STATUS2_DSP_CORE_BUFFER_OVF_SHIFT (1U)
#define DSPSS_DSP_CORE_BUFFER_STATUS2_DSP_CORE_BUFFER_OVF_WIDTH (1U)
#define DSPSS_DSP_CORE_BUFFER_STATUS2_DSP_CORE_BUFFER_OVF(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSP_CORE_BUFFER_STATUS2_DSP_CORE_BUFFER_OVF_SHIFT)) & DSPSS_DSP_CORE_BUFFER_STATUS2_DSP_CORE_BUFFER_OVF_MASK)

#define DSPSS_DSP_CORE_BUFFER_STATUS2_DSP_CORE_BUFFER_UNDF_MASK (0x4U)
#define DSPSS_DSP_CORE_BUFFER_STATUS2_DSP_CORE_BUFFER_UNDF_SHIFT (2U)
#define DSPSS_DSP_CORE_BUFFER_STATUS2_DSP_CORE_BUFFER_UNDF_WIDTH (1U)
#define DSPSS_DSP_CORE_BUFFER_STATUS2_DSP_CORE_BUFFER_UNDF(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSP_CORE_BUFFER_STATUS2_DSP_CORE_BUFFER_UNDF_SHIFT)) & DSPSS_DSP_CORE_BUFFER_STATUS2_DSP_CORE_BUFFER_UNDF_MASK)
/*! @} */

/*! @name DSP_TO_CORE_TRIG_ERR_STATUS2 - DSP To Cortex-M7 Core Error Trigger */
/*! @{ */

#define DSPSS_DSP_TO_CORE_TRIG_ERR_STATUS2_DSP_TO_CORE_TRIG_ERR_STATUS_MASK (0x1U)
#define DSPSS_DSP_TO_CORE_TRIG_ERR_STATUS2_DSP_TO_CORE_TRIG_ERR_STATUS_SHIFT (0U)
#define DSPSS_DSP_TO_CORE_TRIG_ERR_STATUS2_DSP_TO_CORE_TRIG_ERR_STATUS_WIDTH (1U)
#define DSPSS_DSP_TO_CORE_TRIG_ERR_STATUS2_DSP_TO_CORE_TRIG_ERR_STATUS(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSP_TO_CORE_TRIG_ERR_STATUS2_DSP_TO_CORE_TRIG_ERR_STATUS_SHIFT)) & DSPSS_DSP_TO_CORE_TRIG_ERR_STATUS2_DSP_TO_CORE_TRIG_ERR_STATUS_MASK)
/*! @} */

/*! @name DS_GATE_STATUS_REGISTER2 - DSP Output Control */
/*! @{ */

#define DSPSS_DS_GATE_STATUS_REGISTER2_DS_GATE_STATUS_REGISTER_MASK (0x1U)
#define DSPSS_DS_GATE_STATUS_REGISTER2_DS_GATE_STATUS_REGISTER_SHIFT (0U)
#define DSPSS_DS_GATE_STATUS_REGISTER2_DS_GATE_STATUS_REGISTER_WIDTH (1U)
#define DSPSS_DS_GATE_STATUS_REGISTER2_DS_GATE_STATUS_REGISTER(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DS_GATE_STATUS_REGISTER2_DS_GATE_STATUS_REGISTER_SHIFT)) & DSPSS_DS_GATE_STATUS_REGISTER2_DS_GATE_STATUS_REGISTER_MASK)
/*! @} */

/*! @name DS_GATE_TRIGMUX_REGISTER2 - DSP Trigger To TRIGMUX */
/*! @{ */

#define DSPSS_DS_GATE_TRIGMUX_REGISTER2_DS_GATE_TRIGMUX_TRIGGER_MASK (0x1U)
#define DSPSS_DS_GATE_TRIGMUX_REGISTER2_DS_GATE_TRIGMUX_TRIGGER_SHIFT (0U)
#define DSPSS_DS_GATE_TRIGMUX_REGISTER2_DS_GATE_TRIGMUX_TRIGGER_WIDTH (1U)
#define DSPSS_DS_GATE_TRIGMUX_REGISTER2_DS_GATE_TRIGMUX_TRIGGER(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DS_GATE_TRIGMUX_REGISTER2_DS_GATE_TRIGMUX_TRIGGER_SHIFT)) & DSPSS_DS_GATE_TRIGMUX_REGISTER2_DS_GATE_TRIGMUX_TRIGGER_MASK)
/*! @} */

/*! @name HW_CTRL_DMA_REQ_STOP2 - Stop DMA Request */
/*! @{ */

#define DSPSS_HW_CTRL_DMA_REQ_STOP2_STOP_MASK    (0x1U)
#define DSPSS_HW_CTRL_DMA_REQ_STOP2_STOP_SHIFT   (0U)
#define DSPSS_HW_CTRL_DMA_REQ_STOP2_STOP_WIDTH   (1U)
#define DSPSS_HW_CTRL_DMA_REQ_STOP2_STOP(x)      (((uint32_t)(((uint32_t)(x)) << DSPSS_HW_CTRL_DMA_REQ_STOP2_STOP_SHIFT)) & DSPSS_HW_CTRL_DMA_REQ_STOP2_STOP_MASK)
/*! @} */

/*! @name DMA_ERROR_CTRL2 - DMA Error Control */
/*! @{ */

#define DSPSS_DMA_ERROR_CTRL2_DONE_MASK          (0x1U)
#define DSPSS_DMA_ERROR_CTRL2_DONE_SHIFT         (0U)
#define DSPSS_DMA_ERROR_CTRL2_DONE_WIDTH         (1U)
#define DSPSS_DMA_ERROR_CTRL2_DONE(x)            (((uint32_t)(((uint32_t)(x)) << DSPSS_DMA_ERROR_CTRL2_DONE_SHIFT)) & DSPSS_DMA_ERROR_CTRL2_DONE_MASK)
/*! @} */

/*! @name HW_CTRL_DMA_REQ_RESPONSE2 - Hardware Control Handling for DMA Request And Response */
/*! @{ */

#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE2_START_MASK (0x1U)
#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE2_START_SHIFT (0U)
#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE2_START_WIDTH (1U)
#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE2_START(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_HW_CTRL_DMA_REQ_RESPONSE2_START_SHIFT)) & DSPSS_HW_CTRL_DMA_REQ_RESPONSE2_START_MASK)

#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE2_NUM_OF_DMA_REQ_MASK (0x1FEU)
#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE2_NUM_OF_DMA_REQ_SHIFT (1U)
#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE2_NUM_OF_DMA_REQ_WIDTH (8U)
#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE2_NUM_OF_DMA_REQ(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_HW_CTRL_DMA_REQ_RESPONSE2_NUM_OF_DMA_REQ_SHIFT)) & DSPSS_HW_CTRL_DMA_REQ_RESPONSE2_NUM_OF_DMA_REQ_MASK)

#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE2_DONE_MASK (0x200U)
#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE2_DONE_SHIFT (9U)
#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE2_DONE_WIDTH (1U)
#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE2_DONE(x)  (((uint32_t)(((uint32_t)(x)) << DSPSS_HW_CTRL_DMA_REQ_RESPONSE2_DONE_SHIFT)) & DSPSS_HW_CTRL_DMA_REQ_RESPONSE2_DONE_MASK)

#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE2_NUM_OF_DMA_REQ_PEND_MASK (0x3FC00U)
#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE2_NUM_OF_DMA_REQ_PEND_SHIFT (10U)
#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE2_NUM_OF_DMA_REQ_PEND_WIDTH (8U)
#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE2_NUM_OF_DMA_REQ_PEND(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_HW_CTRL_DMA_REQ_RESPONSE2_NUM_OF_DMA_REQ_PEND_SHIFT)) & DSPSS_HW_CTRL_DMA_REQ_RESPONSE2_NUM_OF_DMA_REQ_PEND_MASK)
/*! @} */

/*! @name DSPSS_SCHEDULER_XMEM_ADDR_TH3 - Thread Start And End Address Location Configuration */
/*! @{ */

#define DSPSS_DSPSS_SCHEDULER_XMEM_ADDR_TH3_SCHEDULER_THRD_START_ADDR_MASK (0xFFFFU)
#define DSPSS_DSPSS_SCHEDULER_XMEM_ADDR_TH3_SCHEDULER_THRD_START_ADDR_SHIFT (0U)
#define DSPSS_DSPSS_SCHEDULER_XMEM_ADDR_TH3_SCHEDULER_THRD_START_ADDR_WIDTH (16U)
#define DSPSS_DSPSS_SCHEDULER_XMEM_ADDR_TH3_SCHEDULER_THRD_START_ADDR(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSPSS_SCHEDULER_XMEM_ADDR_TH3_SCHEDULER_THRD_START_ADDR_SHIFT)) & DSPSS_DSPSS_SCHEDULER_XMEM_ADDR_TH3_SCHEDULER_THRD_START_ADDR_MASK)

#define DSPSS_DSPSS_SCHEDULER_XMEM_ADDR_TH3_SCHEDULER_THRD_END_ADDR_MASK (0xFFFF0000U)
#define DSPSS_DSPSS_SCHEDULER_XMEM_ADDR_TH3_SCHEDULER_THRD_END_ADDR_SHIFT (16U)
#define DSPSS_DSPSS_SCHEDULER_XMEM_ADDR_TH3_SCHEDULER_THRD_END_ADDR_WIDTH (16U)
#define DSPSS_DSPSS_SCHEDULER_XMEM_ADDR_TH3_SCHEDULER_THRD_END_ADDR(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSPSS_SCHEDULER_XMEM_ADDR_TH3_SCHEDULER_THRD_END_ADDR_SHIFT)) & DSPSS_DSPSS_SCHEDULER_XMEM_ADDR_TH3_SCHEDULER_THRD_END_ADDR_MASK)
/*! @} */

/*! @name DSPSS_SCHEDULER_XMEM_TH3 - Thread Threshold And Enable */
/*! @{ */

#define DSPSS_DSPSS_SCHEDULER_XMEM_TH3_SCHEDULER_THRD_TH_MASK (0xFFFFU)
#define DSPSS_DSPSS_SCHEDULER_XMEM_TH3_SCHEDULER_THRD_TH_SHIFT (0U)
#define DSPSS_DSPSS_SCHEDULER_XMEM_TH3_SCHEDULER_THRD_TH_WIDTH (16U)
#define DSPSS_DSPSS_SCHEDULER_XMEM_TH3_SCHEDULER_THRD_TH(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSPSS_SCHEDULER_XMEM_TH3_SCHEDULER_THRD_TH_SHIFT)) & DSPSS_DSPSS_SCHEDULER_XMEM_TH3_SCHEDULER_THRD_TH_MASK)

#define DSPSS_DSPSS_SCHEDULER_XMEM_TH3_SCHEDULER_THRD_EN_MASK (0x80000000U)
#define DSPSS_DSPSS_SCHEDULER_XMEM_TH3_SCHEDULER_THRD_EN_SHIFT (31U)
#define DSPSS_DSPSS_SCHEDULER_XMEM_TH3_SCHEDULER_THRD_EN_WIDTH (1U)
#define DSPSS_DSPSS_SCHEDULER_XMEM_TH3_SCHEDULER_THRD_EN(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSPSS_SCHEDULER_XMEM_TH3_SCHEDULER_THRD_EN_SHIFT)) & DSPSS_DSPSS_SCHEDULER_XMEM_TH3_SCHEDULER_THRD_EN_MASK)
/*! @} */

/*! @name DSPSS_SCHEDULER_DSP_CFG_TH3 - PC Initial Value */
/*! @{ */

#define DSPSS_DSPSS_SCHEDULER_DSP_CFG_TH3_DSPSS_SCHEDULER_DSP_PCINIT_MASK (0x3FFFU)
#define DSPSS_DSPSS_SCHEDULER_DSP_CFG_TH3_DSPSS_SCHEDULER_DSP_PCINIT_SHIFT (0U)
#define DSPSS_DSPSS_SCHEDULER_DSP_CFG_TH3_DSPSS_SCHEDULER_DSP_PCINIT_WIDTH (14U)
#define DSPSS_DSPSS_SCHEDULER_DSP_CFG_TH3_DSPSS_SCHEDULER_DSP_PCINIT(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSPSS_SCHEDULER_DSP_CFG_TH3_DSPSS_SCHEDULER_DSP_PCINIT_SHIFT)) & DSPSS_DSPSS_SCHEDULER_DSP_CFG_TH3_DSPSS_SCHEDULER_DSP_PCINIT_MASK)
/*! @} */

/*! @name DSPSS_SCHEDULER_CURR_XMEM_ADDR_TH3 - Current XMEM Write Pointer */
/*! @{ */

#define DSPSS_DSPSS_SCHEDULER_CURR_XMEM_ADDR_TH3_DSPSS_SCHEDULER_CURR_XMEM_ADDR_MASK (0x7FFFU)
#define DSPSS_DSPSS_SCHEDULER_CURR_XMEM_ADDR_TH3_DSPSS_SCHEDULER_CURR_XMEM_ADDR_SHIFT (0U)
#define DSPSS_DSPSS_SCHEDULER_CURR_XMEM_ADDR_TH3_DSPSS_SCHEDULER_CURR_XMEM_ADDR_WIDTH (15U)
#define DSPSS_DSPSS_SCHEDULER_CURR_XMEM_ADDR_TH3_DSPSS_SCHEDULER_CURR_XMEM_ADDR(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSPSS_SCHEDULER_CURR_XMEM_ADDR_TH3_DSPSS_SCHEDULER_CURR_XMEM_ADDR_SHIFT)) & DSPSS_DSPSS_SCHEDULER_CURR_XMEM_ADDR_TH3_DSPSS_SCHEDULER_CURR_XMEM_ADDR_MASK)
/*! @} */

/*! @name DSP_SDADC_CURR_READ_PTR3 - Last Scheduled-Request Address */
/*! @{ */

#define DSPSS_DSP_SDADC_CURR_READ_PTR3_DSP_SDADC_CURR_READ_PTR_MASK (0x3FFFU)
#define DSPSS_DSP_SDADC_CURR_READ_PTR3_DSP_SDADC_CURR_READ_PTR_SHIFT (0U)
#define DSPSS_DSP_SDADC_CURR_READ_PTR3_DSP_SDADC_CURR_READ_PTR_WIDTH (14U)
#define DSPSS_DSP_SDADC_CURR_READ_PTR3_DSP_SDADC_CURR_READ_PTR(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSP_SDADC_CURR_READ_PTR3_DSP_SDADC_CURR_READ_PTR_SHIFT)) & DSPSS_DSP_SDADC_CURR_READ_PTR3_DSP_SDADC_CURR_READ_PTR_MASK)
/*! @} */

/*! @name DSP_CORE_BUF_ADDR3 - Start And End Pointers For DSP And Cortex-M7 Core Shared Buffer */
/*! @{ */

#define DSPSS_DSP_CORE_BUF_ADDR3_DSP_CORE_BUF_START_ADDR_MASK (0x3FFFU)
#define DSPSS_DSP_CORE_BUF_ADDR3_DSP_CORE_BUF_START_ADDR_SHIFT (0U)
#define DSPSS_DSP_CORE_BUF_ADDR3_DSP_CORE_BUF_START_ADDR_WIDTH (14U)
#define DSPSS_DSP_CORE_BUF_ADDR3_DSP_CORE_BUF_START_ADDR(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSP_CORE_BUF_ADDR3_DSP_CORE_BUF_START_ADDR_SHIFT)) & DSPSS_DSP_CORE_BUF_ADDR3_DSP_CORE_BUF_START_ADDR_MASK)

#define DSPSS_DSP_CORE_BUF_ADDR3_DSP_CORE_BUF_END_ADDR_MASK (0xFFFC0000U)
#define DSPSS_DSP_CORE_BUF_ADDR3_DSP_CORE_BUF_END_ADDR_SHIFT (18U)
#define DSPSS_DSP_CORE_BUF_ADDR3_DSP_CORE_BUF_END_ADDR_WIDTH (14U)
#define DSPSS_DSP_CORE_BUF_ADDR3_DSP_CORE_BUF_END_ADDR(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSP_CORE_BUF_ADDR3_DSP_CORE_BUF_END_ADDR_SHIFT)) & DSPSS_DSP_CORE_BUF_ADDR3_DSP_CORE_BUF_END_ADDR_MASK)
/*! @} */

/*! @name DSP_CORE_CURR_RD_PTR3 - Read Pointer In DSP Buffer */
/*! @{ */

#define DSPSS_DSP_CORE_CURR_RD_PTR3_DSP_CORE_CURR_RD_PTR_MASK (0x3FFFU)
#define DSPSS_DSP_CORE_CURR_RD_PTR3_DSP_CORE_CURR_RD_PTR_SHIFT (0U)
#define DSPSS_DSP_CORE_CURR_RD_PTR3_DSP_CORE_CURR_RD_PTR_WIDTH (14U)
#define DSPSS_DSP_CORE_CURR_RD_PTR3_DSP_CORE_CURR_RD_PTR(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSP_CORE_CURR_RD_PTR3_DSP_CORE_CURR_RD_PTR_SHIFT)) & DSPSS_DSP_CORE_CURR_RD_PTR3_DSP_CORE_CURR_RD_PTR_MASK)

#define DSPSS_DSP_CORE_CURR_RD_PTR3_DSP_CORE_CURR_RD_PTR_WRAP_MASK (0x4000U)
#define DSPSS_DSP_CORE_CURR_RD_PTR3_DSP_CORE_CURR_RD_PTR_WRAP_SHIFT (14U)
#define DSPSS_DSP_CORE_CURR_RD_PTR3_DSP_CORE_CURR_RD_PTR_WRAP_WIDTH (1U)
#define DSPSS_DSP_CORE_CURR_RD_PTR3_DSP_CORE_CURR_RD_PTR_WRAP(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSP_CORE_CURR_RD_PTR3_DSP_CORE_CURR_RD_PTR_WRAP_SHIFT)) & DSPSS_DSP_CORE_CURR_RD_PTR3_DSP_CORE_CURR_RD_PTR_WRAP_MASK)
/*! @} */

/*! @name DSP_CORE_CURR_WR_PTR3 - Write Pointer In DSP Buffer */
/*! @{ */

#define DSPSS_DSP_CORE_CURR_WR_PTR3_DSP_CORE_CURR_WR_PTR_MASK (0x3FFFU)
#define DSPSS_DSP_CORE_CURR_WR_PTR3_DSP_CORE_CURR_WR_PTR_SHIFT (0U)
#define DSPSS_DSP_CORE_CURR_WR_PTR3_DSP_CORE_CURR_WR_PTR_WIDTH (14U)
#define DSPSS_DSP_CORE_CURR_WR_PTR3_DSP_CORE_CURR_WR_PTR(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSP_CORE_CURR_WR_PTR3_DSP_CORE_CURR_WR_PTR_SHIFT)) & DSPSS_DSP_CORE_CURR_WR_PTR3_DSP_CORE_CURR_WR_PTR_MASK)

#define DSPSS_DSP_CORE_CURR_WR_PTR3_DSP_CORE_CURR_WR_PTR_WRAP_MASK (0x4000U)
#define DSPSS_DSP_CORE_CURR_WR_PTR3_DSP_CORE_CURR_WR_PTR_WRAP_SHIFT (14U)
#define DSPSS_DSP_CORE_CURR_WR_PTR3_DSP_CORE_CURR_WR_PTR_WRAP_WIDTH (1U)
#define DSPSS_DSP_CORE_CURR_WR_PTR3_DSP_CORE_CURR_WR_PTR_WRAP(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSP_CORE_CURR_WR_PTR3_DSP_CORE_CURR_WR_PTR_WRAP_SHIFT)) & DSPSS_DSP_CORE_CURR_WR_PTR3_DSP_CORE_CURR_WR_PTR_WRAP_MASK)
/*! @} */

/*! @name DMA_READ_ADDR3 - Reference DMA Read Region */
/*! @{ */

#define DSPSS_DMA_READ_ADDR3_DMA_READ_START_ADDR_MASK (0x3FFFU)
#define DSPSS_DMA_READ_ADDR3_DMA_READ_START_ADDR_SHIFT (0U)
#define DSPSS_DMA_READ_ADDR3_DMA_READ_START_ADDR_WIDTH (14U)
#define DSPSS_DMA_READ_ADDR3_DMA_READ_START_ADDR(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DMA_READ_ADDR3_DMA_READ_START_ADDR_SHIFT)) & DSPSS_DMA_READ_ADDR3_DMA_READ_START_ADDR_MASK)

#define DSPSS_DMA_READ_ADDR3_DMA_READ_END_ADDR_MASK (0xFFFC0000U)
#define DSPSS_DMA_READ_ADDR3_DMA_READ_END_ADDR_SHIFT (18U)
#define DSPSS_DMA_READ_ADDR3_DMA_READ_END_ADDR_WIDTH (14U)
#define DSPSS_DMA_READ_ADDR3_DMA_READ_END_ADDR(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DMA_READ_ADDR3_DMA_READ_END_ADDR_SHIFT)) & DSPSS_DMA_READ_ADDR3_DMA_READ_END_ADDR_MASK)
/*! @} */

/*! @name DMA_ERROR_STATUS3 - DMA Error Status */
/*! @{ */

#define DSPSS_DMA_ERROR_STATUS3_DMA_ADDR_MISMATCH_WR_BUFFER_MASK (0x1U)
#define DSPSS_DMA_ERROR_STATUS3_DMA_ADDR_MISMATCH_WR_BUFFER_SHIFT (0U)
#define DSPSS_DMA_ERROR_STATUS3_DMA_ADDR_MISMATCH_WR_BUFFER_WIDTH (1U)
#define DSPSS_DMA_ERROR_STATUS3_DMA_ADDR_MISMATCH_WR_BUFFER(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DMA_ERROR_STATUS3_DMA_ADDR_MISMATCH_WR_BUFFER_SHIFT)) & DSPSS_DMA_ERROR_STATUS3_DMA_ADDR_MISMATCH_WR_BUFFER_MASK)

#define DSPSS_DMA_ERROR_STATUS3_DMA_ADDR_MISMATCH_RD_BUFFER_MASK (0x2U)
#define DSPSS_DMA_ERROR_STATUS3_DMA_ADDR_MISMATCH_RD_BUFFER_SHIFT (1U)
#define DSPSS_DMA_ERROR_STATUS3_DMA_ADDR_MISMATCH_RD_BUFFER_WIDTH (1U)
#define DSPSS_DMA_ERROR_STATUS3_DMA_ADDR_MISMATCH_RD_BUFFER(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DMA_ERROR_STATUS3_DMA_ADDR_MISMATCH_RD_BUFFER_SHIFT)) & DSPSS_DMA_ERROR_STATUS3_DMA_ADDR_MISMATCH_RD_BUFFER_MASK)

#define DSPSS_DMA_ERROR_STATUS3_DMA_XFR_ERR_WRITE_MASK (0x4U)
#define DSPSS_DMA_ERROR_STATUS3_DMA_XFR_ERR_WRITE_SHIFT (2U)
#define DSPSS_DMA_ERROR_STATUS3_DMA_XFR_ERR_WRITE_WIDTH (1U)
#define DSPSS_DMA_ERROR_STATUS3_DMA_XFR_ERR_WRITE(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DMA_ERROR_STATUS3_DMA_XFR_ERR_WRITE_SHIFT)) & DSPSS_DMA_ERROR_STATUS3_DMA_XFR_ERR_WRITE_MASK)

#define DSPSS_DMA_ERROR_STATUS3_DMA_XFR_ERR_READ_MASK (0x8U)
#define DSPSS_DMA_ERROR_STATUS3_DMA_XFR_ERR_READ_SHIFT (3U)
#define DSPSS_DMA_ERROR_STATUS3_DMA_XFR_ERR_READ_WIDTH (1U)
#define DSPSS_DMA_ERROR_STATUS3_DMA_XFR_ERR_READ(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DMA_ERROR_STATUS3_DMA_XFR_ERR_READ_SHIFT)) & DSPSS_DMA_ERROR_STATUS3_DMA_XFR_ERR_READ_MASK)
/*! @} */

/*! @name DMA_WRITE_ADDR3 - Reference DMA Write Region */
/*! @{ */

#define DSPSS_DMA_WRITE_ADDR3_DMA_WRITE_START_ADDR_MASK (0x3FFFU)
#define DSPSS_DMA_WRITE_ADDR3_DMA_WRITE_START_ADDR_SHIFT (0U)
#define DSPSS_DMA_WRITE_ADDR3_DMA_WRITE_START_ADDR_WIDTH (14U)
#define DSPSS_DMA_WRITE_ADDR3_DMA_WRITE_START_ADDR(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DMA_WRITE_ADDR3_DMA_WRITE_START_ADDR_SHIFT)) & DSPSS_DMA_WRITE_ADDR3_DMA_WRITE_START_ADDR_MASK)

#define DSPSS_DMA_WRITE_ADDR3_DMA_WRITE_END_ADDR_MASK (0xFFFC0000U)
#define DSPSS_DMA_WRITE_ADDR3_DMA_WRITE_END_ADDR_SHIFT (18U)
#define DSPSS_DMA_WRITE_ADDR3_DMA_WRITE_END_ADDR_WIDTH (14U)
#define DSPSS_DMA_WRITE_ADDR3_DMA_WRITE_END_ADDR(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DMA_WRITE_ADDR3_DMA_WRITE_END_ADDR_SHIFT)) & DSPSS_DMA_WRITE_ADDR3_DMA_WRITE_END_ADDR_MASK)
/*! @} */

/*! @name DMA_CURR_WR_PTR3 - DMA Current Write Pointer */
/*! @{ */

#define DSPSS_DMA_CURR_WR_PTR3_DMA_CURR_WRITE_PTR_MASK (0x3FFFU)
#define DSPSS_DMA_CURR_WR_PTR3_DMA_CURR_WRITE_PTR_SHIFT (0U)
#define DSPSS_DMA_CURR_WR_PTR3_DMA_CURR_WRITE_PTR_WIDTH (14U)
#define DSPSS_DMA_CURR_WR_PTR3_DMA_CURR_WRITE_PTR(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DMA_CURR_WR_PTR3_DMA_CURR_WRITE_PTR_SHIFT)) & DSPSS_DMA_CURR_WR_PTR3_DMA_CURR_WRITE_PTR_MASK)

#define DSPSS_DMA_CURR_WR_PTR3_DMA_WRITE_PTR_WRAP_MASK (0x80000000U)
#define DSPSS_DMA_CURR_WR_PTR3_DMA_WRITE_PTR_WRAP_SHIFT (31U)
#define DSPSS_DMA_CURR_WR_PTR3_DMA_WRITE_PTR_WRAP_WIDTH (1U)
#define DSPSS_DMA_CURR_WR_PTR3_DMA_WRITE_PTR_WRAP(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DMA_CURR_WR_PTR3_DMA_WRITE_PTR_WRAP_SHIFT)) & DSPSS_DMA_CURR_WR_PTR3_DMA_WRITE_PTR_WRAP_MASK)
/*! @} */

/*! @name DMA_CURR_RD_PTR3 - DMA Current Read Pointer */
/*! @{ */

#define DSPSS_DMA_CURR_RD_PTR3_DMA_CURR_READ_PTR_MASK (0x3FFFU)
#define DSPSS_DMA_CURR_RD_PTR3_DMA_CURR_READ_PTR_SHIFT (0U)
#define DSPSS_DMA_CURR_RD_PTR3_DMA_CURR_READ_PTR_WIDTH (14U)
#define DSPSS_DMA_CURR_RD_PTR3_DMA_CURR_READ_PTR(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DMA_CURR_RD_PTR3_DMA_CURR_READ_PTR_SHIFT)) & DSPSS_DMA_CURR_RD_PTR3_DMA_CURR_READ_PTR_MASK)

#define DSPSS_DMA_CURR_RD_PTR3_DMA_READ_PTR_WRAP_MASK (0x80000000U)
#define DSPSS_DMA_CURR_RD_PTR3_DMA_READ_PTR_WRAP_SHIFT (31U)
#define DSPSS_DMA_CURR_RD_PTR3_DMA_READ_PTR_WRAP_WIDTH (1U)
#define DSPSS_DMA_CURR_RD_PTR3_DMA_READ_PTR_WRAP(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DMA_CURR_RD_PTR3_DMA_READ_PTR_WRAP_SHIFT)) & DSPSS_DMA_CURR_RD_PTR3_DMA_READ_PTR_WRAP_MASK)
/*! @} */

/*! @name DSP_TO_DMA_REQUEST_STATUS3 - DMA Request Status */
/*! @{ */

#define DSPSS_DSP_TO_DMA_REQUEST_STATUS3_DSP_TO_DMA_REQUEST_STATUS_MASK (0x1U)
#define DSPSS_DSP_TO_DMA_REQUEST_STATUS3_DSP_TO_DMA_REQUEST_STATUS_SHIFT (0U)
#define DSPSS_DSP_TO_DMA_REQUEST_STATUS3_DSP_TO_DMA_REQUEST_STATUS_WIDTH (1U)
#define DSPSS_DSP_TO_DMA_REQUEST_STATUS3_DSP_TO_DMA_REQUEST_STATUS(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSP_TO_DMA_REQUEST_STATUS3_DSP_TO_DMA_REQUEST_STATUS_SHIFT)) & DSPSS_DSP_TO_DMA_REQUEST_STATUS3_DSP_TO_DMA_REQUEST_STATUS_MASK)

#define DSPSS_DSP_TO_DMA_REQUEST_STATUS3_DMA_TO_DSP_ACK_STATUS_MASK (0x2U)
#define DSPSS_DSP_TO_DMA_REQUEST_STATUS3_DMA_TO_DSP_ACK_STATUS_SHIFT (1U)
#define DSPSS_DSP_TO_DMA_REQUEST_STATUS3_DMA_TO_DSP_ACK_STATUS_WIDTH (1U)
#define DSPSS_DSP_TO_DMA_REQUEST_STATUS3_DMA_TO_DSP_ACK_STATUS(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSP_TO_DMA_REQUEST_STATUS3_DMA_TO_DSP_ACK_STATUS_SHIFT)) & DSPSS_DSP_TO_DMA_REQUEST_STATUS3_DMA_TO_DSP_ACK_STATUS_MASK)
/*! @} */

/*! @name THREAD_SUSPEND_REQ3 - Thread Suspend Request For Thread Disabling/PCINIT Change */
/*! @{ */

#define DSPSS_THREAD_SUSPEND_REQ3_SUSPEND_REQ_MASK (0x1U)
#define DSPSS_THREAD_SUSPEND_REQ3_SUSPEND_REQ_SHIFT (0U)
#define DSPSS_THREAD_SUSPEND_REQ3_SUSPEND_REQ_WIDTH (1U)
#define DSPSS_THREAD_SUSPEND_REQ3_SUSPEND_REQ(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_THREAD_SUSPEND_REQ3_SUSPEND_REQ_SHIFT)) & DSPSS_THREAD_SUSPEND_REQ3_SUSPEND_REQ_MASK)
/*! @} */

/*! @name DSPSS_DSP_TH_STATUS3 - Thread Status */
/*! @{ */

#define DSPSS_DSPSS_DSP_TH_STATUS3_dspss_th_suspended_MASK (0x1U)
#define DSPSS_DSPSS_DSP_TH_STATUS3_dspss_th_suspended_SHIFT (0U)
#define DSPSS_DSPSS_DSP_TH_STATUS3_dspss_th_suspended_WIDTH (1U)
#define DSPSS_DSPSS_DSP_TH_STATUS3_dspss_th_suspended(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSPSS_DSP_TH_STATUS3_dspss_th_suspended_SHIFT)) & DSPSS_DSPSS_DSP_TH_STATUS3_dspss_th_suspended_MASK)
/*! @} */

/*! @name DSP_CORE_BUFFER_STATUS3 - DSP Core Buffer Status */
/*! @{ */

#define DSPSS_DSP_CORE_BUFFER_STATUS3_DSP_CORE_BUFFER_OVF_MASK (0x2U)
#define DSPSS_DSP_CORE_BUFFER_STATUS3_DSP_CORE_BUFFER_OVF_SHIFT (1U)
#define DSPSS_DSP_CORE_BUFFER_STATUS3_DSP_CORE_BUFFER_OVF_WIDTH (1U)
#define DSPSS_DSP_CORE_BUFFER_STATUS3_DSP_CORE_BUFFER_OVF(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSP_CORE_BUFFER_STATUS3_DSP_CORE_BUFFER_OVF_SHIFT)) & DSPSS_DSP_CORE_BUFFER_STATUS3_DSP_CORE_BUFFER_OVF_MASK)

#define DSPSS_DSP_CORE_BUFFER_STATUS3_DSP_CORE_BUFFER_UNDF_MASK (0x4U)
#define DSPSS_DSP_CORE_BUFFER_STATUS3_DSP_CORE_BUFFER_UNDF_SHIFT (2U)
#define DSPSS_DSP_CORE_BUFFER_STATUS3_DSP_CORE_BUFFER_UNDF_WIDTH (1U)
#define DSPSS_DSP_CORE_BUFFER_STATUS3_DSP_CORE_BUFFER_UNDF(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSP_CORE_BUFFER_STATUS3_DSP_CORE_BUFFER_UNDF_SHIFT)) & DSPSS_DSP_CORE_BUFFER_STATUS3_DSP_CORE_BUFFER_UNDF_MASK)
/*! @} */

/*! @name DSP_TO_CORE_TRIG_ERR_STATUS3 - DSP To Cortex-M7 Core Error Trigger */
/*! @{ */

#define DSPSS_DSP_TO_CORE_TRIG_ERR_STATUS3_DSP_TO_CORE_TRIG_ERR_STATUS_MASK (0x1U)
#define DSPSS_DSP_TO_CORE_TRIG_ERR_STATUS3_DSP_TO_CORE_TRIG_ERR_STATUS_SHIFT (0U)
#define DSPSS_DSP_TO_CORE_TRIG_ERR_STATUS3_DSP_TO_CORE_TRIG_ERR_STATUS_WIDTH (1U)
#define DSPSS_DSP_TO_CORE_TRIG_ERR_STATUS3_DSP_TO_CORE_TRIG_ERR_STATUS(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSP_TO_CORE_TRIG_ERR_STATUS3_DSP_TO_CORE_TRIG_ERR_STATUS_SHIFT)) & DSPSS_DSP_TO_CORE_TRIG_ERR_STATUS3_DSP_TO_CORE_TRIG_ERR_STATUS_MASK)
/*! @} */

/*! @name DS_GATE_STATUS_REGISTER3 - DSP Output Control */
/*! @{ */

#define DSPSS_DS_GATE_STATUS_REGISTER3_DS_GATE_STATUS_REGISTER_MASK (0x1U)
#define DSPSS_DS_GATE_STATUS_REGISTER3_DS_GATE_STATUS_REGISTER_SHIFT (0U)
#define DSPSS_DS_GATE_STATUS_REGISTER3_DS_GATE_STATUS_REGISTER_WIDTH (1U)
#define DSPSS_DS_GATE_STATUS_REGISTER3_DS_GATE_STATUS_REGISTER(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DS_GATE_STATUS_REGISTER3_DS_GATE_STATUS_REGISTER_SHIFT)) & DSPSS_DS_GATE_STATUS_REGISTER3_DS_GATE_STATUS_REGISTER_MASK)
/*! @} */

/*! @name DS_GATE_TRIGMUX_REGISTER3 - DSP Trigger To TRIGMUX */
/*! @{ */

#define DSPSS_DS_GATE_TRIGMUX_REGISTER3_DS_GATE_TRIGMUX_TRIGGER_MASK (0x1U)
#define DSPSS_DS_GATE_TRIGMUX_REGISTER3_DS_GATE_TRIGMUX_TRIGGER_SHIFT (0U)
#define DSPSS_DS_GATE_TRIGMUX_REGISTER3_DS_GATE_TRIGMUX_TRIGGER_WIDTH (1U)
#define DSPSS_DS_GATE_TRIGMUX_REGISTER3_DS_GATE_TRIGMUX_TRIGGER(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DS_GATE_TRIGMUX_REGISTER3_DS_GATE_TRIGMUX_TRIGGER_SHIFT)) & DSPSS_DS_GATE_TRIGMUX_REGISTER3_DS_GATE_TRIGMUX_TRIGGER_MASK)
/*! @} */

/*! @name HW_CTRL_DMA_REQ_STOP3 - Stop DMA Request */
/*! @{ */

#define DSPSS_HW_CTRL_DMA_REQ_STOP3_STOP_MASK    (0x1U)
#define DSPSS_HW_CTRL_DMA_REQ_STOP3_STOP_SHIFT   (0U)
#define DSPSS_HW_CTRL_DMA_REQ_STOP3_STOP_WIDTH   (1U)
#define DSPSS_HW_CTRL_DMA_REQ_STOP3_STOP(x)      (((uint32_t)(((uint32_t)(x)) << DSPSS_HW_CTRL_DMA_REQ_STOP3_STOP_SHIFT)) & DSPSS_HW_CTRL_DMA_REQ_STOP3_STOP_MASK)
/*! @} */

/*! @name DMA_ERROR_CTRL3 - DMA Error Control */
/*! @{ */

#define DSPSS_DMA_ERROR_CTRL3_DONE_MASK          (0x1U)
#define DSPSS_DMA_ERROR_CTRL3_DONE_SHIFT         (0U)
#define DSPSS_DMA_ERROR_CTRL3_DONE_WIDTH         (1U)
#define DSPSS_DMA_ERROR_CTRL3_DONE(x)            (((uint32_t)(((uint32_t)(x)) << DSPSS_DMA_ERROR_CTRL3_DONE_SHIFT)) & DSPSS_DMA_ERROR_CTRL3_DONE_MASK)
/*! @} */

/*! @name HW_CTRL_DMA_REQ_RESPONSE3 - Hardware Control Handling for DMA Request And Response */
/*! @{ */

#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE3_START_MASK (0x1U)
#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE3_START_SHIFT (0U)
#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE3_START_WIDTH (1U)
#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE3_START(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_HW_CTRL_DMA_REQ_RESPONSE3_START_SHIFT)) & DSPSS_HW_CTRL_DMA_REQ_RESPONSE3_START_MASK)

#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE3_NUM_OF_DMA_REQ_MASK (0x1FEU)
#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE3_NUM_OF_DMA_REQ_SHIFT (1U)
#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE3_NUM_OF_DMA_REQ_WIDTH (8U)
#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE3_NUM_OF_DMA_REQ(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_HW_CTRL_DMA_REQ_RESPONSE3_NUM_OF_DMA_REQ_SHIFT)) & DSPSS_HW_CTRL_DMA_REQ_RESPONSE3_NUM_OF_DMA_REQ_MASK)

#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE3_DONE_MASK (0x200U)
#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE3_DONE_SHIFT (9U)
#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE3_DONE_WIDTH (1U)
#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE3_DONE(x)  (((uint32_t)(((uint32_t)(x)) << DSPSS_HW_CTRL_DMA_REQ_RESPONSE3_DONE_SHIFT)) & DSPSS_HW_CTRL_DMA_REQ_RESPONSE3_DONE_MASK)

#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE3_NUM_OF_DMA_REQ_PEND_MASK (0x3FC00U)
#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE3_NUM_OF_DMA_REQ_PEND_SHIFT (10U)
#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE3_NUM_OF_DMA_REQ_PEND_WIDTH (8U)
#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE3_NUM_OF_DMA_REQ_PEND(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_HW_CTRL_DMA_REQ_RESPONSE3_NUM_OF_DMA_REQ_PEND_SHIFT)) & DSPSS_HW_CTRL_DMA_REQ_RESPONSE3_NUM_OF_DMA_REQ_PEND_MASK)
/*! @} */

/*! @name DSPSS_SOFT_RESET_REGISTER - DSPSS Soft Reset */
/*! @{ */

#define DSPSS_DSPSS_SOFT_RESET_REGISTER_SFTRST_MASK (0x1U)
#define DSPSS_DSPSS_SOFT_RESET_REGISTER_SFTRST_SHIFT (0U)
#define DSPSS_DSPSS_SOFT_RESET_REGISTER_SFTRST_WIDTH (1U)
#define DSPSS_DSPSS_SOFT_RESET_REGISTER_SFTRST(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSPSS_SOFT_RESET_REGISTER_SFTRST_SHIFT)) & DSPSS_DSPSS_SOFT_RESET_REGISTER_SFTRST_MASK)
/*! @} */

/*! @name DSP_ACK_TIMEOUT_CFG_AND_ERR_CTRL - DSP ACK Timeout Configuration And Error Control */
/*! @{ */

#define DSPSS_DSP_ACK_TIMEOUT_CFG_AND_ERR_CTRL_DSP_ACK_TIMEOUT_TIMER_MASK (0x3FU)
#define DSPSS_DSP_ACK_TIMEOUT_CFG_AND_ERR_CTRL_DSP_ACK_TIMEOUT_TIMER_SHIFT (0U)
#define DSPSS_DSP_ACK_TIMEOUT_CFG_AND_ERR_CTRL_DSP_ACK_TIMEOUT_TIMER_WIDTH (6U)
#define DSPSS_DSP_ACK_TIMEOUT_CFG_AND_ERR_CTRL_DSP_ACK_TIMEOUT_TIMER(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSP_ACK_TIMEOUT_CFG_AND_ERR_CTRL_DSP_ACK_TIMEOUT_TIMER_SHIFT)) & DSPSS_DSP_ACK_TIMEOUT_CFG_AND_ERR_CTRL_DSP_ACK_TIMEOUT_TIMER_MASK)

#define DSPSS_DSP_ACK_TIMEOUT_CFG_AND_ERR_CTRL_DSP_ACK_TIMEOUT_EN_MASK (0x40U)
#define DSPSS_DSP_ACK_TIMEOUT_CFG_AND_ERR_CTRL_DSP_ACK_TIMEOUT_EN_SHIFT (6U)
#define DSPSS_DSP_ACK_TIMEOUT_CFG_AND_ERR_CTRL_DSP_ACK_TIMEOUT_EN_WIDTH (1U)
#define DSPSS_DSP_ACK_TIMEOUT_CFG_AND_ERR_CTRL_DSP_ACK_TIMEOUT_EN(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSP_ACK_TIMEOUT_CFG_AND_ERR_CTRL_DSP_ACK_TIMEOUT_EN_SHIFT)) & DSPSS_DSP_ACK_TIMEOUT_CFG_AND_ERR_CTRL_DSP_ACK_TIMEOUT_EN_MASK)

#define DSPSS_DSP_ACK_TIMEOUT_CFG_AND_ERR_CTRL_DSP_ACK_TIMEOUT_ERR_MASK (0x100U)
#define DSPSS_DSP_ACK_TIMEOUT_CFG_AND_ERR_CTRL_DSP_ACK_TIMEOUT_ERR_SHIFT (8U)
#define DSPSS_DSP_ACK_TIMEOUT_CFG_AND_ERR_CTRL_DSP_ACK_TIMEOUT_ERR_WIDTH (1U)
#define DSPSS_DSP_ACK_TIMEOUT_CFG_AND_ERR_CTRL_DSP_ACK_TIMEOUT_ERR(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSP_ACK_TIMEOUT_CFG_AND_ERR_CTRL_DSP_ACK_TIMEOUT_ERR_SHIFT)) & DSPSS_DSP_ACK_TIMEOUT_CFG_AND_ERR_CTRL_DSP_ACK_TIMEOUT_ERR_MASK)

#define DSPSS_DSP_ACK_TIMEOUT_CFG_AND_ERR_CTRL_REQ_ACC_FIFO_THRESHOLD_FOR_INTR_MASK (0x3E00U)
#define DSPSS_DSP_ACK_TIMEOUT_CFG_AND_ERR_CTRL_REQ_ACC_FIFO_THRESHOLD_FOR_INTR_SHIFT (9U)
#define DSPSS_DSP_ACK_TIMEOUT_CFG_AND_ERR_CTRL_REQ_ACC_FIFO_THRESHOLD_FOR_INTR_WIDTH (5U)
#define DSPSS_DSP_ACK_TIMEOUT_CFG_AND_ERR_CTRL_REQ_ACC_FIFO_THRESHOLD_FOR_INTR(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSP_ACK_TIMEOUT_CFG_AND_ERR_CTRL_REQ_ACC_FIFO_THRESHOLD_FOR_INTR_SHIFT)) & DSPSS_DSP_ACK_TIMEOUT_CFG_AND_ERR_CTRL_REQ_ACC_FIFO_THRESHOLD_FOR_INTR_MASK)

#define DSPSS_DSP_ACK_TIMEOUT_CFG_AND_ERR_CTRL_REQ_ACC_FIFO_INTR_MASK (0x4000U)
#define DSPSS_DSP_ACK_TIMEOUT_CFG_AND_ERR_CTRL_REQ_ACC_FIFO_INTR_SHIFT (14U)
#define DSPSS_DSP_ACK_TIMEOUT_CFG_AND_ERR_CTRL_REQ_ACC_FIFO_INTR_WIDTH (1U)
#define DSPSS_DSP_ACK_TIMEOUT_CFG_AND_ERR_CTRL_REQ_ACC_FIFO_INTR(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSP_ACK_TIMEOUT_CFG_AND_ERR_CTRL_REQ_ACC_FIFO_INTR_SHIFT)) & DSPSS_DSP_ACK_TIMEOUT_CFG_AND_ERR_CTRL_REQ_ACC_FIFO_INTR_MASK)

#define DSPSS_DSP_ACK_TIMEOUT_CFG_AND_ERR_CTRL_REQ_COUNT_ACC_FIFO_MASK (0xF8000U)
#define DSPSS_DSP_ACK_TIMEOUT_CFG_AND_ERR_CTRL_REQ_COUNT_ACC_FIFO_SHIFT (15U)
#define DSPSS_DSP_ACK_TIMEOUT_CFG_AND_ERR_CTRL_REQ_COUNT_ACC_FIFO_WIDTH (5U)
#define DSPSS_DSP_ACK_TIMEOUT_CFG_AND_ERR_CTRL_REQ_COUNT_ACC_FIFO(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSP_ACK_TIMEOUT_CFG_AND_ERR_CTRL_REQ_COUNT_ACC_FIFO_SHIFT)) & DSPSS_DSP_ACK_TIMEOUT_CFG_AND_ERR_CTRL_REQ_COUNT_ACC_FIFO_MASK)

#define DSPSS_DSP_ACK_TIMEOUT_CFG_AND_ERR_CTRL_DSP_ACK_TIMEOUT_ERR_TH0_MASK (0x100000U)
#define DSPSS_DSP_ACK_TIMEOUT_CFG_AND_ERR_CTRL_DSP_ACK_TIMEOUT_ERR_TH0_SHIFT (20U)
#define DSPSS_DSP_ACK_TIMEOUT_CFG_AND_ERR_CTRL_DSP_ACK_TIMEOUT_ERR_TH0_WIDTH (1U)
#define DSPSS_DSP_ACK_TIMEOUT_CFG_AND_ERR_CTRL_DSP_ACK_TIMEOUT_ERR_TH0(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSP_ACK_TIMEOUT_CFG_AND_ERR_CTRL_DSP_ACK_TIMEOUT_ERR_TH0_SHIFT)) & DSPSS_DSP_ACK_TIMEOUT_CFG_AND_ERR_CTRL_DSP_ACK_TIMEOUT_ERR_TH0_MASK)

#define DSPSS_DSP_ACK_TIMEOUT_CFG_AND_ERR_CTRL_DSP_ACK_TIMEOUT_ERR_TH1_MASK (0x200000U)
#define DSPSS_DSP_ACK_TIMEOUT_CFG_AND_ERR_CTRL_DSP_ACK_TIMEOUT_ERR_TH1_SHIFT (21U)
#define DSPSS_DSP_ACK_TIMEOUT_CFG_AND_ERR_CTRL_DSP_ACK_TIMEOUT_ERR_TH1_WIDTH (1U)
#define DSPSS_DSP_ACK_TIMEOUT_CFG_AND_ERR_CTRL_DSP_ACK_TIMEOUT_ERR_TH1(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSP_ACK_TIMEOUT_CFG_AND_ERR_CTRL_DSP_ACK_TIMEOUT_ERR_TH1_SHIFT)) & DSPSS_DSP_ACK_TIMEOUT_CFG_AND_ERR_CTRL_DSP_ACK_TIMEOUT_ERR_TH1_MASK)

#define DSPSS_DSP_ACK_TIMEOUT_CFG_AND_ERR_CTRL_DSP_ACK_TIMEOUT_ERR_TH2_MASK (0x400000U)
#define DSPSS_DSP_ACK_TIMEOUT_CFG_AND_ERR_CTRL_DSP_ACK_TIMEOUT_ERR_TH2_SHIFT (22U)
#define DSPSS_DSP_ACK_TIMEOUT_CFG_AND_ERR_CTRL_DSP_ACK_TIMEOUT_ERR_TH2_WIDTH (1U)
#define DSPSS_DSP_ACK_TIMEOUT_CFG_AND_ERR_CTRL_DSP_ACK_TIMEOUT_ERR_TH2(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSP_ACK_TIMEOUT_CFG_AND_ERR_CTRL_DSP_ACK_TIMEOUT_ERR_TH2_SHIFT)) & DSPSS_DSP_ACK_TIMEOUT_CFG_AND_ERR_CTRL_DSP_ACK_TIMEOUT_ERR_TH2_MASK)

#define DSPSS_DSP_ACK_TIMEOUT_CFG_AND_ERR_CTRL_DSP_ACK_TIMEOUT_ERR_TH3_MASK (0x800000U)
#define DSPSS_DSP_ACK_TIMEOUT_CFG_AND_ERR_CTRL_DSP_ACK_TIMEOUT_ERR_TH3_SHIFT (23U)
#define DSPSS_DSP_ACK_TIMEOUT_CFG_AND_ERR_CTRL_DSP_ACK_TIMEOUT_ERR_TH3_WIDTH (1U)
#define DSPSS_DSP_ACK_TIMEOUT_CFG_AND_ERR_CTRL_DSP_ACK_TIMEOUT_ERR_TH3(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSP_ACK_TIMEOUT_CFG_AND_ERR_CTRL_DSP_ACK_TIMEOUT_ERR_TH3_SHIFT)) & DSPSS_DSP_ACK_TIMEOUT_CFG_AND_ERR_CTRL_DSP_ACK_TIMEOUT_ERR_TH3_MASK)
/*! @} */

/*! @name ECC_ERROR_MONITOR_THREAD_SUSPEND_CTRL - Disable Monitoring of ECC Errors In XMEM And PMEM */
/*! @{ */

#define DSPSS_ECC_ERROR_MONITOR_THREAD_SUSPEND_CTRL_XMEM_EVEN_ECC_ERROR_DIS_MASK (0x1U)
#define DSPSS_ECC_ERROR_MONITOR_THREAD_SUSPEND_CTRL_XMEM_EVEN_ECC_ERROR_DIS_SHIFT (0U)
#define DSPSS_ECC_ERROR_MONITOR_THREAD_SUSPEND_CTRL_XMEM_EVEN_ECC_ERROR_DIS_WIDTH (1U)
#define DSPSS_ECC_ERROR_MONITOR_THREAD_SUSPEND_CTRL_XMEM_EVEN_ECC_ERROR_DIS(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_ECC_ERROR_MONITOR_THREAD_SUSPEND_CTRL_XMEM_EVEN_ECC_ERROR_DIS_SHIFT)) & DSPSS_ECC_ERROR_MONITOR_THREAD_SUSPEND_CTRL_XMEM_EVEN_ECC_ERROR_DIS_MASK)

#define DSPSS_ECC_ERROR_MONITOR_THREAD_SUSPEND_CTRL_XMEM_ODD_ECC_ERROR_DIS_MASK (0x2U)
#define DSPSS_ECC_ERROR_MONITOR_THREAD_SUSPEND_CTRL_XMEM_ODD_ECC_ERROR_DIS_SHIFT (1U)
#define DSPSS_ECC_ERROR_MONITOR_THREAD_SUSPEND_CTRL_XMEM_ODD_ECC_ERROR_DIS_WIDTH (1U)
#define DSPSS_ECC_ERROR_MONITOR_THREAD_SUSPEND_CTRL_XMEM_ODD_ECC_ERROR_DIS(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_ECC_ERROR_MONITOR_THREAD_SUSPEND_CTRL_XMEM_ODD_ECC_ERROR_DIS_SHIFT)) & DSPSS_ECC_ERROR_MONITOR_THREAD_SUSPEND_CTRL_XMEM_ODD_ECC_ERROR_DIS_MASK)

#define DSPSS_ECC_ERROR_MONITOR_THREAD_SUSPEND_CTRL_PMEM_ECC_ERROR_DIS_MASK (0x4U)
#define DSPSS_ECC_ERROR_MONITOR_THREAD_SUSPEND_CTRL_PMEM_ECC_ERROR_DIS_SHIFT (2U)
#define DSPSS_ECC_ERROR_MONITOR_THREAD_SUSPEND_CTRL_PMEM_ECC_ERROR_DIS_WIDTH (1U)
#define DSPSS_ECC_ERROR_MONITOR_THREAD_SUSPEND_CTRL_PMEM_ECC_ERROR_DIS(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_ECC_ERROR_MONITOR_THREAD_SUSPEND_CTRL_PMEM_ECC_ERROR_DIS_SHIFT)) & DSPSS_ECC_ERROR_MONITOR_THREAD_SUSPEND_CTRL_PMEM_ECC_ERROR_DIS_MASK)
/*! @} */

/*! @name INTERRUPT_ENABLE_REGISTER2 - Interrupt Enable */
/*! @{ */

#define DSPSS_INTERRUPT_ENABLE_REGISTER2_SDADC_SYNC_FIFO_OVERFLOW_IE_MASK (0xFU)
#define DSPSS_INTERRUPT_ENABLE_REGISTER2_SDADC_SYNC_FIFO_OVERFLOW_IE_SHIFT (0U)
#define DSPSS_INTERRUPT_ENABLE_REGISTER2_SDADC_SYNC_FIFO_OVERFLOW_IE_WIDTH (4U)
#define DSPSS_INTERRUPT_ENABLE_REGISTER2_SDADC_SYNC_FIFO_OVERFLOW_IE(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_INTERRUPT_ENABLE_REGISTER2_SDADC_SYNC_FIFO_OVERFLOW_IE_SHIFT)) & DSPSS_INTERRUPT_ENABLE_REGISTER2_SDADC_SYNC_FIFO_OVERFLOW_IE_MASK)

#define DSPSS_INTERRUPT_ENABLE_REGISTER2_DSP_CORE_BUFFER_OVERFLOW_IE_MASK (0xF00U)
#define DSPSS_INTERRUPT_ENABLE_REGISTER2_DSP_CORE_BUFFER_OVERFLOW_IE_SHIFT (8U)
#define DSPSS_INTERRUPT_ENABLE_REGISTER2_DSP_CORE_BUFFER_OVERFLOW_IE_WIDTH (4U)
#define DSPSS_INTERRUPT_ENABLE_REGISTER2_DSP_CORE_BUFFER_OVERFLOW_IE(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_INTERRUPT_ENABLE_REGISTER2_DSP_CORE_BUFFER_OVERFLOW_IE_SHIFT)) & DSPSS_INTERRUPT_ENABLE_REGISTER2_DSP_CORE_BUFFER_OVERFLOW_IE_MASK)

#define DSPSS_INTERRUPT_ENABLE_REGISTER2_DSP_CORE_BUFFER_UNDERRUN_IE_MASK (0xF000U)
#define DSPSS_INTERRUPT_ENABLE_REGISTER2_DSP_CORE_BUFFER_UNDERRUN_IE_SHIFT (12U)
#define DSPSS_INTERRUPT_ENABLE_REGISTER2_DSP_CORE_BUFFER_UNDERRUN_IE_WIDTH (4U)
#define DSPSS_INTERRUPT_ENABLE_REGISTER2_DSP_CORE_BUFFER_UNDERRUN_IE(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_INTERRUPT_ENABLE_REGISTER2_DSP_CORE_BUFFER_UNDERRUN_IE_SHIFT)) & DSPSS_INTERRUPT_ENABLE_REGISTER2_DSP_CORE_BUFFER_UNDERRUN_IE_MASK)

#define DSPSS_INTERRUPT_ENABLE_REGISTER2_DSP_ACK_TIMEOUT_ERR_IE_MASK (0x10000U)
#define DSPSS_INTERRUPT_ENABLE_REGISTER2_DSP_ACK_TIMEOUT_ERR_IE_SHIFT (16U)
#define DSPSS_INTERRUPT_ENABLE_REGISTER2_DSP_ACK_TIMEOUT_ERR_IE_WIDTH (1U)
#define DSPSS_INTERRUPT_ENABLE_REGISTER2_DSP_ACK_TIMEOUT_ERR_IE(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_INTERRUPT_ENABLE_REGISTER2_DSP_ACK_TIMEOUT_ERR_IE_SHIFT)) & DSPSS_INTERRUPT_ENABLE_REGISTER2_DSP_ACK_TIMEOUT_ERR_IE_MASK)

#define DSPSS_INTERRUPT_ENABLE_REGISTER2_REQ_FIFO_ERR_IE_EN_MASK (0x20000U)
#define DSPSS_INTERRUPT_ENABLE_REGISTER2_REQ_FIFO_ERR_IE_EN_SHIFT (17U)
#define DSPSS_INTERRUPT_ENABLE_REGISTER2_REQ_FIFO_ERR_IE_EN_WIDTH (1U)
#define DSPSS_INTERRUPT_ENABLE_REGISTER2_REQ_FIFO_ERR_IE_EN(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_INTERRUPT_ENABLE_REGISTER2_REQ_FIFO_ERR_IE_EN_SHIFT)) & DSPSS_INTERRUPT_ENABLE_REGISTER2_REQ_FIFO_ERR_IE_EN_MASK)

#define DSPSS_INTERRUPT_ENABLE_REGISTER2_DSP_INIT_LOW_IE_MASK (0x40000U)
#define DSPSS_INTERRUPT_ENABLE_REGISTER2_DSP_INIT_LOW_IE_SHIFT (18U)
#define DSPSS_INTERRUPT_ENABLE_REGISTER2_DSP_INIT_LOW_IE_WIDTH (1U)
#define DSPSS_INTERRUPT_ENABLE_REGISTER2_DSP_INIT_LOW_IE(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_INTERRUPT_ENABLE_REGISTER2_DSP_INIT_LOW_IE_SHIFT)) & DSPSS_INTERRUPT_ENABLE_REGISTER2_DSP_INIT_LOW_IE_MASK)

#define DSPSS_INTERRUPT_ENABLE_REGISTER2_REQ_ACC_FIFO_THRESHOLD_CROSS_INT_EN_MASK (0x80000U)
#define DSPSS_INTERRUPT_ENABLE_REGISTER2_REQ_ACC_FIFO_THRESHOLD_CROSS_INT_EN_SHIFT (19U)
#define DSPSS_INTERRUPT_ENABLE_REGISTER2_REQ_ACC_FIFO_THRESHOLD_CROSS_INT_EN_WIDTH (1U)
#define DSPSS_INTERRUPT_ENABLE_REGISTER2_REQ_ACC_FIFO_THRESHOLD_CROSS_INT_EN(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_INTERRUPT_ENABLE_REGISTER2_REQ_ACC_FIFO_THRESHOLD_CROSS_INT_EN_SHIFT)) & DSPSS_INTERRUPT_ENABLE_REGISTER2_REQ_ACC_FIFO_THRESHOLD_CROSS_INT_EN_MASK)
/*! @} */

/*! @name SDADC_SYNC_FIFO_ERROR_STATUS - FIFO Overflow Status */
/*! @{ */

#define DSPSS_SDADC_SYNC_FIFO_ERROR_STATUS_OVERFLOW_MASK (0xFU)
#define DSPSS_SDADC_SYNC_FIFO_ERROR_STATUS_OVERFLOW_SHIFT (0U)
#define DSPSS_SDADC_SYNC_FIFO_ERROR_STATUS_OVERFLOW_WIDTH (4U)
#define DSPSS_SDADC_SYNC_FIFO_ERROR_STATUS_OVERFLOW(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_SDADC_SYNC_FIFO_ERROR_STATUS_OVERFLOW_SHIFT)) & DSPSS_SDADC_SYNC_FIFO_ERROR_STATUS_OVERFLOW_MASK)

#define DSPSS_SDADC_SYNC_FIFO_ERROR_STATUS_REQ_FIFO_OVERFLOW_MASK (0x100U)
#define DSPSS_SDADC_SYNC_FIFO_ERROR_STATUS_REQ_FIFO_OVERFLOW_SHIFT (8U)
#define DSPSS_SDADC_SYNC_FIFO_ERROR_STATUS_REQ_FIFO_OVERFLOW_WIDTH (1U)
#define DSPSS_SDADC_SYNC_FIFO_ERROR_STATUS_REQ_FIFO_OVERFLOW(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_SDADC_SYNC_FIFO_ERROR_STATUS_REQ_FIFO_OVERFLOW_SHIFT)) & DSPSS_SDADC_SYNC_FIFO_ERROR_STATUS_REQ_FIFO_OVERFLOW_MASK)
/*! @} */

/*! @name DSP_CORE_BUFFER_CFG - Configuration For DSP-Core Buffer */
/*! @{ */

#define DSPSS_DSP_CORE_BUFFER_CFG_DSP_CORE_BUFFER_EN_MASK (0xFU)
#define DSPSS_DSP_CORE_BUFFER_CFG_DSP_CORE_BUFFER_EN_SHIFT (0U)
#define DSPSS_DSP_CORE_BUFFER_CFG_DSP_CORE_BUFFER_EN_WIDTH (4U)
#define DSPSS_DSP_CORE_BUFFER_CFG_DSP_CORE_BUFFER_EN(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSP_CORE_BUFFER_CFG_DSP_CORE_BUFFER_EN_SHIFT)) & DSPSS_DSP_CORE_BUFFER_CFG_DSP_CORE_BUFFER_EN_MASK)

#define DSPSS_DSP_CORE_BUFFER_CFG_DSP_CORE_BUFFER_MASTER_MASK (0xF0U)
#define DSPSS_DSP_CORE_BUFFER_CFG_DSP_CORE_BUFFER_MASTER_SHIFT (4U)
#define DSPSS_DSP_CORE_BUFFER_CFG_DSP_CORE_BUFFER_MASTER_WIDTH (4U)
#define DSPSS_DSP_CORE_BUFFER_CFG_DSP_CORE_BUFFER_MASTER(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSP_CORE_BUFFER_CFG_DSP_CORE_BUFFER_MASTER_SHIFT)) & DSPSS_DSP_CORE_BUFFER_CFG_DSP_CORE_BUFFER_MASTER_MASK)
/*! @} */

/*! @name DMA_BUFFER_CFG - DMA Buffer Configuration */
/*! @{ */

#define DSPSS_DMA_BUFFER_CFG_DMA_WRITE_EN_MASK   (0x3FU)
#define DSPSS_DMA_BUFFER_CFG_DMA_WRITE_EN_SHIFT  (0U)
#define DSPSS_DMA_BUFFER_CFG_DMA_WRITE_EN_WIDTH  (6U)
#define DSPSS_DMA_BUFFER_CFG_DMA_WRITE_EN(x)     (((uint32_t)(((uint32_t)(x)) << DSPSS_DMA_BUFFER_CFG_DMA_WRITE_EN_SHIFT)) & DSPSS_DMA_BUFFER_CFG_DMA_WRITE_EN_MASK)

#define DSPSS_DMA_BUFFER_CFG_DMA_READ_EN_MASK    (0xFC0U)
#define DSPSS_DMA_BUFFER_CFG_DMA_READ_EN_SHIFT   (6U)
#define DSPSS_DMA_BUFFER_CFG_DMA_READ_EN_WIDTH   (6U)
#define DSPSS_DMA_BUFFER_CFG_DMA_READ_EN(x)      (((uint32_t)(((uint32_t)(x)) << DSPSS_DMA_BUFFER_CFG_DMA_READ_EN_SHIFT)) & DSPSS_DMA_BUFFER_CFG_DMA_READ_EN_MASK)

#define DSPSS_DMA_BUFFER_CFG_MAP_XFR_DMA_ERR_ON_IPS_MASK (0x80000000U)
#define DSPSS_DMA_BUFFER_CFG_MAP_XFR_DMA_ERR_ON_IPS_SHIFT (31U)
#define DSPSS_DMA_BUFFER_CFG_MAP_XFR_DMA_ERR_ON_IPS_WIDTH (1U)
#define DSPSS_DMA_BUFFER_CFG_MAP_XFR_DMA_ERR_ON_IPS(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DMA_BUFFER_CFG_MAP_XFR_DMA_ERR_ON_IPS_SHIFT)) & DSPSS_DMA_BUFFER_CFG_MAP_XFR_DMA_ERR_ON_IPS_MASK)
/*! @} */

/*! @name SCHEDULER_MODE_CFG - Thread Scheduling Mode Selection */
/*! @{ */

#define DSPSS_SCHEDULER_MODE_CFG_SCHEDULER_MODE_MASK (0x3U)
#define DSPSS_SCHEDULER_MODE_CFG_SCHEDULER_MODE_SHIFT (0U)
#define DSPSS_SCHEDULER_MODE_CFG_SCHEDULER_MODE_WIDTH (2U)
#define DSPSS_SCHEDULER_MODE_CFG_SCHEDULER_MODE(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_SCHEDULER_MODE_CFG_SCHEDULER_MODE_SHIFT)) & DSPSS_SCHEDULER_MODE_CFG_SCHEDULER_MODE_MASK)

#define DSPSS_SCHEDULER_MODE_CFG_SCHD_SEQ_1_MASK (0x3CU)
#define DSPSS_SCHEDULER_MODE_CFG_SCHD_SEQ_1_SHIFT (2U)
#define DSPSS_SCHEDULER_MODE_CFG_SCHD_SEQ_1_WIDTH (4U)
#define DSPSS_SCHEDULER_MODE_CFG_SCHD_SEQ_1(x)   (((uint32_t)(((uint32_t)(x)) << DSPSS_SCHEDULER_MODE_CFG_SCHD_SEQ_1_SHIFT)) & DSPSS_SCHEDULER_MODE_CFG_SCHD_SEQ_1_MASK)

#define DSPSS_SCHEDULER_MODE_CFG_SCHD_SEQ_2_MASK (0x3C0U)
#define DSPSS_SCHEDULER_MODE_CFG_SCHD_SEQ_2_SHIFT (6U)
#define DSPSS_SCHEDULER_MODE_CFG_SCHD_SEQ_2_WIDTH (4U)
#define DSPSS_SCHEDULER_MODE_CFG_SCHD_SEQ_2(x)   (((uint32_t)(((uint32_t)(x)) << DSPSS_SCHEDULER_MODE_CFG_SCHD_SEQ_2_SHIFT)) & DSPSS_SCHEDULER_MODE_CFG_SCHD_SEQ_2_MASK)

#define DSPSS_SCHEDULER_MODE_CFG_SCHD_SEQ_3_MASK (0x3C00U)
#define DSPSS_SCHEDULER_MODE_CFG_SCHD_SEQ_3_SHIFT (10U)
#define DSPSS_SCHEDULER_MODE_CFG_SCHD_SEQ_3_WIDTH (4U)
#define DSPSS_SCHEDULER_MODE_CFG_SCHD_SEQ_3(x)   (((uint32_t)(((uint32_t)(x)) << DSPSS_SCHEDULER_MODE_CFG_SCHD_SEQ_3_SHIFT)) & DSPSS_SCHEDULER_MODE_CFG_SCHD_SEQ_3_MASK)

#define DSPSS_SCHEDULER_MODE_CFG_SCHD_SEQ_4_MASK (0x3C000U)
#define DSPSS_SCHEDULER_MODE_CFG_SCHD_SEQ_4_SHIFT (14U)
#define DSPSS_SCHEDULER_MODE_CFG_SCHD_SEQ_4_WIDTH (4U)
#define DSPSS_SCHEDULER_MODE_CFG_SCHD_SEQ_4(x)   (((uint32_t)(((uint32_t)(x)) << DSPSS_SCHEDULER_MODE_CFG_SCHD_SEQ_4_SHIFT)) & DSPSS_SCHEDULER_MODE_CFG_SCHD_SEQ_4_MASK)

#define DSPSS_SCHEDULER_MODE_CFG_NEXT_REQ_HALT_ACK_WAIT_CTRL_MASK (0x40000U)
#define DSPSS_SCHEDULER_MODE_CFG_NEXT_REQ_HALT_ACK_WAIT_CTRL_SHIFT (18U)
#define DSPSS_SCHEDULER_MODE_CFG_NEXT_REQ_HALT_ACK_WAIT_CTRL_WIDTH (1U)
#define DSPSS_SCHEDULER_MODE_CFG_NEXT_REQ_HALT_ACK_WAIT_CTRL(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_SCHEDULER_MODE_CFG_NEXT_REQ_HALT_ACK_WAIT_CTRL_SHIFT)) & DSPSS_SCHEDULER_MODE_CFG_NEXT_REQ_HALT_ACK_WAIT_CTRL_MASK)
/*! @} */

/*! @name DSPSS_DSP0_CFG - DSP0 Reset And Core Trigger Configuration */
/*! @{ */

#define DSPSS_DSPSS_DSP0_CFG_SCHED_DSP_RST_CTRL_EN_MASK (0x1U)
#define DSPSS_DSPSS_DSP0_CFG_SCHED_DSP_RST_CTRL_EN_SHIFT (0U)
#define DSPSS_DSPSS_DSP0_CFG_SCHED_DSP_RST_CTRL_EN_WIDTH (1U)
#define DSPSS_DSPSS_DSP0_CFG_SCHED_DSP_RST_CTRL_EN(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSPSS_DSP0_CFG_SCHED_DSP_RST_CTRL_EN_SHIFT)) & DSPSS_DSPSS_DSP0_CFG_SCHED_DSP_RST_CTRL_EN_MASK)

#define DSPSS_DSPSS_DSP0_CFG_dspss_scheduler_dsp0_reset_MASK (0x2U)
#define DSPSS_DSPSS_DSP0_CFG_dspss_scheduler_dsp0_reset_SHIFT (1U)
#define DSPSS_DSPSS_DSP0_CFG_dspss_scheduler_dsp0_reset_WIDTH (1U)
#define DSPSS_DSPSS_DSP0_CFG_dspss_scheduler_dsp0_reset(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSPSS_DSP0_CFG_dspss_scheduler_dsp0_reset_SHIFT)) & DSPSS_DSPSS_DSP0_CFG_dspss_scheduler_dsp0_reset_MASK)

#define DSPSS_DSPSS_DSP0_CFG_dspss_dsp0_core_trigger_cfg_MASK (0xCU)
#define DSPSS_DSPSS_DSP0_CFG_dspss_dsp0_core_trigger_cfg_SHIFT (2U)
#define DSPSS_DSPSS_DSP0_CFG_dspss_dsp0_core_trigger_cfg_WIDTH (2U)
#define DSPSS_DSPSS_DSP0_CFG_dspss_dsp0_core_trigger_cfg(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSPSS_DSP0_CFG_dspss_dsp0_core_trigger_cfg_SHIFT)) & DSPSS_DSPSS_DSP0_CFG_dspss_dsp0_core_trigger_cfg_MASK)

#define DSPSS_DSPSS_DSP0_CFG_XMEM_CTRL_PRIORITY_MASK (0x10U)
#define DSPSS_DSPSS_DSP0_CFG_XMEM_CTRL_PRIORITY_SHIFT (4U)
#define DSPSS_DSPSS_DSP0_CFG_XMEM_CTRL_PRIORITY_WIDTH (1U)
#define DSPSS_DSPSS_DSP0_CFG_XMEM_CTRL_PRIORITY(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSPSS_DSP0_CFG_XMEM_CTRL_PRIORITY_SHIFT)) & DSPSS_DSPSS_DSP0_CFG_XMEM_CTRL_PRIORITY_MASK)

#define DSPSS_DSPSS_DSP0_CFG_dspss_dsp0_core_trigger_safety_cfg_MASK (0x180U)
#define DSPSS_DSPSS_DSP0_CFG_dspss_dsp0_core_trigger_safety_cfg_SHIFT (7U)
#define DSPSS_DSPSS_DSP0_CFG_dspss_dsp0_core_trigger_safety_cfg_WIDTH (2U)
#define DSPSS_DSPSS_DSP0_CFG_dspss_dsp0_core_trigger_safety_cfg(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSPSS_DSP0_CFG_dspss_dsp0_core_trigger_safety_cfg_SHIFT)) & DSPSS_DSPSS_DSP0_CFG_dspss_dsp0_core_trigger_safety_cfg_MASK)
/*! @} */

/*! @name INTERRUPT_ENABLE_REGISTER - Interrupt Enable */
/*! @{ */

#define DSPSS_INTERRUPT_ENABLE_REGISTER_DSP_ERROR_INTR_EN_MASK (0xFU)
#define DSPSS_INTERRUPT_ENABLE_REGISTER_DSP_ERROR_INTR_EN_SHIFT (0U)
#define DSPSS_INTERRUPT_ENABLE_REGISTER_DSP_ERROR_INTR_EN_WIDTH (4U)
#define DSPSS_INTERRUPT_ENABLE_REGISTER_DSP_ERROR_INTR_EN(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_INTERRUPT_ENABLE_REGISTER_DSP_ERROR_INTR_EN_SHIFT)) & DSPSS_INTERRUPT_ENABLE_REGISTER_DSP_ERROR_INTR_EN_MASK)

#define DSPSS_INTERRUPT_ENABLE_REGISTER_DMA_WRITE_BUFFER_ERR_INTR_EN_MASK (0x3F0U)
#define DSPSS_INTERRUPT_ENABLE_REGISTER_DMA_WRITE_BUFFER_ERR_INTR_EN_SHIFT (4U)
#define DSPSS_INTERRUPT_ENABLE_REGISTER_DMA_WRITE_BUFFER_ERR_INTR_EN_WIDTH (6U)
#define DSPSS_INTERRUPT_ENABLE_REGISTER_DMA_WRITE_BUFFER_ERR_INTR_EN(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_INTERRUPT_ENABLE_REGISTER_DMA_WRITE_BUFFER_ERR_INTR_EN_SHIFT)) & DSPSS_INTERRUPT_ENABLE_REGISTER_DMA_WRITE_BUFFER_ERR_INTR_EN_MASK)

#define DSPSS_INTERRUPT_ENABLE_REGISTER_DMA_READ_BUFFER_ERR_INTR_EN_MASK (0xFC00U)
#define DSPSS_INTERRUPT_ENABLE_REGISTER_DMA_READ_BUFFER_ERR_INTR_EN_SHIFT (10U)
#define DSPSS_INTERRUPT_ENABLE_REGISTER_DMA_READ_BUFFER_ERR_INTR_EN_WIDTH (6U)
#define DSPSS_INTERRUPT_ENABLE_REGISTER_DMA_READ_BUFFER_ERR_INTR_EN(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_INTERRUPT_ENABLE_REGISTER_DMA_READ_BUFFER_ERR_INTR_EN_SHIFT)) & DSPSS_INTERRUPT_ENABLE_REGISTER_DMA_READ_BUFFER_ERR_INTR_EN_MASK)

#define DSPSS_INTERRUPT_ENABLE_REGISTER_DMA_WRITE_BUFFER_XFR_ERR_INTR_EN_MASK (0x3F0000U)
#define DSPSS_INTERRUPT_ENABLE_REGISTER_DMA_WRITE_BUFFER_XFR_ERR_INTR_EN_SHIFT (16U)
#define DSPSS_INTERRUPT_ENABLE_REGISTER_DMA_WRITE_BUFFER_XFR_ERR_INTR_EN_WIDTH (6U)
#define DSPSS_INTERRUPT_ENABLE_REGISTER_DMA_WRITE_BUFFER_XFR_ERR_INTR_EN(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_INTERRUPT_ENABLE_REGISTER_DMA_WRITE_BUFFER_XFR_ERR_INTR_EN_SHIFT)) & DSPSS_INTERRUPT_ENABLE_REGISTER_DMA_WRITE_BUFFER_XFR_ERR_INTR_EN_MASK)

#define DSPSS_INTERRUPT_ENABLE_REGISTER_DMA_READ_BUFFER_XFR_ERR_INTR_EN_MASK (0xFC00000U)
#define DSPSS_INTERRUPT_ENABLE_REGISTER_DMA_READ_BUFFER_XFR_ERR_INTR_EN_SHIFT (22U)
#define DSPSS_INTERRUPT_ENABLE_REGISTER_DMA_READ_BUFFER_XFR_ERR_INTR_EN_WIDTH (6U)
#define DSPSS_INTERRUPT_ENABLE_REGISTER_DMA_READ_BUFFER_XFR_ERR_INTR_EN(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_INTERRUPT_ENABLE_REGISTER_DMA_READ_BUFFER_XFR_ERR_INTR_EN_SHIFT)) & DSPSS_INTERRUPT_ENABLE_REGISTER_DMA_READ_BUFFER_XFR_ERR_INTR_EN_MASK)
/*! @} */

/*! @name DSPSS_DSP_IO_INTF0 - DSP Trigger to Core */
/*! @{ */

#define DSPSS_DSPSS_DSP_IO_INTF0_DSP_TRIGGER_CORE_TH0_MASK (0x1U)
#define DSPSS_DSPSS_DSP_IO_INTF0_DSP_TRIGGER_CORE_TH0_SHIFT (0U)
#define DSPSS_DSPSS_DSP_IO_INTF0_DSP_TRIGGER_CORE_TH0_WIDTH (1U)
#define DSPSS_DSPSS_DSP_IO_INTF0_DSP_TRIGGER_CORE_TH0(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSPSS_DSP_IO_INTF0_DSP_TRIGGER_CORE_TH0_SHIFT)) & DSPSS_DSPSS_DSP_IO_INTF0_DSP_TRIGGER_CORE_TH0_MASK)

#define DSPSS_DSPSS_DSP_IO_INTF0_DSP_TRIGGER_CORE_TH1_MASK (0x2U)
#define DSPSS_DSPSS_DSP_IO_INTF0_DSP_TRIGGER_CORE_TH1_SHIFT (1U)
#define DSPSS_DSPSS_DSP_IO_INTF0_DSP_TRIGGER_CORE_TH1_WIDTH (1U)
#define DSPSS_DSPSS_DSP_IO_INTF0_DSP_TRIGGER_CORE_TH1(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSPSS_DSP_IO_INTF0_DSP_TRIGGER_CORE_TH1_SHIFT)) & DSPSS_DSPSS_DSP_IO_INTF0_DSP_TRIGGER_CORE_TH1_MASK)

#define DSPSS_DSPSS_DSP_IO_INTF0_DSP_TRIGGER_CORE_TH2_MASK (0x4U)
#define DSPSS_DSPSS_DSP_IO_INTF0_DSP_TRIGGER_CORE_TH2_SHIFT (2U)
#define DSPSS_DSPSS_DSP_IO_INTF0_DSP_TRIGGER_CORE_TH2_WIDTH (1U)
#define DSPSS_DSPSS_DSP_IO_INTF0_DSP_TRIGGER_CORE_TH2(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSPSS_DSP_IO_INTF0_DSP_TRIGGER_CORE_TH2_SHIFT)) & DSPSS_DSPSS_DSP_IO_INTF0_DSP_TRIGGER_CORE_TH2_MASK)

#define DSPSS_DSPSS_DSP_IO_INTF0_DSP_TRIGGER_CORE_TH3_MASK (0x8U)
#define DSPSS_DSPSS_DSP_IO_INTF0_DSP_TRIGGER_CORE_TH3_SHIFT (3U)
#define DSPSS_DSPSS_DSP_IO_INTF0_DSP_TRIGGER_CORE_TH3_WIDTH (1U)
#define DSPSS_DSPSS_DSP_IO_INTF0_DSP_TRIGGER_CORE_TH3(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSPSS_DSP_IO_INTF0_DSP_TRIGGER_CORE_TH3_SHIFT)) & DSPSS_DSPSS_DSP_IO_INTF0_DSP_TRIGGER_CORE_TH3_MASK)
/*! @} */

/*! @name CURR_ACTIVE_THRD - DSP Core Status */
/*! @{ */

#define DSPSS_CURR_ACTIVE_THRD_CURR_ACTIVE_THREAD_MASK (0xFU)
#define DSPSS_CURR_ACTIVE_THRD_CURR_ACTIVE_THREAD_SHIFT (0U)
#define DSPSS_CURR_ACTIVE_THRD_CURR_ACTIVE_THREAD_WIDTH (4U)
#define DSPSS_CURR_ACTIVE_THRD_CURR_ACTIVE_THREAD(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_CURR_ACTIVE_THRD_CURR_ACTIVE_THREAD_SHIFT)) & DSPSS_CURR_ACTIVE_THRD_CURR_ACTIVE_THREAD_MASK)

#define DSPSS_CURR_ACTIVE_THRD_DSP_INIT_COMP_MASK (0x10U)
#define DSPSS_CURR_ACTIVE_THRD_DSP_INIT_COMP_SHIFT (4U)
#define DSPSS_CURR_ACTIVE_THRD_DSP_INIT_COMP_WIDTH (1U)
#define DSPSS_CURR_ACTIVE_THRD_DSP_INIT_COMP(x)  (((uint32_t)(((uint32_t)(x)) << DSPSS_CURR_ACTIVE_THRD_DSP_INIT_COMP_SHIFT)) & DSPSS_CURR_ACTIVE_THRD_DSP_INIT_COMP_MASK)

#define DSPSS_CURR_ACTIVE_THRD_DSP_THRD_SLEEP_STATUS_MASK (0x3C0U)
#define DSPSS_CURR_ACTIVE_THRD_DSP_THRD_SLEEP_STATUS_SHIFT (6U)
#define DSPSS_CURR_ACTIVE_THRD_DSP_THRD_SLEEP_STATUS_WIDTH (4U)
#define DSPSS_CURR_ACTIVE_THRD_DSP_THRD_SLEEP_STATUS(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_CURR_ACTIVE_THRD_DSP_THRD_SLEEP_STATUS_SHIFT)) & DSPSS_CURR_ACTIVE_THRD_DSP_THRD_SLEEP_STATUS_MASK)

#define DSPSS_CURR_ACTIVE_THRD_LAST_CTXT_REQ_MASK (0x3C00U)
#define DSPSS_CURR_ACTIVE_THRD_LAST_CTXT_REQ_SHIFT (10U)
#define DSPSS_CURR_ACTIVE_THRD_LAST_CTXT_REQ_WIDTH (4U)
#define DSPSS_CURR_ACTIVE_THRD_LAST_CTXT_REQ(x)  (((uint32_t)(((uint32_t)(x)) << DSPSS_CURR_ACTIVE_THRD_LAST_CTXT_REQ_SHIFT)) & DSPSS_CURR_ACTIVE_THRD_LAST_CTXT_REQ_MASK)

#define DSPSS_CURR_ACTIVE_THRD_DSP_COMP_LOW_MASK (0x4000U)
#define DSPSS_CURR_ACTIVE_THRD_DSP_COMP_LOW_SHIFT (14U)
#define DSPSS_CURR_ACTIVE_THRD_DSP_COMP_LOW_WIDTH (1U)
#define DSPSS_CURR_ACTIVE_THRD_DSP_COMP_LOW(x)   (((uint32_t)(((uint32_t)(x)) << DSPSS_CURR_ACTIVE_THRD_DSP_COMP_LOW_SHIFT)) & DSPSS_CURR_ACTIVE_THRD_DSP_COMP_LOW_MASK)
/*! @} */

/*! @name DSPSS_DSP_CORE_TRIGGER_SAFETY - >DSP Safety Trigger to Core..DSP Safety Trigger to Core */
/*! @{ */

#define DSPSS_DSPSS_DSP_CORE_TRIGGER_SAFETY_DSP_TRIGGER_SAFETY_1_MASK (0x1U)
#define DSPSS_DSPSS_DSP_CORE_TRIGGER_SAFETY_DSP_TRIGGER_SAFETY_1_SHIFT (0U)
#define DSPSS_DSPSS_DSP_CORE_TRIGGER_SAFETY_DSP_TRIGGER_SAFETY_1_WIDTH (1U)
#define DSPSS_DSPSS_DSP_CORE_TRIGGER_SAFETY_DSP_TRIGGER_SAFETY_1(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSPSS_DSP_CORE_TRIGGER_SAFETY_DSP_TRIGGER_SAFETY_1_SHIFT)) & DSPSS_DSPSS_DSP_CORE_TRIGGER_SAFETY_DSP_TRIGGER_SAFETY_1_MASK)

#define DSPSS_DSPSS_DSP_CORE_TRIGGER_SAFETY_DSP_TRIGGER_SAFETY_2_MASK (0x2U)
#define DSPSS_DSPSS_DSP_CORE_TRIGGER_SAFETY_DSP_TRIGGER_SAFETY_2_SHIFT (1U)
#define DSPSS_DSPSS_DSP_CORE_TRIGGER_SAFETY_DSP_TRIGGER_SAFETY_2_WIDTH (1U)
#define DSPSS_DSPSS_DSP_CORE_TRIGGER_SAFETY_DSP_TRIGGER_SAFETY_2(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSPSS_DSP_CORE_TRIGGER_SAFETY_DSP_TRIGGER_SAFETY_2_SHIFT)) & DSPSS_DSPSS_DSP_CORE_TRIGGER_SAFETY_DSP_TRIGGER_SAFETY_2_MASK)
/*! @} */

/*! @name DMA_READ_ADDR4 - Reference DMA Read Region */
/*! @{ */

#define DSPSS_DMA_READ_ADDR4_DMA_READ_START_ADDR_MASK (0x3FFFU)
#define DSPSS_DMA_READ_ADDR4_DMA_READ_START_ADDR_SHIFT (0U)
#define DSPSS_DMA_READ_ADDR4_DMA_READ_START_ADDR_WIDTH (14U)
#define DSPSS_DMA_READ_ADDR4_DMA_READ_START_ADDR(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DMA_READ_ADDR4_DMA_READ_START_ADDR_SHIFT)) & DSPSS_DMA_READ_ADDR4_DMA_READ_START_ADDR_MASK)

#define DSPSS_DMA_READ_ADDR4_DMA_READ_END_ADDR_MASK (0xFFFC0000U)
#define DSPSS_DMA_READ_ADDR4_DMA_READ_END_ADDR_SHIFT (18U)
#define DSPSS_DMA_READ_ADDR4_DMA_READ_END_ADDR_WIDTH (14U)
#define DSPSS_DMA_READ_ADDR4_DMA_READ_END_ADDR(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DMA_READ_ADDR4_DMA_READ_END_ADDR_SHIFT)) & DSPSS_DMA_READ_ADDR4_DMA_READ_END_ADDR_MASK)
/*! @} */

/*! @name DMA_ERROR_STATUS4 - DMA Error Status */
/*! @{ */

#define DSPSS_DMA_ERROR_STATUS4_DMA_ADDR_MISMATCH_WR_BUFFER_MASK (0x1U)
#define DSPSS_DMA_ERROR_STATUS4_DMA_ADDR_MISMATCH_WR_BUFFER_SHIFT (0U)
#define DSPSS_DMA_ERROR_STATUS4_DMA_ADDR_MISMATCH_WR_BUFFER_WIDTH (1U)
#define DSPSS_DMA_ERROR_STATUS4_DMA_ADDR_MISMATCH_WR_BUFFER(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DMA_ERROR_STATUS4_DMA_ADDR_MISMATCH_WR_BUFFER_SHIFT)) & DSPSS_DMA_ERROR_STATUS4_DMA_ADDR_MISMATCH_WR_BUFFER_MASK)

#define DSPSS_DMA_ERROR_STATUS4_DMA_ADDR_MISMATCH_RD_BUFFER_MASK (0x2U)
#define DSPSS_DMA_ERROR_STATUS4_DMA_ADDR_MISMATCH_RD_BUFFER_SHIFT (1U)
#define DSPSS_DMA_ERROR_STATUS4_DMA_ADDR_MISMATCH_RD_BUFFER_WIDTH (1U)
#define DSPSS_DMA_ERROR_STATUS4_DMA_ADDR_MISMATCH_RD_BUFFER(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DMA_ERROR_STATUS4_DMA_ADDR_MISMATCH_RD_BUFFER_SHIFT)) & DSPSS_DMA_ERROR_STATUS4_DMA_ADDR_MISMATCH_RD_BUFFER_MASK)

#define DSPSS_DMA_ERROR_STATUS4_DMA_XFR_ERR_WRITE_MASK (0x4U)
#define DSPSS_DMA_ERROR_STATUS4_DMA_XFR_ERR_WRITE_SHIFT (2U)
#define DSPSS_DMA_ERROR_STATUS4_DMA_XFR_ERR_WRITE_WIDTH (1U)
#define DSPSS_DMA_ERROR_STATUS4_DMA_XFR_ERR_WRITE(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DMA_ERROR_STATUS4_DMA_XFR_ERR_WRITE_SHIFT)) & DSPSS_DMA_ERROR_STATUS4_DMA_XFR_ERR_WRITE_MASK)

#define DSPSS_DMA_ERROR_STATUS4_DMA_XFR_ERR_READ_MASK (0x8U)
#define DSPSS_DMA_ERROR_STATUS4_DMA_XFR_ERR_READ_SHIFT (3U)
#define DSPSS_DMA_ERROR_STATUS4_DMA_XFR_ERR_READ_WIDTH (1U)
#define DSPSS_DMA_ERROR_STATUS4_DMA_XFR_ERR_READ(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DMA_ERROR_STATUS4_DMA_XFR_ERR_READ_SHIFT)) & DSPSS_DMA_ERROR_STATUS4_DMA_XFR_ERR_READ_MASK)
/*! @} */

/*! @name DMA_WRITE_ADDR4 - Reference DMA Write Region */
/*! @{ */

#define DSPSS_DMA_WRITE_ADDR4_DMA_WRITE_START_ADDR_MASK (0x3FFFU)
#define DSPSS_DMA_WRITE_ADDR4_DMA_WRITE_START_ADDR_SHIFT (0U)
#define DSPSS_DMA_WRITE_ADDR4_DMA_WRITE_START_ADDR_WIDTH (14U)
#define DSPSS_DMA_WRITE_ADDR4_DMA_WRITE_START_ADDR(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DMA_WRITE_ADDR4_DMA_WRITE_START_ADDR_SHIFT)) & DSPSS_DMA_WRITE_ADDR4_DMA_WRITE_START_ADDR_MASK)

#define DSPSS_DMA_WRITE_ADDR4_DMA_WRITE_END_ADDR_MASK (0xFFFC0000U)
#define DSPSS_DMA_WRITE_ADDR4_DMA_WRITE_END_ADDR_SHIFT (18U)
#define DSPSS_DMA_WRITE_ADDR4_DMA_WRITE_END_ADDR_WIDTH (14U)
#define DSPSS_DMA_WRITE_ADDR4_DMA_WRITE_END_ADDR(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DMA_WRITE_ADDR4_DMA_WRITE_END_ADDR_SHIFT)) & DSPSS_DMA_WRITE_ADDR4_DMA_WRITE_END_ADDR_MASK)
/*! @} */

/*! @name DMA_CURR_WR_PTR4 - DMA Current Write Pointer */
/*! @{ */

#define DSPSS_DMA_CURR_WR_PTR4_DMA_CURR_WRITE_PTR_MASK (0x3FFFU)
#define DSPSS_DMA_CURR_WR_PTR4_DMA_CURR_WRITE_PTR_SHIFT (0U)
#define DSPSS_DMA_CURR_WR_PTR4_DMA_CURR_WRITE_PTR_WIDTH (14U)
#define DSPSS_DMA_CURR_WR_PTR4_DMA_CURR_WRITE_PTR(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DMA_CURR_WR_PTR4_DMA_CURR_WRITE_PTR_SHIFT)) & DSPSS_DMA_CURR_WR_PTR4_DMA_CURR_WRITE_PTR_MASK)

#define DSPSS_DMA_CURR_WR_PTR4_DMA_WRITE_PTR_WRAP_MASK (0x80000000U)
#define DSPSS_DMA_CURR_WR_PTR4_DMA_WRITE_PTR_WRAP_SHIFT (31U)
#define DSPSS_DMA_CURR_WR_PTR4_DMA_WRITE_PTR_WRAP_WIDTH (1U)
#define DSPSS_DMA_CURR_WR_PTR4_DMA_WRITE_PTR_WRAP(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DMA_CURR_WR_PTR4_DMA_WRITE_PTR_WRAP_SHIFT)) & DSPSS_DMA_CURR_WR_PTR4_DMA_WRITE_PTR_WRAP_MASK)
/*! @} */

/*! @name DMA_CURR_RD_PTR4 - DMA Current Read Pointer */
/*! @{ */

#define DSPSS_DMA_CURR_RD_PTR4_DMA_CURR_READ_PTR_MASK (0x3FFFU)
#define DSPSS_DMA_CURR_RD_PTR4_DMA_CURR_READ_PTR_SHIFT (0U)
#define DSPSS_DMA_CURR_RD_PTR4_DMA_CURR_READ_PTR_WIDTH (14U)
#define DSPSS_DMA_CURR_RD_PTR4_DMA_CURR_READ_PTR(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DMA_CURR_RD_PTR4_DMA_CURR_READ_PTR_SHIFT)) & DSPSS_DMA_CURR_RD_PTR4_DMA_CURR_READ_PTR_MASK)

#define DSPSS_DMA_CURR_RD_PTR4_DMA_READ_PTR_WRAP_MASK (0x80000000U)
#define DSPSS_DMA_CURR_RD_PTR4_DMA_READ_PTR_WRAP_SHIFT (31U)
#define DSPSS_DMA_CURR_RD_PTR4_DMA_READ_PTR_WRAP_WIDTH (1U)
#define DSPSS_DMA_CURR_RD_PTR4_DMA_READ_PTR_WRAP(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DMA_CURR_RD_PTR4_DMA_READ_PTR_WRAP_SHIFT)) & DSPSS_DMA_CURR_RD_PTR4_DMA_READ_PTR_WRAP_MASK)
/*! @} */

/*! @name DSP_TO_DMA_REQUEST_STATUS4 - DMA Request Status */
/*! @{ */

#define DSPSS_DSP_TO_DMA_REQUEST_STATUS4_DSP_TO_DMA_REQUEST_STATUS_MASK (0x1U)
#define DSPSS_DSP_TO_DMA_REQUEST_STATUS4_DSP_TO_DMA_REQUEST_STATUS_SHIFT (0U)
#define DSPSS_DSP_TO_DMA_REQUEST_STATUS4_DSP_TO_DMA_REQUEST_STATUS_WIDTH (1U)
#define DSPSS_DSP_TO_DMA_REQUEST_STATUS4_DSP_TO_DMA_REQUEST_STATUS(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSP_TO_DMA_REQUEST_STATUS4_DSP_TO_DMA_REQUEST_STATUS_SHIFT)) & DSPSS_DSP_TO_DMA_REQUEST_STATUS4_DSP_TO_DMA_REQUEST_STATUS_MASK)

#define DSPSS_DSP_TO_DMA_REQUEST_STATUS4_DMA_TO_DSP_ACK_STATUS_MASK (0x2U)
#define DSPSS_DSP_TO_DMA_REQUEST_STATUS4_DMA_TO_DSP_ACK_STATUS_SHIFT (1U)
#define DSPSS_DSP_TO_DMA_REQUEST_STATUS4_DMA_TO_DSP_ACK_STATUS_WIDTH (1U)
#define DSPSS_DSP_TO_DMA_REQUEST_STATUS4_DMA_TO_DSP_ACK_STATUS(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSP_TO_DMA_REQUEST_STATUS4_DMA_TO_DSP_ACK_STATUS_SHIFT)) & DSPSS_DSP_TO_DMA_REQUEST_STATUS4_DMA_TO_DSP_ACK_STATUS_MASK)
/*! @} */

/*! @name HW_CTRL_DMA_REQ_STOP4 - Stop DMA Request */
/*! @{ */

#define DSPSS_HW_CTRL_DMA_REQ_STOP4_STOP_MASK    (0x1U)
#define DSPSS_HW_CTRL_DMA_REQ_STOP4_STOP_SHIFT   (0U)
#define DSPSS_HW_CTRL_DMA_REQ_STOP4_STOP_WIDTH   (1U)
#define DSPSS_HW_CTRL_DMA_REQ_STOP4_STOP(x)      (((uint32_t)(((uint32_t)(x)) << DSPSS_HW_CTRL_DMA_REQ_STOP4_STOP_SHIFT)) & DSPSS_HW_CTRL_DMA_REQ_STOP4_STOP_MASK)
/*! @} */

/*! @name DMA_ERROR_CTRL4 - DMA Error Control */
/*! @{ */

#define DSPSS_DMA_ERROR_CTRL4_DONE_MASK          (0x1U)
#define DSPSS_DMA_ERROR_CTRL4_DONE_SHIFT         (0U)
#define DSPSS_DMA_ERROR_CTRL4_DONE_WIDTH         (1U)
#define DSPSS_DMA_ERROR_CTRL4_DONE(x)            (((uint32_t)(((uint32_t)(x)) << DSPSS_DMA_ERROR_CTRL4_DONE_SHIFT)) & DSPSS_DMA_ERROR_CTRL4_DONE_MASK)
/*! @} */

/*! @name HW_CTRL_DMA_REQ_RESPONSE4 - Hardware Control Handling for DMA Request And Response */
/*! @{ */

#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE4_START_MASK (0x1U)
#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE4_START_SHIFT (0U)
#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE4_START_WIDTH (1U)
#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE4_START(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_HW_CTRL_DMA_REQ_RESPONSE4_START_SHIFT)) & DSPSS_HW_CTRL_DMA_REQ_RESPONSE4_START_MASK)

#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE4_NUM_OF_DMA_REQ_MASK (0x1FEU)
#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE4_NUM_OF_DMA_REQ_SHIFT (1U)
#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE4_NUM_OF_DMA_REQ_WIDTH (8U)
#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE4_NUM_OF_DMA_REQ(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_HW_CTRL_DMA_REQ_RESPONSE4_NUM_OF_DMA_REQ_SHIFT)) & DSPSS_HW_CTRL_DMA_REQ_RESPONSE4_NUM_OF_DMA_REQ_MASK)

#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE4_DONE_MASK (0x200U)
#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE4_DONE_SHIFT (9U)
#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE4_DONE_WIDTH (1U)
#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE4_DONE(x)  (((uint32_t)(((uint32_t)(x)) << DSPSS_HW_CTRL_DMA_REQ_RESPONSE4_DONE_SHIFT)) & DSPSS_HW_CTRL_DMA_REQ_RESPONSE4_DONE_MASK)

#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE4_NUM_OF_DMA_REQ_PEND_MASK (0x3FC00U)
#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE4_NUM_OF_DMA_REQ_PEND_SHIFT (10U)
#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE4_NUM_OF_DMA_REQ_PEND_WIDTH (8U)
#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE4_NUM_OF_DMA_REQ_PEND(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_HW_CTRL_DMA_REQ_RESPONSE4_NUM_OF_DMA_REQ_PEND_SHIFT)) & DSPSS_HW_CTRL_DMA_REQ_RESPONSE4_NUM_OF_DMA_REQ_PEND_MASK)
/*! @} */

/*! @name DMA_READ_ADDR5 - Reference DMA Read Region */
/*! @{ */

#define DSPSS_DMA_READ_ADDR5_DMA_READ_START_ADDR_MASK (0x3FFFU)
#define DSPSS_DMA_READ_ADDR5_DMA_READ_START_ADDR_SHIFT (0U)
#define DSPSS_DMA_READ_ADDR5_DMA_READ_START_ADDR_WIDTH (14U)
#define DSPSS_DMA_READ_ADDR5_DMA_READ_START_ADDR(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DMA_READ_ADDR5_DMA_READ_START_ADDR_SHIFT)) & DSPSS_DMA_READ_ADDR5_DMA_READ_START_ADDR_MASK)

#define DSPSS_DMA_READ_ADDR5_DMA_READ_END_ADDR_MASK (0xFFFC0000U)
#define DSPSS_DMA_READ_ADDR5_DMA_READ_END_ADDR_SHIFT (18U)
#define DSPSS_DMA_READ_ADDR5_DMA_READ_END_ADDR_WIDTH (14U)
#define DSPSS_DMA_READ_ADDR5_DMA_READ_END_ADDR(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DMA_READ_ADDR5_DMA_READ_END_ADDR_SHIFT)) & DSPSS_DMA_READ_ADDR5_DMA_READ_END_ADDR_MASK)
/*! @} */

/*! @name DMA_ERROR_STATUS5 - DMA Error Status */
/*! @{ */

#define DSPSS_DMA_ERROR_STATUS5_DMA_ADDR_MISMATCH_WR_BUFFER_MASK (0x1U)
#define DSPSS_DMA_ERROR_STATUS5_DMA_ADDR_MISMATCH_WR_BUFFER_SHIFT (0U)
#define DSPSS_DMA_ERROR_STATUS5_DMA_ADDR_MISMATCH_WR_BUFFER_WIDTH (1U)
#define DSPSS_DMA_ERROR_STATUS5_DMA_ADDR_MISMATCH_WR_BUFFER(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DMA_ERROR_STATUS5_DMA_ADDR_MISMATCH_WR_BUFFER_SHIFT)) & DSPSS_DMA_ERROR_STATUS5_DMA_ADDR_MISMATCH_WR_BUFFER_MASK)

#define DSPSS_DMA_ERROR_STATUS5_DMA_ADDR_MISMATCH_RD_BUFFER_MASK (0x2U)
#define DSPSS_DMA_ERROR_STATUS5_DMA_ADDR_MISMATCH_RD_BUFFER_SHIFT (1U)
#define DSPSS_DMA_ERROR_STATUS5_DMA_ADDR_MISMATCH_RD_BUFFER_WIDTH (1U)
#define DSPSS_DMA_ERROR_STATUS5_DMA_ADDR_MISMATCH_RD_BUFFER(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DMA_ERROR_STATUS5_DMA_ADDR_MISMATCH_RD_BUFFER_SHIFT)) & DSPSS_DMA_ERROR_STATUS5_DMA_ADDR_MISMATCH_RD_BUFFER_MASK)

#define DSPSS_DMA_ERROR_STATUS5_DMA_XFR_ERR_WRITE_MASK (0x4U)
#define DSPSS_DMA_ERROR_STATUS5_DMA_XFR_ERR_WRITE_SHIFT (2U)
#define DSPSS_DMA_ERROR_STATUS5_DMA_XFR_ERR_WRITE_WIDTH (1U)
#define DSPSS_DMA_ERROR_STATUS5_DMA_XFR_ERR_WRITE(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DMA_ERROR_STATUS5_DMA_XFR_ERR_WRITE_SHIFT)) & DSPSS_DMA_ERROR_STATUS5_DMA_XFR_ERR_WRITE_MASK)

#define DSPSS_DMA_ERROR_STATUS5_DMA_XFR_ERR_READ_MASK (0x8U)
#define DSPSS_DMA_ERROR_STATUS5_DMA_XFR_ERR_READ_SHIFT (3U)
#define DSPSS_DMA_ERROR_STATUS5_DMA_XFR_ERR_READ_WIDTH (1U)
#define DSPSS_DMA_ERROR_STATUS5_DMA_XFR_ERR_READ(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DMA_ERROR_STATUS5_DMA_XFR_ERR_READ_SHIFT)) & DSPSS_DMA_ERROR_STATUS5_DMA_XFR_ERR_READ_MASK)
/*! @} */

/*! @name DMA_WRITE_ADDR5 - Reference DMA Write Region */
/*! @{ */

#define DSPSS_DMA_WRITE_ADDR5_DMA_WRITE_START_ADDR_MASK (0x3FFFU)
#define DSPSS_DMA_WRITE_ADDR5_DMA_WRITE_START_ADDR_SHIFT (0U)
#define DSPSS_DMA_WRITE_ADDR5_DMA_WRITE_START_ADDR_WIDTH (14U)
#define DSPSS_DMA_WRITE_ADDR5_DMA_WRITE_START_ADDR(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DMA_WRITE_ADDR5_DMA_WRITE_START_ADDR_SHIFT)) & DSPSS_DMA_WRITE_ADDR5_DMA_WRITE_START_ADDR_MASK)

#define DSPSS_DMA_WRITE_ADDR5_DMA_WRITE_END_ADDR_MASK (0xFFFC0000U)
#define DSPSS_DMA_WRITE_ADDR5_DMA_WRITE_END_ADDR_SHIFT (18U)
#define DSPSS_DMA_WRITE_ADDR5_DMA_WRITE_END_ADDR_WIDTH (14U)
#define DSPSS_DMA_WRITE_ADDR5_DMA_WRITE_END_ADDR(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DMA_WRITE_ADDR5_DMA_WRITE_END_ADDR_SHIFT)) & DSPSS_DMA_WRITE_ADDR5_DMA_WRITE_END_ADDR_MASK)
/*! @} */

/*! @name DMA_CURR_WR_PTR5 - DMA Current Write Pointer */
/*! @{ */

#define DSPSS_DMA_CURR_WR_PTR5_DMA_CURR_WRITE_PTR_MASK (0x3FFFU)
#define DSPSS_DMA_CURR_WR_PTR5_DMA_CURR_WRITE_PTR_SHIFT (0U)
#define DSPSS_DMA_CURR_WR_PTR5_DMA_CURR_WRITE_PTR_WIDTH (14U)
#define DSPSS_DMA_CURR_WR_PTR5_DMA_CURR_WRITE_PTR(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DMA_CURR_WR_PTR5_DMA_CURR_WRITE_PTR_SHIFT)) & DSPSS_DMA_CURR_WR_PTR5_DMA_CURR_WRITE_PTR_MASK)

#define DSPSS_DMA_CURR_WR_PTR5_DMA_WRITE_PTR_WRAP_MASK (0x80000000U)
#define DSPSS_DMA_CURR_WR_PTR5_DMA_WRITE_PTR_WRAP_SHIFT (31U)
#define DSPSS_DMA_CURR_WR_PTR5_DMA_WRITE_PTR_WRAP_WIDTH (1U)
#define DSPSS_DMA_CURR_WR_PTR5_DMA_WRITE_PTR_WRAP(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DMA_CURR_WR_PTR5_DMA_WRITE_PTR_WRAP_SHIFT)) & DSPSS_DMA_CURR_WR_PTR5_DMA_WRITE_PTR_WRAP_MASK)
/*! @} */

/*! @name DMA_CURR_RD_PTR5 - DMA Current Read Pointer */
/*! @{ */

#define DSPSS_DMA_CURR_RD_PTR5_DMA_CURR_READ_PTR_MASK (0x3FFFU)
#define DSPSS_DMA_CURR_RD_PTR5_DMA_CURR_READ_PTR_SHIFT (0U)
#define DSPSS_DMA_CURR_RD_PTR5_DMA_CURR_READ_PTR_WIDTH (14U)
#define DSPSS_DMA_CURR_RD_PTR5_DMA_CURR_READ_PTR(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DMA_CURR_RD_PTR5_DMA_CURR_READ_PTR_SHIFT)) & DSPSS_DMA_CURR_RD_PTR5_DMA_CURR_READ_PTR_MASK)

#define DSPSS_DMA_CURR_RD_PTR5_DMA_READ_PTR_WRAP_MASK (0x80000000U)
#define DSPSS_DMA_CURR_RD_PTR5_DMA_READ_PTR_WRAP_SHIFT (31U)
#define DSPSS_DMA_CURR_RD_PTR5_DMA_READ_PTR_WRAP_WIDTH (1U)
#define DSPSS_DMA_CURR_RD_PTR5_DMA_READ_PTR_WRAP(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DMA_CURR_RD_PTR5_DMA_READ_PTR_WRAP_SHIFT)) & DSPSS_DMA_CURR_RD_PTR5_DMA_READ_PTR_WRAP_MASK)
/*! @} */

/*! @name DSP_TO_DMA_REQUEST_STATUS5 - DMA Request Status */
/*! @{ */

#define DSPSS_DSP_TO_DMA_REQUEST_STATUS5_DSP_TO_DMA_REQUEST_STATUS_MASK (0x1U)
#define DSPSS_DSP_TO_DMA_REQUEST_STATUS5_DSP_TO_DMA_REQUEST_STATUS_SHIFT (0U)
#define DSPSS_DSP_TO_DMA_REQUEST_STATUS5_DSP_TO_DMA_REQUEST_STATUS_WIDTH (1U)
#define DSPSS_DSP_TO_DMA_REQUEST_STATUS5_DSP_TO_DMA_REQUEST_STATUS(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSP_TO_DMA_REQUEST_STATUS5_DSP_TO_DMA_REQUEST_STATUS_SHIFT)) & DSPSS_DSP_TO_DMA_REQUEST_STATUS5_DSP_TO_DMA_REQUEST_STATUS_MASK)

#define DSPSS_DSP_TO_DMA_REQUEST_STATUS5_DMA_TO_DSP_ACK_STATUS_MASK (0x2U)
#define DSPSS_DSP_TO_DMA_REQUEST_STATUS5_DMA_TO_DSP_ACK_STATUS_SHIFT (1U)
#define DSPSS_DSP_TO_DMA_REQUEST_STATUS5_DMA_TO_DSP_ACK_STATUS_WIDTH (1U)
#define DSPSS_DSP_TO_DMA_REQUEST_STATUS5_DMA_TO_DSP_ACK_STATUS(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSP_TO_DMA_REQUEST_STATUS5_DMA_TO_DSP_ACK_STATUS_SHIFT)) & DSPSS_DSP_TO_DMA_REQUEST_STATUS5_DMA_TO_DSP_ACK_STATUS_MASK)
/*! @} */

/*! @name HW_CTRL_DMA_REQ_STOP5 - Stop DMA Request */
/*! @{ */

#define DSPSS_HW_CTRL_DMA_REQ_STOP5_STOP_MASK    (0x1U)
#define DSPSS_HW_CTRL_DMA_REQ_STOP5_STOP_SHIFT   (0U)
#define DSPSS_HW_CTRL_DMA_REQ_STOP5_STOP_WIDTH   (1U)
#define DSPSS_HW_CTRL_DMA_REQ_STOP5_STOP(x)      (((uint32_t)(((uint32_t)(x)) << DSPSS_HW_CTRL_DMA_REQ_STOP5_STOP_SHIFT)) & DSPSS_HW_CTRL_DMA_REQ_STOP5_STOP_MASK)
/*! @} */

/*! @name DMA_ERROR_CTRL5 - DMA Error Control */
/*! @{ */

#define DSPSS_DMA_ERROR_CTRL5_DONE_MASK          (0x1U)
#define DSPSS_DMA_ERROR_CTRL5_DONE_SHIFT         (0U)
#define DSPSS_DMA_ERROR_CTRL5_DONE_WIDTH         (1U)
#define DSPSS_DMA_ERROR_CTRL5_DONE(x)            (((uint32_t)(((uint32_t)(x)) << DSPSS_DMA_ERROR_CTRL5_DONE_SHIFT)) & DSPSS_DMA_ERROR_CTRL5_DONE_MASK)
/*! @} */

/*! @name HW_CTRL_DMA_REQ_RESPONSE5 - Hardware Control Handling for DMA Request And Response */
/*! @{ */

#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE5_START_MASK (0x1U)
#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE5_START_SHIFT (0U)
#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE5_START_WIDTH (1U)
#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE5_START(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_HW_CTRL_DMA_REQ_RESPONSE5_START_SHIFT)) & DSPSS_HW_CTRL_DMA_REQ_RESPONSE5_START_MASK)

#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE5_NUM_OF_DMA_REQ_MASK (0x1FEU)
#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE5_NUM_OF_DMA_REQ_SHIFT (1U)
#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE5_NUM_OF_DMA_REQ_WIDTH (8U)
#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE5_NUM_OF_DMA_REQ(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_HW_CTRL_DMA_REQ_RESPONSE5_NUM_OF_DMA_REQ_SHIFT)) & DSPSS_HW_CTRL_DMA_REQ_RESPONSE5_NUM_OF_DMA_REQ_MASK)

#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE5_DONE_MASK (0x200U)
#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE5_DONE_SHIFT (9U)
#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE5_DONE_WIDTH (1U)
#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE5_DONE(x)  (((uint32_t)(((uint32_t)(x)) << DSPSS_HW_CTRL_DMA_REQ_RESPONSE5_DONE_SHIFT)) & DSPSS_HW_CTRL_DMA_REQ_RESPONSE5_DONE_MASK)

#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE5_NUM_OF_DMA_REQ_PEND_MASK (0x3FC00U)
#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE5_NUM_OF_DMA_REQ_PEND_SHIFT (10U)
#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE5_NUM_OF_DMA_REQ_PEND_WIDTH (8U)
#define DSPSS_HW_CTRL_DMA_REQ_RESPONSE5_NUM_OF_DMA_REQ_PEND(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_HW_CTRL_DMA_REQ_RESPONSE5_NUM_OF_DMA_REQ_PEND_SHIFT)) & DSPSS_HW_CTRL_DMA_REQ_RESPONSE5_NUM_OF_DMA_REQ_PEND_MASK)
/*! @} */

/*! @name DSPSS_DSP_THREAD_INFO - Thread Status Info 0..Thread Status Info 3 */
/*! @{ */

#define DSPSS_DSPSS_DSP_THREAD_INFO_SDADC_XMEM_CURR_WR_PTR_MASK (0x3FFFU)
#define DSPSS_DSPSS_DSP_THREAD_INFO_SDADC_XMEM_CURR_WR_PTR_SHIFT (0U)
#define DSPSS_DSPSS_DSP_THREAD_INFO_SDADC_XMEM_CURR_WR_PTR_WIDTH (14U)
#define DSPSS_DSPSS_DSP_THREAD_INFO_SDADC_XMEM_CURR_WR_PTR(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSPSS_DSP_THREAD_INFO_SDADC_XMEM_CURR_WR_PTR_SHIFT)) & DSPSS_DSPSS_DSP_THREAD_INFO_SDADC_XMEM_CURR_WR_PTR_MASK)

#define DSPSS_DSPSS_DSP_THREAD_INFO_WRAP_COUNT_MASK (0xC000U)
#define DSPSS_DSPSS_DSP_THREAD_INFO_WRAP_COUNT_SHIFT (14U)
#define DSPSS_DSPSS_DSP_THREAD_INFO_WRAP_COUNT_WIDTH (2U)
#define DSPSS_DSPSS_DSP_THREAD_INFO_WRAP_COUNT(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSPSS_DSP_THREAD_INFO_WRAP_COUNT_SHIFT)) & DSPSS_DSPSS_DSP_THREAD_INFO_WRAP_COUNT_MASK)

#define DSPSS_DSPSS_DSP_THREAD_INFO_CURR_FSM_STATE_MASK (0x3FF0000U)
#define DSPSS_DSPSS_DSP_THREAD_INFO_CURR_FSM_STATE_SHIFT (16U)
#define DSPSS_DSPSS_DSP_THREAD_INFO_CURR_FSM_STATE_WIDTH (10U)
#define DSPSS_DSPSS_DSP_THREAD_INFO_CURR_FSM_STATE(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSPSS_DSP_THREAD_INFO_CURR_FSM_STATE_SHIFT)) & DSPSS_DSPSS_DSP_THREAD_INFO_CURR_FSM_STATE_MASK)

#define DSPSS_DSPSS_DSP_THREAD_INFO_NUM_THREADS_IN_ACC_FIFO_MASK (0x3C000000U)
#define DSPSS_DSPSS_DSP_THREAD_INFO_NUM_THREADS_IN_ACC_FIFO_SHIFT (26U)
#define DSPSS_DSPSS_DSP_THREAD_INFO_NUM_THREADS_IN_ACC_FIFO_WIDTH (4U)
#define DSPSS_DSPSS_DSP_THREAD_INFO_NUM_THREADS_IN_ACC_FIFO(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSPSS_DSP_THREAD_INFO_NUM_THREADS_IN_ACC_FIFO_SHIFT)) & DSPSS_DSPSS_DSP_THREAD_INFO_NUM_THREADS_IN_ACC_FIFO_MASK)

#define DSPSS_DSPSS_DSP_THREAD_INFO_THREAD_ACC_FIFO_FULL_MASK (0x40000000U)
#define DSPSS_DSPSS_DSP_THREAD_INFO_THREAD_ACC_FIFO_FULL_SHIFT (30U)
#define DSPSS_DSPSS_DSP_THREAD_INFO_THREAD_ACC_FIFO_FULL_WIDTH (1U)
#define DSPSS_DSPSS_DSP_THREAD_INFO_THREAD_ACC_FIFO_FULL(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSPSS_DSP_THREAD_INFO_THREAD_ACC_FIFO_FULL_SHIFT)) & DSPSS_DSPSS_DSP_THREAD_INFO_THREAD_ACC_FIFO_FULL_MASK)

#define DSPSS_DSPSS_DSP_THREAD_INFO_THREAD_ACC_FIFO_OVF_MASK (0x80000000U)
#define DSPSS_DSPSS_DSP_THREAD_INFO_THREAD_ACC_FIFO_OVF_SHIFT (31U)
#define DSPSS_DSPSS_DSP_THREAD_INFO_THREAD_ACC_FIFO_OVF_WIDTH (1U)
#define DSPSS_DSPSS_DSP_THREAD_INFO_THREAD_ACC_FIFO_OVF(x) (((uint32_t)(((uint32_t)(x)) << DSPSS_DSPSS_DSP_THREAD_INFO_THREAD_ACC_FIFO_OVF_SHIFT)) & DSPSS_DSPSS_DSP_THREAD_INFO_THREAD_ACC_FIFO_OVF_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group DSPSS_Register_Masks */

/*!
 * @}
 */ /* end of group DSPSS_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K39_DSPSS_H_) */
