# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.dsc_aoi)
    mcux_component_version(2.0.0)

    mcux_add_source(SOURCES fsl_aoi.c fsl_aoi.h)

    mcux_add_include(INCLUDES .)

endif()
