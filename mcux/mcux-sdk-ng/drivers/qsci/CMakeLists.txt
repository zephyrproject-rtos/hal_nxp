# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.qsci_dma)
    mcux_component_version(2.0.1)

    mcux_add_source(SOURCES fsl_qsci_dma.h fsl_qsci_dma.c)

    mcux_add_include(INCLUDES .)

endif()

if(CONFIG_MCUX_COMPONENT_driver.qsci_edma)
    mcux_component_version(2.0.1)

    mcux_add_source(SOURCES fsl_qsci_edma.h fsl_qsci_edma.c)

    mcux_add_include(INCLUDES .)

endif()

if(CONFIG_MCUX_COMPONENT_driver.qsci)
    mcux_component_version(2.0.4)

    mcux_add_source(SOURCES fsl_qsci.h fsl_qsci.c)

    mcux_add_include(INCLUDES .)

endif()
