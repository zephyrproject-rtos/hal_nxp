# Copyright 2024-2025 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.spi_dma)
    mcux_component_version(2.1.1)

    mcux_add_source(SOURCES fsl_spi_dma.h fsl_spi_dma.c)

    mcux_add_include(INCLUDES .)

endif()

if(CONFIG_MCUX_COMPONENT_driver.spi)
    mcux_component_version(2.1.4)

    mcux_add_source(SOURCES fsl_spi.h fsl_spi.c)

    mcux_add_include(INCLUDES .)

endif()
