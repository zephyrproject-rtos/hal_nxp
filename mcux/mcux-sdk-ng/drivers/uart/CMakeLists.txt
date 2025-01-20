# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.uart_dma)
    mcux_component_version(2.5.0)

    mcux_add_source(SOURCES fsl_uart_dma.h fsl_uart_dma.c)

    mcux_add_include(INCLUDES .)

endif()

if(CONFIG_MCUX_COMPONENT_driver.uart_edma)
    mcux_component_version(2.5.2)

    mcux_add_source(SOURCES fsl_uart_edma.h fsl_uart_edma.c)

    mcux_add_include(INCLUDES .)

endif()

if(CONFIG_MCUX_COMPONENT_driver.uart)
    mcux_component_version(2.5.1)

    mcux_add_source(SOURCES fsl_uart.h fsl_uart.c)

    mcux_add_include(INCLUDES .)

endif()
