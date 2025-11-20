# Copyright 2024-2025 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.acmp)
    mcux_component_version(2.4.0)

    mcux_add_source(SOURCES fsl_acmp.c fsl_acmp.h)

    mcux_add_include(INCLUDES .)

endif()
