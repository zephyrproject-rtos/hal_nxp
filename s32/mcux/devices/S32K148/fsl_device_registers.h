/*
 * Copyright 2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef __FSL_DEVICE_REGISTERS_H__
#define __FSL_DEVICE_REGISTERS_H__

/*
 * Include the cpu specific register header files.
 *
 * The CPU macro should be declared in the project or makefile.
 */

#if defined(CPU_S32K148)

/* CMSIS-style register definitions */
#include <S32K148.h>
#include "S32K148_device.h"

/* CPU specific feature definitions */
#include "S32K148_features.h"

/* Needed for MCUX fsl_common.h */
#include "core_cm4.h"

#else
    #error "No valid CPU defined!"
#endif

#endif /* __FSL_DEVICE_REGISTERS_H__ */
