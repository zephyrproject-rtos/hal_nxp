# Copyright 2023 NXP
# SPDX-License-Identifier: BSD-3-Clause

zephyr_include_directories(include)
zephyr_library_sources(src/Emios_Mcl_Ip.c)
zephyr_library_sources(src/Emios_Mcl_Ip_Irq.c)

if (CONFIG_QDEC_NXP_S32)
    zephyr_library_sources(src/Trgmux_Ip.c)
    zephyr_library_sources(src/Trgmux_Ip_HwAcc.c)
    zephyr_library_sources(src/Lcu_Ip.c)
    zephyr_library_sources(src/Lcu_Ip_Hw_Access.c)
endif()
