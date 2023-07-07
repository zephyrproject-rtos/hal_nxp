# Copyright 2023 NXP
# SPDX-License-Identifier: BSD-3-Clause

zephyr_include_directories(include)
zephyr_library_sources(src/Qspi_Ip.c)
zephyr_library_sources(src/Qspi_Ip_Controller.c)
zephyr_library_sources(src/Qspi_Ip_Hyperflash.c)
zephyr_library_sources(src/Qspi_Ip_Sfdp.c)
