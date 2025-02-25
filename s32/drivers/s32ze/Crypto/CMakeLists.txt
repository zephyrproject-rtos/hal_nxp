# Copyright 2024 NXP
# SPDX-License-Identifier: BSD-3-Clause

zephyr_include_directories(include)
zephyr_library_sources(
    src/Hse_Ip.c
    src/Mu_Ip_Irq.c
)
