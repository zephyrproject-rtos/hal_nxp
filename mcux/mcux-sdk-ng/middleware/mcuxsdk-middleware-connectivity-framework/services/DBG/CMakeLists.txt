# Copyright 2024-2025 NXP
# SPDX-License-Identifier: BSD-3-Clause

mcux_add_cmakelists(${CMAKE_CURRENT_LIST_DIR}/sbtsnoop)
mcux_add_cmakelists(${CMAKE_CURRENT_LIST_DIR}/SWO)

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.dbg.fault_handlers)
    mcux_add_source(
        SOURCES
                fault_handlers/fwk_fault_handlers.c
                fault_handlers/fwk_fault_handlers_utils.c
                fault_handlers/fwk_fault_handlers_utils.h
    )
    mcux_add_include(
        INCLUDES
                fault_handlers/
                fault_handlers/rtos_port
    )
    mcux_add_source(
        SOURCES fault_handlers/rtos_port/fwk_fault_handlers_freertos.c
                fault_handlers/rtos_port/fwk_fault_handlers_rtos_port.h
        COMPONENTS middleware.freertos-kernel
    )
    mcux_add_source(
        SOURCES fault_handlers/rtos_port/fwk_fault_handlers_threadx.c
                fault_handlers/rtos_port/fwk_fault_handlers_rtos_port.h
        COMPONENTS component.osa_threadx
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.dbg.nbu_debug_on_host)
    mcux_add_source(
        SOURCES
                nbu_dbg/host_interface/fwk_nbu_dbg.c
                nbu_dbg/host_interface/fwk_nbu_dbg.h
    )

    mcux_add_include(
        INCLUDES
                nbu_dbg/host_interface
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.dbg.nbu_debug)
    mcux_add_source(
        SOURCES
                nbu_dbg/nbu_interface/fwk_nbu_dbg.c
    )

    mcux_add_include(
        INCLUDES
                nbu_dbg/nbu_interface
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.dbg.nbu_debug.dbg_struct_legacy)
    mcux_add_source(
        SOURCES
                nbu_dbg/common/legacy/fwk_debug_struct.h
    )

    mcux_add_include(
        INCLUDES
                nbu_dbg/common/legacy
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.dbg.nbu_debug.dbg_struct)
    mcux_add_source(
        SOURCES
                nbu_dbg/common/fwk_debug_struct.h
    )

    mcux_add_include(
        INCLUDES
                nbu_dbg/common
    )
endif()
