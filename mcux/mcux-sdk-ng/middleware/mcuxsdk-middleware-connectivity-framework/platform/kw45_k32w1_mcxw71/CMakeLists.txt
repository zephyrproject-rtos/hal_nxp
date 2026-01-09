# Copyright 2024-2025 NXP
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.platform.kw45_k32w1_mcxw71)
    mcux_add_cmakelists(${CMAKE_CURRENT_LIST_DIR}/../wireless_mcu)

    mcux_set_list(KW45_FAMILY "KW45B41Z52xxxA KW45B41Z53xxxA  KW45B41Z82xxxA  KW45B41Z83xxxA  K32W1480xxxA")
    mcux_set_list(MCXW71_FAMILY "MCXW716CxxxA MCXW716AxxxA")

    mcux_add_source(SOURCES
        configs/fwk_config.h
        configs/rpmsg_config.h
        fwk_platform_definitions.h
        fwk_platform_kw45_mcxw71.c
        DEVICE_IDS ${KW45_FAMILY} ${MCXW71_FAMILY}
        CORE_IDS "cm33_core0" "cm33"
    )

    mcux_add_include(INCLUDES
        .
        configs
        DEVICE_IDS ${KW45_FAMILY} ${MCXW71_FAMILY}
        CORE_IDS "cm33_core0" "cm33"
    )

    if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.seclib_rng_port.psa)
        mcux_add_source(SOURCES
            ../wireless_mcu/configs/SecLib_psa_config.h
            DEVICE_IDS ${KW45_FAMILY} ${MCXW71_FAMILY}
            CORE_IDS "cm33_core0" "cm33"
        )
        mcux_add_include(INCLUDES
            ../wireless_mcu/configs
            DEVICE_IDS ${KW45_FAMILY} ${MCXW71_FAMILY}
            CORE_IDS "cm33_core0" "cm33"
        )
    endif()

    if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.seclib_rng_port.mbedtls)
        mcux_add_source(SOURCES
            configs/SecLib_mbedtls_config.h
            DEVICE_IDS ${KW45_FAMILY} ${MCXW71_FAMILY}
            CORE_IDS "cm33_core0" "cm33"
        )
    endif()
endif()
