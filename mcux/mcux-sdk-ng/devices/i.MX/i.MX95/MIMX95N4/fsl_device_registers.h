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
#if (defined(CPU_MIMX95N4AVTXN_ca55) || defined(CPU_MIMX95N4AVZXN_ca55) || defined(CPU_MIMX95N4CVTXN_ca55) || defined(CPU_MIMX95N4CVZXN_ca55) || defined(CPU_MIMX95N4DVTXN_ca55) || defined(CPU_MIMX95N4DVZXN_ca55) || defined(CPU_MIMX95N4XVTXN_ca55) || defined(CPU_MIMX95N4XVZXN_ca55))
#include "MIMX95N4_ca55.h"
#elif (defined(CPU_MIMX95N4AVTXN_cm33) || defined(CPU_MIMX95N4AVZXN_cm33) || defined(CPU_MIMX95N4CVTXN_cm33) || defined(CPU_MIMX95N4CVZXN_cm33) || defined(CPU_MIMX95N4DVTXN_cm33) || defined(CPU_MIMX95N4DVZXN_cm33) || defined(CPU_MIMX95N4XVTXN_cm33) || defined(CPU_MIMX95N4XVZXN_cm33))
#include "MIMX95N4_cm33.h"
#elif (defined(CPU_MIMX95N4AVTXN_cm7) || defined(CPU_MIMX95N4AVZXN_cm7) || defined(CPU_MIMX95N4CVTXN_cm7) || defined(CPU_MIMX95N4CVZXN_cm7) || defined(CPU_MIMX95N4DVTXN_cm7) || defined(CPU_MIMX95N4DVZXN_cm7) || defined(CPU_MIMX95N4XVTXN_cm7) || defined(CPU_MIMX95N4XVZXN_cm7))
#include "MIMX95N4_cm7.h"
#else
  #error "No valid CPU defined!"
#endif

#endif /* __FSL_DEVICE_REGISTERS_H__ */

/*******************************************************************************
 * EOF
 ******************************************************************************/
