# Copyright 2025 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.biss)
    mcux_component_version(1.0.2)

    mcux_add_source(SOURCES fsl_biss.c fsl_biss.h)

    mcux_add_include(INCLUDES .)

endif()
