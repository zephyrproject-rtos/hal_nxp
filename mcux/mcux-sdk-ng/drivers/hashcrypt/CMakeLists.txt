# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.hashcrypt)
    mcux_component_version(2.2.16)

    mcux_add_source(SOURCES fsl_hashcrypt.h fsl_hashcrypt.c)

    mcux_add_include(INCLUDES .)

endif()
