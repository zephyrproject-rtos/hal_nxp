/*
 * Copyright 2025 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef FSL_C40_FLASH_H_
#define FSL_C40_FLASH_H_

#include "fsl_common.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*! @{ */
/*! @brief eDMA driver version */
#define FSL_FLASH_C40_DRIVER_VERSION (MAKE_VERSION(1, 1, 0))
/*! @} */


/*! @brief Flash driver status group. */
#if defined(kStatusGroup_FlashDriver)
#define kStatusGroupGeneric     kStatusGroup_Generic
#define kStatusGroupFlashDriver kStatusGroup_FlashDriver
#elif defined(kStatusGroup_FLASH)
#define kStatusGroupGeneric     kStatusGroup_Generic
#define kStatusGroupFlashDriver kStatusGroup_FLASH
#else
#define kStatusGroupGeneric     0
#define kStatusGroupFlashDriver 1
#endif

/*! @brief Constructs a status code value from a group and a code number. */
#if !defined(MAKE_STATUS)
#define MAKE_STATUS(group, code) ((((group)*100) + (code)))
#endif

/*!
 * @brief FLASH driver status codes.
 */
enum
{
    kStatus_FLASH_Success         = MAKE_STATUS(kStatusGroupGeneric, 0),     /*!< API is executed successfully*/
    kStatus_FLASH_InvalidArgument = MAKE_STATUS(kStatusGroupGeneric, 4),     /*!< Invalid argument*/
    kStatus_FLASH_SizeError       = MAKE_STATUS(kStatusGroupFlashDriver, 0), /*!< Error size*/
    kStatus_FLASH_AlignmentError =
        MAKE_STATUS(kStatusGroupFlashDriver, 1), /*!< Parameter is not aligned with the specified baseline*/
    kStatus_FLASH_AddressError = MAKE_STATUS(kStatusGroupFlashDriver, 2), /*!< Address is out of range */
    kStatus_FLASH_AccessError =
        MAKE_STATUS(kStatusGroupFlashDriver, 3), /*!< Invalid instruction codes and out-of bound addresses */
    kStatus_FLASH_ProtectionViolation = MAKE_STATUS(
        kStatusGroupFlashDriver, 4), /*!< The program/erase operation is requested to execute on protected areas */
    kStatus_FLASH_CommandFailure =
        MAKE_STATUS(kStatusGroupFlashDriver, 5), /*!< Run-time error during command execution */
    kStatus_FLASH_UnknownProperty = MAKE_STATUS(kStatusGroupFlashDriver, 6), /*!< Unknown property*/
    kStatus_FLASH_EraseKeyError   = MAKE_STATUS(kStatusGroupFlashDriver, 7), /*!< API erase key is invalid*/
    kStatus_FLASH_OperationInProgress = MAKE_STATUS(kStatusGroupFlashDriver, 8), /*!< Flash operation already in progress*/
    kStatus_FLASH_SectorUnlocked = MAKE_STATUS(kStatusGroupFlashDriver, 9),  /*!< Sector is unlocked*/
    kStatus_FLASH_SectorLocked = MAKE_STATUS(kStatusGroupFlashDriver, 10),   /*!< Sector is locked*/
    kStatus_FLASH_NotSupported = MAKE_STATUS(kStatusGroupFlashDriver, 11),   /*!< Unsupported operation/feature*/
};

/*!
 * @brief Enumeration for various flash properties.
 */
typedef enum _flash_property_tag
{
    kFLASH_PropertyPflashSectorSize    = 0x00U, /*!< Pflash sector size property.*/
    kFLASH_PropertyPflashTotalSize     = 0x01U, /*!< Pflash total size property.*/
    kFLASH_PropertyPflashBlockSize     = 0x02U, /*!< Pflash block size property.*/
    kFLASH_PropertyPflashBlockCount    = 0x03U, /*!< Pflash block count property.*/
    kFLASH_PropertyPflashBlockBaseAddr = 0x04U, /*!< Pflash block base address property.*/
} flash_property_tag_t;

/*!
 * @brief Constructs the four character code for the Flash driver API key.
 */
#if !defined(FOUR_CHAR_CODE)
#define FOUR_CHAR_CODE(a, b, c, d) (((d) << 24) | ((c) << 16) | ((b) << 8) | ((a)))
#endif

/*!
 * @brief Enumeration for Flash driver API keys.
 *
 * @note The resulting value is built with a byte order such that the string
 * being readable in expected order when viewed in a hex editor, if the value
 * is treated as a 32-bit little endian value.
 */
enum _flash_driver_api_keys
{
    kFLASH_ApiEraseKey = FOUR_CHAR_CODE('c', '4', '0', 'k') /*!< Key value used to validate all flash erase APIs.*/
};

/*! @brief Flash driver state information.
 *
 * An instance of this structure is allocated by the user of the flash driver and
 * passed into each of the driver APIs.
 */
typedef struct _flash_config
{
    uint32_t PFlashBlockBase;          /*!< Base address of the first PFlash block */
    uint32_t PFlashTotalSize;          /*!< Size of combined PFlash blocks */
    uint32_t PFlashBlockCount;         /*!< Number of PFlash blocks */
    uint32_t PFlashSectorSize;         /*!< Size in bytes of a sector of PFlash */

    uint32_t DataFlashBase;            /*!< Base address of the Data Flash */
    uint32_t DataFlashSize;            /*!< Size of the Data Flash */
} flash_config_t;


/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Initializes the global flash properties structure members.
 *
 * This function checks and initializes the Flash module for the other Flash APIs.
 *
 * @param config         Pointer to the storage for the driver runtime state.
 * @param coreDomainId   Domain Id of the core accessing the flash.
 *
 * @retval #kStatus_FLASH_Success API was executed successfully.
 * @retval #kStatus_FLASH_InvalidArgument An invalid argument is provided.
 */
status_t FLASH_Init(flash_config_t *config);


/*!
 * @brief Erases the flash sectors encompassed by parameters passed into function.
 *
 * This function erases the appropriate number of flash sectors based on the
 * desired start address and length.
 *
 * @param config The pointer to the storage for the driver runtime state.
 * @param start The start address of the desired flash memory to be erased.
 *              The start address does not need to be sector-aligned but must be word-aligned.
 * @param lengthInBytes The length, given in bytes (not words or long-words)
 *                      to be erased. Must be word-aligned.
 * @param key The value used to validate all flash erase APIs.
 *
 * @retval #kStatus_FLASH_Success API was executed successfully.
 * @retval #kStatus_FLASH_InvalidArgument An invalid argument is provided.
 * @retval #kStatus_FLASH_AlignmentError The parameter is not aligned with the specified baseline.
 * @retval #kStatus_FLASH_AddressError The address is out of range.
 * @retval #kStatus_FLASH_EraseKeyError The API erase key is invalid.
 * @retval #kStatus_FLASH_ExecuteInRamFunctionNotReady Execute-in-RAM function is not available.
 * @retval #kStatus_FLASH_AccessError Invalid instruction codes and out-of bounds addresses.
 * @retval #kStatus_FLASH_ProtectionViolation The program/erase operation is requested to execute on protected areas.
 * @retval #kStatus_FLASH_CommandFailure Run-time error during the command execution.
 */
status_t FLASH_Erase(flash_config_t *config, uint32_t start, uint32_t lengthInBytes, uint32_t key);


/*!
 * @brief Programs flash with data at locations passed in through parameters.
 *
 * This function programs the flash memory with the desired data for a given
 * flash area as determined by the start address and the length.
 *
 * @param config A pointer to the storage for the driver runtime state.
 * @param start The start address of the desired flash memory to be programmed. Must be 8-byte aligned.
 * @param src A pointer to the source buffer of data that is to be programmed into the flash.
 * @param lengthInBytes The length in bytes to be programmed. Must be 8-byte aligned.
 *
 * @retval #kStatus_FLASH_Success API was executed successfully.
 * @retval #kStatus_FLASH_InvalidArgument An invalid argument is provided.
 * @retval #kStatus_FLASH_AlignmentError Address or size parameters are not aligned.
 * @retval #kStatus_FLASH_AddressError Address is out of range.
 * @retval #kStatus_FLASH_ProtectionViolation The program/erase operation is requested to execute on protected areas.
 * @retval #kStatus_FLASH_CommandFailure Run-time error during the command execution.
 */
status_t FLASH_Program(flash_config_t *config, uint32_t start, uint32_t *src, uint32_t lengthInBytes);


/*!
 * @brief Sets the sector protection to the intended protection status.
 *
 * @param config   A pointer to storage for the driver runtime state.
 * @param address  Address belonging to the corresponding sector
 * @param locked   Protection will be set if true
 *
 * @retval #kStatus_FLASH_Success        API was executed successfully
 * @retval #kStatus_FLASH_CommandFailure Failed to verify sector protection changed
 * @retval #kStatus_FLASH_AddressError   Invalid address
 */
status_t FLASH_SetSectorProtection(flash_config_t *config, uint32_t address, bool locked);


/*!
 * @brief Returns current state of sector protection
 *
 * @param config   A pointer to storage for the driver runtime state.
 * @param address  Address belonging to the corresponding sector
 *
 * @retval #kStatus_FLASH_SectorLocked      Sector protection for given address is ACTIVE
 * @retval #kStatus_FLASH_SectorUnlocked    Sector protection for given address is INACTIVE
 * @retval #kStatus_FLASH_AddressError      Invalid address
 */
status_t FLASH_GetSectorProtection(flash_config_t *config, uint32_t address);

#if defined(__cplusplus)
}
#endif

#endif /* FSL_C40_FLASH_H_ */
