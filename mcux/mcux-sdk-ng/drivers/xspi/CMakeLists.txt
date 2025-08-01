# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.xspi_edma)
    mcux_component_version(2.0.2)

    mcux_add_source(SOURCES fsl_xspi_edma.c fsl_xspi_edma.h)

    mcux_add_include(INCLUDES .)

endif()

if(CONFIG_MCUX_COMPONENT_driver.xspi)
    mcux_component_version(2.5.1)

    mcux_add_source(SOURCES fsl_xspi.c fsl_xspi.h)

    mcux_add_include(INCLUDES .)

endif()
