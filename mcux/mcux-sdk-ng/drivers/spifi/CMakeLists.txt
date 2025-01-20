# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.spifi_dma)
    mcux_component_version(2.0.3)

    mcux_add_source(SOURCES fsl_spifi_dma.h fsl_spifi_dma.c)

    mcux_add_include(INCLUDES .)

endif()

if(CONFIG_MCUX_COMPONENT_driver.spifi)
    mcux_component_version(2.0.3)

    mcux_add_source(SOURCES fsl_spifi.h fsl_spifi.c)

    mcux_add_include(INCLUDES .)

endif()
