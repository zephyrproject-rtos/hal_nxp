if (CONFIG_MCUX_COMPONENT_driver.nic301)
    mcux_component_version(2.0.1)

    mcux_add_source(
        SOURCES fsl_nic301.h
    )

    mcux_add_include(
        INCLUDES .
    )
endif()