if (CONFIG_MCUX_COMPONENT_board.boot_header)
    mcux_add_source(
        SOURCES ${board}_flexspi_nor_config.c
                ${board}_flexspi_nor_config.h
    )

    mcux_add_include(
        INCLUDES .
    )
endif()
