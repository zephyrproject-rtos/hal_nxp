# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if (CONFIG_MCUX_PRJSEG_config.arm.core.cm0p)

    mcux_add_iar_configuration(
        AS "--cpu=cortex-M0+"
        CC "--cpu=cortex-M0+"
        CX "--cpu=cortex-M0+"
        LD "--cpu=cortex-M0+"
    )

    mcux_add_mdk_configuration(
        AS "-mcpu=cortex-m0plus --target=arm-arm-none-eabi"
        CC "-mcpu=cortex-m0plus"
        CX "-mcpu=cortex-m0plus"
        LD "--cpu Cortex-M0plus"
    )

    mcux_add_armgcc_mcux_configuration(
        AS "-mcpu=cortex-m0plus"
        CC "-mcpu=cortex-m0plus"
        CX "-mcpu=cortex-m0plus"
        LD "-mcpu=cortex-m0plus"
    )

endif()
