/*
 * Copyright 2025-2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_sramctl.h"

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.sramctl"
#endif

#if defined(SRAMCTL_RSTS)
#define SRAMCTL_RESETS_ARRAY SRAMCTL_RSTS
#elif defined(SRAMCTL_RSTS_N)
#define SRAMCTL_RESETS_ARRAY SRAMCTL_RSTS_N
#endif

#if defined(SRAMCTL_RESETS_ARRAY)
/* Reset array */
static const reset_ip_name_t s_sramctlResets[] = SRAMCTL_RESETS_ARRAY;
#endif

/*******************************************************************************
 * Code
 ******************************************************************************/

status_t SRAMCTL_Init(SRAMCTL_Type *base, sramctl_config_t const *config)
{
    if ((base == NULL) || (config == NULL))
    {
        return kStatus_InvalidArgument;
    }

#if defined(SRAMCTL_RESETS_ARRAY)
    RESET_ReleasePeripheralReset(s_sramctlResets[0]);
#endif

    /* Clear previous completion / event flags (W1C), including any latched ECC errors. */
    (void)SRAMCTL_ClearStatusFlags(base, (uint32_t)(kSRAMCTL_InitializationDone | kSRAMCTL_BusError | kSRAMCTL_AddressValid |
                                                  kSRAMCTL_EccAddressError | kSRAMCTL_EccMultiBitError | kSRAMCTL_EccSingleBitError));

    base->RAMIAS = config->addressStart;
    base->RAMIAE = config->addressEnd;

    uint32_t ramcr = 0U;
    ramcr |= SRAMCTL_RAMCR_IWS((uint32_t)config->initializationWaitStates);
    ramcr |= SRAMCTL_RAMCR_INIT_SYSA((uint32_t)config->addressType);
    base->RAMCR = ramcr;

    /* Each init requires 0->1 transition per RM, so write 0 first then 1. */
    base->RAMCR &= ~SRAMCTL_RAMCR_INIT_MASK;
    base->RAMCR |= SRAMCTL_RAMCR_INIT(1U);

    while ((base->RAMSR & SRAMCTL_RAMSR_IDONE_MASK) == 0U)
    {
        /* busy wait */
    }

    return kStatus_Success;
}

void SRAMCTL_SetRamMaximumAddress(SRAMCTL_Type *base, uint32_t address)
{
    base->RAMMAXA = address;
}

void SRAMCTL_EnableExclusiveMonitor(SRAMCTL_Type *base, bool enable)
{
    if (enable)
    {
        base->RAMCR2 &= ~SRAMCTL_RAMCR2_DEM_MASK;
    }
    else
    {
        base->RAMCR2 |= SRAMCTL_RAMCR2_DEM(1U);
    }
}

status_t SRAMCTL_ClearStatusFlags(SRAMCTL_Type *base, uint32_t mask)
{
    if (base == NULL)
    {
        return kStatus_InvalidArgument;
    }

    /* IPEND and SEC are RO; clearing attempt is undefined per RM. */
    if ((mask & ((uint32_t)kSRAMCTL_InitializationPending | (uint32_t)kSRAMCTL_SecureRegion)) != 0U)
    {
        return kStatus_InvalidArgument;
    }

    /* Only W1C flags are meaningful here. */
    base->RAMSR = (mask & (uint32_t)kSRAMCTL_AllW1CFlags);

    return kStatus_Success;
}

void SRAMCTL_GetErrorInfo(SRAMCTL_Type *base, sramctl_error_info_t *info)
{
    assert(base != NULL);
    assert(info != NULL);

    uint32_t ramsr   = base->RAMSR;
    uint32_t rammema = base->RAMMEMA;

    info->eccSyndromeValue         = (uint8_t)((ramsr & SRAMCTL_RAMSR_SYND_MASK) >> SRAMCTL_RAMSR_SYND_SHIFT);
    info->ramStatusEventInfo       = (uint8_t)((ramsr & SRAMCTL_RAMSR_EINFO_MASK) >> SRAMCTL_RAMSR_EINFO_SHIFT);
    info->ramCorrectableErrorCount = (uint8_t)((base->RAMECCNT & SRAMCTL_RAMECCNT_ECCNT_MASK) >> SRAMCTL_RAMECCNT_ECCNT_SHIFT);
    info->ramEccAddressBankId      = (uint16_t)((rammema & SRAMCTL_RAMMEMA_BANK_MASK) >> SRAMCTL_RAMMEMA_BANK_SHIFT);
    info->ramEccAddressBankAddress = (uint32_t)((rammema & SRAMCTL_RAMMEMA_MEMA_MASK) >> SRAMCTL_RAMMEMA_MEMA_SHIFT);
    info->ramSystemAddress         = base->RAMSYSA;
}

void SRAMCTL_ConfigErrorInjectionAddress(SRAMCTL_Type *base, const sramctl_error_injection_address_t *config)
{
    if (config->ramErrorInjectionAddressEnable)
    {
        base->RAMEIA  = config->ramErrorInjectionBaseAddress;
        base->RAMEIAM = config->ramErrorInjectionAddressMask;
        base->RAMEIDC |= SRAMCTL_RAMEIDC_EIA_EN(1U);
    }
    else
    {
        base->RAMEIDC &= ~SRAMCTL_RAMEIDC_EIA_EN_MASK;
    }
}

void SRAMCTL_ConfigErrorInjectionData(SRAMCTL_Type *base, const sramctl_error_injection_data_t *config)
{
    if (config->ramErrorInjectionDataEnable)
    {
        base->RAMEID0 = config->ramErrorInjectionData0;
        base->RAMEID1 = config->ramErrorInjectionData1;

        uint32_t eidc = base->RAMEIDC;
        eidc &= ~SRAMCTL_RAMEIDC_EID_CKB_MASK;
        eidc |= SRAMCTL_RAMEIDC_EID_CKB(config->ramErrorInjectionDataCheckbits);
        eidc |= SRAMCTL_RAMEIDC_EID_EN(1U);
        base->RAMEIDC = eidc;
    }
    else
    {
        base->RAMEIDC &= ~SRAMCTL_RAMEIDC_EID_EN_MASK;
    }
}

void SRAMCTL_EnableErrorInjectionForSafetyAlarm(SRAMCTL_Type *base, bool enable)
{
    if (enable)
    {
#ifdef SRAMCTL_RAMEIDC_EI_EN
        base->RAMEIDC |= SRAMCTL_RAMEIDC_EI_EN(1U);
#else
	base->RAMEIDC |= SRAMCTL_RAMEIDC_EIP_EN(1U);
#endif
    }
    else
    {
#ifdef SRAMCTL_RAMEIDC_EI_EN
        base->RAMEIDC &= ~SRAMCTL_RAMEIDC_EI_EN_MASK;
#else
        base->RAMEIDC &= ~SRAMCTL_RAMEIDC_EIP_EN_MASK;
#endif
    }
}

void SRAMCTL_InitMem(SRAMCTL_Type *base, uint32_t start_addr, uint32_t end_addr)
{
    sramctl_config_t config;
    config.addressType              = kSRAMCTL_AddressTypeLocal;
    config.initializationWaitStates = kSRAMCTL_ZeroWaitCycle;
    config.addressStart             = start_addr;
    config.addressEnd               = end_addr;

    (void)SRAMCTL_Init(base, &config);
}
