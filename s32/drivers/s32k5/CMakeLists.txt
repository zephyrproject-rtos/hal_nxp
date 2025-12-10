# Copyright 2025 NXP
# SPDX-License-Identifier: BSD-3-Clause

add_subdirectory(BaseNXP)
add_subdirectory(Mcu)
add_subdirectory(Platform)
add_subdirectory(Rte)
add_subdirectory_ifdef(CONFIG_ADC_NXP_S32_ADC_SAR Adc)
add_subdirectory_ifdef(CONFIG_PWM_NXP_S32_EMIOS Icu)
add_subdirectory_ifdef(CONFIG_NXP_S32_EMIOS Mcl)
add_subdirectory_ifdef(CONFIG_PWM_NXP_S32_EMIOS Pwm)