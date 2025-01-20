# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.lpsci_dma)
    mcux_component_version(2.1.0)

    mcux_add_source(SOURCES fsl_lpsci_dma.h fsl_lpsci_dma.c)

    mcux_add_include(INCLUDES .)

endif()

if(CONFIG_MCUX_COMPONENT_driver.lpsci)
    mcux_component_version(2.1.1)

    mcux_add_source(SOURCES fsl_lpsci.h fsl_lpsci.c)

    mcux_add_include(INCLUDES .)

endif()
