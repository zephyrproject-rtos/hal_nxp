# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.wwdt)
    mcux_component_version(2.1.9)

    mcux_add_source(SOURCES fsl_wwdt.h fsl_wwdt.c)

    mcux_add_include(INCLUDES .)

endif()
