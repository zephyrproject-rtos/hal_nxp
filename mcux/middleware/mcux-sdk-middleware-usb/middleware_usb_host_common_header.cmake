#Description: USB Host Common Header; user_visible: True
include_guard(GLOBAL)
message("middleware_usb_host_common_header component is included.")

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/host
)


include(middleware_usb_common_header)
