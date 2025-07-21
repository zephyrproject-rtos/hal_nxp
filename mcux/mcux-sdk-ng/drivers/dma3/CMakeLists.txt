# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.ad_dma3)
    mcux_component_version(2.3.0)

    mcux_add_source(SOURCES fsl_ad_edma.h fsl_ad_edma.c)

    mcux_add_include(INCLUDES .)

endif()

if(CONFIG_MCUX_COMPONENT_driver.dma3)
    mcux_component_version(2.5.0)

    mcux_add_source(SOURCES fsl_edma.h fsl_edma.c)

    mcux_add_include(INCLUDES .)

endif()
