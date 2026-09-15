# Copyright 2026 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

#### device specific drivers
include(${SdkRootDirPath}/devices/arm/device_header_multicore.cmake)
include(${SdkRootDirPath}/devices/arm/device_header_multicore_cstartup.cmake)

if (CONFIG_MCUX_COMPONENT_CMSIS_Include_core_ca)
    mcux_add_include(BASE_PATH ${ACoreCmsisDirPath}/Core_AArch64/Include INCLUDES .)
endif()