# Copyright 2024-2025 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.lpflexcomm_lpi2c)
    mcux_component_version(2.2.6)

    mcux_add_source(SOURCES fsl_lpi2c.h fsl_lpi2c.c)

    mcux_add_include(INCLUDES .)

endif()

if(CONFIG_MCUX_COMPONENT_driver.lpflexcomm_lpi2c_edma)
    mcux_component_version(2.0.1)

    mcux_add_source(SOURCES fsl_lpi2c_edma.h fsl_lpi2c_edma.c)

    mcux_add_include(INCLUDES .)

endif()
