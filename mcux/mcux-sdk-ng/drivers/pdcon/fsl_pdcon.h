/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_PDCON_H
#define FSL_PDCON_H

#include "fsl_common.h"

/*!
 * @addtogroup pdcon
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*@{*/
/*! @brief pdcon driver version 2.1.0. */
#define FSL_PDCON_DRIVER_VERSION (MAKE_VERSION(2, 1, 0))
/*@}*/

/*!
 * @brief Max loops to wait for PDCON to stop being busy
 *
 * If defined as 0, the driver will wait until completion.
 */
#ifndef PDCON_BUSY_TIMEOUT
#ifdef CONFIG_PDCON_BUSY_TIMEOUT
#define PDCON_BUSY_TIMEOUT CONFIG_PDCON_BUSY_TIMEOUT
#else
#define PDCON_BUSY_TIMEOUT 0U
#endif
#endif

/*!
 * @brief PDCON power domain event/state encoding.
 *
 * Unified 2-bit encoding for configuration and events.
 */
typedef enum _pdcon_event
{
    kPDCON_EventNoneOrActive = 0U, /*!< Active (config) / No event (status). */
    kPDCON_EventRetention    = 1U, /*!< Retention. */
    kPDCON_EventPowerOff     = 2U, /*!< Power-off. */
} pdcon_event_t;

/*!
 * @brief PDCON handshake mask.
 *
 * Handshake mask must be non-zero.
 */
typedef enum _pdcon_handshake_mask
{
    kPDCON_HandshakeNone  = 0x0U, /*!< No handshake (invalid). */
    kPDCON_HandshakeUnit0 = 0x1U, /*!< Handshake with unit 0. */
    kPDCON_HandshakeUnit1 = 0x2U, /*!< Handshake with unit 1. */
    kPDCON_HandshakeUnit2 = 0x4U, /*!< Handshake with unit 2. */
    kPDCON_HandshakeAll   = 0x7U, /*!< Handshake with all units. */
} pdcon_handshake_mask_t;

/*!
 * @brief PDCON access control configuration.
 */
typedef struct _pdcon_access_ctrl
{
    bool enableNonSecure; /*!< Enable non-secure access. */
    bool enableUserMode;  /*!< Enable user mode access. */
    uint8_t domainId;     /*!< Domain ID. */
    bool lock;            /*!< Lock the access control settings. */
} pdcon_access_ctrl_t;

/*!
 * @brief PDCON trigger capability configuration.
 */
typedef struct _pdcon_trigger_config
{
    uint8_t swEnableMask; /*!< Software trigger enable mask. Bit n enables SW trigger for domain n. */
    uint8_t hwEnableMask; /*!< Hardware trigger enable mask. Bit n enables HW trigger for domain n. */
    bool lock;            /*!< Lock the trigger configuration. */
} pdcon_trigger_config_t;

/*!
 * @brief PDCON domain configuration.
 *
 * Target events for Run/Sleep planes.
 */
typedef struct _pdcon_domain_cfg
{
    uint8_t       domainId;      /*!< Power domain index (0–5). */
    pdcon_event_t activeEvent;   /*!< Event in active mode. */
    pdcon_event_t lowPowerEvent; /*!< Event in low power modes. */
} pdcon_domain_cfg_t;

/*!
 * @brief PDCON module configuration.
 */
typedef struct _pdcon_config
{
    pdcon_access_ctrl_t accessCtrl; /*!< Access control configuration. */
    pdcon_trigger_config_t trigger; /*!< Trigger capability configuration. */
} pdcon_config_t;

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @name Initialization
 * @{
 */

/*!
 * @brief Gets the PDCON version ID.
 *
 * @param base PDCON peripheral base address.
 * @return Version ID of the PDCON module.
 */
uint32_t PDCON_GetVersionID(PDCON_Type *base);

/*!
 * @brief Initializes the PDCON module.
 *
 * This function initializes the PDCON module with the configuration provided.
 *
 * @note In default, after POR, all handshaked selections are enabled for each power domain.
 *
 * @param base PDCON peripheral base address.
 * @param config Pointer to the configuration structure, @ref pdcon_config_t.
 *
 * @retval kStatus_Success Initialization successful.
 * @retval kStatus_ReadOnly Access control or trigger configuration is locked.
 */
status_t PDCON_Init(PDCON_Type *base, const pdcon_config_t *config);

/*! @} */

/*!
 * @name Access Control and Trigger Configuration
 * @{
 */

/*!
 * @brief Sets the access control configuration.
 *
 * @param base PDCON peripheral base address.
 * @param acc Pointer to the access control configuration, @ref pdcon_access_ctrl_t.
 *
 * @retval kStatus_Success Access control configuration set successfully.
 * @retval kStatus_ReadOnly Access control is locked and cannot be modified.
 */
status_t PDCON_SetAccessControl(PDCON_Type *base, const pdcon_access_ctrl_t *acc);

/*!
 * @brief Unlocks the access control configuration.
 *
 * @param base PDCON peripheral base address.
 */
static inline void PDCON_UnlockAccessControl(PDCON_Type *base)
{
    base->ACCCTRL &= ~PDCON_ACCCTRL_LOCK_MASK;
}

/*!
 * @brief Sets the trigger configuration.
 *
 * @param base PDCON peripheral base address.
 * @param cfg Pointer to the trigger configuration, @ref pdcon_trigger_config_t.
 *
 * @retval kStatus_Success Trigger configuration set successfully.
 * @retval kStatus_ReadOnly Trigger configuration is locked and cannot be modified.
 */
status_t PDCON_SetTriggerConfig(PDCON_Type *base, const pdcon_trigger_config_t *cfg);

/*!
 * @brief Unlocks the trigger configuration.
 *
 * @param base PDCON peripheral base address.
 */
static inline void PDCON_UnlockTriggerConfig(PDCON_Type *base)
{
    base->MDCTRL &= ~PDCON_MDCTRL_LOCK_MASK;
}

/*!
 * @brief Enables or disables hardware trigger for a single power domain.
 *
 * Read-modify-write on MDCTRL[5:0] (HW enable mask).
 *
 * @param base   PDCON peripheral base address.
 * @param domain Power domain index (0–5).
 * @param enable true = enable HW trigger; false = disable.
 */
static inline void PDCON_EnableDomainHwTrigger(PDCON_Type *base, uint8_t domain, bool enable)
{
    uint32_t bit = (1UL << (uint32_t)domain) << PDCON_MDCTRL_HW_SHIFT;
    if (enable)
    {
        base->MDCTRL |= bit;
    }
    else
    {
        base->MDCTRL &= ~bit;
    }
}

/*!
 * @brief Enables or disables software trigger for a single power domain.
 *
 * Read-modify-write on MDCTRL[21:16] (SW enable mask).
 * Must be enabled before calling PDCON_SoftwareTrigger() for a domain.
 *
 * @param base   PDCON peripheral base address.
 * @param domain Power domain index (0–5).
 * @param enable true = enable SW trigger; false = disable.
 */
static inline void PDCON_EnableDomainSwTrigger(PDCON_Type *base, uint8_t domain, bool enable)
{
    uint32_t bit = (1UL << (uint32_t)domain) << PDCON_MDCTRL_SW_SHIFT;
    if (enable)
    {
        base->MDCTRL |= bit;
    }
    else
    {
        base->MDCTRL &= ~bit;
    }
}

/*! @} */

/*!
 * @name Handshake and Warm Reset Configuration
 * @{
 */

/*!
 * @brief Sets the handshake configuration for a power domain.
 *
 * @param base     PDCON peripheral base address.
 * @param domainId Power domain index (0–5).
 * @param mask     Handshake mask, see @ref pdcon_handshake_mask_t.
 */
void PDCON_SetHandshake(PDCON_Type *base, uint8_t domainId, pdcon_handshake_mask_t mask);

/*!
 * @brief Sets the warm reset postpone cycles for a power domain.
 *
 * @param base           PDCON peripheral base address.
 * @param domainId       Power domain index (0–5).
 * @param postponeCycles Number of cycles to postpone warm reset.
 */
void PDCON_SetWarmResetPostpone(PDCON_Type *base, uint8_t domainId, uint32_t postponeCycles);

/*! @} */

/*!
 * @name Power Mode Configuration
 * @{
 */

/*!
 * @brief Sets the power domain event in active mode.
 *
 * This function configures the power domain behavior in active mode.
 *
 * @param base     PDCON peripheral base address.
 * @param domainId Power domain index. Only 3–5 are valid (domains 0–2 have no PDRUNCFG field).
 * @param event    Power event. See @ref pdcon_event_t.
 *
 * @retval kStatus_Success Power domain event set successfully.
 * @retval kStatus_InvalidArgument Invalid domain (only domains 3-5 are supported).
 */
status_t PDCON_SetEventInActiveMode(PDCON_Type *base, uint8_t domainId, pdcon_event_t event);

/*!
 * @brief Sets the power domain event in low power modes.
 *
 * This function configures the power domain behavior in low power modes.
 *
 * @param base     PDCON peripheral base address.
 * @param domainId Power domain index. Only 1–5 are valid (domain 0 has no PDSLPCFG field).
 * @param event    Power event. See @ref pdcon_event_t.
 *
 * @retval kStatus_Success Power domain event set successfully.
 * @retval kStatus_InvalidArgument Invalid domain (only domains 1-5 are supported).
 */
status_t PDCON_SetEventInLowPowerModes(PDCON_Type *base, uint8_t domainId, pdcon_event_t event);

/*!
 * @brief Sets the power domain event configuration for both active and low power modes.
 *
 * This function configures the power domain behavior for both active/run mode and
 * low power/sleep mode in a single call.
 *
 * @param base     PDCON peripheral base address.
 * @param eventCfg Pointer to the domain event configuration. See @ref pdcon_domain_cfg_t.
 * @retval kStatus_Success Power domain events set successfully for both modes.
 * @retval kStatus_InvalidArgument Invalid domain (see limitations for each mode).
 *
 * @note Active mode configuration only supports domains 3-5.
 * @note Low power mode configuration only supports domains 1-5.
 */
status_t PDCON_SetPowerDomainEventCfg(PDCON_Type *base, const pdcon_domain_cfg_t *eventCfg);

/*! @} */

/*!
 * @name Trigger and Status
 * @{
 */

/*!
 * @brief Triggers a software-initiated power domain transition.
 *
 * This function triggers a software-initiated power domain transition.
 * The function waits for the domain to be idle before triggering and waits for completion.
 *
 * @note If CONFIG_PDCON_BUSY_TIMEOUT is defined, the function will timeout after the specified cycles.
 *
 * @param base     PDCON peripheral base address.
 * @param domainId Power domain index (0–5).
 *
 * @retval kStatus_Success Software trigger completed successfully.
 * @retval kStatus_Timeout Timeout occurred while waiting for domain to be idle or transition to complete (only if
 * PDCON_BUSY_TIMEOUT is defined).
 */
status_t PDCON_SoftwareTrigger(PDCON_Type *base, uint8_t domainId);

/*!
 * @brief Checks if a power domain is busy.
 *
 * @param base     PDCON peripheral base address.
 * @param domainId Power domain index (0–5).
 * @return true if the domain is busy, false otherwise.
 */
bool PDCON_IsDomainBusy(PDCON_Type *base, uint8_t domainId);

/*!
 * @brief Gets the current state of a power domain.
 *
 * @param base     PDCON peripheral base address.
 * @param domainId Power domain index (0–5).
 * @return Current state of the power domain. See @ref pdcon_event_t.
 */
pdcon_event_t PDCON_GetDomainState(PDCON_Type *base, uint8_t domainId);

/*!
 * @brief Gets and optionally clears the event flag for a power domain.
 *
 * @param base     PDCON peripheral base address.
 * @param domainId Power domain index (0–5).
 * @param clear    true to clear the event flag after reading, false to only read.
 * @return true if the event flag was pending; false if no event was pending.
 */
bool PDCON_GetAndClearEvent(PDCON_Type *base, uint8_t domainId, bool clear);

/*! @} */

/*!
 * @name Miscellaneous Control
 * @{
 */

/*!
 * @brief Enable or disable the PDCON functional clock (MISCCTRL.FCEN).
 *
 * MUST be called (enable=true) before any PDCON register access. May be
 * disabled to save power when PDCON is fully quiescent.
 *
 * @param base   PDCON peripheral base address.
 * @param enable true = enable functional clock; false = gate it.
 */
static inline void PDCON_EnableFunctionClock(PDCON_Type *base, bool enable)
{
    if (enable)
    {
        base->MISCCTRL |= PDCON_MISCCTRL_FCEN_MASK;
    }
    else
    {
        base->MISCCTRL &= ~PDCON_MISCCTRL_FCEN_MASK;
    }
}

/*!
 * @brief Select the observe/debug mux output (MISCCTRL.SEL).
 *
 * Routes internal PDCON signals from the specified domain to the observe bus.
 * For debug and characterization use only — has no effect on normal operation.
 *
 * @param base     PDCON peripheral base address.
 * @param domainId Domain index to observe (0–5).
 */
static inline void PDCON_SetObserveDomain(PDCON_Type *base, uint8_t domainId)
{
    base->MISCCTRL = (base->MISCCTRL & ~PDCON_MISCCTRL_SEL_MASK) |
                     PDCON_MISCCTRL_SEL(domainId);
}

/*! @} */

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */
#endif /* FSL_PDCON_H */
