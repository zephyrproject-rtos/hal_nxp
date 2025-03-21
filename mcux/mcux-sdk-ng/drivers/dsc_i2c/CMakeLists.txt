# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.dsc_i2c_dma)
    mcux_component_version(2.0.0)

    mcux_add_source(SOURCES fsl_i2c_dma.c fsl_i2c_dma.h)

    mcux_add_include(INCLUDES .)

endif()

if(CONFIG_MCUX_COMPONENT_driver.dsc_i2c_edma)
    mcux_component_version(2.0.0)

    mcux_add_source(SOURCES fsl_i2c_edma.c fsl_i2c_edma.h)

    mcux_add_include(INCLUDES .)

endif()

if(CONFIG_MCUX_COMPONENT_driver.dsc_i2c)
    mcux_component_version(2.0.1)

    mcux_add_source(SOURCES fsl_i2c.h fsl_i2c.c)

    mcux_add_include(INCLUDES .)

endif()
