message("connectivity_framework middleware is included.")
if(CONFIG_SOC_SERIES_RW6XX)
    target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/platform/rw61x/fwk_platform_ble.c
        ${CMAKE_CURRENT_LIST_DIR}/platform/rw61x/fwk_platform_coex.c
        ${CMAKE_CURRENT_LIST_DIR}/platform/rw61x/fwk_platform_hdlc.c
        ${CMAKE_CURRENT_LIST_DIR}/platform/rw61x/fwk_platform_ot.c
    )

    zephyr_include_directories(
        ${CMAKE_CURRENT_LIST_DIR}/platform/include
        ${CMAKE_CURRENT_LIST_DIR}/platform/rw61x
        ${CMAKE_CURRENT_LIST_DIR}/platform/rw61x/configs
        # Flash files are only included to build successfully the framework files.
        # Content is not used
        ${CMAKE_CURRENT_LIST_DIR}/../../mcux-sdk/components/flash/mflash/rdrw612bga
        ${CMAKE_CURRENT_LIST_DIR}/../../mcux-sdk/components/flash/mflash
    )

    zephyr_compile_definitions(gPlatformDisableVendorSpecificInit=1U)

    if (CONFIG_NXP_MONOLITHIC_WIFI OR CONFIG_NXP_MONOLITHIC_BT OR CONFIG_NXP_MONOLITHIC_IEEE802154)
        zephyr_compile_definitions(gPlatformMonolithicApp_d=1U)

        zephyr_compile_definitions_ifndef(CONFIG_NXP_MONOLITHIC_BT
                                          BLE_FW_ADDRESS=0U)

        zephyr_compile_definitions_ifndef(CONFIG_NXP_MONOLITHIC_WIFI
                                          WIFI_FW_ADDRESS=0U)

        zephyr_compile_definitions_ifndef(CONFIG_NXP_MONOLITHIC_IEEE802154
                                          COMBO_FW_ADDRESS=0U)
    endif()
endif()

if(CONFIG_SOC_SERIES_MCXW OR CONFIG_SOC_SERIES_KINETIS_KW45)
    target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/platform/connected_mcu/fwk_platform.c
        ${CMAKE_CURRENT_LIST_DIR}/platform/connected_mcu/fwk_platform_ble.c
        ${CMAKE_CURRENT_LIST_DIR}/platform/connected_mcu/fwk_platform_ics.c
    )

    zephyr_include_directories(
        ${CMAKE_CURRENT_LIST_DIR}/Common
        ${CMAKE_CURRENT_LIST_DIR}/platform/connected_mcu
        ${CMAKE_CURRENT_LIST_DIR}/platform/connected_mcu/configs
    )

    set(CONFIG_USE_component_osa_zephyr true)
    include(set_component_osa)
endif()
