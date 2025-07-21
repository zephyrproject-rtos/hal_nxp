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
#if (defined(CPU_MIMX9536AVZXN_ca55) || defined(CPU_MIMX9536CVTXN_ca55) || defined(CPU_MIMX9536CVZXN_ca55) || defined(CPU_MIMX9536DVTXN_ca55) || defined(CPU_MIMX9536DVZXN_ca55) || defined(CPU_MIMX9536DVZXQ_ca55) || defined(CPU_MIMX9536XVTXN_ca55) || defined(CPU_MIMX9536XVZXN_ca55))
#include "MIMX9536_ca55.h"
#elif (defined(CPU_MIMX9536AVZXN_cm33) || defined(CPU_MIMX9536CVTXN_cm33) || defined(CPU_MIMX9536CVZXN_cm33) || defined(CPU_MIMX9536DVTXN_cm33) || defined(CPU_MIMX9536DVZXN_cm33) || defined(CPU_MIMX9536DVZXQ_cm33) || defined(CPU_MIMX9536XVTXN_cm33) || defined(CPU_MIMX9536XVZXN_cm33))
#include "MIMX9536_cm33.h"
#elif (defined(CPU_MIMX9536AVZXN_cm7) || defined(CPU_MIMX9536CVTXN_cm7) || defined(CPU_MIMX9536CVZXN_cm7) || defined(CPU_MIMX9536DVTXN_cm7) || defined(CPU_MIMX9536DVZXN_cm7) || defined(CPU_MIMX9536DVZXQ_cm7) || defined(CPU_MIMX9536XVTXN_cm7) || defined(CPU_MIMX9536XVZXN_cm7))
#include "MIMX9536_cm7.h"
#else
  #error "No valid CPU defined!"
#endif

#endif /* __FSL_DEVICE_REGISTERS_H__ */

/*******************************************************************************
 * EOF
 ******************************************************************************/
