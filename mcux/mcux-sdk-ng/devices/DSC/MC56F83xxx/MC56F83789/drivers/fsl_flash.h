/*
 * Copyright 2019 - 2021 NXP
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef FSL_FLASHIAP_H
#define FSL_FLASHIAP_H

#include "fsl_common.h"

/*!
 * @defgroup flash_driver Flash Driver
 * @details The flash driver provides general APIs to handle specific operations on chip flash;
 *          The user can use those APIs directly in the application.
 *          The flash supports:
 *          - Initialize the global flash
 *          - Erase flash region.
 *          - Program data to flash.
 * @{
 */

/*********************************************************************************************************************
 *                               Driver change logs
 *********************************************************************************************************************/

/*!
 * @defgroup flash_driver_log Driver Change Log
 * @ingroup flash_driver
 * @{
 * The current FLASH driver version is 3.2.0.
 *
 * - 3.2.0
 *   - Change file name to fsl_flash.x
 *
 * - 3.1.0
 *   - Accumulated bug fix
 *   - MISRA warning fix
 *
 * - 3.0.0
 *   - Initial version.
 * @}
 */

/*********************************************************************************************************************
 *                               Variable types
 *********************************************************************************************************************/
typedef int flash_status_t;

/*!
 * @name Flash version
 * @{
 */
/*! @brief Flash driver version for SDK*/
#define FSL_FLASH_DRIVER_VERSION (MAKE_VERSION(3U, 2U, 0U))

/*! @brief Flash driver version for ROM*/
#define FSL_FLASH_DRIVER_VERSION_ROM (MAKE_VERSION(3U, 2U, 0U))

/*! @brief Flash driver version for ROM*/
enum _flash_driver_version_constants
{
    kFLASH_DriverVersionName   = 'F', /*!< Flash driver version name.*/
    kFLASH_DriverVersionMajor  = 3,   /*!< Major flash driver version.*/
    kFLASH_DriverVersionMinor  = 0,   /*!< Minor flash driver version.*/
    kFLASH_DriverVersionBugfix = 0    /*!< Bugfix for flash driver version.*/
};

/* @brief Structure of version property.*/
typedef union _standard_version
{
    struct
    {
        uint8_t bugfix; /* bugfix version [7:0] */
        uint8_t minor;  /* minor version [15:8] */
        uint8_t major;  /* major version [23:16] */
        char name;      /* name [31:24] */
    } B;
    uint32_t version; /* combined version numbers */

#if defined(__cplusplus)
    StandardVersion() : version(0)
    {
    }
    StandardVersion(uint32_t version) : version(version)
    {
    }
#endif
} standard_version_t;

/*@}*/

/*********************************************************************************************************************
 *                               enumeration and structure types definition for input parameter
 *********************************************************************************************************************/

/*!
 * @brief Enumeration for FLASH driver API keys.
 *
 * @note The resulting value is built with a byte order such that the string
 * being readable in expected order when viewed in a hex editor, if the value
 * is treated as a 32-bit little endian value.
 */
enum _flash_driver_api_keys
{
    kFLASH_ApiEraseKey = 0x6B65666BUL
};

/*!
 * @brief Enumeration for the two possible options of flash read resource command.
 */
typedef enum _flash_read_resource_opt
{
    kFLASH_ResourceOptionFlashIfr =
        0x00U, /*!< Select code for Program flash 0 IFR, Program flash swap 0 IFR, Data flash 0 IFR */
    kFLASH_ResourceOptionVersionId = 0x01U /*!< Select code for the version ID*/
} flash_read_resource_opt_t;

/*!
 * @brief Enumeration for supported FTFx margin levels.
 */
typedef enum _flash_margin_value
{
    kFLASH_MarginValueNormal,  /*!< Use the 'normal' read level for 1s.*/
    kFLASH_MarginValueUser,    /*!< Apply the 'User' margin to the normal read-1 level.*/
    kFLASH_MarginValueFactory, /*!< Apply the 'Factory' margin to the normal read-1 level.*/
    kFLASH_MarginValueInvalid  /*!< Not real margin level, Used to determine the range of valid margin level. */
} flash_margin_value_t;

/*!
 * @brief Enumeration for the three possible FTFx security states.
 */
typedef enum _flash_security_state
{
    kFLASH_SecurityStateNotSecure        = 0xc33cc33cU, /*!< Flash is not secure.*/
    kFLASH_SecurityStateBackdoorEnabled  = 0x5aa55aa5U, /*!< Flash backdoor is enabled.*/
    kFLASH_SecurityStateBackdoorDisabled = 0x5ac33ca5U  /*!< Flash backdoor is disabled.*/
} flash_security_state_t;

/*!
 * @brief Enumeration for the possible options of Swap control commands
 */
typedef enum _flash_swap_control_opt
{
    kFLASH_SwapControlOptionIntializeSystem    = 0x01U, /*!< An option used to initialize the Swap system */
    kFLASH_SwapControlOptionSetInUpdateState   = 0x02U, /*!< An option used to set the Swap in an update state */
    kFLASH_SwapControlOptionSetInCompleteState = 0x04U, /*!< An option used to set the Swap in a complete state */
    kFLASH_SwapControlOptionReportStatus       = 0x08U, /*!< An option used to report the Swap status */
    kFLASH_SwapControlOptionDisableSystem      = 0x10U  /*!< An option used to disable the Swap status */
} flash_swap_control_opt_t;

/*!
 * @brief Enumeration for the possible flash Swap status.
 */
typedef enum _flash_swap_state
{
    kFLASH_SwapStateUninitialized = 0x00U, /*!< Flash Swap system is in an uninitialized state.*/
    kFLASH_SwapStateReady         = 0x01U, /*!< Flash Swap system is in a ready state.*/
    kFLASH_SwapStateUpdate        = 0x02U, /*!< Flash Swap system is in an update state.*/
    kFLASH_SwapStateUpdateErased  = 0x03U, /*!< Flash Swap system is in an updateErased state.*/
    kFLASH_SwapStateComplete      = 0x04U, /*!< Flash Swap system is in a complete state.*/
    kFLASH_SwapStateDisabled      = 0x05U  /*!< Flash Swap system is in a disabled state.*/
} flash_swap_state_t;

/*!
 * @brief Enumeration for the possible flash Swap block status
 */
typedef enum _flash_swap_block_status
{
    kFLASH_SwapBlockStatusLowerHalfProgramBlocksAtZero =
        0x00U, /*!< Swap block status is that lower half program block at zero.*/
    kFLASH_SwapBlockStatusUpperHalfProgramBlocksAtZero =
        0x01U /*!< Swap block status is that upper half program block at zero.*/
} flash_swap_block_status_t;

/*!
 * @brief Flash Swap information
 */
typedef struct _flash_swap_state_config
{
    flash_swap_state_t flashSwapState;                /*!<The current Swap system status.*/
    flash_swap_block_status_t currentSwapBlockStatus; /*!< The current Swap block status.*/
    flash_swap_block_status_t nextSwapBlockStatus;    /*!< The next Swap block status.*/
} flash_swap_state_config_t;

/*!
 * @brief Enumeration for FTFx memory type.
 */
enum _flash_memory_type
{
    kFLASH_MemTypePflash  = 0x00U,
    kFLASH_MemTypeFlexnvm = 0x01U
};

/*!
 * @brief ftfx special memory access information.
 */
typedef struct _flash_special_mem
{
    uint32_t base;  /*!< Base address of flash special memory.*/
    uint32_t size;  /*!< size of flash special memory.*/
    uint32_t count; /*!< flash special memory count.*/
} flash_spec_mem_t;

/*!
 * @brief Flash memory descriptor.
 */
typedef struct _flash_mem_desc_t
{
    uint8_t type;  /*!< Type of flash block.*/
    uint8_t index; /*!< Index of flash block.*/
    uint8_t reserved[2];
    struct
    {
        uint32_t isIndBlock : 1;
        uint32_t hasIndPfsizeReg : 1;
        uint32_t hasProtControl : 1;
        uint32_t hasIndProtReg : 1;
        uint32_t hasXaccControl : 1;
        uint32_t hasIndXaccReg : 1;
        uint32_t : 18;
        uint32_t ProtRegBits : 8;
    } feature;
    uint32_t blockBase;  /*!< A base address of the flash block */
    uint32_t totalSize;  /*!< The size of the flash block. */
    uint32_t sectorSize; /*!< The size in bytes of a sector of flash. */
    uint32_t blockCount; /*!< A number of flash blocks. */
    flash_spec_mem_t accessSegmentMem;
    flash_spec_mem_t protectRegionMem;
} flash_mem_desc_t;

/*!
 * @brief Active FTFx information for the current operation.
 */
typedef struct _flash_ops_config
{
    uint32_t convertedAddress; /*!< A converted address for the current flash type.*/
    struct
    {
        uint8_t sectorCmd;
        uint8_t sectionCmd;
        uint8_t resourceCmd;
        uint8_t checkCmd;
        uint8_t swapCtrlCmd;
        uint8_t blockWriteUnitSize;
        uint8_t reserved[2];
    } addrAligment;
} flash_ops_config_t;

/*!
 * @brief Flash IFR memory descriptor.
 */
typedef struct _flash_ifr_desc
{
    struct
    {
        uint32_t has4ByteIdxSupport : 1;
        uint32_t has8ByteIdxSupport : 1;
        uint32_t : 30;
    } feature;
    struct
    {
        uint8_t versionIdStart;
        uint8_t versionIdSize;
        uint16_t ifrMemSize;
        uint32_t pflashIfrStart;
        uint32_t dflashIfrStart;
        uint32_t pflashSwapIfrStart;
    } resRange;
    struct
    {
        uint16_t mix8byteIdxStart;
        uint16_t mix8byteIdxEnd;
    } idxInfo;
} flash_ifr_desc_t;

/*! @brief Flash driver state information.
 *
 * An instance of this structure is allocated by the user of the flash driver and
 * passed into each of the driver APIs.
 */
typedef struct _ftfx_config
{
    flash_mem_desc_t flashDesc;
    flash_ops_config_t opsConfig;
    uint32_t flexramBlockBase; /*!< The base address of the FlexRAM/acceleration RAM */
    uint32_t flexramTotalSize; /*!< The size of the FlexRAM/acceleration RAM */
    uint16_t eepromTotalSize;  /*!< The size of EEPROM area which was partitioned from FlexRAM */
    uint16_t reserved;
    uint32_t *runCmdFuncAddr; /*!< An buffer point to the flash execute-in-RAM function. */
    flash_ifr_desc_t ifrDesc;
} ftfx_config_t;

/*! @brief Construct a status code value from a group and code number. */
#if !defined(MAKE_STATUS)
#define MAKE_STATUS(group, code) ((((group)*100) + (code)))
#endif

/*! @brief Flash driver state information.
 *
 * An instance of this structure is allocated by the user of the flash driver and
 * passed into each of the driver APIs.
 */
#define FTFx_FLASH_COUNT 1
typedef struct _flash_config
{
    ftfx_config_t ftfxConfig[FTFx_FLASH_COUNT];
} flash_config_t;

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
    kFLASH_PropertyVersion             = 0x22U
} flash_property_tag_t;

typedef union
{
    uint32_t dummy[1];
    uint8_t byte[4];
} UNION_Type_aligned_for_longword;

/*!
 * @brief FTFx driver status codes.
 */
enum _flash_status
{
    kStatus_FLASH_Success         = 0U,  /*!< API is executed successfully*/
    kStatus_FLASH_InvalidArgument = 4,   /*!< Invalid argument*/
    kStatus_FLASH_SizeError       = 100, /*!< Error size*/
    kStatus_FLASH_AlignmentError  = 101, /*!< Parameter is not aligned with the specified baseline*/
    kStatus_FLASH_AddressError    = 102, /*!< Address is out of range */
    kStatus_FLASH_AccessError     = 103, /*!< Invalid instruction codes and out-of bound addresses */
    kStatus_FLASH_ProtectionViolation =
        104, /*!< The program/erase operation is requested to execute on protected areas */
    kStatus_FLASH_CommandFailure               = 105, /*!< Run-time error during command execution. */
    kStatus_FLASH_UnknownProperty              = 106, /*!< Unknown property.*/
    kStatus_FLASH_EraseKeyError                = 107, /*!< API erase key is invalid.*/
    kStatus_FLASH_CommandNotSupported          = 115, /*!< Flash API is not supported.*/
    kStatus_FLASH_SwapSystemNotInUninitialized = 116, /*!< Swap system is not in an uninitialzed state.*/
    kStatus_FLASH_SwapIndicatorAddressError    = 117, /*!< The swap indicator address is invalid.*/
    kStatus_FLASH_ReadOnlyProperty             = 118, /*!< The flash property is read-only.*/
    kStatus_FLASH_InvalidPropertyValue         = 119, /*!< The flash property value is out of range.*/
    kStatus_FLASH_InvalidSpeculationOption     = 120  /*!< The option of flash prefetch speculation is invalid.*/
};

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @name Initialization
 * @{
 */

/*!
 * @brief Initializes the global flash properties structure members.
 *
 * This function checks and initializes the Flash module for the other Flash APIs.
 *
 * @param config Pointer to the storage for the driver runtime state.
 *
 * @retval #kStatus_FLASH_Success API was executed successfully.
 * @retval #kStatus_FLASH_InvalidArgument An invalid argument is provided.
 */
flash_status_t FLASH_Init(flash_config_t *config);

/*@}*/

/*!
 * @name Properties
 * @{
 */

/*!
 * @brief Returns the desired flash property.
 *
 * @param config A pointer to the storage for the driver runtime state.
 * @param whichProperty The desired property from the list of properties in
 *        enum flash_property_tag_t
 * @param value A pointer to the value returned for the desired flash property.
 *
 * @retval #kStatus_FLASH_Success API was executed successfully; the flash property was stored to value.
 * @retval #kStatus_FLASH_InvalidArgument An invalid argument is provided.
 * @retval #kStatus_FLASH_UnknownProperty An unknown property tag.
 */
flash_status_t FLASH_GetProperty(flash_config_t *config, flash_property_tag_t whichProperty, uint32_t *value);

/*@}*/

/*!
 * @name Erasing
 * @{
 */

/*!
 * @brief Erases the flash sectors encompassed by parameters passed into function.
 *
 * This function erases the appropriate number of flash sectors based on the
 * desired start address and length.
 *
 * @param config The pointer to the storage for the driver runtime state.
 * @param start The start address of the desired flash memory to be erased.
 *              The start address does not need to be sector-aligned but must be phrase-aligned (64 bits).
 * @param lengthInBytes The length, given in bytes (not words or long-words)
 *                      to be erased. Must be phrase-aligned (64 bits).
 * @param key The value used to validate all flash erase APIs. Use kFLASH_ApiEraseKey here.
 *
 * @retval #kStatus_FLASH_Success API was executed successfully.
 * @retval #kStatus_FLASH_InvalidArgument An invalid argument is provided.
 * @retval #kStatus_FLASH_AlignmentError The parameter is not aligned with the specified baseline.
 * @retval #kStatus_FLASH_AddressError The address is out of range.
 * @retval #kStatus_FLASH_EraseKeyError The API erase key is invalid.
 * @retval #kStatus_FLASH_AccessError Invalid instruction codes and out-of bounds addresses.
 * @retval #kStatus_FLASH_ProtectionViolation The program/erase operation is requested to execute on protected areas.
 * @retval #kStatus_FLASH_CommandFailure Run-time error during the command execution.
 */
flash_status_t FLASH_Erase(flash_config_t *config, uint32_t start, uint32_t lengthInBytes, uint32_t key);

/*!
 * @brief Erases entire flash, after done flash is on security status
 *
 * @param config Pointer to the storage for the driver runtime state.
 * @param key A value used to validate all flash erase APIs. Use kFLASH_ApiEraseKey here.
 *
 * @retval #kStatus_FLASH_Success API was executed successfully.
 * @retval #kStatus_FLASH_InvalidArgument An invalid argument is provided.
 * @retval #kStatus_FLASH_EraseKeyError API erase key is invalid.
 * @retval #kStatus_FLASH_AccessError Invalid instruction codes and out-of bounds addresses.
 * @retval #kStatus_FLASH_ProtectionViolation The program/erase operation is requested to execute on protected areas.
 * @retval #kStatus_FLASH_CommandFailure Run-time error during command execution.
 */
flash_status_t FLASH_EraseAll(flash_config_t *config, uint32_t key);

/*!
 * @brief Erases the entire flash, after done flash is on unsecurity status
 *
 * @param config Pointer to the storage for the driver runtime state.
 * @param key A value used to validate all flash erase APIs. Use kFLASH_ApiEraseKey here.
 *
 * @retval #kStatus_FLASH_Success API was executed successfully.
 * @retval #kStatus_FLASH_InvalidArgument An invalid argument is provided.
 * @retval #kStatus_FLASH_EraseKeyError API erase key is invalid.
 * @retval #kStatus_FLASH_AccessError Invalid instruction codes and out-of bounds addresses.
 * @retval #kStatus_FLASH_ProtectionViolation The program/erase operation is requested to execute on protected areas.
 * @retval #kStatus_FLASH_CommandFailure Run-time error during command execution.
 */
flash_status_t FLASH_EraseAllUnsecure(flash_config_t *config, uint32_t key);

/*@}*/

/*!
 * @name Programming
 * @{
 */

/*!
 * @brief Programs flash with data at locations passed in through parameters via the Program Section command.
 *
 * This function programs the flash memory with the desired data for a given
 * flash area as determined by the start address and length.
 *
 * @param config A pointer to the storage for the driver runtime state.
 * @param start The start address of the desired flash memory to be programmed. Must be
 *              phrase-aligned (64 bits).
 * @param src A pointer to the source buffer of data that is to be programmed
 *            into the flash.
 * @param lengthInBytes The length, given in bytes (not words or long-words),
 *                      to be programmed. Must be phrase-aligned (64 bits).
 *
 * @retval #kStatus_FLASH_Success API was executed successfully.
 * @retval #kStatus_FLASH_InvalidArgument An invalid argument is provided.
 * @retval #kStatus_FLASH_AlignmentError Parameter is not aligned with specified baseline.
 * @retval #kStatus_FLASH_AddressError Address is out of range.
 * @retval #kStatus_FLASH_AccessError Invalid instruction codes and out-of bounds addresses.
 * @retval #kStatus_FLASH_ProtectionViolation The program/erase operation is requested to execute on protected areas.
 * @retval #kStatus_FLASH_CommandFailure Run-time error during command execution.
 */
flash_status_t FLASH_Program(flash_config_t *config, uint32_t start, uint8_t *src, uint32_t lengthInBytes);

/*!
 * @brief Programs Program Once Field through parameters.
 *
 * This function programs the Program Once Field with the desired data for a given
 * flash area as determined by the index and length.
 *
 * @param config A pointer to the storage for the driver runtime state.
 * @param index The index indicating which area of the Program Once Field to be programmed.Index is 0~7.
 * @param src A pointer to the source buffer of data that is to be programmed
 *            into the Program Once Field.
 * @param lengthInBytes The length, given in bytes (not words or long-words),
 *                      to be programmed. Must be phrase-aligned (64 bits). This value is ignored, it's always 8 bytes
 * that are written into specified IFR area.
 *
 * @retval #kStatus_FLASH_Success API was executed successfully.
 * @retval #kStatus_FLASH_InvalidArgument An invalid argument is provided.
 * @retval #kStatus_FLASH_AccessError Invalid instruction codes and out-of bounds addresses.
 * @retval #kStatus_FLASH_ProtectionViolation The program/erase operation is requested to execute on protected areas.
 * @retval #kStatus_FLASH_CommandFailure Run-time error during the command execution.
 */
flash_status_t FLASH_ProgramOnce(ftfx_config_t *config, uint32_t index, uint8_t *src, uint32_t lengthInBytes);

/*@}*/

/*!
 * @name Verification
 * @{
 */

/*!
 * @brief Verifies an erasure of the desired flash area at a specified margin level.
 *
 * This function checks the appropriate number of flash sectors based on
 * the desired start address and length to check whether the flash is erased
 * to the specified read margin level.
 *
 * @param config A pointer to the storage for the driver runtime state.
 * @param start The start address of the desired flash memory to be verified.
 *        The start address does not need to be sector-aligned but must be phrase-aligned (64 bits).
 * @param lengthInBytes The length, given in bytes (not words or long-words),
 *        to be verified. Must be phrase-aligned (64 bits).
 * @param margin Read margin choice. Choose from the members in flash_margin_value_t.
 *
 * @retval #kStatus_FLASH_Success API was executed successfully.
 * @retval #kStatus_FLASH_InvalidArgument An invalid argument is provided.
 * @retval #kStatus_FLASH_AlignmentError Parameter is not aligned with specified baseline.
 * @retval #kStatus_FLASH_AddressError Address is out of range.
 * @retval #kStatus_FLASH_AccessError Invalid instruction codes and out-of bounds addresses.
 * @retval #kStatus_FLASH_ProtectionViolation The program/erase operation is requested to execute on protected areas.
 * @retval #kStatus_FLASH_CommandFailure Run-time error during the command execution.
 */
flash_status_t FLASH_VerifyErase(flash_config_t *config,
                                 uint32_t start,
                                 uint32_t lengthInBytes,
                                 flash_margin_value_t margin);

/*!
 * @brief Verifies erasure of the entire flash at a specified margin level.
 *
 * This function checks whether the flash is erased to the
 * specified read margin level.
 *
 * @param config A pointer to the storage for the driver runtime state.
 * @param margin Read margin choice. Choose from the members in flash_margin_value_t.
 *
 * @retval #kStatus_FLASH_Success API was executed successfully.
 * @retval #kStatus_FLASH_InvalidArgument An invalid argument is provided.
 * @retval #kStatus_FLASH_AccessError Invalid instruction codes and out-of bounds addresses.
 * @retval #kStatus_FLASH_ProtectionViolation The program/erase operation is requested to execute on protected areas.
 * @retval #kStatus_FLASH_CommandFailure Run-time error during the command execution.
 */
flash_status_t FLASH_VerifyEraseAll(flash_config_t *config, flash_margin_value_t margin);

/*!
 * @brief Verifies programming of the desired flash area at a specified margin level.
 *
 * This function verifies the data programed in the flash memory using the
 * Flash Program Check Command and compares it to the expected data for a given
 * flash area as determined by the start address and length.
 *
 * @param config A pointer to the storage for the driver runtime state.
 * @param start The start address of the desired flash memory to be verified. Must be longword-aligned (32 bits).
 * @param lengthInBytes The length, given in bytes (not words or long-words),
 *        to be verified. Must be longword-aligned (32 bits).
 * @param expectedData A pointer to the expected data that is to be
 *        verified against.
 * @param margin Read margin choice. Choose from the members in flash_margin_value_t. "kFLASH_MarginValueNormal" is not
 * for this command.
 * @param failedAddress A pointer to the returned failing address, which is used by PGMCHK command. So it's always
 * longword-aligned.
 * @param failedData A pointer to the returned failing data.  Some derivatives do
 *        not include failed data as part of the FCCOBx registers.  In this
 *        case, zeros are returned upon failure.
 *
 * @retval #kStatus_FLASH_Success API was executed successfully.
 * @retval #kStatus_FLASH_InvalidArgument An invalid argument is provided.
 * @retval #kStatus_FLASH_AlignmentError Parameter is not aligned with specified baseline.
 * @retval #kStatus_FLASH_AddressError Address is out of range.
 * @retval #kStatus_FLASH_AccessError Invalid instruction codes and out-of bounds addresses.
 * @retval #kStatus_FLASH_ProtectionViolation The program/erase operation is requested to execute on protected areas.
 * @retval #kStatus_FLASH_CommandFailure Run-time error during the command execution.
 */
flash_status_t FLASH_VerifyProgram(flash_config_t *config,
                                   uint32_t start,
                                   uint32_t lengthInBytes,
                                   const uint8_t *expectedData,
                                   flash_margin_value_t margin,
                                   uint32_t *failedAddress,
                                   uint32_t *failedData);

/*@}*/

/*!
 * @name Security
 * @{
 */

/*!
 * @brief Returns the security state via the pointer passed into the function.
 *
 * This function retrieves the current flash security status, including the
 * security enabling state and the backdoor key enabling state.
 *
 * @param config A pointer to storage for the driver runtime state.
 * @param state A pointer to the value returned for the current security status code: one of the members in
 * flash_security_state_t.
 *
 * @retval #kStatus_FLASH_Success API was executed successfully.
 * @retval #kStatus_FLASH_InvalidArgument An invalid argument is provided.
 */
flash_status_t FLASH_GetSecurityState(flash_config_t *config, flash_security_state_t *state);

/*!
 * @brief Allows users to bypass security with a backdoor key.
 *
 * If the MCU is in secured state, this function unsecures the MCU by
 * comparing the provided backdoor key with ones in the flash configuration
 * field.
 *
 * @param config A pointer to the storage for the driver runtime state.
 * @param backdoorKey A pointer to the user buffer containing the backdoor key.
 *
 * @retval #kStatus_FLASH_Success API was executed successfully.
 * @retval #kStatus_FLASH_InvalidArgument An invalid argument is provided.
 * @retval #kStatus_FLASH_AccessError Invalid instruction codes and out-of bounds addresses.
 * @retval #kStatus_FLASH_ProtectionViolation The program/erase operation is requested to execute on protected areas.
 * @retval #kStatus_FLASH_CommandFailure Run-time error during the command execution.
 */
flash_status_t FLASH_SecurityBypass(flash_config_t *config, const uint8_t *backdoorKey);

/*@}*/

/*!
 * @name Reading
 * @{
 */

/*!
 * @brief Reads the Program Once Field through parameters.
 *
 * This function reads the read once feild with given index and length.
 *
 * @param config A pointer to the storage for the driver runtime state.
 * @param index The index indicating the area of program once field to be read. Index is 0~7.
 * @param dst A pointer to the destination buffer of data that is used to store
 *        data to be read.
 * @param lengthInBytes The length, given in bytes (not words or long-words),
 *        to be programmed. This value is ignored, it's always 8 bytes that are read out from the specified IFR area.
 *
 * @retval #kStatus_FLASH_Success API was executed successfully.
 * @retval #kStatus_FLASH_InvalidArgument An invalid argument is provided.
 * @retval #kStatus_FLASH_AccessError Invalid instruction codes and out-of bounds addresses.
 * @retval #kStatus_FLASH_ProtectionViolation The program/erase operation is requested to execute on protected areas.
 * @retval #kStatus_FLASH_CommandFailure Run-time error during the command execution.
 */
flash_status_t FLASH_ReadOnce(ftfx_config_t *config, uint32_t index, uint8_t *dst, uint32_t lengthInBytes);

/*!
 * @brief Reads the resource with data at locations passed in through parameters.
 *
 * This function reads the flash memory with the desired location for a given
 * flash area as determined by the start address and length.
 *
 * @param config A pointer to the storage for the driver runtime state.
 * @param start The start address of the desired flash memory resource to be read. Must be
 *              phrase-aligned (64 bits).
 * @param dst A pointer to the destination buffer of data that is used to store
 *        data to be read.
 * @param lengthInBytes The length, given in bytes (not words or long-words),
 *        to be read. Must be phrase-aligned (64 bits). When option is "kFLASH_ResourceOptionFlashIfr", lengthInBytes
 * can't be larger than 64. When option is "kFLASH_ResourceOptionVersionId", lengthInBytes should be set to 8.
 * @param option The resource option which indicates which area should be read back. Choose from
 * "kFLASH_ResourceOptionFlashIfr" and "kFLASH_ResourceOptionVersionId".
 *
 * @retval #kStatus_FLASH_Success API was executed successfully.
 * @retval #kStatus_FLASH_InvalidArgument An invalid argument is provided.
 * @retval #kStatus_FLASH_AlignmentError Parameter is not aligned with the specified baseline.
 * @retval #kStatus_FLASH_AccessError Invalid instruction codes and out-of bounds addresses.
 * @retval #kStatus_FLASH_ProtectionViolation The program/erase operation is requested to execute on protected areas.
 * @retval #kStatus_FLASH_CommandFailure Run-time error during the command execution.
 */
flash_status_t FLASH_ReadResource(
    flash_config_t *config, uint32_t start, uint8_t *dst, uint32_t lengthInBytes, flash_read_resource_opt_t option);

/*@}*/

/*!
 * @name Swap
 * @{
 */

/*!
 * @brief Swaps the lower half flash with the higher half flash.
 *
 * @param config A pointer to the storage for the driver runtime state.
 * @param address Address used to configure the flash swap function
 * @param isSetEnable The possible option used to configure the Flash Swap function or check the flash Swap status.
 *
 * @retval #kStatus_FLASH_Success API was executed successfully.
 * @retval #kStatus_FLASH_InvalidArgument An invalid argument is provided.
 * @retval #kStatus_FLASH_AlignmentError Parameter is not aligned with specified baseline.
 * @retval #kStatus_FLASH_SwapIndicatorAddressError Swap indicator address is invalid.
 * @retval #kStatus_FLASH_AccessError Invalid instruction codes and out-of bounds addresses.
 * @retval #kStatus_FLASH_ProtectionViolation The program/erase operation is requested to execute on protected areas.
 * @retval #kStatus_FLASH_CommandFailure Run-time error during command execution.
 * @retval #kStatus_FLASH_SwapSystemNotInUninitialized Swap system is not in an uninitialzed state.
 */
flash_status_t FLASH_Swap(flash_config_t *config, uint32_t address, uint8_t isSetEnable);

/*@}*/

#if defined(__cplusplus)
}
#endif

/*! @}*/

#endif /* FSL_FLASHIAP_H */
