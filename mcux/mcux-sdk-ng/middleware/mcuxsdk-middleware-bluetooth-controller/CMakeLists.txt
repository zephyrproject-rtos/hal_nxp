# Copyright 2025 NXP
# SPDX-License-Identifier: BSD-3-Clause

mcux_set_list(KW45_NBU_FAMILY "KW45B41Z52xxxA_NBU KW45B41Z53xxxA_NBU  KW45B41Z82xxxA_NBU  KW45B41Z83xxxA_NBU  K32W1480xxxA_NBU")
mcux_set_list(MCXW71_NBU_FAMILY "MCXW716CxxxA_NBU MCXW716AxxxA_NBU")
mcux_set_list(KW45_FAMILY_WITHOUT_K32W1 "KW45B41Z52xxxA KW45B41Z53xxxA  KW45B41Z82xxxA  KW45B41Z83xxxA")
mcux_set_list(KW47_FAMILY "KW47B42Z83xxxA KW47B42Z96xxxA KW47B42Z97xxxA KW47B42ZB2xxxA KW47B42ZB3xxxA KW47B42ZB6xxxA KW47B42ZB7xxxA KW47Z42082xxxA KW47Z42092xxxA KW47Z420B2xxxA KW47Z420B3xxxA")
mcux_set_list(MCXW72_FAMILY "MCXW727CxxxA")
mcux_set_list(KW43_FAMILY "KW43B43ZC7xxxA_NBU")
mcux_set_list(MCXW23_FAMILY "MCXW236 MCXW235")

if(CONFIG_MCUX_COMPONENT_middleware.wireless.ble_controller_threadx)
    mcux_add_source(
        SOURCES lib/threadx_inc/tx_api.h
                lib/threadx_inc/tx_user.h
                lib/threadx_inc/tx_event_flags.h
    )
    mcux_add_source(
        SOURCES lib/threadx_inc/cortex_m3/tx_port.h
        TOOLCHAINS iar
        DEVICE_IDS ${KW45_NBU_FAMILY} ${MCXW71_NBU_FAMILY}
    )
    mcux_add_source(
        SOURCES lib/threadx_inc/cortex_m33/tx_port.h
        TOOLCHAINS iar armgcc
        DEVICE_IDS ${KW47_FAMILY} ${MCXW72_FAMILY} ${KW43_FAMILY} ${MCXW23_FAMILY}
    )
    mcux_add_include(
        INCLUDES lib/threadx_inc
    )
    mcux_add_include(
        INCLUDES lib/threadx_inc/cortex_m3
        TOOLCHAINS iar
        DEVICE_IDS ${KW45_NBU_FAMILY} ${MCXW71_NBU_FAMILY}
    )
    mcux_add_include(
        INCLUDES lib/threadx_inc/cortex_m33
        TOOLCHAINS iar armgcc
        DEVICE_IDS ${KW47_FAMILY} ${MCXW72_FAMILY} ${KW43_FAMILY} ${MCXW23_FAMILY}
    )
    mcux_add_library(
        LIBS lib/cm3_libthreadx.a
        TOOLCHAINS iar armgcc
        DEVICE_IDS ${KW45_NBU_FAMILY} ${MCXW71_NBU_FAMILY}
    )
    mcux_add_library(
        LIBS lib/cm33_libthreadx.a
        TOOLCHAINS iar armgcc
        DEVICE_IDS ${KW47_FAMILY} ${MCXW72_FAMILY} ${KW43_FAMILY} ${MCXW23_FAMILY}
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.ble_controller_nbu)
    mcux_add_source(
        SOURCES src/KW4x/nbu_ble.c
                src/KW4x/nbu_version.c
                src/KW4x/sw_version.h
                src/KW4x/controller_init.c
                src/KW4x/controller_api_ll.c
                src/KW4x/ll_types.h
                interface/controller_init.h
                lib/mll_inc/controller_api_ll.h
                src/KW4x/app.h
                src/KW4x/board.h
                src/KW4x/board.c
                src/hybrid_gfsk/hybrid_gfsk_hal.c
                lib/mll_inc/hybrid_gfsk_hal.h
                lib/mll_inc/ble_debug_struct.h
    )
    mcux_add_include(
        INCLUDES src/KW4x
                 interface
                 lib/mll_inc
                 src/hybrid_gfsk
    )
    mcux_add_source(
        TOOLCHAINS armgcc
        SOURCES src/KW4x/armgcc/nbu_ble_wrap.s
    )
    mcux_add_source(
        TOOLCHAINS iar
        SOURCES src/KW4x/iar/nbu_ble_wrap.s
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.ble_controller_nbu_interface)
    mcux_add_source(
        SOURCES src/KW4x/ll_types.h
                interface/controller_init.h
                lib/mll_inc/controller_api_ll.h
    )
    mcux_add_include(
        INCLUDES src/KW4x
                 interface
                 lib/mll_inc
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.ble_controller_nbu_app_base)
    mcux_add_source(
        SOURCES src/KW4x/nbu_version.c
                src/KW4x/sw_version.h
                src/KW4x/controller_init.c
                src/KW4x/controller_api_ll.c
                src/KW4x/ll_types.h
                interface/controller_init.h
                lib/mll_inc/controller_api_ll.h
                lib/mll_inc/ble_debug_struct.h
                src/KW4x/app.h
                src/KW4x/board.h
                src/KW4x/board.c
    )
    mcux_add_source(
        TOOLCHAINS armgcc
        SOURCES src/KW4x/armgcc/nbu_ble_wrap.s
    )
    mcux_add_source(
        TOOLCHAINS iar
        SOURCES src/KW4x/iar/nbu_ble_wrap.s
    )
    mcux_add_library(
        LIBS lib/kw47_nbu_all_hosted_libcommon.a
        TOOLCHAINS iar armgcc mcux
        DEVICE_IDS ${MCXW72_FAMILY}
    )
    mcux_add_library(
        LIBS lib/kw47_nbu_all_hosted_libbtu2_5x.a
        TOOLCHAINS iar armgcc mcux
        DEVICE_IDS ${MCXW72_FAMILY}
    )

    mcux_add_include(
        INCLUDES src/KW4x
                 interface
                 lib/mll_inc
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.ble_controller_bin)
    mcux_add_source(
        SOURCES bin/kw47_nbu_ble_all_hosted.bin
        DEVICE_IDS ${KW47_FAMILY}
    )
    mcux_add_source(
        SOURCES bin/mcxw72_nbu_ble_all_hosted.bin
        DEVICE_IDS ${MCXW72_FAMILY}
    )
    mcux_add_source(
        SOURCES bin/kw45b41_nbu_ble_hadm_hosted.sb3
        DEVICE_IDS ${KW45_FAMILY_WITHOUT_K32W1}
    )
    mcux_add_source(
        SOURCES bin/kw45b41_nbu_ble_hadm_hosted.xip
        DEVICE_IDS ${KW45_FAMILY_WITHOUT_K32W1}
    )
    mcux_add_source(
        SOURCES bin/kw45b41_nbu_ble_hosted.sb3
        DEVICE_IDS ${KW45_FAMILY_WITHOUT_K32W1}
    )
    mcux_add_source(
        SOURCES bin/kw45b41_nbu_ble_hosted.xip
        DEVICE_IDS ${KW45_FAMILY_WITHOUT_K32W1}
    )
    mcux_add_source(
        SOURCES bin/kw45b41_nbu_ble_xp_hosted.sb3
        DEVICE_IDS ${KW45_FAMILY_WITHOUT_K32W1}
    )
    mcux_add_source(
        SOURCES bin/kw45b41_nbu_ble_xp_hosted.xip
        DEVICE_IDS ${KW45_FAMILY_WITHOUT_K32W1}
    )
    mcux_add_source(
        SOURCES bin/k32w1_nbu_ble_hadm_hosted.sb3
        DEVICE_IDS K32W1480xxxA
    )
    mcux_add_source(
        SOURCES bin/k32w1_nbu_ble_hadm_hosted.xip
        DEVICE_IDS K32W1480xxxA
    )
    mcux_add_source(
        SOURCES bin/k32w1_nbu_ble_hosted.sb3
        DEVICE_IDS K32W1480xxxA
    )
    mcux_add_source(
        SOURCES bin/k32w1_nbu_ble_hosted.xip
        DEVICE_IDS K32W1480xxxA
    )
    mcux_add_source(
        SOURCES bin/k32w1_nbu_ble_xp_hosted.sb3
        DEVICE_IDS K32W1480xxxA
    )
    mcux_add_source(
        SOURCES bin/k32w1_nbu_ble_xp_hosted.xip
        DEVICE_IDS K32W1480xxxA
    )
    mcux_add_source(
        SOURCES bin/mcxw71_nbu_ble_hadm_hosted.sb3
        DEVICE_IDS ${MCXW71_FAMILY}
    )
    mcux_add_source(
        SOURCES bin/mcxw71_nbu_ble_hadm_hosted.xip
        DEVICE_IDS ${MCXW71_FAMILY}
    )
    mcux_add_source(
        SOURCES bin/mcxw71_nbu_ble_hosted.sb3
        DEVICE_IDS ${MCXW71_FAMILY}
    )
    mcux_add_source(
        SOURCES bin/mcxw71_nbu_ble_hosted.xip
        DEVICE_IDS ${MCXW71_FAMILY}
    )
    mcux_add_source(
        SOURCES bin/mcxw71_nbu_ble_xp_hosted.sb3
        DEVICE_IDS ${MCXW71_FAMILY}
    )
    mcux_add_source(
        SOURCES bin/mcxw71_nbu_ble_xp_hosted.xip
        DEVICE_IDS ${MCXW71_FAMILY}
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.ble_controller_dtm)
    mcux_add_source(
        SOURCES src/dtm/dtm.c
                interface/dtm.h
    )
    mcux_add_include(
        INCLUDES interface
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.controller_api)
    mcux_add_source(
        SOURCES src/controller_api.c
                src/hybrid_gfsk/hybrid_gfsk.c
                interface/controller_api.h
                interface/controller_interface.h
                interface/hybrid_gfsk.h
    )
    mcux_add_include(
        INCLUDES interface
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.ble_controller_hadm)
    # common header files
    mcux_add_source(
        SOURCES
                lib/mll_inc/ble_hadm_hal.h
                lib/mll_inc/ble_hadm_types.h
                lib/mll_inc/ble_hadm_api.h
                src/hadm/lcl_hadm_hartt.h
                src/hadm/lcl_hadm_aes.h
    )

    # kw47/mcxw72 - using an optimized library prebuilt with IAR toolchain
    mcux_add_source(
        SOURCES src/hadm/kw47_mcxw72x_nbu/lcl_hadm_measurement.h
                src/hadm/kw47_mcxw72x_nbu/lcl_hadm_utils.h
                src/hadm/kw47_mcxw72x_nbu/lcl_xcvr_hal.h
        DEVICE_IDS ${KW47_FAMILY} ${MCXW72_FAMILY} ${KW43_FAMILY}
        CORE_IDS "cm33" "cm33_core1"
    )
    mcux_add_include(
        INCLUDES interface
                 src/hadm
                 src/hadm/kw47_mcxw72x_nbu
        DEVICE_IDS ${KW47_FAMILY} ${MCXW72_FAMILY} ${KW43_FAMILY}
    )
    mcux_add_library(
        LIBS lib/ble_hadm_kw47_mcxw72x_nbu.a
        TOOLCHAINS kds armgcc mcux iar
        DEVICE_IDS ${KW47_FAMILY} ${MCXW72_FAMILY}
    )
    # kw43 uses the same sources than kw47 but external dependencies are different
    # so to guarantee compatibility, add a specific library
    mcux_add_library(
        LIBS lib/ble_hadm_kw43_mcxw70_nbu.a
        TOOLCHAINS kds armgcc mcux iar
        DEVICE_IDS ${KW43_FAMILY}
    )

    # kw45/mcxw71 - compiling from sources
    mcux_add_source(
        SOURCES src/hadm/kw45_k32w1_nbu/lcl_hadm_measurement.c
                src/hadm/kw45_k32w1_nbu/lcl_hadm_measurement.h
                src/hadm/kw45_k32w1_nbu/lcl_hadm_utils.c
                src/hadm/kw45_k32w1_nbu/lcl_hadm_utils.h
                src/hadm/kw45_k32w1_nbu/lcl_xcvr_hal.h
                src/hadm/kw45_k32w1_nbu/lcl_xcvr_hal.c
                src/hadm/ble_hadm_hal_impl.c
                src/hadm/lcl_hadm_hartt.c
                src/hadm/lcl_hadm_aes.c
        DEVICE_IDS ${KW45_NBU_FAMILY} ${MCXW71_NBU_FAMILY}
    )
    mcux_add_include(
        INCLUDES interface
                 src/hadm
                 src/hadm/kw45_k32w1_nbu
        DEVICE_IDS ${KW45_NBU_FAMILY} ${MCXW71_NBU_FAMILY}
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.ble_controller_interface)
    mcux_add_source(
        SOURCES interface/controller_interface.h
    )
    mcux_add_include(
        INCLUDES interface
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.nbu_hosted_lib)
    mcux_add_library(
        LIBS ../marvell_ll/src/build/kw4x/lib/kw45b41_nbu_hosted_libbtu2_5x.a
        TOOLCHAINS kds armgcc mcux iar
        DEVICE_IDS ${KW45_NBU_FAMILY}
    )
    mcux_add_library(
        LIBS ../marvell_ll/src/build/kw4x/lib/kw45b41_nbu_hosted_libcommon.a
        TOOLCHAINS kds armgcc mcux iar
        DEVICE_IDS ${KW45_NBU_FAMILY} ${MCXW71_NBU_FAMILY}
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.nbu_hadm_hosted_lib)
    mcux_add_library(
        LIBS ../marvell_ll/src/build/kw4x/lib/kw45b41_nbu_hadm_hosted_libbtu2_5x.a
        TOOLCHAINS kds armgcc mcux iar
        DEVICE_IDS ${KW45_NBU_FAMILY} ${MCXW71_NBU_FAMILY}
    )
    mcux_add_library(
        LIBS ../marvell_ll/src/build/kw4x/lib/kw45b41_nbu_hosted_hadm_libcommon.a
        TOOLCHAINS kds armgcc mcux iar
        DEVICE_IDS ${KW45_NBU_FAMILY} ${MCXW71_NBU_FAMILY}
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.nbu_xp_hosted_lib)
    mcux_add_library(
        LIBS ../marvell_ll/src/build/kw4x/lib/kw45b41_nbu_xp_hosted_libbtu2_5x.a
        TOOLCHAINS kds armgcc mcux iar
        DEVICE_IDS ${KW45_NBU_FAMILY} ${MCXW71_NBU_FAMILY}
    )
    mcux_add_library(
        LIBS ../marvell_ll/src/build/kw4x/lib/kw45b41_nbu_xp_hosted_libcommon.a
        TOOLCHAINS kds armgcc mcux iar
        DEVICE_IDS ${KW45_NBU_FAMILY} ${MCXW71_NBU_FAMILY}
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.nbu_all_hosted_lib)
    mcux_add_library(
        LIBS lib/kw47_nbu_all_hosted_libbtu2_5x.a
        TOOLCHAINS kds armgcc mcux iar
        DEVICE_IDS ${KW47_FAMILY} ${MCXW72_FAMILY}
    )
    mcux_add_library(
        LIBS lib/kw47_nbu_all_hosted_libcommon.a
        TOOLCHAINS kds armgcc mcux iar
        DEVICE_IDS ${KW47_FAMILY} ${MCXW72_FAMILY}
    )
    mcux_add_library(
        LIBS ../marvell_ll/src/build/kw4x/lib/kw43_nbu_all_hosted_libbtu2_5x.a
        TOOLCHAINS armgcc iar
        DEVICE_IDS ${KW43_FAMILY}
    )
    mcux_add_library(
        LIBS ../marvell_ll/src/build/kw4x/lib/kw43_nbu_all_hosted_libcommon.a
        TOOLCHAINS armgcc iar
        DEVICE_IDS ${KW43_FAMILY}
    )
    mcux_add_library(
        LIBS ../marvell_ll/src/build/kw4x/lib/kw45b41_nbu_hosted_libbtu2_5x.a
        TOOLCHAINS kds armgcc mcux iar
        DEVICE_IDS ${KW45_NBU_FAMILY}
    )
    mcux_add_library(
        LIBS ../marvell_ll/src/build/kw4x/lib/kw45b41_nbu_hosted_libcommon.a
        TOOLCHAINS kds armgcc mcux iar
        DEVICE_IDS ${KW45_NBU_FAMILY} ${MCXW71_NBU_FAMILY}
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.nbu_matter_hosted_lib)
    mcux_add_library(
        LIBS lib/kw47_nbu_matter_hosted_libbtu2_5x.a
        TOOLCHAINS kds armgcc mcux iar
        DEVICE_IDS ${KW47_FAMILY} ${MCXW72_FAMILY}
    )
    mcux_add_library(
        LIBS lib/kw47_nbu_matter_hosted_libcommon.a
        TOOLCHAINS kds armgcc mcux iar
        DEVICE_IDS ${KW47_FAMILY} ${MCXW72_FAMILY}
    )
    mcux_add_library(
        LIBS ../marvell_ll/src/build/kw4x/lib/kw45b41_nbu_matter_hosted_libbtu2_5x.a
        TOOLCHAINS kds armgcc mcux iar
        DEVICE_IDS ${KW45_NBU_FAMILY}
    )
    mcux_add_library(
        LIBS ../marvell_ll/src/build/kw4x/lib/kw45b41_nbu_matter_hosted_libcommon.a
        TOOLCHAINS kds armgcc mcux iar
        DEVICE_IDS ${KW45_NBU_FAMILY} ${MCXW71_NBU_FAMILY}
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.ble_controller_MWS)
    mcux_add_source(
        SOURCES src/mws/ble_mws.c
                src/mws/ble_mws.h
    )
    mcux_add_include(
        INCLUDES src/mws
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.ble_controller_hybrid_gfsk)
    mcux_add_source(
        SOURCES src/hybrid_gfsk/hybrid_gfsk.c
                interface/hybrid_gfsk.h
    )
    mcux_add_include(
        INCLUDES interface
    )
endif()

include(./CMakeLists_snps.txt)