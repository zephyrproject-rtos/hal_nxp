# Copyright 2024-2025 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.lpflexcomm_lpspi)
    mcux_component_version(2.2.8)

    mcux_add_source(SOURCES fsl_lpspi.h fsl_lpspi.c)

    mcux_add_include(INCLUDES .)

endif()

if(CONFIG_MCUX_COMPONENT_driver.lpflexcomm_lpspi_edma)
    mcux_component_version(2.1.4)

    mcux_add_source(SOURCES fsl_lpspi_edma.h fsl_lpspi_edma.c)

    mcux_add_include(INCLUDES .)

endif()
