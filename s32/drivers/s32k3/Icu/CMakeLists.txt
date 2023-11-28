# Copyright 2023 NXP
# SPDX-License-Identifier: BSD-3-Clause

zephyr_include_directories(include)

zephyr_library_sources_ifdef(CONFIG_NXP_S32_EIRQ
    src/Siul2_Icu_Ip.c
    src/Siul2_Icu_Ip_Irq.c
)

zephyr_library_sources_ifdef(CONFIG_NXP_S32_WKPU
    src/Wkpu_Ip.c
    src/Wkpu_Ip_Irq.c
)

if ((CONFIG_PWM_NXP_S32_EMIOS AND CONFIG_PWM_CAPTURE) OR CONFIG_QDEC_NXP_S32)
    zephyr_library_sources(
        src/Emios_Icu_Ip.c
        src/Emios_Icu_Ip_Irq.c
    )
endif()
