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
#if (defined(CPU_MIMX9576AVZXN_ca55) || defined(CPU_MIMX9576CVTXN_ca55) || defined(CPU_MIMX9576CVZXN_ca55) || defined(CPU_MIMX9576DVTXN_ca55) || defined(CPU_MIMX9576DVZXN_ca55) || defined(CPU_MIMX9576XVTXN_ca55) || defined(CPU_MIMX9576XVZXN_ca55))
#include "MIMX9576_ca55.h"
#elif (defined(CPU_MIMX9576AVZXN_cm33) || defined(CPU_MIMX9576CVTXN_cm33) || defined(CPU_MIMX9576CVZXN_cm33) || defined(CPU_MIMX9576DVTXN_cm33) || defined(CPU_MIMX9576DVZXN_cm33) || defined(CPU_MIMX9576XVTXN_cm33) || defined(CPU_MIMX9576XVZXN_cm33))
#include "MIMX9576_cm33.h"
#elif (defined(CPU_MIMX9576AVZXN_cm7) || defined(CPU_MIMX9576CVTXN_cm7) || defined(CPU_MIMX9576CVZXN_cm7) || defined(CPU_MIMX9576DVTXN_cm7) || defined(CPU_MIMX9576DVZXN_cm7) || defined(CPU_MIMX9576XVTXN_cm7) || defined(CPU_MIMX9576XVZXN_cm7))
#include "MIMX9576_cm7.h"
#else
  #error "No valid CPU defined!"
#endif

#endif /* __FSL_DEVICE_REGISTERS_H__ */

/*******************************************************************************
 * EOF
 ******************************************************************************/
