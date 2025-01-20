# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.rgpio)
    mcux_component_version(2.1.0)

    mcux_add_source(SOURCES fsl_rgpio.h fsl_rgpio.c)

    mcux_add_include(INCLUDES .)

endif()
