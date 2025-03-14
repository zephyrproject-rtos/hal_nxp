# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.adc_12b1msps_sar)
    mcux_component_version(2.0.4)

    mcux_add_source(SOURCES fsl_adc.c fsl_adc.h)

    mcux_add_include(INCLUDES .)

endif()
