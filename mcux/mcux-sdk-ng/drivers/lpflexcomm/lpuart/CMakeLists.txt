# Copyright 2024-2025 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.lpflexcomm_lpuart)
    mcux_component_version(2.3.3)

    mcux_add_source(SOURCES fsl_lpuart.h fsl_lpuart.c)

    mcux_add_include(INCLUDES .)

endif()

if(CONFIG_MCUX_COMPONENT_driver.lpflexcomm_lpuart_edma)
    mcux_component_version(2.0.0)

    mcux_add_source(SOURCES fsl_lpuart_edma.h fsl_lpuart_edma.c)

    mcux_add_include(INCLUDES .)

endif()
