# Copyright 2024 NXP
# All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause

#### Source record
mcux_set_variable(core_id_suffix_name _dsp)
mcux_set_variable(multicore_foldername hifi4)

if(NOT XTENSA_CORE)
    mcux_set_variable(XTENSA_CORE nxp_rt600_RI23_11_newlib)
endif()

mcux_set_variable(XTENSA_LSP_DEBUG ${SdkRootDirPath}/devices/RT/RT600/MIMXRT685S/xtensa/gdbio)
mcux_set_variable(XTENSA_LSP_RELEASE ${SdkRootDirPath}/devices/RT/RT600/MIMXRT685S/xtensa/min-rt)
