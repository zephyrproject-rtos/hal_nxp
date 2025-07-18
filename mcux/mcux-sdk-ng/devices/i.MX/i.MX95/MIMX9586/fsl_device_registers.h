/*
 * Copyright 2014-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2025 NXP
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
#if (defined(CPU_MIMX9586AVZXN_ca55) || defined(CPU_MIMX9586XVZXN_ca55))
#include "MIMX9586_ca55.h"
#elif (defined(CPU_MIMX9586AVZXN_cm33) || defined(CPU_MIMX9586XVZXN_cm33))
#include "MIMX9586_cm33.h"
#elif (defined(CPU_MIMX9586AVZXN_cm7) || defined(CPU_MIMX9586XVZXN_cm7))
#include "MIMX9586_cm7.h"
#else
  #error "No valid CPU defined!"
#endif

#endif /* __FSL_DEVICE_REGISTERS_H__ */

/*******************************************************************************
 * EOF
 ******************************************************************************/
