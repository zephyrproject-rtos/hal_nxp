/*
 * Copyright 2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*
 * mflash porting layer for FRDM-IMXRT700
 *
 * Flash: W25Q25PW (256 Mb, quad SDR, 4-byte address)
 * Interface: XSPI0, SDR Quad mode
 *
 * Initialization sequence:
 *   1. Power up / clock XSPI0
 *   2. Configure XSPI and load LUT (SPI mode)
 *   3. Enable QE bit via Write Status Register-2 (cmd 0x31, data 0x02)
 *   4. Enter 4-byte address mode (cmd 0xB7)
 *   5. Subsequent operations use 1-1-4 / 1-4-4 SDR commands with 32-bit addresses
 */

#include <stdbool.h>
#include <string.h>

#include "mflash_drv.h"
#include "fsl_xspi.h"
#include "fsl_cache.h"
#include "board.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* LUT sequence indices */
#define NOR_CMD_LUT_SEQ_IDX_READ            0  /* 1-4-4 Fast Read (4-byte addr, 0xEC) */
#define NOR_CMD_LUT_SEQ_IDX_READ_STATUS     1  /* Read Status Register-1 (0x05)       */
#define NOR_CMD_LUT_SEQ_IDX_WRITE_ENABLE    2  /* Write Enable (0x06)                  */
#define NOR_CMD_LUT_SEQ_IDX_ERASE_SECTOR    3  /* Sector Erase 4KB (4-byte, 0x21)     */
#define NOR_CMD_LUT_SEQ_IDX_PAGEPROGRAM     4  /* Quad Page Program (4-byte, 0x34)    */
#define NOR_CMD_LUT_SEQ_IDX_READ_ID         5  /* Read JEDEC ID (0x9F)                 */
#define NOR_CMD_LUT_SEQ_IDX_ENABLE_QE       6  /* Write SR2 to set QE bit (0x31)      */
#define NOR_CMD_LUT_SEQ_IDX_ENTER_4BYTE     7  /* Enter 4-byte address mode (0xB7)    */
#define NOR_CMD_LUT_SEQ_IDX_ERASE_CHIP      8  /* Chip Erase (0xC7)                   */

#define CUSTOM_LUT_LENGTH  45  /* 9 sequences × 5 words */

/* Status register WIP bit (bit 0) */
#define FLASH_BUSY_STATUS_OFFSET 0

/* QE bit value to write into SR2 */
#define FLASH_ENABLE_QE_VAL  0x02U

/* Errata ERR052528: LUT-declared read data size must be at least 8 bytes for any
   read command including RDSR. The LUT operand below is fixed at 8 bytes; the actual
   per-transfer dataSize used by xspi_nor_wait_busy() can remain smaller. */

/*******************************************************************************
 * Variables
 ******************************************************************************/

static xspi_device_ddr_config_t s_flashSdrConfig = {
    .ddrDataAlignedClk         = kXSPI_DDRDataAlignedWithInternalRefClk,
    .enableDdr                 = false,   /* SDR quad mode */
    .enableByteSwapInOctalMode = false,
};

static xspi_device_config_t s_deviceConfig = {
    .xspiRootClk     = 198000000U,                          /* MAIN_PLL_PFD1(396 MHz) / 2 = 198 MHz */
    .enableCknPad    = false,
    .deviceInterface = kXSPI_StrandardExtendedSPI,
    .interfaceSettings.strandardExtendedSPISettings.pageSize = MFLASH_PAGE_SIZE,
    .CSHoldTime      = 3,
    .CSSetupTime     = 3,
    /* No external DQS on quad flash — use internal loopback */
    .sampleClkConfig.sampleClkSource       = kXSPI_SampleClkFromDqsPadLoopback,
    .sampleClkConfig.enableDQSLatency      = false,
    .sampleClkConfig.dllConfig.dllMode     = kXSPI_AutoUpdateMode,
    .sampleClkConfig.dllConfig.useRefValue = true,
    .sampleClkConfig.dllConfig.enableCdl8  = true,
    .ptrDeviceDdrConfig                    = &s_flashSdrConfig,
    .addrMode                              = kXSPI_DeviceByteAddressable,
    .columnAddrWidth                       = 0U,
    .enableCASInterleaving                 = false,
    .deviceSize[0]    = MFLASH_FLASH_SIZE / 1024U,
    .deviceSize[1]    = MFLASH_FLASH_SIZE / 1024U,
    .ptrDeviceRegInfo = NULL,
};

/*
 * LUT for MX25UW51345G in quad SDR mode with 4-byte addresses.
 *
 * All commands are standard SPI (1 pad) except the read/write data phases
 * which use 4 pads (quad).
 */
RAMVARIABLE(const uint32_t customLUT[CUSTOM_LUT_LENGTH]) = {
    /* [0] 1-4-4 Fast Read, 4-byte addr (0xEC), 6 dummy cycles */
    [5 * NOR_CMD_LUT_SEQ_IDX_READ + 0] =
        XSPI_LUT_SEQ(kXSPI_Command_SDR, kXSPI_1PAD, 0xEC,
                     kXSPI_Command_RADDR_SDR, kXSPI_4PAD, 0x20),
    [5 * NOR_CMD_LUT_SEQ_IDX_READ + 1] =
        XSPI_LUT_SEQ(kXSPI_Command_DUMMY_SDR, kXSPI_4PAD, 0x06,
                     kXSPI_Command_READ_SDR, kXSPI_4PAD, 0x08),
    [5 * NOR_CMD_LUT_SEQ_IDX_READ + 2] =
        XSPI_LUT_SEQ(kXSPI_Command_STOP, kXSPI_1PAD, 0x00, 0, 0, 0),

    /* [1] Read Status Register-1 (0x05) — ERR052528: LUT-declared size must be >=8 bytes */
    [5 * NOR_CMD_LUT_SEQ_IDX_READ_STATUS + 0] =
        XSPI_LUT_SEQ(kXSPI_Command_SDR, kXSPI_1PAD, 0x05,
                     kXSPI_Command_READ_SDR, kXSPI_1PAD, 0x08),

    /* [2] Write Enable (0x06) */
    [5 * NOR_CMD_LUT_SEQ_IDX_WRITE_ENABLE + 0] =
        XSPI_LUT_SEQ(kXSPI_Command_SDR, kXSPI_1PAD, 0x06,
                     kXSPI_Command_STOP, kXSPI_1PAD, 0x00),

    /* [3] Sector Erase 4KB, 4-byte addr (0x21) */
    [5 * NOR_CMD_LUT_SEQ_IDX_ERASE_SECTOR + 0] =
        XSPI_LUT_SEQ(kXSPI_Command_SDR, kXSPI_1PAD, 0x21,
                     kXSPI_Command_RADDR_SDR, kXSPI_1PAD, 0x20),

    /* [4] Quad Page Program, 4-byte addr (0x34) */
    [5 * NOR_CMD_LUT_SEQ_IDX_PAGEPROGRAM + 0] =
        XSPI_LUT_SEQ(kXSPI_Command_SDR, kXSPI_1PAD, 0x34,
                     kXSPI_Command_RADDR_SDR, kXSPI_1PAD, 0x20),
    [5 * NOR_CMD_LUT_SEQ_IDX_PAGEPROGRAM + 1] =
        XSPI_LUT_SEQ(kXSPI_Command_WRITE_SDR, kXSPI_4PAD, 0x04,
                     kXSPI_Command_STOP, kXSPI_1PAD, 0x00),

    /* [5] Read JEDEC ID (0x9F) */
    [5 * NOR_CMD_LUT_SEQ_IDX_READ_ID + 0] =
        XSPI_LUT_SEQ(kXSPI_Command_SDR, kXSPI_1PAD, 0x9F,
                     kXSPI_Command_READ_SDR, kXSPI_1PAD, 0x08),

    /* [6] Write Status Register-2 to enable QE (0x31, data = 0x02) */
    [5 * NOR_CMD_LUT_SEQ_IDX_ENABLE_QE + 0] =
        XSPI_LUT_SEQ(kXSPI_Command_SDR, kXSPI_1PAD, 0x31,
                     kXSPI_Command_WRITE_SDR, kXSPI_1PAD, 0x01),

    /* [7] Enter 4-byte address mode (0xB7) */
    [5 * NOR_CMD_LUT_SEQ_IDX_ENTER_4BYTE + 0] =
        XSPI_LUT_SEQ(kXSPI_Command_SDR, kXSPI_1PAD, 0xB7,
                     kXSPI_Command_STOP, kXSPI_1PAD, 0x00),

    /* [8] Chip Erase (0xC7) */
    [5 * NOR_CMD_LUT_SEQ_IDX_ERASE_CHIP + 0] =
        XSPI_LUT_SEQ(kXSPI_Command_SDR, kXSPI_1PAD, 0xC7,
                     kXSPI_Command_STOP, kXSPI_1PAD, 0x00),
};

/*******************************************************************************
 * Static helpers (placed in RAM so they can run while XIP flash is busy)
 ******************************************************************************/

RAMFUNC static status_t xspi_nor_write_enable(XSPI_Type *base, uint32_t addr)
{
    xspi_transfer_t xfer = {
        .deviceAddress   = MFLASH_BASE_ADDRESS + addr,
        .cmdType         = kXSPI_Command,
        .seqIndex        = NOR_CMD_LUT_SEQ_IDX_WRITE_ENABLE,
        .targetGroup     = kXSPI_TargetGroup0,
        .data            = NULL,
        .dataSize        = 0UL,
        .lockArbitration = false,
    };
    return XSPI_TransferBlocking(base, &xfer);
}

RAMFUNC static status_t xspi_nor_wait_busy(XSPI_Type *base)
{
    uint32_t readValue;
    status_t status;
    xspi_transfer_t xfer = {
        .deviceAddress   = MFLASH_BASE_ADDRESS,
        .cmdType         = kXSPI_Read,
        .seqIndex        = NOR_CMD_LUT_SEQ_IDX_READ_STATUS,
        .targetGroup     = kXSPI_TargetGroup0,
        .data            = &readValue,
        .dataSize        = 4U,
        .lockArbitration = false,
    };
    do
    {
        status = XSPI_TransferBlocking(base, &xfer);
        if (status != kStatus_Success)
        {
            return status;
        }
    } while ((readValue & (1U << FLASH_BUSY_STATUS_OFFSET)) != 0U);

    return kStatus_Success;
}

RAMFUNC static status_t xspi_nor_enable_quad_mode(XSPI_Type *base)
{
    xspi_transfer_t xfer;
    status_t status;
    uint32_t writeValue = FLASH_ENABLE_QE_VAL;

    status = xspi_nor_write_enable(base, 0U);
    if (status != kStatus_Success)
    {
        return status;
    }

    xfer.deviceAddress   = MFLASH_BASE_ADDRESS;
    xfer.cmdType         = kXSPI_Write;
    xfer.seqIndex        = NOR_CMD_LUT_SEQ_IDX_ENABLE_QE;
    xfer.targetGroup     = kXSPI_TargetGroup0;
    xfer.data            = &writeValue;
    xfer.dataSize        = 1U;
    xfer.lockArbitration = false;

    status = XSPI_TransferBlocking(base, &xfer);
    if (status != kStatus_Success)
    {
        return status;
    }

    return xspi_nor_wait_busy(base);
}

#if 0
RAMFUNC static status_t xspi_nor_enter_4byte_addr(XSPI_Type *base)
{
    xspi_transfer_t xfer = {
        .deviceAddress   = MFLASH_BASE_ADDRESS,
        .cmdType         = kXSPI_Command,
        .seqIndex        = NOR_CMD_LUT_SEQ_IDX_ENTER_4BYTE,
        .targetGroup     = kXSPI_TargetGroup0,
        .data            = NULL,
        .dataSize        = 0UL,
        .lockArbitration = false,
    };
    return XSPI_TransferBlocking(base, &xfer);
}
#endif

RAMFUNC static status_t xspi_nor_flash_read(
    XSPI_Type *base, uint32_t addr, uint32_t *dst, uint32_t length)
{
    xspi_transfer_t xfer = {
        .deviceAddress   = MFLASH_BASE_ADDRESS + addr,
        .cmdType         = kXSPI_Read,
        .seqIndex        = NOR_CMD_LUT_SEQ_IDX_READ,
        .targetGroup     = kXSPI_TargetGroup0,
        .data            = dst,
        .dataSize        = length,
        .lockArbitration = false,
    };
    status_t status = XSPI_TransferBlocking(base, &xfer);
    if (status != kStatus_Success)
    {
        return status;
    }
    return xspi_nor_wait_busy(base);
}

RAMFUNC static status_t xspi_nor_erase_sector(XSPI_Type *base, uint32_t addr)
{
    status_t status;
    xspi_transfer_t xfer;

    status = xspi_nor_write_enable(base, 0U);
    if (status != kStatus_Success)
    {
        return status;
    }

    xfer.deviceAddress   = MFLASH_BASE_ADDRESS + addr;
    xfer.cmdType         = kXSPI_Command;
    xfer.seqIndex        = NOR_CMD_LUT_SEQ_IDX_ERASE_SECTOR;
    xfer.targetGroup     = kXSPI_TargetGroup0;
    xfer.data            = NULL;
    xfer.dataSize        = 0UL;
    xfer.lockArbitration = false;

    status = XSPI_TransferBlocking(base, &xfer);
    if (status != kStatus_Success)
    {
        return status;
    }

    return xspi_nor_wait_busy(base);
}

RAMFUNC static status_t xspi_nor_page_program(
    XSPI_Type *base, uint32_t addr, uint32_t *src)
{
    status_t status;
    xspi_transfer_t xfer;

    status = xspi_nor_wait_busy(base);
    if (status != kStatus_Success)
    {
        return status;
    }

    status = xspi_nor_write_enable(base, addr);
    if (status != kStatus_Success)
    {
        return status;
    }

    xfer.deviceAddress   = MFLASH_BASE_ADDRESS + addr;
    xfer.cmdType         = kXSPI_Write;
    xfer.seqIndex        = NOR_CMD_LUT_SEQ_IDX_PAGEPROGRAM;
    xfer.targetGroup     = kXSPI_TargetGroup0;
    xfer.data            = src;
    xfer.dataSize        = MFLASH_PAGE_SIZE;
    xfer.lockArbitration = false;

    status = XSPI_TransferBlocking(base, &xfer);
    if (status != kStatus_Success)
    {
        return status;
    }

    return xspi_nor_wait_busy(base);
}

/*******************************************************************************
 * Internal init (RAM function — safe to call even when running from XIP flash)
 ******************************************************************************/

RAMFUNC static int32_t mflash_drv_init_internal(XSPI_Type *base)
{
    uint32_t primask;
    xspi_config_t config;
    xspi_ahb_access_config_t ahbCfg;
    xspi_ip_access_config_t  ipCfg;
    status_t status = kStatus_Success;

    if ((uint32_t)mflash_drv_init_internal >= MFLASH_BASE_ADDRESS &&
        (uint32_t)mflash_drv_init_internal < (MFLASH_BASE_ADDRESS + MFLASH_FLASH_SIZE))
    {
        return kStatus_ReadOnly;
    }

    primask = __get_PRIMASK();
    __asm("cpsid i");

    /* Clock: MAIN_PLL_PFD1 (396 MHz) / 2 = 198 MHz */
    CLOCK_AttachClk(kMAIN_PLL_PFD1_to_XSPI0);
    CLOCK_SetClkDiv(kCLOCK_DivXspi0Clk, 2U);

    POWER_DisablePD(kPDRUNCFG_APD_XSPI0);
    POWER_DisablePD(kPDRUNCFG_PPD_XSPI0);
    POWER_ApplyPD();

    /* XSPI initialization */
    config.ptrAhbAccessConfig = &ahbCfg;
    config.ptrIpAccessConfig  = &ipCfg;
    XSPI_GetDefaultConfig(&config);

    config.byteOrder                                    = kXSPI_64BitLE;
    config.ptrAhbAccessConfig->ahbErrorPayload.highPayload = 0x5A5A5A5AUL;
    config.ptrAhbAccessConfig->ahbErrorPayload.lowPayload  = 0x5A5A5A5AUL;
    config.ptrAhbAccessConfig->ptrAhbWriteConfig        = NULL;
    config.ptrAhbAccessConfig->ARDSeqIndex              = NOR_CMD_LUT_SEQ_IDX_READ;
    config.ptrAhbAccessConfig->enableAHBBufferWriteFlush = true;
    config.ptrAhbAccessConfig->enableAHBPrefetch         = true;

    config.ptrIpAccessConfig->ptrSfpFradConfig               = NULL;
    config.ptrIpAccessConfig->ptrSfpMdadConfig               = NULL;
    config.ptrIpAccessConfig->ipAccessTimeoutValue           = 0xFFFFFFFFUL;
    config.ptrIpAccessConfig->sfpArbitrationLockTimeoutValue = 0xFFFFFFUL;

    XSPI_Init(base, &config);
    XSPI_SetDeviceConfig(base, &s_deviceConfig);

    /* Copy LUT to RAM before updating (avoid XIP corruption) */
    uint32_t tmpLUT[CUSTOM_LUT_LENGTH] = {0};
    memcpy(tmpLUT, customLUT, sizeof(tmpLUT));
    XSPI_UpdateLUT(base, 0, tmpLUT, CUSTOM_LUT_LENGTH);

    /* Enable Quad-Enable bit in flash SR2 */
    status = xspi_nor_enable_quad_mode(base);
    if (status != kStatus_Success)
    {
        goto done;
    }

    /* Switch flash to 4-byte address mode */
    /* status = xspi_nor_enter_4byte_addr(base); */

done:
    if (primask == 0U)
    {
        __asm("cpsie i");
    }
    return status;
}

/*******************************************************************************
 * Public mflash API
 ******************************************************************************/

RAMFUNC int32_t mflash_drv_init(void)
{
    return mflash_drv_init_internal(XSPI0);
}

RAMFUNC static int32_t mflash_drv_read_internal(
    uint32_t addr, uint32_t *buffer, uint32_t len)
{
    uint32_t primask = __get_PRIMASK();
    __asm("cpsid i");

    status_t status = xspi_nor_flash_read(XSPI0, addr, buffer, len);

    if (primask == 0U)
    {
        __asm("cpsie i");
    }
    __ISB();
    return status;
}

RAMFUNC int32_t mflash_drv_read(uint32_t addr, uint32_t *buffer, uint32_t len)
{
    if (((uint32_t)buffer % 4U) || (len % 4U))
    {
        return kStatus_InvalidArgument;
    }
    return mflash_drv_read_internal(addr, buffer, len);
}

RAMFUNC static int32_t mflash_drv_sector_erase_internal(uint32_t sector_addr)
{
    uint32_t primask = __get_PRIMASK();
    __asm("cpsid i");

    status_t status = xspi_nor_erase_sector(XSPI0, sector_addr);

    XSPI_Cache64_InvalidateCache(CACHE64_CTRL0);

    if (primask == 0U)
    {
        __asm("cpsie i");
    }
    __ISB();
    return status;
}

RAMFUNC int32_t mflash_drv_sector_erase(uint32_t sector_addr)
{
    if (0 == mflash_drv_is_sector_aligned(sector_addr))
    {
        return kStatus_InvalidArgument;
    }
    return mflash_drv_sector_erase_internal(sector_addr);
}

RAMFUNC static int32_t mflash_drv_page_program_internal(
    uint32_t page_addr, uint32_t *data)
{
    uint32_t primask = __get_PRIMASK();
    __asm("cpsid i");

    status_t status = xspi_nor_page_program(XSPI0, page_addr, data);

    XSPI_Cache64_InvalidateCache(CACHE64_CTRL0);

    if (primask == 0U)
    {
        __asm("cpsie i");
    }
    __ISB();
    return status;
}

RAMFUNC int32_t mflash_drv_page_program(uint32_t page_addr, uint32_t *data)
{
    if (0 == mflash_drv_is_page_aligned(page_addr))
    {
        return kStatus_InvalidArgument;
    }
    return mflash_drv_page_program_internal(page_addr, data);
}

void *mflash_drv_phys2log(uint32_t addr, uint32_t len)
{
    return (void *)(addr + MFLASH_BASE_ADDRESS);
}

uint32_t mflash_drv_log2phys(void *ptr, uint32_t len)
{
    return ((uint32_t)ptr - MFLASH_BASE_ADDRESS);
}
