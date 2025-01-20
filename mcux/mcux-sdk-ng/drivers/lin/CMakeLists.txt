# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.lin_stack)
    mcux_component_version(2.2.1)

    mcux_add_source(
        SOURCES
        lin_driver.h
        lin_driver.c
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
        fsl_lin_lpuart.h
        fsl_lin_lpuart.c
    )

    mcux_add_include(INCLUDES .)

endif()
