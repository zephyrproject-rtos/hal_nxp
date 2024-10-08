#Description: FLEXCOMM I2C Driver; user_visible: True
include_guard(GLOBAL)
message("driver_flexcomm_i2c component is included.")

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/i2c/fsl_i2c.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/i2c/.
)


include(driver_flexcomm)
