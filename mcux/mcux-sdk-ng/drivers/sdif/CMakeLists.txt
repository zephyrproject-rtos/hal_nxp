# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.sdif)
    mcux_component_version(2.1.0)

    mcux_add_source(SOURCES fsl_sdif.c fsl_sdif.h)

    mcux_add_include(INCLUDES .)

endif()
