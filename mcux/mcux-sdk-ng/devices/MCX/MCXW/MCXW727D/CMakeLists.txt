# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

#### device specific drivers
include(${SdkRootDirPath}/devices/arm/device_header_multicore.cmake)
mcux_add_cmakelists(${SdkRootDirPath}/${device_root}/MCX/MCXW/MCXW727D/drivers)

#### MCXW shared drivers/components/middlewares, project segments
include(${SdkRootDirPath}/devices/MCX/MCXW/shared.cmake)
