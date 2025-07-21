# Copyright 2024 NXP
# All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause

#### chip related
include(${SdkRootDirPath}/devices/i.MX/variable.cmake)
mcux_set_variable(device MCIMX7U5)
mcux_set_variable(device_root devices)
mcux_set_variable(soc_series i.MX7ULP)
mcux_set_variable(soc_periph periph)
mcux_set_variable(core_id_suffix_name "")
mcux_set_variable(multicore_foldername .)

#### Source record
