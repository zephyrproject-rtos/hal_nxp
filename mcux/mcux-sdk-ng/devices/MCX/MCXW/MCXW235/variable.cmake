# Copyright 2024-2025 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

#### chip related
include(${SdkRootDirPath}/devices/MCX/variable.cmake)
mcux_set_variable(device MCXW235)
mcux_set_variable(device_root devices)
mcux_set_variable(soc_series MCXW)
mcux_set_variable(soc_periph periph4)
mcux_set_variable(multicore_foldername .)

#### Source record
