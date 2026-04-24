/*
 * Copyright 2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_ESPI_H_
#define FSL_ESPI_H_

#include "fsl_common.h"

/*!
 * @addtogroup espi
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*@{*/
#define FSL_ESPI_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*@}*/

#define ESPI_INVALID_PORT (0xFFU)

/*! @brief eSPI PnCFG.TYPE register values. */
typedef enum _espi_port_type
{
    kESPI_PortType_Unconfigured         = 0x0U, /*!< 0000b: Unconfigured (reset condition). */
    kESPI_PortType_ACPIEndpoint         = 0x1U, /*!< 0001b: ACPI style Endpoint. */
    kESPI_PortType_ACPIIndexData        = 0x2U, /*!< 0010b: ACPI style Index/Data. */
    kESPI_PortType_BusMasterMemSingle   = 0x4U, /*!< 0100b: Bus Master Mem Single. */
    kESPI_PortType_BusMasterFlashSingle = 0x5U, /*!< 0101b: Bus Master Flash Single. */
    kESPI_PortType_MailboxShared        = 0x8U, /*!< 1000b: Mailbox Shared. */
    kESPI_PortType_MailboxSingle        = 0x9U, /*!< 1001b: Mailbox Single. */
    kESPI_PortType_MailboxSplit         = 0xAU, /*!< 1010b: Mailbox Split. */
    kESPI_PortType_MailboxOOBSplit      = 0xBU, /*!< 1011b: Mailbox OOB Split. */
    kESPI_PortType_MailboxOEM           = 0xCU, /*!< 1100b: Mailbox OEM. */
} espi_port_type_t;

/*! @brief eSPI SAF read completion types. */
typedef enum _espi_saf_rx_completion_type
{
    kESPI_SAFReadMiddle = 0U, /*!< Middle completion of split sequence. */
    kESPI_SAFReadFirst  = 1U, /*!< First completion of split sequence. */
    kESPI_SAFReadLast   = 2U, /*!< Last completion of split sequence. */
    kESPI_SAFReadOnly   = 3U, /*!< Only completion for single transaction. */
} espi_saf_rx_completion_type_t;

/*! @brief eSPI flash transaction types. */
typedef enum _espi_flash_transaction_type
{
    kESPI_FlashTransNone  = 0U, /*!< No transaction. */
    kESPI_FlashTransRead  = 1U, /*!< Read transaction. */
    kESPI_FlashTransWrite = 2U, /*!< Write transaction. */
    kESPI_FlashTransErase = 3U, /*!< Erase transaction. */
} espi_flash_trans_type_t;

/*! @brief eSPI/LPC enable mode encoding. */
typedef enum _espi_enable_mode
{
    kESPI_Disable    = 0U,
    kESPI_EnableESPI = 1U,
    kESPI_EnableLPC  = 2U,
} espi_enable_mode_t;

/* Encoded target read request sizes for ESPICAP.TRGT_REQ_SIZE_SUPP. */
typedef enum _espi_read_req_size
{
    kESPI_ReadReq64B   = 1U,
    kESPI_ReadReq128B  = 2U,
    kESPI_ReadReq256B  = 3U,
    kESPI_ReadReq512B  = 4U,
    kESPI_ReadReq1024B = 5U,
    kESPI_ReadReq2048B = 6U,
    kESPI_ReadReq4096B = 7U,
} espi_read_req_size_t;

/* Encoded maximum payload sizes for memory channel (ESPICAP.MEMMX). */
typedef enum _espi_mem_max_payload
{
    kESPI_MemMax64B  = 1U,
    kESPI_MemMax128B = 2U,
    kESPI_MemMax256B = 3U,
} espi_mem_max_payload_t;

/* Encoded maximum payload sizes for flash channel (ESPICAP.FLASHMX). */
typedef enum _espi_flash_max_payload
{
    kESPI_FlashMax64B  = 0U,
    kESPI_FlashMax128B = 1U,
    kESPI_FlashMax256B = 2U,
    kESPI_FlashMax512B = 3U,
} espi_flash_max_payload_t;

/* Encoded maximum payload sizes for OOB channel (ESPICAP.OOBMX). */
typedef enum _espi_oob_max_payload
{
    kESPI_OOBMax64B  = 1U,
    kESPI_OOBMax128B = 2U,
    kESPI_OOBMax256B = 3U,
} espi_oob_max_payload_t;

/*! @brief eSPI SPI capability mode.
 *
 * Defines the SPI wire mode capabilities supported by the eSPI controller.
 * These values are programmed into ESPICAP.SPICAP field to indicate which
 * SPI modes the target supports to the host.
 *
 * Mode encoding.
 * - Single: Standard SPI using single data line (MOSI/MISO).
 * - Dual:   Dual SPI using 2 data lines (IO[1:0]).
 * - Quad:   Quad SPI using 4 data lines (IO[3:0]).
 */
typedef enum _espi_spi_mode
{
    kESPI_SPIMode_SingleOnly    = 0U, /*!< Single SPI only. */
    kESPI_SPIMode_SingleAndDual = 1U, /*!< Single + Dual SPI.*/
    kESPI_SPIMode_SingleAndQuad = 2U, /*!< Single + Quad SPI. */
    kESPI_SPIMode_All           = 3U, /*!< All modes: Single, Dual and Quad SPI */
} espi_spi_mode_t;

/*! @brief eSPI WRSTAT field values (PnSTAT[WRSTAT] or STAT.WRSTAT).
 *
 * These symbolic names document the 2-bit WRSTAT encoding used by the
 * eSPI controller to indicate host flash request types. The numeric
 * encoding comes from the eSPI specification; use these symbols in the
 * driver instead of magic numbers for clarity.
 */
typedef enum _espi_wrstat_values
{
    kESPI_WRSTAT_NoRequest    = 0x0U, /*!< 00b: No flash request / idle. */
    kESPI_WRSTAT_ReadRequest  = 0x1U, /*!< 01b: Host read request. */
    kESPI_WRSTAT_WriteRequest = 0x2U, /*!< 10b: Host write request. */
    kESPI_WRSTAT_EraseRequest = 0x3U, /*!< 11b: Host erase request. */
} espi_wrstat_values_t;

/*! @brief eSPI interrupt enable flags. */
enum _espi_interrupt_enable
{
    kESPI_PortInterruptEnable       = ESPI_INTENSET_PORTINT_MASK, /*!< Port interrupt enable. */
    kESPI_Port80InterruptEnable     = ESPI_INTENSET_P80INT_MASK,  /*!< Port 80 interrupt enable. */
    kESPI_BusResetInterruptEnable   = ESPI_INTENSET_BUSRST_MASK,  /*!< Bus reset interrupt enable. */
    kESPI_IrqUpdateInterruptEnable  = ESPI_INTENSET_IRQUPD_MASK,  /*!< IRQ update interrupt enable. */
    kESPI_WireChangeInterruptEnable = ESPI_INTENSET_WIRECHG_MASK, /*!< Wire change interrupt enable. */
    kESPI_HostStallInterruptEnable  = ESPI_INTENSET_HSTALL_MASK,  /*!< Host stall interrupt enable. */
    kESPI_CrcErrorInterruptEnable   = ESPI_INTENSET_CRCERR_MASK,  /*!< CRC error interrupt enable. */
    kESPI_GpioInterruptEnable       = ESPI_INTENSET_GPIO_MASK,    /*!< GPIO interrupt enable. */
    kESPI_CsInterruptEnable         = ESPI_INTENSET_CS_INT_MASK,  /*!< CS interrupt enable. */
    kESPI_AllInterruptEnable = kESPI_PortInterruptEnable | kESPI_Port80InterruptEnable | kESPI_BusResetInterruptEnable |
                               kESPI_IrqUpdateInterruptEnable | kESPI_WireChangeInterruptEnable |
                               kESPI_HostStallInterruptEnable | kESPI_CrcErrorInterruptEnable |
                               kESPI_GpioInterruptEnable | kESPI_CsInterruptEnable /*!< All interrupts enable. */
};

/*! @brief eSPI status flags. */
enum _espi_status_flags
{
    kESPI_PortInterruptFlag     = ESPI_MSTAT_PORTINT_MASK,   /*!< Port interrupt flag. */
    kESPI_Port80InterruptFlag   = ESPI_MSTAT_P80INT_MASK,    /*!< Port 80 interrupt flag. */
    kESPI_BusResetFlag          = ESPI_MSTAT_BUSRST_MASK,    /*!< Bus reset flag. */
    kESPI_IrqUpdateFlag         = ESPI_MSTAT_IRQUPD_MASK,    /*!< IRQ update flag. */
    kESPI_WireChangeFlag        = ESPI_MSTAT_WIRECHG_MASK,   /*!< Wire change flag. */
    kESPI_HostStallFlag         = ESPI_MSTAT_HSTALL_MASK,    /*!< Host stall flag. */
    kESPI_CrcErrorFlag          = ESPI_MSTAT_CRCERR_MASK,    /*!< CRC error flag. */
    kESPI_GpioFlag              = ESPI_MSTAT_GPIO_MASK,      /*!< GPIO flag. */
    kESPI_BusyFlag              = ESPI_MSTAT_BUSY_MASK,      /*!< Bus busy flag. */
    kESPI_InResetFlag           = ESPI_MSTAT_INRST_MASK,     /*!< In reset flag. */
    kESPI_CompletionPendingFlag = ESPI_MSTAT_COMPPEND_MASK,  /*!< Completion pending flag. */
    kESPI_MasterPendingFlag     = ESPI_MSTAT_MASTPEND_MASK,  /*!< Master pending flag. */
    kESPI_AlertPendingFlag      = ESPI_MSTAT_ALERTPEND_MASK, /*!< Alert pending flag. */
    kESPI_BusStatusFlags = kESPI_Port80InterruptFlag | kESPI_BusResetFlag | kESPI_IrqUpdateFlag | kESPI_WireChangeFlag |
                           kESPI_HostStallFlag | kESPI_CrcErrorFlag | kESPI_GpioFlag,
};

/*! @brief eSPI port interrupt flags. */
enum _espi_port_interrupt_flags
{
    kESPI_PortErrorInterrupt = ESPI_STAT_INTERR_MASK,   /*!< Error interrupt. */
    kESPI_PortReadInterrupt  = ESPI_STAT_INTRD_MASK,    /*!< Read interrupt. */
    kESPI_PortWriteInterrupt = ESPI_STAT_INTWR_MASK,    /*!< Write interrupt. */
    kESPI_PortSpec0Interrupt = ESPI_STAT_INTSPC0_MASK,  /*!< Special 0 interrupt. */
    kESPI_PortSpec1Interrupt = ESPI_STAT_INTSPC1_MASK,  /*!< Special 1 interrupt. */
    kESPI_PortSpec2Interrupt = ESPI_STAT_INTSPC2_MASK,  /*!< Special 2 interrupt. */
    kESPI_PortSpec3Interrupt = ESPI_STAT_INSTSPC3_MASK, /*!< Special 3 interrupt. */
    kESPI_PortAllInterrupts  = kESPI_PortErrorInterrupt | kESPI_PortReadInterrupt | kESPI_PortWriteInterrupt |
                              kESPI_PortSpec0Interrupt | kESPI_PortSpec1Interrupt | kESPI_PortSpec2Interrupt |
                              kESPI_PortSpec3Interrupt,
};

/*! @brief eSPI SAF erase size enumeration */
typedef enum _espi_saf_erase_size
{
    kESPI_SAFErase2KB  = 0x0U, /*!< 2 kB minimum erase sector. */
    kESPI_SAFErase4KB  = 0x1U, /*!< 4 kB minimum erase sector. */
    kESPI_SAFErase8KB  = 0x2U, /*!< 8 kB minimum erase sector. */
    kESPI_SAFErase16KB = 0x3U, /*!< 16 kB minimum erase sector. */
} espi_saf_erase_size_t;

/*! @brief eSPI maximum SPI speed enumeration */
typedef enum _espi_max_speed
{
    kESPI_MaxSpeed20MHz = 0x0U, /*!< <= 20 MHz. */
    kESPI_MaxSpeed25MHz = 0x1U, /*!< <= 25 MHz (24 MHz). */
    kESPI_MaxSpeed33MHz = 0x2U, /*!< <= 33 MHz (30 MHz). */
    kESPI_MaxSpeed50MHz = 0x3U, /*!< <= 50 MHz (48 MHz). */
    kESPI_MaxSpeed66MHz = 0x4U, /*!< <= 66 MHz (60 MHz). */
} espi_max_speed_t;

/*! @brief eSPI RAM length. */
typedef enum _espi_ram_size
{
    kESPI_RamSize4B   = 0U,
    kESPI_RamSize8B   = 1U,
    kESPI_RamSize16B  = 2U,
    kESPI_RamSize32B  = 3U,
    kESPI_RamSize64B  = 4U,
    kESPI_RamSize128B = 5U,
    kESPI_RamSize256B = 6U,
    kESPI_RamSize512B = 7U,
} espi_ram_size_t;

/*!
 * @brief eSPI address base selection.
 *
 * Determines how the port address is calculated:
 * - Direct: Address = PnADDR[OFF]
 * - Base0:  Address = (MAPBASE[BASE0] << 16) | PnADDR[OFF]
 * - Base1:  Address = (MAPBASE[BASE1] << 16) | PnADDR[OFF]
 */
typedef enum _espi_addr_base
{
    kESPI_AddrBaseDirect = 0U, /*!< Direct addressing: 0x0000-0xFFFF (I/O or low memory) */
    kESPI_AddrBase0      = 1U, /*!< Use MAPBASE[BASE0] as upper 16 bits */
    kESPI_AddrBase1      = 2U, /*!< Use MAPBASE[BASE1] as upper 16 bits */
} espi_addr_base_t;

/*! @brief eSPI PnIRULESTAT.SSTCL (Status Set and Clear) values.
 *
 * These values are written to PnIRULESTAT[19:16] to control port status transitions.
 * The meaning depends on the port type configured in PnCFG[TYPE].
 *
 * For Endpoint/Index-and-Data types (TYPE=0x1, 0x2):
 *   - Individual bits control specific status flags
 *   - Bit 0: Set RDPEND
 *   - Bit 1: Clear WRRDY
 *   - Bit 2: Clear RDPEND
 *   - Bit 3: Clear CMD (Endpoint only)
 *
 * For Mailbox types (TYPE=0x8, 0x9, 0xA, 0xB):
 *   - Bits [1:0] control RDSTAT (Host Read / MCU Write direction)
 *   - Bits [3:2] control WRSTAT (Host Write / MCU Read direction)
 *
 * For Bus Master types (TYPE=0x4, 0x5):
 *   - Value 0x1: Start memory/flash request
 *
 * For SAF (Slave-Attached Flash):
 *   - Value 0x1: Send completion response
 */
typedef enum _espi_sstcl
{
    /* ====================================================================== */
    /* Endpoint / Index-and-Data Port Types (TYPE = 0x1, 0x2)                */
    /* ====================================================================== */
    kESPI_SSTCL_ACPISetRdPend = 0x1U, /*!< Bit 0=1: Set RDPEND (read data pending). */
    kESPI_SSTCL_ACPIClrWrRdy  = 0x2U, /*!< Bit 1=1: Clear WRRDY (write ready). */
    kESPI_SSTCL_ACPIClrRdPend = 0x4U, /*!< Bit 2=1: Clear RDPEND (read data pending). */
    kESPI_SSTCL_ACPIClrCmd    = 0x8U, /*!< Bit 3=1: Clear CMD flag (Endpoint only). */

    /* ====================================================================== */
    /* Mailbox Port Types - RDSTAT Control (Bits [1:0])                      */
    /* Host Read / MCU Write direction                                       */
    /* Applicable to: Mailbox Single, Split, Shared, OOB Split               */
    /* ====================================================================== */
    kESPI_SSTCL_MailboxRdStarted   = 0x1U, /*!< 01b: MCU started writing data. */
    kESPI_SSTCL_MailboxRdCompleted = 0x2U, /*!< 10b: MCU completed writing data. */
    kESPI_SSTCL_MailboxRdEmpty     = 0x3U, /*!< 11b: Set read status to Empty. */

    /* ====================================================================== */
    /* Mailbox Port Types - WRSTAT Control (Bits [3:2])                      */
    /* Host Write / MCU Read direction                                       */
    /* Applicable to: Mailbox Single, Split, Shared                          */
    /* ====================================================================== */
    kESPI_SSTCL_MailboxWrStarted = 0x4U, /*!< 01b << 2: MCU started reading (partial). */
    kESPI_SSTCL_MailboxWrEmpty   = 0xCU, /*!< 11b << 2: Set write status to Empty. */

    /* ====================================================================== */
    /* Mailbox Combined Control - Common Operations                          */
    /* ====================================================================== */
    kESPI_SSTCL_MailboxBothEmpty = 0xFU, /*!< Clear both RDSTAT and WRSTAT to Empty. */

    /* ====================================================================== */
    /* OOB (Out-of-Band) Mailbox Specific (TYPE = 0xB)                       */
    /* ====================================================================== */
    kESPI_SSTCL_OOBSendStart    = 0x1U, /*!< Start OOB message send. */
    kESPI_SSTCL_OOBSendComplete = 0x2U, /*!< Complete OOB send, trigger host GET. */
    kESPI_SSTCL_OOBSendEmpty    = 0x3U, /*!< Clear OOB send status. */
    kESPI_SSTCL_OOBRecvEmpty    = 0xCU, /*!< Clear OOB receive status. */

    /* ====================================================================== */
    /* Bus Master Memory/Flash Types (TYPE = 0x4, 0x5)                       */
    /* ====================================================================== */
    kESPI_SSTCL_MAFStart = 0x1U, /*!< Start memory/flash request (MAF). */

    /* ====================================================================== */
    /* SAF (Slave-Attached Flash) - Used with Flash Port                     */
    /* ====================================================================== */
    kESPI_SSTCL_SAFCompletion  = 0x1U, /*!< Send SAF completion response. */
    kESPI_SSTCL_SAFReqAccepted = 0x2U, /*!< Flash request accepted. */
} espi_sstcl_t;

/*! @brief eSPI OMFLEN[TRANS] field values.
 *
 * Encodes the 2-bit `TRANS` field of `PnOMFLEN` for different port types.
 * The same numeric values have context-specific meanings across OOB,
 * bus mastering (memory/MAF), and SAF completion.
 *
 * Reference: MCXA577 eSPI RM – Port OOB, Mastering, and Flash Length (PnOMFLEN).
 */
typedef enum _espi_omflen_trans
{
    /* ====================================================================== */
    /* OOB (Out-of-Band) Mailbox (TYPE = 0xB)                                */
    /* ====================================================================== */
    kESPI_OMFLEN_OOB_ToHost = 0x0U, /*!< 00b: OOB message to host. */

    /* ====================================================================== */
    /* Bus Master Memory (TYPE = 0x4)                                        */
    /* Host memory move directions and address sizes                         */
    /* ====================================================================== */
    kESPI_OMFLEN_MasterToHost32   = 0x0U, /*!< 00b: To host, 32-bit address read. */
    kESPI_OMFLEN_MasterToHost64   = 0x1U, /*!< 01b: To host, 64-bit address read. */
    kESPI_OMFLEN_MasterFromHost32 = 0x2U, /*!< 10b: From host, 32-bit address write. */
    kESPI_OMFLEN_MasterFromHost64 = 0x3U, /*!< 11b: From host, 64-bit address write. */

    /* ====================================================================== */
    /* Master-Attached Flash (MAF) (TYPE = 0x5)                              */
    /* Flash operation selection                                              */
    /* ====================================================================== */
    kESPI_OMFLEN_MAFReadFlash  = 0x1U, /*!< 01b: Read flash (location in RAM). */
    kESPI_OMFLEN_MAFWriteFlash = 0x2U, /*!< 10b: Write/program flash (location in RAM). */
    kESPI_OMFLEN_MAFEraseFlash = 0x3U, /*!< 11b: Erase flash (sector info in RAM). */

    /* ====================================================================== */
    /* SAF (Slave-Attached Flash) Completion (Flash port with SAF enabled)   */
    /* Completion result encoding                                             */
    /* ====================================================================== */
    kESPI_OMFLEN_SAFCompletionFail     = 0x0U, /*!< 00b: Completion failure (LEN=0). */
    kESPI_OMFLEN_SAFCompletionWithData = 0x1U, /*!< 01b: Completion with data (read). */
    kESPI_OMFLEN_SAFCompletionNoData   = 0x2U, /*!< 10b: Completion with no data (write/erase). */
} espi_omflen_trans_t;

/*!
 * @brief eSPI port error codes (context-dependent on port type).
 */
typedef enum _espi_port_error
{
    kESPI_PortError_None = 0U, /*!< No error. */

    /* Endpoint / Index-and-Data errors (ERR0-ERR2 valid) */
    kESPI_PortError_EndpointWriteOverrun = 1U, /*!< ERR0: Host wrote when WRDY=1. */
    kESPI_PortError_EndpointReadEmpty    = 2U, /*!< ERR1: Host read when RPEND=0. */
    kESPI_PortError_EndpointInvalidSize  = 3U, /*!< ERR2: Transfer size > 1 byte. */

    /* Mailbox errors. */
    kESPI_PortError_MailboxInvalidAccess   = 10U, /*!< ERR0: Invalid host read/write access. */
    kESPI_PortError_MailboxOverrunUnderrun = 11U, /*!< ERR1: Write overrun or read underrun. */
    kESPI_PortError_MailboxSizeOverflow    = 12U, /*!< ERR2: Request size exceeds mailbox boundary. */
    kESPI_PortError_MailboxRAMBusError     = 13U, /*!< ERR3: AHB/RAM access error. */

    /* Bus Master / Flash errors. */
    kESPI_PortError_MasterFromHostFailed  = 20U, /*!< ERR0: From-host transfer failed. */
    kESPI_PortError_MasterOverrunUnderrun = 21U, /*!< ERR1: Transfer timing error. */
    kESPI_PortError_MasterEraseFailed     = 22U, /*!< ERR2: Flash erase failed. */
    kESPI_PortError_MasterBusError        = 23U, /*!< ERR3: Bus master access error. */
} espi_port_error_t;

/*! @brief eSPI per-port configuration structure (PnCFG/PnADDR/PnRAMUSE).
 *
 * This describes one hardware port (Pn). ESPI_Init will program CFG, RAMUSE and
 * ADDR for each entry if provided in espi_config_t::portConfig.
 */
typedef struct _espi_port_config
{
    uint8_t type;            /*!< Port type. Refer to @ref espi_port_type_t. */
    uint8_t direction;       /*!< PnCFG.DIRECTION (for single-direction mailbox). */
    uint32_t ramOffset;      /*!< PnRAMUSE.OFF (byte address offset from RAMBASE). */
    espi_ram_size_t ramSize; /*!< PnRAMUSE.LEN encoding (4,8,...,512 bytes). */
    uint32_t addrOffset;     /*!< PnADDR.OFF (offset within selected base). */
    uint8_t addrBase;        /*!< PnADDR.BASE/ASZ encoding. */
    uint8_t idxOffset;       /*!< PnADDR.IDXOFF. */
} espi_port_config_t;

/*! @brief eSPI configuration structure. */
typedef struct _espi_config
{
    uint32_t ramBaseAddr;                 /*!< RAM base address. */
    uint16_t base0Addr;                   /*!< Base 0 address. */
    uint16_t base1Addr;                   /*!< Base 1 address. */
    bool enableSAF;                       /*!< Enable Slave Attached Flash. */
    bool enableOOB;                       /*!< Enable Out-Of-Band channel. */
    bool enableP80;                       /*!< Enable Port 80 capture/logic. */
    bool enableAlertPin;                  /*!< Alert pin enable. */
    uint8_t spiMode;                      /*!< SPI mode. */
    uint8_t busSpeed;                     /*!< Maximum SPI speed. */
    uint8_t enableMode;                   /*!< See espi_enable_mode_t. */
    uint8_t SAFEraseSize;                 /*!< SAF minimum erase sector size, see espi_saf_erase_size_t. */
    uint8_t maxSAFRxReqSize;              /*!< Maximum read request size. */
    uint8_t maxPayloadSize;               /*!< Maximum payload size. */
    uint8_t maxFlashPayloadSize;          /*!< Maximum flash payload size. */
    uint8_t maxOOBPayloadSize;            /*!< Maximum OOB payload size. */
    const espi_port_config_t *portConfig; /*!< Port configurations(array). */
    uint32_t portCount;                   /*!< Number of entries in portConfig. */
} espi_config_t;

/*!
 * @brief Port 80 status structure.
 */
typedef struct _espi_port80_status
{
    uint8_t currentCode;  /*!< Current POST code. */
    uint8_t previousCode; /*!< Previous POST code. */
    uint8_t counter;      /*!< POST code counter (0-15, wraps). */
} espi_p80_status_t;

/*! @brief eSPI Virtual Wire receive flags.
 *
 * Symbolic names for bits reported by `WIRERO`. These indicate host-driven
 * VWIRE signal states latched in the receive register.
 */
typedef enum _espi_vw_rd_flags
{
    kESPI_VWireRd_SlpS3N      = ESPI_WIRERO_SLP_S3N_MASK,        /*!< Sleep State S3. */
    kESPI_VWireRd_SlpS4N      = ESPI_WIRERO_SLP_S4N_MASK,        /*!< Sleep State S4. */
    kESPI_VWireRd_SlpS5N      = ESPI_WIRERO_SLP_S5N_MASK,        /*!< Sleep State S5. */
    kESPI_VWireRd_SusStat     = ESPI_WIRERO_SUS_STAT_MASK,       /*!< Suspend Status. */
    kESPI_VWireRd_PltRst      = ESPI_WIRERO_PLTRSTN_MASK,        /*!< Platform Reset Request. */
    kESPI_VWireRd_OobRstWarn  = ESPI_WIRERO_OOB_RST_WARN_MASK,   /*!< OOB Reset Warning. */
    kESPI_VWireRd_HostRstWarn = ESPI_WIRERO_HOST_RST_WARN_MASK,  /*!< Host Reset Warning. */
    kESPI_VWireRd_SusWarn     = ESPI_WIRERO_SUS_WARN_MASK,       /*!< Suspend Warning. */
    kESPI_VWireRd_SusPwrdnAck = ESPI_WIRERO_SUS_PWRDN_ACKN_MASK, /*!< Suspend Power Well Acknowledge. */
    kESPI_VWireRd_SlpAN       = ESPI_WIRERO_SLP_AN_MASK,         /*!< Sleep AN. */
    kESPI_VWireRd_SlpLAN      = ESPI_WIRERO_SLP_LAN_MASK,        /*!< Wired LAN Sleep. */
    kESPI_VWireRd_SlpWLAN     = ESPI_WIRERO_SLP_WLAN_MASK,       /*!< Wireless LAN Sleep. */
    kESPI_VWireRd_P2E         = ESPI_WIRERO_P2E_MASK,            /*!< PCIe to EC group. */
    kESPI_VWireRd_HostC10N    = ESPI_WIRERO_HOST_C10N_MASK,      /*!< Host entering C10 state. */
} espi_vw_rd_flags_t;

/*! @brief eSPI Virtual Wire write/ack flags (WIREWO)
 *
 * Symbolic names for bits written to `WIREWO` to drive or acknowledge VWIRE
 * signals to the host.
 */
typedef enum _espi_vw_wr_flags
{
    kESPI_VWireWr_DswPwrokRst = ESPI_WIREWO_DSW_PWROK_RST_MASK, /*!< DSW / PWR OK / Reset (Wr). */
    kESPI_VWireWr_BootErrn    = ESPI_WIREWO_BOOT_ERRN_MASK,     /*!< Boot error (active low, Wr). */
    kESPI_VWireWr_BootDone    = ESPI_WIREWO_BOOT_DONE_MASK,     /*!< Boot done (Wr). */
    kESPI_VWireWr_E2P         = ESPI_WIREWO_E2P_MASK,           /*!< E2P field (Wr). */
    kESPI_VWireWr_SusAckN     = ESPI_WIREWO_SUSACKN_MASK,       /*!< Suspend acknowledge (active low, Wr). */
    kESPI_VWireWr_HostRstAck  = ESPI_WIREWO_HOST_RST_ACK_MASK,  /*!< Host reset acknowledge (Wr). */
    kESPI_VWireWr_Rcinn       = ESPI_WIREWO_RCINN_MASK,         /*!< RCINN group (Wr). */
    kESPI_VWireWr_Smin        = ESPI_WIREWO_SMIN_MASK,          /*!< SMIN group (Wr). */
    kESPI_VWireWr_Scin        = ESPI_WIREWO_SCIN_MASK,          /*!< SCIN group (Wr). */
    kESPI_VWireWr_Pmen        = ESPI_WIREWO_PMEN_MASK,          /*!< Power management enable (Wr). */
    kESPI_VWireWr_WakenScin   = ESPI_WIREWO_WAKEN_SCIN_MASK,    /*!< Wake enable / sensor input (Wr). */
    kESPI_VWireWr_OobRstAck   = ESPI_WIREWO_OOB_RST_ACK_MASK,   /*!< OOB reset acknowledge (Wr). */
} espi_vw_wr_flags_t;

/*! @brief eSPI flash request structure. */
typedef struct _espi_flash_request
{
    uint32_t addr;                /*!< Flash address. */
    uint32_t length;              /*!< Request length. */
    uint8_t tag;                  /*!< Transaction tag. */
    espi_flash_trans_type_t type; /*!< Transaction type. */
    uint8_t *data;                /*!< Pointer to payload data. */
    bool readStart;               /*!< Read request with address and length information. */
} espi_flash_request_t;

typedef struct _espi_handle espi_handle_t;

/*! @brief eSPI common callback function pointer. */
typedef void (*espi_common_callback_t)(ESPI_Type *base, uint32_t status, void *userData);

/*! @brief eSPI port callback function pointer. */
typedef void (*espi_port_callback_t)(
    ESPI_Type *base, espi_handle_t *handle, uint32_t port, uint32_t status, void *userData);

/*! @brief eSPI flash callback function pointer. */
typedef void (*espi_flash_ops_t)(ESPI_Type *base, espi_handle_t *handle, espi_flash_request_t *req, void *userData);

/*!
 * @brief eSPI callback configuration structure.
 */
typedef struct _espi_callback_config
{
    espi_common_callback_t commonCallback; /*!< Global event callback. */
    espi_port_callback_t portCallback;     /*!< Port event callback. */
} espi_callback_config_t;

/*! @brief eSPI handle structure. */
struct _espi_handle
{
    espi_callback_config_t callback;      /*!< Callback function. */
    void *userData;                       /*!< User data. */
    espi_flash_ops_t flashOps;            /*!< Flash backend operations. */
    uint32_t flashSize;                   /*!< Flash address space size for bounds checking. */
    uint32_t addrOffset[ESPI_PORT_COUNT]; /*!< Cached PnADDR.OFF values for each port. */
    uint8_t oobPort;                      /*!< Port index for OOB (TYPE=Mailbox OOB Split). */
    uint8_t safPort;                      /*!< Port index for Slave Flash. */
    uint8_t mafPort;                      /*!< Port index for Bus Master Mem Single. */
};

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @name Initialization and deinitialization
 * @{
 */

/*!
 * @brief Initializes the eSPI peripheral.
 *
 * This function enables the eSPI clock, configures the eSPI peripheral according
 * to the configuration structure.
 *
 * @param base eSPI peripheral base address.
 * @param config Pointer to the configuration structure.
 */
void ESPI_Init(ESPI_Type *base, const espi_config_t *config);

/*!
 * @brief Deinitializes the eSPI peripheral.
 *
 * This function disables the eSPI peripheral and gates the eSPI clock.
 *
 * @param base eSPI peripheral base address.
 */
void ESPI_Deinit(ESPI_Type *base);

/*!
 * @brief Gets the default configuration structure.
 *
 * This function initializes the eSPI configuration structure to default values.
 *
 * @param config Pointer to the configuration structure.
 */
void ESPI_GetDefaultConfig(espi_config_t *config);

/*! @} */

/*!
 * @name Status
 * @{
 */

/*!
 * @brief Gets the eSPI status flags.
 *
 * @param base eSPI peripheral base address.
 * @return Status flags mask. AND with #_espi_status_flags to test specific flags.
 */
static inline uint32_t ESPI_GetStatusFlags(ESPI_Type *base)
{
    return base->MSTAT;
}

/*!
 * @brief Clears the eSPI status flags.
 *
 * @param base eSPI peripheral base address.
 * @param mask Status flag mask, see #_espi_status_flags.
 */
static inline void ESPI_ClearStatusFlags(ESPI_Type *base, uint32_t mask)
{
    base->MSTAT = mask;
}

/*!
 * @brief Gets a pointer to the RAM memory buffer.
 *
 * Returns a pointer to the start of the mailbox RAM for a port.
 *
 * @param base eSPI peripheral base address.
 * @param port Hardware port index.
 * @return Pointer to the start of the mailbox/port RAM.
 */
static inline uint8_t *ESPI_GetPortRamBuffer(ESPI_Type *base, uint32_t port)
{
    assert(port < ESPI_PORT_COUNT);
    uint32_t offset = (base->PORT[port].RAMUSE & ESPI_RAMUSE_OFF_MASK) >> ESPI_RAMUSE_OFF_SHIFT;
    return (uint8_t *)(base->RAMBASE + offset);
}

/*!
 * @brief Gets the maximum flash payload size.
 *
 * Calculates the configured maximum flash payload in bytes.
 *
 * @param base eSPI peripheral base address.
 * @return Maximum flash payload size in bytes.
 */
static inline uint32_t ESPI_GetFlashMaxPayload(ESPI_Type *base)
{
    return (64U << ((base->ESPICFG & ESPI_ESPICFG_FLASHSZ_MASK) >> ESPI_ESPICFG_FLASHSZ_SHIFT));
}

/*! @} */

/*!
 * @name Interrupts
 * @{
 */

/*!
 * @brief Enables the eSPI interrupts.
 *
 * @param base eSPI peripheral base address.
 * @param mask Interrupt source, see #_espi_interrupt_enable.
 */
static inline void ESPI_EnableInterrupts(ESPI_Type *base, uint32_t mask)
{
    base->INTENSET = mask;
}

/*!
 * @brief Disables the eSPI interrupts.
 *
 * @param base eSPI peripheral base address.
 * @param mask Interrupt source, see #_espi_interrupt_enable.
 */
static inline void ESPI_DisableInterrupts(ESPI_Type *base, uint32_t mask)
{
    base->INTENCLR = mask;
}

/*!
 * @brief Gets the enabled eSPI interrupts.
 *
 * @param base eSPI peripheral base address.
 * @return Enabled interrupts, see #_espi_interrupt_enable.
 */
static inline uint32_t ESPI_GetEnabledInterrupts(ESPI_Type *base)
{
    return base->INTENSET;
}

/*!
 * @brief Sets the IRQ push register.
 *
 * This register allows the application to push an IRQ assert through eSPI.
 *
 * @param base eSPI peripheral base address.
 * @param irqNum IRQ to push across to host.
 */
static inline void ESPI_PushIrq(ESPI_Type *base, uint8_t irqNum)
{
    base->IRQPUSH = irqNum & ESPI_IRQPUSH_IRQ_MASK;
}

/*!
 * @brief Check if IRQ Push is Done
 * @param base ESPI peripheral base address.
 */
static inline bool ESPI_IsIrqPushDone(ESPI_Type *base)
{
    return ((base->IRQPUSH & ESPI_IRQPUSH_DONE_MASK) != 0U);
}

/*! @} */

/*!
 * @name Port Configuration
 * @{
 */

/*!
 * @brief Gets the configured type of an eSPI port.
 *
 * This function reads the PnCFG register and extracts the TYPE field,
 * which indicates how the port interacts with the host (endpoint, mailbox,
 * bus master, etc.).
 *
 * @param base eSPI peripheral base address.
 * @param port Port index (0 to ESPI_PORT_COUNT-1).
 * @return Port type value, see @ref espi_port_type_t.
 */
static inline espi_port_type_t ESPI_GetPortType(ESPI_Type *base, uint32_t port)
{
    assert(port < ESPI_PORT_COUNT);
    return (espi_port_type_t)((base->PORT[port].CFG & ESPI_CFG_TYPE_MASK) >> ESPI_CFG_TYPE_SHIFT);
}

/*!
 * @brief Enables the eSPI port interrupts.
 *
 * @param base eSPI peripheral base address.
 * @param port eSPI port.
 * @param mask Interrupt mask, see #_espi_port_interrupt_flags.
 */
static inline void ESPI_EnablePortInterrupts(ESPI_Type *base, uint32_t port, uint32_t mask)
{
    assert(port < ESPI_PORT_COUNT);
    base->PORT[port].IRULESTAT |= mask;
}

/*!
 * @brief Disables the eSPI port interrupts.
 *
 * @param base eSPI peripheral base address.
 * @param port eSPI port.
 * @param mask Interrupt mask, see #_espi_port_interrupt_flags.
 */
static inline void ESPI_DisablePortInterrupts(ESPI_Type *base, uint32_t port, uint32_t mask)
{
    assert(port < ESPI_PORT_COUNT);
    base->PORT[port].IRULESTAT &= ~mask;
}

/*!
 * @brief Gets the eSPI port status.
 *
 * @param base eSPI peripheral base address.
 * @param port eSPI port index.
 * @return Port status flags.
 */
static inline uint32_t ESPI_GetPortStatus(ESPI_Type *base, uint32_t port)
{
    assert(port < ESPI_PORT_COUNT);
    return base->PORT[port].STAT;
}

/*!
 * @brief Writes the eSPI port DATAOUT register.
 *
 * This function writes a response byte to the DATAOUT register for
 * endpoint or index/data port types.
 *
 * @param base eSPI peripheral base address.
 * @param port eSPI port index.
 * @param data Value to write to DATAOUT.
 */
static inline void ESPI_WritePortData(ESPI_Type *base, uint32_t port, uint32_t data)
{
    assert(port < ESPI_PORT_COUNT);
    base->PORT[port].DATAOUT = ESPI_DATAOUT_DATA(data);
}

/*!
 * @brief Clears the eSPI port status flags.
 *
 * @param base eSPI peripheral base address.
 * @param port eSPI port index.
 * @param mask Port interrupt status flag mask, see #_espi_port_interrupt_flags.
 */
static inline void ESPI_ClearPortStatus(ESPI_Type *base, uint32_t port, uint32_t mask)
{
    assert(port < ESPI_PORT_COUNT);
    base->PORT[port].STAT = (mask & (uint32_t)kESPI_PortAllInterrupts);
}

/*!
 * @brief Gets the mailbox maximum size (bytes) for a port.
 *
 * @param base eSPI peripheral base address.
 * @param port Hardware port index.
 * @return Mailbox size in bytes.
 */
static inline uint32_t ESPI_GetPortMailboxSize(ESPI_Type *base, uint32_t port)
{
    assert(port < ESPI_PORT_COUNT);
    return (uint32_t)(4U << ((base->PORT[port].RAMUSE & ESPI_RAMUSE_LEN_MASK) >> ESPI_RAMUSE_LEN_SHIFT));
}

/*!
 * @brief Gets Port 80 status and POST codes.
 *
 * This function reads the Port 80 status register and extracts the current POST code,
 * previous POST code, and counter value. Port 80 is used by BIOS/UEFI to write
 * Power-On Self-Test (POST) codes during boot for debugging purposes.
 *
 * @param base eSPI peripheral base address.
 * @param status Pointer to structure to receive Port 80 status.
 * @retval kStatus_Success Successfully read Port 80 status.
 * @retval kStatus_Fail Port 80 is not enabled.
 */
status_t ESPI_GetPort80Status(ESPI_Type *base, espi_p80_status_t *status);

/*!
 * @brief Resets Port 80 counter.
 *
 * This function resets the Port 80 POST code counter back to 0.
 *
 * @param base eSPI peripheral base address.
 */
static inline void ESPI_ResetPort80Counter(ESPI_Type *base)
{
    base->P80STAT |= ESPI_P80STAT_RST_MASK;
}

/*!
 * @brief Gets endpoint data fields from a port.
 *
 * This function reads PnDATAIN and extracts the IDX field and DATA_LEN field.
 *
 * @param base eSPI peripheral base address.
 * @param port eSPI port index.
 * @param idx Pointer to store the extracted IDX field.
 * @param data Pointer to store the extracted DATA_LEN field.
 */
void ESPI_GetEndpointData(ESPI_Type *base, uint32_t port, uint32_t *idx, uint32_t *data);

/*!
 * @brief Checks port error status.
 *
 * Reads and interprets the error bits (ERR0-ERR3) from PnSTAT register.
 * Returns a specific error code based on the port type.
 *
 * Error bit interpretation depends on port type.
 *
 * @param base eSPI peripheral base address.
 * @param port Port number to check.
 * @param pstat Port status from PnSTAT register.
 * @param error Pointer to structure to receive error information.
 *
 * @note Error status bits are read-only and automatically cleared by hardware
 *       when the error condition is resolved.
 * @note Only returns the first error found (priority: ERR0 > ERR1 > ERR2 > ERR3).
 */
void ESPI_GetPortErrorStatus(ESPI_Type *base, uint32_t port, uint32_t pstat, espi_port_error_t *error);

/*!
 * @brief Gets the message length from DATAIN register.
 *
 * This function reads the PnDATAIN register and extracts the DATA_LEN field,
 * which indicates the number of bytes in the current mailbox message.
 * The actual length is DATA_LEN + 1.
 *
 * @param base eSPI peripheral base address.
 * @param port Port index.
 * @return Message length in bytes.
 */
static inline uint32_t ESPI_GetPortMsgLen(ESPI_Type *base, uint32_t port)
{
    assert(port < ESPI_PORT_COUNT);
    return ((base->PORT[port].DATAIN & ESPI_DATAIN_DATA_LEN_MASK) + 1U);
}

/*! @} */

/*!
 * @name Virtual Wire
 * @{
 */

/*!
 * @brief Reads current Virtual Wire receive status.
 *
 * Returns raw `WIRERO` bits so upper layers can inspect incoming VW signals.
 *
 * @param base eSPI peripheral base address.
 * @return Raw `WIRERO` bitfield value.
 */
static inline uint32_t ESPI_GetVWire(ESPI_Type *base)
{
    return base->WIRERO;
}

/*!
 * @brief Sends a virtual wire message.
 *
 * @param base eSPI peripheral base address.
 * @param flag Virtual wire flag to send, see @ref espi_vw_wr_flags_t.
 * @param value Value to set for the wire.
 * @retval kStatus_Success Operation completed.
 * @retval kStatus_Busy Previous write still pending.
 */
status_t ESPI_SendVWire(ESPI_Type *base, espi_vw_wr_flags_t flag, uint32_t value);

/*! @} */

/*!
 * @name OOB (Out-of-Band)
 * @{
 */

/*!
 * @brief Triggers an OOB message.
 *
 * Programs `PnOMFLEN.LEN` and sets `PnIRULESTAT.SSTCL` to start an outbound OOB message.
 *
 * @param base eSPI peripheral base address.
 * @param handle eSPI handle (provides OOB port index and ACK flag).
 * @param length Message length in bytes (> 0).
 */
void ESPI_TriggerOOBMsg(ESPI_Type *base, espi_handle_t *handle, uint32_t length);

/*!
 * @brief Send an Out-of-Band (OOB) message.
 *
 * Copies `length` bytes into the OOB mailbox, triggers the OOB message.
 *
 * @param base eSPI peripheral base address.
 * @param handle Optional eSPI handle to arm IRQ-driven ACK handling.
 * @param data Pointer to data to send.
 * @param length Number of bytes to send (>0).
 * @param announce If true, set SSTCL to "Started by MCU" before copy.
 * @retval kStatus_Success Message accepted and triggered.
 * @retval kStatus_InvalidArgument Invalid argument.
 */
status_t ESPI_SendOOB(ESPI_Type *base, espi_handle_t *handle, const uint8_t *data, uint32_t length, bool announce);

/*!
 * @brief Reads the OOB mailbox into a destination buffer.
 *
 * Copies the OOB message into `buffer` (up to `*len`). `*len` receives the
 * actual number of bytes copied. Returns `kStatus_ESPI_Error` if
 * truncation occurred.
 *
 * @param base eSPI peripheral base address.
 * @param handle eSPI handle.
 * @param buffer Destination data buffer.
 * @param len [in] Length of bytes to receive, [out] Length of actual received bytes.
 * @retval kStatus_Success Read successfully (no truncation).
 * @retval kStatus_ESPI_Error Message truncated.
 */
status_t ESPI_ReadOOB(ESPI_Type *base, espi_handle_t *handle, uint8_t *buffer, uint32_t *len);

/*! @} */

/*!
 * @name Transactional
 * @{
 */

/*!
 * @brief Sets the flash operation length.
 *
 * Configures the transaction type and payload length for a flash operation.
 *
 * @param base eSPI peripheral base address.
 * @param port Hardware port index.
 * @param type Flash transaction type.
 * @param length Payload length in bytes.
 */
static inline void ESPI_SetFlashOpLen(ESPI_Type *base, uint32_t port, uint32_t type, uint32_t length)
{
    base->PORT[port].OMFLEN = ESPI_OMFLEN_TRANS(type) | ESPI_OMFLEN_LEN((length == 0U) ? 0U : (length - 1U));
}

/*!
 * @brief Sets the flash completion status.
 *
 * Updates the completion status fields for the specified port and tag.
 *
 * @param base eSPI peripheral base address.
 * @param port Hardware port index.
 * @param tag Transaction tag.
 * @param state Transaction state.
 * @param type Completion type.
 */
void ESPI_SetFlashCompletion(ESPI_Type *base, uint32_t port, uint32_t tag, uint32_t state, uint32_t type);

/*!
 * @brief Initializes the eSPI handle.
 *
 * @param base eSPI peripheral base address.
 * @param handle Pointer to the eSPI handle.
 * @param config Pointer to the configuration structure.
 * @param callback Pointer to callback configuration structure.
 * @param userData User data.
 */
void ESPI_CreateHandle(ESPI_Type *base,
                       espi_handle_t *handle,
                       const espi_config_t *config,
                       espi_callback_config_t *callback,
                       void *userData);

/*!
 * @brief Initializes the eSPI flash functionality in the handle.
 *
 * @param base eSPI peripheral base address.
 * @param handle Pointer to the eSPI handle.
 * @param flashOps Pointer to flash backend operations.
 * @param flashSize Flash address space size.
 */
void ESPI_FlashCreateHandle(
    ESPI_Type *base, espi_handle_t *handle, espi_flash_ops_t flashOps, uint32_t flashSize);

/*!
 * @brief eSPI IRQ handle function.
 *
 * This function handles the eSPI transmit and receive IRQ request.
 *
 * @param base eSPI peripheral base address.
 * @param handle Pointer to the eSPI handle.
 */
void ESPI_TransferHandleIRQ(ESPI_Type *base, espi_handle_t *handle);

/*! @} */

#if defined(__cplusplus)
}
#endif

/*! @} */

#endif /* FSL_ESPI_H_ */
