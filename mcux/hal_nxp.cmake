list(APPEND CMAKE_MODULE_PATH
    ${CMAKE_CURRENT_LIST_DIR}/mcux-sdk/devices/${MCUX_DEVICE_PATH}
    ${CMAKE_CURRENT_LIST_DIR}/mcux-sdk/devices/${MCUX_DEVICE_PATH}/drivers
    ${CMAKE_CURRENT_LIST_DIR}/mcux-sdk/drivers/common
    ${CMAKE_CURRENT_LIST_DIR}/mcux-sdk/drivers/flexcomm
    ${CMAKE_CURRENT_LIST_DIR}/mcux-sdk/drivers/flexio
    ${CMAKE_CURRENT_LIST_DIR}/mcux-sdk/drivers/dmamux
)

if(CONFIG_CPU_CORTEX_A)
    list(APPEND CMAKE_MODULE_PATH
        ${CMAKE_CURRENT_LIST_DIR}/mcux-sdk/CMSIS/Core_AArch64/Include
    )
else()
    list(APPEND CMAKE_MODULE_PATH
        ${CMAKE_CURRENT_LIST_DIR}/mcux-sdk/drivers/cache/armv7-m7
        ${CMAKE_CURRENT_LIST_DIR}/mcux-sdk/CMSIS/Core/Include
    )
endif()

function(include_ifdef feature_toggle module)
  if(${${feature_toggle}})
    include(${module})
  endif()
endfunction()

function(include_driver_ifdef feature_toggle directory module)
  if(${${feature_toggle}})
    list(APPEND CMAKE_MODULE_PATH
        ${CMAKE_CURRENT_LIST_DIR}/mcux-sdk/drivers/${directory}
    )
    zephyr_include_directories(${CMAKE_CURRENT_LIST_DIR}/mcux-sdk/drivers/${directory})
    include(${module})
  endif()
endfunction()

message("Load components for ${MCUX_DEVICE}:")

#specific operation to shared drivers
if((DEFINED CONFIG_FLASH_MCUX_FLEXSPI_XIP) AND (DEFINED CONFIG_FLASH))
  zephyr_code_relocate(FILES ${CMAKE_CURRENT_LIST_DIR}/mcux-sdk/drivers/flexspi/fsl_flexspi.c
    LOCATION ${CONFIG_FLASH_MCUX_FLEXSPI_XIP_MEM}_TEXT)
endif()

if(NOT CONFIG_ASSERT OR CONFIG_FORCE_NO_ASSERT)
  zephyr_compile_definitions(NDEBUG) # squelch fsl_flexcan.c warning
endif()

zephyr_compile_definitions_ifdef(
  CONFIG_PTP_CLOCK_MCUX
  ENET_ENHANCEDBUFFERDESCRIPTOR_MODE
)

zephyr_compile_definitions_ifdef(
  CONFIG_PTP_CLOCK_NXP_ENET
  ENET_ENHANCEDBUFFERDESCRIPTOR_MODE
)

zephyr_library_compile_definitions_ifdef(
  CONFIG_HAS_MCUX_CACHE FSL_SDK_ENABLE_DRIVER_CACHE_CONTROL
)

# note: if FSL_IRQSTEER_ENABLE_MASTER_INT is not
# defined then it will automatically be defined
# and set to 1 via fsl_irqsteer.h
zephyr_library_compile_definitions_ifdef(
  CONFIG_NXP_IRQSTEER
  FSL_IRQSTEER_ENABLE_MASTER_INT=0
)

zephyr_library_compile_definitions_ifdef(
  CONFIG_DAI_NXP_SAI
  MCUX_SDK_SAI_DISABLE_IMPLICIT_CHAN_CONFIG=1
)

# Required by all SCFW-based SoCs
if (CONFIG_SOC_MIMX8QM_A53 OR CONFIG_SOC_MIMX8QM_ADSP OR CONFIG_SOC_MIMX8QXP_ADSP)
    list(APPEND CMAKE_MODULE_PATH
        ${CMAKE_CURRENT_LIST_DIR}/mcux-sdk/devices/${MCUX_DEVICE}/scfw_api
    )
    zephyr_include_directories(${CMAKE_CURRENT_LIST_DIR}/mcux-sdk/devices/${MCUX_DEVICE}/scfw_api)
    include(driver_scfw_api)
endif()

include(driver_common)

#Include system_xxx file
#This can be extended to other SoC series if needed
if (DEFINED CONFIG_PLATFORM_SPECIFIC_INIT OR DEFINED CONFIG_SOC_SERIES_IMX_RT6XX
    OR DEFINED CONFIG_SOC_SERIES_LPC55XXX)
if (CONFIG_SOC_MIMXRT1166_CM4)
include(device_system_MIMXRT1166_cm4)
elseif (CONFIG_SOC_MIMXRT1166_CM7)
include(device_system_MIMXRT1166_cm7)
elseif (CONFIG_SOC_MIMXRT1176_CM4)
include(device_system_MIMXRT1176_cm4)
elseif (CONFIG_SOC_MIMXRT1176_CM7)
include(device_system_MIMXRT1176_cm7)
elseif (CONFIG_SOC_LPC55S69_CPU0)
include(device_system_LPC55S69_cm33_core0)
elseif (CONFIG_SOC_LPC55S69_CPU1)
include(device_system_LPC55S69_cm33_core1)
elseif (CONFIG_SOC_LPC54114_M4)
include(device_system_LPC54114_cm4)
elseif (CONFIG_SOC_LPC54114_M0)
include(device_system_LPC54114_cm0plus)
else()
include(device_system)
endif()
endif()

zephyr_include_directories(${CMAKE_CURRENT_LIST_DIR}/mcux-sdk/drivers/common)

#include shared drivers
include_driver_ifdef(CONFIG_ADC_MCUX_LPADC		lpadc		driver_lpadc)
include_driver_ifdef(CONFIG_COUNTER_MCUX_CTIMER		ctimer		driver_ctimer)
include_driver_ifdef(CONFIG_COUNTER_MCUX_LPC_RTC	lpc_rtc		driver_lpc_rtc)
include_driver_ifdef(CONFIG_DMA_MCUX_LPC		lpc_dma		driver_lpc_dma)
include_driver_ifdef(CONFIG_GPIO_MCUX_LPC		lpc_gpio        driver_lpc_gpio)
include_driver_ifdef(CONFIG_NXP_PINT			pint    	driver_pint)
include_driver_ifdef(CONFIG_NXP_PINT			inputmux	driver_inputmux)
include_driver_ifdef(CONFIG_I2C_MCUX_FLEXCOMM		flexcomm	driver_flexcomm)
include_driver_ifdef(CONFIG_I2C_MCUX_FLEXCOMM		flexcomm/i2c	driver_flexcomm_i2c)
include_driver_ifdef(CONFIG_I2S_MCUX_FLEXCOMM		flexcomm	driver_flexcomm)
include_driver_ifdef(CONFIG_I2S_MCUX_FLEXCOMM		flexcomm/i2s	driver_flexcomm_i2s)
include_driver_ifdef(CONFIG_MCUX_OS_TIMER		ostimer		driver_ostimer)
include_driver_ifdef(CONFIG_PWM_MCUX_SCTIMER		sctimer		driver_sctimer)
include_driver_ifdef(CONFIG_SOC_FLASH_LPC		flashiap	driver_flashiap)
include_driver_ifdef(CONFIG_SPI_MCUX_FLEXCOMM		flexcomm	driver_flexcomm)
include_driver_ifdef(CONFIG_SPI_MCUX_FLEXCOMM		flexcomm/spi	driver_flexcomm_spi)
include_driver_ifdef(CONFIG_UART_MCUX_FLEXCOMM		flexcomm	driver_flexcomm)
include_driver_ifdef(CONFIG_UART_MCUX_FLEXCOMM		flexcomm/usart	driver_flexcomm_usart)
include_driver_ifdef(CONFIG_WDT_MCUX_WWDT		wwdt		driver_wwdt)
include_driver_ifdef(CONFIG_ADC_MCUX_ADC12		adc12		driver_adc12)
include_driver_ifdef(CONFIG_ADC_MCUX_ADC16		adc16		driver_adc16)
include_driver_ifdef(CONFIG_IPM_IMX			mu		driver_mu)
include_driver_ifdef(CONFIG_MBOX_NXP_IMX_MU		mu		driver_mu)
include_driver_ifdef(CONFIG_CAN_MCUX_FLEXCAN		flexcan		driver_flexcan)
include_driver_ifdef(CONFIG_CAN_MCUX_FLEXCAN_FD		flexcan		driver_flexcan)
include_driver_ifdef(CONFIG_COUNTER_MCUX_PIT		pit		driver_pit)
include_driver_ifdef(CONFIG_COUNTER_MCUX_RTC		rtc		driver_rtc)
include_driver_ifdef(CONFIG_DAC_MCUX_DAC		dac		driver_dac)
include_driver_ifdef(CONFIG_DAC_MCUX_DAC32		dac32		driver_dac32)
include_driver_ifdef(CONFIG_DMA_MCUX_EDMA		dmamux		driver_dmamux)
include_driver_ifdef(CONFIG_DMA_MCUX_EDMA_V3		dmamux		driver_dmamux)
include_driver_ifdef(CONFIG_DMA_MCUX_EDMA		edma		driver_edma)
include_driver_ifdef(CONFIG_DMA_MCUX_EDMA_V3		dma3		driver_dma3)
include_driver_ifdef(CONFIG_ENTROPY_MCUX_RNGA		rnga		driver_rnga)
include_driver_ifdef(CONFIG_ENTROPY_MCUX_TRNG		trng		driver_trng)
include_driver_ifdef(CONFIG_ENTROPY_MCUX_CAAM		caam		driver_caam)
include_driver_ifdef(CONFIG_ETH_NXP_ENET		enet		driver_enet)
include_driver_ifdef(CONFIG_HAS_MCUX_SMC		smc		driver_smc)
include_driver_ifdef(CONFIG_I2C_MCUX			i2c		driver_i2c)
include_driver_ifdef(CONFIG_I2C_MCUX_LPI2C		lpi2c		driver_lpi2c)
include_driver_ifdef(CONFIG_I3C_MCUX			i3c		driver_i3c)
include_driver_ifdef(CONFIG_MCUX_ACMP			acmp		driver_acmp)
include_driver_ifdef(CONFIG_PWM_MCUX_FTM		ftm     	driver_ftm)
include_driver_ifdef(CONFIG_PWM_MCUX_TPM		tpm		driver_tpm)
include_driver_ifdef(CONFIG_PWM_MCUX_PWT		pwt		driver_pwt)
include_driver_ifdef(CONFIG_RTC_MCUX			rtc		driver_rtc)
include_driver_ifdef(CONFIG_SPI_MCUX_DSPI		dspi		driver_dspi)
include_driver_ifdef(CONFIG_SPI_MCUX_LPSPI		lpspi		driver_lpspi)
include_driver_ifdef(CONFIG_UART_MCUX			uart		driver_uart)
include_driver_ifdef(CONFIG_UART_MCUX_LPSCI		lpsci		driver_lpsci)
include_driver_ifdef(CONFIG_UART_MCUX_LPUART		lpuart		driver_lpuart)
include_driver_ifdef(CONFIG_WDT_MCUX_WDOG		wdog		driver_wdog)
include_driver_ifdef(CONFIG_WDT_MCUX_WDOG32		wdog32		driver_wdog32)
include_driver_ifdef(CONFIG_COUNTER_MCUX_GPT		gpt		driver_gpt)
include_driver_ifdef(CONFIG_MCUX_GPT_TIMER		gpt		driver_gpt)
include_driver_ifdef(CONFIG_COUNTER_MCUX_PIT		pit		driver_pit)
include_driver_ifdef(CONFIG_COUNTER_MCUX_QTMR		qtmr_1		driver_qtmr_1)
include_driver_ifdef(CONFIG_DISPLAY_MCUX_ELCDIF		elcdif		driver_elcdif)
include_driver_ifdef(CONFIG_DISPLAY_MCUX_DCNANO_LCDIF	lcdif		driver_lcdif)
include_driver_ifdef(CONFIG_MCUX_PXP			pxp		driver_pxp)
include_driver_ifdef(CONFIG_ETH_MCUX			enet		driver_enet)
include_driver_ifdef(CONFIG_GPIO_MCUX_IGPIO		igpio		driver_igpio)
include_driver_ifdef(CONFIG_I2C_MCUX_LPI2C		lpi2c		driver_lpi2c)
include_driver_ifdef(CONFIG_I2S_MCUX_SAI		sai		driver_sai)
include_driver_ifdef(CONFIG_DAI_NXP_SAI			sai		driver_sai)
include_driver_ifdef(CONFIG_MEMC_MCUX_FLEXSPI		flexspi		driver_flexspi)
include_driver_ifdef(CONFIG_PWM_MCUX			pwm		driver_pwm)
include_driver_ifdef(CONFIG_SPI_MCUX_LPSPI		lpspi		driver_lpspi)
include_driver_ifdef(CONFIG_UART_MCUX_LPUART		lpuart		driver_lpuart)
include_driver_ifdef(CONFIG_VIDEO_MCUX_CSI		csi		driver_csi)
include_driver_ifdef(CONFIG_WDT_MCUX_IMX_WDOG		wdog01		driver_wdog01)
include_driver_ifdef(CONFIG_DMA_MCUX_LPC		lpc_dma		driver_lpc_dma)
include_driver_ifdef(CONFIG_MEMC_MCUX_FLEXSPI		flexspi		driver_flexspi)
include_driver_ifdef(CONFIG_HAS_MCUX_RDC		rdc		driver_rdc)
include_driver_ifdef(CONFIG_UART_MCUX_IUART		iuart		driver_iuart)
include_driver_ifdef(CONFIG_ADC_MCUX_12B1MSPS_SAR	adc_12b1msps_sar	driver_adc_12b1msps_sar)
include_driver_ifdef(CONFIG_HWINFO_MCUX_SRC		src		driver_src)
include_driver_ifdef(CONFIG_HWINFO_MCUX_SIM		sim		driver_sim)
include_driver_ifdef(CONFIG_HWINFO_MCUX_RCM		rcm		driver_rcm)
include_driver_ifdef(CONFIG_IPM_MCUX			mailbox		driver_mailbox)
include_driver_ifdef(CONFIG_COUNTER_MCUX_SNVS		snvs_hp		driver_snvs_hp)
include_driver_ifdef(CONFIG_COUNTER_MCUX_SNVS_SRTC	snvs_lp		driver_snvs_lp)
include_driver_ifdef(CONFIG_COUNTER_MCUX_LPTMR		lptmr		driver_lptmr)
include_driver_ifdef(CONFIG_MCUX_LPTMR_TIMER		lptmr		driver_lptmr)
include_driver_ifdef(CONFIG_IMX_USDHC			usdhc		driver_usdhc)
include_driver_ifdef(CONFIG_MIPI_DSI_MCUX		mipi_dsi_split	driver_mipi_dsi_split)
include_driver_ifdef(CONFIG_MIPI_DSI_MCUX_2L		mipi_dsi	driver_mipi_dsi)
include_driver_ifdef(CONFIG_ADC_LPC_ADC			lpc_adc		driver_lpc_adc)
include_driver_ifdef(CONFIG_MCUX_SDIF			sdif		driver_sdif)
include_driver_ifdef(CONFIG_ADC_MCUX_ETC		adc_etc		driver_adc_etc)
include_driver_ifdef(CONFIG_MCUX_XBARA			xbara		driver_xbara)
include_driver_ifdef(CONFIG_QDEC_MCUX			enc		driver_enc)
include_driver_ifdef(CONFIG_CRYPTO_MCUX_DCP			dcp		driver_dcp)
include_driver_ifdef(CONFIG_DMA_MCUX_SMARTDMA		smartdma	driver_lpc_smartdma)
include_driver_ifdef(CONFIG_DAC_MCUX_LPDAC			dac_1		driver_dac_1)
include_driver_ifdef(CONFIG_NXP_IRQSTEER			irqsteer	driver_irqsteer)

if ((${MCUX_DEVICE} MATCHES "MIMXRT1[0-9][0-9][0-9]") AND (NOT (CONFIG_SOC_MIMXRT1166_CM4 OR CONFIG_SOC_MIMXRT1176_CM4)))
  include_driver_ifdef(CONFIG_HAS_MCUX_CACHE		cache/armv7-m7	driver_cache_armv7_m7)
elseif(${MCUX_DEVICE} MATCHES "MIMXRT(5|6)")
  include_driver_ifdef(CONFIG_HAS_MCUX_CACHE		cache/cache64	driver_cache_cache64)
elseif((${MCUX_DEVICE} MATCHES "MK(28|66)") OR (${MCUX_DEVICE} MATCHES "MKE(14|16|18)") OR (CONFIG_SOC_MIMXRT1166_CM4) OR (CONFIG_SOC_MIMXRT1176_CM4))
  include_driver_ifdef(CONFIG_HAS_MCUX_CACHE		cache/lmem	driver_cache_lmem)
endif()

if (${MCUX_DEVICE} MATCHES "MIMXRT11[0-9][0-9]")
   include_driver_ifdef(CONFIG_PM_MCUX_GPC		gpc_3		driver_gpc_3)
   include_ifdef(CONFIG_HWINFO_MCUX_SRC_V2		driver_soc_src)
elseif (${MCUX_DEVICE} MATCHES "MIMXRT10[0-9][0-9]")
   include_driver_ifdef(CONFIG_PM_MCUX_GPC		gpc_1		driver_gpc_1)
   include_driver_ifdef(CONFIG_PM_MCUX_DCDC		dcdc_1		driver_dcdc_1)
   include_driver_ifdef(CONFIG_PM_MCUX_PMU		pmu		driver_pmu)
endif()

if("${CONFIG_SOC_FAMILY}" STREQUAL "nxp_kinetis")

  include_driver_ifdef(CONFIG_SOC_FLASH_MCUX		flash		driver_flash)

  include(${CMAKE_CURRENT_LIST_DIR}/mcux-sdk/drivers/port/driver_port.cmake)
  zephyr_include_directories(${CMAKE_CURRENT_LIST_DIR}/mcux-sdk/drivers/port)

  if(${MCUX_DEVICE} MATCHES "MK(80|82|64|66|M34|M35|E14F|E16F|E18F|22F12)")
    include(${CMAKE_CURRENT_LIST_DIR}/mcux-sdk/drivers/sysmpu/driver_sysmpu.cmake)
    zephyr_include_directories(${CMAKE_CURRENT_LIST_DIR}/mcux-sdk/drivers/sysmpu)
  endif()

endif()

if("${CONFIG_SOC_FAMILY}" STREQUAL "nxp_lpc")

if ((${MCUX_DEVICE} MATCHES "LPC8[0-9][0-9]") OR (${MCUX_DEVICE} MATCHES "LPC5(1|4)"))
  include_driver_ifdef(CONFIG_SOC_FLASH_MCUX		iap		driver_iap)
  include_driver_ifdef(CONFIG_ENTROPY_MCUX_RNG		iap		driver_rng)
elseif (${MCUX_DEVICE} MATCHES "LPC55")
  if (${MCUX_DEVICE} MATCHES "LPC55S*3")
   if(${CONFIG_SOC_FLASH_MCUX})
      list(APPEND CMAKE_MODULE_PATH
        ${CMAKE_CURRENT_LIST_DIR}/mcux-sdk/devices/LPC55S36/drivers
      )
      zephyr_include_directories(${CMAKE_CURRENT_LIST_DIR}/mcux-sdk/devices/LPC55S36/drivers/flash)
      include(driver_flashiap)
    endif()
  else()
    include_driver_ifdef(CONFIG_SOC_FLASH_MCUX		iap1		driver_iap1)
  endif()
  include_driver_ifdef(CONFIG_ENTROPY_MCUX_RNG		rng_1		driver_rng_1)
endif()

if (${MCUX_DEVICE} MATCHES "LPC5")
  include(${CMAKE_CURRENT_LIST_DIR}/mcux-sdk/drivers/lpc_iocon/driver_lpc_iocon.cmake)
  zephyr_include_directories(${CMAKE_CURRENT_LIST_DIR}/mcux-sdk/drivers/lpc_iocon)
  if (${MCUX_DEVICE} MATCHES "LPC55S*3" AND (DEFINED CONFIG_ADC_MCUX_LPADC OR DEFINED CONFIG_DAC_MCUX_LPDAC))
    include(${CMAKE_CURRENT_LIST_DIR}/mcux-sdk/drivers/vref_1/driver_vref_1.cmake)
    zephyr_include_directories(${CMAKE_CURRENT_LIST_DIR}/mcux-sdk/drivers/vref_1)
  endif()
elseif (${MCUX_DEVICE} MATCHES "LPC8")
  include(${CMAKE_CURRENT_LIST_DIR}/mcux-sdk/drivers/lpc_iocon_lite/driver_lpc_iocon_lite.cmake)
  zephyr_include_directories(${CMAKE_CURRENT_LIST_DIR}/mcux-sdk/drivers/lpc_iocon_lite)
endif()

endif()

if(${MCUX_DEVICE} MATCHES "MIMXRT(5|6)")
  include(${CMAKE_CURRENT_LIST_DIR}/mcux-sdk/drivers/lpc_iopctl/driver_lpc_iopctl.cmake)
  zephyr_include_directories(${CMAKE_CURRENT_LIST_DIR}/mcux-sdk/drivers/lpc_iopctl)
endif()

if(CONFIG_ETH_MCUX)
  zephyr_include_directories(${CMAKE_CURRENT_LIST_DIR}/mcux-sdk/components/phy)
  zephyr_include_directories(${CMAKE_CURRENT_LIST_DIR}/mcux-sdk/components/phy/device/phyksz8081)
  zephyr_include_directories(${CMAKE_CURRENT_LIST_DIR}/mcux-sdk/components/phy/device/phyar8031)
  zephyr_include_directories(${CMAKE_CURRENT_LIST_DIR}/mcux-sdk/components/phy/device/phylan8720a)
  zephyr_include_directories(${CMAKE_CURRENT_LIST_DIR}/mcux-sdk/components/phy/device/phyrtl8211f)
  zephyr_library_sources(mcux-sdk/components/phy/device/phyksz8081/fsl_phyksz8081.c)
  zephyr_library_sources(mcux-sdk/components/phy/device/phyar8031/fsl_phyar8031.c)
  zephyr_library_sources(mcux-sdk/components/phy/device/phylan8720a/fsl_phylan8720a.c)
  zephyr_library_sources(mcux-sdk/components/phy/device/phyrtl8211f/fsl_phyrtl8211f.c)

  zephyr_include_directories(${CMAKE_CURRENT_LIST_DIR}/mcux-sdk/components/phy/mdio/enet)
  #zephyr_library_sources(mcux-sdk/components/phy/mdio/enet/fsl_enet_mdio.c)
endif()

if (CONFIG_USB_DEVICE_DRIVER)
  list(APPEND CMAKE_MODULE_PATH
    ${CMAKE_CURRENT_LIST_DIR}/middleware/mcux-sdk-middleware-usb
  )
  include(middleware_usb_phy)
  include_ifdef(CONFIG_USB_DC_NXP_EHCI         middleware_usb_device_ehci)
  include_ifdef(CONFIG_USB_DC_NXP_LPCIP3511    middleware_usb_device_ip3511fs)

  zephyr_include_directories(${CMAKE_CURRENT_LIST_DIR}/middleware/mcux-sdk-middleware-usb/device)
  zephyr_include_directories(${CMAKE_CURRENT_LIST_DIR}/middleware/mcux-sdk-middleware-usb/phy)
  zephyr_include_directories(${CMAKE_CURRENT_LIST_DIR}/middleware/mcux-sdk-middleware-usb/include)
endif()

if(CONFIG_ENTROPY_MCUX_CSS)
  list(APPEND CMAKE_MODULE_PATH
    ${CMAKE_CURRENT_LIST_DIR}/mcux-sdk/components/css_pkc
  )
  zephyr_include_directories(${CMAKE_CURRENT_LIST_DIR}/mcux-sdk/components/css_pkc/src/comps/mcuxClCss/inc)
  zephyr_include_directories(${CMAKE_CURRENT_LIST_DIR}/mcux-sdk/components/css_pkc/src/comps/mcuxCsslFlowProtection/inc)
  zephyr_include_directories(${CMAKE_CURRENT_LIST_DIR}/mcux-sdk/components/css_pkc/src/comps/mcuxCsslSecureCounter/inc)
  zephyr_include_directories(${CMAKE_CURRENT_LIST_DIR}/mcux-sdk/components/css_pkc/src/comps/mcuxCsslCPreProcessor/inc)
  zephyr_include_directories(${CMAKE_CURRENT_LIST_DIR}/mcux-sdk/components/css_pkc/src/comps/mcuxClMemory/inc)
  zephyr_include_directories(${CMAKE_CURRENT_LIST_DIR}/mcux-sdk/components/css_pkc/src/platforms)
  zephyr_include_directories(${CMAKE_CURRENT_LIST_DIR}/mcux-sdk/components/css_pkc/src/platforms/LPC55S3x/inc)
  zephyr_include_directories(${CMAKE_CURRENT_LIST_DIR}/mcux-sdk/components/css_pkc/src/compiler/iar)
  zephyr_include_directories(${CMAKE_CURRENT_LIST_DIR}/mcux-sdk/components/css_pkc/src/platforms/crypto_ip/inc/css/2.13.4)
  zephyr_include_directories(${CMAKE_CURRENT_LIST_DIR}/mcux-sdk/components/css_pkc/src/platforms/crypto_ip/inc/fame)
  zephyr_include_directories(${CMAKE_CURRENT_LIST_DIR}/mcux-sdk/components/css_pkc/src/comps/mcuxClKey/src)
  zephyr_include_directories(${CMAKE_CURRENT_LIST_DIR}/mcux-sdk/components/css_pkc/src/comps/mcuxClSession/inc)
  include(component_css)
endif()
