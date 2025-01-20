/*
 * Copyright 2013-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2021 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "fsl_ftfx_controller.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*!
 * @name Flash controller command numbers
 * @{
 */
#define FTFx_VERIFY_BLOCK                    0x00U /*!< RD1BLK*/
#define FTFx_VERIFY_SECTION                  0x01U /*!< RD1SEC*/
#define FTFx_PROGRAM_CHECK                   0x02U /*!< PGMCHK*/
#define FTFx_READ_RESOURCE                   0x03U /*!< RDRSRC*/
#define FTFx_PROGRAM_LONGWORD                0x06U /*!< PGM4*/
#define FTFx_PROGRAM_PHRASE                  0x07U /*!< PGM8*/
#define FTFx_ERASE_BLOCK                     0x08U /*!< ERSBLK*/
#define FTFx_ERASE_SECTOR                    0x09U /*!< ERSSCR*/
#define FTFx_PROGRAM_SECTION                 0x0BU /*!< PGMSEC*/
#define FTFx_GENERATE_CRC                    0x0CU /*!< CRCGEN*/
#define FTFx_VERIFY_ALL_BLOCK                0x40U /*!< RD1ALL*/
#define FTFx_READ_ONCE                       0x41U /*!< RDONCE or RDINDEX*/
#define FTFx_PROGRAM_ONCE                    0x43U /*!< PGMONCE or PGMINDEX*/
#define FTFx_ERASE_ALL_BLOCK                 0x44U /*!< ERSALL*/
#define FTFx_SECURITY_BY_PASS                0x45U /*!< VFYKEY*/
#define FTFx_SWAP_CONTROL                    0x46U /*!< SWAP*/
#define FTFx_ERASE_ALL_BLOCK_UNSECURE        0x49U /*!< ERSALLU*/
#define FTFx_VERIFY_ALL_EXECUTE_ONLY_SEGMENT 0x4AU /*!< RD1XA*/
#define FTFx_ERASE_ALL_EXECUTE_ONLY_SEGMENT  0x4BU /*!< ERSXA*/
#define FTFx_PROGRAM_PARTITION               0x80U /*!< PGMPART*/
#define FTFx_SET_FLEXRAM_FUNCTION            0x81U /*!< SETRAM*/
/*@}*/

/*!
 * @brief Constants for execute-in-RAM flash function.
 */
enum _ftfx_ram_func_constants
{
    kFTFx_RamFuncMaxSizeInWords = 16U, /*!< The maximum size of execute-in-RAM function.*/
};

/*! @brief A function pointer used to point to relocated flash_run_command() */
typedef void (*callFtfxRunCommand_t)(FTFx_REG8_ACCESS_TYPE ftfx_fstat);

/*!
 * @name Enumeration for Flash security register code
 * @{
 */
enum _ftfx_fsec_register_code
{
    kFTFx_FsecRegCode_KEYEN_Enabled = 0x80U,
    kFTFx_FsecRegCode_SEC_Unsecured = 0x02U
};
/*@}*/

#if defined(FSL_FEATURE_FLASH_HAS_SWAP_CONTROL_CMD) && FSL_FEATURE_FLASH_HAS_SWAP_CONTROL_CMD
/*!
 * @brief Enumeration for flash config area.
 */
enum _ftfx_pflash_config_area_range
{
    kFTFx_PflashConfigAreaStart = 0x400U,
    kFTFx_PflashConfigAreaEnd   = 0x40FU
};
#endif /* FSL_FEATURE_FLASH_HAS_SWAP_CONTROL_CMD */

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*! @brief Init IFR memory related info */
static void ftfx_init_ifr(ftfx_config_t *config);

/*! @brief Internal function Flash command sequence. Called by driver APIs only*/
static status_t ftfx_command_sequence(ftfx_config_t *config);

/*! @brief Validates the range and alignment of the given address range.*/
static status_t ftfx_check_mem_range(ftfx_config_t *config,
                                     uint32_t startAddress,
                                     uint32_t lengthInBytes,
                                     uint8_t alignmentBaseline);

/*! @brief Validates the given user key for flash erase APIs.*/
static status_t ftfx_check_user_key(uint32_t key);

#if defined(FSL_FEATURE_FLASH_HAS_READ_RESOURCE_CMD) && FSL_FEATURE_FLASH_HAS_READ_RESOURCE_CMD
/*! @brief Validates the range of the given resource address.*/
static status_t ftfx_check_resource_range(
    ftfx_config_t *config, uint32_t start, uint32_t lengthInBytes, uint32_t alignmentBaseline, uint8_t option);
#endif /* FSL_FEATURE_FLASH_HAS_READ_RESOURCE_CMD */

#if defined(FTFx_DRIVER_IS_FLASH_RESIDENT) && (FTFx_DRIVER_IS_FLASH_RESIDENT > 0U)
void flash_run_command(void);
#endif /* FTFx_DRIVER_IS_FLASH_RESIDENT */
/*******************************************************************************
 * Variables
 ******************************************************************************/

#if FTFx_DRIVER_IS_FLASH_RESIDENT
#pragma section CODES_IN_RAM begin
void flash_run_command(void)
{
    /* clear RDCOLERR & ACCERR & FPVIOL flag in flash status register */
    FTFx->FSTAT = FTFx_FSTAT_RDCOLERR_MASK | FTFx_FSTAT_ACCERR_MASK | FTFx_FSTAT_FPVIOL_MASK;

    /* clear CCIF bit */
    FTFx->FSTAT = FTFx_FSTAT_CCIF_MASK;

    /* Check CCIF bit of the flash status register, wait till it is set.
     * IP team indicates that this loop will always complete. */
    while ((FTFx->FSTAT & FTFx_FSTAT_CCIF_MASK) == 0U)
    {
    }
}
#pragma section CODES_IN_RAM end
#endif /* FTFx_DRIVER_IS_FLASH_RESIDENT */

#if defined(FSL_FEATURE_FLASH_HAS_FLEX_NVM) && FSL_FEATURE_FLASH_HAS_FLEX_NVM
/*! @brief Table of eeprom sizes. */
static const uint16_t kEepromDensities[16] = {
    FSL_FEATURE_FLASH_FLEX_NVM_EEPROM_SIZE_FOR_EEESIZE_0000, FSL_FEATURE_FLASH_FLEX_NVM_EEPROM_SIZE_FOR_EEESIZE_0001,
    FSL_FEATURE_FLASH_FLEX_NVM_EEPROM_SIZE_FOR_EEESIZE_0010, FSL_FEATURE_FLASH_FLEX_NVM_EEPROM_SIZE_FOR_EEESIZE_0011,
    FSL_FEATURE_FLASH_FLEX_NVM_EEPROM_SIZE_FOR_EEESIZE_0100, FSL_FEATURE_FLASH_FLEX_NVM_EEPROM_SIZE_FOR_EEESIZE_0101,
    FSL_FEATURE_FLASH_FLEX_NVM_EEPROM_SIZE_FOR_EEESIZE_0110, FSL_FEATURE_FLASH_FLEX_NVM_EEPROM_SIZE_FOR_EEESIZE_0111,
    FSL_FEATURE_FLASH_FLEX_NVM_EEPROM_SIZE_FOR_EEESIZE_1000, FSL_FEATURE_FLASH_FLEX_NVM_EEPROM_SIZE_FOR_EEESIZE_1001,
    FSL_FEATURE_FLASH_FLEX_NVM_EEPROM_SIZE_FOR_EEESIZE_1010, FSL_FEATURE_FLASH_FLEX_NVM_EEPROM_SIZE_FOR_EEESIZE_1011,
    FSL_FEATURE_FLASH_FLEX_NVM_EEPROM_SIZE_FOR_EEESIZE_1100, FSL_FEATURE_FLASH_FLEX_NVM_EEPROM_SIZE_FOR_EEESIZE_1101,
    FSL_FEATURE_FLASH_FLEX_NVM_EEPROM_SIZE_FOR_EEESIZE_1110, FSL_FEATURE_FLASH_FLEX_NVM_EEPROM_SIZE_FOR_EEESIZE_1111};
/*! @brief Table of dflash sizes. */
static const uint32_t kDflashDensities[16] = {
    FSL_FEATURE_FLASH_FLEX_NVM_DFLASH_SIZE_FOR_DEPART_0000, FSL_FEATURE_FLASH_FLEX_NVM_DFLASH_SIZE_FOR_DEPART_0001,
    FSL_FEATURE_FLASH_FLEX_NVM_DFLASH_SIZE_FOR_DEPART_0010, FSL_FEATURE_FLASH_FLEX_NVM_DFLASH_SIZE_FOR_DEPART_0011,
    FSL_FEATURE_FLASH_FLEX_NVM_DFLASH_SIZE_FOR_DEPART_0100, FSL_FEATURE_FLASH_FLEX_NVM_DFLASH_SIZE_FOR_DEPART_0101,
    FSL_FEATURE_FLASH_FLEX_NVM_DFLASH_SIZE_FOR_DEPART_0110, FSL_FEATURE_FLASH_FLEX_NVM_DFLASH_SIZE_FOR_DEPART_0111,
    FSL_FEATURE_FLASH_FLEX_NVM_DFLASH_SIZE_FOR_DEPART_1000, FSL_FEATURE_FLASH_FLEX_NVM_DFLASH_SIZE_FOR_DEPART_1001,
    FSL_FEATURE_FLASH_FLEX_NVM_DFLASH_SIZE_FOR_DEPART_1010, FSL_FEATURE_FLASH_FLEX_NVM_DFLASH_SIZE_FOR_DEPART_1011,
    FSL_FEATURE_FLASH_FLEX_NVM_DFLASH_SIZE_FOR_DEPART_1100, FSL_FEATURE_FLASH_FLEX_NVM_DFLASH_SIZE_FOR_DEPART_1101,
    FSL_FEATURE_FLASH_FLEX_NVM_DFLASH_SIZE_FOR_DEPART_1110, FSL_FEATURE_FLASH_FLEX_NVM_DFLASH_SIZE_FOR_DEPART_1111};
#endif /* FSL_FEATURE_FLASH_HAS_FLEX_NVM */

/*******************************************************************************
 * Code
 ******************************************************************************/

/*!
 * @brief Initializes the global flash properties structure members.
 */
void FTFx_API_Init(ftfx_config_t *config)
{
    if (config == NULL)
    {
        return;
    }
    config->runCmdFuncAddr.callFlashCommand = NULL;
    config->flexramBlockBase                = FSL_FEATURE_FLASH_FLEX_RAM_START_ADDRESS;
    config->flexramTotalSize                = FSL_FEATURE_FLASH_FLEX_RAM_SIZE;

    ftfx_init_ifr(config);
}

/*!
 * @brief Erases the flash sectors encompassed by parameters passed into function.
 */
status_t FTFx_CMD_Erase(ftfx_config_t *config, uint32_t start, uint32_t lengthInBytes, uint32_t key)
{
    uint32_t sectorSize;
    uint32_t endAddress;      /* storing end address */
    uint32_t numberOfSectors; /* number of sectors calculated by endAddress */
    status_t returnCode;
    uint32_t eraseStart = start;

    uint32_t fccob_byte;

    /* Check the supplied address range. */
    returnCode = ftfx_check_mem_range(config, eraseStart, lengthInBytes, config->opsConfig.addrAligment.sectorCmd);
    if (returnCode != kStatus_FTFx_Success)
    {
        return returnCode;
    }

    /* Validate the user key */
    returnCode = ftfx_check_user_key(key);
    if (returnCode != kStatus_FTFx_Success)
    {
        return returnCode;
    }

    eraseStart = config->opsConfig.convertedAddress;
    sectorSize = config->flashDesc.sectorSize;

    /* Calculate Flash end address */
    endAddress = eraseStart + lengthInBytes - 1U;

    /* re-calculate the endAddress and align it to the start of the next sector
     * which will be used in the comparison below */
    if (0U != (endAddress % sectorSize))
    {
        numberOfSectors = endAddress / sectorSize + 1U;
        endAddress      = numberOfSectors * sectorSize - 1U;
    }

    /* the start address will increment to the next sector address
     * until it reaches the endAdddress */
    while (eraseStart <= endAddress)
    {
        /* preparing passing parameter to erase a flash block */
        FTFx->FCCOB0 = FTFx_ERASE_SECTOR;
        fccob_byte   = eraseStart;
        FTFx->FCCOB3 = (uint8_t)(fccob_byte & 0xFFU);
        FTFx->FCCOB2 = (uint8_t)((fccob_byte >> 8U) & 0xFFU);
        FTFx->FCCOB1 = (uint8_t)((fccob_byte >> 16U) & 0xFFU);

        /* calling flash command sequence function to execute the command */
        returnCode = ftfx_command_sequence(config);

        /* checking the success of command execution */
        if (kStatus_FTFx_Success != returnCode)
        {
            break;
        }
        else
        {
            /* Increment to the next sector */
            eraseStart += sectorSize;
        }
    }

    return returnCode;
}

/*!
 * @brief Erases entire flash
 */
status_t FTFx_CMD_EraseAll(ftfx_config_t *config, uint32_t key)
{
    status_t returnCode;

    if (config == NULL)
    {
        return kStatus_FTFx_InvalidArgument;
    }

    /* preparing passing parameter to erase all flash blocks */
    FTFx->FCCOB0 = FTFx_ERASE_ALL_BLOCK;
    FTFx->FCCOB1 = 0xFFU;
    FTFx->FCCOB2 = 0xFFU;
    FTFx->FCCOB3 = 0xFFU;

    /* Validate the user key */
    returnCode = ftfx_check_user_key(key);
    if (kStatus_FTFx_Success != returnCode)
    {
        return returnCode;
    }

    /* calling flash command sequence function to execute the command */
    returnCode = ftfx_command_sequence(config);

#if defined(FSL_FEATURE_FLASH_HAS_FLEX_NVM) && FSL_FEATURE_FLASH_HAS_FLEX_NVM
    /* Data flash IFR will be erased by erase all command, so we need to
     *  update FlexNVM memory partition status synchronously */
    if (returnCode == kStatus_FTFx_Success)
    {
        if (config->ifrDesc.resRange.dflashIfrStart != config->ifrDesc.resRange.pflashIfrStart)
        {
            returnCode = FTFx_API_UpdateFlexnvmPartitionStatus(config);
        }
    }
#endif /* FSL_FEATURE_FLASH_HAS_FLEX_NVM */

    return returnCode;
}

#if defined(FSL_FEATURE_FLASH_HAS_ERASE_ALL_BLOCKS_UNSECURE_CMD) && FSL_FEATURE_FLASH_HAS_ERASE_ALL_BLOCKS_UNSECURE_CMD
/*!
 * @brief Erases the entire flash, including protected sectors.
 */
status_t FTFx_CMD_EraseAllUnsecure(ftfx_config_t *config, uint32_t key)
{
    status_t returnCode;

    if (config == NULL)
    {
        return kStatus_FTFx_InvalidArgument;
    }

    /* Prepare passing parameter to erase all flash blocks (unsecure). */
    FTFx->FCCOB0 = FTFx_ERASE_ALL_BLOCK_UNSECURE;
    FTFx->FCCOB1 = 0xFFU;
    FTFx->FCCOB2 = 0xFFU;
    FTFx->FCCOB3 = 0xFFU;

    /* Validate the user key */
    returnCode = ftfx_check_user_key(key);
    if (returnCode != kStatus_FTFx_Success)
    {
        return returnCode;
    }

    /* calling flash command sequence function to execute the command */
    returnCode = ftfx_command_sequence(config);

#if defined(FSL_FEATURE_FLASH_HAS_FLEX_NVM) && FSL_FEATURE_FLASH_HAS_FLEX_NVM
    /* Data flash IFR will be erased by erase all unsecure command, so we need to
     *  update FlexNVM memory partition status synchronously */
    if (returnCode == kStatus_FTFx_Success)
    {
        if (config->ifrDesc.resRange.dflashIfrStart != config->ifrDesc.resRange.pflashIfrStart)
        {
            returnCode = FTFx_API_UpdateFlexnvmPartitionStatus(config);
        }
    }
#endif /* FSL_FEATURE_FLASH_HAS_FLEX_NVM */

    return returnCode;
}
#endif /* FSL_FEATURE_FLASH_HAS_ERASE_ALL_BLOCKS_UNSECURE_CMD */

/*!
 * @brief Programs flash with data at locations passed in through parameters.
 */
status_t FTFx_CMD_Program(ftfx_config_t *config, uint32_t start, const uint8_t *src, uint32_t lengthInBytes)
{
    status_t returnCode;
    uint8_t blockWriteUnitSize = config->opsConfig.addrAligment.blockWriteUnitSize;
    uint32_t programStart;
    uint32_t remainingLength;
    uint32_t fccob_byte;

    if (src == NULL)
    {
        return kStatus_FTFx_InvalidArgument;
    }

    /* Check the supplied address range. */
    returnCode = ftfx_check_mem_range(config, start, lengthInBytes, blockWriteUnitSize);
    if (returnCode != kStatus_FTFx_Success)
    {
        return returnCode;
    }

    programStart    = config->opsConfig.convertedAddress;
    remainingLength = lengthInBytes;

    while (remainingLength > 0U)
    {
        /* preparing passing parameter to program the flash block */
        FTFx->FCCOB4 = src[0];
        FTFx->FCCOB5 = src[1];
        FTFx->FCCOB6 = src[2];
        FTFx->FCCOB7 = src[3];
        src          = &src[4];

        if (4U == blockWriteUnitSize)
        {
            FTFx->FCCOB0 = FTFx_PROGRAM_LONGWORD;
            fccob_byte   = programStart;
            FTFx->FCCOB3 = (uint8_t)(fccob_byte & 0xFFU);
            FTFx->FCCOB2 = (uint8_t)((fccob_byte >> 8U) & 0xFFU);
            FTFx->FCCOB1 = (uint8_t)((fccob_byte >> 16U) & 0xFFU);
        }
        else if (8U == blockWriteUnitSize)
        {
            src          = &src[4];
            FTFx->FCCOB4 = src[0];
            FTFx->FCCOB5 = src[1];
            FTFx->FCCOB6 = src[2];
            FTFx->FCCOB7 = src[3];
            FTFx->FCCOB0 = FTFx_PROGRAM_PHRASE;
            fccob_byte   = programStart;
            FTFx->FCCOB3 = (uint8_t)(fccob_byte & 0xFFU);
            FTFx->FCCOB2 = (uint8_t)((fccob_byte >> 8U) & 0xFFU);
            FTFx->FCCOB1 = (uint8_t)((fccob_byte >> 16U) & 0xFFU);
        }
        else
        {
            return kStatus_FTFx_InvalidArgument;
        }

        /* calling flash command sequence function to execute the command */
        returnCode = ftfx_command_sequence(config);

        /* checking for the success of command execution */
        if (kStatus_FTFx_Success != returnCode)
        {
            break;
        }
        else
        {
            /* update programStart address for next iteration */
            programStart += blockWriteUnitSize;

            /* update remainingLength for next iteration */
            remainingLength -= blockWriteUnitSize;
        }
    }

    return returnCode;
}

/*!
 * @brief Programs Program Once Field through parameters.
 */
status_t FTFx_CMD_ProgramOnce(ftfx_config_t *config, uint8_t index, const uint8_t *src, uint32_t lengthInBytes)
{
    status_t returnCode;

    if ((config == NULL) || (src == NULL))
    {
        return kStatus_FTFx_InvalidArgument;
    }

    /* pass parameters to FTFx */
    FTFx->FCCOB0 = FTFx_PROGRAM_ONCE;
    FTFx->FCCOB1 = index;
    FTFx->FCCOB2 = 0xFFU;
    FTFx->FCCOB3 = 0xFFU;

    FTFx->FCCOB4 = src[0];
    FTFx->FCCOB5 = src[1];
    FTFx->FCCOB6 = src[2];
    FTFx->FCCOB7 = src[3];
    src          = &src[4];

    /* Note: Have to separate the first index from the rest if it equals 0
     * to avoid a pointless comparison of unsigned int to 0 compiler warning */
    if (config->ifrDesc.feature.has8ByteIdxSupport != 0U)
    {
        if (config->ifrDesc.feature.has4ByteIdxSupport != 0U)
        {
            if (((index == config->ifrDesc.idxInfo.mix8byteIdxStart) ||
                 ((index >= (config->ifrDesc.idxInfo.mix8byteIdxStart + 1U)) &&
                  (index <= config->ifrDesc.idxInfo.mix8byteIdxEnd))) &&
                (lengthInBytes == 8U))
            {
                FTFx->FCCOB8 = src[0];
                FTFx->FCCOB9 = src[1];
                FTFx->FCCOBA = src[2];
                FTFx->FCCOBB = src[3];
            }
        }
        else
        {
            FTFx->FCCOB8 = src[0];
            FTFx->FCCOB9 = src[1];
            FTFx->FCCOBA = src[2];
            FTFx->FCCOBB = src[3];
        }
    }

    /* calling flash command sequence function to execute the command */
    returnCode = ftfx_command_sequence(config);

    return returnCode;
}

/*!
 * @brief Reads the Program Once Field through parameters.
 */
status_t FTFx_CMD_ReadOnce(ftfx_config_t *config, uint8_t index, uint8_t *dst, uint32_t lengthInBytes)
{
    status_t returnCode;

    if ((config == NULL) || (dst == NULL))
    {
        return kStatus_FTFx_InvalidArgument;
    }

    /* pass parameters to FTFx */
    FTFx->FCCOB0 = FTFx_READ_ONCE;
    FTFx->FCCOB1 = index;
    FTFx->FCCOB2 = 0xFFU;
    FTFx->FCCOB3 = 0xFFU;

    /* calling flash command sequence function to execute the command */
    returnCode = ftfx_command_sequence(config);

    if (returnCode == kStatus_FTFx_Success)
    {
        dst[0] = FTFx->FCCOB4;
        dst[1] = FTFx->FCCOB5;
        dst[2] = FTFx->FCCOB6;
        dst[3] = FTFx->FCCOB7;
        dst    = &dst[4];

        /* Note: Have to separate the first index from the rest if it equals 0
         *       to avoid a pointless comparison of unsigned int to 0 compiler warning */
        if (config->ifrDesc.feature.has8ByteIdxSupport != 0U)
        {
            if (config->ifrDesc.feature.has4ByteIdxSupport != 0U)
            {
                if (((index == config->ifrDesc.idxInfo.mix8byteIdxStart) ||
                     ((index >= (config->ifrDesc.idxInfo.mix8byteIdxStart + 1U)) &&
                      (index <= config->ifrDesc.idxInfo.mix8byteIdxEnd))) &&
                    (lengthInBytes == 8U))
                {
                    dst[0] = FTFx->FCCOB8;
                    dst[1] = FTFx->FCCOB9;
                    dst[2] = FTFx->FCCOBA;
                    dst[3] = FTFx->FCCOBB;
                    dst    = &dst[4];
                }
            }
            else
            {
                dst[0] = FTFx->FCCOB8;
                dst[1] = FTFx->FCCOB9;
                dst[2] = FTFx->FCCOBA;
                dst[3] = FTFx->FCCOBB;
                dst    = &dst[4];
            }
        }
    }

    return returnCode;
}

#if defined(FSL_FEATURE_FLASH_HAS_READ_RESOURCE_CMD) && FSL_FEATURE_FLASH_HAS_READ_RESOURCE_CMD
/*!
 * @brief Reads the resource with data at locations passed in through parameters.
 *
 * this function can read  date from  program flash IFR, data flash IFR space,
 * and the Version ID field.
 */
status_t FTFx_CMD_ReadResource(
    ftfx_config_t *config, uint32_t start, uint8_t *dst, uint32_t lengthInBytes, uint8_t option)
{
    status_t returnCode;
    uint32_t readstart;
    uint32_t fccob_byte;

    uint8_t *destaddress;
    uint32_t readlengthBytes;
    readstart       = start;
    destaddress     = dst;
    readlengthBytes = lengthInBytes;
    if ((config == NULL) || (dst == NULL))
    {
        return kStatus_FTFx_InvalidArgument;
    }

    uint8_t aligmentInBytes = config->opsConfig.addrAligment.resourceCmd;

    /* Check the supplied address range. */
    returnCode = ftfx_check_resource_range(config, readstart, readlengthBytes, aligmentInBytes, option);
    if (returnCode != kStatus_FTFx_Success)
    {
        return returnCode;
    }

    while (readlengthBytes > 0U)
    {
        FTFx->FCCOB0 = FTFx_READ_RESOURCE;
        fccob_byte   = readstart;
        FTFx->FCCOB3 = (uint8_t)(fccob_byte & 0xFFU);
        FTFx->FCCOB2 = (uint8_t)((fccob_byte >> 8U) & 0xFFU);
        FTFx->FCCOB1 = (uint8_t)((fccob_byte >> 16U) & 0xFFU);

        if (aligmentInBytes == 4U)
        {
            FTFx->FCCOB8 = option;
            FTFx->FCCOB9 = 0xFFU;
            FTFx->FCCOBA = 0xFFU;
            FTFx->FCCOBB = 0xFFU;
        }
        else if (aligmentInBytes == 8U)
        {
            FTFx->FCCOB4 = option;
            FTFx->FCCOB5 = 0xFFU;
            FTFx->FCCOB6 = 0xFFU;
            FTFx->FCCOB7 = 0xFFU;
        }
        else
        {
            return kStatus_FTFx_InvalidArgument;
        }

        /* calling flash command sequence function to execute the command */
        returnCode = ftfx_command_sequence(config);

        if (kStatus_FTFx_Success != returnCode)
        {
            break;
        }

        /* fetch data */
        dst[0] = FTFx->FCCOB4;
        dst[1] = FTFx->FCCOB5;
        dst[2] = FTFx->FCCOB6;
        dst[3] = FTFx->FCCOB7;
        dst    = &dst[4];
        if (aligmentInBytes == 8U)
        {
            dst[0] = FTFx->FCCOB8;
            dst[1] = FTFx->FCCOB9;
            dst[2] = FTFx->FCCOBA;
            dst[3] = FTFx->FCCOBB;
            dst    = &dst[4];
        }
        /* update readstart address for next iteration */
        readstart += aligmentInBytes;
        /* update readlengthBytes for next iteration */
        readlengthBytes -= aligmentInBytes;
    }

    return (returnCode);
}
#endif /* FSL_FEATURE_FLASH_HAS_READ_RESOURCE_CMD */

/*!
 * @brief Verifies an erasure of the desired flash area at a specified margin level.
 *
 * This function checks the appropriate number of flash sectors based on
 * the desired start address and length to check whether the flash is erased
 * to the specified read margin level.
 */
status_t FTFx_CMD_VerifyErase(ftfx_config_t *config, uint32_t start, uint32_t lengthInBytes, uint8_t margin)
{
    /* Check arguments. */
    uint32_t blockSize;
    uint32_t nextBlockStartAddress;
    uint32_t fccob_byte;

    uint32_t remainingBytes;
    uint8_t aligmentInBytes = config->opsConfig.addrAligment.sectionCmd;
    status_t returnCode;
    uint32_t erasestart;

    /* Validates the range and alignment of the given address range.*/
    returnCode = ftfx_check_mem_range(config, start, lengthInBytes, aligmentInBytes);
    if (kStatus_FTFx_Success != returnCode)
    {
        return returnCode;
    }

    erasestart = config->opsConfig.convertedAddress;
    blockSize  = config->flashDesc.totalSize / config->flashDesc.blockCount;

    /* Calculate the next block start address */
    nextBlockStartAddress = ALIGN_UP(erasestart, blockSize);

    if (nextBlockStartAddress == erasestart)
    {
        nextBlockStartAddress += blockSize;
    }

    remainingBytes = lengthInBytes;

    while (0U != remainingBytes)
    {
        uint32_t numberOfPhrases;

        uint32_t verifyLength = nextBlockStartAddress - erasestart;
        /* Calculate the size to be verified, this flash does not support erase and program across block. */
        if (verifyLength > remainingBytes)
        {
            verifyLength = remainingBytes;
        }

        /* Calculate the number of phrases to be verified */
        numberOfPhrases = verifyLength / aligmentInBytes;

        /* Fill in verify section command parameters. */
        FTFx->FCCOB0 = FTFx_VERIFY_SECTION;
        fccob_byte   = erasestart;
        FTFx->FCCOB3 = (uint8_t)(fccob_byte & 0xFFU);
        FTFx->FCCOB2 = (uint8_t)((fccob_byte >> 8U) & 0xFFU);
        FTFx->FCCOB1 = (uint8_t)((fccob_byte >> 16U) & 0xFFU);

        FTFx->FCCOB5 = (uint8_t)(numberOfPhrases & 0xFFU);
        FTFx->FCCOB4 = (uint8_t)((numberOfPhrases >> 8U) & 0xFFU);
        FTFx->FCCOB6 = margin;

        /* calling flash command sequence function to execute the command */
        returnCode = ftfx_command_sequence(config);
        if (kStatus_FTFx_Success != returnCode)
        {
            return returnCode;
        }

        remainingBytes -= verifyLength;
        erasestart += verifyLength;
        nextBlockStartAddress += blockSize;
    }

    return kStatus_FTFx_Success;
}

/*!
 * @brief Verifies erasure of the entire flash at a specified margin level.
 */
status_t FTFx_CMD_VerifyEraseAll(ftfx_config_t *config, uint8_t margin)
{
    if (config == NULL)
    {
        return kStatus_FTFx_InvalidArgument;
    }

    /* preparing passing parameter to verify all block command */
    FTFx->FCCOB0 = FTFx_VERIFY_ALL_BLOCK;
    FTFx->FCCOB1 = margin;
    FTFx->FCCOB2 = 0xFFU;
    FTFx->FCCOB3 = 0xFFU;

    /* calling flash command sequence function to execute the command */
    return ftfx_command_sequence(config);
}

/*!
 * @brief Verifies programming of the desired flash area at a specified margin level.
 *
 * This function verifies the data programed in the flash memory using the
 * Flash Program Check Command and compares it to the expected data for a given
 * flash area as determined by the start address and length.
 */
status_t FTFx_CMD_VerifyProgram(ftfx_config_t *config,
                                uint32_t start,
                                uint32_t lengthInBytes,
                                const uint8_t *expectedData,
                                uint8_t margin,
                                uint32_t *failedAddress,
                                uint32_t *failedData)
{
    status_t returnCode;
    uint8_t aligmentInBytes = config->opsConfig.addrAligment.checkCmd;
    uint32_t programstart;
    uint32_t programlength;

    uint32_t fccob_byte;

    programlength = lengthInBytes;
    if (expectedData == NULL)
    {
        return kStatus_FTFx_InvalidArgument;
    }

    /* Validates the range and alignment of the given address range */
    returnCode = ftfx_check_mem_range(config, start, lengthInBytes, aligmentInBytes);
    if (kStatus_FTFx_Success != returnCode)
    {
        return returnCode;
    }

    programstart = config->opsConfig.convertedAddress;

    while (0U != programlength)
    {
        /* preparing passing parameter to program check the flash block */
        FTFx->FCCOB0 = FTFx_PROGRAM_CHECK;
        fccob_byte   = programstart;
        FTFx->FCCOB3 = (uint8_t)(fccob_byte & 0xFFU);
        FTFx->FCCOB2 = (uint8_t)((fccob_byte >> 8U) & 0xFFU);
        FTFx->FCCOB1 = (uint8_t)((fccob_byte >> 16U) & 0xFFU);

        FTFx->FCCOB4 = margin;
        FTFx->FCCOB5 = 0xFFU;
        FTFx->FCCOB6 = 0xFFU;
        FTFx->FCCOB7 = 0xFFU;

        FTFx->FCCOB8 = expectedData[0];
        FTFx->FCCOB9 = expectedData[1];
        FTFx->FCCOBA = expectedData[2];
        FTFx->FCCOBB = expectedData[3];

        /* calling flash command sequence function to execute the command */
        returnCode = ftfx_command_sequence(config);

        /* checking for the success of command execution */
        if (kStatus_FTFx_Success != returnCode)
        {
            if (failedAddress != NULL)
            {
                *failedAddress = programstart;
            }
            if (failedData != NULL)
            {
                *failedData = 0U;
            }
            break;
        }

        programlength -= aligmentInBytes;
        expectedData = &expectedData[aligmentInBytes];
        programstart += aligmentInBytes;
    }

    return (returnCode);
}

/*!
 * @brief Returns the security state via the pointer passed into the function.
 */
status_t FTFx_REG_GetSecurityState(ftfx_config_t *config, ftfx_security_state_t *state)
{
    /* store data read from flash register */
    uint8_t registerValue;
    if ((config == NULL) || (state == NULL))
    {
        return kStatus_FTFx_InvalidArgument;
    }

    /* Get flash security register value */
    registerValue = FTFx->FSEC;

    /* check the status of the flash security bits in the security register */
    if ((uint8_t)kFTFx_FsecRegCode_SEC_Unsecured == (registerValue & FTFx_FSEC_SEC_MASK))
    {
        /* Flash in unsecured state */
        *state = kFTFx_SecurityStateNotSecure;
    }
    else
    {
        /* Flash in secured state
         * check for backdoor key security enable bit */
        if ((uint8_t)kFTFx_FsecRegCode_KEYEN_Enabled == (registerValue & FTFx_FSEC_KEYEN_MASK))
        {
            /* Backdoor key security enabled */
            *state = kFTFx_SecurityStateBackdoorEnabled;
        }
        else
        {
            /* Backdoor key security disabled */
            *state = kFTFx_SecurityStateBackdoorDisabled;
        }
    }

    return kStatus_FTFx_Success;
}

static void ftfx_init_ifr(ftfx_config_t *config)
{
#if defined(FSL_FEATURE_FLASH_IS_FTFA) && FSL_FEATURE_FLASH_IS_FTFA
    /* FTFA parts(eg. K80, KL80, L5K) support both 4-bytes and 8-bytes unit size */
    config->ifrDesc.feature.has4ByteIdxSupport = 1U;
    config->ifrDesc.feature.has8ByteIdxSupport = 1U;
    config->ifrDesc.idxInfo.mix8byteIdxStart   = 0x10U;
    config->ifrDesc.idxInfo.mix8byteIdxEnd     = 0x13U;
#elif defined(FSL_FEATURE_FLASH_IS_FTFE) && FSL_FEATURE_FLASH_IS_FTFE
    /* FTFE parts(eg. K65, KE18) only support 8-bytes unit size */
    config->ifrDesc.feature.has4ByteIdxSupport = 0U;
    config->ifrDesc.feature.has8ByteIdxSupport = 1U;
#elif defined(FSL_FEATURE_FLASH_IS_FTFL) && FSL_FEATURE_FLASH_IS_FTFL
    /* FTFL parts(eg. K20) only support 4-bytes unit size */
    config->ifrDesc.feature.has4ByteIdxSupport = 1U;
    config->ifrDesc.feature.has8ByteIdxSupport = 0U;
#endif

    config->ifrDesc.resRange.pflashIfrStart = 0x0000U;
    config->ifrDesc.resRange.versionIdSize  = 0x08U;
#if defined(FSL_FEATURE_FLASH_IS_FTFE) && FSL_FEATURE_FLASH_IS_FTFE
    config->ifrDesc.resRange.versionIdStart = 0x08U;
    config->ifrDesc.resRange.ifrMemSize     = 0x0400U;
#else /* FSL_FEATURE_FLASH_IS_FTFL == 1 or FSL_FEATURE_FLASH_IS_FTFA = =1 */
    config->ifrDesc.resRange.versionIdStart    = 0x00U;
    config->ifrDesc.resRange.ifrMemSize        = 0x0100U;
#endif
}

/*!
 * @brief FTFx Command Sequence
 *
 * This function is used to perform the command write sequence to the flash.
 *
 * @param driver Pointer to storage for the driver runtime state.
 * @return An error code or kStatus_FTFx_Success
 */
static status_t ftfx_command_sequence(ftfx_config_t *config)
{
    uint8_t registerValue;

#if FTFx_DRIVER_IS_FLASH_RESIDENT

    flash_run_command();

#else
    /* clear RDCOLERR & ACCERR & FPVIOL flag in flash status register */
    FTFx->FSTAT = FTFx_FSTAT_RDCOLERR_MASK | FTFx_FSTAT_ACCERR_MASK | FTFx_FSTAT_FPVIOL_MASK;

    /* clear CCIF bit */
    FTFx->FSTAT = FTFx_FSTAT_CCIF_MASK;

    /* Check CCIF bit of the flash status register, wait till it is set.
     * IP team indicates that this loop will always complete. */
    while (!(FTFx->FSTAT & FTFx_FSTAT_CCIF_MASK))
    {
    }
#endif /* FTFx_DRIVER_IS_FLASH_RESIDENT */

    /* Check error bits */
    /* Get flash status register value */
    registerValue = FTFx->FSTAT;

    /* checking access error */
    if (0U != (registerValue & FTFx_FSTAT_ACCERR_MASK))
    {
        return kStatus_FTFx_AccessError;
    }
    /* checking protection error */
    else if (0U != (registerValue & FTFx_FSTAT_FPVIOL_MASK))
    {
        return kStatus_FTFx_ProtectionViolation;
    }
    /* checking MGSTAT0 non-correctable error */
    else if (0U != (registerValue & FTFx_FSTAT_MGSTAT0_MASK))
    {
        return kStatus_FTFx_CommandFailure;
    }
    else
    {
        return kStatus_FTFx_Success;
    }
}

/*! @brief Validates the range and alignment of the given address range.*/
static status_t ftfx_check_mem_range(ftfx_config_t *config,
                                     uint32_t startAddress,
                                     uint32_t lengthInBytes,
                                     uint8_t alignmentBaseline)
{
    status_t status = kStatus_FTFx_AddressError;

    /* Verify the start and length are alignmentBaseline aligned. */
    if ((0U != (startAddress & (uint8_t)(alignmentBaseline - 1U))) ||
        (0U != (lengthInBytes & (uint8_t)(alignmentBaseline - 1U))))
    {
        return kStatus_FTFx_AlignmentError;
    }

    /* check for valid range of the target addresses */
    if ((startAddress >= config->flashDesc.blockBase) &&
        ((startAddress + lengthInBytes) <= (config->flashDesc.blockBase + config->flashDesc.totalSize)))
    {
        status = kStatus_FTFx_Success;
    }
#if defined(FSL_FEATURE_FLASH_HAS_FLEX_NVM_ALIAS) && FSL_FEATURE_FLASH_HAS_FLEX_NVM_ALIAS
    else if ((startAddress >= config->flashDesc.aliasBlockBase) &&
             ((startAddress + lengthInBytes) <= (config->flashDesc.aliasBlockBase + config->flashDesc.totalSize)))
    {
        status = kStatus_FTFx_Success;
    }
    else
    {
        status = kStatus_FTFx_AddressError;
    }
#endif

    return status;
}

/*! @brief Validates the given user key for flash erase APIs.*/
static status_t ftfx_check_user_key(uint32_t key)
{
    /* Validate the user key */
    if (key != (uint32_t)kFTFx_ApiEraseKey)
    {
        return kStatus_FTFx_EraseKeyError;
    }

    return kStatus_FTFx_Success;
}

#if defined(FSL_FEATURE_FLASH_HAS_READ_RESOURCE_CMD) && FSL_FEATURE_FLASH_HAS_READ_RESOURCE_CMD
/*! @brief Validates the range of the given resource address.*/
static status_t ftfx_check_resource_range(
    ftfx_config_t *config, uint32_t start, uint32_t lengthInBytes, uint32_t alignmentBaseline, uint8_t option)
{
    status_t status;
    uint32_t maxReadbleAddress;

    if ((0U != (start & (alignmentBaseline - 1u))) || (0U != (lengthInBytes & (alignmentBaseline - 1u))))
    {
        return kStatus_FTFx_AlignmentError;
    }

    status = kStatus_FTFx_Success;

    maxReadbleAddress = start + lengthInBytes - 1u;
    /* read resource code from the version ID field */
    if (option == kFTFx_ResourceOptionVersionId)
    {
        if ((start != config->ifrDesc.resRange.versionIdStart) ||
            (lengthInBytes != config->ifrDesc.resRange.versionIdSize))
        {
            status = kStatus_FTFx_InvalidArgument;
        }
    }
    else if (option == kFTFx_ResourceOptionFlashIfr)
    {
        /* read resource code from the  program flash IFR space */
        if ((start >= config->ifrDesc.resRange.pflashIfrStart) &&
            (maxReadbleAddress < (config->ifrDesc.resRange.pflashIfrStart + config->ifrDesc.resRange.ifrMemSize)))
        {
        }
#if defined(FSL_FEATURE_FLASH_HAS_FLEX_NVM) && FSL_FEATURE_FLASH_HAS_FLEX_NVM
        /* read resource code from the  date flash IFR space */
        else if ((start >= config->ifrDesc.resRange.dflashIfrStart) &&
                 (maxReadbleAddress < (config->ifrDesc.resRange.dflashIfrStart + config->ifrDesc.resRange.ifrMemSize)))
        {
        }
#endif /* FSL_FEATURE_FLASH_HAS_FLEX_NVM */
#if defined(FSL_FEATURE_FLASH_HAS_SWAP_CONTROL_CMD) && FSL_FEATURE_FLASH_HAS_SWAP_CONTROL_CMD
        /* read resource code from the  Program Flash Swap IFR space */
        else if ((start >= config->ifrDesc.resRange.pflashSwapIfrStart) &&
                 (maxReadbleAddress <
                  (config->ifrDesc.resRange.pflashSwapIfrStart + config->ifrDesc.resRange.ifrMemSize)))
        {
        }
#endif /* FSL_FEATURE_FLASH_HAS_SWAP_CONTROL_CMD */
        else
        {
            status = kStatus_FTFx_InvalidArgument;
        }
    }
    else
    {
        status = kStatus_FTFx_InvalidArgument;
    }

    return status;
}
#endif /* FSL_FEATURE_FLASH_HAS_READ_RESOURCE_CMD */
