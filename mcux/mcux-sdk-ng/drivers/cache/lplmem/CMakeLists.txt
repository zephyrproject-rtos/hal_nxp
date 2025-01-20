# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.cache_lplmem)
    mcux_component_version(2.1.1)

    mcux_add_source(SOURCES fsl_cache.c fsl_cache.h)

    mcux_add_include(INCLUDES .)

endif()
