# Copyright 2024 NXP
# All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause

#### chip related
include(${SdkRootDirPath}/devices/Kinetis/variable.cmake)
mcux_set_variable(device K32L3A60)
mcux_set_variable(device_root devices)
mcux_set_variable(soc_series K32L)
mcux_set_variable(soc_periph periph3)

if (NOT DEFINED core_id)
    message(FATAL_ERROR "Please specify core_id for multicore device.")
endif()

include(${SdkRootDirPath}/${device_root}/Kinetis/K32L/K32L3A60/${core_id}/variable.cmake)

#### Source record
