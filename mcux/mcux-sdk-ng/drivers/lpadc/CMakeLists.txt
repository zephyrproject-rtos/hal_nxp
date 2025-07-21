# Copyright 2024-2025 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.lpadc)
    mcux_component_version(2.9.3)

    mcux_add_source(SOURCES fsl_lpadc.c fsl_lpadc.h)

    mcux_add_include(INCLUDES .)

endif()
