# Copyright 2023 NXP
# SPDX-License-Identifier: BSD-3-Clause

add_subdirectory(BaseNXP)
add_subdirectory(Mcu)
add_subdirectory(Rte)
add_subdirectory(Icu)
add_subdirectory_ifdef(CONFIG_ADC_NXP_S32_ADC_SAR Adc)
add_subdirectory_ifdef(CONFIG_MEMC_NXP_S32_QSPI Fls)
if(CONFIG_ETH_NXP_S32_GMAC OR CONFIG_MDIO_NXP_S32_GMAC)
  add_subdirectory(Eth_GMAC)
endif()
add_subdirectory_ifdef(CONFIG_NXP_S32_EMIOS Mcl)
add_subdirectory_ifdef(CONFIG_PWM_NXP_S32_EMIOS Pwm)
