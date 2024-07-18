# Copyright 2022-2023 NXP
# SPDX-License-Identifier: BSD-3-Clause

add_subdirectory(BaseNXP)
add_subdirectory(Mcu)
add_subdirectory(Rte)
add_subdirectory_ifdef(CONFIG_NXP_S32_SPI Spi)
add_subdirectory_ifdef(CONFIG_UART_NXP_S32_LINFLEXD Uart)
add_subdirectory_ifdef(CONFIG_MBOX_NXP_S32_MRU Platform)
if (CONFIG_ETH_NXP_S32_NETC)
  add_subdirectory(Eth_NETC)
  add_subdirectory(EthSwt_NETC)
endif()
add_subdirectory_ifdef(CONFIG_CAN_NXP_S32_CANXL Can_CANEXCEL)
