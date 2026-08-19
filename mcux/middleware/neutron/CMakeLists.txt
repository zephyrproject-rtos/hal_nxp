# SPDX-License-Identifier: Apache-2.0
# Copyright 2026 NXP

set(hal_blobs_dir ${ZEPHYR_HAL_NXP_MODULE_DIR}/zephyr/blobs)

if(CONFIG_NXP_NEUTRON)
    add_library(neutron_driver STATIC IMPORTED GLOBAL)

    if(CONFIG_SOC_SERIES_IMXRT266X)
        set(neutron_driver_lib ${hal_blobs_dir}/neutron/rt2660/libNeutronDriver.a)
        set_target_properties(neutron_driver PROPERTIES IMPORTED_LOCATION ${neutron_driver_lib})

        set(neutron_firmware_elf ${hal_blobs_dir}/neutron/rt2660/NeutronFirmware.elf)

        zephyr_library_named(neutron_firmware)
        zephyr_library_sources(
            ${CMAKE_CURRENT_LIST_DIR}/neutron_firmware.S
            ${CMAKE_CURRENT_LIST_DIR}/neutron_shim.c
        )
        set_property(SOURCE ${CMAKE_CURRENT_LIST_DIR}/neutron_firmware.S PROPERTY LANGUAGE ASM)
        set_source_files_properties(${CMAKE_CURRENT_LIST_DIR}/neutron_firmware.S
            PROPERTIES COMPILE_DEFINITIONS "NEUTRON_FIRMWARE_ELF=\"${neutron_firmware_elf}\""
                       OBJECT_DEPENDS "${neutron_firmware_elf}"
        )
    else()
        add_library(neutron_firmware STATIC IMPORTED GLOBAL)

        if(CONFIG_SOC_MIMXRT798S_CM33_CPU0)
            set_target_properties(neutron_driver PROPERTIES IMPORTED_LOCATION ${hal_blobs_dir}/neutron/rt700/cm33/libNeutronDriver.a)
            set_target_properties(neutron_firmware PROPERTIES IMPORTED_LOCATION ${hal_blobs_dir}/neutron/rt700/cm33/libNeutronFirmware.a)
        elseif(CONFIG_SOC_MCXN947)
            set_target_properties(neutron_driver PROPERTIES IMPORTED_LOCATION ${hal_blobs_dir}/neutron/mcxn/libNeutronDriver.a)
            set_target_properties(neutron_firmware PROPERTIES IMPORTED_LOCATION ${hal_blobs_dir}/neutron/mcxn/libNeutronFirmware.a)
        endif()
    endif()

    if(CONFIG_TFLM_NXP_NEUTRON)
        zephyr_library_named(tflm_nxp_neutron)

        zephyr_library_sources(
            ${CMAKE_CURRENT_LIST_DIR}/tflite-micro/tensorflow/lite/micro/kernels/neutron/neutron.cpp
        )

	target_include_directories(tflm_nxp_neutron PUBLIC
            ${CMAKE_CURRENT_LIST_DIR}/tflite-micro/
            ${CMAKE_CURRENT_LIST_DIR}/include/
        )

        zephyr_library_link_libraries(neutron_driver neutron_firmware)

        target_link_libraries(app PRIVATE tflm_nxp_neutron)
    endif()

    if(CONFIG_SOC_SERIES_IMXRT266X)
        # neutron_firmware is a real Zephyr library (embedded ELF via .incbin) and
        # is already part of the Zephyr link; only the driver needs linking to app.
        target_link_libraries(app PRIVATE neutron_driver)
    else()
        target_link_libraries(app PRIVATE neutron_driver neutron_firmware)
    endif()

endif()
