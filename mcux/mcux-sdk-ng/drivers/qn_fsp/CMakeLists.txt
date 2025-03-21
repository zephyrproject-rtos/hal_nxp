# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.qn_fsp)
    mcux_component_version(2.0.2)

    mcux_add_source(SOURCES fsl_fsp.c fsl_fsp.h)

    mcux_add_include(INCLUDES .)

endif()
