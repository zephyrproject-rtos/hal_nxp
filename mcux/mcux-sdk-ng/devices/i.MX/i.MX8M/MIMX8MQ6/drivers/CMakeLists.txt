# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if (CONFIG_MCUX_COMPONENT_driver.clock)
    mcux_component_version(2.4.1)
    mcux_add_source( SOURCES fsl_clock.c fsl_clock.h )
    mcux_add_include( INCLUDES . )
endif()

if (CONFIG_MCUX_COMPONENT_driver.iomuxc)
    mcux_component_version(2.0.1)
    mcux_add_source( SOURCES fsl_iomuxc.h )
    mcux_add_include( INCLUDES . )
endif()

if (CONFIG_MCUX_COMPONENT_driver.memory)
    mcux_component_version(2.0.1)
    mcux_add_source( SOURCES fsl_memory.h )
    mcux_add_include( INCLUDES . )
endif()
