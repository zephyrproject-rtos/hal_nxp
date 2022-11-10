# Copyright 2022 NXP
# SPDX-License-Identifier: BSD-3-Clause

zephyr_include_directories(include)
zephyr_library_sources(src/CanEXCEL_Ip_HwAccess.c)
zephyr_library_sources(src/CanEXCEL_Ip_Irq.c)
zephyr_library_sources(src/CanEXCEL_Ip.c)
