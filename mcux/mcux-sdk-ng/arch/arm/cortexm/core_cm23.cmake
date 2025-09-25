# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

# for CM23 with SAU
if (CONFIG_MCUX_PRJSEG_config.arm.core.cm23)

    mcux_add_iar_configuration(
        AS "--cpu=cortex-m23.no_se"
        CC "--cpu=cortex-m23.no_se"
        CX "--cpu=cortex-m23.no_se"
        LD "--cpu=cortex-m23.no_se"
    )

    mcux_add_mdk_configuration(
        AS "-mcpu=cortex-m23 --target=arm-arm-none-eabi"
        CC "-mcpu=cortex-m23"
        CX "-mcpu=cortex-m23"
        LD "--cpu=Cortex-M33"
    )

    mcux_add_armgcc_mcux_configuration(
        AS "-mcpu=cortex-m23"
        CC "-mcpu=cortex-m23"
        CX "-mcpu=cortex-m23"
        LD "-mcpu=cortex-m23"
    )

endif()

# for CM23 with DSP but no SAU
if (CONFIG_MCUX_PRJSEG_config.arm.core.cm23_nosau)

    mcux_add_iar_configuration(
        AS "--cpu=cortex-m23.no_se"
        CC "--cpu=cortex-m23.no_se"
        CX "--cpu=cortex-m23.no_se"
        LD "--cpu=cortex-m23.no_se"
    )

    mcux_add_mdk_configuration(
        AS "-mcpu=cortex-m23 --target=arm-arm-none-eabi"
        CC "-mcpu=cortex-m23"
        CX "-mcpu=cortex-m23"
        LD "--cpu=Cortex-M33"
    )

    mcux_add_armgcc_mcux_configuration(
        AS "-mcpu=cortex-m23"
        CC "-mcpu=cortex-m23"
        CX "-mcpu=cortex-m23"
        LD "-mcpu=cortex-m23"
    )

endif()
