# Copyright 2024-2025 NXP
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.platform.kw47_mcxw72)
    mcux_add_cmakelists(${CMAKE_CURRENT_LIST_DIR}/../wireless_mcu)

    mcux_set_list(KW47_FAMILY "KW47B42Z83xxxA KW47B42Z96xxxA KW47B42Z97xxxA KW47B42ZB2xxxA KW47B42ZB3xxxA KW47B42ZB6xxxA KW47B42ZB7xxxA KW47Z42082xxxA KW47Z42092xxxA KW47Z420B2xxxA KW47Z420B3xxxA")
    mcux_set_list(MCXW72_FAMILY "MCXW727CxxxA")

    mcux_add_source(SOURCES
        configs/fwk_config.h
        configs/rpmsg_config.h
        fwk_platform_definitions.h
        fwk_platform_kw47_mcxw72.c
        DEVICE_IDS ${KW47_FAMILY} ${MCXW72_FAMILY}
        CORE_IDS "cm33_core0" "cm33"
    )

    mcux_add_include(INCLUDES
        .
        configs
        DEVICE_IDS ${KW47_FAMILY} ${MCXW72_FAMILY}
        CORE_IDS "cm33_core0" "cm33"
    )

    if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.seclib_rng_port.psa)
        mcux_add_source(SOURCES
            ../wireless_mcu/configs/SecLib_psa_config.h
            DEVICE_IDS ${KW47_FAMILY} ${MCXW72_FAMILY}
            CORE_IDS "cm33_core0" "cm33"
        )
        mcux_add_include(INCLUDES
            ../wireless_mcu/configs
            DEVICE_IDS ${KW47_FAMILY} ${MCXW72_FAMILY}
            CORE_IDS "cm33_core0" "cm33"
        )
    endif()

    if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.seclib_rng_port.mbedtls)
            mcux_add_source(SOURCES
            configs/SecLib_mbedtls_config.h
            DEVICE_IDS ${KW47_FAMILY} ${MCXW72_FAMILY}
            CORE_IDS "cm33_core0" "cm33"
        )
    endif()
    if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.platform.dbg)
        mcux_add_source(SOURCES
            fwk_platform_dbg.c
            ../wireless_mcu/fwk_platform_dbg.h
            DEVICE_IDS ${KW47_FAMILY} ${MCXW72_FAMILY}
            CORE_IDS "cm33_core0" "cm33"
        )
        mcux_add_include(INCLUDES
            .
            ../wireless_mcu
            DEVICE_IDS ${KW47_FAMILY} ${MCXW72_FAMILY}
            CORE_IDS "cm33_core0" "cm33"
        )
    endif()
endif()
