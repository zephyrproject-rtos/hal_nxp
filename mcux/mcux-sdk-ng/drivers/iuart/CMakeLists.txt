# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.iuart_sdma)
    mcux_component_version(2.3.0)

    mcux_add_source(SOURCES fsl_uart_sdma.h fsl_uart_sdma.c)

    mcux_add_include(INCLUDES .)

endif()

if(CONFIG_MCUX_COMPONENT_driver.iuart)
    mcux_component_version(2.3.2)

    mcux_add_source(SOURCES fsl_uart.h fsl_uart.c)

    mcux_add_include(INCLUDES .)

endif()
