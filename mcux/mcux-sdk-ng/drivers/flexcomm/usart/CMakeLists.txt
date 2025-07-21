# Copyright 2024-2025 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.flexcomm_usart_dma)
    mcux_component_version(2.3.1)

    mcux_add_source(SOURCES fsl_usart_dma.h fsl_usart_dma.c)

    mcux_add_include(INCLUDES .)

endif()

if(CONFIG_MCUX_COMPONENT_driver.flexcomm_usart)
    mcux_component_version(2.8.5)

    mcux_add_source(SOURCES fsl_usart.h fsl_usart.c)

    mcux_add_include(INCLUDES .)

endif()
