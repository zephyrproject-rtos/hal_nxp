# Copyright 2026 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

# Copy variable into project config.cmake to use software component
#set.board.mimxrt2660evk
#  # description: Utility mimxrt2660evk_jlinkscript
#  set(CONFIG_USE_utility_jlinkscript true)

#  # description: XIP Board Driver
#  set(CONFIG_USE_board_boot_header true)

#set.device.MIMXRT2663
#  # description: IO expander PCAL6524 driver
#  set(CONFIG_USE_driver_pcal6524 true)

#  # description: IO expander PCA9555 driver
#  set(CONFIG_USE_driver_pca9555 true)

#  # description: Clock Driver
#  set(CONFIG_USE_driver_clock true)

#  # description: EDMA SOC Driver
#  set(CONFIG_USE_driver_edma_soc true)

#  # description: MEMORY Driver
#  set(CONFIG_USE_driver_memory true)

#  # description: MONCON SOC Driver
#  set(CONFIG_USE_driver_modcon true)

#  # description: TRDC SOC Driver
#  set(CONFIG_USE_driver_trdc_soc true)

#  # description: SOC MIPI DSI Driver
#  set(CONFIG_USE_driver_soc_mipi_dsi true)

#  # description: Inputmux_connections Driver
#  set(CONFIG_USE_driver_inputmux_connections true)

#  # description: Device Boot Header
#  set(CONFIG_USE_device_boot_header true)

#  # description: Middleware baremetal
#  set(CONFIG_USE_middleware_baremetal true)

#  # description: Rte_device
#  set(CONFIG_USE_device_RTE true)

#  # description: Utility notifier
#  set(CONFIG_USE_utility_notifier true)

#  # description: Utilities which is needed for particular toolchain like the SBRK function required to address limitation between HEAP and STACK in GCC toolchain library.
#  set(CONFIG_USE_utilities_misc_utilities true)

#  # description: Used to include slave core binary into master core binary.
#  set(CONFIG_USE_utility_incbin true)

#  # description: Component coremark
#  set(CONFIG_USE_component_coremark true)

#  # description: common Driver
#  set(CONFIG_USE_driver_common true)

#  # description: Wi-Fi module Tx power limits
#  set(CONFIG_USE_component_wifi_bt_module_tx_pwr_limits true)

#  # description: Wi-Fi/BT combo firmware
#  set(CONFIG_USE_component_wifi_bt_module_wifi_bt_combo_fw true)

#  # description: BT only firmware
#  set(CONFIG_USE_component_wifi_bt_module_bt_only_fw true)

#  # description: Wi-Fi firmware
#  set(CONFIG_USE_component_wifi_bt_module_wifi_fw true)

#  # description: Narrow band firmware
#  set(CONFIG_USE_component_wifi_bt_module_nb_fw true)

#  # description: wifi_nb_combo firmware
#  set(CONFIG_USE_component_wifi_bt_module_wifi_nb_combo_fw true)

#  # description: uncompressed_firmware
#  set(CONFIG_USE_component_wifi_bt_module_uncompressed_firmware true)

#  # description: FRDM M.2 adapter v1
#  set(CONFIG_USE_component_wifi_bt_module_frdm_m2_adapter_v1 true)

#  # description: IO expander ADP5585 driver
#  set(CONFIG_USE_driver_adp5585 true)

#  # description: IO expander PCA6416A driver
#  set(CONFIG_USE_driver_pca6416a true)

#  # description: IO expander PCAL6408 driver
#  set(CONFIG_USE_driver_pcal6408 true)

#  # description: IO expander PI4IO6408 driver
#  set(CONFIG_USE_driver_pi4io6408 true)

#  # description: Driver ektf2k
#  set(CONFIG_USE_driver_ektf2k true)

#  # description: Touch panel controller FT3267 driver
#  set(CONFIG_USE_driver_ft3267 true)

#  # description: Driver ft5406
#  set(CONFIG_USE_driver_ft5406 true)

#  # description: Driver gt911
#  set(CONFIG_USE_driver_gt911 true)

#  # description: Driver tma525b
#  set(CONFIG_USE_driver_tma525b true)

#  # description: Driver silicon_id imx8
#  set(CONFIG_USE_component_silicon_id_imx8 true)

#  # description: Driver silicon_id imx93
#  set(CONFIG_USE_component_silicon_id_imx93 true)

#  # description: Driver silicon_id rt10xx
#  set(CONFIG_USE_component_silicon_id_imxrt10xx true)

#  # description: Driver silicon_id imxrt1170
#  set(CONFIG_USE_component_silicon_id_imxrt1170 true)

#  # description: Driver silicon_id imxrt1180
#  set(CONFIG_USE_component_silicon_id_imxrt1180 true)

#  # description: Driver silicon_id imxrt2660
#  set(CONFIG_USE_component_silicon_id_imxrt2660 true)

#  # description: Driver silicon_id rw610
#  set(CONFIG_USE_component_silicon_id_rw610 true)

#  # description: Driver silicon_id mcxn
#  set(CONFIG_USE_component_silicon_id_mcxn true)

#  # description: Driver silicon_id scfw
#  set(CONFIG_USE_component_silicon_id_scfw true)

#  # description: Driver silicon_id mcxe31x
#  set(CONFIG_USE_component_silicon_id_mcxe31x true)

#  # description: Component serial_manager_swo
#  set(CONFIG_USE_component_serial_manager_swo true)

#  # description: Component serial_manager_virtual
#  set(CONFIG_USE_component_serial_manager_virtual true)

#  # description: Component serial_manager_ble_wu
#  set(CONFIG_USE_component_serial_manager_ble_wu true)

#  # description: RTT template configuration
#  set(CONFIG_USE_driver_rtt_template true)

#  # description: Component rnga_adapter
#  set(CONFIG_USE_component_rnga_adapter true)

#  # description: Component reset_adapter
#  set(CONFIG_USE_component_reset_adapter true)

#  # description: Component panic
#  set(CONFIG_USE_component_panic true)

#  # description: Driver mx25r_flash
#  set(CONFIG_USE_driver_mx25r_flash true)

#  # description: Component software_crc_adapter
#  set(CONFIG_USE_component_software_crc_adapter true)

#  # description: Component ak4497 adapter for single codec
#  set(CONFIG_USE_component_ak4497_adapter true)

#  # description: Component codec adapters for multi codec
#  set(CONFIG_USE_component_codec_adapters true)

#  # description: Component cs42448 adapter for single codec
#  set(CONFIG_USE_component_cs42448_adapter true)

#  # description: Component cs42888 adapter for single codec
#  set(CONFIG_USE_component_cs42888_adapter true)

#  # description: Component da7212 adapter for single codec
#  set(CONFIG_USE_component_da7212_adapter true)

#  # description: Component pcm186x adapter for single codec
#  set(CONFIG_USE_component_pcm186x_adapter true)

#  # description: Component pcm512x adapter for single codec
#  set(CONFIG_USE_component_pcm512x_adapter true)

#  # description: Component sgtl5000 adapter for single codec
#  set(CONFIG_USE_component_sgtl_adapter true)

#  # description: Component tfa9896 adapter for single codec
#  set(CONFIG_USE_component_tfa9896_adapter true)

#  # description: Component tfa9xxx adapter for single codec
#  set(CONFIG_USE_component_tfa9xxx_adapter true)

#  # description: Component wm8524 adapter for single codec
#  set(CONFIG_USE_component_wm8524_adapter true)

#  # description: Component wm8904 adapter for single codec
#  set(CONFIG_USE_component_wm8904_adapter true)

#  # description: Component wm8960 adapter for single codecs
#  set(CONFIG_USE_component_wm8960_adapter true)

#  # description: Component wm8962 adapter for single codecs
#  set(CONFIG_USE_component_wm8962_adapter true)

#  # description: Driver codec
#  set(CONFIG_USE_driver_codec true)

#  # description: TRDC Driver
#  set(CONFIG_USE_driver_trdc_1 true)

#  # description: POWER SOC Driver
#  set(CONFIG_USE_driver_power true)

#  # description: IOMUXC Driver
#  set(CONFIG_USE_driver_iomuxc true)

#  # description: VBATCON SOC Driver
#  set(CONFIG_USE_driver_vbatcon true)

#  # description: MEMCON SOC Driver
#  set(CONFIG_USE_driver_memcon true)

#  # description: RESETCON SOC Driver
#  set(CONFIG_USE_driver_resetcon true)

#  # description: MCM SOC Driver
#  set(CONFIG_USE_driver_mcm true)

#  # description: Device MIMXRT2663_cmsis
#  set(CONFIG_USE_device_CMSIS true)

#  # description: Device MIMXRT2663_system
#  set(CONFIG_USE_device_system true)

#  # description: Device MIMXRT2663_startup
#  set(CONFIG_USE_device_startup true)

#  # description: Utility str
#  set(CONFIG_USE_utility_str true)

#  # description: Utility debug_console_lite
#  set(CONFIG_USE_utility_debug_console_lite true)

#  # description: Utility debug_console
#  set(CONFIG_USE_utility_debug_console true)

#  # description: Utility debug_console Template Config
#  set(CONFIG_USE_utility_debug_console_template_config true)

#  # description: Utility assert
#  set(CONFIG_USE_utility_assert true)

#  # description: Utility assert_lite
#  set(CONFIG_USE_utility_assert_lite true)

#  # description: LPUART Freertos Driver
#  set(CONFIG_USE_driver_lpuart_freertos true)

#  # description: LPSPI FreeRTOS Driver
#  set(CONFIG_USE_driver_lpspi_freertos true)

#  # description: LPI2C FreeRTOS Driver
#  set(CONFIG_USE_driver_lpi2c_freertos true)

#  # description: IRTC Driver
#  set(CONFIG_USE_driver_irtc true)

#  # description: RT2K_PMU Driver
#  set(CONFIG_USE_driver_rt2k_pmu true)

#  # description: POWERCON Driver
#  set(CONFIG_USE_driver_powercon true)

#  # description: SINC Driver
#  set(CONFIG_USE_driver_sinc true)

#  # description: TPM Driver
#  set(CONFIG_USE_driver_tpm true)

#  # description: MMU Driver
#  set(CONFIG_USE_driver_mmu true)

#  # description: LPADC Driver
#  set(CONFIG_USE_driver_lpadc true)

#  # description: EVTG Driver
#  set(CONFIG_USE_driver_evtg true)

#  # description: EQDC Driver
#  set(CONFIG_USE_driver_eqdc true)

#  # description: DAC Driver
#  set(CONFIG_USE_driver_dac_1 true)

#  # description: asrc Driver
#  set(CONFIG_USE_driver_asrc true)

#  # description: asrc_edma Driver
#  set(CONFIG_USE_driver_asrc_edma true)

#  # description: ACMP Driver
#  set(CONFIG_USE_driver_acmp true)

#  # description: swt Driver
#  set(CONFIG_USE_driver_swt true)

#  # description: stm Driver
#  set(CONFIG_USE_driver_stm true)

#  # description: XBAR Driver
#  set(CONFIG_USE_driver_xbar_1 true)

#  # description: USDHC Driver
#  set(CONFIG_USE_driver_usdhc true)

#  # description: TRGSYNC Driver
#  set(CONFIG_USE_driver_trgsync true)

#  # description: TENBASET_PHY Driver
#  set(CONFIG_USE_driver_tenbaset_phy true)

#  # description: SRAMCTL Driver
#  set(CONFIG_USE_driver_sramctl true)

#  # description: SAI Driver
#  set(CONFIG_USE_driver_sai true)

#  # description: SAI EDMA Driver
#  set(CONFIG_USE_driver_sai_edma true)

#  # description: S3MU Driver
#  set(CONFIG_USE_driver_s3mu true)

#  # description: REFORMATTER Driver
#  set(CONFIG_USE_driver_reformatter true)

#  # description: QTMR Driver
#  set(CONFIG_USE_driver_qtmr_1 true)

#  # description: FlexPWM Driver
#  set(CONFIG_USE_driver_flexpwm true)

#  # description: pdcon Driver
#  set(CONFIG_USE_driver_pdcon true)

#  # description: MIPI DSI Driver
#  set(CONFIG_USE_driver_mipi_dsi_split_1 true)

#  # description: MIPI CSI2RX RAMBUS Driver
#  set(CONFIG_USE_driver_mipi_csi2rx_rambus true)

#  # description: LPUART Driver
#  set(CONFIG_USE_driver_lpuart true)

#  # description: LPUART Driver
#  set(CONFIG_USE_driver_lpuart_edma true)

#  # description: LPTMR Driver
#  set(CONFIG_USE_driver_lptmr true)

#  # description: LPSPI Driver
#  set(CONFIG_USE_driver_lpspi true)

#  # description: LPSPI Driver
#  set(CONFIG_USE_driver_lpspi_edma true)

#  # description: LPIT Driver
#  set(CONFIG_USE_driver_lpit true)

#  # description: LPI2C Driver
#  set(CONFIG_USE_driver_lpi2c true)

#  # description: LPI2C Driver
#  set(CONFIG_USE_driver_lpi2c_edma true)

#  # description: lpc_freqme Driver
#  set(CONFIG_USE_driver_lpc_freqme true)

#  # description: JPEG decoder Driver
#  set(CONFIG_USE_driver_jpegdec true)

#  # description: INPUTMUX Driver
#  set(CONFIG_USE_driver_inputmux true)

#  # description: I3C Driver
#  set(CONFIG_USE_driver_i3c true)

#  # description: I3C EDMA Driver
#  set(CONFIG_USE_driver_i3c_edma true)

#  # description: ISI Driver
#  set(CONFIG_USE_driver_isi true)

#  # description: GPIO Driver
#  set(CONFIG_USE_driver_gpio true)

#  # description: XSPI Driver
#  set(CONFIG_USE_driver_xspi true)

#  # description: XSPI EDMA Driver
#  set(CONFIG_USE_driver_xspi_edma true)

#  # description: FLEXIO UART Driver
#  set(CONFIG_USE_driver_flexio_uart true)

#  # description: FLEXIO UART EDMA Driver
#  set(CONFIG_USE_driver_flexio_uart_edma true)

#  # description: FLEXIO SPI Driver
#  set(CONFIG_USE_driver_flexio_spi true)

#  # description: FLEXIO SPI EDMA Driver
#  set(CONFIG_USE_driver_flexio_spi_edma true)

#  # description: FLEXIO I2S Driver
#  set(CONFIG_USE_driver_flexio_i2s true)

#  # description: FLEXIO I2S EDMA Driver
#  set(CONFIG_USE_driver_flexio_i2s_edma true)

#  # description: FLEXIO I2C Driver
#  set(CONFIG_USE_driver_flexio_i2c_master true)

#  # description: FLEXIO Driver
#  set(CONFIG_USE_driver_flexio true)

#  # description: FLEXCAN Driver
#  set(CONFIG_USE_driver_flexcan true)

#  # description: FLEXCAN Driver
#  set(CONFIG_USE_driver_flexcan_edma true)

#  # description: EWM Driver
#  set(CONFIG_USE_driver_ewm true)

#  # description: ENET QoS Driver
#  set(CONFIG_USE_driver_enet_qos true)

#  # description: ENET Driver
#  set(CONFIG_USE_driver_enet true)

#  # description: EDMA Driver
#  set(CONFIG_USE_driver_edma_unified true)

#  # description: DCIF Driver
#  set(CONFIG_USE_driver_dcif_1 true)

#  # description: CSI Driver
#  set(CONFIG_USE_driver_csi true)

#  # description: CRC Driver
#  set(CONFIG_USE_driver_crc true)

#  # description: Last Level Cache Driver
#  set(CONFIG_USE_driver_cache_llc true)

#  # description: CACHE Driver
#  set(CONFIG_USE_driver_cache_armv7_m7 true)

#  # description: LPUART CMSIS Driver
#  set(CONFIG_USE_driver_cmsis_lpuart true)

#  # description: LPSPI CMSIS Driver
#  set(CONFIG_USE_driver_cmsis_lpspi true)

#  # description: LPI2C CMSIS Driver
#  set(CONFIG_USE_driver_cmsis_lpi2c true)

#  # description: ENET PHY CMSIS Driver
#  set(CONFIG_USE_driver_cmsis_enet_phy true)

#  # description: ENET CMSIS Driver
#  set(CONFIG_USE_driver_cmsis_enet true)

#  # description: Wi-Fi and BT module configs
#  set(CONFIG_USE_component_wifi_bt_module_config true)

#  # description: RW61X Wi-Fi
#  set(CONFIG_USE_component_wifi_bt_module_RW61X true)

#  # description: 88W8987 Wi-Fi
#  set(CONFIG_USE_component_wifi_bt_module_88W8987 true)

#  # description: IW416 Wi-Fi
#  set(CONFIG_USE_component_wifi_bt_module_IW416 true)

#  # description: IW61X Wi-Fi
#  set(CONFIG_USE_component_wifi_bt_module_IW61X true)

#  # description: RD-RW61X Wi-Fi board
#  set(CONFIG_USE_component_wifi_bt_module_board_rd_rw61x true)

#  # description: FRDM-RW61X Wi-Fi board
#  set(CONFIG_USE_component_wifi_bt_module_board_frdm_rw61x true)

#  # description: AW-CM358MA-M2 Wi-Fi board
#  set(CONFIG_USE_component_wifi_bt_module_board_aw_cm358ma true)

#  # description: AW-CM358-USD Wi-Fi board
#  set(CONFIG_USE_component_wifi_bt_module_board_aw_cm358_usd true)

#  # description: MURATA-1ZM-M2 Wi-Fi board
#  set(CONFIG_USE_component_wifi_bt_module_board_murata_1zm_m2 true)

#  # description: MURATA-1ZM-USD Wi-Fi board
#  set(CONFIG_USE_component_wifi_bt_module_board_murata_1zm_usd true)

#  # description: UBX-JODY-W2-USD Wi-Fi board
#  set(CONFIG_USE_component_wifi_bt_module_board_ubx_jody_w2_usd true)

#  # description: UBX-JODY-W5-M2 Wi-Fi board
#  set(CONFIG_USE_component_wifi_bt_module_board_ubx_jody_w5_m2 true)

#  # description: UBX-JODY-W5-USD Wi-Fi board
#  set(CONFIG_USE_component_wifi_bt_module_board_ubx_jody_w5_usd true)

#  # description: IW416-AW-AM457MA-M2 Wi-Fi board
#  set(CONFIG_USE_component_wifi_bt_module_board_aw_am457ma true)

#  # description: IW416-AW-AM457-USD Wi-Fi board
#  set(CONFIG_USE_component_wifi_bt_module_board_aw_am457_usd true)

#  # description: IW416-AW-AM510-M2 Wi-Fi board
#  set(CONFIG_USE_component_wifi_bt_module_board_aw_am510ma true)

#  # description: IW416-AW-AM510-USD Wi-Fi board
#  set(CONFIG_USE_component_wifi_bt_module_board_aw_am510_usd true)

#  # description: FRDM-IW416-AW-AM510 Wi-Fi board
#  set(CONFIG_USE_component_wifi_bt_module_board_aw_am510_arduino true)

#  # description: IW416-MURATA-1XK-M2 Wi-Fi board
#  set(CONFIG_USE_component_wifi_bt_module_board_murata_1xk_m2 true)

#  # description: IW416-MURATA-1XK-USD Wi-Fi board
#  set(CONFIG_USE_component_wifi_bt_module_board_murata_1xk_usd true)

#  # description: UBX-MAYA-W1-USD Wi-Fi board
#  set(CONFIG_USE_component_wifi_bt_module_board_ubx_maya_w1_usd true)

#  # description: IW611-MURATA-2DL-M2 Wi-Fi board
#  set(CONFIG_USE_component_wifi_bt_module_board_murata_2dl_m2 true)

#  # description: IW611-MURATA-2DL-USD Wi-Fi board
#  set(CONFIG_USE_component_wifi_bt_module_board_murata_2dl_usd true)

#  # description: IW612-MURATA-2EL-M2 Wi-Fi board
#  set(CONFIG_USE_component_wifi_bt_module_board_murata_2el_m2 true)

#  # description: IW612-MURATA-2EL-USD Wi-Fi board
#  set(CONFIG_USE_component_wifi_bt_module_board_murata_2el_usd true)

#  # description: UBX-MAYA-W276 Wi-Fi board
#  set(CONFIG_USE_component_wifi_bt_module_board_ubx_maya_w276 true)

#  # description: QUECTEL-FGS060N Wi-Fi board
#  set(CONFIG_USE_component_wifi_bt_module_board_quectel_fgs060n true)

#  # description: IW610-MURATA-2LL-M2 Wi-Fi board
#  set(CONFIG_USE_component_wifi_bt_module_board_murata_2ll_m2 true)

#  # description: IW610-MURATA-2LL-USD Wi-Fi board
#  set(CONFIG_USE_component_wifi_bt_module_board_murata_2ll_usd true)

#  # description: Driver camera-common
#  set(CONFIG_USE_driver_camera-common true)

#  # description: Driver camera-device-ap1302
#  set(CONFIG_USE_driver_camera-device-ap1302 true)

#  # description: Driver camera-device-common
#  set(CONFIG_USE_driver_camera-device-common true)

#  # description: Driver camera-device-max9286
#  set(CONFIG_USE_driver_camera-device-max9286 true)

#  # description: Driver camera-device-mt9m114
#  set(CONFIG_USE_driver_camera-device-mt9m114 true)

#  # description: Driver camera-device-ov5640
#  set(CONFIG_USE_driver_camera-device-ov5640 true)

#  # description: Driver camera-device-ov7670
#  set(CONFIG_USE_driver_camera-device-ov7670 true)

#  # description: Driver camera-device-ov7725
#  set(CONFIG_USE_driver_camera-device-ov7725 true)

#  # description: Driver camera-device-sccb
#  set(CONFIG_USE_driver_camera-device-sccb true)

#  # description: Driver camera-receiver-common
#  set(CONFIG_USE_driver_camera-receiver-common true)

#  # description: Driver camera-receiver-csi
#  set(CONFIG_USE_driver_camera-receiver-csi true)

#  # description: Driver camera-receiver-isi
#  set(CONFIG_USE_driver_camera-receiver-isi true)

#  # description: Driver dbi
#  set(CONFIG_USE_driver_dbi true)

#  # description: Driver dbi_dcif
#  set(CONFIG_USE_driver_dbi_dcif true)

#  # description: Driver dc-fb-common
#  set(CONFIG_USE_driver_dc-fb-common true)

#  # description: Driver dc-fb-dbi
#  set(CONFIG_USE_driver_dc-fb-dbi true)

#  # description: Driver dc-fb-dsi-cmd
#  set(CONFIG_USE_driver_dc-fb-dsi-cmd true)

#  # description: Driver dc-fb-dcif_1
#  set(CONFIG_USE_driver_dc-fb-dcif_1 true)

#  # description: Driver dc-fb-ssd1963
#  set(CONFIG_USE_driver_dc-fb-ssd1963 true)

#  # description: Driver display-adv7535
#  set(CONFIG_USE_driver_display-adv7535 true)

#  # description: Driver display-sn65dsi83
#  set(CONFIG_USE_driver_display-sn65dsi83 true)

#  # description: Driver display-waveshare-dsi2dpi
#  set(CONFIG_USE_driver_display-waveshare-dsi2dpi true)

#  # description: Driver display-common
#  set(CONFIG_USE_driver_display-common true)

#  # description: Driver display-hx8394
#  set(CONFIG_USE_driver_display-hx8394 true)

#  # description: Driver display-it6161
#  set(CONFIG_USE_driver_display-it6161 true)

#  # description: Driver display-it6263
#  set(CONFIG_USE_driver_display-it6263 true)

#  # description: Driver display-mipi-dsi-cmd
#  set(CONFIG_USE_driver_display-mipi-dsi-cmd true)

#  # description: Driver display-rm67162
#  set(CONFIG_USE_driver_display-rm67162 true)

#  # description: Driver display-co5300
#  set(CONFIG_USE_driver_display-co5300 true)

#  # description: Driver display-rm67191
#  set(CONFIG_USE_driver_display-rm67191 true)

#  # description: Driver display-rm68191
#  set(CONFIG_USE_driver_display-rm68191 true)

#  # description: Driver display-rm68200
#  set(CONFIG_USE_driver_display-rm68200 true)

#  # description: Driver display-rm692c9
#  set(CONFIG_USE_driver_display-rm692c9 true)

#  # description: Driver display-rpi
#  set(CONFIG_USE_driver_display-rpi true)

#  # description: Driver fbdev
#  set(CONFIG_USE_driver_fbdev true)

#  # description: Driver video-common
#  set(CONFIG_USE_driver_video-common true)

#  # description: Driver video-i2c
#  set(CONFIG_USE_driver_video-i2c true)

#  # description: Component lpuart_adapter
#  set(CONFIG_USE_component_lpuart_adapter true)

#  # description: Driver ft5406_rt
#  set(CONFIG_USE_driver_ft5406_rt true)

#  # description: Driver ft6x06
#  set(CONFIG_USE_driver_ft6x06 true)

#  # description: Component timer_manager
#  set(CONFIG_USE_component_timer_manager true)

#  # description: Component lpit_adapter
#  set(CONFIG_USE_component_lpit_adapter true)

#  # description: Component lptmr_adapter
#  set(CONFIG_USE_component_lptmr_adapter true)

#  # description: Component tpm_adapter
#  set(CONFIG_USE_component_tpm_adapter true)

#  # description: Component lpit time stamp adapter
#  set(CONFIG_USE_component_lpit_time_stamp_adapter true)

#  # description: Component lptmr time stamp adapter
#  set(CONFIG_USE_component_lptmr_time_stamp_adapter true)

#  # description: Component lpspi_adapter
#  set(CONFIG_USE_component_lpspi_adapter true)

#  # description: Driver silicon_id
#  set(CONFIG_USE_component_silicon_id true)

#  # description: Utility shell
#  set(CONFIG_USE_utility_shell true)

#  # description: Component serial_manager
#  set(CONFIG_USE_component_serial_manager true)

#  # description: Component serial_manager_spi
#  set(CONFIG_USE_component_serial_manager_spi true)

#  # description: Component serial_manager_uart
#  set(CONFIG_USE_component_serial_manager_uart true)

#  # description: Component serial_manager_usb_cdc
#  set(CONFIG_USE_component_serial_manager_usb_cdc true)

#  # description: Driver fxas21002cq
#  set(CONFIG_USE_driver_fxas21002cq true)

#  # description: Driver fxls8974cf
#  set(CONFIG_USE_driver_fxls8974cf true)

#  # description: Driver fxos8700cq
#  set(CONFIG_USE_driver_fxos8700cq true)

#  # description: Driver htu21d
#  set(CONFIG_USE_driver_htu21d true)

#  # description: Driver icm42688p
#  set(CONFIG_USE_driver_icm42688p true)

#  # description: Driver lsm6dso
#  set(CONFIG_USE_driver_lsm6dso true)

#  # description: Driver max30101
#  set(CONFIG_USE_driver_max30101 true)

#  # description: Driver mma8451q
#  set(CONFIG_USE_driver_mma8451q true)

#  # description: Driver mma8652fc
#  set(CONFIG_USE_driver_mma8652fc true)

#  # description: Driver nmh1000
#  set(CONFIG_USE_driver_nmh1000 true)

#  # description: Driver p3t1755
#  set(CONFIG_USE_driver_p3t1755 true)

#  # description: Driver tsl2561
#  set(CONFIG_USE_driver_tsl2561 true)

#  # description: SEGGER Real Time Transfer(RTT)
#  set(CONFIG_USE_driver_rtt true)

#  # description: Component rng_adapter_interface
#  set(CONFIG_USE_component_rng_adapter_interface true)

#  # description: Component software_rng_adapter
#  set(CONFIG_USE_component_software_rng_adapter true)

#  # description: Component pwm_tpm_adapter
#  set(CONFIG_USE_component_pwm_tpm_adapter true)

#  # description: Driver pca9420
#  set(CONFIG_USE_driver_pca9420 true)

#  # description: Driver pca9422
#  set(CONFIG_USE_driver_pca9422 true)

#  # description: Driver pf1550
#  set(CONFIG_USE_driver_pf1550 true)

#  # description: Driver pf3000
#  set(CONFIG_USE_driver_pf3000 true)

#  # description: Driver pf5020
#  set(CONFIG_USE_driver_pf5020 true)

#  # description: Driver pf9453
#  set(CONFIG_USE_driver_pf9453 true)

#  # description: Driver phy-common
#  set(CONFIG_USE_component_eth_phy_common true)

#  # description: Driver phy-device-aqr113c
#  set(CONFIG_USE_component_phyaqr113c true)

#  # description: Driver phy-device-ar8031
#  set(CONFIG_USE_component_phyar8031 true)

#  # description: Driver phy-device-dp8384x
#  set(CONFIG_USE_component_phydp8384x true)

#  # description: Driver phy-device-gpy215
#  set(CONFIG_USE_component_phygpy215 true)

#  # description: Driver phy-device-ksz8041
#  set(CONFIG_USE_component_phyksz8041 true)

#  # description: Driver phy-device-ksz8081
#  set(CONFIG_USE_component_phyksz8081 true)

#  # description: Driver phy-device-lan8720a
#  set(CONFIG_USE_component_phylan8720a true)

#  # description: Driver phy-device-lan8741
#  set(CONFIG_USE_component_phylan8741 true)

#  # description: Driver phy-device-rtl8201
#  set(CONFIG_USE_component_phyrtl8201 true)

#  # description: Driver phy-device-rtl8211f
#  set(CONFIG_USE_component_phyrtl8211f true)

#  # description: Driver phy-device-tja1100
#  set(CONFIG_USE_component_phytja1100 true)

#  # description: Driver phy-device-tja1104
#  set(CONFIG_USE_component_phytja1104 true)

#  # description: Driver phy-device-tja1120
#  set(CONFIG_USE_component_phytja1120 true)

#  # description: Driver phy-device-vsc8541
#  set(CONFIG_USE_component_phyvsc8541 true)

#  # description: Driver phy-device-yt8521
#  set(CONFIG_USE_component_phyyt8521 true)

#  # description: Driver phy-device-jl1111
#  set(CONFIG_USE_component_phyjl1111 true)

#  # description: Driver phy-device-tenbaset-phy
#  set(CONFIG_USE_component_phytenbaset true)

#  # description: Component messaging
#  set(CONFIG_USE_component_messaging true)

#  # description: Component mem_manager
#  set(CONFIG_USE_component_mem_manager true)

#  # description: Component mem_manager_legacy
#  set(CONFIG_USE_component_mem_manager_legacy true)

#  # description: Component mem_manager_freertos
#  set(CONFIG_USE_component_mem_manager_freertos true)

#  # description: Component mem_manager_light
#  set(CONFIG_USE_component_mem_manager_light true)

#  # description: Component log
#  set(CONFIG_USE_component_log true)

#  # description: Component log backend debug console
#  set(CONFIG_USE_component_log_backend_debug_console true)

#  # description: Component log backend debug console lite
#  set(CONFIG_USE_component_log_backend_debug_console_lite true)

#  # description: Component log backend ring buffer
#  set(CONFIG_USE_component_log_backend_ringbuffer true)

#  # description: Component lists
#  set(CONFIG_USE_component_lists true)

#  # description: Component led
#  set(CONFIG_USE_component_led true)

#  # description: Component i3c_adapter
#  set(CONFIG_USE_component_i3c_adapter true)

#  # description: Component lpi2c_adapter
#  set(CONFIG_USE_component_lpi2c_adapter true)

#  # description: Component i2c_adapter_interface
#  set(CONFIG_USE_component_i2c_adapter_interface true)

#  # description: Component i2c_mux_pca954x
#  set(CONFIG_USE_component_i2c_mux_pca954x true)

#  # description: Component enable_pca9544
#  set(CONFIG_USE_component_enable_pca9544 true)

#  # description: Component enable_pca9548
#  set(CONFIG_USE_component_enable_pca9548 true)

#  # description: Component at_least_one_i2c_mux_device_enabled
#  set(CONFIG_USE_component_at_least_one_i2c_mux_device_enabled true)

#  # description: Component gpio_adapter
#  set(CONFIG_USE_component_gpio_adapter true)

#  # description: Component flash_nand_xspi
#  set(CONFIG_USE_component_flash_nand_xspi true)

#  # description: Component flash_nor_lpspi
#  set(CONFIG_USE_component_flash_nor_lpspi true)

#  # description: Component flash_nor_xspi
#  set(CONFIG_USE_component_flash_nor_xspi true)

#  # description: mflash onchip
#  set(CONFIG_USE_component_mflash_onchip true)

#  # description: mflash offchip
#  set(CONFIG_USE_component_mflash_offchip true)

#  # description: Component exception_handling_cm7
#  set(CONFIG_USE_component_exception_handling_cm7 true)

#  # description: Driver ili9341
#  set(CONFIG_USE_driver_ili9341 true)

#  # description: Driver psp27801
#  set(CONFIG_USE_driver_psp27801 true)

#  # description: Driver ssd1963
#  set(CONFIG_USE_driver_ssd1963 true)

#  # description: Driver st7796s
#  set(CONFIG_USE_driver_st7796s true)

#  # description: Component crc_adapter
#  set(CONFIG_USE_component_crc_adapter true)

#  # description: Component codec_i2c
#  set(CONFIG_USE_component_codec_i2c true)

#  # description: Driver ak4497
#  set(CONFIG_USE_driver_ak4497 true)

#  # description: Driver cs42448
#  set(CONFIG_USE_driver_cs42448 true)

#  # description: Driver cs42888
#  set(CONFIG_USE_driver_cs42888 true)

#  # description: Driver dialog7212
#  set(CONFIG_USE_driver_dialog7212 true)

#  # description: Driver pcm186x
#  set(CONFIG_USE_driver_pcm186x true)

#  # description: Driver pcm512x
#  set(CONFIG_USE_driver_pcm512x true)

#  # description: Driver sgtl5000
#  set(CONFIG_USE_driver_sgtl5000 true)

#  # description: Driver tfa9896
#  set(CONFIG_USE_driver_tfa9896 true)

#  # description: Driver tfa9xxx
#  set(CONFIG_USE_driver_tfa9xxx true)

#  # description: Driver tfa9xxx_hal
#  set(CONFIG_USE_driver_tfa9xxx_hal true)

#  # description: Driver wm8524
#  set(CONFIG_USE_driver_wm8524 true)

#  # description: Driver wm8904
#  set(CONFIG_USE_driver_wm8904 true)

#  # description: Driver wm8960
#  set(CONFIG_USE_driver_wm8960 true)

#  # description: Driver wm8962
#  set(CONFIG_USE_driver_wm8962 true)

#  # description: Component button
#  set(CONFIG_USE_component_button true)

#  # description: logging, IoT reference common example component
#  set(CONFIG_USE_middleware_iot_reference_logging true)

#  # description: transport_mbedtls, IoT reference common example component
#  set(CONFIG_USE_middleware_iot_reference_transport_mbedtls true)

#  # description: transport_mbedtls3x, IoT reference common example component
#  set(CONFIG_USE_middleware_iot_reference_transport_mbedtls3x true)

#  # description: transport_mbedtls_psa, IoT reference common example component
#  set(CONFIG_USE_middleware_iot_reference_transport_mbedtls_psa true)

#  # description: Component sai_edma_adapter
#  set(CONFIG_USE_component_audio_sai_edma_adapter true)

#set.CMSIS_DSP_Lib
#  # description: CMSIS-DSP Library Header
#  set(CONFIG_USE_CMSIS_DSP_Include true)

#  # description: CMSIS-DSP Library
#  set(CONFIG_USE_CMSIS_DSP_Source true)

#set.CMSIS
#  # description: Device interrupt controller interface
#  set(CONFIG_USE_CMSIS_Device_API_OSTick true)

#  # description: CMSIS-RTOS API for Cortex-M, SC000, and SC300
#  set(CONFIG_USE_CMSIS_Device_API_RTOS2 true)

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

#  # description: Access to #include Driver_GPIO.h file for custom implementation
#  set(CONFIG_USE_CMSIS_Driver_Include_GPIO true)

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

#  # description: Access to #include Driver_USART.h file for custom implementation
#  set(CONFIG_USE_CMSIS_Driver_Include_USART true)

#  # description: Access to #include Driver_USBD.h file for custom implementation
#  set(CONFIG_USE_CMSIS_Driver_Include_USB_Device true)

#  # description: Access to #include Driver_USBH.h file for custom implementation
#  set(CONFIG_USE_CMSIS_Driver_Include_USB_Host true)

#  # description: Access to #include Driver_WiFi.h file
#  set(CONFIG_USE_CMSIS_Driver_Include_WiFi true)

#  # description: CMSIS-NN Library
#  set(CONFIG_USE_CMSIS_NN_Source true)

#  # description: CMSIS-CORE for Cortex-M, ARMv8-M, ARMv8.1-M
#  set(CONFIG_USE_CMSIS_Include_core_cm true)

#  # description: CMSIS-RTOS2 RTX5 for Cortex-M, SC000, C300 and Armv8-M (Library)
#  set(CONFIG_USE_CMSIS_RTOS2_RTX true)

#  # description: CMSIS-RTOS2 RTX5 for Cortex-M, SC000, C300 and Armv8-M (Library)
#  set(CONFIG_USE_CMSIS_RTOS2_RTX_LIB true)

#set.middleware.freertos-kernel
#  # description: Template configuration file to be edited by user. Provides also memory allocator (heap_x), change variant if needed.
#  set(CONFIG_USE_middleware_freertos-kernel_config true)

#  # description: FreeRTOS kernel (NXP integration layer)
#  set(CONFIG_USE_middleware_freertos-kernel true)

#  # description: FreeRTOS cm85 non trustzone port
#  set(CONFIG_USE_middleware_freertos-kernel_cm85_non_trustzone true)

#  # description: FreeRTOS cm85 secure port
#  set(CONFIG_USE_middleware_freertos-kernel_cm85_trustzone_non_secure true)

#  # description: FreeRTOS Secure Context
#  set(CONFIG_USE_middleware_freertos-kernel_cm85_trustzone_secure true)

#  # description: FreeRTOS NXP extension
#  set(CONFIG_USE_middleware_freertos-kernel_extension true)

#  # description: FreeRTOS NXP Newlib Reentrant
#  set(CONFIG_USE_middleware_freertos-kernel_use_newlib_reentrant true)

#  # description: FreeRTOS NXP Picolibc TLS
#  set(CONFIG_USE_middleware_freertos-kernel_use_picolibc_tls true)

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

#  # description: old FreeRTOS MPU wrappers used before V10.6.0
#  set(CONFIG_USE_middleware_freertos-kernel_mpu_wrappers true)

#  # description: new V2 FreeRTOS MPU wrappers introduced in V10.6.0
#  set(CONFIG_USE_middleware_freertos-kernel_mpu_wrappers_v2 true)

#set.middleware.coremqtt
#  # description: Client implementation of the MQTT 3.1.1 specification for embedded devices.
#  set(CONFIG_USE_middleware_freertos_coremqtt true)

#  # description: Template configuration file to be edited by user.
#  set(CONFIG_USE_middleware_freertos_coremqtt_template true)

#set.middleware.corejson
#  # description: A parser strictly enforcing the ECMA-404 JSON standard, suitable for microcontrollers.
#  set(CONFIG_USE_middleware_freertos_corejson true)

#set.middleware.backoffalgorithm
#  # description: Algorithm for calculating exponential backoff with jitter for network retry attempts.
#  set(CONFIG_USE_middleware_freertos_backoffalgorithm true)

#set.middleware.tinycbor
#  # description: Concise Binary Object Representation (CBOR) Library
#  set(CONFIG_USE_middleware_tinycbor true)

#set.middleware.tfm
#  # description: TFM driver header files
#  set(CONFIG_USE_middleware_tfm_driver_headers true)

#  # description: TFM common headers files
#  set(CONFIG_USE_middleware_tfm_common_headers true)

#  # description: TFM Library NV seed in RAM
#  set(CONFIG_USE_middleware_tfm_s_platform_nv_seed true)

#  # description: TFM Flash NAND wrapper use
#  set(CONFIG_USE_middleware_tfm_flash_use_nand_interface true)

#  # description: TFM CMSIS Flash driver
#  set(CONFIG_USE_middleware_tfm_flash_dummy true)

#  # description: TFM CMSIS driver for LPUART based on USART
#  set(CONFIG_USE_middleware_tfm_lpuart true)

#  # description: Enable No flash option for Platform
#  set(CONFIG_USE_middleware_tfm_enable_platform_no_flash true)

#  # description: Enable deterministic ecdsa
#  set(CONFIG_USE_middleware_tfm_enable_deterministic_ecdsa_module true)

#  # description: TFM Load Init Attest Service
#  set(CONFIG_USE_middleware_tfm_s_partition_load_attest true)

#  # description: CQBOR library
#  set(CONFIG_USE_middleware_tfm_qcbor true)

#  # description: CQBOR library tests
#  set(CONFIG_USE_middleware_tfm_qcbor_test true)

#  # description: TFM Secure Storage Service
#  set(CONFIG_USE_middleware_tfm_s_partition_load_ps true)

#  # description: TFM Secure Storage Service
#  set(CONFIG_USE_middleware_tfm_s_partition_ps true)

#  # description: TFM Secure Storage Service
#  set(CONFIG_USE_middleware_tfm_s_test_partition_load_ps_tests true)

#  # description: TFM Secure Storage Service
#  set(CONFIG_USE_middleware_tfm_s_test_partition_ps_tests true)

#  # description: TFM Test Secure Framework
#  set(CONFIG_USE_middleware_tfm_s_test true)

#  # description: TFM Test ITS Secure
#  set(CONFIG_USE_middleware_tfm_s_test_its true)

#  # description: TFM Test Attestation Secure
#  set(CONFIG_USE_middleware_tfm_s_test_attestation true)

#  # description: TFM t_cose sign1 verify
#  set(CONFIG_USE_middleware_tfm_t_cose_sign1_verify true)

#  # description: TFM t_cose mac0 verify
#  set(CONFIG_USE_middleware_tfm_t_cose_mac0_verify true)

#  # description: TFM Test Crypto Secure
#  set(CONFIG_USE_middleware_tfm_s_test_crypto true)

#  # description: TFM Platform test
#  set(CONFIG_USE_middleware_tfm_platform_test true)

#  # description: TFM Test Platform Secure
#  set(CONFIG_USE_middleware_tfm_s_test_platform true)

#  # description: TFM Test IPC Secure
#  set(CONFIG_USE_middleware_tfm_s_test_ipc true)

#  # description: TFM Test ITS Non Secure
#  set(CONFIG_USE_middleware_tfm_ns_test_its true)

#  # description: TFM Test Secure Framework
#  set(CONFIG_USE_middleware_tfm_ns_test_s true)

#  # description: TFM Tests Attestation Non Secure
#  set(CONFIG_USE_middleware_tfmtests_ns_test_attestation true)

#  # description: TFM default test app Non Secure
#  set(CONFIG_USE_middleware_tfm_ns_test_default_app true)

#  # description: PSA Test app for arch-tests
#  set(CONFIG_USE_middleware_tfm_ns_test_psatest_app true)

#  # description: TFM Test Crypto Non Secure
#  set(CONFIG_USE_middleware_tfm_ns_test_crypto true)

#  # description: TFM Test QCBOR Non Secure
#  set(CONFIG_USE_middleware_tfm_ns_test_qcbor true)

#  # description: TFM Test Platform Non Secure
#  set(CONFIG_USE_middleware_tfm_ns_test_platform true)

#  # description: TFM Tests T_COSE Non Secure
#  set(CONFIG_USE_middleware_tfmtests_ns_test_tcose true)

#  # description: TFM Library
#  set(CONFIG_USE_middleware_tfm_s true)

#  # description: TFM Library
#  set(CONFIG_USE_middleware_tfm_s_board true)

#  # description: TFM Large Profile
#  set(CONFIG_USE_middleware_tfm_profile_large_s_configs true)

#  # description: TFM Medium Profile
#  set(CONFIG_USE_middleware_tfm_profile_medium_s_configs true)

#  # description: TFM Small Profile
#  set(CONFIG_USE_middleware_tfm_profile_small_s_configs true)

#  # description: TFM Library
#  set(CONFIG_USE_middleware_tfm_s_platform_default_crypto_keys true)

#  # description: TFM Library
#  set(CONFIG_USE_middleware_tfm_s_platform_default_nv_counter true)

#  # description: TFM Library with no accelerator
#  set(CONFIG_USE_middleware_tfm_s_accelerator true)

#  # description: TFM CMSIS Flash rt700 driver
#  set(CONFIG_USE_middleware_tfm_flash_rt700 true)

#  # description: Enable additional sha algo
#  set(CONFIG_USE_middleware_tfm_profile_medium_additional_sha_algo true)

#  # description: TFM Platform Service
#  set(CONFIG_USE_middleware_tfm_s_platform true)

#  # description: TFM Platform Service for RW61x
#  set(CONFIG_USE_middleware_tfm_s_platform_sp_common true)

#  # description: Enable Crypto Cipher module
#  set(CONFIG_USE_middleware_tfm_enable_crypto_cipher_module true)

#  # description: TFM Crypto clients at secure side
#  set(CONFIG_USE_middleware_tfm_secure_crypto_clients true)

#  # description: TFM Crypto Service
#  set(CONFIG_USE_middleware_tfm_s_crypto true)

#  # description: TFM enable Init Attest
#  set(CONFIG_USE_middleware_tfm_partition_init_attest true)

#  # description: TFM Initial Attestation Service asymmetric
#  set(CONFIG_USE_middleware_tfm_s_initial_attestation_asymmetric true)

#  # description: TFM Initial Attestation Service asymmetric
#  set(CONFIG_USE_middleware_tfm_s_initial_attestation_symmetric true)

#  # description: TFM Initial Attestation Service
#  set(CONFIG_USE_middleware_tfm_s_initial_attestation true)

#  # description: TFM Secure Storage Service
#  set(CONFIG_USE_middleware_tfm_s_protected_storage true)

#  # description: TFM Isolation Level 1
#  set(CONFIG_USE_middleware_tfm_isolation_level_1 true)

#  # description: TFM Isolation Level 2
#  set(CONFIG_USE_middleware_tfm_isolation_level_2 true)

#  # description: TFM Isolation Level 3
#  set(CONFIG_USE_middleware_tfm_isolation_level_3 true)

#  # description: TFM secure isolation 1 base
#  set(CONFIG_USE_middleware_tfm_s_isolation_1 true)

#  # description: TFM secure isolation 1 cfg
#  set(CONFIG_USE_middleware_tfm_s_isolation_1_cfg true)

#  # description: TFM secure isolation 2 base
#  set(CONFIG_USE_middleware_tfm_s_isolation_2 true)

#  # description: TFM secure isolation 2 cfg
#  set(CONFIG_USE_middleware_tfm_s_isolation_2_cfg true)

#  # description: TFM Internal Trusted Storage Service
#  set(CONFIG_USE_middleware_tfm_s_its true)

#  # description: TFM Internal Trusted Storage Service Load Info
#  set(CONFIG_USE_middleware_tfm_s_its_load_info_common true)

#  # description: TFM Non Secure
#  set(CONFIG_USE_middleware_tfm_ns true)

#  # description: TFM Library
#  set(CONFIG_USE_middleware_tfm_ns_board true)

#  # description: TFM Client Large Profile
#  set(CONFIG_USE_middleware_tfm_profile_large_client_configs true)

#  # description: TFM Client Medium Profile
#  set(CONFIG_USE_middleware_tfm_profile_medium_client_configs true)

#  # description: TFM Client Small Profile
#  set(CONFIG_USE_middleware_tfm_profile_small_client_configs true)

#  # description: TFM NS OS wrapper for bare metal
#  set(CONFIG_USE_middleware_tfm_ns_os_wrapper_baremetal true)

#  # description: TFM NS OS wrapper for RTOS
#  set(CONFIG_USE_middleware_tfm_ns_os_wrapper_rtos true)

#  # description: TFM Tests Non Secure
#  set(CONFIG_USE_middleware_tfmtests_ns true)

#  # description: TFM Reg tests on secure area
#  set(CONFIG_USE_middleware_tfm_secure_reg_test_enable true)

#  # description: TFM Framework profile large
#  set(CONFIG_USE_middleware_tfm_profile_large true)

#  # description: TFM Framework profile medium
#  set(CONFIG_USE_middleware_tfm_profile_medium true)

#  # description: TFM Framework profile small
#  set(CONFIG_USE_middleware_tfm_profile_small true)

#  # description: TFM Test Secure Framework profile large
#  set(CONFIG_USE_middleware_tfm_profile_large_s_test_configs true)

#  # description: TFM Test Secure Framework profile medium
#  set(CONFIG_USE_middleware_tfm_profile_medium_s_test_configs true)

#  # description: TFM Test Secure Framework profile small
#  set(CONFIG_USE_middleware_tfm_profile_small_s_test_configs true)

#  # description: TFM Test PS Secure
#  set(CONFIG_USE_middleware_tfm_s_test_protected_storage true)

#  # description: TFM Test Attestation Secure Asymmetric
#  set(CONFIG_USE_middleware_tfm_s_test_attestation_asymmetric true)

#  # description: TFM Test Attestation Secure Symmetric
#  set(CONFIG_USE_middleware_tfm_s_test_attestation_symmetric true)

#  # description: TFM Test IRQ Service
#  set(CONFIG_USE_middleware_tfm_s_test_irq_slih true)

#  # description: TFM Test IRQ Service
#  set(CONFIG_USE_middleware_tfm_s_test_irq_flih true)

#  # description: TFM Test Non Secure Framework
#  set(CONFIG_USE_middleware_tfm_ns_test true)

#  # description: TFM Test Non Secure Framework profile large
#  set(CONFIG_USE_middleware_tfm_profile_large_ns_test_configs true)

#  # description: TFM Test Non Secure Framework profile medium
#  set(CONFIG_USE_middleware_tfm_profile_medium_ns_test_configs true)

#  # description: TFM Test Non Secure Framework profile small
#  set(CONFIG_USE_middleware_tfm_profile_small_ns_test_configs true)

#  # description: TFM Test PS Non Secure
#  set(CONFIG_USE_middleware_tfm_ns_test_ps true)

#  # description: TFM Test Attestation Non Secure asymmetric
#  set(CONFIG_USE_middleware_tfm_ns_test_attestation_asymmetric true)

#  # description: TFM Test Attestation Non Secure asymmetric
#  set(CONFIG_USE_middleware_tfm_ns_test_attestation_symmetric true)

#  # description: TFM Test Attestation Non Secure
#  set(CONFIG_USE_middleware_tfm_ns_test_attestation true)

#  # description: TFM Tests Attestation Non Secure asymmetric
#  set(CONFIG_USE_middleware_tfmtests_ns_test_attestation_asymmetric true)

#  # description: TFM Tests Attestation Non Secure Symmetric
#  set(CONFIG_USE_middleware_tfmtests_ns_test_attestation_symmetric true)

#  # description: TFM Test IPC Non Secure
#  set(CONFIG_USE_middleware_tfm_ns_test_ipc true)

#  # description: TFM Test IRQ SLIH Mode Non Secure
#  set(CONFIG_USE_middleware_tfm_ns_test_irq_slih true)

#  # description: TFM Test IRQ FLIH Mode Non Secure
#  set(CONFIG_USE_middleware_tfm_ns_test_irq_flih true)

#  # description: TFM Test T_COSE Non Secure
#  set(CONFIG_USE_middleware_tfm_ns_test_tcose true)

#set.middleware.psatest
#  # description: PSA Test Suite Crypto Non Secure
#  set(CONFIG_USE_middleware_psatest_ns_crypto true)

#  # description: PSA Suite disable Crypto Cipher
#  set(CONFIG_USE_middleware_psatest_ns_disable_crypto_cipher_module true)

#  # description: PSA Test Suite Initial Attestation Non Secure part 1
#  set(CONFIG_USE_middleware_psatest_ns_t_cose true)

#  # description: PSA Test Suite Protected Storage Non Secure
#  set(CONFIG_USE_middleware_psatest_ns_protected_storage true)

#  # description: PSA Test Suite Internal Trusted Storage Non Secure
#  set(CONFIG_USE_middleware_psatest_ns_internal_trusted_storage true)

#  # description: PSA Test Suite Non Secure
#  set(CONFIG_USE_middleware_psatest_ns true)

#  # description: PSA Test Suite Non Secure target dev_apis
#  set(CONFIG_USE_middleware_psatest_ns_tgt_dev_apis_nxp true)

#  # description: PSA Test Suite Non Secure Large Profile
#  set(CONFIG_USE_middleware_tfm_profile_large_ns_psatest_configs true)

#  # description: PSA Test Suite Non Secure Medium Profile
#  set(CONFIG_USE_middleware_tfm_profile_medium_ns_psatest_configs true)

#  # description: PSA Test Suite Non Secure Small Profile
#  set(CONFIG_USE_middleware_tfm_profile_small_ns_psatest_configs true)

#  # description: PSA Test Suite Initial Attestation Non Secure part 1
#  set(CONFIG_USE_middleware_psatest_ns_initial_attestation true)

#set.middleware.sdmmc
#  # description: Middleware sdmmc common
#  set(CONFIG_USE_middleware_sdmmc_common true)

#  # description: Template configuration file to be edited by user.
#  set(CONFIG_USE_middleware_sdmmc_sdhc_template true)

#  # description: Template configuration file to be edited by user.
#  set(CONFIG_USE_middleware_sdmmc_sdif_template true)

#  # description: Template configuration file to be edited by user.
#  set(CONFIG_USE_middleware_sdmmc_usdhc_template true)

#  # description: Middleware sdmmc osa
#  set(CONFIG_USE_middleware_sdmmc_osa true)

#  # description: Middleware sdmmc sd
#  set(CONFIG_USE_middleware_sdmmc_sd true)

#  # description: Middleware sdmmc mmc
#  set(CONFIG_USE_middleware_sdmmc_mmc true)

#  # description: Middleware sdmmc sdio
#  set(CONFIG_USE_middleware_sdmmc_sdio true)

#  # description: Middleware sdmmc sdspi
#  set(CONFIG_USE_middleware_sdmmc_sdspi true)

#  # description: Middleware sdmmc host usdhc
#  set(CONFIG_USE_middleware_sdmmc_host_usdhc true)

#  # description: Middleware sdmmc host usdhc non_blocking
#  set(CONFIG_USE_middleware_sdmmc_host_usdhc_non_blocking true)

#  # description: Middleware sdmmc host usdhc blocking
#  set(CONFIG_USE_middleware_sdmmc_host_usdhc_blocking true)

#set.middleware.pngdec
#  # description: PNG decoder
#  set(CONFIG_USE_middleware_pngdec true)

#set.middleware.pkcs11
#  # description: Public Key Cryptography Standard #11 defines generic cryptographic token interface.
#  set(CONFIG_USE_middleware_pkcs11 true)

#set.middleware.openh264
#  # description: openh264 api
#  set(CONFIG_USE_middleware_openh264_api true)

#  # description: openh264 common
#  set(CONFIG_USE_middleware_openh264_common true)

#  # description: openh264 procesing
#  set(CONFIG_USE_middleware_openh264_procesing true)

#  # description: openh264 decoder
#  set(CONFIG_USE_middleware_openh264_decoder true)

#  # description: openh264 encoder
#  set(CONFIG_USE_middleware_openh264_encoder true)

#  # description: openh264 files unused by projects
#  set(CONFIG_USE_middleware_openh264_unused_files true)

#set.middleware.mcuboot
#  # description: MCUboot application support layer
#  set(CONFIG_USE_middleware_mcuboot_nxp_app_support true)

#  # description: MCUboot serial recovery (core)
#  set(CONFIG_USE_middleware_mcuboot_boot_serial true)

#  # description: MCUboot Zcbor library
#  set(CONFIG_USE_middleware_mcuboot_zcbor true)

#  # description: mcuboot
#  set(CONFIG_USE_middleware_mcuboot_bootutil true)

#  # description: NXP porting layer for MCUboot's bootutil code
#  set(CONFIG_USE_middleware_mcuboot_nxp_bootutil_port true)

#  # description: Customized MbedTLS configuration headers
#  set(CONFIG_USE_middleware_mcuboot_mbedtls_config true)

#  # description: Configuration headers needed for TinyCrypt backend
#  set(CONFIG_USE_middleware_mcuboot_tinycrypt_config true)

#  # description: MCUboot default stack/heap setup for MbedTLS
#  set(CONFIG_USE_middleware_mcuboot_stack_heap_default_mbedtls true)

#  # description: MCUboot default stack/heap setup for TinyCrypt
#  set(CONFIG_USE_middleware_mcuboot_stack_heap_default_tinycrypt true)

#  # description: MCUboot device flash porting layer
#  set(CONFIG_USE_middleware_mcuboot_bootutil_flashapi_rt true)

#  # description: MCUboot device flash porting layer
#  set(CONFIG_USE_middleware_mcuboot_bootutil_flashapi_mcx true)

#  # description: MCUboot serial recovery support
#  set(CONFIG_USE_middleware_mcuboot_serial_recovery true)

#  # description: TinyCrypt fork in MCUBoot repository
#  set(CONFIG_USE_middleware_mcuboot_tinycrypt true)

#  # description: MCUBoot's subset of MbedTLS for ASN.1 parsing
#  set(CONFIG_USE_middleware_mcuboot_mbedtls-asn1 true)

#set.middleware.mbedtls3x
#  # description: mbedTLS Template with config files.
#  set(CONFIG_USE_middleware_mbedtls3x_template true)

#  # description: mbedTLS port library common files for MCUX
#  set(CONFIG_USE_middleware_mbedtls3x_port_config true)

#  # description: mbedTLS port library common files for MCUX
#  set(CONFIG_USE_middleware_mbedtls3x_port_only_accelerator_config true)

#  # description: mbedTLS port library common files for MCUX
#  set(CONFIG_USE_middleware_mbedtls3x_port_psa_crypto_config true)

#  # description: mbedTLS port library for hw initialization of trng
#  set(CONFIG_USE_middleware_mbedtls3x_port_hw_init true)

#  # description: mbedTLS port library for only_entropy sources
#  set(CONFIG_USE_middleware_mbedtls3x_port_only_entropy true)

#  # description: mbedTLS test suite
#  set(CONFIG_USE_middleware_mbedtls3x_tests true)

#  # description: X.509 test certificates
#  set(CONFIG_USE_middleware_mbedtls3x_tests_certs_only true)

#  # description: mbedTLS crypto library without PSA
#  set(CONFIG_USE_middleware_mbedtls3x_crypto_no_psa true)

#  # description: mbedTLS X.509 library
#  set(CONFIG_USE_middleware_mbedtls3x_x509 true)

#  # description: mbedTLS 3rdparty p256-m
#  set(CONFIG_USE_middleware_mbedtls3x_p256m true)

#  # description: mbedTLS port library for use in TFM NS
#  set(CONFIG_USE_middleware_mbedtls3x_port_tfm true)

#  # description: PSA ITS simulator over stdio files.
#  set(CONFIG_USE_middleware_mbedtls3x_crypto_storage_default true)

#  # description: PSA ITS simulator over objects in RAM.
#  set(CONFIG_USE_middleware_mbedtls3x_crypto_storage_ram true)

#  # description: mbedTLS crypto library
#  set(CONFIG_USE_middleware_mbedtls3x_crypto true)

#  # description: mbedTLS SSL library without PSA
#  set(CONFIG_USE_middleware_mbedtls3x_ssl_no_psa true)

#  # description: mbedTLS SSL library
#  set(CONFIG_USE_middleware_mbedtls3x_ssl true)

#  # description: mbedTLS library v3.x without PSA
#  set(CONFIG_USE_middleware_mbedtls3x_no_psa true)

#  # description: mbedTLS library v3.x
#  set(CONFIG_USE_middleware_mbedtls3x true)

#set.middleware.mbedtls
#  # description: mbedTLS library
#  set(CONFIG_USE_middleware_mbedtls true)

#set.middleware.lvgl
#  # description: lvgl template
#  set(CONFIG_USE_middleware_lvgl_template true)

#  # description: lvgl library
#  set(CONFIG_USE_middleware_lvgl true)

#  # description: LVGL benchmark demo
#  set(CONFIG_USE_middleware_lvgl_demo_benchmark true)

#  # description: LVGL demo common
#  set(CONFIG_USE_middleware_lvgl_demo_common true)

#  # description: LVGL demo transform
#  set(CONFIG_USE_middleware_lvgl_demo_transform true)

#  # description: LVGL demo multilang
#  set(CONFIG_USE_middleware_lvgl_demo_multilang true)

#  # description: LVGL demo flex_layout
#  set(CONFIG_USE_middleware_lvgl_demo_flex_layout true)

#  # description: LVGL demo scroll
#  set(CONFIG_USE_middleware_lvgl_demo_scroll true)

#  # description: LVGL demo music
#  set(CONFIG_USE_middleware_lvgl_demo_music true)

#  # description: LVGL demo keypad_encoder
#  set(CONFIG_USE_middleware_lvgl_demo_keypad_encoder true)

#  # description: LVGL stress demo
#  set(CONFIG_USE_middleware_lvgl_demo_stress true)

#  # description: LVGL widgets demo
#  set(CONFIG_USE_middleware_lvgl_demo_widgets true)

#  # description: LVGL thorvg
#  set(CONFIG_USE_middleware_lvgl_src_libs_thorvg true)

#set.middleware.littlefs
#  # description: littlefs
#  set(CONFIG_USE_middleware_littlefs true)

#  # description: littlefs mflash
#  set(CONFIG_USE_middleware_littlefs_mflash true)

#set.middleware.libjpeg
#  # description: JPEG library
#  set(CONFIG_USE_middleware_libjpeg true)

#  # description: Template configuration file to be edited by user. Users could map the file system functions to the file system they are using.
#  set(CONFIG_USE_middleware_libjpeg_template true)

#set.middleware.fatfs
#  # description: FatFs
#  set(CONFIG_USE_middleware_fatfs true)

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

#  # description: FatFs_MMC
#  set(CONFIG_USE_middleware_fatfs_mmc true)

#  # description: FatFs_NAND
#  set(CONFIG_USE_middleware_fatfs_nand true)

#  # description: FatFs_RAM
#  set(CONFIG_USE_middleware_fatfs_ram true)

#  # description: FatFs_SD
#  set(CONFIG_USE_middleware_fatfs_sd true)

#  # description: FatFs_SDSPI
#  set(CONFIG_USE_middleware_fatfs_sdspi true)

#  # description: FatFs_USB
#  set(CONFIG_USE_middleware_fatfs_usb true)

#set.middleware.eiq
#  # description: ethos-u core software application interface layer
#  set(CONFIG_USE_middleware_eiq_ethosu_application true)

#  # description: ethos-u core software core driver interface layer
#  set(CONFIG_USE_middleware_eiq_ethosu_core_driver true)

#  # description: ExecuTorch library
#  set(CONFIG_USE_middleware_eiq_executorch true)

#  # description: TensorFlow Lite Micro library
#  set(CONFIG_USE_middleware_eiq_tensorflow_lite_micro true)

#  # description: TensorFlow Lite Micro library binary with core specific kernel implementations
#  set(CONFIG_USE_middleware_eiq_tensorflow_lite_micro_refenerce true)

#  # description: General Purpose FFT (Fast Fourier/Cosine/Sine Transform) Package
#  set(CONFIG_USE_middleware_eiq_tensorflow_lite_micro_third_party_fft2d true)

#  # description: Neutron library binary
#  set(CONFIG_USE_middleware_eiq_neutron true)

#  # description: ExecuTorch library binary with core specific kernel implementations
#  set(CONFIG_USE_middleware_eiq_executorch_binary true)

#  # description: ExecuTorch Runtime source code
#  set(CONFIG_USE_middleware_eiq_executorch_source true)

#  # description: TensorFlow Lite Micro library binary with core specific kernel implementations
#  set(CONFIG_USE_middleware_eiq_tensorflow_lite_micro_binary true)

#  # description: TensorFlow Lite Micro library binary with core specific kernel implementations
#  set(CONFIG_USE_middleware_eiq_tensorflow_lite_micro_source true)

#  # description: TensorFlow Lite Micro library binary with core specific kernel implementations
#  set(CONFIG_USE_middleware_eiq_tensorflow_lite_micro_debug_log true)

#  # description: TensorFlow Lite Micro library binary with core specific kernel implementations
#  set(CONFIG_USE_middleware_eiq_tensorflow_lite_micro_library true)

#  # description: TensorFlow Lite Micro library with CMSIS-NN kernel implementations
#  set(CONFIG_USE_middleware_eiq_tensorflow_lite_micro_cmsis_nn true)

#  # description: TensorFlow Lite Micro word detection library
#  set(CONFIG_USE_middleware_eiq_tensorflow_lite_micro_examples_microspeech true)

#  # description: TensorFlow Lite Micro library header files
#  set(CONFIG_USE_middleware_eiq_tensorflow_lite_micro_headers true)

#  # description: Neutron kernel implementations for TensorFlow Lite Micro
#  set(CONFIG_USE_middleware_eiq_tensorflow_lite_micro_neutron true)

#  # description: TensorFlow Lite Micro library with reference kernel implementations
#  set(CONFIG_USE_middleware_eiq_tensorflow_lite_micro_reference true)

#  # description: CMSIS-NN library
#  set(CONFIG_USE_middleware_eiq_tensorflow_lite_micro_third_party_cmsis_nn true)

#set.middleware.dhara
#  # description: Middleware dhara
#  set(CONFIG_USE_middleware_dhara true)

#  # description: Middleware dhara dhara_ecc_bch
#  set(CONFIG_USE_middleware_dhara_dhara_ecc_bch true)

#  # description: Middleware dhara dhara_ecc_hamming
#  set(CONFIG_USE_middleware_dhara_dhara_ecc_hamming true)

#set.middleware.cjson
#  # description: CJSON library
#  set(CONFIG_USE_middleware_cjson true)

#set.component.psa_crypto_driver
#  # description: Common files of PSA crypto driver for ele_s200
#  set(CONFIG_USE_component_psa_crypto_driver_ele_s200_common true)

#  # description: Transparent part of PSA crypto driver for ele_s200
#  set(CONFIG_USE_component_psa_crypto_driver_ele_s200_transparent true)

#  # description: Opaque part of PSA crypto driver for ele_s200
#  set(CONFIG_USE_component_psa_crypto_driver_ele_s200_opaque true)

#  # description: Common files of PSA crypto driver for els_pkc
#  set(CONFIG_USE_component_psa_crypto_driver_els_pkc_common true)

#  # description: Opaque part of PSA crypto driver for els_pkc
#  set(CONFIG_USE_component_psa_crypto_driver_els_pkc_opaque true)

#  # description: RW61x Oracle of PSA crypto driver for els_pkc
#  set(CONFIG_USE_component_psa_crypto_driver_els_pkc_oracle_rw61x true)

#  # description: MIMXRT Oracle of PSA crypto driver for els_pkc
#  set(CONFIG_USE_component_psa_crypto_driver_els_pkc_oracle_mimxrt true)

#  # description: MCXN Oracle of PSA crypto driver for els_pkc
#  set(CONFIG_USE_component_psa_crypto_driver_els_pkc_oracle_mcxn true)

#  # description: LPC Oracle of PSA crypto driver for els_pkc
#  set(CONFIG_USE_component_psa_crypto_driver_els_pkc_oracle_lpc true)

#  # description: Transparent part of PSA crypto driver for els_pkc
#  set(CONFIG_USE_component_psa_crypto_driver_els_pkc_transparent true)

#  # description: PSA crypto driver for SGI
#  set(CONFIG_USE_component_psa_crypto_driver_sgi_common true)

#  # description: PSA crypto driver for SGI
#  set(CONFIG_USE_component_psa_crypto_driver_sgi_transparent true)

#  # description: PSA crypto driver for SGI
#  set(CONFIG_USE_component_psa_crypto_driver_sgi_opaque true)

#  # description: Threading Alt implementation for mbedtls layer via PSA crypto driver
#  set(CONFIG_USE_component_psa_crypto_driver_mbedtls_thread_alt true)

#  # description: OS Abstraction Layer for PSA crypto driver on Zephyr
#  set(CONFIG_USE_component_psa_crypto_driver_osal_zephyr true)

#  # description: psa_crypto_driver_trng usage compile option
#  set(CONFIG_USE_component_psa_crypto_driver_use_trng_compile_option true)

#  # description: PSA crypto driver utility for operation wraparound checks
#  set(CONFIG_USE_component_psa_crypto_driver_util_wrapcheck_static_inline true)

#  # description: PSA crypto driver for ELE S4XX
#  set(CONFIG_USE_component_psa_crypto_driver_ele_s4xx_psa true)

#  # description: PSA Opaque driver wrappers for ELE S4XX opaque
#  set(CONFIG_USE_component_psa_crypto_driver_ele_s4xx_psa_opaque true)

#  # description: Transparent part of PSA crypto driver for ele_s4xx
#  set(CONFIG_USE_component_psa_crypto_driver_ele_s4xx_psa_transparent true)

#  # description: PSA port library for ELE S4xx with only RNG ALT Function
#  set(CONFIG_USE_component_psa_crypto_driver_ele_s4xx_rng true)

#  # description: OS Abstraction Layer for PSA crypto driver
#  set(CONFIG_USE_component_psa_crypto_driver_osal true)

#  # description: OS Abstraction Layer for PSA crypto driver on bare metal
#  set(CONFIG_USE_component_psa_crypto_driver_osal_baremetal true)

#  # description: OS Abstraction Layer for PSA crypto driver on FreeRTOS
#  set(CONFIG_USE_component_psa_crypto_driver_osal_frtos true)

#  # description: Intermediate Kconfig selection symbol for baremetal OSAL
#  set(CONFIG_USE_component_psa_crypto_driver_osal_selection_baremetal true)

#  # description: Intermediate Kconfig selection symbol for FreeRTOS OSAL
#  set(CONFIG_USE_component_psa_crypto_driver_osal_selection_frtos true)

#set.component.osa
#  # description: Component osa template config
#  set(CONFIG_USE_component_osa_template_config true)

#  # description: Component osa
#  set(CONFIG_USE_component_osa true)

#  # description: Component osa_bm
#  set(CONFIG_USE_component_osa_bm true)

#  # description: Component osa_free_rtos
#  set(CONFIG_USE_component_osa_free_rtos true)

#  # description: Component common_task
#  set(CONFIG_USE_component_common_task true)

#set.middleware.freertos_posix
#  # description: FreeRTOS POSIX wrapper (pthread subset)
#  set(CONFIG_USE_middleware_freertos_posix true)

#  # description: FreeRTOS POSIX wrapper (pthread subset)
#  set(CONFIG_USE_middleware_freertos_freertos_posix_upstream true)

#set.middleware.corepkcs11
#  # description: Template configuration file to be edited by user.
#  set(CONFIG_USE_middleware_freertos_corepkcs11_template true)

#  # description: Software implementation of the PKCS #11 standard.
#  set(CONFIG_USE_middleware_freertos_corepkcs11 true)

#  # description: PKCS #11, mbedtls port.
#  set(CONFIG_USE_middleware_freertos_corepkcs11_mbedtls true)

#  # description: PKCS #11, mbedtls_utils
#  set(CONFIG_USE_middleware_freertos_corepkcs11_mbedtls_utils true)

#set.middleware.corehttp
#  # description: Client implementation of the HTTP/1.1 specification for embedded devices.
#  set(CONFIG_USE_middleware_freertos_corehttp true)

#set.middleware.usb_pd
#  # description: Middleware usb_pd
#  set(CONFIG_USE_middleware_usb_pd true)

#  # description: Middleware usb_pd altmode
#  set(CONFIG_USE_middleware_usb_pd_altmode true)

#  # description: Middleware usb_pd phy ptn5110
#  set(CONFIG_USE_middleware_usb_pd_phy_ptn5110 true)

#  # description: USB Type-C PD Stack
#  set(CONFIG_USE_middleware_usb_pd_config_header true)

#  # description: Middleware usb_pd compliance_test_report
#  set(CONFIG_USE_middleware_usb_pd_compliance_test_report true)

#set.middleware.usb
#  # description: Middleware usb common_header
#  set(CONFIG_USE_middleware_usb_common_header true)

#  # description: Middleware usb device common_header
#  set(CONFIG_USE_middleware_usb_device_common_header true)

#  # description: Middleware usb device khci
#  set(CONFIG_USE_middleware_usb_device_khci true)

#  # description: USB device khci config header
#  set(CONFIG_USE_middleware_usb_device_khci_config_header true)

#  # description: Middleware usb device ehci
#  set(CONFIG_USE_middleware_usb_device_ehci true)

#  # description: USB device ehci config header
#  set(CONFIG_USE_middleware_usb_device_ehci_config_header true)

#  # description: Middleware usb device controller driver
#  set(CONFIG_USE_middleware_usb_device_controller_driver true)

#  # description: Middleware usb device stack
#  set(CONFIG_USE_middleware_usb_device_stack true)

#  # description: Middleware usb device audio
#  set(CONFIG_USE_middleware_usb_device_audio true)

#  # description: Middleware usb device cdc
#  set(CONFIG_USE_middleware_usb_device_cdc true)

#  # description: Middleware usb device cdc ecm
#  set(CONFIG_USE_middleware_usb_device_cdc_ecm true)

#  # description: Middleware usb device cdc rndis
#  set(CONFIG_USE_middleware_usb_device_cdc_rndis true)

#  # description: Middleware usb device hid
#  set(CONFIG_USE_middleware_usb_device_hid true)

#  # description: Middleware usb device dfu
#  set(CONFIG_USE_middleware_usb_device_dfu true)

#  # description: Middleware usb device msd
#  set(CONFIG_USE_middleware_usb_device_msd true)

#  # description: Middleware usb device mtp
#  set(CONFIG_USE_middleware_usb_device_mtp true)

#  # description: Middleware usb device phdc
#  set(CONFIG_USE_middleware_usb_device_phdc true)

#  # description: Middleware usb device video
#  set(CONFIG_USE_middleware_usb_device_video true)

#  # description: Middleware usb device ccid
#  set(CONFIG_USE_middleware_usb_device_ccid true)

#  # description: Middleware usb device printer
#  set(CONFIG_USE_middleware_usb_device_printer true)

#  # description: Middleware usb phy
#  set(CONFIG_USE_middleware_usb_phy true)

#  # description: Middleware usb HSDCD (Select manually if needed)
#  set(CONFIG_USE_middleware_usb_hsdcd true)

#  # description: USB device hsdcd config header
#  set(CONFIG_USE_middleware_usb_hsdcd_config_header true)

#  # description: Middleware usb host common_header
#  set(CONFIG_USE_middleware_usb_host_common_header true)

#  # description: Middleware usb host khci
#  set(CONFIG_USE_middleware_usb_host_khci true)

#  # description: USB host khci config header
#  set(CONFIG_USE_middleware_usb_host_khci_config_header true)

#  # description: Middleware usb host ehci
#  set(CONFIG_USE_middleware_usb_host_ehci true)

#  # description: USB host ehci config header
#  set(CONFIG_USE_middleware_usb_host_ehci_config_header true)

#  # description: Middleware usb host stack
#  set(CONFIG_USE_middleware_usb_host_stack true)

#  # description: Middleware usb host audio
#  set(CONFIG_USE_middleware_usb_host_audio true)

#  # description: Middleware usb host cdc
#  set(CONFIG_USE_middleware_usb_host_cdc true)

#  # description: Middleware usb host cdc_ecm
#  set(CONFIG_USE_middleware_usb_host_cdc_ecm true)

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

#set.middleware.lwip
#  # description: lwIP - A Lightweight TCP/IP Stack
#  set(CONFIG_USE_middleware_lwip true)

#  # description: lwIP ALTCP TLS layer
#  set(CONFIG_USE_middleware_lwip_apps_altcp_tls true)

#  # description: lwIP HTTP Daemon
#  set(CONFIG_USE_middleware_lwip_apps_httpd true)

#  # description: lwIP HTTP Daemon Implementation Support Files
#  set(CONFIG_USE_middleware_lwip_apps_httpd_support true)

#  # description: lwIP HTTP Server Implementation
#  set(CONFIG_USE_middleware_lwip_apps_httpsrv true)

#  # description: lwIP HTTPS Server Implementation
#  set(CONFIG_USE_middleware_lwip_apps_httpssrv true)

#  # description: lwIP IPERF Implementation
#  set(CONFIG_USE_middleware_lwip_apps_lwiperf true)

#  # description: lwIP IPERF Implementation non_generated_lwipopts
#  set(CONFIG_USE_middleware_lwip_apps_lwiperf_non_generated_lwipopts true)

#  # description: lwIP mDNS Implementation
#  set(CONFIG_USE_middleware_lwip_apps_mdns true)

#  # description: lwIP MQTT Client
#  set(CONFIG_USE_middleware_lwip_apps_mqtt true)

#  # description: lwIP SNTP
#  set(CONFIG_USE_middleware_lwip_apps_sntp true)

#  # description: lwIP Ping Sender contrib
#  set(CONFIG_USE_middleware_lwip_contrib_ping true)

#  # description: lwIP TCP Echo contrib
#  set(CONFIG_USE_middleware_lwip_contrib_tcpecho true)

#  # description: lwIP TCP Echo Raw API contrib
#  set(CONFIG_USE_middleware_lwip_contrib_tcpecho_raw true)

#  # description: lwIP UDP Echo contrib
#  set(CONFIG_USE_middleware_lwip_contrib_udpecho true)

#  # description: lwIP UDP Echo Raw API contrib
#  set(CONFIG_USE_middleware_lwip_contrib_udpecho_raw true)

#  # description: Empty ethernet interface
#  set(CONFIG_USE_middleware_lwip_empty_ethernetif true)

#  # description: Enet ethernet interface
#  set(CONFIG_USE_middleware_lwip_enet_ethernetif true)

#  # description: Enet ethernet interface non_generated_lwipopts
#  set(CONFIG_USE_middleware_lwip_enet_ethernetif_non_generated_lwipopts true)

#  # description: EtherCAT EOE ethernet interface
#  set(CONFIG_USE_middleware_lwip_eoe_ethernetif true)

#  # description: EtherCAT EOE ethernet interface non_generated_lwipopts
#  set(CONFIG_USE_middleware_lwip_eoe_ethernetif_non_generated_lwipopts true)

#  # description: Kinetis ethernet interface
#  set(CONFIG_USE_middleware_lwip_kinetis_ethernetif true)

#  # description: Kinetis ethernet interface non_generated_lwipopts
#  set(CONFIG_USE_middleware_lwip_kinetis_ethernetif_non_generated_lwipopts true)

#  # description: lwIP System Abstraction Layer using either FreeRTOS dynamic memory allocation APIs or bare-metal
#  set(CONFIG_USE_middleware_lwip_sys_arch_dynamic true)

#  # description: lwIP Template
#  set(CONFIG_USE_middleware_lwip_template true)

#  # description: USB network layer
#  set(CONFIG_USE_middleware_lwip_usb_ethernetif true)

#  # description: Baremetal port layer for USB ethernet
#  set(CONFIG_USE_middleware_lwip_usb_ethernetif_bm true)

#  # description: FreeRTOS port layer for USB ethernet
#  set(CONFIG_USE_middleware_lwip_usb_ethernetif_freertos true)

#set.middleware.llhttp
#  # description: HTTP parser in LLVM IR
#  set(CONFIG_USE_middleware_llhttp true)

#set.middleware.fmstr
#  # description: Common FreeMASTER driver code.
#  set(CONFIG_USE_middleware_fmstr true)

#  # description: FreeMASTER driver code for 32bit platforms, enabling communication between FreeMASTER or FreeMASTER Lite tools and MCU application. Supports Serial, CAN, USB and BDM/JTAG physical interface.
#  set(CONFIG_USE_middleware_fmstr_platform_gen32le true)

#  # description: FreeMASTER driver code for DSC platforms, enabling communication between FreeMASTER or FreeMASTER Lite tools and MCU application. Supports Serial, CAN, USB and BDM/JTAG physical interface.
#  set(CONFIG_USE_middleware_fmstr_platform_56f800e true)

#  # description: FreeMASTER driver code for S32 platform.
#  set(CONFIG_USE_middleware_fmstr_platform_s32 true)

#  # description: FreeMASTER driver code for Power Architecture 32bit platform.
#  set(CONFIG_USE_middleware_fmstr_platform_pa32 true)

#  # description: FreeMASTER driver code for S12Z platform.
#  set(CONFIG_USE_middleware_fmstr_platform_s12z true)

#set.component.ele_crypto
#  # description: Component ele_crypto
#  set(CONFIG_USE_component_ele_crypto true)

#  # description: Component ele_nvm_manager
#  set(CONFIG_USE_component_ele_nvm_manager true)

list(APPEND CMAKE_MODULE_PATH
  ${CMAKE_CURRENT_LIST_DIR}/.
  ${CMAKE_CURRENT_LIST_DIR}/../../../../arch/arm/CMSIS/Core/Include
  ${CMAKE_CURRENT_LIST_DIR}/../../../../arch/arm/CMSIS/DSP
  ${CMAKE_CURRENT_LIST_DIR}/../../../../arch/arm/CMSIS/Driver
  ${CMAKE_CURRENT_LIST_DIR}/../../../../arch/arm/CMSIS/NN
  ${CMAKE_CURRENT_LIST_DIR}/../../../../arch/arm/CMSIS/RTOS2
  ${CMAKE_CURRENT_LIST_DIR}/../../../../arch/arm/CMSIS/RTOS2/Include
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/assert
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/audio
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/aws_iot/logging
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/aws_iot/using_mbedtls_pkcs11
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/aws_iot/using_mbedtls_psa
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/button
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/cmsis_drivers/cmsis_enet
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/cmsis_drivers/cmsis_enet_phy
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/cmsis_drivers/cmsis_lpi2c
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/cmsis_drivers/cmsis_lpspi
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/cmsis_drivers/cmsis_lpuart
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/codec
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/codec/ak4497
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/codec/cs42448
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/codec/cs42888
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/codec/da7212
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/codec/i2c
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/codec/pcm186x
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/codec/pcm512x
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/codec/sgtl5000
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/codec/tfa9896
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/codec/tfa9xxx
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/codec/wm8524
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/codec/wm8904
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/codec/wm8960
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/codec/wm8962
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/common_task
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/coremark
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/crc
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/display/ili9341
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/display/psp27801
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/display/ssd1963
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/display/st7796s
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/ele_crypto
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/exception_handling
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/expander/adp5585
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/expander/pca6416a
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/expander/pca9555
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/expander/pcal6408
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/expander/pcal6524
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/expander/pi4io6408
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/flash
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/flash/mflash
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/gpio
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/i2c
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/i2c/muxes
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/led
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/lists
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/log
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/mem_manager
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/messaging
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/misc_utilities
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/mx25r_flash
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/notifier
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/osa
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/panic
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/phy
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/phy/device/phyaqr113c
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/phy/device/phyar8031
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/phy/device/phydp8384x
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/phy/device/phygpy215
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/phy/device/phyjl1111
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/phy/device/phyksz8041
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/phy/device/phyksz8081
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/phy/device/phylan8720a
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/phy/device/phylan8741
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/phy/device/phyrtl8201
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/phy/device/phyrtl8211f
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/phy/device/phytenbaset
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/phy/device/phytja1100
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/phy/device/phytja1104
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/phy/device/phytja1120
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/phy/device/phyvsc8541
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/phy/device/phyyt8521
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/pmic/pca9420
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/pmic/pca9422
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/pmic/pf1550
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/pmic/pf3000
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/pmic/pf5020
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/pmic/pf9453
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/psa_crypto_driver
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/pwm
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/reset
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/rng
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/rtt
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/sensor/fxas21002cq
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/sensor/fxls8974cf
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/sensor/fxos8700cq
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/sensor/htu21d
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/sensor/icm42688p
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/sensor/lsm6dso
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/sensor/max30101
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/sensor/mma8451q
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/sensor/mma8652fc
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/sensor/nmh1000
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/sensor/p3t1755
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/sensor/tsl2561
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/serial_manager
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/shell
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/silicon_id
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/silicon_id/socs/imx8
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/silicon_id/socs/imx93
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/silicon_id/socs/imxrt1170
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/silicon_id/socs/imxrt1180
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/silicon_id/socs/imxrt2660
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/silicon_id/socs/mcxe31x
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/silicon_id/socs/mcxn
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/silicon_id/socs/rt10xx
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/silicon_id/socs/rw610
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/silicon_id/socs/scfw
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/spi
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/time_stamp
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/timer
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/timer_manager
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/touch/ektf2k
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/touch/ft3267
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/touch/ft5406
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/touch/ft5406_rt
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/touch/ft6x06
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/touch/gt911
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/touch/tma525b
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/uart
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/video
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/video/camera
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/video/camera/device
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/video/camera/device/ap1302
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/video/camera/device/max9286
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/video/camera/device/mt9m114
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/video/camera/device/ov5640
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/video/camera/device/ov7670
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/video/camera/device/ov7725
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/video/camera/device/sccb
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/video/camera/receiver
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/video/camera/receiver/csi
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/video/camera/receiver/isi
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/video/display
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/video/display/adv7535
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/video/display/co5300
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/video/display/dbi
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/video/display/dbi/dcif
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/video/display/dc
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/video/display/dc/dbi
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/video/display/dc/dcif_1
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/video/display/dc/dsi_cmd
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/video/display/dc/ssd1963
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/video/display/fbdev
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/video/display/hx8394
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/video/display/it6161
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/video/display/it6263
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/video/display/mipi_dsi_cmd
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/video/display/rm67162
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/video/display/rm67191
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/video/display/rm68191
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/video/display/rm68200
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/video/display/rm692c9
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/video/display/rpi
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/video/display/sn65dsi83
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/video/display/waveshare_dsi2dpi
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/video/i2c
  ${CMAKE_CURRENT_LIST_DIR}/../../../../components/wifi_bt_module
  ${CMAKE_CURRENT_LIST_DIR}/../../../../drivers/acmp
  ${CMAKE_CURRENT_LIST_DIR}/../../../../drivers/asrc
  ${CMAKE_CURRENT_LIST_DIR}/../../../../drivers/cache/armv7-m7
  ${CMAKE_CURRENT_LIST_DIR}/../../../../drivers/cache/llc
  ${CMAKE_CURRENT_LIST_DIR}/../../../../drivers/common
  ${CMAKE_CURRENT_LIST_DIR}/../../../../drivers/crc
  ${CMAKE_CURRENT_LIST_DIR}/../../../../drivers/csi
  ${CMAKE_CURRENT_LIST_DIR}/../../../../drivers/dac_1
  ${CMAKE_CURRENT_LIST_DIR}/../../../../drivers/dcif_1
  ${CMAKE_CURRENT_LIST_DIR}/../../../../drivers/edma_unified
  ${CMAKE_CURRENT_LIST_DIR}/../../../../drivers/enet
  ${CMAKE_CURRENT_LIST_DIR}/../../../../drivers/enet_qos
  ${CMAKE_CURRENT_LIST_DIR}/../../../../drivers/eqdc
  ${CMAKE_CURRENT_LIST_DIR}/../../../../drivers/evtg
  ${CMAKE_CURRENT_LIST_DIR}/../../../../drivers/ewm
  ${CMAKE_CURRENT_LIST_DIR}/../../../../drivers/flexcan
  ${CMAKE_CURRENT_LIST_DIR}/../../../../drivers/flexio
  ${CMAKE_CURRENT_LIST_DIR}/../../../../drivers/flexio/i2c
  ${CMAKE_CURRENT_LIST_DIR}/../../../../drivers/flexio/i2s
  ${CMAKE_CURRENT_LIST_DIR}/../../../../drivers/flexio/spi
  ${CMAKE_CURRENT_LIST_DIR}/../../../../drivers/flexio/uart
  ${CMAKE_CURRENT_LIST_DIR}/../../../../drivers/flexpwm
  ${CMAKE_CURRENT_LIST_DIR}/../../../../drivers/gpio
  ${CMAKE_CURRENT_LIST_DIR}/../../../../drivers/i3c
  ${CMAKE_CURRENT_LIST_DIR}/../../../../drivers/inputmux
  ${CMAKE_CURRENT_LIST_DIR}/../../../../drivers/irtc
  ${CMAKE_CURRENT_LIST_DIR}/../../../../drivers/isi
  ${CMAKE_CURRENT_LIST_DIR}/../../../../drivers/jpegdec
  ${CMAKE_CURRENT_LIST_DIR}/../../../../drivers/lpadc
  ${CMAKE_CURRENT_LIST_DIR}/../../../../drivers/lpc_freqme
  ${CMAKE_CURRENT_LIST_DIR}/../../../../drivers/lpi2c
  ${CMAKE_CURRENT_LIST_DIR}/../../../../drivers/lpit
  ${CMAKE_CURRENT_LIST_DIR}/../../../../drivers/lpspi
  ${CMAKE_CURRENT_LIST_DIR}/../../../../drivers/lptmr
  ${CMAKE_CURRENT_LIST_DIR}/../../../../drivers/lpuart
  ${CMAKE_CURRENT_LIST_DIR}/../../../../drivers/mipi_csi2rx_rambus
  ${CMAKE_CURRENT_LIST_DIR}/../../../../drivers/mipi_dsi_split_1
  ${CMAKE_CURRENT_LIST_DIR}/../../../../drivers/mmu
  ${CMAKE_CURRENT_LIST_DIR}/../../../../drivers/pdcon
  ${CMAKE_CURRENT_LIST_DIR}/../../../../drivers/powercon
  ${CMAKE_CURRENT_LIST_DIR}/../../../../drivers/qtmr_1
  ${CMAKE_CURRENT_LIST_DIR}/../../../../drivers/reformatter
  ${CMAKE_CURRENT_LIST_DIR}/../../../../drivers/rt2k_pmu
  ${CMAKE_CURRENT_LIST_DIR}/../../../../drivers/s3mu
  ${CMAKE_CURRENT_LIST_DIR}/../../../../drivers/sai
  ${CMAKE_CURRENT_LIST_DIR}/../../../../drivers/sinc
  ${CMAKE_CURRENT_LIST_DIR}/../../../../drivers/sramctl
  ${CMAKE_CURRENT_LIST_DIR}/../../../../drivers/stm
  ${CMAKE_CURRENT_LIST_DIR}/../../../../drivers/swt
  ${CMAKE_CURRENT_LIST_DIR}/../../../../drivers/tenbaset_phy
  ${CMAKE_CURRENT_LIST_DIR}/../../../../drivers/tpm
  ${CMAKE_CURRENT_LIST_DIR}/../../../../drivers/trdc_1
  ${CMAKE_CURRENT_LIST_DIR}/../../../../drivers/trgsync
  ${CMAKE_CURRENT_LIST_DIR}/../../../../drivers/usdhc
  ${CMAKE_CURRENT_LIST_DIR}/../../../../drivers/xbar_1
  ${CMAKE_CURRENT_LIST_DIR}/../../../../drivers/xspi
  ${CMAKE_CURRENT_LIST_DIR}/../../../../examples/_boards/mimxrt2660evk
  ${CMAKE_CURRENT_LIST_DIR}/../../../../examples/_boards/mimxrt2660evk/xip
  ${CMAKE_CURRENT_LIST_DIR}/../../../../examples/lvgl_examples/lvgl_sdk
  ${CMAKE_CURRENT_LIST_DIR}/../../../../middleware/bm
  ${CMAKE_CURRENT_LIST_DIR}/../../../../middleware/cjson
  ${CMAKE_CURRENT_LIST_DIR}/../../../../middleware/dhara
  ${CMAKE_CURRENT_LIST_DIR}/../../../../middleware/eiq
  ${CMAKE_CURRENT_LIST_DIR}/../../../../middleware/eiq/ethos-u-core-software
  ${CMAKE_CURRENT_LIST_DIR}/../../../../middleware/eiq/executorch
  ${CMAKE_CURRENT_LIST_DIR}/../../../../middleware/eiq/neutron
  ${CMAKE_CURRENT_LIST_DIR}/../../../../middleware/eiq/tensorflow-lite
  ${CMAKE_CURRENT_LIST_DIR}/../../../../middleware/eiq/tensorflow-lite/tensorflow/lite/micro/kernels/neutron
  ${CMAKE_CURRENT_LIST_DIR}/../../../../middleware/eiq/tensorflow-lite/third_party/cmsis_nn
  ${CMAKE_CURRENT_LIST_DIR}/../../../../middleware/fatfs
  ${CMAKE_CURRENT_LIST_DIR}/../../../../middleware/freemaster
  ${CMAKE_CURRENT_LIST_DIR}/../../../../middleware/freertos_posix
  ${CMAKE_CURRENT_LIST_DIR}/../../../../middleware/libjpeg
  ${CMAKE_CURRENT_LIST_DIR}/../../../../middleware/littlefs
  ${CMAKE_CURRENT_LIST_DIR}/../../../../middleware/llhttp
  ${CMAKE_CURRENT_LIST_DIR}/../../../../middleware/lvgl
  ${CMAKE_CURRENT_LIST_DIR}/../../../../middleware/lvgl/demos
  ${CMAKE_CURRENT_LIST_DIR}/../../../../middleware/lvgl/demos/benchmark
  ${CMAKE_CURRENT_LIST_DIR}/../../../../middleware/lvgl/demos/flex_layout
  ${CMAKE_CURRENT_LIST_DIR}/../../../../middleware/lvgl/demos/keypad_encoder
  ${CMAKE_CURRENT_LIST_DIR}/../../../../middleware/lvgl/demos/multilang
  ${CMAKE_CURRENT_LIST_DIR}/../../../../middleware/lvgl/demos/music
  ${CMAKE_CURRENT_LIST_DIR}/../../../../middleware/lvgl/demos/scroll
  ${CMAKE_CURRENT_LIST_DIR}/../../../../middleware/lvgl/demos/stress
  ${CMAKE_CURRENT_LIST_DIR}/../../../../middleware/lvgl/demos/transform
  ${CMAKE_CURRENT_LIST_DIR}/../../../../middleware/lvgl/demos/widgets
  ${CMAKE_CURRENT_LIST_DIR}/../../../../middleware/lvgl/src/libs/thorvg
  ${CMAKE_CURRENT_LIST_DIR}/../../../../middleware/lwip
  ${CMAKE_CURRENT_LIST_DIR}/../../../../middleware/mbedtls
  ${CMAKE_CURRENT_LIST_DIR}/../../../../middleware/mbedtls3x
  ${CMAKE_CURRENT_LIST_DIR}/../../../../middleware/mcuboot_opensource/boot/boot_serial
  ${CMAKE_CURRENT_LIST_DIR}/../../../../middleware/mcuboot_opensource/boot/bootutil
  ${CMAKE_CURRENT_LIST_DIR}/../../../../middleware/mcuboot_opensource/boot/nxp_mcux_sdk
  ${CMAKE_CURRENT_LIST_DIR}/../../../../middleware/mcuboot_opensource/boot/nxp_mcux_sdk/flashapi
  ${CMAKE_CURRENT_LIST_DIR}/../../../../middleware/mcuboot_opensource/boot/nxp_mcux_sdk/mbedtls_config
  ${CMAKE_CURRENT_LIST_DIR}/../../../../middleware/mcuboot_opensource/boot/nxp_mcux_sdk/serial_recovery
  ${CMAKE_CURRENT_LIST_DIR}/../../../../middleware/mcuboot_opensource/boot/nxp_mcux_sdk/tinycrypt_config
  ${CMAKE_CURRENT_LIST_DIR}/../../../../middleware/mcuboot_opensource/boot/zcbor
  ${CMAKE_CURRENT_LIST_DIR}/../../../../middleware/mcuboot_opensource/ext/mbedtls-asn1
  ${CMAKE_CURRENT_LIST_DIR}/../../../../middleware/mcuboot_opensource/ext/tinycrypt/lib
  ${CMAKE_CURRENT_LIST_DIR}/../../../../middleware/openh264
  ${CMAKE_CURRENT_LIST_DIR}/../../../../middleware/pkcs11
  ${CMAKE_CURRENT_LIST_DIR}/../../../../middleware/pngdec
  ${CMAKE_CURRENT_LIST_DIR}/../../../../middleware/sdmmc
  ${CMAKE_CURRENT_LIST_DIR}/../../../../middleware/tfm/psa-arch-tests/api-tests
  ${CMAKE_CURRENT_LIST_DIR}/../../../../middleware/tfm/qcbor
  ${CMAKE_CURRENT_LIST_DIR}/../../../../middleware/tfm/tf-m
  ${CMAKE_CURRENT_LIST_DIR}/../../../../middleware/tfm/tf-m-tests
  ${CMAKE_CURRENT_LIST_DIR}/../../../../middleware/tinycbor
  ${CMAKE_CURRENT_LIST_DIR}/../../../../middleware/usb
  ${CMAKE_CURRENT_LIST_DIR}/../../../../rtos/freertos/backoffalgorithm
  ${CMAKE_CURRENT_LIST_DIR}/../../../../rtos/freertos/corehttp
  ${CMAKE_CURRENT_LIST_DIR}/../../../../rtos/freertos/corejson
  ${CMAKE_CURRENT_LIST_DIR}/../../../../rtos/freertos/coremqtt
  ${CMAKE_CURRENT_LIST_DIR}/../../../../rtos/freertos/corepkcs11
  ${CMAKE_CURRENT_LIST_DIR}/../../../../rtos/freertos/freertos-drivers/lpi2c
  ${CMAKE_CURRENT_LIST_DIR}/../../../../rtos/freertos/freertos-drivers/lpspi
  ${CMAKE_CURRENT_LIST_DIR}/../../../../rtos/freertos/freertos-drivers/lpuart
  ${CMAKE_CURRENT_LIST_DIR}/../../../../rtos/freertos/freertos-kernel
  ${CMAKE_CURRENT_LIST_DIR}/../../../../rtos/freertos/freertos-kernel-upstream
  ${CMAKE_CURRENT_LIST_DIR}/../../../../rtos/freertos/lab-project-freertos-posix-upstream
  ${CMAKE_CURRENT_LIST_DIR}/../../RT2600/MIMXRT2663/drivers
  ${CMAKE_CURRENT_LIST_DIR}/../../RT2662/MIMXRT2663/drivers
  ${CMAKE_CURRENT_LIST_DIR}/drivers
  ${CMAKE_CURRENT_LIST_DIR}/template
  ${CMAKE_CURRENT_LIST_DIR}/xip
)

include_if_use(CMSIS_DSP_Include)
include_if_use(CMSIS_DSP_Source)
include_if_use(CMSIS_Device_API_OSTick)
include_if_use(CMSIS_Device_API_RTOS2)
include_if_use(CMSIS_Driver_Include_CAN)
include_if_use(CMSIS_Driver_Include_Ethernet)
include_if_use(CMSIS_Driver_Include_Ethernet_MAC)
include_if_use(CMSIS_Driver_Include_Ethernet_PHY)
include_if_use(CMSIS_Driver_Include_Flash)
include_if_use(CMSIS_Driver_Include_GPIO)
include_if_use(CMSIS_Driver_Include_I2C)
include_if_use(CMSIS_Driver_Include_MCI)
include_if_use(CMSIS_Driver_Include_NAND)
include_if_use(CMSIS_Driver_Include_SAI)
include_if_use(CMSIS_Driver_Include_SPI)
include_if_use(CMSIS_Driver_Include_USART)
include_if_use(CMSIS_Driver_Include_USB_Device)
include_if_use(CMSIS_Driver_Include_USB_Host)
include_if_use(CMSIS_Driver_Include_WiFi)
include_if_use(CMSIS_Include_core_cm)
include_if_use(CMSIS_NN_Source)
include_if_use(CMSIS_RTOS2_RTX)
include_if_use(CMSIS_RTOS2_RTX_LIB)
include_if_use(board_boot_header)
include_if_use(component_ak4497_adapter.MIMXRT2663)
include_if_use(component_at_least_one_i2c_mux_device_enabled.MIMXRT2663)
include_if_use(component_audio_sai_edma_adapter.MIMXRT2663)
include_if_use(component_button.MIMXRT2663)
include_if_use(component_codec_adapters.MIMXRT2663)
include_if_use(component_codec_i2c.MIMXRT2663)
include_if_use(component_common_task)
include_if_use(component_coremark.MIMXRT2663)
include_if_use(component_crc_adapter.MIMXRT2663)
include_if_use(component_cs42448_adapter.MIMXRT2663)
include_if_use(component_cs42888_adapter.MIMXRT2663)
include_if_use(component_da7212_adapter.MIMXRT2663)
include_if_use(component_ele_crypto)
include_if_use(component_ele_nvm_manager)
include_if_use(component_enable_pca9544.MIMXRT2663)
include_if_use(component_enable_pca9548.MIMXRT2663)
include_if_use(component_eth_phy_common.MIMXRT2663)
include_if_use(component_exception_handling_cm7.MIMXRT2663)
include_if_use(component_flash_nand_xspi.MIMXRT2663)
include_if_use(component_flash_nor_lpspi.MIMXRT2663)
include_if_use(component_flash_nor_xspi.MIMXRT2663)
include_if_use(component_gpio_adapter.MIMXRT2663)
include_if_use(component_i2c_adapter_interface.MIMXRT2663)
include_if_use(component_i2c_mux_pca954x.MIMXRT2663)
include_if_use(component_i3c_adapter.MIMXRT2663)
include_if_use(component_led.MIMXRT2663)
include_if_use(component_lists.MIMXRT2663)
include_if_use(component_log.MIMXRT2663)
include_if_use(component_log_backend_debug_console.MIMXRT2663)
include_if_use(component_log_backend_debug_console_lite.MIMXRT2663)
include_if_use(component_log_backend_ringbuffer.MIMXRT2663)
include_if_use(component_lpi2c_adapter.MIMXRT2663)
include_if_use(component_lpit_adapter.MIMXRT2663)
include_if_use(component_lpit_time_stamp_adapter.MIMXRT2663)
include_if_use(component_lpspi_adapter.MIMXRT2663)
include_if_use(component_lptmr_adapter.MIMXRT2663)
include_if_use(component_lptmr_time_stamp_adapter.MIMXRT2663)
include_if_use(component_lpuart_adapter.MIMXRT2663)
include_if_use(component_mem_manager.MIMXRT2663)
include_if_use(component_mem_manager_freertos.MIMXRT2663)
include_if_use(component_mem_manager_legacy.MIMXRT2663)
include_if_use(component_mem_manager_light.MIMXRT2663)
include_if_use(component_messaging.MIMXRT2663)
include_if_use(component_mflash_offchip.MIMXRT2663)
include_if_use(component_mflash_onchip.MIMXRT2663)
include_if_use(component_osa)
include_if_use(component_osa_bm)
include_if_use(component_osa_free_rtos)
include_if_use(component_osa_template_config)
include_if_use(component_panic.MIMXRT2663)
include_if_use(component_pcm186x_adapter.MIMXRT2663)
include_if_use(component_pcm512x_adapter.MIMXRT2663)
include_if_use(component_phyaqr113c.MIMXRT2663)
include_if_use(component_phyar8031.MIMXRT2663)
include_if_use(component_phydp8384x.MIMXRT2663)
include_if_use(component_phygpy215.MIMXRT2663)
include_if_use(component_phyjl1111.MIMXRT2663)
include_if_use(component_phyksz8041.MIMXRT2663)
include_if_use(component_phyksz8081.MIMXRT2663)
include_if_use(component_phylan8720a.MIMXRT2663)
include_if_use(component_phylan8741.MIMXRT2663)
include_if_use(component_phyrtl8201.MIMXRT2663)
include_if_use(component_phyrtl8211f.MIMXRT2663)
include_if_use(component_phytenbaset.MIMXRT2663)
include_if_use(component_phytja1100.MIMXRT2663)
include_if_use(component_phytja1104.MIMXRT2663)
include_if_use(component_phytja1120.MIMXRT2663)
include_if_use(component_phyvsc8541.MIMXRT2663)
include_if_use(component_phyyt8521.MIMXRT2663)
include_if_use(component_psa_crypto_driver_ele_s200_common)
include_if_use(component_psa_crypto_driver_ele_s200_opaque)
include_if_use(component_psa_crypto_driver_ele_s200_transparent)
include_if_use(component_psa_crypto_driver_ele_s4xx_psa)
include_if_use(component_psa_crypto_driver_ele_s4xx_psa_opaque)
include_if_use(component_psa_crypto_driver_ele_s4xx_psa_transparent)
include_if_use(component_psa_crypto_driver_ele_s4xx_rng)
include_if_use(component_psa_crypto_driver_els_pkc_common)
include_if_use(component_psa_crypto_driver_els_pkc_opaque)
include_if_use(component_psa_crypto_driver_els_pkc_oracle_lpc)
include_if_use(component_psa_crypto_driver_els_pkc_oracle_mcxn)
include_if_use(component_psa_crypto_driver_els_pkc_oracle_mimxrt)
include_if_use(component_psa_crypto_driver_els_pkc_oracle_rw61x)
include_if_use(component_psa_crypto_driver_els_pkc_transparent)
include_if_use(component_psa_crypto_driver_mbedtls_thread_alt)
include_if_use(component_psa_crypto_driver_osal)
include_if_use(component_psa_crypto_driver_osal_baremetal)
include_if_use(component_psa_crypto_driver_osal_frtos)
include_if_use(component_psa_crypto_driver_osal_selection_baremetal)
include_if_use(component_psa_crypto_driver_osal_selection_frtos)
include_if_use(component_psa_crypto_driver_osal_zephyr)
include_if_use(component_psa_crypto_driver_sgi_common)
include_if_use(component_psa_crypto_driver_sgi_opaque)
include_if_use(component_psa_crypto_driver_sgi_transparent)
include_if_use(component_psa_crypto_driver_use_trng_compile_option)
include_if_use(component_psa_crypto_driver_util_wrapcheck_static_inline)
include_if_use(component_pwm_tpm_adapter.MIMXRT2663)
include_if_use(component_reset_adapter.MIMXRT2663)
include_if_use(component_rng_adapter_interface.MIMXRT2663)
include_if_use(component_rnga_adapter.MIMXRT2663)
include_if_use(component_serial_manager.MIMXRT2663)
include_if_use(component_serial_manager_ble_wu.MIMXRT2663)
include_if_use(component_serial_manager_spi.MIMXRT2663)
include_if_use(component_serial_manager_swo.MIMXRT2663)
include_if_use(component_serial_manager_uart.MIMXRT2663)
include_if_use(component_serial_manager_usb_cdc.MIMXRT2663)
include_if_use(component_serial_manager_virtual.MIMXRT2663)
include_if_use(component_sgtl_adapter.MIMXRT2663)
include_if_use(component_silicon_id.MIMXRT2663)
include_if_use(component_silicon_id_imx8.MIMXRT2663)
include_if_use(component_silicon_id_imx93.MIMXRT2663)
include_if_use(component_silicon_id_imxrt10xx.MIMXRT2663)
include_if_use(component_silicon_id_imxrt1170.MIMXRT2663)
include_if_use(component_silicon_id_imxrt1180.MIMXRT2663)
include_if_use(component_silicon_id_imxrt2660.MIMXRT2663)
include_if_use(component_silicon_id_mcxe31x.MIMXRT2663)
include_if_use(component_silicon_id_mcxn.MIMXRT2663)
include_if_use(component_silicon_id_rw610.MIMXRT2663)
include_if_use(component_silicon_id_scfw.MIMXRT2663)
include_if_use(component_software_crc_adapter.MIMXRT2663)
include_if_use(component_software_rng_adapter.MIMXRT2663)
include_if_use(component_tfa9896_adapter.MIMXRT2663)
include_if_use(component_tfa9xxx_adapter.MIMXRT2663)
include_if_use(component_timer_manager.MIMXRT2663)
include_if_use(component_tpm_adapter.MIMXRT2663)
include_if_use(component_wifi_bt_module_88W8987.MIMXRT2663)
include_if_use(component_wifi_bt_module_IW416.MIMXRT2663)
include_if_use(component_wifi_bt_module_IW61X.MIMXRT2663)
include_if_use(component_wifi_bt_module_RW61X.MIMXRT2663)
include_if_use(component_wifi_bt_module_board_aw_am457_usd.MIMXRT2663)
include_if_use(component_wifi_bt_module_board_aw_am457ma.MIMXRT2663)
include_if_use(component_wifi_bt_module_board_aw_am510_arduino.MIMXRT2663)
include_if_use(component_wifi_bt_module_board_aw_am510_usd.MIMXRT2663)
include_if_use(component_wifi_bt_module_board_aw_am510ma.MIMXRT2663)
include_if_use(component_wifi_bt_module_board_aw_cm358_usd.MIMXRT2663)
include_if_use(component_wifi_bt_module_board_aw_cm358ma.MIMXRT2663)
include_if_use(component_wifi_bt_module_board_frdm_rw61x.MIMXRT2663)
include_if_use(component_wifi_bt_module_board_murata_1xk_m2.MIMXRT2663)
include_if_use(component_wifi_bt_module_board_murata_1xk_usd.MIMXRT2663)
include_if_use(component_wifi_bt_module_board_murata_1zm_m2.MIMXRT2663)
include_if_use(component_wifi_bt_module_board_murata_1zm_usd.MIMXRT2663)
include_if_use(component_wifi_bt_module_board_murata_2dl_m2.MIMXRT2663)
include_if_use(component_wifi_bt_module_board_murata_2dl_usd.MIMXRT2663)
include_if_use(component_wifi_bt_module_board_murata_2el_m2.MIMXRT2663)
include_if_use(component_wifi_bt_module_board_murata_2el_usd.MIMXRT2663)
include_if_use(component_wifi_bt_module_board_murata_2ll_m2.MIMXRT2663)
include_if_use(component_wifi_bt_module_board_murata_2ll_usd.MIMXRT2663)
include_if_use(component_wifi_bt_module_board_quectel_fgs060n.MIMXRT2663)
include_if_use(component_wifi_bt_module_board_rd_rw61x.MIMXRT2663)
include_if_use(component_wifi_bt_module_board_ubx_jody_w2_usd.MIMXRT2663)
include_if_use(component_wifi_bt_module_board_ubx_jody_w5_m2.MIMXRT2663)
include_if_use(component_wifi_bt_module_board_ubx_jody_w5_usd.MIMXRT2663)
include_if_use(component_wifi_bt_module_board_ubx_maya_w1_usd.MIMXRT2663)
include_if_use(component_wifi_bt_module_board_ubx_maya_w276.MIMXRT2663)
include_if_use(component_wifi_bt_module_bt_only_fw.MIMXRT2663)
include_if_use(component_wifi_bt_module_config.MIMXRT2663)
include_if_use(component_wifi_bt_module_frdm_m2_adapter_v1.MIMXRT2663)
include_if_use(component_wifi_bt_module_nb_fw.MIMXRT2663)
include_if_use(component_wifi_bt_module_tx_pwr_limits.MIMXRT2663)
include_if_use(component_wifi_bt_module_uncompressed_firmware.MIMXRT2663)
include_if_use(component_wifi_bt_module_wifi_bt_combo_fw.MIMXRT2663)
include_if_use(component_wifi_bt_module_wifi_fw.MIMXRT2663)
include_if_use(component_wifi_bt_module_wifi_nb_combo_fw.MIMXRT2663)
include_if_use(component_wm8524_adapter.MIMXRT2663)
include_if_use(component_wm8904_adapter.MIMXRT2663)
include_if_use(component_wm8960_adapter.MIMXRT2663)
include_if_use(component_wm8962_adapter.MIMXRT2663)
include_if_use(device_CMSIS.MIMXRT2663)
include_if_use(device_RTE.MIMXRT2663)
include_if_use(device_boot_header.MIMXRT2663)
include_if_use(device_startup.MIMXRT2663)
include_if_use(device_system.MIMXRT2663)
include_if_use(driver_acmp.MIMXRT2663)
include_if_use(driver_adp5585.MIMXRT2663)
include_if_use(driver_ak4497.MIMXRT2663)
include_if_use(driver_asrc.MIMXRT2663)
include_if_use(driver_asrc_edma.MIMXRT2663)
include_if_use(driver_cache_armv7_m7.MIMXRT2663)
include_if_use(driver_cache_llc.MIMXRT2663)
include_if_use(driver_camera-common.MIMXRT2663)
include_if_use(driver_camera-device-ap1302.MIMXRT2663)
include_if_use(driver_camera-device-common.MIMXRT2663)
include_if_use(driver_camera-device-max9286.MIMXRT2663)
include_if_use(driver_camera-device-mt9m114.MIMXRT2663)
include_if_use(driver_camera-device-ov5640.MIMXRT2663)
include_if_use(driver_camera-device-ov7670.MIMXRT2663)
include_if_use(driver_camera-device-ov7725.MIMXRT2663)
include_if_use(driver_camera-device-sccb.MIMXRT2663)
include_if_use(driver_camera-receiver-common.MIMXRT2663)
include_if_use(driver_camera-receiver-csi.MIMXRT2663)
include_if_use(driver_camera-receiver-isi.MIMXRT2663)
include_if_use(driver_clock.MIMXRT2663)
include_if_use(driver_cmsis_enet.MIMXRT2663)
include_if_use(driver_cmsis_enet_phy.MIMXRT2663)
include_if_use(driver_cmsis_lpi2c.MIMXRT2663)
include_if_use(driver_cmsis_lpspi.MIMXRT2663)
include_if_use(driver_cmsis_lpuart.MIMXRT2663)
include_if_use(driver_codec.MIMXRT2663)
include_if_use(driver_common.MIMXRT2663)
include_if_use(driver_crc.MIMXRT2663)
include_if_use(driver_cs42448.MIMXRT2663)
include_if_use(driver_cs42888.MIMXRT2663)
include_if_use(driver_csi.MIMXRT2663)
include_if_use(driver_dac_1.MIMXRT2663)
include_if_use(driver_dbi.MIMXRT2663)
include_if_use(driver_dbi_dcif.MIMXRT2663)
include_if_use(driver_dc-fb-common.MIMXRT2663)
include_if_use(driver_dc-fb-dbi.MIMXRT2663)
include_if_use(driver_dc-fb-dcif_1.MIMXRT2663)
include_if_use(driver_dc-fb-dsi-cmd.MIMXRT2663)
include_if_use(driver_dc-fb-ssd1963.MIMXRT2663)
include_if_use(driver_dcif_1.MIMXRT2663)
include_if_use(driver_dialog7212.MIMXRT2663)
include_if_use(driver_display-adv7535.MIMXRT2663)
include_if_use(driver_display-co5300.MIMXRT2663)
include_if_use(driver_display-common.MIMXRT2663)
include_if_use(driver_display-hx8394.MIMXRT2663)
include_if_use(driver_display-it6161.MIMXRT2663)
include_if_use(driver_display-it6263.MIMXRT2663)
include_if_use(driver_display-mipi-dsi-cmd.MIMXRT2663)
include_if_use(driver_display-rm67162.MIMXRT2663)
include_if_use(driver_display-rm67191.MIMXRT2663)
include_if_use(driver_display-rm68191.MIMXRT2663)
include_if_use(driver_display-rm68200.MIMXRT2663)
include_if_use(driver_display-rm692c9.MIMXRT2663)
include_if_use(driver_display-rpi.MIMXRT2663)
include_if_use(driver_display-sn65dsi83.MIMXRT2663)
include_if_use(driver_display-waveshare-dsi2dpi.MIMXRT2663)
include_if_use(driver_edma4.MIMXRT2663)
include_if_use(driver_edma_soc.MIMXRT2663)
include_if_use(driver_ektf2k.MIMXRT2663)
include_if_use(driver_enet.MIMXRT2663)
include_if_use(driver_enet_qos.MIMXRT2663)
include_if_use(driver_eqdc.MIMXRT2663)
include_if_use(driver_evtg.MIMXRT2663)
include_if_use(driver_ewm.MIMXRT2663)
include_if_use(driver_fbdev.MIMXRT2663)
include_if_use(driver_flexcan.MIMXRT2663)
include_if_use(driver_flexcan_edma.MIMXRT2663)
include_if_use(driver_flexio.MIMXRT2663)
include_if_use(driver_flexio_i2c_master.MIMXRT2663)
include_if_use(driver_flexio_i2s.MIMXRT2663)
include_if_use(driver_flexio_i2s_edma.MIMXRT2663)
include_if_use(driver_flexio_spi.MIMXRT2663)
include_if_use(driver_flexio_spi_edma.MIMXRT2663)
include_if_use(driver_flexio_uart.MIMXRT2663)
include_if_use(driver_flexio_uart_edma.MIMXRT2663)
include_if_use(driver_flexpwm.MIMXRT2663)
include_if_use(driver_ft3267.MIMXRT2663)
include_if_use(driver_ft5406.MIMXRT2663)
include_if_use(driver_ft5406_rt.MIMXRT2663)
include_if_use(driver_ft6x06.MIMXRT2663)
include_if_use(driver_fxas21002cq.MIMXRT2663)
include_if_use(driver_fxls8974cf.MIMXRT2663)
include_if_use(driver_fxos8700cq.MIMXRT2663)
include_if_use(driver_gpio.MIMXRT2663)
include_if_use(driver_gt911.MIMXRT2663)
include_if_use(driver_htu21d.MIMXRT2663)
include_if_use(driver_i3c.MIMXRT2663)
include_if_use(driver_i3c_edma.MIMXRT2663)
include_if_use(driver_icm42688p.MIMXRT2663)
include_if_use(driver_ili9341.MIMXRT2663)
include_if_use(driver_inputmux.MIMXRT2663)
include_if_use(driver_inputmux_connections.MIMXRT2663)
include_if_use(driver_iomuxc.MIMXRT2663)
include_if_use(driver_irtc.MIMXRT2663)
include_if_use(driver_isi.MIMXRT2663)
include_if_use(driver_jpegdec.MIMXRT2663)
include_if_use(driver_lpadc.MIMXRT2663)
include_if_use(driver_lpc_freqme.MIMXRT2663)
include_if_use(driver_lpi2c.MIMXRT2663)
include_if_use(driver_lpi2c_edma.MIMXRT2663)
include_if_use(driver_lpi2c_freertos.MIMXRT2663)
include_if_use(driver_lpit.MIMXRT2663)
include_if_use(driver_lpspi.MIMXRT2663)
include_if_use(driver_lpspi_edma.MIMXRT2663)
include_if_use(driver_lpspi_freertos.MIMXRT2663)
include_if_use(driver_lptmr.MIMXRT2663)
include_if_use(driver_lpuart.MIMXRT2663)
include_if_use(driver_lpuart_edma.MIMXRT2663)
include_if_use(driver_lpuart_freertos.MIMXRT2663)
include_if_use(driver_lsm6dso.MIMXRT2663)
include_if_use(driver_max30101.MIMXRT2663)
include_if_use(driver_mcm.MIMXRT2663)
include_if_use(driver_memcon.MIMXRT2663)
include_if_use(driver_memory.MIMXRT2663)
include_if_use(driver_mipi_csi2rx_rambus.MIMXRT2663)
include_if_use(driver_mipi_dsi_split_1.MIMXRT2663)
include_if_use(driver_mma8451q.MIMXRT2663)
include_if_use(driver_mma8652fc.MIMXRT2663)
include_if_use(driver_mmu.MIMXRT2663)
include_if_use(driver_modcon.MIMXRT2663)
include_if_use(driver_mx25r_flash.MIMXRT2663)
include_if_use(driver_nmh1000.MIMXRT2663)
include_if_use(driver_p3t1755.MIMXRT2663)
include_if_use(driver_pca6416a.MIMXRT2663)
include_if_use(driver_pca9420.MIMXRT2663)
include_if_use(driver_pca9422.MIMXRT2663)
include_if_use(driver_pca9555.MIMXRT2663)
include_if_use(driver_pcal6408.MIMXRT2663)
include_if_use(driver_pcal6524.MIMXRT2663)
include_if_use(driver_pcm186x.MIMXRT2663)
include_if_use(driver_pcm512x.MIMXRT2663)
include_if_use(driver_pdcon.MIMXRT2663)
include_if_use(driver_pf1550.MIMXRT2663)
include_if_use(driver_pf3000.MIMXRT2663)
include_if_use(driver_pf5020.MIMXRT2663)
include_if_use(driver_pf9453.MIMXRT2663)
include_if_use(driver_pi4io6408.MIMXRT2663)
include_if_use(driver_power.MIMXRT2663)
include_if_use(driver_powercon.MIMXRT2663)
include_if_use(driver_psp27801.MIMXRT2663)
include_if_use(driver_qtmr_1.MIMXRT2663)
include_if_use(driver_reformatter.MIMXRT2663)
include_if_use(driver_resetcon.MIMXRT2663)
include_if_use(driver_rt2k_pmu.MIMXRT2663)
include_if_use(driver_rtt.MIMXRT2663)
include_if_use(driver_rtt_template.MIMXRT2663)
include_if_use(driver_s3mu.MIMXRT2663)
include_if_use(driver_sai.MIMXRT2663)
include_if_use(driver_sai_edma.MIMXRT2663)
include_if_use(driver_sgtl5000.MIMXRT2663)
include_if_use(driver_sinc.MIMXRT2663)
include_if_use(driver_soc_mipi_dsi.MIMXRT2663)
include_if_use(driver_sramctl.MIMXRT2663)
include_if_use(driver_ssd1963.MIMXRT2663)
include_if_use(driver_st7796s.MIMXRT2663)
include_if_use(driver_stm.MIMXRT2663)
include_if_use(driver_swt.MIMXRT2663)
include_if_use(driver_tenbaset_phy.MIMXRT2663)
include_if_use(driver_tfa9896.MIMXRT2663)
include_if_use(driver_tfa9xxx.MIMXRT2663)
include_if_use(driver_tfa9xxx_hal.MIMXRT2663)
include_if_use(driver_tma525b.MIMXRT2663)
include_if_use(driver_tpm.MIMXRT2663)
include_if_use(driver_trdc_1.MIMXRT2663)
include_if_use(driver_trdc_soc.MIMXRT2663)
include_if_use(driver_trgsync.MIMXRT2663)
include_if_use(driver_tsl2561.MIMXRT2663)
include_if_use(driver_usdhc.MIMXRT2663)
include_if_use(driver_vbatcon.MIMXRT2663)
include_if_use(driver_video-common.MIMXRT2663)
include_if_use(driver_video-i2c.MIMXRT2663)
include_if_use(driver_wm8524.MIMXRT2663)
include_if_use(driver_wm8904.MIMXRT2663)
include_if_use(driver_wm8960.MIMXRT2663)
include_if_use(driver_wm8962.MIMXRT2663)
include_if_use(driver_xbar_1.MIMXRT2663)
include_if_use(driver_xspi.MIMXRT2663)
include_if_use(driver_xspi_edma.MIMXRT2663)
include_if_use(middleware_baremetal.MIMXRT2663)
include_if_use(middleware_cjson)
include_if_use(middleware_dhara)
include_if_use(middleware_dhara_dhara_ecc_bch)
include_if_use(middleware_dhara_dhara_ecc_hamming)
include_if_use(middleware_eiq_ethosu_application)
include_if_use(middleware_eiq_ethosu_core_driver)
include_if_use(middleware_eiq_executorch)
include_if_use(middleware_eiq_executorch_binary)
include_if_use(middleware_eiq_executorch_source)
include_if_use(middleware_eiq_neutron)
include_if_use(middleware_eiq_tensorflow_lite_micro)
include_if_use(middleware_eiq_tensorflow_lite_micro_binary)
include_if_use(middleware_eiq_tensorflow_lite_micro_cmsis_nn)
include_if_use(middleware_eiq_tensorflow_lite_micro_debug_log)
include_if_use(middleware_eiq_tensorflow_lite_micro_examples_microspeech)
include_if_use(middleware_eiq_tensorflow_lite_micro_headers)
include_if_use(middleware_eiq_tensorflow_lite_micro_library)
include_if_use(middleware_eiq_tensorflow_lite_micro_neutron)
include_if_use(middleware_eiq_tensorflow_lite_micro_refenerce)
include_if_use(middleware_eiq_tensorflow_lite_micro_reference)
include_if_use(middleware_eiq_tensorflow_lite_micro_source)
include_if_use(middleware_eiq_tensorflow_lite_micro_third_party_cmsis_nn)
include_if_use(middleware_eiq_tensorflow_lite_micro_third_party_fft2d)
include_if_use(middleware_fatfs)
include_if_use(middleware_fatfs_mmc)
include_if_use(middleware_fatfs_nand)
include_if_use(middleware_fatfs_ram)
include_if_use(middleware_fatfs_sd)
include_if_use(middleware_fatfs_sdspi)
include_if_use(middleware_fatfs_template_mmc)
include_if_use(middleware_fatfs_template_nand)
include_if_use(middleware_fatfs_template_ram)
include_if_use(middleware_fatfs_template_sd)
include_if_use(middleware_fatfs_template_sdspi)
include_if_use(middleware_fatfs_template_usb)
include_if_use(middleware_fatfs_usb)
include_if_use(middleware_fmstr)
include_if_use(middleware_fmstr_platform_56f800e)
include_if_use(middleware_fmstr_platform_gen32le)
include_if_use(middleware_fmstr_platform_pa32)
include_if_use(middleware_fmstr_platform_s12z)
include_if_use(middleware_fmstr_platform_s32)
include_if_use(middleware_freertos-kernel)
include_if_use(middleware_freertos-kernel_cm85_non_trustzone)
include_if_use(middleware_freertos-kernel_cm85_trustzone_non_secure)
include_if_use(middleware_freertos-kernel_cm85_trustzone_secure)
include_if_use(middleware_freertos-kernel_config)
include_if_use(middleware_freertos-kernel_extension)
include_if_use(middleware_freertos-kernel_heap_1)
include_if_use(middleware_freertos-kernel_heap_2)
include_if_use(middleware_freertos-kernel_heap_3)
include_if_use(middleware_freertos-kernel_heap_4)
include_if_use(middleware_freertos-kernel_heap_5)
include_if_use(middleware_freertos-kernel_mpu_wrappers)
include_if_use(middleware_freertos-kernel_mpu_wrappers_v2)
include_if_use(middleware_freertos-kernel_use_newlib_reentrant)
include_if_use(middleware_freertos-kernel_use_picolibc_tls)
include_if_use(middleware_freertos_backoffalgorithm)
include_if_use(middleware_freertos_corehttp)
include_if_use(middleware_freertos_corejson)
include_if_use(middleware_freertos_coremqtt)
include_if_use(middleware_freertos_coremqtt_template)
include_if_use(middleware_freertos_corepkcs11)
include_if_use(middleware_freertos_corepkcs11_mbedtls)
include_if_use(middleware_freertos_corepkcs11_mbedtls_utils)
include_if_use(middleware_freertos_corepkcs11_template)
include_if_use(middleware_freertos_freertos_posix_upstream)
include_if_use(middleware_freertos_posix)
include_if_use(middleware_iot_reference_logging.MIMXRT2663)
include_if_use(middleware_iot_reference_transport_mbedtls.MIMXRT2663)
include_if_use(middleware_iot_reference_transport_mbedtls3x.MIMXRT2663)
include_if_use(middleware_iot_reference_transport_mbedtls_psa.MIMXRT2663)
include_if_use(middleware_libjpeg)
include_if_use(middleware_libjpeg_template)
include_if_use(middleware_littlefs)
include_if_use(middleware_littlefs_mflash)
include_if_use(middleware_llhttp)
include_if_use(middleware_lvgl)
include_if_use(middleware_lvgl_demo_benchmark)
include_if_use(middleware_lvgl_demo_common)
include_if_use(middleware_lvgl_demo_flex_layout)
include_if_use(middleware_lvgl_demo_keypad_encoder)
include_if_use(middleware_lvgl_demo_multilang)
include_if_use(middleware_lvgl_demo_music)
include_if_use(middleware_lvgl_demo_scroll)
include_if_use(middleware_lvgl_demo_stress)
include_if_use(middleware_lvgl_demo_transform)
include_if_use(middleware_lvgl_demo_widgets)
include_if_use(middleware_lvgl_src_libs_thorvg)
include_if_use(middleware_lvgl_template)
include_if_use(middleware_lwip)
include_if_use(middleware_lwip_apps_altcp_tls)
include_if_use(middleware_lwip_apps_httpd)
include_if_use(middleware_lwip_apps_httpd_support)
include_if_use(middleware_lwip_apps_httpsrv)
include_if_use(middleware_lwip_apps_httpssrv)
include_if_use(middleware_lwip_apps_lwiperf)
include_if_use(middleware_lwip_apps_lwiperf_non_generated_lwipopts)
include_if_use(middleware_lwip_apps_mdns)
include_if_use(middleware_lwip_apps_mqtt)
include_if_use(middleware_lwip_apps_sntp)
include_if_use(middleware_lwip_contrib_ping)
include_if_use(middleware_lwip_contrib_tcpecho)
include_if_use(middleware_lwip_contrib_tcpecho_raw)
include_if_use(middleware_lwip_contrib_udpecho)
include_if_use(middleware_lwip_contrib_udpecho_raw)
include_if_use(middleware_lwip_empty_ethernetif)
include_if_use(middleware_lwip_enet_ethernetif)
include_if_use(middleware_lwip_enet_ethernetif_non_generated_lwipopts)
include_if_use(middleware_lwip_eoe_ethernetif)
include_if_use(middleware_lwip_eoe_ethernetif_non_generated_lwipopts)
include_if_use(middleware_lwip_kinetis_ethernetif)
include_if_use(middleware_lwip_kinetis_ethernetif_non_generated_lwipopts)
include_if_use(middleware_lwip_sys_arch_dynamic)
include_if_use(middleware_lwip_template)
include_if_use(middleware_lwip_usb_ethernetif)
include_if_use(middleware_lwip_usb_ethernetif_bm)
include_if_use(middleware_lwip_usb_ethernetif_freertos)
include_if_use(middleware_mbedtls)
include_if_use(middleware_mbedtls3x)
include_if_use(middleware_mbedtls3x_crypto)
include_if_use(middleware_mbedtls3x_crypto_no_psa)
include_if_use(middleware_mbedtls3x_crypto_storage_default)
include_if_use(middleware_mbedtls3x_crypto_storage_ram)
include_if_use(middleware_mbedtls3x_no_psa)
include_if_use(middleware_mbedtls3x_p256m)
include_if_use(middleware_mbedtls3x_port_config)
include_if_use(middleware_mbedtls3x_port_hw_init)
include_if_use(middleware_mbedtls3x_port_only_accelerator_config)
include_if_use(middleware_mbedtls3x_port_only_entropy)
include_if_use(middleware_mbedtls3x_port_psa_crypto_config)
include_if_use(middleware_mbedtls3x_port_tfm)
include_if_use(middleware_mbedtls3x_ssl)
include_if_use(middleware_mbedtls3x_ssl_no_psa)
include_if_use(middleware_mbedtls3x_template)
include_if_use(middleware_mbedtls3x_tests)
include_if_use(middleware_mbedtls3x_tests_certs_only)
include_if_use(middleware_mbedtls3x_x509)
include_if_use(middleware_mcuboot_boot_serial)
include_if_use(middleware_mcuboot_bootutil)
include_if_use(middleware_mcuboot_bootutil_flashapi_mcx)
include_if_use(middleware_mcuboot_bootutil_flashapi_rt)
include_if_use(middleware_mcuboot_mbedtls-asn1)
include_if_use(middleware_mcuboot_mbedtls_config)
include_if_use(middleware_mcuboot_nxp_app_support)
include_if_use(middleware_mcuboot_nxp_bootutil_port)
include_if_use(middleware_mcuboot_serial_recovery)
include_if_use(middleware_mcuboot_stack_heap_default_mbedtls)
include_if_use(middleware_mcuboot_stack_heap_default_tinycrypt)
include_if_use(middleware_mcuboot_tinycrypt)
include_if_use(middleware_mcuboot_tinycrypt_config)
include_if_use(middleware_mcuboot_zcbor)
include_if_use(middleware_openh264_api)
include_if_use(middleware_openh264_common)
include_if_use(middleware_openh264_decoder)
include_if_use(middleware_openh264_encoder)
include_if_use(middleware_openh264_procesing)
include_if_use(middleware_openh264_unused_files)
include_if_use(middleware_pkcs11)
include_if_use(middleware_pngdec)
include_if_use(middleware_psatest_ns)
include_if_use(middleware_psatest_ns_crypto)
include_if_use(middleware_psatest_ns_disable_crypto_cipher_module)
include_if_use(middleware_psatest_ns_initial_attestation)
include_if_use(middleware_psatest_ns_internal_trusted_storage)
include_if_use(middleware_psatest_ns_protected_storage)
include_if_use(middleware_psatest_ns_t_cose)
include_if_use(middleware_psatest_ns_tgt_dev_apis_nxp)
include_if_use(middleware_sdmmc_common)
include_if_use(middleware_sdmmc_host_usdhc)
include_if_use(middleware_sdmmc_host_usdhc_blocking)
include_if_use(middleware_sdmmc_host_usdhc_non_blocking)
include_if_use(middleware_sdmmc_mmc)
include_if_use(middleware_sdmmc_osa)
include_if_use(middleware_sdmmc_sd)
include_if_use(middleware_sdmmc_sdhc_template)
include_if_use(middleware_sdmmc_sdif_template)
include_if_use(middleware_sdmmc_sdio)
include_if_use(middleware_sdmmc_sdspi)
include_if_use(middleware_sdmmc_usdhc_template)
include_if_use(middleware_tfm_common_headers)
include_if_use(middleware_tfm_driver_headers)
include_if_use(middleware_tfm_enable_crypto_cipher_module)
include_if_use(middleware_tfm_enable_deterministic_ecdsa_module)
include_if_use(middleware_tfm_enable_platform_no_flash)
include_if_use(middleware_tfm_flash_dummy)
include_if_use(middleware_tfm_flash_rt700)
include_if_use(middleware_tfm_flash_use_nand_interface)
include_if_use(middleware_tfm_isolation_level_1)
include_if_use(middleware_tfm_isolation_level_2)
include_if_use(middleware_tfm_isolation_level_3)
include_if_use(middleware_tfm_lpuart)
include_if_use(middleware_tfm_ns)
include_if_use(middleware_tfm_ns_board)
include_if_use(middleware_tfm_ns_os_wrapper_baremetal)
include_if_use(middleware_tfm_ns_os_wrapper_rtos)
include_if_use(middleware_tfm_ns_test)
include_if_use(middleware_tfm_ns_test_attestation)
include_if_use(middleware_tfm_ns_test_attestation_asymmetric)
include_if_use(middleware_tfm_ns_test_attestation_symmetric)
include_if_use(middleware_tfm_ns_test_crypto)
include_if_use(middleware_tfm_ns_test_default_app)
include_if_use(middleware_tfm_ns_test_ipc)
include_if_use(middleware_tfm_ns_test_irq_flih)
include_if_use(middleware_tfm_ns_test_irq_slih)
include_if_use(middleware_tfm_ns_test_its)
include_if_use(middleware_tfm_ns_test_platform)
include_if_use(middleware_tfm_ns_test_ps)
include_if_use(middleware_tfm_ns_test_psatest_app)
include_if_use(middleware_tfm_ns_test_qcbor)
include_if_use(middleware_tfm_ns_test_s)
include_if_use(middleware_tfm_ns_test_tcose)
include_if_use(middleware_tfm_partition_init_attest)
include_if_use(middleware_tfm_platform_test)
include_if_use(middleware_tfm_profile_large)
include_if_use(middleware_tfm_profile_large_client_configs)
include_if_use(middleware_tfm_profile_large_ns_psatest_configs)
include_if_use(middleware_tfm_profile_large_ns_test_configs)
include_if_use(middleware_tfm_profile_large_s_configs)
include_if_use(middleware_tfm_profile_large_s_test_configs)
include_if_use(middleware_tfm_profile_medium)
include_if_use(middleware_tfm_profile_medium_additional_sha_algo)
include_if_use(middleware_tfm_profile_medium_client_configs)
include_if_use(middleware_tfm_profile_medium_ns_psatest_configs)
include_if_use(middleware_tfm_profile_medium_ns_test_configs)
include_if_use(middleware_tfm_profile_medium_s_configs)
include_if_use(middleware_tfm_profile_medium_s_test_configs)
include_if_use(middleware_tfm_profile_small)
include_if_use(middleware_tfm_profile_small_client_configs)
include_if_use(middleware_tfm_profile_small_ns_psatest_configs)
include_if_use(middleware_tfm_profile_small_ns_test_configs)
include_if_use(middleware_tfm_profile_small_s_configs)
include_if_use(middleware_tfm_profile_small_s_test_configs)
include_if_use(middleware_tfm_qcbor)
include_if_use(middleware_tfm_qcbor_test)
include_if_use(middleware_tfm_s)
include_if_use(middleware_tfm_s_accelerator)
include_if_use(middleware_tfm_s_board)
include_if_use(middleware_tfm_s_crypto)
include_if_use(middleware_tfm_s_initial_attestation)
include_if_use(middleware_tfm_s_initial_attestation_asymmetric)
include_if_use(middleware_tfm_s_initial_attestation_symmetric)
include_if_use(middleware_tfm_s_isolation_1)
include_if_use(middleware_tfm_s_isolation_1_cfg)
include_if_use(middleware_tfm_s_isolation_2)
include_if_use(middleware_tfm_s_isolation_2_cfg)
include_if_use(middleware_tfm_s_its)
include_if_use(middleware_tfm_s_its_load_info_common)
include_if_use(middleware_tfm_s_partition_load_attest)
include_if_use(middleware_tfm_s_partition_load_ps)
include_if_use(middleware_tfm_s_partition_ps)
include_if_use(middleware_tfm_s_platform)
include_if_use(middleware_tfm_s_platform_default_crypto_keys)
include_if_use(middleware_tfm_s_platform_default_nv_counter)
include_if_use(middleware_tfm_s_platform_nv_seed)
include_if_use(middleware_tfm_s_platform_sp_common)
include_if_use(middleware_tfm_s_protected_storage)
include_if_use(middleware_tfm_s_test)
include_if_use(middleware_tfm_s_test_attestation)
include_if_use(middleware_tfm_s_test_attestation_asymmetric)
include_if_use(middleware_tfm_s_test_attestation_symmetric)
include_if_use(middleware_tfm_s_test_crypto)
include_if_use(middleware_tfm_s_test_ipc)
include_if_use(middleware_tfm_s_test_irq_flih)
include_if_use(middleware_tfm_s_test_irq_slih)
include_if_use(middleware_tfm_s_test_its)
include_if_use(middleware_tfm_s_test_partition_load_ps_tests)
include_if_use(middleware_tfm_s_test_partition_ps_tests)
include_if_use(middleware_tfm_s_test_platform)
include_if_use(middleware_tfm_s_test_protected_storage)
include_if_use(middleware_tfm_secure_crypto_clients)
include_if_use(middleware_tfm_secure_reg_test_enable)
include_if_use(middleware_tfm_t_cose_mac0_verify)
include_if_use(middleware_tfm_t_cose_sign1_verify)
include_if_use(middleware_tfmtests_ns)
include_if_use(middleware_tfmtests_ns_test_attestation)
include_if_use(middleware_tfmtests_ns_test_attestation_asymmetric)
include_if_use(middleware_tfmtests_ns_test_attestation_symmetric)
include_if_use(middleware_tfmtests_ns_test_tcose)
include_if_use(middleware_tinycbor)
include_if_use(middleware_usb_common_header)
include_if_use(middleware_usb_device_audio)
include_if_use(middleware_usb_device_ccid)
include_if_use(middleware_usb_device_cdc)
include_if_use(middleware_usb_device_cdc_ecm)
include_if_use(middleware_usb_device_cdc_rndis)
include_if_use(middleware_usb_device_common_header)
include_if_use(middleware_usb_device_controller_driver)
include_if_use(middleware_usb_device_dfu)
include_if_use(middleware_usb_device_ehci)
include_if_use(middleware_usb_device_ehci_config_header)
include_if_use(middleware_usb_device_hid)
include_if_use(middleware_usb_device_khci)
include_if_use(middleware_usb_device_khci_config_header)
include_if_use(middleware_usb_device_msd)
include_if_use(middleware_usb_device_mtp)
include_if_use(middleware_usb_device_phdc)
include_if_use(middleware_usb_device_printer)
include_if_use(middleware_usb_device_stack)
include_if_use(middleware_usb_device_video)
include_if_use(middleware_usb_host_audio)
include_if_use(middleware_usb_host_cdc)
include_if_use(middleware_usb_host_cdc_ecm)
include_if_use(middleware_usb_host_cdc_rndis)
include_if_use(middleware_usb_host_common_header)
include_if_use(middleware_usb_host_ehci)
include_if_use(middleware_usb_host_ehci_config_header)
include_if_use(middleware_usb_host_hid)
include_if_use(middleware_usb_host_khci)
include_if_use(middleware_usb_host_khci_config_header)
include_if_use(middleware_usb_host_msd)
include_if_use(middleware_usb_host_phdc)
include_if_use(middleware_usb_host_printer)
include_if_use(middleware_usb_host_stack)
include_if_use(middleware_usb_host_video)
include_if_use(middleware_usb_hsdcd)
include_if_use(middleware_usb_hsdcd_config_header)
include_if_use(middleware_usb_pd)
include_if_use(middleware_usb_pd_altmode)
include_if_use(middleware_usb_pd_compliance_test_report)
include_if_use(middleware_usb_pd_config_header)
include_if_use(middleware_usb_pd_phy_ptn5110)
include_if_use(middleware_usb_phy)
include_if_use(utilities_misc_utilities.MIMXRT2663)
include_if_use(utility_assert.MIMXRT2663)
include_if_use(utility_assert_lite.MIMXRT2663)
include_if_use(utility_debug_console.MIMXRT2663)
include_if_use(utility_debug_console_lite.MIMXRT2663)
include_if_use(utility_debug_console_template_config.MIMXRT2663)
include_if_use(utility_incbin.MIMXRT2663)
include_if_use(utility_jlinkscript)
include_if_use(utility_notifier.MIMXRT2663)
include_if_use(utility_shell.MIMXRT2663)
include_if_use(utility_str.MIMXRT2663)
