#
# Copyright 2023 NXP
#
# SPDX-License-Identifier: Apache-2.0
#
add_subdirectory_ifdef(CONFIG_USB_DEVICE_DRIVER usb)
zephyr_include_directories(.)
