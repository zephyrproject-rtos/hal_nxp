/*
 * Copyright 2025 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/*
    Version 1.1.0:
        - Generic setup for entire family

    Version 1.0.0:
        - Support for Erase and Write
        - Basic support for Sector Locking
        - Setup only for CPU_MCXE31BMPB
        - No UTest flash block support
        - No PFCBLKx_SETSLOCK & PFCBLKx_LOCKMASTER_Sy support (locking by Core Domain ID)
*/

#include "fsl_c40_flash.h"
#include "fsl_common.h"
#include "fsl_device_registers.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.flash_c40"
#endif

/* Functions that trigger Erase/Write operation must be placed in RAM */
#if defined(__IAR_SYSTEMS_ICC__)
#define RAMFUNC __ramfunc
#elif defined(__GNUC__)
#define RAMFUNC __attribute__((section(".ramfunc"))) __attribute__((__noinline__))
#else
#error "Unsupported toolchain"
#endif


/* Flash size parameters that differ across devices*/

#define C40_BLOCK_SIZE_CODE    FSL_FEATURE_FLASH_C40_BLOCK_SIZE_CODE
#define C40_BLOCK_SIZE_DATA    FSL_FEATURE_FLASH_C40_BLOCK_SIZE_DATA
#define C40_BLOCK_COUNT_CODE   FSL_FEATURE_FLASH_C40_BLOCK_COUNT_CODE


/* Common definitions for entire family */

#define C40_BLOCK_COUNT_DATA     (1)

#define C40_BASE_ADDR_CODE       (0x00400000)
#define C40_END_ADDR_CODE        (C40_BASE_ADDR_CODE + (C40_BLOCK_SIZE_CODE * C40_BLOCK_COUNT_CODE) - 1)

#define C40_BASE_ADDR_DATA       (0x10000000)
#define C40_END_ADDR_DATA        (C40_BASE_ADDR_DATA + (C40_BLOCK_SIZE_DATA * C40_BLOCK_COUNT_DATA) - 1)


#define C40_SECTOR_SIZE        ( 8 * 1024)
#define C40_SUPER_SECTOR_SIZE  (64 * 1024)

#define C40_SECTORS_IN_SUPER_SECTOR (C40_SUPER_SECTOR_SIZE / C40_SECTOR_SIZE)

/*
 * RM, PFLASH chapter:
 * For 512 KB blocks, the first half of the block is protected with super sector granularity.
 * For 1 MB blocks, the first 768 KB is protected with super sector granularity.
 */

#if FSL_FEATURE_FLASH_C40_BLOCK_SIZE_CODE == (1024 * 1024)

#define C40_MAX_SUPER_SECTOR_BLOCK_AREA (768 * 1024)

#elif FSL_FEATURE_FLASH_C40_BLOCK_SIZE_CODE == (512 * 1024)

#define C40_MAX_SUPER_SECTOR_BLOCK_AREA (512 * 1024)

#else
#error "Unexpected flash block size"
#endif


#define C40_NUM_SECTORS_PER_BLOCK_CODE    (C40_BLOCK_SIZE_CODE / C40_SECTOR_SIZE)
#define C40_NUM_SECTORS_PER_BLOCK_DATA    (C40_BLOCK_SIZE_DATA / C40_SECTOR_SIZE)

#define C40_SECTOR_COUNT_CODE    (C40_BLOCK_COUNT_CODE * C40_NUM_SECTORS_PER_BLOCK_CODE)
#define C40_SECTOR_COUNT_DATA    (C40_BLOCK_COUNT_DATA * C40_NUM_SECTORS_PER_BLOCK_DATA)
#define C40_SECTOR_COUNT_TOTAL   (C40_SECTOR_COUNT_CODE + C40_SECTOR_COUNT_DATA)


#define C40_PAGE_SIZE            (32)
#define C40_QUAD_PAGE_SIZE       (4 * C40_PAGE_SIZE)

#define C40_WRITE_ALIGNMENT      (8)
#define C40_WRITE_SIZE_MIN       (8)
#define C40_WRITE_SIZE_MAX       C40_QUAD_PAGE_SIZE


#define LOGADDR_IN_CODE_REGION(a) ((a) >= C40_BASE_ADDR_CODE && (a) <= C40_END_ADDR_CODE)
#define LOGADDR_IN_DATA_REGION(a) ((a) >= C40_BASE_ADDR_DATA && (a) <= C40_END_ADDR_DATA)


/* The driver partly works with Core Domain ID support.
 * This is mainly used for sector locking for a particular core. For a single core device
 * this might not be needed. The support is not yet fully implemented.
 */
#define C40_DEFAULT_CORE_DOMAIN_ID    (0)


/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Private Code
 ******************************************************************************/

/*
 * @brief Abort ongoing Program/Erase operation
 */

static status_t C40_AbortProgramErase(void)
{
    /* Disable HV to finalize/abort the operation */
    FLASH->MCR &= ~FLASH_MCR_EHV_MASK;

    while (0U == (FLASH->MCRS & FLASH_MCRS_DONE_MASK))
    {
        ;
    }

    /* Clear ERS and PGM bits */
    FLASH->MCR &= ~(FLASH_MCR_PGM_MASK|FLASH_MCR_ESS_MASK|FLASH_MCR_ERS_MASK);

    return kStatus_FLASH_Success;
}


/*
 * @brief Clear all error flags in C40 IP
 */

static inline void C40_ClearAllErrorFlags(void)
{
    /** Clear all error flags for main interface */
    FLASH->MCRS &= FLASH_MCRS_EER_MASK |  \
                   FLASH_MCRS_SBC_MASK |  \
                   FLASH_MCRS_AEE_MASK |  \
                   FLASH_MCRS_EEE_MASK |  \
                   FLASH_MCRS_RVE_MASK |  \
                   FLASH_MCRS_RRE_MASK |  \
                   FLASH_MCRS_RWE_MASK |  \
                   FLASH_MCRS_PES_MASK |  \
                   FLASH_MCRS_PEP_MASK;
}

/*
 * @brief Initializes registers and clears context
 */

static status_t C40_Init(void)
{
    status_t ret;

    ret = C40_AbortProgramErase();

    /* Disable watchdog interrupt */
    FLASH->MCR &= ~FLASH_MCR_WDIE_MASK;
    /* No interrupt request will be generated when the DONE flag is set*/
    FLASH->MCR &= ~FLASH_MCR_PECIE_MASK;

    C40_ClearAllErrorFlags();

    return ret;
}

/*
 * @brief Translates sector number to sector address
 *
 * @param sectorNum       Sector number
 * @param sectorAddress   Sector address derived from the sector number
 *
 * @retval kStatus_FLASH_Success         Sector number translation was ok
 * @retval kStatus_FLASH_AddressError    Sanity check failed
 *
 */

static status_t C40_SectorNumToAddr(uint32_t sectorNum, uint32_t *sectorAddress)
{
    uint32_t address;

    if (sectorNum >= C40_SECTOR_COUNT_TOTAL)
    {
        return kStatus_FLASH_AddressError;
    }

    /* Sector belongs to CODE flash */
    if (sectorNum < C40_SECTOR_COUNT_CODE)
    {
        address = C40_BASE_ADDR_CODE + (sectorNum * C40_SECTOR_SIZE);
    }
    /* Sector belongs to DATA flash */
    else if (sectorNum >= C40_SECTOR_COUNT_CODE)
    {
        address = C40_BASE_ADDR_DATA + ((sectorNum - C40_SECTOR_COUNT_CODE) * C40_SECTOR_SIZE);
    }

    if (sectorAddress)
    {
        *sectorAddress = address;
    }

    return kStatus_FLASH_Success;
}

/*
 * @brief Translates address to belonging sector number
 *
 * @param address         Address of code or data flash region
 * @param sectorNum       Coresponding sector number
 *
 * @retval kStatus_FLASH_Success         Address translation was ok
 * @retval kStatus_FLASH_AddressError    Sanity check failed
 *
 */

static status_t C40_AddrToSectorNum(uint32_t address, uint32_t *sectorNum)
{
    uint32_t sector;

    if (LOGADDR_IN_CODE_REGION(address))
    {
        /* CODE flash */
        sector = (address - C40_BASE_ADDR_CODE) / C40_SECTOR_SIZE;
    }
    else if (LOGADDR_IN_DATA_REGION(address))
    {
        /* DATA flash */
        sector = (address - C40_BASE_ADDR_DATA) / C40_SECTOR_SIZE;
        sector += C40_SECTOR_COUNT_CODE;
    }
    else
    {
        return kStatus_FLASH_AddressError;
    }

    if (sectorNum)
    {
        *sectorNum = sector;
    }

    return kStatus_FLASH_Success;
}

/*
 * @brief Translates sector number to corresponding flash lock register and sector index in it
 *
 * @param sectorNum        Sector number
 * @param lockSectorIndex  Sector index in the PFCBLK_*LOCK* registers
 * @param lockSectorReg    Pointer to corresponsing PFCBLK_*LOCK* register
 *
 * @retval kStatus_FLASH_Success          Successfull translation
 * @retval kStatus_FLASH_AddressError     Sector translates to wrong address
 *
 */

static status_t C40_LockSectorIndex(uint32_t sectorNum, uint32_t *lockSectorIndex, volatile uint32_t **lockSectorReg)
{
    uint32_t index;
    volatile uint32_t *reg;

    if (sectorNum >= C40_SECTOR_COUNT_TOTAL)
    {
        return kStatus_FLASH_AddressError;
    }


    if (sectorNum >= C40_SECTOR_COUNT_CODE)
    {
        /* DATA Flash */

        /* Data flash has no Super Sectors */
        index = sectorNum - C40_SECTOR_COUNT_CODE;

        /* Locking register for the data flash is the last one */
        reg = &(PFLASH->PFCBLK_SPELOCK[C40_BLOCK_COUNT_CODE]);
    }
    else
    {
        /* CODE Flash */

        /* Sector position within a block */
        uint32_t sectorIdInBlock = sectorNum % C40_NUM_SECTORS_PER_BLOCK_CODE;

        /* Flash block number for given sector */
        uint32_t blockId = sectorNum / C40_NUM_SECTORS_PER_BLOCK_CODE;

        /* Test if lock sector is within super sector area */

        if ((sectorIdInBlock * C40_SECTOR_SIZE) < C40_MAX_SUPER_SECTOR_BLOCK_AREA)
        {
            /* Scale to Super Sector */
            index = sectorIdInBlock / C40_SECTORS_IN_SUPER_SECTOR;

            /* Locking register for Super Sectors */
            reg = &(PFLASH->PFCBLK_SSPELOCK[blockId]);
        }
        else
        {
            /* Beyond Super Sector area, normal sector granularity */
            index = sectorIdInBlock - (C40_MAX_SUPER_SECTOR_BLOCK_AREA / C40_SECTOR_SIZE);

            /* Locking register for normal sectors */
            reg = &(PFLASH->PFCBLK_SPELOCK[blockId]);
        }
    }

    if (lockSectorIndex)
    {
        *lockSectorIndex = index;
    }
    if (lockSectorReg)
    {
        *lockSectorReg = reg;
    }

    return kStatus_FLASH_Success;
}


static status_t C40_SectorLockSet(uint32_t sectorNum, bool locked, bool verify)
{
    status_t ret;
    uint32_t lockSectorIndex;
    uint32_t origValue;
    volatile uint32_t *lockSectorRegister;

    ret = C40_LockSectorIndex(sectorNum, &lockSectorIndex, &lockSectorRegister);
    if (ret != kStatus_FLASH_Success)
    {
        return ret;
    }

    origValue = *lockSectorRegister;

    if (locked)
    {

        *lockSectorRegister |= (1 << lockSectorIndex);
    }
    else
    {
        *lockSectorRegister &= ~(1 << lockSectorIndex);
    }

    if (verify && (origValue ^ *lockSectorRegister) == 0)
    {
        /* No change, something failed */
        return kStatus_FLASH_CommandFailure;
    }

    return kStatus_FLASH_Success;
}


/*
 * @brief Determines lock status of selected sector
 *
 * @param sectorNum       Sector number
 *
 * @retval kStatus_FLASH_SectorUnlocked   Sector is locked
 * @retval kStatus_FLASH_SectorLocked     Sector is unlocked
 * @retval kStatus_FLASH_AddressError     Sector translates to wrong address
 *
 */

static status_t C40_SectorLockStatus(uint32_t sectorNum)
{
    status_t ret;
    uint32_t lockSectorIndex;
    volatile uint32_t *lockSectorRegister;

    ret = C40_LockSectorIndex(sectorNum, &lockSectorIndex, &lockSectorRegister);
    if (ret != kStatus_FLASH_Success)
    {
        return ret;
    }

    if (*lockSectorRegister & (1 << lockSectorIndex))
    {
        return kStatus_FLASH_SectorLocked;
    }
    else
    {
        return kStatus_FLASH_SectorUnlocked;
    }
}


/*
 * @brief Function used to setup flash operation address
 *
 * @param address           Logical address of flash operation
 * @param callerDomainId    Domain ID of the caller
 *
 * @retval kStatus_FLASH_Success    Address was written and callerDomainId synced
 */

static status_t C40_WriteJobAddress(uint32_t address, uint8_t callerDomainId)
{
    uint8_t currentId;

    /* This is used to synchronize potential multiple callers/cores that request flash
       operations.
     */

    do
    {
        PFLASH->PFCPGM_PEADR_L = address;
        currentId = (FLASH->MCR & FLASH_MCR_PEID_MASK) >> FLASH_MCR_PEID_SHIFT;
    }
    while (currentId != callerDomainId);

    return kStatus_FLASH_Success;
}


/*
 * @brief Checks the status of ongoing flash Erase/Program operation
 *
 * @retval kStatus_FLASH_Success                Flash operation successfully terminated
 * @retval kStatus_FLASH_OperationInProgress    Flash operation still in progress
 * @retval kStatus_FLASH_CommandFailure         Flash operation failed
 */

RAMFUNC static status_t C40_ProgramEraseStatus(void)
{
    if ((FLASH->MCRS & FLASH_MCRS_DONE_MASK) == 0)
    {
        return kStatus_FLASH_OperationInProgress;
    }
    else
    {
        uint32_t flags = FLASH->MCRS & (FLASH_MCRS_PEG_MASK | FLASH_MCRS_PEP_MASK | FLASH_MCRS_PES_MASK);

        /* Program/Erase Good: only PEG = 1; both PEP and PES should be 0 */
        if (flags == FLASH_MCRS_PEG_MASK)
        {
            return kStatus_FLASH_Success;
        }
        else
        {
            return kStatus_FLASH_CommandFailure;
        }
    }
}


/*
 * @brief Initiates erase opearation and blocks until finished
 *
 * This function must run in RAM - therefore marked as RAMFUNC
 *
 * @retval kStatus_FLASH_Success                Flash operation successfully terminated
 * @retval kStatus_FLASH_CommandFailure         Flash operation failed
 */

RAMFUNC static status_t C40_SectorEraseStartAndWait(void)
{
    status_t ret;

    /* One and only one ADATA register must also be written. This is referred to as an erase interlock write.*/
    FLASH->DATA[0] = 0xFFFFFFFFU;
    /* Setup erase operation */
    FLASH->MCR |= FLASH_MCR_ERS_MASK;
    /* Flash memory erase will be on a sector */
    FLASH->MCR &= ~FLASH_MCR_ESS_MASK;
    /* start internal erase sequence */
    FLASH->MCR |= FLASH_MCR_EHV_MASK;

    /* block until finished */
    do
    {
        ret = C40_ProgramEraseStatus();
    }
    while (ret == kStatus_FLASH_OperationInProgress);

    /* terminate erase operation */
    FLASH->MCR &= ~FLASH_MCR_EHV_MASK;
    FLASH->MCR &= ~FLASH_MCR_ERS_MASK;

    return ret;
}


/*
 * @brief Erases a single sector
 *
 * The sector number is counted from the first block and zero sector.
 *
 * @param sectorNum         Sector number to be erased
 * @param callerDomainId    Domain ID of the caller
 */
static status_t C40_SectorErase(uint32_t sectorNum, uint8_t callerDomainId)
{
    status_t ret;
    uint32_t address;

    if (sectorNum >= C40_SECTOR_COUNT_TOTAL)
    {
        return kStatus_FLASH_AddressError;
    }

    /* Verify that there is no other job in progress */
    if (FLASH->MCR & (FLASH_MCR_ERS_MASK | FLASH_MCR_PGM_MASK))
    {
        return kStatus_FLASH_OperationInProgress;
    }

    /* Check the lock bit */
    if (C40_SectorLockStatus(sectorNum) != kStatus_FLASH_SectorUnlocked)
    {
        return kStatus_FLASH_ProtectionViolation;
    }

    C40_ClearAllErrorFlags();

    /* Address of the sector to be erased */
    ret = C40_SectorNumToAddr(sectorNum, &address);
    if (ret != kStatus_FLASH_Success)
    {
        return ret;
    }

    /* Write the address to be erased */
    C40_WriteJobAddress(address, callerDomainId);

    ret = C40_SectorEraseStartAndWait();

    return ret;
}


/*
 * @brief Fills internal DATA registers with data to be written
 *
 * @param dataRegIndex    Index of first DATA register to be used
 * @param src             Pointer to data to written
 * @param length          Data length in bytes
 */

static void C40_FillDataBuff(uint32_t dataRegIndex, const uint8_t *src, uint32_t length)
{
    assert(dataRegIndex < FLASH_DATA_COUNT);
    assert(dataRegIndex + (length/4) < FLASH_DATA_COUNT);

    const uint32_t *src32 = (const uint32_t *) src;
    const uint8_t  *src8  = src;
    uint32_t written = 0;
    volatile uint32_t dataTemp32;  /* Prevent compiler optimization when working with unaligned addresses */

    do
    {
        if (((uint32_t)src % 4) == 0)
        {
            /* 4 byte aligned source data */
            FLASH->DATA[dataRegIndex] = *src32;
            src32++;
        }
        else
        {
            /* unaligned source data -> byte access */
            dataTemp32  = (uint32_t)src8[0] <<  0;
            dataTemp32 |= (uint32_t)src8[1] <<  8;
            dataTemp32 |= (uint32_t)src8[2] << 16;
            dataTemp32 |= (uint32_t)src8[3] << 24;
            FLASH->DATA[dataRegIndex] = dataTemp32;
            src8 += 4;
        }

        dataRegIndex++;
        written += 4;
    }
    while (written < length);

}

/*
 * @brief Initiates program operation and blocks until finished
 *
 * This function must run in RAM - therefore marked as RAMFUNC
 *
 * @retval kStatus_FLASH_Success                Flash operation successfully terminated
 * @retval kStatus_FLASH_CommandFailure         Flash operation failed
 */

RAMFUNC static status_t C40_WriteStartAndWait(void)
{
    status_t ret;

    /* Setup program operation */
    FLASH->MCR |= FLASH_MCR_PGM_MASK;
    FLASH->MCR |= FLASH_MCR_EHV_MASK;

    /* block until finished */
    do
    {
        ret = C40_ProgramEraseStatus();
    }
    while (ret == kStatus_FLASH_OperationInProgress);

    /* Terminate program operation */
    FLASH->MCR &= ~FLASH_MCR_EHV_MASK;
    FLASH->MCR &= ~FLASH_MCR_PGM_MASK;

    return ret;
}


/*
 * @brief Programs flash with specified data
 *
 * @param address          Destination address for data being written. Must be 8byte aligned.
 * @param length           Size of data in bytes. Must be 8byte aligned.
 * @param source           Source address of data.
 * @param callerDomainId   DomainId of the calling core.
 *
 * @retval kStatus_FLASH_Success           Flash operation successfully terminated
 * @retval kStatus_FLASH_CommandFailure    Flash operation failed
 * @retval kStatus_FLASH_AddressError      Sector translates to wrong address
 */

static status_t C40_Write(uint32_t address, uint32_t length, const uint8_t *source, uint8_t callerDomainId)
{
    status_t ret;
    uint32_t sector;
    uint32_t dataRegIndex;
    uint32_t quadPageOffset = address % C40_QUAD_PAGE_SIZE;

    /* Translate to sector number, this also validates address */

    ret = C40_AddrToSectorNum(address, &sector);
    if (ret != kStatus_FLASH_Success)
    {
        return ret;
    }

    if (length == 0 || length > C40_QUAD_PAGE_SIZE)
    {
        return kStatus_FLASH_InvalidArgument;
    }

    /* Alignment and size constraints */

    /* RM:
     * It is recommended that all programming operations range from 64 bits to 1024 bits, and be 64-bit aligned.
     * The programming operation should completely fill selected ECC segments within the page.
     * Only one program is allowed per 64-bit ECC segment between erases.
     *
     * Values may be programmed in any or all of eight words, within a page, with a single program sequence.
     * Up to four pages can be programmed at once on a quad-page boundary.
     */

    if ((address % C40_WRITE_ALIGNMENT) != 0  ||
        (length % C40_WRITE_ALIGNMENT)  != 0  ||
        (quadPageOffset + length)       > C40_QUAD_PAGE_SIZE)
    {
        return kStatus_FLASH_AlignmentError;
    }

    /* Verify that EHV may be set */
    if ((FLASH->MCR & (FLASH_MCR_ERS_MASK | FLASH_MCR_PGM_MASK)) != 0)
    {
        return kStatus_FLASH_OperationInProgress;
    }

    /* Check lock bit of the targeted sector */

    if (C40_SectorLockStatus(sector) == kStatus_FLASH_SectorLocked)
    {
        return kStatus_FLASH_ProtectionViolation;
    }

    C40_ClearAllErrorFlags();
    C40_WriteJobAddress(address, callerDomainId);

    /*
     * Actual start location needs to be written to DATA registers (DATA[0], DATA[1] ..)
     * Ex: if LogicalAddress = 0 it means that data (of LogicalAddress 0->3) will be written starting from the DATA[0] register.
     *     if LogicalAddress = 4 it means that data (of LogicalAddress 4->7) will be written starting from the DATA[1] register.
     */

    /* Index of first DATA register to be used for write */

    dataRegIndex = (address % C40_WRITE_SIZE_MAX) / 4;

    /* Fill the data into hardware buffer */
    C40_FillDataBuff(dataRegIndex, source, length);

    ret = C40_WriteStartAndWait();

    return ret;
}


/*******************************************************************************
 * Public Code
 ******************************************************************************/

status_t FLASH_Init(flash_config_t *config)
{
    status_t ret;

    ret = C40_Init();

    /* Init config structure */

    if (config == NULL)
    {
        return kStatus_FLASH_InvalidArgument;
    }

    /* No UTest support, verify it's not enabled */

    if ((FLASH->UT0 & FLASH_UT0_UTE_MASK) != 0)
    {
        return kStatus_FLASH_NotSupported;
    }

    config->PFlashBlockBase = C40_BASE_ADDR_CODE;
    config->PFlashBlockCount = C40_BLOCK_COUNT_CODE;
    config->PFlashTotalSize = C40_BLOCK_COUNT_CODE * C40_BLOCK_SIZE_CODE;
    config->PFlashSectorSize = C40_SECTOR_SIZE;

    config->DataFlashSize = C40_BLOCK_COUNT_DATA * C40_BLOCK_SIZE_DATA;
    config->DataFlashBase = C40_BASE_ADDR_DATA;

    return ret;
}

status_t FLASH_Erase(flash_config_t *config, uint32_t start, uint32_t lengthInBytes, uint32_t key)
{
    status_t ret;
    uint32_t sectorNumStart;
    uint32_t sectorCount = lengthInBytes / C40_SECTOR_SIZE;

    if (config == NULL)
    {
        return kStatus_FLASH_InvalidArgument;
    }

    /* address must be within CODE or DATA flash block */

    if (!LOGADDR_IN_CODE_REGION(start) && !LOGADDR_IN_DATA_REGION(start))
    {
        return kStatus_FLASH_AddressError;
    }

    /* address and length must be sector aligned */

    if ((start % C40_SECTOR_SIZE) != 0 || (lengthInBytes % C40_SECTOR_SIZE) != 0)
    {
        return kStatus_FLASH_AlignmentError;
    }

    /* check the erase key */
    if (key != kFLASH_ApiEraseKey)
    {
        return kStatus_FLASH_EraseKeyError;
    }

    ret = C40_AddrToSectorNum(start, &sectorNumStart);
    if (ret != kStatus_FLASH_Success)
    {
        return ret;
    }

    for (uint32_t i=0; i < sectorCount; i++)
    {
        ret = C40_SectorErase(sectorNumStart + i, C40_DEFAULT_CORE_DOMAIN_ID);
        if (ret != kStatus_FLASH_Success)
        {
            return ret;
        }
    }

    return ret;
}

status_t FLASH_Program(flash_config_t *config, uint32_t start, uint32_t *src, uint32_t lengthInBytes)
{
    status_t ret;
    size_t chunkSize;
    size_t sizeLeft = lengthInBytes;
    uint8_t *src8 = (uint8_t *) src;
    uint32_t addr = start;

    if (config == NULL)
    {
        return kStatus_FLASH_InvalidArgument;
    }

    /* allow for multiple quad-page writes */

    /* if start address isn't quad-page aligned, program this chunk first */

    if ((addr % C40_WRITE_SIZE_MAX) > 0)
    {
        uint32_t bytesToAlignedPage = C40_WRITE_SIZE_MAX - (addr % C40_WRITE_SIZE_MAX);

        chunkSize = (sizeLeft > bytesToAlignedPage) ? bytesToAlignedPage : sizeLeft;

        ret = C40_Write(start, lengthInBytes, src8, C40_DEFAULT_CORE_DOMAIN_ID);
        if (ret != kStatus_FLASH_Success)
        {
            return ret;
        }

        sizeLeft -= chunkSize;
        src8     += chunkSize;
    }

    /* continue with aligned writes */

    while (sizeLeft > 0)
    {

        chunkSize = (sizeLeft > C40_WRITE_SIZE_MAX) ? C40_WRITE_SIZE_MAX : sizeLeft;

        ret = C40_Write(start, lengthInBytes, src8, C40_DEFAULT_CORE_DOMAIN_ID);
        if (ret != kStatus_FLASH_Success)
        {
            return ret;
        }

        sizeLeft -= chunkSize;
        src8     += chunkSize;
    }

    return ret;
}

status_t FLASH_SetSectorProtection(flash_config_t *config, uint32_t address, bool locked)
{
    status_t ret;
    uint32_t sectorNum;

    (void) config;

    ret = C40_AddrToSectorNum(address, &sectorNum);
    if (ret != kStatus_FLASH_Success)
    {
        return ret;
    }

    return C40_SectorLockSet(sectorNum, locked, true);
}

status_t FLASH_GetSectorProtection(flash_config_t *config, uint32_t address)
{
    status_t ret;
    uint32_t sectorNum;

    (void) config;

    ret = C40_AddrToSectorNum(address, &sectorNum);
    if (ret != kStatus_FLASH_Success)
    {
        return ret;
    }

    return C40_SectorLockStatus(sectorNum);
}