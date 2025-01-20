/*
 * Copyright 2022 NXP.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_gpdma.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.pn_gpdma"
#endif

/** @brief The control register is invalid. */
#define GPDMA_INVALID_CTRL 0xFFFFFFFFUL

/* Timeout setting wait for GPDMA register status change. */
#ifndef GPDMA_WAIT_STATUS_TIMEOUT
#define GPDMA_WAIT_STATUS_TIMEOUT 256U
#endif

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
static uint32_t GPDMA_GetInstance(GPDMA_Type *base);
/*
 * brief Make the CTRL register value
 *
 * param srcBurstSize source address offset.
 * param srcTransferWidth Source data trasnfer size every time.
 * param destBurstSize destination address offset.
 * param destTransferWidth Destination data trasnfer size every time.
 * param totalBytes GPDMA transfer bytes to be transferred.
 * param transferType GPDMA transfer type.
 * param enableInt Enable interrupt when this descriptor finished.
 */
static uint32_t GPDMA_MakeCtrlWord(gpdma_burst_size_t srcBurstSize,
                                   gpdma_transfer_width_t srcTransferWidth,
                                   gpdma_burst_size_t destBurstSize,
                                   gpdma_transfer_width_t destTransferWidth,
                                   uint32_t totalBytes,
                                   gpdma_transfer_type_t transferType,
                                   bool enableInt);

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*! @brief Array to map GPDMA instance number to base pointer. */
static GPDMA_Type *const s_gpdmaBases[] = GPDMA_BASE_PTRS;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/*! @brief Array to map GPDMA instance number to clock name. */
static const clock_ip_name_t s_gpdmaClockName[] = GPDMA_CLOCKS;
#endif

/*! @brief Pointers to transfer handle for each GPDMA channel. */
static gpdma_handle_t *s_GPDMAHandle[FSL_FEATURE_GPDMA_MODULE_MAX_CHANNEL];

/*******************************************************************************
 * Code
 ******************************************************************************/

static uint32_t GPDMA_GetInstance(GPDMA_Type *base)
{
    uint32_t instance;

    /* Find the instance index from base address mappings. */
    for (instance = 0U; instance < ARRAY_SIZE(s_gpdmaBases); instance++)
    {
        if (MSDK_REG_SECURE_ADDR(s_gpdmaBases[instance]) == MSDK_REG_SECURE_ADDR(base))
        {
            break;
        }
    }

    assert(instance < ARRAY_SIZE(s_gpdmaBases));

    return instance;
}

/*
 * brief Make the CTRL register value
 *
 * param srcBurstSize source address offset.
 * param srcTransferWidth Source data trasnfer size every time.
 * param destBurstSize destination address offset.
 * param destTransferWidth Destination data trasnfer size every time.
 * param totalBytes GPDMA transfer bytes to be transferred.
 * param transferType GPDMA transfer type.
 * param enableInt Enable interrupt when this descriptor finished.
 */
static uint32_t GPDMA_MakeCtrlWord(gpdma_burst_size_t srcBurstSize,
                                   gpdma_transfer_width_t srcTransferWidth,
                                   gpdma_burst_size_t destBurstSize,
                                   gpdma_transfer_width_t destTransferWidth,
                                   uint32_t totalBytes,
                                   gpdma_transfer_type_t transferType,
                                   bool enableInt)
{
    uint32_t ctrlWrod = 0U;

    ctrlWrod = GPDMA_CONTROL_TRANSFERSIZE(totalBytes >> (uint32_t)srcTransferWidth)          /* Number of transfer  */
               | GPDMA_CONTROL_SBSIZE(srcBurstSize) | GPDMA_CONTROL_SWIDTH(srcTransferWidth) /* Source */
               | GPDMA_CONTROL_DBSIZE(destBurstSize) | GPDMA_CONTROL_DWIDTH(destTransferWidth);

    if (enableInt)
    {
        ctrlWrod |= GPDMA_CONTROL_I_MASK;
    }

    switch (transferType)
    {
        /* Memory to memory */
        case kGPDMA_TransferM2MControllerDma:
            ctrlWrod |= (GPDMA_CONTROL_SI_MASK | GPDMA_CONTROL_DI_MASK);
            break;

        case kGPDMA_TransferP2MControllerDma:
        case kGPDMA_TransferP2MControllerPeripheral:
            ctrlWrod |= (GPDMA_CONTROL_S_MASK | GPDMA_CONTROL_DI_MASK);
            break;

        case kGPDMA_TransferM2PControllerDma:
        case kGPDMA_TransferM2PControllerPeripheral:
            ctrlWrod |= (GPDMA_CONTROL_D_MASK | GPDMA_CONTROL_SI_MASK);
            break;

        case kGPDMA_TransferP2PControllerDma:
        case kGPDMA_TransferP2PControllerDestPeripheral:
        case kGPDMA_TransferP2PControllerSrcPeripheral:
            ctrlWrod |= (GPDMA_CONTROL_S_MASK | GPDMA_CONTROL_D_MASK);
            break;

        default:
            ctrlWrod = GPDMA_INVALID_CTRL;
            break;
    }

    return ctrlWrod;
}

/*!
 * brief Initializes the GPDMA peripheral.
 *
 * param base GPDMA peripheral base address.
 */
status_t GPDMA_Init(GPDMA_Type *base)
{
    uint32_t i      = 0U;
    status_t status = kStatus_Success;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Enable GPDMA clock */
    CLOCK_EnableClock(s_gpdmaClockName[GPDMA_GetInstance(base)]);
#endif

    /* Reset all channel configuration register */
    for (i = (uint8_t)FSL_FEATURE_GPDMA_MODULE_MAX_CHANNEL; i > 0U; i--)
    {
        base->DMACC[i - 1U].CONFIGURATION = 0U;
    }

    /* Clear all GPDMA interrupt and error flag */
    base->INTTCCLEAR = GPDMA_INTTCCLEAR_INTTCCLEAR_MASK;
    base->INTERRCLR  = GPDMA_INTERRCLR_INTERRCLR_MASK;

    /* Clear pending & enable NVIC for GPDMA */
    NVIC_ClearPendingIRQ(GPDMA_IRQn);
    NVIC_EnableIRQ(GPDMA_IRQn);

    /* Enable GPDMA channels, little endian */
    base->CONFIGURATION = GPDMA_CONFIGURATION_E_MASK;

    i = GPDMA_WAIT_STATUS_TIMEOUT;

    while (0UL == (base->CONFIGURATION & GPDMA_CONFIGURATION_E_MASK))
    {
        if (--i == 0U)
        {
            break;
        }
    }

    if (0U == i)
    {
        status = kStatus_Timeout;
    }

    return status;
}

/*!
 * brief Deinitializes the GPDMA peripheral.
 *
 * param base GPDMA peripheral base address.
 */
void GPDMA_Deinit(GPDMA_Type *base)
{
    uint8_t ch;

    for (ch = 0U; ch < (uint8_t)FSL_FEATURE_GPDMA_MODULE_MAX_CHANNEL; ch++)
    {
        GPDMA_StopChannel(base, ch);
    }

    /* Clear pending & disable NVIC for GPDMA */
    NVIC_ClearPendingIRQ(GPDMA_IRQn);
    NVIC_DisableIRQ(GPDMA_IRQn);

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* disable GPDMA clock as it saves power */
    CLOCK_DisableClock(s_gpdmaClockName[GPDMA_GetInstance(base)]);
#endif
}

/**
 * brief Enable or Disable the GPDMA Channel
 *
 * param base Base address of GPDMA module
 * param channel The GPDMA channel (0 to 7)
 * param enable true to enable GPDMA or false to disable GPDMA channel
 */
void GPDMA_EnableChannel(GPDMA_Type *base, uint8_t channel, bool enable)
{
    assert(channel < (uint8_t)FSL_FEATURE_GPDMA_MODULE_MAX_CHANNEL);
    uint32_t i;

    if (enable == true)
    {
        base->DMACC[channel].CONFIGURATION &= ~GPDMA_CONFIGURATION_H_MASK;
        base->DMACC[channel].CONFIGURATION |= GPDMA_CONFIGURATION_E_MASK;
    }
    else
    {
        /* Halt the channel, not to receive any new requests */
        base->DMACC[channel].CONFIGURATION |= GPDMA_CONFIGURATION_H_MASK;

        i = GPDMA_WAIT_STATUS_TIMEOUT;
        /* Check if Active bit is set, wait for channel FIFO empty */
        while (0UL != (base->DMACC[channel].CONFIGURATION & GPDMA_CONFIGURATION_A_MASK))
        {
            if (--i == 0U)
            {
                break;
            }
        }

        /* Disable the channel */
        base->DMACC[channel].CONFIGURATION &= ~GPDMA_CONFIGURATION_E_MASK;
    }
}

/**
 * brief Stop a stream GPDMA transfer.
 *
 * param base Base address of GPDMA module.
 * param channel The GPDMA channel (0 to 7).
 */
void GPDMA_StopChannel(GPDMA_Type *base, uint8_t channel)
{
    assert(channel < (uint8_t)FSL_FEATURE_GPDMA_MODULE_MAX_CHANNEL);

    /* Disable channel interrupt */
    GPDMA_DisableChannelInterrupts(base, channel);

    GPDMA_EnableChannel(base, channel, false);

    /* Clear the status. */
    GPDMA_ClearChannelStatus(base, channel, kGPDMA_StatusClearInterruptTerminalCountRequest);
    GPDMA_ClearChannelStatus(base, channel, kGPDMA_StatusClearInterruptError);
}

/**
 * brief The GPDMA stream interrupt status checking.
 *
 * param base Base address of GPDMA module.
 * param channel The GPDMA channel (0 to 7).
 * return status: kStatus_Success It means succeed.
 *                kStatus_Fail It means failed.
 */
status_t GPDMA_CheckChannelInterrupts(GPDMA_Type *base, uint8_t channel)
{
    assert(channel < (uint8_t)FSL_FEATURE_GPDMA_MODULE_MAX_CHANNEL);

    if (GPDMA_GetChannelStatus(base, channel, kGPDMA_StatusInterrupt))
    {
        /* Check counter terminal status */
        if (GPDMA_GetChannelStatus(base, channel, kGPDMA_StatusInterruptTerminalCountRequest))
        {
            /* Clear terminate counter Interrupt pending */
            GPDMA_ClearChannelStatus(base, channel, kGPDMA_StatusClearInterruptTerminalCountRequest);
            return kStatus_Success;
        }

        /* Check error terminal status */
        if (GPDMA_GetChannelStatus(base, channel, kGPDMA_StatusInterruptError))
        {
            /* Clear error counter Interrupt pending */
            GPDMA_ClearChannelStatus(base, channel, kGPDMA_StatusClearInterruptError);
            return kStatus_Fail;
        }
    }

    return kStatus_Fail;
}

/**
 * brief Read the status from different registers according to the flag.
 *
 * param base Base address of GPDMA module.
 * param channel The GPDMA channel (0 to 7).
 * param flag The GPDMA interrupt flag.
 * return status: true It means flag is set.
 *                false It means flag is not set.
 */
bool GPDMA_GetChannelStatus(GPDMA_Type *base, uint8_t channel, gpdma_status_t flag)
{
    assert(channel < (uint8_t)FSL_FEATURE_GPDMA_MODULE_MAX_CHANNEL);

    uint32_t status          = 0UL;
    const uint32_t chBitMask = ((1UL << channel) & 0xFFUL);

    switch (flag)
    {
        case kGPDMA_StatusInterrupt: /* check status of GPDMA channel interrupts */
            status = (base->INTSTATUS & chBitMask);
            break;

        case kGPDMA_StatusInterruptTerminalCountRequest: /* check terminal count interrupt request status for GPDMA */
            status = (base->INTTCSTATUS & chBitMask);
            break;

        case kGPDMA_StatusInterruptError: /* check interrupt status for GPDMA channels */
            status = (base->INTERRORSTATUS & chBitMask);
            break;

        case kGPDMA_StatusRawInterruptTerminalCount: /* check status of the terminal count interrupt for GPDMA channels
                                                      */
            status = (base->RAWINTTCSTATUS & chBitMask);
            break;

        case kGPDMA_StatusRawErrorInterrupt: /* check status of the error interrupt for GPDMA channels */
            status = (base->RAWINTERRORSTATUS & chBitMask);
            break;

        case kGPDMA_StatusEnabledChannel:
            status = (base->ENBLDCHNS & chBitMask);
            break;

        default:
            /* Empty for MISRA. */
            break;
    }

    return (status != 0UL);
}

/**
 * brief Clear the Interrupt status from different registers according to the flag.
 *
 * param base Base address of GPDMA module.
 * param channel The GPDMA channel (0 to 7).
 * param flag The GPDMA nterrupt flag.
 */
void GPDMA_ClearChannelStatus(GPDMA_Type *base, uint8_t channel, gpdma_status_clear_t flag)
{
    assert(channel < (uint8_t)FSL_FEATURE_GPDMA_MODULE_MAX_CHANNEL);

    if (flag == kGPDMA_StatusClearInterruptTerminalCountRequest)
    {
        /* clears the terminal count interrupt request on GPDMA channel */
        base->INTTCCLEAR = ((1UL << (channel)) & 0xFFUL);
    }
    else
    {
        /* clear the error interrupt request */
        base->INTERRCLR = ((1UL << (channel)) & 0xFFUL);
    }
}

/*!
 * brief Prepares the GPDMA transfer descriptor.
 *
 * param descriptor The transfer descriptor.
 * param srcAddr GPDMA transfer source address.
 * param srcBurstSize source address offset.
 * param srcTransferWidth Source data trasnfer size every time.
 * param destAddr GPDMA transfer destination address.
 * param destBurstSize destination address offset.
 * param destTransferWidth Destination data trasnfer size every time.
 * param totalBytes GPDMA transfer bytes to be transferred.
 * param transferType GPDMA transfer type.
 * param linkListItem Pointer to next transfer descriptor.
 */
status_t GPDMA_PrepareDescriptor(gpdma_descriptor_t *descriptor,
                                 void *srcAddr,
                                 gpdma_burst_size_t srcBurstSize,
                                 gpdma_transfer_width_t srcTransferWidth,
                                 void *destAddr,
                                 gpdma_burst_size_t destBurstSize,
                                 gpdma_transfer_width_t destTransferWidth,
                                 uint32_t totalBytes,
                                 gpdma_transfer_type_t transferType,
                                 uint32_t linkListItem)
{
    assert(descriptor != NULL);
    uint32_t ctrlWrod;

    ctrlWrod = GPDMA_MakeCtrlWord(srcBurstSize, srcTransferWidth, destBurstSize, destTransferWidth, totalBytes,
                                  transferType, (linkListItem == 0UL));

    if (GPDMA_INVALID_CTRL == ctrlWrod)
    {
        return kStatus_InvalidArgument;
    }

    descriptor->srcAddr  = (uint32_t)(uintptr_t)(uint8_t *)srcAddr;
    descriptor->destAddr = (uint32_t)(uintptr_t)(uint8_t *)destAddr;
    descriptor->lli      = linkListItem;
    descriptor->control  = ctrlWrod;

    return kStatus_Success;
}

/*!
 * brief Prepares the GPDMA transfer structure configurations.
 *
 * param config The user configuration structure of type.
 * param srcAddr GPDMA transfer source address.
 * param srcBurstSize source address offset.
 * param srcTransferWidth Source data trasnfer size every time.
 * param destAddr GPDMA transfer destination address.
 * param destBurstSize destination address offset.
 * param destTransferWidth Destination data trasnfer size every time.
 * param totalBytes GPDMA transfer bytes to be transferred.
 * param transferType GPDMA transfer type.
 * param linkListItem Pointer to next transfer descriptor.
 */
void GPDMA_PrepareTransferConfig(gpdma_transfer_config_t *config,
                                 void *srcAddr,
                                 gpdma_burst_size_t srcBurstSize,
                                 gpdma_transfer_width_t srcTransferWidth,
                                 void *destAddr,
                                 gpdma_burst_size_t destBurstSize,
                                 gpdma_transfer_width_t destTransferWidth,
                                 uint32_t totalBytes,
                                 gpdma_transfer_type_t transferType,
                                 uint32_t linkListItem)
{
    config->srcAddr           = (uint32_t)(uintptr_t)(uint8_t *)srcAddr;
    config->destAddr          = (uint32_t)(uintptr_t)(uint8_t *)destAddr;
    config->srcBurstSize      = srcBurstSize;
    config->destBurstSize     = destBurstSize;
    config->srcTransferWidth  = srcTransferWidth;
    config->destTransferWidth = destTransferWidth;
    config->totalBytes        = totalBytes;
    config->transferType      = transferType;
    config->linkListItem      = linkListItem;
}

/*!
 * brief Configures the GPDMA transfer attribute.
 *
 * param base GPDMA peripheral base address.
 * param channel The GPDMA channel (0 to 7).
 * param config Pointer to GPDMA transfer configuration structure.
 */
status_t GPDMA_SetTransferConfig(GPDMA_Type *base, uint8_t channel, const gpdma_transfer_config_t *config)
{
    assert(channel < (uint8_t)FSL_FEATURE_GPDMA_MODULE_MAX_CHANNEL);
    assert(config != NULL);
    uint32_t ctrlWrod;

    if (0UL != (base->ENBLDCHNS & ((1UL << channel) & GPDMA_ENBLDCHNS_ENABLEDCHANNELS_MASK)))
    {
        /* This channel is enabled, need to release this channel first */
        return kStatus_Busy;
    }

    /* When link list enabled, only generate interrupt with
     * last trasnfer descriptor done.
     */
    ctrlWrod = GPDMA_MakeCtrlWord(config->srcBurstSize, config->srcTransferWidth, config->destBurstSize,
                                  config->destTransferWidth, config->totalBytes, config->transferType,
                                  (config->linkListItem == 0UL));

    if (GPDMA_INVALID_CTRL == ctrlWrod)
    {
        return kStatus_InvalidArgument;
    }

    /* Reset the Interrupt status */
    base->INTTCCLEAR = (((1UL << channel) & 0xFFUL));
    base->INTERRCLR  = (((1UL << channel) & 0xFFUL));

    /* Assign Linker List Item value */
    base->DMACC[channel].LLI = config->linkListItem;

    base->DMACC[channel].SRCADDR  = config->srcAddr;
    base->DMACC[channel].DESTADDR = config->destAddr;

    /* Configure GPDMA Channel, enable Error Counter and Terminate counter */
    base->DMACC[channel].CONFIGURATION = (base->DMACC[channel].CONFIGURATION & (~GPDMA_CONFIGURATION_FLOWCNTRL_MASK)) |
                                         GPDMA_CONFIGURATION_IE_MASK | GPDMA_CONFIGURATION_ITC_MASK |
                                         GPDMA_CONFIGURATION_FLOWCNTRL(config->transferType);

    base->DMACC[channel].CONTROL = ctrlWrod;

    return kStatus_Success;
}

/**
 * brief Get a free GPDMA channel.
 *
 * param base Base address of GPDMA module.
 * return The channel number which is selected in case of success (0 to 7).
 * return Maximum channel number (8) in case channel is not available.
 */
uint8_t GPDMA_GetFreeChannel(GPDMA_Type *base)
{
    uint8_t ch = 0U;

    for (ch = 0U; ch < (uint8_t)FSL_FEATURE_GPDMA_MODULE_MAX_CHANNEL; ch++)
    {
        if (0UL != (base->ENBLDCHNS & ((1UL << ch) & 0xFFUL)))
        {
            break;
        }
    }

    return ch;
}

/*!
 * brief Creates the GPDMA handle.
 *
 * param handle GPDMA handle pointer. The GPDMA handle stores callback function and
 *               parameters.
 * param base GPDMA peripheral base address.
 * param channel The GPDMA channel (0 to 7).
 */
void GPDMA_CreateHandle(gpdma_handle_t *handle, GPDMA_Type *base, uint8_t channel)
{
    assert(handle != NULL);
    assert(channel < (uint8_t)FSL_FEATURE_GPDMA_MODULE_MAX_CHANNEL);

    /* Zero the handle */
    (void)memset(handle, 0, sizeof(*handle));

    handle->base    = base;
    handle->channel = channel;

    s_GPDMAHandle[channel] = handle;
}

/*!
 * brief Installs a callback function for the GPDMA transfer.
 *
 * param handle GPDMA handle pointer.
 * param callback GPDMA callback function pointer.
 * param userData A parameter for the callback function.
 */
void GPDMA_SetCallback(gpdma_handle_t *handle, gpdma_callback callback, void *userData)
{
    assert(handle != NULL);

    handle->callback = callback;
    handle->userData = userData;
}

/*!
 * brief Submits the GPDMA transfer request.
 *
 * param handle GPDMA handle pointer.
 * param config Pointer to GPDMA transfer configuration structure.
 */
status_t GPDMA_SubmitTransfer(gpdma_handle_t *handle, const gpdma_transfer_config_t *config)
{
    assert(handle != NULL);
    assert(config != NULL);

    return GPDMA_SetTransferConfig(handle->base, handle->channel, config);
}

/*!
 * brief Abort running transfer by handle.
 *
 * This function aborts GPDMA transfer specified by handle.
 *
 * param handle GPDMA handle pointer.
 */
void GPDMA_AbortTransfer(gpdma_handle_t *handle)
{
    assert(NULL != handle);

    GPDMA_StopChannel(handle->base, handle->channel);
}

/*!
 * brief GPDMA start transfer.
 *
 * User can call this function after GPDMA_SubmitTransfer.
 *
 * param handle GPDMA handle pointer.
 */
void GPDMA_StartTransfer(gpdma_handle_t *handle)
{
    assert(NULL != handle);

    GPDMA_EnableChannel(handle->base, handle->channel, true);
}

void GPDMA_HandleIRQ(GPDMA_Type *base)
{
    uint8_t channel;
    gpdma_handle_t *handle;

    /* Check Interrupt for all the GPDMA channels */
    for (channel = 0U; channel < (uint8_t)FSL_FEATURE_GPDMA_MODULE_MAX_CHANNEL; channel++)
    {
        handle = s_GPDMAHandle[channel];

        if (NULL == handle)
        {
            continue;
        }

        if (GPDMA_GetChannelStatus(base, channel, kGPDMA_StatusInterrupt))
        {
            /* Check counter terminal status */
            if (GPDMA_GetChannelStatus(base, channel, kGPDMA_StatusInterruptTerminalCountRequest))
            {
                /* Clear terminate counter Interrupt pending */
                GPDMA_ClearChannelStatus(base, channel, kGPDMA_StatusClearInterruptTerminalCountRequest);

                /* Execute callback function for the chnannel */
                if (handle->callback != NULL)
                {
                    (handle->callback)(handle, handle->userData, (uint32_t)kGPDMA_StatusInterruptTerminalCountRequest);
                }
            }

            /* Check error terminal status */
            if (GPDMA_GetChannelStatus(base, channel, kGPDMA_StatusInterruptError))
            {
                /* Clear error counter Interrupt pending */
                GPDMA_ClearChannelStatus(base, channel, kGPDMA_StatusClearInterruptError);

                /* Execute callback function for the chnannel */
                if (handle->callback != NULL)
                {
                    (handle->callback)(handle, handle->userData, (uint32_t)kGPDMA_StatusInterruptError);
                }
            }
        }
    }
}

void GPDMA_DriverIRQHandler(void);
void GPDMA_DriverIRQHandler(void)
{
    GPDMA_HandleIRQ(GPDMA);

    SDK_ISR_EXIT_BARRIER;
}
