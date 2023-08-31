set(MCUX_SDK_PROJECT_NAME ${ZEPHYR_CURRENT_LIBRARY})
# Translate the SoC name and part number into the mcux device and cpu
# name respectively.

# Get MCUX_DEVICE and MCUX_DEVICE_PATH from CONFIG_SOC
# For example, if CONFIG_SOC=mimx8ml8_ca53, then MCUX_DEVICE=MIMX8ML8_ca53
# and MCUX_DEVICE_PATH=MIMX8ML8
string(FIND ${CONFIG_SOC} "_" pos)
if(pos GREATER -1)
  string(REPLACE "_" ";" MCUX_DEVICE_TMP ${CONFIG_SOC})
  list(GET MCUX_DEVICE_TMP 0 MCUX_DEVICE_SOC)
  list(GET MCUX_DEVICE_TMP 1 MCUX_DEVICE_CORE)
  string(TOUPPER ${MCUX_DEVICE_SOC} MCUX_DEVICE_PATH)
  set(MCUX_DEVICE ${MCUX_DEVICE_PATH}_${MCUX_DEVICE_CORE})
else()
  string(TOUPPER ${CONFIG_SOC} MCUX_DEVICE)
  string(TOUPPER ${CONFIG_SOC} MCUX_DEVICE_PATH)
endif()

if("${MCUX_DEVICE}" STREQUAL "LPC51U68")
  set(MCUX_CPU CPU_${CONFIG_SOC_PART_NUMBER})
elseif("${MCUX_DEVICE}" STREQUAL "LPC54114")
  set(MCUX_CPU CPU_${CONFIG_SOC_PART_NUMBER}_cm4)
elseif("${MCUX_DEVICE}" STREQUAL "LPC54114_m0")
  set(MCUX_CPU CPU_${CONFIG_SOC_PART_NUMBER}_cm0plus)
elseif("${MCUX_DEVICE}" STREQUAL "LPC55S16")
  set(MCUX_CPU CPU_${CONFIG_SOC_PART_NUMBER})
elseif("${MCUX_DEVICE}" STREQUAL "LPC55S28")
  set(MCUX_CPU CPU_${CONFIG_SOC_PART_NUMBER})
elseif("${MCUX_DEVICE}" STREQUAL "LPC55S69_cpu0")
  set(MCUX_CPU CPU_${CONFIG_SOC_PART_NUMBER}_cm33_core0)
elseif("${MCUX_DEVICE}" STREQUAL "LPC55S69_cpu1")
  set(MCUX_CPU CPU_${CONFIG_SOC_PART_NUMBER}_cm33_core1)
elseif("${MCUX_DEVICE}" STREQUAL "MIMXRT1052")
  string(REGEX REPLACE "(.*)[AB]$" "CPU_\\1B" MCUX_CPU ${CONFIG_SOC_PART_NUMBER})
elseif("${MCUX_DEVICE}" STREQUAL "MIMXRT595S_cm33")
  set(MCUX_CPU CPU_${CONFIG_SOC_PART_NUMBER}_cm33)
elseif("${MCUX_DEVICE}" STREQUAL "MIMXRT685S_cm33")
  set(MCUX_CPU CPU_${CONFIG_SOC_PART_NUMBER}_cm33)
elseif("${MCUX_DEVICE}" STREQUAL "MIMXRT1176_cm4")
  set(MCUX_CPU CPU_${CONFIG_SOC_PART_NUMBER}_cm4)
elseif("${MCUX_DEVICE}" STREQUAL "MIMXRT1176_cm7")
  set(MCUX_CPU CPU_${CONFIG_SOC_PART_NUMBER}_cm7)
elseif("${MCUX_DEVICE}" STREQUAL "MIMXRT1166_cm4")
  set(MCUX_CPU CPU_${CONFIG_SOC_PART_NUMBER}_cm4)
elseif("${MCUX_DEVICE}" STREQUAL "MIMXRT1166_cm7")
  set(MCUX_CPU CPU_${CONFIG_SOC_PART_NUMBER}_cm7)
else()
  set(MCUX_CPU CPU_${CONFIG_SOC_PART_NUMBER})
endif()

zephyr_include_directories(mcux-sdk/devices/${MCUX_DEVICE_PATH})
zephyr_include_directories(mcux-sdk/devices/${MCUX_DEVICE_PATH}/drivers)

#include device specific drivers
if (${MCUX_DEVICE} MATCHES "MIMXRT1[0-9][0-9][0-9]")
  zephyr_include_directories(mcux-sdk/devices/${MCUX_DEVICE_PATH}/xip)
endif()

#include CMSIS of mcux-sdk for Cortex-A
if (CONFIG_CPU_CORTEX_A)
  zephyr_include_directories(mcux-sdk/CMSIS/Core_AArch64/Include)
endif()

# The mcux uses the cpu name to expose SoC-specific features of a
# given peripheral. For example, the UART peripheral may be
# instantiated with/without a hardware FIFO, and the size of that FIFO
# may be different for each instance in a given SoC. See
# fsl_device_registers.h and ${MCUX_DEVICE}_features.h
zephyr_compile_definitions(${MCUX_CPU})

# Build mcux device-specific objects. Although it is not normal
# practice, drilling down like this avoids the need for repetitive
# build scripts for every mcux device.
zephyr_library_sources(mcux-sdk/devices/${MCUX_DEVICE_PATH}/drivers/fsl_clock.c)
if (${MCUX_DEVICE} MATCHES "LPC|MIMXRT6|MIMXRT5")
  zephyr_library_sources(mcux-sdk/devices/${MCUX_DEVICE_PATH}/drivers/fsl_power.c)
  zephyr_library_sources(mcux-sdk/devices/${MCUX_DEVICE_PATH}/drivers/fsl_reset.c)
endif()

# RT11xx SOC initialization file requires additional drivers, import them
if (${MCUX_DEVICE} MATCHES "MIMXRT11")
  zephyr_library_sources(mcux-sdk/devices/${MCUX_DEVICE_PATH}/drivers/fsl_romapi.c)
  zephyr_library_sources(mcux-sdk/devices/${MCUX_DEVICE_PATH}/drivers/fsl_pmu.c)
  zephyr_library_sources(mcux-sdk/devices/${MCUX_DEVICE_PATH}/drivers/fsl_dcdc.c)
  zephyr_library_sources(mcux-sdk/devices/${MCUX_DEVICE_PATH}/drivers/fsl_anatop_ai.c)
endif()

zephyr_library_sources_ifdef(CONFIG_HAS_MCUX_AUDIOMIX mcux-sdk/devices/${MCUX_DEVICE_PATH}/drivers/fsl_audiomix.c)

add_subdirectory(components)

add_subdirectory_ifdef(
  CONFIG_IEEE802154_KW41Z
  middleware/wireless/framework_5.3.3
  )

#Include Entry cmake component
include(${CMAKE_CURRENT_LIST_DIR}/hal_nxp.cmake)
enable_language(C ASM)

zephyr_library_sources_ifdef(CONFIG_SOC_LPC54114_M4 mcux-sdk/devices/${MCUX_DEVICE_PATH}/gcc/startup_LPC54114_cm4.S)

zephyr_linker_sources(RWDATA quick_access_data.ld)
zephyr_linker_sources_ifdef(CONFIG_ARCH_HAS_RAMFUNC_SUPPORT
  RAMFUNC_SECTION
  quick_access_code.ld
)
zephyr_linker_sources_ifdef(CONFIG_NOCACHE_MEMORY
  NOCACHE_SECTION
  nocache.ld
)
zephyr_library_compile_definitions_ifdef(CONFIG_NOCACHE_MEMORY
  __STARTUP_INITIALIZE_NONCACHEDATA
)
