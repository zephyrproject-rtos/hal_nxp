# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.mipi_dsi_smartdma)
    mcux_component_version(2.3.2)

    mcux_add_source(SOURCES fsl_mipi_dsi_smartdma.c fsl_mipi_dsi_smartdma.h)

    mcux_add_include(INCLUDES .)

endif()

if(CONFIG_MCUX_COMPONENT_driver.mipi_dsi)
    mcux_component_version(2.2.2)

    mcux_add_source(SOURCES fsl_mipi_dsi.c fsl_mipi_dsi.h)

    mcux_add_include(INCLUDES .)

endif()
