# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.dsc_eqdc)
    mcux_component_version(2.0.0)

    mcux_add_source(SOURCES fsl_eqdc.h fsl_eqdc.c)

    mcux_add_include(INCLUDES .)

endif()
