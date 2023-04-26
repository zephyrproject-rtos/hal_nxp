#Description: USB Device Common Controller; user_visible: True
include_guard(GLOBAL)
message("middleware_usb_device_controller_driver component is included.")

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/device/usb_device_dci.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/device
)

#OR Logic component
if(CONFIG_USE_middleware_usb_device_khci) 
    include(middleware_usb_device_khci)
endif()
if(CONFIG_USE_middleware_usb_device_ehci_MK66F18) 
    include(middleware_usb_device_ehci_MK66F18)
endif()

include(component_osa)
