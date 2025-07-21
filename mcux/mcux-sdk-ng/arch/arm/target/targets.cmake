# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if (CONFIG_MCUX_PRJSEG_module.board.suite)

mcux_add_iar_configuration(
    TARGETS debug
            flash_debug
            flexspi_nor_debug
            flexspi_nor_sdram_debug
            flexspi_nor_hyperram_debug
            sdram_debug
            sdram_txt_debug
            hyperram_debug
            hyperram_txt_debug
            ram_0x1400_debug
            ddr_debug
    AS "-r"
    CC "-On --debug --no_cse --no_unroll --no_inline --no_code_motion --no_tbaa --no_clustering --no_scheduling"
    CX "--debug --no_cse --no_unroll --no_code_motion --no_tbaa --no_clustering --no_scheduling"
)

mcux_add_iar_configuration(
    TARGETS release
            flash_release
            flexspi_nor_release
            flexspi_nor_sdram_release
            flexspi_nor_hyperram_release
            sdram_release
            sdram_txt_release
            hyperram_release
            hyperram_txt_release
            ram_0x1400_release
            ddr_release
    CC "-Oh"
    CX "-Oh"
)

mcux_add_mdk_configuration(
    TARGETS debug
            flash_debug
            flexspi_nor_debug
            flexspi_nor_sdram_debug
            flexspi_nor_hyperram_debug
            sdram_debug
            sdram_txt_debug
            hyperram_debug
            hyperram_txt_debug
            ram_0x1400_debug
            ddr_debug
    AS "-g"
    CC "-g -O1"
    CX "-g -O1"
)

mcux_add_mdk_configuration(
    TARGETS release
            flash_release
            flexspi_nor_release
            flexspi_nor_sdram_release
            flexspi_nor_hyperram_release
            sdram_release
            sdram_txt_release
            hyperram_release
            hyperram_txt_release
            ram_0x1400_release
            ddr_release
    CC "-Oz"
    CX "-Oz"
)

mcux_add_armgcc_configuration(
    TARGETS debug
            flash_debug
            flexspi_nor_debug
            flexspi_nor_sdram_debug
            flexspi_nor_hyperram_debug
            sdram_debug
            sdram_txt_debug
            hyperram_debug
            hyperram_txt_debug
            ram_0x1400_debug
            ddr_debug
    AS "-g"
    CC "-g -O0"
    CX "-g -O0"
    LD "-g"
)

mcux_add_armgcc_configuration(
    TARGETS release
            flash_release
            flexspi_nor_release
            flexspi_nor_sdram_release
            flexspi_nor_hyperram_release
            sdram_release
            sdram_txt_release
            hyperram_release
            hyperram_txt_release
            ram_0x1400_release
            ddr_release
    CC "-Os"
    CX "-Os"
)

endif()