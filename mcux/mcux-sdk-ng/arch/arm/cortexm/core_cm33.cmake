# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

# for CM33 with DSP and SAU
if (CONFIG_MCUX_PRJSEG_config.arm.core.cm33)

    mcux_add_iar_configuration(
        AS "--cpu=cortex-m33.no_se"
        CC "--cpu=cortex-m33.no_se"
        CX "--cpu=cortex-m33.no_se"
        LD "--cpu=cortex-m33.no_se"
    )

    mcux_add_mdk_configuration(
        AS "-mcpu=cortex-m33 --target=arm-arm-none-eabi"
        CC "-mcpu=cortex-m33"
        CX "-mcpu=cortex-m33"
        LD "--cpu=Cortex-M33"
    )

    mcux_add_armgcc_mcux_configuration(
        AS "-mcpu=cortex-m33"
        CC "-mcpu=cortex-m33"
        CX "-mcpu=cortex-m33"
        LD "-mcpu=cortex-m33"
    )

endif()

# for CM33 without DSP and SAU
if (CONFIG_MCUX_PRJSEG_config.arm.core.cm33_nodsp_nosau)

    mcux_add_iar_configuration(
        AS "--cpu=cortex-m33.no_dsp.no_se"
        CC "--cpu=cortex-m33.no_dsp.no_se"
        CX "--cpu=cortex-m33.no_dsp.no_se"
        LD "--cpu=cortex-m33.no_dsp.no_se"
    )

    mcux_add_mdk_configuration(
        AS "-mcpu=cortex-m33+nodsp --target=arm-arm-none-eabi"
        CC "-mcpu=cortex-m33+nodsp"
        CX "-mcpu=cortex-m33+nodsp"
        LD "--cpu=Cortex-M33.no_dsp"
    )

    mcux_add_armgcc_mcux_configuration(
        AS "-mcpu=cortex-m33+nodsp"
        CC "-mcpu=cortex-m33+nodsp"
        CX "-mcpu=cortex-m33+nodsp"
        LD "-mcpu=cortex-m33+nodsp"
    )

endif()

# for CM33 with DSP but no SAU
if (CONFIG_MCUX_PRJSEG_config.arm.core.cm33_dsp_nosau)

    mcux_add_iar_configuration(
        AS "--cpu=cortex-m33.no_se"
        CC "--cpu=cortex-m33.no_se"
        CX "--cpu=cortex-m33.no_se"
        LD "--cpu=cortex-m33.no_se"
    )

    mcux_add_mdk_configuration(
        AS "-mcpu=cortex-m33 --target=arm-arm-none-eabi"
        CC "-mcpu=cortex-m33"
        CX "-mcpu=cortex-m33"
        LD "--cpu=Cortex-M33"
    )

    mcux_add_armgcc_mcux_configuration(
        AS "-mcpu=cortex-m33"
        CC "-mcpu=cortex-m33"
        CX "-mcpu=cortex-m33"
        LD "-mcpu=cortex-m33"
    )

endif()

# for CM33 with no DSP but with SAU
if (CONFIG_MCUX_PRJSEG_config.arm.core.cm33_nodsp_sau)

    mcux_add_iar_configuration(
        AS "--cpu=Cortex-M33.no_dsp"
        CC "--cpu=Cortex-M33.no_dsp"
        CX "--cpu=Cortex-M33.no_dsp"
        LD "--cpu=Cortex-M33.no_dsp"
    )

    mcux_add_mdk_configuration(
        AS "-mcpu=cortex-m33+nodsp --target=arm-arm-none-eabi"
        CC "-mcpu=cortex-m33+nodsp"
        CX "-mcpu=cortex-m33+nodsp"
        LD "--cpu=Cortex-M33.no_dsp"
    )

    mcux_add_armgcc_mcux_configuration(
        AS "-mcpu=cortex-m33+nodsp"
        CC "-mcpu=cortex-m33+nodsp"
        CX "-mcpu=cortex-m33+nodsp"
        LD "-mcpu=cortex-m33+nodsp"
    )


endif()
