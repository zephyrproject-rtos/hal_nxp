# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.flexcomm_i2c_dma)
    mcux_component_version(2.3.1)

    mcux_add_source(SOURCES fsl_i2c_dma.c fsl_i2c_dma.h)

    mcux_add_include(INCLUDES .)

endif()

if(CONFIG_MCUX_COMPONENT_driver.flexcomm_i2c)
    mcux_component_version(2.3.3)

    mcux_add_source(SOURCES fsl_i2c.h fsl_i2c.c)

    mcux_add_include(INCLUDES .)

endif()
