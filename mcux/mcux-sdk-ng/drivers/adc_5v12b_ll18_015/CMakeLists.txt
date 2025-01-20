# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.adc_5v12b_ll18_015)
    mcux_component_version(2.1.0)

    mcux_add_source(SOURCES fsl_adc.c fsl_adc.h)

    mcux_add_include(INCLUDES .)

endif()
