/*
** ###################################################################
**     Processors:          MIMXRT758SGAWAR_ezhv
**                          MIMXRT758SGFOA_ezhv
**
**     Reference manual:    iMXRT700RM Rev.2 DraftA, 05/2024
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         Peripheral Access Layer for MIMXRT758S_ezhv
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2022-09-15)
**         Initial version.
**     - rev. 2.0 (2024-05-28)
**         Rev2 DraftA.
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file MIMXRT758S_ezhv_COMMON.h
 * @version 3.0
 * @date 2024-10-29
 * @brief Peripheral Access Layer for MIMXRT758S_ezhv
 *
 * Peripheral Access Layer for MIMXRT758S_ezhv
 */

#if !defined(MIMXRT758S_EZHV_COMMON_H_)
#define MIMXRT758S_EZHV_COMMON_H_                /**< Symbol preventing repeated inclusion */

/** Memory map major version (memory maps with equal major version number are
 * compatible) */
#define MCU_MEM_MAP_VERSION 0x0300U
/** Memory map minor version */
#define MCU_MEM_MAP_VERSION_MINOR 0x0000U

/* ----------------------------------------------------------------------------
   --
   ---------------------------------------------------------------------------- */

#include "core_zv2116.h"
#include "system_MIMXRT758S_ezhv.h"     /* Device specific configuration file */



/* ----------------------------------------------------------------------------
   -- Interrupt vector numbers
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Interrupt_vector_numbers Interrupt vector numbers
 * @{
 */

/** Interrupt Number Definitions */
#define NUMBER_OF_INT_VECTORS 1                  /**< Number of interrupts in the Vector table */

typedef enum IRQn {
  /* Auxiliary constants */
  NotAvail_IRQn                = -128,             /**< Not available device specific interrupt */

  /* Device specific interrupts */
} IRQn_Type;

/*!
 * @}
 */ /* end of group Interrupt_vector_numbers */


/* ----------------------------------------------------------------------------
   -- Cortex EZHV Core Configuration
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Cortex_Core_Configuration Cortex EZHV Core Configuration
 * @{
 */

#define __MPU_PRESENT                  0         /**< Defines if an MPU is present or not */
#define __NVIC_PRIO_BITS               3         /**< Number of priority bits implemented in the NVIC */
#define __Vendor_SysTickConfig         0         /**< Vendor specific implementation of SysTickConfig is defined */
#define __FPU_PRESENT                  0         /**< Defines if an FPU is present or not */
#define __DSP_PRESENT                  0         /**< Defines if Armv8-M Mainline core supports DSP instructions */
#define __SAUREGION_PRESENT            1         /**< Defines if an SAU is present or not */

/*!
 * @}
 */ /* end of group Cortex_Core_Configuration */


#ifndef MIMXRT758S_ezhv_SERIES
#define MIMXRT758S_ezhv_SERIES
#endif
/* CPU specific feature definitions */
#include "MIMXRT758S_ezhv_features.h"

/* ADC - Peripheral instance base addresses */
/** Peripheral ADC0 base address */
#define ADC0_BASE                                (0x4020C000u)
/** Peripheral ADC0 base pointer */
#define ADC0                                     ((ADC_Type *)ADC0_BASE)
/** Array initializer of ADC peripheral base addresses */
#define ADC_BASE_ADDRS                           { ADC0_BASE }
/** Array initializer of ADC peripheral base pointers */
#define ADC_BASE_PTRS                            { ADC0 }

/* AHBSC0 - Peripheral instance base addresses */
/** Peripheral AHBSC0 base address */
#define AHBSC0_BASE                              (0x4017C000u)
/** Peripheral AHBSC0 base pointer */
#define AHBSC0                                   ((AHBSC0_Type *)AHBSC0_BASE)
/** Peripheral AHBSC0_ALIAS1 base address */
#define AHBSC0_ALIAS1_BASE                       (0x4017D000u)
/** Peripheral AHBSC0_ALIAS1 base pointer */
#define AHBSC0_ALIAS1                            ((AHBSC0_Type *)AHBSC0_ALIAS1_BASE)
/** Peripheral AHBSC0_ALIAS2 base address */
#define AHBSC0_ALIAS2_BASE                       (0x4017E000u)
/** Peripheral AHBSC0_ALIAS2 base pointer */
#define AHBSC0_ALIAS2                            ((AHBSC0_Type *)AHBSC0_ALIAS2_BASE)
/** Peripheral AHBSC0_ALIAS3 base address */
#define AHBSC0_ALIAS3_BASE                       (0x4017F000u)
/** Peripheral AHBSC0_ALIAS3 base pointer */
#define AHBSC0_ALIAS3                            ((AHBSC0_Type *)AHBSC0_ALIAS3_BASE)
/** Array initializer of AHBSC0 peripheral base addresses */
#define AHBSC0_BASE_ADDRS                        { AHBSC0_BASE, AHBSC0_ALIAS1_BASE, AHBSC0_ALIAS2_BASE, AHBSC0_ALIAS3_BASE }
/** Array initializer of AHBSC0 peripheral base pointers */
#define AHBSC0_BASE_PTRS                         { AHBSC0, AHBSC0_ALIAS1, AHBSC0_ALIAS2, AHBSC0_ALIAS3 }

/* AHBSC3 - Peripheral instance base addresses */
/** Peripheral AHBSC3 base address */
#define AHBSC3_BASE                              (0x40220000u)
/** Peripheral AHBSC3 base pointer */
#define AHBSC3                                   ((AHBSC3_Type *)AHBSC3_BASE)
/** Peripheral AHBSC3_ALIAS1 base address */
#define AHBSC3_ALIAS1_BASE                       (0x40221000u)
/** Peripheral AHBSC3_ALIAS1 base pointer */
#define AHBSC3_ALIAS1                            ((AHBSC3_Type *)AHBSC3_ALIAS1_BASE)
/** Peripheral AHBSC3_ALIAS2 base address */
#define AHBSC3_ALIAS2_BASE                       (0x40222000u)
/** Peripheral AHBSC3_ALIAS2 base pointer */
#define AHBSC3_ALIAS2                            ((AHBSC3_Type *)AHBSC3_ALIAS2_BASE)
/** Peripheral AHBSC3_ALIAS3 base address */
#define AHBSC3_ALIAS3_BASE                       (0x40223000u)
/** Peripheral AHBSC3_ALIAS3 base pointer */
#define AHBSC3_ALIAS3                            ((AHBSC3_Type *)AHBSC3_ALIAS3_BASE)
/** Array initializer of AHBSC3 peripheral base addresses */
#define AHBSC3_BASE_ADDRS                        { AHBSC3_BASE, AHBSC3_ALIAS1_BASE, AHBSC3_ALIAS2_BASE, AHBSC3_ALIAS3_BASE }
/** Array initializer of AHBSC3 peripheral base pointers */
#define AHBSC3_BASE_PTRS                         { AHBSC3, AHBSC3_ALIAS1, AHBSC3_ALIAS2, AHBSC3_ALIAS3 }

/* AHBSC4 - Peripheral instance base addresses */
/** Peripheral AHBSC4 base address */
#define AHBSC4_BASE                              (0x40400000u)
/** Peripheral AHBSC4 base pointer */
#define AHBSC4                                   ((AHBSC4_Type *)AHBSC4_BASE)
/** Peripheral AHBSC4_ALIAS1 base address */
#define AHBSC4_ALIAS1_BASE                       (0x40401000u)
/** Peripheral AHBSC4_ALIAS1 base pointer */
#define AHBSC4_ALIAS1                            ((AHBSC4_Type *)AHBSC4_ALIAS1_BASE)
/** Peripheral AHBSC4_ALIAS2 base address */
#define AHBSC4_ALIAS2_BASE                       (0x40402000u)
/** Peripheral AHBSC4_ALIAS2 base pointer */
#define AHBSC4_ALIAS2                            ((AHBSC4_Type *)AHBSC4_ALIAS2_BASE)
/** Peripheral AHBSC4_ALIAS3 base address */
#define AHBSC4_ALIAS3_BASE                       (0x40403000u)
/** Peripheral AHBSC4_ALIAS3 base pointer */
#define AHBSC4_ALIAS3                            ((AHBSC4_Type *)AHBSC4_ALIAS3_BASE)
/** Array initializer of AHBSC4 peripheral base addresses */
#define AHBSC4_BASE_ADDRS                        { AHBSC4_BASE, AHBSC4_ALIAS1_BASE, AHBSC4_ALIAS2_BASE, AHBSC4_ALIAS3_BASE }
/** Array initializer of AHBSC4 peripheral base pointers */
#define AHBSC4_BASE_PTRS                         { AHBSC4, AHBSC4_ALIAS1, AHBSC4_ALIAS2, AHBSC4_ALIAS3 }

/* CACHE64_CTRL - Peripheral instance base addresses */
/** Peripheral CACHE64_CTRL0 base address */
#define CACHE64_CTRL0_BASE                       (0x40035000u)
/** Peripheral CACHE64_CTRL0 base pointer */
#define CACHE64_CTRL0                            ((CACHE64_CTRL_Type *)CACHE64_CTRL0_BASE)
/** Peripheral CACHE64_CTRL1 base address */
#define CACHE64_CTRL1_BASE                       (0x40036000u)
/** Peripheral CACHE64_CTRL1 base pointer */
#define CACHE64_CTRL1                            ((CACHE64_CTRL_Type *)CACHE64_CTRL1_BASE)
/** Array initializer of CACHE64_CTRL peripheral base addresses */
#define CACHE64_CTRL_BASE_ADDRS                  { CACHE64_CTRL0_BASE, CACHE64_CTRL1_BASE }
/** Array initializer of CACHE64_CTRL peripheral base pointers */
#define CACHE64_CTRL_BASE_PTRS                   { CACHE64_CTRL0, CACHE64_CTRL1 }
/** CACHE64_CTRL physical memory base address */
 #define CACHE64_CTRL_PHYMEM_BASES                { 0x28000000u, 0x08000000u }
/** CACHE64_CTRL physical memory size */
 #define CACHE64_CTRL_PHYMEM_SIZES                { 0x08000000u, 0x08000000u }
/* Backward compatibility */
#define CACHE64_CTRL_CSAR_PHYADDR_MASK (CACHE64_CTRL_CSAR_PHYADDR27_1_MASK | CACHE64_CTRL_CSAR_PHYADDR31_29_MASK)


/* CACHE64_POLSEL - Peripheral instance base addresses */
/** Peripheral CACHE64_POLSEL0 base address */
#define CACHE64_POLSEL0_BASE                     (0x40035000u)
/** Peripheral CACHE64_POLSEL0 base pointer */
#define CACHE64_POLSEL0                          ((CACHE64_POLSEL_Type *)CACHE64_POLSEL0_BASE)
/** Peripheral CACHE64_POLSEL1 base address */
#define CACHE64_POLSEL1_BASE                     (0x40036000u)
/** Peripheral CACHE64_POLSEL1 base pointer */
#define CACHE64_POLSEL1                          ((CACHE64_POLSEL_Type *)CACHE64_POLSEL1_BASE)
/** Array initializer of CACHE64_POLSEL peripheral base addresses */
#define CACHE64_POLSEL_BASE_ADDRS                { CACHE64_POLSEL0_BASE, CACHE64_POLSEL1_BASE }
/** Array initializer of CACHE64_POLSEL peripheral base pointers */
#define CACHE64_POLSEL_BASE_PTRS                 { CACHE64_POLSEL0, CACHE64_POLSEL1 }

/* CDOG - Peripheral instance base addresses */
/** Peripheral CDOG0 base address */
#define CDOG0_BASE                               (0x40115000u)
/** Peripheral CDOG0 base pointer */
#define CDOG0                                    ((CDOG_Type *)CDOG0_BASE)
/** Peripheral CDOG1 base address */
#define CDOG1_BASE                               (0x40116000u)
/** Peripheral CDOG1 base pointer */
#define CDOG1                                    ((CDOG_Type *)CDOG1_BASE)
/** Peripheral CDOG2 base address */
#define CDOG2_BASE                               (0x40117000u)
/** Peripheral CDOG2 base pointer */
#define CDOG2                                    ((CDOG_Type *)CDOG2_BASE)
/** Peripheral CDOG3 base address */
#define CDOG3_BASE                               (0x4032B000u)
/** Peripheral CDOG3 base pointer */
#define CDOG3                                    ((CDOG_Type *)CDOG3_BASE)
/** Peripheral CDOG4 base address */
#define CDOG4_BASE                               (0x4032A000u)
/** Peripheral CDOG4 base pointer */
#define CDOG4                                    ((CDOG_Type *)CDOG4_BASE)
/** Array initializer of CDOG peripheral base addresses */
#define CDOG_BASE_ADDRS                          { CDOG0_BASE, CDOG1_BASE, CDOG2_BASE, CDOG3_BASE, CDOG4_BASE }
/** Array initializer of CDOG peripheral base pointers */
#define CDOG_BASE_PTRS                           { CDOG0, CDOG1, CDOG2, CDOG3, CDOG4 }

/* CLKCTL0 - Peripheral instance base addresses */
/** Peripheral CLKCTL0 base address */
#define CLKCTL0_BASE                             (0x40001000u)
/** Peripheral CLKCTL0 base pointer */
#define CLKCTL0                                  ((CLKCTL0_Type *)CLKCTL0_BASE)
/** Array initializer of CLKCTL0 peripheral base addresses */
#define CLKCTL0_BASE_ADDRS                       { CLKCTL0_BASE }
/** Array initializer of CLKCTL0 peripheral base pointers */
#define CLKCTL0_BASE_PTRS                        { CLKCTL0 }

/* CLKCTL1 - Peripheral instance base addresses */
/** Peripheral CLKCTL1 base address */
#define CLKCTL1_BASE                             (0x40041000u)
/** Peripheral CLKCTL1 base pointer */
#define CLKCTL1                                  ((CLKCTL1_Type *)CLKCTL1_BASE)
/** Array initializer of CLKCTL1 peripheral base addresses */
#define CLKCTL1_BASE_ADDRS                       { CLKCTL1_BASE }
/** Array initializer of CLKCTL1 peripheral base pointers */
#define CLKCTL1_BASE_PTRS                        { CLKCTL1 }

/* CLKCTL2 - Peripheral instance base addresses */
/** Peripheral CLKCTL2 base address */
#define CLKCTL2_BASE                             (0x40065000u)
/** Peripheral CLKCTL2 base pointer */
#define CLKCTL2                                  ((CLKCTL2_Type *)CLKCTL2_BASE)
/** Array initializer of CLKCTL2 peripheral base addresses */
#define CLKCTL2_BASE_ADDRS                       { CLKCTL2_BASE }
/** Array initializer of CLKCTL2 peripheral base pointers */
#define CLKCTL2_BASE_PTRS                        { CLKCTL2 }

/* CLKCTL3 - Peripheral instance base addresses */
/** Peripheral CLKCTL3 base address */
#define CLKCTL3_BASE                             (0x40061000u)
/** Peripheral CLKCTL3 base pointer */
#define CLKCTL3                                  ((CLKCTL3_Type *)CLKCTL3_BASE)
/** Array initializer of CLKCTL3 peripheral base addresses */
#define CLKCTL3_BASE_ADDRS                       { CLKCTL3_BASE }
/** Array initializer of CLKCTL3 peripheral base pointers */
#define CLKCTL3_BASE_PTRS                        { CLKCTL3 }

/* CLKCTL4 - Peripheral instance base addresses */
/** Peripheral CLKCTL4 base address */
#define CLKCTL4_BASE                             (0x400A1000u)
/** Peripheral CLKCTL4 base pointer */
#define CLKCTL4                                  ((CLKCTL4_Type *)CLKCTL4_BASE)
/** Array initializer of CLKCTL4 peripheral base addresses */
#define CLKCTL4_BASE_ADDRS                       { CLKCTL4_BASE }
/** Array initializer of CLKCTL4 peripheral base pointers */
#define CLKCTL4_BASE_PTRS                        { CLKCTL4 }

/* CMP - Peripheral instance base addresses */
/** Peripheral ACMP0 base address */
#define ACMP0_BASE                               (0x4020B000u)
/** Peripheral ACMP0 base pointer */
#define ACMP0                                    ((CMP_Type *)ACMP0_BASE)
/** Array initializer of CMP peripheral base addresses */
#define CMP_BASE_ADDRS                           { ACMP0_BASE }
/** Array initializer of CMP peripheral base pointers */
#define CMP_BASE_PTRS                            { ACMP0 }

/* CRC - Peripheral instance base addresses */
/** Peripheral CRC base address */
#define CRC_BASE                                 (0x40151000u)
/** Peripheral CRC base pointer */
#define CRC                                      ((CRC_Type *)CRC_BASE)
/** Array initializer of CRC peripheral base addresses */
#define CRC_BASE_ADDRS                           { CRC_BASE }
/** Array initializer of CRC peripheral base pointers */
#define CRC_BASE_PTRS                            { CRC }

/* CTIMER - Peripheral instance base addresses */
/** Peripheral CTIMER0 base address */
#define CTIMER0_BASE                             (0x40028000u)
/** Peripheral CTIMER0 base pointer */
#define CTIMER0                                  ((CTIMER_Type *)CTIMER0_BASE)
/** Peripheral CTIMER1 base address */
#define CTIMER1_BASE                             (0x40029000u)
/** Peripheral CTIMER1 base pointer */
#define CTIMER1                                  ((CTIMER_Type *)CTIMER1_BASE)
/** Peripheral CTIMER2 base address */
#define CTIMER2_BASE                             (0x4002A000u)
/** Peripheral CTIMER2 base pointer */
#define CTIMER2                                  ((CTIMER_Type *)CTIMER2_BASE)
/** Peripheral CTIMER3 base address */
#define CTIMER3_BASE                             (0x4002B000u)
/** Peripheral CTIMER3 base pointer */
#define CTIMER3                                  ((CTIMER_Type *)CTIMER3_BASE)
/** Peripheral CTIMER4 base address */
#define CTIMER4_BASE                             (0x4002C000u)
/** Peripheral CTIMER4 base pointer */
#define CTIMER4                                  ((CTIMER_Type *)CTIMER4_BASE)
/** Peripheral CTIMER5 base address */
#define CTIMER5_BASE                             (0x40048000u)
/** Peripheral CTIMER5 base pointer */
#define CTIMER5                                  ((CTIMER_Type *)CTIMER5_BASE)
/** Peripheral CTIMER6 base address */
#define CTIMER6_BASE                             (0x40049000u)
/** Peripheral CTIMER6 base pointer */
#define CTIMER6                                  ((CTIMER_Type *)CTIMER6_BASE)
/** Peripheral CTIMER7 base address */
#define CTIMER7_BASE                             (0x4004A000u)
/** Peripheral CTIMER7 base pointer */
#define CTIMER7                                  ((CTIMER_Type *)CTIMER7_BASE)
/** Array initializer of CTIMER peripheral base addresses */
#define CTIMER_BASE_ADDRS                        { CTIMER0_BASE, CTIMER1_BASE, CTIMER2_BASE, CTIMER3_BASE, CTIMER4_BASE, CTIMER5_BASE, CTIMER6_BASE, CTIMER7_BASE }
/** Array initializer of CTIMER peripheral base pointers */
#define CTIMER_BASE_PTRS                         { CTIMER0, CTIMER1, CTIMER2, CTIMER3, CTIMER4, CTIMER5, CTIMER6, CTIMER7 }

/* DMA - Peripheral instance base addresses */
/** Peripheral DMA0 base address */
#define DMA0_BASE                                (0x40140000u)
/** Peripheral DMA0 base pointer */
#define DMA0                                     ((DMA_Type *)DMA0_BASE)
/** Peripheral DMA1 base address */
#define DMA1_BASE                                (0x40160000u)
/** Peripheral DMA1 base pointer */
#define DMA1                                     ((DMA_Type *)DMA1_BASE)
/** Peripheral DMA2 base address */
#define DMA2_BASE                                (0x40300000u)
/** Peripheral DMA2 base pointer */
#define DMA2                                     ((DMA_Type *)DMA2_BASE)
/** Peripheral DMA3 base address */
#define DMA3_BASE                                (0x40310000u)
/** Peripheral DMA3 base pointer */
#define DMA3                                     ((DMA_Type *)DMA3_BASE)
/** Array initializer of DMA peripheral base addresses */
#define DMA_BASE_ADDRS                           { DMA0_BASE, DMA1_BASE, DMA2_BASE, DMA3_BASE }
/** Array initializer of DMA peripheral base pointers */
#define DMA_BASE_PTRS                            { DMA0, DMA1, DMA2, DMA3 }

/* ELS - Peripheral instance base addresses */
/** Peripheral ELS base address */
#define ELS_BASE                                 (0x40190000u)
/** Peripheral ELS base pointer */
#define ELS                                      ((ELS_Type *)ELS_BASE)
/** Peripheral ELS_ALIAS1 base address */
#define ELS_ALIAS1_BASE                          (0x40191000u)
/** Peripheral ELS_ALIAS1 base pointer */
#define ELS_ALIAS1                               ((ELS_Type *)ELS_ALIAS1_BASE)
/** Peripheral ELS_ALIAS2 base address */
#define ELS_ALIAS2_BASE                          (0x40192000u)
/** Peripheral ELS_ALIAS2 base pointer */
#define ELS_ALIAS2                               ((ELS_Type *)ELS_ALIAS2_BASE)
/** Peripheral ELS_ALIAS3 base address */
#define ELS_ALIAS3_BASE                          (0x40193000u)
/** Peripheral ELS_ALIAS3 base pointer */
#define ELS_ALIAS3                               ((ELS_Type *)ELS_ALIAS3_BASE)
/** Array initializer of ELS peripheral base addresses */
#define ELS_BASE_ADDRS                           { ELS_BASE, ELS_ALIAS1_BASE, ELS_ALIAS2_BASE, ELS_ALIAS3_BASE }
/** Array initializer of ELS peripheral base pointers */
#define ELS_BASE_PTRS                            { ELS, ELS_ALIAS1, ELS_ALIAS2, ELS_ALIAS3 }

/* FLEXIO - Peripheral instance base addresses */
/** Peripheral FLEXIO base address */
#define FLEXIO_BASE                              (0x40416000u)
/** Peripheral FLEXIO base pointer */
#define FLEXIO                                   ((FLEXIO_Type *)FLEXIO_BASE)
/** Array initializer of FLEXIO peripheral base addresses */
#define FLEXIO_BASE_ADDRS                        { FLEXIO_BASE }
/** Array initializer of FLEXIO peripheral base pointers */
#define FLEXIO_BASE_PTRS                         { FLEXIO }

/* FREQME - Peripheral instance base addresses */
/** Peripheral FREQME base address */
#define FREQME_BASE                              (0x40023000u)
/** Peripheral FREQME base pointer */
#define FREQME                                   ((FREQME_Type *)FREQME_BASE)
/** Array initializer of FREQME peripheral base addresses */
#define FREQME_BASE_ADDRS                        { FREQME_BASE }
/** Array initializer of FREQME peripheral base pointers */
#define FREQME_BASE_PTRS                         { FREQME }

/* FRO - Peripheral instance base addresses */
/** Peripheral FRO0 base address */
#define FRO0_BASE                                (0x40001100u)
/** Peripheral FRO0 base pointer */
#define FRO0                                     ((FRO_Type *)FRO0_BASE)
/** Peripheral FRO1 base address */
#define FRO1_BASE                                (0x40001000u)
/** Peripheral FRO1 base pointer */
#define FRO1                                     ((FRO_Type *)FRO1_BASE)
/** Peripheral FRO2 base address */
#define FRO2_BASE                                (0x40061100u)
/** Peripheral FRO2 base pointer */
#define FRO2                                     ((FRO_Type *)FRO2_BASE)
/** Array initializer of FRO peripheral base addresses */
#define FRO_BASE_ADDRS                           { FRO0_BASE, FRO1_BASE, FRO2_BASE }
/** Array initializer of FRO peripheral base pointers */
#define FRO_BASE_PTRS                            { FRO0, FRO1, FRO2 }

/* GDET - Peripheral instance base addresses */
/** Peripheral GDET0 base address */
#define GDET0_BASE                               (0x40013000u)
/** Peripheral GDET0 base pointer */
#define GDET0                                    ((GDET_Type *)GDET0_BASE)
/** Peripheral GDET3 base address */
#define GDET3_BASE                               (0x4006B000u)
/** Peripheral GDET3 base pointer */
#define GDET3                                    ((GDET_Type *)GDET3_BASE)
/** Array initializer of GDET peripheral base addresses */
#define GDET_BASE_ADDRS                          { GDET0_BASE, 0u, 0u, GDET3_BASE }
/** Array initializer of GDET peripheral base pointers */
#define GDET_BASE_PTRS                           { GDET0, (GDET_Type *)0u, (GDET_Type *)0u, GDET3 }

/* GLIKEY - Peripheral instance base addresses */
/** Peripheral GLIKEY0 base address */
#define GLIKEY0_BASE                             (0x4017CC00u)
/** Peripheral GLIKEY0 base pointer */
#define GLIKEY0                                  ((GLIKEY_Type *)GLIKEY0_BASE)
/** Peripheral GLIKEY1 base address */
#define GLIKEY1_BASE                             (0x40220C00u)
/** Peripheral GLIKEY1 base pointer */
#define GLIKEY1                                  ((GLIKEY_Type *)GLIKEY1_BASE)
/** Peripheral GLIKEY2 base address */
#define GLIKEY2_BASE                             (0x40400C00u)
/** Peripheral GLIKEY2 base pointer */
#define GLIKEY2                                  ((GLIKEY_Type *)GLIKEY2_BASE)
/** Peripheral GLIKEY3 base address */
#define GLIKEY3_BASE                             (0x40002C00u)
/** Peripheral GLIKEY3 base pointer */
#define GLIKEY3                                  ((GLIKEY_Type *)GLIKEY3_BASE)
/** Peripheral GLIKEY4 base address */
#define GLIKEY4_BASE                             (0x40062C00u)
/** Peripheral GLIKEY4 base pointer */
#define GLIKEY4                                  ((GLIKEY_Type *)GLIKEY4_BASE)
/** Peripheral GLIKEY5 base address */
#define GLIKEY5_BASE                             (0x400A2C00u)
/** Peripheral GLIKEY5 base pointer */
#define GLIKEY5                                  ((GLIKEY_Type *)GLIKEY5_BASE)
/** Array initializer of GLIKEY peripheral base addresses */
#define GLIKEY_BASE_ADDRS                        { GLIKEY0_BASE, GLIKEY1_BASE, GLIKEY2_BASE, GLIKEY3_BASE, GLIKEY4_BASE, GLIKEY5_BASE }
/** Array initializer of GLIKEY peripheral base pointers */
#define GLIKEY_BASE_PTRS                         { GLIKEY0, GLIKEY1, GLIKEY2, GLIKEY3, GLIKEY4, GLIKEY5 }

/* GPIO - Peripheral instance base addresses */
/** Peripheral GPIO0 base address */
#define GPIO0_BASE                               (0x40100000u)
/** Peripheral GPIO0 base pointer */
#define GPIO0                                    ((GPIO_Type *)GPIO0_BASE)
/** Peripheral GPIO1 base address */
#define GPIO1_BASE                               (0x40102000u)
/** Peripheral GPIO1 base pointer */
#define GPIO1                                    ((GPIO_Type *)GPIO1_BASE)
/** Peripheral GPIO2 base address */
#define GPIO2_BASE                               (0x40104000u)
/** Peripheral GPIO2 base pointer */
#define GPIO2                                    ((GPIO_Type *)GPIO2_BASE)
/** Peripheral GPIO3 base address */
#define GPIO3_BASE                               (0x40106000u)
/** Peripheral GPIO3 base pointer */
#define GPIO3                                    ((GPIO_Type *)GPIO3_BASE)
/** Peripheral GPIO4 base address */
#define GPIO4_BASE                               (0x40108000u)
/** Peripheral GPIO4 base pointer */
#define GPIO4                                    ((GPIO_Type *)GPIO4_BASE)
/** Peripheral GPIO5 base address */
#define GPIO5_BASE                               (0x4010A000u)
/** Peripheral GPIO5 base pointer */
#define GPIO5                                    ((GPIO_Type *)GPIO5_BASE)
/** Peripheral GPIO6 base address */
#define GPIO6_BASE                               (0x4010C000u)
/** Peripheral GPIO6 base pointer */
#define GPIO6                                    ((GPIO_Type *)GPIO6_BASE)
/** Peripheral GPIO7 base address */
#define GPIO7_BASE                               (0x4010E000u)
/** Peripheral GPIO7 base pointer */
#define GPIO7                                    ((GPIO_Type *)GPIO7_BASE)
/** Peripheral GPIO8 base address */
#define GPIO8_BASE                               (0x40320000u)
/** Peripheral GPIO8 base pointer */
#define GPIO8                                    ((GPIO_Type *)GPIO8_BASE)
/** Peripheral GPIO9 base address */
#define GPIO9_BASE                               (0x40322000u)
/** Peripheral GPIO9 base pointer */
#define GPIO9                                    ((GPIO_Type *)GPIO9_BASE)
/** Peripheral GPIO10 base address */
#define GPIO10_BASE                              (0x40324000u)
/** Peripheral GPIO10 base pointer */
#define GPIO10                                   ((GPIO_Type *)GPIO10_BASE)
/** Peripheral GPIO0_ALIAS base address */
#define GPIO0_ALIAS_BASE                         (0x40101000u)
/** Peripheral GPIO0_ALIAS base pointer */
#define GPIO0_ALIAS                              ((GPIO_Type *)GPIO0_ALIAS_BASE)
/** Peripheral GPIO1_ALIAS base address */
#define GPIO1_ALIAS_BASE                         (0x40103000u)
/** Peripheral GPIO1_ALIAS base pointer */
#define GPIO1_ALIAS                              ((GPIO_Type *)GPIO1_ALIAS_BASE)
/** Peripheral GPIO2_ALIAS base address */
#define GPIO2_ALIAS_BASE                         (0x40105000u)
/** Peripheral GPIO2_ALIAS base pointer */
#define GPIO2_ALIAS                              ((GPIO_Type *)GPIO2_ALIAS_BASE)
/** Peripheral GPIO3_ALIAS base address */
#define GPIO3_ALIAS_BASE                         (0x40107000u)
/** Peripheral GPIO3_ALIAS base pointer */
#define GPIO3_ALIAS                              ((GPIO_Type *)GPIO3_ALIAS_BASE)
/** Peripheral GPIO4_ALIAS base address */
#define GPIO4_ALIAS_BASE                         (0x40109000u)
/** Peripheral GPIO4_ALIAS base pointer */
#define GPIO4_ALIAS                              ((GPIO_Type *)GPIO4_ALIAS_BASE)
/** Peripheral GPIO5_ALIAS base address */
#define GPIO5_ALIAS_BASE                         (0x4010B000u)
/** Peripheral GPIO5_ALIAS base pointer */
#define GPIO5_ALIAS                              ((GPIO_Type *)GPIO5_ALIAS_BASE)
/** Peripheral GPIO6_ALIAS base address */
#define GPIO6_ALIAS_BASE                         (0x4010D000u)
/** Peripheral GPIO6_ALIAS base pointer */
#define GPIO6_ALIAS                              ((GPIO_Type *)GPIO6_ALIAS_BASE)
/** Peripheral GPIO7_ALIAS base address */
#define GPIO7_ALIAS_BASE                         (0x4010F000u)
/** Peripheral GPIO7_ALIAS base pointer */
#define GPIO7_ALIAS                              ((GPIO_Type *)GPIO7_ALIAS_BASE)
/** Peripheral GPIO8_ALIAS base address */
#define GPIO8_ALIAS_BASE                         (0x40321000u)
/** Peripheral GPIO8_ALIAS base pointer */
#define GPIO8_ALIAS                              ((GPIO_Type *)GPIO8_ALIAS_BASE)
/** Peripheral GPIO9_ALIAS base address */
#define GPIO9_ALIAS_BASE                         (0x40323000u)
/** Peripheral GPIO9_ALIAS base pointer */
#define GPIO9_ALIAS                              ((GPIO_Type *)GPIO9_ALIAS_BASE)
/** Peripheral GPIO10_ALIAS base address */
#define GPIO10_ALIAS_BASE                        (0x40325000u)
/** Peripheral GPIO10_ALIAS base pointer */
#define GPIO10_ALIAS                             ((GPIO_Type *)GPIO10_ALIAS_BASE)
/** Array initializer of GPIO peripheral base addresses */
#define GPIO_BASE_ADDRS                          { GPIO0_BASE, GPIO1_BASE, GPIO2_BASE, GPIO3_BASE, GPIO4_BASE, GPIO5_BASE, GPIO6_BASE, GPIO7_BASE, GPIO8_BASE, GPIO9_BASE, GPIO10_BASE, GPIO0_ALIAS_BASE, GPIO1_ALIAS_BASE, GPIO2_ALIAS_BASE, GPIO3_ALIAS_BASE, GPIO4_ALIAS_BASE, GPIO5_ALIAS_BASE, GPIO6_ALIAS_BASE, GPIO7_ALIAS_BASE, GPIO8_ALIAS_BASE, GPIO9_ALIAS_BASE, GPIO10_ALIAS_BASE }
/** Array initializer of GPIO peripheral base pointers */
#define GPIO_BASE_PTRS                           { GPIO0, GPIO1, GPIO2, GPIO3, GPIO4, GPIO5, GPIO6, GPIO7, GPIO8, GPIO9, GPIO10, GPIO0_ALIAS, GPIO1_ALIAS, GPIO2_ALIAS, GPIO3_ALIAS, GPIO4_ALIAS, GPIO5_ALIAS, GPIO6_ALIAS, GPIO7_ALIAS, GPIO8_ALIAS, GPIO9_ALIAS, GPIO10_ALIAS }
/* Interrupt vectors for the GPIO peripheral type */


/* I2S - Peripheral instance base addresses */
/** Peripheral SAI0 base address */
#define SAI0_BASE                                (0x40152000u)
/** Peripheral SAI0 base pointer */
#define SAI0                                     ((I2S_Type *)SAI0_BASE)
/** Peripheral SAI1 base address */
#define SAI1_BASE                                (0x40153000u)
/** Peripheral SAI1 base pointer */
#define SAI1                                     ((I2S_Type *)SAI1_BASE)
/** Peripheral SAI2 base address */
#define SAI2_BASE                                (0x40154000u)
/** Peripheral SAI2 base pointer */
#define SAI2                                     ((I2S_Type *)SAI2_BASE)
/** Peripheral SAI3 base address */
#define SAI3_BASE                                (0x4031C000u)
/** Peripheral SAI3 base pointer */
#define SAI3                                     ((I2S_Type *)SAI3_BASE)
/** Array initializer of I2S peripheral base addresses */
#define I2S_BASE_ADDRS                           { SAI0_BASE, SAI1_BASE, SAI2_BASE, SAI3_BASE }
/** Array initializer of I2S peripheral base pointers */
#define I2S_BASE_PTRS                            { SAI0, SAI1, SAI2, SAI3 }

/* I3C - Peripheral instance base addresses */
/** Peripheral I3C0 base address */
#define I3C0_BASE                                (0x40037000u)
/** Peripheral I3C0 base pointer */
#define I3C0                                     ((I3C_Type *)I3C0_BASE)
/** Peripheral I3C1 base address */
#define I3C1_BASE                                (0x40038000u)
/** Peripheral I3C1 base pointer */
#define I3C1                                     ((I3C_Type *)I3C1_BASE)
/** Peripheral I3C2 base address */
#define I3C2_BASE                                (0x40056000u)
/** Peripheral I3C2 base pointer */
#define I3C2                                     ((I3C_Type *)I3C2_BASE)
/** Peripheral I3C3 base address */
#define I3C3_BASE                                (0x40057000u)
/** Peripheral I3C3 base pointer */
#define I3C3                                     ((I3C_Type *)I3C3_BASE)
/** Array initializer of I3C peripheral base addresses */
#define I3C_BASE_ADDRS                           { I3C0_BASE, I3C1_BASE, I3C2_BASE, I3C3_BASE }
/** Array initializer of I3C peripheral base pointers */
#define I3C_BASE_PTRS                            { I3C0, I3C1, I3C2, I3C3 }

/* INPUTMUX0 - Peripheral instance base addresses */
/** Peripheral INPUTMUX0 base address */
#define INPUTMUX0_BASE                           (0x40026000u)
/** Peripheral INPUTMUX0 base pointer */
#define INPUTMUX0                                ((INPUTMUX0_Type *)INPUTMUX0_BASE)
/** Array initializer of INPUTMUX0 peripheral base addresses */
#define INPUTMUX0_BASE_ADDRS                     { INPUTMUX0_BASE }
/** Array initializer of INPUTMUX0 peripheral base pointers */
#define INPUTMUX0_BASE_PTRS                      { INPUTMUX0 }

/* INPUTMUX1 - Peripheral instance base addresses */
/** Peripheral INPUTMUX1 base address */
#define INPUTMUX1_BASE                           (0x40046000u)
/** Peripheral INPUTMUX1 base pointer */
#define INPUTMUX1                                ((INPUTMUX1_Type *)INPUTMUX1_BASE)
/** Array initializer of INPUTMUX1 peripheral base addresses */
#define INPUTMUX1_BASE_ADDRS                     { INPUTMUX1_BASE }
/** Array initializer of INPUTMUX1 peripheral base pointers */
#define INPUTMUX1_BASE_PTRS                      { INPUTMUX1 }

/* IOPCTL0 - Peripheral instance base addresses */
/** Peripheral IOPCTL0 base address */
#define IOPCTL0_BASE                             (0x40004000u)
/** Peripheral IOPCTL0 base pointer */
#define IOPCTL0                                  ((IOPCTL0_Type *)IOPCTL0_BASE)
/** Array initializer of IOPCTL0 peripheral base addresses */
#define IOPCTL0_BASE_ADDRS                       { IOPCTL0_BASE }
/** Array initializer of IOPCTL0 peripheral base pointers */
#define IOPCTL0_BASE_PTRS                        { IOPCTL0 }

/* IOPCTL1 - Peripheral instance base addresses */
/** Peripheral IOPCTL1 base address */
#define IOPCTL1_BASE                             (0x40064000u)
/** Peripheral IOPCTL1 base pointer */
#define IOPCTL1                                  ((IOPCTL1_Type *)IOPCTL1_BASE)
/** Array initializer of IOPCTL1 peripheral base addresses */
#define IOPCTL1_BASE_ADDRS                       { IOPCTL1_BASE }
/** Array initializer of IOPCTL1 peripheral base pointers */
#define IOPCTL1_BASE_PTRS                        { IOPCTL1 }

/* IOPCTL2 - Peripheral instance base addresses */
/** Peripheral IOPCTL2 base address */
#define IOPCTL2_BASE                             (0x400A5000u)
/** Peripheral IOPCTL2 base pointer */
#define IOPCTL2                                  ((IOPCTL2_Type *)IOPCTL2_BASE)
/** Array initializer of IOPCTL2 peripheral base addresses */
#define IOPCTL2_BASE_ADDRS                       { IOPCTL2_BASE }
/** Array initializer of IOPCTL2 peripheral base pointers */
#define IOPCTL2_BASE_PTRS                        { IOPCTL2 }
/** Array initializer of IOPCTL peripheral base addresses */
  #define IOPCTL_BASE_ADDRS                        {IOPCTL0_BASE, IOPCTL1_BASE, IOPCTLR2_BASE}


/* JPEGDEC - Peripheral instance base addresses */
/** Peripheral JPEGDEC base address */
#define JPEGDEC_BASE                             (0x400A6100u)
/** Peripheral JPEGDEC base pointer */
#define JPEGDEC                                  ((JPEGDEC_Type *)JPEGDEC_BASE)
/** Array initializer of JPEGDEC peripheral base addresses */
#define JPEGDEC_BASE_ADDRS                       { JPEGDEC_BASE }
/** Array initializer of JPEGDEC peripheral base pointers */
#define JPEGDEC_BASE_PTRS                        { JPEGDEC }

/* JPGDECWRP - Peripheral instance base addresses */
/** Peripheral JPGDECWRP base address */
#define JPGDECWRP_BASE                           (0x400A6000u)
/** Peripheral JPGDECWRP base pointer */
#define JPGDECWRP                                ((JPGDECWRP_Type *)JPGDECWRP_BASE)
/** Array initializer of JPGDECWRP peripheral base addresses */
#define JPGDECWRP_BASE_ADDRS                     { JPGDECWRP_BASE }
/** Array initializer of JPGDECWRP peripheral base pointers */
#define JPGDECWRP_BASE_PTRS                      { JPGDECWRP }

/* LCDIF - Peripheral instance base addresses */
/** Peripheral LCDIF base address */
#define LCDIF_BASE                               (0x40480000u)
/** Peripheral LCDIF base pointer */
#define LCDIF                                    ((LCDIF_Type *)LCDIF_BASE)
/** Array initializer of LCDIF peripheral base addresses */
#define LCDIF_BASE_ADDRS                         { LCDIF_BASE }
/** Array initializer of LCDIF peripheral base pointers */
#define LCDIF_BASE_PTRS                          { LCDIF }

/* LPI2C - Peripheral instance base addresses */
/** Peripheral LPI2C0 base address */
#define LPI2C0_BASE                              (0x40110800u)
/** Peripheral LPI2C0 base pointer */
#define LPI2C0                                   ((LPI2C_Type *)LPI2C0_BASE)
/** Peripheral LPI2C1 base address */
#define LPI2C1_BASE                              (0x40111800u)
/** Peripheral LPI2C1 base pointer */
#define LPI2C1                                   ((LPI2C_Type *)LPI2C1_BASE)
/** Peripheral LPI2C2 base address */
#define LPI2C2_BASE                              (0x40112800u)
/** Peripheral LPI2C2 base pointer */
#define LPI2C2                                   ((LPI2C_Type *)LPI2C2_BASE)
/** Peripheral LPI2C3 base address */
#define LPI2C3_BASE                              (0x40113800u)
/** Peripheral LPI2C3 base pointer */
#define LPI2C3                                   ((LPI2C_Type *)LPI2C3_BASE)
/** Peripheral LPI2C4 base address */
#define LPI2C4_BASE                              (0x40171800u)
/** Peripheral LPI2C4 base pointer */
#define LPI2C4                                   ((LPI2C_Type *)LPI2C4_BASE)
/** Peripheral LPI2C5 base address */
#define LPI2C5_BASE                              (0x40172800u)
/** Peripheral LPI2C5 base pointer */
#define LPI2C5                                   ((LPI2C_Type *)LPI2C5_BASE)
/** Peripheral LPI2C6 base address */
#define LPI2C6_BASE                              (0x40173800u)
/** Peripheral LPI2C6 base pointer */
#define LPI2C6                                   ((LPI2C_Type *)LPI2C6_BASE)
/** Peripheral LPI2C7 base address */
#define LPI2C7_BASE                              (0x40174800u)
/** Peripheral LPI2C7 base pointer */
#define LPI2C7                                   ((LPI2C_Type *)LPI2C7_BASE)
/** Peripheral LPI2C8 base address */
#define LPI2C8_BASE                              (0x40199800u)
/** Peripheral LPI2C8 base pointer */
#define LPI2C8                                   ((LPI2C_Type *)LPI2C8_BASE)
/** Peripheral LPI2C9 base address */
#define LPI2C9_BASE                              (0x4019A800u)
/** Peripheral LPI2C9 base pointer */
#define LPI2C9                                   ((LPI2C_Type *)LPI2C9_BASE)
/** Peripheral LPI2C10 base address */
#define LPI2C10_BASE                             (0x4019B800u)
/** Peripheral LPI2C10 base pointer */
#define LPI2C10                                  ((LPI2C_Type *)LPI2C10_BASE)
/** Peripheral LPI2C11 base address */
#define LPI2C11_BASE                             (0x4019C800u)
/** Peripheral LPI2C11 base pointer */
#define LPI2C11                                  ((LPI2C_Type *)LPI2C11_BASE)
/** Peripheral LPI2C12 base address */
#define LPI2C12_BASE                             (0x4019D800u)
/** Peripheral LPI2C12 base pointer */
#define LPI2C12                                  ((LPI2C_Type *)LPI2C12_BASE)
/** Peripheral LPI2C13 base address */
#define LPI2C13_BASE                             (0x4019E800u)
/** Peripheral LPI2C13 base pointer */
#define LPI2C13                                  ((LPI2C_Type *)LPI2C13_BASE)
/** Peripheral LPI2C15 base address */
#define LPI2C15_BASE                             (0x40213000u)
/** Peripheral LPI2C15 base pointer */
#define LPI2C15                                  ((LPI2C_Type *)LPI2C15_BASE)
/** Peripheral LPI2C17 base address */
#define LPI2C17_BASE                             (0x40326800u)
/** Peripheral LPI2C17 base pointer */
#define LPI2C17                                  ((LPI2C_Type *)LPI2C17_BASE)
/** Peripheral LPI2C18 base address */
#define LPI2C18_BASE                             (0x40327800u)
/** Peripheral LPI2C18 base pointer */
#define LPI2C18                                  ((LPI2C_Type *)LPI2C18_BASE)
/** Peripheral LPI2C19 base address */
#define LPI2C19_BASE                             (0x40328800u)
/** Peripheral LPI2C19 base pointer */
#define LPI2C19                                  ((LPI2C_Type *)LPI2C19_BASE)
/** Peripheral LPI2C20 base address */
#define LPI2C20_BASE                             (0x40329800u)
/** Peripheral LPI2C20 base pointer */
#define LPI2C20                                  ((LPI2C_Type *)LPI2C20_BASE)
/** Array initializer of LPI2C peripheral base addresses */
#define LPI2C_BASE_ADDRS                         { LPI2C0_BASE, LPI2C1_BASE, LPI2C2_BASE, LPI2C3_BASE, LPI2C4_BASE, LPI2C5_BASE, LPI2C6_BASE, LPI2C7_BASE, LPI2C8_BASE, LPI2C9_BASE, LPI2C10_BASE, LPI2C11_BASE, LPI2C12_BASE, LPI2C13_BASE, 0u, LPI2C15_BASE, 0u, LPI2C17_BASE, LPI2C18_BASE, LPI2C19_BASE, LPI2C20_BASE }
/** Array initializer of LPI2C peripheral base pointers */
#define LPI2C_BASE_PTRS                          { LPI2C0, LPI2C1, LPI2C2, LPI2C3, LPI2C4, LPI2C5, LPI2C6, LPI2C7, LPI2C8, LPI2C9, LPI2C10, LPI2C11, LPI2C12, LPI2C13, (LPI2C_Type *)0u, LPI2C15, (LPI2C_Type *)0u, LPI2C17, LPI2C18, LPI2C19, LPI2C20 }

/* LPSPI - Peripheral instance base addresses */
/** Peripheral LPSPI0 base address */
#define LPSPI0_BASE                              (0x40110000u)
/** Peripheral LPSPI0 base pointer */
#define LPSPI0                                   ((LPSPI_Type *)LPSPI0_BASE)
/** Peripheral LPSPI1 base address */
#define LPSPI1_BASE                              (0x40111000u)
/** Peripheral LPSPI1 base pointer */
#define LPSPI1                                   ((LPSPI_Type *)LPSPI1_BASE)
/** Peripheral LPSPI2 base address */
#define LPSPI2_BASE                              (0x40112000u)
/** Peripheral LPSPI2 base pointer */
#define LPSPI2                                   ((LPSPI_Type *)LPSPI2_BASE)
/** Peripheral LPSPI3 base address */
#define LPSPI3_BASE                              (0x40113000u)
/** Peripheral LPSPI3 base pointer */
#define LPSPI3                                   ((LPSPI_Type *)LPSPI3_BASE)
/** Peripheral LPSPI4 base address */
#define LPSPI4_BASE                              (0x40171000u)
/** Peripheral LPSPI4 base pointer */
#define LPSPI4                                   ((LPSPI_Type *)LPSPI4_BASE)
/** Peripheral LPSPI5 base address */
#define LPSPI5_BASE                              (0x40172000u)
/** Peripheral LPSPI5 base pointer */
#define LPSPI5                                   ((LPSPI_Type *)LPSPI5_BASE)
/** Peripheral LPSPI6 base address */
#define LPSPI6_BASE                              (0x40173000u)
/** Peripheral LPSPI6 base pointer */
#define LPSPI6                                   ((LPSPI_Type *)LPSPI6_BASE)
/** Peripheral LPSPI7 base address */
#define LPSPI7_BASE                              (0x40174000u)
/** Peripheral LPSPI7 base pointer */
#define LPSPI7                                   ((LPSPI_Type *)LPSPI7_BASE)
/** Peripheral LPSPI8 base address */
#define LPSPI8_BASE                              (0x40199000u)
/** Peripheral LPSPI8 base pointer */
#define LPSPI8                                   ((LPSPI_Type *)LPSPI8_BASE)
/** Peripheral LPSPI9 base address */
#define LPSPI9_BASE                              (0x4019A000u)
/** Peripheral LPSPI9 base pointer */
#define LPSPI9                                   ((LPSPI_Type *)LPSPI9_BASE)
/** Peripheral LPSPI10 base address */
#define LPSPI10_BASE                             (0x4019B000u)
/** Peripheral LPSPI10 base pointer */
#define LPSPI10                                  ((LPSPI_Type *)LPSPI10_BASE)
/** Peripheral LPSPI11 base address */
#define LPSPI11_BASE                             (0x4019C000u)
/** Peripheral LPSPI11 base pointer */
#define LPSPI11                                  ((LPSPI_Type *)LPSPI11_BASE)
/** Peripheral LPSPI12 base address */
#define LPSPI12_BASE                             (0x4019D000u)
/** Peripheral LPSPI12 base pointer */
#define LPSPI12                                  ((LPSPI_Type *)LPSPI12_BASE)
/** Peripheral LPSPI13 base address */
#define LPSPI13_BASE                             (0x4019E000u)
/** Peripheral LPSPI13 base pointer */
#define LPSPI13                                  ((LPSPI_Type *)LPSPI13_BASE)
/** Peripheral LPSPI14 base address */
#define LPSPI14_BASE                             (0x40484000u)
/** Peripheral LPSPI14 base pointer */
#define LPSPI14                                  ((LPSPI_Type *)LPSPI14_BASE)
/** Peripheral LPSPI16 base address */
#define LPSPI16_BASE                             (0x40405000u)
/** Peripheral LPSPI16 base pointer */
#define LPSPI16                                  ((LPSPI_Type *)LPSPI16_BASE)
/** Peripheral LPSPI17 base address */
#define LPSPI17_BASE                             (0x40326000u)
/** Peripheral LPSPI17 base pointer */
#define LPSPI17                                  ((LPSPI_Type *)LPSPI17_BASE)
/** Peripheral LPSPI18 base address */
#define LPSPI18_BASE                             (0x40327000u)
/** Peripheral LPSPI18 base pointer */
#define LPSPI18                                  ((LPSPI_Type *)LPSPI18_BASE)
/** Peripheral LPSPI19 base address */
#define LPSPI19_BASE                             (0x40328000u)
/** Peripheral LPSPI19 base pointer */
#define LPSPI19                                  ((LPSPI_Type *)LPSPI19_BASE)
/** Peripheral LPSPI20 base address */
#define LPSPI20_BASE                             (0x40329000u)
/** Peripheral LPSPI20 base pointer */
#define LPSPI20                                  ((LPSPI_Type *)LPSPI20_BASE)
/** Array initializer of LPSPI peripheral base addresses */
#define LPSPI_BASE_ADDRS                         { LPSPI0_BASE, LPSPI1_BASE, LPSPI2_BASE, LPSPI3_BASE, LPSPI4_BASE, LPSPI5_BASE, LPSPI6_BASE, LPSPI7_BASE, LPSPI8_BASE, LPSPI9_BASE, LPSPI10_BASE, LPSPI11_BASE, LPSPI12_BASE, LPSPI13_BASE, LPSPI14_BASE, 0u, LPSPI16_BASE, LPSPI17_BASE, LPSPI18_BASE, LPSPI19_BASE, LPSPI20_BASE }
/** Array initializer of LPSPI peripheral base pointers */
#define LPSPI_BASE_PTRS                          { LPSPI0, LPSPI1, LPSPI2, LPSPI3, LPSPI4, LPSPI5, LPSPI6, LPSPI7, LPSPI8, LPSPI9, LPSPI10, LPSPI11, LPSPI12, LPSPI13, LPSPI14, (LPSPI_Type *)0u, LPSPI16, LPSPI17, LPSPI18, LPSPI19, LPSPI20 }

/* LPUART - Peripheral instance base addresses */
/** Peripheral LPUART0 base address */
#define LPUART0_BASE                             (0x40110000u)
/** Peripheral LPUART0 base pointer */
#define LPUART0                                  ((LPUART_Type *)LPUART0_BASE)
/** Peripheral LPUART1 base address */
#define LPUART1_BASE                             (0x40111000u)
/** Peripheral LPUART1 base pointer */
#define LPUART1                                  ((LPUART_Type *)LPUART1_BASE)
/** Peripheral LPUART2 base address */
#define LPUART2_BASE                             (0x40112000u)
/** Peripheral LPUART2 base pointer */
#define LPUART2                                  ((LPUART_Type *)LPUART2_BASE)
/** Peripheral LPUART3 base address */
#define LPUART3_BASE                             (0x40113000u)
/** Peripheral LPUART3 base pointer */
#define LPUART3                                  ((LPUART_Type *)LPUART3_BASE)
/** Peripheral LPUART4 base address */
#define LPUART4_BASE                             (0x40171000u)
/** Peripheral LPUART4 base pointer */
#define LPUART4                                  ((LPUART_Type *)LPUART4_BASE)
/** Peripheral LPUART5 base address */
#define LPUART5_BASE                             (0x40172000u)
/** Peripheral LPUART5 base pointer */
#define LPUART5                                  ((LPUART_Type *)LPUART5_BASE)
/** Peripheral LPUART6 base address */
#define LPUART6_BASE                             (0x40173000u)
/** Peripheral LPUART6 base pointer */
#define LPUART6                                  ((LPUART_Type *)LPUART6_BASE)
/** Peripheral LPUART7 base address */
#define LPUART7_BASE                             (0x40174000u)
/** Peripheral LPUART7 base pointer */
#define LPUART7                                  ((LPUART_Type *)LPUART7_BASE)
/** Peripheral LPUART8 base address */
#define LPUART8_BASE                             (0x40199000u)
/** Peripheral LPUART8 base pointer */
#define LPUART8                                  ((LPUART_Type *)LPUART8_BASE)
/** Peripheral LPUART9 base address */
#define LPUART9_BASE                             (0x4019A000u)
/** Peripheral LPUART9 base pointer */
#define LPUART9                                  ((LPUART_Type *)LPUART9_BASE)
/** Peripheral LPUART10 base address */
#define LPUART10_BASE                            (0x4019B000u)
/** Peripheral LPUART10 base pointer */
#define LPUART10                                 ((LPUART_Type *)LPUART10_BASE)
/** Peripheral LPUART11 base address */
#define LPUART11_BASE                            (0x4019C000u)
/** Peripheral LPUART11 base pointer */
#define LPUART11                                 ((LPUART_Type *)LPUART11_BASE)
/** Peripheral LPUART12 base address */
#define LPUART12_BASE                            (0x4019D000u)
/** Peripheral LPUART12 base pointer */
#define LPUART12                                 ((LPUART_Type *)LPUART12_BASE)
/** Peripheral LPUART13 base address */
#define LPUART13_BASE                            (0x4019E000u)
/** Peripheral LPUART13 base pointer */
#define LPUART13                                 ((LPUART_Type *)LPUART13_BASE)
/** Peripheral LPUART17 base address */
#define LPUART17_BASE                            (0x40326000u)
/** Peripheral LPUART17 base pointer */
#define LPUART17                                 ((LPUART_Type *)LPUART17_BASE)
/** Peripheral LPUART18 base address */
#define LPUART18_BASE                            (0x40327000u)
/** Peripheral LPUART18 base pointer */
#define LPUART18                                 ((LPUART_Type *)LPUART18_BASE)
/** Peripheral LPUART19 base address */
#define LPUART19_BASE                            (0x40328000u)
/** Peripheral LPUART19 base pointer */
#define LPUART19                                 ((LPUART_Type *)LPUART19_BASE)
/** Peripheral LPUART20 base address */
#define LPUART20_BASE                            (0x40329000u)
/** Peripheral LPUART20 base pointer */
#define LPUART20                                 ((LPUART_Type *)LPUART20_BASE)
/** Array initializer of LPUART peripheral base addresses */
#define LPUART_BASE_ADDRS                        { LPUART0_BASE, LPUART1_BASE, LPUART2_BASE, LPUART3_BASE, LPUART4_BASE, LPUART5_BASE, LPUART6_BASE, LPUART7_BASE, LPUART8_BASE, LPUART9_BASE, LPUART10_BASE, LPUART11_BASE, LPUART12_BASE, LPUART13_BASE, 0u, 0u, 0u, LPUART17_BASE, LPUART18_BASE, LPUART19_BASE, LPUART20_BASE }
/** Array initializer of LPUART peripheral base pointers */
#define LPUART_BASE_PTRS                         { LPUART0, LPUART1, LPUART2, LPUART3, LPUART4, LPUART5, LPUART6, LPUART7, LPUART8, LPUART9, LPUART10, LPUART11, LPUART12, LPUART13, (LPUART_Type *)0u, (LPUART_Type *)0u, (LPUART_Type *)0u, LPUART17, LPUART18, LPUART19, LPUART20 }
#define LPUART_RX_TX_IRQS                        { NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn }
#define LPUART_ERR_IRQS                          { NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn }


/* LP_FLEXCOMM - Peripheral instance base addresses */
/** Peripheral LP_FLEXCOMM0 base address */
#define LP_FLEXCOMM0_BASE                        (0x40110000u)
/** Peripheral LP_FLEXCOMM0 base pointer */
#define LP_FLEXCOMM0                             ((LP_FLEXCOMM_Type *)LP_FLEXCOMM0_BASE)
/** Peripheral LP_FLEXCOMM1 base address */
#define LP_FLEXCOMM1_BASE                        (0x40111000u)
/** Peripheral LP_FLEXCOMM1 base pointer */
#define LP_FLEXCOMM1                             ((LP_FLEXCOMM_Type *)LP_FLEXCOMM1_BASE)
/** Peripheral LP_FLEXCOMM2 base address */
#define LP_FLEXCOMM2_BASE                        (0x40112000u)
/** Peripheral LP_FLEXCOMM2 base pointer */
#define LP_FLEXCOMM2                             ((LP_FLEXCOMM_Type *)LP_FLEXCOMM2_BASE)
/** Peripheral LP_FLEXCOMM3 base address */
#define LP_FLEXCOMM3_BASE                        (0x40113000u)
/** Peripheral LP_FLEXCOMM3 base pointer */
#define LP_FLEXCOMM3                             ((LP_FLEXCOMM_Type *)LP_FLEXCOMM3_BASE)
/** Peripheral LP_FLEXCOMM4 base address */
#define LP_FLEXCOMM4_BASE                        (0x40171000u)
/** Peripheral LP_FLEXCOMM4 base pointer */
#define LP_FLEXCOMM4                             ((LP_FLEXCOMM_Type *)LP_FLEXCOMM4_BASE)
/** Peripheral LP_FLEXCOMM5 base address */
#define LP_FLEXCOMM5_BASE                        (0x40172000u)
/** Peripheral LP_FLEXCOMM5 base pointer */
#define LP_FLEXCOMM5                             ((LP_FLEXCOMM_Type *)LP_FLEXCOMM5_BASE)
/** Peripheral LP_FLEXCOMM6 base address */
#define LP_FLEXCOMM6_BASE                        (0x40173000u)
/** Peripheral LP_FLEXCOMM6 base pointer */
#define LP_FLEXCOMM6                             ((LP_FLEXCOMM_Type *)LP_FLEXCOMM6_BASE)
/** Peripheral LP_FLEXCOMM7 base address */
#define LP_FLEXCOMM7_BASE                        (0x40174000u)
/** Peripheral LP_FLEXCOMM7 base pointer */
#define LP_FLEXCOMM7                             ((LP_FLEXCOMM_Type *)LP_FLEXCOMM7_BASE)
/** Peripheral LP_FLEXCOMM8 base address */
#define LP_FLEXCOMM8_BASE                        (0x40199000u)
/** Peripheral LP_FLEXCOMM8 base pointer */
#define LP_FLEXCOMM8                             ((LP_FLEXCOMM_Type *)LP_FLEXCOMM8_BASE)
/** Peripheral LP_FLEXCOMM9 base address */
#define LP_FLEXCOMM9_BASE                        (0x4019A000u)
/** Peripheral LP_FLEXCOMM9 base pointer */
#define LP_FLEXCOMM9                             ((LP_FLEXCOMM_Type *)LP_FLEXCOMM9_BASE)
/** Peripheral LP_FLEXCOMM10 base address */
#define LP_FLEXCOMM10_BASE                       (0x4019B000u)
/** Peripheral LP_FLEXCOMM10 base pointer */
#define LP_FLEXCOMM10                            ((LP_FLEXCOMM_Type *)LP_FLEXCOMM10_BASE)
/** Peripheral LP_FLEXCOMM11 base address */
#define LP_FLEXCOMM11_BASE                       (0x4019C000u)
/** Peripheral LP_FLEXCOMM11 base pointer */
#define LP_FLEXCOMM11                            ((LP_FLEXCOMM_Type *)LP_FLEXCOMM11_BASE)
/** Peripheral LP_FLEXCOMM12 base address */
#define LP_FLEXCOMM12_BASE                       (0x4019D000u)
/** Peripheral LP_FLEXCOMM12 base pointer */
#define LP_FLEXCOMM12                            ((LP_FLEXCOMM_Type *)LP_FLEXCOMM12_BASE)
/** Peripheral LP_FLEXCOMM13 base address */
#define LP_FLEXCOMM13_BASE                       (0x4019E000u)
/** Peripheral LP_FLEXCOMM13 base pointer */
#define LP_FLEXCOMM13                            ((LP_FLEXCOMM_Type *)LP_FLEXCOMM13_BASE)
/** Peripheral LP_FLEXCOMM17 base address */
#define LP_FLEXCOMM17_BASE                       (0x40326000u)
/** Peripheral LP_FLEXCOMM17 base pointer */
#define LP_FLEXCOMM17                            ((LP_FLEXCOMM_Type *)LP_FLEXCOMM17_BASE)
/** Peripheral LP_FLEXCOMM18 base address */
#define LP_FLEXCOMM18_BASE                       (0x40327000u)
/** Peripheral LP_FLEXCOMM18 base pointer */
#define LP_FLEXCOMM18                            ((LP_FLEXCOMM_Type *)LP_FLEXCOMM18_BASE)
/** Peripheral LP_FLEXCOMM19 base address */
#define LP_FLEXCOMM19_BASE                       (0x40328000u)
/** Peripheral LP_FLEXCOMM19 base pointer */
#define LP_FLEXCOMM19                            ((LP_FLEXCOMM_Type *)LP_FLEXCOMM19_BASE)
/** Peripheral LP_FLEXCOMM20 base address */
#define LP_FLEXCOMM20_BASE                       (0x40329000u)
/** Peripheral LP_FLEXCOMM20 base pointer */
#define LP_FLEXCOMM20                            ((LP_FLEXCOMM_Type *)LP_FLEXCOMM20_BASE)
/** Array initializer of LP_FLEXCOMM peripheral base addresses */
#define LP_FLEXCOMM_BASE_ADDRS                   { LP_FLEXCOMM0_BASE, LP_FLEXCOMM1_BASE, LP_FLEXCOMM2_BASE, LP_FLEXCOMM3_BASE, LP_FLEXCOMM4_BASE, LP_FLEXCOMM5_BASE, LP_FLEXCOMM6_BASE, LP_FLEXCOMM7_BASE, LP_FLEXCOMM8_BASE, LP_FLEXCOMM9_BASE, LP_FLEXCOMM10_BASE, LP_FLEXCOMM11_BASE, LP_FLEXCOMM12_BASE, LP_FLEXCOMM13_BASE, 0u, 0u, 0u, LP_FLEXCOMM17_BASE, LP_FLEXCOMM18_BASE, LP_FLEXCOMM19_BASE, LP_FLEXCOMM20_BASE }
/** Array initializer of LP_FLEXCOMM peripheral base pointers */
#define LP_FLEXCOMM_BASE_PTRS                    { LP_FLEXCOMM0, LP_FLEXCOMM1, LP_FLEXCOMM2, LP_FLEXCOMM3, LP_FLEXCOMM4, LP_FLEXCOMM5, LP_FLEXCOMM6, LP_FLEXCOMM7, LP_FLEXCOMM8, LP_FLEXCOMM9, LP_FLEXCOMM10, LP_FLEXCOMM11, LP_FLEXCOMM12, LP_FLEXCOMM13, (LP_FLEXCOMM_Type *)0u, (LP_FLEXCOMM_Type *)0u, (LP_FLEXCOMM_Type *)0u, LP_FLEXCOMM17, LP_FLEXCOMM18, LP_FLEXCOMM19, LP_FLEXCOMM20 }
#define LP_FLEXCOMM_IRQS                         { NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn }


/* MIPI_DSI_HOST - Peripheral instance base addresses */
/** Peripheral MIPI_DSI_HOST base address */
#define MIPI_DSI_HOST_BASE                       (0x40417000u)
/** Peripheral MIPI_DSI_HOST base pointer */
#define MIPI_DSI_HOST                            ((MIPI_DSI_HOST_Type *)MIPI_DSI_HOST_BASE)
/** Array initializer of MIPI_DSI_HOST peripheral base addresses */
#define MIPI_DSI_HOST_BASE_ADDRS                 { MIPI_DSI_HOST_BASE }
/** Array initializer of MIPI_DSI_HOST peripheral base pointers */
#define MIPI_DSI_HOST_BASE_PTRS                  { MIPI_DSI_HOST }

/* MMU - Peripheral instance base addresses */
/** Peripheral MMU0 base address */
#define MMU0_BASE                                (0x40030000u)
/** Peripheral MMU0 base pointer */
#define MMU0                                     ((MMU_Type *)MMU0_BASE)
/** Peripheral MMU1 base address */
#define MMU1_BASE                                (0x40031000u)
/** Peripheral MMU1 base pointer */
#define MMU1                                     ((MMU_Type *)MMU1_BASE)
/** Peripheral MMU2 base address */
#define MMU2_BASE                                (0x400A8000u)
/** Peripheral MMU2 base pointer */
#define MMU2                                     ((MMU_Type *)MMU2_BASE)
/** Array initializer of MMU peripheral base addresses */
#define MMU_BASE_ADDRS                           { MMU0_BASE, MMU1_BASE, MMU2_BASE }
/** Array initializer of MMU peripheral base pointers */
#define MMU_BASE_PTRS                            { MMU0, MMU1, MMU2 }

/* MRT - Peripheral instance base addresses */
/** Peripheral MRT0 base address */
#define MRT0_BASE                                (0x4002D000u)
/** Peripheral MRT0 base pointer */
#define MRT0                                     ((MRT_Type *)MRT0_BASE)
/** Peripheral MRT1 base address */
#define MRT1_BASE                                (0x4004D000u)
/** Peripheral MRT1 base pointer */
#define MRT1                                     ((MRT_Type *)MRT1_BASE)
/** Array initializer of MRT peripheral base addresses */
#define MRT_BASE_ADDRS                           { MRT0_BASE, MRT1_BASE }
/** Array initializer of MRT peripheral base pointers */
#define MRT_BASE_PTRS                            { MRT0, MRT1 }

/* MU - Peripheral instance base addresses */
/** Peripheral MU0_MUA base address */
#define MU0_MUA_BASE                             (0x40200000u)
/** Peripheral MU0_MUA base pointer */
#define MU0_MUA                                  ((MU_Type *)MU0_MUA_BASE)
/** Peripheral MU0_MUB base address */
#define MU0_MUB_BASE                             (0x40201000u)
/** Peripheral MU0_MUB base pointer */
#define MU0_MUB                                  ((MU_Type *)MU0_MUB_BASE)
/** Peripheral MU1_MUA base address */
#define MU1_MUA_BASE                             (0x40202000u)
/** Peripheral MU1_MUA base pointer */
#define MU1_MUA                                  ((MU_Type *)MU1_MUA_BASE)
/** Peripheral MU1_MUB base address */
#define MU1_MUB_BASE                             (0x40203000u)
/** Peripheral MU1_MUB base pointer */
#define MU1_MUB                                  ((MU_Type *)MU1_MUB_BASE)
/** Peripheral MU2_MUA base address */
#define MU2_MUA_BASE                             (0x40204000u)
/** Peripheral MU2_MUA base pointer */
#define MU2_MUA                                  ((MU_Type *)MU2_MUA_BASE)
/** Peripheral MU2_MUB base address */
#define MU2_MUB_BASE                             (0x40205000u)
/** Peripheral MU2_MUB base pointer */
#define MU2_MUB                                  ((MU_Type *)MU2_MUB_BASE)
/** Peripheral MU3_MUA base address */
#define MU3_MUA_BASE                             (0x40319000u)
/** Peripheral MU3_MUA base pointer */
#define MU3_MUA                                  ((MU_Type *)MU3_MUA_BASE)
/** Peripheral MU3_MUB base address */
#define MU3_MUB_BASE                             (0x4031A000u)
/** Peripheral MU3_MUB base pointer */
#define MU3_MUB                                  ((MU_Type *)MU3_MUB_BASE)
/** Array initializer of MU peripheral base addresses */
#define MU_BASE_ADDRS                            { MU0_MUA_BASE, MU0_MUB_BASE, MU1_MUA_BASE, MU1_MUB_BASE, MU2_MUA_BASE, MU2_MUB_BASE, MU3_MUA_BASE, MU3_MUB_BASE }
/** Array initializer of MU peripheral base pointers */
#define MU_BASE_PTRS                             { MU0_MUA, MU0_MUB, MU1_MUA, MU1_MUB, MU2_MUA, MU2_MUB, MU3_MUA, MU3_MUB }

/* NIC - Peripheral instance base addresses */
/** Peripheral NIC_MEDIA1 base address */
#define NIC_MEDIA1_BASE                          (0x404C0000u)
/** Peripheral NIC_MEDIA1 base pointer */
#define NIC_MEDIA1                               ((NIC_Type *)NIC_MEDIA1_BASE)
/** Array initializer of NIC peripheral base addresses */
#define NIC_BASE_ADDRS                           { NIC_MEDIA1_BASE }
/** Array initializer of NIC peripheral base pointers */
#define NIC_BASE_PTRS                            { NIC_MEDIA1 }

/* OCOTP - Peripheral instance base addresses */
/** Peripheral OCOTP base address */
#define OCOTP_BASE                               (0x40018000u)
/** Peripheral OCOTP base pointer */
#define OCOTP                                    ((OCOTP_Type *)OCOTP_BASE)
/** Array initializer of OCOTP peripheral base addresses */
#define OCOTP_BASE_ADDRS                         { OCOTP_BASE }
/** Array initializer of OCOTP peripheral base pointers */
#define OCOTP_BASE_PTRS                          { OCOTP }

/* OSC32KNP - Peripheral instance base addresses */
/** Peripheral OSC32KNP base address */
#define OSC32KNP_BASE                            (0x40063000u)
/** Peripheral OSC32KNP base pointer */
#define OSC32KNP                                 ((OSC32KNP_Type *)OSC32KNP_BASE)
/** Array initializer of OSC32KNP peripheral base addresses */
#define OSC32KNP_BASE_ADDRS                      { OSC32KNP_BASE }
/** Array initializer of OSC32KNP peripheral base pointers */
#define OSC32KNP_BASE_PTRS                       { OSC32KNP }

/* OSCCA - Peripheral instance base addresses */
/** Peripheral OSCCA base address */
#define OSCCA_BASE                               (0x4001A000u)
/** Peripheral OSCCA base pointer */
#define OSCCA                                    ((OSCCA_Type *)OSCCA_BASE)
/** Array initializer of OSCCA peripheral base addresses */
#define OSCCA_BASE_ADDRS                         { OSCCA_BASE }
/** Array initializer of OSCCA peripheral base pointers */
#define OSCCA_BASE_PTRS                          { OSCCA }

/* OSTIMER - Peripheral instance base addresses */
/** Peripheral OSTIMER_CPU0 base address */
#define OSTIMER_CPU0_BASE                        (0x40207000u)
/** Peripheral OSTIMER_CPU0 base pointer */
#define OSTIMER_CPU0                             ((OSTIMER_Type *)OSTIMER_CPU0_BASE)
/** Peripheral OSTIMER_CPU1 base address */
#define OSTIMER_CPU1_BASE                        (0x40209000u)
/** Peripheral OSTIMER_CPU1 base pointer */
#define OSTIMER_CPU1                             ((OSTIMER_Type *)OSTIMER_CPU1_BASE)
/** Peripheral OSTIMER_HIFI1 base address */
#define OSTIMER_HIFI1_BASE                       (0x4020A000u)
/** Peripheral OSTIMER_HIFI1 base pointer */
#define OSTIMER_HIFI1                            ((OSTIMER_Type *)OSTIMER_HIFI1_BASE)
/** Peripheral OSTIMER_HIFI4 base address */
#define OSTIMER_HIFI4_BASE                       (0x40208000u)
/** Peripheral OSTIMER_HIFI4 base pointer */
#define OSTIMER_HIFI4                            ((OSTIMER_Type *)OSTIMER_HIFI4_BASE)
/** Array initializer of OSTIMER peripheral base addresses */
#define OSTIMER_BASE_ADDRS                       { OSTIMER_CPU0_BASE, OSTIMER_CPU1_BASE, OSTIMER_HIFI1_BASE, OSTIMER_HIFI4_BASE }
/** Array initializer of OSTIMER peripheral base pointers */
#define OSTIMER_BASE_PTRS                        { OSTIMER_CPU0, OSTIMER_CPU1, OSTIMER_HIFI1, OSTIMER_HIFI4 }

/* PDM - Peripheral instance base addresses */
/** Peripheral PDM base address */
#define PDM_BASE                                 (0x4020E000u)
/** Peripheral PDM base pointer */
#define PDM                                      ((PDM_Type *)PDM_BASE)
/** Array initializer of PDM peripheral base addresses */
#define PDM_BASE_ADDRS                           { PDM_BASE }
/** Array initializer of PDM peripheral base pointers */
#define PDM_BASE_PTRS                            { PDM }

/* PINT - Peripheral instance base addresses */
/** Peripheral PINT0 base address */
#define PINT0_BASE                               (0x40025000u)
/** Peripheral PINT0 base pointer */
#define PINT0                                    ((PINT_Type *)PINT0_BASE)
/** Peripheral PINT1 base address */
#define PINT1_BASE                               (0x40045000u)
/** Peripheral PINT1 base pointer */
#define PINT1                                    ((PINT_Type *)PINT1_BASE)
/** Array initializer of PINT peripheral base addresses */
#define PINT_BASE_ADDRS                          { PINT0_BASE, PINT1_BASE }
/** Array initializer of PINT peripheral base pointers */
#define PINT_BASE_PTRS                           { PINT0, PINT1 }

/* PKC - Peripheral instance base addresses */
/** Peripheral PKC base address */
#define PKC_BASE                                 (0x40011000u)
/** Peripheral PKC base pointer */
#define PKC                                      ((PKC_Type *)PKC_BASE)
/** Array initializer of PKC peripheral base addresses */
#define PKC_BASE_ADDRS                           { PKC_BASE }
/** Array initializer of PKC peripheral base pointers */
#define PKC_BASE_PTRS                            { PKC }

/* PMC - Peripheral instance base addresses */
/** Peripheral PMC0 base address */
#define PMC0_BASE                                (0x4020F000u)
/** Peripheral PMC0 base pointer */
#define PMC0                                     ((PMC_Type *)PMC0_BASE)
/** Peripheral PMC1 base address */
#define PMC1_BASE                                (0x40210000u)
/** Peripheral PMC1 base pointer */
#define PMC1                                     ((PMC_Type *)PMC1_BASE)
/** Array initializer of PMC peripheral base addresses */
#define PMC_BASE_ADDRS                           { PMC0_BASE, PMC1_BASE }
/** Array initializer of PMC peripheral base pointers */
#define PMC_BASE_PTRS                            { PMC0, PMC1 }

/* PNGDEC - Peripheral instance base addresses */
/** Peripheral PNGDEC base address */
#define PNGDEC_BASE                              (0x400A7000u)
/** Peripheral PNGDEC base pointer */
#define PNGDEC                                   ((PNGDEC_Type *)PNGDEC_BASE)
/** Array initializer of PNGDEC peripheral base addresses */
#define PNGDEC_BASE_ADDRS                        { PNGDEC_BASE }
/** Array initializer of PNGDEC peripheral base pointers */
#define PNGDEC_BASE_PTRS                         { PNGDEC }

/* PUF - Peripheral instance base addresses */
/** Peripheral PUF base address */
#define PUF_BASE                                 (0x40194000u)
/** Peripheral PUF base pointer */
#define PUF                                      ((PUF_Type *)PUF_BASE)
/** Peripheral PUF_ALIAS1 base address */
#define PUF_ALIAS1_BASE                          (0x40195000u)
/** Peripheral PUF_ALIAS1 base pointer */
#define PUF_ALIAS1                               ((PUF_Type *)PUF_ALIAS1_BASE)
/** Peripheral PUF_ALIAS2 base address */
#define PUF_ALIAS2_BASE                          (0x40196000u)
/** Peripheral PUF_ALIAS2 base pointer */
#define PUF_ALIAS2                               ((PUF_Type *)PUF_ALIAS2_BASE)
/** Peripheral PUF_ALIAS3 base address */
#define PUF_ALIAS3_BASE                          (0x40197000u)
/** Peripheral PUF_ALIAS3 base pointer */
#define PUF_ALIAS3                               ((PUF_Type *)PUF_ALIAS3_BASE)
/** Array initializer of PUF peripheral base addresses */
#define PUF_BASE_ADDRS                           { PUF_BASE, PUF_ALIAS1_BASE, PUF_ALIAS2_BASE, PUF_ALIAS3_BASE }
/** Array initializer of PUF peripheral base pointers */
#define PUF_BASE_PTRS                            { PUF, PUF_ALIAS1, PUF_ALIAS2, PUF_ALIAS3 }

/* PVTS - Peripheral instance base addresses */
/** Peripheral PVTS0 base address */
#define PVTS0_BASE                               (0x40005000u)
/** Peripheral PVTS0 base pointer */
#define PVTS0                                    ((PVTS_Type *)PVTS0_BASE)
/** Peripheral PVTS1 base address */
#define PVTS1_BASE                               (0x40043000u)
/** Peripheral PVTS1 base pointer */
#define PVTS1                                    ((PVTS_Type *)PVTS1_BASE)
/** Array initializer of PVTS peripheral base addresses */
#define PVTS_BASE_ADDRS                          { PVTS0_BASE, PVTS1_BASE }
/** Array initializer of PVTS peripheral base pointers */
#define PVTS_BASE_PTRS                           { PVTS0, PVTS1 }

/* ROMCP - Peripheral instance base addresses */
/** Peripheral ROMCP base address */
#define ROMCP_BASE                               (0x40182000u)
/** Peripheral ROMCP base pointer */
#define ROMCP                                    ((ROMCP_Type *)ROMCP_BASE)
/** Array initializer of ROMCP peripheral base addresses */
#define ROMCP_BASE_ADDRS                         { ROMCP_BASE }
/** Array initializer of ROMCP peripheral base pointers */
#define ROMCP_BASE_PTRS                          { ROMCP }

/* RSTCTL0 - Peripheral instance base addresses */
/** Peripheral RSTCTL0 base address */
#define RSTCTL0_BASE                             (0x40000000u)
/** Peripheral RSTCTL0 base pointer */
#define RSTCTL0                                  ((RSTCTL0_Type *)RSTCTL0_BASE)
/** Array initializer of RSTCTL0 peripheral base addresses */
#define RSTCTL0_BASE_ADDRS                       { RSTCTL0_BASE }
/** Array initializer of RSTCTL0 peripheral base pointers */
#define RSTCTL0_BASE_PTRS                        { RSTCTL0 }

/* RSTCTL1 - Peripheral instance base addresses */
/** Peripheral RSTCTL1 base address */
#define RSTCTL1_BASE                             (0x40040000u)
/** Peripheral RSTCTL1 base pointer */
#define RSTCTL1                                  ((RSTCTL1_Type *)RSTCTL1_BASE)
/** Array initializer of RSTCTL1 peripheral base addresses */
#define RSTCTL1_BASE_ADDRS                       { RSTCTL1_BASE }
/** Array initializer of RSTCTL1 peripheral base pointers */
#define RSTCTL1_BASE_PTRS                        { RSTCTL1 }

/* RSTCTL2 - Peripheral instance base addresses */
/** Peripheral RSTCTL2 base address */
#define RSTCTL2_BASE                             (0x40067000u)
/** Peripheral RSTCTL2 base pointer */
#define RSTCTL2                                  ((RSTCTL2_Type *)RSTCTL2_BASE)
/** Array initializer of RSTCTL2 peripheral base addresses */
#define RSTCTL2_BASE_ADDRS                       { RSTCTL2_BASE }
/** Array initializer of RSTCTL2 peripheral base pointers */
#define RSTCTL2_BASE_PTRS                        { RSTCTL2 }

/* RSTCTL3 - Peripheral instance base addresses */
/** Peripheral RSTCTL3 base address */
#define RSTCTL3_BASE                             (0x40060000u)
/** Peripheral RSTCTL3 base pointer */
#define RSTCTL3                                  ((RSTCTL3_Type *)RSTCTL3_BASE)
/** Array initializer of RSTCTL3 peripheral base addresses */
#define RSTCTL3_BASE_ADDRS                       { RSTCTL3_BASE }
/** Array initializer of RSTCTL3 peripheral base pointers */
#define RSTCTL3_BASE_PTRS                        { RSTCTL3 }

/* RSTCTL4 - Peripheral instance base addresses */
/** Peripheral RSTCTL4 base address */
#define RSTCTL4_BASE                             (0x400A0000u)
/** Peripheral RSTCTL4 base pointer */
#define RSTCTL4                                  ((RSTCTL4_Type *)RSTCTL4_BASE)
/** Array initializer of RSTCTL4 peripheral base addresses */
#define RSTCTL4_BASE_ADDRS                       { RSTCTL4_BASE }
/** Array initializer of RSTCTL4 peripheral base pointers */
#define RSTCTL4_BASE_PTRS                        { RSTCTL4 }

/* RTC - Peripheral instance base addresses */
/** Peripheral RTC1 base address */
#define RTC1_BASE                                (0x40069000u)
/** Peripheral RTC1 base pointer */
#define RTC1                                     ((RTC_Type *)RTC1_BASE)
/** Array initializer of RTC peripheral base addresses */
#define RTC_BASE_ADDRS                           { RTC1_BASE }
/** Array initializer of RTC peripheral base pointers */
#define RTC_BASE_PTRS                            { RTC1 }

/* SCT - Peripheral instance base addresses */
/** Peripheral SCT0 base address */
#define SCT0_BASE                                (0x40114000u)
/** Peripheral SCT0 base pointer */
#define SCT0                                     ((SCT_Type *)SCT0_BASE)
/** Array initializer of SCT peripheral base addresses */
#define SCT_BASE_ADDRS                           { SCT0_BASE }
/** Array initializer of SCT peripheral base pointers */
#define SCT_BASE_PTRS                            { SCT0 }

/* SDADC - Peripheral instance base addresses */
/** Peripheral SDADC base address */
#define SDADC_BASE                               (0x4020D000u)
/** Peripheral SDADC base pointer */
#define SDADC                                    ((SDADC_Type *)SDADC_BASE)
/** Array initializer of SDADC peripheral base addresses */
#define SDADC_BASE_ADDRS                         { SDADC_BASE }
/** Array initializer of SDADC peripheral base pointers */
#define SDADC_BASE_PTRS                          { SDADC }

/* SEMA42 - Peripheral instance base addresses */
/** Peripheral SEMA42_0 base address */
#define SEMA42_0_BASE                            (0x40206000u)
/** Peripheral SEMA42_0 base pointer */
#define SEMA42_0                                 ((SEMA42_Type *)SEMA42_0_BASE)
/** Peripheral SEMA42_3 base address */
#define SEMA42_3_BASE                            (0x4031B000u)
/** Peripheral SEMA42_3 base pointer */
#define SEMA42_3                                 ((SEMA42_Type *)SEMA42_3_BASE)
/** Peripheral SEMA42_4 base address */
#define SEMA42_4_BASE                            (0x4018A000u)
/** Peripheral SEMA42_4 base pointer */
#define SEMA42_4                                 ((SEMA42_Type *)SEMA42_4_BASE)
/** Array initializer of SEMA42 peripheral base addresses */
#define SEMA42_BASE_ADDRS                        { SEMA42_0_BASE, 0u, 0u, SEMA42_3_BASE, SEMA42_4_BASE }
/** Array initializer of SEMA42 peripheral base pointers */
#define SEMA42_BASE_PTRS                         { SEMA42_0, (SEMA42_Type *)0u, (SEMA42_Type *)0u, SEMA42_3, SEMA42_4 }

/* SLEEPCON0 - Peripheral instance base addresses */
/** Peripheral SLEEPCON0 base address */
#define SLEEPCON0_BASE                           (0x40003000u)
/** Peripheral SLEEPCON0 base pointer */
#define SLEEPCON0                                ((SLEEPCON0_Type *)SLEEPCON0_BASE)
/** Array initializer of SLEEPCON0 peripheral base addresses */
#define SLEEPCON0_BASE_ADDRS                     { SLEEPCON0_BASE }
/** Array initializer of SLEEPCON0 peripheral base pointers */
#define SLEEPCON0_BASE_PTRS                      { SLEEPCON0 }

/* SLEEPCON1 - Peripheral instance base addresses */
/** Peripheral SLEEPCON1 base address */
#define SLEEPCON1_BASE                           (0x40044000u)
/** Peripheral SLEEPCON1 base pointer */
#define SLEEPCON1                                ((SLEEPCON1_Type *)SLEEPCON1_BASE)
/** Array initializer of SLEEPCON1 peripheral base addresses */
#define SLEEPCON1_BASE_ADDRS                     { SLEEPCON1_BASE }
/** Array initializer of SLEEPCON1 peripheral base pointers */
#define SLEEPCON1_BASE_PTRS                      { SLEEPCON1 }

/* SYSCON0 - Peripheral instance base addresses */
/** Peripheral SYSCON0 base address */
#define SYSCON0_BASE                             (0x40002000u)
/** Peripheral SYSCON0 base pointer */
#define SYSCON0                                  ((SYSCON0_Type *)SYSCON0_BASE)
/** Array initializer of SYSCON0 peripheral base addresses */
#define SYSCON0_BASE_ADDRS                       { SYSCON0_BASE }
/** Array initializer of SYSCON0 peripheral base pointers */
#define SYSCON0_BASE_PTRS                        { SYSCON0 }

/* SYSCON1 - Peripheral instance base addresses */
/** Peripheral SYSCON1 base address */
#define SYSCON1_BASE                             (0x40042000u)
/** Peripheral SYSCON1 base pointer */
#define SYSCON1                                  ((SYSCON1_Type *)SYSCON1_BASE)
/** Array initializer of SYSCON1 peripheral base addresses */
#define SYSCON1_BASE_ADDRS                       { SYSCON1_BASE }
/** Array initializer of SYSCON1 peripheral base pointers */
#define SYSCON1_BASE_PTRS                        { SYSCON1 }

/* SYSCON2 - Peripheral instance base addresses */
/** Peripheral SYSCON2 base address */
#define SYSCON2_BASE                             (0x40066000u)
/** Peripheral SYSCON2 base pointer */
#define SYSCON2                                  ((SYSCON2_Type *)SYSCON2_BASE)
/** Array initializer of SYSCON2 peripheral base addresses */
#define SYSCON2_BASE_ADDRS                       { SYSCON2_BASE }
/** Array initializer of SYSCON2 peripheral base pointers */
#define SYSCON2_BASE_PTRS                        { SYSCON2 }

/* SYSCON3 - Peripheral instance base addresses */
/** Peripheral SYSCON3 base address */
#define SYSCON3_BASE                             (0x40062000u)
/** Peripheral SYSCON3 base pointer */
#define SYSCON3                                  ((SYSCON3_Type *)SYSCON3_BASE)
/** Array initializer of SYSCON3 peripheral base addresses */
#define SYSCON3_BASE_ADDRS                       { SYSCON3_BASE }
/** Array initializer of SYSCON3 peripheral base pointers */
#define SYSCON3_BASE_PTRS                        { SYSCON3 }

/* SYSCON4 - Peripheral instance base addresses */
/** Peripheral SYSCON4 base address */
#define SYSCON4_BASE                             (0x400A2000u)
/** Peripheral SYSCON4 base pointer */
#define SYSCON4                                  ((SYSCON4_Type *)SYSCON4_BASE)
/** Array initializer of SYSCON4 peripheral base addresses */
#define SYSCON4_BASE_ADDRS                       { SYSCON4_BASE }
/** Array initializer of SYSCON4 peripheral base pointers */
#define SYSCON4_BASE_PTRS                        { SYSCON4 }

/* SYSPM - Peripheral instance base addresses */
/** Peripheral CMX_PERFMON0 base address */
#define CMX_PERFMON0_BASE                        (0x4018C000u)
/** Peripheral CMX_PERFMON0 base pointer */
#define CMX_PERFMON0                             ((SYSPM_Type *)CMX_PERFMON0_BASE)
/** Peripheral CMX_PERFMON1 base address */
#define CMX_PERFMON1_BASE                        (0x4018D000u)
/** Peripheral CMX_PERFMON1 base pointer */
#define CMX_PERFMON1                             ((SYSPM_Type *)CMX_PERFMON1_BASE)
/** Peripheral CMX_PERFMON2 base address */
#define CMX_PERFMON2_BASE                        (0x4018E000u)
/** Peripheral CMX_PERFMON2 base pointer */
#define CMX_PERFMON2                             ((SYSPM_Type *)CMX_PERFMON2_BASE)
/** Peripheral CMX_PERFMON3 base address */
#define CMX_PERFMON3_BASE                        (0x4018F000u)
/** Peripheral CMX_PERFMON3 base pointer */
#define CMX_PERFMON3                             ((SYSPM_Type *)CMX_PERFMON3_BASE)
/** Array initializer of SYSPM peripheral base addresses */
#define SYSPM_BASE_ADDRS                         { CMX_PERFMON0_BASE, CMX_PERFMON1_BASE, CMX_PERFMON2_BASE, CMX_PERFMON3_BASE }
/** Array initializer of SYSPM peripheral base pointers */
#define SYSPM_BASE_PTRS                          { CMX_PERFMON0, CMX_PERFMON1, CMX_PERFMON2, CMX_PERFMON3 }

/* TRNG - Peripheral instance base addresses */
/** Peripheral TRNG base address */
#define TRNG_BASE                                (0x40187000u)
/** Peripheral TRNG base pointer */
#define TRNG                                     ((TRNG_Type *)TRNG_BASE)
/** Array initializer of TRNG peripheral base addresses */
#define TRNG_BASE_ADDRS                          { TRNG_BASE }
/** Array initializer of TRNG peripheral base pointers */
#define TRNG_BASE_PTRS                           { TRNG }
/* Backward compatibility */
#define TRNG0                                    TRNG


/* USB - Peripheral instance base addresses */
/** Peripheral USB0 base address */
#define USB0_BASE                                (0x40418000u)
/** Peripheral USB0 base pointer */
#define USB0                                     ((USB_Type *)USB0_BASE)
/** Peripheral USB1 base address */
#define USB1_BASE                                (0x40419000u)
/** Peripheral USB1 base pointer */
#define USB1                                     ((USB_Type *)USB1_BASE)
/** Array initializer of USB peripheral base addresses */
#define USB_BASE_ADDRS                           { USB0_BASE, USB1_BASE }
/** Array initializer of USB peripheral base pointers */
#define USB_BASE_PTRS                            { USB0, USB1 }
/* Backward compatibility */
#define GPTIMER0CTL                              GPTIMER0CTRL
#define GPTIMER1CTL                              GPTIMER1CTRL
#define USB_SBUSCFG                              SBUSCFG
#define EPLISTADDR                               ENDPTLISTADDR
#define EPSETUPSR                                ENDPTSETUPSTAT
#define EPPRIME                                  ENDPTPRIME
#define EPFLUSH                                  ENDPTFLUSH
#define EPSR                                     ENDPTSTAT
#define EPCOMPLETE                               ENDPTCOMPLETE
#define EPCR                                     ENDPTCTRL
#define EPCR0                                    ENDPTCTRL0
#define USBHS_ID_ID_MASK                         USB_ID_ID_MASK
#define USBHS_ID_ID_SHIFT                        USB_ID_ID_SHIFT
#define USBHS_ID_ID(x)                           USB_ID_ID(x)
#define USBHS_ID_NID_MASK                        USB_ID_NID_MASK
#define USBHS_ID_NID_SHIFT                       USB_ID_NID_SHIFT
#define USBHS_ID_NID(x)                          USB_ID_NID(x)
#define USBHS_ID_REVISION_MASK                   USB_ID_REVISION_MASK
#define USBHS_ID_REVISION_SHIFT                  USB_ID_REVISION_SHIFT
#define USBHS_ID_REVISION(x)                     USB_ID_REVISION(x)
#define USBHS_HWGENERAL_PHYW_MASK                USB_HWGENERAL_PHYW_MASK
#define USBHS_HWGENERAL_PHYW_SHIFT               USB_HWGENERAL_PHYW_SHIFT
#define USBHS_HWGENERAL_PHYW(x)                  USB_HWGENERAL_PHYW(x)
#define USBHS_HWGENERAL_PHYM_MASK                USB_HWGENERAL_PHYM_MASK
#define USBHS_HWGENERAL_PHYM_SHIFT               USB_HWGENERAL_PHYM_SHIFT
#define USBHS_HWGENERAL_PHYM(x)                  USB_HWGENERAL_PHYM(x)
#define USBHS_HWGENERAL_SM_MASK                  USB_HWGENERAL_SM_MASK
#define USBHS_HWGENERAL_SM_SHIFT                 USB_HWGENERAL_SM_SHIFT
#define USBHS_HWGENERAL_SM(x)                    USB_HWGENERAL_SM(x)
#define USBHS_HWHOST_HC_MASK                     USB_HWHOST_HC_MASK
#define USBHS_HWHOST_HC_SHIFT                    USB_HWHOST_HC_SHIFT
#define USBHS_HWHOST_HC(x)                       USB_HWHOST_HC(x)
#define USBHS_HWHOST_NPORT_MASK                  USB_HWHOST_NPORT_MASK
#define USBHS_HWHOST_NPORT_SHIFT                 USB_HWHOST_NPORT_SHIFT
#define USBHS_HWHOST_NPORT(x)                    USB_HWHOST_NPORT(x)
#define USBHS_HWDEVICE_DC_MASK                   USB_HWDEVICE_DC_MASK
#define USBHS_HWDEVICE_DC_SHIFT                  USB_HWDEVICE_DC_SHIFT
#define USBHS_HWDEVICE_DC(x)                     USB_HWDEVICE_DC(x)
#define USBHS_HWDEVICE_DEVEP_MASK                USB_HWDEVICE_DEVEP_MASK
#define USBHS_HWDEVICE_DEVEP_SHIFT               USB_HWDEVICE_DEVEP_SHIFT
#define USBHS_HWDEVICE_DEVEP(x)                  USB_HWDEVICE_DEVEP(x)
#define USBHS_HWTXBUF_TXBURST_MASK               USB_HWTXBUF_TXBURST_MASK
#define USBHS_HWTXBUF_TXBURST_SHIFT              USB_HWTXBUF_TXBURST_SHIFT
#define USBHS_HWTXBUF_TXBURST(x)                 USB_HWTXBUF_TXBURST(x)
#define USBHS_HWTXBUF_TXCHANADD_MASK             USB_HWTXBUF_TXCHANADD_MASK
#define USBHS_HWTXBUF_TXCHANADD_SHIFT            USB_HWTXBUF_TXCHANADD_SHIFT
#define USBHS_HWTXBUF_TXCHANADD(x)               USB_HWTXBUF_TXCHANADD(x)
#define USBHS_HWRXBUF_RXBURST_MASK               USB_HWRXBUF_RXBURST_MASK
#define USBHS_HWRXBUF_RXBURST_SHIFT              USB_HWRXBUF_RXBURST_SHIFT
#define USBHS_HWRXBUF_RXBURST(x)                 USB_HWRXBUF_RXBURST(x)
#define USBHS_HWRXBUF_RXADD_MASK                 USB_HWRXBUF_RXADD_MASK
#define USBHS_HWRXBUF_RXADD_SHIFT                USB_HWRXBUF_RXADD_SHIFT
#define USBHS_HWRXBUF_RXADD(x)                   USB_HWRXBUF_RXADD(x)
#define USBHS_GPTIMER0LD_GPTLD_MASK              USB_GPTIMER0LD_GPTLD_MASK
#define USBHS_GPTIMER0LD_GPTLD_SHIFT             USB_GPTIMER0LD_GPTLD_SHIFT
#define USBHS_GPTIMER0LD_GPTLD(x)                USB_GPTIMER0LD_GPTLD(x)
#define USBHS_GPTIMER0CTL_GPTCNT_MASK            USB_GPTIMER0CTRL_GPTCNT_MASK
#define USBHS_GPTIMER0CTL_GPTCNT_SHIFT           USB_GPTIMER0CTRL_GPTCNT_SHIFT
#define USBHS_GPTIMER0CTL_GPTCNT(x)              USB_GPTIMER0CTRL_GPTCNT(x)
#define USBHS_GPTIMER0CTL_MODE_MASK              USB_GPTIMER0CTRL_GPTMODE_MASK
#define USBHS_GPTIMER0CTL_MODE_SHIFT             USB_GPTIMER0CTRL_GPTMODE_SHIFT
#define USBHS_GPTIMER0CTL_MODE(x)                USB_GPTIMER0CTRL_GPTMODE(x)
#define USBHS_GPTIMER0CTL_RST_MASK               USB_GPTIMER0CTRL_GPTRST_MASK
#define USBHS_GPTIMER0CTL_RST_SHIFT              USB_GPTIMER0CTRL_GPTRST_SHIFT
#define USBHS_GPTIMER0CTL_RST(x)                 USB_GPTIMER0CTRL_GPTRST(x)
#define USBHS_GPTIMER0CTL_RUN_MASK               USB_GPTIMER0CTRL_GPTRUN_MASK
#define USBHS_GPTIMER0CTL_RUN_SHIFT              USB_GPTIMER0CTRL_GPTRUN_SHIFT
#define USBHS_GPTIMER0CTL_RUN(x)                 USB_GPTIMER0CTRL_GPTRUN(x)
#define USBHS_GPTIMER1LD_GPTLD_MASK              USB_GPTIMER1LD_GPTLD_MASK
#define USBHS_GPTIMER1LD_GPTLD_SHIFT             USB_GPTIMER1LD_GPTLD_SHIFT
#define USBHS_GPTIMER1LD_GPTLD(x)                USB_GPTIMER1LD_GPTLD(x)
#define USBHS_GPTIMER1CTL_GPTCNT_MASK            USB_GPTIMER1CTRL_GPTCNT_MASK
#define USBHS_GPTIMER1CTL_GPTCNT_SHIFT           USB_GPTIMER1CTRL_GPTCNT_SHIFT
#define USBHS_GPTIMER1CTL_GPTCNT(x)              USB_GPTIMER1CTRL_GPTCNT(x)
#define USBHS_GPTIMER1CTL_MODE_MASK              USB_GPTIMER1CTRL_GPTMODE_MASK
#define USBHS_GPTIMER1CTL_MODE_SHIFT             USB_GPTIMER1CTRL_GPTMODE_SHIFT
#define USBHS_GPTIMER1CTL_MODE(x)                USB_GPTIMER1CTRL_GPTMODE(x)
#define USBHS_GPTIMER1CTL_RST_MASK               USB_GPTIMER1CTRL_GPTRST_MASK
#define USBHS_GPTIMER1CTL_RST_SHIFT              USB_GPTIMER1CTRL_GPTRST_SHIFT
#define USBHS_GPTIMER1CTL_RST(x)                 USB_GPTIMER1CTRL_GPTRST(x)
#define USBHS_GPTIMER1CTL_RUN_MASK               USB_GPTIMER1CTRL_GPTRUN_MASK
#define USBHS_GPTIMER1CTL_RUN_SHIFT              USB_GPTIMER1CTRL_GPTRUN_SHIFT
#define USBHS_GPTIMER1CTL_RUN(x)                 USB_GPTIMER1CTRL_GPTRUN(x)
#define USBHS_USB_SBUSCFG_BURSTMODE_MASK         USB_SBUSCFG_AHBBRST_MASK
#define USBHS_USB_SBUSCFG_BURSTMODE_SHIFT        USB_SBUSCFG_AHBBRST_SHIFT
#define USBHS_USB_SBUSCFG_BURSTMODE(x)           USB_SBUSCFG_AHBBRST(x)
#define USBHS_HCIVERSION_CAPLENGTH(x)            USB_HCIVERSION_CAPLENGTH(x)
#define USBHS_HCIVERSION_HCIVERSION_MASK         USB_HCIVERSION_HCIVERSION_MASK
#define USBHS_HCIVERSION_HCIVERSION_SHIFT        USB_HCIVERSION_HCIVERSION_SHIFT
#define USBHS_HCIVERSION_HCIVERSION(x)           USB_HCIVERSION_HCIVERSION(x)
#define USBHS_HCSPARAMS_N_PORTS_MASK             USB_HCSPARAMS_N_PORTS_MASK
#define USBHS_HCSPARAMS_N_PORTS_SHIFT            USB_HCSPARAMS_N_PORTS_SHIFT
#define USBHS_HCSPARAMS_N_PORTS(x)               USB_HCSPARAMS_N_PORTS(x)
#define USBHS_HCSPARAMS_PPC_MASK                 USB_HCSPARAMS_PPC_MASK
#define USBHS_HCSPARAMS_PPC_SHIFT                USB_HCSPARAMS_PPC_SHIFT
#define USBHS_HCSPARAMS_PPC(x)                   USB_HCSPARAMS_PPC(x)
#define USBHS_HCSPARAMS_N_PCC_MASK               USB_HCSPARAMS_N_PCC_MASK
#define USBHS_HCSPARAMS_N_PCC_SHIFT              USB_HCSPARAMS_N_PCC_SHIFT
#define USBHS_HCSPARAMS_N_PCC(x)                 USB_HCSPARAMS_N_PCC(x)
#define USBHS_HCSPARAMS_N_CC_MASK                USB_HCSPARAMS_N_CC_MASK
#define USBHS_HCSPARAMS_N_CC_SHIFT               USB_HCSPARAMS_N_CC_SHIFT
#define USBHS_HCSPARAMS_N_CC(x)                  USB_HCSPARAMS_N_CC(x)
#define USBHS_HCSPARAMS_PI_MASK                  USB_HCSPARAMS_PI_MASK
#define USBHS_HCSPARAMS_PI_SHIFT                 USB_HCSPARAMS_PI_SHIFT
#define USBHS_HCSPARAMS_PI(x)                    USB_HCSPARAMS_PI(x)
#define USBHS_HCSPARAMS_N_PTT_MASK               USB_HCSPARAMS_N_PTT_MASK
#define USBHS_HCSPARAMS_N_PTT_SHIFT              USB_HCSPARAMS_N_PTT_SHIFT
#define USBHS_HCSPARAMS_N_PTT(x)                 USB_HCSPARAMS_N_PTT(x)
#define USBHS_HCSPARAMS_N_TT_MASK                USB_HCSPARAMS_N_TT_MASK
#define USBHS_HCSPARAMS_N_TT_SHIFT               USB_HCSPARAMS_N_TT_SHIFT
#define USBHS_HCSPARAMS_N_TT(x)                  USB_HCSPARAMS_N_TT(x)
#define USBHS_HCCPARAMS_ADC_MASK                 USB_HCCPARAMS_ADC_MASK
#define USBHS_HCCPARAMS_ADC_SHIFT                USB_HCCPARAMS_ADC_SHIFT
#define USBHS_HCCPARAMS_ADC(x)                   USB_HCCPARAMS_ADC(x)
#define USBHS_HCCPARAMS_PFL_MASK                 USB_HCCPARAMS_PFL_MASK
#define USBHS_HCCPARAMS_PFL_SHIFT                USB_HCCPARAMS_PFL_SHIFT
#define USBHS_HCCPARAMS_PFL(x)                   USB_HCCPARAMS_PFL(x)
#define USBHS_HCCPARAMS_ASP_MASK                 USB_HCCPARAMS_ASP_MASK
#define USBHS_HCCPARAMS_ASP_SHIFT                USB_HCCPARAMS_ASP_SHIFT
#define USBHS_HCCPARAMS_ASP(x)                   USB_HCCPARAMS_ASP(x)
#define USBHS_HCCPARAMS_IST_MASK                 USB_HCCPARAMS_IST_MASK
#define USBHS_HCCPARAMS_IST_SHIFT                USB_HCCPARAMS_IST_SHIFT
#define USBHS_HCCPARAMS_IST(x)                   USB_HCCPARAMS_IST(x)
#define USBHS_HCCPARAMS_EECP_MASK                USB_HCCPARAMS_EECP_MASK
#define USBHS_HCCPARAMS_EECP_SHIFT               USB_HCCPARAMS_EECP_SHIFT
#define USBHS_HCCPARAMS_EECP(x)                  USB_HCCPARAMS_EECP(x)
#define USBHS_DCIVERSION_DCIVERSION_MASK         USB_DCIVERSION_DCIVERSION_MASK
#define USBHS_DCIVERSION_DCIVERSION_SHIFT        USB_DCIVERSION_DCIVERSION_SHIFT
#define USBHS_DCIVERSION_DCIVERSION(x)           USB_DCIVERSION_DCIVERSION(x)
#define USBHS_DCCPARAMS_DEN_MASK                 USB_DCCPARAMS_DEN_MASK
#define USBHS_DCCPARAMS_DEN_SHIFT                USB_DCCPARAMS_DEN_SHIFT
#define USBHS_DCCPARAMS_DEN(x)                   USB_DCCPARAMS_DEN(x)
#define USBHS_DCCPARAMS_DC_MASK                  USB_DCCPARAMS_DC_MASK
#define USBHS_DCCPARAMS_DC_SHIFT                 USB_DCCPARAMS_DC_SHIFT
#define USBHS_DCCPARAMS_DC(x)                    USB_DCCPARAMS_DC(x)
#define USBHS_DCCPARAMS_HC_MASK                  USB_DCCPARAMS_HC_MASK
#define USBHS_DCCPARAMS_HC_SHIFT                 USB_DCCPARAMS_HC_SHIFT
#define USBHS_DCCPARAMS_HC(x)                    USB_DCCPARAMS_HC(x)
#define USBHS_USBCMD_RS_MASK                     USB_USBCMD_RS_MASK
#define USBHS_USBCMD_RS_SHIFT                    USB_USBCMD_RS_SHIFT
#define USBHS_USBCMD_RS(x)                       USB_USBCMD_RS(x)
#define USBHS_USBCMD_RST_MASK                    USB_USBCMD_RST_MASK
#define USBHS_USBCMD_RST_SHIFT                   USB_USBCMD_RST_SHIFT
#define USBHS_USBCMD_RST(x)                      USB_USBCMD_RST(x)
#define USBHS_USBCMD_FS_MASK                     USB_USBCMD_FS_1_MASK
#define USBHS_USBCMD_FS_SHIFT                    USB_USBCMD_FS_1_SHIFT
#define USBHS_USBCMD_FS(x)                       USB_USBCMD_FS_1(x)
#define USBHS_USBCMD_PSE_MASK                    USB_USBCMD_PSE_MASK
#define USBHS_USBCMD_PSE_SHIFT                   USB_USBCMD_PSE_SHIFT
#define USBHS_USBCMD_PSE(x)                      USB_USBCMD_PSE(x)
#define USBHS_USBCMD_ASE_MASK                    USB_USBCMD_ASE_MASK
#define USBHS_USBCMD_ASE_SHIFT                   USB_USBCMD_ASE_SHIFT
#define USBHS_USBCMD_ASE(x)                      USB_USBCMD_ASE(x)
#define USBHS_USBCMD_IAA_MASK                    USB_USBCMD_IAA_MASK
#define USBHS_USBCMD_IAA_SHIFT                   USB_USBCMD_IAA_SHIFT
#define USBHS_USBCMD_IAA(x)                      USB_USBCMD_IAA(x)
#define USBHS_USBCMD_ASP_MASK                    USB_USBCMD_ASP_MASK
#define USBHS_USBCMD_ASP_SHIFT                   USB_USBCMD_ASP_SHIFT
#define USBHS_USBCMD_ASP(x)                      USB_USBCMD_ASP(x)
#define USBHS_USBCMD_ASPE_MASK                   USB_USBCMD_ASPE_MASK
#define USBHS_USBCMD_ASPE_SHIFT                  USB_USBCMD_ASPE_SHIFT
#define USBHS_USBCMD_ASPE(x)                     USB_USBCMD_ASPE(x)
#define USBHS_USBCMD_ATDTW_MASK                  USB_USBCMD_ATDTW_MASK
#define USBHS_USBCMD_ATDTW_SHIFT                 USB_USBCMD_ATDTW_SHIFT
#define USBHS_USBCMD_ATDTW(x)                    USB_USBCMD_ATDTW(x)
#define USBHS_USBCMD_SUTW_MASK                   USB_USBCMD_SUTW_MASK
#define USBHS_USBCMD_SUTW_SHIFT                  USB_USBCMD_SUTW_SHIFT
#define USBHS_USBCMD_SUTW(x)                     USB_USBCMD_SUTW(x)
#define USBHS_USBCMD_FS2_MASK                    USB_USBCMD_FS_2_MASK
#define USBHS_USBCMD_FS2_SHIFT                   USB_USBCMD_FS_2_SHIFT
#define USBHS_USBCMD_FS2(x)                      USB_USBCMD_FS_2(x)
#define USBHS_USBCMD_ITC_MASK                    USB_USBCMD_ITC_MASK
#define USBHS_USBCMD_ITC_SHIFT                   USB_USBCMD_ITC_SHIFT
#define USBHS_USBCMD_ITC(x)                      USB_USBCMD_ITC(x)
#define USBHS_USBSTS_UI_MASK                     USB_USBSTS_UI_MASK
#define USBHS_USBSTS_UI_SHIFT                    USB_USBSTS_UI_SHIFT
#define USBHS_USBSTS_UI(x)                       USB_USBSTS_UI(x)
#define USBHS_USBSTS_UEI_MASK                    USB_USBSTS_UEI_MASK
#define USBHS_USBSTS_UEI_SHIFT                   USB_USBSTS_UEI_SHIFT
#define USBHS_USBSTS_UEI(x)                      USB_USBSTS_UEI(x)
#define USBHS_USBSTS_PCI_MASK                    USB_USBSTS_PCI_MASK
#define USBHS_USBSTS_PCI_SHIFT                   USB_USBSTS_PCI_SHIFT
#define USBHS_USBSTS_PCI(x)                      USB_USBSTS_PCI(x)
#define USBHS_USBSTS_FRI_MASK                    USB_USBSTS_FRI_MASK
#define USBHS_USBSTS_FRI_SHIFT                   USB_USBSTS_FRI_SHIFT
#define USBHS_USBSTS_FRI(x)                      USB_USBSTS_FRI(x)
#define USBHS_USBSTS_SEI_MASK                    USB_USBSTS_SEI_MASK
#define USBHS_USBSTS_SEI_SHIFT                   USB_USBSTS_SEI_SHIFT
#define USBHS_USBSTS_SEI(x)                      USB_USBSTS_SEI(x)
#define USBHS_USBSTS_AAI_MASK                    USB_USBSTS_AAI_MASK
#define USBHS_USBSTS_AAI_SHIFT                   USB_USBSTS_AAI_SHIFT
#define USBHS_USBSTS_AAI(x)                      USB_USBSTS_AAI(x)
#define USBHS_USBSTS_URI_MASK                    USB_USBSTS_URI_MASK
#define USBHS_USBSTS_URI_SHIFT                   USB_USBSTS_URI_SHIFT
#define USBHS_USBSTS_URI(x)                      USB_USBSTS_URI(x)
#define USBHS_USBSTS_SRI_MASK                    USB_USBSTS_SRI_MASK
#define USBHS_USBSTS_SRI_SHIFT                   USB_USBSTS_SRI_SHIFT
#define USBHS_USBSTS_SRI(x)                      USB_USBSTS_SRI(x)
#define USBHS_USBSTS_SLI_MASK                    USB_USBSTS_SLI_MASK
#define USBHS_USBSTS_SLI_SHIFT                   USB_USBSTS_SLI_SHIFT
#define USBHS_USBSTS_SLI(x)                      USB_USBSTS_SLI(x)
#define USBHS_USBSTS_ULPII_MASK                  USB_USBSTS_ULPII_MASK
#define USBHS_USBSTS_ULPII_SHIFT                 USB_USBSTS_ULPII_SHIFT
#define USBHS_USBSTS_ULPII(x)                    USB_USBSTS_ULPII(x)
#define USBHS_USBSTS_HCH_MASK                    USB_USBSTS_HCH_MASK
#define USBHS_USBSTS_HCH_SHIFT                   USB_USBSTS_HCH_SHIFT
#define USBHS_USBSTS_HCH(x)                      USB_USBSTS_HCH(x)
#define USBHS_USBSTS_RCL_MASK                    USB_USBSTS_RCL_MASK
#define USBHS_USBSTS_RCL_SHIFT                   USB_USBSTS_RCL_SHIFT
#define USBHS_USBSTS_RCL(x)                      USB_USBSTS_RCL(x)
#define USBHS_USBSTS_PS_MASK                     USB_USBSTS_PS_MASK
#define USBHS_USBSTS_PS_SHIFT                    USB_USBSTS_PS_SHIFT
#define USBHS_USBSTS_PS(x)                       USB_USBSTS_PS(x)
#define USBHS_USBSTS_AS_MASK                     USB_USBSTS_AS_MASK
#define USBHS_USBSTS_AS_SHIFT                    USB_USBSTS_AS_SHIFT
#define USBHS_USBSTS_AS(x)                       USB_USBSTS_AS(x)
#define USBHS_USBSTS_NAKI_MASK                   USB_USBSTS_NAKI_MASK
#define USBHS_USBSTS_NAKI_SHIFT                  USB_USBSTS_NAKI_SHIFT
#define USBHS_USBSTS_NAKI(x)                     USB_USBSTS_NAKI(x)
#define USBHS_USBSTS_TI0_MASK                    USB_USBSTS_TI0_MASK
#define USBHS_USBSTS_TI0_SHIFT                   USB_USBSTS_TI0_SHIFT
#define USBHS_USBSTS_TI0(x)                      USB_USBSTS_TI0(x)
#define USBHS_USBSTS_TI1_MASK                    USB_USBSTS_TI1_MASK
#define USBHS_USBSTS_TI1_SHIFT                   USB_USBSTS_TI1_SHIFT
#define USBHS_USBSTS_TI1(x)                      USB_USBSTS_TI1(x)
#define USBHS_USBINTR_UE_MASK                    USB_USBINTR_UE_MASK
#define USBHS_USBINTR_UE_SHIFT                   USB_USBINTR_UE_SHIFT
#define USBHS_USBINTR_UE(x)                      USB_USBINTR_UE(x)
#define USBHS_USBINTR_UEE_MASK                   USB_USBINTR_UEE_MASK
#define USBHS_USBINTR_UEE_SHIFT                  USB_USBINTR_UEE_SHIFT
#define USBHS_USBINTR_UEE(x)                     USB_USBINTR_UEE(x)
#define USBHS_USBINTR_PCE_MASK                   USB_USBINTR_PCE_MASK
#define USBHS_USBINTR_PCE_SHIFT                  USB_USBINTR_PCE_SHIFT
#define USBHS_USBINTR_PCE(x)                     USB_USBINTR_PCE(x)
#define USBHS_USBINTR_FRE_MASK                   USB_USBINTR_FRE_MASK
#define USBHS_USBINTR_FRE_SHIFT                  USB_USBINTR_FRE_SHIFT
#define USBHS_USBINTR_FRE(x)                     USB_USBINTR_FRE(x)
#define USBHS_USBINTR_SEE_MASK                   USB_USBINTR_SEE_MASK
#define USBHS_USBINTR_SEE_SHIFT                  USB_USBINTR_SEE_SHIFT
#define USBHS_USBINTR_SEE(x)                     USB_USBINTR_SEE(x)
#define USBHS_USBINTR_AAE_MASK                   USB_USBINTR_AAE_MASK
#define USBHS_USBINTR_AAE_SHIFT                  USB_USBINTR_AAE_SHIFT
#define USBHS_USBINTR_AAE(x)                     USB_USBINTR_AAE(x)
#define USBHS_USBINTR_URE_MASK                   USB_USBINTR_URE_MASK
#define USBHS_USBINTR_URE_SHIFT                  USB_USBINTR_URE_SHIFT
#define USBHS_USBINTR_URE(x)                     USB_USBINTR_URE(x)
#define USBHS_USBINTR_SRE_MASK                   USB_USBINTR_SRE_MASK
#define USBHS_USBINTR_SRE_SHIFT                  USB_USBINTR_SRE_SHIFT
#define USBHS_USBINTR_SRE(x)                     USB_USBINTR_SRE(x)
#define USBHS_USBINTR_SLE_MASK                   USB_USBINTR_SLE_MASK
#define USBHS_USBINTR_SLE_SHIFT                  USB_USBINTR_SLE_SHIFT
#define USBHS_USBINTR_SLE(x)                     USB_USBINTR_SLE(x)
#define USBHS_USBINTR_ULPIE_MASK                 USB_USBINTR_ULPIE_MASK
#define USBHS_USBINTR_ULPIE_SHIFT                USB_USBINTR_ULPIE_SHIFT
#define USBHS_USBINTR_ULPIE(x)                   USB_USBINTR_ULPIE(x)
#define USBHS_USBINTR_NAKE_MASK                  USB_USBINTR_NAKE_MASK
#define USBHS_USBINTR_NAKE_SHIFT                 USB_USBINTR_NAKE_SHIFT
#define USBHS_USBINTR_NAKE(x)                    USB_USBINTR_NAKE(x)
#define USBHS_USBINTR_UAIE_MASK                  USB_USBINTR_UAIE_MASK
#define USBHS_USBINTR_UAIE_SHIFT                 USB_USBINTR_UAIE_SHIFT
#define USBHS_USBINTR_UAIE(x)                    USB_USBINTR_UAIE(x)
#define USBHS_USBINTR_UPIE_MASK                  USB_USBINTR_UPIE_MASK
#define USBHS_USBINTR_UPIE_SHIFT                 USB_USBINTR_UPIE_SHIFT
#define USBHS_USBINTR_UPIE(x)                    USB_USBINTR_UPIE(x)
#define USBHS_USBINTR_TIE0_MASK                  USB_USBINTR_TIE0_MASK
#define USBHS_USBINTR_TIE0_SHIFT                 USB_USBINTR_TIE0_SHIFT
#define USBHS_USBINTR_TIE0(x)                    USB_USBINTR_TIE0(x)
#define USBHS_USBINTR_TIE1_MASK                  USB_USBINTR_TIE1_MASK
#define USBHS_USBINTR_TIE1_SHIFT                 USB_USBINTR_TIE1_SHIFT
#define USBHS_USBINTR_TIE1(x)                    USB_USBINTR_TIE1(x)
#define USBHS_FRINDEX_FRINDEX_MASK               USB_FRINDEX_FRINDEX_MASK
#define USBHS_FRINDEX_FRINDEX_SHIFT              USB_FRINDEX_FRINDEX_SHIFT
#define USBHS_FRINDEX_FRINDEX(x)                 USB_FRINDEX_FRINDEX(x)
#define USBHS_DEVICEADDR_USBADRA_MASK            USB_DEVICEADDR_USBADRA_MASK
#define USBHS_DEVICEADDR_USBADRA_SHIFT           USB_DEVICEADDR_USBADRA_SHIFT
#define USBHS_DEVICEADDR_USBADRA(x)              USB_DEVICEADDR_USBADRA(x)
#define USBHS_DEVICEADDR_USBADR_MASK             USB_DEVICEADDR_USBADR_MASK
#define USBHS_DEVICEADDR_USBADR_SHIFT            USB_DEVICEADDR_USBADR_SHIFT
#define USBHS_DEVICEADDR_USBADR(x)               USB_DEVICEADDR_USBADR(x)
#define USBHS_PERIODICLISTBASE_PERBASE_MASK      USB_PERIODICLISTBASE_BASEADR_MASK
#define USBHS_PERIODICLISTBASE_PERBASE_SHIFT     USB_PERIODICLISTBASE_BASEADR_SHIFT
#define USBHS_PERIODICLISTBASE_PERBASE(x)        USB_PERIODICLISTBASE_BASEADR(x)
#define USBHS_ASYNCLISTADDR_ASYBASE_MASK         USB_ASYNCLISTADDR_ASYBASE_MASK
#define USBHS_ASYNCLISTADDR_ASYBASE_SHIFT        USB_ASYNCLISTADDR_ASYBASE_SHIFT
#define USBHS_ASYNCLISTADDR_ASYBASE(x)           USB_ASYNCLISTADDR_ASYBASE(x)
#define USBHS_EPLISTADDR_EPBASE_MASK             USB_ENDPTLISTADDR_EPBASE_MASK
#define USBHS_EPLISTADDR_EPBASE_SHIFT            USB_ENDPTLISTADDR_EPBASE_SHIFT
#define USBHS_EPLISTADDR_EPBASE(x)               USB_ENDPTLISTADDR_EPBASE(x)
#define USBHS_BURSTSIZE_RXPBURST_MASK            USB_BURSTSIZE_RXPBURST_MASK
#define USBHS_BURSTSIZE_RXPBURST_SHIFT           USB_BURSTSIZE_RXPBURST_SHIFT
#define USBHS_BURSTSIZE_RXPBURST(x)              USB_BURSTSIZE_RXPBURST(x)
#define USBHS_BURSTSIZE_TXPBURST_MASK            USB_BURSTSIZE_TXPBURST_MASK
#define USBHS_BURSTSIZE_TXPBURST_SHIFT           USB_BURSTSIZE_TXPBURST_SHIFT
#define USBHS_BURSTSIZE_TXPBURST(x)              USB_BURSTSIZE_TXPBURST(x)
#define USBHS_TXFILLTUNING_TXSCHOH_MASK          USB_TXFILLTUNING_TXSCHOH_MASK
#define USBHS_TXFILLTUNING_TXSCHOH_SHIFT         USB_TXFILLTUNING_TXSCHOH_SHIFT
#define USBHS_TXFILLTUNING_TXSCHOH(x)            USB_TXFILLTUNING_TXSCHOH(x)
#define USBHS_TXFILLTUNING_TXSCHHEALTH_MASK      USB_TXFILLTUNING_TXSCHHEALTH_MASK
#define USBHS_TXFILLTUNING_TXSCHHEALTH_SHIFT     USB_TXFILLTUNING_TXSCHHEALTH_SHIFT
#define USBHS_TXFILLTUNING_TXSCHHEALTH(x)        USB_TXFILLTUNING_TXSCHHEALTH(x)
#define USBHS_TXFILLTUNING_TXFIFOTHRES_MASK      USB_TXFILLTUNING_TXFIFOTHRES_MASK
#define USBHS_TXFILLTUNING_TXFIFOTHRES_SHIFT     USB_TXFILLTUNING_TXFIFOTHRES_SHIFT
#define USBHS_TXFILLTUNING_TXFIFOTHRES(x)        USB_TXFILLTUNING_TXFIFOTHRES(x)
#define USBHS_ENDPTNAK_EPRN_MASK                 USB_ENDPTNAK_EPRN_MASK
#define USBHS_ENDPTNAK_EPRN_SHIFT                USB_ENDPTNAK_EPRN_SHIFT
#define USBHS_ENDPTNAK_EPRN(x)                   USB_ENDPTNAK_EPRN(x)
#define USBHS_ENDPTNAK_EPTN_MASK                 USB_ENDPTNAK_EPTN_MASK
#define USBHS_ENDPTNAK_EPTN_SHIFT                USB_ENDPTNAK_EPTN_SHIFT
#define USBHS_ENDPTNAK_EPTN(x)                   USB_ENDPTNAK_EPTN(x)
#define USBHS_ENDPTNAKEN_EPRNE_MASK              USB_ENDPTNAKEN_EPRNE_MASK
#define USBHS_ENDPTNAKEN_EPRNE_SHIFT             USB_ENDPTNAKEN_EPRNE_SHIFT
#define USBHS_ENDPTNAKEN_EPRNE(x)                USB_ENDPTNAKEN_EPRNE(x)
#define USBHS_ENDPTNAKEN_EPTNE_MASK              USB_ENDPTNAKEN_EPTNE_MASK
#define USBHS_ENDPTNAKEN_EPTNE_SHIFT             USB_ENDPTNAKEN_EPTNE_SHIFT
#define USBHS_ENDPTNAKEN_EPTNE(x)                USB_ENDPTNAKEN_EPTNE(x)
#define USBHS_CONFIGFLAG_CF_MASK                 USB_CONFIGFLAG_CF_MASK
#define USBHS_CONFIGFLAG_CF_SHIFT                USB_CONFIGFLAG_CF_SHIFT
#define USBHS_CONFIGFLAG_CF(x)                   USB_CONFIGFLAG_CF(x)
#define USBHS_PORTSC1_CCS_MASK                   USB_PORTSC1_CCS_MASK
#define USBHS_PORTSC1_CCS_SHIFT                  USB_PORTSC1_CCS_SHIFT
#define USBHS_PORTSC1_CCS(x)                     USB_PORTSC1_CCS(x)
#define USBHS_PORTSC1_CSC_MASK                   USB_PORTSC1_CSC_MASK
#define USBHS_PORTSC1_CSC_SHIFT                  USB_PORTSC1_CSC_SHIFT
#define USBHS_PORTSC1_CSC(x)                     USB_PORTSC1_CSC(x)
#define USBHS_PORTSC1_PE_MASK                    USB_PORTSC1_PE_MASK
#define USBHS_PORTSC1_PE_SHIFT                   USB_PORTSC1_PE_SHIFT
#define USBHS_PORTSC1_PE(x)                      USB_PORTSC1_PE(x)
#define USBHS_PORTSC1_PEC_MASK                   USB_PORTSC1_PEC_MASK
#define USBHS_PORTSC1_PEC_SHIFT                  USB_PORTSC1_PEC_SHIFT
#define USBHS_PORTSC1_PEC(x)                     USB_PORTSC1_PEC(x)
#define USBHS_PORTSC1_OCA_MASK                   USB_PORTSC1_OCA_MASK
#define USBHS_PORTSC1_OCA_SHIFT                  USB_PORTSC1_OCA_SHIFT
#define USBHS_PORTSC1_OCA(x)                     USB_PORTSC1_OCA(x)
#define USBHS_PORTSC1_OCC_MASK                   USB_PORTSC1_OCC_MASK
#define USBHS_PORTSC1_OCC_SHIFT                  USB_PORTSC1_OCC_SHIFT
#define USBHS_PORTSC1_OCC(x)                     USB_PORTSC1_OCC(x)
#define USBHS_PORTSC1_FPR_MASK                   USB_PORTSC1_FPR_MASK
#define USBHS_PORTSC1_FPR_SHIFT                  USB_PORTSC1_FPR_SHIFT
#define USBHS_PORTSC1_FPR(x)                     USB_PORTSC1_FPR(x)
#define USBHS_PORTSC1_SUSP_MASK                  USB_PORTSC1_SUSP_MASK
#define USBHS_PORTSC1_SUSP_SHIFT                 USB_PORTSC1_SUSP_SHIFT
#define USBHS_PORTSC1_SUSP(x)                    USB_PORTSC1_SUSP(x)
#define USBHS_PORTSC1_PR_MASK                    USB_PORTSC1_PR_MASK
#define USBHS_PORTSC1_PR_SHIFT                   USB_PORTSC1_PR_SHIFT
#define USBHS_PORTSC1_PR(x)                      USB_PORTSC1_PR(x)
#define USBHS_PORTSC1_HSP_MASK                   USB_PORTSC1_HSP_MASK
#define USBHS_PORTSC1_HSP_SHIFT                  USB_PORTSC1_HSP_SHIFT
#define USBHS_PORTSC1_HSP(x)                     USB_PORTSC1_HSP(x)
#define USBHS_PORTSC1_LS_MASK                    USB_PORTSC1_LS_MASK
#define USBHS_PORTSC1_LS_SHIFT                   USB_PORTSC1_LS_SHIFT
#define USBHS_PORTSC1_LS(x)                      USB_PORTSC1_LS(x)
#define USBHS_PORTSC1_PP_MASK                    USB_PORTSC1_PP_MASK
#define USBHS_PORTSC1_PP_SHIFT                   USB_PORTSC1_PP_SHIFT
#define USBHS_PORTSC1_PP(x)                      USB_PORTSC1_PP(x)
#define USBHS_PORTSC1_PO_MASK                    USB_PORTSC1_PO_MASK
#define USBHS_PORTSC1_PO_SHIFT                   USB_PORTSC1_PO_SHIFT
#define USBHS_PORTSC1_PO(x)                      USB_PORTSC1_PO(x)
#define USBHS_PORTSC1_PIC_MASK                   USB_PORTSC1_PIC_MASK
#define USBHS_PORTSC1_PIC_SHIFT                  USB_PORTSC1_PIC_SHIFT
#define USBHS_PORTSC1_PIC(x)                     USB_PORTSC1_PIC(x)
#define USBHS_PORTSC1_PTC_MASK                   USB_PORTSC1_PTC_MASK
#define USBHS_PORTSC1_PTC_SHIFT                  USB_PORTSC1_PTC_SHIFT
#define USBHS_PORTSC1_PTC(x)                     USB_PORTSC1_PTC(x)
#define USBHS_PORTSC1_WKCN_MASK                  USB_PORTSC1_WKCN_MASK
#define USBHS_PORTSC1_WKCN_SHIFT                 USB_PORTSC1_WKCN_SHIFT
#define USBHS_PORTSC1_WKCN(x)                    USB_PORTSC1_WKCN(x)
#define USBHS_PORTSC1_WKDS_MASK                  USB_PORTSC1_WKDC_MASK
#define USBHS_PORTSC1_WKDS_SHIFT                 USB_PORTSC1_WKDC_SHIFT
#define USBHS_PORTSC1_WKDS(x)                    USB_PORTSC1_WKDC(x)
#define USBHS_PORTSC1_WKOC_MASK                  USB_PORTSC1_WKOC_MASK
#define USBHS_PORTSC1_WKOC_SHIFT                 USB_PORTSC1_WKOC_SHIFT
#define USBHS_PORTSC1_WKOC(x)                    USB_PORTSC1_WKOC(x)
#define USBHS_PORTSC1_PHCD_MASK                  USB_PORTSC1_PHCD_MASK
#define USBHS_PORTSC1_PHCD_SHIFT                 USB_PORTSC1_PHCD_SHIFT
#define USBHS_PORTSC1_PHCD(x)                    USB_PORTSC1_PHCD(x)
#define USBHS_PORTSC1_PFSC_MASK                  USB_PORTSC1_PFSC_MASK
#define USBHS_PORTSC1_PFSC_SHIFT                 USB_PORTSC1_PFSC_SHIFT
#define USBHS_PORTSC1_PFSC(x)                    USB_PORTSC1_PFSC(x)
#define USBHS_PORTSC1_PTS2_MASK                  USB_PORTSC1_PTS_2_MASK
#define USBHS_PORTSC1_PTS2_SHIFT                 USB_PORTSC1_PTS_2_SHIFT
#define USBHS_PORTSC1_PTS2(x)                    USB_PORTSC1_PTS_2(x)
#define USBHS_PORTSC1_PSPD_MASK                  USB_PORTSC1_PSPD_MASK
#define USBHS_PORTSC1_PSPD_SHIFT                 USB_PORTSC1_PSPD_SHIFT
#define USBHS_PORTSC1_PSPD(x)                    USB_PORTSC1_PSPD(x)
#define USBHS_PORTSC1_PTW_MASK                   USB_PORTSC1_PTW_MASK
#define USBHS_PORTSC1_PTW_SHIFT                  USB_PORTSC1_PTW_SHIFT
#define USBHS_PORTSC1_PTW(x)                     USB_PORTSC1_PTW(x)
#define USBHS_PORTSC1_STS_MASK                   USB_PORTSC1_STS_MASK
#define USBHS_PORTSC1_STS_SHIFT                  USB_PORTSC1_STS_SHIFT
#define USBHS_PORTSC1_STS(x)                     USB_PORTSC1_STS(x)
#define USBHS_PORTSC1_PTS_MASK                   USB_PORTSC1_PTS_1_MASK
#define USBHS_PORTSC1_PTS_SHIFT                  USB_PORTSC1_PTS_1_SHIFT
#define USBHS_PORTSC1_PTS(x)                     USB_PORTSC1_PTS_1(x)
#define USBHS_OTGSC_VD_MASK                      USB_OTGSC_VD_MASK
#define USBHS_OTGSC_VD_SHIFT                     USB_OTGSC_VD_SHIFT
#define USBHS_OTGSC_VD(x)                        USB_OTGSC_VD(x)
#define USBHS_OTGSC_VC_MASK                      USB_OTGSC_VC_MASK
#define USBHS_OTGSC_VC_SHIFT                     USB_OTGSC_VC_SHIFT
#define USBHS_OTGSC_VC(x)                        USB_OTGSC_VC(x)
#define USBHS_OTGSC_OT_MASK                      USB_OTGSC_OT_MASK
#define USBHS_OTGSC_OT_SHIFT                     USB_OTGSC_OT_SHIFT
#define USBHS_OTGSC_OT(x)                        USB_OTGSC_OT(x)
#define USBHS_OTGSC_DP_MASK                      USB_OTGSC_DP_MASK
#define USBHS_OTGSC_DP_SHIFT                     USB_OTGSC_DP_SHIFT
#define USBHS_OTGSC_DP(x)                        USB_OTGSC_DP(x)
#define USBHS_OTGSC_IDPU_MASK                    USB_OTGSC_IDPU_MASK
#define USBHS_OTGSC_IDPU_SHIFT                   USB_OTGSC_IDPU_SHIFT
#define USBHS_OTGSC_IDPU(x)                      USB_OTGSC_IDPU(x)
#define USBHS_OTGSC_ID_MASK                      USB_OTGSC_ID_MASK
#define USBHS_OTGSC_ID_SHIFT                     USB_OTGSC_ID_SHIFT
#define USBHS_OTGSC_ID(x)                        USB_OTGSC_ID(x)
#define USBHS_OTGSC_AVV_MASK                     USB_OTGSC_AVV_MASK
#define USBHS_OTGSC_AVV_SHIFT                    USB_OTGSC_AVV_SHIFT
#define USBHS_OTGSC_AVV(x)                       USB_OTGSC_AVV(x)
#define USBHS_OTGSC_ASV_MASK                     USB_OTGSC_ASV_MASK
#define USBHS_OTGSC_ASV_SHIFT                    USB_OTGSC_ASV_SHIFT
#define USBHS_OTGSC_ASV(x)                       USB_OTGSC_ASV(x)
#define USBHS_OTGSC_BSV_MASK                     USB_OTGSC_BSV_MASK
#define USBHS_OTGSC_BSV_SHIFT                    USB_OTGSC_BSV_SHIFT
#define USBHS_OTGSC_BSV(x)                       USB_OTGSC_BSV(x)
#define USBHS_OTGSC_BSE_MASK                     USB_OTGSC_BSE_MASK
#define USBHS_OTGSC_BSE_SHIFT                    USB_OTGSC_BSE_SHIFT
#define USBHS_OTGSC_BSE(x)                       USB_OTGSC_BSE(x)
#define USBHS_OTGSC_MST_MASK                     USB_OTGSC_TOG_1MS_MASK
#define USBHS_OTGSC_MST_SHIFT                    USB_OTGSC_TOG_1MS_SHIFT
#define USBHS_OTGSC_MST(x)                       USB_OTGSC_TOG_1MS(x)
#define USBHS_OTGSC_DPS_MASK                     USB_OTGSC_DPS_MASK
#define USBHS_OTGSC_DPS_SHIFT                    USB_OTGSC_DPS_SHIFT
#define USBHS_OTGSC_DPS(x)                       USB_OTGSC_DPS(x)
#define USBHS_OTGSC_IDIS_MASK                    USB_OTGSC_IDIS_MASK
#define USBHS_OTGSC_IDIS_SHIFT                   USB_OTGSC_IDIS_SHIFT
#define USBHS_OTGSC_IDIS(x)                      USB_OTGSC_IDIS(x)
#define USBHS_OTGSC_AVVIS_MASK                   USB_OTGSC_AVVIS_MASK
#define USBHS_OTGSC_AVVIS_SHIFT                  USB_OTGSC_AVVIS_SHIFT
#define USBHS_OTGSC_AVVIS(x)                     USB_OTGSC_AVVIS(x)
#define USBHS_OTGSC_ASVIS_MASK                   USB_OTGSC_ASVIS_MASK
#define USBHS_OTGSC_ASVIS_SHIFT                  USB_OTGSC_ASVIS_SHIFT
#define USBHS_OTGSC_ASVIS(x)                     USB_OTGSC_ASVIS(x)
#define USBHS_OTGSC_BSVIS_MASK                   USB_OTGSC_BSVIS_MASK
#define USBHS_OTGSC_BSVIS_SHIFT                  USB_OTGSC_BSVIS_SHIFT
#define USBHS_OTGSC_BSVIS(x)                     USB_OTGSC_BSVIS(x)
#define USBHS_OTGSC_BSEIS_MASK                   USB_OTGSC_BSEIS_MASK
#define USBHS_OTGSC_BSEIS_SHIFT                  USB_OTGSC_BSEIS_SHIFT
#define USBHS_OTGSC_BSEIS(x)                     USB_OTGSC_BSEIS(x)
#define USBHS_OTGSC_MSS_MASK                     USB_OTGSC_STATUS_1MS_MASK
#define USBHS_OTGSC_MSS_SHIFT                    USB_OTGSC_STATUS_1MS_SHIFT
#define USBHS_OTGSC_MSS(x)                       USB_OTGSC_STATUS_1MS(x)
#define USBHS_OTGSC_DPIS_MASK                    USB_OTGSC_DPIS_MASK
#define USBHS_OTGSC_DPIS_SHIFT                   USB_OTGSC_DPIS_SHIFT
#define USBHS_OTGSC_DPIS(x)                      USB_OTGSC_DPIS(x)
#define USBHS_OTGSC_IDIE_MASK                    USB_OTGSC_IDIE_MASK
#define USBHS_OTGSC_IDIE_SHIFT                   USB_OTGSC_IDIE_SHIFT
#define USBHS_OTGSC_IDIE(x)                      USB_OTGSC_IDIE(x)
#define USBHS_OTGSC_AVVIE_MASK                   USB_OTGSC_AVVIE_MASK
#define USBHS_OTGSC_AVVIE_SHIFT                  USB_OTGSC_AVVIE_SHIFT
#define USBHS_OTGSC_AVVIE(x)                     USB_OTGSC_AVVIE(x)
#define USBHS_OTGSC_ASVIE_MASK                   USB_OTGSC_ASVIE_MASK
#define USBHS_OTGSC_ASVIE_SHIFT                  USB_OTGSC_ASVIE_SHIFT
#define USBHS_OTGSC_ASVIE(x)                     USB_OTGSC_ASVIE(x)
#define USBHS_OTGSC_BSVIE_MASK                   USB_OTGSC_BSVIE_MASK
#define USBHS_OTGSC_BSVIE_SHIFT                  USB_OTGSC_BSVIE_SHIFT
#define USBHS_OTGSC_BSVIE(x)                     USB_OTGSC_BSVIE(x)
#define USBHS_OTGSC_BSEIE_MASK                   USB_OTGSC_BSEIE_MASK
#define USBHS_OTGSC_BSEIE_SHIFT                  USB_OTGSC_BSEIE_SHIFT
#define USBHS_OTGSC_BSEIE(x)                     USB_OTGSC_BSEIE(x)
#define USBHS_OTGSC_MSE_MASK                     USB_OTGSC_EN_1MS_MASK
#define USBHS_OTGSC_MSE_SHIFT                    USB_OTGSC_EN_1MS_SHIFT
#define USBHS_OTGSC_MSE(x)                       USB_OTGSC_EN_1MS(x)
#define USBHS_OTGSC_DPIE_MASK                    USB_OTGSC_DPIE_MASK
#define USBHS_OTGSC_DPIE_SHIFT                   USB_OTGSC_DPIE_SHIFT
#define USBHS_OTGSC_DPIE(x)                      USB_OTGSC_DPIE(x)
#define USBHS_USBMODE_CM_MASK                    USB_USBMODE_CM_MASK
#define USBHS_USBMODE_CM_SHIFT                   USB_USBMODE_CM_SHIFT
#define USBHS_USBMODE_CM(x)                      USB_USBMODE_CM(x)
#define USBHS_USBMODE_ES_MASK                    USB_USBMODE_ES_MASK
#define USBHS_USBMODE_ES_SHIFT                   USB_USBMODE_ES_SHIFT
#define USBHS_USBMODE_ES(x)                      USB_USBMODE_ES(x)
#define USBHS_USBMODE_SLOM_MASK                  USB_USBMODE_SLOM_MASK
#define USBHS_USBMODE_SLOM_SHIFT                 USB_USBMODE_SLOM_SHIFT
#define USBHS_USBMODE_SLOM(x)                    USB_USBMODE_SLOM(x)
#define USBHS_USBMODE_SDIS_MASK                  USB_USBMODE_SDIS_MASK
#define USBHS_USBMODE_SDIS_SHIFT                 USB_USBMODE_SDIS_SHIFT
#define USBHS_USBMODE_SDIS(x)                    USB_USBMODE_SDIS(x)
#define USBHS_EPSETUPSR_EPSETUPSTAT_MASK         USB_ENDPTSETUPSTAT_ENDPTSETUPSTAT_MASK
#define USBHS_EPSETUPSR_EPSETUPSTAT_SHIFT        USB_ENDPTSETUPSTAT_ENDPTSETUPSTAT_SHIFT
#define USBHS_EPSETUPSR_EPSETUPSTAT(x)           USB_ENDPTSETUPSTAT_ENDPTSETUPSTAT(x)
#define USBHS_EPPRIME_PERB_MASK                  USB_ENDPTPRIME_PERB_MASK
#define USBHS_EPPRIME_PERB_SHIFT                 USB_ENDPTPRIME_PERB_SHIFT
#define USBHS_EPPRIME_PERB(x)                    USB_ENDPTPRIME_PERB(x)
#define USBHS_EPPRIME_PETB_MASK                  USB_ENDPTPRIME_PETB_MASK
#define USBHS_EPPRIME_PETB_SHIFT                 USB_ENDPTPRIME_PETB_SHIFT
#define USBHS_EPPRIME_PETB(x)                    USB_ENDPTPRIME_PETB(x)
#define USBHS_EPFLUSH_FERB_MASK                  USB_ENDPTFLUSH_FERB_MASK
#define USBHS_EPFLUSH_FERB_SHIFT                 USB_ENDPTFLUSH_FERB_SHIFT
#define USBHS_EPFLUSH_FERB(x)                    USB_ENDPTFLUSH_FERB(x)
#define USBHS_EPFLUSH_FETB_MASK                  USB_ENDPTFLUSH_FETB_MASK
#define USBHS_EPFLUSH_FETB_SHIFT                 USB_ENDPTFLUSH_FETB_SHIFT
#define USBHS_EPFLUSH_FETB(x)                    USB_ENDPTFLUSH_FETB(x)
#define USBHS_EPSR_ERBR_MASK                     USB_ENDPTSTAT_ERBR_MASK
#define USBHS_EPSR_ERBR_SHIFT                    USB_ENDPTSTAT_ERBR_SHIFT
#define USBHS_EPSR_ERBR(x)                       USB_ENDPTSTAT_ERBR(x)
#define USBHS_EPSR_ETBR_MASK                     USB_ENDPTSTAT_ETBR_MASK
#define USBHS_EPSR_ETBR_SHIFT                    USB_ENDPTSTAT_ETBR_SHIFT
#define USBHS_EPSR_ETBR(x)                       USB_ENDPTSTAT_ETBR(x)
#define USBHS_EPCOMPLETE_ERCE_MASK               USB_ENDPTCOMPLETE_ERCE_MASK
#define USBHS_EPCOMPLETE_ERCE_SHIFT              USB_ENDPTCOMPLETE_ERCE_SHIFT
#define USBHS_EPCOMPLETE_ERCE(x)                 USB_ENDPTCOMPLETE_ERCE(x)
#define USBHS_EPCOMPLETE_ETCE_MASK               USB_ENDPTCOMPLETE_ETCE_MASK
#define USBHS_EPCOMPLETE_ETCE_SHIFT              USB_ENDPTCOMPLETE_ETCE_SHIFT
#define USBHS_EPCOMPLETE_ETCE(x)                 USB_ENDPTCOMPLETE_ETCE(x)
#define USBHS_EPCR0_RXS_MASK                     USB_ENDPTCTRL0_RXS_MASK
#define USBHS_EPCR0_RXS_SHIFT                    USB_ENDPTCTRL0_RXS_SHIFT
#define USBHS_EPCR0_RXS(x)                       USB_ENDPTCTRL0_RXS(x)
#define USBHS_EPCR0_RXT_MASK                     USB_ENDPTCTRL0_RXT_MASK
#define USBHS_EPCR0_RXT_SHIFT                    USB_ENDPTCTRL0_RXT_SHIFT
#define USBHS_EPCR0_RXT(x)                       USB_ENDPTCTRL0_RXT(x)
#define USBHS_EPCR0_RXE_MASK                     USB_ENDPTCTRL0_RXE_MASK
#define USBHS_EPCR0_RXE_SHIFT                    USB_ENDPTCTRL0_RXE_SHIFT
#define USBHS_EPCR0_RXE(x)                       USB_ENDPTCTRL0_RXE(x)
#define USBHS_EPCR0_TXS_MASK                     USB_ENDPTCTRL0_TXS_MASK
#define USBHS_EPCR0_TXS_SHIFT                    USB_ENDPTCTRL0_TXS_SHIFT
#define USBHS_EPCR0_TXS(x)                       USB_ENDPTCTRL0_TXS(x)
#define USBHS_EPCR0_TXT_MASK                     USB_ENDPTCTRL0_TXT_MASK
#define USBHS_EPCR0_TXT_SHIFT                    USB_ENDPTCTRL0_TXT_SHIFT
#define USBHS_EPCR0_TXT(x)                       USB_ENDPTCTRL0_TXT(x)
#define USBHS_EPCR0_TXE_MASK                     USB_ENDPTCTRL0_TXE_MASK
#define USBHS_EPCR0_TXE_SHIFT                    USB_ENDPTCTRL0_TXE_SHIFT
#define USBHS_EPCR0_TXE(x)                       USB_ENDPTCTRL0_TXE(x)
#define USBHS_EPCR_RXS_MASK                      USB_ENDPTCTRL_RXS_MASK
#define USBHS_EPCR_RXS_SHIFT                     USB_ENDPTCTRL_RXS_SHIFT
#define USBHS_EPCR_RXS(x)                        USB_ENDPTCTRL_RXS(x)
#define USBHS_EPCR_RXD_MASK                      USB_ENDPTCTRL_RXD_MASK
#define USBHS_EPCR_RXD_SHIFT                     USB_ENDPTCTRL_RXD_SHIFT
#define USBHS_EPCR_RXD(x)                        USB_ENDPTCTRL_RXD(x)
#define USBHS_EPCR_RXT_MASK                      USB_ENDPTCTRL_RXT_MASK
#define USBHS_EPCR_RXT_SHIFT                     USB_ENDPTCTRL_RXT_SHIFT
#define USBHS_EPCR_RXT(x)                        USB_ENDPTCTRL_RXT(x)
#define USBHS_EPCR_RXI_MASK                      USB_ENDPTCTRL_RXI_MASK
#define USBHS_EPCR_RXI_SHIFT                     USB_ENDPTCTRL_RXI_SHIFT
#define USBHS_EPCR_RXI(x)                        USB_ENDPTCTRL_RXI(x)
#define USBHS_EPCR_RXR_MASK                      USB_ENDPTCTRL_RXR_MASK
#define USBHS_EPCR_RXR_SHIFT                     USB_ENDPTCTRL_RXR_SHIFT
#define USBHS_EPCR_RXR(x)                        USB_ENDPTCTRL_RXR(x)
#define USBHS_EPCR_RXE_MASK                      USB_ENDPTCTRL_RXE_MASK
#define USBHS_EPCR_RXE_SHIFT                     USB_ENDPTCTRL_RXE_SHIFT
#define USBHS_EPCR_RXE(x)                        USB_ENDPTCTRL_RXE(x)
#define USBHS_EPCR_TXS_MASK                      USB_ENDPTCTRL_TXS_MASK
#define USBHS_EPCR_TXS_SHIFT                     USB_ENDPTCTRL_TXS_SHIFT
#define USBHS_EPCR_TXS(x)                        USB_ENDPTCTRL_TXS(x)
#define USBHS_EPCR_TXD_MASK                      USB_ENDPTCTRL_TXD_MASK
#define USBHS_EPCR_TXD_SHIFT                     USB_ENDPTCTRL_TXD_SHIFT
#define USBHS_EPCR_TXD(x)                        USB_ENDPTCTRL_TXD(x)
#define USBHS_EPCR_TXT_MASK                      USB_ENDPTCTRL_TXT_MASK
#define USBHS_EPCR_TXT_SHIFT                     USB_ENDPTCTRL_TXT_SHIFT
#define USBHS_EPCR_TXT(x)                        USB_ENDPTCTRL_TXT(x)
#define USBHS_EPCR_TXI_MASK                      USB_ENDPTCTRL_TXI_MASK
#define USBHS_EPCR_TXI_SHIFT                     USB_ENDPTCTRL_TXI_SHIFT
#define USBHS_EPCR_TXI(x)                        USB_ENDPTCTRL_TXI(x)
#define USBHS_EPCR_TXR_MASK                      USB_ENDPTCTRL_TXR_MASK
#define USBHS_EPCR_TXR_SHIFT                     USB_ENDPTCTRL_TXR_SHIFT
#define USBHS_EPCR_TXR(x)                        USB_ENDPTCTRL_TXR(x)
#define USBHS_EPCR_TXE_MASK                      USB_ENDPTCTRL_TXE_MASK
#define USBHS_EPCR_TXE_SHIFT                     USB_ENDPTCTRL_TXE_SHIFT
#define USBHS_EPCR_TXE(x)                        USB_ENDPTCTRL_TXE(x)
#define USBHS_EPCR_COUNT                         USB_ENDPTCTRL_COUNT
#define USBHS_Type                               USB_Type
#define USBHS_BASE_ADDRS                         USB_BASE_ADDRS
#define USBHS_IRQS                               USB_IRQS
#define USBHS_IRQHandler                         USB0_IRQHandler


/* USBHSDCD - Peripheral instance base addresses */
/** Peripheral USBDCD base address */
#define USBDCD_BASE                              (0x40414800u)
/** Peripheral USBDCD base pointer */
#define USBDCD                                   ((USBHSDCD_Type *)USBDCD_BASE)
/** Array initializer of USBHSDCD peripheral base addresses */
#define USBHSDCD_BASE_ADDRS                      { USBDCD_BASE }
/** Array initializer of USBHSDCD peripheral base pointers */
#define USBHSDCD_BASE_PTRS                       { USBDCD }

/* USBNC - Peripheral instance base addresses */
/** Peripheral USBNC0 base address */
#define USBNC0_BASE                              (0x40418200u)
/** Peripheral USBNC0 base pointer */
#define USBNC0                                   ((USBNC_Type *)USBNC0_BASE)
/** Peripheral USBNC1 base address */
#define USBNC1_BASE                              (0x40419200u)
/** Peripheral USBNC1 base pointer */
#define USBNC1                                   ((USBNC_Type *)USBNC1_BASE)
/** Array initializer of USBNC peripheral base addresses */
#define USBNC_BASE_ADDRS                         { USBNC0_BASE, USBNC1_BASE }
/** Array initializer of USBNC peripheral base pointers */
#define USBNC_BASE_PTRS                          { USBNC0, USBNC1 }
/* Backward compatibility */
#define USB_OTGn_CTRL     CTRL1
#define USBNC_USB_OTGn_CTRL_OVER_CUR_DIS_MASK      USBNC_CTRL1_OVER_CUR_DIS_MASK
#define USBNC_USB_OTGn_CTRL_OVER_CUR_DIS_SHIFT     USBNC_CTRL1_OVER_CUR_DIS_SHIFT
#define USBNC_USB_OTGn_CTRL_OVER_CUR_DIS(x)        USBNC_CTRL1_OVER_CUR_DIS(x)
#define USBNC_USB_OTGn_CTRL_OVER_CUR_POL_MASK      USBNC_CTRL1_OVER_CUR_POL_MASK
#define USBNC_USB_OTGn_CTRL_OVER_CUR_POL_SHIFT     USBNC_CTRL1_OVER_CUR_POL_SHIFT
#define USBNC_USB_OTGn_CTRL_OVER_CUR_POL(x)        USBNC_CTRL1_OVER_CUR_POL(x)
#define USBNC_USB_OTGn_CTRL_PWR_POL_MASK           USBNC_CTRL1_PWR_POL_MASK
#define USBNC_USB_OTGn_CTRL_PWR_POL_SHIFT          USBNC_CTRL1_PWR_POL_SHIFT
#define USBNC_USB_OTGn_CTRL_PWR_POL(x)             USBNC_CTRL1_PWR_POL(x)
#define USBNC_USB_OTGn_CTRL_WIE_MASK               USBNC_CTRL1_WIE_MASK
#define USBNC_USB_OTGn_CTRL_WIE_SHIFT              USBNC_CTRL1_WIE_SHIFT
#define USBNC_USB_OTGn_CTRL_WIE(x)                 USBNC_CTRL1_WIE(x)
#define USBNC_USB_OTGn_CTRL_WKUP_SW_EN_MASK        USBNC_CTRL1_WKUP_SW_EN_MASK
#define USBNC_USB_OTGn_CTRL_WKUP_SW_EN_SHIFT       USBNC_CTRL1_WKUP_SW_EN_SHIFT
#define USBNC_USB_OTGn_CTRL_WKUP_SW_EN(x)          USBNC_CTRL1_WKUP_SW_EN(x)
#define USBNC_USB_OTGn_CTRL_WKUP_SW_MASK           USBNC_CTRL1_WKUP_SW_MASK
#define USBNC_USB_OTGn_CTRL_WKUP_SW_SHIFT          USBNC_CTRL1_WKUP_SW_SHIFT
#define USBNC_USB_OTGn_CTRL_WKUP_SW(x)             USBNC_CTRL1_WKUP_SW(x)
#define USBNC_USB_OTGn_CTRL_WKUP_VBUS_EN_MASK      USBNC_CTRL1_WKUP_VBUS_EN_MASK
#define USBNC_USB_OTGn_CTRL_WKUP_VBUS_EN_SHIFT     USBNC_CTRL1_WKUP_VBUS_EN_SHIFT
#define USBNC_USB_OTGn_CTRL_WKUP_VBUS_EN(x)        USBNC_CTRL1_WKUP_VBUS_EN(x)
#define USBNC_USB_OTGn_CTRL_REMOTE_WAKEUP_EN_MASK  USBNC_CTRL1_REMOTE_WAKEUP_EN_MASK
#define USBNC_USB_OTGn_CTRL_REMOTE_WAKEUP_EN_SHIFT USBNC_CTRL1_REMOTE_WAKEUP_EN_SHIFT
#define USBNC_USB_OTGn_CTRL_REMOTE_WAKEUP_EN(x)    USBNC_CTRL1_REMOTE_WAKEUP_EN(x)
#define USBNC_USB_OTGn_CTRL_WKUP_DPDM_EN_MASK      USBNC_CTRL1_WKUP_DPDM_EN_MASK
#define USBNC_USB_OTGn_CTRL_WKUP_DPDM_EN_SHIFT     USBNC_CTRL1_WKUP_DPDM_EN_SHIFT
#define USBNC_USB_OTGn_CTRL_WKUP_DPDM_EN(x)        USBNC_CTRL1_WKUP_DPDM_EN(x)
#define USBNC_USB_OTGn_CTRL_WIR_MASK               USBNC_CTRL1_WIR_MASK
#define USBNC_USB_OTGn_CTRL_WIR_SHIFT              USBNC_CTRL1_WIR_SHIFT
#define USBNC_USB_OTGn_CTRL_WIR(x)                 USBNC_CTRL1_WIR(x)
#define USBNC_STACK_BASE_ADDRS                     { USBNC0_BASE, USBNC1_BASE }


/* USBPHY - Peripheral instance base addresses */
/** Peripheral USBPHY base address */
#define USBPHY_BASE                              (0x40414000u)
/** Peripheral USBPHY base pointer */
#define USBPHY                                   ((USBPHY_Type *)USBPHY_BASE)
/** Array initializer of USBPHY peripheral base addresses */
#define USBPHY_BASE_ADDRS                        { USBPHY_BASE }
/** Array initializer of USBPHY peripheral base pointers */
#define USBPHY_BASE_PTRS                         { USBPHY }
/* Backward compatibility */
#define USBPHY_CTRL_ENDEVPLUGINDET_MASK     USBPHY_CTRL_ENDEVPLUGINDETECT_MASK
#define USBPHY_CTRL_ENDEVPLUGINDET_SHIFT    USBPHY_CTRL_ENDEVPLUGINDETECT_SHIFT
#define USBPHY_CTRL_ENDEVPLUGINDET(x)       USBPHY_CTRL_ENDEVPLUGINDETECT(x)
#define USBPHY_TX_TXCAL45DM_MASK            USBPHY_TX_TXCAL45DN_MASK
#define USBPHY_TX_TXCAL45DM_SHIFT           USBPHY_TX_TXCAL45DN_SHIFT
#define USBPHY_TX_TXCAL45DM(x)              USBPHY_TX_TXCAL45DN(x)


/* USDHC - Peripheral instance base addresses */
/** Peripheral USDHC0 base address */
#define USDHC0_BASE                              (0x40412000u)
/** Peripheral USDHC0 base pointer */
#define USDHC0                                   ((USDHC_Type *)USDHC0_BASE)
/** Peripheral USDHC1 base address */
#define USDHC1_BASE                              (0x40413000u)
/** Peripheral USDHC1 base pointer */
#define USDHC1                                   ((USDHC_Type *)USDHC1_BASE)
/** Array initializer of USDHC peripheral base addresses */
#define USDHC_BASE_ADDRS                         { USDHC0_BASE, USDHC1_BASE }
/** Array initializer of USDHC peripheral base pointers */
#define USDHC_BASE_PTRS                          { USDHC0, USDHC1 }

/* UTICK - Peripheral instance base addresses */
/** Peripheral UTICK0 base address */
#define UTICK0_BASE                              (0x4000F000u)
/** Peripheral UTICK0 base pointer */
#define UTICK0                                   ((UTICK_Type *)UTICK0_BASE)
/** Peripheral UTICK1 base address */
#define UTICK1_BASE                              (0x40052000u)
/** Peripheral UTICK1 base pointer */
#define UTICK1                                   ((UTICK_Type *)UTICK1_BASE)
/** Array initializer of UTICK peripheral base addresses */
#define UTICK_BASE_ADDRS                         { UTICK0_BASE, UTICK1_BASE }
/** Array initializer of UTICK peripheral base pointers */
#define UTICK_BASE_PTRS                          { UTICK0, UTICK1 }

/* WWDT - Peripheral instance base addresses */
/** Peripheral WWDT0 base address */
#define WWDT0_BASE                               (0x4000E000u)
/** Peripheral WWDT0 base pointer */
#define WWDT0                                    ((WWDT_Type *)WWDT0_BASE)
/** Peripheral WWDT1 base address */
#define WWDT1_BASE                               (0x4002E000u)
/** Peripheral WWDT1 base pointer */
#define WWDT1                                    ((WWDT_Type *)WWDT1_BASE)
/** Peripheral WWDT2 base address */
#define WWDT2_BASE                               (0x40050000u)
/** Peripheral WWDT2 base pointer */
#define WWDT2                                    ((WWDT_Type *)WWDT2_BASE)
/** Peripheral WWDT3 base address */
#define WWDT3_BASE                               (0x40051000u)
/** Peripheral WWDT3 base pointer */
#define WWDT3                                    ((WWDT_Type *)WWDT3_BASE)
/** Array initializer of WWDT peripheral base addresses */
#define WWDT_BASE_ADDRS                          { WWDT0_BASE, WWDT1_BASE, WWDT2_BASE, WWDT3_BASE }
/** Array initializer of WWDT peripheral base pointers */
#define WWDT_BASE_PTRS                           { WWDT0, WWDT1, WWDT2, WWDT3 }

/* XCACHE - Peripheral instance base addresses */
/** Peripheral XCACHE0 base address */
#define XCACHE0_BASE                             (0x40033000u)
/** Peripheral XCACHE0 base pointer */
#define XCACHE0                                  ((XCACHE_Type *)XCACHE0_BASE)
/** Peripheral XCACHE1 base address */
#define XCACHE1_BASE                             (0x40034000u)
/** Peripheral XCACHE1 base pointer */
#define XCACHE1                                  ((XCACHE_Type *)XCACHE1_BASE)
/** Array initializer of XCACHE peripheral base addresses */
#define XCACHE_BASE_ADDRS                        { XCACHE0_BASE, XCACHE1_BASE }
/** Array initializer of XCACHE peripheral base pointers */
#define XCACHE_BASE_PTRS                         { XCACHE0, XCACHE1 }
/** XCACHE physical memory base address */
 #define XCACHE_PHYMEM_BASES                       { 0x20000000u, 0x00000000u }
/** XCACHE physical memory size */
 #define XCACHE_PHYMEM_SIZES                       { 0x780000u, 0x780000u }
/* Backward compatibility */
#define XCACHE_CSAR_PHYADDR_MASK (XCACHE_CSAR_PHYADDR27_1_MASK | XCACHE_CSAR_PHYADDR31_29_MASK)


/* XSPI - Peripheral instance base addresses */
/** Peripheral XSPI0 base address */
#define XSPI0_BASE                               (0x40184000u)
/** Peripheral XSPI0 base pointer */
#define XSPI0                                    ((XSPI_Type *)XSPI0_BASE)
/** Peripheral XSPI1 base address */
#define XSPI1_BASE                               (0x40185000u)
/** Peripheral XSPI1 base pointer */
#define XSPI1                                    ((XSPI_Type *)XSPI1_BASE)
/** Peripheral XSPI2 base address */
#define XSPI2_BASE                               (0x40411000u)
/** Peripheral XSPI2 base pointer */
#define XSPI2                                    ((XSPI_Type *)XSPI2_BASE)
/** Array initializer of XSPI peripheral base addresses */
#define XSPI_BASE_ADDRS                          { XSPI0_BASE, XSPI1_BASE, XSPI2_BASE }
/** Array initializer of XSPI peripheral base pointers */
#define XSPI_BASE_PTRS                           { XSPI0, XSPI1, XSPI2 }
  /* XSPI AMBA address. */
  #define XSPI0_AMBA_BASE      (0x28000000u)
  #define XSPI1_AMBA_BASE      (0x08000000u)
  #define XSPI2_AMBA_BASE      (0x60000000u)
  #define XSPI_AMBA_BASES      {0x28000000u, 0x08000000u, 0x60000000u}


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

/**  Used for get the base address of ROM API */
#define FSL_ROM_API_BASE_ADDR 0x1302F000U

/*!
 * @}
 */ /* end of group SDK_Compatibility_Symbols */


#endif  /* MIMXRT758S_EZHV_COMMON_H_ */

