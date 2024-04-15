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

    if (CONFIG_MONOLITHIC_WIFI OR CONFIG_MONOLITHIC_BT OR CONFIG_MONOLITHIC_IEEE802154)
        zephyr_compile_definitions(gPlatformMonolithicApp_d=1U)

        zephyr_compile_definitions_ifndef(CONFIG_MONOLITHIC_BT
                                          BLE_FW_ADDRESS=0U)

        zephyr_compile_definitions_ifndef(CONFIG_MONOLITHIC_WIFI
                                          WIFI_FW_ADDRESS=0U)

        zephyr_compile_definitions_ifndef(CONFIG_MONOLITHIC_IEEE802154
                                          COMBO_FW_ADDRESS=0U)
    endif()
endif()
