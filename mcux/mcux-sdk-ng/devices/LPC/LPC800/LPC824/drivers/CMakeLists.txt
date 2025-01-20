# Copyright 2024 NXP
# All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause

if (CONFIG_MCUX_COMPONENT_driver.clock)
    mcux_component_version(2.4.4)
    mcux_add_source( SOURCES fsl_clock.c fsl_clock.h )
    mcux_add_include( INCLUDES . )
endif()

if (CONFIG_MCUX_COMPONENT_driver.inputmux_connections)
    mcux_component_version(2.0.0)
    mcux_add_source( SOURCES fsl_inputmux_connections.h )
    mcux_add_include( INCLUDES . )
endif()

if (CONFIG_MCUX_COMPONENT_driver.power)
    mcux_component_version(2.1.0)
    mcux_add_source( SOURCES fsl_power.c fsl_power.h )
    mcux_add_include( INCLUDES . )
endif()

if (CONFIG_MCUX_COMPONENT_driver.reset)
    mcux_component_version(2.4.0)
    mcux_add_source( SOURCES fsl_reset.c fsl_reset.h )
    mcux_add_include( INCLUDES . )
endif()

if (CONFIG_MCUX_COMPONENT_driver.swm_connections)
    mcux_component_version(2.0.0)
    mcux_add_source( SOURCES fsl_swm_connections.h )
    mcux_add_include( INCLUDES . )
endif()

if (CONFIG_MCUX_COMPONENT_driver.syscon_connections)
    mcux_component_version(2.0.0)
    mcux_add_source( SOURCES fsl_syscon_connections.h )
    mcux_add_include( INCLUDES . )
endif()
