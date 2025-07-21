# Copyright 2024-2025 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.ewm)
    mcux_component_version(2.0.4)

    mcux_add_source(SOURCES fsl_ewm.c fsl_ewm.h)

    mcux_add_include(INCLUDES .)

endif()
