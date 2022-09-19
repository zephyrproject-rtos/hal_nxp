# Copyright 2022 NXP
# SPDX-License-Identifier: BSD-3-Clause

zephyr_include_directories(include)
zephyr_library_sources_ifdef(CONFIG_GPIO_S32 src/SchM_Dio.c)
zephyr_library_sources_ifdef(CONFIG_EIRQ_S32 src/SchM_Icu.c)
zephyr_library_sources(src/SchM_Mcu.c)
zephyr_library_sources_ifdef(CONFIG_PINCTRL_S32 src/SchM_Port.c)
zephyr_library_sources_ifdef(CONFIG_UART_S32_LINFLEXD src/SchM_Uart.c)
