#
# Copyright (c) 2018, NXP
#
# SPDX-License-Identifier: Apache-2.0
#

zephyr_include_directories(.)

zephyr_library_sources_ifdef(CONFIG_COUNTER_MCUX_GPT	fsl_gpt.c)
zephyr_library_sources_ifdef(CONFIG_GPIO_MCUX_IGPIO	fsl_gpio.c)
zephyr_library_sources_ifdef(CONFIG_I2S_MCUX_SAI	fsl_sai.c)
zephyr_library_sources_ifdef(CONFIG_I2S_MCUX_SAI	fsl_sai_edma.c)
zephyr_library_sources_ifdef(CONFIG_PWM_MCUX		fsl_pwm.c)
zephyr_library_sources_ifdef(CONFIG_HAS_MCUX_RDC	fsl_rdc.c)
zephyr_library_sources_ifdef(CONFIG_UART_MCUX_IUART	fsl_uart.c)
