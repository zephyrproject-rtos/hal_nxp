/*
 * Copyright 2021 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_dma.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.dsc_dma"
#endif

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*! @brief Array to map DMA instance number to base pointer. */
static DMA_Type *const s_dmaBases[] = DMA_BASE_PTRS;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/*! @brief Array to map DMA instance number to clock name. */
static const clock_ip_name_t s_dmaClockName[] = DMA_CLOCKS;
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

/*! @brief Array to map DMA instance number to IRQ number. */
static const IRQn_Type s_dmaIRQNumber[][FSL_FEATURE_DMA_MODULE_CHANNEL] = DMA_CHN_IRQS;

/*! @brief Pointers to transfer handle for each DMA channel. */
static dma_handle_t *s_DMAHandle[FSL_FEATURE_DMA_MODULE_CHANNEL * FSL_FEATURE_SOC_DMA_COUNT];
/*******************************************************************************
 * Code
 ******************************************************************************/
static uint32_t DMA_GetInstance(DMA_Type *base)
{
    uint32_t u32Instance;

    /* Find the instance index from base address mappings. */
    for (u32Instance = 0; u32Instance < ARRAY_SIZE(s_dmaBases); u32Instance++)
    {
        if (s_dmaBases[u32Instance] == base)
        {
            break;
        }
    }

    assert(u32Instance < ARRAY_SIZE(s_dmaBases));

    return u32Instance;
}

/*!
 * brief DMA initialization
 *
 * param base DMA peripheral base address.
 * param psConfig pointer to user's DMA configure structure, see dma_config_t for detail.
 */
void DMA_Init(DMA_Type *base, dma_config_t *psConfig)
{
    int i;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    CLOCK_EnableClock(s_dmaClockName[DMA_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

    /* channel transfer configuration */
    for (i = 0; i < FSL_FEATURE_DMA_MODULE_CHANNEL; i++)
    {
        if (psConfig->psChannelTransferConfig[i] != NULL)
        {
            DMA_SetChannelTransferConfig(base, (dma_channel_t)i, psConfig->psChannelTransferConfig[i]);
        }
    }
}

/*!
 * brief DMA De-initialization
 *
 * param base DMA peripheral base address.
 */
void DMA_Deinit(DMA_Type *base)
{
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    CLOCK_DisableClock(s_dmaClockName[DMA_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

/*!
 * brief Resets the DMA channel.
 *
 * Sets all register values to reset values and enables
 * the cycle steal and auto stop channel request features.
 *
 * param base DMA peripheral base address.
 * param eChannel DMA channel number.
 */
void DMA_ResetChannel(DMA_Type *base, dma_channel_t eChannel)
{
    assert((uint32_t)eChannel < (uint32_t)FSL_FEATURE_DMA_MODULE_CHANNEL);

    /* clear all status bit */
    base->DMA[(uint8_t)eChannel].DSR_BCR |= DMA_DSR_BCR_DONE(true);
    /* clear all registers */
    base->DMA[(uint8_t)eChannel].SAR     = 0;
    base->DMA[(uint8_t)eChannel].DAR     = 0;
    base->DMA[(uint8_t)eChannel].DSR_BCR = 0;
}

/*!
 * brief Get channel default transfer configuration.
 *
 * note 1. This function will reset all of the configuration structure members to zero firstly,
 *       then apply default configurations to the structure.
 *       2. No interrupt enabled by this function by default, if application would like to use DMA interrupt
 *          please enable it manually by psTransfer->u16EnabledInterruptMask = _dma_channel_interrupt
 *
 * param psTransfer pointer to user's DMA channel configure structure, see dma_channel_transfer_config_t for detail.
 * param u32SrcAddr source address, must be byte address.
 * param u32DstAddr destination address,  must be byte address.
 * param u32TotalBytes total bytes to be transferred.
 * param eTransferWidth, it represents how many bits are transferred in each read/write.
 * param eTransferType DMA channel transfer type.
 */
void DMA_GetChannelDefaultTransferConfig(dma_channel_transfer_config_t *psTransfer,
                                         uint32_t u32SrcAddr,
                                         uint32_t u32DstAddr,
                                         uint32_t u32TotalBytes,
                                         dma_channel_transfer_width_t eTransferWidth,
                                         dma_channel_transfer_type_t eTransferType)
{
    assert(psTransfer != NULL);
    assert(u32SrcAddr != 0UL);
    assert(u32DstAddr != 0UL);
    assert((eTransferWidth == kDMA_ChannelTransferWidth8Bits) || (eTransferWidth == kDMA_ChannelTransferWidth16Bits) ||
           (eTransferWidth == kDMA_ChannelTransferWidth32Bits));

    (void)memset(psTransfer, 0, sizeof(dma_channel_transfer_config_t));

    psTransfer->u32SrcAddr              = u32SrcAddr;
    psTransfer->u32DstAddr              = u32DstAddr;
    psTransfer->u32TransferSize         = u32TotalBytes;
    psTransfer->eSrcWidthOfEachTransfer = eTransferWidth;
    psTransfer->eDstWidthOfEachTransfer = eTransferWidth;

    if (eTransferType == kDMA_ChannelTransferMemoryToMemory)
    {
        psTransfer->eEnableSrcIncrement  = kDMA_ChannelAddressIncrement;
        psTransfer->eEnableDestIncrement = kDMA_ChannelAddressIncrement;
    }
    else if (eTransferType == kDMA_ChannelTransferPeripheralToMemory)
    {
        psTransfer->eEnableSrcIncrement  = kDMA_ChannelAddressFix;
        psTransfer->eEnableDestIncrement = kDMA_ChannelAddressIncrement;
    }
    else
    {
        psTransfer->eEnableSrcIncrement  = kDMA_ChannelAddressIncrement;
        psTransfer->eEnableDestIncrement = kDMA_ChannelAddressFix;
    }

    /* default advance channel transfer configurations */
    psTransfer->eSrcAddrModulo                  = kDMA_ChannelModuloDisable;
    psTransfer->eDstAddrModulo                  = kDMA_ChannelModuloDisable;
    psTransfer->bEnablAutoStopPeripheralRequest = false;
    psTransfer->bEnableAutoAlign                = false;
    psTransfer->bEnableCycleSteal               = false;
    psTransfer->bEnableInterrupt                = true;
}

/*!
 * brief DMA set channel transfer configurations
 *
 * param base DMA peripheral base address.
 * param eChannel DMA channel number.
 * param psTransfer pointer to user's DMA channel configure structure, see dma_channel_transfer_config_t for detail.
 */
void DMA_SetChannelTransferConfig(DMA_Type *base, dma_channel_t eChannel, dma_channel_transfer_config_t *psTransfer)
{
    assert((uint32_t)eChannel < (uint32_t)FSL_FEATURE_DMA_MODULE_CHANNEL);
    assert(psTransfer != NULL);

    uint32_t u32Tmpreg;

    DMA_ResetChannel(base, eChannel);

    /* Set source address */
    base->DMA[(uint8_t)eChannel].SAR = psTransfer->u32SrcAddr;
    /* Set destination address */
    base->DMA[(uint8_t)eChannel].DAR = psTransfer->u32DstAddr;
    /* Set transfer bytes */
    base->DMA[(uint8_t)eChannel].DSR_BCR = DMA_DSR_BCR_BCR(psTransfer->u32TransferSize);
    /* Set DMA Control Register */
    u32Tmpreg = base->DMA[(uint8_t)eChannel].DCR;
    u32Tmpreg &= ~(DMA_DCR_DSIZE_MASK | DMA_DCR_DINC_MASK | DMA_DCR_SSIZE_MASK | DMA_DCR_SINC_MASK);
    u32Tmpreg |= (DMA_DCR_DSIZE(psTransfer->eDstWidthOfEachTransfer) | DMA_DCR_DINC(psTransfer->eEnableDestIncrement) |
                  DMA_DCR_SSIZE(psTransfer->eSrcWidthOfEachTransfer) | DMA_DCR_SINC(psTransfer->eEnableSrcIncrement));
    base->DMA[(uint8_t)eChannel].DCR = u32Tmpreg;

    DMA_EnableChannelAutoStopRequest(base, eChannel, psTransfer->bEnablAutoStopPeripheralRequest);
    DMA_EnableChannelAutoAlign(base, eChannel, psTransfer->bEnableAutoAlign);
    DMA_EnableChannelCycleSteal(base, eChannel, psTransfer->bEnableCycleSteal);
    DMA_EnableChannelInterrupt(base, eChannel, psTransfer->bEnableInterrupt);
    DMA_SetChannelModulo(base, eChannel, psTransfer->eSrcAddrModulo, psTransfer->eDstAddrModulo);

    if (psTransfer->pChannelLinkControl != NULL)
    {
        DMA_SetChannelLinkConfig(base, eChannel, psTransfer->pChannelLinkControl);
    }
}

/*!
 * brief Configures the DMA channel link feature.
 *
 * This function allows DMA channels to have their transfers linked. The current DMA channel
 * triggers a DMA request to the linked channels (LCH1 or LCH2) depending on the channel link
 * type.
 * Perform a link to channel LCH1 after each cycle-steal transfer followed by a link to LCH2
 * after the BCR decrements to 0 if the type is kDMA_ChannelLinkChannel1AndChannel2.
 * Perform a link to LCH1 after each cycle-steal transfer if the type is kDMA_ChannelLinkChannel1.
 * Perform a link to LCH1 after the BCR decrements to 0 if the type is kDMA_ChannelLinkChannel1AfterBCR0.
 *
 * param base DMA peripheral base address.
 * param eChannel DMA channel number.
 * param pLinkConfig Pointer to the channel link configuration structure.
 */
void DMA_SetChannelLinkConfig(DMA_Type *base, dma_channel_t eChannel, dma_channel_link_config_t *pLinkConfig)
{
    assert((uint32_t)eChannel < (uint32_t)FSL_FEATURE_DMA_MODULE_CHANNEL);
    assert(pLinkConfig != NULL);

    uint32_t u32Tmpreg;

    u32Tmpreg = base->DMA[(uint8_t)eChannel].DCR;
    u32Tmpreg &= ~(DMA_DCR_LINKCC_MASK | DMA_DCR_LCH1_MASK | DMA_DCR_LCH2_MASK);
    u32Tmpreg |= (DMA_DCR_LINKCC(pLinkConfig->linkType) | DMA_DCR_LCH1(pLinkConfig->eChannel1) |
                  DMA_DCR_LCH2(pLinkConfig->eChannel2));
    base->DMA[(uint8_t)eChannel].DCR = u32Tmpreg;
}

/*!
 * brief Sets the DMA transfer peripheral number for the DMA transfer.
 *
 * param base DMA peripheral base address.
 * param eChannel DMA channel number.
 * param eChannelRequestSource The number of request source.
 */
void DMA_SetChannelPeripheralRequest(DMA_Type *base,
                                     dma_channel_t eChannel,
                                     dma_channel_request_source_t eChannelRequestSource)
{
    assert((uint32_t)eChannel < (uint32_t)FSL_FEATURE_DMA_MODULE_CHANNEL);
    assert((uint32_t)eChannel == (((uint32_t)eChannelRequestSource) >> 8));

    uint32_t u32Source;

    u32Source = (((uint32_t)eChannelRequestSource) & 0xFFU);

    if ((((uint32_t)eChannelRequestSource) >> 8) == 0UL)
    {
        base->REQC = (base->REQC & (~DMA_REQC_DMAC0_MASK)) | DMA_REQC_DMAC0(u32Source);
    }
    else if ((((uint32_t)eChannelRequestSource) >> 8) == 1UL)
    {
        base->REQC = (base->REQC & (~DMA_REQC_DMAC1_MASK)) | DMA_REQC_DMAC1(u32Source);
    }
    else if ((((uint32_t)eChannelRequestSource) >> 8) == 2UL)
    {
        base->REQC = (base->REQC & (~DMA_REQC_DMAC2_MASK)) | DMA_REQC_DMAC2(u32Source);
    }
    else
    {
        base->REQC = (base->REQC & (~DMA_REQC_DMAC3_MASK)) | DMA_REQC_DMAC3(u32Source);
    }
}

/*!
 * brief Sets the source address range and the destination address range for the DMA transfer.
 *
 * This function defines a specific address range of source/destination address, after the source/destination address
 * hits the range boundary, source/destination address will wrap to origin value.
 *
 * Setting this field provides the ability
 * to implement a circular data queue easily. For data queues require loop power-of-2 size bytes, the
 * queue should start at a 0-modulo-size address and the SMOD field should be set to the appropriate
 * value for the queue, freezing the desired number of upper address bits. The value programmed into
 * this field specifies the number of lower address bits allowed to change
 *
 * param base DMA peripheral base address.
 * param eChannel DMA channel number.
 * param eSrcModulo A source modulo value.
 * param eDestModulo A destination modulo value.
 */
void DMA_SetChannelModulo(DMA_Type *base,
                          dma_channel_t eChannel,
                          dma_channel_modulo_t eSrcModulo,
                          dma_channel_modulo_t eDestModulo)
{
    assert((uint32_t)eChannel < (uint32_t)FSL_FEATURE_DMA_MODULE_CHANNEL);

    uint32_t u32Tmpreg;

    u32Tmpreg = base->DMA[(uint8_t)eChannel].DCR;
    u32Tmpreg &= ~(DMA_DCR_SMOD_MASK | DMA_DCR_DMOD_MASK);
    u32Tmpreg |= (DMA_DCR_SMOD(eSrcModulo) | DMA_DCR_DMOD(eDestModulo));
    base->DMA[(uint8_t)eChannel].DCR = u32Tmpreg;
}

/*!
 * brief Creates the DMA handle.
 *
 * This function is called first if using the transactional API for the DMA. This function
 * initializes the internal state of the DMA handle.
 *
 * param base DMA peripheral base address.
 * param psHandle DMA handle pointer. The DMA handle stores callback function and
 *               parameters.
 * param eChannel DMA channel number.
 * param pfCallback DMA callback function pointer.
 * param pUserData A parameter for the callback function.
 */
void DMA_TransferChannelCreateHandle(
    DMA_Type *base, dma_handle_t *psHandle, dma_channel_t eChannel, dma_transfer_callback_t pfCallback, void *pUserData)
{
    assert(psHandle != NULL);
    assert((uint32_t)eChannel < (uint32_t)FSL_FEATURE_DMA_MODULE_CHANNEL);

    uint32_t u32DmaInstance  = 0U;
    uint32_t u32ChannelIndex = 0u;

    /* Zero the handle */
    (void)memset(psHandle, 0, sizeof(dma_handle_t));

    psHandle->psBase     = base;
    psHandle->eChannel   = eChannel;
    psHandle->pfCallback = pfCallback;
    psHandle->pUserData  = pUserData;

    /* Get the DMA instance number */
    u32DmaInstance               = DMA_GetInstance(base);
    u32ChannelIndex              = (u32DmaInstance * (uint32_t)FSL_FEATURE_DMA_MODULE_CHANNEL) + (uint32_t)eChannel;
    s_DMAHandle[u32ChannelIndex] = psHandle;

    /* Enable interrupt */
    (void)EnableIRQ(s_dmaIRQNumber[u32DmaInstance][u32ChannelIndex]);
}

/*!
 * brief Submits the DMA transfer request.
 *
 * This function submits the DMA transfer request according to the transfer configuration structure.
 *
 * param psHandle DMA handle pointer.
 * param psTransfer Pointer to DMA transfer configuration structure.
 *
 * retval kStatus_Success It indicates that the DMA submit transfer request succeeded.
 * retval kStatus_DMA_ChannelBusy It indicates that the DMA is busy. Submit transfer request is not allowed.
 * note This function can't process multi transfer request.
 */
status_t DMA_TransferChannelSubmit(dma_handle_t *psHandle, dma_channel_transfer_config_t *psTransfer)
{
    assert(psHandle != NULL);
    assert(psTransfer != NULL);

    status_t status;

    /* Check if DMA is busy */
    if ((psHandle->psBase->DMA[(uint8_t)psHandle->eChannel].DSR_BCR & DMA_DSR_BCR_BSY_MASK) != 0UL)
    {
        status = kStatus_DMA_ChannelBusy;
    }
    else
    {
        DMA_SetChannelTransferConfig(psHandle->psBase, psHandle->eChannel, psTransfer);
        status = kStatus_Success;
    }

    return status;
}

/*!
 * brief DMA starts transfer.
 *
 * This function enables the channel request. Call this function
 * after submitting a transfer request.
 *
 * param psHandle DMA handle pointer.
 * param bIsPeripheral  For true: enable DMA hardware request peripheral.
 * 				        For false: disable DMA hardware request peripheral.
 */
void DMA_TransferChannelStart(dma_handle_t *psHandle, bool bIsPeripheral)
{
    assert(psHandle != NULL);

    if (bIsPeripheral)
    {
        psHandle->psBase->DMA[(uint8_t)psHandle->eChannel].DCR |= DMA_DCR_ERQ_MASK;
    }
    else
    {
        psHandle->psBase->DMA[(uint8_t)psHandle->eChannel].DCR |= DMA_DCR_START_MASK;
    }
}

/*!
 * brief DMA stops a transfer.
 *
 * This function disables the channel request to stop a DMA transfer.
 * The transfer can be resumed by calling the DMA_StartTransfer.
 *
 * param psHandle DMA handle pointer.
 */
void DMA_TransferChannelStop(dma_handle_t *psHandle)
{
    assert(psHandle != NULL);

    if ((psHandle->psBase->DMA[(uint8_t)psHandle->eChannel].DCR & DMA_DCR_ERQ_MASK) != 0U)
    {
        psHandle->psBase->DMA[(uint8_t)psHandle->eChannel].DCR &= ~DMA_DCR_ERQ_MASK;
    }
}

/*!
 * brief DMA aborts transfer.
 *
 * This function disables the channel request and clear transfer status bits.
 * Users can submit another transfer after calling this API.
 *
 * param psHandle DMA handle pointer.
 */
void DMA_TransferChannelAbort(dma_handle_t *psHandle)
{
    assert(psHandle != NULL);

    if ((psHandle->psBase->DMA[(uint8_t)psHandle->eChannel].DCR & DMA_DCR_ERQ_MASK) != 0U)
    {
        psHandle->psBase->DMA[(uint8_t)psHandle->eChannel].DCR &= ~DMA_DCR_ERQ_MASK;
    }

    psHandle->psBase->DMA[(uint8_t)psHandle->eChannel].DSR_BCR |= DMA_DSR_BCR_DONE(true);
}

/*!
 * brief DMA IRQ handler for current transfer complete.
 *
 * This function clears the channel interrupt flag and calls
 * the callback function if it is not NULL.
 *
 * param psHandle DMA handle pointer.
 */
void DMA_TransferChannelHandleIRQ(dma_handle_t *psHandle)
{
    assert(psHandle != NULL);

    /* Clear interrupt pending bit */
    DMA_ClearChannelDoneStatus(psHandle->psBase, psHandle->eChannel);
    if (psHandle->pfCallback != NULL)
    {
        (psHandle->pfCallback)(psHandle, psHandle->pUserData);
    }
}

void DMA0_DriverIRQHandler(void);
void DMA0_DriverIRQHandler(void)
{
    DMA_TransferChannelHandleIRQ(s_DMAHandle[0]);
}

void DMA1_DriverIRQHandler(void);
void DMA1_DriverIRQHandler(void)
{
    DMA_TransferChannelHandleIRQ(s_DMAHandle[1]);
}

void DMA2_DriverIRQHandler(void);
void DMA2_DriverIRQHandler(void)
{
    DMA_TransferChannelHandleIRQ(s_DMAHandle[2]);
}

void DMA3_DriverIRQHandler(void);
void DMA3_DriverIRQHandler(void)
{
    DMA_TransferChannelHandleIRQ(s_DMAHandle[3]);
}
