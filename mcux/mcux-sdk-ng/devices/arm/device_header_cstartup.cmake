# device spcific drivers for single core device
if(CONFIG_MCUX_COMPONENT_device.CMSIS)

    mcux_add_source(BASE_PATH ${SdkRootDirPath}/${device_root}/${soc_portfolio}/${soc_series}/${device} SOURCES fsl_device_registers.h
                    "${CONFIG_MCUX_HW_DEVICE_CORE}.h" "${CONFIG_MCUX_HW_DEVICE_CORE}_features.h" "${CONFIG_MCUX_HW_DEVICE_CORE}_COMMON.h" "../${soc_periph}/*.h")

    mcux_add_include(BASE_PATH ${SdkRootDirPath}/${device_root}/${soc_portfolio}/${soc_series}/${device} INCLUDES .)
    mcux_add_include(BASE_PATH ${SdkRootDirPath}/${device_root}/${soc_portfolio}/${soc_series}/${soc_periph} INCLUDES .)

endif()

if(CONFIG_MCUX_COMPONENT_device.system)
    mcux_add_source(BASE_PATH ${SdkRootDirPath}/${device_root}/${soc_portfolio}/${soc_series}/${device} SOURCES system_${CONFIG_MCUX_HW_DEVICE_CORE}.c
                    system_${CONFIG_MCUX_HW_DEVICE_CORE}.h)

    mcux_add_include(BASE_PATH ${SdkRootDirPath}/${device_root}/${soc_portfolio}/${soc_series}/${device} INCLUDES .)

endif()

if(CONFIG_MCUX_COMPONENT_device.startup)

    mcux_add_source(
        BASE_PATH
        ${SdkRootDirPath}/${device_root}/${soc_portfolio}/${soc_series}/${device}
        SOURCES
        startup_${CONFIG_MCUX_HW_DEVICE_CORE}.c
        TOOLCHAINS
        iar
        armgcc
        mdk
        CONFIG
        true)

endif()

