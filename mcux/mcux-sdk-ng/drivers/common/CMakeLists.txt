# Copyright 2024-2025 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.common)
    mcux_component_version(2.6.0)

    mcux_add_source(SOURCES fsl_common.h fsl_common.c)

    mcux_add_include(INCLUDES .)

    mcux_add_source(
        CORES
        cm4
        cm4f
        cm7f
        cm33
        cm0p
        SOURCES
        fsl_common_arm.c
        fsl_common_arm.h
    )

    mcux_add_source(
        CORES
        dsp56800ex
        dsp56800ef
        SOURCES
        fsl_common_dsc.c
        fsl_common_dsc.h
    )

    mcux_add_source(
        CORES
        dsp
        SOURCES
        fsl_common_dsp.c
        fsl_common_dsp.h
    )

    mcux_add_source(
        CORES
        ezhv
        SOURCES
        fsl_common_riscv.c
        fsl_common_riscv.h
    )
endif()
