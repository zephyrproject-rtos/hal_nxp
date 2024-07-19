# Copyright 2023 NXP
# SPDX-License-Identifier: BSD-3-Clause

zephyr_include_directories(include)

if ((CONFIG_PWM_NXP_S32_EMIOS AND CONFIG_PWM_CAPTURE) OR CONFIG_QDEC_NXP_S32)
    zephyr_library_sources(
        src/Emios_Icu_Ip.c
        src/Emios_Icu_Ip_Irq.c
    )
endif()
