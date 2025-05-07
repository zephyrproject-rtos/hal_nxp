# Copyright 2025 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

#### device spepcific drivers
include(${SdkRootDirPath}/devices/arm/device_header_multicore.cmake)
mcux_add_include(BASE_PATH ${ACoreCmsisDirPath}/Core_AArch64/Include INCLUDES .)
