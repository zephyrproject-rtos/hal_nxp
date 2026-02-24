# Copyright 2026 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.spi_filter)
    mcux_component_version(2.0.0)

    mcux_add_source(SOURCES fsl_spi_filter.c fsl_spi_filter.h)

    mcux_add_include(INCLUDES .)

endif()
