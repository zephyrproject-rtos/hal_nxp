if(CONFIG_BT OR CONFIG_NET_L2_OPENTHREAD)
    list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/mcux-sdk-middleware-connectivity-framework)
    include(connectivity_framework)
    if(CONFIG_SOC_SERIES_MCXW OR CONFIG_SOC_SERIES_KINETIS_KW45)
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
    endif()
endif()
