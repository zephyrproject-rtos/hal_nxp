# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.dsc_mcm)
    mcux_component_version(2.0.1)

    mcux_add_source(SOURCES fsl_mcm.h fsl_mcm.c)

    mcux_add_include(INCLUDES .)

endif()
