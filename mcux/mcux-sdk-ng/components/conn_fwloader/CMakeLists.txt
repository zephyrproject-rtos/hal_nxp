# Copyright 2024 NXP
# SPDX-License-Identifier: BSD-3-Clause

if (CONFIG_MCUX_COMPONENT_driver.conn_fwloader)
    mcux_add_source(
        SOURCES include/api_tree_root.h
                include/fsl_loader.h
                include/fsl_loader_utils.h
                include/fusemap.h
                include/life_cycle.h
                include/nboot_rom_api_table.h
                fsl_loader.c
                fsl_loader_utils.c
                nboot_hal.c
                life_cycle.c
                readme.txt
                script/fw_bin2c_conv.py
    )
    mcux_add_include(
        INCLUDES include
    )
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

