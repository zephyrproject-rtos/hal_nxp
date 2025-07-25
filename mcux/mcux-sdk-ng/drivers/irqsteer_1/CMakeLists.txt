# Copyright 2024-2025 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.irqsteer_1)
    mcux_component_version(2.0.2)

    mcux_add_source(SOURCES fsl_irqsteer.h fsl_irqsteer.c)

    mcux_add_include(INCLUDES .)

endif()
