#Description: mflash rt1170; user_visible: True
include_guard(GLOBAL)
message("component_mflash_rt1170 component is included.")

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/mflash_drv.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/.
)

#OR Logic component
if(CONFIG_USE_driver_cache_lmem) 
    include(driver_cache_lmem)
endif()
if(CONFIG_USE_driver_cache_armv7_m7) 
    include(driver_cache_armv7_m7)
endif()

include(driver_flexspi)
include(component_mflash_common)
