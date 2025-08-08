# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if (CONFIG_MCUX_PRJSEG_module.board.suite)
    
    mcux_add_iar_linker_script(
        TARGETS hyperram_txt_debug hyperram_txt_release
        BASE_PATH ${SdkRootDirPath}
        LINKER ${device_root}/${soc_portfolio}/${soc_series}/${device}/iar/${CONFIG_MCUX_TOOLCHAIN_LINKER_DEVICE_PREFIX}_hyperram_txt.icf
    )

    mcux_add_armgcc_linker_script(
        TARGETS hyperram_txt_debug hyperram_txt_release
        BASE_PATH ${SdkRootDirPath}
        LINKER ${device_root}/${soc_portfolio}/${soc_series}/${device}/gcc/${CONFIG_MCUX_TOOLCHAIN_LINKER_DEVICE_PREFIX}_hyperram_txt.ld
    )

    mcux_add_mdk_linker_script(
        TARGETS hyperram_txt_debug hyperram_txt_release
        BASE_PATH ${SdkRootDirPath}
        LINKER ${device_root}/${soc_portfolio}/${soc_series}/${device}/arm/${CONFIG_MCUX_TOOLCHAIN_LINKER_DEVICE_PREFIX}_hyperram_txt.scf
    )

endif()