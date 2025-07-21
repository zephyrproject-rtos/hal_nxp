# Copyright 2024-2025 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.trng)
    mcux_component_version(2.0.18)

    mcux_add_source(SOURCES fsl_trng.c fsl_trng.h)

    mcux_add_include(INCLUDES .)

endif()
