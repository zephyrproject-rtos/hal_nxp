# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.smartdma)
    mcux_component_version(2.10.0)

    mcux_add_source(
        SOURCES
        fsl_smartdma.h
        fsl_smartdma.c
        fsl_smartdma_prv.h
        fsl_smartdma_rt500.c
        fsl_smartdma_rt500.h
        fsl_smartdma_mcxn.c
        fsl_smartdma_mcxn.h
    )

    mcux_add_include(INCLUDES .)

endif()
