# Copyright 2024-2025 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.ela_csec)
    mcux_component_version(2.0.0)

    mcux_add_source(SOURCES ela_csec_driver.c ela_csec_driver.h ela_csec_hw_access.c ela_csec_hw_access.h)

    mcux_add_include(INCLUDES .)


endif()
