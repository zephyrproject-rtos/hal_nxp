# Copyright 2024 NXP
# SPDX-License-Identifier: BSD-3-Clause

if (CONFIG_MCUX_COMPONENT_component.lists)

    mcux_add_source(
        SOURCES fsl_component_generic_list.h
                fsl_component_generic_list.c
    )

    mcux_add_include(
        INCLUDES .
    )

endif()