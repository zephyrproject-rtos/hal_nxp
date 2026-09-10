/*
 * Copyright 2014-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2026 NXP
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __FSL_DEVICE_REGISTERS_H__
#define __FSL_DEVICE_REGISTERS_H__

/*
 * Include the cpu specific register header files.
 *
 * The CPU macro should be declared in the project or makefile.
 */
#if (defined(CPU_MIMXRT2663AHP8A) || defined(CPU_MIMXRT2663AVV8A) || defined(CPU_MIMXRT2663CHPAA) || defined(CPU_MIMXRT2663CVVAA) || defined(CPU_MIMXRT2663DHPAA) || defined(CPU_MIMXRT2663DVVAA) || defined(CPU_MIMXRT2663XHP8A) || defined(CPU_MIMXRT2663XHPAA) || defined(CPU_MIMXRT2663XVV8A) || defined(CPU_MIMXRT2663XVVAA))
#include "MIMXRT2663.h"
#else
  #error "No valid CPU defined!"
#endif

/*
 * RGPIO compatibility shim (Zephyr RT2260-EVK baseline).
 *
 * The MIMXRT2663 device pack models the RGPIO instances under the legacy
 * "GPIO" peripheral name (GPIO_Type, GPIO_BASE_PTRS, GPIO_ICR_* field macros),
 * but the shared fsl_rgpio driver - and the Zephyr nxp,imx-rgpio driver that
 * wraps it (gpio_mcux_rgpio.c) - expect the RGPIO_* spelling used by the other
 * RT parts (e.g. RT1180). The register layout is identical; only the generated
 * names differ. Alias the RGPIO_* names the driver needs onto the GPIO_* names
 * this device provides. The optional RGPIO feature flags are deliberately left
 * undefined so the attribute-checker / IRQ-config / port-input-disable code
 * paths (which rely on GACR / other fields not generated here) stay disabled.
 */
#ifndef RGPIO_Type
#define RGPIO_Type                  GPIO_Type
#define RGPIO_BASE_PTRS             GPIO_BASE_PTRS
#define RGPIO_ICR_IRQC_MASK         GPIO_ICR_IRQC_MASK
#define RGPIO_ICR_IRQC_SHIFT        GPIO_ICR_IRQC_SHIFT
#define RGPIO_ICR_IRQC(x)           GPIO_ICR_IRQC(x)
#define RGPIO_ICR_IRQS_MASK         GPIO_ICR_IRQS_MASK
#define RGPIO_ICR_IRQS_SHIFT        GPIO_ICR_IRQS_SHIFT
#define RGPIO_ICR_IRQS(x)           GPIO_ICR_IRQS(x)

/*
 * The RGPIO instances expose the per-pin Interrupt Control Register (ICR) with
 * the IRQC/IRQS fields, so enable the fsl_rgpio IRQ-config API. The pin
 * attribute-checker (GACR) and port-input-disable (PIDR-based) features are not
 * generated for this device, so leave their feature flags undefined.
 */
#ifndef FSL_FEATURE_RGPIO_HAS_IRQ_CONFIG
#define FSL_FEATURE_RGPIO_HAS_IRQ_CONFIG  (1)
#endif
#endif /* RGPIO_Type */

#endif /* __FSL_DEVICE_REGISTERS_H__ */

/*******************************************************************************
 * EOF
 ******************************************************************************/
