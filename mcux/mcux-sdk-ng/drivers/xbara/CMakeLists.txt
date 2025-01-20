# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.xbara)
    mcux_component_version(2.0.6)

    mcux_add_source(SOURCES fsl_xbara.h fsl_xbara.c)

    mcux_add_include(INCLUDES .)

endif()
