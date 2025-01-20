# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.wdog01)
    mcux_component_version(2.2.0)

    mcux_add_source(SOURCES fsl_wdog.h fsl_wdog.c)

    mcux_add_include(INCLUDES .)

endif()
