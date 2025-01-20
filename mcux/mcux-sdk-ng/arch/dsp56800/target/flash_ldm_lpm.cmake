# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if (CONFIG_MCUX_PRJSEG_module.board.suite)
    mcux_add_codewarrior_linker_script(
            TARGETS flash_ldm_lpm_debug flash_ldm_lpm_release
            BASE_PATH ${SdkRootDirPath}
            LINKER devices/${soc_portfolio}/${soc_series}/${device}/codewarrior/${device}_Internal_PFlash_LDM.cmd
    )

endif()
