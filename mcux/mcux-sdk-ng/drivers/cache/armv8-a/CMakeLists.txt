# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.cache_armv8_a)

    mcux_add_source(SOURCES fsl_cache.c fsl_cache.h)

    mcux_add_include(INCLUDES .)

endif()
