/*
 * Copyright 2023-2024 NXP
 *
 * All rights reserved.
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_mmu.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.mmu"
#endif

#define MMU_UNIT_BYTE_SIZE       (0x1000UL << (uint32_t)(g_selectedUnitSize))

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/*!
 * brief Get the MMU instance from the peripheral base address.
 *
 * param base MMU peripheral base address.
 * return MMU instance.
 */
static uint32_t MMU_GetInstance(MMU_Type *base);
#endif

static mmu_lut_word_t MMU_TransferAddrToLUTWord(uint32_t addr);
static uint16_t MMU_TransferAddrToLUTIndex(uint32_t addr);
/*******************************************************************************
 * Variables
 ******************************************************************************/
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
static MMU_Type *const s_mmuBases[] = MMU_BASE_PTRS;

static const clock_ip_name_t s_mmuClock[] = MMU_CLOCKS;
#endif

mmu_unit_size_t g_selectedUnitSize = kMMU_UnitSize4KB;
mmu_page_option_t g_selectedPageOpt = kMMU_PageOpt_1Page;
/*******************************************************************************
 * Code
 ******************************************************************************/

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/*!
 * brief Get the MMU instance from the peripheral base address.
 *
 * param base MMU peripheral base address.
 * return MMU instance.
 */
static uint32_t MMU_GetInstance(MMU_Type *base)
{
    uint32_t instance = 0UL;

    for (instance = 0UL; instance < ARRAY_SIZE(s_mmuBases); instance++)
    {
        if (MSDK_REG_SECURE_ADDR(s_mmuBases[instance]) == MSDK_REG_SECURE_ADDR(base))
        {
            break;
        }
    }

    assert(instance < ARRAY_SIZE(s_mmuBases));

    return instance;
}
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

static mmu_lut_word_t MMU_TransferAddrToLUTWord(uint32_t addr)
{
    uint32_t maskPerUnitSize[MMU_NUM_OF_UNIT_SIZE] = 
    {
        0x7FFF000UL,    /* Mask for 4KB unit size. */
        0xFFFE000UL,    /* Mask for 8KB unit size. */
        0xFFFC000UL,    /* Mask for 16KB unit size. */
        0xFFF8000UL,    /* Mask for 32KB unit size. */
        0xFFF0000UL,    /* Mask for 64KB unit size. */
    };

    uint32_t shiftPerUnitSize[MMU_NUM_OF_UNIT_SIZE] = 
    {
        12UL,       /* Shift for 4KB unit size. */
        13UL,       /* Shift for 8KB unit size. */
        14UL,       /* Shift for 16KB unit size. */
        15UL,       /* Shift for 32KB unit size. */
        16UL,       /* Shift for 64KB unit size. */
    };
    mmu_lut_word_t lutWord;
    uint8_t unitSizeIndex = (uint8_t)g_selectedUnitSize;

    lutWord.mappedValue = (uint16_t)((addr & maskPerUnitSize[unitSizeIndex]) >> shiftPerUnitSize[unitSizeIndex]);
    lutWord.valid = 1U;

    return lutWord;
}

static uint16_t MMU_TransferAddrToLUTIndex(uint32_t addr)
{
    uint32_t maskPerUnitSize[2U][MMU_NUM_OF_UNIT_SIZE] =
    {
        {
            0x1FFFFFFUL,        /* Mask for 4KB unit size, in 1 page mode  */
            0x3FFFFFFUL,        /* Mask for 8KB unit size, in 1 page mode */
            0x7FFFFFFUL,        /* Mask for 16KB unit size, in 1 page mode */
            0xFFFFFFFUL,        /* Mask for 32KB unit size, in 1 page mode */
            0x1FFFFFFFUL,       /* Mask for 64KB unit size, in 1 page mode */
        },
        {
            0x7FFFFFUL,         /* Mask for 4KB unit size, in 4 page mode. */
            0xFFFFFFUL,         /* Mask for 8KB unit size, in 4 page mode. */
            0x1FFFFFFUL,        /* Mask for 16KB unit size, in 4 page mode. */
            0x3FFFFFFUL,        /* Mask for 32KB unit size, in 4 page mode. */
            0x7FFFFFFUL,        /* Mask for 64KB unit size, in 4 page mode. */
        },
    };

    uint32_t factorPerUnitSize[MMU_NUM_OF_UNIT_SIZE] = 
    {
        0x1000UL,            /* Factor for 4KB unit size.  */
        0x2000UL,            /* Factor for 8KB unit size.  */
        0x4000UL,            /* Factor for 16KB unit size.  */
        0x8000UL,            /* Factor for 32KB unit size.  */
        0x10000UL,           /* Factor for 64KB unit size.  */
    };

    uint8_t unitSizeIndex = (uint8_t)g_selectedUnitSize;
    uint16_t lutPointer = 0U;
    uint8_t pageMode = (g_selectedPageOpt == kMMU_PageOpt_1Page) ? 0U : 1U;


    lutPointer = (addr & maskPerUnitSize[pageMode][unitSizeIndex]) / factorPerUnitSize[unitSizeIndex];
    if (pageMode != 0U)
    {
        uint8_t pageSelect = ((uint8_t)g_selectedPageOpt) & 0x6U >> 1U;
        lutPointer |= pageSelect << 11U;
    }

    return lutPointer;
}

/*!
 * brief Initialize MMU:
 *          1. Enable MMU clock;
 *          2. Define the basic unit that is used in the memory map;
 *          3. Configure valid address range;
 *          4. Fill LUT SRAM;
 *          5. Enable MMU remap function.
 *
 * param base MMU peripheral base address.
 * param config Pointer to the user defined variable in type of mmu_config_t.
 */
void MMU_Init(MMU_Type *base, const mmu_config_t *config)
{
    assert(config);

    /* 1. Enable MMU clock */
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    CLOCK_EnableClock(s_mmuClock[MMU_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
    MMU_DoSoftwareReset(base);
    base->CTRL &= ~MMU_CTRL_CLK_DIS_MASK;

    /* 2. Configure unit size to define the basic unit that is used in the memory map. */
    MMU_UpdateUnitSize(base, config->unitSize);
    MMU_ChangePageOption(base, config->pageOpt);

    /* 3. Configure valid address range. */
    MMU_UpdateValidAddressRange(base, config->baseAddr, config->maxAddr);

    /* 4. Fill LUT SRAM. */
    if ((config->ptrPhyAddrArray != NULL) && (config->ptrVirtualAddrArray != NULL))
    {
        MMU_SetupArrayMap(base, config->ptrVirtualAddrArray, config->ptrPhyAddrArray, config->countOfAddr);
    }

    /* 5. Enable MMU remap function. */
    MMU_EnableMemoryMap(base, config->enableMMP);
}

/*!
 * brief De-initialize MMU:
 *          1. Disable MMU remap function;
 *          2. Reset MMU logic;
 *          3. Disable MMU clock.
 * param base
 */
void MMU_Deinit(MMU_Type *base)
{
    /* 1. Disable MMU remap function. */
    MMU_EnableMemoryMap(base, false);

    /* 2. Reset MMU logic. */
    MMU_DoSoftwareReset(base);

    /* 3. Disable MMU clock. */
    base->CTRL |= MMU_CTRL_CLK_DIS_MASK;
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    CLOCK_DisableClock(s_mmuClock[MMU_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

/*!
 * brief Get default configurations of MMU module.
 *
 * code
 *    config->unitSize        = kMMU_UnitSize4KB;
 *    config->pageOpt        = kMMU_PageOpt_1Page;
 *    config->invalidAddrMode = kMMU_InvalidAddrRespondError;
 *    config->baseAddr = 0x0UL;
 *    config->maxAddr  = 0x0UL;
 *    config->ptrPhyAddrArray = NULL;
 *    config->ptrVirtualAddrArray = NULL;
 *    config->countOfPhyAddr = 0U;
 *    config->enableMMP = false;
 * endcode
 *
 * param config Pointer to the user defined variable in type of mmu_config_t.
 */
void MMU_GetDefaultConfig(mmu_config_t *config)
{
    assert(config);

    config->unitSize        = kMMU_UnitSize4KB;
    config->pageOpt        = kMMU_PageOpt_1Page;
    config->invalidAddrMode = kMMU_InvalidAddrRespondError;

    config->baseAddr = 0x0UL;
    config->maxAddr  = 0x0UL;

    config->ptrPhyAddrArray = NULL;
    config->ptrVirtualAddrArray = NULL;
    config->countOfAddr = 0U;

    config->enableMMP = false;
}

/*!
 * brief Assert software reset to reset the MMU logic.
 *
 * param base MMU peripheral base address.
 */
void MMU_DoSoftwareReset(MMU_Type *base)
{
    /* Reset MMU logic. */
    base->CTRL |= MMU_CTRL_SWRST_MASK;

    /* Delay six NOP cycles for reset propagation. */
    for (uint8_t i = 0U; i < 6U; i++)
    {
        __NOP();
    }

    /* Disable software reset. */
    base->CTRL &= ~MMU_CTRL_SWRST_MASK;
}

/*!
 * brief Use the blocking method to update LUT SRAM with user-defined words.
 *
 * note This function only return when all words that #ptrLutWord refers are set into LUT SRAM.
 *
 * note This function supports both single write and burst write described in RM, please note that burst write is only
 * useful when to fill continuous value into continuous addresses.
 *
 * note #startPointer + #countOfWords should not exceed the maximum size of LUT SRAM(8192).
 * code
 * Fill continuous values into continuous addresses (E.g: initialize LUT SRAM address 2 and 3 with value 0x12 and 0x13)
 *              mmu_lut_word_t    startLutWord = {
 *                  .targetAddr = 0x12U;
 *                  .valid = 1U;
 *  	        };
 *              MMU_UpdateLUTBlocking(MMU0, 2U, &startLutWord, 2U, kMMU_LUTBurstWrite);
 * endcode
 * code
 * Fill discontinuous values into continuous addresses(E.g: initialize LUT SRAM address 2 and 3 with value 0x12 and
 * 0x34) mmu_lut_word_t lutWordArray[2] = {
 *                  {
 *                      .targetAddr = 0x12U;
 *                      .valid      = 1U;
 *                  },
 *                  {
 *                      .targetAddr = 0x34U;
 *                      .valid      = 1U;
 *                  },
 *              };
 *              MMU_UpdateLUTBlocking(MMU0, 2U, lutWordArray, 2U,kMMU_LUTSingleWrite);
 * endcode
 * code
 * Fill discontinuous values into discontinuous addresses(E.g: initialize LUT SRAM address 2 and 5 with value 0x12 and
 * 0x34)): mmu_lut_word_t addr2LutWord = { .targetAddr = 0x12U; .valid      = 1U;
 *              };
 *              MMU_UpdateLUTBlocking(MMU0, 2U, &addr2LutWord, 1U, kMMU_LUTSingleWrite);
 *
 *              mmu_lut_word_t addr5LutWord = {
 *                  .targetAddr = 0x34U;
 *                  .valid      = 1U;
 *              };
 *              MMU_UpdateLUTBlocking(MMU0, 5U, &addr5LutWord, 1U, kMMU_LUTSingleWrite);
 * endcode
 *
 * param base MMU peripheral base address.
 * param startPointer Start pointer of LUT SRAM to fill new mapping words, range from 0 to 8191.
 * param ptrLutWord Pointer to new lut words:
 *                   if \b writeOperation is selected as \b kMMU_LUTBurstWrite this parameter should be a pointer to the
 *      	            variable which represents the first LUT word to set;
 *                   if \b writeOperation is selected as \b kMMU_LUTSingleWrite this parameter can be set as a pointer
 * to the array that contains all new LUT words to set or set as a pointer to one variable when only want to update one
 * word into LUT's specific pointer. param countOfWord Count to new word to update into LUT SRAM, range from 1 to 8192.
 * param writeOperation Specify the write operation, the meaning of #ptrLutWord is different for
 *                      different write operations.
 */
void MMU_UpdateLUTBlocking(MMU_Type *base,
                           uint16_t startPointer,
                           mmu_lut_word_t *ptrLutWord,
                           uint16_t countOfWord,
                           mmu_lut_write_operation_t writeOperation)
{
    assert(ptrLutWord != NULL);
    assert(countOfWord > 0U);
    /* The LUT SRAM size is 8K word. */
    assert((startPointer + countOfWord) <= 8192U);

    mmu_lut_word_t *tmpPtrLutWord = ptrLutWord;
    uint16_t tmpCount             = countOfWord;

    MMU_UnlockLUT(base);
    if (writeOperation == kMMU_LUTSingleWrite)
    {
        /* In case of single write. */
        base->WRITE_PTR = MMU_WRITE_PTR_POINTER(startPointer);

        do
        {
            base->LUT_WDATA = MMU_LUT_WDATA_ADDR(tmpPtrLutWord->mappedValue) |
                              MMU_LUT_WDATA_VALID(tmpPtrLutWord->valid) | MMU_LUT_WDATA_COUNT(0U);

            tmpPtrLutWord++; /* Increase the pointer to point to next word in array. */
            tmpCount--;
        } while (tmpCount > 0U);
    }
    else
    {
        /* In case of burst write. */
        base->WRITE_PTR = MMU_WRITE_PTR_POINTER(startPointer);
        base->LUT_WDATA = MMU_LUT_WDATA_ADDR(tmpPtrLutWord->mappedValue) | MMU_LUT_WDATA_VALID(tmpPtrLutWord->valid) |
                          MMU_LUT_WDATA_COUNT(tmpCount - 1U);

        /* Wait for the burst-write operation to complete. */
        while ((base->STS & MMU_STS_BUSY_MASK) != 0UL)
        {
        }
    }
    MMU_LockLUT(base);
}

/*!
 * brief Read the specified number of LUT content from the specified pointer into the user-defined buffer.
 *
 * note #startPointer + #count should not exceed maximum size of LUT SRAM(8192).
 *
 * param base MMU peripheral base address.
 * param startPointer Specify start address to read in LUT SRAM, range from 0 to 8191.
 * param ptrWordReadBuffer Pointer of a buffer that record read out words.
 * param count Specify number of continuous address in LUT SRAM to read, range from 1 to 8192.
 */
void MMU_ReadLUT(MMU_Type *base, uint16_t startPointer, mmu_lut_word_t *ptrWordReadBuffer, uint16_t count)
{
    assert(ptrWordReadBuffer != NULL);
    assert(count > 0U);
    assert((startPointer + count) <= 8192U);

    mmu_lut_word_t *tmpPtrBuffer = ptrWordReadBuffer;
    uint16_t tmpCount            = count;
    uint32_t readData            = 0UL;

    base->READ_PTR = MMU_READ_PTR_POINTER(startPointer);
    do
    {
        readData                  = (((base->LUT_RDATA) & MMU_LUT_RDATA_DATA_MASK) >> MMU_LUT_RDATA_DATA_SHIFT);
        tmpPtrBuffer->mappedValue = (uint16_t)readData & 0x7FFFU;
        tmpPtrBuffer->valid       = ((readData & 0x8000U) != 0U) ? 1U : 0U;
        tmpPtrBuffer++;
        tmpCount--;
    } while (tmpCount > 0U);
}

/*!
 * brief Trigger the specified number of read operations from LUT SRAM, compare with the input golden word, the read
 * address and golden data are increased automatically each time.
 *
 * note This function only return when all read-verify operations are complete.
 *
 * param base MMU peripheral base address.
 * param startPointer The pointer of LUT SRAM which start to check, range from 0 to 8191.
 * param goldenWordToCheck The first golden word to check, in following read-verify operation,
 *                          the golden data will increase automatically.
 *
 * param count Specify number of continuous address in LUT SRAM to check, range from 1 to 8192.
 */
void MMU_TriggerLUTVerificationBlocking(MMU_Type *base,
                                        uint16_t startPointer,
                                        mmu_lut_word_t goldenWordToCheck,
                                        uint16_t count)
{
    assert(count > 0U);
    assert((startPointer + count) <= 8192U);

    base->READ_PTR = MMU_READ_PTR_POINTER(startPointer);
    base->READ_VFY = MMU_READ_VFY_DATA((goldenWordToCheck.mappedValue) | (goldenWordToCheck.valid << 15U)) |
                     MMU_READ_VFY_COUNT(count - 1U);

    /* Wait for the read-verify to complete. */
    while ((base->STS & MMU_STS_BUSY_MASK) != 0UL)
    {
    }
}

/*!
 * brief Get a record of AHB information when an error happens.
 *
 * param base MMU peripheral base address.
 * ptrRecord Pointer to user-defined variable which used to store current AHB error information.
 */
void MMU_GetAHBErrorRecord(MMU_Type *base, mmu_ahb_error_record_t *ptrRecord)
{
    assert(ptrRecord != NULL);
    uint32_t tmpInfo = 0UL;

    tmpInfo = base->FAIL_INFO;

    memcpy(ptrRecord, &tmpInfo, sizeof(uint32_t));
    ptrRecord->failAddr = base->FAIL_ADDR;
}


/*!
 * brief Map one physical unit to the virtual unit.
 * 
 * param base MMU peripheral base address.
 * param virt The unit-aligned virtual address.
 * param phys The unit-aligned virtual address.
 */
void MMU_SetupSimpleMap(MMU_Type *base, uint32_t virt, uint32_t phys)
{
    assert((virt % MMU_UNIT_BYTE_SIZE) == 0UL);
    assert((phys % MMU_UNIT_BYTE_SIZE) == 0UL);

    mmu_lut_word_t lutWord = MMU_TransferAddrToLUTWord(phys);
    uint16_t lutIndex = MMU_TransferAddrToLUTIndex(virt);

    MMU_UpdateLUTBlocking(base, lutIndex, &lutWord, 1U, kMMU_LUTSingleWrite);
}

/*!
 * brief Remove mapping for one unit of provided virtual address.
 * 
 * param base MMU peripheral base address.
 * param virt The unit-aligned virtual address.
 */
void MMU_TearDownSimpleMap(MMU_Type *base, uint32_t virt)
{
    assert((virt % MMU_UNIT_BYTE_SIZE) == 0UL);

    uint16_t lutIndex = MMU_TransferAddrToLUTIndex(virt);
    mmu_lut_word_t lutWord;

    MMU_ReadLUT(base, lutIndex, &lutWord, 1U);
    lutWord.valid = 0U;

    MMU_UpdateLUTBlocking(base, lutIndex, &lutWord, 1U, kMMU_LUTSingleWrite);
}

/*!
 * brief Map a region of physical memory into the virtual address space.
 * 
 * param base MMU peripheral base address.
 * param virt The unit-aligned destination virtual address to map.
 * param phys The unit-aligned source physical address to map.
 * param regionSize Unit-aligned size of mapped memory region in bytes.
 */
void MMU_SetupRegionMap(MMU_Type *base, uint32_t virt, uint32_t phys, size_t regionSize)
{
    assert((virt % MMU_UNIT_BYTE_SIZE) == 0UL);
    assert((phys % MMU_UNIT_BYTE_SIZE) == 0UL);
    assert((regionSize % MMU_UNIT_BYTE_SIZE) == 0UL);

    mmu_lut_word_t lutWord = MMU_TransferAddrToLUTWord(phys);
    uint16_t lutIndex = MMU_TransferAddrToLUTIndex(virt);
    uint16_t unitCount = (regionSize / MMU_UNIT_BYTE_SIZE);

    MMU_UpdateLUTBlocking(base, lutIndex, &lutWord, unitCount, kMMU_LUTBurstWrite);
}

/*!
 * brief Remove mapping for a provided virtual address region.
 * 
 * param base MMU peripheral base address.
 * param virt The unit-aligned virtual address.
 * param regionSize The unit-aligned size of region in bytes.
 */
void MMU_TearDownRegionMap(MMU_Type *base, uint32_t virt, size_t regionSize)
{
    assert((virt % MMU_UNIT_BYTE_SIZE) == 0UL);
    assert((regionSize % MMU_UNIT_BYTE_SIZE) == 0UL);

    mmu_lut_word_t lutWord;
    uint16_t lutIndex = MMU_TransferAddrToLUTIndex(virt);
    uint16_t unitCount = (regionSize / MMU_UNIT_BYTE_SIZE);

    MMU_ReadLUT(base, lutIndex, &lutWord, 1U);
    lutWord.valid = 0U;

    MMU_UpdateLUTBlocking(base, lutIndex, &lutWord, unitCount, kMMU_LUTBurstWrite);
}

/*!
 * brief Remap old virtual region into new address.
 * 
 * param base MMU peripheral base address.
 * param oldVirt The unit-aligned old virtual address.
 * param newVirt The unit-aligned new virtual address.
 * param regionSize The unit-aligned size of region in bytes.
 */
void MMU_RemapRegion(MMU_Type *base, uint32_t oldVirt, uint32_t newVirt, size_t regionSize)
{
    assert((oldVirt % MMU_UNIT_BYTE_SIZE) == 0UL);
    assert((newVirt % MMU_UNIT_BYTE_SIZE) == 0UL);
    assert((regionSize % MMU_UNIT_BYTE_SIZE) == 0UL);

    mmu_lut_word_t lutWord;
    uint16_t oldLutIndex = MMU_TransferAddrToLUTIndex(oldVirt);
    uint16_t newLutIndex = MMU_TransferAddrToLUTIndex(newVirt);
    uint16_t unitCount = (regionSize / MMU_UNIT_BYTE_SIZE);

    /* Setup mapping of new virtual address. */
    MMU_ReadLUT(base, oldLutIndex, &lutWord, 1U);
    lutWord.valid = 1U;
    MMU_UpdateLUTBlocking(base, newLutIndex, &lutWord, unitCount, kMMU_LUTBurstWrite);

    /* Teardown mapping of old virtual address. */
    MMU_TearDownRegionMap(base, oldVirt, regionSize);
}

/*!
 * brief Physically move region of memory, with copy
 *
 * details Maps a region of physical memory into the new virtual address space, and copy region of size from the 
 * old virtual address space. The new virtual memory region is mapped from physical memory starting @p newPhys of
 * size @p regionSize.
 * 
 * param base MMU peripheral base address.
 * param oldVirt Unit-aligned old virtual region address.
 * param newVirt Unit-aligned new virtual region address.
 * param newPhys Unit-aligned new physical region address which will map to new virtual region address.
 * param regionSize Unit-aligned size of region in bytes.
 */
void MMU_MoveRegion(MMU_Type *base, uint32_t oldVirt, uint32_t newVirt, uint32_t newPhys, size_t regionSize)
{
    MMU_SetupRegionMap(base, newVirt, newPhys, regionSize);
    memcpy((void *)newVirt, (void *)oldVirt, regionSize);
    MMU_TearDownRegionMap(base, oldVirt, regionSize);
}

/*!
 * brief Map an array of physical memory address into an array of virtual memory address.
 * 
 * param base MMU peripheral base address.
 * param ptrVirts Pointer to the array which contain unit-aligned virtual address.
 * param ptrPhys Pointer to the array which contain unit-aligned physical address.
 * param count Count of array elements.
 */
void MMU_SetupArrayMap(MMU_Type *base, uint32_t *ptrVirts, uint32_t *ptrPhys, uint32_t count)
{
    for (uint32_t i = 0UL; i < count; i++)
    {
        MMU_SetupSimpleMap(base, ptrVirts[i], ptrPhys[i]);
    }
}

/*!
 * brief Remove mapping of an array of virtual address.
 * 
 * param base MMU peripheral base address.
 * param ptrVirts Pointer to the array which contains unit-aligned virtual address.
 * param count Count of array elements.
 */
void MMU_TearDownArrayMap(MMU_Type *base, uint32_t *ptrVirts, uint32_t count)
{
    for (uint32_t i = 0UL; i < count; i++)
    {
        MMU_TearDownSimpleMap(base, ptrVirts[i]);
    }
}

/*!
 * brief Physical move array of memory, with copy.
 * 
 * details Maps an array of physical memory into the new array of virtual address space( @p ptrNewVirts ), and
 * copy an unit size of data from old array of virtual address to new array of virtual address.
 * 
 * param base MMU peripheral base address.
 * param ptrOldVirts Pointer to the array which contain old unit-aligned virtual address.
 * param ptrNewVirts Pointer to the array which contain new unit-aligned virtual address.
 * param ptrNewPhys Pointer to the array which contain new unit-aligned physical address.
 * param count Count of array elements.
 */
void MMU_MoveArray(MMU_Type *base, uint32_t *ptrOldVirts, uint32_t *ptrNewVirts, uint32_t *ptrNewPhys, uint32_t count)
{
    MMU_SetupArrayMap(base, ptrNewVirts, ptrNewPhys, count);
    for (uint32_t i = 0UL; i < count; i++)
    {
        memcpy((void *)&(ptrNewVirts[i]), (void *)&(ptrOldVirts[i]), MMU_UNIT_BYTE_SIZE);
    }
    MMU_TearDownArrayMap(base, ptrOldVirts, count);
}

/*!
 * brief Get mapped physical address from input virtual address.
 * 
 * param base MMU peripheral base address.
 * param virt The virtual address.
 * param[out] ptrPtrs Pointer to the variable to store mapped physical address.
 */
void MMU_GetPhyAddr(MMU_Type *base, uint32_t virt, uint32_t *ptrPtrs)
{
    uint32_t shiftArray[MMU_NUM_OF_UNIT_SIZE] =
    {
        12UL, /* Shift for 4KB unit size */
        13UL, /* Shift for 8KB unit size */
        14UL, /* Shift for 16KB unit size */
        15UL, /* Shift for 32KB unit size */
        16UL, /* Shift for 64KB unit size */
    };

    uint32_t maskArray[MMU_NUM_OF_UNIT_SIZE] =
    {
        0xFFFUL,    /* Mask for 4KB unit size. */
        0x1FFFUL,   /* Mask for 8KB unit size. */
        0x3FFFUL,   /* Mask for 16KB unit size. */
        0x7FFFUL,   /* Mask for 32KB unit size. */
        0xFFFFUL,   /* Mask for 64KB unit size. */
    };
    uint16_t lutIndex = MMU_TransferAddrToLUTIndex(virt);
    mmu_lut_word_t lutWord;
    uint32_t mapAddr = 0UL;

    MMU_ReadLUT(base, lutIndex, &lutWord, 1U);
    mapAddr = (uint32_t)lutWord.mappedValue << shiftArray[(uint8_t)g_selectedUnitSize];

    (*ptrPtrs) = ((virt & 0xF0000000UL) | mapAddr | (virt & maskArray[(uint8_t)g_selectedUnitSize]));
}
