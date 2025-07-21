# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.cache_cache64)
    mcux_component_version(2.0.11)

    mcux_add_source(SOURCES fsl_cache.c fsl_cache.h)

    mcux_add_include(INCLUDES .)

endif()
