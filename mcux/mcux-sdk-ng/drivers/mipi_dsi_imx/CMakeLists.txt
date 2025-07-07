# Copyright 2024-2025 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.mipi_dsi_imx)
    mcux_component_version(2.0.3)

    mcux_add_source(SOURCES fsl_mipi_dsi.c fsl_mipi_dsi.h)

    mcux_add_include(INCLUDES .)

endif()
