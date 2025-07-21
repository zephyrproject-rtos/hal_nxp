# Copyright 2024 NXP
# All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause

#### device spepcific drivers
include(${SdkRootDirPath}/devices/arm/device_header.cmake)
mcux_add_cmakelists(${SdkRootDirPath}/${device_root}/RT/RT600/MIMXRT633S/drivers)

# common configuration
include(${SdkRootDirPath}/arch/arm/configuration/RT.cmake)

# middlewares and components
include(${SdkRootDirPath}/devices/arm/shared.cmake)
