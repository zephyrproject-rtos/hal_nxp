# Copyright 2022 NXP
# SPDX-License-Identifier: BSD-3-Clause

zephyr_include_directories(include)
zephyr_library_sources(src/I3c_Ip.c)
zephyr_library_sources(src/I3c_Ip_Isr.c)