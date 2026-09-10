# Copyright 2024 NXP
# SPDX-License-Identifier: Apache-2.0

# Translate the SoC name and part number into the mcux device and cpu
# name respectively.
set(MCUX_SDK_PROJECT_NAME ${ZEPHYR_CURRENT_LIBRARY})
string(TOUPPER ${CONFIG_SOC} MCUX_DEVICE)

set(ELS_PKC_PATH ${CMAKE_CURRENT_LIST_DIR}/../)

message ("els_pkc module is included.")

if(CONFIG_MCUX_ELS_PKC)
  set(CONFIG_EXPORT_MCUX_ELS_PKC_TARGETS ON)
endif()

if(CONFIG_MCUX_ELS_PKC AND NOT CONFIG_BUILD_WITH_TFM)

  add_subdirectory(${ELS_PKC_PATH} els_pkc)
  zephyr_include_directories("$<TARGET_PROPERTY:McuxElsPkc,INTERFACE_INCLUDE_DIRECTORIES>")
  target_link_libraries(app PUBLIC McuxElsPkc)
endif()

if(${MCUX_DEVICE} MATCHES "RW61")
  zephyr_include_directories(${ZEPHYR_HAL_NXP_MODULE_DIR}/mcux/mcux-sdk/devices/RW612)
  zephyr_include_directories(${ZEPHYR_HAL_NXP_MODULE_DIR}/mcux/mcux-sdk/devices/RW612/drivers)
  zephyr_include_directories(${ELS_PKC_PATH}/src/platforms/rw61x)
  zephyr_include_directories(${ELS_PKC_PATH}/src/platforms/rw61x/inc)
  zephyr_include_directories(${ELS_PKC_PATH}/src/comps/mcuxCsslCPreProcessor/inc)
  zephyr_include_directories(${ELS_PKC_PATH}/src/comps/mcuxCsslFlowProtection/inc)
  zephyr_include_directories(${ELS_PKC_PATH}/src/comps/mcuxCsslSecureCounter/inc)
  zephyr_include_directories(${ELS_PKC_PATH}/src/comps/mcuxClCore/inc)
  zephyr_include_directories(${ELS_PKC_PATH}/src/comps/mcuxClEls/inc)

  if(NOT CONFIG_MCUX_ELS_PKC AND NOT CONFIG_BUILD_WITH_TFM)
    zephyr_sources(${ELS_PKC_PATH}/src/comps/mcuxClEls/src/mcuxClEls_Common.c)
    zephyr_sources(${ELS_PKC_PATH}/src/comps/mcuxClEls/src/mcuxClEls_GlitchDetector.c)
  endif()
endif()

if(CONFIG_MCUX_ELS_PKC)
  if(CONFIG_MCUX_ELS_PKC_EXAMPLES)
    add_subdirectory(${ELS_PKC_PATH}/examples examples)
  endif()
endif()