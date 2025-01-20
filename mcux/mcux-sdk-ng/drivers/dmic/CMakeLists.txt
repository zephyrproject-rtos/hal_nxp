# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.dmic_dma)
    mcux_component_version(2.4.0)

    mcux_add_source(SOURCES fsl_dmic_dma.c fsl_dmic_dma.h)

    mcux_add_include(INCLUDES .)

endif()

if(CONFIG_MCUX_COMPONENT_driver.dmic_hwvad)
    mcux_component_version(2.3.0)

    mcux_add_source(SOURCES fsl_dmic.c fsl_dmic.h)

    mcux_add_include(INCLUDES .)

endif()

if(CONFIG_MCUX_COMPONENT_driver.dmic)
    mcux_component_version(2.3.2)

    mcux_add_source(SOURCES fsl_dmic.c fsl_dmic.h)

    mcux_add_include(INCLUDES .)

endif()
