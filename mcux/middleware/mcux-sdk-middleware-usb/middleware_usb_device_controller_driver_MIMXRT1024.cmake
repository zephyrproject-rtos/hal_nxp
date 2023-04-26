#Description: USB Device Common Controller; user_visible: True
include_guard(GLOBAL)
message("middleware_usb_device_controller_driver component is included.")

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/device/usb_device_dci.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/device
)


include(middleware_usb_device_ehci_MIMXRT1024)
include(component_osa)
