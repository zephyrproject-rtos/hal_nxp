/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K566.h
 * @version 2.1
 * @date 2025-07-29
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
#if !defined(S32K566_DSPV_COMMON_H_)  /* Check if memory map has not been already included */
#define S32K566_DSPV_COMMON_H_
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
#define MCU_MEM_MAP_VERSION_MINOR 0x0001U

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
#define NUMBER_OF_INT_VECTORS 213                /**< Number of interrupts in the Vector table */

typedef enum {
  /* Auxiliary constants */
  NotAvail_IRQn                = -128,             /**< Not available device specific interrupt */

  /* Machine External Interrupts */
  INTC_SW_0_IRQn               = 0,               /**< Software Interrupts 0 */
  INTC_SW_1_IRQn               = 1,               /**< Software Interrupts 1 */
  INTC_SW_2_IRQn               = 2,               /**< Software Interrupts 2 */
  INTC_SW_3_IRQn               = 3,               /**< Software Interrupts 3 */
  INTC_SW_4_IRQn               = 4,               /**< Software Interrupts 4 */
  INTC_SW_5_IRQn               = 5,               /**< Software Interrupts 5 */
  INTC_SW_6_IRQn               = 6,               /**< Software Interrupts 6 */
  INTC_SW_7_IRQn               = 7,               /**< Software Interrupts 7 */

  SWT_IRQn                     = 8,              /**< Watchdog service */
  MU0_IRQn                     = 9,              /**< Or'd interrupts MU0 B-Interface */
  MU1_IRQn                     = 10,              /**< Or'd interrupts MU1 B-Interface */
  MU2_IRQn                     = 11,              /**< Or'd interrupts MU2 B-Interface */
  MU3_IRQn                     = 12,              /**< Or'd interrupts MU3 B-Interface */
  STM_CH0_IRQn                 = 13,              /**< Timer compare 0 */
  STM_CH1_IRQn                 = 14,              /**< Timer compare 1 */
  STM_CH2_IRQn                 = 15,              /**< Timer compare 2 */
  STM_CH3_IRQn                 = 16,              /**< Timer compare 3 */

  /* Device specific interrupts */
  eDMA5_TCD0_2_INT_IRQn        = 41,              /**< DMA transfer complete and error channel 0/DMA transfer complete and error channel 1 */
  eDMA5_TCD2_3_INT_IRQn        = 42,              /**< DMA transfer complete and error channel 2/DMA transfer complete and error channel 3 */
  eDMA5_TCD16_17_INT_IRQn      = 43,              /**< DMA transfer complete and error channel 16/DMA transfer complete and error channel 17 */
  eDMA5_TCD18_19_INT_IRQn      = 44,              /**< DMA transfer complete and error channel 18/DMA transfer complete and error channel 19 */
  NEUTRON_ACCEL_INT0_1_IRQn    = 45,              /**< Functional/Fault */
  SARADC0_INT0_2_IRQn          = 46,              /**< End of conversion/Error/Analog watchdog */
  SARADC1_INT0_2_IRQn          = 47,              /**< End of conversion/Error/Analog watchdog */
  BCTU_INT0_5_IRQn             = 48,              /**< ADC conversion triggered/ADC0 conversion data ready/ADC1 conversion data ready/ADC last command of list issued/FIFO1/FIFO2 */
  SINC_INT0_3_IRQn             = 49,              /**< Channel 0/Channel 1/Channel 2/Channel 3 */
  CANXL0_INT0_20_IRQn          = 50,              /**< CAN frame transmission from one of the Tx message buffers 0-31 completed/CAN frame transmission from one of the Tx message buffers 32-63 completed/CAN frame reception into one of the Rx message buffers 0-31 completed/CAN frame reception into one of the Rx message buffers 32-63 completed/The Rx FIFO used for reception of selected CAN frames has reached its programmable threshold/The Rx FIFO used for reception of selected CAN frames has experienced underflow or overflow/Message Receive Unit/Protocol engine error occurred related to reception or transmission of CAN frames/Receive Error Counter Interrupt/Transmit Error Counter Interrupt/Bus Off Recovery Ready Interrupt/Bus Off Interrupt/Protocol Exception Error Interrupt/Passive Error State Interrupt/Frame error during arbitration/data phase 1/Frame error during arbitration/data phase 2/Frame error during arbitration/data phase 3/Internal exception is detected/Non-correctable error occurred within internal data RAM/Correctable error occurred within internal data RAM/IP has entered or exited freeze mode */
  FLEXCAN0_INT0_8_IRQn         = 51,              /**< CAN bus went to Bus Off state/CAN has completed the Bus Off count process (it has counted 11 recessive bits 128 times) and is ready for bus off recover/Errors detected on the CAN bus/Errors detected on the CAN bus for FD messages in the Fast Bit Rate region/Transmit Error Counter transition from < 96 to >= 96/Receive Error Counter transition from < 96 to >= 96/Correctable error detected in memory read access/Non-correctable error detected in memory read access by host (cpu)/Non-correctable error detected in memory read access by CAN */
  FLEXCAN0_INT9_15_IRQn        = 52,              /**< The number of messages stored in FIFO is greater than the FIFO watermarker/At least one message stored in FIFO/An underflow occurs in the FIFO/An overflow occurs in the FIFO/All Message Buffers */
  FLEXCAN1_INT0_8_IRQn         = 53,              /**< CAN bus went to Bus Off state/CAN has completed the Bus Off count process (it has counted 11 recessive bits 128 times) and is ready for bus off recover/Errors detected on the CAN bus/Errors detected on the CAN bus for FD messages in the Fast Bit Rate region/Transmit Error Counter transition from < 96 to >= 96/Receive Error Counter transition from < 96 to >= 96/Correctable error detected in memory read access/Non-correctable error detected in memory read access by host (cpu)/Non-correctable error detected in memory read access by CAN */
  FLEXCAN1_INT9_15_IRQn        = 54,              /**< The number of messages stored in FIFO is greater than the FIFO watermarker/At least one message stored in FIFO/An underflow occurs in the FIFO/An overflow occurs in the FIFO/All Message Buffers */
  FLEXCAN2_INT0_8_IRQn         = 55,              /**< CAN bus went to Bus Off state/CAN has completed the Bus Off count process (it has counted 11 recessive bits 128 times) and is ready for bus off recover/Errors detected on the CAN bus/Errors detected on the CAN bus for FD messages in the Fast Bit Rate region/Transmit Error Counter transition from < 96 to >= 96/Receive Error Counter transition from < 96 to >= 96/Correctable error detected in memory read access/Non-correctable error detected in memory read access by host (cpu)/Non-correctable error detected in memory read access by CAN */
  FLEXCAN2_INT9_15_IRQn        = 56,              /**< The number of messages stored in FIFO is greater than the FIFO watermarker/At least one message stored in FIFO/An underflow occurs in the FIFO/An overflow occurs in the FIFO/All Message Buffers */
  FLEXCAN3_INT0_8_IRQn         = 57,              /**< CAN bus went to Bus Off state/CAN has completed the Bus Off count process (it has counted 11 recessive bits 128 times) and is ready for bus off recover/Errors detected on the CAN bus/Errors detected on the CAN bus for FD messages in the Fast Bit Rate region/Transmit Error Counter transition from < 96 to >= 96/Receive Error Counter transition from < 96 to >= 96/Correctable error detected in memory read access/Non-correctable error detected in memory read access by host (cpu)/Non-correctable error detected in memory read access by CAN */
  FLEXCAN3_INT9_15_IRQn        = 58,              /**< The number of messages stored in FIFO is greater than the FIFO watermarker/At least one message stored in FIFO/An underflow occurs in the FIFO/An overflow occurs in the FIFO/All Message Buffers */
  FLEXCAN4_INT0_8_IRQn         = 59,              /**< CAN bus went to Bus Off state/CAN has completed the Bus Off count process (it has counted 11 recessive bits 128 times) and is ready for bus off recover/Errors detected on the CAN bus/Errors detected on the CAN bus for FD messages in the Fast Bit Rate region/Transmit Error Counter transition from < 96 to >= 96/Receive Error Counter transition from < 96 to >= 96/Correctable error detected in memory read access/Non-correctable error detected in memory read access by host (cpu)/Non-correctable error detected in memory read access by CAN */
  FLEXCAN4_INT9_15_IRQn        = 60,              /**< The number of messages stored in FIFO is greater than the FIFO watermarker/At least one message stored in FIFO/An underflow occurs in the FIFO/An overflow occurs in the FIFO/All Message Buffers */
  FLEXCAN5_INT0_8_IRQn         = 61,              /**< CAN bus went to Bus Off state/CAN has completed the Bus Off count process (it has counted 11 recessive bits 128 times) and is ready for bus off recover/Errors detected on the CAN bus/Errors detected on the CAN bus for FD messages in the Fast Bit Rate region/Transmit Error Counter transition from < 96 to >= 96/Receive Error Counter transition from < 96 to >= 96/Correctable error detected in memory read access/Non-correctable error detected in memory read access by host (cpu)/Non-correctable error detected in memory read access by CAN */
  FLEXCAN5_INT9_15_IRQn        = 62,              /**< The number of messages stored in FIFO is greater than the FIFO watermarker/At least one message stored in FIFO/An underflow occurs in the FIFO/An overflow occurs in the FIFO/All Message Buffers */
  FLEXCAN6_INT0_8_IRQn         = 63,              /**< CAN bus went to Bus Off state/CAN has completed the Bus Off count process (it has counted 11 recessive bits 128 times) and is ready for bus off recover/Errors detected on the CAN bus/Errors detected on the CAN bus for FD messages in the Fast Bit Rate region/Transmit Error Counter transition from < 96 to >= 96/Receive Error Counter transition from < 96 to >= 96/Correctable error detected in memory read access/Non-correctable error detected in memory read access by host (cpu)/Non-correctable error detected in memory read access by CAN */
  FLEXCAN6_INT9_15_IRQn        = 64,              /**< The number of messages stored in FIFO is greater than the FIFO watermarker/At least one message stored in FIFO/An underflow occurs in the FIFO/An overflow occurs in the FIFO/All Message Buffers */
  FLEXCAN7_INT0_8_IRQn         = 65,              /**< CAN bus went to Bus Off state/CAN has completed the Bus Off count process (it has counted 11 recessive bits 128 times) and is ready for bus off recover/Errors detected on the CAN bus/Errors detected on the CAN bus for FD messages in the Fast Bit Rate region/Transmit Error Counter transition from < 96 to >= 96/Receive Error Counter transition from < 96 to >= 96/Correctable error detected in memory read access/Non-correctable error detected in memory read access by host (cpu)/Non-correctable error detected in memory read access by CAN */
  FLEXCAN7_INT9_15_IRQn        = 66,              /**< The number of messages stored in FIFO is greater than the FIFO watermarker/At least one message stored in FIFO/An underflow occurs in the FIFO/An overflow occurs in the FIFO/All Message Buffers */
  FLEXCAN8_INT0_8_IRQn         = 67,              /**< CAN bus went to Bus Off state/CAN has completed the Bus Off count process (it has counted 11 recessive bits 128 times) and is ready for bus off recover/Errors detected on the CAN bus/Errors detected on the CAN bus for FD messages in the Fast Bit Rate region/Transmit Error Counter transition from < 96 to >= 96/Receive Error Counter transition from < 96 to >= 96/Correctable error detected in memory read access/Non-correctable error detected in memory read access by host (cpu)/Non-correctable error detected in memory read access by CAN */
  FLEXCAN8_INT9_15_IRQn        = 68,              /**< The number of messages stored in FIFO is greater than the FIFO watermarker/At least one message stored in FIFO/An underflow occurs in the FIFO/An overflow occurs in the FIFO/All Message Buffers */
  FLEXIO0_INT_IRQn             = 69,              /**< FlexIO */
  FLEXIO1_INT_IRQn             = 70,              /**< FlexIO */
  LPI2C0_INT0_1_IRQn           = 71,              /**< Master/Slave */
  LPI2C1_INT0_1_IRQn           = 72,              /**< Master/Slave */
  LPSPI0_INT_IRQn              = 73,              /**< Transmit and receive data and errors */
  LPSPI1_INT_IRQn              = 74,              /**< Transmit and receive data and errors */
  LPUART0_INT0_1_IRQn          = 75,              /**< Transmit data and errors/Receive data and errors */
  LPUART1_INT0_1_IRQn          = 76,              /**< Transmit data and errors/Receive data and errors */
  LPUART2_INT0_1_IRQn          = 77,              /**< Transmit data and errors/Receive data and errors */
  LPUART3_INT0_1_IRQn          = 78,              /**< Transmit data and errors/Receive data and errors */
  LPUART4_INT0_1_IRQn          = 79,              /**< Transmit data and errors/Receive data and errors */
  LPUART5_INT0_1_IRQn          = 80,              /**< Transmit data and errors/Receive data and errors */
  LPUART6_INT0_1_IRQn          = 81,              /**< Transmit data and errors/Receive data and errors */
  LPUART7_INT0_1_IRQn          = 82,              /**< Transmit data and errors/Receive data and errors */
  LPUART8_INT0_1_IRQn          = 83,              /**< Transmit data and errors/Receive data and errors */
  LPUART9_INT0_1_IRQn          = 84,              /**< Transmit data and errors/Receive data and errors */
  LPUART10_INT0_1_IRQn         = 85,              /**< Transmit data and errors/Receive data and errors */
  LPUART11_INT0_1_IRQn         = 86,              /**< Transmit data and errors/Receive data and errors */
  LPUART12_INT0_1_IRQn         = 87,              /**< Transmit data and errors/Receive data and errors */
  MSGINTR0_INT0_2_IRQn         = 88,              /**< Message signaled interrupt register 0/Message signaled interrupt register 1/Message signaled interrupt register 2 */
  MSGINTR1_INT0_2_IRQn         = 89,              /**< Message signaled interrupt register 0/Message signaled interrupt register 1/Message signaled interrupt register 2 */
  MSGINTR2_INT0_2_IRQn         = 90,              /**< Message signaled interrupt register 0/Message signaled interrupt register 1/Message signaled interrupt register 2 */
  MSGINTR3_INT0_2_IRQn         = 91,              /**< Message signaled interrupt register 0/Message signaled interrupt register 1/Message signaled interrupt register 2 */
  MSGINTR4_INT0_2_IRQn         = 92,              /**< Message signaled interrupt register 0/Message signaled interrupt register 1/Message signaled interrupt register 2 */
  MSGINTR5_INT0_2_IRQn         = 93,              /**< Message signaled interrupt register 0/Message signaled interrupt register 1/Message signaled interrupt register 2 */
  MSGINTR6_INT0_2_IRQn         = 94,              /**< Message signaled interrupt register 0/Message signaled interrupt register 1/Message signaled interrupt register 2 */
  NETC_IEPRC_INT0_1_IRQn       = 95,              /**< NETC Root Complex PCI 0/NETC Root Complex PCI 1 */
  RXLUT_INT_IRQn               = 96,              /**< RXLUT */
  SAI0_INT0_1_IRQn             = 97,              /**< Receive/Transmit */
  SAI1_INT0_1_IRQn             = 98              /**< Receive/Transmit */
} IRQn_Type;

/*!
 * @}
 */ /* end of group Interrupt_vector_numbers */


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


#endif  /* #if !defined(S32K566_DSPV_COMMON_H_) */

