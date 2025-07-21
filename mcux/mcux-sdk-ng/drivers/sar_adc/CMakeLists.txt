# Copyright 2024-2025 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.sar_adc)
    mcux_component_version(2.3.0)

    mcux_add_source(SOURCES fsl_sar_adc.c fsl_sar_adc.h)

    mcux_add_include(INCLUDES .)

endif()
