# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.irtc)
    mcux_component_version(2.3.2)

    mcux_add_source(SOURCES fsl_irtc.c fsl_irtc.h)

    mcux_add_include(INCLUDES .)

endif()
