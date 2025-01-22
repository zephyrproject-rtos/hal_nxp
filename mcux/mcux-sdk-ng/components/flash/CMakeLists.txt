# Copyright 2024 NXP
# SPDX-License-Identifier: BSD-3-Clause

if (CONFIG_MCUX_COMPONENT_component.flash_nand_flexspi)
    mcux_add_source(
        BASE_PATH ${SdkRootDirPath}/components/flash/nand
        SOURCES
            fsl_nand_flash.h
            flexspi/fsl_flexspi_nand_flash.c
            flexspi/fsl_flexspi_nand_flash.h
    )

    mcux_add_include(
        BASE_PATH ${SdkRootDirPath}/components/flash/nand
        INCLUDES
            .
            ./flexspi
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.flash_nand_semc)
    mcux_add_source(
        BASE_PATH ${SdkRootDirPath}/components/flash/nand
        SOURCES
            fsl_nand_flash.h
            semc/fsl_semc_nand_flash.c
            semc/fsl_semc_nand_flash.h
    )

    mcux_add_include(
        BASE_PATH ${SdkRootDirPath}/components/flash/nand
        INCLUDES
            .
            ./semc
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.flash_nor_flexspi)
    mcux_add_source(
        BASE_PATH ${SdkRootDirPath}/components/flash/nor
        SOURCES
            fsl_nor_flash.h
            flexspi/fsl_flexspi_nor_flash.c
            flexspi/fsl_flexspi_nor_flash.h
    )

    mcux_add_include(
        BASE_PATH ${SdkRootDirPath}/components/flash/nor
        INCLUDES
            .
            ./flexspi
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.flash_nor_lpspi)

    mcux_add_source(
        BASE_PATH ${SdkRootDirPath}/components/flash/nor
        SOURCES
            fsl_nor_flash.h
            lpspi/fsl_lpspi_nor_flash.c
            lpspi/fsl_lpspi_nor_flash.h
            lpspi/fsl_lpspi_mem_adapter.c
            lpspi/fsl_lpspi_mem_adapter.h
    )

    mcux_add_include(
        BASE_PATH ${SdkRootDirPath}/components/flash/nor
        INCLUDES
            .
            ./lpspi
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.flash_nor_spifi)
    mcux_add_source(
        BASE_PATH ${SdkRootDirPath}/components/flash/nor
        SOURCES
            fsl_nor_flash.h
            spifi/fsl_spifi_nor_flash.c
            spifi/fsl_spifi_nor_flash.h
    )

    mcux_add_include(
        BASE_PATH ${SdkRootDirPath}/components/flash/nor
        INCLUDES
            .
            ./spifi
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.flash_nor_xspi)
    mcux_add_source(
        BASE_PATH ${SdkRootDirPath}/components/flash/nor
        SOURCES
            fsl_nor_flash.h
            xspi/fsl_xspi_nor_flash.c
            xspi/fsl_xspi_nor_flash.h
            fsl_sfdp_parser.c
            fsl_sfdp_parser.h
    )

    mcux_add_include(
        BASE_PATH ${SdkRootDirPath}/components/flash/nor
        INCLUDES
            .
            ./xspi
    )
endif()


if (${device} STREQUAL MK64F12)
    mcux_set_variable(drv_folder frdmk64f)
endif()

if (${device} STREQUAL MK66F18)
    mcux_set_variable(drv_folder frdmk64f)
endif()

if (${device} STREQUAL MK82F25615)
    mcux_set_variable(drv_folder frdmk82f)
endif()

if (${device} STREQUAL LPC54S018M)
    mcux_set_variable(drv_folder lpc54s018m)
endif()

if ((${board} STREQUAL lpcxpresso54018) OR (${board} STREQUAL lpc54018iotmodule) OR 
    (${board} STREQUAL lpc54s018iotmodule) OR (${board} STREQUAL lpcxpresso54608) OR
    (${board} STREQUAL lpcxpresso54618) OR (${board} STREQUAL lpcxpresso54628) OR 
    (${board} STREQUAL lpcxpresso54s018))
    mcux_set_variable(drv_folder lpc54xxx)
endif()

if ((${device} STREQUAL LPC55S69) OR (${device} STREQUAL LPC55S28))
    mcux_set_variable(drv_folder lpc55xxx)
endif()

if (${device} STREQUAL LPC55S36)
    mcux_set_variable(drv_folder lpc55s3x)
endif()

if ((${device} STREQUAL MCXN947) OR (${device} STREQUAL MCXN547) OR (${device} STREQUAL MCXN236))
    mcux_set_variable(drv_folder mcxnx4x)
endif()

if ((${device} STREQUAL MCXA153) OR (${device} STREQUAL MCXA156) OR (${device} STREQUAL MCXA166) OR (${device} STREQUAL MCXA276))
    mcux_set_variable(drv_folder mcxa)
endif()

if (${board} STREQUAL evkmimxrt1020)
    mcux_set_variable(drv_folder mimxrt1021)
endif()

if (${board} STREQUAL evkmimxrt1024)
    mcux_set_variable(drv_folder mimxrt1024)
endif()

if (${board} STREQUAL evkmimxrt1040)
    mcux_set_variable(drv_folder mimxrt1042)
endif()

if (${board} STREQUAL evkbimxrt1050)
    mcux_set_variable(drv_folder mimxrt1052)
endif()

if ((${board} STREQUAL evkbmimxrt1060))
    mcux_set_variable(drv_folder mimxrt1062)
endif()

if (${board} STREQUAL evkcmimxrt1060)
    mcux_set_variable(drv_folder evkcmimxrt1060)
endif()

if (${device} STREQUAL MIMXRT1064)
    mcux_set_variable(drv_folder mimxrt1064)
endif()

if (${board} STREQUAL evkmimxrt1160)
    mcux_set_variable(drv_folder mimxrt1160)
endif()

if (${board} STREQUAL evkmimxrt1170)
    mcux_set_variable(drv_folder mimxrt1170)
endif()

if (${board} STREQUAL evkbmimxrt1170)
    mcux_set_variable(drv_folder mimxrt1170evkb)
endif()

if (${board} STREQUAL evkmimxrt1180)
    mcux_set_variable(drv_folder mimxrt1180)
endif()

if (${board} STREQUAL evkmimxrt1180a)
    mcux_set_variable(drv_folder mimxrt1180a)
endif()

if (${board} STREQUAL mimxrt700evk)
    mcux_set_variable(drv_folder mimxrt700)
endif()

if (${board} STREQUAL evkmimxrt685)
    mcux_set_variable(drv_folder mimxrt685)
endif()

if (${board} STREQUAL mimxrt685audevk)
    mcux_set_variable(drv_folder mimxrt685audevk)
endif()

if (${board} STREQUAL evkmimxrt595)
    mcux_set_variable(drv_folder mimxrt595)
endif()

if ((${board} STREQUAL rdrw612bga) OR (${board} STREQUAL rdrw612qfn))
    mcux_set_variable(drv_folder rdrw612bga)
endif()

if (${board} STREQUAL frdmrw612)
    mcux_set_variable(drv_folder frdmrw612)
endif()

if ((${board} STREQUAL kw45b41zevk) OR (${board} STREQUAL kw45b41zloc) OR (${board} STREQUAL kw47evk) OR (${board} STREQUAL kw47loc) OR (${board} STREQUAL mcxw72evk) OR (${board} STREQUAL frdmmcxw72))
    mcux_set_variable(drv_folder k4w1)
endif()

if (${board} STREQUAL k32w148evk)
    mcux_set_variable(drv_folder k32w1)
endif()

if (${board} STREQUAL frdmmcxw71)
    mcux_set_variable(drv_folder k32w1)
endif()

mcux_add_cmakelists(${SdkRootDirPath}/components/flash/mflash/${drv_folder} OPTIONAL)
