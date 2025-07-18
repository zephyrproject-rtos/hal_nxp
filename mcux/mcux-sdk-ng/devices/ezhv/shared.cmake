# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

# core related
include(${SdkRootDirPath}/arch/riscv/core/core_${CONFIG_MCUX_HW_CORE}.cmake)

# build target related
include(${SdkRootDirPath}/arch/riscv/target/targets.cmake)
