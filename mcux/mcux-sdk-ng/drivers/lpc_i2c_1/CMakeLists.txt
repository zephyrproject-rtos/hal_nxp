# Copyright 2024, 2026 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.lpc_i2c_1)
    mcux_component_version(2.0.2)

    mcux_add_source(SOURCES fsl_i2c.h fsl_i2c.c)

    mcux_add_include(INCLUDES .)

endif()
