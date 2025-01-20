# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if (CONFIG_MCUX_PRJSEG_module.board.suite)
    mcux_add_codewarrior_configuration(
            TARGETS flash_sdm_spm_debug
            AS "-data 16 -prog 16"
            CC "-opt level=1 -sprog -D__SDM__ -D__SPM__"
            LD "-l\"${MCUToolsBaseDir}/DSP56800x_EABI_Tools/lib/spm/sdm/o4p/librt.lib\" \
                 -l\"${MCUToolsBaseDir}/DSP56800x_EABI_Tools/lib/spm/sdm/o4p/libc.lib\""
    )

    mcux_add_codewarrior_configuration(
            TARGETS flash_sdm_spm_release
            AS "-data 16 -prog 16 -nodebug_workaround"
            CC "-opt level=4 -sprog -nopadpipe -D__SDM__ -D__SPM__ -DNDEBUG"
            LD "-l\"${MCUToolsBaseDir}/DSP56800x_EABI_Tools/lib/spm/sdm/o4p/librt.lib\" \
                 -l\"${MCUToolsBaseDir}/DSP56800x_EABI_Tools/lib/spm/sdm/o4p/libc.lib\""
    )

    mcux_add_codewarrior_linker_script(
            TARGETS flash_sdm_spm_debug flash_sdm_spm_release
            BASE_PATH ${SdkRootDirPath}
            LINKER devices/${soc_portfolio}/${soc_series}/${device}/codewarrior/${device}_Internal_PFlash_SDM.cmd
    )
endif()