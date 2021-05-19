#
# Copyright (c) 2019, NXP
#
# SPDX-License-Identifier: Apache-2.0
#

zephyr_include_directories(.)

zephyr_library_compile_definitions_ifdef(
  CONFIG_HAS_MCUX_CACHE FSL_SDK_ENABLE_DRIVER_CACHE_CONTROL
)

zephyr_sources(fsl_common.c)
zephyr_sources_ifdef(CONFIG_HAS_MCUX_CACHE    fsl_cache.c)
zephyr_sources_ifdef(CONFIG_SPI_MCUX_FLEXCOMM   fsl_spi.c fsl_flexcomm.c)
zephyr_sources_ifdef(CONFIG_I2C_MCUX_FLEXCOMM   fsl_i2c.c fsl_flexcomm.c)
zephyr_sources_ifdef(CONFIG_UART_MCUX_FLEXCOMM	fsl_usart.c fsl_flexcomm.c)
zephyr_sources_ifdef(CONFIG_I2S_MCUX_FLEXCOMM	fsl_i2s.c fsl_flexcomm.c)
zephyr_sources_ifdef(CONFIG_GPIO_MCUX_LPC     fsl_gpio.c fsl_pint.c fsl_inputmux.c)
zephyr_sources_ifdef(CONFIG_DMA_MCUX_LPC      fsl_dma.c)
zephyr_sources_ifdef(CONFIG_MCUX_ACMP         fsl_acmp.c)
zephyr_sources_ifdef(CONFIG_MEMC_MCUX_FLEXSPI	fsl_flexspi.c)
zephyr_sources_ifdef(CONFIG_MCUX_OS_TIMER	fsl_ostimer.c)
zephyr_sources_ifdef(CONFIG_COUNTER_MCUX_LPC_RTC	fsl_rtc.c)
zephyr_sources_ifdef(CONFIG_PWM_MCUX_LPC	fsl_sctimer.c)
if(CONFIG_FLASH_MCUX_FLEXSPI_XIP)
  zephyr_code_relocate(fsl_flexspi.c ${CONFIG_FLASH_MCUX_FLEXSPI_XIP_MEM}_TEXT)
endif()
