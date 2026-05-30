/*
 * Copyright 2026 NXP
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef FSL_MBC_H_
#define FSL_MBC_H_

#include "fsl_common.h"

/*!
 * @defgroup mbc MBC: Memory Block Checker Driver
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*! @{ */
/*! @brief MBC driver version. */
#define FSL_MBC_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*! @} */

/*!
 * @brief Hardware configuration of one slave memory in a MBC instance.
 */
typedef struct _trdc_slave_memory_hardware_config
{
    uint32_t blockNum;  /*!< Number of blocks. */
    uint32_t blockSize; /*!< Block size as log2 value. */
} trdc_slave_memory_hardware_config_t;

/*!
 * @brief Access control policy for a MBC memory access control register.
 *
 * This platform uses primary access (Core0/DMA0) and secondary access (Core1/DMA1)
 * instead of secure/nonsecure privilege/user distinctions.
 * primaryX/W/R maps to PAX/PAW/PAR (Core0/DMA0 access bits).
 * secondaryX/W/R maps to SAX/SAW/SAR (Core1/DMA1 access bits).
 */
typedef struct _trdc_memory_access_control_config
{
    uint32_t : 8U;
    uint32_t secondaryX : 1U; /*!< Secondary execute access. */
    uint32_t secondaryW : 1U; /*!< Secondary write access. */
    uint32_t secondaryR : 1U; /*!< Secondary read access. */
    uint32_t : 1U;
    uint32_t primaryX : 1U;   /*!< Primary execute access. */
    uint32_t primaryW : 1U;   /*!< Primary write access. */
    uint32_t primaryR : 1U;   /*!< Primary read access. */
    uint32_t : 16U;
    uint32_t lock : 1U;       /*!< Lock bit. Once set, the register cannot be written. */
} trdc_memory_access_control_config_t;

/*!
 * @brief Enumeration of MBC slave memory indices.
 */
enum _trdc_MBC_memory
{
    kTRDC_MbcSlaveMemory0 = (1U << 0U), /*!< MBC slave memory 0. */
    kTRDC_MbcSlaveMemory1 = (1U << 1U), /*!< MBC slave memory 1. */
    kTRDC_MbcSlaveMemory2 = (1U << 2U), /*!< MBC slave memory 2. */
    kTRDC_MbcSlaveMemory3 = (1U << 3U), /*!< MBC slave memory 3. */
};

/*!
 * @brief Configuration of a MBC memory block.
 */
typedef struct _trdc_mbc_memory_block_config
{
    uint32_t memoryAccessControlSelect : 3U; /*!< Index of the memory access control policy register to use. */
    uint32_t : 1U;                           /*!< Reserved. */
    uint32_t mbcIdx : 4U;                    /*!< MBC hardware index within the TRDC instance. */
    uint32_t domainIdx : 8U;                 /*!< Domain index. */
    uint32_t slaveMemoryIdx : 8U;            /*!< Slave memory index within the MBC. */
    uint32_t memoryBlockIdx : 8U;            /*!< Block index within the slave memory. */
} trdc_mbc_memory_block_config_t;

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Gets the hardware configuration of a slave memory in a MBC instance.
 *
 * @param base  TRDC peripheral base address.
 * @param config Pointer to the structure to receive the configuration.
 * @param mbcIdx MBC hardware index.
 * @param slvIdx Slave memory index.
 */
void TRDC_GetMbcHardwareConfig(TRDC_Type *base,
                               trdc_slave_memory_hardware_config_t *config,
                               uint8_t mbcIdx,
                               uint8_t slvIdx);

/*!
 * @brief Sets the memory access control policy for a MBC access control register.
 *
 * @param base   TRDC peripheral base address.
 * @param config Pointer to the access control configuration.
 * @param mbcIdx MBC hardware index.
 * @param rgdIdx Access control register index (0–7).
 */
void TRDC_MbcSetMemoryAccessConfig(TRDC_Type *base,
                                   const trdc_memory_access_control_config_t *config,
                                   uint8_t mbcIdx,
                                   uint8_t rgdIdx);

/*!
 * @brief Configures the access policy of a single MBC memory block.
 *
 * @param base   TRDC peripheral base address.
 * @param config Pointer to the block configuration.
 */
void TRDC_MbcSetMemoryBlockConfig(TRDC_Type *base, const trdc_mbc_memory_block_config_t *config);

/*!
 * @brief Clears the MBC access violation error.
 *
 * @param base   TRDC peripheral base address.
 * @param mbcIdx MBC hardware index.
 */
static inline void TRDC_MbcClearError(TRDC_Type *base, uint8_t mbcIdx)
{
    base->MBC_INDEX[mbcIdx].MBC_MEM_GLBCFG[3] |= TRDC_MBC_MEM_GLBCFG_CLRE(1U);
}

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */

#endif /* FSL_MBC_H_ */
