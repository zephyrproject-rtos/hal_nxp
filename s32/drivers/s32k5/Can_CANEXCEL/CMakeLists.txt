# Copyright 2026 NXP
# SPDX-License-Identifier: BSD-3-Clause

zephyr_include_directories(include)
zephyr_library_sources(src/CanEXCEL_Ip.c)
zephyr_library_sources(src/CanEXCEL_Ip_HwAccess.c)
zephyr_library_sources(src/CanEXCEL_Ip_Irq.c)
