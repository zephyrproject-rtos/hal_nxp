/*
 * Copyright 2025-2026 NXP
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
 * brief Union describing the low half-word of a MU message.
 */
typedef union _power_mu_msg_2half_content
{
    uint16_t halfWordValueMask;   /* Generic low half-word value. */
    uint16_t sharedHandleAddrOff; /* Handle offset used by SYNC messages. */
    uint16_t NAckReason;          /* NACK reason bitmap. */
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

/*!
 * brief MU transfer state machine.
 */
typedef enum _power_mu_transfer_state
{
    kPower_MuTransferIdle        = 0U,
    kPower_MuTransferStart       = 1U,
    kPower_MuTransferEndWithNACK = 2U,
    kPower_MuTransferEndWithACK  = 3U,
    kPower_MuTransferWrong       = 4U,
} power_mu_transfer_state_t;

volatile power_mu_transfer_state_t g_powerMuTransferState = kPower_MuTransferIdle;

#define POWER_UPDATE_SMM_STALL(long, mid, short)                                                                \
    do                                                                                                          \
    {                                                                                                           \
        uint32_t stall1_reg = *((volatile uint32_t *)0xA009A03CUL);                                             \
        stall1_reg =                                                                                            \
            (stall1_reg & ~0xFFFUL) | (((uint32_t)(short)&0xFUL) << 0UL) | (((uint32_t)(mid) & 0xFFUL) << 4UL); \
        *((volatile uint32_t *)0xA009A03CUL) = stall1_reg;                                                      \
        uint32_t stall2_reg                  = *((volatile uint32_t *)0xA009A040UL);                            \
        stall2_reg                           = (stall2_reg & ~0xFFFFUL) | ((uint32_t)(long)&0xFFFFUL);          \
        *((volatile uint32_t *)0xA009A040UL) = stall2_reg;                                                      \
    } while (0)

/*******************************************************************************
 * Variables
 ******************************************************************************/
#define POWER_HANDLE_OFFSET_NOT_INIT_VALUE (0x5A5AA5A5UL)

uint32_t g_Handle_Offset = POWER_HANDLE_OFFSET_NOT_INIT_VALUE;

#if __CORTEX_M == 33U
#define POWER_USED_MU (MUA)
#elif __CORTEX_M == 0U
#define POWER_USED_MU (MUB)
#endif /* __CORTEX_M */

/*******************************************************************************
 * Code
 ******************************************************************************/

/*!
 * @brief Get VddCore AON voltage based on target frequency
 *
 * This function determines the appropriate VddCore AON voltage for a given frequency.
 * Used when ADVC is disabled to ensure proper voltage for the target frequency.
 *
 * @param targetFreqHz Target AON CPU frequency in Hz
 * @return Appropriate VddCore voltage value
 */
static power_vdd_core_output_voltage_t Power_GetVddCoreForFreq(uint32_t targetFreqHz)
{
    power_vdd_core_output_voltage_t voltage;

    if (targetFreqHz == 10000000U)
    {
        /* 10MHz requires 770mV */
        voltage = kPower_VddCoreAon_772_5mV;
    }
    else if (targetFreqHz == 5000000U)
    {
        /* 5MHz requires 740mV */
        voltage = kPower_VddCoreAon_744mV;
    }
    else if (targetFreqHz == 3000000U)
    {
        /* 3MHz requires 720mV */
        voltage = kPower_VddCoreAon_725mV;
    }
    else if (targetFreqHz == 2500000U)
    {
        /* 2.5MHz requires 730mV */
        voltage = kPower_VddCoreAon_734_5mV;
    }
    else if (targetFreqHz >= 750000U)
    {
        /* 0.75MHz requires 680mV */
        voltage = kPower_VddCoreAon_687mV;
    }
    else
    {
        /* 32kHz and below require 600mV */
        voltage = kPower_VddCoreAon_601_5mV;
    }

    return voltage;
}

/*!
 * @brief Get DPD2 target frequency based on configuration
 *
 * This function determines the target AON CPU frequency for DPD2 mode based on
 * the switchToX32K flag and current FRO configuration.
 *
 * @param config Pointer to DPD2 configuration
 * @return Target frequency in Hz (32768, 750000, or 2500000)
 */
static uint32_t Power_GetDpd2TargetFreq(const power_dpd2_config_t *config)
{
    uint32_t targetFreq;

    if (config->switchToX32K)
    {
        /* Switching to 32KHz */
        targetFreq = 32768U;
    }
    else
    {
        /* Using FRO/4: either 10MHz/4=2.5MHz or 3MHz/4=0.75MHz */
        /* Check which FRO is currently enabled */
        if (AON__CGU->CLK_CONFIG & CGU_CLK_CONFIG_SEL_MODE_MASK)
        {
            /* ULPIRC (3MHz) is selected, so FRO/4 = 0.75MHz */
            targetFreq = 750000U;
        }
        else
        {
            /* LPIRC (10MHz) is selected, so FRO/4 = 2.5MHz */
            targetFreq = 2500000U;
        }
    }

    return targetFreq;
}

/*!
 * @brief Configure stall values based on power mode and frequency
 *
 * This function configures the appropriate stall values (short, mid, long) or PAC wakeup time
 * based on the target power mode and AON CPU clock frequency to optimize wakeup time.
 *
 * @param mode Target low power mode
 * @param freqHz AON CPU clock frequency in Hz
 */
static void Power_ConfigureStallForMode(power_low_power_mode_t mode, uint32_t freqHz)
{
#if 0
    /* Configure stall values based on frequency and power mode */
    if (mode == kPower_DeepPowerDown3 || mode == kPower_ShutDown)
    {
        /* DPD3/SD mode: use PAC wakeup time */
        if (freqHz == 16000U)
        {
            /* 16kHz: PAC wakeup time = 64 */
            PMU_UpdateWakeupTime(AON__PMU, 64);
        }
        else
        {
            /* 8kHz: PAC wakeup time = 32 */
            PMU_UpdateWakeupTime(AON__PMU, 32);
        }
    }
    else if ((mode == kPower_DeepPowerDown1) || (mode == kPower_PowerDown1) || (mode == kPower_PowerDown2))
    {
        if (freqHz == 10000000)
        {
            POWER_UPDATE_SMM_STALL(500U, 200U, 8U);
        }
        else if (freqHz == 3000000U)
        {
            POWER_UPDATE_SMM_STALL(150U, 60U, 2U);
        }
        else
        {
            /* Avoid violation of MISRA rule. */
        }
    }
    else if (mode == kPower_DeepPowerDown2)
    {
        /* DPD2 mode: stall values depend on frequency */
        if (freqHz == 2500000U)
        {
            /* 2.5MHz with ADVC WA: short=1, mid=50, long=125 */
            POWER_UPDATE_SMM_STALL(125U, 50U, 1U);
        }
        else if (freqHz == 750000U)
        {
            /* 0.75MHz without ADVC: short=2, mid=60, long=150 */
            POWER_UPDATE_SMM_STALL(150U, 60U, 2U);
        }
        else if (freqHz == 32768)
        {
            POWER_UPDATE_SMM_STALL(150U, 60U, 2U);
        }
    }
#endif
}

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

static status_t Power_PrepareVddCoreAndFro10M(power_vdd_core_output_voltage_t vddCoreAonVoltage, bool disableFRO10M)
{
    if ((vddCoreAonVoltage == kPower_VddCoreAon_AdvcControl) && ADVC_IsEnabled())
    {
        if (disableFRO10M)
        {
            if (ADVC_PreVoltageChangeRequest(CLOCK_GetAonCoreSysClkFreq()) != kADVC_Stat_Ok)
            {
                return kStatus_Power_AdvcPreVoltageChangeFailed;
            }
            AON__CGU->CLK_CONFIG &= ~CGU_CLK_CONFIG_LPIRC_EN_MASK;
            if (ADVC_PostVoltageChangeRequest() != kADVC_Stat_Ok)
            {
                /* Post voltage change request fail, re-enable FRO10M. */
                AON__CGU->CLK_CONFIG |= CGU_CLK_CONFIG_LPIRC_EN_MASK;
                return kStatus_Power_AdvcPostVoltageChangeFailed;
            }
        }
    }
    else
    {
        if (disableFRO10M)
        {
            AON__CGU->CLK_CONFIG &= ~CGU_CLK_CONFIG_LPIRC_EN_MASK;
        }
        PMU_UpdateVDDCoreInActiveMode(AON__PMU, Power_GetVddCoreForFreq(CLOCK_GetAonCoreSysClkFreq()));
    }

    return kStatus_Success;
}

#if __CORTEX_M == 0U
static status_t Power_ReqestCM33StartLpSeq(power_low_power_mode_t targetMode)
{
    uint32_t tmp32            = 0UL;
    power_handle_t *curHandle = (power_handle_t *)(POWER_SHARED_RAM_BASE_ADDR + g_Handle_Offset);

    tmp32 = Power_PopulateMuMessage(kPower_MsgTypeRequest, kPower_MsgDirAonToMain, targetMode,
                                    (uint16_t)(g_Handle_Offset & 0xFFFFUL));
    MU_SendMsg(POWER_USED_MU, curHandle->muChannelId, tmp32);

#if POWER_MU_TRANSFER_TIMEOUT
    uint32_t timeout = POWER_MU_TRANSFER_TIMEOUT;
#endif
    /* Waiting for response from CM0P. */
    while (g_powerMuTransferState == kPower_MuTransferStart)
    {
#if POWER_MU_TRANSFER_TIMEOUT
        if ((--timeout) == 0U)
        {
            return kStatus_Timeout;
        }
#endif
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

#if __CORTEX_M == 33U
/*!
 * @brief Send a low-power mode request to CM0P and wait for ACK/NACK.
 *
 * @param targetMode  The requested low power mode.
 * @param muChannelId MU channel ID.
 * @return kStatus_Success, kStatus_POWER_MuTransferError,
 *         kStatus_POWER_RequestNotAllowed, or kStatus_Timeout.
 */
static status_t Power_CM33RequestLowPowerMode(power_low_power_mode_t targetMode, uint32_t muChannelId)
{
    uint32_t tmp32 = Power_PopulateMuMessage(kPower_MsgTypeRequest, kPower_MsgDirMainToAon, targetMode, 0UL);
    g_powerMuTransferState = kPower_MuTransferStart;
    MU_SendMsg(POWER_USED_MU, muChannelId, tmp32);
#if POWER_MU_TRANSFER_TIMEOUT
    uint32_t timeout = POWER_MU_TRANSFER_TIMEOUT;
#endif
    /* Waiting for response from CM0P. */
    while (g_powerMuTransferState == kPower_MuTransferStart)
    {
#if POWER_MU_TRANSFER_TIMEOUT
        if ((--timeout) == 0U)
        {
            return kStatus_Timeout;
        }
#endif
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
    return kStatus_Success;
}
#endif /* __CORTEX_M == 33U */

/*!
 * @brief Send a SYNC message to the peer core and wait for ACK/NACK.
 *
 * May be called from either CM33 or CM0+. The message direction is derived
 * automatically from the core that calls this function.
 *
 * @param muChannelId MU channel ID.
 * @return kStatus_Success, kStatus_POWER_MuTransferError,
 *         kStatus_Power_HandleDuplicated, or kStatus_Timeout.
 */
static status_t Power_MuDoSync(uint32_t muChannelId)
{
#if __CORTEX_M == 33U
    power_mu_message_direction_t dir = kPower_MsgDirMainToAon;
#else
    power_mu_message_direction_t dir = kPower_MsgDirAonToMain;
#endif
    uint32_t tmp32 = Power_PopulateMuMessage(kPower_MsgTypeSync, dir, kPower_Active,
                                             (uint16_t)(g_Handle_Offset & 0xFFFFUL));
    g_powerMuTransferState = kPower_MuTransferStart;
    MU_SendMsg(POWER_USED_MU, muChannelId, tmp32);
#if POWER_MU_TRANSFER_TIMEOUT
    uint32_t timeout = POWER_MU_TRANSFER_TIMEOUT;
#endif
    /* Waiting for response from peer core. */
    while (g_powerMuTransferState == kPower_MuTransferStart)
    {
#if POWER_MU_TRANSFER_TIMEOUT
        if ((--timeout) == 0U)
        {
            return kStatus_Timeout;
        }
#endif
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
    return kStatus_Success;
}

/*!
 * @brief Configure AON/Main SRAM retention settings.
 *
 * @param aonSramToRetain  Bitmask of AON SRAM arrays to retain.
 * @param mainSramToRetain Bitmask of Main SRAM arrays to retain.
 * @param disableBandgap   Whether to shut down bandgap in low power.
 * @param enableIVS        Whether to enable IVS mode for SRAM retention.
 */
static void Power_ConfigSleepModeManager(uint8_t aonSramToRetain, uint32_t mainSramToRetain,
                                         bool disableBandgap, bool enableIVS)
{
    SMM_PowerOffAonSramAutomatically(AON__SMM, (uint8_t)(~aonSramToRetain & 0xFFUL));
    SMM_EnableMainDomainSramRetention(AON__SMM, mainSramToRetain);
    SMM_ShutDownBandgapInLowPowerModes(AON__SMM, disableBandgap);
    SMM_EnableIvsModeForSramRetention(AON__SMM, enableIVS);
}

/*!
 * @brief Enable wakeup sources for both main and AON CPU domains.
 *
 * The masks in sharedHandle are updated by Power_CheckThenEnableWakeupSource(),
 * so SMM_EnableWakeupSource calls must happen AFTER CheckThenEnable completes.
 * Do NOT pass the masks as arguments — they must be read from sharedHandle
 * inside this function, after the CheckThenEnable calls update them.
 *
 * @param mainWs Main domain wakeup source.
 * @param aonWs  AON domain wakeup source.
 */
static void Power_EnableDualDomainWakeupSources(power_wakeup_source_t mainWs, power_wakeup_source_t aonWs)
{
    power_handle_t *sharedHandle = (power_handle_t *)(POWER_SHARED_RAM_BASE_ADDR + g_Handle_Offset);
    Power_CheckThenEnableWakeupSource(mainWs);
    Power_CheckThenEnableWakeupSource(aonWs);
    SMM_EnableWakeupSourceToMainCpu(AON__SMM, sharedHandle->enabledWsInfo.mainWakeupSourceMask);
    SMM_EnableWakeupSourceToAonCpu(AON__SMM, sharedHandle->enabledWsInfo.aonWakeupSourceMask);
}

#if __CORTEX_M == 0U
static status_t Power_SetDpd2AdvcWorkaround(power_dpd2_config_t *config)
{
    advc_result_t advcRet;
    /* Per platform requirement, DPD2+ADVC workaround must be executed on CM0P (AON core). */
    CLOCK_DisableADVCControl();

    uint32_t targetFreq = Power_GetDpd2TargetFreq(config);

    advcRet = ADVC_PreVoltageChangeRequest(targetFreq);

    if (advcRet != kADVC_Stat_Ok)
    {
        return kStatus_Power_AdvcPreVoltageChangeFailed;
    }

    if (config->switchToX32K)
    {
        AON__CGU->CLK_CONFIG |= CGU_CLK_CONFIG_XTAL32_OUT_EN_MASK;
        CLOCK_AttachClk(kXTAL32K_to_AON_CPU);
    }
    else
    {
        CLOCK_AttachClk(kFROdiv4_to_AON_CPU);
    }

    if (config->disableFRO10M)
    {
        AON__CGU->CLK_CONFIG &= ~CGU_CLK_CONFIG_LPIRC_EN_MASK;
    }
    if (config->disableFRO3M)
    {
        AON__CGU->CLK_CONFIG &= ~CGU_CLK_CONFIG_ULPIRC_EN_MASK;
    }
    /* Disable Auto Calibration. */
    AON__CGU->CAL_CONFIG &= ~CGU_CAL_CONFIG_CAL_CLK_EN_MASK;

    advcRet = ADVC_PostVoltageChangeRequest();
    if (advcRet != kADVC_Stat_Ok)
    {
        return kStatus_Power_AdvcPostVoltageChangeFailed;
    }

    Power_ConfigureStallForMode(kPower_DeepPowerDown2, targetFreq);
    return kStatus_Success;
}
#endif /* __CORTEX_M */

/*!
 * brief Create the shared power handle.
 *
 * This function initializes the shared power_handle_t in the shared RAM and, unless
 * power_drv_config_t::noSyncCM0P is true, attempts to synchronize with the other core.
 *
 * note Please invoke this function before using other APIs.
 *
 * param[in] handle Pointer to power_handle_t in **shared RAM**.
 * param[in] config Pointer to power_drv_config_t.
 *
 * retval kStatus_Success                 Handle created (and cores synchronized if requested).
 * retval kStatus_Power_HandleDuplicated  A shared handle has already been created by the peer.
 * retval kStatus_POWER_MuTransferError   MU synchronization/transfer error.
 * retval kStatus_Timeout                 Timed out while waiting for MU response (if timeout enabled).
 */
status_t Power_CreateHandle(power_handle_t *handle, const power_drv_config_t *config)
{
#if __CORTEX_M == 33U
    assert((uint32_t)handle >= POWER_SHARED_RAM_BASE_ADDR);
    assert(config != NULL);
#endif

    (void)memset(handle, 0UL, sizeof(power_handle_t));

    handle->muChannelId       = config->muChannelId;
    handle->targetPowerMode   = kPower_Active;
    handle->previousPowerMode = kPower_Active;

    handle->dualCoreSynced   = false;
    handle->requestCM33Start = false;

    /* Record offset of handle. */
    g_Handle_Offset = (uint32_t)handle - POWER_SHARED_RAM_BASE_ADDR;

    if (config->noSyncCM0P != true)
    {
        status_t syncStatus = Power_MuDoSync(config->muChannelId);
        if (syncStatus != kStatus_Success)
        {
            return syncStatus;
        }
        handle->dualCoreSynced = true;
    }
    else
    {
        handle->dualCoreSynced = false;
    }

    return kStatus_Success;
}

/*!
 * brief Dump the current shared handle into a local buffer.
 *
 * param[out] ptrDumpBuffer The pointer to a buffer in type of ref power_handle_t to store dumped handle value.
 */
void Power_DumpHandleValue(power_handle_t *ptrDumpBuffer)
{
    assert(g_Handle_Offset != POWER_HANDLE_OFFSET_NOT_INIT_VALUE);

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
    assert(g_Handle_Offset != POWER_HANDLE_OFFSET_NOT_INIT_VALUE);

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

status_t Power_SyncDualCoreBlocking(void)
{
    assert(g_Handle_Offset != POWER_HANDLE_OFFSET_NOT_INIT_VALUE);

    power_handle_t *sharedHandle = (power_handle_t *)(POWER_SHARED_RAM_BASE_ADDR + g_Handle_Offset);

    status_t syncStatus = Power_MuDoSync(sharedHandle->muChannelId);
    if (syncStatus != kStatus_Success)
    {
        return syncStatus;
    }
    sharedHandle->dualCoreSynced = true;

    return kStatus_Success;
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

    switch (handleBuf.targetPowerMode)
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
    assert(g_Handle_Offset != POWER_HANDLE_OFFSET_NOT_INIT_VALUE);

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
    assert(g_Handle_Offset != POWER_HANDLE_OFFSET_NOT_INIT_VALUE);

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
        else
        {
            /* Wrong input value. */
            assert(false);
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
    assert(g_Handle_Offset != POWER_HANDLE_OFFSET_NOT_INIT_VALUE);

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
    power_handle_t *sharedHandle = (power_handle_t *)(POWER_SHARED_RAM_BASE_ADDR + g_Handle_Offset);
    SMM_DisableWakeupSourceToMainCpu(AON__SMM, SMM_WKUP_MAIN_WKUP_SRC_MAIN_CPU_MASK);
    SMM_DisableWakeupSourceToAonCpu(AON__SMM, SMM_AON_CPU_WKUP_SRC_AON_CPU_MASK);
    sharedHandle->enabledWsInfo.mainWakeupSourceMask = 0UL;
    sharedHandle->enabledWsInfo.aonWakeupSourceMask = 0UL;
}

/*!
 * brief Dump information of all configured wakeup sources, in type of power_wakeup_source_info_t.
 *
 * param[out] ptrWsInfo Pointer to the variable to store dumped wakeup source information.
 */
void Power_DumpEnabledWakeSource(power_wakeup_source_info_t *ptrWsInfo)
{
    assert(ptrWsInfo);
    assert(g_Handle_Offset != POWER_HANDLE_OFFSET_NOT_INIT_VALUE);

    power_handle_t *sharedHandle = (power_handle_t *)(POWER_SHARED_RAM_BASE_ADDR + g_Handle_Offset);

    (void)memcpy((void *)ptrWsInfo, (void *)(&(sharedHandle->enabledWsInfo)), sizeof(power_wakeup_source_info_t));
}

/*!
 * brief Get latest mask of wakeup sources which cause the wakeup to main CPU.
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
    assert(g_Handle_Offset != POWER_HANDLE_OFFSET_NOT_INIT_VALUE);

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
    assert(g_Handle_Offset != POWER_HANDLE_OFFSET_NOT_INIT_VALUE);

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
    assert(g_Handle_Offset != POWER_HANDLE_OFFSET_NOT_INIT_VALUE);

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
    assert(g_Handle_Offset != POWER_HANDLE_OFFSET_NOT_INIT_VALUE);

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
    assert(g_Handle_Offset != POWER_HANDLE_OFFSET_NOT_INIT_VALUE);

    power_handle_t *sharedHandle = (power_handle_t *)(POWER_SHARED_RAM_BASE_ADDR + g_Handle_Offset);

    return sharedHandle->previousPowerMode;
}

/*!
 * brief Reset previous power mode as active mode.
 */
void Power_ResetPreviousPowerMode(void)
{
    assert(g_Handle_Offset != POWER_HANDLE_OFFSET_NOT_INIT_VALUE);

    power_handle_t *sharedHandle = (power_handle_t *)(POWER_SHARED_RAM_BASE_ADDR + g_Handle_Offset);

    sharedHandle->previousPowerMode = kPower_Active;
}

/*!
 * brief Update previous power mode as input low power mode.
 *
 * param lpMode The low power mode to update, in type of power_low_power_mode_t.
 */
void Power_UpdatePreviousPowerMode(power_low_power_mode_t lpMode)
{
    assert(g_Handle_Offset != POWER_HANDLE_OFFSET_NOT_INIT_VALUE);

    power_handle_t *sharedHandle = (power_handle_t *)(POWER_SHARED_RAM_BASE_ADDR + g_Handle_Offset);

    sharedHandle->previousPowerMode = lpMode;
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
    assert(g_Handle_Offset != POWER_HANDLE_OFFSET_NOT_INIT_VALUE);

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
    assert(g_Handle_Offset != POWER_HANDLE_OFFSET_NOT_INIT_VALUE);

    power_handle_t *sharedHandle           = (power_handle_t *)(POWER_SHARED_RAM_BASE_ADDR + g_Handle_Offset);
    power_low_power_mode_t targetPowerMode = sharedHandle->targetPowerMode;

    return targetPowerMode;
}

/*!
 * brief Clear the target low power mode.
 */
void Power_ClearTargetPowerMode(void)
{
    assert(g_Handle_Offset != POWER_HANDLE_OFFSET_NOT_INIT_VALUE);

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
    AON__SMM->STAT = SMM_STAT_DPD_SEQ_END_MASK | SMM_STAT_DPD_END_MASK;
    AON__SMM->PWDN_CONFIG &= ~(SMM_PWDN_CONFIG_BGR_PULSE_MASK | SMM_PWDN_CONFIG_DPD1_VDD_CORE_MAIN_SRC_MASK |
                               SMM_PWDN_CONFIG_CTRL_SRAM_DPD2_MASK);
#elif __CORTEX_M == 0U
    SMM_DisableAonCpuIso(AON__SMM);
    SMM_ClearAllLowPowerSequence(AON__SMM);
    SMM_ClearAonCpuWakeupSources(AON__SMM);
    AON__SMM->STAT = SMM_STAT_DPD_SEQ_END_MASK | SMM_STAT_DPD_END_MASK;
    AON__SMM->PWDN_CONFIG &= ~SMM_PWDN_CONFIG_CTRL_SRAM_DPD2_MASK;
    if (SMM_GetPowerState(AON__SMM) != 2U)
    {
        /* If current mode is deep power down1 mode, keep bandgap setting and VDD_CORE_MAIN SRC no changed. */
        AON__SMM->PWDN_CONFIG &= ~(SMM_PWDN_CONFIG_BGR_PULSE_MASK | SMM_PWDN_CONFIG_DPD1_VDD_CORE_MAIN_SRC_MASK);
    }
#endif /* __CORTEX_M */
}

/*!
 * brief Enter selected low power mode.
 *
 * param[in] lowpowerMode Indicate specific low power mode.
 * param config Point to low power configurations.
 *
 * retval kStatus_POWER_MuTransferError An error occurred during MU transfer.
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
 * retval kStatus_POWER_MuTransferError An error occurred during MU transfer.
 * retval kStatus_POWER_RequestNotAllowed Request not allowed by another core.
 */
status_t Power_EnterSleep(void)
{
#if __CORTEX_M == 33U
    assert(g_Handle_Offset != POWER_HANDLE_OFFSET_NOT_INIT_VALUE);

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
 * retval kStatus_POWER_MuTransferError An error occurred during MU transfer.
 * retval kStatus_POWER_RequestNotAllowed Request not allowed by another core.
 */
status_t Power_EnterDeepSleep(power_ds_config_t *config)
{
    assert(g_Handle_Offset != POWER_HANDLE_OFFSET_NOT_INIT_VALUE);

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
 * retval kStatus_POWER_MuTransferError An error occurred during MU transfer.
 * retval kStatus_POWER_RequestNotAllowed Request not allowed by another core.
 */
status_t Power_EnterPowerDown1(power_pd1_config_t *config)
{
    assert(g_Handle_Offset != POWER_HANDLE_OFFSET_NOT_INIT_VALUE);

    power_handle_t *sharedHandle = (power_handle_t *)(POWER_SHARED_RAM_BASE_ADDR + g_Handle_Offset);
    memset(sharedHandle->lpConfig, 0UL, 16UL);
    memcpy(sharedHandle->lpConfig, config, sizeof(power_pd1_config_t));
#if __CORTEX_M == 33U
    /*1. Enable wakeup sources.  */
    Power_CheckThenEnableWakeupSource(config->mainWakeupSource);

    /*2. Configuration for SMM and PMU. */
    Power_ConfigureStallForMode(kPower_PowerDown1, CLOCK_GetAonCoreSysClkFreq());
    PMU_UpdateFRO16KFreq(AON__PMU, config->fro16KOutputFreq);
    SMM_EnableWakeupSourceToMainCpu(AON__SMM, sharedHandle->enabledWsInfo.mainWakeupSourceMask);
    SMM_EnableMainDomainSramRetention(AON__SMM, kPower_MainDomainAllRams);
    SMM_ShutDownBandgapInLowPowerModes(AON__SMM, false);
    SMM_EnableIvsModeForSramRetention(AON__SMM, config->enableIVSMode);
    SMM_StartPowerDownSequence(AON__SMM);
    PMU_DoHandshakeBetweenPMUAndPAC(AON__PMU);

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
 * retval kStatus_POWER_MuTransferError An error occurred during MU transfer.
 * retval kStatus_POWER_RequestNotAllowed Request not allowed by another core.
 */
status_t Power_EnterPowerDown2(power_pd2_config_t *config)
{
    assert(g_Handle_Offset != POWER_HANDLE_OFFSET_NOT_INIT_VALUE);

    power_handle_t *sharedHandle = (power_handle_t *)(POWER_SHARED_RAM_BASE_ADDR + g_Handle_Offset);
    memset(sharedHandle->lpConfig, 0UL, 16UL);
    memcpy(sharedHandle->lpConfig, config, sizeof(power_pd2_config_t));

    if (sharedHandle->dualCoreSynced == false)
    {
        return kStatus_Power_DualCoreNotSynced;
    }
#if __CORTEX_M == 33U
    /* 1. Inform CM0P that CM33 request to set whole system into PD2 mode, require CM0P execute WFI. */
    if (sharedHandle->requestCM33Start != true)
    {
        status_t muStatus = Power_CM33RequestLowPowerMode(kPower_PowerDown2, sharedHandle->muChannelId);
        if (muStatus != kStatus_Success)
        {
            return muStatus;
        }
    }

    status_t status = Power_PrepareVddCoreAndFro10M(config->vddCoreAonVoltage, config->disableFRO10M);
    if (status != kStatus_Success)
    {
        return status;
    }

    /* 2. Enable wakeup sources for different domain. */
    Power_CheckThenEnableWakeupSource(config->mainWakeupSource);
    Power_CheckThenEnableWakeupSource(config->aonWakeupSource);

    Power_ConfigureStallForMode(kPower_PowerDown2, CLOCK_GetAonCoreSysClkFreq());
    PMU_UpdateFRO16KFreq(AON__PMU, config->fro16KOutputFreq);
    SMM_EnableWakeupSourceToMainCpu(AON__SMM, sharedHandle->enabledWsInfo.mainWakeupSourceMask);
    SMM_EnableWakeupSourceToAonCpu(AON__SMM, sharedHandle->enabledWsInfo.aonWakeupSourceMask);

    /* 3. Configuration for SMM and PMU. */
    Power_ConfigSleepModeManager(kPower_AonDomainAllRams, kPower_MainDomainAllRams,
                                 false, config->enableIVSMode);
    SMM_StartPowerDownSequence(AON__SMM);

    PMU_DoHandshakeBetweenPMUAndPAC(AON__PMU);

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

            status = Power_PrepareVddCoreAndFro10M(config->vddCoreAonVoltage, config->disableFRO10M);
            if (status != kStatus_Success)
            {
                return status;
            }
            /*1. Enable wakeup sources.*/
            Power_CheckThenEnableWakeupSource(config->mainWakeupSource);
            Power_CheckThenEnableWakeupSource(config->aonWakeupSource);
            Power_ConfigureStallForMode(kPower_PowerDown2, CLOCK_GetAonCoreSysClkFreq());
            PMU_UpdateFRO16KFreq(AON__PMU, config->fro16KOutputFreq);
            SMM_EnableWakeupSourceToMainCpu(AON__SMM, sharedHandle->enabledWsInfo.mainWakeupSourceMask);
            SMM_EnableWakeupSourceToAonCpu(AON__SMM, sharedHandle->enabledWsInfo.aonWakeupSourceMask);

            /*2. Update SMM settings. */
            Power_ConfigSleepModeManager(kPower_AonDomainAllRams, kPower_MainDomainAllRams,
                                         false, config->enableIVSMode);

            PMU_DoHandshakeBetweenPMUAndPAC(AON__PMU);

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
 * retval kStatus_Fail Fail to enter Deep Power Down1 Mode.
 * retval kStatus_POWER_MuTransferError An error occurred during MU transfer.
 * retval kStatus_POWER_RequestNotAllowed Request not allowed by another core.
 * retval kStatus_Power_WakeupFromDPD1 Enter and wakeup from DPD1 successfully.
 */
status_t Power_EnterDeepPowerDown1(power_dpd1_config_t *config)
{
    assert(g_Handle_Offset != POWER_HANDLE_OFFSET_NOT_INIT_VALUE);

    power_handle_t *sharedHandle = (power_handle_t *)(POWER_SHARED_RAM_BASE_ADDR + g_Handle_Offset);

    memset(sharedHandle->lpConfig, 0UL, 16UL);
    memcpy(sharedHandle->lpConfig, config, sizeof(power_dpd1_config_t));
#if __CORTEX_M == 33U
    status_t status = Power_PrepareVddCoreAndFro10M(config->vddCoreAonVoltage, config->disableFRO10M);

    if (status != kStatus_Success)
    {
        return status;
    }
    Power_CheckThenEnableWakeupSource(config->mainWakeupSource);
    SMM_EnableWakeupSourceToMainCpu(AON__SMM, sharedHandle->enabledWsInfo.mainWakeupSourceMask);

    /* 1. Configuration for SMM and PMU. */
    Power_ConfigureStallForMode(kPower_DeepPowerDown1, CLOCK_GetAonCoreSysClkFreq());
    PMU_UpdateFRO16KFreq(AON__PMU, config->fro16KOutputFreq);
    SMM_EnableMainDomainSramRetention(AON__SMM, config->mainRamArraysToRetain);
    SMM_PowerOffAonSramAutomatically(AON__SMM, (uint8_t)(~kPower_AonDomainAllRams & 0xFFUL));
    SMM_ShutDownBandgapInLowPowerModes(AON__SMM, config->disableBandgap);
    SMM_EnableIvsModeForSramRetention(AON__SMM, config->enableIVSMode);
    SMM_StartPowerDownSequence(AON__SMM);

    PMU_DoHandshakeBetweenPMUAndPAC(AON__PMU);

    /* 2. Configuration for CMC. */
    CMC_SetPowerModeProtection(CMC, kCMC_AllowAllLowPowerModes);
    CMC_SetClockMode(CMC, kCMC_GateAllSystemClocksEnterLowPowerMode);
    CMC_SetGlobalPowerMode(CMC, kCMC_DeepPowerDown);
    sharedHandle->requestCM33Start = false;

    sharedHandle->targetPowerMode   = kPower_DeepPowerDown1;
    sharedHandle->previousPowerMode = kPower_DeepPowerDown1;

    if ((config->mainRamArraysToRetain != kPower_MainDomainNoneRams) && (config->saveContext == true))
    {
        AON__SMM->LSB_BCKP1 = 0UL;
        AON__SMM->MSB_BCKP1 = 0UL;
        if (Power_PushContext((uint32_t)sharedHandle) == 0UL)
        {
            SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;
            __DSB();
            __ISB();
            __WFI();
        }
        while(AON__SMM->MSB_BCKP1 != 0x5A5AU)
        {}
        AON__SMM->MSB_BCKP1 = 0UL;
        AON__SMM->LSB_BCKP1 = 0UL;

        AON__SMM->LSB_BCKP2 = 0UL;
        AON__SMM->MSB_BCKP2 = 0UL;
        return kStatus_Power_WakeupFromDPD1;
    }
    else
    {
        sharedHandle->previousPowerMode = kPower_DeepPowerDown1;
        /* 3. Software configuration for CM33. */
        SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;
        __DSB();
        __ISB();
        __WFI();

        return kStatus_Fail;
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
    assert(g_Handle_Offset != POWER_HANDLE_OFFSET_NOT_INIT_VALUE);

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
 * retval kStatus_Success                 Entered DPD2 (or completed the request sequence).
 * retval kStatus_Power_WakeupFromDPD2    Returned from DPD2 with context restored (when context saving enabled).
 * retval kStatus_POWER_MuTransferError   MU transfer error.
 * retval kStatus_POWER_RequestNotAllowed Request rejected by the peer.
 * retval kStatus_Power_DualCoreNotSynced Cores are not synchronized.
 * retval kStatus_Timeout                 Timed out while waiting for MU response / cross-core sync.
 */
status_t Power_EnterDeepPowerDown2(power_dpd2_config_t *config)
{
    assert(g_Handle_Offset != POWER_HANDLE_OFFSET_NOT_INIT_VALUE);

    power_handle_t *sharedHandle = (power_handle_t *)(POWER_SHARED_RAM_BASE_ADDR + g_Handle_Offset);

    if (sharedHandle->dualCoreSynced == false)
    {
        return kStatus_Power_DualCoreNotSynced;
    }

    memset(sharedHandle->lpConfig, 0UL, 16UL);
    memcpy(sharedHandle->lpConfig, config, sizeof(power_dpd2_config_t));
#if __CORTEX_M == 33U
    /*1. Inform CM0P that CM33 request to set whole system into DPD2 mode, require CM0P execute WFI. */
    if (sharedHandle->requestCM33Start != true)
    {
        status_t muStatus = Power_CM33RequestLowPowerMode(kPower_DeepPowerDown2, sharedHandle->muChannelId);
        if (muStatus != kStatus_Success)
        {
            return muStatus;
        }
    }

    while(sharedHandle->cm0pWFI == false)
    {}

    /*2. Enable wakeup sources for main and aon domain. */
    Power_EnableDualDomainWakeupSources(config->mainWakeupSource, config->aonWakeupSource);

    /*3. Configuration for SMM and PMU. */
    if (ADVC_IsEnabled() == false)
    {
        /* When ADVC is disabled, manually select VddCore voltage based on target frequency */
        PMU_UpdateVDDCoreInLpMode(AON__PMU, Power_GetVddCoreForFreq(Power_GetDpd2TargetFreq(config)));

        if (config->switchToX32K)
        {
            CLOCK_AttachClk(kXTAL32K_to_AON_CPU);
        }
        else
        {
            CLOCK_AttachClk(kFROdiv4_to_AON_CPU);
        }
    }
    Power_ConfigSleepModeManager(config->aonRamArraysToRetain, config->mainRamArraysToRetain,
                                 config->disableBandgap, config->enableIVSMode);
    SMM_SwitchToXTAL32(AON__SMM, config->switchToX32K);
    /* TODO: Configure stall values based on target frequency */
    PMU_UpdateFRO16KFreq(AON__PMU, config->fro16KOutputFreq);
    SMM_StartAonDPD2Sequence(AON__SMM);
    PMU_DoHandshakeBetweenPMUAndPAC(AON__PMU);

    /* 4. Configuration for CMC */
    CMC_SetPowerModeProtection(CMC, kCMC_AllowAllLowPowerModes);
    CMC_SetClockMode(CMC, kCMC_GateAllSystemClocksEnterLowPowerMode);
    CMC_SetGlobalPowerMode(CMC, kCMC_DeepPowerDown);

    sharedHandle->requestCM33Start  = false;
    sharedHandle->targetPowerMode   = kPower_DeepPowerDown2;
    sharedHandle->previousPowerMode = kPower_DeepPowerDown2;
    sharedHandle->cm0pWFI           = false;

    /* 5. Software configuration for CM33. */
    if ((config->mainRamArraysToRetain != kPower_MainDomainNoneRams) &&
        (config->aonRamArraysToRetain != kPower_AonDomainNoneRams) && (config->saveContext == true))
    {
        AON__SMM->LSB_BCKP1 = 0UL;
        if (Power_PushContext((uint32_t)sharedHandle) == 0UL)
        {
            SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;
            __DSB();
            __ISB();
            __WFI();
        }
        while(AON__SMM->MSB_BCKP1 != 0x5A5AU)
        {}
        AON__SMM->MSB_BCKP1 = 0UL;
        __DSB();
        __ISB();
        Power_ClearLpPowerSettings();

        AON__SMM->LSB_BCKP1 = 0UL;
        AON__SMM->MSB_BCKP1 = 0UL;
        AON__SMM->LSB_BCKP2 = 0UL;
        AON__SMM->MSB_BCKP2 = 0UL;
        return kStatus_Power_WakeupFromDPD2;
    }
    else
    {
        SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;
        __DSB();
        __ISB();
        __WFI();
        return kStatus_Fail;
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
            Power_EnableDualDomainWakeupSources(config->mainWakeupSource, config->aonWakeupSource);

            /*2. Configuration for SMM and PMU. */
            Power_ConfigSleepModeManager(config->aonRamArraysToRetain, config->mainRamArraysToRetain,
                                         config->disableBandgap, config->enableIVSMode);

            if (ADVC_IsEnabled() == false)
            {
                /* Disable Auto Calibration. */
                AON__CGU->CAL_CONFIG &= ~CGU_CAL_CONFIG_CAL_CLK_EN_MASK;
                /* When ADVC is disabled, manually select VddCore voltage based on target frequency */
                PMU_UpdateVDDCoreInLpMode(AON__PMU, Power_GetVddCoreForFreq(Power_GetDpd2TargetFreq(config)));

                if (config->switchToX32K)
                {
                    CLOCK_AttachClk(kXTAL32K_to_AON_CPU);
                }
                else
                {
                    CLOCK_AttachClk(kFROdiv4_to_AON_CPU);
                }
            }
            else
            {
                status = Power_SetDpd2AdvcWorkaround(config);
                if (status != kStatus_Success)
                {
                    return status;
                }
            }

            SMM_SwitchToXTAL32(AON__SMM, config->switchToX32K);

            /* Configure stall values based on target frequency */
            Power_ConfigureStallForMode(kPower_DeepPowerDown2, Power_GetDpd2TargetFreq(config));
            PMU_UpdateFRO16KFreq(AON__PMU, config->fro16KOutputFreq);
            PMU_DoHandshakeBetweenPMUAndPAC(AON__PMU);

            sharedHandle->previousPowerMode = kPower_DeepPowerDown2;
            /*3. CM0P. Execute WFI */
            SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;
            sharedHandle->cm0pWFI = true;

            if ((config->aonRamArraysToRetain != kPower_AonDomainNoneRams) && (config->saveContext == true))
            {
                if (Power_PushContext((uint32_t)sharedHandle) == 0UL)
                {
                    SMM_StartAonDPD2Sequence(AON__SMM);
                    (void)AON__SMM->PWDN_CONFIG;
                    __DSB();
                    __ISB();
                    __WFI();
                }
                __ISB();
                __DSB();
                Power_ClearLpPowerSettings();
                return kStatus_Power_WakeupFromDPD2;
            }
            else
            {
                SMM_StartAonDPD2Sequence(AON__SMM);
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
 * retval kStatus_Success                 Entered DPD3 (or completed the request sequence).
 * retval kStatus_POWER_MuTransferError   MU transfer error.
 * retval kStatus_POWER_RequestNotAllowed Request rejected by the peer.
 * retval kStatus_Power_DualCoreNotSynced Cores are not synchronized.
 * retval kStatus_Timeout                 Timed out while waiting for MU response (if timeout enabled).
 */
status_t Power_EnterDeepPowerDown3(power_dpd3_config_t *config)
{
    assert(g_Handle_Offset != POWER_HANDLE_OFFSET_NOT_INIT_VALUE);

    power_handle_t *sharedHandle = (power_handle_t *)(POWER_SHARED_RAM_BASE_ADDR + g_Handle_Offset);

    if (sharedHandle->dualCoreSynced == false)
    {
        return kStatus_Power_DualCoreNotSynced;
    }

    memset(sharedHandle->lpConfig, 0UL, 16UL);
    memcpy(sharedHandle->lpConfig, config, sizeof(power_dpd3_config_t));
#if __CORTEX_M == 33U
    /*1. Inform CM0P that CM33 request to set whole system into DPD3 mode, require CM0P execute WFI. */
    if (sharedHandle->requestCM33Start != true)
    {
        status_t muStatus = Power_CM33RequestLowPowerMode(kPower_DeepPowerDown3, sharedHandle->muChannelId);
        if (muStatus != kStatus_Success)
        {
            return muStatus;
        }
    }

    /*2. Enable wakeup source to wakeup the whole system. */
    Power_CheckThenEnableWakeupSource(config->wakeupSource);
    SMM_EnableWakeupSourceToMainCpu(AON__SMM, sharedHandle->enabledWsInfo.mainWakeupSourceMask);
    SMM_EnableWakeupSourceToAonCpu(AON__SMM, sharedHandle->enabledWsInfo.aonWakeupSourceMask);
    PMU_UpdateFRO16KFreq(AON__PMU, config->fro16KOutputFreq);
    Power_ConfigureStallForMode(kPower_ShutDown, (config->fro16KOutputFreq == kPMU_FRO16KOutput16KHz) ? 16000 : 8000);

    /*3. Configuration of SMM. */
    SMM_StartAonShutDownSequence(AON__SMM);
    PMU_DoHandshakeBetweenPMUAndPAC(AON__PMU);

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
 * retval kStatus_Success                 Entered Shutdown (or completed the request sequence).
 * retval kStatus_POWER_MuTransferError   MU transfer error.
 * retval kStatus_POWER_RequestNotAllowed Request rejected by the peer.
 * retval kStatus_Power_DualCoreNotSynced Cores are not synchronized.
 * retval kStatus_Timeout                 Timed out while waiting for MU response (if timeout enabled).
 */
status_t Power_EnterShutDown(power_sd_config_t *config)
{
    assert(g_Handle_Offset != POWER_HANDLE_OFFSET_NOT_INIT_VALUE);

    power_handle_t *sharedHandle = (power_handle_t *)(POWER_SHARED_RAM_BASE_ADDR + g_Handle_Offset);

    if (sharedHandle->dualCoreSynced == false)
    {
        return kStatus_Power_DualCoreNotSynced;
    }

    memset(sharedHandle->lpConfig, 0UL, 16UL);
    memcpy(sharedHandle->lpConfig, config, sizeof(power_sd_config_t));
#if __CORTEX_M == 33U
    /*1. Inform CM0P that CM33 request to set whole system into SD mode, require CM0P execute WFI.  */
    if (sharedHandle->requestCM33Start != true)
    {
        status_t muStatus = Power_CM33RequestLowPowerMode(kPower_ShutDown, sharedHandle->muChannelId);
        if (muStatus != kStatus_Success)
        {
            return muStatus;
        }
    }

    /*2. Enable wakeup source to wakeup the whole system. */
    Power_CheckThenEnableWakeupSource(config->wakeupSource);
    SMM_EnableWakeupSourceToMainCpu(AON__SMM, sharedHandle->enabledWsInfo.mainWakeupSourceMask);
    SMM_EnableWakeupSourceToAonCpu(AON__SMM, sharedHandle->enabledWsInfo.aonWakeupSourceMask);

    /*3. Configuration of SMM and PMU. */
    PMU_UpdateFRO16KFreq(AON__PMU, config->fro16KOutputFreq);
    Power_ConfigureStallForMode(kPower_ShutDown, (config->fro16KOutputFreq == kPMU_FRO16KOutput16KHz) ? 16000 : 8000);
    /* Clean all settings of RTC. */
    AON__SMM->RTC_DCDC_CNTRL  = 0xe00;
    AON__SMM->RTC_XTAL_CONFG1 = 0x0UL;
    AON__SMM->RTC_XTAL_CONFG2 = 0x0UL;
    SMM_StartAonShutDownSequence(AON__SMM);
    PMU_DoHandshakeBetweenPMUAndPAC(AON__PMU);

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
    __ASM volatile("VSTMDB sp!, {D15}");
    __ASM volatile("VSTMDB sp!, {D14}");
    __ASM volatile("VSTMDB sp!, {D13}");
    __ASM volatile("VSTMDB sp!, {D12}");
    __ASM volatile("VSTMDB sp!, {D11}");
    __ASM volatile("VSTMDB sp!, {D10}");
    __ASM volatile("VSTMDB sp!, {D9}");
    __ASM volatile("VSTMDB sp!, {D8}");
#endif
    /* push LR */
    __ASM volatile("PUSH {lr}");

    /* push r12 */
    __ASM volatile("PUSH {r0}");
    __ASM volatile("MOV r0, r12");
    __ASM volatile("POP {r1}");
    __ASM volatile("PUSH {r0}");
    __ASM volatile("MOV r12, r1");

    /* push r11, r10, r9, r8. */
    __ASM volatile("MOV r0, r8");
    __ASM volatile("MOV r1, r9");
    __ASM volatile("MOV r2, r10");
    __ASM volatile("MOV r3, r11");
    __ASM volatile("PUSH {r0-r3}");

    /* push r7, r6, r5, r4. */
    __ASM volatile("PUSH {r4-r7}");

    /* push value of current handle.*/
    __ASM volatile("MOV r0, r12");
    __ASM volatile("LDR r1, [r0, #40]"); /* Latest word */
    __ASM volatile("PUSH {r1}");
    __ASM volatile("LDR r1, [r0, #36]"); /* handle->enabledWsInfo.mainWakeupSourceMask. */
    __ASM volatile("PUSH {r1}");
    __ASM volatile("LDR r1, [r0, #32]"); /* handle->enabledWsInfo.aonWakeupSourceMask. */
    __ASM volatile("PUSH {r1}");
    __ASM volatile("LDR r1, [r0, #28]"); /* handle->cm0pUserData. */
    __ASM volatile("PUSH {r1}");
    __ASM volatile("LDR r1, [r0, #24]"); /* handle->cm0pCallback. */
    __ASM volatile("PUSH {r1}");
    __ASM volatile("LDR r1, [r0, #20]"); /* handle->cm33UserData. */
    __ASM volatile("PUSH {r1}");
    __ASM volatile("LDR r1, [r0, #16]"); /* handle->cm33Callback. */
    __ASM volatile("PUSH {r1}");
    __ASM volatile("LDR r1, [r0, #12]"); /* handle->lpConfig[3]. */
    __ASM volatile("PUSH {r1}");
    __ASM volatile("LDR r1, [r0, #8]");  /* handle->lpConfig[2]. */
    __ASM volatile("PUSH {r1}");
    __ASM volatile("LDR r1, [r0, #4]");  /* handle->lpConfig[1]. */
    __ASM volatile("PUSH {r1}");
    __ASM volatile("LDR r1, [r0, #0]");  /* handle->lpConfig[0]. */
    __ASM volatile("PUSH {r1}");
    __ASM volatile("PUSH {r0}");

    /* push aspr, psr, PRIMASK, CONTROL */
    __ASM volatile("MRS r0, CONTROL");
    __ASM volatile("MRS r1, PRIMASK");
    __ASM volatile("MRS r2, XPSR");
    __ASM volatile("MRS r3, APSR");
    __ASM volatile("PUSH {r0-r3}");

    /* save current sp to backup register */
#if __CORTEX_M == 33U
    __ASM volatile("MOV R0, SP");
    __ASM volatile("UXTH R1, R0");
    __ASM volatile("LDR R2, =0xA009A034");
    __ASM volatile("STR R1, [R2]");
    __ASM volatile("LSRS R1, R0, #16");
    __ASM volatile("LDR R2, =0xA009A038");
    __ASM volatile("STR R1, [R2]");
#else
    __ASM volatile("MOV R0, SP");
    __ASM volatile("LDR R2, =0xA009A030");
    __ASM volatile("STR R0, [R2]");
#endif

    __ASM volatile("MOVS R0, #0");
    __ASM volatile("BX LR");

    return 0;
}

#define POWER_BCKP1_MSB_VALUE (uint32_t)(AON__SMM->MSB_BCKP1 & SMM_MSB_BCKP1_MSB1_MASK)

#define POWER_BCKP2_VALUE                                        \
    (uint32_t)((AON__SMM->LSB_BCKP2 & SMM_LSB_BCKP2_LSB2_MASK) | \
               ((AON__SMM->MSB_BCKP2 & SMM_MSB_BCKP2_MSB2_MASK) << 16UL))

/*!
 * brief Restore saved context from stack.
 */
#ifdef __IAR_SYSTEMS_ICC__
#pragma optimize = none
void Power_LowPowerBoot(void)
#elif (defined(__CC_ARM) || defined(__ARMCC_VERSION))
void Power_LowPowerBoot(void)
#elif (defined(__GNUC__)) || defined(DOXYGEN_OUTPUT)
void __attribute__((optimize("O0"))) Power_LowPowerBoot(void)
#else
void Power_LowPowerBoot(void)
#endif
{
    AON__CGU->PER_CLK_EN |= CGU_PER_CLK_EN_APB_CLK_MASK;
    __ISB();
#if __CORTEX_M == 33U
    if (POWER_BCKP2_VALUE != 0UL)
    {
        __ASM volatile("MOV sp, %[input]"
                       : // no C variable outputs
                       : [input] "r"(POWER_BCKP2_VALUE)
                       : // No need to tell nothing to the compiler
        );
        __ASM volatile("ISB");
#else
    if (POWER_BCKP1_MSB_VALUE != 0UL)
    {
        __ASM volatile("MOV sp, %[input]"
                       : // no C variable outputs
                       : [input] "r"(POWER_BCKP1_MSB_VALUE)
                       : // No need to tell nothing to the compiler
        );
#endif

        __ASM volatile("POP {r0-r3}");
        __ASM volatile("MSR CONTROL, r0");
        __ASM volatile("MSR PRIMASK, r1");
#ifdef __IAR_SYSTEMS_ICC__
        __ASM volatile("MSR psr, r2");
        __ASM volatile("MSR APSR, r3");
#else
        __ASM volatile("MSR xPSR_nzcvq, r2");
        __ASM volatile("MSR APSR_nzcvq, r3");
#endif
        __ASM volatile("ISB");

        /* Restore handle value. */
        __ASM volatile("POP {r0}"); /* handle address. */
#if (defined(__ICCARM__)) || ((defined(__CC_ARM) || defined(__ARMCC_VERSION)))
        __ASM volatile("SUBS %[output], r0, %[offset]"
                       : [output] "=r"(g_Handle_Offset)
                       : [offset] "r"(POWER_SHARED_RAM_BASE_ADDR)
                       : "r0");
#else
        __ASM volatile("SUB %[output], r0, %[offset]"
                       : [output] "=r"(g_Handle_Offset)
                       : [offset] "r"(POWER_SHARED_RAM_BASE_ADDR)
                       : "r0");
#endif
        __ASM volatile("ISB");

        __ASM volatile("MOV r0, %[input]"
                       :               // no C variable outputs
                       : [input] "r"(g_Handle_Offset + POWER_SHARED_RAM_BASE_ADDR)
                       :               // No need to tell nothing to the compiler
        );
        __ASM volatile("POP {r1-r7}"); /* first 7 words of handle. */
        __ASM volatile("STR r1, [r0]");
#if (defined(__ICCARM__)) || ((defined(__CC_ARM) || defined(__ARMCC_VERSION)))
        __ASM volatile("ADDS r0, r0, #4");
#else
        __ASM volatile("ADD r0, r0, #4");
#endif
        __ASM volatile("STR r2, [r0]");
#if (defined(__ICCARM__)) || ((defined(__CC_ARM) || defined(__ARMCC_VERSION)))
        __ASM volatile("ADDS r0, r0, #4");
#else
        __ASM volatile("ADD r0, r0, #4");
#endif
        __ASM volatile("STR r3, [r0]");
#if (defined(__ICCARM__)) || ((defined(__CC_ARM) || defined(__ARMCC_VERSION)))
        __ASM volatile("ADDS r0, r0, #4");
#else
        __ASM volatile("ADD r0, r0, #4");
#endif
        __ASM volatile("STR r4, [r0]");
#if (defined(__ICCARM__)) || ((defined(__CC_ARM) || defined(__ARMCC_VERSION)))
        __ASM volatile("ADDS r0, r0, #4");
#else
        __ASM volatile("ADD r0, r0, #4");
#endif
        __ASM volatile("STR r5, [r0]");
#if (defined(__ICCARM__)) || ((defined(__CC_ARM) || defined(__ARMCC_VERSION)))
        __ASM volatile("ADDS r0, r0, #4");
#else
        __ASM volatile("ADD r0, r0, #4");
#endif
        __ASM volatile("STR r6, [r0]");
#if (defined(__ICCARM__)) || ((defined(__CC_ARM) || defined(__ARMCC_VERSION)))
        __ASM volatile("ADDS r0, r0, #4");
#else
        __ASM volatile("ADD r0, r0, #4");
#endif
        __ASM volatile("STR r7, [r0]");
#if (defined(__ICCARM__)) || ((defined(__CC_ARM) || defined(__ARMCC_VERSION)))
        __ASM volatile("ADDS r0, r0, #4");
#else
        __ASM volatile("ADD r0, r0, #4");
#endif
        __ASM volatile("POP {r1-r4}"); /*left 4 words of handle. */
        __ASM volatile("STR r1, [r0]");
#if (defined(__ICCARM__)) || ((defined(__CC_ARM) || defined(__ARMCC_VERSION)))
        __ASM volatile("ADDS r0, r0, #4");
#else
        __ASM volatile("ADD r0, r0, #4");
#endif
        __ASM volatile("STR r2, [r0]");
#if (defined(__ICCARM__)) || ((defined(__CC_ARM) || defined(__ARMCC_VERSION)))
        __ASM volatile("ADDS r0, r0, #4");
#else
        __ASM volatile("ADD r0, r0, #4");
#endif
        __ASM volatile("STR r3, [r0]");
#if (defined(__ICCARM__)) || ((defined(__CC_ARM) || defined(__ARMCC_VERSION)))
        __ASM volatile("ADDS r0, r0, #4");
#else
        __ASM volatile("ADD r0, r0, #4");
#endif
        __ASM volatile("STR r4, [r0]");
        __ASM volatile("ISB");
        /* Restore r4-r7. */
        __ASM volatile("POP {r4-r7}");
        __ASM volatile("ISB");
        /* Restore r8-r12. */
        __ASM volatile("POP {r0-r4}");
        __ASM volatile("MOV r8, r0");
        __ASM volatile("MOV r9, r1");
        __ASM volatile("MOV r10, r2");
        __ASM volatile("MOV r11, r3");
        __ASM volatile("MOV r12, r4");
        __ASM volatile("ISB");
        /* Restore LR */
        __ASM volatile("POP {r0}"); /* saved PC */
        __ASM volatile("MOV lr, r0");
        __ASM volatile("ISB");
#ifdef __ARMVFP__
        __ASM volatile("VLDMIA sp!, {D8}");
        __ASM volatile("VLDMIA sp!, {D9}");
        __ASM volatile("VLDMIA sp!, {D10}");
        __ASM volatile("VLDMIA sp!, {D11}");
        __ASM volatile("VLDMIA sp!, {D12}");
        __ASM volatile("VLDMIA sp!, {D13}");
        __ASM volatile("VLDMIA sp!, {D14}");
        __ASM volatile("VLDMIA sp!, {D15}");
#endif
        __ASM volatile("MOVS r0, #1");
        __ASM volatile("BX lr");
    }
}


void Power_NotifyCM33ToRun(void)
{
    AON__SMM->MSB_BCKP1 = 0x5A5AU;
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
 * retval kStatus_Power_SyncFailed Failed to sync between dual cores.
 * retval kStatus_POWER_MuTransferError Something wrong during transfer.
 * retval kStatus_POWER_RequestNotAllowed Request is not allowed.
 * retval kStatus_Success Interpret request/response message successfully.
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
    assert(g_Handle_Offset != POWER_HANDLE_OFFSET_NOT_INIT_VALUE);

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

#if __CORTEX_M == 0U
    if (userAllowed && (targetLowPowerMode == kPower_DeepPowerDown2) && ADVC_IsEnabled())
    {
        Power_SetDpd2AdvcWorkaround((power_dpd2_config_t *)lpConfigAddr);
    }
#endif /* __CORTEX_M == 0U */

    uint32_t tmp32 = Power_PopulateMuMessage(resType, responseDir, targetLowPowerMode, lowerHalfWordValue);
    MU_SendMsg(POWER_USED_MU, channelId, tmp32);

    PMU_DoHandshakeBetweenPMUAndPAC(AON__PMU);
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
            sharedHandle->targetPowerMode   = targetLowPowerMode;
            sharedHandle->previousPowerMode = targetLowPowerMode;            
            if ((targetLowPowerMode == kPower_DeepPowerDown2) &&
                (((power_dpd2_config_t *)lpConfigAddr)->aonRamArraysToRetain != kPower_AonDomainNoneRams) &&
                (((power_dpd2_config_t *)lpConfigAddr)->saveContext == true))
            {
                if (Power_PushContext((uint32_t)sharedHandle) == 0UL)
                {
                    sharedHandle->cm0pWFI = true;
                    SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;
                    __DSB();
                    __ISB();
                    __WFI();
                }
                __ISB();
                __DSB();

                Power_ClearLpPowerSettings();
                AON__SMM->MSB_BCKP1 = SMM_MSB_BCKP1_MSB1(0U);
            }
            else
            {
                sharedHandle->cm0pWFI = true;
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
 * brief Interpret a MU response message.
 *
 * param[in] message The response message sent to the requester.
 *
 * retval kStatus_Success                 The response has been interpreted successfully (ACK).
 * retval kStatus_POWER_MuTransferError   Invalid message or MU error.
 * retval kStatus_POWER_RequestNotAllowed NACK due to target mode not allowed.
 * retval kStatus_Power_NackWithMultiReasons NACK with multiple reasons.
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
