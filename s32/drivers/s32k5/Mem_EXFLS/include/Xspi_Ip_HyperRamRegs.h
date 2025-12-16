/*
 * Copyright 2024-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef XSPI_IP_HYPERRAMREGS_H
#define XSPI_IP_HYPERRAMREGS_H

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define XSPI_IP_HYPERRAMREGS_VENDOR_ID_H                    43
#define XSPI_IP_HYPERRAMREGS_AR_RELEASE_MAJOR_VERSION_H     4
#define XSPI_IP_HYPERRAMREGS_AR_RELEASE_MINOR_VERSION_H     9
#define XSPI_IP_HYPERRAMREGS_AR_RELEASE_REVISION_VERSION_H  0
#define XSPI_IP_HYPERRAMREGS_SW_MAJOR_VERSION_H             0
#define XSPI_IP_HYPERRAMREGS_SW_MINOR_VERSION_H             8
#define XSPI_IP_HYPERRAMREGS_SW_PATCH_VERSION_H             0


/*******************************************************************************
 *                                       DEFINITIONS
 ******************************************************************************/

 #if (XSPI_IP_HYPERRAM_ENABLED == STD_ON)
/*Address of Configuarion Register 0*/
#define XSPI_IP_HR_REGCFG0_ADDR         0x001000U

/*Address of Configuarion Register 1*/
#define XSPI_IP_HR_REGCFG1_ADDR         0x001002U

#define XSPI_IP_HR_CR0_DRIVE_STRENGTH_MASK           0x70U
#define XSPI_IP_HR_CR0_DRIVE_STRENGTH_SHIFT          4U
#define XSPI_IP_HR_CR0_DRIVE_STRENGTH(x)             (((uint16)(((uint16)(x)) << XSPI_IP_HR_CR0_DRIVE_STRENGTH_SHIFT)) & XSPI_IP_HR_CR0_DRIVE_STRENGTH_MASK)

#define XSPI_IP_HR_CR0_INITIAL_LATENCY_MASK          0xF000U
#define XSPI_IP_HR_CR0_INITIAL_LATENCY_SHIFT         12U
#define XSPI_IP_HR_CR0_INITIAL_LATENCY(x)            (((uint16)(((uint16)(x)) << XSPI_IP_HR_CR0_INITIAL_LATENCY_SHIFT)) & XSPI_IP_HR_CR0_INITIAL_LATENCY_MASK)

/*Default value of CR0*/
/*Drive strength and initial latency bits field will be configured by the driver.
  Other bits field will be kept as default follow datasheet of the hyperram */
#define XSPI_IP_HR_CR0_DEFAULT_VALUE                 0x0F8FU

/* Macros for Configuation Register 1 bits manipulation */
#define XSPI_IP_HR_CR1_MASTER_CLOCK_TYPE_MASK        0x4000U
#define XSPI_IP_HR_CR1_MASTER_CLOCK_TYPE_SHIFT       14U
#define XSPI_IP_HR_CR1_MASTER_CLOCK_TYPE(x)          (((uint16)(((uint16)(x)) << XSPI_IP_HR_CR1_MASTER_CLOCK_TYPE_SHIFT)) & XSPI_IP_HR_CR1_MASTER_CLOCK_TYPE_MASK)

#define XSPI_IP_HR_CR1_PARTIAL_REFRESH_MASK          0x1C00U
#define XSPI_IP_HR_CR1_PARTIAL_REFRESH_SHIFT         10U
#define XSPI_IP_HR_CR1_PARTIAL_REFRESH(x)            (((uint16)(((uint16)(x)) << XSPI_IP_HR_CR1_PARTIAL_REFRESH_SHIFT)) & XSPI_IP_HR_CR1_PARTIAL_REFRESH_MASK)

/*Default value of CR1*/
/*Master clock type and Partial array refresh bits field will be configured by the driver.
  Other bits field will be kept as default follow datasheet of the hyperram */
#define XSPI_IP_HR_CR1_DEFAULT_VALUE                 0x81FFU

#endif /* XSPI_IP_HYPERRAM_ENABLED == STD_ON */

#ifdef __cplusplus
}
#endif

#endif /* XSPI_IP_HYPERRAMREGS_H */
