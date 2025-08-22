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
#if (defined(CPU_MIMX9574AVZXN_ca55) || defined(CPU_MIMX9574CVTXN_ca55) || defined(CPU_MIMX9574CVZXN_ca55) || defined(CPU_MIMX9574DVTXN_ca55) || defined(CPU_MIMX9574DVZXN_ca55) || defined(CPU_MIMX9574XVTXN_ca55) || defined(CPU_MIMX9574XVZXN_ca55))
#include "MIMX9574_ca55.h"
#elif (defined(CPU_MIMX9574AVZXN_cm33) || defined(CPU_MIMX9574CVTXN_cm33) || defined(CPU_MIMX9574CVZXN_cm33) || defined(CPU_MIMX9574DVTXN_cm33) || defined(CPU_MIMX9574DVZXN_cm33) || defined(CPU_MIMX9574XVTXN_cm33) || defined(CPU_MIMX9574XVZXN_cm33))
#include "MIMX9574_cm33.h"
#elif (defined(CPU_MIMX9574AVZXN_cm7) || defined(CPU_MIMX9574CVTXN_cm7) || defined(CPU_MIMX9574CVZXN_cm7) || defined(CPU_MIMX9574DVTXN_cm7) || defined(CPU_MIMX9574DVZXN_cm7) || defined(CPU_MIMX9574XVTXN_cm7) || defined(CPU_MIMX9574XVZXN_cm7))
#include "MIMX9574_cm7.h"
#else
  #error "No valid CPU defined!"
#endif

#endif /* __FSL_DEVICE_REGISTERS_H__ */

/*******************************************************************************
 * EOF
 ******************************************************************************/
