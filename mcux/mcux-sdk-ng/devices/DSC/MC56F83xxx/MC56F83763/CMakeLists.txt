# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

#### device spepcific drivers
include(${SdkRootDirPath}/devices/dsp56800/device_header.cmake)
mcux_add_cmakelists(${SdkRootDirPath}/${device_root}/DSC/MC56F83xxx/MC56F83763/drivers)

#### DSC shared drivers/components/middlewares, project segments
include(${SdkRootDirPath}/devices/DSC/shared.cmake)
