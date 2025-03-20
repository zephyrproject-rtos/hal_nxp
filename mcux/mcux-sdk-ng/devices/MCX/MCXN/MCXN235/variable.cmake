# Copyright 2024 NXP
# All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause

#### chip related
include(${SdkRootDirPath}/devices/MCX/variable.cmake)
mcux_set_variable(device MCXN235)
mcux_set_variable(soc_series MCXN)
mcux_set_variable(soc_periph periph1)
mcux_set_variable(core_id_suffix_name "")
mcux_set_variable(multicore_foldername .)

#### Source record
