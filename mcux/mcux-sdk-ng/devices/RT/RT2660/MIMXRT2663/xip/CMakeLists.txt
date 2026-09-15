if(CONFIG_MCUX_COMPONENT_device.boot_header)
    mcux_add_source(
        SOURCES fsl_xspi_nor_boot.c
                fsl_xspi_nor_boot.h
    )

    mcux_add_include(
        INCLUDES .
    )
endif()
