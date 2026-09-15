# Copyright 2024-2026 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.flexcomm_spi_dma)
    mcux_component_version(2.3.0)

    mcux_add_source(SOURCES fsl_spi_dma.c fsl_spi_dma.h)

    mcux_add_include(INCLUDES .)

endif()

if(CONFIG_MCUX_COMPONENT_driver.flexcomm_spi)
    mcux_component_version(2.4.0)

    mcux_add_source(SOURCES fsl_spi.c fsl_spi.h)

    mcux_add_include(INCLUDES .)

endif()
