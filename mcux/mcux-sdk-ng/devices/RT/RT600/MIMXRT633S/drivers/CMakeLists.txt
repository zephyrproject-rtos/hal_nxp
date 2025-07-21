# Copyright 2024-2025 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if (CONFIG_MCUX_COMPONENT_driver.clock)
    mcux_component_version(2.7.4)
    mcux_add_source( BASE_PATH ../../MIMXRT685S/drivers SOURCES fsl_clock.c fsl_clock.h )
    mcux_add_include( BASE_PATH ../../MIMXRT685S/drivers INCLUDES . )
endif()

if (CONFIG_MCUX_COMPONENT_driver.i2s_bridge)
    mcux_component_version(2.0.0)
    mcux_add_source( BASE_PATH ../../MIMXRT685S/drivers SOURCES fsl_i2s_bridge.c fsl_i2s_bridge.h )
    mcux_add_include( BASE_PATH ../../MIMXRT685S/drivers INCLUDES . )
endif()

if (CONFIG_MCUX_COMPONENT_driver.inputmux_connections)
    mcux_component_version(2.0.0)
    mcux_add_source( BASE_PATH ../../MIMXRT685S/drivers SOURCES fsl_inputmux_connections.h )
    mcux_add_include( BASE_PATH ../../MIMXRT685S/drivers INCLUDES . )
endif()

if (CONFIG_MCUX_COMPONENT_driver.power)
    mcux_component_version(2.5.0)
    mcux_add_source( BASE_PATH ../../MIMXRT685S/drivers SOURCES fsl_power.c fsl_power.h )
    mcux_add_include( BASE_PATH ../../MIMXRT685S/drivers INCLUDES . )
endif()

if (CONFIG_MCUX_COMPONENT_driver.reset)
    mcux_component_version(2.2.1)
    mcux_add_source( BASE_PATH ../../MIMXRT685S/drivers SOURCES fsl_reset.c fsl_reset.h )
    mcux_add_include( BASE_PATH ../../MIMXRT685S/drivers INCLUDES . )
endif()
