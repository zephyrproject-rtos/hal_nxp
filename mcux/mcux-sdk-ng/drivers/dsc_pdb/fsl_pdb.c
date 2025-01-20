/*
 * Copyright 2021 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_pdb.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.dsc_pdb"
#endif

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/*!
 * @brief Gets the instance from the base address to be used to gate or ungate the module clock
 *
 * @param base PDB peripheral base address
 *
 * @return The PDB instance
 */
static uint32_t PDB_GetInstance(PDB_Type *base);

/*! @brief Pointers to PDB bases for each instance. */
static PDB_Type *const s_pdbBases[] = PDB_BASE_PTRS;
/*! @brief Pointers to PDB clocks for each instance. */
static const clock_ip_name_t s_pdbClocks[] = PDB_CLOCKS;

/*******************************************************************************
 * Code
 ******************************************************************************/
static uint32_t PDB_GetInstance(PDB_Type *base)
{
    uint32_t instance;

    /* Find the instance index from base address mappings. */
    for (instance = 0; instance < ARRAY_SIZE(s_pdbBases); instance++)
    {
        if (s_pdbBases[instance] == base)
        {
            break;
        }
    }

    assert(instance < ARRAY_SIZE(s_pdbBases));

    return instance;
}

/*!
 * brief Initializes the PDB user configuration structure.
 *
 * This function initializes the user configuration structure to a default value. The default values are as follows.
 * code
 *   psConfig->bEnableContinuousMode                                = false;
 *   psConfig->eInputTrigger                                        = kPDB_TriggerInput0;
 *   psConfig->eLoadValueMode                                       = kPDB_LoadValueImmediately;
 *   psConfig->ePrescalerDivider                                    = kPDB_PrescalerDivider1;
 *   psConfig->sPdbTriggerABOutputConfig.bBypassTrigger1            = false;
 *   psConfig->sPdbTriggerABOutputConfig.bBypassTrigger2            = false;
 *   psConfig->sPdbTriggerABOutputConfig.bEnableTrigger1            = false;
 *   psConfig->sPdbTriggerABOutputConfig.bEnableTrigger2            = false;
 *   psConfig->sPdbTriggerABOutputConfig.bEnbleTriggerCombineOutput = false;
 *   psConfig->sPdbTriggerABOutputConfig.eTriggerInitValue          = kPDB_InitValue0;
 *   psConfig->sPdbTriggerABOutputConfig.eFaultLength               = kPDB_2IPBusClockCycles;
 *   psConfig->sPdbTriggerABOutputConfig.eFaultPolarity             = kPDB_FaultPolarity0;
 *   psConfig->sPdbTriggerABOutputConfig.bFaultEnable               = false;
 *   psConfig->sPdbTriggerABOutputConfig.uDelay1                    = 0xFFFFU;
 *   psConfig->sPdbTriggerABOutputConfig.uDelay2                    = 0xFFFFU;
 *   psConfig->sPdbTriggerCDOutputConfig.bBypassTrigger1            = false;
 *   psConfig->sPdbTriggerCDOutputConfig.bBypassTrigger2            = false;
 *   psConfig->sPdbTriggerCDOutputConfig.bEnableTrigger1            = false;
 *   psConfig->sPdbTriggerCDOutputConfig.bEnableTrigger2            = false;
 *   psConfig->sPdbTriggerCDOutputConfig.bEnbleTriggerCombineOutput = false;
 *   psConfig->sPdbTriggerCDOutputConfig.eTriggerInitValue          = kPDB_InitValue0;
 *   psConfig->sPdbTriggerCDOutputConfig.eFaultLength               = kPDB_2IPBusClockCycles;
 *   psConfig->sPdbTriggerCDOutputConfig.eFaultPolarity             = kPDB_FaultPolarity0;
 *   psConfig->sPdbTriggerCDOutputConfig.bFaultEnable               = false;
 *   psConfig->sPdbTriggerCDOutputConfig.uDelay1                    = 0xFFFFU;
 *   psConfig->sPdbTriggerCDOutputConfig.uDelay2                    = 0xFFFFU;
 *   psConfig->u16PeriodCount                                       = 0xFFFFU;
 *   psConfig->u16EnableInterruptMask                               = 0x0u;
 *   psConfig->bEnablePDB                                           = false;
 * endcode
 * param config Pointer to configuration structure. See "pdb_config_t".
 */
void PDB_GetDefaultConfig(pdb_config_t *psConfig)
{
    assert(psConfig != NULL);

    /* Initializes the configure structure to zero. */
    (void)memset(psConfig, 0, sizeof(*psConfig));

    psConfig->bEnableContinuousMode                                = false;
    psConfig->eInputTrigger                                        = kPDB_TriggerSoftware;
    psConfig->eLoadValueMode                                       = kPDB_LoadValueImmediately;
    psConfig->ePrescalerDivider                                    = kPDB_PrescalerDivider1;
    psConfig->sPdbTriggerABOutputConfig.bBypassTrigger1            = false;
    psConfig->sPdbTriggerABOutputConfig.bBypassTrigger2            = false;
    psConfig->sPdbTriggerABOutputConfig.bEnableTrigger1            = false;
    psConfig->sPdbTriggerABOutputConfig.bEnableTrigger2            = false;
    psConfig->sPdbTriggerABOutputConfig.bEnbleTriggerCombineOutput = false;
    psConfig->sPdbTriggerABOutputConfig.eTriggerInitValue          = kPDB_InitValue0;
    psConfig->sPdbTriggerABOutputConfig.eFaultLength               = kPDB_2IPBusClockCycles;
    psConfig->sPdbTriggerABOutputConfig.eFaultPolarity             = kPDB_FaultPolarity0;
    psConfig->sPdbTriggerABOutputConfig.bFaultEnable               = false;
    psConfig->sPdbTriggerABOutputConfig.uDelay1                    = 0xFFFFU;
    psConfig->sPdbTriggerABOutputConfig.uDelay2                    = 0xFFFFU;
    psConfig->sPdbTriggerCDOutputConfig.bBypassTrigger1            = false;
    psConfig->sPdbTriggerCDOutputConfig.bBypassTrigger2            = false;
    psConfig->sPdbTriggerCDOutputConfig.bEnableTrigger1            = false;
    psConfig->sPdbTriggerCDOutputConfig.bEnableTrigger2            = false;
    psConfig->sPdbTriggerCDOutputConfig.bEnbleTriggerCombineOutput = false;
    psConfig->sPdbTriggerCDOutputConfig.eTriggerInitValue          = kPDB_InitValue0;
    psConfig->sPdbTriggerCDOutputConfig.eFaultLength               = kPDB_2IPBusClockCycles;
    psConfig->sPdbTriggerCDOutputConfig.eFaultPolarity             = kPDB_FaultPolarity0;
    psConfig->sPdbTriggerCDOutputConfig.bFaultEnable               = false;
    psConfig->sPdbTriggerCDOutputConfig.uDelay1                    = 0xFFFFU;
    psConfig->sPdbTriggerCDOutputConfig.uDelay2                    = 0xFFFFU;
    psConfig->u16PeriodCount                                       = 0xFFFFU;
    psConfig->u16EnableInterruptMask                               = 0x0U;
    psConfig->bEnablePDB                                           = false;
}

/*!
 * brief Initializes the PDB module.
 *
 * This function initializes the PDB module. The operations included are as follows.
 *  - Enable the clock for PDB instance.
 *  - Configure the PDB module.
 *  - Enable the PDB module.
 *
 * param base PDB peripheral base address.
 * param psConfig Pointer to the configuration structure. See "pdb_config_t".
 */
void PDB_Init(PDB_Type *base, const pdb_config_t *psConfig)
{
    assert(NULL != psConfig);
    uint16_t u16Tmp = 0U;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Enable the clock. */
    CLOCK_EnableClock(s_pdbClocks[PDB_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

    /* Configure. */
    /* PDBx_MCTRL. */
    u16Tmp |= PDB_MCTRL_LDMOD(psConfig->eLoadValueMode) | PDB_MCTRL_PRESCALER(psConfig->ePrescalerDivider) |
              PDB_MCTRL_TRIGSEL(psConfig->eInputTrigger);
    base->MCTRL = u16Tmp;
    while (PDB_GetPdbLdOk(base))
    {
    }
    PDB_SetTriggerOutputLogicConfig(base, kPDB_LogicA, &psConfig->sPdbTriggerABOutputConfig);
    PDB_SetTriggerOutputLogicConfig(base, kPDB_LogicC, &psConfig->sPdbTriggerCDOutputConfig);
    PDB_EnableInterrupts(base, psConfig->u16EnableInterruptMask);
    base->MOD = psConfig->u16PeriodCount;
    PDB_SetLoadOk(base);
    PDB_EnableModule(base, psConfig->bEnablePDB); /* Enable the PDB module. */
}

/*!
 * brief De-initializes the PDB module.
 *
 * param base PDB peripheral base address.
 */
void PDB_Deinit(PDB_Type *base)
{
    PDB_EnableModule(base, false); /* Disable the PDB module. */

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Disable the clock. */
    CLOCK_DisableClock(s_pdbClocks[PDB_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

/*!
 * brief Set the PDB trigger output logic.
 *
 * param base PDB peripheral base address.
 * param psConfig Pointer to the configuration structure. See "pdb_trigger_output_logic_config_t".
 */
void PDB_SetTriggerOutputLogicConfig(PDB_Type *base,
                                     pdb_logic_t eLogic,
                                     const pdb_trigger_output_logic_config_t *psConfig)
{
    uint16_t u16Tmp = 0U;

    if (eLogic == kPDB_LogicA)
    {
        /* Configure PDBx_CTRLA. */
        u16Tmp = PDB_CTRLA_BYPA(psConfig->bBypassTrigger1) | PDB_CTRLA_BYPB(psConfig->bBypassTrigger2) |
                 PDB_CTRLA_ABSEL(psConfig->bEnbleTriggerCombineOutput) | PDB_CTRLA_AINIT(psConfig->eTriggerInitValue) |
                 PDB_CTRLA_FLENA(psConfig->eFaultLength) | PDB_CTRLA_FPOLA(psConfig->eFaultPolarity) |
                 PDB_CTRLA_FLTAEN(psConfig->bFaultEnable) | PDB_CTRLA_ENA(psConfig->bEnableTrigger1) |
                 PDB_CTRLA_ENB(psConfig->bEnableTrigger2);
        base->CTRLA  = u16Tmp;
        base->DELAYA = psConfig->uDelay1;
        base->DELAYB = psConfig->uDelay2;
    }

    else
    {
        /* Configure PDBx_CTRLC. */
        u16Tmp = PDB_CTRLC_BYPC(psConfig->bBypassTrigger1) | PDB_CTRLC_BYPD(psConfig->bBypassTrigger2) |
                 PDB_CTRLC_CDSEL(psConfig->bEnbleTriggerCombineOutput) | PDB_CTRLC_CINIT(psConfig->eTriggerInitValue) |
                 PDB_CTRLC_FLENC(psConfig->eFaultLength) | PDB_CTRLC_FPOLC(psConfig->eFaultPolarity) |
                 PDB_CTRLC_FLTCEN(psConfig->bFaultEnable) | PDB_CTRLC_ENC(psConfig->bEnableTrigger1) |
                 PDB_CTRLC_END(psConfig->bEnableTrigger2);
        base->CTRLC  = u16Tmp;
        base->DELAYC = psConfig->uDelay1;
        base->DELAYD = psConfig->uDelay2;
    }
}
