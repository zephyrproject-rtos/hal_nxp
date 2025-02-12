# Copyright 2024 NXP
# SPDX-License-Identifier: BSD-3-Clause

if(NOT CONFIG_BUILD_WITH_TFM)
  if (CONFIG_MCUX_COMPONENT_driver.conn_fwloader)
      mcux_add_source(
          SOURCES fsl_loader.c
                  fsl_loader_utils.c
                  nboot_hal.c
                  life_cycle.c
      )
      mcux_add_include(
          INCLUDES include
      )
  endif()
endif()

if(CONFIG_BUILD_WITH_TFM)
  add_compile_definitions(TFM_PARTITION_LOADER_SERVICE)
endif()

if(CONFIG_USE_component_osa_free_rtos_RW612) 
  include(component_osa_free_rtos_RW612)
endif()

if(CONFIG_USE_component_osa_bm) 
  include(component_osa_bm)
endif()

