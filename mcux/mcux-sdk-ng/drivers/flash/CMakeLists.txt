# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.flash)
    mcux_component_version(3.1.3)

    mcux_add_source(
        SOURCES
        fsl_ftfx_adapter.h
        fsl_ftfx_utilities.h
        fsl_ftfx_features.h
        fsl_ftfx_controller.c
        fsl_ftfx_controller.h
        fsl_ftfx_flash.c
        fsl_ftfx_flash.h
        fsl_ftfx_cache.c
        fsl_ftfx_cache.h
        fsl_ftfx_flexnvm.c
        fsl_ftfx_flexnvm.h
        fsl_flash.h
    )

    mcux_add_include(INCLUDES .)

endif()
