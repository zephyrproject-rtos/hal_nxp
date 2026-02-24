# Copyright 2026 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

#### chip related
include(${SdkRootDirPath}/devices/i.MX/variable.cmake)
mcux_set_variable(device MIMX93W52)
mcux_set_variable(device_root devices)
mcux_set_variable(soc_series i.MX93W)
mcux_set_variable(soc_periph periph)
mcux_set_variable(core_id_suffix_name "_cm33")
mcux_set_variable(multicore_foldername .)

#### Source record
