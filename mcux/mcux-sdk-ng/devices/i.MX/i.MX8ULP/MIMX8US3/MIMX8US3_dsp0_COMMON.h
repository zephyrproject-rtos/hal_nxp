/*
** ###################################################################
**     Processors:          MIMX8US3CVP08_dsp0
**                          MIMX8US3DVK08_dsp0
**                          MIMX8US3DVP08_dsp0
**
**     Compiler:            Xtensa Compiler
**     Reference manual:    IMX8ULPRM, Rev. D, December. 2022
**     Version:             rev. 6.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         Peripheral Access Layer for MIMX8US3_dsp0
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2020-05-25)
**         Initial version.
**     - rev. 2.0 (2020-09-18)
**         Base on rev A RM
**     - rev. 3.0 (2021-01-20)
**         Base on rev A.1 RM
**     - rev. 4.0 (2021-07-05)
**         Base on rev B RM
**     - rev. 5.0 (2023-04-27)
**         Base on rev D RM
**     - rev. 6.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file MIMX8US3_dsp0_COMMON.h
 * @version 6.0
 * @date 2024-10-29
 * @brief Peripheral Access Layer for MIMX8US3_dsp0
 *
 * Peripheral Access Layer for MIMX8US3_dsp0
 */

#if !defined(MIMX8US3_DSP0_COMMON_H_)
#define MIMX8US3_DSP0_COMMON_H_                  /**< Symbol preventing repeated inclusion */

/** Memory map major version (memory maps with equal major version number are
 * compatible) */
#define MCU_MEM_MAP_VERSION 0x0600U
/** Memory map minor version */
#define MCU_MEM_MAP_VERSION_MINOR 0x0000U

/* ----------------------------------------------------------------------------
   --
   ---------------------------------------------------------------------------- */

/* IO definitions (access restrictions to peripheral registers) */
/**
    \defgroup CMSIS_glob_defs CMSIS Global Defines
    <strong>IO Type Qualifiers</strong> are used
    \li to specify the access to peripheral variables.
    \li for automatic generation of peripheral register debug information.
*/
#define     __I     volatile const       /*!< Defines 'read only' permissions */
#define     __O     volatile             /*!< Defines 'write only' permissions */
#define     __IO    volatile             /*!< Defines 'read / write' permissions */

/* following defines should be used for structure members */
#define     __IM     volatile const      /*! Defines 'read only' structure member permissions */
#define     __OM     volatile            /*! Defines 'write only' structure member permissions */
#define     __IOM    volatile            /*! Defines 'read / write' structure member permissions */

#define __STATIC_INLINE static inline

#define __BKPT(value) do {} while(0)
#define __NOP() do {} while(0)

#include "system_MIMX8US3_dsp0.h"     /* Device specific configuration file */



/* ----------------------------------------------------------------------------
   -- Interrupt vector numbers
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Interrupt_vector_numbers Interrupt vector numbers
 * @{
 */

/** Interrupt Number Definitions */
#define NUMBER_OF_INT_VECTORS 32                 /**< Number of interrupts in the Vector table */

typedef enum IRQn {
  /* Auxiliary constants */
  NotAvail_IRQn                = -128,             /**< Not available device specific interrupt */

  /* Core interrupts */
  NonMaskableInt_IRQn          = 0,                /**< SysIRQ, Non Maskable Interrupt */
  Software_IRQn                = 1,                /**< Software triggered Interrupt */
  RtosTimer0_IRQn              = 2,                /**< Internal RTOS Timer0 Interrupt */
  RtosTimer1_IRQn              = 3,                /**< Internal RTOS Timer1 Interrupt */
  Profiling_IRQn               = 4,                /**< Profiling Interrupt */

  /* Device specific interrupts */
  DMA0_0_IRQn                  = 5,                /**< DMA0 Channel 0 Error or Transfer Complete */
  DMA0_1_IRQn                  = 6,                /**< DMA0 Channel 1 Error or Transfer Complete */
  DMA0_2_IRQn                  = 7,                /**< DMA0 Channel 2 Error or Transfer Complete */
  DMA0_3_IRQn                  = 8,                /**< DMA0 Channel 3 Error or Transfer Complete */
  DMA0_4_IRQn                  = 9,                /**< DMA0 Channel 4 Error or Transfer Complete */
  DMA0_5_IRQn                  = 10,               /**< DMA0 Channel 5 Error or Transfer Complete */
  DMA0_6_IRQn                  = 11,               /**< DMA0 Channel 6 Error or Transfer Complete */
  DMA0_7_IRQn                  = 12,               /**< DMA0 Channel 7 Error or Transfer Complete */
  MU1_B_IRQn                   = 13,               /**< Messaging Unit 1 - Side B (to communicate with M33) */
  WDOG2_IRQn                   = 14,               /**< Watchdog 2 Interrupt */
  LPTMR0_IRQn                  = 15,               /**< Low Power Timer 0 */
  I3C1_IRQn                    = 16,               /**< Improved Inter-Integrated Circuit 1 interrupt */
  TPM2_IRQn                    = 17,               /**< Timer PWM module 2 */
  TPM3_IRQn                    = 18,               /**< Timer PWM module 3 */
  MRT0_IRQn                    = 19,               /**< Multi-Rate Timer interrupt */
  LPI2C2_IRQn                  = 20,               /**< Low Power Inter-Integrated Circuit module 2 */
  LPI2C3_IRQn                  = 21,               /**< Low Power Inter-Integrated Circuit module 3 */
  LPSPI2_IRQn                  = 22,               /**< Low Power Serial Peripheral Interface 2 */
  LPSPI3_IRQn                  = 23,               /**< Low Power Serial Peripheral Interface 3 */
  LPUART2_IRQn                 = 24,               /**< Low Power UART 2 */
  AHB_Error_IRQn               = 25,               /**< AHB Bus Error interrupt */
  PDM_EVENT_IRQn               = 26,               /**< Digital Microphone interrupt */
  PDM_HWVAD_EVENT_IRQn         = 27,               /**< Digital Microphone Voice Activity Detection interrupt */
  SAI2_IRQn                    = 28,               /**< Serial Audio Interface 2 */
  SAI3_IRQn                    = 29,               /**< Serial Audio Interface 3 */
  GPIOA_IRQn                   = 30,               /**< General Purpose Input/Output A interrupt */
  GPIOB_IRQn                   = 31                /**< General Purpose Input/Output B interrupt */
} IRQn_Type;

/*!
 * @}
 */ /* end of group Interrupt_vector_numbers */


#ifndef MIMX8US3_dsp0_SERIES
#define MIMX8US3_dsp0_SERIES
#endif
/* CPU specific feature definitions */
#include "MIMX8US3_dsp0_features.h"

/* ADC - Peripheral instance base addresses */
/** Peripheral ADC0 base address */
#define ADC0_BASE                                (0x28040000u)
/** Peripheral ADC0 base pointer */
#define ADC0                                     ((ADC_Type *)ADC0_BASE)
/** Peripheral ADC1 base address */
#define ADC1_BASE                                (0x280A2000u)
/** Peripheral ADC1 base pointer */
#define ADC1                                     ((ADC_Type *)ADC1_BASE)
/** Array initializer of ADC peripheral base addresses */
#define ADC_BASE_ADDRS                           { ADC0_BASE, ADC1_BASE }
/** Array initializer of ADC peripheral base pointers */
#define ADC_BASE_PTRS                            { ADC0, ADC1 }

/* AHB_ADDR_REMAP - Peripheral instance base addresses */
/** Peripheral ADDR_REMAP0 base address */
#define ADDR_REMAP0_BASE                         (0x28039800u)
/** Peripheral ADDR_REMAP0 base pointer */
#define ADDR_REMAP0                              ((AHB_ADDR_REMAP_Type *)ADDR_REMAP0_BASE)
/** Peripheral ADDR_REMAP1 base address */
#define ADDR_REMAP1_BASE                         (0x29810800u)
/** Peripheral ADDR_REMAP1 base pointer */
#define ADDR_REMAP1                              ((AHB_ADDR_REMAP_Type *)ADDR_REMAP1_BASE)
/** Array initializer of AHB_ADDR_REMAP peripheral base addresses */
#define AHB_ADDR_REMAP_BASE_ADDRS                { ADDR_REMAP0_BASE, ADDR_REMAP1_BASE }
/** Array initializer of AHB_ADDR_REMAP peripheral base pointers */
#define AHB_ADDR_REMAP_BASE_PTRS                 { ADDR_REMAP0, ADDR_REMAP1 }

/* AXBS - Peripheral instance base addresses */
/** Peripheral AXBS0 base address */
#define AXBS0_BASE                               (0x28000000u)
/** Peripheral AXBS0 base pointer */
#define AXBS0                                    ((AXBS_Type *)AXBS0_BASE)
/** Peripheral AXBS1 base address */
#define AXBS1_BASE                               (0x29000000u)
/** Peripheral AXBS1 base pointer */
#define AXBS1                                    ((AXBS_Type *)AXBS1_BASE)
/** Array initializer of AXBS peripheral base addresses */
#define AXBS_BASE_ADDRS                          { AXBS0_BASE, AXBS1_BASE }
/** Array initializer of AXBS peripheral base pointers */
#define AXBS_BASE_PTRS                           { AXBS0, AXBS1 }

/* BBNSM - Peripheral instance base addresses */
/** Peripheral BBNSM base address */
#define BBNSM_BASE                               (0x28038000u)
/** Peripheral BBNSM base pointer */
#define BBNSM                                    ((BBNSM_Type *)BBNSM_BASE)
/** Array initializer of BBNSM peripheral base addresses */
#define BBNSM_BASE_ADDRS                         { BBNSM_BASE }
/** Array initializer of BBNSM peripheral base pointers */
#define BBNSM_BASE_PTRS                          { BBNSM }

/* CACHE64_CTRL - Peripheral instance base addresses */
/** Peripheral CACHE64_CTRL0 base address */
#define CACHE64_CTRL0_BASE                       (0x28046000u)
/** Peripheral CACHE64_CTRL0 base pointer */
#define CACHE64_CTRL0                            ((CACHE64_CTRL_Type *)CACHE64_CTRL0_BASE)
/** Peripheral CACHE64_CTRL1 base address */
#define CACHE64_CTRL1_BASE                       (0x28046800u)
/** Peripheral CACHE64_CTRL1 base pointer */
#define CACHE64_CTRL1                            ((CACHE64_CTRL_Type *)CACHE64_CTRL1_BASE)
/** Array initializer of CACHE64_CTRL peripheral base addresses */
#define CACHE64_CTRL_BASE_ADDRS                  { CACHE64_CTRL0_BASE, CACHE64_CTRL1_BASE }
/** Array initializer of CACHE64_CTRL peripheral base pointers */
#define CACHE64_CTRL_BASE_PTRS                   { CACHE64_CTRL0, CACHE64_CTRL1 }

/* CAN - Peripheral instance base addresses */
/** Peripheral CAN0 base address */
#define CAN0_BASE                                (0x280A8000u)
/** Peripheral CAN0 base pointer */
#define CAN0                                     ((CAN_Type *)CAN0_BASE)
/** Array initializer of CAN peripheral base addresses */
#define CAN_BASE_ADDRS                           { CAN0_BASE }
/** Array initializer of CAN peripheral base pointers */
#define CAN_BASE_PTRS                            { CAN0 }

/* CASPER - Peripheral instance base addresses */
/** Peripheral CASPER base address */
#define CASPER_BASE                              (0x28410000u)
/** Peripheral CASPER base pointer */
#define CASPER                                   ((CASPER_Type *)CASPER_BASE)
/** Array initializer of CASPER peripheral base addresses */
#define CASPER_BASE_ADDRS                        { CASPER_BASE }
/** Array initializer of CASPER peripheral base pointers */
#define CASPER_BASE_PTRS                         { CASPER }

/* CGC - Peripheral instance base addresses */
/** Peripheral CGC_RTD base address */
#define CGC_RTD_BASE                             (0x2802F000u)
/** Peripheral CGC_RTD base pointer */
#define CGC_RTD                                  ((CGC_Type *)CGC_RTD_BASE)
/** Array initializer of CGC peripheral base addresses */
#define CGC_BASE_ADDRS                           { CGC_RTD_BASE }
/** Array initializer of CGC peripheral base pointers */
#define CGC_BASE_PTRS                            { CGC_RTD }

/* CGC_AD - Peripheral instance base addresses */
/** Peripheral CGC_AD base address */
#define CGC_AD_BASE                              (0x292C0000u)
/** Peripheral CGC_AD base pointer */
#define CGC_AD                                   ((CGC_AD_Type *)CGC_AD_BASE)
/** Array initializer of CGC_AD peripheral base addresses */
#define CGC_AD_BASE_ADDRS                        { CGC_AD_BASE }
/** Array initializer of CGC_AD peripheral base pointers */
#define CGC_AD_BASE_PTRS                         { CGC_AD }

/* CGC_LPAV - Peripheral instance base addresses */
/** Peripheral CGC_LPAV base address */
#define CGC_LPAV_BASE                            (0x2DA60000u)
/** Peripheral CGC_LPAV base pointer */
#define CGC_LPAV                                 ((CGC_LPAV_Type *)CGC_LPAV_BASE)
/** Array initializer of CGC_LPAV peripheral base addresses */
#define CGC_LPAV_BASE_ADDRS                      { CGC_LPAV_BASE }
/** Array initializer of CGC_LPAV peripheral base pointers */
#define CGC_LPAV_BASE_PTRS                       { CGC_LPAV }

/* CMC - Peripheral instance base addresses */
/** Peripheral CMC_RTD base address */
#define CMC_RTD_BASE                             (0x28025000u)
/** Peripheral CMC_RTD base pointer */
#define CMC_RTD                                  ((CMC_Type *)CMC_RTD_BASE)
/** Array initializer of CMC peripheral base addresses */
#define CMC_BASE_ADDRS                           { CMC_RTD_BASE }
/** Array initializer of CMC peripheral base pointers */
#define CMC_BASE_PTRS                            { CMC_RTD }

/* CMC_AD - Peripheral instance base addresses */
/** Peripheral CMC_AD base address */
#define CMC_AD_BASE                              (0x29240000u)
/** Peripheral CMC_AD base pointer */
#define CMC_AD                                   ((CMC_AD_Type *)CMC_AD_BASE)
/** Array initializer of CMC_AD peripheral base addresses */
#define CMC_AD_BASE_ADDRS                        { CMC_AD_BASE }
/** Array initializer of CMC_AD peripheral base pointers */
#define CMC_AD_BASE_PTRS                         { CMC_AD }

/* CMC_LPAC - Peripheral instance base addresses */
/** Peripheral CMC_LPAC base address */
#define CMC_LPAC_BASE                            (0x2DA40000u)
/** Peripheral CMC_LPAC base pointer */
#define CMC_LPAC                                 ((CMC_LPAC_Type *)CMC_LPAC_BASE)
/** Array initializer of CMC_LPAC peripheral base addresses */
#define CMC_LPAC_BASE_ADDRS                      { CMC_LPAC_BASE }
/** Array initializer of CMC_LPAC peripheral base pointers */
#define CMC_LPAC_BASE_PTRS                       { CMC_LPAC }

/* CMP - Peripheral instance base addresses */
/** Peripheral CMP0 base address */
#define CMP0_BASE                                (0x28041000u)
/** Peripheral CMP0 base pointer */
#define CMP0                                     ((CMP_Type *)CMP0_BASE)
/** Peripheral CMP1 base address */
#define CMP1_BASE                                (0x28042000u)
/** Peripheral CMP1 base pointer */
#define CMP1                                     ((CMP_Type *)CMP1_BASE)
/** Array initializer of CMP peripheral base addresses */
#define CMP_BASE_ADDRS                           { CMP0_BASE, CMP1_BASE }
/** Array initializer of CMP peripheral base pointers */
#define CMP_BASE_PTRS                            { CMP0, CMP1 }

/* DAC - Peripheral instance base addresses */
/** Peripheral DAC0 base address */
#define DAC0_BASE                                (0x28043000u)
/** Peripheral DAC0 base pointer */
#define DAC0                                     ((DAC_Type *)DAC0_BASE)
/** Peripheral DAC1 base address */
#define DAC1_BASE                                (0x28044000u)
/** Peripheral DAC1 base pointer */
#define DAC1                                     ((DAC_Type *)DAC1_BASE)
/** Array initializer of DAC peripheral base addresses */
#define DAC_BASE_ADDRS                           { DAC0_BASE, DAC1_BASE }
/** Array initializer of DAC peripheral base pointers */
#define DAC_BASE_PTRS                            { DAC0, DAC1 }

/* DMA - Peripheral instance base addresses */
/** Peripheral DMA0 base address */
#define DMA0_BASE                                (0x28001000u)
/** Peripheral DMA0 base pointer */
#define DMA0                                     ((DMA_Type *)DMA0_BASE)
/** Array initializer of DMA peripheral base addresses */
#define DMA_BASE_ADDRS                           { DMA0_BASE }
/** Array initializer of DMA peripheral base pointers */
#define DMA_BASE_PTRS                            { DMA0 }
/** Interrupt vectors for the DMA peripheral type */
#define DMA_IRQS                                 { { DMA0_0_IRQn, DMA0_1_IRQn, DMA0_2_IRQn, DMA0_3_IRQn, DMA0_4_IRQn, DMA0_5_IRQn, DMA0_6_IRQn, DMA0_7_IRQn } }
#define DMA_ERROR_IRQS                           { { DMA0_0_IRQn, DMA0_1_IRQn, DMA0_2_IRQn, DMA0_3_IRQn, DMA0_4_IRQn, DMA0_5_IRQn, DMA0_6_IRQn, DMA0_7_IRQn } }

/* DMA_AD - Peripheral instance base addresses */
/** Peripheral DMA1 base address */
#define DMA1_BASE                                (0x29010000u)
/** Peripheral DMA1 base pointer */
#define DMA1                                     ((DMA_AD_Type *)DMA1_BASE)
/** Peripheral DMA2 base address */
#define DMA2_BASE                                (0x2D800000u)
/** Peripheral DMA2 base pointer */
#define DMA2                                     ((DMA_AD_Type *)DMA2_BASE)
/** Array initializer of DMA_AD peripheral base addresses */
#define DMA_AD_BASE_ADDRS                        { DMA1_BASE, DMA2_BASE }
/** Array initializer of DMA_AD peripheral base pointers */
#define DMA_AD_BASE_PTRS                         { DMA1, DMA2 }

/* ENET - Peripheral instance base addresses */
/** Peripheral ENET base address */
#define ENET_BASE                                (0x29950000u)
/** Peripheral ENET base pointer */
#define ENET                                     ((ENET_Type *)ENET_BASE)
/** Array initializer of ENET peripheral base addresses */
#define ENET_BASE_ADDRS                          { ENET_BASE }
/** Array initializer of ENET peripheral base pointers */
#define ENET_BASE_PTRS                           { ENET }

/* EPDC - Peripheral instance base addresses */
/** Peripheral EPDC base address */
#define EPDC_BASE                                (0x2DB30000u)
/** Peripheral EPDC base pointer */
#define EPDC                                     ((EPDC_Type *)EPDC_BASE)
/** Array initializer of EPDC peripheral base addresses */
#define EPDC_BASE_ADDRS                          { EPDC_BASE }
/** Array initializer of EPDC peripheral base pointers */
#define EPDC_BASE_PTRS                           { EPDC }

/* EWM - Peripheral instance base addresses */
/** Peripheral EWM0 base address */
#define EWM0_BASE                                (0x2802E000u)
/** Peripheral EWM0 base pointer */
#define EWM0                                     ((EWM_Type *)EWM0_BASE)
/** Array initializer of EWM peripheral base addresses */
#define EWM_BASE_ADDRS                           { EWM0_BASE }
/** Array initializer of EWM peripheral base pointers */
#define EWM_BASE_PTRS                            { EWM0 }

/* FLEXIO - Peripheral instance base addresses */
/** Peripheral FLEXIO0 base address */
#define FLEXIO0_BASE                             (0x2803C000u)
/** Peripheral FLEXIO0 base pointer */
#define FLEXIO0                                  ((FLEXIO_Type *)FLEXIO0_BASE)
/** Peripheral FLEXIO1 base address */
#define FLEXIO1_BASE                             (0x29350000u)
/** Peripheral FLEXIO1 base pointer */
#define FLEXIO1                                  ((FLEXIO_Type *)FLEXIO1_BASE)
/** Array initializer of FLEXIO peripheral base addresses */
#define FLEXIO_BASE_ADDRS                        { FLEXIO0_BASE, FLEXIO1_BASE }
/** Array initializer of FLEXIO peripheral base pointers */
#define FLEXIO_BASE_PTRS                         { FLEXIO0, FLEXIO1 }

/* FLEXSPI - Peripheral instance base addresses */
/** Peripheral FLEXSPI0 base address */
#define FLEXSPI0_BASE                            (0x28039000u)
/** Peripheral FLEXSPI0 base pointer */
#define FLEXSPI0                                 ((FLEXSPI_Type *)FLEXSPI0_BASE)
/** Peripheral FLEXSPI1 base address */
#define FLEXSPI1_BASE                            (0x28092000u)
/** Peripheral FLEXSPI1 base pointer */
#define FLEXSPI1                                 ((FLEXSPI_Type *)FLEXSPI1_BASE)
/** Peripheral FLEXSPI2 base address */
#define FLEXSPI2_BASE                            (0x29810000u)
/** Peripheral FLEXSPI2 base pointer */
#define FLEXSPI2                                 ((FLEXSPI_Type *)FLEXSPI2_BASE)
/** Array initializer of FLEXSPI peripheral base addresses */
#define FLEXSPI_BASE_ADDRS                       { FLEXSPI0_BASE, FLEXSPI1_BASE, FLEXSPI2_BASE }
/** Array initializer of FLEXSPI peripheral base pointers */
#define FLEXSPI_BASE_PTRS                        { FLEXSPI0, FLEXSPI1, FLEXSPI2 }
/** FlexSPI AMBA memory base alias count */
#define FLEXSPI_AMBA_BASE_ALIAS_COUNT     (1)
/* FlexSPI AMBA base address array. */
#define FlexSPI_AMBA_BASE_ARRAY                  { {0x04000000u}, {0x40000000u}, {0x60000000u} }
/* FlexSPI AMBA end address array. */
#define FlexSPI_AMBA_END_ARRAY                   { {0x0BFFFFFFu}, {0x4FFFFFFFu}, {0x6FFFFFFFu} }
/* FlexSPI0 AMBA base address. */
#define FlexSPI0_AMBA_BASE                        (0x04000000u)
/* FlexSPI1 AMBA base address. */
#define FlexSPI1_AMBA_BASE                        (0x40000000u)
/* FlexSPI2 AMBA base address. */
#define FlexSPI2_AMBA_BASE                        (0x60000000u)


/* I2S - Peripheral instance base addresses */
/** Peripheral SAI0 base address */
#define SAI0_BASE                                (0x2809C000u)
/** Peripheral SAI0 base pointer */
#define SAI0                                     ((I2S_Type *)SAI0_BASE)
/** Peripheral SAI1 base address */
#define SAI1_BASE                                (0x2809D000u)
/** Peripheral SAI1 base pointer */
#define SAI1                                     ((I2S_Type *)SAI1_BASE)
/** Peripheral SAI2 base address */
#define SAI2_BASE                                (0x2810F000u)
/** Peripheral SAI2 base pointer */
#define SAI2                                     ((I2S_Type *)SAI2_BASE)
/** Peripheral SAI3 base address */
#define SAI3_BASE                                (0x28110000u)
/** Peripheral SAI3 base pointer */
#define SAI3                                     ((I2S_Type *)SAI3_BASE)
/** Peripheral SAI4 base address */
#define SAI4_BASE                                (0x29880000u)
/** Peripheral SAI4 base pointer */
#define SAI4                                     ((I2S_Type *)SAI4_BASE)
/** Peripheral SAI5 base address */
#define SAI5_BASE                                (0x29890000u)
/** Peripheral SAI5 base pointer */
#define SAI5                                     ((I2S_Type *)SAI5_BASE)
/** Peripheral SAI6 base address */
#define SAI6_BASE                                (0x2DA90000u)
/** Peripheral SAI6 base pointer */
#define SAI6                                     ((I2S_Type *)SAI6_BASE)
/** Peripheral SAI7 base address */
#define SAI7_BASE                                (0x2DAA0000u)
/** Peripheral SAI7 base pointer */
#define SAI7                                     ((I2S_Type *)SAI7_BASE)
/** Array initializer of I2S peripheral base addresses */
#define I2S_BASE_ADDRS                           { SAI0_BASE, SAI1_BASE, SAI2_BASE, SAI3_BASE, SAI4_BASE, SAI5_BASE, SAI6_BASE, SAI7_BASE }
/** Array initializer of I2S peripheral base pointers */
#define I2S_BASE_PTRS                            { SAI0, SAI1, SAI2, SAI3, SAI4, SAI5, SAI6, SAI7 }
/** Interrupt vectors for the I2S peripheral type */
#define I2S_RX_IRQS                              { NotAvail_IRQn, NotAvail_IRQn, SAI2_IRQn, SAI3_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn }
#define I2S_TX_IRQS                              { NotAvail_IRQn, NotAvail_IRQn, SAI2_IRQn, SAI3_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn }

/* I3C - Peripheral instance base addresses */
/** Peripheral I3C0 base address */
#define I3C0_BASE                                (0x2803D000u)
/** Peripheral I3C0 base pointer */
#define I3C0                                     ((I3C_Type *)I3C0_BASE)
/** Peripheral I3C1 base address */
#define I3C1_BASE                                (0x2810A000u)
/** Peripheral I3C1 base pointer */
#define I3C1                                     ((I3C_Type *)I3C1_BASE)
/** Peripheral I3C2 base address */
#define I3C2_BASE                                (0x29360000u)
/** Peripheral I3C2 base pointer */
#define I3C2                                     ((I3C_Type *)I3C2_BASE)
/** Array initializer of I3C peripheral base addresses */
#define I3C_BASE_ADDRS                           { I3C0_BASE, I3C1_BASE, I3C2_BASE }
/** Array initializer of I3C peripheral base pointers */
#define I3C_BASE_PTRS                            { I3C0, I3C1, I3C2 }
/** Interrupt vectors for the I3C peripheral type */
#define I3C_IRQS                                 { NotAvail_IRQn, I3C1_IRQn, NotAvail_IRQn }

/* IOMUXC0 - Peripheral instance base addresses */
/** Peripheral IOMUXC0 base address */
#define IOMUXC0_BASE                             (0x280A1000u)
/** Peripheral IOMUXC0 base pointer */
#define IOMUXC0                                  ((IOMUXC0_Type *)IOMUXC0_BASE)
/** Array initializer of IOMUXC0 peripheral base addresses */
#define IOMUXC0_BASE_ADDRS                       { IOMUXC0_BASE }
/** Array initializer of IOMUXC0 peripheral base pointers */
#define IOMUXC0_BASE_PTRS                        { IOMUXC0 }

/* IOMUXC1 - Peripheral instance base addresses */
/** Peripheral IOMUXC1 base address */
#define IOMUXC1_BASE                             (0x298C0000u)
/** Peripheral IOMUXC1 base pointer */
#define IOMUXC1                                  ((IOMUXC1_Type *)IOMUXC1_BASE)
/** Array initializer of IOMUXC1 peripheral base addresses */
#define IOMUXC1_BASE_ADDRS                       { IOMUXC1_BASE }
/** Array initializer of IOMUXC1 peripheral base pointers */
#define IOMUXC1_BASE_PTRS                        { IOMUXC1 }

/* ISI - Peripheral instance base addresses */
/** Peripheral ISI0 base address */
#define ISI0_BASE                                (0x2DAC0000u)
/** Peripheral ISI0 base pointer */
#define ISI0                                     ((ISI_Type *)ISI0_BASE)
/** Array initializer of ISI peripheral base addresses */
#define ISI_BASE_ADDRS                           { ISI0_BASE }
/** Array initializer of ISI peripheral base pointers */
#define ISI_BASE_PTRS                            { ISI0 }

/* LCDIF - Peripheral instance base addresses */
/** Peripheral LCDIF base address */
#define LCDIF_BASE                               (0x2E050000u)
/** Peripheral LCDIF base pointer */
#define LCDIF                                    ((LCDIF_Type *)LCDIF_BASE)
/** Array initializer of LCDIF peripheral base addresses */
#define LCDIF_BASE_ADDRS                         { LCDIF_BASE }
/** Array initializer of LCDIF peripheral base pointers */
#define LCDIF_BASE_PTRS                          { LCDIF }

/* LPDDR - Peripheral instance base addresses */
/** Peripheral LPDDR base address */
#define LPDDR_BASE                               (0x2E060000u)
/** Peripheral LPDDR base pointer */
#define LPDDR                                    ((LPDDR_Type *)LPDDR_BASE)
/** Array initializer of LPDDR peripheral base addresses */
#define LPDDR_BASE_ADDRS                         { LPDDR_BASE }
/** Array initializer of LPDDR peripheral base pointers */
#define LPDDR_BASE_PTRS                          { LPDDR }

/* LPI2C - Peripheral instance base addresses */
/** Peripheral LPI2C0 base address */
#define LPI2C0_BASE                              (0x28098000u)
/** Peripheral LPI2C0 base pointer */
#define LPI2C0                                   ((LPI2C_Type *)LPI2C0_BASE)
/** Peripheral LPI2C1 base address */
#define LPI2C1_BASE                              (0x28099000u)
/** Peripheral LPI2C1 base pointer */
#define LPI2C1                                   ((LPI2C_Type *)LPI2C1_BASE)
/** Peripheral LPI2C2 base address */
#define LPI2C2_BASE                              (0x28108000u)
/** Peripheral LPI2C2 base pointer */
#define LPI2C2                                   ((LPI2C_Type *)LPI2C2_BASE)
/** Peripheral LPI2C3 base address */
#define LPI2C3_BASE                              (0x28109000u)
/** Peripheral LPI2C3 base pointer */
#define LPI2C3                                   ((LPI2C_Type *)LPI2C3_BASE)
/** Peripheral LPI2C4 base address */
#define LPI2C4_BASE                              (0x29370000u)
/** Peripheral LPI2C4 base pointer */
#define LPI2C4                                   ((LPI2C_Type *)LPI2C4_BASE)
/** Peripheral LPI2C5 base address */
#define LPI2C5_BASE                              (0x29380000u)
/** Peripheral LPI2C5 base pointer */
#define LPI2C5                                   ((LPI2C_Type *)LPI2C5_BASE)
/** Peripheral LPI2C6 base address */
#define LPI2C6_BASE                              (0x29840000u)
/** Peripheral LPI2C6 base pointer */
#define LPI2C6                                   ((LPI2C_Type *)LPI2C6_BASE)
/** Peripheral LPI2C7 base address */
#define LPI2C7_BASE                              (0x29850000u)
/** Peripheral LPI2C7 base pointer */
#define LPI2C7                                   ((LPI2C_Type *)LPI2C7_BASE)
/** Array initializer of LPI2C peripheral base addresses */
#define LPI2C_BASE_ADDRS                         { LPI2C0_BASE, LPI2C1_BASE, LPI2C2_BASE, LPI2C3_BASE, LPI2C4_BASE, LPI2C5_BASE, LPI2C6_BASE, LPI2C7_BASE }
/** Array initializer of LPI2C peripheral base pointers */
#define LPI2C_BASE_PTRS                          { LPI2C0, LPI2C1, LPI2C2, LPI2C3, LPI2C4, LPI2C5, LPI2C6, LPI2C7 }
/** Interrupt vectors for the LPI2C peripheral type */
#define LPI2C_IRQS                               { NotAvail_IRQn, NotAvail_IRQn, LPI2C2_IRQn, LPI2C3_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn }

/* LPIT - Peripheral instance base addresses */
/** Peripheral LPIT0 base address */
#define LPIT0_BASE                               (0x2803B000u)
/** Peripheral LPIT0 base pointer */
#define LPIT0                                    ((LPIT_Type *)LPIT0_BASE)
/** Peripheral LPIT1 base address */
#define LPIT1_BASE                               (0x29320000u)
/** Peripheral LPIT1 base pointer */
#define LPIT1                                    ((LPIT_Type *)LPIT1_BASE)
/** Array initializer of LPIT peripheral base addresses */
#define LPIT_BASE_ADDRS                          { LPIT0_BASE, LPIT1_BASE }
/** Array initializer of LPIT peripheral base pointers */
#define LPIT_BASE_PTRS                           { LPIT0, LPIT1 }

/* LPSPI - Peripheral instance base addresses */
/** Peripheral LPSPI0 base address */
#define LPSPI0_BASE                              (0x2803E000u)
/** Peripheral LPSPI0 base pointer */
#define LPSPI0                                   ((LPSPI_Type *)LPSPI0_BASE)
/** Peripheral LPSPI1 base address */
#define LPSPI1_BASE                              (0x2803F000u)
/** Peripheral LPSPI1 base pointer */
#define LPSPI1                                   ((LPSPI_Type *)LPSPI1_BASE)
/** Peripheral LPSPI2 base address */
#define LPSPI2_BASE                              (0x2810D000u)
/** Peripheral LPSPI2 base pointer */
#define LPSPI2                                   ((LPSPI_Type *)LPSPI2_BASE)
/** Peripheral LPSPI3 base address */
#define LPSPI3_BASE                              (0x2810E000u)
/** Peripheral LPSPI3 base pointer */
#define LPSPI3                                   ((LPSPI_Type *)LPSPI3_BASE)
/** Peripheral LPSPI4 base address */
#define LPSPI4_BASE                              (0x293B0000u)
/** Peripheral LPSPI4 base pointer */
#define LPSPI4                                   ((LPSPI_Type *)LPSPI4_BASE)
/** Peripheral LPSPI5 base address */
#define LPSPI5_BASE                              (0x293C0000u)
/** Peripheral LPSPI5 base pointer */
#define LPSPI5                                   ((LPSPI_Type *)LPSPI5_BASE)
/** Array initializer of LPSPI peripheral base addresses */
#define LPSPI_BASE_ADDRS                         { LPSPI0_BASE, LPSPI1_BASE, LPSPI2_BASE, LPSPI3_BASE, LPSPI4_BASE, LPSPI5_BASE }
/** Array initializer of LPSPI peripheral base pointers */
#define LPSPI_BASE_PTRS                          { LPSPI0, LPSPI1, LPSPI2, LPSPI3, LPSPI4, LPSPI5 }
/** Interrupt vectors for the LPSPI peripheral type */
#define LPSPI_IRQS                               { NotAvail_IRQn, NotAvail_IRQn, LPSPI2_IRQn, LPSPI3_IRQn, NotAvail_IRQn, NotAvail_IRQn }

/* LPTMR - Peripheral instance base addresses */
/** Peripheral LPTMR0 base address */
#define LPTMR0_BASE                              (0x28093000u)
/** Peripheral LPTMR0 base pointer */
#define LPTMR0                                   ((LPTMR_Type *)LPTMR0_BASE)
/** Peripheral LPTMR1 base address */
#define LPTMR1_BASE                              (0x28094000u)
/** Peripheral LPTMR1 base pointer */
#define LPTMR1                                   ((LPTMR_Type *)LPTMR1_BASE)
/** Array initializer of LPTMR peripheral base addresses */
#define LPTMR_BASE_ADDRS                         { LPTMR0_BASE, LPTMR1_BASE }
/** Array initializer of LPTMR peripheral base pointers */
#define LPTMR_BASE_PTRS                          { LPTMR0, LPTMR1 }
/** Interrupt vectors for the LPTMR peripheral type */
#define LPTMR_IRQS                               { LPTMR0_IRQn, NotAvail_IRQn }

/* LPUART - Peripheral instance base addresses */
/** Peripheral LPUART0 base address */
#define LPUART0_BASE                             (0x2809A000u)
/** Peripheral LPUART0 base pointer */
#define LPUART0                                  ((LPUART_Type *)LPUART0_BASE)
/** Peripheral LPUART1 base address */
#define LPUART1_BASE                             (0x2809B000u)
/** Peripheral LPUART1 base pointer */
#define LPUART1                                  ((LPUART_Type *)LPUART1_BASE)
/** Peripheral LPUART2 base address */
#define LPUART2_BASE                             (0x2810B000u)
/** Peripheral LPUART2 base pointer */
#define LPUART2                                  ((LPUART_Type *)LPUART2_BASE)
/** Peripheral LPUART3 base address */
#define LPUART3_BASE                             (0x2810C000u)
/** Peripheral LPUART3 base pointer */
#define LPUART3                                  ((LPUART_Type *)LPUART3_BASE)
/** Peripheral LPUART4 base address */
#define LPUART4_BASE                             (0x29390000u)
/** Peripheral LPUART4 base pointer */
#define LPUART4                                  ((LPUART_Type *)LPUART4_BASE)
/** Peripheral LPUART5 base address */
#define LPUART5_BASE                             (0x293A0000u)
/** Peripheral LPUART5 base pointer */
#define LPUART5                                  ((LPUART_Type *)LPUART5_BASE)
/** Peripheral LPUART6 base address */
#define LPUART6_BASE                             (0x29860000u)
/** Peripheral LPUART6 base pointer */
#define LPUART6                                  ((LPUART_Type *)LPUART6_BASE)
/** Peripheral LPUART7 base address */
#define LPUART7_BASE                             (0x29870000u)
/** Peripheral LPUART7 base pointer */
#define LPUART7                                  ((LPUART_Type *)LPUART7_BASE)
/** Array initializer of LPUART peripheral base addresses */
#define LPUART_BASE_ADDRS                        { LPUART0_BASE, LPUART1_BASE, LPUART2_BASE, LPUART3_BASE, LPUART4_BASE, LPUART5_BASE, LPUART6_BASE, LPUART7_BASE }
/** Array initializer of LPUART peripheral base pointers */
#define LPUART_BASE_PTRS                         { LPUART0, LPUART1, LPUART2, LPUART3, LPUART4, LPUART5, LPUART6, LPUART7 }
/** Interrupt vectors for the LPUART peripheral type */
#define LPUART_RX_TX_IRQS                        { NotAvail_IRQn, NotAvail_IRQn, LPUART2_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn }

/* MCM - Peripheral instance base addresses */
/** Peripheral MCM base address */
#define MCM_BASE                                 (0xE0080000u)
/** Peripheral MCM base pointer */
#define MCM                                      ((MCM_Type *)MCM_BASE)
/** Array initializer of MCM peripheral base addresses */
#define MCM_BASE_ADDRS                           { MCM_BASE }
/** Array initializer of MCM peripheral base pointers */
#define MCM_BASE_PTRS                            { MCM }

/* MIPI_CSI2RX - Peripheral instance base addresses */
/** Peripheral MIPI_CSI2RX base address */
#define MIPI_CSI2RX_BASE                         (0x2DAD0000u)
/** Peripheral MIPI_CSI2RX base pointer */
#define MIPI_CSI2RX                              ((MIPI_CSI2RX_Type *)MIPI_CSI2RX_BASE)
/** Array initializer of MIPI_CSI2RX peripheral base addresses */
#define MIPI_CSI2RX_BASE_ADDRS                   { MIPI_CSI2RX_BASE }
/** Array initializer of MIPI_CSI2RX peripheral base pointers */
#define MIPI_CSI2RX_BASE_PTRS                    { MIPI_CSI2RX }

/* MIPI_CSI_CSR - Peripheral instance base addresses */
/** Peripheral MIPI_CSI_CSR base address */
#define MIPI_CSI_CSR_BASE                        (0x2DAF0000u)
/** Peripheral MIPI_CSI_CSR base pointer */
#define MIPI_CSI_CSR                             ((MIPI_CSI_CSR_Type *)MIPI_CSI_CSR_BASE)
/** Array initializer of MIPI_CSI_CSR peripheral base addresses */
#define MIPI_CSI_CSR_BASE_ADDRS                  { MIPI_CSI_CSR_BASE }
/** Array initializer of MIPI_CSI_CSR peripheral base pointers */
#define MIPI_CSI_CSR_BASE_PTRS                   { MIPI_CSI_CSR }

/* MIPI_DSI_HOST - Peripheral instance base addresses */
/** Peripheral MIPI_DSI base address */
#define MIPI_DSI_BASE                            (0x2DB00000u)
/** Peripheral MIPI_DSI base pointer */
#define MIPI_DSI                                 ((MIPI_DSI_HOST_Type *)MIPI_DSI_BASE)
/** Array initializer of MIPI_DSI_HOST peripheral base addresses */
#define MIPI_DSI_HOST_BASE_ADDRS                 { MIPI_DSI_BASE }
/** Array initializer of MIPI_DSI_HOST peripheral base pointers */
#define MIPI_DSI_HOST_BASE_PTRS                  { MIPI_DSI }

/* MRT - Peripheral instance base addresses */
/** Peripheral MRT0 base address */
#define MRT0_BASE                                (0x28107000u)
/** Peripheral MRT0 base pointer */
#define MRT0                                     ((MRT_Type *)MRT0_BASE)
/** Array initializer of MRT peripheral base addresses */
#define MRT_BASE_ADDRS                           { MRT0_BASE }
/** Array initializer of MRT peripheral base pointers */
#define MRT_BASE_PTRS                            { MRT0 }
/** Interrupt vectors for the MRT peripheral type */
#define MRT_IRQS                                 { MRT0_IRQn }

/* MU - Peripheral instance base addresses */
/** Peripheral MU1_MUB base address */
#define MU1_MUB_BASE                             (0x28100000u)
/** Peripheral MU1_MUB base pointer */
#define MU1_MUB                                  ((MU_Type *)MU1_MUB_BASE)
/** Array initializer of MU peripheral base addresses */
#define MU_BASE_ADDRS                            { MU1_MUB_BASE }
/** Array initializer of MU peripheral base pointers */
#define MU_BASE_PTRS                             { MU1_MUB }
/** Interrupt vectors for the MU peripheral type */
#define MU_IRQS                                  { MU1_B_IRQn }

/* PCC0 - Peripheral instance base addresses */
/** Peripheral PCC0 base address */
#define PCC0_BASE                                (0x28030000u)
/** Peripheral PCC0 base pointer */
#define PCC0                                     ((PCC0_Type *)PCC0_BASE)
/** Array initializer of PCC0 peripheral base addresses */
#define PCC0_BASE_ADDRS                          { PCC0_BASE }
/** Array initializer of PCC0 peripheral base pointers */
#define PCC0_BASE_PTRS                           { PCC0 }

/* PCC1 - Peripheral instance base addresses */
/** Peripheral PCC1 base address */
#define PCC1_BASE                                (0x28091000u)
/** Peripheral PCC1 base pointer */
#define PCC1                                     ((PCC1_Type *)PCC1_BASE)
/** Array initializer of PCC1 peripheral base addresses */
#define PCC1_BASE_ADDRS                          { PCC1_BASE }
/** Array initializer of PCC1 peripheral base pointers */
#define PCC1_BASE_PTRS                           { PCC1 }

/* PCC2 - Peripheral instance base addresses */
/** Peripheral PCC2 base address */
#define PCC2_BASE                                (0x28102000u)
/** Peripheral PCC2 base pointer */
#define PCC2                                     ((PCC2_Type *)PCC2_BASE)
/** Array initializer of PCC2 peripheral base addresses */
#define PCC2_BASE_ADDRS                          { PCC2_BASE }
/** Array initializer of PCC2 peripheral base pointers */
#define PCC2_BASE_PTRS                           { PCC2 }

/* PCC3 - Peripheral instance base addresses */
/** Peripheral PCC3 base address */
#define PCC3_BASE                                (0x292D0000u)
/** Peripheral PCC3 base pointer */
#define PCC3                                     ((PCC3_Type *)PCC3_BASE)
/** Array initializer of PCC3 peripheral base addresses */
#define PCC3_BASE_ADDRS                          { PCC3_BASE }
/** Array initializer of PCC3 peripheral base pointers */
#define PCC3_BASE_PTRS                           { PCC3 }

/* PCC4 - Peripheral instance base addresses */
/** Peripheral PCC4 base address */
#define PCC4_BASE                                (0x29800000u)
/** Peripheral PCC4 base pointer */
#define PCC4                                     ((PCC4_Type *)PCC4_BASE)
/** Array initializer of PCC4 peripheral base addresses */
#define PCC4_BASE_ADDRS                          { PCC4_BASE }
/** Array initializer of PCC4 peripheral base pointers */
#define PCC4_BASE_PTRS                           { PCC4 }

/* PCC5 - Peripheral instance base addresses */
/** Peripheral PCC5 base address */
#define PCC5_BASE                                (0x2DA70000u)
/** Peripheral PCC5 base pointer */
#define PCC5                                     ((PCC5_Type *)PCC5_BASE)
/** Array initializer of PCC5 peripheral base addresses */
#define PCC5_BASE_ADDRS                          { PCC5_BASE }
/** Array initializer of PCC5 peripheral base pointers */
#define PCC5_BASE_PTRS                           { PCC5 }

/* PDM - Peripheral instance base addresses */
/** Peripheral PDM base address */
#define PDM_BASE                                 (0x28111000u)
/** Peripheral PDM base pointer */
#define PDM                                      ((PDM_Type *)PDM_BASE)
/** Array initializer of PDM peripheral base addresses */
#define PDM_BASE_ADDRS                           { PDM_BASE }
/** Array initializer of PDM peripheral base pointers */
#define PDM_BASE_PTRS                            { PDM }

/* POWERQUAD - Peripheral instance base addresses */
/** Peripheral POWERQUAD base address */
#define POWERQUAD_BASE                           (0x28400000u)
/** Peripheral POWERQUAD base pointer */
#define POWERQUAD                                ((POWERQUAD_Type *)POWERQUAD_BASE)
/** Array initializer of POWERQUAD peripheral base addresses */
#define POWERQUAD_BASE_ADDRS                     { POWERQUAD_BASE }
/** Array initializer of POWERQUAD peripheral base pointers */
#define POWERQUAD_BASE_PTRS                      { POWERQUAD }

/* PXP - Peripheral instance base addresses */
/** Peripheral PXP base address */
#define PXP_BASE                                 (0x2DB40000u)
/** Peripheral PXP base pointer */
#define PXP                                      ((PXP_Type *)PXP_BASE)
/** Array initializer of PXP peripheral base addresses */
#define PXP_BASE_ADDRS                           { PXP_BASE }
/** Array initializer of PXP peripheral base pointers */
#define PXP_BASE_PTRS                            { PXP }

/* RGPIO - Peripheral instance base addresses */
/** Peripheral GPIOA base address */
#define GPIOA_BASE                               (0x28800000u)
/** Peripheral GPIOA base pointer */
#define GPIOA                                    ((RGPIO_Type *)GPIOA_BASE)
/** Peripheral GPIOB base address */
#define GPIOB_BASE                               (0x28810000u)
/** Peripheral GPIOB base pointer */
#define GPIOB                                    ((RGPIO_Type *)GPIOB_BASE)
/** Peripheral GPIOC base address */
#define GPIOC_BASE                               (0x28820000u)
/** Peripheral GPIOC base pointer */
#define GPIOC                                    ((RGPIO_Type *)GPIOC_BASE)
/** Peripheral GPIOD base address */
#define GPIOD_BASE                               (0x2E200000u)
/** Peripheral GPIOD base pointer */
#define GPIOD                                    ((RGPIO_Type *)GPIOD_BASE)
/** Peripheral GPIOE base address */
#define GPIOE_BASE                               (0x2D000000u)
/** Peripheral GPIOE base pointer */
#define GPIOE                                    ((RGPIO_Type *)GPIOE_BASE)
/** Peripheral GPIOF base address */
#define GPIOF_BASE                               (0x2D010000u)
/** Peripheral GPIOF base pointer */
#define GPIOF                                    ((RGPIO_Type *)GPIOF_BASE)
/** Array initializer of RGPIO peripheral base addresses */
#define RGPIO_BASE_ADDRS                         { GPIOA_BASE, GPIOB_BASE, GPIOC_BASE, GPIOD_BASE, GPIOE_BASE, GPIOF_BASE }
/** Array initializer of RGPIO peripheral base pointers */
#define RGPIO_BASE_PTRS                          { GPIOA, GPIOB, GPIOC, GPIOD, GPIOE, GPIOF }

/* SEMA42 - Peripheral instance base addresses */
/** Peripheral SEMA42_0 base address */
#define SEMA42_0_BASE                            (0x28037000u)
/** Peripheral SEMA42_0 base pointer */
#define SEMA42_0                                 ((SEMA42_Type *)SEMA42_0_BASE)
/** Peripheral SEMA42_1 base address */
#define SEMA42_1_BASE                            (0x29300000u)
/** Peripheral SEMA42_1 base pointer */
#define SEMA42_1                                 ((SEMA42_Type *)SEMA42_1_BASE)
/** Peripheral SEMA42_2 base address */
#define SEMA42_2_BASE                            (0x2DA30000u)
/** Peripheral SEMA42_2 base pointer */
#define SEMA42_2                                 ((SEMA42_Type *)SEMA42_2_BASE)
/** Array initializer of SEMA42 peripheral base addresses */
#define SEMA42_BASE_ADDRS                        { SEMA42_0_BASE, SEMA42_1_BASE, SEMA42_2_BASE }
/** Array initializer of SEMA42 peripheral base pointers */
#define SEMA42_BASE_PTRS                         { SEMA42_0, SEMA42_1, SEMA42_2 }

/* SIM - Peripheral instance base addresses */
/** Peripheral SIM_RTD base address */
#define SIM_RTD_BASE                             (0x2802A000u)
/** Peripheral SIM_RTD base pointer */
#define SIM_RTD                                  ((SIM_Type *)SIM_RTD_BASE)
/** Array initializer of SIM peripheral base addresses */
#define SIM_BASE_ADDRS                           { SIM_RTD_BASE }
/** Array initializer of SIM peripheral base pointers */
#define SIM_BASE_PTRS                            { SIM_RTD }

/* SIM_AD - Peripheral instance base addresses */
/** Peripheral SIM_AD base address */
#define SIM_AD_BASE                              (0x29290000u)
/** Peripheral SIM_AD base pointer */
#define SIM_AD                                   ((SIM_AD_Type *)SIM_AD_BASE)
/** Array initializer of SIM_AD peripheral base addresses */
#define SIM_AD_BASE_ADDRS                        { SIM_AD_BASE }
/** Array initializer of SIM_AD peripheral base pointers */
#define SIM_AD_BASE_PTRS                         { SIM_AD }

/* SIM_LPAV - Peripheral instance base addresses */
/** Peripheral SIM_LPAV base address */
#define SIM_LPAV_BASE                            (0x2DA50000u)
/** Peripheral SIM_LPAV base pointer */
#define SIM_LPAV                                 ((SIM_LPAV_Type *)SIM_LPAV_BASE)
/** Array initializer of SIM_LPAV peripheral base addresses */
#define SIM_LPAV_BASE_ADDRS                      { SIM_LPAV_BASE }
/** Array initializer of SIM_LPAV peripheral base pointers */
#define SIM_LPAV_BASE_PTRS                       { SIM_LPAV }

/* SIM_SEC - Peripheral instance base addresses */
/** Peripheral SIM_SEC base address */
#define SIM_SEC_BASE                             (0x2802B000u)
/** Peripheral SIM_SEC base pointer */
#define SIM_SEC                                  ((SIM_SEC_Type *)SIM_SEC_BASE)
/** Array initializer of SIM_SEC peripheral base addresses */
#define SIM_SEC_BASE_ADDRS                       { SIM_SEC_BASE }
/** Array initializer of SIM_SEC peripheral base pointers */
#define SIM_SEC_BASE_PTRS                        { SIM_SEC }

/* SPDIF - Peripheral instance base addresses */
/** Peripheral SPDIF base address */
#define SPDIF_BASE                               (0x2DAB0000u)
/** Peripheral SPDIF base pointer */
#define SPDIF                                    ((SPDIF_Type *)SPDIF_BASE)
/** Array initializer of SPDIF peripheral base addresses */
#define SPDIF_BASE_ADDRS                         { SPDIF_BASE }
/** Array initializer of SPDIF peripheral base pointers */
#define SPDIF_BASE_PTRS                          { SPDIF }

/* SYSPM - Peripheral instance base addresses */
/** Peripheral SYSPM0 base address */
#define SYSPM0_BASE                              (0x28026000u)
/** Peripheral SYSPM0 base pointer */
#define SYSPM0                                   ((SYSPM_Type *)SYSPM0_BASE)
/** Peripheral SYSPM1 base address */
#define SYSPM1_BASE                              (0x29270000u)
/** Peripheral SYSPM1 base pointer */
#define SYSPM1                                   ((SYSPM_Type *)SYSPM1_BASE)
/** Array initializer of SYSPM peripheral base addresses */
#define SYSPM_BASE_ADDRS                         { SYSPM0_BASE, SYSPM1_BASE }
/** Array initializer of SYSPM peripheral base pointers */
#define SYSPM_BASE_PTRS                          { SYSPM0, SYSPM1 }

/* TPM - Peripheral instance base addresses */
/** Peripheral TPM0 base address */
#define TPM0_BASE                                (0x28095000u)
/** Peripheral TPM0 base pointer */
#define TPM0                                     ((TPM_Type *)TPM0_BASE)
/** Peripheral TPM1 base address */
#define TPM1_BASE                                (0x28096000u)
/** Peripheral TPM1 base pointer */
#define TPM1                                     ((TPM_Type *)TPM1_BASE)
/** Peripheral TPM2 base address */
#define TPM2_BASE                                (0x28105000u)
/** Peripheral TPM2 base pointer */
#define TPM2                                     ((TPM_Type *)TPM2_BASE)
/** Peripheral TPM3 base address */
#define TPM3_BASE                                (0x28106000u)
/** Peripheral TPM3 base pointer */
#define TPM3                                     ((TPM_Type *)TPM3_BASE)
/** Peripheral TPM4 base address */
#define TPM4_BASE                                (0x29330000u)
/** Peripheral TPM4 base pointer */
#define TPM4                                     ((TPM_Type *)TPM4_BASE)
/** Peripheral TPM5 base address */
#define TPM5_BASE                                (0x29340000u)
/** Peripheral TPM5 base pointer */
#define TPM5                                     ((TPM_Type *)TPM5_BASE)
/** Peripheral TPM6 base address */
#define TPM6_BASE                                (0x29820000u)
/** Peripheral TPM6 base pointer */
#define TPM6                                     ((TPM_Type *)TPM6_BASE)
/** Peripheral TPM7 base address */
#define TPM7_BASE                                (0x29830000u)
/** Peripheral TPM7 base pointer */
#define TPM7                                     ((TPM_Type *)TPM7_BASE)
/** Peripheral TPM8 base address */
#define TPM8_BASE                                (0x2DA80000u)
/** Peripheral TPM8 base pointer */
#define TPM8                                     ((TPM_Type *)TPM8_BASE)
/** Array initializer of TPM peripheral base addresses */
#define TPM_BASE_ADDRS                           { TPM0_BASE, TPM1_BASE, TPM2_BASE, TPM3_BASE, TPM4_BASE, TPM5_BASE, TPM6_BASE, TPM7_BASE, TPM8_BASE }
/** Array initializer of TPM peripheral base pointers */
#define TPM_BASE_PTRS                            { TPM0, TPM1, TPM2, TPM3, TPM4, TPM5, TPM6, TPM7, TPM8 }
/** Interrupt vectors for the TPM peripheral type */
#define TPM_IRQS                                 { NotAvail_IRQn, NotAvail_IRQn, TPM2_IRQn, TPM3_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn }

/* TRDC - Peripheral instance base addresses */
/** Peripheral TRDC base address */
#define TRDC_BASE                                (0x28031000u)
/** Peripheral TRDC base pointer */
#define TRDC                                     ((TRDC_Type *)TRDC_BASE)
/** Array initializer of TRDC peripheral base addresses */
#define TRDC_BASE_ADDRS                          { TRDC_BASE }
/** Array initializer of TRDC peripheral base pointers */
#define TRDC_BASE_PTRS                           { TRDC }

/* TRGMUX - Peripheral instance base addresses */
/** Peripheral TRGMUX0 base address */
#define TRGMUX0_BASE                             (0x28027000u)
/** Peripheral TRGMUX0 base pointer */
#define TRGMUX0                                  ((TRGMUX_Type *)TRGMUX0_BASE)
/** Peripheral TRGMUX1 base address */
#define TRGMUX1_BASE                             (0x29250000u)
/** Peripheral TRGMUX1 base pointer */
#define TRGMUX1                                  ((TRGMUX_Type *)TRGMUX1_BASE)
/** Array initializer of TRGMUX peripheral base addresses */
#define TRGMUX_BASE_ADDRS                        { TRGMUX0_BASE, TRGMUX1_BASE }
/** Array initializer of TRGMUX peripheral base pointers */
#define TRGMUX_BASE_PTRS                         { TRGMUX0, TRGMUX1 }

/* TSTMR - Peripheral instance base addresses */
/** Peripheral TSTMR0__TIMESTAMP0 base address */
#define TSTMR0__TIMESTAMP0_BASE                  (0x2802AC00u)
/** Peripheral TSTMR0__TIMESTAMP0 base pointer */
#define TSTMR0__TIMESTAMP0                       ((TSTMR_Type *)TSTMR0__TIMESTAMP0_BASE)
/** Peripheral TSTMR1__TIMESTAMP0 base address */
#define TSTMR1__TIMESTAMP0_BASE                  (0x29290C00u)
/** Peripheral TSTMR1__TIMESTAMP0 base pointer */
#define TSTMR1__TIMESTAMP0                       ((TSTMR_Type *)TSTMR1__TIMESTAMP0_BASE)
/** Array initializer of TSTMR peripheral base addresses */
#define TSTMR_BASE_ADDRS                         { TSTMR0__TIMESTAMP0_BASE, TSTMR1__TIMESTAMP0_BASE }
/** Array initializer of TSTMR peripheral base pointers */
#define TSTMR_BASE_PTRS                          { TSTMR0__TIMESTAMP0, TSTMR1__TIMESTAMP0 }

/* USB - Peripheral instance base addresses */
/** Peripheral USB0 base address */
#define USB0_BASE                                (0x29900000u)
/** Peripheral USB0 base pointer */
#define USB0                                     ((USB_Type *)USB0_BASE)
/** Peripheral USB1 base address */
#define USB1_BASE                                (0x29920000u)
/** Peripheral USB1 base pointer */
#define USB1                                     ((USB_Type *)USB1_BASE)
/** Peripheral USB_XBAR base address */
#define USB_XBAR_BASE                            (0x29940000u)
/** Peripheral USB_XBAR base pointer */
#define USB_XBAR                                 ((USB_Type *)USB_XBAR_BASE)
/** Array initializer of USB peripheral base addresses */
#define USB_BASE_ADDRS                           { USB0_BASE, USB1_BASE, USB_XBAR_BASE }
/** Array initializer of USB peripheral base pointers */
#define USB_BASE_PTRS                            { USB0, USB1, USB_XBAR }

/* USBHSDCD - Peripheral instance base addresses */
/** Peripheral USBDCD0 base address */
#define USBDCD0_BASE                             (0x29910800u)
/** Peripheral USBDCD0 base pointer */
#define USBDCD0                                  ((USBHSDCD_Type *)USBDCD0_BASE)
/** Peripheral USBDCD1 base address */
#define USBDCD1_BASE                             (0x29930800u)
/** Peripheral USBDCD1 base pointer */
#define USBDCD1                                  ((USBHSDCD_Type *)USBDCD1_BASE)
/** Array initializer of USBHSDCD peripheral base addresses */
#define USBHSDCD_BASE_ADDRS                      { USBDCD0_BASE, USBDCD1_BASE }
/** Array initializer of USBHSDCD peripheral base pointers */
#define USBHSDCD_BASE_PTRS                       { USBDCD0, USBDCD1 }

/* USBNC - Peripheral instance base addresses */
/** Peripheral USBNC0 base address */
#define USBNC0_BASE                              (0x29900200u)
/** Peripheral USBNC0 base pointer */
#define USBNC0                                   ((USBNC_Type *)USBNC0_BASE)
/** Peripheral USBNC1 base address */
#define USBNC1_BASE                              (0x29920200u)
/** Peripheral USBNC1 base pointer */
#define USBNC1                                   ((USBNC_Type *)USBNC1_BASE)
/** Peripheral USBNC_XBAR base address */
#define USBNC_XBAR_BASE                          (0x29940200u)
/** Peripheral USBNC_XBAR base pointer */
#define USBNC_XBAR                               ((USBNC_Type *)USBNC_XBAR_BASE)
/** Array initializer of USBNC peripheral base addresses */
#define USBNC_BASE_ADDRS                         { USBNC0_BASE, USBNC1_BASE, USBNC_XBAR_BASE }
/** Array initializer of USBNC peripheral base pointers */
#define USBNC_BASE_PTRS                          { USBNC0, USBNC1, USBNC_XBAR }

/* USBPHY - Peripheral instance base addresses */
/** Peripheral USB0_PHY base address */
#define USB0_PHY_BASE                            (0x29910000u)
/** Peripheral USB0_PHY base pointer */
#define USB0_PHY                                 ((USBPHY_Type *)USB0_PHY_BASE)
/** Peripheral USB1_PHY base address */
#define USB1_PHY_BASE                            (0x29930000u)
/** Peripheral USB1_PHY base pointer */
#define USB1_PHY                                 ((USBPHY_Type *)USB1_PHY_BASE)
/** Array initializer of USBPHY peripheral base addresses */
#define USBPHY_BASE_ADDRS                        { USB0_PHY_BASE, USB1_PHY_BASE }
/** Array initializer of USBPHY peripheral base pointers */
#define USBPHY_BASE_PTRS                         { USB0_PHY, USB1_PHY }
/* Backward compatibility */
#define USBPHY_CTRL_ENDEVPLUGINDET_MASK     USBPHY_CTRL_ENDEVPLUGINDETECT_MASK
#define USBPHY_CTRL_ENDEVPLUGINDET_SHIFT    USBPHY_CTRL_ENDEVPLUGINDETECT_SHIFT
#define USBPHY_CTRL_ENDEVPLUGINDET(x)       USBPHY_CTRL_ENDEVPLUGINDETECT(x)
#define USBPHY_TX_TXCAL45DM_MASK            USBPHY_TX_TXCAL45DN_MASK
#define USBPHY_TX_TXCAL45DM_SHIFT           USBPHY_TX_TXCAL45DN_SHIFT
#define USBPHY_TX_TXCAL45DM(x)              USBPHY_TX_TXCAL45DN(x)


/* USDHC - Peripheral instance base addresses */
/** Peripheral USDHC0 base address */
#define USDHC0_BASE                              (0x298D0000u)
/** Peripheral USDHC0 base pointer */
#define USDHC0                                   ((USDHC_Type *)USDHC0_BASE)
/** Peripheral USDHC1 base address */
#define USDHC1_BASE                              (0x298E0000u)
/** Peripheral USDHC1 base pointer */
#define USDHC1                                   ((USDHC_Type *)USDHC1_BASE)
/** Peripheral USDHC2 base address */
#define USDHC2_BASE                              (0x298F0000u)
/** Peripheral USDHC2 base pointer */
#define USDHC2                                   ((USDHC_Type *)USDHC2_BASE)
/** Array initializer of USDHC peripheral base addresses */
#define USDHC_BASE_ADDRS                         { USDHC0_BASE, USDHC1_BASE, USDHC2_BASE }
/** Array initializer of USDHC peripheral base pointers */
#define USDHC_BASE_PTRS                          { USDHC0, USDHC1, USDHC2 }

/* WDOG - Peripheral instance base addresses */
/** Peripheral WDOG0 base address */
#define WDOG0_BASE                               (0x2802C000u)
/** Peripheral WDOG0 base pointer */
#define WDOG0                                    ((WDOG_Type *)WDOG0_BASE)
/** Peripheral WDOG1 base address */
#define WDOG1_BASE                               (0x2802D000u)
/** Peripheral WDOG1 base pointer */
#define WDOG1                                    ((WDOG_Type *)WDOG1_BASE)
/** Peripheral WDOG2 base address */
#define WDOG2_BASE                               (0x28101000u)
/** Peripheral WDOG2 base pointer */
#define WDOG2                                    ((WDOG_Type *)WDOG2_BASE)
/** Peripheral WDOG3 base address */
#define WDOG3_BASE                               (0x292A0000u)
/** Peripheral WDOG3 base pointer */
#define WDOG3                                    ((WDOG_Type *)WDOG3_BASE)
/** Peripheral WDOG4 base address */
#define WDOG4_BASE                               (0x292B0000u)
/** Peripheral WDOG4 base pointer */
#define WDOG4                                    ((WDOG_Type *)WDOG4_BASE)
/** Peripheral WDOG5 base address */
#define WDOG5_BASE                               (0x2DB20000u)
/** Peripheral WDOG5 base pointer */
#define WDOG5                                    ((WDOG_Type *)WDOG5_BASE)
/** Array initializer of WDOG peripheral base addresses */
#define WDOG_BASE_ADDRS                          { WDOG0_BASE, WDOG1_BASE, WDOG2_BASE, WDOG3_BASE, WDOG4_BASE, WDOG5_BASE }
/** Array initializer of WDOG peripheral base pointers */
#define WDOG_BASE_PTRS                           { WDOG0, WDOG1, WDOG2, WDOG3, WDOG4, WDOG5 }
/** Interrupt vectors for the WDOG peripheral type */
#define WDOG_IRQS                                { NotAvail_IRQn, NotAvail_IRQn, WDOG2_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn }

/* WUU - Peripheral instance base addresses */
/** Peripheral WUU0 base address */
#define WUU0_BASE                                (0x28028000u)
/** Peripheral WUU0 base pointer */
#define WUU0                                     ((WUU_Type *)WUU0_BASE)
/** Peripheral WUU1 base address */
#define WUU1_BASE                                (0x29260000u)
/** Peripheral WUU1 base pointer */
#define WUU1                                     ((WUU_Type *)WUU1_BASE)
/** Array initializer of WUU peripheral base addresses */
#define WUU_BASE_ADDRS                           { WUU0_BASE, WUU1_BASE }
/** Array initializer of WUU peripheral base pointers */
#define WUU_BASE_PTRS                            { WUU0, WUU1 }

/* XRDC - Peripheral instance base addresses */
/** Peripheral XRDC base address */
#define XRDC_BASE                                (0x292F0000u)
/** Peripheral XRDC base pointer */
#define XRDC                                     ((XRDC_Type *)XRDC_BASE)
/** Array initializer of XRDC peripheral base addresses */
#define XRDC_BASE_ADDRS                          { XRDC_BASE }
/** Array initializer of XRDC peripheral base pointers */
#define XRDC_BASE_PTRS                           { XRDC }

/* ----------------------------------------------------------------------------
   -- Macros for use with bit field definitions (xxx_SHIFT, xxx_MASK).
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Bit_Field_Generic_Macros Macros for use with bit field definitions (xxx_SHIFT, xxx_MASK).
 * @{
 */

/**
 * @brief Mask and left-shift a bit field value for use in a register bit range.
 * @param field Name of the register bit field.
 * @param value Value of the bit field.
 * @return Masked and shifted value.
 */
#define NXP_VAL2FLD(field, value)    (((value) << (field ## _SHIFT)) & (field ## _MASK))
/**
 * @brief Mask and right-shift a register value to extract a bit field value.
 * @param field Name of the register bit field.
 * @param value Value of the register.
 * @return Masked and shifted bit field value.
 */
#define NXP_FLD2VAL(field, value)    (((value) & (field ## _MASK)) >> (field ## _SHIFT))

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

/* No SDK compatibility issues. */

/*!
 * @}
 */ /* end of group SDK_Compatibility_Symbols */


#endif  /* MIMX8US3_DSP0_COMMON_H_ */

