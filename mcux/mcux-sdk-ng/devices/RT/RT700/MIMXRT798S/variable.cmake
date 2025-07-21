# Copyright 2024 NXP
# All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause

#### chip related
include(${SdkRootDirPath}/devices/RT/variable.cmake)
mcux_set_variable(device MIMXRT798S)
mcux_set_variable(device_root devices)
mcux_set_variable(soc_series RT700)
mcux_set_variable(soc_periph periph)

if (NOT DEFINED core_id)
    message(FATAL_ERROR "Please specify core_id for multicore device.")
endif()

include(${SdkRootDirPath}/${device_root}/RT/RT700/MIMXRT798S/${core_id}/variable.cmake)

#### Source record
