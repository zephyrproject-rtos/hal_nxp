# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.i2c_gpdma)
    mcux_component_version(2.1.0)

    mcux_add_source(SOURCES fsl_i2c_gpdma.c fsl_i2c_gpdma.h)

    mcux_add_include(INCLUDES .)

endif()

if(CONFIG_MCUX_COMPONENT_driver.pn76_i2c)
    mcux_component_version(2.2.0)

    mcux_add_source(SOURCES fsl_i2c.h fsl_i2c.c)

    mcux_add_include(INCLUDES .)

endif()
