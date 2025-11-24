# Copyright 2024-2025 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.smartdma)
    mcux_component_version(2.13.3)

    mcux_add_source(
        SOURCES
        fsl_smartdma.h
        fsl_smartdma.c
        fsl_smartdma_prv.h
    )

    mcux_add_include(INCLUDES .)

endif()

if(CONFIG_MCUX_COMPONENT_driver.smartdma_rt500)
    mcux_component_version(2.13.3)

    mcux_add_source(
        SOURCES
        ./rt500/fsl_smartdma_fw.c
        ./rt500/fsl_smartdma_fw.h
    )

    mcux_add_include(INCLUDES ./rt500)

endif()

if(CONFIG_MCUX_COMPONENT_driver.smartdma_mcxn)
    mcux_component_version(2.13.3)

    mcux_add_source(
        SOURCES
        ./mcxn/fsl_smartdma_fw.c
        ./mcxn/fsl_smartdma_fw.h
    )

    mcux_add_include(INCLUDES ./mcxn)

endif()

if(CONFIG_MCUX_COMPONENT_driver.smartdma_mcxa)
    mcux_component_version(2.13.3)

    mcux_add_source(
        SOURCES
        ./mcxa/fsl_smartdma_fw.c
        ./mcxa/fsl_smartdma_fw.h
    )

    mcux_add_include(INCLUDES ./mcxa)

endif()
