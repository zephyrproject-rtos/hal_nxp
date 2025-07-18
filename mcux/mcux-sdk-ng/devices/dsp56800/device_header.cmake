# device spcific drivers for single core device
if(CONFIG_MCUX_COMPONENT_device.CMSIS)

    mcux_add_source(
        BASE_PATH ${SdkRootDirPath}/${device_root}/${soc_portfolio}/${soc_series}/${device} 
        SOURCES fsl_device_registers.h
                ${CONFIG_MCUX_HW_DEVICE_CORE}.h
                ${CONFIG_MCUX_HW_DEVICE_CORE}_features.h
                ${CONFIG_MCUX_HW_DEVICE_CORE}_COMMON.h
                ../${soc_periph}/*.h
    )

    mcux_add_include(BASE_PATH ${SdkRootDirPath}/${device_root}/${soc_portfolio}/${soc_series}/${device} INCLUDES .)
    mcux_add_include(BASE_PATH ${SdkRootDirPath}/${device_root}/${soc_portfolio}/${soc_series}/${soc_periph} INCLUDES .)

endif()

if(CONFIG_MCUX_COMPONENT_device.startup)
    mcux_add_source(
        BASE_PATH ${SdkRootDirPath}/${device_root}/${soc_portfolio}/${soc_series}/${device}/codewarrior
        SOURCES ${device}_Vectors.c
        TOOLCHAINS codewarrior
        CONFIG true
    )

    mcux_add_include(BASE_PATH ${SdkRootDirPath}/${device_root}/${soc_portfolio}/${soc_series}/${device}/codewarrior INCLUDES .)
endif()

include(${SdkRootDirPath}/${device_root}/${soc_portfolio}/${soc_series}/codewarrior/CMakeLists.txt)