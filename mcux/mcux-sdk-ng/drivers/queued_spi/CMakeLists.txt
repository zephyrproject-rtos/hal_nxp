# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.queued_spi_dma)
    mcux_component_version(2.0.0)

    mcux_add_source(SOURCES fsl_queued_spi_dma.h fsl_queued_spi_dma.c)

    mcux_add_include(INCLUDES .)

endif()

if(CONFIG_MCUX_COMPONENT_driver.queued_spi_edma)
    mcux_component_version(2.0.0)

    mcux_add_source(SOURCES fsl_queued_spi_edma.h fsl_queued_spi_edma.c)

    mcux_add_include(INCLUDES .)

endif()

if(CONFIG_MCUX_COMPONENT_driver.queued_spi)
    mcux_component_version(2.1.1)

    mcux_add_source(SOURCES fsl_queued_spi.h fsl_queued_spi.c)

    mcux_add_include(INCLUDES .)

endif()
