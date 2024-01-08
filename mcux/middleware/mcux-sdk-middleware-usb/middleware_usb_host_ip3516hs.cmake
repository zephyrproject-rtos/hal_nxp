#Description: USB Host IP3516HS Controller Driver(HS); user_visible: True
include_guard(GLOBAL)
message("middleware_usb_host_ip3516hs component is included.")

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/host/usb_host_ip3516hs.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/host
    ${CMAKE_CURRENT_LIST_DIR}/include
)


include(middleware_usb_host_common_header)
include(middleware_usb_phy)
