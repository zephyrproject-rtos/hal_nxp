include(${SdkRootDirPath}/devices/arm/device_header_multicore.cmake)

# core related
include(${CMAKE_CURRENT_LIST_DIR}/${core_id}/setting.cmake)

# device specific drivers
mcux_add_cmakelists(${CMAKE_CURRENT_LIST_DIR}/drivers)

include(${SdkRootDirPath}/devices/RT/shared.cmake)

