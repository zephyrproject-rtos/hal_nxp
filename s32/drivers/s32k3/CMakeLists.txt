# Copyright 2023 NXP
# SPDX-License-Identifier: BSD-3-Clause

add_subdirectory(BaseNXP)
add_subdirectory(Mcu)
add_subdirectory(Rte)
add_subdirectory_ifdef(CONFIG_GPIO_NXP_S32 Dio)
add_subdirectory_ifdef(CONFIG_NXP_S32_EIRQ Icu)
add_subdirectory_ifdef(CONFIG_PINCTRL_NXP_S32 Port)
