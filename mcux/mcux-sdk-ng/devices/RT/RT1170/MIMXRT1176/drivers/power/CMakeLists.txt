
if (CONFIG_MCUX_COMPONENT_driver.dcdc_2)
    mcux_component_version(2.1.2)

    mcux_add_source(
        SOURCES fsl_dcdc.c
                fsl_dcdc.h
    )

    mcux_add_include(
        INCLUDES .
    )

endif()

if (CONFIG_MCUX_COMPONENT_driver.gpc_xxx_ctrl)
    mcux_component_version(2.5.0)

    mcux_add_source(
        SOURCES fsl_gpc.c
                fsl_gpc.h
    )

    mcux_add_include(
        INCLUDES .
    )

endif()

if (CONFIG_MCUX_COMPONENT_driver.pgmc)
    mcux_component_version(2.1.2)

    mcux_add_source(
        SOURCES fsl_pgmc.h
                fsl_pgmc.c
    )

    mcux_add_include(
        INCLUDES .
    )

endif()

if (CONFIG_MCUX_COMPONENT_driver.anadig_pmu)
    mcux_component_version(2.1.2)

    mcux_add_source(
        SOURCES fsl_pmu.h
                fsl_pmu.c
    )

    mcux_add_include(
        INCLUDES .
    )

endif()

if (CONFIG_MCUX_COMPONENT_driver.src_2)
    mcux_component_version(2.1.1)

    mcux_add_source(
        SOURCES fsl_soc_src.c
                fsl_soc_src.h
    )

    mcux_add_include(
        INCLUDES .
    )

endif()
