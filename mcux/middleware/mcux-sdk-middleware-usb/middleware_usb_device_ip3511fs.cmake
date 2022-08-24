#Description: USB Device IP3511FS Controller Driver(FS); user_visible: True
include_guard(GLOBAL)
message("middleware_usb_device_ip3511fs component is included.")

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/device/usb_device_lpcip3511.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/device
    ${CMAKE_CURRENT_LIST_DIR}/include
)


include(middleware_usb_device_common_header)
