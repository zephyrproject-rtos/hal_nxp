# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.qn_flash_dma)
    mcux_component_version(2.0.0)

    mcux_add_source(SOURCES fsl_flash_dma.h fsl_flash_dma.c)

    mcux_add_include(INCLUDES .)

endif()

if(CONFIG_MCUX_COMPONENT_driver.qn_flash)
    mcux_component_version(2.0.0)

    mcux_add_source(SOURCES fsl_flash.h fsl_flash.c)

    mcux_add_include(INCLUDES .)

endif()
