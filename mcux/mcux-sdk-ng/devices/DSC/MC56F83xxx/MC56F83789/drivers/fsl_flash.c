/*
 * Copyright 2019 - 2020 NXP
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_flash.h"

/*
 * MC56F83xxx has two flash blocks, it support read/execute code on one flash block while erase/program on another flash
 * block. Make sure don't access the flash block while it performs erase/program operation.
 *
 * If put the code(including ISR) only in one flash block, and erase/program another flash block, then it is OK to
 * enable the interrupt since there is no access(even the ISR) to the flash block which is performing erase/program
 * operation.
 *
 * If move the vector table, ISR code to RAM(mapping to flash space), then it is also OK to enable the interrupt, since
 * there is no access(even the ISR) to the flash block which is performing erase/program operation.
 *
 * Anyway for safety reason, it is highly recommended to disable the interrupt before ROM flash API call.
 *
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.dsc_flash"
#endif

static uint32_t array[] = {
    0x797f8, /* FLASH_Init */
    0x79a41, /* FLASH_EraseAll */
    0x79a44, /* FLASH_EraseAllUnsecure */
    0x79a09, /* FLASH_Erase */
    0x79b35, /* FLASH_GetSecurityState */
    0x79b38, /* FLASH_SecurityBypass */
    0x79af1, /* FLASH_VerifyEraseAll */
    0x79ab6, /* FLASH_VerifyErase */
    0x79af4, /* FLASH_VerifyProgram */
    0x79c3b, /* FLASH_GetProperty */
    0x79ee3, /* FLASH_ProgramOnce */
    0x7a002, /* FLASH_ReadOnce */
    0x79ab3, /* FLASH_ReadResource */
    0x79a7d, /* FLASH_ProgramSection */
    0x79b3b, /* FLASH_Swap */
};

/*********************************************************************************************************************
 *                               Structure with API function pointers members
 *********************************************************************************************************************/
/* @brief Interface for the flash driver. */
typedef struct FlashDriverInterface
{
    flash_status_t (*flash_init)(flash_config_t *config);
    flash_status_t (*flash_erase_all)(flash_config_t *config, uint32_t key);
    flash_status_t (*flash_erase_all_unsecure)(flash_config_t *config, uint32_t key);
    flash_status_t (*flash_erase)(flash_config_t *config, uint32_t start, uint32_t lengthInBytes, uint32_t key);
    flash_status_t (*flash_get_security_state)(flash_config_t *config, flash_security_state_t *state);
    flash_status_t (*flash_security_bypass)(flash_config_t *config, const uint8_t *backdoorKey);
    flash_status_t (*flash_verify_erase_all)(flash_config_t *config, flash_margin_value_t margin);
    flash_status_t (*flash_verify_erase)(flash_config_t *config,
                                         uint32_t start,
                                         uint32_t lengthInBytes,
                                         flash_margin_value_t margin);
    flash_status_t (*flash_verify_program)(flash_config_t *config,
                                           uint32_t start,
                                           uint32_t lengthInBytes,
                                           const uint8_t *expectedData,
                                           flash_margin_value_t margin,
                                           uint32_t *failedAddress,
                                           uint32_t *failedData);
    flash_status_t (*flash_get_property)(flash_config_t *config, flash_property_tag_t whichProperty, uint32_t *value);
    flash_status_t (*flash_program_once)(ftfx_config_t *config, uint32_t index, uint8_t *src, uint32_t lengthInBytes);
    flash_status_t (*flash_read_once)(ftfx_config_t *config, uint32_t index, uint8_t *dst, uint32_t lengthInBytes);
    flash_status_t (*flash_read_resource)(
        flash_config_t *config, uint32_t start, uint8_t *dst, uint32_t lengthInBytes, flash_read_resource_opt_t option);
    flash_status_t (*flash_program_section)(flash_config_t *config,
                                            uint32_t start,
                                            uint8_t *src,
                                            uint32_t lengthInBytes);
    flash_status_t (*flash_swap)(flash_config_t *config, uint32_t address, uint8_t isSetEnable);
} flash_driver_interface_t;

/*******************************************************************************
 * Variables
 ******************************************************************************/
static volatile flash_driver_interface_t *sROMFlashDrive = (flash_driver_interface_t *)array;

/*******************************************************************************
 * Code
 ******************************************************************************/
/*!
 * @brief Initializes the global flash properties structure members.
 */
flash_status_t FLASH_Init(flash_config_t *config)
{
    return sROMFlashDrive->flash_init(config);
}

/*!
 * @brief Returns the desired flash property.
 */
flash_status_t FLASH_GetProperty(flash_config_t *config, flash_property_tag_t whichProperty, uint32_t *value)
{
    standard_version_t version;

    if (whichProperty == kFLASH_PropertyVersion)
    {
        version.B.name   = (char)kFLASH_DriverVersionName;
        version.B.major  = (uint8_t)kFLASH_DriverVersionMajor;
        version.B.minor  = (uint8_t)kFLASH_DriverVersionMinor;
        version.B.bugfix = (uint8_t)kFLASH_DriverVersionBugfix;
        *value           = version.version;
        return kStatus_Success;
    }
    return sROMFlashDrive->flash_get_property(config, whichProperty, value);
}

/*!
 * @brief Erases the flash sectors encompassed by parameters passed into function.
 */
flash_status_t FLASH_Erase(flash_config_t *config, uint32_t start, uint32_t lengthInBytes, uint32_t key)
{
    return sROMFlashDrive->flash_erase(config, start, lengthInBytes, key);
}

/*!
 * @brief Erases entire flash, after done flash is on security status
 */
flash_status_t FLASH_EraseAll(flash_config_t *config, uint32_t key)
{
    return sROMFlashDrive->flash_erase_all(config, key);
}

/*!
 * @brief Erases the entire flash, after done flash is on unsecurity status
 */
flash_status_t FLASH_EraseAllUnsecure(flash_config_t *config, uint32_t key)
{
    return sROMFlashDrive->flash_erase_all_unsecure(config, key);
}

/*!
 * @brief Programs flash with data at locations passed in through parameters via the Program Section command.
 */
flash_status_t FLASH_Program(flash_config_t *config, uint32_t start, uint8_t *src, uint32_t lengthInBytes)
{
    return sROMFlashDrive->flash_program_section(config, start, src, lengthInBytes);
}

/*!
 * @brief Verifies an erasure of the desired flash area at a specified margin level.
 */
flash_status_t FLASH_VerifyErase(flash_config_t *config,
                                 uint32_t start,
                                 uint32_t lengthInBytes,
                                 flash_margin_value_t margin)
{
    return sROMFlashDrive->flash_verify_erase(config, start, lengthInBytes, margin);
}

/*!
 * @brief Verifies erasure of the entire flash at a specified margin level.
 */
flash_status_t FLASH_VerifyEraseAll(flash_config_t *config, flash_margin_value_t margin)
{
    return sROMFlashDrive->flash_verify_erase_all(config, margin);
}

/*!
 * @brief Verifies programming of the desired flash area at a specified margin level.
 */
flash_status_t FLASH_VerifyProgram(flash_config_t *config,
                                   uint32_t start,
                                   uint32_t lengthInBytes,
                                   const uint8_t *expectedData,
                                   flash_margin_value_t margin,
                                   uint32_t *failedAddress,
                                   uint32_t *failedData)
{
    return sROMFlashDrive->flash_verify_program(config, start, lengthInBytes, expectedData, margin, failedAddress,
                                                failedData);
}

/*!
 * @brief Returns the security state via the pointer passed into the function.
 */
flash_status_t FLASH_GetSecurityState(flash_config_t *config, flash_security_state_t *state)
{
    return sROMFlashDrive->flash_get_security_state(config, state);
}

/*!
 * @brief Reads the Program Once Field through parameters.
 */
flash_status_t FLASH_ReadOnce(ftfx_config_t *config, uint32_t index, uint8_t *dst, uint32_t lengthInBytes)
{
    return sROMFlashDrive->flash_read_once(config, index, dst, lengthInBytes);
}

/*!
 * @brief Reads the resource with data at locations passed in through parameters.
 */
flash_status_t FLASH_ReadResource(
    flash_config_t *config, uint32_t start, uint8_t *dst, uint32_t lengthInBytes, flash_read_resource_opt_t option)
{
    return sROMFlashDrive->flash_read_resource(config, start, dst, lengthInBytes, option);
}

/*!
 * @brief Programs Program Once Field through parameters.
 */
flash_status_t FLASH_ProgramOnce(ftfx_config_t *config, uint32_t index, uint8_t *src, uint32_t lengthInBytes)
{
    return sROMFlashDrive->flash_program_once(config, index, src, lengthInBytes);
}

/*!
 * @brief Swaps the lower half flash with the higher half flash.
 */
flash_status_t FLASH_Swap(flash_config_t *config, uint32_t address, uint8_t isSetEnable)
{
    return sROMFlashDrive->flash_swap(config, address, isSetEnable);
}

/*!
 * @brief Allows users to bypass security with a backdoor key.
 */
flash_status_t FLASH_SecurityBypass(flash_config_t *config, const uint8_t *backdoorKey)
{
    return sROMFlashDrive->flash_security_bypass(config, backdoorKey);
}
