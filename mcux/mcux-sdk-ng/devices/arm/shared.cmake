if(CONFIG_CPU_CORTEX_M)
# core related
include(${SdkRootDirPath}/arch/arm/cortexm/core_${CONFIG_MCUX_HW_CORE}.cmake)
include(${SdkRootDirPath}/arch/arm/cortexm/core_${CONFIG_MCUX_HW_FPU_TYPE}.cmake)
include(${SdkRootDirPath}/arch/arm/cortexm/cpu_define.cmake)
endif()

if(CONFIG_MCUX_COMPONENT_device.RTE)

    mcux_add_source(BASE_PATH ${SdkRootDirPath}/${device_root}/${soc_portfolio}/${soc_series}/${device}/template SOURCES RTE_Device.h CONFIG
                    true)

    mcux_add_include(BASE_PATH ${SdkRootDirPath}/${device_root}/${soc_portfolio}/${soc_series}/${device}/template TARGET_FILES RTE_Device.h
                     INCLUDES .)

endif()

# build target related
include(${SdkRootDirPath}/arch/arm/target/targets.cmake)
