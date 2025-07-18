/*
 * Copyright 2019-2020 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_common.h"
#include "Flash_config.h"

typedef struct _bootloader_cofiguration_area
{
    char tag[4];
    uint32_t crcStartAddress;
    uint32_t crcByteCount;
    uint32_t crcExpectedValue;
    uint8_t enabledPeripherals;
    uint8_t i2cSlaveAddress;
    uint16_t peripheralDetectionTimeout;
    uint8_t reserved_0[2];
    uint8_t reserved_1[2];
    uint8_t reserved_2[4];
    uint8_t reserved_3;
    uint8_t reserved_4;
    uint8_t bootFlags;
    uint8_t reserved_5;
    uint8_t reserved_6[4];
    uint8_t reserved_7[4];
    uint8_t reserved_8;
    uint8_t canConfig1;
    uint16_t canConfig2;
    uint16_t canTxId;
    uint16_t canRxId;
    uint8_t reserved_9[4];
    uint8_t reserved_10[12];
} bootloader_cofiguration_area_t;

#pragma define_section reserved_BCA "reserved_BCA.text" RX
#pragma section reserved_BCA begin
static const bootloader_cofiguration_area_t s_BCAConfig = {
    {'k', 'c', 'f', 'g'},             /* tag */
    BCA_CRC_START_ADDRESS,            /* Start address for image CRC check */
    BCA_CRC_BYTE_COUNTS,              /* Byte count for image CRC check */
    BCA_CRC_EXPECTED_VALUE,           /* Expected CRC value for image CRC check */
    BCA_ENABLED_PERIPHERALS,          /* Enabled Peripherals */
    BCA_I2C_SLAVE_ADDRESS,            /* I2C slave address */
    BCA_PERIPHERAL_DETECTION_TIMEOUT, /* Peripheral detection timeout in ms */
    {0xFFU, 0xFFU},                   /* reserved_0 */
    {0xFFU, 0xFFU},                   /* reserved_1 */
    {0xFFU, 0xFFU, 0xFFU, 0xFFU},     /* reserved_2 */
    0xFFU,                            /* reserved_3 */
    0xFFU,                            /* reserved_4 */
    BCA_DIRECT_BOOT_FLAG,             /* One's complement of direct boot flag */
    0xFFU,                            /* reserved_5 */
    {0xFFU, 0xFFU, 0xFFU, 0xFFU},     /* reserved_6 */
    {0xFFU, 0xFFU, 0xFFU, 0xFFU},     /* reserved_7 */
    0xFFU,                            /* reserved_8 */
    BCA_CAN_CONFIG1,                  /* CAN config1 */
    BCA_CAN_CONFIG2,                  /* CAN config2 */
    BCA_CAN_TX_ID,                    /* CAN TX id */
    BCA_CAN_RX_ID,                    /* CAN RX id */
    {0xFFU, 0xFFU, 0xFFU, 0xFFU},     /* reserved_9 */
    {0xFFU, 0xFFU, 0xFFU, 0xFFU, 0xFFU, 0xFFU, 0xFFU, 0xFFU, 0xFFU, 0xFFU, 0xFFU, 0xFFU} /* reserved_10 */
};

#pragma section reserved_BCA end

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
    0xFFU, /* reserved */
    0xFFU  /* reserved */
};
#pragma section reserved_FCF end
