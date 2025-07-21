# Copyright 2024,2025 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.lcdif)
    mcux_component_version(2.3.1)

    mcux_add_source(SOURCES fsl_lcdif.h fsl_lcdif.c)

    mcux_add_include(INCLUDES .)

endif()
