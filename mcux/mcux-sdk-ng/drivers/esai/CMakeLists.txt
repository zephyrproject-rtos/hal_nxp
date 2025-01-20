# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.esai_edma)
    mcux_component_version(2.1.1)

    mcux_add_source(SOURCES fsl_esai_edma.h fsl_esai_edma.c)

    mcux_add_include(INCLUDES .)

endif()

if(CONFIG_MCUX_COMPONENT_driver.esai)
    mcux_component_version(2.1.1)

    mcux_add_source(SOURCES fsl_esai.h fsl_esai.c)

    mcux_add_include(INCLUDES .)

endif()
