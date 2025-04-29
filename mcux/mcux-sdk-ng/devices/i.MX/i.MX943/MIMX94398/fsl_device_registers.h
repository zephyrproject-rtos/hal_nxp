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
#if (defined(CPU_MIMX94398AVKE_ca55) || defined(CPU_MIMX94398AVKJ_ca55) || defined(CPU_MIMX94398AVKM_ca55) || defined(CPU_MIMX94398AVME_ca55) || defined(CPU_MIMX94398AVMJ_ca55) || defined(CPU_MIMX94398AVMM_ca55) || defined(CPU_MIMX94398CVKE_ca55) || defined(CPU_MIMX94398CVKJ_ca55) || defined(CPU_MIMX94398CVKM_ca55) || defined(CPU_MIMX94398CVME_ca55) || defined(CPU_MIMX94398CVMJ_ca55) || defined(CPU_MIMX94398CVMM_ca55) || defined(CPU_MIMX94398DVKE_ca55) || defined(CPU_MIMX94398DVKJ_ca55) || defined(CPU_MIMX94398DVKM_ca55) || defined(CPU_MIMX94398DVME_ca55) || defined(CPU_MIMX94398DVMJ_ca55) || defined(CPU_MIMX94398DVMM_ca55) || defined(CPU_MIMX94398XVKE_ca55) || defined(CPU_MIMX94398XVKJ_ca55) || defined(CPU_MIMX94398XVKM_ca55) || defined(CPU_MIMX94398XVME_ca55) || defined(CPU_MIMX94398XVMJ_ca55) || defined(CPU_MIMX94398XVMM_ca55))
#include "MIMX94398_ca55.h"
#elif (defined(CPU_MIMX94398AVKE_cm33_core0) || defined(CPU_MIMX94398AVKJ_cm33_core0) || defined(CPU_MIMX94398AVKM_cm33_core0) || defined(CPU_MIMX94398AVME_cm33_core0) || defined(CPU_MIMX94398AVMJ_cm33_core0) || defined(CPU_MIMX94398AVMM_cm33_core0) || defined(CPU_MIMX94398CVKE_cm33_core0) || defined(CPU_MIMX94398CVKJ_cm33_core0) || defined(CPU_MIMX94398CVKM_cm33_core0) || defined(CPU_MIMX94398CVME_cm33_core0) || defined(CPU_MIMX94398CVMJ_cm33_core0) || defined(CPU_MIMX94398CVMM_cm33_core0) || defined(CPU_MIMX94398DVKE_cm33_core0) || defined(CPU_MIMX94398DVKJ_cm33_core0) || defined(CPU_MIMX94398DVKM_cm33_core0) || defined(CPU_MIMX94398DVME_cm33_core0) || defined(CPU_MIMX94398DVMJ_cm33_core0) || defined(CPU_MIMX94398DVMM_cm33_core0) || defined(CPU_MIMX94398XVKE_cm33_core0) || defined(CPU_MIMX94398XVKJ_cm33_core0) || defined(CPU_MIMX94398XVKM_cm33_core0) || defined(CPU_MIMX94398XVME_cm33_core0) || defined(CPU_MIMX94398XVMJ_cm33_core0) || defined(CPU_MIMX94398XVMM_cm33_core0))
#include "MIMX94398_cm33_core0.h"
#elif (defined(CPU_MIMX94398AVKE_cm33_core1) || defined(CPU_MIMX94398AVKJ_cm33_core1) || defined(CPU_MIMX94398AVKM_cm33_core1) || defined(CPU_MIMX94398AVME_cm33_core1) || defined(CPU_MIMX94398AVMJ_cm33_core1) || defined(CPU_MIMX94398AVMM_cm33_core1) || defined(CPU_MIMX94398CVKE_cm33_core1) || defined(CPU_MIMX94398CVKJ_cm33_core1) || defined(CPU_MIMX94398CVKM_cm33_core1) || defined(CPU_MIMX94398CVME_cm33_core1) || defined(CPU_MIMX94398CVMJ_cm33_core1) || defined(CPU_MIMX94398CVMM_cm33_core1) || defined(CPU_MIMX94398DVKE_cm33_core1) || defined(CPU_MIMX94398DVKJ_cm33_core1) || defined(CPU_MIMX94398DVKM_cm33_core1) || defined(CPU_MIMX94398DVME_cm33_core1) || defined(CPU_MIMX94398DVMJ_cm33_core1) || defined(CPU_MIMX94398DVMM_cm33_core1) || defined(CPU_MIMX94398XVKE_cm33_core1) || defined(CPU_MIMX94398XVKJ_cm33_core1) || defined(CPU_MIMX94398XVKM_cm33_core1) || defined(CPU_MIMX94398XVME_cm33_core1) || defined(CPU_MIMX94398XVMJ_cm33_core1) || defined(CPU_MIMX94398XVMM_cm33_core1))
#include "MIMX94398_cm33_core1.h"
#elif (defined(CPU_MIMX94398AVKE_cm7_core0) || defined(CPU_MIMX94398AVKJ_cm7_core0) || defined(CPU_MIMX94398AVKM_cm7_core0) || defined(CPU_MIMX94398AVME_cm7_core0) || defined(CPU_MIMX94398AVMJ_cm7_core0) || defined(CPU_MIMX94398AVMM_cm7_core0) || defined(CPU_MIMX94398CVKE_cm7_core0) || defined(CPU_MIMX94398CVKJ_cm7_core0) || defined(CPU_MIMX94398CVKM_cm7_core0) || defined(CPU_MIMX94398CVME_cm7_core0) || defined(CPU_MIMX94398CVMJ_cm7_core0) || defined(CPU_MIMX94398CVMM_cm7_core0) || defined(CPU_MIMX94398DVKE_cm7_core0) || defined(CPU_MIMX94398DVKJ_cm7_core0) || defined(CPU_MIMX94398DVKM_cm7_core0) || defined(CPU_MIMX94398DVME_cm7_core0) || defined(CPU_MIMX94398DVMJ_cm7_core0) || defined(CPU_MIMX94398DVMM_cm7_core0) || defined(CPU_MIMX94398XVKE_cm7_core0) || defined(CPU_MIMX94398XVKJ_cm7_core0) || defined(CPU_MIMX94398XVKM_cm7_core0) || defined(CPU_MIMX94398XVME_cm7_core0) || defined(CPU_MIMX94398XVMJ_cm7_core0) || defined(CPU_MIMX94398XVMM_cm7_core0))
#include "MIMX94398_cm7_core0.h"
#elif (defined(CPU_MIMX94398AVKE_cm7_core1) || defined(CPU_MIMX94398AVKJ_cm7_core1) || defined(CPU_MIMX94398AVKM_cm7_core1) || defined(CPU_MIMX94398AVME_cm7_core1) || defined(CPU_MIMX94398AVMJ_cm7_core1) || defined(CPU_MIMX94398AVMM_cm7_core1) || defined(CPU_MIMX94398CVKE_cm7_core1) || defined(CPU_MIMX94398CVKJ_cm7_core1) || defined(CPU_MIMX94398CVKM_cm7_core1) || defined(CPU_MIMX94398CVME_cm7_core1) || defined(CPU_MIMX94398CVMJ_cm7_core1) || defined(CPU_MIMX94398CVMM_cm7_core1) || defined(CPU_MIMX94398DVKE_cm7_core1) || defined(CPU_MIMX94398DVKJ_cm7_core1) || defined(CPU_MIMX94398DVKM_cm7_core1) || defined(CPU_MIMX94398DVME_cm7_core1) || defined(CPU_MIMX94398DVMJ_cm7_core1) || defined(CPU_MIMX94398DVMM_cm7_core1) || defined(CPU_MIMX94398XVKE_cm7_core1) || defined(CPU_MIMX94398XVKJ_cm7_core1) || defined(CPU_MIMX94398XVKM_cm7_core1) || defined(CPU_MIMX94398XVME_cm7_core1) || defined(CPU_MIMX94398XVMJ_cm7_core1) || defined(CPU_MIMX94398XVMM_cm7_core1))
#include "MIMX94398_cm7_core1.h"
#else
  #error "No valid CPU defined!"
#endif

#endif /* __FSL_DEVICE_REGISTERS_H__ */

/*******************************************************************************
 * EOF
 ******************************************************************************/
