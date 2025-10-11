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

#include "fsl_advc.h"

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

/*!
 * @brief The union of lower half word of message.
 */
typedef union _power_mu_msg_2half_content
{
    uint16_t halfWordValueMask;
    uint16_t sharedHandleAddrOff; /* Used when message type is sync. */
    uint16_t NAckReason;          /* Used when message type is NACK. */
} power_mu_msg_2half_content_t;

/*!
 * brief Union representing a power MU message.
 */
typedef union _power_mu_message
{
    struct
    {
        uint32_t syncCode : 8U;            /*!< Synchronization code for the message */
        power_mu_message_type_t type : 2U; /*!< Type of the message, refer to ref power_mu_message_type_t */
        power_mu_message_direction_t
            direction : 1U;                /*!< Direction of the message, refer to ref power_mu_message_direction_t */
        power_low_power_mode_t reqestLowPowerMode : 4U; /*!< Requested low power mode */
        bool reserved : 1U;                             /*!< Reserved */
        power_mu_msg_2half_content_t lowHalfContent;    /*!< Contents of lower half word, different message type
                                                          indicate different meaning. */
    } strcutFormat;
    uint32_t wordFormat;                                /*!< Message in word format */
} power_mu_message_t;

typedef enum _power_mu_transfer_state
{
    kPower_MuTransferIdle        = 0U,
    kPower_MuTransferStart       = 1U,
    kPower_MuTransferEndWithNACK = 2U,
    kPower_MuTransferEndWithACK  = 3U,
    kPower_MuTransferWrong       = 4U,
} power_mu_transfer_state_t;

volatile power_mu_transfer_state_t g_powerMuTransferState = kPower_MuTransferIdle;

/*******************************************************************************
 * Variables
 ******************************************************************************/
volatile power_mu_message_t g_powerRequestMuMsg;

uint32_t g_Handle_Offset = 0xFFFFFFFFUL;

#if __CORTEX_M == 33U
#define POWER_USED_MU (MUA)
#elif __CORTEX_M == 0U
#define POWER_USED_MU (MUB)
#endif /* __CORTEX_M */

/*******************************************************************************
 * Code
 ******************************************************************************/

static status_t Power_VerifyMuMessage(uint32_t message)
{
    power_mu_message_t msg;
    msg.wordFormat = message;

    if (msg.strcutFormat.syncCode != 0x5A)
    {
        return kStatus_POWER_MuTransferError;
    }
    else
    {
        return kStatus_Success;
    }
}

static uint32_t Power_PopulateMuMessage(power_mu_message_type_t msgType,
                                        power_mu_message_direction_t msgDirection,
                                        power_low_power_mode_t lowPowerMode,
                                        uint16_t lowHalfWordValue)
{
    power_mu_message_t msg;

    msg.strcutFormat.syncCode                         = 0x5A;
    msg.strcutFormat.type                             = msgType;
    msg.strcutFormat.direction                        = msgDirection;
    msg.strcutFormat.reqestLowPowerMode               = lowPowerMode;
    msg.strcutFormat.lowHalfContent.halfWordValueMask = lowHalfWordValue;

    return msg.wordFormat;
}

static power_mu_nack_reason_t Power_GetMuNackReason(uint32_t message)
{
    power_mu_message_t msg;

    msg.wordFormat = message;

    return (power_mu_nack_reason_t)(msg.strcutFormat.lowHalfContent.NAckReason);
}

#if __CORTEX_M == 0U
static status_t Power_ReqestCM33StartLpSeq(power_low_power_mode_t targetMode)
{
    uint32_t tmp32            = 0UL;
    power_handle_t *curHandle = (power_handle_t *)(POWER_SHARED_RAM_BASE_ADDR + g_Handle_Offset);

    tmp32 =
        Power_PopulateMuMessage(kPower_MsgTypeRequest, kPower_MsgDirAonToMain, targetMode, (uint16_t)g_Handle_Offset);
    MU_SendMsg(POWER_USED_MU, curHandle->muChannelId, tmp32);

    /* Waiting for response from CM0P. */
    while (g_powerMuTransferState != kPower_MuTransferStart)
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
status_t Power_CreateHandle(power_handle_t *handle, uint32_t muChannelId)
{
#if __CORTEX_M == 33U
    assert((uint32_t)handle >= POWER_SHARED_RAM_BASE_ADDR);
#endif

    (void)memset(handle, 0UL, sizeof(power_handle_t));

    handle->muChannelId       = muChannelId;
    handle->targetPowerMode   = kPower_Active;
    handle->previousPowerMode = kPower_Active;

    handle->dualCoreSynced   = false;
    handle->requestCM33Start = false;

    /* Record offset of handle. */
    g_Handle_Offset = (uint32_t)handle - POWER_SHARED_RAM_BASE_ADDR;
    /* Inform another that attemp to create handle. */
    uint32_t tmp32 =
        Power_PopulateMuMessage(kPower_MsgTypeSync, kPower_MsgDirMainToAon, kPower_Active, (uint16_t)g_Handle_Offset);

    g_powerMuTransferState = kPower_MuTransferStart;
    MU_SendMsg(POWER_USED_MU, muChannelId, tmp32);

    /* Waiting for response from CM0P. */
    while (g_powerMuTransferState == kPower_MuTransferStart)
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

/*!
 * brief Dump contents of handle.
 *
 * param[out] ptrDumpBuffer The pointer to a buffer in type of ref power_handle_t to store dumped handle value.
 */
void Power_DumpHandleValue(power_handle_t *ptrDumpBuffer)
{
    power_handle_t *sharedHandle = (power_handle_t *)(POWER_SHARED_RAM_BASE_ADDR + g_Handle_Offset);

    memcpy(ptrDumpBuffer, sharedHandle, sizeof(power_handle_t));
}

/*!
 * brief Get the offset of shared handle in shared RAM.
 *
 * return Offset of shared handle in shared RAM, in bytes.
 */
uint32_t Power_GetHandleOffset(void)
{
    return g_Handle_Offset;
}

/*!
 * brief Restore the shared handle from offset in shared RAM.
 *
 * param[in] offset Offset of shared handle in shared RAM, in bytes.
 */
void Power_RestoreHandleOffset(uint32_t offset)
{
    g_Handle_Offset = offset;
}

/*!
 * brief Get configurations of latest requested low power mode.
 *
 * param[out] config The pointer to a buffer to store configurations of latest requested low power mode
 */
void Power_GetPowerModeConfig(void *config)
{
    power_handle_t handleBuf;

    Power_DumpHandleValue(&handleBuf);

    switch (handleBuf.previousPowerMode)
    {
        case kPower_DeepSleep:
        {
            (void)memcpy(config, handleBuf.lpConfig, sizeof(power_ds_config_t));
            break;
        }
        case kPower_PowerDown1:
        {
            (void)memcpy(config, handleBuf.lpConfig, sizeof(power_pd1_config_t));
            break;
        }
        case kPower_PowerDown2:
        {
            (void)memcpy(config, handleBuf.lpConfig, sizeof(power_pd2_config_t));
            break;
        }
        case kPower_DeepPowerDown1:
        {
            (void)memcpy(config, handleBuf.lpConfig, sizeof(power_dpd1_config_t));
            break;
        }
        case kPower_DeepPowerDown2:
        {
            (void)memcpy(config, handleBuf.lpConfig, sizeof(power_dpd2_config_t));
            break;
        }
        case kPower_DeepPowerDown3:
        {
            (void)memcpy(config, handleBuf.lpConfig, sizeof(power_dpd3_config_t));
            break;
        }
        case kPower_ShutDown:
        {
            (void)memcpy(config, handleBuf.lpConfig, sizeof(power_sd_config_t));
            break;
        }
        default:
        {
            /* Avoid violation of MISRA C-2012 rule. */
            break;
        }
    }
}

/*!
 * brief Get the target low power mode of latest request.
 *
 * return The target low power mode ref power_low_power_mode_t of latest request.
 */
power_low_power_mode_t Power_GetTargetLowPowerMode(void)
{
    power_handle_t *sharedHandle = (power_handle_t *)(POWER_SHARED_RAM_BASE_ADDR + g_Handle_Offset);

    return sharedHandle->targetPowerMode;
}

/*!
 * brief Enable input wakeup source, once enabled it will be effective until disabled
 *
 * param[in] ws Specify the coded wakeup source, please refer to power_wakeup_source_t for details.
 */
void Power_EnableWakeupSource(power_wakeup_source_t ws)
{
    uint32_t aonIndex;
    uint32_t pinEdge;
    uint32_t wakeupDomain;

    power_handle_t *sharedHandle = (power_handle_t *)(POWER_SHARED_RAM_BASE_ADDR + g_Handle_Offset);
    POWER_DECODE_WS((uint32_t)ws);

    if (ws == kPower_WS_NONE)
    {
        return;
    }

    if (wakeupDomain == 0U)
    {
        sharedHandle->enabledWsInfo.mainWakeupSourceMask |= 1UL << aonIndex;
    }
    else if (wakeupDomain == 1)
    {
        sharedHandle->enabledWsInfo.aonWakeupSourceMask |= 1UL << aonIndex;
    }
    else
    {
        sharedHandle->enabledWsInfo.mainWakeupSourceMask |= 1UL << aonIndex;
        sharedHandle->enabledWsInfo.aonWakeupSourceMask |= 1UL << aonIndex;
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

/*!
 * brief Disable input wakeup source.
 *
 * param[in] ws Specify the coded wakeup source, please refer to power_wakeup_source_t for details.
 */
void Power_DisableWakeupSource(power_wakeup_source_t ws)
{
    uint32_t aonIndex;
    uint32_t pinEdge;
    uint32_t wakeupDomain;
    power_handle_t *sharedHandle = (power_handle_t *)(POWER_SHARED_RAM_BASE_ADDR + g_Handle_Offset);

    POWER_DECODE_WS((uint32_t)ws);

    (void)pinEdge;

    if (ws == kPower_WS_NONE)
    {
        return;
    }

    if (wakeupDomain == 0)
    {
        sharedHandle->enabledWsInfo.mainWakeupSourceMask &= ~(1UL << aonIndex);
        SMM_DisableWakeupSourceToMainCpu(AON__SMM, (1UL << aonIndex));
    }
    else if (wakeupDomain == 1)
    {
        sharedHandle->enabledWsInfo.aonWakeupSourceMask &= ~(1UL << aonIndex);
        SMM_DisableWakeupSourceToAonCpu(AON__SMM, (1UL << aonIndex));
    }
    else
    {
        sharedHandle->enabledWsInfo.mainWakeupSourceMask &= ~(1UL << aonIndex);
        sharedHandle->enabledWsInfo.aonWakeupSourceMask &= ~(1UL << aonIndex);
        SMM_DisableWakeupSourceToAonCpu(AON__SMM, (1UL << aonIndex));
        SMM_DisableWakeupSourceToMainCpu(AON__SMM, (1UL << aonIndex));
    }
}

void Power_DisableAllWakeupSources(void)
{
    SMM_DisableWakeupSourceToMainCpu(AON__SMM, SMM_WKUP_MAIN_WKUP_SRC_MAIN_CPU_MASK);
    SMM_DisableWakeupSourceToAonCpu(AON__SMM, SMM_AON_CPU_WKUP_SRC_AON_CPU_MASK);
}

/*!
 * brief Dump information of all configured wakeup sources, in type of power_wakeup_source_info_t.
 *
 * param[out] ptrWsInfo Pointer to the variable to store dumped wakeup source information.
 */
void Power_DumpEnabledWakeSource(power_wakeup_source_info_t *ptrWsInfo)
{
    assert(ptrWsInfo);

    power_handle_t *sharedHandle = (power_handle_t *)(POWER_SHARED_RAM_BASE_ADDR + g_Handle_Offset);

    (void)memcpy((void *)ptrWsInfo, (void *)(&(sharedHandle->enabledWsInfo)), sizeof(power_wakeup_source_info_t));
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
 * brief Check selected wakeup source already enabled, if is enabled then disable it.
 *
 * param ws Specify the wakeup source in type of power_wakeup_source_t.
 */
void Power_CheckThenDisableWakeupSource(power_wakeup_source_t ws)
{
    uint32_t aonIndex;
    uint32_t pinEdge;
    uint32_t wakeupDomain;
    power_handle_t *sharedHandle = (power_handle_t *)(POWER_SHARED_RAM_BASE_ADDR + g_Handle_Offset);

    POWER_DECODE_WS((uint32_t)ws);

    (void)pinEdge;

    if (ws == kPower_WS_NONE)
    {
        return;
    }

    if (wakeupDomain == 0UL)
    {
        if ((sharedHandle->enabledWsInfo.mainWakeupSourceMask & (1UL << aonIndex)) != 0UL)
        {
            Power_DisableWakeupSource(ws);
        }
    }
    else if (wakeupDomain == 1UL)
    {
        if ((sharedHandle->enabledWsInfo.aonWakeupSourceMask & (1UL << aonIndex)) != 0UL)
        {
            Power_DisableWakeupSource(ws);
        }
    }
    else
    {
        if (((sharedHandle->enabledWsInfo.mainWakeupSourceMask & (1UL << aonIndex)) != 0UL) &&
            ((sharedHandle->enabledWsInfo.aonWakeupSourceMask & (1UL << aonIndex)) != 0UL))
        {
            Power_DisableWakeupSource(ws);
        }
    }
}

/*!
 * brief Check selected wakeup source is disabled, if is disabled then enable it.
 *
 * param ws Specify the wakeup source in type of power_wakeup_source_t.
 */
void Power_CheckThenEnableWakeupSource(power_wakeup_source_t ws)
{
    uint32_t aonIndex;
    uint32_t pinEdge;
    uint32_t wakeupDomain;
    power_handle_t *sharedHandle = (power_handle_t *)(POWER_SHARED_RAM_BASE_ADDR + g_Handle_Offset);

    POWER_DECODE_WS((uint32_t)ws);
    (void)pinEdge;

    if (ws == kPower_WS_NONE)
    {
        return;
    }

    if (wakeupDomain == 0U)
    {
        if ((sharedHandle->enabledWsInfo.mainWakeupSourceMask & (1UL << aonIndex)) == 0UL)
        {
            Power_EnableWakeupSource(ws);
        }
    }
    else if (wakeupDomain == 1)
    {
        if ((sharedHandle->enabledWsInfo.aonWakeupSourceMask & (1UL << aonIndex)) == 0UL)
        {
            Power_EnableWakeupSource(ws);
        }
    }
    else
    {
        if (((sharedHandle->enabledWsInfo.mainWakeupSourceMask & (1UL << aonIndex)) == 0UL) &&
            ((sharedHandle->enabledWsInfo.aonWakeupSourceMask & (1UL << aonIndex)) == 0UL))
        {
            Power_EnableWakeupSource(ws);
        }
    }
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

/*!
 * brief Get previous power mode.
 *
 * return The previous power mode.
 */
power_low_power_mode_t Power_GetPreviousPowerMode(void)
{
    power_handle_t *sharedHandle = (power_handle_t *)(POWER_SHARED_RAM_BASE_ADDR + g_Handle_Offset);

    return sharedHandle->previousPowerMode;
}

/*!
 * brief Reset previous power mode as active mode.
 */
void Power_ResetPreviousPowerMode(void)
{
    power_handle_t *sharedHandle = (power_handle_t *)(POWER_SHARED_RAM_BASE_ADDR + g_Handle_Offset);

    sharedHandle->previousPowerMode = kPower_Active;
}

/*!
 * brief Get current power mode.
 *
 * param[out] ptrCurLpMode Pointer to store current low power mode
 *
 * retval kStatus_Success Successfully retrieved current low power mode.
 */
status_t Power_GetCurrentPowerMode(power_low_power_mode_t *ptrCurLpMode)
{
    assert(g_Handle_Offset != 0xFFFFFFFFUL);
    status_t status                     = kStatus_Success;
    uint8_t tmp8                        = SMM_GetPowerState(AON__SMM);
    power_handle_t *sharedHandle        = (power_handle_t *)(POWER_SHARED_RAM_BASE_ADDR + g_Handle_Offset);
    power_low_power_mode_t targetLpMode = sharedHandle->targetPowerMode;
    power_low_power_mode_t curLpMode    = kPower_Active;

    switch (tmp8)
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
        default:
        {
            status = kStatus_Fail;
            break;
        }
    }

    *ptrCurLpMode = curLpMode;
    return status;
}

/*!
 * brief Get the target low power mode.
 *
 * return Requested low power mode, in type of ref power_low_power_mode_t.
 */
power_low_power_mode_t Power_GetTargetPowerMode(void)
{
    power_handle_t *sharedHandle           = (power_handle_t *)(POWER_SHARED_RAM_BASE_ADDR + g_Handle_Offset);
    power_low_power_mode_t targetPowerMode = sharedHandle->targetPowerMode;

    return targetPowerMode;
}

/*!
 * brief Clear the target low power mode.
 */
void Power_ClearTargetPowerMode(void)
{
    power_handle_t *sharedHandle  = (power_handle_t *)(POWER_SHARED_RAM_BASE_ADDR + g_Handle_Offset);
    sharedHandle->targetPowerMode = kPower_Active;
}

/*!
 * brief Clear all low power settings.
 */
void Power_ClearLpPowerSettings(void)
{
#if __CORTEX_M == 33U
    SMM_DisableMainCpuIso(AON__SMM);
    SMM_ClearAllLowPowerSequence(AON__SMM);
    SMM_ClearMainCpuWakeupSources(AON__SMM);
    CMC_SetClockMode(CMC, kCMC_GateNoneClock);
    CMC_SetGlobalPowerMode(CMC, kCMC_ActiveOrSleepMode);
    AON__SMM->STAT      = SMM_STAT_DPD_SEQ_END_MASK | SMM_STAT_DPD_END_MASK;
    AON__SMM->LSB_BCKP1 = 0UL;
    AON__SMM->LSB_BCKP2 = 0UL;
    AON__SMM->MSB_BCKP2 = 0UL;
#elif __CORTEX_M == 0U
    SMM_DisableAonCpuIso(AON__SMM);
    SMM_ClearAllLowPowerSequence(AON__SMM);
    SMM_ClearAonCpuWakeupSources(AON__SMM);
#if 0
    AON__SMM->STAT = SMM_STAT_DPD_SEQ_END_MASK | SMM_STAT_DPD_END_MASK;
#endif
    AON__SMM->MSB_BCKP1 = 0UL;
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
    switch (lowpowerMode)
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
    power_handle_t *sharedHandle  = (power_handle_t *)(POWER_SHARED_RAM_BASE_ADDR + g_Handle_Offset);
    sharedHandle->targetPowerMode = kPower_Sleep;
    __DSB();
    __ISB();
    __WFI();
    sharedHandle->previousPowerMode = kPower_Sleep;

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
    (void)config;
#if __CORTEX_M == 33U
    /* Invoke CMC API to set Main domain as Deep power down mode and then
       execute WFI instruction. */
    CMC_SetPowerModeProtection(CMC, kCMC_AllowDeepSleepMode);
    CMC_SetClockMode(CMC, kCMC_GateAllSystemClocksEnterLowPowerMode);
    CMC_SetGlobalPowerMode(CMC, kCMC_DeepSleepMode);
    sharedHandle->requestCM33Start = false;
    sharedHandle->targetPowerMode  = kPower_DeepSleep;
    SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;
    __DSB();
    __WFI();
    __ISB();

    sharedHandle->previousPowerMode = kPower_DeepSleep;
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
    /*1. Enable wakeup sources.  */
    Power_CheckThenEnableWakeupSource(config->mainWakeupSource);

    /*2. Configuration for SMM and PMU. */
    SMM_EnableWakeupSourceToMainCpu(AON__SMM, sharedHandle->enabledWsInfo.mainWakeupSourceMask);
    SMM_EnableMainDomainSramRetention(AON__SMM, config->mainRamArraysToRetain);
    SMM_ShutDownBandgapInLowPowerModes(AON__SMM, false);
    SMM_EnableIvsModeForSramRetention(AON__SMM, config->enableIVSMode);
    SMM_StartPowerDownSequence(AON__SMM);

    /* 3. Configuration for CMC. */
    CMC_SetPowerModeProtection(CMC, kCMC_AllowAllLowPowerModes);
    CMC_SetClockMode(CMC, kCMC_GateAllSystemClocksEnterLowPowerMode);
    CMC->GPMCTRL = CMC_GPMCTRL_LPMODE((uint8_t)0x7);

    sharedHandle->requestCM33Start = false;
    sharedHandle->targetPowerMode  = kPower_PowerDown1;
    SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;
    __DSB();
    __ISB();
    __WFI();

    sharedHandle->previousPowerMode = kPower_PowerDown1;
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
    /* 1. Inform CM0P that CM33 request to set whole system into PD2 mode, require CM0P execute WFI. */
    if (sharedHandle->requestCM33Start != true)
    {
        /* Inform CM0P to execute WFI. */
        power_mu_message_t msg = {.strcutFormat = {
                                      .syncCode                         = 0x5A,
                                      .type                             = kPower_MsgTypeRequest,
                                      .direction                        = kPower_MsgDirMainToAon,
                                      .reqestLowPowerMode               = kPower_PowerDown2,
                                      .lowHalfContent.halfWordValueMask = 0UL,
                                  }};
        g_powerMuTransferState = kPower_MuTransferStart;
        g_powerRequestMuMsg    = msg;
        MU_SendMsg(POWER_USED_MU, sharedHandle->muChannelId, (uint32_t)msg.wordFormat);
        /* Waiting for response from CM0P. */
        while (g_powerMuTransferState == kPower_MuTransferStart)
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

    /* 2. Enable wakeup sources for different domain. */
    Power_CheckThenEnableWakeupSource(config->mainWakeupSource);
    Power_CheckThenEnableWakeupSource(config->aonWakeupSource);

    SMM_EnableWakeupSourceToMainCpu(AON__SMM, sharedHandle->enabledWsInfo.mainWakeupSourceMask);
    SMM_EnableWakeupSourceToAonCpu(AON__SMM, sharedHandle->enabledWsInfo.aonWakeupSourceMask);

    /* 3. Configuration for SMM and PMU. */
    if (config->vddCoreAonVoltage != kPower_VddCoreAon_AdvcControl)
    {
        PMU_UpdateVDDCoreInActiveMode(AON__PMU, config->vddCoreAonVoltage);
    }
    SMM_PowerOffAonSramAutomatically(AON__SMM, (uint8_t)(~(config->aonRamArraysToRetain)));
    SMM_EnableMainDomainSramRetention(AON__SMM, config->mainRamArraysToRetain);
    SMM_ShutDownBandgapInLowPowerModes(AON__SMM, false);
    SMM_EnableIvsModeForSramRetention(AON__SMM, config->enableIVSMode);
    SMM_StartPowerDownSequence(AON__SMM);

    /* 4. Configuration for CMC. */
    CMC_SetPowerModeProtection(CMC, kCMC_AllowAllLowPowerModes);
    CMC_SetClockMode(CMC, kCMC_GateAllSystemClocksEnterLowPowerMode);
    CMC->GPMCTRL = CMC_GPMCTRL_LPMODE((uint8_t)0x7);

    /* Disable FRO10M is required. */
    if (sharedHandle->cm0pWFI == false)
    {
        return kStatus_Power_CM0PNotWFI;
    }
    else
    {
        if (config->disableFRO10M)
        {
            AON__CGU->CLK_CONFIG |= CGU_CLK_CONFIG_ROOT_AUX_CLK_EN_MASK;
            AON__CGU->CLK_CONFIG =
                (AON__CGU->CLK_CONFIG & ~CGU_CLK_CONFIG_ROOT_CLK_SEL_MASK) | CGU_CLK_CONFIG_ROOT_CLK_SEL(3U);
            AON__CGU->CLK_CONFIG &= ~(CGU_CLK_CONFIG_FRO10M_EN_MASK | CGU_CLK_CONFIG_FRO2M_EN_MASK);
        }

        sharedHandle->requestCM33Start  = false;
        sharedHandle->targetPowerMode   = kPower_PowerDown2;
        sharedHandle->previousPowerMode = kPower_PowerDown2;
        sharedHandle->cm0pWFI           = false;

        /* 5. Execute WFI. */
        SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;
        __DSB();
        __ISB();
        __WFI();
        return kStatus_Success;
    }

#elif __CORTEX_M == 0U
    status_t status                = kStatus_POWER_RequestNotAllowed;
    sharedHandle->requestCM33Start = true;
    sharedHandle->targetPowerMode  = kPower_PowerDown2;
    power_low_power_mode_t curLpMode;
    status = Power_GetCurrentPowerMode(&curLpMode);

    if (status == kStatus_Success)
    {
        if (curLpMode != kPower_PowerDown1)
        {
            /* If system is not in Power Down1 Mode, request CM33 to start sequence to enter PD2. */
            status = Power_ReqestCM33StartLpSeq(kPower_PowerDown2);
        }
        else
        { /* System is in PD1 mode, */

            /*1. Enable wakeup sources.*/
            Power_CheckThenEnableWakeupSource(config->mainWakeupSource);
            Power_CheckThenEnableWakeupSource(config->aonWakeupSource);

            SMM_EnableWakeupSourceToMainCpu(AON__SMM, sharedHandle->enabledWsInfo.mainWakeupSourceMask);
            SMM_EnableWakeupSourceToAonCpu(AON__SMM, sharedHandle->enabledWsInfo.aonWakeupSourceMask);

            /*2. Update SMM settings. */
            SMM_PowerOffAonSramAutomatically(AON__SMM, (uint8_t)(~(config->aonRamArraysToRetain)));
            SMM_EnableMainDomainSramRetention(AON__SMM, config->mainRamArraysToRetain);
            SMM_ShutDownBandgapInLowPowerModes(AON__SMM, false);
            SMM_EnableIvsModeForSramRetention(AON__SMM, config->enableIVSMode);

            if (config->disableFRO10M)
            {
                AON__CGU->CLK_CONFIG |= CGU_CLK_CONFIG_ROOT_AUX_CLK_EN_MASK;
                AON__CGU->CLK_CONFIG =
                    (AON__CGU->CLK_CONFIG & ~CGU_CLK_CONFIG_ROOT_CLK_SEL_MASK) | CGU_CLK_CONFIG_ROOT_CLK_SEL(3U);
                AON__CGU->CLK_CONFIG &= ~(CGU_CLK_CONFIG_FRO10M_EN_MASK | CGU_CLK_CONFIG_FRO2M_EN_MASK);
            }

            sharedHandle->previousPowerMode = kPower_PowerDown2;
            /*3. Execute WFI to enter PD2. */
            SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;
            sharedHandle->cm0pWFI = true;
            __DSB();
            __ISB();
            __WFI();
        }
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
    Power_CheckThenEnableWakeupSource(config->mainWakeupSource);
    SMM_EnableWakeupSourceToMainCpu(AON__SMM, sharedHandle->enabledWsInfo.mainWakeupSourceMask);

    /* 1. Configuration for SMM and PMU. */
    if (config->vddCoreAonVoltage != kPower_VddCoreAon_AdvcControl)
    {
        PMU_UpdateVDDCoreInActiveMode(AON__PMU, config->vddCoreAonVoltage);
    }
    SMM_EnableMainDomainSramRetention(AON__SMM, config->mainRamArraysToRetain);
    SMM_ShutDownBandgapInLowPowerModes(AON__SMM, config->disableBandgap);
    SMM_EnableIvsModeForSramRetention(AON__SMM, config->enableIVSMode);
    SMM_StartPowerDownSequence(AON__SMM);

    /* 2. Configuration for CMC. */
    CMC_SetPowerModeProtection(CMC, kCMC_AllowAllLowPowerModes);
    CMC_SetClockMode(CMC, kCMC_GateAllSystemClocksEnterLowPowerMode);
    CMC_SetGlobalPowerMode(CMC, kCMC_DeepPowerDown);
    sharedHandle->requestCM33Start  = false;
    sharedHandle->targetPowerMode   = kPower_DeepPowerDown1;
    sharedHandle->previousPowerMode = kPower_DeepPowerDown1;

    if (config->mainRamArraysToRetain != kPower_MainDomainNoneRams)
    {
        AON__SMM->LSB_BCKP1 = 0UL;
        if (Power_PushContext((uint32_t)sharedHandle) == 0UL)
        {
            SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;
            __DSB();
            __ISB();
            __WFI();
        }
        g_Handle_Offset                 = (uint32_t)((uint32_t)sharedHandle - POWER_SHARED_RAM_BASE_ADDR);
        sharedHandle->previousPowerMode = kPower_DeepPowerDown1;
        return kStatus_Power_WakeupFromDPD1;
    }
    else
    {
        /* 3. Software configuration for CM33. */
        SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;
        __DSB();
        __ISB();
        __WFI();

        return kStatus_Success;
    }
#elif __CORTEX_M == 0U
    sharedHandle->requestCM33Start = true;
    return Power_ReqestCM33StartLpSeq(kPower_DeepPowerDown1);
#endif /* __CORTEX_M == 33U */
}

/*!
 * brief Get the next transition after Deep Power Down 1 mode.
 *
 * return Next transition after Deep Power Down 1 mode, in type of power_dpd1_transition_t.
 */
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
    /*1. Inform CM0P that CM33 request to set whole system into DPD2 mode, require CM0P execute WFI. */
    if (sharedHandle->requestCM33Start != true)
    {
        /* Inform CM0P to execute WFI. */
        power_mu_message_t msg = {.strcutFormat = {
                                      .syncCode                         = 0x5A,
                                      .type                             = kPower_MsgTypeRequest,
                                      .direction                        = kPower_MsgDirMainToAon,
                                      .reqestLowPowerMode               = kPower_DeepPowerDown2,
                                      .lowHalfContent.halfWordValueMask = 0UL,
                                  }};
        g_powerMuTransferState = kPower_MuTransferStart;
        g_powerRequestMuMsg    = msg;
        MU_SendMsg(POWER_USED_MU, sharedHandle->muChannelId, (uint32_t)msg.wordFormat);

        /* Waiting for response from CM0P. */
        while (g_powerMuTransferState == kPower_MuTransferStart)
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

    /*2. Enable wakeup sources for main and aon domain. */
    Power_CheckThenEnableWakeupSource(config->mainWakeupSource);
    Power_CheckThenEnableWakeupSource(config->aonWakeupSource);

    SMM_EnableWakeupSourceToMainCpu(AON__SMM, sharedHandle->enabledWsInfo.mainWakeupSourceMask);
    SMM_EnableWakeupSourceToAonCpu(AON__SMM, sharedHandle->enabledWsInfo.aonWakeupSourceMask);

    /*3. Configuration for SMM and PMU. */
    PMU_UpdateVDDCoreInLpMode(AON__PMU, (uint8_t)config->dpd2VddCoreAonVoltage);
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

    /* 4. Configuration for CMC */
    CMC_SetPowerModeProtection(CMC, kCMC_AllowAllLowPowerModes);
    CMC_SetClockMode(CMC, kCMC_GateAllSystemClocksEnterLowPowerMode);
    CMC_SetGlobalPowerMode(CMC, kCMC_DeepPowerDown);

    if (sharedHandle->cm0pWFI == false)
    {
        return kStatus_Power_CM0PNotWFI;
    }
    else
    {
        if (config->disableFRO10M)
        {
            AON__CGU->CLK_CONFIG |= CGU_CLK_CONFIG_ROOT_AUX_CLK_EN_MASK;
            AON__CGU->CLK_CONFIG =
                (AON__CGU->CLK_CONFIG & ~CGU_CLK_CONFIG_ROOT_CLK_SEL_MASK) | CGU_CLK_CONFIG_ROOT_CLK_SEL(3U);
            AON__CGU->CLK_CONFIG &= ~(CGU_CLK_CONFIG_FRO10M_EN_MASK | CGU_CLK_CONFIG_FRO2M_EN_MASK);
        }

        sharedHandle->requestCM33Start  = false;
        sharedHandle->targetPowerMode   = kPower_DeepPowerDown2;
        sharedHandle->previousPowerMode = kPower_DeepPowerDown2;
        sharedHandle->cm0pWFI           = false;

        /* Disable ADVC in DPD2 mode. */
        if (ADVC_IsEnabled() == true)
        {
            ADVC_Disable();
        }

        /* 5. Software configuration for CM33. */
        SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;
        __DSB();
        __ISB();
        __WFI();

        return kStatus_Success;
    }
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

            /*1. Enable wakeup sources for main and aon domain. */
            Power_CheckThenEnableWakeupSource(config->mainWakeupSource);
            Power_CheckThenEnableWakeupSource(config->aonWakeupSource);

            SMM_EnableWakeupSourceToMainCpu(AON__SMM, sharedHandle->enabledWsInfo.mainWakeupSourceMask);
            SMM_EnableWakeupSourceToAonCpu(AON__SMM, sharedHandle->enabledWsInfo.aonWakeupSourceMask);

            /*2. Configuration for SMM and PMU. */
            /* Disable ADVC in DPD2 mode. */
            if (ADVC_IsEnabled() == true)
            {
                ADVC_Disable();
            }
            PMU_UpdateVDDCoreInLpMode(AON__PMU, (uint8_t)config->dpd2VddCoreAonVoltage);
            SMM_PowerOffAonSramAutomatically(AON__SMM, (uint8_t)(~(config->aonRamArraysToRetain)));
            SMM_EnableMainDomainSramRetention(AON__SMM, config->mainRamArraysToRetain);
            SMM_ShutDownBandgapInLowPowerModes(AON__SMM, config->disableBandgap);
            SMM_EnableIvsModeForSramRetention(AON__SMM, config->enableIVSMode);
            SMM_SwitchToXTAL32(AON__SMM, config->switchToX32K);
            if (config->switchToX32K)
            {
                AON__CGU->CLK_CONFIG |= CGU_CLK_CONFIG_ROOT_AUX_CLK_EN_MASK;
            }

            if (config->disableFRO10M)
            {
                AON__CGU->CLK_CONFIG |= CGU_CLK_CONFIG_ROOT_AUX_CLK_EN_MASK;
                AON__CGU->CLK_CONFIG =
                    (AON__CGU->CLK_CONFIG & ~CGU_CLK_CONFIG_ROOT_CLK_SEL_MASK) | CGU_CLK_CONFIG_ROOT_CLK_SEL(3U);
                AON__CGU->CLK_CONFIG &= ~(CGU_CLK_CONFIG_FRO10M_EN_MASK | CGU_CLK_CONFIG_FRO2M_EN_MASK);
            }

            sharedHandle->previousPowerMode = kPower_DeepPowerDown2;

            /*3. CM0P. Execute WFI */
            SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;
            sharedHandle->cm0pWFI = true;

            if ((config->wakeToDpd1 == true) && (config->aonRamArraysToRetain != kPower_AonDomainNoneRams))
            {
                if (Power_PushContext((uint32_t)sharedHandle) == 0UL)
                {
                    AON__SMM->PWDN_CONFIG |= SMM_PWDN_CONFIG_DPD2_AON_MASK;
                    (void)AON__SMM->PWDN_CONFIG;
                    __DSB();
                    __ISB();
                    __WFI();
                }
                AON__SMM->MSB_BCKP1 = SMM_MSB_BCKP1_MSB1(0UL);
                g_Handle_Offset     = (uint32_t)((uint32_t)sharedHandle - POWER_SHARED_RAM_BASE_ADDR);

                return kStatus_Power_WakeupFromDPD2;
            }
            else
            {
                AON__SMM->MSB_BCKP1 = SMM_MSB_BCKP1_MSB1(0UL);
                AON__SMM->PWDN_CONFIG |= SMM_PWDN_CONFIG_DPD2_AON_MASK;
                (void)AON__SMM->PWDN_CONFIG;
                __DSB();
                __ISB();
                __WFI();

                return kStatus_Fail;
            }
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
    /*1. Inform CM0P that CM33 request to set whole system into DPD3 mode, require CM0P execute WFI. */
    if (sharedHandle->requestCM33Start != true)
    {
        /* Inform CM0P to execute WFI. */
        power_mu_message_t msg = {.strcutFormat = {
                                      .syncCode                         = 0x5A,
                                      .type                             = kPower_MsgTypeRequest,
                                      .direction                        = kPower_MsgDirMainToAon,
                                      .reqestLowPowerMode               = kPower_DeepPowerDown3,
                                      .lowHalfContent.halfWordValueMask = 0UL,
                                  }};
        g_powerMuTransferState = kPower_MuTransferStart;
        g_powerRequestMuMsg    = msg;
        MU_SendMsg(POWER_USED_MU, sharedHandle->muChannelId, (uint32_t)msg.wordFormat);

        /* Waiting for response from CM0P. */
        while (g_powerMuTransferState == kPower_MuTransferStart)
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

    /*2. Enable wakeup source to wakeup the whole system. */
    Power_CheckThenEnableWakeupSource(config->wakeupSource);
    SMM_EnableWakeupSourceToMainCpu(AON__SMM, sharedHandle->enabledWsInfo.mainWakeupSourceMask);
    SMM_EnableWakeupSourceToAonCpu(AON__SMM, sharedHandle->enabledWsInfo.aonWakeupSourceMask);

    /*3. Configuration of SMM. */
    SMM_StartAonShutDownSequence(AON__SMM);

    /*4. Configuration of CMC */
    CMC_SetPowerModeProtection(CMC, kCMC_AllowAllLowPowerModes);
    CMC_SetClockMode(CMC, kCMC_GateAllSystemClocksEnterLowPowerMode);
    CMC_SetGlobalPowerMode(CMC, kCMC_DeepPowerDown);

    if (sharedHandle->cm0pWFI == false)
    {
        return kStatus_Power_CM0PNotWFI;
    }
    else
    {
        sharedHandle->cm0pWFI           = false;
        sharedHandle->requestCM33Start  = false;
        sharedHandle->targetPowerMode   = kPower_DeepPowerDown3;
        sharedHandle->previousPowerMode = kPower_DeepPowerDown3;
        /* 5. Software configuration for CM33. */
        SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;
        __DSB();
        __ISB();
        __WFI();
    }

    return kStatus_Success;
#else
    status_t status                = kStatus_Success;
    sharedHandle->requestCM33Start = true;

    status = Power_ReqestCM33StartLpSeq(kPower_DeepPowerDown3);

    if (status == kStatus_Success)
    {
        SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;
        sharedHandle->cm0pWFI = true;
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
    /*1. Inform CM0P that CM33 request to set whole system into SD mode, require CM0P execute WFI.  */
    if (sharedHandle->requestCM33Start != true)
    {
        /* Inform CM0P to execute WFI. */
        power_mu_message_t msg = {.strcutFormat = {
                                      .syncCode                         = 0x5A,
                                      .type                             = kPower_MsgTypeRequest,
                                      .direction                        = kPower_MsgDirMainToAon,
                                      .reqestLowPowerMode               = kPower_ShutDown,
                                      .lowHalfContent.halfWordValueMask = 0UL,
                                  }};
        g_powerMuTransferState = kPower_MuTransferStart;
        g_powerRequestMuMsg    = msg;
        MU_SendMsg(POWER_USED_MU, sharedHandle->muChannelId, (uint32_t)msg.wordFormat);

        /* Waiting for response from CM0P. */
        while (g_powerMuTransferState == kPower_MuTransferStart)
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

    /*2. Enable wakeup source to wakeup the whole system. */
    Power_CheckThenEnableWakeupSource(config->wakeupSource);
    SMM_EnableWakeupSourceToMainCpu(AON__SMM, sharedHandle->enabledWsInfo.mainWakeupSourceMask);
    SMM_EnableWakeupSourceToAonCpu(AON__SMM, sharedHandle->enabledWsInfo.aonWakeupSourceMask);

    /*3. Configuration of SMM and PMU. */

    PMU_UpdateFRO16KFreq(AON__PMU, config->fro16KOutputFreq);
    PMU_UpdateWakeupTime(AON__PMU, 0x7F8);
    /* Clean all settings of RTC. */
    AON__SMM->RTC_DCDC_CNTRL  = 0xe00;
    AON__SMM->RTC_XTAL_CONFG1 = 0x0UL;
    AON__SMM->RTC_XTAL_CONFG2 = 0x0UL;
    SMM_StartAonShutDownSequence(AON__SMM);

    /*4. Configuration of CMC */
    CMC_SetPowerModeProtection(CMC, kCMC_AllowAllLowPowerModes);
    CMC_SetClockMode(CMC, kCMC_GateAllSystemClocksEnterLowPowerMode);
    CMC_SetGlobalPowerMode(CMC, kCMC_DeepPowerDown);

    if (sharedHandle->cm0pWFI == false)
    {
        return kStatus_Power_CM0PNotWFI;
    }
    else
    {
        sharedHandle->requestCM33Start  = false;
        sharedHandle->targetPowerMode   = kPower_ShutDown;
        sharedHandle->previousPowerMode = kPower_ShutDown;
        /* 5. Software configuration for CM33. */
        SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;
        __DSB();
        __ISB();
        __WFI();
        return kStatus_Success;
    }

#elif __CORTEX_M == 0U
    status_t status                = kStatus_Success;
    sharedHandle->requestCM33Start = true;

    status = Power_ReqestCM33StartLpSeq(kPower_ShutDown);

    if (status == kStatus_Success)
    {
        SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;
        sharedHandle->cm0pWFI = true;
        __DSB();
        __ISB();
        __WFI();
    }

    return status;
#endif /* __CORTEX_M == 0U */
}

/*!
 * brief Save current context into stack.
 *      ---------    <-----High address
        |  D15  |       -----
        ---------           |
        |  D14  |           |
        ---------           |
        |  D13  |           |
        ---------           |
        |  D12  |           |
        ---------           |---- Only CM33
        |  D11  |           |
        ---------           |
        |  D10  |           |
        ---------           |
        |  D9   |           |
        ---------           |
        |  D8   |       -----
        ---------
        |  LR   |
        ---------
        |  R12  |
        ---------
        |  R11  |
        ---------
        |  R10  |
        ---------
        |  R9   |
        ---------
        |  R8   |
        ---------
        |  R7   |
        ---------
        |  R6   |
        ---------
        |  R5   |
        ---------
        |  R4   |
        ---------
        | handle|
        | value |
        ---------
        | handle|
        | addr  |
        ---------
        | ASPR  |
        ---------
        | PSR   |
        ---------
        |PRIMASK|
        ---------
        |CONTROL|
        ---------  <------ SP Address saved in backup register
 * param handleAddr The address of handle.
 *
 * retval 0 Return 0 before entering low power modes. 
 * retval 1 Return 1 after waking up from low power modes.
 */
uint32_t Power_PushContext(uint32_t handleAddr)
{
    /* Stack layout:
        ---------    <-----High address
        |  D15  |       -----
        ---------           |
        |  D14  |           |
        ---------           |
        |  D13  |           |
        ---------           |
        |  D12  |           |
        ---------           |---- Only CM33
        |  D11  |           |
        ---------           |
        |  D10  |           |
        ---------           |
        |  D9   |           |
        ---------           |
        |  D8   |       -----
        ---------
        |  LR   |
        ---------
        |  R12  |
        ---------
        |  R11  |
        ---------
        |  R10  |
        ---------
        |  R9   |
        ---------
        |  R8   |
        ---------
        |  R7   |
        ---------
        |  R6   |
        ---------
        |  R5   |
        ---------
        |  R4   |
        ---------
        | handle|
        | value |
        ---------
        | handle|
        | addr  |
        ---------
        | ASPR  |
        ---------
        | PSR   |
        ---------
        |PRIMASK|
        ---------
        |CONTROL|
        ---------  <------ SP Address saved in backup register
    */
#ifdef __ARMVFP__
    /* push FPU registers. */
    asm volatile("VSTMDB sp!, {D15}");
    asm volatile("VSTMDB sp!, {D14}");
    asm volatile("VSTMDB sp!, {D13}");
    asm volatile("VSTMDB sp!, {D12}");
    asm volatile("VSTMDB sp!, {D11}");
    asm volatile("VSTMDB sp!, {D10}");
    asm volatile("VSTMDB sp!, {D9}");
    asm volatile("VSTMDB sp!, {D8}");
#endif
    /* push LR */
    asm volatile("PUSH {lr}");

    /* push r12 */
    asm volatile("PUSH {r0}");
    asm volatile("MOV r0, r12");
    asm volatile("POP {r1}");
    asm volatile("PUSH {r0}");
    asm volatile("MOV r12, r1");

    /* push r11, r10, r9, r8. */
    asm volatile("MOV r0, r8");
    asm volatile("MOV r1, r9");
    asm volatile("MOV r2, r10");
    asm volatile("MOV r3, r11");
    asm volatile("PUSH {r0-r3}");

    /* push r7, r6, r5, r4. */
    asm volatile("PUSH {r4-r7}");

    /* push value of current handle.*/
    asm volatile("MOV r0, r12");
    asm volatile("LDR r1, [r0, #40]"); /* Latest word */
    asm volatile("PUSH {r1}");
    asm volatile("LDR r1, [r0, #36]"); /* handle->enabledWsInfo.mainWakeupSourceMask. */
    asm volatile("PUSH {r1}");
    asm volatile("LDR r1, [r0, #32]"); /* handle->enabledWsInfo.aonWakeupSourceMask. */
    asm volatile("PUSH {r1}");
    asm volatile("LDR r1, [r0, #28]"); /* handle->cm0pUserData. */
    asm volatile("PUSH {r1}");
    asm volatile("LDR r1, [r0, #24]"); /* handle->cm0pCallback. */
    asm volatile("PUSH {r1}");
    asm volatile("LDR r1, [r0, #20]"); /* handle->cm33UserData. */
    asm volatile("PUSH {r1}");
    asm volatile("LDR r1, [r0, #16]"); /* handle->cm33Callback. */
    asm volatile("PUSH {r1}");
    asm volatile("LDR r1, [r0, #12]"); /* handle->lpConfig[3]. */
    asm volatile("PUSH {r1}");
    asm volatile("LDR r1, [r0, #8]");  /* handle->lpConfig[2]. */
    asm volatile("PUSH {r1}");
    asm volatile("LDR r1, [r0, #4]");  /* handle->lpConfig[1]. */
    asm volatile("PUSH {r1}");
    asm volatile("LDR r1, [r0, #0]");  /* handle->lpConfig[0]. */
    asm volatile("PUSH {r1}");
    asm volatile("PUSH {r0}");

    /* push aspr, psr, PRIMASK, CONTROL */
    asm volatile("MRS r0, CONTROL");
    asm volatile("MRS r1, PRIMASK");
    asm volatile("MRS r2, psr");
    asm volatile("MRS r3, apsr");
    asm volatile("PUSH {r0-r3}");

    /* save current sp to backup register */
#if __CORTEX_M == 33U
    asm volatile("MOV R0, SP");
    asm volatile("UXTH R1, R0");
    asm volatile("LDR R2, =0xA009A034");
    asm volatile("STR R1, [R2]");
    asm volatile("LSRS R1, R0, #16");
    asm volatile("LDR R2, =0xA009A038");
    asm volatile("STR R1, [R2]");
#else
    asm volatile("MOV R0, SP");
    asm volatile("LDR R2, =0xA009A030");
    asm volatile("STR R0, [R2]");
#endif

    asm volatile("MOVS R0, #0");
    asm volatile("BX LR");

    return 0;
}

#define POWER_BCKP1_MSB_VALUE (uint32_t)(AON__SMM->MSB_BCKP1 & SMM_MSB_BCKP1_MSB1_MASK)

#define POWER_BCKP2_VALUE                                        \
    (uint32_t)((AON__SMM->LSB_BCKP2 & SMM_LSB_BCKP2_LSB2_MASK) | \
               ((AON__SMM->MSB_BCKP2 & SMM_MSB_BCKP2_MSB2_MASK) << 16UL))

/*!
 * brief Restore saved context from stack.
 */
void Power_LowPowerBoot(void)
{
#if __CORTEX_M == 33U
    if (POWER_BCKP2_VALUE != 0UL)
    {
        AON__SMM->LSB_BCKP1 = 0x5A5A;
        asm volatile("MOV sp, %[input]"
                     : // no C variable outputs
                     : [input] "r"(POWER_BCKP2_VALUE)
                     : // No need to tell nothing to the compiler
        );
#else
    if (POWER_BCKP1_MSB_VALUE != 0UL)
    {
        asm volatile("MOV sp, %[input]"
                     : // no C variable outputs
                     : [input] "r"(POWER_BCKP1_MSB_VALUE)
                     : // No need to tell nothing to the compiler
        );
#endif

        asm volatile("POP {r0-r3}");
        asm volatile("MSR CONTROL, r0");
        asm volatile("MSR PRIMASK, r1");
#ifdef __IAR_SYSTEMS_ICC__
        __asm volatile("MSR psr, r2");
        __asm volatile("MSR APSR, r3");
#else
        __asm volatile("MSR psr_nzcvq, r2");
        __asm volatile("MSR APSR_nzcvq, r3");
#endif

        /* Restore handle value. */
        asm volatile("POP {r0}");    /* handle address. */
        asm volatile("POP {r1-r7}"); /* first 7 words of handle. */
        asm volatile("STR r1, [r0]");
#if __IAR_SYSTEMS_ICC__
        asm volatile("ADDS r0, r0, #4");
#else
        asm volatile("ADD r0, r0, #4");
#endif
        asm volatile("STR r2, [r0]");
#if __IAR_SYSTEMS_ICC__
        asm volatile("ADDS r0, r0, #4");
#else
        asm volatile("ADD r0, r0, #4");
#endif
        asm volatile("STR r3, [r0]");
#if __IAR_SYSTEMS_ICC__
        asm volatile("ADDS r0, r0, #4");
#else
        asm volatile("ADD r0, r0, #4");
#endif
        asm volatile("STR r4, [r0]");
#if __IAR_SYSTEMS_ICC__
        asm volatile("ADDS r0, r0, #4");
#else
        asm volatile("ADD r0, r0, #4");
#endif
        asm volatile("STR r5, [r0]");
#if __IAR_SYSTEMS_ICC__
        asm volatile("ADDS r0, r0, #4");
#else
        asm volatile("ADD r0, r0, #4");
#endif
        asm volatile("STR r6, [r0]");
#if __IAR_SYSTEMS_ICC__
        asm volatile("ADDS r0, r0, #4");
#else
        asm volatile("ADD r0, r0, #4");
#endif
        asm volatile("STR r7, [r0]");
#if __IAR_SYSTEMS_ICC__
        asm volatile("ADDS r0, r0, #4");
#else
        asm volatile("ADD r0, r0, #4");
#endif
        asm volatile("POP {r1-r4}"); /*left 4 words of handle. */
        asm volatile("STR r1, [r0]");
#if __IAR_SYSTEMS_ICC__
        asm volatile("ADDS r0, r0, #4");
#else
        asm volatile("ADD r0, r0, #4");
#endif
        asm volatile("STR r2, [r0]");
#if __IAR_SYSTEMS_ICC__
        asm volatile("ADDS r0, r0, #4");
#else
        asm volatile("ADD r0, r0, #4");
#endif
        asm volatile("STR r3, [r0]");
#if __IAR_SYSTEMS_ICC__
        asm volatile("ADDS r0, r0, #4");
#else
        asm volatile("ADD r0, r0, #4");
#endif
        asm volatile("STR r4, [r0]");

        /* Restore r4-r7. */
        asm volatile("POP {r4-r7}");

        /* Restore r8-r12. */
        asm volatile("POP {r0-r4}");
        asm volatile("MOV r8, r0");
        asm volatile("MOV r9, r1");
        asm volatile("MOV r10, r2");
        asm volatile("MOV r11, r3");
        asm volatile("MOV r12, r4");

        /* Restore LR */
        asm volatile("POP {r0}"); /* saved PC */
        asm volatile("MOV lr, r0");
#ifdef __ARMVFP__
        asm volatile("VLDMIA sp!, {D8}");
        asm volatile("VLDMIA sp!, {D9}");
        asm volatile("VLDMIA sp!, {D10}");
        asm volatile("VLDMIA sp!, {D11}");
        asm volatile("VLDMIA sp!, {D12}");
        asm volatile("VLDMIA sp!, {D13}");
        asm volatile("VLDMIA sp!, {D14}");
        asm volatile("VLDMIA sp!, {D15}");
#endif
        asm volatile("MOVS r0, #1");
        asm volatile("BX lr");
    }
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
status_t Power_MuMessageCallback(uint32_t message, uint32_t channelId)
{
    status_t status                 = kStatus_Success;
    power_mu_message_type_t msgType = Power_GetMuMessageType(message);
    if (msgType == kPower_MsgTypeSync)
    {
        status = Power_MuSyncCallback(message, channelId);
    }
    else if (msgType == kPower_MsgTypeRequest)
    {
        status = Power_InterpretRequest(message);
    }
    else
    {
        status = Power_InterpretResponse(message);
    }

    return status;
}

/*!
 * brief Get type of received MU message.
 *
 * param message The received message.
 *
 * return The type of MU message.
 */
power_mu_message_type_t Power_GetMuMessageType(uint32_t message)
{
    power_mu_message_t msg;
    msg.wordFormat = message;

    return msg.strcutFormat.type;
}

/*!
 * brief Get direction of received MU message.
 *
 * param message The received message.
 *
 * return The direction of MU message.
 */
power_mu_message_direction_t Power_GetMuMessageDir(uint32_t message)
{
    power_mu_message_t msg;
    msg.wordFormat = message;

    return msg.strcutFormat.direction;
}

/*!
 * brief The callback when one core want to sync with another, that is when the message type is #kPower_MsgTypeSync.
 *
 * param message Received message value.
 * param channelId The channel which transfer the message.
 *
 * retval kStatus_Power_SyncFailed Failed to sync between dual cores.
 * retval kStatus_Success Sync dual cores successfully.
 */
status_t Power_MuSyncCallback(uint32_t message, uint32_t channelId)
{
    power_mu_message_type_t resType = kPower_MsgTypeACK;
    power_mu_message_t msg;
    msg.wordFormat                            = message;
    power_low_power_mode_t targetLowPowerMode = msg.strcutFormat.reqestLowPowerMode;
    power_mu_message_direction_t responseDir  = kPower_MsgDirAonToMain;
    uint16_t lowerHalfWordValue               = 0U;

    if (Power_VerifyMuMessage(message) != kStatus_Success)
    {
        lowerHalfWordValue |= kPower_MsgNACK_WrongMsgReceived;
    }
    else
    {
        g_Handle_Offset              = msg.strcutFormat.lowHalfContent.sharedHandleAddrOff;
        power_handle_t *sharedHandle = (power_handle_t *)(POWER_SHARED_RAM_BASE_ADDR + g_Handle_Offset);
        if (sharedHandle->muChannelId != channelId)
        {
            lowerHalfWordValue |= kPower_MsgNACK_ChannelMisMatch;
        }
        if (targetLowPowerMode != kPower_Active)
        {
            lowerHalfWordValue |= kPower_MsgNACK_TargetModeNotAllowed;
        }
    }

    if (Power_GetMuMessageDir(message) == kPower_MsgDirAonToMain)
    {
        responseDir = kPower_MsgDirMainToAon;
    }
    if (lowerHalfWordValue != 0U)
    {
        resType = kPower_MsgTypeNACK;
    }

    uint32_t tmp32 = Power_PopulateMuMessage(resType, responseDir, targetLowPowerMode, lowerHalfWordValue);
    MU_SendMsg(POWER_USED_MU, channelId, tmp32);

    if (lowerHalfWordValue != 0U)
    {
        return kStatus_Power_SyncFailed;
    }
    else
    {
        return kStatus_Success;
    }
}

/*!
 * brief Interpret request message from requester.
 *
 * param message The message which request from requester.
 *
 * retval kStatus_POWER_MuTransferError Something wrong during transfer.
 * retval kStatus_POWER_RequestNotAllowed Request is not allowed.
 * retval kStatus_Success Interpret request message successfully.
 */
status_t Power_InterpretRequest(uint32_t message)
{
    power_mu_message_type_t resType          = kPower_MsgTypeACK;
    power_mu_message_direction_t responseDir = kPower_MsgDirAonToMain;
    power_user_callback_t curCallback        = NULL;
    void *curCallbackData                    = NULL;
    uint32_t lpConfigAddr = POWER_SHARED_RAM_BASE_ADDR + g_Handle_Offset + offsetof(power_handle_t, lpConfig[0]);
    power_mu_message_t msg;
    msg.wordFormat                            = message;
    power_low_power_mode_t targetLowPowerMode = msg.strcutFormat.reqestLowPowerMode;
    bool userAllowed                          = false;
    uint16_t lowerHalfWordValue               = 0U;
    status_t status                           = kStatus_Success;
    uint32_t channelId                        = 0U;
    power_handle_t *sharedHandle              = (power_handle_t *)(POWER_SHARED_RAM_BASE_ADDR + g_Handle_Offset);

    if (Power_VerifyMuMessage(message) != kStatus_Success)
    {
        lowerHalfWordValue |= kPower_MsgNACK_WrongMsgReceived;
        status = kStatus_POWER_MuTransferError;
    }
    else
    {
        channelId = sharedHandle->muChannelId;
#if __CORTEX_M == 33U
        curCallback     = sharedHandle->cm33Callback;
        curCallbackData = sharedHandle->cm33UserData;
#else
        curCallback     = sharedHandle->cm0pCallback;
        curCallbackData = sharedHandle->cm0pUserData;
#endif
        if (curCallback != NULL)
        {
            userAllowed = curCallback(targetLowPowerMode, (void *)lpConfigAddr, curCallbackData);
        }

        if (userAllowed == false)
        {
            lowerHalfWordValue |= kPower_MsgNACK_TargetModeNotAllowed;
            status = kStatus_POWER_RequestNotAllowed;
        }
    }

    if (lowerHalfWordValue != 0UL)
    {
        resType = kPower_MsgTypeNACK;
    }

    if (Power_GetMuMessageDir(message) == kPower_MsgDirAonToMain)
    {
        responseDir = kPower_MsgDirMainToAon;
    }
    uint32_t tmp32 = Power_PopulateMuMessage(resType, responseDir, targetLowPowerMode, lowerHalfWordValue);
    MU_SendMsg(POWER_USED_MU, channelId, tmp32);

    /* Until now, response already send to requester. */
    if (userAllowed && (resType != kPower_MsgTypeNACK))
    {
#if __CORTEX_M == 33U
        (void)Power_EnterLowPowerMode(targetLowPowerMode, (void *)lpConfigAddr);
#elif __CORTEX_M == 0U
        if ((targetLowPowerMode == kPower_PowerDown2) ||
            ((targetLowPowerMode >= kPower_DeepPowerDown2) && (targetLowPowerMode < kPower_Active)))
        {
            /* If CM0P approve to enter target low power mode, execute WFI. */
            SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;
            sharedHandle->cm0pWFI         = true;
            sharedHandle->targetPowerMode = targetLowPowerMode;
            if (targetLowPowerMode == kPower_DeepPowerDown2)
            {
                if ((((power_dpd2_config_t *)lpConfigAddr)->aonRamArraysToRetain != kPower_AonDomainNoneRams) &&
                    (((power_dpd2_config_t *)lpConfigAddr)->wakeToDpd1 == true))
                {
                    if (Power_PushContext((uint32_t)sharedHandle) == 0UL)
                    {
                        __DSB();
                        __ISB();
                        __WFI();
                    }
                    AON__SMM->MSB_BCKP1             = SMM_MSB_BCKP1_MSB1(0UL);
                    g_Handle_Offset                 = (uint32_t)((uint32_t)sharedHandle - POWER_SHARED_RAM_BASE_ADDR);
                    sharedHandle->previousPowerMode = targetLowPowerMode;
                }
            }
            else
            {
                __DSB();
                __ISB();
                __WFI();
            }
        }
#endif /* __CORTEX_M */
    }

    return status;
}

/*!
 * brief Interpre responce of message.
 *
 * param message The message which responce to requester.
 *
 * retval kStatus_POWER_MuTransferError    Something wrong during transfer.
 * retval kStatus_POWER_RequestNotAllowed  Request is not allowed.
 * retval kStatus_Power_NackWithMultiReasons Responce as NACK with multiple reasons.
 * retval kStatus_Success Interpret response message successfully.
 */
status_t Power_InterpretResponse(uint32_t message)
{
    status_t status = kStatus_Success;

    if (Power_VerifyMuMessage(message) != kStatus_Success)
    {
        g_powerMuTransferState = kPower_MuTransferWrong;
        status                 = kStatus_POWER_MuTransferError;
    }

    if (Power_GetMuMessageType(message) == kPower_MsgTypeACK)
    {
        g_powerMuTransferState = kPower_MuTransferEndWithACK;
    }
    else
    {
        g_powerMuTransferState = kPower_MuTransferEndWithNACK;
        power_mu_nack_reason_t reason;
        reason = Power_GetMuNackReason(message);
        if (reason == kPower_MsgNACK_TargetModeNotAllowed)
        {
            status = kStatus_POWER_RequestNotAllowed;
        }
        else if ((reason == kPower_MsgNACK_ChannelMisMatch) || (reason == kPower_MsgNACK_WrongMsgReceived))
        {
            status = kStatus_POWER_MuTransferError;
        }
        else
        {
            status = kStatus_Power_NackWithMultiReasons;
        }
    }

    return status;
}
