# Copyright 2024 NXP
# SPDX-License-Identifier: BSD-3-Clause

if (CONFIG_MCUX_COMPONENT_component.sdio_dev)
    mcux_add_source(
        SOURCES fsl_adapter_sdu.c
                fsl_adapter_sdu.h
                cis_table.c
                cis_table.h
                fsl_sdioslv_sdu.c
                fsl_sdioslv_sdu.h
    )
    mcux_add_include(
        INCLUDES ./
    )
endif()
