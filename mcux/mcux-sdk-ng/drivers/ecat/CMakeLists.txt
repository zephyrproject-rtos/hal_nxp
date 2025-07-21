if(CONFIG_MCUX_COMPONENT_driver.ecat)
    mcux_component_version(2.0.0)

    mcux_add_source(SOURCES fsl_ecat.c fsl_ecat.h)

    mcux_add_include(INCLUDES .)

endif()