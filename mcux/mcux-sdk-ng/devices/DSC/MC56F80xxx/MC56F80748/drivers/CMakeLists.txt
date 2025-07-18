# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if (CONFIG_MCUX_COMPONENT_driver.clock)
    mcux_component_version(2.0.0)
    mcux_add_source( SOURCES fsl_clock.c fsl_clock.h )
    mcux_add_include( INCLUDES . )
endif()

if (CONFIG_MCUX_COMPONENT_driver.dsc_device_sim)
    mcux_component_version(2.0.0)
    mcux_add_source( SOURCES fsl_sim.h )
    mcux_add_include( INCLUDES . )
endif()
