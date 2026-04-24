# Copyright 2024, 2026 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.flashiap)
    mcux_component_version(2.0.7)

    mcux_add_source(SOURCES fsl_flashiap.h fsl_flashiap.c)

    mcux_add_include(INCLUDES .)

endif()
