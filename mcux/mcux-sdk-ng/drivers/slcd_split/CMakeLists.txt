# Copyright 2025 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.slcd_split)
    mcux_component_version(2.0.0)

    mcux_add_source(SOURCES fsl_slcd.h fsl_slcd.c)

    mcux_add_include(INCLUDES .)

endif()
