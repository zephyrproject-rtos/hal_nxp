# Copyright 2024-2025 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.lpc_i2c)
    mcux_component_version(2.2.1)

    mcux_add_source(SOURCES fsl_i2c.h fsl_i2c.c)

    mcux_add_include(INCLUDES .)

endif()
