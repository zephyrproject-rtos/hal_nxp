# Copyright 2024 NXP
# SPDX-License-Identifier: BSD-3-Clause

if (CONFIG_MCUX_COMPONENT_component.rpmsg_adapter)
    mcux_add_source(
        SOURCES fsl_adapter_rpmsg.h
                fsl_adapter_rpmsg.c
    )
    mcux_add_include(
        INCLUDES ./
    )
endif()
