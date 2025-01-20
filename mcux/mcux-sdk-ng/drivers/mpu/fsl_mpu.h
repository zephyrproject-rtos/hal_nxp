/*
 * The Clear BSD License
 * Copyright (c) 2015 - 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2017, 2021 NXP
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted (subject to the limitations in the disclaimer below) provided
 *  that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * NO EXPRESS OR IMPLIED LICENSES TO ANY PARTY'S PATENT RIGHTS ARE GRANTED BY THIS LICENSE.
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef FSL_MPU_H_
#define FSL_MPU_H_

#include "fsl_common.h"
#include "fsl_device_registers.h"

/*!
 * @addtogroup mpu
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#if (__CORTEX_M == 33U)
#define MPU_MAIR_InnerAttr_Pos  0U                                 /*!< MPU MAIR: Inner Memory Attribute Position */
#define MPU_MAIR_InnerAttr_Msk  (0x0FU << MPU_MAIR_InnerAttr_Pos)  /*!< MPU MAIR: Inner Memory Attribute Mask */
#define MPU_MAIR_OuterAttr_Pos  4U                                 /*!< MPU MAIR: Outer Memory Attribute Position */
#define MPU_MAIR_OuterAttr_Msk  (0x0FU << MPU_MAIR_OuterAttr_Pos)  /*!< MPU MAIR: Outer Memory Attribute Mask */
#define MPU_MAIR_DeviceAttr_Pos 2U                                 /*!< MPU MAIR: Device Memory Attribute Position */
#define MPU_MAIR_DeviceAttr_Msk (0x12U << MPU_MAIR_DeviceAttr_Pos) /*!< MPU MAIR: Device Memory Attribute Mask */
#endif                                                             /* #if (__CORTEX_M = 33U) */

enum
{
    kMPU_MinRegionSizeInBytes       = 256,
    kMPU_MinRegionSizeInPower       = 8,
    kMPU_MinRegionSizeInBytesARMv8m = 32,
};

#if (__CORTEX_M != 33U)
typedef enum _mpu_access_attribute
{
    kMPU_FlashRegionAttribute =
        (1U << MPU_RASR_XN_Pos) | (3U << MPU_RASR_AP_Pos) |
        MPU_RASR_C_Msk, /*!< Instruction fectches disabled. Full access. Normal memory, Non-shareable, write-through. */
    kMPU_RAMRegionAttributeWithCode =
        (3U << MPU_RASR_AP_Pos) | MPU_RASR_C_Msk |
        MPU_RASR_S_Msk, /*!< Instruction fectches enabled. Full access. Normal memory, Shareable, write-through*/
    kMPU_RAMRegionAttributeWithoutCode =
        (1U << MPU_RASR_XN_Pos) | (3U << MPU_RASR_AP_Pos) | MPU_RASR_C_Msk |
        MPU_RASR_S_Msk, /*!< Instruction fectches disabled. Full access. Normal memory, Shareable, write-through*/
    kMPU_ROMRegionAttribute = (6U << MPU_RASR_AP_Pos), /*!< Instruction fectches enabled. Read-only. */
    kMPU_DefaultRegionAttribute =
        (1U << MPU_RASR_XN_Pos) | (3U << MPU_RASR_AP_Pos) | MPU_RASR_S_Msk |
        MPU_RASR_B_Msk, /*!< Instruction fectches disabled. Full access. Device memory, Shareable*/
} mpu_access_attribute_t;
#else
/* MAIR_ATTR definition for normal memory (Outer!=0), the enum is used for both Outer and Inner attributes definition */
typedef enum _mpu_normal_memory_attribute
{
    kMPU_NormalMemory_WTTWA   = 1U,  /*!< Normal Memory, Write-Through transient, write allocate. */
    kMPU_NormalMemory_WTTRA   = 2U,  /*!< Normal Memory, Write-Through transient, read allocate. */
    kMPU_NormalMemory_WTTRAWA = 3U,  /*!< Normal Memory, Write-Through transient, read allocate, write allocate. */
    kMPU_NormalMemory         = 4U,  /*!< Normal Memory, Non-cacheable */
    kMPU_NormalMemory_WBTWA   = 5U,  /*!< Normal Memory, Write-Back transient, write allocate. */
    kMPU_NormalMemory_WBTRA   = 6U,  /*!< Normal Memory, Write-Back transient, read allocate. */
    kMPU_NormalMemory_WBTRAWA = 7U,  /*!< Normal Memory, Write-Back transient, read allocate, write allocate. */
    kMPU_NormalMemory_WTWA    = 9U,  /*!< Normal Memory, Write-Through non-transient, write allocate. */
    kMPU_NormalMemory_WTRA    = 10U, /*!< Normal Memory, Write-Through non-transient, read allocate. */
    kMPU_NormalMemory_WTRAWA  = 11U, /*!< Normal Memory, Write-Through non-transient, read allocate, write allocate. */
    kMPU_NormalMemory_WBWA    = 13U, /*!< Normal Memory, Write-Back non-transient, write allocate. */
    kMPU_NormalMemory_WBRA    = 14U, /*!< Normal Memory, Write-Back non-transient, read allocate. */
    kMPU_NormalMemory_WBRAWA  = 15U, /*!< Normal Memory, Write-Back non-transient, read allocate, write allocate. */
} mpu_normal_memory_attribute_t;

/* MAIR_ATTR definition for device memory (Outer=0), the enum is used for device attributes definition */
typedef enum _mpu_device_memory_attribute
{
    kMPU_DeviceMemory_nGnRnE = 0U, /*!< Device Memory, non-Gathering, non-Reordering, no Early Write Acknowledge. */
    kMPU_DeviceMemory_nGnRE =
        ((1U << MPU_MAIR_DeviceAttr_Pos) &
         MPU_MAIR_DeviceAttr_Msk), /*!< Device Memory, non-Gathering, non-Reordering, Early Write Acknowledge. */
    kMPU_DeviceMemory_nGRE =
        ((2U << MPU_MAIR_DeviceAttr_Pos) &
         MPU_MAIR_DeviceAttr_Msk), /*!< Device Memory, non-Gathering, Reordering, Early Write Acknowledge. */
    kMPU_DeviceMemory_GRE =
        ((3U << MPU_MAIR_DeviceAttr_Pos) &
         MPU_MAIR_DeviceAttr_Msk), /*!< Device Memory, Gathering, Reordering, Early Write Acknowledge. */
} mpu_device_memory_attribute_t;

/* The enum is used for SH, AP and XN definition in RBAR register */
typedef enum _mpu_access_attribute
{
    kMPU_FlashAccessAttribute =
        ((2U << MPU_RBAR_AP_Pos) |
         (1U << MPU_RBAR_XN_Pos)), /*!< Read in priviledge mode only, Never Execute, Non-shareable*/
    kMPU_RAMAccessAttributeWithCode =
        (2U << MPU_RBAR_SH_Pos), /*!< Read/Write in priviledge mode only,  Outer Shareable*/
    kMPU_RAMAccessAttributeWithoutCode =
        ((2U << MPU_RBAR_SH_Pos) |
         (1U << MPU_RBAR_XN_Pos)), /*!< Read/Write in priviledge mode only,  Outer Shareable, Never Execute*/
    kMPU_ROMAccessAttribute = (2U << MPU_RBAR_AP_Pos), /*!< Read in priviledge mode only, Non-shareable*/
} mpu_access_attribute_t;

/* The enum is used for AttrX definition in MAIRx registers */
typedef enum _mpu_region_attribute
{
    kMPU_InternalMemoryAttrIndex = 0, /*!< Attr0 in MAIR0 register */
    kMPU_PeripheralsAttrIndex    = 1, /*!< Attr1 in MAIR0 register*/
} mpu_region_attribute_t;
#endif /* #if (__CORTEX_M != 33U) */

/*!
 * MPU region configuration structure.
 *
 * This structure is used to configure the regionNum region.
 */
typedef struct _mpu_region_config
{
    uint32_t regionNum;   /*!< MPU region number, range form 0 ~ MPU->TYPE[DREGION] - 1. */
    uint32_t baseAddress; /*!< Memory region start address. Note: bit0 ~ bit4 must always be marked as 0. */
#if (__CORTEX_M == 33U)
    uint32_t sizeInBytes;
    uint32_t regionAttributeIndex;
    uint32_t accessAttribute;
#else
    uint32_t sizeInPower; /*!< Memory region Size. Note: Not size in bytes, it is the power of 2. */
    uint32_t attribute;   /* PMU region attribute. Note: bit0 ~ bit 15 must always be marked as 0 */
#endif /* if ( __CORTEX_M == 33U) */

} mpu_region_config_t;

/*******************************************************************************
 * Externs
 ******************************************************************************/

/*******************************************************************************
 * API
 ******************************************************************************/

/*!
 * @name Initialization and deinitialization
 * @{
 */

/*!
 * Initializes the MPU with the user configuration structure.
 *
 * This function configures the MPU module with the user-defined configuration.
 *
 * @param base          MPU peripheral base address.
 * @param config        The pointer to the configuration structure. If config==NULL
 *                      the control is written to MPU_CTRL register only
 * @param regionCount   The number of elements in config structure
 * @param control       The value written into MPU_CTRL register at
 *                      the end of configuration (PRIVDEFENA, HFNMIENA, ENABLE bits)
 * @return              The result status.
 *                      kStatus_Success  - Sucess for the operation.
 *                      kStatus_Fail - Error happen during the operation.
 */
status_t MPU_Init(MPU_Type *base, const mpu_region_config_t config[], uint32_t regionCount, uint32_t control);

/*!
 * Deinitializes the MPU regions.
 *
 * @param base     MPU peripheral base address.
 * @return The result status.
 *         kStatus_Success  - Sucess for the operation.
 *         kStatus_Fail - Error happen during the operation.
 */
status_t MPU_Deinit(MPU_Type *base);

/*! @} */

/*!
 * @name Basic Control Operations
 * @{
 */

/*!
 * Returns number of implemented regions in MPU.
 *
 * Call this API to enable the MPU module.
 *
 * @param base     MPU peripheral base address.
 */
static inline uint32_t MpuRegionCount(MPU_Type *base)
{
    return (base->TYPE & MPU_TYPE_DREGION_Msk) >> MPU_TYPE_DREGION_Pos;
}

/*!
 * Enables the MPU globally.
 *
 * Call this API to enable the MPU module.
 *
 * @param base     MPU peripheral base address.
 */
static inline void MpuEnable(MPU_Type *base)
{
    base->CTRL |= MPU_CTRL_ENABLE_Msk;
}

/*!
 * Disables the MPU globally.
 *
 * Call this API to disable the MPU module.
 *
 * @param base     MPU peripheral base address.
 */
static inline void MpuDisable(MPU_Type *base)
{
    base->CTRL &= ~MPU_CTRL_ENABLE_Msk;
}

/*! @} */

/*! @} */

#endif /* FSL_MPU_H_ */
