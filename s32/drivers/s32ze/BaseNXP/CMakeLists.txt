# Copyright 2022 NXP
# SPDX-License-Identifier: BSD-3-Clause

zephyr_include_directories(header)
zephyr_include_directories(include)
zephyr_library_sources(src/OsIf_Interrupts.c)
zephyr_library_sources(src/OsIf_Timer.c)
zephyr_library_sources(src/OsIf_Timer_System.c)
zephyr_library_sources(src/OsIf_Timer_System_Internal_GenericTimer.c)
zephyr_library_sources(src/OsIf_Timer_System_Internal_Systick.c)
