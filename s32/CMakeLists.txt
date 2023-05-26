# Copyright 2022-2023 NXP

# Set the SoC specific drivers and configuration to build
if(${CONFIG_SOC} STREQUAL "s32z27")
  set(SOC_BASE ${CONFIG_SOC})
  set(DRIVERS_BASE s32ze)
elseif(${CONFIG_SOC} MATCHES "s32k3.*")
  set(SOC_BASE ${CONFIG_SOC})
  set(DRIVERS_BASE s32k3)
else()
  message(FATAL_ERROR "SoC ${CONFIG_SOC} not supported")
endif()

add_subdirectory(drivers/${DRIVERS_BASE})
add_subdirectory(soc/${SOC_BASE})
