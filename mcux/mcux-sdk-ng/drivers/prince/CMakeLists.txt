# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.prince)
    mcux_component_version(2.6.0)

    mcux_add_source(SOURCES fsl_prince.c fsl_prince.h)

    mcux_add_include(INCLUDES .)

endif()
