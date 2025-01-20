# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.lcdifv2)
    mcux_component_version(2.3.3)

    mcux_add_source(SOURCES fsl_lcdifv2.c fsl_lcdifv2.h)

    mcux_add_include(INCLUDES .)

endif()
