# Copyright 2024-2025 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.lpuart_dma)
    mcux_component_version(2.6.0)

    mcux_add_source(SOURCES fsl_lpuart_dma.h fsl_lpuart_dma.c)

    mcux_add_include(INCLUDES .)

endif()

if(CONFIG_MCUX_COMPONENT_driver.lpuart_edma)
    mcux_component_version(2.6.0)

    mcux_add_source(SOURCES fsl_lpuart_edma.h fsl_lpuart_edma.c)

    mcux_add_include(INCLUDES .)

endif()

if(CONFIG_MCUX_COMPONENT_driver.lpuart)
    mcux_component_version(2.9.1)

    mcux_add_source(SOURCES fsl_lpuart.h fsl_lpuart.c)

    mcux_add_include(INCLUDES .)

endif()
