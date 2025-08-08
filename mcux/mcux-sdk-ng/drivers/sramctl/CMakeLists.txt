# Copyright 2025 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.sramctl)
    mcux_component_version(3.0.0)

    mcux_add_source(SOURCES fsl_sramctl.c fsl_sramctl.h)

    mcux_add_include(INCLUDES .)

endif()
