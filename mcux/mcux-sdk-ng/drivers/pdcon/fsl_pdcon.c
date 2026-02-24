/*
 * Copyright 2025 NXP
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

    status_t status = PDCON_SetAccessControl(base, &config->accessCtrl);
    if (status != kStatus_Success)
    {
        return status;
    }

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

    if ((base->ACCCTRL & PDCON_ACCCTRL_LOCK_MASK) != 0U)
    {
        return kStatus_ReadOnly;
    }

    uint32_t value = 0U;
    value |= PDCON_ACCCTRL_DID(acc->domainId & 0xFU);
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

    if ((base->MDCTRL & PDCON_MDCTRL_LOCK_MASK) != 0U)
    {
        return kStatus_ReadOnly;
    }

    uint32_t value = 0U;
    value |= PDCON_MDCTRL_SW(cfg->swEnableMask & 0x3FU);
    value |= PDCON_MDCTRL_HW(cfg->hwEnableMask & 0x3FU);
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
 * param base PDCON peripheral base address.
 * param domain Power domain. See "pdcon_domain_t".
 * param mask Handshake mask. See "pdcon_handshake_mask_t".
 */
void PDCON_SetHandshake(PDCON_Type *base, pdcon_domain_t domain, pdcon_handshake_mask_t mask)
{
    /* Extract handshake mask value and ensure it fits within the PD0 handshake mask field */
    uint32_t val = (uint32_t)mask & PDCON_HSKEN0_PD0_HSK_MASK;

    if (domain <= kPDCON_Domain3)
    {
        uint32_t shift = ((uint32_t)domain * PDCON_HSKEN0_PD1_HSK_SHIFT); /* PD0=0, PD1=8, PD2=16, PD3=24 */
        uint32_t reg   = base->HSKEN0;
        reg &= ~(PDCON_HSKEN0_PD0_HSK_MASK << shift);
        reg |= (val << shift);
        base->HSKEN0 = reg;
    }
    else
    {
        uint32_t shift = (((uint32_t)domain - 4U) * PDCON_HSKEN0_PD1_HSK_SHIFT); /* PD4=0, PD5=8 */
        uint32_t reg   = base->HSKEN1;
        reg &= ~(0x7U << shift);
        reg |= (val << shift);
        base->HSKEN1 = reg;
    }
}
/*!
 * brief Sets the warm reset postpone cycles for a power domain.
 *
 * param base PDCON peripheral base address.
 * param domain Power domain. See "pdcon_domain_t".
 * param postponeCycles Number of cycles to postpone warm reset.
 */
void PDCON_SetWarmResetPostpone(PDCON_Type *base, pdcon_domain_t domain, uint8_t postponeCycles)
{
    assert(base != NULL);

    if (domain <= kPDCON_Domain3)
    {
        uint32_t shift = (uint32_t)domain * PDCON_WRPSP0_PSPD1_SHIFT; /* bytes for PD0..PD3 */
        base->WRPSP0   = (base->WRPSP0 & ~(0xFFU << shift)) | ((uint32_t)postponeCycles << shift);
    }
    else
    {
        uint32_t shift = ((uint32_t)domain - 4U) * 8U; /* bytes for PD4..PD5 */
        base->WRPSP1   = (base->WRPSP1 & ~(0xFFU << shift)) | ((uint32_t)postponeCycles << shift);
    }
}
/*!
 * brief Sets the power domain event in active mode.
 *
 * This function configures the power domain behavior in active/run mode (PDRUNCFG).
 * Note: Only domains 3..5 have fields in PDRUNCFG on this SoC.
 *
 * param base PDCON peripheral base address.
 * param domain Power domain. See @ref pdcon_domain_t.
 * param event Power event. See @ref pdcon_event_t.
 * retval kStatus_Success Power domain event set successfully.
 * retval kStatus_InvalidArgument Invalid domain (only domains 3-5 are supported).
 */
status_t PDCON_SetEventInActiveMode(PDCON_Type *base, pdcon_domain_t domain, pdcon_event_t event)
{
    assert(base != NULL);

    switch (domain)
    {
        case kPDCON_Domain3:
            base->PDRUNCFG = (base->PDRUNCFG & ~PDCON_PDRUNCFG_PDCFG3_MASK) | PDCON_PDRUNCFG_PDCFG3(event);
            return kStatus_Success;

        case kPDCON_Domain4:
            base->PDRUNCFG = (base->PDRUNCFG & ~PDCON_PDRUNCFG_PDCFG4_MASK) | PDCON_PDRUNCFG_PDCFG4(event);
            return kStatus_Success;

        case kPDCON_Domain5:
            base->PDRUNCFG = (base->PDRUNCFG & ~PDCON_PDRUNCFG_PDCFG5_MASK) | PDCON_PDRUNCFG_PDCFG5(event);
            return kStatus_Success;

        default:
            return kStatus_InvalidArgument; /* PD0..PD2 have no fields in PDRUNCFG on this SoC */
    }
}

/*!
 * brief Sets the power domain event in low power modes.
 *
 * This function configures the power domain behavior in low power/sleep modes (PDSLPCFG).
 * Note: Domains 0..5 have fields in PDSLPCFG on this SoC.
 *
 * param base PDCON peripheral base address.
 * param domain Power domain. See @ref pdcon_domain_t.
 * param event Power event. See @ref pdcon_event_t.
 * retval kStatus_Success Power domain event set successfully.
 * retval kStatus_InvalidArgument Invalid domain (only domains 1-5 are supported).
 */
status_t PDCON_SetEventInLowPowerModes(PDCON_Type *base, pdcon_domain_t domain, pdcon_event_t event)
{
    assert(base != NULL);

    switch (domain)
    {
        case kPDCON_Domain1:
            base->PDSLPCFG = (base->PDSLPCFG & ~PDCON_PDSLPCFG_PDCFG1_MASK) | PDCON_PDSLPCFG_PDCFG1(event);
            return kStatus_Success;

        case kPDCON_Domain2:
            base->PDSLPCFG = (base->PDSLPCFG & ~PDCON_PDSLPCFG_PDCFG2_MASK) | PDCON_PDSLPCFG_PDCFG2(event);
            return kStatus_Success;

        case kPDCON_Domain3:
            base->PDSLPCFG = (base->PDSLPCFG & ~PDCON_PDSLPCFG_PDCFG3_MASK) | PDCON_PDSLPCFG_PDCFG3(event);
            return kStatus_Success;

        case kPDCON_Domain4:
            base->PDSLPCFG = (base->PDSLPCFG & ~PDCON_PDSLPCFG_PDCFG4_MASK) | PDCON_PDSLPCFG_PDCFG4(event);
            return kStatus_Success;

        case kPDCON_Domain5:
            base->PDSLPCFG = (base->PDSLPCFG & ~PDCON_PDSLPCFG_PDCFG5_MASK) | PDCON_PDSLPCFG_PDCFG5(event);
            return kStatus_Success;

        default:
            return kStatus_InvalidArgument;
    }
}
/*!
 * brief Sets the power domain event configuration for both active and low power modes.
 *
 * This function configures the power domain behavior for both active/run mode and
 * low power/sleep mode in a single call.
 *
 * param base PDCON peripheral base address.
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

    status = PDCON_SetEventInActiveMode(base, eventCfg->domain, eventCfg->activeEvent);
    if (status == kStatus_Success)
    {
        status = PDCON_SetEventInLowPowerModes(base, eventCfg->domain, eventCfg->lowPowerEvent);
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
 * param base PDCON peripheral base address.
 * param domain Power domain. See @ref pdcon_domain_t.
 * retval kStatus_Success Software trigger completed successfully.
 * retval kStatus_Timeout Timeout occurred while waiting for domain to be idle or transition to complete (only if
 * PDCON_BUSY_TIMEOUT is defined).
 */
status_t PDCON_SoftwareTrigger(PDCON_Type *base, pdcon_domain_t domain)
{
    assert(base != NULL);

    /* Wait idle before trigger */
#if PDCON_BUSY_TIMEOUT
    uint32_t timeout = PDCON_BUSY_TIMEOUT;
#endif

    while (((base->PDST >> (PDCON_PDST_PDB0_SHIFT + (uint32_t)domain)) & 0x1U) != 0U)
    {
#if PDCON_BUSY_TIMEOUT
        if ((--timeout) == 0U)
        {
            return kStatus_Timeout;
        }
#endif
    }

    /* Issue SW trigger: SWTRG[n] = 1 (self-clearing) */
    base->SWCTRL = PDCON_SWCTRL_SWTRG(1U << (uint32_t)domain);

    /* Wait until transition completes (busy -> 0) */
    while (((base->PDST >> (PDCON_PDST_PDB0_SHIFT + (uint32_t)domain)) & 0x1U) != 0U)
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
 * param base PDCON peripheral base address.
 * param domain Power domain. See "pdcon_domain_t".
 * return true if the domain is busy, false otherwise.
 */
bool PDCON_IsDomainBusy(PDCON_Type *base, pdcon_domain_t domain)
{
    assert(base != NULL);

    uint32_t bit = (base->PDST >> (PDCON_PDST_PDB0_SHIFT + (uint32_t)domain)) & 0x1U;
    return (bool)(bit != 0U);
}

/*!
 * brief Gets the current state of a power domain.
 *
 * param base PDCON peripheral base address.
 * param domain Power domain. See "pdcon_domain_t".
 * return Current state of the power domain. See "pdcon_event_t".
 */
pdcon_event_t PDCON_GetDomainState(PDCON_Type *base, pdcon_domain_t domain)
{
    assert(base != NULL);

    uint32_t shift = (uint32_t)domain * 2U; /* PDS0@0, PDS1@2, ... */
    uint32_t value = (base->PDST >> shift) & 0x3U;
    return (pdcon_event_t)value;
}

/*!
 * brief Gets and optionally clears the event flag for a power domain.
 *
 * param base PDCON peripheral base address.
 * param domain Power domain. See "pdcon_domain_t".
 * param clear true to clear the event flag after reading, false to only read.
 * return Event flag for the power domain. See "pdcon_event_t".
 */
pdcon_event_t PDCON_GetAndClearEvent(PDCON_Type *base, pdcon_domain_t domain, bool clear)
{
    assert(base != NULL);
    assert(domain <= kPDCON_Domain5);

    uint32_t shift = (uint32_t)domain * 2U; /* PEF0@0, PEF1@2, ... */
    uint32_t mask  = (0x3U << shift);
    uint32_t value = base->PDSEF;

    pdcon_event_t event = (pdcon_event_t)((value & mask) >> shift);
    if (clear && (event != kPDCON_EventNoneOrActive))
    {
        base->PDSEF = mask; /* write 1s to the two bits of that field only */
    }

    return event;
}
