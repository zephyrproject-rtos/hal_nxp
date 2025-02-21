# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.adc_5hc)
    mcux_component_version(2.0.2)

    mcux_add_source(SOURCES fsl_adc_5hc.c fsl_adc_5hc.h)

    mcux_add_include(INCLUDES .)

endif()
