# Copyright 2024-2025 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.lpi2c_edma)
    mcux_component_version(2.4.5)

    mcux_add_source(SOURCES fsl_lpi2c_edma.c fsl_lpi2c_edma.h)

    mcux_add_include(INCLUDES .)

endif()

if(CONFIG_MCUX_COMPONENT_driver.lpi2c)
    mcux_component_version(2.6.2)

    mcux_add_source(SOURCES fsl_lpi2c.c fsl_lpi2c.h)

    mcux_add_include(INCLUDES .)

endif()
