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
#if !defined(S32K566_M7_COMMON_H_)  /* Check if memory map has not been already included */
#define S32K566_M7_COMMON_H_
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
  HardFault_IRQn               = -13,              /**< Cortex-M7 SV Hard Fault Interrupt */
  MemoryManagement_IRQn        = -12,              /**< Cortex-M7 Memory Management Interrupt */
  BusFault_IRQn                = -11,              /**< Cortex-M7 Bus Fault Interrupt */
  UsageFault_IRQn              = -10,              /**< Cortex-M7 Usage Fault Interrupt */
  SVCall_IRQn                  = -5,               /**< Cortex-M7 SV Call Interrupt */
  DebugMonitor_IRQn            = -4,               /**< Cortex-M7 Debug Monitor Interrupt */
  PendSV_IRQn                  = -2,               /**< Cortex-M7 Pend SV Interrupt */
  SysTick_IRQn                 = -1,               /**< Cortex-M7 System Tick Interrupt */

  /* Device specific interrupts */
  CM7_CTI_INT0_1_IRQn          = 0,                /**< Per core: DWT comparator output 0/Per core: DWT comparator output 1 */
  CM7_DSP_INT0_IRQn            = 1,                /**< ORed requests to MU0 */
  CM7_DSP_INT1_IRQn            = 2,                /**< ORed requests to MU1 */
  CM7_DSP_INT2_IRQn            = 3,                /**< ORed requests to MU2 */
  CM7_DSP_INT3_IRQn            = 4,                /**< ORed requests to MU3 */
  CM7_eDMA5_TCD0_2_INT_IRQn    = 5,                /**< DMA transfer complete and error channel 0/DMA transfer complete and error channel 1 */
  CM7_eDMA5_TCD2_3_INT_IRQn    = 6,                /**< DMA transfer complete and error channel 2/DMA transfer complete and error channel 3 */
  CM7_eDMA5_TCD4_5_INT_IRQn    = 7,                /**< DMA transfer complete and error channel 4/DMA transfer complete and error channel 5 */
  CM7_eDMA5_TCD6_7_INT_IRQn    = 8,                /**< DMA transfer complete and error channel 6/DMA transfer complete and error channel 7 */
  CM7_eDMA5_TCD8_9_INT_IRQn    = 9,                /**< DMA transfer complete and error channel 8/DMA transfer complete and error channel 9 */
  CM7_eDMA5_TCD10_11_INT_IRQn  = 10,               /**< DMA transfer complete and error channel 10/DMA transfer complete and error channel 11 */
  CM7_eDMA5_TCD12_13_INT_IRQn  = 11,               /**< DMA transfer complete and error channel 12/DMA transfer complete and error channel 13 */
  CM7_eDMA5_TCD14_15_INT_IRQn  = 12,               /**< DMA transfer complete and error channel 14/DMA transfer complete and error channel 15 */
  CM7_eDMA5_TCD16_17_INT_IRQn  = 13,               /**< DMA transfer complete and error channel 16/DMA transfer complete and error channel 17 */
  CM7_eDMA5_TCD18_19_INT_IRQn  = 14,               /**< DMA transfer complete and error channel 18/DMA transfer complete and error channel 19 */
  CM7_eDMA5_TCD20_21_INT_IRQn  = 15,               /**< DMA transfer complete and error channel 20/DMA transfer complete and error channel 21 */
  CM7_eDMA5_TCD22_23_INT_IRQn  = 16,               /**< DMA transfer complete and error channel 22/DMA transfer complete and error channel 23 */
  CM7_eDMA5_TCD24_25_INT_IRQn  = 17,               /**< DMA transfer complete and error channel 24/DMA transfer complete and error channel 25 */
  CM7_eDMA5_TCD26_27_INT_IRQn  = 18,               /**< DMA transfer complete and error channel 26/DMA transfer complete and error channel 27 */
  CM7_eDMA5_TCD28_29_INT_IRQn  = 19,               /**< DMA transfer complete and error channel 28/DMA transfer complete and error channel 29 */
  CM7_eDMA5_TCD30_31_INT_IRQn  = 20,               /**< DMA transfer complete and error channel 30/DMA transfer complete and error channel 31 */
  CM7_XRDC_A_C_INT_IRQn        = 21,               /**< Transfer error/Transfer error/Transfer error */
  CM7_0_MRU0_INT0_4_IRQn       = 22,               /**< Per core: Notification channel 0/Per core: Notification channel 1/Per core: Notification channel 2/Per core: Notification channel 3/Channel reset */
  CM7_1_MRU2_INT0_4_IRQn       = 22,               /**< Per core: Notification channel 0/Per core: Notification channel 1/Per core: Notification channel 2/Per core: Notification channel 3/Channel reset */
  CM7_2_MRU4_INT0_4_IRQn       = 22,               /**< Per core: Notification channel 0/Per core: Notification channel 1/Per core: Notification channel 2/Per core: Notification channel 3/Channel reset */
  CM7_3_MRU6_INT0_4_IRQn       = 22,               /**< Per core: Notification channel 0/Per core: Notification channel 1/Per core: Notification channel 2/Per core: Notification channel 3/Channel reset */
  CM7_0_MRU1_INT0_4_IRQn       = 23,               /**< Per core: Notification channel 0/Per core: Notification channel 1/Per core: Notification channel 2/Per core: Notification channel 3/Channel reset */
  CM7_1_MRU3_INT0_4_IRQn       = 23,               /**< Per core: Notification channel 0/Per core: Notification channel 1/Per core: Notification channel 2/Per core: Notification channel 3/Channel reset */
  CM7_2_MRU5_INT0_4_IRQn       = 23,               /**< Per core: Notification channel 0/Per core: Notification channel 1/Per core: Notification channel 2/Per core: Notification channel 3/Channel reset */
  CM7_3_MRU7_INT0_4_IRQn       = 23,               /**< Per core: Notification channel 0/Per core: Notification channel 1/Per core: Notification channel 2/Per core: Notification channel 3/Channel reset */
  CM7_MCM_INT0_6_IRQn          = 24,               /**< Per core: FPU input denormal/Per core: FPU inexact/Per core: FPU underflow/Per core: FPU overflow/Per core: FPU divide-by-zero/Per core: FPU invalid operation/Per core: Write abort */
  CM7_MRAMC_INT_IRQn           = 25,               /**< AXI bufferable write error */
  CM7_NEUTRON_ACCEL_INT0_1_IRQn = 26,              /**< Functional/Fault */
  CM7_SWT_STARTUP_INT_IRQn     = 27,               /**< Initial time-out */
  CM7_0_SWT0_INT_IRQn          = 28,               /**< Initial time-out */
  CM7_1_SWT1_INT_IRQn          = 28,               /**< Initial time-out */
  CM7_2_SWT2_INT_IRQn          = 28,               /**< Initial time-out */
  CM7_3_SWT3_INT_IRQn          = 28,               /**< Initial time-out */
  CM7_SIUL2_0_INT_IRQn         = 29,               /**< Vector 0 */
  CM7_SIUL2_1_INT_IRQn         = 30,               /**< Vector 0 */
  CM7_SIUL2_3_INT_IRQn         = 31,               /**< Vector 0 */
  CM7_SIUL2_4_INT_IRQn         = 32,               /**< Vector 0 */
  CM7_CSTCU_INT_IRQn           = 36,               /**< Self-test complete */
  CM7_0_VFCCU_INT1_IRQn        = 37,               /**< Per core: Central FCCU reaction 1 */
  CM7_1_VFCCU_INT2_IRQn        = 37,               /**< Per core: Central FCCU reaction 2 */
  CM7_2_VFCCU_INT3_IRQn        = 37,               /**< Per core: Central FCCU reaction 3 */
  CM7_3_VFCCU_INT4_IRQn        = 37,               /**< Per core: Central FCCU reaction 4 */
  CM7_VFCCU_INT8_IRQn          = 38,               /**< Central FCCU reaction index0 */
  CM7_VFCCU_INT9_IRQn          = 39,               /**< Central FCCU reaction index1 */
  CM7_ERM0_INT0_1_IRQn         = 41,               /**< Single-bit correctable event/Multi-bit uncorrectable error event */
  CM7_ERM1_INT0_1_IRQn         = 42,               /**< Single-bit correctable event/Multi-bit uncorrectable error event */
  CM7_ERM2_INT0_1_IRQn         = 43,               /**< Single-bit correctable event/Multi-bit uncorrectable error event */
  CM7_ERM3_INT0_1_IRQn         = 44,               /**< Single-bit correctable event/Multi-bit uncorrectable error event */
  CM7_ERM4_INT0_1_IRQn         = 45,               /**< Single-bit correctable event/Multi-bit uncorrectable error event */
  CM7_ERM5_INT0_1_IRQn         = 46,               /**< Single-bit correctable event/Multi-bit uncorrectable error event */
  CM7_AES_ACCEL_INT0_2_IRQn    = 47,               /**< Application 0/Application 0 timeout/Application 0 keystore error */
  CM7_AES_ACCEL_INT3_5_IRQn    = 48,               /**< Application 1/Application 1 timeout/Application 1 keystore error */
  CM7_AES_ACCEL_INT6_8_IRQn    = 49,               /**< Application 2/Application 2 timeout/Application 2 keystore error */
  CM7_AES_ACCEL_INT9_11_IRQn   = 50,               /**< Application 3/Application 3 timeout/Application 3 keystore error */
  CM7_AES_ACCEL_INT12_14_IRQn  = 51,               /**< Application 4/Application 4 timeout/Application 4 keystore error */
  CM7_AES_ACCEL_INT15_17_IRQn  = 52,               /**< Application 5/Application 5 timeout/Application 5 keystore error */
  CM7_AES_ACCEL_INT18_20_IRQn  = 53,               /**< Application 6/Application 6 timeout/Application 6 keystore error */
  CM7_AES_ACCEL_INT21_23_IRQn  = 54,               /**< Application 7/Application 7 timeout/Application 7 keystore error */
  CM7_AES_ACCEL_INT24_25_IRQn  = 55,               /**< Feed DMA error/Result DMA error */
  CM7_SENTMU0_INT0_2_IRQn      = 56,               /**< ORed TX request to MU0A/ORed RX request to MU0A/ORed general purpose request to MU0A */
  CM7_SENTMU1_INT0_2_IRQn      = 57,               /**< ORed TX request to MU1A/ORed RX request to MU1A/ORed general purpose request to MU1A */
  CM7_SENTMU2_INT0_2_IRQn      = 58,               /**< ORed TX request to MU2A/ORed RX request to MU2A/ORed general purpose request to MU2A */
  CM7_SENTMU3_INT0_2_IRQn      = 59,               /**< ORed TX request to MU3A/ORed RX request to MU3A/ORed general purpose request to MU3A */
  CM7_SENTMU4_INT0_2_IRQn      = 60,               /**< ORed TX request to MU4A/ORed RX request to MU4A/ORed general purpose request to MU4A */
  CM7_SENTMU5_INT0_2_IRQn      = 61,               /**< ORed TX request to MU5A/ORed RX request to MU5A/ORed general purpose request to MU5A */
  CM7_SENTMU6_INT0_2_IRQn      = 62,               /**< ORed TX request to MU6A/ORed RX request to MU6A/ORed general purpose request to MU6A */
  CM7_SENTMU7_INT0_2_IRQn      = 63,               /**< ORed TX request to MU7A/ORed RX request to MU7A/ORed general purpose request to MU7A */
  CM7_SARADC0_INT0_2_IRQn      = 64,               /**< End of conversion/Error/Analog watchdog */
  CM7_SARADC1_INT0_2_IRQn      = 65,               /**< End of conversion/Error/Analog watchdog */
  CM7_BCTU_INT0_5_IRQn         = 66,               /**< ADC conversion triggered/ADC0 conversion data ready/ADC1 conversion data ready/ADC last command of list issued/FIFO1/FIFO2 */
  CM7_eMIOS0_INT0_3_IRQn       = 67,               /**< Channel 0/Channel 1/Channel 2/Channel 3 */
  CM7_eMIOS0_INT4_7_IRQn       = 68,               /**< Channel 4/Channel 5/Channel 6/Channel 7 */
  CM7_eMIOS0_INT8_11_IRQn      = 69,               /**< Channel 8/Channel 9/Channel 10/Channel 11 */
  CM7_eMIOS0_INT12_15_IRQn     = 70,               /**< Channel 12/Channel 13/Channel 14/Channel 15 */
  CM7_eMIOS0_INT16_19_IRQn     = 71,               /**< Channel 16/Channel 17/Channel 18/Channel 19 */
  CM7_eMIOS0_INT20_23_IRQn     = 72,               /**< Channel 20/Channel 21/Channel 22/Channel 23 */
  CM7_eMIOS1_INT0_3_IRQn       = 73,               /**< Channel 0/Channel 1/Channel 2/Channel 3 */
  CM7_eMIOS1_INT4_7_IRQn       = 74,               /**< Channel 4/Channel 5/Channel 6/Channel 7 */
  CM7_eMIOS1_INT8_11_IRQn      = 75,               /**< Channel 8/Channel 9/Channel 10/Channel 11 */
  CM7_eMIOS1_INT12_15_IRQn     = 76,               /**< Channel 12/Channel 13/Channel 14/Channel 15 */
  CM7_eMIOS1_INT16_19_IRQn     = 77,               /**< Channel 16/Channel 17/Channel 18/Channel 19 */
  CM7_eMIOS1_INT20_23_IRQn     = 78,               /**< Channel 20/Channel 21/Channel 22/Channel 23 */
  CM7_eMIOS2_INT0_3_IRQn       = 79,               /**< Channel 0/Channel 1/Channel 2/Channel 3 */
  CM7_eMIOS2_INT4_7_IRQn       = 80,               /**< Channel 4/Channel 5/Channel 6/Channel 7 */
  CM7_eMIOS2_INT8_11_IRQn      = 81,               /**< Channel 8/Channel 9/Channel 10/Channel 11 */
  CM7_eMIOS2_INT12_15_IRQn     = 82,               /**< Channel 12/Channel 13/Channel 14/Channel 15 */
  CM7_eMIOS2_INT16_19_IRQn     = 83,               /**< Channel 16/Channel 17/Channel 18/Channel 19 */
  CM7_eMIOS2_INT20_23_IRQn     = 84,               /**< Channel 20/Channel 21/Channel 22/Channel 23 */
  CM7_GTM_INT0_28_IRQn         = 85,               /**< GTM ERR/GTM AEI/GTM ARU/GTM BRC/GTM SPE0/GTM SPE1/GTM CMP/GTM PSM0/GTM DPLL/GTM TIM0/GTM TIM1/GTM TIM2/GTM MCS0/GTM MCS1/GTM MCS2/GTM MCS3/GTM MCS0_S/GTM MCS1_S/GTM MCS2_S/GTM MCS3_S/GTM TOM0/GTM TOM1/GTM TIO1_G0/GTM TIO2_G0/GTM TIO3_G0/GTM ATOM0/GTM ATOM1/GTM ATOM2/GTM ATOM3 */
  CM7_LCU0_INT0_2_IRQn         = 86,               /**< Logic Cell 0/Logic Cell 1/Logic Cell 2 */
  CM7_LCU1_INT0_2_IRQn         = 87,               /**< Logic Cell 0/Logic Cell 1/Logic Cell 2 */
  CM7_PIT0_INT0_3_IRQn         = 88,               /**< Channel 0/Channel 1/Channel 2/Channel 3 */
  CM7_PIT1_INT0_3_IRQn         = 89,               /**< Channel 0/Channel 1/Channel 2/Channel 3 */
  CM7_PIT2_INT0_3_IRQn         = 90,               /**< Channel 0/Channel 1/Channel 2/Channel 3 */
  CM7_PIT3_INT0_3_IRQn         = 91,               /**< Channel 0/Channel 1/Channel 2/Channel 3 */
  CM7_SINC_INT0_3_IRQn         = 92,               /**< Channel 0/Channel 1/Channel 2/Channel 3 */
  CM7_STM0_INT0_3_IRQn         = 93,               /**< Channel 0/Channel 1/Channel 2/Channel 3 */
  CM7_STM1_INT0_3_IRQn         = 94,               /**< Channel 0/Channel 1/Channel 2/Channel 3 */
  CM7_STM2_INT0_3_IRQn         = 95,               /**< Channel 0/Channel 1/Channel 2/Channel 3 */
  CM7_STM3_INT0_3_IRQn         = 96,               /**< Channel 0/Channel 1/Channel 2/Channel 3 */
  CM7_CANXL0_INT0_20_IRQn      = 97,               /**< CAN frame transmission from one of the Tx message buffers 0-31 completed/CAN frame transmission from one of the Tx message buffers 32-63 completed/CAN frame reception into one of the Rx message buffers 0-31 completed/CAN frame reception into one of the Rx message buffers 32-63 completed/The Rx FIFO used for reception of selected CAN frames has reached its programmable threshold/The Rx FIFO used for reception of selected CAN frames has experienced underflow or overflow/Message Receive Unit/Protocol engine error occurred related to reception or transmission of CAN frames/Receive Error Counter Interrupt/Transmit Error Counter Interrupt/Bus Off Recovery Ready Interrupt/Bus Off Interrupt/Protocol Exception Error Interrupt/Passive Error State Interrupt/Frame error during arbitration/data phase 1/Frame error during arbitration/data phase 2/Frame error during arbitration/data phase 3/Internal exception is detected/Non-correctable error occurred within internal data RAM/Correctable error occurred within internal data RAM/IP has entered or exited freeze mode */
  CM7_CANXL1_INT0_20_IRQn      = 98,               /**< CAN frame transmission from one of the Tx message buffers 0-31 completed/CAN frame transmission from one of the Tx message buffers 32-63 completed/CAN frame reception into one of the Rx message buffers 0-31 completed/CAN frame reception into one of the Rx message buffers 32-63 completed/The Rx FIFO used for reception of selected CAN frames has reached its programmable threshold/The Rx FIFO used for reception of selected CAN frames has experienced underflow or overflow/Message Receive Unit/Protocol engine error occurred related to reception or transmission of CAN frames/Receive Error Counter Interrupt/Transmit Error Counter Interrupt/Bus Off Recovery Ready Interrupt/Bus Off Interrupt/Protocol Exception Error Interrupt/Passive Error State Interrupt/Frame error during arbitration/data phase 1/Frame error during arbitration/data phase 2/Frame error during arbitration/data phase 3/Internal exception is detected/Non-correctable error occurred within internal data RAM/Correctable error occurred within internal data RAM/IP has entered or exited freeze mode */
  CM7_TENBASET_PHY0_INT_IRQn   = 99,               /**< Physical collision */
  CM7_TENBASET_PHY1_INT_IRQn   = 100,              /**< Physical collision */
  CM7_TENBASET_PHY2_INT_IRQn   = 101,              /**< Physical collision */
  CM7_TENBASET_PHY3_INT_IRQn   = 102,              /**< Physical collision */
  CM7_DSPI_MSC0_INT_IRQn       = 103,              /**< DSPI Global (OR of all lines) */
  CM7_DSPI_MSC1_INT_IRQn       = 104,              /**< DSPI Global (OR of all lines) */
  CM7_XSPI_INT0_1_IRQn         = 105,              /**< XSPI/FlashA ECC error */
  CM7_FLEXCAN0_INT0_8_IRQn     = 106,              /**< CAN bus went to Bus Off state/CAN has completed the Bus Off count process (it has counted 11 recessive bits 128 times) and is ready for bus off recover/Errors detected on the CAN bus/Errors detected on the CAN bus for FD messages in the Fast Bit Rate region/Transmit Error Counter transition from < 96 to >= 96/Receive Error Counter transition from < 96 to >= 96/Correctable error detected in memory read access/Non-correctable error detected in memory read access by host (cpu)/Non-correctable error detected in memory read access by CAN */
  CM7_FLEXCAN0_INT9_15_IRQn    = 107,              /**< The number of messages stored in FIFO is greater than the FIFO watermarker/At least one message stored in FIFO/An underflow occurs in the FIFO/An overflow occurs in the FIFO/All Message Buffers */
  CM7_FLEXCAN1_INT0_8_IRQn     = 108,              /**< CAN bus went to Bus Off state/CAN has completed the Bus Off count process (it has counted 11 recessive bits 128 times) and is ready for bus off recover/Errors detected on the CAN bus/Errors detected on the CAN bus for FD messages in the Fast Bit Rate region/Transmit Error Counter transition from < 96 to >= 96/Receive Error Counter transition from < 96 to >= 96/Correctable error detected in memory read access/Non-correctable error detected in memory read access by host (cpu)/Non-correctable error detected in memory read access by CAN */
  CM7_FLEXCAN1_INT9_15_IRQn    = 109,              /**< The number of messages stored in FIFO is greater than the FIFO watermarker/At least one message stored in FIFO/An underflow occurs in the FIFO/An overflow occurs in the FIFO/All Message Buffers */
  CM7_FLEXCAN2_INT0_8_IRQn     = 110,              /**< CAN bus went to Bus Off state/CAN has completed the Bus Off count process (it has counted 11 recessive bits 128 times) and is ready for bus off recover/Errors detected on the CAN bus/Errors detected on the CAN bus for FD messages in the Fast Bit Rate region/Transmit Error Counter transition from < 96 to >= 96/Receive Error Counter transition from < 96 to >= 96/Correctable error detected in memory read access/Non-correctable error detected in memory read access by host (cpu)/Non-correctable error detected in memory read access by CAN */
  CM7_FLEXCAN2_INT9_15_IRQn    = 111,              /**< The number of messages stored in FIFO is greater than the FIFO watermarker/At least one message stored in FIFO/An underflow occurs in the FIFO/An overflow occurs in the FIFO/All Message Buffers */
  CM7_FLEXCAN3_INT0_8_IRQn     = 112,              /**< CAN bus went to Bus Off state/CAN has completed the Bus Off count process (it has counted 11 recessive bits 128 times) and is ready for bus off recover/Errors detected on the CAN bus/Errors detected on the CAN bus for FD messages in the Fast Bit Rate region/Transmit Error Counter transition from < 96 to >= 96/Receive Error Counter transition from < 96 to >= 96/Correctable error detected in memory read access/Non-correctable error detected in memory read access by host (cpu)/Non-correctable error detected in memory read access by CAN */
  CM7_FLEXCAN3_INT9_15_IRQn    = 113,              /**< The number of messages stored in FIFO is greater than the FIFO watermarker/At least one message stored in FIFO/An underflow occurs in the FIFO/An overflow occurs in the FIFO/All Message Buffers */
  CM7_FLEXCAN4_INT0_8_IRQn     = 114,              /**< CAN bus went to Bus Off state/CAN has completed the Bus Off count process (it has counted 11 recessive bits 128 times) and is ready for bus off recover/Errors detected on the CAN bus/Errors detected on the CAN bus for FD messages in the Fast Bit Rate region/Transmit Error Counter transition from < 96 to >= 96/Receive Error Counter transition from < 96 to >= 96/Correctable error detected in memory read access/Non-correctable error detected in memory read access by host (cpu)/Non-correctable error detected in memory read access by CAN */
  CM7_FLEXCAN4_INT9_15_IRQn    = 115,              /**< The number of messages stored in FIFO is greater than the FIFO watermarker/At least one message stored in FIFO/An underflow occurs in the FIFO/An overflow occurs in the FIFO/All Message Buffers */
  CM7_FLEXCAN5_INT0_8_IRQn     = 116,              /**< CAN bus went to Bus Off state/CAN has completed the Bus Off count process (it has counted 11 recessive bits 128 times) and is ready for bus off recover/Errors detected on the CAN bus/Errors detected on the CAN bus for FD messages in the Fast Bit Rate region/Transmit Error Counter transition from < 96 to >= 96/Receive Error Counter transition from < 96 to >= 96/Correctable error detected in memory read access/Non-correctable error detected in memory read access by host (cpu)/Non-correctable error detected in memory read access by CAN */
  CM7_FLEXCAN5_INT9_15_IRQn    = 117,              /**< The number of messages stored in FIFO is greater than the FIFO watermarker/At least one message stored in FIFO/An underflow occurs in the FIFO/An overflow occurs in the FIFO/All Message Buffers */
  CM7_FLEXCAN6_INT0_8_IRQn     = 118,              /**< CAN bus went to Bus Off state/CAN has completed the Bus Off count process (it has counted 11 recessive bits 128 times) and is ready for bus off recover/Errors detected on the CAN bus/Errors detected on the CAN bus for FD messages in the Fast Bit Rate region/Transmit Error Counter transition from < 96 to >= 96/Receive Error Counter transition from < 96 to >= 96/Correctable error detected in memory read access/Non-correctable error detected in memory read access by host (cpu)/Non-correctable error detected in memory read access by CAN */
  CM7_FLEXCAN6_INT9_15_IRQn    = 119,              /**< The number of messages stored in FIFO is greater than the FIFO watermarker/At least one message stored in FIFO/An underflow occurs in the FIFO/An overflow occurs in the FIFO/All Message Buffers */
  CM7_FLEXCAN7_INT0_8_IRQn     = 120,              /**< CAN bus went to Bus Off state/CAN has completed the Bus Off count process (it has counted 11 recessive bits 128 times) and is ready for bus off recover/Errors detected on the CAN bus/Errors detected on the CAN bus for FD messages in the Fast Bit Rate region/Transmit Error Counter transition from < 96 to >= 96/Receive Error Counter transition from < 96 to >= 96/Correctable error detected in memory read access/Non-correctable error detected in memory read access by host (cpu)/Non-correctable error detected in memory read access by CAN */
  CM7_FLEXCAN7_INT9_15_IRQn    = 121,              /**< The number of messages stored in FIFO is greater than the FIFO watermarker/At least one message stored in FIFO/An underflow occurs in the FIFO/An overflow occurs in the FIFO/All Message Buffers */
  CM7_FLEXCAN8_INT0_8_IRQn     = 122,              /**< CAN bus went to Bus Off state/CAN has completed the Bus Off count process (it has counted 11 recessive bits 128 times) and is ready for bus off recover/Errors detected on the CAN bus/Errors detected on the CAN bus for FD messages in the Fast Bit Rate region/Transmit Error Counter transition from < 96 to >= 96/Receive Error Counter transition from < 96 to >= 96/Correctable error detected in memory read access/Non-correctable error detected in memory read access by host (cpu)/Non-correctable error detected in memory read access by CAN */
  CM7_FLEXCAN8_INT9_15_IRQn    = 123,              /**< The number of messages stored in FIFO is greater than the FIFO watermarker/At least one message stored in FIFO/An underflow occurs in the FIFO/An overflow occurs in the FIFO/All Message Buffers */
  CM7_FLEXCAN9_INT0_8_IRQn     = 124,              /**< CAN bus went to Bus Off state/CAN has completed the Bus Off count process (it has counted 11 recessive bits 128 times) and is ready for bus off recover/Errors detected on the CAN bus/Errors detected on the CAN bus for FD messages in the Fast Bit Rate region/Transmit Error Counter transition from < 96 to >= 96/Receive Error Counter transition from < 96 to >= 96/Correctable error detected in memory read access/Non-correctable error detected in memory read access by host (cpu)/Non-correctable error detected in memory read access by CAN */
  CM7_FLEXCAN9_INT9_15_IRQn    = 125,              /**< The number of messages stored in FIFO is greater than the FIFO watermarker/At least one message stored in FIFO/An underflow occurs in the FIFO/An overflow occurs in the FIFO/All Message Buffers */
  CM7_FLEXCAN10_INT0_8_IRQn    = 126,              /**< CAN bus went to Bus Off state/CAN has completed the Bus Off count process (it has counted 11 recessive bits 128 times) and is ready for bus off recover/Errors detected on the CAN bus/Errors detected on the CAN bus for FD messages in the Fast Bit Rate region/Transmit Error Counter transition from < 96 to >= 96/Receive Error Counter transition from < 96 to >= 96/Correctable error detected in memory read access/Non-correctable error detected in memory read access by host (cpu)/Non-correctable error detected in memory read access by CAN */
  CM7_FLEXCAN10_INT9_15_IRQn   = 127,              /**< The number of messages stored in FIFO is greater than the FIFO watermarker/At least one message stored in FIFO/An underflow occurs in the FIFO/An overflow occurs in the FIFO/All Message Buffers */
  CM7_FLEXCAN11_INT0_8_IRQn    = 128,              /**< CAN bus went to Bus Off state/CAN has completed the Bus Off count process (it has counted 11 recessive bits 128 times) and is ready for bus off recover/Errors detected on the CAN bus/Errors detected on the CAN bus for FD messages in the Fast Bit Rate region/Transmit Error Counter transition from < 96 to >= 96/Receive Error Counter transition from < 96 to >= 96/Correctable error detected in memory read access/Non-correctable error detected in memory read access by host (cpu)/Non-correctable error detected in memory read access by CAN */
  CM7_FLEXCAN11_INT9_15_IRQn   = 129,              /**< The number of messages stored in FIFO is greater than the FIFO watermarker/At least one message stored in FIFO/An underflow occurs in the FIFO/An overflow occurs in the FIFO/All Message Buffers */
  CM7_FLEXCAN12_INT0_8_IRQn    = 130,              /**< CAN bus went to Bus Off state/CAN has completed the Bus Off count process (it has counted 11 recessive bits 128 times) and is ready for bus off recover/Errors detected on the CAN bus/Errors detected on the CAN bus for FD messages in the Fast Bit Rate region/Transmit Error Counter transition from < 96 to >= 96/Receive Error Counter transition from < 96 to >= 96/Correctable error detected in memory read access/Non-correctable error detected in memory read access by host (cpu)/Non-correctable error detected in memory read access by CAN */
  CM7_FLEXCAN12_INT9_15_IRQn   = 131,              /**< The number of messages stored in FIFO is greater than the FIFO watermarker/At least one message stored in FIFO/An underflow occurs in the FIFO/An overflow occurs in the FIFO/All Message Buffers */
  CM7_FLEXCAN13_INT0_8_IRQn    = 132,              /**< CAN bus went to Bus Off state/CAN has completed the Bus Off count process (it has counted 11 recessive bits 128 times) and is ready for bus off recover/Errors detected on the CAN bus/Errors detected on the CAN bus for FD messages in the Fast Bit Rate region/Transmit Error Counter transition from < 96 to >= 96/Receive Error Counter transition from < 96 to >= 96/Correctable error detected in memory read access/Non-correctable error detected in memory read access by host (cpu)/Non-correctable error detected in memory read access by CAN */
  CM7_FLEXCAN13_INT9_15_IRQn   = 133,              /**< The number of messages stored in FIFO is greater than the FIFO watermarker/At least one message stored in FIFO/An underflow occurs in the FIFO/An overflow occurs in the FIFO/All Message Buffers */
  CM7_FLEXCAN14_INT0_8_IRQn    = 134,              /**< CAN bus went to Bus Off state/CAN has completed the Bus Off count process (it has counted 11 recessive bits 128 times) and is ready for bus off recover/Errors detected on the CAN bus/Errors detected on the CAN bus for FD messages in the Fast Bit Rate region/Transmit Error Counter transition from < 96 to >= 96/Receive Error Counter transition from < 96 to >= 96/Correctable error detected in memory read access/Non-correctable error detected in memory read access by host (cpu)/Non-correctable error detected in memory read access by CAN */
  CM7_FLEXCAN14_INT9_15_IRQn   = 135,              /**< The number of messages stored in FIFO is greater than the FIFO watermarker/At least one message stored in FIFO/An underflow occurs in the FIFO/An overflow occurs in the FIFO/All Message Buffers */
  CM7_FLEXCAN15_INT0_8_IRQn    = 136,              /**< CAN bus went to Bus Off state/CAN has completed the Bus Off count process (it has counted 11 recessive bits 128 times) and is ready for bus off recover/Errors detected on the CAN bus/Errors detected on the CAN bus for FD messages in the Fast Bit Rate region/Transmit Error Counter transition from < 96 to >= 96/Receive Error Counter transition from < 96 to >= 96/Correctable error detected in memory read access/Non-correctable error detected in memory read access by host (cpu)/Non-correctable error detected in memory read access by CAN */
  CM7_FLEXCAN15_INT9_15_IRQn   = 137,              /**< The number of messages stored in FIFO is greater than the FIFO watermarker/At least one message stored in FIFO/An underflow occurs in the FIFO/An overflow occurs in the FIFO/All Message Buffers */
  CM7_FLEXCAN16_INT0_8_IRQn    = 138,              /**< CAN bus went to Bus Off state/CAN has completed the Bus Off count process (it has counted 11 recessive bits 128 times) and is ready for bus off recover/Errors detected on the CAN bus/Errors detected on the CAN bus for FD messages in the Fast Bit Rate region/Transmit Error Counter transition from < 96 to >= 96/Receive Error Counter transition from < 96 to >= 96/Correctable error detected in memory read access/Non-correctable error detected in memory read access by host (cpu)/Non-correctable error detected in memory read access by CAN */
  CM7_FLEXCAN16_INT9_15_IRQn   = 139,              /**< The number of messages stored in FIFO is greater than the FIFO watermarker/At least one message stored in FIFO/An underflow occurs in the FIFO/An overflow occurs in the FIFO/All Message Buffers */
  CM7_FLEXIO0_INT_IRQn         = 140,              /**< FlexIO */
  CM7_FLEXIO1_INT_IRQn         = 141,              /**< FlexIO */
  CM7_FLEXRAY_INT0_11_IRQn     = 142,              /**< LRAM Non-Corrected Error/DRAM Non-Corrected Error/LRAM Corrected Error/DRAM Corrected Error/Receive FIFO channel A not empty/Receive FIFO channel B not empty/Wakeup/Combined protocol status and error/Combined CHI error/Combined transmit message buffer/Combined receive message buffer/Global */
  CM7_LPI2C0_INT0_1_IRQn       = 143,              /**< Master/Slave */
  CM7_LPI2C1_INT0_1_IRQn       = 144,              /**< Master/Slave */
  CM7_LPI2C2_INT0_1_IRQn       = 145,              /**< Master/Slave */
  CM7_LPI2C3_INT0_1_IRQn       = 146,              /**< Master/Slave */
  CM7_LPSPI0_INT_IRQn          = 147,              /**< Transmit and receive data and errors */
  CM7_LPSPI1_INT_IRQn          = 148,              /**< Transmit and receive data and errors */
  CM7_LPSPI2_INT_IRQn          = 149,              /**< Transmit and receive data and errors */
  CM7_LPSPI3_INT_IRQn          = 150,              /**< Transmit and receive data and errors */
  CM7_LPSPI4_INT_IRQn          = 151,              /**< Transmit and receive data and errors */
  CM7_LPSPI5_INT_IRQn          = 152,              /**< Transmit and receive data and errors */
  CM7_LPSPI6_INT_IRQn          = 153,              /**< Transmit and receive data and errors */
  CM7_LPSPI7_INT_IRQn          = 154,              /**< Transmit and receive data and errors */
  CM7_LPUART0_INT0_1_IRQn      = 155,              /**< Transmit data and errors/Receive data and errors */
  CM7_LPUART1_INT0_1_IRQn      = 156,              /**< Transmit data and errors/Receive data and errors */
  CM7_LPUART2_INT0_1_IRQn      = 157,              /**< Transmit data and errors/Receive data and errors */
  CM7_LPUART3_INT0_1_IRQn      = 158,              /**< Transmit data and errors/Receive data and errors */
  CM7_LPUART4_INT0_1_IRQn      = 159,              /**< Transmit data and errors/Receive data and errors */
  CM7_LPUART5_INT0_1_IRQn      = 160,              /**< Transmit data and errors/Receive data and errors */
  CM7_LPUART6_INT0_1_IRQn      = 161,              /**< Transmit data and errors/Receive data and errors */
  CM7_LPUART7_INT0_1_IRQn      = 162,              /**< Transmit data and errors/Receive data and errors */
  CM7_LPUART8_INT0_1_IRQn      = 163,              /**< Transmit data and errors/Receive data and errors */
  CM7_LPUART9_INT0_1_IRQn      = 164,              /**< Transmit data and errors/Receive data and errors */
  CM7_LPUART10_INT0_1_IRQn     = 165,              /**< Transmit data and errors/Receive data and errors */
  CM7_LPUART11_INT0_1_IRQn     = 166,              /**< Transmit data and errors/Receive data and errors */
  CM7_LPUART12_INT0_1_IRQn     = 167,              /**< Transmit data and errors/Receive data and errors */
  CM7_LPUART13_INT0_1_IRQn     = 168,              /**< Transmit data and errors/Receive data and errors */
  CM7_LPUART14_INT0_1_IRQn     = 169,              /**< Transmit data and errors/Receive data and errors */
  CM7_LPUART15_INT0_1_IRQn     = 170,              /**< Transmit data and errors/Receive data and errors */
  CM7_LPUART16_INT0_1_IRQn     = 171,              /**< Transmit data and errors/Receive data and errors */
  CM7_LPUART17_INT0_1_IRQn     = 172,              /**< Transmit data and errors/Receive data and errors */
  CM7_LPUART18_INT0_1_IRQn     = 173,              /**< Transmit data and errors/Receive data and errors */
  CM7_LPUART19_INT0_1_IRQn     = 174,              /**< Transmit data and errors/Receive data and errors */
  CM7_LPUART20_INT0_1_IRQn     = 175,              /**< Transmit data and errors/Receive data and errors */
  CM7_LPUART_MSC_INT0_1_IRQn   = 176,              /**< Transmit data and errors/Receive data and errors */
  CM7_LFAST_INT0_4_IRQn        = 177,              /**< Transmit/Transmit exception/Receive/Receive exception/ICLC Receive */
  CM7_MSGINTR0_INT0_2_IRQn     = 178,              /**< Message signaled interrupt register 0/Message signaled interrupt register 1/Message signaled interrupt register 2 */
  CM7_MSGINTR1_INT0_2_IRQn     = 179,              /**< Message signaled interrupt register 0/Message signaled interrupt register 1/Message signaled interrupt register 2 */
  CM7_MSGINTR2_INT0_2_IRQn     = 180,              /**< Message signaled interrupt register 0/Message signaled interrupt register 1/Message signaled interrupt register 2 */
  CM7_MSGINTR3_INT0_2_IRQn     = 181,              /**< Message signaled interrupt register 0/Message signaled interrupt register 1/Message signaled interrupt register 2 */
  CM7_MSGINTR4_INT0_2_IRQn     = 182,              /**< Message signaled interrupt register 0/Message signaled interrupt register 1/Message signaled interrupt register 2 */
  CM7_MSGINTR5_INT0_2_IRQn     = 183,              /**< Message signaled interrupt register 0/Message signaled interrupt register 1/Message signaled interrupt register 2 */
  CM7_MSGINTR6_INT0_2_IRQn     = 184,              /**< Message signaled interrupt register 0/Message signaled interrupt register 1/Message signaled interrupt register 2 */
  CM7_MSGINTR7_INT0_2_IRQn     = 185,              /**< Message signaled interrupt register 0/Message signaled interrupt register 1/Message signaled interrupt register 2 */
  CM7_NETC_IEPRC_INT0_1_IRQn   = 186,              /**< NETC Root Complex PCI 0/NETC Root Complex PCI 1 */
  CM7_PSI50_INT0_23_IRQn       = 187,              /**< PSI5 channel 0 DMA combined; asserted when data overflow/underflow occurs or dma transfer finished/PSI5 channel 0 combined general; asserted when SENT message arrives/has an error or when the data output register request for new data or are overwritten when not ready to accept new data/PSI5 channel 0 new message received/PSI5 channel 0 message overwrite/PSI5 channel 0 error/PSI5 channel 0 combined/PSI5 channel 1 DMA combined; asserted when data overflow/underflow occurs or dma transfer finished/PSI5 channel 1 combined general; asserted when SENT message arrives/has an error or when the data output register request for new data or are overwritten when not ready to accept new data/PSI5 channel 1 new message received/PSI5 channel 1 message overwrite/PSI5 channel 1 error/PSI5 channel 1 combined/PSI5 channel 2 DMA combined; asserted when data overflow/underflow occurs or dma transfer finished/PSI5 channel 2 combined general; asserted when SENT message arrives/has an error or when the data output register request for new data or are overwritten when not ready to accept new data/PSI5 channel 2 new message received/PSI5 channel 2 message overwrite/PSI5 channel 2 error/PSI5 channel 2 combined/PSI5 channel 3 DMA combined; asserted when data overflow/underflow occurs or dma transfer finished/PSI5 channel 3 combined general; asserted when SENT message arrives/has an error or when the data output register request for new data or are overwritten when not ready to accept new data/PSI5 channel 3 new message received/PSI5 channel 3 message overwrite/PSI5 channel 3 error/PSI5 channel 3 combined */
  CM7_PSI51_INT0_23_IRQn       = 188,              /**< PSI5 channel 0 DMA combined; asserted when data overflow/underflow occurs or dma transfer finished/PSI5 channel 0 combined general; asserted when SENT message arrives/has an error or when the data output register request for new data or are overwritten when not ready to accept new data/PSI5 channel 0 new message received/PSI5 channel 0 message overwrite/PSI5 channel 0 error/PSI5 channel 0 combined/PSI5 channel 1 DMA combined; asserted when data overflow/underflow occurs or dma transfer finished/PSI5 channel 1 combined general; asserted when SENT message arrives/has an error or when the data output register request for new data or are overwritten when not ready to accept new data/PSI5 channel 1 new message received/PSI5 channel 1 message overwrite/PSI5 channel 1 error/PSI5 channel 1 combined/PSI5 channel 2 DMA combined; asserted when data overflow/underflow occurs or dma transfer finished/PSI5 channel 2 combined general; asserted when SENT message arrives/has an error or when the data output register request for new data or are overwritten when not ready to accept new data/PSI5 channel 2 new message received/PSI5 channel 2 message overwrite/PSI5 channel 2 error/PSI5 channel 2 combined/PSI5 channel 3 DMA combined; asserted when data overflow/underflow occurs or dma transfer finished/PSI5 channel 3 combined general; asserted when SENT message arrives/has an error or when the data output register request for new data or are overwritten when not ready to accept new data/PSI5 channel 3 new message received/PSI5 channel 3 message overwrite/PSI5 channel 3 error/PSI5 channel 3 combined */
  CM7_PSI5_S0_INT0_18_IRQn     = 189,              /**< PS_SR_IRQ[0]/PS_SR_IRQ[1]/PS_SR_IRQ[2]/PS_SR_IRQ[3]/PS_SR_IRQ[4]/PS_SR_IRQ[5]/PS_SR_IRQ[6]/PS_SR_IRQ[7]/PSI5_E2SSR[1]/PSI5_E2SSR[2]/PSI5_E2SSR[3]/PSI5_E2SSR[4]/PSI5_E2SSR[5]/PSI5_E2SSR[6]/PSI5_E2SSR[7]/PS_GLSR/PSI5_S_0_UART_RX/PSI5_S_0_UART_TX/PSI5_S_0_UART_ERR */
  CM7_PSI5_S1_INT0_18_IRQn     = 190,              /**< PS_SR_IRQ[0]/PS_SR_IRQ[1]/PS_SR_IRQ[2]/PS_SR_IRQ[3]/PS_SR_IRQ[4]/PS_SR_IRQ[5]/PS_SR_IRQ[6]/PS_SR_IRQ[7]/PSI5_E2SSR[1]/PSI5_E2SSR[2]/PSI5_E2SSR[3]/PSI5_E2SSR[4]/PSI5_E2SSR[5]/PSI5_E2SSR[6]/PSI5_E2SSR[7]/PS_GLSR/PSI5_S_0_UART_RX/PSI5_S_0_UART_TX/PSI5_S_0_UART_ERR */
  CM7_RXLUT_INT_IRQn           = 191,              /**< RXLUT */
  CM7_SIPI_INT0_IRQn           = 192,              /**< Read channel 2 */
  CM7_SIPI_INT1_6_IRQn         = 193,              /**< Read channel 1/Read channel 3/Read channel 4/Error 1/Error 2/Trigger command */
  CM7_SAI0_INT0_1_IRQn         = 195,              /**< Receive/Transmit */
  CM7_SAI1_INT0_1_IRQn         = 196,              /**< Receive/Transmit */
  CM7_uSDHC_INT_IRQn           = 197,              /**< uSDHC */
  CM7_LPE_eDMA3_TCD0_1_INT_IRQn = 199,             /**< DMA transfer complete and error channel 0/DMA transfer complete and error channel 1 */
  CM7_LPE_eDMA3_TCD2_3_INT_IRQn = 200,             /**< DMA transfer complete and error channel 2/DMA transfer complete and error channel 3 */
  CM7_LPE_eDMA3_TCD4_5_INT_IRQn = 201,             /**< DMA transfer complete and error channel 4/DMA transfer complete and error channel 5 */
  CM7_LPE_eDMA3_TCD6_7_INT_IRQn = 202,             /**< DMA transfer complete and error channel 6/DMA transfer complete and error channel 7 */
  CM7_LPE_eDMA3_TCD8_9_INT_IRQn = 203,             /**< DMA transfer complete and error channel 8/DMA transfer complete and error channel 9 */
  CM7_LPE_eDMA3_TCD10_11_INT_IRQn = 204,           /**< DMA transfer complete and error channel 10/DMA transfer complete and error channel 11 */
  CM7_LPE_XRDC_INT_IRQn        = 205,              /**< Transfer error */
  CM7_LPE_PMC_INT0_3_IRQn      = 208,              /**< Low-voltage detect on VDD_LVDS < 1.7V (LVDLVDSF flag)/Low-voltage detect VDD_HV_B < 3.0V (LVDB33F flag) and VDD_HV_B < 1.7V (LVDB18F flag)/High-voltage detect > x.xV (HVDxF flags) */
  CM7_LPE_MC_RGM_INT_IRQn      = 209,              /**< RGM */
  CM7_LPE_SWT_INT_IRQn         = 210,              /**< Initial time-out */
  CM7_LPE_SIUL2_INT_IRQn       = 211,              /**< Vector 0 */
  CM7_LPE_WKPU_INT0_8_IRQn     = 212,              /**< Group 0/Group 1/Group 2/Group 3/Group 4/Group 5/Group 6/Group 7/Group 8 */
  CM7_0_LPE_WKPU_INT10_IRQn    = 213,              /**< Per core: Active low non-maskable request 1 */
  CM7_1_LPE_WKPU_INT11_IRQn    = 213,              /**< Per core: Active low non-maskable request 2 */
  CM7_2_LPE_WKPU_INT12_IRQn    = 213,              /**< Per core: Active low non-maskable request 3 */
  CM7_3_LPE_WKPU_INT13_IRQn    = 213,              /**< Per core: Active low non-maskable request 4 */
  CM7_LPE_CXPI0_INT_IRQn       = 214,              /**< ORed arbitration loss, dominant timeout, wakeup pulse reception */
  CM7_LPE_CXPI1_INT_IRQn       = 215,              /**< ORed arbitration loss, dominant timeout, wakeup pulse reception */
  CM7_LPE_ERM_INT0_1_IRQn      = 216,              /**< Single-bit correctable event/Multi-bit uncorrectable error event */
  CM7_LPE_SARADC_INT0_2_IRQn   = 217,              /**< End of conversion/Error/Analog watchdog */
  CM7_LPE_LPCMP0_INT_IRQn      = 218,              /**< Asynchronous */
  CM7_LPE_LPCMP1_INT_IRQn      = 219,              /**< Asynchronous */
  CM7_LPE_LPCMP2_INT_IRQn      = 220,              /**< Asynchronous */
  CM7_LPE_TEMPSENSE_INT0_3_IRQn = 221,             /**< Data ready 0/Comparator threshold 0/Comparator threshold 1/Comparator threshold 2 */
  CM7_LPE_BCTU_INT0_4_IRQn     = 222,              /**< ADC conversion triggered/ADC0 conversion data ready/ADC last command of list issued/FIFO1/FIFO2 */
  CM7_LPE_FTM_INT0_10_IRQn     = 223,              /**< Channel 0/Channel 1/Channel 2/Channel 3/Channel 4/Channel 5/Channel 6/Channel 7/Fault/Overflow/Reload */
  CM7_LPE_LCU_INT_IRQn         = 224,              /**< Logic Cell 0 */
  CM7_LPE_PIT_RTI_INT0_3_IRQn  = 225,              /**< Channel 0/Channel 1/Channel 2/Channel 3/Channel 4 (RTI) */
  CM7_LPE_RTC_API_INT0_1_IRQn  = 226,              /**< RTC compare and counter overflow/API compare */
  CM7_LPE_STM_INT0_3_IRQn      = 227,              /**< Channel 0/Channel 1/Channel 2/Channel 3 */
  CM7_LPE_FLEXCAN_INT0_8_IRQn  = 228,              /**< CAN bus went to Bus Off state/CAN has completed the Bus Off count process (it has counted 11 recessive bits 128 times) and is ready for bus off recover/Errors detected on the CAN bus/Errors detected on the CAN bus for FD messages in the Fast Bit Rate region/Transmit Error Counter transition from < 96 to >= 96/Receive Error Counter transition from < 96 to >= 96/Correctable error detected in memory read access/Non-correctable error detected in memory read access by host (cpu)/Non-correctable error detected in memory read access by CAN */
  CM7_LPE_FLEXCAN_INT9_15_IRQn = 229,              /**< The number of messages stored in FIFO is greater than the FIFO watermarker/At least one message stored in FIFO/An underflow occurs in the FIFO/An overflow occurs in the FIFO/All Message Buffers */
  CM7_LPE_LPI2C_INT0_3_IRQn    = 230,              /**< Master/Asynchronous master/Slave/Asynchronous slave */
  CM7_LPE_LPSPI0_INT0_1_IRQn   = 231,              /**< Transmit and receive data and errors/Asynchronous */
  CM7_LPE_LPSPI1_INT0_1_IRQn   = 232,              /**< Transmit and receive data and errors/Asynchronous */
  CM7_LPE_LPUART0_INT0_3_IRQn  = 233,              /**< Transmit data and errors/Asynchronous transmit/Receive data and errors/Asynchronous receive */
  CM7_LPE_LPUART1_INT0_3_IRQn  = 234,              /**< Transmit data and errors/Asynchronous transmit/Receive data and errors/Asynchronous receive */
  CM7_LPE_LPUART2_INT0_3_IRQn  = 235,              /**< Transmit data and errors/Asynchronous transmit/Receive data and errors/Asynchronous receive */
  CM7_CPE_XRDC_INT_IRQn        = 237               /**< Transfer Error */
} IRQn_Type;

/*!
 * @}
 */ /* end of group Interrupt_vector_numbers */


/* ----------------------------------------------------------------------------
   -- Cortex M7 Core Configuration
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Cortex_Core_Configuration Cortex M7 Core Configuration
 * @{
 */

#define __MPU_PRESENT                  1         /**< Defines if an MPU is present or not */
#define __ICACHE_PRESENT               1         /**< Defines if an ICACHE is present or not */
#define __DCACHE_PRESENT               1         /**< Defines if an DCACHE is present or not */
#define __DTCM_PRESENT                 1         /**< Defines if an DTCM is present or not */
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


#endif  /* #if !defined(S32K566_M7_COMMON_H_) */

