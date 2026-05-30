# Copyright 2024, 2026 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.utick)
    mcux_component_version(2.0.6)

    mcux_add_source(SOURCES fsl_utick.h fsl_utick.c)

    mcux_add_include(INCLUDES .)

endif()
