#
# 2023-11-03 - Created by Sendrato.com
# SPDX-License-Identifier: Apache-2.0
#

zephyr_include_directories(.)

zephyr_library_sources_ifdef(CONFIG_ADC_LPC_ADC             fsl_adc.c)
zephyr_library_sources_ifdef(CONFIG_BT_NXP_IPM		        fsl_adc.c)
# fsl_aes : bluetooth controller depends on the fsl_aes.c that again depends on fsl_common.c library
zephyr_library_sources_ifdef(CONFIG_BT                      fsl_aes.c)
# fsl_cic_XX
# fsl_cmp
zephyr_library_sources_ifdef(CONFIG_BT_NXP_IPM		        fsl_common.c)
zephyr_library_sources_ifdef(CONFIG_COUNTER_MCUX_CTIMER     fsl_ctimer.c)
zephyr_library_sources_ifdef(CONFIG_DMA_MCUX_LPC            fsl_dma.c)
# fsl_dmic_XX
# fsl_flash: Always include flash
zephyr_library_sources(fsl_flash.c)
zephyr_library_sources_ifdef(CONFIG_SPI_MCUX_FLEXCOMM       fsl_flexcomm.c)
zephyr_library_sources_ifdef(CONFIG_I2C_MCUX_FLEXCOMM       fsl_flexcomm.c)
zephyr_library_sources_ifdef(CONFIG_I2S_MCUX_FLEXCOMM       fsl_flexcomm.c)
zephyr_library_sources_ifdef(CONFIG_UART_MCUX_FLEXCOMM      fsl_flexcomm.c)
# fsl_fmeas
# fsl_gint
zephyr_library_sources_ifdef(CONFIG_GPIO_MCUX_LPC	        fsl_gpio.c)
zephyr_library_sources_ifdef(CONFIG_I2C_MCUX		        fsl_i2c.c)
zephyr_library_sources_ifdef(CONFIG_I2C_MCUX_FLEXCOMM	    fsl_i2c.c)
# fsl_i2c_dma
zephyr_library_sources_ifdef(CONFIG_GPIO_MCUX_LPC           fsl_inputmux.c)
# fsl_ntag
zephyr_library_sources_ifdef(CONFIG_GPIO_MCUX_LPC	        fsl_pint.c)
zephyr_library_sources_ifdef(CONFIG_PWM_MCUX	            fsl_pwm.c)
zephyr_library_sources_ifdef(CONFIG_ENTROPY_MCUX_RNG	    fsl_rng.c)
zephyr_library_sources_ifdef(CONFIG_RTC_MCUX		        fsl_rtc.c)
zephyr_library_sources_ifdef(CONFIG_COUNTER_MCUX_RTC	    fsl_rtc.c)
zephyr_library_sources_ifdef(CONFIG_COUNTER_MCUX_LPC_RTC	fsl_rtc.c)
# fsl_sha
zephyr_library_sources_ifdef(CONFIG_SPI_MCUX_FLEXCOMM	    fsl_spi.c)
# fsl_spi_dma
# fsl_spifi
# fsl_spifi_dma
zephyr_library_sources_ifdef(CONFIG_UART_MCUX_FLEXCOMM	    fsl_usart.c)
zephyr_library_sources_ifdef(CONFIG_UART_MCUX_USART	        fsl_usart.c)
# fsl_usart_dma
# fsl_wtimer : always include
zephyr_library_sources(fsl_wtimer.c)
zephyr_library_sources_ifdef(CONFIG_WDT_MCUX_WWDT	        fsl_wwdt.c)
# psector_api : always include psector/rom functions
zephyr_library_sources(psector_api.c)
# sha is used by BLE framework
zephyr_library_sources_ifdef(CONFIG_BT_NXP_IPM			fsl_sha.c)

if(NOT CONFIG_ASSERT OR CONFIG_FORCE_NO_ASSERT)
  zephyr_compile_definitions(NDEBUG) # squelch fsl_flexcan.c warning
endif()


if(CONFIG_BT)
    zephyr_compile_definitions(gSupportBle=1)

    # no support for zigbee
    #zephyr_compile_definitions(SUPPORT_FOR_15_4=0)

    zephyr_compile_definitions(SUPPORT_FOR_BLE=1)
#    zephyr_compile_definitions(CPU_QN9090HN)
#    zephyr_compile_definitions(CPU_QN9090HN_cm4)
#    zephyr_compile_definitions(CPU_QN9090)
#    zephyr_compile_definitions(__CPU_JN518X_REV=1)
#    zephyr_compile_definitions(QN9090DK6)
#    zephyr_compile_definitions(DK6)
#    zephyr_compile_definitions(CPU_JN518X)
 #   zephyr_compile_definitions(CFG_BLE_PRJ=1)
    zephyr_compile_definitions(ENABLE_RAM_VECTOR_TABLE=1)
    zephyr_compile_definitions(gPWR_CpuClk_48MHz)
#    zephyr_compile_definitions(gBLE50_d)

## extra ?!?
    #zephyr_compile_definitions(gRadioUsePdm_d=1)

endif()
