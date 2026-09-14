/* -------------------------------------------------------------------------- */
/*                           Copyright 2025-2026 NXP                          */
/*                    SPDX-License-Identifier: BSD-3-Clause                   */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */

#include "fwk_config.h"
#include "fwk_platform.h"
#include "fwk_platform_ics.h"

#if defined(gPlatformNbuDebugGpioDAccessEnabled_d) && (gPlatformNbuDebugGpioDAccessEnabled_d > 0)
#include "fsl_trdc.h"
#endif

/* -------------------------------------------------------------------------- */
/*                               Private macros                               */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                         Private type definitions                           */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                         Private memory declarations                        */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                              Private functions                              */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                              Public functions                              */
/* -------------------------------------------------------------------------- */

int PLATFORM_GetRadioIdleDuration32K(void)
{
    /* On this platform, Radio NBU is located on separated power domain so no impact on main core */
    return PLATFORM_RADIO_IDLE_FOREVER;
}

/*!
 * \brief Get 32kHz timestamp from 32kHz counter
 *
 * \return uint64_t number ticks since start of counter.
 *
 */
uint64_t PLATFORM_Get32KTimeStamp(void)
{
    /* 32kHz TSTMR not instantiated on KW47 / MCXW72 */
    return 0ULL;
}

/*!
 * \brief Compute number of microseconds between 2 timestamps expressed in number of TSTM 32kHz ticks
 *
 * \param [in] timestamp0 start timestamp from which duration is assessed.
 * \param [in] timestamp1 end timestamp till which duration is assessed.
 *
 * \return uint64_t number of microseconds
 *
 */
uint64_t PLATFORM_Get32KTimeStampDeltaUs(uint64_t timestamp0, uint64_t timestamp1)
{
    NOT_USED(timestamp0);
    NOT_USED(timestamp1);
    /* 32kHz TSTMR not instantiated on KW47 / MCXW72 */
    return 0ULL; /* Placeholder implementation */
}

/*
 * Tell NBU the address in RAM where to write its next activity timestamp.
 * Not applicable on KW45/MCXW71.
 */
int PLATFORM_SetNbuSharedCtxAddress(void)
{
    return -1;
}

int PLATFORM_InitNbuSpecific(void)
{
#if defined(gPlatformNbuDebugGpioDAccessEnabled_d) && (gPlatformNbuDebugGpioDAccessEnabled_d == 1)
    /* Init TRDC for NBU - Allow NBU to access GPIOD*/
    trdc_non_processor_domain_assignment_t domainAssignment;
    TRDC_SetDacGlobalValid(TRDC);
    TRDC_GetDefaultNonProcessorDomainAssignment(&domainAssignment);
    domainAssignment.privilegeAttr = (uint8_t)kTRDC_ForcePrivilege;
    TRDC_SetNonProcessorDomainAssignment(TRDC, (uint8_t)kTRDC_MasterRadioNBU, &domainAssignment);
#endif
    return 0;
}

/* Linker-defined symbol for the low power flag shared word (MISRA C-2012 Rule 8.6:
 * external linkage declaration at file scope). */
extern uint32_t m_lowpower_flag_start[]; /* defined by linker */

/*!
 * \brief Set the low power flag shared word read by the NBU core.
 *
 * The NBU reads this cross-core shared word (PLATFORM_GetLowPowerFlag) to decide
 * whether an additional wake-up delay is required when the host is in power down.
 *
 * \param[in] PwrDownOngoing true if the host is about to enter power down.
 */
void PLATFORM_SetLowPowerFlag(bool PwrDownOngoing)
{
    uint32_t           val       = 0UL;
    volatile uint32_t *p_lp_flag = (volatile uint32_t *)(uint32_t)m_lowpower_flag_start;

    if (PwrDownOngoing)
    {
        val = PLATFORM_HOST_USE_POWER_DOWN;
    }

    *p_lp_flag = val;
}
