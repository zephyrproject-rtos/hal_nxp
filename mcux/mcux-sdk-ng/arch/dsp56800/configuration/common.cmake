# Copyright 2024-2025 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if (CONFIG_MCUX_PRJSEG_config.dsp56800.shared)
    mcux_add_codewarrior_configuration(
        CC "-lang c99 -nostrict-align"
    )
    
    mcux_add_codewarrior_sys_include(
        SYS_SEARCH_PATH "\"${MCUToolsBaseDir}/DSP56800x_EABI_Tools/M56800E Support/runtime_56800E/include\""
                        "\"${MCUToolsBaseDir}/DSP56800x_EABI_Tools/M56800E Support/msl/MSL_C/MSL_Common/Include\""
                        "\"${MCUToolsBaseDir}/DSP56800x_EABI_Tools/M56800E Support/msl/MSL_C/DSP_56800E/prefix\""
        SYS_PATH_RECURSIVELY "\"${MCUToolsBaseDir}/DSP56800x_EABI_Tools/M56800E Support\""
    )

    mcux_add_codewarrior_configuration(
        CC "-D__DSC__ -D__CW__"
    )

    mcux_add_codewarrior_configuration(
        AS "-msgstyle parseable -nosyspath -debug"
        CC "-msgstyle parseable -g -requireprotos"
        LD "-msgstyle parseable -g -nostdlib -main F_EntryPoint -map"
    )

    mcux_add_codewarrior_configuration(
        CC "-w=illpragmas -w=possible -w=extended -w=extracomma -w=emptydecl -w=structclass -w=notinlined"
    )

endif()