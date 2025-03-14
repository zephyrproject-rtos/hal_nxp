# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.dsc_pit)
    mcux_component_version(2.3.1)

    mcux_add_source(SOURCES fsl_pit.h fsl_pit.c)

    mcux_add_include(INCLUDES .)

endif()
