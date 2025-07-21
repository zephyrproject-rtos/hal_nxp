# Copyright 2024 NXP
# All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause

#### Source record
mcux_set_variable(core_id_suffix_name _dsp0)
mcux_set_variable(multicore_foldername fusionf1)

if(NOT XTENSA_CORE)
    mcux_set_variable(XTENSA_CORE fusion_nxp02_dsp_prod)
endif()

mcux_set_variable(XTENSA_LSP_DEBUG ${SdkRootDirPath}/devices/i.MX/i.MX8ULP/MIMX8US3/xtensa/gdbio)
mcux_set_variable(XTENSA_LSP_RELEASE ${SdkRootDirPath}/devices/i.MX/i.MX8ULP/MIMX8US3/xtensa/min-rt)
