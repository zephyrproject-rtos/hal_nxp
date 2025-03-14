# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.sdu)
    mcux_component_version(1.0.0)

    mcux_add_source(
        SOURCES
        fsl_sdioslv_sdu.h
        fsl_sdioslv_sdu.c
        cis_table.h
        cis_table.c
    )

    mcux_add_include(INCLUDES .)

endif()
