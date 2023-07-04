# Copyright 2023 NXP
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

zephyr_library_sources(
  src/Power_Ip.c
  src/Power_Ip_AEC.c
  src/Power_Ip_CortexM7.c
  src/Power_Ip_DCM_GPR.c
  src/Power_Ip_FLASH.c
  src/Power_Ip_MC_ME.c
  src/Power_Ip_MC_RGM.c
  src/Power_Ip_MC_RGM_Irq.c
  src/Power_Ip_PMC.c
  src/Power_Ip_PMC_Irq.c
  src/Power_Ip_Private.c
)
