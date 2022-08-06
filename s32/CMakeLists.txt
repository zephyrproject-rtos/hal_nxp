# Copyright 2022 NXP

# Set the SoC specific drivers and configuration to build
message(FATAL_ERROR "SoC ${CONFIG_SOC} not supported")

add_subdirectory(drivers/${DRIVERS_BASE})
add_subdirectory(soc/${SOC_BASE})
