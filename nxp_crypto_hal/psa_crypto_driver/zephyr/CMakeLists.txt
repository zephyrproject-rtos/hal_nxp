#-------------------------------------------------------------------------------
# Copyright 2024-2026 NXP
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------
set(PSA_CRYPTO_DRIVER_PATH ${CMAKE_CURRENT_LIST_DIR}/../)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

string(TOUPPER ${CONFIG_SOC} MCUX_DEVICE)

if(CONFIG_PSA_CRYPTO_DRIVER_CAAM)
    add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/../ psa_crypto_driver)
    target_link_libraries(app PUBLIC McuxPsaCryptoDriverCaam)
    zephyr_include_directories("$<TARGET_PROPERTY:McuxPsaCryptoDriverCaam,INTERFACE_INCLUDE_DIRECTORIES>")
endif()

if(CONFIG_MCUX_PSA_CRYPTO_DRIVER_ELS_PKC AND NOT CONFIG_BUILD_WITH_TFM)
    add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/../ psa_crypto_driver)
    target_link_libraries(app PUBLIC McuxPsaCryptoDriverElsPkc)
    zephyr_include_directories("$<TARGET_PROPERTY:McuxPsaCryptoDriverElsPkc,INTERFACE_INCLUDE_DIRECTORIES>")
endif()

if(CONFIG_PSA_CRYPTO_DRIVER_DCP)
    add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/../ psa_crypto_driver)
    target_link_libraries(app PUBLIC McuxPsaCryptoDriverDcp)
    zephyr_include_directories("$<TARGET_PROPERTY:McuxPsaCryptoDriverDcp,INTERFACE_INCLUDE_DIRECTORIES>")
endif()

if(CONFIG_PSA_CRYPTO_DRIVER_ELE_S2XX)
    add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/../ psa_crypto_driver)
    target_link_libraries(app PUBLIC McuxPsaCryptoDriverEleS2xx)
    zephyr_include_directories("$<TARGET_PROPERTY:McuxPsaCryptoDriverEleS2xx,INTERFACE_INCLUDE_DIRECTORIES>")
endif()

if(CONFIG_PSA_CRYPTO_DRIVER_ELE_S4xx)
    add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/../ psa_crypto_driver)
    target_link_libraries(app PUBLIC McuxPsaCryptoDriverEleS4xx)
    zephyr_include_directories("$<TARGET_PROPERTY:McuxPsaCryptoDriverEleS4xx,INTERFACE_INCLUDE_DIRECTORIES>")
endif()

if(CONFIG_PSA_CRYPTO_DRIVER_SGI_PKC)

    # if the build is for tfm, then, pass HW accelration presense config to tfm build system
    if(CONFIG_BUILD_WITH_TFM)
        set_property(TARGET zephyr_property_target
            APPEND PROPERTY TFM_CMAKE_OPTIONS
            -DCRYPTO_HW_ACCELERATOR=ON
        )
    else()
        add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/../ psa_crypto_driver)
        target_link_libraries(app PUBLIC McuxPsaCryptoDriverSgiPkc)
        zephyr_include_directories("$<TARGET_PROPERTY:McuxPsaCryptoDriverSgiPkc,INTERFACE_INCLUDE_DIRECTORIES>")
    endif()
endif()

if(CONFIG_PSA_CRYPTO_DRIVER_CASPER_HASHCRYPT)
    add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/../ psa_crypto_driver)
    target_link_libraries(app PUBLIC McuxPsaDrvCasperHc)
    zephyr_include_directories("$<TARGET_PROPERTY:McuxPsaDrvCasperHc,INTERFACE_INCLUDE_DIRECTORIES>")
endif()
