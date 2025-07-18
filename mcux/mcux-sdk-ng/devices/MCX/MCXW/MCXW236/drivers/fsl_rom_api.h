/*
 * Copyright 2024-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef __FSL_ROM_API_H_
#define __FSL_ROM_API_H_

#include "fsl_common.h"
#include "fsl_iap_kbp.h"
#include "fsl_iap.h"
#include "fsl_iap_ffr.h"

/*!
 * @addtogroup rom_api_driver
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! Bootloader address of ROM API Tree */
#define BOOTLOADER_API_TREE_POINTER ((bootloader_tree_t *)0x1301fe00U)

/*!
 * List of skboot error codes
 */
typedef enum skboot_status_s
{
    kStatus_SKBOOT_Success = 0x5ac3c35au,
    kStatus_SKBOOT_Fail    = 0xc35ac35au
} skboot_status_t;

/*! Structure of version property.*/
typedef union standard_version_s
{
    struct
    {
        uint32_t bugfix : 8; /*!< bugfix version [7:0] */
        uint32_t minor : 8;  /*!< minor version [15:8] */
        uint32_t major : 8;  /*!< major version [23:16] */
        uint32_t name : 8;   /*!< name [31:24] */
    };
    uint32_t version; /*!< combined version numbers. */
} standard_version_t;

/*!
 * Structure defining boot arguments for RunBootloader function
 */
typedef union
{
    struct
    {
        uint32_t imageIndex : 4;
        uint32_t reserved : 12;
        uint32_t ispInterface : 4;
        uint32_t bootMode : 4;
        uint32_t tag : 8;
    } fields;
    uint32_t value;
} boot_argument_t;

/*!
 * List of ISP interfaces
 */
typedef enum boot_isp_interface_s
{
    BOOT_ISP_INTERFACE_AUTO = 0,
    BOOT_ISP_INTERFACE_UART = 2,
    BOOT_ISP_INTERFACE_SPI  = 3,
    BOOT_ISP_INTERFACE_I2C  = 4
} boot_isp_interface_t;

/*!
 * List of boot modes
 */
typedef enum boot_mode_s
{
    BOOT_MODE_PASSIVE = 0,
    BOOT_MODE_ISP     = 1
} boot_mode_t;

/*!
 * List of boot tags
 */
typedef enum boot_tag_s
{
    BOOT_TAG = 0xEB
} boot_tag_t;

/*! Interface for the flash IAP functions.*/
typedef struct flash_driver_interface_s
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
    uint32_t reserved[3];
    /*!< Flash FFR driver*/
    status_t (*ffr_init)(flash_config_t *config);
    status_t (*ffr_lock_all)(flash_config_t *config);
    status_t (*ffr_cust_factory_page_write)(flash_config_t *config, uint8_t *page_data, bool seal_part);
    status_t (*ffr_get_uuid)(flash_config_t *config, uint8_t *uuid);
    status_t (*ffr_get_customer_data)(flash_config_t *config, uint8_t *pData, uint32_t offset, uint32_t len);
    status_t (*ffr_keystore_write)(flash_config_t *config, ffr_key_store_t *pKeyStore);
    status_t (*ffr_keystore_get_ac)(flash_config_t *config, uint8_t *pActivationCode);
    status_t (*ffr_keystore_get_kc)(flash_config_t *config, uint8_t *pKeyCode, ffr_key_type_t keyIndex);
    status_t (*ffr_infield_page_write)(flash_config_t *config, uint8_t *page_data, uint32_t valid_len);
    status_t (*ffr_get_customer_infield_data)(flash_config_t *config, uint8_t *pData, uint32_t offset, uint32_t len);
} flash_driver_interface_t;
/*! @}*/

/*! Interface for the bootloader functions.*/
typedef struct kb_interface_s
{
    status_t (*kb_init)(kb_session_ref_t **session, const kb_options_t *options);
    status_t (*kb_deinit)(kb_session_ref_t *session);
    status_t (*kb_execute)(kb_session_ref_t *session, const uint8_t *data, uint32_t dataLength);
} kb_interface_t;

/*! Interface for the image authentication functions.*/
typedef struct kb_authenticate_interface_s
{
    status_t (*kb_authenticate)(const uint8_t *imageStartAddr, secure_bool_t *isSignVerified);
    void (*hashcrypt_irq_handler)(void);
} kb_authenticate_interface_t;

/*! Interface for the low power functions.*/
typedef struct lowpower_driver_interface_s
{
    void (*power_cycle_cpu_and_flash)(void);
} lowpower_driver_interface_t;

/*! Interface for the crypto engine functions.*/
typedef struct bus_crypto_engine_interface_s
{
    skboot_status_t (*bus_crypto_engine_set_encrypt_for_address_range)(uint8_t region_number,
                                                                       uint32_t start_address,
                                                                       uint32_t length,
                                                                       flash_config_t *flash_context);
} bus_crypto_engine_interface_t;

/*! Bootloader ROM API Tree.*/
typedef struct BootloaderTree
{
    void (*runBootloader)(void *arg);      /*!< Function to start the bootloader executing. */
    standard_version_t bootloader_version; /*!< Bootloader version number. */
    const char *copyright;                 /*!< Copyright string. */
    const uint32_t reserved0;              /*!< Do NOT use. */
    flash_driver_interface_t *flashDriver;
    const kb_interface_t *kbApi;                          /*!< Bootloader API. */
    const lowpower_driver_interface_t *lowpowerDriver;    /*!< Power driver API. */
    const bus_crypto_engine_interface_t *busCryptoEngine; //!< PRINCE encryption API.
    const kb_authenticate_interface_t *kbAuthenticate;    /*!< Image authentication API. */
} bootloader_tree_t;

/*! ROM implementation of HASHCRYPT interrupt handler to be used when using kb_authenticate (see kb_authenticate for
 * more details).*/
void kb_HASHCRYPT_IRQHandler(void);

/*!
 * This API function can be used to enter ISP mode from application.
 * @arg arg A pointer to the boot argument.
 */
void RunBootloader(boot_argument_t *arg);
/*@}*/

#endif /*! __FSL_FLASH_FFR_H_ */
