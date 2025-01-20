# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.sinc)
    mcux_component_version(2.1.5)

    mcux_add_source(SOURCES fsl_sinc.h fsl_sinc.c)

    mcux_add_include(INCLUDES .)

endif()
