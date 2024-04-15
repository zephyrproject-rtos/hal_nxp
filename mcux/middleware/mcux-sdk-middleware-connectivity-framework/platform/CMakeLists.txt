# Configure the platform lib
add_subdirectory(${CONNFWK_PLATFORM})

if(CONNFWK_PLATFORM_FAMILY)
    target_include_directories(connfwk-config INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/${CONNFWK_PLATFORM_FAMILY}/${CONNFWK_PLATFORM}
    )
    add_subdirectory(${CONNFWK_PLATFORM_FAMILY})
endif()
