if (CONFIG_MCUX_COMPONENT_driver.anatop_ai)
    mcux_component_version(1.0.0)

    mcux_add_source(
        SOURCES fsl_anatop_ai.c
                fsl_anatop_ai.h
    )

    mcux_add_include(
        INCLUDES .
    )

endif()
