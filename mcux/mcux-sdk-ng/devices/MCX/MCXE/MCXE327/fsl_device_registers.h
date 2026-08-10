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
#if (defined(CPU_MCXE327MPA_cm7_core0) || defined(CPU_MCXE327MPB_cm7_core0))
#include "MCXE327_cm7_core0.h"
#elif (defined(CPU_MCXE327MPA_cm7_core1) || defined(CPU_MCXE327MPB_cm7_core1))
#include "MCXE327_cm7_core1.h"
#else
  #error "No valid CPU defined!"
#endif

#endif /* __FSL_DEVICE_REGISTERS_H__ */

/*******************************************************************************
 * EOF
 ******************************************************************************/
