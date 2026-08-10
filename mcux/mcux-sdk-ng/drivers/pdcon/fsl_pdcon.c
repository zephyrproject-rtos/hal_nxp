/*
 * Copyright 2025-2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_pdcon.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.pdcon"
#endif

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/

/*!
 * brief Gets the PDCON version ID.
 *
 * param base PDCON peripheral base address.
 * return Version ID of the PDCON module.
 */
uint32_t PDCON_GetVersionID(PDCON_Type *base)
{
    assert(base != NULL);
    return base->VERID;
}

/*!
 * brief Initializes the PDCON module.
 *
 * This function initializes the PDCON module with the configuration provided.
 *
 * param base PDCON peripheral base address.
 * param config Pointer to the configuration structure. See @ref pdcon_config_t.
 * retval kStatus_Success Initialization successful.
 * retval kStatus_ReadOnly Access control or trigger configuration is locked.
 */
status_t PDCON_Init(PDCON_Type *base, const pdcon_config_t *config)
{
    assert(base != NULL);
    assert(config != NULL);

    /* Apply access control configuration; return immediately on lock error. */
    status_t status = PDCON_SetAccessControl(base, &config->accessCtrl);
    if (status != kStatus_Success)
    {
        return status;
    }

    /* Apply trigger (mode-control) configuration; return on lock error. */
    status = PDCON_SetTriggerConfig(base, &config->trigger);
    if (status != kStatus_Success)
    {
        return status;
    }

    return kStatus_Success;
}

/*!
 * brief Sets the access control configuration.
 *
 * param base PDCON peripheral base address.
 * param acc Pointer to the access control configuration. See @ref pdcon_access_ctrl_t.
 * retval kStatus_Success Access control configuration set successfully.
 * retval kStatus_ReadOnly Access control is locked and cannot be modified.
 */
status_t PDCON_SetAccessControl(PDCON_Type *base, const pdcon_access_ctrl_t *acc)
{
    assert(base != NULL);
    assert(acc != NULL);

    /* Refuse modification if register is locked. */
    if ((base->ACCCTRL & PDCON_ACCCTRL_LOCK_MASK) != 0U)
    {
        return kStatus_ReadOnly;
    }

    /* Assemble ACCCTRL: domain ID, user-mode enable, non-secure enable, optional lock. */
    uint32_t value = 0U;
    value |= PDCON_ACCCTRL_DID((uint32_t)acc->domainId & 0xFU);
    value |= PDCON_ACCCTRL_UM(acc->enableUserMode ? 1U : 0U);
    value |= PDCON_ACCCTRL_NSM(acc->enableNonSecure ? 1U : 0U);
    if (acc->lock)
    {
        value |= PDCON_ACCCTRL_LOCK(1U);
    }

    base->ACCCTRL = value;
    return kStatus_Success;
}

/*!
 * brief Sets the trigger configuration.
 *
 * param base PDCON peripheral base address.
 * param cfg Pointer to the trigger configuration. See @ref pdcon_trigger_config_t.
 * retval kStatus_Success Trigger configuration set successfully.
 * retval kStatus_ReadOnly Trigger configuration is locked and cannot be modified.
 */
status_t PDCON_SetTriggerConfig(PDCON_Type *base, const pdcon_trigger_config_t *cfg)
{
    assert(base != NULL);
    assert(cfg != NULL);

    /* Refuse modification if trigger register is locked. */
    if ((base->MDCTRL & PDCON_MDCTRL_LOCK_MASK) != 0U)
    {
        return kStatus_ReadOnly;
    }

    /* Assemble MDCTRL: SW trigger enable mask, HW trigger enable mask, optional lock. */
    uint32_t value = 0U;
    value |= PDCON_MDCTRL_SW((uint32_t)cfg->swEnableMask & 0x3FU);
    value |= PDCON_MDCTRL_HW((uint32_t)cfg->hwEnableMask & 0x3FU);
    if (cfg->lock)
    {
        value |= PDCON_MDCTRL_LOCK(1U);
    }

    base->MDCTRL = value;
    return kStatus_Success;
}

/*!
 * brief Sets the handshake configuration for a power domain.
 *
 * param base     PDCON peripheral base address.
 * param domainId Power domain index (0–5).
 * param mask     Handshake mask. See "pdcon_handshake_mask_t".
 */
void PDCON_SetHandshake(PDCON_Type *base, uint8_t domainId, pdcon_handshake_mask_t mask)
{
    assert(base != NULL);

    uint32_t val = (uint32_t)mask & PDCON_HSKEN0_PD0_HSK_MASK;

    if (domainId <= 3U)
    {
        uint32_t shift = (uint32_t)domainId * PDCON_HSKEN0_PD1_HSK_SHIFT; /* PD0=0, PD1=8, PD2=16, PD3=24 */
        uint32_t reg   = base->HSKEN0;
        reg &= ~((uint32_t)PDCON_HSKEN0_PD0_HSK_MASK << shift);
        reg |= (val << shift);
        base->HSKEN0 = reg;
    }
    else
    {
        uint32_t shift = ((uint32_t)domainId - 4U) * PDCON_HSKEN0_PD1_HSK_SHIFT; /* PD4=0, PD5=8 */
        uint32_t reg   = base->HSKEN1;
        reg &= ~((uint32_t)PDCON_HSKEN0_PD0_HSK_MASK << shift);
        reg |= (val << shift);
        base->HSKEN1 = reg;
    }
}

/*!
 * brief Sets the warm reset postpone cycles for a power domain.
 *
 * param base           PDCON peripheral base address.
 * param domainId       Power domain index (0–5).
 * param postponeCycles Number of cycles to postpone warm reset.
 */
void PDCON_SetWarmResetPostpone(PDCON_Type *base, uint8_t domainId, uint32_t postponeCycles)
{
    assert(base != NULL);

    if (domainId <= 3U)
    {
        uint32_t shift = (uint32_t)domainId * PDCON_WRPSP0_PSPD1_SHIFT; /* bytes for PD0..PD3 */
        base->WRPSP0   = (base->WRPSP0 & ~((uint32_t)0xFFU << shift)) | ((postponeCycles & 0xFFU) << shift);
    }
    else
    {
        uint32_t shift = ((uint32_t)domainId - 4U) * 8U; /* bytes for PD4..PD5 */
        base->WRPSP1   = (base->WRPSP1 & ~((uint32_t)0xFFU << shift)) | ((postponeCycles & 0xFFU) << shift);
    }
}

/*!
 * brief Sets the power domain event in active mode.
 *
 * This function configures the power domain behavior in active/run mode (PDRUNCFG).
 * Note: Only domains 3..5 have fields in PDRUNCFG on this SoC.
 *
 * param base     PDCON peripheral base address.
 * param domainId Power domain index. Only 3–5 are valid.
 * param event    Power event. See @ref pdcon_event_t.
 * retval kStatus_Success Power domain event set successfully.
 * retval kStatus_InvalidArgument Invalid domain (only domains 3-5 are supported).
 */
status_t PDCON_SetEventInActiveMode(PDCON_Type *base, uint8_t domainId, pdcon_event_t event)
{
    assert(base != NULL);

    status_t status;
    /* Map domainId to the corresponding PDRUNCFG field and write the event value. */
    switch (domainId)
    {
        case 3U:
            base->PDRUNCFG = (base->PDRUNCFG & ~PDCON_PDRUNCFG_PDCFG3_MASK) | PDCON_PDRUNCFG_PDCFG3(event);
            status = kStatus_Success;
            break;

        case 4U:
            base->PDRUNCFG = (base->PDRUNCFG & ~PDCON_PDRUNCFG_PDCFG4_MASK) | PDCON_PDRUNCFG_PDCFG4(event);
            status = kStatus_Success;
            break;

        case 5U:
            base->PDRUNCFG = (base->PDRUNCFG & ~PDCON_PDRUNCFG_PDCFG5_MASK) | PDCON_PDRUNCFG_PDCFG5(event);
            status = kStatus_Success;
            break;

        default:
            status = kStatus_InvalidArgument; /* PD0..PD2 have no fields in PDRUNCFG on this SoC */
            break;
    }
    return status;
}

/*!
 * brief Sets the power domain event in low power modes.
 *
 * This function configures the power domain behavior in low power/sleep modes (PDSLPCFG).
 * Note: Only domains 1..5 have fields in PDSLPCFG on this SoC.
 *
 * param base     PDCON peripheral base address.
 * param domainId Power domain index. Only 1–5 are valid.
 * param event    Power event. See @ref pdcon_event_t.
 * retval kStatus_Success Power domain event set successfully.
 * retval kStatus_InvalidArgument Invalid domain (only domains 1-5 are supported).
 */
status_t PDCON_SetEventInLowPowerModes(PDCON_Type *base, uint8_t domainId, pdcon_event_t event)
{
    assert(base != NULL);

    status_t status;
    /* Map domainId to the corresponding PDSLPCFG field and write the event value.
     * Domains 1-5 map to PDCFG1-PDCFG5 fields respectively; each is 2 bits wide.
     * A read-modify-write pattern preserves the adjacent domain fields.
     * Domain 0 has no PDSLPCFG field and is rejected by the default case. */
    switch (domainId)
    {
        case 1U:
            base->PDSLPCFG = (base->PDSLPCFG & ~PDCON_PDSLPCFG_PDCFG1_MASK) | PDCON_PDSLPCFG_PDCFG1(event);
            status = kStatus_Success;
            break;

        case 2U:
            base->PDSLPCFG = (base->PDSLPCFG & ~PDCON_PDSLPCFG_PDCFG2_MASK) | PDCON_PDSLPCFG_PDCFG2(event);
            status = kStatus_Success;
            break;

        case 3U:
            base->PDSLPCFG = (base->PDSLPCFG & ~PDCON_PDSLPCFG_PDCFG3_MASK) | PDCON_PDSLPCFG_PDCFG3(event);
            status = kStatus_Success;
            break;

        case 4U:
            base->PDSLPCFG = (base->PDSLPCFG & ~PDCON_PDSLPCFG_PDCFG4_MASK) | PDCON_PDSLPCFG_PDCFG4(event);
            status = kStatus_Success;
            break;

        case 5U:
            base->PDSLPCFG = (base->PDSLPCFG & ~PDCON_PDSLPCFG_PDCFG5_MASK) | PDCON_PDSLPCFG_PDCFG5(event);
            status = kStatus_Success;
            break;

        default:
            status = kStatus_InvalidArgument; /* PD0 has no field in PDSLPCFG on this SoC */
            break;
    }
    return status;
}

/*!
 * brief Sets the power domain event configuration for both active and low power modes.
 *
 * param base     PDCON peripheral base address.
 * param eventCfg Pointer to the domain event configuration. See @ref pdcon_domain_cfg_t.
 * retval kStatus_Success Power domain events set successfully for both modes.
 * retval kStatus_InvalidArgument Invalid domain (see limitations for each mode).
 *
 * note Active mode configuration only supports domains 3-5.
 * note Low power mode configuration only supports domains 1-5.
 */
status_t PDCON_SetPowerDomainEventCfg(PDCON_Type *base, const pdcon_domain_cfg_t *eventCfg)
{
    assert(base != NULL);
    assert(eventCfg != NULL);

    status_t status;

    /* Set the active mode event; proceed to low power mode only on success. */
    status = PDCON_SetEventInActiveMode(base, eventCfg->domainId, eventCfg->activeEvent);
    if (status == kStatus_Success)
    {
        /* Set the low power mode event for the same domain. */
        status = PDCON_SetEventInLowPowerModes(base, eventCfg->domainId, eventCfg->lowPowerEvent);
    }

    return status;
}

/*!
 * brief Triggers a software-initiated power domain transition.
 *
 * This function triggers a software-initiated power domain transition.
 * The function waits for the domain to be idle before triggering and waits for completion.
 * If CONFIG_PDCON_BUSY_TIMEOUT is defined, the function will timeout after the specified cycles.
 *
 * param base     PDCON peripheral base address.
 * param domainId Power domain index (0–5).
 * retval kStatus_Success Software trigger completed successfully.
 * retval kStatus_Timeout Timeout occurred while waiting for domain to be idle or transition to complete (only if
 * PDCON_BUSY_TIMEOUT is defined).
 */
status_t PDCON_SoftwareTrigger(PDCON_Type *base, uint8_t domainId)
{
    assert(base != NULL);

    /* Wait idle before trigger */
#if PDCON_BUSY_TIMEOUT
    uint32_t timeout = PDCON_BUSY_TIMEOUT;
#endif

    while (((base->PDST >> (PDCON_PDST_PDB0_SHIFT + (uint32_t)domainId)) & 0x1U) != 0U)
    {
#if PDCON_BUSY_TIMEOUT
        if ((--timeout) == 0U)
        {
            return kStatus_Timeout;
        }
#endif
    }

    /* Issue SW trigger: SWTRG[n] = 1 (self-clearing) */
    base->SWCTRL = PDCON_SWCTRL_SWTRG((uint32_t)(1UL << (uint32_t)domainId));

    /* Wait until transition completes (busy -> 0) */
#if PDCON_BUSY_TIMEOUT
    timeout = PDCON_BUSY_TIMEOUT;
#endif
    while (((base->PDST >> (PDCON_PDST_PDB0_SHIFT + (uint32_t)domainId)) & 0x1U) != 0U)
    {
#if PDCON_BUSY_TIMEOUT
        if ((--timeout) == 0U)
        {
            return kStatus_Timeout;
        }
#endif
    }

    return kStatus_Success;
}

/*!
 * brief Checks if a power domain is busy.
 *
 * param base     PDCON peripheral base address.
 * param domainId Power domain index (0–5).
 * return true if the domain is busy, false otherwise.
 */
bool PDCON_IsDomainBusy(PDCON_Type *base, uint8_t domainId)
{
    assert(base != NULL);

    uint32_t bit = (base->PDST >> (PDCON_PDST_PDB0_SHIFT + (uint32_t)domainId)) & 0x1U;
    return (bool)(bit != 0U);
}

/*!
 * brief Gets the current state of a power domain.
 *
 * param base     PDCON peripheral base address.
 * param domainId Power domain index (0–5).
 * return Current state of the power domain. See "pdcon_event_t".
 */
pdcon_event_t PDCON_GetDomainState(PDCON_Type *base, uint8_t domainId)
{
    assert(base != NULL);

    uint32_t shift = (uint32_t)domainId * 2U; /* PDS0@0, PDS1@2, ... */
    uint32_t value = (base->PDST >> shift) & 0x3U;
    return (pdcon_event_t)value;
}

/*!
 * brief Gets and optionally clears the event flag for a power domain.
 *
 * param base     PDCON peripheral base address.
 * param domainId Power domain index (0–5).
 * param clear    true to clear the event flag after reading, false to only read.
 * return true if the event flag was pending; false if no event was pending.
 */
bool PDCON_GetAndClearEvent(PDCON_Type *base, uint8_t domainId, bool clear)
{
    assert(base != NULL);
    assert(domainId <= 5U);

    uint32_t shift   = (uint32_t)domainId * 2U; /* PEF0@0, PEF1@2, ... */
    uint32_t mask    = ((uint32_t)0x3U << shift);
    uint32_t rawBits = (base->PDSEF & mask) >> shift;
    bool pending     = (rawBits != 0U);

    if (clear && pending)
    {
        base->PDSEF = mask; /* W1C: write 1s to the two event-flag bits of this domain */
    }

    return pending;
}
