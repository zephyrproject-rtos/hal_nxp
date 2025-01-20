# core related
include(${SdkRootDirPath}/arch/xtensa/core/core_${CONFIG_MCUX_HW_CORE}.cmake)

if(CONFIG_MCUX_COMPONENT_device.RTE)
    mcux_add_source(
      BASE_PATH ${SdkRootDirPath}/devices/${soc_portfolio}/${soc_series}/${device}/template
      SOURCES RTE_Device.h
      CONFIG true
    )

    mcux_add_include(
      BASE_PATH ${SdkRootDirPath}/devices/${soc_portfolio}/${soc_series}/${device}/template
      PROJECT_BASE_PATH board
      INCLUDES .
    )
endif()

# build target related
include(${SdkRootDirPath}/arch/xtensa/target/targets.cmake)
