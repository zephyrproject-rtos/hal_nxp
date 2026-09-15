/*
 * Copyright 2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_edma.h"
#include "fsl_edma_soc.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.dsc_edma3"
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

/*!
 * @brief Resets a channel's hardware TCD registers to zero.
 *
 * @param base eDMA peripheral base address.
 * @param eChannel eDMA channel number.
 */
static void EDMA_ResetChannelTCD(DMA_Type *base, edma_channel_t eChannel);

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*! @brief Array to map EDMA instance number to base pointer. */
static DMA_Type *const s_edmaBases[] = DMA_BASE_PTRS;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/*! @brief Array to map EDMA instance number to clock name. */
static const clock_ip_name_t s_edmaClockName[] = EDMA_CLOCKS;
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

/*! @brief Array to map EDMA instance number to IRQ number (4 shared IRQs per instance). */
static const IRQn_Type s_edmaIRQNumber[][EDMA_IRQ_COUNT_PER_INSTANCE] = EDMA_CHN_IRQS;

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
#elif defined(eDMA0)
    u8StartInstanceNum = (uint8_t)EDMA_GetInstance(eDMA0);
#elif defined(eDMA1)
    u8StartInstanceNum = (uint8_t)EDMA_GetInstance(eDMA1);
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

static void EDMA_ResetChannelTCD(DMA_Type *base, edma_channel_t eChannel)
{
    assert(eChannel < (edma_channel_t)FSL_FEATURE_EDMA_MODULE_CHANNEL);

    base->CH[(uint8_t)eChannel].TCD_SADDR         = 0U;
    base->CH[(uint8_t)eChannel].TCD_SOFF          = 0U;
    base->CH[(uint8_t)eChannel].TCD_ATTR          = 0U;
    base->CH[(uint8_t)eChannel].TCD_NBYTES_MLOFFNO = 0U;
    base->CH[(uint8_t)eChannel].TCD_SLAST_SDA     = 0U;
    base->CH[(uint8_t)eChannel].TCD_DADDR         = 0U;
    base->CH[(uint8_t)eChannel].TCD_DOFF          = 0U;
    base->CH[(uint8_t)eChannel].TCD_CITER_ELINKNO = 0U;
    base->CH[(uint8_t)eChannel].TCD_DLAST_SGA     = 0U;
    base->CH[(uint8_t)eChannel].TCD_CSR           = 0U;
    base->CH[(uint8_t)eChannel].TCD_BITER_ELINKNO = 0U;
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

    psConfig->eArbitrationType         = kEDMA_ArbitrationFixedPriority;
    psConfig->bEnableHaltOnError       = true;
    psConfig->bEnableDmaInDebugMode    = false;
    psConfig->bEnableGlobalChannelLink = true;

    for (i = 0U; i < (uint32_t)FSL_FEATURE_EDMA_MODULE_CHANNEL; i++)
    {
        psConfig->sChannelPreemptionConfig[i].bSuspendedByHighPriorityChannel = false;
        psConfig->sChannelPreemptionConfig[i].bSuspendLowPriorityChannel      = false;
        psConfig->sChannelPreemptionConfig[i].u8ChannelPriority               = (uint8_t)(i & 0x7U);
        psConfig->sChannelPreemptionConfig[i].u8GroupPriority                 = (uint8_t)i;
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

    /* Clear all the enabled request, status to make sure EDMA status is in normal condition */
    for (i = 0U; i < (uint32_t)FSL_FEATURE_EDMA_MODULE_CHANNEL; i++)
    {
        /* Disable channel request */
        base->CH[i].CH_CSR &= ~DMA_CH_CSR_ERQ_MASK;
        /* Clear interrupt status (W1C) */
        base->CH[i].CH_INT = DMA_CH_INT_INT_MASK;
        /* Clear error status (W1C) */
        base->CH[i].CH_ES = DMA_CH_ES_ERR_MASK;
        /* Clear DONE status (W1C) */
        base->CH[i].CH_CSR |= DMA_CH_CSR_DONE_MASK;
    }

    /* Configure EDMA peripheral according to the configuration structure. */
    u32tmpCSR = base->MP_CSR;
    u32tmpCSR &= ~(DMA_MP_CSR_ERCA_MASK | DMA_MP_CSR_HAE_MASK | DMA_MP_CSR_EDBG_MASK | DMA_MP_CSR_GCLC_MASK);
    u32tmpCSR |= (DMA_MP_CSR_ERCA(psConfig->eArbitrationType) | DMA_MP_CSR_HAE(psConfig->bEnableHaltOnError) |
                  DMA_MP_CSR_EDBG(psConfig->bEnableDmaInDebugMode) |
                  DMA_MP_CSR_GCLC(psConfig->bEnableGlobalChannelLink));
    base->MP_CSR = u32tmpCSR;

    /* Channel preemption configuration */
    if (psConfig->eArbitrationType == kEDMA_ArbitrationFixedPriority)
    {
        for (i = 0U; i < (uint32_t)FSL_FEATURE_EDMA_MODULE_CHANNEL; i++)
        {
            EDMA_SetChannelPreemption(base, (edma_channel_t)i,
                                      psConfig->sChannelPreemptionConfig[i].bSuspendedByHighPriorityChannel,
                                      psConfig->sChannelPreemptionConfig[i].bSuspendLowPriorityChannel,
                                      psConfig->sChannelPreemptionConfig[i].u8ChannelPriority);
            /* Set group priority */
            base->CH_GRPRI[(uint8_t)i] = DMA_CH_GRPRI_GRPRI(psConfig->sChannelPreemptionConfig[i].u8GroupPriority);
        }
    }

    /* Channel transfer configuration */
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
    /* Gate EDMA peripheral clock */
    CLOCK_DisableClock(s_edmaClockName[EDMA_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

/*!
 * brief Get channel default transfer configuration.
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
 */
void EDMA_SetChannelTransferConfig(DMA_Type *base, edma_channel_t eChannel, edma_channel_transfer_config_t *psTransfer)
{
    assert(eChannel < (edma_channel_t)FSL_FEATURE_EDMA_MODULE_CHANNEL);
    assert(psTransfer != NULL);

    edma_channel_tcd_t tcdOnStack;

    /* Reset TCD registers to zero. */
    EDMA_ResetChannelTCD(base, eChannel);

    /* Use a local stack TCD, configure it, then install to hardware */
    (void)memset(&tcdOnStack, 0, sizeof(edma_channel_tcd_t));
    /* Note: tcdOnStack is on stack, skip alignment assertion for software TCD */
    EDMA_ConfigChannelSoftwareTCD(&tcdOnStack, psTransfer);
    EDMA_InstallChannelSoftwareTCD(base, eChannel, &tcdOnStack);

    EDMA_EnableChannelInterrupts(
        base, eChannel, psTransfer->u16EnabledInterruptMask & (uint16_t)kEDMA_ChannelErrorInterruptEnable, true);
    EDMA_EnableChannelRequest(base, eChannel, psTransfer->bEnableChannelRequest);
}

/*!
 * brief Gets the eDMA channel status flags.
 */
uint16_t EDMA_GetChannelStatusFlags(DMA_Type *base, edma_channel_t eChannel)
{
    assert(eChannel < (edma_channel_t)FSL_FEATURE_EDMA_MODULE_CHANNEL);

    uint16_t retval = 0;

    /* Get DONE bit flag from CH_CSR */
    if ((base->CH[(uint8_t)eChannel].CH_CSR & DMA_CH_CSR_DONE_MASK) != 0U)
    {
        retval |= (uint16_t)kEDMA_ChannelStatusMajorLoopCompleteFlag;
    }
    else
    {
        /* Get interrupt status from CH_INT */
        if ((base->CH[(uint8_t)eChannel].CH_INT & DMA_CH_INT_INT_MASK) != 0U)
        {
            retval |= (uint16_t)kEDMA_ChannelStatusMajorLoopHalfCompleteFlag;
        }
    }

    /* Get ERROR bit flag from CH_ES */
    if ((base->CH[(uint8_t)eChannel].CH_ES & DMA_CH_ES_ERR_MASK) != 0U)
    {
        retval |= (uint16_t)kEDMA_ChannelStatusErrorFlag;
    }

    return retval;
}

/*!
 * brief Clears the eDMA channel status flags.
 */
void EDMA_ClearChannelStatusFlags(DMA_Type *base, edma_channel_t eChannel, uint16_t u16StatusFlags)
{
    assert(eChannel < (edma_channel_t)FSL_FEATURE_EDMA_MODULE_CHANNEL);

    /* Clear complete status bit flag (DONE is W1C in CH_CSR, INT is W1C in CH_INT) */
    if (0U != (u16StatusFlags & (uint16_t)kEDMA_ChannelStatusMajorLoopCompleteFlag))
    {
        base->CH[(uint8_t)eChannel].CH_CSR |= DMA_CH_CSR_DONE_MASK;
        base->CH[(uint8_t)eChannel].CH_INT = DMA_CH_INT_INT_MASK;
    }
    /* Clear ERROR bit flag (ERR is W1C in CH_ES) */
    if (0U != (u16StatusFlags & (uint16_t)kEDMA_ChannelStatusErrorFlag))
    {
        base->CH[(uint8_t)eChannel].CH_ES = DMA_CH_ES_ERR_MASK;
    }
    /* Clear half complete status flag (INT is W1C in CH_INT) */
    if (0U != (u16StatusFlags & (uint16_t)kEDMA_ChannelStatusMajorLoopHalfCompleteFlag))
    {
        base->CH[(uint8_t)eChannel].CH_INT = DMA_CH_INT_INT_MASK;
    }
}

/*!
 * brief Configures the eDMA channel minor loop offset value.
 */
void EDMA_SetChannelMinorLoopOffset(DMA_Type *base,
                                    edma_channel_t eChannel,
                                    bool bEnableSrcMinorLoopOffset,
                                    bool bEnableDestMinorLoopOffset,
                                    int32_t i32MinorLoopOffset)
{
    assert(eChannel < (edma_channel_t)FSL_FEATURE_EDMA_MODULE_CHANNEL);

    uint32_t u32Tmpreg;

    u32Tmpreg = base->CH[(uint8_t)eChannel].TCD_NBYTES_MLOFFYES;
    u32Tmpreg &= ~(DMA_TCD_NBYTES_MLOFFYES_SMLOE_MASK | DMA_TCD_NBYTES_MLOFFYES_DMLOE_MASK |
                   DMA_TCD_NBYTES_MLOFFYES_MLOFF_MASK);
    u32Tmpreg |= (DMA_TCD_NBYTES_MLOFFYES_SMLOE(bEnableSrcMinorLoopOffset) |
                  DMA_TCD_NBYTES_MLOFFYES_DMLOE(bEnableDestMinorLoopOffset) |
                  DMA_TCD_NBYTES_MLOFFYES_MLOFF(i32MinorLoopOffset));
    base->CH[(uint8_t)eChannel].TCD_NBYTES_MLOFFYES = u32Tmpreg;
}

/*!
 * brief Configures the eDMA channel major loop offset feature.
 */
void EDMA_SetChannelMajorLoopOffset(DMA_Type *base,
                                    edma_channel_t eChannel,
                                    int32_t i32SourceOffset,
                                    int32_t i32DestOffset)
{
    assert(eChannel < (edma_channel_t)FSL_FEATURE_EDMA_MODULE_CHANNEL);

    base->CH[(uint8_t)eChannel].TCD_SLAST_SDA = (uint32_t)i32SourceOffset;
    base->CH[(uint8_t)eChannel].TCD_DLAST_SGA = (uint32_t)i32DestOffset;
}

/*!
 * brief Configures the eDMA channel preemption configurations.
 */
void EDMA_SetChannelPreemption(DMA_Type *base,
                               edma_channel_t eChannel,
                               bool bSuspendedByHighPriorityChannel,
                               bool bSuspendLowPriorityChannel,
                               uint8_t u8Priority)
{
    assert(eChannel < (edma_channel_t)FSL_FEATURE_EDMA_MODULE_CHANNEL);
    /* CH_PRI.APL is 3 bits wide, a larger value would be truncated silently */
    assert(u8Priority <= (uint8_t)DMA_CH_PRI_APL_MASK);

    uint32_t u32Reg;

    u32Reg = DMA_CH_PRI_APL(u8Priority) |
             DMA_CH_PRI_DPA((true == bSuspendLowPriorityChannel ? 0U : 1U)) |
             DMA_CH_PRI_ECP((true == bSuspendedByHighPriorityChannel ? 1U : 0U));

    base->CH[(uint8_t)eChannel].CH_PRI = u32Reg;
}

/*!
 * brief Enable the major loop channel link and configure the linked channel number.
 */
void EDMA_EnableMajorLoopChannelLink(DMA_Type *base, edma_channel_t eChannel, edma_channel_t eLinkChannel)
{
    uint16_t tmpreg;

    tmpreg = base->CH[(uint8_t)eChannel].TCD_CSR & (~(uint16_t)DMA_TCD_CSR_MAJORLINKCH_MASK);
    base->CH[(uint8_t)eChannel].TCD_CSR = tmpreg | DMA_TCD_CSR_MAJORLINKCH(eLinkChannel) | DMA_TCD_CSR_MAJORELINK_MASK;
}

/*!
 * brief Enable the minor loop channel link and configure the linked channel number.
 */
void EDMA_EnableMinorLoopChannelLink(DMA_Type *base, edma_channel_t eChannel, edma_channel_t eLinkChannel)
{
    uint16_t tmpreg;

    tmpreg = base->CH[(uint8_t)eChannel].TCD_CITER_ELINKYES & (~(uint16_t)DMA_TCD_CITER_ELINKYES_LINKCH_MASK);
    tmpreg |= DMA_TCD_CITER_ELINKYES_LINKCH(eLinkChannel);
    base->CH[(uint8_t)eChannel].TCD_CITER_ELINKYES = tmpreg | DMA_TCD_CITER_ELINKYES_ELINK_MASK;
    tmpreg = base->CH[(uint8_t)eChannel].TCD_BITER_ELINKYES & (~(uint16_t)DMA_TCD_BITER_ELINKYES_LINKCH_MASK);
    tmpreg |= DMA_TCD_BITER_ELINKYES_LINKCH(eLinkChannel);
    base->CH[(uint8_t)eChannel].TCD_BITER_ELINKYES = tmpreg | DMA_TCD_BITER_ELINKYES_ELINK_MASK;
}

/*!
 * brief Sets the edma channel stall cycles after each R/W.
 */
void EDMA_SetChannelBandWidth(DMA_Type *base, edma_channel_t eChannel, edma_channel_bandwidth_t eBandWidth)
{
    assert(eChannel < (edma_channel_t)FSL_FEATURE_EDMA_MODULE_CHANNEL);

    base->CH[(uint8_t)eChannel].TCD_CSR =
        (uint16_t)((base->CH[(uint8_t)eChannel].TCD_CSR & (~DMA_TCD_CSR_BWC_MASK)) | DMA_TCD_CSR_BWC(eBandWidth));
}

/*!
 * brief Sets the source address range and the destination address range for the eDMA transfer.
 */
void EDMA_SetChannelModulo(DMA_Type *base,
                           edma_channel_t eChannel,
                           edma_channel_modulo_t eSrcModulo,
                           edma_channel_modulo_t eDestModulo)
{
    assert(eChannel < (edma_channel_t)FSL_FEATURE_EDMA_MODULE_CHANNEL);

    uint16_t u16Tmpreg;

    u16Tmpreg = base->CH[(uint8_t)eChannel].TCD_ATTR &
                (~(uint16_t)(DMA_TCD_ATTR_SMOD_MASK | DMA_TCD_ATTR_DMOD_MASK));
    base->CH[(uint8_t)eChannel].TCD_ATTR = u16Tmpreg | DMA_TCD_ATTR_DMOD(eDestModulo) | DMA_TCD_ATTR_SMOD(eSrcModulo);
}

/*!
 * brief Enables the edma channel interrupts according to a provided mask.
 */
void EDMA_EnableChannelInterrupts(DMA_Type *base, edma_channel_t eChannel, uint16_t u16InterruptsMask, bool bEnable)
{
    assert(eChannel < (edma_channel_t)FSL_FEATURE_EDMA_MODULE_CHANNEL);

    /* Enable/disable error interrupt via CH_CSR.EEI */
    if (0U != (u16InterruptsMask & (uint16_t)kEDMA_ChannelErrorInterruptEnable))
    {
        if (bEnable)
        {
            base->CH[(uint8_t)eChannel].CH_CSR |= DMA_CH_CSR_EEI_MASK;
        }
        else
        {
            base->CH[(uint8_t)eChannel].CH_CSR &= ~DMA_CH_CSR_EEI_MASK;
        }
    }
    else
    {
        uint16_t u16TempReg = base->CH[(uint8_t)eChannel].TCD_CSR;
        /* Enable/disable complete(major) interrupt */
        if (0U != (u16InterruptsMask & (uint32_t)kEDMA_ChannelMajorLoopCompleteInterruptEnable))
        {
            u16TempReg &= ~(uint16_t)DMA_TCD_CSR_INTMAJOR_MASK;
            u16TempReg |= bEnable ? DMA_TCD_CSR_INTMAJOR_MASK : 0U;
        }

        /* Enable/disable half complete(half major) interrupt */
        if (0U != (u16InterruptsMask & (uint32_t)kEDMA_ChannelMajorLoopHalfCompleteInterruptEnable))
        {
            u16TempReg &= ~(uint16_t)DMA_TCD_CSR_INTHALF_MASK;
            u16TempReg |= bEnable ? DMA_TCD_CSR_INTHALF_MASK : 0U;
        }

        base->CH[(uint8_t)eChannel].TCD_CSR = u16TempReg;
    }
}

/*!
 * brief Gets the remaining major loop count from the eDMA current channel TCD.
 */
uint32_t EDMA_GetChannelRemainingMajorLoopCount(DMA_Type *base, edma_channel_t eChannel)
{
    assert(eChannel < (edma_channel_t)FSL_FEATURE_EDMA_MODULE_CHANNEL);

    uint32_t u32RemainingCount = 0;

    if (0U != (DMA_CH_CSR_DONE_MASK & base->CH[(uint8_t)eChannel].CH_CSR))
    {
        u32RemainingCount = 0;
    }
    else
    {
        /* Calculate the unfinished bytes */
        if (0U != (base->CH[(uint8_t)eChannel].TCD_CITER_ELINKNO & DMA_TCD_CITER_ELINKNO_ELINK_MASK))
        {
            u32RemainingCount =
                (((uint32_t)base->CH[(uint8_t)eChannel].TCD_CITER_ELINKYES & DMA_TCD_CITER_ELINKYES_CITER_MASK) >>
                 DMA_TCD_CITER_ELINKYES_CITER_SHIFT);
        }
        else
        {
            u32RemainingCount =
                (((uint32_t)base->CH[(uint8_t)eChannel].TCD_CITER_ELINKNO & DMA_TCD_CITER_ELINKNO_CITER_MASK) >>
                 DMA_TCD_CITER_ELINKNO_CITER_SHIFT);
        }
    }

    return u32RemainingCount;
}

/*!
 * brief Push content of TCD structure into hardware TCD register.
 */
void EDMA_InstallChannelSoftwareTCD(DMA_Type *base, edma_channel_t eChannel, edma_channel_tcd_t *psTcd)
{
    assert(eChannel < (edma_channel_t)FSL_FEATURE_EDMA_MODULE_CHANNEL);
    assert(psTcd != NULL);

    /* Push tcd into hardware TCD registers */
    base->CH[(uint8_t)eChannel].TCD_SADDR         = psTcd->u32SADDR;
    base->CH[(uint8_t)eChannel].TCD_SOFF          = psTcd->u16SOFF;
    base->CH[(uint8_t)eChannel].TCD_ATTR          = psTcd->u16ATTR;
    base->CH[(uint8_t)eChannel].TCD_NBYTES_MLOFFNO = psTcd->u32NBYTES;
    base->CH[(uint8_t)eChannel].TCD_SLAST_SDA     = psTcd->u32SLAST;
    base->CH[(uint8_t)eChannel].TCD_DADDR         = psTcd->u32DADDR;
    base->CH[(uint8_t)eChannel].TCD_DOFF          = psTcd->u16DOFF;
    base->CH[(uint8_t)eChannel].TCD_CITER_ELINKNO = psTcd->u16CITER;
    base->CH[(uint8_t)eChannel].TCD_DLAST_SGA     = psTcd->u32DLAST_SGA;
    /* Clear DONE bit first, otherwise ESG cannot be set */
    base->CH[(uint8_t)eChannel].TCD_CSR           = 0;
    base->CH[(uint8_t)eChannel].TCD_CSR           = psTcd->u16CSR;
    base->CH[(uint8_t)eChannel].TCD_BITER_ELINKNO = psTcd->u16BITER;
}

/*!
 * brief Sets TCD fields according to the user's channel transfer configuration structure.
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
    psTcd->u16ATTR = DMA_TCD_ATTR_SSIZE(psTransfer->eSrcWidthOfEachTransfer) |
                     DMA_TCD_ATTR_DSIZE(psTransfer->eDstWidthOfEachTransfer);

    /* Source address signed offset */
    psTcd->u16SOFF = (uint16_t)(psTransfer->i16SrcOffsetOfEachTransfer);
    /* Destination address signed offset */
    psTcd->u16DOFF = (uint16_t)(psTransfer->i16DstOffsetOfEachTransfer);

    /* Minor loop offset - in eDMA3, minor loop mapping is always available */
    if (((psTransfer->bEnableSrcMinorLoopOffset) || (psTransfer->bEnableDstMinorLoopOffset)))
    {
        psTcd->u32NBYTES = DMA_TCD_NBYTES_MLOFFYES_NBYTES(psTransfer->u32BytesEachMinorLoop) |
                           DMA_TCD_NBYTES_MLOFFYES_MLOFF(psTransfer->i32MinorLoopOffset) |
                           DMA_TCD_NBYTES_MLOFFYES_DMLOE(psTransfer->bEnableDstMinorLoopOffset) |
                           DMA_TCD_NBYTES_MLOFFYES_SMLOE(psTransfer->bEnableSrcMinorLoopOffset);
    }
    else
    {
        psTcd->u32NBYTES = DMA_TCD_NBYTES_MLOFFNO_NBYTES(psTransfer->u32BytesEachMinorLoop);
    }

    /* Current major iteration count */
    psTcd->u16CITER = (uint16_t)(psTransfer->u16MinorLoopCountsEachMajorLoop);
    /* Starting major iteration count */
    psTcd->u16BITER = (uint16_t)(psTransfer->u16MinorLoopCountsEachMajorLoop);
    /* Enable scatter/gather processing */
    if (psTransfer->psLinkTCD != NULL)
    {
        psTcd->u32DLAST_SGA = (uint32_t)((uint8_t *)psTransfer->psLinkTCD);

        psTcd->u16CSR |= (uint16_t)DMA_TCD_CSR_ESG_MASK;
    }
    else
    {
        psTcd->u16CSR &= ~(uint16_t)DMA_TCD_CSR_ESG_MASK;
        psTcd->u32DLAST_SGA = (uint32_t)psTransfer->i32DstMajorLoopOffset;
    }

    /* configure bandwidth/interrupt/auto disable channel request */
    psTcd->u16CSR |= (psTcd->u16CSR & (~(uint16_t)(DMA_TCD_CSR_DREQ_MASK | DMA_TCD_CSR_BWC_MASK))) |
                     DMA_TCD_CSR_BWC(psTransfer->eChannelBandWidth) |
                     DMA_TCD_CSR_DREQ(psTransfer->bDisableRequestAfterMajorLoopComplete) |
                     (psTransfer->u16EnabledInterruptMask & (~(uint16_t)kEDMA_ChannelErrorInterruptEnable));

    /* Minor link config */
    if (psTransfer->bEnableChannelMinorLoopLink)
    {
        uint16_t tmpreg;

        /* Enable minor link */
        psTcd->u16CITER |= DMA_TCD_CITER_ELINKYES_ELINK_MASK;
        psTcd->u16BITER |= DMA_TCD_BITER_ELINKYES_ELINK_MASK;
        /* Set linked channel */
        tmpreg = psTcd->u16CITER & (~(uint16_t)DMA_TCD_CITER_ELINKYES_LINKCH_MASK);
        tmpreg |= DMA_TCD_CITER_ELINKYES_LINKCH(psTransfer->eMinorLoopLinkChannel);
        psTcd->u16CITER = tmpreg;
        tmpreg          = psTcd->u16BITER & (~(uint16_t)DMA_TCD_BITER_ELINKYES_LINKCH_MASK);
        tmpreg |= DMA_TCD_BITER_ELINKYES_LINKCH(psTransfer->eMinorLoopLinkChannel);
        psTcd->u16BITER = tmpreg;
    }
    /* Major link config */
    if (psTransfer->bEnableChannelMajorLoopLink)
    {
        uint16_t tmpreg;

        /* Enable major link */
        psTcd->u16CSR |= DMA_TCD_CSR_MAJORELINK_MASK;
        /* Set major linked channel */
        tmpreg        = psTcd->u16CSR & (~(uint16_t)DMA_TCD_CSR_MAJORLINKCH_MASK);
        psTcd->u16CSR = tmpreg | DMA_TCD_CSR_MAJORLINKCH(psTransfer->eMajorLoopLinkChannel);
    }
    /* clear link relate field if no channel link enabled */
    if ((!psTransfer->bEnableChannelMajorLoopLink) && (!psTransfer->bEnableChannelMinorLoopLink))
    {
        psTcd->u16CITER &= ~(uint16_t)DMA_TCD_CITER_ELINKYES_ELINK_MASK;
        psTcd->u16BITER &= ~(uint16_t)DMA_TCD_BITER_ELINKYES_ELINK_MASK;
        psTcd->u16CSR &= ~(uint16_t)DMA_TCD_CSR_MAJORELINK_MASK;
    }

    /* major loop offset */
    psTcd->u32SLAST = (uint32_t)psTransfer->i32SrcMajorLoopOffset;
    /* modulo feature */
    u16Tmpreg = psTcd->u16ATTR & (~(uint16_t)(DMA_TCD_ATTR_SMOD_MASK | DMA_TCD_ATTR_DMOD_MASK));
    psTcd->u16ATTR =
        u16Tmpreg | DMA_TCD_ATTR_DMOD(psTransfer->eDstAddrModulo) | DMA_TCD_ATTR_SMOD(psTransfer->eSrcAddrModulo);
}

/*!
 * brief Creates the eDMA channel handle.
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

    /* Enable interrupt - map channel to shared IRQ using modulo */
    (void)EnableIRQ(s_edmaIRQNumber[u32EdmaInstance][(uint8_t)eChannel & (EDMA_IRQ_COUNT_PER_INSTANCE - 1U)]);

    /* Reset TCD registers to zero. */
    EDMA_ResetChannelTCD(base, eChannel);

    /* Initialize tcd queue attribute. */
    psHandle->u8Header  = 0;
    psHandle->u8Tail    = 0;
    psHandle->u8TcdUsed = 0;
    psHandle->u8TcdSize = (uint8_t)u32TcdCount;
    psHandle->psTcdPool = psTcdPool;
}

/*!
 * brief Submits the eDMA single transfer configuration.
 */
status_t EDMA_TransferSubmitSingleTransfer(edma_handle_t *psHandle, edma_channel_transfer_config_t *psTransfer)
{
    assert(psHandle != NULL);
    assert(psTransfer != NULL);
    assert(psHandle->psTcdPool != NULL);

    DMA_Type *base       = psHandle->psBase;
    uint8_t u8Ch         = (uint8_t)psHandle->eChannel;
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
            u16Csr = psHandle->psTcdPool[u8PreviousTcd].u16CSR | ((uint16_t)DMA_TCD_CSR_ESG_MASK);
            u16Csr &= ~((uint16_t)DMA_TCD_CSR_DREQ_MASK);
            psHandle->psTcdPool[u8PreviousTcd].u16CSR = u16Csr;
            /*
                Check if the TCD block in the registers is the previous one (points to current TCD block). It
                is used to check if the previous TCD linked has been loaded in TCD register. If so, it need to
                link the TCD register in case link the current TCD with the dead chain when TCD loading occurs
                before linking the previous TCD block.
            */
            if (base->CH[u8Ch].TCD_DLAST_SGA == (uint32_t)((uint8_t *)(&psHandle->psTcdPool[u8CurrentTcd])))
            {
                /* Clear the DREQ bits for the dynamic scatter gather */
                base->CH[u8Ch].TCD_CSR &= ~(uint16_t)DMA_TCD_CSR_DREQ_MASK;
                /* Enable scatter/gather also in the TCD registers. */
                u16Csr = base->CH[u8Ch].TCD_CSR | DMA_TCD_CSR_ESG_MASK;
                /* Must write the CSR register one-time, because the transfer maybe finish anytime. */
                base->CH[u8Ch].TCD_CSR = u16Csr;
                /*
                    It is very important to check the ESG bit!
                    Because this hardware design: if DONE bit is set, the ESG bit can not be set. So it can
                    be used to check if the dynamic TCD link operation is successful. If ESG bit is not set
                    and the DLAST_SGA is not the next TCD address(it means the dynamic TCD link succeed and
                    the current TCD block has been loaded into TCD registers), it means transfer has finished
                    and TCD link operation fail, so must install TCD content into TCD registers and enable
                    transfer again. And if ESG is set, it means transfer has not finished, so TCD dynamic
                    link succeed.

                    Note: In eDMA3, DONE is in CH_CSR not TCD_CSR. ESG remains in TCD_CSR.
                */
                if (0U != (base->CH[u8Ch].TCD_CSR & DMA_TCD_CSR_ESG_MASK))
                {
                    base->CH[u8Ch].TCD_CSR &= ~(uint16_t)DMA_TCD_CSR_DREQ_MASK;
                    return kStatus_Success;
                }
                /*
                    Check whether the current TCD block is already loaded in the TCD registers. It is another
                    condition when ESG bit is not set: it means the dynamic TCD link succeeds and the current
                    TCD block has been loaded into TCD registers.
                */
                if (base->CH[u8Ch].TCD_DLAST_SGA == (uint32_t)((uint8_t *)(&psHandle->psTcdPool[u8NextTcd])))
                {
                    return kStatus_Success;
                }
                /*
                    If go to this, means the previous transfer finished, and the DONE bit is set.
                    So shall configure TCD registers.
                */
            }
            else if (base->CH[u8Ch].TCD_DLAST_SGA != 0UL)
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
    /* There is no live chain, TCD block need to be installed in TCD registers. */
    EDMA_InstallChannelSoftwareTCD(base, psHandle->eChannel, &psHandle->psTcdPool[u8CurrentTcd]);

    /* enable interrupt */
    EDMA_EnableChannelInterrupts(base, psHandle->eChannel,
                                 psTransfer->u16EnabledInterruptMask & (uint16_t)kEDMA_ChannelErrorInterruptEnable,
                                 true);

    return kStatus_Success;
}

/*!
 * brief Submits the eDMA scatter gather transfer configurations.
 */
status_t EDMA_TransferSubmitLoopTransfer(edma_handle_t *psHandle,
                                         edma_channel_transfer_config_t *psTransfer,
                                         uint32_t transferLoopCount)
{
    assert(psTransfer != NULL);
    assert(psHandle != NULL);
    assert(psHandle->psTcdPool != NULL);

    DMA_Type *base = psHandle->psBase;
    uint8_t u8Ch   = (uint8_t)psHandle->eChannel;
    uint32_t i     = 0U;

    if (psHandle->u8TcdSize < transferLoopCount)
    {
        return kStatus_EDMA_ChannelQueueFull;
    }

    /*
     *    Check if EDMA channel is busy:
     *    1. if channel active bit is set, it implies that minor loop is executing, then channel is busy
     *    2. if channel active bit is not set and BITER not equal to CITER, it implies that major loop is executing,
     *       then channel is busy
     */
    if (((base->CH[u8Ch].CH_CSR & DMA_CH_CSR_ACTIVE_MASK) != 0U) ||
        (((base->CH[u8Ch].TCD_CITER_ELINKNO & DMA_TCD_CITER_ELINKNO_CITER_MASK) !=
          (base->CH[u8Ch].TCD_BITER_ELINKNO & DMA_TCD_BITER_ELINKNO_BITER_MASK))))
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
    /* There is no live chain, TCD block need to be installed in TCD registers. */
    EDMA_InstallChannelSoftwareTCD(base, psHandle->eChannel, &psHandle->psTcdPool[0U]);

    /* enable interrupt */
    EDMA_EnableChannelInterrupts(base, psHandle->eChannel,
                                 psTransfer->u16EnabledInterruptMask & (uint16_t)kEDMA_ChannelErrorInterruptEnable,
                                 true);

    return kStatus_Success;
}

/*!
 * brief eDMA starts transfer.
 */
void EDMA_TransferStart(edma_handle_t *psHandle)
{
    assert(psHandle != NULL);

    DMA_Type *base = psHandle->psBase;
    uint8_t u8Ch   = (uint8_t)psHandle->eChannel;
    uint32_t u32TmpChCSR;
    uint16_t u16TmpTcdCSR;

    /* Check if channel request is actually disabled (ERQ bit in CH_CSR). */
    if ((base->CH[u8Ch].CH_CSR & DMA_CH_CSR_ERQ_MASK) == 0U)
    {
        /* Check if transfer is paused.
         * In eDMA3, DONE is in CH_CSR and ESG is in TCD_CSR. */
        u32TmpChCSR  = base->CH[u8Ch].CH_CSR;
        u16TmpTcdCSR = base->CH[u8Ch].TCD_CSR;
        if ((0U == (u32TmpChCSR & DMA_CH_CSR_DONE_MASK)) || (0U != (u16TmpTcdCSR & DMA_TCD_CSR_ESG_MASK)))
        {
            /*
                Re-enable channel request must be as soon as possible, so must put it into
                critical section to avoid task switching or interrupt service routine.
            */
            base->CH[u8Ch].CH_CSR |= DMA_CH_CSR_ERQ_MASK;
        }
    }
}

/*!
 * brief eDMA stops transfer.
 */
void EDMA_TransferStop(edma_handle_t *psHandle)
{
    assert(psHandle != NULL);

    psHandle->psBase->CH[(uint8_t)psHandle->eChannel].CH_CSR &= ~DMA_CH_CSR_ERQ_MASK;
}

/*!
 * brief eDMA aborts transfer.
 */
void EDMA_TransferAbort(edma_handle_t *psHandle)
{
    DMA_Type *base = psHandle->psBase;
    uint8_t u8Ch   = (uint8_t)psHandle->eChannel;

    /* Disable channel request */
    base->CH[u8Ch].CH_CSR &= ~DMA_CH_CSR_ERQ_MASK;
    /*
        Clear TCD_CSR to release channel. Because if the given channel started transfer,
        CSR will be not zero. Because if it is the last transfer, DREQ will be set.
        If not, ESG will be set.
    */
    base->CH[u8Ch].TCD_CSR = 0;
    /* Cancel all next TCD transfer. */
    base->CH[u8Ch].TCD_DLAST_SGA = 0;

    psHandle->u8Header  = 0;
    psHandle->u8Tail    = 0;
    psHandle->u8TcdUsed = 0;
}

/*!
 * brief eDMA IRQ handler for the current major loop transfer completion.
 */
void EDMA_TransferHandleIRQ(edma_handle_t *psHandle)
{
    assert(psHandle != NULL);

    DMA_Type *base = psHandle->psBase;
    uint8_t u8Ch   = (uint8_t)psHandle->eChannel;
    bool bTransferDone;

    /* Clear EDMA interrupt flag (W1C) */
    base->CH[u8Ch].CH_INT = DMA_CH_INT_INT_MASK;
    /* Check if transfer is already finished. DONE is in CH_CSR for eDMA3. */
    bTransferDone = ((base->CH[u8Ch].CH_CSR & DMA_CH_CSR_DONE_MASK) != 0U);

    uint32_t u32Sga = base->CH[u8Ch].TCD_DLAST_SGA;
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
        /* In eDMA3, DONE is W1C in CH_CSR */
        base->CH[u8Ch].CH_CSR |= DMA_CH_CSR_DONE_MASK;
    }
}

/*!
 * brief eDMA IRQ handler called from the device-specific SOC layer.
 *
 * This function checks the channel interrupt status and dispatches to the
 * per-channel transfer handle IRQ handler.
 *
 * param instance eDMA instance number.
 * param channel eDMA channel number.
 */
void EDMA_DriverIRQHandler(uint32_t instance, uint32_t channel)
{
    DMA_Type *base = s_edmaBases[instance];

    /* Check if channel interrupt is pending */
    if ((base->CH[channel].CH_INT & DMA_CH_INT_INT_MASK) != 0U)
    {
        uint32_t u32ChannelIndex =
            (EDMA_GetInstanceOffset(instance) * (uint32_t)FSL_FEATURE_EDMA_MODULE_CHANNEL) + channel;

        if (s_EDMAHandle[u32ChannelIndex] != NULL)
        {
            EDMA_TransferHandleIRQ(s_EDMAHandle[u32ChannelIndex]);
        }
        else
        {
            /* Clear interrupt even if no handle registered */
            base->CH[channel].CH_INT = DMA_CH_INT_INT_MASK;
        }
    }
}
