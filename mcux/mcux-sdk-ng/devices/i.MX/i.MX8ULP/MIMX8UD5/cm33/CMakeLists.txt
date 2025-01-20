# Copyright 2024 NXP
# All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause

#### device spepcific drivers
include(${SdkRootDirPath}/devices/arm/device_header_multicore.cmake)
mcux_add_cmakelists(${SdkRootDirPath}/devices/i.MX/i.MX8ULP/MIMX8UD5/drivers)
mcux_add_cmakelists(${SdkRootDirPath}/devices/i.MX/i.MX8ULP/MIMX8UD5/drivers/upower)


#### i.MX shared drivers/components/middlewares, project segments
include(${SdkRootDirPath}/devices/i.MX/shared.cmake)
