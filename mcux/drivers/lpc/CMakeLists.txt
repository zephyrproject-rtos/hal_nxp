#
# Copyright (c) 2018, NXP
#
# SPDX-License-Identifier: Apache-2.0
#

zephyr_include_directories(.)

zephyr_library_sources(fsl_common.c)
zephyr_library_sources_ifdef(CONFIG_ENTROPY_MCUX_RNG	fsl_rng.c)
zephyr_library_sources_ifdef(CONFIG_GPIO_MCUX_LPC	fsl_gpio.c fsl_pint.c fsl_inputmux.c)
zephyr_library_sources_ifdef(CONFIG_I2C_MCUX_FLEXCOMM	fsl_i2c.c fsl_flexcomm.c)
zephyr_library_sources_ifdef(CONFIG_SOC_FLASH_MCUX	fsl_iap.c)
zephyr_library_sources_ifdef(CONFIG_SPI_MCUX_FLEXCOMM	fsl_spi.c fsl_flexcomm.c)
zephyr_library_sources_ifdef(CONFIG_UART_MCUX_FLEXCOMM	fsl_usart.c fsl_flexcomm.c)
zephyr_library_sources_ifdef(CONFIG_WDT_MCUX_WWDT	fsl_wwdt.c)
zephyr_library_sources_ifdef(CONFIG_ADC_MCUX_LPADC	fsl_lpadc.c)
