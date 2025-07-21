# Copyright 2024-2025 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.mcx_enet)
    mcux_component_version(2.1.4)

    mcux_add_source(SOURCES fsl_enet.h fsl_enet.c)

    mcux_add_include(INCLUDES .)

endif()
