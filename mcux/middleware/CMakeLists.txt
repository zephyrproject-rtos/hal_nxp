if(CONFIG_BT OR CONFIG_NET_L2_IEEE802154 OR CONFIG_NET_L2_OPENTHREAD)
    list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/mcux-sdk-middleware-connectivity-framework)
    include(connectivity_framework)
    if(CONFIG_SOC_SERIES_MCXW)
        zephyr_include_directories(${CMAKE_CURRENT_LIST_DIR}/mcux-sdk-middleware-multicore/mcmgr/src)

        zephyr_library_sources(
            ${CMAKE_CURRENT_LIST_DIR}/mcux-sdk-middleware-multicore/mcmgr/src/mcmgr_internal_core_api_mcxw716_ext.c
            ${CMAKE_CURRENT_LIST_DIR}/mcux-sdk-middleware-multicore/mcmgr/src/mcmgr_internal_core_api_mcxw716.c
            ${CMAKE_CURRENT_LIST_DIR}/mcux-sdk-middleware-multicore/mcmgr/src/mcmgr.c
            ${CMAKE_CURRENT_LIST_DIR}/mcux-sdk-middleware-multicore/mcmgr/src/mcmgr_imu_internal.c
        )

        zephyr_include_directories(
            ${CMAKE_CURRENT_LIST_DIR}/mcux-sdk-middleware-multicore/rpmsg_lite/lib/include
            ${CMAKE_CURRENT_LIST_DIR}/mcux-sdk-middleware-multicore/rpmsg_lite/lib/include/platform/kw45b41
            ${CMAKE_CURRENT_LIST_DIR}/mcux-sdk-middleware-multicore/rpmsg_lite/lib/include/environment/zephyr
        )

        zephyr_library_sources(
            ${CMAKE_CURRENT_LIST_DIR}/mcux-sdk-middleware-multicore/rpmsg_lite/lib/common/llist.c
            ${CMAKE_CURRENT_LIST_DIR}/mcux-sdk-middleware-multicore/rpmsg_lite/lib/virtio/virtqueue.c
            ${CMAKE_CURRENT_LIST_DIR}/mcux-sdk-middleware-multicore/rpmsg_lite/lib/rpmsg_lite/porting/platform/kw45b41/rpmsg_platform_ext.c
            ${CMAKE_CURRENT_LIST_DIR}/mcux-sdk-middleware-multicore/rpmsg_lite/lib/rpmsg_lite/porting/environment/rpmsg_env_zephyr.c
            ${CMAKE_CURRENT_LIST_DIR}/mcux-sdk-middleware-multicore/rpmsg_lite/lib/rpmsg_lite/porting/platform/kw45b41/rpmsg_platform.c
            ${CMAKE_CURRENT_LIST_DIR}/mcux-sdk-middleware-multicore/rpmsg_lite/lib/rpmsg_lite/rpmsg_lite.c
        )

        if(CONFIG_NET_L2_IEEE802154 OR CONFIG_NET_L2_OPENTHREAD)
            zephyr_include_directories(
                ${CMAKE_CURRENT_LIST_DIR}/mcux-sdk-middleware-ieee_802.15.4/ieee_802_15_4/phy/interface
            )

            zephyr_library_sources(
                ${CMAKE_CURRENT_LIST_DIR}/mcux-sdk-middleware-ieee_802.15.4/ieee_802_15_4/phy/source/PhyTime.c
                ${CMAKE_CURRENT_LIST_DIR}/mcux-sdk-middleware-ieee_802.15.4/ieee_802_15_4/phy/source/SerialDevice/Phy.c
            )
            zephyr_compile_definitions(USE_NBU=1)
            zephyr_compile_definitions(MEM_USE_ZEPHYR=1U)
        endif()
    endif()
endif()
