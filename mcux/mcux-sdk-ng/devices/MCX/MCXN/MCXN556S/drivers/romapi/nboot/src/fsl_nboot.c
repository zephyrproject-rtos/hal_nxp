/*
 * Copyright 2025 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include "fsl_nboot_hal.h"
#include "fsl_common.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! @brief Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.nboot"
#endif

#define BOOTLOADER_API_TREE_POINTER ((bootloader_tree_t *)0x1303e000u)

/**
 * @brief Image authentication operations.
 *
 * These abstract interface are used for image verification operations.
 */

typedef struct nboot_interface_struct
{
    nboot_status_protected_t (*nboot_context_init)(nboot_context_t *context);
    nboot_status_protected_t (*nboot_context_deinit)(nboot_context_t *context);
    nboot_status_protected_t (*nboot_context_set_uuid)(nboot_context_t *context, const uint8_t uuid[16]);
    nboot_status_protected_t (*nboot_sb4_load_manifest)(nboot_context_t *context,
                                                        const uint32_t *manifest,
                                                        nboot_sb4_load_manifest_parms_t *parms);
    nboot_status_protected_t (*nboot_sb4_load_block)(nboot_context_t *context, uint32_t *block);
    nboot_status_protected_t (*nboot_sb4_check_authenticity_and_completeness_romapi)(
        nboot_context_t *context, const uint32_t *address, nboot_sb4_load_manifest_parms_t *parms);
    nboot_status_protected_t (*nboot_img_authenticate_romapi)(nboot_context_t *context,
                                                              const uint8_t imageStartAddress[],
                                                              nboot_bool_t *isSignatureVerified,
                                                              nboot_img_auth_parms_t *parms);
} nboot_interface_t;

/*!
 * @brief Root of the bootloader API tree.
 *
 * An instance of this struct resides in read-only memory in the bootloader. It
 * provides a user application access to APIs exported by the bootloader.
 *
 * @note The order of existing fields must not be changed.
 */
typedef struct BootloaderTree
{
    void (*runBootloader)(void *arg);     /*!< Function to start the bootloader executing.*/
    const uint32_t version;               /*!< Bootloader version number.*/
    const char *copyright;                /*!< Copyright string.*/
    const uint32_t reserved0;             /*!< reserved*/
    const uint32_t flashDriver;           /*!< Internal Flash driver API.*/
    const uint32_t reserved1[5];          /*!< reserved*/
    const nboot_interface_t *nbootDriver; /*!< nBoot driver API */
    const uint32_t reserved2;             /*!< reserved.*/
    const uint32_t efuseDriver;           /*!< eFuse driver API */
    const uint32_t iapAPIDriver;          /*!< IAP driver API */
} bootloader_tree_t;

/*******************************************************************************
 * API
 ******************************************************************************/

/*!
 * @brief The function is used for initializing of the nboot context data structure.
 *        It should be called prior to any other calls of nboot API.
 *
 * @param nbootCtx Pointer to nboot_context_t structure.
 *
 * @retval #kStatus_NBOOT_Success Operation successfully finished
 * @retval #kStatus_NBOOT_Fail Error occured during operation
 */
nboot_status_protected_t NBOOT_ContextInit(nboot_context_t *context)
{
    assert(BOOTLOADER_API_TREE_POINTER);
    return BOOTLOADER_API_TREE_POINTER->nbootDriver->nboot_context_init(context);
}

/*!
 * @brief The function is used to deinitialize nboot context data structure.
 * Its contents are overwritten with random data so that any sensitive data does not remain in memory.
 *
 * @param context Pointer to nboot_context_t structure.

 * @retval #kStatus_NBOOT_Success Operation successfully finished
 * @retval #kStatus_NBOOT_Fail Error occured during operation
 */
nboot_status_protected_t NBOOT_ContextDeinit(nboot_context_t *context)
{
    assert(BOOTLOADER_API_TREE_POINTER);
    return BOOTLOADER_API_TREE_POINTER->nbootDriver->nboot_context_deinit(context);
}

/*!
 * @brief Set UUID in the nboot context
 *
 * This function sets the UUID (Universally Unique Identifier) in the nboot context structure.
 * The NBOOT context has to be initialized by the function nboot_context_init before calling
 * this function.
 *
 * @param context Pointer to nboot_context_t structure.
 * @param uuid Pointer to 16-byte UUID array to be set in the context.
 *
 * @retval #kStatus_NBOOT_Success Operation successfully finished
 * @retval #kStatus_NBOOT_Fail Error occured during operation
 */
nboot_status_protected_t NBOOT_ContextSetUuid(nboot_context_t *context, const uint8_t uuid[16])
{
    assert(BOOTLOADER_API_TREE_POINTER);
    return BOOTLOADER_API_TREE_POINTER->nbootDriver->nboot_context_set_uuid(context, uuid);
}

/*!
 * @brief Load NBOOT SB4 manifest
 *
 * This function loads and processes an NBOOT SB4 manifest. The manifest contains metadata
 * and configuration information for the SB4 file processing. The NBOOT context has to be
 * initialized by the function nboot_context_init before calling this function.
 *
 * @param context Pointer to nboot_context_t structure.
 * @param manifest Pointer to the SB4 manifest data.
 * @param parms Pointer to a data structure in trusted memory, holding input parameters for the algorithm.
 *              The data structure shall be correctly filled before the function call.
 *
 * @retval #kStatus_NBOOT_Success Operation successfully finished
 * @retval #kStatus_NBOOT_Fail Error occured during operation
 */
nboot_status_protected_t NBOOT_Sb4LoadManifest(nboot_context_t *context,
                                               const uint32_t *manifest,
                                               nboot_sb4_load_manifest_parms_t *parms)
{
    assert(BOOTLOADER_API_TREE_POINTER);
    return BOOTLOADER_API_TREE_POINTER->nbootDriver->nboot_sb4_load_manifest(context, manifest, parms);
}

/*!
 * @brief Load NBOOT SB4 block
 *
 * This function loads and processes an NBOOT SB4 block. The NBOOT context has to be
 * initialized by the function nboot_context_init before calling this function.
 *
 * @param context Pointer to nboot_context_t structure.
 * @param block Pointer to the SB4 block data to be loaded.
 *
 * @retval #kStatus_NBOOT_Success Operation successfully finished
 * @retval #kStatus_NBOOT_Fail Error occured during operation
 */
nboot_status_protected_t NBOOT_Sb4LoadBlock(nboot_context_t *context, uint32_t *block)
{
    assert(BOOTLOADER_API_TREE_POINTER);
    return BOOTLOADER_API_TREE_POINTER->nbootDriver->nboot_sb4_load_block(context, block);
}

/*!
 * @brief Check authenticity and completeness of NBOOT SB4 file
 *
 * This function verifies the authenticity and completeness of an NBOOT SB4 file.
 * The NBOOT context has to be initialized by the function nboot_context_init before calling this function.
 *
 * @param context Pointer to nboot_context_t structure.
 * @param address Pointer to the SB4 file data in memory.
 * @param parms Pointer to a data structure in trusted memory, holding input parameters for the algorithm.
 *              The data structure shall be correctly filled before the function call.
 *
 * @retval #kStatus_NBOOT_Success Operation successfully finished
 * @retval #kStatus_NBOOT_Fail Error occured during operation
 */
nboot_status_protected_t NBOOT_SB4CheckAuthenticityAndCompleteness(nboot_context_t *context,
                                                                   const uint32_t *address,
                                                                   nboot_sb4_load_manifest_parms_t *parms)
{
    assert(BOOTLOADER_API_TREE_POINTER);
    return BOOTLOADER_API_TREE_POINTER->nbootDriver->nboot_sb4_check_authenticity_and_completeness_romapi(
        context, address, parms);
}

/*!
 * @brief Authenticate NBOOT image
 *
 * This function authenticates an NBOOT image by verifying its signature and integrity.
 * The NBOOT context has to be initialized by the function nboot_context_init before calling this function.
 *
 * @param context Pointer to nboot_context_t structure.
 * @param imageStartAddress Pointer to the start address of the image data to be authenticated.
 * @param isSignatureVerified Pointer to a boolean flag that will be set to indicate if the signature was verified.
 * @param parms Pointer to a data structure in trusted memory, holding input parameters for the algorithm.
 *              The data structure shall be correctly filled before the function call.
 *
 * @retval #kStatus_NBOOT_Success Operation successfully finished
 * @retval #kStatus_NBOOT_Fail Error occured during operation
 */
nboot_status_protected_t NBOOT_ImgAuthenticate(nboot_context_t *context,
                                               const uint8_t imageStartAddress[],
                                               nboot_bool_t *isSignatureVerified,
                                               nboot_img_auth_parms_t *parms)
{
    assert(BOOTLOADER_API_TREE_POINTER);
    return BOOTLOADER_API_TREE_POINTER->nbootDriver->nboot_img_authenticate_romapi(context, imageStartAddress,
                                                                                   isSignatureVerified, parms);
}
