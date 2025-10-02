/*
 * Copyright 2023, 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_FLEXSPI_FLR_H_
#define FSL_FLEXSPI_FLR_H_

#include <stddef.h>
#include "fsl_device_registers.h"
#include "fsl_common.h"

/*!
 * @addtogroup flexspi_flr
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*@{*/
/*! @brief FLEXSPI FOLLOWER driver version. */
#define FSL_FLEXSPI_SLV_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*@}*/

#define FLEXSPI_SLV_CMD_DDR(x) (((uint16_t)(x) << 8U) | (uint16_t)(x))

/*! @brief IO mode enumeration of FLEXSPI FOLLOWER.*/
enum
{
    kFLEXSPI_SLV_IOMODE_SDRx4 = 0,
    kFLEXSPI_SLV_IOMODE_SDRx8 = 1,
    kFLEXSPI_SLV_IOMODE_DDRx4 = 2,
    kFLEXSPI_SLV_IOMODE_DDRx8 = 3
};

/*! @brief The read fetch size enumeration of FLEXSPI FOLLOWER.*/
enum
{
    kFLEXSPI_SLV_Read_Fetch_256Bytes = 0,
    kFLEXSPI_SLV_Read_Fetch_512Bytes = 1,
    kFLEXSPI_SLV_Read_Fetch_1KBytes  = 2,
    kFLEXSPI_SLV_Read_Fetch_2KBytes  = 3
};

/*! @brief The write watermark enumeration of FLEXSPI FOLLOWER.*/
enum
{
    kFLEXSPI_SLV_Write_Watermark_32Bytes  = 0,
    kFLEXSPI_SLV_Write_Watermark_64Bytes  = 1,
    kFLEXSPI_SLV_Write_Watermark_128Bytes = 2,
    kFLEXSPI_SLV_Write_Watermark_256Bytes = 3
};

/*! @brief Interrupt status flags of FLEXSPI FOLLOWER.*/
enum
{
    kFLEXSPI_SLV_WriteOverflowFlag = FLEXSPI_SLV_MODULE_INTEN_WOFEN_MASK,   /*!< An IO RX FIFO overflow occurred during
                                               command/address/write data phase. */
    kFLEXSPI_SLV_ReadUnderflowFlag = FLEXSPI_SLV_MODULE_INTEN_RUFEN_MASK,   /*!< IO TX FIFO underflow has occurred
                                                during a read command. */
    kFLEXSPI_SLV_ErrorCommandFlag = FLEXSPI_SLV_MODULE_INTEN_ERRCMDEN_MASK, /*!< An unknown command has been received
                                             from the SPI bus. */
    kFLEXSPI_SLV_MailInterruptFlag = 0x8U,                                  /*!< Mailbox interrupt. */
    kFLEXSPI_SLV_AllInterruptFlags = kFLEXSPI_SLV_WriteOverflowFlag | kFLEXSPI_SLV_ReadUnderflowFlag |
                                     kFLEXSPI_SLV_ErrorCommandFlag | kFLEXSPI_SLV_MailInterruptFlag, /*!< All flags. */
};

/*! @brief FLEXSPI FOLLOWER configuration structure. */
typedef struct _flexspi_slv_config
{
    uint32_t baseAddr1;          /*!< Read/Write CMD1 Base Address. */
    uint32_t baseAddr2;          /*!< Read/Write CMD2 Base Address. */
    uint32_t addrRange1;         /*!< Read/Write CMD1 Addr Range. */
    uint32_t addrRange2;         /*!< Read/Write CMD2 Addr Range. */
    uint8_t ioMode;              /*!< IO mode control - SDRx4, SDRx8, DDRx4, DDRx8. */
    uint8_t rxFetchSize;         /*!< Specifies the maximum read size triggered by a single read command. */
    uint8_t rxWatermark;         /*!< Triggers a new AXI read to fetch more data through the IP AXI header. */
    uint8_t txWatermark;         /*!< Specifies the watermark value. During the write command, if pending
                                   write data equals or exceeds the watermark level, it triggers a new AXI write. */
    uint16_t readRegCmd;         /*!< Read register command. */
    uint16_t readRegDummyCycle;  /*!< Read register dymmy cycle. */
    uint16_t writeRegCmd;        /*!< Write register command. */
    uint16_t readMemCmd1;        /*!< Read memory command1. */
    uint16_t readMemDummyCycle1; /*!< Read memory dymmy cycle1. */
    uint16_t readMemCmd2;        /*!< Read memory command2. */
    uint16_t readMemDummyCycle2; /*!< Read memory dymmy cycle2. */
    uint16_t writeMemCmd1;       /*!< Write memory command1. */
    uint16_t writeMemCmd2;       /*!< Write memory command2. */
} flexspi_slv_config_t;

/* Forward declaration of the handle typedef. */
typedef struct _flexspi_slv_handle flexspi_slv_handle_t;

/*! @brief FLEXSPI FOLLOWER interrupt callback function. */
typedef void (*flexspi_slv_callback_t)(FLEXSPI_SLV_Type *base, flexspi_slv_handle_t *handle);

/*! @brief Interrupt handle structure for FLEXSPI FOLLOWER. */
struct _flexspi_slv_handle
{
    uint32_t intrMask;               /*!< Interrupt state for FLEXSPI FOLLOWER. */
    flexspi_slv_callback_t callback; /*!< Callback for users while mailbox received or error occurred. */
};

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif /*_cplusplus. */

/*!
 * @name Initialization and deinitialization
 * @{
 */

/*!
 * @brief Get the instance number for FLEXSPI FOLLOWER.
 *
 * @param base FLEXSPI FOLLOWER base pointer.
 */
uint32_t FLEXSPI_SLV_GetInstance(FLEXSPI_SLV_Type *base);

/*!
 * @brief Initializes the FLEXSPI FOLLOWER module and internal state.
 *
 * This function enables the clock for FLEXSPI FOLLOWER and also configures the FLEXSPI FOLLOWER
 * with the input configure parameters. Users should call this function before any FLEXSPI
 * FOLLOWER operations.
 *
 * @param base FLEXSPI FOLLOWER peripheral base address.
 * @param config FLEXSPI FOLLOWER configure structure.
 */
void FLEXSPI_SLV_Init(FLEXSPI_SLV_Type *base, const flexspi_slv_config_t *config);

/*!
 * @brief Gets default settings for FLEXSPI FOLLOWER.
 *
 * @param config FLEXSPI FOLLOWER configuration structure.
 */
void FLEXSPI_SLV_GetDefaultConfig(flexspi_slv_config_t *config);

/*!
 * @brief Deinitializes the FLEXSPI FOLLOWER module.
 *
 * Clears the FLEXSPI FOLLOWER state and FLEXSPI FOLLOWER module registers.
 * @param base FLEXSPI FOLLOWER peripheral base address.
 */
void FLEXSPI_SLV_Deinit(FLEXSPI_SLV_Type *base);

/*!
 * @brief Software reset for the FLEXSPI FOLLOWER logic.
 *
 * This function does software reset for the FLEXSPI FOLLOWER.
 *
 * @param base FLEXSPI FOLLOWER peripheral base address.
 */
static inline void FLEXSPI_SLV_SoftwareReset(FLEXSPI_SLV_Type *base)
{
#if (defined(FSL_FEATURE_NETC_HAS_ERRATA_052145) && FSL_FEATURE_NETC_HAS_ERRATA_052145)
    /* Errata 052145: AWhen setting the block operations (Block Read, Block Write, Block Next Read and Block Next Write)
       in MODULE_CONTROL register and implementing the software reset, the block behavior will mismatch the bit
       definition in the register after the reset. */
    base->MODULE_CONTROL = 0;
#endif

    base->MODULE_CONTROL |= FLEXSPI_SLV_MODULE_CONTROL_SWRESET_MASK;
    base->MODULE_CONTROL &= ~FLEXSPI_SLV_MODULE_CONTROL_SWRESET_MASK;
}

/*!
 * @brief Set IO mode for the FLEXSPI FOLLOWER module.
 *
 * This function sets the IO mode flags for the FLEXSPI FOLLOWER.
 *
 * @param base FLEXSPI FOLLOWER peripheral base address.
 * @param ioMode Set IO Mode for FLEXSPI FOLLOWER
 */
static inline void FLEXSPI_SLV_SetIOMode(FLEXSPI_SLV_Type *base, uint32_t ioMode)
{
    base->MODULE_CONTROL =
        (base->MODULE_CONTROL & ~FLEXSPI_SLV_MODULE_CONTROL_IOMODE_MASK) | FLEXSPI_SLV_MODULE_CONTROL_IOMODE(ioMode);
}

/*!
 * @brief Update RW CMD base address and range value for the FLEXSPI FOLLOWER module.
 *
 * This function updates RW CMD base address and range value for the FLEXSPI FOLLOWER.
 *
 * @param base FLEXSPI FOLLOWER peripheral base address.
 */
static inline void FLEXSPI_SLV_UpdateRWCmdBaseRange(FLEXSPI_SLV_Type *base)
{
    base->MODULE_CONTROL |= FLEXSPI_SLV_MODULE_CONTROL_CMDRANGEBASEUPDATE_MASK;
}

/*!
 * @brief Set RW command base address1 for the FLEXSPI FOLLOWER module.
 *
 * This function sets the RW command base address1 for the FLEXSPI FOLLOWER.
 *
 * @param base FLEXSPI FOLLOWER peripheral base address.
 * @param addr1 The high 16-bit base address of the RW command0.
 * @param addr2 The high 16-bit base address of the RW command1.
 */
static inline void FLEXSPI_SLV_SetRWCmdBaseAddr(FLEXSPI_SLV_Type *base, uint32_t addr1, uint32_t addr2)
{
    base->RW_COMMAND_BASE = FLEXSPI_SLV_RW_COMMAND_BASE_ADDRBASE1(addr1) | FLEXSPI_SLV_RW_COMMAND_BASE_ADDRBASE2(addr2);
}

/*!
 * @brief Set address1/2 range for the FLEXSPI FOLLOWER module.
 *
 * This function sets the address1/2 range for the FLEXSPI FOLLOWER.
 *
 * @param base FLEXSPI FOLLOWER peripheral base address.
 * @param index The index of RW command, 0 or 1.
 * @param val The size of the memory range in 1KB units.
 */
static inline void FLEXSPI_SLV_SetAddrRange(FLEXSPI_SLV_Type *base, uint32_t index, uint32_t val)
{
    assert(index < FLEXSPI_SLV_CMD_RANGE_COUNT);
    base->CMD_RANGE[index] = FLEXSPI_SLV_CMD_RANGE_RANGE(val);
}

/*!
 * @brief Set read water mark level for the FLEXSPI FOLLOWER module.
 *
 * This function sets read water mark level for the FLEXSPI FOLLOWER.
 *
 * @param base FLEXSPI FOLLOWER peripheral base address.
 * @param val Read watermark level in bytes
 */
static inline void FLEXSPI_SLV_SetReadWatermark(FLEXSPI_SLV_Type *base, uint32_t rxWatermark, bool enable)
{
    base->READ_COMMAND_CONTROL =
        (base->READ_COMMAND_CONTROL &
         ~(FLEXSPI_SLV_READ_COMMAND_CONTROL_WMEN_MASK | FLEXSPI_SLV_READ_COMMAND_CONTROL_RDWM_MASK)) |
        (enable ? FLEXSPI_SLV_READ_COMMAND_CONTROL_WMEN_MASK : 0U) | FLEXSPI_SLV_READ_COMMAND_CONTROL_RDWM(rxWatermark);
}

/*!
 * @brief Sets the maximum read size triggered by a single read command.
 *
 * This function sets the maximum read size for the FLEXSPI FOLLOWER.
 *
 * @param base FLEXSPI  FOLLOWER peripheral base address.
 * @param rxFetchSize  The maximum read size triggered by a single read command.
 */
static inline void FLEXSPI_SLV_SetReadFetchSize(FLEXSPI_SLV_Type *base, uint32_t rxFetchSize)
{
    base->READ_COMMAND_CONTROL = (base->WRITE_COMMAND_CONTROL & ~FLEXSPI_SLV_READ_COMMAND_CONTROL_RDFETCHSIZE_MASK) |
                                 FLEXSPI_SLV_READ_COMMAND_CONTROL_RDFETCHSIZE(rxFetchSize);
}

/*!
 * @brief Set write water mark level for the FLEXSPI FOLLOWER module.
 *
 * This function sets write water mark level for the FLEXSPI FOLLOWER.
 *
 * @param base FLEXSPI FOLLOWER peripheral base address.
 * @param txWatermark Write watermark level
 */
static inline void FLEXSPI_SLV_SetWriteWatermark(FLEXSPI_SLV_Type *base, uint32_t txWatermark)
{
    base->WRITE_COMMAND_CONTROL = (base->WRITE_COMMAND_CONTROL & ~FLEXSPI_SLV_WRITE_COMMAND_CONTROL_WRWM_MASK) |
                                  FLEXSPI_SLV_WRITE_COMMAND_CONTROL_WRWM(txWatermark);
}

/*!
 * @brief Set CS mask value for the FLEXSPI FOLLOWER module.
 *
 * This function sets CS mask value for the FLEXSPI FOLLOWER.
 *
 * @param base  FLEXSPI FOLLOWER peripheral base address.
 * @param mask  0 - Not masked, 1 - Masked.
 */
static inline void FLEXSPI_SLV_MaskChipSelect(FLEXSPI_SLV_Type *base, uint32_t mask)
{
    base->MODULE_CONTROL =
        (base->MODULE_CONTROL & ~FLEXSPI_SLV_MODULE_CONTROL_CSMASK_MASK) | FLEXSPI_SLV_MODULE_CONTROL_CSMASK(mask);
}
/* @} */

/*!
 * @name Interrupts
 * @{
 */
/*!
 * @brief Enables the FLEXSPI FOLLOWER interrupts.
 *
 * @param base FLEXSPI FOLLOWER peripheral base address.
 * @param mask FLEXSPI FOLLOWER interrupt source.
 */
static inline void FLEXSPI_SLV_EnableInterrupts(FLEXSPI_SLV_Type *base, uint32_t mask)
{
    base->MODULE_INTEN |= mask;
}

/*!
 * @brief Disable the FLEXSPI FOLLOWER interrupts.
 *
 * @param base FLEXSPI FOLLOWER peripheral base address.
 * @param mask FLEXSPI FOLLOWER interrupt source.
 */
static inline void FLEXSPI_SLV_DisableInterrupts(FLEXSPI_SLV_Type *base, uint32_t mask)
{
    base->MODULE_INTEN &= ~mask;
}

/*!
 * @brief Get the FLEXSPI FOLLOWER enabled interrupts.
 *
 * @param base FLEXSPI FOLLOWER peripheral base address.
 */
static inline uint32_t FLEXSPI_SLV_GetEnabledInterrupts(FLEXSPI_SLV_Type *base)
{
    return base->MODULE_INTEN;
}

/*!
 * @brief Enable the FLEXSPI FOLLOWER mailbox interrupts.
 *
 * @param base FLEXSPI FOLLOWER peripheral base address.
 * @param enable Whether enable the mailbox interrupt.
 */
static inline void FLEXSPI_SLV_EnableMailInterrupt(FLEXSPI_SLV_Type *base, bool enable)
{
    base->SPI_MAIL_CTRL = FLEXSPI_SLV_SPI_MAIL_CTRL_SPIINTEN(enable ? 1 : 0);
}

/*!
 * @brief Return whether the FLEXSPI FOLLOWER enables the mailbox interrupt.
 *
 * @param base FLEXSPI FOLLOWER peripheral base address.
 */
static inline bool FLEXSPI_SLV_GetEnabledMailInterrupt(FLEXSPI_SLV_Type *base)
{
    return (0U != (base->SPI_MAIL_CTRL & FLEXSPI_SLV_SPI_MAIL_CTRL_SPIINTEN_MASK));
}
/* @} */

/*!
 * @brief Gets the SPI leader read/write out-of-allowed-range count.
 *
 * @param base FLEXSPI FOLLOWER peripheral base address.
 * @param[out] rdCount Pointer through which the current number in the read out-of-allowed-range counter is returned.
 *      Pass NULL if this value is not required.
 * @param[out] wrCount Pointer through which the current number in the write out-of-allowed-range counter is returned
 *      Pass NULL if this value is not required.
 */
static inline void FLEXSPI_SLV_GetOutOfRangeCounts(FLEXSPI_SLV_Type *base, size_t *rdCount, size_t *wrCount)
{
    if (NULL != rdCount)
    {
        *rdCount =
            ((base->MODULE_STATUS) & FLEXSPI_SLV_MODULE_STATUS_RDOFR_MASK) >> FLEXSPI_SLV_MODULE_STATUS_RDOFR_SHIFT;
    }
    if (NULL != wrCount)
    {
        *wrCount =
            ((base->MODULE_STATUS) & FLEXSPI_SLV_MODULE_STATUS_WROFR_MASK) >> FLEXSPI_SLV_MODULE_STATUS_WROFR_SHIFT;
    }
}

/*!
 * @name Status
 * @{
 */
/*!
 * @brief Get the FLEXSPI FOLLOWER interrupt status flags.
 *
 * @param base FLEXSPI FOLLOWER peripheral base address.
 * @retval Interrupt status flag, use status flag to AND the bit mask could get the related status.
 */
static inline uint32_t FLEXSPI_SLV_GetInterruptStatusFlags(FLEXSPI_SLV_Type *base)
{
    return (base->MODULE_INT);
}

/*!
 * @brief Get the FLEXSPI FOLLOWER mailbox data.
 *
 * @param base FLEXSPI FOLLOWER peripheral base address.
 * @param index The index of the mail interrupt register
 * @return Return the FLEXSPI FOLLOWER mailbox data
 */
static inline uint32_t FLEXSPI_SLV_GetMailboxData(FLEXSPI_SLV_Type *base, uint32_t index)
{
    return ((index < FLEXSPI_SLV_SPIMAIL_COUNT) ? base->SPIMAIL[index] : 0U);
}

/*!
 * @brief Clear the FLEXSPI FOLLOWER interrupt status flags.
 *
 * @param base FLEXSPI FOLLOWER peripheral base address.
 * @param mask FLEXSPI FOLLOWER interrupt source.
 */
static inline void FLEXSPI_SLV_ClearInterruptStatusFlags(FLEXSPI_SLV_Type *base, uint32_t mask)
{
    base->MODULE_INT |= mask;
}

/*!
 * @brief Clear the FLEXSPI FOLLOWER mailbox interrupt flag.
 *
 * @param base FLEXSPI FOLLOWER peripheral base address.
 */
static inline void FLEXSPI_SLV_ClearMailInterruptFlag(FLEXSPI_SLV_Type *base)
{
    base->SPI_MAIL_CTRL |= FLEXSPI_SLV_SPI_MAIL_CTRL_CLRINT_MASK;
}

/*! @brief Returns whether the current AXI write leader is busy with a write command.
 *
 * @param base FLEXSPI FOLLOWER peripheral base address.
 * @retval true The current AXI write leader is busy.
 * @retval false The current AXI write leader is not busy.
 */
static inline bool FLEXSPI_SLV_GetAXIWriteBusyStatus(FLEXSPI_SLV_Type *base)
{
    return (0U != (base->MODULE_STATUS & FLEXSPI_SLV_MODULE_STATUS_WIP_MASK));
}

/*! @brief Returns whether the AXI read leader is busy with a read request or else idle with no pending
 *         AXI read request.
 *
 * @param base FLEXSPI FOLLOWER peripheral base address.
 * @retval true The current AXI read leader is idle.
 * @retval false The current AXI read leader is busy.
 */
static inline bool FLEXSPI_SLV_GetAXIReadIdleStatus(FLEXSPI_SLV_Type *base)
{
    return (0U != (base->MODULE_STATUS & FLEXSPI_SLV_MODULE_STATUS_AXIREADIDLE_MASK));
}

/*! @brief Returns whether the SPI to read/write register queue is idle.
 *
 * @param base FLEXSPI FOLLOWER peripheral base address.
 * @retval true The SPI to read/write register queue is idle.
 * @retval false The SPI to read/write register queue is busy.
 */
static inline bool FLEXSPI_SLV_GetRegReadWriteIdleStatus(FLEXSPI_SLV_Type *base)
{
    return (0U != (base->MODULE_STATUS & FLEXSPI_SLV_MODULE_STATUS_REGRWIDLE_MASK));
}

/*! @brief Returns whether the SEQ control logic is idle or else busy with an ongoing SPI request.
 *
 * @param base FLEXSPI FOLLOWER peripheral base address.
 * @retval true The SEQ control logic is idle.
 * @retval false The SEQ control logic is busy.
 */
static inline bool FLEXSPI_SLV_GetSEQIdleStatus(FLEXSPI_SLV_Type *base)
{
    return (0U != (base->MODULE_STATUS & FLEXSPI_SLV_MODULE_STATUS_SEQIDLE_MASK));
}

/*! @brief Returns whether the FLEXSPI FOLLOWER module is busy.
 *
 * @param base FLEXSPI FOLLOWER peripheral base address.
 * @retval true The SEQ control logic is busy.
 * @retval false The SEQ control logic is idle.
 */
static inline bool FLEXSPI_SLV_GetModuleBusyStatus(FLEXSPI_SLV_Type *base)
{
    uint32_t statusMasks = 0, idleFlags = 0;

    statusMasks = FLEXSPI_SLV_MODULE_STATUS_WIP_MASK | FLEXSPI_SLV_MODULE_STATUS_AXIREADIDLE_MASK |
                  FLEXSPI_SLV_MODULE_STATUS_REGRWIDLE_MASK | FLEXSPI_SLV_MODULE_STATUS_SEQIDLE_MASK;

    idleFlags = FLEXSPI_SLV_MODULE_STATUS_WIP(0) | FLEXSPI_SLV_MODULE_STATUS_AXIREADIDLE(1) |
                FLEXSPI_SLV_MODULE_STATUS_REGRWIDLE(1) | FLEXSPI_SLV_MODULE_STATUS_SEQIDLE(1);

    return (((base->MODULE_STATUS & statusMasks) != idleFlags) ? true : false);
}
/*@}*/

/*!
 * @name Bus Operations
 * @{
 */

/*!
 * @brief Sets the read memory command.
 *
 * @param base FLEXSPI FOLLOWER peripheral base address.
 * @param index  The read command setting register index.
 * @param command The read command value.
 * @param dummyCycle The dummy cycle value of the read command.
 */
static inline void FLEXSPI_SLV_SetReadMemCommand(FLEXSPI_SLV_Type *base,
                                                 uint32_t index,
                                                 uint16_t command,
                                                 uint16_t dummyCycle)
{
    assert(index < FLEXSPI_SLV_READ_COMMAND_COUNT);
    base->READ_COMMAND[index] =
        FLEXSPI_SLV_READ_COMMAND_COMMANDSET(command) | FLEXSPI_SLV_READ_COMMAND_DUMMYCYCLES(dummyCycle);
}

/*!
 * @brief Sets the write memory command.
 *
 * @param base  FLEXSPI FOLLOWER peripheral base address.
 * @param index  The write command setting register index.
 * @param command  The write command value.
 */
static inline void FLEXSPI_SLV_SetWriteMemCommand(FLEXSPI_SLV_Type *base, uint32_t index, uint32_t command)
{
    assert(index < FLEXSPI_SLV_WRITE_COMMAND_COUNT);
    base->WRITE_COMMAND[index] = FLEXSPI_SLV_WRITE_COMMAND_COMMANDSET(command);
}

/*!
 * @brief Sets the read register command.
 *
 * @param base FLEXSPI FOLLOWER peripheral base address
 * @param command The read command value.
 * @param dummyCycle The dummy cycle value of the read command.
 */
static inline void FLEXSPI_SLV_SetReadRegCommand(FLEXSPI_SLV_Type *base, uint16_t command, uint16_t dummyCycle)
{
    base->READ_REGISTER_COMMAND0 = FLEXSPI_SLV_READ_REGISTER_COMMAND0_COMMANDSET(command) |
                                   FLEXSPI_SLV_READ_REGISTER_COMMAND0_DUMMYCYCLES(dummyCycle);
}

/*!
 * @brief Sets the write register command.
 *
 * @param base FLEXSPI FOLLOWER peripheral base address.
 * @param command The write register command value.
 */
static inline void FLEXSPI_SLV_SetWriteRegCommand(FLEXSPI_SLV_Type *base, uint32_t command)
{
    base->WRITE_REGISTER_COMMAND0 = FLEXSPI_SLV_WRITE_REGISTER_COMMAND0_COMMANDSET(command);
}

/*! @} */

/*!
 * @name Transactional
 * @{
 */

/*!
 * @brief Initializes the FLEXSPI FOLLOWER handle which is used in transactional functions.
 *
 * @param base FLEXSPI FOLLOWER peripheral base address.
 * @param handle Pointer to flexspi_slv_handle_t structure to store the interrupt state.
 * @param callback Pointer to user callback function.
 * @param interruptMask Interrupt mask to enable during handle creation. Use enumeration values ORed.
 */
void FLEXSPI_SLV_InterruptCreateHandle(FLEXSPI_SLV_Type *base,
                                       flexspi_slv_handle_t *handle,
                                       flexspi_slv_callback_t callback,
                                       uint32_t interruptMask);

/*!
 * @brief Master interrupt handler.
 *
 * @param base FLEXSPI FOLLOWER peripheral base address.
 * @param handle Pointer to flexspi_slv_handle_t structure.
 */
void FLEXSPI_SLV_HandleIRQ(FLEXSPI_SLV_Type *base, flexspi_slv_handle_t *handle);
/*! @} */

#if defined(__cplusplus)
}
#endif /*_cplusplus. */
/*@}*/

#endif /* FSL_FLEXSPI_FLR_H_ */
