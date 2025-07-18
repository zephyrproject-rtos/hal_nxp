/*
 * Copyright 2024-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef __FSL_IAP_H_
#define __FSL_IAP_H_

#include "fsl_common.h"
/*!
 * @addtogroup flash_driver
 * @{
 */

/*! @file */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*!
 * Flash related constants
 */
#define FLASH_SIZE_BYTES        FSL_FEATURE_SYSCON_FLASH_SIZE_BYTES
#define FLASH_PAGE_SIZE_BYTES   FSL_FEATURE_SYSCON_FLASH_PAGE_SIZE_BYTES
#define FLASH_SECTOR_SIZE_BYTES FSL_FEATURE_SYSCON_FLASH_SECTOR_SIZE_BYTES

#define FLASH_CFPA_SCRATCH_ADDRESS  (FLASH_CFPA_SCRATCH_BASE)
#define FLASH_CFPA_PING_ADDRESS     (FLASH_CFPA0_BASE)
#define FLASH_CFPA_PONG_ADDRESS     (FLASH_CFPA1_BASE)
#define FLASH_CMPA_ADDRESS          (FLASH_CMPA_BASE)
#define FLASH_OEM_KEY_STORE_ADDRESS (FLASH_KEY_STORE_BASE)
#define FLASH_NXP_KEY_STORE_ADDRESS (FLASH_KEY_STORE_BASE + 0x1000)

#define FLASH_LAST_PRINCE_ADDRESS (0xFDFFFU)

/*!
 * @name Flash version
 * @{
 */
/*! Constructs the version number for drivers. */
#if !defined(MAKE_VERSION)
#define MAKE_VERSION(major, minor, bugfix) (((major) << 16) | ((minor) << 8) | (bugfix))
#endif

/*! Flash driver version for SDK*/
#define FSL_FLASH_DRIVER_VERSION (MAKE_VERSION(1, 0, 0)) /*!< Version 1.0.0. */

/*! Flash driver version for ROM*/
enum flash_driver_version_constants_s
{
    kFLASH_DriverVersionName   = 'F', /*!< Flash driver version name.*/
    kFLASH_DriverVersionMajor  = 1,   /*!< Major flash driver version.*/
    kFLASH_DriverVersionMinor  = 0,   /*!< Minor flash driver version.*/
    kFLASH_DriverVersionBugfix = 0    /*!< Bugfix for flash driver version.*/
};

/*@}*/

/*!
 * @name Flash status
 * @{
 */
/*! Flash driver status group. */
#if defined(kStatusGroup_FlashDriver)
#define kStatusGroupGeneric     kStatusGroup_Generic
#define kStatusGroupFlashDriver kStatusGroup_FlashDriver
#elif defined(kStatusGroup_FLASHIAP)
#define kStatusGroupGeneric     kStatusGroup_Generic
#define kStatusGroupFlashDriver kStatusGroup_FLASH
#else
#define kStatusGroupGeneric     0U
#define kStatusGroupFlashDriver 1U
#endif

/*! Constructs a status code value from a group and a code number. */
#if !defined(MAKE_STATUS)
#define MAKE_STATUS(group, code) ((((group)*100) + (code)))
#endif

/*!
 * Flash driver status codes.
 */
enum flash_status_s
{
    kStatus_FLASH_Success         = MAKE_STATUS(kStatusGroupGeneric, 0u),     /*!< API is executed successfully*/
    kStatus_FLASH_InvalidArgument = MAKE_STATUS(kStatusGroupGeneric, 4u),     /*!< Invalid argument*/
    kStatus_FLASH_SizeError       = MAKE_STATUS(kStatusGroupFlashDriver, 0u), /*!< Error size*/
    kStatus_FLASH_AlignmentError =
        MAKE_STATUS(kStatusGroupFlashDriver, 1u), /*!< Parameter is not aligned with the specified baseline*/
    kStatus_FLASH_AddressError = MAKE_STATUS(kStatusGroupFlashDriver, 2u), /*!< Address is out of range */
    kStatus_FLASH_AccessError =
        MAKE_STATUS(kStatusGroupFlashDriver, 3u), /*!< Invalid instruction codes and out-of bound addresses */
    kStatus_FLASH_ProtectionViolation = MAKE_STATUS(
        kStatusGroupFlashDriver, 4u), /*!< The program/erase operation is requested to execute on protected areas */
    kStatus_FLASH_CommandFailure =
        MAKE_STATUS(kStatusGroupFlashDriver, 5u), /*!< Run-time error during command execution. */
    kStatus_FLASH_UnknownProperty = MAKE_STATUS(kStatusGroupFlashDriver, 6u), /*!< Unknown property.*/
    kStatus_FLASH_EraseKeyError   = MAKE_STATUS(kStatusGroupFlashDriver, 7u), /*!< API erase key is invalid.*/
    kStatus_FLASH_RegionExecuteOnly =
        MAKE_STATUS(kStatusGroupFlashDriver, 8u), /*!< The current region is execute-only.*/
    kStatus_FLASH_ExecuteInRamFunctionNotReady =
        MAKE_STATUS(kStatusGroupFlashDriver, 9u), /*!< Execute-in-RAM function is not available.*/
    kStatus_FLASH_PartitionStatusUpdateFailure =
        MAKE_STATUS(kStatusGroupFlashDriver, 10u), /*!< Failed to update partition status.*/
    kStatus_FLASH_SetFlexramAsEepromError =
        MAKE_STATUS(kStatusGroupFlashDriver, 11u), /*!< Failed to set FlexRAM as EEPROM.*/
    kStatus_FLASH_RecoverFlexramAsRamError =
        MAKE_STATUS(kStatusGroupFlashDriver, 12u), /*!< Failed to recover FlexRAM as RAM.*/
    kStatus_FLASH_SetFlexramAsRamError = MAKE_STATUS(kStatusGroupFlashDriver, 13u), /*!< Failed to set FlexRAM as RAM.*/
    kStatus_FLASH_RecoverFlexramAsEepromError =
        MAKE_STATUS(kStatusGroupFlashDriver, 14u), /*!< Failed to recover FlexRAM as EEPROM.*/
    kStatus_FLASH_CommandNotSupported = MAKE_STATUS(kStatusGroupFlashDriver, 15u), /*!< Flash API is not supported.*/
    kStatus_FLASH_SwapSystemNotInUninitialized =
        MAKE_STATUS(kStatusGroupFlashDriver, 16u), /*!< Swap system is not in an uninitialzed state.*/
    kStatus_FLASH_SwapIndicatorAddressError =
        MAKE_STATUS(kStatusGroupFlashDriver, 17u), /*!< The swap indicator address is invalid.*/
    kStatus_FLASH_ReadOnlyProperty = MAKE_STATUS(kStatusGroupFlashDriver, 18u), /*!< The flash property is read-only.*/
    kStatus_FLASH_InvalidPropertyValue =
        MAKE_STATUS(kStatusGroupFlashDriver, 19u), /*!< The flash property value is out of range.*/
    kStatus_FLASH_CommandAborOption =
        MAKE_STATUS(kStatusGroupFlashDriver, 21u), /*!< The option of flash prefetch speculation is invalid.*/
    kStatus_FLASH_CompareError =
        MAKE_STATUS(kStatusGroupFlashDriver, 22u), /*!< Destination and source memory contents do not match. */
    kStatus_FLASH_OutOfDateCfpaPage =
        MAKE_STATUS(kStatusGroupFlashDriver, 32u), /*!< CFPA page version is out of date. */
    kStatus_FLASH_BlankIfrPageData = MAKE_STATUS(kStatusGroupFlashDriver, 33u), /*!< Blank page cannnot be read. */
    kStatus_FLASH_HashCheckError = MAKE_STATUS(kStatusGroupFlashDriver, 36u), /*!< Hash check of page data is failed. */
    kStatus_FLASH_SealedFfrRegion      = MAKE_STATUS(kStatusGroupFlashDriver, 37u), /*!< The FFR region is sealed. */
    kStatus_FLASH_FfrRegionWriteBroken = MAKE_STATUS(
        kStatusGroupFlashDriver, 38u), /*!< The FFR Spec region is not allowed to be written discontinuously. */
    kStatus_FLASH_NmpaAccessNotAllowed =
        MAKE_STATUS(kStatusGroupFlashDriver, 39u), /*!< The NMPA region is not allowed to be read/written/erased. */
    kStatus_FLASH_CmpaCfgDirectEraseNotAllowed =
        MAKE_STATUS(kStatusGroupFlashDriver, 40u), /*!< The CMPA Cfg region is not allowed to be erased directly. */
    kStatus_FLASH_FfrBankIsLocked = MAKE_STATUS(kStatusGroupFlashDriver, 0x29), /*!< The FFR bank region is locked. */
    kStatus_FLASH_CfpaScratchPageInvalid =
        MAKE_STATUS(kStatusGroupFlashDriver, 48u), /*!< CFPA Scratch Page is invalid*/
    kStatus_FLASH_CfpaVersionRollbackDisallowed =
        MAKE_STATUS(kStatusGroupFlashDriver, 49u), /*!< CFPA version rollback is not allowed */
};
/*@}*/

/*!
 * @name Flash API key
 * @{
 */
/*! Constructs the four character code for the Flash driver API key. */
#if !defined(FOUR_CHAR_CODE)
#define FOUR_CHAR_CODE(a, b, c, d) (((d) << 24) | ((c) << 16) | ((b) << 8) | ((a)))
#endif

/*!
 * Enumeration for Flash driver API keys.
 */
enum flash_driver_api_keys_s
{
    kFLASH_ApiEraseKey = FOUR_CHAR_CODE('l', 'f', 'e', 'k') /*!< Key value used to validate all flash erase APIs.*/
};
/*@}*/

/*!
 * Enumeration for various flash properties.
 */
typedef enum flash_property_tag_s
{
    kFLASH_PropertyPflashSectorSize    = 0x00U,
    kFLASH_PropertyPflashTotalSize     = 0x01U,
    kFLASH_PropertyPflashBlockSize     = 0x02U,
    kFLASH_PropertyPflashBlockCount    = 0x03U,
    kFLASH_PropertyPflashBlockBaseAddr = 0x04U,

    kFLASH_PropertyPflashPageSize   = 0x30U,
    kFLASH_PropertyPflashSystemFreq = 0x31U,

    kFLASH_PropertyFfrSectorSize    = 0x40U,
    kFLASH_PropertyFfrTotalSize     = 0x41U,
    kFLASH_PropertyFfrBlockBaseAddr = 0x42U,
    kFLASH_PropertyFfrPageSize      = 0x43U,
} flash_property_tag_t;

/*!
 * Flash memory descriptor.
 */
typedef struct flash_mem_desc_s
{
    uint32_t blockBase;
    uint32_t totalSize;
    uint32_t blockCount;
    uint32_t pageSize;
    uint32_t sectorSize;
} flash_mem_desc_t;

/*! Flash controller paramter config. */
typedef struct flash_ffr_config_s
{
    uint32_t ffrBlockBase;
    uint32_t ffrTotalSize;
    uint32_t ffrPageSize;
    uint32_t cfpaPageVersion;
    uint32_t cfpaPageAddress;
} flash_ffr_config_t;

/*! Flash driver state information.
 *
 * An instance of this structure is allocated by the user of the flash driver and
 * passed into each of the driver APIs.
 */
typedef struct flash_config_s
{
    uint32_t sysFreqInMHz;
    flash_mem_desc_t flashDesc;
    flash_ffr_config_t ffrConfig;
} flash_config_t;

/*******************************************************************************
 * API
 ******************************************************************************/

/*!
 * @name Initialization
 * @{
 */

/*!
 * Initializes the flash properties structure members.
 *
 * @param config Pointer to the storage for the driver runtime state.
 *
 * @retval #kStatus_FLASH_Success API was executed successfully.
 * @retval #kStatus_FLASH_InvalidArgument An invalid argument is provided.
 */
status_t FLASH_Init(flash_config_t *config);

/*@}*/

/*!
 * @name Erasing
 * @{
 */

/*!
 * Erases the specified flash sectors.
 *
 * This function erases the appropriate number of flash sectors based on the
 * desired start address and length.
 *
 * @param config The pointer to the storage for the driver runtime state.
 * @param start The start address of the desired flash memory to be erased.
 *              The start address need to be 8192bytes-aligned.
 * @param lengthInBytes The length, given in bytes (not words or long-words)
 *                      to be erased. Must be 8192bytes-aligned.
 * @param key The value used to validate all flash erase APIs.
 *
 * @retval #kStatus_FLASH_Success API was executed successfully;
 *         the appropriate number of flash sectors based on the desired
 *         start address and length were erased successfully.
 * @retval #kStatus_FLASH_InvalidArgument An invalid argument is provided.
 * @retval #kStatus_FLASH_AlignmentError The parameter is not aligned with the specified baseline.
 * @retval #kStatus_FLASH_AddressError The address is out of range.
 * @retval #kStatus_FLASH_EraseKeyError The API erase key is invalid.
 *
 * @attention No interrupts should be executed from flash while executing this function.
 */
status_t FLASH_Erase(flash_config_t *config, uint32_t start, uint32_t lengthInBytes, uint32_t key);

/*@}*/

/*!
 * @name Programming
 * @{
 */

/*!
 * Programs data to flash.
 *
 * This function programs the flash memory with the desired data for a given
 * flash area as determined by the start address and the length.
 *
 * @param config A pointer to the storage for the driver runtime state.
 * @param start The start address of the desired flash memory to be programmed. Must be
 *              16bytes-aligned.
 * @param src A pointer to the source buffer of data that is to be programmed
 *            into the flash.
 * @param lengthInBytes The length, given in bytes (not words or long-words),
 *                      to be programmed. Must be 16bytes-aligned.
 *
 * @retval #kStatus_FLASH_Success API was executed successfully; the desired data were programed successfully
 *         into flash based on desired start address and length.
 * @retval #kStatus_FLASH_InvalidArgument An invalid argument is provided.
 * @retval #kStatus_FLASH_AlignmentError Parameter is not aligned with the specified baseline.
 * @retval #kStatus_FLASH_AddressError Address is out of range.
 * @retval #kStatus_FLASH_AccessError Invalid instruction codes and out-of bounds addresses.
 * @retval #kStatus_FLASH_CommandFailure Run-time error during the command execution.
 *
 * @attention No interrupts should be executed from flash while executing this function.
 */
status_t FLASH_Program(flash_config_t *config, uint32_t start, uint8_t *src, uint32_t lengthInBytes);

/*@}*/

/*!
 * @name Verification
 * @{
 */

/*!
 * Reads data from flash.
 *
 * This function read the flash memory from a given flash area as determined
 * by the start address and the length.
 *
 * @param config A pointer to the storage for the driver runtime state.
 * @param start The start address of the desired flash memory to be read.
 * @param dest A pointer to the dest buffer of data that is to be read
 *            from the flash.
 * @param lengthInBytes The length, given in bytes (not words or long-words),
 *                      to be read.
 *
 * @retval #kStatus_FLASH_Success API was executed successfully.
 * @retval #kStatus_FLASH_AddressError Address is out of range.
 */
status_t FLASH_Read(flash_config_t *config, uint32_t start, uint8_t *dest, uint32_t lengthInBytes);

/*!
 * Verifies if erase of the specified sectors was successful.
 *
 * This function checks whether the appropriate number of flash sectors is erased based on
 * the desired start address and length.
 *
 * @param config A pointer to the storage for the driver runtime state.
 * @param start The start address of the desired flash memory to be verified.
 *        The start address need to be 8192bytes-aligned.
 * @param lengthInBytes The length, given in bytes (not words or long-words),
 *        to be verified. Must be 8192bytes-aligned.
 *
 * @retval #kStatus_FLASH_Success API was executed successfully; the specified FLASH region has been erased.
 * @retval #kStatus_FLASH_InvalidArgument An invalid argument is provided.
 * @retval #kStatus_FLASH_AlignmentError Parameter is not aligned with specified baseline.
 * @retval #kStatus_FLASH_AddressError Address is out of range.
 * @retval #kStatus_FLASH_AccessError Invalid instruction codes and out-of bounds addresses.
 * @retval #kStatus_FLASH_CommandFailure Run-time error during the command execution.
 *
 * @attention No interrupts should be executed from flash while executing this function.
 */
status_t FLASH_VerifyErase(flash_config_t *config, uint32_t start, uint32_t lengthInBytes);

/*!
 * Verifies if programming of the specified data was successful.
 *
 * This function verifies the data programed in the flash memory using the
 * Flash Program Check Command and compares it to the expected data for a given
 * flash area as determined by the start address and length.
 *
 * @param config A pointer to the storage for the driver runtime state.
 * @param start The start address of the desired flash memory to be verified. need be 8192bytes-aligned.
 * @param lengthInBytes The length, given in bytes (not words or long-words),
 *        to be verified. need be 8192bytes-aligned.
 * @param expectedData A pointer to the expected data that is to be
 *        verified against.
 * @param failedAddress A pointer to the returned failing address.
 * @param failedData A pointer to the returned failing data.
 *
 * @retval #kStatus_FLASH_Success API was executed successfully;
 *         the desired data have been successfully programed into specified FLASH region.
 *
 * @retval #kStatus_FLASH_InvalidArgument An invalid argument is provided.
 * @retval #kStatus_FLASH_AddressError Address is out of range.
 * @retval #kStatus_FLASH_AccessError Invalid instruction codes and out-of bounds addresses.
 * @retval #kStatus_FLASH_CommandFailure Run-time error during the command execution.
 *
 * @attention No interrupts should be executed from flash while executing this function.
 */
status_t FLASH_VerifyProgram(flash_config_t *config,
                             uint32_t start,
                             uint32_t lengthInBytes,
                             const uint8_t *expectedData,
                             uint32_t *failedAddress,
                             uint32_t *failedData);

/*@}*/

/*!
 * @name Properties
 * @{
 */

/*!
 * Returns the desired flash property.
 *
 * @param config A pointer to the storage for the driver runtime state.
 * @param whichProperty The desired property from the list of properties in
 *        enum flash_property_tag_t
 * @param value A pointer to the value returned for the desired flash property.
 *
 * @retval #kStatus_FLASH_Success API was executed successfully; the flash property was stored to value.
 * @retval #kStatus_FLASH_UnknownProperty An unknown property tag.
 *
 * @pre Properties only work after executing FLASH_Init() first.
 */
status_t FLASH_GetProperty(flash_config_t *config, flash_property_tag_t whichProperty, uint32_t *value);

/*!
 * Clears the FLASH cache.
 *
 * @note The kCLOCK_Sysctl clock must be enabled for this function to have an effect.
 */
void FLASH_CacheClear(void);

/*!
 * Enables/disables speculative loading of the cache.
 *
 * @param enable True to enable the speculative loading, False to disable it.
 *
 * @note The kCLOCK_Sysctl clock must be enabled for this function to have an effect.
 */
void FLASH_CacheSpeculationControl(bool enable);

/*!
 * Checks a given flash area  as determined by the start address and the length
 * for unrecoverable ECC errors. In case an unrecoverable ECC error is present,
 * reading from this area will raise a HardFault exception.
 *
 * @param config A pointer to the storage for the driver runtime state.
 * @param start The start address of the desired flash memory to be read.
 * @param lengthInBytes The length, given in bytes (not words or long-words),
 *                      to be read.
 *
 * @retval #kStatus_FLASH_Success API was executed successfully.
 * @retval #kStatus_FLASH_AddressError Address is out of range.
 * @retval #kStatus_FLASH_AccessError An unrecoverable ECC error is present.
 *
 * @note The kCLOCK_Sysctl clock must be enabled for this function to work correctly.
 *
 * @attention No interrupts should be executed while executing this function.
 */
status_t FLASH_CheckECC(flash_config_t *config, uint32_t start, uint32_t lengthInBytes);
/*@}*/

/*@}*/

#endif /* __FLASH_FLASH_H_ */
