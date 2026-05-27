# Copyright 2024, 2026 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.ecspi_sdma)
    mcux_component_version(2.2.0)

    mcux_add_source(SOURCES fsl_ecspi_sdma.h fsl_ecspi_sdma.c)

    mcux_add_include(INCLUDES .)

endif()

if(CONFIG_MCUX_COMPONENT_driver.ecspi)
    mcux_component_version(2.3.4)

    mcux_add_source(SOURCES fsl_ecspi.h fsl_ecspi.c)

    mcux_add_include(INCLUDES .)

endif()
