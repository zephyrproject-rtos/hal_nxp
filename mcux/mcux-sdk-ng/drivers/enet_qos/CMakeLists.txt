# Copyright 2024-2025 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.enet_qos)
    mcux_component_version(2.6.5)

    mcux_add_source(SOURCES fsl_enet_qos.h fsl_enet_qos.c)

    mcux_add_include(INCLUDES .)

endif()
