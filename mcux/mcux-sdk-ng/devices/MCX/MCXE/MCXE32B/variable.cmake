# Copyright 2026 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

#### chip related
include(${SdkRootDirPath}/devices/MCX/variable.cmake)
mcux_set_variable(device_root devices)
mcux_set_variable(device MCXE32B)
mcux_set_variable(soc_series MCXE)
mcux_set_variable(soc_periph periph6)
#### mcux_set_variable(core_id_suffix_name "")
#### mcux_set_variable(multicore_foldername .)
if (NOT DEFINED core_id)
    message(FATAL_ERROR "Please specify core_id for multicore device.")
endif()

include(${SdkRootDirPath}/${device_root}/MCX/MCXE/MCXE32B/${core_id}/variable.cmake)

#### Source record
