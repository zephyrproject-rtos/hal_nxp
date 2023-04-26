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

#OR Logic component
if(CONFIG_USE_middleware_usb_host_ehci_MK66F18) 
    include(middleware_usb_host_ehci_MK66F18)
endif()
if(CONFIG_USE_middleware_usb_host_khci) 
    include(middleware_usb_host_khci)
endif()

include(component_osa)
