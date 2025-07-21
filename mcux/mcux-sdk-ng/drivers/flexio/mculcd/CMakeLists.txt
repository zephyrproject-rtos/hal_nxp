# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.flexio_mculcd_dma)
    mcux_component_version(2.0.6)

    mcux_add_source(SOURCES fsl_flexio_mculcd_dma.c fsl_flexio_mculcd_dma.h)

    mcux_add_include(INCLUDES .)

endif()

if(CONFIG_MCUX_COMPONENT_driver.flexio_mculcd_edma)
    mcux_component_version(2.0.6)

    mcux_add_source(SOURCES fsl_flexio_mculcd_edma.c fsl_flexio_mculcd_edma.h)

    mcux_add_include(INCLUDES .)

endif()

if(CONFIG_MCUX_COMPONENT_driver.flexio_mculcd_smartdma)
    mcux_component_version(2.0.5)

    mcux_add_source(SOURCES fsl_flexio_mculcd_smartdma.c fsl_flexio_mculcd_smartdma.h)

    mcux_add_include(INCLUDES .)

endif()

if(CONFIG_MCUX_COMPONENT_driver.flexio_mculcd)
    mcux_component_version(2.3.0)

    mcux_add_source(SOURCES fsl_flexio_mculcd.c fsl_flexio_mculcd.h)

    mcux_add_include(INCLUDES .)

endif()
