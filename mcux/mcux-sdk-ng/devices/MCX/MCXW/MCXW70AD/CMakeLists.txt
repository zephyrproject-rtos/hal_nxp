# Copyright 2026 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

#### device specific drivers
include(${SdkRootDirPath}/devices/arm/device_header.cmake)
mcux_add_cmakelists(${SdkRootDirPath}/${device_root}/MCX/MCXW/MCXW70AD/drivers)

#### MCXW shared drivers/components/middlewares, project segments
include(${SdkRootDirPath}/devices/MCX/MCXW/shared.cmake)
