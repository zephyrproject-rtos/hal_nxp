/*
 * Copyright 2026 NXP
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_mbc.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.mbc"
#endif

/* Domain configuration register block size in DSC word addresses. */
#define TRDC_MBC_DOMAIN_INCREMENT 0x200UL

/* Offset from MBC_DOM0_MEM0_BLK_CFG_W[0] to the first block config word of
 * each slave memory, expressed in DSC word addresses.
 * MEM0 base is the reference (offset 0).  Values derived from PERI_TRDC.h
 * struct layout (DSC word addressing: each uint32_t = 2 address units). */
#define TRDC_MBC_SLAVE_INCREMENT(x) \
    (((x) == 0U) ? (0U) : (((x) == 1U) ? (0xA0UL) : (((x) == 2U) ? (0xB4UL) : (0xC8UL))))

/* Each block-config word covers 8 blocks (4 bits each).
 * On DSC, each uint32_t register occupies 2 address units. */
#define TRDC_MBC_SLAVE_WORD_INCREMENT 2U

/* 4 slave indexes in total. */
#define TRDC_MBC_SLAVE_COUNT 4U

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/

/* Helper union to convert between bitfield structs and raw uint32_t without
 * violating strict-aliasing rules. */
typedef union
{
    trdc_memory_access_control_config_t _memory_access_control;
    trdc_mbc_memory_block_config_t _mbc_memory_blk;
    uint32_t _u32;
} mbc_reg32_convert_t;

/*!
 * brief Gets the hardware configuration of a slave memory in a MBC instance.
 *
 * param base   TRDC peripheral base address.
 * param config Pointer to structure to receive the configuration.
 * param mbcIdx MBC hardware index.
 * param slvIdx Slave memory index.
 */
void TRDC_GetMbcHardwareConfig(TRDC_Type *base,
                               trdc_slave_memory_hardware_config_t *config,
                               uint8_t mbcIdx,
                               uint8_t slvIdx)
{
    assert(NULL != config);
    assert(mbcIdx < (uint8_t)TRDC_MBC_INDEX_COUNT);
    assert(slvIdx < TRDC_MBC_SLAVE_COUNT);

    uint32_t glbConfig = base->MBC_INDEX[mbcIdx].MBC_MEM_GLBCFG[slvIdx];

    config->blockNum = glbConfig & TRDC_MBC_MEM_GLBCFG_NBLKS_MASK;
    config->blockSize =
        (glbConfig & TRDC_MBC_MEM_GLBCFG_SIZE_LOG2_MASK) >> TRDC_MBC_MEM_GLBCFG_SIZE_LOG2_SHIFT;
}

/*!
 * brief Sets the memory access control policy for a MBC access control register.
 *
 * param base   TRDC peripheral base address.
 * param config Pointer to the access control configuration.
 * param mbcIdx MBC hardware index.
 * param rgdIdx Access control register index (0-7).
 */
void TRDC_MbcSetMemoryAccessConfig(TRDC_Type *base,
                                   const trdc_memory_access_control_config_t *config,
                                   uint8_t mbcIdx,
                                   uint8_t rgdIdx)
{
    assert(NULL != base);
    assert(NULL != config);
    assert(rgdIdx < 8U);
    assert((base->MBC_INDEX[mbcIdx].MBC_MEMN_GLBAC[rgdIdx] & TRDC_MBC_MEMN_GLBAC_LK_MASK) == 0U);

    mbc_reg32_convert_t pid;
    pid._memory_access_control                       = *config;
    base->MBC_INDEX[mbcIdx].MBC_MEMN_GLBAC[rgdIdx] = pid._u32;
}

/*!
 * brief Configures the access policy of a single MBC memory block.
 *
 * param base   TRDC peripheral base address.
 * param config Pointer to the block configuration.
 */
void TRDC_MbcSetMemoryBlockConfig(TRDC_Type *base, const trdc_mbc_memory_block_config_t *config)
{
    assert(NULL != base);
    assert(NULL != config);
    assert(config->mbcIdx < TRDC_MBC_INDEX_COUNT);
    assert(config->slaveMemoryIdx < TRDC_MBC_SLAVE_COUNT);
    assert(config->domainIdx < FSL_FEATURE_TRDC_MBC_DOMAIN_COUNT);

    uint32_t shift      = 4UL * (config->memoryBlockIdx % 8UL);
    uint32_t regAddr    = (uint32_t) & (base->MBC_INDEX[config->mbcIdx].MBC_DOM0_MEM0_BLK_CFG_W[0]);
    uint32_t configWord = 0U;
    mbc_reg32_convert_t pid;

    pid._mbc_memory_blk = *config;
    configWord          = (pid._u32 & 0xFU) << shift;

    regAddr += (TRDC_MBC_DOMAIN_INCREMENT * config->domainIdx +
                TRDC_MBC_SLAVE_INCREMENT(config->slaveMemoryIdx)) +
               ((uint32_t)config->memoryBlockIdx / 8U) * TRDC_MBC_SLAVE_WORD_INCREMENT;

    configWord           = configWord | (*(uint32_t *)regAddr & ~(0xFUL << shift));
    *(uint32_t *)regAddr = configWord;

    assert((*(uint32_t *)regAddr & (0xFUL << shift)) == ((pid._u32 & 0xFU) << shift));
}
