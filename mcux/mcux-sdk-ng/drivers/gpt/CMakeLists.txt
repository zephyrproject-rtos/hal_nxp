# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.gpt)
    mcux_component_version(2.0.5)

    mcux_add_source(SOURCES fsl_gpt.c fsl_gpt.h)

    mcux_add_include(INCLUDES .)

endif()
