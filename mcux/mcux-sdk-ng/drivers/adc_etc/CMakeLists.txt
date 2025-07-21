# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.adc_etc)
    mcux_component_version(2.3.2)

    mcux_add_source(SOURCES fsl_adc_etc.c fsl_adc_etc.h)

    mcux_add_include(INCLUDES .)

endif()
