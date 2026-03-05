# Copyright 2025 NXP
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.platform.kw43_mcxw70)
    mcux_add_cmakelists(${CMAKE_CURRENT_LIST_DIR}/../wireless_mcu)
    mcux_add_source(SOURCES
        configs/fwk_config.h
        configs/rpmsg_config.h
        fwk_platform_definitions.h
        ../../../framework_private/platform/kw43_mcxw70/fwk_platform_kw43_mcxw70.c
        DEVICE_IDS ${KW43_FAMILY}
    )

    mcux_add_include(INCLUDES
        .
        configs
        DEVICE_IDS ${KW43_FAMILY}
    )
endif()
