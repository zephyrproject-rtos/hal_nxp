# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.otfad)
    mcux_component_version(2.1.4)

    mcux_add_source(SOURCES fsl_otfad.c fsl_otfad.h)

    mcux_add_include(INCLUDES .)

endif()
