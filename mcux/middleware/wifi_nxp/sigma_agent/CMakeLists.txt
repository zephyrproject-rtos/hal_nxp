cmake_minimum_required(VERSION 3.10.2)
project(sigma_agent
    VERSION 0.2.0
    LANGUAGES C CXX ASM
)

set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_STANDARD 99)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/../tools/cmake)

set(NXP_DRIVER_LIB nxp-${SG_NXP_PLATFORM}-driver)

# Determine whether the SDK used is the github repo, a package or the internal repo
if(EXISTS ${NXP_SDK_ROOT}/core/.github)
    set(SDK_TYPE "GITHUB")
elseif(EXISTS ${NXP_SDK_ROOT}/SW-Content-Register.txt)
    set(SDK_TYPE "PACKAGE")
else()
    set(SDK_TYPE "INTERNAL")
endif()
message(STATUS "SDK_TYPE: ${SDK_TYPE}")

set(MIDDLEWARE_PATH ${NXP_SDK_ROOT}/middleware)

set(EVK_MIMXRT1170 "evkbmimxrt1170" CACHE STRING "evkbmimxrt1170")
set(MIMXRT1170_EVK "mimxrt1170evkb" CACHE STRING "mimxrt1170evkb")

if(${SDK_TYPE} STREQUAL "GITHUB")
    message("SDK_GITHUB driver path chosen")
    set(MIDDLEWARE_PATH ${NXP_SDK_ROOT}/middleware)
    set(NXP_SDK_ROOT ${NXP_SDK_ROOT}/core)
    set(DRIVER_FILES_PATH ${NXP_SDK_ROOT}/drivers)
    set(DRIVER_LPUART_FILES_PATH ${DRIVER_FILES_PATH}/lpuart)
    set(DRIVER_LPSPI_FILES_PATH ${DRIVER_FILES_PATH}/lpspi)
    set(DRIVER_GPT_FILES_PATH ${DRIVER_FILES_PATH}/gpt)
    set(DRIVER_LPI2C_FILES_PATH ${DRIVER_FILES_PATH}/lpi2c)
    set(DRIVER_EDMA_FILES_PATH ${DRIVER_FILES_PATH}/edma)
    set(DRIVER_DMAMUX_FILES_PATH ${DRIVER_FILES_PATH}/dmamux)
    set(DRIVER_PIT_FILES_PATH ${DRIVER_FILES_PATH}/pit)
    set(DRIVER_TRNG_FILES_PATH ${DRIVER_FILES_PATH}/trng)
    set(DRIVER_FLEXSPI_FILES_PATH ${DRIVER_FILES_PATH}/flexspi)
    set(DRIVER_IGPIO_FILES_PATH ${DRIVER_FILES_PATH}/igpio)
    set(DRIVER_DCP_FILES_PATH ${DRIVER_FILES_PATH}/dcp)
    set(DRIVER_FSL_CACHE_FILES_PATH ${DRIVER_FILES_PATH}/cache/armv7-m7)
    set(DRIVER_COMMON_FILES_PATH ${DRIVER_FILES_PATH}/common)
    set(DRIVER_ENET_FILES_PATH ${DRIVER_FILES_PATH}/enet)
    set(DRIVER_USDHC_FILES_PATH ${DRIVER_FILES_PATH}/usdhc)
    set(DRIVER_SDHC_FILES_PATH ${DRIVER_FILES_PATH}/sdhc)
    set(DRIVER_CAAM_FILES_PATH ${DRIVER_FILES_PATH}/caam)
    set(DRIVER_MU_FILES_PATH ${DRIVER_FILES_PATH}/mu)
    set(DRIVER_DEVICE_FILES_PATH ${NXP_SDK_ROOT}/devices/MIMXRT1176/drivers)
    set(DRIVER_CACHE_FILES_PATH ${NXP_SDK_ROOT}/devices/MIMXRT1176/drivers/cm7)
    set(UTILITIES_FILES_PATH ${NXP_SDK_ROOT}/utilities)
    set(UTILITIES_DEVICE_FILES_PATH ${NXP_SDK_ROOT}/devices/MIMXRT1176/utilities)
    set(ASSERT_FILES_PATH ${UTILITIES_FILES_PATH}/assert)
    set(DEBUG_CONSOLE_FILES_PATH ${UTILITIES_FILES_PATH}/debug_console_lite)
    set(STR_FILES_PATH ${UTILITIES_FILES_PATH}/debug_console/str)
    set(FSL_FLEXSPI_NOR_BOOT_FILES_PATH ${NXP_SDK_ROOT}/devices/MIMXRT1176/xip)
    set(INCBIN_FILES_PATH ${NXP_SDK_ROOT}/utilities/misc_utilities)
    set(WIFI_BT_CONFIG_SOURCE_FILE ${NXP_SDK_ROOT}/boards/${EVK_MIMXRT1170}/wireless_config_template/wifi_bt_config.c)
elseif(${SDK_TYPE} STREQUAL "PACKAGE")
    set(DRIVER_FILES_PATH ${NXP_SDK_ROOT}/devices/MIMXRT1176/drivers)
    set(DRIVER_LPUART_FILES_PATH ${DRIVER_FILES_PATH})
    set(DRIVER_LPSPI_FILES_PATH ${DRIVER_FILES_PATH})
    set(DRIVER_LPI2C_FILES_PATH ${DRIVER_FILES_PATH})
    set(DRIVER_PIT_FILES_PATH ${DRIVER_FILES_PATH})
    set(DRIVER_GPT_FILES_PATH ${DRIVER_FILES_PATH})
    set(DRIVER_FLEXSPI_FILES_PATH ${DRIVER_FILES_PATH})
    set(DRIVER_IGPIO_FILES_PATH ${DRIVER_FILES_PATH})
    set(DRIVER_COMMON_FILES_PATH ${DRIVER_FILES_PATH})
    set(DRIVER_DEVICE_FILES_PATH ${DRIVER_FILES_PATH})
    set(DRIVER_EDMA_FILES_PATH ${DRIVER_FILES_PATH})
    set(DRIVER_DMAMUX_FILES_PATH ${DRIVER_FILES_PATH})
    set(DRIVER_ENET_FILES_PATH ${DRIVER_FILES_PATH})
    set(DRIVER_USDHC_FILES_PATH ${DRIVER_FILES_PATH})
    set(DRIVER_SDHC_FILES_PATH ${DRIVER_FILES_PATH})
    set(DRIVER_CACHE_FILES_PATH ${DRIVER_FILES_PATH}/cm7)
    set(DRIVER_CAAM_FILES_PATH ${DRIVER_FILES_PATH})
    set(DRIVER_MU_FILES_PATH ${DRIVER_FILES_PATH})
    set(DEBUG_CONSOLE_FILES_PATH ${NXP_SDK_ROOT}/devices/MIMXRT1176/utilities/debug_console)
    set(ASSERT_FILES_PATH ${NXP_SDK_ROOT}/devices/MIMXRT1176/utilities)
    set(STR_FILES_PATH ${NXP_SDK_ROOT}/devices/MIMXRT1176/utilities/str)
    set(FSL_FLEXSPI_NOR_BOOT_FILES_PATH ${NXP_SDK_ROOT}/devices/MIMXRT1176/xip)
    set(INCBIN_FILES_PATH ${NXP_SDK_ROOT}/devices/MIMXRT1176/utilities/incbin)
    set(WIFI_BT_CONFIG_SOURCE_FILE ${NXP_SDK_ROOT}/components/wifi_bt_module/template/wifi_bt_config.c)
    set(WIFI_BT_CONFIG_SOURCE_FILE ${NXP_SDK_ROOT}/boards/${EVK_MIMXRT1170}/wireless_config_template/wifi_bt_config.c)
elseif(${SDK_TYPE} STREQUAL "INTERNAL")
    set(DRIVER_LPUART_FILES_PATH ${NXP_SDK_ROOT}/platform/drivers/lpuart)
    set(DRIVER_LPSPI_FILES_PATH ${NXP_SDK_ROOT}/platform/drivers/lpspi)
    set(DRIVER_LPI2C_FILES_PATH ${NXP_SDK_ROOT}/platform/drivers/lpi2c)
    set(DRIVER_PIT_FILES_PATH ${NXP_SDK_ROOT}/platform/drivers/pit)
    set(DRIVER_GPT_FILES_PATH ${NXP_SDK_ROOT}/platform/drivers/gpt)
    set(DRIVER_FLEXSPI_FILES_PATH ${NXP_SDK_ROOT}/platform/drivers/flexspi)
    set(DRIVER_IGPIO_FILES_PATH ${NXP_SDK_ROOT}/platform/drivers/igpio)
    set(DRIVER_COMMON_FILES_PATH ${NXP_SDK_ROOT}/platform/drivers/common)
    set(DRIVER_DEVICE_FILES_PATH ${NXP_SDK_ROOT}/devices/MIMXRT1176/drivers)
    set(DRIVER_EDMA_FILES_PATH ${NXP_SDK_ROOT}/platform/drivers/edma)
    set(DRIVER_DMAMUX_FILES_PATH ${NXP_SDK_ROOT}/platform/drivers/dmamux)
    set(DRIVER_ENET_FILES_PATH ${NXP_SDK_ROOT}/platform/drivers/enet)
    set(DRIVER_USDHC_FILES_PATH ${NXP_SDK_ROOT}/platform/drivers/usdhc)
    set(DRIVER_SDHC_FILES_PATH ${NXP_SDK_ROOT}/platform/drivers/sdhc)
    set(DRIVER_CACHE_FILES_PATH ${NXP_SDK_ROOT}/platform/drivers/cache/armv7-m7)
    set(DRIVER_CAAM_FILES_PATH ${NXP_SDK_ROOT}/platform/drivers/caam)
    set(DRIVER_MU_FILES_PATH ${NXP_SDK_ROOT}/platform/drivers/mu)
    set(DEBUG_CONSOLE_FILES_PATH ${NXP_SDK_ROOT}/platform/utilities/debug_console)
    set(ASSERT_FILES_PATH ${NXP_SDK_ROOT}/platform/utilities/assert)
    set(STR_FILES_PATH ${NXP_SDK_ROOT}/platform/utilities/str)
    set(FSL_FLEXSPI_NOR_BOOT_FILES_PATH ${NXP_SDK_ROOT}/devices/MIMXRT1176/xip)
    set(INCBIN_FILES_PATH ${NXP_SDK_ROOT}/platform/utilities/misc_utilities)
    set(WIFI_BT_CONFIG_SOURCE_FILE ${NXP_SDK_ROOT}/components/wifi_bt_module/template/wifi_bt_config.c)
else()
    message(FATAL_ERROR "Unknown SDK_TYPE")
endif()

list(APPEND SDK_INCLUDES

    # CMSIS includes
    ${NXP_SDK_ROOT}/CMSIS/Core/Include

    # other SDK files
    ${NXP_SDK_ROOT}/devices/MIMXRT1176
    ${DRIVER_DEVICE_FILES_PATH}
    ${DRIVER_DEVICE_FILES_PATH}/cm7
    ${DRIVER_COMMON_FILES_PATH}
    ${DRIVER_LPUART_FILES_PATH}
    ${DRIVER_LPSPI_FILES_PATH}
    ${DRIVER_LPI2C_FILES_PATH}
    ${DRIVER_IGPIO_FILES_PATH}
    ${DRIVER_PIT_FILES_PATH}
    ${DRIVER_GPT_FILES_PATH}
    ${DRIVER_FLEXSPI_FILES_PATH}
    ${DRIVER_EDMA_FILES_PATH}
    ${DRIVER_CACHE_FILES_PATH}
    ${DRIVER_CAAM_FILES_PATH}
    ${DRIVER_MU_FILES_PATH}
    ${DRIVER_DMAMUX_FILES_PATH}
    ${DEBUG_CONSOLE_FILES_PATH}
    ${UTILITIES_FILES_PATH}/debug_console/debug_console
    ${STR_FILES_PATH}

    # XIP
    ${NXP_SDK_ROOT}/devices/MIMXRT1176/xip
    ${NXP_SDK_ROOT}/boards/${EVK_MIMXRT1170}/xip

    # SDK components
    ${NXP_SDK_ROOT}/components/uart
    ${NXP_SDK_ROOT}/components/serial_manager
    ${NXP_SDK_ROOT}/components/lists
    ${NXP_SDK_ROOT}/components/osa
    ${NXP_SDK_ROOT}/components/common_task
    ${NXP_SDK_ROOT}/components/log
    ${NXP_SDK_ROOT}/components/timer_manager
    ${NXP_SDK_ROOT}/components/timer
    ${NXP_SDK_ROOT}/components/internal_flash
    ${NXP_SDK_ROOT}/components/spi
    ${NXP_SDK_ROOT}/components/gpio
    ${NXP_SDK_ROOT}/components/time_stamp

    # File system
    ${MIDDLEWARE_PATH}/littlefs
    ${NXP_SDK_ROOT}/components/flash/mflash
    ${NXP_SDK_ROOT}/components/flash/mflash/${MIMXRT1170_EVK}
)

list(APPEND SDK_COMPILE_DEFINITIONS
    -D__STARTUP_CLEAR_BSS
    -D__STARTUP_INITIALIZE_NONCACHEDATA

    # -DSERIAL_MANAGER_NON_BLOCKING_MODE=1
    # -DSERIAL_MANAGER_TASK_HANDLE_RX_AVAILABLE_NOTIFY=1
    -DSDK_OS_FREE_RTOS
    -DUSE_RTOS
    -DOSA_USED
    -DFSL_OSA_MAIN_FUNC_ENABLE=0
    -DFSL_RTOS_FREE_RTOS
    -DXIP_EXTERNAL_FLASH=1
    -DXIP_BOOT_HEADER_ENABLE=1
    -DCPU_MIMXRT1176DVMAA
    -DCPU_MIMXRT1176DVMAA_cm7
    -DFSL_SDK_ENABLE_DRIVER_CACHE_CONTROL=1
    -DSDK_COMPONENT_INTEGRATION=1
    -DFSL_DRIVER_TRANSFER_DOUBLE_WEAK_IRQ=0
    -DDEBUG_CONSOLE_TRANSFER_NON_BLOCKING
    -DHAL_UART_ADAPTER_FIFO=1
    -DSDK_DEBUGCONSOLE_UART=1
    -DDEBUG_CONSOLE_RX_ENABLE=0
    -DSERIAL_PORT_TYPE_UART=1
    -DCONFIG_ARM=1
    -DSERIAL_MANAGER_TASK_STACK_SIZE=4048

    # Flash size should be increased for RT1170
    -DFLASH_ADAPTER_SIZE=0x4000

    # Security flags
    -DCRYPTO_USE_DRIVER_CAAM
    -DCACHE_MODE_WRITE_THROUGH=1
)

list(APPEND SDK_INCLUDES
    ${DRIVER_USDHC_FILES_PATH}
    ${DRIVER_SDHC_FILES_PATH}
    ${MIDDLEWARE_PATH}/wifi_nxp/wifidriver
    ${MIDDLEWARE_PATH}/wifi_nxp/wifi_bt_firmware/nw61x
    ${MIDDLEWARE_PATH}/sdmmc/common
    ${MIDDLEWARE_PATH}/sdmmc/sdio
    ${MIDDLEWARE_PATH}/sdmmc/host/usdhc
    ${MIDDLEWARE_PATH}/sdmmc/osa
    ${MIDDLEWARE_PATH}/wifi_nxp/incl/wifidriver
    ${MIDDLEWARE_PATH}/wifi_nxp/incl
    ${MIDDLEWARE_PATH}/wifi_nxp/incl/wlcmgr
    ${MIDDLEWARE_PATH}/wifi_nxp/incl/port/os
    ${MIDDLEWARE_PATH}/wifi_nxp/incl/port/lwip
    ${MIDDLEWARE_PATH}/wifi_nxp/wifidriver
    ${MIDDLEWARE_PATH}/wifi_nxp/sdio_nxp_abs/incl
    ${MIDDLEWARE_PATH}/wifi_nxp/wifidriver/incl
    ${MIDDLEWARE_PATH}/wifi_nxp/fwdnld_intf_abs
    ${MIDDLEWARE_PATH}/wifi_nxp/sdio_nxp_abs/incl
    ${MIDDLEWARE_PATH}/wifi_nxp/firmware_dnld
    ${MIDDLEWARE_PATH}/wifi_nxp/posix
    ${MIDDLEWARE_PATH}/wifi_nxp/posix/include
    ${MIDDLEWARE_PATH}/wifi_nxp/posix/include/FreeRTOS_POSIX
    ${MIDDLEWARE_PATH}/wifi_nxp/posix/include/private
    ${MIDDLEWARE_PATH}/wifi_nxp/posix/FreeRTOS-Plus-POSIX
    ${MIDDLEWARE_PATH}/wifi_nxp/posix/FreeRTOS-Plus-POSIX/include
    ${MIDDLEWARE_PATH}/wifi_nxp/posix/FreeRTOS-Plus-POSIX/include/portable
    ${MIDDLEWARE_PATH}/wifi_nxp/posix/FreeRTOS-Plus-POSIX/include/portable/nxp
    ${MIDDLEWARE_PATH}/wifi_nxp/posix/FreeRTOS-Plus-POSIX/include/portable/nxp/rt
    ${NXP_SDK_ROOT}/components/wifi_bt_module/template
    ${NXP_SDK_ROOT}/components/wifi_bt_module/incl
)

set(LWIP_PATH ${NXP_SDK_ROOT}/middleware/lwip)

list(APPEND SDK_INCLUDES
    ${LWIP_PATH}
    ${LWIP_PATH}/port
    ${LWIP_PATH}/port/arch
    ${LWIP_PATH}/src/include
    ${LWIP_PATH}/src/include/lwip/apps
)

add_library(sigma_agent STATIC
    "sigma_agent.c"
    "dut/wfa_dut_init.c"
    "dut/wfa_dut.c"
    "lib/nxp_gvars.c"
    "lib/nxp_miscs.c"
    "lib/wfa_cmdtbl.c"
    "lib/wfa_cs.c"
    "lib/wfa_miscs.c"
    "lib/wfa_sock.c"
    "lib/wfa_tg.c"
    "lib/wfa_thr.c"
    "lib/wfa_tlv.c"
    "lib/wfa_typestr.c"
    "lib/wfa_wmmps.c"
)

target_compile_definitions(sigma_agent
    PUBLIC
    ${SDK_COMPILE_DEFINITIONS}
)

list(APPEND SDK_TARGET_COMPILE_OPTIONS -include ../example/wifi_wpa_supplicant/wifi_config.h)

target_compile_options(sigma_agent
    PUBLIC
    ${SDK_TARGET_COMPILE_OPTIONS}
    PRIVATE
    -Wno-unknown-pragmas
    -Wno-sign-compare
    -Wno-unused-parameter
    -Wno-empty-body
    -Wno-unused-function
)

target_include_directories(sigma_agent
    PRIVATE ../example/wifi_wpa_supplicant/ dut inc ../incl ../incl/port/os ../incl/wlcmgr ../incl/wifidriver ${NXP_SDK_ROOT}/rtos/freertos/freertos-kernel/include
    ${NXP_SDK_ROOT}/rtos/freertos/freertos-kernel/portable/GCC/ARM_CM4F
    ${NXP_SDK_ROOT}/platform/utilities/debug_console  ${NXP_SDK_ROOT}/boards/${EVK_MIMXRT1170} ${NXP_SDK_ROOT}/platform/drivers/common ${SDK_INCLUDES}
)

project(sigma_agent)
