# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.sdma)
    mcux_component_version(2.4.2)

    mcux_add_source(
        SOURCES
        fsl_sdma.h
        fsl_sdma_script.h
        fsl_sdma.c
    )

    mcux_add_include(INCLUDES .)

endif()
