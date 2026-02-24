# Copyright 2025 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.cache_llc)
    mcux_component_version(2.0.1)

    mcux_add_source(SOURCES fsl_llc.c fsl_llc.h)

    mcux_add_include(INCLUDES .)

endif()
