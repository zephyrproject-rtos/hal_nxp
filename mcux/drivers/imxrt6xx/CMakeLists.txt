#
# Copyright (c) 2019, NXP
#
# SPDX-License-Identifier: Apache-2.0
#

zephyr_include_directories(.)

zephyr_library_compile_definitions_ifdef(
  CONFIG_MCUX_CACHE FSL_SDK_ENABLE_DRIVER_CACHE_CONTROL
)

zephyr_sources(fsl_common.c)
zephyr_sources_ifdef(CONFIG_MCUX_ACMP			fsl_acmp.c)
zephyr_sources_ifdef(CONFIG_MCUX_CACHE			fsl_cache.c)
zephyr_sources_ifdef(CONFIG_MCUX_FLEXCOMM_I2C		fsl_i2c.c fsl_flexcomm.c)
zephyr_sources_ifdef(CONFIG_MCUX_FLEXCOMM_SPI		fsl_spi.c fsl_flexcomm.c)
zephyr_sources_ifdef(CONFIG_MCUX_FLEXCOMM_UART		fsl_usart.c fsl_flexcomm.c)
zephyr_sources_ifdef(CONFIG_MCUX_FLEXSPI		fsl_flexspi.c)
zephyr_sources_ifdef(CONFIG_MCUX_LPC_DMA		fsl_dma.c)
zephyr_sources_ifdef(CONFIG_MCUX_LPC_GPIO		fsl_gpio.c fsl_pint.c fsl_inputmux.c)
