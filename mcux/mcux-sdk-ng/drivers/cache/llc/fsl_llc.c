/*
 * Copyright 2025 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_llc.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.cache_llc"
#endif

/* Timeout for maintenance operations (in loop iterations) */
#if !defined(CONFIG_LLC_MAINTENANCE_TIMEOUT)
#define CONFIG_LLC_MAINTENANCE_TIMEOUT (1000U)
#endif

#define LLC_WAY_NUMBER (8U)

#define LLC_SET_NUMBER (8192U)

#define LLC_WAY_PARTITION_COUNT (8U)

/*******************************************************************************
 * Variables
 ******************************************************************************/
static llc_callback_t s_LLCCallback;

/* Array of LLC peripheral base address */
static LLC_Type *const s_llcBases[] = LLC_BASE_PTRS;

#if (defined(LLC_PHYMEM_BASE_ALIAS_COUNT))
#define LLC_PHYMEM_COLUMN_COUNT LLC_PHYMEM_BASE_ALIAS_COUNT
/* Array of LLC physical memory base address,
  it is a 2D array, the row indicate cache instance,
  the column indicate the alias of one instance.  */
static uint32_t const s_llcPhymemBases[FSL_FEATURE_SOC_LLC_COUNT][LLC_PHYMEM_COLUMN_COUNT] = LLC_PHYMEM_BASES;
/* Array of LLC physical size base address,
  it is a 2D array, the row indicate cache instance,
  the column indicate the alias of one instance.  */
static uint32_t const s_llcPhymemSizes[FSL_FEATURE_SOC_LLC_COUNT][LLC_PHYMEM_COLUMN_COUNT] = LLC_PHYMEM_SIZES;
#else
#define LLC_PHYMEM_COLUMN_COUNT 1
static uint32_t const s_llcPhymemBases[] = LLC_PHYMEM_BASES;
static uint32_t const s_llcPhymemSizes[] = LLC_PHYMEM_SIZES;
#endif

volatile uint8_t g_llcMemPhyAliasId = 0U;

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/*!
 * @brief Get Cache line offset bits based on cache line size.
 *
 * @param base LLC peripheral base address.
 * @return Cache line offset bits.
 */
static uint32_t LLC_GetCacheLineOffsetBits(LLC_Type *base);

/*!
 * @brief Performs maintenance operation with timeout.
 *
 * @param base LLC peripheral base address.
 * @param arrayType Array type for maintenance operation.
 * @param operation Maintenance operation type.
 * @return Status of the operation.
 */
static status_t LLC_RunMaintenance(LLC_Type *base, uint32_t arrayId, llc_maintenance_operation_t operation);

/*!
 * @brief Align address to cache line size.
 *
 * @param base LLC peripheral base address.
 * @param address Address to align.
 * @return Aligned address.
 */
static uint32_t LLC_AlignAddressToCacheLine(LLC_Type *base, uint32_t address);

/*!
 * brief Returns an instance number given physical memory address.
 *
 * param address The physical memory address.
 * return LLC instance number starting from 0.
 */
uint32_t LLC_GetInstanceByAddr(uint32_t address);

/*******************************************************************************
 * Code
 ******************************************************************************/
/*!
 * brief Get Cache line offset bits based on cache line size.
 */
static uint32_t LLC_GetCacheLineOffsetBits(LLC_Type *base)
{
    assert(base != NULL);

    uint32_t cacheLineSize = (base->CCUHI & LLC_CCUHI_CACHELINESIZE_MASK) >> LLC_CCUHI_CACHELINESIZE_SHIFT;

    assert(cacheLineSize > 0U);

    switch ((llc_cache_line_size_t)cacheLineSize)
    {
        case kLLC_CacheLineSize128B:
            /* 2^7 = 128 */
            return 7U;
        default:
            /* Unknown, should not happen */
            return 0U;
    }
}

/*!
 * brief Performs maintenance operation with timeout.
 */
static status_t LLC_RunMaintenance(LLC_Type *base, uint32_t arrayId, llc_maintenance_operation_t operation)
{
    uint32_t timeout = CONFIG_LLC_MAINTENANCE_TIMEOUT;

    base->CCUCMCR = (base->CCUCMCR & ~(LLC_CCUCMCR_ARRAYID_MASK | LLC_CCUCMCR_MNTOP_MASK)) |
                    LLC_CCUCMCR_ARRAYID(arrayId) | LLC_CCUCMCR_MNTOP((uint32_t)operation);

    while (((base->CCUCMAR & LLC_CCUCMAR_MNTOPACTV_MASK) != 0U) && (timeout > 0U))
    {
        timeout--;
    }

    return (timeout > 0U) ? kStatus_Success : kStatus_Timeout;
}

/*!
 * brief Align address to cache line size.
 */
static uint32_t LLC_AlignAddressToCacheLine(LLC_Type *base, uint32_t address)
{
    uint32_t cacheLineOffsetBits = LLC_GetCacheLineOffsetBits(base);
    assert(cacheLineOffsetBits > 0U);
    return (address & ~((1UL << cacheLineOffsetBits) - 1UL));
}

/*!
 * brief Returns an instance number given physical memory address.
 */
uint32_t LLC_GetInstanceByAddr(uint32_t address)
{
    uint32_t i = 0UL;
    uint32_t phyMemBase[FSL_FEATURE_SOC_LLC_COUNT][LLC_PHYMEM_COLUMN_COUNT];
    uint32_t phyMemSize[FSL_FEATURE_SOC_LLC_COUNT][LLC_PHYMEM_COLUMN_COUNT];
    memcpy(phyMemBase, s_llcPhymemBases, sizeof(s_llcPhymemBases));
    memcpy(phyMemSize, s_llcPhymemSizes, sizeof(s_llcPhymemSizes));

    while (i < ARRAY_SIZE(s_llcBases))
    {
        g_llcMemPhyAliasId = 0U;
        while (g_llcMemPhyAliasId < LLC_PHYMEM_COLUMN_COUNT)
        {
            if ((MSDK_REG_SECURE_ADDR(address) >= MSDK_REG_SECURE_ADDR(phyMemBase[i][g_llcMemPhyAliasId])) &&
                ((MSDK_REG_SECURE_ADDR(address) - MSDK_REG_SECURE_ADDR(phyMemBase[i][g_llcMemPhyAliasId])) <
                 phyMemSize[i][g_llcMemPhyAliasId]))
            {
                return i;
            }
            g_llcMemPhyAliasId++;
        }
        i++;
    }

    return 0xFFFFFFFFUL;
}

/*!
 * brief Gets the default configuration structure.
 *
 * This function initializes the LLC configuration structure to default values.
 * code
 *  config->enableErrorDetection    = true;
 *  config->enableWriteAllocPartial = true;
 *  config->scratchpadConfig        = NULL;
 * endcode
 *
 * param config Pointer to configuration structure.
 */
void LLC_GetDefaultConfig(llc_config_t *config)
{
    assert(config != NULL);

    /* Clear configuration structure */
    (void)memset(config, 0, sizeof(llc_config_t));

    /* Set default values */
    config->enableErrorDetection    = true;
    config->enableWriteAllocPartial = true;
    config->scratchpadConfig        = NULL;
}

/*!
 * brief Initializes the LLC module.
 *
 * This function configures the LLC module with user-defined settings.
 * It initializes the tag and data arrays and configures basic settings.
 *
 * param base LLC peripheral base address.
 * param config Pointer to configuration structure.
 * return kStatus_Success LLC initialization succeeded.
 * return kStatus_InvalidArgument Invalid argument provided.
 * return kStatus_Timeout Maintenance operation timeout.
 */
status_t LLC_Init(LLC_Type *base, const llc_config_t *config)
{
    assert(base != NULL);
    assert(config != NULL);

    status_t status;

    /* TRANSEN is enabled by default, just in case */
    if ((base->CCUTCR & LLC_CCUTCR_TRANSEN_MASK) == 0U)
    {
        base->CCUTCR |= LLC_CCUTCR_TRANSEN_MASK;
    }

    /* Initialize Tag Array */
    status = LLC_RunMaintenance(base, 0U, kLLC_MaintenanceInitValidEntries);
    if (status != kStatus_Success)
    {
        return status;
    }
    /* Optional Initialize Data Array */
    status = LLC_RunMaintenance(base, 1U, kLLC_MaintenanceInitValidEntries);
    if (status != kStatus_Success)
    {
        return status;
    }

    /* Configure scratchpad if provided */
    if (config->scratchpadConfig != NULL)
    {
        status = LLC_ConfigScratchpad(base, config->scratchpadConfig);
        if (status != kStatus_Success)
        {
            return status;
        }
    }

    /* Enable cache operations */
    LLC_EnableCache(base);

    /* Configure error detection */
    if (config->enableErrorDetection)
    {
        (void)LLC_EnableErrorDetection(base, kLLC_ErrorUncorrectableMemory, true);
        (void)LLC_EnableErrorDetection(base, kLLC_ErrorUncorrectableProtocol, true);
    }

    /* Configure partial write allocation */
    base->CCUCAOR = (base->CCUCAOR & ~LLC_CCUCAOR_WRALLOCPARTIALEN_MASK) |
                    LLC_CCUCAOR_WRALLOCPARTIALEN(config->enableWriteAllocPartial ? 1U : 0U);

    return kStatus_Success;
}

/*!
 * brief Enables the LLC.
 *
 * This function enables cache lookup and fill operations.
 *
 * param base LLC peripheral base address.
 */
void LLC_EnableCache(LLC_Type *base)
{
    assert(base != NULL);

    LLC_BARRIER();

    /* Enable cache lookup */
    base->CCUCTCR |= LLC_CCUCTCR_LOOKUPEN_MASK;

    /* Enable cache fill on miss */
    base->CCUCTCR |= LLC_CCUCTCR_FILLEN_MASK;

    LLC_BARRIER();
}

/*!
 * brief Disables the LLC.
 *
 * This function disables cache lookup and fill operations.
 *
 * param base LLC peripheral base address.
 */
void LLC_DisableCache(LLC_Type *base)
{
    assert(base != NULL);

    LLC_BARRIER();

    /* Disable cache lookup */
    base->CCUCTCR &= ~LLC_CCUCTCR_LOOKUPEN_MASK;

    /* Disable cache fill on miss */
    base->CCUCTCR &= ~LLC_CCUCTCR_FILLEN_MASK;

    LLC_BARRIER();
}

/*!
 * brief Gets the LLC version.
 *
 * param base LLC peripheral base address.
 * param versionInfo Pointer to version information structure.
 */
void LLC_GetVersion(LLC_Type *base, llc_version_info_t *versionInfo)
{
    assert(base != NULL);
    assert(versionInfo != NULL);

    uint32_t reg = base->CCUIDR;

    versionInfo->major = (uint8_t)((reg & LLC_CCUIDR_MAIRELVER_MASK) >> LLC_CCUIDR_MAIRELVER_SHIFT);
    versionInfo->minor = (uint8_t)((reg & LLC_CCUIDR_MINRELVER_MASK) >> LLC_CCUIDR_MINRELVER_SHIFT);
    versionInfo->patch = (uint8_t)((reg & LLC_CCUIDR_PATCHRELVER_MASK) >> LLC_CCUIDR_PATCHRELVER_SHIFT);
}

/*!
 * brief Gets LLC feature capabilities.
 *
 * param base LLC peripheral base address.
 * param feature Pointer to feature capability to query.
 */
void LLC_GetCapabilities(LLC_Type *base, llc_feature_capability_t *feature)
{
    assert(base != NULL);
    assert(feature != NULL);

    /* Hardware Information (CCUHI) */
    uint32_t hi = base->CCUHI;
    feature->cacheLineSize =
        (llc_cache_line_size_t)((hi & LLC_CCUHI_CACHELINESIZE_MASK) >> LLC_CCUHI_CACHELINESIZE_SHIFT);
    feature->axiDataWidth = (llc_axi_data_width_t)((hi & LLC_CCUHI_AXIDATAWIDTH_MASK) >> LLC_CCUHI_AXIDATAWIDTH_SHIFT);

    /* Performance Monitor Hardware Information (CCUPMHI) */
    uint32_t pmhi         = base->CCUPMHI;
    feature->freeRun      = (((pmhi & LLC_CCUPMHI_FREERUN_MASK) >> LLC_CCUPMHI_FREERUN_SHIFT) != 0U);
    feature->counterWidth = (uint8_t)((pmhi & LLC_CCUPMHI_COUNTERWIDTH_MASK) >> LLC_CCUPMHI_COUNTERWIDTH_SHIFT);
}

/*!
 * brief Cleans and invalidates the entire cache.
 *
 * This operation evicts all dirty line and invalidates all lines from ways designed as valid
 * by the CCUCMWVR register in the cache and leaves all entries of these valid ways in an invalid state.
 *
 * param base LLC peripheral base address.
 * return kStatus_Success Cache invalidation succeeded.
 * return kStatus_Timeout Maintenance operation timeout.
 */
status_t LLC_CleanInvalidateCache(LLC_Type *base)
{
    assert(base != NULL);

    /* Set maintenance location registers to zero */
    base->CCUCMLR0 = 0U;
    base->CCUCMLR1 = 0U;

    /* Perform flush valid entries operation on tag array */
    return LLC_RunMaintenance(base, 0U, kLLC_MaintenanceFlushValidEntries);
}

/*!
 * brief Cleans and invalidates cache at specific set and way.
 *
 * This API evicts a dirty line. It invalidates all lines at the specified physical set and way in the cache.
 * It leaves the entry in the invalid state.
 *
 * param base LLC peripheral base address.
 * param set Cache set index, starting from 0.
 * param way Cache way index, starting from 0.
 * return kStatus_Success Cache invalidation succeeded.
 * return kStatus_InvalidArgument Invalid set or way.
 * return kStatus_Timeout Maintenance operation timeout.
 */
status_t LLC_CleanInvalidateCacheAtSetAndWay(LLC_Type *base, uint16_t set, uint8_t way)
{
    assert(base != NULL);

    /* Validate parameters */
    if (way >= LLC_WAY_NUMBER || set >= LLC_SET_NUMBER)
    {
        return kStatus_InvalidArgument;
    }

    /* Set maintenance location registers */
    base->CCUCMLR0 = LLC_CCUCMLR0_MNTSET(set) | LLC_CCUCMLR0_MNTWAY(way) | LLC_CCUCMLR0_MNTWORD(0U);
    base->CCUCMLR1 = 0U;

    /* Perform flush entry at set and way operation */
    return LLC_RunMaintenance(base, 0U, kLLC_MaintenanceFlushEntrySetWay);
}

/*!
 * brief Cleans and invalidates cache at address.
 *
 * This operation evicts a dirty line and invalidates all lines matching the specified address,
 * if any, in the cache and leaves the entry in the invalid state.
 *
 * param base LLC peripheral base address.
 * param address 32 bits cache line address to invalidate.
 * return kStatus_Success Cache invalidation succeeded.
 * return kStatus_Timeout Maintenance operation timeout.
 */
status_t LLC_CleanInvalidateCacheAtAddress(LLC_Type *base, uint32_t address)
{
    assert(base != NULL);

    uint32_t cacheLineOffsetBits = LLC_GetCacheLineOffsetBits(base);
    assert(cacheLineOffsetBits > 0U);

    uint32_t lineLow = address >> cacheLineOffsetBits;

    /* Program address (low bits across MNTSET/MNTWAY/MNTWORD, high bits into MNTADDR) */
    base->CCUCMLR0 = lineLow;
    base->CCUCMLR1 = 0U;

    /* Perform flush entry at address operation */
    return LLC_RunMaintenance(base, 0U, kLLC_MaintenanceFlushEntryAddress);
}

/*!
 * brief Cleans and invalidates cache at address range.
 *
 * This operation evicts a dirty line and invalidates all lines matching the specified address,
 * if any, in the cache and leaves the entry in the invalid state.
 *
 * param base LLC peripheral base address.
 * param address 32 bits starting cache line address to invalidate.
 * param sizeInCacheLines Number of cache lines to invalidate.
 * return kStatus_Success Cache invalidation succeeded.
 * return kStatus_Timeout Maintenance operation timeout.
 */
status_t LLC_CleanInvalidateCacheAtAddressRange(LLC_Type *base, uint32_t address, uint16_t sizeInCacheLines)
{
    assert(base != NULL);

    uint32_t cacheLineOffsetBits = LLC_GetCacheLineOffsetBits(base);
    assert(cacheLineOffsetBits > 0U);

    uint32_t lineLow = address >> cacheLineOffsetBits;

    base->CCUCMLR0 = lineLow;
    base->CCUCMLR1 = 0U;
    base->CCUCMLR2 = (base->CCUCMLR2 & ~LLC_CCUCMLR2_MNTRANGE_MASK) | LLC_CCUCMLR2_MNTRANGE(sizeInCacheLines + 1U);

    /* Perform flush address range operation */
    return LLC_RunMaintenance(base, 0U, kLLC_MaintenanceFlushAddressRange);
}

/*!
 * brief Cleans and invalidates cache at set and way range.
 *
 * This operation evicts all dirty lines and invalidates all lines within the specified physical
 * set and way range in the cache.
 *
 * param base LLC peripheral base address.
 * param set Starting cache set index.
 * param way Starting cache way index.
 * param sizeInCacheLines Number of cache lines to invalidate.
 * return kStatus_Success Cache invalidation succeeded.
 * return kStatus_InvalidArgument Invalid parameters.
 * return kStatus_Timeout Maintenance operation timeout.
 */
status_t LLC_CleanInvalidateCacheAtSetWayRange(LLC_Type *base, uint16_t set, uint8_t way, uint16_t sizeInCacheLines)
{
    assert(base != NULL);

    /* Validate parameters */
    if ((way >= LLC_WAY_NUMBER) || (set >= LLC_SET_NUMBER) || (sizeInCacheLines == 0U))
    {
        return kStatus_InvalidArgument;
    }

    /* Set maintenance location registers */
    base->CCUCMLR0 = LLC_CCUCMLR0_MNTSET(set) | LLC_CCUCMLR0_MNTWAY(way) | LLC_CCUCMLR0_MNTWORD(0U);
    base->CCUCMLR1 = 0U;
    base->CCUCMLR2 = (base->CCUCMLR2 & ~LLC_CCUCMLR2_MNTRANGE_MASK) | LLC_CCUCMLR2_MNTRANGE(sizeInCacheLines + 1U);

    /* Perform flush set way range operation */
    return LLC_RunMaintenance(base, 0U, kLLC_MaintenanceFlushSetWayRange);
}

/*!
 * brief Cleans and invalidates cache by range using physical address.
 *
 * This API uses the physical address to locate the corresponding LLC instance,
 * aligns the range to cache line boundaries, and issues one or more address-range
 * maintenance operations to invalidate the requested memory region.
 *
 * The operation evicts any dirty lines in the affected range (write-back) and
 * invalidates them.
 *
 * param address   The physical start address.
 * param sizeByte  Size of the memory to be invalidated in bytes. Must be > 0. Better to align to cache line size.
 * return kStatus_Success Cache invalidation succeeded.
 * return kStatus_InvalidArgument Invalid parameters.
 * return kStatus_Timeout Maintenance operation timeout.
 */
status_t LLC_CleanInvalidateCacheByRange(uint32_t address, uint32_t sizeByte)
{
    /* Validate inputs */
    assert(sizeByte > 0U);
    assert(address < UINT32_MAX - sizeByte);

    /* Determine the LLC instance from the start address */
    uint32_t instance = LLC_GetInstanceByAddr(address);
    if (instance >= ARRAY_SIZE(s_llcBases))
    {
        return kStatus_InvalidArgument;
    }
    /* Get the LLC base for this instance */
    LLC_Type *base = s_llcBases[instance];
    /* Align the start address down to the nearest cache line boundary */
    uint32_t startAddress = MSDK_REG_SECURE_ADDR(LLC_AlignAddressToCacheLine(base, address));
    /* Compute inclusive end address of requested range */
    uint32_t endAddress = address + sizeByte - 1U;
    uint32_t endAddressLimitation;
    uint32_t cacheLineNumber = 0U;

    uint32_t phyMemBase[FSL_FEATURE_SOC_LLC_COUNT][LLC_PHYMEM_COLUMN_COUNT];
    uint32_t phyMemSize[FSL_FEATURE_SOC_LLC_COUNT][LLC_PHYMEM_COLUMN_COUNT];
    memcpy(phyMemBase, s_llcPhymemBases, sizeof(s_llcPhymemBases));
    memcpy(phyMemSize, s_llcPhymemSizes, sizeof(s_llcPhymemSizes));

    endAddressLimitation = phyMemBase[instance][g_llcMemPhyAliasId] + phyMemSize[instance][g_llcMemPhyAliasId] - 1U;
    endAddress           = (endAddress > endAddressLimitation) ? endAddressLimitation : endAddress;
    endAddress           = MSDK_REG_SECURE_ADDR(LLC_AlignAddressToCacheLine(base, endAddress));

    /* Compute the number of cache lines to invalidate */
    cacheLineNumber = (uint16_t)(((endAddress - startAddress) >> LLC_GetCacheLineOffsetBits(base)) + 1U);

    /* Invalidate at the current cache line address */
    return LLC_CleanInvalidateCacheAtAddressRange(base, startAddress, cacheLineNumber);
}

/*!
 * brief Configures the scratchpad.
 *
 * param base LLC peripheral base address.
 * param config Pointer to scratchpad configuration.
 * return kStatus_Success Scratchpad configuration succeeded.
 * return kStatus_InvalidArgument Invalid configuration.
 */
status_t LLC_ConfigScratchpad(LLC_Type *base, const llc_scratchpad_config_t *config)
{
    assert(base != NULL);
    assert(config != NULL);

    /* Validate parameters */
    if ((config->numberOfWays == 0U) || (config->numberOfWays >= LLC_WAY_NUMBER) || (config->size == 0U))
    {
        return kStatus_InvalidArgument;
    }

    if (config->enable)
    {
        /* Align scratchpad base address */
        uint32_t alignedBaseAddress = LLC_AlignAddressToCacheLine(base, config->baseAddress);
        /* Configure scratchpad base address */
        base->CCUSPBR0 = LLC_CCUSPBR0_SCPADBASEADDR(alignedBaseAddress);

        /* Configure scratchpad size */
        base->CCUSPCR1 = LLC_CCUSPCR1_SCPADSIZE(config->size - 1U);

        /* Configure and enable scratchpad */
        base->CCUSPCR0 = (base->CCUSPCR0 & ~(LLC_CCUSPCR0_NUMSCPADWAYS_MASK | LLC_CCUSPCR0_SCPADEN_MASK)) |
                         LLC_CCUSPCR0_NUMSCPADWAYS(config->numberOfWays - 1U) | LLC_CCUSPCR0_SCPADEN_MASK;
    }
    else
    {
        /* Disable scratchpad */
        base->CCUSPCR0 &= ~LLC_CCUSPCR0_SCPADEN_MASK;
    }

    return kStatus_Success;
}

/*!
 * brief Sets cache override configuration.
 *
 * param base LLC peripheral base address.
 * param overrideType Type of cache override to configure.
 * param overrideValue Cache override value (AxCACHE bits).
 * return kStatus_Success Cache override configuration succeeded.
 * return kStatus_InvalidArgument Invalid parameters.
 */
status_t LLC_SetCacheOverride(LLC_Type *base, llc_cache_override_t overrideType, uint8_t overrideValue)
{
    assert(base != NULL);

    switch (overrideType)
    {
        case kLLC_CacheOverrideWrite:
            /* Set write channel override value and enable */
            base->CCUCAOR = (base->CCUCAOR & ~(LLC_CCUCAOR_AWALLOCVALUE_MASK | LLC_CCUCAOR_AWALLOCEN_MASK)) |
                            LLC_CCUCAOR_AWALLOCVALUE(overrideValue) | LLC_CCUCAOR_AWALLOCEN_MASK;
            break;

        case kLLC_CacheOverrideRead:
            /* Set read channel override value and enable */
            base->CCUCAOR = (base->CCUCAOR & ~(LLC_CCUCAOR_ARALLOCVALUE_MASK | LLC_CCUCAOR_ARALLOCEN_MASK)) |
                            LLC_CCUCAOR_ARALLOCVALUE(overrideValue) | LLC_CCUCAOR_ARALLOCEN_MASK;
            break;

        case kLLC_CacheOverrideDisable:
            /* Disable both read and write channel overrides */
            base->CCUCAOR &= ~(LLC_CCUCAOR_AWALLOCEN_MASK | LLC_CCUCAOR_ARALLOCEN_MASK);
            break;

        default:
            return kStatus_InvalidArgument;
    }

    return kStatus_Success;
}

/*!
 * brief Configures way partitioning.
 *
 * param base LLC peripheral base address.
 * param partitionIndex Way partition control register set index (0-7).
 * param config Pointer to way partitioning configuration.
 * return kStatus_Success Way partitioning configuration succeeded.
 * return kStatus_InvalidArgument Invalid parameters.
 */
status_t LLC_ConfigWayPartition(LLC_Type *base, uint8_t partitionIndex, const llc_way_partition_config_t *config)
{
    assert(base != NULL);
    assert(config != NULL);

    /* Validate partition index */
    if (partitionIndex >= LLC_WAY_PARTITION_COUNT)
    {
        return kStatus_InvalidArgument;
    }

    /* Configure way partitioning based on partition index */
    volatile uint32_t *agentIdReg;
    volatile uint32_t *wayVectorReg;

    switch (partitionIndex)
    {
        case 0U:
            agentIdReg   = &base->CCUWPCR00;
            wayVectorReg = &base->CCUWPCR10;
            break;
        case 1U:
            agentIdReg   = &base->CCUWPCR01;
            wayVectorReg = &base->CCUWPCR11;
            break;
        case 2U:
            agentIdReg   = &base->CCUWPCR02;
            wayVectorReg = &base->CCUWPCR12;
            break;
        case 3U:
            agentIdReg   = &base->CCUWPCR03;
            wayVectorReg = &base->CCUWPCR13;
            break;
        case 4U:
            agentIdReg   = &base->CCUWPCR04;
            wayVectorReg = &base->CCUWPCR14;
            break;
        case 5U:
            agentIdReg   = &base->CCUWPCR05;
            wayVectorReg = &base->CCUWPCR15;
            break;
        case 6U:
            agentIdReg   = &base->CCUWPCR06;
            wayVectorReg = &base->CCUWPCR16;
            break;
        case 7U:
            agentIdReg   = &base->CCUWPCR07;
            wayVectorReg = &base->CCUWPCR17;
            break;
        default:
            return kStatus_InvalidArgument;
    }

    if (config->enable)
    {
        /* Configure agent ID and enable */
        *agentIdReg = (*agentIdReg & ~(LLC_CCUWPCR00_WPAGENTID_MASK | LLC_CCUWPCR00_WPAGENTIDVALID_MASK)) |
                      LLC_CCUWPCR00_WPAGENTID(config->agentId) | LLC_CCUWPCR00_WPAGENTIDVALID_MASK;

        /* Configure way vector */
        *wayVectorReg =
            (*wayVectorReg & ~LLC_CCUWPCR10_WPWAYVECTOR_MASK) | LLC_CCUWPCR10_WPWAYVECTOR(config->wayVector);
    }
    else
    {
        /* Disable way partitioning for this partition */
        *agentIdReg &= ~LLC_CCUWPCR00_WPAGENTIDVALID_MASK;
    }

    return kStatus_Success;
}

/*!
 * brief Enables or disables error detection.
 *
 * param base LLC peripheral base address.
 * param errorType Type of error detection to configure.
 * param enable True to enable, false to disable.
 * return kStatus_Success Error detection configuration succeeded.
 * return kStatus_InvalidArgument Invalid error type.
 */
status_t LLC_EnableErrorDetection(LLC_Type *base, llc_error_type_t errorType, bool enable)
{
    assert(base != NULL);

    if ((errorType & kLLC_ErrorCorrectable) != 0U)
    {
        base->CCUCECR = (base->CCUCECR & ~LLC_CCUCECR_ERRDETEN_MASK) | LLC_CCUCECR_ERRDETEN(enable ? 1U : 0U);
    }

    if ((errorType & kLLC_ErrorUncorrectableMemory) != 0U)
    {
        base->CCUUEDR = (base->CCUUEDR & ~LLC_CCUUEDR_MEMERRDETEN_MASK) | LLC_CCUUEDR_MEMERRDETEN(enable ? 1U : 0U);
    }

    if ((errorType & kLLC_ErrorUncorrectableProtocol) != 0U)
    {
        base->CCUUEDR = (base->CCUUEDR & ~LLC_CCUUEDR_PROTERRDETEN_MASK) | LLC_CCUUEDR_PROTERRDETEN(enable ? 1U : 0U);
    }

    return kStatus_Success;
}

/*!
 * brief Gets error status.
 *
 * Note: errorStatus->correctableErrorValid and errorStatus->uncorrectableErrorValid
 * reflect the same hardware bits exposed as status flags by LLC_GetStatusFlags().
 * Prefer LLC_GetStatusFlags() for quick checks; use this API for full details.
 *
 * param base LLC peripheral base address.
 * param errorStatus Pointer to error status structure.
 * return kStatus_Success Error status retrieved successfully.
 * return kStatus_InvalidArgument Invalid argument.
 */
status_t LLC_GetErrorStatus(LLC_Type *base, llc_error_status_t *errorStatus)
{
    assert(base != NULL);
    assert(errorStatus != NULL);

    uint32_t cesr = base->CCUCESR;
    uint32_t uesr = base->CCUUESR;

    /* Read correctable error status */
    errorStatus->correctableErrorValid = ((cesr & LLC_CCUCESR_CERRVLD_MASK) != 0U);
    errorStatus->correctableErrorType  = (uint8_t)((cesr & LLC_CCUCESR_CERRTYPE_MASK) >> LLC_CCUCESR_CERRTYPE_SHIFT);
    errorStatus->correctableErrorInfo  = (uint16_t)((cesr & LLC_CCUCESR_CERRINFO_MASK) >> LLC_CCUCESR_CERRINFO_SHIFT);
    errorStatus->correctableErrorLoc0  = base->CCUCELR0;
    errorStatus->correctableErrorLoc1  = base->CCUCELR1;

    /* Read uncorrectable error status */
    errorStatus->uncorrectableErrorValid = ((uesr & LLC_CCUUESR_UERRVLD_MASK) != 0U);
    errorStatus->uncorrectableErrorType  = (uint8_t)((uesr & LLC_CCUUESR_UERRTYPE_MASK) >> LLC_CCUUESR_UERRTYPE_SHIFT);
    errorStatus->uncorrectableErrorInfo  = (uesr & LLC_CCUUESR_UERRINFO_MASK) >> LLC_CCUUESR_UERRINFO_SHIFT;
    errorStatus->uncorrectableErrorLoc0  = base->CCUUELR0;
    errorStatus->uncorrectableErrorLoc1  = base->CCUUELR1;

    return kStatus_Success;
}

/*!
 * brief Enable LLC interrupts.
 *
 * param base LLC peripheral base address.
 * param mask Mask of interrupts to enable. This is a logical OR of members of the
 *             enumeration ::llc_interrupt_enable_t
 */
void LLC_EnableInterrupts(LLC_Type *base, uint32_t mask)
{
    assert(base != NULL);

    mask &= (uint32_t)kLLC_AllInterruptsEnable;

    uint32_t cecrValue = base->CCUCECR;
    uint32_t uedrValue = base->CCUUEDR;
    uint32_t ueirValue = base->CCUUEIR;
    uint32_t emrValue  = base->CCUEMR;

    if ((mask & kLLC_CorrectableErrorInterruptEnable) != 0U)
    {
        cecrValue |= (uint32_t)(LLC_CCUCECR_ERRDETEN_MASK | LLC_CCUCECR_ERRINTEN_MASK);
    }

    if ((mask & kLLC_UncorrectableErrorMemoryProtectionErrorInterruptEnable) != 0U)
    {
        uedrValue |= (uint32_t)LLC_CCUUEDR_MEMERRDETEN_MASK;
        ueirValue |= (uint32_t)LLC_CCUUEIR_MEMERRINTEN_MASK;
    }

    if ((mask & kLLC_UncorrectableErrorProtocolErrorInterruptEnable) != 0U)
    {
        uedrValue |= (uint32_t)LLC_CCUUEDR_PROTERRDETEN_MASK;
        ueirValue |= (uint32_t)LLC_CCUUEIR_PROTERRINTEN_MASK;
    }

    if ((mask & kLLC_MaintenanceCompletionInterruptEnable) != 0U)
    {
        emrValue |= LLC_CCUEMR_MASK(0x01U);
    }

    if ((mask & kLLC_PerformanceMonitorInterruptEnable) != 0U)
    {
        emrValue |= LLC_CCUEMR_MASK(0x02U);
    }

    base->CCUCECR = cecrValue;
    base->CCUUEDR = uedrValue;
    base->CCUUEIR = ueirValue;
    base->CCUEMR  = emrValue;
}

/*!
 * brief Disable LLC interrupts.
 *
 * param base LLC peripheral base address.
 * param mask Mask of interrupts to disable. This is a logical OR of members of the
 *             enumeration ::llc_interrupt_enable_t
 */
void LLC_DisableInterrupts(LLC_Type *base, uint32_t mask)
{
    assert(base != NULL);

    mask &= (uint32_t)kLLC_AllInterruptsEnable;

    uint32_t cecrValue = base->CCUCECR;
    uint32_t ueirValue = base->CCUUEIR;
    uint32_t emrValue  = base->CCUEMR;

    /* Correctable error */
    if ((mask & kLLC_CorrectableErrorInterruptEnable) != 0U)
    {
        cecrValue &= (uint32_t)(~(LLC_CCUCECR_ERRDETEN_MASK & LLC_CCUCECR_ERRINTEN_MASK));
    }

    /* Uncorrectable memory protection error (only interrupt enable bit cleared) */
    if ((mask & kLLC_UncorrectableErrorMemoryProtectionErrorInterruptEnable) != 0U)
    {
        ueirValue &= (uint32_t)(~LLC_CCUUEIR_MEMERRINTEN_MASK);
    }

    /* Uncorrectable protocol error (only interrupt enable bit cleared) */
    if ((mask & kLLC_UncorrectableErrorProtocolErrorInterruptEnable) != 0U)
    {
        ueirValue &= (uint32_t)(~LLC_CCUUEIR_PROTERRINTEN_MASK);
    }

    /* Maintenance complete */
    if ((mask & kLLC_MaintenanceCompletionInterruptEnable) != 0U)
    {
        emrValue &= ~LLC_CCUEMR_MASK(0x01U);
    }

    /* Performance monitor */
    if ((mask & kLLC_PerformanceMonitorInterruptEnable) != 0U)
    {
        emrValue &= ~LLC_CCUEMR_MASK(0x02U);
    }

    base->CCUCECR = cecrValue;
    base->CCUUEIR = ueirValue;
    base->CCUEMR  = emrValue;
}

/*!
 * brief Gets enabled LLC interrupts.
 *
 * param base LLC peripheral base address.
 * return Mask of enabled interrupts. This is a logical OR of members of the
 *         enumeration ::llc_interrupt_enable_t
 */
uint32_t LLC_GetEnabledInterrupts(LLC_Type *base)
{
    assert(base != NULL);

    uint32_t mask = 0U;

    uint32_t cecrValue = base->CCUCECR;
    uint32_t uedrValue = base->CCUUEDR;
    uint32_t ueirValue = base->CCUUEIR;
    uint32_t emrValue  = base->CCUEMR;

    /* Correctable error */
    if (((cecrValue & LLC_CCUCECR_ERRDETEN_MASK) != 0U) && ((cecrValue & LLC_CCUCECR_ERRINTEN_MASK) != 0U))
    {
        mask |= (uint32_t)kLLC_CorrectableErrorInterruptEnable;
    }

    /* Uncorrectable memory protection error */
    if (((uedrValue & LLC_CCUUEDR_MEMERRDETEN_MASK) != 0U) && ((ueirValue & LLC_CCUUEIR_MEMERRINTEN_MASK) != 0U))
    {
        mask |= (uint32_t)kLLC_UncorrectableErrorMemoryProtectionErrorInterruptEnable;
    }

    /* Uncorrectable protocol error */
    if (((uedrValue & LLC_CCUUEDR_PROTERRDETEN_MASK) != 0U) && ((ueirValue & LLC_CCUUEIR_PROTERRINTEN_MASK) != 0U))
    {
        mask |= (uint32_t)kLLC_UncorrectableErrorProtocolErrorInterruptEnable;
    }

    /* Maintenance completion (event bit0) */
    if ((emrValue & LLC_CCUEMR_MASK(0x01U)) != 0U)
    {
        mask |= (uint32_t)kLLC_MaintenanceCompletionInterruptEnable;
    }

    /* Performance monitor (event bit1) */
    if ((emrValue & LLC_CCUEMR_MASK(0x02U)) != 0U)
    {
        mask |= (uint32_t)kLLC_PerformanceMonitorInterruptEnable;
    }

    return mask;
}

/*!
 * brief Gets LLC status flags.
 *
 * Note: The error-valid flags reported here (kLLC_CorrectableErrorValidFlag and
 * kLLC_UncorrectableErrorValidFlag) mirror the corresponding fields returned by
 * LLC_GetErrorStatus(). Use this function for a quick poll; call LLC_GetErrorStatus()
 * when you need detailed error information.
 *
 * param base LLC peripheral base address.
 * return LLC status flags. This is a logical OR of members of the
 *         enumeration ::llc_status_flags_t
 */
uint32_t LLC_GetStatusFlags(LLC_Type *base)
{
    assert(base != NULL);

    uint32_t flags      = 0U;
    uint32_t errorFlags = 0U;

    /* Correctable error valid */
    if ((base->CCUCESR & LLC_CCUCESR_CERRVLD_MASK) != 0U)
    {
        flags |= (uint32_t)kLLC_CorrectableErrorValidFlag;
    }

    /* Uncorrectable error valid */
    if ((base->CCUUESR & LLC_CCUUESR_UERRVLD_MASK) != 0U)
    {
        flags |= (uint32_t)kLLC_UncorrectableErrorValidFlag;
    }

    errorFlags = base->CCUESR;

    /* Maintenance operation complete */
    if ((errorFlags & LLC_CCUESR_STATUS(0x01U)) != 0U)
    {
        flags |= (uint32_t)kLLC_MaintenanceCompletionFlag;
    }

    /* Performance monitor event */
    if ((errorFlags & LLC_CCUESR_STATUS(0x02U)) != 0U)
    {
        flags |= (uint32_t)kLLC_PerformanceMonitorEventFlag;
    }

    return flags;
}

/*!
 * brief Clears LLC status flags.
 *
 * param base LLC peripheral base address.
 * param mask Mask of status flags to clear. This is a logical OR of members of the
 *             enumeration ::llc_status_flags_t
 */
void LLC_ClearStatusFlags(LLC_Type *base, uint32_t mask)
{
    assert(base != NULL);

    uint32_t eventClearMask = 0U;

    mask &= (uint32_t)kLLC_AllFlags;

    if ((mask & kLLC_CorrectableErrorValidFlag) != 0U)
    {
        /* Clear correctable error valid flag (write-1-to-clear) */
        base->CCUCESR = (uint32_t)LLC_CCUCESR_CERRVLD_MASK;
    }

    if ((mask & kLLC_UncorrectableErrorValidFlag) != 0U)
    {
        /* Clear uncorrectable error valid flag (write-1-to-clear) */
        base->CCUUESR = (uint32_t)LLC_CCUUESR_UERRVLD_MASK;
    }

    if ((mask & kLLC_MaintenanceCompletionFlag) != 0U)
    {
        eventClearMask |= LLC_CCUESR_STATUS(0x01U);
    }
    if ((mask & kLLC_PerformanceMonitorEventFlag) != 0U)
    {
        eventClearMask |= LLC_CCUESR_STATUS(0x02U);
    }
    if (eventClearMask != 0U)
    {
        /* Clear event flags by writing to CCUESR */
        base->CCUESR = eventClearMask;
    }
}

/*!
 * brief Initializes performance monitor.
 */
status_t LLC_InitPerformanceMonitor(LLC_Type *base, const llc_performance_config_t *config)
{
    assert(base != NULL);
    assert(config != NULL);

    uint32_t durationField = 0U;

    /* Validate threshold values */
    if ((config->rttThreshold > 7U) || (config->wttThreshold > 7U))
    {
        return kStatus_InvalidArgument;
    }

    /* Reset performance counters */
    LLC_ResetPerformanceCounters(base);

    /* Configure performance monitor */
    base->CCUPMCTL = (base->CCUPMCTL & ~(LLC_CCUPMCTL_ENABLE_MASK | LLC_CCUPMCTL_HARDWARE_TRIGGER_MASK)) |
                     LLC_CCUPMCTL_ENABLE(config->enable ? 1U : 0U) |
                     LLC_CCUPMCTL_HARDWARE_TRIGGER(config->hardwareTrigger ? 1U : 0U);

    /* duration register expects (value - 1); saturate if user passes 0 to avoid underflow */
    durationField = (config->duration == 0U) ? 0U : (config->duration - 1U);
    /* Configure slot duration */
    base->CCUPMSC = (base->CCUPMSC & ~LLC_CCUPMSC_DURATION_MASK) | LLC_CCUPMSC_DURATION(durationField);

    /* Configure thresholds */
    base->CCUPMOTC = (base->CCUPMOTC & ~(LLC_CCUPMOTC_RTT_MASK | LLC_CCUPMOTC_WTT_MASK)) |
                     LLC_CCUPMOTC_RTT(config->rttThreshold) | LLC_CCUPMOTC_WTT(config->wttThreshold);

    return kStatus_Success;
}

/*!
 * brief Starts performance monitoring.
 */
void LLC_StartPerformanceMonitor(LLC_Type *base)
{
    assert(base != NULL);

    base->CCUPMCTL |= LLC_CCUPMCTL_ENABLE_MASK;
}

/*!
 * brief Stops performance monitoring.
 */
void LLC_StopPerformanceMonitor(LLC_Type *base)
{
    assert(base != NULL);

    base->CCUPMCTL &= ~LLC_CCUPMCTL_ENABLE_MASK;
}

/*!
 * brief Resets performance monitor counters.
 */
void LLC_ResetPerformanceCounters(LLC_Type *base)
{
    assert(base != NULL);

    /* Trigger software reset of counters */
    base->CCUPMCTL |= LLC_CCUPMCTL_SWRESET_MASK;

    /* Clear the reset bit */
    base->CCUPMCTL &= ~LLC_CCUPMCTL_SWRESET_MASK;
}

/*!
 * brief Gets performance monitor counters.
 */
status_t LLC_GetPerformanceCounters(LLC_Type *base, llc_performance_counters_t *counters)
{
    assert(base != NULL);
    assert(counters != NULL);

    /* Read all performance counters */
    counters->cycleCounter             = base->CCUPMCYCO;
    counters->readRequestCounter       = base->CCUPMRRCO;
    counters->writeRequestCounter      = base->CCUPMWRCO;
    counters->cacheableReadCounter     = base->CCUPMCRRCO;
    counters->cacheableWriteCounter    = base->CCUPMCWRCO;
    counters->readHitCounter           = base->CCUPMRHCO;
    counters->writeHitCounter          = base->CCUPMWHCO;
    counters->evictionCounter          = base->CCUPMECO;
    counters->readBeatCounter          = base->CCUPMRBCO;
    counters->writeBeatCounter         = base->CCUPMWBCO;
    counters->rttAboveThresholdCounter = base->CCUPMRATCO;
    counters->wttAboveThresholdCounter = base->CCUPMWATCO;

    return kStatus_Success;
}

/*!
 * brief LLC interrupt handler.
 *
 * This function is called when the LLC interrupt occurs.
 * It clears the interrupt flags and calls the registered callback function if set.
 */
void CMPT_LLC_DriverIRQHandler(void);
void CMPT_LLC_DriverIRQHandler(void)
{
    uint32_t interrupt_flags = LLC_GetStatusFlags(CMPT__LLC);

    LLC_ClearStatusFlags(CMPT__LLC, interrupt_flags);

    if ((s_LLCCallback != NULL) && (interrupt_flags != 0U))
    {
        /* Invoke callback once per asserted flag (Option A) */
        if ((interrupt_flags & (uint32_t)kLLC_CorrectableErrorValidFlag) != 0U)
        {
            s_LLCCallback(kLLC_CorrectableErrorCallback);
        }
        if ((interrupt_flags & (uint32_t)kLLC_UncorrectableErrorValidFlag) != 0U)
        {
            s_LLCCallback(kLLC_UncorrectableErrorCallback);
        }
        if ((interrupt_flags & (uint32_t)kLLC_MaintenanceCompletionFlag) != 0U)
        {
            s_LLCCallback(kLLC_MaintenanceCompletionCallback);
        }
        if ((interrupt_flags & (uint32_t)kLLC_PerformanceMonitorEventFlag) != 0U)
        {
            s_LLCCallback(kLLC_PerformanceMonitorCallback);
        }
    }

    SDK_ISR_EXIT_BARRIER;
}
