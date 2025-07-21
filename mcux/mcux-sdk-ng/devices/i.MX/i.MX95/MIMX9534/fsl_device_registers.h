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
#if (defined(CPU_MIMX9534AVZXN_ca55) || defined(CPU_MIMX9534CVTXN_ca55) || defined(CPU_MIMX9534CVZXN_ca55) || defined(CPU_MIMX9534DVTXN_ca55) || defined(CPU_MIMX9534DVZXN_ca55) || defined(CPU_MIMX9534XVTXN_ca55) || defined(CPU_MIMX9534XVZXN_ca55))
#include "MIMX9534_ca55.h"
#elif (defined(CPU_MIMX9534AVZXN_cm33) || defined(CPU_MIMX9534CVTXN_cm33) || defined(CPU_MIMX9534CVZXN_cm33) || defined(CPU_MIMX9534DVTXN_cm33) || defined(CPU_MIMX9534DVZXN_cm33) || defined(CPU_MIMX9534XVTXN_cm33) || defined(CPU_MIMX9534XVZXN_cm33))
#include "MIMX9534_cm33.h"
#elif (defined(CPU_MIMX9534AVZXN_cm7) || defined(CPU_MIMX9534CVTXN_cm7) || defined(CPU_MIMX9534CVZXN_cm7) || defined(CPU_MIMX9534DVTXN_cm7) || defined(CPU_MIMX9534DVZXN_cm7) || defined(CPU_MIMX9534XVTXN_cm7) || defined(CPU_MIMX9534XVZXN_cm7))
#include "MIMX9534_cm7.h"
#else
  #error "No valid CPU defined!"
#endif

#endif /* __FSL_DEVICE_REGISTERS_H__ */

/*******************************************************************************
 * EOF
 ******************************************************************************/
