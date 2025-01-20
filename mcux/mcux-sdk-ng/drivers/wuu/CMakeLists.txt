# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.wuu)
    mcux_component_version(2.4.0)

    mcux_add_source(SOURCES fsl_wuu.c fsl_wuu.h)

    mcux_add_include(INCLUDES .)

endif()
