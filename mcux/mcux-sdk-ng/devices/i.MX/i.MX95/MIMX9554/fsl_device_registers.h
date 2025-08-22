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
#if (defined(CPU_MIMX9554AVTXN_ca55) || defined(CPU_MIMX9554AVZXN_ca55) || defined(CPU_MIMX9554CVTXN_ca55) || defined(CPU_MIMX9554CVZXN_ca55) || defined(CPU_MIMX9554DVTXN_ca55) || defined(CPU_MIMX9554DVZXN_ca55) || defined(CPU_MIMX9554XVTXN_ca55) || defined(CPU_MIMX9554XVZXN_ca55))
#include "MIMX9554_ca55.h"
#elif (defined(CPU_MIMX9554AVTXN_cm33) || defined(CPU_MIMX9554AVZXN_cm33) || defined(CPU_MIMX9554CVTXN_cm33) || defined(CPU_MIMX9554CVZXN_cm33) || defined(CPU_MIMX9554DVTXN_cm33) || defined(CPU_MIMX9554DVZXN_cm33) || defined(CPU_MIMX9554XVTXN_cm33) || defined(CPU_MIMX9554XVZXN_cm33))
#include "MIMX9554_cm33.h"
#elif (defined(CPU_MIMX9554AVTXN_cm7) || defined(CPU_MIMX9554AVZXN_cm7) || defined(CPU_MIMX9554CVTXN_cm7) || defined(CPU_MIMX9554CVZXN_cm7) || defined(CPU_MIMX9554DVTXN_cm7) || defined(CPU_MIMX9554DVZXN_cm7) || defined(CPU_MIMX9554XVTXN_cm7) || defined(CPU_MIMX9554XVZXN_cm7))
#include "MIMX9554_cm7.h"
#else
  #error "No valid CPU defined!"
#endif

#endif /* __FSL_DEVICE_REGISTERS_H__ */

/*******************************************************************************
 * EOF
 ******************************************************************************/
