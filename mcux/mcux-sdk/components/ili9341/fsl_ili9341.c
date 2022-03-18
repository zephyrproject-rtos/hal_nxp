/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2017,2019 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_ili9341.h"

void FT9341_Init(ili9341_send_byte_t _writeData, ili9341_send_byte_t _writeCommand)
{
    SDK_DelayAtLeastUs(ILI9341_RESET_CANCEL_MS * 1000U, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);

    _writeCommand(ILI9341_CMD_PWRA);
    _writeData(0x39);
    _writeData(0x2C);
    _writeData(0x00);
    _writeData(0x34);
    _writeData(0x02);
    _writeCommand(ILI9341_CMD_PWRB);
    _writeData(0x00);
    _writeData(0xC1);
    _writeData(0x30);
    _writeCommand(ILI9341_CMD_DTCA);
    _writeData(0x85);
    _writeData(0x00);
    _writeData(0x78);
    _writeCommand(ILI9341_CMD_DTCB);
    _writeData(0x00);
    _writeData(0x00);
    _writeCommand(ILI9341_CMD_PWRSEQ);
    _writeData(0x64);
    _writeData(0x03);
    _writeData(0x12);
    _writeData(0x81);
    _writeCommand(ILI9341_CMD_PRC);
    _writeData(0x20);
    _writeCommand(ILI9341_CMD_PWR1);
    _writeData(0x23);
    _writeCommand(ILI9341_CMD_PWR2);
    _writeData(0x10);
    _writeCommand(ILI9341_CMD_VCOM1);
    _writeData(0x3E);
    _writeData(0x28);
    _writeCommand(ILI9341_CMD_VCOM2);
    _writeData(0x86);
    _writeCommand(ILI9341_CMD_MAC);
    _writeData(0x40);
    _writeCommand(ILI9341_CMD_PIXELFORMAT);
    _writeData(0x55);
    _writeCommand(ILI9341_CMD_FRC);
    _writeData(0x00);
    _writeData(0x18);
    _writeCommand(ILI9341_CMD_DFC);
    _writeData(0x08);
    _writeData(0x82);
    _writeData(0x27);
    _writeCommand(ILI9341_CMD_3GAMMAEN);
    _writeData(0x00);
    _writeCommand(ILI9341_CMD_COLADDR);
    _writeData(0x00);
    _writeData(0x00);
    _writeData(0x00);
    _writeData(0xEF);
    _writeCommand(ILI9341_CMD_PAGEADDR);
    _writeData(0x00);
    _writeData(0x00);
    _writeData(0x01);
    _writeData(0x3F);
    _writeCommand(ILI9341_CMD_GAMMA);
    _writeData(0x01);
    _writeCommand(ILI9341_CMD_PGAMMA);
    _writeData(0x0F);
    _writeData(0x31);
    _writeData(0x2B);
    _writeData(0x0C);
    _writeData(0x0E);
    _writeData(0x08);
    _writeData(0x4E);
    _writeData(0xF1);
    _writeData(0x37);
    _writeData(0x07);
    _writeData(0x10);
    _writeData(0x03);
    _writeData(0x0E);
    _writeData(0x09);
    _writeData(0x00);
    _writeCommand(ILI9341_CMD_NGAMMA);
    _writeData(0x00);
    _writeData(0x0E);
    _writeData(0x14);
    _writeData(0x03);
    _writeData(0x11);
    _writeData(0x07);
    _writeData(0x31);
    _writeData(0xC1);
    _writeData(0x48);
    _writeData(0x08);
    _writeData(0x0F);
    _writeData(0x0C);
    _writeData(0x31);
    _writeData(0x36);
    _writeData(0x0F);
    _writeCommand(ILI9341_CMD_SLEEPOUT);
    _writeCommand(ILI9341_CMD_DISPLAYON);
}
