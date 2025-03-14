# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.rcm)
    mcux_component_version(2.0.4)

    mcux_add_source(SOURCES fsl_rcm.c fsl_rcm.h)

    mcux_add_include(INCLUDES .)

endif()
