if(CONFIG_MCUX_COMPONENT_device.CMSIS)
    mcux_add_source(BASE_PATH ${SdkRootDirPath}/${device_root}/${soc_portfolio}/${soc_series}/${device} SOURCES fsl_device_registers.h)
    mcux_add_source(BASE_PATH ${SdkRootDirPath}/${device_root}/${soc_portfolio}/${soc_series}/${device} SOURCES ${device}_hifi4.h CORE_IDS hifi4)
    mcux_add_source(BASE_PATH ${SdkRootDirPath}/${device_root}/${soc_portfolio}/${soc_series}/${device} SOURCES ${device}_hifi4_features.h CORE_IDS hifi4)
    mcux_add_source(BASE_PATH ${SdkRootDirPath}/${device_root}/${soc_portfolio}/${soc_series}/${device} SOURCES ${CONFIG_MCUX_HW_DEVICE_CORE}_COMMON.h CORE_IDS hifi4)

    mcux_add_include(BASE_PATH ${SdkRootDirPath}/${device_root}/${soc_portfolio}/${soc_series}/${soc_periph} INCLUDES .)
    mcux_add_include(BASE_PATH ${SdkRootDirPath}/${device_root}/${soc_portfolio}/${soc_series}/${device} INCLUDES .)
endif()

if(CONFIG_MCUX_COMPONENT_device.system)
    mcux_add_source(
        BASE_PATH
        ${SdkRootDirPath}/${device_root}/${soc_portfolio}/${soc_series}/${device}
        SOURCES
        system_${device}_hifi4.c
        system_${device}_hifi4.h
        TOOLCHAINS
        xcc
        xtensa
        CORE_IDS
        hifi4)

    mcux_add_include(BASE_PATH ${SdkRootDirPath}/${device_root}/${soc_portfolio}/${soc_series}/${device} INCLUDES .)
endif()
