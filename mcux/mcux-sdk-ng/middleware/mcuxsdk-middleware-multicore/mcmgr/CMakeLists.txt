#
# Copyright 2024-2025 NXP
#
# SPDX-License-Identifier: BSD-3-Clause
#

if (CONFIG_MCUX_COMPONENT_middleware.multicore.mcmgr)
    mcux_add_include(
        INCLUDES inc
    )

    mcux_add_source(
        SOURCES inc/mcmgr.h
                inc/mcmgr_internal_core_api.h
                src/mcmgr.c
    )

    mcux_add_configuration(
            CC "-DMULTICORE_APP=1"
            CX "-DMULTICORE_APP=1"
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.multicore.mcmgr.imxrt700)
    mcux_add_source(
            SOURCES src/mcmgr_internal_core_api_imxrt700.c
                    src/mcmgr_mu_internal.c
    )

    mcux_add_include(
        INCLUDES inc/platform/imxrt700/
    )

    mcux_add_source(
        SOURCES inc/platform/imxrt700/mcmgr_platform.h
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.multicore.mcmgr.imxrt1160)
    mcux_add_source(
            SOURCES src/mcmgr_internal_core_api_imxrt1160.c
                    src/mcmgr_mu_internal.c
    )

    mcux_add_include(
        INCLUDES inc/platform/imxrt1160/
    )

    mcux_add_source(
        SOURCES inc/platform/imxrt1160/mcmgr_platform.h
    )
endif()

if (CONFIG_MCUX_COMPONENT_middleware.multicore.mcmgr.imxrt1170)
    mcux_add_source(
            SOURCES src/mcmgr_internal_core_api_imxrt1170.c
                    src/mcmgr_mu_internal.c
    )

    mcux_add_include(
        INCLUDES inc/platform/imxrt1170/
    )

    mcux_add_source(
        SOURCES inc/platform/imxrt1170/mcmgr_platform.h
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.multicore.mcmgr.imxrt1180)
    mcux_add_source(
            SOURCES src/mcmgr_internal_core_api_imxrt1180.c
                    src/mcmgr_mu_internal.c
    )

    mcux_add_include(
        INCLUDES inc/platform/imxrt1180/
    )

    mcux_add_source(
        SOURCES inc/platform/imxrt1180/mcmgr_platform.h
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.multicore.mcmgr.k32l3a6)
    mcux_add_source(
            SOURCES src/mcmgr_internal_core_api_k32l3a6.c
                    src/mcmgr_mu_internal.c
    )

    mcux_add_include(
        INCLUDES inc/platform/k32l3a6/
    )

    mcux_add_source(
        SOURCES inc/platform/k32l3a6/mcmgr_platform.h
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.multicore.mcmgr.k32w1)
    mcux_add_source(
            SOURCES src/mcmgr_internal_core_api_k32w1.c
                    src/mcmgr_internal_core_api_k32w1_ext.c
                    src/mcmgr_imu_internal.c
                    inc/mcmgr_imu_internal.h
    )

    mcux_add_include(
        INCLUDES inc/platform/k32w1/
    )

    mcux_add_source(
        SOURCES inc/platform/k32w1/mcmgr_platform.h
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.multicore.mcmgr.kw45b41)
    mcux_add_source(
            SOURCES src/mcmgr_internal_core_api_kw45b41.c
                    src/mcmgr_internal_core_api_kw45b41_ext.c
                    src/mcmgr_imu_internal.c
                    inc/mcmgr_imu_internal.h
    )

    mcux_add_include(
        INCLUDES inc/platform/kw45b41/
    )

    mcux_add_source(
        SOURCES inc/platform/kw45b41/mcmgr_platform.h
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.multicore.mcmgr.kw47b42)
    mcux_add_source(
            SOURCES src/mcmgr_internal_core_api_kw47b42.c
                    src/mcmgr_internal_core_api_kw47b42_ext.c
                    src/mcmgr_imu_internal.c
                    inc/mcmgr_imu_internal.h
    )

    mcux_add_include(
        INCLUDES inc/platform/kw47b42/
    )

    mcux_add_source(
        SOURCES inc/platform/kw47b42/mcmgr_platform.h
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.multicore.mcmgr.kw43b43)
    mcux_add_source(
            SOURCES src/mcmgr_internal_core_api_kw43b43.c
                    src/mcmgr_mu_internal.c
    )

    mcux_add_include(
        INCLUDES inc/platform/kw43b43/
    )

    mcux_add_source(
        SOURCES inc/platform/kw43b43/mcmgr_platform.h
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.multicore.mcmgr.lpc55s69)
    mcux_add_source(
            SOURCES src/mcmgr_internal_core_api_lpc55s69.c
    )

    mcux_add_include(
        INCLUDES inc/platform/lpc55s69/
    )

    mcux_add_source(
        SOURCES inc/platform/lpc55s69/mcmgr_platform.h
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.multicore.mcmgr.lpc54114)
    mcux_add_source(
            SOURCES src/mcmgr_internal_core_api_lpc54114.c
    )

    mcux_add_include(
        INCLUDES inc/platform/lpc54114/
    )

    mcux_add_source(
        SOURCES inc/platform/lpc54114/mcmgr_platform.h
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.multicore.mcmgr.mcxnx4x)
    mcux_add_source(
            SOURCES src/mcmgr_internal_core_api_mcxnx4x.c
    )

    mcux_add_include(
        INCLUDES inc/platform/mcxnx4x/
    )

    mcux_add_source(
        SOURCES inc/platform/mcxnx4x/mcmgr_platform.h
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.multicore.mcmgr.mcxl20)
    mcux_add_source(
            SOURCES src/mcmgr_internal_core_api_mcxl20.c
                    src/mcmgr_mu_internal.c
            )

            mcux_add_include(
                INCLUDES inc/platform/mcxl20/
            )
        
            mcux_add_source(
                SOURCES inc/platform/mcxl20/mcmgr_platform.h
            )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.multicore.mcmgr.mcxw716)
    mcux_add_source(
            SOURCES src/mcmgr_internal_core_api_mcxw716.c
                    src/mcmgr_internal_core_api_mcxw716_ext.c
                    src/mcmgr_imu_internal.c
                    inc/mcmgr_imu_internal.h
    )

    mcux_add_include(
        INCLUDES inc/platform/mcxw716/
    )

    mcux_add_source(
        SOURCES inc/platform/mcxw716/mcmgr_platform.h
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.multicore.mcmgr.mcxw727)
    mcux_add_source(
            SOURCES src/mcmgr_internal_core_api_mcxw727.c
                    src/mcmgr_internal_core_api_mcxw727_ext.c
                    src/mcmgr_imu_internal.c
                    inc/mcmgr_imu_internal.h
    )

    mcux_add_include(
        INCLUDES inc/platform/mcxw727/
    )

    mcux_add_source(
        SOURCES inc/platform/mcxw727/mcmgr_platform.h
    )
endif()
