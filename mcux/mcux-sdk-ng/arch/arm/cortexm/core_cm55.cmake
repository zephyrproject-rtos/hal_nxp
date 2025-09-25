# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

# for CM55 with DSP and SAU
if (CONFIG_MCUX_PRJSEG_config.arm.core.cm55)

    mcux_add_iar_configuration(
        AS "--cpu=cortex-m55.no_se"
        CC "--cpu=cortex-m55.no_se"
        CX "--cpu=cortex-m55.no_se"
        LD "--cpu=cortex-m55.no_se"
    )

    mcux_add_mdk_configuration(
        AS "-mcpu=cortex-m55 --target=arm-arm-none-eabi"
        CC "-mcpu=cortex-m55"
        CX "-mcpu=cortex-m55"
        LD "--cpu=Cortex-m55"
    )

    mcux_add_armgcc_mcux_configuration(
        AS "-mcpu=cortex-m55"
        CC "-mcpu=cortex-m55"
        CX "-mcpu=cortex-m55"
        LD "-mcpu=cortex-m55"
    )

endif()

# for CM55 without DSP and SAU
if (CONFIG_MCUX_PRJSEG_config.arm.core.cm55_nodsp_nosau)

    mcux_add_iar_configuration(
        AS "--cpu=cortex-m55.no_dsp.no_se"
        CC "--cpu=cortex-m55.no_dsp.no_se"
        CX "--cpu=cortex-m55.no_dsp.no_se"
        LD "--cpu=cortex-m55.no_dsp.no_se"
    )

    mcux_add_mdk_configuration(
        AS "-mcpu=cortex-m55+nodsp --target=arm-arm-none-eabi"
        CC "-mcpu=cortex-m55+nodsp"
        CX "-mcpu=cortex-m55+nodsp"
        LD "--cpu=Cortex-m55.no_dsp"
    )

    mcux_add_armgcc_mcux_configuration(
        AS "-mcpu=cortex-m55+nodsp"
        CC "-mcpu=cortex-m55+nodsp"
        CX "-mcpu=cortex-m55+nodsp"
        LD "-mcpu=cortex-m55+nodsp"
    )

endif()

# for CM55 with DSP but no SAU
if (CONFIG_MCUX_PRJSEG_config.arm.core.cm55_dsp_nosau)

    mcux_add_iar_configuration(
        AS "--cpu=cortex-m55.no_se"
        CC "--cpu=cortex-m55.no_se"
        CX "--cpu=cortex-m55.no_se"
        LD "--cpu=cortex-m55.no_se"
    )

    mcux_add_mdk_configuration(
        AS "-mcpu=cortex-m55 --target=arm-arm-none-eabi"
        CC "-mcpu=cortex-m55"
        CX "-mcpu=cortex-m55"
        LD "--cpu=Cortex-m55"
    )

    mcux_add_armgcc_mcux_configuration(
        AS "-mcpu=cortex-m55"
        CC "-mcpu=cortex-m55"
        CX "-mcpu=cortex-m55"
        LD "-mcpu=cortex-m55"
    )

endif()

# for CM55 with no DSP but with SAU
if (CONFIG_MCUX_PRJSEG_config.arm.core.cm55_nodsp_sau)

    mcux_add_iar_configuration(
        AS "--cpu=Cortex-m55.no_dsp"
        CC "--cpu=Cortex-m55.no_dsp"
        CX "--cpu=Cortex-m55.no_dsp"
        LD "--cpu=Cortex-m55.no_dsp"
    )

    mcux_add_mdk_configuration(
        AS "-mcpu=cortex-m55+nodsp --target=arm-arm-none-eabi"
        CC "-mcpu=cortex-m55+nodsp"
        CX "-mcpu=cortex-m55+nodsp"
        LD "--cpu=Cortex-m55.no_dsp"
    )

    mcux_add_armgcc_mcux_configuration(
        AS "-mcpu=cortex-m55+nodsp"
        CC "-mcpu=cortex-m55+nodsp"
        CX "-mcpu=cortex-m55+nodsp"
        LD "-mcpu=cortex-m55+nodsp"
    )


endif()
