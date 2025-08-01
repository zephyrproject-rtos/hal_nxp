# Copyright 2024 NXP
# All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause

#### device spepcific drivers
include(${SdkRootDirPath}/devices/arm/device_header.cmake)
mcux_add_cmakelists(${SdkRootDirPath}/${device_root}/LPC/LPC54000/LPC54S018M/drivers)

#### LPC shared drivers/components/middlewares, project segments
include(${SdkRootDirPath}/devices/LPC/shared.cmake)
