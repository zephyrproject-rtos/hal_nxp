# Copyright 2026 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.dsc_freqme)
    mcux_component_version(2.0.0)

    mcux_add_source(SOURCES fsl_freqme.h fsl_freqme.c)

    mcux_add_include(INCLUDES .)

endif()
