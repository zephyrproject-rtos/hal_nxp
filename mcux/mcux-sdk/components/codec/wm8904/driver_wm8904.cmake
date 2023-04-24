#Description: Driver wm8904; user_visible: True
include_guard(GLOBAL)
message("driver_wm8904 component is included.")

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/fsl_wm8904.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/.
)

#OR Logic component
if(${MCUX_DEVICE} STREQUAL "LPC55S69_cm33_core0")
    include(component_codec_i2c_LPC55S69_cm33_core0)
endif()
if(${MCUX_DEVICE} STREQUAL "MIMXRT595S_cm33")
    include(component_codec_i2c_MIMXRT595S_cm33)
endif()
if(${MCUX_DEVICE} STREQUAL "LPC54114_cm4")
    include(component_codec_i2c_LPC54114_cm4)
endif()
if(${MCUX_DEVICE} STREQUAL "LPC54113_cm4")
    include(component_codec_i2c_LPC54114_cm4)
endif()

