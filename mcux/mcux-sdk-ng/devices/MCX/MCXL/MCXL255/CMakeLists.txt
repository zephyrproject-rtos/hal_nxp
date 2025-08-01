# Copyright 2024-2025 NXP
# All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause

include(${SdkRootDirPath}/devices/arm/device_header_multicore.cmake)

#### core related
include(${CMAKE_CURRENT_LIST_DIR}/${core_id}/setting.cmake)

#### device specific drivers
mcux_add_cmakelists(${CMAKE_CURRENT_LIST_DIR}/drivers)

#### MCX shared drivers/components/middlewares, project segments
include(${SdkRootDirPath}/devices/MCX/shared.cmake)
