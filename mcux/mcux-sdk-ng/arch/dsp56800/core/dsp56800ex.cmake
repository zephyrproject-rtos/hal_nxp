# Copyright 2024-2025 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

# dsc_common_settings => ps.config.dsc.shared
if (CONFIG_MCUX_PRJSEG_config.dsp56800.ex)
    mcux_add_codewarrior_configuration(
        AS "-v3"
        CC "-v3"
        LD "-v3"
    )

    mcux_add_codewarrior_configuration(
        CC "-D__CORE_56800EX__"
    )

    mcux_add_codewarrior_configuration(
        TARGETS flash_sdm_spm_debug flash_sdm_spm_release
        LD "-l\"${MCUToolsBaseDir}/DSP56800x_EABI_Tools/lib/spm/sdm/o4p/librt.lib\" \
            -l\"${MCUToolsBaseDir}/DSP56800x_EABI_Tools/lib/spm/sdm/o4p/libc.lib\""
    )
    mcux_add_codewarrior_configuration(
        TARGETS flash_sdm_lpm_debug flash_sdm_lpm_release
        LD "-l\"${MCUToolsBaseDir}/DSP56800x_EABI_Tools/lib/lpm/sdm/o4p/librt.lib\" \
            -l\"${MCUToolsBaseDir}/DSP56800x_EABI_Tools/lib/lpm/sdm/o4p/libc.lib\""
    )
    mcux_add_codewarrior_configuration(
        TARGETS flash_sdm_hpm_debug flash_sdm_hpm_release
        LD "-l\"${MCUToolsBaseDir}/DSP56800x_EABI_Tools/lib/hpm/sdm/o4p/librt.lib\" \
            -l\"${MCUToolsBaseDir}/DSP56800x_EABI_Tools/lib/hpm/sdm/o4p/libc.lib\""
    )
    mcux_add_codewarrior_configuration(
        TARGETS flash_ldm_lpm_debug flash_ldm_lpm_release
        LD "-l\"${MCUToolsBaseDir}/DSP56800x_EABI_Tools/lib/lpm/ldm/o4p/librt.lib\" \
            -l\"${MCUToolsBaseDir}/DSP56800x_EABI_Tools/lib/lpm/ldm/o4p/libc.lib\""
    )
    mcux_add_codewarrior_configuration(
        TARGETS flash_ldm_hpm_debug flash_ldm_hpm_release
        LD "-l\"${MCUToolsBaseDir}/DSP56800x_EABI_Tools/lib/hpm/ldm/o4p/librt.lib\" \
            -l\"${MCUToolsBaseDir}/DSP56800x_EABI_Tools/lib/hpm/ldm/o4p/libc.lib\""
    )
endif()