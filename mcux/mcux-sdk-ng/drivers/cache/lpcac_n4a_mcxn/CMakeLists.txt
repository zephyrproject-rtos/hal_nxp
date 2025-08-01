# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.cache_lpcac_n4a_mcxn)
    mcux_component_version(2.2.0)

    mcux_add_source(SOURCES fsl_cache_lpcac.c fsl_cache_lpcac.h)

    mcux_add_include(INCLUDES .)

endif()
