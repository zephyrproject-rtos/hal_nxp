# Copyright 2024, 2026 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.lcdifv3)
    mcux_component_version(2.1.0)

    mcux_add_source(SOURCES fsl_lcdifv3.c fsl_lcdifv3.h)

    mcux_add_include(INCLUDES .)

endif()
