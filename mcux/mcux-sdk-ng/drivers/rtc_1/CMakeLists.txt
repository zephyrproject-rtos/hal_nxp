# Copyright 2024-2025 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.rtc_1)
    mcux_component_version(2.0.6)

    mcux_add_source(SOURCES fsl_rtc.c fsl_rtc.h)

    mcux_add_include(INCLUDES .)

endif()
