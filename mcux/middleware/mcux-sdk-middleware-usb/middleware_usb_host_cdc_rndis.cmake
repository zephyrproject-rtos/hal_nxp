#Description: USB Host CDC RNDIS; user_visible: True
include_guard(GLOBAL)
message("middleware_usb_host_cdc_rndis component is included.")

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/host/class/usb_host_cdc_rndis.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/host/class
)


include(middleware_usb_host_cdc)
