# Copyright 2024-2025 NXP
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
    )
    mcux_add_include(
        INCLUDES include
    )
endif()

if (CONFIG_MCUX_COMPONENT_driver.conn_fwloader.fw_bin)
    mcux_add_source(
        SOURCES script/fw_bin2c_conv.py
                fw_bin/rw61x_sb_wifi_a2.bin
                fw_bin/rw61x_sb_ble_a2.bin
                fw_bin/rw61x_sb_ble_15d4_combo_a2.bin
                fw_bin/script/wlan_gen_fw_incs.py
                fw_bin/inc/*.inc
                fw_bin/rw61x/rw61x_cpu1.c
                fw_bin/rw61x/rw61x_cpu2.c
    )
    mcux_add_include(
        INCLUDES fw_bin
                 fw_bin/inc
                 fw_bin/rw61x
                 fw_bin/script
    )
endif()

if (CONFIG_MCUX_COMPONENT_driver.conn_fwloader_ns)
    mcux_add_source(
        SOURCES include/fsl_loader.h
    )
    mcux_add_include(
        INCLUDES include
    )
endif()

if (CONFIG_MCUX_COMPONENT_driver.conn_fwloader.monolithic)
    mcux_add_macro(
        CC  "-DgPlatformMonolithicApp_d=1"
        CX  "-DgPlatformMonolithicApp_d=1"
    )

    mcux_add_source(
        BASE_PATH ${SdkRootDirPath}/examples/_boards/${board}
        PREINCLUDE TRUE
        SOURCES monolithic_config.h
    )
endif()
