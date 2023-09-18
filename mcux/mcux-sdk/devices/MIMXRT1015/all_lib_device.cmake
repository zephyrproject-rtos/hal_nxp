# Copy variable into project config.cmake to use software component
#set.board.evkmimxrt1015
#  # description: Board_project_template evkmimxrt1015
#  set(CONFIG_USE_BOARD_Project_Template_evkmimxrt1015 true)

#  # description: XIP Board Driver
#  set(CONFIG_USE_driver_xip_board_evkmimxrt1015 true)

#set.device.MIMXRT1015
#  # description: Middleware baremetal
#  set(CONFIG_USE_middleware_baremetal true)

#  # description: Utilities which is needed for particular toolchain like the SBRK function required to address limitation between HEAP and STACK in GCC toolchain library.
#  set(CONFIG_USE_utilities_misc_utilities true)

#  # description: Driver nand_flash-common
#  set(CONFIG_USE_driver_nand_flash-common true)

#  # description: Driver nor_flash-common
#  set(CONFIG_USE_driver_nor_flash-common true)

#  # description: Driver mx25r_flash
#  set(CONFIG_USE_driver_mx25r_flash true)

#  # description: Driver pf1550
#  set(CONFIG_USE_driver_pf1550 true)

#  # description: Driver pf3000
#  set(CONFIG_USE_driver_pf3000 true)

#  # description: RTT template configuration
#  set(CONFIG_USE_driver_rtt_template true)

#  # description: Devices_project_template MIMXRT1015
#  set(CONFIG_USE_DEVICES_Project_Template_MIMXRT1015 true)

#  # description: Device MIMXRT1015_startup
#  set(CONFIG_USE_device_MIMXRT1015_startup true)

#  # description: Device MIMXRT1015_cmsis
#  set(CONFIG_USE_device_MIMXRT1015_CMSIS true)

#  # description: Rte_device
#  set(CONFIG_USE_RTE_Device true)

#  # description: SAI EDMA Driver
#  set(CONFIG_USE_driver_sai_edma true)

#  # description: LPI2C Driver
#  set(CONFIG_USE_driver_lpi2c_edma true)

#  # description: LPSPI Driver
#  set(CONFIG_USE_driver_lpspi_edma true)

#  # description: LPUART Driver
#  set(CONFIG_USE_driver_lpuart_edma true)

#  # description: DCP Driver
#  set(CONFIG_USE_driver_dcp true)

#  # description: Clock Driver
#  set(CONFIG_USE_driver_clock true)

#  # description: Component serial_manager_uart
#  set(CONFIG_USE_component_serial_manager_uart true)

#  # description: Utility debug_console_lite
#  set(CONFIG_USE_utility_debug_console_lite true)

#  # description: IOMUXC Driver
#  set(CONFIG_USE_driver_iomuxc true)

#  # description: LPSPI CMSIS Driver
#  set(CONFIG_USE_driver_cmsis_lpspi true)

#  # description: LPI2C CMSIS Driver
#  set(CONFIG_USE_driver_cmsis_lpi2c true)

#  # description: LPUART CMSIS Driver
#  set(CONFIG_USE_driver_cmsis_lpuart true)

#  # description: FLEXIO CAMERA EDMA Driver
#  set(CONFIG_USE_driver_flexio_camera_edma true)

#  # description: FLEXIO I2S EDMA Driver
#  set(CONFIG_USE_driver_flexio_i2s_edma true)

#  # description: FLEXIO MCULCD EDMA Driver
#  set(CONFIG_USE_driver_flexio_mculcd_edma true)

#  # description: FLEXIO SPI EDMA Driver
#  set(CONFIG_USE_driver_flexio_spi_edma true)

#  # description: FLEXIO UART EDMA Driver
#  set(CONFIG_USE_driver_flexio_uart_edma true)

#  # description: FLEXSPI Driver
#  set(CONFIG_USE_driver_flexspi_edma true)

#  # description: SPDIF EDMA Driver
#  set(CONFIG_USE_driver_spdif_edma true)

#  # description: Utility notifier
#  set(CONFIG_USE_utility_notifier true)

#  # description: Device MIMXRT1015_system
#  set(CONFIG_USE_device_MIMXRT1015_system true)

#  # description: Utility assert
#  set(CONFIG_USE_utility_assert true)

#  # description: Utility assert_lite
#  set(CONFIG_USE_utility_assert_lite true)

#  # description: Utility str
#  set(CONFIG_USE_utility_str true)

#  # description: Utility debug_console
#  set(CONFIG_USE_utility_debug_console true)

#  # description: Component sai_edma_adapter
#  set(CONFIG_USE_component_audio_sai_edma_adapter true)

#  # description: Component button
#  set(CONFIG_USE_component_button true)

#  # description: Driver codec
#  set(CONFIG_USE_driver_codec true)

#  # description: Component codec adapters for multi codec
#  set(CONFIG_USE_component_codec_adapters true)

#  # description: Component wm8904 adapter for single codec
#  set(CONFIG_USE_component_wm8904_adapter true)

#  # description: Component wm8960 adapter for single codecs
#  set(CONFIG_USE_component_wm8960_adapter true)

#  # description: Component cs42888 adapter for single codec
#  set(CONFIG_USE_component_cs42888_adapter true)

#  # description: Component sgtl5000 adapter for single codec
#  set(CONFIG_USE_component_sgtl_adapter true)

#  # description: Component da7212 adapter for single codec
#  set(CONFIG_USE_component_da7212_adapter true)

#  # description: Component codec_i2c
#  set(CONFIG_USE_component_codec_i2c true)

#  # description: Component software_crc_adapter
#  set(CONFIG_USE_component_software_crc_adapter true)

#  # description: Driver cs42888
#  set(CONFIG_USE_driver_cs42888 true)

#  # description: Driver dialog7212
#  set(CONFIG_USE_driver_dialog7212 true)

#  # description: Component exception_handling_cm7
#  set(CONFIG_USE_component_exception_handling_cm7 true)

#  # description: Driver nand_flash-controller-flexspi
#  set(CONFIG_USE_driver_nand_flash-controller-flexspi true)

#  # description: Driver nor_flash-controller-flexspi
#  set(CONFIG_USE_driver_nor_flash-controller-flexspi true)

#  # description: Driver nor_flash-controller-lpspi
#  set(CONFIG_USE_driver_nor_flash-controller-lpspi true)

#  # description: Driver ft5406
#  set(CONFIG_USE_driver_ft5406 true)

#  # description: Driver ft5406_rt
#  set(CONFIG_USE_driver_ft5406_rt true)

#  # description: Driver ft6x06
#  set(CONFIG_USE_driver_ft6x06 true)

#  # description: Driver fxos8700cq
#  set(CONFIG_USE_driver_fxos8700cq true)

#  # description: Component igpio_adapter
#  set(CONFIG_USE_component_igpio_adapter true)

#  # description: Component lpi2c_adapter
#  set(CONFIG_USE_component_lpi2c_adapter true)

#  # description: Driver ili9341
#  set(CONFIG_USE_driver_ili9341 true)

#  # description: Component led
#  set(CONFIG_USE_component_led true)

#  # description: Component lists
#  set(CONFIG_USE_component_lists true)

#  # description: Component log
#  set(CONFIG_USE_component_log true)

#  # description: Component log backend debug console
#  set(CONFIG_USE_component_log_backend_debugconsole true)

#  # description: Component log backend debug console lite
#  set(CONFIG_USE_component_log_backend_debugconsole_lite true)

#  # description: Component log backend ring buffer
#  set(CONFIG_USE_component_log_backend_ringbuffer true)

#  # description: Component mem_manager
#  set(CONFIG_USE_component_mem_manager true)

#  # description: Component mem_manager_light
#  set(CONFIG_USE_component_mem_manager_light true)

#  # description: Driver mma8451q
#  set(CONFIG_USE_driver_mma8451q true)

#  # description: Component panic
#  set(CONFIG_USE_component_panic true)

#  # description: Component reset_adapter
#  set(CONFIG_USE_component_reset_adapter true)

#  # description: Component trng_adapter
#  set(CONFIG_USE_component_trng_adapter true)

#  # description: Component software_rng_adapter
#  set(CONFIG_USE_component_software_rng_adapter true)

#  # description: Component serial_manager
#  set(CONFIG_USE_component_serial_manager true)

#  # description: Component serial_manager_spi
#  set(CONFIG_USE_component_serial_manager_spi true)

#  # description: Component serial_manager_usb_cdc
#  set(CONFIG_USE_component_serial_manager_usb_cdc true)

#  # description: Component serial_manager_virtual
#  set(CONFIG_USE_component_serial_manager_virtual true)

#  # description: Component serial_manager_swo
#  set(CONFIG_USE_component_serial_manager_swo true)

#  # description: Driver sgtl5000
#  set(CONFIG_USE_driver_sgtl5000 true)

#  # description: Utility shell
#  set(CONFIG_USE_utility_shell true)

#  # description: Component lpspi_adapter
#  set(CONFIG_USE_component_lpspi_adapter true)

#  # description: Component gpt_adapter
#  set(CONFIG_USE_component_gpt_adapter true)

#  # description: Component pit_adapter
#  set(CONFIG_USE_component_pit_adapter true)

#  # description: Component timer_manager
#  set(CONFIG_USE_component_timer_manager true)

#  # description: Component lpuart_adapter
#  set(CONFIG_USE_component_lpuart_adapter true)

#  # description: Component lpuart_dma_adapter
#  set(CONFIG_USE_component_lpuart_dma_adapter true)

#  # description: Driver video-common
#  set(CONFIG_USE_driver_video-common true)

#  # description: Driver wm8904
#  set(CONFIG_USE_driver_wm8904 true)

#  # description: Driver wm8960
#  set(CONFIG_USE_driver_wm8960 true)

#  # description: COMMON Driver
#  set(CONFIG_USE_driver_common true)

#  # description: ADC Driver
#  set(CONFIG_USE_driver_adc_12b1msps_sar true)

#  # description: ADC_ETC Driver
#  set(CONFIG_USE_driver_adc_etc true)

#  # description: aipstz Driver
#  set(CONFIG_USE_driver_aipstz true)

#  # description: AOI Driver
#  set(CONFIG_USE_driver_aoi true)

#  # description: BEE Driver
#  set(CONFIG_USE_driver_bee true)

#  # description: CACHE Driver
#  set(CONFIG_USE_driver_cache_armv7_m7 true)

#  # description: DCDC Driver
#  set(CONFIG_USE_driver_dcdc_1 true)

#  # description: DMAMUX Driver
#  set(CONFIG_USE_driver_dmamux true)

#  # description: EDMA Driver
#  set(CONFIG_USE_driver_edma true)

#  # description: ENC Driver
#  set(CONFIG_USE_driver_enc true)

#  # description: EWM Driver
#  set(CONFIG_USE_driver_ewm true)

#  # description: FLEXIO Driver
#  set(CONFIG_USE_driver_flexio true)

#  # description: FLEXIO Driver
#  set(CONFIG_USE_driver_flexio_camera true)

#  # description: FLEXIO I2C Driver
#  set(CONFIG_USE_driver_flexio_i2c_master true)

#  # description: FLEXIO I2S Driver
#  set(CONFIG_USE_driver_flexio_i2s true)

#  # description: FLEXIO MCULCD Driver
#  set(CONFIG_USE_driver_flexio_mculcd true)

#  # description: FLEXIO SPI Driver
#  set(CONFIG_USE_driver_flexio_spi true)

#  # description: FLEXIO UART Driver
#  set(CONFIG_USE_driver_flexio_uart true)

#  # description: FLEXRAM Driver
#  set(CONFIG_USE_driver_flexram true)

#  # description: FLEXSPI Driver
#  set(CONFIG_USE_driver_flexspi true)

#  # description: GPC Driver
#  set(CONFIG_USE_driver_gpc_1 true)

#  # description: GPT Driver
#  set(CONFIG_USE_driver_gpt true)

#  # description: GPIO Driver
#  set(CONFIG_USE_driver_igpio true)

#  # description: KPP Driver
#  set(CONFIG_USE_driver_kpp true)

#  # description: LPI2C Driver
#  set(CONFIG_USE_driver_lpi2c true)

#  # description: LPI2C Driver
#  set(CONFIG_USE_driver_lpi2c_freertos true)

#  # description: LPSPI Driver
#  set(CONFIG_USE_driver_lpspi true)

#  # description: LPSPI Driver
#  set(CONFIG_USE_driver_lpspi_freertos true)

#  # description: LPUART Driver
#  set(CONFIG_USE_driver_lpuart true)

#  # description: LPUART Driver
#  set(CONFIG_USE_driver_lpuart_freertos true)

#  # description: OCOTP Driver
#  set(CONFIG_USE_driver_ocotp true)

#  # description: PIT Driver
#  set(CONFIG_USE_driver_pit true)

#  # description: pmu Driver
#  set(CONFIG_USE_driver_pmu true)

#  # description: PWM Driver
#  set(CONFIG_USE_driver_pwm true)

#  # description: QTMR Driver
#  set(CONFIG_USE_driver_qtmr_1 true)

#  # description: RTWDOG Driver
#  set(CONFIG_USE_driver_rtwdog true)

#  # description: SAI Driver
#  set(CONFIG_USE_driver_sai true)

#  # description: SNVS HP Driver
#  set(CONFIG_USE_driver_snvs_hp true)

#  # description: SNVS LP Driver
#  set(CONFIG_USE_driver_snvs_lp true)

#  # description: SPDIF Driver
#  set(CONFIG_USE_driver_spdif true)

#  # description: SRC Driver
#  set(CONFIG_USE_driver_src true)

#  # description: TEMPMON Driver
#  set(CONFIG_USE_driver_tempmon true)

#  # description: TRNG Driver
#  set(CONFIG_USE_driver_trng true)

#  # description: wdog01 Driver
#  set(CONFIG_USE_driver_wdog01 true)

#  # description: XBARA Driver
#  set(CONFIG_USE_driver_xbara true)

#  # description: XBARB Driver
#  set(CONFIG_USE_driver_xbarb true)

#  # description: ROMAPI Driver
#  set(CONFIG_USE_driver_romapi true)

#  # description: NIC301 Driver
#  set(CONFIG_USE_driver_nic301 true)

#  # description: SOC FLEXRAM ALLOCATE Driver
#  set(CONFIG_USE_driver_soc_flexram_allocate true)

#  # description: XIP Device Driver
#  set(CONFIG_USE_driver_xip_device true)

#  # description: SEGGER Real Time Transfer(RTT)
#  set(CONFIG_USE_driver_rtt true)

#set.CMSIS
#  # description: CMSIS-CORE for Cortex-M, ARMv8-M, ARMv8.1-M
#  set(CONFIG_USE_CMSIS_Include_core_cm true)

#  # description: Access to #include Driver_USART.h file for custom implementation
#  set(CONFIG_USE_CMSIS_Driver_Include_USART true)

#  # description: Access to #include Driver_CAN.h file for custom implementation
#  set(CONFIG_USE_CMSIS_Driver_Include_CAN true)

#  # description: Access to #include Driver_ETH.h file for custom implementation
#  set(CONFIG_USE_CMSIS_Driver_Include_Ethernet true)

#  # description: Access to #include Driver_ETH_MAC.h file for custom implementation
#  set(CONFIG_USE_CMSIS_Driver_Include_Ethernet_MAC true)

#  # description: Access to #include Driver_ETH_PHY.h file for custom implementation
#  set(CONFIG_USE_CMSIS_Driver_Include_Ethernet_PHY true)

#  # description: Access to #include Driver_Flash.h file for custom implementation
#  set(CONFIG_USE_CMSIS_Driver_Include_Flash true)

#  # description: Access to #include Driver_I2C.h file for custom implementation
#  set(CONFIG_USE_CMSIS_Driver_Include_I2C true)

#  # description: Access to #include Driver_MCI.h file for custom implementation
#  set(CONFIG_USE_CMSIS_Driver_Include_MCI true)

#  # description: Access to #include Driver_NAND.h file for custom implementation
#  set(CONFIG_USE_CMSIS_Driver_Include_NAND true)

#  # description: Access to #include Driver_SAI.h file for custom implementation
#  set(CONFIG_USE_CMSIS_Driver_Include_SAI true)

#  # description: Access to #include Driver_SPI.h file for custom implementation
#  set(CONFIG_USE_CMSIS_Driver_Include_SPI true)

#  # description: Access to #include Driver_USBD.h file for custom implementation
#  set(CONFIG_USE_CMSIS_Driver_Include_USB_Device true)

#  # description: Access to #include Driver_USBH.h file for custom implementation
#  set(CONFIG_USE_CMSIS_Driver_Include_USB_Host true)

#  # description: Access to #include Driver_WiFi.h file
#  set(CONFIG_USE_CMSIS_Driver_Include_WiFi true)

#  # description: Device interrupt controller interface
#  set(CONFIG_USE_CMSIS_Device_API_OSTick true)

#  # description: CMSIS-RTOS API for Cortex-M, SC000, and SC300
#  set(CONFIG_USE_CMSIS_Device_API_RTOS2 true)

#  # description: CMSIS-RTOS2 RTX5 for Cortex-M, SC000, C300 and Armv8-M (Library)
#  set(CONFIG_USE_CMSIS_RTOS2_Secure true)

#  # description: CMSIS-RTOS2 RTX5 for Armv8-M Non-Secure Domain (Library)
#  set(CONFIG_USE_CMSIS_RTOS2_NonSecure true)

#set.CMSIS_DSP_Lib
#  # description: CMSIS-DSP Library Header
#  set(CONFIG_USE_CMSIS_DSP_Include true)

#  # description: CMSIS-DSP Library
#  set(CONFIG_USE_CMSIS_DSP_Source true)

#  # description: CMSIS-NN Library
#  set(CONFIG_USE_CMSIS_NN_Source true)

#set.middleware.fatfs
#  # description: FatFs template MMC
#  set(CONFIG_USE_middleware_fatfs_template_mmc true)

#  # description: FatFs template NAND
#  set(CONFIG_USE_middleware_fatfs_template_nand true)

#  # description: FatFs template RAM
#  set(CONFIG_USE_middleware_fatfs_template_ram true)

#  # description: FatFs template SD
#  set(CONFIG_USE_middleware_fatfs_template_sd true)

#  # description: FatFs template SDSPI
#  set(CONFIG_USE_middleware_fatfs_template_sdspi true)

#  # description: FatFs template USB
#  set(CONFIG_USE_middleware_fatfs_template_usb true)

#  # description: FatFs
#  set(CONFIG_USE_middleware_fatfs true)

#  # description: FatFs_RAM
#  set(CONFIG_USE_middleware_fatfs_ram true)

#  # description: FatFs_USB
#  set(CONFIG_USE_middleware_fatfs_usb true)

#set.middleware.freertos-kernel
#  # description: FreeRTOS NXP extension
#  set(CONFIG_USE_middleware_freertos-kernel_extension true)

#  # description: Template configuration file to be edited by user. Provides also memory allocator (heap_x), change variant if needed.
#  set(CONFIG_USE_middleware_freertos-kernel_template true)

#  # description: FreeRTOS kernel
#  set(CONFIG_USE_middleware_freertos-kernel true)

#  # description: FreeRTOS heap 1
#  set(CONFIG_USE_middleware_freertos-kernel_heap_1 true)

#  # description: FreeRTOS heap 2
#  set(CONFIG_USE_middleware_freertos-kernel_heap_2 true)

#  # description: FreeRTOS heap 3
#  set(CONFIG_USE_middleware_freertos-kernel_heap_3 true)

#  # description: FreeRTOS heap 4
#  set(CONFIG_USE_middleware_freertos-kernel_heap_4 true)

#  # description: FreeRTOS heap 5
#  set(CONFIG_USE_middleware_freertos-kernel_heap_5 true)

#  # description: FreeRTOS MPU wrappers
#  set(CONFIG_USE_middleware_freertos-kernel_mpu_wrappers true)

#set.middleware.issdk
#  # description: ISSDK Serial to MQTT bridge application
#  set(CONFIG_USE_middleware_issdk_sensor_tools true)

#  # description: ISSDK Utils
#  set(CONFIG_USE_middleware_issdk_drivers_systick_utils true)

#  # description: ISSDK Sensors RegDefs
#  set(CONFIG_USE_middleware_issdk_sensor_allregdefs true)

#  # description: ISSDK FXAS21002 Sensor Driver Files
#  set(CONFIG_USE_middleware_issdk_sensor_fxas21002 true)

#  # description: ISSDK FXOS8700 Sensor Driver Files
#  set(CONFIG_USE_middleware_issdk_sensor_fxos8700 true)

#  # description: ISSDK MPL3115 Sensor Driver Files
#  set(CONFIG_USE_middleware_issdk_sensor_mpl3115 true)

#  # description: ISSDK FXLC95000 Sensor Driver Files
#  set(CONFIG_USE_middleware_issdk_sensor_fxlc95000 true)

#  # description: ISSDK MMA8491 Sensor Driver Files
#  set(CONFIG_USE_middleware_issdk_sensor_mma8491q true)

#  # description: ISSDK FXLS8471 Sensor Driver Files
#  set(CONFIG_USE_middleware_issdk_sensor_fxls8471q true)

#  # description: ISSDK MAG3110 Sensor Driver Files
#  set(CONFIG_USE_middleware_issdk_sensor_mag3110 true)

#  # description: ISSDK MMA845x Sensor Driver Files
#  set(CONFIG_USE_middleware_issdk_sensor_mma845x true)

#  # description: ISSDK MMA865x Sensor Driver Files
#  set(CONFIG_USE_middleware_issdk_sensor_mma865x true)

#  # description: ISSDK FXPQ3115 Sensor Driver Files
#  set(CONFIG_USE_middleware_issdk_sensor_fxpq3115 true)

#  # description: ISSDK FXLS8962 Sensor Driver Files
#  set(CONFIG_USE_middleware_issdk_sensor_fxls8962 true)

#  # description: ISSDK MMA9553 Sensor Driver Files
#  set(CONFIG_USE_middleware_issdk_sensor_mma9553 true)

#  # description: ISSDK nps300x Sensor Driver Files
#  set(CONFIG_USE_middleware_issdk_sensor_nps300x true)

#  # description: ISSDK ISL29023 Sensor Driver Files
#  set(CONFIG_USE_middleware_issdk_sensor_isl29023 true)

#  # description: ISSDK fxps7250d4 Sensor Driver Files
#  set(CONFIG_USE_middleware_issdk_sensor_fxps7250d4 true)

#  # description: ISSDK FXLS896xAF Sensor Driver Files
#  set(CONFIG_USE_middleware_issdk_sensor_fxls896xaf true)

#  # description: ISSDK FXLS8974CF Sensor Driver Files
#  set(CONFIG_USE_middleware_issdk_sensor_fxls8974cf true)

#  # description: ISSDK FXLS8961AF Sensor Driver Files
#  set(CONFIG_USE_middleware_issdk_sensor_fxls8961af true)

#  # description: ISSDK FXLS8971CF Sensor Driver Files
#  set(CONFIG_USE_middleware_issdk_sensor_fxls8971cf true)

#  # description: ISSDK NMH1000 Sensor Driver Files
#  set(CONFIG_USE_middleware_issdk_sensor_nmh1000 true)

#  # description: ISSDK Sensor Interface Common
#  set(CONFIG_USE_middleware_issdk_sensor_interface_common true)

#  # description: ISSDK GPIO Driver for i.MXRT10xx
#  set(CONFIG_USE_middleware_issdk_drivers_gpio_imx true)

#  # description: ISSDK GPIO Driver for i.MX8xx
#  set(CONFIG_USE_middleware_issdk_drivers_gpio_imx8 true)

#  # description: ISSDK GPIO Driver for i.MXRT685
#  set(CONFIG_USE_middleware_issdk_drivers_gpio_imxrt600 true)

#  # description: ISSDK GPIO Driver for i.MXRT1180
#  set(CONFIG_USE_middleware_issdk_drivers_gpio_imxrt1180 true)

#  # description: ISSDK GPIO Driver for i.MXRT
#  set(CONFIG_USE_middleware_issdk_drivers_gpio_imxrt true)

#  # description: ISSDK Host Interface Service
#  set(CONFIG_USE_middleware_issdk_drivers_host true)

#set.middleware.azure_rtos
#  # description: Azure RTOS Core
#  set(CONFIG_USE_middleware_azure_rtos_tx_template true)

#  # description: Azure RTOS Core
#  set(CONFIG_USE_middleware_azure_rtos_tx_mgr_template true)

#  # description: Real Time Operating System Kernel
#  set(CONFIG_USE_middleware_azure_rtos_tx_lib true)

#  # description: Real Time Operating System Kernel
#  set(CONFIG_USE_middleware_azure_rtos_tx_mgr_lib true)

#  # description: Real Time Operating System Kernel
#  set(CONFIG_USE_middleware_azure_rtos_txm_lib true)

#  # description: A file system based on azure RTOS
#  set(CONFIG_USE_middleware_azure_rtos_fx_template true)

#  # description: A file system based on azure RTOS
#  set(CONFIG_USE_middleware_azure_rtos_fx_lib true)

#  # description: A GUI library based on azure RTOS
#  set(CONFIG_USE_middleware_azure_rtos_gx_lib true)

#  # description: A network protocol stack based on azure RTOS
#  set(CONFIG_USE_middleware_azure_rtos_nxd_template true)

#  # description: A network protocol stack based on azure RTOS
#  set(CONFIG_USE_middleware_azure_rtos_nxd_lib true)

#  # description: A USB library based on azure RTOS
#  set(CONFIG_USE_middleware_azure_rtos_ux_template true)

#  # description: Azure RTOS USBX Host Controller EHCI
#  set(CONFIG_USE_middleware_azure_rtos_ux_ehci true)

#  # description: Azure RTOS USBX Host Controller OHCI
#  set(CONFIG_USE_middleware_azure_rtos_ux_ohci true)

#  # description: Azure RTOS USBX Host Controller IP3516
#  set(CONFIG_USE_middleware_azure_rtos_ux_ip3516 true)

#  # description: Azure RTOS USBX Device Controller IP3511
#  set(CONFIG_USE_middleware_azure_rtos_ux_ip3511 true)

#  # description: Azure RTOS USBX Device Controller for i.MX RT
#  set(CONFIG_USE_middleware_azure_rtos_ux_dci true)

#  # description: A USB library based on azure RTOS
#  set(CONFIG_USE_middleware_azure_rtos_ux_lib true)

#  # description: Azure RTOS Core
#  set(CONFIG_USE_middleware_azure_rtos_tx true)

#  # description: Azure RTOS Core
#  set(CONFIG_USE_middleware_azure_rtos_tx_mgr true)

#  # description: Azure RTOS Core
#  set(CONFIG_USE_middleware_azure_rtos_tx_sp true)

#  # description: A file system based on azure RTOS
#  set(CONFIG_USE_middleware_azure_rtos_fx true)

#  # description: A file system based on azure RTOS
#  set(CONFIG_USE_middleware_azure_rtos_fx_sp true)

#  # description: A GUI library based on azure RTOS
#  set(CONFIG_USE_middleware_azure_rtos_gx true)

#  # description: LevelX provides NAND and NOR flash wear leveling facilities to embedded applications
#  set(CONFIG_USE_middleware_azure_rtos_lx true)

#  # description: A network protocol stack based on azure RTOS
#  set(CONFIG_USE_middleware_azure_rtos_nxd true)

#  # description: A network protocol stack based on azure RTOS
#  set(CONFIG_USE_middleware_azure_rtos_nxd_sp true)

#  # description: Azure NetX Duo driver based on i.MXRT series
#  set(CONFIG_USE_middleware_netxduo_imxrt true)

#  # description: A USB library based on azure RTOS
#  set(CONFIG_USE_middleware_azure_rtos_ux true)

#  # description: A USB library based on azure RTOS
#  set(CONFIG_USE_middleware_azure_rtos_ux_sp true)

#  # description: A software package that connects to the IoT Hub through Azure RTOS
#  set(CONFIG_USE_middleware_azure_rtos_azure_iot true)

#set.middleware.usb
#  # description: USB device ehci config header
#  set(CONFIG_USE_middleware_usb_device_ehci_config_header true)

#  # description: Middleware usb common_header
#  set(CONFIG_USE_middleware_usb_common_header true)

#  # description: Middleware usb device common_header
#  set(CONFIG_USE_middleware_usb_device_common_header true)

#  # description: Middleware usb device ehci
#  set(CONFIG_USE_middleware_usb_device_ehci true)

#  # description: Middleware usb phy
#  set(CONFIG_USE_middleware_usb_phy true)

#  # description: Middleware usb device stack external
#  set(CONFIG_USE_middleware_usb_device_stack_external true)

#  # description: Middleware usb device audio external
#  set(CONFIG_USE_middleware_usb_device_audio_external true)

#  # description: Middleware usb device cdc external
#  set(CONFIG_USE_middleware_usb_device_cdc_external true)

#  # description: Middleware usb device cdc rndis external
#  set(CONFIG_USE_middleware_usb_device_cdc_rndis_external true)

#  # description: Middleware usb device hid external
#  set(CONFIG_USE_middleware_usb_device_hid_external true)

#  # description: Middleware usb device dfu external
#  set(CONFIG_USE_middleware_usb_device_dfu_external true)

#  # description: Middleware usb device msd external
#  set(CONFIG_USE_middleware_usb_device_msd_external true)

#  # description: Middleware usb device phdc external
#  set(CONFIG_USE_middleware_usb_device_phdc_external true)

#  # description: Middleware usb device video external
#  set(CONFIG_USE_middleware_usb_device_video_external true)

#  # description: Middleware usb device ccid external
#  set(CONFIG_USE_middleware_usb_device_ccid_external true)

#  # description: Middleware usb device printer external
#  set(CONFIG_USE_middleware_usb_device_printer_external true)

#  # description: Middleware usb device controller driver
#  set(CONFIG_USE_middleware_usb_device_controller_driver true)

#  # description: Middleware usb host ehci
#  set(CONFIG_USE_middleware_usb_host_ehci true)

#  # description: Middleware usb host audio
#  set(CONFIG_USE_middleware_usb_host_audio true)

#  # description: Middleware usb host cdc
#  set(CONFIG_USE_middleware_usb_host_cdc true)

#  # description: Middleware usb host cdc_rndis
#  set(CONFIG_USE_middleware_usb_host_cdc_rndis true)

#  # description: Middleware usb host hid
#  set(CONFIG_USE_middleware_usb_host_hid true)

#  # description: Middleware usb host msd
#  set(CONFIG_USE_middleware_usb_host_msd true)

#  # description: Middleware usb host video
#  set(CONFIG_USE_middleware_usb_host_video true)

#  # description: Middleware usb host phdc
#  set(CONFIG_USE_middleware_usb_host_phdc true)

#  # description: Middleware usb host printer
#  set(CONFIG_USE_middleware_usb_host_printer true)

#  # description: Middleware usb host common_header
#  set(CONFIG_USE_middleware_usb_host_common_header true)

#  # description: USB host ehci config header
#  set(CONFIG_USE_middleware_usb_host_ehci_config_header true)

#  # description: Middleware usb host stack
#  set(CONFIG_USE_middleware_usb_host_stack true)

#set.component.osa
#  # description: Component common_task
#  set(CONFIG_USE_component_common_task true)

#  # description: Component osa_bm
#  set(CONFIG_USE_component_osa_bm true)

#  # description: Component osa_free_rtos
#  set(CONFIG_USE_component_osa_free_rtos true)

#  # description: Component osa
#  set(CONFIG_USE_component_osa true)

#  # description: Component osa interface
#  set(CONFIG_USE_component_osa_interface true)

#  # description: Component osa thread
#  set(CONFIG_USE_component_osa_thread true)

list(APPEND CMAKE_MODULE_PATH
  ${CMAKE_CURRENT_LIST_DIR}/.
  ${CMAKE_CURRENT_LIST_DIR}/../../components/osa
  ${CMAKE_CURRENT_LIST_DIR}/../../../middleware/fatfs
  ${CMAKE_CURRENT_LIST_DIR}/../../middleware/issdk
  ${CMAKE_CURRENT_LIST_DIR}/../../../middleware/usb
  ${CMAKE_CURRENT_LIST_DIR}/../../../rtos/azure-rtos
  ${CMAKE_CURRENT_LIST_DIR}/../../../rtos/freertos/freertos-kernel
  ${CMAKE_CURRENT_LIST_DIR}/drivers
  ${CMAKE_CURRENT_LIST_DIR}/project_template
  ${CMAKE_CURRENT_LIST_DIR}/template
  ${CMAKE_CURRENT_LIST_DIR}/xip
  ${CMAKE_CURRENT_LIST_DIR}/../../CMSIS
  ${CMAKE_CURRENT_LIST_DIR}/../../boards/evkmimxrt1015
  ${CMAKE_CURRENT_LIST_DIR}/../../devices/MIMXRT1166
  ${CMAKE_CURRENT_LIST_DIR}/../../devices/MIMXRT1052
)

include(set_board_evkmimxrt1015 OPTIONAL)
include(set_CMSIS_DSP_Lib OPTIONAL)
include(set_CMSIS OPTIONAL)
include(set_device_MIMXRT1015 OPTIONAL)
include(set_component_osa OPTIONAL)
include(set_middleware_azure_rtos OPTIONAL)
include(set_middleware_fatfs OPTIONAL)
include(set_middleware_freertos-kernel OPTIONAL)
include(set_middleware_issdk OPTIONAL)
include(set_middleware_usb OPTIONAL)
