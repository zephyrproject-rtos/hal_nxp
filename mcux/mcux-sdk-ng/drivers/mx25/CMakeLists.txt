# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.mx25)
    mcux_component_version(0.1.0)

    mcux_add_source(SOURCES fsl_mx25.h fsl_mx25.c)

    mcux_add_include(INCLUDES .)

endif()
