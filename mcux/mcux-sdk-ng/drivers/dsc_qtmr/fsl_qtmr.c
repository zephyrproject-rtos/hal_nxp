/*
 * Copyright 2020-2021 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_qtmr.h"

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.dsc_qtmr"
#endif

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/*!
 * @brief Gets the instance from the base address to be used to gate or ungate
 * the module clock
 *
 * @param base Quad Timer peripheral base address
 *
 * @return The Quad Timer instance
 */
static uint32_t QTMR_GetInstance(TMR_Type *base);

/*******************************************************************************
 * Variables
 ******************************************************************************/
/*! @brief Pointers to Quad Timer bases for each instance. */
static TMR_Type *const s_qtmrBases[] = TMR_BASE_PTRS;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/*! @brief Pointers to Quad Timer clocks for each instance. */
static const clock_ip_name_t s_qtmrClocks[] = TMR_CLOCKS;
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

/*******************************************************************************
 * Code
 ******************************************************************************/
static uint32_t QTMR_GetInstance(TMR_Type *base)
{
    uint32_t instance;

    /* Find the instance index from base address mappings. */
    for (instance = 0; instance < ARRAY_SIZE(s_qtmrBases); instance++)
    {
        if (s_qtmrBases[instance] == base)
        {
            break;
        }
    }

    assert(instance < ARRAY_SIZE(s_qtmrBases));

    return instance;
}

/*!
 * brief Initialization Quad Timer module with provided structure.
 *
 * This function can initial one or more channels of the Quad Timer module.
 *
 * This examples shows how only initial channel 0.
 * code
 *     qtmr_config_t sConfig = {0};
 *     qtmr_channel_config_t sChannel0Config;
 *     sConfig.psChannelConfig[0] = &sChannel0Config;
 *     QTMR_GetChannelDefaultConfig(&sChannel0Config);
 *     QTMR_Init(QTMR, sConfig);
 * endcode
 *
 * note This API should be called at the beginning of the application using the Quad Timer module.
 *
 * param base      Quad Timer peripheral base address.
 * param psConfig  Pointer to Quad Timer configure structure. See @ref qtmr_config_t.
 */
void QTMR_Init(TMR_Type *base, const qtmr_config_t *psConfig)
{
    assert(NULL != psConfig);
    uint16_t u16EnableMask = 0u;

    for (uint16_t i = 0U; i < 4U; i++)
    {
        if (psConfig->psInputFilterConfig[i] != NULL)
        {
            QTMR_SetInputFilter(base, (qtmr_input_pin_t)i, psConfig->psInputFilterConfig[i]->u8Count,
                                psConfig->psInputFilterConfig[i]->u8Period);
        }
    }
    for (uint16_t i = 0U; i < 4U; i++)
    {
        if (psConfig->psChannelConfig[i] != NULL)
        {
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
            /* Enable the QTMR channel clock*/
            CLOCK_EnableClock(s_qtmrClocks[QTMR_GetInstance(base) * 4U + i]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
            QTMR_SetupChannleConfig(base, (qtmr_channel_number_t)i, psConfig->psChannelConfig[i]);
            u16EnableMask |= (uint16_t)(psConfig->psChannelConfig[i]->bEnableChannel) << (uint16_t)i;
        }
    }

    /* Setup channel eanble status */
    QTMR_EnableChannels(base, u16EnableMask);
}

/*!
 * brief De-initialization Quad Timer module.
 *
 * param base  Quad Timer peripheral base address.
 */
void QTMR_Deinit(TMR_Type *base)
{
    /* Disable all channels */
    QTMR_DisableChannels(base, (uint16_t)kQTMR_ALLChannelEnable);

    for (uint16_t i = 0U; i < 4U; i++)
    {
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
        /* Disable the QTMR channel clock*/
        CLOCK_DisableClock(s_qtmrClocks[QTMR_GetInstance(base) * 4U + i]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
    }
}

/*!
 * brief Gets an available pre-defined options for Quad Timer channel module's configuration.
 *
 * This function initializes the channel configuration structure with a free run 16bit timer work setting.
 * The default values are:
 * code
 *   psConfig->sInputConfig.ePrimarySource = kQTMR_PrimarySrcIPBusClockDivide2;
 *   psConfig->sInputConfig.eSecondarySource = kQTMR_SecondarySrcInputPin0;
 *   psConfig->sInputConfig.eSecondarySourceCaptureMode = kQTMR_SecondarySrcCaptureNoCapture;
 *   psConfig->sInputConfig.bEnableSecondarySrcFaultFunction = false;
 *   psConfig->sInputConfig.eEnableInputInvert = false;
 *   psConfig->sCountConfig.eCountMode = kQTMR_CountPrimarySrcRiseEdge;
 *   psConfig->sCountConfig.eCountLength = kQTMR_CountLengthUntilRollOver;
 *   psConfig->sCountConfig.eCountDir = kQTMR_CountDirectionUp;
 *   psConfig->sCountConfig.eCountTimes = kQTMR_CountTimesRepeat;
 *   psConfig->sCountConfig.eCountLoadMode = kQTMR_CountLoadNormal;
 *   psConfig->sCountConfig.eCountPreload1 = kQTMR_CountPreloadNoLoad;
 *   psConfig->sCountConfig.eCountPreload2 = kQTMR_CountPreloadNoLoad;
 *   psConfig->sOutputConfig.eOutputMode = kQTMR_OutputAssertWhenCountActive;
 *   psConfig->sOutputConfig.eOutputValueOnForce = kQTMR_OutputValueClearOnForce;
 *   psConfig->sOutputConfig.bEnableOutputInvert = false;
 *   psConfig->sOutputConfig.bEnableSwForceOutput = false;
 *   psConfig->sOutputConfig.bEnableOutputPin = false;
 *   psConfig->sCooperationConfig.bEnableMasterReInit = false;
 *   psConfig->sCooperationConfig.bEnableMasterForceOFLAG = false;
 *   psConfig->sCooperationConfig.bEnableMasterMode = false;
 *   psConfig->eDebugMode = kQTMR_DebugRunNormal;
 *   psConfig->u16EnabledInterruptMask = 0x0U;
 *   psConfig->u16EnabledDMAMask = 0x0U;
 *   psConfig->u16Comp1 = 0x0U;
 *   psConfig->u16Comp2 = 0x0U;
 *   psConfig->u16Comp1Preload = 0x0U;
 *   psConfig->u16Comp1Preload = 0x0U;
 *   psConfig->u16Load = 0x0U;
 *   psConfig->u16Count = 0x0U;
 *   psConfig->bEnableChannel = false;
 * endcode
 *
 * param psConfig Pointer to user's Quad Timer channel config structure. See @ref qtmr_channel_config_t.
 */
void QTMR_GetChannelDefaultConfig(qtmr_channel_config_t *psConfig)
{
    assert(NULL != psConfig);

    /* Initializes the configure structure to zero. */
    (void)memset(psConfig, 0, sizeof(*psConfig));

    psConfig->sInputConfig.ePrimarySource                   = kQTMR_PrimarySrcIPBusClockDivide2;
    psConfig->sInputConfig.eSecondarySource                 = kQTMR_SecondarySrcInputPin0;
    psConfig->sInputConfig.eSecondarySourceCaptureMode      = kQTMR_SecondarySrcCaptureNoCapture;
    psConfig->sInputConfig.bEnableSecondarySrcFaultFunction = false;
    psConfig->sInputConfig.eEnableInputInvert               = false;

    psConfig->sCountConfig.eCountMode     = kQTMR_CountPrimarySrcRiseEdge;
    psConfig->sCountConfig.eCountLength   = kQTMR_CountLengthUntilRollOver;
    psConfig->sCountConfig.eCountDir      = kQTMR_CountDirectionUp;
    psConfig->sCountConfig.eCountTimes    = kQTMR_CountTimesRepeat;
    psConfig->sCountConfig.eCountLoadMode = kQTMR_CountLoadNormal;
    psConfig->sCountConfig.eCountPreload1 = kQTMR_CountPreloadNoLoad;
    psConfig->sCountConfig.eCountPreload2 = kQTMR_CountPreloadNoLoad;

    psConfig->sOutputConfig.eOutputMode                  = kQTMR_OutputAssertWhenCountActive;
    psConfig->sOutputConfig.eOutputValueOnForce          = kQTMR_OutputValueClearOnForce;
    psConfig->sOutputConfig.bEnableOutputInvert          = false;
    psConfig->sOutputConfig.bEnableSwForceOutput         = false;
    psConfig->sOutputConfig.bEnableOutputPin             = false;
    psConfig->sCooperationConfig.bEnableMasterReInit     = false;
    psConfig->sCooperationConfig.bEnableMasterForceOFLAG = false;
    psConfig->sCooperationConfig.bEnableMasterMode       = false;
    psConfig->eDebugMode                                 = kQTMR_DebugRunNormal;
    psConfig->u16EnabledInterruptMask                    = 0x0U;
    psConfig->u16EnabledDMAMask                          = 0x0U;
    psConfig->u16Comp1                                   = 0x0U;
    psConfig->u16Comp2                                   = 0x0U;
    psConfig->u16Comp1Preload                            = 0x0U;
    psConfig->u16Comp1Preload                            = 0x0U;
    psConfig->u16Load                                    = 0x0U;
    psConfig->u16Count                                   = 0x0U;
    psConfig->bEnableChannel                             = false;
}

/*!
 * brief Setup a Quad Timer channel with provided structure.
 *
 * param base            Quad Timer peripheral base address.
 * param eChannelNumber  Quad Timer channel number. See @ref qtmr_channel_number_t.
 * param psConfig        Pointer to user's Quad Timer channel config structure. See @ref qtmr_channel_config_t.
 */
void QTMR_SetupChannleConfig(TMR_Type *base,
                             qtmr_channel_number_t eChannelNumber,
                             const qtmr_channel_config_t *psConfig)
{
    assert(NULL != psConfig);

    /* Disable the channel first */
    QTMR_DisableChannels(base, (uint16_t)(1UL << (uint16_t)eChannelNumber));

    /* Setup the qtmr config */
    base->CHANNEL[eChannelNumber].CTRL =
        (TMR_CTRL_PCS(psConfig->sInputConfig.ePrimarySource) | TMR_CTRL_SCS(psConfig->sInputConfig.eSecondarySource) |
         TMR_CTRL_ONCE(psConfig->sCountConfig.eCountTimes) | TMR_CTRL_LENGTH(psConfig->sCountConfig.eCountLength) |
         TMR_CTRL_DIR(psConfig->sCountConfig.eCountDir) |
         TMR_CTRL_COINIT(psConfig->sCooperationConfig.bEnableMasterReInit) |
         TMR_CTRL_OUTMODE(psConfig->sOutputConfig.eOutputMode));

    base->CHANNEL[eChannelNumber].SCTRL = (TMR_SCTRL_IPS(psConfig->sInputConfig.eEnableInputInvert) |
                                           TMR_SCTRL_MSTR(psConfig->sCooperationConfig.bEnableMasterMode) |
                                           TMR_SCTRL_EEOF(psConfig->sCooperationConfig.bEnableMasterForceOFLAG) |
                                           TMR_SCTRL_VAL(psConfig->sOutputConfig.eOutputValueOnForce) |
                                           TMR_SCTRL_FORCE(psConfig->sOutputConfig.bEnableSwForceOutput) |
                                           TMR_SCTRL_OPS(psConfig->sOutputConfig.bEnableOutputInvert) |
                                           TMR_SCTRL_OEN(psConfig->sOutputConfig.bEnableOutputPin));

    base->CHANNEL[eChannelNumber].CSCTRL =
        (TMR_CSCTRL_DBG_EN(psConfig->eDebugMode) |
         TMR_CSCTRL_FAULT(psConfig->sInputConfig.bEnableSecondarySrcFaultFunction) |
         TMR_CSCTRL_ALT_LOAD(psConfig->sCountConfig.eCountLoadMode) |
         TMR_CSCTRL_CL1(psConfig->sCountConfig.eCountPreload1) | TMR_CSCTRL_CL2(psConfig->sCountConfig.eCountPreload2));

    QTMR_SetCountMode(base, eChannelNumber, psConfig->sCountConfig.eCountMode);
    QTMR_SetSecondarySourceInputCaptureMode(base, eChannelNumber, psConfig->sInputConfig.eSecondarySourceCaptureMode);

    /* Setup counter register */
    QTMR_SetCounterValue(base, eChannelNumber, psConfig->u16Count);
    /* Setup compare and load registers */
    QTMR_SetLoadValue(base, eChannelNumber, psConfig->u16Load);
    QTMR_SetCompare1Value(base, eChannelNumber, psConfig->u16Comp1);
    QTMR_SetCompare2Value(base, eChannelNumber, psConfig->u16Comp2);
    QTMR_SetCompare1PreloadValue(base, eChannelNumber, psConfig->u16Comp1Preload);
    QTMR_SetCompare2PreloadValue(base, eChannelNumber, psConfig->u16Comp2Preload);

    /* Config interrupts */
    QTMR_EnableInterrupts(base, eChannelNumber, psConfig->u16EnabledInterruptMask);

    /* Config DMA */
    QTMR_EnableDma(base, eChannelNumber, psConfig->u16EnabledDMAMask);
}

/*!
 * brief Sets channel count mode.
 *
 * This function select channel basic count mode which trigger by primary input or/and secondary input events.
 *
 * param base     Quad Timer peripheral base address.
 * param eChannelNumber  Quad Timer channel number. See @ref qtmr_channel_number_t.
 * param eCountMode  The mode of operation for the count. See @ref qtmr_channel_count_mode_t.
 */
void QTMR_SetCountMode(TMR_Type *base, qtmr_channel_number_t eChannelNumber, qtmr_channel_count_mode_t eCountMode)
{
    uint16_t reg = base->CHANNEL[eChannelNumber].CTRL & (~(uint16_t)TMR_CTRL_CM_MASK);

    if ((uint8_t)eCountMode > (uint8_t)kQTMR_CountCascadeWithOtherChannel)
    {
        base->CHANNEL[eChannelNumber].CSCTRL |= TMR_CSCTRL_TCI_MASK;
    }
    else
    {
        base->CHANNEL[eChannelNumber].CSCTRL &= ~(uint16_t)TMR_CSCTRL_TCI_MASK;
    }

    /* Set the new values */
    reg |= TMR_CTRL_CM(eCountMode);
    base->CHANNEL[eChannelNumber].CTRL = reg;
}

/*!
 * brief Sets secondary input node capture mode.
 *
 * This function select the capture mode for secondary input node, it can select from "disable capture", "capture on
 * rising/falling edge" and "capture on both edges". Need enable capture mode when input edge interrupt is needed.
 *
 * param base     Quad Timer peripheral base address.
 * param eChannelNumber  Quad Timer channel number. See @ref qtmr_channel_number_t.
 * param eCaptureMode The capture mode of secondary input node. See @ref qtmr_channel_secondary_source_capture_mode_t.
 */
void QTMR_SetSecondarySourceInputCaptureMode(TMR_Type *base,
                                             qtmr_channel_number_t eChannelNumber,
                                             qtmr_channel_secondary_source_capture_mode_t eCaptureMode)
{
    uint16_t reg = base->CHANNEL[eChannelNumber].SCTRL & (~(uint16_t)TMR_SCTRL_CAPTURE_MODE_MASK);

    switch (eCaptureMode)
    {
        case kQTMR_SecondarySrcCaptureRisingEdge:
        case kQTMR_SecondarySrcCaptureFallingEdge:
        case kQTMR_SecondarySrcCaptureRisingEdgeWithReload:
        case kQTMR_SecondarySrcCaptureFallingEdgeWithReload:
            if ((base->CHANNEL[eChannelNumber].SCTRL & TMR_SCTRL_IPS_MASK) != 0U)
            {
                reg |= TMR_SCTRL_CAPTURE_MODE(~(uint16_t)eCaptureMode);
            }
            else
            {
                reg |= TMR_SCTRL_CAPTURE_MODE(eCaptureMode);
            }
            break;
        default:
            reg |= TMR_SCTRL_CAPTURE_MODE(eCaptureMode);
            break;
    }

    if ((uint8_t)eCaptureMode > (uint8_t)kQTMR_SecondarySrcCaptureRisingAndFallingEdge)
    {
        base->CHANNEL[eChannelNumber].CSCTRL |= (uint16_t)TMR_CSCTRL_ROC_MASK;
    }
    else
    {
        base->CHANNEL[eChannelNumber].CSCTRL &= ~(uint16_t)TMR_CSCTRL_ROC_MASK;
    }
    /* Set the new values */
    base->CHANNEL[eChannelNumber].SCTRL = reg;
}
