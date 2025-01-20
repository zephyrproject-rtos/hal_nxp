# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.acmp_1)
    mcux_component_version(2.0.2)

    mcux_add_source(SOURCES fsl_acmp.c fsl_acmp.h)

    mcux_add_include(INCLUDES .)

endif()
