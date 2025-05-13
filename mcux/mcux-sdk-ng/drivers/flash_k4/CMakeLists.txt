# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.flash_k4)
    mcux_component_version(2.2.1)

    mcux_add_source(
        SOURCES
        fsl_flash.h
        fsl_k4_flash.c
        fsl_k4_flash.h
        fsl_flash_utilities.h
        fsl_flash_adapter.h
        fsl_k4_controller.c
        fsl_k4_controller.h
    )

    mcux_add_include(INCLUDES .)

endif()
