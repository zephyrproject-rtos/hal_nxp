/*
 * Copyright 2025-2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_tenbaset_phy.h"
#include "fsl_clock.h"
#include "fsl_common.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

#ifndef CONFIG_TENBASET_PHY_MODE_TIMEOUT
/*! @brief TENBASET_PHY timeout for mode transitions (in microseconds). */
#define CONFIG_TENBASET_PHY_MODE_TIMEOUT (1000000U)
#endif /* CONFIG_TENBASET_PHY_MODE_TIMEOUT */

#ifndef CONFIG_TENBASET_PHY_RESET_TIMEOUT
/*! @brief TENBASET_PHY reset timeout (in microseconds). */
#define CONFIG_TENBASET_PHY_RESET_TIMEOUT (100000U)
#endif /* CONFIG_TENBASET_PHY_RESET_TIMEOUT */

#ifndef CONFIG_TENBASET_PHY_SMI_TIMEOUT
/*! @brief TENBASET_PHY SMI ready timeout (in loop cycles). */
#define CONFIG_TENBASET_PHY_SMI_TIMEOUT (1000U)
#endif /* CONFIG_TENBASET_PHY_SMI_TIMEOUT */

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*!
 * @brief Returns index of the TENBASET_PHY instance.
 *
 * @param base TENBASET_PHY peripheral base address.
 * @return Instance index.
 */
static uint32_t TENBASET_PHY_GetIndex(TENBASET_PHY_Type *base);

/*!
 * @brief Wait for mode transition completion.
 *
 * @param base TENBASET_PHY peripheral base address.
 * @param targetStatus Target mode status.
 * @param timeoutUs Timeout in microseconds.
 * @retval kStatus_Success Mode transition completed.
 * @retval kStatus_Timeout Timeout occurred.
 */
static status_t TENBASET_PHY_WaitForModeTransition(TENBASET_PHY_Type *base,
                                                   tenbaset_phy_mode_status_t targetStatus,
                                                   uint32_t timeoutUs);

/*!
 * @brief Perform software reset.
 *
 * @param base TENBASET_PHY peripheral base address.
 * @retval kStatus_Success Reset completed successfully.
 * @retval kStatus_Timeout Reset timeout.
 */
static status_t TENBASET_PHY_SoftwareReset(TENBASET_PHY_Type *base);

/*!
 * @brief Waits for the SMI (Serial Management Interface) to become ready.
 *
 * This internal function polls the SMI status until it becomes ready or a timeout occurs.
 * It is used internally by SMI read and write operations to ensure the interface
 * is available before initiating a transaction.
 *
 * @note This is a blocking function with a finite timeout to prevent indefinite waiting.
 *
 * @param base TENBASET_PHY peripheral base address
 * @return status_t Operation status
 *         - kStatus_Success: SMI became ready within the timeout period
 *         - kStatus_Timeout: SMI did not become ready before timeout expired
 *
 * @see TENBASET_PHY_SMIRead
 * @see TENBASET_PHY_SMIWrite
 */
static status_t TENBASET_PHY_WaitSMIReady(TENBASET_PHY_Type *base);

/*!
 * @brief Common interrupt handler for 10BASE-T1S PHY driver.
 *
 * This static function provides a shared implementation for handling
 * 10BASE-T1S PHY interrupts across multiple instances.
 *
 * @param index Instance index of the 10BASE-T1S PHY
 */
static void TENBASET_PHY_DriverIRQHandler(uint32_t index);

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*! @brief Pointers to TENBASET_PHY bases for each instance. */
static TENBASET_PHY_Type *const s_tenbaset_phyBases[] = TENBASET_PHY_BASE_PTRS;

/*! @brief Pointers to handles for each instance. */
static tenbaset_phy_handle_t *s_tenbaset_phyHandles[ARRAY_SIZE(s_tenbaset_phyBases)];

/*******************************************************************************
 * Code
 ******************************************************************************/

void TENBASET_PHY_GetDefaultConfig(tenbaset_phy_config_t *config)
{
    assert(config != NULL);

    /* Clear the configuration structure */
    (void)memset(config, 0, sizeof(*config));

    /* Set default PLCA configuration to match hardware defaults */
    config->plcaConfig.nodeId        = 0xFFU;
    config->plcaConfig.nodeCount     = 0x08U;
    config->plcaConfig.toTimer       = 0x20U;
    config->plcaConfig.burstTimer    = 0x80U;
    config->plcaConfig.maxBurstCount = 0U;
    config->plcaConfig.enable        = false;

    /* Set default wake configuration based on hardware defaults */
    config->wakeConfig.suspendWakeEnable       = true;
    config->wakeConfig.remoteWakeEnable        = true;
    config->wakeConfig.localWakeEnable         = true;
    config->wakeConfig.remoteWakeForwardEnable = true;
    config->wakeConfig.localWakeWupEnable      = true;
    config->wakeConfig.wupTimeout              = 0xFFU;

    /* Interrupts disabled by default */
    config->interruptMask = 0U;
}

void TENBASET_PHY_CreateHandle(TENBASET_PHY_Type *base,
                               tenbaset_phy_handle_t *handle,
                               tenbaset_phy_callback_t callback,
                               void *userData)
{
    assert(base != NULL);
    assert(handle != NULL);

    handle->callback    = callback;
    handle->userData    = userData;
    handle->initialized = false;
}

status_t TENBASET_PHY_Init(TENBASET_PHY_Type *base, const tenbaset_phy_config_t *config, tenbaset_phy_handle_t *handle)
{
    assert(base != NULL);
    assert(config != NULL);
    assert(handle != NULL);

    status_t status;

    /* Mark as not initialized */
    handle->initialized = false;

    /* Store the handle */
    s_tenbaset_phyHandles[TENBASET_PHY_GetIndex(base)] = handle;

    if (TENBASET_PHY_GetModeStatus(base) != kTENBASET_PHY_StatusLinkDown)
    {
        /* Perform software reset */
        status = TENBASET_PHY_SoftwareReset(base);
        if (status != kStatus_Success)
        {
            return status;
        }

        status =
            TENBASET_PHY_WaitForModeTransition(base, kTENBASET_PHY_StatusLinkDown, CONFIG_TENBASET_PHY_MODE_TIMEOUT);
        if (status != kStatus_Success)
        {
            return status;
        }
    }

    /* Go to link up state already, otherwise subsystems like PLCA will stay in reset */
    status = TENBASET_PHY_SetMode(base, kTENBASET_PHY_ModeLinkUp);
    if (status != kStatus_Success)
    {
        return status;
    }

    /* Configure PLCA */
    status = TENBASET_PHY_SetPLCAConfig(base, &config->plcaConfig);
    if (status != kStatus_Success)
    {
        return status;
    }

    /* Configure wake settings */
    TENBASET_PHY_SetWakeConfig(base, &config->wakeConfig);

    /* Enable only specified interrupts (if any) */
    TENBASET_PHY_DisableInterrupts(base, 0xFFFFU);
    TENBASET_PHY_EnableInterrupts(base, config->interruptMask);

    /* Mark as initialized */
    handle->initialized = true;

    return kStatus_Success;
}

void TENBASET_PHY_Deinit(TENBASET_PHY_Type *base, tenbaset_phy_handle_t *handle)
{
    assert(base != NULL);
    assert(handle != NULL);

    /* Disable all interrupts */
    TENBASET_PHY_DisableInterrupts(base, 0xFFFFU);

    /* Set to link down mode */
    (void)TENBASET_PHY_SetMode(base, kTENBASET_PHY_ModeLinkDown);

    /* Disable PLCA */
    uint16_t mask = (uint16_t)TENBASET_PHY_PLCACTRL0_EN_MASK;
    base->PLCACTRL0 &= ~mask;

    /* Clear handle */
    s_tenbaset_phyHandles[TENBASET_PHY_GetIndex(base)] = NULL;
    handle->initialized                                = false;
}

status_t TENBASET_PHY_SetMode(TENBASET_PHY_Type *base, tenbaset_phy_mode_t mode)
{
    assert(base != NULL);

    status_t status = kStatus_Success;

    /* Set the mode command */
    base->MODECTRL = TENBASET_PHY_MODECTRL_CMD(mode);

    /* Wait for mode transition if not "none" command */
    if (mode != kTENBASET_PHY_ModeNone)
    {
        tenbaset_phy_mode_status_t targetStatus;

        switch (mode)
        {
            case kTENBASET_PHY_ModeLinkDown:
                targetStatus = kTENBASET_PHY_StatusLinkDown;
                break;
            case kTENBASET_PHY_ModeLinkUp:
                targetStatus = kTENBASET_PHY_StatusLinkUp;
                break;
            case kTENBASET_PHY_ModeLowPower:
                targetStatus = kTENBASET_PHY_StatusLowPower;
                break;
            case kTENBASET_PHY_ModeTxcCfg:
                targetStatus = kTENBASET_PHY_StatusTxcCfg;
                break;
            case kTENBASET_PHY_ModeTxcBist:
                targetStatus = kTENBASET_PHY_StatusTxcBist;
                break;
            default:
                status = kStatus_InvalidArgument;
                break;
        }

        if (status != kStatus_Success)
        {
            return status;
        }

        status = TENBASET_PHY_WaitForModeTransition(base, targetStatus, CONFIG_TENBASET_PHY_MODE_TIMEOUT);
    }

    return status;
}

tenbaset_phy_mode_status_t TENBASET_PHY_GetModeStatus(TENBASET_PHY_Type *base)
{
    assert(base != NULL);

    return (tenbaset_phy_mode_status_t)((base->MODESTAT & TENBASET_PHY_MODESTAT_STAT_MASK) >>
                                        TENBASET_PHY_MODESTAT_STAT_SHIFT);
}

bool TENBASET_PHY_IsLinkUp(TENBASET_PHY_Type *base)
{
    assert(base != NULL);

    return (TENBASET_PHY_GetModeStatus(base) == kTENBASET_PHY_StatusLinkUp);
}

void TENBASET_PHY_GetPLCAConfig(TENBASET_PHY_Type *base, tenbaset_phy_plca_config_t *config)
{
    assert(base != NULL);
    assert(config != NULL);

    /* Clear configuration structure */
    (void)memset(config, 0, sizeof(*config));

    /* Extract node ID and count */
    config->nodeId = (uint8_t)((base->PLCACTRL1 & TENBASET_PHY_PLCACTRL1_ID_MASK) >> TENBASET_PHY_PLCACTRL1_ID_SHIFT);
    config->nodeCount =
        (uint8_t)((base->PLCACTRL1 & TENBASET_PHY_PLCACTRL1_NCNT_MASK) >> TENBASET_PHY_PLCACTRL1_NCNT_SHIFT);

    /* Extract timers */
    config->toTimer =
        (uint8_t)((base->PLCATOTMR & TENBASET_PHY_PLCATOTMR_TOTMR_MASK) >> TENBASET_PHY_PLCATOTMR_TOTMR_SHIFT);
    config->burstTimer =
        (uint8_t)((base->PLCABURST & TENBASET_PHY_PLCABURST_BTMR_MASK) >> TENBASET_PHY_PLCABURST_BTMR_SHIFT);
    config->maxBurstCount =
        (uint8_t)((base->PLCABURST & TENBASET_PHY_PLCABURST_MAXBC_MASK) >> TENBASET_PHY_PLCABURST_MAXBC_SHIFT);

    /* Check if PLCA is enabled */
    config->enable = (base->PLCACTRL0 & TENBASET_PHY_PLCACTRL0_EN_MASK) != 0U;
}

status_t TENBASET_PHY_SetPLCAConfig(TENBASET_PHY_Type *base, const tenbaset_phy_plca_config_t *config)
{
    assert(base != NULL);
    assert(config != NULL);

    /* Disable PLCA before configuration */
    uint16_t mask = (uint16_t)TENBASET_PHY_PLCACTRL0_EN_MASK;
    base->PLCACTRL0 &= ~mask;

    /* Configure node ID and count */
    base->PLCACTRL1 = TENBASET_PHY_PLCACTRL1_ID(config->nodeId) | TENBASET_PHY_PLCACTRL1_NCNT(config->nodeCount);

    /* Configure timers */
    base->PLCATOTMR = TENBASET_PHY_PLCATOTMR_TOTMR(config->toTimer);
    base->PLCABURST =
        TENBASET_PHY_PLCABURST_BTMR(config->burstTimer) | TENBASET_PHY_PLCABURST_MAXBC(config->maxBurstCount);

    /* Enable PLCA if requested */
    if (config->enable)
    {
        base->PLCACTRL0 |= TENBASET_PHY_PLCACTRL0_EN_MASK;
    }
    /* else PLCA has already been disabled above */

    return kStatus_Success;
}

bool TENBASET_PHY_GetPLCAStatus(TENBASET_PHY_Type *base)
{
    assert(base != NULL);

    return ((base->PLCASTAT & TENBASET_PHY_PLCASTAT_PST_MASK) != 0U);
}

uint32_t TENBASET_PHY_GetPLCADiagnosticFlags(TENBASET_PHY_Type *base)
{
    assert(base != NULL);

    uint32_t flags = 0U;

    flags |= TENBASET_PHY_PLCADIAG1_FLAG(base->PLCADIAG1);
    flags |= TENBASET_PHY_PLCADIAG2_FLAG(base->PLCADIAG2);

    return flags;
}

void TENBASET_PHY_ClearPLCADiagnosticFlags(TENBASET_PHY_Type *base, uint32_t diagFlags)
{
    assert(base != NULL);

    uint16_t clearMask1 = TENBASET_PHY_PLCADIAG1_FLAG_TO_REG(diagFlags);
    uint16_t clearMask2 = TENBASET_PHY_PLCADIAG2_FLAG_TO_REG(diagFlags);

    base->PLCADIAG1 = clearMask1;
    base->PLCADIAG2 = clearMask2;
}

uint16_t TENBASET_PHY_GetBeaconCounter(TENBASET_PHY_Type *base)
{
    assert(base != NULL);

    return (base->PLCADIAG3 & TENBASET_PHY_PLCADIAG3_RXBCNTCNT_MASK) >> TENBASET_PHY_PLCADIAG3_RXBCNTCNT_SHIFT;
}

void TENBASET_PHY_ClearBeaconCounter(TENBASET_PHY_Type *base)
{
    assert(base != NULL);

    /* Write 0 to clear counter */
    base->PLCADIAG3 = TENBASET_PHY_PLCADIAG3_RXBCNTCNT(0U);
}

uint16_t TENBASET_PHY_GetTransmitOpportunityCounter(TENBASET_PHY_Type *base)
{
    assert(base != NULL);

    return (base->PLCADIAG4 & TENBASET_PHY_PLCADIAG4_TOCNT_MASK) >> TENBASET_PHY_PLCADIAG4_TOCNT_SHIFT;
}

void TENBASET_PHY_ClearTransmitOpportunityCounter(TENBASET_PHY_Type *base)
{
    assert(base != NULL);

    /* Write 0 to clear counter */
    base->PLCADIAG4 = TENBASET_PHY_PLCADIAG4_TOCNT(0U);
}

void TENBASET_PHY_GetPMAConfig(TENBASET_PHY_Type *base, tenbaset_phy_pma_config_t *config)
{
    assert(base != NULL);
    assert(config != NULL);

    uint16_t pmactrl = base->PMACTRL;

    /* Clear configuration structure */
    (void)memset(config, 0, sizeof(*config));

    /* Extract reset bit */
    config->resetEnable = (pmactrl & TENBASET_PHY_PMACTRL_RST_MASK) != 0U;

    /* Extract transmission enable bit (not inverted) */
    config->transmissionEnable = (pmactrl & TENBASET_PHY_PMACTRL_TXDIS_MASK) == 0U;

    /* Extract loopback bit */
    config->loopbackEnable = (pmactrl & TENBASET_PHY_PMACTRL_LOOP_MASK) != 0U;
}

void TENBASET_PHY_SetPMAConfig(TENBASET_PHY_Type *base, const tenbaset_phy_pma_config_t *config)
{
    assert(base != NULL);
    assert(config != NULL);

    uint16_t pmactrl = 0U;

    /* Set reset bit */
    if (config->resetEnable)
    {
        pmactrl |= TENBASET_PHY_PMACTRL_RST_MASK;
    }

    /* Set transmission disable bit (based on transmission enable) */
    if (!config->transmissionEnable)
    {
        pmactrl |= TENBASET_PHY_PMACTRL_TXDIS_MASK;
    }

    /* Set loopback bit */
    if (config->loopbackEnable)
    {
        pmactrl |= TENBASET_PHY_PMACTRL_LOOP_MASK;
    }

    /* Always set multidrop bit (read-only, always 1) */
    pmactrl |= TENBASET_PHY_PMACTRL_MULT_MASK;

    /* Write to register */
    base->PMACTRL = pmactrl;
}

void TENBASET_PHY_GetPCSConfig(TENBASET_PHY_Type *base, tenbaset_phy_pcs_config_t *config)
{
    assert(base != NULL);
    assert(config != NULL);

    uint16_t pcsctrl = base->PCSCTRL;

    /* Clear configuration structure */
    (void)memset(config, 0, sizeof(*config));

    /* Extract reset bit */
    config->resetEnable = (pcsctrl & TENBASET_PHY_PCSCTRL_RST_MASK) != 0U;

    /* Extract loopback bit */
    config->loopbackEnable = (pcsctrl & TENBASET_PHY_PCSCTRL_LOOP_MASK) != 0U;
}

void TENBASET_PHY_SetPCSConfig(TENBASET_PHY_Type *base, const tenbaset_phy_pcs_config_t *config)
{
    assert(base != NULL);
    assert(config != NULL);

    uint16_t pcsctrl = 0U;

    /* Set reset bit */
    if (config->resetEnable)
    {
        pcsctrl |= TENBASET_PHY_PCSCTRL_RST_MASK;
    }

    /* Set loopback bit */
    if (config->loopbackEnable)
    {
        pcsctrl |= TENBASET_PHY_PCSCTRL_LOOP_MASK;
    }

    /* Always set half-duplex mode (fixed configuration) */
    pcsctrl |= TENBASET_PHY_PCSCTRL_DUPLX_MASK;

    /* Write to register */
    base->PCSCTRL = pcsctrl;
}

uint16_t TENBASET_PHY_GetRemoteJabberCounter(TENBASET_PHY_Type *base)
{
    assert(base != NULL);

    return (base->PCSDIAG1 & TENBASET_PHY_PCSDIAG1_REMJABCNT_MASK) >> TENBASET_PHY_PCSDIAG1_REMJABCNT_SHIFT;
}

uint16_t TENBASET_PHY_GetCollisionCounter(TENBASET_PHY_Type *base)
{
    assert(base != NULL);

    return (base->PCSDIAG2 & TENBASET_PHY_PCSDIAG2_PHYCOLCNT_MASK) >> TENBASET_PHY_PCSDIAG2_PHYCOLCNT_SHIFT;
}

void TENBASET_PHY_SetWakeConfig(TENBASET_PHY_Type *base, const tenbaset_phy_wake_config_t *config)
{
    assert(base != NULL);
    assert(config != NULL);

    uint16_t modecfg = 0U;
    uint16_t wkcfg   = 0U;
    uint16_t wupcfg  = 0U;

    /* Configure Mode Configuration (MODECFG) - wake events */
    if (config->suspendWakeEnable)
    {
        modecfg |= TENBASET_PHY_MODECFG_SSPWKENA_MASK;
    }
    if (config->remoteWakeEnable)
    {
        modecfg |= TENBASET_PHY_MODECFG_REMWKENA_MASK;
    }
    if (config->localWakeEnable)
    {
        modecfg |= TENBASET_PHY_MODECFG_LCLWKENA_MASK;
    }

    /* Configure Wake Configuration (WKCFG) - wake forwarding */
    if (config->remoteWakeForwardEnable)
    {
        wkcfg |= TENBASET_PHY_WKCFG_REMKWKFDW_MASK;
    }

    /* Configure Wakeup Configuration (WUPCFG) - WUP generation */
    if (config->localWakeWupEnable)
    {
        wupcfg |= TENBASET_PHY_WUPCFG_LCLWKWUP_MASK;
    }
    wupcfg |= TENBASET_PHY_WUPCFG_WUPTIMEOUT(config->wupTimeout);

    /* Write configuration to registers */
    base->MODECFG = modecfg;
    base->WKCFG   = wkcfg;
    base->WUPCFG  = wupcfg;
}

void TENBASET_PHY_TriggerWakeForward(TENBASET_PHY_Type *base)
{
    assert(base != NULL);

    /* Trigger generation of a wake-forward pulse (write 1 to trigger) */
    base->WKCTRL |= TENBASET_PHY_WKCTRL_REMWKFDW_MASK;
}

void TENBASET_PHY_TriggerWakeUp(TENBASET_PHY_Type *base)
{
    assert(base != NULL);

    /* Trigger WUP sequencer (write 1 to trigger) */
    base->WUPCTRL |= TENBASET_PHY_WUPCTRL_WUPCMD_MASK;
}

void TENBASET_PHY_AbortWakeUp(TENBASET_PHY_Type *base)
{
    assert(base != NULL);

    /* Abort WUP sequencer (write 1 to abort) */
    base->WUPCTRL |= TENBASET_PHY_WUPCTRL_ABORTCMD_MASK;
}

void TENBASET_PHY_GetWakeUpStatus(TENBASET_PHY_Type *base, tenbaset_phy_wup_status_info_t *statusInfo)
{
    assert(base != NULL);
    assert(statusInfo != NULL);

    uint16_t wupstat = base->WUPSTAT;

    /* Extract status */
    statusInfo->status =
        (tenbaset_phy_wup_status_t)((wupstat & TENBASET_PHY_WUPSTAT_STAT_MASK) >> TENBASET_PHY_WUPSTAT_STAT_SHIFT);

    /* Extract error code */
    statusInfo->errorCode = (tenbaset_phy_wup_error_code_t)((wupstat & TENBASET_PHY_WUPSTAT_ERRCODE_MASK) >>
                                                            TENBASET_PHY_WUPSTAT_ERRCODE_SHIFT);
}

void TENBASET_PHY_EnableInterrupts(TENBASET_PHY_Type *base, uint16_t mask)
{
    assert(base != NULL);

    base->INTENSET1 |= mask;
}

void TENBASET_PHY_DisableInterrupts(TENBASET_PHY_Type *base, uint16_t mask)
{
    assert(base != NULL);

    base->INTENCLR1 = mask;
}

uint16_t TENBASET_PHY_GetInterruptStatus(TENBASET_PHY_Type *base)
{
    assert(base != NULL);

    return base->INTSTAT1;
}

void TENBASET_PHY_ClearInterruptStatus(TENBASET_PHY_Type *base, uint16_t mask)
{
    assert(base != NULL);

    base->INTENCAPT1 = mask;
}

void TENBASET_PHY_EnableInterrupts2(TENBASET_PHY_Type *base, uint16_t mask)
{
    assert(base != NULL);

    base->INTENSET2 |= mask;
}

void TENBASET_PHY_DisableInterrupts2(TENBASET_PHY_Type *base, uint16_t mask)
{
    assert(base != NULL);

    base->INTENCLR2 = mask;
}

uint16_t TENBASET_PHY_GetInterruptStatus2(TENBASET_PHY_Type *base)
{
    assert(base != NULL);

    return base->INTSTAT2;
}

void TENBASET_PHY_ClearInterruptStatus2(TENBASET_PHY_Type *base, uint16_t mask)
{
    assert(base != NULL);

    base->INTENCAPT2 = mask;
}

void TENBASET_PHY0_DriverIRQHandler(void);
void TENBASET_PHY0_DriverIRQHandler(void)
{
    TENBASET_PHY_DriverIRQHandler(0U);
    SDK_ISR_EXIT_BARRIER;
}

#if defined(FSL_FEATURE_SOC_TENBASET_PHY_COUNT) && FSL_FEATURE_SOC_TENBASET_PHY_COUNT > 1
void TENBASET_PHY1_DriverIRQHandler(void);
void TENBASET_PHY1_DriverIRQHandler(void)
{
    TENBASET_PHY_DriverIRQHandler(1U);
    SDK_ISR_EXIT_BARRIER;
}
#endif /* FSL_FEATURE_SOC_TENBASET_PHY_COUNT */

uint32_t TENBASET_PHY_GetPhyId(TENBASET_PHY_Type *base)
{
    assert(base != NULL);

    uint32_t phyId0 = base->PHYID0;
    uint32_t phyId1 = base->PHYID1;
    uint32_t phyId  = 0U;

    /* Extract OUI bits 3-18 from PHYID0[15:0] and place in bits 3-18 of result */
    phyId |= (((uint32_t)(phyId0 & TENBASET_PHY_PHYID0_OUI_03_18_MASK) >> TENBASET_PHY_PHYID0_OUI_03_18_SHIFT) << 3U);

    /* Extract OUI bits 19-24 from PHYID1[15:10] and place in bits 19-24 of result */
    phyId |= (((uint32_t)(phyId1 & TENBASET_PHY_PHYID1_OUI_19_24_MASK) >> TENBASET_PHY_PHYID1_OUI_19_24_SHIFT) << 19U);

    return phyId;
}

void TENBASET_PHY_GetVersionInfo(TENBASET_PHY_Type *base, tenbaset_phy_version_info_t *versionInfo)
{
    assert(base != NULL);
    assert(versionInfo != NULL);

    uint16_t version = base->VERSION;

    versionInfo->majorVersion =
        (uint8_t)((version & TENBASET_PHY_VERSION_MAJORVER_MASK) >> TENBASET_PHY_VERSION_MAJORVER_SHIFT);
    versionInfo->minorVersion =
        (uint8_t)((version & TENBASET_PHY_VERSION_MINORVER_MASK) >> TENBASET_PHY_VERSION_MINORVER_SHIFT);
    versionInfo->customerVersion =
        (uint8_t)((version & TENBASET_PHY_VERSION_CUSTVER_MASK) >> TENBASET_PHY_VERSION_CUSTVER_SHIFT);
}

uint16_t TENBASET_PHY_GetTransceiverDiagnosticFlags(TENBASET_PHY_Type *base)
{
    assert(base != NULL);

    return base->TXCDIAG;
}

void TENBASET_PHY_ClearTransceiverDiagnosticFlags(TENBASET_PHY_Type *base, uint16_t diagFlags)
{
    assert(base != NULL);

    /* Clear the flags (write 1 to clear) */
    base->TXCDIAG = diagFlags;
}

status_t TENBASET_PHY_SetSMIConfig(TENBASET_PHY_Type *base, const tenbaset_phy_smi_config_t *config)
{
    assert(base != NULL);
    assert(config != NULL);

    /* Validate input parameters */
    if (config->speed > 0x3FU)
    {
        return kStatus_InvalidArgument;
    }

    uint16_t smicfg = 0U;

    /* Configure MDIO hold time */
    smicfg |= TENBASET_PHY_SMICFG_HOLD(config->holdTime);

    /* Configure preamble */
    if (config->preambleEnable)
    {
        smicfg |= TENBASET_PHY_SMICFG_DISPRE_MASK;
    }

    /* Configure MDC clock speed */
    smicfg |= TENBASET_PHY_SMICFG_SPEED(config->speed);

    /* Write configuration */
    base->SMICFG = smicfg;

    return kStatus_Success;
}

bool TENBASET_PHY_GetSMIStatus(TENBASET_PHY_Type *base, tenbaset_phy_smi_error_code_t *errorCode)
{
    assert(base != NULL);

    /* Read status register once to maintain consistent value */
    uint16_t smistat = base->SMISTAT;

    /* Check if SMI is ready */
    bool isReady = (smistat & TENBASET_PHY_SMISTAT_READY_MASK) != 0U;

    /* Extract error code if pointer is not NULL */
    if (errorCode != NULL)
    {
        *errorCode = (tenbaset_phy_smi_error_code_t)((smistat & TENBASET_PHY_SMISTAT_ERRCODE_MASK) >>
                                                     TENBASET_PHY_SMISTAT_ERRCODE_SHIFT);
    }

    return isReady;
}

status_t TENBASET_PHY_SMIRead(TENBASET_PHY_Type *base, uint8_t phyAddr, uint8_t regAddr, uint16_t *data)
{
    assert(base != NULL);
    assert(data != NULL);

    /* Wait for SMI to be ready */
    status_t result = TENBASET_PHY_WaitSMIReady(base);
    if (result != kStatus_Success)
    {
        return result;
    }

    /* Construct SMI control register value */
    base->SMICTRL = TENBASET_PHY_SMICTRL_ST(1)                       /* Start of frame delimiter */
                    | TENBASET_PHY_SMICTRL_OP(kTENBASET_PHY_SMIRead) /* Read operation */
                    | TENBASET_PHY_SMICTRL_PA(phyAddr)               /* PHY address */
                    | TENBASET_PHY_SMICTRL_RA(regAddr)               /* Register address */
                    | TENBASET_PHY_SMICTRL_TA(2);                    /* Turn-around */

    /* Return read data */
    *data = base->SMIDATA;

    return kStatus_Success;
}

status_t TENBASET_PHY_SMIWrite(TENBASET_PHY_Type *base, uint8_t phyAddr, uint8_t regAddr, uint16_t data)
{
    assert(base != NULL);

    /* Wait for SMI to be ready */
    status_t result = TENBASET_PHY_WaitSMIReady(base);
    if (result != kStatus_Success)
    {
        return result;
    }

    /* Write data to SMI data register */
    base->SMIDATA = data;

    /* Construct SMI control register value */
    base->SMICTRL = TENBASET_PHY_SMICTRL_ST(1)                        /* Start of frame delimiter */
                    | TENBASET_PHY_SMICTRL_OP(kTENBASET_PHY_SMIWrite) /* Write operation */
                    | TENBASET_PHY_SMICTRL_PA(phyAddr)                /* PHY address */
                    | TENBASET_PHY_SMICTRL_RA(regAddr)                /* Register address */
                    | TENBASET_PHY_SMICTRL_TA(2);                     /* Turn-around */

    return kStatus_Success;
}

/*******************************************************************************
 * Static Functions
 ******************************************************************************/

static uint32_t TENBASET_PHY_GetIndex(TENBASET_PHY_Type *base)
{
    uint32_t index;

    /* Find the instance index from base address mappings. */
    for (index = 0; index < ARRAY_SIZE(s_tenbaset_phyBases); index++)
    {
        if (MSDK_REG_SECURE_ADDR(s_tenbaset_phyBases[index]) == MSDK_REG_SECURE_ADDR(base))
        {
            break;
        }
    }

    assert(index < ARRAY_SIZE(s_tenbaset_phyBases));

    return index;
}

static status_t TENBASET_PHY_WaitForModeTransition(TENBASET_PHY_Type *base,
                                                   tenbaset_phy_mode_status_t targetStatus,
                                                   uint32_t timeoutUs)
{
    uint32_t elapsedTime     = 0U;
    const uint32_t delayStep = 25U; /* Check every 25us */

    while (TENBASET_PHY_GetModeStatus(base) != targetStatus)
    {
        if (elapsedTime >= timeoutUs)
        {
            return kStatus_Timeout;
        }

        SDK_DelayAtLeastUs(delayStep, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);

        if (UINT32_MAX - elapsedTime < delayStep)
        {
            return kStatus_Timeout;
        }

        elapsedTime += delayStep;
    }

    return kStatus_Success;
}

static status_t TENBASET_PHY_SoftwareReset(TENBASET_PHY_Type *base)
{
    uint32_t delayCount      = 0U;
    const uint32_t delayStep = 25U; /* Check every 25us */

    /* Reset PHY - this will reset all subsystems */
    base->PHYCTRL |= TENBASET_PHY_PHYCTRL_RESET_MASK;

    /* Wait for reset to complete */
    while ((base->PHYCTRL & TENBASET_PHY_PHYCTRL_RESET_MASK) != 0U)
    {
        if (delayCount >= CONFIG_TENBASET_PHY_RESET_TIMEOUT)
        {
            return kStatus_Timeout;
        }

        SDK_DelayAtLeastUs(delayStep, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);
        delayCount += delayStep;
    }

    return kStatus_Success;
}

static status_t TENBASET_PHY_WaitSMIReady(TENBASET_PHY_Type *base)
{
    tenbaset_phy_smi_error_code_t errorCode;
    uint32_t timeout = CONFIG_TENBASET_PHY_SMI_TIMEOUT;

    while (!TENBASET_PHY_GetSMIStatus(base, &errorCode))
    {
        if (timeout-- == 0U)
        {
            return kStatus_Timeout;
        }
    }

    return kStatus_Success;
}

static void TENBASET_PHY_DriverIRQHandler(uint32_t index)
{
    TENBASET_PHY_Type *base       = s_tenbaset_phyBases[index];
    tenbaset_phy_handle_t *handle = s_tenbaset_phyHandles[index];

    uint16_t flags = TENBASET_PHY_GetInterruptStatus(base);

    if (flags != 0U)
    {
        /* Clear the interrupt flags */
        TENBASET_PHY_ClearInterruptStatus(base, flags);

        if ((handle != NULL) && handle->initialized && (handle->callback != NULL))
        {
            /* Call user callback */
            handle->callback(base, flags, handle->userData);
        }
    }
}
