# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.dryice)
    mcux_component_version(2.0.3)

    mcux_add_source(SOURCES fsl_dryice.c fsl_dryice.h)

    mcux_add_include(INCLUDES .)

endif()
