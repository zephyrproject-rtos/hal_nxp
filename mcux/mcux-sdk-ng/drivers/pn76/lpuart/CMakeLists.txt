# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.lpuart_gpdma)
    mcux_component_version(2.0.0)

    mcux_add_source(SOURCES fsl_lpuart_gpdma.h fsl_lpuart_gpdma.c)

    mcux_add_include(INCLUDES .)

endif()

if(CONFIG_MCUX_COMPONENT_driver.pn76_lpuart)
    mcux_component_version(2.0.1)

    mcux_add_source(SOURCES fsl_lpuart.h fsl_lpuart.c)

    mcux_add_include(INCLUDES .)

endif()
