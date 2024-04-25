set(MCUX_SDK_PROJECT_NAME ${ZEPHYR_CURRENT_LIBRARY})
# Translate the SoC name and part number into the mcux device and cpu
# name respectively.
# When this code completes, the following variables will be defined:
# MCUX_DEVICE: SOC name, suffixed by core name when using a dual core part.
#              Example: MIMXRT595S_cm33, or LPC55S36
# MCUX_CPU: "CPU"+ SOC part number, followed by core name when using a dual core part.
#              Example: CPU_MIMXRT595SFAWC_cm33, or  CPU_LPC55S36JBD100
# MCU_DEVICE_PATH: SOC name without core suffix. Must match the name of the
#              folder in MCUX HAL. IE MIMXRT595S, or LPC55S36

if(NOT HWMv2)
  # Include HWMv1 logic for MCUX variables
  include(${CMAKE_CURRENT_LIST_DIR}/hwmv1.cmake)
else()
  string(TOUPPER ${CONFIG_SOC} MCUX_DEVICE_PATH)
  string(TOUPPER ${CONFIG_SOC} MCUX_DEVICE)
  set(MCUX_CPU CPU_${CONFIG_SOC_PART_NUMBER})

  if(DEFINED CONFIG_MCUX_CORE_SUFFIX)
    string(APPEND MCUX_DEVICE ${CONFIG_MCUX_CORE_SUFFIX})
    string(APPEND MCUX_CPU ${CONFIG_MCUX_CORE_SUFFIX})
  endif()
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
if (${MCUX_DEVICE} MATCHES "LPC|MIMXRT6|MIMXRT5|RW6|MCXN.4.")
  zephyr_library_sources(mcux-sdk/devices/${MCUX_DEVICE_PATH}/drivers/fsl_power.c)
  zephyr_library_sources(mcux-sdk/devices/${MCUX_DEVICE_PATH}/drivers/fsl_reset.c)
  zephyr_library_sources_ifdef(CONFIG_HWINFO_RW61X mcux-sdk/devices/${MCUX_DEVICE}/drivers/fsl_ocotp.c)
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

add_subdirectory(middleware)
