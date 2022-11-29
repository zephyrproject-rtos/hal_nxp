# Copyright 2022 NXP
# SPDX-License-Identifier: BSD-3-Clause

zephyr_include_directories(include)
zephyr_library_sources(
    src/Mru_Ip.c
    src/Mru_Ip_Irq.c
)
