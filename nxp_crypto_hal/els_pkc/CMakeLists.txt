#-------------------------------------------------------------------------------
# Copyright (c) 2023-2024, 2026 NXP.
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

# set path of crypto modules and SDK for zephyr, keep fallback for connectivity unit tests
if(DEFINED ZEPHYR_HAL_NXP_MODULE_DIR)
    set(NXP_MODULE_CRYPTO_PATH ${ZEPHYR_HAL_NXP_MODULE_DIR}/../../crypto)
    set(NXP_MCUX_SDK_PATH ${ZEPHYR_HAL_NXP_MODULE_DIR}/mcux/mcux-sdk)
    # MCXN and RT700 device headers live in the NG SDK tree (mcux-sdk-ng).
    set(NXP_MCUX_SDK_NG_PATH ${ZEPHYR_HAL_NXP_MODULE_DIR}/mcux/mcux-sdk-ng)
else()
    set(NXP_MODULE_CRYPTO_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../../middleware)
    set(NXP_MCUX_SDK_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../..)
    set(NXP_MCUX_SDK_NG_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../..)
endif()

add_library(McuxElsPkc) 

target_compile_options(
    McuxElsPkc
    PUBLIC
        ${TOOLCHAIN_C_FLAGS}
        -mcmse  # Why is this not even part of the default zephyr build options?
)

target_link_options(
    McuxElsPkc
    PRIVATE
        ${TOOLCHAIN_LD_FLAGS}
)

target_include_directories(McuxElsPkc
    PRIVATE
        # SDK driver header files
        ${NXP_MCUX_SDK_PATH}/drivers/common
        # psa/crypto.h and psa/crypto_types.h
        ${NXP_MODULE_CRYPTO_PATH}/mbedtls/include
        ${NXP_MODULE_CRYPTO_PATH}/mbedtls/include/psa
        # for psa driver wrapper
        ${NXP_MODULE_CRYPTO_PATH}/mbedtls/library
)

if(CONFIG_BUILD_WITH_TFM)
    target_compile_options(
        McuxElsPkc
        PUBLIC
            ${COMPILER_CP_FLAG}
    )
endif()

if(CONFIG_SOC_SERIES_RW6XX)

    # Platform sub-directory name used to locate the per-component
    # platform-specific headers under comps/<comp>/inc/platform/<platform>
    # (e.g. mcuxCl*_MemoryConsumption.h). Consumed in src/CMakeLists.txt.
    set(ELS_PKC_PLATFORM rw61x)

    target_compile_definitions(
        McuxElsPkc 
        PUBLIC
            CPU_RW612ETA1I
            CPU_RW612ETA2I
    ) 

    target_include_directories(McuxElsPkc
        PRIVATE
            # cmsis required to build els_pkc (use Zephyr's common CMSIS)
            ${ZEPHYR_CMSIS_MODULE_DIR}/CMSIS/Core/Include
    )

    target_include_directories(McuxElsPkc
        PUBLIC
            ${CMAKE_CURRENT_SOURCE_DIR}/src/platforms/rw61x/
            ${CMAKE_CURRENT_SOURCE_DIR}/src/platforms/rw61x/inc
            # fsl_common.h and related driver headers live in the NG SDK tree
            ${NXP_MCUX_SDK_NG_PATH}/drivers/common
            ${NXP_MCUX_SDK_NG_PATH}/devices/Wireless/RW/periph
            ${NXP_MCUX_SDK_NG_PATH}/devices/Wireless/RW/RW612
            ${NXP_MCUX_SDK_NG_PATH}/devices/Wireless/RW/RW612/drivers
    )

    target_sources(McuxElsPkc
        PRIVATE
            ${NXP_MCUX_SDK_NG_PATH}/devices/Wireless/RW/RW612/drivers/fsl_ocotp.c
            ${CMAKE_CURRENT_SOURCE_DIR}/src/platforms/rw61x/mcux_els.c
            ${CMAKE_CURRENT_SOURCE_DIR}/src/platforms/rw61x/mcux_pkc.c
    )
endif()


if(CONFIG_SOC_FAMILY_MCXN)

    # Platform sub-directory name used to locate the per-component
    # platform-specific headers under comps/<comp>/inc/platform/<platform>
    # (e.g. mcuxCl*_MemoryConsumption.h). Consumed in src/CMakeLists.txt.
    set(ELS_PKC_PLATFORM mcxn)

    # The CPU macro is required by fsl_device_registers.h. The McuxElsPkc
    # library is built standalone (outside the hal_nxp component scope where
    # cpu_define.cmake would normally provide it), so it is set explicitly per
    # SoC here. All part-number variants of a given SoC map to the same device
    # register header, so a single representative CPU macro per SoC is enough.
    if(CONFIG_SOC_MCXN947)
        target_compile_definitions(McuxElsPkc PUBLIC CPU_MCXN947VDF_cm33_core0)
    elseif(CONFIG_SOC_MCXN547)
        target_compile_definitions(McuxElsPkc PUBLIC CPU_MCXN547VDF_cm33_core0)
    elseif(CONFIG_SOC_MCXN236)
        target_compile_definitions(McuxElsPkc PUBLIC CPU_MCXN236VDF)
    endif()

    target_include_directories(McuxElsPkc
        PRIVATE
            # cmsis required to build els_pkc (use Zephyr's common CMSIS)
            ${ZEPHYR_CMSIS_MODULE_DIR}/CMSIS/Core/Include
    )

    target_include_directories(McuxElsPkc
        PUBLIC
            ${CMAKE_CURRENT_SOURCE_DIR}/src/platforms/mcxn/
            ${CMAKE_CURRENT_SOURCE_DIR}/src/platforms/mcxn/inc
            # fsl_common.h and related driver headers live in the NG SDK tree
            ${NXP_MCUX_SDK_NG_PATH}/drivers/common
    )

    if(CONFIG_SOC_MCXN947)
        target_include_directories(McuxElsPkc
            PUBLIC
                ${NXP_MCUX_SDK_NG_PATH}/devices/MCX/MCXN/periph
                ${NXP_MCUX_SDK_NG_PATH}/devices/MCX/MCXN/MCXN947
                ${NXP_MCUX_SDK_NG_PATH}/devices/MCX/MCXN/MCXN947/drivers
        )
    elseif(CONFIG_SOC_MCXN547)
        # MCXN547 has no device drivers/ dir of its own; it reuses the MCXN947
        # drivers (hal_nxp compiles MCXN947/drivers/fsl_clock.c for it). Add the
        # MCXN947 drivers include path so fsl_clock.h (pulled in via
        # fsl_common_arm.h) resolves.
        target_include_directories(McuxElsPkc
            PUBLIC
                ${NXP_MCUX_SDK_NG_PATH}/devices/MCX/MCXN/periph
                ${NXP_MCUX_SDK_NG_PATH}/devices/MCX/MCXN/MCXN547
                ${NXP_MCUX_SDK_NG_PATH}/devices/MCX/MCXN/MCXN947/drivers
        )
    elseif(CONFIG_SOC_MCXN236)
        target_include_directories(McuxElsPkc
            PUBLIC
                ${NXP_MCUX_SDK_NG_PATH}/devices/MCX/MCXN/periph1
                ${NXP_MCUX_SDK_NG_PATH}/devices/MCX/MCXN/MCXN236
                ${NXP_MCUX_SDK_NG_PATH}/devices/MCX/MCXN/MCXN236/drivers
        )
    endif()


    target_sources(McuxElsPkc
        PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/src/platforms/mcxn/mcux_els.c
            ${CMAKE_CURRENT_SOURCE_DIR}/src/platforms/mcxn/mcux_pkc.c
    )
endif()

if(CONFIG_SOC_SERIES_IMXRT7XX)

    # Platform sub-directory name used to locate the per-component
    # platform-specific headers under comps/<comp>/inc/platform/<platform>
    # (e.g. mcuxCl*_MemoryConsumption.h). Consumed in src/CMakeLists.txt.
    set(ELS_PKC_PLATFORM mimxrt)

    target_compile_definitions(McuxElsPkc PUBLIC CPU_MIMXRT798SGFOB_cm33_core0)

    target_include_directories(McuxElsPkc
        PRIVATE
            ${ZEPHYR_CMSIS_MODULE_DIR}/CMSIS/Core/Include
    )

    target_include_directories(McuxElsPkc
        PUBLIC
            ${CMAKE_CURRENT_SOURCE_DIR}/src/platforms/mimxrt/
            ${CMAKE_CURRENT_SOURCE_DIR}/src/platforms/mimxrt/inc
            # fsl_common.h and related driver headers live in the NG SDK tree
            ${NXP_MCUX_SDK_NG_PATH}/drivers/common
            ${NXP_MCUX_SDK_NG_PATH}/devices/RT/RT700/periph
            ${NXP_MCUX_SDK_NG_PATH}/devices/RT/RT700/MIMXRT798S
            ${NXP_MCUX_SDK_NG_PATH}/devices/RT/RT700/MIMXRT798S/drivers
            # mcux_els.c includes fsl_glikey.h
            ${NXP_MCUX_SDK_NG_PATH}/drivers/glikey
    )

    target_sources(McuxElsPkc
        PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/src/platforms/mimxrt/mcux_els.c
            ${CMAKE_CURRENT_SOURCE_DIR}/src/platforms/mimxrt/mcux_pkc.c
    )
endif()


if(CONFIG_EXPORT_MCUX_ELS_PKC_TARGETS)
export(TARGETS McuxElsPkc
    FILE "${CMAKE_CURRENT_BINARY_DIR}/McuxElsPkcTargets.cmake"
    NAMESPACE McuxElsPkc::
)
endif()
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/src)
