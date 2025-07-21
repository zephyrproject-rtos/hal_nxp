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
#if (defined(CPU_MIMX9556AVZXN_ca55) || defined(CPU_MIMX9556CVTXN_ca55) || defined(CPU_MIMX9556CVZXN_ca55) || defined(CPU_MIMX9556DVTXN_ca55) || defined(CPU_MIMX9556DVZXN_ca55) || defined(CPU_MIMX9556XVTXN_ca55) || defined(CPU_MIMX9556XVZXN_ca55))
#include "MIMX9556_ca55.h"
#elif (defined(CPU_MIMX9556AVZXN_cm33) || defined(CPU_MIMX9556CVTXN_cm33) || defined(CPU_MIMX9556CVZXN_cm33) || defined(CPU_MIMX9556DVTXN_cm33) || defined(CPU_MIMX9556DVZXN_cm33) || defined(CPU_MIMX9556XVTXN_cm33) || defined(CPU_MIMX9556XVZXN_cm33))
#include "MIMX9556_cm33.h"
#elif (defined(CPU_MIMX9556AVZXN_cm7) || defined(CPU_MIMX9556CVTXN_cm7) || defined(CPU_MIMX9556CVZXN_cm7) || defined(CPU_MIMX9556DVTXN_cm7) || defined(CPU_MIMX9556DVZXN_cm7) || defined(CPU_MIMX9556XVTXN_cm7) || defined(CPU_MIMX9556XVZXN_cm7))
#include "MIMX9556_cm7.h"
#else
  #error "No valid CPU defined!"
#endif

#endif /* __FSL_DEVICE_REGISTERS_H__ */

/*******************************************************************************
 * EOF
 ******************************************************************************/
