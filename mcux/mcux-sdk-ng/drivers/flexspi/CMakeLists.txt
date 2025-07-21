# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.flexspi_dma)
    mcux_component_version(2.2.1)

    mcux_add_source(SOURCES fsl_flexspi_dma.c fsl_flexspi_dma.h)

    mcux_add_include(INCLUDES .)

endif()

if(CONFIG_MCUX_COMPONENT_driver.flexspi_edma)
    mcux_component_version(2.3.3)

    mcux_add_source(SOURCES fsl_flexspi_edma.c fsl_flexspi_edma.h)

    mcux_add_include(INCLUDES .)

endif()

if(CONFIG_MCUX_COMPONENT_driver.flexspi)
    mcux_component_version(2.7.0)

    mcux_add_source(SOURCES fsl_flexspi.c fsl_flexspi.h)

    mcux_add_include(INCLUDES .)

endif()
