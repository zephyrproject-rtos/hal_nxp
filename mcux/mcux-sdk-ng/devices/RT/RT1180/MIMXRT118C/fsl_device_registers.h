/*
 * Copyright 2014-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2026 NXP
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
#if (defined(CPU_MIMXRT118CCVJ8C_cm33) || defined(CPU_MIMXRT118CXVJ8C_cm33))
#include "MIMXRT118C_cm33.h"
#elif (defined(CPU_MIMXRT118CCVJ8C_cm7) || defined(CPU_MIMXRT118CXVJ8C_cm7))
#include "MIMXRT118C_cm7.h"
#else
  #error "No valid CPU defined!"
#endif

#endif /* __FSL_DEVICE_REGISTERS_H__ */

/*******************************************************************************
 * EOF
 ******************************************************************************/
