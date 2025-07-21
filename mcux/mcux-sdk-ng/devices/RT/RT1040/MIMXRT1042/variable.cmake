# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

#### chip related
include(${SdkRootDirPath}/devices/RT/variable.cmake)
mcux_set_variable(device MIMXRT1042)
mcux_set_variable(device_root devices)
mcux_set_variable(soc_series RT1040)
mcux_set_variable(soc_periph periph)

mcux_set_variable(core_id_suffix_name "")
