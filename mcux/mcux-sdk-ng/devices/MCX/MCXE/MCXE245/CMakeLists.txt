# Copyright 2025 NXP
# All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause

#### device spepcific drivers
include(${SdkRootDirPath}/devices/arm/device_header.cmake)
mcux_add_cmakelists(${SdkRootDirPath}/${device_root}/MCX/MCXE/MCXE245/drivers)

#### MCX shared drivers/components/middlewares, project segments
include(${SdkRootDirPath}/devices/MCX/shared.cmake)
