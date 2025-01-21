# Copyright 2024 NXP
# All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause

#### chip related
include(${SdkRootDirPath}/devices/LPC/variable.cmake)
mcux_set_variable(device LPC55S66)
mcux_set_variable(soc_series LPC5500)
mcux_set_variable(soc_periph periph)

if (NOT DEFINED core_id)
    message(FATAL_ERROR "Please specify core_id for multicore device.")
endif()

include(${SdkRootDirPath}/devices/LPC/LPC5500/LPC55S66/${core_id}/variable.cmake)

#### Source record
