# Copyright 2024-2025 NXP
# SPDX-License-Identifier: BSD-3-Clause

mcux_set_list(RW61x_FAMILY "RW610 RW612")

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.platform.rw61x)
    mcux_add_source(SOURCES
        configs/fwk_config.h
        fwk_platform_definitions.h
        fwk_platform.c
        fwk_platform.h
        fwk_platform_ics.h
        ../include/fwk_platform_rng.h
        DEVICE_IDS ${RW61x_FAMILY}
    )

    if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.seclib_rng_port.mbedtls)
        mcux_add_source(SOURCES
            configs/rw61x-mbedtls-config.h
            configs/SecLib_mbedtls_config.h
            DEVICE_IDS ${RW61x_FAMILY}
        )
    endif()

    if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.seclib_rng_port.psa)
        mcux_add_source(SOURCES
            configs/SecLib_psa_config.h
            DEVICE_IDS ${RW61x_FAMILY}
        )
    endif()

    mcux_add_include(INCLUDES
        .
        configs
        ../include
        DEVICE_IDS ${RW61x_FAMILY}
    )

    if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.file_system)
        mcux_add_source(SOURCES
            fwk_platform_flash.c
            fwk_platform_flash.h
            DEVICE_IDS ${RW61x_FAMILY}
        )
    endif()

    mcux_add_macro(
        MBEDTLS_MCUX_ELS_PKC_API
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.platform.sensors)
    mcux_add_source(SOURCES
        fwk_platform_sensors.c
        fwk_platform_sensors.h
        DEVICE_IDS ${RW61x_FAMILY}
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.platform.ota)
    mcux_add_source(SOURCES
        fwk_platform_ota.c
        ../include/fwk_platform_ota.h
        DEVICE_IDS ${RW61x_FAMILY}
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.platform.external_flash)
    mcux_add_source(SOURCES
        fwk_platform_extflash.c
        ../include/fwk_platform_extflash.h
        DEVICE_IDS ${RW61x_FAMILY}
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.platform.ot)
    mcux_add_source(SOURCES
        fwk_platform_ot.c
        ../include/fwk_platform_ot.h
        DEVICE_IDS ${RW61x_FAMILY}
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.platform.coex)
    mcux_add_source(SOURCES
        fwk_platform_coex.c
        ../include/fwk_platform_coex.h
        DEVICE_IDS ${RW61x_FAMILY}
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.platform.crypto)
    mcux_add_source(SOURCES
        fwk_platform_crypto.c
        ../include/fwk_platform_crypto.h
        DEVICE_IDS ${RW61x_FAMILY}
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.platform.ble)
    mcux_add_source(SOURCES
        fwk_platform_ble.c
        fwk_platform_ble.h
        DEVICE_IDS ${RW61x_FAMILY}
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.platform.hdlc)
    mcux_add_source(SOURCES
        ../include/fwk_platform_hdlc.h
        fwk_platform_hdlc.c
        DEVICE_IDS ${RW61x_FAMILY}
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.platform.lowpower)
    mcux_add_source(SOURCES
        fwk_platform_lowpower.c
        fwk_platform_lowpower.h
        fwk_platform_lowpower_timer.h
        DEVICE_IDS ${RW61x_FAMILY})
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.platform.zb)
    mcux_add_source(SOURCES
        ../include/fwk_platform_zb.h
        fwk_platform_zb.c
        DEVICE_IDS ${RW61x_FAMILY})
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.platform.rng)
    # Nothing needed, platform rng API is defined in fwk_platform.c
endif()
