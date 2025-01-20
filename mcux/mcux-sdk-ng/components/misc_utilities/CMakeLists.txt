# Copyright 2024 NXP
# SPDX-License-Identifier: BSD-3-Clause

if (CONFIG_MCUX_COMPONENT_utilities.misc_utilities)

    # If there is an executable project that links to the meta build system library project, fsl_syscall_stub.c should also
    # work for the executable project to prevent the compiler warning: _close is not implemented and will always fail
    mcux_add_source(
        SCOPE PUBLIC
        SOURCES fsl_syscall_stub.c
        TOOLCHAINS armgcc
)

    mcux_add_source(
        SOURCES fsl_sbrk.c
        TOOLCHAINS armgcc
    )

    mcux_add_source(
        SOURCES fsl_memcpy.S
        TOOLCHAINS armgcc mcux mdk
        CORES cm3 cm4 cm4f cm7 cm7f cm23 cm33 cm33f
    )    

endif()

if (CONFIG_MCUX_COMPONENT_utility.incbin)

    mcux_add_source(
            SOURCES fsl_incbin.S
            TOOLCHAINS armgcc mdk
    )

endif()
