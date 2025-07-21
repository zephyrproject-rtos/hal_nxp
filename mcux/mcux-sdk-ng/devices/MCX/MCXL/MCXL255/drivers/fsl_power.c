/*
 * Copyright 2025 NXP
 *
 * All rights reserved.
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include "fsl_power.h"
#if __CORTEX_M == 33U
#include "fsl_cmc.h"
#include "fsl_wuu.h"
#endif /* __CORTEX_M */
#include "fsl_mu.h"
#include "fsl_smm.h"
#include "fsl_pmu.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.power"
#endif

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
typedef enum _power_mu_transfer_state
{
    kPower_MuTransferIdle = 0U,
    kPower_MuTransferStart = 1U,
    kPower_MuTransferEndWithNACK = 2U,
    kPower_MuTransferEndWithACK = 3U,
    kPower_MuTransferWrong = 4U,
} power_mu_transfer_state_t;

volatile power_wakeup_source_info_t g_powerWakeupSourceInfo = {
    .aonWakeupSourceMask    = 0UL,
    .wuuPinIntEnable[0]     = 0UL,
    .wuuPinIntEnable[1]     = 0UL,
    .wuuModuleIntEnable     = 0UL,
    .wuuModuleDmaTrigEnable = 0UL,
    .wuuPinDmaTrigConfig[0] = 0UL,
    .wuuPinDmaTrigConfig[1] = 0UL,
};

volatile power_mu_transfer_state_t g_powerMuTransferState = kPower_MuTransferIdle;

static void Power_RecordWUURegisterValue(void);

/*******************************************************************************
 * Variables
 ******************************************************************************/
volatile power_mu_message_t g_powerRequestMuMsg;

uint32_t g_Handle_Offset = 0xFFFFFFFFUL;

#if __CORTEX_M == 33U
#define POWER_USED_MU   (MUA)
#elif __CORTEX_M == 0U
#define POWER_USED_MU   (MUB)
#endif /* __CORTEX_M */

/*******************************************************************************
 * Code
 ******************************************************************************/

static void Power_RecordWUURegisterValue(void)
{
#if __CORTEX_M == 33U
    g_powerWakeupSourceInfo.wuuPinIntEnable[0]     = WUU0->PE1;
    g_powerWakeupSourceInfo.wuuPinIntEnable[1]     = WUU0->PE2;
    g_powerWakeupSourceInfo.wuuModuleIntEnable     = WUU0->ME;
    g_powerWakeupSourceInfo.wuuModuleDmaTrigEnable = WUU0->DE;
    g_powerWakeupSourceInfo.wuuPinDmaTrigConfig[0] = WUU0->PDC1;
    g_powerWakeupSourceInfo.wuuPinDmaTrigConfig[1] = WUU0->PDC2;
#endif
}

static status_t Power_VerifyMuMessage(uint32_t message, bool msgIsRequest)
{
    power_mu_message_t msg;
    msg.wordFormat = message;

    if (msg.strcutFormat.syncCode != 0x5A)
    {
        return kStatus_POWER_MuTransferError;
    }
    else
    {
#if 0
        if (msgIsRequest == false)
        {
            if ((msg.strcutFormat.direction == g_powerRequestMuMsg.strcutFormat.direction) ||
                (msg.strcutFormat.reqestLowPowerMode != g_powerRequestMuMsg.strcutFormat.reqestLowPowerMode) ||
                (msg.strcutFormat.sharedHandleAddrOff != g_powerRequestMuMsg.strcutFormat.sharedHandleAddrOff))
            {
                return kStatus_POWER_MuTransferError;
            }
        }
#endif
        return kStatus_Success;
    }
}

static uint32_t Power_PopulateMuMessage(power_mu_message_type_t msgType, power_mu_message_direction_t msgDirection,
    power_low_power_mode_t lowPowerMode, bool init, uint32_t sharedHandleAddrOff)
{
    power_mu_message_t msg;

    msg.strcutFormat.syncCode = 0x5A; 
    msg.strcutFormat.type = msgType;
    msg.strcutFormat.direction = msgDirection;
    msg.strcutFormat.reqestLowPowerMode = lowPowerMode;
    msg.strcutFormat.init = init;
    msg.strcutFormat.sharedHandleAddrOff = sharedHandleAddrOff;

    return msg.wordFormat;
}

#if __CORTEX_M == 0U
static status_t Power_ReqestCM33StartLpSeq(power_low_power_mode_t targetMode)
{
    uint32_t tmp32 = 0UL;
    power_handle_t *curHandle = (power_handle_t *)(POWER_SHARED_RAM_BASE_ADDR + g_Handle_Offset);

    tmp32 = Power_PopulateMuMessage(kPower_MsgTypeRequest, kPower_MsgDirAonToMain, targetMode, false, g_Handle_Offset);
    MU_SendMsg(POWER_USED_MU, curHandle->muChannelId, tmp32);

    /* Waiting for response from CM0P. */
    while(g_powerMuTransferState != kPower_MuTransferStart)
    {
    }
    if (g_powerMuTransferState == kPower_MuTransferWrong)
    {
        return kStatus_POWER_MuTransferError;
    }
    if (g_powerMuTransferState == kPower_MuTransferEndWithNACK)
    {
        return kStatus_POWER_RequestNotAllowed;
    }

    return kStatus_Success;
}

#endif /* __CORTEX_M == 0U */

/*!
 * brief Create shared power handle.
 * 
 * param[in] handle Pointer to a handle in type of power_handle_t, must be in shared RAM.
 * param[in] muChannelId MU channel ID used by power driver.
 *
 * retval kStatus_POWER_MuTransferError Something error occurs during MU transfer.
 * retval kStatus_Power_HandleDuplicated Shared power handle already be created.
 * retval kStatus_Success Created handle successfully.
 */
status_t Power_CreateHandle(power_handle_t *handle,
    uint32_t muChannelId)
{
#if __CORTEX_M == 33U
    assert((uint32_t)handle >= POWER_SHARED_RAM_BASE_ADDR);
#endif

    (void)memset(handle, 0UL, sizeof(power_handle_t));

    handle->muChannelId = muChannelId;
    handle->targetPowerMode = kPower_Active;

    handle->dualCoreSynced = false;
    handle->requestCM33Start = false;

    /* Record offset of handle. */
    g_Handle_Offset = (uint32_t)handle - POWER_SHARED_RAM_BASE_ADDR;
    /* Inform another that attemp to create handle. */
    uint32_t tmp32 = Power_PopulateMuMessage(kPower_MsgTypeRequest, kPower_MsgDirMainToAon, kPower_Active, true, g_Handle_Offset);

    g_powerMuTransferState = kPower_MuTransferStart;
    MU_SendMsg(POWER_USED_MU, muChannelId, tmp32);

    /* Waiting for response from CM0P. */
    while(g_powerMuTransferState == kPower_MuTransferStart)
    {
    }
    if (g_powerMuTransferState == kPower_MuTransferWrong)
    {
        return kStatus_POWER_MuTransferError;
    }
    if (g_powerMuTransferState == kPower_MuTransferEndWithNACK)
    {
        return kStatus_Power_HandleDuplicated;
    }
    g_powerMuTransferState = kPower_MuTransferIdle;

    handle->dualCoreSynced = true;
    return kStatus_Success;
}

void Power_DumpHandleValue(power_handle_t *ptrDumpBuffer)
{
  power_handle_t *sharedHandle = (power_handle_t *)(POWER_SHARED_RAM_BASE_ADDR + g_Handle_Offset);
  
  memcpy(ptrDumpBuffer, sharedHandle, sizeof(power_handle_t));
}

uint32_t Power_GetHandleOffset(void)
{
    return g_Handle_Offset;
}

void Power_RestoreHandleOffset(uint32_t offset)
{
    g_Handle_Offset = offset;
}

/*!
 * brief Enable input wakeup source, once enabled it will be effective until disabled
 *
 * param[in] ws Specify the coded wakeup source, please refer to power_wakeup_source_t for details.
 */
void Power_EnableWakeupSource(power_wakeup_source_t ws)
{
    uint32_t aonIndex;
    uint32_t wuuIndex;
    uint32_t wuuEvent;
    uint32_t pinEdge;
    uint32_t wakeupDomain;
    bool isWuuExtPin;
    bool isCm33Ws;
#if __CORTEX_M == 33U
    wuu_external_wakeup_pin_config_t tmpPinConfig;
#endif

    POWER_DECODE_WS((uint32_t)ws);

    if (isCm33Ws == true)
    {
#if __CORTEX_M == 33U
        if (isWuuExtPin == true)
        {
            tmpPinConfig.edge  = (wuu_external_pin_edge_detection_t)pinEdge;
            tmpPinConfig.event = (wuu_external_wakeup_pin_event_t)wuuEvent;
            tmpPinConfig.mode  = kWUU_ExternalPinActiveAlways;
            WUU_SetExternalWakeUpPinsConfig(WUU0, wuuIndex, &tmpPinConfig);
        }
        else
        {
            WUU_SetInternalWakeUpModulesConfig(WUU0, wuuIndex, (wuu_internal_wakeup_module_event_t)wuuEvent);
        }
#elif __CORTEX_M == 0U
        (void)wuuIndex;
        (void)wuuEvent;
        (void)isWuuExtPin;
#endif
    }
    else
    {
        g_powerWakeupSourceInfo.aonWakeupSourceMask |= 1UL << aonIndex;
        if (wakeupDomain == 0)
        {
            SMM_EnableWakeupSourceToMainCpu(AON__SMM, aonIndex);
        }
        else if (wakeupDomain == 1)
        {
            SMM_EnableWakeupSourceToAonCpu(AON__SMM, aonIndex);
        }
        else
        {
            SMM_EnableWakeupSourceToAonCpu(AON__SMM, aonIndex);
            SMM_EnableWakeupSourceToMainCpu(AON__SMM, aonIndex);
        }

        if (aonIndex == 5U)
        {
            /* In case of external interrupt. */
            smm_ext_int_config_t extIntConfig = {
                .maskExtIntPin = false,
            };
            if (pinEdge == 2UL)
            {
                extIntConfig.extIntPolarity = kSMM_ExtIntFallingEdge;
            }
            else if (pinEdge == 1UL)
            {
                extIntConfig.extIntPolarity = kSMM_ExtIntRisingEdge;
            }
            SMM_SetExtInterruptConfig(AON__SMM, &extIntConfig);
            SMM_ClearExternalIntFlag(AON__SMM);
        }
    }

    Power_RecordWUURegisterValue();

#if __CORTEX_M == 33U
    if ((g_powerWakeupSourceInfo.wuuPinIntEnable[0] != 0UL) || (g_powerWakeupSourceInfo.wuuPinIntEnable[1] != 0UL))
    {
        EnableIRQ(WUU0_IRQn);
    }
#endif
}

/*!
 * brief Disable input wakeup source.
 *
 * param[in] ws Specify the coded wakeup source, please refer to power_wakeup_source_t for details.
 */
void Power_DisableWakeupSource(power_wakeup_source_t ws)
{
    uint32_t aonIndex;
    uint32_t wuuIndex;
    uint32_t wuuEvent;
    uint32_t pinEdge;
    uint32_t wakeupDomain;
    bool isWuuExtPin;
    bool isCm33Ws;

    POWER_DECODE_WS((uint32_t)ws);

    (void)pinEdge;
    if (isCm33Ws == true)
    {
#if __CORTEX_M == 33U
        if (isWuuExtPin == true)
        {
            WUU_ClearExternalWakeupPinsConfig(WUU0, wuuIndex);
        }
        else
        {
            WUU_ClearInternalWakeUpModulesConfig(WUU0, wuuIndex, (wuu_internal_wakeup_module_event_t)wuuEvent);
        }
#elif __CORTEX_M == 0U
        (void)wuuIndex;
        (void)wuuEvent;
        (void)isWuuExtPin;
#endif
    }
    else
    {
        if (wakeupDomain == 0)
        {
            SMM_DisableWakeupSourceToMainCpu(AON__SMM, aonIndex);
        }
        else if (wakeupDomain == 1)
        {
            SMM_DisableWakeupSourceToAonCpu(AON__SMM, aonIndex);
        }
        else
        {
            SMM_DisableWakeupSourceToAonCpu(AON__SMM, aonIndex);
            SMM_DisableWakeupSourceToMainCpu(AON__SMM, aonIndex);
        }
    }

    Power_RecordWUURegisterValue();

#if __CORTEX_M == 33U
    if ((g_powerWakeupSourceInfo.wuuPinIntEnable[0] == 0UL) && (g_powerWakeupSourceInfo.wuuPinIntEnable[1] == 0UL))
    {
        DisableIRQ(WUU0_IRQn);
    }
#endif 
}

/*!
 * brief Dump information of all configured wakeup sources, in type of power_wakeup_source_info_t.
 *
 * param[out] ptrWsInfo Pointer to the variable to store dumped wakeup source information.
 */
void Power_DumpEnabledWakeSource(power_wakeup_source_info_t *ptrWsInfo)
{
    assert(ptrWsInfo);

    (void)memcpy((void *)ptrWsInfo, (void *)(&g_powerWakeupSourceInfo), sizeof(g_powerWakeupSourceInfo));
}

/*!
 * brief Get latest mask of wakeup sources which cause the wake-up to main CPU.
 *
 * param[out] ptrWakeupSourceMask Pointer to the variable to store mask of wakeup sources.
 */
void Power_GetWakeupSource(uint32_t *ptrWakeupSourceMask)
{
    *ptrWakeupSourceMask = SMM_GetWakeupSourceStatus(AON__SMM);
}

/*!
 * brief Register user callback.
 * 
 * param[in] callback Pointer to callback in type of power_user_callback_t.
 * param[in] userData Pointer to user data.
 */
void Power_RegisterUserCallback(power_user_callback_t callback, void *userData)
{
    power_handle_t *sharedHandle = (power_handle_t *)(POWER_SHARED_RAM_BASE_ADDR + g_Handle_Offset);
#if __CORTEX_M == 33U
    sharedHandle->cm33Callback = callback;
    sharedHandle->cm33UserData = userData;
#else
    sharedHandle->cm0pCallback = callback;
    sharedHandle->cm0pUserData = userData;
#endif
}

/*!
 * brief Unregister user callback.
 */
void Power_UnRegisterUserCallback(void)
{
    power_handle_t *sharedHandle = (power_handle_t *)(POWER_SHARED_RAM_BASE_ADDR + g_Handle_Offset);
#if __CORTEX_M == 33U
    sharedHandle->cm33Callback = NULL;
    sharedHandle->cm33UserData = NULL;
#else
    sharedHandle->cm0pCallback = NULL;
    sharedHandle->cm0pUserData = NULL;
#endif
}

status_t Power_GetCurrentPowerMode(power_low_power_mode_t *ptrCurLpMode)
{
    status_t status = kStatus_Success;
    uint8_t tmp8 = SMM_GetPowerState(AON__SMM);
    power_handle_t *sharedHandle = (power_handle_t *)(POWER_SHARED_RAM_BASE_ADDR + g_Handle_Offset);
    power_low_power_mode_t targetLpMode = sharedHandle->targetPowerMode;
    power_low_power_mode_t curLpMode = kPower_Active;

    switch(tmp8)
    {
        case 0U:
        {
            if (targetLpMode == kPower_Sleep)
            {
                curLpMode = kPower_Sleep;
            }
            break;
        }
        case 1U:
        {
            curLpMode = kPower_DeepSleep;
            break;
        }
        case 2U:
        {
            curLpMode = kPower_DeepPowerDown1;
            break;
        }
        case 3U:
        {
            curLpMode = kPower_PowerDown1;
            break;
        }
        case 4U:
        {
            curLpMode = kPower_DeepPowerDown2;
            break;
        }
        case 5U:
        {
            curLpMode = kPower_DeepPowerDown3;
            break;
        }
        case 6U:
        {
            curLpMode = kPower_ShutDown;
            break;
        }
        default:    
        {
            /* Avoid violation of MISRA rule. */
            break;
        }
    }

    *ptrCurLpMode = curLpMode;
//    if (curLpMode != targetLpMode)
//    {
//        status = kStatus_Power_NotInTargetMode;
//    }
    return status;
}

power_low_power_mode_t Power_GetTargetPowerMode(void)
{
    power_handle_t *sharedHandle = (power_handle_t *)(POWER_SHARED_RAM_BASE_ADDR + g_Handle_Offset);
    power_low_power_mode_t targetPowerMode = sharedHandle->targetPowerMode;

    return targetPowerMode;
}

void Power_ClearTargatePowerMode(void)
{
    power_handle_t *sharedHandle = (power_handle_t *)(POWER_SHARED_RAM_BASE_ADDR + g_Handle_Offset);
    sharedHandle->targetPowerMode = kPower_Active;
}

void Power_ClearLpPowerSettings(void)
{
#if __CORTEX_M == 33U
    SMM_DisableMainCpuIso(AON__SMM);
    SMM_ClearAllLowPowerSequence(AON__SMM);
    SMM_ClearMainCpuWakeupSources(AON__SMM);
#elif __CORTEX_M == 0U
    SMM_DisableAonCpuIso(AON__SMM);
    SMM_ClearAllLowPowerSequence(AON__SMM);
    SMM_ClearAonCpuWakeupSources(AON__SMM);
#endif /* __CORTEX_M */
}

/*!
* brief Enter selected low power mode.
* 
* param[in] lowpowerMode Indicate specific low power mode.
* param config Point to low power configurations.
*
* retval kStatus_POWER_MuTransferError Something error occurs during MU transfer.
* retval kStatus_POWER_RequestNotAllowed Request not allowed by another core.
*/
status_t Power_EnterLowPowerMode(power_low_power_mode_t lowpowerMode, void *config)
{
    status_t status = kStatus_Success; 
    switch(lowpowerMode)
    {
        case kPower_Sleep:
        {
            (void)config;
            status = Power_EnterSleep();
            break;
        } 
        case kPower_DeepSleep:
        {
            status = Power_EnterDeepSleep((power_ds_config_t *)config);
            break;
        }
        case kPower_PowerDown1:
        {
            status = Power_EnterPowerDown1((power_pd1_config_t *)config);
            break;
        }
        case kPower_PowerDown2:
        {
            status = Power_EnterPowerDown2((power_pd2_config_t *)config);
            break;
        }
        case kPower_DeepPowerDown1:
        {
            status = Power_EnterDeepPowerDown1((power_dpd1_config_t *)config);
            break;
        }
        case kPower_DeepPowerDown2:
        {
            status = Power_EnterDeepPowerDown2((power_dpd2_config_t *)config);
            break;
        }
        case kPower_DeepPowerDown3:
        {
            status = Power_EnterDeepPowerDown3((power_dpd3_config_t *)config);
            break;
        }
        case kPower_ShutDown:
        {
            status = Power_EnterShutDown((power_sd_config_t *)config);
            break;
        }
        default:
        {
            /* Avoid MISRA violation. */
            break;
        }
    }

    return status;
}

/*!
 * brief Enter the sleep mode.
 * 
 * This function is used to put the system into sleep mode.
 * 
 * retval kStatus_Success Successfully entered sleep mode.
 * retval kStatus_POWER_MuTransferError Something error occurs during MU transfer.
 * retval kStatus_POWER_RequestNotAllowed Request not allowed by another core.
 */
status_t Power_EnterSleep(void)
{
#if __CORTEX_M == 33U
    power_handle_t *sharedHandle = (power_handle_t *)(POWER_SHARED_RAM_BASE_ADDR + g_Handle_Offset);
    sharedHandle->targetPowerMode = kPower_Sleep;
    __DSB();
    __ISB();
    __WFI();

    return kStatus_Success;
#elif __CORTEX_M == 0U
    return Power_ReqestCM33StartLpSeq(kPower_Sleep);
#endif /* __CORTEX_M == 33U */
}


/*!
 * brief Enter Deep Sleep mode.
 * 
 * This function attempts to put the system into Deep Sleep mode with the provided configuration.
 * 
 * param[in] config Pointer to the Deep Sleep mode configuration.
 * 
 * retval kStatus_Success Successfully entered Deep Sleep mode.
 * retval kStatus_POWER_MuTransferError Something error occurs during MU transfer.
 * retval kStatus_POWER_RequestNotAllowed Request not allowed by another core.
 */
status_t Power_EnterDeepSleep(power_ds_config_t *config)
{
    power_handle_t *sharedHandle = (power_handle_t *)(POWER_SHARED_RAM_BASE_ADDR + g_Handle_Offset);
    memcpy(sharedHandle->lpConfig, config, sizeof(power_ds_config_t));
#if __CORTEX_M == 33U
    /* Invoke CMC API to set Main domain as Deep power down mode and then
       execute WFI instruction. */
    CMC_SetPowerModeProtection(CMC, kCMC_AllowDeepSleepMode);
    CMC_SetClockMode(CMC, kCMC_GateAllSystemClocksEnterLowPowerMode);
    CMC_SetGlobalPowerMode(CMC, kCMC_DeepSleepMode);
    sharedHandle->requestCM33Start = false;
    sharedHandle->targetPowerMode = kPower_DeepSleep;
    SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;
    __DSB();
    __WFI();
    __ISB();

    return kStatus_Success;
#elif __CORTEX_M == 0U
    sharedHandle->requestCM33Start = true;
    return Power_ReqestCM33StartLpSeq(kPower_DeepSleep);
#endif /* __CORTEX_M == 33U */
}

/*!
 * brief Enter Power Down 1 mode.
 * 
 * This function attempts to put the system into Power Down 1 mode with the provided configuration.
 * 
 * param[in] config Pointer to the Power Down 1 mode configuration.
 * 
 * retval kStatus_Success Successfully entered Power Down 1 mode.
 * retval kStatus_POWER_MuTransferError Something error occurs during MU transfer.
 * retval kStatus_POWER_RequestNotAllowed Request not allowed by another core.
 */
status_t Power_EnterPowerDown1(power_pd1_config_t *config)
{
    power_handle_t *sharedHandle = (power_handle_t *)(POWER_SHARED_RAM_BASE_ADDR + g_Handle_Offset);
    memcpy(sharedHandle->lpConfig, config, sizeof(power_pd1_config_t));
#if __CORTEX_M == 33U

    SMM_EnableMainDomainSramRetention(AON__SMM, config->mainRamArraysToRetain);
    SMM_ShutDownBandgapInLowPowerModes(AON__SMM, config->disableBandgap);
    SMM_EnableIvsModeForSramRetention(AON__SMM, config->enableIVSMode);
    SMM_StartPowerDownSequence(AON__SMM);

    /* TODO: WUU settings? */

    CMC_SetPowerModeProtection(CMC, kCMC_AllowAllLowPowerModes);
    CMC_SetClockMode(CMC, kCMC_GateAllSystemClocksEnterLowPowerMode);
    CMC->GPMCTRL = CMC_GPMCTRL_LPMODE((uint8_t)0x7);

    sharedHandle->requestCM33Start = false;
    sharedHandle->targetPowerMode = kPower_PowerDown1;
    SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;
    __DSB();
    __ISB();
    __WFI();

    return kStatus_Success;
#elif __CORTEX_M == 0U
    sharedHandle->requestCM33Start = true;
    return Power_ReqestCM33StartLpSeq(kPower_PowerDown1);
#endif /* __CORTEX_M == 33U */
}

/*!
 * brief Enter Power Down 2 mode.
 * 
 * This function attempts to put the system into Power Down 2 mode with the provided configuration.
 * 
 * param[in] config Pointer to the Power Down 2 mode configuration.
 * 
 * retval kStatus_Success Successfully entered Power Down 2 mode.
 * retval kStatus_POWER_MuTransferError Something error occurs during MU transfer.
 * retval kStatus_POWER_RequestNotAllowed Request not allowed by another core.
 */
status_t Power_EnterPowerDown2(power_pd2_config_t *config)
{
    power_handle_t *sharedHandle = (power_handle_t *)(POWER_SHARED_RAM_BASE_ADDR + g_Handle_Offset);
    memcpy(sharedHandle->lpConfig, config, sizeof(power_pd2_config_t));
#if __CORTEX_M == 33U
    /* 1. Configuration for SMM. */
    SMM_PowerOffAonSramAutomatically(AON__SMM, (uint8_t)(~(config->aonRamArraysToRetain)));
    SMM_EnableMainDomainSramRetention(AON__SMM, config->mainRamArraysToRetain);
    SMM_ShutDownBandgapInLowPowerModes(AON__SMM, config->disableBandgap);
    SMM_EnableIvsModeForSramRetention(AON__SMM, config->enableIVSMode);
    SMM_SwitchToXTAL32(AON__SMM, config->switchToX32K);
    if (config->switchToX32K)
    {
        AON__CGU->CLK_CONFIG |= CGU_CLK_CONFIG_ROOT_AUX_CLK_EN_MASK;
    }  
    SMM_StartAonDPD2Sequence(AON__SMM);

    /* 2. Software configuration for CM0P. */
    if (sharedHandle->requestCM33Start != true)
    {
        /* Inform CM0P to execute WFI. */
        power_mu_message_t msg = {
            .strcutFormat = {
                .syncCode = 0x5A,
                .type = kPower_MsgTypeRequest,
                .direction = kPower_MsgDirMainToAon,
                .reqestLowPowerMode = kPower_PowerDown2,
                .sharedHandleAddrOff = 0UL,
            }
        };
        g_powerMuTransferState = kPower_MuTransferStart;
        g_powerRequestMuMsg = msg;
        MU_SendMsg(MUA, sharedHandle->muChannelId, (uint32_t)msg.wordFormat);
        /* Waiting for response from CM0P. */
        while(g_powerMuTransferState == kPower_MuTransferStart)
        {
        }
        if (g_powerMuTransferState == kPower_MuTransferWrong)
        {
            return kStatus_POWER_MuTransferError;
        }
        if (g_powerMuTransferState == kPower_MuTransferEndWithNACK)
        {
            return kStatus_POWER_RequestNotAllowed;
        }
        g_powerMuTransferState = kPower_MuTransferIdle;
    }

    /* 3. TODO: Configuration for WUU? */

    /* 4. Configuration for CMC. */
    CMC_SetPowerModeProtection(CMC, kCMC_AllowAllLowPowerModes);
    CMC_SetClockMode(CMC, kCMC_GateAllSystemClocksEnterLowPowerMode);
    CMC->GPMCTRL = CMC_GPMCTRL_LPMODE((uint8_t)0x7);
    sharedHandle->requestCM33Start = false;
    sharedHandle->targetPowerMode = kPower_PowerDown2;

    if (config->disableFRO10M)
    {
        AON__CGU->CLK_CONFIG |= CGU_CLK_CONFIG_ROOT_AUX_CLK_EN_MASK;
        AON__CGU->CLK_CONFIG = (AON__CGU->CLK_CONFIG & ~CGU_CLK_CONFIG_ROOT_CLK_SEL_MASK) | CGU_CLK_CONFIG_ROOT_CLK_SEL(3U);
        AON__CGU->CLK_CONFIG &= ~(CGU_CLK_CONFIG_FRO10M_EN_MASK | CGU_CLK_CONFIG_FRO2M_EN_MASK);
    }  
    /* 5. Software configuration for CM33. */
    SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;
    __DSB();
    __ISB();
    __WFI();
    
    return kStatus_Success;
#elif __CORTEX_M == 0U
    status_t status = kStatus_Success;
    sharedHandle->requestCM33Start = true;

    status = Power_ReqestCM33StartLpSeq(kPower_PowerDown2);

    if (status == kStatus_Success)
    {
        SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;
        __DSB();
        __ISB();
        __WFI();
    }

    return status;
#endif /* __CORTEX_M == 33U */
}

/*!
 * brief Enter Deep Power Down 1 mode.
 * 
 * This function attempts to put the system into Deep Power Down 1 mode with the provided configuration.
 * 
 * param[in] config Pointer to the Deep Power Down 1 mode configuration.
 * 
 * retval kStatus_Success Successfully entered Deep Power Down 1 mode.
 * retval kStatus_POWER_MuTransferError Something error occurs during MU transfer.
 * retval kStatus_POWER_RequestNotAllowed Request not allowed by another core.
 */
status_t Power_EnterDeepPowerDown1(power_dpd1_config_t *config)
{
    power_handle_t *sharedHandle = (power_handle_t *)(POWER_SHARED_RAM_BASE_ADDR + g_Handle_Offset);

    memcpy(sharedHandle->lpConfig, config, sizeof(power_dpd1_config_t));
#if __CORTEX_M == 33U
    /* 1. Configuration for PMU. */
//    PMU_UpdateVDDCoreInLpMode(AON__PMU, (uint8_t)config->VDDCoreOutputVoltage);

    /* 2. Configuration for SMM. */
    SMM_EnableMainDomainSramRetention(AON__SMM, config->mainRamArraysToRetain);
    SMM_ShutDownBandgapInLowPowerModes(AON__SMM, config->disableBandgap);
    SMM_EnableIvsModeForSramRetention(AON__SMM, config->enableIVSMode);
    SMM_StartPowerDownSequence(AON__SMM);

    /* 3. Configuration for CMC. */
    CMC_SetPowerModeProtection(CMC, kCMC_AllowAllLowPowerModes);
    CMC_SetClockMode(CMC, kCMC_GateAllSystemClocksEnterLowPowerMode);
    CMC_SetGlobalPowerMode(CMC, kCMC_DeepPowerDown);
    sharedHandle->requestCM33Start = false;
    sharedHandle->targetPowerMode = kPower_DeepPowerDown1;

    /* 4. Software configuration for CM33. */
    SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;
    __DSB();
    __ISB();
    __WFI();

    return kStatus_Success;
#elif __CORTEX_M == 0U
    sharedHandle->requestCM33Start = true;
    return Power_ReqestCM33StartLpSeq(kPower_DeepPowerDown1);
#endif /* __CORTEX_M == 33U */
}

power_dpd1_transition_t Power_GetDeepPowerDown1NextTransition(void)
{
    power_handle_t *sharedHandle = (power_handle_t *)(POWER_SHARED_RAM_BASE_ADDR + g_Handle_Offset);
    power_dpd1_config_t config;
    memcpy(&config, sharedHandle->lpConfig, sizeof(power_dpd1_config_t));
    
    return config.nextTrans;
}

/*!
 * brief Enter Deep Power Down 2 mode.
 * 
 * This function attempts to put the system into Deep Power Down 2 mode with the provided configuration.
 * 
 * param[in] config Pointer to the Deep Power Down 2 mode configuration.
 * 
 * retval kStatus_Success Successfully entered Deep Power Down 2 mode.
 * retval kStatus_POWER_MuTransferError Something error occurs during MU transfer.
 * retval kStatus_POWER_RequestNotAllowed Request not allowed by another core.
 */
status_t Power_EnterDeepPowerDown2(power_dpd2_config_t *config)
{
    power_handle_t *sharedHandle = (power_handle_t *)(POWER_SHARED_RAM_BASE_ADDR + g_Handle_Offset);
    memcpy(sharedHandle->lpConfig, config, sizeof(power_dpd2_config_t));

#if __CORTEX_M == 33U    
    //patch
    uint32_t *ptr = (uint32_t *)0xA0098038;
    *ptr |= (1 << 11); // Set the 8th bit (bit 7, as bits are 0-indexed)
    
    /*1. Configuration for SMM. */
    SMM_PowerOffAonSramAutomatically(AON__SMM, (uint8_t)(~(config->aonRamArraysToRetain)));
    SMM_EnableMainDomainSramRetention(AON__SMM, config->mainRamArraysToRetain);
    SMM_ShutDownBandgapInLowPowerModes(AON__SMM, config->disableBandgap);
    SMM_EnableIvsModeForSramRetention(AON__SMM, config->enableIVSMode);
    SMM_SwitchToXTAL32(AON__SMM, config->switchToX32K);
    if (config->switchToX32K)
    {
        AON__CGU->CLK_CONFIG |= CGU_CLK_CONFIG_ROOT_AUX_CLK_EN_MASK;
    }  
    SMM_StartAonDPD2Sequence(AON__SMM);

    /*2. Software configuration for CM0P. */
    if (sharedHandle->requestCM33Start != true)
    {
        /* Inform CM0P to execute WFI. */
        power_mu_message_t msg = {
            .strcutFormat = {
                .syncCode = 0x5A,
                .type = kPower_MsgTypeRequest,
                .direction = kPower_MsgDirMainToAon,
                .reqestLowPowerMode = kPower_DeepPowerDown2,
                .sharedHandleAddrOff = 0UL,
            }
        };
        g_powerMuTransferState = kPower_MuTransferStart;
        g_powerRequestMuMsg = msg;
        MU_SendMsg(MUA, sharedHandle->muChannelId, (uint32_t)msg.wordFormat);

        /* Waiting for response from CM0P. */
        while(g_powerMuTransferState == kPower_MuTransferStart)
        {
        }
        if (g_powerMuTransferState == kPower_MuTransferWrong)
        {
            return kStatus_POWER_MuTransferError;
        }
        if (g_powerMuTransferState == kPower_MuTransferEndWithNACK)
        {
            return kStatus_POWER_RequestNotAllowed;
        }
        g_powerMuTransferState = kPower_MuTransferIdle;
    }
    /* 3. Configuration for CMC */
    CMC_SetPowerModeProtection(CMC, kCMC_AllowAllLowPowerModes);
    CMC_SetClockMode(CMC, kCMC_GateAllSystemClocksEnterLowPowerMode);
    CMC_SetGlobalPowerMode(CMC, kCMC_DeepPowerDown);
    sharedHandle->requestCM33Start = false;
    sharedHandle->targetPowerMode = kPower_DeepPowerDown2;
    
    if (config->disableFRO10M)
    {
        AON__CGU->CLK_CONFIG |= CGU_CLK_CONFIG_ROOT_AUX_CLK_EN_MASK;
        AON__CGU->CLK_CONFIG = (AON__CGU->CLK_CONFIG & ~CGU_CLK_CONFIG_ROOT_CLK_SEL_MASK) | CGU_CLK_CONFIG_ROOT_CLK_SEL(3U);
        AON__CGU->CLK_CONFIG &= ~(CGU_CLK_CONFIG_FRO10M_EN_MASK | CGU_CLK_CONFIG_FRO2M_EN_MASK);
    }    
    /* 4. Software configuration for CM33. */
    SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;
    __DSB();
    __ISB();
    __WFI();

    return kStatus_Success;
#else
    status_t status = kStatus_Success;
    power_low_power_mode_t curLpMode;
    status = Power_GetCurrentPowerMode(&curLpMode);
    
    if (status == kStatus_Success)
    {
        if (curLpMode != kPower_DeepPowerDown1)
        {
            /* If current system is not in DPD1 mode, request CM33 to start DPD2 entry sequence. */
            sharedHandle->requestCM33Start = true;

            status = Power_ReqestCM33StartLpSeq(kPower_DeepPowerDown2);
        }
        else
        {
            /* If current system is in DPD1 mode, enter DPD2 from DPD1.  */
            sharedHandle->targetPowerMode = kPower_DeepPowerDown2;
            //patch
            uint32_t *ptr = (uint32_t *)0xA0098038;
            *ptr |= (1 << 11); // Set the 8th bit (bit 7, as bits are 0-indexed)
            /*1. Configuration for SMM. */
            SMM_PowerOffAonSramAutomatically(AON__SMM, (uint8_t)(~(config->aonRamArraysToRetain)));
            SMM_EnableMainDomainSramRetention(AON__SMM, config->mainRamArraysToRetain);
            SMM_ShutDownBandgapInLowPowerModes(AON__SMM, config->disableBandgap);
            SMM_EnableIvsModeForSramRetention(AON__SMM, config->enableIVSMode);
            SMM_SwitchToXTAL32(AON__SMM, config->switchToX32K);
            if (config->switchToX32K)
            {
                AON__CGU->CLK_CONFIG |= CGU_CLK_CONFIG_ROOT_AUX_CLK_EN_MASK;
            }  
            SMM_StartAonDPD2Sequence(AON__SMM);
            (void)AON__SMM->PWDN_CONFIG;
            if (config->disableFRO10M)
            {
                AON__CGU->CLK_CONFIG |= CGU_CLK_CONFIG_ROOT_AUX_CLK_EN_MASK;
                AON__CGU->CLK_CONFIG = (AON__CGU->CLK_CONFIG & ~CGU_CLK_CONFIG_ROOT_CLK_SEL_MASK) | CGU_CLK_CONFIG_ROOT_CLK_SEL(3U);
                AON__CGU->CLK_CONFIG &= ~(CGU_CLK_CONFIG_FRO10M_EN_MASK | CGU_CLK_CONFIG_FRO2M_EN_MASK);
            }    
            SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;
            __DSB();
            __ISB();
            __WFI();
        }
    }

    return status;
#endif /* __CORTEX_M == 33U */
}

/*!
 * brief Enter Deep Power Down 3 mode.
 * 
 * This function attempts to put the system into Deep Power Down 3 mode with the provided configuration.
 * 
 * param[in] config Pointer to the Deep Power Down 3 mode configuration.
 * 
 * retval kStatus_Success Successfully entered Deep Power Down 3 mode.
 * retval kStatus_POWER_MuTransferError Something error occurs during MU transfer.
 * retval kStatus_POWER_RequestNotAllowed Request not allowed by another core.
 */
status_t Power_EnterDeepPowerDown3(power_dpd3_config_t *config)
{
    power_handle_t *sharedHandle = (power_handle_t *)(POWER_SHARED_RAM_BASE_ADDR + g_Handle_Offset);
    memcpy(sharedHandle->lpConfig, config, sizeof(power_dpd3_config_t));
#if __CORTEX_M == 33U

    /* 1. Configuration of SMM. */
    SMM_StartAonShutDownSequence(AON__SMM);

    /*2. Software configuration for CM0P. */
    if (sharedHandle->requestCM33Start != true)
    {
        /* Inform CM0P to execute WFI. */
        power_mu_message_t msg = {
            .strcutFormat = {
                .syncCode = 0x5A,
                .type = kPower_MsgTypeRequest,
                .direction = kPower_MsgDirMainToAon,
                .reqestLowPowerMode = kPower_DeepPowerDown3,
                .sharedHandleAddrOff = 0UL,
            }
        };
        g_powerMuTransferState = kPower_MuTransferStart;
        g_powerRequestMuMsg = msg;
        MU_SendMsg(MUA, sharedHandle->muChannelId, (uint32_t)msg.wordFormat);

        /* Waiting for response from CM0P. */
        while(g_powerMuTransferState == kPower_MuTransferStart)
        {
        }
        if (g_powerMuTransferState == kPower_MuTransferWrong)
        {
            return kStatus_POWER_MuTransferError;
        }
        if (g_powerMuTransferState == kPower_MuTransferEndWithNACK)
        {
            return kStatus_POWER_RequestNotAllowed;
        }
        g_powerMuTransferState = kPower_MuTransferIdle;
    }

    /*3. Configuration of CMC */
    CMC_SetPowerModeProtection(CMC, kCMC_AllowAllLowPowerModes);
    CMC_SetClockMode(CMC, kCMC_GateAllSystemClocksEnterLowPowerMode);
    CMC_SetGlobalPowerMode(CMC, kCMC_DeepPowerDown);
    sharedHandle->requestCM33Start = false;
    sharedHandle->targetPowerMode = kPower_DeepPowerDown3;
    /* 4. Software configuration for CM33. */
    SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;
    __DSB();
    __ISB();
    __WFI();

    return kStatus_Success;
#else
    status_t status = kStatus_Success;
    sharedHandle->requestCM33Start = true;

    status = Power_ReqestCM33StartLpSeq(kPower_DeepPowerDown3);

    if (status == kStatus_Success)
    {
        SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;
        __DSB();
        __ISB();
        __WFI();
    }

    return status;
#endif /* __CORTEX == 33U */
}

/*!
 * brief Enter Shutdown mode.
 * 
 * This function attempts to put the system into Shutdown mode with the provided configuration.
 * 
 * param[in] config Pointer to the Shutdown mode configuration.
 * 
 * retval kStatus_Success Successfully entered Shutdown mode.
 * retval kStatus_POWER_MuTransferError Something error occurs during MU transfer.
 * retval kStatus_POWER_RequestNotAllowed Request not allowed by another core.
 */
status_t Power_EnterShutDown(power_sd_config_t *config)
{
    power_handle_t *sharedHandle = (power_handle_t *)(POWER_SHARED_RAM_BASE_ADDR + g_Handle_Offset);

    memcpy(sharedHandle->lpConfig, config, sizeof(power_sd_config_t));
#if __CORTEX_M == 33U
    /* 1. Configuration of SMM. */
    SMM_StartAonShutDownSequence(AON__SMM);

    /*2. Software configuration for CM0P. */
    if (sharedHandle->requestCM33Start != true)
    {
        /* Inform CM0P to execute WFI. */
        power_mu_message_t msg = {
            .strcutFormat = {
                .syncCode = 0x5A,
                .type = kPower_MsgTypeRequest,
                .direction = kPower_MsgDirMainToAon,
                .reqestLowPowerMode = kPower_ShutDown,
                .sharedHandleAddrOff = 0UL,
            }
        };
        g_powerMuTransferState = kPower_MuTransferStart;
        g_powerRequestMuMsg = msg;
        MU_SendMsg(MUA, sharedHandle->muChannelId, (uint32_t)msg.wordFormat);

        /* Waiting for response from CM0P. */
        while(g_powerMuTransferState == kPower_MuTransferStart)
        {
        }
        if (g_powerMuTransferState == kPower_MuTransferWrong)
        {
            return kStatus_POWER_MuTransferError;
        }
        if (g_powerMuTransferState == kPower_MuTransferEndWithNACK)
        {
            return kStatus_POWER_RequestNotAllowed;
        }
        g_powerMuTransferState = kPower_MuTransferIdle;
    }

    AON__SMM->RTC_DCDC_CNTRL &= ~(SMM_RTC_DCDC_CNTRL_LDO_EN_MASK);
    AON__SMM->RTC_XTAL_CONFG1 &= ~SMM_RTC_XTAL_CONFG1_XTAL_EN_MASK;
    AON__SMM->RTC_XTAL_CONFG2 &= ~(SMM_RTC_XTAL_CONFG2_CAP_BNK_EN_MASK | SMM_RTC_XTAL_CONFG2_SOX_EN_MASK);
    AON__SMM->RTC_DCDC_CNTRL |= SMM_RTC_DCDC_CNTRL_LDO_PULDWN_EN_MASK;
    /*3. Configuration of CMC */
    CMC_SetPowerModeProtection(CMC, kCMC_AllowAllLowPowerModes);
    CMC_SetClockMode(CMC, kCMC_GateAllSystemClocksEnterLowPowerMode);
    CMC_SetGlobalPowerMode(CMC, kCMC_DeepPowerDown);
    sharedHandle->requestCM33Start = false;
    sharedHandle->targetPowerMode = kPower_ShutDown;
    /* 4. Software configuration for CM33. */
    SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;
    __DSB();
    __ISB();
    __WFI();

    return kStatus_Success;
#elif __CORTEX_M == 0U
    status_t status = kStatus_Success;
    sharedHandle->requestCM33Start = true;

    status = Power_ReqestCM33StartLpSeq(kPower_ShutDown);

    if (status == kStatus_Success)
    {
        SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;
        __DSB();
        __ISB();
        __WFI();
    }

    return status;
#endif /* __CORTEX_M == 0U */
}

/*!
 * brief Callback function for handling power MU messages.
 * 
 * This function is called when a power MU message is received. It processes the message
 * based on the given message content and the channel ID.
 * 
 * param[in] message The received power MU message.
 * param[in] channelId The ID of the channel on which the message was received.
 * 
 * retval None This function does not return a value.
 */
void Power_MuMessageCallback(uint32_t message, uint32_t channelId)
{
    power_mu_message_t msg;
    uint32_t tmp32;
    power_mu_message_type_t resType;
    bool userAllowed = false;
    msg.wordFormat = message;
    power_low_power_mode_t targetLowPowerMode = msg.strcutFormat.reqestLowPowerMode;
    uint32_t lpConfigAddr = POWER_SHARED_RAM_BASE_ADDR + g_Handle_Offset + offsetof(power_handle_t, lpConfig[0]);
    power_user_callback_t curCallback = NULL;
    void *curCallbackData = NULL;
   
    if (msg.strcutFormat.type == kPower_MsgTypeRequest)
    {
        if (Power_VerifyMuMessage(message, true) != kStatus_Success)
        {
            resType = kPower_MsgTypeNACK;
        }
        else
        {
            if (msg.strcutFormat.init == true)
            {
                g_Handle_Offset = msg.strcutFormat.sharedHandleAddrOff;
                resType = kPower_MsgTypeACK;
            }
            else
            {
                power_handle_t *sharedHandle = (power_handle_t *)(POWER_SHARED_RAM_BASE_ADDR + g_Handle_Offset);
#if __CORTEX_M == 33U
                curCallback = sharedHandle->cm33Callback;
                curCallbackData = sharedHandle->cm33UserData;
#else
                curCallback = sharedHandle->cm0pCallback;
                curCallbackData = sharedHandle->cm0pUserData;
#endif
                if (curCallback != NULL)
                {
                    userAllowed = curCallback(targetLowPowerMode, (void *)lpConfigAddr, curCallbackData);
                }

                resType = ((userAllowed == false) ? kPower_MsgTypeNACK : kPower_MsgTypeACK);
            }
        }
        /* Return response to CM0P */
        tmp32 = Power_PopulateMuMessage(resType, kPower_MsgDirAonToMain, targetLowPowerMode, false, msg.strcutFormat.sharedHandleAddrOff);
        MU_SendMsg(POWER_USED_MU, channelId, tmp32);

        if (userAllowed)
        {
#if __CORTEX_M == 33U
            (void)Power_EnterLowPowerMode(targetLowPowerMode, (void *)lpConfigAddr);
#elif __CORTEX_M == 0U
            if ((targetLowPowerMode == kPower_PowerDown2) || ((targetLowPowerMode >= kPower_DeepPowerDown2) && (targetLowPowerMode < kPower_Active)))
            {
              /* If CM0P approve to enter target low power mode, execute WFI. */
              SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;
              __DSB();
              __ISB();
              __WFI();
            }
#endif /* __CORTEX_M */

        }
    }
    else
    {
        /* Handle response from CM0P */
        if (Power_VerifyMuMessage(message, false) != kStatus_Success)
        {
            g_powerMuTransferState = kPower_MuTransferWrong;
        }
        if (msg.strcutFormat.type == kPower_MsgTypeACK)
        {
            g_powerMuTransferState = kPower_MuTransferEndWithACK;
        }
        else
        {
            g_powerMuTransferState = kPower_MuTransferEndWithNACK;
        }
    }
}

