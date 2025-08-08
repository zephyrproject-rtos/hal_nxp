# Copyright 2024-2025 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.flexio_spi_dma)
    mcux_component_version(2.3.0)

    mcux_add_source(SOURCES fsl_flexio_spi_dma.c fsl_flexio_spi_dma.h)

    mcux_add_include(INCLUDES .)

endif()

if(CONFIG_MCUX_COMPONENT_driver.flexio_spi_edma)
    mcux_component_version(2.3.0)

    mcux_add_source(SOURCES fsl_flexio_spi_edma.c fsl_flexio_spi_edma.h)

    mcux_add_include(INCLUDES .)

endif()

if(CONFIG_MCUX_COMPONENT_driver.flexio_spi)
    mcux_component_version(2.4.2)

    mcux_add_source(SOURCES fsl_flexio_spi.c fsl_flexio_spi.h)

    mcux_add_include(INCLUDES .)

endif()
