#-------------------------------------------------------------------------------
# Copyright 2026 NXP
# SPDX-License-Identifier: BSD-3-Clause
#-------------------------------------------------------------------------------
# sgi_pkc: TF-M secure build logic


# Mirror Kconfig "default y" list in CMake.
# These are all `default y` under `if SGI_PKC` in Kconfig, but tfm needs these to be explicitly enabled.
# other option is to have a define_all Kconfig
function(sgi_pkc_default_on opt)
  if(CONFIG_SGI_PKC)
    if(NOT DEFINED ${opt})
      set(${opt} ON CACHE BOOL "Auto-enabled (mirrors Kconfig default y when SGI_PKC is enabled)" FORCE)
    endif()
  endif()
endfunction()

foreach(_option IN ITEMS
  CONFIG_SGI_PKC_CORE
  CONFIG_SGI_PKC_TOOLCHAIN
  CONFIG_SGI_PKC_PRE_PROCESSOR
  CONFIG_SGI_PKC_DATA_INTEGRITY
  CONFIG_SGI_PKC_FLOW_PROTECTION
  CONFIG_SGI_PKC_PARAM_INTEGRITY
  CONFIG_SGI_PKC_SECURE_COUNTER
  CONFIG_SGI_PKC_MEMORY
  CONFIG_SGI_PKC_BUFFER
  CONFIG_SGI_PKC_SESSION
  CONFIG_SGI_PKC_RESOURCE
  CONFIG_SGI_PKC_PKC
  CONFIG_SGI_PKC_SGI
  CONFIG_SGI_PKC_DMA
  CONFIG_SGI_PKC_AES
  CONFIG_SGI_PKC_CIPHER
  CONFIG_SGI_PKC_CIPHER_MODES
  CONFIG_SGI_PKC_AEAD
  CONFIG_SGI_PKC_AEAD_MODES
  CONFIG_SGI_PKC_HASH
  CONFIG_SGI_PKC_HASHMODES
  CONFIG_SGI_PKC_MAC
  CONFIG_SGI_PKC_MAC_MODES
  CONFIG_SGI_PKC_HMAC
  CONFIG_SGI_PKC_PADDING
  CONFIG_SGI_PKC_ECC
  CONFIG_SGI_PKC_RSA
  CONFIG_SGI_PKC_FFDH
  CONFIG_SGI_PKC_SIGNATURE
  CONFIG_SGI_PKC_KEY
  CONFIG_SGI_PKC_MATH
  CONFIG_SGI_PKC_RANDOM
  CONFIG_SGI_PKC_RANDOM_MODES
  CONFIG_SGI_PKC_PRNG
  CONFIG_SGI_PKC_CSSL_PRNG
  CONFIG_SGI_PKC_TRNG
  CONFIG_SGI_PKC_CRC
  CONFIG_SGI_PKC_GLIKEY
)

  if(_option STREQUAL "CONFIG_SGI_PKC_FFDH" AND CONFIG_SGI_PKC_PLATFORM_MCXW)
    continue()
  endif()

  sgi_pkc_default_on(${_option})
endforeach()

# MCXW-specific SGI/PKC option
if(CONFIG_SGI_PKC AND CONFIG_SGI_PKC_PLATFORM_MCXW)
  sgi_pkc_default_on(CONFIG_SGI_PKC_KDF_MODES)
endif()

target_compile_options(
    McuxSgiPkc
    PUBLIC
        ${TOOLCHAIN_C_FLAGS}
        -mcmse  # Why is this not even part of the default zephyr build options?
)
 target_compile_options(
    McuxSgiPkc
    PUBLIC
        ${COMPILER_CP_FLAG}
)
target_link_options(
    McuxSgiPkc
    PRIVATE
        ${TOOLCHAIN_LD_FLAGS}
)

# use psa_crypto_driver library interface include files to provide platform specific files
target_include_directories(
    McuxSgiPkc
    PRIVATE
    "$<TARGET_PROPERTY:McuxPsaCryptoDriverSgiPkc,INTERFACE_INCLUDE_DIRECTORIES>"
)

# export the library so that other components can use it in system
export(TARGETS McuxSgiPkc
    FILE "${CMAKE_CURRENT_BINARY_DIR}/McuxSgiPkcTargets.cmake"
    NAMESPACE McuxSgiPkc::
)
