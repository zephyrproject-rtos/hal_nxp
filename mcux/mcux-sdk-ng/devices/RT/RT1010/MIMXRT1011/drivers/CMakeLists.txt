if (CONFIG_MCUX_COMPONENT_driver.clock)
    mcux_component_version(2.5.3)

    mcux_add_source(
        SOURCES fsl_clock.h
                fsl_clock.c
    )

    mcux_add_include(
        INCLUDES .
    )

endif()

if (CONFIG_MCUX_COMPONENT_driver.iomuxc)
    mcux_component_version(2.0.4)

    mcux_add_source(
        SOURCES fsl_iomuxc.h
    )

    mcux_add_include(
        INCLUDES .
    )

endif()

mcux_add_cmakelists(${CMAKE_CURRENT_LIST_DIR}/../../../RT1050/MIMXRT1052/drivers/flexram)
mcux_add_cmakelists(${CMAKE_CURRENT_LIST_DIR}/../../../RT1020/MIMXRT1021/drivers/nic301)