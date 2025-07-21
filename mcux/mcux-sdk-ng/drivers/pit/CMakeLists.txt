# Copyright 2024-2025 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.pit)
    mcux_component_version(2.2.0)

    mcux_add_source(SOURCES fsl_pit.c fsl_pit.h)

    mcux_add_include(INCLUDES .)

endif()
