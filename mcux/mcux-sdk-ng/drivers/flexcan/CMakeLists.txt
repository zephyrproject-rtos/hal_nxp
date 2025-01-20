# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.flexcan_edma)
    mcux_component_version(2.11.7)

    mcux_add_source(SOURCES fsl_flexcan_edma.h fsl_flexcan_edma.c)

    mcux_add_include(INCLUDES .)

endif()

if(CONFIG_MCUX_COMPONENT_driver.flexcan)
    mcux_component_version(2.13.0)

    mcux_add_source(SOURCES fsl_flexcan.h fsl_flexcan.c)

    mcux_add_include(INCLUDES .)

endif()
