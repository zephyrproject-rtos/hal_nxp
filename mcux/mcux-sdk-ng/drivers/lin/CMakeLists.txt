# Copyright 2024,2025 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.lin_lpuart)
    mcux_component_version(2.2.4)

    mcux_add_source(
        SOURCES
        fsl_lin_lpuart.h
        fsl_lin_lpuart.c
    )

    mcux_add_include(INCLUDES .)

endif()

if(CONFIG_MCUX_COMPONENT_driver.lin)
    mcux_component_version(2.2.1)

    mcux_add_source(
        SOURCES
        fsl_lin.h
        fsl_lin.c
    )

    mcux_add_include(INCLUDES .)

endif()
