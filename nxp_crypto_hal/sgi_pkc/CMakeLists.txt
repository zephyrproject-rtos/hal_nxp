#---------------------------------------------
# Copyright 2025-2026 NXP.
# SPDX-License-Identifier: BSD-3-Clause
#---------------------------------------------

#Add cmake for PQC addon
mcux_add_cmakelists(${SdkRootDirPath}/components/sgi_pkc/pqc/ OPTIONAL)

if (CONFIG_MCUX_COMPONENT_component.sgi_pkc.doc.mcxa)
    mcux_add_source(
        SOURCES
                doc/mcxa2xx/html/*.*
                doc/mcxa2xx/html/search/*.*
                LICENSE.md
                ReleaseNotes.txt
                SBOM-MCU_DCI2-DCI_SDK_V4.3.0.spdx.json
                BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )

    mcux_add_include(
        INCLUDES ./
        BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.sgi_pkc.doc.mcxa5xx)
    mcux_add_source(
        SOURCES
                doc/mcxa5xx/html/*.*
                doc/mcxa5xx/html/search/*.*
                LICENSE.md
                ReleaseNotes.txt
                SBOM-MCU_DCI2-DCI_SDK_V4.3.0.spdx.json
                BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )

    mcux_add_include(
        INCLUDES ./
        BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.sgi_pkc.doc.mcxl)
    mcux_add_source(
        SOURCES
                doc/mcxl2xx/html/*.*
                doc/mcxl2xx/html/search/*.*
                LICENSE.md
                ReleaseNotes.txt
                SBOM-MCU_DCI2-DCI_SDK_V4.3.0.spdx.json
                BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )

    mcux_add_include(
        INCLUDES ./
        BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.sgi_pkc.doc.mcxw7x)
    mcux_add_source(
        SOURCES
                doc/mcxw7x/html/*.*
                doc/mcxw7x/html/search/*.*
                LICENSE.md
                ReleaseNotes.txt
                SBOM-MCU_DCI2-DCI_SDK_V4.3.0.spdx.json
                BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )

    mcux_add_include(
        INCLUDES ./
        BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.sgi_pkc.platform.mcxa)
    mcux_add_source(
        SOURCES src/platforms/mcxa/platform_specific_headers.h
                src/platforms/mcxa/mcuxClConfig.h
                src/platforms/mcxa/inc/ip_platform.h

                src/platforms/mcxa/mcux_sgi.c
                src/platforms/mcxa/mcux_sgi.h
                src/platforms/mcxa/mcux_pkc.c
                src/platforms/mcxa/mcux_pkc.h

                includes/platform/mcxa/mcuxClAeadModes_MemoryConsumption.h
                includes/platform/mcxa/mcuxClCipherModes_MemoryConsumption.h
                includes/platform/mcxa/mcuxClEcc_MemoryConsumption.h
                includes/platform/mcxa/mcuxClFfdh_MemoryConsumption.h
                includes/platform/mcxa/mcuxClHash_MemoryConsumption.h
                includes/platform/mcxa/mcuxClHashModes_MemoryConsumption.h
                includes/platform/mcxa/mcuxClHmac_MemoryConsumption.h
                includes/platform/mcxa/mcuxClKdfModes_MemoryConsumption.h
                includes/platform/mcxa/mcuxClKey_MemoryConsumption.h
                includes/platform/mcxa/mcuxClMacModes_MemoryConsumption.h
                includes/platform/mcxa/mcuxClRandomModes_MemoryConsumption.h
                includes/platform/mcxa/mcuxClResource_MemoryConsumption.h
                includes/platform/mcxa/mcuxClRsa_MemoryConsumption.h
                includes/platform/mcxa/mcuxClSession_Internal_AssemblyHeader.h
                includes/platform/mcxa/mcuxClSession_MemoryConsumption.h
                includes/platform/mcxa/mcuxClSignature_MemoryConsumption.h
                includes/platform/mcxa/mcuxClXofModes_MemoryConsumption.h
                includes/platform/mcxa/mcuxCsslMemory_AssemblyHeader.h
                includes/platform/mcxa/mcuxCsslPrng_AssemblyHeader.h
                BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
    mcux_add_include(
        INCLUDES ./
                 src/platforms/mcxa
                 src/platforms/mcxa/inc
                 includes/platform/mcxa
                 BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.sgi_pkc.platform.mcxa5xx)
    mcux_add_source(
        SOURCES src/platforms/mcxa5/platform_specific_headers.h
                src/platforms/mcxa5/mcuxClConfig.h
                src/platforms/mcxa5/inc/ip_platform.h

                src/platforms/mcxa5/mcux_sgi.c
                src/platforms/mcxa5/mcux_sgi.h
                src/platforms/mcxa5/mcux_pkc.c
                src/platforms/mcxa5/mcux_pkc.h

                includes/platform/mcxa5/mcuxClAeadModes_MemoryConsumption.h
                includes/platform/mcxa5/mcuxClCipherModes_MemoryConsumption.h
                includes/platform/mcxa5/mcuxClEcc_MemoryConsumption.h
                includes/platform/mcxa5/mcuxClFfdh_MemoryConsumption.h
                includes/platform/mcxa5/mcuxClHash_MemoryConsumption.h
                includes/platform/mcxa5/mcuxClHashModes_MemoryConsumption.h
                includes/platform/mcxa5/mcuxClHmac_MemoryConsumption.h
                includes/platform/mcxa5/mcuxClKdfModes_MemoryConsumption.h
                includes/platform/mcxa5/mcuxClKey_MemoryConsumption.h
                includes/platform/mcxa5/mcuxClMacModes_MemoryConsumption.h
                includes/platform/mcxa5/mcuxClRandomModes_MemoryConsumption.h
                includes/platform/mcxa5/mcuxClResource_MemoryConsumption.h
                includes/platform/mcxa5/mcuxClRsa_MemoryConsumption.h
                includes/platform/mcxa5/mcuxClSession_Internal_AssemblyHeader.h
                includes/platform/mcxa5/mcuxClSession_MemoryConsumption.h
                includes/platform/mcxa5/mcuxClSignature_MemoryConsumption.h
                includes/platform/mcxa5/mcuxClXofModes_MemoryConsumption.h
                includes/platform/mcxa5/mcuxCsslMemory_AssemblyHeader.h
                includes/platform/mcxa5/mcuxCsslPrng_AssemblyHeader.h
                BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
    mcux_add_include(
        INCLUDES ./
                 src/platforms/mcxa5
                 src/platforms/mcxa5/inc
                 includes/platform/mcxa5
                 BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.sgi_pkc.platform.mcxl)
    mcux_add_source(
        SOURCES src/platforms/mcxl/platform_specific_headers.h
                src/platforms/mcxl/mcuxClConfig.h
                src/platforms/mcxl/inc/ip_platform.h

                src/platforms/mcxl/mcux_sgi.c
                src/platforms/mcxl/mcux_sgi.h
                src/platforms/mcxl/mcux_pkc.c
                src/platforms/mcxl/mcux_pkc.h

                includes/platform/mcxl/mcuxClAeadModes_MemoryConsumption.h
                includes/platform/mcxl/mcuxClCipherModes_MemoryConsumption.h
                includes/platform/mcxl/mcuxClEcc_MemoryConsumption.h
                includes/platform/mcxl/mcuxClFfdh_MemoryConsumption.h
                includes/platform/mcxl/mcuxClHash_MemoryConsumption.h
                includes/platform/mcxl/mcuxClHashModes_MemoryConsumption.h
                includes/platform/mcxl/mcuxClHmac_MemoryConsumption.h
                includes/platform/mcxl/mcuxClKdfModes_MemoryConsumption.h
                includes/platform/mcxl/mcuxClKey_MemoryConsumption.h
                includes/platform/mcxl/mcuxClMacModes_MemoryConsumption.h
                includes/platform/mcxl/mcuxClRandomModes_MemoryConsumption.h
                includes/platform/mcxl/mcuxClResource_MemoryConsumption.h
                includes/platform/mcxl/mcuxClRsa_MemoryConsumption.h
                includes/platform/mcxl/mcuxClSession_Internal_AssemblyHeader.h
                includes/platform/mcxl/mcuxClSession_MemoryConsumption.h
                includes/platform/mcxl/mcuxClSignature_MemoryConsumption.h
                includes/platform/mcxl/mcuxClXofModes_MemoryConsumption.h
                includes/platform/mcxl/mcuxCsslMemory_AssemblyHeader.h
                includes/platform/mcxl/mcuxCsslPrng_AssemblyHeader.h
                BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
    mcux_add_include(
        INCLUDES ./
                 src/platforms/mcxl
                 src/platforms/mcxl/inc
                 includes/platform/mcxl
                 BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.sgi_pkc.platform.mcxw7x)
    mcux_add_source(
        SOURCES src/platforms/mcxw/platform_specific_headers.h
                src/platforms/mcxw/mcuxClConfig.h
                src/platforms/mcxw/inc/ip_platform.h

                src/platforms/mcxw/mcux_sgi.c
                src/platforms/mcxw/mcux_sgi.h
                src/platforms/mcxw/mcux_pkc.c
                src/platforms/mcxw/mcux_pkc.h

                includes/platform/mcxw/mcuxClAeadModes_MemoryConsumption.h
                includes/platform/mcxw/mcuxClCipherModes_MemoryConsumption.h
                includes/platform/mcxw/mcuxClEcc_MemoryConsumption.h
                includes/platform/mcxw/mcuxClFfdh_MemoryConsumption.h
                includes/platform/mcxw/mcuxClHash_MemoryConsumption.h
                includes/platform/mcxw/mcuxClHashModes_MemoryConsumption.h
                includes/platform/mcxw/mcuxClHmac_MemoryConsumption.h
                includes/platform/mcxw/mcuxClKdfModes_MemoryConsumption.h
                includes/platform/mcxw/mcuxClKey_MemoryConsumption.h
                includes/platform/mcxw/mcuxClMacModes_MemoryConsumption.h
                includes/platform/mcxw/mcuxClRandomModes_MemoryConsumption.h
                includes/platform/mcxw/mcuxClResource_MemoryConsumption.h
                includes/platform/mcxw/mcuxClRsa_MemoryConsumption.h
                includes/platform/mcxw/mcuxClSession_Internal_AssemblyHeader.h
                includes/platform/mcxw/mcuxClSession_MemoryConsumption.h
                includes/platform/mcxw/mcuxClSignature_MemoryConsumption.h
                includes/platform/mcxw/mcuxClXofModes_MemoryConsumption.h
                includes/platform/mcxw/mcuxCsslMemory_AssemblyHeader.h
                includes/platform/mcxw/mcuxCsslPrng_AssemblyHeader.h
                BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
    mcux_add_include(
        INCLUDES ./
                 src/platforms/mcxw
                 src/platforms/mcxw/inc
                 includes/platform/mcxw
                 BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.sgi_pkc.aead)
    mcux_add_source(
        SOURCES src/comps/mcuxClAead/src/mcuxClAead.c
                src/comps/mcuxClAead/inc/mcuxClAead.h
                src/comps/mcuxClAead/inc/mcuxClAead_Constants.h
                src/comps/mcuxClAead/inc/mcuxClAead_Functions.h
                src/comps/mcuxClAead/inc/mcuxClAead_Types.h
                src/comps/mcuxClAead/inc/internal/mcuxClAead_Ctx.h
                src/comps/mcuxClAead/inc/internal/mcuxClAead_Descriptor.h
                BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
    mcux_add_include(
        INCLUDES ./
                 src/comps/mcuxClAead/inc
                 src/comps/mcuxClAead/inc/internal
                 BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.sgi_pkc.aead_modes)
    mcux_add_source(
        SOURCES src/comps/mcuxClAeadModes/src/mcuxClAeadModes_Sgi_Ccm.c
                src/comps/mcuxClAeadModes/src/mcuxClAeadModes_Sgi_Cleanup.c
                src/comps/mcuxClAeadModes/src/mcuxClAeadModes_Sgi_Common.c
                src/comps/mcuxClAeadModes/src/mcuxClAeadModes_Sgi_Gcm.c
                src/comps/mcuxClAeadModes/src/mcuxClAeadModes_Sgi_Modes.c
                src/comps/mcuxClAeadModes/src/mcuxClAeadModes_Sgi_Multipart.c
                src/comps/mcuxClAeadModes/src/mcuxClAeadModes_Sgi_Oneshot.c
                src/comps/mcuxClAeadModes/src/size/size.c
                src/comps/mcuxClAeadModes/inc/mcuxClAeadModes.h
                src/comps/mcuxClAeadModes/inc/mcuxClAeadModes_Modes.h
                src/comps/mcuxClAeadModes/inc/internal/mcuxClAeadModes_Common.h
                src/comps/mcuxClAeadModes/inc/internal/mcuxClAeadModes_Common_Constants.h
                src/comps/mcuxClAeadModes/inc/internal/mcuxClAeadModes_Common_Functions.h
                src/comps/mcuxClAeadModes/inc/internal/mcuxClAeadModes_Common_Wa.h
                src/comps/mcuxClAeadModes/inc/internal/mcuxClAeadModes_Sgi_Algorithms.h
                src/comps/mcuxClAeadModes/inc/internal/mcuxClAeadModes_Sgi_Cleanup.h
                src/comps/mcuxClAeadModes/inc/internal/mcuxClAeadModes_Sgi_Ctx.h
                src/comps/mcuxClAeadModes/inc/internal/mcuxClAeadModes_Sgi_Functions.h
                src/comps/mcuxClAeadModes/inc/internal/mcuxClAeadModes_Sgi_Types.h
                # src/comps/mcuxClAeadModes/inc/platform/mcxa/mcuxClAeadModes_MemoryConsumption.h
                BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
    mcux_add_include(
        INCLUDES ./
                 src/comps/mcuxClAeadModes/inc
                 src/comps/mcuxClAeadModes/inc/internal
                 # src/comps/mcuxClAeadModes/inc/platform/mcxa
                 BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.sgi_pkc.aes)
    mcux_add_source(
        SOURCES src/comps/mcuxClAes/src/mcuxClAes_KeyEncodingMechanisms_Sgi.c
                src/comps/mcuxClAes/src/mcuxClAes_KeyHelper_Sgi.c
                src/comps/mcuxClAes/src/mcuxClAes_KeyTypes.c
                src/comps/mcuxClAes/src/mcuxClAes_SecurityUtils_Sgi.c
                src/comps/mcuxClAes/inc/mcuxClAes.h
                src/comps/mcuxClAes/inc/mcuxClAes_Constants.h
                src/comps/mcuxClAes/inc/mcuxClAes_KeyEncodingMechanisms.h
                src/comps/mcuxClAes/inc/mcuxClAes_KeyTypes.h
                src/comps/mcuxClAes/inc/mcuxClAes_Types.h
                src/comps/mcuxClAes/inc/internal/mcuxClAes_Ctx.h
                src/comps/mcuxClAes/inc/internal/mcuxClAes_Internal_Constants.h
                src/comps/mcuxClAes/inc/internal/mcuxClAes_Internal_Functions.h
                src/comps/mcuxClAes/inc/internal/mcuxClAes_KeyEncodingMechanisms_Sgi.h
                src/comps/mcuxClAes/inc/internal/mcuxClAes_Wa.h
                BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
    mcux_add_include(
        INCLUDES ./
                 src/comps/mcuxClAes/inc
                 src/comps/mcuxClAes/inc/internal
                 BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.sgi_pkc.buffer)
    mcux_add_source(
        SOURCES src/comps/mcuxClBuffer/src/mcuxClBuffer.c
                src/comps/mcuxClBuffer/inc/mcuxClBuffer.h
                src/comps/mcuxClBuffer/inc/mcuxClBuffer_Cfg.h
                src/comps/mcuxClBuffer/inc/mcuxClBuffer_Constants.h
                src/comps/mcuxClBuffer/inc/mcuxClBuffer_Impl.h
                src/comps/mcuxClBuffer/inc/mcuxClBuffer_Pointer.h
                src/comps/mcuxClBuffer/inc/internal/mcuxClBuffer_FeatureConfig.h
                src/comps/mcuxClBuffer/inc/internal/mcuxClBuffer_Internal.h
                src/comps/mcuxClBuffer/inc/internal/mcuxClBuffer_Internal_Pointer.h
                BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
    mcux_add_include(
        INCLUDES ./
                 src/comps/mcuxClBuffer/inc
                 src/comps/mcuxClBuffer/inc/internal
                 BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.sgi_pkc.cipher)
    mcux_add_source(
        SOURCES src/comps/mcuxClCipher/src/mcuxClCipher.c
                src/comps/mcuxClCipher/inc/mcuxClCipher.h
                src/comps/mcuxClCipher/inc/mcuxClCipher_Constants.h
                src/comps/mcuxClCipher/inc/mcuxClCipher_Functions.h
                src/comps/mcuxClCipher/inc/mcuxClCipher_Types.h
                src/comps/mcuxClCipher/inc/internal/mcuxClCipher_Internal.h
                src/comps/mcuxClCipher/inc/internal/mcuxClCipher_Internal_Types.h
                BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
    mcux_add_include(
        INCLUDES ./
                 src/comps/mcuxClCipher/inc
                 src/comps/mcuxClCipher/inc/internal
                 BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.sgi_pkc.cipher_modes)
    mcux_add_source(
        SOURCES src/comps/mcuxClCipherModes/src/mcuxClCipherModes_Sgi_Aes_Iv.c
                src/comps/mcuxClCipherModes/src/mcuxClCipherModes_Sgi_Aes_Multipart.c
                src/comps/mcuxClCipherModes/src/mcuxClCipherModes_Sgi_Aes_NonBlocking_Multipart.c
                src/comps/mcuxClCipherModes/src/mcuxClCipherModes_Sgi_Aes_NonBlocking_Oneshot.c
                src/comps/mcuxClCipherModes/src/mcuxClCipherModes_Sgi_Aes_Oneshot.c
                src/comps/mcuxClCipherModes/src/mcuxClCipherModes_Sgi_Aes_Security.c
                src/comps/mcuxClCipherModes/src/mcuxClCipherModes_Sgi_Cbc.c
                src/comps/mcuxClCipherModes/src/mcuxClCipherModes_Sgi_Cbc_Dma_NonBlocking.c
                src/comps/mcuxClCipherModes/src/mcuxClCipherModes_Sgi_Cleanup.c
                src/comps/mcuxClCipherModes/src/mcuxClCipherModes_Sgi_Ctr.c
                src/comps/mcuxClCipherModes/src/mcuxClCipherModes_Sgi_Ctr_Dma_NonBlocking.c
                src/comps/mcuxClCipherModes/src/mcuxClCipherModes_Sgi_Ecb.c
                src/comps/mcuxClCipherModes/src/mcuxClCipherModes_Sgi_Ecb_Dma_NonBlocking.c
                src/comps/mcuxClCipherModes/src/mcuxClCipherModes_Sgi_Helper.c
                src/comps/mcuxClCipherModes/src/mcuxClCipherModes_Sgi_Modes.c
                src/comps/mcuxClCipherModes/src/size/size.c
				
                src/comps/mcuxClCipherModes/inc/mcuxClCipherModes.h
                src/comps/mcuxClCipherModes/inc/mcuxClCipherModes_Modes.h
                src/comps/mcuxClCipherModes/inc/internal/mcuxClCipherModes_Common.h
                src/comps/mcuxClCipherModes/inc/internal/mcuxClCipherModes_Common_Constants.h
                src/comps/mcuxClCipherModes/inc/internal/mcuxClCipherModes_Common_Wa.h
                src/comps/mcuxClCipherModes/inc/internal/mcuxClCipherModes_Sgi_Aes_Iv.h
                src/comps/mcuxClCipherModes/inc/internal/mcuxClCipherModes_Sgi_Aes_Multipart.h
                src/comps/mcuxClCipherModes/inc/internal/mcuxClCipherModes_Sgi_Aes_NonBlocking_Multipart.h
                src/comps/mcuxClCipherModes/inc/internal/mcuxClCipherModes_Sgi_Aes_NonBlocking_Oneshot.h
                src/comps/mcuxClCipherModes/inc/internal/mcuxClCipherModes_Sgi_Aes_Oneshot.h
                src/comps/mcuxClCipherModes/inc/internal/mcuxClCipherModes_Sgi_Aes_Security.h
                src/comps/mcuxClCipherModes/inc/internal/mcuxClCipherModes_Sgi_Algorithms.h
                src/comps/mcuxClCipherModes/inc/internal/mcuxClCipherModes_Sgi_Cleanup.h
                src/comps/mcuxClCipherModes/inc/internal/mcuxClCipherModes_Sgi_Functions.h
                src/comps/mcuxClCipherModes/inc/internal/mcuxClCipherModes_Sgi_Helper.h
                src/comps/mcuxClCipherModes/inc/internal/mcuxClCipherModes_Sgi_Types.h
				
                # src/comps/mcuxClCipherModes/inc/platform/mcxa/mcuxClCipherModes_MemoryConsumption.h
                BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
    mcux_add_include(
        INCLUDES ./
                 src/comps/mcuxClCipherModes/inc
                 src/comps/mcuxClCipherModes/inc/internal
                 BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.sgi_pkc.core)
    mcux_add_source(
        SOURCES src/comps/mcuxClCore/inc/mcuxClCore_Examples.h
                src/comps/mcuxClCore/inc/mcuxClCore_FunctionIdentifiers.h
                src/comps/mcuxClCore/inc/mcuxClCore_Macros.h
                src/comps/mcuxClCore/inc/mcuxClCore_Platform.h
                src/comps/mcuxClCore/inc/mcuxClCore_Toolchain.h
                BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
    mcux_add_include(
        INCLUDES ./
                 src/comps/mcuxClCore/inc/
                 BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.sgi_pkc.crc)
    mcux_add_source(
        SOURCES src/comps/mcuxClCrc/src/mcuxClCrc.c
                src/comps/mcuxClCrc/src/mcuxClCrc_Context_Crc_Hw.c
                src/comps/mcuxClCrc/src/mcuxClCrc_Drv.c
                src/comps/mcuxClCrc/inc/mcuxClCrc.h
                src/comps/mcuxClCrc/inc/internal/mcuxClCrc_Drv.h
                src/comps/mcuxClCrc/inc/internal/mcuxClCrc_FeatureConfig.h
                src/comps/mcuxClCrc/inc/internal/mcuxClCrc_Internal_Constants.h
                src/comps/mcuxClCrc/inc/internal/mcuxClCrc_Internal_Functions.h
                src/comps/mcuxClCrc/inc/internal/mcuxClCrc_Internal_Types.h
                src/comps/mcuxClCrc/inc/internal/mcuxClCrc_Sfr.h
                src/comps/mcuxClCrc/inc/internal/mcuxClCrc_SfrAccess.h
                BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
    mcux_add_include(
        INCLUDES ./
                 src/comps/mcuxClCrc/inc
                 src/comps/mcuxClCrc/inc/internal
                 BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.sgi_pkc.dma)
    mcux_add_source(
        SOURCES src/comps/mcuxClDma/src/mcuxClDma_Drv.c
                src/comps/mcuxClDma/src/mcuxClDma_Resource.c
                src/comps/mcuxClDma/src/mcuxClDma_Utils.c
                src/comps/mcuxClDma/src/mcuxClDma_Utils_Sgi.c
                src/comps/mcuxClDma/inc/mcuxClDma_Types.h
                src/comps/mcuxClDma/inc/internal/mcuxClDma_Drv.h
                src/comps/mcuxClDma/inc/internal/mcuxClDma_FeatureConfig.h
                src/comps/mcuxClDma/inc/internal/mcuxClDma_Resource.h
                src/comps/mcuxClDma/inc/internal/mcuxClDma_Sfr.h
                src/comps/mcuxClDma/inc/internal/mcuxClDma_SfrAccess.h
                src/comps/mcuxClDma/inc/internal/mcuxClDma_Utils.h
                src/comps/mcuxClDma/inc/internal/mcuxClDma_Utils_Sgi.h
                BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
    mcux_add_include(
        INCLUDES ./
                 src/comps/mcuxClDma/inc
                 src/comps/mcuxClDma/inc/internal
                 BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.sgi_pkc.ecc)
    mcux_add_source(
        SOURCES src/comps/mcuxClEcc/src/mcuxClEcc_ArithmeticOperation.c
                src/comps/mcuxClEcc/src/mcuxClEcc_ArithmeticOperation_PointAdd.c
                src/comps/mcuxClEcc/src/mcuxClEcc_ArithmeticOperation_PointAddSub.c
                src/comps/mcuxClEcc/src/mcuxClEcc_ArithmeticOperation_PointSub.c
                src/comps/mcuxClEcc/src/mcuxClEcc_ArithmeticOperation_ScalarMult.c
                src/comps/mcuxClEcc/src/mcuxClEcc_ArithmeticOperation_SecureScalarMult.c
                src/comps/mcuxClEcc/src/mcuxClEcc_Constants.c
                src/comps/mcuxClEcc/src/mcuxClEcc_ECDH_KeyAgreement.c
                src/comps/mcuxClEcc/src/mcuxClEcc_ECDSA_GenerateSignature.c
                src/comps/mcuxClEcc/src/mcuxClEcc_ECDSA_GenerateSignature_FUP.c
                src/comps/mcuxClEcc/src/mcuxClEcc_ECDSA_Internal_PrepareMessageDigest.c
                src/comps/mcuxClEcc/src/mcuxClEcc_ECDSA_VerifySignature.c
                src/comps/mcuxClEcc/src/mcuxClEcc_ECDSA_VerifySignature_FUP.c
                src/comps/mcuxClEcc/src/mcuxClEcc_EdDSA_GenerateKeyPair.c
                src/comps/mcuxClEcc/src/mcuxClEcc_EdDSA_GenerateKeyPair_FUP.c
                src/comps/mcuxClEcc/src/mcuxClEcc_EdDSA_GenerateSignature.c
                src/comps/mcuxClEcc/src/mcuxClEcc_EdDSA_GenerateSignature_FUP.c
                src/comps/mcuxClEcc/src/mcuxClEcc_EdDSA_GenerateSignatureMode.c
                src/comps/mcuxClEcc/src/mcuxClEcc_EdDSA_InitPrivKeyInputMode.c
                src/comps/mcuxClEcc/src/mcuxClEcc_EdDSA_Internal_CalcHashModN_FUP.c
                src/comps/mcuxClEcc/src/mcuxClEcc_EdDSA_Internal_DecodePoint_Ed25519.c
                src/comps/mcuxClEcc/src/mcuxClEcc_EdDSA_Internal_DecodePoint_FUP.c
                src/comps/mcuxClEcc/src/mcuxClEcc_EdDSA_Internal_EncodePoint.c
                src/comps/mcuxClEcc/src/mcuxClEcc_EdDSA_Internal_HashOperations.c
                src/comps/mcuxClEcc/src/mcuxClEcc_EdDSA_Internal_InputParamSanityCheck.c
                src/comps/mcuxClEcc/src/mcuxClEcc_EdDSA_Internal_SetupEnvironment.c
                src/comps/mcuxClEcc/src/mcuxClEcc_EdDSA_Internal_SignatureMechanisms.c
                src/comps/mcuxClEcc/src/mcuxClEcc_EdDSA_VerifySignature.c
                src/comps/mcuxClEcc/src/mcuxClEcc_Internal_BlindedFixScalarMult.c
                src/comps/mcuxClEcc/src/mcuxClEcc_Internal_BlindedVarScalarMult.c
                src/comps/mcuxClEcc/src/mcuxClEcc_Internal_BlindedVarScalarMult_FUP.c
                src/comps/mcuxClEcc/src/mcuxClEcc_Internal_Convert_FUP.c
                src/comps/mcuxClEcc/src/mcuxClEcc_Internal_GenerateMultiplicativeBlinding.c
                src/comps/mcuxClEcc/src/mcuxClEcc_Internal_GenerateMultiplicativeBlinding_FUP.c
                src/comps/mcuxClEcc/src/mcuxClEcc_Internal_IntegrityCheckPN.c
                src/comps/mcuxClEcc/src/mcuxClEcc_Internal_Interleave_FUP.c
                src/comps/mcuxClEcc/src/mcuxClEcc_Internal_InterleaveScalar.c
                src/comps/mcuxClEcc/src/mcuxClEcc_Internal_ModInv.c
                src/comps/mcuxClEcc/src/mcuxClEcc_Internal_PointComparison_FUP.c
                src/comps/mcuxClEcc/src/mcuxClEcc_Internal_Random.c
                src/comps/mcuxClEcc/src/mcuxClEcc_Internal_Random_FUP.c
                src/comps/mcuxClEcc/src/mcuxClEcc_Internal_RecodeAndReorderScalar.c
                src/comps/mcuxClEcc/src/mcuxClEcc_Internal_SecurePointSelectML.c
                src/comps/mcuxClEcc/src/mcuxClEcc_Internal_SecurePtrTableEntrySelect.c
                src/comps/mcuxClEcc/src/mcuxClEcc_Internal_SetupEnvironment.c
                src/comps/mcuxClEcc/src/mcuxClEcc_Internal_SetupEnvironment_FUP.c
                src/comps/mcuxClEcc/src/mcuxClEcc_Internal_Types.c
                src/comps/mcuxClEcc/src/mcuxClEcc_KeyEncodingMechanisms.c
                src/comps/mcuxClEcc/src/mcuxClEcc_KeyTypes.c
                src/comps/mcuxClEcc/src/mcuxClEcc_Mont_Internal_DhSetupEnvironment.c
                src/comps/mcuxClEcc/src/mcuxClEcc_Mont_Internal_MontDhX.c
                src/comps/mcuxClEcc/src/mcuxClEcc_Mont_Internal_MontDhX_FUP.c
                src/comps/mcuxClEcc/src/mcuxClEcc_Mont_Internal_SecureScalarMult_XZMontLadder.c
                src/comps/mcuxClEcc/src/mcuxClEcc_Mont_Internal_SecureScalarMult_XZMontLadder_FUP.c
                src/comps/mcuxClEcc/src/mcuxClEcc_MontDH_GenerateKeyPair.c
                src/comps/mcuxClEcc/src/mcuxClEcc_MontDH_KeyAgreement.c
                src/comps/mcuxClEcc/src/mcuxClEcc_SignatureMechanisms.c
                src/comps/mcuxClEcc/src/mcuxClEcc_TwEd_Internal_Convert_FUP.c
                src/comps/mcuxClEcc/src/mcuxClEcc_TwEd_Internal_FixScalarMult.c
                src/comps/mcuxClEcc/src/mcuxClEcc_TwEd_Internal_PlainFixScalarMult25519.c
                src/comps/mcuxClEcc/src/mcuxClEcc_TwEd_Internal_PlainPtrSelectComb.c
                src/comps/mcuxClEcc/src/mcuxClEcc_TwEd_Internal_PlainPtrSelectML.c
                src/comps/mcuxClEcc/src/mcuxClEcc_TwEd_Internal_PlainVarScalarMult.c
                src/comps/mcuxClEcc/src/mcuxClEcc_TwEd_Internal_PointArithmetic.c
                src/comps/mcuxClEcc/src/mcuxClEcc_TwEd_Internal_PointArithmetic_FUP.c
                src/comps/mcuxClEcc/src/mcuxClEcc_TwEd_Internal_PointArithmeticEd25519.c
                src/comps/mcuxClEcc/src/mcuxClEcc_TwEd_Internal_PointArithmeticEd25519_FUP.c
                src/comps/mcuxClEcc/src/mcuxClEcc_TwEd_Internal_PointSubtraction_FUP.c
                src/comps/mcuxClEcc/src/mcuxClEcc_TwEd_Internal_PointValidation_FUP.c
                src/comps/mcuxClEcc/src/mcuxClEcc_TwEd_Internal_SecureFixScalarMult25519.c
                src/comps/mcuxClEcc/src/mcuxClEcc_TwEd_Internal_SecurePtrSelectComb.c
                src/comps/mcuxClEcc/src/mcuxClEcc_TwEd_Internal_SecureVarScalarMult.c
                src/comps/mcuxClEcc/src/mcuxClEcc_TwEd_Internal_UpdateExtHomCoords_FUP.c
                src/comps/mcuxClEcc/src/mcuxClEcc_TwEd_Internal_VarScalarMult.c
                src/comps/mcuxClEcc/src/mcuxClEcc_TwEd_Internal_VarScalarMult_FUP.c
                src/comps/mcuxClEcc/src/mcuxClEcc_Weier_DecodePoint.c
                src/comps/mcuxClEcc/src/mcuxClEcc_Weier_DecodePoint_FUP.c
                src/comps/mcuxClEcc/src/mcuxClEcc_Weier_GenerateDomainParams.c
                src/comps/mcuxClEcc/src/mcuxClEcc_Weier_GenerateDomainParams_FUP.c
                src/comps/mcuxClEcc/src/mcuxClEcc_Weier_Internal_BooleanToArithmeticMasking.c
                src/comps/mcuxClEcc/src/mcuxClEcc_Weier_Internal_BooleanToArithmeticMasking_FUP.c
                src/comps/mcuxClEcc/src/mcuxClEcc_Weier_Internal_ConvertPoint.c
                src/comps/mcuxClEcc/src/mcuxClEcc_Weier_Internal_ConvertPoint_FUP.c
                src/comps/mcuxClEcc/src/mcuxClEcc_Weier_Internal_DiscriminantCalculate_FUP.c
                src/comps/mcuxClEcc/src/mcuxClEcc_Weier_Internal_DomainParamsCheck.c
                src/comps/mcuxClEcc/src/mcuxClEcc_Weier_Internal_EncTypeSEC.c
                src/comps/mcuxClEcc/src/mcuxClEcc_Weier_Internal_FUP.c
                src/comps/mcuxClEcc/src/mcuxClEcc_Weier_Internal_GenerateKeyPair.c
                src/comps/mcuxClEcc/src/mcuxClEcc_Weier_Internal_GenerateKeyPair_FUP.c
                src/comps/mcuxClEcc/src/mcuxClEcc_Weier_Internal_KeyGen.c
                src/comps/mcuxClEcc/src/mcuxClEcc_Weier_Internal_KeyGen_FUP.c
                src/comps/mcuxClEcc/src/mcuxClEcc_Weier_Internal_KeyValidation.c
                src/comps/mcuxClEcc/src/mcuxClEcc_Weier_Internal_PlainFixScalarMult.c
                src/comps/mcuxClEcc/src/mcuxClEcc_Weier_Internal_PointArithmetic.c
                src/comps/mcuxClEcc/src/mcuxClEcc_Weier_Internal_PointArithmetic_FUP.c
                src/comps/mcuxClEcc/src/mcuxClEcc_Weier_Internal_PointCheck.c
                src/comps/mcuxClEcc/src/mcuxClEcc_Weier_Internal_PointCheck_FUP.c
                src/comps/mcuxClEcc/src/mcuxClEcc_Weier_Internal_PointMult.c
                src/comps/mcuxClEcc/src/mcuxClEcc_Weier_Internal_SecurePointMult_CoZMontLadder.c
                src/comps/mcuxClEcc/src/mcuxClEcc_Weier_Internal_SecurePointMult_CoZMontLadder_FUP.c
                src/comps/mcuxClEcc/src/mcuxClEcc_Weier_Internal_SetupEnvironment.c
                src/comps/mcuxClEcc/src/size/size.c			
				
                src/comps/mcuxClEcc/inc/mcuxClEcc.h
                src/comps/mcuxClEcc/inc/mcuxClEcc_Constants.h
                src/comps/mcuxClEcc/inc/mcuxClEcc_ECDSA_GenerateSignature_FUP.h
                src/comps/mcuxClEcc/inc/mcuxClEcc_ECDSA_VerifySignature_FUP.h
                src/comps/mcuxClEcc/inc/mcuxClEcc_EdDSA_GenerateKeyPair_FUP.h
                src/comps/mcuxClEcc/inc/mcuxClEcc_EdDSA_GenerateSignature_FUP.h
                src/comps/mcuxClEcc/inc/mcuxClEcc_EdDSA_Internal_CalcHashModN_FUP.h
                src/comps/mcuxClEcc/inc/mcuxClEcc_EdDSA_Internal_DecodePoint_FUP.h
                src/comps/mcuxClEcc/inc/mcuxClEcc_Functions.h
                src/comps/mcuxClEcc/inc/mcuxClEcc_Internal_BlindedVarScalarMult_FUP.h
                src/comps/mcuxClEcc/inc/mcuxClEcc_Internal_Convert_FUP.h
                src/comps/mcuxClEcc/inc/mcuxClEcc_Internal_GenerateMultiplicativeBlinding_FUP.h
                src/comps/mcuxClEcc/inc/mcuxClEcc_Internal_Interleave_FUP.h
                src/comps/mcuxClEcc/inc/mcuxClEcc_Internal_PointComparison_FUP.h
                src/comps/mcuxClEcc/inc/mcuxClEcc_Internal_Random_FUP.h
                src/comps/mcuxClEcc/inc/mcuxClEcc_Internal_SetupEnvironment_FUP.h
                src/comps/mcuxClEcc/inc/mcuxClEcc_KeyEncodingMechanisms.h
                src/comps/mcuxClEcc/inc/mcuxClEcc_KeyTypes.h
                src/comps/mcuxClEcc/inc/mcuxClEcc_Mont_Internal_MontDhX_FUP.h
                src/comps/mcuxClEcc/inc/mcuxClEcc_Mont_Internal_SecureScalarMult_XZMontLadder_FUP.h
                src/comps/mcuxClEcc/inc/mcuxClEcc_TwEd_Internal_Convert_FUP.h
                src/comps/mcuxClEcc/inc/mcuxClEcc_TwEd_Internal_PointArithmetic_FUP.h
                src/comps/mcuxClEcc/inc/mcuxClEcc_TwEd_Internal_PointArithmeticEd25519_FUP.h
                src/comps/mcuxClEcc/inc/mcuxClEcc_TwEd_Internal_PointSubtraction_FUP.h
                src/comps/mcuxClEcc/inc/mcuxClEcc_TwEd_Internal_PointValidation_FUP.h
                src/comps/mcuxClEcc/inc/mcuxClEcc_TwEd_Internal_UpdateExtHomCoords_FUP.h
                src/comps/mcuxClEcc/inc/mcuxClEcc_TwEd_Internal_VarScalarMult_FUP.h
                src/comps/mcuxClEcc/inc/mcuxClEcc_Types.h
                src/comps/mcuxClEcc/inc/mcuxClEcc_Weier_DecodePoint_FUP.h
                src/comps/mcuxClEcc/inc/mcuxClEcc_Weier_GenerateDomainParams_FUP.h
                src/comps/mcuxClEcc/inc/mcuxClEcc_Weier_Internal_BooleanToArithmeticMasking_FUP.h
                src/comps/mcuxClEcc/inc/mcuxClEcc_Weier_Internal_ConvertPoint_FUP.h
                src/comps/mcuxClEcc/inc/mcuxClEcc_Weier_Internal_DiscriminantCalculate_FUP.h
                src/comps/mcuxClEcc/inc/mcuxClEcc_Weier_Internal_FUP.h
                src/comps/mcuxClEcc/inc/mcuxClEcc_Weier_Internal_GenerateKeyPair_FUP.h
                src/comps/mcuxClEcc/inc/mcuxClEcc_Weier_Internal_KeyGen_FUP.h
                src/comps/mcuxClEcc/inc/mcuxClEcc_Weier_Internal_PointArithmetic_FUP.h
                src/comps/mcuxClEcc/inc/mcuxClEcc_Weier_Internal_PointCheck_FUP.h
                src/comps/mcuxClEcc/inc/mcuxClEcc_Weier_Internal_SecurePointMult_CoZMontLadder_FUP.h
				
				src/comps/mcuxClEcc/inc/internal/mcuxClEcc_ECDH_Internal.h
                src/comps/mcuxClEcc/inc/internal/mcuxClEcc_ECDSA_Internal.h
                src/comps/mcuxClEcc/inc/internal/mcuxClEcc_EdDSA_Internal.h
                src/comps/mcuxClEcc/inc/internal/mcuxClEcc_EdDSA_Internal_FUP.h
                src/comps/mcuxClEcc/inc/internal/mcuxClEcc_EdDSA_Internal_Hash.h
                src/comps/mcuxClEcc/inc/internal/mcuxClEcc_FeatureConfig.h
                src/comps/mcuxClEcc/inc/internal/mcuxClEcc_Internal.h
                src/comps/mcuxClEcc/inc/internal/mcuxClEcc_Internal_FUP.h
                src/comps/mcuxClEcc/inc/internal/mcuxClEcc_Internal_KeyHelper.h
                src/comps/mcuxClEcc/inc/internal/mcuxClEcc_Internal_MemoryConsumption.h
                src/comps/mcuxClEcc/inc/internal/mcuxClEcc_Internal_PkcWaLayout.h
                src/comps/mcuxClEcc/inc/internal/mcuxClEcc_Internal_Random.h
                src/comps/mcuxClEcc/inc/internal/mcuxClEcc_Internal_UPTRT_access.h
                src/comps/mcuxClEcc/inc/internal/mcuxClEcc_Mont_Internal.h
                src/comps/mcuxClEcc/inc/internal/mcuxClEcc_Mont_Internal_FUP.h
                src/comps/mcuxClEcc/inc/internal/mcuxClEcc_Mont_Internal_PkcWaLayout.h
                src/comps/mcuxClEcc/inc/internal/mcuxClEcc_TwEd_Internal.h
                src/comps/mcuxClEcc/inc/internal/mcuxClEcc_TwEd_Internal_FUP.h
                src/comps/mcuxClEcc/inc/internal/mcuxClEcc_TwEd_Internal_PkcWaLayout.h
                src/comps/mcuxClEcc/inc/internal/mcuxClEcc_Weier_Internal.h
                src/comps/mcuxClEcc/inc/internal/mcuxClEcc_Weier_Internal_FP.h
                src/comps/mcuxClEcc/inc/internal/mcuxClEcc_Weier_Internal_FUP.h
                src/comps/mcuxClEcc/inc/internal/mcuxClEcc_Weier_Internal_PkcWaLayout.h
								
                #src/comps/mcuxClEcc/inc/platform/mcxa/mcuxClEcc_MemoryConsumption.h
                BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
    mcux_add_include(
        INCLUDES ./
                 src/comps/mcuxClEcc/inc
                 src/comps/mcuxClEcc/inc/internal
                 BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.sgi_pkc.example)
    mcux_add_source(
        SOURCES src/comps/mcuxClExample/inc/mcuxClExample_OS.h
                src/comps/mcuxClExample/inc/mcuxClExample_RNG_Helper.h
                src/comps/mcuxClExample/inc/mcuxClExample_Session_Helper.h
                BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
    mcux_add_include(
        INCLUDES ./
                 src/comps/mcuxClExample/inc
                 BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.sgi_pkc.ffdh)
    mcux_add_source(
        SOURCES src/comps/mcuxClFfdh/src/mcuxClFfdh_Constants.c
                src/comps/mcuxClFfdh/src/mcuxClFfdh_KeyAgreement.c
                src/comps/mcuxClFfdh/src/mcuxClFfdh_KeyEncodingMechanisms.c
                src/comps/mcuxClFfdh/src/mcuxClFfdh_KeyTypes.c
                src/comps/mcuxClFfdh/src/mcuxClFfdh_PublicKeyLoadAndValidate.c
                src/comps/mcuxClFfdh/src/mcuxClFfdh_SetupEnvironment.c
                src/comps/mcuxClFfdh/src/size/size.c
				
                src/comps/mcuxClFfdh/inc/mcuxClFfdh.h
                src/comps/mcuxClFfdh/inc/mcuxClFfdh_Constants.h
                src/comps/mcuxClFfdh/inc/mcuxClFfdh_KeyEncodingMechanisms.h
                src/comps/mcuxClFfdh/inc/mcuxClFfdh_KeyTypes.h
                src/comps/mcuxClFfdh/inc/mcuxClFfdh_Types.h
				
                src/comps/mcuxClFfdh/inc/internal/mcuxClFfdh_Internal.h
                src/comps/mcuxClFfdh/inc/internal/mcuxClFfdh_Internal_PkcDefs.h
				
                #src/comps/mcuxClFfdh/inc/platform/mcxa/mcuxClFfdh_MemoryConsumption.h
				
                BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
    mcux_add_include(
        INCLUDES ./
                 src/comps/mcuxClFfdh/inc
                 BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.sgi_pkc.glikey)
    mcux_add_source(
        SOURCES src/comps/mcuxClGlikey/src/mcuxClGlikey.c
                src/comps/mcuxClGlikey/inc/mcuxClGlikey.h
                src/comps/mcuxClGlikey/inc/internal/mcuxClGlikey_SfrAccess.h
                BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
    mcux_add_include(
        INCLUDES ./
                 src/comps/mcuxClGlikey/inc
                 src/comps/mcuxClGlikey/inc/internal
                 BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.sgi_pkc.hash)
    mcux_add_source(
        SOURCES src/comps/mcuxClHash/src/mcuxClHash_api_multipart_common.c
                src/comps/mcuxClHash/src/mcuxClHash_api_multipart_compute.c
                src/comps/mcuxClHash/src/mcuxClHash_api_oneshot_compute.c
                src/comps/mcuxClHash/src/mcuxClHash_api_selftest.c
                src/comps/mcuxClHash/src/mcuxClHash_Internal.c
                src/comps/mcuxClHash/src/mcuxClHash_Oid.c
                src/comps/mcuxClHash/inc/mcuxClHash.h
                src/comps/mcuxClHash/src/size/size.c
                src/comps/mcuxClHash/inc/mcuxClHash.h
                src/comps/mcuxClHash/inc/mcuxClHash_Constants.h
                src/comps/mcuxClHash/inc/mcuxClHash_Functions.h
                src/comps/mcuxClHash/inc/mcuxClHash_Types.h
                src/comps/mcuxClHash/inc/internal/mcuxClHash_Internal.h
                src/comps/mcuxClHash/inc/internal/mcuxClHash_Internal_Memory.h
                #src/comps/mcuxClHash/inc/platform/mcxa/mcuxClHash_MemoryConsumption.h
                BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
    mcux_add_include(
        INCLUDES ./
                 src/comps/mcuxClHash/inc
                 src/comps/mcuxClHash/inc/internal
                 # src/comps/mcuxClHash/inc/platform/mcxa
                 BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.sgi_pkc.hashmodes)
    mcux_add_source(
        SOURCES src/comps/mcuxClHashModes/src/mcuxClHashModes_Core_c_sha3.c
                src/comps/mcuxClHashModes/src/mcuxClHashModes_Internal_c_sha3.c
                src/comps/mcuxClHashModes/src/mcuxClHashModes_Internal_Resource_Common.c
                src/comps/mcuxClHashModes/src/mcuxClHashModes_Internal_sgi_sha2.c
                src/comps/mcuxClHashModes/src/mcuxClHashModes_Internal_sgi_sha2_common.c
                src/comps/mcuxClHashModes/src/mcuxClHashModes_Internal_sgi_sha2_dma_Common.c
                src/comps/mcuxClHashModes/src/mcuxClHashModes_Internal_sgi_sha2_dma_nonBlocking.c
                src/comps/mcuxClHashModes/src/size/size.c
				
                src/comps/mcuxClHashModes/inc/mcuxClHashModes.h
                src/comps/mcuxClHashModes/inc/mcuxClHashModes_Algorithms.h
                src/comps/mcuxClHashModes/inc/mcuxClHashModes_Constants.h
                src/comps/mcuxClHashModes/inc/internal/mcuxClHashModes_Core_c_sha3.h
                src/comps/mcuxClHashModes/inc/internal/mcuxClHashModes_Internal.h
                src/comps/mcuxClHashModes/inc/internal/mcuxClHashModes_Internal_Algorithms.h
                src/comps/mcuxClHashModes/inc/internal/mcuxClHashModes_Internal_Memory.h
                src/comps/mcuxClHashModes/inc/internal/mcuxClHashModes_Internal_nonBlocking.h
                src/comps/mcuxClHashModes/inc/internal/mcuxClHashModes_Internal_Resource_Common.h
                src/comps/mcuxClHashModes/inc/internal/mcuxClHashModes_Internal_sgi_sha2.h
                src/comps/mcuxClHashModes/inc/internal/mcuxClHashModes_Internal_sgi_sha2_common.h
                src/comps/mcuxClHashModes/inc/internal/mcuxClHashModes_MemoryComputation.h
                src/comps/mcuxClHashModes/inc/internal/mcuxClHashModes_ModesConstants.h
                src/comps/mcuxClHashModes/inc/internal/mcuxClHashModes_ModesMemoryMacros.h
                src/comps/mcuxClHashModes/inc/internal/mcuxClHashModes_ModesMemoryMacros_Impl.h
                #src/comps/mcuxClHashModes/inc/platform/mcxa/mcuxClHashModes_MemoryConsumption.h
                BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
    mcux_add_include(
        INCLUDES ./
                 src/comps/mcuxClHashModes/inc
                 src/comps/mcuxClHashModes/inc/internal
                 BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.sgi_pkc.hmac)
    mcux_add_source(
        SOURCES src/comps/mcuxClHmac/src/mcuxClHmac_Cleanup.c
                src/comps/mcuxClHmac/src/mcuxClHmac_Functions.c
                src/comps/mcuxClHmac/src/mcuxClHmac_Helper.c
                src/comps/mcuxClHmac/src/mcuxClHmac_KeyTypes.c
                src/comps/mcuxClHmac/src/mcuxClHmac_Modes.c
                src/comps/mcuxClHmac/src/mcuxClHmac_Sw.c
                src/comps/mcuxClHmac/src/size/size.c
				
                src/comps/mcuxClHmac/inc/mcuxClHmac.h
                src/comps/mcuxClHmac/inc/mcuxClHmac_Constants.h
                src/comps/mcuxClHmac/inc/mcuxClHmac_Functions.h
                src/comps/mcuxClHmac/inc/mcuxClHmac_KeyTypes.h
                src/comps/mcuxClHmac/inc/internal/mcuxClHmac_Core_Functions_Sw.h
                src/comps/mcuxClHmac/inc/internal/mcuxClHmac_Internal_Functions.h
                src/comps/mcuxClHmac/inc/internal/mcuxClHmac_Internal_Memory.h
                src/comps/mcuxClHmac/inc/internal/mcuxClHmac_Internal_Types.h
                #src/comps/mcuxClHmac/inc/platform/mcxa/mcuxClHmac_MemoryConsumption.h
                BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
    mcux_add_include(
        INCLUDES ./
                 src/comps/mcuxClHmac/inc/
                 src/comps/mcuxClHmac/inc/internal
                 BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.sgi_pkc.kdf_modes)
    mcux_add_source(
        SOURCES src/comps/mcuxClKdfModes/src/mcuxClKdfModes_HKDF.c
                src/comps/mcuxClKdfModes/src/mcuxClKdfModes_NIST_SP800_56C.c
                src/comps/mcuxClKdfModes/src/mcuxClKdfModes_NIST_SP800_108.c
                src/comps/mcuxClKdfModes/src/mcuxClKdfModes_PBKDF2.c
                src/comps/mcuxClKdfModes/src/size/size.c
                src/comps/mcuxClKdfModes/inc/mcuxClKdfModes.h
                src/comps/mcuxClKdfModes/inc/mcuxClKdfModes_Algorithms.h
                src/comps/mcuxClKdfModes/inc/mcuxClKdfModes_Algorithms_HKDF.h
                src/comps/mcuxClKdfModes/inc/mcuxClKdfModes_Algorithms_NIST_SP800_56C.h
                src/comps/mcuxClKdfModes/inc/mcuxClKdfModes_Algorithms_NIST_SP800_108.h
                src/comps/mcuxClKdfModes/inc/mcuxClKdfModes_Algorithms_PBKDF2.h
                src/comps/mcuxClKdfModes/inc/mcuxClKdfModes_Constants.h
                src/comps/mcuxClKdfModes/inc/internal/mcuxClKdfModes_Internal_Algorithms.h
                src/comps/mcuxClKdfModes/inc/internal/mcuxClKdfModes_Internal_Functions.h
                BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
    mcux_add_include(
        INCLUDES ./
                 src/comps/mcuxClKdfModes/inc
                 src/comps/mcuxClKdfModes/inc/internal
                 BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.sgi_pkc.key)
    mcux_add_source(
        SOURCES src/comps/mcuxClKey/src/mcuxClKey.c
                src/comps/mcuxClKey/src/mcuxClKey_agreement.c
                src/comps/mcuxClKey/src/mcuxClKey_agreement_selftest.c
                src/comps/mcuxClKey/src/mcuxClKey_Derivation.c
                src/comps/mcuxClKey/src/mcuxClKey_Encoding.c
                src/comps/mcuxClKey/src/mcuxClKey_generate_keypair.c
                src/comps/mcuxClKey/src/mcuxClKey_Validation.c
                src/comps/mcuxClKey/src/size/size.c
                src/comps/mcuxClKey/inc/mcuxClKey.h
                src/comps/mcuxClKey/inc/mcuxClKey_Constants.h
                src/comps/mcuxClKey/inc/mcuxClKey_EncodingMechanisms.h
                src/comps/mcuxClKey/inc/mcuxClKey_Functions.h
                src/comps/mcuxClKey/inc/mcuxClKey_Types.h
                src/comps/mcuxClKey/inc/internal/mcuxClKey_Constants_Internal.h
                src/comps/mcuxClKey/inc/internal/mcuxClKey_FeatureConfig.h
                src/comps/mcuxClKey/inc/internal/mcuxClKey_Functions_Internal.h
                src/comps/mcuxClKey/inc/internal/mcuxClKey_Internal.h
                src/comps/mcuxClKey/inc/internal/mcuxClKey_Internal_EncodingMechanisms.h
                src/comps/mcuxClKey/inc/internal/mcuxClKey_Types_Internal.h
                #src/comps/mcuxClKey/inc/platform/mcxa/mcuxClKey_MemoryConsumption.h
                BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
    mcux_add_include(
        INCLUDES ./
                 src/comps/mcuxClKey/inc
                 src/comps/mcuxClKey/inc/internal
                 BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.sgi_pkc.mac)
    mcux_add_source(
        SOURCES src/comps/mcuxClMac/src/mcuxClMac.c
                src/comps/mcuxClMac/inc/mcuxClMac.h
                src/comps/mcuxClMac/inc/mcuxClMac_Constants.h
                src/comps/mcuxClMac/inc/mcuxClMac_Functions.h
                src/comps/mcuxClMac/inc/mcuxClMac_Types.h
                src/comps/mcuxClMac/inc/internal/mcuxClMac_Ctx.h
                src/comps/mcuxClMac/inc/internal/mcuxClMac_Internal_Constants.h
                src/comps/mcuxClMac/inc/internal/mcuxClMac_Internal_Types.h
                BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
    mcux_add_include(
        INCLUDES ./
                 src/comps/mcuxClMac/inc/
                 src/comps/mcuxClMac/inc/internal
                 BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.sgi_pkc.mac_modes)
    mcux_add_source(
        SOURCES src/comps/mcuxClMacModes/src/mcuxClMacModes_Common.c
                src/comps/mcuxClMacModes/src/mcuxClMacModes_Sgi_Cbcmac.c
                src/comps/mcuxClMacModes/src/mcuxClMacModes_Sgi_Cleanup.c
                src/comps/mcuxClMacModes/src/mcuxClMacModes_Sgi_Cmac.c
                src/comps/mcuxClMacModes/src/mcuxClMacModes_Sgi_Cmac_Dma_NonBlocking.c
                src/comps/mcuxClMacModes/src/mcuxClMacModes_Sgi_Cmac_DmaDriven.c
                src/comps/mcuxClMacModes/src/mcuxClMacModes_Sgi_Functions.c
                src/comps/mcuxClMacModes/src/mcuxClMacModes_Sgi_Functions_DmaDriven.c
                src/comps/mcuxClMacModes/src/mcuxClMacModes_Sgi_Gmac.c
                src/comps/mcuxClMacModes/src/mcuxClMacModes_Sgi_Helper.c
                src/comps/mcuxClMacModes/src/mcuxClMacModes_Sgi_Modes.c
                src/comps/mcuxClMacModes/src/size/size.c
                src/comps/mcuxClMacModes/inc/mcuxClMacModes.h
                src/comps/mcuxClMacModes/inc/mcuxClMacModes_Constants.h
                src/comps/mcuxClMacModes/inc/mcuxClMacModes_Functions.h
                src/comps/mcuxClMacModes/inc/mcuxClMacModes_Modes.h
                src/comps/mcuxClMacModes/inc/internal/mcuxClMacModes_Common_Constants.h
                src/comps/mcuxClMacModes/inc/internal/mcuxClMacModes_Common_Functions.h
                src/comps/mcuxClMacModes/inc/internal/mcuxClMacModes_Common_Memory.h
                src/comps/mcuxClMacModes/inc/internal/mcuxClMacModes_Common_Types.h
                src/comps/mcuxClMacModes/inc/internal/mcuxClMacModes_Common_Wa.h
                src/comps/mcuxClMacModes/inc/internal/mcuxClMacModes_Sgi_Algorithms.h
                src/comps/mcuxClMacModes/inc/internal/mcuxClMacModes_Sgi_Cbcmac.h
                src/comps/mcuxClMacModes/inc/internal/mcuxClMacModes_Sgi_Cleanup.h
                src/comps/mcuxClMacModes/inc/internal/mcuxClMacModes_Sgi_Cmac.h
                src/comps/mcuxClMacModes/inc/internal/mcuxClMacModes_Sgi_Ctx.h
                src/comps/mcuxClMacModes/inc/internal/mcuxClMacModes_Sgi_Functions.h
                src/comps/mcuxClMacModes/inc/internal/mcuxClMacModes_Sgi_Gmac.h
                src/comps/mcuxClMacModes/inc/internal/mcuxClMacModes_Sgi_Types.h
                #src/comps/mcuxClMacModes/inc/platform/mcxa/mcuxClMacModes_MemoryConsumption.h
                BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
    mcux_add_include(
        INCLUDES ./
                 src/comps/mcuxClMacModes/inc
                 src/comps/mcuxClMacModes/inc/internal
                 BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.sgi_pkc.math)
    mcux_add_source(
        SOURCES src/comps/mcuxClMath/src/mcuxClMath_ExactDivide.c
                src/comps/mcuxClMath/src/mcuxClMath_ExactDivideOdd.c
                src/comps/mcuxClMath/src/mcuxClMath_ExactDivideOdd_FUP.c
                src/comps/mcuxClMath/src/mcuxClMath_ModExp_SqrMultL2R.c
                src/comps/mcuxClMath/src/mcuxClMath_ModInv.c
                src/comps/mcuxClMath/src/mcuxClMath_ModInv_FUP.c
                src/comps/mcuxClMath/src/mcuxClMath_ModSquareRoot.c
                src/comps/mcuxClMath/src/mcuxClMath_NDash.c
                src/comps/mcuxClMath/src/mcuxClMath_NDash_FUP.c
                src/comps/mcuxClMath/src/mcuxClMath_QDash.c
                src/comps/mcuxClMath/src/mcuxClMath_QDash_FUP.c
                src/comps/mcuxClMath/src/mcuxClMath_ReduceModEven.c
                src/comps/mcuxClMath/src/mcuxClMath_SecModExp.c
                src/comps/mcuxClMath/src/mcuxClMath_SecModExp_FUP.c
                src/comps/mcuxClMath/src/mcuxClMath_Utils.c
                src/comps/mcuxClMath/inc/mcuxClMath_ExactDivideOdd_FUP.h
                src/comps/mcuxClMath/inc/mcuxClMath_ModInv_FUP.h
                src/comps/mcuxClMath/inc/mcuxClMath_NDash_FUP.h
                src/comps/mcuxClMath/inc/mcuxClMath_QDash_FUP.h
                src/comps/mcuxClMath/inc/mcuxClMath_SecModExp_FUP.h
                src/comps/mcuxClMath/inc/internal/mcuxClMath_ExactDivideOdd_FUP.h
                src/comps/mcuxClMath/inc/internal/mcuxClMath_Internal.h
                src/comps/mcuxClMath/inc/internal/mcuxClMath_Internal_ExactDivideOdd.h
                src/comps/mcuxClMath/inc/internal/mcuxClMath_Internal_Functions.h
                src/comps/mcuxClMath/inc/internal/mcuxClMath_Internal_ModInv.h
                src/comps/mcuxClMath/inc/internal/mcuxClMath_Internal_ModSquareRoot.h
                src/comps/mcuxClMath/inc/internal/mcuxClMath_Internal_NDash.h
                src/comps/mcuxClMath/inc/internal/mcuxClMath_Internal_QDash.h
                src/comps/mcuxClMath/inc/internal/mcuxClMath_Internal_SecModExp.h
                src/comps/mcuxClMath/inc/internal/mcuxClMath_Internal_Types.h
                src/comps/mcuxClMath/inc/internal/mcuxClMath_Internal_Utils.h
                src/comps/mcuxClMath/inc/internal/mcuxClMath_ModInv_FUP.h
                src/comps/mcuxClMath/inc/internal/mcuxClMath_NDash_FUP.h
                src/comps/mcuxClMath/inc/internal/mcuxClMath_QDash_FUP.h
                src/comps/mcuxClMath/inc/internal/mcuxClMath_SecModExp_FUP.h
                BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
    mcux_add_include(
        INCLUDES ./
                 src/comps/mcuxClMath/inc/
                 src/comps/mcuxClMath/inc/internal
                 BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.sgi_pkc.memory)
    mcux_add_source(
        SOURCES src/comps/mcuxClMemory/src/mcuxClMemory.c
                src/comps/mcuxClMemory/src/mcuxClMemory_Internal.c
                src/comps/mcuxClMemory/inc/mcuxClMemory.h
                src/comps/mcuxClMemory/inc/mcuxClMemory_Clear.h
                src/comps/mcuxClMemory/inc/mcuxClMemory_Constants.h
                src/comps/mcuxClMemory/inc/mcuxClMemory_Copy.h
                src/comps/mcuxClMemory/inc/mcuxClMemory_Copy_Reversed.h
                src/comps/mcuxClMemory/inc/mcuxClMemory_Endianness.h
                src/comps/mcuxClMemory/inc/mcuxClMemory_Set.h
                src/comps/mcuxClMemory/inc/mcuxClMemory_Types.h
                src/comps/mcuxClMemory/inc/mcuxClMemory_Xor.h
                src/comps/mcuxClMemory/inc/internal/mcuxClMemory_Clear_Internal.h
                src/comps/mcuxClMemory/inc/internal/mcuxClMemory_ClearSecure_Internal.h
                src/comps/mcuxClMemory/inc/internal/mcuxClMemory_Compare_Internal.h
                src/comps/mcuxClMemory/inc/internal/mcuxClMemory_CompareDPASecure_Internal.h
                src/comps/mcuxClMemory/inc/internal/mcuxClMemory_CompareRev_Internal.h
                src/comps/mcuxClMemory/inc/internal/mcuxClMemory_CompareSecure_Internal.h
                src/comps/mcuxClMemory/inc/internal/mcuxClMemory_Copy_Internal.h
                src/comps/mcuxClMemory/inc/internal/mcuxClMemory_CopySecure_Reversed_Internal.h
                src/comps/mcuxClMemory/inc/internal/mcuxClMemory_CopySecure_Internal.h
                src/comps/mcuxClMemory/inc/internal/mcuxClMemory_Copy_Reversed_Internal.h
                src/comps/mcuxClMemory/inc/internal/mcuxClMemory_CopyWords_Internal.h
                src/comps/mcuxClMemory/inc/internal/mcuxClMemory_FeatureConfig.h
                src/comps/mcuxClMemory/inc/internal/mcuxClMemory_Internal.h
                src/comps/mcuxClMemory/inc/internal/mcuxClMemory_Set_Internal.h
                src/comps/mcuxClMemory/inc/internal/mcuxClMemory_SetSecure_Internal.h
                src/comps/mcuxClMemory/inc/internal/mcuxClMemory_XOR_Internal.h
                src/comps/mcuxClMemory/inc/internal/mcuxClMemory_XORSecure_Internal.h
                src/comps/mcuxClMemory/inc/internal/mcuxClMemory_XORSecureWithConst_Internal.h
				
				
                src/comps/mcuxCsslMemory/src/mcuxCsslMemory_Clear.c
                src/comps/mcuxCsslMemory/src/mcuxCsslMemory_Compare.c
                src/comps/mcuxCsslMemory/src/mcuxCsslMemory_Copy.c
                src/comps/mcuxCsslMemory/src/mcuxCsslMemory_Internal_SecureSet.c
                src/comps/mcuxCsslMemory/src/mcuxCsslMemory_Internal_Set.c
                src/comps/mcuxCsslMemory/src/mcuxCsslMemory_Internal_XOR.c
                src/comps/mcuxCsslMemory/src/mcuxCsslMemory_SecureCompare.c
                src/comps/mcuxCsslMemory/src/mcuxCsslMemory_SecureCopy.c
                src/comps/mcuxCsslMemory/src/mcuxCsslMemory_SecureSet.c
                src/comps/mcuxCsslMemory/src/mcuxCsslMemory_SecureXOR.c
                src/comps/mcuxCsslMemory/src/mcuxCsslMemory_Set.c
				
                src/comps/mcuxCsslMemory/src/asm/mcuxCsslMemory_Compare_arm_asm.S
                src/comps/mcuxCsslMemory/src/asm/mcuxCsslMemory_FastCompare_arm_asm.S
                src/comps/mcuxCsslMemory/src/asm/mcuxCsslMemory_FastCompareRev_arm_asm.S
                src/comps/mcuxCsslMemory/src/asm/mcuxCsslMemory_Internal_Copy_arm_asm.S
                src/comps/mcuxCsslMemory/src/asm/mcuxCsslMemory_Internal_CopyRev_arm_asm.S
                src/comps/mcuxCsslMemory/src/asm/mcuxCsslMemory_Internal_SecureCompare_arm_asm.S
                src/comps/mcuxCsslMemory/src/asm/mcuxCsslMemory_Internal_SecureCopy_arm_asm.S
                src/comps/mcuxCsslMemory/src/asm/mcuxCsslMemory_Internal_SecureCopyRev_arm_asm.S
                src/comps/mcuxCsslMemory/src/asm/mcuxCsslMemory_Internal_SecureXOR_arm_asm.S
                src/comps/mcuxCsslMemory/src/asm/mcuxCsslMemory_Internal_SecureXORRev_arm_asm.S
                src/comps/mcuxCsslMemory/src/asm/mcuxCsslMemory_Internal_SecureXORWithConst_arm_asm.S
				
                src/comps/mcuxCsslMemory/src/size/size.c
				
                src/comps/mcuxCsslMemory/inc/mcuxCsslMemory.h
                src/comps/mcuxCsslMemory/inc/mcuxCsslMemory_Clear.h 
                src/comps/mcuxCsslMemory/inc/mcuxCsslMemory_Compare.h
                src/comps/mcuxCsslMemory/inc/mcuxCsslMemory_Constants.h
                src/comps/mcuxCsslMemory/inc/mcuxCsslMemory_Copy.h
                src/comps/mcuxCsslMemory/inc/mcuxCsslMemory_SecureCompare.h
                src/comps/mcuxCsslMemory/inc/mcuxCsslMemory_SecureCopy.h
                src/comps/mcuxCsslMemory/inc/mcuxCsslMemory_SecureSet.h
                src/comps/mcuxCsslMemory/inc/mcuxCsslMemory_SecureXOR.h
                src/comps/mcuxCsslMemory/inc/mcuxCsslMemory_Set.h
                src/comps/mcuxCsslMemory/inc/mcuxCsslMemory_Types.h
				
                src/comps/mcuxCsslMemory/inc/internal/mcuxCsslMemory_Internal_AssemblyMacros.h
                src/comps/mcuxCsslMemory/inc/internal/mcuxCsslMemory_Internal_Compare.h
                src/comps/mcuxCsslMemory/inc/internal/mcuxCsslMemory_Internal_Compare_arm_asm.h
                src/comps/mcuxCsslMemory/inc/internal/mcuxCsslMemory_Internal_CompareRev_arm_asm.h
                src/comps/mcuxCsslMemory/inc/internal/mcuxCsslMemory_Internal_Copy_arm_asm.h
                src/comps/mcuxCsslMemory/inc/internal/mcuxCsslMemory_Internal_Copy_asm.h
                src/comps/mcuxCsslMemory/inc/internal/mcuxCsslMemory_Internal_CopyRev_arm_asm.h
                src/comps/mcuxCsslMemory/inc/internal/mcuxCsslMemory_Internal_SecureCompare.h
                src/comps/mcuxCsslMemory/inc/internal/mcuxCsslMemory_Internal_SecureCompare_arm_asm.h
                src/comps/mcuxCsslMemory/inc/internal/mcuxCsslMemory_Internal_SecureCopy.h
                src/comps/mcuxCsslMemory/inc/internal/mcuxCsslMemory_Internal_SecureSet.h
                src/comps/mcuxCsslMemory/inc/internal/mcuxCsslMemory_Internal_SecureXOR.h
                src/comps/mcuxCsslMemory/inc/internal/mcuxCsslMemory_Internal_Set.h
                src/comps/mcuxCsslMemory/inc/internal/mcuxCsslMemory_Internal_XOR.h
				
                BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
    mcux_add_include(
        INCLUDES ./
                 src/comps/mcuxClMemory/inc
                 src/comps/mcuxClMemory/inc/internal
                src/comps/mcuxCsslMemory/inc
                src/comps/mcuxCsslMemory/inc/internal
                 BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.sgi_pkc.padding)
    mcux_add_source(
        SOURCES src/comps/mcuxClPadding/src/mcuxClPadding.c
                src/comps/mcuxClPadding/inc/mcuxClPadding.h
                src/comps/mcuxClPadding/inc/mcuxClPadding_Constants.h
                src/comps/mcuxClPadding/inc/mcuxClPadding_Types.h
                src/comps/mcuxClPadding/inc/internal/mcuxClPadding_Functions_Internal.h
                src/comps/mcuxClPadding/inc/internal/mcuxClPadding_Internal.h
                src/comps/mcuxClPadding/inc/internal/mcuxClPadding_Types_Internal.h
                BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
    mcux_add_include(
        INCLUDES ./
                 src/comps/mcuxClPadding/inc/
                 src/comps/mcuxClPadding/inc/internal/
                 BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.sgi_pkc.pkc)
    mcux_add_source(
        SOURCES src/comps/mcuxClPkc/src/mcuxClPkc_Calculate.c
                src/comps/mcuxClPkc/src/mcuxClPkc_ImportExport.c
                src/comps/mcuxClPkc/src/mcuxClPkc_Initialize.c
                src/comps/mcuxClPkc/src/mcuxClPkc_UPTRT.c
                src/comps/mcuxClPkc/inc/internal/mcuxClPkc_BasicDefs.h
                src/comps/mcuxClPkc/inc/internal/mcuxClPkc_FupMacros.h
                src/comps/mcuxClPkc/inc/internal/mcuxClPkc_ImportExport.h
                src/comps/mcuxClPkc/inc/internal/mcuxClPkc_Inline_Functions.h
                src/comps/mcuxClPkc/inc/internal/mcuxClPkc_Internal.h
                src/comps/mcuxClPkc/inc/internal/mcuxClPkc_Internal_Functions.h
                src/comps/mcuxClPkc/inc/internal/mcuxClPkc_Internal_Types.h
                src/comps/mcuxClPkc/inc/internal/mcuxClPkc_Macros.h
                src/comps/mcuxClPkc/inc/internal/mcuxClPkc_Operations.h
                src/comps/mcuxClPkc/inc/internal/mcuxClPkc_Resource.h
                src/comps/mcuxClPkc/inc/internal/mcuxClPkc_SfrAccess.h
                BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
    mcux_add_include(
        INCLUDES ./
                 src/comps/mcuxClPkc/inc/
                 src/comps/mcuxClPkc/inc/internal
                 BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
	mcux_add_linker_symbol(
    SYMBOLS __pkc__=1
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.sgi_pkc.prng)
    mcux_add_source(
        SOURCES src/comps/mcuxClPrng/src/mcuxClPrng.c
                src/comps/mcuxClPrng/inc/internal/mcuxClPrng_Internal.h
                src/comps/mcuxClPrng/inc/internal/mcuxClPrng_Internal_Functions.h
                src/comps/mcuxClPrng/inc/internal/mcuxClPrng_Internal_Types.h
                BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
    mcux_add_include(
        INCLUDES ./
                 src/comps/mcuxClPrng/inc
                 src/comps/mcuxClPrng/inc/internal
                 BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.sgi_pkc.random)
    mcux_add_source(
        SOURCES src/comps/mcuxClRandom/src/mcuxClRandom_DRBG.c
                src/comps/mcuxClRandom/src/mcuxClRandom_PRNG.c
                src/comps/mcuxClRandom/inc/mcuxClRandom.h
                src/comps/mcuxClRandom/inc/mcuxClRandom_Constants.h
                src/comps/mcuxClRandom/inc/mcuxClRandom_Functions.h
                src/comps/mcuxClRandom/inc/mcuxClRandom_MemoryConsumption.h
                src/comps/mcuxClRandom/inc/mcuxClRandom_Types.h
                src/comps/mcuxClRandom/inc/internal/mcuxClRandom_Internal_Functions.h
                src/comps/mcuxClRandom/inc/internal/mcuxClRandom_Internal_Types.h
                BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
    mcux_add_include(
        INCLUDES ./
                 src/comps/mcuxClRandom/inc
                 src/comps/mcuxClRandom/inc/internal
                 BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.sgi_pkc.random_modes)
    mcux_add_source(
        SOURCES src/comps/mcuxClRandomModes/src/mcuxClRandomModes_CtrDrbg.c
                src/comps/mcuxClRandomModes/src/mcuxClRandomModes_CtrDrbg_PrDisabled.c
                src/comps/mcuxClRandomModes/src/mcuxClRandomModes_CtrDrbg_Sgi.c
                src/comps/mcuxClRandomModes/src/mcuxClRandomModes_ExitGates.c
                src/comps/mcuxClRandomModes/src/mcuxClRandomModes_NormalMode.c
                src/comps/mcuxClRandomModes/src/mcuxClRandomModes_PatchMode.c
                src/comps/mcuxClRandomModes/src/mcuxClRandomModes_PrDisabled.c
                src/comps/mcuxClRandomModes/src/mcuxClRandomModes_TestMode.c
                src/comps/mcuxClRandomModes/src/size/size.c
                src/comps/mcuxClRandomModes/inc/mcuxClRandomModes.h
                src/comps/mcuxClRandomModes/inc/mcuxClRandomModes_Constants.h
                src/comps/mcuxClRandomModes/inc/mcuxClRandomModes_Functions_PatchMode.h
                src/comps/mcuxClRandomModes/inc/mcuxClRandomModes_Functions_TestMode.h
                src/comps/mcuxClRandomModes/inc/internal/mcuxClRandomModes_Internal_SizeDefinitions.h
                src/comps/mcuxClRandomModes/inc/internal/mcuxClRandomModes_Private_CtrDrbg.h
                src/comps/mcuxClRandomModes/inc/internal/mcuxClRandomModes_Private_Drbg.h
                src/comps/mcuxClRandomModes/inc/internal/mcuxClRandomModes_Private_ExitGates.h
                src/comps/mcuxClRandomModes/inc/internal/mcuxClRandomModes_Private_NormalMode.h
                src/comps/mcuxClRandomModes/inc/internal/mcuxClRandomModes_Private_PatchMode.h
                src/comps/mcuxClRandomModes/inc/internal/mcuxClRandomModes_Private_PrDisabled.h
                src/comps/mcuxClRandomModes/inc/internal/mcuxClRandomModes_Private_TestMode.h
                #src/comps/mcuxClRandomModes/inc/platform/mcxa/mcuxClRandomModes_MemoryConsumption.h
                BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
    mcux_add_include(
        INCLUDES ./
                 src/comps/mcuxClRandomModes/inc
                 src/comps/mcuxClRandomModes/inc/internal
                 BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.sgi_pkc.resource)
    mcux_add_source(
        SOURCES src/comps/mcuxClResource/src/mcuxClResource.c
                src/comps/mcuxClResource/src/size/size.c
                src/comps/mcuxClResource/inc/mcuxClResource.h
                src/comps/mcuxClResource/inc/mcuxClResource_Functions.h
                src/comps/mcuxClResource/inc/mcuxClResource_Types.h
                src/comps/mcuxClResource/inc/internal/mcuxClResource_Internal_Functions.h
                src/comps/mcuxClResource/inc/internal/mcuxClResource_Internal_Types.h
                #src/comps/mcuxClResource/inc/platform/mcxa/mcuxClResource_MemoryConsumption.h
                BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
    mcux_add_include(
        INCLUDES ./
                 src/comps/mcuxClResource/inc
                 src/comps/mcuxClResource/inc/internal
                #src/comps/mcuxClResource/inc/platform/mcxa/
                 BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.sgi_pkc.rsa)
    mcux_add_source(
        SOURCES src/comps/mcuxClRsa/src/mcuxClRsa_ComputeD.c
                src/comps/mcuxClRsa/src/mcuxClRsa_ComputeD_FUP.c
                src/comps/mcuxClRsa/src/mcuxClRsa_GenerateProbablePrime.c
                src/comps/mcuxClRsa/src/mcuxClRsa_getMillerRabinTestIterations.c
                src/comps/mcuxClRsa/src/mcuxClRsa_KeyGeneration_GenerateKeyPair.c
                src/comps/mcuxClRsa/src/mcuxClRsa_KeyLoadStore.c
                src/comps/mcuxClRsa/src/mcuxClRsa_KeyTypes.c
                src/comps/mcuxClRsa/src/mcuxClRsa_Mgf1.c
                src/comps/mcuxClRsa/src/mcuxClRsa_MillerRabinTest.c
                src/comps/mcuxClRsa/src/mcuxClRsa_MillerRabinTest_FUP.c
                src/comps/mcuxClRsa/src/mcuxClRsa_ModeConstructors.c
                src/comps/mcuxClRsa/src/mcuxClRsa_ModInv.c
                src/comps/mcuxClRsa/src/mcuxClRsa_ModInv_FUP.c
                src/comps/mcuxClRsa/src/mcuxClRsa_OaepDecode.c
                src/comps/mcuxClRsa/src/mcuxClRsa_OaepEncode.c
                src/comps/mcuxClRsa/src/mcuxClRsa_pkcs1v15Decode_decrypt.c
                src/comps/mcuxClRsa/src/mcuxClRsa_Pkcs1v15Encode_encrypt.c
                src/comps/mcuxClRsa/src/mcuxClRsa_Pkcs1v15Encode_sign.c
                src/comps/mcuxClRsa/src/mcuxClRsa_Pkcs1v15Verify.c
                src/comps/mcuxClRsa/src/mcuxClRsa_PrivateCrt.c
                src/comps/mcuxClRsa/src/mcuxClRsa_PrivateCrt_FUP.c
                src/comps/mcuxClRsa/src/mcuxClRsa_PrivatePlain.c
                src/comps/mcuxClRsa/src/mcuxClRsa_PssEncode.c
                src/comps/mcuxClRsa/src/mcuxClRsa_PssVerify.c
                src/comps/mcuxClRsa/src/mcuxClRsa_Public.c
                src/comps/mcuxClRsa/src/mcuxClRsa_PublicExp.c
                src/comps/mcuxClRsa/src/mcuxClRsa_RemoveBlinding.c
                src/comps/mcuxClRsa/src/mcuxClRsa_RemoveBlinding_FUP.c
                src/comps/mcuxClRsa/src/mcuxClRsa_TestPQDistance.c
                src/comps/mcuxClRsa/src/mcuxClRsa_TestPQDistance_FUP.c
                src/comps/mcuxClRsa/src/mcuxClRsa_TestPrimeCandidate.c
                src/comps/mcuxClRsa/src/mcuxClRsa_TestPrimeCandidate_FUP.c
                src/comps/mcuxClRsa/src/mcuxClRsa_Util_Decrypt.c
                src/comps/mcuxClRsa/src/mcuxClRsa_Util_Encrypt.c
                src/comps/mcuxClRsa/src/mcuxClRsa_Util_KeyGeneration_Crt.c
                src/comps/mcuxClRsa/src/mcuxClRsa_Util_KeyGeneration_Crt_FUP.c
                src/comps/mcuxClRsa/src/mcuxClRsa_Util_KeyGeneration_Helper.c
                src/comps/mcuxClRsa/src/mcuxClRsa_Util_KeyGeneration_Plain.c
                src/comps/mcuxClRsa/src/mcuxClRsa_Util_KeyGeneration_Plain_FUP.c
                src/comps/mcuxClRsa/src/mcuxClRsa_Util_Sign.c
                src/comps/mcuxClRsa/src/mcuxClRsa_Util_Verify.c
                src/comps/mcuxClRsa/src/mcuxClRsa_VerifyE.c
                src/comps/mcuxClRsa/src/size/size.c
				
                src/comps/mcuxClRsa/inc/mcuxClRsa.h
                src/comps/mcuxClRsa/inc/mcuxClRsa_ComputeD_FUP.h
                src/comps/mcuxClRsa/inc/mcuxClRsa_Functions.h
                src/comps/mcuxClRsa/inc/mcuxClRsa_KeyTypes.h
                src/comps/mcuxClRsa/inc/mcuxClRsa_MillerRabinTest_FUP.h
                src/comps/mcuxClRsa/inc/mcuxClRsa_ModeConstructors.h
                src/comps/mcuxClRsa/inc/mcuxClRsa_ModInv_FUP.h
                src/comps/mcuxClRsa/inc/mcuxClRsa_PrivateCrt_FUP.h
                src/comps/mcuxClRsa/inc/mcuxClRsa_RemoveBlinding_FUP.h
                src/comps/mcuxClRsa/inc/mcuxClRsa_TestPQDistance_FUP.h
                src/comps/mcuxClRsa/inc/mcuxClRsa_TestPrimeCandidate_FUP.h
                src/comps/mcuxClRsa/inc/mcuxClRsa_Types.h
                src/comps/mcuxClRsa/inc/mcuxClRsa_Util_KeyGeneration_Crt_FUP.h
                src/comps/mcuxClRsa/inc/mcuxClRsa_Util_KeyGeneration_Plain_FUP.h
				
				src/comps/mcuxClRsa/inc/internal/mcuxClRsa_ComputeD_FUP.h
                src/comps/mcuxClRsa/inc/internal/mcuxClRsa_Internal_Functions.h
                src/comps/mcuxClRsa/inc/internal/mcuxClRsa_Internal_Macros.h
                src/comps/mcuxClRsa/inc/internal/mcuxClRsa_Internal_MemoryConsumption.h
                src/comps/mcuxClRsa/inc/internal/mcuxClRsa_Internal_PkcDefs.h
                src/comps/mcuxClRsa/inc/internal/mcuxClRsa_Internal_PkcTypes.h
                src/comps/mcuxClRsa/inc/internal/mcuxClRsa_Internal_Types.h
                src/comps/mcuxClRsa/inc/internal/mcuxClRsa_MillerRabinTest_FUP.h
                src/comps/mcuxClRsa/inc/internal/mcuxClRsa_ModInv_FUP.h
                src/comps/mcuxClRsa/inc/internal/mcuxClRsa_PrivateCrt_FUP.h
                src/comps/mcuxClRsa/inc/internal/mcuxClRsa_RemoveBlinding_FUP.h
                src/comps/mcuxClRsa/inc/internal/mcuxClRsa_TestPQDistance_FUP.h
                src/comps/mcuxClRsa/inc/internal/mcuxClRsa_TestPrimeCandidate_FUP.h
                src/comps/mcuxClRsa/inc/internal/mcuxClRsa_Util_KeyGeneration_Crt_FUP.h
                src/comps/mcuxClRsa/inc/internal/mcuxClRsa_Util_KeyGeneration_Plain_FUP.h
				
                #src/comps/mcuxClRsa/inc/platform/mcxa/mcuxClRsa_MemoryConsumption.h
                BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
    mcux_add_include(
        INCLUDES ./
                 src/comps/mcuxClRsa/inc
                 src/comps/mcuxClRsa/inc/internal
                 BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.sgi_pkc.session)
    mcux_add_source(
        SOURCES src/comps/mcuxClSession/src/mcuxClSession.c
                src/comps/mcuxClSession/src/mcuxClSession_jobHandling.c
                src/comps/mcuxClSession/src/size/size.c
                src/comps/mcuxClSession/src/asm/mcuxClSession_Internal_EntryExit_EarlyExit_Entry_arm.S
                src/comps/mcuxClSession/src/asm/mcuxClSession_Internal_EntryExit_EarlyExit_Return_arm.S
				
                src/comps/mcuxClSession/inc/mcuxClSession.h
                src/comps/mcuxClSession/inc/mcuxClSession_Functions.h
                src/comps/mcuxClSession/inc/mcuxClSession_Types.h
				
                src/comps/mcuxClSession/inc/internal/mcuxClSession_FeatureConfig.h
                src/comps/mcuxClSession/inc/internal/mcuxClSession_Internal.h
                src/comps/mcuxClSession/inc/internal/mcuxClSession_Internal_EntryExit.h
                src/comps/mcuxClSession/inc/internal/mcuxClSession_Internal_EntryExit_EarlyExit.h
                src/comps/mcuxClSession/inc/internal/mcuxClSession_Internal_EntryExit_EarlyExit_Types.h
                src/comps/mcuxClSession/inc/internal/mcuxClSession_Internal_Functions.h
                #src/comps/mcuxClSession/inc/platform/mcxa/mcuxClSession_Internal_AssemblyHeader.h
                #src/comps/mcuxClSession/inc/platform/mcxa/mcuxClSession_MemoryConsumption.h
				
                BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
    mcux_add_include(
        INCLUDES ./
                 src/comps/mcuxClSession/inc
                 src/comps/mcuxClSession/inc/internal
                 BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.sgi_pkc.sgi)
    mcux_add_source(
        SOURCES src/comps/mcuxClSgi/src/mcuxClSgi_Drv.c
                src/comps/mcuxClSgi/src/mcuxClSgi_Utils.c
                src/comps/mcuxClSgi/inc/mcuxClSgi_Constants.h
                src/comps/mcuxClSgi/inc/mcuxClSgi_Types.h
                src/comps/mcuxClSgi/inc/internal/mcuxClSgi_Drv.h
                src/comps/mcuxClSgi/inc/internal/mcuxClSgi_Internal_Types.h
                src/comps/mcuxClSgi/inc/internal/mcuxClSgi_Sfr_Ctrl.h
                src/comps/mcuxClSgi/inc/internal/mcuxClSgi_Sfr_RegBank.h
                src/comps/mcuxClSgi/inc/internal/mcuxClSgi_Sfr_Sec.h
                src/comps/mcuxClSgi/inc/internal/mcuxClSgi_Sfr_Status.h
                src/comps/mcuxClSgi/inc/internal/mcuxClSgi_SfrAccess.h
                src/comps/mcuxClSgi/inc/internal/mcuxClSgi_Utils.h
                BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
    mcux_add_include(
        INCLUDES ./
                 src/comps/mcuxClSgi/inc
                 src/comps/mcuxClSgi/inc/internal
                 BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.sgi_pkc.signature)
    mcux_add_source(
        SOURCES src/comps/mcuxClSignature/src/mcuxClSignature.c
                src/comps/mcuxClSignature/src/size/size.c
                src/comps/mcuxClSignature/inc/mcuxClSignature.h
                src/comps/mcuxClSignature/inc/mcuxClSignature_Constants.h
                src/comps/mcuxClSignature/inc/mcuxClSignature_Functions.h
                src/comps/mcuxClSignature/inc/mcuxClSignature_Types.h
                src/comps/mcuxClSignature/inc/internal/mcuxClSignature_Internal.h
                #src/comps/mcuxClSignature/inc/platform/mcxa/mcuxClSignature_MemoryConsumption.h
				
                BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
    mcux_add_include(
        INCLUDES ./
                 src/comps/mcuxClSignature/inc
                 src/comps/mcuxClSignature/inc/internal
                 BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.sgi_pkc.trng)
    mcux_add_source(
        SOURCES src/comps/mcuxClTrng/src/mcuxClTrng_SA_TRNG.c
                src/comps/mcuxClTrng/inc/internal/mcuxClTrng_Internal.h
                src/comps/mcuxClTrng/inc/internal/mcuxClTrng_Internal_Constants.h
                src/comps/mcuxClTrng/inc/internal/mcuxClTrng_Internal_Functions.h
                src/comps/mcuxClTrng/inc/internal/mcuxClTrng_Internal_SA_TRNG.h
                src/comps/mcuxClTrng/inc/internal/mcuxClTrng_Internal_Types.h
                src/comps/mcuxClTrng/inc/internal/mcuxClTrng_SfrAccess.h
                BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
    mcux_add_include(
        INCLUDES ./
                 src/comps/mcuxClTrng/inc
                 src/comps/mcuxClTrng/inc/internal
                 BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.sgi_pkc.xof)
    mcux_add_source(
        SOURCES src/comps/mcuxClXof/src/mcuxClXof_api.c
                src/comps/mcuxClXof/inc/mcuxClXof.h
                src/comps/mcuxClXof/inc/mcuxClXof_Constants.h
                src/comps/mcuxClXof/inc/mcuxClXof_Functions.h
                src/comps/mcuxClXof/inc/mcuxClXof_Types.h
                src/comps/mcuxClXof/inc/internal/mcuxClXof_Internal.h
                BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
    mcux_add_include(
        INCLUDES ./
                 src/comps/mcuxClXof/inc
                 src/comps/mcuxClXof/inc/internal
                 BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.sgi_pkc.xof_modes)
    mcux_add_source(
        SOURCES src/comps/mcuxClXofModes/src/mcuxClXofModes_Internal_shake.c
                src/comps/mcuxClXofModes/src/size/size.c
                src/comps/mcuxClXofModes/inc/mcuxClXofModes.h
                src/comps/mcuxClXofModes/inc/mcuxClXofModes_Algorithms.h
                src/comps/mcuxClXofModes/inc/internal/mcuxClXofModes_Internal_Algorithms.h
                src/comps/mcuxClXofModes/inc/internal/mcuxClXofModes_Internal_Memory.h
                BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
    mcux_add_include(
        INCLUDES ./
                 src/comps/mcuxClXofModes/inc
                 src/comps/mcuxClXofModes/inc/internal
                 BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.sgi_pkc.pre_processor)
    mcux_add_source(
        SOURCES src/comps/mcuxCsslCPreProcessor/inc/mcuxCsslAnalysis.h
                src/comps/mcuxCsslCPreProcessor/inc/mcuxCsslAssembly.h
                src/comps/mcuxCsslCPreProcessor/inc/mcuxCsslCPreProcessor.h
                BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
    mcux_add_include(
        INCLUDES ./
                 src/comps/mcuxCsslCPreProcessor/inc
                 BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.sgi_pkc.data_integrity)
    mcux_add_source(
        SOURCES src/comps/mcuxCsslDataIntegrity/inc/mcuxCsslDataIntegrity.h
                src/comps/mcuxCsslDataIntegrity/inc/mcuxCsslDataIntegrity_AssemblyMacros.h
                src/comps/mcuxCsslDataIntegrity/inc/mcuxCsslDataIntegrity_Cfg.h
                src/comps/mcuxCsslDataIntegrity/inc/mcuxCsslDataIntegrity_Impl.h
                src/comps/mcuxCsslDataIntegrity/inc/mcuxCsslDataIntegrity_None.h
                src/comps/mcuxCsslDataIntegrity/inc/mcuxCsslDataIntegrity_SecureCounter.h
                BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
    mcux_add_include(
        INCLUDES ./
                 src/comps/mcuxCsslDataIntegrity/inc/
                 BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.sgi_pkc.flow_protection)
    mcux_add_source(
        SOURCES src/comps/mcuxCsslFlowProtection/inc/mcuxCsslFlowProtection.h
                src/comps/mcuxCsslFlowProtection/inc/mcuxCsslFlowProtection_Cfg.h
                src/comps/mcuxCsslFlowProtection/inc/mcuxCsslFlowProtection_FunctionIdentifiers.h
                src/comps/mcuxCsslFlowProtection/inc/mcuxCsslFlowProtection_Impl.h
                src/comps/mcuxCsslFlowProtection/inc/mcuxCsslFlowProtection_None.h
                src/comps/mcuxCsslFlowProtection/inc/mcuxCsslFlowProtection_SecureCounter_Common.h
                src/comps/mcuxCsslFlowProtection/inc/mcuxCsslFlowProtection_SecureCounter_Local.h
                src/comps/mcuxCsslFlowProtection/inc/mcuxCsslFlowProtection_SecureCounter_Local_AssemblyMacros.h
                BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
    mcux_add_include(
        INCLUDES ./
                 src/comps/mcuxCsslFlowProtection/inc
                 BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.sgi_pkc.param_integrity)
    mcux_add_source(
        SOURCES src/comps/mcuxCsslParamIntegrity/src/mcuxCsslParamIntegrity32.c
                src/comps/mcuxCsslParamIntegrity/inc/mcuxCsslParamIntegrity.h
                BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
    mcux_add_include(
        INCLUDES ./
                 src/comps/mcuxCsslParamIntegrity/inc
                 BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.sgi_pkc.prng)
    mcux_add_source(
        SOURCES src/comps/mcuxCsslPrng/src/size/size.c
                src/comps/mcuxCsslPrng/inc/internal/mcuxCsslPrng_AssemblyMacros.h
                src/comps/mcuxCsslPrng/inc/internal/mcuxCsslPrng_Macros.h
                #src/comps/mcuxCsslPrng/inc/platform/mcxa/mcuxCsslPrng_AssemblyHeader.h
                BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
    mcux_add_include(
        INCLUDES ./
                 src/comps/mcuxCsslPrng/inc
                 BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.sgi_pkc.secure_counter)
    mcux_add_source(
        SOURCES src/comps/mcuxCsslSecureCounter/inc/mcuxCsslSecureCounter.h
                src/comps/mcuxCsslSecureCounter/inc/mcuxCsslSecureCounter_AssemblyMacros.h
                src/comps/mcuxCsslSecureCounter/inc/mcuxCsslSecureCounter_Cfg.h
                src/comps/mcuxCsslSecureCounter/inc/mcuxCsslSecureCounter_Impl.h
                src/comps/mcuxCsslSecureCounter/inc/mcuxCsslSecureCounter_None.h
                src/comps/mcuxCsslSecureCounter/inc/mcuxCsslSecureCounter_SW_Local.h
                BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
    mcux_add_include(
        INCLUDES ./
                 src/comps/mcuxCsslSecureCounter/inc
                 BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.sgi_pkc)
    mcux_add_source(
        SOURCES src/inc/mcuxCl_clns.h
                BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
    mcux_add_include(
        INCLUDES ./
                 src/inc
                 BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.sgi_pkc.toolchain)
    mcux_add_source(
        SOURCES /src/compiler/mcuxClToolchain.h
                BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
    mcux_add_include(
        INCLUDES ./
                 src/compiler
                 BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.sgi_pkc.examples_aead)
    mcux_add_source(
        SOURCES examples/mcuxClAeadModes/mcuxClAeadModes_Ccm_Aes128_Multipart_example.c
                examples/mcuxClAeadModes/mcuxClAeadModes_Ccm_Aes128_Oneshot_Nist1_example.c
                examples/mcuxClAeadModes/mcuxClAeadModes_Ccm_Aes128_Oneshot_Nist2_example.c
                examples/mcuxClAeadModes/mcuxClAeadModes_Ccm_Aes128_Oneshot_PreloadedKey_example.c
                examples/mcuxClAeadModes/mcuxClAeadModes_Gcm_Aes128_Multipart_example.c
                examples/mcuxClAeadModes/mcuxClAeadModes_Gcm_Aes128_Oneshot_example.c
                examples/mcuxClAeadModes/mcuxClAeadModes_Gcm_Aes128_Oneshot_LongNonce_example.c
                BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
    mcux_add_include(
        INCLUDES ./
                 BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.sgi_pkc.examples_cipher_modes)
    mcux_add_source(
        SOURCES examples/mcuxClCipherModes/mcuxClCipherModes_Cbc_Aes128_Multipart_example.c
                examples/mcuxClCipherModes/mcuxClCipherModes_Cbc_Aes128_Multipart_KeyRfc3394Encoding_example.c
                examples/mcuxClCipherModes/mcuxClCipherModes_Cbc_Aes128_Multipart_PaddingISO_example.c
                # examples/mcuxClCipherModes/mcuxClCipherModes_Cbc_Aes128_Multipart_PaddingZero_Dma_NonBlocking_example.c
                examples/mcuxClCipherModes/mcuxClCipherModes_Cbc_Aes128_Multipart_PaddingZero_example.c
                # examples/mcuxClCipherModes/mcuxClCipherModes_Cbc_Aes128_Oneshot_Dma_NonBlocking_example.c
                examples/mcuxClCipherModes/mcuxClCipherModes_Cbc_Aes128_Oneshot_example.c
                examples/mcuxClCipherModes/mcuxClCipherModes_Cbc_Aes128_Oneshot_PaddingISO_example.c
                examples/mcuxClCipherModes/mcuxClCipherModes_Cbc_Aes128_Oneshot_PaddingZero_example.c
                # examples/mcuxClCipherModes/mcuxClCipherModes_Ctr_Aes128_Multipart_Dma_NonBlocking_example.c
                examples/mcuxClCipherModes/mcuxClCipherModes_Ctr_Aes128_Multipart_example.c
                # examples/mcuxClCipherModes/mcuxClCipherModes_Ctr_Aes128_Oneshot_Dma_NonBlocking_example.c
                examples/mcuxClCipherModes/mcuxClCipherModes_Ctr_Aes128_Oneshot_example.c
                examples/mcuxClCipherModes/mcuxClCipherModes_Ecb_Aes128_Multipart_example.c
                examples/mcuxClCipherModes/mcuxClCipherModes_Ecb_Aes128_Multipart_PaddingISO_example.c
                # examples/mcuxClCipherModes/mcuxClCipherModes_Ecb_Aes128_Multipart_PaddingZero_Dma_NonBlocking_example.c
                # examples/mcuxClCipherModes/mcuxClCipherModes_Ecb_Aes128_Multipart_PaddingZero_Dma_NonBlocking_MultipleProcess_example.c
                examples/mcuxClCipherModes/mcuxClCipherModes_Ecb_Aes128_Multipart_PaddingZero_example.c
                # examples/mcuxClCipherModes/mcuxClCipherModes_Ecb_Aes128_Oneshot_Dma_NonBlocking_example.c
                examples/mcuxClCipherModes/mcuxClCipherModes_Ecb_Aes128_Oneshot_example.c
                examples/mcuxClCipherModes/mcuxClCipherModes_Ecb_Aes128_Oneshot_PaddingISO_example.c
                examples/mcuxClCipherModes/mcuxClCipherModes_Ecb_Aes128_Oneshot_PaddingPKCS7_example.c
                examples/mcuxClCipherModes/mcuxClCipherModes_Ecb_Aes128_Oneshot_PaddingZero_example.c
                examples/mcuxClCipherModes/mcuxClCipherModes_Ecb_Aes128_Oneshot_PreloadedKey_example.c
                BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
    mcux_add_include(
        INCLUDES ./
                 BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.sgi_pkc.examples_crc)
    mcux_add_source(
        SOURCES examples/mcuxClCrc/mcuxClCrc_Crc16_example.c
                examples/mcuxClCrc/mcuxClCrc_Crc32_example.c
                BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
    mcux_add_include(
        INCLUDES ./
                 BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.sgi_pkc.examples_ecc)
    mcux_add_source(
        SOURCES # examples/mcuxClEcc/mcuxClEcc_ArithmeticOperation_BurmesterDesmedt_NIST_P256_example.c
                # examples/mcuxClEcc/mcuxClEcc_ArithmeticOperation_PointAdd_NIST_P224_example.c
                # examples/mcuxClEcc/mcuxClEcc_ArithmeticOperation_PointSub_NIST_P224_example.c
                # examples/mcuxClEcc/mcuxClEcc_ArithmeticOperation_ScalarMult_secp521r1_example.c
                # examples/mcuxClEcc/mcuxClEcc_ArithmeticOperation_SecureScalarMult_secp521r1_example.c
                examples/mcuxClEcc/mcuxClEcc_ECDH_KeyAgreement_NIST_P256_example.c
                examples/mcuxClEcc/mcuxClEcc_ECDSA_FixedKeys_NIST_P256_example.c
                examples/mcuxClEcc/mcuxClEcc_ECDSA_GeneratedKeys_NIST_P256_example.c
                examples/mcuxClEcc/mcuxClEcc_ECDSA_VerifyOnly_NIST_P256_example.c
                examples/mcuxClEcc/mcuxClEcc_EdDSA_Ed25519_example.c
                examples/mcuxClEcc/mcuxClEcc_EdDSA_Ed25519ctx_example.c
                examples/mcuxClEcc/mcuxClEcc_EdDSA_Ed25519ph_example.c
                examples/mcuxClEcc/mcuxClEcc_EdDSA_GenerateSignature_Ed25519_example.c
                examples/mcuxClEcc/mcuxClEcc_MontDH_Curve25519_example.c
                examples/mcuxClEcc/mcuxClEcc_Weier_KeyValidation_PrivateKey_example.c
                examples/mcuxClEcc/mcuxClEcc_Weier_KeyValidation_PublicKey_example.c
                # examples/mcuxClEcc/mcuxClEcc_WeierECC_CustomEccWeierType_BN256_example.c
                examples/mcuxClEcc/mcuxClEcc_WeierECC_DecodePoint_brainpoolP384r1_example.c
                examples/mcuxClEcc/mcuxClEcc_WeierECC_DecodePoint_secp224r1_example.c
                BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
    mcux_add_include(
        INCLUDES ./
                 BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.sgi_pkc.examples_ffdh)
    mcux_add_source(
        SOURCES examples/mcuxClFfdh/mcuxClFfdh_KeyAgreement_ffdhe2048_example.c
                examples/mcuxClFfdh/mcuxClFfdh_KeyAgreement_ffdhe3072_example.c
                examples/mcuxClFfdh/mcuxClFfdh_KeyAgreement_ffdhe4096_example.c
                examples/mcuxClFfdh/mcuxClFfdh_KeyAgreement_ffdhe6144_example.c
                examples/mcuxClFfdh/mcuxClFfdh_KeyAgreement_ffdhe8192_example.c
                BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
    mcux_add_include(
        INCLUDES ./
                 BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.sgi_pkc.examples_glikey)
    mcux_add_source(
        SOURCES examples/mcuxClGlikey/mcuxClGlikey_example.c
                BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
    mcux_add_include(
        INCLUDES ./
                 BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.sgi_pkc.examples_hash_modes)
    mcux_add_source(
        SOURCES # examples/mcuxClHashModes/mcuxClHashModes_sha3_224_oneshot_example.c
                # examples/mcuxClHashModes/mcuxClHashModes_sha3_224_streaming_example.c
                # examples/mcuxClHashModes/mcuxClHashModes_sha3_256_oneshot_example.c
                # examples/mcuxClHashModes/mcuxClHashModes_sha3_256_streaming_example.c
                # examples/mcuxClHashModes/mcuxClHashModes_sha3_384_oneshot_example.c
                # examples/mcuxClHashModes/mcuxClHashModes_sha3_384_streaming_example.c
                # examples/mcuxClHashModes/mcuxClHashModes_sha3_512_oneshot_example.c
                # examples/mcuxClHashModes/mcuxClHashModes_sha3_512_streaming_example.c
                examples/mcuxClHashModes/mcuxClHashModes_sha224_oneshot_example.c
                examples/mcuxClHashModes/mcuxClHashModes_sha256_longMsgOneshot_example.c
                # examples/mcuxClHashModes/mcuxClHashModes_sha256_oneshot_dma_nonBlocking_example.c
                examples/mcuxClHashModes/mcuxClHashModes_sha256_oneshot_example.c
                # examples/mcuxClHashModes/mcuxClHashModes_sha256_streaming_dma_nonBlocking_example.c
                examples/mcuxClHashModes/mcuxClHashModes_sha256_streaming_example.c
                examples/mcuxClHashModes/mcuxClHashModes_sha384_oneshot_example.c
                examples/mcuxClHashModes/mcuxClHashModes_sha512_oneshot_example.c
                BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
    mcux_add_include(
        INCLUDES ./
                 BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.sgi_pkc.examples_hmac)
    mcux_add_source(
        SOURCES examples/mcuxClHmac/mcuxClHmac_Sw_Multipart_example.c
                examples/mcuxClHmac/mcuxClHmac_Sw_Oneshot_example.c
                BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
    mcux_add_include(
        INCLUDES ./
                 BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.sgi_pkc.examples_kdf_modes)
    mcux_add_source(
        SOURCES examples/mcuxClKdfModes/mcuxClKdfModes_CM_CMAC_example.c
        SOURCES examples/mcuxClKdfModes/mcuxClKdfModes_HKDF_example.c
        SOURCES examples/mcuxClKdfModes/mcuxClKdfModes_SP800_56C_example.c
        SOURCES examples/mcuxClKdfModes/mcuxClKdfModes_SP800_56C_twostep_cmac_example.c
        SOURCES examples/mcuxClKdfModes/mcuxClKdfModes_SP800_56C_twostep_hmac_example.c
        SOURCES examples/mcuxClKdfModes/mcuxClKdfModes_SP800_108_Counter_Mode_CMAC_example.c
        SOURCES examples/mcuxClKdfModes/mcuxClKdfModes_SP800_108_Double_Pipeline_Mode_CMAC_example.c
        SOURCES examples/mcuxClKdfModes/mcuxClKdfModes_SP800_108_Double_Pipeline_Mode_HMAC_example.c
        SOURCES examples/mcuxClKdfModes/mcuxClKdfModes_SP800_108_Feedback_Mode_CMAC_example.c
                BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
    mcux_add_include(
        INCLUDES ./
                 BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
endif()


if (CONFIG_MCUX_COMPONENT_component.sgi_pkc.examples_key)
    mcux_add_source(
        SOURCES examples/mcuxClKey/mcuxClKey_Load_Flush_Sgi_example.c
        SOURCES examples/mcuxClKey/mcuxClKey_Rewrap_Rfc3394_Sgi_example.c
        SOURCES examples/mcuxClKey/mcuxClKey_Unwrap_Rfc3394_Sgi_example.c
        SOURCES examples/mcuxClKey/mcuxClKey_Wrap_Rfc3394_Sgi_kwkAlreadyLoaded_example.c
        SOURCES examples/mcuxClKey/mcuxClKey_WrapAndLoad_Rfc3394_Sgi_example.c
                BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
    mcux_add_include(
        INCLUDES ./
                 BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.sgi_pkc.examples_mac_modes)
    mcux_add_source(
        # SOURCES examples/mcuxClMacModes/mcuxClMacModes_Cmac_Aes128_Compute_Dma_NonBlocking_example.c
        SOURCES examples/mcuxClMacModes/mcuxClMacModes_Cmac_Aes128_Compute_example.c
        SOURCES examples/mcuxClMacModes/mcuxClMacModes_Cmac_Aes128_Compute_PreloadedKey_example.c
        # SOURCES examples/mcuxClMacModes/mcuxClMacModes_Cmac_Aes128_Multipart_Dma_NonBlocking_example.c
        SOURCES examples/mcuxClMacModes/mcuxClMacModes_Cmac_Aes128_Multipart_example.c
        SOURCES examples/mcuxClMacModes/mcuxClMacModes_Cmac_Aes256_Compute_example.c
                BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
    mcux_add_include(
        INCLUDES ./
                 BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.sgi_pkc.examples_random)
    mcux_add_source(
        SOURCES examples/mcuxClRandom/mcuxClRandom_PRNG_Patch_example.c
        SOURCES examples/mcuxClRandom/mcuxClRandom_PRNG_Seed_example.c
                BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
    mcux_add_include(
        INCLUDES ./
                 BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.sgi_pkc.examples_random_modes)
    mcux_add_source(
        SOURCES # examples/mcuxClRandomModes/mcuxClRandomModes_CtrDrbg_AES128_DRG3_example.c
                examples/mcuxClRandomModes/mcuxClRandomModes_CtrDrbg_AES256_DRG3_example.c
                examples/mcuxClRandomModes/mcuxClRandomModes_CtrDrbg_AES256_DRG4_example.c
                examples/mcuxClRandomModes/mcuxClRandomModes_Different_Sessions_example.c
                examples/mcuxClRandomModes/mcuxClRandomModes_PatchMode_CtrDrbg_AES256_DRG3_example.c
                examples/mcuxClRandomModes/mcuxClRandomModes_TestMode_CtrDrbg_AES256_DRG4_example.c
                BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
    mcux_add_include(
        INCLUDES ./
                 examples/mcuxCsslFlowProtection/inc/
                 examples/mcuxCsslMemory/inc/
                 src/comps/mcuxClExample/inc/
                 src/comps/mcuxClBuffer/inc/
                 BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.sgi_pkc.examples_rsa)
    mcux_add_source(
        SOURCES # examples/mcuxClRsa/mcuxClRsa_Cipher_RSAES_OAEP_example.c
                # examples/mcuxClRsa/mcuxClRsa_Cipher_RSAES_PKCS1_v1_5_example.c
                examples/mcuxClRsa/mcuxClRsa_KeyGeneration_example.c
                # examples/mcuxClRsa/mcuxClRsa_Signature_PKCS1_v1_5_SHA3_example.c
                examples/mcuxClRsa/mcuxClRsa_Signature_RSASSA_PSS_example.c
                BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
    mcux_add_include(
        INCLUDES ./
                 examples/mcuxCsslFlowProtection/inc/
                 examples/mcuxCsslMemory/inc/
                 src/comps/mcuxClExample/inc/
                 src/comps/mcuxClBuffer/inc/
                 BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.sgi_pkc.examples_xof_modes)
    mcux_add_source(
        SOURCES examples/mcuxClXofModes/mcuxClXofModes_shake_256_more_streaming_example.c
                examples/mcuxClXofModes/mcuxClXofModes_shake_256_oneshot_example.c
                examples/mcuxClXofModes/mcuxClXofModes_shake_256_streaming_example.c
                BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
    mcux_add_include(
        INCLUDES ./
                 examples/mcuxCsslMemory/inc/
                 src/comps/mcuxClExample/inc/
                 src/comps/mcuxClBuffer/inc/
                 BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.sgi_pkc.examples_flow_protection)
    mcux_add_source(
        SOURCES examples/mcuxCsslFlowProtection/mcuxCsslFlowProtection_Assert_example.c
		        examples/mcuxCsslFlowProtection/mcuxCsslFlowProtection_Branch_example.c
		        examples/mcuxCsslFlowProtection/mcuxCsslFlowProtection_Function_example.c
		        examples/mcuxCsslFlowProtection/mcuxCsslFlowProtection_Loop_example.c
                examples/mcuxCsslFlowProtection/inc/mcuxCsslExamples.h
                BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
    mcux_add_include(
        INCLUDES ./
                 examples/mcuxCsslFlowProtection/inc/
                 examples/mcuxCsslMemory/inc/
                 src/comps/mcuxClExample/inc/
                 src/comps/mcuxClBuffer/inc/
                 BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.sgi_pkc.examples_memory)
    mcux_add_source(
        SOURCES examples/mcuxCsslMemory/mcuxCsslMemory_Clear_example.c
                examples/mcuxCsslMemory/mcuxCsslMemory_Compare_example.c
                examples/mcuxCsslMemory/mcuxCsslMemory_Copy_example.c
                examples/mcuxCsslMemory/mcuxCsslMemory_SecureCompare_example.c
                # examples/mcuxCsslMemory/mcuxCsslMemory_SecureCopy_example.c
                examples/mcuxCsslMemory/mcuxCsslMemory_SecureSet_example.c
                # examples/mcuxCsslMemory/mcuxCsslMemory_SecureXOR_example.c
                examples/mcuxCsslMemory/mcuxCsslMemory_Set_example.c
                examples/mcuxCsslMemory/inc/mcuxCsslMemory_Examples.h
                BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
    mcux_add_include(
        INCLUDES ./
                 examples/mcuxCsslFlowProtection/inc/
                 examples/mcuxCsslMemory/inc/
                 src/comps/mcuxClExample/inc/
                 src/comps/mcuxClBuffer/inc/
                 BASE_PATH ${SdkRootDirPath}/components/sgi_pkc/
    )
endif()
