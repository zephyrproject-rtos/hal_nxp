 #
 # Copyright 2023,2026 NXP
 #
 # SPDX-License-Identifier: BSD-3-Clause
 #

if (CONFIG_PSA_CRYPTO_DRIVER_CAAM)
target_include_directories(
    McuxPsaCryptoDriverCaam
    PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/.
    zephyr/.
)
target_sources(
    McuxPsaCryptoDriverCaam
    PRIVATE
    #baremetal/osal_mutex.c
    #frtos/osal_mutex.c
    zephyr/osal_mutex.c
    zephyr/threading_alt.c
)
endif() # CONFIG_PSA_CRYPTO_DRIVER_CAAM

if(CONFIG_PSA_CRYPTO_DRIVER_DCP)
target_include_directories(
    McuxPsaCryptoDriverDcp
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/.
        #baremetal
        #frtos
        zephyr/.
)

target_sources(
    McuxPsaCryptoDriverDcp
    PRIVATE
        #baremetal/osal_mutex.c
        #frtos/osal_mutex.c
        zephyr/osal_mutex.c
        zephyr/osal_mutex_platform.h
        zephyr/threading_alt.c
)
endif() #CONFIG_PSA_CRYPTO_DRIVER_DCP

if(CONFIG_PSA_CRYPTO_DRIVER_ELE_S2XX)
target_include_directories(
    McuxPsaCryptoDriverEleS2xx
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/.
        zephyr/.
)

target_sources(
    McuxPsaCryptoDriverEleS2xx
    PRIVATE
        zephyr/osal_mutex.c
        zephyr/threading_alt.c
)
endif() # CONFIG_PSA_CRYPTO_DRIVER_ELE_S2XX

if(CONFIG_PSA_CRYPTO_DRIVER_ELE_S4xx)
target_include_directories(
    McuxPsaCryptoDriverEleS4xx
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/.
        #baremetal
        #frtos
        zephyr/.
)

target_sources(
    McuxPsaCryptoDriverEleS4xx
    PRIVATE
        #baremetal/osal_mutex.c
        #frtos/osal_mutex.c
        zephyr/osal_mutex.c
        zephyr/threading_alt.c
)
endif() # CONFIG_PSA_CRYPTO_DRIVER_ELE_S4xx

if(CONFIG_MCUX_PSA_CRYPTO_DRIVER_ELS_PKC)

# There should be option to choode baremetal in cmake. 
#At the moment, using only the TFM config as it 
#requires baremetal build
if(CONFIG_BUILD_WITH_TFM)
target_include_directories(
    McuxPsaCryptoDriverElsPkc
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/baremetal
)
target_sources(
    McuxPsaCryptoDriverElsPkc
    PRIVATE
        baremetal/osal_mutex.c
        baremetal/threading_alt.c
)
else()
target_include_directories(
    McuxPsaCryptoDriverElsPkc
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/.
        zephyr/.
)
target_sources(
    McuxPsaCryptoDriverElsPkc
    PRIVATE
        zephyr/osal_mutex.c
)
endif() # CONFIG_BUILD_WITH_TFM
endif() # CONFIG_PSA_CRYPTO_DRIVER_SGI_PKC OR CONFIG_PSA_CRYPTO_DRIVER_ELS_PKC

if(CONFIG_PSA_CRYPTO_DRIVER_CASPER_HASHCRYPT)
target_include_directories(
    McuxPsaDrvCasperHc
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/.
        zephyr/.
)

target_sources(
    McuxPsaDrvCasperHc
    PRIVATE
        zephyr/osal_mutex.c
)
endif() # CONFIG_PSA_CRYPTO_DRIVER_CASPER_HASHCRYPT

if(CONFIG_PSA_CRYPTO_DRIVER_SGI_PKC)

# There should be option to choode baremetal in cmake. 
#At the moment, using only the TFM config as it 
#requires baremetal build
if(CONFIG_BUILD_WITH_TFM)
target_include_directories(
    McuxPsaCryptoDriverSgiPkc
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/baremetal
)
target_sources(
    McuxPsaCryptoDriverSgiPkc
    PRIVATE
        baremetal/osal_mutex.c
        baremetal/threading_alt.c
)
else()
target_include_directories(
    McuxPsaCryptoDriverSgiPkc
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/.
        zephyr/.
)
target_sources(
    McuxPsaCryptoDriverSgiPkc
    PRIVATE
        zephyr/osal_mutex.c
)
endif() # CONFIG_BUILD_WITH_TFM
endif() # CONFIG_PSA_CRYPTO_DRIVER_SGI_PKC OR CONFIG_PSA_CRYPTO_DRIVER_ELS_PKC
