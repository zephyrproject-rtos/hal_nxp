# Copyright 2024-2025 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.lpc_miniusart)
    mcux_component_version(2.5.2)

    mcux_add_source(SOURCES fsl_usart.h fsl_usart.c)

    mcux_add_include(INCLUDES .)

endif()
