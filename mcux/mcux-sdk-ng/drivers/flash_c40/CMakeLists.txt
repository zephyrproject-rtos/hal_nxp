# Copyright 2025 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.flash_c40)
    mcux_component_version(1.0.0)

    mcux_add_source(
        SOURCES
        fsl_flash.h
        fsl_c40_flash.c
        fsl_c40_flash.h
    )

    mcux_add_include(INCLUDES .)

endif()
