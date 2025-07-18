/*
 * Copyright 2019-2021 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_common.h"
#include "Flash_config.h"

#pragma define_section reserved_FCF "reserved_FCF.text" RX
#pragma section reserved_FCF begin
static const uint8_t s_flashConfigField[] = {
    FCF_BACKDOOR_KEY3,
    FCF_BACKDOOR_KEY2,
    FCF_BACKDOOR_KEY1,
    FCF_BACKDOOR_KEY0,
    FCF_BACKDOOR_KEY7,
    FCF_BACKDOOR_KEY6,
    FCF_BACKDOOR_KEY5,
    FCF_BACKDOOR_KEY4,
    FCF_FLASH_PROTECTION_BYTE3,
    FCF_FLASH_PROTECTION_BYTE2,
    FCF_FLASH_PROTECTION_BYTE1,
    FCF_FLASH_PROTECTION_BYTE0,
    FCF_FLASH_SECURE_BYTE,
    FCF_FLASH_OPTION_BYTE,
    FCF_EEPROM_PROTECTION_BYTE,    /* FlexNVM EEPROM protection */
    FCF_DATA_FLASH_PROTECTION_BYTE /* FlexNVM Data flash protection */
};
#pragma section reserved_FCF end
