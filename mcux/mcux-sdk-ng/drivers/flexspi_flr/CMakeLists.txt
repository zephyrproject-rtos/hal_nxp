# Copyright 2024-2025 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.flexspi_flr)
    mcux_component_version(2.0.0)

    mcux_add_source(SOURCES fsl_flexspi_flr.c fsl_flexspi_flr.h)

    mcux_add_include(INCLUDES .)

endif()
