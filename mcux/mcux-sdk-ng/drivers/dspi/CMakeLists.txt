# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.dspi_dma)
    mcux_component_version(2.2.5)

    mcux_add_source(SOURCES fsl_dspi_dma.h fsl_dspi_dma.c)

    mcux_add_include(INCLUDES .)

endif()

if(CONFIG_MCUX_COMPONENT_driver.dspi_edma)
    mcux_component_version(2.2.7)

    mcux_add_source(SOURCES fsl_dspi_edma.h fsl_dspi_edma.c)

    mcux_add_include(INCLUDES .)

endif()

if(CONFIG_MCUX_COMPONENT_driver.dspi)
    mcux_component_version(2.2.7)

    mcux_add_source(SOURCES fsl_dspi.h fsl_dspi.c)

    mcux_add_include(INCLUDES .)

endif()
