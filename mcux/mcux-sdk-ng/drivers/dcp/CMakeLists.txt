# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.dcp)
    mcux_component_version(2.1.7)

    mcux_add_source(SOURCES fsl_dcp.c fsl_dcp.h)

    mcux_add_include(INCLUDES .)

endif()
