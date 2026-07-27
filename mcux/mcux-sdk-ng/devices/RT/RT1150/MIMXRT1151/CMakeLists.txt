include(${SdkRootDirPath}/devices/arm/device_header.cmake)

# XIP related
mcux_add_cmakelists(${CMAKE_CURRENT_LIST_DIR}/xip)

# device specific drivers
mcux_add_cmakelists(${CMAKE_CURRENT_LIST_DIR}/drivers)

include(${SdkRootDirPath}/devices/RT/shared.cmake)

