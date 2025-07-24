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
#if (defined(CPU_MIMX95N6AVTXN_ca55) || defined(CPU_MIMX95N6AVZXN_ca55) || defined(CPU_MIMX95N6CVTXN_ca55) || defined(CPU_MIMX95N6CVYXN_ca55) || defined(CPU_MIMX95N6CVZXN_ca55) || defined(CPU_MIMX95N6DVTXN_ca55) || defined(CPU_MIMX95N6DVZXN_ca55) || defined(CPU_MIMX95N6XVTXN_ca55) || defined(CPU_MIMX95N6XVZXN_ca55))
#include "MIMX95N6_ca55.h"
#elif (defined(CPU_MIMX95N6AVTXN_cm33) || defined(CPU_MIMX95N6AVZXN_cm33) || defined(CPU_MIMX95N6CVTXN_cm33) || defined(CPU_MIMX95N6CVYXN_cm33) || defined(CPU_MIMX95N6CVZXN_cm33) || defined(CPU_MIMX95N6DVTXN_cm33) || defined(CPU_MIMX95N6DVZXN_cm33) || defined(CPU_MIMX95N6XVTXN_cm33) || defined(CPU_MIMX95N6XVZXN_cm33))
#include "MIMX95N6_cm33.h"
#elif (defined(CPU_MIMX95N6AVTXN_cm7) || defined(CPU_MIMX95N6AVZXN_cm7) || defined(CPU_MIMX95N6CVTXN_cm7) || defined(CPU_MIMX95N6CVYXN_cm7) || defined(CPU_MIMX95N6CVZXN_cm7) || defined(CPU_MIMX95N6DVTXN_cm7) || defined(CPU_MIMX95N6DVZXN_cm7) || defined(CPU_MIMX95N6XVTXN_cm7) || defined(CPU_MIMX95N6XVZXN_cm7))
#include "MIMX95N6_cm7.h"
#else
  #error "No valid CPU defined!"
#endif

#endif /* __FSL_DEVICE_REGISTERS_H__ */

/*******************************************************************************
 * EOF
 ******************************************************************************/
