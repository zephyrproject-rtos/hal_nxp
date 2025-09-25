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
#if (defined(CPU_MIMXRT798SGAWBR_cm33_core0) || defined(CPU_MIMXRT798SGFOB_cm33_core0))
#include "MIMXRT798S_cm33_core0.h"
#elif (defined(CPU_MIMXRT798SGAWBR_cm33_core1) || defined(CPU_MIMXRT798SGFOB_cm33_core1))
#include "MIMXRT798S_cm33_core1.h"
#elif (defined(CPU_MIMXRT798SGAWBR_ezhv) || defined(CPU_MIMXRT798SGFOB_ezhv))
#include "MIMXRT798S_ezhv.h"
#elif (defined(CPU_MIMXRT798SGAWBR_hifi1) || defined(CPU_MIMXRT798SGFOB_hifi1))
#include "MIMXRT798S_hifi1.h"
#elif (defined(CPU_MIMXRT798SGAWBR_hifi4) || defined(CPU_MIMXRT798SGFOB_hifi4))
#include "MIMXRT798S_hifi4.h"
#else
  #error "No valid CPU defined!"
#endif

#endif /* __FSL_DEVICE_REGISTERS_H__ */

/*******************************************************************************
 * EOF
 ******************************************************************************/
