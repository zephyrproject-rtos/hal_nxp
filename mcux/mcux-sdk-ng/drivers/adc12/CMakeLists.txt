# Copyright 2024-2025 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.adc12)
    mcux_component_version(2.0.8)

    mcux_add_source(SOURCES fsl_adc12.c fsl_adc12.h)

    mcux_add_include(INCLUDES .)

endif()
