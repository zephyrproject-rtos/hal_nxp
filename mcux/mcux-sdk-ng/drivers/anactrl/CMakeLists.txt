# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.anactrl)
    mcux_component_version(2.4.0)

    mcux_add_source(SOURCES fsl_anactrl.h fsl_anactrl.c)

    mcux_add_include(INCLUDES .)

endif()
