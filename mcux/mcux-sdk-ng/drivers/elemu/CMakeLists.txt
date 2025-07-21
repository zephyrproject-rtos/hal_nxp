# Copyright 2024-2025 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.elemu)
    mcux_component_version(2.1.2)

    mcux_add_source(SOURCES fsl_elemu.c fsl_elemu.h)

    mcux_add_include(INCLUDES .)

endif()
