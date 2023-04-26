#Description: USB Host Stack; user_visible: True
include_guard(GLOBAL)
message("middleware_usb_host_stack component is included.")

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/host/usb_host_hci.c
    ${CMAKE_CURRENT_LIST_DIR}/host/usb_host_devices.c
    ${CMAKE_CURRENT_LIST_DIR}/host/usb_host_framework.c
    ${CMAKE_CURRENT_LIST_DIR}/host/class/usb_host_hub.c
    ${CMAKE_CURRENT_LIST_DIR}/host/class/usb_host_hub_app.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/host
    ${CMAKE_CURRENT_LIST_DIR}/host/class
    ${CMAKE_CURRENT_LIST_DIR}/include
)


include(middleware_usb_host_ip3516hs)
include(component_osa)
