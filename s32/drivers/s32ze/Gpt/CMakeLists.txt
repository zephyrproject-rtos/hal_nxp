# Copyright 2022 NXP
# SPDX-License-Identifier: BSD-3-Clause

zephyr_include_directories(include)
zephyr_library_sources_ifdef(CONFIG_COUNTER_NXP_S32_SYS_TIMER src/Stm_Ip.c)
