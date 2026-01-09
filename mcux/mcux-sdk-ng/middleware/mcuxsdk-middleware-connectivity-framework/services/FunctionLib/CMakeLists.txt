# Copyright 2024 NXP
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.function_lib)
    mcux_add_source(
        SOURCES FunctionLib.c
                FunctionLib.h
                README.md
    )
    mcux_add_include(
        INCLUDES .
    )
endif()
if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.function_lib.use_toolchain_mem_function)
    mcux_add_macro(gUseToolchainMemFunc_d=1)
endif()

