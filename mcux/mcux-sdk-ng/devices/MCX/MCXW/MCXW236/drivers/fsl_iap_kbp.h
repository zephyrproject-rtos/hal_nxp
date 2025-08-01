/*
 * Copyright (c) 2020, Freescale Semiconductor, Inc.
 * Copyright 2021-2022 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef _FSL_IAP_KBP_H_
#define _FSL_IAP_KBP_H_

#include "fsl_common.h"

/*!
 * @addtogroup kb_driver
 * @{
 */
/*******************************************************************************
 * Definitions
 *******************************************************************************/

/*! KBoot API version. */
#define kKBootApiVersion    (0x1)
#define kStatusGroup_RomApi (0x6C)

/*!
 * Kb status codes
 */
enum kb_status_s
{
    kStatus_RomApiExecuteCompleted                          = kStatus_Success,
    kStatus_RomApiNeedMoreData                              = MAKE_STATUS(kStatusGroup_RomApi, 1),
    kStatus_RomApiBufferSizeNotEnough                       = MAKE_STATUS(kStatusGroup_RomApi, 2),
    kStatus_RomApiInvalidBuffer                             = MAKE_STATUS(kStatusGroup_RomApi, 3),
    kStatus_AUTHENTICATE_Success                            = 0x5ac3c35au,
    kStatus_AUTHENTICATE_Fail                               = 0xc35ac35au,
    kStatus_AUTHENTICATE_KeyStoreMarkerInvalid              = 0xc3c35a5au,
    kStatus_AUTHENTICATE_HashcryptFinishedWithStatusSuccess = 0xc15a5ac3,
    kStatus_AUTHENTICATE_HashcryptFinishedWithStatusFail    = 0xc15a5acb,
};

/*!
 * Secure bool status codes
 */
typedef enum secure_bool_s
{
    kSECURE_TRUE                       = 0xc33cc33cU,
    kSECURE_FALSE                      = 0x5aa55aa5U,
    kSECURE_CALLPROTECT_SECURITY_FLAGS = 0xc33c5aa5U,
    kSECURE_CALLPROTECT_IS_APP_READY   = 0x5aa5c33cU,
    kSECURE_TRACKER_VERIFIED           = 0x55aacc33U,
} secure_bool_t;

/*!
 *  Details of the operation to be performed by the ROM.
 */
typedef enum kb_operation_s
{
    kRomAuthenticateImage = 1,
    kRomLoadImage         = 2
} kb_operation_t;

/*!
 * Security constraint flags, Security profile flags.
 */
enum kb_security_profile_s
{
    kKbootMinRSA4096 = (1 << 16),
};

/*!
 * Memory region definition.
 */
typedef struct kb_region_s
{
    uint32_t address;
    uint32_t length;
} kb_region_t;

/*!
 * User-provided options passed into kb_init().
 *
 * The buffer field is a pointer to memory provided by the caller for use by
 * Kboot during execution of the operation. Minimum size is the size of each
 * certificate in the chain plus 432 bytes additional per certificate.
 *
 * The profile field is a mask that specifies which features are required in
 * the SB file or image being processed. This includes the minimum AES and RSA
 * key sizes. See the _kb_security_profile enum for profile mask constants.
 * The image being loaded or authenticated must match the profile or an error will
 * be returned.
 *
 * minBuildNumber is an optional field that can be used to prevent version
 * rollback. The API will check the build number of the image, and if it is less
 * than minBuildNumber will fail with an error.
 *
 * The regions field points to an array of memory regions that the SB file being
 * loaded is allowed to access. If regions is NULL, then all memory is
 * accessible by the SB file. This feature is required to prevent a malicious
 * image from erasing good code or RAM contents while it is being loaded, only
 * for us to find that the image is inauthentic when we hit the end of the
 * section.
 *
 * The userSBKEK field lets a user provide their own AES-256 key for unwrapping
 * keys in an SB file during the kKbootLoadSB operation. userSBKEK should point
 * to a 32-byte AES-256 key. If userSBKEK is NULL then the IFR SBKEK will be used.
 * After kb_init() returns, the caller should zero out the data pointed to by
 * userSBKEK, as the API will have installed the key in the CAU3.
 */

/*!
 * Structure describing the loadSB parameter from kb_options_t
 */
typedef struct kb_load_sb_s
{
    uint32_t profile;
    uint32_t minBuildNumber;
    uint32_t reserved;
    uint32_t *userSBKEK;
    uint32_t regionCount;
    const kb_region_t *regions;
} kb_load_sb_t;

/*!
 * Structure describing the context parameter from kb_session_ref_t
 */
typedef struct kb_options_s
{
    uint32_t version; /*!< Should be set to kKbootApiVersion.*/
    uint8_t *buffer;  /*!< Caller-provided buffer used by Kboot.*/
    uint32_t bufferLength;
    kb_operation_t op;
    kb_load_sb_t loadSB; /*! Settings for kKbootLoadSB operation.*/
} kb_options_t;

/*!
 * Interface to memory operations for one region of memory.
 */
typedef struct memory_region_interface_s
{
    status_t (*init)(void);
    status_t (*read)(uint32_t address, uint32_t length, uint8_t *buffer);
    status_t (*write)(uint32_t address, uint32_t length, const uint8_t *buffer);
    status_t (*fill)(uint32_t address, uint32_t length, uint32_t pattern);
    status_t (*flush)(void);
    status_t (*erase)(uint32_t address, uint32_t length);
    status_t (*config)(uint32_t *buffer);
    status_t (*erase_all)(void);
} memory_region_interface_t;

/*!
 * Structure of a memory map entry.
 */
typedef struct memory_map_entry_s
{
    uint32_t startAddress;
    uint32_t endAddress;
    uint32_t memoryProperty;
    uint32_t memoryId;
    const memory_region_interface_t *memoryInterface;
} memory_map_entry_t;

/*!
 * Structure of a kb session
 */
typedef struct kb_session_ref_s
{
    kb_options_t context;
    bool cau3Initialized;
    memory_map_entry_t *memoryMap;
} kb_session_ref_t;

/*******************************************************************************
 * API
 ******************************************************************************/

/*!
 * Initialize Kboot for a given operation.
 *
 * Inits the ROM API based on the options provided by the application in the second
 * argument. Every call to kb_init() should be paired with a call to kb_deinit().
 */
status_t kb_init(kb_session_ref_t **session, const kb_options_t *options);

/*!
 * Cleans up the Kboot context.
 *
 * After this call, the context parameter can be reused for another operation
 * by calling kb_init() again.
 */
status_t kb_deinit(kb_session_ref_t *session);

/*!
 * Perform the operation configured during kb_init.
 *
 * This application must call this API repeatedly, passing in sequential chunks of
 * data from the boot image (SB file) that is to be processed. The ROM will perform
 * the selected operation on this data and return. The application may call this
 * function with as much or as little data as it wishes, which can be used to select
 * the granularity of time given to the application in between executing the operation.
 *
 * @param session Current session pointer.
 * @param data Buffer of boot image data provided to the ROM by the application.
 * @param dataLength Length in bytes of the data in the buffer provided to the ROM.
 *
 * @retval kStatus_RomApiExecuteSuccess ROM successfully process the part of sb file/boot image.
 * @retval kStatus_RomApiExecuteCompleted ROM successfully process the whole sb file/boot image.
 * @retval kStatus_Fail An error occurred while executing the operation.
 * @retval kStatus_RomApiNeedMoreData No error occurred, but the ROM needs more data to
 *     continue processing the boot image.
 * @retval kStatus_RomApiBufferSizeNotEnough user buffer is not enough for
 *     use by Kboot during execution of the operation.
 * @retval kStatus_RomApiBufferNotOkForArena user buffer does't meet the requirement
 *     of arena memory.
 */
status_t kb_execute(kb_session_ref_t *session, const uint8_t *data, uint32_t dataLength);

/*!
 * This API function can be used to verify the authenticity of an image.
 * function during the secure boot flow to authenticate an image in the internal flash, and it
 * also uses it to verify authenticity of the SB 2.1 files. If a user application calls
 * skboot_authenticate() directly or indirectly from SB file processing functions
 * kb_init,kb_execute and kb_deinit, the user HASHCRYPT interrupt vector shall call the
 * kb_HASHCRYPT_IRQHandler() function for handling of the Hashcrypt IP interrupt. This is due to the
 * fact that the hashing is implemented as non-blocking for shorter computation time while
 * the Hashcrypt AHB master fetches data for hashing, the CPU and Casper co-processor
 * work on RSA Verification.
 *
 * The function requires the imageStartAddr input pointer to be 32-bit word aligned. The
 * status is returned by two ways - via a function return as well as by a write to the
 * isSignVerified pointer. This is provided for redundant protection, the caller shall verify
 * both return values and consider authentic image only when the function returns
 * kStatus_SKBOOT_Success AND *isSignVerified == kSECURE_TRACKER_VERIFIED.
 */
status_t kb_authenticate(const uint8_t *imageStartAddr, secure_bool_t *isSignVerified);

/*!
 * Hashcrypt interrupt handler will be triggered by kb_authenticate. It has to be implemented by calling the
 * kb_HASHCRYPT_IRQHandler() (the ROM hashcrypt irq implementation). Note that the default Hashcrypt Irq handler needs
 * to be overwritten (weak symbol) to make sure that the rom implementation of the function is used. E.g.: void
 * HASHCRYPT_IRQHandler(void)
 * {
 *   kb_HASHCRYPT_IRQHandler();
 * }
 */
void HASHCRYPT_IRQHandler(void);

/*!
 *@}
 */

#endif /* _FSL_IAP_KBP_H_ */
