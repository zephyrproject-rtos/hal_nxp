# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.trgmux)
    mcux_component_version(2.0.1)

    mcux_add_source(SOURCES fsl_trgmux.h fsl_trgmux.c)

    mcux_add_include(INCLUDES .)

endif()
