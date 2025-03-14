/*
 * Copyright 2013-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2021 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "fsl_ftfx_flash.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.dsc_flash"
#endif

/*!
 * @brief Enumeration for special memory property.
 */
enum _ftfx_special_mem_property
{
    kFTFx_AccessSegmentUnitSize = 256UL,
    kFTFx_MinProtectBlockSize   = 1024UL,
};

#if defined(FSL_FEATURE_FLASH_HAS_SWAP_CONTROL_CMD) && FSL_FEATURE_FLASH_HAS_SWAP_CONTROL_CMD
/*!
 * @brief Enumeration for the index of read/program once record
 */
enum _k3_flash_read_once_index
{
    kFLASH_RecordIndexSwapAddr    = 0xA1U, /*!< Index of Swap indicator address.*/
    kFLASH_RecordIndexSwapEnable  = 0xA2U, /*!< Index of Swap system enable.*/
    kFLASH_RecordIndexSwapDisable = 0xA3U, /*!< Index of Swap system disable.*/
};
#endif /* FSL_FEATURE_FLASH_HAS_SWAP_CONTROL_CMD */

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*! @brief init flash features */
static void flash_init_features(ftfx_config_t *config);

/*! @brief init  protection feature */
static void flash_protection_init(flash_config_t *config, uint8_t flashIndex);

/*! @brief init access segment feature */
#if defined(FSL_FEATURE_FLASH_HAS_ACCESS_CONTROL) && FSL_FEATURE_FLASH_HAS_ACCESS_CONTROL
static void flash_access_init(flash_config_t *config, uint8_t flashIndex);
#endif

/*! @brief init flash operation config */
static void flash_opsonfig_Init(flash_config_t *config, uint8_t flashIndex);

/*! @brief Calculate flash memory size based on given parameter */
static uint32_t flash_calculate_mem_size(uint32_t pflashBlockCount, uint32_t pflashBlockSize);

static uint32_t flash_calculate_prot_segment_size(uint32_t flashSize, uint32_t segmentCount);

/*! @brief Validates the given address to get current flash index */
static status_t flash_check_range_to_get_index(flash_config_t *config,
                                               uint32_t start,
                                               uint32_t lengthInBytes,
                                               uint8_t *flashIndex);

/*! @brief Decide whether to convert the start address from primary flash to secondary flash based on the current start
 * address*/
static void flash_convert_start_address(ftfx_config_t *config, uint32_t start);

#if defined(FSL_FEATURE_FLASH_HAS_PFLASH_BLOCK_SWAP) && FSL_FEATURE_FLASH_HAS_PFLASH_BLOCK_SWAP
/*! @brief Validates the given address to see if it is equal to swap indicator address in pflash swap IFR.*/
static status_t flash_validate_swap_indicator_address(ftfx_config_t *config, uint32_t address);
#endif /* FSL_FEATURE_FLASH_HAS_PFLASH_BLOCK_SWAP */

/*******************************************************************************
 * Variables
 ******************************************************************************/

#if defined(FTFx_FLASH0_HAS_HIGH_PROT_REG) && FTFx_FLASH0_HAS_HIGH_PROT_REG
static volatile uint32_t *const kFPROTH = (volatile uint32_t *)&FTFx_FPROT_HIGH_REG;
#endif /* FTFx_FLASH0_HAS_HIGH_PROT_REG */
#if defined(FTFx_FLASH1_HAS_INT_PROT_REG) && FTFx_FLASH1_HAS_INT_PROT_REG
volatile uint8_t *const kFPROTSL = (volatile uint8_t *)&FTFx_FPROTSL_REG;
volatile uint8_t *const kFPROTSH = (volatile uint8_t *)&FTFx_FPROTSH_REG;
#endif /* FTFx_FLASH1_HAS_INT_PROT_REG */

/*******************************************************************************
 * Code
 ******************************************************************************/

/*!
 * @brief Initializes the global flash properties structure members.
 *
 * This function checks and initializes the Flash module for the other Flash APIs.
 *
 * @param config Pointer to the storage for the driver runtime state.
 *
 * @retval #kStatus_FTFx_Success API was executed successfully.
 * @retval #kStatus_FTFx_InvalidArgument An invalid argument is provided.
 * @retval #kStatus_FTFx_ExecuteInRamFunctionNotReady Execute-in-RAM function is not available.
 * @retval #kStatus_FTFx_PartitionStatusUpdateFailure Failed to update the partition status.
 */
status_t FLASH_Init(flash_config_t *config)
{
    if (config == NULL)
    {
        return kStatus_FTFx_InvalidArgument;
    }

    for (uint8_t flashIndex = 0U; flashIndex < FTFx_FLASH_COUNT; flashIndex++)
    {
        /* init flash type, kinetis has Pflash and flxnvm, pflash is often used to store executable code
         * and flexnvm can be used as date flash to store user data, and can also be configured as eeprom backup space
         * with flexram.
         */
        config->ftfxConfig[flashIndex].flashDesc.type = (uint8_t)kFTFx_MemTypePflash;
        /* init the current flash index */
        config->ftfxConfig[flashIndex].flashDesc.index = flashIndex;
        /* init flash features */
        flash_init_features(&config->ftfxConfig[flashIndex]);
        /* init flash Operation Config */
        flash_opsonfig_Init(config, flashIndex);

#if defined(FSL_FEATURE_FLASH_HAS_ACCESS_CONTROL) && FSL_FEATURE_FLASH_HAS_ACCESS_CONTROL
        if (0U != (config->ftfxConfig[flashIndex].flashDesc.feature.hasXaccControl))
        {
            /* init access segment feature */
            flash_access_init(config, flashIndex);
        }
#endif /* FSL_FEATURE_FLASH_HAS_ACCESS_CONTROL */
#if (FTFx_FLASH_COUNT > 1U)
        if (0U != (config->ftfxConfig[flashIndex].flashDesc.feature.hasProtControl))
#endif
        {
            /* init  protection feature */
            flash_protection_init(config, flashIndex);
        }

        /* Init FTFx Kernel */
        FTFx_API_Init(&config->ftfxConfig[flashIndex]);
    }

    return kStatus_FTFx_Success;
}

/*!
 * @brief Erases the Dflash sectors encompassed by parameters passed into function.
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
 * @retval #kStatus_FTFx_Success API was executed successfully; the appropriate number of flash sectors based on the
 *         desired start address and length was erased successfully.
 *
 * @retval #kStatus_FTFx_InvalidArgument An invalid argument is provided.
 * @retval #kStatus_FTFx_AlignmentError The parameter is not aligned with the specified baseline.
 * @retval #kStatus_FTFx_AddressError The address is out of range.
 * @retval #kStatus_FTFx_EraseKeyError The API erase key is invalid.
 * @retval #kStatus_FTFx_ExecuteInRamFunctionNotReady Execute-in-RAM function is not available.
 * @retval #kStatus_FTFx_AccessError Invalid instruction codes and out-of bounds addresses.
 * @retval #kStatus_FTFx_ProtectionViolation The program/erase operation is requested to execute on protected areas.
 * @retval #kStatus_FTFx_CommandFailure Run-time error during the command execution.
 */
status_t FLASH_Erase(flash_config_t *config, uint32_t start, uint32_t lengthInBytes, uint32_t key)
{
    status_t returnCode;
    uint8_t flashIndex;

    /* check the supplied address range to get flash index  */
    returnCode = flash_check_range_to_get_index(config, start, lengthInBytes, &flashIndex);
    if (returnCode != kStatus_FTFx_Success)
    {
        return returnCode;
    }

    /* Decide whether to convert the start address from primary flash to secondary flash based on the current address */
    flash_convert_start_address(&config->ftfxConfig[flashIndex], start);

    return FTFx_CMD_Erase(&config->ftfxConfig[flashIndex], start, lengthInBytes, key);
}

/*!
 * @brief Erases entire flexnvm
 */
status_t FLASH_EraseAll(flash_config_t *config, uint32_t key)
{
    return FTFx_CMD_EraseAll(&config->ftfxConfig[0], key);
}

#if defined(FSL_FEATURE_FLASH_HAS_ERASE_ALL_BLOCKS_UNSECURE_CMD) && FSL_FEATURE_FLASH_HAS_ERASE_ALL_BLOCKS_UNSECURE_CMD
/*!
 * @brief Erases the entire flexnvm, including protected sectors.
 */
status_t FLASH_EraseAllUnsecure(flash_config_t *config, uint32_t key)
{
    return FTFx_CMD_EraseAllUnsecure(&config->ftfxConfig[0], key);
}
#endif

/*!
 * @brief Programs flash with data at locations passed in through parameters.
 *
 * This function programs the flash memory with the desired data for a given
 * flash area as determined by the start address and the length.
 */
status_t FLASH_Program(flash_config_t *config, uint32_t start, uint8_t *src, uint32_t lengthInBytes)
{
    status_t returnCode;
    uint8_t flashIndex;

    /* check range to get flash index */
    returnCode = flash_check_range_to_get_index(config, start, lengthInBytes, &flashIndex);
    if (returnCode != kStatus_FTFx_Success)
    {
        return returnCode;
    }
    /* convert the start address from primary flash to secondary flash based on the current address */
    flash_convert_start_address(&config->ftfxConfig[flashIndex], start);

    /* Programs flash */
    return FTFx_CMD_Program(&config->ftfxConfig[flashIndex], start, src, lengthInBytes);
}

/*!
 * @brief Reads the Program Once Field through parameters.
 */
status_t FLASH_ProgramOnce(flash_config_t *config, uint8_t index, uint8_t *src, uint32_t lengthInBytes)
{
    return FTFx_CMD_ProgramOnce(&config->ftfxConfig[0], index, src, lengthInBytes);
}

#if defined(FSL_FEATURE_FLASH_HAS_READ_RESOURCE_CMD) && FSL_FEATURE_FLASH_HAS_READ_RESOURCE_CMD
/*!
 * @brief Reads the resource with data at locations passed in through parameters.
 */
status_t FLASH_ReadResource(
    flash_config_t *config, uint32_t start, uint8_t *dst, uint32_t lengthInBytes, uint8_t option)
{
    return FTFx_CMD_ReadResource(&config->ftfxConfig[0], start, dst, lengthInBytes, option);
}
#endif

/*!
 * @brief Reads the Program Once Field through parameters.
 */
status_t FLASH_ReadOnce(flash_config_t *config, uint8_t index, uint8_t *dst, uint32_t lengthInBytes)
{
    return FTFx_CMD_ReadOnce(&config->ftfxConfig[0], index, dst, lengthInBytes);
}

/*!
 * @brief Verifies an erasure of the desired flash area at a specified margin level.
 *
 * This function checks the appropriate number of flash sectors based on
 * the desired start address and length to check whether the flash is erased
 * to the specified read margin level.
 */
status_t FLASH_VerifyErase(flash_config_t *config, uint32_t start, uint32_t lengthInBytes, uint8_t margin)
{
    status_t returnCode;
    uint8_t flashIndex;

    /* check range to get flash index */
    returnCode = flash_check_range_to_get_index(config, start, lengthInBytes, &flashIndex);
    if (returnCode != kStatus_FTFx_Success)
    {
        return returnCode;
    }

    /* convert the start address from primary flash to secondary flash based on the current start address*/
    flash_convert_start_address(&config->ftfxConfig[flashIndex], start);

    return FTFx_CMD_VerifyErase(&config->ftfxConfig[flashIndex], start, lengthInBytes, margin);
}

/*!
 * @brief Verifies erasure of the entire flash at a specified margin level.
 */
status_t FLASH_VerifyEraseAll(flash_config_t *config, uint8_t margin)
{
    return FTFx_CMD_VerifyEraseAll(&config->ftfxConfig[0], margin);
}

/*!
 * @brief Verifies programming of the desired flash area at a specified margin level.
 *
 * This function verifies the data programmed in the flash memory using the
 * Flash Program Check Command and compares it to the expected data for a given
 * flash area as determined by the start address and length.
 */
status_t FLASH_VerifyProgram(flash_config_t *config,
                             uint32_t start,
                             uint32_t lengthInBytes,
                             const uint8_t *expectedData,
                             uint8_t margin,
                             uint32_t *failedAddress,
                             uint32_t *failedData)
{
    status_t returnCode;
    uint8_t flashIndex;

    /* Validates the given address to get current flash index */
    returnCode = flash_check_range_to_get_index(config, start, lengthInBytes, &flashIndex);
    if (returnCode != kStatus_FTFx_Success)
    {
        return returnCode;
    }

    /* convert the start address from primary flash to secondary flash based on the current start address */
    flash_convert_start_address(&config->ftfxConfig[flashIndex], start);

    return FTFx_CMD_VerifyProgram(&config->ftfxConfig[flashIndex], start, lengthInBytes, expectedData, margin,
                                  failedAddress, failedData);
}

/*!
 * @brief Returns the security state via the pointer passed into the function.
 */
status_t FLASH_GetSecurityState(flash_config_t *config, ftfx_security_state_t *state)
{
    return FTFx_REG_GetSecurityState(&config->ftfxConfig[0], state);
}

/*!
 * @brief Returns the desired flash property.
 *
 * @param config A pointer to the storage for the driver runtime state.
 * @param whichProperty The desired property from the list of properties in
 *        enum flash_property_tag_t
 * @param value A pointer to the value returned for the desired flash property.
 *
 * @retval #kStatus_FTFx_Success API was executed successfully.
 * @retval #kStatus_FTFx_InvalidArgument An invalid argument is provided.
 * @retval #kStatus_FTFx_UnknownProperty An unknown property tag.
 */
status_t FLASH_GetProperty(flash_config_t *config, flash_property_tag_t whichProperty, uint32_t *value)
{
    if ((config == NULL) || (value == NULL))
    {
        return kStatus_FTFx_InvalidArgument;
    }

    status_t status = kStatus_FTFx_Success;

    switch (whichProperty)
    {
        /* gat Pflash0 sector size */
        case kFLASH_PropertyPflash0SectorSize:
            *value = config->ftfxConfig[0].flashDesc.sectorSize;
            break;
        /* gat Pflash0 total size */
        case kFLASH_PropertyPflash0TotalSize:
            *value = config->ftfxConfig[0].flashDesc.totalSize;
            break;
        /* gat Pflash0 block size */
        case kFLASH_PropertyPflash0BlockSize:
            *value = config->ftfxConfig[0].flashDesc.totalSize / config->ftfxConfig[0].flashDesc.blockCount;
            break;
        /* gat Pflash0 block cont */
        case kFLASH_PropertyPflash0BlockCount:
            *value = config->ftfxConfig[0].flashDesc.blockCount;
            break;
        /* gat Pflash0 block base address */
        case kFLASH_PropertyPflash0BlockBaseAddr:
            *value = config->ftfxConfig[0].flashDesc.blockBase;
            break;
        /* gat Pflash0 fac support feature */
        case kFLASH_PropertyPflash0FacSupport:
            *value = (uint32_t)config->ftfxConfig[0].flashDesc.feature.hasXaccControl;
            break;
        /* gat Pflash0 access segment size feature */
        case kFLASH_PropertyPflash0AccessSegmentSize:
            *value = config->ftfxConfig[0].flashDesc.accessSegmentMem.size;
            break;
        /* gat Pflash0 access segment count feature */
        case kFLASH_PropertyPflash0AccessSegmentCount:
            *value = config->ftfxConfig[0].flashDesc.accessSegmentMem.count;
            break;

#if defined(FTFx_DRIVER_HAS_FLASH1_SUPPORT) && FTFx_DRIVER_HAS_FLASH1_SUPPORT
        case kFLASH_PropertyPflash1SectorSize:
            *value = config->ftfxConfig[1].flashDesc.sectorSize;
            break;
        case kFLASH_PropertyPflash1TotalSize:
            *value = config->ftfxConfig[1].flashDesc.totalSize;
            break;
        case kFLASH_PropertyPflash1BlockSize:
            *value = config->ftfxConfig[1].flashDesc.totalSize / config->ftfxConfig[1].flashDesc.blockCount;
            break;
        case kFLASH_PropertyPflash1BlockCount:
            *value = config->ftfxConfig[1].flashDesc.blockCount;
            break;
        case kFLASH_PropertyPflash1BlockBaseAddr:
            *value = config->ftfxConfig[1].flashDesc.blockBase;
            break;
        case kFLASH_PropertyPflash1FacSupport:
            *value = (uint32_t)config->ftfxConfig[1].flashDesc.feature.hasXaccControl;
            break;
        case kFLASH_PropertyPflash1AccessSegmentSize:
            *value = config->ftfxConfig[1].flashDesc.accessSegmentMem.size;
            break;
        case kFLASH_PropertyPflash1AccessSegmentCount:
            *value = config->ftfxConfig[1].flashDesc.accessSegmentMem.count;
            break;
#endif
        /* gat FlexRam block base addrese */
        case kFLASH_PropertyFlexRamBlockBaseAddr:
            *value = config->ftfxConfig[0].flexramBlockBase;
            break;
        /* gat FlexRam total size  */
        case kFLASH_PropertyFlexRamTotalSize:
            *value = config->ftfxConfig[0].flexramTotalSize;
            break;

        default: /* catch inputs that are not recognized */
            status = kStatus_FTFx_UnknownProperty;
            break;
    }

    return status;
}

/*!
 * @brief init flash FPROT, XACC registers and Independent flash block
 */
static void flash_init_features(ftfx_config_t *config)
{
    /* Initialize whether flash0 has independent block, protection registers and
     * execute only access registers */
#if (FTFx_FLASH_COUNT > 1U)
    if (config->flashDesc.index == 0U)
#endif
    {
        config->flashDesc.feature.isIndBlock      = 1U;
        config->flashDesc.feature.hasIndPfsizeReg = 1U;
        config->flashDesc.feature.hasIndProtReg   = 1U;
        config->flashDesc.feature.hasIndXaccReg   = 1U;
    }
    /* if another flash exists */
#if defined(FTFx_DRIVER_HAS_FLASH1_SUPPORT) && FTFx_DRIVER_HAS_FLASH1_SUPPORT
    else if (config->flashDesc.index == 1U)
    {
        config->flashDesc.feature.isIndBlock      = FTFx_FLASH1_IS_INDEPENDENT_BLOCK;
        config->flashDesc.feature.hasIndPfsizeReg = config->flashDesc.feature.isIndBlock;
        config->flashDesc.feature.hasIndProtReg   = FTFx_FLASH1_HAS_INT_PROT_REG;
        config->flashDesc.feature.hasIndXaccReg   = FTFx_FLASH1_HAS_INT_XACC_REG;
    }
#endif
#if (FTFx_FLASH_COUNT > 1U)
    else
    {
        /*do nothing*/
    }
#endif
    /* init  protection Registers feature*/
    config->flashDesc.feature.hasProtControl = 1U;
    /* init  Execute-only Access Registers feature*/
    config->flashDesc.feature.hasXaccControl = FSL_FEATURE_FLASH_HAS_ACCESS_CONTROL;
}

/*!
 * @brief Initializes the flash operation config.
 */
static void flash_opsonfig_Init(flash_config_t *config, uint8_t flashIndex)
{
    uint32_t pflashStartAddress;
    uint32_t pflashBlockSize;
    uint32_t pflashBlockCount;
    uint32_t pflashBlockSectorSize;
    uint32_t pflashBlockWriteUnitSize;  /* store P-Flash write unit size */
    uint32_t pflashSectorCmdAlignment;  /* store P-Flash Erase sector command address alignment */
    uint32_t pflashSectionCmdAlignment; /* store Program/Verify section command address alignment */

#if (FTFx_FLASH_COUNT > 1U)
    if (flashIndex == 1U)
    {
        pflashStartAddress        = FLASH1_FEATURE_PFLASH_START_ADDRESS;
        pflashBlockSize           = FLASH1_FEATURE_PFLASH_BLOCK_SIZE;
        pflashBlockCount          = FLASH1_FEATURE_PFLASH_BLOCK_COUNT;
        pflashBlockSectorSize     = FLASH1_FEATURE_PFLASH_BLOCK_SECTOR_SIZE;
        pflashBlockWriteUnitSize  = FLASH1_FEATURE_PFLASH_BLOCK_WRITE_UNIT_SIZE;
        pflashSectorCmdAlignment  = FLASH1_FEATURE_PFLASH_SECTOR_CMD_ADDRESS_ALIGMENT;
        pflashSectionCmdAlignment = FLASH1_FEATURE_PFLASH_SECTION_CMD_ADDRESS_ALIGMENT;
    }
    else
#endif
    {
        pflashStartAddress        = FLASH0_FEATURE_PFLASH_START_ADDRESS; /* get P-Flash start address */
        pflashBlockSize           = FLASH0_FEATURE_PFLASH_BLOCK_SIZE;
        pflashBlockCount          = FLASH0_FEATURE_PFLASH_BLOCK_COUNT;
        pflashBlockSectorSize     = FLASH0_FEATURE_PFLASH_BLOCK_SECTOR_SIZE;
        pflashBlockWriteUnitSize  = FLASH0_FEATURE_PFLASH_BLOCK_WRITE_UNIT_SIZE;
        pflashSectorCmdAlignment  = FLASH0_FEATURE_PFLASH_SECTOR_CMD_ADDRESS_ALIGMENT;
        pflashSectionCmdAlignment = FLASH0_FEATURE_PFLASH_SECTION_CMD_ADDRESS_ALIGMENT;
    }
    /* init current flash start address */
    config->ftfxConfig[flashIndex].flashDesc.blockBase = pflashStartAddress;
    /* init current flash block count */
    config->ftfxConfig[flashIndex].flashDesc.blockCount = pflashBlockCount;
    /* init current flash block sector size */
    config->ftfxConfig[flashIndex].flashDesc.sectorSize = pflashBlockSectorSize;

#if (FTFx_FLASH_COUNT > 1U)
    if ((0U != config->ftfxConfig[flashIndex].flashDesc.feature.isIndBlock) &&
        (0U != config->ftfxConfig[flashIndex].flashDesc.feature.hasIndPfsizeReg))
#endif
    {
        /* Calculate flash memory size based on given parameter */
        config->ftfxConfig[flashIndex].flashDesc.totalSize =
            flash_calculate_mem_size(pflashBlockCount, pflashBlockSize);
    }
#if (FTFx_FLASH_COUNT > 1U)
    else
    {
        config->ftfxConfig[flashIndex].flashDesc.totalSize = pflashBlockCount * pflashBlockSize;
    }
#endif

    /* init P-Flash write unit size */
    config->ftfxConfig[flashIndex].opsConfig.addrAligment.blockWriteUnitSize = (uint8_t)pflashBlockWriteUnitSize;
    /* init P-Flash Erase sector command address alignment */
    config->ftfxConfig[flashIndex].opsConfig.addrAligment.sectorCmd = (uint8_t)pflashSectorCmdAlignment;
    /* init P-Flash Program/Verify section command address alignment */
    config->ftfxConfig[flashIndex].opsConfig.addrAligment.sectionCmd = (uint8_t)pflashSectionCmdAlignment;
    /* init P-Flash Read resource command address alignment. */
    config->ftfxConfig[flashIndex].opsConfig.addrAligment.resourceCmd =
        (uint8_t)FSL_FEATURE_FLASH_PFLASH_RESOURCE_CMD_ADDRESS_ALIGMENT;
    /* init P-Flash Program check command address alignment. */
    config->ftfxConfig[flashIndex].opsConfig.addrAligment.checkCmd =
        (uint8_t)FSL_FEATURE_FLASH_PFLASH_CHECK_CMD_ADDRESS_ALIGMENT;
    /* init P-Flash swap command address alignment */
    config->ftfxConfig[flashIndex].opsConfig.addrAligment.swapCtrlCmd =
        (uint8_t)FSL_FEATURE_FLASH_PFLASH_SWAP_CONTROL_CMD_ADDRESS_ALIGMENT;
}

/*! @brief init protection feature */
static void flash_protection_init(flash_config_t *config, uint8_t flashIndex)
{
    uint32_t pflashProtectionRegionCount;
#if (FTFx_FLASH_COUNT > 1U)
    uint8_t i;

    if (flashIndex == 1U)
    {
        /* store flash0 Protection region count */
        pflashProtectionRegionCount = FLASH1_FEATURE_PFLASH_PROTECTION_REGION_COUNT;
    }
    else
#endif // #if (FTFx_FLASH_COUNT > 1U)
    {
        /* store flash0 Protection region count */
        pflashProtectionRegionCount = FLASH0_FEATURE_PFLASH_PROTECTION_REGION_COUNT;
    }

    /* Start to initialize the structure of protection features */
    ftfx_spec_mem_t *specMem;
    specMem = &config->ftfxConfig[flashIndex].flashDesc.protectRegionMem;
#if (FTFx_FLASH_COUNT > 1U)
    if (0U != (config->ftfxConfig[flashIndex].flashDesc.feature.hasIndProtReg))
#endif // #if (FTFx_FLASH_COUNT > 1U)
    {
        specMem->base  = config->ftfxConfig[flashIndex].flashDesc.blockBase;
        specMem->count = pflashProtectionRegionCount;
        /* Calculate flash prot segment size */
        specMem->size =
            flash_calculate_prot_segment_size(config->ftfxConfig[flashIndex].flashDesc.totalSize, specMem->count);
    }
#if (FTFx_FLASH_COUNT > 1U)
    else
    {
        uint32_t pflashTotalSize = 0U;
        specMem->base            = config->ftfxConfig[0].flashDesc.blockBase;
        specMem->count           = FLASH0_FEATURE_PFLASH_PROTECTION_REGION_COUNT;
        if (flashIndex == FTFx_FLASH_COUNT - 1U)
        {
            uint32_t segmentSize; /* store the flash protection region count */
            for (i = 0U; i < FTFx_FLASH_COUNT; i++)
            {
                /* get pflash total size*/
                pflashTotalSize += config->ftfxConfig[flashIndex].flashDesc.totalSize;
            }
            /* get pflash port segment size based on parameters */
            segmentSize = flash_calculate_prot_segment_size(pflashTotalSize, specMem->count);
            for (i = 0U; i < FTFx_FLASH_COUNT; i++)
            {
                /* init flash0 and flash1 port segment size */
                config->ftfxConfig[i].flashDesc.protectRegionMem.size = segmentSize;
            }
        }
    }
#endif // #if (FTFx_FLASH_COUNT > 1U)
}

/*!
 * @brief Calculate flash memory size based on given parameter
 */
static uint32_t flash_calculate_mem_size(uint32_t pflashBlockCount, uint32_t pflashBlockSize)
{
    uint32_t flashDensity;
    flashDensity = pflashBlockCount * pflashBlockSize;
    return flashDensity;
}

/*!
 * @brief Calculate flash prot segment size
 */
static uint32_t flash_calculate_prot_segment_size(uint32_t flashSize, uint32_t segmentCount)
{
    uint32_t segmentSize;

    /* Calculate the size of the flash protection region
     * If the flash density is > 32KB, then protection region is 1/32 of total flash density
     * Else if flash density is < 32KB, then flash protection region is set to 1KB */
    if (flashSize > segmentCount * (uint32_t)kFTFx_MinProtectBlockSize)
    {
        segmentSize = flashSize / segmentCount;
    }
    else
    {
        segmentSize = (uint32_t)kFTFx_MinProtectBlockSize;
    }

    return segmentSize;
}

/*!
 * @brief Validates the given start address and length to get flash index
 */
static status_t flash_check_range_to_get_index(flash_config_t *config,
                                               uint32_t start,
                                               uint32_t lengthInBytes,
                                               uint8_t *flashIndex)
{
    if (config == NULL)
    {
        return kStatus_FTFx_InvalidArgument;
    }

    /* Validates the range of the given address */
    for (uint8_t index = 0U; index < FTFx_FLASH_COUNT; index++)
    {
        if ((start >= config->ftfxConfig[index].flashDesc.blockBase) &&
            ((start + lengthInBytes) <=
             (config->ftfxConfig[index].flashDesc.blockBase + config->ftfxConfig[index].flashDesc.totalSize)))
        {
            *flashIndex = config->ftfxConfig[index].flashDesc.index;
            return kStatus_FTFx_Success;
        }
    }

    return kStatus_FTFx_AddressError;
}

/*!
 * @brief Decide whether to convert the start address from primary flash to secondary flash based on the current start
 * address
 */
static void flash_convert_start_address(ftfx_config_t *config, uint32_t start)
{
    // The caller will guarantee that the config is valid
#if (FTFx_FLASH_COUNT > 1U)
    if ((0U != config->flashDesc.index) && (0U != config->flashDesc.feature.isIndBlock))
    {
        /* When required by the command, address bit 23 selects between main flash memory
         * (=0) and secondary flash memory (=1).*/
        config->opsConfig.convertedAddress = start - config->flashDesc.blockBase + 0x800000U;
    }
    else
#endif
    {
        config->opsConfig.convertedAddress = start;
    }
}
