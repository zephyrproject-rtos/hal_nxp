# Copyright 2023 NXP
# SPDX-License-Identifier: BSD-3-Clause

zephyr_include_directories(include)
zephyr_library_sources(src/Gmac_Ip.c)
zephyr_library_sources(src/Gmac_Ip_Hw_Access.c)
zephyr_library_sources(src/Gmac_Ip_Irq.c)
