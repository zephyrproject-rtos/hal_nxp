# Copyright 2022-2023 NXP
# SPDX-License-Identifier: BSD-3-Clause

zephyr_include_directories(include)

zephyr_library_sources_ifdef(CONFIG_CLOCK_CONTROL_NXP_S32
  src/Clock_Ip.c
  src/Clock_Ip_Data.c
  src/Clock_Ip_Divider.c
  src/Clock_Ip_DividerTrigger.c
  src/Clock_Ip_ExtOsc.c
  src/Clock_Ip_FracDiv.c
  src/Clock_Ip_Frequency.c
  src/Clock_Ip_Gate.c
  src/Clock_Ip_IntOsc.c
  src/Clock_Ip_Irq.c
  src/Clock_Ip_Monitor.c
  src/Clock_Ip_Pll.c
  src/Clock_Ip_ProgFreqSwitch.c
  src/Clock_Ip_Selector.c
  src/Clock_Ip_Specific.c
)
