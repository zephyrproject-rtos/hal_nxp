# Copyright 2024-2025 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.lcdic_dma)
    mcux_component_version(2.1.0)

    mcux_add_source(SOURCES fsl_lcdic_dma.c fsl_lcdic_dma.h)

    mcux_add_include(INCLUDES .)

endif()

if(CONFIG_MCUX_COMPONENT_driver.lcdic)
    mcux_component_version(2.2.0)

    mcux_add_source(SOURCES fsl_lcdic.h fsl_lcdic.c)

    mcux_add_include(INCLUDES .)

endif()
