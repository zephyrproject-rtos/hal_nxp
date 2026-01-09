# Copyright 2025 NXP
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.platform)
    mcux_add_source(SOURCES
        fwk_platform.c
        fwk_platform.h
        DEVICE_IDS ${KW45_FAMILY} ${KW47_FAMILY} ${MCXW71_FAMILY} ${MCXW72_FAMILY} ${KW43_FAMILY}
        CORE_IDS "cm33_core0" "cm33"
    )

    mcux_add_include(INCLUDES
        .
        ../include
        DEVICE_IDS ${KW45_FAMILY} ${KW47_FAMILY} ${MCXW71_FAMILY} ${MCXW72_FAMILY} ${KW43_FAMILY}
        CORE_IDS "cm33_core0"
    )

    mcux_add_include(INCLUDES
        .
        ../include
        DEVICE_IDS ${KW45_FAMILY} ${MCXW71_FAMILY} ${KW43_FAMILY}
    )

    mcux_add_macro(RPMSG_ADAPTER_NON_BLOCKING_MODE=1)
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.platform.external_flash)
    mcux_add_source(SOURCES
                            fwk_platform_extflash.c
                            ../include/fwk_platform_extflash.h
                            DEVICE_IDS ${KW45_FAMILY} ${KW47_FAMILY} ${MCXW71_FAMILY} ${MCXW72_FAMILY}
                            CORE_IDS "cm33_core0" "cm33"
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.platform.rng)
    mcux_add_source(SOURCES
                            fwk_platform_rng.c
                            ../include/fwk_platform_rng.h
                            DEVICE_IDS ${KW45_FAMILY} ${KW47_FAMILY} ${MCXW71_FAMILY} ${MCXW72_FAMILY} ${KW43_FAMILY}
                            CORE_IDS "cm33_core0" "cm33"
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.platform.ble)
    mcux_add_source(SOURCES
                            fwk_platform_ble.c
                            fwk_platform_ble.h
                            DEVICE_IDS ${KW45_FAMILY} ${KW47_FAMILY} ${MCXW71_FAMILY} ${MCXW72_FAMILY} ${KW43_FAMILY}
                            CORE_IDS "cm33_core0" "cm33"
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.platform.ics)
    mcux_add_source(SOURCES
                            fwk_platform_ics.c
                            fwk_platform_ics.h
                            DEVICE_IDS ${KW45_FAMILY} ${KW47_FAMILY} ${MCXW71_FAMILY} ${MCXW72_FAMILY} ${KW43_FAMILY}
                            CORE_IDS "cm33_core0" "cm33"
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.platform.sensors)
    mcux_add_source(SOURCES
                            fwk_platform_sensors.c
                            fwk_platform_sensors.h
                            DEVICE_IDS ${KW45_FAMILY} ${KW47_FAMILY} ${MCXW71_FAMILY} ${MCXW72_FAMILY} ${KW43_FAMILY}
                            CORE_IDS "cm33_core0" "cm33"
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.platform.lowpower)
    mcux_add_source(SOURCES
                            fwk_platform_lowpower.c
                            fwk_platform_lowpower.h
                            DEVICE_IDS ${KW45_FAMILY} ${KW47_FAMILY} ${MCXW71_FAMILY} ${MCXW72_FAMILY}
                            CORE_IDS "cm33_core0" "cm33"
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.platform.lowpower_timer)
    mcux_add_source(SOURCES
                            fwk_platform_lowpower_timer.c
                            fwk_platform_lowpower_timer.h
                            DEVICE_IDS ${KW45_FAMILY} ${KW47_FAMILY} ${MCXW71_FAMILY} ${MCXW72_FAMILY}
                            CORE_IDS "cm33_core0" "cm33"
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.platform.genfsk)
    mcux_add_source(SOURCES
                            fwk_platform_genfsk.c
                            fwk_platform_genfsk.h
                            DEVICE_IDS ${KW45_FAMILY} ${KW47_FAMILY} ${MCXW71_FAMILY} ${MCXW72_FAMILY} ${KW43_FAMILY}
                            CORE_IDS "cm33_core0" "cm33"
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.platform.internal_flash)
    mcux_add_source(SOURCES
                            fwk_platform_intflash.c
                            fwk_platform_intflash.h
                            DEVICE_IDS ${KW45_FAMILY} ${KW47_FAMILY} ${MCXW71_FAMILY} ${MCXW72_FAMILY}
                            CORE_IDS "cm33_core0" "cm33"
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.platform.ot)
    mcux_add_source(SOURCES
                            fwk_platform_ot.c
                            fwk_platform_ot.h
                            DEVICE_IDS ${KW45_FAMILY} ${KW47_FAMILY} ${MCXW71_FAMILY} ${MCXW72_FAMILY} ${KW43_FAMILY}
                            CORE_IDS "cm33_core0" "cm33"
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.platform.reset)
    mcux_add_source(SOURCES
                            fwk_platform_reset.c
                            fwk_platform_reset.h
                            DEVICE_IDS ${KW45_FAMILY} ${KW47_FAMILY} ${MCXW71_FAMILY} ${MCXW72_FAMILY} ${KW43_FAMILY}
                            CORE_IDS "cm33_core0" "cm33"
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.platform.ota)
    mcux_add_source(SOURCES
                            fwk_platform_ota.c
                            ../include/fwk_platform_ota.h
                            DEVICE_IDS ${KW45_FAMILY} ${KW47_FAMILY} ${MCXW71_FAMILY} ${MCXW72_FAMILY} ${KW43_FAMILY}
                            CORE_IDS "cm33_core0" "cm33"
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.platform.lcl)
    mcux_add_source(SOURCES
                            fwk_platform_lcl.c
                            fwk_platform_lcl.h
                            DEVICE_IDS ${KW45_FAMILY} ${KW47_FAMILY} ${MCXW71_FAMILY} ${MCXW72_FAMILY} ${KW43_FAMILY}
                            CORE_IDS "cm33_core0" "cm33"
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.platform.zb)
    mcux_add_source(SOURCES
                            fwk_platform_zb.c
                            ../include/fwk_platform_zb.h
                            DEVICE_IDS ${KW45_FAMILY} ${KW47_FAMILY} ${MCXW71_FAMILY} ${MCXW72_FAMILY}
                            CORE_IDS "cm33_core0" "cm33"
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.platform.crypto)
    mcux_add_source(SOURCES
                            fwk_platform_crypto.c
                            ../include/fwk_platform_crypto.h
                            DEVICE_IDS ${KW45_FAMILY} ${KW47_FAMILY} ${MCXW71_FAMILY} ${MCXW72_FAMILY}
                            CORE_IDS "cm33_core0" "cm33"
    )
endif()
