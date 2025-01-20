/*
 * Copyright 2020 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_edma.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.dsc_edma"
#endif

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/*!
 * @brief Sets all fields to 0 for the TCD structure.
 *
 * This function sets all fields for this TCD structure to zero.
 *
 * @param psTcd Pointer to the TCD structure.
 */
static void EDMA_TcdReset(edma_channel_tcd_t *psTcd);

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*! @brief Array to map EDMA instance number to base pointer. */
static DMA_Type *const s_edmaBases[] = DMA_BASE_PTRS;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/*! @brief Array to map EDMA instance number to clock name. */
static const clock_ip_name_t s_edmaClockName[] = EDMA_CLOCKS;
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

/*! @brief Array to map EDMA instance number to IRQ number. */
static const IRQn_Type s_edmaIRQNumber[][FSL_FEATURE_EDMA_MODULE_CHANNEL] = DMA_CHN_IRQS;

/*! @brief Pointers to transfer handle for each EDMA channel. */
static edma_handle_t *s_EDMAHandle[FSL_FEATURE_EDMA_MODULE_CHANNEL * FSL_FEATURE_SOC_EDMA_COUNT];

/*******************************************************************************
 * Code
 ******************************************************************************/
static uint32_t EDMA_GetInstance(DMA_Type *base)
{
    uint32_t u32Instance;

    /* Find the instance index from base address mappings. */
    for (u32Instance = 0; u32Instance < ARRAY_SIZE(s_edmaBases); u32Instance++)
    {
        if (s_edmaBases[u32Instance] == base)
        {
            break;
        }
    }

    assert(u32Instance < ARRAY_SIZE(s_edmaBases));

    return u32Instance;
}

static uint32_t EDMA_GetInstanceOffset(uint32_t u32Instance)
{
    static uint8_t u8StartInstanceNum;

#if defined(DMA0)
    u8StartInstanceNum = (uint8_t)EDMA_GetInstance(DMA0);
#elif defined(DMA1)
    u8StartInstanceNum = (uint8_t)EDMA_GetInstance(DMA1);
#elif defined(DMA2)
    u8StartInstanceNum = (uint8_t)EDMA_GetInstance(DMA2);
#elif defined(DMA3)
    u8StartInstanceNum = (uint8_t)EDMA_GetInstance(DMA3);
#endif

    assert(u8StartInstanceNum <= u32Instance);

    return u32Instance - u8StartInstanceNum;
}

static void EDMA_TcdReset(edma_channel_tcd_t *psTcd)
{
    assert(psTcd != NULL);
    assert(((uint32_t)((uint8_t *)psTcd) & 0x1FU) == 0U);

    /* Reset channel TCD */
    psTcd->u32SADDR     = 0U;
    psTcd->u16SOFF      = 0U;
    psTcd->u16ATTR      = 0U;
    psTcd->u32NBYTES    = 0U;
    psTcd->u32SLAST     = 0U;
    psTcd->u32DADDR     = 0U;
    psTcd->u16DOFF      = 0U;
    psTcd->u16CITER     = 0U;
    psTcd->u32DLAST_SGA = 0U;
    psTcd->u16CSR       = 0U;
    psTcd->u16BITER     = 0U;
}

/*!
 * brief Get default edma configuration.
 *
 * note This function will reset all of the configuration structure members to zero firstly,
 *       then apply default configurations to the structure.
 *
 * param psConfig pointer to user's eDMA configure structure, see edma_config_t for detail.
 */
void EDMA_GetDefaultConfig(edma_config_t *psConfig)
{
    assert(psConfig != NULL);

    uint16_t i = 0U;

    (void)memset(psConfig, 0, sizeof(edma_config_t));

    psConfig->eArbitrationType          = kEDMA_ArbitrationFixedPriority;
    psConfig->bEnableHaltOnError        = true;
    psConfig->bEnableContinuousLinkMode = false;
    psConfig->bEnableDmaInDebugMode     = false;
    psConfig->bEnableMinorLoopMapping   = true;

    for (i = 0U; i < (uint32_t)FSL_FEATURE_EDMA_MODULE_CHANNEL; i++)
    {
        psConfig->sChannelPreemptionConfig[i].bSuspendedByHighPriorityChannel = false;
        psConfig->sChannelPreemptionConfig[i].bSuspendLowPriorityChannel      = false;
        psConfig->sChannelPreemptionConfig[i].u8ChannelPriority               = (uint8_t)i;
    }
}

/*!
 * brief EDMA initialization
 *
 * param base eDMA peripheral base address.
 * param psConfig pointer to user's eDMA configure structure, see edma_transfer_config_t for detail.
 */
void EDMA_Init(DMA_Type *base, edma_config_t *psConfig)
{
    assert(psConfig != NULL);

    uint32_t u32tmpCSR, i = 0U;
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Ungate EDMA peripheral clock */
    CLOCK_EnableClock(s_edmaClockName[EDMA_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

    /* clear all the enabled request, status to make sure EDMA status is in normal condition */
    base->CERQ = 0x40U;
    base->CINT = 0x40U;
    base->CERR = 0x40U;
    base->CDNE = 0x40U;

    /* Configure EDMA peripheral according to the configuration structure. */
    u32tmpCSR = base->CR;
    u32tmpCSR &= ~(DMA_CR_ERCA_MASK | DMA_CR_HOE_MASK | DMA_CR_CLM_MASK | DMA_CR_EDBG_MASK);
    u32tmpCSR |= (DMA_CR_ERCA(psConfig->eArbitrationType) | DMA_CR_HOE(psConfig->bEnableHaltOnError) |
                  DMA_CR_CLM(psConfig->bEnableContinuousLinkMode) | DMA_CR_EDBG(psConfig->bEnableDmaInDebugMode) |
                  DMA_CR_EMLM(psConfig->bEnableMinorLoopMapping));
    base->CR = u32tmpCSR;

    /* channel preemption configuration */
    if (psConfig->eArbitrationType == kEDMA_ArbitrationFixedPriority)
    {
        EDMA_SetChannelPreemption(base, (edma_channel_t)i,
                                  psConfig->sChannelPreemptionConfig[i].bSuspendedByHighPriorityChannel,
                                  psConfig->sChannelPreemptionConfig[i].bSuspendLowPriorityChannel,
                                  psConfig->sChannelPreemptionConfig[i].u8ChannelPriority);
    }

    /* channel transfer configuration */
    for (i = 0U; i < (uint32_t)FSL_FEATURE_EDMA_MODULE_CHANNEL; i++)
    {
        if (psConfig->psChannelTransferConfig[i] != NULL)
        {
            EDMA_SetChannelTransferConfig(base, (edma_channel_t)i, psConfig->psChannelTransferConfig[i]);
        }
    }
}

/*!
 * @brief EDMA De-initialization
 *
 * @param base eDMA peripheral base address.
 */
void EDMA_Deinit(DMA_Type *base)
{
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Ungate EDMA peripheral clock */
    CLOCK_DisableClock(s_edmaClockName[EDMA_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

/*!
 * brief Get channel default transfer configuration.
 *
 * note 1. This function will reset all of the configuration structure members to zero firstly,
 *       then apply default configurations to the structure.
 *       2. No interrupt enabled by this function by default, if application would like to use DMA interrupt
 *          please enable it manually by psTransfer->u16EnabledInterruptMask = _edma_channel_interrupt
 *
 * param psTransfer pointer to user's eDMA channel configure structure, see edma_channel_transfer_config_t for detail.
 * param u32SrcAddr source address, must be byte address.
 * param u32DstAddr destination address,  must be byte address.
 * param u32BytesEachRequest bytes to be transferred in each request(namely, in each minor loop).
 * param u32TotalBytes total bytes to be transferred.
 * param eTransferWidth it represents how many bits are transferred in each read/write.
 * param eTransferType eDMA channel transfer type.
 */
void EDMA_GetChannelDefaultTransferConfig(edma_channel_transfer_config_t *psTransfer,
                                          uint32_t u32SrcAddr,
                                          uint32_t u32DstAddr,
                                          uint32_t u32BytesEachRequest,
                                          uint32_t u32TotalBytes,
                                          edma_channel_transfer_width_t eTransferWidth,
                                          edma_channel_transfer_type_t eTransferType)
{
    assert(psTransfer != NULL);
    assert(((u32TotalBytes % u32BytesEachRequest) == 0U));

    uint32_t u32TransferWidthTmpValue = 0UL;
    (void)memset(psTransfer, 0, sizeof(edma_channel_transfer_config_t));

    psTransfer->u32SrcAddr                      = u32SrcAddr;
    psTransfer->u32DstAddr                      = u32DstAddr;
    psTransfer->eSrcWidthOfEachTransfer         = eTransferWidth;
    psTransfer->eDstWidthOfEachTransfer         = eTransferWidth;
    psTransfer->u32BytesEachMinorLoop           = u32BytesEachRequest;
    psTransfer->u16MinorLoopCountsEachMajorLoop = (uint16_t)(u32TotalBytes / u32BytesEachRequest);

    /* default advance channel transfer configurations */
    psTransfer->eSrcAddrModulo = kEDMA_ChannelModuloDisable;
    psTransfer->eDstAddrModulo = kEDMA_ChannelModuloDisable;

    u32TransferWidthTmpValue = 1UL << (uint32_t)eTransferWidth;
    if (eTransferType == kEDMA_ChannelTransferMemoryToMemory)
    {
        psTransfer->i16SrcOffsetOfEachTransfer = (int16_t)u32TransferWidthTmpValue;
        psTransfer->i16DstOffsetOfEachTransfer = (int16_t)u32TransferWidthTmpValue;
    }
    else if (eTransferType == kEDMA_ChannelTransferPeripheralToMemory)
    {
        psTransfer->i16SrcOffsetOfEachTransfer = 0;
        psTransfer->i16DstOffsetOfEachTransfer = (int16_t)u32TransferWidthTmpValue;
    }
    else if (eTransferType == kEDMA_ChannelTransferMemoryToPeripheral)
    {
        psTransfer->i16SrcOffsetOfEachTransfer = (int16_t)u32TransferWidthTmpValue;
        psTransfer->i16DstOffsetOfEachTransfer = 0;
    }
    else
    {
        psTransfer->i16SrcOffsetOfEachTransfer = 0;
        psTransfer->i16DstOffsetOfEachTransfer = 0;
    }

    psTransfer->bEnableSrcMinorLoopOffset = false;
    psTransfer->bEnableDstMinorLoopOffset = false;
    psTransfer->i32MinorLoopOffset        = 0;

    psTransfer->i32SrcMajorLoopOffset = 0;
    psTransfer->i32DstMajorLoopOffset = 0;

    psTransfer->bEnableChannelMajorLoopLink = false;
    psTransfer->bEnableChannelMinorLoopLink = false;
    /* no interrupt enable by default */
    psTransfer->u16EnabledInterruptMask = 0U;

    psTransfer->eChannelBandWidth                     = kEDMA_ChannelBandwidthStallNone;
    psTransfer->bDisableRequestAfterMajorLoopComplete = true;

    psTransfer->bEnableChannelRequest = false;
}

/*!
 * brief EDMA set channel transfer configurations
 *
 * param base eDMA peripheral base address.
 * param eChannel eDMA channel number.
 * param psTransfer pointer to user's eDMA channel configure structure, see edma_channel_transfer_config_t for detail.
 *
 * note
 * 1.This function must not be called while the channel transfer is ongoing
 * or it causes unpredictable results.
 * 2.The psLinkTCD must be configured before invoke this API if scatter/gather function is needed
 * 3.The edma channel request may be enabled after the channel transfer configure done according to the transfer
 *   configurations.
 *
 */
void EDMA_SetChannelTransferConfig(DMA_Type *base, edma_channel_t eChannel, edma_channel_transfer_config_t *psTransfer)
{
    assert(eChannel < (edma_channel_t)FSL_FEATURE_EDMA_MODULE_CHANNEL);
    assert(psTransfer != NULL);

    edma_channel_tcd_t *psTcdRegs = NULL;

    /*
       Reset TCD registers to zero.
    */
    psTcdRegs = (edma_channel_tcd_t *)(uint32_t)&base->TCD[(uint8_t)eChannel];
    EDMA_TcdReset(psTcdRegs);

    /* minor loop mapping need to enabled for minor loop offset feature */
    if (((psTransfer->bEnableSrcMinorLoopOffset) || (psTransfer->bEnableDstMinorLoopOffset)))
    {
        EDMA_EnableMinorLoopMapping(base, true);
    }
    /* configure TCD */
    EDMA_ConfigChannelSoftwareTCD(psTcdRegs, psTransfer);

    EDMA_EnableChannelInterrupts(
        base, eChannel, psTransfer->u16EnabledInterruptMask & (uint16_t)kEDMA_ChannelErrorInterruptEnable, true);
    EDMA_EnableChannelRequest(base, eChannel, psTransfer->bEnableChannelRequest);
}

/*!
 * brief Gets the eDMA channel status flags.
 *
 * param base eDMA peripheral base address.
 * param eChannel eDMA channel number.
 * return The mask of channel status flags. Users need to use the
 *         _edma_channel_status_flags type to decode the return variables.
 */
uint16_t EDMA_GetChannelStatusFlags(DMA_Type *base, edma_channel_t eChannel)
{
    assert(eChannel < (edma_channel_t)FSL_FEATURE_EDMA_MODULE_CHANNEL);

    uint16_t retval = 0;

    /* Get DONE bit flag */
    if ((base->TCD[(uint8_t)eChannel].CSR & DMA_CSR_DONE_MASK) != 0U)
    {
        retval |= (uint16_t)kEDMA_ChannelStatusMajorLoopCompleteFlag;
    }
    else
    {
        if (((base->INT >> ((uint8_t)eChannel)) & 0x1U) != 0U)
        {
            retval |= (uint16_t)kEDMA_ChannelStatusMajorLoopHalfCompleteFlag;
        }
    }

    /* Get ERROR bit flag */
    if (((base->ERR >> ((uint8_t)eChannel)) & 0x1U) != 0U)
    {
        retval |= (uint16_t)kEDMA_ChannelStatusErrorFlag;
    }

    return retval;
}

/*!
 * brief Clears the eDMA channel status flags.
 *
 * param base eDMA peripheral base address.
 * param eChannel eDMA channel number.
 * param u16StatusFlags The mask of channel status to be cleared. Users need to use
 *             the defined _edma_channel_status_flags type.
 */
void EDMA_ClearChannelStatusFlags(DMA_Type *base, edma_channel_t eChannel, uint16_t u16StatusFlags)
{
    assert(eChannel < (edma_channel_t)FSL_FEATURE_EDMA_MODULE_CHANNEL);

    /* Clear complete status bit flag */
    if (0U != (u16StatusFlags & (uint16_t)kEDMA_ChannelStatusMajorLoopCompleteFlag))
    {
        base->CDNE = (uint8_t)eChannel;
        base->CINT = (uint8_t)eChannel;
    }
    /* Clear ERROR bit flag */
    if (0U != (u16StatusFlags & (uint16_t)kEDMA_ChannelStatusErrorFlag))
    {
        base->CERR = (uint8_t)eChannel;
    }
    /* Clear half complete status flag */
    if (0U != (u16StatusFlags & (uint16_t)kEDMA_ChannelStatusMajorLoopHalfCompleteFlag))
    {
        base->CINT = (uint8_t)eChannel;
    }
}

/*!
 * brief Configures the eDMA channel minor loop offset value.
 *
 * The minor offset means that the signed-extended value is added to the source address or destination
 * address after each minor loop.
 *
 * param base eDMA peripheral base address.
 * param eChannel eDMA channel number.
 * param bEnableSrcMinorLoopOffset True is enable source address minor offset, otherwise is disable
 * param bEnableDestMinorLoopOffset True is enable source address minor offset, otherwise is disable
 * param i32MinorLoopOffset Minor loop offset value.
 */
void EDMA_SetChannelMinorLoopOffset(DMA_Type *base,
                                    edma_channel_t eChannel,
                                    bool bEnableSrcMinorLoopOffset,
                                    bool bEnableDestMinorLoopOffset,
                                    int32_t i32MinorLoopOffset)
{
    assert(eChannel < (edma_channel_t)FSL_FEATURE_EDMA_MODULE_CHANNEL);

    uint32_t u32Tmpreg;

    u32Tmpreg = base->TCD[(uint8_t)eChannel].NBYTES_MLOFFYES;
    u32Tmpreg &= ~(DMA_NBYTES_MLOFFYES_SMLOE_MASK | DMA_NBYTES_MLOFFYES_DMLOE_MASK | DMA_NBYTES_MLOFFYES_MLOFF_MASK);
    u32Tmpreg |=
        (DMA_NBYTES_MLOFFYES_SMLOE(bEnableSrcMinorLoopOffset) | DMA_NBYTES_MLOFFYES_DMLOE(bEnableDestMinorLoopOffset) |
         DMA_NBYTES_MLOFFYES_MLOFF(i32MinorLoopOffset));
    base->TCD[(uint8_t)eChannel].NBYTES_MLOFFYES = u32Tmpreg;
}

/*!
 * brief Configures the eDMA channel major loop offset feature.
 *
 * Adjustment value added to the source/destination address at the completion of the major iteration count
 *
 * param base eDMA peripheral base address.
 * param eChannel edma channel number.
 * param i32SourceOffset source address offset.
 * param i32DestOffset destination address offset.
 */
void EDMA_SetChannelMajorLoopOffset(DMA_Type *base,
                                    edma_channel_t eChannel,
                                    int32_t i32SourceOffset,
                                    int32_t i32DestOffset)
{
    assert(eChannel < (edma_channel_t)FSL_FEATURE_EDMA_MODULE_CHANNEL);

    base->TCD[(uint8_t)eChannel].SLAST     = i32SourceOffset;
    base->TCD[(uint8_t)eChannel].DLAST_SGA = i32DestOffset;
}

/*!
 * brief Configures the eDMA channel preemption configurations.
 *
 * This function configures the channel preemption attribute and the priority of the channel.
 *
 * param base eDMA peripheral base address.
 * param eChannel eDMA channel number
 * param bSuspendedByHighPriorityChannel True is the channel can be suspended by high priority channel, otherwise
 cannot.
 * param bSuspendLowPriorityChannel True is the channel can suspend low priority channel, otherwise cannot.
 * param u8Priority Channel priority.
 *
 * note, this function is used only in  fixed-priority channel arbitration mode.
 */
void EDMA_SetChannelPreemption(DMA_Type *base,
                               edma_channel_t eChannel,
                               bool bSuspendedByHighPriorityChannel,
                               bool bSuspendLowPriorityChannel,
                               uint8_t u8Priority)
{
    assert(eChannel < (edma_channel_t)FSL_FEATURE_EDMA_MODULE_CHANNEL);

    uint8_t u8Reg =
        (DMA_DCHPRI0_DPA((true == bSuspendLowPriorityChannel ? 0U : 1U)) |
         DMA_DCHPRI0_ECP((true == bSuspendedByHighPriorityChannel ? 1U : 0U)) | DMA_DCHPRI0_CHPRI(u8Priority));

    /* Don't use a uint8_t pointer of DCHPRI3 for index by eChannel, since a uint8_t pointer of DCHPRI3
     * is out of 16bits, that is not SDM compliance */

    switch (eChannel)
    {
        case kEDMA_Channel0:
            base->DCHPRI0 = u8Reg;
            break;
        case kEDMA_Channel1:
            base->DCHPRI1 = u8Reg;
            break;
        case kEDMA_Channel2:
            base->DCHPRI2 = u8Reg;
            break;
        case kEDMA_Channel3:
            base->DCHPRI3 = u8Reg;
            break;
        default:
            assert(false);
            break;
    }
}

/*!
 * brief Enable the major loop channel link and configure the linked channel number.
 *
 * This function configures the major link mode. The major link means that the channel link is triggered when the CITER
 * is exhausted.
 *
 * param base eDMA peripheral base address.
 * param eChannel eDMA channel number.
 * param eLinkChannel The linked channel number.
 * note Users should ensure that DONE flag is cleared before calling this interface, or the configuration is invalid.
 */
void EDMA_EnableMajorLoopChannelLink(DMA_Type *base, edma_channel_t eChannel, edma_channel_t eLinkChannel)
{
    uint16_t tmpreg;

    tmpreg                           = base->TCD[(uint8_t)eChannel].CSR & (~(uint16_t)DMA_CSR_MAJORLINKCH_MASK);
    base->TCD[(uint8_t)eChannel].CSR = tmpreg | DMA_CSR_MAJORLINKCH(eLinkChannel) | DMA_CSR_MAJORELINK_MASK;
}

/*!
 * brief Enable the minor loop channel link and configure the linked channel number.
 *
 * This function configures the minor link mode. The minor link means that the channel link is
 * triggered every time CITER decreases by 1.
 *
 * param base eDMA peripheral base address.
 * param eChannel eDMA channel number.
 * param eLinkChannel The linked channel number.
 * note Users should ensure that DONE flag is cleared before calling this interface, or the configuration is invalid.
 */
void EDMA_EnableMinorLoopChannelLink(DMA_Type *base, edma_channel_t eChannel, edma_channel_t eLinkChannel)
{
    uint16_t tmpreg;

    tmpreg = base->TCD[(uint8_t)eChannel].CITER_ELINKYES & (~(uint16_t)DMA_CITER_ELINKYES_LINKCH_MASK);
    tmpreg |= DMA_CITER_ELINKYES_LINKCH(eLinkChannel);
    base->TCD[(uint8_t)eChannel].CITER_ELINKYES = tmpreg | DMA_CITER_ELINKYES_ELINK_MASK;
    tmpreg = base->TCD[(uint8_t)eChannel].BITER_ELINKYES & (~(uint16_t)DMA_BITER_ELINKYES_LINKCH_MASK);
    tmpreg |= DMA_BITER_ELINKYES_LINKCH(eLinkChannel);
    base->TCD[(uint8_t)eChannel].BITER_ELINKYES = tmpreg | DMA_BITER_ELINKYES_ELINK_MASK;
}

/*!
 * brief Sets the edma channel stall cycles after each R/W.
 *
 * Because the eDMA processes the minor loop, it continuously generates read/write sequences
 * until the minor count is exhausted. The bandwidth forces the eDMA to stall after the completion of
 * each read/write access to control the bus request bandwidth seen by the crossbar switch.
 *
 * NOTE:
 * 1.If the source and destination sizes are equal, this field is ignored between the first and second
 * transfers and after the last write of each minor loop. This behavior is a side effect of reducing
 * start-up latency.
 * 2.When executing a large, zero wait-stated memory-to-memory transfer, insert bandwidth control
 * using the TCD_CSR[BWC] bits to avoid:
 *   Starvation of another master accessing the memory.
 *   Any delay in writing a TCD during the transfer.
 *
 * param base eDMA peripheral base address.
 * param eChannel eDMA channel number.
 * param eBandWidth A bandwidth setting, which can be one of the following:
 *     arg kEDMABandwidthStallNone
 *     arg kEDMABandwidthStall4Cycle
 *     arg kEDMABandwidthStall8Cycle
 */
void EDMA_SetChannelBandWidth(DMA_Type *base, edma_channel_t eChannel, edma_channel_bandwidth_t eBandWidth)
{
    assert(eChannel < (edma_channel_t)FSL_FEATURE_EDMA_MODULE_CHANNEL);

    base->TCD[(uint8_t)eChannel].CSR =
        (uint16_t)((base->TCD[(uint8_t)eChannel].CSR & (~DMA_CSR_BWC_MASK)) | DMA_CSR_BWC(eBandWidth));
}

/*!
 * brief Sets the source address range and the destination address range for the eDMA transfer.
 *
 * This function defines a specific address range of source/destination address, after the source/destination address
 * hits the range boundary, source/destination address will wrap to origin value.
 *
 * Setting this field provides the ability
 * to implement a circular data queue easily. For data queues requiring power-of-2 size bytes, the
 * queue should start at a 0-modulo-size address and the SMOD field should be set to the appropriate
 * value for the queue, freezing the desired number of upper address bits. The value programmed into
 * this field specifies the number of lower address bits allowed to change
 *
 * param base eDMA peripheral base address.
 * param eChannel eDMA channel number.
 * param eSrcModulo A source modulo value.
 * param eDestModulo A destination modulo value.
 */
void EDMA_SetChannelModulo(DMA_Type *base,
                           edma_channel_t eChannel,
                           edma_channel_modulo_t eSrcModulo,
                           edma_channel_modulo_t eDestModulo)
{
    assert(eChannel < (edma_channel_t)FSL_FEATURE_EDMA_MODULE_CHANNEL);

    uint16_t u16Tmpreg;

    u16Tmpreg = base->TCD[(uint8_t)eChannel].ATTR & (~(uint16_t)(DMA_ATTR_SMOD_MASK | DMA_ATTR_DMOD_MASK));
    base->TCD[(uint8_t)eChannel].ATTR = u16Tmpreg | DMA_ATTR_DMOD(eDestModulo) | DMA_ATTR_SMOD(eSrcModulo);
}

/*!
 * brief Enables the edma channel interrupts according to a provided mask,
 *       the mask is a logical OR of enumerator members see _edma_channel_interrupt_enable.
 *
 * param base eDMA peripheral base address.
 * param eChannel eDMA channel number.
 * param u16InterruptsMask the mask is a logical OR of enumerator members @ref _edma_channel_interrupt_enable.
 * param bEnable true is enable, false is disable.
 */
void EDMA_EnableChannelInterrupts(DMA_Type *base, edma_channel_t eChannel, uint16_t u16InterruptsMask, bool bEnable)
{
    assert(eChannel < (edma_channel_t)FSL_FEATURE_EDMA_MODULE_CHANNEL);

    /* Enable error interrupt */
    if (0U != (u16InterruptsMask & (uint16_t)kEDMA_ChannelErrorInterruptEnable))
    {
        if (bEnable)
        {
            base->SEEI = DMA_SEEI_SEEI(eChannel);
        }
        else
        {
            base->CEEI = DMA_CEEI_CEEI(eChannel);
        }
    }
    else
    {
        uint16_t u16TempReg = base->TCD[(uint8_t)eChannel].CSR;
        /* Enable complete(major) interrupt */
        if (0U != (u16InterruptsMask & (uint32_t)kEDMA_ChannelMajorLoopCompleteInterruptEnable))
        {
            u16TempReg &= ~(uint16_t)DMA_CSR_INTMAJOR_MASK;
            u16TempReg |= bEnable ? DMA_CSR_INTMAJOR_MASK : 0U;
        }

        /* Enable Half complete(half major) interrupt */
        if (0U != (u16InterruptsMask & (uint32_t)kEDMA_ChannelMajorLoopHalfCompleteInterruptEnable))
        {
            u16TempReg &= ~(uint16_t)DMA_CSR_INTHALF_MASK;
            u16TempReg |= bEnable ? DMA_CSR_INTHALF_MASK : 0U;
        }

        base->TCD[(uint8_t)eChannel].CSR = u16TempReg;
    }
}

/*!
 * brief Gets the remaining major loop count from the eDMA current channel TCD.
 *
 * This function checks the TCD (Task Control Descriptor) status for a specified
 * eDMA channel and returns the number of major loop count that has not finished.
 *
 * param base eDMA peripheral base address.
 * param eChannel eDMA channel number.
 * return Major loop count which has not been transferred yet for the current TCD.
 * note 1. This function can only be used to get unfinished major loop count of transfer without
 *          the next TCD, or it might be inaccuracy.
 *       2. The unfinished/remaining transfer bytes cannot be obtained directly from registers while
 *          the channel is running.
 *          Because to calculate the remaining bytes, the initial NBYTES configured in DMA_TCDn_NBYTES_MLNO
 *          register is needed while the eDMA IP does not support getting it while a channel is active.
 *          In another word, the NBYTES value reading is always the actual (decrementing) NBYTES value the dma_engine
 *          is working with while a channel is running.
 *          Consequently, to get the remaining transfer bytes, a software-saved initial value of NBYTES (for example
 *          copied before enabling the channel) is needed. The formula to calculate it is shown below:
 *          RemainingBytes = RemainingMajorLoopCount * NBYTES(initially configured)
 */
uint32_t EDMA_GetChannelRemainingMajorLoopCount(DMA_Type *base, edma_channel_t eChannel)
{
    assert(eChannel < (edma_channel_t)FSL_FEATURE_EDMA_MODULE_CHANNEL);

    uint32_t u32RemainingCount = 0;

    if (0U != (DMA_CSR_DONE_MASK & base->TCD[(uint8_t)eChannel].CSR))
    {
        u32RemainingCount = 0;
    }
    else
    {
        /* Calculate the unfinished bytes */
        if (0U != (base->TCD[(uint8_t)eChannel].CITER_ELINKNO & DMA_CITER_ELINKNO_ELINK_MASK))
        {
            u32RemainingCount =
                (((uint32_t)base->TCD[(uint8_t)eChannel].CITER_ELINKYES & DMA_CITER_ELINKYES_CITER_MASK) >>
                 DMA_CITER_ELINKYES_CITER_SHIFT);
        }
        else
        {
            u32RemainingCount =
                (((uint32_t)base->TCD[(uint8_t)eChannel].CITER_ELINKNO & DMA_CITER_ELINKNO_CITER_MASK) >>
                 DMA_CITER_ELINKNO_CITER_SHIFT);
        }
    }

    return u32RemainingCount;
}

/*!
 * brief Push content of TCD structure into hardware TCD register.
 *
 * param base EDMA peripheral base address.
 * param eChannel EDMA channel number.
 * param tcd Point to TCD structure.
 */
void EDMA_InstallChannelSoftwareTCD(DMA_Type *base, edma_channel_t eChannel, edma_channel_tcd_t *psTcd)
{
    assert(eChannel < (edma_channel_t)FSL_FEATURE_EDMA_MODULE_CHANNEL);
    assert(psTcd != NULL);
    assert(((uint32_t)((uint8_t *)psTcd) & 0x1FU) == 0U);

    /* Push tcd into hardware TCD register */
    base->TCD[(uint8_t)eChannel].SADDR         = psTcd->u32SADDR;
    base->TCD[(uint8_t)eChannel].SOFF          = psTcd->u16SOFF;
    base->TCD[(uint8_t)eChannel].ATTR          = psTcd->u16ATTR;
    base->TCD[(uint8_t)eChannel].NBYTES_MLNO   = psTcd->u32NBYTES;
    base->TCD[(uint8_t)eChannel].SLAST         = (int32_t)psTcd->u32SLAST;
    base->TCD[(uint8_t)eChannel].DADDR         = psTcd->u32DADDR;
    base->TCD[(uint8_t)eChannel].DOFF          = psTcd->u16DOFF;
    base->TCD[(uint8_t)eChannel].CITER_ELINKNO = psTcd->u16CITER;
    base->TCD[(uint8_t)eChannel].DLAST_SGA     = (int32_t)psTcd->u32DLAST_SGA;
    /* Clear DONE bit first, otherwise ESG cannot be set */
    base->TCD[(uint8_t)eChannel].CSR           = 0;
    base->TCD[(uint8_t)eChannel].CSR           = psTcd->u16CSR;
    base->TCD[(uint8_t)eChannel].BITER_ELINKNO = psTcd->u16BITER;
}

/*!
 * brief Sets TCD fields according to the user's channel transfer configuration structure, see
 * edma_channel_transfer_config_t.
 *
 * Application should be careful about the TCD pool buffer storage class,
 * - For the platform has cache, the software TCD should be put in non cache section
 * - The TCD pool buffer should have a consistent storage class.
 *
 * note Application should be careful when using the minor loop offset feature with this function, please make sure the
 * EMLM bit is asserted, although EDMA_SetChannelTransferConfig will set this bit by default, if the bit is cleared,
 * application can use @ref EDMA_EnableMinorLoopMapping to enable the feature.*
 *
 * param psTcd Pointer to the TCD structure.
 * param psTransfer channel transfer configuration pointer.
 *
 */
void EDMA_ConfigChannelSoftwareTCD(edma_channel_tcd_t *psTcd, edma_channel_transfer_config_t *psTransfer)
{
    assert(psTransfer != NULL);
    assert((psTransfer->u32BytesEachMinorLoop % (1UL << ((uint32_t)psTransfer->eSrcWidthOfEachTransfer))) == 0U);
    assert((psTransfer->u32BytesEachMinorLoop % (1UL << ((uint32_t)psTransfer->eDstWidthOfEachTransfer))) == 0U);
    assert(((uint32_t)psTransfer->i16SrcOffsetOfEachTransfer %
            (1UL << ((uint32_t)psTransfer->eSrcWidthOfEachTransfer))) == 0U);
    assert(((uint32_t)psTransfer->i16DstOffsetOfEachTransfer %
            (1UL << ((uint32_t)psTransfer->eDstWidthOfEachTransfer))) == 0U);
    assert((psTransfer->u32SrcAddr % (1UL << ((uint32_t)psTransfer->eSrcWidthOfEachTransfer))) == 0U);
    assert((psTransfer->u32DstAddr % (1UL << ((uint32_t)psTransfer->eDstWidthOfEachTransfer))) == 0U);
    assert((psTransfer->u32SrcAddr % (1UL << ((uint32_t)psTransfer->eSrcAddrModulo))) == 0U);
    assert((psTransfer->u32DstAddr % (1UL << ((uint32_t)psTransfer->eDstAddrModulo))) == 0U);

    uint16_t u16Tmpreg;

    /* source address */
    psTcd->u32SADDR = psTransfer->u32SrcAddr;
    /* destination address */
    psTcd->u32DADDR = psTransfer->u32DstAddr;
    /* Source data and destination data transfer size */
    psTcd->u16ATTR =
        DMA_ATTR_SSIZE(psTransfer->eSrcWidthOfEachTransfer) | DMA_ATTR_DSIZE(psTransfer->eDstWidthOfEachTransfer);

    /* Source address signed offset */
    psTcd->u16SOFF = (uint16_t)(psTransfer->i16SrcOffsetOfEachTransfer);
    /* Destination address signed offset */
    psTcd->u16DOFF = (uint16_t)(psTransfer->i16DstOffsetOfEachTransfer);

    if (((psTransfer->bEnableSrcMinorLoopOffset) || (psTransfer->bEnableDstMinorLoopOffset)))
    {
        psTcd->u32NBYTES = DMA_NBYTES_MLOFFYES_NBYTES(psTransfer->u32BytesEachMinorLoop) |
                           DMA_NBYTES_MLOFFYES_MLOFF(psTransfer->i32MinorLoopOffset) |
                           DMA_NBYTES_MLOFFYES_DMLOE(psTransfer->bEnableDstMinorLoopOffset) |
                           DMA_NBYTES_MLOFFYES_SMLOE(psTransfer->bEnableSrcMinorLoopOffset);
    }
    else
    {
        psTcd->u32NBYTES = DMA_NBYTES_MLNO_NBYTES(psTransfer->u32BytesEachMinorLoop);
    }

    /* Current major iteration count */
    psTcd->u16CITER = (uint16_t)(psTransfer->u16MinorLoopCountsEachMajorLoop);
    /* Starting major iteration count */
    psTcd->u16BITER = (uint16_t)(psTransfer->u16MinorLoopCountsEachMajorLoop);
    /* Enable scatter/gather processing */
    if (psTransfer->psLinkTCD != NULL)
    {
        psTcd->u32DLAST_SGA = (uint32_t)((uint8_t *)psTransfer->psLinkTCD);

        psTcd->u16CSR |= (uint16_t)DMA_CSR_ESG_MASK;
    }
    else
    {
        psTcd->u16CSR &= ~(uint16_t)DMA_CSR_ESG_MASK;
        psTcd->u32DLAST_SGA = (uint32_t)psTransfer->i32DstMajorLoopOffset;
    }

    /* configure bandwidth/interrupt/auto disable channel request */
    psTcd->u16CSR |= (psTcd->u16CSR & (~(uint16_t)(DMA_CSR_DREQ_MASK | DMA_CSR_BWC_MASK))) |
                     DMA_CSR_BWC(psTransfer->eChannelBandWidth) |
                     DMA_CSR_DREQ(psTransfer->bDisableRequestAfterMajorLoopComplete) |
                     (psTransfer->u16EnabledInterruptMask & (~(uint16_t)kEDMA_ChannelErrorInterruptEnable));

    /* Minor link config */
    if (psTransfer->bEnableChannelMinorLoopLink)
    {
        uint16_t tmpreg;

        /* Enable minor link */
        psTcd->u16CITER |= DMA_CITER_ELINKYES_ELINK_MASK;
        psTcd->u16BITER |= DMA_BITER_ELINKYES_ELINK_MASK;
        /* Set linked channel */
        tmpreg = psTcd->u16CITER & (~(uint16_t)DMA_CITER_ELINKYES_LINKCH_MASK);
        tmpreg |= DMA_CITER_ELINKYES_LINKCH(psTransfer->eMinorLoopLinkChannel);
        psTcd->u16CITER = tmpreg;
        tmpreg          = psTcd->u16BITER & (~(uint16_t)DMA_BITER_ELINKYES_LINKCH_MASK);
        tmpreg |= DMA_BITER_ELINKYES_LINKCH(psTransfer->eMinorLoopLinkChannel);
        psTcd->u16BITER = tmpreg;
    }
    /* Major link config */
    if (psTransfer->bEnableChannelMajorLoopLink)
    {
        uint16_t tmpreg;

        /* Enable major link */
        psTcd->u16CSR |= DMA_CSR_MAJORELINK_MASK;
        /* Set major linked channel */
        tmpreg        = psTcd->u16CSR & (~(uint16_t)DMA_CSR_MAJORLINKCH_MASK);
        psTcd->u16CSR = tmpreg | DMA_CSR_MAJORLINKCH(psTransfer->eMajorLoopLinkChannel);
    }
    /* clear link relate field if no channel link enabled */
    if ((!psTransfer->bEnableChannelMajorLoopLink) && (!psTransfer->bEnableChannelMinorLoopLink))
    {
        psTcd->u16CITER &= ~(uint16_t)DMA_CITER_ELINKYES_ELINK_MASK;
        psTcd->u16BITER &= ~(uint16_t)DMA_BITER_ELINKYES_ELINK_MASK;
        psTcd->u16CSR &= ~(uint16_t)DMA_CSR_MAJORELINK_MASK;
    }

    /* major loop offset */
    psTcd->u32SLAST = (uint32_t)psTransfer->i32SrcMajorLoopOffset;
    /* modulo feature */
    u16Tmpreg      = psTcd->u16ATTR & (~(uint16_t)(DMA_ATTR_SMOD_MASK | DMA_ATTR_DMOD_MASK));
    psTcd->u16ATTR = u16Tmpreg | DMA_ATTR_DMOD(psTransfer->eDstAddrModulo) | DMA_ATTR_SMOD(psTransfer->eSrcAddrModulo);
}

/*!
 * brief Creates the eDMA channel handle.
 *
 * This function is called if using the transactional API for eDMA. This function
 * initializes the internal state of the eDMA handle.
 *
 * param base eDMA peripheral base address.
 * param psHandle eDMA handle pointer. The eDMA handle stores callback function and
 *               parameters.
 * param eChannel eDMA channel number.
 * param psTcdPool A memory pool to store TCDs. It must be 32 bytes aligned.
 * param u32TcdCount The number of TCD slots.
 * param pfCallback eDMA callback function pointer.
 * param pUserData A parameter for the callback function.
 *
 */
void EDMA_TransferCreateHandle(DMA_Type *base,
                               edma_handle_t *psHandle,
                               edma_channel_t eChannel,
                               edma_channel_tcd_t *psTcdPool,
                               uint32_t u32TcdCount,
                               edma_transfer_callback_t pfCallback,
                               void *pUserData)
{
    assert(psHandle != NULL);
    assert(eChannel < (edma_channel_t)FSL_FEATURE_EDMA_MODULE_CHANNEL);
    assert(psTcdPool != NULL);
    assert(((uint32_t)((uint8_t *)psTcdPool) & 0x1FU) == 0U);

    uint32_t u32EdmaInstance;
    uint32_t eChannelIndex;
    edma_channel_tcd_t *psTcdRegs;

    /* Zero the handle */
    (void)memset(psHandle, 0, sizeof(edma_handle_t));

    psHandle->psBase     = base;
    psHandle->eChannel   = eChannel;
    psHandle->pfCallback = pfCallback;
    psHandle->pUserData  = pUserData;
    /* Get the DMA instance number */
    u32EdmaInstance = EDMA_GetInstance(base);
    eChannelIndex =
        (EDMA_GetInstanceOffset(u32EdmaInstance) * (uint32_t)FSL_FEATURE_EDMA_MODULE_CHANNEL) + (uint32_t)eChannel;
    s_EDMAHandle[(uint8_t)eChannelIndex] = psHandle;

    /* Enable interrupt */
    (void)EnableIRQ(s_edmaIRQNumber[u32EdmaInstance][(uint8_t)eChannel]);

    /*Reset TCD registers to zero.*/
    psTcdRegs = (edma_channel_tcd_t *)(uint32_t)&psHandle->psBase->TCD[(uint8_t)eChannel];
    EDMA_TcdReset(psTcdRegs);

    /* Initialize tcd queue attribute. */
    psHandle->u8Header  = 0;
    psHandle->u8Tail    = 0;
    psHandle->u8TcdUsed = 0;
    psHandle->u8TcdSize = (uint8_t)u32TcdCount;
    psHandle->psTcdPool = psTcdPool;
}

/*!
 * brief Submits the eDMA single transfer configuration.
 *
 * Application can submit single transfer when
 * 1. channel is idle, the transfer request will be submitted to eDMA channel TCD register directly
 * 2. channel is idle, a previous transfer request is pending, the new transfer request will be submitted to the
 * installed TCD pool and linked to the pending one.
 * 3. channel is active, the transfer request will be submitted to the installed TCD pool and linked to previous one.
 *
 * note,
 * 1.Please be aware of that tcd pool maintain is unprotect by default, that is to say, the behavior of multiple task
 * trying to access the same channel is undefine, application can protect the channel by itself or overwrite
 * EDMA_ENTER_CRITICAL_SECTION/EDMA_LEAVE_CRITICAL_SECTION to have edma driver protect the TCD pool maintain.
 * 2.Since the destination major loop offset feature register is reused as scatter gather tcd address, so the two
 * features cannot be used together, if the destination major loop offset feature is used, then the transfer request
 * will be submit hardware TCD directly.
 *
 * It is suggest that application should check the return value of this function to make sure that the transfer request
 * is submitted successfully.
 *
 * param psHandle eDMA handle pointer.
 * param psTransfer pointer to user's eDMA channel configure structure, see edma_channel_transfer_config_t for detail.
 *
 * retval #kStatus_Success It means submit transfer request succeed.
 * retval #kStatus_EDMA_ChannelQueueFull It means TCD queue is full. Submit transfer request is not allowed.
 */
status_t EDMA_TransferSubmitSingleTransfer(edma_handle_t *psHandle, edma_channel_transfer_config_t *psTransfer)
{
    assert(psHandle != NULL);
    assert(psTransfer != NULL);
    assert(psHandle->psTcdPool != NULL);

    edma_channel_tcd_t *tcdRegs = (edma_channel_tcd_t *)(uint32_t)&psHandle->psBase->TCD[(uint8_t)psHandle->eChannel];
    uint16_t u16Csr;
    uint8_t u8CurrentTcd;
    uint8_t u8PreviousTcd;
    uint8_t u8NextTcd;
    uint8_t u8TmpTcdUsed;
    uint8_t u8TmpTcdSize;

    /* Check if tcd pool is full. */
    EDMA_ENTER_CRITICAL_SECTION();
    u8TmpTcdUsed = psHandle->u8TcdUsed;
    u8TmpTcdSize = psHandle->u8TcdSize;
    if (u8TmpTcdUsed >= u8TmpTcdSize)
    {
        EDMA_LEAVE_CRITICAL_SECTION();

        return kStatus_EDMA_ChannelQueueFull;
    }
    u8CurrentTcd = psHandle->u8Tail;
    psHandle->u8TcdUsed++;
    /* Calculate index of next TCD */
    u8NextTcd = u8CurrentTcd + 1U;
    if (u8NextTcd == psHandle->u8TcdSize)
    {
        u8NextTcd = 0;
    }
    /* Advance queue tail index */
    psHandle->u8Tail = u8NextTcd;
    EDMA_LEAVE_CRITICAL_SECTION();
    /* Calculate index of previous TCD */
    u8PreviousTcd = u8CurrentTcd != 0U ? u8CurrentTcd - 1U : (psHandle->u8TcdSize - 1U);
    /* convert transfer configuration to TCD */
    EDMA_TcdReset(&psHandle->psTcdPool[u8CurrentTcd]);
    EDMA_ConfigChannelSoftwareTCD(&psHandle->psTcdPool[u8CurrentTcd], psTransfer);

    /* enable scatter gather only when destination major loop offset feature is disabled */
    if (psTransfer->i32DstMajorLoopOffset == 0)
    {
        /* Link current TCD with next TCD for identification of current TCD */
        psHandle->psTcdPool[u8CurrentTcd].u32DLAST_SGA = (uint32_t)((uint8_t *)(&psHandle->psTcdPool[u8NextTcd]));
        /* Chain from previous descriptor unless tcd pool size is 1(this descriptor is its own predecessor). */
        if (u8CurrentTcd != u8PreviousTcd)
        {
            /* Enable scatter/gather feature in the previous TCD block. */
            u16Csr = psHandle->psTcdPool[u8PreviousTcd].u16CSR | ((uint16_t)DMA_CSR_ESG_MASK);
            u16Csr &= ~((uint16_t)DMA_CSR_DREQ_MASK);
            psHandle->psTcdPool[u8PreviousTcd].u16CSR = u16Csr;
            /*
                Check if the TCD block in the registers is the previous one (points to current TCD block). It
                is used to check if the previous TCD linked has been loaded in TCD register. If so, it need to
                link the TCD register in case link the current TCD with the dead chain when TCD loading occurs
                before linking the previous TCD block.
            */
            if (tcdRegs->u32DLAST_SGA == (uint32_t)((uint8_t *)(&psHandle->psTcdPool[u8CurrentTcd])))
            {
                /* Clear the DREQ bits for the dynamic scatter gather */
                tcdRegs->u16CSR |= DMA_CSR_DREQ_MASK;
                /* Enable scatter/gather also in the TCD registers. */
                u16Csr = tcdRegs->u16CSR | DMA_CSR_ESG_MASK;
                /* Must write the CSR register one-time, because the transfer maybe finish anytime. */
                tcdRegs->u16CSR = u16Csr;
                /*
                    It is very important to check the ESG bit!
                    Because this hardware design: if DONE bit is set, the ESG bit can not be set. So it can
                    be used to check if the dynamic TCD link operation is successful. If ESG bit is not set
                    and the DLAST_SGA is not the next TCD address(it means the dynamic TCD link succeed and
                    the current TCD block has been loaded into TCD registers), it means transfer has finished
                    and TCD link operation fail, so must install TCD content into TCD registers and enable
                    transfer again. And if ESG is set, it means transfer has not finished, so TCD dynamic
                    link succeed.
                */
                if (0U != (tcdRegs->u16CSR & DMA_CSR_ESG_MASK))
                {
                    tcdRegs->u16CSR &= ~(uint16_t)DMA_CSR_DREQ_MASK;
                    return kStatus_Success;
                }
                /*
                    Check whether the current TCD block is already loaded in the TCD registers. It is another
                    condition when ESG bit is not set: it means the dynamic TCD link succeeds and the current
                    TCD block has been loaded into TCD registers.
                */
                if (tcdRegs->u32DLAST_SGA == (uint32_t)((uint8_t *)(&psHandle->psTcdPool[u8NextTcd])))
                {
                    return kStatus_Success;
                }
                /*
                    If go to this, means the previous transfer finished, and the DONE bit is set.
                    So shall configure TCD registers.
                */
            }
            else if (tcdRegs->u32DLAST_SGA != 0UL)
            {
                /* The current TCD block has been linked successfully. */
                return kStatus_Success;
            }
            else
            {
                /*
                    DLAST_SGA is 0 and it means the first submit transfer, so shall configure
                    TCD registers.
                */
            }
        }
    }
    /* enable minor loop mapping if minor loop offset feature is used */
    if (((psTransfer->bEnableSrcMinorLoopOffset) || (psTransfer->bEnableDstMinorLoopOffset)))
    {
        EDMA_EnableMinorLoopMapping(psHandle->psBase, true);
    }
    /* There is no live chain, TCD block need to be installed in TCD registers. */
    EDMA_InstallChannelSoftwareTCD(psHandle->psBase, psHandle->eChannel, &psHandle->psTcdPool[u8CurrentTcd]);

    /* enable interrupt */
    EDMA_EnableChannelInterrupts(psHandle->psBase, psHandle->eChannel,
                                 psTransfer->u16EnabledInterruptMask & (uint16_t)kEDMA_ChannelErrorInterruptEnable,
                                 true);

    return kStatus_Success;
}

/*!
 * brief Submits the eDMA scatter gather transfer configurations.
 *
 * The function is target for submit loop transfer request,
 * the ring transfer request means that the transfer request TAIL is link to HEAD, such as,
 * A->B->C->D->A, or A->A
 *
 * To use the ring transfer feature, the application should allocate several transfer object, such as
 * @code
 * edma_channel_transfer_config_t transfer[2];
 * EDMA_TransferSubmitLoopTransfer(psHandle, &transfer, 2U);
 * @endcode
 * Then eDMA driver will link transfer[0] and transfer[1] to each other
 *
 * note Application should check the return value of this function to avoid transfer request
 * submit failed
 *
 * param psHandle eDMA handle pointer
 * param psTransfer pointer to user's eDMA channel configure structure, see edma_channel_transfer_config_t for detail
 * param transferLoopCount the count of the transfer ring, if loop count is 1, that means that the one will link to
 * itself.
 *
 * retval #kStatus_Success It means submit transfer request succeed
 * retval #kStatus_EDMA_ChannelBusy channel is in busy status
 * retval #kStatus_EDMA_ChannelQueueFull It means TCD pool is not len enough for the ring transfer request
 */
status_t EDMA_TransferSubmitLoopTransfer(edma_handle_t *psHandle,
                                         edma_channel_transfer_config_t *psTransfer,
                                         uint32_t transferLoopCount)
{
    assert(psTransfer != NULL);
    assert(psHandle != NULL);
    assert(psHandle->psTcdPool != NULL);

    uint32_t i = 0U;

    if (psHandle->u8TcdSize < transferLoopCount)
    {
        return kStatus_EDMA_ChannelQueueFull;
    }

    /*
     *    Check if EDMA channel is busy:
     *    1. if channel active bit is set, it implies that minor loop is executing, then channel is busy
     *    2. if channel active bit is not set and BITER not equal to CITER, it implies that major loop is executing,
     *       then channel is busy
     *
     *    There is one case can not be covered in below condition:
     *    When transfer request is submitted, but no request from peripheral, that is to say channel service doesn't
     *    begin, if application would like to submit another transfer , then the TCD will be overwritten, since the
     *    ACTIVE is 0 and BITER = CITER, for such case, it is a scatter gather(link TCD) case actually, so
     *    application should enabled TCD pool for dynamic scatter gather mode by calling EDMA_InstallTCDMemory.
     */
    if (((psHandle->psBase->TCD[(uint8_t)psHandle->eChannel].CSR & DMA_CSR_ACTIVE_MASK) != 0U) ||
        (((psHandle->psBase->TCD[(uint8_t)psHandle->eChannel].CITER_ELINKNO & DMA_CITER_ELINKNO_CITER_MASK) !=
          (psHandle->psBase->TCD[(uint8_t)psHandle->eChannel].BITER_ELINKNO & DMA_BITER_ELINKNO_BITER_MASK))))
    {
        return kStatus_EDMA_ChannelBusy;
    }

    (void)memset(psHandle->psTcdPool, 0, psHandle->u8TcdSize * sizeof(edma_channel_tcd_t));

    for (i = 0U; i < transferLoopCount - 1UL; i++)
    {
        psTransfer[i].psLinkTCD = &psHandle->psTcdPool[i + 1UL];
        EDMA_ConfigChannelSoftwareTCD(&(psHandle->psTcdPool[i]), &psTransfer[i]);
    }

    /* prepare last one in the ring and link it to the HEAD of the ring */
    psTransfer[i].psLinkTCD = &psHandle->psTcdPool[0];
    EDMA_ConfigChannelSoftwareTCD(&(psHandle->psTcdPool[i]), &psTransfer[i]);
    if (((psTransfer->bEnableSrcMinorLoopOffset) || (psTransfer->bEnableDstMinorLoopOffset)))
    {
        EDMA_EnableMinorLoopMapping(psHandle->psBase, true);
    }
    /* There is no live chain, TCD block need to be installed in TCD registers. */
    EDMA_InstallChannelSoftwareTCD(psHandle->psBase, psHandle->eChannel, &psHandle->psTcdPool[0U]);

    /* enable interrupt */
    EDMA_EnableChannelInterrupts(psHandle->psBase, psHandle->eChannel,
                                 psTransfer->u16EnabledInterruptMask & (uint16_t)kEDMA_ChannelErrorInterruptEnable,
                                 true);

    return kStatus_Success;
}

/*!
 * brief eDMA starts transfer.
 *
 * This function enables the channel request. Users can call this function after submitting the transfer request
 * or before submitting the transfer request.
 *
 * param psHandle eDMA handle pointer.
 */
void EDMA_TransferStart(edma_handle_t *psHandle)
{
    assert(psHandle != NULL);
    uint32_t u32TmpCSR = 0;

    edma_channel_tcd_t *psTcdRegs = (edma_channel_tcd_t *)(uint32_t)&psHandle->psBase->TCD[(uint8_t)psHandle->eChannel];

    /* Check if channel request is actually disable. */
    if ((psHandle->psBase->ERQ & (1UL << ((uint8_t)psHandle->eChannel))) == 0U)
    {
        /* Check if transfer is paused. */
        u32TmpCSR = psTcdRegs->u16CSR;
        if ((0U == (u32TmpCSR & DMA_CSR_DONE_MASK)) || (0U != (u32TmpCSR & DMA_CSR_ESG_MASK)))
        {
            /*
                Re-enable channel request must be as soon as possible, so must put it into
                critical section to avoid task switching or interrupt service routine.
            */
            psHandle->psBase->SERQ = DMA_SERQ_SERQ(psHandle->eChannel);
        }
    }
}

/*!
 * brief eDMA stops transfer.
 *
 * This function disables the channel request to pause the transfer. Users can call EDMA_StartTransfer()
 * again to resume the transfer.
 *
 * param psHandle eDMA handle pointer.
 */
void EDMA_TransferStop(edma_handle_t *psHandle)
{
    assert(psHandle != NULL);

    psHandle->psBase->CERQ = DMA_CERQ_CERQ(psHandle->eChannel);
}

/*!
 * brief eDMA aborts transfer.
 *
 * This function disables the channel request and clear transfer status bits.
 * Users can submit another transfer after calling this API.
 *
 * param psHandle DMA handle pointer.
 */
void EDMA_TransferAbort(edma_handle_t *psHandle)
{
    psHandle->psBase->CERQ = DMA_CERQ_CERQ(psHandle->eChannel);
    /*
        Clear CSR to release channel. Because if the given channel started transfer,
        CSR will be not zero. Because if it is the last transfer, DREQ will be set.
        If not, ESG will be set.
    */
    psHandle->psBase->TCD[(uint8_t)psHandle->eChannel].CSR = 0;
    /* Cancel all next TCD transfer. */
    psHandle->psBase->TCD[(uint8_t)psHandle->eChannel].DLAST_SGA = 0;

    psHandle->u8Header  = 0;
    psHandle->u8Tail    = 0;
    psHandle->u8TcdUsed = 0;
}

/*!
 * brief eDMA IRQ handler for the current major loop transfer completion.
 *
 * This function clears the channel major interrupt flag and calls
 * the callback function if it is not NULL.
 *
 * Note:
 * For the case using TCD queue, when the major iteration count is exhausted, additional Interfaces are performed.
 * These include the final address adjustments and reloading of the BITER field into the CITER.
 * Assertion of an optional interrupt request also occurs at this time, as does a possible fetch of a new TCD from
 * memory using the scatter/gather address pointer included in the descriptor (if scatter/gather is enabled).
 *
 * For instance, when the time interrupt of TCD[0] happens, the TCD[1] has already been loaded into the eDMA engine.
 * As sga and sga_index are calculated based on the DLAST_SGA bit field lies in the TCD_CSR register, the sga_index
 * in this case should be 2 (DLAST_SGA of TCD[1] stores the address of TCD[2]). Thus, the "tcdUsed" updated should be
 * (tcdUsed - 2U) which indicates the number of TCDs can be loaded in the memory pool (because TCD[0] and TCD[1] have
 * been loaded into the eDMA engine at this point already.).
 *
 * For the last two continuous ISRs in a scatter/gather process, they  both load the last TCD (The last ISR does not
 * load a new TCD) from the memory pool to the eDMA engine when major loop completes.
 * Therefore, ensure that the header and tcdUsed updated are identical for them.
 * tcdUsed are both 0 in this case as no TCD to be loaded.
 *
 * See the "eDMA basic data flow" in the eDMA Functional description section of the Reference Manual for
 * further details.
 *
 * param psHandle eDMA handle pointer.
 */
void EDMA_TransferHandleIRQ(edma_handle_t *psHandle)
{
    assert(psHandle != NULL);

    bool bTransferDone;

    /* Clear EDMA interrupt flag */
    psHandle->psBase->CINT = (uint8_t)psHandle->eChannel;
    /* Check if transfer is already finished. */
    bTransferDone = ((psHandle->psBase->TCD[(uint8_t)psHandle->eChannel].CSR & DMA_CSR_DONE_MASK) != 0U);

    uint32_t u32Sga = (uint32_t)psHandle->psBase->TCD[(uint8_t)psHandle->eChannel].DLAST_SGA;
    uint32_t u32SgaIndex;
    int32_t i32TcdsDone;
    uint8_t u8NewHeader;

    /* Get the offset of the next transfer TCD blocks to be loaded into the eDMA engine. */
    u32Sga -= (uint32_t)(uint8_t *)psHandle->psTcdPool;
    /* Get the index of the next transfer TCD blocks to be loaded into the eDMA engine. */
    u32SgaIndex = (uint32_t)(u32Sga / sizeof(edma_channel_tcd_t));
    /* Adjust header positions. */
    if (bTransferDone)
    {
        /* New header shall point to the next TCD to be loaded (current one is already finished) */
        u8NewHeader = (uint8_t)u32SgaIndex;
    }
    else
    {
        /* New header shall point to this descriptor currently loaded (not finished yet) */
        u8NewHeader = u32SgaIndex != 0U ? (uint8_t)u32SgaIndex - 1U : (uint8_t)psHandle->u8TcdSize - 1U;
    }
    /* Calculate the number of finished TCDs */
    if (u8NewHeader == (uint8_t)psHandle->u8Header)
    {
        uint8_t u8TmpTcdUsed = psHandle->u8TcdUsed;
        uint8_t u8TmpTcdSize = psHandle->u8TcdSize;

        if (u8TmpTcdUsed == u8TmpTcdSize)
        {
            i32TcdsDone = (int32_t)psHandle->u8TcdUsed;
        }
        else
        {
            /* No TCD in the memory are going to be loaded or internal error occurs. */
            i32TcdsDone = 0;
        }
    }
    else
    {
        i32TcdsDone = (int32_t)u8NewHeader - (int32_t)psHandle->u8Header;
        if (i32TcdsDone < 0)
        {
            i32TcdsDone += (int32_t)psHandle->u8TcdSize;
        }
    }
    /* Advance header which points to the TCD to be loaded into the eDMA engine from memory. */
    psHandle->u8Header = u8NewHeader;
    /* Release TCD blocks. tcdUsed is the TCD number which can be used/loaded in the memory pool. */
    psHandle->u8TcdUsed -= (uint8_t)i32TcdsDone;
    /* Invoke callback function. */
    if (NULL != psHandle->pfCallback)
    {
        (psHandle->pfCallback)(psHandle, psHandle->pUserData, bTransferDone, i32TcdsDone);
    }

    /* clear the DONE bit here is meaningful for below cases:
     *1.A new TCD has been loaded to EDMA already:
     * need to clear the DONE bit in the IRQ psHandler to avoid TCD in EDMA been overwritten
     * if peripheral request isn't coming before next transfer request.
     *2.A new TCD has not been loaded to EDMA:
     * for the case that transfer request occurs in the previous edma callback, this is a case that doesn't
     * need scatter gather, so keep DONE bit during the next transfer request will re-install the TCD.
     */
    if (bTransferDone)
    {
        psHandle->psBase->CDNE = (uint8_t)psHandle->eChannel;
    }
}

void DMACH0_DriverIRQHandler(void);
void DMACH0_DriverIRQHandler(void)
{
    EDMA_TransferHandleIRQ(s_EDMAHandle[0]);
}
void DMA0_DriverIRQHandler(void);
void DMA0_DriverIRQHandler(void)
{
    EDMA_TransferHandleIRQ(s_EDMAHandle[0]);
}

void DMACH1_DriverIRQHandler(void);
void DMACH1_DriverIRQHandler(void)
{
    EDMA_TransferHandleIRQ(s_EDMAHandle[1]);
}
void DMA1_DriverIRQHandler(void);
void DMA1_DriverIRQHandler(void)
{
    EDMA_TransferHandleIRQ(s_EDMAHandle[1]);
}

void DMACH2_DriverIRQHandler(void);
void DMACH2_DriverIRQHandler(void)
{
    EDMA_TransferHandleIRQ(s_EDMAHandle[2]);
}
void DMA2_DriverIRQHandler(void);
void DMA2_DriverIRQHandler(void)
{
    EDMA_TransferHandleIRQ(s_EDMAHandle[2]);
}

void DMACH3_DriverIRQHandler(void);
void DMACH3_DriverIRQHandler(void)
{
    EDMA_TransferHandleIRQ(s_EDMAHandle[3]);
}
void DMA3_DriverIRQHandler(void);
void DMA3_DriverIRQHandler(void)
{
    EDMA_TransferHandleIRQ(s_EDMAHandle[3]);
}
