# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

# device spepcific files
include(${SdkRootDirPath}/devices/ezhv/device_header_ezhv.cmake)

# middlewares and components
include(${SdkRootDirPath}/devices/ezhv/shared.cmake)

# common configuration
include(${SdkRootDirPath}/arch/riscv/configuration/common.cmake)
