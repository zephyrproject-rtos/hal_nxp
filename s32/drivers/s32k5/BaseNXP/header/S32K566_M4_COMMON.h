/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K566.h
 * @version 2.2
 * @date 2025-10-16
 * @brief Peripheral Access Layer for S32K566
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


/* ----------------------------------------------------------------------------
   -- MCU activation
   ---------------------------------------------------------------------------- */

/* Prevention from multiple including the same memory map */
#if !defined(S32K566_M4_COMMON_H_)  /* Check if memory map has not been already included */
#define S32K566_M4_COMMON_H_
#define MCU_S32K566

/* Check if another memory map has not been also included */
#if (defined(MCU_ACTIVE))
  #error S32K566 memory map: There is already included another memory map. Only one memory map can be included.
#endif /* (defined(MCU_ACTIVE)) */
#define MCU_ACTIVE

#include <stdint.h>

/** Memory map major version (memory maps with equal major version number are
 * compatible) */
#define MCU_MEM_MAP_VERSION 0x0200U
/** Memory map minor version */
#define MCU_MEM_MAP_VERSION_MINOR 0x0002U

/* ----------------------------------------------------------------------------
   -- Generic macros
   ---------------------------------------------------------------------------- */

/* IO definitions (access restrictions to peripheral registers) */
/**
*   IO Type Qualifiers are used
*   \li to specify the access to peripheral variables.
*   \li for automatic generation of peripheral register debug information.
*/
#ifndef __IO
#ifdef __cplusplus
  #define   __I     volatile             /*!< Defines 'read only' permissions                 */
#else
  #define   __I     volatile const       /*!< Defines 'read only' permissions                 */
#endif
#define     __O     volatile             /*!< Defines 'write only' permissions                */
#define     __IO    volatile             /*!< Defines 'read / write' permissions              */
#endif


/**
* @brief 32 bits memory read macro.
*/
#if !defined(REG_READ32)
  #define REG_READ32(address)               (*(volatile uint32_t*)(address))
#endif

/**
* @brief 32 bits memory write macro.
*/
#if !defined(REG_WRITE32)
  #define REG_WRITE32(address, value)       ((*(volatile uint32_t*)(address))= (uint32_t)(value))
#endif

/**
* @brief 32 bits bits setting macro.
*/
#if !defined(REG_BIT_SET32)
  #define REG_BIT_SET32(address, mask)      ((*(volatile uint32_t*)(address))|= (uint32_t)(mask))
#endif

/**
* @brief 32 bits bits clearing macro.
*/
#if !defined(REG_BIT_CLEAR32)
  #define REG_BIT_CLEAR32(address, mask)    ((*(volatile uint32_t*)(address))&= ((uint32_t)~((uint32_t)(mask))))
#endif

/**
* @brief 32 bit clear bits and set with new value
* @note It is user's responsability to make sure that value has only "mask" bits set - (value&~mask)==0
*/
#if !defined(REG_RMW32)
  #define REG_RMW32(address, mask, value)   (REG_WRITE32((address), ((REG_READ32(address)& ((uint32_t)~((uint32_t)(mask))))| ((uint32_t)(value)))))
#endif


/* ----------------------------------------------------------------------------
   -- Interrupt vector numbers
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Interrupt_vector_numbers Interrupt vector numbers
 * @{
 */

/** Interrupt Number Definitions */
#define NUMBER_OF_INT_VECTORS 254                /**< Number of interrupts in the Vector table */

typedef enum {
  /* Auxiliary constants */
  NotAvail_IRQn                = -128,             /**< Not available device specific interrupt */

  /* Core interrupts */
  NonMaskableInt_IRQn          = -14,              /**< Non Maskable Interrupt */
  HardFault_IRQn               = -13,              /**< Cortex-M4 SV Hard Fault Interrupt */
  MemoryManagement_IRQn        = -12,              /**< Cortex-M4 Memory Management Interrupt */
  BusFault_IRQn                = -11,              /**< Cortex-M4 Bus Fault Interrupt */
  UsageFault_IRQn              = -10,              /**< Cortex-M4 Usage Fault Interrupt */
  SVCall_IRQn                  = -5,               /**< Cortex-M4 SV Call Interrupt */
  DebugMonitor_IRQn            = -4,               /**< Cortex-M4 Debug Monitor Interrupt */
  PendSV_IRQn                  = -2,               /**< Cortex-M4 Pend SV Interrupt */
  SysTick_IRQn                 = -1,               /**< Cortex-M4 System Tick Interrupt */

  /* Device specific interrupts */
  CM4_CTI_INT0_1_IRQn          = 0,                /**< Per core: DWT comparator output 0/Per core: DWT comparator output 1 */
  CM4_DSP_INT0_IRQn            = 1,                /**< ORed requests to MU0 */
  CM4_DSP_INT1_IRQn            = 2,                /**< ORed requests to MU1 */
  CM4_DSP_INT2_IRQn            = 3,                /**< ORed requests to MU2 */
  CM4_DSP_INT3_IRQn            = 4,                /**< ORed requests to MU3 */
  CM4_XRDC_A_C_INT_IRQn        = 21,               /**< Transfer error/Transfer error/Transfer error */
  CM4_MRAMC_INT_IRQn           = 25,               /**< AXI bufferable write error */
  CM4_NEUTRON_ACCEL_INT0_1_IRQn = 26,              /**< Functional/Fault */
  CM4_SWT_STARTUP_INT_IRQn     = 27,               /**< Initial time-out */
  CM4_SIUL2_0_INT_IRQn         = 29,               /**< Vector 0 */
  CM4_SIUL2_1_INT_IRQn         = 30,               /**< Vector 0 */
  CM4_SIUL2_3_INT_IRQn         = 31,               /**< Vector 0 */
  CM4_SIUL2_4_INT_IRQn         = 32,               /**< Vector 0 */
  CM4_CSTCU_INT_IRQn           = 36,               /**< Self-test complete */
  CM4_VFCCU_INT0_IRQn          = 37,               /**< Per core: Central FCCU reaction 0 */
  CM4_VFCCU_INT8_IRQn          = 38,               /**< Central FCCU reaction index0 */
  CM4_VFCCU_INT9_IRQn          = 39,               /**< Central FCCU reaction index1 */
  CM4_ERM0_INT0_1_IRQn         = 41,               /**< Single-bit correctable event/Multi-bit uncorrectable error event */
  CM4_ERM1_INT0_1_IRQn         = 42,               /**< Single-bit correctable event/Multi-bit uncorrectable error event */
  CM4_ERM2_INT0_1_IRQn         = 43,               /**< Single-bit correctable event/Multi-bit uncorrectable error event */
  CM4_ERM3_INT0_1_IRQn         = 44,               /**< Single-bit correctable event/Multi-bit uncorrectable error event */
  CM4_ERM4_INT0_1_IRQn         = 45,               /**< Single-bit correctable event/Multi-bit uncorrectable error event */
  CM4_ERM5_INT0_1_IRQn         = 46,               /**< Single-bit correctable event/Multi-bit uncorrectable error event */
  CM4_AES_ACCEL_INT0_2_IRQn    = 47,               /**< Application 0/Application 0 timeout/Application 0 keystore error */
  CM4_AES_ACCEL_INT3_5_IRQn    = 48,               /**< Application 1/Application 1 timeout/Application 1 keystore error */
  CM4_AES_ACCEL_INT6_8_IRQn    = 49,               /**< Application 2/Application 2 timeout/Application 2 keystore error */
  CM4_AES_ACCEL_INT9_11_IRQn   = 50,               /**< Application 3/Application 3 timeout/Application 3 keystore error */
  CM4_AES_ACCEL_INT12_14_IRQn  = 51,               /**< Application 4/Application 4 timeout/Application 4 keystore error */
  CM4_AES_ACCEL_INT15_17_IRQn  = 52,               /**< Application 5/Application 5 timeout/Application 5 keystore error */
  CM4_AES_ACCEL_INT18_20_IRQn  = 53,               /**< Application 6/Application 6 timeout/Application 6 keystore error */
  CM4_AES_ACCEL_INT21_23_IRQn  = 54,               /**< Application 7/Application 7 timeout/Application 7 keystore error */
  CM4_AES_ACCEL_INT24_25_IRQn  = 55,               /**< Feed DMA error/Result DMA error */
  CM4_SENTMU2_INT0_2_IRQn      = 58,               /**< ORed TX request to MU2A/ORed RX request to MU2A/ORed general purpose request to MU2A */
  CM4_SINC_INT0_3_IRQn         = 92,               /**< Channel 0/Channel 1/Channel 2/Channel 3 */
  CM4_CANXL0_INT0_20_IRQn      = 97,               /**< CAN frame transmission from one of the Tx message buffers 0-31 completed/CAN frame transmission from one of the Tx message buffers 32-63 completed/CAN frame reception into one of the Rx message buffers 0-31 completed/CAN frame reception into one of the Rx message buffers 32-63 completed/The Rx FIFO used for reception of selected CAN frames has reached its programmable threshold/The Rx FIFO used for reception of selected CAN frames has experienced underflow or overflow/Message Receive Unit/Protocol engine error occurred related to reception or transmission of CAN frames/Receive Error Counter Interrupt/Transmit Error Counter Interrupt/Bus Off Recovery Ready Interrupt/Bus Off Interrupt/Protocol Exception Error Interrupt/Passive Error State Interrupt/Frame error during arbitration/data phase 1/Frame error during arbitration/data phase 2/Frame error during arbitration/data phase 3/Internal exception is detected/Non-correctable error occurred within internal data RAM/Correctable error occurred within internal data RAM/IP has entered or exited freeze mode */
  CM4_FLEXCAN0_INT0_8_IRQn     = 106,              /**< CAN bus went to Bus Off state/CAN has completed the Bus Off count process (it has counted 11 recessive bits 128 times) and is ready for bus off recover/Errors detected on the CAN bus/Errors detected on the CAN bus for FD messages in the Fast Bit Rate region/Transmit Error Counter transition from < 96 to >= 96/Receive Error Counter transition from < 96 to >= 96/Correctable error detected in memory read access/Non-correctable error detected in memory read access by host (cpu)/Non-correctable error detected in memory read access by CAN */
  CM4_FLEXCAN0_INT9_15_IRQn    = 107,              /**< The number of messages stored in FIFO is greater than the FIFO watermarker/At least one message stored in FIFO/An underflow occurs in the FIFO/An overflow occurs in the FIFO/All Message Buffers */
  CM4_FLEXCAN1_INT0_8_IRQn     = 108,              /**< CAN bus went to Bus Off state/CAN has completed the Bus Off count process (it has counted 11 recessive bits 128 times) and is ready for bus off recover/Errors detected on the CAN bus/Errors detected on the CAN bus for FD messages in the Fast Bit Rate region/Transmit Error Counter transition from < 96 to >= 96/Receive Error Counter transition from < 96 to >= 96/Correctable error detected in memory read access/Non-correctable error detected in memory read access by host (cpu)/Non-correctable error detected in memory read access by CAN */
  CM4_FLEXCAN1_INT9_15_IRQn    = 109,              /**< The number of messages stored in FIFO is greater than the FIFO watermarker/At least one message stored in FIFO/An underflow occurs in the FIFO/An overflow occurs in the FIFO/All Message Buffers */
  CM4_FLEXCAN2_INT0_8_IRQn     = 110,              /**< CAN bus went to Bus Off state/CAN has completed the Bus Off count process (it has counted 11 recessive bits 128 times) and is ready for bus off recover/Errors detected on the CAN bus/Errors detected on the CAN bus for FD messages in the Fast Bit Rate region/Transmit Error Counter transition from < 96 to >= 96/Receive Error Counter transition from < 96 to >= 96/Correctable error detected in memory read access/Non-correctable error detected in memory read access by host (cpu)/Non-correctable error detected in memory read access by CAN */
  CM4_FLEXCAN2_INT9_15_IRQn    = 111,              /**< The number of messages stored in FIFO is greater than the FIFO watermarker/At least one message stored in FIFO/An underflow occurs in the FIFO/An overflow occurs in the FIFO/All Message Buffers */
  CM4_FLEXCAN3_INT0_8_IRQn     = 112,              /**< CAN bus went to Bus Off state/CAN has completed the Bus Off count process (it has counted 11 recessive bits 128 times) and is ready for bus off recover/Errors detected on the CAN bus/Errors detected on the CAN bus for FD messages in the Fast Bit Rate region/Transmit Error Counter transition from < 96 to >= 96/Receive Error Counter transition from < 96 to >= 96/Correctable error detected in memory read access/Non-correctable error detected in memory read access by host (cpu)/Non-correctable error detected in memory read access by CAN */
  CM4_FLEXCAN3_INT9_15_IRQn    = 113,              /**< The number of messages stored in FIFO is greater than the FIFO watermarker/At least one message stored in FIFO/An underflow occurs in the FIFO/An overflow occurs in the FIFO/All Message Buffers */
  CM4_FLEXCAN4_INT0_8_IRQn     = 114,              /**< CAN bus went to Bus Off state/CAN has completed the Bus Off count process (it has counted 11 recessive bits 128 times) and is ready for bus off recover/Errors detected on the CAN bus/Errors detected on the CAN bus for FD messages in the Fast Bit Rate region/Transmit Error Counter transition from < 96 to >= 96/Receive Error Counter transition from < 96 to >= 96/Correctable error detected in memory read access/Non-correctable error detected in memory read access by host (cpu)/Non-correctable error detected in memory read access by CAN */
  CM4_FLEXCAN4_INT9_15_IRQn    = 115,              /**< The number of messages stored in FIFO is greater than the FIFO watermarker/At least one message stored in FIFO/An underflow occurs in the FIFO/An overflow occurs in the FIFO/All Message Buffers */
  CM4_FLEXCAN5_INT0_8_IRQn     = 116,              /**< CAN bus went to Bus Off state/CAN has completed the Bus Off count process (it has counted 11 recessive bits 128 times) and is ready for bus off recover/Errors detected on the CAN bus/Errors detected on the CAN bus for FD messages in the Fast Bit Rate region/Transmit Error Counter transition from < 96 to >= 96/Receive Error Counter transition from < 96 to >= 96/Correctable error detected in memory read access/Non-correctable error detected in memory read access by host (cpu)/Non-correctable error detected in memory read access by CAN */
  CM4_FLEXCAN5_INT9_15_IRQn    = 117,              /**< The number of messages stored in FIFO is greater than the FIFO watermarker/At least one message stored in FIFO/An underflow occurs in the FIFO/An overflow occurs in the FIFO/All Message Buffers */
  CM4_FLEXCAN6_INT0_8_IRQn     = 118,              /**< CAN bus went to Bus Off state/CAN has completed the Bus Off count process (it has counted 11 recessive bits 128 times) and is ready for bus off recover/Errors detected on the CAN bus/Errors detected on the CAN bus for FD messages in the Fast Bit Rate region/Transmit Error Counter transition from < 96 to >= 96/Receive Error Counter transition from < 96 to >= 96/Correctable error detected in memory read access/Non-correctable error detected in memory read access by host (cpu)/Non-correctable error detected in memory read access by CAN */
  CM4_FLEXCAN6_INT9_15_IRQn    = 119,              /**< The number of messages stored in FIFO is greater than the FIFO watermarker/At least one message stored in FIFO/An underflow occurs in the FIFO/An overflow occurs in the FIFO/All Message Buffers */
  CM4_FLEXCAN7_INT0_8_IRQn     = 120,              /**< CAN bus went to Bus Off state/CAN has completed the Bus Off count process (it has counted 11 recessive bits 128 times) and is ready for bus off recover/Errors detected on the CAN bus/Errors detected on the CAN bus for FD messages in the Fast Bit Rate region/Transmit Error Counter transition from < 96 to >= 96/Receive Error Counter transition from < 96 to >= 96/Correctable error detected in memory read access/Non-correctable error detected in memory read access by host (cpu)/Non-correctable error detected in memory read access by CAN */
  CM4_FLEXCAN7_INT9_15_IRQn    = 121,              /**< The number of messages stored in FIFO is greater than the FIFO watermarker/At least one message stored in FIFO/An underflow occurs in the FIFO/An overflow occurs in the FIFO/All Message Buffers */
  CM4_FLEXCAN8_INT0_8_IRQn     = 122,              /**< CAN bus went to Bus Off state/CAN has completed the Bus Off count process (it has counted 11 recessive bits 128 times) and is ready for bus off recover/Errors detected on the CAN bus/Errors detected on the CAN bus for FD messages in the Fast Bit Rate region/Transmit Error Counter transition from < 96 to >= 96/Receive Error Counter transition from < 96 to >= 96/Correctable error detected in memory read access/Non-correctable error detected in memory read access by host (cpu)/Non-correctable error detected in memory read access by CAN */
  CM4_FLEXCAN8_INT9_15_IRQn    = 123,              /**< The number of messages stored in FIFO is greater than the FIFO watermarker/At least one message stored in FIFO/An underflow occurs in the FIFO/An overflow occurs in the FIFO/All Message Buffers */
  CM4_FLEXIO0_INT_IRQn         = 140,              /**< FlexIO */
  CM4_FLEXIO1_INT_IRQn         = 141,              /**< FlexIO */
  CM4_LPUART0_INT0_1_IRQn      = 155,              /**< Transmit data and errors/Receive data and errors */
  CM4_LPUART1_INT0_1_IRQn      = 156,              /**< Transmit data and errors/Receive data and errors */
  CM4_LPUART2_INT0_1_IRQn      = 157,              /**< Transmit data and errors/Receive data and errors */
  CM4_LPUART3_INT0_1_IRQn      = 158,              /**< Transmit data and errors/Receive data and errors */
  CM4_LPUART4_INT0_1_IRQn      = 159,              /**< Transmit data and errors/Receive data and errors */
  CM4_LPUART5_INT0_1_IRQn      = 160,              /**< Transmit data and errors/Receive data and errors */
  CM4_LPUART6_INT0_1_IRQn      = 161,              /**< Transmit data and errors/Receive data and errors */
  CM4_LPUART7_INT0_1_IRQn      = 162,              /**< Transmit data and errors/Receive data and errors */
  CM4_LPUART8_INT0_1_IRQn      = 163,              /**< Transmit data and errors/Receive data and errors */
  CM4_LPUART9_INT0_1_IRQn      = 164,              /**< Transmit data and errors/Receive data and errors */
  CM4_LPUART10_INT0_1_IRQn     = 165,              /**< Transmit data and errors/Receive data and errors */
  CM4_LPUART11_INT0_1_IRQn     = 166,              /**< Transmit data and errors/Receive data and errors */
  CM4_LPUART12_INT0_1_IRQn     = 167,              /**< Transmit data and errors/Receive data and errors */
  CM4_MSGINTR0_INT0_2_IRQn     = 178,              /**< Message signaled interrupt register 0/Message signaled interrupt register 1/Message signaled interrupt register 2 */
  CM4_MSGINTR1_INT0_2_IRQn     = 179,              /**< Message signaled interrupt register 0/Message signaled interrupt register 1/Message signaled interrupt register 2 */
  CM4_MSGINTR2_INT0_2_IRQn     = 180,              /**< Message signaled interrupt register 0/Message signaled interrupt register 1/Message signaled interrupt register 2 */
  CM4_MSGINTR3_INT0_2_IRQn     = 181,              /**< Message signaled interrupt register 0/Message signaled interrupt register 1/Message signaled interrupt register 2 */
  CM4_MSGINTR4_INT0_2_IRQn     = 182,              /**< Message signaled interrupt register 0/Message signaled interrupt register 1/Message signaled interrupt register 2 */
  CM4_MSGINTR5_INT0_2_IRQn     = 183,              /**< Message signaled interrupt register 0/Message signaled interrupt register 1/Message signaled interrupt register 2 */
  CM4_MSGINTR6_INT0_2_IRQn     = 184,              /**< Message signaled interrupt register 0/Message signaled interrupt register 1/Message signaled interrupt register 2 */
  CM4_NETC_IEPRC_INT0_1_IRQn   = 186,              /**< NETC Root Complex PCI 0/NETC Root Complex PCI 1 */
  CM4_RXLUT_INT_IRQn           = 191,              /**< RXLUT */
  CM4_LPE_eDMA3_TCD0_1_INT_IRQn = 199,             /**< DMA transfer complete and error channel 0/DMA transfer complete and error channel 1 */
  CM4_LPE_eDMA3_TCD2_3_INT_IRQn = 200,             /**< DMA transfer complete and error channel 2/DMA transfer complete and error channel 3 */
  CM4_LPE_eDMA3_TCD4_5_INT_IRQn = 201,             /**< DMA transfer complete and error channel 4/DMA transfer complete and error channel 5 */
  CM4_LPE_eDMA3_TCD6_7_INT_IRQn = 202,             /**< DMA transfer complete and error channel 6/DMA transfer complete and error channel 7 */
  CM4_LPE_eDMA3_TCD8_9_INT_IRQn = 203,             /**< DMA transfer complete and error channel 8/DMA transfer complete and error channel 9 */
  CM4_LPE_eDMA3_TCD10_11_INT_IRQn = 204,           /**< DMA transfer complete and error channel 10/DMA transfer complete and error channel 11 */
  CM4_LPE_XRDC_INT_IRQn        = 205,              /**< Transfer error */
  CM4_LPE_MRU_INT0_4_IRQn      = 206,              /**< Per core: Notification channel 0/Per core: Notification channel 1/Per core: Notification channel 2/Per core: Notification channel 3/Channel reset */
  CM4_LPE_MCM_INT_IRQn         = 207,              /**< Per core: FPU sources */
  CM4_LPE_PMC_INT0_3_IRQn      = 208,              /**< Low-voltage detect on VDD_LVDS < 1.7V (LVDLVDSF flag)/Low-voltage detect VDD_HV_B < 3.0V (LVDB33F flag) and VDD_HV_B < 1.7V (LVDB18F flag)/High-voltage detect > x.xV (HVDxF flags) */
  CM4_LPE_MC_RGM_INT_IRQn      = 209,              /**< RGM */
  CM4_LPE_SWT_INT_IRQn         = 210,              /**< Initial time-out */
  CM4_LPE_SIUL2_INT_IRQn       = 211,              /**< Vector 0 */
  CM4_LPE_WKPU_INT0_8_IRQn     = 212,              /**< Group 0/Group 1/Group 2/Group 3/Group 4/Group 5/Group 6/Group 7/Group 8 */
  CM4_LPE_WKPU_INT9_IRQn       = 213,              /**< Per core: Active low non-maskable request 0 */
  CM4_LPE_CXPI0_INT_IRQn       = 214,              /**< ORed arbitration loss, dominant timeout, wakeup pulse reception */
  CM4_LPE_CXPI1_INT_IRQn       = 215,              /**< ORed arbitration loss, dominant timeout, wakeup pulse reception */
  CM4_LPE_ERM_INT0_1_IRQn      = 216,              /**< Single-bit correctable event/Multi-bit uncorrectable error event */
  CM4_LPE_SARADC_INT0_2_IRQn   = 217,              /**< End of conversion/Error/Analog watchdog */
  CM4_LPE_LPCMP0_INT_IRQn      = 218,              /**< Asynchronous */
  CM4_LPE_LPCMP1_INT_IRQn      = 219,              /**< Asynchronous */
  CM4_LPE_LPCMP2_INT_IRQn      = 220,              /**< Asynchronous */
  CM4_LPE_TEMPSENSE_INT0_3_IRQn = 221,             /**< Data ready 0/Comparator threshold 0/Comparator threshold 1/Comparator threshold 2 */
  CM4_LPE_BCTU_INT0_4_IRQn     = 222,              /**< ADC conversion triggered/ADC0 conversion data ready/ADC last command of list issued/FIFO1/FIFO2 */
  CM4_LPE_FTM_INT0_10_IRQn     = 223,              /**< Channel 0/Channel 1/Channel 2/Channel 3/Channel 4/Channel 5/Channel 6/Channel 7/Fault/Overflow/Reload */
  CM4_LPE_LCU_INT_IRQn         = 224,              /**< Logic Cell 0 */
  CM4_LPE_PIT_RTI_INT0_3_IRQn  = 225,              /**< Channel 0/Channel 1/Channel 2/Channel 3/Channel 4 (RTI) */
  CM4_LPE_RTC_API_INT0_1_IRQn  = 226,              /**< RTC compare and counter overflow/API compare */
  CM4_LPE_STM_INT0_3_IRQn      = 227,              /**< Channel 0/Channel 1/Channel 2/Channel 3 */
  CM4_LPE_FLEXCAN_INT0_8_IRQn  = 228,              /**< CAN bus went to Bus Off state/CAN has completed the Bus Off count process (it has counted 11 recessive bits 128 times) and is ready for bus off recover/Errors detected on the CAN bus/Errors detected on the CAN bus for FD messages in the Fast Bit Rate region/Transmit Error Counter transition from < 96 to >= 96/Receive Error Counter transition from < 96 to >= 96/Correctable error detected in memory read access/Non-correctable error detected in memory read access by host (cpu)/Non-correctable error detected in memory read access by CAN */
  CM4_LPE_FLEXCAN_INT9_15_IRQn = 229,              /**< The number of messages stored in FIFO is greater than the FIFO watermarker/At least one message stored in FIFO/An underflow occurs in the FIFO/An overflow occurs in the FIFO/All Message Buffers */
  CM4_LPE_LPI2C_INT0_3_IRQn    = 230,              /**< Master/Asynchronous master/Slave/Asynchronous slave */
  CM4_LPE_LPSPI0_INT0_1_IRQn   = 231,              /**< Transmit and receive data and errors/Asynchronous */
  CM4_LPE_LPSPI1_INT0_1_IRQn   = 232,              /**< Transmit and receive data and errors/Asynchronous */
  CM4_LPE_LPUART0_INT0_3_IRQn  = 233,              /**< Transmit data and errors/Asynchronous transmit/Receive data and errors/Asynchronous receive */
  CM4_LPE_LPUART1_INT0_3_IRQn  = 234,              /**< Transmit data and errors/Asynchronous transmit/Receive data and errors/Asynchronous receive */
  CM4_LPE_LPUART2_INT0_3_IRQn  = 235,              /**< Transmit data and errors/Asynchronous transmit/Receive data and errors/Asynchronous receive */
  CM4_LPE_VFCCU_INT_IRQn       = 236,              /**< CM4 FCCU reaction 7 */
  CM4_CPE_XRDC_INT_IRQn        = 237               /**< Transfer Error */
} IRQn_Type;

/*!
 * @}
 */ /* end of group Interrupt_vector_numbers */


/* ----------------------------------------------------------------------------
   -- Cortex M4 Core Configuration
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Cortex_Core_Configuration Cortex M4 Core Configuration
 * @{
 */

#define __MPU_PRESENT                  1         /**< Defines if an MPU is present or not */
#define __NVIC_PRIO_BITS               4         /**< Number of priority bits implemented in the NVIC */
#define __Vendor_SysTickConfig         0         /**< Vendor specific implementation of SysTickConfig is defined */
#define __FPU_PRESENT                  1         /**< Defines if an FPU is present or not */


/*!
 * @}
 */ /* end of group Cortex_Core_Configuration */


/* ----------------------------------------------------------------------------
   -- SDK Compatibility
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SDK_Compatibility_Symbols SDK Compatibility
 * @{
 */

/* No SDK compatibility issues. */

/*!
 * @}
 */ /* end of group SDK_Compatibility_Symbols */


#endif  /* #if !defined(S32K566_M4_COMMON_H_) */

