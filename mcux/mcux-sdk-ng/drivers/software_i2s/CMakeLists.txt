# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.software_i2s)
    mcux_component_version(2.0.0)

    mcux_add_source(SOURCES fsl_software_i2s.h fsl_software_i2s.c)

    mcux_add_include(INCLUDES .)

endif()
