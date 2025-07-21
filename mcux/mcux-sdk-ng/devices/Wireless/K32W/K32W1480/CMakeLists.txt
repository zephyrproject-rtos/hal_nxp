# Copyright 2024 NXP
#  
#
# SPDX-License-Identifier: BSD-3-Clause

#### device spepcific drivers
include(${SdkRootDirPath}/devices/arm/device_header.cmake)
mcux_add_cmakelists(${SdkRootDirPath}/${device_root}/Wireless/K32W/K32W1480/drivers)

#### Wireless shared drivers/components/middlewares, project segments
include(${SdkRootDirPath}/devices/Wireless/shared.cmake)
