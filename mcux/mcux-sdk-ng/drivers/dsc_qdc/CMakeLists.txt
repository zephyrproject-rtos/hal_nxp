# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.dsc_qdc)
    mcux_component_version(2.1.0)

    mcux_add_source(SOURCES fsl_qdc.h fsl_qdc.c)

    mcux_add_include(INCLUDES .)

endif()
