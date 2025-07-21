/*
** ###################################################################
**     Processor:           KW47B42ZB7AFTA_cm33_core1
**     Compilers:           GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**                          Keil ARM C/C++ Compiler
**                          MCUXpresso Compiler
**
**     Reference manual:    Rev. 1, 2024-10-13
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250522
**
**     Abstract:
**         CMSIS Peripheral Access Layer for KW47B42ZB7_cm33_core1
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2024-10-13)
**         Rev. 1, 2024-10-13
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file KW47B42ZB7_cm33_core1_COMMON.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for KW47B42ZB7_cm33_core1
 *
 * CMSIS Peripheral Access Layer for KW47B42ZB7_cm33_core1
 */

#if !defined(KW47B42ZB7_CM33_CORE1_COMMON_H_)
#define KW47B42ZB7_CM33_CORE1_COMMON_H_          /**< Symbol preventing repeated inclusion */

/** Memory map major version (memory maps with equal major version number are
 * compatible) */
#define MCU_MEM_MAP_VERSION 0x0200U
/** Memory map minor version */
#define MCU_MEM_MAP_VERSION_MINOR 0x0000U


/* ----------------------------------------------------------------------------
   -- Interrupt vector numbers
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Interrupt_vector_numbers Interrupt vector numbers
 * @{
 */

/** Interrupt Number Definitions */
#define NUMBER_OF_INT_VECTORS 49                 /**< Number of interrupts in the Vector table */

typedef enum IRQn {
  /* Auxiliary constants */
  NotAvail_IRQn                = -128,             /**< Not available device specific interrupt */

  /* Core interrupts */
  NonMaskableInt_IRQn          = -14,              /**< Non Maskable Interrupt */
  HardFault_IRQn               = -13,              /**< Cortex-M33 SV Hard Fault Interrupt */
  MemoryManagement_IRQn        = -12,              /**< Cortex-M33 Memory Management Interrupt */
  BusFault_IRQn                = -11,              /**< Cortex-M33 Bus Fault Interrupt */
  UsageFault_IRQn              = -10,              /**< Cortex-M33 Usage Fault Interrupt */
  SecureFault_IRQn             = -9,               /**< Cortex-M33 Secure Fault Interrupt */
  SVCall_IRQn                  = -5,               /**< Cortex-M33 SV Call Interrupt */
  DebugMonitor_IRQn            = -4,               /**< Cortex-M33 Debug Monitor Interrupt */
  PendSV_IRQn                  = -2,               /**< Cortex-M33 Pend SV Interrupt */
  SysTick_IRQn                 = -1,               /**< Cortex-M33 System Tick Interrupt */

  /* Device specific interrupts */
  BLE_INT0_IRQn                = 0,
  BLE_INT1_IRQn                = 1,
  BLE_INT2_IRQn                = 2,
  BTU_FIQ_IRQn                 = 3,
  BTU_INT_IRQn                 = 4,
  BRF_INT_IRQn                 = 5,
  CTI_IRQ0_IRQn                = 6,
  T1_INT_IRQn                  = 7,
  T2_INT_IRQn                  = 8,
  T3_INT_IRQn                  = 9,
  T4_INT_IRQn                  = 10,
  WDG2_INT_IRQn                = 11,
  SI_INT_IRQn                  = 12,
  CTI_IRQ1_IRQn                = 13,
  CPU2_MSG_RDY_INT_IRQn        = 14,
  CPU2_MSG_SPC_AVAIL_INT_IRQn  = 15,
  ZIGBEE_INT_IRQn              = 16,
  CIU2_INT_IRQn                = 17,
  CPU2_ERR_INT_IRQn            = 18,
  GENLL_INT_IRQn               = 19,
  BRIC_INT_IRQn                = 20,
  RF_SFA_IRQn                  = 21,
  RBME_INT_IRQn                = 22,
  LCL_INT_IRQn                 = 23,
  RSM_INT_IRQn                 = 24,
  XO_RDY_INT_IRQn              = 25,
  PLL_ABORT_INT_IRQn           = 26,
  FMU_INT_IRQn                 = 27,
  WOR_INT_IRQn                 = 28,
  TPM2_INT_IRQn                = 29,               /**< Timer / PWM Module2 interrupt */
  DSB_IRQn                     = 30,
  SECSUBSYS_IRQn               = 31,
  LPTMR2_IRQn                  = 32                /**< Low-Power Timer2 interrupt */
} IRQn_Type;

/*!
 * @}
 */ /* end of group Interrupt_vector_numbers */


/* ----------------------------------------------------------------------------
   -- Cortex M33 Core Configuration
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Cortex_Core_Configuration Cortex M33 Core Configuration
 * @{
 */

#define __MPU_PRESENT                  1         /**< Defines if an MPU is present or not */
#define __NVIC_PRIO_BITS               3         /**< Number of priority bits implemented in the NVIC */
#define __Vendor_SysTickConfig         0         /**< Vendor specific implementation of SysTickConfig is defined */
#define __FPU_PRESENT                  0         /**< Defines if an FPU is present or not */
#define __DSP_PRESENT                  0         /**< Defines if Armv8-M Mainline core supports DSP instructions */
#define __SAUREGION_PRESENT            0         /**< Defines if an SAU is present or not */

#include "core_cm33.h"                 /* Core Peripheral Access Layer */
#include "system_KW47B42ZB7_cm33_core1.h" /* Device specific configuration file */

/*!
 * @}
 */ /* end of group Cortex_Core_Configuration */


#ifndef KW47B42ZB7_cm33_core1_SERIES
#define KW47B42ZB7_cm33_core1_SERIES
#endif
/* CPU specific feature definitions */
#include "KW47B42ZB7_cm33_core1_features.h"

/* ADC - Peripheral instance base addresses */
/** Peripheral ADC0 base address */
#define ADC0_BASE                                (0xA91C7000u)
/** Peripheral ADC0 base pointer */
#define ADC0                                     ((ADC_Type *)ADC0_BASE)
/** Array initializer of ADC peripheral base addresses */
#define ADC_BASE_ADDRS                           { ADC0_BASE }
/** Array initializer of ADC peripheral base pointers */
#define ADC_BASE_PTRS                            { ADC0 }

/* ATX - Peripheral instance base addresses */
/** Peripheral ATX0 base address */
#define ATX0_BASE                                (0xA91CB000u)
/** Peripheral ATX0 base pointer */
#define ATX0                                     ((ATX_Type *)ATX0_BASE)
/** Array initializer of ATX peripheral base addresses */
#define ATX_BASE_ADDRS                           { ATX0_BASE }
/** Array initializer of ATX peripheral base pointers */
#define ATX_BASE_PTRS                            { ATX0 }

/* AXBS - Peripheral instance base addresses */
/** Peripheral AXBS0 base address */
#define AXBS0_BASE                               (0xA9180000u)
/** Peripheral AXBS0 base pointer */
#define AXBS0                                    ((AXBS_Type *)AXBS0_BASE)
/** Array initializer of AXBS peripheral base addresses */
#define AXBS_BASE_ADDRS                          { AXBS0_BASE }
/** Array initializer of AXBS peripheral base pointers */
#define AXBS_BASE_PTRS                           { AXBS0 }

/* BLE2_REG - Peripheral instance base addresses */
/** Peripheral BLE2_REG base address */
#define BLE2_REG_BASE                            (0xA9020000u)
/** Peripheral BLE2_REG base pointer */
#define BLE2_REG                                 ((BLE2_REG_Type *)BLE2_REG_BASE)
/** Array initializer of BLE2_REG peripheral base addresses */
#define BLE2_REG_BASE_ADDRS                      { BLE2_REG_BASE }
/** Array initializer of BLE2_REG peripheral base pointers */
#define BLE2_REG_BASE_PTRS                       { BLE2_REG }

/* BRIC - Peripheral instance base addresses */
/** Peripheral BRIC base address */
#define BRIC_BASE                                (0xA9106700u)
/** Peripheral BRIC base pointer */
#define BRIC                                     ((BRIC_Type *)BRIC_BASE)
/** Array initializer of BRIC peripheral base addresses */
#define BRIC_BASE_ADDRS                          { BRIC_BASE }
/** Array initializer of BRIC peripheral base pointers */
#define BRIC_BASE_PTRS                           { BRIC }

/* BTRTU1 - Peripheral instance base addresses */
/** Peripheral BTRTU1 base address */
#define BTRTU1_BASE                              (0xA8009400u)
/** Peripheral BTRTU1 base pointer */
#define BTRTU1                                   ((BTRTU1_Type *)BTRTU1_BASE)
/** Array initializer of BTRTU1 peripheral base addresses */
#define BTRTU1_BASE_ADDRS                        { BTRTU1_BASE }
/** Array initializer of BTRTU1 peripheral base pointers */
#define BTRTU1_BASE_PTRS                         { BTRTU1 }

/* BTU2_REG - Peripheral instance base addresses */
/** Peripheral BTU2_REG base address */
#define BTU2_REG_BASE                            (0xA9020000u)
/** Peripheral BTU2_REG base pointer */
#define BTU2_REG                                 ((BTU2_REG_Type *)BTU2_REG_BASE)
/** Array initializer of BTU2_REG peripheral base addresses */
#define BTU2_REG_BASE_ADDRS                      { BTU2_REG_BASE }
/** Array initializer of BTU2_REG peripheral base pointers */
#define BTU2_REG_BASE_PTRS                       { BTU2_REG }

/* CAN - Peripheral instance base addresses */
/** Peripheral CAN0 base address */
#define CAN0_BASE                                (0xA91BB000u)
/** Peripheral CAN0 base pointer */
#define CAN0                                     ((CAN_Type *)CAN0_BASE)
/** Peripheral CAN1 base address */
#define CAN1_BASE                                (0xA91CF000u)
/** Peripheral CAN1 base pointer */
#define CAN1                                     ((CAN_Type *)CAN1_BASE)
/** Array initializer of CAN peripheral base addresses */
#define CAN_BASE_ADDRS                           { CAN0_BASE, CAN1_BASE }
/** Array initializer of CAN peripheral base pointers */
#define CAN_BASE_PTRS                            { CAN0, CAN1 }

/* CCM32K - Peripheral instance base addresses */
/** Peripheral CCM32K base address */
#define CCM32K_BASE                              (0xA919F000u)
/** Peripheral CCM32K base pointer */
#define CCM32K                                   ((CCM32K_Type *)CCM32K_BASE)
/** Array initializer of CCM32K peripheral base addresses */
#define CCM32K_BASE_ADDRS                        { CCM32K_BASE }
/** Array initializer of CCM32K peripheral base pointers */
#define CCM32K_BASE_PTRS                         { CCM32K }

/* CIU2 - Peripheral instance base addresses */
/** Peripheral CIU2 base address */
#define CIU2_BASE                                (0xA8008000u)
/** Peripheral CIU2 base pointer */
#define CIU2                                     ((CIU2_Type *)CIU2_BASE)
/** Array initializer of CIU2 peripheral base addresses */
#define CIU2_BASE_ADDRS                          { CIU2_BASE }
/** Array initializer of CIU2 peripheral base pointers */
#define CIU2_BASE_PTRS                           { CIU2 }

/* CMC - Peripheral instance base addresses */
/** Peripheral CMC0 base address */
#define CMC0_BASE                                (0xA9181000u)
/** Peripheral CMC0 base pointer */
#define CMC0                                     ((CMC_Type *)CMC0_BASE)
/** Array initializer of CMC peripheral base addresses */
#define CMC_BASE_ADDRS                           { CMC0_BASE }
/** Array initializer of CMC peripheral base pointers */
#define CMC_BASE_PTRS                            { CMC0 }

/* CRC - Peripheral instance base addresses */
/** Peripheral CRC0 base address */
#define CRC0_BASE                                (0xA91A3000u)
/** Peripheral CRC0 base pointer */
#define CRC0                                     ((CRC_Type *)CRC0_BASE)
/** Array initializer of CRC peripheral base addresses */
#define CRC_BASE_ADDRS                           { CRC0_BASE }
/** Array initializer of CRC peripheral base pointers */
#define CRC_BASE_PTRS                            { CRC0 }

/* DMA - Peripheral instance base addresses */
/** Peripheral DMA0 base address */
#define DMA0_BASE                                (0xA9182000u)
/** Peripheral DMA0 base pointer */
#define DMA0                                     ((DMA_Type *)DMA0_BASE)
/** Array initializer of DMA peripheral base addresses */
#define DMA_BASE_ADDRS                           { DMA0_BASE }
/** Array initializer of DMA peripheral base pointers */
#define DMA_BASE_PTRS                            { DMA0 }

/* DSB - Peripheral instance base addresses */
/** Peripheral DSB0 base address */
#define DSB0_BASE                                (0xA91C1000u)
/** Peripheral DSB0 base pointer */
#define DSB0                                     ((DSB_Type *)DSB0_BASE)
/** Array initializer of DSB peripheral base addresses */
#define DSB_BASE_ADDRS                           { DSB0_BASE }
/** Array initializer of DSB peripheral base pointers */
#define DSB_BASE_PTRS                            { DSB0 }

/* ELEMU - Peripheral instance base addresses */
/** Peripheral ELEMUA base address */
#define ELEMUA_BASE                              (0xA91A4000u)
/** Peripheral ELEMUA base pointer */
#define ELEMUA                                   ((ELEMU_Type *)ELEMUA_BASE)
/** Array initializer of ELEMU peripheral base addresses */
#define ELEMU_BASE_ADDRS                         { ELEMUA_BASE }
/** Array initializer of ELEMU peripheral base pointers */
#define ELEMU_BASE_PTRS                          { ELEMUA }

/* EWM - Peripheral instance base addresses */
/** Peripheral EWM0 base address */
#define EWM0_BASE                                (0xA9193000u)
/** Peripheral EWM0 base pointer */
#define EWM0                                     ((EWM_Type *)EWM0_BASE)
/** Array initializer of EWM peripheral base addresses */
#define EWM_BASE_ADDRS                           { EWM0_BASE }
/** Array initializer of EWM peripheral base pointers */
#define EWM_BASE_PTRS                            { EWM0 }

/* FLEXIO - Peripheral instance base addresses */
/** Peripheral FLEXIO0 base address */
#define FLEXIO0_BASE                             (0xA91BA000u)
/** Peripheral FLEXIO0 base pointer */
#define FLEXIO0                                  ((FLEXIO_Type *)FLEXIO0_BASE)
/** Array initializer of FLEXIO peripheral base addresses */
#define FLEXIO_BASE_ADDRS                        { FLEXIO0_BASE }
/** Array initializer of FLEXIO peripheral base pointers */
#define FLEXIO_BASE_PTRS                         { FLEXIO0 }

/* FMU - Peripheral instance base addresses */
/** Peripheral FMU0 base address */
#define FMU0_BASE                                (0xA91A0000u)
/** Peripheral FMU0 base pointer */
#define FMU0                                     ((FMU_Type *)FMU0_BASE)
/** Peripheral RF_FMU base address */
#define RF_FMU_BASE                              (0xA9141000u)
/** Peripheral RF_FMU base pointer */
#define RF_FMU                                   ((FMU_Type *)RF_FMU_BASE)
/** Array initializer of FMU peripheral base addresses */
#define FMU_BASE_ADDRS                           { FMU0_BASE, RF_FMU_BASE }
/** Array initializer of FMU peripheral base pointers */
#define FMU_BASE_PTRS                            { FMU0, RF_FMU }

/* FRO192M - Peripheral instance base addresses */
/** Peripheral FRO192M0 base address */
#define FRO192M0_BASE                            (0xA9140000u)
/** Peripheral FRO192M0 base pointer */
#define FRO192M0                                 ((FRO192M_Type *)FRO192M0_BASE)
/** Array initializer of FRO192M peripheral base addresses */
#define FRO192M_BASE_ADDRS                       { FRO192M0_BASE }
/** Array initializer of FRO192M peripheral base pointers */
#define FRO192M_BASE_PTRS                        { FRO192M0 }

/* GEN4PHY - Peripheral instance base addresses */
/** Peripheral XCVR_2P4GHZ_PHY base address */
#define XCVR_2P4GHZ_PHY_BASE                     (0xA9107600u)
/** Peripheral XCVR_2P4GHZ_PHY base pointer */
#define XCVR_2P4GHZ_PHY                          ((GEN4PHY_Type *)XCVR_2P4GHZ_PHY_BASE)
/** Array initializer of GEN4PHY peripheral base addresses */
#define GEN4PHY_BASE_ADDRS                       { XCVR_2P4GHZ_PHY_BASE }
/** Array initializer of GEN4PHY peripheral base pointers */
#define GEN4PHY_BASE_PTRS                        { XCVR_2P4GHZ_PHY }

/* GENFSK - Peripheral instance base addresses */
/** Peripheral GENFSK base address */
#define GENFSK_BASE                              (0xA9102000u)
/** Peripheral GENFSK base pointer */
#define GENFSK                                   ((GENFSK_Type *)GENFSK_BASE)
/** Array initializer of GENFSK peripheral base addresses */
#define GENFSK_BASE_ADDRS                        { GENFSK_BASE }
/** Array initializer of GENFSK peripheral base pointers */
#define GENFSK_BASE_PTRS                         { GENFSK }

/* GPIO - Peripheral instance base addresses */
/** Peripheral GPIOD base address */
#define GPIOD_BASE                               (0xA91C6000u)
/** Peripheral GPIOD base pointer */
#define GPIOD                                    ((GPIO_Type *)GPIOD_BASE)
/** Array initializer of GPIO peripheral base addresses */
#define GPIO_BASE_ADDRS                          { GPIOD_BASE }
/** Array initializer of GPIO peripheral base pointers */
#define GPIO_BASE_PTRS                           { GPIOD }

/* I3C - Peripheral instance base addresses */
/** Peripheral I3C0 base address */
#define I3C0_BASE                                (0xA91B5000u)
/** Peripheral I3C0 base pointer */
#define I3C0                                     ((I3C_Type *)I3C0_BASE)
/** Array initializer of I3C peripheral base addresses */
#define I3C_BASE_ADDRS                           { I3C0_BASE }
/** Array initializer of I3C peripheral base pointers */
#define I3C_BASE_PTRS                            { I3C0 }

/* LPCMP - Peripheral instance base addresses */
/** Peripheral LPCMP0 base address */
#define LPCMP0_BASE                              (0xA91C8000u)
/** Peripheral LPCMP0 base pointer */
#define LPCMP0                                   ((LPCMP_Type *)LPCMP0_BASE)
/** Peripheral LPCMP1 base address */
#define LPCMP1_BASE                              (0xA91C9000u)
/** Peripheral LPCMP1 base pointer */
#define LPCMP1                                   ((LPCMP_Type *)LPCMP1_BASE)
/** Array initializer of LPCMP peripheral base addresses */
#define LPCMP_BASE_ADDRS                         { LPCMP0_BASE, LPCMP1_BASE }
/** Array initializer of LPCMP peripheral base pointers */
#define LPCMP_BASE_PTRS                          { LPCMP0, LPCMP1 }

/* LPI2C - Peripheral instance base addresses */
/** Peripheral LPI2C0 base address */
#define LPI2C0_BASE                              (0xA91B3000u)
/** Peripheral LPI2C0 base pointer */
#define LPI2C0                                   ((LPI2C_Type *)LPI2C0_BASE)
/** Peripheral LPI2C1 base address */
#define LPI2C1_BASE                              (0xA91B4000u)
/** Peripheral LPI2C1 base pointer */
#define LPI2C1                                   ((LPI2C_Type *)LPI2C1_BASE)
/** Array initializer of LPI2C peripheral base addresses */
#define LPI2C_BASE_ADDRS                         { LPI2C0_BASE, LPI2C1_BASE }
/** Array initializer of LPI2C peripheral base pointers */
#define LPI2C_BASE_PTRS                          { LPI2C0, LPI2C1 }

/* LPIT - Peripheral instance base addresses */
/** Peripheral LPIT0 base address */
#define LPIT0_BASE                               (0xA91AF000u)
/** Peripheral LPIT0 base pointer */
#define LPIT0                                    ((LPIT_Type *)LPIT0_BASE)
/** Array initializer of LPIT peripheral base addresses */
#define LPIT_BASE_ADDRS                          { LPIT0_BASE }
/** Array initializer of LPIT peripheral base pointers */
#define LPIT_BASE_PTRS                           { LPIT0 }

/* LPSPI - Peripheral instance base addresses */
/** Peripheral LPSPI0 base address */
#define LPSPI0_BASE                              (0xA91B6000u)
/** Peripheral LPSPI0 base pointer */
#define LPSPI0                                   ((LPSPI_Type *)LPSPI0_BASE)
/** Peripheral LPSPI1 base address */
#define LPSPI1_BASE                              (0xA91B7000u)
/** Peripheral LPSPI1 base pointer */
#define LPSPI1                                   ((LPSPI_Type *)LPSPI1_BASE)
/** Array initializer of LPSPI peripheral base addresses */
#define LPSPI_BASE_ADDRS                         { LPSPI0_BASE, LPSPI1_BASE }
/** Array initializer of LPSPI peripheral base pointers */
#define LPSPI_BASE_PTRS                          { LPSPI0, LPSPI1 }

/* LPTMR - Peripheral instance base addresses */
/** Peripheral LPTMR0 base address */
#define LPTMR0_BASE                              (0xA91AD000u)
/** Peripheral LPTMR0 base pointer */
#define LPTMR0                                   ((LPTMR_Type *)LPTMR0_BASE)
/** Peripheral LPTMR1 base address */
#define LPTMR1_BASE                              (0xA91AE000u)
/** Peripheral LPTMR1 base pointer */
#define LPTMR1                                   ((LPTMR_Type *)LPTMR1_BASE)
/** Peripheral LPTMR2 base address */
#define LPTMR2_BASE                              (0xA9146000u)
/** Peripheral LPTMR2 base pointer */
#define LPTMR2                                   ((LPTMR_Type *)LPTMR2_BASE)
/** Array initializer of LPTMR peripheral base addresses */
#define LPTMR_BASE_ADDRS                         { LPTMR0_BASE, LPTMR1_BASE, LPTMR2_BASE }
/** Array initializer of LPTMR peripheral base pointers */
#define LPTMR_BASE_PTRS                          { LPTMR0, LPTMR1, LPTMR2 }
/** Interrupt vectors for the LPTMR peripheral type */
#define LPTMR_IRQS                               { NotAvail_IRQn, NotAvail_IRQn, LPTMR2_IRQn }

/* LPUART - Peripheral instance base addresses */
/** Peripheral LPUART0 base address */
#define LPUART0_BASE                             (0xA91B8000u)
/** Peripheral LPUART0 base pointer */
#define LPUART0                                  ((LPUART_Type *)LPUART0_BASE)
/** Peripheral LPUART1 base address */
#define LPUART1_BASE                             (0xA91B9000u)
/** Peripheral LPUART1 base pointer */
#define LPUART1                                  ((LPUART_Type *)LPUART1_BASE)
/** Array initializer of LPUART peripheral base addresses */
#define LPUART_BASE_ADDRS                        { LPUART0_BASE, LPUART1_BASE }
/** Array initializer of LPUART peripheral base pointers */
#define LPUART_BASE_PTRS                         { LPUART0, LPUART1 }

/* LTC - Peripheral instance base addresses */
/** Peripheral LTC base address */
#define LTC_BASE                                 (0xA9106800u)
/** Peripheral LTC base pointer */
#define LTC                                      ((LTC_Type *)LTC_BASE)
/** Array initializer of LTC peripheral base addresses */
#define LTC_BASE_ADDRS                           { LTC_BASE }
/** Array initializer of LTC peripheral base pointers */
#define LTC_BASE_PTRS                            { LTC }

/* MRCC - Peripheral instance base addresses */
/** Peripheral MRCC base address */
#define MRCC_BASE                                (0xA919C000u)
/** Peripheral MRCC base pointer */
#define MRCC                                     ((MRCC_Type *)MRCC_BASE)
/** Array initializer of MRCC peripheral base addresses */
#define MRCC_BASE_ADDRS                          { MRCC_BASE }
/** Array initializer of MRCC peripheral base pointers */
#define MRCC_BASE_PTRS                           { MRCC }

/* MSCM - Peripheral instance base addresses */
/** Peripheral MSCM base address */
#define MSCM_BASE                                (0xA9194000u)
/** Peripheral MSCM base pointer */
#define MSCM                                     ((MSCM_Type *)MSCM_BASE)
/** Array initializer of MSCM peripheral base addresses */
#define MSCM_BASE_ADDRS                          { MSCM_BASE }
/** Array initializer of MSCM peripheral base pointers */
#define MSCM_BASE_PTRS                           { MSCM }

/* MU - Peripheral instance base addresses */
/** Peripheral MUA base address */
#define MUA_BASE                                 (0xA91D3000u)
/** Peripheral MUA base pointer */
#define MUA                                      ((MU_Type *)MUA_BASE)
/** Array initializer of MU peripheral base addresses */
#define MU_BASE_ADDRS                            { MUA_BASE }
/** Array initializer of MU peripheral base pointers */
#define MU_BASE_PTRS                             { MUA }

/* NPX - Peripheral instance base addresses */
/** Peripheral NPX base address */
#define NPX_BASE                                 (0xA91A5000u)
/** Peripheral NPX base pointer */
#define NPX                                      ((NPX_Type *)NPX_BASE)
/** Array initializer of NPX peripheral base addresses */
#define NPX_BASE_ADDRS                           { NPX_BASE }
/** Array initializer of NPX peripheral base pointers */
#define NPX_BASE_PTRS                            { NPX }

/* PORT - Peripheral instance base addresses */
/** Peripheral PORTA base address */
#define PORTA_BASE                               (0xA91C2000u)
/** Peripheral PORTA base pointer */
#define PORTA                                    ((PORT_Type *)PORTA_BASE)
/** Peripheral PORTB base address */
#define PORTB_BASE                               (0xA91C3000u)
/** Peripheral PORTB base pointer */
#define PORTB                                    ((PORT_Type *)PORTB_BASE)
/** Peripheral PORTC base address */
#define PORTC_BASE                               (0xA91C4000u)
/** Peripheral PORTC base pointer */
#define PORTC                                    ((PORT_Type *)PORTC_BASE)
/** Peripheral PORTD base address */
#define PORTD_BASE                               (0xA91C5000u)
/** Peripheral PORTD base pointer */
#define PORTD                                    ((PORT_Type *)PORTD_BASE)
/** Array initializer of PORT peripheral base addresses */
#define PORT_BASE_ADDRS                          { PORTA_BASE, PORTB_BASE, PORTC_BASE, PORTD_BASE }
/** Array initializer of PORT peripheral base pointers */
#define PORT_BASE_PTRS                           { PORTA, PORTB, PORTC, PORTD }

/* RADIO_CTRL - Peripheral instance base addresses */
/** Peripheral RADIO_CTRL base address */
#define RADIO_CTRL_BASE                          (0xA9106000u)
/** Peripheral RADIO_CTRL base pointer */
#define RADIO_CTRL                               ((RADIO_CTRL_Type *)RADIO_CTRL_BASE)
/** Array initializer of RADIO_CTRL peripheral base addresses */
#define RADIO_CTRL_BASE_ADDRS                    { RADIO_CTRL_BASE }
/** Array initializer of RADIO_CTRL peripheral base pointers */
#define RADIO_CTRL_BASE_PTRS                     { RADIO_CTRL }

/* RBME - Peripheral instance base addresses */
/** Peripheral RBME base address */
#define RBME_BASE                                (0xA9106200u)
/** Peripheral RBME base pointer */
#define RBME                                     ((RBME_Type *)RBME_BASE)
/** Array initializer of RBME peripheral base addresses */
#define RBME_BASE_ADDRS                          { RBME_BASE }
/** Array initializer of RBME peripheral base pointers */
#define RBME_BASE_PTRS                           { RBME }

/* REGFILE - Peripheral instance base addresses */
/** Peripheral REGFILE0 base address */
#define REGFILE0_BASE                            (0xA91A1000u)
/** Peripheral REGFILE0 base pointer */
#define REGFILE0                                 ((REGFILE_Type *)REGFILE0_BASE)
/** Peripheral REGFILE1 base address */
#define REGFILE1_BASE                            (0xA91A2000u)
/** Peripheral REGFILE1 base pointer */
#define REGFILE1                                 ((REGFILE_Type *)REGFILE1_BASE)
/** Array initializer of REGFILE peripheral base addresses */
#define REGFILE_BASE_ADDRS                       { REGFILE0_BASE, REGFILE1_BASE }
/** Array initializer of REGFILE peripheral base pointers */
#define REGFILE_BASE_PTRS                        { REGFILE0, REGFILE1 }

/* RFMC - Peripheral instance base addresses */
/** Peripheral RFMC base address */
#define RFMC_BASE                                (0xA91C0000u)
/** Peripheral RFMC base pointer */
#define RFMC                                     ((RFMC_Type *)RFMC_BASE)
/** Array initializer of RFMC peripheral base addresses */
#define RFMC_BASE_ADDRS                          { RFMC_BASE }
/** Array initializer of RFMC peripheral base pointers */
#define RFMC_BASE_PTRS                           { RFMC }

/* RF_CMC1 - Peripheral instance base addresses */
/** Peripheral RF_CMC1 base address */
#define RF_CMC1_BASE                             (0xA9143000u)
/** Peripheral RF_CMC1 base pointer */
#define RF_CMC1                                  ((RF_CMC1_Type *)RF_CMC1_BASE)
/** Array initializer of RF_CMC1 peripheral base addresses */
#define RF_CMC1_BASE_ADDRS                       { RF_CMC1_BASE }
/** Array initializer of RF_CMC1 peripheral base pointers */
#define RF_CMC1_BASE_PTRS                        { RF_CMC1 }

/* RF_FMCCFG - Peripheral instance base addresses */
/** Peripheral RF_FMCCFG base address */
#define RF_FMCCFG_BASE                           (0xA9142000u)
/** Peripheral RF_FMCCFG base pointer */
#define RF_FMCCFG                                ((RF_FMCCFG_Type *)RF_FMCCFG_BASE)
/** Array initializer of RF_FMCCFG peripheral base addresses */
#define RF_FMCCFG_BASE_ADDRS                     { RF_FMCCFG_BASE }
/** Array initializer of RF_FMCCFG peripheral base pointers */
#define RF_FMCCFG_BASE_PTRS                      { RF_FMCCFG }

/* RTC - Peripheral instance base addresses */
/** Peripheral RTC base address */
#define RTC_BASE                                 (0xA91AC000u)
/** Peripheral RTC base pointer */
#define RTC                                      ((RTC_Type *)RTC_BASE)
/** Array initializer of RTC peripheral base addresses */
#define RTC_BASE_ADDRS                           { RTC_BASE }
/** Array initializer of RTC peripheral base pointers */
#define RTC_BASE_PTRS                            { RTC }

/* RX_PACKET_RAM - Peripheral instance base addresses */
/** Peripheral RX_PACKET_RAM base address */
#define RX_PACKET_RAM_BASE                       (0xA9109000u)
/** Peripheral RX_PACKET_RAM base pointer */
#define RX_PACKET_RAM                            ((RX_PACKET_RAM_Type *)RX_PACKET_RAM_BASE)
/** Array initializer of RX_PACKET_RAM peripheral base addresses */
#define RX_PACKET_RAM_BASE_ADDRS                 { RX_PACKET_RAM_BASE }
/** Array initializer of RX_PACKET_RAM peripheral base pointers */
#define RX_PACKET_RAM_BASE_PTRS                  { RX_PACKET_RAM }

/* SCG - Peripheral instance base addresses */
/** Peripheral SCG0 base address */
#define SCG0_BASE                                (0xA919E000u)
/** Peripheral SCG0 base pointer */
#define SCG0                                     ((SCG_Type *)SCG0_BASE)
/** Array initializer of SCG peripheral base addresses */
#define SCG_BASE_ADDRS                           { SCG0_BASE }
/** Array initializer of SCG peripheral base pointers */
#define SCG_BASE_PTRS                            { SCG0 }

/* SEMA42 - Peripheral instance base addresses */
/** Peripheral SEMA42 base address */
#define SEMA42_BASE                              (0xA91BF000u)
/** Peripheral SEMA42 base pointer */
#define SEMA42                                   ((SEMA42_Type *)SEMA42_BASE)
/** Array initializer of SEMA42 peripheral base addresses */
#define SEMA42_BASE_ADDRS                        { SEMA42_BASE }
/** Array initializer of SEMA42 peripheral base pointers */
#define SEMA42_BASE_PTRS                         { SEMA42 }

/* SFA - Peripheral instance base addresses */
/** Peripheral SFA0 base address */
#define SFA0_BASE                                (0xA919D000u)
/** Peripheral SFA0 base pointer */
#define SFA0                                     ((SFA_Type *)SFA0_BASE)
/** Peripheral RF_SFA base address */
#define RF_SFA_BASE                              (0xA9106300u)
/** Peripheral RF_SFA base pointer */
#define RF_SFA                                   ((SFA_Type *)RF_SFA_BASE)
/** Array initializer of SFA peripheral base addresses */
#define SFA_BASE_ADDRS                           { SFA0_BASE, RF_SFA_BASE }
/** Array initializer of SFA peripheral base pointers */
#define SFA_BASE_PTRS                            { SFA0, RF_SFA }

/* SMSCM - Peripheral instance base addresses */
/** Peripheral SMSCM base address */
#define SMSCM_BASE                               (0xA9195000u)
/** Peripheral SMSCM base pointer */
#define SMSCM                                    ((SMSCM_Type *)SMSCM_BASE)
/** Array initializer of SMSCM peripheral base addresses */
#define SMSCM_BASE_ADDRS                         { SMSCM_BASE }
/** Array initializer of SMSCM peripheral base pointers */
#define SMSCM_BASE_PTRS                          { SMSCM }

/* SPC - Peripheral instance base addresses */
/** Peripheral SPC0 base address */
#define SPC0_BASE                                (0xA9196000u)
/** Peripheral SPC0 base pointer */
#define SPC0                                     ((SPC_Type *)SPC0_BASE)
/** Array initializer of SPC peripheral base addresses */
#define SPC_BASE_ADDRS                           { SPC0_BASE }
/** Array initializer of SPC peripheral base pointers */
#define SPC_BASE_PTRS                            { SPC0 }

/* SYSPM - Peripheral instance base addresses */
/** Peripheral SYSPM base address */
#define SYSPM_BASE                               (0xA9197000u)
/** Peripheral SYSPM base pointer */
#define SYSPM                                    ((SYSPM_Type *)SYSPM_BASE)
/** Array initializer of SYSPM peripheral base addresses */
#define SYSPM_BASE_ADDRS                         { SYSPM_BASE }
/** Array initializer of SYSPM peripheral base pointers */
#define SYSPM_BASE_PTRS                          { SYSPM }

/* TPM - Peripheral instance base addresses */
/** Peripheral TPM0 base address */
#define TPM0_BASE                                (0xA91B1000u)
/** Peripheral TPM0 base pointer */
#define TPM0                                     ((TPM_Type *)TPM0_BASE)
/** Peripheral TPM1 base address */
#define TPM1_BASE                                (0xA91B2000u)
/** Peripheral TPM1 base pointer */
#define TPM1                                     ((TPM_Type *)TPM1_BASE)
/** Peripheral TPM2 base address */
#define TPM2_BASE                                (0xA9144000u)
/** Peripheral TPM2 base pointer */
#define TPM2                                     ((TPM_Type *)TPM2_BASE)
/** Array initializer of TPM peripheral base addresses */
#define TPM_BASE_ADDRS                           { TPM0_BASE, TPM1_BASE, TPM2_BASE }
/** Array initializer of TPM peripheral base pointers */
#define TPM_BASE_PTRS                            { TPM0, TPM1, TPM2 }
/** Interrupt vectors for the TPM peripheral type */
#define TPM_IRQS                                 { NotAvail_IRQn, NotAvail_IRQn, TPM2_INT_IRQn }

/* TRDC - Peripheral instance base addresses */
/** Peripheral TRDC base address */
#define TRDC_BASE                                (0xA91A6000u)
/** Peripheral TRDC base pointer */
#define TRDC                                     ((TRDC_Type *)TRDC_BASE)
/** Array initializer of TRDC peripheral base addresses */
#define TRDC_BASE_ADDRS                          { TRDC_BASE }
/** Array initializer of TRDC peripheral base pointers */
#define TRDC_BASE_PTRS                           { TRDC }
#define MBC0_MEMORY_CFG_WORD_COUNT {8, 1, 1, 2}
#define MBC1_MEMORY_CFG_WORD_COUNT {1, 2, 2, 1}
#define MBC2_MEMORY_CFG_WORD_COUNT {11, 1, 2, 0}
#define MBC3_MEMORY_CFG_WORD_COUNT {0, 0, 0, 0}
#define MBC_MEMORY_CFG_WORD_COUNT {MBC0_MEMORY_CFG_WORD_COUNT , MBC1_MEMORY_CFG_WORD_COUNT, MBC2_MEMORY_CFG_WORD_COUNT, MBC3_MEMORY_CFG_WORD_COUNT}
#define MBC0_MEMORY_NSE_WORD_COUNT {2, 1, 1, 1}
#define MBC1_MEMORY_NSE_WORD_COUNT {1, 1, 1, 1}
#define MBC2_MEMORY_NSE_WORD_COUNT {3, 1, 1, 0}
#define MBC3_MEMORY_NSE_WORD_COUNT {0, 0, 0, 0}
#define MBC_MEMORY_NSE_WORD_COUNT {MBC0_MEMORY_NSE_WORD_COUNT , MBC1_MEMORY_NSE_WORD_COUNT, MBC2_MEMORY_NSE_WORD_COUNT, MBC3_MEMORY_NSE_WORD_COUNT}


/* TRGMUX - Peripheral instance base addresses */
/** Peripheral TRGMUX0 base address */
#define TRGMUX0_BASE                             (0xA9198000u)
/** Peripheral TRGMUX0 base pointer */
#define TRGMUX0                                  ((TRGMUX_Type *)TRGMUX0_BASE)
/** Array initializer of TRGMUX peripheral base addresses */
#define TRGMUX_BASE_ADDRS                        { TRGMUX0_BASE }
/** Array initializer of TRGMUX peripheral base pointers */
#define TRGMUX_BASE_PTRS                         { TRGMUX0 }

/* TSTMR - Peripheral instance base addresses */
/** Peripheral TSTMR0 base address */
#define TSTMR0_BASE                              (0xA91B0000u)
/** Peripheral TSTMR0 base pointer */
#define TSTMR0                                   ((TSTMR_Type *)TSTMR0_BASE)
/** Array initializer of TSTMR peripheral base addresses */
#define TSTMR_BASE_ADDRS                         { TSTMR0_BASE }
/** Array initializer of TSTMR peripheral base pointers */
#define TSTMR_BASE_PTRS                          { TSTMR0 }

/* TX_PACKET_RAM - Peripheral instance base addresses */
/** Peripheral TX_PACKET_RAM base address */
#define TX_PACKET_RAM_BASE                       (0xA9108000u)
/** Peripheral TX_PACKET_RAM base pointer */
#define TX_PACKET_RAM                            ((TX_PACKET_RAM_Type *)TX_PACKET_RAM_BASE)
/** Array initializer of TX_PACKET_RAM peripheral base addresses */
#define TX_PACKET_RAM_BASE_ADDRS                 { TX_PACKET_RAM_BASE }
/** Array initializer of TX_PACKET_RAM peripheral base pointers */
#define TX_PACKET_RAM_BASE_PTRS                  { TX_PACKET_RAM }

/* UART - Peripheral instance base addresses */
/** Peripheral UART base address */
#define UART_BASE                                (0xA8003100u)
/** Peripheral UART base pointer */
#define UART                                     ((UART_Type *)UART_BASE)
/** Array initializer of UART peripheral base addresses */
#define UART_BASE_ADDRS                          { UART_BASE }
/** Array initializer of UART peripheral base pointers */
#define UART_BASE_PTRS                           { UART }

/* UART_PFU - Peripheral instance base addresses */
/** Peripheral UART_PFU base address */
#define UART_PFU_BASE                            (0xA8004000u)
/** Peripheral UART_PFU base pointer */
#define UART_PFU                                 ((UART_PFU_Type *)UART_PFU_BASE)
/** Array initializer of UART_PFU peripheral base addresses */
#define UART_PFU_BASE_ADDRS                      { UART_PFU_BASE }
/** Array initializer of UART_PFU peripheral base pointers */
#define UART_PFU_BASE_PTRS                       { UART_PFU }

/* VBAT - Peripheral instance base addresses */
/** Peripheral VBAT0 base address */
#define VBAT0_BASE                               (0xA91AB000u)
/** Peripheral VBAT0 base pointer */
#define VBAT0                                    ((VBAT_Type *)VBAT0_BASE)
/** Array initializer of VBAT peripheral base addresses */
#define VBAT_BASE_ADDRS                          { VBAT0_BASE }
/** Array initializer of VBAT peripheral base pointers */
#define VBAT_BASE_PTRS                           { VBAT0 }

/* VREF - Peripheral instance base addresses */
/** Peripheral VREF0 base address */
#define VREF0_BASE                               (0xA91CA000u)
/** Peripheral VREF0 base pointer */
#define VREF0                                    ((VREF_Type *)VREF0_BASE)
/** Array initializer of VREF peripheral base addresses */
#define VREF_BASE_ADDRS                          { VREF0_BASE }
/** Array initializer of VREF peripheral base pointers */
#define VREF_BASE_PTRS                           { VREF0 }

/* WDOG - Peripheral instance base addresses */
/** Peripheral WDOG0 base address */
#define WDOG0_BASE                               (0xA919A000u)
/** Peripheral WDOG0 base pointer */
#define WDOG0                                    ((WDOG_Type *)WDOG0_BASE)
/** Array initializer of WDOG peripheral base addresses */
#define WDOG_BASE_ADDRS                          { WDOG0_BASE }
/** Array initializer of WDOG peripheral base pointers */
#define WDOG_BASE_PTRS                           { WDOG0 }

/* WOR - Peripheral instance base addresses */
/** Peripheral WOR_REGS base address */
#define WOR_REGS_BASE                            (0xA9106100u)
/** Peripheral WOR_REGS base pointer */
#define WOR_REGS                                 ((WOR_Type *)WOR_REGS_BASE)
/** Array initializer of WOR peripheral base addresses */
#define WOR_BASE_ADDRS                           { WOR_REGS_BASE }
/** Array initializer of WOR peripheral base pointers */
#define WOR_BASE_PTRS                            { WOR_REGS }

/* WUU - Peripheral instance base addresses */
/** Peripheral WUU0 base address */
#define WUU0_BASE                                (0xA9199000u)
/** Peripheral WUU0 base pointer */
#define WUU0                                     ((WUU_Type *)WUU0_BASE)
/** Array initializer of WUU peripheral base addresses */
#define WUU_BASE_ADDRS                           { WUU0_BASE }
/** Array initializer of WUU peripheral base pointers */
#define WUU_BASE_PTRS                            { WUU0 }

/* XCVR_ANALOG - Peripheral instance base addresses */
/** Peripheral XCVR_ANALOG base address */
#define XCVR_ANALOG_BASE                         (0xA9107C00u)
/** Peripheral XCVR_ANALOG base pointer */
#define XCVR_ANALOG                              ((XCVR_ANALOG_Type *)XCVR_ANALOG_BASE)
/** Array initializer of XCVR_ANALOG peripheral base addresses */
#define XCVR_ANALOG_BASE_ADDRS                   { XCVR_ANALOG_BASE }
/** Array initializer of XCVR_ANALOG peripheral base pointers */
#define XCVR_ANALOG_BASE_PTRS                    { XCVR_ANALOG }

/* XCVR_MISC - Peripheral instance base addresses */
/** Peripheral XCVR_MISC base address */
#define XCVR_MISC_BASE                           (0xA9107D00u)
/** Peripheral XCVR_MISC base pointer */
#define XCVR_MISC                                ((XCVR_MISC_Type *)XCVR_MISC_BASE)
/** Array initializer of XCVR_MISC peripheral base addresses */
#define XCVR_MISC_BASE_ADDRS                     { XCVR_MISC_BASE }
/** Array initializer of XCVR_MISC peripheral base pointers */
#define XCVR_MISC_BASE_PTRS                      { XCVR_MISC }

/* XCVR_PLL_DIG - Peripheral instance base addresses */
/** Peripheral XCVR_PLL_DIG base address */
#define XCVR_PLL_DIG_BASE                        (0xA9107300u)
/** Peripheral XCVR_PLL_DIG base pointer */
#define XCVR_PLL_DIG                             ((XCVR_PLL_DIG_Type *)XCVR_PLL_DIG_BASE)
/** Array initializer of XCVR_PLL_DIG peripheral base addresses */
#define XCVR_PLL_DIG_BASE_ADDRS                  { XCVR_PLL_DIG_BASE }
/** Array initializer of XCVR_PLL_DIG peripheral base pointers */
#define XCVR_PLL_DIG_BASE_PTRS                   { XCVR_PLL_DIG }

/* XCVR_RX_DIG - Peripheral instance base addresses */
/** Peripheral XCVR_RX_DIG base address */
#define XCVR_RX_DIG_BASE                         (0xA9107000u)
/** Peripheral XCVR_RX_DIG base pointer */
#define XCVR_RX_DIG                              ((XCVR_RX_DIG_Type *)XCVR_RX_DIG_BASE)
/** Array initializer of XCVR_RX_DIG peripheral base addresses */
#define XCVR_RX_DIG_BASE_ADDRS                   { XCVR_RX_DIG_BASE }
/** Array initializer of XCVR_RX_DIG peripheral base pointers */
#define XCVR_RX_DIG_BASE_PTRS                    { XCVR_RX_DIG }

/* XCVR_TSM - Peripheral instance base addresses */
/** Peripheral XCVR_TSM base address */
#define XCVR_TSM_BASE                            (0xA9107800u)
/** Peripheral XCVR_TSM base pointer */
#define XCVR_TSM                                 ((XCVR_TSM_Type *)XCVR_TSM_BASE)
/** Array initializer of XCVR_TSM peripheral base addresses */
#define XCVR_TSM_BASE_ADDRS                      { XCVR_TSM_BASE }
/** Array initializer of XCVR_TSM peripheral base pointers */
#define XCVR_TSM_BASE_PTRS                       { XCVR_TSM }

/* XCVR_TX_DIG - Peripheral instance base addresses */
/** Peripheral XCVR_TX_DIG base address */
#define XCVR_TX_DIG_BASE                         (0xA9107200u)
/** Peripheral XCVR_TX_DIG base pointer */
#define XCVR_TX_DIG                              ((XCVR_TX_DIG_Type *)XCVR_TX_DIG_BASE)
/** Array initializer of XCVR_TX_DIG peripheral base addresses */
#define XCVR_TX_DIG_BASE_ADDRS                   { XCVR_TX_DIG_BASE }
/** Array initializer of XCVR_TX_DIG peripheral base pointers */
#define XCVR_TX_DIG_BASE_PTRS                    { XCVR_TX_DIG }

/* ----------------------------------------------------------------------------
   -- Macros for use with bit field definitions (xxx_SHIFT, xxx_MASK).
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Bit_Field_Generic_Macros Macros for use with bit field definitions (xxx_SHIFT, xxx_MASK).
 * @{
 */

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang system_header
  #endif
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma system_include
#endif

/**
 * @brief Mask and left-shift a bit field value for use in a register bit range.
 * @param field Name of the register bit field.
 * @param value Value of the bit field.
 * @return Masked and shifted value.
 */
#define NXP_VAL2FLD(field, value)    (((value) << (field##_SHIFT)) & (field##_MASK))
/**
 * @brief Mask and right-shift a register value to extract a bit field value.
 * @param field Name of the register bit field.
 * @param value Value of the register.
 * @return Masked and shifted bit field value.
 */
#define NXP_FLD2VAL(field, value)    (((value) & (field##_MASK)) >> (field##_SHIFT))

/*!
 * @}
 */ /* end of group Bit_Field_Generic_Macros */


/* ----------------------------------------------------------------------------
   -- SDK Compatibility
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SDK_Compatibility_Symbols SDK Compatibility
 * @{
 */

#if defined(KW47B42Z83_cm33_core0_H_) || defined(KW47B42Z96_cm33_core0_H_) || defined(KW47B42Z97_cm33_core0_H_) || defined(KW47B42ZB2_cm33_core0_H_) || defined(KW47B42ZB3_cm33_core0_H_) || defined(KW47B42ZB6_cm33_core0_H_) || defined(KW47B42ZB7_cm33_core0_H_) || defined(KW47Z420B2_H_) || defined(KW47Z420B3_H_) || defined(KW47Z42082_H_) || defined(KW47Z42092_H_)
#define RADIO_IS_GEN_4P7 (1)
#define NXP_RADIO_GEN (470)
#define IS_APP_CORE (1)
#define IS_RADIO_CORE (0)
#ifndef KW47_core0_SERIES
#define KW47_core0_SERIES
#endif

/*! @brief define LTC0 from LTC. */
#define LTC0 LTC


/*
 * Macros below define the chip revision.
 */
#define DEVICE_REVISION_A0     (0x10U)
#define DEVICE_REVISION_A1     (0x11U)
#define DEVICE_REVISION_A2     (0x12U)
#define DEVICE_REVISION_OTHERS (0xFFU)

#define IS_CHIP_REVISION_A0() (DEVICE_REVISION_A0 == Chip_GetVersion())
#define IS_CHIP_REVISION_A1() (DEVICE_REVISION_A1 == Chip_GetVersion())
#define IS_CHIP_REVISION_A2() (DEVICE_REVISION_A2 == Chip_GetVersion())

/*!
* @brief Get the chip value.
*
* @return chip version, 0x10: A0 version chip, 0x11: A1 version chip, 0x12: A2 version chip, 0xFF: invalid version.
*/
static inline uint8_t Chip_GetVersion(void)
{
    return DEVICE_REVISION_A0;
}

/*
 * CE STCMs base address.
 */
#define CE_STCM5_BASE (0x20020000u)
#define CE_STCM6_BASE (0x20028000u)
#define CE_STCM7_BASE (0x20030000u)

#elif defined(KW47B42Z83_cm33_core1_H_) || defined(KW47B42Z96_cm33_core1_H_) || defined(KW47B42Z97_cm33_core1_H_) || defined(KW47B42ZB2_cm33_core1_H_) || defined(KW47B42ZB3_cm33_core1_H_) || defined(KW47B42ZB6_cm33_core1_H_) || defined(KW47B42ZB7_cm33_core1_H_)
#define RADIO_IS_GEN_4P7 (1)
#define NXP_RADIO_GEN (470)
#define IS_APP_CORE (0)
#define IS_RADIO_CORE (1)
#ifndef KW47_core1_SERIES
#define KW47_core1_SERIES
#endif

/*! @brief define LTC0 from LTC. */
#define LTC0 LTC

#endif

/*!
 * @}
 */ /* end of group SDK_Compatibility_Symbols */


#endif  /* KW47B42ZB7_CM33_CORE1_COMMON_H_ */

