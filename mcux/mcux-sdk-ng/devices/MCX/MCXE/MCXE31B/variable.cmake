# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

#### chip related
include(${SdkRootDirPath}/devices/MCX/variable.cmake)
mcux_set_variable(device_root devices)
mcux_set_variable(device MCXE31B)
mcux_set_variable(soc_series MCXE)
mcux_set_variable(soc_periph periph1)
mcux_set_variable(core_id_suffix_name "")
mcux_set_variable(multicore_foldername .)
#### Source record
