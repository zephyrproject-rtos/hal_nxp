# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.vusart_dma)
    mcux_component_version(2.3.0)

    mcux_add_source(SOURCES fsl_usart_dma.h fsl_usart_dma.c)

    mcux_add_include(INCLUDES .)

endif()

if(CONFIG_MCUX_COMPONENT_driver.vusart)
    mcux_component_version(2.3.1)

    mcux_add_source(SOURCES fsl_usart.h fsl_usart.c)

    mcux_add_include(INCLUDES .)

endif()
