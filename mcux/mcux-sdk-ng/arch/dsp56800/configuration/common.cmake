# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

# dsc_common_settings => ps.config.dsc.shared
if (CONFIG_MCUX_PRJSEG_config.dsp56800.shared)
    mcux_add_codewarrior_configuration(
            CC "-msgstyle parseable -lang c99 -nostrict-align -globalsInLowerMemory -g -requireprotos -D__DSC__ -D__CW__ -DMCUXPRESSO_SDK -DMCUX_META_BUILD"
            LD "-msgstyle parseable -map -main F_EntryPoint -nostdlib -g"
            AS "-msgstyle parseable -debug -nosyspath"
    )

    mcux_add_codewarrior_configuration(
            TARGETS flash_sdm_lpm_debug flash_ldm_lpm_debug 
            CC "-opt level=1"
    )
    mcux_add_codewarrior_configuration(
            TARGETS  flash_sdm_lpm_release flash_ldm_lpm_release
            CC "-opt level=4 -DNDEBUG -nopadpipe"
            AS "-nodebug_workaround"
    )

    mcux_add_codewarrior_configuration(
            TARGETS flash_sdm_lpm_debug flash_sdm_lpm_release 
            CC "-D__SDM__"
            AS "-data 16 -prog 19"
    )
    mcux_add_codewarrior_configuration(
            TARGETS flash_ldm_lpm_debug flash_ldm_lpm_release 
            CC "-D__LDM__ -ldata"
            LD "-ldata"
            AS "-data 24 -prog 19"
    )
    mcux_add_codewarrior_configuration(
            TARGETS flash_sdm_lpm_debug flash_sdm_lpm_release
                    flash_ldm_lpm_debug flash_ldm_lpm_release 
            CC "-D__LPM__"
    )

    mcux_add_codewarrior_configuration(
            CC "-opt speed"
    )

    mcux_add_codewarrior_sys_include(
        SYS_SEARCH_PATH "\"${MCUToolsBaseDir}/DSP56800x_EABI_Tools/M56800E Support/runtime_56800E/include\""
                                "\"${MCUToolsBaseDir}/DSP56800x_EABI_Tools/M56800E Support/msl/MSL_C/MSL_Common/Include\""
                                "\"${MCUToolsBaseDir}/DSP56800x_EABI_Tools/M56800E Support/msl/MSL_C/DSP_56800E/prefix\""
        SYS_PATH_RECURSIVELY "\"${MCUToolsBaseDir}/DSP56800x_EABI_Tools/M56800E Support\""
    )
endif()