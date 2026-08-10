# Copyright 2026 NXP
# SPDX-License-Identifier: Apache-2.0

zephyr_sources(
    AppConfigParams.c
    PrintUtility.c
    PrintUtility_Proprietary.c
    PrintUtility_RfTest.c
    UwbApi.c
    UwbApi_Internal.c
    UwbApi_Proprietary.c
    UwbApi_Proprietary_Internal.c
    UwbApi_RfTest.c
    UwbApi_Utility.c
    phNxpUciHal.c
    phNxpUciHal_ext.c
    phNxpUciHal_fwd.c
    phNxpUwbConfig.c
    uwb_uwbs_common_config.c
)

zephyr_include_directories(
    .
)

zephyr_compile_definitions(
    -DT1oI2C_UM11225=1
    -DT1oI2C=1
    -DSSS_USE_FTR_FILE
)

