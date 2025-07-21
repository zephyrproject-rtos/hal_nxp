# Copyright 2024-2025 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.afe)
    mcux_component_version(2.0.3)

    mcux_add_source(SOURCES fsl_afe.c fsl_afe.h)

    mcux_add_include(INCLUDES .)

endif()
