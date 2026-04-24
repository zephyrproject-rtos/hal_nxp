/*
 * Copyright 2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_espi.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.espi"
#endif

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*! @brief Pointers to eSPI bases for each instance. */
static ESPI_Type *const s_espiBases[] = ESPI_BASE_PTRS;

/*! @brief Pointers to eSPI handles for each instance. */
static espi_handle_t *s_espiHandle[ARRAY_SIZE(s_espiBases)];

/*! @brief Pointers to eSPI IRQ number for each instance. */
static const IRQn_Type s_espiIRQ[] = ESPI_IRQS;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/*! @brief Pointers to eSPI clocks for each instance. */
static const clock_ip_name_t s_espiClocks[] = ESPI_CLOCKS;
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

#if defined(ESPI_RSTS)
/*! @brief Reset array. */
static const reset_ip_name_t s_espiResets[] = ESPI_RSTS;
#endif

/*******************************************************************************
 * Code
 ******************************************************************************/

/*!
 * @brief Gets eSPI instance index from base address.
 *
 * @param base eSPI peripheral base address.
 * @return Instance index into `s_espiBases`.
 */
static uint32_t ESPI_GetInstance(ESPI_Type *base)
{
    uint32_t instance;

    /* Find the instance index from base address mappings. */
    for (instance = 0; instance < ARRAY_SIZE(s_espiBases); instance++)
    {
        if (s_espiBases[instance] == base)
        {
            break;
        }
    }

    assert(instance < ARRAY_SIZE(s_espiBases));

    return instance;
}

/*!
 * brief Initializes the eSPI peripheral.
 *
 * Enables the eSPI clock and configures the eSPI peripheral according to
 * the configuration structure.
 *
 * param base eSPI peripheral base address.
 * param config Pointer to the configuration structure.
 */
void ESPI_Init(ESPI_Type *base, const espi_config_t *config)
{
    assert(config != NULL);
    assert(config->portCount <= ESPI_PORT_COUNT);
    assert((config->ramBaseAddr & (~ESPI_RAMBASE_RAM_MASK)) == 0U);

    uint32_t instance = ESPI_GetInstance(base);

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Enable the eSPI clock. */
    CLOCK_EnableClock(s_espiClocks[instance]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

#if defined(ESPI_RSTS)
    /* Reset the eSPI peripheral. */
    RESET_PeripheralReset(s_espiResets[instance]);
#endif

    /* Set RAM base address. */
    base->RAMBASE = config->ramBaseAddr;

    /* Set BASE0 and BASE1 address. */
    base->MAPBASE = ESPI_MAPBASE_BASE0(config->base0Addr) | ESPI_MAPBASE_BASE1(config->base1Addr);

    /* Configure eSPI capabilities. */
    uint32_t value = ESPI_ESPICAP_SPICAP(config->spiMode) | ESPI_ESPICAP_MAXSPD(config->busSpeed) |
                     ESPI_ESPICAP_TRGT_REQ_SIZE_SUPP(config->maxSAFRxReqSize) |
                     ESPI_ESPICAP_MEMMX(config->maxPayloadSize) | (config->enableAlertPin ? ESPI_ESPICAP_ALPIN_MASK : 0U);

    if (config->enableSAF)
    {
        value |= ESPI_ESPICAP_SAF_MASK | ESPI_ESPICAP_SAFERA(config->SAFEraseSize) |
                 ESPI_ESPICAP_FLASHMX(config->maxFlashPayloadSize);
    }

    if (config->enableOOB)
    {
        value |= ESPI_ESPICAP_OOBOK_MASK | ESPI_ESPICAP_OOBMX(config->maxOOBPayloadSize);
    }
    base->ESPICAP = value;

    value = 0U;
    if ((config->portConfig != NULL) && (config->portCount > 0U))
    {
        for (uint32_t i = 0; i < config->portCount; i++)
        {
            const espi_port_config_t *pCfg = &config->portConfig[i];
            base->PORT[i].CFG    = ESPI_CFG_TYPE(pCfg->type) | ESPI_CFG_DIRECTION(pCfg->direction);
            base->PORT[i].RAMUSE = ESPI_RAMUSE_OFF(pCfg->ramOffset) | ESPI_RAMUSE_LEN(pCfg->ramSize);
            base->PORT[i].ADDR   = ESPI_ADDR_OFF(pCfg->addrOffset) | ESPI_ADDR_BASE_ASZ(pCfg->addrBase) |
                                 ESPI_ADDR_IDXOFF(pCfg->idxOffset);
            value |= (1UL << i);
        }
    }

    base->MCTRL = ESPI_MCTRL_PENA(value) | ESPI_MCTRL_ENABLE(config->enableMode) |
                  (config->enableP80 ? ESPI_MCTRL_P80ENA_MASK : 0U) | ESPI_MCTRL_CLK_DIV_DISABLE(1U);
}

/*!
 * brief Deinitializes the eSPI peripheral.
 *
 * Disables the eSPI peripheral and gates the eSPI clock.
 *
 * param base eSPI peripheral base address.
 */
void ESPI_Deinit(ESPI_Type *base)
{
    /* Disable eSPI controller. */
    base->MCTRL &= ~ESPI_MCTRL_ENABLE_MASK;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    uint32_t instance = ESPI_GetInstance(base);
    CLOCK_DisableClock(s_espiClocks[instance]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

/*!
 * brief Gets the default configuration structure.
 *
 * Initializes the eSPI configuration structure to default values.
 *
 * param config Pointer to the configuration structure.
 */
void ESPI_GetDefaultConfig(espi_config_t *config)
{
    assert(config != NULL);

    (void)memset(config, 0, sizeof(*config));

    config->enableMode          = (uint8_t)kESPI_EnableESPI;
    config->spiMode             = (uint8_t)kESPI_SPIMode_All;
    config->busSpeed            = (uint8_t)kESPI_MaxSpeed66MHz;
    config->enableSAF           = false;
    config->enableOOB           = false;
    config->enableP80           = false;
    config->maxSAFRxReqSize     = (uint8_t)kESPI_ReadReq4096B;
    config->maxPayloadSize      = (uint8_t)kESPI_MemMax256B;
    config->maxFlashPayloadSize = (uint8_t)kESPI_FlashMax512B;
    config->maxOOBPayloadSize   = (uint8_t)kESPI_OOBMax256B;
}

/*!
 * brief Gets Port 80 status and POST codes.
 *
 * This function reads the Port 80 status register and extracts the current POST code,
 * previous POST code, and counter value.
 *
 * param base eSPI peripheral base address.
 * param status Pointer to structure to receive Port 80 status.
 * retval kStatus_Success Successfully read Port 80 status.
 * retval kStatus_Fail Port 80 is not enabled.
 */
status_t ESPI_GetPort80Status(ESPI_Type *base, espi_p80_status_t *status)
{
    assert(status != NULL);

    uint32_t p80Stat;

    /* Check if Port80 is enabled */
    if ((base->MCTRL & ESPI_MCTRL_P80ENA_MASK) == 0U)
    {
        return kStatus_Fail;
    }

    p80Stat              = base->P80STAT;
    status->currentCode  = (uint8_t)((p80Stat & ESPI_P80STAT_CURR_MASK) >> ESPI_P80STAT_CURR_SHIFT);
    status->previousCode = (uint8_t)((p80Stat & ESPI_P80STAT_PREV_MASK) >> ESPI_P80STAT_PREV_SHIFT);
    status->counter      = (uint8_t)((p80Stat & ESPI_P80STAT_CNT_MASK) >> ESPI_P80STAT_CNT_SHIFT);

    return kStatus_Success;
}

/*!
 * brief Sends a virtual wire message.
 *
 * param base eSPI peripheral base address.
 * param flag Virtual wire flag to send, see ref espi_vw_wr_flags_t.
 * param value Value to set for the wire.
 * retval kStatus_Success Operation completed.
 * retval kStatus_Busy Previous write still pending.
 */
status_t ESPI_SendVWire(ESPI_Type *base, espi_vw_wr_flags_t flag, uint32_t value)
{
    /* If previous write is still pending, return busy so caller can retry. */
    if ((base->WIREWO & ESPI_WIREWO_DONE_MASK) == 0U)
    {
        return kStatus_Busy;
    }
    else
    {
        uint32_t reg = (base->WIREWO & ~((uint32_t)flag));
        if (flag == kESPI_VWireWr_E2P)
        {
            assert(value <= ESPI_WIREWO_E2P_MASK);
            reg |= ESPI_WIREWO_E2P(value);
        }
        else
        {
            assert(value <= 1U);
            reg = (value == 0U) ? (reg & ~(uint32_t)flag) : (reg | (uint32_t)flag);
        }
        base->WIREWO = reg;
        return kStatus_Success;
    }
}

/*!
 * brief Gets endpoint data fields from a port.
 *
 * This function reads PnDATAIN and extracts the IDX field and DATA_LEN field.
 *
 * param base eSPI peripheral base address.
 * param port eSPI port index.
 * param idx Pointer to store the extracted IDX field.
 * param data Pointer to store the extracted DATA_LEN field.
 */
void ESPI_GetEndpointData(ESPI_Type *base, uint32_t port, uint32_t *idx, uint32_t *data)
{
    assert((idx != NULL) && (data != NULL));

    uint32_t datain = base->PORT[port].DATAIN;

    *idx  = (datain & ESPI_DATAIN_IDX_MASK) >> ESPI_DATAIN_IDX_SHIFT;
    *data = (datain & ESPI_DATAIN_DATA_LEN_MASK) >> ESPI_DATAIN_DATA_LEN_SHIFT;
}

/*!
 * brief Checks port error status.
 *
 * Reads and interprets the error bits (ERR0-ERR3) from PnSTAT register.
 * Returns a specific error code based on the port type.
 *
 * Error bit interpretation depends on port type.
 *
 * param base eSPI peripheral base address.
 * param port Port number to check.
 * param pstat Port status from PnSTAT register.
 * param error Pointer to structure to receive error information.
 *
 * note Error status bits are read-only and automatically cleared by hardware
 *       when the error condition is resolved.
 * note Only returns the first error found (priority: ERR0 > ERR1 > ERR2 > ERR3).
 */
void ESPI_GetPortErrorStatus(ESPI_Type *base, uint32_t port, uint32_t pstat, espi_port_error_t *error)
{
    assert(port < ESPI_PORT_COUNT);
    assert(error != NULL);

    bool err0 = ((pstat & ESPI_STAT_ERR0_MASK) != 0U);
    bool err1 = ((pstat & ESPI_STAT_ERR1_MASK) != 0U);
    bool err2 = ((pstat & ESPI_STAT_ERR2_MASK) != 0U);
    bool err3 = ((pstat & ESPI_STAT_ERR3_MASK) != 0U);

    *error = kESPI_PortError_None;

    /* Map error bits to specific error codes based on port type */
    switch (ESPI_GetPortType(base, port))
    {
        case kESPI_PortType_ACPIEndpoint:
        case kESPI_PortType_ACPIIndexData:
            /* Check errors in priority order */
            if (err0)
            {
                *error = kESPI_PortError_EndpointWriteOverrun;
            }
            else if (err1)
            {
                *error = kESPI_PortError_EndpointReadEmpty;
            }
            else if (err2)
            {
                *error = kESPI_PortError_EndpointInvalidSize;
            }
            else
            {
                /* Intentional empty. */
            }
            break;

        case kESPI_PortType_MailboxShared:
        case kESPI_PortType_MailboxSingle:
        case kESPI_PortType_MailboxSplit:
        case kESPI_PortType_MailboxOOBSplit:
            if (err0)
            {
                *error = kESPI_PortError_MailboxInvalidAccess;
            }
            else if (err1)
            {
                *error = kESPI_PortError_MailboxOverrunUnderrun;
            }
            else if (err2)
            {
                *error = kESPI_PortError_MailboxSizeOverflow;
            }
            else if (err3)
            {
                *error = kESPI_PortError_MailboxRAMBusError;
            }
            else
            {
                /* Intentional empty. */
            }
            break;

        case kESPI_PortType_BusMasterMemSingle:
        case kESPI_PortType_BusMasterFlashSingle:
            if (err0)
            {
                *error = kESPI_PortError_MasterFromHostFailed;
            }
            else if (err1)
            {
                *error = kESPI_PortError_MasterOverrunUnderrun;
            }
            else if (err2)
            {
                *error = kESPI_PortError_MasterEraseFailed;
            }
            else if (err3)
            {
                *error = kESPI_PortError_MasterBusError;
            }
            else
            {
                /* Intentional empty. */
            }
            break;

        default:
            /* Unconfigured port - no errors */
            break;
    }
}

/*!
 * @brief eSPI flash IRQ handle function.
 *
 * This IRQ handler processes flash-related channel interrupts. It decodes
 * the incoming request (read/write/erase), extracts the tag/address and
 * dispatches to the corresponding helper functions that perform the
 * necessary buffer copies and status updates. It also handles host
 * completion notifications by calling ESPI_FlashHandleCompletion.
 *
 * This function executes in IRQ context; it must be fast and must not block.
 * Helper functions called from here are expected to be non-blocking or
 * perform only short operations suitable for IRQ context.
 *
 * @param base eSPI peripheral base address.
 * @param handle Pointer to the eSPI handle associated with this instance.
 * @param status Channel status flags (value returned by ESPI_GetChannelStatus).
 */
static void ESPI_HandleSAFIRQ(ESPI_Type *base, espi_handle_t *handle, uint32_t status)
{
    uint32_t dataIn = base->PORT[handle->safPort].DATAIN;
    uint32_t length = (dataIn & ESPI_DATAIN_DATA_LEN_MASK) + 1U;
    uint32_t tag    = (dataIn & 0x3C000000U) >> 26U;
    uint32_t wrstat = (status & ESPI_STAT_WRSTAT_MASK) >> ESPI_STAT_WRSTAT_SHIFT;
    uint8_t *buff = ESPI_GetPortRamBuffer(base, handle->safPort);
    espi_flash_request_t request = {0};

    if (wrstat == (uint32_t)kESPI_WRSTAT_NoRequest)
    {
        return;
    }

    request.data    = (wrstat == (uint32_t)kESPI_WRSTAT_WriteRequest) ? &buff[4] : &buff[0];
    request.type = (espi_flash_trans_type_t)wrstat;

    /* Check for read or write interrupt. */
    if ((status & ((uint32_t)kESPI_PortReadInterrupt | (uint32_t)kESPI_PortWriteInterrupt)) != 0U)
    {
        /* Get flash address from buffer (big-endian per spec). */
        uint32_t addr =
            ((uint32_t)buff[0] << 24U) | ((uint32_t)buff[1] << 16U) | ((uint32_t)buff[2] << 8U) | ((uint32_t)buff[3]);

        assert(addr >= handle->addrOffset[handle->safPort]);
        addr -= handle->addrOffset[handle->safPort];

        /* Check address range. */
        if (addr >= handle->flashSize)
        {
            ESPI_SetFlashOpLen(base, handle->safPort, (uint32_t)kESPI_OMFLEN_SAFCompletionFail, 0U);
            ESPI_SetFlashCompletion(base, handle->safPort, tag, (uint32_t)kESPI_SSTCL_SAFCompletion, (uint32_t)kESPI_SAFReadOnly);
        }
        else
        {
            /* Adjust length if it exceeds flash size. */
            if (length > (handle->flashSize - addr))
            {
                length = handle->flashSize - addr;
            }

            request.addr    = addr;
            request.length  = length;
            request.tag     = (uint8_t)tag;
            request.readStart = true;

            /* Using backend operation. */
            handle->flashOps(base, handle, &request, handle->userData);
        }
    }

    /* Handle completion interrupts */
    if ((status & ESPI_STAT_INTSPC0_MASK) != 0U)
    {
        if (wrstat == (uint32_t)kESPI_WRSTAT_ReadRequest)
        {
            request.readStart = false;

            /* Using backend operation. */
            handle->flashOps(base, handle, &request, handle->userData);
        }
    }
}

/*!
 * brief Triggers an OOB message.
 *
 * Programs the OOB payload length and triggers the message.
 *
 * param base eSPI peripheral base address.
 * param handle eSPI handle (provides OOB port index and ACK flag).
 * param length Message length in bytes.
 */
void ESPI_TriggerOOBMsg(ESPI_Type *base, espi_handle_t *handle, uint32_t length)
{
    assert(length != 0U);

    uint32_t value = (base->PORT[handle->oobPort].OMFLEN & ~ESPI_OMFLEN_LEN_MASK) | ESPI_OMFLEN_LEN(length - 1U);
    base->PORT[handle->oobPort].OMFLEN = value;

    value = (base->PORT[handle->oobPort].IRULESTAT & ~ESPI_IRULESTAT_SSTCL_MASK) |
            ESPI_IRULESTAT_SSTCL((uint32_t)kESPI_SSTCL_OOBSendComplete);
    base->PORT[handle->oobPort].IRULESTAT = value;
}

/*!
 * brief Sends an Out-of-Band (OOB) message.
 *
 * Copies `length` bytes into the OOB mailbox, triggers the OOB message.
 *
 * param base eSPI peripheral base address.
 * param handle Optional eSPI handle to arm IRQ-driven ACK handling.
 * param data Pointer to data to send.
 * param length Number of bytes to send (>0).
 * param announce If true, set SSTCL to "Started by MCU" before copy.
 * retval kStatus_Success Message accepted and triggered.
 * retval kStatus_InvalidArgument Invalid argument.
 */
status_t ESPI_SendOOB(ESPI_Type *base, espi_handle_t *handle, const uint8_t *data, uint32_t length, bool announce)
{
    assert(data != NULL);
    assert(length != 0U);

    uint32_t mbSize = ESPI_GetPortMailboxSize(base, handle->oobPort);
    uint8_t *buffer;

    if (length > mbSize)
    {
        return kStatus_InvalidArgument;
    }

    /* If requested, announce start (SSTCL = 1) before preparing data. This
     * allows host-side drivers that react to "Started by MCU" to prepare
     * (e.g. allocate DMA) before the MCU sets completion.
     */
    if (announce)
    {
        base->PORT[handle->oobPort].IRULESTAT =
            (base->PORT[handle->oobPort].IRULESTAT & ~ESPI_IRULESTAT_SSTCL_MASK) | ESPI_IRULESTAT_SSTCL(0x1U);
    }

    /* Get OOB memory address. */
    buffer = ESPI_GetPortRamBuffer(base, handle->oobPort);
    buffer += mbSize;
    (void)memcpy(buffer, data, length);

    /* Trigger message after arming ACK handling. */
    ESPI_TriggerOOBMsg(base, handle, length);

    return kStatus_Success;
}

/*!
 * brief Reads an Out-of-Band (OOB) message.
 *
 * Copies up to `*len` bytes from the OOB mailbox into `buffer` and updates
 * `*len` with the actual number of bytes copied.
 *
 * param base eSPI peripheral base address.
 * param handle eSPI handle.
 * param buffer Destination data buffer.
 * param len [in] Length of bytes to receive, [out] Length of actual received bytes.
 * retval kStatus_Success Operation completed.
 * retval kStatus_Fail Message truncated.
 */
status_t ESPI_ReadOOB(ESPI_Type *base, espi_handle_t *handle, uint8_t *buffer, uint32_t *len)
{
    assert(buffer != NULL);
    assert(len != NULL);

    uint32_t mailboxMax = ESPI_GetPortMailboxSize(base, handle->oobPort);
    uint8_t *oobBuf     = ESPI_GetPortRamBuffer(base, handle->oobPort);
    uint32_t msgLen     = ESPI_GetPortMsgLen(base, handle->oobPort);

    status_t result = kStatus_Success;
    uint32_t copyLen;

    /* Defensively clamp msgLen to mailboxMax. */
    msgLen  = (msgLen > mailboxMax) ? mailboxMax : msgLen;
    copyLen = (msgLen <= *len) ? msgLen : *len;
    *len    = copyLen;

    (void)memcpy(buffer, oobBuf, copyLen);

    if (copyLen < msgLen)
    {
        result = kStatus_Fail;
    }

    return result;
}

/*!
 * brief Initializes the eSPI handle.
 *
 * Initializes the eSPI handle structure for non-blocking transfers.
 *
 * param base eSPI peripheral base address.
 * param handle Pointer to the eSPI handle.
 * param config Pointer to the configuration structure.
 * param callback Pointer to callback configuration structure.
 * param userData User data.
 */
void ESPI_CreateHandle(ESPI_Type *base,
                       espi_handle_t *handle,
                       const espi_config_t *config,
                       espi_callback_config_t *callback,
                       void *userData)
{
    assert(handle != NULL);
    assert(config != NULL);

    uint32_t instance = ESPI_GetInstance(base);

    (void)memset(handle, 0, sizeof(espi_handle_t));

    handle->callback     = *callback;
    handle->userData     = userData;
    handle->oobPort      = ESPI_INVALID_PORT;
    handle->safPort      = ESPI_INVALID_PORT;
    handle->mafPort      = ESPI_INVALID_PORT;
    handle->flashOps     = NULL;
    handle->flashSize    = 0U;

    /* Discover key ports by scanning PnCFG.TYPE once. */
    for (uint8_t port = 0; port < config->portCount; port++)
    {
        espi_port_type_t type = ESPI_GetPortType(base, port);

        if (type == kESPI_PortType_MailboxOOBSplit)
        {
            handle->oobPort = port;
        }
        else if (type == kESPI_PortType_BusMasterFlashSingle)
        {
            handle->safPort = port;
        }
        else if (type == kESPI_PortType_BusMasterMemSingle)
        {
            handle->mafPort = port;
        }
        else
        {
            /* Intentional empty. */
        }

        handle->addrOffset[port] = config->portConfig[port].addrOffset;
    }

    /* Save the context in global variables to support the double weak mechanism. */
    s_espiHandle[instance] = handle;

    /* Enable interrupt in NVIC. */
    (void)EnableIRQ(s_espiIRQ[instance]);
}

/*!
 * brief Initializes the eSPI flash functionality in the handle.
 *
 * param base eSPI peripheral base address.
 * param handle Pointer to the eSPI handle.
 * param flashOps Pointer to flash backend operations.
 * param flashSize Flash address space size.
 */
void ESPI_FlashCreateHandle(
    ESPI_Type *base, espi_handle_t *handle, espi_flash_ops_t flashOps, uint32_t flashSize)
{
    assert(handle != NULL);

    handle->flashOps  = flashOps;
    handle->flashSize = flashSize;
}

/*!
 * brief Sets the flash completion status.
 *
 * Updates the completion status fields for the specified port and tag.
 *
 * param base eSPI peripheral base address.
 * param port Hardware port index.
 * param tag Transaction tag.
 * param state Transaction state.
 * param type Completion type.
 */
void ESPI_SetFlashCompletion(ESPI_Type *base, uint32_t port, uint32_t tag, uint32_t state, uint32_t type)
{
    uint32_t regValue = base->PORT[port].IRULESTAT;

    regValue &= ~(ESPI_IRULESTAT_SSTCL_MASK | ESPI_IRULESTAT_CPU_TAG_MASK | ESPI_IRULESTAT_FLASH_COMPLETION_TYPE_MASK);
    regValue |= ESPI_IRULESTAT_SSTCL(state) | ESPI_IRULESTAT_CPU_TAG(tag) | ESPI_IRULESTAT_FLASH_COMPLETION_TYPE(type);

    base->PORT[port].IRULESTAT = regValue;
}

/*!
 * brief eSPI IRQ handle function.
 *
 * Handles the eSPI transmit and receive IRQ request.
 *
 * param base eSPI peripheral base address.
 * param handle Pointer to the eSPI handle.
 */
void ESPI_TransferHandleIRQ(ESPI_Type *base, espi_handle_t *handle)
{
    assert(handle != NULL);

    uint32_t status = ESPI_GetStatusFlags(base);
    ESPI_ClearStatusFlags(base, status);

    if ((status & (uint32_t)kESPI_BusStatusFlags) != 0U)
    {
        if (handle->callback.commonCallback != NULL)
        {
            handle->callback.commonCallback(base, status, handle->userData);
        }
    }

    uint32_t portIntr = (status & (uint32_t)kESPI_PortInterruptFlag);
    if (portIntr != 0U)
    {
        for (uint32_t port = 0U; port < ESPI_PORT_COUNT; port++)
        {
            if ((portIntr & (1UL << port)) != 0U)
            {
                uint32_t portStatus = ESPI_GetPortStatus(base, port);

                ESPI_ClearPortStatus(base, port, portStatus);

                if ((handle->flashOps != NULL) && (port == handle->safPort) && (handle->safPort != ESPI_INVALID_PORT))
                {
                    ESPI_HandleSAFIRQ(base, handle, portStatus);
                }

                if (handle->callback.portCallback != NULL)
                {
                    handle->callback.portCallback(base, handle, port, portStatus, handle->userData);
                }
            }
        }
    }
}

void ESPI_DriverIRQHandler(uint32_t instance);
void ESPI_DriverIRQHandler(uint32_t instance)
{
    if (instance >= ARRAY_SIZE(s_espiBases))
    {
        return;
    }

    ESPI_Type *base       = s_espiBases[instance];
    espi_handle_t *handle = s_espiHandle[instance];

    ESPI_TransferHandleIRQ(base, handle);
    SDK_ISR_EXIT_BARRIER;
}
