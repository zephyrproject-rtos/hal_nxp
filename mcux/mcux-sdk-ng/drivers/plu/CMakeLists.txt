# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.plu)
    mcux_component_version(2.2.1)

    mcux_add_source(SOURCES fsl_plu.h fsl_plu.c)

    mcux_add_include(INCLUDES .)

endif()
