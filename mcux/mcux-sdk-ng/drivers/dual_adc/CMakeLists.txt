# Copyright 2026 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.dual_adc)
    mcux_component_version(2.0.0)

    mcux_add_source(SOURCES fsl_dual_adc.c fsl_dual_adc.h)

    mcux_add_include(INCLUDES .)

endif()
