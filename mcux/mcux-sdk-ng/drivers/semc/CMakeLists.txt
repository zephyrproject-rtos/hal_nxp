# Copyright 2024, 2025 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.semc)
    mcux_component_version(2.7.1)

    mcux_add_source(SOURCES fsl_semc.h fsl_semc.c)

    mcux_add_include(INCLUDES .)

endif()
