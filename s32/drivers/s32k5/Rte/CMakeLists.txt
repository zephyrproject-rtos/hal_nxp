# Copyright 2025-2026 NXP
# SPDX-License-Identifier: BSD-3-Clause

zephyr_include_directories(include)
zephyr_library_sources_ifdef(CONFIG_CLOCK_CONTROL_NXP_S32 src/SchM_Mcu.c)
zephyr_library_sources_ifdef(CONFIG_ADC_NXP_S32_ADC_SAR src/SchM_Adc.c)
zephyr_library_sources(src/SchM_Icu.c)
zephyr_library_sources_ifdef(CONFIG_NXP_S32_EMIOS src/SchM_Mcl.c)
zephyr_library_sources_ifdef(CONFIG_PWM_NXP_S32_EMIOS src/SchM_Pwm.c)
zephyr_library_sources_ifdef(CONFIG_CAN_NXP_S32_CANXL src/SchM_Can_43_CANEXCEL.c)
zephyr_library_sources_ifdef(CONFIG_MEMC_NXP_S32_XSPI src/SchM_Mem_43_EXFLS.c)
