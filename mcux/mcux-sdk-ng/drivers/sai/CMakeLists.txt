# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.sai_dma)
    mcux_component_version(2.4.0)

    mcux_add_source(SOURCES fsl_sai_dma.h fsl_sai_dma.c)

    mcux_add_include(INCLUDES .)

endif()

if(CONFIG_MCUX_COMPONENT_driver.sai_edma)
    mcux_component_version(2.7.3)

    mcux_add_source(SOURCES fsl_sai_edma.h fsl_sai_edma.c)

    mcux_add_include(INCLUDES .)

endif()

if(CONFIG_MCUX_COMPONENT_driver.sai_sdma)
    mcux_component_version(2.6.0)

    mcux_add_source(SOURCES fsl_sai_sdma.h fsl_sai_sdma.c)

    mcux_add_include(INCLUDES .)

endif()

if(CONFIG_MCUX_COMPONENT_driver.sai)
    mcux_component_version(2.4.9)

    mcux_add_source(SOURCES fsl_sai.h fsl_sai.c)

    mcux_add_include(INCLUDES .)

endif()
