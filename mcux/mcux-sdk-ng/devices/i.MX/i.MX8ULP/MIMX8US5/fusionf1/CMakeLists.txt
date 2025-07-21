# Copyright 2024 NXP
# All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause

#### device spepcific drivers
include(${SdkRootDirPath}/devices/xtensa/device_header_dsp.cmake)

# middlewares and components
include(${SdkRootDirPath}/devices/xtensa/shared.cmake)

# common configuration
include(${SdkRootDirPath}/arch/xtensa/configuration/common.cmake)
