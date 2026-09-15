# Copyright 2024, 2026 NXP
# All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause

#### chip related
include(${SdkRootDirPath}/devices/i.MX/variable.cmake)
mcux_set_variable(device MIMX9596)
mcux_set_variable(device_root devices)
mcux_set_variable(soc_series i.MX95)

mcux_set_variable(soc_periph periph)

if (NOT DEFINED core_id)
    mcux_set_variable(core_id cm7)
endif()

include(${SdkRootDirPath}/devices/i.MX/${soc_series}/${device}/${core_id}/variable.cmake)

#### Source record
