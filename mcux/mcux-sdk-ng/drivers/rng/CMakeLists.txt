# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.rng)
    mcux_component_version(2.1.0)

    mcux_add_source(SOURCES fsl_rng.h fsl_rng.c)

    mcux_add_include(INCLUDES .)

endif()
