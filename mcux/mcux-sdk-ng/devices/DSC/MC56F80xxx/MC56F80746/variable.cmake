# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

#### chip related
include(${SdkRootDirPath}/devices/DSC/variable.cmake)
mcux_set_variable(device_root devices)
mcux_set_variable(device MC56F80746)
mcux_set_variable(soc_series MC56F80xxx)
mcux_set_variable(soc_periph periph)
mcux_set_variable(core_id_suffix_name "")
mcux_set_variable(multicore_foldername .)
