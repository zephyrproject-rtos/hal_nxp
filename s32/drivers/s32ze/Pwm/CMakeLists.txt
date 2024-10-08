# Copyright 2024 NXP
# SPDX-License-Identifier: BSD-3-Clause

zephyr_include_directories(include)
zephyr_library_sources(src/Emios_Pwm_Ip.c)
zephyr_library_sources(src/Emios_Pwm_Ip_Irq.c)
