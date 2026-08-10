# Copyright 2026 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.espi)
    mcux_component_version(2.1.0)

    mcux_add_source(SOURCES fsl_espi.c fsl_espi.h)

    mcux_add_include(INCLUDES .)

endif()
