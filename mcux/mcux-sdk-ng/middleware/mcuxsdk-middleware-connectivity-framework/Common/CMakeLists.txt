# Copyright 2024 NXP
# SPDX-License-Identifier: BSD-3-Clause


if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework)
    mcux_add_include(
        INCLUDES
        .
        ../services/DBG
    )

    mcux_add_source(
        SOURCES
                EmbeddedTypes.h
                fwk_hal_macros.h
                fwk_errno.h
                ../services/DBG/fwk_debug.h
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.systicks)
    mcux_add_include(
        INCLUDES
        rtos/freertos
    )

    mcux_add_source(
        SOURCES rtos/freertos/fwk_freertos_utils.c
                rtos/freertos/fwk_freertos_utils.h
    )

endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.heap_mem_manager)
    mcux_add_source(
        SOURCES rtos/freertos/heap_mem_manager.c
    )
endif()
