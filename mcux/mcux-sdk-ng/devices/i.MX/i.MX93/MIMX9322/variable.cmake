# Copyright 2024 NXP
# All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause

#### chip related
include(${SdkRootDirPath}/devices/i.MX/variable.cmake)
mcux_set_variable(device MIMX9322)
mcux_set_variable(soc_series i.MX93)
mcux_set_variable(soc_periph periph)
mcux_set_variable(core_id_suffix_name "_cm33")
mcux_set_variable(multicore_foldername .)

#### Source record
