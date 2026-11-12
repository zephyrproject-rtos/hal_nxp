if(CONFIG_MCUX_COMPONENT_device.boot_header)
    mcux_add_source(
        SOURCES fsl_boot_container.c
                fsl_boot_container.h
    )

    mcux_add_include(
        INCLUDES .
    )
endif()
