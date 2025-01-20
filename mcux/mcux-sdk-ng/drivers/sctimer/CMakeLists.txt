# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.sctimer)
    mcux_component_version(2.5.1)

    mcux_add_source(SOURCES fsl_sctimer.h fsl_sctimer.c)

    mcux_add_include(INCLUDES .)

endif()
