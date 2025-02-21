# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.vspi_dma)
    mcux_component_version(2.0.3)

    mcux_add_source(SOURCES fsl_spi_dma.c fsl_spi_dma.h)

    mcux_add_include(INCLUDES .)

endif()

if(CONFIG_MCUX_COMPONENT_driver.vspi)
    mcux_component_version(2.0.6)

    mcux_add_source(SOURCES fsl_spi.c fsl_spi.h)

    mcux_add_include(INCLUDES .)

endif()
