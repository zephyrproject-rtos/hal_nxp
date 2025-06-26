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

    mcux_add_source(
        BASE_PATH ${CMAKE_CURRENT_LIST_DIR}/..
        SOURCES xmcd.c
                xmcd.h
    )
endif()
