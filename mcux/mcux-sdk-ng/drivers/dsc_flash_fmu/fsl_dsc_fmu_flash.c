/*
 * Copyright 2018-2021,2025-2026 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "fsl_dsc_fmu_flash.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.dsc_flash_fmu"
#endif

/*******************************************************************************
 * Internal types
 ******************************************************************************/

enum
{
    flashType_main,
    flashType_ifr0
};

typedef struct addr_info
{
    int arrayIdx;
    int flashType;
    uint32_t baseAddr;
    uint32_t physAddr;
} addr_info_t;

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
static status_t flash_check_param(
    flash_config_t *config, FMU_Type *base, uint32_t start, uint32_t lengthInBytes, uint32_t alignmentBaseline, addr_info_t *addrInfo);
static int flash_array_idx(flash_config_t *config, uint32_t addr, uint32_t size, uint32_t *offset);
static int ifr_array_idx(flash_config_t *config, uint32_t addr, uint32_t size, uint32_t *offset);
static status_t flash_check_user_key(uint32_t key);

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/

status_t FLASH_Init(flash_config_t *config)
{
    status_t status = kStatus_Fail;

    if (config == NULL)
    {
        status = kStatus_FLASH_InvalidArgument;
    }
    else
    {
        config->flash[0].flashDesc.blockBase  = FLASH_FEATURE_ARRAY0_START_ADDRESS;
        config->flash[0].flashDesc.totalSize  = FLASH_FEATURE_ARRAY0_SIZE;
        config->flash[0].flashDesc.blockCount = 1;

        config->flash[1].flashDesc.blockBase  = FLASH_FEATURE_ARRAY1_START_ADDRESS;
        config->flash[1].flashDesc.totalSize  = FLASH_FEATURE_ARRAY1_SIZE;
        config->flash[1].flashDesc.blockCount = 1;

        config->flash[0].ifrDesc.pflashIfr0Start   = FLASH_FEATURE_IFR0_ARRAY0_START_ADDRESS;
        config->flash[0].ifrDesc.pflashIfr0MemSize = FLASH_FEATURE_IFR0_ARRAY0_SIZE;

        config->flash[1].ifrDesc.pflashIfr0Start   = FLASH_FEATURE_IFR0_ARRAY1_START_ADDRESS;
        config->flash[1].ifrDesc.pflashIfr0MemSize = FLASH_FEATURE_IFR0_ARRAY1_SIZE;

        status = kStatus_FLASH_Success;
    }

    return status;
}

status_t FLASH_Erase(flash_config_t *config, FMU_Type *base, uint32_t start, uint32_t lengthInBytes, uint32_t key)
{
    status_t status = kStatus_Fail;

    status = flash_check_param(config, base, start, lengthInBytes, FLASH_FEATURE_PHRASE_SIZE, NULL);
    if ((status == kStatus_FLASH_Success) && (flash_check_user_key(key) == kStatus_FLASH_Success))
    {
        uint32_t endAddress = start + lengthInBytes - 1U;

        while (start <= endAddress)
        {
            status = FLASH_CMD_EraseSector(base, start);
            if (kStatus_FLASH_Success != status)
            {
                break;
            }
            else
            {
                /* Increment to the next sector */
                start += FLASH_FEATURE_SECTOR_SIZE;
            }
        }
    }
    else
    {
        ; /* MISRA */
    }

    return status;
}

status_t FLASH_EraseAll(FMU_Type *base, uint32_t key)
{
    status_t status   = kStatus_Fail;
    FMU_Type *baseTmp = (FMU_Type *)((uint32_t)base & FLASH_ADDR_MASK);

    if (base == NULL || baseTmp != FLASH)
    {
        status = kStatus_FLASH_InvalidArgument;
    }
    else
    {
        /* Validate the user key */
        status = flash_check_user_key(key);
    }

    if (kStatus_FLASH_Success == status)
    {
        status = FLASH_CMD_EraseAll(base);
    }
    else
    {
        ; /* MISRA */
    }

    return status;
}

status_t FLASH_Program(flash_config_t *config, FMU_Type *base, uint32_t start, uint32_t *src, uint32_t lengthInBytes)
{
    status_t status = kStatus_Fail;

    status = flash_check_param(config, base, start, lengthInBytes, FLASH_FEATURE_PHRASE_SIZE, NULL);
    if (status == kStatus_FLASH_Success)
    {
        /* Align length to whole phrase */
        uint32_t alignedLength = ALIGN_DOWN(lengthInBytes, sizeof(uint8_t) * FLASH_FEATURE_PHRASE_SIZE);
        uint32_t extraBytes    = 0;

        if (lengthInBytes >= alignedLength)
        {
            extraBytes = lengthInBytes - alignedLength;
        }
        else
        {
            /* Handle underflow error */
            return kStatus_FLASH_AddressError;
        }

        if (alignedLength > 0U)
        {
            uint32_t endAddress;
            if (start > UINT32_MAX - alignedLength)
            {
                /* Handle overflow error */
                return kStatus_FLASH_AddressError;
            }
            endAddress = start + alignedLength - 1U;
            while (start <= endAddress)
            {
                status = FLASH_CMD_ProgramPhrase(base, start, src);
                if (kStatus_FLASH_Success != status)
                {
                    break;
                }
                else
                {
                    /* Increment to the next sector */
                    start += FLASH_FEATURE_PHRASE_SIZE;
                    src   += FLASH_FEATURE_PHRASE_SIZE_IN_WORD;
                }
            }
        }
        else
        {
            ; /* MISRA */
        }

        if ((kStatus_FLASH_Success == status) && (extraBytes > 0U))
        {
            uint32_t extraData[4] = {0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu};

            /* Copy extra bytes to phrase buffer */
            union
            {
                uint32_t *src;
                const void *srcVoid;
            } srcPtr;
            srcPtr.src = src;

            union
            {
                uint32_t *xData;
                void *xDataVoid;
            } xDataPtr;
            xDataPtr.xData = (uint32_t *)&extraData[0];

            (void)memcpy(xDataPtr.xDataVoid, srcPtr.srcVoid, extraBytes);

            status = FLASH_CMD_ProgramPhrase(base, start, extraData);
        }
    }
    else
    {
        ; /* MISRA */
    }

    return status;
}

status_t FLASH_ProgramPage(flash_config_t *config, FMU_Type *base, uint32_t start, uint32_t *src, uint32_t lengthInBytes)
{
    status_t status = kStatus_Fail;

    status = flash_check_param(config, base, start, lengthInBytes, FLASH_FEATURE_PAGE_SIZE, NULL);
    if (status == kStatus_FLASH_Success)
    {
        /* Align length to whole phrase */
        uint32_t alignedLength = ALIGN_DOWN(lengthInBytes, sizeof(uint8_t) * FLASH_FEATURE_PAGE_SIZE);
        uint32_t extraBytes    = 0;
        if (lengthInBytes >= alignedLength)
        {
            extraBytes = lengthInBytes - alignedLength;
        }
        else
        {
            /* Handle underflow error */
            return kStatus_FLASH_AddressError;
        }

        if (alignedLength > 0U)
        {
            uint32_t endAddress;
            if (start > UINT32_MAX - alignedLength)
            {
                /* Handle overflow error */
                return kStatus_FLASH_AddressError;
            }
            endAddress = start + alignedLength - 1U;
            while (start <= endAddress)
            {
                status = FLASH_CMD_ProgramPage(base, start, src);
                if (kStatus_FLASH_Success != status)
                {
                    break;
                }
                else
                {
                    /* Increment to the next sector */
                    start += FLASH_FEATURE_PAGE_SIZE;
                    src   += FLASH_FEATURE_PAGE_SIZE_IN_WORD;
                }
            }
        }
        else
        {
            ; /* MISRA */
        }

        if ((kStatus_FLASH_Success == status) && (extraBytes > 0U))
        {
            uint32_t extraData[32] = {
                0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu,
                0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu,
                0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu,
                0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu};

            /* Copy extra bytes to page buffer */
            union
            {
                uint32_t *src;
                const void *srcVoid;
            } srcPtr;
            srcPtr.src = src;

            union
            {
                uint32_t *xData;
                void *xDataVoid;
            } xDataPtr;
            xDataPtr.xData = (uint32_t *)&extraData[0];

            (void)memcpy(xDataPtr.xDataVoid, srcPtr.srcVoid, extraBytes);

            status = FLASH_CMD_ProgramPage(base, start, extraData);
        }
    }
    else
    {
        ; /* MISRA */
    }

    return status;
}

status_t FLASH_VerifyErasePhrase(flash_config_t *config, FMU_Type *base, uint32_t start, uint32_t lengthInBytes)
{
    status_t status = kStatus_Fail;
    addr_info_t info;

    status = flash_check_param(config, base, start, lengthInBytes, FLASH_FEATURE_PHRASE_SIZE, &info);
    if (status == kStatus_FLASH_Success)
    {
        uint32_t physAddr = info.physAddr;
        uint32_t endAddress;

        if (physAddr > UINT32_MAX - lengthInBytes)
        {
            /* Handle overflow error */
            return kStatus_FLASH_AddressError;
        }
        endAddress = info.physAddr + lengthInBytes - 1U;

        while (physAddr <= endAddress)
        {
            if (info.flashType == flashType_main)
            {
                status = FLASH_CMD_VerifyErasePhrase(base, physAddr);
            }
            else
            {
                status = FLASH_CMD_VerifyEraseIFRPhrase(base, physAddr);
            }

            if (kStatus_FLASH_Success != status)
            {
                break;
            }
            else
            {
                /* Increment to the next phrase */
                physAddr += FLASH_FEATURE_PHRASE_SIZE;
            }
        }
    }
    else
    {
        ; /* MISRA */
    }

    return status;
}

status_t FLASH_VerifyErasePage(flash_config_t *config, FMU_Type *base, uint32_t start, uint32_t lengthInBytes)
{
    status_t status = kStatus_Fail;
    addr_info_t info;

    status = flash_check_param(config, base, start, lengthInBytes, FLASH_FEATURE_PAGE_SIZE, &info);
    if (status == kStatus_FLASH_Success)
    {
        uint32_t physAddr = info.physAddr;
        uint32_t endAddress;

        if (physAddr > UINT32_MAX - lengthInBytes)
        {
            /* Handle overflow error */
            return kStatus_FLASH_AddressError;
        }
        endAddress = physAddr + lengthInBytes - 1U;

        while (physAddr <= endAddress)
        {
            if (info.flashType == flashType_main)
            {
                status = FLASH_CMD_VerifyErasePage(base, physAddr);
            }
            else
            {
                status = FLASH_CMD_VerifyEraseIFRPage(base, physAddr);
            }

            if (kStatus_FLASH_Success != status)
            {
                break;
            }
            else
            {
                /* Increment to the next page */
                physAddr += FLASH_FEATURE_PAGE_SIZE;
            }
        }
    }
    else
    {
        ; /* MISRA */
    }

    return status;
}

status_t FLASH_VerifyEraseSector(flash_config_t *config, FMU_Type *base, uint32_t start, uint32_t lengthInBytes)
{
    status_t status = kStatus_Fail;
    addr_info_t info;

    status = flash_check_param(config, base, start, lengthInBytes, FLASH_FEATURE_SECTOR_SIZE, &info);
    if (status == kStatus_FLASH_Success)
    {
        uint32_t physAddr = info.physAddr;
        uint32_t endAddress;

        if (physAddr > UINT32_MAX - lengthInBytes)
        {
            /* Handle overflow error */
            return kStatus_FLASH_AddressError;
        }
        endAddress = physAddr + lengthInBytes - 1U;

        while (physAddr <= endAddress)
        {
            if (info.flashType == flashType_main)
            {
                status = FLASH_CMD_VerifyEraseSector(base, physAddr);
            }
            else
            {
                status = FLASH_CMD_VerifyEraseIFRSector(base, physAddr);
            }

            if (kStatus_FLASH_Success != status)
            {
                break;
            }
            else
            {
                /* Increment to the next sector */
                physAddr += FLASH_FEATURE_SECTOR_SIZE;
            }
        }
    }
    else
    {
        ; /* MISRA */
    }

    return status;
}

#if 0
status_t FLASH_VerifyEraseIFRPhrase(flash_config_t *config, FMU_Type *base, uint32_t start, uint32_t lengthInBytes)
{
    status_t status   = kStatus_Fail;
    uint32_t physAddr = 0;

    status = flash_check_param(config, base, start, lengthInBytes, FLASH_FEATURE_PHRASE_SIZE, &physAddr);
    if (status == kStatus_FLASH_Success)
    {
        uint32_t endAddress;
        if (physAddr > UINT32_MAX - lengthInBytes)
        {
            /* Handle overflow error */
            return kStatus_FLASH_AddressError;
        }
        endAddress = physAddr + lengthInBytes - 1U;
        while (physAddr <= endAddress)
        {
            status = FLASH_CMD_VerifyEraseIFRPhrase(base, physAddr);
            if (kStatus_FLASH_Success != status)
            {
                break;
            }
            else
            {
                /* Increment to the next phrase */
                physAddr += FLASH_FEATURE_PHRASE_SIZE;
            }
        }
    }
    else
    {
        ; /* MISRA */
    }

    return status;
}

status_t FLASH_VerifyEraseIFRPage(flash_config_t *config, FMU_Type *base, uint32_t start, uint32_t lengthInBytes)
{
    status_t status   = kStatus_Fail;
    uint32_t physAddr = 0;

    status = flash_check_param(config, base, start, lengthInBytes, FLASH_FEATURE_PAGE_SIZE, &physAddr);
    if (status == kStatus_FLASH_Success)
    {
        uint32_t endAddress;
        if (physAddr > UINT32_MAX - lengthInBytes)
        {
            /* Handle overflow error */
            return kStatus_FLASH_AddressError;
        }
        endAddress = physAddr + lengthInBytes - 1U;
        while (physAddr <= endAddress)
        {
            status = FLASH_CMD_VerifyEraseIFRPage(base, physAddr);
            if (kStatus_FLASH_Success != status)
            {
                break;
            }
            else
            {
                /* Increment to the next page */
                physAddr += FLASH_FEATURE_PAGE_SIZE;
            }
        }
    }
    else
    {
        ; /* MISRA */
    }

    return status;
}

status_t FLASH_VerifyEraseIFRSector(flash_config_t *config, FMU_Type *base, uint32_t start, uint32_t lengthInBytes)
{
    status_t status   = kStatus_Fail;
    uint32_t physAddr = 0;

    status = flash_check_param(config, base, start, lengthInBytes, FLASH_FEATURE_SECTOR_SIZE, &physAddr);
    if (status == kStatus_FLASH_Success)
    {
        uint32_t endAddress;
        if (physAddr > UINT32_MAX - lengthInBytes)
        {
            return kStatus_FLASH_AddressError;
        }
        endAddress = physAddr + lengthInBytes - 1U;
        while (physAddr <= endAddress)
        {
            status = FLASH_CMD_VerifyEraseIFRSector(base, physAddr);
            if (kStatus_FLASH_Success != status)
            {
                break;
            }
            else
            {
                /* Increment to the next sector */
                physAddr += FLASH_FEATURE_SECTOR_SIZE;
            }
        }
    }
    else
    {
        ; /* MISRA */
    }

    return status;
}
#endif

status_t FLASH_VerifyEraseAll(FMU_Type *base)
{
    status_t status   = kStatus_Fail;
    FMU_Type *baseTmp = (FMU_Type *)((uint32_t)base & FLASH_ADDR_MASK);

    if (base == NULL || baseTmp != FLASH)
    {
        status = kStatus_FLASH_InvalidArgument;
    }
    else
    {
        status = FLASH_CMD_VerifyEraseAll(base);
    }

    return status;
}

status_t FLASH_VerifyEraseBlock(flash_config_t *config, FMU_Type *base, uint32_t blockaddr)
{
    status_t status      = kStatus_Fail;
    FMU_Type *baseNS     = (FMU_Type *)((uint32_t)base & FLASH_ADDR_MASK);
    uint32_t blockaddrNS = blockaddr & FLASH_ADDR_MASK;
    uint32_t offset = 0;
    int idx;

    if (config == NULL || base == NULL || baseNS != FLASH)
    {
        status = kStatus_FLASH_InvalidArgument;
    }

    idx = flash_array_idx(config, blockaddrNS, FLASH_FEATURE_SECTOR_SIZE, &offset);
    if (idx >= 0)
    {
        if (blockaddrNS != config->flash[idx].flashDesc.blockBase)
        {
            status = kStatus_FLASH_AddressError;
        }
        else
        {
            status = FLASH_CMD_VerifyEraseBlock(base, offset);
        }
    }
    else
    {
        status = kStatus_FLASH_AddressError;
    }

    return status;
}

status_t Read_Into_MISR(
    flash_config_t *config, FMU_Type *base, uint32_t start, uint32_t ending, uint32_t *seed, uint32_t *signature)
{
    status_t status = kStatus_Fail;
    addr_info_t info;

    if ((start >= ending) || (seed == NULL) ||
        (((ending + FLASH_FEATURE_PHRASE_SIZE) & (FLASH_FEATURE_PAGE_SIZE - 1U)) != 0u))
    {
        status = kStatus_FLASH_InvalidArgument;
    }
    else if ((ending & (FLASH_FEATURE_PHRASE_SIZE - 1U)) != 0u)
    {
        status = kStatus_FLASH_AlignmentError;
    }
    else
    {
        status = flash_check_param(config, base, start, (ending - start), FLASH_FEATURE_PAGE_SIZE, &info);
        if (status == kStatus_FLASH_Success)
        {
            uint32_t physAddr = info.physAddr;
            uint32_t endAddr;
            if (physAddr > UINT32_MAX - (ending - start))
            {
                /* Handle overflow error */
                return kStatus_FLASH_AddressError;
            }
            endAddr = physAddr + ending - start;
            status = FLASH_CMD_ReadIntoMISR(base, physAddr, endAddr, seed, signature);
        }
        else
        {
            ; /* MISRA */
        }
    }

    return status;
}

status_t Read_IFR_Into_MISR(
    flash_config_t *config, FMU_Type *base, uint32_t start, uint32_t ending, uint32_t *seed, uint32_t *signature)
{
    status_t status = kStatus_Fail;
    addr_info_t info;

    if ((start >= ending) || (seed == NULL) ||
        (((ending + FLASH_FEATURE_PHRASE_SIZE) & (FLASH_FEATURE_PAGE_SIZE - 1U)) != 0U))
    {
        status = kStatus_FLASH_InvalidArgument;
    }
    else if ((ending & (FLASH_FEATURE_PHRASE_SIZE - 1U)) != 0u)
    {
        status = kStatus_FLASH_AlignmentError;
    }
    else
    {
        status = flash_check_param(config, base, start, (ending - start), FLASH_FEATURE_PAGE_SIZE, &info);
        if (status == kStatus_FLASH_Success)
        {
            uint32_t physAddr = info.physAddr;
            uint32_t endAddr;
            if (physAddr > UINT32_MAX - (ending - start))
            {
                /* Handle overflow error */
                return kStatus_FLASH_AddressError;
            }
            endAddr = physAddr + ending - start;
            status  = FLASH_CMD_ReadIFRIntoMISR(base, physAddr, endAddr, seed, signature);
        }
        else
        {
            ; /* MISRA */
        }
    }

    return status;
}

status_t FLASH_GetProperty(flash_config_t *config, flash_property_tag_t whichProperty, uint32_t *value)
{
    status_t status = kStatus_FLASH_Success;

    switch (whichProperty)
    {
        case kFLASH_PropertyPflash0TotalSize:
            *value = config->flash[0].flashDesc.totalSize;
            break;
        case kFLASH_PropertyPflash0BlockSize:
            *value = config->flash[0].flashDesc.totalSize / config->flash[0].flashDesc.blockCount;
            break;
        case kFLASH_PropertyPflash0BlockCount:
            *value = config->flash[0].flashDesc.blockCount;
            break;
        case kFLASH_PropertyPflash0BlockBaseAddr:
            *value = config->flash[0].flashDesc.blockBase;
            break;
        case kFLASH_PropertyPflash0SectorSize:
        case kFLASH_PropertyPflash1SectorSize:
            *value = FLASH_FEATURE_SECTOR_SIZE;
            break;
        case kFLASH_PropertyPflash1TotalSize:
            *value = config->flash[1].flashDesc.totalSize;
            break;
        case kFLASH_PropertyPflash1BlockSize:
            *value = config->flash[1].flashDesc.totalSize / config->flash[1].flashDesc.blockCount;
            break;
        case kFLASH_PropertyPflash1BlockCount:
            *value = config->flash[1].flashDesc.blockCount;
            break;
        case kFLASH_PropertyPflash1BlockBaseAddr:
            *value = config->flash[1].flashDesc.blockBase;
            break;
        default:
            status = kStatus_FLASH_UnknownProperty;
            /* To avoid MISRA-C 2012 rule 16.4 issue. */
            break;
    }
    return status;
}

static int ifr_array_idx(flash_config_t *config, uint32_t addr, uint32_t size, uint32_t *offset)
{
    uint32_t totsize = 0;

    for (int i = 0; i < ARRAY_SIZE(config->flash); i++)
    {
        flash_ifr_desc_t ifr = config->flash[i].ifrDesc;

        if (offset)
        {
            *offset = totsize;
        }

        if ((addr >= ifr.pflashIfr0Start) && ((addr + size) <= (ifr.pflashIfr0Start + ifr.pflashIfr0MemSize)))
        {
            return i;
        }

        totsize += ifr.pflashIfr0MemSize;
    }

    return -1;
}

static int flash_array_idx(flash_config_t *config, uint32_t addr, uint32_t size, uint32_t *offset)
{
    uint32_t totsize = 0;

    for (int i = 0; i < ARRAY_SIZE(config->flash); i++)
    {
        flash_mem_desc_t flash = config->flash[i].flashDesc;

        if (offset)
        {
            *offset = totsize;
        }

        if ((addr >= flash.blockBase) && ((addr + size) <= (flash.blockBase + flash.totalSize)))
        {
            return i;
        }

        totsize += flash.totalSize;
    }

    return -1;
}


static status_t flash_check_param(
    flash_config_t *config, FMU_Type *base, uint32_t start, uint32_t lengthInBytes, uint32_t alignmentBaseline, addr_info_t *addrInfo)
{
    status_t status   = kStatus_FLASH_InvalidArgument;
    FMU_Type *baseTmp = (FMU_Type *)((uint32_t)base & FLASH_ADDR_MASK);

    if (lengthInBytes == 0U)
    {
        status = kStatus_FLASH_Success;
    }
    else if (config == NULL || base == NULL || baseTmp != FLASH)
    {
        status = kStatus_FLASH_InvalidArgument;
    }
    else if ((alignmentBaseline > 0U) && ((start & (alignmentBaseline - 1U)) != 0u))
    {
        /* Verify the start is alignmentBaseline aligned. */
        status = kStatus_FLASH_AlignmentError;
    }
    else
    {
        start = start & FLASH_ADDR_MASK;

        if (baseTmp == FLASH)
        {
            /* Validate the range for main flash */

            uint32_t offset = 0;
            int idx = flash_array_idx(config, start, lengthInBytes, &offset);

            if (idx >= 0)
            {
                if (addrInfo)
                {
                    addrInfo->arrayIdx = idx;
                    addrInfo->flashType = flashType_main;
                    addrInfo->baseAddr = config->flash[idx].flashDesc.blockBase;
                    /* Internally both flash arrays are considered as a continuous space */
                    addrInfo->physAddr = start - config->flash[idx].flashDesc.blockBase + offset;
                }
                return kStatus_FLASH_Success;
            }

            /* Validate the range for IFR_0 flash */

            idx = ifr_array_idx(config, start, lengthInBytes, &offset);

            if (idx >= 0)
            {
                if (addrInfo)
                {
                    addrInfo->arrayIdx = idx;
                    addrInfo->flashType = flashType_ifr0;
                    addrInfo->baseAddr = config->flash[idx].ifrDesc.pflashIfr0Start;
                    /* Internally both IFR_0's are considered as a continuous space */
                    addrInfo->physAddr = start - config->flash[idx].ifrDesc.pflashIfr0Start + offset;
                }

                return kStatus_FLASH_Success;
            }

            return kStatus_FLASH_AddressError;
        }
    }

    return status;
}

/*! @brief Validates the given user key for flash erase APIs.*/
static status_t flash_check_user_key(uint32_t key)
{
    status_t status = kStatus_Fail;

    /* Validate the user key */
    if (key != (uint32_t)kFLASH_ApiEraseKey)
    {
        status = kStatus_FLASH_EraseKeyError;
    }
    else
    {
        status = kStatus_FLASH_Success;
    }

    return status;
}
