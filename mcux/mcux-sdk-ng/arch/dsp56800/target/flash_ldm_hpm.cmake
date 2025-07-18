# Copyright 2024-2025 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if (CONFIG_MCUX_PRJSEG_module.board.suite)
    mcux_add_codewarrior_linker_script(
            TARGETS flash_ldm_hpm_debug flash_ldm_hpm_release
            BASE_PATH ${SdkRootDirPath}
            LINKER ${device_root}/${soc_portfolio}/${soc_series}/${device}/codewarrior/${CONFIG_MCUX_TOOLCHAIN_LINKER_DEVICE_PREFIX}_Internal_PFlash_LDM.cmd
    )
endif()
