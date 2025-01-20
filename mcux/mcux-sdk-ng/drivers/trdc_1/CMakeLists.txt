# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.trdc_1)
    mcux_component_version(2.2.1)

    mcux_add_source(
        SOURCES
        fsl_trdc.h
        fsl_trdc_core.h
        fsl_trdc.c
    )

    mcux_add_include(INCLUDES .)

endif()
