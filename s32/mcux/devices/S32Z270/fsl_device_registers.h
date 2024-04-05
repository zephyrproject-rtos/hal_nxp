/*
 * Copyright 2023-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef __FSL_DEVICE_REGISTERS_H__
#define __FSL_DEVICE_REGISTERS_H__

/*
 * Include the cpu specific register header files.
 *
 * The CPU macro should be declared in the project or makefile.
 */

#if defined(CPU_S32Z270)

/* CMSIS-style register definitions */
#include "S32Z2.h"
/* CPU specific feature definitions */
#include "S32Z270_features.h"

/* Define the IRQ types for RTU sub-system */
#define IRQn_Type       RTU_IRQn_Type
#define NotAvail_IRQn   RTU_NotAvail_IRQn

/*
 * In order to reuse RTD CMSIS-based headers for the MCUX drivers, is needed
 * to redefine the peripheral macros from IP_PERIPHERAL_n to PERIPHERALn.
 */
#include "S32Z270_glue_mcux.h"

/* Dummy implementations just to build mcux/mcux-sdk/drivers/common/fsl_common_arm.h */
#define __GIC_PRESENT   0
#define __GIC_PRIO_BITS 0
static inline void GIC_EnableIRQ(IRQn_Type IRQn) { }
static inline void GIC_DisableIRQ(IRQn_Type IRQn) { }
static inline void GIC_ClearPendingIRQ(IRQn_Type IRQn) { }
static inline void GIC_SetPriority(IRQn_Type IRQn, uint32_t priority) { }

#include "core_cr52.h"

#else
    #error "No valid CPU defined!"
#endif

#endif /* __FSL_DEVICE_REGISTERS_H__ */
