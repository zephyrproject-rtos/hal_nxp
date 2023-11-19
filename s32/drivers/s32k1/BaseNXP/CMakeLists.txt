# Copyright 2023 NXP
# SPDX-License-Identifier: BSD-3-Clause

zephyr_include_directories(header include)
zephyr_library_sources(
  src/OsIf_Interrupts.c
  src/OsIf_Timer.c
  src/OsIf_Timer_System.c
  src/OsIf_Timer_System_Internal_Systick.c
)
