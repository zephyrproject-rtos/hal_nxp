# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.lpc_rtc_1)
    mcux_component_version(2.1.0)

    mcux_add_source(SOURCES fsl_rtc.h fsl_rtc.c)

    mcux_add_include(INCLUDES .)

endif()
