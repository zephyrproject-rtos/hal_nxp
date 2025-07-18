# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

#### chip related
include(${SdkRootDirPath}/devices/RT/variable.cmake)
mcux_set_variable(device MIMXRT1176)
mcux_set_variable(device_root devices)
mcux_set_variable(soc_series RT1170)
mcux_set_variable(soc_periph periph)

if (NOT DEFINED core_id)
    message(FATAL_ERROR "Please specify core_id for multicore device.")
endif()

include(${CMAKE_CURRENT_LIST_DIR}/${core_id}/variable.cmake)

