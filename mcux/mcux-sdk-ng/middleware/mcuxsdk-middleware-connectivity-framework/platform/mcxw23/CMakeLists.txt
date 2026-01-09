# Copyright 2025 NXP
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.platform.mcxw23)

    mcux_set_list(MCXW23_FAMILY "MCXW236 MCXW235")

    mcux_add_source(
        SOURCES
        configs/fwk_config.h
        fwk_platform_definitions.h
        fwk_platform.c
        ../include/fwk_platform_rng.h
        ../wireless_mcu/fwk_platform.h
        ../wireless_mcu/fwk_platform_ics.h
        DEVICE_IDS ${MCXW23_FAMILY}
        CORE_IDS "cm33_core0"
    )

    mcux_add_include(INCLUDES
        .
        ../include
        ../wireless_mcu
        configs
        DEVICE_IDS ${MCXW23_FAMILY}
        CORE_IDS "cm33_core0"
    )

    mcux_add_configuration(CC "-DENABLE_RAM_VECTOR_TABLE")

    # temporarily ignore warnings from the ble controller sources
    mcux_add_iar_configuration(
        CC "--diag_suppress=Pa084,Pe188"
    )

    if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.platform.ble)
        mcux_add_source(
            SOURCES
            ../wireless_mcu/fwk_platform_ble.h
            fwk_platform_ble.c
            DEVICE_IDS ${MCXW23_FAMILY}
            CORE_IDS "cm33_core0"
        )

        mcux_add_include(INCLUDES
            ../wireless_mcu
            DEVICE_IDS ${MCXW23_FAMILY}
            CORE_IDS "cm33_core0"
        )
    endif()

    if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.platform.reset)
        mcux_add_source(
            SOURCES
            ../wireless_mcu/fwk_platform_reset.h
            DEVICE_IDS ${MCXW23_FAMILY}
            CORE_IDS "cm33_core0"
        )
    endif()

    if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.platform.ota)
        mcux_add_source(SOURCES
            ../mcxw23/fwk_platform_ota.c
            ../include/fwk_platform_ota.h
            DEVICE_IDS ${MCXW23_FAMILY}
            CORE_IDS "cm33_core0"
        )
    endif()

    if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.platform.sensors)
        mcux_add_source(SOURCES
            fwk_platform_sensors.c
            ../wireless_mcu/fwk_platform_sensors.h
            DEVICE_IDS ${MCXW23_FAMILY}
            CORE_IDS "cm33_core0"
        )
    endif()

    if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.platform.external_flash)
        mcux_add_source(SOURCES
            fwk_platform_extflash.c
            ../include/fwk_platform_extflash.h
            DEVICE_IDS ${MCXW23_FAMILY}
            CORE_IDS "cm33_core0"
        )
    endif()

    if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.ota_support.external_flash)
        mcux_add_macro(gPlatformUseExternalOtaStorage=1)
    endif()

    if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.seclib_rng_port.psa)
        mcux_add_source(SOURCES
            configs/SecLib_psa_config.h
            DEVICE_IDS ${MCXW23_FAMILY}
            CORE_IDS "cm33_core0"
        )
    endif()
endif()
