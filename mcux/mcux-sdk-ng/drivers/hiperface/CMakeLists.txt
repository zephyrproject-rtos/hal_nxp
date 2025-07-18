# Copyright 2025 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.hiperface)
    mcux_component_version(1.0.0)

    mcux_add_source(SOURCES fsl_hiperface.h fsl_hiperface.c)

    mcux_add_include(INCLUDES .)

endif()
