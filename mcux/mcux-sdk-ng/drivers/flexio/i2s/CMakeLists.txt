# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.flexio_i2s_dma)
    mcux_component_version(2.1.7)

    mcux_add_source(SOURCES fsl_flexio_i2s_dma.c fsl_flexio_i2s_dma.h)

    mcux_add_include(INCLUDES .)

endif()

if(CONFIG_MCUX_COMPONENT_driver.flexio_i2s_edma)
    mcux_component_version(2.1.8)

    mcux_add_source(SOURCES fsl_flexio_i2s_edma.c fsl_flexio_i2s_edma.h)

    mcux_add_include(INCLUDES .)

endif()

if(CONFIG_MCUX_COMPONENT_driver.flexio_i2s)
    mcux_component_version(2.2.1)

    mcux_add_source(SOURCES fsl_flexio_i2s.c fsl_flexio_i2s.h)

    mcux_add_include(INCLUDES .)

endif()
