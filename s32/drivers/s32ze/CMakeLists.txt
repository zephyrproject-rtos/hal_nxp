# Copyright 2022 NXP
# SPDX-License-Identifier: BSD-3-Clause

add_subdirectory(BaseNXP)
add_subdirectory_ifdef(CONFIG_GPIO_S32 Dio)
add_subdirectory_ifdef(CONFIG_EIRQ_S32 Icu)
add_subdirectory(Mcu)
add_subdirectory_ifdef(CONFIG_PINCTRL_S32 Port)
add_subdirectory(Rte)
add_subdirectory_ifdef(CONFIG_UART_S32_LINFLEXD Uart)
