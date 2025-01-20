/*
 * Copyright 2021 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_mx25.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

#define QUAD_MODE_VAL         (0x40)
#define DUAL_MODE_VAL         (0x00)
#define WIP_BIT_TIMEOUT_VALUE (0xFFFFF)

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
static void CheckIfFinished(mx25_config_t *config);
static void DmaCallback(void);

/*******************************************************************************
 * Variables
 ******************************************************************************/
static volatile bool s_finished = false;

static const spifi_command_t s_command[kMX25_CMD_NUM] = {
    /*Read Status Register*/
    {1, false, kSPIFI_DataInput, 0, kSPIFI_CommandAllSerial, kSPIFI_CommandOpcodeOnly, 0x05},
    /*Read Configuration Register*/
    {1, false, kSPIFI_DataInput, 0, kSPIFI_CommandAllSerial, kSPIFI_CommandOpcodeOnly, 0x15},
    /*Read Security Register*/
    {1, false, kSPIFI_DataInput, 0, kSPIFI_CommandAllSerial, kSPIFI_CommandOpcodeOnly, 0x2B},
    /*Write Status Register*/
    {1, false, kSPIFI_DataOutput, 0, kSPIFI_CommandAllSerial, kSPIFI_CommandOpcodeOnly, 0x01},
    /*Write Status and Config Registers*/
    {2, false, kSPIFI_DataOutput, 0, kSPIFI_CommandAllSerial, kSPIFI_CommandOpcodeOnly, 0x01},
    /*Write Security Register*/
    {1, false, kSPIFI_DataOutput, 0, kSPIFI_CommandAllSerial, kSPIFI_CommandOpcodeOnly, 0x2F},
    /*Set Write Enable Bit*/
    {0, false, kSPIFI_DataOutput, 0, kSPIFI_CommandAllSerial, kSPIFI_CommandOpcodeOnly, 0x06},
    /*Unset Write Enable Bit (Write Disable)*/
    {0, false, kSPIFI_DataOutput, 0, kSPIFI_CommandAllSerial, kSPIFI_CommandOpcodeOnly, 0x04},
    /*Enter Secure OTP*/
    {0, false, kSPIFI_DataOutput, 0, kSPIFI_CommandAllSerial, kSPIFI_CommandOpcodeOnly, 0xB1},
    /*Exit Secure OTP*/
    {0, false, kSPIFI_DataOutput, 0, kSPIFI_CommandAllSerial, kSPIFI_CommandOpcodeOnly, 0xC1},
    /*Suspend page program*/
    {0, false, kSPIFI_DataOutput, 0, kSPIFI_CommandAllSerial, kSPIFI_CommandOpcodeOnly, 0x75},
    /*Suspend erase*/
    {0, false, kSPIFI_DataOutput, 0, kSPIFI_CommandAllSerial, kSPIFI_CommandOpcodeOnly, 0xB0},
    /*Resume page program*/
    {0, false, kSPIFI_DataOutput, 0, kSPIFI_CommandAllSerial, kSPIFI_CommandOpcodeOnly, 0x7A},
    /*Resume erase*/
    {0, false, kSPIFI_DataOutput, 0, kSPIFI_CommandAllSerial, kSPIFI_CommandOpcodeOnly, 0x30},
    /*Reset Enbale*/
    {0, false, kSPIFI_DataOutput, 0, kSPIFI_CommandAllSerial, kSPIFI_CommandOpcodeOnly, 0x66},
    /*Reset command*/
    {0, false, kSPIFI_DataOutput, 0, kSPIFI_CommandAllSerial, kSPIFI_CommandOpcodeOnly, 0x99},
    /*Basic Read Mode*/
    {MX25_PAGE_SIZE, false, kSPIFI_DataInput, 0, kSPIFI_CommandAllSerial, kSPIFI_CommandOpcodeAddrThreeBytes, 0x03},
    /*Fast Read Mode*/
    {MX25_PAGE_SIZE, false, kSPIFI_DataInput, 1, kSPIFI_CommandAllSerial, kSPIFI_CommandOpcodeAddrThreeBytes, 0x0B},
    /*Dual Read Mode*/
    {MX25_PAGE_SIZE, false, kSPIFI_DataInput, 1, kSPIFI_CommandDataQuad, kSPIFI_CommandOpcodeAddrThreeBytes, 0x3B},
    /*2 I/O Read Mode (Address also written in dual mode)*/
    {MX25_PAGE_SIZE, false, kSPIFI_DataInput, 1, kSPIFI_CommandOpcodeSerial, kSPIFI_CommandOpcodeAddrThreeBytes, 0xBB},
    /*Quad Read Mode*/
    {MX25_PAGE_SIZE, false, kSPIFI_DataInput, 1, kSPIFI_CommandDataQuad, kSPIFI_CommandOpcodeAddrThreeBytes, 0x6B},
    /*4 I/O Read Mode (Address also written in quad mode)*/
    {MX25_PAGE_SIZE, false, kSPIFI_DataInput, 3, kSPIFI_CommandOpcodeSerial, kSPIFI_CommandOpcodeAddrThreeBytes, 0xEB},
    /*Burst Read Enabled*/
    {0, false, kSPIFI_DataInput, 0, kSPIFI_CommandOpcodeSerial, kSPIFI_CommandOpcodeAddrOneByte, 0xC0},
    /*Program Page to write to flash*/
    {MX25_PAGE_SIZE, false, kSPIFI_DataOutput, 0, kSPIFI_CommandAllSerial, kSPIFI_CommandOpcodeAddrThreeBytes, 0x02},
    /*Program page to write to flash in Quad Mode*/
    {MX25_PAGE_SIZE, false, kSPIFI_DataOutput, 0, kSPIFI_CommandOpcodeSerial, kSPIFI_CommandOpcodeAddrThreeBytes, 0x38},
    /*Erase 4KBytes Sector of Flash*/
    {0, false, kSPIFI_DataOutput, 0, kSPIFI_CommandAllSerial, kSPIFI_CommandOpcodeAddrThreeBytes, 0x20},
    /*Erase 32KBytes Block of Flash */
    {0, false, kSPIFI_DataOutput, 0, kSPIFI_CommandAllSerial, kSPIFI_CommandOpcodeAddrThreeBytes, 0x52},
    /*Erase 64KBytes Block of Flash */
    {0, false, kSPIFI_DataOutput, 0, kSPIFI_CommandAllSerial, kSPIFI_CommandOpcodeAddrThreeBytes, 0xD8},
    /*Erase Entire Flash*/
    {0, false, kSPIFI_DataOutput, 0, kSPIFI_CommandAllSerial, kSPIFI_CommandOpcodeOnly, 0x60},
    /*Read Device and manufacturer ID*/
    {3, false, kSPIFI_DataInput, 0, kSPIFI_CommandAllSerial, kSPIFI_CommandOpcodeOnly, 0x9F},
    /*Read Device and manufacturer ID*/
    {1, false, kSPIFI_DataInput, 3, kSPIFI_CommandAllSerial, kSPIFI_CommandOpcodeOnly, 0xAB},
    /*Read Device and manufacturer ID*/
    {2, false, kSPIFI_DataInput, 2, kSPIFI_CommandAllSerial, kSPIFI_CommandOpcodeAddrOneByte, 0x9F},
    /*Enter Deep Power-Down Mode*/
    {0, false, kSPIFI_DataOutput, 0, kSPIFI_CommandAllSerial, kSPIFI_CommandOpcodeOnly, 0xB9}};

/*******************************************************************************
 * Code
 ******************************************************************************/

void MX25_GetDefaultConfig(mx25_config_t *config)
{
    assert(config != NULL);

    /* Initializes the configure structure to zero. */
    (void)memset(config, 0, sizeof(*config));

    SPIFI_GetDefaultConfig(&config->config);
    config->spifiStatIRQMask     = SPIFI_STAT_INTRQ_MASK;
    config->extMemAddr           = FSL_FEATURE_SPIFI_START_ADDR;
    config->mx25PerfEnhanceValue = 0x00;
    config->irqSource            = SPIFI_IRQn;
    config->base                 = SPIFI0;
}

void MX25_Init(mx25_config_t *config)
{
    assert(config != NULL);
    SPIFI_Init(config->base, &config->config);
    /* Enabling Quad Mode by default. */
    MX25_SetStatusRegister(config, QUAD_MODE_VAL);
}

void MX25_Deinit(mx25_config_t *config)
{
    SPIFI_Deinit(config->base);
}

/*!
 *
 * Checks the Write in Progress (WIP) bit.
 * It is recommended to check the WIP bit before sending a new instruction when a program,
 * erase, or write status register operation is in progress.
 *
 */
static void CheckIfFinished(mx25_config_t *config)
{
    uint8_t val      = 0;
    uint32_t counter = 0;
    /* Check WIP bit */
    do
    {
        SPIFI_SetCommand(config->base, (spifi_command_t *)&s_command[kMX25_CMD_READ_SR]);
        while ((config->base->STAT & config->spifiStatIRQMask) == 0U)
        {
            counter++;
            if (counter == WIP_BIT_TIMEOUT_VALUE)
            {
                break;
            }
        }
        val = SPIFI_ReadDataByte(config->base);
    } while (val & 0x1);
}

status_t MX25_EnableMode(mx25_config_t *config, const spifi_dual_mode_t mode)
{
    status_t status = kStatus_Fail;

    if (mode == kSPIFI_DualMode)
    {
        config->config.dualMode = kSPIFI_DualMode;
        MX25_SetStatusRegister(config, DUAL_MODE_VAL);
        SPIFI_Init(config->base, &config->config);
        status = kStatus_Success;
    }
    else if (mode == kSPIFI_QuadMode)
    {
        config->config.dualMode = kSPIFI_QuadMode;
        MX25_SetStatusRegister(config, QUAD_MODE_VAL);
        SPIFI_Init(config->base, &config->config);
        status = kStatus_Success;
    }
    return status;
}

status_t MX25_WriteBuffer(
    mx25_config_t *config, const uint32_t address, const unsigned char *buf, uint32_t dataLen, mx25_cmd_t pageProgCmd)
{
    assert(buf != NULL);
    status_t status = kStatus_Fail;

    if ((dataLen % MX25_PAGE_SIZE))
    {
        status = kStatus_Fail;
    }

    else
    {
        /* Reset the SPIFI to switch to command mode */
        SPIFI_ResetCommand(config->base);
        EnableIRQ(config->irqSource);
        for (int i = 0; i < (dataLen / MX25_PAGE_SIZE); i++)
        {
            SPIFI_SetCommand(config->base, (spifi_command_t *)&s_command[kMX25_CMD_WRITE_ENABLE]);
            SPIFI_SetCommandAddress(config->base, i * MX25_PAGE_SIZE + address);
            SPIFI_SetCommand(config->base, (spifi_command_t *)&s_command[pageProgCmd]);
            for (int j = 0; j < MX25_PAGE_SIZE; j += sizeof(uint32_t))
            {
                uint32_t data = 0;
                for (int k = 0; k < sizeof(uint32_t); k++)
                {
                    data |= ((uint32_t)(buf[j + k])) << (k * 8);
                }
                SPIFI_WriteData(config->base, data);
            }
            CheckIfFinished(config);
        }
        status = kStatus_Success;
    }
    return status;
}

void MX25_Erase(mx25_config_t *config, uint32_t address, mx25_cmd_t eraseCmd)
{
    assert((eraseCmd == kMX25_CMD_SECTOR_ERASE) | (eraseCmd == kMX25_CMD_BLOCK_ERASE32K) |
           (eraseCmd == kMX25_CMD_BLOCK_ERASE64K) | (eraseCmd == kMX25_CMD_CHIP_ERASE));

    SPIFI_ResetCommand(config->base);
    EnableIRQ(config->irqSource);

    SPIFI_SetCommand(config->base, (spifi_command_t *)&s_command[kMX25_CMD_WRITE_ENABLE]);
    if (eraseCmd != kMX25_CMD_CHIP_ERASE)
    {
        SPIFI_SetCommandAddress(config->base, address);
    }
    SPIFI_SetCommand(config->base, (spifi_command_t *)&s_command[eraseCmd]);
    CheckIfFinished(config);
}

void MX25_ReadBuffer(
    mx25_config_t *config, uint32_t address, unsigned char *buf, uint32_t dataLen, mx25_cmd_t readModeCmd)
{
    assert(buf != NULL);
    /* Reset to memory command mode */
    SPIFI_ResetCommand(config->base);
    if (readModeCmd == kMX25_CMD_FOUR_READ)
    {
        SPIFI_SetIntermediateData(config->base, config->mx25PerfEnhanceValue);
    }
    SPIFI_SetMemoryCommand(config->base, (spifi_command_t *)&s_command[readModeCmd]);

    for (int i = address; i < (dataLen + address); i++)
    {
        buf[i - address] = *(uint8_t *)(config->extMemAddr + i);
    }
}

void MX25_Read(mx25_config_t *config, mx25_cmd_t readModeCmd)
{
    /* Reset to memory command mode */
    SPIFI_ResetCommand(config->base);
    if (readModeCmd == kMX25_CMD_FOUR_READ)
    {
        SPIFI_SetIntermediateData(config->base, config->mx25PerfEnhanceValue);
    }
    SPIFI_SetMemoryCommand(config->base, (spifi_command_t *)&s_command[readModeCmd]);
}

uint32_t MX25_ReadDeviceInfo(mx25_config_t *config, mx25_cmd_t readInfoCmd)
{
    uint8_t val     = 0;
    uint32_t result = 0;
    bool flag       = false;

    SPIFI_ResetCommand(config->base);
    EnableIRQ(config->irqSource);

    SPIFI_SetCommand(config->base, (spifi_command_t *)&s_command[readInfoCmd]);

    for (int i = 0; i < (s_command[readInfoCmd].dataLen - 1); i++)
    {
        val = SPIFI_ReadDataByte(config->base);
        if (s_command[readInfoCmd].dataLen == 2)
        {
            flag   = true;
            result = (result | val);
            break;
        }
        result = (result | val) << 8;
    }
    if (!flag)
    {
        val    = SPIFI_ReadDataByte(config->base);
        result = (result | val);
    }
    return result;
}

void MX25_SetConfigRegister(mx25_config_t *config, uint8_t crVal)
{
    uint8_t currentSrValue;
    currentSrValue = (uint8_t)MX25_ReadDeviceInfo(config, kMX25_CMD_READ_SR);

    SPIFI_ResetCommand(config->base);
    EnableIRQ(config->irqSource);

    SPIFI_SetCommand(config->base, (spifi_command_t *)&s_command[kMX25_CMD_WRITE_ENABLE]);
    SPIFI_SetCommand(config->base, (spifi_command_t *)&s_command[kMX25_CMD_WRITE_SC_REGISTERS]);
    /* The status register is always written first. This is why we read its value at the beginning of the function. */
    SPIFI_WriteDataByte(config->base, currentSrValue);
    SPIFI_WriteDataByte(config->base, crVal);
    CheckIfFinished(config);
}

void MX25_SetStatusRegister(mx25_config_t *config, uint8_t srVal)
{
    SPIFI_ResetCommand(config->base);
    EnableIRQ(config->irqSource);

    SPIFI_SetCommand(config->base, (spifi_command_t *)&s_command[kMX25_CMD_WRITE_ENABLE]);
    SPIFI_SetCommand(config->base, (spifi_command_t *)&s_command[kMX25_CMD_WRITE_SR]);
    SPIFI_WriteDataByte(config->base, srVal);

    CheckIfFinished(config);
}

void MX25_SetProtectionMode(mx25_config_t *config, uint8_t protectionModeMask)
{
    uint8_t srVal;
    srVal = (uint8_t)MX25_ReadDeviceInfo(config, kMX25_CMD_READ_SR);

    MX25_SetStatusRegister(config, srVal | protectionModeMask);

    CheckIfFinished(config);
}

void MX25_SetOperationalParameters(mx25_config_t *config, mx25_cmd_t opParamCmd)
{
    SPIFI_ResetCommand(config->base);
    EnableIRQ(config->irqSource);

    SPIFI_SetCommand(config->base, (spifi_command_t *)&s_command[opParamCmd]);
}

static void DmaCallback(void)
{
    s_finished = true;
}

void MX25_TransferRxCreateHandleDMA(mx25_config_t *config, spifi_dma_handle_t *handle, dma_handle_t *dmaHandle)
{
    SPIFI_TransferRxCreateHandleDMA(config->base, handle, (void *)DmaCallback, NULL, dmaHandle);
}

void MX25_WritePageDma(mx25_config_t *config,
                       const uint32_t address,
                       unsigned char *buf,
                       mx25_cmd_t pageProgCmd,
                       spifi_dma_handle_t handle)
{
    assert(buf != NULL);
    spifi_transfer_t xfer = {0};

    SPIFI_SetCommand(config->base, (spifi_command_t *)&s_command[kMX25_CMD_WRITE_ENABLE]);
    SPIFI_SetCommandAddress(config->base, address);
    SPIFI_SetCommand(config->base, (spifi_command_t *)&s_command[pageProgCmd]);
    xfer.data     = buf;
    xfer.dataSize = MX25_PAGE_SIZE;

    SPIFI_TransferSendDMA(config->base, &handle, &xfer);
    while (!s_finished)
    {
    }
    s_finished = false;
    CheckIfFinished(config);
}
