# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.flexram)
    mcux_component_version(2.3.0)

    mcux_add_source(SOURCES fsl_flexram.c fsl_flexram.h)

    mcux_add_include(INCLUDES .)

endif()
