#Description: Component flexcomm_i2s_dma_adapter; user_visible: True
include_guard(GLOBAL)
message("component_audio_flexcomm_i2s_dma_adapter component is included.")

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/fsl_adapter_flexcomm_i2s.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/.
)


include(driver_common)
include(driver_flexcomm_i2s_dma)
