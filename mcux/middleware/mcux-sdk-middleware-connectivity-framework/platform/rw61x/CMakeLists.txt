set(SOURCES
    fwk_platform.c
    fwk_platform_ble.c
    fwk_platform_lowpower.c
    fwk_platform_sensors.c
    fwk_platform_hdlc.c
    fwk_platform_ot.c
    fwk_platform_coex.c
    fwk_platform_extflash.c
    fwk_platform_ota.c
    configs/fwk_lfs_config.c
)

if(CONNFWK_IGNORE_PLATFORM)
    list(REMOVE_ITEM SOURCES fwk_platform.c)
endif()

if(CONNFWK_IGNORE_PLATFORM_BLE)
    list(REMOVE_ITEM SOURCES fwk_platform_ble.c)
endif()

if(CONNFWK_IGNORE_PLATFORM_LOWPOWER)
    list(REMOVE_ITEM SOURCES fwk_platform_lowpower.c)
endif()

if(CONNFWK_IGNORE_PLATFORM_SENSORS)
    list(REMOVE_ITEM SOURCES fwk_platform_sensors.c)
endif()

if(CONNFWK_IGNORE_PLATFORM_HDLC)
    list(REMOVE_ITEM SOURCES fwk_platform_hdlc.c)
endif()

if(CONNFWK_IGNORE_PLATFORM_OT)
    list(REMOVE_ITEM SOURCES fwk_platform_ot.c)
endif()

if(CONNFWK_IGNORE_PLATFORM_COEX)
    list(REMOVE_ITEM SOURCES fwk_platform_coex.c)
endif()

if(CONNFWK_IGNORE_PLATFORM_EXTFLASH)
    list(REMOVE_ITEM SOURCES fwk_platform_extflash.c)
endif()

if(CONNFWK_IGNORE_PLATFORM_OTA)
    list(REMOVE_ITEM SOURCES fwk_platform_ota.c)
endif()

add_library(${CONNFWK_PLATFORM_LIB} ${SOURCES})

# Making those includes PUBLIC will share them to the other targets linking this lib
target_include_directories(${CONNFWK_PLATFORM_LIB}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/../include
        ${CMAKE_CURRENT_SOURCE_DIR}
        configs
)

# Get common configs from the connfwk-config interface
target_link_libraries(${CONNFWK_PLATFORM_LIB}
    PRIVATE
        connfwk-config
        connfwk-FunctionLib
    PUBLIC
        ${CONNFWK_MCUX_SDK_LIB}
)

if(MCUBOOT_MONOLITHIC_OTA)
    target_compile_definitions(${CONNFWK_PLATFORM_LIB}
        PUBLIC
            gPlatformMonolithicApp_d=1
    )
endif()

if(PROJECT_IS_TOP_LEVEL)
    connfwk_target_set_linker_script(${CONNFWK_PLATFORM_LIB} PUBLIC ${CONNFWK_PLATFORM_LINKER_FILE})
    # Rebuild executables if the linker script is changed
    set_target_properties(connfwk-config PROPERTIES INTERFACE_LINK_DEPENDS ${CONNFWK_PLATFORM_LINKER_FILE})
    connfwk_target_generate_map_file(${CONNFWK_PLATFORM_LIB} PUBLIC ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/$<TARGET_PROPERTY:NAME>.map)
endif()
