# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

# for Cm3 with SAU
if (CONFIG_MCUX_PRJSEG_config.arm.core.cm3)

    mcux_add_iar_configuration(
        AS "--cpu=cortex-m3"
        CC "--cpu=cortex-m3"
        CX "--cpu=cortex-m3"
        LD "--cpu=cortex-m3"
    )

    mcux_add_mdk_configuration(
        AS "-mcpu=cortex-m3 --target=arm-arm-none-eabi"
        CC "-mcpu=cortex-m3"
        CX "-mcpu=cortex-m3"
        LD "--cpu=Cortex-m3"
    )

    mcux_add_armgcc_mcux_configuration(
        AS "-mcpu=cortex-m3"
        CC "-mcpu=cortex-m3"
        CX "-mcpu=cortex-m3"
        LD "-mcpu=cortex-m3"
    )

endif()
