# Copyright 2025 NXP
# SPDX-License-Identifier: BSD-3-Clause

zephyr_include_directories(include)
zephyr_library_sources(src/Xspi_Ip.c)
zephyr_library_sources(src/Xspi_Ip_Controller.c)
zephyr_library_sources(src/Xspi_Ip_HyperRam.c)
zephyr_library_sources(src/Xspi_Ip_Sfdp.c)
