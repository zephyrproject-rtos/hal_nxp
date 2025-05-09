list(APPEND CMAKE_MODULE_PATH
    ${CMAKE_CURRENT_LIST_DIR}/.
    ${CMAKE_CURRENT_LIST_DIR}/../../CMSIS/Core/Include
    ${CMAKE_CURRENT_LIST_DIR}/../../components/lists
    ${CMAKE_CURRENT_LIST_DIR}/../../components/serial_manager
    ${CMAKE_CURRENT_LIST_DIR}/../../components/uart
    ${CMAKE_CURRENT_LIST_DIR}/../../drivers/common
    ${CMAKE_CURRENT_LIST_DIR}/../../drivers/adc16
    ${CMAKE_CURRENT_LIST_DIR}/../../drivers/clock
    ${CMAKE_CURRENT_LIST_DIR}/../../drivers/cmp
    ${CMAKE_CURRENT_LIST_DIR}/../../drivers/cmt
    ${CMAKE_CURRENT_LIST_DIR}/../../drivers/crc
    ${CMAKE_CURRENT_LIST_DIR}/../../drivers/dac
    ${CMAKE_CURRENT_LIST_DIR}/../../drivers/dmamux
    ${CMAKE_CURRENT_LIST_DIR}/../../drivers/dspi
    ${CMAKE_CURRENT_LIST_DIR}/../../drivers/edma
    ${CMAKE_CURRENT_LIST_DIR}/../../drivers/ewm
    ${CMAKE_CURRENT_LIST_DIR}/../../drivers/flash
    ${CMAKE_CURRENT_LIST_DIR}/../../drivers/flexbus
    ${CMAKE_CURRENT_LIST_DIR}/../../drivers/flexcan
    ${CMAKE_CURRENT_LIST_DIR}/../../drivers/ftm
    ${CMAKE_CURRENT_LIST_DIR}/../../drivers/gpio
    ${CMAKE_CURRENT_LIST_DIR}/../../drivers/i2c
    ${CMAKE_CURRENT_LIST_DIR}/../../drivers/llwu
    ${CMAKE_CURRENT_LIST_DIR}/../../drivers/lptmr
    ${CMAKE_CURRENT_LIST_DIR}/../../drivers/sysmpu
    ${CMAKE_CURRENT_LIST_DIR}/../../drivers/pdb
    ${CMAKE_CURRENT_LIST_DIR}/../../drivers/pit
    ${CMAKE_CURRENT_LIST_DIR}/../../drivers/pmc
    ${CMAKE_CURRENT_LIST_DIR}/../../drivers/port
    ${CMAKE_CURRENT_LIST_DIR}/../../drivers/rcm
    ${CMAKE_CURRENT_LIST_DIR}/../../drivers/rnga
    ${CMAKE_CURRENT_LIST_DIR}/../../drivers/rtc
    ${CMAKE_CURRENT_LIST_DIR}/../../drivers/sai
    ${CMAKE_CURRENT_LIST_DIR}/../../drivers/sdhc
    ${CMAKE_CURRENT_LIST_DIR}/../../drivers/sim
    ${CMAKE_CURRENT_LIST_DIR}/../../drivers/smc
    ${CMAKE_CURRENT_LIST_DIR}/../../drivers/uart
    ${CMAKE_CURRENT_LIST_DIR}/../../drivers/vref
    ${CMAKE_CURRENT_LIST_DIR}/../../drivers/wdog
    ${CMAKE_CURRENT_LIST_DIR}/../../utilities/assert
    ${CMAKE_CURRENT_LIST_DIR}/../../utilities/debug_console
    ${CMAKE_CURRENT_LIST_DIR}/../../utilities/debug_console_lite
    ${CMAKE_CURRENT_LIST_DIR}/../../utilities/misc_utilities
    ${CMAKE_CURRENT_LIST_DIR}/drivers
    ${CMAKE_CURRENT_LIST_DIR}/utilities
)


# Copy the cmake components into projects
#    include(driver_common)
#    include(driver_adc16)
#    include(driver_clock)
#    include(driver_cmp)
#    include(driver_cmt)
#    include(driver_crc)
#    include(driver_dac)
#    include(driver_dmamux)
#    include(driver_dspi)
#    include(driver_dspi_edma)
#    include(driver_edma)
#    include(driver_ewm)
#    include(driver_flash)
#    include(driver_flexbus)
#    include(driver_flexcan)
#    include(driver_ftm)
#    include(driver_gpio)
#    include(driver_i2c)
#    include(driver_i2c_edma)
#    include(driver_llwu)
#    include(driver_lptmr)
#    include(driver_sysmpu)
#    include(driver_pdb)
#    include(driver_pit)
#    include(driver_pmc)
#    include(driver_port)
#    include(driver_rcm)
#    include(driver_rnga)
#    include(driver_rtc)
#    include(driver_sai)
#    include(driver_sai_edma)
#    include(driver_sdhc)
#    include(driver_sim)
#    include(driver_smc)
#    include(driver_uart)
#    include(driver_uart_edma)
#    include(driver_vref)
#    include(driver_wdog)
#    include(component_lists)
#    include(device_system)
#    include(utility_notifier)
#    include(utility_debug_console_lite)
#    include(utility_assert)
#    include(CMSIS_Include_core_cm OPTIONAL)
#    include(utility_assert_lite)
#    include(utility_debug_console)
#    include(device_CMSIS)
#    include(utilities_misc_utilities)
#    include(component_serial_manager)
#    include(component_serial_manager_uart)
#    include(component_uart_adapter)
#    include(utility_shell)
