# Copyright 2024 NXP
# All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause

#### chip related
include(${SdkRootDirPath}/devices/LPC/variable.cmake)
mcux_set_variable(device LPC804)
mcux_set_variable(device_root devices)
mcux_set_variable(soc_series LPC800)
mcux_set_variable(soc_periph periph5)
mcux_set_variable(core_id_suffix_name "")
mcux_set_variable(multicore_foldername .)

#### Source record
