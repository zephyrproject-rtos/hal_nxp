# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.tempmon)
    mcux_component_version(2.2.1)

    mcux_add_source(SOURCES fsl_tempmon.h fsl_tempmon.c)

    mcux_add_include(INCLUDES .)

endif()
