if (CONFIG_MCUX_COMPONENT_driver.romapi)
    mcux_component_version(1.1.0)

    mcux_add_source(
        SOURCES fsl_romapi.c
                fsl_romapi.h
    )

    mcux_add_include(
        INCLUDES .
    )
endif()