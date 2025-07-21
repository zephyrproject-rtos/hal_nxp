# Copyright 2024,2025 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.smartdma)
    mcux_component_version(2.13.0)

    mcux_add_source(
        SOURCES
        fsl_smartdma.h
        fsl_smartdma.c
        fsl_smartdma_prv.h
    )

    mcux_add_include(INCLUDES .)

endif()

if(CONFIG_MCUX_COMPONENT_driver.smartdma_rt500)
    mcux_component_version(2.12.0)

    mcux_add_source(
        SOURCES
        fsl_smartdma_rt500.c
        fsl_smartdma_rt500.h
    )

    mcux_add_include(INCLUDES .)

endif()

if(CONFIG_MCUX_COMPONENT_driver.smartdma_mcxn)
    mcux_component_version(2.12.0)

    mcux_add_source(
        SOURCES
        fsl_smartdma_mcxn.c
        fsl_smartdma_mcxn.h
    )

    mcux_add_include(INCLUDES .)

endif()

if(CONFIG_MCUX_COMPONENT_driver.smartdma_mcxa)
    mcux_component_version(2.13.0)

    mcux_add_source(
        SOURCES
        fsl_smartdma_mcxa.c
        fsl_smartdma_mcxa.h
    )

    mcux_add_include(INCLUDES .)

endif()