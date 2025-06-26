# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.qn_adc)
    mcux_component_version(2.0.2)

    mcux_add_source(SOURCES fsl_adc.h fsl_adc.c)

    mcux_add_include(INCLUDES .)

endif()
