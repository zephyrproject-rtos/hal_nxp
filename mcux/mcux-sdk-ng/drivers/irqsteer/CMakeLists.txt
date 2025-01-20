# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.irqsteer)
    mcux_component_version(2.1.3)

    mcux_add_source(SOURCES fsl_irqsteer.h fsl_irqsteer.c)

    mcux_add_include(INCLUDES .)

endif()
