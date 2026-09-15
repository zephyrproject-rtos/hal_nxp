# Copyright 2026 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

# Add set(CONFIG_USE_driver_power true) in config.cmake to use this component

include_guard(GLOBAL)
message("${CMAKE_CURRENT_LIST_FILE} component is included.")

      target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
          ${CMAKE_CURRENT_LIST_DIR}/fsl_power.c
        )

  
      target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
          ${CMAKE_CURRENT_LIST_DIR}/devices/RT/RT2660/MIMXRT2663/drivers
          ${CMAKE_CURRENT_LIST_DIR}/../../../../../drivers/powercon
          ${CMAKE_CURRENT_LIST_DIR}/../../../../../drivers/pdcon
          ${CMAKE_CURRENT_LIST_DIR}/../../../../../drivers/rt2k_pmu
        )

  
