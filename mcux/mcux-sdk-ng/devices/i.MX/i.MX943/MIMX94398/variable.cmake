# Copyright 2024 NXP
# SPDX-License-Identifier: BSD-3-Clause

#### chip related
include(${SdkRootDirPath}/devices/i.MX/variable.cmake)
mcux_set_variable(soc_series i.MX943)
if (NOT DEFINED device_root)
    mcux_set_variable(device_root devices)
endif()
mcux_set_variable(device MIMX94398)
mcux_set_variable(soc_periph periph)

if (NOT DEFINED core_id)
    message(FATAL_ERROR "Please specify core_id for multicore device.")
endif()

include(${SdkRootDirPath}/devices/i.MX/${soc_series}/${device}/${core_id}/variable.cmake)

#### Source record
