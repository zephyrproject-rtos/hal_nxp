# Copyright 2025 NXP
#
# SPDX-License-Identifier: BSD-3-Clause
include(${SdkRootDirPath}/devices/arm/device_header.cmake)

# device specific drivers
mcux_add_cmakelists(${CMAKE_CURRENT_LIST_DIR}/drivers)

include(${SdkRootDirPath}/devices/RT/shared.cmake)
