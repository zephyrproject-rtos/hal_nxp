# Copyright 2024-2025 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.intm)
    mcux_component_version(2.1.0)

    mcux_add_source(SOURCES fsl_intm.c fsl_intm.h)

    mcux_add_include(INCLUDES .)

endif()
