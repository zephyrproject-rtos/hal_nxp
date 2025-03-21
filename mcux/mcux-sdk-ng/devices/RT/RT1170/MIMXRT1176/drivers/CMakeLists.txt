if (CONFIG_MCUX_COMPONENT_driver.clock)
    mcux_component_version(2.5.6)

    mcux_add_source(
        SOURCES fsl_clock.h
                fsl_clock.c
    )

    mcux_add_include(
        INCLUDES .
    )

endif()

if (CONFIG_MCUX_COMPONENT_driver.iomuxc)
    mcux_component_version(2.0.2)

    mcux_add_source(
        SOURCES fsl_iomuxc.h
    )

    mcux_add_include(
        INCLUDES .
    )

endif()

if (CONFIG_MCUX_COMPONENT_driver.mipi_csi2rx_soc)
    mcux_component_version(2.0.2)

    mcux_add_source(
        SOURCES fsl_soc_mipi_csi2rx.c
                fsl_soc_mipi_csi2rx.h
    )

    mcux_add_include(
        INCLUDES .
    )

endif()

if (CONFIG_MCUX_COMPONENT_driver.mipi_dsi_soc)
    mcux_component_version(2.0.0)

    mcux_add_source(
        SOURCES fsl_soc_mipi_dsi.h
    )

    mcux_add_include(
        INCLUDES .
    )

endif()

mcux_add_cmakelists(${CMAKE_CURRENT_LIST_DIR}/anatop_ai)
mcux_add_cmakelists(${CMAKE_CURRENT_LIST_DIR}/memory)
mcux_add_cmakelists(${CMAKE_CURRENT_LIST_DIR}/nic301)
mcux_add_cmakelists(${CMAKE_CURRENT_LIST_DIR}/power)
mcux_add_cmakelists(${CMAKE_CURRENT_LIST_DIR}/romapi)
mcux_add_cmakelists(${CMAKE_CURRENT_LIST_DIR}/flexram)
