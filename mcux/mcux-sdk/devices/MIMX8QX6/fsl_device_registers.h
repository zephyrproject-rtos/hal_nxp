/*
 * Copyright 2014-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2020 NXP
 * All rights reserved.
 *
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
#if (defined(CPU_MIMX8QX6AVLFZ) || defined(CPU_MIMX8QX6CVLDZ))

#define MIMX8QX6_cm4_SERIES

/* CMSIS-style register definitions */
#include "MIMX8QX6_cm4.h"
/* CPU specific feature definitions */
#include "MIMX8QX6_cm4_features.h"

#elif (defined(CPU_MIMX8QX6AVLFZ_dsp))

#define MIMX8QX6_dsp_SERIES

/* CMSIS-style register definitions */
#include "MIMX8QX6_dsp.h"
/* CPU specific feature definitions */
#include "MIMX8QX6_dsp_features.h"

#else
    #error "No valid CPU defined!"
#endif

#endif /* __FSL_DEVICE_REGISTERS_H__ */

/*******************************************************************************
 * EOF
 ******************************************************************************/
