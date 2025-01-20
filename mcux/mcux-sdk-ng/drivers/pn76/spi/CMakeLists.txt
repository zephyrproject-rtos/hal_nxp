# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.spi_gpdma)
    mcux_component_version(2.0.1)

    mcux_add_source(SOURCES fsl_spi_gpdma.c fsl_spi_gpdma.h)

    mcux_add_include(INCLUDES .)

endif()

if(CONFIG_MCUX_COMPONENT_driver.pn_spi)
    mcux_component_version(2.1.1)

    mcux_add_source(SOURCES fsl_spi.c fsl_spi.h)

    mcux_add_include(INCLUDES .)

endif()
