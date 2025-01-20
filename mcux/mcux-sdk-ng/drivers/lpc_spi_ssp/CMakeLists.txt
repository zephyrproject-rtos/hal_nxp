# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.lpc_spi_ssp)
    mcux_component_version(2.0.3)

    mcux_add_source(SOURCES fsl_spi.c fsl_spi.h)

    mcux_add_include(INCLUDES .)

endif()
