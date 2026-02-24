/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_TENBASET_PHY_H_
#define FSL_TENBASET_PHY_H_

#include "fsl_common.h"

/*!
 * @addtogroup tenbaset_phy
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*@{*/
/*! @brief TENBASET_PHY driver version. */
#define FSL_TENBASET_PHY_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*@}*/

#define TENBASET_PHY_PLCADIAG1_FLAG(flag)        ((uint32_t)(flag) << 0U)
#define TENBASET_PHY_PLCADIAG2_FLAG(flag)        ((uint32_t)(flag) << 16U)
#define TENBASET_PHY_PLCADIAG1_FLAG_TO_REG(flag) ((uint16_t)(((flag)&0x0000FFFFU) >> 0U))
#define TENBASET_PHY_PLCADIAG2_FLAG_TO_REG(flag) ((uint16_t)(((flag)&0xFFFF0000U) >> 16U))

/*! @brief TENBASET_PHY operating modes. */
typedef enum _tenbaset_phy_mode
{
    kTENBASET_PHY_ModeNone     = 0U, /*!< No mode command */
    kTENBASET_PHY_ModeLinkDown = 1U, /*!< Link down mode */
    kTENBASET_PHY_ModeLinkUp   = 2U, /*!< Link up mode */
    kTENBASET_PHY_ModeTxcCfg   = 3U, /*!< Transceiver configuration mode */
    kTENBASET_PHY_ModeLowPower = 4U, /*!< Low power mode */
    kTENBASET_PHY_ModeTxcBist  = 5U, /*!< Transceiver BIST mode */
} tenbaset_phy_mode_t;

/*! @brief TENBASET_PHY mode status. */
typedef enum _tenbaset_phy_mode_status
{
    kTENBASET_PHY_StatusPorst         = 0U,  /*!< Power-on reset state */
    kTENBASET_PHY_StatusWaitInit      = 1U,  /*!< Wait for initialization */
    kTENBASET_PHY_StatusLinkDown      = 2U,  /*!< Link down state */
    kTENBASET_PHY_StatusLinkUp        = 3U,  /*!< Link up state */
    kTENBASET_PHY_StatusWaitCmdLp     = 4U,  /*!< Wait for low power command */
    kTENBASET_PHY_StatusLowPower      = 5U,  /*!< Low power state */
    kTENBASET_PHY_StatusWaitCmdCfg    = 6U,  /*!< Wait for configuration command */
    kTENBASET_PHY_StatusTxcCfg        = 7U,  /*!< Transceiver configuration state */
    kTENBASET_PHY_StatusTxcBist       = 8U,  /*!< Transceiver BIST state */
    kTENBASET_PHY_StatusWaitSilentLp  = 9U,  /*!< Wait silent for low power */
    kTENBASET_PHY_StatusWaitSilentCfg = 10U, /*!< Wait silent for configuration */
} tenbaset_phy_mode_status_t;

/*! @brief TENBASET_PHY PLCA configuration structure. */
typedef struct _tenbaset_phy_plca_config
{
    uint8_t nodeId;        /*!< PLCA node identifier */
    uint8_t nodeCount;     /*!< Total number of nodes in network */
    uint8_t toTimer;       /*!< Transmit opportunity timer value */
    uint8_t burstTimer;    /*!< Burst timer value */
    uint8_t maxBurstCount; /*!< Maximum burst count */
    bool enable;           /*!< Enable PLCA */
} tenbaset_phy_plca_config_t;

/*! @brief TENBASET_PHY PLCA diagnostic flags. */
enum _tenbaset_phy_plca_diag_flags
{
    kTENBASET_PHY_RxInTo = TENBASET_PHY_PLCADIAG1_FLAG(
        TENBASET_PHY_PLCADIAG1_RXINTO_MASK),     /*!< Reception occurred within local transmit opportunity */
    kTENBASET_PHY_UnexpectedBeacon = TENBASET_PHY_PLCADIAG1_FLAG(
        TENBASET_PHY_PLCADIAG1_UNEXPB_MASK),     /*!< Reception of unexpected BEACON by coordinator */
    kTENBASET_PHY_BeaconBeforeTo = TENBASET_PHY_PLCADIAG1_FLAG(
        TENBASET_PHY_PLCADIAG1_BCNBFTO_MASK),    /*!< 4 consecutive BEACONs received before TO reached */
    kTENBASET_PHY_UndefinedState = TENBASET_PHY_PLCADIAG2_FLAG(
        TENBASET_PHY_PLCADIAG2_UNDEFSTATE_MASK), /*!< PLCA state-machines in undefined state */
    kTENBASET_PHY_NoRxBeacon = TENBASET_PHY_PLCADIAG2_FLAG(
        TENBASET_PHY_PLCADIAG2_NORXBCN_MASK),    /*!< No beacon received by coordinator while transmitted */
    kTENBASET_PHY_LateBeacon = TENBASET_PHY_PLCADIAG2_FLAG(
        TENBASET_PHY_PLCADIAG2_LATEBCN_MASK),    /*!< Reception of late BEACON by follower node */
    kTENBASET_PHY_EarlyBeacon = TENBASET_PHY_PLCADIAG2_FLAG(
        TENBASET_PHY_PLCADIAG2_EARLYBCN_MASK),   /*!< Reception of early BEACON by follower node */
};

/*! @brief PMA configuration structure */
typedef struct _tenbaset_phy_pma_config
{
    bool resetEnable;        /*!< Reset the PMA and PCS layers */
    bool transmissionEnable; /*!< Enable transmission */
    bool loopbackEnable;     /*!< Enable PMA loopback mode */
} tenbaset_phy_pma_config_t;

/*! @brief PCS configuration structure */
typedef struct _tenbaset_phy_pcs_config
{
    bool resetEnable;    /*!< Reset the PCS layer */
    bool loopbackEnable; /*!< Enable PCS loopback mode */
} tenbaset_phy_pcs_config_t;

/*! @brief TENBASET_PHY wake configuration structure. */
typedef struct _tenbaset_phy_wake_config
{
    /* Mode Configuration (MODECFG) settings */
    bool suspendWakeEnable; /*!< Enable wake-up to WAITINIT mode by SUSPEND detection */
    bool remoteWakeEnable;  /*!< Enable wake-up to WAITINIT mode by remote-wake-event */
    bool localWakeEnable;   /*!< Enable wake-up to WAITINIT mode by local-wake-event */

    /* Wake Configuration (WKCFG) settings */
    bool remoteWakeForwardEnable; /*!< Enable wake forwarding of a remote-wake-event */

    /* Wakeup Configuration (WUPCFG) settings */
    bool localWakeWupEnable; /*!< Enable WUP transmission by local-wake-event */
    uint8_t wupTimeout;      /*!< WUP timeout value (WUP time-out = (WUPTIMEOUT + 1) * 10ms) */
} tenbaset_phy_wake_config_t;

/*! @brief TENBASET_PHY WUP error codes. */
typedef enum _tenbaset_phy_wup_error_code
{
    kTENBASET_PHY_WupErrorNone    = 0U, /*!< WUP transmission successful */
    kTENBASET_PHY_WupErrorSwAbort = 1U, /*!< WUP sequencer aborted by software */
    kTENBASET_PHY_WupErrorModeChg = 2U, /*!< WUP sequencer aborted by invalid mode */
    kTENBASET_PHY_WupErrorToWm    = 3U, /*!< WUP sequencer aborted by time-out in WAITMODE state */
    kTENBASET_PHY_WupErrorToPd    = 4U, /*!< WUP sequencer aborted by time-out in PENDING state */
    kTENBASET_PHY_WupErrorToWp    = 5U, /*!< WUP sequencer aborted by time-out in PENDING state */
    kTENBASET_PHY_WupErrorToWa    = 6U, /*!< WUP sequencer aborted by time-out in PENDING state */
    kTENBASET_PHY_WupErrorCore    = 7U  /*!< WUP sequencer aborted by core */
} tenbaset_phy_wup_error_code_t;

/*! @brief TENBASET_PHY WUP sequencer status. */
typedef enum _tenbaset_phy_wup_status
{
    kTENBASET_PHY_WupStatusIdle     = 0U, /*!< WUP sequencer is idle */
    kTENBASET_PHY_WupStatusWaitLink = 1U, /*!< WUP sequencer is waiting for LINKUP mode */
    kTENBASET_PHY_WupStatusPending  = 2U  /*!< WUP sequencer is waiting for transmission slot */
} tenbaset_phy_wup_status_t;

/*! @brief TENBASET_PHY WUP status structure. */
typedef struct _tenbaset_phy_wup_status_info
{
    tenbaset_phy_wup_status_t status;        /*!< WUP sequencer status */
    tenbaset_phy_wup_error_code_t errorCode; /*!< Error code of previous WUP sequence */
} tenbaset_phy_wup_status_info_t;

/*! @brief TENBASET_PHY version information structure. */
typedef struct _tenbaset_phy_version_info
{
    uint8_t majorVersion;    /*!< Major version number */
    uint8_t minorVersion;    /*!< Minor version number */
    uint8_t customerVersion; /*!< Customer version number */
} tenbaset_phy_version_info_t;

/*! @brief TENBASET_PHY transceiver diagnostic flags. */
enum _tenbaset_phy_txc_diag_flags
{
    kTENBASET_PHY_LowPowerFail = TENBASET_PHY_TXCDIAG_LPWRFAIL_MASK,  /*!< Failure of ED/RX pin in LOWPOWER mode */
    kTENBASET_PHY_EdHighFail   = TENBASET_PHY_TXCDIAG_EDHGHFAIL_MASK, /*!< Stuck HIGH of the ED pin */
    kTENBASET_PHY_EdLowFail    = TENBASET_PHY_TXCDIAG_EDLOWFAIL_MASK, /*!< Stuck LOW of the ED pin */
    kTENBASET_PHY_RxHighFail   = TENBASET_PHY_TXCDIAG_RXHGHFAIL_MASK, /*!< Stuck HIGH of the RX pin */
    kTENBASET_PHY_RxLowFail    = TENBASET_PHY_TXCDIAG_RXLOWFAIL_MASK, /*!< Stuck LOW of the RX pin */
};

/*! @brief TENBASET_PHY interrupt flags. */
enum _tenbaset_phy_interrupt_flags
{
    kTENBASET_PHY_PhysicalCollisionFlag = TENBASET_PHY_INTSTAT1_PHYSCOL_MASK,   /*!< Physical collision interrupt */
    kTENBASET_PHY_PLCARecoveryFlag      = TENBASET_PHY_INTSTAT1_PLCAREC_MASK,   /*!< PLCA recovery interrupt */
    kTENBASET_PHY_PLCAStatusFlag        = TENBASET_PHY_INTSTAT1_PLCASTAT_MASK,  /*!< PLCA status interrupt */
    kTENBASET_PHY_ModeStatusFlag        = TENBASET_PHY_INTSTAT1_MODESTAT_MASK,  /*!< Mode status interrupt */
    kTENBASET_PHY_InvalidAPBFlag        = TENBASET_PHY_INTSTAT1_INVLDAPB_MASK,  /*!< Invalid APB interrupt */
    kTENBASET_PHY_LocalJabberFlag       = TENBASET_PHY_INTSTAT1_LOCJAB_MASK,    /*!< Local jabber interrupt */
    kTENBASET_PHY_RemoteJabberFlag      = TENBASET_PHY_INTSTAT1_REMJAB_MASK,    /*!< Remote jabber interrupt */
    kTENBASET_PHY_PinFaultFlag          = TENBASET_PHY_INTSTAT1_PINFAULT_MASK,  /*!< Pin fault interrupt */
    kTENBASET_PHY_PLCADiagFlag          = TENBASET_PHY_INTSTAT1_PLCADIAG_MASK,  /*!< PLCA diagnostics interrupt */
    kTENBASET_PHY_SMIAccessFlag         = TENBASET_PHY_INTSTAT1_SMIACCESS_MASK, /*!< SMI access interrupt */
    kTENBASET_PHY_LocalWakeFlag         = TENBASET_PHY_INTSTAT1_LCLWK_MASK,     /*!< Local wake interrupt */
    kTENBASET_PHY_SuspendDetectFlag     = TENBASET_PHY_INTSTAT1_SSPDET_MASK,    /*!< Suspend detect interrupt */
    kTENBASET_PHY_WUTDetectFlag         = TENBASET_PHY_INTSTAT1_WUTDET_MASK,    /*!< WUT detect interrupt */
    kTENBASET_PHY_WUPDoneFlag           = TENBASET_PHY_INTSTAT1_WUPDONE_MASK,   /*!< WUP done interrupt */
    kTENBASET_PHY_APBParityFlag         = TENBASET_PHY_INTSTAT1_APBPARITY_MASK, /*!< APB parity interrupt */
};

/*! @brief SMI operation types */
typedef enum _tenbaset_phy_smi_operation
{
    kTENBASET_PHY_SMIWriteWithCompError = 0U, /*!< Write frame with C22 compliance error */
    kTENBASET_PHY_SMIWrite              = 1U, /*!< Standard write frame operation */
    kTENBASET_PHY_SMIRead               = 2U, /*!< Standard read frame operation */
    kTENBASET_PHY_SMIReadWithCompError  = 3U  /*!< Read frame with C22 compliance error */
} tenbaset_phy_smi_operation_t;

/*! @brief SMI MDIO hold time options */
typedef enum _tenbaset_phy_smi_hold_time
{
    kTENBASET_PHY_SMIHold1Cycle  = 0U, /*!< 1 PCLK cycle */
    kTENBASET_PHY_SMIHold2Cycles = 1U, /*!< 2 PCLK cycles */
    kTENBASET_PHY_SMIHold3Cycles = 2U, /*!< 3 PCLK cycles */
    kTENBASET_PHY_SMIHold4Cycles = 3U, /*!< 4 PCLK cycles */
    kTENBASET_PHY_SMIHold5Cycles = 4U, /*!< 5 PCLK cycles */
    kTENBASET_PHY_SMIHold6Cycles = 5U, /*!< 6 PCLK cycles */
    kTENBASET_PHY_SMIHold7Cycles = 6U, /*!< 7 PCLK cycles */
    kTENBASET_PHY_SMIHold8Cycles = 7U  /*!< 8 PCLK cycles */
} tenbaset_phy_smi_hold_time_t;

/*! @brief SMI configuration structure */
typedef struct _tenbaset_phy_smi_config
{
    tenbaset_phy_smi_hold_time_t holdTime; /*!< MDIO hold time */
    bool preambleEnable;                   /*!< Enable SMI preamble generation */
    uint8_t speed;                         /*!< MDC clock frequency divisor (0-63) */
} tenbaset_phy_smi_config_t;

/*! @brief SMI error codes */
typedef enum _tenbaset_phy_smi_error_code
{
    kTENBASET_PHY_SMIErrorNone       = 0U, /*!< SMI access successful */
    kTENBASET_PHY_SMIErrorNonTC14    = 1U, /*!< Non-compliancy with TC14 detected */
    kTENBASET_PHY_SMIErrorDisabled   = 2U, /*!< SMI access triggered while disabled */
    kTENBASET_PHY_SMIErrorAborted    = 3U, /*!< SMI access got aborted */
    kTENBASET_PHY_SMIErrorInProgress = 4U  /*!< SMI access triggered while in progress */
} tenbaset_phy_smi_error_code_t;

/*! @brief TENBASET_PHY callback function type. */
typedef void (*tenbaset_phy_callback_t)(TENBASET_PHY_Type *base, uint16_t flags, void *userData);

/*! @brief TENBASET_PHY configuration structure. */
typedef struct _tenbaset_phy_config
{
    tenbaset_phy_plca_config_t plcaConfig; /*!< PLCA configuration */
    tenbaset_phy_wake_config_t wakeConfig; /*!< Wake configuration */
    uint16_t interruptMask;                /*!< Mask of enabled interrupts */
} tenbaset_phy_config_t;

/*! @brief TENBASET_PHY handle structure. */
typedef struct _tenbaset_phy_handle
{
    tenbaset_phy_callback_t callback; /*!< Callback function */
    void *userData;                   /*!< User data for callback */
    bool initialized;                 /*!< Initialization status */
} tenbaset_phy_handle_t;

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @name Initialization and Deinitialization
 * @{
 */

/*!
 * @brief Gets the default configuration structure.
 *
 * This function initializes the TENBASET_PHY configuration structure to default values. The default values are:
 * @code
 *   config->plcaConfig.nodeId        = 0xFFU;
 *   config->plcaConfig.nodeCount     = 0x08U;
 *   config->plcaConfig.toTimer       = 0x20U;
 *   config->plcaConfig.burstTimer    = 0x80U;
 *   config->plcaConfig.maxBurstCount = 0U;
 *   config->plcaConfig.enable        = false;
 *   config->wakeConfig.suspendWakeEnable       = true;
 *   config->wakeConfig.remoteWakeEnable        = true;
 *   config->wakeConfig.localWakeEnable         = true;
 *   config->wakeConfig.remoteWakeForwardEnable = true;
 *   config->wakeConfig.localWakeWupEnable      = true;
 *   config->wakeConfig.wupTimeout              = 0xFFU;
 *   config->interruptMask = 0U;
 * @endcode
 *
 * @param config Pointer to the TENBASET_PHY configuration structure.
 */
void TENBASET_PHY_GetDefaultConfig(tenbaset_phy_config_t *config);

/*!
 * @brief Initializes driver handle for TENBASET_PHY instance.
 *
 * This function initializes the handle with the provided data.
 *
 * @param base TENBASET_PHY peripheral base address.
 * @param handle Pointer to the TENBASET_PHY handle structure.
 * @param callback Pointer to the callback function called from ISR.
 * @param userData Pointer to the user data (passed to the callback).
 */
void TENBASET_PHY_CreateHandle(TENBASET_PHY_Type *base,
                               tenbaset_phy_handle_t *handle,
                               tenbaset_phy_callback_t callback,
                               void *userData);

/*!
 * @brief Initializes the TENBASET_PHY peripheral.
 *
 * This function initializes the TENBASET_PHY peripheral with the provided configuration.
 *
 * @param base TENBASET_PHY peripheral base address.
 * @param config Pointer to the TENBASET_PHY configuration structure.
 * @param handle Pointer to the TENBASET_PHY handle structure.
 * @retval kStatus_Success Initialization successful.
 * @retval kStatus_Timeout Initialization timeout.
 * @retval kStatus_Fail PLCA configuration error.
 */
status_t TENBASET_PHY_Init(TENBASET_PHY_Type *base, const tenbaset_phy_config_t *config, tenbaset_phy_handle_t *handle);

/*!
 * @brief Deinitializes the TENBASET_PHY peripheral.
 *
 * @param base TENBASET_PHY peripheral base address.
 * @param handle Pointer to the TENBASET_PHY handle structure.
 */
void TENBASET_PHY_Deinit(TENBASET_PHY_Type *base, tenbaset_phy_handle_t *handle);

/*! @} */

/*!
 * @name Mode Control
 * @{
 */

/*!
 * @brief Sets the TENBASET_PHY operating mode.
 *
 * @param base TENBASET_PHY peripheral base address.
 * @param mode Target operating mode.
 * @retval kStatus_Success Mode set successfully.
 * @retval kStatus_Timeout Mode transition timeout.
 * @retval kStatus_InvalidArgument Invalid mode transition.
 */
status_t TENBASET_PHY_SetMode(TENBASET_PHY_Type *base, tenbaset_phy_mode_t mode);

/*!
 * @brief Gets the current TENBASET_PHY mode status.
 *
 * @param base TENBASET_PHY peripheral base address.
 * @return Current mode status.
 */
tenbaset_phy_mode_status_t TENBASET_PHY_GetModeStatus(TENBASET_PHY_Type *base);

/*!
 * @brief Checks if the link is up.
 *
 * @param base TENBASET_PHY peripheral base address.
 * @return true if link is up, false otherwise.
 */
bool TENBASET_PHY_IsLinkUp(TENBASET_PHY_Type *base);

/*! @} */

/*!
 * @name PLCA (Physical Layer Collision Avoidance) Control and Diagnostic
 * @{
 */

/*!
 * @brief Retrieves the current Physical Layer Collision Avoidance (PLCA) configuration.
 *
 * This function reads the current PLCA settings from the registers,
 * including node ID, node count, timers, and PLCA enable status.
 *
 * @param base TENBASET_PHY peripheral base address
 * @param config Pointer to store the current PLCA configuration
 */
void TENBASET_PHY_GetPLCAConfig(TENBASET_PHY_Type *base, tenbaset_phy_plca_config_t *config);

/*!
 * @brief Configures PLCA settings.
 *
 * @param base TENBASET_PHY peripheral base address.
 * @param config Pointer to PLCA configuration structure.
 * @retval kStatus_Success PLCA configured successfully.
 * @retval kStatus_Fail PLCA configuration error.
 */
status_t TENBASET_PHY_SetPLCAConfig(TENBASET_PHY_Type *base, const tenbaset_phy_plca_config_t *config);

/*!
 * @brief Gets PLCA status.
 *
 * @param base TENBASET_PHY peripheral base address.
 * @return PLCA node status.
 */
bool TENBASET_PHY_GetPLCAStatus(TENBASET_PHY_Type *base);

/*!
 * @brief Gets PLCA diagnostic flags.
 *
 * @param base TENBASET_PHY peripheral base address.
 * @return diagnostic flags (combination of _tenbaset_phy_plca_diag_flags).
 */
uint32_t TENBASET_PHY_GetPLCADiagnosticFlags(TENBASET_PHY_Type *base);

/*!
 * @brief Clears PLCA diagnostic flags.
 *
 * @param base TENBASET_PHY peripheral base address.
 * @param diagFlags Flags to clear (combination of _tenbaset_phy_plca_diag_flags).
 */
void TENBASET_PHY_ClearPLCADiagnosticFlags(TENBASET_PHY_Type *base, uint32_t diagFlags);

/*!
 * @brief Gets PLCA beacon counter.
 *
 * @param base TENBASET_PHY peripheral base address.
 * @return RX beacon counter value.
 */
uint16_t TENBASET_PHY_GetBeaconCounter(TENBASET_PHY_Type *base);

/*!
 * @brief Clears PLCA beacon counter.
 *
 * @param base TENBASET_PHY peripheral base address.
 */
void TENBASET_PHY_ClearBeaconCounter(TENBASET_PHY_Type *base);

/*!
 * @brief Gets PLCA transmit opportunity counter.
 *
 * @param base TENBASET_PHY peripheral base address.
 * @return Transmit opportunity counter value.
 */
uint16_t TENBASET_PHY_GetTransmitOpportunityCounter(TENBASET_PHY_Type *base);

/*!
 * @brief Clears PLCA transmit opportunity counter.
 *
 * @param base TENBASET_PHY peripheral base address.
 */
void TENBASET_PHY_ClearTransmitOpportunityCounter(TENBASET_PHY_Type *base);

/*! @} */

/*!
 * @name Physical Medium Attachment (PMA) Control
 * @{
 */

/*!
 * @brief Retrieves the current PMA configuration.
 *
 * Reads the PMA control register and populates the configuration structure.
 *
 * @param base TENBASET_PHY peripheral base address
 * @param config Pointer to store PMA configuration
 */
void TENBASET_PHY_GetPMAConfig(TENBASET_PHY_Type *base, tenbaset_phy_pma_config_t *config);

/*!
 * @brief Configures the PMA operation.
 *
 * Writes to the PMA control register to set reset, transmission,
 * and loopback modes.
 *
 * @param base TENBASET_PHY peripheral base address
 * @param config Pointer to PMA configuration
 */
void TENBASET_PHY_SetPMAConfig(TENBASET_PHY_Type *base, const tenbaset_phy_pma_config_t *config);

/*! @} */

/*!
 * @name Physical Coding Sublayer (PCS) Control and Diagnostic
 * @{
 */

/*!
 * @brief Retrieves the current PCS configuration.
 *
 * Reads the PCS control register and populates the configuration structure.
 *
 * @param base TENBASET_PHY peripheral base address
 * @param config Pointer to store PCS configuration
 */
void TENBASET_PHY_GetPCSConfig(TENBASET_PHY_Type *base, tenbaset_phy_pcs_config_t *config);

/*!
 * @brief Configures the PCS operation.
 *
 * Writes to the PCS control register to set reset and loopback modes.
 *
 * @param base TENBASET_PHY peripheral base address
 * @param config Pointer to PCS configuration
 */
void TENBASET_PHY_SetPCSConfig(TENBASET_PHY_Type *base, const tenbaset_phy_pcs_config_t *config);

/*!
 * @brief Gets PCS remote jabber counter.
 *
 * @param base TENBASET_PHY peripheral base address.
 * @return Remote jabber counter value.
 */
uint16_t TENBASET_PHY_GetRemoteJabberCounter(TENBASET_PHY_Type *base);

/*!
 * @brief Gets PCS physical collision counter.
 *
 * @param base TENBASET_PHY peripheral base address.
 * @return Physical collision counter value.
 */
uint16_t TENBASET_PHY_GetCollisionCounter(TENBASET_PHY_Type *base);

/*! @} */

/*!
 * @name Wake Configuration and Control
 * @{
 */

/*!
 * @brief Configures wake settings.
 *
 * @param base TENBASET_PHY peripheral base address.
 * @param config Pointer to wake configuration structure.
 */
void TENBASET_PHY_SetWakeConfig(TENBASET_PHY_Type *base, const tenbaset_phy_wake_config_t *config);

/*!
 * @brief Triggers a wake-forward pulse.
 *
 * This function commands the TENBASET_PHY PHY to generate a wake-forward pulse.
 *
 * @param base TENBASET_PHY peripheral base address.
 */
void TENBASET_PHY_TriggerWakeForward(TENBASET_PHY_Type *base);

/*!
 * @brief Triggers WUP sequencer transmission.
 *
 * @param base TENBASET_PHY peripheral base address.
 */
void TENBASET_PHY_TriggerWakeUp(TENBASET_PHY_Type *base);

/*!
 * @brief Aborts WUP sequencer when pending.
 *
 * @param base TENBASET_PHY peripheral base address.
 */
void TENBASET_PHY_AbortWakeUp(TENBASET_PHY_Type *base);

/*!
 * @brief Gets WUP status information.
 *
 * @param base TENBASET_PHY peripheral base address.
 * @param statusInfo Pointer to structure to store WUP status information.
 */
void TENBASET_PHY_GetWakeUpStatus(TENBASET_PHY_Type *base, tenbaset_phy_wup_status_info_t *statusInfo);

/*! @} */

/*!
 * @name Interrupt Control
 * @{
 */

/*!
 * @brief Enables TENBASET_PHY interrupts of functional events to the MCU.
 *
 * @param base TENBASET_PHY peripheral base address.
 * @param mask Interrupt mask (combination of _tenbaset_phy_interrupt_flags).
 */
void TENBASET_PHY_EnableInterrupts(TENBASET_PHY_Type *base, uint16_t mask);

/*!
 * @brief Disables TENBASET_PHY interrupts of functional events to the MCU.
 *
 * @param base TENBASET_PHY peripheral base address.
 * @param mask Interrupt mask (combination of _tenbaset_phy_interrupt_flags).
 */
void TENBASET_PHY_DisableInterrupts(TENBASET_PHY_Type *base, uint16_t mask);

/*!
 * @brief Gets interrupt status flags of functional events to the MCU.
 *
 * @param base TENBASET_PHY peripheral base address.
 * @return Interrupt status flags.
 */
uint16_t TENBASET_PHY_GetInterruptStatus(TENBASET_PHY_Type *base);

/*!
 * @brief Clears interrupt status flags of functional events to the MCU.
 *
 * @param base TENBASET_PHY peripheral base address.
 * @param mask Interrupt flags to clear.
 */
void TENBASET_PHY_ClearInterruptStatus(TENBASET_PHY_Type *base, uint16_t mask);

/*!
 * @brief Enables TENBASET_PHY interrupts of safety related events
 * to the Fault Collection and Control Unit (FCCU).
 *
 * @param base TENBASET_PHY peripheral base address.
 * @param mask Interrupt mask (combination of _tenbaset_phy_interrupt_flags).
 */
void TENBASET_PHY_EnableInterrupts2(TENBASET_PHY_Type *base, uint16_t mask);

/*!
 * @brief Disables TENBASET_PHY interrupts of safety related events
 * to the Fault Collection and Control Unit (FCCU).
 *
 * @param base TENBASET_PHY peripheral base address.
 * @param mask Interrupt mask (combination of _tenbaset_phy_interrupt_flags).
 */
void TENBASET_PHY_DisableInterrupts2(TENBASET_PHY_Type *base, uint16_t mask);

/*!
 * @brief Gets interrupt status flags of safety related events
 * to the Fault Collection and Control Unit (FCCU).
 *
 * @param base TENBASET_PHY peripheral base address.
 * @return Interrupt status flags.
 */
uint16_t TENBASET_PHY_GetInterruptStatus2(TENBASET_PHY_Type *base);

/*!
 * @brief Clears interrupt status flags of safety related events
 * to the Fault Collection and Control Unit (FCCU).
 *
 * @param base TENBASET_PHY peripheral base address.
 * @param mask Interrupt flags to clear.
 */
void TENBASET_PHY_ClearInterruptStatus2(TENBASET_PHY_Type *base, uint16_t mask);

/*! @} */

/*!
 * @name Diagnostic and Status
 * @{
 */

/*!
 * @brief Gets PHY identifier.
 *
 * @param base TENBASET_PHY peripheral base address.
 * @return OUI part of the 32-bit PHY identifier.
 */
uint32_t TENBASET_PHY_GetPhyId(TENBASET_PHY_Type *base);

/*!
 * @brief Gets version information.
 *
 * @param base TENBASET_PHY peripheral base address.
 * @param versionInfo Pointer to structure to store version information.
 */
void TENBASET_PHY_GetVersionInfo(TENBASET_PHY_Type *base, tenbaset_phy_version_info_t *versionInfo);

/*!
 * @brief Gets transceiver diagnostic flags.
 *
 * @param base TENBASET_PHY peripheral base address.
 * @return Diagnostic flags (combination of _tenbaset_phy_txc_diag_flags).
 */
uint16_t TENBASET_PHY_GetTransceiverDiagnosticFlags(TENBASET_PHY_Type *base);

/*!
 * @brief Clears transceiver diagnostic flags.
 *
 * @param base TENBASET_PHY peripheral base address.
 * @param diagFlags Flags to clear (combination of _tenbaset_phy_txc_diag_flags).
 */
void TENBASET_PHY_ClearTransceiverDiagnosticFlags(TENBASET_PHY_Type *base, uint16_t diagFlags);

/*! @} */

/*!
 * @name SMI (Serial Management Interface)
 * @{
 */

/*!
 * @brief Configures the SMI (Serial Management Interface) parameters.
 *
 * This function sets up the SMI interface configuration, including:
 * - MDIO hold time
 * - Preamble generation
 * - MDC clock frequency
 *
 * @param base TENBASET_PHY peripheral base address
 * @param config Pointer to SMI configuration structure
 * @return status_t Operation status
 *         - kStatus_Success: Configuration successful
 *         - kStatus_InvalidArgument: Invalid speed parameter
 */
status_t TENBASET_PHY_SetSMIConfig(TENBASET_PHY_Type *base, const tenbaset_phy_smi_config_t *config);

/*!
 * @brief Retrieves the current SMI status.
 *
 * Checks if the SMI is ready and optionally retrieves the current error code.
 *
 * @param base TENBASET_PHY peripheral base address
 * @param errorCode Pointer to store error code (can be NULL if error code not needed)
 * @return bool
 *         - true: SMI is ready
 *         - false: SMI is not ready
 */
bool TENBASET_PHY_GetSMIStatus(TENBASET_PHY_Type *base, tenbaset_phy_smi_error_code_t *errorCode);

/*!
 * @brief Reads a register from an external PMD transceiver via SMI.
 *
 * Performs an SMI read operation with timeout handling.
 *
 * @param base TENBASET_PHY peripheral base address
 * @param phyAddr PHY address of PMD transceiver
 * @param regAddr Register address to read
 * @param data Pointer to store the read register value
 * @return status_t Operation status
 *         - kStatus_Success: Read successful
 *         - kStatus_Timeout: SMI not ready within timeout period
 */
status_t TENBASET_PHY_SMIRead(TENBASET_PHY_Type *base, uint8_t phyAddr, uint8_t regAddr, uint16_t *data);

/*!
 * @brief Writes a register to an external PMD transceiver via SMI.
 *
 * Performs an SMI write operation with timeout handling.
 *
 * @param base TENBASET_PHY peripheral base address
 * @param phyAddr PHY address of PMD transceiver
 * @param regAddr Register address to write
 * @param data Value to write to the register
 * @return status_t Operation status
 *         - kStatus_Success: Write successful
 *         - kStatus_Timeout: SMI not ready within timeout period
 */
status_t TENBASET_PHY_SMIWrite(TENBASET_PHY_Type *base, uint8_t phyAddr, uint8_t regAddr, uint16_t data);

/*! @} */

#if defined(__cplusplus)
}
#endif

/*! @} */

#endif /* FSL_TENBASET_PHY_H_ */
