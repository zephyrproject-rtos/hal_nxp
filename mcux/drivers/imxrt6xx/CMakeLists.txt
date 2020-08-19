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
zephyr_sources_ifdef(CONFIG_GPIO_MCUX_LPC     fsl_gpio.c fsl_pint.c fsl_inputmux.c)
zephyr_sources_ifdef(CONFIG_DMA_MCUX_LPC      fsl_dma.c)
