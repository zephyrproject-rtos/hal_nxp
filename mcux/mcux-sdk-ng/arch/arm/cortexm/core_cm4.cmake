# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if (CONFIG_MCUX_PRJSEG_config.arm.core.cm4)

    mcux_add_iar_configuration(
        AS "--cpu=cortex-m4"
        CC "--cpu=cortex-m4"
        CX "--cpu=cortex-m4"
        LD "--cpu=cortex-m4"
    )

    mcux_add_mdk_configuration(
        AS "-mcpu=cortex-m4 --target=arm-arm-none-eabi"
        CC "-mcpu=cortex-m4"
        CX "-mcpu=cortex-m4"
        LD "--cpu=Cortex-M4"
    )

    mcux_add_armgcc_mcux_configuration(
        AS "-mcpu=cortex-m4"
        CC "-mcpu=cortex-m4"
        CX "-mcpu=cortex-m4"
        LD "-mcpu=cortex-m4"
    )

endif()
