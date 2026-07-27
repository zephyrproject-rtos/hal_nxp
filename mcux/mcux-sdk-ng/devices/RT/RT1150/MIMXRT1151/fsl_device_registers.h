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
#if (defined(CPU_MIMXRT1151DHM8B) || defined(CPU_MIMXRT1151DVM8B) || defined(CPU_MIMXRT1151XHM8B) || defined(CPU_MIMXRT1151XVM8B))
#include "MIMXRT1151.h"
#else
  #error "No valid CPU defined!"
#endif

#endif /* __FSL_DEVICE_REGISTERS_H__ */

/*******************************************************************************
 * EOF
 ******************************************************************************/
