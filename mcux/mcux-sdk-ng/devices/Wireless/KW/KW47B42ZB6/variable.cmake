# Copyright 2024 NXP
#  
#
# SPDX-License-Identifier: BSD-3-Clause

#### chip related
include(${SdkRootDirPath}/devices/Wireless/variable.cmake)
mcux_set_variable(device KW47B42ZB6)
mcux_set_variable(device_root devices)
mcux_set_variable(soc_series KW)
mcux_set_variable(soc_periph periph6)

if (NOT DEFINED core_id)
    message(FATAL_ERROR "Please specify core_id for multicore device.")
endif()

include(${SdkRootDirPath}/${device_root}/Wireless/KW/KW47B42ZB6/${core_id}/variable.cmake)

#### Source record
