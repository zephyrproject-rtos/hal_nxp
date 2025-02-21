# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.bbnsm)
    mcux_component_version(2.0.0)

    mcux_add_source(SOURCES fsl_bbnsm.c fsl_bbnsm.h)

    mcux_add_include(INCLUDES .)

endif()
