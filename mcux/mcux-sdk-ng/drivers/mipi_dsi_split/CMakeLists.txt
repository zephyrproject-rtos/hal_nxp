# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.mipi_dsi_split)
    mcux_component_version(2.2.5)

    mcux_add_source(SOURCES fsl_mipi_dsi.c fsl_mipi_dsi.h)

    mcux_add_include(INCLUDES .)

endif()
