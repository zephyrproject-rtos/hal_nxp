#Description: Driver fro_calib; user_visible: True
include_guard(GLOBAL)
message("driver_fro_calib component is included.")

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/drivers
)


include(driver_common)
