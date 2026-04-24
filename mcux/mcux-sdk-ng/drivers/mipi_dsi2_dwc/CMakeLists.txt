# Copyright 2025-2026 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.mipi_dsi2_dwc)
    mcux_component_version(2.1.0)

    mcux_add_source(
        SOURCES
        fsl_mipi_dsi.c
        fsl_mipi_dsi.h
        fsl_mipi_dsi2_dwc_dphy.c
        fsl_mipi_dsi2_dwc_dphy.h
    )

    mcux_add_include(INCLUDES .)

endif()
