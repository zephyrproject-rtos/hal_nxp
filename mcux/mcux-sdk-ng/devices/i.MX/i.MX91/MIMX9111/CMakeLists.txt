# Copyright 2025-2026 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

#### device spepcific drivers
mcux_add_cmakelists(${SdkRootDirPath}/${device_root}/i.MX/i.MX91/${device}/drivers)

#### device spepcific drivers
include(${SdkRootDirPath}/devices/arm/device_header_multicore.cmake)
include(${SdkRootDirPath}/devices/arm/device_header_multicore_cstartup.cmake)

#### i.MX shared drivers/components/middlewares, project segments
include(${SdkRootDirPath}/devices/i.MX/shared.cmake)
