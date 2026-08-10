# Copyright 2026 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

#### device spepcific drivers
include(${SdkRootDirPath}/devices/arm/device_header_multicore_cstartup.cmake)
mcux_add_cmakelists(${SdkRootDirPath}/${device_root}/MCX/MCXE/MCXE32B/drivers)

#### MCX shared drivers/components/middlewares, project segments
include(${SdkRootDirPath}/devices/MCX/shared.cmake)
