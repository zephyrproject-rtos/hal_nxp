# device spepcific drivers
if(CONFIG_MCUX_COMPONENT_device.CMSIS)
    mcux_add_source(BASE_PATH ${SdkRootDirPath}/${device_root}/${soc_portfolio}/${soc_series}/${device} SOURCES fsl_device_registers.h)

    mcux_add_source(BASE_PATH ${SdkRootDirPath}/${device_root}/${soc_portfolio}/${soc_series}/${device} SOURCES ${CONFIG_MCUX_HW_DEVICE_CORE}.h CORE_IDS ${core_id})
    mcux_add_source(BASE_PATH ${SdkRootDirPath}/${device_root}/${soc_portfolio}/${soc_series}/${device} SOURCES ${CONFIG_MCUX_HW_DEVICE_CORE}_COMMON.h CORE_IDS ${core_id})
    mcux_add_source(BASE_PATH ${SdkRootDirPath}/${device_root}/${soc_portfolio}/${soc_series}/${device} SOURCES ${CONFIG_MCUX_HW_DEVICE_CORE}_features.h CORE_IDS
                    ${core_id})

    mcux_add_source(BASE_PATH ${SdkRootDirPath}/${device_root}/${soc_portfolio}/${soc_series} SOURCES ${soc_periph}/*.h)

    mcux_add_include(BASE_PATH ${SdkRootDirPath}/${device_root}/${soc_portfolio}/${soc_series}/${device} INCLUDES .)
    mcux_add_include(BASE_PATH ${SdkRootDirPath}/${device_root}/${soc_portfolio}/${soc_series}/${soc_periph} INCLUDES .)

endif()

if(CONFIG_MCUX_COMPONENT_device.system)

    mcux_add_source(BASE_PATH ${SdkRootDirPath}/${device_root}/${soc_portfolio}/${soc_series}/${device} SOURCES system_${CONFIG_MCUX_HW_DEVICE_CORE}.c CORE_IDS
                    ${core_id})
    mcux_add_source(BASE_PATH ${SdkRootDirPath}/${device_root}/${soc_portfolio}/${soc_series}/${device} SOURCES system_${CONFIG_MCUX_HW_DEVICE_CORE}.h CORE_IDS
                    ${core_id})

    mcux_add_include(BASE_PATH ${SdkRootDirPath}/${device_root}/${soc_portfolio}/${soc_series}/${device} INCLUDES .)

endif()

if(CONFIG_MCUX_COMPONENT_device.startup)

    mcux_add_source(
        BASE_PATH
        ${SdkRootDirPath}/${device_root}/${soc_portfolio}/${soc_series}/${device}
        SOURCES
        iar/startup_${CONFIG_MCUX_HW_DEVICE_CORE}.s
        TOOLCHAINS
        iar
        CORE_IDS
        ${core_id}
        CONFIG
        true)

    mcux_add_source(
        BASE_PATH
        ${SdkRootDirPath}/${device_root}/${soc_portfolio}/${soc_series}/${device}
        SOURCES
        gcc/startup_${CONFIG_MCUX_HW_DEVICE_CORE}.S
        TOOLCHAINS
        armgcc
        CORE_IDS
        ${core_id}
        CONFIG
        true)

    mcux_add_source(
        BASE_PATH
        ${SdkRootDirPath}/${device_root}/${soc_portfolio}/${soc_series}/${device}
        SOURCES
        arm/startup_${CONFIG_MCUX_HW_DEVICE_CORE}.S
        TOOLCHAINS
        mdk
        CORE_IDS
        ${core_id}
        CONFIG
        true)

endif()
