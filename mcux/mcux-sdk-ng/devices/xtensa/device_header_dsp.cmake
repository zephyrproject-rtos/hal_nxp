if(CONFIG_MCUX_COMPONENT_device.CMSIS)
    mcux_add_source(BASE_PATH ${SdkRootDirPath}/${device_root}/${soc_portfolio}/${soc_series}/${device} SOURCES fsl_device_registers.h)
    mcux_add_source(BASE_PATH ${SdkRootDirPath}/${device_root}/${soc_portfolio}/${soc_series}/${device} SOURCES ${CONFIG_MCUX_HW_DEVICE_CORE}.h CORES dsp)
    mcux_add_source(BASE_PATH ${SdkRootDirPath}/${device_root}/${soc_portfolio}/${soc_series}/${device} SOURCES ${CONFIG_MCUX_HW_DEVICE_CORE}_COMMON.h CORES dsp)
    mcux_add_source(BASE_PATH ${SdkRootDirPath}/${device_root}/${soc_portfolio}/${soc_series}/${device} SOURCES ${CONFIG_MCUX_HW_DEVICE_CORE}_features.h CORES dsp)
    mcux_add_source(BASE_PATH ${SdkRootDirPath}/${device_root}/${soc_portfolio}/${soc_series} SOURCES ${soc_periph}/*.h)

    mcux_add_include(BASE_PATH ${SdkRootDirPath}/${device_root}/${soc_portfolio}/${soc_series}/${soc_periph} INCLUDES .)
    mcux_add_include(BASE_PATH ${SdkRootDirPath}/${device_root}/${soc_portfolio}/${soc_series}/${device} INCLUDES .)
endif()

if(CONFIG_MCUX_COMPONENT_device.system)
    mcux_add_source(
        BASE_PATH
        ${SdkRootDirPath}/${device_root}/${soc_portfolio}/${soc_series}/${device}
        SOURCES
        system_${CONFIG_MCUX_HW_DEVICE_CORE}.c
        system_${CONFIG_MCUX_HW_DEVICE_CORE}.h
        TOOLCHAINS
        xcc
        xtensa
        CORES
        dsp)

    mcux_add_include(BASE_PATH ${SdkRootDirPath}/${device_root}/${soc_portfolio}/${soc_series}/${device} INCLUDES .)
endif()
