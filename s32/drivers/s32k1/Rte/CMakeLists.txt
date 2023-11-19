# Copyright 2023 NXP
# SPDX-License-Identifier: BSD-3-Clause

zephyr_include_directories(include)
zephyr_library_sources_ifdef(CONFIG_CLOCK_CONTROL_NXP_S32 src/SchM_Mcu.c)
