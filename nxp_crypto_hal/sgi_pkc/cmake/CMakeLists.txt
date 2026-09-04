#---------------------------------------------
# Copyright 2026 NXP.
# SPDX-License-Identifier: BSD-3-Clause
#---------------------------------------------

if(TARGET McuxSgiPkc)
  message(STATUS "SGI_PKC: McuxSgiPkc already defined, skipping re-definition")
  return()
endif()

if(CONFIG_SGI_PKC)

# Set base path for the SGI PKC component
set(SGI_PKC_BASE ${CMAKE_CURRENT_LIST_DIR}/../)

# Create single library for all SGI PKC components
add_library(McuxSgiPkc)

if(CONFIG_BUILD_WITH_TFM)
include(${CMAKE_CURRENT_LIST_DIR}/tfm.cmake)
else()
target_link_libraries(McuxSgiPkc PRIVATE zephyr_interface)
endif()

# Common include directories - always added and visible globally
target_include_directories(McuxSgiPkc PUBLIC
    ${SGI_PKC_BASE}/includes
    ${SGI_PKC_BASE}/src/inc
    ${SGI_PKC_BASE}/src/compiler
)

# Platform MCXA
if(CONFIG_SGI_PKC_PLATFORM_MCXA)
    target_sources(McuxSgiPkc PRIVATE
        ${SGI_PKC_BASE}/src/platforms/mcxa/mcux_sgi.c
        ${SGI_PKC_BASE}/src/platforms/mcxa/mcux_pkc.c
    )
    target_include_directories(McuxSgiPkc PUBLIC
        ${SGI_PKC_BASE}/src/platforms/mcxa
        ${SGI_PKC_BASE}/src/platforms/mcxa/inc
        ${SGI_PKC_BASE}/src/comps/mcuxClAeadModes/inc/platform/mcxa2xx
        ${SGI_PKC_BASE}/src/comps/mcuxClCipherModes/inc/platform/mcxa2xx
        ${SGI_PKC_BASE}/src/comps/mcuxClEcc/inc/platform/mcxa2xx
        ${SGI_PKC_BASE}/src/comps/mcuxClFfdh/inc/platform/mcxa2xx
        ${SGI_PKC_BASE}/src/comps/mcuxClHash/inc/platform/mcxa2xx
        ${SGI_PKC_BASE}/src/comps/mcuxClHashModes/inc/platform/mcxa2xx
        ${SGI_PKC_BASE}/src/comps/mcuxClHmac/inc/platform/mcxa2xx
        ${SGI_PKC_BASE}/src/comps/mcuxClKey/inc/platform/mcxa2xx
        ${SGI_PKC_BASE}/src/comps/mcuxClMacModes/inc/platform/mcxa2xx
        ${SGI_PKC_BASE}/src/comps/mcuxClRandomModes/inc/platform/mcxa2xx
        ${SGI_PKC_BASE}/src/comps/mcuxClResource/inc/platform/mcxa2xx
        ${SGI_PKC_BASE}/src/comps/mcuxClRsa/inc/platform/mcxa2xx
        ${SGI_PKC_BASE}/src/comps/mcuxClSession/inc/platform/mcxa2xx
        ${SGI_PKC_BASE}/src/comps/mcuxClSignature/inc/platform/mcxa2xx
        ${SGI_PKC_BASE}/src/comps/mcuxCsslMemory/inc/platform/mcxa2xx
        ${SGI_PKC_BASE}/src/comps/mcuxCsslPrng/inc/platform/mcxa2xx

    )
endif()

# Platform MCXA5
if(CONFIG_SGI_PKC_PLATFORM_MCXA5)
    target_sources(McuxSgiPkc PRIVATE
        ${SGI_PKC_BASE}/src/platforms/mcxa5/mcux_sgi.c
        ${SGI_PKC_BASE}/src/platforms/mcxa5/mcux_pkc.c
    )
    target_include_directories(McuxSgiPkc PUBLIC
        ${SGI_PKC_BASE}/src/platforms/mcxa5
        ${SGI_PKC_BASE}/src/platforms/mcxa5/inc
        ${SGI_PKC_BASE}/src/comps/mcuxClAeadModes/inc/platform/mcxa5xx
        ${SGI_PKC_BASE}/src/comps/mcuxClCipherModes/inc/platform/mcxa5xx
        ${SGI_PKC_BASE}/src/comps/mcuxClEcc/inc/platform/mcxa5xx
        ${SGI_PKC_BASE}/src/comps/mcuxClHash/inc/platform/mcxa5xx
        ${SGI_PKC_BASE}/src/comps/mcuxClHashModes/inc/platform/mcxa5xx
        ${SGI_PKC_BASE}/src/comps/mcuxClHmac/inc/platform/mcxa5xx
        ${SGI_PKC_BASE}/src/comps/mcuxClKey/inc/platform/mcxa5xx
        ${SGI_PKC_BASE}/src/comps/mcuxClMacModes/inc/platform/mcxa5xx
        ${SGI_PKC_BASE}/src/comps/mcuxClRandomModes/inc/platform/mcxa5xx
        ${SGI_PKC_BASE}/src/comps/mcuxClResource/inc/platform/mcxa5xx
        ${SGI_PKC_BASE}/src/comps/mcuxClRsa/inc/platform/mcxa5xx
        ${SGI_PKC_BASE}/src/comps/mcuxClSession/inc/platform/mcxa5xx
        ${SGI_PKC_BASE}/src/comps/mcuxClSignature/inc/platform/mcxa5xx
        ${SGI_PKC_BASE}/src/comps/mcuxCsslMemory/inc/platform/mcxa5xx
        ${SGI_PKC_BASE}/src/comps/mcuxCsslPrng/inc/platform/mcxa5xx
        ${SGI_PKC_BASE}/src/comps/mcuxClKdfModes/inc/platform/mcxa5xx
        ${SGI_PKC_BASE}/src/comps/mcuxClXofModes/inc/platform/mcxa5xx

    )
endif()

# Platform MCXL
if(CONFIG_SGI_PKC_PLATFORM_MCXL)
    target_sources(McuxSgiPkc PRIVATE
        ${SGI_PKC_BASE}/src/platforms/mcxl/mcux_sgi.c
        ${SGI_PKC_BASE}/src/platforms/mcxl/mcux_pkc.c
    )
    target_include_directories(McuxSgiPkc PUBLIC
        ${SGI_PKC_BASE}/src/platforms/mcxl
        ${SGI_PKC_BASE}/src/platforms/mcxl/inc
        ${SGI_PKC_BASE}/src/comps/mcuxClAeadModes/inc/platform/mcxl2xx
        ${SGI_PKC_BASE}/src/comps/mcuxClCipherModes/inc/platform/mcxl2xx
        ${SGI_PKC_BASE}/src/comps/mcuxClEcc/inc/platform/mcxl2xx
        ${SGI_PKC_BASE}/src/comps/mcuxClHash/inc/platform/mcxl2xx
        ${SGI_PKC_BASE}/src/comps/mcuxClHashModes/inc/platform/mcxl2xx
        ${SGI_PKC_BASE}/src/comps/mcuxClHmac/inc/platform/mcxl2xx
        ${SGI_PKC_BASE}/src/comps/mcuxClKey/inc/platform/mcxl2xx
        ${SGI_PKC_BASE}/src/comps/mcuxClMacModes/inc/platform/mcxl2xx
        ${SGI_PKC_BASE}/src/comps/mcuxClRandomModes/inc/platform/mcxl2xx
        ${SGI_PKC_BASE}/src/comps/mcuxClResource/inc/platform/mcxl2xx
        ${SGI_PKC_BASE}/src/comps/mcuxClRsa/inc/platform/mcxl2xx
        ${SGI_PKC_BASE}/src/comps/mcuxClSession/inc/platform/mcxl2xx
        ${SGI_PKC_BASE}/src/comps/mcuxClSignature/inc/platform/mcxl2xx
        ${SGI_PKC_BASE}/src/comps/mcuxCsslMemory/inc/platform/mcxl2xx
        ${SGI_PKC_BASE}/src/comps/mcuxCsslPrng/inc/platform/mcxl2xx
    )
endif()

# Platform MCXW
if(CONFIG_SGI_PKC_PLATFORM_MCXW)
    target_sources(McuxSgiPkc PRIVATE
        ${SGI_PKC_BASE}/src/platforms/mcxw/mcux_sgi.c
        ${SGI_PKC_BASE}/src/platforms/mcxw/mcux_pkc.c
    )
    target_include_directories(McuxSgiPkc PUBLIC
        ${SGI_PKC_BASE}/src/platforms/mcxw
        ${SGI_PKC_BASE}/src/platforms/mcxw/inc
        ${SGI_PKC_BASE}/src/comps/mcuxClAeadModes/inc/platform/mcxw7x
        ${SGI_PKC_BASE}/src/comps/mcuxClCipherModes/inc/platform/mcxw7x
        ${SGI_PKC_BASE}/src/comps/mcuxClEcc/inc/platform/mcxw7x
        ${SGI_PKC_BASE}/src/comps/mcuxClHash/inc/platform/mcxw7x
        ${SGI_PKC_BASE}/src/comps/mcuxClHashModes/inc/platform/mcxw7x
        ${SGI_PKC_BASE}/src/comps/mcuxClHmac/inc/platform/mcxw7x
        ${SGI_PKC_BASE}/src/comps/mcuxClKdfModes/inc/platform/mcxw7x
        ${SGI_PKC_BASE}/src/comps/mcuxClKey/inc/platform/mcxw7x
        ${SGI_PKC_BASE}/src/comps/mcuxClMacModes/inc/platform/mcxw7x
        ${SGI_PKC_BASE}/src/comps/mcuxClRandomModes/inc/platform/mcxw7x
        ${SGI_PKC_BASE}/src/comps/mcuxClResource/inc/platform/mcxw7x
        ${SGI_PKC_BASE}/src/comps/mcuxClRsa/inc/platform/mcxw7x
        ${SGI_PKC_BASE}/src/comps/mcuxClSession/inc/platform/mcxw7x
        ${SGI_PKC_BASE}/src/comps/mcuxClSignature/inc/platform/mcxw7x
        ${SGI_PKC_BASE}/src/comps/mcuxClXofModes/inc/platform/mcxw7x
        ${SGI_PKC_BASE}/src/comps/mcuxCsslMemory/inc/platform/mcxw7x
        ${SGI_PKC_BASE}/src/comps/mcuxCsslPrng/inc/platform/mcxw7x
    )
endif()

# Core component
if(CONFIG_SGI_PKC_CORE)
    target_include_directories(McuxSgiPkc PUBLIC ${SGI_PKC_BASE}/src/comps/mcuxClCore/inc)
endif()

# AEAD component
if(CONFIG_SGI_PKC_AEAD)
    file(GLOB_RECURSE AEAD_SOURCES ${SGI_PKC_BASE}/src/comps/mcuxClAead/src/*.c)
    if(AEAD_SOURCES)
        target_sources(McuxSgiPkc PRIVATE ${AEAD_SOURCES})
    endif()
    target_include_directories(McuxSgiPkc PUBLIC 
        ${SGI_PKC_BASE}/src/comps/mcuxClAead/inc
        ${SGI_PKC_BASE}/src/comps/mcuxClAead/inc/internal
    )
endif()

# AEAD Modes component
if(CONFIG_SGI_PKC_AEAD_MODES)
    file(GLOB_RECURSE AEAD_MODES_SOURCES ${SGI_PKC_BASE}/src/comps/mcuxClAeadModes/src/*.c)
    if(AEAD_MODES_SOURCES)
        target_sources(McuxSgiPkc PRIVATE ${AEAD_MODES_SOURCES})
    endif()
    target_include_directories(McuxSgiPkc PUBLIC 
        ${SGI_PKC_BASE}/src/comps/mcuxClAeadModes/inc
        ${SGI_PKC_BASE}/src/comps/mcuxClAeadModes/inc/internal
    )
endif()

# AES component
if(CONFIG_SGI_PKC_AES)
    file(GLOB_RECURSE AES_SOURCES ${SGI_PKC_BASE}/src/comps/mcuxClAes/src/*.c)
    if(AES_SOURCES)
        target_sources(McuxSgiPkc PRIVATE ${AES_SOURCES})
    endif()
    target_include_directories(McuxSgiPkc PUBLIC 
        ${SGI_PKC_BASE}/src/comps/mcuxClAes/inc
        ${SGI_PKC_BASE}/src/comps/mcuxClAes/inc/internal
    )
endif()

# Buffer component
if(CONFIG_SGI_PKC_BUFFER)
    file(GLOB_RECURSE BUFFER_SOURCES ${SGI_PKC_BASE}/src/comps/mcuxClBuffer/src/*.c)
    if(BUFFER_SOURCES)
        target_sources(McuxSgiPkc PRIVATE ${BUFFER_SOURCES})
    endif()
    target_include_directories(McuxSgiPkc PUBLIC 
        ${SGI_PKC_BASE}/src/comps/mcuxClBuffer/inc
        ${SGI_PKC_BASE}/src/comps/mcuxClBuffer/inc/internal
    )
endif()

# Cipher component
if(CONFIG_SGI_PKC_CIPHER)
    file(GLOB_RECURSE CIPHER_SOURCES ${SGI_PKC_BASE}/src/comps/mcuxClCipher/src/*.c)
    if(CIPHER_SOURCES)
        target_sources(McuxSgiPkc PRIVATE ${CIPHER_SOURCES})
    endif()
    target_include_directories(McuxSgiPkc PUBLIC 
        ${SGI_PKC_BASE}/src/comps/mcuxClCipher/inc
        ${SGI_PKC_BASE}/src/comps/mcuxClCipher/inc/internal
    )
endif()

# Cipher Modes component
if(CONFIG_SGI_PKC_CIPHER_MODES)
    file(GLOB_RECURSE CIPHER_MODES_SOURCES ${SGI_PKC_BASE}/src/comps/mcuxClCipherModes/src/*.c)
    if(CIPHER_MODES_SOURCES)
        target_sources(McuxSgiPkc PRIVATE ${CIPHER_MODES_SOURCES})
    endif()
    target_include_directories(McuxSgiPkc PUBLIC 
        ${SGI_PKC_BASE}/src/comps/mcuxClCipherModes/inc
        ${SGI_PKC_BASE}/src/comps/mcuxClCipherModes/inc/internal
    )
endif()

# CRC component
if(CONFIG_SGI_PKC_CRC)
    file(GLOB_RECURSE CRC_SOURCES ${SGI_PKC_BASE}/src/comps/mcuxClCrc/src/*.c)
    if(CRC_SOURCES)
        target_sources(McuxSgiPkc PRIVATE ${CRC_SOURCES})
    endif()
    target_include_directories(McuxSgiPkc PUBLIC 
        ${SGI_PKC_BASE}/src/comps/mcuxClCrc/inc
        ${SGI_PKC_BASE}/src/comps/mcuxClCrc/inc/internal
    )
endif()

# DMA component
if(CONFIG_SGI_PKC_DMA)
    file(GLOB_RECURSE DMA_SOURCES ${SGI_PKC_BASE}/src/comps/mcuxClDma/src/*.c)
    if(DMA_SOURCES)
        target_sources(McuxSgiPkc PRIVATE ${DMA_SOURCES})
    endif()
    target_include_directories(McuxSgiPkc PUBLIC 
        ${SGI_PKC_BASE}/src/comps/mcuxClDma/inc
        ${SGI_PKC_BASE}/src/comps/mcuxClDma/inc/internal
    )
endif()

# ECC component
if(CONFIG_SGI_PKC_ECC)
    file(GLOB_RECURSE ECC_SOURCES ${SGI_PKC_BASE}/src/comps/mcuxClEcc/src/*.c)
    if(ECC_SOURCES)
        target_sources(McuxSgiPkc PRIVATE ${ECC_SOURCES})
    endif()
    target_include_directories(McuxSgiPkc PUBLIC 
        ${SGI_PKC_BASE}/src/comps/mcuxClEcc/inc
        ${SGI_PKC_BASE}/src/comps/mcuxClEcc/inc/internal
    )
endif()

# FFDH component
if(CONFIG_SGI_PKC_FFDH)
    file(GLOB_RECURSE FFDH_SOURCES ${SGI_PKC_BASE}/src/comps/mcuxClFfdh/src/*.c)
    if(FFDH_SOURCES)
        target_sources(McuxSgiPkc PRIVATE ${FFDH_SOURCES})
    endif()
    target_include_directories(McuxSgiPkc PUBLIC 
        ${SGI_PKC_BASE}/src/comps/mcuxClFfdh/inc
        ${SGI_PKC_BASE}/src/comps/mcuxClFfdh/inc/internal
    )
endif()

# Glikey component
if(CONFIG_SGI_PKC_GLIKEY)
    file(GLOB_RECURSE GLIKEY_SOURCES ${SGI_PKC_BASE}/src/comps/mcuxClGlikey/src/*.c)
    if(GLIKEY_SOURCES)
        target_sources(McuxSgiPkc PRIVATE ${GLIKEY_SOURCES})
    endif()
    target_include_directories(McuxSgiPkc PUBLIC 
        ${SGI_PKC_BASE}/src/comps/mcuxClGlikey/inc
        ${SGI_PKC_BASE}/src/comps/mcuxClGlikey/inc/internal
    )
endif()

# Hash component
if(CONFIG_SGI_PKC_HASH)
    file(GLOB_RECURSE HASH_SOURCES ${SGI_PKC_BASE}/src/comps/mcuxClHash/src/*.c)
    if(HASH_SOURCES)
        target_sources(McuxSgiPkc PRIVATE ${HASH_SOURCES})
    endif()
    target_include_directories(McuxSgiPkc PUBLIC 
        ${SGI_PKC_BASE}/src/comps/mcuxClHash/inc
        ${SGI_PKC_BASE}/src/comps/mcuxClHash/inc/internal
    )
endif()

# Hash Modes component
if(CONFIG_SGI_PKC_HASHMODES)
    file(GLOB_RECURSE HASHMODES_SOURCES ${SGI_PKC_BASE}/src/comps/mcuxClHashModes/src/*.c)
    if(HASHMODES_SOURCES)
        target_sources(McuxSgiPkc PRIVATE ${HASHMODES_SOURCES})
    endif()
    target_include_directories(McuxSgiPkc PUBLIC 
        ${SGI_PKC_BASE}/src/comps/mcuxClHashModes/inc
        ${SGI_PKC_BASE}/src/comps/mcuxClHashModes/inc/internal
    )
endif()

# HMAC component
if(CONFIG_SGI_PKC_HMAC)
    file(GLOB_RECURSE HMAC_SOURCES ${SGI_PKC_BASE}/src/comps/mcuxClHmac/src/*.c)
    if(HMAC_SOURCES)
        target_sources(McuxSgiPkc PRIVATE ${HMAC_SOURCES})
    endif()
    target_include_directories(McuxSgiPkc PUBLIC 
        ${SGI_PKC_BASE}/src/comps/mcuxClHmac/inc
        ${SGI_PKC_BASE}/src/comps/mcuxClHmac/inc/internal
    )
endif()

# Key component
if(CONFIG_SGI_PKC_KEY)
    file(GLOB_RECURSE KEY_SOURCES ${SGI_PKC_BASE}/src/comps/mcuxClKey/src/*.c)
    if(KEY_SOURCES)
        target_sources(McuxSgiPkc PRIVATE ${KEY_SOURCES})
    endif()
    target_include_directories(McuxSgiPkc PUBLIC 
        ${SGI_PKC_BASE}/src/comps/mcuxClKey/inc
        ${SGI_PKC_BASE}/src/comps/mcuxClKey/inc/internal
    )
endif()

# MAC component
if(CONFIG_SGI_PKC_MAC)
    file(GLOB_RECURSE MAC_SOURCES ${SGI_PKC_BASE}/src/comps/mcuxClMac/src/*.c)
    if(MAC_SOURCES)
        target_sources(McuxSgiPkc PRIVATE ${MAC_SOURCES})
    endif()
    target_include_directories(McuxSgiPkc PUBLIC 
        ${SGI_PKC_BASE}/src/comps/mcuxClMac/inc
        ${SGI_PKC_BASE}/src/comps/mcuxClMac/inc/internal
    )
endif()

# MAC Modes component
if(CONFIG_SGI_PKC_MAC_MODES)
    file(GLOB_RECURSE MAC_MODES_SOURCES ${SGI_PKC_BASE}/src/comps/mcuxClMacModes/src/*.c)
    if(MAC_MODES_SOURCES)
        target_sources(McuxSgiPkc PRIVATE ${MAC_MODES_SOURCES})
    endif()
    target_include_directories(McuxSgiPkc PUBLIC 
        ${SGI_PKC_BASE}/src/comps/mcuxClMacModes/inc
        ${SGI_PKC_BASE}/src/comps/mcuxClMacModes/inc/internal
    )
endif()

# Math component
if(CONFIG_SGI_PKC_MATH)
    file(GLOB_RECURSE MATH_SOURCES ${SGI_PKC_BASE}/src/comps/mcuxClMath/src/*.c)
    if(MATH_SOURCES)
        target_sources(McuxSgiPkc PRIVATE ${MATH_SOURCES})
    endif()
    target_include_directories(McuxSgiPkc PUBLIC 
        ${SGI_PKC_BASE}/src/comps/mcuxClMath/inc
        ${SGI_PKC_BASE}/src/comps/mcuxClMath/inc/internal
    )
endif()

# Memory component
if(CONFIG_SGI_PKC_MEMORY)
    file(GLOB_RECURSE MEMORY_C_SOURCES ${SGI_PKC_BASE}/src/comps/mcuxClMemory/src/*.c)
    file(GLOB_RECURSE CSSL_MEMORY_C_SOURCES ${SGI_PKC_BASE}/src/comps/mcuxCsslMemory/src/*.c)
    file(GLOB_RECURSE CSSL_MEMORY_ASM_SOURCES ${SGI_PKC_BASE}/src/comps/mcuxCsslMemory/src/asm/*.S)
    
    set(MEMORY_SOURCES ${MEMORY_C_SOURCES} ${CSSL_MEMORY_C_SOURCES} ${CSSL_MEMORY_ASM_SOURCES})
    if(MEMORY_SOURCES)
        target_sources(McuxSgiPkc PRIVATE ${MEMORY_SOURCES})
    endif()
    target_include_directories(McuxSgiPkc PUBLIC 
        ${SGI_PKC_BASE}/src/comps/mcuxClMemory/inc
        ${SGI_PKC_BASE}/src/comps/mcuxClMemory/inc/internal
        ${SGI_PKC_BASE}/src/comps/mcuxCsslMemory/inc
        ${SGI_PKC_BASE}/src/comps/mcuxCsslMemory/inc/internal
    )
endif()

# Padding component
if(CONFIG_SGI_PKC_PADDING)
    file(GLOB_RECURSE PADDING_SOURCES ${SGI_PKC_BASE}/src/comps/mcuxClPadding/src/*.c)
    if(PADDING_SOURCES)
        target_sources(McuxSgiPkc PRIVATE ${PADDING_SOURCES})
    endif()
    target_include_directories(McuxSgiPkc PUBLIC 
        ${SGI_PKC_BASE}/src/comps/mcuxClPadding/inc
        ${SGI_PKC_BASE}/src/comps/mcuxClPadding/inc/internal
    )
endif()

# PKC component
if(CONFIG_SGI_PKC_PKC)
    file(GLOB_RECURSE PKC_SOURCES ${SGI_PKC_BASE}/src/comps/mcuxClPkc/src/*.c)
    if(PKC_SOURCES)
        target_sources(McuxSgiPkc PRIVATE ${PKC_SOURCES})
    endif()
    target_include_directories(McuxSgiPkc PUBLIC 
        ${SGI_PKC_BASE}/src/comps/mcuxClPkc/inc
        ${SGI_PKC_BASE}/src/comps/mcuxClPkc/inc/internal
    )
endif()

# PRNG component
if(CONFIG_SGI_PKC_PRNG)
    file(GLOB_RECURSE PRNG_SOURCES ${SGI_PKC_BASE}/src/comps/mcuxClPrng/src/*.c)
    if(PRNG_SOURCES)
        target_sources(McuxSgiPkc PRIVATE ${PRNG_SOURCES})
    endif()
    target_include_directories(McuxSgiPkc PUBLIC 
        ${SGI_PKC_BASE}/src/comps/mcuxClPrng/inc
        ${SGI_PKC_BASE}/src/comps/mcuxClPrng/inc/internal
    )
endif()

# Random component
if(CONFIG_SGI_PKC_RANDOM)
    file(GLOB_RECURSE RANDOM_SOURCES ${SGI_PKC_BASE}/src/comps/mcuxClRandom/src/*.c)
    if(RANDOM_SOURCES)
        target_sources(McuxSgiPkc PRIVATE ${RANDOM_SOURCES})
    endif()
    target_include_directories(McuxSgiPkc PUBLIC 
        ${SGI_PKC_BASE}/src/comps/mcuxClRandom/inc
        ${SGI_PKC_BASE}/src/comps/mcuxClRandom/inc/internal
    )
endif()

# Random Modes component
if(CONFIG_SGI_PKC_RANDOM_MODES)
    file(GLOB_RECURSE RANDOM_MODES_SOURCES ${SGI_PKC_BASE}/src/comps/mcuxClRandomModes/src/*.c)
    if(RANDOM_MODES_SOURCES)
        target_sources(McuxSgiPkc PRIVATE ${RANDOM_MODES_SOURCES})
    endif()
    target_include_directories(McuxSgiPkc PUBLIC 
        ${SGI_PKC_BASE}/src/comps/mcuxClRandomModes/inc
        ${SGI_PKC_BASE}/src/comps/mcuxClRandomModes/inc/internal
    )
endif()

# Resource component
if(CONFIG_SGI_PKC_RESOURCE)
    file(GLOB_RECURSE RESOURCE_SOURCES ${SGI_PKC_BASE}/src/comps/mcuxClResource/src/*.c)
    if(RESOURCE_SOURCES)
        target_sources(McuxSgiPkc PRIVATE ${RESOURCE_SOURCES})
    endif()
    target_include_directories(McuxSgiPkc PUBLIC 
        ${SGI_PKC_BASE}/src/comps/mcuxClResource/inc
        ${SGI_PKC_BASE}/src/comps/mcuxClResource/inc/internal
    )
endif()

# RSA component
if(CONFIG_SGI_PKC_RSA)
    file(GLOB_RECURSE RSA_SOURCES ${SGI_PKC_BASE}/src/comps/mcuxClRsa/src/*.c)
    if(RSA_SOURCES)
        target_sources(McuxSgiPkc PRIVATE ${RSA_SOURCES})
    endif()
    target_include_directories(McuxSgiPkc PUBLIC 
        ${SGI_PKC_BASE}/src/comps/mcuxClRsa/inc
        ${SGI_PKC_BASE}/src/comps/mcuxClRsa/inc/internal
    )
endif()

# Session component
if(CONFIG_SGI_PKC_SESSION)
    file(GLOB_RECURSE SESSION_C_SOURCES ${SGI_PKC_BASE}/src/comps/mcuxClSession/src/*.c)
    file(GLOB_RECURSE SESSION_ASM_SOURCES ${SGI_PKC_BASE}/src/comps/mcuxClSession/src/asm/*.S)
    
    set(SESSION_SOURCES ${SESSION_C_SOURCES} ${SESSION_ASM_SOURCES})
    if(SESSION_SOURCES)
        target_sources(McuxSgiPkc PRIVATE ${SESSION_SOURCES})
    endif()
    target_include_directories(McuxSgiPkc PUBLIC 
        ${SGI_PKC_BASE}/src/comps/mcuxClSession/inc
        ${SGI_PKC_BASE}/src/comps/mcuxClSession/inc/internal
    )
endif()

# SGI component
if(CONFIG_SGI_PKC_SGI)
    file(GLOB_RECURSE SGI_SOURCES ${SGI_PKC_BASE}/src/comps/mcuxClSgi/src/*.c)
    if(SGI_SOURCES)
        target_sources(McuxSgiPkc PRIVATE ${SGI_SOURCES})
    endif()
    target_include_directories(McuxSgiPkc PUBLIC 
        ${SGI_PKC_BASE}/src/comps/mcuxClSgi/inc
        ${SGI_PKC_BASE}/src/comps/mcuxClSgi/inc/internal
    )
endif()

# Signature component
if(CONFIG_SGI_PKC_SIGNATURE)
    file(GLOB_RECURSE SIGNATURE_SOURCES ${SGI_PKC_BASE}/src/comps/mcuxClSignature/src/*.c)
    if(SIGNATURE_SOURCES)
        target_sources(McuxSgiPkc PRIVATE ${SIGNATURE_SOURCES})
    endif()
    target_include_directories(McuxSgiPkc PUBLIC 
        ${SGI_PKC_BASE}/src/comps/mcuxClSignature/inc
        ${SGI_PKC_BASE}/src/comps/mcuxClSignature/inc/internal
    )
endif()

# TRNG component
if(CONFIG_SGI_PKC_TRNG)
    file(GLOB_RECURSE TRNG_SOURCES ${SGI_PKC_BASE}/src/comps/mcuxClTrng/src/*.c)
    if(TRNG_SOURCES)
        target_sources(McuxSgiPkc PRIVATE ${TRNG_SOURCES})
    endif()
    target_include_directories(McuxSgiPkc PUBLIC 
        ${SGI_PKC_BASE}/src/comps/mcuxClTrng/inc
        ${SGI_PKC_BASE}/src/comps/mcuxClTrng/inc/internal
    )
endif()

# XOF component
if(CONFIG_SGI_PKC_XOF)
    file(GLOB_RECURSE XOF_SOURCES ${SGI_PKC_BASE}/src/comps/mcuxClXof/src/*.c)
    if(XOF_SOURCES)
        target_sources(McuxSgiPkc PRIVATE ${XOF_SOURCES})
    endif()
    target_include_directories(McuxSgiPkc PUBLIC 
        ${SGI_PKC_BASE}/src/comps/mcuxClXof/inc
        ${SGI_PKC_BASE}/src/comps/mcuxClXof/inc/internal
    )
endif()

# KDF Modes component
if(CONFIG_SGI_PKC_KDF_MODES)
    file(GLOB_RECURSE KDF_MODES_SOURCES ${SGI_PKC_BASE}/src/comps/mcuxClKdfModes/src/*.c)
    if(KDF_MODES_SOURCES)
        target_sources(McuxSgiPkc PRIVATE ${KDF_MODES_SOURCES})
    endif()
    target_include_directories(McuxSgiPkc PUBLIC
        ${SGI_PKC_BASE}/src/comps/mcuxClKdfModes/inc
        ${SGI_PKC_BASE}/src/comps/mcuxClKdfModes/inc/internal
    )
endif()

# XOF Modes component
if(CONFIG_SGI_PKC_XOF_MODES)
    file(GLOB_RECURSE XOF_MODES_SOURCES ${SGI_PKC_BASE}/src/comps/mcuxClXofModes/src/*.c)
    if(XOF_MODES_SOURCES)
        target_sources(McuxSgiPkc PRIVATE ${XOF_MODES_SOURCES})
    endif()
    target_include_directories(McuxSgiPkc PUBLIC 
        ${SGI_PKC_BASE}/src/comps/mcuxClXofModes/inc
        ${SGI_PKC_BASE}/src/comps/mcuxClXofModes/inc/internal
    )
endif()

# CSSL C Pre-Processor component
if(CONFIG_SGI_PKC_PRE_PROCESSOR)
    target_include_directories(McuxSgiPkc PUBLIC ${SGI_PKC_BASE}/src/comps/mcuxCsslCPreProcessor/inc)
endif()

# CSSL Data Integrity component
if(CONFIG_SGI_PKC_DATA_INTEGRITY)
    target_include_directories(McuxSgiPkc PUBLIC ${SGI_PKC_BASE}/src/comps/mcuxCsslDataIntegrity/inc)
endif()

# CSSL Flow Protection component
if(CONFIG_SGI_PKC_FLOW_PROTECTION)
    target_include_directories(McuxSgiPkc PUBLIC ${SGI_PKC_BASE}/src/comps/mcuxCsslFlowProtection/inc)
endif()

# CSSL Param Integrity component
if(CONFIG_SGI_PKC_PARAM_INTEGRITY)
    file(GLOB_RECURSE PARAM_INTEGRITY_SOURCES ${SGI_PKC_BASE}/src/comps/mcuxCsslParamIntegrity/src/*.c)
    if(PARAM_INTEGRITY_SOURCES)
        target_sources(McuxSgiPkc PRIVATE ${PARAM_INTEGRITY_SOURCES})
    endif()
    target_include_directories(McuxSgiPkc PUBLIC ${SGI_PKC_BASE}/src/comps/mcuxCsslParamIntegrity/inc)
endif()

# CSSL PRNG component
if(CONFIG_SGI_PKC_CSSL_PRNG)
    file(GLOB_RECURSE CSSL_PRNG_SOURCES ${SGI_PKC_BASE}/src/comps/mcuxCsslPrng/src/*.c)
    if(CSSL_PRNG_SOURCES)
        target_sources(McuxSgiPkc PRIVATE ${CSSL_PRNG_SOURCES})
    endif()
    target_include_directories(McuxSgiPkc PUBLIC 
        ${SGI_PKC_BASE}/src/comps/mcuxCsslPrng/inc
        ${SGI_PKC_BASE}/src/comps/mcuxCsslPrng/inc/internal
    )
endif()

# CSSL Secure Counter component
if(CONFIG_SGI_PKC_SECURE_COUNTER)
    target_include_directories(McuxSgiPkc PUBLIC ${SGI_PKC_BASE}/src/comps/mcuxCsslSecureCounter/inc)
endif()

endif() ## SGI_PKC
