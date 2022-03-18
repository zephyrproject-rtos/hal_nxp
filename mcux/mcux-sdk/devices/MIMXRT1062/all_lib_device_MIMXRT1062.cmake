list(APPEND CMAKE_MODULE_PATH
    ${CMAKE_CURRENT_LIST_DIR}/.
    ${CMAKE_CURRENT_LIST_DIR}/../../CMSIS/Core/Include
    ${CMAKE_CURRENT_LIST_DIR}/../../CMSIS/DSP
    ${CMAKE_CURRENT_LIST_DIR}/../../CMSIS/Driver/Include
    ${CMAKE_CURRENT_LIST_DIR}/../../boards/evkbmimxrt1060/xip
    ${CMAKE_CURRENT_LIST_DIR}/../../boards/evkmimxrt1060/xip
    ${CMAKE_CURRENT_LIST_DIR}/../../cmsis_drivers/enet
    ${CMAKE_CURRENT_LIST_DIR}/../../cmsis_drivers/lpi2c
    ${CMAKE_CURRENT_LIST_DIR}/../../cmsis_drivers/lpspi
    ${CMAKE_CURRENT_LIST_DIR}/../../cmsis_drivers/lpuart
    ${CMAKE_CURRENT_LIST_DIR}/../../components/audio
    ${CMAKE_CURRENT_LIST_DIR}/../../components/button
    ${CMAKE_CURRENT_LIST_DIR}/../../components/codec
    ${CMAKE_CURRENT_LIST_DIR}/../../components/codec/cs42448
    ${CMAKE_CURRENT_LIST_DIR}/../../components/codec/i2c
    ${CMAKE_CURRENT_LIST_DIR}/../../components/codec/wm8960
    ${CMAKE_CURRENT_LIST_DIR}/../../components/common_task
    ${CMAKE_CURRENT_LIST_DIR}/../../components/flash/mflash
    ${CMAKE_CURRENT_LIST_DIR}/../../components/flash/mflash/mimxrt1062
    ${CMAKE_CURRENT_LIST_DIR}/../../components/flash/nor
    ${CMAKE_CURRENT_LIST_DIR}/../../components/flash/nor/flexspi
    ${CMAKE_CURRENT_LIST_DIR}/../../components/ft5406_rt
    ${CMAKE_CURRENT_LIST_DIR}/../../components/fxos8700cq
    ${CMAKE_CURRENT_LIST_DIR}/../../components/gpio
    ${CMAKE_CURRENT_LIST_DIR}/../../components/i2c
    ${CMAKE_CURRENT_LIST_DIR}/../../components/internal_flash
    ${CMAKE_CURRENT_LIST_DIR}/../../components/lists
    ${CMAKE_CURRENT_LIST_DIR}/../../components/log
    ${CMAKE_CURRENT_LIST_DIR}/../../components/mem_manager
    ${CMAKE_CURRENT_LIST_DIR}/../../components/messaging
    ${CMAKE_CURRENT_LIST_DIR}/../../components/osa
    ${CMAKE_CURRENT_LIST_DIR}/../../components/panic
    ${CMAKE_CURRENT_LIST_DIR}/../../components/phy
    ${CMAKE_CURRENT_LIST_DIR}/../../components/phy/device/phyksz8081
    ${CMAKE_CURRENT_LIST_DIR}/../../components/phy/mdio/enet
    ${CMAKE_CURRENT_LIST_DIR}/../../components/rng
    ${CMAKE_CURRENT_LIST_DIR}/../../components/serial_manager
    ${CMAKE_CURRENT_LIST_DIR}/../../components/timer
    ${CMAKE_CURRENT_LIST_DIR}/../../components/timer_manager
    ${CMAKE_CURRENT_LIST_DIR}/../../components/uart
    ${CMAKE_CURRENT_LIST_DIR}/../../components/video
    ${CMAKE_CURRENT_LIST_DIR}/../../components/video/camera
    ${CMAKE_CURRENT_LIST_DIR}/../../components/video/camera/device
    ${CMAKE_CURRENT_LIST_DIR}/../../components/video/camera/device/mt9m114
    ${CMAKE_CURRENT_LIST_DIR}/../../components/video/camera/device/ov7725
    ${CMAKE_CURRENT_LIST_DIR}/../../components/video/camera/device/sccb
    ${CMAKE_CURRENT_LIST_DIR}/../../components/video/camera/receiver
    ${CMAKE_CURRENT_LIST_DIR}/../../components/video/camera/receiver/csi
    ${CMAKE_CURRENT_LIST_DIR}/../../components/video/display/dc
    ${CMAKE_CURRENT_LIST_DIR}/../../components/video/display/dc/elcdif
    ${CMAKE_CURRENT_LIST_DIR}/../../components/video/display/fbdev
    ${CMAKE_CURRENT_LIST_DIR}/../../components/video/i2c
    ${CMAKE_CURRENT_LIST_DIR}/../../drivers/adc_12b1msps_sar
    ${CMAKE_CURRENT_LIST_DIR}/../../drivers/adc_etc
    ${CMAKE_CURRENT_LIST_DIR}/../../drivers/aoi
    ${CMAKE_CURRENT_LIST_DIR}/../../drivers/bee
    ${CMAKE_CURRENT_LIST_DIR}/../../drivers/cache/armv7-m7
    ${CMAKE_CURRENT_LIST_DIR}/../../drivers/cmp
    ${CMAKE_CURRENT_LIST_DIR}/../../drivers/common
    ${CMAKE_CURRENT_LIST_DIR}/../../drivers/csi
    ${CMAKE_CURRENT_LIST_DIR}/../../drivers/dcdc_1
    ${CMAKE_CURRENT_LIST_DIR}/../../drivers/dcp
    ${CMAKE_CURRENT_LIST_DIR}/../../drivers/dmamux
    ${CMAKE_CURRENT_LIST_DIR}/../../drivers/edma
    ${CMAKE_CURRENT_LIST_DIR}/../../drivers/elcdif
    ${CMAKE_CURRENT_LIST_DIR}/../../drivers/enc
    ${CMAKE_CURRENT_LIST_DIR}/../../drivers/enet
    ${CMAKE_CURRENT_LIST_DIR}/../../drivers/ewm
    ${CMAKE_CURRENT_LIST_DIR}/../../drivers/flexcan
    ${CMAKE_CURRENT_LIST_DIR}/../../drivers/flexio
    ${CMAKE_CURRENT_LIST_DIR}/../../drivers/flexram
    ${CMAKE_CURRENT_LIST_DIR}/../../drivers/flexspi
    ${CMAKE_CURRENT_LIST_DIR}/../../drivers/gpc_1
    ${CMAKE_CURRENT_LIST_DIR}/../../drivers/gpt
    ${CMAKE_CURRENT_LIST_DIR}/../../drivers/igpio
    ${CMAKE_CURRENT_LIST_DIR}/../../drivers/kpp
    ${CMAKE_CURRENT_LIST_DIR}/../../drivers/lpi2c
    ${CMAKE_CURRENT_LIST_DIR}/../../drivers/lpspi
    ${CMAKE_CURRENT_LIST_DIR}/../../drivers/lpuart
    ${CMAKE_CURRENT_LIST_DIR}/../../drivers/ocotp
    ${CMAKE_CURRENT_LIST_DIR}/../../drivers/pit
    ${CMAKE_CURRENT_LIST_DIR}/../../drivers/pwm
    ${CMAKE_CURRENT_LIST_DIR}/../../drivers/pxp
    ${CMAKE_CURRENT_LIST_DIR}/../../drivers/qtmr_1
    ${CMAKE_CURRENT_LIST_DIR}/../../drivers/rtwdog
    ${CMAKE_CURRENT_LIST_DIR}/../../drivers/sai
    ${CMAKE_CURRENT_LIST_DIR}/../../drivers/semc
    ${CMAKE_CURRENT_LIST_DIR}/../../drivers/snvs_hp
    ${CMAKE_CURRENT_LIST_DIR}/../../drivers/snvs_lp
    ${CMAKE_CURRENT_LIST_DIR}/../../drivers/src
    ${CMAKE_CURRENT_LIST_DIR}/../../drivers/tempmon
    ${CMAKE_CURRENT_LIST_DIR}/../../drivers/trng
    ${CMAKE_CURRENT_LIST_DIR}/../../drivers/usdhc
    ${CMAKE_CURRENT_LIST_DIR}/../../drivers/wdog01
    ${CMAKE_CURRENT_LIST_DIR}/../../drivers/xbara
    ${CMAKE_CURRENT_LIST_DIR}/../../drivers/xbarb
    ${CMAKE_CURRENT_LIST_DIR}/../../../middleware
    ${CMAKE_CURRENT_LIST_DIR}/../../../middleware/eiq
    ${CMAKE_CURRENT_LIST_DIR}/../../../middleware/eiq/tensorflow-lite
    ${CMAKE_CURRENT_LIST_DIR}/../../../middleware/eiq/tensorflow-lite/third_party/cmsis
    ${CMAKE_CURRENT_LIST_DIR}/../../../middleware/fatfs
    ${CMAKE_CURRENT_LIST_DIR}/../../../middleware/multicore
    ${CMAKE_CURRENT_LIST_DIR}/../../../middleware/sdmmc
    ${CMAKE_CURRENT_LIST_DIR}/../../../middleware/usb
    ${CMAKE_CURRENT_LIST_DIR}/../../../middleware/wireless/ethermind
    ${CMAKE_CURRENT_LIST_DIR}/../../../middleware/wireless/ethermind/port/pal/mcux/bluetooth/controller/wifi
    ${CMAKE_CURRENT_LIST_DIR}/../../../rtos/azure-rtos
    ${CMAKE_CURRENT_LIST_DIR}/../../../rtos/freertos/freertos_kernel
    ${CMAKE_CURRENT_LIST_DIR}/../../utilities/assert
    ${CMAKE_CURRENT_LIST_DIR}/../../utilities/debug_console
    ${CMAKE_CURRENT_LIST_DIR}/../../utilities/debug_console_lite
    ${CMAKE_CURRENT_LIST_DIR}/../../utilities/misc_utilities
    ${CMAKE_CURRENT_LIST_DIR}/drivers
    ${CMAKE_CURRENT_LIST_DIR}/utilities
    ${CMAKE_CURRENT_LIST_DIR}/xip
)


# Copy the cmake components into projects
#    include(middleware_usb_host_cdc_rndis)
#    include(driver_lpuart_freertos)
#    include(component_codec_adapters)
#    include(middleware_usb_host_stack_MIMXRT1062)
#    include(middleware_sdmmc_osa_bm)
#    include(middleware_sdmmc_mmc)
#    include(driver_dmamux)
#    include(driver_phy-common)
#    include(driver_nor_flash-controller-flexspi)
#    include(driver_cmsis_lpuart)
#    include(middleware_azure_rtos_nxd)
#    include(device_system)
#    include(driver_snvs_lp)
#    include(driver_dc-fb-common)
#    include(driver_camera-device-mt9m114)
#    include(driver_mdio-enet)
#    include(driver_flexio_uart)
#    include(driver_wm8960)
#    include(driver_ewm)
#    include(driver_flexio)
#    include(driver_aoi)
#    include(component_flexspi_nor_flash_adapter_rt1060evk)
#    include(driver_enc)
#    include(driver_flexio_i2c_master)
#    include(middleware_baremetal)
#    include(component_cs42448_adapter)
#    include(middleware_sdmmc_host_usdhc)
#    include(component_log_backend_ringbuffer)
#    include(driver_lpuart_edma)
#    include(driver_lpspi_edma)
#    include(component_mflash_file_MIMXRT1062)
#    include(driver_wdog01)
#    include(driver_flexio_uart_edma)
#    include(driver_ocotp)
#    include(driver_codec)
#    include(utilities_misc_utilities)
#    include(driver_pxp)
#    include(driver_xip_device)
#    include(component_mflash_rt1060)
#    include(middleware_eiq_deepviewrt_deps_stb)
#    include(component_serial_manager)
#    include(middleware_wireless_ethermind_wifi_fwdnld)
#    include(driver_camera-device-ov7725)
#    include(driver_pit)
#    include(middleware_eiq_tensorflow_lite_micro_third_party_cmsis_nn)
#    include(middleware_azure_rtos_ux)
#    include(component_serial_manager_uart)
#    include(driver_lpspi_freertos)
#    include(component_log_backend_debugconsole)
#    include(CMSIS_Driver_Include_Ethernet_MAC)
#    include(CMSIS_DSP_Library)
#    include(driver_tempmon)
#    include(component_lpuart_adapter)
#    include(driver_lpi2c_edma)
#    include(middleware_sdmmc_osa_freertos)
#    include(middleware_usb_device_cdc_external)
#    include(driver_cmsis_enet)
#    include(utility_shell)
#    include(device_startup)
#    include(middleware_eiq_deepviewrt_deps_flatcc)
#    include(component_panic)
#    include(driver_phy-device-ksz8081)
#    include(driver_usdhc)
#    include(driver_gpt)
#    include(utility_assert)
#    include(driver_enet)
#    include(driver_rtwdog)
#    include(middleware_freertos-kernel_extension)
#    include(CMSIS_Driver_Include_I2C)
#    include(driver_camera-receiver-common)
#    include(driver_nor_flash-common)
#    include(middleware_usb_common_header)
#    include(driver_cmsis_lpi2c)
#    include(CMSIS_Driver_Include_Ethernet)
#    include(driver_soc_flexram_allocate)
#    include(component_serial_manager_usb_cdc)
#    include(driver_flexcan_edma)
#    include(middleware_eiq_worker_video_MIMXRT1062)
#    include(device_CMSIS)
#    include(driver_romapi)
#    include(CMSIS_Driver_Include_Common)
#    include(middleware_azure_rtos_fx)
#    include(middleware_multicore_erpc_doc)
#    include(driver_ft5406_rt)
#    include(component_codec_i2c_MIMXRT1062)
#    include(component_osa_bm)
#    include(driver_camera-device-sccb)
#    include(driver_adc_12b1msps_sar)
#    include(component_mflash_dummy)
#    include(driver_common)
#    include(middleware_eiq_gui_printf)
#    include(driver_kpp)
#    include(middleware_multicore_erpc_common)
#    include(middleware_usb_host_ehci)
#    include(component_osa_free_rtos)
#    include(driver_camera-common)
#    include(driver_camera-device-common)
#    include(middleware_eiq_deepviewrt_modelrunner_server_flash)
#    include(component_lpi2c_adapter)
#    include(middleware_freertos-kernel_heap_3)
#    include(CMSIS_Include_core_cm)
#    include(driver_video-common)
#    include(middleware_freertos-kernel_heap_4)
#    include(driver_dcdc_1)
#    include(middleware_azure_rtos_ux_template_MIMXRT1062)
#    include(middleware_azure_rtos_tx)
#    include(middleware_sdmmc_host_usdhc_polling_MIMXRT1062)
#    include(middleware_azure_rtos_nxd_template_MIMXRT1062)
#    include(middleware_sdmmc_sdio)
#    include(middleware_eiq_deepviewrt_deps_json)
#    include(driver_snvs_hp)
#    include(middleware_sdmmc_host_usdhc_interrupt_MIMXRT1062)
#    include(middleware_usb_host_msd)
#    include(middleware_azure_rtos_fx_template_MIMXRT1062)
#    include(driver_lpspi)
#    include(driver_flexspi_edma)
#    include(component_gpt_adapter)
#    include(middleware_usb_host_common_header)
#    include(component_flexspi_nor_flash_adapter)
#    include(driver_csi)
#    include(component_log)
#    include(middleware_sdmmc_host_usdhc_freertos_MIMXRT1062)
#    include(middleware_eiq_worker)
#    include(driver_xip_board_evkbmimxrt1060)
#    include(middleware_multicore_erpc_eRPC_server)
#    include(CMSIS_Driver_Include_USART)
#    include(CMSIS_Driver_Include_SPI)
#    include(utility_debug_console_lite)
#    include(component_audio_sai_edma_adapter)
#    include(driver_mdio-common)
#    include(middleware_usb_host_phdc)
#    include(middleware_usb_host_printer)
#    include(driver_iomuxc)
#    include(middleware_multicore_erpc_eRPC_uart_cmsis_transport)
#    include(middleware_usb_device_common_header)
#    include(driver_flexio_spi_edma)
#    include(driver_flexram)
#    include(middleware_azure_rtos_gx)
#    include(middleware_fatfs)
#    include(driver_semc)
#    include(driver_xbarb)
#    include(driver_xbara)
#    include(middleware_usb_host_audio)
#    include(driver_flexcan)
#    include(utility_debug_console)
#    include(middleware_usb_host_hid)
#    include(component_osa_thread)
#    include(driver_lpi2c_freertos)
#    include(component_mflash_common)
#    include(driver_cmsis_lpspi)
#    include(middleware_usb_device_ehci)
#    include(component_software_rng_adapter)
#    include(middleware_azure_rtos_azure_iot)
#    include(middleware_multicore_erpc_eRPC_port_stdlib)
#    include(utility_assert_lite)
#    include(driver_camera-receiver-csi)
#    include(component_wm8960_adapter)
#    include(middleware_eiq_worker_audio)
#    include(driver_bee)
#    include(middleware_usb_phy)
#    include(driver_sai_edma)
#    include(driver_dc-fb-elcdif)
#    include(driver_dcp)
#    include(middleware_fatfs_usb)
#    include(middleware_fatfs_sd)
#    include(middleware_sdmmc_osa_azurertos)
#    include(driver_flexspi)
#    include(driver_adc_etc)
#    include(component_timer_manager)
#    include(driver_clock)
#    include(driver_qtmr_1)
#    include(driver_trng)
#    include(component_common_task)
#    include(middleware_usb_host_video)
#    include(driver_gpc_1)
#    include(component_lists)
#    include(driver_video-i2c)
#    include(middleware_sdmmc_common)
#    include(driver_cmp)
#    include(middleware_eiq_tensorflow_lite_micro_third_party_ruy)
#    include(component_igpio_adapter)
#    include(component_osa)
#    include(driver_fxos8700cq)
#    include(middleware_eiq_worker_sensor)
#    include(driver_lpuart)
#    include(driver_edma_MIMXRT1062)
#    include(driver_flexio_spi)
#    include(middleware_freertos-kernel_MIMXRT1062)
#    include(component_pit_adapter)
#    include(component_messaging)
#    include(middleware_eiq_tensorflow_lite_micro_third_party_gemmlowp)
#    include(middleware_edgefast_bluetooth_k32w061_controller)
#    include(driver_fbdev)
#    include(middleware_eiq_tensorflow_lite_micro_cmsis_nn)
#    include(middleware_eiq_tensorflow_lite_micro)
#    include(driver_cs42448)
#    include(component_button)
#    include(middleware_sdmmc_sd)
#    include(driver_src)
#    include(driver_xip_board_evkmimxrt1060)
#    include(driver_lpi2c)
#    include(middleware_azure_rtos_tx_template_MIMXRT1062)
#    include(CMSIS_Driver_Include_Ethernet_PHY)
#    include(middleware_usb_device_controller_driver_MIMXRT1062)
#    include(driver_flexio_i2s)
#    include(middleware_eiq_tensorflow_lite_micro_third_party_flatbuffers)
#    include(driver_elcdif)
#    include(driver_igpio)
#    include(driver_pwm)
#    include(component_mem_manager)
#    include(middleware_sdmmc_host_usdhc_azurertos)
#    include(driver_sai)
#    include(middleware_eiq_glow)
#    include(middleware_eiq_deepviewrt)
#    include(driver_cache_armv7_m7)
#    include(middleware_usb_host_cdc)
#    include(middleware_usb_device_stack_external)
#    include(driver_flexio_i2s_edma)
