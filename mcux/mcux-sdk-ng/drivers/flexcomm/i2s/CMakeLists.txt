# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.flexcomm_i2s_dma)
    mcux_component_version(2.3.3)

    mcux_add_source(SOURCES fsl_i2s_dma.h fsl_i2s_dma.c)

    mcux_add_include(INCLUDES .)

endif()

if(CONFIG_MCUX_COMPONENT_driver.flexcomm_i2s)
    mcux_component_version(2.3.2)

    mcux_add_source(SOURCES fsl_i2s.h fsl_i2s.c)

    mcux_add_include(INCLUDES .)

endif()
