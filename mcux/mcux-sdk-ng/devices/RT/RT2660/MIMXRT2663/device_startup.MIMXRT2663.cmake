# Copyright 2026 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

# Add set(CONFIG_USE_device_startup true) in config.cmake to use this component

include_guard(GLOBAL)
message("${CMAKE_CURRENT_LIST_FILE} component is included.")

      if((CONFIG_TOOLCHAIN STREQUAL iar OR CONFIG_TOOLCHAIN STREQUAL armgcc OR CONFIG_TOOLCHAIN STREQUAL mdk))
          add_config_file(${CMAKE_CURRENT_LIST_DIR}/startup_MIMXRT2663.c "" device_startup.MIMXRT2663)
        endif()

  

