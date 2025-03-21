# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.dsc_flash)
    mcux_component_version(1.0.0)

    mcux_add_source(
        SOURCES
        fsl_ftfx_adapter.h
        fsl_ftfx_utilities.h
        fsl_ftfx_features.h
        fsl_ftfx_controller.c
        fsl_ftfx_controller.h
        fsl_ftfx_flash.c
        fsl_ftfx_flash.h
        fsl_flash.h
    )

    mcux_add_include(INCLUDES .)

endif()
