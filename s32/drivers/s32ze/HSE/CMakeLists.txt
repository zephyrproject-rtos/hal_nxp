# Copyright 2024 NXP
# SPDX-License-Identifier: BSD-3-Clause

zephyr_include_directories_ifdef(CONFIG_CRYPTO_NXP_S32_HSE
    interface
    interface/inc_common
    interface/config
    interface/inc_custom
    interface/inc_services
)

