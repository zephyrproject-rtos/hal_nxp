# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.qspi_edma)
    mcux_component_version(2.2.2)

    mcux_add_source(SOURCES fsl_qspi_edma.h fsl_qspi_edma.c)

    mcux_add_include(INCLUDES .)

endif()

if(CONFIG_MCUX_COMPONENT_driver.qspi)
    mcux_component_version(2.2.5)

    mcux_add_source(SOURCES fsl_qspi.h fsl_qspi.c)

    mcux_add_include(INCLUDES .)

endif()
