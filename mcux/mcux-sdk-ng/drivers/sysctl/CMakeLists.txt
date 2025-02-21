# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.sysctl)
    mcux_component_version(2.0.5)

    mcux_add_source(SOURCES fsl_sysctl.h fsl_sysctl.c)

    mcux_add_include(INCLUDES .)

endif()
