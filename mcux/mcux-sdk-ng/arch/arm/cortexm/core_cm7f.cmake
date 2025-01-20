# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if (CONFIG_MCUX_PRJSEG_config.arm.core.cm7f)
    
    mcux_add_iar_configuration(
        AS "--cpu=cortex-m7"
        CC "--cpu=cortex-m7"
        CX "--cpu=cortex-m7"
        LD "--cpu=cortex-m7"
    )

    mcux_add_mdk_configuration(
        AS "-mcpu=cortex-m7 --target=arm-arm-none-eabi"
        CC "-mcpu=cortex-m7"
        CX "-mcpu=cortex-m7"
        LD "--cpu=Cortex-M7"
    )

    mcux_add_armgcc_mcux_configuration(
        AS "-mcpu=cortex-m7"
        CC "-mcpu=cortex-m7"
        CX "-mcpu=cortex-m7"
        LD "-mcpu=cortex-m7"
    )

endif()
