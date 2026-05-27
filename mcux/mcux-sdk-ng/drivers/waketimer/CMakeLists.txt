# Copyright 2024, 2026 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.waketimer)
    mcux_component_version(2.0.2)

    mcux_add_source(SOURCES fsl_waketimer.h fsl_waketimer.c)

    mcux_add_include(INCLUDES .)

endif()
