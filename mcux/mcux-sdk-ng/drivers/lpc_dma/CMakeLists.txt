# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.lpc_dma)
    mcux_component_version(2.5.3)

    mcux_add_source(SOURCES fsl_dma.c fsl_dma.h)

    mcux_add_include(INCLUDES .)

endif()
