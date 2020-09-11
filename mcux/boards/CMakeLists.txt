#
# Copyright (c) 2018-2020, NXP
#
# SPDX-License-Identifier: Apache-2.0
#

if(CONFIG_BOARD_MIMXRT1010_EVK)
  set(MCUX_BOARD evkmimxrt1010)
elseif(CONFIG_BOARD_MIMXRT1015_EVK)
  set(MCUX_BOARD evkmimxrt1015)
elseif(CONFIG_BOARD_MIMXRT1020_EVK)
  set(MCUX_BOARD evkmimxrt1020)
elseif(CONFIG_BOARD_MIMXRT1050_EVK OR CONFIG_BOARD_MIMXRT1050_EVK_QSPI)
  set(MCUX_BOARD evkbimxrt1050)
elseif(CONFIG_BOARD_MIMXRT1060_EVK OR CONFIG_BOARD_MIMXRT1060_EVK_HYPERFLASH)
  set(MCUX_BOARD evkmimxrt1060)
elseif(CONFIG_BOARD_MIMXRT1064_EVK)
  set(MCUX_BOARD evkmimxrt1064)
elseif(CONFIG_BOARD_MIMXRT685_EVK)
  set(MCUX_BOARD evkmimxrt685)
endif()

zephyr_compile_definitions_ifdef(CONFIG_NXP_IMX_RT_BOOT_HEADER XIP_BOOT_HEADER_ENABLE=1)
zephyr_compile_definitions_ifdef(CONFIG_NXP_IMX_RT6XX_BOOT_HEADER BOOT_HEADER_ENABLE=1)
zephyr_compile_definitions_ifdef(CONFIG_DEVICE_CONFIGURATION_DATA XIP_BOOT_HEADER_DCD_ENABLE=1)
zephyr_compile_definitions(BOARD_FLASH_SIZE=CONFIG_FLASH_SIZE*1024)

if (${MCUX_BOARD} MATCHES "evk[bm]imxrt1[0-9][0-9][0-9]")
zephyr_library_sources_ifdef(CONFIG_BOOT_FLEXSPI_NOR ${MCUX_BOARD}/${MCUX_BOARD}_flexspi_nor_config.c)
zephyr_library_sources_ifdef(CONFIG_DEVICE_CONFIGURATION_DATA ${MCUX_BOARD}/${MCUX_BOARD}_sdram_ini_dcd.c)
elseif (${MCUX_BOARD} MATCHES "evkmimxrt6[0-9][0-9]")
zephyr_library_sources_ifdef(CONFIG_NXP_IMX_RT6XX_BOOT_HEADER ${MCUX_BOARD}/flash_config.c)
endif()
