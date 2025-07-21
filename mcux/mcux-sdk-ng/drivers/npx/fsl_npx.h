/*
 * Copyright 2025 NXP
 * All rights reserved.
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_NPX_H_
#define FSL_NPX_H_

#include "fsl_common.h"

/*!
 * @addtogroup npx
 * @{
 */

/*******************************************************************************
 * Definitions
 *******************************************************************************/

/*! @name Driver version */
/*! @{ */
/*! @brief NPX driver version. Version 2.0.0.
 *
 * Current version: 2.0.0
 *
 * Change log:
 *
 * - 2.0.0
 *   - Initial version
 */
#define FSL_NPX_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*! @} */

enum _npx_status
{
    kStatus_NPX_RegionIsLocked = MAKE_STATUS(kStatusGroup_NPX, 0x1),
};

#define NPX_NPXCR_LOCK_MASK (0x5550u)
  
#define NPX_SUBREGION_SIZE_IN_BYTES (32u * 1024u)
#define NPX_MAX_REGION_SIZE_IN_BYTES (2048u * 1024u)

/*! @brief NPX region. */
#define kNPX_Region0 (0U) /*!< NPX region 0 */
#define kNPX_Region1 (1U) /*!< NPX region 1 */
#define kNPX_Region2 (2U) /*!< NPX region 2 */
#define kNPX_Region3 (3U) /*!< NPX region 3 */
typedef uint32_t npx_region_t;

/*! @brief NPX lock. */
typedef enum _npx_lock
{
    kNPX_GlobalLockEnable = 0x10U,    /*!< NPX global lock */
    kNPX_MaskLockEnable   = 0x40U,    /*!< NPX mask lock */
    kNPX_Region0Lock      = 0x100U,   /*!< NPX region 0 lock */
    kNPX_Region1Lock      = 0x400U ,  /*!< NPX region 1 lock */
    kNPX_Region2Lock      = 0x1000U , /*!< NPX region 2 lock */
    kNPX_Region3Lock      = 0x4000U , /*!< NPX region 3 lock */
} npx_lock_t;

/*! @brief NPX region configuration structure. */
typedef struct _npx_region_config
{
    uint32_t startAddress;    /*!< NPX region start address */
    uint32_t endAddress;      /*!< NPX region end address */
    uint64_t subRegionEnable; /*!< NPX sub-region enable. Each bit coresponds to 8K block */
    uint64_t regionLock;      /*!< NPX sub-region enable. Each bit coresponds to 8K block */
} npx_region_config_t;

/*******************************************************************************
 * API
 ******************************************************************************/
#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Enable data encryption.
 *
 * This function enables NPX on-the-fly data encryption.
 *
 * @param base NPX peripheral address.
 */
static inline void NPX_EncryptEnable(NPX_Type *base)
{
    base->NPXCR |= (NPX_NPXCR_GEE_MASK | NPX_NPXCR_GDE_MASK);
}

/*!
 * @brief Disable data encryption.
 *
 * This function disables NPX on-the-fly data encryption.
 *
 * @param base NPX peripheral address.
 */
static inline void NPX_EncryptDisable(NPX_Type *base)
{
    base->NPXCR &= ~(NPX_NPXCR_GEE_MASK | NPX_NPXCR_GDE_MASK);
}

/*!
 * @brief Sets NPX data mask.
 *
 * This function sets the NPX mask that is used to mask decrypted data.
 *
 * @param base NPX peripheral address.
 */
static inline void NPX_SetMask(NPX_Type *base, uint32_t mask)
{
    base->CACMSK = mask;
}

/*!
 * @brief Locks access for specified region registers or data mask register.
 *
 * This function sets lock on specified region registers or mask register.
 *
 * @param base NPX peripheral address.
 * @param lock registers to lock. This is a logical OR of members of the
 *             enumeration ::npx_lock_t
 */
static inline void NPX_SetLock(NPX_Type *base, uint32_t lock)
{
    base->NPXCR |= lock & NPX_NPXCR_LOCK_MASK;
}

/*!
 * @brief Returns the NPX region context status.
 *
 * This function returns status of NPX region.
 *
 * @param base NPX peripheral address.
 * @param region Selection of the NPX region to check the status.
 */
status_t NPX_GetContextStatus(NPX_Type *base, npx_region_t region);

/*!
 * @brief Sets the NPX Region.
 *
 * This function configures NPX region.
 *
 * @param base NPX peripheral address.
 * @param region Selection of the NPX region to be configured.
 * @param config Configuration structure for NPX.
 */
status_t NPX_SetRegion(NPX_Type *base, npx_region_t region, npx_region_config_t config);

/*!
 * @brief Sets the NPX Sub-Region Enable register.
 *
 * This function configures NPX SR_ENABLE register.
 *
 * @param base NPX peripheral address.
 * @param region Selection of the NPX region to be configured.
 * @param sr_enable Sub-Region Enable register value.
 */
status_t NPX_SetRegionSREnable(NPX_Type *base, npx_region_t region, uint64_t sr_enable);

/*!
 * @brief Gets the NPX Sub-Region Enable register.
 *
 * This function gets NPX SR_ENABLE register.
 *
 * @param base NPX peripheral address.
 * @param region Selection of the NPX region.
 * @param sr_enable Sub-Region Enable register pointer.
 */
status_t NPX_GetRegionSREnable(NPX_Type *base, npx_region_t region, uint64_t *sr_enable);

/*!
 * @brief Sets the NPX region IV.
 *
 * This function sets specified AES IV for the given region.
 *
 * @param base NPX peripheral address.
 * @param region Selection of the NPX region to be configured.
 * @param iv 64-bit AES IV in little-endian byte order.
 */
status_t NPX_SetRegionIV(NPX_Type *base, npx_region_t region, const uint8_t iv[8]);

#if defined(__cplusplus)
}
#endif

/*! @} */

#endif /* FSL_NPX_H_ */
