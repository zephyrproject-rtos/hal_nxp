# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.jn_flash)
    mcux_component_version(1.0.0)

    mcux_add_source(SOURCES fsl_flash.c fsl_flash.h)

    mcux_add_include(INCLUDES .)

endif()
