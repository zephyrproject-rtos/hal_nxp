# Copyright 2024 NXP
# All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause

mcux_set_variable(device_root devices)

include(${SdkRootDirPath}/${device_root}/MCX/MCXL/variable.cmake)
mcux_set_variable(device MCXL255)

if (NOT DEFINED core_id)
    message(FATAL_ERROR "Please specify core_id for multicore device like -Dcore_id=cm33 or -Dcore_id=cm0plus")
endif()

include(${CMAKE_CURRENT_LIST_DIR}/${core_id}/variable.cmake)

