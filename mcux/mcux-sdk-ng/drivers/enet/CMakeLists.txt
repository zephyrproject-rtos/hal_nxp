# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.enet)
    mcux_component_version(2.9.2)

    mcux_add_source(SOURCES fsl_enet.h fsl_enet.c)

    mcux_add_include(INCLUDES .)

endif()
