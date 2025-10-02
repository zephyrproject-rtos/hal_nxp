# Copyright 2025 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

# for cm85 with DSP and SAU
if (CONFIG_MCUX_PRJSEG_config.arm.core.cm85)

    mcux_add_iar_configuration(
        AS "--cpu=cortex-m85.no_se"
        CC "--cpu=cortex-m85.no_se"
        CX "--cpu=cortex-m85.no_se"
        LD "--cpu=cortex-m85.no_se"
    )

    mcux_add_mdk_configuration(
        AS "-mcpu=cortex-m85 --target=arm-arm-none-eabi"
        CC "-mcpu=cortex-m85"
        CX "-mcpu=cortex-m85"
        LD "--cpu=Cortex-m85"
    )

    mcux_add_armgcc_mcux_configuration(
        AS "-mcpu=cortex-m85"
        CC "-mcpu=cortex-m85"
        CX "-mcpu=cortex-m85"
        LD "-mcpu=cortex-m85"
    )

endif()

# for cm85 without DSP and SAU
if (CONFIG_MCUX_PRJSEG_config.arm.core.cm85_nodsp_nosau)

    mcux_add_iar_configuration(
        AS "--cpu=cortex-m85.no_dsp.no_se"
        CC "--cpu=cortex-m85.no_dsp.no_se"
        CX "--cpu=cortex-m85.no_dsp.no_se"
        LD "--cpu=cortex-m85.no_dsp.no_se"
    )

    mcux_add_mdk_configuration(
        AS "-mcpu=cortex-m85+nodsp --target=arm-arm-none-eabi"
        CC "-mcpu=cortex-m85+nodsp"
        CX "-mcpu=cortex-m85+nodsp"
        LD "--cpu=Cortex-m85.no_dsp"
    )

    mcux_add_armgcc_mcux_configuration(
        AS "-mcpu=cortex-m85+nodsp"
        CC "-mcpu=cortex-m85+nodsp"
        CX "-mcpu=cortex-m85+nodsp"
        LD "-mcpu=cortex-m85+nodsp"
    )

endif()

# for cm85 with DSP but no SAU
if (CONFIG_MCUX_PRJSEG_config.arm.core.cm85_dsp_nosau)

    mcux_add_iar_configuration(
        AS "--cpu=cortex-m85.no_se"
        CC "--cpu=cortex-m85.no_se"
        CX "--cpu=cortex-m85.no_se"
        LD "--cpu=cortex-m85.no_se"
    )

    mcux_add_mdk_configuration(
        AS "-mcpu=cortex-m85 --target=arm-arm-none-eabi"
        CC "-mcpu=cortex-m85"
        CX "-mcpu=cortex-m85"
        LD "--cpu=Cortex-m85"
    )

    mcux_add_armgcc_mcux_configuration(
        AS "-mcpu=cortex-m85"
        CC "-mcpu=cortex-m85"
        CX "-mcpu=cortex-m85"
        LD "-mcpu=cortex-m85"
    )

endif()

# for cm85 with no DSP but with SAU
if (CONFIG_MCUX_PRJSEG_config.arm.core.cm85_nodsp_sau)

    mcux_add_iar_configuration(
        AS "--cpu=Cortex-m85.no_dsp"
        CC "--cpu=Cortex-m85.no_dsp"
        CX "--cpu=Cortex-m85.no_dsp"
        LD "--cpu=Cortex-m85.no_dsp"
    )

    mcux_add_mdk_configuration(
        AS "-mcpu=cortex-m85+nodsp --target=arm-arm-none-eabi"
        CC "-mcpu=cortex-m85+nodsp"
        CX "-mcpu=cortex-m85+nodsp"
        LD "--cpu=Cortex-m85.no_dsp"
    )

    mcux_add_armgcc_mcux_configuration(
        AS "-mcpu=cortex-m85+nodsp"
        CC "-mcpu=cortex-m85+nodsp"
        CX "-mcpu=cortex-m85+nodsp"
        LD "-mcpu=cortex-m85+nodsp"
    )


endif()
