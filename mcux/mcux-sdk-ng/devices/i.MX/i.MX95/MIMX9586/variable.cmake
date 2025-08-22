# Copyright 2024 NXP
# All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause

#### chip related
include(${SdkRootDirPath}/devices/i.MX/variable.cmake)
mcux_set_variable(device MIMX9586)
mcux_set_variable(device_root devices)
mcux_set_variable(soc_series i.MX95)

mcux_set_variable(soc_periph periph)
mcux_set_variable(core_id_suffix_name _cm7)
mcux_set_variable(multicore_foldername cm7)
#### Source record
