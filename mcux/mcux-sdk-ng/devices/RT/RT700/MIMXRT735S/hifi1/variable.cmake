# Copyright 2024 NXP
# All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause

#### Source record
mcux_set_variable(core_id_suffix_name _hifi1)
mcux_set_variable(multicore_foldername hifi1)
if(NOT XTENSA_CORE)
    mcux_set_variable(XTENSA_CORE rt700_hifi1_RI23_11_nlib)
endif()

mcux_set_variable(XTENSA_LSP_DEBUG ${SdkRootDirPath}/${device_root}/RT/RT700/MIMXRT735S/xtensa/hifi1/gdbio)
mcux_set_variable(XTENSA_LSP_RELEASE ${SdkRootDirPath}/${device_root}/RT/RT700/MIMXRT735S/xtensa/hifi1/min-rt)