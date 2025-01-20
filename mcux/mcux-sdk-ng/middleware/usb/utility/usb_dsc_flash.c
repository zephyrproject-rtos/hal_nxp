/*
 * Copyright 2019 NXP
 * All rights reserved.
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "usb_flash.h"
#include "fsl_flash.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*******************************************************************************
 * Variables
 ******************************************************************************/
flash_config_t dfuFlashConfig[] = {
    /* Main Flash */
    {0}};
uint32_t pflashBlockBase  = 0;
uint32_t pflashTotalSize  = 0;
uint32_t pflashSectorSize = 0;
/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*!
 * @brief USB memmory initialization function.
 *
 * This function initializes the memmory driver structure and variables.
 *
 * @return A FLASH error or kStatus_FLASH_Success.
 */
usb_memmory_status_t USB_MemmoryInit(void)
{
    usb_memmory_status_t status = kStatus_USB_MemmorySuccess;

    if (0 == FLASH_Init(dfuFlashConfig))
    {
        return kStatus_USB_MemmorySuccess;
    }
    else
    {
        status = kStatus_USB_MemmoryErrorSecure;
    }
    return status;
}
/*!
 * @brief USB memmory erasing function.
 *
 * This function erases the memmory area from start address to the end.
 *
 * @param address  The start address, must be phrase-aligned (64 bits).
 * @param address  The erase size, must be phrase-aligned (64 bits).
 *
 * @return A FLASH error or kStatus_FLASH_Success.
 */
usb_memmory_status_t USB_MemmoryErase(uint32_t address, uint32_t size)
{
    usb_memmory_status_t status = kStatus_USB_MemmorySuccess;
    uint32_t eraseLength;

    eraseLength = (size / 8U + 1U) * 8U; /* make the length is align 64 bits */
    if (0 != FLASH_Erase(dfuFlashConfig, address, eraseLength, kFLASH_ApiEraseKey))
    {
        status = kStatus_USB_MemmoryErrorErase;
        return status;
    }
    if (0 != FLASH_VerifyErase(dfuFlashConfig, address, eraseLength, kFLASH_MarginValueUser))
    {
        status = kStatus_USB_MemmoryErrorEraseVerify;
    }
    return status;
}

/*!
 * @brief USB memmory programming function.
 *
 * This function program memmory with data at locations passed in through parameters.
 *
 * @param address The start address to be programmed.
 * @param buffer  Pointer to buffer data, but must be phrase-aligned (64 bits).
 * @param length  The length of data in byte, but must be phrase-aligned (64 bits).
 *
 * @return A FLASH error or kStatus_FLASH_Success.
 */
usb_memmory_status_t USB_MemmoryProgram(uint32_t address, uint8_t *buffer, uint32_t length)
{
    usb_memmory_status_t status = kStatus_USB_MemmorySuccess;
    flash_status_t flashStatus  = 0;
    uint32_t programLength;

    if (length % 8U)
    {
        programLength = (length / 8U + 1U) * 8U;
    }
    else
    {
        programLength = length;
    }
    flashStatus = FLASH_Program(dfuFlashConfig, address, (uint8_t *)buffer, programLength);
    if (0 != flashStatus)
    {
        status = kStatus_USB_MemmoryErrorProgram;
        return status;
    }
    flashStatus =
        FLASH_VerifyProgram(dfuFlashConfig, address, length, (uint8_t *)buffer, kFLASH_MarginValueUser, NULL, NULL);

    if (0 != flashStatus)
    {
        status = kStatus_USB_MemmoryErrorProgramVerify;
    }
    return status;
}
