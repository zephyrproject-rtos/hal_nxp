/*
 * Copyright 2018-2019 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "fsl_iap.h"
#include "fsl_iap_ffr.h"
#include "fsl_device_registers.h"
/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.iap1"
#endif

/*!
 * @addtogroup flash_driver_api
 * @{
 */

#define BOOTLOADER_API_TREE_POINTER ((bootloader_tree_t *)0x130010f0U)

static uint32_t versionMajor = 0U;

typedef union functionCommandOption
{
    uint32_t commandAddr;
    status_t (*eraseCommend)(flash_config_t *config, uint32_t start, uint32_t lengthInBytes, uint32_t key);
    status_t (*programCommend)(flash_config_t *config, uint32_t start, uint8_t *src, uint32_t lengthInBytes);
    status_t (*verifyProgramCommend)(flash_config_t *config,
                                     uint32_t start,
                                     uint32_t lengthInBytes,
                                     const uint8_t *expectedData,
                                     uint32_t *failedAddress,
                                     uint32_t *failedData);
} function_command_option_t;

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
    StandardVersion() : version(0)
    {
    }
    StandardVersion(uint32_t version) : version(version)
    {
    }
#endif
} standard_version_t;

/*! @brief Interface for the flash driver.*/
typedef struct version1FlashDriverInterface
{
    standard_version_t version; /*!< flash driver API version number.*/

    /*!< Flash driver.*/
    status_t (*flash_init)(flash_config_t *config);
    status_t (*flash_erase)(flash_config_t *config, uint32_t start, uint32_t lengthInBytes, uint32_t key);
    status_t (*flash_program)(flash_config_t *config, uint32_t start, uint8_t *src, uint32_t lengthInBytes);
    status_t (*flash_verify_erase)(flash_config_t *config, uint32_t start, uint32_t lengthInBytes);
    status_t (*flash_verify_program)(flash_config_t *config,
                                     uint32_t start,
                                     uint32_t lengthInBytes,
                                     const uint8_t *expectedData,
                                     uint32_t *failedAddress,
                                     uint32_t *failedData);
    status_t (*flash_get_property)(flash_config_t *config, flash_property_tag_t whichProperty, uint32_t *value);
    uint32_t reserved[3]; /*! Reserved for future use */
    /*!< Flash FFR driver*/
    status_t (*ffr_init)(flash_config_t *config);
    status_t (*ffr_deinit)(flash_config_t *config);
    status_t (*ffr_cust_factory_page_write)(flash_config_t *config, uint8_t *page_data, bool seal_part);
    status_t (*ffr_get_uuid)(flash_config_t *config, uint8_t *uuid);
    status_t (*ffr_get_customer_data)(flash_config_t *config, uint8_t *pData, uint32_t offset, uint32_t len);
    status_t (*ffr_keystore_write)(flash_config_t *config, ffr_key_store_t *pKeyStore);
    status_t (*ffr_keystore_get_ac)(flash_config_t *config, uint8_t *pActivationCode);
    status_t (*ffr_keystore_get_kc)(flash_config_t *config, uint8_t *pKeyCode, ffr_key_type_t keyIndex);
    status_t (*ffr_infield_page_write)(flash_config_t *config, uint8_t *page_data, uint32_t valid_len);
    status_t (*ffr_get_customer_infield_data)(flash_config_t *config, uint8_t *pData, uint32_t offset, uint32_t len);
} version1_flash_driver_interface_t;

/*! @brief Interface for the flash driver.*/
typedef struct version0FlashDriverInterface
{
    standard_version_t version; /*!< flash driver API version number.*/

    /*!< Flash driver.*/
    status_t (*flash_init)(flash_config_t *config);
    status_t (*flash_erase)(flash_config_t *config, uint32_t start, uint32_t lengthInBytes, uint32_t key);
    status_t (*flash_program)(flash_config_t *config, uint32_t start, uint8_t *src, uint32_t lengthInBytes);
    status_t (*flash_verify_erase)(flash_config_t *config, uint32_t start, uint32_t lengthInBytes);
    status_t (*flash_verify_program)(flash_config_t *config,
                                     uint32_t start,
                                     uint32_t lengthInBytes,
                                     const uint8_t *expectedData,
                                     uint32_t *failedAddress,
                                     uint32_t *failedData);
    status_t (*flash_get_property)(flash_config_t *config, flash_property_tag_t whichProperty, uint32_t *value);

    /*!< Flash FFR driver*/
    status_t (*ffr_init)(flash_config_t *config);
    status_t (*ffr_deinit)(flash_config_t *config);
    status_t (*ffr_cust_factory_page_write)(flash_config_t *config, uint8_t *page_data, bool seal_part);
    status_t (*ffr_get_uuid)(flash_config_t *config, uint8_t *uuid);
    status_t (*ffr_get_customer_data)(flash_config_t *config, uint8_t *pData, uint32_t offset, uint32_t len);
    status_t (*ffr_keystore_write)(flash_config_t *config, ffr_key_store_t *pKeyStore);
    status_t (*ffr_keystore_get_ac)(flash_config_t *config, uint8_t *pActivationCode);
    status_t (*ffr_keystore_get_kc)(flash_config_t *config, uint8_t *pKeyCode, ffr_key_type_t keyIndex);
    status_t (*ffr_infield_page_write)(flash_config_t *config, uint8_t *page_data, uint32_t valid_len);
    status_t (*ffr_get_customer_infield_data)(flash_config_t *config, uint8_t *pData, uint32_t offset, uint32_t len);
} version0_flash_driver_interface_t;

typedef union flashDriverInterface
{
    const version1_flash_driver_interface_t *version1FlashDriver;
    const version0_flash_driver_interface_t *version0FlashDriver;
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
    void (*runBootloader)(void *arg);      /*!< Function to start the bootloader executing. */
    standard_version_t bootloader_version; /*!< Bootloader version number. */
    const char *copyright;                 /*!< Copyright string. */
    const uint32_t *reserved;              /*!< Do NOT use. */
    flash_driver_interface_t flashDriver;
    function_command_option_t runCmdFuncOption;
} bootloader_tree_t;

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*! Get pointer to flash driver API table in ROM. */
#define VERSION1_FLASH_API_TREE BOOTLOADER_API_TREE_POINTER->flashDriver.version1FlashDriver
#define VERSION0_FLASH_API_TREE BOOTLOADER_API_TREE_POINTER->flashDriver.version0FlashDriver
#define RUN_COMMAND_FUNC_OPTION BOOTLOADER_API_TREE_POINTER->runCmdFuncOption
/*******************************************************************************
 * Code
 ******************************************************************************/

/*! See fsl_iap.h for documentation of this function. */
status_t FLASH_Init(flash_config_t *config)
{
    assert(VERSION1_FLASH_API_TREE);
    config->modeConfig.sysFreqInMHz = (uint32_t)kSysToFlashFreq_defaultInMHz;
    versionMajor                    = BOOTLOADER_API_TREE_POINTER->bootloader_version.major;
    return VERSION0_FLASH_API_TREE->flash_init(config);
}

/*! See fsl_iap.h for documentation of this function. */
status_t FLASH_Erase(flash_config_t *config, uint32_t start, uint32_t lengthInBytes, uint32_t key)
{
    if (versionMajor == 2U)
    {
        RUN_COMMAND_FUNC_OPTION.commandAddr = 0x1300413bU; /*!< get the flash erase api location adress in rom */
        return RUN_COMMAND_FUNC_OPTION.eraseCommend(config, start, lengthInBytes, key);
    }
    else
    {
        assert(VERSION1_FLASH_API_TREE);
        return VERSION1_FLASH_API_TREE->flash_erase(config, start, lengthInBytes, key);
    }
}

/*! See fsl_iap.h for documentation of this function. */
status_t FLASH_Program(flash_config_t *config, uint32_t start, uint8_t *src, uint32_t lengthInBytes)
{
    if (versionMajor == 2U)
    {
        RUN_COMMAND_FUNC_OPTION.commandAddr = 0x1300419dU; /*!< get the flash program api location adress in rom*/
        return RUN_COMMAND_FUNC_OPTION.programCommend(config, start, src, lengthInBytes);
    }
    else
    {
        assert(VERSION1_FLASH_API_TREE);
        return VERSION1_FLASH_API_TREE->flash_program(config, start, src, lengthInBytes);
    }
}

/*! See fsl_iap.h for documentation of this function. */
status_t FLASH_VerifyErase(flash_config_t *config, uint32_t start, uint32_t lengthInBytes)
{
    assert(VERSION1_FLASH_API_TREE);
    return VERSION1_FLASH_API_TREE->flash_verify_erase(config, start, lengthInBytes);
}

/*! See fsl_iap.h for documentation of this function. */
status_t FLASH_VerifyProgram(flash_config_t *config,
                             uint32_t start,
                             uint32_t lengthInBytes,
                             const uint8_t *expectedData,
                             uint32_t *failedAddress,
                             uint32_t *failedData)
{
    if (versionMajor == 2U)
    {
        RUN_COMMAND_FUNC_OPTION.commandAddr = 0x1300427dU; /*!< get the flash verify program api location adress in rom*/
        return RUN_COMMAND_FUNC_OPTION.verifyProgramCommend(config, start, lengthInBytes, expectedData, failedAddress,
                                                            failedData);
    }
    else
    {
        assert(VERSION1_FLASH_API_TREE);
        return VERSION1_FLASH_API_TREE->flash_verify_program(config, start, lengthInBytes, expectedData, failedAddress,
                                                             failedData);
    }
}

/*! See fsl_iap.h for documentation of this function.*/
status_t FLASH_GetProperty(flash_config_t *config, flash_property_tag_t whichProperty, uint32_t *value)
{
    assert(VERSION1_FLASH_API_TREE);
    return VERSION1_FLASH_API_TREE->flash_get_property(config, whichProperty, value);
}
/********************************************************************************
 * fsl iap ffr CODE
 *******************************************************************************/

/*! See fsl_iap_ffr.h for documentation of this function. */
status_t FFR_Init(flash_config_t *config)
{
    if (versionMajor == 2U)
    {
        assert(VERSION0_FLASH_API_TREE);
        return VERSION0_FLASH_API_TREE->ffr_init(config);
    }
    else
    {
        assert(VERSION1_FLASH_API_TREE);
        return VERSION1_FLASH_API_TREE->ffr_init(config);
    }
}

/*! See fsl_iap_ffr.h for documentation of this function. */
status_t FFR_Deinit(flash_config_t *config)
{
    if (versionMajor == 2U)
    {
        assert(VERSION0_FLASH_API_TREE);
        return VERSION0_FLASH_API_TREE->ffr_deinit(config);
    }
    else
    {
        assert(VERSION1_FLASH_API_TREE);
        return VERSION1_FLASH_API_TREE->ffr_deinit(config);
    }
}

/*! See fsl_iap_ffr.h for documentation of this function. */
status_t FFR_CustFactoryPageWrite(flash_config_t *config, uint8_t *page_data, bool seal_part)
{
    if (versionMajor == 2U)
    {
        assert(VERSION0_FLASH_API_TREE);
        return VERSION0_FLASH_API_TREE->ffr_cust_factory_page_write(config, page_data, seal_part);
    }
    else
    {
        assert(VERSION1_FLASH_API_TREE);
        return VERSION1_FLASH_API_TREE->ffr_cust_factory_page_write(config, page_data, seal_part);
    }
}

/*! See fsl_iap_ffr.h for documentation of this function. */
status_t FFR_GetUUID(flash_config_t *config, uint8_t *uuid)
{
    if (versionMajor == 2U)
    {
        assert(VERSION0_FLASH_API_TREE);
        return VERSION0_FLASH_API_TREE->ffr_get_uuid(config, uuid);
    }
    else
    {
        assert(VERSION1_FLASH_API_TREE);
        return VERSION1_FLASH_API_TREE->ffr_get_uuid(config, uuid);
    }
}

/*! See fsl_iap_ffr.h for documentation of this function. */
status_t FFR_GetCustomerData(flash_config_t *config, uint8_t *pData, uint32_t offset, uint32_t len)
{
    if (versionMajor == 2U)
    {
        assert(VERSION0_FLASH_API_TREE);
        return VERSION0_FLASH_API_TREE->ffr_get_customer_data(config, pData, offset, len);
    }
    else
    {
        assert(VERSION1_FLASH_API_TREE);
        return VERSION1_FLASH_API_TREE->ffr_get_customer_data(config, pData, offset, len);
    }
}

/*! See fsl_iap_ffr.h for documentation of this function. */
status_t FFR_KeystoreWrite(flash_config_t *config, ffr_key_store_t *pKeyStore)
{
    if (versionMajor == 2U)
    {
        assert(VERSION0_FLASH_API_TREE);
        return VERSION0_FLASH_API_TREE->ffr_keystore_write(config, pKeyStore);
    }
    else
    {
        assert(VERSION1_FLASH_API_TREE);
        return VERSION1_FLASH_API_TREE->ffr_keystore_write(config, pKeyStore);
    }
}

/*! See fsl_iap_ffr.h for documentation of this function. */
status_t FFR_KeystoreGetAC(flash_config_t *config, uint8_t *pActivationCode)
{
    if (versionMajor == 2U)
    {
        assert(VERSION0_FLASH_API_TREE);
        return VERSION0_FLASH_API_TREE->ffr_keystore_get_ac(config, pActivationCode);
    }
    else
    {
        assert(VERSION1_FLASH_API_TREE);
        return VERSION1_FLASH_API_TREE->ffr_keystore_get_ac(config, pActivationCode);
    }
}

/*! See fsl_iap_ffr.h for documentation of this function. */
status_t FFR_KeystoreGetKC(flash_config_t *config, uint8_t *pKeyCode, ffr_key_type_t keyIndex)
{
    if (versionMajor == 2U)
    {
        assert(VERSION0_FLASH_API_TREE);
        return VERSION0_FLASH_API_TREE->ffr_keystore_get_kc(config, pKeyCode, keyIndex);
    }
    else
    {
        assert(VERSION1_FLASH_API_TREE);
        return VERSION1_FLASH_API_TREE->ffr_keystore_get_kc(config, pKeyCode, keyIndex);
    }
}

/*! See fsl_iap_ffr.h for documentation of this function. */
status_t FFR_InfieldPageWrite(flash_config_t *config, uint8_t *page_data, uint32_t valid_len)
{
    if (versionMajor == 2U)
    {
        assert(VERSION0_FLASH_API_TREE);
        return VERSION0_FLASH_API_TREE->ffr_infield_page_write(config, page_data, valid_len);
    }
    else
    {
        assert(VERSION1_FLASH_API_TREE);
        return VERSION1_FLASH_API_TREE->ffr_infield_page_write(config, page_data, valid_len);
    }
}

/*! See fsl_iap_ffr.h for documentation of this function. */
status_t FFR_GetCustomerInfieldData(flash_config_t *config, uint8_t *pData, uint32_t offset, uint32_t len)
{
    if (versionMajor == 2U)
    {
        assert(VERSION0_FLASH_API_TREE);
        return VERSION0_FLASH_API_TREE->ffr_get_customer_infield_data(config, pData, offset, len);
    }
    else
    {
        assert(VERSION1_FLASH_API_TREE);
        return VERSION1_FLASH_API_TREE->ffr_get_customer_infield_data(config, pData, offset, len);
    }
}

/*! @}*/

/********************************************************************************
 * EOF
 *******************************************************************************/
