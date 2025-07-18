# Copyright 2024 NXP
# All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause

#### chip related
include(${SdkRootDirPath}/devices/i.MX/variable.cmake)
mcux_set_variable(device MIMX8UD5)
mcux_set_variable(device_root devices)
mcux_set_variable(soc_series i.MX8ULP)
mcux_set_variable(soc_periph periph)

if (NOT DEFINED core_id)
    message(FATAL_ERROR "Please specify core_id for multicore device.")
endif()

include(${SdkRootDirPath}/devices/i.MX/i.MX8ULP/MIMX8UD5/${core_id}/variable.cmake)

#### Source record
