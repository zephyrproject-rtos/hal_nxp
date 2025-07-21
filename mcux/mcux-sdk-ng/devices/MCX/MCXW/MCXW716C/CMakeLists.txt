# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

#### device spepcific drivers
include(${SdkRootDirPath}/devices/arm/device_header.cmake)
mcux_add_cmakelists(${SdkRootDirPath}/${device_root}/MCX/MCXW/MCXW716C/drivers)

#### MCX shared drivers/components/middlewares, project segments
include(${SdkRootDirPath}/devices/MCX/shared.cmake)
