# Copyright 2025 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.npx)
    mcux_component_version(2.0.0)

    mcux_add_source(SOURCES fsl_npx.c fsl_npx.h)

    mcux_add_include(INCLUDES .)

endif()
