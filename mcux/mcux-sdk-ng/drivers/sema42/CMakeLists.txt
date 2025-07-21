# Copyright 2024-2025 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.sema42)
    mcux_component_version(2.1.0)

    mcux_add_source(SOURCES fsl_sema42.h fsl_sema42.c)

    mcux_add_include(INCLUDES .)

endif()
