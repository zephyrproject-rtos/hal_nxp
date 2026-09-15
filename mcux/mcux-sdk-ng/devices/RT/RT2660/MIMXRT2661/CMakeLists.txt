# Copyright 2025 NXP
# All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
include(${SdkRootDirPath}/devices/arm/device_header_cstartup.cmake)
# XIP related
# mcux_add_cmakelists(${CMAKE_CURRENT_LIST_DIR}/xip)

# device specific drivers
mcux_add_cmakelists(${CMAKE_CURRENT_LIST_DIR}/drivers)

include(${SdkRootDirPath}/devices/RT/shared.cmake)

