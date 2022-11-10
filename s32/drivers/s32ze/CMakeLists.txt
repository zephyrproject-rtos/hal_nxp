# Copyright 2022 NXP
# SPDX-License-Identifier: BSD-3-Clause

add_subdirectory(BaseNXP)
add_subdirectory_ifdef(CONFIG_GPIO_S32 Dio)
add_subdirectory_ifdef(CONFIG_NXP_S32_EIRQ Icu)
add_subdirectory(Mcu)
add_subdirectory_ifdef(CONFIG_PINCTRL_S32 Port)
add_subdirectory(Rte)
add_subdirectory_ifdef(CONFIG_NXP_S32_SPI Spi)
add_subdirectory_ifdef(CONFIG_UART_S32_LINFLEXD Uart)
add_subdirectory_ifdef(CONFIG_COUNTER_NXP_S32_SYS_TIMER Gpt)
add_subdirectory_ifdef(CONFIG_WDT_NXP_S32 Swt)
