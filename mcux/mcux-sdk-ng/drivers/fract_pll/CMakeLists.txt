# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.fract_pll)
    mcux_component_version(1.0.0)

    mcux_add_source(SOURCES fsl_fract_pll.h fsl_fract_pll.c)

    mcux_add_include(INCLUDES .)

endif()
