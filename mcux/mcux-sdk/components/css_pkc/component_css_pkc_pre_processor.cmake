#Description: Component css_pkc_pre_processor; user_visible: False
include_guard(GLOBAL)
message("component_css_pkc_pre_processor component is included.")

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/.
    ${CMAKE_CURRENT_LIST_DIR}/src/comps/mcuxCsslCPreProcessor/inc
    ${CMAKE_CURRENT_LIST_DIR}/src/comps/mcuxCsslCPreProcessor/inc/internal
)


