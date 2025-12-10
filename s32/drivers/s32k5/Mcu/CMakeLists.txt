# Copyright 2025 NXP
# SPDX-License-Identifier: BSD-3-Clause

zephyr_include_directories(include)
zephyr_library_sources(src/Clock_Ip.c)
zephyr_library_sources(src/Clock_Ip_Data.c)
zephyr_library_sources(src/Clock_Ip_Divider.c)
zephyr_library_sources(src/Clock_Ip_ExtOsc.c)
zephyr_library_sources(src/Clock_Ip_FracDiv.c)
zephyr_library_sources(src/Clock_Ip_Frequency.c)
zephyr_library_sources(src/Clock_Ip_Gate.c)
zephyr_library_sources(src/Clock_Ip_Irq.c)
zephyr_library_sources(src/Clock_Ip_Monitor.c)
zephyr_library_sources(src/Clock_Ip_Pll.c)
zephyr_library_sources(src/Clock_Ip_RegisterProtocol.c)
zephyr_library_sources(src/Clock_Ip_Selector.c)
zephyr_library_sources(src/Clock_Ip_Specific.c)
