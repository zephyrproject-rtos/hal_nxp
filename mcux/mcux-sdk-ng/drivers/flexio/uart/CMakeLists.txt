# Copyright 2024-2025 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.flexio_uart_dma)
    mcux_component_version(2.4.0)

    mcux_add_source(SOURCES fsl_flexio_uart_dma.c fsl_flexio_uart_dma.h)

    mcux_add_include(INCLUDES .)

endif()

if(CONFIG_MCUX_COMPONENT_driver.flexio_uart_edma)
    mcux_component_version(2.4.1)

    mcux_add_source(SOURCES fsl_flexio_uart_edma.c fsl_flexio_uart_edma.h)

    mcux_add_include(INCLUDES .)

endif()

if(CONFIG_MCUX_COMPONENT_driver.flexio_uart)
    mcux_component_version(2.6.2)

    mcux_add_source(SOURCES fsl_flexio_uart.c fsl_flexio_uart.h)

    mcux_add_include(INCLUDES .)

endif()
