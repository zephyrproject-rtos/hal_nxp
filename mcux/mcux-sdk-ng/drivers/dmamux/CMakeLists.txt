# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.dmamux)
    mcux_component_version(2.1.3)

    mcux_add_source(SOURCES fsl_dmamux.h fsl_dmamux.c)

    mcux_add_include(INCLUDES .)

endif()
