/*
 * Copyright 2025-2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef MCMGR_PLATFORM_H_
#define MCMGR_PLATFORM_H_

#include <stdint.h>

/* Needed for kIMU_LinkCpu* enumerators used in IMU_LINK */
#include "fsl_imu.h"

/* Count of cores in the system */
#define MCMGR_CORECOUNT 2

/* Count of memory regions in the system */
#define MCMGR_MEMREGCOUNT 2

/* MCMGR MU channel index - used for passing startupData */
#define MCMGR_IMU_CHANNEL 1

/*
 * Select the IMU link direction and what core this image is built for.
 * IMU_CPU_INDEX is provided by the device/board configuration.
 */
#if defined(IMU_CPU_INDEX) && (IMU_CPU_INDEX == 1U)
#define IMU_LINK kIMU_LinkCpu1Cpu2
#define MCMGR_BUILD_FOR_CORE_0
#elif defined(IMU_CPU_INDEX) && (IMU_CPU_INDEX == 2U)
#define IMU_LINK kIMU_LinkCpu2Cpu1
#define MCMGR_BUILD_FOR_CORE_1
#else
#error "Building for not supported platform!"
#endif

#endif /* MCMGR_PLATFORM_H_ */
