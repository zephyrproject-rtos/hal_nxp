# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.flexcomm)
    mcux_component_version(2.0.2)

    mcux_add_source(SOURCES fsl_flexcomm.h fsl_flexcomm.c)

    mcux_add_include(INCLUDES .)

endif()
