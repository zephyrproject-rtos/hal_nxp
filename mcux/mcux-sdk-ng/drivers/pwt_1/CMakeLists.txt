# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.pwt_1)
    mcux_component_version(2.0.1)

    mcux_add_source(SOURCES fsl_pwt.c fsl_pwt.h)

    mcux_add_include(INCLUDES .)

endif()
