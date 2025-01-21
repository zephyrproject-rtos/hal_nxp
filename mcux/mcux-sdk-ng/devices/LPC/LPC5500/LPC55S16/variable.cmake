# Copyright 2024 NXP
# All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause

#### chip related
include(${SdkRootDirPath}/devices/LPC/variable.cmake)
mcux_set_variable(device LPC55S16)
mcux_set_variable(soc_series LPC5500)
mcux_set_variable(soc_periph periph2)
mcux_set_variable(core_id_suffix_name "")
mcux_set_variable(multicore_foldername .)

#### Source record
