#
# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if (CONFIG_MCUX_COMPONENT_RISCV_Include_Core)
    mcux_add_include(
        INCLUDES ./
    )

    mcux_add_source(
        SOURCES ./*.h
        COMPILERS riscvllvm
    )
endif()
