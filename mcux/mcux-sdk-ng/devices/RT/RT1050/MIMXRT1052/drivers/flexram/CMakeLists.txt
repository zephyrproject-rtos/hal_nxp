if (CONFIG_MCUX_COMPONENT_driver.flexram_allocate)
    mcux_component_version(2.0.2)

    mcux_add_source(
        SOURCES fsl_flexram_allocate.c
                fsl_flexram_allocate.h
    )

    mcux_add_include(
        INCLUDES .
    )
endif()
