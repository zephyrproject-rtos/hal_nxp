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
#if !defined(S32K566_R52_COMMON_H_)  /* Check if memory map has not been already included */
#define S32K566_R52_COMMON_H_
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
#define NUMBER_OF_INT_VECTORS 344                /**< Number of interrupts in the Vector table */

typedef enum {
  /* Auxiliary constants */
  NotAvail_IRQn                = -128,             /**< Not available device specific interrupt */

  /* Device specific interrupts */
  R52_SGI_1_INT_IRQn           = 0,                /**< Software Generated Interrupt 1 */
  R52_SGI_2_INT_IRQn           = 1,                /**< Software Generated Interrupt 2 */
  R52_SGI_3_INT_IRQn           = 2,                /**< Software Generated Interrupt 3 */
  R52_SGI_4_INT_IRQn           = 3,                /**< Software Generated Interrupt 4 */
  R52_SGI_5_INT_IRQn           = 4,                /**< Software Generated Interrupt 5 */
  R52_SGI_6_INT_IRQn           = 5,                /**< Software Generated Interrupt 6 */
  R52_SGI_7_INT_IRQn           = 6,                /**< Software Generated Interrupt 7 */
  R52_SGI_8_INT_IRQn           = 7,                /**< Software Generated Interrupt 8 */
  R52_SGI_9_INT_IRQn           = 8,                /**< Software Generated Interrupt 9 */
  R52_SGI_10_INT_IRQn          = 9,                /**< Software Generated Interrupt 10 */
  R52_SGI_11_INT_IRQn          = 10,               /**< Software Generated Interrupt 11 */
  R52_SGI_12_INT_IRQn          = 11,               /**< Software Generated Interrupt 12 */
  R52_SGI_13_INT_IRQn          = 12,               /**< Software Generated Interrupt 13 */
  R52_SGI_14_INT_IRQn          = 13,               /**< Software Generated Interrupt 14 */
  R52_SGI_15_INT_IRQn          = 14,               /**< Software Generated Interrupt 15 */
  R52_SGI_16_INT_IRQn          = 15,               /**< Software Generated Interrupt 16 */
  R52_COMM_INT_IRQn            = 22,               /**< Per core: Debug Communications Channel */
  R52_PMU_INT_IRQn             = 23,               /**< Per core: Performance Monitor Counter Overflow */
  R52_CTI_INT_IRQn             = 24,               /**< Per core: Cross Trigger Interface */
  R52_MAINTENANCE_INT_IRQn     = 25,               /**< Per core: Virtual CPU Interface Maintenance */
  R52_HYPERV_TIM_INT_IRQn      = 26,               /**< Per core: Hypervisor Timer */
  R52_VIRTUAL_TIM_INT_IRQn     = 27,               /**< Per core: Virtual Timer */
  R52_EL1_TIM_INT_IRQn         = 30,               /**< Per core: Non-secure EL1  Physical Timer */
  R52_DSP_INT0_IRQn            = 32,               /**< ORed requests to MU0 */
  R52_DSP_INT1_IRQn            = 33,               /**< ORed requests to MU1 */
  R52_DSP_INT2_IRQn            = 34,               /**< ORed requests to MU2 */
  R52_DSP_INT3_IRQn            = 35,               /**< ORed requests to MU3 */
  R52_eDMA5_TCD0_2_INT_IRQn    = 36,               /**< DMA transfer complete and error channel 0/DMA transfer complete and error channel 1 */
  R52_eDMA5_TCD2_3_INT_IRQn    = 37,               /**< DMA transfer complete and error channel 2/DMA transfer complete and error channel 3 */
  R52_eDMA5_TCD4_5_INT_IRQn    = 38,               /**< DMA transfer complete and error channel 4/DMA transfer complete and error channel 5 */
  R52_eDMA5_TCD6_7_INT_IRQn    = 39,               /**< DMA transfer complete and error channel 6/DMA transfer complete and error channel 7 */
  R52_eDMA5_TCD8_9_INT_IRQn    = 40,               /**< DMA transfer complete and error channel 8/DMA transfer complete and error channel 9 */
  R52_eDMA5_TCD10_11_INT_IRQn  = 41,               /**< DMA transfer complete and error channel 10/DMA transfer complete and error channel 11 */
  R52_eDMA5_TCD12_13_INT_IRQn  = 42,               /**< DMA transfer complete and error channel 12/DMA transfer complete and error channel 13 */
  R52_eDMA5_TCD14_15_INT_IRQn  = 43,               /**< DMA transfer complete and error channel 14/DMA transfer complete and error channel 15 */
  R52_eDMA5_TCD16_17_INT_IRQn  = 44,               /**< DMA transfer complete and error channel 16/DMA transfer complete and error channel 17 */
  R52_eDMA5_TCD18_19_INT_IRQn  = 45,               /**< DMA transfer complete and error channel 18/DMA transfer complete and error channel 19 */
  R52_eDMA5_TCD20_21_INT_IRQn  = 46,               /**< DMA transfer complete and error channel 20/DMA transfer complete and error channel 21 */
  R52_eDMA5_TCD22_23_INT_IRQn  = 47,               /**< DMA transfer complete and error channel 22/DMA transfer complete and error channel 23 */
  R52_eDMA5_TCD24_25_INT_IRQn  = 48,               /**< DMA transfer complete and error channel 24/DMA transfer complete and error channel 25 */
  R52_eDMA5_TCD26_27_INT_IRQn  = 49,               /**< DMA transfer complete and error channel 26/DMA transfer complete and error channel 27 */
  R52_eDMA5_TCD28_29_INT_IRQn  = 50,               /**< DMA transfer complete and error channel 28/DMA transfer complete and error channel 29 */
  R52_eDMA5_TCD30_31_INT_IRQn  = 51,               /**< DMA transfer complete and error channel 30/DMA transfer complete and error channel 31 */
  R52_XRDC_A_C_INT_IRQn        = 52,               /**< Transfer error/Transfer error/Transfer error */
  R52_MRAMC_INT_IRQn           = 53,               /**< AXI bufferable write error */
  R52_NEUTRON_ACCEL_INT0_1_IRQn = 54,              /**< Functional/Fault */
  R52_SWT_STARTUP_INT_IRQn     = 55,               /**< Initial time-out */
  R52_SIUL2_0_INT_IRQn         = 56,               /**< Vector 0 */
  R52_SIUL2_1_INT_IRQn         = 57,               /**< Vector 0 */
  R52_SIUL2_3_INT_IRQn         = 58,               /**< Vector 0 */
  R52_SIUL2_4_INT_IRQn         = 59,               /**< Vector 0 */
  R52_CSTCU_INT_IRQn           = 63,               /**< Self-test complete */
  R52_VFCCU_INT5_IRQn          = 64,               /**< Per core: Central FCCU reaction 5 */
  R52_VFCCU_INT6_IRQn          = 65,               /**< Per core: Central FCCU reaction 6 */
  R52_VFCCU_INT7_IRQn          = 66,               /**< Per core: Central FCCU reaction 7 */
  R52_VFCCU_INT8_IRQn          = 67,               /**< Central FCCU reaction index0 */
  R52_VFCCU_INT9_IRQn          = 68,               /**< Central FCCU reaction index1 */
  R52_ERM0_INT0_1_IRQn         = 70,               /**< Single-bit correctable event/Multi-bit uncorrectable error event */
  R52_ERM1_INT0_1_IRQn         = 71,               /**< Single-bit correctable event/Multi-bit uncorrectable error event */
  R52_ERM2_INT0_1_IRQn         = 72,               /**< Single-bit correctable event/Multi-bit uncorrectable error event */
  R52_ERM3_INT0_1_IRQn         = 73,               /**< Single-bit correctable event/Multi-bit uncorrectable error event */
  R52_ERM4_INT0_1_IRQn         = 74,               /**< Single-bit correctable event/Multi-bit uncorrectable error event */
  R52_ERM5_INT0_1_IRQn         = 75,               /**< Single-bit correctable event/Multi-bit uncorrectable error event */
  R52_AES_ACCEL_INT0_2_IRQn    = 76,               /**< Application 0/Application 0 timeout/Application 0 keystore error */
  R52_AES_ACCEL_INT3_5_IRQn    = 77,               /**< Application 1/Application 1 timeout/Application 1 keystore error */
  R52_AES_ACCEL_INT6_8_IRQn    = 78,               /**< Application 2/Application 2 timeout/Application 2 keystore error */
  R52_AES_ACCEL_INT9_11_IRQn   = 79,               /**< Application 3/Application 3 timeout/Application 3 keystore error */
  R52_AES_ACCEL_INT12_14_IRQn  = 80,               /**< Application 4/Application 4 timeout/Application 4 keystore error */
  R52_AES_ACCEL_INT15_17_IRQn  = 81,               /**< Application 5/Application 5 timeout/Application 5 keystore error */
  R52_AES_ACCEL_INT18_20_IRQn  = 82,               /**< Application 6/Application 6 timeout/Application 6 keystore error */
  R52_AES_ACCEL_INT21_23_IRQn  = 83,               /**< Application 7/Application 7 timeout/Application 7 keystore error */
  R52_AES_ACCEL_INT24_25_IRQn  = 84,               /**< Feed DMA error/Result DMA error */
  R52_SENTMU0_INT0_2_IRQn      = 85,               /**< ORed TX request to MU0A/ORed RX request to MU0A/ORed general purpose request to MU0A */
  R52_SENTMU1_INT0_2_IRQn      = 86,               /**< ORed TX request to MU1A/ORed RX request to MU1A/ORed general purpose request to MU1A */
  R52_SENTMU2_INT0_2_IRQn      = 87,               /**< ORed TX request to MU2A/ORed RX request to MU2A/ORed general purpose request to MU2A */
  R52_SENTMU3_INT0_2_IRQn      = 88,               /**< ORed TX request to MU3A/ORed RX request to MU3A/ORed general purpose request to MU3A */
  R52_SENTMU4_INT0_2_IRQn      = 89,               /**< ORed TX request to MU4A/ORed RX request to MU4A/ORed general purpose request to MU4A */
  R52_SENTMU5_INT0_2_IRQn      = 90,               /**< ORed TX request to MU5A/ORed RX request to MU5A/ORed general purpose request to MU5A */
  R52_SENTMU6_INT0_2_IRQn      = 91,               /**< ORed TX request to MU6A/ORed RX request to MU6A/ORed general purpose request to MU6A */
  R52_SENTMU7_INT0_2_IRQn      = 92,               /**< ORed TX request to MU7A/ORed RX request to MU7A/ORed general purpose request to MU7A */
  R52_SARADC0_INT0_2_IRQn      = 93,               /**< End of conversion/Error/Analog watchdog */
  R52_SARADC1_INT0_2_IRQn      = 94,               /**< End of conversion/Error/Analog watchdog */
  R52_BCTU_INT0_5_IRQn         = 95,               /**< ADC conversion triggered/ADC0 conversion data ready/ADC1 conversion data ready/ADC last command of list issued/FIFO1/FIFO2 */
  R52_eMIOS0_INT0_3_IRQn       = 96,               /**< Channel 0/Channel 1/Channel 2/Channel 3 */
  R52_eMIOS0_INT4_7_IRQn       = 97,               /**< Channel 4/Channel 5/Channel 6/Channel 7 */
  R52_eMIOS0_INT8_11_IRQn      = 98,               /**< Channel 8/Channel 9/Channel 10/Channel 11 */
  R52_eMIOS0_INT12_15_IRQn     = 99,               /**< Channel 12/Channel 13/Channel 14/Channel 15 */
  R52_eMIOS0_INT16_19_IRQn     = 100,              /**< Channel 16/Channel 17/Channel 18/Channel 19 */
  R52_eMIOS0_INT20_23_IRQn     = 101,              /**< Channel 20/Channel 21/Channel 22/Channel 23 */
  R52_eMIOS1_INT0_3_IRQn       = 102,              /**< Channel 0/Channel 1/Channel 2/Channel 3 */
  R52_eMIOS1_INT4_7_IRQn       = 103,              /**< Channel 4/Channel 5/Channel 6/Channel 7 */
  R52_eMIOS1_INT8_11_IRQn      = 104,              /**< Channel 8/Channel 9/Channel 10/Channel 11 */
  R52_eMIOS1_INT12_15_IRQn     = 105,              /**< Channel 12/Channel 13/Channel 14/Channel 15 */
  R52_eMIOS1_INT16_19_IRQn     = 106,              /**< Channel 16/Channel 17/Channel 18/Channel 19 */
  R52_eMIOS1_INT20_23_IRQn     = 107,              /**< Channel 20/Channel 21/Channel 22/Channel 23 */
  R52_eMIOS2_INT0_3_IRQn       = 108,              /**< Channel 0/Channel 1/Channel 2/Channel 3 */
  R52_eMIOS2_INT4_7_IRQn       = 109,              /**< Channel 4/Channel 5/Channel 6/Channel 7 */
  R52_eMIOS2_INT8_11_IRQn      = 110,              /**< Channel 8/Channel 9/Channel 10/Channel 11 */
  R52_eMIOS2_INT12_15_IRQn     = 111,              /**< Channel 12/Channel 13/Channel 14/Channel 15 */
  R52_eMIOS2_INT16_19_IRQn     = 112,              /**< Channel 16/Channel 17/Channel 18/Channel 19 */
  R52_eMIOS2_INT20_23_IRQn     = 113,              /**< Channel 20/Channel 21/Channel 22/Channel 23 */
  R52_GTM_INT0_28_IRQn         = 114,              /**< GTM ERR/GTM AEI/GTM ARU/GTM BRC/GTM SPE0/GTM SPE1/GTM CMP/GTM PSM0/GTM DPLL/GTM TIM0/GTM TIM1/GTM TIM2/GTM MCS0/GTM MCS1/GTM MCS2/GTM MCS3/GTM MCS0_S/GTM MCS1_S/GTM MCS2_S/GTM MCS3_S/GTM TOM0/GTM TOM1/GTM TIO1_G0/GTM TIO2_G0/GTM TIO3_G0/GTM ATOM0/GTM ATOM1/GTM ATOM2/GTM ATOM3 */
  R52_LCU0_INT0_2_IRQn         = 115,              /**< Logic Cell 0/Logic Cell 1/Logic Cell 2 */
  R52_LCU1_INT0_2_IRQn         = 116,              /**< Logic Cell 0/Logic Cell 1/Logic Cell 2 */
  R52_SINC_INT0_3_IRQn         = 117,              /**< Channel 0/Channel 1/Channel 2/Channel 3 */
  R52_CANXL0_INT0_20_IRQn      = 118,              /**< CAN frame transmission from one of the Tx message buffers 0-31 completed/CAN frame transmission from one of the Tx message buffers 32-63 completed/CAN frame reception into one of the Rx message buffers 0-31 completed/CAN frame reception into one of the Rx message buffers 32-63 completed/The Rx FIFO used for reception of selected CAN frames has reached its programmable threshold/The Rx FIFO used for reception of selected CAN frames has experienced underflow or overflow/Message Receive Unit/Protocol engine error occurred related to reception or transmission of CAN frames/Receive Error Counter Interrupt/Transmit Error Counter Interrupt/Bus Off Recovery Ready Interrupt/Bus Off Interrupt/Protocol Exception Error Interrupt/Passive Error State Interrupt/Frame error during arbitration/data phase 1/Frame error during arbitration/data phase 2/Frame error during arbitration/data phase 3/Internal exception is detected/Non-correctable error occurred within internal data RAM/Correctable error occurred within internal data RAM/IP has entered or exited freeze mode */
  R52_CANXL1_INT0_20_IRQn      = 119,              /**< CAN frame transmission from one of the Tx message buffers 0-31 completed/CAN frame transmission from one of the Tx message buffers 32-63 completed/CAN frame reception into one of the Rx message buffers 0-31 completed/CAN frame reception into one of the Rx message buffers 32-63 completed/The Rx FIFO used for reception of selected CAN frames has reached its programmable threshold/The Rx FIFO used for reception of selected CAN frames has experienced underflow or overflow/Message Receive Unit/Protocol engine error occurred related to reception or transmission of CAN frames/Receive Error Counter Interrupt/Transmit Error Counter Interrupt/Bus Off Recovery Ready Interrupt/Bus Off Interrupt/Protocol Exception Error Interrupt/Passive Error State Interrupt/Frame error during arbitration/data phase 1/Frame error during arbitration/data phase 2/Frame error during arbitration/data phase 3/Internal exception is detected/Non-correctable error occurred within internal data RAM/Correctable error occurred within internal data RAM/IP has entered or exited freeze mode */
  R52_TENBASET_PHY0_INT_IRQn   = 120,              /**< Physical collision */
  R52_TENBASET_PHY1_INT_IRQn   = 121,              /**< Physical collision */
  R52_TENBASET_PHY2_INT_IRQn   = 122,              /**< Physical collision */
  R52_TENBASET_PHY3_INT_IRQn   = 123,              /**< Physical collision */
  R52_DSPI_MSC0_INT_IRQn       = 124,              /**< DSPI Global (OR of all lines) */
  R52_DSPI_MSC1_INT_IRQn       = 125,              /**< DSPI Global (OR of all lines) */
  R52_XSPI_INT0_1_IRQn         = 126,              /**< XSPI/FlashA ECC error */
  R52_FLEXCAN0_INT0_8_IRQn     = 127,              /**< CAN bus went to Bus Off state/CAN has completed the Bus Off count process (it has counted 11 recessive bits 128 times) and is ready for bus off recover/Errors detected on the CAN bus/Errors detected on the CAN bus for FD messages in the Fast Bit Rate region/Transmit Error Counter transition from < 96 to >= 96/Receive Error Counter transition from < 96 to >= 96/Correctable error detected in memory read access/Non-correctable error detected in memory read access by host (cpu)/Non-correctable error detected in memory read access by CAN */
  R52_FLEXCAN0_INT9_15_IRQn    = 128,              /**< The number of messages stored in FIFO is greater than the FIFO watermarker/At least one message stored in FIFO/An underflow occurs in the FIFO/An overflow occurs in the FIFO/All Message Buffers */
  R52_FLEXCAN1_INT0_8_IRQn     = 129,              /**< CAN bus went to Bus Off state/CAN has completed the Bus Off count process (it has counted 11 recessive bits 128 times) and is ready for bus off recover/Errors detected on the CAN bus/Errors detected on the CAN bus for FD messages in the Fast Bit Rate region/Transmit Error Counter transition from < 96 to >= 96/Receive Error Counter transition from < 96 to >= 96/Correctable error detected in memory read access/Non-correctable error detected in memory read access by host (cpu)/Non-correctable error detected in memory read access by CAN */
  R52_FLEXCAN1_INT9_15_IRQn    = 130,              /**< The number of messages stored in FIFO is greater than the FIFO watermarker/At least one message stored in FIFO/An underflow occurs in the FIFO/An overflow occurs in the FIFO/All Message Buffers */
  R52_FLEXCAN2_INT0_8_IRQn     = 131,              /**< CAN bus went to Bus Off state/CAN has completed the Bus Off count process (it has counted 11 recessive bits 128 times) and is ready for bus off recover/Errors detected on the CAN bus/Errors detected on the CAN bus for FD messages in the Fast Bit Rate region/Transmit Error Counter transition from < 96 to >= 96/Receive Error Counter transition from < 96 to >= 96/Correctable error detected in memory read access/Non-correctable error detected in memory read access by host (cpu)/Non-correctable error detected in memory read access by CAN */
  R52_FLEXCAN2_INT9_15_IRQn    = 132,              /**< The number of messages stored in FIFO is greater than the FIFO watermarker/At least one message stored in FIFO/An underflow occurs in the FIFO/An overflow occurs in the FIFO/All Message Buffers */
  R52_FLEXCAN3_INT0_8_IRQn     = 133,              /**< CAN bus went to Bus Off state/CAN has completed the Bus Off count process (it has counted 11 recessive bits 128 times) and is ready for bus off recover/Errors detected on the CAN bus/Errors detected on the CAN bus for FD messages in the Fast Bit Rate region/Transmit Error Counter transition from < 96 to >= 96/Receive Error Counter transition from < 96 to >= 96/Correctable error detected in memory read access/Non-correctable error detected in memory read access by host (cpu)/Non-correctable error detected in memory read access by CAN */
  R52_FLEXCAN3_INT9_15_IRQn    = 134,              /**< The number of messages stored in FIFO is greater than the FIFO watermarker/At least one message stored in FIFO/An underflow occurs in the FIFO/An overflow occurs in the FIFO/All Message Buffers */
  R52_FLEXCAN4_INT0_8_IRQn     = 135,              /**< CAN bus went to Bus Off state/CAN has completed the Bus Off count process (it has counted 11 recessive bits 128 times) and is ready for bus off recover/Errors detected on the CAN bus/Errors detected on the CAN bus for FD messages in the Fast Bit Rate region/Transmit Error Counter transition from < 96 to >= 96/Receive Error Counter transition from < 96 to >= 96/Correctable error detected in memory read access/Non-correctable error detected in memory read access by host (cpu)/Non-correctable error detected in memory read access by CAN */
  R52_FLEXCAN4_INT9_15_IRQn    = 136,              /**< The number of messages stored in FIFO is greater than the FIFO watermarker/At least one message stored in FIFO/An underflow occurs in the FIFO/An overflow occurs in the FIFO/All Message Buffers */
  R52_FLEXCAN5_INT0_8_IRQn     = 137,              /**< CAN bus went to Bus Off state/CAN has completed the Bus Off count process (it has counted 11 recessive bits 128 times) and is ready for bus off recover/Errors detected on the CAN bus/Errors detected on the CAN bus for FD messages in the Fast Bit Rate region/Transmit Error Counter transition from < 96 to >= 96/Receive Error Counter transition from < 96 to >= 96/Correctable error detected in memory read access/Non-correctable error detected in memory read access by host (cpu)/Non-correctable error detected in memory read access by CAN */
  R52_FLEXCAN5_INT9_15_IRQn    = 138,              /**< The number of messages stored in FIFO is greater than the FIFO watermarker/At least one message stored in FIFO/An underflow occurs in the FIFO/An overflow occurs in the FIFO/All Message Buffers */
  R52_FLEXCAN6_INT0_8_IRQn     = 139,              /**< CAN bus went to Bus Off state/CAN has completed the Bus Off count process (it has counted 11 recessive bits 128 times) and is ready for bus off recover/Errors detected on the CAN bus/Errors detected on the CAN bus for FD messages in the Fast Bit Rate region/Transmit Error Counter transition from < 96 to >= 96/Receive Error Counter transition from < 96 to >= 96/Correctable error detected in memory read access/Non-correctable error detected in memory read access by host (cpu)/Non-correctable error detected in memory read access by CAN */
  R52_FLEXCAN6_INT9_15_IRQn    = 140,              /**< The number of messages stored in FIFO is greater than the FIFO watermarker/At least one message stored in FIFO/An underflow occurs in the FIFO/An overflow occurs in the FIFO/All Message Buffers */
  R52_FLEXCAN7_INT0_8_IRQn     = 141,              /**< CAN bus went to Bus Off state/CAN has completed the Bus Off count process (it has counted 11 recessive bits 128 times) and is ready for bus off recover/Errors detected on the CAN bus/Errors detected on the CAN bus for FD messages in the Fast Bit Rate region/Transmit Error Counter transition from < 96 to >= 96/Receive Error Counter transition from < 96 to >= 96/Correctable error detected in memory read access/Non-correctable error detected in memory read access by host (cpu)/Non-correctable error detected in memory read access by CAN */
  R52_FLEXCAN7_INT9_15_IRQn    = 142,              /**< The number of messages stored in FIFO is greater than the FIFO watermarker/At least one message stored in FIFO/An underflow occurs in the FIFO/An overflow occurs in the FIFO/All Message Buffers */
  R52_FLEXCAN8_INT0_8_IRQn     = 143,              /**< CAN bus went to Bus Off state/CAN has completed the Bus Off count process (it has counted 11 recessive bits 128 times) and is ready for bus off recover/Errors detected on the CAN bus/Errors detected on the CAN bus for FD messages in the Fast Bit Rate region/Transmit Error Counter transition from < 96 to >= 96/Receive Error Counter transition from < 96 to >= 96/Correctable error detected in memory read access/Non-correctable error detected in memory read access by host (cpu)/Non-correctable error detected in memory read access by CAN */
  R52_FLEXCAN8_INT9_15_IRQn    = 144,              /**< The number of messages stored in FIFO is greater than the FIFO watermarker/At least one message stored in FIFO/An underflow occurs in the FIFO/An overflow occurs in the FIFO/All Message Buffers */
  R52_FLEXCAN9_INT0_8_IRQn     = 145,              /**< CAN bus went to Bus Off state/CAN has completed the Bus Off count process (it has counted 11 recessive bits 128 times) and is ready for bus off recover/Errors detected on the CAN bus/Errors detected on the CAN bus for FD messages in the Fast Bit Rate region/Transmit Error Counter transition from < 96 to >= 96/Receive Error Counter transition from < 96 to >= 96/Correctable error detected in memory read access/Non-correctable error detected in memory read access by host (cpu)/Non-correctable error detected in memory read access by CAN */
  R52_FLEXCAN9_INT9_15_IRQn    = 146,              /**< The number of messages stored in FIFO is greater than the FIFO watermarker/At least one message stored in FIFO/An underflow occurs in the FIFO/An overflow occurs in the FIFO/All Message Buffers */
  R52_FLEXCAN10_INT0_8_IRQn    = 147,              /**< CAN bus went to Bus Off state/CAN has completed the Bus Off count process (it has counted 11 recessive bits 128 times) and is ready for bus off recover/Errors detected on the CAN bus/Errors detected on the CAN bus for FD messages in the Fast Bit Rate region/Transmit Error Counter transition from < 96 to >= 96/Receive Error Counter transition from < 96 to >= 96/Correctable error detected in memory read access/Non-correctable error detected in memory read access by host (cpu)/Non-correctable error detected in memory read access by CAN */
  R52_FLEXCAN10_INT9_15_IRQn   = 148,              /**< The number of messages stored in FIFO is greater than the FIFO watermarker/At least one message stored in FIFO/An underflow occurs in the FIFO/An overflow occurs in the FIFO/All Message Buffers */
  R52_FLEXCAN11_INT0_8_IRQn    = 149,              /**< CAN bus went to Bus Off state/CAN has completed the Bus Off count process (it has counted 11 recessive bits 128 times) and is ready for bus off recover/Errors detected on the CAN bus/Errors detected on the CAN bus for FD messages in the Fast Bit Rate region/Transmit Error Counter transition from < 96 to >= 96/Receive Error Counter transition from < 96 to >= 96/Correctable error detected in memory read access/Non-correctable error detected in memory read access by host (cpu)/Non-correctable error detected in memory read access by CAN */
  R52_FLEXCAN11_INT9_15_IRQn   = 150,              /**< The number of messages stored in FIFO is greater than the FIFO watermarker/At least one message stored in FIFO/An underflow occurs in the FIFO/An overflow occurs in the FIFO/All Message Buffers */
  R52_FLEXCAN12_INT0_8_IRQn    = 151,              /**< CAN bus went to Bus Off state/CAN has completed the Bus Off count process (it has counted 11 recessive bits 128 times) and is ready for bus off recover/Errors detected on the CAN bus/Errors detected on the CAN bus for FD messages in the Fast Bit Rate region/Transmit Error Counter transition from < 96 to >= 96/Receive Error Counter transition from < 96 to >= 96/Correctable error detected in memory read access/Non-correctable error detected in memory read access by host (cpu)/Non-correctable error detected in memory read access by CAN */
  R52_FLEXCAN12_INT9_15_IRQn   = 152,              /**< The number of messages stored in FIFO is greater than the FIFO watermarker/At least one message stored in FIFO/An underflow occurs in the FIFO/An overflow occurs in the FIFO/All Message Buffers */
  R52_FLEXCAN13_INT0_8_IRQn    = 153,              /**< CAN bus went to Bus Off state/CAN has completed the Bus Off count process (it has counted 11 recessive bits 128 times) and is ready for bus off recover/Errors detected on the CAN bus/Errors detected on the CAN bus for FD messages in the Fast Bit Rate region/Transmit Error Counter transition from < 96 to >= 96/Receive Error Counter transition from < 96 to >= 96/Correctable error detected in memory read access/Non-correctable error detected in memory read access by host (cpu)/Non-correctable error detected in memory read access by CAN */
  R52_FLEXCAN13_INT9_15_IRQn   = 154,              /**< The number of messages stored in FIFO is greater than the FIFO watermarker/At least one message stored in FIFO/An underflow occurs in the FIFO/An overflow occurs in the FIFO/All Message Buffers */
  R52_FLEXCAN14_INT0_8_IRQn    = 155,              /**< CAN bus went to Bus Off state/CAN has completed the Bus Off count process (it has counted 11 recessive bits 128 times) and is ready for bus off recover/Errors detected on the CAN bus/Errors detected on the CAN bus for FD messages in the Fast Bit Rate region/Transmit Error Counter transition from < 96 to >= 96/Receive Error Counter transition from < 96 to >= 96/Correctable error detected in memory read access/Non-correctable error detected in memory read access by host (cpu)/Non-correctable error detected in memory read access by CAN */
  R52_FLEXCAN14_INT9_15_IRQn   = 156,              /**< The number of messages stored in FIFO is greater than the FIFO watermarker/At least one message stored in FIFO/An underflow occurs in the FIFO/An overflow occurs in the FIFO/All Message Buffers */
  R52_FLEXCAN15_INT0_8_IRQn    = 157,              /**< CAN bus went to Bus Off state/CAN has completed the Bus Off count process (it has counted 11 recessive bits 128 times) and is ready for bus off recover/Errors detected on the CAN bus/Errors detected on the CAN bus for FD messages in the Fast Bit Rate region/Transmit Error Counter transition from < 96 to >= 96/Receive Error Counter transition from < 96 to >= 96/Correctable error detected in memory read access/Non-correctable error detected in memory read access by host (cpu)/Non-correctable error detected in memory read access by CAN */
  R52_FLEXCAN15_INT9_15_IRQn   = 158,              /**< The number of messages stored in FIFO is greater than the FIFO watermarker/At least one message stored in FIFO/An underflow occurs in the FIFO/An overflow occurs in the FIFO/All Message Buffers */
  R52_FLEXCAN16_INT0_8_IRQn    = 159,              /**< CAN bus went to Bus Off state/CAN has completed the Bus Off count process (it has counted 11 recessive bits 128 times) and is ready for bus off recover/Errors detected on the CAN bus/Errors detected on the CAN bus for FD messages in the Fast Bit Rate region/Transmit Error Counter transition from < 96 to >= 96/Receive Error Counter transition from < 96 to >= 96/Correctable error detected in memory read access/Non-correctable error detected in memory read access by host (cpu)/Non-correctable error detected in memory read access by CAN */
  R52_FLEXCAN16_INT9_15_IRQn   = 160,              /**< The number of messages stored in FIFO is greater than the FIFO watermarker/At least one message stored in FIFO/An underflow occurs in the FIFO/An overflow occurs in the FIFO/All Message Buffers */
  R52_FLEXIO0_INT_IRQn         = 161,              /**< FlexIO */
  R52_FLEXIO1_INT_IRQn         = 162,              /**< FlexIO */
  R52_FLEXRAY_INT0_11_IRQn     = 163,              /**< LRAM Non-Corrected Error/DRAM Non-Corrected Error/LRAM Corrected Error/DRAM Corrected Error/Receive FIFO channel A not empty/Receive FIFO channel B not empty/Wakeup/Combined protocol status and error/Combined CHI error/Combined transmit message buffer/Combined receive message buffer/Global */
  R52_LPI2C0_INT0_1_IRQn       = 164,              /**< Master/Slave */
  R52_LPI2C1_INT0_1_IRQn       = 165,              /**< Master/Slave */
  R52_LPI2C2_INT0_1_IRQn       = 166,              /**< Master/Slave */
  R52_LPI2C3_INT0_1_IRQn       = 167,              /**< Master/Slave */
  R52_LPSPI0_INT_IRQn          = 168,              /**< Transmit and receive data and errors */
  R52_LPSPI1_INT_IRQn          = 169,              /**< Transmit and receive data and errors */
  R52_LPSPI2_INT_IRQn          = 170,              /**< Transmit and receive data and errors */
  R52_LPSPI3_INT_IRQn          = 171,              /**< Transmit and receive data and errors */
  R52_LPSPI4_INT_IRQn          = 172,              /**< Transmit and receive data and errors */
  R52_LPSPI5_INT_IRQn          = 173,              /**< Transmit and receive data and errors */
  R52_LPSPI6_INT_IRQn          = 174,              /**< Transmit and receive data and errors */
  R52_LPSPI7_INT_IRQn          = 175,              /**< Transmit and receive data and errors */
  R52_LPUART0_INT0_1_IRQn      = 176,              /**< Transmit data and errors/Receive data and errors */
  R52_LPUART1_INT0_1_IRQn      = 177,              /**< Transmit data and errors/Receive data and errors */
  R52_LPUART2_INT0_1_IRQn      = 178,              /**< Transmit data and errors/Receive data and errors */
  R52_LPUART3_INT0_1_IRQn      = 179,              /**< Transmit data and errors/Receive data and errors */
  R52_LPUART4_INT0_1_IRQn      = 180,              /**< Transmit data and errors/Receive data and errors */
  R52_LPUART5_INT0_1_IRQn      = 181,              /**< Transmit data and errors/Receive data and errors */
  R52_LPUART6_INT0_1_IRQn      = 182,              /**< Transmit data and errors/Receive data and errors */
  R52_LPUART7_INT0_1_IRQn      = 183,              /**< Transmit data and errors/Receive data and errors */
  R52_LPUART8_INT0_1_IRQn      = 184,              /**< Transmit data and errors/Receive data and errors */
  R52_LPUART9_INT0_1_IRQn      = 185,              /**< Transmit data and errors/Receive data and errors */
  R52_LPUART10_INT0_1_IRQn     = 186,              /**< Transmit data and errors/Receive data and errors */
  R52_LPUART11_INT0_1_IRQn     = 187,              /**< Transmit data and errors/Receive data and errors */
  R52_LPUART12_INT0_1_IRQn     = 188,              /**< Transmit data and errors/Receive data and errors */
  R52_LPUART13_INT0_1_IRQn     = 189,              /**< Transmit data and errors/Receive data and errors */
  R52_LPUART14_INT0_1_IRQn     = 190,              /**< Transmit data and errors/Receive data and errors */
  R52_LPUART15_INT0_1_IRQn     = 191,              /**< Transmit data and errors/Receive data and errors */
  R52_LPUART16_INT0_1_IRQn     = 192,              /**< Transmit data and errors/Receive data and errors */
  R52_LPUART17_INT0_1_IRQn     = 193,              /**< Transmit data and errors/Receive data and errors */
  R52_LPUART18_INT0_1_IRQn     = 194,              /**< Transmit data and errors/Receive data and errors */
  R52_LPUART19_INT0_1_IRQn     = 195,              /**< Transmit data and errors/Receive data and errors */
  R52_LPUART20_INT0_1_IRQn     = 196,              /**< Transmit data and errors/Receive data and errors */
  R52_LPUART_MSC_INT0_1_IRQn   = 197,              /**< Transmit data and errors/Receive data and errors */
  R52_LFAST_INT0_4_IRQn        = 198,              /**< Transmit/Transmit exception/Receive/Receive exception/ICLC Receive */
  R52_MSGINTR0_INT0_2_IRQn     = 199,              /**< Message signaled interrupt register 0/Message signaled interrupt register 1/Message signaled interrupt register 2 */
  R52_MSGINTR1_INT0_2_IRQn     = 200,              /**< Message signaled interrupt register 0/Message signaled interrupt register 1/Message signaled interrupt register 2 */
  R52_MSGINTR2_INT0_2_IRQn     = 201,              /**< Message signaled interrupt register 0/Message signaled interrupt register 1/Message signaled interrupt register 2 */
  R52_MSGINTR3_INT0_2_IRQn     = 202,              /**< Message signaled interrupt register 0/Message signaled interrupt register 1/Message signaled interrupt register 2 */
  R52_MSGINTR4_INT0_2_IRQn     = 203,              /**< Message signaled interrupt register 0/Message signaled interrupt register 1/Message signaled interrupt register 2 */
  R52_MSGINTR5_INT0_2_IRQn     = 204,              /**< Message signaled interrupt register 0/Message signaled interrupt register 1/Message signaled interrupt register 2 */
  R52_MSGINTR6_INT0_2_IRQn     = 205,              /**< Message signaled interrupt register 0/Message signaled interrupt register 1/Message signaled interrupt register 2 */
  R52_MSGINTR7_INT0_2_IRQn     = 206,              /**< Message signaled interrupt register 0/Message signaled interrupt register 1/Message signaled interrupt register 2 */
  R52_NETC_IEPRC_INT0_1_IRQn   = 207,              /**< NETC Root Complex PCI 0/NETC Root Complex PCI 1 */
  R52_PSI50_INT0_23_IRQn       = 208,              /**< PSI5 channel 0 DMA combined; asserted when data overflow/underflow occurs or dma transfer finished/PSI5 channel 0 combined general; asserted when SENT message arrives/has an error or when the data output register request for new data or are overwritten when not ready to accept new data/PSI5 channel 0 new message received/PSI5 channel 0 message overwrite/PSI5 channel 0 error/PSI5 channel 0 combined/PSI5 channel 1 DMA combined; asserted when data overflow/underflow occurs or dma transfer finished/PSI5 channel 1 combined general; asserted when SENT message arrives/has an error or when the data output register request for new data or are overwritten when not ready to accept new data/PSI5 channel 1 new message received/PSI5 channel 1 message overwrite/PSI5 channel 1 error/PSI5 channel 1 combined/PSI5 channel 2 DMA combined; asserted when data overflow/underflow occurs or dma transfer finished/PSI5 channel 2 combined general; asserted when SENT message arrives/has an error or when the data output register request for new data or are overwritten when not ready to accept new data/PSI5 channel 2 new message received/PSI5 channel 2 message overwrite/PSI5 channel 2 error/PSI5 channel 2 combined/PSI5 channel 3 DMA combined; asserted when data overflow/underflow occurs or dma transfer finished/PSI5 channel 3 combined general; asserted when SENT message arrives/has an error or when the data output register request for new data or are overwritten when not ready to accept new data/PSI5 channel 3 new message received/PSI5 channel 3 message overwrite/PSI5 channel 3 error/PSI5 channel 3 combined */
  R52_PSI51_INT0_23_IRQn       = 209,              /**< PSI5 channel 0 DMA combined; asserted when data overflow/underflow occurs or dma transfer finished/PSI5 channel 0 combined general; asserted when SENT message arrives/has an error or when the data output register request for new data or are overwritten when not ready to accept new data/PSI5 channel 0 new message received/PSI5 channel 0 message overwrite/PSI5 channel 0 error/PSI5 channel 0 combined/PSI5 channel 1 DMA combined; asserted when data overflow/underflow occurs or dma transfer finished/PSI5 channel 1 combined general; asserted when SENT message arrives/has an error or when the data output register request for new data or are overwritten when not ready to accept new data/PSI5 channel 1 new message received/PSI5 channel 1 message overwrite/PSI5 channel 1 error/PSI5 channel 1 combined/PSI5 channel 2 DMA combined; asserted when data overflow/underflow occurs or dma transfer finished/PSI5 channel 2 combined general; asserted when SENT message arrives/has an error or when the data output register request for new data or are overwritten when not ready to accept new data/PSI5 channel 2 new message received/PSI5 channel 2 message overwrite/PSI5 channel 2 error/PSI5 channel 2 combined/PSI5 channel 3 DMA combined; asserted when data overflow/underflow occurs or dma transfer finished/PSI5 channel 3 combined general; asserted when SENT message arrives/has an error or when the data output register request for new data or are overwritten when not ready to accept new data/PSI5 channel 3 new message received/PSI5 channel 3 message overwrite/PSI5 channel 3 error/PSI5 channel 3 combined */
  R52_PSI5_S0_INT0_18_IRQn     = 210,              /**< PS_SR_IRQ[0]/PS_SR_IRQ[1]/PS_SR_IRQ[2]/PS_SR_IRQ[3]/PS_SR_IRQ[4]/PS_SR_IRQ[5]/PS_SR_IRQ[6]/PS_SR_IRQ[7]/PSI5_E2SSR[1]/PSI5_E2SSR[2]/PSI5_E2SSR[3]/PSI5_E2SSR[4]/PSI5_E2SSR[5]/PSI5_E2SSR[6]/PSI5_E2SSR[7]/PS_GLSR/PSI5_S_0_UART_RX/PSI5_S_0_UART_TX/PSI5_S_0_UART_ERR */
  R52_PSI5_S1_INT0_18_IRQn     = 211,              /**< PS_SR_IRQ[0]/PS_SR_IRQ[1]/PS_SR_IRQ[2]/PS_SR_IRQ[3]/PS_SR_IRQ[4]/PS_SR_IRQ[5]/PS_SR_IRQ[6]/PS_SR_IRQ[7]/PSI5_E2SSR[1]/PSI5_E2SSR[2]/PSI5_E2SSR[3]/PSI5_E2SSR[4]/PSI5_E2SSR[5]/PSI5_E2SSR[6]/PSI5_E2SSR[7]/PS_GLSR/PSI5_S_0_UART_RX/PSI5_S_0_UART_TX/PSI5_S_0_UART_ERR */
  R52_RXLUT_INT_IRQn           = 212,              /**< RXLUT */
  R52_SIPI_INT0_IRQn           = 213,              /**< Read channel 2 */
  R52_SIPI_INT1_6_IRQn         = 214,              /**< Read channel 1/Read channel 3/Read channel 4/Error 1/Error 2/Trigger command */
  R52_SAI0_INT0_1_IRQn         = 216,              /**< Receive/Transmit */
  R52_SAI1_INT0_1_IRQn         = 217,              /**< Receive/Transmit */
  R52_uSDHC_INT_IRQn           = 218,              /**< uSDHC */
  R52_LPE_eDMA3_TCD0_1_INT_IRQn = 220,             /**< DMA transfer complete and error channel 0/DMA transfer complete and error channel 1 */
  R52_LPE_eDMA3_TCD2_3_INT_IRQn = 221,             /**< DMA transfer complete and error channel 2/DMA transfer complete and error channel 3 */
  R52_LPE_eDMA3_TCD4_5_INT_IRQn = 222,             /**< DMA transfer complete and error channel 4/DMA transfer complete and error channel 5 */
  R52_LPE_eDMA3_TCD6_7_INT_IRQn = 223,             /**< DMA transfer complete and error channel 6/DMA transfer complete and error channel 7 */
  R52_LPE_eDMA3_TCD8_9_INT_IRQn = 224,             /**< DMA transfer complete and error channel 8/DMA transfer complete and error channel 9 */
  R52_LPE_eDMA3_TCD10_11_INT_IRQn = 225,           /**< DMA transfer complete and error channel 10/DMA transfer complete and error channel 11 */
  R52_LPE_XRDC_INT_IRQn        = 226,              /**< Transfer error */
  R52_LPE_PMC_INT0_3_IRQn      = 227,              /**< Low-voltage detect on VDD_LVDS < 1.7V (LVDLVDSF flag)/Low-voltage detect VDD_HV_B < 3.0V (LVDB33F flag) and VDD_HV_B < 1.7V (LVDB18F flag)/High-voltage detect > x.xV (HVDxF flags) */
  R52_LPE_MC_RGM_INT_IRQn      = 228,              /**< RGM */
  R52_LPE_SWT_INT_IRQn         = 229,              /**< Initial time-out */
  R52_LPE_SIUL2_INT_IRQn       = 230,              /**< Vector 0 */
  R52_LPE_WKPU_INT0_8_IRQn     = 231,              /**< Group 0/Group 1/Group 2/Group 3/Group 4/Group 5/Group 6/Group 7/Group 8 */
  R52_LPE_WKPU_INT14_IRQn      = 232,              /**< Per core: Active low non-maskable request 5 */
  R52_LPE_WKPU_INT15_IRQn      = 233,              /**< Per core: Active low non-maskable request 6 */
  R52_LPE_WKPU_INT16_IRQn      = 234,              /**< Per core: Active low non-maskable request 7 */
  R52_LPE_CXPI0_INT_IRQn       = 235,              /**< ORed arbitration loss, dominant timeout, wakeup pulse reception */
  R52_LPE_CXPI1_INT_IRQn       = 236,              /**< ORed arbitration loss, dominant timeout, wakeup pulse reception */
  R52_LPE_ERM_INT0_1_IRQn      = 237,              /**< Single-bit correctable event/Multi-bit uncorrectable error event */
  R52_LPE_SARADC_INT0_2_IRQn   = 238,              /**< End of conversion/Error/Analog watchdog */
  R52_LPE_LPCMP0_INT_IRQn      = 239,              /**< Asynchronous */
  R52_LPE_LPCMP1_INT_IRQn      = 240,              /**< Asynchronous */
  R52_LPE_LPCMP2_INT_IRQn      = 241,              /**< Asynchronous */
  R52_LPE_TEMPSENSE_INT0_3_IRQn = 242,             /**< Data ready 0/Comparator threshold 0/Comparator threshold 1/Comparator threshold 2 */
  R52_LPE_BCTU_INT0_4_IRQn     = 243,              /**< ADC conversion triggered/ADC0 conversion data ready/ADC last command of list issued/FIFO1/FIFO2 */
  R52_LPE_FTM_INT0_10_IRQn     = 244,              /**< Channel 0/Channel 1/Channel 2/Channel 3/Channel 4/Channel 5/Channel 6/Channel 7/Fault/Overflow/Reload */
  R52_LPE_LCU_INT_IRQn         = 245,              /**< Logic Cell 0 */
  R52_LPE_PIT_RTI_INT0_3_IRQn  = 246,              /**< Channel 0/Channel 1/Channel 2/Channel 3/Channel 4 (RTI) */
  R52_LPE_RTC_API_INT0_1_IRQn  = 247,              /**< RTC compare and counter overflow/API compare */
  R52_LPE_STM_INT0_3_IRQn      = 248,              /**< Channel 0/Channel 1/Channel 2/Channel 3 */
  R52_LPE_FLEXCAN_INT0_8_IRQn  = 249,              /**< CAN bus went to Bus Off state/CAN has completed the Bus Off count process (it has counted 11 recessive bits 128 times) and is ready for bus off recover/Errors detected on the CAN bus/Errors detected on the CAN bus for FD messages in the Fast Bit Rate region/Transmit Error Counter transition from < 96 to >= 96/Receive Error Counter transition from < 96 to >= 96/Correctable error detected in memory read access/Non-correctable error detected in memory read access by host (cpu)/Non-correctable error detected in memory read access by CAN */
  R52_LPE_FLEXCAN_INT9_15_IRQn = 250,              /**< The number of messages stored in FIFO is greater than the FIFO watermarker/At least one message stored in FIFO/An underflow occurs in the FIFO/An overflow occurs in the FIFO/All Message Buffers */
  R52_LPE_LPI2C_INT0_3_IRQn    = 251,              /**< Master/Asynchronous master/Slave/Asynchronous slave */
  R52_LPE_LPSPI0_INT0_1_IRQn   = 252,              /**< Transmit and receive data and errors/Asynchronous */
  R52_LPE_LPSPI1_INT0_1_IRQn   = 253,              /**< Transmit and receive data and errors/Asynchronous */
  R52_LPE_LPUART0_INT0_3_IRQn  = 254,              /**< Transmit data and errors/Asynchronous transmit/Receive data and errors/Asynchronous receive */
  R52_LPE_LPUART1_INT0_3_IRQn  = 255,              /**< Transmit data and errors/Asynchronous transmit/Receive data and errors/Asynchronous receive */
  R52_LPE_LPUART2_INT0_3_IRQn  = 256,              /**< Transmit data and errors/Asynchronous transmit/Receive data and errors/Asynchronous receive */
  R52_CPE_CTI_INT_IRQn         = 257,              /**< Per cluster: Request */
  R52_CPE_XRDC_INT_IRQn        = 258,              /**< Transfer Error */
  R52_CPE_LLC0_INT0_IRQn       = 259,              /**< Number of correctable error is above threshold */
  R52_CPE_LLC0_INT1_IRQn       = 260,              /**< Uncorrectable error */
  R52_CPE_LLC0_INT2_IRQn       = 261,              /**< Module interrupt */
  R52_CPE_LLC0_INT3_IRQn       = 262,              /**< Correctable error */
  R52_CPE_LLC1_INT0_IRQn       = 263,              /**< Number of correctable error is above threshold */
  R52_CPE_LLC1_INT1_IRQn       = 264,              /**< Uncorrectable error */
  R52_CPE_LLC1_INT2_IRQn       = 265,              /**< Module interrupt */
  R52_CPE_LLC1_INT3_IRQn       = 266,              /**< Correctable error */
  R52_CPE_MRU0_INT0_IRQn       = 267,              /**< Per core: Notification channel 0 */
  R52_CPE_MRU0_INT1_IRQn       = 268,              /**< Per core: Notification channel 1 */
  R52_CPE_MRU0_INT2_IRQn       = 269,              /**< Per core: Notification channel 2 */
  R52_CPE_MRU0_INT3_IRQn       = 270,              /**< Per core: Notification channel 3 */
  R52_CPE_MRU0_INT4_IRQn       = 271,              /**< Channel reset */
  R52_CPE_MRU1_INT0_IRQn       = 272,              /**< Per core: Notification channel 0 */
  R52_CPE_MRU1_INT1_IRQn       = 273,              /**< Per core: Notification channel 1 */
  R52_CPE_MRU1_INT2_IRQn       = 274,              /**< Per core: Notification channel 2 */
  R52_CPE_MRU1_INT3_IRQn       = 275,              /**< Per core: Notification channel 3 */
  R52_CPE_MRU1_INT4_IRQn       = 276,              /**< Channel reset */
  R52_CPE_MRU2_INT0_IRQn       = 277,              /**< Per core: Notification channel 0 */
  R52_CPE_MRU2_INT1_IRQn       = 278,              /**< Per core: Notification channel 1 */
  R52_CPE_MRU2_INT2_IRQn       = 279,              /**< Per core: Notification channel 2 */
  R52_CPE_MRU2_INT3_IRQn       = 280,              /**< Per core: Notification channel 3 */
  R52_CPE_MRU2_INT4_IRQn       = 281,              /**< Channel reset */
  R52_CPE_MRU3_INT0_IRQn       = 282,              /**< Per core: Notification channel 0 */
  R52_CPE_MRU3_INT1_IRQn       = 283,              /**< Per core: Notification channel 1 */
  R52_CPE_MRU3_INT2_IRQn       = 284,              /**< Per core: Notification channel 2 */
  R52_CPE_MRU3_INT3_IRQn       = 285,              /**< Per core: Notification channel 3 */
  R52_CPE_MRU3_INT4_IRQn       = 286,              /**< Channel reset */
  R52_CPE_MRU4_INT0_IRQn       = 287,              /**< Per core: Notification channel 0 */
  R52_CPE_MRU4_INT1_IRQn       = 288,              /**< Per core: Notification channel 1 */
  R52_CPE_MRU4_INT2_IRQn       = 289,              /**< Per core: Notification channel 2 */
  R52_CPE_MRU4_INT3_IRQn       = 290,              /**< Per core: Notification channel 3 */
  R52_CPE_MRU4_INT4_IRQn       = 291,              /**< Channel reset */
  R52_CPE_MRU5_INT0_IRQn       = 292,              /**< Per core: Notification channel 0 */
  R52_CPE_MRU5_INT1_IRQn       = 293,              /**< Per core: Notification channel 1 */
  R52_CPE_MRU5_INT2_IRQn       = 294,              /**< Per core: Notification channel 2 */
  R52_CPE_MRU5_INT3_IRQn       = 295,              /**< Per core: Notification channel 3 */
  R52_CPE_MRU5_INT4_IRQn       = 296,              /**< Channel reset */
  R52_CPE_SWT0_INT_IRQn        = 297,              /**< Initial time-out */
  R52_CPE_SWT1_INT_IRQn        = 298,              /**< Initial time-out */
  R52_CPE_SWT2_INT_IRQn        = 299,              /**< Initial time-out */
  R52_CPE_PIT0_INT0_IRQn       = 303,              /**< Channel 0 */
  R52_CPE_PIT0_INT1_IRQn       = 304,              /**< Channel 1 */
  R52_CPE_PIT0_INT2_IRQn       = 305,              /**< Channel 2 */
  R52_CPE_PIT0_INT3_IRQn       = 306,              /**< Channel 3 */
  R52_CPE_PIT1_INT0_IRQn       = 307,              /**< Channel 0 */
  R52_CPE_PIT1_INT1_IRQn       = 308,              /**< Channel 1 */
  R52_CPE_PIT1_INT2_IRQn       = 309,              /**< Channel 2 */
  R52_CPE_PIT1_INT3_IRQn       = 310,              /**< Channel 3 */
  R52_CPE_PIT2_INT0_IRQn       = 311,              /**< Channel 0 */
  R52_CPE_PIT2_INT1_IRQn       = 312,              /**< Channel 1 */
  R52_CPE_PIT2_INT2_IRQn       = 313,              /**< Channel 2 */
  R52_CPE_PIT2_INT3_IRQn       = 314,              /**< Channel 3 */
  R52_CPE_STM0_INT0_IRQn       = 315,              /**< Channel 0 */
  R52_CPE_STM0_INT1_IRQn       = 316,              /**< Channel 1 */
  R52_CPE_STM0_INT2_IRQn       = 317,              /**< Channel 2 */
  R52_CPE_STM0_INT3_IRQn       = 318,              /**< Channel 3 */
  R52_CPE_STM1_INT0_IRQn       = 319,              /**< Channel 0 */
  R52_CPE_STM1_INT1_IRQn       = 320,              /**< Channel 1 */
  R52_CPE_STM1_INT2_IRQn       = 321,              /**< Channel 2 */
  R52_CPE_STM1_INT3_IRQn       = 322,              /**< Channel 3 */
  R52_CPE_STM2_INT0_IRQn       = 323,              /**< Channel 0 */
  R52_CPE_STM2_INT1_IRQn       = 324,              /**< Channel 1 */
  R52_CPE_STM2_INT2_IRQn       = 325,              /**< Channel 2 */
  R52_CPE_STM2_INT3_IRQn       = 326,              /**< Channel 3 */
  R52_CPE_PMC0_INT_IRQn        = 327               /**< Test program has completed */
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


#endif  /* #if !defined(S32K566_R52_COMMON_H_) */

