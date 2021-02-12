#
# Copyright 2018, 2020 NXP
#
# SPDX-License-Identifier: Apache-2.0
#

zephyr_include_directories(.)

zephyr_compile_definitions_ifdef(
  CONFIG_PTP_CLOCK_MCUX
  ENET_ENHANCEDBUFFERDESCRIPTOR_MODE
)

zephyr_library_sources_ifdef(CONFIG_MCUX_ACMP		fsl_acmp.c)
zephyr_library_sources_ifdef(CONFIG_MCUX_ADC12		fsl_adc12.c)
zephyr_library_sources_ifdef(CONFIG_MCUX_ADC16		fsl_adc16.c)
zephyr_library_sources_ifdef(CONFIG_MCUX_CACHE		fsl_cache.c)
zephyr_library_sources_ifdef(CONFIG_MCUX_DAC		fsl_dac.c)
zephyr_library_sources_ifdef(CONFIG_MCUX_DAC32		fsl_dac32.c)
zephyr_library_sources_ifdef(CONFIG_MCUX_DSPI		fsl_dspi.c)
zephyr_library_sources_ifdef(CONFIG_MCUX_EDMA		fsl_edma.c fsl_dmamux.c)
zephyr_library_sources_ifdef(CONFIG_MCUX_ENET		fsl_enet.c)
zephyr_library_sources_ifdef(CONFIG_MCUX_FLEXCAN	fsl_flexcan.c)
zephyr_library_sources_ifdef(CONFIG_MCUX_FTFX		fsl_ftfx_flash.c fsl_ftfx_controller.c)
zephyr_library_sources_ifdef(CONFIG_MCUX_FTM		fsl_ftm.c)
zephyr_library_sources_ifdef(CONFIG_MCUX_I2C		fsl_i2c.c)
zephyr_library_sources_ifdef(CONFIG_MCUX_LPI2C		fsl_lpi2c.c)
zephyr_library_sources_ifdef(CONFIG_MCUX_LPSCI		fsl_lpsci.c)
zephyr_library_sources_ifdef(CONFIG_MCUX_LPSPI		fsl_lpspi.c)
zephyr_library_sources_ifdef(CONFIG_MCUX_LPTMR		fsl_lptmr.c)
zephyr_library_sources_ifdef(CONFIG_MCUX_LPUART		fsl_lpuart.c)
zephyr_library_sources_ifdef(CONFIG_MCUX_PIT		fsl_pit.c)
zephyr_library_sources_ifdef(CONFIG_MCUX_PWT		fsl_pwt.c)
zephyr_library_sources_ifdef(CONFIG_MCUX_RNGA		fsl_rnga.c)
zephyr_library_sources_ifdef(CONFIG_MCUX_RTC		fsl_rtc.c)
zephyr_library_sources_ifdef(CONFIG_MCUX_SMC		fsl_smc.c)
zephyr_library_sources_ifdef(CONFIG_MCUX_TPM		fsl_tpm.c)
zephyr_library_sources_ifdef(CONFIG_MCUX_TRNG		fsl_trng.c)
zephyr_library_sources_ifdef(CONFIG_MCUX_UART		fsl_uart.c)
zephyr_library_sources_ifdef(CONFIG_MCUX_WDOG		fsl_wdog.c)
zephyr_library_sources_ifdef(CONFIG_MCUX_WDOG32		fsl_wdog32.c)

if(NOT CONFIG_ASSERT OR CONFIG_FORCE_NO_ASSERT)
  zephyr_compile_definitions(NDEBUG) # squelch fsl_flexcan.c warning
endif()
