# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.i3c_dma)
    mcux_component_version(2.1.7)

    mcux_add_source(SOURCES fsl_i3c_dma.c fsl_i3c_dma.h)

    mcux_add_include(INCLUDES .)

endif()

if(CONFIG_MCUX_COMPONENT_driver.i3c_edma)
    mcux_component_version(2.2.9)

    mcux_add_source(SOURCES fsl_i3c_edma.c fsl_i3c_edma.h)

    mcux_add_include(INCLUDES .)

endif()

if(CONFIG_MCUX_COMPONENT_driver.i3c)
    mcux_component_version(2.13.0)

    mcux_add_source(SOURCES fsl_i3c.h fsl_i3c.c)

    mcux_add_include(INCLUDES .)

endif()
