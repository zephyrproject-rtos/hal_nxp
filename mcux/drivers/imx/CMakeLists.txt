#
# Copyright (c) 2018, NXP
#
# SPDX-License-Identifier: Apache-2.0
#

zephyr_include_directories(.)

zephyr_compile_definitions_ifdef(
  CONFIG_PTP_CLOCK_MCUX
  ENET_ENHANCEDBUFFERDESCRIPTOR_MODE
)

zephyr_library_compile_definitions_ifdef(
  CONFIG_MCUX_CACHE FSL_SDK_ENABLE_DRIVER_CACHE_CONTROL
)

zephyr_library_sources_ifdef(CONFIG_MCUX_CACHE		fsl_cache.c)
zephyr_library_sources_ifdef(CONFIG_MCUX_CSI		fsl_csi.c)
zephyr_library_sources_ifdef(CONFIG_MCUX_EDMA		fsl_edma.c fsl_dmamux.c)
zephyr_library_sources_ifdef(CONFIG_MCUX_ELCDIF		fsl_elcdif.c)
zephyr_library_sources_ifdef(CONFIG_MCUX_ENET		fsl_enet.c)
zephyr_library_sources_ifdef(CONFIG_MCUX_FLEXCAN	fsl_flexcan.c)
zephyr_library_sources_ifdef(CONFIG_MCUX_FLEXSPI	fsl_flexspi.c)
zephyr_library_sources_ifdef(CONFIG_MCUX_GPT		fsl_gpt.c)
zephyr_library_sources_ifdef(CONFIG_MCUX_IGPIO		fsl_gpio.c)
zephyr_library_sources_ifdef(CONFIG_MCUX_LPI2C		fsl_lpi2c.c)
zephyr_library_sources_ifdef(CONFIG_MCUX_LPSPI		fsl_lpspi.c)
zephyr_library_sources_ifdef(CONFIG_MCUX_LPUART		fsl_lpuart.c)
zephyr_library_sources_ifdef(CONFIG_MCUX_PIT		fsl_pit.c)
zephyr_library_sources_ifdef(CONFIG_MCUX_PWM		fsl_pwm.c)
zephyr_library_sources_ifdef(CONFIG_MCUX_SAI		fsl_sai.c fsl_sai_edma.c)
zephyr_library_sources_ifdef(CONFIG_MCUX_TRNG		fsl_trng.c)
zephyr_library_sources_ifdef(CONFIG_MCUX_WDOG		fsl_wdog.c)

if(NOT CONFIG_ASSERT OR CONFIG_FORCE_NO_ASSERT)
  zephyr_compile_definitions(NDEBUG) # squelch fsl_flexcan.c warning
endif()
