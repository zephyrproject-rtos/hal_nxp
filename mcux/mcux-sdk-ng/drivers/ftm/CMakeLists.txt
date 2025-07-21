# Copyright 2024, 2025 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.ftm)
    mcux_component_version(2.7.1)

    mcux_add_source(SOURCES fsl_ftm.c fsl_ftm.h)

    mcux_add_include(INCLUDES .)

endif()
