# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

#### chip related
include(${SdkRootDirPath}/devices/MCX/variable.cmake)
mcux_set_variable(device MCXW727A)
mcux_set_variable(device_root devices)
mcux_set_variable(soc_series MCXW)
mcux_set_variable(soc_periph periph3)

if (NOT DEFINED core_id)
    message(FATAL_ERROR "Please specify core_id for multicore device.")
endif()

include(${SdkRootDirPath}/${device_root}/MCX/MCXW/MCXW727A/${core_id}/variable.cmake)

#### Source record
