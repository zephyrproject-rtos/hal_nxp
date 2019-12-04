#
# Copyright (c) 2018, NXP
#
# SPDX-License-Identifier: Apache-2.0
#

zephyr_include_directories(.)

zephyr_sources_ifdef(CONFIG_SPI_MCUX_FLEXCOMM   fsl_spi.c fsl_flexcomm.c)
zephyr_sources_ifdef(CONFIG_UART_MCUX_FLEXCOMM	fsl_usart.c fsl_flexcomm.c)
zephyr_sources_ifdef(CONFIG_GPIO_MCUX_LPC     fsl_gpio.c fsl_pint.c fsl_inputmux.c)
