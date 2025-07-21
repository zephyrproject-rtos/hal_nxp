# Copyright 2024-2025 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.xrdc)
    mcux_component_version(2.0.7)

    mcux_add_source(SOURCES fsl_xrdc.h fsl_xrdc.c)

    mcux_add_include(INCLUDES .)

endif()
