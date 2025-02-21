/*
 * Copyright 2023-2024 NXP
 *
 * All rights reserved.
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_MMU_H_
#define FSL_MMU_H_

#include "fsl_common.h"

/*!
 * @addtogroup mmu
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*!@{*/
/*! @brief mmu driver version 2.0.0. */
#define FSL_MMU_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*!@}*/

/*!
 * @brief The enumeration of MMU status flags, @anchor mmu_status_flags_t.
 */
enum _mmu_status_flags
{
    kMMU_BusyFlag       = MMU_STS_BUSY_MASK, /*!< MMU is in Busy state, wait for it to clear before taking action. */
    kMMU_LUTInvalidFlag = MMU_STS_LUT_INVALID_MASK,      /*!< Indicate whether the valid bit in the access address is 0,
                                                         which means the access operation is invalid in LUT. */
    kMMU_AddressInvalidFlag = MMU_STS_INVALID_ADDR_MASK, /*!< The AHB access address is out
                                                            of the valid address range. */
    kMMU_ParityErrorFlag  = MMU_STS_PARITY_ERROR_MASK,   /*!< A parity error is detected in the access address. */
    kMMU_LockErrorFlag    = MMU_STS_LOCK_ERROR_MASK,     /*!< A lock error is detected when writing to LUT SRAM. */
    kMMU_IpsReadErrorFlag = MMU_STS_IPS_READ_ERROR_MASK, /*!< Indicate whether an IPS read error is detected when
                                                     read LUT SRAM, including IPS read parity error and
                                                     read-verify mismatch error. */

    kMMU_AllFlags = MMU_STS_BUSY_MASK | MMU_STS_LUT_INVALID_MASK | MMU_STS_INVALID_ADDR_MASK |
                    MMU_STS_PARITY_ERROR_MASK | MMU_STS_LOCK_ERROR_MASK |
                    MMU_STS_IPS_READ_ERROR_MASK, /*!< All flags. */
};

/*!
 * @brief The enumeration of MMU interrupts, @anchor mmu_interrupt_enable_t.
 *
 */
enum _mmu_interrupt_enable
{
    kMMU_LUTInvalidInterruptEnable = MMU_INTEN_LUT_INVALID_EN_MASK,      /*!< Enable the interrupt
                                                                         for #kMMU_LUTInvalidFlag. */
    kMMU_AddressInvalidInterruptEnable = MMU_INTEN_INVALID_ADDR_EN_MASK, /*!< Enable the interrupt
                                                                        for #kMMU_AddressInvalidFlag. */
    kMMU_ParityErrorInterruptEnable = MMU_INTEN_PARITY_ERROR_EN_MASK,    /*!< Enable the interrupt
                                                                           for #kMMU_ParityErrorFlag. */
    kMMU_LockErrorInterruptEnable = MMU_INTEN_LOCK_ERROR_EN_MASK, /*!< Enable the interrupt for #kMMU_LockErrorFlag. */
    kMMU_IpsReadErrorInterruptEnable = MMU_INTEN_IPS_READ_ERROR_EN_MASK, /*!< Enable the interrupt
                                                                        for #kMMU_IpsReadErrorFlag. */

    kMMU_AllInterruptsEnable = MMU_INTEN_LUT_INVALID_EN_MASK | MMU_INTEN_INVALID_ADDR_EN_MASK |
                               MMU_INTEN_PARITY_ERROR_EN_MASK | MMU_INTEN_LOCK_ERROR_EN_MASK |
                               MMU_INTEN_IPS_READ_ERROR_EN_MASK, /*!< Enable all interrupts. */
};

/*!
 * @brief The enumeration of unit size, available selections are 4KB, 8KB, 16KB, 32KB, and 64KB.
 */
typedef enum _mmu_unit_size
{
    kMMU_UnitSize4KB = 0U, /*!< Specify the basic size of unit is 4KB. */
    kMMU_UnitSize8KB,      /*!< Specify the basic size of unit is 8KB. */
    kMMU_UnitSize16KB,     /*!< Specify the basic size of unit is 16KB. */
    kMMU_UnitSize32KB,     /*!< Specify the basic size of unit is 32KB. */
    kMMU_UnitSize64KB,     /*!< Specify the basic size of unit is 64KB. */
} mmu_unit_size_t;
#define MMU_NUM_OF_UNIT_SIZE (5U)
extern mmu_unit_size_t g_selectedUnitSize;

/*!
 * @brief The enumeration of AHB access type, available selections are read access and write access.
 */
typedef enum _mmu_ahb_access_type
{
    kMMU_ReadAccess = 0UL, /*!< The access type of the AHB transfer is read. */
    kMMU_WriteAccess,      /*!< The access type of the AHB transfer is write. */
} mmu_ahb_access_type_t;

/*!
 * @brief The enumeration of error type in case of AHB transfer, available selections are LUT invalid error, address
 * invalid error, and parity error.
 */
typedef enum _mmu_ahb_error_type
{
    kMMU_LUTInvalidError  = 0x1UL, /*!< The error type information of the transfer is LUT invalid error. */
    kMMU_AddrInvalidError = 0x2UL, /*!< The error type information of the transfer is address invalid error. */
    kMMU_ParityError      = 0x4UL, /*!< The error type information of the transfer is parity error. */
} mmu_ahb_error_type_t;

#define MMU_PAGE_OPT_MASK (0xE0UL)
#define MMU_PAGE_OPT_SHIFT (5U)
#define MMU_PAGE_OPT(x)   (((uint32_t)(((uint32_t)(x)) << MMU_PAGE_OPT_SHIFT)) & MMU_PAGE_OPT_MASK)
/*!
 * @brief The MMU module supports two different page mode: 1 page mode and 4 pages mode.
 *
 * @note In 4 pages mode, each page contains 2K word. Different page can contain different mapping schema.
 */
typedef enum _mmu_page_option
{
    kMMU_PageOpt_1Page = 0U, /*!< MMU takes LUT SRAM as 1 page for address remapping. */
    kMMU_PageOpt_4Page_Low2KWordSelected = 1U,      /*!< MMU takes LUT SRAM as 4 pages for address remapping,
                                                 in this page mode the whole LUT is divided into 4 pages,
                                                 use LUT SRAM low 2K words for address remapping. */
    kMMU_PageOpt_4Page_MidLow2KWordSelected = 3U,      /*!< MMU takes LUT SRAM as 4 pages for address remapping,
                                            in this page mode the whole LUT is divided into 4 pages,
                                            use LUT SRAM mid-low 2K words for address remapping. */
    kMMU_PageOpt_4Page_MidHigh2KWordSelected = 5U,      /*!< MMU takes LUT SRAM as 4 pages for address remapping,
                                            in this page mode the whole LUT is divided into 4 pages,
                                            use LUT SRAM mid-high 2K words for address remapping. */
    kMMU_PageOpt_4Page_High2KWordSelected = 7U,      /*!< MMU takes LUT SRAM as 4 pages for address remapping,
                                            in this page mode the whole LUT is divided into 4 pages,
                                            use LUT SRAM mid-low 2K words for address remapping. */
} mmu_page_option_t;
extern mmu_page_option_t g_selectedPageOpt;

/*!
 * @brief The enumeration of LUT SRAM write operation, both burst-write and single-write are supported.
 */
typedef enum _mmu_lut_write_operation
{
    kMMU_LUTSingleWrite = 0U, /*!< In this operation, words to write in consequent LUT pointer may not consequent.
                                   It is possible to write discontinuous value into discontinuous address. */
    kMMU_LUTBurstWrite,       /*!< In this operation, words to write in consequence LUT pointer must be consequent.
                                  write continuous value into continuous address. */
} mmu_lut_write_operation_t;

/*!
 * @brief The behavior when an invalid address is detected is programmable.
 */
typedef enum _mmu_invalid_address_mode
{
    kMMU_InvalidAddrRespondError = 0U, /*!< MMU responds with a transfer error when a invalid address is detected. */
    kMMU_InvalidAddrAllowed,           /*!< MMU allows transfer when an invalid address is detected. */
} mmu_invalid_address_mode_t;

/*!
 * @brief The record of AHB information when an error happens.
 */
typedef struct _mmu_ahb_error_record
{
    uint32_t masterId : 8U;                /*!< Indicate the master ID of the transfer. */
    uint32_t protectionInfo : 7U;          /*!< Indicate the protection information of the transfer. */
    mmu_ahb_access_type_t accessType : 1U; /*!< Indicate the access type of the transfer. */
    mmu_ahb_error_type_t errorType : 3U;    /*!< Indicate the error type of the transfer. */
    uint32_t reserved : 13U;               /* Reserved. */
    uint32_t failAddr;                     /*!< Indicates the LUT address where an erro happens. */
} mmu_ahb_error_record_t;

/*!
 * @brief The word in LUT SRAM, there are 8K words exist in LUT SRAM.
 */
typedef struct _mmu_lut_word
{
    uint16_t mappedValue : 15U; /*!< The mapped value to set, should be index of unit in valid address range not
                                   specific AHB address. */
    uint16_t valid : 1U;        /*!< Specify whether the mapped value is valid: 1b1 means valid, 1b0 means invalid. */
} mmu_lut_word_t;

/*!
 * @brief The structure used to initialize the MMU instance includes unit size, page mode, address range, and LUT
 * content.
 */
typedef struct _mmu_config
{
    mmu_unit_size_t unitSize;                   /*!< Specify the basic size of unit that is used in the memory map. */

    mmu_page_option_t pageOpt;                   /*!< Specify the behavior of page option. */
    mmu_invalid_address_mode_t invalidAddrMode; /*!< Specify MMU behavior when an invalid address is detected. */

    /* Parameters used to specify AHB access address range. */
    uint16_t baseAddr; /*!< Upper 16 bits of valid range's base address. */
    uint16_t maxAddr;  /*!< Upper 16 bits of valid range's maximum address. */

    /* Members used to set up map from va to pa  */
    uint32_t *ptrPhyAddrArray;              /*!< Pointer to the physical address array used for array mapping. */
    uint32_t *ptrVirtualAddrArray;          /*!< Pointer to the virtual address array used for array mapping. */
    uint16_t countOfAddr;                   /*!< Count of array elements */

    bool enableMMP;     /*!< Enable/disable memory map feature, once enabled all AHB access to corresponding address
                            are remapped by LUT SRAM. */
} mmu_config_t;

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @name Initialize and De-initialize Interfaces
 * @{
 */

/*!
 * @brief Initialize MMU:
 *          1. Enable MMU clock;
 *          2. Define the basic unit that is used in the memory map;
 *          3. Configure valid address range;
 *          4. Fill LUT SRAM;
 *          5. Enable MMU remap function.
 *
 * @param base MMU peripheral base address.
 * @param config Pointer to the user defined variable in type of @ref mmu_config_t.
 */
void MMU_Init(MMU_Type *base, const mmu_config_t *config);

/*!
 * @brief De-initialize MMU:
 *          1. Disable MMU remap function;
 *          2. Reset MMU logic;
 *          3. Disable MMU clock.
 * @param base
 */
void MMU_Deinit(MMU_Type *base);

/*!
 * @brief Get default configurations of MMU module.
 *
 * @code
 *          config->unitSize = kMMU_UnitSize4KB;
 *          config->pageMode = kMMU_1PageMode;
 *          config->invalidAddrMode = kMMU_InvalidAddrRespondError;
 *          config->baseAddr    = 0x0UL;
 *          config->maxAddr     = 0x0UL;
 *          config->operationToWrite = kMMU_LUTBurstWrite;
 *          config->ptrLutWord       = NULL;
 *          config->countOfWordToWrite = 0U;
 *          config->startPointer = 0U;
 * @endcode
 *
 * @param config Pointer to the user defined variable in type of @ref mmu_config_t.
 */
void MMU_GetDefaultConfig(mmu_config_t *config);

/*! @} */

/*!
 * @name MMU Functional Interfaces
 * @{
 */

/*!
 * @brief Map one physical unit to the virtual unit.
 * 
 * @param base MMU peripheral base address.
 * @param virt The unit-aligned virtual address.
 * @param phys The unit-aligned virtual address.
 */
void MMU_SetupSimpleMap(MMU_Type *base, uint32_t virt, uint32_t phys);

/*!
 * @brief Remove mapping for one unit of provided virtual address.
 * 
 * @param base MMU peripheral base address.
 * @param virt The unit-aligned virtual address.
 */
void MMU_TearDownSimpleMap(MMU_Type *base, uint32_t virt);

/*!
 * @brief Map a region of physical memory into the virtual address space.
 * 
 * @param base MMU peripheral base address.
 * @param virt The unit-aligned destination virtual address to map.
 * @param phys The unit-aligned source physical address to map.
 * @param regionSize Unit-aligned size of mapped memory region in bytes.
 */
void MMU_SetupRegionMap(MMU_Type *base, uint32_t virt, uint32_t phys, size_t regionSize);


/*!
 * @brief Remove mapping for a provided virtual address region.
 * 
 * @param base MMU peripheral base address.
 * @param virt The unit-aligned virtual address.
 * @param regionSize The unit-aligned size of region in bytes.
 */
void MMU_TearDownRegionMap(MMU_Type *base, uint32_t virt, size_t regionSize);

/*!
 * @brief Remap old virtual region into new address.
 * 
 * @param base MMU peripheral base address.
 * @param oldVirt The unit-aligned old virtual address.
 * @param newVirt The unit-aligned new virtual address.
 * @param regionSize The unit-aligned size of region in bytes.
 */
void MMU_RemapRegion(MMU_Type *base, uint32_t oldVirt, uint32_t newVirt, size_t regionSize);

/*!
 * @brief Physically move region of memory, with copy
 *
 * @details Maps a region of physical memory into the new virtual address space, and copy region of size from the 
 * old virtual address space. The new virtual memory region is mapped from physical memory starting @p newPhys of
 * size @p regionSize.
 * 
 * @param base MMU peripheral base address.
 * @param oldVirt Unit-aligned old virtual region address.
 * @param newVirt Unit-aligned new virtual region address.
 * @param newPhys Unit-aligned new physical region address which will map to new virtual region address.
 * @param regionSize Unit-aligned size of region in bytes.
 */
void MMU_MoveRegion(MMU_Type *base, uint32_t oldVirt, uint32_t newVirt, uint32_t newPhys, size_t regionSize);

/*!
 * @brief Map an array of physical memory address into an array of virtual memory address.
 * 
 * @param base MMU peripheral base address.
 * @param ptrVirts Pointer to the array which contain unit-aligned virtual address.
 * @param ptrPhys Pointer to the array which contain unit-aligned physical address.
 * @param count Count of array elements.
 */
void MMU_SetupArrayMap(MMU_Type *base, uint32_t *ptrVirts, uint32_t *ptrPhys, uint32_t count);

/*!
 * @brief Remove mapping of an array of virtual address.
 * 
 * @param base MMU peripheral base address.
 * @param ptrVirts Pointer to the array which contains unit-aligned virtual address.
 * @param count Count of array elements.
 */
void MMU_TearDownArrayMap(MMU_Type *base, uint32_t *ptrVirts, uint32_t count);

/*!
 * @brief Physical move array of memory, with copy.
 * 
 * @details Maps an array of physical memory into the new array of virtual address space( @p ptrNewVirts ), and
 * copy an unit size of data from old array of virtual address to new array of virtual address.
 * 
 * @param base MMU peripheral base address.
 * @param ptrOldVirts Pointer to the array which contain old unit-aligned virtual address.
 * @param ptrNewVirts Pointer to the array which contain new unit-aligned virtual address.
 * @param ptrNewPhys Pointer to the array which contain new unit-aligned physical address.
 * @param count Count of array elements.
 */
void MMU_MoveArray(MMU_Type *base, uint32_t *ptrOldVirts, uint32_t *ptrNewVirts, uint32_t *ptrNewPhys, uint32_t count);

/*!
 * @brief Get mapped physical address from input virtual address.
 * 
 * @param base MMU peripheral base address.
 * @param virt The virtual address.
 * @param[out] ptrPtrs Pointer to the variable to store mapped physical address.
 */
void MMU_GetPhyAddr(MMU_Type *base, uint32_t virt, uint32_t *ptrPtrs);

/*! @} */

/*!
 * @name MMU Low Level Control Interfaces
 * @{
 */

/*!
 * @brief Enable/disable memory map.
 *
 * @param base MMU peripheral base address.
 * @param enable Used to enable/disable memory map:
 *          - \b true Enable memory map, the addresses of the AHB transaction are remapped by looking up LUT SRAM.
 *          - \b false Disable memory map, the AHB transaction passes through MMU without address remapping.
 */
static inline void MMU_EnableMemoryMap(MMU_Type *base, bool enable)
{
    if (enable)
    {
        base->CTRL |= MMU_CTRL_MMU_EN_MASK;
    }
    else
    {
        base->CTRL &= ~MMU_CTRL_MMU_EN_MASK;
    }
}

/*!
 * @brief Update the basic size of the unit that is used in the memory map.
 *
 * @param base MMU peripheral base address.
 * @param unitSize Used to specify the basic size of unit in type of @ref mmu_unit_size_t.
 */
static inline void MMU_UpdateUnitSize(MMU_Type *base, mmu_unit_size_t unitSize)
{
    base->CTRL = (base->CTRL & ~MMU_CTRL_UNIT_SIZE_MASK) | MMU_CTRL_UNIT_SIZE(unitSize);
    g_selectedUnitSize = unitSize;
}

/*!
 * @brief Trigger a software reset to reset the MMU logic.
 *
 * @param base MMU peripheral base address.
 */
void MMU_DoSoftwareReset(MMU_Type *base);

/*!
 * @brief Update the valid address range.
 *
 * @note Both baseAddr and maxAddr mean the upper 16 bits of a valid address.
 *
 * @code
 *      To set AHB address from 0x51000000UL to 0x511FFFFF are valid:
 *      MMU_UpdateValidAddressRange(MMU0, 0x5100U, 0x511FU);
 * @endcode
 *
 * @param base MMU peripheral base address.
 * @param baseAddr Upper 16 bits of valid range's base address.
 * @param maxAddr Upper 16 bits of valid range's maximum address.
 */
static inline void MMU_UpdateValidAddressRange(MMU_Type *base, uint16_t baseAddr, uint16_t maxAddr)
{
    base->ADDR_RANGE = MMU_ADDR_RANGE_BASE_ADDR(baseAddr) | MMU_ADDR_RANGE_MAX_ADDR(maxAddr);
}

/*!
 * @brief Change page mode, the MMU module supports #kMMU_1PageMode and #kMMU_4PageMode.
 *
 * @param base MMU peripheral base address.
 * @param pageMode Page mode to use, please refer to @ref mmu_page_option_t.
 */
static inline void MMU_ChangePageOption(MMU_Type *base, mmu_page_option_t pageOpt)
{
    if (pageOpt == kMMU_PageOpt_1Page)
    {
        base->CTRL &= ~(MMU_PAGE_OPT_MASK);
    }
    else
    {
        base->CTRL = (base->CTRL & ~MMU_PAGE_OPT_MASK) | MMU_PAGE_OPT(pageOpt);
    }

    g_selectedPageOpt = pageOpt;
}

/*! @} */

/*!
 * @name LUT SRAM Control Interfaces
 * @{
 */

/*!
 * @brief Use the blocking method to update LUT SRAM with user-defined words.
 *
 * @note This function only return when all words that #ptrLutWord refers are set into LUT SRAM.
 *
 * @note This function supports both single write and burst write described in RM, please note that burst write is only
 * useful when to fill continuous value into continuous addresses.
 *
 * @note startPointer + countOfWords should not exceed the maximum size of LUT SRAM(8192).
 * @code
 * Fill continuous values into continuous addresses (E.g: initialize LUT SRAM address 2 and 3 with value 0x12 and 0x13)
 *              mmu_lut_word_t    startLutWord = {
 *                  .mappedValue = 0x12U;
 *                  .valid = 1U;
 *  	        };
 *              MMU_UpdateLUTBlocking(MMU0, 2U, &startLutWord, 2U, kMMU_LUTBurstWrite);
 * @endcode
 * @code
 * Fill discontinuous values into continuous addresses(E.g: initialize LUT SRAM address 2 and 3 with value 0x12 and
 * 0x34) mmu_lut_word_t lutWordArray[2] = {
 *                  {
 *                      .mappedValue = 0x12U;
 *                      .valid      = 1U;
 *                  },
 *                  {
 *                      .mappedValue = 0x34U;
 *                      .valid      = 1U;
 *                  },
 *              };
 *              MMU_UpdateLUTBlocking(MMU0, 2U, lutWordArray, 2U,kMMU_LUTSingleWrite);
 * @endcode
 * @code
 * Fill discontinuous values into discontinuous addresses(E.g: initialize LUT SRAM address 2 and 5 with value 0x12 and
 * 0x34)): mmu_lut_word_t addr2LutWord = { .mappedValue = 0x12U; .valid      = 1U;
 *              };
 *              MMU_UpdateLUTBlocking(MMU0, 2U, &addr2LutWord, 1U, kMMU_LUTSingleWrite);
 *
 *              mmu_lut_word_t addr5LutWord = {
 *                  .mappedValue = 0x34U;
 *                  .valid      = 1U;
 *              };
 *              MMU_UpdateLUTBlocking(MMU0, 5U, &addr5LutWord, 1U, kMMU_LUTSingleWrite);
 * @endcode
 *
 * @param base MMU peripheral base address.
 * @param startPointer Start pointer of LUT SRAM to fill new mapping words, range from 0 to 8191.
 * @param ptrLutWord Pointer to new lut words:
 *                   if \b writeOperation is selected as \b kMMU_LUTBurstWrite this parameter should be a pointer to the
 *      	            variable which represents the first LUT word to set;
 *                   if \b writeOperation is selected as \b kMMU_LUTSingleWrite this parameter can be set as a pointer
 * to the array that contains all new LUT words to set or set as a pointer to one variable when only want to update one
 * word into LUT's specific pointer.
 * @param countOfWord Count to new word to update into LUT SRAM, range from 1 to 8192.
 * @param writeOperation Specify the write operation, the meaning of #ptrLutWord is different for
 *                      different write operations.
 */
void MMU_UpdateLUTBlocking(MMU_Type *base,
                           uint16_t startPointer,
                           mmu_lut_word_t *ptrLutWord,
                           uint16_t countOfWords,
                           mmu_lut_write_operation_t writeOperation);


/*!
 * @brief Read the specified number of LUT content from the specified pointer into the user-defined buffer.
 *
 * @note #startPointer + #count should not exceed maximum size of LUT SRAM(8192).
 *
 * @param base MMU peripheral base address.
 * @param startPointer Specify start address to read in LUT SRAM, range from 0 to 8191.
 * @param ptrWordReadBuffer Pointer of a buffer that record read out words.
 * @param count Specify number of continuous address in LUT SRAM to read, range from 1 to 8192.
 */
void MMU_ReadLUT(MMU_Type *base, uint16_t startPointer, mmu_lut_word_t *ptrWordReadBuffer, uint16_t count);

/*!
 * @brief Trigger the specified number of read operations from LUT SRAM, compare with the input golden word, the read
 * address and golden data are increased automatically each time.
 *
 * @note This function only return when all read-verify operations are complete.
 *
 * @param base MMU peripheral base address.
 * @param startPointer The pointer of LUT SRAM which start to check, range from 0 to 8191.
 * @param goldenWordToCheck The first golden word to check, in following read-verify operation,
 *                          the golden data will increase automatically.
 *
 * @param count Specify number of continuous address in LUT SRAM to check, range from 1 to 8192.
 */
void MMU_TriggerLUTVerificationBlocking(MMU_Type *base,
                                        uint16_t startPointer,
                                        mmu_lut_word_t goldenWordToCheck,
                                        uint16_t count);

/*!
 * @brief Lock LUT SRAM to avoid an accidental update.
 *
 * @note If locked, writing to LUT SRAM will trigger #kMMU_LockErrorFlag.
 *
 * @param base MMU peripheral base address.
 */
static inline void MMU_LockLUT(MMU_Type *base)
{
    base->CTRL |= MMU_CTRL_LOCK_LUT_MASK;
}

/*!
 * @brief Unlock LUT SRAM.
 *
 * @note To update LUT SRAM, please ensure LUT is unlocked.
 *
 * @param base MMU peripheral base address.
 */
static inline void MMU_UnlockLUT(MMU_Type *base)
{
    base->CTRL &= ~MMU_CTRL_LOCK_LUT_MASK;
}

/*! @} */

/*!
 * @name Status And Error Interfaces
 * @{
 */

/*!
 * @brief Get status flags.
 *
 * @param base MMU peripheral base address.
 *
 * @return All status flags asserted, should be the OR'ed value of @ref mmu_status_flags_t.
 */
static inline uint32_t MMU_GetStatusFlags(MMU_Type *base)
{
    return base->STS;
}

/*!
 * @brief Clear status flags.
 *
 * @param base MMU peripheral base address.
 * @param mask The mask of flags to clear, should be the OR'ed value of @ref mmu_status_flags_t.
 */
static inline void MMU_ClearStatusFlags(MMU_Type *base, uint32_t mask)
{
    base->STS = mask;
}

/*!
 * @brief Get the LUT SRAM address when an error is detected for the IPS read operation (including IPS read parity error
 * and read-verify mismatch error).
 *
 * @param base MMU peripheral base address.
 *
 * @return The pointer in LUT SRAM, range from 0 to 8191.
 */
static inline uint16_t MMU_GetIPSReadErrorAddress(MMU_Type *base)
{
    return (uint16_t)((base->STS & MMU_STS_IPS_ERR_ADDR_MASK) >> MMU_STS_IPS_ERR_ADDR_SHIFT);
}

/*!
 * @brief Get a record of AHB information when an error happens.
 *
 * @param base MMU peripheral base address.
 * @param ptrRecord Pointer to user-defined @ref mmu_ahb_error_record_t variable which used to
 *                  store current AHB error information.
 *
 * @return The record of AHB information when an error happens, please refer to @ref mmu_ahb_error_record_t for details.
 */
void MMU_GetAHBErrorRecord(MMU_Type *base, mmu_ahb_error_record_t *ptrRecord);

/*!
 * @brief Check if MMU is in the Busy state.
 *
 * @note There are some possible reasons to make MMU is busy state:
 *          - Initialization sequence
 *          - Burst-write operation
 *          - Read-verify operation
 *
 * @param base MMU peripheral base address.
 *
 * @retval false MMU not in the busy state.
 * @retval true  MMU is in the busy state, wait for it is not busy before taking an action.
 */
static inline bool MMU_CheckMMUBusy(MMU_Type *base)
{
    return (((base->STS) & (uint32_t)kMMU_BusyFlag) != 0UL);
}

/*! @} */

/*!
 * @name Interrupts' control Interfaces
 * @{
 */

/*!
 * @brief Enabled interrupts.
 *
 * @param base MMU peripheral base address.
 * @param mask Mask of interrupts to enable, should be the OR'ed value of @ref mmu_interrupt_enable_t.
 */
static inline void MMU_EnableInterrupts(MMU_Type *base, uint32_t mask)
{
    base->INTEN |= mask;
}

/*!
 * @brief Disable interrupts.
 *
 * @param base MMU peripheral base address.
 * @param mask Mask of interrupts to disable, should be the OR'ed value of @ref mmu_interrupt_enable_t.
 */
static inline void MMU_DisableInterrupts(MMU_Type *base, uint32_t mask)
{
    base->INTEN &= ~mask;
}

/*! @} */


#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */
#endif /* _FSL_MMU_H__ */
