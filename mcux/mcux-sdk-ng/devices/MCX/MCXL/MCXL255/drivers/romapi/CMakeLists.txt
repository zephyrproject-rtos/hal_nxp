if (CONFIG_MCUX_COMPONENT_driver.romapi)
    mcux_component_version(2.0.1)
    mcux_add_source(
        SOURCES
            ./fsl_romapi.h
    )

    mcux_add_include(
        INCLUDES .
    )

endif()
