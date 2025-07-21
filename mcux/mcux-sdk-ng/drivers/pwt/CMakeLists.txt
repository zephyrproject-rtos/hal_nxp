# Copyright 2024-2025 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.pwt)
    mcux_component_version(2.0.2)

    mcux_add_source(SOURCES fsl_pwt.c fsl_pwt.h)

    mcux_add_include(INCLUDES .)

endif()
