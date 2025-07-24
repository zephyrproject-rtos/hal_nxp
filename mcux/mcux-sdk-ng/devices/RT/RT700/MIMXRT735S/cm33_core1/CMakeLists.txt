# Copyright 2024-2025 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

#### device spepcific drivers
include(${SdkRootDirPath}/devices/arm/device_header_multicore_cstartup.cmake)

# middlewares and components
include(${SdkRootDirPath}/devices/arm/shared.cmake)

# common configuration
include(${SdkRootDirPath}/arch/arm/configuration/RT.cmake)
