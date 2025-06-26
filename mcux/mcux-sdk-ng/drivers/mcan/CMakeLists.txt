# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.mcan)
    mcux_component_version(2.4.2)

    mcux_add_source(SOURCES fsl_mcan.h fsl_mcan.c)

    mcux_add_include(INCLUDES .)

endif()
