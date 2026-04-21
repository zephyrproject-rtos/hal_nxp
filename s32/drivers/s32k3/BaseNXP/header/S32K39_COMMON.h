/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K39_M7.h
 * @version 1.7
 * @date 2022-11-18
 * @brief Peripheral Access Layer for S32K39_M7
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
#if !defined(S32K39_COMMON_H_)  /* Check if memory map has not been already included */
#define S32K39_COMMON_H_
#define MCU_S32K39

/* Check if another memory map has not been also included */
#if (defined(MCU_ACTIVE))
  #error S32K39_M7 memory map: There is already included another memory map. Only one memory map can be included.
#endif /* (defined(MCU_ACTIVE)) */
#define MCU_ACTIVE

#include "BasicTypes.h"

/** Memory map major version (memory maps with equal major version number are
 * compatible) */
#define MCU_MEM_MAP_VERSION 0x0100U
/** Memory map minor version */
#define MCU_MEM_MAP_VERSION_MINOR 0x0007U

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
#define NUMBER_OF_INT_VECTORS 256                /**< Number of interrupts in the Vector table */

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
  INT0_IRQn                    = 0,                /**< CPU to CPU int0 */
  INT1_IRQn                    = 1,                /**< CPU to CPU int1 */
  INT2_IRQn                    = 2,                /**< CPU to CPU int2 */
  INT3_IRQn                    = 3,                /**< CPU to CPU int3 */
  eDMA0_DMATCD_CH0_CH1_IRQn    = 4,                /**< DMA transfer complete and error CH0, DMA transfer complete and error CH1 */
  eDMA0_DMATCD_CH2_CH3_IRQn    = 5,                /**< DMA transfer complete and error CH2, DMA transfer complete and error CH3 */
  eDMA0_DMATCD_CH4_CH5_IRQn    = 6,                /**< DMA transfer complete and error CH4, DMA transfer complete and error CH5 */
  eDMA0_DMATCD_CH6_CH7_IRQn    = 7,                /**< DMA transfer complete and error CH6, DMA transfer complete and error CH7 */
  eDMA0_DMATCD_CH8_CH9_IRQn    = 8,                /**< DMA transfer complete and error CH8, DMA transfer complete and error CH9 */
  eDMA0_DMATCD_CH10_CH11_IRQn  = 9,                /**< DMA transfer complete and error CH10, DMA transfer complete and error CH11 */
  eDMA0_DMATCD_CH12_CH13_IRQn  = 10,               /**< DMA transfer complete and error CH12, DMA transfer complete and error CH13 */
  eDMA0_DMATCD_CH14_CH15_IRQn  = 11,               /**< DMA transfer complete and error CH14, DMA transfer complete and error CH15 */
  eDMA0_DMATCD_CH16_CH17_IRQn  = 12,               /**< DMA transfer complete and error CH16, DMA transfer complete and error CH17 */
  eDMA0_DMATCD_CH18_CH19_IRQn  = 13,               /**< DMA transfer complete and error CH18, DMA transfer complete and error CH19 */
  eDMA0_DMATCD_CH20_CH21_IRQn  = 14,               /**< DMA transfer complete and error CH20, DMA transfer complete and error CH21 */
  eDMA0_DMATCD_CH22_CH23_IRQn  = 15,               /**< DMA transfer complete and error CH22, DMA transfer complete and error CH23 */
  eDMA0_DMATCD_CH24_CH25_IRQn  = 16,               /**< DMA transfer complete and error CH24, DMA transfer complete and error CH25 */
  eDMA0_DMATCD_CH26_CH27_IRQn  = 17,               /**< DMA transfer complete and error CH26, DMA transfer complete and error CH27 */
  eDMA0_DMATCD_CH28_CH29_IRQn  = 18,               /**< DMA transfer complete and error CH28, DMA transfer complete and error CH29 */
  eDMA0_DMATCD_CH30_CH31_IRQn  = 19,               /**< DMA transfer complete and error CH30, DMA transfer complete and error CH31 */
  eDMA1_DMATCD_CH0_CH1_IRQn    = 20,               /**< DMA transfer complete and error CH0, DMA transfer complete and error CH1 */
  eDMA1_DMATCD_CH2_CH3_IRQn    = 21,               /**< DMA transfer complete and error CH2, DMA transfer complete and error CH3 */
  eDMA1_DMATCD_CH4_CH5_IRQn    = 22,               /**< DMA transfer complete and error CH4, DMA transfer complete and error CH5 */
  eDMA1_DMATCD_CH6_CH7_IRQn    = 23,               /**< DMA transfer complete and error CH6, DMA transfer complete and error CH7 */
  eDMA1_DMATCD_CH8_CH9_IRQn    = 24,               /**< DMA transfer complete and error CH8, DMA transfer complete and error CH9 */
  eDMA1_DMATCD_CH10_CH11_IRQn  = 25,               /**< DMA transfer complete and error CH10, DMA transfer complete and error CH11 */
  eDMA1_DMATCD_CH12_CH13_IRQn  = 26,               /**< DMA transfer complete and error CH12, DMA transfer complete and error CH13 */
  eDMA1_DMATCD_CH14_CH15_IRQn  = 27,               /**< DMA transfer complete and error CH14, DMA transfer complete and error CH15 */
  eDMA1_DMATCD_CH16_CH17_IRQn  = 28,               /**< DMA transfer complete and error CH16, DMA transfer complete and error CH17 */
  eDMA1_DMATCD_CH18_CH19_IRQn  = 29,               /**< DMA transfer complete and error CH18, DMA transfer complete and error CH19 */
  eDMA1_DMATCD_CH20_CH21_IRQn  = 30,               /**< DMA transfer complete and error CH20, DMA transfer complete and error CH21 */
  eDMA1_DMATCD_CH22_CH23_IRQn  = 31,               /**< DMA transfer complete and error CH22, DMA transfer complete and error CH23 */
  eDMA1_DMATCD_CH24_CH25_IRQn  = 32,               /**< DMA transfer complete and error CH24, DMA transfer complete and error CH25 */
  eDMA1_DMATCD_CH26_CH27_IRQn  = 33,               /**< DMA transfer complete and error CH26, DMA transfer complete and error CH27 */
  eDMA1_DMATCD_CH28_CH29_IRQn  = 34,               /**< DMA transfer complete and error CH28, DMA transfer complete and error CH29 */
  eDMA1_DMATCD_CH30_CH31_IRQn  = 35,               /**< DMA transfer complete and error CH30, DMA transfer complete and error CH31 */
  ERM_0_IRQn                   = 36,               /**< Single bit ECC error, ADCBIST interrupt line, FIFO full interrupt line, FIFO overflow interrupt line from FIR, FIFO global interrupt line from FIR */
  ERM_1_IRQn                   = 37,               /**< Multi bit ECC error */
  MCM_IRQn                     = 38,               /**< 'FPU OR'ed sources (Input Denormal, Inexact, Underflow, Overflow, Divide-by-Zero, Invalid Operand) */
  STM0_IRQn                    = 39,               /**< Single interrupt vector for all four channels */
  STM1_IRQn                    = 40,               /**< Single interrupt vector for all four channels */
  STM2_IRQn                    = 41,               /**< Single interrupt vector for all four channels */
  SWT0_IRQn                    = 42,               /**< Platform watchdog initial time-out */
  SWT1_IRQn                    = 43,               /**< Platform watchdog initial time-out */
  SWT2_IRQn                    = 44,               /**< Platform watchdog initial time-out */
  CTI0_IRQn                    = 45,               /**< CTI Interrupt 0 */
  CTI1_IRQn                    = 46,               /**< CTI Interrupt 1 */
  CTI2_IRQn                    = 47,               /**< CTI Interrupt 2 */
  FLASH_0_IRQn                 = 48,               /**< Program or erase operation is completed */
  FLASH_1_IRQn                 = 49,               /**< Main watchdog timeout interrupt */
  FLASH_2_IRQn                 = 50,               /**< Alternate watchdog timeout interrupt */
  RGM_IRQn                     = 51,               /**< Interrupt request to the system */
  PMC_IRQn                     = 52,               /**< One interrupt for all LVDs, One interrupt for all HVDs */
  SIUL_0_IRQn                  = 53,               /**< External Interrupt Vector 0 */
  SIUL_1_IRQn                  = 54,               /**< External Interrupt Vector 1 */
  SIUL_2_IRQn                  = 55,               /**< External Interrupt Vector 2 */
  SIUL_3_IRQn                  = 56,               /**< External Interrupt Vector 3 */
  eTPU_IRQn                    = 57,               /**< ECC Error, Global Exception */
  eTPU_A_CH0_IRQn              = 58,               /**< eTPU Engine A Channel 0 Interrup Status */
  eTPU_A_CH1_IRQn              = 59,               /**< eTPU Engine A Channel 1 Interrup Status */
  eTPU_A_CH2_IRQn              = 60,               /**< eTPU Engine A Channel 2 Interrup Status */
  EMIOS0_0_IRQn                = 61,               /**< Interrupt request 23,22,21,20 */
  EMIOS0_1_IRQn                = 62,               /**< Interrupt request 19,18,17,16 */
  EMIOS0_2_IRQn                = 63,               /**< Interrupt request 15,14,13,12 */
  EMIOS0_3_IRQn                = 64,               /**< Interrupt request 11,10,9,8 */
  EMIOS0_4_IRQn                = 65,               /**< Interrupt request 7,6,5,4 */
  EMIOS0_5_IRQn                = 66,               /**< Interrupt request 3,2,1,0 */
  SIPI1_CH1_IRQn               = 67,               /**< Read interrupt channel 1 */
  SIPI1_CH2_IRQn               = 68,               /**< Read interrupt channel 2 */
  SIPI1_CH3_IRQn               = 69,               /**< Read interrupt channel 3 */
  SIPI1_CH4_IRQn               = 70,               /**< Read interrupt channel 4 */
  SIPI1_Int1_IRQn              = 71,               /**< Error interrupt 1 */
  SIPI1_Int2_IRQn              = 72,               /**< Error interrupt 2 */
  SIPI1_Int3_IRQn              = 73,               /**< Trigger command interrupt */
  DIGRF_Tx_int_IRQn            = 74,               /**< Tx interrupt */
  DIGRF_Tx_exc_IRQn            = 75,               /**< Tx exception */
  DIGRF_Rx_int_IRQn            = 76,               /**< Rx interrupt */
  DIGRF_Rx_exc_IRQn            = 77,               /**< Rx exception */
  DIGRF_ICLC_Rx_IRQn           = 78,               /**< ICLC Rx interrupt */
  eTPU_A_CH3_IRQn              = 79,               /**< eTPU Engine A Channel 3 Interrup Status */
  eTPU_A_CH4_IRQn              = 80,               /**< eTPU Engine A Channel 4 Interrup Status */
  eTPU_A_CH5_IRQn              = 81,               /**< eTPU Engine A Channel 5 Interrup Status */
  eTPU_A_CH6_IRQn              = 82,               /**< eTPU Engine A Channel 6 Interrup Status */
  WKPU_IRQn                    = 83,               /**< Interrupts from pad group 0,1,2,3, Interrupts from pad group 0_64, Interrupts from pad group 1_64, Interrupts from pad group 2_64, Interrupts from pad group 3_64 */
  CMU0_IRQn                    = 84,               /**< CMU0 interrupt */
  CMU1_IRQn                    = 85,               /**< CMU1 interrupt */
  CMU2_IRQn                    = 86,               /**< CMU2 interrupt */
  BCTU0_IRQn                   = 87,               /**< An interrupt is requested when a conversion is issued to the ADC, An interrupt is requested when new data is available from ADC0 conversion, An interrupt is requested when new data is available from ADC1 conversion, An interrupt is requested when new data is available from ADC2 conversion, An interrupt is requested when the last command of a list is issued to the ADC,An Interrupt output for FIFO1,An Interrupt output for FIFO2 */
  BCTU1_IRQn                   = 88,               /**< An interrupt is requested when a conversion is issued to the ADC, An interrupt is requested when new data is available from ADC0 conversion, An interrupt is requested when new data is available from ADC1 conversion, An interrupt is requested when new data is available from ADC2 conversion, An interrupt is requested when the last command of a list is issued to the ADC,An Interrupt output for FIFO1,An Interrupt output for FIFO2 */
  eTPU_A_CH7_IRQn              = 89,               /**< eTPU Engine A Channel 7 Interrup Status */
  eTPU_A_CH8_IRQn              = 90,               /**< eTPU Engine A Channel 8 Interrup Status */
  eTPU_A_CH9_IRQn              = 91,               /**< eTPU Engine A Channel 9 Interrup Status */
  LCU0_IRQn                    = 92,               /**< Interrupt 0, Interrupt 1 Interrupt 2 */
  LCU1_IRQn                    = 93,               /**< Interrupt 0, Interrupt 1 Interrupt 2 */
  eTPU_A_CH10_IRQn             = 94,               /**< eTPU Engine A Channel 10 Interrup Status */
  eTPU_A_CH11_IRQn             = 95,               /**< eTPU Engine A Channel 11 Interrup Status */
  PIT0_IRQn                    = 96,               /**< Interrupt for Channel0,Interrupt for Channel1,Interrupt for Channel2,Interrupt for Channel3,Interrupt for Channel4 */
  PIT1_IRQn                    = 97,               /**< Interrupt for Channel0,Interrupt for Channel1,Interrupt for Channel2,Interrupt for Channel3 */
  PIT2_IRQn                    = 98,               /**< Interrupt for Channel0,Interrupt for Channel1,Interrupt for Channel2,Interrupt for Channel3 */
  eTPU_A_CH12_IRQn             = 99,               /**< eTPU Engine A Channel 12 Interrup Status */
  eTPU_A_CH13_IRQn             = 100,              /**< eTPU Engine A Channel 13 Interrup Status */
  eTPU_A_CH14_IRQn             = 101,              /**< eTPU Engine A Channel 14 Interrup Status */
  RTC_IRQn                     = 102,              /**< RTCF or ROVRF interrupt to be serviced by the system controller, APIF interrupt to be serviced by the system controller */
  eTPU_A_CH15_IRQn             = 103,              /**< eTPU Engine A Channel 15 Interrup Status */
  eTPU_A_CH16_IRQn             = 104,              /**< eTPU Engine A Channel 16 Interrup Status */
  EMAC_0_IRQn                  = 105,              /**< Common interrupt */
  EMAC_1_IRQn                  = 106,              /**< Tx interrupt 0, Tx interrupt 1 */
  EMAC_2_IRQn                  = 107,              /**< Rx interrupt 0, Rx interrupt 1 */
  EMAC_3_IRQn                  = 108,              /**< Safety interrupt correctable, Safety interrupt un-correctable */
  FlexCAN0_0_IRQn              = 109,              /**< Interrupt indicating that the CAN bus went to Bus Off state */
  FlexCAN0_1_IRQn              = 110,              /**< Message Buffer Interrupt line 0-31,ORed Interrupt for Message Buffers */
  FlexCAN0_2_IRQn              = 111,              /**< Message Buffer Interrupt line 32-63 */
  FlexCAN0_3_IRQn              = 112,              /**< Message Buffer Interrupt line 64-95 */
  FlexCAN1_0_IRQn              = 113,              /**< Interrupt indicating that the CAN bus went to Bus Off state */
  FlexCAN1_1_IRQn              = 114,              /**< Message Buffer Interrupt line 0-31 */
  FlexCAN1_2_IRQn              = 115,              /**< Message Buffer Interrupt line 32-63 */
  FlexCAN2_0_IRQn              = 116,              /**< Interrupt indicating that the CAN bus went to Bus Off state */
  FlexCAN2_1_IRQn              = 117,              /**< Message Buffer Interrupt line 0-31 */
  FlexCAN2_2_IRQn              = 118,              /**< Message Buffer Interrupt line 32-63 */
  FlexCAN3_0_IRQn              = 119,              /**< Interrupt indicating that the CAN bus went to Bus Off state */
  FlexCAN3_1_IRQn              = 120,              /**< Message Buffer Interrupt line 0-31 */
  FlexCAN4_0_IRQn              = 121,              /**< Interrupt indicating that the CAN bus went to Bus Off state */
  FlexCAN4_1_IRQn              = 122,              /**< Message Buffer Interrupt line 0-31 */
  FlexCAN5_0_IRQn              = 123,              /**< Interrupt indicating that the CAN bus went to Bus Off state */
  FlexCAN5_1_IRQn              = 124,              /**< Message Buffer Interrupt line 0-31 */
  eTPU_A_CH17_IRQn             = 125,              /**< eTPU Engine A Channel 17 Interrup Status */
  eTPU_A_CH18_IRQn             = 126,              /**< eTPU Engine A Channel 18 Interrup Status */
  eTPU_A_CH19_IRQn             = 127,              /**< eTPU Engine A Channel 19 Interrup Status */
  eTPU_A_CH20_IRQn             = 128,              /**< eTPU Engine A Channel 20 Interrup Status */
  FlexCAN1_3_IRQn              = 129,              /**< Message Buffer Interrupt line 64-95 */
  FlexCAN2_3_IRQn              = 130,              /**< Message Buffer Interrupt line 64-95 */
  FlexCAN3_2_IRQn              = 131,              /**< Message Buffer Interrupt line 32-63 */
  FlexCAN4_2_IRQn              = 132,              /**< Message Buffer Interrupt line 32-63 */
  FlexCAN5_2_IRQn              = 133,              /**< Message Buffer Interrupt line 32-63 */
  eTPU_A_CH21_IRQn             = 134,              /**< eTPU Engine A Channel 21 Interrup Status */
  eTPU_A_CH22_IRQn             = 135,              /**< eTPU Engine A Channel 22 Interrup Status */
  eTPU_A_CH23_IRQn             = 136,              /**< eTPU Engine A Channel 23 Interrup Status */
  SWG_0_IRQn                   = 137,              /**< sgen_error */
  eTPU_A_CH24_31_IRQn          = 138,              /**< eTPU Engine A Channel 24-31 Interrup Status */
  FLEXIO_IRQn                  = 139,              /**< FlexIO Interrupt */
  eTPU_A_CH_0_IRQn             = 140,              /**< eTPU Engine A Channel 0 Interrup Status */
  LPUART0_IRQn                 = 141,              /**< TX and RX interrupt */
  LPUART1_IRQn                 = 142,              /**< TX and RX interrupt */
  LPUART2_IRQn                 = 143,              /**< TX and RX interrupt */
  LPUART3_IRQn                 = 144,              /**< TX and RX interrupt */
  LPUART4_IRQn                 = 145,              /**< TX and RX interrupt */
  LPUART5_IRQn                 = 146,              /**< TX and RX interrupt */
  eTPU_B_CH1_IRQn              = 147,              /**< eTPU Engine A Channel 1 Interrup Status */
  eTPU_B_CH2_IRQn              = 148,              /**< eTPU Engine A Channel 2 Interrup Status */
  eTPU_B_CH3_IRQn              = 149,              /**< eTPU Engine A Channel 3 Interrup Status */
  eTPU_B_CH4_IRQn              = 150,              /**< eTPU Engine A Channel 4 Interrup Status */
  eTPU_B_CH5_IRQn              = 151,              /**< eTPU Engine A Channel 5 Interrup Status */
  eTPU_B_CH6_IRQn              = 152,              /**< eTPU Engine A Channel 6 Interrup Status */
  eTPU_B_CH7_IRQn              = 153,              /**< eTPU Engine A Channel 7 Interrup Status */
  eTPU_B_CH8_IRQn              = 154,              /**< eTPU Engine A Channel 8 Interrup Status */
  eTPU_B_CH9_IRQn              = 155,              /**< eTPU Engine A Channel 9 Interrup Status */
  eTPU_B_CH10_IRQn             = 156,              /**< eTPU Engine A Channel 10 Interrup Status */
  eTPU_B_CH11_IRQn             = 157,              /**< eTPU Engine A Channel 11 Interrup Status */
  eTPU_B_CH12_IRQn             = 158,              /**< eTPU Engine A Channel 12 Interrup Status */
  eTPU_B_CH13_IRQn             = 159,              /**< eTPU Engine A Channel 13 Interrup Status */
  LPI2C0_IRQn                  = 161,              /**< LPI2C Master Interrupt, LPI2C Interrupt */
  LPI2C1_IRQn                  = 162,              /**< LPI2C Master Interrupt, LPI2C Interrupt */
  DSPI0_IRQn                   = 164,              /**< DSPI End of Queue Interrupt, DSPI Transmit FIFO Fill Interrupt, DSPI Command FIFO Fill Interrupt, DSPI Transfer Complete Interrupt, DSPI Command Transfer Complete Interrupt                                               , DSPI Command Transfer Complete Interrupt                                               , SPI Frame Transfer Complete Interrupt                                               , DSI Frame Transfer Complete Interrupt                                               , DSPI Transmit FIFO Invalid Write Flag                                               , DSPI Transmit FIFO Underflow Interrupt                                               , DSPI Receive FIFO Drain Interrupt                                               , DSPI Receive FIFO Overflow Interrupt                                               , DSPI Overrun (OR of ipi_int_tfuf and ipi_int_rfof)                                               , DSPI SPI frames Parity Error Interrupt                                               , DSPI DSI frames Parity Error Interrupt                                               , DSPI DSI frames Data Match Interrupt                                               , DSPI Global Interrupt (OR of all interrupt lines) */
  LPSPI0_IRQn                  = 165,              /**< LPSPI Interrupt */
  LPSPI1_IRQn                  = 166,              /**< LPSPI Interrupt */
  LPSPI2_IRQn                  = 167,              /**< LPSPI Interrupt */
  LPSPI3_IRQn                  = 168,              /**< LPSPI Interrupt */
  LPSPI4_IRQn                  = 169,              /**< LPSPI Interrupt */
  LPSPI5_IRQn                  = 170,              /**< LPSPI Interrupt */
  eTPU_B_CH14_IRQn             = 171,              /**< eTPU Engine A Channel 14 Interrup Status */
  eTPU_B_CH15_IRQn             = 172,              /**< eTPU Engine A Channel 15 Interrup Status */
  QSPI_IRQn                    = 173,              /**< TX Buffer Fill interrupt, Transfer Complete / Transaction Finished, RX Buffer Drain interrupt, Buffer Overflow / Underrun interrupt, Serial Flash Communication Error interrupt, All interrupts ORed output */
  eTPU_B_CH16_IRQn             = 174,              /**< eTPU Engine A Channel 16 Interrup Status */
  eTPU_B_CH17_IRQn             = 175,              /**< eTPU Engine A Channel 17 Interrup Status */
  eFlexPWM0_IRQn               = 176,              /**< fault interrupt, reload error interrupt */
  eFlexPWM1_IRQn               = 177,              /**< capture interrupt from submodule 0, compare interrupt from submodule 0, reload interrupt from submodule 0 */
  JDC_IRQn                     = 178,              /**< Indicates new data to be read from JIN_IPS register or can be written to JOUT_IPS register */
  SDADC_IRQn                   = 179,              /**< SD_ADC 0-3 interrupts */
  ADC0_IRQn                    = 180,              /**< End of conversion, Error interrupt, Watchdog interrupt */
  ADC1_IRQn                    = 181,              /**< End of conversion, Error interrupt, Watchdog interrupt */
  ADC2_IRQn                    = 182,              /**< End of conversion, Error interrupt, Watchdog interrupt */
  LPCMP0_IRQn                  = 183,              /**< Async interrupt */
  LPCMP1_IRQn                  = 184,              /**< Async interrupt */
  ADC3_IRQn                    = 185,              /**< End of conversion, Error interrupt, Watchdog interrupt */
  ADC4_IRQn                    = 186,              /**< End of conversion, Error interrupt, Watchdog interrupt */
  ADC5_IRQn                    = 187,              /**< End of conversion, Error interrupt, Watchdog interrupt */
  ADC6_IRQn                    = 188,              /**< End of conversion, Error interrupt, Watchdog interrupt */
  FCCU_0_IRQn                  = 189,              /**< Interrupt request(ALARM state) */
  FCCU_1_IRQn                  = 190,              /**< Interrupt request(miscellaneous conditions) */
  STCU_LBIST_MBIST_IRQn        = 191,              /**< Interrupt request(miscellaneous conditions) */
  HSE_MU0_TX_IRQn              = 192,              /**< ORed TX interrupt to MU-0 */
  HSE_MU0_RX_IRQn              = 193,              /**< ORed RX interrupt to MU-0 */
  HSE_MU0_ORED_IRQn            = 194,              /**< ORed general purpose interrupt request to MU-0 */
  HSE_MU1_TX_IRQn              = 195,              /**< ORed TX interrupt to MU-1 */
  HSE_MU1_RX_IRQn              = 196,              /**< ORed RX interrupt to MU-1 */
  HSE_MU1_ORED_IRQn            = 197,              /**< ORed general purpose interrupt request to MU-1 */
  eTPU_B_CH18_IRQn             = 198,              /**< eTPU Engine A Channel 18 Interrup Status */
  eTPU_B_CH19_IRQn             = 199,              /**< eTPU Engine A Channel 19 Interrup Status */
  eTPU_B_CH20_IRQn             = 200,              /**< eTPU Engine A Channel 20 Interrup Status */
  eTPU_B_CH21_IRQn             = 201,              /**< eTPU Engine A Channel 21 Interrup Status */
  MU_A_0_IRQn                  = 202,              /**< ORed TX interrupt to MUA */
  MU_A_1_IRQn                  = 203,              /**< ORed RX interrupt to MUA */
  MU_A_2_IRQn                  = 204,              /**< ORed general purpose interrupt request to MUA */
  MU_B_0_IRQn                  = 205,              /**< ORed TX interrupt to MUB */
  MU_B_1_IRQn                  = 206,              /**< ORed RX interrupt to MUB */
  MU_B_2_IRQn                  = 207,              /**< ORed general purpose interrupt request to MUB */
  Soc_RSB_IRQn                 = 212,              /**< PLL LOL interrupt */
  eFlexPWM1_1_IRQn             = 214,              /**< capture interrupt from submodule 1, compare interrupt from submodule 1, reload interrupt from submodule 1 */
  XRDC_IRQn                    = 216,              /**< XRDC Error Interrupt */
  CoolFlux1_IRQn               = 224,              /**< when dsp f/w encounters error during processing, o_core_trigger for safety */
  CoolFlux2_IRQn               = 225,              /**< o_core_trigger per thread */
  CoolFlux3_IRQn               = 226,              /**< o_core_trigger per thread */
  CoolFlux4_IRQn               = 227,              /**< o_core_trigger per thread */
  CoolFlux5_IRQn               = 228,              /**< o_core_trigger per thread */
  eTPU_B_CH22_IRQn             = 229,              /**< eTPU Engine A Channel 22 Interrup Status */
  eTPU_B_CH23_IRQn             = 230,              /**< eTPU Engine A Channel 23 Interrup Status */
  eTPU_B_CH24_IRQn             = 231,              /**< eTPU Engine A Channel 24 Interrup Status */
  SWG1_IRQn                    = 232,              /**< sgen_error */
  eTPU_B_CH25_IRQn             = 233,              /**< eTPU Engine A Channel 25-31 Interrup Status */
  eFlexPWM0_0_IRQn             = 234,              /**< capture interrupt from submodule 0, compare interrupt from submodule 0, reload interrupt from submodule 0 */
  eFlexPWM0_1_IRQn             = 235,              /**< capture interrupt from submodule 1, compare interrupt from submodule 1, reload interrupt from submodule 1 */
  eFlexPWM0_2_IRQn             = 236,              /**< capture interrupt from submodule 2, compare interrupt from submodule 2, reload interrupt from submodule 2 */
  eFlexPWM0_3_IRQn             = 237,              /**< capture interrupt from submodule 3, compare interrupt from submodule 3, reload interrupt from submodule 3 */
  eFlexPWM1_2_IRQn             = 238,              /**< capture interrupt from submodule 2, compare interrupt from submodule 2, reload interrupt from submodule 2 */
  eFlexPWM1_3_IRQn             = 239               /**< capture interrupt from submodule 3, compare interrupt from submodule 3, reload interrupt from submodule 3 */
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


#endif  /* #if !defined(S32K39_COMMON_H_) */

