# Copyright 2024-2025 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.vbat)
    mcux_component_version(2.1.1)

    mcux_add_source(SOURCES fsl_vbat.h fsl_vbat.c)

    mcux_add_include(INCLUDES .)

endif()
