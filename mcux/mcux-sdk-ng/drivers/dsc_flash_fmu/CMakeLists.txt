# Copyright 2026 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.dsc_flash_fmu)
    mcux_component_version(1.0.0)

    mcux_add_source(
        SOURCES
        fsl_flash.h
        fsl_dsc_fmu_flash.c
        fsl_dsc_fmu_flash.h
        fsl_flash_utilities.h
        fsl_flash_adapter.h
        fsl_dsc_fmu_controller.c
        fsl_dsc_fmu_controller.h
    )

    mcux_add_include(INCLUDES .)

endif()
