if (CONFIG_MCUX_COMPONENT_board.boot_header)
    mcux_add_source(
        SOURCES ${board}_flexspi_nor_config.c
                ${board}_flexspi_nor_config.h
    )

    mcux_add_include(
        INCLUDES .
    )

    mcux_add_source(
        BASE_PATH ${CMAKE_CURRENT_LIST_DIR}/..
        SOURCES dcd.c
                dcd.h
    )
endif()

if (CONFIG_MCUX_PRJSEG_module.board.suite)

    mcux_add_configuration(
        TARGETS flexspi_nor_debug        flexspi_nor_release
                flexspi_nor_sdram_debug  flexspi_nor_sdram_release
        CC "-DXIP_BOOT_HEADER_ENABLE=1"
    )

    mcux_add_mdk_configuration(
        TARGETS flexspi_nor_debug        flexspi_nor_release
                flexspi_nor_sdram_debug  flexspi_nor_sdram_release
        LD "--predefine=\"-DXIP_BOOT_HEADER_ENABLE=1\""
    )

    mcux_add_configuration(
        TARGETS flexspi_nor_sdram_debug  flexspi_nor_sdram_release
        CC "-DXIP_BOOT_HEADER_DCD_ENABLE=1"
    )

    mcux_add_mdk_configuration(
        TARGETS flexspi_nor_sdram_debug  flexspi_nor_sdram_release
        LD "--predefine=\"-DXIP_BOOT_HEADER_DCD_ENABLE=1\""
    )
endif()
