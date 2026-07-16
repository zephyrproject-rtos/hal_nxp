# Copyright 2025-2026 NXP
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.platform.kw43_mcxw70)
    mcux_add_cmakelists(${CMAKE_CURRENT_LIST_DIR}/../wireless_mcu)
    mcux_add_source(SOURCES
        configs/fwk_config.h
        configs/rpmsg_config.h
        configs/SecLib_psa_config.h
        fwk_platform_definitions.h
        fwk_platform_kw43_mcxw70.c
        DEVICE_IDS ${KW43_FAMILY} ${MCXW70_FAMILY}
    )

    mcux_add_include(INCLUDES
        .
        configs
        DEVICE_IDS ${KW43_FAMILY} ${MCXW70_FAMILY}
    )

    mcux_add_macro(CONFIG_PSA_NO_EXTERNAL_RNG_IN_DRIVER=1)
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.platform.crypto)
    mcux_add_source(SOURCES
        fwk_platform_crypto.c
        ../include/fwk_platform_crypto.h
        DEVICE_IDS ${KW43_FAMILY} ${MCXW70_FAMILY}
    )
endif()
