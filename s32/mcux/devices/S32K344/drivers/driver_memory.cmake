include_guard(GLOBAL)
message("driver_memory component is included.")

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
    # nothing to build
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/.
)
