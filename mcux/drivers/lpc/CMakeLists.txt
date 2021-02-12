#
# Copyright (c) 2018, NXP
#
# SPDX-License-Identifier: Apache-2.0
#

zephyr_include_directories(.)

zephyr_library_sources(fsl_common.c)

zephyr_library_sources_ifdef(CONFIG_MCUX_FLASHIAP	fsl_flashiap.c)
zephyr_library_sources_ifdef(CONFIG_MCUX_FLEXCOMM_I2C	fsl_i2c.c fsl_flexcomm.c)
zephyr_library_sources_ifdef(CONFIG_MCUX_FLEXCOMM_SPI	fsl_spi.c fsl_flexcomm.c)
zephyr_library_sources_ifdef(CONFIG_MCUX_FLEXCOMM_UART	fsl_usart.c fsl_flexcomm.c)
zephyr_library_sources_ifdef(CONFIG_MCUX_IAP		fsl_iap.c)
zephyr_library_sources_ifdef(CONFIG_MCUX_LPADC		fsl_lpadc.c)
zephyr_library_sources_ifdef(CONFIG_MCUX_LPC_DMA	fsl_dma.c)
zephyr_library_sources_ifdef(CONFIG_MCUX_LPC_GPIO	fsl_gpio.c fsl_pint.c fsl_inputmux.c)
zephyr_library_sources_ifdef(CONFIG_MCUX_RNG		fsl_rng.c)
zephyr_library_sources_ifdef(CONFIG_MCUX_WWDT		fsl_wwdt.c)
