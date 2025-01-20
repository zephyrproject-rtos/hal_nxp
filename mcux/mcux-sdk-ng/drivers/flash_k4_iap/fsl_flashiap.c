/*
 * Copyright 2019 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "fsl_flashiap.h"

/*!
 * @addtogroup flash_driver_api
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define BOOTLOADER_API_TREE_POINTER ((bootloader_tree_t *)0x1481046CU)

/*
 *!@brief Structure of version property.
 *
 *!@ingroup bl_core
 */
typedef union StandardVersion
{
    struct
    {
        uint32_t bugfix : 8; /*!< bugfix version [7:0] */
        uint32_t minor : 8;  /*!< minor version [15:8] */
        uint32_t major : 8;  /*!< major version [23:16] */
        uint32_t name : 8;   /*!< name [31:24] */
    };
    uint32_t version; /*!< combined version numbers. */
#if defined(__cplusplus)
    StandardVersion() : version(0U)
    {
    }
    StandardVersion(uint32_t version) : version(version)
    {
    }
#endif
} standard_version_t;

/*! @brief Interface for the flash driver.*/
typedef struct FlashDriverInterface
{
    // Flash driver
    status_t (*flash_init)(flash_config_t *config);
    status_t (*flash_erase_sector)(flash_config_t *config, uint32_t start, uint32_t lengthInBytes, uint32_t key);
    // status_t (*flash_erase_all)(uint32_t key); // Remove erase all from api, S3 will block this command when it's not
    // FA return state
    status_t (*flash_program_phrase)(flash_config_t *config,
                                     uint32_t start,
                                     const uint32_t *src,
                                     uint32_t lengthInBytes);
    status_t (*flash_program_page)(flash_config_t *config, uint32_t start, const uint32_t *src, uint32_t lengthInBytes);
    status_t (*flash_verify_erase_all)();
    status_t (*flash_verify_erase_block)(flash_config_t *config, uint32_t blockaddr);
    status_t (*flash_verify_erase_phrase)(flash_config_t *config, uint32_t start, uint32_t lengthInBytes);
    status_t (*flash_verify_erase_page)(flash_config_t *config, uint32_t start, uint32_t lengthInBytes);
    status_t (*flash_verify_erase_sector)(flash_config_t *config, uint32_t start, uint32_t lengthInBytes);
    status_t (*flash_get_property)(flash_config_t *config, flash_property_tag_t whichProperty, uint32_t *value);
    // IFR driver
    status_t (*ifr_verify_erase_phrase)(flash_config_t *config, uint32_t start, uint32_t lengthInBytes);
    status_t (*ifr_verify_erase_page)(flash_config_t *config, uint32_t start, uint32_t lengthInBytes);
    status_t (*ifr_verify_erase_sector)(flash_config_t *config, uint32_t start, uint32_t lengthInBytes);
    // version
    standard_version_t version; //!< flash driver API version number.
} flash_driver_interface_t;

/*!
 * @brief Root of the bootloader API tree.
 *
 * An instance of this struct resides in read-only memory in the bootloader. It
 * provides a user application access to APIs exported by the bootloader.
 *
 * @note The order of existing fields must not be changed.
 */
typedef struct BootloaderTree
{
    void (*runBootloader)(void *arg);            //!< Function to start the bootloader executing.
    const flash_driver_interface_t *flashDriver; //!< Internal Flash driver API.
    uint32_t reserved[3];                        //!< Reserved for factory use
    standard_version_t version;                  //!< Bootloader version number.
    const char *copyright;                       //!< Copyright string.
    uint32_t reserved2;                          //!< Reserved for factory use.
} bootloader_tree_t;

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*! @brief Global pointer to the flash driver API table in ROM. */
flash_driver_interface_t *FLASH_API_TREE;
/*! Get pointer to flash driver API table in ROM. */
#define FLASH_API_TREE BOOTLOADER_API_TREE_POINTER->flashDriver

/*******************************************************************************
 * Code
 ******************************************************************************/

status_t FLASH_Init(flash_config_t *config)
{
    assert(FLASH_API_TREE);
    status_t status;
    status = FLASH_API_TREE->flash_init(config);

    return status;
}

status_t FLASH_Erase(flash_config_t *config, uint32_t start, uint32_t lengthInBytes, uint32_t key)
{
    assert(FLASH_API_TREE);
    status_t status;
    status = FLASH_API_TREE->flash_erase_sector(config, start, lengthInBytes, key);

    return status;
}

status_t FLASH_Program(flash_config_t *config, uint32_t start, const uint32_t *src, uint32_t lengthInBytes)
{
    assert(FLASH_API_TREE);
    status_t status;
    status = FLASH_API_TREE->flash_program_phrase(config, start, src, lengthInBytes);

    return status;
}

status_t FLASH_ProgramPage(flash_config_t *config, uint32_t start, const uint32_t *src, uint32_t lengthInBytes)
{
    assert(FLASH_API_TREE);
    status_t status;
    status = FLASH_API_TREE->flash_program_page(config, start, src, lengthInBytes);

    return status;
}

status_t FLASH_VerifyErasePhrase(flash_config_t *config, uint32_t start, uint32_t lengthInBytes)
{
    assert(FLASH_API_TREE);
    status_t status;
    status = FLASH_API_TREE->flash_verify_erase_phrase(config, start, lengthInBytes);

    return status;
}

status_t FLASH_VerifyErasePage(flash_config_t *config, uint32_t start, uint32_t lengthInBytes)
{
    assert(FLASH_API_TREE);
    status_t status;
    status = FLASH_API_TREE->flash_verify_erase_page(config, start, lengthInBytes);

    return status;
}

status_t FLASH_VerifyEraseSector(flash_config_t *config, uint32_t start, uint32_t lengthInBytes)
{
    assert(FLASH_API_TREE);
    status_t status;
    status = FLASH_API_TREE->flash_verify_erase_sector(config, start, lengthInBytes);

    return status;
}

status_t FLASH_VerifyEraseAll(flash_config_t *config)
{
    assert(FLASH_API_TREE);
    status_t status;
    status = FLASH_API_TREE->flash_verify_erase_all(config);

    return status;
}

status_t FLASH_VerifyEraseBlock(flash_config_t *config, uint32_t blockaddr)
{
    assert(FLASH_API_TREE);
    status_t status;
    status = FLASH_API_TREE->flash_verify_erase_block(config, blockaddr);

    return status;
}

status_t FLASH_GetProperty(flash_config_t *config, flash_property_tag_t whichProperty, uint32_t *value)
{
    assert(FLASH_API_TREE);
    status_t status;
    status = FLASH_API_TREE->flash_get_property(config, whichProperty, value);

    return status;
}

void FLASH_CACHE_Disable()
{
    SMSCM->OCMDR0 = (SMSCM->OCMDR0 & (~SMSCM_CACHE_CLEAR_MASK)) | SMSCM_CACHE_CLEAR(0x1);
    SMSCM->OCMDR0 = (SMSCM->OCMDR0 & (~SMSCM_CACHE_CLEAR_MASK)) | SMSCM_CACHE_CLEAR(0x8);
    SMSCM->OCMDR0 = (SMSCM->OCMDR0 & (~SMSCM_SPECULATION_DISABLE_MASK)) | SMSCM_SPECULATION_DISABLE_MASK;
    __ISB();
    __DSB();
}

// TODO: Add speculation clear to this function and add this to flash api
void FLASH_CACHE_Clear()
{
    SMSCM->OCMDR0 |= (SMSCM->OCMDR0 & (~SMSCM_CACHE_CLEAR_MASK)) | SMSCM_CACHE_CLEAR(0x1);
    /* Memory barriers for good measure.
     * All Cache, Branch predictor and TLB maintenance operations before this instruction complete */
    __ISB();
    __DSB();
}

status_t FLASH_VerifyEraseIFRPhrase(flash_config_t *config, uint32_t start, uint32_t lengthInBytes)
{
    assert(FLASH_API_TREE);
    status_t status;
    status = FLASH_API_TREE->ifr_verify_erase_phrase(config, start, lengthInBytes);

    return status;
}

status_t FLASH_VerifyEraseIFRPage(flash_config_t *config, uint32_t start, uint32_t lengthInBytes)
{
    assert(FLASH_API_TREE);
    status_t status;
    status = FLASH_API_TREE->ifr_verify_erase_page(config, start, lengthInBytes);

    return status;
}

status_t FLASH_VerifyEraseIFRSector(flash_config_t *config, uint32_t start, uint32_t lengthInBytes)
{
    assert(FLASH_API_TREE);
    status_t status;
    status = FLASH_API_TREE->ifr_verify_erase_sector(config, start, lengthInBytes);

    return status;
}
