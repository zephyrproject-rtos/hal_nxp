# device spcific drivers for single core device
if(CONFIG_MCUX_COMPONENT_device.CMSIS)

    mcux_add_source(BASE_PATH ${SdkRootDirPath}/devices/${soc_portfolio}/${soc_series}/${device} 
        SOURCES fsl_device_registers.h "${CONFIG_MCUX_HW_DEVICE_CORE}.h" "${CONFIG_MCUX_HW_DEVICE_CORE}_features.h" "${CONFIG_MCUX_HW_DEVICE_CORE}_COMMON.h" "../${soc_periph}/*.h")

    mcux_add_include(BASE_PATH ${SdkRootDirPath}/devices/${soc_portfolio}/${soc_series}/${device} INCLUDES .)
    mcux_add_include(BASE_PATH ${SdkRootDirPath}/devices/${soc_portfolio}/${soc_series}/${soc_periph} INCLUDES .)

endif()

if(CONFIG_MCUX_COMPONENT_device.system)
    mcux_add_include(BASE_PATH ${SdkRootDirPath}/devices/${soc_portfolio}/${soc_series}/${device} INCLUDES .)

endif()

if(CONFIG_MCUX_COMPONENT_device.startup)
    mcux_add_source(
        BASE_PATH
        ${SdkRootDirPath}/devices/${soc_portfolio}/${soc_series}/${device}/codewarrior
        SOURCES
        Cpu.h
        Flash_config.c
        Flash_config.h
        ${soc_series}_init.asm
        ${device}_Vectors.c
        TOOLCHAINS
        codewarrior
        CONFIG
        true)

    mcux_add_include(BASE_PATH ${SdkRootDirPath}/devices/${soc_portfolio}/${soc_series}/${device}/codewarrior INCLUDES .)
endif()
