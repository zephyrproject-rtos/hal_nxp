/*
 * Copyright 2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*
 * mflash porting layer for MIMXRT2660-EVK
 *
 * Flash: Winbond W25H512NWEAM (512 Mb / 64 MB, 1.8 V, automotive grade, quad SDR + DTR + ECC)
 * Interface: MAIN__XSPI_0, SDR Quad mode (octal/DTR not used on this EVK)
 *
 * Per W25H512NW datasheet (rev A, July 2022):
 *   - Section 7.1.9: QE bit at SR2.S9; SR2 is written via cmd 0x31.
 *   - Section 7.1.11: ADP bit factory default = 0 -> powers up in 3-Byte Address Mode.
 *     A 512 Mb chip MUST be switched to 4-Byte Address Mode via cmd 0xB7 to reach
 *     anything above 16 MB.
 *   - Section 8.1.1: JEDEC ID (cmd 0x9F) returns EF A0 20.
 *   - 4-byte instruction set (Section 8.1.5): READ 0xEC, ERASE_SECTOR 0x21,
 *     PAGE_PROGRAM_QUAD 0x34, ENTER_4BYTE 0xB7, CHIP_ERASE 0xC7.
 *
 * Initialization sequence:
 *   1. XSPI0 clock + power are brought up by clock_config.c / BOARD_BootClockRUN().
 *   2. Configure XSPI and load LUT (SPI mode).
 *   3. Read JEDEC ID and sanity-check it matches W25H512 (EF A0 20).
 *   4. Enable QE bit via Write Status Register-2 (cmd 0x31, data 0x02).
 *   5. Enter 4-byte address mode (cmd 0xB7) -- required for 64 MB access.
 *   6. Subsequent operations use 1-1-4 / 1-4-4 SDR commands with 32-bit addresses.
 */

#include <stdbool.h>
#include <string.h>

#include "mflash_drv.h"
#include "fsl_xspi.h"
#include "fsl_cache.h"
#include "fsl_clock.h"
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

/* Errata ERR052528: the XSPI IP requires a minimum read data size of 8 bytes.
   Requesting fewer bytes than the IP clocks in leaves RX residue, so XSPI never
   reports idle and the next command's arbitration grant (ARB_WIN) never asserts,
   hanging XSPI_StartIpAccess(). All IP reads below (RDSR, JEDEC ID) use 8 bytes. */


/*******************************************************************************
 * Variables
 ******************************************************************************/

static xspi_device_ddr_config_t s_flashSdrConfig = {
    .ddrDataAlignedClk         = kXSPI_DDRDataAlignedWithInternalRefClk,
    .enableDdr                 = false,   /* SDR quad mode */
    .enableByteSwapInOctalMode = false,
};

/*
 * SFP MDAD: allow any master ID on both target groups (TG0 = flash, TG1 =
 * port B/mirror), both secure and non-secure attributes.  Only a CSSI
 * initiator (ID 001010b) may write MGC/MRC/MTO and SFP_ARB_TIMEOUT; for MDAD
 * and FRAD the access check uses the domain ID, so the CM85 core can configure
 * these here.
 *
 * These MUST be non-NULL on RT2660. Unlike RT700 -- where the CPU has direct
 * access to the SFP global control registers and can leave the SFP disabled --
 * on RT2660 some of those global control registers can only be modified by ELE,
 * and the SFP block comes up with FRAD/MDAD access checks ENABLED by default.
 * So a valid MDAD (and FRAD) configuration must be supplied here; with MDAD/FRAD
 * left unconfigured the SFP arbiter never grants an IP command/write access, so
 * XSPI_StartIpAccess() spins forever on ERRSTAT.ARB_WIN (observed: hang on the
 * first Write Enable during quad-mode enable).
 */

static xspi_sfp_mdad_config_t s_mflashMdadConfig = {
    .tgMdad[0] =
        {
            .assignIsValid        = true,
            .enableDescriptorLock = false,
            .maskType             = 0U, /* ANDed mask: any master ID matches when mask=0. */
            .mask                 = 0U,
            .masterIdReference    = 0U,
            .secureAttribute      = kXSPI_AttributeMasterNonsecureSecureBoth,
        },
    .tgMdad[1] =
        {
            .assignIsValid        = true,
            .enableDescriptorLock = false,
            .maskType             = 0U,
            .mask                 = 0U,
            .masterIdReference    = 0U,
            .secureAttribute      = kXSPI_AttributeMasterNonsecureSecureBoth,
        },
};

/*
 * SFP FRAD: one region covering the XSPI0 AHB flash window. Both TGs get full
 * read/write access (MD0ACP/MD1ACP = 0x7: secure/privileged/user writes
 * allowed). Remaining FRAD entries stay invalid (zero-initialized).
 *
 * startAddress/endAddress are filled in at runtime in mflash_drv_init_internal()
 * from MFLASH_BASE_ADDRESS: XSPI0_AMBA_BASE is security-dependent (0x60000000
 * non-secure, 0x70000000 secure), and the FRAD region MUST cover the exact
 * address the IP transfers use. If the region is hardcoded to 0x60000000 but
 * the transfers run at 0x70000000 (secure boot), the SFP arbiter reports
 * ERRSTAT.FRADMTCH ("address not in any valid FRAD region") and never grants
 * the IP request, so XSPI_StartIpAccess() spins forever (observed: hang on the
 * first Write Enable, SR idle, ERRSTAT=FRADMTCH, ARB_WIN clear).
 */
static xspi_sfp_frad_config_t s_mflashFradConfig = {
    .fradConfig[0] =
        {
            .startAddress        = 0x70000000UL, /* secure alias -- the one mflash uses */
            .endAddress          = 0x7FFF0000UL,
            .tg0MasterAccess     = 0x7U, /* MDnACP: secure/privileged/user writes allowed. */
            .tg1MasterAccess     = 0x7U,
            .assignIsValid       = true,
            .descriptorLock      = kXSPI_DescriptorLockDisabled,
            .exclusiveAccessLock = kXSPI_ExclusiveAccessLockDisabled,
        },
    .fradConfig[1] =
        {
            .startAddress        = 0x60000000UL, /* non-secure alias -- for robustness */
            .endAddress          = 0x6FFF0000UL,
            .tg0MasterAccess     = 0x7U,
            .tg1MasterAccess     = 0x7U,
            .assignIsValid       = true,
            .descriptorLock      = kXSPI_DescriptorLockDisabled,
            .exclusiveAccessLock = kXSPI_ExclusiveAccessLockDisabled,
        },
    /* Remaining FRAD entries stay invalid (zero-initialized). */
};

static xspi_device_config_t s_deviceConfig = {
    /* Set at runtime in mflash_drv_init_internal() via
     * CLOCK_GetRootClockFreq(kCLOCK_Root_MAIN_xspi0_fclk_divided) so this
     * driver stays in sync if clock_config.c changes the XSPI0 source/divider. */
    .xspiRootClk     = 0U,
    .enableCknPad    = false,
    .deviceInterface = kXSPI_StrandardExtendedSPI,
    .interfaceSettings.strandardExtendedSPISettings.pageSize = MFLASH_PAGE_SIZE,
    .CSHoldTime      = 3,
    .CSSetupTime     = 3,
    /* No external DQS on quad flash — use internal loopback */
    .sampleClkConfig.sampleClkSource       = kXSPI_SampleClkFromDqsPadLoopback,
#if (defined(FSL_FEATURE_XSPI_HAS_DQS_LAT_EN) && FSL_FEATURE_XSPI_HAS_DQS_LAT_EN)
    .sampleClkConfig.enableDQSLatency      = false,
#endif
    .sampleClkConfig.dllConfig.dllMode     = kXSPI_AutoUpdateMode,
    .sampleClkConfig.dllConfig.useRefValue = true,
    .sampleClkConfig.dllConfig.enableCdl8  = true,
    .ptrDeviceDdrConfig                    = &s_flashSdrConfig,
    .addrMode                              = kXSPI_DeviceByteAddressable,
    .columnAddrWidth                       = 0U,
    .enableCASInterleaving                 = false,
    .deviceSize[0]    = MFLASH_FLASH_SIZE / 1024U,
    .deviceSize[1]    = 0U,   /* RT2660 EVK: single W25H512 on XSPI0_CS0; CS1 unused. */
    .ptrDeviceRegInfo = NULL,
};

/*
 * LUT for W25H512NWEAM in quad SDR mode with 4-byte addresses.
 *
 * Opcodes verified against Winbond W25H512NW-DTR datasheet (rev A):
 *   0xEC  Fast Read Quad I/O (4-byte addr)            -- Section 8.2.33
 *   0x05  Read Status Register-1                       -- Section 8.2.4
 *   0x06  Write Enable                                 -- Section 8.2.1
 *   0x21  Sector Erase 4 KB (4-byte addr)              -- Section 8.2.45
 *   0x34  Quad Input Page Program (4-byte addr)        -- Section 8.2.43
 *   0x9F  Read JEDEC ID                                -- Section 8.2.59
 *   0x31  Write Status Register-2 (sets QE bit @ S9)   -- Section 8.2.5 / 7.1.9
 *   0xB7  Enter 4-Byte Address Mode                    -- Section 8.2.13
 *   0xC7  Chip Erase                                   -- Section 8.2.50
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
                     kXSPI_Command_READ_SDR, kXSPI_4PAD, 0x04),
    [5 * NOR_CMD_LUT_SEQ_IDX_READ + 2] =
        XSPI_LUT_SEQ(kXSPI_Command_STOP, kXSPI_1PAD, 0x00, 0, 0, 0),

    /* [1] Read Status Register-1 (0x05) — ERR052528: min IP read is 8 bytes */
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

    /* [5] Read JEDEC ID (0x9F) — ERR052528: min IP read is 8 bytes */
    [5 * NOR_CMD_LUT_SEQ_IDX_READ_ID + 0] =
        XSPI_LUT_SEQ(kXSPI_Command_SDR, kXSPI_1PAD, 0x9F,
                     kXSPI_Command_READ_SDR, kXSPI_1PAD, 0x08),


    /* [6] Write Status Register-2 to enable QE (0x31, data = 0x02 -> SR2.S9 = 1)
     *     W25H512NW datasheet rev A, Section 7.1.9 + 8.2.5: QE bit is at SR2
     *     bit S9 (== bit 1 of the SR2 byte). Same opcode/position as W25Q
     *     family -- the LUT inherited from frdmimxrt700 is correct here. */
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
    uint32_t readValue[2] = {0U};
    status_t status;
    xspi_transfer_t xfer = {
        .deviceAddress   = MFLASH_BASE_ADDRESS,
        .cmdType         = kXSPI_Read,
        .seqIndex        = NOR_CMD_LUT_SEQ_IDX_READ_STATUS,
        .targetGroup     = kXSPI_TargetGroup0,
        .data            = readValue,
        .dataSize        = 8U,   /* ERR052528: min IP read is 8 bytes. Draining
                                  * fewer bytes than the IP clocks in leaves RX
                                  * residue, so XSPI never reports idle and the
                                  * next command's arbitration grant (ARB_WIN)
                                  * never asserts -> XSPI_StartIpAccess() hangs. */
        .lockArbitration = false,
    };
    do
    {
        status = XSPI_TransferBlocking(base, &xfer);
        if (status != kStatus_Success)
        {
            return status;
        }
    } while ((readValue[0] & (1U << FLASH_BUSY_STATUS_OFFSET)) != 0U);

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

/*
 * Read JEDEC ID (cmd 0x9F) and verify the chip is W25H512NW.
 * Datasheet section 8.1.1: returns Manufacturer ID 0xEF (Winbond),
 * 16-bit Device ID 0xA020 -> a 3-byte stream {0xEF, 0xA0, 0x20}.
 */
#define MFLASH_W25H512_JEDEC_MANUF_ID 0xEFU
#if 1
#define MFLASH_W25H512_JEDEC_DEV_HI   0xA0U
#else
#define MFLASH_W25H512_JEDEC_DEV_HI   0x60U   // For backward compatibility of W25Q512
#endif
#define MFLASH_W25H512_JEDEC_DEV_LO   0x20U

RAMFUNC static status_t xspi_nor_read_jedec_id(XSPI_Type *base, uint32_t *jedec_id_out)
{
    uint32_t id[2] = {0U};
    xspi_transfer_t xfer = {
        .deviceAddress   = MFLASH_BASE_ADDRESS,
        .cmdType         = kXSPI_Read,
        .seqIndex        = NOR_CMD_LUT_SEQ_IDX_READ_ID,
        .targetGroup     = kXSPI_TargetGroup0,
        .data            = id,
        .dataSize        = 8U,   /* ERR052528: min IP read is 8 bytes */
        .lockArbitration = false,
    };
    status_t status = XSPI_TransferBlocking(base, &xfer);
    if (status == kStatus_Success && jedec_id_out != NULL)
    {
        *jedec_id_out = id[0];
    }
    return status;
}

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

    /* TODO[MCUX-88497]: RT2660 clock + power attach for MAIN__XSPI_0.
     * On RT2660 the XSPI clock + power are already brought up by
     * clock_config.c / BOARD_BootClockRUN() in the board overlay because the
     * board boots from XIP NOR. If a later use case needs explicit attach /
     * power-gate handling, add the RT2660 clock root + PDRUNCFG calls here. */

    /* Pick up the actual XSPI0 root-clock rate from the live clock tree
     * (set by clock_config.c). This avoids hard-coding 333.33 MHz here and
     * keeps the driver correct if the board's clock setup changes. */
    s_deviceConfig.xspiRootClk =
        CLOCK_GetRootClockFreq(kCLOCK_Root_MAIN_xspi0_fclk_divided);

    /* XSPI initialization */
    config.ptrAhbAccessConfig = &ahbCfg;
    config.ptrIpAccessConfig  = &ipCfg;
    XSPI_GetDefaultConfig(&config);

#if (defined(FSL_FEATURE_XSPI_HAS_END_CFG) && FSL_FEATURE_XSPI_HAS_END_CFG)
    config.byteOrder                                    = kXSPI_64BitLE;
#endif
    config.ptrAhbAccessConfig->ahbErrorPayload.highPayload = 0x5A5A5A5AUL;
    config.ptrAhbAccessConfig->ahbErrorPayload.lowPayload  = 0x5A5A5A5AUL;
    config.ptrAhbAccessConfig->ptrAhbWriteConfig        = NULL;
    config.ptrAhbAccessConfig->ARDSeqIndex              = NOR_CMD_LUT_SEQ_IDX_READ;
    config.ptrAhbAccessConfig->enableAHBBufferWriteFlush = true;
    config.ptrAhbAccessConfig->enableAHBPrefetch         = true;

    /* Fill in the FRAD region from the live MFLASH_BASE_ADDRESS. XSPI0_AMBA_BASE
     * is security-dependent (0x60000000 non-secure, 0x70000000 secure); the
     * region MUST cover the exact address the IP transfers use, or the SFP
     * arbiter reports ERRSTAT.FRADMTCH and never grants the request (observed:
     * hang on the first Write Enable, SR idle, ERRSTAT=FRADMTCH, ARB_WIN clear).
     * The driver masks start/end with 0xFFFF0000 (64-KB alignment). */
    s_mflashFradConfig.fradConfig[0].startAddress = MFLASH_BASE_ADDRESS;
    s_mflashFradConfig.fradConfig[0].endAddress   =
        MFLASH_BASE_ADDRESS + MFLASH_FLASH_SIZE - 0x10000UL;

    /* MDAD/FRAD MUST be non-NULL: with them unconfigured the SFP arbiter never
     * grants an IP command/write access, so XSPI_StartIpAccess() spins forever
     * on ERRSTAT.ARB_WIN. See the config blocks above. */
    config.ptrIpAccessConfig->ptrSfpFradConfig               = &s_mflashFradConfig;

    config.ptrIpAccessConfig->ptrSfpMdadConfig               = &s_mflashMdadConfig;

    /* Finite IP-access timeout (MTO). With the reset default (0xFFFFFFFF) a
     * stuck IP transaction never completes and the blocking read/write helpers
     * spin on it forever. A finite count makes the controller raise
     * ERRSTAT.TO_ERR so XSPI_TransferBlocking() returns kStatus_Timeout and the
     * error can propagate. ~10.5M IPS cycles (tens of ms) is far beyond any
     * real IP command here (status/ID reads, one-page program). */
    config.ptrIpAccessConfig->ipAccessTimeoutValue           = 0x00A00000UL;
    config.ptrIpAccessConfig->sfpArbitrationLockTimeoutValue = 0xFFFFFFUL;

    XSPI_Init(base, &config);
    XSPI_SetDeviceConfig(base, &s_deviceConfig);

    /* Copy LUT to RAM before updating (avoid XIP corruption) */
    uint32_t tmpLUT[CUSTOM_LUT_LENGTH] = {0};
    memcpy(tmpLUT, customLUT, sizeof(tmpLUT));
    XSPI_UpdateLUT(base, 0, tmpLUT, CUSTOM_LUT_LENGTH);

    /* Sanity check: read JEDEC ID and confirm it matches W25H512NW. */
    {
        uint32_t jedec_id = 0U;
        status = xspi_nor_read_jedec_id(base, &jedec_id);
        if (status != kStatus_Success)
        {
            goto done;
        }
        /* The 0x9F transfer returns {manuf, dev_hi, dev_lo, ...} little-endian
         * in the 32-bit word: byte0=manuf, byte1=dev_hi, byte2=dev_lo. */
        if (((jedec_id >> 0)  & 0xFFU) != MFLASH_W25H512_JEDEC_MANUF_ID ||
            ((jedec_id >> 8)  & 0xFFU) != MFLASH_W25H512_JEDEC_DEV_HI   ||
            ((jedec_id >> 16) & 0xFFU) != MFLASH_W25H512_JEDEC_DEV_LO)
        {
            status = kStatus_Fail;
            goto done;
        }
    }

    /* Enable Quad-Enable bit in flash SR2 */
    status = xspi_nor_enable_quad_mode(base);
    if (status != kStatus_Success)
    {
        goto done;
    }

    /* Switch flash to 4-byte address mode.
     * W25H512NW datasheet rev A, Section 7.1.11: ADP factory default = 0,
     * so the chip powers up in 3-byte mode. A 512 Mb chip MUST enter 4-byte
     * mode (cmd 0xB7) to address beyond the first 16 MB. */
    status = xspi_nor_enter_4byte_addr(base);
    if (status != kStatus_Success)
    {
        goto done;
    }

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
    return mflash_drv_init_internal(MAIN__XSPI_0);
}

RAMFUNC static int32_t mflash_drv_read_internal(
    uint32_t addr, uint32_t *buffer, uint32_t len)
{
    uint32_t primask = __get_PRIMASK();
    __asm("cpsid i");

    status_t status = xspi_nor_flash_read(MAIN__XSPI_0, addr, buffer, len);

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

    status_t status = xspi_nor_erase_sector(MAIN__XSPI_0, sector_addr);

    /* RT2660 doesn't have CACHE64; invalidate the L1 D-cache range that maps the flash. */
    DCACHE_InvalidateByRange(MFLASH_BASE_ADDRESS, MFLASH_FLASH_SIZE);

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

    status_t status = xspi_nor_page_program(MAIN__XSPI_0, page_addr, data);

    /* RT2660 doesn't have CACHE64; invalidate the L1 D-cache range that maps the flash. */
    DCACHE_InvalidateByRange(MFLASH_BASE_ADDRESS, MFLASH_FLASH_SIZE);

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
