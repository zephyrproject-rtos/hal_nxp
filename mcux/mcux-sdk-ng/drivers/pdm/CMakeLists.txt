# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.pdm_edma)
    mcux_component_version(2.6.4)

    mcux_add_source(SOURCES fsl_pdm_edma.h fsl_pdm_edma.c)

    mcux_add_include(INCLUDES .)

endif()

if(CONFIG_MCUX_COMPONENT_driver.pdm_sdma)
    mcux_component_version(2.7.0)

    mcux_add_source(SOURCES fsl_pdm_sdma.h fsl_pdm_sdma.c)

    mcux_add_include(INCLUDES .)

endif()

if(CONFIG_MCUX_COMPONENT_driver.pdm)
    mcux_component_version(2.9.1)

    mcux_add_source(SOURCES fsl_pdm.h fsl_pdm.c)

    mcux_add_include(INCLUDES .)

endif()
