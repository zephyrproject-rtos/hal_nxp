# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.edma4)
    mcux_component_version(2.10.5)

    mcux_add_source(
        SOURCES
        fsl_edma.h
        fsl_edma_core.h
        fsl_edma.c
    )

    mcux_add_include(INCLUDES .)

endif()
