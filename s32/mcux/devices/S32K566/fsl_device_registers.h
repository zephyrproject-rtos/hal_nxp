/*
 * Copyright 2025 NXP
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

#if defined(CPU_S32K566)

#define S32K566_SERIES

/* CMSIS-style register definitions */
#include "S32K566.h"
/* CPU specific feature definitions */
#include "S32K566_features.h"

/*
 * In order to reuse RTD CMSIS-based headers for the MCUX drivers, is needed
 * to redefine the peripheral macros from IP_PERIPHERAL_n to PERIPHERALn.
 */
#include "S32K566_glue_mcux.h"

#if defined(CONFIG_CPU_CORTEX_M7)
/*
 * RTD header S32K566_COMMON.h already defined the code configuration for CMSIS,
 * so include the CMSIS core header here since it's needed for some common
 * functions of MCUX.
 */
    #include "core_cm7.h"

#else
    #define __GIC_PRESENT   0
    #define __GIC_PRIO_BITS 0
    static inline void GIC_EnableIRQ(IRQn_Type IRQn) { }
    static inline void GIC_DisableIRQ(IRQn_Type IRQn) { }
    static inline void GIC_ClearPendingIRQ(IRQn_Type IRQn) { }
    static inline void GIC_SetPriority(IRQn_Type IRQn, uint32_t priority) { }

    #include "core_cr52.h"
#endif

#endif

#endif /* __FSL_DEVICE_REGISTERS_H__ */
