# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if (CONFIG_MCUX_PRJSEG_module.board.suite)
    mcux_add_codewarrior_configuration(
            TARGETS flash_sdm_hpm_debug
            AS "-data 16 -prog 21"
            CC "-opt level=1 -hprog -D__SDM__ -D__HPM__"
            LD "-l\"${MCUToolsBaseDir}/DSP56800x_EABI_Tools/lib/hpm/sdm/o4p/librt.lib\" \
                 -l\"${MCUToolsBaseDir}/DSP56800x_EABI_Tools/lib/hpm/sdm/o4p/libc.lib\""
    )

    mcux_add_codewarrior_configuration(
            TARGETS flash_sdm_hpm_release
            AS "-data 16 -prog 21 -nodebug_workaround "
            CC "-opt level=4 -hprog -D__SDM__ -D__HPM__ -DNDEBUG"
            LD "-l\"${MCUToolsBaseDir}/DSP56800x_EABI_Tools/lib/hpm/sdm/o4p/librt.lib\" \
                 -l\"${MCUToolsBaseDir}/DSP56800x_EABI_Tools/lib/hpm/sdm/o4p/libc.lib\""
    )

    mcux_add_codewarrior_linker_script(
            TARGETS flash_sdm_hpm_debug flash_sdm_hpm_release
            BASE_PATH ${SdkRootDirPath}
            LINKER devices/${soc_portfolio}/${soc_series}/${device}/codewarrior/${device}_Internal_PFlash_SDM.cmd
    )
endif()