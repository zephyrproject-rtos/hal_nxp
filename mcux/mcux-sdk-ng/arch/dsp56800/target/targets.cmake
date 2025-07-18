# Copyright 2025 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if (CONFIG_MCUX_PRJSEG_module.board.suite)
    mcux_add_codewarrior_configuration(
            TARGETS flash_sdm_spm_debug flash_sdm_spm_release
                    flash_sdm_lpm_debug flash_sdm_lpm_release
                    flash_sdm_hpm_debug flash_sdm_hpm_release
            AS "-data 16"
    )

    mcux_add_codewarrior_configuration(
            TARGETS flash_ldm_lpm_debug flash_ldm_lpm_release
                    flash_ldm_hpm_debug flash_ldm_hpm_release
            AS "-data 24"
            CC "-ldata -globalsInLowerMemory"
            LD "-ldata"
    )

    mcux_add_codewarrior_configuration(
            TARGETS flash_sdm_spm_debug flash_sdm_spm_release
            AS "-prog 16"
            CC "-sprog"
    )

    mcux_add_codewarrior_configuration(
            TARGETS flash_sdm_lpm_debug flash_sdm_lpm_release
                    flash_ldm_lpm_debug flash_ldm_lpm_release
            AS "-prog 19"
    )

    mcux_add_codewarrior_configuration(
            TARGETS flash_sdm_hpm_debug flash_sdm_hpm_release
                    flash_ldm_hpm_debug flash_ldm_hpm_release
            AS "-prog 21"
            CC "-hprog"
    )

    mcux_add_codewarrior_configuration(
            TARGETS flash_sdm_spm_debug
                    flash_sdm_lpm_debug
                    flash_sdm_hpm_debug
                    flash_ldm_lpm_debug
                    flash_ldm_hpm_debug
            CC "-opt level=1 -opt speed"
    )

    mcux_add_codewarrior_configuration(
            TARGETS flash_sdm_spm_release
                    flash_sdm_lpm_release
                    flash_sdm_hpm_release
                    flash_ldm_lpm_release
                    flash_ldm_hpm_release
            AS "-nodebug_workaround"
            CC "-nopadpipe -opt level=4 -opt speed"
    )
endif()