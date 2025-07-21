# Copyright 2024-2025 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.ostimer)
    mcux_component_version(2.2.4)

    mcux_add_source(SOURCES fsl_ostimer.h fsl_ostimer.c)

    mcux_add_include(INCLUDES .)

endif()
