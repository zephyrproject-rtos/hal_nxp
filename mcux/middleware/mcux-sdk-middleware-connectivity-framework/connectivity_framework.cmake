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
        ${CMAKE_CURRENT_LIST_DIR}/../../mcux-sdk-ng/components/flash/mflash/rdrw612bga
        ${CMAKE_CURRENT_LIST_DIR}/../../mcux-sdk-ng/components/flash/mflash
    )

    zephyr_compile_definitions(gPlatformDisableVendorSpecificInit=1U)

    if (CONFIG_NXP_MONOLITHIC_WIFI OR CONFIG_NXP_MONOLITHIC_NBU)
        zephyr_compile_definitions(
            gPlatformMonolithicApp_d=1U
            fw_cpu2_ble=fw_cpu2
            fw_cpu2_combo=fw_cpu2
        )

        zephyr_compile_definitions_ifndef(CONFIG_NXP_MONOLITHIC_NBU
                                          BLE_FW_ADDRESS=0U
                                          COMBO_FW_ADDRESS=0U)

        zephyr_compile_definitions_ifndef(CONFIG_NXP_MONOLITHIC_WIFI
                                          WIFI_FW_ADDRESS=0U)
    endif()
endif()

if(CONFIG_SOC_FAMILY_MCXW)
    target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/platform/wireless_mcu/fwk_platform.c
        ${CMAKE_CURRENT_LIST_DIR}/platform/wireless_mcu/fwk_platform_ics.c
        ${CMAKE_CURRENT_LIST_DIR}/platform/wireless_mcu/fwk_platform_ot.c
        ${CMAKE_CURRENT_LIST_DIR}/platform/wireless_mcu/fwk_platform_ble.c
    )

    if(CONFIG_SOC_MCXW716C)
        set(platform "kw45_k32w1_mcxw71")
    elseif(CONFIG_SOC_MCXW727C_CPU0)
        set(platform "kw47_mcxw72")
    endif()

    zephyr_include_directories(
        ${CMAKE_CURRENT_LIST_DIR}/Common
        ${CMAKE_CURRENT_LIST_DIR}/platform/wireless_mcu
        ${CMAKE_CURRENT_LIST_DIR}/platform/${platform}
        ${CMAKE_CURRENT_LIST_DIR}/platform/${platform}/configs
    )

    if(DEFINED CONFIG_SOC_SDKNG_UNSUPPORTED)
        include(set_component_osa)
        set(CONFIG_USE_component_osa_zephyr true)
    endif()

endif()
