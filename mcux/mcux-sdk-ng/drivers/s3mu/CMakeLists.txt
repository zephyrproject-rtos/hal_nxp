# Copyright 2024-2025 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.s3mu)
    mcux_component_version(2.0.2)

    mcux_add_source(SOURCES fsl_s3mu.c fsl_s3mu.h)

    mcux_add_include(INCLUDES .)

endif()
