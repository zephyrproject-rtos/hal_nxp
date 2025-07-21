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
#if (defined(CPU_MIMX9594AVZXN_ca55) || defined(CPU_MIMX9594CVTXN_ca55) || defined(CPU_MIMX9594CVZXN_ca55) || defined(CPU_MIMX9594DVTXN_ca55) || defined(CPU_MIMX9594DVZXN_ca55) || defined(CPU_MIMX9594XVTXN_ca55) || defined(CPU_MIMX9594XVZXN_ca55))
#include "MIMX9594_ca55.h"
#elif (defined(CPU_MIMX9594AVZXN_cm33) || defined(CPU_MIMX9594CVTXN_cm33) || defined(CPU_MIMX9594CVZXN_cm33) || defined(CPU_MIMX9594DVTXN_cm33) || defined(CPU_MIMX9594DVZXN_cm33) || defined(CPU_MIMX9594XVTXN_cm33) || defined(CPU_MIMX9594XVZXN_cm33))
#include "MIMX9594_cm33.h"
#elif (defined(CPU_MIMX9594AVZXN_cm7) || defined(CPU_MIMX9594CVTXN_cm7) || defined(CPU_MIMX9594CVZXN_cm7) || defined(CPU_MIMX9594DVTXN_cm7) || defined(CPU_MIMX9594DVZXN_cm7) || defined(CPU_MIMX9594XVTXN_cm7) || defined(CPU_MIMX9594XVZXN_cm7))
#include "MIMX9594_cm7.h"
#else
  #error "No valid CPU defined!"
#endif

#endif /* __FSL_DEVICE_REGISTERS_H__ */

/*******************************************************************************
 * EOF
 ******************************************************************************/
