# Copyright 2024 NXP
# All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause

#### device spepcific drivers
include(${SdkRootDirPath}/devices/arm/device_header.cmake)
mcux_add_cmakelists(${SdkRootDirPath}/${device_root}/i.MX/i.MX7ULP/MCIMX7U3/drivers)

#### MIMX shared drivers/components/middlewares, project segments
include(${SdkRootDirPath}/devices/i.MX/shared.cmake)
