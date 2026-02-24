# Copyright 2024-2025 NXP

# SPDX-License-Identifier: BSD-3-Clause

mcux_add_cmakelists(${SdkRootDirPath}/arch/arm/CMSIS OPTIONAL)

if (CONFIG_MCUX_PRJSEG_config.arm.suppress.warn_as_error)
endif()

if (CONFIG_MCUX_PRJSEG_config.arm.warn_as_error)
    # Set Warning as errors
    mcux_add_armgcc_configuration(
        CC "-Werror"
        CX "-Werror"
    )

    mcux_add_iar_configuration(
        CC "--warnings_are_errors"
        CX "--warnings_are_errors"
    )

    mcux_add_mdk_configuration(
        CC "-Werror"
        CX "-Werror"
    )
endif()

if (CONFIG_MCUX_PRJSEG_config.arm.shared)
        # Create map file
        mcux_add_armgcc_configuration(
                LD "-Xlinker -Map=output.map"
        )

        mcux_add_iar_configuration(
                LD "--map output.map"
        )

        mcux_add_mdk_configuration(
                LD "--list output.map"
        )

        # Output stack usage information on a per-function
        mcux_add_armgcc_configuration(
                CC "-fstack-usage"
                CX "-fstack-usage"
        )
endif()
