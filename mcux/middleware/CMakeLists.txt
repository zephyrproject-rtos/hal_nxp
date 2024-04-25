if(CONFIG_BT)
    list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/mcux-sdk-middleware-connectivity-framework)
    include(connectivity_framework)
endif()
